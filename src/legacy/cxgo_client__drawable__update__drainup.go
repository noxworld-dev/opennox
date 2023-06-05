package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_4CD690(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*uint32)(vp.C())
	a2 := int32(uintptr(dr.C()))
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  *uint32
		v7  int32
		v8  *uint32
		v9  int32
		v10 *uint32
		v11 int32
		v12 *uint32
		v13 *int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int8
		v22 int32
		v23 int16
		v24 int32
	)
	if *memmap.PtrUint32(0x5D4594, 1522976) == 0 {
		*memmap.PtrUint32(0x5D4594, 1522976) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DrainManaOrb")))
	}
	if nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c"), 20) < 50 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 432))) != 0 {
			if a2 == -432 {
				return 1
			}
			if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 437))) != 0 {
				v5 = nox_xxx_netClearHighBit_578B30(int16(uint16(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 437)))))
				v6 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(v5).C())
			} else {
				v7 = nox_xxx_netClearHighBit_578B30(int16(uint16(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 437)))))
				v6 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(v7).C())
			}
			v8 = v6
			if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441))) != 0 {
				v9 = nox_xxx_netClearHighBit_578B30(int16(uint16(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441)))))
				v10 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(v9).C())
			} else {
				v11 = nox_xxx_netClearHighBit_578B30(int16(uint16(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441)))))
				v10 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(v11).C())
			}
			v12 = v10
			if v8 == nil || v10 == nil {
				return 1
			}
			v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*3)) + uint32(nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c"), 61)))
			v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*4)) + uint32(nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c"), 62)))
			v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*4)))
			v22 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*3)))
		} else {
			if a2 == -432 {
				return 1
			}
			v2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441))) + nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c"), 31)
			v3 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 443))) + nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c"), 32)
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v22), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 437))
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v4), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 439))
		}
		v13 = (*int32)(unsafe.Pointer(a1))
		v23 = int16(v4)
		v14 = int32(*a1)
		v15 = int32(*a1 - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		v16 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
		v24 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 104)))
		v17 = v2 + v15
		v18 = v3 + *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1)) - v16 - v24
		if v17 < 0 {
			v2 = *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*4)) + v14 + 1
		}
		if v18 < 0 {
			v3 = v16 - v24 + *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1)) + 1
		}
		if v17 >= *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*8)) {
			v2 = *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*2)) + *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*4)) - 1
		}
		if v18 >= *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*9)) {
			v3 = *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*3)) - v24 + v16 - 1
		}
		v19 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1522976), v2, v3))))
		if v19 != 0 {
			v20 = int8(nox_common_randomIntMinMax_415FF0(6, 12, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c"), 93))
			*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v19)), 432)) = uint16(int16(v22))
			*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v19)), 434)) = uint16(v23)
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v19)), 443)) = uint8(v20)
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v19)), 444)) = uint8(int8(nox_common_randomIntMinMax_415FF0(3, 10, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c"), 100)))
		}
	}
	return 1
}
