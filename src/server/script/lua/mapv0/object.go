package mapv0

import (
	"fmt"

	lua "github.com/yuin/gopher-lua"

	"nox/v1/common/types"
	"nox/v1/server/script"
)

type metaObject struct {
	Object      *lua.LTable
	ObjectType  *lua.LTable
	ObjectGroup *lua.LTable
}

func (vm *api) newObject(obj script.Object) lua.LValue {
	if obj == nil {
		return lua.LNil
	}
	switch obj := obj.(type) {
	case script.Unit:
		return vm.newUnit(obj)
	}
	return &lua.LUserData{Value: obj, Metatable: vm.meta.Object}
}

func (vm *api) newObjectType(typ script.ObjectType) lua.LValue {
	if typ == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: typ, Metatable: vm.meta.ObjectType}
}

func (vm *api) newObjectGroup(v *script.ObjectGroup) lua.LValue {
	if v == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: v, Metatable: vm.meta.ObjectGroup}
}

func (vm *api) initMetaObject() {
	vm.meta.Object = vm.newMeta("Object")
	vm.meta.ObjectGroup = vm.newMeta("ObjectGroup")
	vm.meta.ObjectType = vm.newMeta("")
}

func (vm *api) initObjectType() {
	// print(ObjectType)
	vm.meta.ObjectType.RawSetString("__tostring", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.ObjectType)
		if !ok {
			return 0
		}
		str := "ObjectType(" + obj.ID() + ")"
		s.Push(lua.LString(str))
		return 1
	}))
	// ObjectType[key] expects only Object this time
	vm.meta.ObjectType.RawSetString("__index", vm.s.NewFunction(func(s *lua.LState) int {
		key := s.CheckString(2)
		switch key {
		default:
			s.Push(s.RawGet(vm.meta.ObjectType, lua.LString(key)))
			return 1
		}
	}))
	// ObjectType:Create(p Waypoint)
	// ObjectType:Create(x, y number)
	vm.meta.ObjectType.RawSetString("Create", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.ObjectType)
		if !ok {
			return 0
		}
		var pos types.Pointf
		switch s.Get(2).(type) {
		case lua.LNumber:
			x := float32(s.CheckNumber(2))
			y := float32(s.CheckNumber(3))
			pos = types.Pointf{X: x, Y: y}
		default:
			obj2, ok := s.CheckUserData(2).Value.(script.Positioner)
			if !ok {
				return 0
			}
			pos = obj2.Pos()
		}
		val := obj.CreateObject(pos)
		s.Push(vm.newObject(val))
		return 1
	}))
}

func (vm *api) initObject() {
	// print(Object)
	vm.meta.Object.RawSetString("__tostring", vm.s.NewFunction(func(s *lua.LState) int {
		self := s.Get(1)
		var str string
		if self == vm.meta.Object {
			str = "Object"
		} else {
			obj, ok := s.CheckUserData(1).Value.(script.Object)
			if !ok {
				return 0
			}
			str = "Object(" + obj.ID() + ")"
		}
		s.Push(lua.LString(str))
		return 1
	}))
	// Object(id string) acts as a constructor for both Object and ObjectType
	vm.meta.Object.RawSetString("__call", vm.s.NewFunction(func(s *lua.LState) int {
		id := s.CheckString(2)
		var lv lua.LValue
		if typ := vm.g.ObjectTypeByID(id); typ != nil {
			lv = vm.newObjectType(typ)
		} else if obj := vm.g.ObjectByID(id); obj != nil {
			lv = vm.newObject(obj)
		} else {
			lv = lua.LNil
		}
		s.Push(lv)
		return 1
	}))
	// Object[key] expects only Object this time
	vm.meta.Object.RawSetString("__index", vm.s.NewFunction(func(s *lua.LState) int {
		val := s.CheckUserData(1).Value
		key := s.CheckString(2)
		if v, ok := vm.indexInterfaceV0(val, key); ok {
			s.Push(v)
			return 1
		}
		obj, ok := val.(script.Object)
		if !ok {
			return 0
		}
		switch key {
		case "type":
			typ := obj.ObjectType()
			s.Push(vm.newObjectType(typ))
			return 1
		default:
			s.Push(s.RawGet(vm.meta.Object, lua.LString(key)))
			return 1
		}
	}))
	// Object[key] = v
	vm.meta.Object.RawSetString("__newindex", vm.s.NewFunction(func(s *lua.LState) int {
		val := s.CheckUserData(1).Value
		key := s.CheckString(2)
		if vm.setindexInterfaceV0(s, val, key) {
			return 0
		}
		obj, ok := val.(script.Object)
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
	vm.registerDeleterV0(vm.meta.Object)
	vm.registerPositionerV0(vm.meta.Object)
	vm.registerMoverV0(vm.meta.Object)
	vm.registerTogglerV0(vm.meta.Object)
}

func (vm *api) initObjectGroup() {
	// print(ObjectGroup)
	vm.meta.ObjectGroup.RawSetString("__tostring", vm.s.NewFunction(func(s *lua.LState) int {
		g, ok := s.CheckUserData(1).Value.(*script.ObjectGroup)
		if !ok {
			return 0
		}
		var str string
		if id := g.ID(); id != "" {
			str = fmt.Sprintf("ObjectGroup(%s)", id)
		} else {
			str = fmt.Sprintf("ObjectGroup(%d)", len(g.Objects()))
		}
		s.Push(lua.LString(str))
		return 1
	}))
	// ObjectGroup(id string)
	vm.meta.ObjectGroup.RawSetString("__call", vm.s.NewFunction(func(s *lua.LState) int {
		id := s.CheckString(2)
		g := vm.g.ObjectGroupByID(id)
		s.Push(vm.newObjectGroup(g))
		return 1
	}))
	// ObjectGroup[key]
	vm.meta.ObjectGroup.RawSetString("__index", vm.s.NewFunction(func(s *lua.LState) int {
		val := s.CheckUserData(1).Value
		key := s.CheckString(2)
		if v, ok := vm.indexInterfaceV0(val, key); ok {
			s.Push(v)
			return 1
		}
		obj, ok := val.(*script.ObjectGroup)
		if !ok {
			return 0
		}
		_ = obj
		switch key {
		default:
			s.Push(s.RawGet(vm.meta.Object, lua.LString(key)))
			return 1
		}
	}))
	// ObjectGroup[key] = v
	vm.meta.ObjectGroup.RawSetString("__newindex", vm.s.NewFunction(func(s *lua.LState) int {
		val := s.CheckUserData(1).Value
		key := s.CheckString(2)
		if vm.setindexInterfaceV0(s, val, key) {
			return 0
		}
		obj, ok := val.(*script.ObjectGroup)
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
	vm.registerDeleterV0(vm.meta.ObjectGroup)
	vm.registerMoverV0(vm.meta.ObjectGroup)
	vm.registerTogglerV0(vm.meta.ObjectGroup)
}
