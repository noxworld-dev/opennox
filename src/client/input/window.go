package input

import (
	"image"

	"nox/v1/common/types"
)

type window struct {
	view  image.Rectangle // viewport inside the window
	draw  types.Size      // size of the image that game draws
	scale types.Sizef     // scale factors calculated from sizes above
}

func (win *window) init(def types.Size) {
	win.view = image.Rectangle{Max: def.Point()}
	win.draw = def
	win.scale = types.Sizef{W: 1, H: 1}
}

func (win *window) updateScale() {
	win.scale.W = float32(win.draw.W) / float32(win.view.Dx())
	win.scale.H = float32(win.draw.H) / float32(win.view.Dy())
}

// toDrawSpace remaps window position to position on the video buffer
func (win *window) toDrawSpace(p image.Point) image.Point {
	p.X -= win.view.Min.X
	p.Y -= win.view.Min.Y
	p.X = int(float32(p.X) * win.scale.W)
	p.Y = int(float32(p.Y) * win.scale.H)
	return clamp(image.Rectangle{Max: win.draw.Point()}, p)
}

func clamp(r image.Rectangle, p image.Point) image.Point {
	if p.X < r.Min.X {
		p.X = r.Min.X
	}
	if p.Y < r.Min.Y {
		p.Y = r.Min.Y
	}
	if r.Max.X != 0 && p.X >= r.Max.X {
		p.X = r.Max.X
	}
	if r.Max.Y != 0 && p.Y >= r.Max.Y {
		p.Y = r.Max.Y
	}
	return p
}

func clampf(r image.Rectangle, p types.Pointf) types.Pointf {
	if p.X < float32(r.Min.X) {
		p.X = float32(r.Min.X)
	}
	if p.Y < float32(r.Min.Y) {
		p.Y = float32(r.Min.Y)
	}
	if r.Max.X != 0 && p.X >= float32(r.Max.X) {
		p.X = float32(r.Max.X)
	}
	if r.Max.Y != 0 && p.Y >= float32(r.Max.Y) {
		p.Y = float32(r.Max.Y)
	}
	return p
}

func (win *window) SetWinSize(rect image.Rectangle) {
	if rect.Dx() == 0 || rect.Dy() == 0 {
		return
	}
	win.view = rect
	win.updateScale()
}

func (win *window) SetDrawWinSize(sz types.Size) {
	if sz.W == 0 || sz.H == 0 {
		return
	}
	win.draw = sz
	win.updateScale()
}
