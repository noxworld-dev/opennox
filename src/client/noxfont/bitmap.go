package noxfont

import (
	"image"
	"image/color"
)

var (
	_ image.Image = &Bitmap{}
)

type Bitmap struct {
	Pix    []byte
	Stride int
	Rect   image.Rectangle
}

func (*Bitmap) ColorModel() color.Model {
	return color.AlphaModel
}

func (p *Bitmap) Bounds() image.Rectangle {
	return p.Rect
}

func (p *Bitmap) BitOffsets(x, y int) (int, int) {
	i := (y-p.Rect.Min.Y)*p.Stride + (x-p.Rect.Min.X)/8
	j := 7 - (x-p.Rect.Min.X)%8
	return i, j
}

func (p *Bitmap) at(x, y int) bool {
	if !(image.Point{x, y}.In(p.Rect)) {
		return false
	}
	i, j := p.BitOffsets(x, y)
	return (p.Pix[i]>>j)&0x1 != 0
}

func (p *Bitmap) At(x, y int) color.Color {
	if p.at(x, y) {
		return color.Opaque
	}
	return color.Transparent
}

func (p *Bitmap) set(x, y int, a byte) {
	i, j := p.BitOffsets(x, y)
	if a >= 128 {
		p.Pix[i] |= 1 << j
	} else {
		p.Pix[i] &^= 1 << j
	}
}

func (p *Bitmap) Set(x, y int, c color.Color) {
	if !(image.Point{x, y}.In(p.Rect)) {
		return
	}
	p.set(x, y, color.AlphaModel.Convert(c).(color.Alpha).A)
}

func (p *Bitmap) SetAlpha(x, y int, c color.Alpha) {
	if !(image.Point{x, y}.In(p.Rect)) {
		return
	}
	p.set(x, y, c.A)
}

func (p *Bitmap) SetGray(x, y int, c color.Gray) {
	if !(image.Point{x, y}.In(p.Rect)) {
		return
	}
	p.set(x, y, c.Y)
}
