package nox

import (
	"encoding/binary"
	"unsafe"

	"nox/v1/common/types"
)

func (r *NoxRender) drawImage16(img *Image, pos types.Point) { // nox_client_xxxDraw16_4C7440
	if img == nil {
		return
	}
	switch img.Type() & 0x3F {
	case 2, 7:
		r.nox_client_drawImg_bbb_4C7860(img, pos)
	case 3, 4, 5, 6:
		var ops drawOps
		ops.draw5 = r.sub4C96A0
		ops.draw6 = func(dst []uint16, src []byte, val int) (_ []uint16, _ []byte) { return dst, src }
		if !r.Data().IsAlphaEnabled() {
			if r.p.field_14 != 0 {
				ops.draw5 = r.sub4C9970
				ops.draw27 = r.sub4C86B0
				ops.draw4 = r.sub4C91C0u8
			} else {
				ops.draw27 = r.sub4C8D60
				if r.p.field_17 == 0 {
					ops.draw27 = pixCopyN
				}
				ops.draw4 = r.sub4C8DF0u8
			}
		} else {
			ops.draw5 = r.sub4C97F0
			alpha := r.Data().Alpha()
			if r.p.field_14 != 0 {
				if alpha == 0xFF {
					if r.p.field_16 == 0 {
						ops.draw27 = r.sub4C86B0
						ops.draw4 = r.sub4C91C0u8
					} else {
						ops.draw27 = pixCopyN
						ops.draw4 = r.sub4C8DF0u8
					}
				} else if alpha == 0x80 {
					ops.draw27 = r.pixBlend16
					ops.draw4 = r.sub4C94D0u8
				} else {
					ops.draw27 = r.sub4C8850
					ops.draw4 = r.sub4C92F0u8
				}
			} else {
				if alpha == 0xFF {
					ops.draw27 = pixCopyN
					ops.draw4 = r.sub4C8DF0u8
				} else if alpha == 0x80 {
					ops.draw27 = r.sub4C8410
					ops.draw4 = r.sub4C9050u8
				} else {
					ops.draw27 = r.sub4C8130
					ops.draw4 = r.sub4C8EC0u8
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

func pixCopyN(dst []uint16, src []byte, n int) (_ []uint16, _ []byte) { // sub_4C80E0
	if n < 0 {
		panic("negative size")
	}
	copy16b(dst[:n], src[:n*2])
	return dst[n:], src[n*2:]
}

func (r *NoxRender) pixBlend16(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C8A30
	const ( // TODO: why masks are inverted?
		rshift = 3
		gshift = 2
		bshift = 7

		rmask = 0x001f
		gmask = 0x03e0
		bmask = 0x7c00
	)

	rmul := uint16(byte(r.p.field_26))
	gmul := uint16(byte(r.p.field_25))
	bmul := uint16(byte(r.p.field_24))

	return r.drawOpU16(dst, src, sz, func(old uint16, src uint16) uint16 {
		rc := byte((rmul * ((rmask & src) << rshift)) >> 8)
		gc := byte((gmul * ((gmask & src) >> gshift)) >> 8)
		bc := byte((bmul * ((bmask & src) >> bshift)) >> 8)

		cr := r.colors.R[byte(int16(bc)+(int16((bmask&old)>>bshift)-int16(bc))/2)]
		cg := r.colors.G[byte(int16(gc)+(int16((gmask&old)>>gshift)-int16(gc))/2)]
		cb := r.colors.B[byte(int16(rc)+(int16((rmask&old)<<rshift)-int16(rc))/2)]
		return cr | cg | cb
	})
}

func (r *NoxRender) sub4C96A0(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C96A0
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

func (r *NoxRender) sub4C9970(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C9970
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	rmul := uint16(byte(r.p.field_24))
	gmul := uint16(byte(r.p.field_25))
	bmul := uint16(byte(r.p.field_26))

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

func (r *NoxRender) sub4C97F0(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C97F0
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

func (r *NoxRender) sub4C86B0(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C86B0
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	rmul := uint32(r.p.field_24)
	gmul := uint32(r.p.field_25)
	bmul := uint32(r.p.field_26)

	return r.drawOpU16(dst, src, sz, func(_ uint16, c2 uint16) uint16 {
		cr := r.colors.R[byte((rmul*(uint32(rmask&c2)>>rshift))>>8)]
		cg := r.colors.G[byte((gmul*(uint32(gmask&c2)>>gshift))>>8)]
		cb := r.colors.B[byte((bmul*(uint32(bmask&c2)<<bshift))>>8)]
		return cr | cg | cb
	})
}

func (r *NoxRender) sub4C8410(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C8410
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

func (r *NoxRender) sub4C8130(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C8130
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

func (r *NoxRender) sub4C8850(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C8850
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	a := r.p.Alpha()

	rmul := uint16(byte(r.p.field_24))
	gmul := uint16(byte(r.p.field_25))
	bmul := uint16(byte(r.p.field_26))

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

func (r *NoxRender) sub4C8D60(dst []uint16, src []byte, sz int) (_ []uint16, _ []byte) { // sub_4C8D60
	rmul := uint16(byte(r.p.field_24))
	gmul := uint16(byte(r.p.field_25))
	bmul := uint16(byte(r.p.field_26))

	return r.drawOpU16(dst, src, sz, func(_ uint16, ci uint16) uint16 {
		var c byte
		if int(ci) < len(nox_draw_colorTablesRev_3804668) {
			c = nox_draw_colorTablesRev_3804668[ci]
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

func (r *NoxRender) sub4C91C0u8(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C91C0
	rmul := uint16(byte(r.p.field_24))
	gmul := uint16(byte(r.p.field_25))
	bmul := uint16(byte(r.p.field_26))

	v9 := r.p.field66(int(op))

	rpmul := v9[6]
	gpmul := v9[7]
	bpmul := v9[8]

	return r.drawOpU8(dst, src, sz, func(_ uint16, c byte) uint16 {
		cr := r.colors.R[byte((rmul*uint16(((rpmul*uint32(c))>>8)&0xFF))>>8)]
		cg := r.colors.G[byte((gmul*uint16(((gpmul*uint32(c))>>8)&0xFF))>>8)]
		cb := r.colors.B[byte((bmul*uint16(((bpmul*uint32(c))>>8)&0xFF))>>8)]
		return cr | cg | cb
	})
}

func (r *NoxRender) sub4C8DF0u8(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C8DF0
	v9 := r.p.field66(int(op))

	rpmul := v9[6]
	gpmul := v9[7]
	bpmul := v9[8]

	return r.drawOpU8(dst, src, sz, func(_ uint16, c byte) uint16 {
		cr := r.colors.R[byte((rpmul*uint32(c))>>8)]
		cg := r.colors.G[byte((gpmul*uint32(c))>>8)]
		cb := r.colors.B[byte((bpmul*uint32(c))>>8)]
		return cr | cg | cb
	})
}

func (r *NoxRender) sub4C9050u8(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C9050
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	v5 := r.p.field66(int(op))

	rpmul := v5[6]
	gpmul := v5[7]
	bpmul := v5[8]

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

func (r *NoxRender) sub4C8EC0u8(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C8EC0
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	a := r.p.Alpha()

	v7 := r.p.field66(int(op))

	rpmul := v7[6]
	gpmul := v7[7]
	bpmul := v7[8]

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

func (r *NoxRender) sub4C94D0u8(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C94D0
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	rmul := uint16(byte(r.p.field_24))
	gmul := uint16(byte(r.p.field_25))
	bmul := uint16(byte(r.p.field_26))

	v9 := r.p.field66(int(op))

	rpmul := v9[6]
	gpmul := v9[7]
	bpmul := v9[8]

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

func (r *NoxRender) sub4C92F0u8(dst []uint16, src []byte, op byte, sz int) (_ []uint16, _ []byte) { // sub_4C92F0
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)

	a := r.p.Alpha()

	rmul := uint16(byte(r.p.field_24))
	gmul := uint16(byte(r.p.field_25))
	bmul := uint16(byte(r.p.field_26))

	v12 := r.p.field66(int(op))

	rpmul := v12[6]
	gpmul := v12[7]
	bpmul := v12[8]

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
