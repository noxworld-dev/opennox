package netxfer

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/noxnet/xfer"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/server/netlib"
)

type ReceiveFunc func(conn ntype.PlayerInd, act Action, typ string, data []byte)

type recvChunk struct {
	ind  xfer.Chunk
	data []byte
	next *recvChunk
	prev *recvChunk
}

type recvStream struct {
	conn       netlib.SendStream
	action     Action
	recvID     xfer.RecvID
	nextChunk  int
	received   int
	full       []byte
	typ        string
	progress   float64
	lastUpdate Time
	first      *recvChunk
	last       *recvChunk
}

func (p *recvStream) Reset(id xfer.RecvID) {
	*p = recvStream{
		conn:      p.conn,
		recvID:    id,
		nextChunk: 1,
	}
}

func (p *recvStream) AddChunk(chunk xfer.Chunk, data []byte) {
	if int(chunk) == p.nextChunk {
		copy(p.full[p.received:p.received+len(data)], data)
		p.received += len(data)
		p.nextChunk++
	} else {
		b := &recvChunk{
			ind:  chunk,
			data: make([]byte, len(data)),
		}
		copy(b.data, data)
		b.next = nil
		b.prev = p.last
		if last := p.last; last != nil {
			last.next = b
		}
		p.last = b
		if first := p.first; first == nil {
			p.first = b
		}
	}

	for it := p.first; it != nil; it = it.next {
		if p.nextChunk == int(it.ind) {
			copy(p.full[p.received:p.received+len(it.data)], it.data)
			p.received += len(it.data)
			p.nextChunk++
			if prev := it.prev; prev != nil {
				prev.next = it.next
			} else {
				p.first = it.next
			}
			if next := it.next; next != nil {
				next.prev = it.prev
			} else {
				p.last = it.prev
			}
			*it = recvChunk{}
		}
	}
	p.progress = float64(p.received) / float64(len(p.full)) * 100.0
}

type receiver struct {
	arr    []recvStream
	cnt    int
	active int

	onReceive ReceiveFunc
}

func (x *receiver) Init(n int, onRecv ReceiveFunc) {
	if n < 0 {
		n = minStreams
	} else if n > maxStreams {
		n = maxStreams
	}
	x.onReceive = onRecv
	x.cnt = n
	x.active = 0
	x.arr = make([]recvStream, n)
	for i := 0; i < n; i++ {
		x.arr[i].Reset(xfer.RecvID(i))
	}
}

func (x *receiver) reset(rid xfer.RecvID) {
	x.arr[rid].Reset(rid)
}

func (x *receiver) Free() {
	for i := 0; i < x.cnt; i++ {
		x.free(xfer.RecvID(i))
	}
	x.arr = nil
}

func (x *receiver) free(rid xfer.RecvID) {
	p := &x.arr[rid]
	for it := p.first; it != nil; it = it.next {
		*it = recvChunk{}
	}
}

func (x *receiver) Update(ts Time) {
	for i := 0; i < x.cnt; i++ {
		it := &x.arr[i]
		if len(it.full) != 0 && ts > it.lastUpdate+900 {
			x.abort(xfer.RecvID(i), xfer.ErrRecvTimeout)
		}
	}
}

func (x *receiver) abort(rid xfer.RecvID, reason xfer.Error) {
	p := &x.arr[rid]
	if len(p.full) != 0 {
		sendAbort(p.conn, p.recvID, reason)
		if x.active != 0 {
			x.active--
		}
		x.free(rid)
		x.reset(rid)
	}
}

func (x *receiver) new() *recvStream {
	if x.cnt <= 0 {
		return nil
	}
	for id := 0; id < x.cnt; id++ {
		it := &x.arr[id]
		if len(it.full) == 0 {
			it.recvID = xfer.RecvID(id)
			return it
		}
	}
	return nil
}

func (x *receiver) New(conn netlib.SendStream, act Action, typ string, sz uint32) *recvStream {
	p := x.new()
	p.conn = conn
	p.action = act
	p.typ = typ
	p.full = make([]byte, sz)
	return p
}

func (x *receiver) HandleStart(conn netlib.SendStream, ts Time, m *xfer.MsgStart) {
	if m.Size == 0 {
		return
	}
	p := x.New(conn, m.Act, m.Type.Value, m.Size)
	if p == nil {
		return
	}
	p.lastUpdate = ts
	x.active++
	sendAccept(conn, p.recvID, m.SendID)
}

func (x *receiver) HandleData(pid ntype.PlayerInd, conn netlib.SendStream, ts Time, m *xfer.MsgData) {
	id := m.RecvID
	chunk := m.Chunk
	sendAck(conn, id, chunk)
	if len(m.Data) == 0 {
		return
	}
	if int(id) >= x.cnt {
		return
	}
	p := &x.arr[id]
	if len(p.full) == 0 {
		return
	}
	p.lastUpdate = ts
	p.AddChunk(chunk, m.Data)
	if p.received == len(p.full) {
		sendDone(p.conn, p.recvID)
		if x.onReceive != nil {
			x.onReceive(pid, p.action, p.typ, p.full)
		}
		if x.active != 0 {
			x.active--
		}
		p.full = nil
		x.free(id)
		x.reset(id)
	}
}

func (x *receiver) HandleCancel(m *xfer.MsgCancel) {
	id := m.RecvID
	x.free(id)
	x.reset(id)
}

func sendAck(conn netlib.SendStream, rid xfer.RecvID, chunk xfer.Chunk) {
	conn.QueueMsg(&noxnet.MsgXfer{&xfer.MsgAck{
		RecvID: rid,
		Token:  0,
		Chunk:  chunk,
	}}, true)
}

func sendAccept(conn netlib.SendStream, rid xfer.RecvID, sid xfer.SendID) {
	conn.QueueMsg(&noxnet.MsgXfer{&xfer.MsgAccept{
		RecvID: rid,
		SendID: sid,
	}}, true)
}

func sendDone(conn netlib.SendStream, stream xfer.RecvID) {
	conn.QueueMsg(&noxnet.MsgXfer{&xfer.MsgDone{
		RecvID: stream,
	}}, true)
}

func sendAbort(conn netlib.SendStream, stream xfer.RecvID, reason xfer.Error) {
	conn.QueueMsg(&noxnet.MsgXfer{&xfer.MsgAbort{
		RecvID: stream,
		Reason: reason,
	}}, true)
}
