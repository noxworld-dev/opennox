package server

import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"

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
	Paths        serverAIPaths
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

func (obj *Object) MonsterCancelDurSpell(exp spell.ID) {
	if act := obj.UpdateDataMonster().AIStackHead(); act.Type() == ai.ACTION_CAST_DURATION_SPELL {
		if spell.ID(act.ArgU32(0)) == exp {
			obj.MonsterPopAction()
		}
	}
}

func (obj *Object) Sub_545E60() int {
	s := obj.Server()

	ud := obj.UpdateDataMonster()
	ts := obj.Frame134
	if ud.Field129 >= ts || s.Frame()-ts >= s.SecToFrames(10) {
		return 0
	}
	ud.Field129 = ts
	if obj.Obj130 != nil {
		if obj4 := obj.Obj130.GetOwnerUnit(); obj4 != nil {
			if !s.IsEnemyTo(obj, obj4) {
				return 0
			}
			canInteract := s.CanInteract(obj, obj4, 0)
			if s.IsPlant(obj) {
				if !canInteract {
					return 0
				}
				obj.MonsterPushAction(ai.DEPENDENCY_ENEMY_CLOSER_THAN, float32(ud.Field328)*1.05)
			} else {
				obj.MonsterPushAction(ai.DEPENDENCY_UNDER_ATTACK, s.Frame())
			}
			obj.MonsterPushAction(ai.ACTION_FIGHT, obj4.Pos(), s.Frame())
			if !canInteract {
				obj.MonsterPushAction(ai.DEPENDENCY_NO_VISIBLE_ENEMY)
				if obj.Nox_xxx_monsterCanAttackAtWill_534390() {
					obj.MonsterPushAction(ai.DEPENDENCY_NO_INTERESTING_SOUND)
				}
				obj.MonsterPushAction(ai.ACTION_MOVE_TO, obj4.Pos(), 0)
			}
			return 1
		}
	}
	if !obj.UpdateDataMonster().HasAction(ai.ACTION_ROAM) {
		obj.MonsterPushAction(ai.DEPENDENCY_TIME, s.SecToFrames(5))
		obj.MonsterPushAction(ai.DEPENDENCY_NO_VISIBLE_ENEMY)
		if obj.Nox_xxx_monsterCanAttackAtWill_534390() {
			obj.MonsterPushAction(ai.DEPENDENCY_NO_INTERESTING_SOUND)
		}
		obj.MonsterPushAction(ai.ACTION_ROAM, 0, 0, -128)
	}
	return 0
}
