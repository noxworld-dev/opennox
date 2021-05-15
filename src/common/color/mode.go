package noxcolor

const (
	ModePalette  = Mode(0)
	ModeRGBA5551 = Mode(1)
	ModeRGB565   = Mode(2)
)

var (
	mode Mode = -1
)

// GetMode returns current color mode.
func GetMode() Mode {
	return mode
}

// SetMode sets a new color mode.
func SetMode(m Mode) {
	mode = m
}

// RGBColor uses current color mode to pack RGB color to an integer.
func RGBColor(r, g, b byte) Color16 {
	return mode.RGB(r, g, b)
}

// IntToColor uses current to unpack color from an integer.
func IntToColor(v uint32) Color16 {
	return mode.IntToColor(v)
}

// Mode represents a color mode used by Nox.
type Mode int

// ExtendColor16 extends Color16 to 32 bits int.
func ExtendColor16(c Color16) uint32 {
	if c, ok := c.(RGBA5551); ok && c == 0x8000 {
		return 0x80000000
	}
	val := uint32(c.Color16())
	return val | (val << 16)
}

// RGB packs color to an integer, according to this color mode.
func (m Mode) RGB(r, g, b byte) Color16 {
	switch m {
	case ModePalette:
		// TODO: not supported
		fallthrough
	case ModeRGBA5551:
		return ToRGBA5551(r, g, b, 0xff)
	case ModeRGB565:
		return ToRGB565(r, g, b)
	default:
		return RGBA5551(0)
	}
}

// IntToColor unpacks color from an integer, according to this color mode.
func (m Mode) IntToColor(v uint32) Color16 {
	c := uint16(v >> 16)
	switch m {
	case ModePalette:
		// TODO: not supported
		fallthrough
	case ModeRGBA5551:
		return RGBA5551(c)
	case ModeRGB565:
		return RGB565(c)
	default:
		return RGBA5551(0)
	}
}
