package noxrender

import (
	"image"
	"image/draw"

	noxcolor "nox/v1/common/color"
	"nox/v1/common/noximage"
)

type RenderData interface {
	Frame() uint32
	ClipRect() image.Rectangle

	Color() uint32
	BgColor() uint32

	RenderDataText
}

func NewRender() *NoxRender {
	r := &NoxRender{}
	r.SetColorMode(noxcolor.ModeRGBA5551)
	r.initText()
	return r
}

type NoxRender struct {
	p   RenderData
	pix *noximage.Image16

	colors struct {
		mode noxcolor.Mode
		R    [256]uint16
		G    [256]uint16
		B    [256]uint16
	}
	text noxRenderText
}

func (r *NoxRender) PixBuffer() *noximage.Image16 {
	return r.pix
}

func (r *NoxRender) SetPixBuffer(pix *noximage.Image16) {
	r.pix = pix
}

func (r *NoxRender) Data() RenderData {
	return r.p
}

func (r *NoxRender) SetData(p RenderData) {
	r.p = p
}

func (r *NoxRender) Frame() uint32 {
	return r.p.Frame()
}

func (r *NoxRender) SetColorMode(mode noxcolor.Mode) {
	if r.colors.mode == mode {
		return
	}
	for i := 0; i < 256; i++ {
		r.colors.R[i] = mode.RGB(byte(i), 0, 0).Color16()
		r.colors.G[i] = mode.RGB(0, byte(i), 0).Color16()
		r.colors.B[i] = mode.RGB(0, 0, byte(i)).Color16()
	}
	r.colors.mode = mode
}

func (r *NoxRender) CopyPixBuffer() *image.NRGBA {
	img := image.NewNRGBA(r.pix.Rect)
	draw.Draw(img, img.Rect, r.pix, r.pix.Rect.Min, draw.Src)
	return img
}

func (r *NoxRender) ClearScreen() {
	cl := r.p.BgColor()
	for i := range r.pix.Pix {
		r.pix.Pix[i] = uint16(cl)
	}
}
