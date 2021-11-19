package noxcolor

import "image/color"

var (
	_ Color16 = RGBA5551(0)
)

// ModelRGBA5551 stores RGBA color in 16 bits (5551).
var ModelRGBA5551 = color.ModelFunc(modelRGBA5551)

func modelRGBA5551(c color.Color) color.Color {
	switch c := c.(type) {
	case RGBA5551:
		return c
	case RGB555:
		return RGBA5551(c & 0x7fff) // alpha channel is inverted (0 = opaque)
	case color.RGBA:
		return ToRGBA5551(c.R, c.G, c.B, c.A)
	}
	r, g, b, a := c.RGBA()
	return ToRGBA5551(byte(r>>8), byte(g>>8), byte(b>>8), byte(a>>8))
}

// ToRGBA5551 converts RGBA color to RGBA5551.
func ToRGBA5551(r, g, b, a byte) RGBA5551 {
	rb := uint16(r >> 3)
	gb := uint16(g >> 3)
	bb := uint16(b >> 3)
	ab := uint16(0)
	if a < 128 {
		ab = 1
	}
	return RGBA5551((bb << 0) | (gb << 5) | (rb << 10) | (ab << 15))
}

// RGBA5551 stores RGBA color in 16 bits (5551).
type RGBA5551 uint16

// Color16 implements Color16.
func (c RGBA5551) Color16() uint16 {
	return uint16(c)
}

// RGBA32 implements Color.
func (c RGBA5551) RGBA32() color.RGBA {
	r := byte(c>>10) & 0x1f
	g := byte(c>>5) & 0x1f
	b := byte(c>>0) & 0x1f
	a := byte(0xff)
	if c>>15 != 0 {
		a = 0
	}
	return color.RGBA{
		R: r << 3,
		G: g << 3,
		B: b << 3,
		A: a,
	}
}

// RGBA implements color.Color.
func (c RGBA5551) RGBA() (r, g, b, a uint32) {
	return c.RGBA32().RGBA()
}
