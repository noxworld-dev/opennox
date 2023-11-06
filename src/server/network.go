package server

import (
	"encoding/binary"
	"image"
	"io"
	"math"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/strman"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
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

func (s *Server) NetRayStop(typ byte, val byte, u1, u2 *Object) {
	var buf [7]byte
	buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
	buf[1] = typ
	buf[2] = val
	binary.LittleEndian.PutUint16(buf[3:], uint16(s.GetUnitNetCode(u1)))
	binary.LittleEndian.PutUint16(buf[5:], uint16(s.GetUnitNetCode(u2)))
	s.NetSendPacketXxx1(math.MaxUint8, buf[:7], 0, 1)
}

func (s *Server) NetTeamRemove(tm *Team) {
	var buf [6]byte
	buf[0] = byte(noxnet.MSG_TEAM_MSG)
	buf[1] = 0x6
	binary.LittleEndian.PutUint32(buf[2:], uint32(tm.ID()))
	s.NetSendPacketXxx1(0x9F, buf[:6], 0, 1)
}

func (s *Server) NetTeamChangeLessons(tm *Team, val int) {
	var buf [10]byte
	buf[0] = byte(noxnet.MSG_TEAM_MSG)
	buf[1] = 0x8
	binary.LittleEndian.PutUint32(buf[2:], uint32(tm.ID()))
	binary.LittleEndian.PutUint32(buf[6:], uint32(val))
	s.NetSendPacketXxx1(159, buf[:10], 0, 1)
}

func (s *Server) SendTeamPacket(op byte) int {
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_TEAM_MSG)
	buf[1] = op
	return s.NetSendPacketXxx1(0x9F, buf[:], 0, 1)
}

func (s *Server) NetMusic(music int, volume int) {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_MUSIC_EVENT)
	buf[1] = byte(music)
	buf[2] = byte(volume)
	s.NetSendPacketXxx1(255, buf[:3], 0, 1)
}

func (s *Server) NetMusicPushEvent() {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_MUSIC_PUSH_EVENT)
	s.NetSendPacketXxx1(255, buf[:3], 0, 1)
}

func (s *Server) NetMusicPopEvent() {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_MUSIC_POP_EVENT)
	s.NetSendPacketXxx1(255, buf[:3], 0, 1)
}

func (s *Server) NetMusicEvent() {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_MUSIC_EVENT)
	s.NetSendPacketXxx1(255, buf[:3], 0, 1)
}

func (s *Server) NetHarpoonAttach(u1, u2 *Object) {
	if u1 != nil && u2 != nil {
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
		buf[1] = 7
		buf[2] = 0
		binary.LittleEndian.PutUint16(buf[3:], uint16(s.GetUnitNetCode(u1)))
		binary.LittleEndian.PutUint16(buf[5:], uint16(s.GetUnitNetCode(u2)))
		s.NetSendPacketXxx1(255, buf[:7], 0, 1)
	}
}

func (s *Server) NetHarpoonBreak(u1 *Object, u2 *Object) {
	if u1 != nil && u2 != nil {
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
		buf[1] = 14
		buf[2] = 0
		binary.LittleEndian.PutUint16(buf[3:], uint16(s.GetUnitNetCode(u1)))
		binary.LittleEndian.PutUint16(buf[5:], uint16(s.GetUnitNetCode(u2)))
		s.NetSendPacketXxx1(255, buf[:7], 0, 1)
	}
}

func (s *Server) Nox_xxx_netFxShield_0_4D9200(a1 int, a2 *Object) int {
	code := uint16(a2.NetCode)
	if noxflags.HasGame(noxflags.GameFlag28) {
		code |= 0x8000
	}
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_REPORT_LOSE_CREATURE)
	binary.LittleEndian.PutUint16(buf[1:], code)
	return s.NetSendPacketXxx1(a1, buf[:], 0, 1)
}

func (s *Server) Nox_xxx_netMsgFadeBegin_4D9800(a1, a2 bool) int {
	var p [3]byte
	p[0] = byte(noxnet.MSG_FADE_BEGIN)
	if a1 {
		p[1] = 1
	}
	if a2 {
		p[2] = 1
	}
	return s.NetSendPacketXxx1(255, p[:], 0, 1)
}

func (s *Server) NetReportSpellStat(a1 int, a2 spell.ID, a3 byte) bool {
	var buf [6]byte
	buf[0] = byte(noxnet.MSG_REPORT_SPELL_STAT)
	binary.LittleEndian.PutUint32(buf[1:], uint32(a2))
	buf[5] = a3
	return s.NetSendPacketXxx0(a1, buf[:], 0, 1) != 0
}

func (s *Server) Nox_xxx_netReportLesson_4D8EF0(u *Object) {
	var buf [11]byte
	buf[0] = byte(noxnet.MSG_REPORT_LESSON)
	pl := u.ControllingPlayer()
	binary.LittleEndian.PutUint16(buf[1:], uint16(u.NetCode))
	binary.LittleEndian.PutUint32(buf[3:], uint32(pl.Lessons))
	binary.LittleEndian.PutUint32(buf[7:], uint32(pl.Field2140))
	s.NetSendPacketXxx1(255, buf[:11], 0, 1)
}

func (s *Server) Nox_xxx_netScriptMessageKill_4D9760(u *Object) {
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	pl := u.ControllingPlayer()
	var buf [1]byte
	buf[0] = byte(noxnet.MSG_MESSAGES_KILL)
	s.NetSendPacketXxx0(pl.Index(), buf[:1], 0, 1)
}

func (s *Server) Nox_xxx_netKillChat_528D00(who *Object) {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_CHAT_KILL)
	binary.LittleEndian.PutUint16(buf[1:], uint16(s.GetUnitNetCode(who)))
	for _, pl := range s.Players.List() {
		u := pl.PlayerUnit
		if u == nil {
			continue
		}
		s.NetList.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:3])
	}
}

func (s *Server) Nox_xxx_sendGauntlet_4DCF80(ind ntype.PlayerInd, v byte) {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_GAUNTLET)
	buf[1] = 28
	buf[2] = v
	s.NetSendPacketXxx1(int(ind), buf[:3], 0, 0)
}

func (s *Server) NetSendServerQuit() {
	var buf [1]byte
	buf[0] = byte(noxnet.MSG_SERVER_QUIT)
	s.NetSendPacketXxx0(159, buf[:1], 0, 1)
}

func (s *Server) Nox_xxx_netSendBallStatus_4D95F0(a1 int, a2 byte, a3 uint16) int {
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_REPORT_BALL_STATUS)
	buf[1] = a2
	binary.LittleEndian.PutUint16(buf[2:], a3)
	return s.NetSendPacketXxx1(a1, buf[:4], 0, 1)
}

func (s *Server) Nox_xxx_netObjectOutOfSight_528A60(ind int, obj *Object) int {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_OBJECT_OUT_OF_SIGHT)
	binary.LittleEndian.PutUint16(buf[1:], uint16(s.GetUnitNetCode(obj)))
	return s.NetSendPacketXxx0(ind, buf[:3], 0, 1)
}

func (s *Server) Nox_xxx_netObjectInShadows_528A90(ind int, obj *Object) int {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_OBJECT_IN_SHADOWS)
	binary.LittleEndian.PutUint16(buf[1:], uint16(s.GetUnitNetCode(obj)))
	return s.NetSendPacketXxx0(ind, buf[:3], 0, 1)
}
