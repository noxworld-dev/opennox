package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func sub_499490(a1 int32, a2 *uint16, a3 int32, a4 int32, a5 int8, a6 int8) {
	var (
		result *uint32
		v7     *uint32
	)
	result = (*uint32)(nox_xxx_spriteLoadAdd_45A360_drawable(a1, a3+int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(uint16(0))*2))), a4+int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(uint16(0))*3)))).C())
	v7 = result
	if result != nil {
		*((*uint16)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(uint16(0))*216))) = *a2
		*((*uint16)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(uint16(0))*217))) = *(*uint16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(uint16(0))*1))
		*((*uint8)(unsafe.Add(unsafe.Pointer(result), 443))) = uint8(a5)
		*((*uint8)(unsafe.Add(unsafe.Pointer(result), 444))) = uint8(int8(nox_common_randomIntMinMax_415FF0(3, 10, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 138)))
		*((*uint8)(unsafe.Add(unsafe.Pointer(v7), 446))) = uint8(a6)
		*((*uint8)(unsafe.Add(unsafe.Pointer(v7), 445))) = uint8(a6)
		nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(v7)))
	}
}
func sub_499520(a1 int32, a2 *int16, a3 int16, a4 int8, a5 int8) {
	var (
		v5     int32
		v6     int32
		result *uint32
		v8     *uint32
	)
	v6 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(int16(0))*2)))
	v5 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(int16(0))*3)))
	result = (*uint32)(nox_xxx_spriteLoadAdd_45A360_drawable(a1, v6, v5).C())
	v8 = result
	if result != nil {
		*((*uint16)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(uint16(0))*216))) = uint16(*(*int16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(int16(0))*0)))
		*((*uint16)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(uint16(0))*217))) = uint16(*(*int16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(int16(0))*1)))
		*((*uint16)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(uint16(0))*218))) = uint16(int16(v6))
		*((*uint16)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(uint16(0))*219))) = uint16(int16(v5))
		*((*uint8)(unsafe.Add(unsafe.Pointer(result), 442))) = uint8(int8(a3))
		*((*uint16)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(uint16(0))*220))) = uint16(int16(int64(math.Sqrt(float64((v6-int32(*(*int16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(int16(0))*0))))*(v6-int32(*(*int16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(int16(0))*0)))) + (v5-int32(*(*int16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(int16(0))*1))))*(v5-int32(*(*int16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(int16(0))*1)))))))))
		*((*uint8)(unsafe.Add(unsafe.Pointer(result), 443))) = uint8(a4)
		*((*uint8)(unsafe.Add(unsafe.Pointer(result), 444))) = uint8(int8(nox_common_randomIntMinMax_415FF0(3, 10, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 182)))
		*((*uint8)(unsafe.Add(unsafe.Pointer(v8), 446))) = uint8(a5)
		*((*uint8)(unsafe.Add(unsafe.Pointer(v8), 445))) = uint8(a5)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*116)) = uint32(uintptr(ccall.FuncAddr(sub_4CA720)))
		*((*uint16)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(uint16(0))*254))) = uint16(a3)
		nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(v8)))
	}
}
func nox_xxx_makePointFxCli_499610(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int32) int32 {
	var (
		result int32
		v7     int32
		v8     int32
	)
	result = a2
	if a2 > 0 {
		for {
			v7 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(a1, a5, a6))))
			v8 = v7
			if v7 != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 432)) = *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 12)) << 12
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 436)) = *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 16)) << 12
				*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 299)) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 227)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v8)), 440)) = uint32(nox_common_randomIntMinMax_415FF0(1, a3, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 230))
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v8)), 448)) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(a4, 64, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 233))
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v8)), 444)) = gameFrame()
				*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v8)), 104)) = 0
				*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v8)), 296)) = uint8(int8(nox_common_randomIntMinMax_415FF0(2, 10, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 239)))
				nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(uintptr(v8))))
			}
			result = func() int32 {
				p := &a2
				*p--
				return *p
			}()
			if a2 == 0 {
				break
			}
		}
	}
	return result
}
func nox_xxx_drawEnergyBolt_499710(a1 int32, a2 int32, a3 int16, a4 int32) int32 {
	var (
		v4     int32
		v5     int32
		result int32
		v7     int32
	)
	v7 = 2
	for {
		v4 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(a4, a1, a2))))
		v5 = v4
		if v4 != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v4)), 432)) = uint32(a1 << 12)
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v4)), 436)) = uint32(a2 << 12)
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v4)), 299)) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 268)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v5)), 440)) = uint32(nox_common_randomIntMinMax_415FF0(1, 3000, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 271))
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v5)), 448)) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(5, 20, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 274))
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v5)), 444)) = gameFrame()
			*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v5)), 104)) = uint16(int16(int32(a3) + nox_common_randomIntMinMax_415FF0(0, 20, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 279)))
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v5)), 296)) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, 4, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 280)))
			nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(uintptr(v5))))
		}
		result = func() int32 {
			p := &v7
			*p--
			return *p
		}()
		if v7 == 0 {
			break
		}
	}
	return result
}
func sub_499950(a1 int32, a2 *int2, a3 *int2, a4 uint16, a5 int8) int32 {
	var (
		result int32
		v6     int32
	)
	result = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(a1, a2.field_0, a2.field_4))))
	v6 = result
	if result != 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(result)), 104)) = uint32(a4)
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(result)), 296)) = uint8(a5)
		*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(result)), 440)) = a4
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(result)), 442)) = uint8(int8(nox_common_randomIntMinMax_415FF0(3, 10, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 406)))
		*(*int2)(unsafe.Add(unsafe.Pointer(uintptr(v6)), 432)) = *a3
		nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(uintptr(v6))))
	}
	return result
}
func nox_xxx_makeLightningParticles_4999D0(a1 int32, a2 *int2, a3 *int2) int32 {
	var (
		v3  *int2
		v4  int32
		v5  int32
		v6  int64
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v14 int32
		v15 int32
		v16 int32
		v17 *int2
	)
	v3 = a2
	v4 = a3.field_0 - a2.field_0
	v5 = a3.field_4 - a2.field_4
	v14 = a3.field_0 - a2.field_0
	v15 = v5
	v6 = int64(math.Sqrt(float64(v4*v4 + v5*v5)))
	v7 = int32(v6)
	v16 = int32(v6)
	if int32(v6) > 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v6), 4*0)) = uint32(nox_common_randomIntMinMax_415FF0(0, int32(v6), internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 437))
		v8 = int32(v6)
		v17 = (*int2)(unsafe.Pointer(uintptr(v6)))
		if int32(v6) <= v7 {
			for {
				v9 = v3.field_0 + v4*v8/v7
				v10 = v3.field_4 + v5*v8/v7
				v11 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(a1, v9, v10))))
				v12 = v11
				if v11 != 0 {
					if v11 != -432 {
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v11)), 432)) = uint32(v9 << 12)
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v11)), 436)) = uint32(v10 << 12)
						*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v11)), 299)) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 458)))
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v12)), 440)) = uint32(nox_common_randomIntMinMax_415FF0(1, 3000, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 461))
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v12)), 448)) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(5, 20, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 464))
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v12)), 444)) = gameFrame()
					}
					*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v12)), 104)) = uint16(int16(nox_common_randomIntMinMax_415FF0(15, 30, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 471)))
					*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v12)), 296)) = uint8(int8(nox_common_randomIntMinMax_415FF0(-4, 4, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 472)))
					nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(uintptr(v12))))
					v7 = v16
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v6), 4*0)) = uint32(nox_common_randomIntMinMax_415FF0(8, 100, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 439))
				v17 = (*int2)(unsafe.Add(unsafe.Pointer(v17), v6))
				if int32(uintptr(unsafe.Pointer(v17))) > v7 {
					break
				}
				v3 = a2
				v4 = v14
				v5 = v15
				v8 = int32(uintptr(unsafe.Pointer(v17)))
			}
		}
	}
	return int32(v6)
}
func nox_xxx_draw_499E70(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int32, a7 int32) int32 {
	var (
		v7     int32
		v8     int32
		v9     int8
		v10    int32
		v11    int32
		result int32
		v13    int32
	)
	v13 = 100
	for {
		if a6 == 2 {
			v7 = a3
			v8 = a2 + nox_common_randomIntMinMax_415FF0(0, a4, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 555)
		} else {
			v8 = a2
			v7 = a3 + nox_common_randomIntMinMax_415FF0(0, a5, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 563)
		}
		v9 = int8(nox_common_randomIntMinMax_415FF0(2, 5, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 568))
		v10 = nox_common_randomIntMinMax_415FF0(-40, -20, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 571)
		if a7 == 1 {
			v11 = nox_common_randomIntMinMax_415FF0(-20, 0, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 573)
		} else {
			v11 = nox_common_randomIntMinMax_415FF0(0, 20, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 575)
		}
		nox_client_newScreenParticle_431540(a1, v8, v7, v11, v10, 1, v9, 0, 0, 1)
		result = func() int32 {
			p := &v13
			*p--
			return *p
		}()
		if v13 == 0 {
			break
		}
	}
	return result
}
func sub_49A150(a1 *int2, a2 int32, a3 uint8) int32 {
	var (
		v3     int32
		result int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
	)
	v3 = int32(a3)*2400/math.MaxUint8 + 200
	result = int32(uint32(a3) * 84215050)
	v5 = int32(a3)*10/math.MaxUint8 + 5
	if int32(a3)*180/math.MaxUint8+10 > 0 {
		v8 = int32(a3)*180/math.MaxUint8 + 10
		for {
			v6 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(a2, a1.field_0, a1.field_4))))
			v7 = v6
			if v6 != 0 {
				if v6 != -432 {
					*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v6)), 432)) = *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v6)), 12)) << 12
					*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v6)), 436)) = *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v6)), 16)) << 12
					*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v6)), 299)) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 822)))
					*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 440)) = uint32(nox_common_randomIntMinMax_415FF0(1, v3, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 825))
					*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 448)) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(v5, 96, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 828))
					*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 444)) = gameFrame()
				}
				*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 104)) = uint16(int16(nox_common_randomIntMinMax_415FF0(5, 15, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 834)))
				*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 106)) = 0
				*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 296)) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, 8, internCStr("C:\\NoxPost\\src\\client\\Draw\\Fx.c"), 836)))
				nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(uintptr(v7))))
			}
			result = func() int32 {
				p := &v8
				*p--
				return *p
			}()
			if v8 == 0 {
				break
			}
		}
	}
	return result
}
