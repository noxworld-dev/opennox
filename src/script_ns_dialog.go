package opennox

import (
	"github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/noxscript/ns/v4/audio"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func (s noxScriptNS) SetShopkeeperText(obj ns.Obj, text ns.StringID) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) SetShopkeeperTextStr(obj ns.Obj, text string) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) TellStory(aud audio.Name, story ns.StringID) {
	caller := s.s.noxScript.Caller()
	trigger := s.s.noxScript.Trigger()
	snd := sound.ByName(string(aud))
	nox_xxx_startShopDialog_548DE0(caller, trigger, snd, strman.ID(story))
}

func (s noxScriptNS) TellStoryStr(audio audio.Name, story string) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) StartDialog(cobj ns.Obj, cother ns.Obj) {
	if cobj == nil || cother == nil {
		return
	}
	obj := s.asObj(cobj)
	other := s.asObj(cother)
	nox_xxx_script_forcedialog_548CD0(other, obj)
}
