package noxcolor

import "image/color"

var (
	_ Color16 = RGBA4444(0)
)

// ModelRGBA4444 stores RGBA color in 16 bits (4444).
var ModelRGBA4444 = color.ModelFunc(modelRGBA4444)

func modelRGBA4444(c color.Color) color.Color {
	switch c := c.(type) {
	case RGBA4444:
		return c
	case color.RGBA:
		return ToRGBA4444(c.R, c.G, c.B, c.A)
	}
	r, g, b, a := c.RGBA()
	return ToRGBA4444(byte(r>>8), byte(g>>8), byte(b>>8), byte(a>>8))
}

// ToRGBA4444 converts RGBA color to RGBA4444.
func ToRGBA4444(r, g, b, a byte) RGBA4444 {
	rb := uint16(uint32(r)*15/0xff) & 0xf
	gb := uint16(uint32(g)*15/0xff) & 0xf
	bb := uint16(uint32(b)*15/0xff) & 0xf
	ab := uint16(uint32(a)*15/0xff) & 0xf
	return RGBA4444((ab << 0) | (bb << 4) | (gb << 8) | (rb << 12))
}

// RGBA4444 stores RGBA color in 16 bits (4444).
type RGBA4444 uint16

// Color16 implements Color16.
func (c RGBA4444) Color16() uint16 {
	return uint16(c)
}

// RGBA32 implements Color.
func (c RGBA4444) RGBA32() (v color.RGBA) {
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
func (c RGBA4444) RGBA() (r, g, b, a uint32) {
	return c.RGBA32().RGBA()
}
