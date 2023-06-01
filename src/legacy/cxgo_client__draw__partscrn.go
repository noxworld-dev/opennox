package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func nox_client_screenParticleDraw_489700(a1p *noxrender.Viewport, p *Nox_screenParticle) {
	var (
		a1    int32 = int32(uintptr(a1p.C()))
		v7    int32
		v10   int32
		v11   int8
		v12   int8
		xLeft int2
	)
	xLeft.field_0 = int32(p.Field_24 >> 16)
	xLeft.field_4 = int32(p.Field_28 >> 16)
	if xLeft.field_0 <= 0 || xLeft.field_4 <= 0 || xLeft.field_0 >= *(*int32)(unsafe.Pointer(uintptr(a1 + 32))) || xLeft.field_4 >= *(*int32)(unsafe.Pointer(uintptr(a1 + 36))) {
		sub_431700((*uint64)(unsafe.Pointer(p)))
		return
	}
	sub_4B6720(&xLeft, int32(p.Field_8), int32(p.Field_40[0]), int8(p.Field_40[0]))
	nox_client_drawSetColor_434460(int32(p.Field_12))
	nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, int32(p.Field_40[0])>>1)
	var v3 int8 = int8(p.Field_40[1])
	p.Field_20 += p.Field_36
	if int32(v3) != 0 {
		var v4 int8 = int8(int32(v3) - 1)
		p.Field_40[1] = uint8(v4)
		if int32(v4) == 0 {
			if int32(p.Field_40[2]) == 1 {
				var v5 uint8 = uint8(int8(int32(p.Field_40[0]) + 1))
				p.Field_40[0] = v5
				if int32(v5) >= 4 {
					p.Field_40[2] = 2
				}
			} else {
				var v6 int8 = int8(int32(p.Field_40[0]) - 1)
				p.Field_40[0] = uint8(v6)
				if int32(v6) == 0 {
					sub_431700((*uint64)(unsafe.Pointer(p)))
					return
				}
			}
			p.Field_40[1] = p.Field_40[3]
		}
	}
	if int32(*(*uint8)(unsafe.Pointer(&p.Field_32))) == 1 && nox_common_randomIntMinMax_415FF0(0, 10, internCStr("C:\\NoxPost\\src\\client\\Draw\\PartScrn.c"), 105) >= 8 {
		v12 = int8(nox_common_randomIntMinMax_415FF0(3, 5, internCStr("C:\\NoxPost\\src\\client\\Draw\\PartScrn.c"), 115))
		v11 = int8(nox_common_randomIntMinMax_415FF0(2, 3, internCStr("C:\\NoxPost\\src\\client\\Draw\\PartScrn.c"), 114))
		v10 = xLeft.field_4
		v7 = nox_common_randomIntMinMax_415FF0(-2, 2, internCStr("C:\\NoxPost\\src\\client\\Draw\\PartScrn.c"), 109)
		nox_client_newScreenParticle_431540(int32(p.Field_4), xLeft.field_0+v7, v10, 0, 0, 1, v11, v12, 2, 2)
	}
	p.Field_24 += p.Field_16
	p.Field_28 += p.Field_20
}
