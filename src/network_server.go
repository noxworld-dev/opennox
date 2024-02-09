package opennox

import (
	"encoding/binary"
	"fmt"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/noxnet"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s *Server) onPacket(ind ntype.PlayerInd, data []byte) bool {
	cdata, cfree := alloc.Make([]byte{}, len(data))
	defer cfree()
	return s.onPacketRaw(ind, cdata)
}

func (s *Server) onPacketRaw(pli ntype.PlayerInd, data []byte) bool {
	pl := s.Players.ByInd(pli)
	if len(data) == 0 {
		if pl != nil {
			pl.Frame3596 = s.Frame()
		}
		return true
	}
	if noxflags.HasEngine(noxflags.EngineReplayWrite) {
		s.nox_xxx_replayWriteMSgMB(pl, data)
	}
	op := noxnet.Op(data[0])
	switch op {
	case 0x20:
		if s.newPlayerFromPacket(pli, data[1:]) == 0 {
			s.NetStr.ReadPackets(s.NetStr.ByPlayerInd(pli))
		}
		return true
	case 0x22:
		legacy.Nox_xxx_playerForceDisconnect_4DE7C0(pli)
		return true
	case 0x25:
		if pl != nil {
			pl.Frame3596 = s.Frame()
		}
		return true
	}
	if pl == nil {
		return true
	}
	u := pl.PlayerUnit
	if u == nil {
		return true
	}
	for len(data) > 0 {
		op = noxnet.Op(data[0])
		n, ok := s.onPacketOp(pli, op, data, pl, u)
		if !ok {
			netstr.Log.Printf("SERVER: ERR: op=%d (%s) [%d:???]\n%02x %x", int(op), op.String(), op.Len(), data[0], data[1:])
			return false
		}
		if s.NetStr.Debug && n != 0 {
			netstr.Log.Printf("SERVER: op=%d (%s) [%d:%d]\n%02x %x", int(op), op.String(), int(n)-1, op.Len(), data[0], data[1:])
		}
		if n > len(data) {
			panic(fmt.Errorf("incorrect length returned for op: %v", op))
		}
		data = data[n:]
	}
	pl.Frame3596 = s.Frame()
	return true
}

func (s *Server) onPacketOp(pli ntype.PlayerInd, op noxnet.Op, data []byte, pl *server.Player, u *server.Object) (int, bool) {
	if n, ok, err := s.Server.OnPacketOpSub(pli, op, data, pl, u); err != nil {
		return n, false
	} else if ok {
		return n, true
	}
	switch op {
	case noxnet.MSG_NEED_TIMESTAMP:
		legacy.Nox_xxx_netNeedTimestampStatus_4174F0(pl, 64)
		return 1, true
	case noxnet.MSG_TRY_ABILITY:
		if len(data) < 2 {
			return 0, false
		}
		if !noxflags.HasGame(noxflags.GameModeChat) && pl.Field3680&0x3 == 0 {
			s.abilities.Do(u, server.Ability(data[1]))
		}
		return 2, true
	case noxnet.MSG_CLIENT_READY:
		legacy.Nox_xxx_gameServerReadyMB_4DD180(pl.Index())
		return 1, true
	case noxnet.MSG_SERVER_QUIT_ACK:
		serverQuitAck()
		return 1, true
	case noxnet.MSG_INCOMING_CLIENT:
		legacy.Nox_xxx_netPlayerIncomingServ_4DDF60(pl.Index())
		return 1, true
	case noxnet.MSG_OUTGOING_CLIENT:
		nox_xxx_playerDisconnFinish_4DE530(pl.PlayerIndex(), 2)
		return 1, true
	case noxnet.MSG_REQUEST_TIMER_STATUS:
		v41 := legacy.Sub_40A220()
		Nox_xxx_netTimerStatus_4D8F50(pli, v41)
		return 1, true
	case noxnet.MSG_TEXT_MESSAGE:
		var msg noxnet.MsgText
		n, err := msg.Decode(data[1:])
		if err != nil {
			return 0, false
		}
		text := msg.Text()
		msz := 1 + n
		if pl != nil && (pl.Field3680>>2)&0x1 != 0 {
			return msz, true
		}
		orig := text
		if !msg.Flags.Has(noxnet.TextTeam) { // global chat
			text = s.CallOnChat(nil, pl, pl.PlayerUnit, text)
			if text == "" {
				return msz, true // mute
			}
			if text != orig {
				msg.Flags = noxnet.TextUTF8
				msg.Data = []byte(text + "\x00")
				msg.Size = byte(len(text))
			}
			for it := s.Players.First(); it != nil; it = s.Players.Next(it) {
				if noxflags.HasGame(noxflags.GameClient) && it.Index() == server.HostPlayerIndex {
					noxClient.HandleMessage(server.HostPlayerIndex, &msg)
				} else {
					conn := s.NetStr.ByPlayer(it)
					conn.SendMsg(&msg, 0)
					conn.SendReadPacket(true)
				}
			}
			return msz, true
		}
		// team message
		netcode := int(msg.NetCode)
		tm := nox_xxx_objGetTeamByNetCode_418C80(netcode)
		if tm == nil || !tm.Has() {
			return msz, true
		}
		tcl := s.Teams.ByID(tm.ID)
		if tcl == nil {
			return msz, true
		}
		text = s.CallOnChat(tcl, pl, pl.PlayerUnit, text)
		if text == "" {
			return msz, true // mute
		}
		if text != orig {
			msg.Flags = noxnet.TextUTF8 | noxnet.TextTeam
			msg.Data = []byte(text + "\x00")
			msg.Size = byte(len(text))
		}
		for it := s.Players.First(); it != nil; it = s.Players.Next(it) {
			uit := it.PlayerUnit
			if uit == nil {
				continue
			}
			if legacy.Nox_xxx_teamCompare2_419180(uit.TeamPtr(), tcl.ID()) != 0 {
				if noxflags.HasGame(noxflags.GameClient) && int(uit.NetCode) == legacy.ClientPlayerNetCode() {
					noxClient.HandleMessage(it.PlayerIndex(), &msg)
				} else {
					conn := s.NetStr.ByPlayer(it)
					conn.SendMsg(&msg, 0)
					conn.SendReadPacket(true)
				}
			}
		}
		return msz, true
	case noxnet.MSG_SYSOP_PW:
		if len(data) < 21 {
			return 0, false
		}
		var buf [2]byte
		buf[0] = byte(noxnet.MSG_SYSOP_RESULT)
		pass := legacy.Nox_xxx_sysopGetPass_40A630()
		got := alloc.GoString16B(data[1:])
		if pass == "" || pass != got {
			buf[1] = 0
		} else {
			buf[1] = 1
			if legacy.Sub_4D12A0(pl.Index()) == 0 {
				legacy.Sub_4D1210(pl.Index())
				str := s.Strings().GetStringInFile("sysopAccessGranted", "sdecode.c")
				s.Printf(console.ColorRed, str, pl.Name())
			}
		}
		s.NetSendPacketXxx0(pl.Index(), buf[:2], 0, 1)
		return 1 + 20, true
	case noxnet.MSG_SERVER_CMD:
		if len(data) < 7 {
			return 0, false
		}
		sz := int(data[4])
		wtext := data[5:]
		if len(wtext) < 2*sz {
			return 0, false
		}
		wtext = wtext[:2*sz]
		nox_xxx_serverHandleClientConsole_443E90(pl, data[1], alloc.GoString16B(wtext))
		return 5 + 2*sz, true
	case noxnet.MSG_IMPORTANT_ACK:
		if len(data) < 5 {
			return 0, false
		}
		id := binary.LittleEndian.Uint32(data[1:])
		legacy.Nox_net_importantACK_4E55A0(pl.Index(), int(id))
		return 5, true
	case noxnet.MSG_REQUEST_MAP:
		s.PlayerGoObserver(pl, true, true)
		if u != nil {
			legacy.Nox_xxx_netChangeTeamMb_419570(u.TeamPtr(), uint32(pl.NetCode()))
		}
		s.MapSend.StartSendShared(pl.PlayerIndex())
		return 1, true
	case noxnet.MSG_REQUEST_SAVE_PLAYER:
		if len(data) < 3 {
			return 0, false
		}
		if noxflags.HasGame(noxflags.GameModeQuest) && pl.Index() != server.HostPlayerIndex && pl.IsActive() && u != nil && u.UpdateDataPlayer().Field138 == 1 {
			s.PlayerDisconnect(pl, 2)
		} else {
			fname := datapath.Save(common.SaveDir, "_temp_.dat")
			defer ifs.Remove(fname)
			if savePlayerData(fname, pl.PlayerIndex()) {
				sub41CFA0(fname, pl.PlayerIndex())
			}
		}
		return 3, true
	case noxnet.MSG_TEAM_MSG:
		if len(data) < 10 {
			return 0, false
		}
		switch data[1] {
		case 10:
			ti := server.TeamID(binary.LittleEndian.Uint32(data[2:]))
			tm := s.Teams.ByID(ti)
			if tm == nil {
				return 10, true
			}
			netcode := int(binary.LittleEndian.Uint16(data[6:]))
			obj := s.getObjectFromNetCode(netcode)
			legacy.Nox_xxx_createAtImpl_4191D0(tm.ID(), obj.TeamPtr(), 1, netcode, 1)
			return 10, true
		case 11:
			netcode := int(binary.LittleEndian.Uint16(data[6:]))
			u2 := s.getObjectFromNetCode(netcode)
			if u2 == nil {
				return 10, true
			}
			if !noxflags.HasGame(noxflags.GameModeChat) {
				pos := s.nox_xxx_mapFindPlayerStart_4F7AB0(u2)
				asObjectS(u2).SetPos(pos)
			}
			ti := server.TeamID(binary.LittleEndian.Uint32(data[2:]))
			tm := s.Teams.ByID(ti)
			if tm == nil {
				return 10, true
			}
			legacy.Sub_4196D0(unsafe.Pointer(u2.TeamPtr()), tm.C(), netcode, 1)
			return 10, true
		default:
			return 0, false
		}
	case noxnet.MSG_SOCIAL:
		if len(data) < 2 {
			return 0, false
		}
		switch data[1] {
		case 1:
			nox_xxx_playerSetState_4FA020(u, server.PlayerStateLaugh)
		case 2:
			nox_xxx_playerSetState_4FA020(u, server.PlayerStateShakeFist)
		case 4:
			nox_xxx_playerSetState_4FA020(u, server.PlayerState27) // TODO: should it be state 28 (point)?
		}
		return 2, true
	case noxnet.MSG_DIALOG:
		if len(data) < 2 {
			return 0, false
		}
		typ := data[1]
		switch typ {
		case 1:
			if len(data) < 4 {
				return 0, false
			}
			if nox_xxx_gameGet_4DB1B0() {
				return 4, true
			}
			if pl.Field3680&0x3 != 0 {
				return 4, true
			}
			id := binary.LittleEndian.Uint16(data[2:])
			if obj := legacy.Nox_server_getObjectFromNetCode_4ECCB0(int(id)); obj != nil {
				nox_xxx_script_forcedialog_548CD0(u, obj)
			}
			return 4, true
		case 2:
			if len(data) < 3 {
				return 0, false
			}
			legacy.Nox_xxx_scriptDialog_548D30(u, data[2])
			return 3, true
		}
		return 0, false
	default:
		res := legacy.Nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_switch(pli, data, pl, u, u.UpdateData)
		if res <= 0 || res > len(data) {
			return 0, false
		}
		return res, true
	}
}
