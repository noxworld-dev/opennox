package noxfont

import (
	"unicode"
	"unicode/utf16"
)

const (
	DefaultName = "default"
	LargeName   = "large"
	SmallName   = "small"
	NumbersName = "number"
)

type Font struct {
	Field0 uint32
	Field1 uint32
	Inline bool
	Ranges []Range
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
		return nil
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
