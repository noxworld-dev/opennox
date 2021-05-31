package mapv0

import (
	lua "github.com/yuin/gopher-lua"

	"nox/v1/common/types"
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

func (vm *api) registerMobileV0(meta *lua.LTable) {
	// Object:Freeze()
	meta.RawSetString("Freeze", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Mobile)
		if !ok {
			return 0
		}
		freeze := s.OptBool(2, true)
		obj.Freeze(freeze)
		s.Push(s.Get(1))
		return 1
	}))
	// Object:Wander()
	meta.RawSetString("Wander", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Mobile)
		if !ok {
			return 0
		}
		obj.Wander()
		s.Push(s.Get(1))
		return 1
	}))
	// Object:Return()
	meta.RawSetString("Return", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Mobile)
		if !ok {
			return 0
		}
		obj.Return()
		s.Push(s.Get(1))
		return 1
	}))
	// Object:Idle()
	meta.RawSetString("Idle", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Mobile)
		if !ok {
			return 0
		}
		obj.Idle()
		s.Push(s.Get(1))
		return 1
	}))
	// Object:LookAt(p Object) Object
	// Object:LookAt(p Waypoint) Object
	// Object:LookAt(x, y number) Object
	meta.RawSetString("LookAt", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Mobile)
		if !ok {
			return 0
		}
		switch s.Get(2).(type) {
		case lua.LNumber:
			x := s.CheckNumber(2)
			y := s.CheckNumber(3)
			obj.LookAt(types.Pointf{X: float32(x), Y: float32(y)})
			s.Push(s.Get(1))
			return 1
		default:
			pos, ok := s.CheckUserData(2).Value.(script.Positioner)
			if !ok {
				return 0
			}
			script.LookAtPos(obj, pos)
			s.Push(s.Get(1))
			return 1
		}
	}))
	// Object:WalkTo(p Object) Object
	// Object:WalkTo(p Waypoint) Object
	// Object:WalkTo(x, y number) Object
	meta.RawSetString("WalkTo", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Mobile)
		if !ok {
			return 0
		}
		switch s.Get(2).(type) {
		case lua.LNumber:
			x := s.CheckNumber(2)
			y := s.CheckNumber(3)
			obj.WalkTo(types.Pointf{X: float32(x), Y: float32(y)})
			s.Push(s.Get(1))
			return 1
		default:
			pos, ok := s.CheckUserData(2).Value.(script.Positioner)
			if !ok {
				return 0
			}
			script.WalkToPos(obj, pos)
			s.Push(s.Get(1))
			return 1
		}
	}))
	// Object:LookAtDir(dir number)
	meta.RawSetString("LookAtDir", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Mobile)
		if !ok {
			return 0
		}
		dir := int(s.CheckNumber(2))
		obj.LookAtDir(dir)
		s.Push(s.Get(1))
		return 1
	}))
	// Object:LookAngle(ang number)
	meta.RawSetString("LookAngle", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Mobile)
		if !ok {
			return 0
		}
		dir := int(s.CheckNumber(2))
		obj.LookAngle(dir)
		s.Push(s.Get(1))
		return 1
	}))
	// Object:Follow(obj Object)
	meta.RawSetString("Follow", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Mobile)
		if !ok {
			return 0
		}
		obj2, ok := s.CheckUserData(2).Value.(script.Positioner)
		if !ok {
			return 0
		}
		obj.Follow(obj2)
		s.Push(s.Get(1))
		return 1
	}))
	// Object:Flee(obj Object, dur Duration)
	meta.RawSetString("Flee", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Mobile)
		if !ok {
			return 0
		}
		obj2, ok := s.CheckUserData(2).Value.(script.Positioner)
		if !ok {
			return 0
		}
		a3 := s.OptUserData(3, nil)
		var dur script.Duration
		if a3 != nil {
			dur, _ = a3.Value.(script.Duration)
		}
		obj.Flee(obj2, dur)
		s.Push(s.Get(1))
		return 1
	}))
}

func (vm *api) registerOffensiveGroupV0(meta *lua.LTable) {
	// Object:Attack(obj Object)
	meta.RawSetString("Attack", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.OffensiveGroup)
		if !ok {
			return 0
		}
		obj2, ok := s.CheckUserData(2).Value.(script.Positioner)
		if !ok {
			return 0
		}
		obj.Attack(obj2)
		s.Push(s.Get(1))
		return 1
	}))
	// Object:HitMelee(obj Object)
	// Object:HitMelee(x, y number)
	meta.RawSetString("HitMelee", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.OffensiveGroup)
		if !ok {
			return 0
		}
		switch s.Get(2).(type) {
		case lua.LNumber:
			x := float32(s.CheckNumber(2))
			y := float32(s.CheckNumber(3))
			obj.HitMelee(types.Pointf{X: x, Y: y})
		default:
			obj2, ok := s.CheckUserData(2).Value.(script.Positioner)
			if !ok {
				return 0
			}
			script.HitMeleePos(obj, obj2)
		}
		s.Push(s.Get(1))
		return 1
	}))
	// Object:HitRanged(obj Object)
	// Object:HitRanged(x, y number)
	meta.RawSetString("HitRanged", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.OffensiveGroup)
		if !ok {
			return 0
		}
		switch s.Get(2).(type) {
		case lua.LNumber:
			x := float32(s.CheckNumber(2))
			y := float32(s.CheckNumber(3))
			obj.HitRanged(types.Pointf{X: x, Y: y})
		default:
			obj2, ok := s.CheckUserData(2).Value.(script.Positioner)
			if !ok {
				return 0
			}
			script.HitRangedPos(obj, obj2)
		}
		s.Push(s.Get(1))
		return 1
	}))
	// Object:Guard()
	meta.RawSetString("Guard", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.OffensiveGroup)
		if !ok {
			return 0
		}
		obj.Guard()
		s.Push(s.Get(1))
		return 1
	}))
	// Object:Hunt()
	meta.RawSetString("Hunt", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.OffensiveGroup)
		if !ok {
			return 0
		}
		obj.Hunt()
		s.Push(s.Get(1))
		return 1
	}))
}

func (vm *api) registerChattyV0(meta *lua.LTable) {
	// Object:Say(text string, dur Duration)
	meta.RawSetString("Say", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Chatty)
		if !ok {
			return 0
		}
		text := s.CheckString(2)
		a3 := s.OptUserData(3, nil)
		var dur script.Duration
		if a3 != nil {
			dur, _ = a3.Value.(script.Duration)
		}
		obj.Say(text, dur)
		s.Push(s.Get(1))
		return 1
	}))
	// Object:Mute()
	meta.RawSetString("Mute", vm.s.NewFunction(func(s *lua.LState) int {
		obj, ok := s.CheckUserData(1).Value.(script.Chatty)
		if !ok {
			return 0
		}
		obj.Mute()
		s.Push(s.Get(1))
		return 1
	}))
}
