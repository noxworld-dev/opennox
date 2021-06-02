package mapv0

import (
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
	if list := v.Objects(); script.IsAllUnits(list) {
		units := make([]script.Unit, 0, len(list))
		for _, obj := range list {
			units = append(units, obj.(script.Unit))
		}
		v := script.NewUnitGroup(v.ID(), units...)
		return vm.newUnitGroup(v)
	}
	return vm.newObjectGroupRaw(v)
}

func (vm *api) newObjectGroupRaw(v *script.ObjectGroup) lua.LValue {
	if v == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: v, Metatable: vm.meta.ObjectGroup}
}

func (vm *api) initMetaObject() {
	vm.meta.ObjectType = vm.newMeta("ObjectType")
	vm.meta.Object = vm.newMeta("Object")
	vm.meta.ObjectGroup = vm.newMeta("ObjectGroup")

	vm.registerObjMethod("Pos", func(obj script.Positioner) (x, y float32) {
		pos := obj.Pos()
		return pos.X, pos.Y
	})
	vm.registerObjMethod("SetPos", func(obj script.PositionSetter, to types.Pointf) (_ receiverValue) {
		obj.SetPos(to)
		return
	})
	vm.registerObjMethod("DistanceTo", func(obj script.Positioner, to types.Pointf) float32 {
		return float32(obj.Pos().Sub(to).Len())
	})
	vm.registerObjMethod("SetOwner", func(obj script.OwnerSetter, owner script.ObjectWrapper) (_ receiverValue) {
		obj.SetOwner(owner)
		return
	})
	vm.registerObjMethod("PushTo", func(obj script.Pushable, to types.Pointf) (_ receiverValue) {
		obj.PushTo(to)
		return
	})
	vm.registerObjMethod("Push", func(obj script.Pushable, vec types.Pointf, force float32) (_ receiverValue) {
		obj.Push(vec, force)
		return
	})
	vm.registerObjMethod("Delete", func(obj script.Deleter) {
		obj.Delete()
	})
	vm.registerObjMethod("Destroy", func(obj script.Destroyable) {
		obj.Destroy()
	})
	vm.registerObjMethod("Break", func(obj script.Destroyable) {
		obj.Destroy()
	})
	vm.registerObjMethod("Kill", func(obj script.Destroyable) {
		obj.Destroy()
	})
	vm.registerObjMethod("Toggle", func(val interface{}) {
		switch val := val.(type) {
		case script.Toggler:
			val.Toggle()
		case script.Enabler:
			script.Toggle(val)
		default:
			// TODO: allow registering methods with the same name on different types?
			panic("cannot toggle")
		}
	})
}

func (vm *api) initObjectType() {
	// ObjectType(id string)
	vm.meta.ObjectType.RawSetString("__call", vm.s.NewFunction(func(s *lua.LState) int {
		id := s.CheckString(2)
		typ := vm.g.ObjectTypeByID(id)
		s.Push(vm.newObjectType(typ))
		return 1
	}))
	// ObjectType[key]
	vm.setIndexFunction(vm.meta.ObjectType, nil)
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
	// Object(id string)
	vm.meta.Object.RawSetString("__call", vm.s.NewFunction(func(s *lua.LState) int {
		id := s.CheckString(2)
		obj := vm.g.ObjectByID(id)
		s.Push(vm.newObject(obj))
		return 1
	}))
	// Object[key] expects only Object this time
	vm.setIndexFunction(vm.meta.Object, func(val interface{}, key string) (lua.LValue, bool) {
		obj, ok := val.(script.Object)
		if !ok {
			return nil, false
		}
		switch key {
		case "type":
			typ := obj.ObjectType()
			return vm.newObjectType(typ), true
		}
		return nil, false
	})
	// Object[key] = v
	vm.setSetIndexFunction(vm.meta.Object, nil)
}

func (vm *api) initObjectGroup() {
	// ObjectGroup(id string)
	vm.meta.ObjectGroup.RawSetString("__call", vm.s.NewFunction(func(s *lua.LState) int {
		switch s.Get(2).(type) {
		case lua.LString:
			// get by ID
			id := s.CheckString(2)
			g := vm.g.ObjectGroupByID(id)
			s.Push(vm.newObjectGroup(g))
			return 1
		}
		// create a new group
		var (
			objs  []script.Object
			units []script.Unit
		)
		for i := 2; i <= s.GetTop(); i++ {
			obj, ok := s.CheckUserData(i).Value.(script.Object)
			if !ok {
				return 0
			}
			if u, ok := obj.(script.Unit); ok {
				units = append(units, u)
			}
			objs = append(objs, obj)
		}
		var lv lua.LValue
		if len(units) == len(objs) {
			g := script.NewUnitGroup("", units...)
			lv = vm.newUnitGroup(g)
		} else {
			g := script.NewObjectGroup("", objs...)
			lv = vm.newObjectGroupRaw(g)
		}
		s.Push(lv)
		return 1
	}))
	// ObjectGroup[key]
	vm.setIndexFunction(vm.meta.ObjectGroup, nil)
	// ObjectGroup[key] = v
	vm.setSetIndexFunction(vm.meta.ObjectGroup, nil)
}
