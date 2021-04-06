package noxcolor

import (
	"image/color"
)

var (
	_ color.Color = RGB15(0)
)

// ColorToRGB15 converts any color to RGB15. It will drop alpha-channel, if any.
func ColorToRGB15(c color.Color) RGB15 {
	if c, ok := c.(color.RGBA); ok {
		return ToRGB15(c.R, c.G, c.B)
	}
	r, g, b, _ := c.RGBA()
	return ToRGB15(byte(r>>8), byte(g>>8), byte(b>>8))
}

// ToRGB15 converts RGB color to RGB15.
func ToRGB15(r, g, b byte) RGB15 {
	rb := uint16(uint32(r)*31/0xff) & 0x1f
	gb := uint16(uint32(g)*31/0xff) & 0x1f
	bb := uint16(uint32(b)*31/0xff) & 0x1f
	return RGB15((bb << 0) | (gb << 5) | (rb << 10))
}

// RGB15 stores RGB color in 15 bits.
type RGB15 uint16

// RGBA32 is similar to RGBA, but returns color.RGBA instead.
func (c RGB15) RGBA32() (v color.RGBA) {
	r := uint32((c&0xfc00)>>10) * 0xff
	g := uint32((c&0x03e0)>>5) * 0xff
	b := uint32((c&0x001f)>>0) * 0xff
	v.R = byte(r / 31)
	v.G = byte(g / 31)
	v.B = byte(b / 31)
	v.A = 0xff
	if r%31 != 0 {
		v.R++
	}
	if g%31 != 0 {
		v.G++
	}
	if b%31 != 0 {
		v.B++
	}
	return
}

// RGBA implements color.Color.
func (c RGB15) RGBA() (r, g, b, a uint32) {
	return c.RGBA32().RGBA()
}
