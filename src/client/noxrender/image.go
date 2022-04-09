package noxrender

import (
	"encoding/binary"
	"fmt"
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"
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

func NewRawImage(typ int, data []byte) Image16 {
	return &rawImage{typ: typ, data: data}
}

func (r *NoxRender) DrawImage16(img Image16, pos image.Point) { // nox_client_xxxDraw16_4C7440
	if img == nil {
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
	if r.p.Flag0() {
		rc := types.Rect{
			Left:   pos.X,
			Top:    pos.Y,
			Right:  pos.X + int(width),
			Bottom: pos.Y + int(height),
		}
		a1a, ok := types.UtilRectXxx(rc, r.p.ClipRectNox())
		if !ok {
			return
		}
		v11 := a1a.Left - rc.Left
		v12 := a1a.Top - rc.Top
		wsz = a1a.Right - a1a.Left
		height = uint32(a1a.Bottom - a1a.Top)
		if a1a.Left != rc.Left || v12 != 0 {
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

func (r *NoxRender) nox_client_drawImg_aaa_4C79F0(ops *drawOps, img Image16, pos image.Point) { // nox_client_drawImg_aaa_4C79F0
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
	if r.p.Flag0() {
		rc := types.Rect{Left: pos.X, Top: pos.Y, Right: pos.X + int(width), Bottom: pos.Y + int(height)}
		a1a, ok := types.UtilRectXxx(rc, r.p.ClipRectNox())
		if !ok {
			return
		}
		if rc != a1a {
			r.nox_client_drawXxx_4C7C80(ops, src, pos, int(width), a1a)
			return
		}
	}
	r.dword_5d4594_3799508 ^= byte(pos.Y & 0x1)
	pixbuf := r.PixBuffer()
	pitch := pixbuf.Stride
	for i := 0; i < int(height); i++ {
		dst := pixbuf.Pix[pitch*(pos.Y+i)+pos.X:]
		if r.dword_5d4594_3799552 != 0 {
			r.dword_5d4594_3799508 ^= 1
			if r.dword_5d4594_3799508 != 0 {
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

func (r *NoxRender) nox_client_drawXxx_4C7C80(ops *drawOps, pix []byte, pos image.Point, width int, clip types.Rect) { // nox_client_drawXxx_4C7C80
	left := clip.Left
	right := clip.Right
	dy := clip.Top - pos.Y
	height := clip.Bottom - clip.Top
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
	r.dword_5d4594_3799508 ^= byte(ys & 0x1)
	pixbuf := r.PixBuffer()
	pitch := pixbuf.Stride
	for i := 0; i < height; i++ {
		yi := ys + i
		if r.dword_5d4594_3799552 != 0 {
			r.dword_5d4594_3799508 ^= 1
			if r.dword_5d4594_3799508 != 0 {
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

func pixOpSrc(dst []uint16, src []byte, n int) (_ []uint16, _ []byte) { // sub_4C80E0
	if n < 0 {
		panic("negative size")
	}
	copy16b(dst[:n], src[:n*2])
	return dst[n:], src[n*2:]
}

func (r *NoxRender) pixOpOverMultiplyAlpha50(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C8A30
	const (
		rshift = 7
		gshift = 2
		bshift = 3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)
	rm, gm, bm := r.p.ColorMultA()
	rmul := uint16(byte(rm))
	gmul := uint16(byte(gm))
	bmul := uint16(byte(bm))

	return r.drawOpU16(dst, src, sz, func(old uint16, src uint16) uint16 {
		rc := byte((rmul * ((rmask & src) >> rshift)) >> 8)
		gc := byte((gmul * ((gmask & src) >> gshift)) >> 8)
		bc := byte((bmul * ((bmask & src) << bshift)) >> 8)

		cr := r.colors.R[byte(int16(rc)+(int16((rmask&old)>>rshift)-int16(rc))/2)]
		cg := r.colors.G[byte(int16(gc)+(int16((gmask&old)>>gshift)-int16(gc))/2)]
		cb := r.colors.B[byte(int16(bc)+(int16((bmask&old)<<bshift)-int16(bc))/2)]
		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpOver4444(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C96A0
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)
	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cr := (c1 & rmask) >> rshift
		cg := (c1 & gmask) >> gshift
		cb := (c1 & bmask) << bshift

		c2v := (c2 << 4) & 0xFF
		cr = r.colors.R[byte(cr+((c2v*(((c2>>8)&0xF0)-cr))>>8))]
		cg = r.colors.G[byte(cg+((c2v*(((c2>>4)&0xF0)-cg))>>8))]
		cb = r.colors.B[byte(cb+((c2v*(((c2>>0)&0xF0)-cb))>>8))]
		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpOver4444Multiply(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C9970
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)
	rm, gm, bm := r.p.ColorMultA()
	rmul := uint16(byte(rm))
	gmul := uint16(byte(gm))
	bmul := uint16(byte(bm))

	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cr := (c1 & rmask) >> rshift
		cg := (c1 & gmask) >> gshift
		cb := (c1 & bmask) << bshift

		c2v := (c2 << 4) & 0xFF
		cr = r.colors.R[byte(cr+((c2v*(((rmul*((c2>>8)&0xF0))>>8)-cr))>>8))]
		cg = r.colors.G[byte(cg+((c2v*(((gmul*((c2>>4)&0xF0))>>8)-cg))>>8))]
		cb = r.colors.B[byte(cb+((c2v*(((bmul*(c2&0xF0))>>8)-cb))>>8))]
		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpOver4444Alpha(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C97F0
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	a := uint32(r.p.Alpha())

	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		v5 := byte((a * uint32(c2&0x0F) << 4) >> 8)

		cr := (c1 & rmask) >> rshift
		cg := (c1 & gmask) >> gshift
		cb := (c1 & bmask) << bshift

		cr = r.colors.R[byte(cr+((uint16(v5)*((c2>>8)&0xF0-cr))>>8))]
		cg = r.colors.G[byte(cg+((uint16(v5)*((c2>>4)&0xF0-cg))>>8))]
		cb = r.colors.B[byte(cb+((uint16(v5)*((c2>>0)&0xF0-cb))>>8))]

		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpSrcMultiply(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C86B0
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	rmul, gmul, bmul := r.p.ColorMultA()

	return r.drawOpU16(dst, src, sz, func(_ uint16, c2 uint16) uint16 {
		cr := r.colors.R[byte((rmul*(uint32(rmask&c2)>>rshift))>>8)]
		cg := r.colors.G[byte((gmul*(uint32(gmask&c2)>>gshift))>>8)]
		cb := r.colors.B[byte((bmul*(uint32(bmask&c2)<<bshift))>>8)]
		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpOverAlpha50(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C8410
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)
	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cr1 := (c1 & rmask) >> rshift
		cg1 := (c1 & gmask) >> gshift
		cb1 := (c1 & bmask) << bshift

		cr2 := (c2 & rmask) >> rshift
		cg2 := (c2 & gmask) >> gshift
		cb2 := (c2 & bmask) << bshift

		cr := r.colors.R[byte(cr1+((cr2-cr1)>>1))]
		cg := r.colors.G[byte(cg1+((cg2-cg1)>>1))]
		cb := r.colors.B[byte(cb1+((cb2-cb1)>>1))]

		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpOverAlpha(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C8130
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	a := r.p.Alpha()

	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cr1 := (c1 & rmask) >> rshift
		cg1 := (c1 & gmask) >> gshift
		cb1 := (c1 & bmask) << bshift

		cr2 := (c2 & rmask) >> rshift
		cg2 := (c2 & gmask) >> gshift
		cb2 := (c2 & bmask) << bshift

		cr := r.colors.R[byte(cr1+((uint16(a)*(cr2-cr1))>>8))]
		cg := r.colors.G[byte(cg1+((uint16(a)*(cg2-cg1))>>8))]
		cb := r.colors.B[byte(cb1+((uint16(a)*(cb2-cb1))>>8))]

		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpOverMultiplyAlpha(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C8850
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	a := r.p.Alpha()
	rm, gm, bm := r.p.ColorMultA()
	rmul := uint16(byte(rm))
	gmul := uint16(byte(gm))
	bmul := uint16(byte(bm))

	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cr1 := (c1 & rmask) >> rshift
		cg1 := (c1 & gmask) >> gshift
		cb1 := (c1 & bmask) << bshift

		cr2 := (c2 & rmask) >> rshift
		cg2 := (c2 & gmask) >> gshift
		cb2 := (c2 & bmask) << bshift

		cr := r.colors.R[byte(cr1+((uint16(a)*(((rmul*cr2)>>8)-cr1))>>8))]
		cg := r.colors.G[byte(cg1+((uint16(a)*(((gmul*cg2)>>8)-cg1))>>8))]
		cb := r.colors.B[byte(cb1+((uint16(a)*(((bmul*cb2)>>8)-cb1))>>8))]

		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpSrcColorize(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C8D60
	rm, gm, bm := r.p.ColorMultA()
	rmul := uint16(byte(rm))
	gmul := uint16(byte(gm))
	bmul := uint16(byte(bm))

	return r.drawOpU16(dst, src, sz, func(_ uint16, ci uint16) uint16 {
		var c byte
		if int(ci) < len(r.colors.revTable) {
			c = r.colors.revTable[ci]
		}
		cr := r.colors.R[byte((uint32(rmul)*uint32(c))>>8)]
		cg := r.colors.G[byte((uint32(gmul)*uint32(c))>>8)]
		cb := r.colors.B[byte((uint32(bmul)*uint32(c))>>8)]
		return cr | cg | cb
	})
}

func (r *NoxRender) pixBlendPremult(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C9B20
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)
	return r.drawOpU16(dst, src, sz, func(c1 uint16, c2 uint16) uint16 {
		cr := (c1 & rmask) >> rshift
		cg := (c1 & gmask) >> gshift
		cb := (c1 & bmask) << bshift
		crb := ((c2>>8)&0xF8 | 7) + cr
		cgb := ((c2>>3)&0xFC | 3) + cg
		rbb := ((c2<<3)&0xF8 | 7) + cb
		if crb > 0xff {
			crb = 0xff
		}
		if cgb > 0xff {
			cgb = 0xff
		}
		if rbb > 0xff {
			rbb = 0xff
		}
		return r.colors.R[crb] | r.colors.G[cgb] | r.colors.B[rbb]
	})
}

func (r *NoxRender) pixOpSrcMultiplyIndexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C91C0
	rm, gm, bm := r.p.ColorMultA()
	rmul := uint16(byte(rm))
	gmul := uint16(byte(gm))
	bmul := uint16(byte(bm))

	rpmul, gpmul, bpmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(_ uint16, c byte) uint16 {
		cr := r.colors.R[byte((rmul*uint16(((rpmul*uint32(c))>>8)&0xFF))>>8)]
		cg := r.colors.G[byte((gmul*uint16(((gpmul*uint32(c))>>8)&0xFF))>>8)]
		cb := r.colors.B[byte((bmul*uint16(((bpmul*uint32(c))>>8)&0xFF))>>8)]
		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpSrcIndexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C8DF0
	rpmul, gpmul, bpmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(_ uint16, c byte) uint16 {
		cr := r.colors.R[byte((rpmul*uint32(c))>>8)]
		cg := r.colors.G[byte((gpmul*uint32(c))>>8)]
		cb := r.colors.B[byte((bpmul*uint32(c))>>8)]
		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpOverAlpha50Indexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C9050
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	rpmul, gpmul, bpmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(c1 uint16, c2 byte) uint16 {
		cr := (c1 & rmask) >> rshift
		cg := (c1 & gmask) >> gshift
		cb := (c1 & bmask) << bshift

		cr = r.colors.R[byte(cr+((uint16(((rpmul*uint32(c2))>>8)&0xFF)-cr)>>1))]
		cg = r.colors.G[byte(cg+((uint16(((gpmul*uint32(c2))>>8)&0xFF)-cg)>>1))]
		cb = r.colors.B[byte(cb+((uint16(((bpmul*uint32(c2))>>8)&0xFF)-cb)>>1))]

		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpOverAlphaIndexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C8EC0
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	a := r.p.Alpha()

	rpmul, gpmul, bpmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(c1 uint16, c2 byte) uint16 {
		cr := (c1 & rmask) >> rshift
		cg := (c1 & gmask) >> gshift
		cb := (c1 & bmask) << bshift

		cr = r.colors.R[byte(cr+((uint16(a)*(((uint16(rpmul)*uint16(c2))>>8)&0xFF-cr))>>8))]
		cg = r.colors.G[byte(cg+((uint16(a)*(((uint16(gpmul)*uint16(c2))>>8)&0xFF-cg))>>8))]
		cb = r.colors.B[byte(cb+((uint16(a)*(((uint16(bpmul)*uint16(c2))>>8)&0xFF-cb))>>8))]

		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpOverMultiplyAlpha50Indexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C94D0
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	rm, gm, bm := r.p.ColorMultA()
	rmul := uint16(byte(rm))
	gmul := uint16(byte(gm))
	bmul := uint16(byte(bm))

	rpmul, gpmul, bpmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(c1 uint16, c2 byte) uint16 {
		cr := (c1 & rmask) >> rshift
		cg := (c1 & gmask) >> gshift
		cb := (c1 & bmask) << bshift

		cr = r.colors.R[byte((rmul*((cr+((uint16((rpmul*uint32(c2))>>8)&0xFF-cr)>>1))&0xFF))>>8)]
		cg = r.colors.G[byte((gmul*((cg+((uint16((gpmul*uint32(c2))>>8)&0xFF-cg)>>1))&0xFF))>>8)]
		cb = r.colors.B[byte((bmul*((cb+((uint16((bpmul*uint32(c2))>>8)&0xFF-cb)>>1))&0xFF))>>8)]

		return cr | cg | cb
	})
}

func (r *NoxRender) pixOpOverMultiplyAlphaIndexed(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C92F0
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	a := r.p.Alpha()

	rm, gm, bm := r.p.ColorMultA()
	rmul := uint16(byte(rm))
	gmul := uint16(byte(gm))
	bmul := uint16(byte(bm))

	rpmul, gpmul, bpmul := r.p.ColorMultOp(int(op))

	return r.drawOpU8(dst, src, sz, func(c1 uint16, c2 byte) uint16 {
		cr := (c1 & rmask) >> rshift
		cg := (c1 & gmask) >> gshift
		cb := (c1 & bmask) << bshift

		cr = r.colors.R[byte(cr+(uint16(uint32(a)*uint32(((rmul*uint16(((rpmul*uint32(c2))>>8)&0xFF))>>8)-cr))>>8))]
		cg = r.colors.G[byte(cg+(uint16(uint32(a)*uint32(((gmul*uint16(((gpmul*uint32(c2))>>8)&0xFF))>>8)-cg))>>8))]
		cb = r.colors.B[byte(cb+(uint16(uint32(a)*uint32(((bmul*uint16(((bpmul*uint32(c2))>>8)&0xFF))>>8)-cb))>>8))]

		return cr | cg | cb
	})
}
