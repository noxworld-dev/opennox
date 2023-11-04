package gui

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/input"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func NewCheckBoxImg(g *GUI, par *Window, id uint, px, py, w, h int, text string, bg, sel, dis *noxrender.Image) *Window {
	draw, dfree := NewWindowData()
	defer dfree()
	*draw = *par.DrawData()

	draw.Window = par
	draw.Style = StyleCheckBox | StyleMouseTrack
	draw.SetHighlightColor(noxcolor.RGB5551Color(192, 128, 128))
	draw.SetTextColor(noxcolor.RGB5551Color(240, 180, 42))
	draw.SetText(text)
	draw.SetBackgroundImage(bg)
	draw.SetSelectedImage(sel)
	draw.SetDisabledImage(dis)
	draw.SetEnabledImage(nil)
	draw.SetHighlightImage(nil)
	status := StatusEnabled | StatusImage | StatusNoFocus

	win := NewCheckBoxRaw(g, par, status, px, py, w, h, draw)
	win.SetID(id)
	if par != nil {
		par.Func94(WindowNewChild{ID: id})
	}
	return win
}

func NewCheckBoxRaw(g *GUI, parent *Window, status StatusFlags, px, py, w, h int, draw *WindowData) *Window {
	btn := g.NewWindowRaw(parent, status, px, py, w, h, nox_xxx_wndCheckboxProcMB_4A92C0)
	if btn == nil {
		return nil
	}
	nox_xxx_wndCheckBoxInit_4A8E60(btn)
	if draw.Window == nil {
		draw.Window = btn
	}
	btn.CopyDrawData(draw)
	return btn
}

func nox_xxx_wndCheckboxProcMB_4A92C0(win *Window, e WindowEvent) WindowEventResp {
	switch e := e.(type) {
	case WindowFocus:
		if !e {
			win.DrawData().Field0 &^= 0x2
		}
		// TODO
		p3, _ := e.EventArgsC()
		win.DrawData().Window.Func94(AsWindowEvent(0x4003, p3, uintptr(win.ID())))
		return RawEventResp(1)
	case *StaticTextSetText:
		win.DrawData().SetText(e.Str)
		return RawEventResp(0)
	default:
		return RawEventResp(0)
	}
}

func nox_xxx_wndCheckBoxInit_4A8E60(win *Window) {
	if !win.Flags.Has(StatusImage) {
		win.SetAllFuncs(nox_xxx_wndCheckBoxProc_4A8C00, nox_xxx_wndDrawCheckBoxNoImg_4A8EA0, nil)
	} else {
		win.SetAllFuncs(nox_xxx_wndCheckBoxProc_4A8C00, nox_xxx_wndDrawCheckBox_4A9050, nil)
	}
}

func nox_xxx_wndCheckBoxProc_4A8C00(win *Window, e WindowEvent) WindowEventResp {
	switch e := e.(type) {
	case WindowKeyPress:
		switch e.Key {
		case keybind.KeyTab, keybind.KeyRight, keybind.KeyDown, keybind.KeyUp, keybind.KeyLeft:
			return RawEventResp(1)
		case keybind.KeyEnter, keybind.KeySpace:
			if e.Pressed {
				win.DrawData().Window.Func94(AsWindowEvent(0x4007, uintptr(unsafe.Pointer(win)), 0))
				win.DrawData().Field0 ^= 4
			}
			return RawEventResp(1)
		default:
			return RawEventResp(0)
		}
	case *WindowMouseState:
		switch e.State {
		case input.NOX_MOUSE_LEFT_DOWN:
			return RawEventResp(1)
		case input.NOX_MOUSE_LEFT_DRAG_END, input.NOX_MOUSE_LEFT_UP:
			if (win.DrawData().Field0 & 2) == 0 {
				return RawEventResp(0)
			}
			a3, _ := e.EventArgsC()
			win.DrawData().Window.Func94(AsWindowEvent(0x4007, uintptr(unsafe.Pointer(win)), a3))
			win.DrawData().Field0 ^= 4
			return RawEventResp(1)
		case input.NOX_MOUSE_LEFT_PRESSED:
			a3, _ := e.EventArgsC()
			win.DrawData().Window.Func94(AsWindowEvent(0x4000, uintptr(unsafe.Pointer(win)), a3))
			return RawEventResp(1)
		default:
			return RawEventResp(0)
		}
	default:
		switch e.EventCode() {
		case 17:
			if win.DrawData().Style.Has(StyleMouseTrack) {
				win.DrawData().Field0 |= 0x2
				a3, _ := e.EventArgsC()
				win.DrawData().Window.Func94(AsWindowEvent(0x4005, uintptr(unsafe.Pointer(win)), a3))
				win.Focus()
			}
			return RawEventResp(1)
		case 18:
			if win.DrawData().Style.Has(StyleMouseTrack) {
				win.DrawData().Field0 &^= 0x2
				a3, _ := e.EventArgsC()
				win.DrawData().Window.Func94(AsWindowEvent(0x4006, uintptr(unsafe.Pointer(win)), a3))
			}
			return RawEventResp(1)
		default:
			return RawEventResp(0)
		}
	}
}

func nox_xxx_wndDrawCheckBoxNoImg_4A8EA0(win *Window, draw *WindowData) int {
	g := win.GUI()
	r := g.Render()
	borderCl := draw.EnabledColor()
	backCl := draw.BackgroundColor()
	pos := win.GlobalPos()
	x, y := pos.X, pos.Y
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(win), 4)))&8 != 0 {
		if draw.Field0&2 != 0 {
			borderCl = draw.HighlightColor()
		}
	} else {
		backCl = draw.DisabledColor()
	}
	x1 := x + 4
	y1 := y + win.SizeVal.Y/2 - 5
	if backCl.Color32() != noxcolor.Transparent32RGBA5551 {
		r.DrawRectFilledOpaque(x, y, win.SizeVal.X, win.SizeVal.Y, backCl)
	}
	if borderCl.Color32() != noxcolor.Transparent32RGBA5551 {
		r.DrawBorder(x1, y1, 10, 10, borderCl)
	}
	if draw.Field0&4 != 0 {
		if selCl := draw.SelectedColor(); selCl.Color32() != noxcolor.Transparent32RGBA5551 {
			r.DrawRectFilledOpaque(x1+1, y1+1, 8, 8, selCl)
			if borderCl.Color32() != noxcolor.Transparent32RGBA5551 {
				r.DrawVector(image.Pt(x1, y1), image.Pt(9, 9), borderCl)
				r.DrawVector(image.Pt(x1, y1+9), image.Pt(9, -9), borderCl)
			}
		}
	}
	text := draw.Text()
	textCl := draw.TextColor()
	if textCl.Color32() == noxcolor.Transparent32RGBA5551 {
		return 1
	}
	font := draw.Font()
	x2 := x1 + 14
	y2 := 5 - r.FontHeight(font)/2 + y1
	if win.Flags.Has(StatusSmoothText) {
		r.SetTextSmooting(true)
	}
	defer r.SetTextSmooting(false)
	r.Data().SetTextColor(textCl)
	pt := image.Pt(x2, y2)
	r.DrawStringWrapped(font, text, image.Rectangle{Min: pt, Max: pt.Add(image.Pt(win.SizeVal.X, 0))})
	return 1
}

func nox_xxx_wndDrawCheckBox_4A9050(win *Window, draw *WindowData) int {
	g := win.GUI()
	r := g.Render()
	v11 := r.Bag.AsImage(draw.EnImageHnd)
	a2 := r.Bag.AsImage(draw.BgImageHnd)
	pos := win.GlobalPos()
	x := pos.X
	y := pos.Y + win.SizeVal.Y/2
	if win.Flags&8 != 0 {
		if draw.Field0&2 != 0 {
			v11 = r.Bag.AsImage(draw.HlImageHnd)
		}
	} else {
		a2 = r.Bag.AsImage(draw.DisImageHnd)
	}
	x1 := x + 4
	y1 := y - 5
	if a2 != nil {
		r.DrawImage16(a2, image.Pt(x1+win.DrawData().ImgPtVal.X, y1+win.DrawData().ImgPtVal.Y))
	}
	if draw.Field0&0x4 != 0 {
		v7 := r.Bag.AsImage(draw.SelImageHnd)
		if v7 != nil {
			r.DrawImage16(v7, image.Pt(x1+win.DrawData().ImgPtVal.X, y1+win.DrawData().ImgPtVal.Y))
		}
	} else {
		if v11 != nil {
			r.DrawImage16(v11, image.Pt(x1+win.DrawData().ImgPtVal.X, y1+win.DrawData().ImgPtVal.Y))
		}
	}
	text := draw.Text()
	textCl := draw.TextColor()
	if textCl.Color32() == noxcolor.Transparent32RGBA5551 {
		return 1
	}
	font := draw.Font()
	x2 := x1 + 16
	y2 := 5 - r.FontHeight(font)/2 + y1
	if win.Flags.Has(StatusSmoothText) {
		r.SetTextSmooting(true)
	}
	defer r.SetTextSmooting(false)
	pt := image.Pt(x2, y2)
	r.Data().SetTextColor(textCl)
	r.DrawStringWrapped(font, text, image.Rectangle{Min: pt, Max: pt.Add(image.Pt(win.SizeVal.X, 0))})
	return 1
}
