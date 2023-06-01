package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var _ = [1]struct{}{}[524-unsafe.Sizeof(gui.ScrollListBoxItem{})]
var _ = [1]struct{}{}[56-unsafe.Sizeof(gui.ScrollListBoxData{})]
var _ = [1]struct{}{}[1056-unsafe.Sizeof(gui.EntryFieldData{})]

// nox_gui_newStaticText_489300
func nox_gui_newStaticText_489300(par *nox_window, status int32, px, py, w, h int32, draw *nox_window_data, data *nox_staticText_data) *nox_window {
	return (*nox_window)(GetClient().Cli().GUI.NewStaticTextRaw(asWindow(par), gui.StatusFlags(status), int(px), int(py), int(w), int(h), asWindowData(draw), (*gui.StaticTextData)(unsafe.Pointer(data))).C())
}

// nox_xxx_wndStaticDrawNoImage_488D00
func nox_xxx_wndStaticDrawNoImage_488D00(win *nox_window, draw *nox_window_data) int {
	return gui.StaticTextDrawNoImage(asWindow(win), asWindowData(draw))
}

func Nox_gui_newScrollListBox_4A4310(par *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, tdata *gui.ScrollListBoxData) *gui.Window {
	return asWindow((*nox_window)(nox_gui_newScrollListBox_4A4310((*nox_window)(par.C()), nox_window_flags(status), px, py, w, h, int32(uintptr(draw.C())), (*nox_scrollListBox_data)(unsafe.Pointer(tdata)))))
}

func Nox_gui_newEntryField_488500(par *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, tdata *gui.EntryFieldData) *gui.Window {
	return asWindow((*nox_window)(nox_gui_newEntryField_488500((*nox_window)(par.C()), nox_window_flags(status), px, py, w, h, int32(uintptr(draw.C())), (*uint16)(unsafe.Pointer(tdata)))))
}

func Nox_gui_newSlider_4B4EE0(par *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, tdata *gui.SliderData) *gui.Window {
	return asWindow((*nox_window)(nox_gui_newSlider_4B4EE0(int32(uintptr(par.C())), nox_window_flags(status), px, py, w, h, (*uint32)(draw.C()), (*float32)(unsafe.Pointer(tdata)))))
}

func Nox_gui_newProgressBar_4CAF10(par *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData) *gui.Window {
	return asWindow((*nox_window)(nox_gui_newProgressBar_4CAF10(int32(uintptr(par.C())), nox_window_flags(status), px, py, w, h, (*uint32)(draw.C()))))
}

func Nox_xxx_wndButtonInit_4A8340(btn *gui.Window) {
	nox_xxx_wndButtonInit_4A8340(int32(uintptr(btn.C())))
}

func Nox_xxx_wndCheckBoxInit_4A8E60(btn *gui.Window) {
	nox_xxx_wndCheckBoxInit_4A8E60(int32(uintptr(btn.C())))
}

func Nox_xxx_wndRadioButtonSetAllFn_4A87E0(win *gui.Window) {
	nox_xxx_wndRadioButtonSetAllFn_4A87E0(int32(uintptr(win.C())))
}

var (
	Nox_xxx_wndButtonProcPre_4A9250      = gui.WrapFunc(nox_xxx_wndButtonProcPre_4A9250)
	Nox_xxx_wndCheckboxProcMB_4A92C0     = gui.WrapFunc(nox_xxx_wndCheckboxProcMB_4A92C0)
	Nox_xxx_wndRadioButtonProcPre_4A93C0 = gui.WrapFunc(nox_xxx_wndRadioButtonProcPre_4A93C0)
)
