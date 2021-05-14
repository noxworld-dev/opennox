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
