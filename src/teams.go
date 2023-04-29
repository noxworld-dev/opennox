package opennox

import (
	"encoding/binary"

	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/noxnet"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s *Server) teamsReset() {
	s.Teams.Reset()
	noxflags.SetGamePlay(2)
	noxflags.UnsetGamePlay(1)
	noxflags.UnsetGamePlay(4)
}

func (s *Server) TeamCount() int {
	return int(memmap.Uint8(0x5D4594, 526280))
}

func nox_xxx_objGetTeamByNetCode_418C80(code int) *server.ObjectTeam {
	if noxflags.HasGame(noxflags.GameHost) {
		p := noxServer.getObjectFromNetCode(code)
		if p != nil {
			return p.TeamPtr()
		}
	} else {
		p := noxClient.Objs.ByNetCodeDynamic(code)
		if p != nil {
			return p.TeamPtr()
		}
	}
	return nil
}

func (s *Server) createCoopTeam() {
	noxflags.SetGame(noxflags.GameModeCoopTeam)
	const id = 1
	t := s.Teams.ByID(id)
	if t == nil {
		t = s.TeamCreate(id)
	}
	if v1 := nox_xxx_objGetTeamByNetCode_418C80(int(legacy.Get_nox_player_netCode_85319C())); v1 != nil {
		legacy.Nox_xxx_createAtImpl_4191D0(t.ID(), v1, 0, legacy.Get_nox_player_netCode_85319C(), 0)
	}
	if t != nil {
		text := s.Strings().GetStringInFile("COOP", "C:\\NoxPost\\src\\common\\System\\team.c")
		t.SetNameAnd68(text, 0)
	}
	noxflags.UnsetGamePlay(1)
}

func (s *Server) TeamCreate(id server.TeamID) *server.Team {
	if int(memmap.Uint8(0x5D4594, 526280)) >= s.Teams.Count()-1 {
		text := s.Strings().GetStringInFile("teamexceed", "C:\\NoxPost\\src\\common\\System\\team.c")
		s.Printf(console.ColorRed, text)
		return nil
	}
	t := s.Teams.New(id)
	*memmap.PtrUint8(0x5D4594, 526280)++
	legacy.Sub_459CD0() // TODO: GUI callback
	if !noxflags.HasGame(noxflags.GameModeCoopTeam) {
		text := s.Strings().GetStringInFile("teamcreate", "C:\\NoxPost\\src\\common\\System\\team.c")
		s.Printf(console.ColorRed, text)
	}
	return t
}

func (s *Server) TeamsResetYyy() int {
	s.Teams.ResetYyy()
	if !noxflags.HasGame(noxflags.GameHost) {
		return 0
	}
	return s.sendTeamPacket(0x09)
}

func (s *Server) sendTeamPacket(op byte) int {
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_TEAM_MSG)
	buf[1] = op
	return s.nox_xxx_netSendPacket1_4E5390(159, buf[:], 0, 1)
}

func (s *Server) teamChangeLessons(tm *server.Team, val int) { // nox_xxx_netChangeTeamID_419090
	if tm == nil {
		return
	}
	tm.Lessons = val
	if !noxflags.HasGame(noxflags.GameHost) {
		return
	}
	var buf [10]byte
	buf[0] = byte(noxnet.MSG_TEAM_MSG)
	buf[1] = 0x8
	binary.LittleEndian.PutUint32(buf[2:], uint32(tm.ID()))
	binary.LittleEndian.PutUint32(buf[6:], uint32(val))
	s.nox_xxx_netSendPacket1_4E5390(159, buf[:10], 0, 1)
}

func (s *Server) TeamsZzz(a1 int) int {
	noxflags.UnsetGamePlay(4)
	for i := 1; i < len(s.Teams.Arr); i++ {
		t := &s.Teams.Arr[i]
		if t.Active() {
			legacy.Sub_418F20(t.C(), 0)
		}
	}
	if a1 == 0 {
		return 0
	}
	legacy.Sub_456FA0() // TODO: GUI callback?
	return s.sendTeamPacket(0x07)
}
