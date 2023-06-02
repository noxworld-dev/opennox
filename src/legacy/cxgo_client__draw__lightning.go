package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_drawLightningStep_4BB070(a1 int32, a2 int32) int32 {
	var (
		v2  int32
		v3  bool
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  uint8
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 int32
		v23 int32
		v24 int32
		v25 int32
		v26 int32
		v27 int32
		v28 int32
	)
	v2 = int32(dword_5d4594_1316492 + 1)
	v3 = dword_5d4594_1316492+1 == dword_5d4594_1316448
	v23 = 0
	dword_5d4594_1316492++
	if !v3 {
		v14 = 1
		v15 = 1
		if v2 > 1 {
			v16 = v2 - 1
			for {
				v14 *= int32(*memmap.PtrUint32(0x587000, 178212) + 9)
				v15 *= 10
				v16--
				if v16 == 0 {
					break
				}
			}
		}
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v24))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v15*nox_common_randomIntMinMax_415FF0(int32(-dword_5d4594_1316476), *(*int32)(unsafe.Pointer(&dword_5d4594_1316476)), internCStr("C:\\NoxPost\\src\\Client\\Draw\\lightning.c"), 193)/v14 + ((int32(int16(a1)) + int32(int16(a2))) >> 1)))
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v24))), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(v15*nox_common_randomIntMinMax_415FF0(int32(-dword_5d4594_1316476), *(*int32)(unsafe.Pointer(&dword_5d4594_1316476)), internCStr("C:\\NoxPost\\src\\Client\\Draw\\lightning.c"), 196)/v14 + ((int32(*(*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(&a1))), unsafe.Sizeof(int16(0))*1))) + int32(*(*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(&a2))), unsafe.Sizeof(int16(0))*1)))) >> 1)))
		nox_xxx_drawLightningStep_4BB070(a1, v24)
		nox_xxx_drawLightningStep_4BB070(v24, a2)
		return int32(func() uint32 {
			p := &dword_5d4594_1316492
			*p--
			return *p
		}())
	}
	if *memmap.PtrUint32(0x5D4594, 1316508) != 0 {
		v23 = int32(*memmap.PtrUint8(0x5D4594, 1316420)) + 48
		nox_draw_set54RGB32_434040(*memmap.PtrInt32(0x5D4594, 1316440))
		sub_434080(12)
		v4 = int32(*(*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(&a1))), unsafe.Sizeof(int16(0))*1)))
		v5 = int32(int16(a1))
		nox_client_drawAddPoint_49F500(int32(int16(a1)), int32(*(*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(&a1))), unsafe.Sizeof(int16(0))*1))))
		v6 = int32(*(*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(&a2))), unsafe.Sizeof(int16(0))*1)))
		v7 = int32(int16(a2))
		nox_client_drawAddPoint_49F500(int32(int16(a2)), int32(*(*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(&a2))), unsafe.Sizeof(int16(0))*1))))
		sub_49E4F0(v23)
		v23 = 1
	} else {
		nox_draw_set54RGB32_434040(*(*int32)(unsafe.Pointer(&dword_5d4594_1316472)))
		sub_434080(3)
		v4 = int32(*(*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(&a1))), unsafe.Sizeof(int16(0))*1)))
		v5 = int32(int16(a1))
		nox_client_drawAddPoint_49F500(int32(int16(a1)), int32(*(*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(&a1))), unsafe.Sizeof(int16(0))*1))))
		v6 = int32(*(*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(&a2))), unsafe.Sizeof(int16(0))*1)))
		v7 = int32(int16(a2))
		nox_client_drawAddPoint_49F500(int32(int16(a2)), int32(*(*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(&a2))), unsafe.Sizeof(int16(0))*1))))
		sub_49E4F0(32)
	}
	nox_client_drawSetColor_434460(*(*int32)(unsafe.Pointer(&dword_5d4594_1316472)))
	nox_client_drawAddPoint_49F500(v5, v4)
	nox_client_drawAddPoint_49F500(v7, v6)
	nox_client_drawLineFromPoints_49E4B0()
	if v23 == 0 {
		return int32(func() uint32 {
			p := &dword_5d4594_1316492
			*p--
			return *p
		}())
	}
	v8 = *memmap.PtrUint8(0x5D4594, 1316420)
	v25 = 1
	if (int32(*memmap.PtrUint8(0x5D4594, 1316420)) & 0xFE) > 2 {
		v19 = v7 + 1
		v21 = v5 + 1
		v17 = v4 + 1
		v27 = v6 + 1
		for {
			nox_client_drawResetPoints_49F5A0()
			v9 = v5 - v7
			if v5-v7 < 0 {
				v9 = v7 - v5
			}
			v10 = v4 - v6
			if v4-v6 < 0 {
				v10 = v6 - v4
			}
			if v9 <= v10 {
				nox_client_drawAddPoint_49F500(v19, v6)
				nox_client_drawAddPoint_49F500(v21, v4)
			} else {
				nox_client_drawAddPoint_49F500(v7, v27)
				nox_client_drawAddPoint_49F500(v5, v17)
			}
			nox_client_drawLineFromPoints_49E4B0()
			v27++
			v17++
			v21++
			v8 = *memmap.PtrUint8(0x5D4594, 1316420)
			v19++
			v25++
			if v25 >= (int32(*memmap.PtrUint8(0x5D4594, 1316420)) >> 1) {
				break
			}
		}
	}
	v26 = 1
	if (int32(v8) & 0xFE) <= 2 {
		return int32(func() uint32 {
			p := &dword_5d4594_1316492
			*p--
			return *p
		}())
	}
	v20 = v7 - 1
	v18 = v5 - 1
	v22 = v4 - 1
	v28 = v6 - 1
	for {
		nox_client_drawResetPoints_49F5A0()
		v11 = v5 - v7
		if v5-v7 < 0 {
			v11 = v7 - v5
		}
		v12 = v4 - v6
		if v4-v6 < 0 {
			v12 = v6 - v4
		}
		if v11 <= v12 {
			nox_client_drawAddPoint_49F500(v20, v6)
			nox_client_drawAddPoint_49F500(v18, v4)
		} else {
			nox_client_drawAddPoint_49F500(v7, v28)
			nox_client_drawAddPoint_49F500(v5, v22)
		}
		nox_client_drawLineFromPoints_49E4B0()
		v28--
		v22--
		v18--
		v26++
		v20--
		if v26 >= (int32(*memmap.PtrUint8(0x5D4594, 1316420)) >> 1) {
			break
		}
	}
	return int32(func() uint32 {
		p := &dword_5d4594_1316492
		*p--
		return *p
	}())
}
func nox_xxx_lightningProc2_4BAE60(a1 *int2, a2 *int2, a3 int32, a4 *int16, a5 int32, a6 int32, a7 int32) int32 {
	var (
		v7     *int2
		v8     *int2
		v9     int32
		v10    int32
		v11    int32
		v12    int64
		v13    int32
		v14    int32
		v15    int32
		v16    int32
		v17    int32
		v18    int32
		v19    int32
		result int32
		v21    *int2
		v22    *int2
	)
	v7 = a2
	v8 = a1
	if a1.field_0-a2.field_0 >= 0 {
		v9 = a1.field_0 - a2.field_0
	} else {
		v9 = a2.field_0 - a1.field_0
	}
	v10 = a2.field_4
	if a1.field_4-v10 >= 0 {
		v11 = a1.field_4 - v10
	} else {
		v11 = v10 - a1.field_4
	}
	v12 = int64(math.Sqrt(float64(v9*v9 + v11*v11)))
	if int32(v12) >= 512 {
		dword_5d4594_1316476 = *memmap.PtrUint32(0x587000, 178204)
		dword_5d4594_1316448 = nox_xxx_lightningSteps_587000_178216
	} else {
		dword_5d4594_1316476 = *memmap.PtrUint32(0x587000, 178208) + uint32(int32(v12))*(*memmap.PtrUint32(0x587000, 178204)-*memmap.PtrUint32(0x587000, 178208))/512
		var v13p bool = false
		if int32(v12) < 64 {
			v13 = int32(nox_xxx_lightningSteps_587000_178216 - 3)
		} else if int32(v12) < 128 {
			v13 = int32(nox_xxx_lightningSteps_587000_178216 - 2)
		} else if int32(v12) < 256 {
			v13 = int32(nox_xxx_lightningSteps_587000_178216 - 1)
		} else {
			v13 = int32(nox_xxx_lightningSteps_587000_178216)
			v13p = true
		}
		if v13 >= 1 || v13p {
			dword_5d4594_1316448 = uint32(v13)
		} else {
			dword_5d4594_1316448 = 1
		}
	}
	*memmap.PtrUint32(0x5D4594, 1316532) = uint32(a3)
	if a3 == 1 || a3 == 3 {
		*memmap.PtrUint16(0x5D4594, 1316432) = uint16(*a4)
		*memmap.PtrUint16(0x5D4594, 1316434) = uint16(*(*int16)(unsafe.Add(unsafe.Pointer(a4), unsafe.Sizeof(int16(0))*2)))
		v14 = a1.field_0
		v15 = a2.field_0
		v16 = a1.field_0 - a2.field_0
		if v16 < 0 {
			v16 = v15 - v14
		}
		v17 = a1.field_4
		v18 = a2.field_4
		v19 = a1.field_4 - v18
		if v19 < 0 {
			v19 = v18 - v17
		}
		if v16 <= v19 {
			*memmap.PtrUint32(0x5D4594, 1316500) = uint32(bool2int32(v17 >= v18) + 2)
		} else {
			*memmap.PtrUint32(0x5D4594, 1316500) = uint32(bool2int32(v14 >= v15))
		}
		v7 = a2
	}
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v22))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(a1.field_0))
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v21))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v7.field_0))
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v22))), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(v8.field_4))
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v21))), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(v7.field_4))
	if a6 != 0 {
		dword_5d4594_1316492 = 1
		dword_5d4594_1316472 = dword_5d4594_1316456
		*memmap.PtrUint32(0x5D4594, 1316508) = 0
		nox_xxx_drawLightningStep_4BB070(int32(uintptr(unsafe.Pointer(v22))), int32(uintptr(unsafe.Pointer(v21))))
		dword_5d4594_1316492 = 1
		dword_5d4594_1316472 = dword_5d4594_1316452
		nox_xxx_drawLightningStep_4BB070(int32(uintptr(unsafe.Pointer(v22))), int32(uintptr(unsafe.Pointer(v21))))
	}
	result = a7
	if a7 != 0 {
		dword_5d4594_1316492 = 1
		dword_5d4594_1316472 = dword_5d4594_1316436
		*memmap.PtrUint32(0x5D4594, 1316440) = dword_5d4594_1316484
		*memmap.PtrUint32(0x5D4594, 1316508) = 1
		result = nox_xxx_drawLightningStep_4BB070(int32(uintptr(unsafe.Pointer(v22))), int32(uintptr(unsafe.Pointer(v21))))
	}
	return result
}
func nox_thing_lightning_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := (*int32)(vp.C())
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  uint16
		v7  *uint32
		v8  *uint32
		v9  *uint32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		a2a int2
		a1a int2
		a3  int2
		v18 int2
		v19 int32
		a2  int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 432)))) == 0 {
		v2 = *a1
		v3 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
		v4 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
		v5 = *a1
		v19 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		v18.field_0 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 437))))
		a1a.field_0 = v18.field_0 + v5 - v3
		v6 = *(*uint16)(unsafe.Pointer(uintptr(a2 + 441)))
		v18.field_4 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 439))))
		a1a.field_4 = v19 - v4 + v18.field_4 - 20
		a3.field_0 = int32(v6)
		a2a.field_0 = v2 + int32(v6) - v3
		a3.field_4 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 443))))
		a2a.field_4 = a3.field_4 - v4 + v19 - 20
	} else {
		if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Pointer(uintptr(a2 + 437)))) != 0 {
			v7 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 437))))).C())
		} else {
			v7 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 437))))).C())
		}
		v8 = v7
		if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Pointer(uintptr(a2 + 441)))) != 0 {
			v9 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 441))))).C())
		} else {
			v9 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 441))))).C())
		}
		if v8 == nil || v9 == nil {
			return 1
		}
		v10 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
		v11 = *a1 - v10
		a1a.field_0 = int32(uint32(*a1) + *(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*3)) - uint32(v10))
		v12 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
		v13 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		a1a.field_4 = int32(uint32(v13) + *(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*4)) - uint32(v12) - 20)
		v18 = *(*int2)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*3))))
		a2a.field_0 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*3)) + uint32(v11))
		a2a.field_4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*4)) - uint32(v12) + uint32(v13) - 20)
		a3 = *(*int2)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*3))))
	}
	dword_5d4594_1316452 = *memmap.PtrUint32(0x5D4594, 1316428)
	dword_5d4594_1316436 = *memmap.PtrUint32(0x5D4594, 1316464)
	dword_5d4594_1316456 = *memmap.PtrUint32(0x5D4594, 1316424)
	dword_5d4594_1316484 = *memmap.PtrUint32(0x5D4594, 1316488)
	*memmap.PtrUint8(0x5D4594, 1316420) = 1
	nox_xxx_lightningProc2_4BAE60(&a1a, &a2a, 2, nil, 1, 1, 1)
	if nox_xxx_checkGameFlagPause_413A50() == 0 {
		nox_xxx_makeLightningParticles_4999D0(*memmap.PtrInt32(0x5D4594, 1316520), &v18, &a3)
	}
	return 1
}
func nox_thing_chain_lightning_bolt_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := (*int32)(vp.C())
	var (
		v2  uint16
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  uint16
		v9  *uint32
		v10 *uint32
		v11 *uint32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		a2a int2
		a1a int2
		v19 int2
		a3  int2
		a2  int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 432)))) == 0 {
		v2 = *(*uint16)(unsafe.Pointer(uintptr(a2 + 437)))
		v3 = *a1
		v4 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
		v5 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
		v6 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		v7 = int32(v2) + *a1 - v4
		v19.field_0 = int32(v2)
		a1a.field_0 = v7
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v7))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 439)))
		a2a.field_0 = v3 + int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 441)))) - v4
		v19.field_4 = int32(uint16(int16(v7)))
		v8 = *(*uint16)(unsafe.Pointer(uintptr(a2 + 443)))
		a1a.field_4 = v6 - v5 + int32(uint16(int16(v7))) - 20
		a3.field_0 = int32(v8)
		a2a.field_4 = int32(v8) - v5 + v6 - 20
	} else {
		if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Pointer(uintptr(a2 + 437)))) != 0 {
			v9 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 437))))).C())
		} else {
			v9 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 437))))).C())
		}
		v10 = v9
		if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Pointer(uintptr(a2 + 441)))) != 0 {
			v11 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 441))))).C())
		} else {
			v11 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 441))))).C())
		}
		if v10 == nil || v11 == nil {
			return 1
		}
		v12 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
		v13 = *a1 - v12
		a1a.field_0 = int32(uint32(*a1) + *(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*3)) - uint32(v12))
		v14 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
		v15 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		a1a.field_4 = int32(uint32(v15) + *(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*4)) - uint32(v14) - 20)
		v19 = *(*int2)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*3))))
		a2a.field_0 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*3)) + uint32(v13))
		a2a.field_4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*4)) - uint32(v14) + uint32(v15) - 20)
		a3 = *(*int2)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*3))))
	}
	dword_5d4594_1316452 = *memmap.PtrUint32(0x5D4594, 1316428)
	dword_5d4594_1316436 = *memmap.PtrUint32(0x5D4594, 1316464)
	dword_5d4594_1316456 = *memmap.PtrUint32(0x5D4594, 1316424)
	dword_5d4594_1316484 = *memmap.PtrUint32(0x5D4594, 1316488)
	*memmap.PtrUint8(0x5D4594, 1316420) = 1
	nox_xxx_lightningProc2_4BAE60(&a1a, &a2a, 2, nil, 1, 1, 1)
	if nox_xxx_checkGameFlagPause_413A50() == 0 {
		nox_xxx_makeLightningParticles_4999D0(*memmap.PtrInt32(0x5D4594, 1316520), &v19, &a3)
	}
	return 1
}
func nox_thing_energy_bolt_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := (*int32)(vp.C())
	var (
		v2  int32
		v3  bool
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  uint16
		v9  *uint32
		v10 *uint32
		v11 *uint32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		a2a int2
		a1a int2
		a3  int2
		v20 int2
		v21 int32
		v22 int8
		a2  int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	v2 = a2
	v3 = int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 432)))) == 0
	v22 = int8(*(*uint8)(unsafe.Pointer(uintptr(a2 + 433))))
	if v3 {
		v4 = *a1
		v5 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
		v6 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
		v7 = *a1
		v21 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		v20.field_0 = int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 437))))
		a1a.field_0 = v20.field_0 + v7 - v5
		v8 = *(*uint16)(unsafe.Pointer(uintptr(v2 + 441)))
		v20.field_4 = int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 439))))
		a1a.field_4 = v21 - v6 + v20.field_4 - 20
		a3.field_0 = int32(v8)
		a2a.field_0 = v4 + int32(v8) - v5
		a3.field_4 = int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 443))))
		a2a.field_4 = a3.field_4 - v6 + v21 - 20
	} else {
		if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Pointer(uintptr(v2 + 437)))) != 0 {
			v9 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 437))))).C())
		} else {
			v9 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 437))))).C())
		}
		v10 = v9
		if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Pointer(uintptr(v2 + 441)))) != 0 {
			v11 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 441))))).C())
		} else {
			v11 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 441))))).C())
		}
		if v10 == nil || v11 == nil {
			return 1
		}
		v12 = *a1
		v13 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
		v14 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
		v15 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		a1a.field_0 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*3)) + uint32(*a1) - uint32(v13))
		a1a.field_4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*4)) - uint32(v14) + uint32(v15) - 20)
		v20 = *(*int2)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*3))))
		a2a.field_0 = int32(uint32(v12) + *(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*3)) - uint32(v13))
		a2a.field_4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*4)) - uint32(v14) + uint32(v15) - 20)
		a3 = *(*int2)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*3))))
	}
	*memmap.PtrUint8(0x5D4594, 1316420) = uint8(int8((int32(v22) + math.MaxInt8) * 2))
	dword_5d4594_1316436 = *memmap.PtrUint32(0x5D4594, 1316496)
	dword_5d4594_1316484 = *memmap.PtrUint32(0x5D4594, 1316468)
	nox_xxx_lightningProc2_4BAE60(&a1a, &a2a, 2, nil, 0, 0, 1)
	if nox_xxx_checkGameFlagPause_413A50() == 0 {
		nox_xxx_makeLightningParticles_4999D0(*memmap.PtrInt32(0x5D4594, 1316524), &v20, &a3)
	}
	return 1
}
func nox_thing_green_bolt_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := (*int32)(vp.C())
	var (
		v2  int32
		v3  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  uint16
		v10 *uint32
		v11 *uint32
		v12 *uint32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		a2a int2
		a1a int2
		a3  int2
		v20 int2
		v21 int32
		a2  int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 432)))) != 0 {
		if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Pointer(uintptr(a2 + 437)))) != 0 {
			v10 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 437))))).C())
		} else {
			v10 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 437))))).C())
		}
		v11 = v10
		if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Pointer(uintptr(a2 + 441)))) != 0 {
			v12 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 441))))).C())
		} else {
			v12 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 441))))).C())
		}
		if v11 == nil || v12 == nil {
			return 1
		}
		v13 = *a1
		v14 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
		a1a.field_0 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*3)) + uint32(*a1) - uint32(v14))
		v15 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
		v16 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		a1a.field_4 = int32(uint32(v16) + *(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*4)) - uint32(v15) - 20)
		v20 = *(*int2)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*3))))
		a2a.field_0 = int32(uint32(v13) + *(*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*3)) - uint32(v14))
		a2a.field_4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*4)) - uint32(v15) + uint32(v16) - 20)
		a3 = *(*int2)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*3))))
	} else {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 433))))
		if v2 != 0 {
			v3 = v2 - 1
			*(*uint32)(unsafe.Pointer(uintptr(a2 + 433))) = uint32(v3)
			if v3 == 0 {
				nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
				return 0
			}
		}
		v5 = *a1
		v6 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
		v7 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
		v8 = *a1
		v21 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		v20.field_0 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 437))))
		a1a.field_0 = v20.field_0 + v8 - v6
		v9 = *(*uint16)(unsafe.Pointer(uintptr(a2 + 441)))
		v20.field_4 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 439))))
		a1a.field_4 = v21 - v7 + v20.field_4 - 20
		a3.field_0 = int32(v9)
		a2a.field_0 = v5 + int32(v9) - v6
		a3.field_4 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 443))))
		a2a.field_4 = a3.field_4 - v7 + v21 - 20
	}
	dword_5d4594_1316452 = *memmap.PtrUint32(0x5D4594, 1316444)
	dword_5d4594_1316436 = *memmap.PtrUint32(0x5D4594, 1316504)
	dword_5d4594_1316456 = *memmap.PtrUint32(0x5D4594, 1316460)
	dword_5d4594_1316484 = *memmap.PtrUint32(0x5D4594, 1316480)
	*memmap.PtrUint8(0x5D4594, 1316420) = 1
	nox_xxx_lightningProc2_4BAE60(&a1a, &a2a, 2, nil, 1, 1, 1)
	if nox_xxx_checkGameFlagPause_413A50() == 0 {
		nox_xxx_makeLightningParticles_4999D0(*memmap.PtrInt32(0x5D4594, 1316528), &v20, &a3)
	}
	return 1
}
