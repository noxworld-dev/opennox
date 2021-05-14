package noxcolor

import "image/color"

// Color extends color.Color to also return color.RGBA.
type Color interface {
	color.Color
	// RGBA32 is similar to RGBA, but returns color.RGBA instead.
	RGBA32() color.RGBA
}

// Color16 is an interface for colors that occupy 16 bits.
type Color16 interface {
	Color
	// Color16 returns color value as uint16.
	Color16() uint16
}

// ExtendColor16 extends Color16 to 32 bits int.
func ExtendColor16(c Color16) uint32 {
	val := uint32(c.Color16())
	return val | (val << 16)
}
