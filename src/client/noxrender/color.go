package noxrender

import noxcolor "github.com/noxworld-dev/opennox-lib/color"

var colorTable struct {
	R, G, B [256]Color
}

func init() {
	for i := 0; i <= 0xff; i++ {
		colorTable.R[i] = noxcolor.ToRGBA5551(byte(i), 0, 0, 0xff)
		colorTable.G[i] = noxcolor.ToRGBA5551(0, byte(i), 0, 0xff)
		colorTable.B[i] = noxcolor.ToRGBA5551(0, 0, byte(i), 0xff)
	}
}

type Color = noxcolor.RGBA5551

func ColorRGB(r, g, b byte) Color {
	return noxcolor.ToRGBA5551(r, g, b, 0xff)
}

// SplitColor splits RGB555 color into separate 8 bit RGB components.
// Color components are returned as uint16 for convenience.
func SplitColor(cl Color) (c Color16) {
	c.R = uint16(cl&0x7c00) >> 7 // -10+3
	c.G = uint16(cl&0x03e0) >> 2 // -5+3
	c.B = uint16(cl&0x001f) << 3 // -0+3
	return
}

func SplitColor16(cl uint16) (c Color16) {
	c.R = cl & 0x7c00 >> 7 // -10+3
	c.G = cl & 0x03e0 >> 2 // -5+3
	c.B = cl & 0x001f << 3 // -0+3
	return
}

func SplitColor4444(cl uint16) (c Color16, a uint16) {
	c.R = (cl >> 8) & 0xf0 // -12+4
	c.G = (cl >> 4) & 0xf0 // -8+4
	c.B = (cl >> 0) & 0xf0 // -4+4
	a = (cl << 4) & 0xf0   // -0+4
	return
}

type Color16 struct {
	R, G, B uint16
}

func (c Color16) Make() Color {
	return colorTable.R[byte(c.R)] | colorTable.G[byte(c.G)] | colorTable.B[byte(c.B)]
}

func (c Color16) Make16() uint16 {
	return uint16(colorTable.R[byte(c.R)] | colorTable.G[byte(c.G)] | colorTable.B[byte(c.B)])
}

func (c Color16) Saturate() Color16 {
	if c.R > 0xff {
		c.R = 0xff
	}
	if c.G > 0xff {
		c.G = 0xff
	}
	if c.B > 0xff {
		c.B = 0xff
	}
	return c
}

func (c Color16) Mult(c2 Color16) Color16 {
	c.R = uint16((uint32(c.R)*uint32(c2.R))>>8) & 0xff
	c.G = uint16((uint32(c.G)*uint32(c2.G))>>8) & 0xff
	c.B = uint16((uint32(c.B)*uint32(c2.B))>>8) & 0xff
	return c
}

func (c Color16) MultI(c2 uint16) Color16 {
	c.R = uint16((uint32(c.R)*uint32(c2))>>8) & 0xff
	c.G = uint16((uint32(c.G)*uint32(c2))>>8) & 0xff
	c.B = uint16((uint32(c.B)*uint32(c2))>>8) & 0xff
	return c
}

func (c Color16) Over(c2 Color16) Color16 {
	c.R += (c2.R - c.R) / 2
	c.G += (c2.G - c.G) / 2
	c.B += (c2.B - c.B) / 2
	return c
}

func (c Color16) Over2(c2 Color16) Color16 {
	c.R += (c2.R - c.R) / 4
	c.G += (c2.G - c.G) / 4
	c.B += (c2.B - c.B) / 4
	return c
}

func (c Color16) OverAlpha(a uint16, c2 Color16) Color16 {
	c.R += ((a * (c2.R - c.R)) >> 8) & 0xff
	c.G += ((a * (c2.G - c.G)) >> 8) & 0xff
	c.B += ((a * (c2.B - c.B)) >> 8) & 0xff
	return c
}
