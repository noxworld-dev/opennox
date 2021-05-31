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
	vm.meta.Timer = vm.newMeta("Timer")
	vm.meta.Dur = vm.newMeta("")
}

func (vm *api) luaNewTimer(dur script.Duration, s *lua.LState, off int) int {
	fnc := s.CheckFunction(off)
	var args []lua.LValue
	for i := off + 1; i <= s.GetTop(); i++ {
		args = append(args, s.Get(i))
	}
	t := vm.tm.SetTimer(dur, func() {
		vm.s.Push(fnc)
		for _, a := range args {
			vm.s.Push(a)
		}
		err := vm.s.PCall(len(args), 0, nil)
		if err != nil {
			vm.s.Error(lua.LString(err.Error()), 0)
		}
	})
	s.Push(vm.newTimer(t))
	return 1
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
	// Nox.FrameTimer(frames, fnc, ...)
	vm.root.RawSetString("FrameTimer", vm.s.NewFunction(func(s *lua.LState) int {
		v := int(s.CheckNumber(1))
		return vm.luaNewTimer(script.Frames(v), s, 2)
	}))
	// Nox.SecondTimer(sec, fnc, ...)
	vm.root.RawSetString("SecondTimer", vm.s.NewFunction(func(s *lua.LState) int {
		dt := time.Duration(float64(s.CheckNumber(1)) * float64(time.Second))
		return vm.luaNewTimer(script.Time(dt), s, 2)
	}))
	// Nox.Timer(dur, fnc)
	vm.meta.Timer.RawSetString("__call", vm.s.NewFunction(func(s *lua.LState) int {
		dur, ok := s.CheckUserData(2).Value.(script.Duration)
		if !ok {
			return 0
		}
		return vm.luaNewTimer(dur, s, 3)
	}))
	// Timer:Stop()
	vm.meta.Timer.RawSetString("Stop", vm.s.NewFunction(func(s *lua.LState) int {
		t, ok := s.CheckUserData(1).Value.(*script.Timer)
		if !ok {
			return 0
		}
		t.Stop()
		return 0
	}))
	vm.setIndexFunction(vm.meta.Timer, nil)
}
