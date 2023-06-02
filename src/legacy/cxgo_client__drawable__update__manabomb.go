package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_updDrawManabombCharge_4CCAC0(vp *noxrender.Viewport, dr *client.Drawable) int {
	a2 := (*uint32)(dr.C())
	var rad int32 = int32(nox_xxx_gamedataGetFloat_419D40(internCStr("ManaBombOutRadius")))
	if dword_5d4594_1522956 == 0 {
		dword_5d4594_1522956 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ManaBombOrb")))
		*memmap.PtrUint32(0x5D4594, 1522960) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("VioletSpark")))
	}
	for v19 := int32(20); v19 != 0; v19-- {
		var v5 int32 = (rad / 4) + nox_common_randomIntMinMax_415FF0(0, rad, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c"), 63)
		if v5 > rad {
			v5 = rad
		}
		var v6 int32 = nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c"), 68)
		var v7 int32 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1522960), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3))+uint32(v5**memmap.PtrInt32(0x587000, uintptr(v6*8)+192088)/16)), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*4))+uint32(v5**memmap.PtrInt32(0x587000, uintptr(v6*8)+192092)/16))))))
		if v7 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 432))) = *(*uint32)(unsafe.Pointer(uintptr(v7 + 12))) << 12
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 436))) = *(*uint32)(unsafe.Pointer(uintptr(v7 + 16))) << 12
			*(*uint8)(unsafe.Pointer(uintptr(v7 + 299))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 440))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 448))) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(10, 30, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c"), 88))
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 444))) = gameFrame()
			*(*uint16)(unsafe.Pointer(uintptr(v7 + 104))) = 0
			*(*uint8)(unsafe.Pointer(uintptr(v7 + 296))) = uint8(int8(nox_common_randomIntMinMax_415FF0(2, 8, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c"), 94)))
			nox_xxx_sprite_45A110_drawable((*nox_drawable)(unsafe.Pointer(uintptr(v7))))
		}
	}
	if gameFrame()&1 != 0 {
		if (gameFrame() - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*80))) < 10 {
			var vv1 [4]int16
			vv1[0] = *((*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(a2))), unsafe.Sizeof(int16(0))*6)))
			vv1[1] = *((*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(a2))), unsafe.Sizeof(int16(0))*8)))
			for v10 := int32(int32(gameFrame() % 51)); v10 < 256; v10 += 51 {
				var tbl *int16 = (*int16)(memmap.PtrOff(0x587000, uintptr(v10*8)+192088))
				vv1[2] = int16(int32(vv1[0]) + (rad/16)*int32(*(*int16)(unsafe.Add(unsafe.Pointer(tbl), unsafe.Sizeof(int16(0))*0))))
				vv1[3] = int16(int32(vv1[1]) + (rad/16)*int32(*(*int16)(unsafe.Add(unsafe.Pointer(tbl), unsafe.Sizeof(int16(0))*2))))
				sub_499520(int32(dword_5d4594_1522956), &vv1[0], int16(v10), 0, 0)
				sub_499520(int32(dword_5d4594_1522956), &vv1[0], int16(v10), 1, 0)
			}
		}
	}
	return 1
}
