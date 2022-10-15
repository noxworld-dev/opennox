package opennox

import (
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/player"
)

const ctrlBufCap = 128

type serverCtrlBuf struct {
	byPlayer [common.MaxPlayers]ctrlBuf
}

func (s *serverCtrlBuf) Player(pi int) *ctrlBuf {
	return &s.byPlayer[pi]
}

type ctrlBufEvent struct {
	code   player.CtrlCode
	data   uint32
	active bool
}

func (e *ctrlBufEvent) Uint8() byte {
	return byte(e.data)
}

func (e *ctrlBufEvent) Uint16() uint16 {
	return uint16(e.data)
}

func (e *ctrlBufEvent) Uint32() uint32 {
	return e.data
}

type ctrlBuf struct {
	events [ctrlBufCap]ctrlBufEvent
	read   int
	write  int
}

func (cb *ctrlBuf) Append(buf []ctrlBufEvent) {
	i := cb.write
	if i+len(buf) >= len(cb.events) {
		return
	}
	cb.write += copy(cb.events[i:], buf)
	cb.dedup()
}

func (cb *ctrlBuf) dedup() {
	var code4, code5, code2 bool
	for i := cb.write - 1; i >= 0; i-- {
		p := &cb.events[i]
		if !p.active {
			continue
		}
		if p.code == player.CCMoveForward {
			if code2 {
				p.active = false
			} else {
				code2 = true
			}
		} else if p.code == player.CCMoveLeft {
			if code4 {
				p.active = false
			} else {
				code4 = true
			}
		} else if p.code == player.CCMoveRight {
			if code5 {
				p.active = false
			} else {
				code5 = true
			}
		}
	}
}

func (cb *ctrlBuf) First() *ctrlBufEvent {
	cb.read = 0
	if cb.write <= 0 {
		return nil
	}
	for !cb.events[cb.read].active {
		cb.read++
		if cb.read >= cb.write {
			return nil
		}
	}
	return &cb.events[cb.read]
}

func (cb *ctrlBuf) Next() *ctrlBufEvent {
	cb.read++
	if cb.read >= cb.write {
		return nil
	}
	for !cb.events[cb.read].active {
		cb.read++
		if cb.read >= cb.write {
			return nil
		}
	}
	return &cb.events[cb.read]
}

func (cb *ctrlBuf) Reset() {
	cb.write = 0
}

func (cb *ctrlBuf) IsEmpty() bool {
	return cb.write == 0
}
