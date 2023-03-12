package opennox

import (
	"github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/noxscript/ns/v4/audio"

	"github.com/noxworld-dev/opennox/v1/server"
)

func (s noxScriptNS) SetShopkeeperText(obj ns.Obj, text ns.StringID) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) SetShopkeeperTextStr(obj ns.Obj, text string) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) SetDialog(cobj ns.Obj, typ ns.DialogType, start, end ns.Func) {
	if cobj == nil {
		return
	}
	flags := server.ParseDialogFlags(string(typ))
	obj := cobj.(nsObj)
	starti := s.s.noxScript.AsFuncIndex(start)
	endi := s.s.noxScript.AsFuncIndex(end)
	nox_xxx_scriptSetDialog_548C80(obj.SObj(), flags, starti, endi)
}

func (s noxScriptNS) CancelDialog(obj ns.Obj) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) StoryPic(obj ns.Obj, name string) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) TellStory(audio audio.Name, story ns.StringID) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) TellStoryStr(audio audio.Name, story string) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) StartDialog(obj ns.Obj, other ns.Obj) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) GetAnswer(obj ns.Obj) ns.DialogAnswer {
	//TODO implement me
	panic("implement me")
}
