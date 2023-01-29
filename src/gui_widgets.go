package opennox

/*
#include "GAME2_2.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "client__gui__gadgets__listbox.h"
*/
import "C"
import (
	"image/color"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

type scrollListBoxData C.nox_scrollListBox_data

func (d *scrollListBoxData) CWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

var _ = [1]struct{}{}[1056-unsafe.Sizeof(gui.EntryFieldData{})]

func guiNewWidget(g *gui.GUI, typ string, parent *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, data gui.WidgetData) *gui.Window {
	draw.Window = parent
	iparent := unsafePtrToInt(unsafe.Pointer(parent.C()))
	udraw := unsafe.Pointer(draw.C())
	switch typ {
	case "PUSHBUTTON":
		draw.Style |= gui.StylePushButton
		return newButtonOrCheckbox(g, parent, status, px, py, w, h, draw)
	case "RADIOBUTTON":
		tdata, _ := data.(*gui.RadioButtonData)
		draw.Style |= gui.StyleRadioButton
		return newRadioButton(g, parent, status, px, py, w, h, draw, tdata)
	case "CHECKBOX":
		draw.Style |= gui.StyleCheckBox
		return newButtonOrCheckbox(g, parent, status, px, py, w, h, draw)
	case "VERTSLIDER":
		tdata, _ := data.(*gui.SliderData)
		draw.Style |= gui.StyleVertSlider
		return asWindow(C.nox_gui_newSlider_4B4EE0(C.int(iparent), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(unsafe.Pointer(tdata))))
	case "HORZSLIDER":
		tdata, _ := data.(*gui.SliderData)
		draw.Style |= gui.StyleHorizSlider
		return asWindow(C.nox_gui_newSlider_4B4EE0(C.int(iparent), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(unsafe.Pointer(tdata))))
	case "SCROLLLISTBOX":
		tdata, _ := data.(*scrollListBoxData)
		draw.Style |= gui.StyleScrollListBox
		return nox_gui_newScrollListBox_4A4310(parent, status, px, py, w, h, draw, tdata)
	case "ENTRYFIELD":
		tdata, _ := data.(*gui.EntryFieldData)
		draw.Style |= gui.StyleEntryField
		return nox_gui_newEntryField_488500(parent, status, px, py, w, h, draw, tdata)
	case "STATICTEXT":
		tdata, _ := data.(*gui.StaticTextData)
		draw.Style |= gui.StyleStaticText
		return g.NewStaticTextRaw(parent, status, px, py, w, h, draw, tdata)
	case "PROGRESSBAR":
		draw.Style |= gui.StyleProgressBar
		return asWindow(C.nox_gui_newProgressBar_4CAF10(C.int(iparent), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw)))
	}
	return nil
}

func nox_gui_newScrollListBox_4A4310(par *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, tdata *scrollListBoxData) *gui.Window {
	return asWindow((*C.nox_window)(C.nox_gui_newScrollListBox_4A4310((*C.nox_window)(par.C()), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), C.int(dataPtrToInt(draw)), (*C.nox_scrollListBox_data)(unsafe.Pointer(tdata)))))
}

func nox_gui_newEntryField_488500(par *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, tdata *gui.EntryFieldData) *gui.Window {
	return asWindow((*C.nox_window)(C.nox_gui_newEntryField_488500((*C.nox_window)(par.C()), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), C.int(dataPtrToInt(draw)), (*C.ushort)(unsafe.Pointer(tdata)))))
}

//export nox_gui_newStaticText_489300
func nox_gui_newStaticText_489300(par *C.nox_window, status C.int, px, py, w, h C.int, draw *C.nox_window_data, data *C.nox_staticText_data) *C.nox_window {
	return (*C.nox_window)(noxClient.GUI.NewStaticTextRaw(asWindow(par), gui.StatusFlags(status), int(px), int(py), int(w), int(h), asWindowData(draw), (*gui.StaticTextData)(unsafe.Pointer(data))).C())
}

//export nox_xxx_wndStaticDrawNoImage_488D00
func nox_xxx_wndStaticDrawNoImage_488D00(win *C.nox_window, draw *C.nox_window_data) int {
	return gui.StaticTextDrawNoImage(asWindow(win), asWindowData(draw))
}

func NewHorizontalSlider(par *gui.Window, id uint, px, py, w, h int, min, max int) *gui.Window {
	draw, dfree := gui.NewWindowData()
	defer dfree()
	*draw = *par.DrawData()

	draw.Window = par
	draw.Style |= gui.StyleHorizSlider
	draw.SetHighlightColor(color.Transparent)
	draw.SetDisabledColor(color.Transparent)
	draw.SetEnabledColor(noxcolor.RGB5551Color(230, 165, 65))
	draw.SetSelectedColor(noxcolor.RGB5551Color(230, 165, 65))
	status := gui.StatusEnabled | gui.StatusNoFocus

	data, dataFree := alloc.New(gui.SliderData{})
	defer dataFree()
	data.Min = uint32(min)
	data.Max = uint32(max)
	data.Field2 = 0
	data.Field3 = 0

	iparent := unsafePtrToInt(unsafe.Pointer(par.C()))
	win := asWindow(C.nox_gui_newSlider_4B4EE0(C.int(iparent), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h),
		(*C.uint)(unsafe.Pointer(draw)), (*C.float)(unsafe.Pointer(data))))
	win.SetID(id)
	if par != nil {
		par.Func94(gui.WindowNewChild{ID: id})
	}
	return win
}

func NewCheckbox(g *gui.GUI, par *gui.Window, id uint, px, py, w, h int, text string) *gui.Window {
	draw, dfree := gui.NewWindowData()
	defer dfree()
	*draw = *par.DrawData()

	draw.Window = par
	draw.Style = gui.StyleCheckBox | gui.StyleMouseTrack
	draw.SetHighlightColor(noxcolor.RGB5551Color(192, 128, 128))
	draw.SetTextColor(noxcolor.RGB5551Color(240, 180, 42))
	draw.SetText(text)
	draw.SetBackgroundImage(nox_xxx_gLoadImg("UICheckBox"))
	draw.SetSelectedImage(nox_xxx_gLoadImg("UICheckBoxLit"))
	draw.SetDisabledImage(nox_xxx_gLoadImg("UICheckBox"))
	draw.SetEnabledImage(nil)
	draw.SetHighlightImage(nil)
	status := gui.StatusEnabled | gui.StatusImage | gui.StatusNoFocus

	win := newButtonOrCheckbox(g, par, status, px, py, w, h, draw)
	win.SetID(id)
	if par != nil {
		par.Func94(gui.WindowNewChild{ID: id})
	}
	return win
}

func NewRadioButton(g *gui.GUI, par *gui.Window, id uint, px, py, w, h int, group int, text string) *gui.Window {
	draw, dfree := gui.NewWindowData()
	defer dfree()

	*draw = *par.DrawData()

	draw.Window = par
	draw.Style = gui.StyleRadioButton | gui.StyleMouseTrack
	draw.SetTextColor(noxcolor.RGB5551Color(240, 180, 42))
	draw.SetText(text)
	draw.SetBackgroundImage(nox_xxx_gLoadImg("UIRadio"))
	draw.SetSelectedImage(nox_xxx_gLoadImg("UIRadioLit"))
	draw.SetDisabledImage(nox_xxx_gLoadImg("UIRadio"))
	draw.SetEnabledImage(nil)
	draw.SetHighlightImage(nil)
	draw.SetGroup(group)
	status := gui.StatusEnabled | gui.StatusToggle | gui.StatusImage | gui.StatusSmoothText | gui.StatusNoFocus

	rdata, rfree := alloc.New(gui.RadioButtonData{})
	defer rfree()

	win := newRadioButton(g, par, status, px, py, w, h, draw, rdata)
	win.SetID(id)
	if par != nil {
		par.Func94(gui.WindowNewChild{ID: id})
	}
	return win
}

func newButtonOrCheckbox(g *gui.GUI, parent *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData) *gui.Window {
	st := draw.Style
	if st.IsPushButton() {
		btn := g.NewWindowRaw(parent, status, px, py, w, h, gui.WrapFuncC(C.nox_xxx_wndButtonProcPre_4A9250))
		if btn == nil {
			return nil
		}
		C.nox_xxx_wndButtonInit_4A8340(C.int(unsafePtrToInt(unsafe.Pointer(btn.C()))))
		if draw.Window == nil {
			draw.Window = btn
		}
		btn.CopyDrawData(draw)
		return btn
	} else if st.IsCheckBox() {
		btn := g.NewWindowRaw(parent, status, px, py, w, h, gui.WrapFuncC(C.nox_xxx_wndCheckboxProcMB_4A92C0))
		if btn == nil {
			return nil
		}
		C.nox_xxx_wndCheckBoxInit_4A8E60(C.int(unsafePtrToInt(unsafe.Pointer(btn.C()))))
		if draw.Window == nil {
			draw.Window = btn
		}
		btn.CopyDrawData(draw)
		return btn
	}
	return nil
}

func newRadioButton(g *gui.GUI, parent *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, data *gui.RadioButtonData) *gui.Window {
	if !draw.Style.IsRadioButton() {
		return nil
	}
	win := g.NewWindowRaw(parent, status, px, py, w, h, gui.WrapFuncC(C.nox_xxx_wndRadioButtonProcPre_4A93C0))
	if win == nil {
		return nil
	}
	C.nox_xxx_wndRadioButtonSetAllFn_4A87E0(C.int(unsafePtrToInt(unsafe.Pointer(win.C()))))
	if draw.Window == nil {
		draw.Window = win
	}
	d, _ := alloc.New(gui.RadioButtonData{})
	if data != nil {
		d.Field0 = data.Field0
	}
	win.WidgetData = unsafe.Pointer(d)
	win.CopyDrawData(draw)
	return win
}
