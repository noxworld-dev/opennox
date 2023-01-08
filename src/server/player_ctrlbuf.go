package server

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

type PlayerCtrl struct {
	Code   player.CtrlCode
	Data   uint32
	Active bool
}

func (e *PlayerCtrl) Uint8() byte {
	return byte(e.Data)
}

func (e *PlayerCtrl) Uint16() uint16 {
	return uint16(e.Data)
}

func (e *PlayerCtrl) Uint32() uint32 {
	return e.Data
}

type ctrlBuf struct {
	events [ctrlBufCap]PlayerCtrl
	read   int
	write  int
}

func (cb *ctrlBuf) Append(buf []PlayerCtrl) {
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
		if !p.Active {
			continue
		}
		if p.Code == player.CCMoveForward {
			if code2 {
				p.Active = false
			} else {
				code2 = true
			}
		} else if p.Code == player.CCMoveLeft {
			if code4 {
				p.Active = false
			} else {
				code4 = true
			}
		} else if p.Code == player.CCMoveRight {
			if code5 {
				p.Active = false
			} else {
				code5 = true
			}
		}
	}
}

func (cb *ctrlBuf) First() *PlayerCtrl {
	cb.read = 0
	if cb.write <= 0 {
		return nil
	}
	for !cb.events[cb.read].Active {
		cb.read++
		if cb.read >= cb.write {
			return nil
		}
	}
	return &cb.events[cb.read]
}

func (cb *ctrlBuf) Next() *PlayerCtrl {
	cb.read++
	if cb.read >= cb.write {
		return nil
	}
	for !cb.events[cb.read].Active {
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
