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
		initIndex: -1,
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
	initIndex      int
	streams        [maxStructs]*conn
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

func (g *Streams) ByPlayer(p ntype.Player) Handle {
	return g.ByPlayerInd(p.PlayerIndex())
}

func (g *Streams) ByPlayerInd(pind ntype.PlayerInd) Handle {
	return Handle{g, int(pind) + 1}
}

func (g *Streams) ByIndexRaw(ind int) Handle {
	return Handle{g, ind}
}

func (g *Streams) First() Handle {
	return Handle{g, 0}
}

func (h Handle) addTransferStats(n int) {
	h.g.transfer[h.i] += uint32(n)
}

func (h Handle) TransferStats() uint32 {
	if !h.Valid() {
		return 0
	}
	val := h.g.transfer[h.i]
	h.g.transfer[h.i] = 0
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
	for i := range g.streams {
		if g.streams[i] == nil {
			return i, true
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

func (g *Streams) connByAddr(addr netip.AddrPort) *conn {
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

type Handler func(id Handle, buf []byte) int

type Options struct {
	Port       int
	Max        int
	BufferSize int
	OnSend     Handler
	OnReceive  Handler
	OnJoin     JoinCheck
	Check17    Check17
}

func (g *Streams) newStream(opt *Options) *conn {
	ns := &conn{
		g:         g,
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
	return ns
}

func (ns *conn) reset() {
	if ns == nil {
		return
	}
	ns.recv.Reset()
	*ns = conn{g: ns.g}
}

func (ns *conn) Close() error {
	if ns == nil {
		return nil
	}
	if ns.pc != nil {
		if ns.g.Debug {
			ns.g.Log.Printf("closing connection: %d", ns.id.i)
		}
		_ = ns.pc.Close()
	}
	ns.pc = nil
	ns.reset()
	return nil
}

func (h Handle) Close() {
	if ns := h.get(); ns != nil {
		_ = ns.Close()
		h.g.streams[h.i] = nil
	}
}

func (g *Streams) Listen(opt *Options) (Handle, error) {
	if opt == nil {
		return Handle{nil, -2}, errors.New("empty options")
	}
	if opt.Max > maxStructs {
		return Handle{nil, -2}, errors.New("max limit reached")
	}
	if opt.Port < 1024 || opt.Port > 0x10000 {
		opt.Port = common.GamePort
	}
	pc, port, err := listenOnFreePort(g.Log, opt.Port)
	if err != nil {
		return Handle{nil, -5}, err
	}
	opt.Port = port
	ind, ok := g.getFreeIndex()
	if !ok {
		_ = pc.Close()
		return Handle{nil, -8}, errors.New("no more slots for net structs")
	}
	ns := g.newStream(opt)
	ns.id = Handle{g, -1}
	ns.pc = pc
	g.streams[ind] = ns
	ns.Data2hdr()[0] = byte(ind)
	g.initIndex = ind
	return Handle{g, ind}, nil
}

func (g *Streams) NewClient(narg *Options) (Handle, error) {
	if narg == nil {
		return Handle{nil, -2}, NewConnectErr(-2, errors.New("empty options"))
	}
	ind, ok := g.getFreeIndex()
	if !ok {
		return Handle{nil, -8}, NewConnectErr(-8, errors.New("no more slots for net structs"))
	}
	ns := g.newStream(narg)
	g.streams[ind] = ns
	return Handle{g, ind}, nil
}

func (h Handle) Dial(host string, port int, cport int, opts encoding.BinaryMarshaler) error {
	if h.g.Debug {
		h.g.Log.Println("NET_CONNECT", h, host, port)
	}
	ns := h.get()
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
		sock, err := listen(h.g.Log, netip.AddrPortFrom(netip.IPv4Unspecified(), uint16(cport)))
		if err == nil {
			ns.pc = sock
			break
		} else if !ErrIsInUse(err) {
			return NewConnectErr(-1, err)
		}
		cport++
	}
	h.g.Responded = false
	var v12 [1]byte // TODO: sending zero, is that correct? if so, set explicitly here
	v11, err := h.Send(v12[:], SendQueue|SendFlush)
	if err != nil {
		return fmt.Errorf("cannot send data: %w", err)
	}

	retries, counter := 60, 0
	for {
		ns := h.get()
		if ns == nil {
			return NewConnectErr(-23, errors.New("no net struct"))
		}
		//counter = 0 // TODO: is this correct?
		counter++
		if counter > 20*retries {
			return NewConnectErr(-23, errors.New("timeout"))
		}
		h.RecvLoop(RecvCanRead | RecvNoHooks | RecvJustOne)
		h.g.MaybeSendQueues()
		f28 := int(ns.seqRecv)
		if f28 >= v11 {
			break
		}
		h.g.Sleep(30 * time.Millisecond)
	}

	ns = h.get()
	if h.g.Responded && ns.Handle().Valid() {
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
		_, _ = h.Send(buf, SendQueue|SendFlush)
	}

	if !ns.Handle().Valid() {
		return NewConnectErr(-1, errors.New("invalid net struct id"))
	}
	return nil
}

func (h Handle) DialWait(timeout time.Duration, send func(), check func() bool) error {
	deadline := h.g.Now() + timeout
	if h.g.Debug {
		h.g.Log.Println("CONNECT_WAIT_LOOP_START", deadline)
	}
	for {
		now := h.g.Now()
		if timeout >= 0 && now >= deadline {
			return NewConnectErr(-19, errors.New("timeout 2"))
		}
		h.RecvLoop(RecvCanRead)
		send()
		h.g.MaybeSendQueues()
		if check() {
			break
		}
		h.g.Sleep(5 * time.Millisecond)
	}
	return nil
}

type conn struct {
	g    *Streams
	pc   net.PacketConn
	addr netip.AddrPort
	id   Handle

	recv bytes.Buffer

	sendBuf   []byte
	sendWrite int

	max       uint32
	accepted  uint32
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

func (ns *conn) String() string {
	if ns == nil {
		return "<nil>"
	}
	return fmt.Sprintf("Conn(id: %d, addr: %s)", ns.id.i, ns.addr.String())
}

func (ns *conn) Addr() netip.AddrPort {
	if ns == nil {
		return netip.AddrPort{}
	}
	return ns.addr
}

func (ns *conn) SetAddr(addr netip.AddrPort) {
	ns.addr = addr
}

func (ns *conn) Handle() Handle {
	if ns == nil {
		return Handle{nil, -1}
	}
	return ns.id
}

func (ns *conn) Data2hdr() *[2]byte {
	if ns == nil {
		var v [2]byte
		return &v
	}
	return (*[2]byte)(ns.sendBuf[:2])
}

func (ns *conn) SendReadBuf() []byte {
	if ns == nil {
		return nil
	}
	return ns.sendBuf[:ns.sendWrite]
}

func (ns *conn) SendWriteBuf() []byte {
	if ns == nil {
		return nil
	}
	return ns.sendBuf[ns.sendWrite:]
}

func (ns *conn) callOnSend(id Handle, buf []byte) int {
	if ns.onSend == nil {
		return 0
	}
	return ns.onSend(id, buf)
}

func (ns *conn) callOnReceive(id Handle, buf []byte) int {
	if ns.onReceive == nil {
		return 0
	}
	return ns.onReceive(id, buf)
}

const (
	SendQueue = netlib.SendQueue
	SendFlush = netlib.SendFlush
)

type SendFlags = netlib.SendFlags

func (h Handle) SendMsg(msg noxnet.Message, flags SendFlags) (int, error) {
	buf, err := noxnet.AppendPacket(nil, msg)
	if err != nil {
		return 0, err
	}
	return h.Send(buf, flags)
}

func (h Handle) Send(buf []byte, flags SendFlags) (int, error) {
	ns := h.get()
	if ns == nil {
		return -3, errors.New("no net struct")
	}
	if len(buf) == 0 {
		return -2, errors.New("empty buffer")
	}
	var (
		idd    Handle
		ei, si Handle
	)
	if ns.id.i == -1 {
		si = Handle{h.g, 0}
		ei = Handle{h.g, maxStructs}
		idd = h
	} else {
		si = h
		ei = Handle{h.g, h.i + 1}
		idd = ns.Handle()
	}
	if flags.Has(SendQueue) {
		n := len(buf)
		for i := si.i; i < ei.i; i++ {
			ns2 := Handle{h.g, i}.get()
			if ns2 != nil && ns2.Handle() == idd {
				seq, err := ns2.addToQueue(buf)
				if seq == -1 {
					return -1, err
				}
				n = seq
				if flags.Has(SendFlush) {
					ns2.sendQueueSeq(byte(seq))
				}
			}
		}
		return n, nil
	}
	n := len(buf)
	for i := si.i; i < ei.i; i++ {
		ns2 := Handle{h.g, i}.get()
		if ns2 == nil {
			continue
		}
		if ns2.Handle() != idd {
			continue
		}
		d2x := ns2.SendWriteBuf()
		if n+1 > len(d2x) {
			return -7, errors.New("buffer too short")
		}
		if flags.Has(SendFlush) {
			copy(d2x[:2], ns2.Data2hdr()[:2])
			copy(d2x[2:2+n], buf)
			n2, err := ns2.WriteTo(d2x[:n+2], ns2.addr)
			if n2 == -1 {
				return -1, err
			}
			h.addTransferStats(n + 2)
			return n2, nil
		}
		copy(d2x[:n], buf)
		ns2.sendWrite += n
	}
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

func (ns *conn) addToQueue(buf []byte) (int, error) {
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

func (ns *conn) sendQueueSeq(seq byte) int {
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

func (ns *conn) sendQueueActive() int {
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

func (ns *conn) resendQueueBySeq(seq byte) {
	if ns == nil {
		return
	}
	for it := ns.queue; it != nil; it = it.next {
		if it.data[1] == seq {
			it.active = true
		}
	}
}

func (ns *conn) queueByTime() {
	if ns == nil {
		return
	}
	for it := ns.queue; it != nil; it = it.next {
		if it.retryAt <= ns.g.ticks2 {
			it.active = true
		}
	}
}

func (g *Streams) GetInitInd() Handle {
	if g.initIndex < 0 {
		return Handle{}
	}
	return Handle{g, g.initIndex}
}

func (h Handle) SendReadPacket(noHooks bool) int {
	ns := h.get()
	if ns == nil {
		return -3
	}
	find := h
	var min, max Handle
	if ns.id.i != -1 {
		min = h
		max = Handle{h.g, h.i + 1}
		find = ns.id
	} else {
		min = Handle{h.g, 0}
		max = Handle{h.g, maxStructs}
	}
	for j := min.i; j < max.i; j++ {
		ns2 := h.g.streams[j]
		h2 := Handle{h.g, j}
		if ns2 == nil || ns2.id != find {
			continue
		}
		ns2.sendQueueActive()
		if !noHooks {
			buf := ns2.SendWriteBuf()
			n := ns2.callOnSend(h2, buf)
			if n > 0 && n <= len(buf) {
				ns2.sendWrite += n
			}
		}
		if buf := ns2.SendReadBuf(); len(buf) > 2 {
			_, err := ns.WriteTo(buf, ns2.addr)
			if err != nil {
				return -1
			}
			h2.addTransferStats(len(buf))
			ns2.sendWrite = 2
		}
	}
	return 0
}

func (ns *conn) maybeFreeQueue(seq byte, act int) {
	if ns == nil {
		return
	}
	var (
		next *queueItem
		prev *queueItem
	)
	for it := ns.queue; it.next != nil; it = next {
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

func (g *Streams) ReadPackets(ind Handle) int {
	if !ind.Valid() {
		return -3
	}
	ns := ind.get()
	if ns == nil {
		return 0
	}
	v4 := ns.Handle()
	var si, ei Handle
	if v4.i == -1 {
		si, ei = Handle{g, 0}, Handle{g, maxStructs}
		v4 = ind
	} else {
		si, ei = ind, Handle{g, ind.i + 1}
		ns2 := v4.get()
		if ns2 == nil || ns2.id.i != -1 {
			ns.reset()
			g.streams[ind.i] = nil
			return 0
		}
	}
	for i := si.i; i < ei.i; i++ {
		ii := Handle{g, i}
		ns2 := ii.get()
		if ns2 == nil || ns2.Handle() != v4 {
			continue
		}
		ii.SendReadPacket(true)
		var buf [1]byte
		buf[0] = byte(code11)
		_, _ = ii.Send(buf[:], 0)
		ii.SendReadPacket(true)
		v4.get().accepted--
		ns.maybeFreeQueue(0, 2)
		ns2.reset()
		g.streams[ii.i] = nil
	}
	return 0
}

func (g *Streams) maybeReadPackets() {
	g.ticks2 = g.Now()
	for i, ns := range g.streams {
		if ns == nil {
			continue
		}
		if ns.field38 == 1 && ns.frame40+300 < g.GameFrame() {
			g.ReadPackets(Handle{g, i})
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

func (ns *conn) IP() netip.Addr {
	if ns == nil {
		return netip.Addr{}
	}
	return ns.addr.Addr()
}

func (h Handle) SendClose() {
	if h.get() == nil {
		return
	}
	h.SendReadPacket(false)
	var buf [1]byte
	buf[0] = byte(code10)
	_, _ = h.Send(buf[:1], 0)
	h.SendReadPacket(false)
	h.Close()
}

func (g *Streams) processStreamOp0(id Handle, out []byte, pid Handle, p1 byte, ns1 *conn, from netip.AddrPort) int {
	if f := g.GameFlags(); f.Has(noxflags.GameHost) && f.Has(noxflags.GameFlag4) {
		return 0
	}
	out[0] = 0
	out[1] = p1
	if int(ns1.accepted) >= g.GetMaxPlayers()+(g.cntX-1) {
		out[2] = byte(codeErr2)
		return 3
	}
	if pid.i != -1 {
		g.Log.Printf("pid must be set to -1 when joining: was %d (%s)\n", pid.i, from.String())
		// pid in the request must be -1 (0xff); fail if it's not
		out[2] = byte(codeErr2)
		return 3
	}
	// now, find free net struct index and use it as pid
	for i, it := range g.streams {
		if it == nil {
			pid = Handle{g, i}
			break
		}
		if from == it.addr {
			out[2] = byte(codeAlreadyJoined4) // already joined?
			return 3
		}
	}
	if pid.i == -1 {
		out[2] = byte(codeErr2)
		return 3
	}
	ns2 := g.newStream(&Options{
		BufferSize: len(ns1.sendBuf),
		OnJoin:     ns1.onJoin,
		Check17:    ns1.check17,
	})
	g.streams[pid.i] = ns2
	ns1.accepted++

	hdr := ns2.Data2hdr()
	hdr[0] = byte(id.i)
	if hdr[1] == p1 {
		hdr[1]++
	}
	ns2.id = id
	ns2.pc = ns1.pc
	ns2.onSend = ns1.onSend
	ns2.onReceive = ns1.onReceive

	g.timing[id.i] = timingStruct{field28: 1}
	key := byte(g.KeyRand(1, 255))
	if !g.Xor {
		key = 0
	}
	ns2.xorKey = 0 // send this packet without xor encoding

	ns2.SetAddr(from)

	out[0] = byte(code31) // TODO: it's not a code here, but an ID?
	out[1] = p1
	out[2] = byte(codeNewStream1)
	binary.LittleEndian.PutUint32(out[3:], uint32(pid.i))
	out[7] = key
	v67, _ := pid.Send(out[:8], SendQueue|SendFlush)

	ns2.xorKey = key
	ns2.field38 = 1
	ns2.seq39 = byte(v67)
	ns2.frame40 = g.GameFrame()
	return 0
}

func (g *Streams) processStreamOp6(pid Handle, out []byte, ns1 *conn, packetCur []byte) int {
	if len(packetCur) < 4 {
		return 0
	}
	v := binary.LittleEndian.Uint32(packetCur[:4])

	ns2 := pid.get()
	if ns2 == nil {
		return 0
	}
	out[0] = byte(code37)
	ns1.callOnReceive(pid, out[:1])

	g.timing[pid.i].field4 = v
	var hdr *[2]byte
	if ns1.id.i == -1 {
		out[0] = byte(ns2.id.i)
		hdr = ns2.Data2hdr()
	} else {
		out[0] = byte(ns1.id.i)
		hdr = ns1.Data2hdr()
	}
	out[1] = hdr[0]
	out[2] = byte(code8)
	binary.LittleEndian.PutUint32(out[3:], v)
	return 7
}

func (g *Streams) processStreamOp7(pid Handle, out []byte, ns1 *conn) int {
	ns4 := pid.get()
	if ns4 == nil {
		return 0
	}
	ms := int((g.ticks2 - ns4.ticks24) / time.Millisecond)
	speed := -1
	if ms >= 1 {
		speed = 256000 / ms
	}
	out[0] = byte(code35)
	binary.LittleEndian.PutUint32(out[1:], uint32(speed))
	// TODO: these two were sending hook payload from either ns1 or ns4
	if ns1.id.i == -1 {
		ns1.callOnReceive(pid, out[:5])
	} else {
		ns1.callOnReceive(pid, out[:5])
	}
	return 0
}

func (g *Streams) processStreamOp8(pid Handle, out []byte, ns1 *conn, packetCur []byte) int {
	ns5 := pid.get()
	if ns5 == nil && binary.LittleEndian.Uint32(packetCur) != uint32(ns5.ticks22/time.Millisecond) {
		return 0
	}
	dt := g.ticks2 - ns5.ticks23
	ns5.ticks24 = dt
	out[0] = byte(code36) // MSG_PING?
	ms := int(dt / time.Millisecond)
	binary.LittleEndian.PutUint32(out[1:], uint32(ms))
	// TODO: these two were sending hook payload from either ns1 or ns5
	if ns1.id.i == -1 {
		ns1.callOnReceive(pid, out[:5])
	} else {
		ns1.callOnReceive(pid, out[:5])
	}

	out[0] = ns1.Data2hdr()[0]
	out[1] = ns5.Data2hdr()[1]
	out[2] = byte(code9)
	ms = int(g.ticks2 / time.Millisecond)
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

func (g *Streams) processStreamOp14(out []byte, packet []byte, ns1 *conn, p1 byte, from netip.AddrPort, check JoinCheck) int {
	out[0] = 0
	out[1] = p1

	a4a := false
	if int(ns1.accepted) >= g.GetMaxPlayers()-1 {
		a4a = true
	}
	if n := check(out, packet, a4a, func(pl ntype.Player) bool {
		pid := g.ByPlayer(pl)
		if _, ok := g.playerIDs[pid]; ok {
			return false
		}
		g.playerIDs[pid] = struct{}{}
		g.cntX++
		return true
	}); n != 0 {
		return n
	}

	ind2 := g.getFreeNetStruct2Ind()
	if ind2 < 0 {
		out[2] = byte(codeACK20)
		return 3
	}
	nx := &g.streams2[ind2]
	nx.active = true
	nx.cur = 0
	nx.lost = 0
	nx.addr = from

	// TODO: this overwrites first 2 bytes
	t := g.Now()
	return copy(out, nx.nextPingPacket(t))
}

func (g *Streams) SendCode6(ind Handle) int {
	var buf [5]byte

	ns := ind.get()
	if ns == nil {
		return -3
	}
	var (
		min, max Handle
		find     Handle
	)
	if ns.id.i == -1 {
		min = Handle{g, 0}
		max = Handle{g, maxStructs}
		find = ind
	} else {
		min = ind
		max = Handle{g, ind.i + 1}
		find = ns.id
	}
	buf[0] = byte(code6)
	for i := min.i; i < max.i; i++ {
		ns2 := g.streams[i]
		if ns2 != nil && ns2.id == find {
			ns2.ticks22 = g.ticks2
			ns2.ticks23 = ns2.ticks22
			binary.LittleEndian.PutUint32(buf[1:], uint32(ns2.ticks22/time.Millisecond))
			_, _ = Handle{g, i}.Send(buf[:5], SendFlush)
		}
	}
	return 0
}

func (g *Streams) readXxx(id1, id2 Handle, a3 byte, buf []byte) bool {
	ns2 := id2.get()
	if ns2 == nil || ns2.field38 != 1 || ns2.seq39 > a3 {
		return false
	}
	ns1 := id1.get()
	if int(ns1.accepted) > (g.GetMaxPlayers() - 1) {
		g.ReadPackets(id2)
		return true
	}
	if len(buf) >= 4 && buf[4] == 32 {
		ns2.field38 = 2
		ns2.seq39 = 0xff
		ns2.frame40 = 0
		ns1.callOnReceive(id2, buf[4:])
	}
	return true
}

func (g *Streams) processStreamOp(id Handle, packet []byte, out []byte, from netip.AddrPort) int {
	if len(packet) < 2 {
		return 0
	}
	pid := Handle{g, int(int8(packet[0]))}
	p1 := packet[1]
	packetCur := packet[2:]

	ns1 := id.get()
	if ns1 == nil {
		return 0
	}

	pidb := pid // TODO: some of the functions assume it's different from pid, check what's wrong
	for len(packetCur) != 0 {
		op := packetCur[0]
		packetCur = packetCur[1:]
		if g.Debug {
			g.Log.Printf("processStreamOp: op=%d [%d]\n", op, len(packetCur))
		}
		switch noxnet.Op(op) {
		default:
			return 0
		case codeInit0:
			return g.processStreamOp0(id, out, pidb, p1, ns1, from)
		case codeNewStream1:
			if len(packetCur) < 5 {
				return 0
			}
			v11 := Handle{g, int(binary.LittleEndian.Uint32(packetCur[:4]))}
			xor := packetCur[4]
			packetCur = packetCur[5:]

			ns1.id = v11
			ns1.Data2hdr()[0] = byte(v11.i)
			ns1.xorKey = xor
			g.Responded = true
		case codeErr2:
			ns1.id.i = -18
			g.Responded = true
		case code3: // ack?
			ns1.id.i = -12
			g.Responded = true
		case codeAlreadyJoined4:
			ns1.id.i = -13
			g.Responded = true
		case code5:
			if len(packetCur) < 4 {
				return 0
			}
			v := binary.LittleEndian.Uint32(packetCur[:4])
			out[0] = ns1.xorKey
			out[1] = 0
			out[2] = byte(code7)
			binary.LittleEndian.PutUint32(out[3:], v)
			return 7
		case code6:
			return g.processStreamOp6(pid, out, ns1, packetCur)
		case code7:
			return g.processStreamOp7(pid, out, ns1)
		case code8:
			return g.processStreamOp8(pid, out, ns1, packetCur)
		case code9:
			return g.processStreamOp9(pid, packetCur)
		case code10:
			return g.processStreamOp10(id, pid, out, ns1)
		case code11:
			ns7 := pid.get()
			if ns7 == nil {
				return 0
			}
			out[0] = byte(code33)
			ns1.callOnReceive(pid, out[:1])
			id.Close()
			return 0
		case codeJoin14: // join game request?
			return g.processStreamOp14(out, packet, ns1, p1, from, ns1.onJoin)
		case code17:
			return g.processStreamOp17(out, packet, p1, from, ns1.check17)
		case codePong18:
			return g.processPong(out, packet, from)
		case code31:
			if len(packetCur) < 1 {
				return 0
			}
			seq := packetCur[0]
			packetCur = packetCur[1:]

			ns8 := pidb.get()
			if ns8 == nil {
				return 0
			}
			g.Log.Printf("switch 31: 0x%x 0x%x\n", seq, ns8.seqRecv)
			if seq != byte(ns8.seqRecv) {
				ns9 := pid.get()
				ns9.resendQueueBySeq(seq)
				ns9.maybeFreeQueue(seq, 1)
				ns8.seqRecv = int8(seq)
				out[0] = byte(code38)
				out[1] = seq
				ns1.callOnReceive(pid, out[:2])
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

func (g *Streams) processStreamOp10(id Handle, pid Handle, out []byte, ns1 *conn) int {
	if pid.i == -1 {
		return 0
	}
	ns6 := pid.get()
	if ns6 == nil || ns6.field38 == 1 {
		return 0
	}
	out[0] = byte(code34)
	ns1.callOnReceive(pid, out[:1])

	g.timing[id.i] = timingStruct{}

	if _, ok := g.playerIDs[pid]; ok {
		delete(g.playerIDs, pid)
		g.cntX--
	}

	g.ReadPackets(pid)
	return 0
}

type Check17 func(out []byte, packet []byte) int

func (g *Streams) processStreamOp17(out []byte, packet []byte, p1 byte, from netip.AddrPort, check Check17) int {
	out[0] = 0
	out[1] = p1
	if n := check(out, packet); n != 0 {
		return n
	}
	ind2 := g.getFreeNetStruct2Ind()
	if ind2 < 0 {
		out[2] = byte(codeACK20)
		return 3
	}
	nx := &g.streams2[ind2]
	nx.active = true
	nx.cur = 0
	nx.lost = 0
	nx.addr = from

	// TODO: this overwrites first 2 bytes
	t := g.Now()
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

func (h Handle) RecvLoop(flags RecvFlags) int {
	ns := h.get()
	if ns == nil {
		return -3
	}

	argp := 1
	var err error
	if flags.Has(RecvCanRead) {
		argp, err = canReadConn(h.g.Debug, h.g.Log, ns.pc)
		if err != nil || argp == 0 {
			return -1
		}
	}

	var tmp [256]byte

	inJoin := true
	for {
		n, src := h.g.recvRoot(&ns.recv, ns.pc)
		if n == -1 {
			return -1
		}
		if n <= 2 { // empty payload
			ns.recv.Reset()
			if !flags.Has(RecvCanRead) || flags.Has(RecvJustOne) {
				return n
			}
			argp, err = canReadConn(h.g.Debug, h.g.Log, ns.pc)
			if err != nil {
				return -1
			} else if argp == 0 {
				return n
			}
			continue
		}
		hdr := ns.recv.Bytes()[:3]
		a0 := hdr[0]
		h2 := Handle{h.g, int(a0 & maskID)}
		seq := hdr[1]
		op := noxnet.Op(hdr[2])
		if h.g.Debug {
			h.g.Log.Printf("servNetInitialPackets: op=%d (%s)\n", int(op), op.String())
		}
		dst := ns
		if op == codeDiscover12 {
			// Discover packets are not a part of the protocol, they are filtered out
			// and handled separately. Responses are written directly to underlying conn.
			n = h.g.OnDiscover(ns.recv.Bytes(), tmp[:])
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
				if !h.g.hasConnWithIndAndAddr(h2, src) {
					goto continueX
				}
				inJoin = true
			}
			if ns.id.i == -1 {
				dst = h2.get()
			}
			if a0&someIDFlag == 0 {
				if dst == nil {
					goto continueX
				}
				if seq != byte(dst.seqRecv) {
					ns9 := h2.get()
					ns9.resendQueueBySeq(seq)
					ns9.maybeFreeQueue(seq, 1)
					dst.seqRecv = int8(seq)
					v20 := false
					if h.g.readXxx(h, h2, seq, ns.recv.Bytes()) {
						v20 = false
					} else {
						v20 = true
					}
					tmp[0] = byte(code38)
					tmp[1] = byte(dst.seqRecv)
					ns.callOnReceive(h2, tmp[:2])
					if !v20 {
						goto continueX
					}
				}
			} else if a0 == anyID {
				if op == 0 {
					n = h.g.processStreamOp(h, ns.recv.Bytes(), tmp[:], src)
					if n > 0 {
						n, _ = ns.WriteTo(tmp[:n], src)
					}
					goto continueX
				}
			} else {
				data := ns.recv.Bytes()
				data[0] &= maskID // TODO: fails without this
				h2 = Handle{h.g, int(data[0])}
				if dst == nil {
					goto continueX
				}
				hdr2 := dst.Data2hdr()
				if hdr2[1] != seq {
					goto continueX
				}
				hdr2[1]++
				if h.g.readXxx(h, h2, seq, ns.recv.Bytes()) {
					goto continueX
				}
			}
		}
		if op < code32 {
			n = h.g.processStreamOp(h, ns.recv.Bytes(), tmp[:], src)
			if n > 0 {
				n, _ = ns.WriteTo(tmp[:n], src)
			}
		} else {
			if dst != nil && !flags.Has(RecvNoHooks) {
				ns.callOnReceive(h2, ns.recv.Bytes()[2:n])
			}
		}
	continueX:
		ns.recv.Reset()
		if !flags.Has(RecvCanRead) || flags.Has(RecvJustOne) {
			return n
		}
		argp, err = canReadConn(h.g.Debug, h.g.Log, ns.pc)
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
	ns := g.streams[g.initIndex]
	ns2 := &g.streams2[ind2]
	buf := ns2.nextPingPacket(g.Now())
	return ns.WriteTo(buf, ns2.addr)
}

func (g *Streams) sendCode20(ind2 int) (int, error) {
	ns := g.streams[g.initIndex]
	var buf [3]byte
	buf[0] = 0
	buf[1] = 0
	buf[2] = byte(codeACK20)

	nx := &g.streams2[ind2]
	nx.active = false

	return ns.WriteTo(buf[:3], nx.addr)
}

func (g *Streams) sendCode19(code byte, ind2 int) (int, error) {
	ns := g.streams[g.initIndex]
	var buf [4]byte
	buf[0] = 0
	buf[1] = 0
	buf[2] = byte(codeErrCode19)
	buf[3] = code

	nx := &g.streams2[ind2]
	nx.active = false

	return ns.WriteTo(buf[:4], nx.addr)
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

func (h Handle) CountInQueue(ops ...noxnet.Op) int {
	ns := h.get()
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

func (h Handle) WaitServerResponse(seq int, try int, flags RecvFlags) int {
	if h.g.Debug {
		h.g.Log.Printf("nox_xxx_cliWaitServerResponse_5525B0: %d, %d, %d, %d\n", h.i, seq, try, flags)
	}
	ns := h.get()
	if ns == nil {
		return -3
	}

	if int(ns.seqRecv) >= seq {
		return 0
	}
	for i := 0; i <= 20*try; i++ {
		h.g.Sleep(50 * time.Millisecond)
		h.RecvLoop(flags | RecvCanRead)
		h.g.MaybeSendQueues()
		if int(ns.seqRecv) >= seq {
			return 0
		}
		// FIXME(awesie)
		return 0
	}
	return -23
}

func (h Handle) SendSelfRaw(buf []byte) int {
	return h.get().SendSelfRaw(buf)
}

func (ns *conn) SendSelfRaw(buf []byte) int {
	if ns == nil {
		return 0
	}
	n, _ := ns.WriteToRaw(buf, ns.addr)
	return n
}

func (ns *conn) WriteToRaw(buf []byte, addr netip.AddrPort) (int, error) {
	if ns == nil || len(buf) == 0 {
		return 0, nil
	}
	return writeTo(ns.g.Debug, ns.g.Log, ns.pc, buf, addr)
}

func (ns *conn) WriteTo(buf []byte, addr netip.AddrPort) (int, error) {
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
