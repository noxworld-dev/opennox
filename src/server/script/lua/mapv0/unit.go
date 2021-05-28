package mapv0

import (
	"fmt"

	lua "github.com/yuin/gopher-lua"

	"nox/v1/server/script"
)

type metaUnit struct {
	Unit *lua.LTable
}

func (vm *api) newUnit(u script.Unit) lua.LValue {
	if u == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: u, Metatable: vm.meta.Unit}
}

func (vm *api) initMetaUnit() {
	vm.meta.Unit = vm.newMeta("")
}

func (vm *api) initUnit() {
	// print(Unit)
	vm.meta.Unit.RawSetString("__tostring", vm.s.NewFunction(func(s *lua.LState) int {
		u, ok := s.CheckUserData(1).Value.(script.Unit)
		if !ok {
			return 0
		}
		str := "Unit(" + u.ID() + ")"
		s.Push(lua.LString(str))
		return 1
	}))
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
	vm.meta.Unit.RawSetString("__newindex", vm.s.NewFunction(func(s *lua.LState) int {
		val := s.CheckUserData(1).Value
		key := s.CheckString(2)
		if vm.setindexInterfaceV0(s, val, key) {
			return 0
		}
		u, ok := val.(script.Unit)
		if !ok {
			return 0
		}
		_ = u
		switch key {
		default:
			s.ArgError(2, fmt.Sprintf("no such key: %q", key))
			return 0
		}
	}))
	vm.registerDeleterV0(vm.meta.Unit)
	vm.registerPositionerV0(vm.meta.Unit)
	vm.registerMoverV0(vm.meta.Unit)
	vm.registerMobileV0(vm.meta.Unit)
	vm.registerOffensiveV0(vm.meta.Unit)
	vm.registerChattyV0(vm.meta.Unit)
}
