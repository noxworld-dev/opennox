package noxfont

import (
	"image"
	"unicode"
	"unicode/utf16"

	"golang.org/x/image/font"
	"golang.org/x/image/math/fixed"
)

const (
	DefaultName = "default"
	LargeName   = "large"
	SmallName   = "small"
	NumbersName = "numbers"
)

const (
	DefaultFile = "default"
	LargeFile   = "large"
	SmallFile   = "small"
	NumbersFile = "number"
)

var _ font.Face = &Font{}

type Font struct {
	Field0 uint32
	Field1 uint32
	Inline bool
	Ranges []Range
	CP1251 bool // this font is encoded for CP-1251 instead of UTF-16
}

type Range struct {
	StartChar uint16
	EndChar   uint16
	Glyphs    []*Bitmap
}

func (f *Font) RangeFor(c uint16) *Range {
	for i, rng := range f.Ranges {
		if c >= rng.StartChar && c <= rng.EndChar {
			return &f.Ranges[i]
		}
	}
	return nil
}

func (f *Font) Char16(c uint16) *Bitmap {
	rng := f.RangeFor(c)
	if rng == nil {
		if !f.CP1251 {
			return nil
		}
		if first := rune2utf16('А'); c >= first && c <= rune2utf16('я') {
			c = 0xC0 + (c - first)
		} else {
			return nil
		}
		rng = f.RangeFor(c)
		if rng == nil {
			return nil
		}
	}
	ind := c - rng.StartChar
	return rng.Glyphs[ind]
}

func (f *Font) Rune(rn rune) *Bitmap {
	c := rune2utf16(rn)
	return f.Char16(c)
}

func rune2utf16(r rune) uint16 {
	// TODO: shouldn't we keep the second one?
	r1, _ := utf16.EncodeRune(r)
	if r1 == unicode.ReplacementChar {
		return uint16(r)
	}
	return uint16(r1)
}

func (f *Font) Close() error { return nil }

func (f *Font) Kern(r0, r1 rune) fixed.Int26_6 { return 0 }

func (f *Font) Glyph(dot fixed.Point26_6, r rune) (dr image.Rectangle, mask image.Image, maskp image.Point, advance fixed.Int26_6, ok bool) {
	g := f.Rune(r)
	if g == nil {
		g = f.Rune('\ufffd')
	}
	if g == nil {
		return image.Rectangle{}, nil, image.Point{}, 0, false
	}
	x := dot.X.Round()
	y := dot.Y.Round()

	dr = image.Rectangle{
		Min: image.Point{
			X: x,
			Y: y - g.Rect.Dy(),
		},
		Max: image.Point{
			X: x + g.Rect.Dx(),
			Y: y,
		},
	}

	return dr, g, image.Point{}, fixed.I(g.Rect.Dx() + 1), true
}

func (f *Font) GlyphBounds(r rune) (fixed.Rectangle26_6, fixed.Int26_6, bool) {
	g := f.Rune(r)
	if g == nil {
		return fixed.Rectangle26_6{}, 0, false
	}
	return fixed.R(0, 0, g.Rect.Dx(), g.Rect.Dy()), fixed.I(g.Rect.Dx() + 1), true
}

func (f *Font) GlyphAdvance(r rune) (fixed.Int26_6, bool) {
	g := f.Rune(r)
	if g == nil {
		return 0, false
	}
	return fixed.I(g.Rect.Dx() + 1), true
}

func (f *Font) Metrics() font.Metrics {
	if len(f.Ranges) == 0 {
		return font.Metrics{}
	}
	r := &f.Ranges[0]
	if len(r.Glyphs) == 0 {
		return font.Metrics{}
	}
	g := r.Glyphs[0]
	return font.Metrics{
		Height:     fixed.I(g.Rect.Dy()),
		Ascent:     fixed.I(g.Rect.Dy()),
		Descent:    0,
		XHeight:    fixed.I(g.Rect.Dy()),
		CapHeight:  fixed.I(g.Rect.Dy()),
		CaretSlope: image.Point{X: 0, Y: 1},
	}
}
