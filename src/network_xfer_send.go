package opennox

import (
	"encoding/binary"

	"github.com/noxworld-dev/opennox-lib/noxnet"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	xferSendr xferSender
)

const (
	xferSendFree     = xferSendState(0)
	xferSendStarted  = xferSendState(1)
	xferSendAccepted = xferSendState(2)
)

type xferSendState uint16

type xferBlockSend struct {
	Ind      uint16
	Data     []byte
	LastSent uint32
	Retries  uint16
	Next     *xferBlockSend
	Prev     *xferBlockSend
}

type xferSend struct {
	Conn      netstr.Handle
	Index     byte
	State     xferSendState
	Size      int
	NextBlock uint32
	BlockCnt  int
	BlockSize uint16
	Action    byte
	Type      string
	First     *xferBlockSend
	Last      *xferBlockSend
}

func (p *xferSend) Reset() {
	*p = xferSend{
		State:     xferSendFree,
		NextBlock: 1,
	}
}

func (p *xferSend) Free() {
	for it := p.First; it != nil; it = it.Next {
		*it = xferBlockSend{}
	}
}

func (p *xferSend) callAborted() {
	netXferSendAborted(p.Conn, p.Action)
}

type xferSender struct {
	arr    []xferSend
	cnt    int
	active int
}

func (x *xferSender) Init(n int) {
	if n < 0 {
		n = netXferDef
	} else if n > netXferMax {
		n = netXferMax
	}
	x.cnt = n
	x.arr = make([]xferSend, n)
	for i := 0; i < n; i++ {
		x.arr[i].Reset()
	}
	x.active = 0
}

func (x *xferSender) find(conn netstr.Handle, ind byte) *xferSend {
	for i := 0; i < x.cnt; i++ {
		it := &x.arr[i]
		if it.Conn == conn && it.Index == ind {
			return it
		}
	}
	return nil
}

func (x *xferSender) HandleAccept(conn netstr.Handle, stream byte, tok byte) {
	if int(tok) >= x.cnt {
		return
	}
	p := &x.arr[tok]
	p.Index = stream
	p.State = xferSendAccepted
}

func (x *xferSender) HandleAck(conn netstr.Handle, ind byte, block uint16) {
	p := x.find(conn, ind)
	if p == nil {
		return
	}
	for it := p.First; it != nil; it = it.Next {
		if it.Ind == block {
			if next := it.Next; next != nil {
				next.Prev = it.Prev
			} else {
				p.Last = it.Prev
			}
			if prev := it.Prev; prev != nil {
				prev.Next = it.Next
			} else {
				p.First = it.Next
			}
			*it = xferBlockSend{}
			return
		}
	}
}

func (x *xferSender) HandleDone(conn netstr.Handle, ind byte) {
	p := x.find(conn, ind)
	if p == nil {
		return
	}
	netXferSendDone(conn, p.Action)
	x.active--
	p.Reset()
}

func (x *xferSender) HandleAbort(conn netstr.Handle, a2 byte, ind byte) {
	p := x.find(conn, ind)
	if p == nil {
		return
	}
	netXferSendAborted(p.Conn, p.Action)
	for it := p.First; it != nil; it = it.Next {
		*it = xferBlockSend{}
	}
	p.Reset()
}

func (x *xferSender) Send(pli ntype.PlayerInd, act byte, typ string, data []byte, remote bool) bool {
	if len(data) == 0 {
		return false
	}
	var nind netstr.Handle
	if !noxflags.HasGame(noxflags.GameHost) {
		nind = netstrClientConn
	} else {
		if !noxflags.HasGame(noxflags.GameClient) {
			return false
		}
		if !remote || pli == server.HostPlayerIndex {
			netXferLocal(act, data)
			return true
		}
		nind = netstr.Global.ByPlayerInd(pli)
	}
	s, pi := x.New()
	if s == nil {
		return false
	}
	x.active++
	left := data
	const blockSz = 512
	blocks := (len(data)-1)/blockSz + 1
	for i := 0; i < blocks; i++ {
		b := &xferBlockSend{
			Ind: uint16(i + 1),
		}
		n := blockSz
		if len(left) <= n {
			n = len(left)
		}
		buf := make([]byte, n)
		copy(buf, left[:n])
		b.Data = buf
		b.LastSent = 0
		b.Retries = 0
		b.Next = nil
		b.Prev = s.Last
		left = left[n:]
		if prev := s.Last; prev != nil {
			prev.Next = b
		} else {
			s.First = b
		}
		s.Last = b
	}
	s.Conn = nind
	s.Index = 0
	s.State = xferSendStarted
	s.Size = len(data)
	s.NextBlock = 1
	s.BlockCnt = blocks
	s.BlockSize = blockSz
	if typ != "" {
		s.Type = typ
	}
	s.Action = act
	netSendXferStart(nind, act, typ, len(data), byte(pi))
	return true
}

func (x *xferSender) Cancel(ind netstr.Handle) {
	for i := 0; i < x.cnt; i++ {
		it := &x.arr[i]
		// TODO: shouldn't it be State == 2?
		if it.BlockCnt == 2 && it.Conn == ind {
			x.cancel(it, 1)
		}
	}
}

func (x *xferSender) New() (*xferSend, int) {
	for i := 0; i < x.cnt; i++ {
		it2 := &x.arr[i]
		if it2.State == xferSendFree && it2.Size == 0 {
			return it2, i
		}
	}
	return nil, -1
}

func (x *xferSender) Free() {
	x.arr = nil
}

func (x *xferSender) Update(ts uint32) {
	if x.active == 0 {
		return
	}
	if x.cnt <= 0 {
		return
	}
	for i := 0; i < x.cnt; i++ {
		s := &x.arr[i]
		if s.State != xferSendAccepted {
			continue
		}
		for j, b := 0, s.First; j < 2 && b != nil; j, b = j+1, b.Next {
			if t := b.LastSent; t == 0 {
				netSendXferData(s.Conn, s.Index, b.Ind, b.Data)
				s.NextBlock++
				b.LastSent = ts
			} else if ts > t+90 {
				if b.Retries < 20 {
					netSendXferData(s.Conn, s.Index, b.Ind, b.Data)
					b.LastSent = ts
					b.Retries++
				} else if s.State == xferSendAccepted {
					x.cancel(s, 2)
					break
				}
			}
		}
	}
}

func (x *xferSender) cancel(s *xferSend, reason byte) {
	netSendXferCancel(s.Conn, s.Index, reason)
	s.callAborted()
	s.Free()
	s.Reset()
	if x.active != 0 {
		x.active--
	}
}

func netSendXferStart(conn netstr.Handle, act byte, typ string, sz int, tok byte) {
	var buf [140]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 0 // XFER_START
	buf[2] = act
	binary.LittleEndian.PutUint32(buf[4:], uint32(sz))
	n := copy(buf[8:136], typ)
	buf[8+n] = 0
	buf[136] = tok
	conn.Send(buf[:140], netstr.SendQueue|netstr.SendFlush)
}

func netSendXferData(conn netstr.Handle, a2 byte, block uint16, data []byte) int {
	buf := make([]byte, 8+len(data))
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 2 // XFER_DATA
	buf[2] = a2
	buf[3] = 0
	binary.LittleEndian.PutUint16(buf[4:], block)
	binary.LittleEndian.PutUint16(buf[6:], uint16(len(data)))
	copy(buf[8:], data)
	conn.Send(buf, 0)
	return conn.SendReadPacket(true)
}

func netSendXferCancel(conn netstr.Handle, a2 byte, reason byte) {
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 5 // XFER_CODE5
	buf[2] = a2
	buf[3] = reason
	conn.Send(buf[:4], netstr.SendQueue|netstr.SendFlush)
}
