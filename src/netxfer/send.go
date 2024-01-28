package netxfer

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/internal/netstr"
)

const (
	sendFree     = sendState(0)
	sendStarted  = sendState(1)
	sendAccepted = sendState(2)
)

type DoneFunc func(conn netstr.Handle, act Action)
type AbortFunc func(conn netstr.Handle, act Action)

type sendState byte

type sendStreamID byte

type sendChunk struct {
	ind      chunkInd
	data     []byte
	lastSent Time
	retries  uint16
	next     *sendChunk
	prev     *sendChunk
}

type sendStream struct {
	conn      netstr.Handle
	stream    recvStreamID
	state     sendState
	size      int
	nextChunk int
	chunkCnt  int
	chunkSize uint16
	action    Action
	typ       string
	first     *sendChunk
	last      *sendChunk
	onDone    DoneFunc
	onAbort   AbortFunc
}

func (p *sendStream) Reset() {
	*p = sendStream{
		state:     sendFree,
		nextChunk: 1,
	}
}

func (p *sendStream) Free() {
	for it := p.first; it != nil; it = it.next {
		*it = sendChunk{}
	}
}

func (p *sendStream) Ack(chunk chunkInd) {
	if p == nil {
		return
	}
	for it := p.first; it != nil; it = it.next {
		if it.ind == chunk {
			if next := it.next; next != nil {
				next.prev = it.prev
			} else {
				p.last = it.prev
			}
			if prev := it.prev; prev != nil {
				prev.next = it.next
			} else {
				p.first = it.next
			}
			*it = sendChunk{}
			return
		}
	}
}

func (p *sendStream) callAborted() {
	if p.onAbort != nil {
		p.onAbort(p.conn, p.action)
	}
}

func (p *sendStream) callDone() {
	if p.onDone != nil {
		p.onDone(p.conn, p.action)
	}
}

type sender struct {
	arr    []sendStream
	cnt    int
	active int
}

func (x *sender) Init(n int) {
	if n < 0 {
		n = minStreams
	} else if n > maxStreams {
		n = maxStreams
	}
	x.cnt = n
	x.arr = make([]sendStream, n)
	for i := 0; i < n; i++ {
		x.arr[i].Reset()
	}
	x.active = 0
}

func (x *sender) find(conn netstr.Handle, stream recvStreamID) *sendStream {
	for i := 0; i < x.cnt; i++ {
		it := &x.arr[i]
		if it.conn == conn && it.stream == stream {
			return it
		}
	}
	return nil
}

func (x *sender) HandleAccept(conn netstr.Handle, m *noxnet.MsgXferState) {
	id := sendStreamID(m.Token)
	if int(id) >= x.cnt {
		return
	}
	p := &x.arr[id]
	p.stream = recvStreamID(m.Stream)
	p.state = sendAccepted
}

func (x *sender) HandleAck(conn netstr.Handle, m *noxnet.MsgXferAck) {
	x.find(conn, recvStreamID(m.Stream)).Ack(chunkInd(m.Chunk))
}

func (x *sender) HandleDone(conn netstr.Handle, m *noxnet.MsgXferClose) {
	p := x.find(conn, recvStreamID(m.Stream))
	if p == nil {
		return
	}
	p.callDone()
	x.active--
	p.Reset()
}

func (x *sender) HandleAbort(conn netstr.Handle, m *noxnet.MsgXferState) {
	p := x.find(conn, recvStreamID(m.Stream))
	if p == nil {
		return
	}
	p.callAborted()
	for it := p.first; it != nil; it = it.next {
		*it = sendChunk{}
	}
	p.Reset()
}

func (x *sender) Send(conn netstr.Handle, act Action, typ string, data []byte, onDone DoneFunc, onAbort AbortFunc) bool {
	if len(data) == 0 {
		return false
	}
	s, id := x.New()
	if s == nil {
		return false
	}
	x.active++
	left := data
	const blockSz = 512
	blocks := (len(data)-1)/blockSz + 1
	for i := 0; i < blocks; i++ {
		b := &sendChunk{
			ind: chunkInd(i + 1),
		}
		n := blockSz
		if len(left) <= n {
			n = len(left)
		}
		buf := make([]byte, n)
		copy(buf, left[:n])
		b.data = buf
		b.lastSent = 0
		b.retries = 0
		b.next = nil
		b.prev = s.last
		left = left[n:]
		if prev := s.last; prev != nil {
			prev.next = b
		} else {
			s.first = b
		}
		s.last = b
	}
	s.conn = conn
	s.stream = 0
	s.state = sendStarted
	s.size = len(data)
	s.nextChunk = 1
	s.chunkCnt = blocks
	s.chunkSize = blockSz
	if typ != "" {
		s.typ = typ
	}
	s.action = act
	s.onDone = onDone
	s.onAbort = onAbort
	sendStart(conn, act, typ, len(data), id)
	return true
}

func (x *sender) Cancel(ind netstr.Handle) {
	for i := 0; i < x.cnt; i++ {
		it := &x.arr[i]
		if it.state == sendAccepted && it.conn == ind {
			x.cancel(it, 1)
		}
	}
}

func (x *sender) New() (*sendStream, sendStreamID) {
	for i := 0; i < x.cnt; i++ {
		it := &x.arr[i]
		if it.state == sendFree && it.size == 0 {
			return it, sendStreamID(i)
		}
	}
	return nil, 0
}

func (x *sender) Free() {
	x.arr = nil
}

func (x *sender) Update(ts Time) {
	if x.active == 0 {
		return
	}
	if x.cnt <= 0 {
		return
	}
	for i := 0; i < x.cnt; i++ {
		s := &x.arr[i]
		if s.state != sendAccepted {
			continue
		}
		for j, b := 0, s.first; j < 2 && b != nil; j, b = j+1, b.next {
			if t := b.lastSent; t == 0 {
				sendData(s.conn, s.stream, b.ind, b.data)
				s.nextChunk++
				b.lastSent = ts
			} else if ts > t+90 {
				if b.retries < 20 {
					sendData(s.conn, s.stream, b.ind, b.data)
					b.lastSent = ts
					b.retries++
				} else if s.state == sendAccepted {
					x.cancel(s, 2)
					break
				}
			}
		}
	}
}

func (x *sender) cancel(s *sendStream, reason byte) {
	sendCancel(s.conn, s.stream, reason)
	s.callAborted()
	s.Free()
	s.Reset()
	if x.active != 0 {
		x.active--
	}
}

func sendStart(conn netstr.Handle, act Action, typ string, sz int, tok sendStreamID) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferStart{
		Act:   byte(act),
		Size:  uint32(sz),
		Type:  noxnet.FixedString{Value: typ},
		Token: byte(tok),
	}}, netstr.SendQueue|netstr.SendFlush)
}

func sendData(conn netstr.Handle, stream recvStreamID, chunk chunkInd, data []byte) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferData{
		Stream: byte(stream),
		Token:  0,
		Chunk:  uint16(chunk),
		Data:   data,
	}}, 0)
	conn.SendReadPacket(true)
}

func sendCancel(conn netstr.Handle, stream recvStreamID, reason byte) {
	conn.SendMsg(&noxnet.MsgXfer{&noxnet.MsgXferState{
		Code:   noxnet.XferCode5,
		Stream: byte(stream),
		Token:  reason,
	}}, netstr.SendQueue|netstr.SendFlush)
}
