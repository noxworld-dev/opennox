package netstr

import (
	"bytes"
	"encoding/binary"
	"fmt"
	"net"
	"net/netip"
	"time"

	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/server/netlib"
)

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
	seqRecv   int8
	sendPoll  Handler
	onReceive Handler
	xorKey    byte
	field38   byte
	seq39     byte
	frame40   uint32
	onJoin    JoinCheck
	check17   Check17

	reliable *reliableSender
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

func (ns *Conn) setAddr(addr netip.AddrPort) {
	ns.addr = addr
}

func (ns *Conn) IP() netip.Addr {
	if ns == nil {
		return netip.Addr{}
	}
	return ns.addr.Addr()
}

func (ns *Conn) handle() handle {
	if ns == nil {
		return errHandle(-1)
	}
	return handle{ns.g, ns.id}
}

func (ns *Conn) data2hdr() *[2]byte {
	if ns == nil {
		var v [2]byte
		return &v
	}
	return (*[2]byte)(ns.sendBuf[:2])
}

func (ns *Conn) callOnReceive(ns2 *Conn, buf []byte) int {
	if ns.onReceive == nil {
		return 0
	}
	return ns.onReceive(ns2, buf)
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

func (ns *Conn) reset() {
	if ns == nil {
		return
	}
	ns.recv.Reset()
	*ns = Conn{g: ns.g, ind: ns.ind, sendBuf: ns.sendBuf}
	ns.resetReliable()
}

func (ns *Conn) resetReliable() {
	ns.reliable = newReliableSender(ns.write)
	ns.reliable.Now = func() time.Duration {
		return ns.g.now
	}
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

func (ns *Conn) SendCode11() {
	if ns == nil {
		return
	}
	ns.Flush()
	var buf [1]byte
	buf[0] = byte(code11)
	_, _ = ns.SendUnreliable(buf[:], false)
	ns.Flush()
	ns.accepted--
	ns.reliable.Clear()
	ns.reset()
	ns.g.streams[ns.ind] = nil
}

func (ns *Conn) SendClose() {
	if ns == nil {
		return
	}
	ns.FlushAndPoll()
	var buf [1]byte
	buf[0] = byte(code10)
	_, _ = ns.SendUnreliable(buf[:1], false)
	ns.FlushAndPoll()
	ns.Close()
}

func (ns *Conn) processStreamOp0(out []byte, pid handle, p1 byte, from netip.AddrPort) int {
	if ns.g.IsHost() && ns.g.IsFlag4() {
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

	hdr := ns2.data2hdr()
	hdr[0] = byte(ns.ind)
	if hdr[1] == p1 {
		hdr[1]++
	}
	ns2.pc = ns.pc
	ns2.sendPoll = ns.sendPoll
	ns2.onReceive = ns.onReceive

	ns.g.timing[ind] = timingStruct{field28: 1}
	key := byte(ns.g.KeyRand(1, 255))
	if !ns.g.Xor {
		key = 0
	}
	ns2.xorKey = 0 // send this packet without xor encoding

	ns2.setAddr(from)

	out[0] = byte(code31) // TODO: it's not a code here, but an ID?
	out[1] = p1
	out[2] = byte(codeNewStream1)
	binary.LittleEndian.PutUint32(out[3:], uint32(ind))
	out[7] = key
	seq, _ := ns2.SendReliable(out[:8])

	ns2.xorKey = key
	ns2.field38 = 1
	ns2.seq39 = byte(seq)
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
		hdr = ns2.data2hdr()
	} else {
		out[0] = byte(ns.id)
		hdr = ns.data2hdr()
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
	ms := int((ns.g.now - ns2.ticks24) / time.Millisecond)
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
	dt := ns.g.now - ns2.ticks23
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

	out[0] = ns.data2hdr()[0]
	out[1] = ns2.data2hdr()[1]
	out[2] = byte(code9)
	ms = int(ns.g.now / time.Millisecond)
	binary.LittleEndian.PutUint32(out[3:], uint32(ms))
	return 7
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
		if _, ok := ns.g.playerIDs[ns2.ind]; ok {
			return false
		}
		ns.g.playerIDs[ns2.ind] = struct{}{}
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
	ns.ticks22 = ns.g.now
	ns.ticks23 = ns.ticks22
	binary.LittleEndian.PutUint32(buf[1:], uint32(ns.ticks22/time.Millisecond))
	_, _ = ns.SendUnreliable(buf[:5], true)
	return 0
}

func (ns *Conn) readXxx(ns2 *Conn, a3 byte, buf []byte) bool {
	if ns2 == nil || ns2.field38 != 1 || ns2.seq39 > a3 {
		return false
	}
	if ns.accepted > (ns.g.GetMaxPlayers() - 1) {
		ns2.SendCode11()
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
			ns.data2hdr()[0] = byte(ind)
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
			return ns.processStreamOp10(pid.Get(), out)
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
				ns9.reliable.SetCurrent(seq)
				ns8.seqRecv = int8(seq)
				out[0] = byte(code38)
				out[1] = seq
				ns.callOnReceive(ns9, out[:2])
			}
		}
	}
	return 0
}

func (ns *Conn) processStreamOp10(ns2 *Conn, out []byte) int {
	if ns2 == nil || ns2.field38 == 1 {
		return 0
	}
	out[0] = byte(code34)
	ns.callOnReceive(ns2, out[:1])

	ns.g.timing[ns.ind] = timingStruct{}

	if _, ok := ns.g.playerIDs[ns2.ind]; ok {
		delete(ns.g.playerIDs, ns2.ind)
		ns.g.cntX--
	}

	ns2.SendCode11()
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

const (
	RecvCanRead = netlib.RecvCanRead
	RecvNoHooks = netlib.RecvNoHooks
	RecvJustOne = netlib.RecvJustOne
)

type RecvFlags = netlib.RecvFlags

func (ns *Conn) RecvLoop(noHooks bool) int {
	flags := RecvCanRead
	if noHooks {
		flags |= RecvNoHooks
	}
	return ns.recvLoop(flags)
}
func (ns *Conn) recvLoop(flags RecvFlags) int {
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
				n, _ = ns.writeToRaw(tmp[:n], src)
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
			if a0&reliableFlag == 0 {
				if dst == nil {
					goto continueX
				}
				if seq != byte(dst.seqRecv) {
					ns9 := h2.Get()
					ns9.reliable.SetCurrent(seq)
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
						n, _ = ns.writeTo(tmp[:n], src)
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
				hdr2 := dst.data2hdr()
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
				n, _ = ns.writeTo(tmp[:n], src)
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

func (ns *Conn) SendSelfRaw(buf []byte) int {
	if ns == nil {
		return 0
	}
	n, _ := ns.writeToRaw(buf, ns.addr)
	return n
}

func (ns *Conn) writeToRaw(buf []byte, addr netip.AddrPort) (int, error) {
	if ns == nil || len(buf) == 0 {
		return 0, nil
	}
	return writeTo(ns.g.Debug, ns.g.Log, ns.pc, buf, addr)
}

func (ns *Conn) write(buf []byte) (int, error) {
	return ns.writeTo(buf, ns.addr)
}

func (ns *Conn) writeTo(buf []byte, addr netip.AddrPort) (int, error) {
	if ns == nil || len(buf) == 0 {
		return 0, nil
	}
	ns2 := ns.g.connByAddr(addr)
	if ns2 == nil || ns2.xorKey == 0 {
		return ns.writeToRaw(buf, addr)
	}
	dst := ns.g.sendXorBuf[:len(buf)]
	if ns.g.Xor {
		netCryptDst(ns2.xorKey, buf, dst)
	} else {
		copy(dst, buf)
	}
	return ns.writeToRaw(dst, ns2.addr)
}

func netCryptDst(key byte, src, dst []byte) {
	if len(src) == 0 || len(dst) == 0 {
		return
	}
	for i := range src {
		dst[i] = key ^ src[i]
	}
}
