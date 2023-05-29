package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/cmath"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_4CCEA0(a1 *uint32, a2 int32) {
	var (
		v2  *uint32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v8  int32
		v9  int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 float2
		v18 int32
	)
	if *memmap.PtrUint32(0x5D4594, 1522964) == 0 {
		*memmap.PtrUint32(0x5D4594, 1522964) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Spark")))
	}
	v2 = a1
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)))
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)))
	v18 = v4
	v15 = v3
	v6 = int32(cmath.Abs(int64(v4)) + cmath.Abs(int64(v5)))
	if v6/7 > 0 {
		v16 = v6 / 7
		for {
			v8 = nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c"), 46)
			v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*8)) + uint32(v4*v8/100))
			v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*9)) + uint32((v3*v8)/100))
			v12 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1522964), v9, v11))))
			if v12 != 0 {
				*(*uint32)(unsafe.Pointer(uintptr(v12 + 432))) = uint32(v9 << 12)
				*(*uint32)(unsafe.Pointer(uintptr(v12 + 436))) = uint32(v11 << 12)
				v17.field_0 = float32(float64(-v18))
				v17.field_4 = float32(float64(-v15))
				v13 = nox_common_randomIntMinMax_415FF0(-25, 25, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c"), 63)
				v14 = nox_xxx_math_509ED0(&v17) + v13
				if v14 < 0 {
					v14 += int32(uint32(math.MaxUint8-v14) >> 8 << 8)
				}
				*(*uint8)(unsafe.Pointer(uintptr(v12 + 299))) = uint8(int8(v14))
				*(*uint32)(unsafe.Pointer(uintptr(v12 + 440))) = uint32(a2 * nox_common_randomIntMinMax_415FF0(100, 300, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c"), 74))
				*(*uint32)(unsafe.Pointer(uintptr(v12 + 448))) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(30, 45, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c"), 77))
				*(*uint32)(unsafe.Pointer(uintptr(v12 + 444))) = gameFrame()
				*(*uint16)(unsafe.Pointer(uintptr(v12 + 104))) = 28
				*(*uint16)(unsafe.Pointer(uintptr(v12 + 106))) = 0
				*(*uint8)(unsafe.Pointer(uintptr(v12 + 296))) = uint8(int8(nox_common_randomIntMinMax_415FF0(-2, 4, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c"), 84)))
				nox_xxx_sprite_45A110_drawable((*nox_drawable)(unsafe.Pointer(uintptr(v12))))
			}
			v16--
			if v16 == 0 {
				break
			}
			v3 = v15
			v4 = v18
		}
	}
}
