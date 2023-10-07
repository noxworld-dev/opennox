package server

import (
	"encoding/binary"
	"image"
	"io"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
)

func (s *Server) NetSendPacketXxx0(a1 int, buf []byte, a4, a5 int) int {
	return s.NetSendPacketXxx(a1, buf, a4, a5, 0)
}

func (s *Server) NetSendPacketXxx1(a1 int, buf []byte, a4, a5 int) int {
	return s.NetSendPacketXxx(a1, buf, a4, a5, 1)
}

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
		s.NetList.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:5])
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

func (s *Server) NetInformTextMsg(pid ntype.PlayerInd, code byte, ind int) bool {
	if pid < 0 {
		return false
	}
	var buf [6]byte
	buf[0] = byte(noxnet.MSG_INFORM)
	buf[1] = code
	switch code {
	case 0, 1, 2, 12, 13, 16, 20, 21:
		binary.LittleEndian.PutUint32(buf[2:], uint32(ind))
		return s.NetList.AddToMsgListCli(pid, netlist.Kind1, buf[:6])
	case 17:
		return s.NetList.AddToMsgListCli(pid, netlist.Kind1, buf[:2])
	default:
		return true
	}
}

func (s *Server) NetPrintLineToAll(id strman.ID) { // nox_xxx_netPrintLineToAll_4DA390
	for _, u := range s.Players.ListUnits() {
		s.NetPriMsgToPlayer(u.SObj(), id, 0)
	}
}

func (s *Server) NetPriMsgToPlayer(u *Object, id strman.ID, a3 byte) {
	var buf [52]byte
	if u == nil || !u.Class().Has(object.ClassPlayer) || id == "" || len(id) > len(buf)-4 || s.Players.CheckXxx(u) {
		return
	}
	buf[0] = byte(noxnet.MSG_INFORM)
	buf[1] = 15
	buf[2] = a3
	n := copy(buf[3:len(buf)-1], string(id))
	buf[3+n] = 0
	s.NetList.AddToMsgListCli(u.ControllingPlayer().PlayerIndex(), netlist.Kind1, buf[:n+4])
}

func (s *Server) NetPrintCompToAll(i int) {
	switch i {
	case 0:
		s.NetPrintLineToAll("report.c:NoComp")
	case 1:
		s.NetPrintLineToAll("report.c:MinComp")
	case 2:
		s.NetPrintLineToAll("report.c:AveComp")
	case 3:
		s.NetPrintLineToAll("report.c:UserComp")
	}
}
