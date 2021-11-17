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
	return color.GrayModel
}

func (p *Bitmap) Bounds() image.Rectangle {
	return p.Rect
}

func (p *Bitmap) BitOffsets(x, y int) (int, int) {
	i := (y-p.Rect.Min.Y)*p.Stride + (x-p.Rect.Min.X)/8
	j := 7 - (x-p.Rect.Min.X)%8
	return i, j
}

func (p *Bitmap) At(x, y int) color.Color {
	return p.GrayAt(x, y)
}

func (p *Bitmap) GrayAt(x, y int) color.Gray {
	if !(image.Point{x, y}.In(p.Rect)) {
		return color.Gray{}
	}
	i, j := p.BitOffsets(x, y)
	if (p.Pix[i]>>j)&0x1 != 0 {
		return color.Gray{Y: 0xFF}
	}
	return color.Gray{}
}

func (p *Bitmap) setGray(x, y int, c byte) {
	i, j := p.BitOffsets(x, y)
	if c >= 128 {
		p.Pix[i] |= 1 << j
	} else {
		p.Pix[i] &^= 1 << j
	}
}

func (p *Bitmap) Set(x, y int, c color.Color) {
	if !(image.Point{x, y}.In(p.Rect)) {
		return
	}
	p.setGray(x, y, color.GrayModel.Convert(c).(color.Gray).Y)
}

func (p *Bitmap) SetGray(x, y int, c color.Gray) {
	if !(image.Point{x, y}.In(p.Rect)) {
		return
	}
	p.setGray(x, y, c.Y)
}
