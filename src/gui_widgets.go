package opennox

/*
#include "GAME2_2.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "client__gui__gadgets__listbox.h"
*/
import "C"
import (
	"image"
	"image/color"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/alloc"
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

type radioButtonData struct {
	field0 uint32
}

func (d *radioButtonData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

type sliderData struct {
	min    uint32
	max    uint32
	field2 uint32
	field3 uint32
}

func (d *sliderData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

type scrollListBoxData C.nox_scrollListBox_data

func (d *scrollListBoxData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

var _ = [1]struct{}{}[1056-unsafe.Sizeof(entryFieldData{})]

type entryFieldData struct {
	text       [512]wchar_t
	field_1024 uint32
	field_1028 uint32
	field_1032 uint32
	field_1036 uint32
	field_1040 uint16
	field_1042 int16
	field_1044 uint32
	field_1048 uint32
	field_1052 uint32
}

func (d *entryFieldData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

type staticTextData struct {
	text   *wchar_t
	center uint32
	glow   uint32
}

func (d *staticTextData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

func guiNewWidget(typ string, parent *Window, status gui.StatusFlags, px, py, w, h int, draw *WindowData, data guiWidgetData) *Window {
	draw.win = parent.C()
	iparent := unsafePtrToInt(unsafe.Pointer(parent.C()))
	udraw := unsafe.Pointer(draw.C())
	switch typ {
	case "PUSHBUTTON":
		draw.style |= int32(gui.StylePushButton)
		return newButtonOrCheckbox(parent, status, px, py, w, h, draw)
	case "RADIOBUTTON":
		tdata, _ := data.(*radioButtonData)
		draw.style |= int32(gui.StyleRadioButton)
		return newRadioButton(parent, status, px, py, w, h, draw, tdata)
	case "CHECKBOX":
		draw.style |= int32(gui.StyleCheckBox)
		return newButtonOrCheckbox(parent, status, px, py, w, h, draw)
	case "VERTSLIDER":
		tdata, _ := data.(*sliderData)
		draw.style |= int32(gui.StyleVertSlider)
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(unsafe.Pointer(tdata))))
	case "HORZSLIDER":
		tdata, _ := data.(*sliderData)
		draw.style |= int32(gui.StyleHorizSlider)
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(unsafe.Pointer(tdata))))
	case "SCROLLLISTBOX":
		tdata, _ := data.(*scrollListBoxData)
		draw.style |= int32(gui.StyleScrollListBox)
		return nox_gui_newScrollListBox_4A4310(parent, status, px, py, w, h, draw, tdata)
	case "ENTRYFIELD":
		tdata, _ := data.(*entryFieldData)
		draw.style |= int32(gui.StyleEntryField)
		return nox_gui_newEntryField_488500(parent, status, px, py, w, h, draw, tdata)
	case "STATICTEXT":
		tdata, _ := data.(*staticTextData)
		draw.style |= int32(gui.StyleStaticText)
		return newStaticText(parent, status, px, py, w, h, draw, tdata)
	case "PROGRESSBAR":
		draw.style |= int32(gui.StyleProgressBar)
		return asWindow(C.nox_gui_newProgressBar_4CAF10(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw)))
	}
	return nil
}

func nox_gui_newScrollListBox_4A4310(par *Window, status gui.StatusFlags, px, py, w, h int, draw *WindowData, tdata *scrollListBoxData) *Window {
	return asWindow(C.nox_gui_newScrollListBox_4A4310(par.C(), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.nox_scrollListBox_data)(unsafe.Pointer(tdata))))
}

func nox_gui_newEntryField_488500(par *Window, status gui.StatusFlags, px, py, w, h int, draw *WindowData, tdata *entryFieldData) *Window {
	return asWindow(C.nox_gui_newEntryField_488500(par.C(), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.ushort)(unsafe.Pointer(tdata))))
}

func tempDrawData() (*WindowData, func()) {
	d, free := alloc.New(WindowData{})
	d.SetHighlightColor(noxcolor.RGB5551Color(255, 255, 255))
	d.SetTextColor(noxcolor.RGB5551Color(200, 200, 200))
	d.SetEnabledColor(color.Transparent)
	d.SetDisabledColor(color.Transparent)
	d.SetSelectedColor(color.Transparent)
	d.SetBackgroundColor(color.Transparent)
	return d, free
}

func NewStaticText(par *Window, id uint, px, py, w, h int, center, glow bool, text string) *Window {
	draw, dfree := tempDrawData()
	defer dfree()
	*draw = *par.DrawData()

	draw.win = par.C()
	draw.style |= int32(gui.StyleStaticText)
	status := gui.StatusSmoothText | gui.StatusNoFocus

	win := newStaticText(par, status, px, py, w, h, draw, &staticTextData{
		text:   internWStr(text),
		center: uint32(bool2int(center)),
		glow:   uint32(bool2int(glow)),
	})
	win.SetID(id)
	if par != nil {
		par.Func94(WindowNewChild{ID: id})
	}
	return win
}

//export nox_gui_newStaticText_489300
func nox_gui_newStaticText_489300(par *C.nox_window, status C.int, px, py, w, h C.int, draw *C.nox_window_data, data *C.nox_staticText_data) *C.nox_window {
	return newStaticText(asWindow(par), gui.StatusFlags(status), int(px), int(py), int(w), int(h), asWindowData(draw), (*staticTextData)(unsafe.Pointer(data))).C()
}

func newStaticText(par *Window, status gui.StatusFlags, px, py, w, h int, draw *WindowData, data *staticTextData) *Window { // nox_gui_newStaticText_489300
	style := draw.StyleFlags()
	style &= 0xFFFFFBFF
	draw.SetStyleFlags(style)
	if style&gui.StyleStaticText == 0 {
		return nil
	}
	win := newWindowRaw(par, status, px, py, w, h, nox_xxx_wndStaticProcPre_489390)
	if !win.Flags().Has(gui.StatusImage) {
		win.SetAllFuncs(nox_xxx_wndStaticProc_489420, nox_xxx_wndStaticDrawNoImage, nil)
	} else {
		win.SetAllFuncs(nox_xxx_wndStaticProc_489420, nox_xxx_wndStaticDrawWithImage_489550, nil)
	}
	if draw.win == nil {
		draw.win = win.C()
	}
	win.CopyDrawData(draw)
	wdata, _ := alloc.New(staticTextData{})
	*wdata = *data
	win.widget_data = unsafe.Pointer(wdata)
	return win
}

const (
	guiEventStaticTextPref    = 0x4000
	guiEventStaticTextSetText = guiEventStaticTextPref + 1
	guiEventStaticTextGetText = guiEventStaticTextPref + 2
)

func nox_xxx_wndStaticProcPre_489390(win *Window, e WindowEvent) WindowEventResp {
	switch e := e.(type) {
	case WindowDestroy:
		alloc.Free(win.widget_data)
		win.widget_data = nil
		return nil
	case *WindowEvent0x4001:
		data := (*staticTextData)(win.widget_data)
		if e.Str != "" {
			data.text = e.cStr()
		} else {
			data.text = nil
		}
		return nil
	}
	switch e.EventCode() {
	case guiEventStaticTextGetText:
		data := (*staticTextData)(win.widget_data)
		return RawEventResp(unsafe.Pointer(data.text))
	}
	return nil
}

func nox_xxx_wndStaticProc_489420(win *Window, ev WindowEvent) WindowEventResp {
	switch ev := ev.(type) {
	case WindowKeyPress:
		switch ev.Key {
		case keybind.KeyTab, keybind.KeyRight, keybind.KeyDown, keybind.KeyUp, keybind.KeyLeft:
			return RawEventResp(1)
		}
	}
	return nil
}

func nox_xxx_wndStaticDrawWithImage_489550(win *Window, draw *WindowData) int {
	r := noxClient.r

	data := (*staticTextData)(unsafe.Pointer(win.widget_data))

	wpos := win.GlobalPos()
	wsz := win.Size()
	fnt := draw.Font()
	fh := r.FontHeight(fnt)
	if win.Flags().Has(gui.StatusSmoothText) {
		r.SetTextSmooting(true)
	}
	if bg := draw.BackgroundImage(); bg != nil {
		r.DrawImageAt(bg, wpos.Add(draw.ImagePoint()))
	}
	var img *Image
	if win.Flags().Has(gui.StatusEnabled) {
		img = draw.EnabledImage()
	} else {
		img = draw.DisabledImage()
	}
	if img != nil {
		r.DrawImageAt(img, wpos.Add(draw.ImagePoint()))
	}
	if str := GoWString(data.text); str != "" {
		r.Data().SetTextColor(draw.TextColor())
		y0 := wpos.Y + wsz.Y/2 - fh/2
		if data.center != 0 {
			tsz := r.GetStringSizeWrapped(fnt, str, 0)
			x0 := wpos.X + (wsz.X-tsz.X)/2
			rect := image.Rect(x0, y0, x0+wsz.X, y0)
			r.DrawStringWrapped(fnt, str, rect)
		} else {
			x0 := wpos.X + 2
			rect := image.Rect(x0, y0, x0+wsz.X, y0)
			r.DrawStringWrapped(fnt, str, rect)
		}
	}
	r.SetTextSmooting(false)
	return 1
}

//export nox_xxx_wndStaticDrawNoImage_488D00
func nox_xxx_wndStaticDrawNoImage_488D00(win *C.nox_window, draw *C.nox_window_data) C.int {
	return C.int(nox_xxx_wndStaticDrawNoImage(asWindow(win), asWindowData(draw)))
}

func nox_xxx_wndStaticDrawNoImage(win *Window, draw *WindowData) int { // nox_xxx_wndStaticDrawNoImage_488D00
	r := noxClient.r
	fnt := draw.Font()

	wdata := (*staticTextData)(win.widget_data)
	highlight := draw.EnabledColor()
	wpos := win.GlobalPos()
	wsz := win.Size()
	x, y := wpos.X, wpos.Y
	w, h := wsz.X, wsz.Y
	if win.Flags().Has(gui.StatusSmoothText) {
		r.SetTextSmooting(true)
		defer r.SetTextSmooting(false)
	}
	borderColor := draw.EnabledColor()
	var bgColor color.Color
	if win.Flags().Has(gui.StatusEnabled) {
		if draw.Field0()&0x2 != 0 {
			borderColor = draw.HighlightColor()
		}
		bgColor = draw.BackgroundColor()
	} else {
		bgColor = draw.DisabledColor()
	}
	if draw.Field0()&0x4 != 0 {
		highlight = draw.SelectedColor()
	}
	if _, _, _, alpha := bgColor.RGBA(); alpha != 0 {
		r.DrawRectFilledOpaque(x+1, y+1, w-2, h-2, bgColor)
	}
	if _, _, _, alpha := borderColor.RGBA(); alpha != 0 {
		r.DrawBorder(x, y, w, h, borderColor)
	}
	text := GoWString(wdata.text)
	if text == "" {
		return 1
	}
	if _, _, _, alpha := draw.TextColor().RGBA(); alpha != 0 {
		r.Data().SetTextColor(draw.TextColor())
		sz := r.GetStringSizeWrapped(fnt, text, w)
		cy := y + (h-sz.Y)/2
		if wdata.center != 0 {
			if sz.Y > r.FontHeight(fnt) {
				dy := fnt.Metrics().CapHeight.Round()
				for i, line := range r.SplitStringWrapped(fnt, text, w) {
					if strings.TrimSpace(line) == "" {
						continue
					}
					sz := r.GetStringSizeWrapped(fnt, line, w)
					lx := x + (w-sz.X)/2
					ly := cy + dy*i
					if wdata.glow != 0 {
						r.Data().SetTextColor(highlight)
						r.DrawStringWrapped(fnt, line, image.Rect(lx-1, ly-1, lx-1+w, ly-1))
						r.DrawStringWrapped(fnt, line, image.Rect(lx+1, ly-1, lx+1+w, ly-1))
						r.DrawStringWrapped(fnt, line, image.Rect(lx-1, ly+1, lx-1+w, ly+1))
						r.DrawStringWrapped(fnt, line, image.Rect(lx+1, ly+1, lx+1+w, ly+1))
						r.Data().SetTextColor(draw.TextColor())
						r.DrawStringWrapped(fnt, line, image.Rect(lx, ly, lx+w, ly))
					} else {
						r.DrawStringWrapped(fnt, line, image.Rect(lx, ly, lx+w, ly))
					}
				}
			} else {
				x += (w - sz.X) / 2
				if wdata.glow != 0 {
					r.Data().SetTextColor(highlight)
					r.DrawStringWrapped(fnt, text, image.Rect(x-1, cy-1, x-1+w, cy-1))
					r.DrawStringWrapped(fnt, text, image.Rect(x+1, cy-1, x+1+w, cy-1))
					r.DrawStringWrapped(fnt, text, image.Rect(x-1, cy+1, x-1+w, cy+1))
					r.DrawStringWrapped(fnt, text, image.Rect(x+1, cy+1, x+1+w, cy+1))
					r.Data().SetTextColor(draw.TextColor())
					r.DrawStringWrapped(fnt, text, image.Rect(x, cy, x+w, cy))
				} else {
					r.DrawStringWrapped(fnt, text, image.Rect(x, cy, x+w, cy))
				}
			}
		} else if wdata.glow != 0 {
			r.Data().SetTextColor(highlight)
			r.DrawStringWrapped(fnt, text, image.Rect(x+1, cy-1, x+1+w, cy-1))
			r.DrawStringWrapped(fnt, text, image.Rect(x+3, cy-1, x+3+w, cy-1))
			r.DrawStringWrapped(fnt, text, image.Rect(x+1, cy+1, x+1+w, cy+1))
			r.DrawStringWrapped(fnt, text, image.Rect(x+3, cy+1, x+3+w, cy+1))
			r.Data().SetTextColor(draw.TextColor())
			r.DrawStringWrapped(fnt, text, image.Rect(x+2, cy, x+2+w, cy))
		} else {
			r.DrawStringWrapped(fnt, text, image.Rect(x+2, cy, x+2+w, cy))
		}
	}
	return 1
}

func NewHorizontalSlider(par *Window, id uint, px, py, w, h int, min, max int) *Window {
	draw, dfree := tempDrawData()
	defer dfree()
	*draw = *par.DrawData()

	draw.win = par.C()
	draw.style |= int32(gui.StyleHorizSlider)
	draw.SetHighlightColor(color.Transparent)
	draw.SetDisabledColor(color.Transparent)
	draw.SetEnabledColor(noxcolor.RGB5551Color(230, 165, 65))
	draw.SetSelectedColor(noxcolor.RGB5551Color(230, 165, 65))
	status := gui.StatusEnabled | gui.StatusNoFocus

	data, dataFree := alloc.New(sliderData{})
	defer dataFree()
	data.min = uint32(min)
	data.max = uint32(max)
	data.field2 = 0
	data.field3 = 0

	iparent := unsafePtrToInt(unsafe.Pointer(par.C()))
	win := asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h),
		(*C.uint)(unsafe.Pointer(draw)), (*C.float)(unsafe.Pointer(data))))
	win.SetID(id)
	if par != nil {
		par.Func94(WindowNewChild{ID: id})
	}
	return win
}

func NewCheckbox(par *Window, id uint, px, py, w, h int, text string) *Window {
	draw, dfree := tempDrawData()
	defer dfree()
	*draw = *par.DrawData()

	draw.win = par.C()
	draw.style = int32(gui.StyleCheckBox | gui.StyleMouseTrack)
	draw.SetHighlightColor(noxcolor.RGB5551Color(192, 128, 128))
	draw.SetTextColor(noxcolor.RGB5551Color(240, 180, 42))
	draw.SetText(text)
	draw.SetBackgroundImage(nox_xxx_gLoadImg("UICheckBox"))
	draw.SetSelectedImage(nox_xxx_gLoadImg("UICheckBoxLit"))
	draw.SetDisabledImage(nox_xxx_gLoadImg("UICheckBox"))
	draw.SetEnabledImage(nil)
	draw.SetHighlightImage(nil)
	status := gui.StatusEnabled | gui.StatusImage | gui.StatusNoFocus

	win := newButtonOrCheckbox(par, status, px, py, w, h, draw)
	win.SetID(id)
	if par != nil {
		par.Func94(WindowNewChild{ID: id})
	}
	return win
}

func NewRadioButton(par *Window, id uint, px, py, w, h int, group int, text string) *Window {
	draw, dfree := tempDrawData()
	defer dfree()

	*draw = *par.DrawData()

	draw.win = par.C()
	draw.style = int32(gui.StyleRadioButton | gui.StyleMouseTrack)
	draw.SetTextColor(noxcolor.RGB5551Color(240, 180, 42))
	draw.SetText(text)
	draw.SetBackgroundImage(nox_xxx_gLoadImg("UIRadio"))
	draw.SetSelectedImage(nox_xxx_gLoadImg("UIRadioLit"))
	draw.SetDisabledImage(nox_xxx_gLoadImg("UIRadio"))
	draw.SetEnabledImage(nil)
	draw.SetHighlightImage(nil)
	draw.SetGroup(group)
	status := gui.StatusEnabled | gui.StatusToggle | gui.StatusImage | gui.StatusSmoothText | gui.StatusNoFocus

	rdata, rfree := alloc.New(radioButtonData{})
	defer rfree()

	win := newRadioButton(par, status, px, py, w, h, draw, rdata)
	win.SetID(id)
	if par != nil {
		par.Func94(WindowNewChild{ID: id})
	}
	return win
}

func newButtonOrCheckbox(parent *Window, status gui.StatusFlags, px, py, w, h int, draw *WindowData) *Window {
	st := draw.StyleFlags()
	if st.IsPushButton() {
		btn := newWindowRaw(parent, status, px, py, w, h, wrapWindowFuncC(C.nox_xxx_wndButtonProcPre_4A9250))
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
		btn := newWindowRaw(parent, status, px, py, w, h, wrapWindowFuncC(C.nox_xxx_wndCheckboxProcMB_4A92C0))
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

func newRadioButton(parent *Window, status gui.StatusFlags, px, py, w, h int, draw *WindowData, data *radioButtonData) *Window {
	if !draw.StyleFlags().IsRadioButton() {
		return nil
	}
	win := newWindowRaw(parent, status, px, py, w, h, wrapWindowFuncC(C.nox_xxx_wndRadioButtonProcPre_4A93C0))
	if win == nil {
		return nil
	}
	C.nox_xxx_wndRadioButtonSetAllFn_4A87E0(unsafePtrToInt(unsafe.Pointer(win.C())))
	if draw.win == nil {
		draw.win = win.C()
	}
	d, _ := alloc.New(radioButtonData{})
	if data != nil {
		d.field0 = data.field0
	}
	win.widget_data = unsafe.Pointer(d)
	win.CopyDrawData(draw)
	return win
}
