package legacy

import (
	"image"
	"runtime/debug"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

type nox_window = gui.Window

func AsWindowP(win unsafe.Pointer) *gui.Window {
	w := (*gui.Window)(win)
	if false && cgoSafe && w.ID() == DeadWord {
		debug.PrintStack()
		panic("memory corruption detected")
	}
	return w
}

func asWindow(win *nox_window) *gui.Window {
	return AsWindowP(unsafe.Pointer(win))
}

// get_dword_5d4594_3799468
func get_dword_5d4594_3799468() int {
	return GetClient().Cli().GUI.ValXXX
}

// set_dword_5d4594_3799468
func set_dword_5d4594_3799468(v int) {
	GetClient().Cli().GUI.ValYYY = v
}

type WindowFunc = func(win *nox_window, p2, p3, p4 uintptr) uintptr

func nox_window_new(par *nox_window, flags nox_window_flags, a3, a4, w, h int, fnc WindowFunc) *nox_window {
	return (*nox_window)(GetClient().Cli().GUI.NewWindowRaw(asWindow(par), gui.StatusFlags(flags), a3, a4, w, h, gui.WrapFunc(fnc)).C())
}

// nox_xxx_wndGetID_46B0A0
func nox_xxx_wndGetID_46B0A0(win *nox_window) int32 {
	if win == nil {
		return -2
	}
	return int32(asWindow(win).ID())
}

// nox_xxx_wndSetID_46B080
func nox_xxx_wndSetID_46B080(win *nox_window, id int32) int32 {
	if win == nil {
		return -2
	}
	asWindow(win).SetID(uint(id))
	return 0
}

func nox_window_set_all_funcs(win *nox_window, proc WindowFunc, draw gui.WindowDrawFunc, tooltip unsafe.Pointer) int32 {
	if win == nil {
		return -2
	}
	win.SetFunc93(gui.WrapFunc(proc))
	win.SetDraw(draw)
	win.SetTooltipFunc(tooltip)
	return 0
}

func nox_xxx_wndSetWindowProc_46B300(win *nox_window, fnc WindowFunc) int32 {
	if win == nil {
		return -2
	}
	asWindow(win).SetFunc93(gui.WrapFunc(fnc))
	return 0
}

func nox_xxx_wndSetProc_46B2C0(win *nox_window, fnc WindowFunc) int32 {
	if win == nil {
		return -2
	}
	asWindow(win).SetFunc94(gui.WrapFunc(fnc))
	return 0
}

func nox_xxx_wndSetDrawFn_46B340(win *nox_window, fnc gui.WindowDrawFunc) int32 {
	if win == nil {
		return -2
	}
	asWindow(win).SetDraw(fnc)
	return 0
}

// nox_gui_winSetFunc96_46B070
func nox_gui_winSetFunc96_46B070(win *nox_window, fnc unsafe.Pointer) {
	asWindow(win).SetTooltipFunc(fnc)
}

// nox_xxx_wndSetRectColor2MB_46AFE0
func nox_xxx_wndSetRectColor2MB_46AFE0(win *nox_window, a2 int32) int32 {
	if win == nil {
		return -2
	}
	// TODO: not sure if the color format is correct
	asWindow(win).DrawData().SetBackgroundColor(noxcolor.RGBA5551(a2))
	return 0
}

// nox_window_call_field_94_fnc
func nox_window_call_field_94_fnc(p *nox_window, a2, a3, a4 uintptr) uintptr {
	if p == nil {
		return 0
	}
	if guiDebug {
		guiLog.Printf("nox_window_call_field_94(%p, %x, %x, %x)", p, a2, a3, a4)
	}
	r := asWindow(p).Func94(gui.AsWindowEvent(int(a2), a3, a4))
	if r == nil {
		return 0
	}
	return r.EventRespC()
}

// nox_window_call_field_93
func nox_window_call_field_93(p *nox_window, a2, a3, a4 int32) int32 {
	if p == nil {
		return 0
	}
	r := asWindow(p).Func93(gui.AsWindowEvent(int(a2), uintptr(a3), uintptr(a4)))
	if r == nil {
		return 0
	}
	return int32(r.EventRespC())
}

// nox_xxx_wndGetChildByID_46B0C0
func nox_xxx_wndGetChildByID_46B0C0(root *nox_window, id int32) *nox_window {
	return (*nox_window)(asWindow(root).ChildByID(uint(id)).C())
}

// nox_xxx_windowDestroyMB_46C4E0
func nox_xxx_windowDestroyMB_46C4E0(a1 *nox_window) int32 {
	win := asWindow(a1)
	if win == nil {
		return -2
	}
	win.Destroy()
	return 0
}

// nox_window_set_hidden
func nox_window_set_hidden(p *nox_window, hidden int32) int32 {
	if p == nil {
		return -2
	}
	win := asWindow(p)
	if hidden != 0 {
		win.Hide()
	} else {
		win.Show()
	}
	return 0
}

// nox_xxx_wndShowModalMB_46A8C0
func nox_xxx_wndShowModalMB_46A8C0(p *nox_window) int32 {
	return int32(asWindow(p).ShowModal())
}

// nox_window_setPos_46A9B0
func nox_window_setPos_46A9B0(p *nox_window, x, y int32) int32 {
	win := asWindow(p)
	if win == nil {
		return -2
	}
	win.SetPos(image.Point{X: int(x), Y: int(y)})
	return 0
}

// wndIsShown_nox_xxx_wndIsShown_46ACC0
func wndIsShown_nox_xxx_wndIsShown_46ACC0(p *nox_window) int32 {
	if p == nil {
		return 1
	}
	win := asWindow(p)
	is := win.GetFlags().IsHidden()
	return bool2int32(is)
}

// nox_xxx_wnd_46C6E0
func nox_xxx_wnd_46C6E0(p *nox_window) int32 {
	return int32(asWindow(p).StackPop())
}

// sub_46C690
func sub_46C690(p *nox_window) int32 {
	return int32(asWindow(p).StackPush())
}

func Nox_xxx_wnd_46ABB0(p *gui.Window, v int) int {
	return int(nox_xxx_wnd_46ABB0((*nox_window)(p.C()), int32(v)))
}
