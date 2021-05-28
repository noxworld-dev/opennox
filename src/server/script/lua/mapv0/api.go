package mapv0

import (
	"fmt"

	lua "github.com/yuin/gopher-lua"

	"nox/v1/server/script"
)

func New(vm *lua.LState, tm *script.Timers, g script.Game) *lua.LTable {
	a := &api{
		s: vm, g: g, tm: tm,
		root: vm.NewTable(),
	}
	a.initMeta()
	a.init()
	return a.root
}

type api struct {
	g    script.Game
	tm   *script.Timers
	s    *lua.LState
	root *lua.LTable
	meta struct {
		metaWaypoint
		metaWall
		metaObject
		metaUnit
		metaPlayer
		metaTimer
	}
}

func (vm *api) newMeta(key string) *lua.LTable {
	t := vm.s.NewTable()
	t.Metatable = t
	if key != "" {
		vm.root.RawSetString(key, t)
	}
	return t
}

func (vm *api) initMeta() {
	vm.initMetaWaypoint()
	vm.initMetaWall()
	vm.initMetaObject()
	vm.initMetaUnit()
	vm.initMetaPlayer()
	vm.initMetaTimer()
}

func (vm *api) init() {
	vm.initWaypoint()
	vm.initWall()
	vm.initWallGroup()
	vm.initObject()
	vm.initObjectGroup()
	vm.initObjectType()
	vm.initUnit()
	vm.initPlayer()
	vm.initTimer()
}

func (vm *api) setIndexFunction(meta *lua.LTable, fnc func(val interface{}, key string) (lua.LValue, bool)) {
	// Node[key]
	meta.RawSetString("__index", vm.s.NewFunction(func(s *lua.LState) int {
		val := s.CheckUserData(1).Value
		key := s.CheckString(2)
		// automatically handle accesses for well-known interfaces
		if v, ok := vm.indexInterfaceV0(val, key); ok {
			s.Push(v)
			return 1
		}
		if fnc != nil {
			// custom fields for specific types
			if v, ok := fnc(val, key); ok {
				if v == nil {
					s.Push(lua.LNil)
				} else {
					s.Push(v)
				}
				return 1
			}
		}
		// fallback to the metatable (e.g. class methods)
		s.Push(s.RawGet(meta, lua.LString(key)))
		return 1
	}))
}

func (vm *api) setSetIndexFunction(meta *lua.LTable, fnc func(obj interface{}, key string, val lua.LValue) bool) {
	meta.RawSetString("__newindex", vm.s.NewFunction(func(s *lua.LState) int {
		obj := s.CheckUserData(1).Value
		key := s.CheckString(2)
		if vm.setindexInterfaceV0(s, obj, key) {
			return 0
		}
		if fnc != nil {
			if fnc(obj, key, s.Get(3)) {
				return 0
			}
		}
		s.ArgError(2, fmt.Sprintf("no such key: %q", key))
		return 0
	}))
}
