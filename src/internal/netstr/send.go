package netstr

import (
	"errors"
	"io"

	"github.com/noxworld-dev/opennox-lib/noxnet"
)

func (ns *Conn) SendUnreliableMsg(msg noxnet.Message, flush bool) (int, error) {
	buf, err := noxnet.AppendPacket(nil, msg)
	if err != nil {
		return 0, err
	}
	return ns.SendUnreliable(buf, flush)
}

func (ns *Conn) SendUnreliable(buf []byte, flush bool) (int, error) {
	if ns == nil {
		return -3, errors.New("no net struct")
	}
	if len(buf) == 0 {
		return -2, errors.New("empty buffer")
	}
	n := len(buf)
	dst := ns.sendDestBuf()
	if !flush {
		if n > len(dst) {
			return -7, io.ErrShortBuffer
		}
		copy(dst[:n], buf)
		ns.sendWrite += n
		return n, nil
	}
	if n+2 > len(dst) {
		return -7, io.ErrShortBuffer
	}
	copy(dst[:2], ns.data2hdr()[:2])
	copy(dst[2:2+n], buf)
	n2, err := ns.writeTo(dst[:n+2], ns.addr)
	if n2 == -1 {
		return -1, err
	}
	ns.addTransferStats(n + 2)
	return n2, nil
}

func (ns *Conn) sendDestBuf() []byte {
	if ns == nil {
		return nil
	}
	return ns.sendBuf[ns.sendWrite:]
}

func (ns *Conn) callSendPoll(buf []byte) int {
	if ns.sendPoll == nil {
		return 0
	}
	return ns.sendPoll(ns, buf)
}

func (ns *Conn) Flush() error {
	return ns.sendFlush(false)
}

func (ns *Conn) FlushAndPoll() error {
	return ns.sendFlush(true)
}

func (ns *Conn) sendFlush(poll bool) error {
	if ns == nil {
		return errors.New("nil connection")
	}
	ns.reliable.Resend()
	if poll {
		dst := ns.sendDestBuf()
		n := ns.callSendPoll(dst)
		if n > 0 && n <= len(dst) {
			ns.sendWrite += n
		}
	}
	buf := ns.sendBuf[:ns.sendWrite]
	if len(buf) <= 2 {
		return nil // don't send the header only
	}
	_, err := ns.writeTo(buf, ns.addr)
	if err != nil {
		return err
	}
	ns.addTransferStats(len(buf))
	ns.sendWrite = 2 // keep the header
	return nil
}
