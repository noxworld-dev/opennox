package noxcolor

import "image/color"

var (
	_ color.Color = RGB16(0)
)

// ColorToRGBA16 converts any color to RGB16.
func ColorToRGBA16(c color.Color) RGB16 {
	if c, ok := c.(color.RGBA); ok {
		return ToRGB16(c.R, c.G, c.B, c.A)
	}
	r, g, b, a := c.RGBA()
	return ToRGB16(byte(r>>8), byte(g>>8), byte(b>>8), byte(a>>8))
}

// ToRGB16 converts RGBA color to RGB16.
func ToRGB16(r, g, b, a byte) RGB16 {
	rb := uint16(uint32(r)*15/0xff) & 0xf
	gb := uint16(uint32(g)*15/0xff) & 0xf
	bb := uint16(uint32(b)*15/0xff) & 0xf
	ab := uint16(uint32(a)*15/0xff) & 0xf
	return RGB16((ab << 0) | (bb << 4) | (gb << 8) | (rb << 12))
}

// RGB16 stores RGBA color in 16 bits.
type RGB16 uint16

// RGBA32 is similar to RGBA, but returns color.RGBA instead.
func (c RGB16) RGBA32() (v color.RGBA) {
	v.R = byte((c >> 12) & 0xf)
	v.G = byte((c >> 8) & 0xf)
	v.B = byte((c >> 4) & 0xf)
	v.A = byte((c >> 0) & 0xf)
	v.R = byte(uint32(v.R) * 0xff / 15)
	v.G = byte(uint32(v.G) * 0xff / 15)
	v.B = byte(uint32(v.B) * 0xff / 15)
	v.A = byte(uint32(v.A) * 0xff / 15)
	return
}

// RGBA implements color.Color.
func (c RGB16) RGBA() (r, g, b, a uint32) {
	return c.RGBA32().RGBA()
}
