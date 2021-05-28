package mapv0

import (
	"time"

	lua "github.com/yuin/gopher-lua"

	"nox/v1/server/script"
)

type metaTimer struct {
	Timer *lua.LTable
	Dur   *lua.LTable
}

func (vm *api) newTimer(v *script.Timer) lua.LValue {
	if v == nil {
		return lua.LNil
	}
	return &lua.LUserData{Value: v, Metatable: vm.meta.Timer}
}

func (vm *api) newDuration(d script.Duration) lua.LValue {
	return &lua.LUserData{Value: d, Metatable: vm.meta.Dur}
}

func (vm *api) initMetaTimer() {
	vm.meta.Timer = vm.newMeta("")
	vm.meta.Dur = vm.newMeta("")
}

func (vm *api) initTimer() {
	// Nox.Sec(sec number)
	vm.root.RawSetString("Sec", vm.s.NewFunction(func(s *lua.LState) int {
		v := s.CheckNumber(1)
		dt := time.Duration(float64(v) * float64(time.Second))
		s.Push(vm.newDuration(script.Time(dt)))
		return 1
	}))
	// Nox.Frames(frames number)
	vm.root.RawSetString("Frames", vm.s.NewFunction(func(s *lua.LState) int {
		v := int(s.CheckNumber(1))
		s.Push(vm.newDuration(script.Frames(v)))
		return 1
	}))
	// Nox.Timer(dur, fnc)
	vm.root.RawSetString("Timer", vm.s.NewFunction(func(s *lua.LState) int {
		dur, ok := s.CheckUserData(1).Value.(script.Duration)
		if !ok {
			return 0
		}
		fnc := s.CheckFunction(2)
		t := vm.tm.SetTimer(dur, func() {
			vm.s.Push(fnc)
			_ = vm.s.PCall(0, 0, nil)
		})
		s.Push(vm.newTimer(t))
		return 1
	}))
	// Nox.FrameTimer(frames, fnc)
	vm.root.RawSetString("FrameTimer", vm.s.NewFunction(func(s *lua.LState) int {
		v := int(s.CheckNumber(1))
		fnc := s.CheckFunction(2)
		t := vm.tm.SetTimer(script.Frames(v), func() {
			vm.s.Push(fnc)
			_ = vm.s.PCall(0, 0, nil)
		})
		s.Push(vm.newTimer(t))
		return 1
	}))
	// Nox.SecondTimer(sec, fnc)
	vm.root.RawSetString("SecondTimer", vm.s.NewFunction(func(s *lua.LState) int {
		dt := time.Duration(float64(s.CheckNumber(1)) * float64(time.Second))
		fnc := s.CheckFunction(2)
		t := vm.tm.SetTimer(script.Time(dt), func() {
			vm.s.Push(fnc)
			_ = vm.s.PCall(0, 0, nil)
		})
		s.Push(vm.newTimer(t))
		return 1
	}))
}
