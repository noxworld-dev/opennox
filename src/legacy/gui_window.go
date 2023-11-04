package legacy

import (
	"image"
	"runtime/debug"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

func AsWindowP(win unsafe.Pointer) *gui.Window {
	w := (*gui.Window)(win)
	if false && cgoSafe && w.ID() == DeadWord {
		debug.PrintStack()
		panic("memory corruption detected")
	}
	return w
}

// get_dword_5d4594_3799468
func get_dword_5d4594_3799468() int {
	return GetClient().Cli().GUI.ValXXX
}

// set_dword_5d4594_3799468
func set_dword_5d4594_3799468(v int) {
	GetClient().Cli().GUI.ValYYY = v
}

func nox_window_new(par *gui.Window, flags nox_window_flags, a3, a4, w, h int, fnc gui.WindowFuncLegacy) *gui.Window {
	return GetClient().Cli().GUI.NewWindowRaw(par, flags, a3, a4, w, h, gui.WrapFunc(fnc))
}

// nox_xxx_wndGetID_46B0A0
func nox_xxx_wndGetID_46B0A0(win *gui.Window) int32 {
	if win == nil {
		return -2
	}
	return int32(win.ID())
}

// nox_xxx_wndSetID_46B080
func nox_xxx_wndSetID_46B080(win *gui.Window, id int32) int32 {
	if win == nil {
		return -2
	}
	win.SetID(uint(id))
	return 0
}

func nox_window_set_all_funcs(win *gui.Window, proc gui.WindowFuncLegacy, draw gui.WindowDrawFunc, tooltip gui.WindowTooltipFunc) {
	if win == nil {
		return
	}
	win.SetFunc93(gui.WrapFunc(proc))
	win.SetDraw(draw)
	win.SetTooltipFunc(tooltip)
}

func nox_xxx_wndSetWindowProc_46B300(win *gui.Window, fnc gui.WindowFuncLegacy) {
	if win == nil {
		return
	}
	win.SetFunc93(gui.WrapFunc(fnc))
}

func nox_xxx_wndSetProc_46B2C0(win *gui.Window, fnc gui.WindowFuncLegacy) {
	if win == nil {
		return
	}
	win.SetFunc94(gui.WrapFunc(fnc))
}

func nox_xxx_wndSetDrawFn_46B340(win *gui.Window, fnc gui.WindowDrawFunc) {
	if win == nil {
		return
	}
	win.SetDraw(fnc)
}

func nox_gui_winSetFunc96_46B070(win *gui.Window, fnc gui.WindowTooltipFunc) {
	win.SetTooltipFunc(fnc)
}

func nox_xxx_wndSetRectColor2MB_46AFE0(win *gui.Window, a2 int32) int32 {
	if win == nil {
		return -2
	}
	// TODO: not sure if the color format is correct
	win.DrawData().SetBackgroundColor(noxcolor.RGBA5551(a2))
	return 0
}

func nox_window_call_field_94_fnc(p *gui.Window, a2, a3, a4 uintptr) uintptr {
	if p == nil {
		return 0
	}
	if guiDebug {
		guiLog.Printf("nox_window_call_field_94(%p, %x, %x, %x)", p, a2, a3, a4)
	}
	r := p.Func94(gui.AsWindowEvent(int(a2), a3, a4))
	if r == nil {
		return 0
	}
	return r.EventRespC()
}

func nox_window_call_field_93(p *gui.Window, a2, a3, a4 int32) int32 {
	if p == nil {
		return 0
	}
	r := p.Func93(gui.AsWindowEvent(int(a2), uintptr(a3), uintptr(a4)))
	if r == nil {
		return 0
	}
	return int32(r.EventRespC())
}

func nox_xxx_wndGetChildByID_46B0C0(root *gui.Window, id int32) *gui.Window {
	return root.ChildByID(uint(id))
}

func nox_xxx_windowDestroyMB_46C4E0(win *gui.Window) {
	win.Destroy()
}

func nox_window_set_hidden(p *gui.Window, hidden int32) int32 {
	if p == nil {
		return -2
	}
	win := p
	if hidden != 0 {
		win.Hide()
	} else {
		win.Show()
	}
	return 0
}

func nox_xxx_wndShowModalMB_46A8C0(p *gui.Window) int32 {
	return int32(p.ShowModal())
}

func nox_window_setPos_46A9B0(p *gui.Window, x, y int32) int32 {
	win := p
	if win == nil {
		return -2
	}
	win.SetPos(image.Point{X: int(x), Y: int(y)})
	return 0
}

func wndIsShown_nox_xxx_wndIsShown_46ACC0(p *gui.Window) int32 {
	if p == nil {
		return 1
	}
	win := p
	is := win.GetFlags().IsHidden()
	return bool2int32(is)
}

func nox_xxx_wnd_46C6E0(p *gui.Window) int32 {
	return int32(p.StackPop())
}

func sub_46C690(p *gui.Window) int32 {
	return int32(p.StackPush())
}

func Nox_xxx_wnd_46ABB0(p *gui.Window, v int) int {
	return int(nox_xxx_wnd_46ABB0(p, int32(v)))
}
