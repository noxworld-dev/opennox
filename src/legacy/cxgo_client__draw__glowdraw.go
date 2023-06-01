package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_4B6770(a1 *int32, dr *nox_drawable, a3 int32, a4 int32) int32 {
	var (
		a2     int32 = int32(uintptr(unsafe.Pointer(dr)))
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		result int32
	)
	_ = result
	var v9 int32
	var v10 int32
	var v11 int32
	var v12 int32
	var v13 int32
	var v14 int32
	var v15 int32
	var v16 int32
	var xLeft int2
	var v18 int32
	v4 = a2
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 444))))
	v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 448))) - uint32(v5))
	v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 448))) - gameFrame())
	v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 448))) - uint32(v5))
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
		v11 = int32(uint32(*a1) + *(*uint32)(unsafe.Pointer(uintptr(v4 + 12))) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))))
		v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 16))) - uint32(*(*int16)(unsafe.Pointer(uintptr(v4 + 106)))) - uint32(*(*int16)(unsafe.Pointer(uintptr(v4 + 104)))) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))))
		xLeft.field_0 = v11
		v13 = v10 + v12
		xLeft.field_4 = v13
		if v11-10 >= v9 && v13-10 >= v10 && v11+10 < *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) && v13+10 < *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) {
			v14 = v18 * nox_common_randomIntMinMax_415FF0(0, 4, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 213) / v16
			v15 = v14
			if v14 != 0 {
				sub_4B6720(&xLeft, a4, v14*2+1, int8(v14+1))
				nox_client_drawSetColor_434460(a3)
				nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, v15)
			}
		}
		return 1
	} else {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		return 0
	}
}
func nox_thing_magic_sparkle_draw(a1 *int32, dr *nox_drawable) int32 {
	if nox_common_randomIntMinMax_415FF0(0, 10, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 317) >= 5 {
		return sub_4B6770(a1, dr, int32(nox_color_white_2523948), *(*int32)(unsafe.Pointer(&dword_5d4594_1313540)))
	} else {
		return sub_4B6770(a1, dr, *(*int32)(unsafe.Pointer(&dword_5d4594_1313540)), *(*int32)(unsafe.Pointer(&dword_5d4594_1313536)))
	}
}
func nox_thing_pixie_draw(a1 *int32, dr *nox_drawable) int32 {
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
		v15 int2
		a2  int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	v2 = nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 503) < 50
	v3 = int16(*(*uint16)(unsafe.Pointer(uintptr(a2 + 104))))
	if v2 {
		if int32(v3) > 0 {
			v4 = int16(int32(v3) - 1)
			*(*uint16)(unsafe.Pointer(uintptr(a2 + 104))) = uint16(v4)
		}
	} else if int32(v3) < 35 {
		v4 = int16(int32(v3) + 1)
		*(*uint16)(unsafe.Pointer(uintptr(a2 + 104))) = uint16(v4)
	}
	v5 = *a1
	v6 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	v7 = int32(uint32(*a1) + *(*uint32)(unsafe.Pointer(uintptr(a2 + 12))) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))))
	v8 = int32(uint32(v6) + *(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) - uint32(*(*int16)(unsafe.Pointer(uintptr(a2 + 106)))) - uint32(*(*int16)(unsafe.Pointer(uintptr(a2 + 104)))) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))))
	v15.field_0 = v7
	v15.field_4 = v8
	if v7-10 >= v5 && v8-10 >= v6 && v7+10 < *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) && v8+10 < *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) {
		sub_4B6720(&v15, *memmap.PtrInt32(0x5D4594, 1313560), 10, 4)
		v9 = int32(uint32(*a1) + *(*uint32)(unsafe.Pointer(uintptr(a2 + 32))) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))))
		v10 = int32(uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))) + *(*uint32)(unsafe.Pointer(uintptr(a2 + 36))) - uint32(*(*int16)(unsafe.Pointer(uintptr(a2 + 104)))) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))))
		v11 = v15.field_0 - v9
		v12 = v15.field_4 - v10
		if v11*v11+v12*v12 > 400 {
			v13 = int64(math.Sqrt(float64(v11*v11 + v12*v12)))
			v9 = v15.field_0 - v11*20/int32(v13)
			v10 = v15.field_4 - v12*20/int32(v13)
		}
		nox_client_drawSetColor_434460(*(*int32)(unsafe.Pointer(&dword_5d4594_1313564)))
		nox_client_drawAddPoint_49F500(v15.field_0, v15.field_4)
		nox_client_drawAddPoint_49F500(v9, v10)
		nox_client_drawLineFromPoints_49E4B0()
	}
	return 1
}
func nox_thing_pixie_dust_draw(a1 *int32, dr *nox_drawable) int32 {
	var result int32
	if nox_common_randomIntMinMax_415FF0(0, 10, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 554) >= 5 {
		result = sub_4B6770(a1, dr, int32(nox_color_white_2523948), *(*int32)(unsafe.Pointer(&dword_5d4594_1313564)))
	} else {
		result = sub_4B6770(a1, dr, *(*int32)(unsafe.Pointer(&dword_5d4594_1313564)), *memmap.PtrInt32(0x5D4594, 1313560))
	}
	return result
}
func nox_thing_blue_rain_spark_draw(a1 *uint32, dr *nox_drawable) int32 {
	var (
		result int32
		v3     int32
		v4     int32
		v5     int32
		a2     int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	result = sub_4B6970(a1, dr, int32(nox_color_white_2523948), *(*int32)(unsafe.Pointer(&dword_5d4594_1313540)))
	if result == 1 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 296)))) >= 5 {
		v3 = int32(*memmap.PtrUint32(0x5D4594, 1313688))
		if *memmap.PtrUint32(0x5D4594, 1313688) == 0 {
			v3 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("WhiteSpark"))
			*memmap.PtrUint32(0x5D4594, 1313688) = uint32(v3)
		}
		v4 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(v3, int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 12)))), int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))))))
		v5 = v4
		if v4 != 0 {
			if v4 != -432 {
				*(*uint32)(unsafe.Pointer(uintptr(v4 + 432))) = *(*uint32)(unsafe.Pointer(uintptr(a2 + 12))) << 12
				*(*uint32)(unsafe.Pointer(uintptr(v4 + 436))) = *(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) << 12
				*(*uint8)(unsafe.Pointer(uintptr(v4 + 299))) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 605)))
				*(*uint32)(unsafe.Pointer(uintptr(v5 + 440))) = uint32(nox_common_randomIntMinMax_415FF0(1, 1611, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 608))
				*(*uint32)(unsafe.Pointer(uintptr(v5 + 448))) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(10, 96, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 611))
				*(*uint32)(unsafe.Pointer(uintptr(v5 + 444))) = gameFrame()
			}
			*(*uint16)(unsafe.Pointer(uintptr(v5 + 104))) = uint16(int16(nox_common_randomIntMinMax_415FF0(5, 15, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 618)))
			*(*uint16)(unsafe.Pointer(uintptr(v5 + 106))) = 0
			*(*uint8)(unsafe.Pointer(uintptr(v5 + 296))) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, 8, internCStr("C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c"), 620)))
			nox_xxx_sprite_45A110_drawable((*nox_drawable)(unsafe.Pointer(uintptr(v5))))
		}
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		result = 0
	}
	return result
}
func nox_thing_rain_orb_draw(a1 *uint32, dr *nox_drawable) int32 {
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
		xLeft  int2
		v23    [4]int16
		v24    float2
		v25    int32
		a2     int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	v2 = (*int32)(unsafe.Pointer(uintptr(a2)))
	if dword_5d4594_1313692 == 0 {
		dword_5d4594_1313692 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("RainOrbWhite")))
		*memmap.PtrUint32(0x5D4594, 1313696) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("RainOrbBlue")))
	}
	v3 = int16(*(*uint16)(unsafe.Pointer(uintptr(a2 + 104))))
	if int32(v3) > 0 {
		v14 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
		v15 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
		xLeft.field_0 = int32(*a1 + *(*uint32)(unsafe.Pointer(uintptr(a2 + 12))) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		v16 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - uint32(v14))
		v17 = int32(*memmap.PtrUint32(0x5D4594, 1313588))
		v18 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 108))))
		xLeft.field_4 = v15 + v16 - int32(v3)
		if uint32(v18) != dword_5d4594_1313692 {
			v17 = int32(dword_5d4594_1313536)
		}
		sub_4B6720(&xLeft, v17, int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 442)))), 5)
		v19 = int32(*(*int16)(unsafe.Pointer(uintptr(a2 + 104)))) - int32(*(*int16)(unsafe.Pointer(uintptr(a2 + 440))))
		nox_client_drawSetColor_434460(v17)
		nox_client_drawAddPoint_49F500(xLeft.field_0, xLeft.field_4)
		nox_xxx_rasterPointRel_49F570(0, v19)
		nox_client_drawLineFromPoints_49E4B0()
		*(*uint16)(unsafe.Pointer(uintptr(a2 + 440))) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 104)))
		*(*uint16)(unsafe.Pointer(uintptr(a2 + 104))) += uint16(*(*byte)(unsafe.Pointer(uintptr(a2 + 296))))
		nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1313592))
		nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 442))))/3)
		result = 1
	} else {
		if *memmap.PtrUint32(0x5D4594, 1313700) == 0 {
			*memmap.PtrUint32(0x5D4594, 1313700) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("WhiteMoveOrb")))
			*memmap.PtrUint32(0x5D4594, 1313704) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BlueMoveOrb")))
		}
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 12))))
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
		v6 = int16(v5 + 20)
		v25 = int32(uint32(v5) - *(*uint32)(unsafe.Pointer(uintptr(a2 + 436))))
		v24.field_0 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) - *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*108))))
		v24.field_4 = float32(float64(v25))
		v7 = nox_xxx_math_509ED0(&v24)
		v23[2] = int16(v4)
		v23[3] = v6
		v20 = float32(float64(*mem_getFloatPtr(0x587000, uint32(v7*8)+194136))*150.0 + float64(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*108))))
		v8 = int16(int32(v20))
		v9 = float64(*mem_getFloatPtr(0x587000, uint32(v7*8)+194140)) * 150.0
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
	return result
}
func nox_thing_red_spark_draw(a1 *uint32, dr *nox_drawable) int32 {
	return sub_4B6970(a1, dr, *(*int32)(unsafe.Pointer(&dword_5d4594_1313532)), *memmap.PtrInt32(0x5D4594, 1313528))
}
func nox_thing_blue_spark_draw(a1 *uint32, dr *nox_drawable) int32 {
	return sub_4B6970(a1, dr, *(*int32)(unsafe.Pointer(&dword_5d4594_1313540)), *(*int32)(unsafe.Pointer(&dword_5d4594_1313536)))
}
func nox_thing_cyan_spark_draw(a1 *uint32, dr *nox_drawable) int32 {
	return sub_4B6970(a1, dr, *memmap.PtrInt32(0x5D4594, 1313548), *memmap.PtrInt32(0x5D4594, 1313544))
}
func nox_thing_green_spark_draw(a1 *uint32, dr *nox_drawable) int32 {
	return sub_4B6970(a1, dr, *memmap.PtrInt32(0x5D4594, 1313584), *memmap.PtrInt32(0x5D4594, 1313580))
}
func nox_thing_yellow_spark_draw(a1 *uint32, dr *nox_drawable) int32 {
	return sub_4B6970(a1, dr, *(*int32)(unsafe.Pointer(&dword_5d4594_1313532)), *memmap.PtrInt32(0x5D4594, 1313576))
}
func nox_thing_violet_spark_draw(a1 *uint32, dr *nox_drawable) int32 {
	return sub_4B6970(a1, dr, *memmap.PtrInt32(0x5D4594, 1313556), *memmap.PtrInt32(0x5D4594, 1313552))
}
func nox_thing_death_ball_spark_draw(a1 *uint32, dr *nox_drawable) int32 {
	return sub_4B6970(a1, dr, *memmap.PtrInt32(0x5D4594, 1313572), *memmap.PtrInt32(0x5D4594, 1313568))
}
func nox_thing_white_spark_draw(a1 *uint32, dr *nox_drawable) int32 {
	return sub_4B6970(a1, dr, int32(nox_color_white_2523948), *(*int32)(unsafe.Pointer(&dword_5d4594_1313540)))
}
func nox_thing_particle_draw(a1 int32, dr *nox_drawable) int32 {
	var (
		v2 *uint32
		v3 func(*uint32)
		a2 *uint32 = (*uint32)(unsafe.Pointer(dr))
	)
	v2 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*108)))))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*20)) >> 16
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*4)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*21)) >> 16
	v3 = asFuncT[func(*uint32)](unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*31)))))
	if v3 != nil {
		v3(v2)
	}
	return 1
}
func nox_thing_glow_orb_draw(a1 *int32, dr *nox_drawable) int32 {
	return sub_4B6B80(a1, dr, 0)
}
func nox_thing_glow_orb_move_draw(a1 *int32, dr *nox_drawable) int32 {
	return sub_4B6B80(a1, dr, 1)
}
