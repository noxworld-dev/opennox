package netstr

import (
	"bytes"
	"encoding"
	"encoding/binary"
	"errors"
	"fmt"
	"math/rand"
	"net"
	"net/netip"
	"time"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/platform"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/server/netlib"
)

const (
	maxStructs = 128
	maskID     = byte(maxStructs - 1) // 0x7F
	someIDFlag = byte(maxStructs)     // 0x80
	anyID      = byte(0xff)
)

const (
	codeInit0          = noxnet.Op(0x00)
	codeNewStream1     = noxnet.Op(0x01)
	codeErr2           = noxnet.Op(0x02)
	code3              = noxnet.Op(0x03)
	codeAlreadyJoined4 = noxnet.Op(0x04)
	code5              = noxnet.Op(0x05)
	code6              = noxnet.Op(0x06)
	code7              = noxnet.Op(0x07)
	code8              = noxnet.Op(0x08)
	code9              = noxnet.Op(0x09)
	code10             = noxnet.Op(0x0A)
	code11             = noxnet.Op(0x0B)
	codeDiscover12     = noxnet.Op(0x0C)
	codeInfo13         = noxnet.Op(0x0D)
	codeJoin14         = noxnet.Op(0x0E)
	codeErr15          = noxnet.Op(0x0F)
	codePing16         = noxnet.Op(0x10)
	code17             = noxnet.Op(0x11)
	codePong18         = noxnet.Op(0x12)
	codeErrCode19      = noxnet.Op(0x13)
	codeACK20          = noxnet.Op(0x14)
	codeErr21          = noxnet.Op(0x15)
	code31             = noxnet.Op(0x1F)
	code32             = noxnet.Op(0x20)
	code33             = noxnet.Op(0x21)
	code34             = noxnet.Op(0x22)
	code35             = noxnet.Op(0x23)
	code36             = noxnet.Op(0x24)
	code37             = noxnet.Op(0x25)
	code38             = noxnet.Op(0x26)
)

var (
	Log = log.New("network")
)

func NewStreams() *Streams {
	s := &Streams{
		playerIDs: make(map[Handle]struct{}),
		KeyRand: func(min, max int) int {
			return min + rand.Intn(max-min)
		},
		PacketDropRand: func(min, max int) int {
			return min + rand.Intn(max-min)
		},
		Now:           platform.Ticks,
		Sleep:         platform.Sleep,
		Debug:         DebugSockets,
		Log:           Log,
		Xor:           true,
		MaxPacketLoss: 3,
	}
	s.Reset()
	return s
}

type Streams struct {
	lastQueueSend  time.Duration
	ticks2         time.Duration
	cntX           int
	lis            *Conn
	streams        [maxStructs]*Conn
	streams2       [maxStructs]stream2
	timing         [maxStructs]timingStruct
	transfer       [maxStructs]uint32
	playerIDs      map[Handle]struct{}
	sendXorBuf     [4096]byte // TODO: remove this buffer?
	Log            *log.Logger
	Now            func() time.Duration
	Sleep          func(dt time.Duration)
	GameFlags      func() noxflags.GameFlag
	GameFrame      func() uint32
	GetMaxPlayers  func() int
	OnDiscover     func(src, dst []byte) int
	OnExtPacket    func(pc net.PacketConn, buf1 []byte, from netip.AddrPort)
	KeyRand        func(min, max int) int
	PacketDropRand func(min, max int) int
	PacketDrop     int
	MaxPacketLoss  int
	Responded      bool
	Xor            bool
	Debug          bool
}

func (g *Streams) Reset() {
	for i, ns := range g.streams {
		if ns != nil && ns.pc != nil {
			_ = ns.Close()
		}
		g.streams[i] = nil
	}
	for i := range g.streams2 {
		g.streams2[i] = stream2{}
	}
}

func (g *Streams) ConnByPlayerInd(pind ntype.PlayerInd) *Conn {
	return g.streams[int(pind)+1]
}

func (g *Streams) ByPlayer(p ntype.Player) *Conn {
	return g.ConnByPlayerInd(p.PlayerIndex())
}

func (g *Streams) StreamByPlayerInd(pind ntype.PlayerInd) netlib.Stream {
	return g.ConnByPlayerInd(pind)
}

func (g *Streams) HostStream() netlib.Stream {
	return g.Host()
}

func (g *Streams) Host() *Conn {
	return g.streams[0]
}

func (ns *Conn) addTransferStats(n int) {
	ns.g.transfer[ns.ind] += uint32(n)
}

func (ns *Conn) TransferStats() uint32 {
	if ns == nil {
		return 0
	}
	val := ns.g.transfer[ns.ind]
	ns.g.transfer[ns.ind] = 0
	return val
}

func (g *Streams) Update() {
	g.maybeReadPackets()
	g.MaybeSendQueues()
}

type timingStruct struct {
	field0  uint32
	field4  uint32
	field8  [5]uint32
	field28 uint32
}

type queueItem struct {
	next    *queueItem
	retryAt time.Duration
	active  bool
	size    uint32
	data    [1024]byte
}

func (q *queueItem) Data() []byte {
	return q.data[:q.size]
}

type stream2 struct {
	active  bool
	lost    uint8
	addr    netip.AddrPort
	cur     uint8 // index into samples
	samples [10]time.Duration
	ticks   time.Duration
}

func (g *Streams) getFreeIndex() (int, bool) {
	for i, it := range g.streams {
		if it == nil {
			return i, true
		}
	}
	return -1, false
}

func (g *Streams) getFreeIndexWithAddr(addr netip.AddrPort) (int, bool) {
	for i, it := range g.streams {
		if it == nil {
			return i, true
		} else if it.addr == addr {
			return i, false
		}
	}
	return -1, false
}

func (g *Streams) getFreeNetStruct2Ind() int {
	for i := range g.streams2 {
		if !g.streams2[i].active {
			return i
		}
	}
	return -1
}

func (g *Streams) connByAddr(addr netip.AddrPort) *Conn {
	for i := range g.streams {
		ns := g.streams[i]
		if ns == nil {
			continue
		}
		if addr == ns.addr {
			return ns
		}
	}
	return nil
}

func (g *Streams) struct2IndByAddr(addr netip.AddrPort) int {
	for i := range g.streams2 {
		nx := &g.streams2[i]
		if addr == nx.addr {
			return i
		}
	}
	return -1
}

func (g *Streams) hasConnWithIndAndAddr(ind Handle, addr netip.AddrPort) bool {
	for i := range g.streams {
		ns := g.streams[i]
		if ns == nil {
			continue
		}
		if addr == ns.addr && ind.i == i {
			return true
		}
	}
	return false
}

type Handler func(conn netlib.StreamID, buf []byte) int

type Options struct {
	Port       int
	Max        int
	BufferSize int
	OnSend     Handler
	OnReceive  Handler
	OnJoin     JoinCheck
	Check17    Check17
}

func (g *Streams) newStream(id int, opt *Options) *Conn {
	ind, ok := g.getFreeIndex()
	if !ok {
		return nil
	}
	return g.newStreamAt(ind, id, opt)
}

func (g *Streams) newStreamAt(ind int, id int, opt *Options) *Conn {
	ns := &Conn{
		g:         g,
		ind:       ind,
		id:        id,
		max:       uint32(opt.Max),
		seqRecv:   -1,
		xorKey:    0,
		onSend:    opt.OnSend,
		onReceive: opt.OnReceive,
		onJoin:    opt.OnJoin,
		check17:   opt.Check17,
	}
	if dsz := opt.BufferSize; dsz > 0 {
		dsz -= dsz % 4
		opt.BufferSize = dsz
	} else {
		opt.BufferSize = 1024
	}
	ns.recv.Grow(2 + opt.BufferSize)

	ns.sendBuf = make([]byte, 2+opt.BufferSize)
	ns.sendWrite = 2
	*ns.Data2hdr() = [2]byte{anyID, 0}
	g.streams[ind] = ns
	return ns
}

func (ns *Conn) reset() {
	if ns == nil {
		return
	}
	ns.recv.Reset()
	*ns = Conn{g: ns.g, ind: ns.ind}
}

func (ns *Conn) Close() error {
	if ns == nil {
		return nil
	}
	if ns.pc != nil {
		if ns.g.Debug {
			ns.g.Log.Printf("closing connection: %d", ns.id)
		}
		_ = ns.pc.Close()
	}
	ns.pc = nil
	ns.reset()
	ns.g.streams[ns.ind] = nil
	return nil
}

func (g *Streams) Listen(opt *Options) (*Conn, error) {
	if opt == nil {
		return nil, errors.New("empty options")
	}
	if opt.Max > maxStructs {
		return nil, errors.New("max limit reached")
	}
	if opt.Port < 1024 || opt.Port > 0x10000 {
		opt.Port = common.GamePort
	}
	pc, port, err := listenOnFreePort(g.Log, opt.Port)
	if err != nil {
		return nil, err
	}
	opt.Port = port
	ns := g.newStream(-1, opt)
	if ns == nil {
		return nil, errors.New("no more slots for net structs")
	}
	ns.pc = pc
	ns.Data2hdr()[0] = byte(ns.ind)
	g.lis = ns
	return ns, nil
}

func (g *Streams) NewClient(narg *Options) (*Conn, error) {
	if narg == nil {
		return nil, NewConnectErr(-2, errors.New("empty options"))
	}
	ns := g.newStream(0, narg)
	if ns == nil {
		return nil, NewConnectErr(-8, errors.New("no more slots for net structs"))
	}
	return ns, nil
}

func (ns *Conn) Dial(host string, port int, cport int, opts encoding.BinaryMarshaler) error {
	if ns.g.Debug {
		ns.g.Log.Println("NET_CONNECT", host, port)
	}
	if ns == nil {
		return NewConnectErr(-3, errors.New("no net struct"))
	}
	if len(host) == 0 {
		return NewConnectErr(-4, errors.New("empty hostname"))
	}
	if port < 1024 || port > 0x10000 {
		return NewConnectErr(-15, errors.New("invalid port"))
	}
	var ip netip.Addr
	if host[0] < '0' || host[0] > '9' {
		list, err := net.LookupIP(host)
		if err != nil || len(list) == 0 {
			log.Printf("error: cannot find ip for a host %q: %v", host, err)

			return NewConnectErr(-4, err)
		}
		ip, _ = netip.AddrFromSlice(list[0].To4())
	} else {
		var err error
		ip, err = netip.ParseAddr(host)
		if err != nil {
			log.Printf("error: cannot parse host %q: %v", host, err)
			return NewConnectErr(-4, err)
		}
	}
	addr := netip.AddrPortFrom(ip, uint16(port))
	ns.SetAddr(addr)

	for {
		sock, err := listen(ns.g.Log, netip.AddrPortFrom(netip.IPv4Unspecified(), uint16(cport)))
		if err == nil {
			ns.pc = sock
			break
		} else if !ErrIsInUse(err) {
			return NewConnectErr(-1, err)
		}
		cport++
	}
	ns.g.Responded = false
	var v12 [1]byte // TODO: sending zero, is that correct? if so, set explicitly here
	v11, err := ns.Send(v12[:], SendQueue|SendFlush)
	if err != nil {
		return fmt.Errorf("cannot send data: %w", err)
	}

	retries, counter := 60, 0
	for {
		//counter = 0 // TODO: is this correct?
		counter++
		if counter > 20*retries {
			return NewConnectErr(-23, errors.New("timeout"))
		}
		ns.RecvLoop(RecvCanRead | RecvNoHooks | RecvJustOne)
		ns.g.MaybeSendQueues()
		f28 := int(ns.seqRecv)
		if f28 >= v11 {
			break
		}
		ns.g.Sleep(30 * time.Millisecond)
	}

	if ns.g.Responded && ns.Handle().Valid() {
		data, err := opts.MarshalBinary()
		if err != nil {
			return err
		}
		buf := make([]byte, 3+len(data))
		buf[0] = byte(code31) // TODO: it isn't a code, it an ID?
		buf[1] = ns.Data2hdr()[1]
		buf[2] = byte(code32)
		if len(data) > 0 {
			copy(buf[3:], data)
		}
		_, _ = ns.Send(buf, SendQueue|SendFlush)
	}

	if !ns.Handle().Valid() {
		return NewConnectErr(-1, errors.New("invalid net struct id"))
	}
	return nil
}

func (ns *Conn) DialWait(timeout time.Duration, send func(), check func() bool) error {
	deadline := ns.g.Now() + timeout
	if ns.g.Debug {
		ns.g.Log.Println("CONNECT_WAIT_LOOP_START", deadline)
	}
	for {
		now := ns.g.Now()
		if timeout >= 0 && now >= deadline {
			return NewConnectErr(-19, errors.New("timeout 2"))
		}
		ns.RecvLoop(RecvCanRead)
		send()
		ns.g.MaybeSendQueues()
		if check() {
			break
		}
		ns.g.Sleep(5 * time.Millisecond)
	}
	return nil
}

type Conn struct {
	g    *Streams
	pc   net.PacketConn
	addr netip.AddrPort
	id   int
	ind  int

	recv bytes.Buffer

	sendBuf   []byte
	sendWrite int

	max       uint32
	accepted  int
	ticks22   time.Duration
	ticks23   time.Duration
	ticks24   time.Duration
	seqSend   uint8
	seqRecv   int8
	queue     *queueItem
	onSend    Handler
	onReceive Handler
	xorKey    byte
	field38   byte
	seq39     byte
	frame40   uint32
	onJoin    JoinCheck
	check17   Check17
}

func (ns *Conn) String() string {
	if ns == nil {
		return "<nil>"
	}
	return fmt.Sprintf("Conn(ind: %d, id: %d, addr: %s)", ns.ind, ns.id, ns.addr.String())
}

func (ns *Conn) IsHost() bool {
	if ns == nil {
		return false
	}
	return ns.ind == 0
}

func (ns *Conn) Player() ntype.PlayerInd {
	if ns == nil {
		return 0
	}
	return ntype.PlayerInd(ns.id - 1)
}

func (ns *Conn) Addr() netip.AddrPort {
	if ns == nil {
		return netip.AddrPort{}
	}
	return ns.addr
}

func (ns *Conn) SetAddr(addr netip.AddrPort) {
	ns.addr = addr
}

func (ns *Conn) IndHandle() Handle {
	if ns == nil {
		return errHandle(-1)
	}
	return Handle{ns.g, ns.ind}
}

func (ns *Conn) Handle() Handle {
	if ns == nil {
		return errHandle(-1)
	}
	return Handle{ns.g, ns.id}
}

func (ns *Conn) Data2hdr() *[2]byte {
	if ns == nil {
		var v [2]byte
		return &v
	}
	return (*[2]byte)(ns.sendBuf[:2])
}

func (ns *Conn) SendReadBuf() []byte {
	if ns == nil {
		return nil
	}
	return ns.sendBuf[:ns.sendWrite]
}

func (ns *Conn) SendWriteBuf() []byte {
	if ns == nil {
		return nil
	}
	return ns.sendBuf[ns.sendWrite:]
}

func (ns *Conn) callOnSend(buf []byte) int {
	if ns.onSend == nil {
		return 0
	}
	return ns.onSend(ns.IndHandle(), buf)
}

func (ns *Conn) callOnReceive(ns2 *Conn, buf []byte) int {
	if ns.onReceive == nil {
		return 0
	}
	return ns.onReceive(ns2, buf)
}

const (
	SendQueue = netlib.SendQueue
	SendFlush = netlib.SendFlush
)

type SendFlags = netlib.SendFlags

func (ns *Conn) SendMsg(msg noxnet.Message, flags SendFlags) (int, error) {
	buf, err := noxnet.AppendPacket(nil, msg)
	if err != nil {
		return 0, err
	}
	return ns.Send(buf, flags)
}

func (ns *Conn) Send(buf []byte, flags SendFlags) (int, error) {
	if ns == nil {
		return -3, errors.New("no net struct")
	}
	if len(buf) == 0 {
		return -2, errors.New("empty buffer")
	}
	if flags.Has(SendQueue) {
		seq, err := ns.addToQueue(buf)
		if seq == -1 {
			return -1, err
		}
		if flags.Has(SendFlush) {
			ns.sendQueueSeq(byte(seq))
		}
		return seq, nil
	}
	n := len(buf)
	d2x := ns.SendWriteBuf()
	if n+1 > len(d2x) {
		return -7, errors.New("buffer too short")
	}
	if flags.Has(SendFlush) {
		copy(d2x[:2], ns.Data2hdr()[:2])
		copy(d2x[2:2+n], buf)
		n2, err := ns.WriteTo(d2x[:n+2], ns.addr)
		if n2 == -1 {
			return -1, err
		}
		ns.addTransferStats(n + 2)
		return n2, nil
	}
	copy(d2x[:n], buf)
	ns.sendWrite += n
	return n, nil
}

func netCrypt(key byte, p []byte) {
	if len(p) == 0 {
		return
	}
	for i := range p {
		p[i] ^= key
	}
}

func (ns *Conn) addToQueue(buf []byte) (int, error) {
	if len(buf) > 1024-2 {
		return -1, errors.New("buffer too large")
	}
	if len(buf) == 0 {
		return -1, errors.New("empty buffer")
	}
	seq := ns.seqSend
	ns.seqSend++

	q := &queueItem{
		active: true,
		size:   uint32(2 + len(buf)),
	}
	q.data[0] = ns.Data2hdr()[0] | someIDFlag
	q.data[1] = seq
	copy(q.data[2:], buf)

	q.next = ns.queue
	ns.queue = q

	return int(seq), nil
}

func (ns *Conn) sendQueueSeq(seq byte) int {
	if ns == nil {
		return -3
	}
	for it := ns.queue; it != nil; it = it.next {
		if it.data[1] != seq {
			continue
		}
		it.active = false
		it.retryAt = ns.g.ticks2 + 2*time.Second
		if _, err := ns.WriteTo(it.Data(), ns.addr); err != nil {
			ns.g.Log.Println(err)
			return 0
		}
	}
	return 0
}

func (ns *Conn) sendQueueActive() int {
	if ns == nil {
		return -3
	}
	for it := ns.queue; it != nil; it = it.next {
		if !it.active {
			continue
		}
		it.active = false
		it.retryAt = ns.g.ticks2 + 2*time.Second
		if _, err := ns.WriteTo(it.Data(), ns.addr); err != nil {
			ns.g.Log.Println(err)
			return 0
		}
	}
	return 0
}

func (ns *Conn) resendQueueBySeq(seq byte) {
	if ns == nil {
		return
	}
	for it := ns.queue; it != nil; it = it.next {
		if it.data[1] == seq {
			it.active = true
		}
	}
}

func (ns *Conn) queueByTime() {
	if ns == nil {
		return
	}
	for it := ns.queue; it != nil; it = it.next {
		if it.retryAt <= ns.g.ticks2 {
			it.active = true
		}
	}
}

func (g *Streams) Listener() *Conn {
	return g.lis
}

func (g *Streams) getForPacket(i int) Handle {
	return Handle{g, i}
}

func (ns *Conn) SendReadPacket(noHooks bool) int {
	if ns == nil {
		return -3
	}
	ns.sendQueueActive()
	if !noHooks {
		buf := ns.SendWriteBuf()
		n := ns.callOnSend(buf)
		if n > 0 && n <= len(buf) {
			ns.sendWrite += n
		}
	}
	if buf := ns.SendReadBuf(); len(buf) > 2 {
		_, err := ns.WriteTo(buf, ns.addr)
		if err != nil {
			return -1
		}
		ns.addTransferStats(len(buf))
		ns.sendWrite = 2
	}
	return 0
}

func (ns *Conn) maybeFreeQueue(seq byte, act int) {
	if ns == nil {
		return
	}
	var (
		next *queueItem
		prev *queueItem
	)
	for it := ns.queue; it != nil; it = next {
		next = it.next
		switch act {
		case 0:
			if it.data[1] != seq {
				prev = it
				continue
			}
		case 1:
			if seq < 0x20 || seq > 0xE0 {
				if it.data[1] >= seq {
					prev = it
					continue
				}
			} else {
				if it.data[1] >= seq {
					prev = it
					continue
				}
			}
		case 2:
			// nop
		default:
			prev = it
			continue
		}
		if head := ns.queue; it == head {
			ns.queue = head.next
		}
		if prev != nil {
			prev.next = next
		}
		it.next = nil
		*it = queueItem{}
	}
}

func (ns *Conn) ReadPackets() {
	if ns == nil {
		return
	}
	ns.SendReadPacket(true)
	var buf [1]byte
	buf[0] = byte(code11)
	_, _ = ns.Send(buf[:], 0)
	ns.SendReadPacket(true)
	ns.accepted--
	ns.maybeFreeQueue(0, 2)
	ns.reset()
	ns.g.streams[ns.ind] = nil
}

func (g *Streams) maybeReadPackets() {
	g.ticks2 = g.Now()
	for _, ns := range g.streams {
		if ns == nil {
			continue
		}
		if ns.field38 == 1 && ns.frame40+300 < g.GameFrame() {
			ns.ReadPackets()
		}
	}
}

func (g *Streams) MaybeSendQueues() {
	now := g.Now()
	g.ticks2 = now
	if now-g.lastQueueSend <= 1*time.Second {
		return
	}
	for _, ns := range g.streams {
		if ns != nil {
			ns.queueByTime()
			ns.sendQueueActive()
		}
	}
	g.lastQueueSend = now
}

func (g *Streams) GetTimingByInd1(ind ntype.PlayerInd) int {
	return int(g.timing[int(ind)+1].field28)
}

func (ns *Conn) IP() netip.Addr {
	if ns == nil {
		return netip.Addr{}
	}
	return ns.addr.Addr()
}

func (ns *Conn) SendClose() {
	if ns == nil {
		return
	}
	ns.SendReadPacket(false)
	var buf [1]byte
	buf[0] = byte(code10)
	_, _ = ns.Send(buf[:1], 0)
	ns.SendReadPacket(false)
	ns.Close()
}

func (ns *Conn) processStreamOp0(out []byte, pid Handle, p1 byte, from netip.AddrPort) int {
	if f := ns.g.GameFlags(); f.Has(noxflags.GameHost) && f.Has(noxflags.GameFlag4) {
		return 0
	}
	out[0] = 0
	out[1] = p1
	if ns.accepted >= ns.g.GetMaxPlayers()+(ns.g.cntX-1) {
		out[2] = byte(codeErr2)
		return 3
	}
	if pid.i != -1 {
		ns.g.Log.Printf("pid must be set to -1 when joining: was %d (%s)\n", pid.i, from.String())
		// pid in the request must be -1 (0xff); fail if it's not
		out[2] = byte(codeErr2)
		return 3
	}
	// now, find free net struct index and use it as pid
	ind, ok := ns.g.getFreeIndexWithAddr(from)
	if !ok {
		if ind >= 0 {
			out[2] = byte(codeAlreadyJoined4) // already joined?
			return 3
		}
		// no free streams left
		out[2] = byte(codeErr2)
		return 3
	}
	ns2 := ns.g.newStreamAt(ind, ind, &Options{
		BufferSize: len(ns.sendBuf),
		OnJoin:     ns.onJoin,
		Check17:    ns.check17,
	})
	ns.accepted++

	hdr := ns2.Data2hdr()
	hdr[0] = byte(ns.ind)
	if hdr[1] == p1 {
		hdr[1]++
	}
	ns2.pc = ns.pc
	ns2.onSend = ns.onSend
	ns2.onReceive = ns.onReceive

	ns.g.timing[ind] = timingStruct{field28: 1}
	key := byte(ns.g.KeyRand(1, 255))
	if !ns.g.Xor {
		key = 0
	}
	ns2.xorKey = 0 // send this packet without xor encoding

	ns2.SetAddr(from)

	out[0] = byte(code31) // TODO: it's not a code here, but an ID?
	out[1] = p1
	out[2] = byte(codeNewStream1)
	binary.LittleEndian.PutUint32(out[3:], uint32(ind))
	out[7] = key
	v67, _ := ns2.Send(out[:8], SendQueue|SendFlush)

	ns2.xorKey = key
	ns2.field38 = 1
	ns2.seq39 = byte(v67)
	ns2.frame40 = ns.g.GameFrame()
	return 0
}

func (ns *Conn) processStreamOp6(ns2 *Conn, out []byte, packetCur []byte) int {
	if ns2 == nil {
		return 0
	}
	if len(packetCur) < 4 {
		return 0
	}
	v := binary.LittleEndian.Uint32(packetCur[:4])

	out[0] = byte(code37)
	ns.callOnReceive(ns2, out[:1])

	ns.g.timing[ns2.ind].field4 = v
	var hdr *[2]byte
	if ns.id == -1 {
		out[0] = byte(ns2.id)
		hdr = ns2.Data2hdr()
	} else {
		out[0] = byte(ns.id)
		hdr = ns.Data2hdr()
	}
	out[1] = hdr[0]
	out[2] = byte(code8)
	binary.LittleEndian.PutUint32(out[3:], v)
	return 7
}

func (ns *Conn) processStreamOp7(ns2 *Conn, out []byte) int {
	if ns2 == nil {
		return 0
	}
	ms := int((ns.g.ticks2 - ns2.ticks24) / time.Millisecond)
	speed := -1
	if ms >= 1 {
		speed = 256000 / ms
	}
	out[0] = byte(code35)
	binary.LittleEndian.PutUint32(out[1:], uint32(speed))
	// TODO: these two were sending hook payload from either ns1 or ns4
	if ns.id == -1 {
		ns.callOnReceive(ns2, out[:5])
	} else {
		ns.callOnReceive(ns2, out[:5])
	}
	return 0
}

func (ns *Conn) processStreamOp8(ns2 *Conn, out []byte, packetCur []byte) int {
	if ns2 == nil || binary.LittleEndian.Uint32(packetCur) != uint32(ns2.ticks22/time.Millisecond) {
		return 0
	}
	dt := ns.g.ticks2 - ns2.ticks23
	ns2.ticks24 = dt
	out[0] = byte(code36) // MSG_PING?
	ms := int(dt / time.Millisecond)
	binary.LittleEndian.PutUint32(out[1:], uint32(ms))
	// TODO: these two were sending hook payload from either ns1 or ns2
	if ns.id == -1 {
		ns.callOnReceive(ns2, out[:5])
	} else {
		ns.callOnReceive(ns2, out[:5])
	}

	out[0] = ns.Data2hdr()[0]
	out[1] = ns2.Data2hdr()[1]
	out[2] = byte(code9)
	ms = int(ns.g.ticks2 / time.Millisecond)
	binary.LittleEndian.PutUint32(out[3:], uint32(ms))
	return 7
}

func (g *Streams) processStreamOp9(pid Handle, packetCur []byte) int {
	if len(packetCur) < 4 {
		return 0
	}
	v := binary.LittleEndian.Uint32(packetCur[:4])
	p := &g.timing[pid.i]
	dv := v - p.field4
	if dv <= 0 || dv >= 1000 {
		return 0
	}
	ind := p.field0
	p.field8[ind] = dv
	v26 := (ind + 1) % 5
	v27 := v26
	if v26 == 0 {
		for _, vv := range p.field8 {
			v26 += vv
		}
		p.field28 = v26 / uint32(len(p.field8))
	}
	p.field0 = v27
	return 0
}

type JoinCheck func(out []byte, packet []byte, a4a bool, add func(pid ntype.Player) bool) int

func (ns *Conn) processStreamOp14(out []byte, packet []byte, p1 byte, from netip.AddrPort) int {
	out[0] = 0
	out[1] = p1

	a4a := false
	if ns.accepted >= ns.g.GetMaxPlayers()-1 {
		a4a = true
	}
	if n := ns.onJoin(out, packet, a4a, func(pl ntype.Player) bool {
		ns2 := ns.g.ByPlayer(pl)
		pid := ns2.IndHandle()
		if _, ok := ns.g.playerIDs[pid]; ok {
			return false
		}
		ns.g.playerIDs[pid] = struct{}{}
		ns.g.cntX++
		return true
	}); n != 0 {
		return n
	}

	ind2 := ns.g.getFreeNetStruct2Ind()
	if ind2 < 0 {
		out[2] = byte(codeACK20)
		return 3
	}
	nx := &ns.g.streams2[ind2]
	nx.active = true
	nx.cur = 0
	nx.lost = 0
	nx.addr = from

	// TODO: this overwrites first 2 bytes
	t := ns.g.Now()
	return copy(out, nx.nextPingPacket(t))
}

func (ns *Conn) SendCode6() int {
	if ns == nil {
		return -3
	}
	var buf [5]byte
	buf[0] = byte(code6)
	ns.ticks22 = ns.g.ticks2
	ns.ticks23 = ns.ticks22
	binary.LittleEndian.PutUint32(buf[1:], uint32(ns.ticks22/time.Millisecond))
	_, _ = ns.Send(buf[:5], SendFlush)
	return 0
}

func (ns *Conn) readXxx(ns2 *Conn, a3 byte, buf []byte) bool {
	if ns2 == nil || ns2.field38 != 1 || ns2.seq39 > a3 {
		return false
	}
	if ns.accepted > (ns.g.GetMaxPlayers() - 1) {
		ns2.ReadPackets()
		return true
	}
	if len(buf) >= 4 && buf[4] == 32 {
		ns2.field38 = 2
		ns2.seq39 = 0xff
		ns2.frame40 = 0
		ns.callOnReceive(ns2, buf[4:])
	}
	return true
}

func (ns *Conn) processStreamOp(packet []byte, out []byte, from netip.AddrPort) int {
	if ns == nil {
		return 0
	}
	if len(packet) < 2 {
		return 0
	}
	pid := ns.g.getForPacket(int(int8(packet[0])))
	p1 := packet[1]
	packetCur := packet[2:]

	pidb := pid // TODO: some of the functions assume it's different from pid, check what's wrong
	for len(packetCur) != 0 {
		op := packetCur[0]
		packetCur = packetCur[1:]
		if ns.g.Debug {
			ns.g.Log.Printf("processStreamOp: op=%d [%d]\n", op, len(packetCur))
		}
		switch noxnet.Op(op) {
		default:
			return 0
		case codeInit0:
			return ns.processStreamOp0(out, pidb, p1, from)
		case codeNewStream1:
			if len(packetCur) < 5 {
				return 0
			}
			ind := int(binary.LittleEndian.Uint32(packetCur[:4]))
			xor := packetCur[4]
			packetCur = packetCur[5:]

			ns.id = ind
			ns.Data2hdr()[0] = byte(ind)
			ns.xorKey = xor
			ns.g.Responded = true
		case codeErr2:
			ns.id = -18
			ns.g.Responded = true
		case code3: // ack?
			ns.id = -12
			ns.g.Responded = true
		case codeAlreadyJoined4:
			ns.id = -13
			ns.g.Responded = true
		case code5:
			if len(packetCur) < 4 {
				return 0
			}
			v := binary.LittleEndian.Uint32(packetCur[:4])
			out[0] = ns.xorKey
			out[1] = 0
			out[2] = byte(code7)
			binary.LittleEndian.PutUint32(out[3:], v)
			return 7
		case code6:
			return ns.processStreamOp6(pid.Get(), out, packetCur)
		case code7:
			return ns.processStreamOp7(pid.Get(), out)
		case code8:
			return ns.processStreamOp8(pid.Get(), out, packetCur)
		case code9:
			return ns.g.processStreamOp9(pid, packetCur)
		case code10:
			return ns.processStreamOp10(pid, out)
		case code11:
			ns7 := pid.Get()
			if ns7 == nil {
				return 0
			}
			out[0] = byte(code33)
			ns.callOnReceive(ns7, out[:1])
			ns.Close()
			return 0
		case codeJoin14: // join game request?
			return ns.processStreamOp14(out, packet, p1, from)
		case code17:
			return ns.processStreamOp17(out, packet, p1, from)
		case codePong18:
			return ns.g.processPong(out, packet, from)
		case code31:
			if len(packetCur) < 1 {
				return 0
			}
			seq := packetCur[0]
			packetCur = packetCur[1:]

			ns8 := pidb.Get()
			if ns8 == nil {
				return 0
			}
			ns.g.Log.Printf("switch 31: 0x%x 0x%x\n", seq, ns8.seqRecv)
			if seq != byte(ns8.seqRecv) {
				ns9 := pid.Get()
				ns9.resendQueueBySeq(seq)
				ns9.maybeFreeQueue(seq, 1)
				ns8.seqRecv = int8(seq)
				out[0] = byte(code38)
				out[1] = seq
				ns.callOnReceive(ns9, out[:2])
			}
		}
	}
	return 0
}

func (g *Streams) recvRoot(dst *bytes.Buffer, pc net.PacketConn) (int, netip.AddrPort) {
	var buf [1024]byte // TODO: get rid of this buffer
	n, src, err := g.recvRaw(pc, buf[:])
	if err == nil && g.Xor {
		if ns := g.connByAddr(src); ns != nil && ns.xorKey != 0 {
			netCrypt(ns.xorKey, buf[:n])
		}
	}
	if g.GameFlags().Has(noxflags.GameHost) {
		dst.Write(buf[:n])
		return n, src
	}
	if r := g.PacketDropRand(1, 99); r < g.PacketDrop {
		return 0, src
	}
	dst.Write(buf[:n])
	return n, src
}

func (g *Streams) recvRaw(pc net.PacketConn, buf []byte) (int, netip.AddrPort, error) {
	n, src, err := readFrom(g.Debug, g.Log, pc, buf)
	if err != nil {
		return n, src, err
	}
	if n >= 2 && binary.LittleEndian.Uint16(buf[:2]) == 0xF13A { // extension packet code
		g.OnExtPacket(pc, buf, src)
		return 0, src, nil
	}
	return n, src, nil
}

func (ns *Conn) processStreamOp10(pid Handle, out []byte) int {
	if pid.i == -1 {
		return 0
	}
	ns6 := pid.Get()
	if ns6 == nil || ns6.field38 == 1 {
		return 0
	}
	out[0] = byte(code34)
	ns.callOnReceive(ns6, out[:1])

	ns.g.timing[ns.ind] = timingStruct{}

	if _, ok := ns.g.playerIDs[pid]; ok {
		delete(ns.g.playerIDs, pid)
		ns.g.cntX--
	}

	ns6.ReadPackets()
	return 0
}

type Check17 func(out []byte, packet []byte) int

func (ns *Conn) processStreamOp17(out []byte, packet []byte, p1 byte, from netip.AddrPort) int {
	out[0] = 0
	out[1] = p1
	if n := ns.check17(out, packet); n != 0 {
		return n
	}
	ind2 := ns.g.getFreeNetStruct2Ind()
	if ind2 < 0 {
		out[2] = byte(codeACK20)
		return 3
	}
	nx := &ns.g.streams2[ind2]
	nx.active = true
	nx.cur = 0
	nx.lost = 0
	nx.addr = from

	// TODO: this overwrites first 2 bytes
	t := ns.g.Now()
	return copy(out, nx.nextPingPacket(t))
}

func (g *Streams) processPong(out []byte, packet []byte, from netip.AddrPort) int {
	if len(packet) < 8 {
		return 0
	}
	token := binary.LittleEndian.Uint32(packet[4:])
	dt := g.Now() - time.Duration(token)*time.Millisecond
	ind := g.struct2IndByAddr(from)
	if ind < 0 {
		return 0
	}
	nx := &g.streams2[ind]
	if packet[3] != nx.cur {
		return 0
	}
	nx.samples[nx.cur] = dt
	nx.cur++
	if int(nx.cur) >= len(nx.samples) {
		return 0
	}
	// TODO: this overwrites first 2 bytes
	t := g.Now()
	return copy(out, nx.nextPingPacket(t))
}

const (
	RecvCanRead = netlib.RecvCanRead
	RecvNoHooks = netlib.RecvNoHooks
	RecvJustOne = netlib.RecvJustOne
)

type RecvFlags = netlib.RecvFlags

func (ns *Conn) RecvLoop(flags RecvFlags) int {
	if ns == nil {
		return -3
	}

	argp := 1
	var err error
	if flags.Has(RecvCanRead) {
		argp, err = canReadConn(ns.g.Debug, ns.g.Log, ns.pc)
		if err != nil || argp == 0 {
			return -1
		}
	}

	var tmp [256]byte

	inJoin := true
	for {
		n, src := ns.g.recvRoot(&ns.recv, ns.pc)
		if n == -1 {
			return -1
		}
		if n <= 2 { // empty payload
			ns.recv.Reset()
			if !flags.Has(RecvCanRead) || flags.Has(RecvJustOne) {
				return n
			}
			argp, err = canReadConn(ns.g.Debug, ns.g.Log, ns.pc)
			if err != nil {
				return -1
			} else if argp == 0 {
				return n
			}
			continue
		}
		hdr := ns.recv.Bytes()[:3]
		a0 := hdr[0]
		h2 := ns.g.getForPacket(int(a0 & maskID))
		seq := hdr[1]
		op := noxnet.Op(hdr[2])
		if ns.g.Debug {
			ns.g.Log.Printf("servNetInitialPackets: op=%d (%s)\n", int(op), op.String())
		}
		dst := ns
		if op == codeDiscover12 {
			// Discover packets are not a part of the protocol, they are filtered out
			// and handled separately. Responses are written directly to underlying conn.
			n = ns.g.OnDiscover(ns.recv.Bytes(), tmp[:])
			if n > 0 {
				n, _ = ns.WriteToRaw(tmp[:n], src)
			}
			goto continueX
		}
		if op >= codeJoin14 && op <= codeACK20 {
			inJoin = true
		} else {
			if a0 == anyID {
				if !inJoin {
					goto continueX
				}
			} else {
				inJoin = false
				if !ns.g.hasConnWithIndAndAddr(h2, src) {
					goto continueX
				}
				inJoin = true
			}
			if ns.id == -1 {
				dst = h2.Get()
			}
			if a0&someIDFlag == 0 {
				if dst == nil {
					goto continueX
				}
				if seq != byte(dst.seqRecv) {
					ns9 := h2.Get()
					ns9.resendQueueBySeq(seq)
					ns9.maybeFreeQueue(seq, 1)
					dst.seqRecv = int8(seq)
					v20 := false
					if ns.readXxx(ns9, seq, ns.recv.Bytes()) {
						v20 = false
					} else {
						v20 = true
					}
					tmp[0] = byte(code38)
					tmp[1] = byte(dst.seqRecv)
					ns.callOnReceive(ns9, tmp[:2])
					if !v20 {
						goto continueX
					}
				}
			} else if a0 == anyID {
				if op == 0 {
					n = ns.processStreamOp(ns.recv.Bytes(), tmp[:], src)
					if n > 0 {
						n, _ = ns.WriteTo(tmp[:n], src)
					}
					goto continueX
				}
			} else {
				data := ns.recv.Bytes()
				data[0] &= maskID // TODO: fails without this
				h2 = ns.g.getForPacket(int(data[0]))
				if dst == nil {
					goto continueX
				}
				hdr2 := dst.Data2hdr()
				if hdr2[1] != seq {
					goto continueX
				}
				hdr2[1]++
				if ns.readXxx(h2.Get(), seq, ns.recv.Bytes()) {
					goto continueX
				}
			}
		}
		if op < code32 {
			n = ns.processStreamOp(ns.recv.Bytes(), tmp[:], src)
			if n > 0 {
				n, _ = ns.WriteTo(tmp[:n], src)
			}
		} else {
			if dst != nil && !flags.Has(RecvNoHooks) {
				ns.callOnReceive(h2.Get(), ns.recv.Bytes()[2:n])
			}
		}
	continueX:
		ns.recv.Reset()
		if !flags.Has(RecvCanRead) || flags.Has(RecvJustOne) {
			return n
		}
		argp, err = canReadConn(ns.g.Debug, ns.g.Log, ns.pc)
		if err != nil {
			return -1
		} else if argp == 0 {
			return n
		}
	}
	// unreachable
}

func (nx *stream2) nextPingPacket(t time.Duration) []byte {
	nx.ticks = t

	var buf [8]byte
	buf[2] = byte(codePing16)
	buf[3] = nx.cur
	binary.LittleEndian.PutUint32(buf[4:], uint32(nx.ticks/time.Millisecond))
	return buf[:]
}

func (g *Streams) sendTime(ind2 int) (int, error) {
	ns2 := &g.streams2[ind2]
	buf := ns2.nextPingPacket(g.Now())
	return g.lis.WriteTo(buf, ns2.addr)
}

func (g *Streams) sendCode20(ind2 int) (int, error) {
	var buf [3]byte
	buf[0] = 0
	buf[1] = 0
	buf[2] = byte(codeACK20)

	nx := &g.streams2[ind2]
	nx.active = false

	return g.lis.WriteTo(buf[:3], nx.addr)
}

func (g *Streams) sendCode19(code byte, ind2 int) (int, error) {
	var buf [4]byte
	buf[0] = 0
	buf[1] = 0
	buf[2] = byte(codeErrCode19)
	buf[3] = code

	nx := &g.streams2[ind2]
	nx.active = false

	return g.lis.WriteTo(buf[:4], nx.addr)
}

func (g *Streams) ProcessStats(min, max time.Duration) {
	start := g.Now()
	for i := range g.streams2 {
		nx := &g.streams2[i]
		if !nx.active {
			continue
		}
		v2 := nx.cur
		if int(v2) >= len(nx.samples) {
			if int(nx.lost) > g.MaxPacketLoss {
				_, _ = g.sendCode19(1, i)
				_, _ = g.sendCode20(i)
				continue
			}
			cnt := 0
			var sum time.Duration
			for i = 0; i < 10; i++ {
				if nx.samples[i] > 0 {
					cnt++
					sum += nx.samples[i]
				}
			}
			avg := sum / time.Duration(cnt)
			if min != -1 && avg < min {
				_, _ = g.sendCode19(0, i)
			}
			if max != -1 && avg > max {
				_, _ = g.sendCode19(1, i)
			}
			_, _ = g.sendCode20(i)
		} else {
			if start-nx.ticks > 2*time.Second {
				g.streams2[i].samples[v2] = -1
				nx.lost++
				if int(nx.lost) <= g.MaxPacketLoss {
					nx.cur++
					_, _ = g.sendTime(i)
				} else {
					_, _ = g.sendCode19(1, i)
				}
			}
		}
	}
}

func (ns *Conn) CountInQueue(ops ...noxnet.Op) int {
	if ns == nil {
		return 0
	}
	cnt := 0
	for it := ns.queue; it != nil; it = it.next {
		op := noxnet.Op(it.data[2])
		if len(ops) == 0 {
			cnt++
			continue
		}
		for _, op2 := range ops {
			if op == op2 {
				cnt++
				break
			}
		}
	}
	return cnt
}

func (ns *Conn) WaitServerResponse(seq int, try int, flags RecvFlags) int {
	if ns == nil {
		return -3
	}
	if ns.g.Debug {
		ns.g.Log.Printf("nox_xxx_cliWaitServerResponse_5525B0: %d, %d, %d\n", seq, try, flags)
	}

	if int(ns.seqRecv) >= seq {
		return 0
	}
	for i := 0; i <= 20*try; i++ {
		ns.g.Sleep(50 * time.Millisecond)
		ns.RecvLoop(flags | RecvCanRead)
		ns.g.MaybeSendQueues()
		if int(ns.seqRecv) >= seq {
			return 0
		}
		// FIXME(awesie)
		return 0
	}
	return -23
}

func (ns *Conn) SendSelfRaw(buf []byte) int {
	if ns == nil {
		return 0
	}
	n, _ := ns.WriteToRaw(buf, ns.addr)
	return n
}

func (ns *Conn) WriteToRaw(buf []byte, addr netip.AddrPort) (int, error) {
	if ns == nil || len(buf) == 0 {
		return 0, nil
	}
	return writeTo(ns.g.Debug, ns.g.Log, ns.pc, buf, addr)
}

func (ns *Conn) WriteTo(buf []byte, addr netip.AddrPort) (int, error) {
	if ns == nil || len(buf) == 0 {
		return 0, nil
	}
	ns2 := ns.g.connByAddr(addr)
	if ns2 == nil || ns2.xorKey == 0 {
		return ns.WriteToRaw(buf, addr)
	}
	dst := ns.g.sendXorBuf[:len(buf)]
	if ns.g.Xor {
		netCryptDst(ns2.xorKey, buf, dst)
	} else {
		copy(dst, buf)
	}
	return ns.WriteToRaw(dst, ns2.addr)
}

func netCryptDst(key byte, src, dst []byte) {
	if len(src) == 0 || len(dst) == 0 {
		return
	}
	for i := range src {
		dst[i] = key ^ src[i]
	}
}

type LobbyWaitOptions struct {
	OnResult func(addr netip.AddrPort, data []byte)
	OnCode15 func()
	OnPing   func(addr netip.AddrPort, data []byte)
	OnCode19 func(errcode byte) bool
	OnCode20 func()
	OnCode21 func()
}

func WaitForLobbyResults(conn net.PacketConn, srvAddr netip.Addr, flag RecvFlags, opts LobbyWaitOptions) (int, error) {
	argp := 0
	if flag.Has(RecvCanRead) {
		var err error
		argp, err = canReadConn(DebugSockets, Log, conn)
		if err != nil {
			return 0, err
		} else if argp == 0 {
			// TODO: is it an error at all?
			return 0, errors.New("nothing to read")
		}
	} else {
		argp = 1
	}
	buf := make([]byte, 256)
	for {
		buf = buf[:cap(buf)]
		n, from, err := readFrom(DebugSockets, Log, conn, buf)
		if err != nil {
			return 0, err
		}
		buf = buf[:n]
		op := noxnet.Op(buf[2])
		if op < code32 {
			if op == codeInfo13 || srvAddr == from.Addr() {
				switch op {
				case codeInfo13:
					if from.Addr().IsValid() {
						opts.OnResult(from, buf)
					}
				case codeErr15:
					opts.OnCode15()
				case codePing16:
					opts.OnPing(from, buf)
				case codeErrCode19:
					if !opts.OnCode19(buf[3]) {
						break
					}
				case codeACK20:
					opts.OnCode20()
				case codeErr21:
					opts.OnCode21()
				}
			}
		}
		if flag&RecvCanRead == 0 || (flag&RecvJustOne) != 0 {
			return n, nil
		}
		argp, err = canReadConn(DebugSockets, Log, conn)
		if err != nil {
			return n, err
		} else if argp == 0 {
			return n, nil
		}
	}
}
