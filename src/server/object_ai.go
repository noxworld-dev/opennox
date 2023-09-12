package server

import (
	"github.com/noxworld-dev/opennox-lib/object"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
)

var aiActions = make(map[ai.ActionType]AIAction)

type AIAction interface {
	Type() ai.ActionType
	Start(u *Object)
	Update(u *Object)
	End(u *Object)
	Cancel(u *Object)
}

func RegisterAIAction(act AIAction) {
	if _, ok := aiActions[act.Type()]; ok {
		panic("already registered")
	}
	aiActions[act.Type()] = act
}

func GetAIAction(typ ai.ActionType) AIAction {
	return aiActions[typ]
}

func aiStackEmptyAndIdle(u *Object) bool {
	ud := u.UpdateDataMonster()
	return ud.AIStackInd == 0 && ai.ActionType(ud.AIStack[0].Action) == ai.ACTION_IDLE
}

type serverAI struct {
	StackChanged bool
}

func (obj *Object) MaybePrintAIStack(event string) {
	if noxflags.HasEngine(noxflags.EngineShowAI) {
		obj.UpdateDataMonster().PrintAIStack(obj.Server().Frame(), event)
	}
}

func (obj *Object) MonsterActionReset() {
	s := obj.Server()
	ud := obj.UpdateDataMonster()
	ud.Field2 = 0
	ud.Field67 = 0
	ud.Field74 = 0
	ud.Field91 = 0
	ud.Field120_1 = 0
	ud.Field120_2 = 0
	ud.Field120_3 = 0
	ud.Field124 = s.Frame()
	ud.Field137 = s.Frame()
}

func (obj *Object) ClearActionStack() { // aka nox_xxx_monsterClearActionStack_50A3A0
	if obj.Class().Has(object.ClassMonster) {
		for !aiStackEmptyAndIdle(obj.SObj()) {
			obj.MonsterPopAction()
		}
	}
}

func (obj *Object) MonsterActionIsScheduled(act ai.ActionType) bool { // nox_xxx_monsterIsActionScheduled_50A090
	stack := obj.UpdateDataMonster().GetAIStack()
	for _, v := range stack {
		if v.Type() == act {
			return true
		}
	}
	return false
}

func (obj *Object) MonsterPushAction(act ai.ActionType, args ...any) *AIStackItem { // aka nox_xxx_monsterPushAction_50A260
	st := obj.MonsterPushActionImpl(act, "go", 0)
	st.SetArgs(args...)
	return st
}

func (obj *Object) MonsterPushActionImpl(act ai.ActionType, file string, line int) *AIStackItem {
	if !obj.Class().Has(object.ClassMonster) {
		return nil
	}
	s := obj.Server()
	ud := obj.UpdateDataMonster()
	if int(ud.AIStackInd) >= len(ud.AIStack)-1 {
		return nil
	}
	if cur := ud.AIStackHead(); cur == nil {
		ud.AIStackInd = -1
	} else {
		if ud.AIStackHead().Type() == ai.ACTION_DEAD && act != ai.ACTION_DYING {
			return nil
		}
		if curAct := cur.Type(); curAct == ai.ACTION_IDLE && ud.AIStackInd == 0 {
			ud.AIStackInd = -1
		} else if !curAct.IsCondition() && cur.Field5 != 0 {
			if a := GetAIAction(curAct); a != nil {
				a.Cancel(obj.SObj())
			}
		}
	}
	ud.AIStackInd++
	ud.AIStack[ud.AIStackInd] = AIStackItem{
		Action: uint32(act), Field5: 0,
	}
	obj.MonsterActionReset()
	if noxflags.HasEngine(noxflags.EngineShowAI) {
		ai.Log.Printf("%d: PushActionStack( %s(#%d), %s ), result: (%s:%d)\n", s.Frame(), obj, obj.NetCode, act, file, line)
	}
	s.AI.StackChanged = true
	return ud.AIStackHead()
}

func (obj *Object) MonsterPopAction() int {
	s := obj.Server()
	ud := obj.UpdateDataMonster()
	if noxflags.HasEngine(noxflags.EngineShowAI) {
		typ := ud.AIStackHead().Type()
		ai.Log.Printf("%d: PopActionStack( %s(#%d) ) = %s@%d:\n", s.Frame(), obj, obj.NetCode, typ, ud.AIStackInd)
	}
	if cur := ud.AIStackHead(); cur != nil {
		if act := cur.Type(); !act.IsCondition() && cur.Field5 != 0 {
			if a := GetAIAction(act); a != nil {
				a.End(obj.SObj())
			}
		}
	}
	s.AI.StackChanged = true
	// pop action
	ud.AIStackInd--
	// pop related conditions (if any)
	for ; ud.AIStackInd >= 0; ud.AIStackInd-- {
		cur := &ud.AIStack[ud.AIStackInd]
		if !cur.Type().IsCondition() {
			break
		}
	}
	obj.MonsterActionReset()
	si := ud.AIStackInd
	if si < 0 {
		ud.AIStackInd = 0
		ud.AIStack[0].Action = 0
	}
	return int(si)
}

func (obj *Object) MonsterIsInjured() bool {
	return obj.UpdateDataMonster().StatusFlags.Has(object.MonStatusInjured)
}

func (obj *Object) MonsterLookAtDamager() bool {
	if !obj.MonsterIsInjured() {
		return false
	}
	obj.MonsterPushAction(ai.ACTION_FACE_LOCATION, obj.Pos132)
	return true
}
