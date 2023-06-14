package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_4BA230(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var (
		v5     int32
		v6     *uint8
		v7     int32
		i      int32
		result int32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    int32
		v15    int32
		j      int32
		v17    *uint8
		v18    int32
		v19    int32
		v20    int32
		v21    int32
		v22    int32
		v23    int32
		v24    float64
		v25    int32
		v26    int32
		v27    int32
		v28    float32
		v29    float32
		v30    float32
		v31    float32
		a4a    int2
		a3a    int2
		a2a    int2
		a1a    int2
		v36    int32
		v37    float32
	)
	v5 = 0
	if *memmap.PtrUint32(0x5D4594, 1316404) == 0 {
		*memmap.PtrUint32(0x5D4594, 1313828) = nox_color_rgb_4344A0(40, 180, math.MaxUint8)
		*memmap.PtrUint32(0x5D4594, 1313832) = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, math.MaxUint8)
		*memmap.PtrUint32(0x5D4594, 1313836) = nox_color_rgb_4344A0(40, 180, math.MaxUint8)
		*memmap.PtrUint32(0x5D4594, 1313844) = 8
		*memmap.PtrUint32(0x5D4594, 1313852) = 8
		*memmap.PtrUint32(0x5D4594, 1313856) = 0
		*memmap.PtrUint32(0x5D4594, 1313860) = 0
		*memmap.PtrUint8(0x5D4594, 1313840) = 16
		*memmap.PtrUint8(0x5D4594, 1313842) = 16
		*memmap.PtrUint32(0x5D4594, 1313848) = 12
		*memmap.PtrUint8(0x5D4594, 1313841) = 24
		v6 = (*uint8)(memmap.PtrOff(0x5D4594, 1313900))
		*memmap.PtrUint32(0x5D4594, 1313864) = 0
		for {
			v7 = 30
			for {
				*((*uint32)(unsafe.Add(unsafe.Pointer(v6), -int(4*1)))) = 0
				*(*uint32)(unsafe.Pointer(v6)) = 0
				*((*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))) = 0
				*((*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*2))) = 0
				*((*uint32)(unsafe.Add(unsafe.Pointer(v6), -int(4*2)))) = 0
				v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 28))
				v7--
				if v7 == 0 {
					break
				}
			}
			if int32(uintptr(unsafe.Pointer(v6))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1316420))) {
				break
			}
		}
		*memmap.PtrUint32(0x5D4594, 1316404) = 1
	}
	sub_4BA670(a1, a2, a3, a4, a5)
	for i = 0; i < 3; i++ {
		result = int32(dword_5d4594_1316408)
		v10 = 0
		if *(*int32)(unsafe.Pointer(&dword_5d4594_1316408))+1 <= 0 {
			continue
		}
		for {
			v11 = (i*30 + v10) * 28
			v12 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313900) + *memmap.PtrUint32(0x5D4594, uintptr(v11)+1313896))
			*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313896) = uint32(v12)
			if v12 < 256 {
				if v12 >= 0 {
					goto LABEL_14
				}
				v13 = v12 + math.MaxUint8
			} else {
				v13 = v12 - 256
			}
			*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313896) = uint32(v13)
		LABEL_14:
			if v10 == 0 {
				*memmap.PtrUint32(0x5D4594, uintptr(i*840)+1313896) = uint32(a1)
			}
			v14 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313904) + *memmap.PtrUint32(0x5D4594, uintptr(v11)+1313900))
			*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313900) = uint32(v14)
			if i == 1 {
				if v14 <= 10 {
					if v14 < -10 {
						*memmap.PtrUint32(0x5D4594, uintptr(v10*28)+1314740) = 4294967286
					}
				} else {
					*memmap.PtrUint32(0x5D4594, uintptr(v10*28)+1314740) = 10
				}
			} else if v14 <= 25 {
				if v14 < -25 {
					*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313900) = 4294967271
				}
			} else {
				*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313900) = 25
			}
			v15 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313908) - 1)
			*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313908) = uint32(v15)
			if v15 <= 0 {
				*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313908) = uint32(nox_common_randomIntMinMax_415FF0(10, 90, internCStr("C:\\NoxPost\\src\\client\\Draw\\Plasma.c"), 378))
				*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313904) = uint32(nox_common_randomIntMinMax_415FF0(4, 8, internCStr("C:\\NoxPost\\src\\client\\Draw\\Plasma.c"), 382))
				if nox_common_randomIntMinMax_415FF0(0, 1, internCStr("C:\\NoxPost\\src\\client\\Draw\\Plasma.c"), 385) != 0 {
					*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313904) = -*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313904)
				}
				if i == 1 {
					*memmap.PtrUint32(0x5D4594, uintptr(v10*28)+1314732) = uint32(nox_common_randomIntMinMax_415FF0(40, 50, internCStr("C:\\NoxPost\\src\\client\\Draw\\Plasma.c"), 392))
				} else {
					*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313892) = uint32(nox_common_randomIntMinMax_415FF0(80, 110, internCStr("C:\\NoxPost\\src\\client\\Draw\\Plasma.c"), 395))
					if v10 < 4 && nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\client\\Draw\\Plasma.c"), 402) > 90 {
						*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313892) = uint32(nox_common_randomIntMinMax_415FF0(150, 200, internCStr("C:\\NoxPost\\src\\client\\Draw\\Plasma.c"), 407))
						*memmap.PtrUint32(0x5D4594, uintptr(v11)+1313908) *= 2
					}
				}
			}
			result = int32(dword_5d4594_1316408)
			v10++
			if v10 >= *(*int32)(unsafe.Pointer(&dword_5d4594_1316408))+1 {
				break
			}
		}
		v5 = 0
	}
	for j = 0; j < 3; j++ {
		if result > 0 {
			v17 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(j*840)+1313896))
			for {
				v36 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v17), -int(4*1)))))
				v18 = int32(*(*uint32)(unsafe.Pointer(v17)))
				v19 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v17), -int(4*2)))))
				a1a.field_0 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v17), -int(4*3)))))
				a1a.field_4 = v19
				v37 = float32(float64(v36))
				v28 = v37 * *mem_getFloatPtr(0x587000, uint32(v18*8)+194136)
				v20 = int32(v28)
				v21 = int32(*(*uint32)(unsafe.Pointer(v17)))
				a3a.field_0 = v20
				v29 = v37 * *mem_getFloatPtr(0x587000, uint32(v21*8)+194140)
				v22 = int32(v29)
				v23 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v17), 4*4))))
				v24 = float64(v37 * *mem_getFloatPtr(0x587000, *((*uint32)(unsafe.Add(unsafe.Pointer(v17), 4*7)))*8+194136))
				a3a.field_4 = v22
				v25 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v17), 4*5))))
				a2a.field_0 = v23
				a2a.field_4 = v25
				v30 = float32(v24)
				v26 = int32(v30)
				v27 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v17), 4*7))))
				a4a.field_0 = v26
				v31 = v37 * *mem_getFloatPtr(0x587000, uint32(v27*8)+194140)
				a4a.field_4 = int32(v31)
				sub_4BE800(int32(*memmap.PtrUint32(0x5D4594, uintptr(j*4)+1313828)))
				sub_4BE810(1, int32(*memmap.PtrUint32(0x5D4594, uintptr(j*4)+1313828)), int32(*memmap.PtrUint32(0x5D4594, uintptr(j*4)+1313844)), int8(*memmap.PtrUint8(0x5D4594, uintptr(j)+1313840)))
				if j == 1 {
					sub_4BEAD0(&a1a, &a2a, &a3a, &a4a, 8, 1)
				} else {
					sub_4BEAD0(&a1a, &a2a, &a3a, &a4a, 8, 0)
				}
				result = int32(dword_5d4594_1316408)
				v5++
				v17 = (*uint8)(unsafe.Add(unsafe.Pointer(v17), 28))
				if v5 >= *(*int32)(unsafe.Pointer(&dword_5d4594_1316408)) {
					break
				}
			}
			v5 = 0
		}
	}
	return result
}
func sub_4BA8B0(a1p, a2p *int2, a3p unsafe.Pointer) {
	a1 := (*int32)(unsafe.Pointer(a1p))
	a2 := (*int32)(unsafe.Pointer(a2p))
	a3 := (*int32)(a3p)
	var (
		v3 int32
		v4 *byte
		v5 int32
		v6 int32
	)
	v3 = *a3
	v4 = (*byte)(unsafe.Pointer(nox_draw_getViewport_437250()))
	if *memmap.PtrUint32(0x5D4594, 1316416) == 0 {
		*memmap.PtrUint32(0x5D4594, 1316416) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CyanSpark")))
	}
	v6 = int32((dword_5d4594_1316412 + uint32(v3*30)) * 28)
	v5 = int32(dword_5d4594_1316412 + 1)
	*memmap.PtrUint32(0x5D4594, uintptr(v6)+1313884) = uint32(*a1)
	*memmap.PtrUint32(0x5D4594, uintptr(v6)+1313888) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	*memmap.PtrUint32(0x5D4594, uintptr(v6)+1313912) = uint32(*a2)
	*memmap.PtrUint32(0x5D4594, uintptr(v6)+1313916) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*1)))
	*((*uint8)(unsafe.Pointer(&v6))) = uint8(gameFrame())
	dword_5d4594_1316412 = uint32(v5)
	if int32(uint8(gameFrame()))&4 != 0 {
		v6 = nox_common_randomIntMinMax_415FF0(0, 10, internCStr("C:\\NoxPost\\src\\client\\Draw\\Plasma.c"), 135)
		if v6 > 5 {
			*((*uint8)(unsafe.Pointer(&v6))) = uint8(int8(nox_xxx_drawEnergyBolt_499710(int32(uint32(*a2)+*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*4)))-*(*uint32)(unsafe.Pointer(v4))), int32(uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*1)))+*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*5)))-*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))), 8, *memmap.PtrInt32(0x5D4594, 1316416))))
		}
	}
}
func nox_thing_plasma_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*int32)(vp.C())
	var (
		v3   int32
		v4   uint16
		v5   int32
		v6   int32
		v7   int32
		v8   int32
		v9   int32
		v10  *int32
		v11  *int32
		v12  int32
		v13  *uint32
		v14  int32
		v15  *uint32
		v16  int32
		v17  *uint32
		v18  int32
		v19  *uint32
		v20  int32
		v21  int32
		v22  int32
		v23  int32
		v25  types.Pointf
		v26  uint8
		a2   int32     = int32(uintptr(unsafe.Pointer(dr)))
		mpos nox_point = nox_client_getMousePos_4309F0()
	)
	v3 = a2
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 432))) != 0 {
		if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 437))) != 0 {
			v12 = nox_xxx_netClearHighBit_578B30(int16(uint16(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 437)))))
			v13 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(v12).C())
		} else {
			v14 = nox_xxx_netClearHighBit_578B30(int16(uint16(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 437)))))
			v13 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(v14).C())
		}
		v15 = v13
		if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441))) != 0 {
			v16 = nox_xxx_netClearHighBit_578B30(int16(uint16(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441)))))
			v17 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(v16).C())
		} else {
			v18 = nox_xxx_netClearHighBit_578B30(int16(uint16(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441)))))
			v17 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(v18).C())
		}
		v19 = v17
		if v15 != nil && v17 != nil {
			v20 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
			v21 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
			v22 = *a1
			v23 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
			v9 = int32(uint32(*a1) + *(*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*3)) - uint32(v21))
			a2 = int32(uint32(*a1) + *(*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*3)) - uint32(v21))
			a1 = (*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*4)) - uint32(v20) + uint32(v23) - 20)))
			v10 = (*int32)(unsafe.Pointer(uintptr(uint32(v22) + *(*uint32)(unsafe.Add(unsafe.Pointer(v19), 4*3)) - uint32(v21))))
			v11 = (*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v19), 4*4)) - uint32(v20) + uint32(v23) - 20)))
		} else {
			v9 = a2
			v10 = a1
			v11 = a1
		}
		v25.X = float32(float64(mpos.x) - float64(a2))
		v25.Y = float32(float64(mpos.y) - float64(int32(uintptr(unsafe.Pointer(a1)))))
		v26 = uint8(int8(nox_xxx_math_509ED0(&v25)))
	} else {
		v4 = *(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 439))
		v26 = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 433))
		v5 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
		v6 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
		v7 = *a1
		v8 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		v9 = *a1 + int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v3)), 437))) - v6
		a1 = (*int32)(unsafe.Pointer(uintptr(int32(v4) - v5 + v8 - 20)))
		v10 = (*int32)(unsafe.Pointer(uintptr(v7 + int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v3)), 441))) - v6)))
		v11 = (*int32)(unsafe.Pointer(uintptr(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v3)), 443))) - v5 + v8 - 20)))
	}
	sub_4BA230(int32(v26), v9, int32(uintptr(unsafe.Pointer(a1))), int32(uintptr(unsafe.Pointer(v10))), int32(uintptr(unsafe.Pointer(v11))))
	return 1
}
