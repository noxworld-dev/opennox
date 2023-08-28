package noxscript

import (
	"github.com/noxworld-dev/noxscript/ns/asm"
	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/noxscript/ns/v4/damage"
	"github.com/noxworld-dev/noxscript/ns/v4/enchant"
	"github.com/noxworld-dev/noxscript/ns/v4/spell"
)

func init() {
	Register(asm.BuiltinObjectGroup, nsGetObjectGroup)
	Register(asm.BuiltinObjectGroupOn, nsObjectGroupOn)
	Register(asm.BuiltinObjectGroupOff, nsObjectGroupOff)
	Register(asm.BuiltinObjectGroupToggle, nsObjectGroupToggle)
	Register(asm.BuiltinGroupSetOwner, nsGroupSetOwner)
	Register(asm.BuiltinGroupSetOwners, nsGroupSetOwners)
	Register(asm.BuiltinGroupIsOwnedBy, nsGroupIsOwnedBy)
	Register(asm.BuiltinGroupIsOwnedByAny, nsGroupIsOwnedByAny)
	Register(asm.BuiltinGroupDelete, nsGroupDelete)
	Register(asm.BuiltinGroupLookAtDirection, nsGroupLookAtDirection)
	Register(asm.BuiltinGroupWander, nsGroupWander)
	Register(asm.BuiltinCreatureGroupIdle, nsGroupIdle)
	Register(asm.BuiltinCreatureGroupHunt, nsGroupHunt)
	Register(asm.BuiltinCreatureGroupFollow, nsGroupFollow)
	Register(asm.BuiltinGroupWalk, nsGroupWalkTo)
	Register(asm.BuiltinGroupMove, nsGroupMove)
	Register(asm.BuiltinGroupCreateMover, nsGroupCreateMover)
	Register(asm.BuiltinRaiseZombieGroup, nsRaiseZombieGroup)
	Register(asm.BuiltinZombieGroupStayDown, nsZombieStayDownGroup)
	Register(asm.BuiltinGroupDamage, nsGroupDamage)
	Register(asm.BuiltinGroupEnchant, nsGroupEnchant)
	Register(asm.BuiltinGroupAwardSpell, nsGroupAwardSpell)
	Register(asm.BuiltinGroupAggressionLevel, nsSetAggressionLevelGroup)
	Register(asm.BuiltinGroupRetreatLevel, nsSetRetreatLevelGroup)
	Register(asm.BuiltinGroupResumeLevel, nsSetResumeLevelGroup)
	Register(asm.BuiltinGroupAttack, nsGroupAttack)
	Register(asm.BuiltinGroupRunAway, nsGroupRunAway)
	Register(asm.BuiltinCreatureGroupGuard, nsGroupGuard)
	Register(asm.BuiltinGroupPauseObject, nsGroupPause)
	Register(asm.BuiltinGroupHitLocation, nsGroupHitLocation)
	Register(asm.BuiltinGroupHitFarLocation, nsGroupHitFarLocation)
}

func nsGetObjectGroup(s VM) int {
	str := s.PopString()
	str += s.NameSuff()
	s.PushHandleNS(s.NoxScript().ObjectGroup(str))
	return 0
}

func nsObjectGroupOn(s VM) int {
	if g := s.PopObjGroupNS(); g != nil {
		g.Enable(true)
	}
	return 0
}

func nsObjectGroupOff(s VM) int {
	if g := s.PopObjGroupNS(); g != nil {
		g.Enable(false)
	}
	return 0
}

func nsObjectGroupToggle(s VM) int {
	if g := s.PopObjGroupNS(); g != nil {
		g.Toggle()
	}
	return 0
}

func nsGroupSetOwner(s VM) int {
	g := s.PopObjGroupNS()
	owner := s.PopObjectNS()
	if g != nil {
		g.SetOwner(owner)
	}
	return 0
}

func nsGroupSetOwners(s VM) int {
	g := s.PopObjGroupNS()
	owners := s.PopObjGroupNS()
	if g != nil {
		g.SetOwners(owners)
	}
	return 0
}

func nsGroupIsOwnedBy(s VM) int {
	g := s.PopObjGroupNS()
	obj := s.PopObjectNS()
	if g != nil {
		s.PushBool(g.HasOwner(obj))
	} else {
		s.PushBool(false)
	}
	return 0
}

func nsGroupIsOwnedByAny(s VM) int {
	owners := s.PopObjGroupNS()
	g := s.PopObjGroupNS()
	if g != nil {
		s.PushBool(g.HasOwnerIn(owners))
	} else {
		s.PushBool(false)
	}
	return 0
}

func nsGroupDelete(s VM) int {
	g := s.PopObjGroupNS()
	g.EachObject(true, func(obj ns4.Obj) bool {
		obj.Delete()
		return true
	})
	return 0
}

func nsGroupLookAtDirection(s VM) int {
	dir := s.PopI32()
	g := s.PopObjGroupNS()
	if g != nil {
		g.LookAtDirection(ns4.Direction(dir))
	}
	return 0
}

func nsGroupWander(s VM) int {
	if g := s.PopObjGroupNS(); g != nil {
		g.EachObject(true, func(obj ns4.Obj) bool {
			obj.Wander()
			return true
		})
	}
	return 0
}

func nsGroupIdle(s VM) int {
	if g := s.PopObjGroupNS(); g != nil {
		g.Idle()
	}
	return 0
}

func nsGroupHunt(s VM) int {
	if g := s.PopObjGroupNS(); g != nil {
		g.Hunt()
	}
	return 0
}

func nsGroupFollow(s VM) int {
	targ := s.PopObjectNS()
	g := s.PopObjGroupNS()
	if g != nil {
		g.Follow(targ)
	}
	return 0
}

func nsGroupWalkTo(s VM) int {
	p := s.PopPointf()
	g := s.PopObjGroupNS()

	dpos := s.DPosf()
	p = p.Add(dpos)
	if g != nil {
		g.WalkTo(p)
	}
	return 0
}

func nsGroupMove(s VM) int {
	wp := s.PopWaypointNS()
	g := s.PopObjGroupNS()
	if g != nil {
		g.Move(wp)
	}
	return 0
}

func nsGroupCreateMover(s VM) int {
	speed := s.PopF32()
	wp := s.PopWaypointNS()
	g := s.PopObjGroupNS()
	if g != nil {
		g.CreateMover(wp, speed)
	}
	return 0
}

func nsRaiseZombieGroup(s VM) int {
	if g := s.PopObjGroupNS(); g != nil {
		g.RaiseZombie()
	}
	return 0
}

func nsZombieStayDownGroup(s VM) int {
	if g := s.PopObjGroupNS(); g != nil {
		g.ZombieStayDown()
	}
	return 0
}

func nsGroupDamage(s VM) int {
	typ := damage.Type(s.PopI32())
	dmg := int(s.PopI32())
	src := s.PopObjectNS()
	g := s.PopObjectNS()
	if g != nil {
		g.Damage(src, dmg, typ)
	}
	return 0
}

func nsGroupEnchant(s VM) int {
	sec := float64(s.PopF32())
	name := s.PopString()
	g := s.PopObjGroupNS()
	if g != nil {
		g.Enchant(enchant.Enchant(name), ns4.Seconds(sec))
	}
	return 0
}

func nsGroupAwardSpell(s VM) int {
	name := s.PopString()
	g := s.PopObjGroupNS()
	if g != nil {
		g.AwardSpell(spell.Spell(name))
	}
	return 0
}

func nsSetAggressionLevelGroup(vm VM) int {
	v := vm.PopF32()
	g := vm.PopObjGroupNS()
	if g != nil {
		g.AggressionLevel(v)
	}
	return 0
}

func nsSetRetreatLevelGroup(vm VM) int {
	v := vm.PopF32()
	g := vm.PopObjGroupNS()
	if g != nil {
		g.RetreatLevel(v)
	}
	return 0
}

func nsSetResumeLevelGroup(vm VM) int {
	v := vm.PopF32()
	g := vm.PopObjGroupNS()
	if g != nil {
		g.ResumeLevel(v)
	}
	return 0
}

func nsGroupAttack(vm VM) int {
	targ := vm.PopObjectNS()
	g := vm.PopObjGroupNS()
	if g != nil {
		g.Attack(targ)
	}
	return 0
}

func nsGroupRunAway(vm VM) int {
	dt := vm.PopU32()
	targ := vm.PopObjectNS()
	g := vm.PopObjGroupNS()
	if targ != nil && g != nil {
		g.Flee(targ, ns4.Frames(int(dt)))
	}
	return 0
}

func nsGroupGuard(vm VM) int {
	dist := vm.PopF32()
	p2 := vm.PopPointf()
	p1 := vm.PopPointf()
	g := vm.PopObjGroupNS()
	if g != nil {
		g.Guard(p1, p2, dist)
	}
	return 0
}

func nsGroupPause(vm VM) int {
	dt := vm.PopU32()
	g := vm.PopObjGroupNS()
	if g != nil {
		g.Pause(ns4.Frames(int(dt)))
	}
	return 0
}

func nsGroupHitLocation(vm VM) int {
	pos := vm.PopPointf()
	g := vm.PopObjGroupNS()
	if g != nil {
		g.HitMelee(pos)
	}
	return 0
}

func nsGroupHitFarLocation(vm VM) int {
	pos := vm.PopPointf()
	g := vm.PopObjGroupNS()
	if g != nil {
		g.HitRanged(pos)
	}
	return 0
}
