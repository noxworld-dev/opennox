package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_updDrawMagicMissile_4CD9E0(vp *noxrender.Viewport, dr *client.Drawable) int {
	a2 := (*uint32)(dr.C())
	var (
		v2  *uint32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 *uint32
		v14 int32
		v15 int32
		v16 int32
	)
	v2 = a2
	if *memmap.PtrUint32(0x5D4594, 1522984) == 0 {
		*memmap.PtrUint32(0x5D4594, 1522984) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Spark")))
		*memmap.PtrUint32(0x5D4594, 1522988) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Puff")))
		*memmap.PtrUint32(0x5D4594, 1522992) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("MagicMissileTailLink")))
	}
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*8)))
	v15 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*4)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*9)))
	v14 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*8)))
	v16 = 0
	if *memmap.PtrUint32(0x587000, 190108) > 0 {
		for {
			v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*8)))
			v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*9)))
			v6 = v3*nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c"), 40)/100 + v4
			v8 = (v15*nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c"), 41))/100 + v5
			v9 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1522984), v6, v8))))
			v10 = v9
			if v9 != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v9)), 432)) = uint32(v6 << 12)
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v9)), 436)) = uint32(v8 << 12)
				*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v9)), 299)) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c"), 52)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v10)), 440)) = 0
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v10)), 448)) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(3, 10, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c"), 59))
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v10)), 444)) = gameFrame()
				*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v10)), 104)) = 20
				*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v10)), 296)) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, 6, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c"), 65)))
				nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(uintptr(v10))))
			}
			if func() int32 {
				p := &v16
				*p++
				return *p
			}() >= *memmap.PtrInt32(0x587000, 190108) {
				break
			}
			v3 = v14
		}
	}
	v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*108)))
	if (*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3))-uint32(v11))*(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3))-uint32(v11))+(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4))-*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*109)))*(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4))-*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*109))) > 200 {
		v12 = (*uint32)(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1522992), v11, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*109)))).C())
		*(*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*108)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*109)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4))
		nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(v12)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*108)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*109)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4))
		nox_xxx_spriteTransparentDecay_49B950((*client.Drawable)(unsafe.Pointer(v12)), int32(gameFPS()/3))
	}
	return 1
}
