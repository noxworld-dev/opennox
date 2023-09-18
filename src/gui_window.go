package opennox

/*
#include <stdlib.h>
#include "client__gui__window.h"

static int nox_window_call_draw_func_go(int (*fnc)(nox_window*, nox_window_data*), nox_window* win, nox_window_data* data) {
	return fnc(win, data);
}
static int nox_window_call_func_go(int (*fnc)(nox_window*, int, int, int), nox_window* win, int a2, int a3, int a4) {
	return fnc(win, a2, a3, a4);
}
static void nox_window_call_tooltip_func(nox_window* win, nox_window_data* data, int a3) {
	if (!win || !win->tooltip_func)
		return;
	win->tooltip_func(win, data, a3);
}
*/
import "C"
import (
	"image"
	"runtime/debug"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

func (c *Client) guiLoadBorderImages() {
	c.GUI.SetBorders(gui.Borders{
		CornerUL:        nox_xxx_gLoadImg("BorderCornerUL"),
		CornerUR:        nox_xxx_gLoadImg("BorderCornerUR"),
		CornerLL:        nox_xxx_gLoadImg("BorderCornerLL"),
		CornerLR:        nox_xxx_gLoadImg("BorderCornerLR"),
		Horizontal:      nox_xxx_gLoadImg("BorderHorizontal"),
		HorizontalShort: nox_xxx_gLoadImg("BorderHorizontalShort"),
		Vertical:        nox_xxx_gLoadImg("BorderVertical"),
		VerticalShort:   nox_xxx_gLoadImg("BorderVerticalShort"),
	})
}

//export get_dword_5d4594_3799468
func get_dword_5d4594_3799468() int {
	return noxClient.GUI.ValXXX
}

//export set_dword_5d4594_3799468
func set_dword_5d4594_3799468(v int) {
	noxClient.GUI.ValYYY = v
}

//export nox_window_new_go
func nox_window_new_go(par *C.nox_window, flags, a3, a4, w, h C.int, fnc unsafe.Pointer) *C.nox_window {
	return (*C.nox_window)(noxClient.GUI.NewWindowRaw(asWindow(par), gui.StatusFlags(flags), int(a3), int(a4), int(w), int(h), gui.WrapFuncC(fnc)).C())
}

//export nox_xxx_wndGetID_46B0A0
func nox_xxx_wndGetID_46B0A0(win *C.nox_window) int {
	if win == nil {
		return -2
	}
	return int(asWindow(win).ID())
}

//export nox_xxx_wndSetID_46B080
func nox_xxx_wndSetID_46B080(win *C.nox_window, id int) int {
	if win == nil {
		return -2
	}
	win.id = C.int(id)
	return 0
}

//export nox_window_set_all_funcs_go
func nox_window_set_all_funcs_go(p *C.nox_window, a2 unsafe.Pointer, draw unsafe.Pointer, tooltip unsafe.Pointer) int {
	if p == nil {
		return -2
	}
	win := asWindow(p)
	win.SetFunc93(gui.WrapFuncC(a2))
	win.SetDraw(gui.WrapDrawFuncC(draw))
	win.SetTooltipFunc(tooltip)
	return 0
}

//export nox_xxx_wndSetWindowProc_46B300_go
func nox_xxx_wndSetWindowProc_46B300_go(win *C.nox_window, fnc unsafe.Pointer) int {
	if win == nil {
		return -2
	}
	asWindow(win).SetFunc93(gui.WrapFuncC(fnc))
	return 0
}

//export nox_xxx_wndSetProc_46B2C0_go
func nox_xxx_wndSetProc_46B2C0_go(win *C.nox_window, fnc unsafe.Pointer) int {
	if win == nil {
		return -2
	}
	asWindow(win).SetFunc94(gui.WrapFuncC(fnc))
	return 0
}

//export nox_xxx_wndSetDrawFn_46B340_go
func nox_xxx_wndSetDrawFn_46B340_go(win *C.nox_window, fnc unsafe.Pointer) int {
	if win == nil {
		return -2
	}
	asWindow(win).SetDraw(gui.WrapDrawFuncC(fnc))
	return 0
}

//export nox_gui_winSetFunc96_46B070
func nox_gui_winSetFunc96_46B070(win *C.nox_window, fnc unsafe.Pointer) {
	asWindow(win).SetTooltipFunc(fnc)
}

//export nox_xxx_wndSetRectColor2MB_46AFE0
func nox_xxx_wndSetRectColor2MB_46AFE0(win *C.nox_window, a2 int) int {
	if win == nil {
		return -2
	}
	// TODO: not sure if the color format is correct
	asWindow(win).DrawData().SetBackgroundColor(noxcolor.RGBA5551(a2))
	return 0
}

//export nox_window_call_field_94_fnc
func nox_window_call_field_94_fnc(p *C.nox_window, a2, a3, a4 int, file *C.char, line int) int {
	if p == nil {
		return 0
	}
	if guiDebug {
		guiLog.Printf("nox_window_call_field_94(%p, %x, %x, %x): %s:%d", p, a2, a3, a4, GoString(file), line)
	}
	r := asWindow(p).Func94(gui.AsWindowEvent(a2, uintptr(a3), uintptr(a4)))
	if r == nil {
		return 0
	}
	return int(r.EventRespC())
}

//export nox_window_call_field_93
func nox_window_call_field_93(p *C.nox_window, a2, a3, a4 int) int {
	if p == nil {
		return 0
	}
	r := asWindow(p).Func93(gui.AsWindowEvent(a2, uintptr(a3), uintptr(a4)))
	if r == nil {
		return 0
	}
	return int(r.EventRespC())
}

//export nox_xxx_wndGetChildByID_46B0C0
func nox_xxx_wndGetChildByID_46B0C0(root *C.nox_window, id int) *C.nox_window {
	return (*C.nox_window)(asWindow(root).ChildByID(uint(id)).C())
}

//export nox_xxx_windowDestroyMB_46C4E0
func nox_xxx_windowDestroyMB_46C4E0(a1 *C.nox_window) int {
	win := asWindow(a1)
	if win == nil {
		return -2
	}
	win.Destroy()
	return 0
}

//export nox_window_set_hidden
func nox_window_set_hidden(p *C.nox_window, hidden int) int {
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

func asWindow(win *C.nox_window) *gui.Window {
	return asWindowP(unsafe.Pointer(win))
}

func asWindowP(win unsafe.Pointer) *gui.Window {
	w := (*gui.Window)(win)
	if false && cgoSafe && w.ID() == DeadWord {
		log.Println("memory corruption detected")
		debug.PrintStack()
		C.abort()
	}
	return w
}

//export nox_xxx_wndShowModalMB_46A8C0
func nox_xxx_wndShowModalMB_46A8C0(p *C.nox_window) int {
	return asWindow(p).ShowModal()
}

//export nox_window_setPos_46A9B0
func nox_window_setPos_46A9B0(p *C.nox_window, x, y int) int {
	win := asWindow(p)
	if win == nil {
		return -2
	}
	win.SetPos(image.Point{X: x, Y: y})
	return 0
}

//export wndIsShown_nox_xxx_wndIsShown_46ACC0
func wndIsShown_nox_xxx_wndIsShown_46ACC0(p *C.nox_window) int {
	if p == nil {
		return 1
	}
	win := asWindow(p)
	is := win.GetFlags().IsHidden()
	return bool2int(is)
}

func nox_xxx_wnd_46ABB0(win *gui.Window, v int) int {
	return int(C.nox_xxx_wnd_46ABB0((*C.nox_window)(win.C()), C.int(v)))
}

//export nox_xxx_wnd_46C6E0
func nox_xxx_wnd_46C6E0(p *C.nox_window) int {
	return asWindow(p).StackPop()
}

//export sub_46C690
func sub_46C690(p *C.nox_window) int {
	return asWindow(p).StackPush()
}
