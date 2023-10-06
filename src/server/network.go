package server

import (
	"encoding/binary"
	"image"
	"io"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/player"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
)

func (s *Server) OnPacketOpSub(pli ntype.PlayerInd, op noxnet.Op, data []byte, pl *Player, u *Object) (int, bool, error) {
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
	case noxnet.MSG_PLAYER_INPUT:
		n := s.netOnPlayerInput(pl, data[1:])
		return 1 + n, true, nil
	case noxnet.MSG_IMPORTANT:
		if len(data) < 5 {
			return 0, false, io.ErrUnexpectedEOF
		}
		id := binary.LittleEndian.Uint32(data[1:])

		var buf [5]byte
		buf[0] = byte(noxnet.MSG_IMPORTANT_ACK)
		binary.LittleEndian.PutUint32(buf[1:], id)
		netlist.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:5])
		return 5, true, nil
	}
	return 0, false, nil
}

func (s *Server) netOnPlayerInput(pl *Player, data []byte) int {
	sz := int(data[0])
	data = data[1 : 1+sz]
	if pl.Field3680&0x10 == 0 {
		return 1 + sz
	}
	buf := netDecodePlayerInput(data, nil)
	s.Players.Control.Player(pl.Index()).Append(buf)
	return 1 + sz
}

func netDecodePlayerInput(data []byte, out []PlayerCtrl) []PlayerCtrl {
	for len(data) > 0 {
		code := player.CtrlCode(data[0])
		data = data[4:]
		v := PlayerCtrl{
			Code:   code,
			Active: true,
		}
		if sz := code.DataSize(); sz != 0 {
			var b [4]byte
			copy(b[:], data[:sz])
			v.Data = binary.LittleEndian.Uint32(b[:4])
			data = data[sz:]
		}
		out = append(out, v)
	}
	return out
}

type ImportantItem2 struct {
	Field0 byte
	Field1 byte
	Field2 byte
	Field3 byte
	Field4 uint32
	Field8 uint32
}
