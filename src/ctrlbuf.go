package opennox

import (
	"encoding/binary"

	"github.com/noxworld-dev/opennox-lib/player"
)

const ctrlBufCap = 128

type serverCtrlBuf struct {
	byPlayer [noxMaxPlayers]ctrlBuf
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

func (s *Server) netOnPlayerInput(pi int, data []byte) int {
	pl := s.getPlayerByInd(pi)
	sz := int(data[0])
	data = data[1 : 1+sz]
	if pl != nil && *(*byte)(pl.field(3680))&0x10 == 0 {
		return 1 + sz
	}
	buf := netDecodePlayerInput(data, nil)
	s.ctrlbuf.Player(pi).Append(buf)
	return 1 + sz
}

func netDecodePlayerInput(data []byte, out []ctrlBufEvent) []ctrlBufEvent {
	for len(data) > 0 {
		code := player.CtrlCode(data[0])
		data = data[4:]
		v := ctrlBufEvent{
			code:   code,
			active: true,
		}
		if sz := code.DataSize(); sz != 0 {
			var b [4]byte
			copy(b[:], data[:sz])
			v.data = binary.LittleEndian.Uint32(b[:4])
			data = data[sz:]
		}
		out = append(out, v)
	}
	return out
}
