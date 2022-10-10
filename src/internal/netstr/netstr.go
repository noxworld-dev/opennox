package netstr

import (
	"encoding"
	"encoding/binary"
	"errors"
	"fmt"
	"math/rand"
	"net"
	"sync"
	"time"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/env"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/platform"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

const (
	maxStructs = 128
)

var (
	Xor           = true
	Debug         bool
	PacketDrop    int
	MaxPacketLoss = 3
	Log           = log.New("network")
)

var (
	GameFrame     func() uint32
	GetMaxPlayers func() int
	OnDiscover    func(src, dst []byte) int
	OnExtPacket   func(s *Socket, buf1 []byte, from net.Addr)
	KeyRand       = func(min, max int) int {
		return min + rand.Intn(max-min)
	}
	PacketDropRand = func(min, max int) int {
		return min + rand.Intn(max-min)
	}
)

var (
	once       sync.Once
	ticks1     uint32
	ticks2     uint32
	cntX       int
	initIndex  int
	Flag1      bool
	structs    [maxStructs]*netStruct
	structs2   [maxStructs]netStruct2
	timing     [maxStructs]timingStruct
	stats      [maxStructs]uint32
	allocQueue alloc.ClassT[queueItem]
	playerIDs  = make(map[int]struct{})
)

func GetStat(ind int) uint32 {
	v := stats[ind]
	stats[ind] = 0
	return v
}

func Init() {
	once.Do(func() {
		for i := range structs {
			structs[i] = nil
		}
		for i := range structs2 {
			structs2[i] = netStruct2{}
		}
		allocQueue = alloc.NewClassT("GQueue", queueItem{}, 200)
	})
}

func Update() {
	sub5524C0()
	MaybeSendAll()
}

type timingStruct struct {
	field0  uint32
	field4  uint32
	field8  [5]uint32
	field28 uint32
}

type queueItem struct {
	next   *queueItem
	ticks  uint32
	active bool
	size   uint32
	data   [1024]byte
}

type netStruct2 struct {
	flag  bool
	cnt   uint8
	addr  net.Addr
	cur   uint8 // index into arr
	arr   [10]int
	ticks uint32
}

func structByInd(i int) *netStruct {
	if i < 0 || i >= maxStructs {
		return nil
	}
	return structs[i]
}

func getFreeNetStruct() int {
	for i := range structs {
		if structs[i] == nil {
			return i
		}
	}
	return -1
}

func getFreeNetStruct2Ind() int {
	for i := range structs {
		if !structs2[i].flag {
			return i
		}
	}
	return -1
}

func structByAddr(ip net.IP, port int) *netStruct {
	for i := range structs {
		ns := structs[i]
		if ns == nil {
			continue
		}
		ip2, port2 := ns.Addr()
		if port == port2 && ip.Equal(ip2) {
			return ns
		}
	}
	return nil
}

func struct2IndByAddr(addr net.Addr) int {
	ip, port := GetAddr(addr)
	for i := range structs2 {
		nx := &structs2[i]
		ip2, port2 := GetAddr(nx.addr)
		if ip.Equal(ip2) && port == port2 {
			return i
		}
	}
	return -1
}

func hasStructWithIndAndAddr(ind int, ip net.IP, port int) bool {
	for i := range structs {
		ns := structs[i]
		if ns == nil {
			continue
		}
		ip2, port2 := ns.Addr()
		if port == port2 && ip.Equal(ip2) && ind == i {
			return true
		}
	}
	return false
}

type Handler func(a1 int, a2 []byte, a3 unsafe.Pointer) int

type Options struct {
	Port      int
	Max       int
	DataSize  int
	Data3Size int
	Func1     Handler
	Func2     Handler
	Check14   Check14
	Check17   Check17
}

func newStruct(opt *Options) *netStruct {
	ns := new(netStruct)

	if opt.Data3Size > 0 {
		ns.data3, _ = alloc.Malloc(uintptr(opt.Data3Size))
	}
	if dsz := opt.DataSize; dsz > 0 {
		dsz -= dsz % 4
		opt.DataSize = dsz
	} else {
		opt.DataSize = 1024
	}
	data1, _ := alloc.Make([]byte{}, opt.DataSize+2)
	ns.data1 = data1
	ns.data1xxx = 0
	ns.data1yyy = 0

	data2, _ := alloc.Make([]byte{}, opt.DataSize+2)
	data2[0] = 0xff
	ns.data2 = data2
	ns.data2xxx = 2
	ns.data2yyy = 2

	ns.max = uint32(opt.Max)
	ns.func1 = opt.Func1
	ns.func2 = opt.Func2
	ns.ind28 = -1
	ns.xorKey = 0

	ns.check14 = opt.Check14
	ns.check17 = opt.Check17
	return ns
}

func CloseByInd(ind int) {
	if ns := structByInd(ind); ns != nil {
		_ = ns.sock.Close()
		ns.sock = nil
		ns.FreeXxx()
		structs[ind] = nil
	}
}

func NewClient(narg *Options) (ind int, _ error) {
	if narg == nil {
		return -2, NewConnectFailErr(-2, errors.New("empty options"))
	}
	ind = getFreeNetStruct()
	if ind < 0 {
		return -8, NewConnectFailErr(-8, errors.New("no more slots for net structs"))
	}
	ns := newStruct(narg)
	structs[ind] = ns
	return ind, nil
}

func Dial(ind int, host string, port int, cport int, opts encoding.BinaryMarshaler) error {
	if Debug {
		Log.Println("NET_CONNECT", ind, host, port)
	}
	ns := structByInd(ind)
	if ns == nil {
		return NewConnectFailErr(-3, errors.New("no net struct"))
	}
	if len(host) == 0 {
		return NewConnectFailErr(-4, errors.New("empty hostname"))
	}
	if port < 1024 || port > 0x10000 {
		return NewConnectFailErr(-15, errors.New("invalid port"))
	}
	var ip net.IP
	if host[0] < '0' || host[0] > '9' {
		list, err := net.LookupIP(host)
		if err != nil || len(list) == 0 {
			log.Printf("error: cannot find ip for a host %q: %v", host, err)

			return NewConnectFailErr(-4, err)
		}
		ip = list[0]
	} else {
		ip = net.ParseIP(host)
	}
	ns.SetAddr(ip, port)

	for {
		sock, err := udpListen(nil, cport)
		if err == nil {
			ns.sock = sock
			break
		} else if !ErrIsInUse(err) {
			return NewConnectFailErr(-1, err)
		}
		cport++
	}
	Flag1 = false
	var v12 [1]byte
	v11, err := Send(ind, v12[:], SendNoLock|SendFlagFlush)
	if err != nil {
		return fmt.Errorf("cannot send data: %w", err)
	}

	id, retries, flags, counter := ind, 60, 6, 0
	for {
		ns := structByInd(id)
		if ns == nil {
			return NewConnectFailErr(-23, errors.New("no net struct"))
		}
		//counter = 0 // TODO: is this correct?
		counter++
		if counter > 20*retries {
			return NewConnectFailErr(-23, errors.New("timeout"))
		}
		ServeInitialPackets(id, flags|1)
		MaybeSendAll()
		f28 := int(ns.ind28)
		if f28 >= v11 {
			break
		}
		platform.Sleep(30 * time.Millisecond)
	}

	ns = structByInd(id)
	if Flag1 && ns.ID() >= 0 {
		vs := unsafe.Slice((*byte)(memmap.PtrOff(0x5D4594, 2512892)), 1024)
		copy(vs, make([]byte, 1024))
		data, err := opts.MarshalBinary()
		if err != nil {
			return err
		}
		vs = vs[:3+len(data)]

		vs[0] = byte(noxnet.MSG_ACCEPTED)
		vs[1] = ns.Data2()[1]
		vs[2] = 32
		if len(data) > 0 {
			copy(vs[3:], data[:153])
		}
		_, _ = Send(id, vs, SendNoLock|SendFlagFlush)
	}

	if ns.ID() < 0 {
		return NewConnectFailErr(-1, errors.New("invalid net struct id"))
	}
	return nil
}

func DialWait(ind int, timeout time.Duration, send func(), check func() bool) error {
	deadline := platform.Ticks() + timeout
	if Debug {
		Log.Println("CONNECT_WAIT_LOOP_START", deadline)
	}
	for {
		now := platform.Ticks()
		if now >= deadline {
			return NewConnectFailErr(-19, errors.New("timeout 2"))
		}
		ServeInitialPackets(ind, 1)
		send()
		MaybeSendAll()
		if check() {
			break
		}
		platform.Sleep(5 * time.Millisecond)
	}
	return nil
}

type netStruct struct {
	sock *Socket
	ip   net.IP
	port int
	id   int

	data1    []byte
	data1xxx int
	data1yyy int

	data2    []byte
	data2xxx int
	data2yyy int

	max         uint32
	playerInd21 uint32
	field22     uint32
	field23     uint32
	field24     uint32
	cnt28       uint8
	ind28       int8
	queue       *queueItem
	data3       unsafe.Pointer
	func1       Handler
	func2       Handler
	xorKey      byte
	field38     byte
	field39     byte
	frame40     uint32
	check14     Check14
	check17     Check17
}

func (ns *netStruct) FreeXxx() {
	if ns == nil {
		return
	}
	if ns.data3 != nil {
		alloc.Free(ns.data3)
	}
	alloc.FreeSlice(ns.data1)
	alloc.FreeSlice(ns.data2)
	*ns = netStruct{}
}

func (ns *netStruct) Addr() (net.IP, int) {
	if ns == nil {
		return nil, 0
	}
	return ns.ip, ns.port
}

func (ns *netStruct) SetAddr(ip net.IP, port int) {
	ns.ip, ns.port = ip, port
}

func (ns *netStruct) ID() int {
	if ns == nil {
		return -1
	}
	return ns.id
}

func (ns *netStruct) Data2() []byte {
	if ns == nil {
		return nil
	}
	return ns.data2
}

func (ns *netStruct) Datax2() []byte {
	if ns == nil {
		return nil
	}
	return ns.data2[:ns.data2xxx]
}

func (ns *netStruct) Data1xxx() []byte {
	if ns == nil {
		return nil
	}
	return ns.data1[ns.data1xxx:]
}

func (ns *netStruct) Data1yyy() []byte {
	if ns == nil {
		return nil
	}
	return ns.data1[ns.data1yyy:ns.data1xxx]
}

func (ns *netStruct) Data2xxx() []byte {
	if ns == nil {
		return nil
	}
	return ns.data2[ns.data2xxx:]
}

func (ns *netStruct) callFunc1(id int, buf []byte, data3 unsafe.Pointer) int {
	if ns.func1 == nil {
		return 0
	}
	return ns.func1(id, buf, data3)
}

func (ns *netStruct) callFunc2(id int, buf []byte, data3 unsafe.Pointer) int {
	if ns.func2 == nil {
		return 0
	}
	return ns.func2(id, buf, data3)
}

const (
	SendNoLock    = 0x1
	SendFlagFlush = 0x2
)

func Send(id int, buf []byte, flags int) (int, error) {
	ns := structByInd(id)
	if ns == nil {
		return -3, errors.New("no net struct")
	}
	if len(buf) == 0 {
		return -2, errors.New("empty buffer")
	}
	var (
		idd    int
		ei, si int
	)
	if ns.id == -1 {
		ei = maxStructs
		si = 0
		idd = id
	} else {
		si = id
		ei = id + 1
		idd = ns.ID()
	}
	if flags&SendNoLock != 0 {
		n := len(buf)
		for i := si; i < ei; i++ {
			ns2 := structByInd(i)
			if ns2 != nil && ns2.ID() == idd {
				v12, err := addToQueue(i, buf)
				if v12 == -1 {
					return -1, err
				}
				n = v12
				if flags&SendFlagFlush != 0 {
					maybeSendQueue(i, byte(v12), true)
				}
			}
		}
		return n, nil
	}
	n := len(buf)
	for i := si; i < ei; i++ {
		ns2 := structByInd(i)
		if ns2 == nil {
			continue
		}
		if ns2.ID() != idd {
			continue
		}
		d2b := ns2.Data2()
		d2x := ns2.Data2xxx()
		if n+1 > len(d2x) {
			return -7, errors.New("buffer too short")
		}
		if flags&SendFlagFlush != 0 {
			copy(d2x[:2], d2b[:2])
			copy(d2x[2:2+n], buf)
			ip, port := ns2.Addr()
			n2, err := SendToAddr(ns2.sock, d2x[:n+2], ip, port)
			if n2 == -1 {
				return -1, err
			}
			addStats(n+2, i)
			return n2, nil
		}
		copy(d2x[:n], buf)
		ns2.data2xxx += n
	}
	return n, nil
}

func netCrypt(key byte, p []byte) {
	if len(p) == 0 || !Xor {
		return
	}
	for i := range p {
		p[i] ^= key
	}
}

func netCryptDst(key byte, src, dst []byte) {
	if len(src) == 0 || len(dst) == 0 {
		return
	}
	if !Xor {
		copy(dst, src)
		return
	}
	for i := range src {
		dst[i] = key ^ src[i]
	}
}

var sendXorBuf [4096]byte

func SendToAddr(s *Socket, buf []byte, ip net.IP, port int) (int, error) {
	ns := structByAddr(ip, port)
	if ns == nil {
		return s.SendTo(buf, ip, port)
	}
	if ns.xorKey == 0 {
		return s.SendTo(buf, ip, port)
	}
	dst := sendXorBuf[:len(buf)]
	netCryptDst(ns.xorKey, buf, dst)
	return s.SendTo(dst, ip, port)
}

func addStats(n int, ind int) {
	stats[ind] += uint32(n)
}

func addToQueue(a1 int, buf []byte) (int, error) {
	if len(buf) > 1024-2 {
		return -1, errors.New("buffer too large")
	}
	if len(buf) == 0 {
		return -1, errors.New("empty buffer")
	}
	ns := structByInd(a1)
	if ns == nil {
		return -3, errors.New("no net struct")
	}
	q := allocQueue.NewObject()
	if q == nil {
		return -1, errors.New("cannot alloc gqueue")
	}
	q.next = ns.queue
	ns.queue = q

	q.active = true
	q.size = uint32(len(buf) + 2)
	q.data[0] = ns.Data2()[0] | 0x80
	q.data[1] = ns.cnt28
	ns.cnt28++
	copy(q.data[2:], buf)
	return int(q.data[1]), nil
}

func maybeSendQueue(ind int, hdrByte byte, checkHdr bool) int {
	ns := structByInd(ind)
	if ns == nil {
		return -3
	}
	for it := ns.queue; it != nil; it = it.next {
		if checkHdr {
			if it.data[1] == hdrByte {
				sz := int(it.size)
				it.active = false
				it.ticks = ticks2 + 2000
				ip, port := ns.Addr()
				if _, err := SendToAddr(ns.sock, it.data[:sz], ip, port); err != nil {
					Log.Println(err)
					return 0
				}
			}
		} else {
			if it.active {
				sz := int(it.size)
				it.active = false
				it.ticks = ticks2 + 2000
				ip, port := ns.Addr()
				if _, err := SendToAddr(ns.sock, it.data[:sz], ip, port); err != nil {
					Log.Println(err)
					return 0
				}
			}
		}
	}
	return 0
}

func setActiveInQueue(ind int, hdrByte byte, checkHdr bool) int {
	ns := structByInd(ind)
	if ns == nil {
		return -3
	}
	for it := ns.queue; it != nil; it = it.next {
		if checkHdr {
			if it.data[1] == hdrByte {
				it.active = true
				continue
			}
		} else {
			if it.ticks <= ticks2 {
				it.active = true
				continue
			}
		}
	}
	return 0
}

func GetInitInd() int {
	return initIndex
}

func InitNew(narg *Options) (ind int, _ error) {
	if narg == nil {
		return -2, errors.New("empty options")
	}
	if narg.Max > maxStructs {
		return -2, errors.New("max limit reached")
	}
	v2 := getFreeNetStruct()
	if v2 < 0 {
		return -8, errors.New("no more slots for net structs")
	}
	ns := newStruct(narg)
	structs[v2] = ns
	ns.Data2()[0] = byte(v2)
	ns.id = -1

	if narg.Port < 1024 || narg.Port > 0x10000 {
		narg.Port = common.GamePort
	}

	for {
		sock, err := udpListen(nil, narg.Port)
		if err == nil {
			ns.sock = sock
			break
		} else if !ErrIsInUse(err) {
			return 0, err
		}
		narg.Port++
	}
	initIndex = v2
	return v2, nil
}

func SendReadPacket(ind int, flags byte) int {
	ns := structByInd(ind)
	if ns == nil {
		return -3
	}
	find := ind
	min := 0
	max := maxStructs
	if ns.id != -1 {
		min = ind
		max = ind + 1
		find = ns.id
	}
	for j := min; j < max; j++ {
		ns2 := structs[j]
		if ns2 == nil || ns2.id != find {
			continue
		}
		maybeSendQueue(j, 0, false)
		if flags&1 == 0 {
			data2 := ns2.Data2xxx()
			n := ns2.callFunc1(j, data2, ns2.data3)
			if n > 0 && n <= len(data2) {
				ns2.data2xxx += n
			}
		}
		datax2 := ns2.Datax2()
		if len(datax2) > 2 {
			ip, port := ns2.Addr()
			_, err := SendToAddr(ns.sock, datax2, ip, port)
			if err != nil {
				return -1
			}
			addStats(len(datax2), j)
			ns2.data2xxx = ns2.data2yyy
		}
	}
	return 0
}

func sub555360(a1 int, a2 byte, a3 int) int {
	ns := structByInd(a1)
	if ns == nil {
		return -3
	}
	var (
		next *queueItem
		prev *queueItem
	)
	for it := ns.queue; it.next != nil; it = next {
		next = it.next
		if a3 == 0 {
			if it.data[1] != a2 {
				prev = it
				continue
			}
		} else if a3 == 1 {
			if a2 < 0x20 || a2 > 0xE0 {
				if it.data[1] >= a2 {
					prev = it
					continue
				}
			} else {
				if it.data[1] >= a2 {
					prev = it
					continue
				}
			}
		} else if a3 != 2 {
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
		allocQueue.FreeObjectFirst(it)
	}
	return 0
}

func ReadPackets(ind int) int {
	if ind < 0 || ind >= maxStructs {
		return -3
	}
	ns := structByInd(ind)
	if ns == nil {
		return 0
	}
	v4 := ns.ID()
	v1 := ind
	var si, ei int
	if v4 == -1 {
		si, ei = 0, maxStructs
		v4 = v1
	} else {
		si, ei = ind, ind+1
		ns2 := structByInd(v4)
		if ns2 == nil || ns2.id != -1 {
			ns.FreeXxx()
			structs[v1] = nil
			return 0
		}
	}
	for i := si; i < ei; i++ {
		ns2 := structByInd(i)
		if ns2 == nil || ns2.ID() != v4 {
			continue
		}
		SendReadPacket(i, 1)
		var buf [1]byte
		buf[0] = 11
		_, _ = Send(i, buf[:], 0)
		SendReadPacket(i, 1)
		structByInd(v4).playerInd21--
		sub555360(v1, 0, 2)
		ns2.FreeXxx()
		structs[i] = nil
	}
	return 0
}

func platformTicks() uint64 {
	if env.IsE2E() {
		return uint64(platform.Ticks())
	}
	return uint64(platform.Ticks() / time.Millisecond)
}

func sub5524C0() {
	ticks2 = uint32(platformTicks())
	for i := range structs {
		ns := structs[i]
		if ns != nil && ns.field38 == 1 {
			if ns.frame40+300 < GameFrame() {
				ReadPackets(i)
			}
		}
	}
}

func MaybeSendAll() {
	ticks := platformTicks()
	ticks2 = uint32(ticks)
	if uint32(ticks)-ticks1 <= 1000 {
		return
	}
	for i := range structs {
		if structs[i] != nil {
			setActiveInQueue(i, 0, false)
			maybeSendQueue(i, 0, false)
		}
	}
	ticks1 = uint32(ticks)
}

func GetTimingByInd1(ind int) int {
	return int(timing[1+ind].field28)
}

func GetIPByInd(ind int) net.IP {
	ns := structByInd(ind)
	if ns == nil {
		return nil
	}
	return ns.ip
}

func SendClose(ind int) {
	if structByInd(ind) == nil {
		return
	}
	SendReadPacket(ind, 0)
	var buf [1]byte
	buf[0] = 10
	_, _ = Send(ind, buf[:1], 0)
	SendReadPacket(ind, 0)
	CloseByInd(ind)
}

func processStreamOp0(id int, out []byte, pid int, p1 byte, ns1 *netStruct, from net.Addr) int {
	if noxflags.HasGame(noxflags.GameHost) && noxflags.HasGame(noxflags.GameFlag4) {
		return 0
	}
	out[0] = 0
	out[1] = p1
	if int(ns1.playerInd21) >= GetMaxPlayers()+(cntX-1) {
		out[2] = 2
		return 3
	}
	if pid != -1 {
		Log.Printf("pid must be set to -1 when joining: was %d (%s)\n", pid, from.String())
		// pid in the request must be -1 (0xff); fail if it's not
		out[2] = 2
		return 3
	}
	ip, port := GetAddr(from)
	// now, find free net struct index and use it as pid
	for i := range structs {
		ns9 := structs[i]
		if ns9 == nil {
			pid = i
			break
		}
		ip2, port2 := ns9.Addr()
		if port == port2 && ip.Equal(ip2) {
			out[2] = 4 // already joined?
			return 3
		}
	}
	if pid == -1 {
		out[2] = 2
		return 3
	}
	data1 := ns1.Data2()
	ns10 := newStruct(&Options{
		Data3Size: 4,
		DataSize:  len(data1),
		Check14:   ns1.check14,
		Check17:   ns1.check17,
	})
	structs[pid] = ns10
	ns1.playerInd21++

	data1 = ns10.Data2()
	data1[0] = byte(id)
	if data1[1] == p1 {
		data1[1]++
	}
	ns10.id = id
	ns10.sock = ns1.sock
	ns10.func1 = ns1.func1
	ns10.func2 = ns1.func2

	timing[id] = timingStruct{field28: 1}
	key := byte(KeyRand(1, 255))
	if !Xor {
		key = 0
	}
	ns10.xorKey = 0 // send this packet without xor encoding

	ns10.SetAddr(ip, port)

	out[0] = 31
	out[1] = p1
	out[2] = 1
	binary.LittleEndian.PutUint32(out[3:], uint32(pid))
	out[7] = key
	v67, _ := Send(pid, out[:8], SendNoLock|SendFlagFlush)

	ns10.xorKey = key
	ns10.field38 = 1
	ns10.field39 = byte(v67)
	ns10.frame40 = GameFrame()
	return 0
}

func processStreamOp6(pid int, out []byte, ns1 *netStruct, packetCur []byte) int {
	if len(packetCur) < 4 {
		return 0
	}
	v := binary.LittleEndian.Uint32(packetCur[:4])

	ns2 := structByInd(pid)
	if ns2 == nil {
		return 0
	}
	out[0] = 37
	ns1.callFunc2(pid, out[:1], ns2.data3)

	timing[pid].field4 = v
	var v18 []byte
	if ns1.id == -1 {
		out[0] = byte(ns2.id)
		v18 = ns2.Data2()
	} else {
		out[0] = byte(ns1.id)
		v18 = ns1.Data2()
	}
	out[1] = v18[0]
	out[2] = 8
	binary.LittleEndian.PutUint32(out[3:], v)
	return 7
}

func processStreamOp7(pid int, out []byte, ns1 *netStruct) int {
	ns4 := structByInd(pid)
	if ns4 == nil {
		return 0
	}
	v31 := int(ticks2) - int(ns4.field24)
	v32 := -1
	if v31 >= 1 {
		v32 = 256000 / v31
	}
	out[0] = 35
	binary.LittleEndian.PutUint32(out[1:], uint32(v32))
	if ns1.id == -1 {
		ns1.callFunc2(pid, out[:5], ns4.data3)
	} else {
		ns1.callFunc2(pid, out[:5], ns1.data3)
	}
	return 0
}

func processStreamOp8(pid int, out []byte, ns1 *netStruct, packetCur []byte) int {
	ns5 := structByInd(pid)
	if ns5 == nil && binary.LittleEndian.Uint32(packetCur) != ns5.field22 {
		return 0
	}
	ns5.field24 = uint32(int(ticks2) - int(ns5.field23))
	out[0] = 36
	binary.LittleEndian.PutUint32(out[1:], ns5.field24)
	var v19 unsafe.Pointer
	if ns1.id == -1 {
		v19 = ns5.data3
	} else {
		v19 = ns1.data3
	}
	ns1.callFunc2(pid, out[:5], v19)

	out[0] = ns1.Data2()[0]
	out[1] = ns5.Data2()[1]
	out[2] = 9
	binary.LittleEndian.PutUint32(out[3:], ticks2)
	return 7
}

func processStreamOp9(pid int, packetCur []byte) int {
	if len(packetCur) < 4 {
		return 0
	}
	v := binary.LittleEndian.Uint32(packetCur[:4])
	p := &timing[pid]
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

type Check14 func(out []byte, packet []byte, a4a bool, add func(pid int) bool) int

func processStreamOp14(out []byte, packet []byte, ns1 *netStruct, p1 byte, from net.Addr, check Check14) int {
	out[0] = 0
	out[1] = p1

	a4a := false
	if int(ns1.playerInd21) >= GetMaxPlayers()-1 {
		a4a = true
	}
	if n := check(out, packet, a4a, func(pid int) bool {
		if _, ok := playerIDs[pid]; ok {
			return false
		}
		playerIDs[pid] = struct{}{}
		cntX++
		return true
	}); n != 0 {
		return n
	}

	id53 := getFreeNetStruct2Ind()
	if id53 < 0 {
		out[2] = 20 // OK
		return 3
	}
	nx := &structs2[id53]
	nx.flag = true
	nx.cur = 0
	nx.cnt = 0
	nx.addr = from

	return copy(out, makeTimePacket(id53))
}

func Sub552E70(ind int) int {
	var buf [5]byte

	ns := structByInd(ind)
	if ns == nil {
		return -3
	}
	var (
		min, max int
		find     int
	)
	if ns.id == -1 {
		min = 0
		max = maxStructs
		find = ind
	} else {
		min = ind
		max = ind + 1
		find = ns.id
	}
	buf[0] = 6
	for i := min; i < max; i++ {
		ns2 := structs[i]
		if ns2 != nil && ns2.id == find {
			ns2.field22 = ticks2
			ns2.field23 = ns2.field22
			binary.LittleEndian.PutUint32(buf[1:], ns2.field22)
			_, _ = Send(i, buf[:5], SendFlagFlush)
		}
	}
	return 0
}

func readXxx(id1, id2 int, a3 byte, buf []byte) bool {
	ns2 := structByInd(id2)
	if ns2 == nil || ns2.field38 != 1 || ns2.field39 > a3 {
		return false
	}
	ns1 := structByInd(id1)
	if int(ns1.playerInd21) > (GetMaxPlayers() - 1) {
		ReadPackets(id2)
		return true
	}
	if len(buf) >= 4 && buf[4] == 32 {
		ns2.field38 = 2
		ns2.field39 = 0xff
		ns2.frame40 = 0
		ns1.callFunc2(id2, buf[4:], ns2.data3)
	}
	return true
}

func processStreamOp(id int, packet []byte, out []byte, from net.Addr) int {
	if len(packet) < 2 {
		return 0
	}
	pid := int(int8(packet[0]))
	p1 := packet[1]
	packetCur := packet[2:]

	ns1 := structByInd(id)
	if ns1 == nil {
		return 0
	}

	pidb := pid // TODO: some of the functions assume it's different from pid, check what's wrong
	for len(packetCur) != 0 {
		op := packetCur[0]
		packetCur = packetCur[1:]
		if Debug {
			Log.Printf("processStreamOp: op=%d [%d]\n", op, len(packetCur))
		}
		switch op {
		default:
			return 0
		case 0:
			return processStreamOp0(id, out, pidb, p1, ns1, from)
		case 1:
			if len(packetCur) < 5 {
				return 0
			}
			v11 := binary.LittleEndian.Uint32(packetCur[:4])
			xor := packetCur[4]
			packetCur = packetCur[5:]

			ns1.id = int(v11)
			ns1.data2[0] = byte(v11)
			ns1.xorKey = xor
			Flag1 = true
		case 2:
			ns1.id = -18
			Flag1 = true
		case 3: // ack?
			ns1.id = -12
			Flag1 = true
		case 4:
			ns1.id = -13
			Flag1 = true
		case 5:
			if len(packetCur) < 4 {
				return 0
			}
			v := binary.LittleEndian.Uint32(packetCur[:4])
			out[0] = ns1.xorKey
			out[1] = 0
			out[2] = 7
			binary.LittleEndian.PutUint32(out[3:], v)
			return 7
		case 6:
			return processStreamOp6(pid, out, ns1, packetCur)
		case 7:
			return processStreamOp7(pid, out, ns1)
		case 8:
			return processStreamOp8(pid, out, ns1, packetCur)
		case 9:
			return processStreamOp9(pid, packetCur)
		case 10:
			return processStreamOp10(id, pid, out, ns1)
		case 11:
			ns7 := structByInd(pid)
			if ns7 == nil {
				return 0
			}
			out[0] = 33
			ns1.callFunc2(pid, out[:1], ns7.data3)
			CloseByInd(id)
			return 0
		case 14: // join game request?
			return processStreamOp14(out, packet, ns1, p1, from, ns1.check14)
		case 17:
			return processStreamOp17(out, packet, p1, from, ns1.check17)
		case 18:
			return processStreamOp18(out, packet, from)
		case 31:
			if len(packetCur) < 1 {
				return 0
			}
			v14 := packetCur[0]
			packetCur = packetCur[1:]

			ns8 := structByInd(pidb)
			if ns8 == nil {
				return 0
			}
			Log.Printf("switch 31: 0x%x 0x%x\n", v14, ns8.ind28)
			if v14 != byte(ns8.ind28) {
				setActiveInQueue(pid, v14, true)
				sub555360(pid, v14, 1)
				ns8.ind28 = int8(v14)
				out[0] = 38
				out[1] = v14
				ns1.callFunc2(pid, out[:2], ns8.data3)
			}
		}
	}
	return 0
}

func recvRoot(s *Socket, buf []byte) (int, net.Addr) {
	n, src, err := recvRaw(s, buf)
	if err == nil {
		ip, port := GetAddr(src)
		ns := structByAddr(ip, port)
		if ns != nil {
			if ns.xorKey != 0 {
				netCrypt(ns.xorKey, buf[:n])
			}
		}
	}
	if noxflags.HasGame(noxflags.GameHost) {
		return n, src
	}

	r := PacketDropRand(1, 99)
	if r >= PacketDrop {
		return n, src
	}
	return 0, src
}

func recvRaw(s *Socket, buf []byte) (int, net.Addr, error) {
	n, src, err := s.pc.ReadFrom(buf)
	if err != nil {
		return n, src, err
	}
	ip, port := GetAddr(src)
	if Debug {
		Log.Printf("recv %s:%d -> %s [%d]\n%x", ip, port, s.pc.LocalAddr(), n, buf[:n])
	}
	if n >= 2 && binary.LittleEndian.Uint16(buf[:2]) == 0xF13A { // extension packet code
		OnExtPacket(s, buf, src)
		return 0, src, nil
	}
	return n, src, nil
}

func processStreamOp10(id int, pid int, out []byte, ns1 *netStruct) int {
	if pid == -1 {
		return 0
	}
	ns6 := structByInd(pid)
	if ns6 == nil || ns6.field38 == 1 {
		return 0
	}
	out[0] = 34
	ns1.callFunc2(pid, out[:1], ns6.data3)

	timing[id] = timingStruct{}

	if _, ok := playerIDs[pid]; ok {
		delete(playerIDs, pid)
		cntX--
	}

	ReadPackets(pid)
	return 0
}

type Check17 func(out []byte, packet []byte) int

func processStreamOp17(out []byte, packet []byte, p1 byte, from net.Addr, check Check17) int {
	out[0] = 0
	out[1] = p1
	if n := check(out, packet); n != 0 {
		return n
	}
	id2 := getFreeNetStruct2Ind()
	if id2 < 0 {
		out[2] = 20
		return 3
	}
	nx := &structs2[id2]
	nx.flag = true
	nx.cur = 0
	nx.cnt = 0
	nx.addr = from

	return copy(out, makeTimePacket(id2))
}

func processStreamOp18(out []byte, packet []byte, from net.Addr) int {
	dt := int(platformTicks()) - int(binary.LittleEndian.Uint32(packet[4:]))
	ind := struct2IndByAddr(from)
	if ind < 0 {
		return 0
	}
	nx := &structs2[ind]
	if packet[3] != nx.cur {
		return 0
	}
	nx.arr[nx.cur] = dt
	nx.cur++
	if int(nx.cur) >= len(nx.arr) {
		return 0
	}
	return copy(out, makeTimePacket(ind))
}

func ServeInitialPackets(id int, flags int) int {
	if id >= maxStructs {
		return -3
	}
	ns := structByInd(id)
	if ns == nil {
		return -3
	}
	ns2 := ns

	argp := 1
	var err error
	if flags&1 != 0 {
		argp, err = ns.sock.CanRead()
		if err != nil || argp == 0 {
			return -1
		}
	}
	buf, bfree := alloc.Make([]byte{}, 256)
	defer bfree()

	v26 := 1
	for {
		n, src := recvRoot(ns.sock, ns.Data1xxx())
		if n == -1 {
			return -1
		}
		ip, port := GetAddr(src)
		if n < 3 {
			ns.data1xxx = 0
			ns.data1yyy = 0
			if flags&1 == 0 || flags&4 != 0 {
				return n
			}
			argp, err = ns.sock.CanRead()
			if err != nil {
				return -1
			} else if argp == 0 {
				return n
			}
			continue
		}
		ns.data1xxx += n
		hdr := ns.Data1yyy()[:3]
		id2 := int(hdr[0])
		v9 := hdr[1]
		op := noxnet.Op(hdr[2])
		if Debug {
			Log.Printf("servNetInitialPackets: op=%d (%s)\n", int(op), op.String())
		}
		if op == noxnet.MSG_SERVER_DISCOVER {
			n = OnDiscover(ns.Data1yyy(), buf)
			if n > 0 {
				n, _ = ns.sock.WriteTo(buf[:n], &net.UDPAddr{IP: ip, Port: port})
			}
			ns.data1xxx = 0
			ns.data1yyy = 0
			if flags&1 == 0 || flags&4 != 0 {
				return n
			}
			argp, err = ns.sock.CanRead()
			if err != nil {
				return -1
			} else if argp == 0 {
				return n
			}
			continue
		}
		if op >= noxnet.MSG_SERVER_JOIN && op <= noxnet.MSG_SERVER_JOIN_OK {
			v26 = 1
		} else {
			if id2 == 255 {
				if v26 != 1 {
					goto continueX
				}
			} else {
				v26 = 0
				if !hasStructWithIndAndAddr(id2&127, ip, port) {
					goto continueX
				}
				v26 = 1
			}
			if ns.id == -1 {
				ns2 = structByInd(id2 & 127)
			}
			if id2&maxStructs == 0 {
				if ns2 == nil {
					goto continueX
				}
				if v9 != byte(ns2.ind28) {
					setActiveInQueue(id2, v9, true)
					sub555360(id2, v9, 1)
					ns2.ind28 = int8(v9)
					v20 := 0
					if readXxx(id, id2, v9, ns.Data1yyy()) {
						v20 = 0
					} else {
						v20 = 1
					}
					buf[0] = 38
					buf[1] = byte(ns2.ind28)
					ns.callFunc1(id2, buf[:2], ns2.data3)
					if v20 == 0 {
						goto continueX
					}
				}
			} else if id2 == 255 {
				if op == 0 {
					data := ns.Data1yyy()
					n = processStreamOp(id, data, buf, src)
					if n > 0 {
						n, _ = SendToAddr(ns.sock, buf[:n], ip, port)
					}
					goto continueX
				}
			} else {
				data := ns.Data1yyy()
				data[0] &= 127
				id2 = int(data[0])
				if ns2 == nil {
					goto continueX
				}
				data2 := ns2.Data2()
				if data2[1] != v9 {
					goto continueX
				}
				data2[1]++
				if readXxx(id, id2, v9, ns.Data1yyy()) {
					goto continueX
				}
			}
		}
		if op < 32 {
			data := ns.Data1yyy()
			n = processStreamOp(id, data, buf, src)
			if n > 0 {
				n, _ = SendToAddr(ns.sock, buf[:n], ip, port)
			}
		} else {
			if ns2 != nil && flags&2 == 0 {
				data := ns.Data1yyy()[2:n]
				ns.callFunc2(id2, data, ns2.data3)
			}
		}
	continueX:
		ns.data1xxx = 0
		ns.data1yyy = 0
		if flags&1 == 0 || flags&4 != 0 {
			return n
		}
		argp, err = ns.sock.CanRead()
		if err != nil {
			return -1
		} else if argp == 0 {
			return n
		}
	}
	// unreachable
}

func makeTimePacket(id int) []byte {
	nx := &structs2[id]
	nx.ticks = uint32(platformTicks())

	var buf [8]byte
	buf[2] = 16
	buf[3] = nx.cur
	binary.LittleEndian.PutUint32(buf[4:], nx.ticks)
	return buf[:]
}

func sendTime(ind2 int) (int, error) {
	ns := structs[initIndex]
	buf := makeTimePacket(ind2)
	ns2 := &structs2[ind2]
	ip, port := GetAddr(ns2.addr)
	return SendToAddr(ns.sock, buf, ip, port)
}

func sendCode20(ind2 int) (int, error) {
	ns := structs[initIndex]
	var buf [3]byte
	buf[0] = 0
	buf[1] = 0
	buf[2] = 20

	nx := &structs2[ind2]
	nx.flag = false

	ip, port := GetAddr(nx.addr)
	return SendToAddr(ns.sock, buf[:], ip, port)
}

func sendCode19(code byte, ind2 int) (int, error) {
	ns := structs[initIndex]
	var buf [4]byte
	buf[0] = 0
	buf[1] = 0
	buf[2] = 19
	buf[3] = code

	nx := &structs2[ind2]
	nx.flag = false

	ip, port := GetAddr(nx.addr)
	return SendToAddr(ns.sock, buf[:], ip, port)
}

func ProcessStats(v105, v107 int) {
	start := platformTicks()
	for i := range structs {
		nx := &structs2[i]
		if !nx.flag {
			continue
		}
		v2 := nx.cur
		if int(v2) >= len(nx.arr) {
			if int(nx.cnt) > MaxPacketLoss {
				_, _ = sendCode19(1, i)
				_, _ = sendCode20(i)
				continue
			}
			cnt := 0
			sum := 0
			for i = 0; i < 10; i++ {
				if nx.arr[i] > 0 {
					cnt++
					sum += nx.arr[i]
				}
			}
			avg := sum / cnt
			if v105 != -1 && avg < v105 {
				_, _ = sendCode19(0, i)
			}
			if v107 != -1 && avg > v107 {
				_, _ = sendCode19(1, i)
			}
			_, _ = sendCode20(i)
		} else {
			if start-uint64(nx.ticks) > 2000 {
				structs2[i].arr[v2] = -1
				nx.cnt++
				if int(nx.cnt) <= MaxPacketLoss {
					nx.cur++
					_, _ = sendTime(i)
				} else {
					_, _ = sendCode19(1, i)
				}
			}
		}
	}
}

var queueIter *queueItem

func QueueFirst(ind int) []byte {
	ns := structByInd(ind)
	if ns == nil {
		return nil
	}
	it := ns.queue
	if it == nil {
		return nil
	}
	queueIter = it.next
	return it.data[2:it.size]
}

func QueueNext(ind int) []byte {
	if queueIter == nil {
		return nil
	}
	ns := structByInd(ind)
	if ns == nil {
		return nil
	}
	next := queueIter
	queueIter = next
	return next.data[2:next.size]
}

func WaitServerResponse(ind1 int, a2 int, a3 int, flags int) int {
	if Debug {
		Log.Printf("nox_xxx_cliWaitServerResponse_5525B0: %d, %d, %d, %d\n", ind1, a2, a3, flags)
	}
	if ind1 >= maxStructs {
		return -3
	}
	ns := structByInd(ind1)
	if ns == nil {
		return -3
	}

	if int(ns.ind28) >= a2 {
		return 0
	}
	for v6 := 0; v6 <= 20*a3; v6++ {
		platform.Sleep(50 * time.Millisecond)
		ServeInitialPackets(ind1, flags|1)
		MaybeSendAll()
		if int(ns.ind28) >= a2 {
			return 0
		}
		// FIXME(awesie)
		return 0
	}
	return -23
}

func SendRaw(ind int, buf []byte) int {
	if len(buf) == 0 {
		return 0
	}
	ns := structByInd(ind)
	if ns == nil {
		return 0
	}
	ip, port := ns.Addr()
	n, _ := ns.sock.WriteTo(buf, &net.UDPAddr{IP: ip, Port: port})
	return n
}
