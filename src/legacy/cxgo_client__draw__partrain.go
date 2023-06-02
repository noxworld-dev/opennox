package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_thing_blue_rain_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := int32(uintptr(vp.C()))
	var (
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 int32
		v8 int32
		v9 int32
		a2 int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	if noxflags.HasGame(0x200000) {
		return 1
	}
	if *memmap.PtrUint32(0x5D4594, 1313716) == 0 {
		*memmap.PtrUint32(0x5D4594, 1313716) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BlueRainSpark")))
	}
	v3 = a2
	v9 = 2
	for {
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 12))) + uint32(nox_common_randomIntMinMax_415FF0(-10, 10, internCStr("C:\\NoxPost\\src\\client\\Draw\\PartRain.c"), 42)))
		v5 = nox_common_randomIntMinMax_415FF0(-10, 10, internCStr("C:\\NoxPost\\src\\client\\Draw\\PartRain.c"), 43)
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 16))) + uint32(v5))
		v7 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1313716), v4, v6))))
		v8 = v7
		if v7 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 432))) = uint32(v4 << 12)
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 436))) = uint32(v6 << 12)
			*(*uint8)(unsafe.Pointer(uintptr(v7 + 299))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 440))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 448))) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(90, 120, internCStr("C:\\NoxPost\\src\\client\\Draw\\PartRain.c"), 63))
			*(*uint32)(unsafe.Pointer(uintptr(v8 + 444))) = gameFrame()
			*(*uint16)(unsafe.Pointer(uintptr(v8 + 106))) = 0
			*(*uint8)(unsafe.Pointer(uintptr(v8 + 296))) = 251
			*(*uint16)(unsafe.Pointer(uintptr(v8 + 104))) = uint16(int16(v6 - int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 20))))))
			nox_xxx_sprite_45A110_drawable((*nox_drawable)(unsafe.Pointer(uintptr(v8))))
		}
		v9--
		if v9 == 0 {
			break
		}
	}
	return 1
}
func nox_thing_levelup_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := int32(uintptr(vp.C()))
	var v2 int32
	v2 = int32(*memmap.PtrUint32(0x5D4594, 1313708))
	if *memmap.PtrUint32(0x5D4594, 1313708) == 0 {
		v2 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("RainOrbWhite"))
		*memmap.PtrUint32(0x5D4594, 1313708) = uint32(v2)
	}
	nox_thing_falling_sparks_draw_4B7740(v2, a1, dr)
	return 1
}
func nox_thing_oblivion_up_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := int32(uintptr(vp.C()))
	var v2 int32
	v2 = int32(*memmap.PtrUint32(0x5D4594, 1313712))
	if *memmap.PtrUint32(0x5D4594, 1313712) == 0 {
		v2 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("RainOrbBlue"))
		*memmap.PtrUint32(0x5D4594, 1313712) = uint32(v2)
	}
	nox_thing_falling_sparks_draw_4B7740(v2, a1, dr)
	return 1
}
