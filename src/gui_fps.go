package opennox

import (
	"image"
	"image/color"
	"strconv"
	"time"

	"golang.org/x/image/font"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

type guiFPS struct {
	win     *gui.Window
	font    font.Face
	enabled bool

	dword1090256 int
	dword147864  int
	dword1090260 int
	dword1090268 uint64
	dword1090248 int
	dword1090246 int
	dword1090252 int
	arr1090184   [32]uint16
}

func (c *guiFPS) sub_470A80() {
	c.dword1090246++
}

func (c *guiFPS) initGuiFPS(r *noxrender.NoxRender, g *gui.GUI) int {
	c.dword147864 = 10
	c.win = newWindowFromFile(g, "GuiFps.wnd", nil)
	if c.win == nil {
		return 0
	}
	c.win.SetDraw(func(win *gui.Window, draw *gui.WindowData) int {
		return c.guiDrawFPS(r, win, draw)
	})
	c.win.SetPos(image.Pt(121, videoGetWindowSize().Y-c.win.Size().Y-5))
	c.font = r.Fonts.FontByName("numbers")
	c.sub_4706C0(0)
	return 1
}

func (c *guiFPS) guiDrawFPS(r *noxrender.NoxRender, win *gui.Window, _ *gui.WindowData) int {
	mon := noxPerfmon
	pos := win.GlobalPos()
	wsz := win.Size()
	if c.dword1090256 >= c.dword147864 {
		c.dword147864 = c.dword1090256 + 10
		ticks := platformTicks()
		c.dword1090260 = 10000 / int(ticks-c.dword1090268)
		c.dword1090268 = ticks
	}
	if c.dword1090246 != 0 {
		c.dword1090246 = 0
		c.arr1090184[c.dword1090248]++
	}
	c.dword1090252 = (c.dword1090252 + 1) % 3
	if c.dword1090252 == 0 {
		c.dword1090248 = (c.dword1090248 + 1) % 31
	}
	r.DrawRectFilledAlpha(pos.X, pos.Y, wsz.X, wsz.Y)
	str := strconv.Itoa(c.dword1090260)
	tsz := r.GetStringSizeWrapped(c.font, str, 0)
	r.Data().SetTextColor(nox_color_white_2523948)
	r.DrawString(c.font, str, pos.Add(image.Pt((wsz.X-tsz.X)/2, 3)))
	r.DrawRectFilledOpaque(pos.X+1, pos.Y+14, 30, 3, nox_color_black_2650656)
	for i := 1; i < 31; i++ {
		v := c.arr1090184[(i+c.dword1090248)%31]
		var (
			f  int
			cl color.Color
		)
		if v == 1 {
			f = 1
			cl = nox_color_red
		} else if v == 2 {
			f = 2
			cl = nox_color_yellow_2589772
		} else if v != 0 {
			f = 3
			cl = nox_color_green
		}
		if f != 0 {
			r.DrawBorder(pos.X+i, pos.Y+14-f+3, 1, f, cl)
		}
	}
	var cl color.Color
	if mon.ping < 250*time.Millisecond {
		cl = nox_color_green
	} else if mon.ping < 500*time.Millisecond {
		cl = nox_color_yellow_2589772
	} else {
		cl = nox_color_red
	}
	str = strconv.Itoa(int(mon.ping.Milliseconds()))
	tsz = r.GetStringSizeWrapped(c.font, str, 0)
	r.Data().SetTextColor(cl)
	r.DrawString(c.font, str, pos.Add(image.Pt((wsz.X-tsz.X)/2, 22)))
	r.DrawBorder(pos.X, pos.Y, wsz.X, wsz.Y, nox_color_gray1)
	c.dword1090256++
	return 1
}

func (c *guiFPS) sub_4706C0(a1 int) {
	win := c.win
	if a1 != 0 && c.enabled && win.GetFlags().IsHidden() {
		win.ShowModal()
	} else {
		win.Hide()
	}
}

func (c *guiFPS) sub_470A60() {
	c.enabled = !c.enabled
	c.sub_4706C0(1)
}
