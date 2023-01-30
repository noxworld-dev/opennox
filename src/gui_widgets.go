package opennox

import (
	"image/color"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func guiNewWidget(g *gui.GUI, typ string, parent *gui.Window, status gui.StatusFlags, px, py, w, h int, draw *gui.WindowData, data gui.WidgetData) *gui.Window {
	draw.Window = parent
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
		return legacy.Nox_gui_newSlider_4B4EE0(parent, status, px, py, w, h, draw, tdata)
	case "HORZSLIDER":
		tdata, _ := data.(*gui.SliderData)
		draw.Style |= gui.StyleHorizSlider
		return legacy.Nox_gui_newSlider_4B4EE0(parent, status, px, py, w, h, draw, tdata)
	case "SCROLLLISTBOX":
		tdata, _ := data.(*gui.ScrollListBoxData)
		draw.Style |= gui.StyleScrollListBox
		return legacy.Nox_gui_newScrollListBox_4A4310(parent, status, px, py, w, h, draw, tdata)
	case "ENTRYFIELD":
		tdata, _ := data.(*gui.EntryFieldData)
		draw.Style |= gui.StyleEntryField
		return legacy.Nox_gui_newEntryField_488500(parent, status, px, py, w, h, draw, tdata)
	case "STATICTEXT":
		tdata, _ := data.(*gui.StaticTextData)
		draw.Style |= gui.StyleStaticText
		return g.NewStaticTextRaw(parent, status, px, py, w, h, draw, tdata)
	case "PROGRESSBAR":
		draw.Style |= gui.StyleProgressBar
		return legacy.Nox_gui_newProgressBar_4CAF10(parent, status, px, py, w, h, draw)
	}
	return nil
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
	win := legacy.Nox_gui_newSlider_4B4EE0(par, status, px, py, w, h, draw, data)
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
		btn := g.NewWindowRaw(parent, status, px, py, w, h, legacy.Nox_xxx_wndButtonProcPre_4A9250)
		if btn == nil {
			return nil
		}
		legacy.Nox_xxx_wndButtonInit_4A8340(btn)
		if draw.Window == nil {
			draw.Window = btn
		}
		btn.CopyDrawData(draw)
		return btn
	} else if st.IsCheckBox() {
		btn := g.NewWindowRaw(parent, status, px, py, w, h, legacy.Nox_xxx_wndCheckboxProcMB_4A92C0)
		if btn == nil {
			return nil
		}
		legacy.Nox_xxx_wndCheckBoxInit_4A8E60(btn)
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
	win := g.NewWindowRaw(parent, status, px, py, w, h, legacy.Nox_xxx_wndRadioButtonProcPre_4A93C0)
	if win == nil {
		return nil
	}
	legacy.Nox_xxx_wndRadioButtonSetAllFn_4A87E0(win)
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
