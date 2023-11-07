package opennox

import (
	"github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) GetHost() ns.Obj {
	// Note: original C code got the player from `s.s.GetPlayerByInd(MaxPlayers - 1)`
	u := s.s.Players.HostUnit
	if u == nil {
		return nil
	}
	return nsObj{s.s, asObjectS(u)}
}

func (s noxScriptNS) HostPlayer() ns.Player {
	pl := HostPlayer()
	if pl == nil {
		return nil
	}
	return nsPlayer{s.s, pl}
}

func (s noxScriptNS) Players() []ns.Player {
	list := s.s.Players.List()
	out := make([]ns.Player, 0, len(list))
	for _, p := range list {
		out = append(out, nsPlayer{s.s, asPlayerS(p)})
	}
	return out
}

func (s noxScriptNS) GetCharacterData(field int) int {
	p := legacy.Nox_xxx_getHostInfoPtr_431770()
	switch field {
	case 0:
		return int(p.Field2235())
	case 1:
		return int(p.Field2239())
	case 2:
		return int(p.Field2243())
	case 3:
		return int(p.Field2247())
	case 4:
		return int(p.PlayerClass())
	case 5:
		if p.IsFemale() {
			return 1
		}
		return 0
	default:
		return 0
	}
}

func (s noxScriptNS) Print(message ns.StringID) {
	c := s.GetCaller()
	if c == nil {
		return
	}
	obj := toObject(c.(server.Obj))
	if !c.Class().Has(object.ClassPlayer) {
		return
	}
	str := s.s.Strings().GetStringInFile(strman.ID(message), "CScrFunc.c")
	legacy.Nox_xxx_netSendLineMessage_4D9EB0(obj.SObj(), str)
}

func (s noxScriptNS) PrintToAll(message ns.StringID) {
	str := s.s.Strings().GetStringInFile(strman.ID(message), "CScrFunc.c")
	legacy.PrintToPlayers(str)
}

func (s noxScriptNS) PrintStr(message string) {
	c := s.GetCaller()
	if c == nil {
		return
	}
	pl := c.Player()
	if pl == nil {
		return
	}
	pl.PrintStr(message)
}

func (s noxScriptNS) PrintStrToAll(message string) {
	legacy.PrintToPlayers(message)
}

func (s noxScriptNS) UnBlind() {
	legacy.Set_nox_gameDisableMapDraw_5d4594_2650672(0)
	noxClient.r.FadeOutScreen(25, false, nil)
}

func (s noxScriptNS) Blind() {
	noxClient.r.FadeInScreen(25, false, fadeDisableGameDraw)
}

func (s noxScriptNS) WideScreen(enable bool) {
	s.s.CinemaPlayers(enable)
}

func (s noxScriptNS) IsTalking() bool {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) IsTrading() bool {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) SetHalberd(upgrade ns.HalberdLevel) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) ImmediateBlind() {
	nox_xxx_cliPlayMapIntro_44E0B0(1)
}

func (s noxScriptNS) EndGame(class player.Class) {
	noxScriptEndGame(int(class))
}

func (s noxScriptNS) StartupScreen(which int) {
	noxScriptStartupScreen(which)
}

func (s noxScriptNS) DeathScreen(which int) {
	*memmap.PtrUint32(0x5D4594, 2386832) = 0
	sub5165D0(which)
}

type nsPlayer struct {
	s *Server
	p *Player
}

func (p nsPlayer) Name() string {
	return p.p.Name()
}

func (p nsPlayer) Unit() ns.Obj {
	u := p.p.UnitC()
	if u == nil {
		return nil
	}
	return nsObj{p.s, u}
}

func (p nsPlayer) Team() ns.Team {
	// TODO: any other way?
	u := p.Unit()
	if u == nil {
		return nil
	}
	return u.Team()
}

func (p nsPlayer) HasTeam(t ns.Team) bool {
	// TODO: any other way?
	u := p.Unit()
	if u == nil {
		return false
	}
	return u.HasTeam(t)
}

func (p nsPlayer) GetScore() int {
	return int(p.p.Lessons)
}

func (p nsPlayer) ChangeScore(score int) {
	u := p.p.UnitC()
	if u == nil {
		return
	}
	p.p.Lessons += int32(score)
	if tm := u.Team(); tm != nil {
		p.s.TeamChangeLessons(tm, score+tm.Lessons)
	}
	p.s.Nox_xxx_netReportLesson_4D8EF0(u.SObj())
}

func (p nsPlayer) Print(message ns.StringID) {
	u := p.p.UnitC()
	if u == nil {
		return
	}
	str := p.s.Strings().GetStringInFile(strman.ID(message), "CScrFunc.c")
	legacy.Nox_xxx_netSendLineMessage_4D9EB0(u.SObj(), str)
}

func (p nsPlayer) PrintStr(message string) {
	u := p.p.UnitC()
	if u == nil {
		return
	}
	legacy.Nox_xxx_netSendLineMessage_4D9EB0(u.SObj(), message)
}

func (p nsPlayer) Blind(blind bool) {
	p.p.Blind(blind)
}
