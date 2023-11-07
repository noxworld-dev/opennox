package server

import ns4 "github.com/noxworld-dev/noxscript/ns/v4"

func nsToObj(v ns4.Obj) *Object {
	if v == nil {
		return nil
	}
	return toObject(v.(Obj))
}

func (s NoxScriptNS) IsTrigger(obj ns4.Obj) bool {
	v := s.s.NoxScriptVM.Trigger()
	if v == nil || obj == nil {
		return false
	}
	return v.ScriptIDVal == obj.ScriptID()
}

func (s NoxScriptNS) IsCaller(obj ns4.Obj) bool {
	v := s.s.NoxScriptVM.Caller()
	if v == nil || obj == nil {
		return false
	}
	return v.ScriptIDVal == obj.ScriptID()
}

func (s NoxScriptNS) IsGameBall(obj ns4.Obj) bool {
	if obj == nil {
		return false
	}
	return s.s.Types.GameBallID() == obj.Type().Index()
}

func (s NoxScriptNS) IsCrown(obj ns4.Obj) bool {
	if obj == nil {
		return false
	}
	return s.s.Types.CrownID() == obj.Type().Index()
}

func (s NoxScriptNS) IsSummoned(obj ns4.Obj) bool {
	if obj == nil {
		return false
	}
	return (obj.MonsterStatus()>>7)&0x1 != 0
}
