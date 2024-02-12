package netstr

import (
	"errors"
	"slices"
	"time"

	"github.com/noxworld-dev/opennox-lib/noxnet"
)

const (
	reliableRetry = 2 * time.Second
)

func (g *Streams) MaybeSendReliable() {
	now := g.Now()
	g.now = now
	if now-g.lastSendReliable <= 1*time.Second {
		return
	}
	for _, ns := range g.streams {
		if ns != nil {
			ns.reliable.ScheduleAndResend()
		}
	}
	g.lastSendReliable = now
}

func (ns *Conn) SendReliable(buf []byte) (seq int, err error) {
	if ns == nil {
		return -3, errors.New("no net struct")
	}
	if len(buf) == 0 {
		return -2, errors.New("empty buffer")
	}
	seq, err = ns.reliable.Send(ns.data2hdr()[0], buf)
	if err != nil || seq < 0 {
		return -1, err
	}
	return seq, nil
}

func (ns *Conn) SendReliableMsg(msg noxnet.Message) (int, error) {
	buf, err := noxnet.AppendPacket(nil, msg)
	if err != nil {
		return 0, err
	}
	return ns.SendReliable(buf)
}

func (ns *Conn) ReliableInQueue(ops ...noxnet.Op) int {
	return ns.reliable.InQueue(ops...)
}

func newReliableSender(send func(data []byte) (int, error)) *reliableSender {
	start := time.Now()
	return &reliableSender{
		write: send,
		Now: func() time.Duration {
			return time.Since(start)
		},
	}
}

type reliablePacket struct {
	next       *reliablePacket
	retryAt    time.Duration
	data       []byte
	seq        byte
	shouldSend bool
}

type reliableSender struct {
	write func(data []byte) (int, error)
	seq   uint8
	queue *reliablePacket
	Now   func() time.Duration
}

func (ns *reliableSender) InQueue(ops ...noxnet.Op) int {
	cnt := 0
	for it := ns.queue; it != nil; it = it.next {
		op := noxnet.Op(it.data[2])
		if len(ops) == 0 || slices.Contains(ops, op) {
			cnt++
		}
	}
	return cnt
}

func (ns *reliableSender) Send(id byte, buf []byte) (seq int, err error) {
	if len(buf) == 0 {
		return -1, errors.New("empty buffer")
	}
	seq = ns.add(id, buf)
	ns.sendAtSeq(byte(seq))
	return seq, nil
}

func (ns *reliableSender) add(id byte, buf []byte) int {
	seq := ns.seq
	ns.seq++

	data := make([]byte, 2+len(buf))
	data[0] = id | reliableFlag
	data[1] = seq
	copy(data[2:], buf)

	q := &reliablePacket{
		shouldSend: true,
		data:       data,
		seq:        seq,
	}
	q.next = ns.queue
	ns.queue = q

	return int(seq)
}

func (ns *reliableSender) sendAtSeq(seq byte) {
	now := ns.Now()
	for it := ns.queue; it != nil; it = it.next {
		if it.seq != seq {
			continue
		}
		it.shouldSend = false
		it.retryAt = now + reliableRetry
		if _, err := ns.write(it.data); err != nil {
			//ns.g.Log.Println(err)
			break
		}
	}
}

func (ns *reliableSender) Resend() {
	now := ns.Now()
	for it := ns.queue; it != nil; it = it.next {
		if !it.shouldSend {
			continue
		}
		it.shouldSend = false
		it.retryAt = now + reliableRetry
		if _, err := ns.write(it.data); err != nil {
			//ns.g.Log.Println(err)
			break
		}
	}
}

func (ns *reliableSender) Clear() {
	ns.queue = nil
}

func (ns *reliableSender) remove(prev, it *reliablePacket) {
	if head := ns.queue; it == head {
		ns.queue = head.next
	}
	if prev != nil {
		prev.next = it.next
	}
	it.next = nil
	*it = reliablePacket{}
}

func (ns *reliableSender) SetCurrent(seq byte) {
	ns.retry(seq)
	ns.ackOlder(seq)
}

func (ns *reliableSender) retry(seq byte) {
	for it := ns.queue; it != nil; it = it.next {
		if it.seq == seq {
			it.shouldSend = true
		}
	}
}

func (ns *reliableSender) ackOlder(seq byte) {
	var (
		next *reliablePacket
		prev *reliablePacket
	)
	for it := ns.queue; it != nil; it = next {
		next = it.next
		// FIXME: condition here looks wrong
		if seq < 0x20 || seq > 0xE0 {
			if it.seq >= seq {
				prev = it
			} else {
				ns.remove(prev, it)
			}
		} else {
			if it.seq >= seq {
				prev = it
			} else {
				ns.remove(prev, it)
			}
		}
	}
}

func (ns *reliableSender) schedule() {
	now := ns.Now()
	for it := ns.queue; it != nil; it = it.next {
		if it.retryAt <= now {
			it.shouldSend = true
		}
	}
}

func (ns *reliableSender) ScheduleAndResend() {
	ns.schedule()
	ns.Resend()
}
