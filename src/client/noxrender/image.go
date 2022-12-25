package noxrender

import (
	"encoding/binary"
	"fmt"
	"image"
	"unsafe"
)

type drawOp16Func func(dst []uint16, src []byte, val int) (outDst []uint16, outSrc []byte)
type drawOp8Func func(dst []uint16, src []byte, op byte, val int) (outDst []uint16, outSrc []byte)

type drawOps struct {
	draw27 drawOp16Func
	draw4  drawOp8Func
	draw5  drawOp16Func
	draw6  drawOp16Func
}

type Image16 interface {
	Type() int
	Pixdata() []byte
}

type rawImage struct {
	typ  int
	data []byte
}

func (img *rawImage) Type() int {
	return img.typ
}

func (img *rawImage) Pixdata() []byte {
	return img.data
}

func NewRawImage16(typ int, data []byte) Image16 {
	return &rawImage{typ: typ, data: data}
}

func (r *NoxRender) DrawImage16(img Image16, pos image.Point) {
	if img == nil {
		return
	}
	if p, ok := img.(*Image); ok && p == nil {
		return
	}
	switch img.Type() & 0x3F {
	case 2, 7:
		r.nox_client_drawImg_bbb_4C7860(img, pos)
	case 3, 4, 5, 6:
		var ops drawOps
		ops.draw5 = r.pixOpOver4444
		ops.draw6 = func(dst []uint16, src []byte, val int) (_ []uint16, _ []byte) { return dst, src }
		if !r.p.IsAlphaEnabled() {
			if r.p.Multiply14() {
				ops.draw5 = r.pixOpOver4444Multiply
				ops.draw27 = r.pixOpSrcMultiply
				ops.draw4 = r.pixOpSrcMultiplyIndexed
			} else {
				ops.draw27 = pixOpSrc
				ops.draw4 = r.pixOpSrcIndexed
				if r.p.Colorize17() {
					ops.draw27 = r.pixOpSrcColorize
				}
			}
		} else {
			ops.draw5 = r.pixOpOver4444Alpha
			alpha := r.Data().Alpha()
			if r.p.Multiply14() {
				if alpha == 0xFF {
					if r.p.Flag16() {
						ops.draw27 = pixOpSrc
						ops.draw4 = r.pixOpSrcIndexed
					} else {
						ops.draw5 = r.pixOpOver4444Multiply
						ops.draw27 = r.pixOpSrcMultiply
						ops.draw4 = r.pixOpSrcMultiplyIndexed
					}
				} else if alpha == 0x80 {
					ops.draw27 = r.pixOpOverMultiplyAlpha50
					ops.draw4 = r.pixOpOverMultiplyAlpha50Indexed
				} else {
					ops.draw27 = r.pixOpOverMultiplyAlpha
					ops.draw4 = r.pixOpOverMultiplyAlphaIndexed
				}
			} else {
				if alpha == 0xFF {
					ops.draw27 = pixOpSrc
					ops.draw4 = r.pixOpSrcIndexed
				} else if alpha == 0x80 {
					ops.draw27 = r.pixOpOverAlpha50
					ops.draw4 = r.pixOpOverAlpha50Indexed
				} else {
					ops.draw27 = r.pixOpOverAlpha
					ops.draw4 = r.pixOpOverAlphaIndexed
				}
			}
		}
		r.nox_client_drawImg_aaa_4C79F0(&ops, img, pos)
	case 8:
		var ops drawOps
		ops.draw27 = r.pixBlendPremult
		r.nox_client_drawImg_aaa_4C79F0(&ops, img, pos)
	}
}

func (r *NoxRender) nox_client_drawImg_bbb_4C7860(img Image16, pos image.Point) {
	data := img.Pixdata()
	if len(data) == 0 {
		return
	}
	width := binary.LittleEndian.Uint32(data[0:])
	height := binary.LittleEndian.Uint32(data[4:])
	data = data[8:]

	offX := int32(binary.LittleEndian.Uint32(data[0:]))
	offY := int32(binary.LittleEndian.Uint32(data[4:]))
	data = data[8:]
	pos.X += int(offX)
	pos.Y += int(offY)

	data = data[1:] // unused

	if r.dword_5d4594_3799484 != 0 {
		height -= r.dword_5d4594_3799484
		if height <= 0 {
			return
		}
		r.dword_5d4594_3799476 = pos.Y + int(height)
	}

	wsz := int(width)
	if r.p.Clip() {
		rc := image.Rectangle{Min: pos, Max: pos.Add(image.Pt(int(width), int(height)))}
		a1a := rc.Intersect(r.p.ClipRect())
		if a1a.Empty() {
			return
		}
		v11 := a1a.Min.X - rc.Min.X
		v12 := a1a.Min.Y - rc.Min.Y
		wsz = a1a.Dx()
		height = uint32(a1a.Dy())
		if a1a.Min.X != rc.Min.X || v12 != 0 {
			pos.X += v11
			data = data[int(width)*v12+2*v11:]
			pos.Y += v12
		}
	}
	xoff := pos.X
	ipitch := 2 * int(width)
	pixbuf := r.PixBuffer()
	pitch := pixbuf.Stride
	for i := 0; i < int(height); i++ {
		dst := pixbuf.Pix[pitch*(pos.Y+1)+xoff:]
		src := data[ipitch*i:]
		copy16b(dst[:wsz], src[:wsz*2])
	}
}

func (r *NoxRender) nox_client_drawImg_aaa_4C79F0(ops *drawOps, img Image16, pos image.Point) {
	src := img.Pixdata()
	if len(src) == 0 {
		return
	}

	width := binary.LittleEndian.Uint32(src[0:])
	height := binary.LittleEndian.Uint32(src[4:])
	src = src[8:]

	offX := int32(binary.LittleEndian.Uint32(src[0:]))
	offY := int32(binary.LittleEndian.Uint32(src[4:]))
	src = src[8:]
	pos.X += int(offX)
	pos.Y += int(offY)

	src = src[1:] // unused

	if r.dword_5d4594_3799484 != 0 {
		height -= r.dword_5d4594_3799484
		if height <= 0 {
			return
		}
		r.dword_5d4594_3799476 = pos.Y + int(height)
	}
	if r.HookImageDrawXxx != nil {
		r.HookImageDrawXxx(pos, image.Point{X: int(width), Y: int(height)})
	}
	if r.p.Clip() {
		rc := image.Rectangle{Min: pos, Max: pos.Add(image.Pt(int(width), int(height)))}
		a1a := rc.Intersect(r.p.ClipRect())
		if a1a.Empty() {
			return
		}
		if rc != a1a {
			r.nox_client_drawXxx_4C7C80(ops, src, pos, int(width), a1a)
			return
		}
	}
	r.interlacingY ^= pos.Y & 0x1
	pixbuf := r.PixBuffer()
	pitch := pixbuf.Stride
	for i := 0; i < int(height); i++ {
		dst := pixbuf.Pix[pitch*(pos.Y+i)+pos.X:]
		if r.interlacing {
			r.interlacingY ^= 1
			if r.interlacingY != 0 {
				if i != 0 {
					copy(dst[:width], pixbuf.Pix[pitch*(pos.Y+i-1)+pos.X:])
				}
				src = skipPixdata(src, int(width), 1)
				continue
			}
		}
		var val int
		for j := 0; j < int(width); j += val {
			op := src[0]
			val = int(src[1])
			src = src[2:]

			if op&0xF == 1 {
				dst = dst[val:]
				continue
			}
			switch op & 0xF {
			case 2, 7:
				dst, src = ops.draw27(dst, src, val)
			case 4:
				dst, src = ops.draw4(dst, src, op>>4, val)
			case 5:
				dst, src = ops.draw5(dst, src, val)
			case 6:
				dst, src = ops.draw6(dst, src, val)
			default:
				panic(fmt.Errorf("invalid draw op: 0x%x, (%d,%d)", op, i, j))
			}
		}
	}
}

func (r *NoxRender) nox_client_drawXxx_4C7C80(ops *drawOps, pix []byte, pos image.Point, width int, clip image.Rectangle) {
	left := clip.Min.X
	right := clip.Max.X
	dy := clip.Min.Y - pos.Y
	height := clip.Dy()
	if r.dword_5d4594_3799484 != 0 {
		height -= int(r.dword_5d4594_3799484)
		if height <= 0 {
			return
		}
		r.dword_5d4594_3799476 = pos.Y + height
	}
	if height == 0 {
		return
	}
	ys := pos.Y
	if dy != 0 {
		ys += dy
		pix = skipPixdata(pix, width, dy)
	}
	r.interlacingY ^= ys & 0x1
	pixbuf := r.PixBuffer()
	pitch := pixbuf.Stride
	for i := 0; i < height; i++ {
		yi := ys + i
		if r.interlacing {
			r.interlacingY ^= 1
			if r.interlacingY != 0 {
				if i != 0 {
					src := pixbuf.Pix[pitch*(yi-1)+left:]
					dst := pixbuf.Pix[pitch*(yi+0)+left:]
					w := right - left
					if w > width {
						w = width
					}
					copy(dst[:w], src[:w])
				}
				pix = skipPixdata(pix, width, 1)
				continue
			}
		}
		if width <= 0 {
			continue
		}
		row := pixbuf.Pix[pitch*yi : pitch*(yi+1)]
		var n int
		for j := 0; j < width; j += n {
			op := pix[0]
			n = int(pix[1]) // TODO: custom bag images fail here
			pix = pix[2:]

			if op&0xF == 1 {
				continue
			}

			var (
				fnc16 drawOp16Func
				fnc8  drawOp8Func
				pmul  int
			)
			switch op & 0xF {
			case 2, 7:
				fnc16 = ops.draw27
				pmul = 2
			case 4:
				fnc8 = ops.draw4
				pmul = 1
			case 5:
				fnc16 = ops.draw5
				pmul = 2
			case 6:
				fnc16 = ops.draw6
				pmul = 2
			default:
				panic(op)
			}
			xs := pos.X + j
			xe := xs + n
			xw := n
			if xe <= left || xs >= right {
				pix = pix[pmul*n:]
				continue
			}

			pix2 := pix
			if xs < left {
				d := left - xs
				xw -= d
				xs = left
				pix2 = pix2[pmul*d:]
			}
			row2 := row[xs:]
			if xe > right {
				d := xe - right
				xw -= d
			}
			if fnc8 != nil {
				_, _ = fnc8(row2, pix2, op>>4, xw)
				pix = pix[n:]
			} else {
				_, _ = fnc16(row2, pix2, xw)
				pix = pix[2*n:]
			}
		}
	}
}

func copy16b(dst []uint16, src []byte) int {
	n16 := len(src) / 2
	src = src[:n16*2]
	src16 := unsafe.Slice((*uint16)(unsafe.Pointer(&src[0])), n16)
	return copy(dst, src16)
}

func skipPixdata(pix []byte, width int, skip int) []byte {
	for i := 0; i < skip; i++ {
		val := 0
		for j := 0; j < width; j += val {
			op := pix[0]
			val = int(pix[1])
			pix = pix[2:]
			switch op & 0xF {
			case 2, 5, 6, 7:
				pix = pix[2*val:]
				break
			case 4:
				pix = pix[val:]
			}
		}
	}
	return pix
}

type drawU16Func func(old uint16, src uint16) uint16

func (r *NoxRender) drawOpU16(dst []uint16, src []byte, sz int, fnc drawU16Func) (_ []uint16, _ []byte) {
	if sz < 0 {
		panic("negative size")
	}
	dnext := dst[sz:]
	snext := src[2*sz:]
	for i := 0; i < sz; i++ {
		c1 := dst[i]
		c2 := binary.LittleEndian.Uint16(src[2*i:])
		dst[i] = fnc(c1, c2)
	}
	return dnext, snext
}

type drawU8Func func(old uint16, src byte) uint16

func (r *NoxRender) drawOpU8(dst []uint16, src []byte, sz int, fnc drawU8Func) (_ []uint16, _ []byte) {
	if sz < 0 {
		panic("negative size")
	}
	dnext := dst[sz:]
	snext := src[sz:]
	for i := 0; i < sz; i++ {
		c1 := dst[i]
		c2 := src[i]
		dst[i] = fnc(c1, c2)
	}
	return dnext, snext
}

func pixOpSrc(dst []uint16, src []byte, n int) (_ []uint16, _ []byte) {
	if n < 0 {
		panic("negative size")
	}
	copy16b(dst[:n], src[:n*2])
	return dst[n:], src[n*2:]
}

func (r *NoxRender) pixOpOverMultiplyAlpha50(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) {
	mul := r.p.ColorMultA()

	return r.drawOpU16(dst, src, sz, func(old uint16, src uint16) uint16 {
		c1 := SplitColor16(src)
		c2 := SplitColor16(old)
		return c1.Mult(mul).Over(c2).Make16()
	})
}

func (r *NoxRender) pixOpOver4444(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) {
	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cc1 := SplitColor16(c1)
		cc2, a := SplitColor4444(c2)
		return cc1.OverAlpha(a, cc2).Make16()
	})
}

func (r *NoxRender) pixOpOver4444Multiply(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) {
	mul := r.p.ColorMultA()

	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cc1 := SplitColor16(c1)
		cc2, a := SplitColor4444(c2)
		return cc1.OverAlpha(a, cc2.Mult(mul)).Make16()
	})
}

func (r *NoxRender) pixOpOver4444Alpha(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) {
	a := uint16(r.p.Alpha())

	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cc1 := SplitColor16(c1)
		cc2, a2 := SplitColor4444(c2)
		a2 = ((a * a2) >> 8) & 0xff
		return cc1.OverAlpha(a2, cc2).Make16()
	})
}

func (r *NoxRender) pixOpSrcMultiply(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) {
	mul := r.p.ColorMultA()

	return r.drawOpU16(dst, src, sz, func(_ uint16, c2 uint16) uint16 {
		c := SplitColor16(c2)
		return c.Mult(mul).Make16()
	})
}

func (r *NoxRender) pixOpOverAlpha50(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) {
	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cc1 := SplitColor16(c1)
		cc2 := SplitColor16(c2)
		return cc1.Over(cc2).Make16()
	})
}

func (r *NoxRender) pixOpOverAlpha(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) {
	a := uint16(r.p.Alpha())

	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cc1 := SplitColor16(c1)
		cc2 := SplitColor16(c2)
		return cc1.OverAlpha(a, cc2).Make16()
	})
}

func (r *NoxRender) pixOpOverMultiplyAlpha(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) {
	a := uint16(r.p.Alpha())
	mul := r.p.ColorMultA()

	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cc1 := SplitColor16(c1)
		cc2 := SplitColor16(c2)
		return cc1.OverAlpha(a, cc2.Mult(mul)).Make16()
	})
}

func (r *NoxRender) pixOpSrcColorize(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) {
	mul := r.p.ColorMultA()

	return r.drawOpU16(dst, src, sz, func(_ uint16, ci uint16) uint16 {
		var c uint16
		if int(ci) < len(r.colors.revTable) {
			c = uint16(r.colors.revTable[ci])
		}
		return mul.MultI(c).Make16()
	})
}

func (r *NoxRender) pixBlendPremult(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) {
	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cc := SplitColor16(c1)
		cc.R += (c2>>8)&0xF8 | 7
		cc.G += (c2>>3)&0xFC | 3
		cc.B += (c2<<3)&0xF8 | 7
		return cc.Saturate().Make16()
	})
}

func (r *NoxRender) pixOpSrcMultiplyIndexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) {
	mul := r.p.ColorMultA()
	pmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(_ uint16, c byte) uint16 {
		return mul.Mult(pmul.MultI(uint16(c))).Make16()
	})
}

func (r *NoxRender) pixOpSrcIndexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) {
	pmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(_ uint16, c byte) uint16 {
		return pmul.MultI(uint16(c)).Make16()
	})
}

func (r *NoxRender) pixOpOverAlpha50Indexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) {
	pmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(c1 uint16, c2 byte) uint16 {
		cc1 := SplitColor16(c1)
		return cc1.Over(pmul.MultI(uint16(c2))).Make16()
	})
}

func (r *NoxRender) pixOpOverAlphaIndexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) {
	a := uint16(r.p.Alpha())
	pmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(c1 uint16, c2 byte) uint16 {
		cc1 := SplitColor16(c1)
		return cc1.OverAlpha(a, pmul.MultI(uint16(c2))).Make16()
	})
}

func (r *NoxRender) pixOpOverMultiplyAlpha50Indexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) {
	mul := r.p.ColorMultA()
	pmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(c1 uint16, c2 byte) uint16 {
		cc1 := SplitColor16(c1)
		return cc1.Over(pmul.MultI(uint16(c2)).Mult(mul)).Make16()
	})
}

func (r *NoxRender) pixOpOverMultiplyAlphaIndexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) {
	a := uint16(r.p.Alpha())
	mul := r.p.ColorMultA()
	pmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(c1 uint16, c2 byte) uint16 {
		cc1 := SplitColor16(c1)
		return cc1.OverAlpha(a, pmul.MultI(uint16(c2)).Mult(mul)).Make16()
	})
}
