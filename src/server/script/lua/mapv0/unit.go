package mapv0

import (
	lua "github.com/yuin/gopher-lua"

	"nox/v1/common/types"
	"nox/v1/server/script"
)

type metaUnit struct {
	Unit      *lua.LTable
	UnitGroup *lua.LTable
}

func (vm *api) newUnit(u script.Unit) lua.LValue {
	if u == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: u, Metatable: vm.meta.Unit}
}

func (vm *api) newUnitGroup(v *script.UnitGroup) lua.LValue {
	if v == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: v, Metatable: vm.meta.UnitGroup}
}

func (vm *api) initMetaUnit() {
	vm.meta.Unit = vm.newMeta("")
	vm.meta.UnitGroup = vm.newMeta("")

	// Mobile
	vm.registerObjMethod("Freeze", func(obj script.Mobile, v *bool) (_ receiverValue) {
		if v == nil {
			obj.Freeze(true)
		} else {
			obj.Freeze(*v)
		}
		return
	})
	vm.registerObjMethod("Idle", func(obj script.Mobile) (_ receiverValue) {
		obj.Idle()
		return
	})
	vm.registerObjMethod("Wander", func(obj script.Mobile) (_ receiverValue) {
		obj.Wander()
		return
	})
	vm.registerObjMethod("Return", func(obj script.Mobile) (_ receiverValue) {
		obj.Return()
		return
	})
	vm.registerObjMethod("LookAtDir", func(obj script.Mobile, v int) (_ receiverValue) {
		obj.LookAtDir(v)
		return
	})
	vm.registerObjMethod("LookAngle", func(obj script.Mobile, v int) (_ receiverValue) {
		obj.LookAngle(v)
		return
	})
	vm.registerObjMethod("LookAt", func(obj script.Mobile, p types.Pointf) (_ receiverValue) {
		obj.LookAt(p)
		return
	})
	vm.registerObjMethod("MoveTo", func(obj script.Mobile, p types.Pointf) (_ receiverValue) {
		obj.MoveTo(p)
		return
	})
	vm.registerObjMethod("WalkTo", func(obj script.Mobile, p types.Pointf) (_ receiverValue) {
		obj.WalkTo(p)
		return
	})
	vm.registerObjMethod("Follow", func(obj script.Mobile, obj2 script.Positioner) (_ receiverValue) {
		obj.Follow(obj2)
		return
	})
	vm.registerObjMethod("Flee", func(obj script.Mobile, obj2 script.Positioner, dur *script.Duration) (_ receiverValue) {
		var d script.Duration
		if dur != nil {
			d = *dur
		}
		obj.Flee(obj2, d)
		return
	})

	// Offensive
	vm.registerObjMethod("Attack", func(obj script.OffensiveGroup, obj2 script.Positioner) (_ receiverValue) {
		obj.Attack(obj2)
		return
	})
	vm.registerObjMethod("HitMelee", func(obj script.OffensiveGroup, p types.Pointf) (_ receiverValue) {
		obj.HitMelee(p)
		return
	})
	vm.registerObjMethod("HitRanged", func(obj script.OffensiveGroup, p types.Pointf) (_ receiverValue) {
		obj.HitRanged(p)
		return
	})
	vm.registerObjMethod("Guard", func(obj script.OffensiveGroup) (_ receiverValue) {
		obj.Guard()
		return
	})
	vm.registerObjMethod("Hunt", func(obj script.OffensiveGroup) (_ receiverValue) {
		obj.Hunt()
		return
	})

	// Chatty
	vm.registerObjMethod("Say", func(obj script.Chatty, text string, dur *script.Duration) (_ receiverValue) {
		var d script.Duration
		if dur != nil {
			d = *dur
		}
		obj.Say(text, d)
		return
	})
	vm.registerObjMethod("Mute", func(obj script.Chatty) (_ receiverValue) {
		obj.Mute()
		return
	})
}

func (vm *api) initUnit() {
	// Unit[key]
	vm.setIndexFunction(vm.meta.Unit, func(val interface{}, key string) (lua.LValue, bool) {
		u, ok := val.(script.Unit)
		if !ok {
			return nil, false
		}
		switch key {
		case "type":
			typ := u.ObjectType()
			return vm.newObjectType(typ), true
		}
		return nil, false
	})
	// Unit[key] = v
	vm.setSetIndexFunction(vm.meta.Unit, nil)
}

func (vm *api) initUnitGroup() {
	// UnitGroup[key]
	vm.setIndexFunction(vm.meta.UnitGroup, nil)
	// UnitGroup[key] = v
	vm.setSetIndexFunction(vm.meta.UnitGroup, nil)
}
