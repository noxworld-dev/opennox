package opennox

import (
	"image"
	"image/color"
	"strconv"
	"time"

	"golang.org/x/image/font"

	"github.com/noxworld-dev/opennox/v1/client/gui"
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

func sub_470A80() {
	noxClient.guiFPS.dword1090246++
}

func (c *Client) initGuiFPS() int {
	c.guiFPS.dword147864 = 10
	c.guiFPS.win = newWindowFromFile(c.GUI, "GuiFps.wnd", nil)
	if c.guiFPS.win == nil {
		return 0
	}
	c.guiFPS.win.SetDraw(c.guiDrawFPS)
	c.guiFPS.win.SetPos(image.Pt(121, videoGetWindowSize().Y-c.guiFPS.win.Size().Y-5))
	c.guiFPS.font = c.r.Fonts.FontByName("numbers")
	sub_4706C0(0)
	return 1
}

func (c *Client) guiDrawFPS(win *gui.Window, _ *gui.WindowData) int {
	g := &c.guiFPS
	pos := win.GlobalPos()
	wsz := win.Size()
	if g.dword1090256 >= g.dword147864 {
		g.dword147864 = g.dword1090256 + 10
		ticks := platformTicks()
		g.dword1090260 = 10000 / int(ticks-g.dword1090268)
		g.dword1090268 = ticks
	}
	if g.dword1090246 != 0 {
		g.dword1090246 = 0
		g.arr1090184[g.dword1090248]++
	}
	g.dword1090252 = (g.dword1090252 + 1) % 3
	if g.dword1090252 == 0 {
		g.dword1090248 = (g.dword1090248 + 1) % 31
	}
	c.r.DrawRectFilledAlpha(pos.X, pos.Y, wsz.X, wsz.Y)
	str := strconv.Itoa(g.dword1090260)
	tsz := c.r.GetStringSizeWrapped(g.font, str, 0)
	c.r.Data().SetTextColor(nox_color_white_2523948)
	c.r.DrawString(g.font, str, pos.Add(image.Pt((wsz.X-tsz.X)/2, 3)))
	c.r.DrawRectFilledOpaque(pos.X+1, pos.Y+14, 30, 3, nox_color_black_2650656)
	for i := 1; i < 31; i++ {
		v := g.arr1090184[(i+g.dword1090248)%31]
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
			c.r.DrawBorder(pos.X+i, pos.Y+14-f+3, 1, f, cl)
		}
	}
	var cl color.Color
	if noxPerfmon.ping < 250*time.Millisecond {
		cl = nox_color_green
	} else if noxPerfmon.ping < 500*time.Millisecond {
		cl = nox_color_yellow_2589772
	} else {
		cl = nox_color_red
	}
	str = strconv.Itoa(int(noxPerfmon.ping.Milliseconds()))
	tsz = c.r.GetStringSizeWrapped(g.font, str, 0)
	c.r.Data().SetTextColor(cl)
	c.r.DrawString(g.font, str, pos.Add(image.Pt((wsz.X-tsz.X)/2, 22)))
	c.r.DrawBorder(pos.X, pos.Y, wsz.X, wsz.Y, nox_color_gray1)
	g.dword1090256++
	return 1
}

func sub_4706C0(a1 int) {
	c := noxClient
	win := c.guiFPS.win
	if a1 != 0 && c.guiFPS.enabled && win.GetFlags().IsHidden() {
		win.ShowModal()
	} else {
		win.Hide()
	}
}

func sub_470A60() {
	c := noxClient
	c.guiFPS.enabled = !c.guiFPS.enabled
	sub_4706C0(1)
}
