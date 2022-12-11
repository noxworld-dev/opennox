package opennox

/*
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
*/
import "C"
import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns"
	"github.com/noxworld-dev/opennox-lib/strman"
)

func (s noxScriptNS) GetHost() ns.Obj {
	// Note: original C code got the player from `s.s.getPlayerByInd(MaxPlayers - 1)`
	u := HostPlayerUnit()
	if u == nil {
		return nil
	}
	return nsObj{u.AsObject()}
}

func (s noxScriptNS) GetCharacterData(field int) int {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) Print(message ns.StringID) {
	c := s.GetCaller()
	if c == nil {
		return
	}
	obj := c.(noxObject).AsObject()
	if !c.Class().Has(object.ClassPlayer) {
		return
	}
	str := s.s.Strings().GetStringInFile(strman.ID(message), "CScrFunc.c")
	nox_xxx_netSendLineMessage_4D9EB0(obj.AsUnit(), str)
}

func (s noxScriptNS) PrintToAll(message ns.StringID) {
	str := s.s.Strings().GetStringInFile(strman.ID(message), "CScrFunc.c")
	PrintToPlayers(str)
}

func (s noxScriptNS) ClearMessages(pl ns.Obj) {
	if pl == nil {
		return
	}
	u := pl.(noxObject).AsObject().AsUnit()
	nox_xxx_netScriptMessageKill_4D9760(u)
}

func (s noxScriptNS) UnBlind() {
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
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
	s.s.noxScript.noxScriptEndGame(int(class))
}
