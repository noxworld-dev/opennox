package opennox

import (
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

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
	t := s.Teams.GetOrCreate(1)
	if v1 := nox_xxx_objGetTeamByNetCode_418C80(int(legacy.Get_nox_player_netCode_85319C())); v1 != nil {
		legacy.Nox_xxx_createAtImpl_4191D0(t.ID(), v1, 0, legacy.Get_nox_player_netCode_85319C(), 0)
	}
	if t != nil {
		text := s.Strings().GetStringInFile("COOP", "C:\\NoxPost\\src\\common\\System\\team.c")
		t.SetNameAnd68(text, 0)
	}
	noxflags.UnsetGamePlay(1)
}

func (s *Server) TeamRemove(t *server.Team, netUpd bool) {
	if t == nil || s.Teams.ByID(t.ID()) == nil {
		return
	}
	name := t.Name()
	if noxflags.HasGame(noxflags.GameHost) && netUpd {
		s.NetTeamRemove(t)
	}
	for pl := s.Players.First(); pl != nil; pl = s.Players.Next(pl) {
		objt := nox_xxx_objGetTeamByNetCode_418C80(pl.NetCode())
		if objt != nil && objt.ID == t.ID() {
			legacy.Sub_418E40(t, objt)
		}
	}
	t.Reset()
	s.Teams.ActiveCnt--
	s.Teams.HookCreateOrRemove()
	if noxflags.HasGame(noxflags.GameHost) {
		legacy.Sub_456EA0(name)
	}
}

func (s *Server) TeamsRemoveActive(hooks bool) int {
	noxflags.UnsetGamePlay(4)
	for i := 1; i < len(s.Teams.Arr); i++ {
		t := &s.Teams.Arr[i]
		if t.Active() {
			s.TeamRemove(t, false)
		}
	}
	if !hooks {
		return 0
	}
	legacy.Sub_456FA0() // TODO: GUI callback?
	return s.SendTeamPacket(0x07)
}
