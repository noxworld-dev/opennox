package input

import (
	"image"

	"nox/common/types"

	"github.com/veandco/go-sdl2/sdl"
)

type window struct {
	size  types.Size  // size of the actual window
	draw  types.Size  // size of the image that game draws
	scale types.Sizef // scale factors calculated from sizes above
}

func (win *window) updateScale() {
	win.scale.W = float32(win.draw.W) / float32(win.size.W)
	win.scale.H = float32(win.draw.H) / float32(win.size.H)
}

// toDrawSpace remaps window position to position on the video buffer
func (win *window) toDrawSpace(p image.Point) image.Point {
	p.X = int(float32(p.X) * win.scale.W)
	p.Y = int(float32(p.Y) * win.scale.H)
	return p
}

// inputClampf clamps window coords according to the current screen size.
func (win *window) inputClampf(p types.Pointf) types.Pointf {
	if p.X < 0 {
		p.X = 0
	}
	if p.Y < 0 {
		p.Y = 0
	}
	if win.size.W > 0 && p.X > float32(win.size.W) {
		p.X = float32(win.size.W)
	}
	if win.size.H > 0 && p.Y > float32(win.size.H) {
		p.Y = float32(win.size.H)
	}
	return p
}

// inputClamp clamps window coords according to the current screen size.
func (win *window) inputClamp(p image.Point) image.Point {
	if p.X < 0 {
		p.X = 0
	}
	if p.Y < 0 {
		p.Y = 0
	}
	if win.size.W > 0 && p.X > win.size.W {
		p.X = win.size.W
	}
	if win.size.H > 0 && p.Y > win.size.H {
		p.Y = win.size.H
	}
	return p
}

func (h *Handler) initWindow() {
	def := h.iface.WindowDefault()
	h.win = window{
		size:  def,
		draw:  def,
		scale: types.Sizef{W: 1, H: 1},
	}
}

func (h *Handler) processWindowEvent(ev *sdl.WindowEvent) {
	if h.iface == nil {
		return
	}
	switch ev.GetType() {
	case sdl.WINDOWEVENT_FOCUS_LOST:
		h.iface.WindowEvent(WindowUnfocus)
	case sdl.WINDOWEVENT_FOCUS_GAINED:
		h.iface.WindowEvent(WindowFocus)
	}
}

func (h *Handler) SetWinSize(sz types.Size) {
	if sz.W == 0 || sz.H == 0 {
		return
	}
	h.win.size = sz
	h.win.updateScale()
}

func (h *Handler) SetDrawWinSize(sz types.Size) {
	if sz.W == 0 || sz.H == 0 {
		return
	}
	h.win.draw = sz
	h.win.updateScale()
}
