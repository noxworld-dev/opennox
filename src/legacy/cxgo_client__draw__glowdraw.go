package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func sub_4B6770(a1 *int32, dr *client.Drawable, a3 int32, a4 int32) int {
	var (
		a2     = dr
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		result int32
	)
	var v9 int32
	var v10 int32
	var v11 int32
	var v12 int32
	var v13 int32
	var v14 int32
	var v15 int32
	var v16 int32
	var xLeft Point32
	var v18 int32
	v4 = a2
	v5 = int32(a2.Field_111)
	v6 = int32(a2.Field_112 - uint32(v5))
	v7 = int32(a2.Field_112 - gameFrame())
	v16 = int32(a2.Field_112 - uint32(v5))
	v18 = v7
	if v7 == v6 {
		v18 = func() int32 {
			p := &v7
			*p--
			return *p
		}()
	}
	if v7 > 0 {
		v9 = *a1
		v10 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		v11 = int32(uint32(*a1) + *(*uint32)(unsafe.Add(v4, 12)) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))))
		v12 = int32(*(*uint32)(unsafe.Add(v4, 16)) - uint32(*(*int16)(unsafe.Add(v4, 106))) - uint32(*(*int16)(unsafe.Add(v4, 104))) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))))
		xLeft.X = v11
		v13 = v10 + v12
		xLeft.Y = v13
		if !(v11-10 >= v9 && v13-10 >= v10 && v11+10 < *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) && v13+10 < *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3))) {
			return 1
		}
		v14 = v18 * nox_common_randomIntMinMax_415FF0(0, 4, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 213) / v16
		v15 = v14
		if v14 == 0 {
			return 1
		}
		sub_4B6720(&xLeft, a4, v14*2+1, int8(v14+1))
		nox_client_drawSetColor_434460(a3)
		nox_xxx_drawPointMB_499B70(xLeft.X, xLeft.Y, v15)
		return 1
	} else {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		return 0
	}
}
func nox_thing_magic_sparkle_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*int32)(vp.C())
	if nox_common_randomIntMinMax_415FF0(0, 10, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 317) >= 5 {
		return sub_4B6770(a1, dr, int32(nox_color_white_2523948), int32(dword_5d4594_1313540))
	} else {
		return sub_4B6770(a1, dr, int32(dword_5d4594_1313540), int32(dword_5d4594_1313536))
	}
}
func nox_thing_pixie_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*int32)(vp.C())
	var (
		v2  bool
		v3  int16
		v4  int16
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int64
		v15 Point32
		a2  int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	v2 = nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 503) < 50
	v3 = int16(*(*uint16)(unsafe.Add(a2, 104)))
	if v2 {
		if int32(v3) > 0 {
			v4 = int16(int32(v3) - 1)
			*(*uint16)(unsafe.Add(a2, 104)) = uint16(v4)
		}
	} else if int32(v3) < 35 {
		v4 = int16(int32(v3) + 1)
		*(*uint16)(unsafe.Add(a2, 104)) = uint16(v4)
	}
	v5 = *a1
	v6 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	v7 = int32(uint32(*a1) + *(*uint32)(unsafe.Add(a2, 12)) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))))
	v8 = int32(uint32(v6) + *(*uint32)(unsafe.Add(a2, 16)) - uint32(*(*int16)(unsafe.Add(a2, 106))) - uint32(*(*int16)(unsafe.Add(a2, 104))) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))))
	v15.X = v7
	v15.Y = v8
	if !(v7-10 >= v5 && v8-10 >= v6 && v7+10 < *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) && v8+10 < *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3))) {
		return 1
	}
	sub_4B6720(&v15, *memmap.PtrInt32(0x5D4594, 1313560), 10, 4)
	v9 = int32(uint32(*a1) + *(*uint32)(unsafe.Add(a2, 32)) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))))
	v10 = int32(uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))) + *(*uint32)(unsafe.Add(a2, 36)) - uint32(*(*int16)(unsafe.Add(a2, 104))) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))))
	v11 = v15.X - v9
	v12 = v15.Y - v10
	if v11*v11+v12*v12 > 400 {
		v13 = int64(math.Sqrt(float64(v11*v11 + v12*v12)))
		v9 = v15.X - v11*20/int32(v13)
		v10 = v15.Y - v12*20/int32(v13)
	}
	nox_client_drawSetColor_434460(int32(dword_5d4594_1313564))
	nox_client_drawAddPoint_49F500(v15.X, v15.Y)
	nox_client_drawAddPoint_49F500(v9, v10)
	nox_client_drawLineFromPoints_49E4B0()
	return 1
}
func nox_thing_pixie_dust_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*int32)(vp.C())
	var result int
	if nox_common_randomIntMinMax_415FF0(0, 10, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 554) >= 5 {
		result = sub_4B6770(a1, dr, int32(nox_color_white_2523948), int32(dword_5d4594_1313564))
	} else {
		result = sub_4B6770(a1, dr, int32(dword_5d4594_1313564), *memmap.PtrInt32(0x5D4594, 1313560))
	}
	return result
}
func nox_thing_blue_rain_spark_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*uint32)(vp.C())
	var (
		result int32
		v3     int32
		v4     int32
		v5     int32
		a2     int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	result = int32(sub_4B6970(a1, dr, int32(nox_color_white_2523948), int32(dword_5d4594_1313540)))
	if !(result == 1 && int32(*(*uint8)(unsafe.Add(a2, 296))) >= 5) {
		return int(result)
	}
	v3 = int32(*memmap.PtrUint32(0x5D4594, 1313688))
	if *memmap.PtrUint32(0x5D4594, 1313688) == 0 {
		v3 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("WhiteSpark"))
		*memmap.PtrUint32(0x5D4594, 1313688) = uint32(v3)
	}
	v4 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(v3, int32(*(*uint32)(unsafe.Add(a2, 12))), int32(*(*uint32)(unsafe.Add(a2, 16)))))))
	v5 = v4
	if v4 != 0 {
		if v4 != -432 {
			*(*uint32)(unsafe.Add(v4, 432)) = *(*uint32)(unsafe.Add(a2, 12)) << 12
			*(*uint32)(unsafe.Add(v4, 436)) = *(*uint32)(unsafe.Add(a2, 16)) << 12
			*(*uint8)(unsafe.Add(v4, 299)) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 605)))
			*(*uint32)(unsafe.Add(v5, 440)) = uint32(nox_common_randomIntMinMax_415FF0(1, 1611, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 608))
			*(*uint32)(unsafe.Add(v5, 448)) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(10, 96, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 611))
			*(*uint32)(unsafe.Add(v5, 444)) = gameFrame()
		}
		*(*uint16)(unsafe.Add(v5, 104)) = uint16(int16(nox_common_randomIntMinMax_415FF0(5, 15, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 618)))
		*(*uint16)(unsafe.Add(v5, 106)) = 0
		*(*uint8)(unsafe.Add(v5, 296)) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, 8, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 620)))
		nox_xxx_sprite_45A110_drawable((*client.Drawable)(v5))
	}
	nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
	result = 0
	return int(result)
}
func nox_thing_rain_orb_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*uint32)(vp.C())
	var (
		v2     *int32
		v3     int16
		v4     int32
		v5     int32
		v6     int16
		v7     int32
		v8     int16
		v9     float64
		v10    int16
		v11    int32
		v12    int8
		result int32
		v14    int32
		v15    int32
		v16    int32
		v17    int32
		v18    int32
		v19    int32
		v20    float32
		v21    float32
		xLeft  Point32
		v23    [4]int16
		v24    types.Pointf
		v25    int32
		a2     int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	v2 = (*int32)(a2)
	if dword_5d4594_1313692 == 0 {
		dword_5d4594_1313692 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("RainOrbWhite")))
		*memmap.PtrUint32(0x5D4594, 1313696) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("RainOrbBlue")))
	}
	v3 = int16(*(*uint16)(unsafe.Add(a2, 104)))
	if int32(v3) > 0 {
		v14 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
		v15 = int32(*(*uint32)(unsafe.Add(a2, 16)))
		xLeft.X = int32(*a1 + *(*uint32)(unsafe.Add(a2, 12)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		v16 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - uint32(v14))
		v17 = int32(*memmap.PtrUint32(0x5D4594, 1313588))
		v18 = int32(*(*uint32)(unsafe.Add(a2, 108)))
		xLeft.Y = v15 + v16 - int32(v3)
		if uint32(v18) != dword_5d4594_1313692 {
			v17 = int32(dword_5d4594_1313536)
		}
		sub_4B6720(&xLeft, v17, int32(*(*uint8)(unsafe.Add(a2, 442))), 5)
		v19 = int32(*(*int16)(unsafe.Add(a2, 104))) - int32(*(*int16)(unsafe.Add(a2, 440)))
		nox_client_drawSetColor_434460(v17)
		nox_client_drawAddPoint_49F500(xLeft.X, xLeft.Y)
		nox_xxx_rasterPointRel_49F570(0, v19)
		nox_client_drawLineFromPoints_49E4B0()
		*(*uint16)(unsafe.Add(a2, 440)) = *(*uint16)(unsafe.Add(a2, 104))
		*(*uint16)(unsafe.Add(a2, 104)) += uint16(*(*byte)(unsafe.Add(a2, 296)))
		nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1313592))
		nox_xxx_drawPointMB_499B70(xLeft.X, xLeft.Y, int32(*(*uint8)(unsafe.Add(a2, 442)))/3)
		result = 1
	} else {
		if *memmap.PtrUint32(0x5D4594, 1313700) == 0 {
			*memmap.PtrUint32(0x5D4594, 1313700) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("WhiteMoveOrb")))
			*memmap.PtrUint32(0x5D4594, 1313704) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BlueMoveOrb")))
		}
		v4 = int32(*(*uint32)(unsafe.Add(a2, 12)))
		v5 = int32(*(*uint32)(unsafe.Add(a2, 16)))
		v6 = int16(v5 + 20)
		v25 = int32(uint32(v5) - *(*uint32)(unsafe.Add(a2, 436)))
		v24.X = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) - *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*108))))
		v24.Y = float32(float64(v25))
		v7 = nox_xxx_math_509ED0(&v24)
		v23[2] = int16(v4)
		v23[3] = v6
		v20 = float32(float64(*memmap.PtrFloat32(0x587000, uint32(v7*8)+194136))*150.0 + float64(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*108))))
		v8 = int16(int32(v20))
		v9 = float64(*memmap.PtrFloat32(0x587000, uint32(v7*8)+194140)) * 150.0
		v23[0] = v8
		v21 = float32(v9 + float64(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*109))))
		v10 = int16(int32(v21))
		v11 = int32(*memmap.PtrUint32(0x5D4594, 1313700))
		v23[1] = v10
		if uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*27))) != dword_5d4594_1313692 {
			v11 = int32(*memmap.PtrUint32(0x5D4594, 1313704))
		}
		v12 = int8(nox_common_randomIntMinMax_415FF0(6, 8, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 793))
		sub_499490(v11, (*uint16)(unsafe.Pointer(&v23[0])), 0, 0, v12, 1)
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		result = 0
	}
	return int(result)
}
func Nox_thing_red_spark_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	return sub_4B6970(vp, dr, int32(dword_5d4594_1313532), *memmap.PtrInt32(0x5D4594, 1313528))
}
func Nox_thing_blue_spark_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	return sub_4B6970(vp, dr, int32(dword_5d4594_1313540), int32(dword_5d4594_1313536))
}
func Nox_thing_cyan_spark_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	return sub_4B6970(vp, dr, *memmap.PtrInt32(0x5D4594, 1313548), *memmap.PtrInt32(0x5D4594, 1313544))
}
func Nox_thing_green_spark_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	return sub_4B6970(vp, dr, *memmap.PtrInt32(0x5D4594, 1313584), *memmap.PtrInt32(0x5D4594, 1313580))
}
func Nox_thing_yellow_spark_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	return sub_4B6970(vp, dr, int32(dword_5d4594_1313532), *memmap.PtrInt32(0x5D4594, 1313576))
}
func nox_thing_violet_spark_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	return sub_4B6970(vp, dr, *memmap.PtrInt32(0x5D4594, 1313556), *memmap.PtrInt32(0x5D4594, 1313552))
}
func nox_thing_death_ball_spark_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	return sub_4B6970(vp, dr, *memmap.PtrInt32(0x5D4594, 1313572), *memmap.PtrInt32(0x5D4594, 1313568))
}
func nox_thing_white_spark_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	return sub_4B6970(vp, dr, int32(nox_color_white_2523948), int32(dword_5d4594_1313540))
}
func nox_thing_particle_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	var (
		v2 *uint32
		a2 = dr
	)
	v2 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*108)))
	a2.PosVec.X = int(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*20)) >> 16)
	a2.PosVec.Y = int(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*21)) >> 16)
	v3 := ccall.AsFunc[func(*uint32)](*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*31)))
	if v3 != nil {
		v3(v2)
	}
	return 1
}
func Nox_thing_glow_orb_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*int32)(vp.C())
	return sub_4B6B80(a1, dr, 0)
}
func nox_thing_glow_orb_move_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*int32)(vp.C())
	return sub_4B6B80(a1, dr, 1)
}
