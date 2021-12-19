package nox

/*
#include "GAME1_3.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "client__gui__guicon.h"
#include "win.h"

extern nox_window* dword_5d4594_1064896;
extern nox_window_ref* nox_win_1064912;

extern unsigned int nox_client_renderGUI_80828;
extern unsigned int nox_xxx_xxxRenderGUI_587000_80832;

int nox_gui_console_Enter_450FD0();
*/
import "C"
import (
	"context"
	"image"
	"os"
	"unsafe"

	"golang.org/x/image/font"

	"nox/v1/client/gui"
	"nox/v1/client/input"
	noxcolor "nox/v1/common/color"
	"nox/v1/common/keybind"
	"nox/v1/common/log"
	"nox/v1/common/strman"
	"nox/v1/common/types"
)

var (
	guiLog                       = log.New("gui")
	guiDebug                     = os.Getenv("NOX_DEBUG_GUI") == "true"
	nox_win_unk3                 *Window
	nox_win_activeWindow_1064900 *Window
	nox_win_1064916              *Window
	nox_win_freeList             *Window // dword_5d4594_1064896
)

func enableGUIDrawing(enable bool) {
	if enable {
		// TODO: might be a bitfield
		C.nox_client_renderGUI_80828 = 1
		C.nox_xxx_xxxRenderGUI_587000_80832 = 1
	} else {
		C.nox_client_renderGUI_80828 = 0
		C.nox_xxx_xxxRenderGUI_587000_80832 = 0
	}
}

//export nox_xxx_wndGetFocus_46B4F0
func nox_xxx_wndGetFocus_46B4F0() *C.nox_window {
	return nox_win_cur_focused.C()
}

//export nox_xxx_windowFocus_46B500
func nox_xxx_windowFocus_46B500(win *C.nox_window) C.int {
	guiFocus(asWindow(win))
	return 0
}

//export nox_client_getWin1064916_46C720
func nox_client_getWin1064916_46C720() *C.nox_window {
	return nox_win_1064916.C()
}

//export nox_xxx_wndSetCaptureMain_46ADC0
func nox_xxx_wndSetCaptureMain_46ADC0(win *C.nox_window) C.int {
	if nox_win_unk3 != nil {
		return -4
	}
	nox_win_unk3 = asWindow(win)
	return 0
}

//export nox_xxx_wndClearCaptureMain_46ADE0
func nox_xxx_wndClearCaptureMain_46ADE0(win *C.nox_window) C.int {
	if win == nox_win_unk3.C() {
		nox_win_unk3 = nil
	}
	return 0
}

//export nox_xxx_wndGetCaptureMain_46AE00
func nox_xxx_wndGetCaptureMain_46AE00() *C.nox_window {
	return nox_win_unk3.C()
}

func asWindowData(data *C.nox_window_data) *WindowData {
	return (*WindowData)(unsafe.Pointer(data))
}

type WindowData C.nox_window_data

func (d *WindowData) C() *C.nox_window_data {
	return (*C.nox_window_data)(unsafe.Pointer(d))
}

func (d *WindowData) Field0() uint32 {
	return uint32(d.field_0)
}

func (d *WindowData) Field0Set(flag uint32, v bool) {
	if v {
		d.field_0 |= C.uint(flag)
	} else {
		d.field_0 &^= C.uint(flag)
	}
}

func (d *WindowData) Group() int {
	return int(d.group)
}

func (d *WindowData) SetGroup(v int) {
	d.group = C.int(v)
}

func (d *WindowData) StyleFlags() gui.StyleFlags {
	return gui.StyleFlags(d.style)
}

func (d *WindowData) SetStyleFlags(v gui.StyleFlags) {
	d.style = C.int(v)
}

func (d *WindowData) Status() gui.StatusFlags {
	return gui.StatusFlags(d.status)
}

func (d *WindowData) SetStatus(v gui.StatusFlags) {
	d.status = C.int(v)
}

func (d *WindowData) Window() *Window {
	return asWindow(d.win)
}

func (d *WindowData) Text() string {
	return GoWString(&d.text[0])
}

func (d *WindowData) SetText(s string) {
	n := len(d.text)
	WStrCopy(&d.text[0], n, s)
	d.text[n-1] = 0
}

func (d *WindowData) BackgroundImage() *Image {
	return asImageP(d.bg_image)
}

func (d *WindowData) SetBackgroundImage(p *Image) {
	d.bg_image = unsafe.Pointer(p.C())
}

func (d *WindowData) BackgroundColor() noxcolor.Color16 {
	return noxcolor.IntToColor(uint32(d.bg_color))
}

func (d *WindowData) SetBackgroundColor(cl noxcolor.Color16) {
	d.bg_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) EnabledImage() *Image {
	return asImageP(d.en_image)
}

func (d *WindowData) SetEnabledImage(p *Image) {
	d.en_image = unsafe.Pointer(p.C())
}

func (d *WindowData) EnabledColor() noxcolor.Color16 {
	return noxcolor.IntToColor(uint32(d.en_color))
}

func (d *WindowData) SetEnabledColor(cl noxcolor.Color16) {
	d.en_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) DisabledImage() *Image {
	return asImageP(d.dis_image)
}

func (d *WindowData) SetDisabledImage(p *Image) {
	d.dis_image = unsafe.Pointer(p.C())
}

func (d *WindowData) DisabledColor() noxcolor.Color16 {
	return noxcolor.IntToColor(uint32(d.dis_color))
}

func (d *WindowData) SetDisabledColor(cl noxcolor.Color16) {
	d.dis_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) HighlightImage() *Image {
	return asImageP(d.hl_image)
}

func (d *WindowData) SetHighlightImage(p *Image) {
	d.hl_image = unsafe.Pointer(p.C())
}

func (d *WindowData) HighlightColor() noxcolor.Color16 {
	return noxcolor.IntToColor(uint32(d.hl_color))
}

func (d *WindowData) SetHighlightColor(cl noxcolor.Color16) {
	d.hl_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) SelectedImage() *Image {
	return asImageP(d.sel_image)
}

func (d *WindowData) SetSelectedImage(p *Image) {
	d.sel_image = unsafe.Pointer(p.C())
}

func (d *WindowData) SelectedColor() noxcolor.Color16 {
	return noxcolor.IntToColor(uint32(d.sel_color))
}

func (d *WindowData) SetSelectedColor(cl noxcolor.Color16) {
	d.sel_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) TextColorRaw() uint32 {
	return uint32(d.text_color)
}

func (d *WindowData) TextColor() noxcolor.Color16 {
	return noxcolor.IntToColor(d.TextColorRaw())
}

func (d *WindowData) SetTextColor(cl noxcolor.Color16) {
	d.text_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) Font() font.Face {
	return asFont(d.font)
}

func (d *WindowData) FontC() unsafe.Pointer {
	return d.font
}

func (d *WindowData) SetFont(font unsafe.Pointer) {
	d.font = font
}

func (d *WindowData) ImagePoint() image.Point {
	return image.Point{
		X: int(d.img_px),
		Y: int(d.img_py),
	}
}

func (d *WindowData) SetImagePoint(p image.Point) {
	d.img_px = C.int(p.X)
	d.img_py = C.int(p.Y)
}

func (d *WindowData) Tooltip() string {
	return GoWString(&d.tooltip[0])
}

func (d *WindowData) SetTooltip(sm *strman.StringManager, s string) {
	n := len(d.tooltip)
	if CWLen(s) > n && sm != nil {
		s = sm.GetStringInFile("TooltipTooLong", "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\gamewin.c")
	}
	WStrCopy(&d.tooltip[0], n, s)
	d.tooltip[n-1] = 0
}

func (d *WindowData) SetDefaults(def gui.StyleDefaults) {
	d.SetEnabledColor(def.EnabledColor)
	d.SetHighlightColor(def.HighlightColor)
	d.SetDisabledColor(def.DisabledColor)
	d.SetBackgroundColor(def.BackgroundColor)
	d.SetSelectedColor(def.SelectedColor)
	d.SetTextColor(def.TextColor)
}

func DrawGUI() {
	// back layer (background and some UI parts)
	for win := nox_win_xxx1_first; win != nil; win = win.Next() {
		if win.Flags().Has(gui.StatusBelow) {
			win.drawRecursive()
		}
	}
	// middle layer
	for win := nox_win_xxx1_first; win != nil; win = win.Next() {
		if win.Flags().HasNone(gui.StatusBelow | gui.StatusAbove) {
			win.drawRecursive()
		}
	}
	// front layer
	for win := nox_win_xxx1_first; win != nil; win = win.Next() {
		if win.Flags().Has(gui.StatusAbove) {
			win.drawRecursive()
		}
	}
}

//export nox_gui_draw
func nox_gui_draw() {
	DrawGUI()
}

//export nox_color_rgb_4344A0
func nox_color_rgb_4344A0(r, g, b C.int) C.uint32_t {
	cl := noxcolor.RGBColor(byte(r), byte(g), byte(b))
	return C.uint32_t(noxcolor.ExtendColor16(cl))
}

//export nox_color_rgb_func
func nox_color_rgb_func(r, g, b C.uint8_t, p *C.uint32_t) {
	cl := noxcolor.RGBColor(byte(r), byte(g), byte(b))
	*p = C.uint32_t(noxcolor.ExtendColor16(cl))
}

//export nox_color_rgb_func_get
func nox_color_rgb_func_get() C.int {
	return C.int(noxcolor.GetMode())
}

func unsafePtrToInt(p unsafe.Pointer) C.int {
	return C.int(uintptr(p))
}

func dataPtrToInt(p *WindowData) C.int {
	return C.int(uintptr(unsafe.Pointer(p)))
}

//export nox_xxx_wndWddSetTooltip_46B000
func nox_xxx_wndWddSetTooltip_46B000(draw *C.nox_window_data, str *C.wchar_t) {
	d := asWindowData(draw)
	if str == nil {
		d.SetTooltip(strMan, "")
		return
	}
	d.SetTooltip(strMan, GoWString(str))
}

func nox_xxx_windowUpdateKeysMB_46B6B0(inp *input.Handler, key keybind.Key) {
	root := nox_win_cur_focused
	if root == nil {
		return
	}
	if key == 0 {
		return
	}
	if inp.GetKeyFlag(key) {
		return
	}
	ok := false
	for win := root; win != nil; win = win.Parent() {
		st := 1
		if inp.IsPressed(key) {
			st = 2
		}
		if win.Func93(21, uintptr(key), uintptr(st)) != 0 {
			ok = true
			break
		}
	}
	inp.SetKeyFlag(key, ok)
}

//export nox_xxx_consoleEditProc_450F40
func nox_xxx_consoleEditProc_450F40(a1 unsafe.Pointer, a2, a3, a4 C.int) C.int {
	if a2 != 21 {
		return C.nox_xxx_wndEditProc_487D70((*C.uint)(a1), a2, a3, a4)
	}
	if ctrlEvent.hasDefBinding(11, keybind.Key(a3)) {
		if a4 == 2 {
			C.nox_client_toggleConsole_451350()
		}
		return 1
	}
	if a3 == 1 {
		if a4 == 2 {
			C.nox_xxx_consoleEsc_49B7A0()
		}
	} else {
		if a3 != 28 {
			return C.nox_xxx_wndEditProc_487D70((*C.uint)(a1), a2, a3, a4)
		}
		if a4 == 2 {
			C.nox_gui_console_Enter_450FD0()
			return 1
		}
	}
	return 1
}

//var dword_5d4594_2618912 *noxKeyEventInt

func keyBindingsCheckActive(inp *input.Handler) int {
	if C.sub_46A4A0() != 0 {
		return 1
	}
	for _, key := range inp.KeyboardKeys() {
		//dword_5d4594_2618912 = p
		if !inp.GetKeyFlag(key) && !inp.IsPressed(key) && !nox_xxx_guiCursor_477600() {
			if noxConsole.ExecMacros(context.Background(), key) {
				inp.SetKeyFlag(key, true)
			}
		}
	}
	return 1
}

func sub_4281F0(p types.Point, r types.Rect) bool {
	return p.X >= r.Left && p.X <= r.Right && p.Y >= r.Top && p.Y <= r.Bottom
}

func freeAllWindowsInList() { // sub_46C200
	win := nox_win_freeList
	nox_win_freeList = nil
	for win != nil {
		prev := win.Prev()
		win.prev = nil
		if nox_win_unk3 == win {
			nox_win_unk3 = nil
		}
		if nox_win_cur_focused == win {
			guiFocus(nil)
		}
		if C.nox_win_1064912 != nil && win.C() == C.nox_win_1064912.win {
			C.nox_xxx_wnd_46C6E0(C.nox_win_1064912.win)
		}
		if nox_win_activeWindow_1064900 == win {
			nox_win_activeWindow_1064900 = nil
		}
		if nox_win_1064916 == win {
			nox_win_1064916 = nil
		}
		win.Func94(2, 0, 0)
		nox_alloc_window.FreeObjectFirst(unsafe.Pointer(win.C()))
		win = prev
	}
}

//export sub_46B120
func sub_46B120(a1, a2 *C.nox_window) C.int {
	return C.int(sub46B120(asWindow(a1), asWindow(a2)))
}

func sub46B120(win, par *Window) int {
	if win == nil {
		return -2
	}
	if win.Parent() != nil {
		sub_46B180(win)
	} else {
		nox_client_wndListXxxRemove_46A960(win)
	}
	if par != nil {
		win.setParent(par)
	} else {
		nox_client_wndListXxxAdd_46A920(win)
		win.parent = nil
	}
	return 0
}
