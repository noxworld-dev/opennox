package mapv0

import (
	"fmt"

	lua "github.com/yuin/gopher-lua"

	"nox/v1/server/script"
)

type metaPlayer struct {
	Player  *lua.LTable
	Players *lua.LTable
}

func (vm *api) newPlayer(obj script.Player) lua.LValue {
	if obj == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: obj, Metatable: vm.meta.Player}
}

func (vm *api) initMetaPlayer() {
	vm.meta.Player = vm.newMeta("")
	vm.meta.Players = vm.newMeta("Players")
}

func (vm *api) initPlayer() {
	// Nox.Players()
	vm.meta.Players.RawSetString("__call", vm.s.NewFunction(func(s *lua.LState) int {
		t := vm.s.NewTable()
		for i, p := range vm.g.Players() {
			t.RawSetInt(i+1, vm.newPlayer(p))
		}
		s.Push(t)
		return 1
	}))
	// Nox.Players[1]
	vm.meta.Players.RawSetString("__index", vm.s.NewFunction(func(s *lua.LState) int {
		switch key := s.Get(2).(type) {
		case lua.LNumber:
			i := int(key)
			if i <= 0 {
				s.Push(lua.LNil)
				return 1
			}
			i-- // LUA indexes start from 1
			list := vm.g.Players()
			if i >= len(list) {
				s.Push(lua.LNil)
				return 1
			}
			s.Push(vm.newPlayer(list[i]))
			return 1
		case lua.LString:
			s.Push(s.RawGet(vm.meta.Players, key))
			return 1
		default:
			s.Push(lua.LNil)
			return 1
		}
	}))
	// Nox.Players.Print("text")
	vm.meta.Players.RawSetString("Print", vm.s.NewFunction(func(s *lua.LState) int {
		text := s.CheckString(1)
		vm.g.Global().Print(text)
		return 0
	}))
	// Nox.Players.Blind(true)
	vm.meta.Players.RawSetString("Blind", vm.s.NewFunction(func(s *lua.LState) int {
		blind := s.OptBool(1, true)
		vm.g.BlindPlayers(blind)
		return 1
	}))
	// Nox.Players.Cinema(100)
	vm.meta.Players.RawSetString("Cinema", vm.s.NewFunction(func(s *lua.LState) int {
		v := s.OptInt(1, 100) // TODO: check exact magnitude
		vm.g.CinemaPlayers(v)
		return 1
	}))

	// print(Player)
	vm.meta.Player.RawSetString("__tostring", vm.s.NewFunction(func(s *lua.LState) int {
		p, ok := s.CheckUserData(1).Value.(script.Player)
		if !ok {
			return 0
		}
		str := fmt.Sprintf("Player(%q)", p.Name())
		s.Push(lua.LString(str))
		return 1
	}))
	// Player[key]
	vm.setIndexFunction(vm.meta.Player, func(val interface{}, key string) (lua.LValue, bool) {
		p, ok := val.(script.Player)
		if !ok {
			return nil, false
		}
		switch key {
		case "name":
			id := p.Name()
			return lua.LString(id), true
		case "host":
			host := p.IsHost()
			return lua.LBool(host), true
		case "unit":
			u := p.Unit()
			return vm.newUnit(u), true
		}
		return nil, false
	})
	// Player[key] = v
	vm.meta.Player.RawSetString("__newindex", vm.s.NewFunction(func(s *lua.LState) int {
		val := s.CheckUserData(1).Value
		key := s.CheckString(2)
		if vm.setindexInterfaceV0(s, val, key) {
			return 0
		}
		p, ok := val.(script.Player)
		if !ok {
			return 0
		}
		_ = p
		switch key {
		default:
			s.ArgError(2, fmt.Sprintf("no such key: %q", key))
			return 0
		}
	}))
	// Player:Print("text")
	vm.meta.Player.RawSetString("Print", vm.s.NewFunction(func(s *lua.LState) int {
		p, ok := s.CheckUserData(1).Value.(script.Player)
		if !ok {
			return 0
		}
		text := s.CheckString(2)
		p.Print(text)
		return 0
	}))
	// Player:Blind(true)
	vm.meta.Player.RawSetString("Blind", vm.s.NewFunction(func(s *lua.LState) int {
		p, ok := s.CheckUserData(1).Value.(script.Player)
		if !ok {
			return 0
		}
		blind := s.OptBool(2, true)
		p.Blind(blind)
		return 0
	}))
	// Player:Cinema(100)
	vm.meta.Player.RawSetString("Cinema", vm.s.NewFunction(func(s *lua.LState) int {
		p, ok := s.CheckUserData(1).Value.(script.Player)
		if !ok {
			return 0
		}
		v := s.OptInt(2, 100) // TODO: check exact magnitude
		p.Cinema(v)
		return 1
	}))
	vm.registerPositionerV0(vm.meta.Player)
	vm.registerMoverV0(vm.meta.Player)
}
