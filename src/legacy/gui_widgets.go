package legacy

/*
#include "GAME2_2.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "client__gui__gadgets__listbox.h"
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

var _ = [1]struct{}{}[524-unsafe.Sizeof(gui.ScrollListBoxItem{})]
var _ = [1]struct{}{}[56-unsafe.Sizeof(gui.ScrollListBoxData{})]
var _ = [1]struct{}{}[1056-unsafe.Sizeof(gui.EntryFieldData{})]

var (
	NewButtonOrCheckbox               func(parent *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData) *gui.Window
	Sub_4B5700                        func(win *gui.Window, bg, dis, en, sel, hl noxrender.ImageHandle)
	Nox_xxx_wndButtonProc_4A7F50      func(win *gui.Window, e gui.WindowEvent) gui.WindowEventResp
	Nox_xxx_wndButtonDrawNoImg_4A81D0 func(win *gui.Window, draw *gui.WindowData) int
)

//export nox_gui_newStaticText_489300
func nox_gui_newStaticText_489300(par *nox_window, status C.int, px, py, w, h C.int, draw *C.nox_window_data, data *C.nox_staticText_data) *nox_window {
	return (*nox_window)(GetClient().Cli().GUI.NewStaticTextRaw(asWindow(par), gui.StatusFlags(status), int(px), int(py), int(w), int(h), asWindowData(draw), (*gui.StaticTextData)(unsafe.Pointer(data))).C())
}

//export nox_xxx_wndStaticDrawNoImage_488D00
func nox_xxx_wndStaticDrawNoImage_488D00(win *nox_window, draw *C.nox_window_data) int {
	return gui.StaticTextDrawNoImage(asWindow(win), asWindowData(draw))
}

//export nox_gui_newButtonOrCheckbox_4A91A0
func nox_gui_newButtonOrCheckbox_4A91A0(parent *nox_window, a2, a3, a4, a5, a6 C.int, draw *C.nox_window_data) *nox_window {
	return (*nox_window)(NewButtonOrCheckbox(asWindow(parent), gui.StatusFlags(a2), int(a3), int(a4), int(a5), int(a6), asWindowData(draw)).C())
}

//export sub_4B5700
func sub_4B5700(win *nox_window, bg, dis, en, sel, hl unsafe.Pointer) {
	Sub_4B5700(asWindow(win), noxrender.ImageHandle(bg), noxrender.ImageHandle(dis), noxrender.ImageHandle(en), noxrender.ImageHandle(sel), noxrender.ImageHandle(hl))
}

//export nox_xxx_wndButtonProc_4A7F50
func nox_xxx_wndButtonProc_4A7F50(win *nox_window, a1, a2, a3 C.int) C.int {
	return C.int(gui.EventRespInt(Nox_xxx_wndButtonProc_4A7F50(asWindow(win), gui.AsWindowEvent(int(a1), uintptr(a2), uintptr(a3)))))
}

//export nox_xxx_wndButtonDrawNoImg_4A81D0
func nox_xxx_wndButtonDrawNoImg_4A81D0(win *nox_window, draw *C.nox_window_data) int {
	return Nox_xxx_wndButtonDrawNoImg_4A81D0(asWindow(win), asWindowData(draw))
}

func Nox_gui_newScrollListBox_4A4310(par *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, tdata *gui.ScrollListBoxData) *gui.Window {
	return asWindow((*nox_window)(C.nox_gui_newScrollListBox_4A4310((*nox_window)(par.C()), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), C.int(uintptr(draw.C())), (*C.nox_scrollListBox_data)(unsafe.Pointer(tdata)))))
}

func Nox_gui_newEntryField_488500(par *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, tdata *gui.EntryFieldData) *gui.Window {
	return asWindow((*nox_window)(C.nox_gui_newEntryField_488500((*nox_window)(par.C()), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), C.int(uintptr(draw.C())), (*C.ushort)(unsafe.Pointer(tdata)))))
}

func Nox_gui_newSlider_4B4EE0(par *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, tdata *gui.SliderData) *gui.Window {
	return asWindow((*nox_window)(C.nox_gui_newSlider_4B4EE0(C.int(uintptr(par.C())), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(draw.C()), (*C.float)(unsafe.Pointer(tdata)))))
}

func Nox_gui_newProgressBar_4CAF10(par *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData) *gui.Window {
	return asWindow((*nox_window)(C.nox_gui_newProgressBar_4CAF10(C.int(uintptr(par.C())), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(draw.C()))))
}

func Nox_xxx_wndRadioButtonSetAllFn_4A87E0(win *gui.Window) {
	C.nox_xxx_wndRadioButtonSetAllFn_4A87E0(C.int(uintptr(win.C())))
}

var (
	Nox_xxx_wndRadioButtonProcPre_4A93C0 = gui.WrapFuncC(C.nox_xxx_wndRadioButtonProcPre_4A93C0)
)
