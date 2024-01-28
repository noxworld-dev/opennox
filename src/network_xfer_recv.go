package opennox

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/internal/netstr"
)

var (
	xferRecvr xferReceiver
)

type xferBlockRecv struct {
	Ind  uint16
	Data []byte
	Next *xferBlockRecv
	Prev *xferBlockRecv
}

type xferRecv struct {
	Conn       netstr.Handle
	Action     byte
	Index      byte
	NextBlock  uint32
	Received   int
	Result     []byte
	Type       string
	Progress   float32
	LastUpdate uint32
	First      *xferBlockRecv
	Last       *xferBlockRecv
}

func (p *xferRecv) Reset(i int) {
	*p = xferRecv{
		Conn:      p.Conn,
		Index:     byte(i),
		NextBlock: 1,
	}
}

func (p *xferRecv) AddChunk(chunk uint16, data []byte) {
	if uint32(chunk) == p.NextBlock {
		copy(p.Result[p.Received:p.Received+len(data)], data)
		p.Received += len(data)
		p.NextBlock++
	} else {
		b := &xferBlockRecv{
			Ind:  chunk,
			Data: make([]byte, len(data)),
		}
		copy(b.Data, data)
		b.Next = nil
		b.Prev = p.Last
		if last := p.Last; last != nil {
			last.Next = b
		}
		p.Last = b
		if first := p.First; first == nil {
			p.First = b
		}
	}

	for it := p.First; it != nil; it = it.Next {
		if p.NextBlock == uint32(it.Ind) {
			copy(p.Result[p.Received:p.Received+len(it.Data)], it.Data)
			p.Received += len(it.Data)
			p.NextBlock++
			if prev := it.Prev; prev != nil {
				prev.Next = it.Next
			} else {
				p.First = it.Next
			}
			if next := it.Next; next != nil {
				next.Prev = it.Prev
			} else {
				p.Last = it.Prev
			}
			*it = xferBlockRecv{}
		}
	}
	p.Progress = float32(float64(p.Received) / float64(len(p.Result)) * 100.0)
}

type xferReceiver struct {
	arr    []xferRecv
	cnt    int
	active int
}

func (x *xferReceiver) Init(n int) {
	if n < 0 {
		n = netXferDef
	} else if n > netXferMax {
		n = netXferMax
	}
	x.cnt = n
	x.arr = make([]xferRecv, n)
	for i := 0; i < n; i++ {
		x.reset(i)
	}
}

func (x *xferReceiver) reset(i int) {
	x.arr[i].Reset(i)
}

func (x *xferReceiver) Free() {
	for i := 0; i < x.cnt; i++ {
		x.free(i)
	}
	x.arr = nil
}

func (x *xferReceiver) free(i int) {
	p := &x.arr[i]
	for it := p.First; it != nil; it = it.Next {
		*it = xferBlockRecv{}
	}
}

func (x *xferReceiver) Update(ts uint32) {
	for i := 0; i < x.cnt; i++ {
		it := &x.arr[i]
		if len(it.Result) != 0 && ts > it.LastUpdate+900 {
			x.sub_40B530(i, 3)
		}
	}
}

func (x *xferReceiver) sub_40B530(i int, a2 byte) {
	p := &x.arr[i]
	if len(p.Result) != 0 {
		netSendXferCode6(p.Conn, p.Index, a2)
		if x.active != 0 {
			x.active--
		}
		x.free(i)
		x.reset(i)
	}
}

func (x *xferReceiver) new() *xferRecv {
	if x.cnt <= 0 {
		return nil
	}
	for i := 0; i < x.cnt; i++ {
		it := &x.arr[i]
		if len(it.Result) == 0 {
			it.Index = byte(i)
			return it
		}
	}
	return nil
}

func (x *xferReceiver) New(conn netstr.Handle, act byte, typ string, sz uint32) *xferRecv {
	p := x.new()
	p.Conn = conn
	p.Action = act
	p.Type = typ
	p.Result = make([]byte, sz)
	return p
}

func (x *xferReceiver) HandleStart(conn netstr.Handle, ts uint32, act byte, typ string, sz uint32, tok byte) {
	if sz == 0 {
		return
	}
	p := x.New(conn, act, typ, sz)
	if p == nil {
		return
	}
	p.LastUpdate = ts
	x.active++
	netSendXferAccept(conn, p.Index, tok)
}

func (x *xferReceiver) HandleData(conn netstr.Handle, ts uint32, stream byte, chunk uint16, data []byte) {
	netSendXferAck(conn, stream, chunk)
	if len(data) == 0 {
		return
	}
	if int(stream) >= x.cnt {
		return
	}
	p := &x.arr[stream]
	if len(p.Result) == 0 {
		return
	}
	p.LastUpdate = ts
	p.AddChunk(chunk, data)
	if p.Received == len(p.Result) {
		netSendXferClose(p.Conn, p.Index)
		xferDataCallback40AF90(conn.Player(), p.Index, p.Action, p.Type, p.Result)
		if x.active != 0 {
			x.active--
		}
		p.Result = nil
		x.free(int(stream))
		x.reset(int(stream))
	}
}

func (x *xferReceiver) HandleCancel(reason byte, a2 byte) {
	x.free(int(a2))
	x.reset(int(a2))
}

func netSendXferAck(conn netstr.Handle, stream byte, chunk uint16) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferAck{
		Stream: stream,
		Token:  0,
		Chunk:  chunk,
	}}, netstr.SendQueue|netstr.SendFlush)
}

func netSendXferAccept(conn netstr.Handle, stream byte, tok byte) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferState{
		Code:   noxnet.XferAccept,
		Stream: stream,
		Token:  tok,
	}}, netstr.SendQueue|netstr.SendFlush)
}

func netSendXferClose(conn netstr.Handle, stream byte) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferClose{
		Stream: stream,
	}}, netstr.SendQueue|netstr.SendFlush)
}

func netSendXferCode6(conn netstr.Handle, stream byte, reason byte) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferState{
		Code:   noxnet.XferCode6,
		Stream: stream,
		Token:  reason,
	}}, netstr.SendQueue|netstr.SendFlush)
}
