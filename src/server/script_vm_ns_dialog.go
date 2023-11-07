package server

import "github.com/noxworld-dev/noxscript/ns/v4"

func (s NoxScriptNS) SetDialog(cobj ns.Obj, typ ns.DialogType, start, end ns.Func) {
	if cobj == nil {
		return
	}
	flags := ParseDialogFlags(string(typ))
	starti := s.s.NoxScriptVM.AsFuncIndex("DialogStart", start)
	endi := s.s.NoxScriptVM.AsFuncIndex("DialogEnd", end)
	nsToObj(cobj).ScriptSetDialog(flags, starti, endi)
}

func (s NoxScriptNS) CancelDialog(cobj ns.Obj) {
	if cobj == nil {
		return
	}
	nsToObj(cobj).ScriptCancelDialog()
}

func (s NoxScriptNS) StoryPic(cobj ns.Obj, name string) {
	if cobj == nil {
		return
	}
	nsToObj(cobj).SetDialogPortrait(name)
}

func (s NoxScriptNS) GetAnswer(cobj ns.Obj) ns.DialogAnswer {
	if cobj == nil {
		return 0
	}
	return ns.DialogAnswer(nsToObj(cobj).ScriptDialogResult())
}
