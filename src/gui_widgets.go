package main

/*
#include "GAME2_2.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "win.h"
#include "client__gui__gadgets__listbox.h"
*/
import "C"
import (
	"unsafe"

	"nox/v1/client/gui"
	"nox/v1/common/alloc"
	noxcolor "nox/v1/common/color"
)

type guiWidgetData interface {
	cWidgetData() unsafe.Pointer
}

type rawWidgetData struct {
	Ptr unsafe.Pointer
}

func (d rawWidgetData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d.Ptr)
}

type radioButtonData C.nox_radioButton_data

func (d *radioButtonData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

type sliderData C.nox_slider_data

func (d *sliderData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

type scrollListBoxData C.nox_scrollListBox_data

func (d *scrollListBoxData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

type entryFieldData C.nox_entryField_data

func (d *entryFieldData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

type staticTextData C.nox_staticText_data

func (d *staticTextData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

func guiNewWidget(typ string, parent *Window, status int, px, py, w, h int, draw *WindowData, data guiWidgetData) *Window {
	draw.win = parent.C()
	iparent := unsafePtrToInt(unsafe.Pointer(parent.C()))
	udraw := unsafe.Pointer(draw.C())
	switch typ {
	case "PUSHBUTTON":
		draw.style |= C.int(gui.StylePushButton)
		return newButtonOrCheckbox(parent, status, px, py, w, h, draw)
	case "RADIOBUTTON":
		tdata, _ := data.(*radioButtonData)
		draw.style |= C.int(gui.StyleRadioButton)
		return newRadioButton(parent, status, px, py, w, h, draw, tdata)
	case "CHECKBOX":
		draw.style |= C.int(gui.StyleCheckBox)
		return newButtonOrCheckbox(parent, status, px, py, w, h, draw)
	case "VERTSLIDER":
		tdata, _ := data.(*sliderData)
		draw.style |= C.int(gui.StyleVertSlider)
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(unsafe.Pointer(tdata))))
	case "HORZSLIDER":
		tdata, _ := data.(*sliderData)
		draw.style |= C.int(gui.StyleHorizSlider)
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(unsafe.Pointer(tdata))))
	case "SCROLLLISTBOX":
		tdata, _ := data.(*scrollListBoxData)
		draw.style |= C.int(gui.StyleScrollListBox)
		return asWindow(C.nox_gui_newScrollListBox_4A4310(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.short)(unsafe.Pointer(tdata))))
	case "ENTRYFIELD":
		tdata, _ := data.(*entryFieldData)
		draw.style |= C.int(gui.StyleEntryField)
		return asWindow(C.nox_gui_newEntryField_488500(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.ushort)(unsafe.Pointer(tdata))))
	case "STATICTEXT":
		tdata, _ := data.(*staticTextData)
		draw.style |= C.int(gui.StyleStaticText)
		return asWindow(C.nox_gui_newStaticText_489300(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.uint)(unsafe.Pointer(tdata))))
	case "PROGRESSBAR":
		draw.style |= C.int(gui.StyleProgressBar)
		return asWindow(C.nox_gui_newProgressBar_4CAF10(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw)))
	}
	return nil
}

func tempDrawData() (*WindowData, func()) {
	p := alloc.Calloc(1, unsafe.Sizeof(WindowData{}))
	return (*WindowData)(p), func() {
		alloc.Free(p)
	}
}

func NewStaticText(par *Window, id uint, px, py, w, h int, f1, f2 bool, text string) *Window {
	draw, dfree := tempDrawData()
	defer dfree()
	*draw = *par.DrawData()

	draw.win = par.C()
	draw.style |= C.int(gui.StyleStaticText)
	status := winStatusSmoothText | winStatusNoFocus

	data := (*staticTextData)(alloc.Calloc(1, unsafe.Sizeof(staticTextData{})))
	defer alloc.Free(unsafe.Pointer(data))
	data.field_1 = C.uint(bool2int(f1))
	data.field_2 = C.uint(bool2int(f2))
	data.text = internWStr(text)

	iparent := unsafePtrToInt(unsafe.Pointer(par.C()))
	win := asWindow(C.nox_gui_newStaticText_489300(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h),
		(*C.uint)(unsafe.Pointer(draw)), (*C.uint)(unsafe.Pointer(data))))
	win.SetID(id)
	if par != nil {
		par.Func94(22, uintptr(id), 0)
	}
	return win
}

func NewHorizontalSlider(par *Window, id uint, px, py, w, h int, min, max int) *Window {
	draw, dfree := tempDrawData()
	defer dfree()
	*draw = *par.DrawData()

	draw.win = par.C()
	draw.style |= C.int(gui.StyleHorizSlider)
	draw.SetHighlightColor(gui.ColorTransparent)
	draw.SetDisabledColor(gui.ColorTransparent)
	draw.SetEnabledColor(noxcolor.RGBColor(230, 165, 65))
	draw.SetSelectedColor(noxcolor.RGBColor(230, 165, 65))
	status := winStatusEnabled | winStatusNoFocus

	data := (*sliderData)(alloc.Calloc(1, unsafe.Sizeof(sliderData{})))
	defer alloc.Free(unsafe.Pointer(data))
	data.field_0 = C.uint(min)
	data.field_1 = C.uint(max)
	data.field_2 = 0
	data.field_3 = 0

	iparent := unsafePtrToInt(unsafe.Pointer(par.C()))
	win := asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h),
		(*C.uint)(unsafe.Pointer(draw)), (*C.float)(unsafe.Pointer(data))))
	win.SetID(id)
	if par != nil {
		par.Func94(22, uintptr(id), 0)
	}
	return win
}

func newButtonOrCheckbox(parent *Window, status int, px, py, w, h int, draw *WindowData) *Window {
	st := draw.StyleFlags()
	if st.IsPushButton() {
		btn := newWindow(parent, status, px, py, w, h, C.nox_xxx_wndButtonProcPre_4A9250)
		if btn == nil {
			return nil
		}
		C.nox_xxx_wndButtonInit_4A8340(unsafePtrToInt(unsafe.Pointer(btn.C())))
		if draw.win == nil {
			draw.win = btn.C()
		}
		btn.CopyDrawData(draw)
		return btn
	} else if st.IsCheckBox() {
		btn := newWindow(parent, status, px, py, w, h, C.nox_xxx_wndCheckboxProcMB_4A92C0)
		if btn == nil {
			return nil
		}
		C.nox_xxx_wndCheckBoxInit_4A8E60(unsafePtrToInt(unsafe.Pointer(btn.C())))
		if draw.win == nil {
			draw.win = btn.C()
		}
		btn.CopyDrawData(draw)
		return btn
	}
	return nil
}

func newRadioButton(parent *Window, status int, px, py, w, h int, draw *WindowData, data *radioButtonData) *Window {
	if !draw.StyleFlags().IsRadioButton() {
		return nil
	}
	win := newWindow(parent, status, px, py, w, h, C.nox_xxx_wndRadioButtonProcPre_4A93C0)
	if win == nil {
		return nil
	}
	C.nox_xxx_wndRadioButtonSetAllFn_4A87E0(unsafePtrToInt(unsafe.Pointer(win.C())))
	if draw.win == nil {
		draw.win = win.C()
	}
	d := (*C.nox_radioButton_data)(alloc.Calloc(1, unsafe.Sizeof(C.nox_radioButton_data{})))
	if data != nil {
		d.field_0 = data.field_0
	}
	win.field_8 = C.uint(unsafePtrToInt(unsafe.Pointer(d)))
	win.CopyDrawData(draw)
	return win
}
