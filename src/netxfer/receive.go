package netxfer

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/internal/netstr"
)

type ReceiveFunc func(conn netstr.Handle, act Action, typ string, data []byte)

type recvStreamID byte

type recvChunk struct {
	ind  chunkInd
	data []byte
	next *recvChunk
	prev *recvChunk
}

type recvStream struct {
	conn       netstr.Handle
	action     Action
	index      recvStreamID
	nextChunk  int
	received   int
	full       []byte
	typ        string
	progress   float64
	lastUpdate Time
	first      *recvChunk
	last       *recvChunk
}

func (p *recvStream) Reset(id recvStreamID) {
	*p = recvStream{
		conn:      p.conn,
		index:     id,
		nextChunk: 1,
	}
}

func (p *recvStream) AddChunk(chunk chunkInd, data []byte) {
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
		x.arr[i].Reset(recvStreamID(i))
	}
}

func (x *receiver) reset(i recvStreamID) {
	x.arr[i].Reset(i)
}

func (x *receiver) Free() {
	for i := 0; i < x.cnt; i++ {
		x.free(recvStreamID(i))
	}
	x.arr = nil
}

func (x *receiver) free(i recvStreamID) {
	p := &x.arr[i]
	for it := p.first; it != nil; it = it.next {
		*it = recvChunk{}
	}
}

func (x *receiver) Update(ts Time) {
	for i := 0; i < x.cnt; i++ {
		it := &x.arr[i]
		if len(it.full) != 0 && ts > it.lastUpdate+900 {
			x.abort(recvStreamID(i), 3)
		}
	}
}

func (x *receiver) abort(i recvStreamID, reason byte) {
	p := &x.arr[i]
	if len(p.full) != 0 {
		sendCode6(p.conn, p.index, reason)
		if x.active != 0 {
			x.active--
		}
		x.free(i)
		x.reset(i)
	}
}

func (x *receiver) new() *recvStream {
	if x.cnt <= 0 {
		return nil
	}
	for id := 0; id < x.cnt; id++ {
		it := &x.arr[id]
		if len(it.full) == 0 {
			it.index = recvStreamID(id)
			return it
		}
	}
	return nil
}

func (x *receiver) New(conn netstr.Handle, act Action, typ string, sz uint32) *recvStream {
	p := x.new()
	p.conn = conn
	p.action = act
	p.typ = typ
	p.full = make([]byte, sz)
	return p
}

func (x *receiver) HandleStart(conn netstr.Handle, ts Time, m *noxnet.MsgXferStart) {
	if m.Size == 0 {
		return
	}
	p := x.New(conn, Action(m.Act), m.Type.Value, m.Size)
	if p == nil {
		return
	}
	p.lastUpdate = ts
	x.active++
	sendAccept(conn, p.index, m.Token)
}

func (x *receiver) HandleData(conn netstr.Handle, ts Time, m *noxnet.MsgXferData) {
	id := recvStreamID(m.Stream)
	chunk := chunkInd(m.Chunk)
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
		sendClose(p.conn, p.index)
		if x.onReceive != nil {
			x.onReceive(conn, p.action, p.typ, p.full)
		}
		if x.active != 0 {
			x.active--
		}
		p.full = nil
		x.free(id)
		x.reset(id)
	}
}

func (x *receiver) HandleCancel(m *noxnet.MsgXferState) {
	id := recvStreamID(m.Stream)
	x.free(id)
	x.reset(id)
}

func sendAck(conn netstr.Handle, stream recvStreamID, chunk chunkInd) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferAck{
		Stream: byte(stream),
		Token:  0,
		Chunk:  uint16(chunk),
	}}, netstr.SendQueue|netstr.SendFlush)
}

func sendAccept(conn netstr.Handle, stream recvStreamID, tok byte) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferState{
		Code:   noxnet.XferAccept,
		Stream: byte(stream),
		Token:  tok,
	}}, netstr.SendQueue|netstr.SendFlush)
}

func sendClose(conn netstr.Handle, stream recvStreamID) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferClose{
		Stream: byte(stream),
	}}, netstr.SendQueue|netstr.SendFlush)
}

func sendCode6(conn netstr.Handle, stream recvStreamID, reason byte) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferState{
		Code:   noxnet.XferCode6,
		Stream: byte(stream),
		Token:  reason,
	}}, netstr.SendQueue|netstr.SendFlush)
}
