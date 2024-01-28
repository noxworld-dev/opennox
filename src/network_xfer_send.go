package opennox

import (
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
	Stream    byte
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

func (p *xferSend) Ack(chunk uint16) {
	if p == nil {
		return
	}
	for it := p.First; it != nil; it = it.Next {
		if it.Ind == chunk {
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

func (x *xferSender) find(conn netstr.Handle, stream byte) *xferSend {
	for i := 0; i < x.cnt; i++ {
		it := &x.arr[i]
		if it.Conn == conn && it.Stream == stream {
			return it
		}
	}
	return nil
}

func (x *xferSender) HandleAccept(conn netstr.Handle, m *noxnet.MsgXferState) {
	ind := int(m.Token)
	if ind >= x.cnt {
		return
	}
	p := &x.arr[ind]
	p.Stream = m.Stream
	p.State = xferSendAccepted
}

func (x *xferSender) HandleAck(conn netstr.Handle, m *noxnet.MsgXferAck) {
	x.find(conn, m.Stream).Ack(m.Chunk)
}

func (x *xferSender) HandleDone(conn netstr.Handle, m *noxnet.MsgXferClose) {
	p := x.find(conn, m.Stream)
	if p == nil {
		return
	}
	netXferSendDone(conn, p.Action)
	x.active--
	p.Reset()
}

func (x *xferSender) HandleAbort(conn netstr.Handle, m *noxnet.MsgXferState) {
	p := x.find(conn, m.Stream)
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
	s.Stream = 0
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
		if it.State == xferSendAccepted && it.Conn == ind {
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
				netSendXferData(s.Conn, s.Stream, b.Ind, b.Data)
				s.NextBlock++
				b.LastSent = ts
			} else if ts > t+90 {
				if b.Retries < 20 {
					netSendXferData(s.Conn, s.Stream, b.Ind, b.Data)
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
	netSendXferCancel(s.Conn, s.Stream, reason)
	s.callAborted()
	s.Free()
	s.Reset()
	if x.active != 0 {
		x.active--
	}
}

func netSendXferStart(conn netstr.Handle, act byte, typ string, sz int, tok byte) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferStart{
		Act:   act,
		Size:  uint32(sz),
		Type:  noxnet.FixedString{Value: typ},
		Token: tok,
	}}, netstr.SendQueue|netstr.SendFlush)
}

func netSendXferData(conn netstr.Handle, ind byte, chunk uint16, data []byte) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferData{
		Stream: ind,
		Token:  0,
		Chunk:  chunk,
		Data:   data,
	}}, 0)
	conn.SendReadPacket(true)
}

func netSendXferCancel(conn netstr.Handle, a2 byte, reason byte) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferState{
		Code:   noxnet.XferCode5,
		Stream: a2,
		Token:  reason,
	}}, netstr.SendQueue|netstr.SendFlush)
}
