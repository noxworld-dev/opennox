package mapv0

import (
	lua "github.com/yuin/gopher-lua"

	"nox/v1/server/script"
)

type metaWaypoint struct {
	Waypoint *lua.LTable
}

func (vm *api) newWaypoint(v script.Waypoint) lua.LValue {
	if v == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: v, Metatable: vm.meta.Waypoint}
}

func (vm *api) initMetaWaypoint() {
	vm.meta.Waypoint = vm.newMeta("Waypoint")
}

func (vm *api) initWaypoint() {
	// print(Waypoint)
	vm.meta.Waypoint.RawSetString("__tostring", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Waypoint)
		if !ok {
			return 0
		}
		str := "Waypoint(" + obj.ID() + ")"
		s.Push(lua.LString(str))
		return 1
	}))
	// Waypoint(id string)
	vm.meta.Waypoint.RawSetString("__call", vm.s.NewFunction(func(s *lua.LState) int {
		id := s.CheckString(2)
		wp := vm.g.WaypointByID(id)
		s.Push(vm.newWaypoint(wp))
		return 1
	}))
	// Waypoint[key]
	vm.setIndexFunction(vm.meta.Waypoint, nil)
	// Waypoint[key] = v
	vm.setSetIndexFunction(vm.meta.Waypoint, nil)
	vm.registerPositionerV0(vm.meta.Waypoint)
	vm.registerMoverV0(vm.meta.Waypoint)
	vm.registerTogglerV0(vm.meta.Waypoint)
}
