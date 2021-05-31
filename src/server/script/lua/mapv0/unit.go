package mapv0

import (
	lua "github.com/yuin/gopher-lua"

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
	vm.registerMobileV0(vm.meta.Unit)
	vm.registerOffensiveGroupV0(vm.meta.Unit)
	vm.registerChattyV0(vm.meta.Unit)
}

func (vm *api) initUnitGroup() {
	// UnitGroup[key]
	vm.setIndexFunction(vm.meta.UnitGroup, nil)
	// UnitGroup[key] = v
	vm.setSetIndexFunction(vm.meta.UnitGroup, nil)
	vm.registerMobileV0(vm.meta.UnitGroup)
	vm.registerOffensiveGroupV0(vm.meta.UnitGroup)
}
