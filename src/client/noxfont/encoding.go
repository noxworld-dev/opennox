package noxfont

import (
	"bytes"
	"encoding/binary"
	"errors"
	"image"
	"io"
)

const magic = "FoNt"

const (
	Ext = ".fnt"
)

var endiness = binary.LittleEndian

func Decode(r io.Reader) (*Font, error) {
	var hdr [28]byte
	_, err := io.ReadFull(r, hdr[:])
	if err != nil {
		return nil, err
	}
	var (
		f      Font
		rcnt   int
		stride uint32
		height uint32
		charSz uint32
		buf    []byte
	)
	if swap4bytes(hdr[:4]) == magic {
		f.Inline = false
		f.Field0 = endiness.Uint32(hdr[4:])
		f.Field1 = endiness.Uint32(hdr[8:])
		stride = endiness.Uint32(hdr[12:])
		height = endiness.Uint32(hdr[16:])
		rcnt = int(endiness.Uint32(hdr[20:]))
		charSz = endiness.Uint32(hdr[24:])
		buf = make([]byte, 8*rcnt)
		_, err = io.ReadFull(r, buf)
		if err != nil {
			return nil, err
		}
	} else {
		f.Inline = true
		data := make([]byte, 76)
		n := copy(data, hdr[:])
		_, err = io.ReadFull(r, data[n:])
		if err != nil {
			return nil, err
		}
		f.Field1 = uint32(endiness.Uint16(data[0:]))
		stride = uint32(endiness.Uint16(data[2:]))
		height = uint32(endiness.Uint16(data[4:]))
		rcnt = int(endiness.Uint16(data[6:]))
		charSz = endiness.Uint32(data[72:])
		buf = make([]byte, 8*rcnt)
		copy(buf, data[8:72])
	}
	f.Ranges = make([]Range, 0, rcnt)
	offs := make([]uint32, 0, rcnt)
	chars := 0
	for i := 0; i < rcnt; i++ {
		b := buf[8*i : 8*(i+1)]
		off := endiness.Uint32(b[0:])
		rng := Range{
			StartChar: endiness.Uint16(b[4:]),
			EndChar:   endiness.Uint16(b[6:]),
		}
		f.Ranges = append(f.Ranges, rng)
		offs = append(offs, off)
		chars += int(rng.EndChar-rng.StartChar) + 1
	}
	dsize := charSz * uint32(chars)
	data := make([]byte, dsize)
	_, err = io.ReadFull(r, data)
	if err != nil {
		return nil, err
	}
	for i := range f.Ranges {
		rng := &f.Ranges[i]
		off := offs[i]
		data := data[charSz*off:]
		for c := rng.StartChar; c <= rng.EndChar; c++ {
			data := data[charSz*uint32(c-rng.StartChar):]
			data = data[:charSz:charSz]
			img := &Bitmap{Pix: data[1:], Stride: int(stride), Rect: image.Rect(0, 0, int(data[0]), int(height))}
			rng.Glyphs = append(rng.Glyphs, img)
		}
	}
	// This is an ugly workaround for Russian Nox fonts.
	// That localization uses CP-1251 characters instead of UTF-16 as all other languages.
	if len(f.Ranges) == 1 {
		if g := f.Char16(0xFB); g != nil {
			if bytes.Equal(g.Pix, fontRusYeruSmall[:]) || bytes.Equal(g.Pix, fontRusYeruLarge[:]) {
				f.CP1251 = true
			}
		}
	}
	return &f, nil
}

var (
	// Tests for one unique Russian letter: "ы" (0xFB in CP-1251).
	fontRusYeruSmall = [18]byte{4: 0x88, 6: 0x88, 8: 0xc8, 10: 0xa8, 12: 0xc8}
	fontRusYeruLarge = [45]byte{15: 0xc1, 16: 0x80, 18: 0xc1, 19: 0x80, 21: 0xf9, 22: 0x80, 24: 0xcd, 25: 0x80, 27: 0xcd, 28: 0x80, 30: 0xf9, 31: 0x80}
)

func (f *Font) Encode() ([]byte, error) {
	var (
		stride int
		height int
		offs   []int
		chars  int
		charSz int
	)
	for _, r := range f.Ranges {
		offs = append(offs, chars)
		chars += len(r.Glyphs)
		for _, s := range r.Glyphs {
			if stride == 0 {
				stride = s.Stride
				height = s.Rect.Dy()
				charSz = stride*height + 1
			} else {
				if s.Stride != stride {
					return nil, errors.New("stride should be the same for all glyphs")
				}
				if s.Rect.Dy() != height {
					return nil, errors.New("height should be the same for all glyphs")
				}
			}
			if len(s.Pix) != charSz-1 {
				return nil, errors.New("incorrect bitmap data size")
			}
			w := s.Rect.Dx()
			if w > 0xff {
				return nil, errors.New("glyph is too large")
			}
		}
	}
	var data bytes.Buffer
	if f.Inline {
		if len(f.Ranges) > 8 {
			return nil, errors.New("too many ranges for inline format")
		}
		data.Grow(76 + chars*charSz)
		var buf [76]byte
		endiness.PutUint16(buf[0:], uint16(f.Field1))
		endiness.PutUint16(buf[2:], uint16(stride))
		endiness.PutUint16(buf[4:], uint16(height))
		endiness.PutUint16(buf[6:], uint16(len(f.Ranges)))
		endiness.PutUint32(buf[72:], uint32(charSz))
		dst := buf[8:72]
		for i, r := range f.Ranges {
			off := offs[i]
			endiness.PutUint32(dst[0:], uint32(off))
			endiness.PutUint16(dst[4:], r.StartChar)
			endiness.PutUint16(dst[6:], r.EndChar)
			dst = dst[8:]
		}
		data.Write(buf[:])
	} else {
		data.Grow(28 + 8*len(f.Ranges) + chars*charSz)
		var buf [28]byte
		swap4put(buf[0:], magic)
		endiness.PutUint32(buf[4:], f.Field0)
		endiness.PutUint32(buf[8:], f.Field1)
		endiness.PutUint32(buf[12:], uint32(stride))
		endiness.PutUint32(buf[16:], uint32(height))
		endiness.PutUint32(buf[20:], uint32(len(f.Ranges)))
		endiness.PutUint32(buf[24:], uint32(charSz))
		data.Write(buf[:])
		for i, r := range f.Ranges {
			off := offs[i]
			endiness.PutUint32(buf[0:], uint32(off))
			endiness.PutUint16(buf[4:], r.StartChar)
			endiness.PutUint16(buf[6:], r.EndChar)
			data.Write(buf[:8])
		}
	}
	for _, r := range f.Ranges {
		for _, s := range r.Glyphs {
			data.WriteByte(byte(s.Rect.Dx()))
			data.Write(s.Pix)
		}
	}
	return data.Bytes(), nil
}

func swap4bytes(p []byte) string {
	return string([]byte{p[3], p[2], p[1], p[0]})
}

func swap4put(p []byte, s string) {
	p[0], p[1], p[2], p[3] = s[3], s[2], s[1], s[0]
}
