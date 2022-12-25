package gui

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"

	"github.com/noxworld-dev/opennox/v1/client/input"
)

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

func EventRespBool(r WindowEventResp) bool {
	if r == nil {
		return false
	}
	return r.EventRespC() != 0
}

func EventRespInt(r WindowEventResp) int {
	if r == nil {
		return 0
	}
	return int(r.EventRespC())
}

func EventRespPtr(r WindowEventResp) unsafe.Pointer {
	if r == nil {
		return nil
	}
	return unsafe.Pointer(r.EventRespC())
}

type WindowEvent interface {
	EventCode() int
	EventArgsC() (a1, a2 uintptr)
}

var (
	winEventTypes = make(map[int]WindowEventTypeFunc)
)

type WindowEventTypeFunc func(a1, a2 uintptr) WindowEvent

func RegisterWindowEvent(typ WindowEvent, fnc WindowEventTypeFunc) {
	ev := typ.EventCode()
	if winEventTypes[ev] != nil && fnc != nil {
		panic("already registered")
	}
	winEventTypes[ev] = fnc
}

func AsWindowEvent(ev int, a1, a2 uintptr) WindowEvent {
	if fnc := winEventTypes[ev]; fnc != nil {
		return fnc(a1, a2)
	}
	if ev >= int(input.NOX_MOUSE_LEFT_DOWN) && ev <= int(input.NOX_MOUSE_MIDDLE_PRESSED) {
		if a2 != 0 {
			panic("unexpected event")
		}
		sx := uint16(a1 >> 0)
		sy := uint16(a1 >> 16)
		pos := image.Point{X: int(sx), Y: int(sy)}
		return &WindowMouseState{State: input.MouseStateCode(ev), Pos: pos}
	}
	switch ev {
	case 17, 18:
		sx := uint16(a1 >> 0)
		sy := uint16(a1 >> 16)
		pos := image.Point{X: int(sx), Y: int(sy)}
		return &WindowMouseUnk{Event: ev, Pos: pos}
	}
	return &RawEvent{Event: ev, Arg1: a1, Arg2: a2}
}

var _ WindowEvent = &RawEvent{}

type RawEvent struct {
	Event      int
	Arg1, Arg2 uintptr
}

func (ev *RawEvent) EventCode() int { return ev.Event }
func (ev *RawEvent) EventArgsC() (uintptr, uintptr) {
	return ev.Arg1, ev.Arg2
}

var _ WindowEvent = WindowInit{}

type WindowInit struct{}

func (WindowInit) EventCode() int { return 1 }
func (ev WindowInit) EventArgsC() (uintptr, uintptr) {
	return 0, 0
}

var _ WindowEvent = WindowDestroy{}

type WindowDestroy struct {
	Targ *Window
}

func (WindowDestroy) EventCode() int { return 2 }
func (ev WindowDestroy) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Targ.C())), 0
}

var _ WindowEvent = &WindowMouseState{}

type WindowMouseState struct {
	State input.MouseStateCode
	Pos   image.Point
}

func (ev *WindowMouseState) EventCode() int { return int(ev.State) }
func (ev *WindowMouseState) EventArgsC() (uintptr, uintptr) {
	sx := uint16(ev.Pos.X)
	sy := uint16(ev.Pos.Y)
	spos := uintptr(uint32(sx) | (uint32(sy) << 16))
	return spos, 0
}

var _ WindowEvent = &WindowMouseUnk{}

type WindowMouseUnk struct {
	Event int
	Pos   image.Point
}

func (ev *WindowMouseUnk) EventCode() int { return ev.Event }
func (ev *WindowMouseUnk) EventArgsC() (uintptr, uintptr) {
	sx := uint16(ev.Pos.X)
	sy := uint16(ev.Pos.Y)
	spos := uintptr(uint32(sx) | (uint32(sy) << 16))
	return spos, 0
}

var _ WindowEvent = WindowKeyPress{}

type WindowKeyPress struct {
	Key     keybind.Key
	Pressed bool
}

func (WindowKeyPress) EventCode() int { return 21 }
func (ev WindowKeyPress) EventArgsC() (uintptr, uintptr) {
	if ev.Pressed {
		return uintptr(ev.Key), 2
	}
	return uintptr(ev.Key), 1
}

var _ WindowEvent = WindowNewChild{}

type WindowNewChild struct {
	ID uint
}

func (WindowNewChild) EventCode() int { return 22 }
func (ev WindowNewChild) EventArgsC() (uintptr, uintptr) {
	return uintptr(ev.ID), 0
}

var _ WindowEvent = WindowFocus(false)

type WindowFocus bool

func (WindowFocus) EventCode() int { return 23 }
func (ev WindowFocus) EventArgsC() (uintptr, uintptr) {
	if ev {
		return 1, 0
	}
	return 0, 0
}

type WindowEventResp interface {
	EventRespC() uintptr
}

var _ WindowEventResp = RawEventResp(0)

type RawEventResp uintptr

func (r RawEventResp) EventRespC() uintptr {
	return uintptr(r)
}
