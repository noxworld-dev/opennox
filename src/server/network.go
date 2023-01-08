package server

import (
	"encoding/binary"
	"image"
	"io"

	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/internal/netlist"
)

func (s *Server) OnPacketOpSub(pli int, op noxnet.Op, data []byte, pl *Player, u *Object) (int, bool, error) {
	switch op {
	case noxnet.MSG_KEEP_ALIVE:
		return 1, true, nil
	case 0x26: // TODO: what this opcode is for?
		return 2, true, nil
	case noxnet.MSG_MOUSE:
		if len(data) < 5 {
			return 0, false, io.ErrUnexpectedEOF
		}
		pl.SetCursorPos(image.Point{
			X: int(binary.LittleEndian.Uint16(data[1:])),
			Y: int(binary.LittleEndian.Uint16(data[3:])),
		})
		return 5, true, nil
	case noxnet.MSG_IMPORTANT:
		if len(data) < 5 {
			return 0, false, io.ErrUnexpectedEOF
		}
		id := binary.LittleEndian.Uint32(data[1:])

		var buf [5]byte
		buf[0] = byte(noxnet.MSG_IMPORTANT_ACK)
		binary.LittleEndian.PutUint32(buf[1:], id)
		netlist.AddToMsgListCli(pl.Index(), netlist.Kind1, buf[:5])
		return 5, true, nil
	}
	return 0, false, nil
}
