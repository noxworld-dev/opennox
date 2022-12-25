package opennox

/*
#include <stdlib.h>
#include "client__gui__window.h"
extern nox_window_ref* nox_win_1064912;

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
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func init() {
	gui.DrawImplFunc = guiDrawWindowStyle
}

var (
	guiBorderCornerUL        *noxrender.Image
	guiBorderCornerUR        *noxrender.Image
	guiBorderCornerLL        *noxrender.Image
	guiBorderCornerLR        *noxrender.Image
	guiBorderHorizontal      *noxrender.Image
	guiBorderHorizontalShort *noxrender.Image
	guiBorderVertical        *noxrender.Image
	guiBorderVerticalShort   *noxrender.Image
)

func guiLoadBorderImages() {
	guiBorderCornerUL = nox_xxx_gLoadImg("BorderCornerUL")
	guiBorderCornerUR = nox_xxx_gLoadImg("BorderCornerUR")
	guiBorderCornerLL = nox_xxx_gLoadImg("BorderCornerLL")
	guiBorderCornerLR = nox_xxx_gLoadImg("BorderCornerLR")
	guiBorderHorizontal = nox_xxx_gLoadImg("BorderHorizontal")
	guiBorderHorizontalShort = nox_xxx_gLoadImg("BorderHorizontalShort")
	guiBorderVertical = nox_xxx_gLoadImg("BorderVertical")
	guiBorderVerticalShort = nox_xxx_gLoadImg("BorderVerticalShort")
}

func guiDrawWindowStyle(win *gui.Window) {
	r := noxClient.r
	data := win.DrawData()
	gpos := win.GlobalPos()
	sz := win.Size()

	for i := 0; i < 32; i++ {
		flag := data.Style & (1 << i)
		if flag == 0 {
			continue
		}
		switch flag {
		case gui.StylePushButton, gui.StyleRadioButton, gui.StyleStaticText, gui.StyleProgressBar, gui.StyleUserWindow:
			guiDrawBorders(gpos.X, gpos.Y, sz.X, sz.Y)
			return
		case gui.StyleCheckBox, gui.StyleVertSlider, gui.StyleHorizSlider:
			return
		case gui.StyleScrollListBox:
			ptr := win.WidgetData
			dsx := 0
			dy := 0
			if *(*uint32)(unsafe.Add(ptr, 12)) != 0 {
				p1 := asWindowP(*(*unsafe.Pointer)(unsafe.Add(ptr, 36)))
				p2 := p1.Field100()
				dsx = p2.Size().Y
			}
			if data.Text() != "" {
				dy = 4
			}
			guiDrawBorders(gpos.X-3, gpos.Y-dy-3, sz.X-dsx+3, sz.Y+6)
			return
		case gui.StyleEntryField:
			v9 := gpos.X
			ptr := win.WidgetData

			sx := sz.X
			x := gpos.X
			dy := 0
			if text := data.Text(); text != "" {
				tsz := r.GetStringSizeWrapped(data.Font(), text, 0)
				x += tsz.X + 6
				sx -= tsz.X + 6
			}
			v14 := int(int16(*(*uint16)(unsafe.Add(ptr, 1042))))
			if int32(v14) > 0 && sx > v14 {
				sx = v14
				x = v9 + sz.X - v14
			}
			guiDrawBorders(x, gpos.Y+dy, sx, sz.Y)
			return
		}
	}
}

func guiDrawBorders(a1 int, a2 int, a3 int, a4 int) {
	r := noxClient.r
	v4 := a1 + a3
	v18 := a1
	v5 := a1 + 10
	v6 := a2 - 10
	v7 := a1 + a3 - 30
	v19 := a1 + a3
	v21 := a2 - 10
	v8 := a2 + a4 - 10
	if v5 <= v7 {
		for {
			r.DrawImageAt(guiBorderHorizontal, image.Pt(v5, v6))
			r.DrawImageAt(guiBorderHorizontal, image.Pt(v5, v8))
			v5 += 20
			if v5 > v7 {
				break
			}
		}
		v4 = v19
	}
	v9 := v4 - 10
	if v4-10-v5 >= 10 {
		r.DrawImageAt(guiBorderHorizontalShort, image.Pt(v5, v6))
		r.DrawImageAt(guiBorderHorizontalShort, image.Pt(v5, v8))
		v5 += 10
	}
	if v5 < v9 {
		v10 := int(uint32(v5) + (uint32(v9-v5+1) & 0xFFFFFFFE) - 10)
		r.DrawImageAt(guiBorderHorizontalShort, image.Pt(v10, v6))
		r.DrawImageAt(guiBorderHorizontalShort, image.Pt(v10, v8))
	}
	v12 := a2 + 10
	v15 := v18 - 10
	v20 := a2 + a4 - 30
	for v12 <= v20 {
		r.DrawImageAt(guiBorderVertical, image.Pt(v15, v12))
		r.DrawImageAt(guiBorderVertical, image.Pt(v9, v12))
		v12 += 20
	}
	if v8-v12 >= 10 {
		r.DrawImageAt(guiBorderVerticalShort, image.Pt(v15, v12))
		r.DrawImageAt(guiBorderVerticalShort, image.Pt(v9, v12))
		v12 += 10
	}
	if v12 < v8 {
		v16 := int(uint32(v12) + (uint32(v8-v12+1) & 0xFFFFFFFE) - 10)
		r.DrawImageAt(guiBorderVerticalShort, image.Pt(v15, v16))
		r.DrawImageAt(guiBorderVerticalShort, image.Pt(v9, v16))
	}
	r.DrawImageAt(guiBorderCornerUL, image.Pt(v15, v21))
	r.DrawImageAt(guiBorderCornerUR, image.Pt(v9, v21))
	r.DrawImageAt(guiBorderCornerLL, image.Pt(v15, v8))
	r.DrawImageAt(guiBorderCornerLR, image.Pt(v9, v8))
}

//export get_dword_5d4594_3799468
func get_dword_5d4594_3799468() int {
	return gui.Dword_5d4594_3799468
}

//export set_dword_5d4594_3799468
func set_dword_5d4594_3799468(v int) {
	gui.Dword_5d4594_3799524 = v
}

//export nox_window_new_go
func nox_window_new_go(par *C.nox_window, flags, a3, a4, w, h C.int, fnc unsafe.Pointer) *C.nox_window {
	return (*C.nox_window)(gui.NewWindowRaw(asWindow(par), gui.StatusFlags(flags), int(a3), int(a4), int(w), int(h), gui.WrapWindowFuncC(fnc)).C())
}

//export nox_xxx_wndGetID_46B0A0
func nox_xxx_wndGetID_46B0A0(win *C.nox_window) C.int {
	if win == nil {
		return -2
	}
	return C.int(asWindow(win).ID())
}

//export nox_xxx_wndSetID_46B080
func nox_xxx_wndSetID_46B080(win *C.nox_window, id C.int) C.int {
	if win == nil {
		return -2
	}
	win.id = C.int(id)
	return 0
}

//export nox_window_set_all_funcs_go
func nox_window_set_all_funcs_go(p *C.nox_window, a2 unsafe.Pointer, draw unsafe.Pointer, tooltip unsafe.Pointer) C.int {
	if p == nil {
		return -2
	}
	win := asWindow(p)
	win.SetFunc93(gui.WrapWindowFuncC(a2))
	win.SetDraw(gui.WrapWindowDrawFuncC(draw))
	win.SetTooltipFunc(tooltip)
	return 0
}

//export nox_xxx_wndSetWindowProc_46B300_go
func nox_xxx_wndSetWindowProc_46B300_go(win *C.nox_window, fnc unsafe.Pointer) C.int {
	if win == nil {
		return -2
	}
	asWindow(win).SetFunc93(gui.WrapWindowFuncC(fnc))
	return 0
}

//export nox_xxx_wndSetProc_46B2C0_go
func nox_xxx_wndSetProc_46B2C0_go(win *C.nox_window, fnc unsafe.Pointer) C.int {
	if win == nil {
		return -2
	}
	asWindow(win).SetFunc94(gui.WrapWindowFuncC(fnc))
	return 0
}

//export nox_xxx_wndSetDrawFn_46B340_go
func nox_xxx_wndSetDrawFn_46B340_go(win *C.nox_window, fnc unsafe.Pointer) C.int {
	if win == nil {
		return -2
	}
	asWindow(win).SetDraw(gui.WrapWindowDrawFuncC(fnc))
	return 0
}

//export nox_gui_winSetFunc96_46B070
func nox_gui_winSetFunc96_46B070(win *C.nox_window, fnc unsafe.Pointer) {
	asWindow(win).SetTooltipFunc(fnc)
}

//export nox_xxx_wndSetRectColor2MB_46AFE0
func nox_xxx_wndSetRectColor2MB_46AFE0(win *C.nox_window, a2 C.int) C.int {
	if win == nil {
		return -2
	}
	// TODO: not sure if the color format is correct
	asWindow(win).DrawData().SetBackgroundColor(noxcolor.RGBA5551(a2))
	return 0
}

//export nox_window_call_field_94_fnc
func nox_window_call_field_94_fnc(p *C.nox_window, a2, a3, a4 C.int, file *C.char, line C.int) C.int {
	if p == nil {
		return 0
	}
	if guiDebug {
		guiLog.Printf("nox_window_call_field_94(%p, %x, %x, %x): %s:%d", p, a2, a3, a4, GoString(file), line)
	}
	r := asWindow(p).Func94(gui.AsWindowEvent(int(a2), uintptr(a3), uintptr(a4)))
	if r == nil {
		return 0
	}
	return C.int(r.EventRespC())
}

//export nox_window_call_field_93
func nox_window_call_field_93(p *C.nox_window, a2, a3, a4 C.int) C.int {
	if p == nil {
		return 0
	}
	r := asWindow(p).Func93(gui.AsWindowEvent(int(a2), uintptr(a3), uintptr(a4)))
	if r == nil {
		return 0
	}
	return C.int(r.EventRespC())
}

//export nox_xxx_wndGetChildByID_46B0C0
func nox_xxx_wndGetChildByID_46B0C0(root *C.nox_window, id C.int) *C.nox_window {
	return (*C.nox_window)(asWindow(root).ChildByID(uint(id)).C())
}

//export nox_xxx_windowDestroyMB_46C4E0
func nox_xxx_windowDestroyMB_46C4E0(a1 *C.nox_window) C.int {
	win := asWindow(a1)
	if win == nil {
		return -2
	}
	win.Destroy()
	return 0
}

//export nox_window_set_hidden
func nox_window_set_hidden(p *C.nox_window, hidden C.int) C.int {
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
func nox_xxx_wndShowModalMB_46A8C0(p *C.nox_window) C.int {
	return C.int(gui.Nox_xxx_wndShowModalMB(asWindow(p)))
}

//export nox_window_setPos_46A9B0
func nox_window_setPos_46A9B0(p *C.nox_window, x, y C.int) C.int {
	win := asWindow(p)
	if win == nil {
		return -2
	}
	win.SetPos(image.Point{X: int(x), Y: int(y)})
	return 0
}

//export wndIsShown_nox_xxx_wndIsShown_46ACC0
func wndIsShown_nox_xxx_wndIsShown_46ACC0(p *C.nox_window) C.int {
	if p == nil {
		return 1
	}
	win := asWindow(p)
	is := win.GetFlags().IsHidden()
	return C.int(bool2int(is))
}

func nox_xxx_wnd_46ABB0(win *gui.Window, v int) int {
	return int(C.nox_xxx_wnd_46ABB0((*C.nox_window)(win.C()), C.int(v)))
}

//export nox_xxx_wnd_46C6E0
func nox_xxx_wnd_46C6E0(p *C.nox_window) C.int {
	return C.int(gui.Nox_xxx_wnd46C6E0(asWindow(p)))
}

//export sub_46C690
func sub_46C690(p *C.nox_window) C.int {
	return C.int(gui.Sub46C690(asWindow(p)))
}
