package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_updDrawAddRndSpark_4CDFA0(a1 int32, a2 *uint32) *uint32 {
	var (
		result *uint32
		v3     *uint32
		v4     *uint32
	)
	if *memmap.PtrUint32(0x5D4594, 1523008) == 0 {
		*memmap.PtrUint32(0x5D4594, 1523008) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DeathBallSpark")))
	}
	result = a2
	if int32(uintptr(unsafe.Pointer(a2))) > 0 {
		v3 = a2
		for {
			result = (*uint32)(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1523008), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 12))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 16)))).C())
			v4 = result
			if result != nil {
				*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*108)) = *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 12)) << 12
				*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*109)) = *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 16)) << 12
				*((*uint8)(unsafe.Add(unsafe.Pointer(result), 299))) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c"), 37)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*110)) = uint32(nox_common_randomIntMinMax_415FF0(1000, 3000, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c"), 40))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*112)) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(10, 40, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c"), 43))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*111)) = gameFrame()
				*((*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*52))) = 22
				*((*uint8)(unsafe.Add(unsafe.Pointer(v4), 296))) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, 4, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c"), 49)))
				nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(v4)))
			}
			v3 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), -1))
			if v3 == nil {
				break
			}
		}
	}
	return result
}
func nox_xxx_updDrawDBallCharge_4CE0C0(vp *noxrender.Viewport, dr *client.Drawable) int {
	a2 := int32(uintptr(dr.C()))
	var (
		v2  int32
		v3  int16
		v4  int32
		v5  int16
		v6  int16
		v7  int32
		v9  int32
		v10 int8
		v11 [4]int16
	)
	if *memmap.PtrUint32(0x5D4594, 1523012) == 0 {
		*memmap.PtrUint32(0x5D4594, 1523012) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CharmOrb")))
	}
	v2 = 10
	v3 = int16(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 16)))
	v11[0] = int16(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 12)))
	v11[1] = v3
	for {
		v4 = nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c"), 102)
		v5 = int16(nox_common_randomIntMinMax_415FF0(2, 8, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c"), 105))
		v6 = int16(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 16))) + int32(v5)*int32(*memmap.PtrInt16(0x587000, uintptr(v4*8)+192092)))
		v11[2] = int16(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 12))) + int32(v5)*int32(*memmap.PtrInt16(0x587000, uintptr(v4*8)+192088)))
		v11[3] = v6
		if nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c"), 112) < 50 {
			v10 = int8(nox_common_randomIntMinMax_415FF0(6, 10, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c"), 116))
			v9 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c"), 115)
			v7 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c"), 114)
			sub_499490(*memmap.PtrInt32(0x5D4594, 1523012), (*uint16)(unsafe.Pointer(&v11[0])), v7, v9, v10, 0)
		}
		v2--
		if v2 == 0 {
			break
		}
	}
	return 1
}
