package noxcolor

import "image/color"

var (
	_ Color16 = RGB555(0)
)

// ModelRGB555 stores RGB color in 15 bits (555).
var ModelRGB555 = color.ModelFunc(modelRGB555)

func modelRGB555(c color.Color) color.Color {
	switch c := c.(type) {
	case RGB555:
		return c
	case RGBA5551:
		return RGB555(c & 0x7fff)
	case color.RGBA:
		return ToRGB555(c.R, c.G, c.B)
	}
	r, g, b, _ := c.RGBA()
	return ToRGB555(byte(r>>8), byte(g>>8), byte(b>>8))
}

// ToRGB555 converts RGB color to RGB555.
func ToRGB555(r, g, b byte) RGB555 {
	rb := uint16(uint32(r)*31/0xff) & 0x1f
	gb := uint16(uint32(g)*31/0xff) & 0x1f
	bb := uint16(uint32(b)*31/0xff) & 0x1f
	return RGB555((bb << 0) | (gb << 5) | (rb << 10))
}

// RGB555 stores RGB color in 15 bits (555).
type RGB555 uint16

// Color16 implements Color16.
func (c RGB555) Color16() uint16 {
	return uint16(c)
}

// RGBA32 implements Color.
func (c RGB555) RGBA32() (v color.RGBA) {
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
func (c RGB555) RGBA() (r, g, b, a uint32) {
	return c.RGBA32().RGBA()
}
