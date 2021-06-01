package mapv0

import (
	lua "github.com/yuin/gopher-lua"

	"nox/v1/server/script"
)

func (vm *api) indexInterfaceV0(val interface{}, key string) (lua.LValue, bool) {
	switch key {
	case "id":
		obj, ok := val.(script.Identifiable)
		if !ok {
			return nil, false
		}
		id := obj.ID()
		return lua.LString(id), true
	case "x":
		obj, ok := val.(script.Positioner)
		if !ok {
			return nil, false
		}
		v := obj.Pos().X
		return lua.LNumber(v), true
	case "y":
		obj, ok := val.(script.Positioner)
		if !ok {
			return nil, false
		}
		v := obj.Pos().Y
		return lua.LNumber(v), true
	case "z":
		obj, ok := val.(script.Raisable)
		if !ok {
			return nil, false
		}
		v := obj.Z()
		return lua.LNumber(v), true
	case "xi":
		obj, ok := val.(script.GridPositioner)
		if !ok {
			return nil, false
		}
		v := obj.GridPos().X
		return lua.LNumber(v), true
	case "yi":
		obj, ok := val.(script.GridPositioner)
		if !ok {
			return nil, false
		}
		v := obj.GridPos().Y
		return lua.LNumber(v), true
	case "owner":
		obj, ok := val.(script.Owned)
		if !ok {
			return nil, false
		}
		v := obj.Owner()
		return vm.newObject(v), true
	case "enabled":
		obj, ok := val.(script.Enabler)
		if !ok {
			return nil, false
		}
		v := obj.IsEnabled()
		return lua.LBool(v), true
	case "health":
		obj, ok := val.(script.Breakable)
		if !ok {
			return nil, false
		}
		v, _ := obj.Health()
		return lua.LNumber(v), true
	case "max_health":
		obj, ok := val.(script.Breakable)
		if !ok {
			return nil, false
		}
		_, v := obj.Health()
		return lua.LNumber(v), true
	case "mana":
		obj, ok := val.(script.Living)
		if !ok {
			return nil, false
		}
		v, _ := obj.Mana()
		return lua.LNumber(v), true
	case "max_mana":
		obj, ok := val.(script.Living)
		if !ok {
			return nil, false
		}
		_, v := obj.Mana()
		return lua.LNumber(v), true
	case "aggression":
		obj, ok := val.(script.Offensive)
		if !ok {
			return nil, false
		}
		v := obj.Aggression()
		return lua.LNumber(v), true
	case "retreat":
		obj, ok := val.(script.Offensive)
		if !ok {
			return nil, false
		}
		v := obj.RetreatLevel()
		return lua.LNumber(v), true
	case "regroup":
		obj, ok := val.(script.Offensive)
		if !ok {
			return nil, false
		}
		v := obj.RegroupLevel()
		return lua.LNumber(v), true
	default:
		return nil, false
	}
}

func (vm *api) setindexInterfaceV0(s *lua.LState, val interface{}, key string) bool {
	switch key {
	case "x":
		obj, ok := val.(script.Positionable)
		if !ok {
			return false
		}
		v := float32(s.CheckNumber(3))
		p := obj.Pos()
		p.X = v
		obj.SetPos(p)
		return true
	case "y":
		obj, ok := val.(script.Positionable)
		if !ok {
			return false
		}
		v := float32(s.CheckNumber(3))
		p := obj.Pos()
		p.Y = v
		obj.SetPos(p)
		return true
	case "z":
		obj, ok := val.(script.Raisable)
		if !ok {
			return false
		}
		v := float32(s.CheckNumber(3))
		obj.SetZ(v)
		return true
	case "owner":
		obj, ok := val.(script.OwnerSetter)
		if !ok {
			return false
		}
		var v script.ObjectWrapper
		if s.Get(3) != lua.LNil {
			v = s.CheckUserData(3).Value.(script.ObjectWrapper)
		}
		obj.SetOwner(v)
		return true
	case "enabled":
		obj, ok := val.(script.EnableSetter)
		if !ok {
			return false
		}
		v := s.CheckBool(3)
		obj.Enable(v)
		return true
	case "health":
		obj, ok := val.(script.Breakable)
		if !ok {
			return false
		}
		v := int(s.CheckNumber(3))
		obj.SetHealth(v)
		return true
	case "max_health":
		obj, ok := val.(script.Breakable)
		if !ok {
			return false
		}
		v := int(s.CheckNumber(3))
		obj.SetMaxHealth(v)
		return true
	case "mana":
		obj, ok := val.(script.Living)
		if !ok {
			return false
		}
		v := int(s.CheckNumber(3))
		obj.SetMana(v)
		return true
	case "max_mana":
		obj, ok := val.(script.Living)
		if !ok {
			return false
		}
		v := int(s.CheckNumber(3))
		obj.SetMaxMana(v)
		return true
	case "aggression":
		obj, ok := val.(script.Offensive)
		if !ok {
			return false
		}
		v := float32(s.CheckNumber(3))
		obj.SetAggression(v)
		return true
	case "retreat":
		obj, ok := val.(script.Offensive)
		if !ok {
			return false
		}
		v := float32(s.CheckNumber(3))
		obj.SetRetreatLevel(v)
		return true
	case "regroup":
		obj, ok := val.(script.Offensive)
		if !ok {
			return false
		}
		v := float32(s.CheckNumber(3))
		obj.SetRegroupLevel(v)
		return true
	default:
		return false
	}
}
