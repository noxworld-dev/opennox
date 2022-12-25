package opennox

/*
 */
import "C"
import (
	"image"
	"unsafe"
)

//export sub_4C26F0
func sub_4C26F0(a1 unsafe.Pointer) C.int {
	win := asWindowP(a1)
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
