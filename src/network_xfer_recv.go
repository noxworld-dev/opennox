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

func (p *xferRecv) AddBlock(block uint16, data []byte) {
	if uint32(block) == p.NextBlock {
		copy(p.Result[p.Received:p.Received+len(data)], data)
		p.Received += len(data)
		p.NextBlock++
	} else {
		b := &xferBlockRecv{
			Ind:  block,
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

func (x *xferReceiver) HandleData(ind netstr.Handle, ts uint32, a2 byte, block uint16, data []byte) {
	if len(data) == 0 {
		return
	}
	if int(a2) >= x.cnt {
		return
	}
	p := &x.arr[a2]
	if len(p.Result) == 0 {
		return
	}
	p.LastUpdate = ts
	p.AddBlock(block, data)
	if p.Received == len(p.Result) {
		netSendXferClose(p.Conn, p.Index)
		xferDataCallback40AF90(ind.Player(), p.Index, p.Action, p.Type, p.Result)
		if x.active != 0 {
			x.active--
		}
		p.Result = nil
		x.free(int(a2))
		x.reset(int(a2))
	}
}

func (x *xferReceiver) HandleCancel(a1 byte, a2 byte) {
	x.free(int(a2))
	x.reset(int(a2))
}

func netSendXferAccept(conn netstr.Handle, stream byte, tok byte) {
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 1 // XFER_ACCEPT
	buf[2] = stream
	buf[3] = tok
	conn.Send(buf[:4], netstr.SendQueue|netstr.SendFlush)
}

func netSendXferClose(conn netstr.Handle, a2 byte) {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 4 // XFER_CLOSE
	buf[2] = a2
	conn.Send(buf[:3], netstr.SendQueue|netstr.SendFlush)
}

func netSendXferCode6(conn netstr.Handle, a2 byte, a3 byte) {
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 6 // XFER_CODE6
	buf[2] = a2
	buf[3] = a3
	conn.Send(buf[:4], netstr.SendQueue|netstr.SendFlush)
}
