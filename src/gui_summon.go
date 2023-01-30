package opennox

import (
	"image"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

func sub_4C26F0(win *gui.Window) int {
	pos := win.GlobalPos()
	x, y := pos.X, pos.Y
	sz := win.Size()
	w, h := sz.X, sz.Y
	r := noxClient.r
	r.DrawRectFilledAlpha(x, y, w, h)
	r.DrawVector(
		image.Point{X: x + 1, Y: y},
		image.Point{X: w - 2, Y: 0},
		nox_color_darkBlue,
	)
	r.DrawVector(
		image.Point{X: x + 1, Y: y + h},
		image.Point{X: w - 2, Y: 0},
		nox_color_darkBlue,
	)
	r.DrawVector(
		image.Point{X: x, Y: y + 1},
		image.Point{X: 0, Y: h - 2},
		nox_color_darkBlue,
	)
	r.DrawVector(
		image.Point{X: x + w, Y: y + 1},
		image.Point{X: 0, Y: h - 2},
		nox_color_darkBlue,
	)
	win.GUI().ValYYY = 1
	return 1
}
