package nox

import (
	"unsafe"

	"nox/v1/client/input"
	"nox/v1/common/keybind"
	"nox/v1/common/types"
)

var (
	winEventTypes = make(map[int]WindowEventTypeFunc)
)

type WindowEventTypeFunc func(a1, a2 uintptr) WindowEvent

func RegisterWindowEvent(typ WindowEvent, fnc WindowEventTypeFunc) {
	ev, _, _ := typ.EventArgsC()
	if winEventTypes[ev] != nil && fnc != nil {
		panic("already registered")
	}
	winEventTypes[ev] = fnc
}

func init() {
	RegisterWindowEvent(WindowInit{}, func(a1, a2 uintptr) WindowEvent {
		if a1 != 0 || a2 != 0 {
			panic("unexpected event")
		}
		return WindowInit{}
	})
	RegisterWindowEvent(WindowDestroy{}, func(a1, a2 uintptr) WindowEvent {
		if a1 != 0 || a2 != 0 {
			panic("unexpected event")
		}
		return WindowDestroy{}
	})
	RegisterWindowEvent(WindowKeyPress{}, func(a1, a2 uintptr) WindowEvent {
		return WindowKeyPress{Key: keybind.Key(a1), Pressed: a2 >= 2}
	})
	RegisterWindowEvent(WindowNewChild{}, func(a1, a2 uintptr) WindowEvent {
		if a2 != 0 {
			panic("unexpected event")
		}
		return WindowNewChild{ID: uint(a1)}
	})
	RegisterWindowEvent(WindowFocus(false), func(a1, a2 uintptr) WindowEvent {
		if a2 != 0 {
			panic("unexpected event")
		}
		return WindowFocus(a1 != 0)
	})
}

type WindowEvent interface {
	EventArgsC() (ev int, a1, a2 uintptr)
}

func asWindowEvent(ev int, a1, a2 uintptr) WindowEvent {
	if fnc := winEventTypes[ev]; fnc != nil {
		return fnc(a1, a2)
	}
	if ev >= int(input.NOX_MOUSE_LEFT_DOWN) && ev <= int(input.NOX_MOUSE_MIDDLE_PRESSED) {
		if a2 != 0 {
			panic("unexpected event")
		}
		sx := uint16(a1 >> 0)
		sy := uint16(a1 >> 16)
		pos := types.Point{X: int(sx), Y: int(sy)}
		return &WindowMouseState{State: input.MouseStateCode(ev), Pos: pos}
	}
	switch ev {
	case 17, 18:
		sx := uint16(a1 >> 0)
		sy := uint16(a1 >> 16)
		pos := types.Point{X: int(sx), Y: int(sy)}
		return &WindowMouseUnk{Event: ev, Pos: pos}
	}
	return &RawEvent{Event: ev, Arg1: a1, Arg2: a2}
}

var _ WindowEvent = &RawEvent{}

type RawEvent struct {
	Event      int
	Arg1, Arg2 uintptr
}

func (ev *RawEvent) EventArgsC() (int, uintptr, uintptr) {
	return ev.Event, ev.Arg1, ev.Arg2
}

var _ WindowEvent = WindowInit{}

type WindowInit struct{}

func (WindowInit) EventArgsC() (int, uintptr, uintptr) {
	return 1, 0, 0
}

var _ WindowEvent = WindowDestroy{}

type WindowDestroy struct {
	Targ *Window
}

func (ev WindowDestroy) EventArgsC() (int, uintptr, uintptr) {
	return 2, uintptr(unsafe.Pointer(ev.Targ.C())), 0
}

var _ WindowEvent = &WindowMouseState{}

type WindowMouseState struct {
	State input.MouseStateCode
	Pos   types.Point
}

func (ev *WindowMouseState) EventArgsC() (int, uintptr, uintptr) {
	sx := uint16(ev.Pos.X)
	sy := uint16(ev.Pos.Y)
	spos := uintptr(uint32(sx) | (uint32(sy) << 16))
	return int(ev.State), spos, 0
}

var _ WindowEvent = &WindowMouseUnk{}

type WindowMouseUnk struct {
	Event int
	Pos   types.Point
}

func (ev *WindowMouseUnk) EventArgsC() (int, uintptr, uintptr) {
	sx := uint16(ev.Pos.X)
	sy := uint16(ev.Pos.Y)
	spos := uintptr(uint32(sx) | (uint32(sy) << 16))
	return ev.Event, spos, 0
}

var _ WindowEvent = WindowKeyPress{}

type WindowKeyPress struct {
	Key     keybind.Key
	Pressed bool
}

func (ev WindowKeyPress) EventArgsC() (int, uintptr, uintptr) {
	if ev.Pressed {
		return 21, uintptr(ev.Key), 2
	}
	return 21, uintptr(ev.Key), 1
}

var _ WindowEvent = WindowNewChild{}

type WindowNewChild struct {
	ID uint
}

func (ev WindowNewChild) EventArgsC() (int, uintptr, uintptr) {
	return 22, uintptr(ev.ID), 0
}

var _ WindowEvent = WindowFocus(false)

type WindowFocus bool

func (ev WindowFocus) EventArgsC() (int, uintptr, uintptr) {
	if ev {
		return 23, 1, 0
	}
	return 23, 0, 0
}

func eventRespBool(r WindowEventResp) bool {
	if r == nil {
		return false
	}
	return r.EventRespC() != 0
}

func eventRespInt(r WindowEventResp) int {
	if r == nil {
		return 0
	}
	return int(r.EventRespC())
}

type WindowEventResp interface {
	EventRespC() uintptr
}

var _ WindowEventResp = RawEventResp(0)

type RawEventResp uintptr

func (r RawEventResp) EventRespC() uintptr {
	return uintptr(r)
}
