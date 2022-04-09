package opennox

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"

	"github.com/noxworld-dev/opennox/v1/client/input"
)

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
	RegisterWindowEvent(&WindowEvent0x4000{}, func(a1, a2 uintptr) WindowEvent {
		return &WindowEvent0x4000{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	RegisterWindowEvent(&WindowEvent0x4001{}, func(a1, a2 uintptr) WindowEvent {
		cstr := (*wchar_t)(unsafe.Pointer(a1))
		str := GoWString(cstr)
		return &WindowEvent0x4001{
			Str:  str,
			Val:  int(a2),
			cstr: cstr,
		}
	})
	RegisterWindowEvent(&WindowEvent0x4005{}, func(a1, a2 uintptr) WindowEvent {
		return &WindowEvent0x4005{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	RegisterWindowEvent(&WindowEvent0x4007{}, func(a1, a2 uintptr) WindowEvent {
		return &WindowEvent0x4007{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	RegisterWindowEvent(&WindowEvent0x4009{}, func(a1, a2 uintptr) WindowEvent {
		return &WindowEvent0x4009{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: int(a2),
		}
	})
	RegisterWindowEvent(&WindowEvent0x400c{}, func(a1, a2 uintptr) WindowEvent {
		return &WindowEvent0x400c{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	RegisterWindowEvent(&WindowEvent0x400d{}, func(a1, a2 uintptr) WindowEvent {
		cstr := (*wchar_t)(unsafe.Pointer(a1))
		str := GoWString(cstr)
		return &WindowEvent0x400d{
			Str:  str,
			Val:  int(a2),
			cstr: cstr,
		}
	})
	RegisterWindowEvent(&WindowEvent0x4010{}, func(a1, a2 uintptr) WindowEvent {
		return &WindowEvent0x4010{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	RegisterWindowEvent(&WindowItemGetString0x4016{}, func(a1, a2 uintptr) WindowEvent {
		return &WindowItemGetString0x4016{
			Ind:  int(a1),
			Val2: a2,
		}
	})
	RegisterWindowEvent(&WindowItemSetString0x4017{}, func(a1, a2 uintptr) WindowEvent {
		cstr := (*wchar_t)(unsafe.Pointer(a1))
		str := GoWString(cstr)
		return &WindowItemSetString0x4017{
			Str:  str,
			Ind:  int(a2),
			cstr: cstr,
		}
	})
	RegisterWindowEvent(&WindowEvent0x4018{}, func(a1, a2 uintptr) WindowEvent {
		return &WindowEvent0x4018{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	RegisterWindowEvent(&WindowEvent0x4019{}, func(a1, a2 uintptr) WindowEvent {
		return &WindowEvent0x4019{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
}

type WindowEvent interface {
	EventCode() int
	EventArgsC() (a1, a2 uintptr)
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

func eventRespPtr(r WindowEventResp) unsafe.Pointer {
	if r == nil {
		return nil
	}
	return unsafe.Pointer(r.EventRespC())
}

func eventRespStr(r WindowEventResp) string {
	switch r := r.(type) {
	case nil:
		return ""
	case *StrEventResp:
		return r.Str
	default:
		return GoWString((*wchar_t)(eventRespPtr(r)))
	}
}

type WindowEventResp interface {
	EventRespC() uintptr
}

var _ WindowEventResp = RawEventResp(0)

type RawEventResp uintptr

func (r RawEventResp) EventRespC() uintptr {
	return uintptr(r)
}

var _ WindowEventResp = &StrEventResp{}

type StrEventResp struct {
	Str  string
	cstr *wchar_t
}

func (r *StrEventResp) EventRespC() uintptr {
	if r.cstr == nil {
		r.cstr = internWStr(r.Str)
	}
	return uintptr(unsafe.Pointer(r.cstr))
}

var _ WindowEvent = &WindowEvent0x4000{}

type WindowEvent0x4000 struct {
	Win *Window
	Val uintptr
}

func (*WindowEvent0x4000) EventCode() int { return 0x4000 }
func (ev *WindowEvent0x4000) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ WindowEvent = &WindowEvent0x4001{}

type WindowEvent0x4001 struct {
	Str  string
	Val  int
	cstr *wchar_t
}

func (*WindowEvent0x4001) EventCode() int { return guiEventStaticTextSetText }
func (ev *WindowEvent0x4001) cStr() *wchar_t {
	if ev.cstr == nil {
		ev.cstr = internWStr(ev.Str)
	}
	return ev.cstr
}
func (ev *WindowEvent0x4001) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.cStr())), uintptr(ev.Val)
}

var _ WindowEvent = &WindowEvent0x4005{}

type WindowEvent0x4005 struct {
	Win *Window
	Val uintptr
}

func (*WindowEvent0x4005) EventCode() int { return 0x4005 }
func (ev *WindowEvent0x4005) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ WindowEvent = &WindowEvent0x4007{}

type WindowEvent0x4007 struct {
	Win *Window
	Val uintptr
}

func (*WindowEvent0x4007) EventCode() int { return 0x4007 }
func (ev *WindowEvent0x4007) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ WindowEvent = &WindowEvent0x4009{}

type WindowEvent0x4009 struct {
	Win *Window
	Val int
}

func (*WindowEvent0x4009) EventCode() int { return 0x4009 }
func (ev *WindowEvent0x4009) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), uintptr(ev.Val)
}

var _ WindowEvent = &WindowEvent0x400c{}

type WindowEvent0x400c struct {
	Win *Window
	Val uintptr
}

func (*WindowEvent0x400c) EventCode() int { return 0x400c }
func (ev *WindowEvent0x400c) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ WindowEvent = &WindowEvent0x400d{}

type WindowEvent0x400d struct {
	Str  string
	Val  int
	cstr *wchar_t
}

func (*WindowEvent0x400d) EventCode() int { return 0x400d }
func (ev *WindowEvent0x400d) EventArgsC() (uintptr, uintptr) {
	if ev.cstr == nil {
		ev.cstr = internWStr(ev.Str)
	}
	return uintptr(unsafe.Pointer(ev.cstr)), uintptr(ev.Val)
}

var _ WindowEvent = &WindowEvent0x4010{}

type WindowEvent0x4010 struct {
	Win *Window
	Val uintptr
}

func (*WindowEvent0x4010) EventCode() int { return 0x4010 }
func (ev *WindowEvent0x4010) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ WindowEvent = &WindowItemGetString0x4016{}

type WindowItemGetString0x4016 struct {
	Ind  int
	Val2 uintptr
}

func (*WindowItemGetString0x4016) EventCode() int { return 0x4016 }
func (ev *WindowItemGetString0x4016) EventArgsC() (uintptr, uintptr) {
	return uintptr(ev.Ind), ev.Val2
}

var _ WindowEvent = &WindowItemSetString0x4017{}

type WindowItemSetString0x4017 struct {
	Str  string
	Ind  int
	cstr *wchar_t
}

func (*WindowItemSetString0x4017) EventCode() int { return 0x4017 }
func (ev *WindowItemSetString0x4017) EventArgsC() (uintptr, uintptr) {
	if ev.cstr == nil {
		ev.cstr = internWStr(ev.Str)
	}
	return uintptr(unsafe.Pointer(ev.cstr)), uintptr(ev.Ind)
}

var _ WindowEvent = &WindowEvent0x4018{}

type WindowEvent0x4018 struct {
	Win *Window
	Val uintptr
}

func (*WindowEvent0x4018) EventCode() int { return 0x4018 }
func (ev *WindowEvent0x4018) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ WindowEvent = &WindowEvent0x4019{}

type WindowEvent0x4019 struct {
	Win *Window
	Val uintptr
}

func (*WindowEvent0x4019) EventCode() int { return 0x4019 }
func (ev *WindowEvent0x4019) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}
