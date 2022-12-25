package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

func init() {
	gui.RegisterWindowEvent(&WindowEvent0x4000{}, func(a1, a2 uintptr) gui.WindowEvent {
		return &WindowEvent0x4000{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	gui.RegisterWindowEvent(&WindowEvent0x4001{}, func(a1, a2 uintptr) gui.WindowEvent {
		cstr := (*wchar_t)(unsafe.Pointer(a1))
		str := GoWString(cstr)
		return &WindowEvent0x4001{
			Str:  str,
			Val:  int(a2),
			cstr: cstr,
		}
	})
	gui.RegisterWindowEvent(&WindowEvent0x4005{}, func(a1, a2 uintptr) gui.WindowEvent {
		return &WindowEvent0x4005{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	gui.RegisterWindowEvent(&WindowEvent0x4007{}, func(a1, a2 uintptr) gui.WindowEvent {
		return &WindowEvent0x4007{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	gui.RegisterWindowEvent(&WindowEvent0x4009{}, func(a1, a2 uintptr) gui.WindowEvent {
		return &WindowEvent0x4009{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: int(a2),
		}
	})
	gui.RegisterWindowEvent(&WindowEvent0x400c{}, func(a1, a2 uintptr) gui.WindowEvent {
		return &WindowEvent0x400c{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	gui.RegisterWindowEvent(&WindowEvent0x400d{}, func(a1, a2 uintptr) gui.WindowEvent {
		cstr := (*wchar_t)(unsafe.Pointer(a1))
		str := GoWString(cstr)
		return &WindowEvent0x400d{
			Str:  str,
			Val:  int(a2),
			cstr: cstr,
		}
	})
	gui.RegisterWindowEvent(&WindowEvent0x4010{}, func(a1, a2 uintptr) gui.WindowEvent {
		return &WindowEvent0x4010{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	gui.RegisterWindowEvent(&WindowItemGetString0x4016{}, func(a1, a2 uintptr) gui.WindowEvent {
		return &WindowItemGetString0x4016{
			Ind:  int(a1),
			Val2: a2,
		}
	})
	gui.RegisterWindowEvent(&WindowItemSetString0x4017{}, func(a1, a2 uintptr) gui.WindowEvent {
		cstr := (*wchar_t)(unsafe.Pointer(a1))
		str := GoWString(cstr)
		return &WindowItemSetString0x4017{
			Str:  str,
			Ind:  int(a2),
			cstr: cstr,
		}
	})
	gui.RegisterWindowEvent(&WindowEvent0x4018{}, func(a1, a2 uintptr) gui.WindowEvent {
		return &WindowEvent0x4018{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
	gui.RegisterWindowEvent(&WindowEvent0x4019{}, func(a1, a2 uintptr) gui.WindowEvent {
		return &WindowEvent0x4019{
			Win: asWindowP(unsafe.Pointer(a1)),
			Val: a2,
		}
	})
}

func eventRespStr(r gui.WindowEventResp) string {
	switch r := r.(type) {
	case nil:
		return ""
	case *StrEventResp:
		return r.Str
	default:
		return GoWString((*wchar_t)(gui.EventRespPtr(r)))
	}
}

var _ gui.WindowEventResp = &StrEventResp{}

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

var _ gui.WindowEvent = &WindowEvent0x4000{}

type WindowEvent0x4000 struct {
	Win *gui.Window
	Val uintptr
}

func (*WindowEvent0x4000) EventCode() int { return 0x4000 }
func (ev *WindowEvent0x4000) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ gui.WindowEvent = &WindowEvent0x4001{}

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

var _ gui.WindowEvent = &WindowEvent0x4005{}

type WindowEvent0x4005 struct {
	Win *gui.Window
	Val uintptr
}

func (*WindowEvent0x4005) EventCode() int { return 0x4005 }
func (ev *WindowEvent0x4005) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ gui.WindowEvent = &WindowEvent0x4007{}

type WindowEvent0x4007 struct {
	Win *gui.Window
	Val uintptr
}

func (*WindowEvent0x4007) EventCode() int { return 0x4007 }
func (ev *WindowEvent0x4007) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ gui.WindowEvent = &WindowEvent0x4009{}

type WindowEvent0x4009 struct {
	Win *gui.Window
	Val int
}

func (*WindowEvent0x4009) EventCode() int { return 0x4009 }
func (ev *WindowEvent0x4009) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), uintptr(ev.Val)
}

var _ gui.WindowEvent = &WindowEvent0x400c{}

type WindowEvent0x400c struct {
	Win *gui.Window
	Val uintptr
}

func (*WindowEvent0x400c) EventCode() int { return 0x400c }
func (ev *WindowEvent0x400c) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ gui.WindowEvent = &WindowEvent0x400d{}

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

var _ gui.WindowEvent = &WindowEvent0x4010{}

type WindowEvent0x4010 struct {
	Win *gui.Window
	Val uintptr
}

func (*WindowEvent0x4010) EventCode() int { return 0x4010 }
func (ev *WindowEvent0x4010) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ gui.WindowEvent = &WindowItemGetString0x4016{}

type WindowItemGetString0x4016 struct {
	Ind  int
	Val2 uintptr
}

func (*WindowItemGetString0x4016) EventCode() int { return 0x4016 }
func (ev *WindowItemGetString0x4016) EventArgsC() (uintptr, uintptr) {
	return uintptr(ev.Ind), ev.Val2
}

var _ gui.WindowEvent = &WindowItemSetString0x4017{}

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

var _ gui.WindowEvent = &WindowEvent0x4018{}

type WindowEvent0x4018 struct {
	Win *gui.Window
	Val uintptr
}

func (*WindowEvent0x4018) EventCode() int { return 0x4018 }
func (ev *WindowEvent0x4018) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}

var _ gui.WindowEvent = &WindowEvent0x4019{}

type WindowEvent0x4019 struct {
	Win *gui.Window
	Val uintptr
}

func (*WindowEvent0x4019) EventCode() int { return 0x4019 }
func (ev *WindowEvent0x4019) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.Win.C())), ev.Val
}
