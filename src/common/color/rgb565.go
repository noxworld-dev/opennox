package noxcolor

import "image/color"

var (
	_ Color16 = RGB565(0)
)

// ModelRGB565 stores RGB color in 16 bits (565).
var ModelRGB565 = color.ModelFunc(modelRGB565)

func modelRGB565(c color.Color) color.Color {
	switch c := c.(type) {
	case RGB565:
		return c
	case color.RGBA:
		return ToRGB565(c.R, c.G, c.B)
	}
	r, g, b, _ := c.RGBA()
	return ToRGB565(byte(r>>8), byte(g>>8), byte(b>>8))
}

// ToRGB565 converts RGBA color to RGB565.
func ToRGB565(r, g, b byte) RGB565 {
	rb := uint16(r >> 3)
	gb := uint16(g >> 2)
	bb := uint16(b >> 3)
	return RGB565((bb << 0) | (gb << 5) | (rb << 11))
}

// RGB565 stores RGB color in 16 bits (565).
type RGB565 uint16

// Color16 implements Color16.
func (c RGB565) Color16() uint16 {
	return uint16(c)
}

// RGBA32 implements Color.
func (c RGB565) RGBA32() color.RGBA {
	r := byte(c>>11) & 0x1f
	g := byte(c>>5) & 0x3f
	b := byte(c>>0) & 0x1f
	return color.RGBA{
		R: r << 3,
		G: g << 2,
		B: b << 3,
		A: 0xff,
	}
}

// RGBA implements color.Color.
func (c RGB565) RGBA() (r, g, b, a uint32) {
	return c.RGBA32().RGBA()
}
