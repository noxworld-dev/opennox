package server

import (
	"github.com/noxworld-dev/opennox-lib/object"

	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
)

func init() {
	RegisterAIAction(AIActionWait{})
	RegisterAIAction(AIActionWaitRel{})
	RegisterAIAction(AIActionMorphIntoChest{})
	RegisterAIAction(AIActionMorphBackToSelf{})
	RegisterAIAction(AIActionDropObj{})
	RegisterAIAction(AIActionFindObj{})
}

type AIActionWait struct{}

func (AIActionWait) Type() ai.ActionType {
	return ai.ACTION_WAIT
}
func (AIActionWait) Start(_ *Object) {}
func (AIActionWait) End(_ *Object)   {}

func (AIActionWait) Update(u *Object) {
	s := u.Server()
	ud := u.UpdateDataMonster()
	if s.Frame() >= ud.AIStackHead().ArgU32(0) {
		u.MonsterPopAction()
	}
}

func (AIActionWait) Cancel(u *Object) {
	u.MonsterPopAction()
}

type AIActionWaitRel struct{}

func (AIActionWaitRel) Type() ai.ActionType {
	return ai.ACTION_WAIT_RELATIVE
}
func (AIActionWaitRel) Start(_ *Object) {}
func (AIActionWaitRel) End(_ *Object)   {}

func (AIActionWaitRel) Update(u *Object) {
	s := u.Server()
	ud := u.UpdateDataMonster()
	if s.Frame() > ud.Field137+ud.AIStackHead().ArgU32(0) {
		u.MonsterPopAction()
	}
}

func (AIActionWaitRel) Cancel(u *Object) {
	u.MonsterPopAction()
}

type AIActionMorphIntoChest struct{}

func (AIActionMorphIntoChest) Type() ai.ActionType {
	return ai.ACTION_MORPH_INTO_CHEST
}

func (AIActionMorphIntoChest) Start(_ *Object)  {}
func (AIActionMorphIntoChest) End(_ *Object)    {}
func (AIActionMorphIntoChest) Cancel(_ *Object) {}

func (AIActionMorphIntoChest) Update(u *Object) {
	ud := u.UpdateDataMonster()
	if ud.Field120_3 != 0 {
		u.MonsterPopAction()
		ud.StatusFlags |= object.MonStatusMorphed
		u.Nox_xxx_monsterMarkUpdate_4E8020()
	}
}

type AIActionMorphBackToSelf struct{}

func (AIActionMorphBackToSelf) Type() ai.ActionType {
	return ai.ACTION_MORPH_BACK_TO_SELF
}

func (AIActionMorphBackToSelf) Start(_ *Object)  {}
func (AIActionMorphBackToSelf) End(_ *Object)    {}
func (AIActionMorphBackToSelf) Cancel(_ *Object) {}

func (AIActionMorphBackToSelf) Update(obj *Object) {
	u := obj
	ud := u.UpdateDataMonster()
	if ud.Field120_3 != 0 {
		u.MonsterPopAction()
		ud.StatusFlags &^= object.MonStatusMorphed
		u.Nox_xxx_monsterMarkUpdate_4E8020()
	}
}

type AIActionDropObj struct{}

func (AIActionDropObj) Type() ai.ActionType {
	return ai.ACTION_DROP_OBJECT
}
func (AIActionDropObj) Start(_ *Object)  {}
func (AIActionDropObj) Update(_ *Object) {}
func (AIActionDropObj) End(_ *Object)    {}
func (AIActionDropObj) Cancel(_ *Object) {}

type AIActionFindObj struct{}

func (AIActionFindObj) Type() ai.ActionType {
	return ai.ACTION_FIND_OBJECT
}
func (AIActionFindObj) Start(_ *Object)  {}
func (AIActionFindObj) Update(_ *Object) {}
func (AIActionFindObj) End(_ *Object)    {}
func (AIActionFindObj) Cancel(_ *Object) {}
