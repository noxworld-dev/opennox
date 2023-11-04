package gui

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/input"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func NewButtonRaw(g *GUI, parent *Window, status StatusFlags, px, py, w, h int, draw *WindowData) *Window {
	btn := g.NewWindowRaw(parent, status, px, py, w, h, buttonProc1)
	if btn == nil {
		return nil
	}
	buttonInit(btn)
	if draw.Window == nil {
		draw.Window = btn
	}
	btn.CopyDrawData(draw)
	return btn
}

func buttonProc1(win *Window, e WindowEvent) WindowEventResp {
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

func buttonInit(win *Window) {
	if !win.Flags.Has(StatusImage) {
		win.SetAllFuncs(ButtonProc2, ButtonDrawNoImg, nil)
	} else {
		win.SetAllFuncs(ButtonProc2, buttonDrawImg, nil)
	}
}

func ButtonSetImage(win *Window, bg, dis, en, sel, hl noxrender.ImageHandle) {
	if win == nil {
		return
	}
	win2 := win.Field100Ptr
	win2.Flags |= StatusImage
	buttonInit(win2)
	win2.DrawData().BgImageHnd = bg
	win2.DrawData().EnImageHnd = en
	win2.DrawData().DisImageHnd = dis
	win2.DrawData().SelImageHnd = sel
	win2.DrawData().HlImageHnd = hl
}

func ButtonProc2(win *Window, e WindowEvent) WindowEventResp {
	switch e := e.(type) {
	case WindowKeyPress:
		switch e.Key {
		case keybind.KeyTab, keybind.KeyRight, keybind.KeyDown, keybind.KeyUp, keybind.KeyLeft:
			return RawEventResp(1)
		case keybind.KeyEnter, keybind.KeySpace:
			if e.Pressed {
				win.DrawData().Field0 |= 0x4
				return RawEventResp(1)
			}
			if win.DrawData().Field0&0x4 != 0 {
				win.DrawData().Window.Func94(AsWindowEvent(0x4007, uintptr(unsafe.Pointer(win)), 0))
				win.DrawData().Field0 &^= 0x4
			}
			return RawEventResp(1)
		default:
			return RawEventResp(0)
		}
	case *WindowMouseState:
		switch e.State {
		case input.NOX_MOUSE_LEFT_DOWN:
			win.DrawData().Field0 |= 0x4
			return RawEventResp(1)
		case input.NOX_MOUSE_LEFT_DRAG_END, input.NOX_MOUSE_LEFT_UP:
			if (win.DrawData().Field0 & 4) == 0 {
				return RawEventResp(0)
			}
			a3, _ := e.EventArgsC()
			win.DrawData().Window.Func94(AsWindowEvent(0x4007, uintptr(unsafe.Pointer(win)), a3))
			win.DrawData().Field0 &^= 0x4
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
			if win.DrawData().Field0&0x4 != 0 {
				win.DrawData().Field0 &^= 0x4
			}
			return RawEventResp(1)
		default:
			return RawEventResp(0)
		}
	}
}

func ButtonDrawNoImg(win *Window, draw *WindowData) int {
	g := win.GUI()
	r := g.Render()
	borderCl := draw.EnabledColor()
	backCl := draw.BackgroundColor()
	gpos := win.GlobalPos()
	x, y := gpos.X, gpos.Y
	if win.Flags&8 != 0 {
		if draw.Field0&4 != 0 {
			backCl = draw.SelectedColor()
		} else if draw.Field0&2 != 0 {
			borderCl = draw.HighlightColor()
		}
	} else {
		backCl = draw.DisabledColor()
	}
	if borderCl.Color32() != noxcolor.Transparent32RGBA5551 {
		r.DrawBorder(x, y, win.SizeVal.X, win.SizeVal.Y, borderCl)
	}
	if backCl.Color32() != noxcolor.Transparent32RGBA5551 {
		r.DrawRectFilledOpaque(x+1, y+1, win.SizeVal.X-2, win.SizeVal.Y-2, backCl)
	}
	text := draw.Text()
	textCl := draw.TextColor()
	if text == "" || textCl.Color32() == noxcolor.Transparent32RGBA5551 {
		return 1
	}
	x2 := x + win.SizeVal.X/2
	y2 := y + win.SizeVal.Y/2
	if win.Flags.Has(StatusSmoothText) {
		r.SetTextSmooting(true)
	}
	defer r.SetTextSmooting(false)
	font := draw.Font()
	tw := r.GetStringSizeWrapped(font, text, 0).X
	th := r.FontHeight(font)
	pt := image.Pt(x2-tw/2, y2-th/2)
	r.Data().SetTextColor(textCl)
	r.DrawStringWrapped(font, text, image.Rectangle{Min: pt, Max: pt.Add(image.Pt(win.SizeVal.X, 0))})
	return 1
}

func buttonDrawImg(win *Window, draw *WindowData) int {
	g := win.GUI()
	r := g.Render()
	fgImg := r.Bag.AsImage(draw.EnImageHnd)
	bgImg := r.Bag.AsImage(draw.BgImageHnd)
	pos := win.GlobalPos()
	x, y := pos.X, pos.Y
	if win.Flags&8 != 0 {
		if draw.Field0&4 != 0 {
			fgImg = r.Bag.AsImage(draw.SelImageHnd)
		} else if draw.Field0&2 != 0 {
			fgImg = r.Bag.AsImage(draw.HlImageHnd)
		}
	} else {
		bgImg = r.Bag.AsImage(draw.DisImageHnd)
	}
	if bgImg != nil {
		r.DrawImage16(bgImg, image.Pt(x+win.DrawData().ImgPtVal.X, y+win.DrawData().ImgPtVal.Y))
	}
	if fgImg != nil {
		r.DrawImage16(fgImg, image.Pt(x+win.DrawData().ImgPtVal.X, y+win.DrawData().ImgPtVal.Y))
	}
	text := draw.Text()
	textCl := draw.TextColor()
	if text == "" || textCl.Color32() == noxcolor.Transparent32RGBA5551 {
		return 1
	}
	x += win.SizeVal.X / 2
	y += win.SizeVal.Y / 2
	if win.Flags&0x2000 != 0 {
		r.SetTextSmooting(true)
	}
	defer r.SetTextSmooting(false)
	font := draw.Font()
	tw := r.GetStringSizeWrapped(font, text, 0).X
	th := r.FontHeight(font)
	pt := image.Pt(x-tw/2, y-th/2)
	r.Data().SetTextColor(textCl)
	r.DrawStringWrapped(font, text, image.Rectangle{Min: pt, Max: pt.Add(image.Pt(win.SizeVal.X, 0))})
	return 1
}
