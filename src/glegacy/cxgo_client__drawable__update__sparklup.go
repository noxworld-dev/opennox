package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"math"
	"unsafe"
)

func nox_xxx_updDrawSparkleTrail_4CDBF0(a1 int32, a2 *uint32) int32 {
	var (
		v2  *uint32
		v3  int32
		v4  int32
		v5  int32
		v6  bool
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
	)
	v2 = a2
	v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*8)))
	v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*4)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*9)))
	if *memmap.PtrUint32(0x5D4594, 1522996) == 0 {
		*memmap.PtrUint32(0x5D4594, 1522996) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BlueSpark")))
	}
	v8 = 0
	v12 = 0
	v9 = 5
	for {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*8)) + uint32(v12/5) + uint32(nox_common_randomIntMinMax_415FF0(-3, 3, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c"), 28)))
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*9)) + uint32(nox_common_randomIntMinMax_415FF0(-3, 3, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c"), 29)) + uint32(v8/5))
		v5 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1522996), v3, v4))))
		if v5 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 300))) = uint32(funAddr(nox_thing_pixie_dust_draw))
			nox_xxx_spriteChangeLightColor_484BE0((*uint32)(unsafe.Pointer(uintptr(v5+136))), math.MaxUint8, 200, 75)
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 432))) = uint32(v3 << 12)
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 436))) = uint32(v4 << 12)
			*(*uint8)(unsafe.Pointer(uintptr(v5 + 299))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 440))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 448))) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(2, 10, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c"), 51))
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 444))) = gameFrame()
			*(*uint16)(unsafe.Pointer(uintptr(v5 + 104))) = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v2))), unsafe.Sizeof(uint16(0))*52)))
			*(*uint16)(unsafe.Pointer(uintptr(v5 + 106))) = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v2))), unsafe.Sizeof(uint16(0))*53)))
			*(*uint8)(unsafe.Pointer(uintptr(v5 + 296))) = 0
			nox_xxx_sprite_45A110_drawable((*nox_drawable)(unsafe.Pointer(uintptr(v5))))
		}
		v12 += v10
		v6 = v9 == 1
		v8 += v11
		v9--
		if v6 {
			break
		}
	}
	return 1
}
