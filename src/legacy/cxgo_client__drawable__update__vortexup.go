package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_updDrawVortexSource_4CC950(vp *noxrender.Viewport, dr *client.Drawable) int {
	a2 := int32(uintptr(dr.C()))
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int8
		v6 int32
		v7 int32
		v9 int32
	)
	if *memmap.PtrUint32(0x5D4594, 1522952) == 0 {
		*memmap.PtrUint32(0x5D4594, 1522952) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("WhiteVortexOrb")))
		*memmap.PtrUint32(0x5D4594, 1522944) = nox_color_rgb_4344A0(200, 200, 200)
		*memmap.PtrUint32(0x5D4594, 1522948) = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, math.MaxUint8)
	}
	v2 = int32(*memmap.PtrUint32(0x5D4594, 1522944))
	v3 = int32(*memmap.PtrUint32(0x5D4594, 1522952))
	v9 = int32(*memmap.PtrUint32(0x5D4594, 1522948))
	v4 = nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c"), 54)
	v5 = int8(v4)
	v6 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(v3, int32(*(*uint32)(unsafe.Add(a2, 12))+uint32(*memmap.PtrInt32(0x587000, uintptr(v4*8)+192088)*50/16)), int32(*(*uint32)(unsafe.Add(a2, 16))+uint32(*memmap.PtrInt32(0x587000, uintptr(v4*8)+192092)*50/16))))))
	v7 = v6
	if v6 == 0 {
		return 1
	}
	*(*uint8)(unsafe.Add(v6, 448)) = uint8(v5)
	*(*uint16)(unsafe.Add(a2, 104)) = 0
	*(*uint8)(unsafe.Add(v6, 449)) = uint8(int8(nox_common_randomIntMinMax_415FF0(2, 3, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c"), 74)))
	if nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c"), 75) > 50 {
		*(*uint8)(unsafe.Add(v7, 449)) = -*(*uint8)(unsafe.Add(v7, 449))
	}
	*(*uint8)(unsafe.Add(v7, 451)) = 1
	*(*uint8)(unsafe.Add(v7, 450)) = 50
	*(*uint32)(unsafe.Add(v7, 440)) = *(*uint32)(unsafe.Add(a2, 12))
	*(*uint32)(unsafe.Add(v7, 444)) = *(*uint32)(unsafe.Add(a2, 16))
	*(*uint32)(unsafe.Add(v7, 432)) = uint32(v2)
	*(*uint32)(unsafe.Add(v7, 436)) = uint32(v9)
	nox_xxx_sprite_45A110_drawable((*client.Drawable)(v7))
	nox_xxx_spriteToSightDestroyList_49BAB0_drawable((*client.Drawable)(v7))
	return 1
}
