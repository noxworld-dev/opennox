package gui

import (
	"image"
	"image/color"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func init() {
	RegisterWindowEvent(&StaticTextSetText{}, func(a1, a2 uintptr) WindowEvent {
		cstr := (*uint16)(unsafe.Pointer(a1))
		str := alloc.GoString16(cstr)
		return &StaticTextSetText{
			Str:  str,
			Val:  int(a2),
			cstr: cstr,
		}
	})
	RegisterWindowEvent(StaticTextGetText{}, func(a1, a2 uintptr) WindowEvent {
		if a1 != 0 || a2 != 0 {
			panic("unsupported get text event")
		}
		return StaticTextGetText{}
	})
}

const (
	eventStaticTextPref    = 0x4000
	eventStaticTextSetText = eventStaticTextPref + 1 // 0x4001
	eventStaticTextGetText = eventStaticTextPref + 2 // 0x4002
)

type StaticTextData struct {
	Text   *uint16
	Center uint32
	Glow   uint32
}

func (d *StaticTextData) CWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

func (g *GUI) NewStaticText(par *Window, id uint, px, py, w, h int, center, glow bool, text string) *Window {
	draw, dfree := NewWindowData()
	defer dfree()
	*draw = *par.DrawData()

	draw.Window = par
	draw.Style |= StyleStaticText
	status := StatusSmoothText | StatusNoFocus

	iglow := 0
	if glow {
		iglow = 1
	}
	icenter := 0
	if center {
		icenter = 1
	}
	win := g.NewStaticTextRaw(par, status, px, py, w, h, draw, &StaticTextData{
		Text:   alloc.InternCString16(text),
		Center: uint32(icenter),
		Glow:   uint32(iglow),
	})
	win.SetID(id)
	if par != nil {
		par.Func94(WindowNewChild{ID: id})
	}
	return win
}

func (g *GUI) NewStaticTextRaw(par *Window, status StatusFlags, px, py, w, h int, draw *WindowData, data *StaticTextData) *Window { // nox_gui_newStaticText_489300
	draw.Style &= 0xFFFFFBFF
	if draw.Style&StyleStaticText == 0 {
		return nil
	}
	win := g.NewWindowRaw(par, status, px, py, w, h, nox_xxx_wndStaticProcPre_489390)
	if !win.GetFlags().Has(StatusImage) {
		win.SetAllFuncs(nox_xxx_wndStaticProc_489420, StaticTextDrawNoImage, nil)
	} else {
		win.SetAllFuncs(nox_xxx_wndStaticProc_489420, StaticDrawWithImage, nil)
	}
	if draw.Window == nil {
		draw.Window = win
	}
	win.CopyDrawData(draw)
	wdata, _ := alloc.New(StaticTextData{})
	*wdata = *data
	win.WidgetData = unsafe.Pointer(wdata)
	return win
}

func nox_xxx_wndStaticProcPre_489390(win *Window, e WindowEvent) WindowEventResp {
	switch e := e.(type) {
	case WindowDestroy:
		alloc.FreePtr(win.WidgetData)
		win.WidgetData = nil
		return nil
	case *StaticTextSetText:
		data := (*StaticTextData)(win.WidgetData)
		if e.Str != "" {
			data.Text = e.cStr()
		} else {
			data.Text = nil
		}
		return nil
	case StaticTextGetText:
		data := (*StaticTextData)(win.WidgetData)
		return RawEventResp(unsafe.Pointer(data.Text))
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

func StaticTextDrawNoImage(win *Window, draw *WindowData) int { // nox_xxx_wndStaticDrawNoImage_488D00
	r := win.GUI().Render()
	fnt := draw.Font()

	wdata := (*StaticTextData)(win.WidgetData)
	highlight := draw.EnabledColor()
	wpos := win.GlobalPos()
	wsz := win.Size()
	x, y := wpos.X, wpos.Y
	w, h := wsz.X, wsz.Y
	if win.GetFlags().Has(StatusSmoothText) {
		r.SetTextSmooting(true)
		defer r.SetTextSmooting(false)
	}
	borderColor := draw.EnabledColor()
	var bgColor color.Color
	if win.GetFlags().Has(StatusEnabled) {
		if draw.Field0&0x2 != 0 {
			borderColor = draw.HighlightColor()
		}
		bgColor = draw.BackgroundColor()
	} else {
		bgColor = draw.DisabledColor()
	}
	if draw.Field0&0x4 != 0 {
		highlight = draw.SelectedColor()
	}
	if _, _, _, alpha := bgColor.RGBA(); alpha != 0 {
		r.DrawRectFilledOpaque(x+1, y+1, w-2, h-2, bgColor)
	}
	if _, _, _, alpha := borderColor.RGBA(); alpha != 0 {
		r.DrawBorder(x, y, w, h, borderColor)
	}
	text := alloc.GoString16(wdata.Text)
	if text == "" {
		return 1
	}
	if _, _, _, alpha := draw.TextColor().RGBA(); alpha != 0 {
		r.Data().SetTextColor(draw.TextColor())
		sz := r.GetStringSizeWrapped(fnt, text, w)
		cy := y + (h-sz.Y)/2
		if wdata.Center != 0 {
			if sz.Y > r.FontHeight(fnt) {
				dy := fnt.Metrics().CapHeight.Round()
				for i, line := range r.SplitStringWrapped(fnt, text, w) {
					if strings.TrimSpace(line) == "" {
						continue
					}
					sz := r.GetStringSizeWrapped(fnt, line, w)
					lx := x + (w-sz.X)/2
					ly := cy + dy*i
					if wdata.Glow != 0 {
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
				if wdata.Glow != 0 {
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
		} else if wdata.Glow != 0 {
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

func StaticDrawWithImage(win *Window, draw *WindowData) int {
	r := win.GUI().Render()

	data := (*StaticTextData)(win.WidgetData)

	wpos := win.GlobalPos()
	wsz := win.Size()
	fnt := draw.Font()
	fh := r.FontHeight(fnt)
	if win.GetFlags().Has(StatusSmoothText) {
		r.SetTextSmooting(true)
	}
	if bg := draw.BackgroundImage(); bg != nil {
		r.DrawImage16(bg, wpos.Add(draw.ImagePoint()))
	}
	var img *noxrender.Image
	if win.GetFlags().Has(StatusEnabled) {
		img = draw.EnabledImage()
	} else {
		img = draw.DisabledImage()
	}
	if img != nil {
		r.DrawImage16(img, wpos.Add(draw.ImagePoint()))
	}
	if str := alloc.GoString16(data.Text); str != "" {
		r.Data().SetTextColor(draw.TextColor())
		y0 := wpos.Y + wsz.Y/2 - fh/2
		if data.Center != 0 {
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

var _ WindowEvent = &StaticTextSetText{}

type StaticTextSetText struct {
	Str  string
	Val  int
	cstr *uint16
}

func (*StaticTextSetText) EventCode() int { return eventStaticTextSetText }
func (ev *StaticTextSetText) cStr() *uint16 {
	if ev.cstr == nil {
		ev.cstr = alloc.InternCString16(ev.Str)
	}
	return ev.cstr
}
func (ev *StaticTextSetText) EventArgsC() (uintptr, uintptr) {
	return uintptr(unsafe.Pointer(ev.cStr())), uintptr(ev.Val)
}

var _ WindowEvent = StaticTextGetText{}

type StaticTextGetText struct{}

func (StaticTextGetText) EventCode() int { return eventStaticTextGetText }
func (StaticTextGetText) EventArgsC() (uintptr, uintptr) {
	return 0, 0
}
