package mapv0

import (
	"fmt"

	lua "github.com/yuin/gopher-lua"

	"nox/v1/common/types"
	"nox/v1/server/script"
)

type metaWall struct {
	Wall      *lua.LTable
	WallGroup *lua.LTable
}

func (vm *api) newWall(v script.Wall) lua.LValue {
	if v == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: v, Metatable: vm.meta.Wall}
}

func (vm *api) newWallGroup(v *script.WallGroup) lua.LValue {
	if v == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: v, Metatable: vm.meta.WallGroup}
}

func (vm *api) initMetaWall() {
	vm.meta.Wall = vm.newMeta("Wall")
	vm.meta.WallGroup = vm.newMeta("WallGroup")
}

func (vm *api) initWall() {
	// print(Wall)
	vm.meta.Wall.RawSetString("__tostring", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Wall)
		if !ok {
			return 0
		}
		pos := obj.GridPos()
		str := fmt.Sprintf("Wall(%d, %d)", pos.X, pos.Y)
		s.Push(lua.LString(str))
		return 1
	}))
	// Wall(x, y number)
	vm.meta.Wall.RawSetString("__call", vm.s.NewFunction(func(s *lua.LState) int {
		x := int(s.CheckNumber(2))
		y := int(s.CheckNumber(3))
		wl := vm.g.WallAtGrid(types.Point{X: x, Y: y})
		s.Push(vm.newWall(wl))
		return 1
	}))
	// Nox.WallAt(obj Object)
	// Nox.WallAt(x, y number)
	vm.root.RawSetString("WallAt", vm.s.NewFunction(func(s *lua.LState) int {
		var wl script.Wall
		switch s.Get(1).(type) {
		case lua.LNumber:
			x := float32(s.CheckNumber(1))
			y := float32(s.CheckNumber(2))
			wl = vm.g.WallAt(types.Pointf{X: x, Y: y})
		default:
			obj2, ok := s.CheckUserData(1).Value.(script.Positioner)
			if !ok {
				return 0
			}
			wl = vm.g.WallAt(obj2.Pos())
		}
		s.Push(vm.newWall(wl))
		return 1
	}))
	// Nox.WallNear(obj Object)
	// Nox.WallNear(x, y number)
	vm.root.RawSetString("WallNear", vm.s.NewFunction(func(s *lua.LState) int {
		var wl script.Wall
		switch s.Get(1).(type) {
		case lua.LNumber:
			x := float32(s.CheckNumber(1))
			y := float32(s.CheckNumber(2))
			wl = vm.g.WallNear(types.Pointf{X: x, Y: y})
		default:
			obj2, ok := s.CheckUserData(1).Value.(script.Positioner)
			if !ok {
				return 0
			}
			wl = vm.g.WallNear(obj2.Pos())
		}
		s.Push(vm.newWall(wl))
		return 1
	}))
	// Wall[key]
	vm.setIndexFunction(vm.meta.Wall, nil)
	// Wall[key] = v
	vm.meta.Wall.RawSetString("__newindex", vm.s.NewFunction(func(s *lua.LState) int {
		val := s.CheckUserData(1).Value
		key := s.CheckString(2)
		if vm.setindexInterfaceV0(s, val, key) {
			return 0
		}
		obj, ok := val.(script.Wall)
		if !ok {
			return 0
		}
		_ = obj
		switch key {
		default:
			s.ArgError(2, fmt.Sprintf("no such key: %q", key))
			return 0
		}
	}))
	// Wall:Break()
	vm.meta.Wall.RawSetString("Break", vm.s.NewFunction(func(s *lua.LState) int {
		wl, ok := s.CheckUserData(1).Value.(script.Wall)
		if !ok {
			return 0
		}
		wl.Break()
		return 0
	}))
	vm.registerPositionerV0(vm.meta.Wall)
	vm.registerGridPositionerV0(vm.meta.Wall)
	vm.registerTogglerV0(vm.meta.Wall)
}

func (vm *api) initWallGroup() {
	// print(WallGroup)
	vm.meta.WallGroup.RawSetString("__tostring", vm.s.NewFunction(func(s *lua.LState) int {
		g, ok := s.CheckUserData(1).Value.(*script.WallGroup)
		if !ok {
			return 0
		}
		var str string
		if id := g.ID(); id != "" {
			str = fmt.Sprintf("WallGroup(%s)", id)
		} else {
			str = fmt.Sprintf("WallGroup(%d)", len(g.Walls()))
		}
		s.Push(lua.LString(str))
		return 1
	}))
	// WallGroup(id string)
	vm.meta.WallGroup.RawSetString("__call", vm.s.NewFunction(func(s *lua.LState) int {
		id := s.CheckString(2)
		g := vm.g.WallGroupByID(id)
		s.Push(vm.newWallGroup(g))
		return 1
	}))
	// WallGroup[key]
	vm.meta.WallGroup.RawSetString("__index", vm.s.NewFunction(func(s *lua.LState) int {
		val := s.CheckUserData(1).Value
		switch s.Get(2).(type) {
		case lua.LNumber:
			i := int(s.CheckNumber(2))
			if i <= 0 {
				return 0
			}
			i--
			obj, ok := val.(*script.WallGroup)
			if !ok {
				return 0
			}
			list := obj.Walls()
			if i >= len(list) {
				return 0
			}
			w := list[i]
			s.Push(vm.newWall(w))
			return 1
		default:
		}
		key := s.CheckString(2)
		if v, ok := vm.indexInterfaceV0(val, key); ok {
			s.Push(v)
			return 1
		}
		obj, ok := val.(*script.WallGroup)
		if !ok {
			return 0
		}
		_ = obj
		switch key {
		default:
			s.Push(s.RawGet(vm.meta.WallGroup, lua.LString(key)))
			return 1
		}
	}))
	// WallGroup[key] = v
	vm.meta.WallGroup.RawSetString("__newindex", vm.s.NewFunction(func(s *lua.LState) int {
		val := s.CheckUserData(1).Value
		key := s.CheckString(2)
		if vm.setindexInterfaceV0(s, val, key) {
			return 0
		}
		obj, ok := val.(*script.WallGroup)
		if !ok {
			return 0
		}
		_ = obj
		switch key {
		default:
			s.ArgError(2, fmt.Sprintf("no such key: %q", key))
			return 0
		}
	}))
	// WallGroup:Break()
	vm.meta.WallGroup.RawSetString("Break", vm.s.NewFunction(func(s *lua.LState) int {
		wl, ok := s.CheckUserData(1).Value.(*script.WallGroup)
		if !ok {
			return 0
		}
		wl.Break()
		return 0
	}))
	vm.registerTogglerV0(vm.meta.WallGroup)
}
