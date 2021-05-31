package mapv0

import (
	lua "github.com/yuin/gopher-lua"

	"nox/v1/server/script"
)

type metaWaypoint struct {
	Waypoint      *lua.LTable
	WaypointGroup *lua.LTable
}

func (vm *api) newWaypoint(v script.Waypoint) lua.LValue {
	if v == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: v, Metatable: vm.meta.Waypoint}
}

func (vm *api) newWaypointGroup(v *script.WaypointGroup) lua.LValue {
	if v == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: v, Metatable: vm.meta.WaypointGroup}
}

func (vm *api) initMetaWaypoint() {
	vm.meta.Waypoint = vm.newMeta("Waypoint")
	vm.meta.WaypointGroup = vm.newMeta("WaypointGroup")
}

func (vm *api) initWaypoint() {
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
}

func (vm *api) initWaypointGroup() {
	// WaypointGroup(id string)
	vm.meta.WaypointGroup.RawSetString("__call", vm.s.NewFunction(func(s *lua.LState) int {
		id := s.CheckString(2)
		g := vm.g.WaypointGroupByID(id)
		s.Push(vm.newWaypointGroup(g))
		return 1
	}))
	// WaypointGroup[key]
	vm.setIndexFunction(vm.meta.WaypointGroup, nil)
	// WaypointGroup[key] = v
	vm.setSetIndexFunction(vm.meta.WaypointGroup, nil)
}
