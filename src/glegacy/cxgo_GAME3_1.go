package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/cmath"
	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var dword_5d4594_1522616 *nox_window = nil
var dword_5d4594_1522620 *nox_window = nil
var dword_5d4594_1522624 *nox_window = nil
var dword_5d4594_1522628 *nox_window = nil
var nox_wnd_xxx_1522608 *nox_gui_animation = nil
var nox_gui_itemAmount_item_1319256 unsafe.Pointer = nil
var nox_gui_itemAmount_dialog_1319228 unsafe.Pointer = nil

func sub_4B9470(a1 **byte) int32 {
	var (
		v1 *byte
		v2 int32
		v3 *uint8
	)
	if a1 == nil {
		return 0
	}
	v1 = *(**byte)(memmap.PtrOff(0x587000, 177488))
	v2 = 0
	if *memmap.PtrUint32(0x587000, 177488) == 0 {
		return 0
	}
	v3 = (*uint8)(memmap.PtrOff(0x587000, 177488))
	for libc.StrCmp(*a1, v1) != 0 {
		v1 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*2))))))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 8))
		v2++
		if v1 == nil {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v2*8)+177492))
}
func sub_4B94E0(dr *nox_drawable) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(dr)))
		result int32
	)
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 112)))&0x10000000 != 0 {
		result = sub_4B9470(*(***byte)(unsafe.Pointer(uintptr(a1 + 436))))
	} else {
		result = 0
	}
	return result
}
func sub_4B95D0(dr *nox_drawable) *uint32 {
	var (
		result *uint32
		v2     int32
		v3     int32
		v4     *uint32
		v5     int32
		v6     *uint8
		v7     *int32
		v8     **uint32
		v9     int32
		a1     int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	result = (*uint32)(nox_xxx_getProjectileClassById_413250(int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 108))))))
	v4 = result
	if result != nil {
		v5 = 1
		v6 = (*uint8)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4))))
		for {
			*((*uint8)(unsafe.Pointer(&v3))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v6), 1))
			*((*uint8)(unsafe.Pointer(&v2))) = *v6
			*((*uint8)(unsafe.Pointer(&result))) = *((*uint8)(unsafe.Add(unsafe.Pointer(v6), -1)))
			nox_draw_setMaterial_4340A0(func() int32 {
				p := &v5
				x := *p
				*p++
				return x
			}(), int32(uintptr(unsafe.Pointer(result))), v2, v3)
			v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 3))
			if v5 >= 7 {
				break
			}
		}
		v7 = (*int32)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*9))))
		v8 = (**uint32)(unsafe.Pointer(uintptr(a1 + 432)))
		v9 = 4
		for {
			result = *v8
			if *v8 != nil {
				*((*uint8)(unsafe.Pointer(&v3))) = *((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(result))), 26)))
				*((*uint8)(unsafe.Pointer(&v2))) = *((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(result))), 25)))
				*((*uint8)(unsafe.Pointer(&result))) = *((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(result))), 24)))
				nox_draw_setMaterial_4340A0(*v7, int32(uintptr(unsafe.Pointer(result))), v2, v3)
			}
			v8 = (**uint32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof((*uint32)(nil))*1))
			v7 = (*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1))
			v9--
			if v9 == 0 {
				break
			}
		}
	}
	return result
}
func sub_4B9650(a1 int32) *uint32 {
	var (
		result *uint32
		v2     int32
		v3     int32
		v4     int32
		v5     *uint8
	)
	result = (*uint32)(nox_xxx_getProjectileClassById_413250(a1))
	if result != nil {
		v4 = 1
		v5 = (*uint8)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4))))
		for {
			*((*uint8)(unsafe.Pointer(&v3))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v5), 1))
			*((*uint8)(unsafe.Pointer(&v2))) = *v5
			*((*uint8)(unsafe.Pointer(&result))) = *((*uint8)(unsafe.Add(unsafe.Pointer(v5), -1)))
			nox_draw_setMaterial_4340A0(func() int32 {
				p := &v4
				x := *p
				*p++
				return x
			}(), int32(uintptr(unsafe.Pointer(result))), v2, v3)
			v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 3))
			if v4 >= 7 {
				break
			}
		}
	}
	return result
}
func sub_4B96F0(dr *nox_drawable) *uint32 {
	var (
		result *uint32
		v2     int32
		v3     int32
		v4     *uint32
		v5     int32
		v6     *uint8
		v7     *int32
		v8     **uint32
		v9     int32
		a1     int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	result = (*uint32)(nox_xxx_equipClothFindDefByTT_413270(int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 108))))))
	v4 = result
	if result != nil {
		v5 = 1
		v6 = (*uint8)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4))))
		for {
			*((*uint8)(unsafe.Pointer(&v3))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v6), 1))
			*((*uint8)(unsafe.Pointer(&v2))) = *v6
			*((*uint8)(unsafe.Pointer(&result))) = *((*uint8)(unsafe.Add(unsafe.Pointer(v6), -1)))
			nox_draw_setMaterial_4340A0(func() int32 {
				p := &v5
				x := *p
				*p++
				return x
			}(), int32(uintptr(unsafe.Pointer(result))), v2, v3)
			v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 3))
			if v5 >= 7 {
				break
			}
		}
		v7 = (*int32)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*9))))
		v8 = (**uint32)(unsafe.Pointer(uintptr(a1 + 432)))
		v9 = 4
		for {
			result = *v8
			if *v8 != nil {
				*((*uint8)(unsafe.Pointer(&v3))) = *((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(result))), 26)))
				*((*uint8)(unsafe.Pointer(&v2))) = *((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(result))), 25)))
				*((*uint8)(unsafe.Pointer(&result))) = *((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(result))), 24)))
				nox_draw_setMaterial_4340A0(*v7, int32(uintptr(unsafe.Pointer(result))), v2, v3)
			}
			v8 = (**uint32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof((*uint32)(nil))*1))
			v7 = (*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1))
			v9--
			if v9 == 0 {
				break
			}
		}
	}
	return result
}
func sub_4BA670(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) {
	var (
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  float64
		v10 float64
		v11 float64
		v12 float64
		v13 float64
		v14 float64
		v15 float64
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 *uint8
		v21 float32
		a4a int2
		a3a int2
		a2a int2
		a1a int2
		v26 float32
	)
	v5 = a5
	v6 = a4 - a2
	v7 = a5 - a3
	v8 = int32(sub_48C6B0(a4-a2, a5-a3))
	dword_5d4594_1316408 = uint32(v8/40 + 1)
	if v8/40+2 >= 30 {
		dword_5d4594_1316408 = 28
	}
	a1a.field_0 = a2
	v9 = float64(*mem_getFloatPtr(0x587000, uint32(a1*8)+194136))
	v10 = float64(*mem_getFloatPtr(0x587000, uint32(a1*8)+194140))
	v11 = float64(a4 - a2)
	v12 = float64(v7)
	a1a.field_4 = a3
	a2a.field_0 = a4
	a2a.field_4 = v5
	*(*float32)(unsafe.Pointer(&dword_5d4594_1313880)) = float32(v12)
	v26 = float32(math.Sqrt(v12*float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1313880)))+v11*v11) + 0.0099999998)
	*mem_getFloatPtr(0x5D4594, 1313876) = float32(v11 / float64(v26))
	v13 = float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1313880)) / v26)
	*(*float32)(unsafe.Pointer(&dword_5d4594_1313880)) = float32(v13)
	v14 = v13*v10 + float64(*mem_getFloatPtr(0x5D4594, 1313876))*v9
	if v14 < 0.0 {
		v14 = v14 * 0.2
	}
	v15 = (1.0 - v14) * float64(v8) * 2.3
	*mem_getFloatPtr(0x5D4594, 1313868) = float32(v9 * v15)
	*mem_getFloatPtr(0x5D4594, 1313872) = float32(v10 * v15)
	a3a.field_0 = nox_float2int(*mem_getFloatPtr(0x5D4594, 1313868))
	v16 = nox_float2int(*mem_getFloatPtr(0x5D4594, 1313872))
	a4a.field_0 = v6
	v17 = 0
	a3a.field_4 = v16
	a4a.field_4 = v7
	a5 = 0
	for {
		if v17 != 0 {
			*mem_getFloatPtr(0x5D4594, uint32(v17*4)+1313856) = float32(float64(*mem_getFloatPtr(0x5D4594, uint32(v17*4)+1313856)) + 0.25)
		} else {
			*mem_getFloatPtr(0x5D4594, 1313856) = float32(float64(*mem_getFloatPtr(0x5D4594, 1313856)) + 0.2)
		}
		v18 = int32(dword_5d4594_1316408)
		if float64(*mem_getFloatPtr(0x5D4594, uint32(v17*4)+1313856)) >= 1.0 {
			v19 = int32(dword_5d4594_1316408 + 1)
			if dword_5d4594_1316408+1 > 0 {
				v20 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr((v19+v17*30)*28)+1313872))
				for {
					*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), 4*6))) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), -int(4*1))))
					*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), 4*7))) = *(*uint32)(unsafe.Pointer(v20))
					*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), 4*8))) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), 4*1)))
					*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), 4*9))) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), 4*2)))
					*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), 4*5))) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), -int(4*2))))
					v20 = (*uint8)(unsafe.Add(unsafe.Pointer(v20), -28))
					v19--
					if v19 == 0 {
						break
					}
				}
			}
			*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1313856) = 0
			*memmap.PtrUint32(0x5D4594, uintptr(v17*840)+1313908) = 0
		}
		v21 = *mem_getFloatPtr(0x5D4594, uint32(v17*4)+1313856)
		dword_5d4594_1316412 = 0
		sub_4BEDE0(&a1a, &a2a, &a3a, &a4a, v18, v21, int32(funAddr(sub_4BA8B0)), int32(uintptr(unsafe.Pointer(&a5))))
		v17 = func() int32 {
			p := &a5
			*p++
			return *p
		}()
		if a5 >= 3 {
			break
		}
	}
}
func nox_xxx_prepareLightningEffects_4BAB30() int32 {
	var result int32
	*memmap.PtrUint32(0x5D4594, 1316464) = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316488) = nox_color_rgb_4344A0(128, 128, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316424) = nox_color_rgb_4344A0(128, 128, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316428) = nox_color_rgb_4344A0(64, 64, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316516) = nox_color_rgb_4344A0(200, 200, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316512) = nox_color_rgb_4344A0(128, 128, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316496) = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316468) = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, 0)
	*memmap.PtrUint32(0x5D4594, 1316460) = nox_color_rgb_4344A0(30, 160, 30)
	*memmap.PtrUint32(0x5D4594, 1316444) = nox_color_rgb_4344A0(60, 140, 60)
	*memmap.PtrUint32(0x5D4594, 1316504) = nox_color_rgb_4344A0(40, 225, 40)
	*memmap.PtrUint32(0x5D4594, 1316480) = nox_color_rgb_4344A0(150, 220, 150)
	*memmap.PtrUint32(0x5D4594, 1316520) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BlueSpark")))
	*memmap.PtrUint32(0x5D4594, 1316524) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("YellowSpark")))
	result = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GreenSpark"))
	*memmap.PtrUint32(0x5D4594, 1316528) = uint32(result)
	return result
}
func nox_xxx_spriteDrawMonsterHP_4BC080(a1 *uint32, a2 int32, a3 uint16, a4 uint16, a5 int8) {
	var (
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 float32
		v11 float32
		v12 float32
	)
	if a2 != 0 {
		v5 = int32(*a1 + *(*uint32)(unsafe.Pointer(uintptr(a2 + 12))) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		v10 = *(*float32)(unsafe.Pointer(uintptr(a2 + 48))) + *(*float32)(unsafe.Pointer(uintptr(a2 + 48)))
		v6 = nox_float2int(v10) + v5
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - uint32(*(*int16)(unsafe.Pointer(uintptr(a2 + 104)))) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
		v11 = *(*float32)(unsafe.Pointer(uintptr(a2 + 100))) - *(*float32)(unsafe.Pointer(uintptr(a2 + 96)))
		v8 = nox_float2int(v11)
		if v8 < 30 {
			v8 = 30
		}
		v12 = *(*float32)(unsafe.Pointer(uintptr(a2 + 96))) + *(*float32)(unsafe.Pointer(uintptr(a2 + 100)))
		v9 = v7 + nox_float2int(v12)/(-2) - v8/2
		if int32(a4) != 0 {
			nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
			nox_client_drawRectFilledOpaque_49CE30(v6, v9, 2, v8)
			if int32(a5) != 0 {
				nox_client_drawSetColor_434460(*memmap.PtrInt32(0x8531A0, 2572))
			} else {
				nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 940))
			}
			nox_client_drawRectFilledOpaque_49CE30(v6, v8+v9-v8*int32(a3)/int32(a4), 2, v8*int32(a3)/int32(a4))
		}
	}
}
func sub_4BC6B0(a1 *int32, dr *nox_drawable, a3 int32) int32 {
	var (
		a2 int32 = int32(uintptr(unsafe.Pointer(dr)))
		v3 int32
	)
	v3 = sub_4BC5D0(dr, a3)
	if v3 < 0 {
		return 0
	}
	nox_xxx_drawObject_4C4770_draw(a1, dr, int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a3 + int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 297))))*4 + 4))) + uint32(v3*4))))))
	return 1
}
func sub_4BC720(a1 int32) int32 {
	var result int32
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 304))))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 432))) = uint32(int32(*(*uint8)(unsafe.Pointer(uintptr(result + 27)))) * (int32(*(*uint8)(unsafe.Pointer(uintptr(result + 32)))) + 1))
	return result
}
func nox_xxx_updDrawMonsterGen_4BC920() int32 {
	return 1
}
func sub_4BD280(a1 int32, a2 int32) *uint32 {
	var (
		v2     int32
		result *uint32
		v4     *uint32
		v5     int32
	)
	v2 = a2 + 4
	result = (*uint32)(alloc.Calloc1(1, uintptr(a1*(a2+4)+4)))
	if result != nil {
		v4 = (*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1))
		*result = uint32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1)))))
		if a1 != 1 {
			v5 = a1 - 1
			for {
				v5--
				*v4 = uint32(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v4))), v2)))))
				v4 = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v4))), v2))))
				if v5 == 0 {
					break
				}
			}
		}
		*v4 = 0
	}
	return result
}
func sub_4BD2D0(lpMem unsafe.Pointer) {
	alloc.FreePtr(lpMem)
}
func sub_4BD2E0(a1 **uint32) *uint32 {
	var (
		result *uint32
		v2     *uint32
	)
	result = *a1
	if *a1 != nil {
		v2 = (*uint32)(unsafe.Pointer(uintptr(*result)))
		result = (*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1))
		*a1 = v2
	}
	return result
}
func sub_4BD300(a1 *uint32, a2 int32) int32 {
	var result int32
	result = a2 - 4
	*(*uint32)(unsafe.Pointer(uintptr(a2 - 4))) = *a1
	*a1 = uint32(a2 - 4)
	return result
}
func sub_4BD340(a1 int32, a2 int32, a3 int32, a4 int32) *uint32 {
	var v4 *uint32
	v4 = (*uint32)(alloc.Calloc1(1, 0x1C))
	libc.MemSet(unsafe.Pointer(v4), 0, 0x1C)
	*v4 = uint32(a1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*6)) = uint32(a4)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = uint32(uintptr(unsafe.Pointer(sub_4BD280(a2/(a4+24), a4+24))))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) = uint32(uintptr(unsafe.Pointer(sub_4BD280(a3, 84))))
	nox_common_list_clear_425760((*nox_list_item_t)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*3)))))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) != 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) != 0 {
		return v4
	}
	sub_4BD3C0(unsafe.Pointer(v4))
	return nil
}
func sub_4BD3C0(lpMem unsafe.Pointer) {
	var i int32
	for i = int32(uintptr(unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Pointer((*int32)(unsafe.Add(unsafe.Pointer((*int32)(lpMem)), 4*3)))))))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Pointer((*int32)(unsafe.Add(unsafe.Pointer((*int32)(lpMem)), 4*3)))))))) {
		sub_4BD690(i)
	}
	if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(lpMem)), 4*1))) != 0 {
		sub_4BD2D0(*((*unsafe.Pointer)(unsafe.Add(unsafe.Pointer((*unsafe.Pointer)(lpMem)), unsafe.Sizeof(unsafe.Pointer(nil))*1))))
	}
	if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(lpMem)), 4*2))) != 0 {
		sub_4BD2D0(*((*unsafe.Pointer)(unsafe.Add(unsafe.Pointer((*unsafe.Pointer)(lpMem)), unsafe.Sizeof(unsafe.Pointer(nil))*2))))
	}
	alloc.FreePtr(lpMem)
}
func sub_4BD420(a1 int32, a2 int32) *uint32 {
	var result *uint32
	result = *(**uint32)(unsafe.Pointer(uintptr(a1 + 12)))
	if result == (*uint32)(unsafe.Pointer(uintptr(a1+12))) {
		return nil
	}
	for *(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4)) != uint32(a2) || *(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*5)) == 0 {
		result = (*uint32)(unsafe.Pointer(uintptr(*result)))
		if result == (*uint32)(unsafe.Pointer(uintptr(a1+12))) {
			return nil
		}
	}
	return result
}
func sub_4BD470(a1 **uint32, a2 int32) *uint32 {
	var (
		v2  *uint32
		v3  *uint32
		v5  *uint32
		v6  *uint32
		v7  *uint32
		v8  *byte
		v9  int32
		v10 *uint32
	)
	v2 = sub_4BD420(int32(uintptr(unsafe.Pointer(a1))), a2)
	v3 = v2
	if v2 != nil {
		nox_common_list_remove_425920(unsafe.Pointer((**uint32)(unsafe.Pointer(v2))))
		sub_425900((*uint32)(unsafe.Pointer((**uint32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((*uint32)(nil))*3)))), v3)
		return v3
	}
	if sub_486B60(int32(uintptr(unsafe.Pointer(*a1))), a2) == 0 {
		return nil
	}
	v5 = sub_4BD2E0((**uint32)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((*uint32)(nil))*2)))))
	if v5 == nil {
		sub_4BD600(int32(uintptr(unsafe.Pointer(a1))))
		v5 = sub_4BD2E0((**uint32)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((*uint32)(nil))*2)))))
		if v5 == nil {
			sub_486E00(int32(uintptr(unsafe.Pointer(*a1))))
			return nil
		}
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*4)) = uint32(a2)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*13)) = uint32(uintptr(unsafe.Pointer(a1)))
	sub_425770(unsafe.Pointer(v5))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*3)) = 0
	sub_487C30((*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*6)))
	nullsub_10(uint32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*14))))))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*11)) = uint32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*14)))))
	v6 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(*a1), 4*71)))))
	v10 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(*a1), 4*71)))))
	if v6 == nil {
		sub_486AA0(*a1, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*4))), (*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*14)))
		sub_425900((*uint32)(unsafe.Pointer((**uint32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((*uint32)(nil))*3)))), v5)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*5)) = 1
		sub_486E00(int32(uintptr(unsafe.Pointer(*a1))))
		return v5
	}
	for {
		v7 = *(**uint32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((*uint32)(nil))*6))
		if int32(uintptr(unsafe.Pointer(v7))) > int32(uintptr(unsafe.Pointer(v6))) {
			v7 = v6
		}
		v8 = (*byte)(unsafe.Pointer(sub_4BD2E0((**uint32)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((*uint32)(nil))*1)))))))
		if v8 == nil {
			for sub_4BD600(int32(uintptr(unsafe.Pointer(a1)))) != 0 {
				v8 = (*byte)(unsafe.Pointer(sub_4BD2E0((**uint32)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((*uint32)(nil))*1)))))))
				if v8 != nil {
					goto LABEL_17
				}
			}
			sub_4BD690(int32(uintptr(unsafe.Pointer(v5))))
			return nil
		}
	LABEL_17:
		sub_487D30((*uint32)(unsafe.Pointer(v8)), int32(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v8), 24))))), int32(uintptr(unsafe.Pointer(v7))))
		sub_487C50(int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*6))))), (*uint32)(unsafe.Pointer(v8)))
		v9 = sub_486DB0(int32(uintptr(unsafe.Pointer(*a1))), (*byte)(unsafe.Add(unsafe.Pointer(v8), 24)), int32(uintptr(unsafe.Pointer(v7))))
		if (*uint32)(unsafe.Pointer(uintptr(v9))) != v7 {
			sub_4BD690(int32(uintptr(unsafe.Pointer(v5))))
			return nil
		}
		v10 = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v10))), -v9))))
		if v10 == nil {
			sub_486AA0(*a1, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*4))), (*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*14)))
			sub_425900((*uint32)(unsafe.Pointer((**uint32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((*uint32)(nil))*3)))), v5)
			*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*5)) = 1
			sub_486E00(int32(uintptr(unsafe.Pointer(*a1))))
			return v5
		}
		v6 = v10
	}
}
func sub_4BD600(a1 int32) int32 {
	var v1 int32
	v1 = sub_425960(a1 + 12)
	if v1 == 0 {
		return 0
	}
	for sub_4BD680(v1) != 0 {
		v1 = sub_425960(v1)
		if v1 == 0 {
			return 0
		}
	}
	sub_4BD690(v1)
	return 1
}
func sub_4BD650(a1 int32) int32 {
	var result int32
	result = a1
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 12)))++
	return result
}
func sub_4BD660(a1 int32) int32 {
	var result int32
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))) - 1)
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))) = uint32(result)
	if result < 0 {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))) = 0
	}
	return result
}
func sub_4BD680(a1 int32) int32 {
	return int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
}
func sub_4BD690(a1 int32) int32 {
	var i **uint32
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 4))) != uint32(a1) {
		nox_common_list_remove_425920(unsafe.Pointer(uintptr(a1)))
	}
	for i = (**uint32)(unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Pointer(uintptr(a1 + 32)))))); i != nil; i = (**uint32)(unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Pointer(uintptr(a1 + 32)))))) {
		nox_common_list_remove_425920(unsafe.Pointer(i))
		sub_487D60(int32(uintptr(unsafe.Pointer(i))))
		sub_4BD300(*(**uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 52))) + 4))), int32(uintptr(unsafe.Pointer(i))))
	}
	nullsub_9(uint32(a1 + 24))
	return sub_4BD300(*(**uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 52))) + 8))), a1)
}
func sub_4BD710(a1 int32) int32 {
	return a1 + 24
}
func sub_4BD720(a1 int32) *uint32 {
	var v1 *uint32
	v1 = (*uint32)(alloc.Calloc1(1, 0x138))
	libc.MemSet(unsafe.Pointer(v1), 0, 0x138)
	sub_425770(unsafe.Pointer(v1))
	sub_4BDC00(int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*30))))))
	sub_4864A0((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*44)))
	sub_4BD7C0(v1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*33)) = uint32(a1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*43)) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 256)))
	if (*(*func(*uint32) int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 256))) + 4))))(v1) == 0 {
		return v1
	}
	if v1 != nil {
		sub_4BD7A0(unsafe.Pointer(v1))
	}
	return nil
}
func sub_4BD7A0(lpMem unsafe.Pointer) {
	(*(*func(unsafe.Pointer))(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(lpMem)), 4*43))) + 8))))(lpMem)
	alloc.FreePtr(lpMem)
}
func sub_4BD7C0(a1 *uint32) *uint32 {
	var result *uint32
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*69)) = uint32(funAddr(sub_4BD8C0))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*70)) = uint32(funAddr(sub_4BD940))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*71)) = uint32(funAddr(sub_4BD9B0))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*34)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*35)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*36)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*38)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) = 1
	sub_4BDC00(int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*30))))))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*30)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*29)) = *memmap.PtrUint32(0x5D4594, 1193340)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*28)) = 0
	result = sub_4864A0((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*72)) = 0
	return result
}
func sub_4BD840(a3 int32) int32 {
	var (
		v1     int32
		v2     *uint32
		v3     *uint32
		result int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a3 + 132))))
	v2 = (*uint32)(unsafe.Pointer(uintptr(a3 + 176)))
	sub_4864A0((*uint32)(unsafe.Pointer(uintptr(a3 + 176))))
	sub_486570((*uint32)(unsafe.Pointer(uintptr(a3+176))), (*uint32)(unsafe.Pointer(uintptr(a3+16))))
	sub_486620((*uint32)(unsafe.Pointer(uintptr(a3 + 16))))
	if *(*uint32)(unsafe.Pointer(uintptr(a3 + 112))) != 0 {
		sub_486570(v2, *(**uint32)(unsafe.Pointer(uintptr(a3 + 112))))
		sub_486620(*(**uint32)(unsafe.Pointer(uintptr(a3 + 112))))
	}
	v3 = *(**uint32)(unsafe.Pointer(uintptr(a3 + 116)))
	if v3 != nil {
		sub_486570(v2, v3)
	}
	sub_486570(v2, (*uint32)(unsafe.Pointer(uintptr(v1+88))))
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 184))))
	if result != 0 {
		result = sub_486570(v2, *(**uint32)(unsafe.Pointer(uintptr(v1 + 184))))
	}
	return result
}
func sub_4BD8C0(a1 int32) int32 {
	var (
		v1     func(int32) int32
		result int32
		v3     int32
		v4     int32
	)
	v1 = *(*func(int32) int32)(unsafe.Pointer(uintptr(a1 + 136)))
	if v1 != nil {
		result = v1(a1)
		if result != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 300))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 304))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 296))) = 0
			return result
		}
	} else {
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 292))) != 0 {
			v3 = int32(uintptr(unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Pointer(*(**int32)(unsafe.Pointer(uintptr(a1 + 292)))))))))
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 292))) = uint32(v3)
			if v3 != 0 {
				*(*uint32)(unsafe.Pointer(uintptr(a1 + 296))) = *(*uint32)(unsafe.Pointer(uintptr(v3 + 12)))
				v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 16))))
				*(*uint32)(unsafe.Pointer(uintptr(a1 + 300))) = uint32(v4)
				*(*uint32)(unsafe.Pointer(uintptr(a1 + 304))) = uint32(v4)
				return 0
			}
		}
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 300))) = 0
	}
	return 0
}
func sub_4BD940(a1 int32) int32 {
	var v1 func(int32)
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 128))) != 0 {
		if *(*int32)(unsafe.Pointer(uintptr(a1 + 128))) != -1 {
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 128)))--
		}
		sub_4BDB90((*uint32)(unsafe.Pointer(uintptr(a1))), *(**uint32)(unsafe.Pointer(uintptr(a1 + 288))))
	} else {
		sub_4BDB90((*uint32)(unsafe.Pointer(uintptr(a1))), nil)
	}
	v1 = *(*func(int32))(unsafe.Pointer(uintptr(a1 + 140)))
	if v1 != nil {
		v1(a1)
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 288))) != 0 {
		(*(*func(int32))(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 172))) + 36))))(a1)
	}
	return 0
}
func sub_4BD9B0(a2 *uint32) int32 {
	var (
		v1     int32
		v2     func(*uint32) int32
		result int32
	)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*72)) = 0
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*31)))
	*((*uint8)(unsafe.Pointer(&v1))) = uint8(int8(v1 & 0xFA))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*31)) = uint32(v1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*32)) = 0
	sub_4864A0((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*4)))
	v2 = asFunc(*(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*36)), (*func(*uint32) int32)(nil)).(func(*uint32) int32)
	if v2 != nil {
		result = v2(a2)
	} else {
		result = 0
	}
	return result
}
func sub_4BDA60(lpMem unsafe.Pointer) {
	sub_4BDA80(int32(uintptr(lpMem)))
	sub_486E90(int32(uintptr(lpMem)))
	sub_4BD7A0(lpMem)
}
func sub_4BDA80(a1 int32) int32 {
	var (
		result  int32 = 0
		result2 func(int32) int32
	)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 124))))&5 != 0 {
		(*(*func(int32))(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 172))) + 16))))(a1)
	}
	result2 = *(*func(int32) int32)(unsafe.Pointer(uintptr(a1 + 148)))
	if result2 != nil {
		result = result2(a1)
	}
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 288))) = 0
	return result
}
func sub_4BDB20(a1 int32) int32 {
	var result int32
	result = a1
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 124))) |= 0x10
	return result
}
func sub_4BDB30(a1 int32) int32 {
	var result int32
	result = a1
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 124))) &= 0xFFFFFFEF
	return result
}
func sub_4BDB40(a2 int32) int32 {
	var result int32
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 124))))&5 != 0 {
		return -2146500608
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a2 + 288))) == 0 {
		return -2147024896
	}
	sub_486520((*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
	sub_4BD840(a2)
	result = (*(*func(int32) int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a2 + 172))) + 12))))(a2)
	if result == 0 {
		*(*uint32)(unsafe.Pointer(uintptr(a2 + 124))) |= 1
	}
	return result
}
func sub_4BDB90(a1 *uint32, a2 *uint32) {
	var (
		v2 int32
		v3 int32
		v4 *uint32
		v5 int32
	)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*72)) = uint32(uintptr(unsafe.Pointer(a2)))
	if a2 != nil {
		v2 = sub_487C80(int32(uintptr(unsafe.Pointer(a2))))
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*73)) = uint32(v2)
		if v2 != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*74)) = *(*uint32)(unsafe.Pointer(uintptr(v2 + 12)))
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))))
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*75)) = uint32(v3)
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*76)) = uint32(v3)
			*a2 = 0
		} else {
			v4 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*72)))))
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*74)) = *v4
			v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*75)) = uint32(v5)
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*76)) = uint32(v5)
		}
	}
}
func sub_4BDC00(a1 int32) int32 {
	var result int32
	result = a1
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 4))) = 0
	return result
}
func nox_xxx_loadAdvancedWnd_4BDC10(a1 *int32) int32 {
	dword_5d4594_1316708 = uint32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("advanced.wnd"), unsafe.Pointer(funAddr(nox_xxx_windowAdvancedServProc_4BDDB0))))))
	sub_46B120((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316708)))), nil)
	sub_46C690((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1316708))))))
	nox_xxx_wndShowModalMB_46A8C0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1316708))))))
	nox_xxx_wndSetWindowProc_46B300(*(*int32)(unsafe.Pointer(&dword_5d4594_1316708)), func(arg1 int32, arg2 int32, arg3 int32, arg4 int32) int32 {
		return sub_4BDDA0()
	})
	nox_xxx_windowFocus_46B500((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1316708))))))
	return sub_4BDC70(a1)
}
func sub_4BDC70(a1 *int32) int32 {
	var (
		v1 *uint32
		v2 *uint32
		v3 *uint32
	)
	if nox_common_gameFlags_check_40A5C0(1) {
		v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316708)))), 10167)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*9)) |= 4
		dword_5d4594_1316704 = 0
	} else {
		v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316708)))), 10164)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*9)) |= 4
		v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316708)))), 10167)))
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), 0)
		dword_5d4594_1316704 = 1
	}
	sub_453F70(unsafe.Pointer((*int32)(unsafe.Add(unsafe.Pointer(a1), 4*6))))
	sub_4535E0((*int32)(unsafe.Add(unsafe.Pointer(a1), 4*11)))
	sub_4535F0(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*12)))
	return sub_4BDD10()
}
func sub_4BDD10() int32 {
	var (
		v1 int32
		v2 *byte
	)
	switch dword_5d4594_1316704 {
	case 0:
		v2 = sub_4165B0()
		v1 = sub_4CEBA0(*(*int32)(unsafe.Pointer(&dword_5d4594_1316708)), v2)
		dword_5d4594_1316712 = uint32(v1)
	case 1:
		dword_5d4594_1316712 = uint32(nox_xxx_guiSpelllistLoad_453850(*(*int32)(unsafe.Pointer(&dword_5d4594_1316708))))
		return nox_xxx_windowFocus_46B500((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1316712))))))
	case 2:
		v1 = nox_xxx_guiObjlistLoad_4530C0(*(*int32)(unsafe.Pointer(&dword_5d4594_1316708)), 0x1000000)
		dword_5d4594_1316712 = uint32(v1)
	case 3:
		v1 = nox_xxx_guiObjlistLoad_4530C0(*(*int32)(unsafe.Pointer(&dword_5d4594_1316708)), 0x2000000)
		dword_5d4594_1316712 = uint32(v1)
	default:
		return nox_xxx_windowFocus_46B500((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1316712))))))
	}
	return nox_xxx_windowFocus_46B500((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1316712))))))
}
func sub_4BDDA0() int32 {
	return 1
}
func nox_xxx_windowAdvancedServProc_4BDDB0(a1 int32, a2 int32, a3 *int32, a4 int32) int32 {
	var (
		v3     int32
		result int32
		v5     *byte
	)
	if a2 == 23 {
		return 1
	}
	if a2 != 16391 {
		return 1
	}
	v3 = nox_xxx_wndGetID_46B0A0((*nox_window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	switch v3 {
	case 10148:
		v5 = sub_4165B0()
		alloc.Memcpy(unsafe.Add(unsafe.Pointer(v5), 24), unsafe.Pointer(sub_453F90()), 0x14)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*11))) = *(*uint32)(unsafe.Pointer(sub_453600()))
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*12))) = uint32(sub_453610())
		sub_4BDF30()
		return 1
	case 10164:
		if dword_5d4594_1316712 != 0 {
			nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316712)))))
			dword_5d4594_1316712 = 0
		}
		dword_5d4594_1316704 = 1
		sub_4BDD10()
		result = 1
	case 10165:
		if dword_5d4594_1316712 != 0 {
			nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316712)))))
			dword_5d4594_1316712 = 0
		}
		dword_5d4594_1316704 = 2
		sub_4BDD10()
		result = 1
	case 10166:
		if dword_5d4594_1316712 != 0 {
			nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316712)))))
			dword_5d4594_1316712 = 0
		}
		dword_5d4594_1316704 = 3
		sub_4BDD10()
		result = 1
	case 10167:
		if dword_5d4594_1316712 != 0 {
			nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316712)))))
			dword_5d4594_1316712 = 0
		}
		dword_5d4594_1316704 = 0
		sub_4BDD10()
		result = 1
	default:
		return 1
	}
	return result
}
func sub_4BDF30() int32 {
	var result int32
	result = int32(dword_5d4594_1316708)
	if dword_5d4594_1316708 != 0 {
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1316708))))))
		nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316708)))))
		dword_5d4594_1316708 = 0
		dword_5d4594_1316712 = 0
		result = nox_xxx_windowFocus_46B500(nil)
	}
	return result
}
func sub_4BDF70(a1 *int32) int32 {
	var result int32
	result = *(*int32)(unsafe.Pointer(&dword_5d4594_1316708))
	if dword_5d4594_1316708 != 0 {
		result = sub_4BDF90(a1)
	}
	return result
}
func sub_4BDF90(a1 *int32) int32 {
	var (
		result  int32 = 0
		result2 func() int32
	)
	sub_453F70(unsafe.Pointer((*int32)(unsafe.Add(unsafe.Pointer(a1), 4*6))))
	sub_4535E0((*int32)(unsafe.Add(unsafe.Pointer(a1), 4*11)))
	sub_4535F0(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*12)))
	result2 = *(*func() int32)(memmap.PtrOff(0x587000, dword_5d4594_1316704*4+180016))
	if result2 != nil {
		result = result2()
	}
	return result
}
func sub_4BDFD0() int32 {
	var (
		v0  *byte
		v1  int32
		v2  int32
		v3  *uint32
		v4  *uint32
		v5  int32
		v6  *uint32
		v7  *uint32
		v9  int32
		v10 int32
	)
	v0 = (*byte)(sub_416640())
	v1 = nox_strman_get_lang_code()
	v2 = int32(uintptr(unsafe.Pointer(v0)))
	if nox_xxx_guiFontHeightMB_43F320(nil) > 10 {
		v1 = 2
	}
	if false {
		v3 = (*uint32)(unsafe.Pointer(nox_new_window_from_file(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1*4)+180088)), unsafe.Pointer(funAddr(sub_4BE330)))))
	} else {
		v3 = (*uint32)(unsafe.Pointer(nox_new_window_from_file(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1*4)+180048)), unsafe.Pointer(funAddr(sub_4BE330)))))
	}
	dword_5d4594_1316972 = uint32(uintptr(unsafe.Pointer(v3)))
	sub_46B120((*nox_window)(unsafe.Pointer(v3)), nil)
	sub_46C690((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1316972))))))
	nox_xxx_wndShowModalMB_46A8C0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1316972))))))
	nox_xxx_windowFocus_46B500((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1316972))))))
	nox_xxx_wndSetWindowProc_46B300(*(*int32)(unsafe.Pointer(&dword_5d4594_1316972)), func(arg1 int32, arg2 int32, arg3 int32, arg4 int32) int32 {
		return sub_4BE320()
	})
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nil, 10100)))
	nox_gui_getWindowOffs_46AA20((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))), (*uint32)(unsafe.Pointer(&v10)), (*uint32)(unsafe.Pointer(&v9)))
	if false {
		v5 = v9 + 55
	} else {
		v5 = v9 + 80
	}
	nox_window_setPos_46A9B0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), v10+15, v5)
	v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2104)))
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v6))), *(*int32)(unsafe.Pointer(&dword_5d4594_1316972)))
	nox_xxx_wndSetProc_46B2C0(int32(uintptr(unsafe.Pointer(v6))), func(arg1 int32, arg2 int32, arg3 int32, arg4 int32) int32 {
		return sub_4BE330(arg1, uint32(arg2), (*int32)(unsafe.Pointer(uintptr(arg3))), arg4)
	})
	if false {
		v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2119)))
		nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v7))), *(*int32)(unsafe.Pointer(&dword_5d4594_1316972)))
	}
	return sub_4BE120(v2)
}
func sub_4BE120(a1 int32) int32 {
	var (
		v1     *uint32
		v2     int32
		v3     uint32
		v4     *uint32
		v5     int32
		v6     uint32
		v7     *uint32
		v8     *uint32
		v9     *uint32
		v10    *uint32
		v11    *uint32
		v12    *uint32
		result int32
	)
	_ = result
	var v14 *uint32
	var v15 int32
	var v16 [16]wchar2_t
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2102)))
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*9)))
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 58))) != 0 {
		v3 = uint32(v2 | 4)
	} else {
		v3 = uint32(v2) & 0xFFFFFFFB
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*9)) = v3
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2103)))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*9)))
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 62))) != 0 {
		v6 = uint32(v5 | 4)
	} else {
		v6 = uint32(v5) & 0xFFFFFFFB
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*9)) = v6
	v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2110)))
	nox_swprintf(&v16[0], (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), *(*uint32)(unsafe.Pointer(uintptr(a1 + 70))))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v7)))))), 16414, int32(uintptr(unsafe.Pointer(&v16[0]))), -1)
	switch *(*uint32)(unsafe.Pointer(uintptr(a1 + 66))) {
	case 0:
		v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2110)))
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))), 0)
		v15 = 2106
		v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), v15)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*9)) |= 4
	case 1:
		v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2110)))
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v9)))))), 0)
		v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2107)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*9)) |= 4
	case 2:
		v11 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2110)))
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v11)))))), 0)
		v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2108)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*9)) |= 4
	case 3:
		v12 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2110)))
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v12)))))), 1)
		v15 = 2109
		v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), v15)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*9)) |= 4
	default:
	}
	if false {
		v14 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2119)))
		nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v14)))))), 16394, int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 74)))), 0)
		result = sub_4BE2C0(int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 74)))))
	}
	return 0
}
func sub_4BE320() int32 {
	return 1
}
func sub_4BE330(a1 int32, a2 uint32, a3 *int32, a4 int32) int32 {
	var (
		v4 *uint32
		v5 *byte
	)
	_ = v5
	var result int32
	var v7 *wchar2_t
	var v8 int32
	var v9 int32
	var v10 *byte
	_ = v10
	var v11 *byte
	_ = v11
	var v12 *byte
	_ = v12
	var v13 *uint32
	var v14 *byte
	_ = v14
	var v15 *uint32
	var v16 *byte
	_ = v16
	var v17 *uint32
	var v18 *byte
	_ = v18
	var v19 *uint32
	var v20 *byte
	_ = v20
	var v21 *wchar2_t
	var v22 int32
	if a2 > 0x4007 {
		if a2 == 16393 {
			sub_4BE2C0(a4)
			nox_xxx_gameSetAudioFadeoutMb_501AC0(a4)
		} else if a2 == 16415 {
			v20 = (*byte)(sub_416640())
			v21 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a3)))))), 16413, 0, 0))))
			if v21 != nil {
				if *v21 != 0 {
					v22 = nox_wcstol(v21, nil, 10)
					if v22 < 0 {
						v22 = 0
					}
					if nox_xxx_wndGetID_46B0A0((*nox_window)(unsafe.Pointer(a3))) == 2110 {
						*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v20), 70)))) = uint32(v22)
						return 1
					}
				}
			}
		}
		return 1
	}
	if a2 != 16391 {
		if a2 != 23 && a2 == 16387 {
			v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), a4)))
			v5 = (*byte)(sub_416640())
			if v4 == nil {
				return 0
			}
			if int32(uint16(uintptr(unsafe.Pointer(a3)))) == 1 {
				return 0
			}
			v7 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))), 16413, 0, 0))))
			if v7 != nil && *v7 != 0 {
				v8 = nox_wcstol(v7, nil, 10)
				if v8 < 0 {
					v8 = 0
				}
				if a4 == 2110 {
					*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v5), 70)))) = uint32(v8)
					return 1
				}
			}
		}
		return 1
	}
	v9 = nox_xxx_wndGetID_46B0A0((*nox_window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	switch v9 {
	case 2102:
		v10 = (*byte)(sub_416640())
		*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v10), 58)))) ^= 1
		result = 1
	case 2103:
		v11 = (*byte)(sub_416640())
		*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v11), 62)))) ^= 1
		result = 1
	case 2106:
		v12 = (*byte)(sub_416640())
		v13 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2110)))
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v13)))))), 0)
		*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v12), 66)))) = 0
		sub_40A6A0(1)
		result = 1
	case 2107:
		v14 = (*byte)(sub_416640())
		v15 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2110)))
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v15)))))), 0)
		*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v14), 66)))) = 1
		sub_40A6A0(1)
		result = 1
	case 2108:
		v16 = (*byte)(sub_416640())
		v17 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2110)))
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v17)))))), 0)
		*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v16), 66)))) = 2
		sub_40A6A0(1)
		result = 1
	case 2109:
		v18 = (*byte)(sub_416640())
		v19 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2110)))
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v19)))))), 1)
		*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v18), 66)))) = 3
		sub_40A6A0(1)
		result = 1
	case 2130:
		sub_4BE610()
		result = 1
	default:
		return 1
	}
	return result
}
func sub_4BE610() int32 {
	var result int32
	result = int32(dword_5d4594_1316972)
	if dword_5d4594_1316972 != 0 {
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1316972))))))
		nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))))
		dword_5d4594_1316972 = 0
		result = nox_xxx_windowFocus_46B500(nil)
	}
	return result
}
func sub_4BE800(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1316980) = uint32(a1)
	return result
}
func sub_4BE810(a1 int32, a2 int32, a3 int32, a4 int8) int8 {
	var result int8
	*memmap.PtrUint32(0x5D4594, 1316988) = uint32(a1)
	result = a4
	*memmap.PtrUint32(0x5D4594, 1316984) = uint32(a2)
	*memmap.PtrUint32(0x5D4594, 1316992) = uint32(a3)
	*memmap.PtrUint8(0x5D4594, 1316996) = uint8(a4)
	return result
}
func sub_4BEAD0(a1 *int2, a2 *int2, a3 *int2, a4 *int2, a5 int32, a6 int32) {
	var (
		v6  int32
		v7  float64
		v8  *uint8
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 *uint8
		v17 int32
		v18 float64
		v19 float64
		v20 float64
		v21 float64
		v22 float64
		v23 float64
		v24 float64
		v25 float64
		v26 float64
		v27 int32
		v28 int32
		i   int32
		v30 int32
		v31 int32
		v32 int32
		v33 bool
		v34 int32
		v35 int32
		v36 int32
		v37 int32
		v38 int32
		v39 int32
		v40 [8]int32
		v41 int32
		v42 int32
		v43 float32
		v44 int32
		v45 int32
		v46 float32
		v47 int32
		v48 int32
	)
	v36 = a1.field_0
	v41 = a1.field_4
	v6 = a4.field_4
	v34 = a4.field_0
	v7 = 1.0 / float64(a5)
	v35 = a2.field_0
	v39 = a2.field_4
	v42 = a3.field_0
	v38 = a3.field_4
	v44 = v6
	v8 = (*uint8)(memmap.PtrOff(0x581450, 9876))
	v45 = 0
	for {
		v9 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*1))))
		v10 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*2))))
		v37 = v9
		v11 = int32(uint32(v39) * *(*uint32)(unsafe.Pointer(v8)))
		v12 = int32(uint32(v35)**(*uint32)(unsafe.Pointer(v8)) + uint32(v34*v10) + uint32(v42*v9))
		v13 = v36
		v14 = int32(uint32(v41) * *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), -int(4*1)))))
		v15 = int32(uint32(v36)**((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), -int(4*1)))) + uint32(v12))
		v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 16))
		v40[v45+4] = v15
		*(*int32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v40[0]))), v45*4)))) = v14 + v11 + v38*v37 + v44*v10
		v45++
		if int32(uintptr(unsafe.Pointer(v8))) >= int32(uintptr(memmap.PtrOff(0x581450, 9940))) {
			break
		}
	}
	*mem_getFloatPtr(0x587000, 180484) = float32(v7)
	v16 = (*uint8)(memmap.PtrOff(0x587000, 180468))
	v17 = 0
	*(*float32)(unsafe.Pointer(&dword_587000_180480)) = float32(v7 * v7)
	*(*float32)(unsafe.Pointer(&dword_587000_180476)) = float32(v7 * v7 * v7)
	*mem_getFloatPtr(0x587000, 180496) = *(*float32)(unsafe.Pointer(&dword_587000_180480)) + *(*float32)(unsafe.Pointer(&dword_587000_180480))
	v18 = float64(*(*float32)(unsafe.Pointer(&dword_587000_180476))) * 6.0
	*mem_getFloatPtr(0x587000, 180492) = float32(v18)
	*mem_getFloatPtr(0x587000, 180508) = float32(v18)
	v19 = float64(v40[7])
	v20 = float64(v40[6])
	v21 = float64(v40[5])
	v22 = float64(v40[4])
	v23 = float64(v40[3])
	v24 = float64(v40[2])
	v43 = float32(float64(v40[1]))
	v46 = float32(float64(v40[0]))
	for {
		v25 = v22 * float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v16))), -int(unsafe.Sizeof(float32(0))*2)))))
		v26 = v21 * float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v16))), -int(unsafe.Sizeof(float32(0))*1)))))
		v16 = (*uint8)(unsafe.Add(unsafe.Pointer(v16), 16))
		*(*float32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v40[0]))), v17*4)))) = float32(v25 + v26 + v20*float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v16))), -int(unsafe.Sizeof(float32(0))*4))))) + v19*float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v16))), -int(unsafe.Sizeof(float32(0))*3))))))
		v17++
		*(*float32)(unsafe.Pointer(&v40[v17+3])) = float32(float64(v46**((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v16))), -int(unsafe.Sizeof(float32(0))*6))))+v43**((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v16))), -int(unsafe.Sizeof(float32(0))*5))))) + v24*float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v16))), -int(unsafe.Sizeof(float32(0))*4))))) + v23*float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v16))), -int(unsafe.Sizeof(float32(0))*3))))))
		if int32(uintptr(unsafe.Pointer(v16))) >= int32(uintptr(memmap.PtrOff(0x587000, 180532))) {
			break
		}
	}
	if a5 > 0 {
		v47 = a5
		for {
			*(*float32)(unsafe.Pointer(&v40[0])) = *(*float32)(unsafe.Pointer(&v40[0])) + *(*float32)(unsafe.Pointer(&v40[1]))
			*(*float32)(unsafe.Pointer(&v40[1])) = *(*float32)(unsafe.Pointer(&v40[2])) + *(*float32)(unsafe.Pointer(&v40[1]))
			*(*float32)(unsafe.Pointer(&v40[2])) = *(*float32)(unsafe.Pointer(&v40[3])) + *(*float32)(unsafe.Pointer(&v40[2]))
			*(*float32)(unsafe.Pointer(&v40[4])) = *(*float32)(unsafe.Pointer(&v40[4])) + *(*float32)(unsafe.Pointer(&v40[5]))
			*(*float32)(unsafe.Pointer(&v40[5])) = *(*float32)(unsafe.Pointer(&v40[6])) + *(*float32)(unsafe.Pointer(&v40[5]))
			*(*float32)(unsafe.Pointer(&v40[6])) = *(*float32)(unsafe.Pointer(&v40[7])) + *(*float32)(unsafe.Pointer(&v40[6]))
			v27 = nox_float2int(*(*float32)(unsafe.Pointer(&v40[0])))
			v28 = nox_float2int(*(*float32)(unsafe.Pointer(&v40[4])))
			nox_client_drawAddPoint_49F500(v13, v41)
			nox_client_drawAddPoint_49F500(v27, v28)
			nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1316980))
			nox_client_drawLineFromPoints_49E4B0()
			if a6 != 0 {
				v48 = 0
				for i = v13 - v28; ; i = v13 - v28 {
					if v48 != 0 {
						v30 = 1
					} else {
						v30 = -1
					}
					if i >= 0 {
						v31 = i
					} else {
						v31 = v28 - v13
					}
					if i < 0 {
						i = v28 - v13
					}
					if v31 <= i {
						nox_client_drawAddPoint_49F500(v30+v27, v28)
						nox_client_drawAddPoint_49F500(v13+v30, v41)
					} else {
						nox_client_drawAddPoint_49F500(v27, v30+v28)
						nox_client_drawAddPoint_49F500(v13, v41+v30)
					}
					nox_client_drawLineFromPoints_49E4B0()
					if func() int32 {
						p := &v48
						*p++
						return *p
					}() >= 2 {
						break
					}
				}
			}
			if *memmap.PtrUint32(0x5D4594, 1316988) != 0 {
				nox_client_drawAddPoint_49F500(v13, v41)
				nox_client_drawAddPoint_49F500(v27, v28)
				nox_draw_set54RGB32_434040(*memmap.PtrInt32(0x5D4594, 1316984))
				sub_434080(*memmap.PtrInt32(0x5D4594, 1316992))
				v32 = int32(*memmap.PtrUint8(0x5D4594, 1316996))
				sub_49E4F0(v32)
			}
			v13 = v27
			v33 = v47 == 1
			v41 = v28
			v47--
			if v33 {
				break
			}
		}
	}
}
func sub_4BEDE0(a1 *int2, a2 *int2, a3 *int2, a4 *int2, a5 int32, a6 float32, a7 int32, a8 int32) {
	var (
		v8  int32
		v9  float64
		v10 *uint8
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 float64
		v17 float64
		v18 float64
		v19 float32
		v20 float32
		v21 float32
		v22 float32
		v23 int32
		v24 float32
		v25 int32
		v26 float32
		v27 int32
		v28 float32
		v29 int32
		v30 float32
		v31 int32
		v32 float32
		v33 int32
		v34 float32
		v35 [5]int2
		v36 *int2
		v37 float32
		v38 *int2
		v39 float32
		v40 int32
		v41 float32
		v42 int32
		v43 float32
		v44 float32
		v45 float32
	)
	v8 = a1.field_0
	v33 = a1.field_4
	v35[2].field_4 = a1.field_4
	v25 = v8
	v35[2].field_0 = v8
	v27 = a2.field_0
	v9 = 1.0 / float64(a5)
	v23 = a3.field_0
	v29 = a3.field_4
	v21 = 0.0
	v40 = a4.field_0
	v31 = a2.field_4
	v42 = a4.field_4
	v10 = (*uint8)(memmap.PtrOff(0x581450, 9876))
	v38 = nil
	for {
		v11 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*1))))
		v12 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*2))))
		v36 = (*int2)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), -int(4*1)))))))
		v13 = int32(uint32(v27)**(*uint32)(unsafe.Pointer(v10)) + uint32(v25)*uint32(uintptr(unsafe.Pointer(v36))) + uint32(v23*v11) + uint32(v40*v12))
		v14 = int32(uint32(v33)*uint32(uintptr(unsafe.Pointer(v36))) + uint32(v31)**(*uint32)(unsafe.Pointer(v10)) + uint32(v29*v11) + uint32(v42*v12))
		v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v10), 16))
		*(*int32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v35[0].field_0))), uint32(uintptr(unsafe.Pointer(v38))))))) = v13
		*(*int32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v35[3].field_0))), uint32(uintptr(unsafe.Pointer(v38))))))) = v14
		v38 = (*int2)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v38))), 4))))
		if int32(uintptr(unsafe.Pointer(v10))) >= int32(uintptr(memmap.PtrOff(0x581450, 9940))) {
			break
		}
	}
	v15 = a5
	if a5 > 0 {
		v16 = v9 * float64(a6)
		v41 = float32(v16 + v9)
		v45 = float32(float64(v35[0].field_0))
		v43 = float32(float64(v35[0].field_4))
		v34 = float32(float64(v35[1].field_0))
		v32 = float32(float64(v35[1].field_4))
		v28 = float32(float64(v35[3].field_0))
		v30 = float32(float64(v35[3].field_4))
		v26 = float32(float64(v35[4].field_0))
		v24 = float32(float64(v35[4].field_4))
		for {
			v17 = float64(v41 + v21)
			v22 = float32(v17)
			if v17 > 1.0 {
				v22 = 1.0
			}
			v18 = float64(v22 * v22)
			v44 = float32(v18)
			v37 = float32(v18 * float64(v22))
			v19 = v43*v44 + v45*v37 + v34*v22 + v32
			v35[0].field_0 = nox_float2int(v19)
			v20 = v30*v44 + v28*v37 + v26*v22 + v24
			v35[0].field_4 = nox_float2int(v20)
			v39 = float32(v16)
			v21 = v22 - v39
			(asFunc(a7, (*func(*int2, *int2, int32))(nil)).(func(*int2, *int2, int32)))(&v35[2], &v35[0], a8)
			v15--
			v35[2].field_0 = v35[0].field_0
			v35[2].field_4 = v35[0].field_4
			if v15 == 0 {
				break
			}
		}
	}
}
func nox_xxx_clientReportSecondaryWeapon_4BF010(a1 int32) int32 {
	var v3 [3]byte
	v3[0] = 224
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeCli_578B00(a1))
	return nox_xxx_netClientSend2_4E53C0(31, unsafe.Pointer(&v3[0]), 3, 0, 1)
}
func sub_4BF7E0(a1 *uint32) int16 {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v13 int32
		v14 *uint8
		v15 *uint8
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) + 15)
	v2 = int32(*a1 + 11)
	v13 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) + 15)
	nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
	nox_client_drawRectFilledOpaque_49CE30(v2, v1, 200, 200)
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v3))), unsafe.Sizeof(uint16(0))*0)) = *memmap.PtrUint16(0x852978, 8)
	if *memmap.PtrUint32(0x852978, 8) != 0 {
		v4 = int32(*memmap.PtrUint32(0x8531A0, 2576))
		if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
			nox_draw_setMaterial_4341D0(1, int32(*(*uint32)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x8531A0, 2576) + 2296)))))
			nox_draw_setMaterial_4341D0(2, int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 2304)))))
			nox_draw_setMaterial_4341D0(3, int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 2312)))))
			nox_draw_setMaterial_4341D0(4, int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 2308)))))
			nox_draw_setMaterial_4341D0(5, int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 2300)))))
			nox_draw_setMaterial_4341D0(6, int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 2292)))))
			if *(*uint32)(unsafe.Pointer(uintptr(v4 + 2292))) == *(*uint32)(unsafe.Pointer(uintptr(v4 + 2296))) {
				nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x973A20, uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 2252))))*4+24))))), v2, v1)
			} else {
				nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x973A20, uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 2252))))*4+16))))), v2, v1)
			}
			v5 = 0
			v14 = (*uint8)(memmap.PtrOff(0x973A20, uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 2252))))*104+32)))
			for {
				if *(*uint32)(unsafe.Pointer(uintptr(v4)))&uint32(1<<v5) != 0 && (uint32(1<<v5)&0x3000000) == 0 {
					v6 = sub_415CD0(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(1 << v5)))))))
					sub_4BF9F0(1<<v5, v6, v2, v13, int32(uintptr(unsafe.Pointer(v14))), v5, 0)
				}
				v5++
				if v5 >= 26 {
					break
				}
			}
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v4))))&2 != 0 {
				v7 = sub_415CD0(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(2)))))))
				sub_4BF9F0(2, v7, v2, v13, int32(uintptr(unsafe.Pointer(v14))), 0, 1)
			}
			v8 = 0
			for {
				if *(*uint32)(unsafe.Pointer(uintptr(v4)))&uint32(1<<v8) != 0 && uint32(1<<v8)&0x3000000 != 0 {
					v9 = sub_415CD0(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(1 << v8)))))))
					sub_4BF9F0(1<<v8, v9, v2, v13, int32(uintptr(unsafe.Pointer(v14))), v8, 0)
				}
				v8++
				if v8 >= 26 {
					break
				}
			}
			v10 = 0
			v15 = (*uint8)(memmap.PtrOff(0x973A20, uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 2252))))*108+256)))
			for {
				v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 4))))
				if v3&(1<<v10) != 0 {
					v11 = sub_415840(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(1 << v10)))))))
					*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v3))), unsafe.Sizeof(uint16(0))*0)) = uint16(sub_4BF9F0(1<<v10, v11, v2, v13, int32(uintptr(unsafe.Pointer(v15))), v10, 0))
				}
				v10++
				if v10 >= 27 {
					break
				}
			}
		}
	}
	return int16(v3)
}
func sub_4BF9F0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int32, a7 int32) int16 {
	var (
		v7  int32
		v8  int32
		v9  *uint32
		v10 int32
		v11 int32
		v12 *uint32
		v13 int32
		v14 int32
		v15 *uint8
		v16 *int32
		v17 **uint8
		v18 int32
		v19 *uint8
	)
	v7 = sub_461600(a2)
	v8 = v7
	if v7 != 0 {
		if *(*uint32)(unsafe.Pointer(uintptr(v7 + 112)))&0x2000000 != 0 {
			v9 = (*uint32)(nox_xxx_equipClothFindDefByTT_413270(int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 108))))))
		} else {
			v9 = (*uint32)(nox_xxx_getProjectileClassById_413250(int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 108))))))
		}
		v12 = v9
		if v9 != nil {
			v13 = v8 + 432
			v14 = 1
			v15 = (*uint8)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*4))))
			for {
				*((*uint8)(unsafe.Pointer(&v9))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v15), 1))
				*((*uint8)(unsafe.Pointer(&v11))) = *v15
				*((*uint8)(unsafe.Pointer(&v10))) = *((*uint8)(unsafe.Add(unsafe.Pointer(v15), -1)))
				nox_draw_setMaterial_4340A0(func() int32 {
					p := &v14
					x := *p
					*p++
					return x
				}(), v10, v11, int32(uintptr(unsafe.Pointer(v9))))
				v15 = (*uint8)(unsafe.Add(unsafe.Pointer(v15), 3))
				if v14 >= 7 {
					break
				}
			}
			v16 = (*int32)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*9))))
			v17 = (**uint8)(unsafe.Pointer(uintptr(v13)))
			v18 = 4
			for {
				v19 = *v17
				if *v17 != nil {
					*((*uint8)(unsafe.Pointer(&v11))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v19), 26))
					*((*uint8)(unsafe.Pointer(&v10))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v19), 25))
					*((*uint8)(unsafe.Pointer(&v19))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v19), 24))
					nox_draw_setMaterial_4340A0(*v16, int32(uintptr(unsafe.Pointer(v19))), v10, v11)
				}
				v17 = (**uint8)(unsafe.Add(unsafe.Pointer(v17), unsafe.Sizeof((*uint8)(nil))*1))
				v16 = (*int32)(unsafe.Add(unsafe.Pointer(v16), 4*1))
				v18--
				if v18 == 0 {
					break
				}
			}
		}
		if a7 != 0 {
			nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1319052)))), a3, a4)
		} else {
			nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a5 + a6*4)))))), a3, a4)
		}
	}
	return int16(v7)
}
func sub_4BFAD0() int32 {
	var (
		v0 int32
		v1 int32
		i  int32
		v3 *byte
		v4 *byte
		v5 int32
		v6 int32
	)
	v0 = 0
	v1 = 0
	for i = 0; i < 8; i += 4 {
		v3 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(*(**byte)(memmap.PtrOff(0x587000, uintptr(i)+180960)))))
		v4 = *(**byte)(memmap.PtrOff(0x587000, uintptr(i)+180968))
		*memmap.PtrUint32(0x973A20, uintptr(i+16)) = uint32(uintptr(unsafe.Pointer(v3)))
		*memmap.PtrUint32(0x973A20, uintptr(i+24)) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(v4))))
		v5 = 26
		for {
			*memmap.PtrUint32(0x973A20, uintptr(v1+32)) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1)+180976))))))
			v1 += 4
			v5--
			if v5 == 0 {
				break
			}
		}
		v6 = 27
		for {
			*memmap.PtrUint32(0x973A20, uintptr(v0+256)) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(*(**byte)(memmap.PtrOff(0x587000, uintptr(v0)+181184))))))
			v0 += 4
			v6--
			if v6 == 0 {
				break
			}
		}
	}
	*memmap.PtrUint32(0x5D4594, 1319052) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("MaleMedievalCloakTop")))))
	return 1
}
func sub_4BFB70(a1 int32) {
	if dword_5d4594_1319056 != 0 {
		dword_5d4594_1319056 = uint32(a1)
	} else {
		if a1 == 1 {
			nox_xxx_clientPlaySoundSpecial_452D80(1022, 100)
		}
		dword_5d4594_1319056 = uint32(a1)
	}
}
func sub_4BFBB0(a1 *uint32) {
	if dword_5d4594_1319056 != 0 {
		if dword_5d4594_1319056 == 1 {
			if a1 == nil {
				sub_4BFC70()
				sub_4BFB70(0)
			}
		}
	} else if uintptr(unsafe.Pointer(a1)) == uintptr(1) {
		sub_4BFBF0()
		sub_4BFB70(1)
	}
}
func sub_4BFBF0() int32 {
	var (
		result int32
		v1     int32
		v2     int32
	)
	result = int32(dword_5d4594_1319060)
	if dword_5d4594_1319060 != 0 {
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1319060))))), 0)
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1319060))))), 1)
		nox_window_get_size((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1319060))))), &v2, &v1)
		nox_window_setPos_46A9B0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1319060)))), nox_win_width/2-v2/2, nox_win_height/2-v1/2)
		result = nox_xxx_windowFocus_46B500(nil)
	}
	return result
}
func sub_4BFC70() int32 {
	var result int32
	result = int32(dword_5d4594_1319060)
	if dword_5d4594_1319060 != 0 {
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1319060))))), 1)
		result = nox_xxx_windowFocus_46B500(nil)
	}
	return result
}
func sub_4BFC90() int32 {
	var result int32
	result = int32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("SKey.wnd"), unsafe.Pointer(funAddr(sub_4BFCD0))))))
	dword_5d4594_1319060 = uint32(result)
	if result != 0 {
		sub_4BFB70(0)
		sub_4BFC70()
		result = 1
	}
	return result
}
func sub_4BFCD0(a1 int32, a2 int32, a3 *int32, a4 int32) int32 {
	var v3 int32
	if a2 == 16391 {
		v3 = nox_xxx_wndGetID_46B0A0((*nox_window)(unsafe.Pointer(a3)))
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
		if v3 == 10803 {
			sub_4BFC70()
		}
	}
	return 0
}
func sub_4BFD10() {
	nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1319060)))))
	dword_5d4594_1319060 = 0
	sub_4BFB70(0)
}
func sub_4BFD30() int32 {
	return int32(dword_5d4594_1319056)
}
func sub_4BFD40() {
	if dword_5d4594_1319268 == 1 {
		nox_window_set_hidden((*nox_window)(nox_gui_itemAmount_dialog_1319228), 1)
		nox_xxx_wnd_46ABB0((*nox_window)(nox_gui_itemAmount_dialog_1319228), 0)
		nox_xxx_wnd_46C6E0((*nox_window)(nox_gui_itemAmount_dialog_1319228))
		if nox_gui_itemAmount_item_1319256 != nil {
			nox_xxx_spriteDelete_45A4B0((*nox_drawable)(nox_gui_itemAmount_item_1319256))
		}
		nox_gui_itemAmount_item_1319256 = nil
		dword_5d4594_1319268 = 0
	} else {
		nox_xxx_wnd_46ABB0((*nox_window)(nox_gui_itemAmount_dialog_1319228), 1)
		sub_46C690((*nox_window)(nox_gui_itemAmount_dialog_1319228))
		nox_xxx_wndShowModalMB_46A8C0((*nox_window)(nox_gui_itemAmount_dialog_1319228))
		dword_5d4594_1319268 = 1
	}
}
func sub_4BFDD0(a1 *uint32, a2 int32, a3 uint32) int32 {
	switch a2 {
	case 5, 9, 13:
		if !nox_xxx_wndPointInWnd_46AAB0(a1, int32(uint16(a3)), int32(a3>>16)) {
			sub_4BFE40()
		}
		return 1
	case 6, 7, 10, 11, 14, 15:
		return 1
	default:
		return 0
	}
}
func sub_4BFE40() int32 {
	var (
		v0 *wchar2_t
		v1 uint32
		v3 int32
		v4 int32
		v5 int2
	)
	if dword_5d4594_1319268 != 1 {
		return 0
	}
	v0 = sub_46AF00(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1319232)))))
	v1 = uint32(nox_wcstol(v0, nil, 10))
	if v1 > uint32(*(*int32)(unsafe.Pointer(&dword_5d4594_1319248))) {
		v1 = dword_5d4594_1319248
	}
	nox_gui_getWindowOffs_46AA20((*nox_window)(nox_gui_itemAmount_dialog_1319228), (*uint32)(unsafe.Pointer(&v3)), (*uint32)(unsafe.Pointer(&v4)))
	v5.field_0 = int32(uint32(v3) + dword_587000_183456)
	v5.field_4 = int32(uint32(v4) + dword_587000_183460)
	if *memmap.PtrUint32(0x5D4594, 1319100) != 0 {
		(*(*func(uint32, uint32, uint32, uint32, uint32))(memmap.PtrOff(0x5D4594, 1319100)))(uint32(uintptr(unsafe.Pointer(&v5))), *memmap.PtrUint32(0x5D4594, 1319244), *memmap.PtrUint32(0x5D4594, 1319240), v1, *memmap.PtrUint32(0x5D4594, 1319252))
	}
	sub_4BFD40()
	return 1
}
func nox_gui_itemAmount_init_4BFEF0() int32 {
	dword_5d4594_1319264 = 0
	nox_gui_itemAmount_dialog_1319228 = unsafe.Pointer(nox_new_window_from_file(internCStr("MultMove.wnd"), unsafe.Pointer(funAddr(sub_4C01C0))))
	if nox_gui_itemAmount_dialog_1319228 == nil {
		return 0
	}
	nox_window_set_all_funcs((*nox_window)(nox_gui_itemAmount_dialog_1319228), func(arg1 int32, arg2 int32, arg3 int32, arg4 int32) int32 {
		return sub_4BFDD0((*uint32)(unsafe.Pointer(uintptr(arg1))), arg2, uint32(arg3))
	}, func(arg1 *nox_window, arg2 unsafe.Pointer) int32 {
		return sub_4C0030(int32(uintptr(unsafe.Pointer(arg1))))
	}, nil)
	dword_5d4594_1319232 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(nox_gui_itemAmount_dialog_1319228), 3601))))
	dword_5d4594_1319236 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(nox_gui_itemAmount_dialog_1319228), 3607))))
	nox_window_set_hidden((*nox_window)(nox_gui_itemAmount_dialog_1319228), 1)
	nox_xxx_wnd_46ABB0((*nox_window)(nox_gui_itemAmount_dialog_1319228), 0)
	*memmap.PtrUint32(0x5D4594, 1319108) = 0
	*memmap.PtrUint32(0x5D4594, 1319112) = 0
	*memmap.PtrUint32(0x5D4594, 1319116) = uint32(nox_win_width)
	*memmap.PtrUint32(0x5D4594, 1319120) = uint32(nox_win_height)
	*memmap.PtrUint32(0x5D4594, 1319140) = uint32(nox_win_width)
	*memmap.PtrUint32(0x5D4594, 1319144) = uint32(nox_win_height)
	*memmap.PtrUint32(0x5D4594, 1319124) = 0
	*memmap.PtrUint32(0x5D4594, 1319128) = 0
	*memmap.PtrUint32(0x5D4594, 1319196) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("MultiMoveBase")))))
	*memmap.PtrUint32(0x5D4594, 1319200) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("MultiMoveUpLit")))))
	*memmap.PtrUint32(0x5D4594, 1319204) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("MultiMoveDownLit")))))
	*memmap.PtrUint32(0x5D4594, 1319208) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("MultiMoveYesPressed")))))
	*memmap.PtrUint32(0x5D4594, 1319212) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("MultiMoveNoPressed")))))
	*memmap.PtrUint32(0x5D4594, 1319216) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("MultiMoveBaseNoTag")))))
	*memmap.PtrUint32(0x5D4594, 1319220) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("MultiMoveYesPressedNoTag")))))
	*memmap.PtrUint32(0x5D4594, 1319224) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("MultiMoveNoPressedNoTag")))))
	return 1
}
func sub_4C0030(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		v3 int32
		v5 int32
		v6 int32
	)
	nox_client_drawRectFilledAlpha_49CF10(0, 0, nox_win_width, nox_win_height)
	nox_gui_getWindowOffs_46AA20((*nox_window)(unsafe.Pointer(uintptr(a1))), (*uint32)(unsafe.Pointer(&v5)), (*uint32)(unsafe.Pointer(&v6)))
	v1 = int32(*memmap.PtrUint32(0x5D4594, 1319196))
	if dword_5d4594_1319264 == 0 {
		v1 = int32(*memmap.PtrUint32(0x5D4594, 1319216))
	}
	nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(v1))), v5, v6)
	*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(nox_gui_itemAmount_item_1319256)) + 12))) = uint32(v5) + dword_587000_183456
	*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(nox_gui_itemAmount_item_1319256)) + 16))) = uint32(v6) + dword_587000_183460
	(*(*func(*uint8, uint32))(unsafe.Pointer(uintptr(uint32(uintptr(nox_gui_itemAmount_item_1319256)) + 300))))((*uint8)(memmap.PtrOff(0x5D4594, 1319108)), uint32(uintptr(nox_gui_itemAmount_item_1319256)))
	if nox_xxx_wndGetChildByID_46B0C0((*nox_window)(nox_gui_itemAmount_dialog_1319228), 3603).DrawData().Field0&4 != 0 {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1319204)))), v5, v6)
	}
	if nox_xxx_wndGetChildByID_46B0C0((*nox_window)(nox_gui_itemAmount_dialog_1319228), 3602).DrawData().Field0&4 != 0 {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1319200)))), v5, v6)
	}
	if nox_xxx_wndGetChildByID_46B0C0((*nox_window)(nox_gui_itemAmount_dialog_1319228), 3604).DrawData().Field0&4 != 0 {
		v2 = int32(*memmap.PtrUint32(0x5D4594, 1319208))
		if dword_5d4594_1319264 == 0 {
			v2 = int32(*memmap.PtrUint32(0x5D4594, 1319220))
		}
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(v2))), v5, v6)
	}
	if nox_xxx_wndGetChildByID_46B0C0((*nox_window)(nox_gui_itemAmount_dialog_1319228), 3605).DrawData().Field0&4 != 0 {
		v3 = int32(*memmap.PtrUint32(0x5D4594, 1319212))
		if dword_5d4594_1319264 == 0 {
			v3 = int32(*memmap.PtrUint32(0x5D4594, 1319224))
		}
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(v3))), v5, v6)
	}
	return 1
}
func sub_4C01C0(a1 int32, a2 int32, a3 *int32, a4 int32) int32 {
	var (
		v3     int32
		result int32
		v5     *wchar2_t
		v6     uint32
		v7     *wchar2_t
		v8     uint32
		v9     *wchar2_t
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    int2
	)
	if a2 != 16391 || dword_5d4594_1319268 != 1 {
		return 0
	}
	v3 = nox_xxx_wndGetID_46B0A0((*nox_window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	switch v3 {
	case 3602:
		v7 = sub_46AF00(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1319232)))))
		v8 = uint32(nox_wcstol(v7, nil, 10) + 1)
		if v8 > uint32(*(*int32)(unsafe.Pointer(&dword_5d4594_1319248))) {
			return 0
		}
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319164)), (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), v8)
		sub_46AEE0(*(*int32)(unsafe.Pointer(&dword_5d4594_1319232)), int32(uintptr(memmap.PtrOff(0x5D4594, 1319164))))
		if dword_5d4594_1319264 == 0 {
			return 0
		}
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319068)), (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), dword_5d4594_1319260*v8)
		sub_46AEE0(*(*int32)(unsafe.Pointer(&dword_5d4594_1319236)), int32(uintptr(memmap.PtrOff(0x5D4594, 1319068))))
		result = 0
	case 3603:
		v9 = sub_46AF00(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1319232)))))
		v10 = nox_wcstol(v9, nil, 10)
		v11 = v10
		if v10 > 1 {
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319164)), (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), v10-1)
			sub_46AEE0(*(*int32)(unsafe.Pointer(&dword_5d4594_1319232)), int32(uintptr(memmap.PtrOff(0x5D4594, 1319164))))
			if dword_5d4594_1319264 != 0 {
				nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319068)), (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), dword_5d4594_1319260*uint32(v11-1))
				sub_46AEE0(*(*int32)(unsafe.Pointer(&dword_5d4594_1319236)), int32(uintptr(memmap.PtrOff(0x5D4594, 1319068))))
			}
		}
		return 0
	case 3604, 3606:
		v5 = sub_46AF00(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1319232)))))
		v6 = uint32(nox_wcstol(v5, nil, 10))
		if v6 > uint32(*(*int32)(unsafe.Pointer(&dword_5d4594_1319248))) {
			v6 = dword_5d4594_1319248
		}
		nox_gui_getWindowOffs_46AA20((*nox_window)(nox_gui_itemAmount_dialog_1319228), (*uint32)(unsafe.Pointer(&v12)), (*uint32)(unsafe.Pointer(&v13)))
		v14.field_0 = int32(uint32(v12) + dword_587000_183456)
		v14.field_4 = int32(uint32(v13) + dword_587000_183460)
		if *memmap.PtrUint32(0x5D4594, 1319160) != 0 {
			(*(*func(uint32, uint32, uint32, uint32, uint32))(memmap.PtrOff(0x5D4594, 1319160)))(uint32(uintptr(unsafe.Pointer(&v14))), *memmap.PtrUint32(0x5D4594, 1319244), *memmap.PtrUint32(0x5D4594, 1319240), v6, *memmap.PtrUint32(0x5D4594, 1319252))
		}
		sub_4BFD40()
		result = 0
	case 3605:
		sub_4BFE40()
		result = 0
	default:
		return 0
	}
	return result
}
func nox_gui_itemAmount_free_4C03E0() {
	if nox_gui_itemAmount_item_1319256 != nil {
		nox_xxx_spriteDelete_45A4B0((*nox_drawable)(nox_gui_itemAmount_item_1319256))
	}
	nox_gui_itemAmount_item_1319256 = nil
	nox_xxx_windowDestroyMB_46C4E0((*nox_window)(nox_gui_itemAmount_dialog_1319228))
	nox_gui_itemAmount_dialog_1319228 = nil
	dword_5d4594_1319232 = 0
	dword_5d4594_1319236 = 0
	dword_5d4594_1319264 = 0
}
func nox_gui_itemAmountDialog_4C0430(title *wchar2_t, x int32, y int32, a4 int32, a5 int32, a6 unsafe.Pointer, a7 int32, a8 int32, accept unsafe.Pointer, cancel unsafe.Pointer) int32 {
	var (
		v10    *uint32
		result int32
	)
	v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(nox_gui_itemAmount_dialog_1319228), 3606)))
	sub_46AEE0(int32(uintptr(unsafe.Pointer(v10))), int32(uintptr(unsafe.Pointer(title))))
	nox_gui_itemAmount_item_1319256 = unsafe.Pointer(nox_new_drawable_for_thing(a5))
	*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(nox_gui_itemAmount_item_1319256)) + 120))) |= 0x40000000
	if a6 != nil {
		alloc.Memcpy(unsafe.Pointer(uintptr(uint32(uintptr(nox_gui_itemAmount_item_1319256))+432)), a6, 0x14)
	}
	*memmap.PtrUint32(0x5D4594, 1319160) = uint32(uintptr(accept))
	*memmap.PtrUint32(0x5D4594, 1319100) = uint32(uintptr(cancel))
	*memmap.PtrUint32(0x5D4594, 1319240) = uint32(a5)
	*memmap.PtrUint32(0x5D4594, 1319244) = uint32(a4)
	dword_5d4594_1319248 = uint32(a7)
	*memmap.PtrUint32(0x5D4594, 1319252) = uint32(a8)
	sub_4BFD40()
	sub_4C0560(x, y)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319164)), (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), 1)
	sub_46AEE0(*(*int32)(unsafe.Pointer(&dword_5d4594_1319232)), int32(uintptr(memmap.PtrOff(0x5D4594, 1319164))))
	if dword_5d4594_1319264 != 0 {
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319068)), (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), dword_5d4594_1319260)
		result = sub_46AEE0(*(*int32)(unsafe.Pointer(&dword_5d4594_1319236)), int32(uintptr(memmap.PtrOff(0x5D4594, 1319068))))
	} else {
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319068)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1319272)))
		result = sub_46AEE0(*(*int32)(unsafe.Pointer(&dword_5d4594_1319236)), int32(uintptr(memmap.PtrOff(0x5D4594, 1319068))))
	}
	return result
}
func sub_4C0560(a1 int32, a2 int32) int32 {
	var (
		v2 int32
		v3 int32
		v5 int32
		v6 int32
	)
	nox_window_get_size((*nox_window)(nox_gui_itemAmount_dialog_1319228), &v5, &v6)
	v2 = int32(uint32(a1) - dword_587000_183456)
	v3 = int32(uint32(a2) - dword_587000_183460)
	if a1-*(*int32)(unsafe.Pointer(&dword_587000_183456)) < 0 {
		v2 = 0
	}
	if v3 < 0 {
		v3 = 0
	}
	if v2+v5 >= nox_win_width {
		v2 = nox_win_width - v5
	}
	if v3+v6 >= nox_win_height {
		v3 = nox_win_height - v6
	}
	return nox_window_setPos_46A9B0((*nox_window)(nox_gui_itemAmount_dialog_1319228), v2, v3)
}
func sub_4C05F0(a1 int32, a2 int32) int32 {
	var result int32
	result = a1
	dword_5d4594_1319264 = uint32(a1)
	dword_5d4594_1319260 = uint32(a2)
	return result
}
func nox_xxx_func_4C0610() int32 {
	var v1 [2]byte
	v1[0] = 201
	v1[1] = 14
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, (*uint8)(unsafe.Pointer(&v1[0])), 2)
}
func sub_4C0630(a1 int32, a2 uint32, a3 uint32) int32 {
	var (
		v3  int32
		v4  *uint32
		v5  *uint32
		v6  int32
		v7  int32
		v8  *uint32
		v9  int32
		v10 int32
		v12 *uint32
		v13 *uint32
		v14 *uint32
		v15 int32
		a1a int2
	)
	a1a.field_4 = int32(a3 >> 16)
	a1a.field_0 = int32(uint16(a3))
	if a2 == 5 {
		v12 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3704)))
		if nox_xxx_wndPointInWnd_46AAB0(v12, a1a.field_0, a1a.field_4) {
			*((*uint8)(unsafe.Pointer(&v13))) = uint8(sub_4C0910(&a1a))
			v14 = v13
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*1)) != 0 {
				nox_xxx_wndSetCaptureMain_46ADC0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320940))))))
				nox_xxx_setKeybTimeout_4160D0(2)
				*(*int2)(memmap.PtrOff(0x5D4594, 1319276)) = a1a
				dword_5d4594_1320968 = *v14
				*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1320968 + 128))) = *(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*1))+1)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*1))+1))) = 0
				nox_xxx_cursorSetDraggedItem_477690((*nox_drawable)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320968))))))
				v15 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*1)) - 1)
				*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*1)) = uint32(v15)
				if v15 == 0 {
					*v14 = 0
				}
				dword_5d4594_1320972 = uint32(uintptr(unsafe.Pointer(v14)))
				*memmap.PtrUint32(0x5D4594, 1320304) = 0
				nox_xxx_clientPlaySoundSpecial_452D80(791, 100)
			}
		}
		return 1
	}
	if a2 <= 5 || a2 > 7 {
		return 0
	}
	v3 = int32(uintptr(unsafe.Pointer(nox_xxx_wndGetCaptureMain_46AE00())))
	v4 = *(**uint32)(unsafe.Pointer(&dword_5d4594_1320940))
	if uint32(v3) == dword_5d4594_1320940 {
		nox_xxx_wndClearCaptureMain_46ADE0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320940))))))
		v4 = *(**uint32)(unsafe.Pointer(&dword_5d4594_1320940))
	}
	if dword_5d4594_1320968 == 0 {
		return 1
	}
	if *memmap.PtrUint32(0x5D4594, 1320304) != 0 {
		if *memmap.PtrUint32(0x5D4594, 1320304) == 1 {
			v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(v4)), 3705)))
			if !nox_xxx_wndPointInWnd_46AAB0(v8, a1a.field_0, a1a.field_4) || (func() bool {
				v9 = int32(*memmap.PtrUint32(0x5D4594, 1319276) - uint32(a1a.field_0))
				v10 = int32(*memmap.PtrUint32(0x5D4594, 1319280) - uint32(a1a.field_4))
				return !nox_xxx_checkKeybTimeout_4160F0(3, gameFPS()/3)
			}()) && v9*v9+v10*v10 < 100 {
				nox_xxx_clientTrade_0_4C08E0(*(*int32)(unsafe.Pointer(&dword_5d4594_1320968)))
			}
		}
	} else {
		v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(v4)), 3704)))
		if nox_xxx_wndPointInWnd_46AAB0(v5, a1a.field_0, a1a.field_4) {
			v6 = int32(*memmap.PtrUint32(0x5D4594, 1319276) - uint32(a1a.field_0))
			v7 = int32(*memmap.PtrUint32(0x5D4594, 1319280) - uint32(a1a.field_4))
			if !nox_xxx_checkKeybTimeout_4160F0(2, gameFPS()/3) && v6*v6+v7*v7 < 100 {
				nox_xxx_clientTrade_0_4C08E0(*(*int32)(unsafe.Pointer(&dword_5d4594_1320968)))
			}
		} else {
			nox_xxx_clientTrade_0_4C08E0(*(*int32)(unsafe.Pointer(&dword_5d4594_1320968)))
		}
	}
	*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1320972 + func() uint32 {
		p := (*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1320972 + 4)))
		x := *p
		*p++
		return x
	}()*4 + 8))) = *(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1320968 + 128)))
	if *(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1320972 + 4))) == 1 {
		**(**uint32)(unsafe.Pointer(&dword_5d4594_1320972)) = dword_5d4594_1320968
	}
	nox_xxx_cursorResetDraggedItem_4776A0()
	dword_5d4594_1320968 = 0
	dword_5d4594_1320972 = 0
	return 1
}
func nox_xxx_clientTrade_0_4C08E0(a1 int32) int32 {
	var v2 [4]byte
	v2[0] = 201
	v2[1] = 16
	*(*uint16)(unsafe.Pointer(&v2[2])) = uint16(nox_xxx_netGetUnitCodeCli_578B00(a1))
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, (*uint8)(unsafe.Pointer(&v2[0])), 4)
}
func sub_4C0910(a1 *int2) int8 {
	var (
		v1  *uint32
		v2  int32
		v3  int32
		i   int32
		v5  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int4
	)
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3704)))
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(v1)), (*uint32)(unsafe.Pointer(&v8)), (*uint32)(unsafe.Pointer(&v9)))
	v2 = 0
	v7 = 0
	for 2 != 0 {
		v3 = 0
		for i = 0; i < 100; i += 50 {
			v10.field_0 = i + v8
			v10.field_8 = i + v8 + 50
			v10.field_4 = v2 + v9
			v10.field_C = v2 + v9 + 50
			v5 = nox_xxx_pointInRect_4281F0(a1, &v10)
			if v5 != 0 {
				return int8(uintptr(memmap.PtrOff(0x5D4594, uintptr((v7+v3*2)*140)+1319284)))
			}
			v3++
		}
		v2 += 50
		v7++
		if v2 < 100 {
			continue
		}
		break
	}
	return int8(v5)
}
func sub_4C0C90(a1 int32, a2 int32, a3 *int32, a4 int32) int32 {
	var v3 int32
	if a2 == 16391 {
		v3 = nox_xxx_wndGetID_46B0A0((*nox_window)(unsafe.Pointer(a3)))
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
		if v3 == 3708 {
			nox_xxx_clientTrade_4C0CE0()
		} else if v3 == 3710 {
			nox_xxx_func_4C0610()
			return 0
		}
	}
	return 0
}
func nox_xxx_clientTrade_4C0CE0() int32 {
	var v1 [2]byte
	v1[0] = 201
	v1[1] = 17
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, (*uint8)(unsafe.Pointer(&v1[0])), 2)
}
func sub_4C0D00() int32 {
	var (
		v0  *uint32
		v1  *uint32
		v2  *uint32
		v3  *uint32
		v4  *uint32
		v5  *uint32
		v6  *uint8
		v7  int32
		v8  int32
		v9  int32
		v10 *uint32
		v11 *uint8
		v12 int32
		v13 int32
		v14 int32
		v16 *uint8
		v17 *uint8
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 int32
		v23 [32]wchar2_t
	)
	nox_gui_getWindowOffs_46AA20((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320940))))), (*uint32)(unsafe.Pointer(&v21)), (*uint32)(unsafe.Pointer(&v22)))
	nox_window_get_size((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320940))))), &v20, &v19)
	nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1320164)))), v21, v22)
	v0 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3711)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v0)))))), 16385, int32(uintptr(memmap.PtrOff(0x5D4594, 1320240))), 0)
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3712)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), 16385, int32(uintptr(memmap.PtrOff(0x5D4594, 1320868))), 0)
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3713)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), 16385, int32(uintptr(memmap.PtrOff(0x5D4594, 1320100))), 0)
	nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1320184)))), int32(uint32(v21)+*memmap.PtrUint32(0x587000, 183696)-64), int32(uint32(v22)+*memmap.PtrUint32(0x587000, 183700)-64))
	nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1320184)))), int32(uint32(v21)+*memmap.PtrUint32(0x587000, 183704)-64), int32(uint32(v22)+*memmap.PtrUint32(0x587000, 183708)-64))
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3708)))
	if dword_5d4594_1320944 != 0 {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1320172)))), v21, v22)
	} else if *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*9))&4 != 0 {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1320168)))), v21, v22)
	}
	if dword_5d4594_1320948 != 0 {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1320176)))), v21, v22)
	}
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3710)))
	if *memmap.PtrUint32(0x5D4594, 1320960) != 0 || *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*9))&4 != 0 {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1320180)))), v21, v22)
	}
	v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3704)))
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(v5)), (*uint32)(unsafe.Pointer(&v21)), (*uint32)(unsafe.Pointer(&v22)))
	v6 = (*uint8)(memmap.PtrOff(0x5D4594, 1319284))
	v18 = nox_xxx_guiFontHeightMB_43F320(nil)
	v7 = 0
	v16 = (*uint8)(memmap.PtrOff(0x5D4594, 1319284))
	for {
		v8 = 0
		for {
			if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*1))) != 0 {
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v6)) + 12))) = uint32(v8 + v21 + 25)
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v6)) + 16))) = uint32(v22 + v7 + 25)
				(*(*func(*uint8, uint32))(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v6)) + 300))))((*uint8)(memmap.PtrOff(0x5D4594, 1320188)), *(*uint32)(unsafe.Pointer(v6)))
				nox_swprintf(&v23[0], (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*1))))
				nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
				nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer((*int16)(unsafe.Pointer(&v23[0])))), v8+v21+5, v22+v7+5)
				v9 = v22 + v7 + 50
				nox_swprintf(&v23[0], (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*34))))
				nox_xxx_drawSetTextColor_434390(int32(nox_color_yellow_2589772))
				nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer((*int16)(unsafe.Pointer(&v23[0])))), v8+v21+5, v9-v18-5)
			}
			v8 += 50
			v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 280))
			if v8 >= 100 {
				break
			}
		}
		v7 += 50
		v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v16), 140))
		v16 = (*uint8)(unsafe.Add(unsafe.Pointer(v16), 140))
		if int32(uintptr(unsafe.Pointer(v16))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1319564))) {
			break
		}
	}
	v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3705)))
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(v10)), (*uint32)(unsafe.Pointer(&v21)), (*uint32)(unsafe.Pointer(&v22)))
	v11 = (*uint8)(memmap.PtrOff(0x5D4594, 1320308))
	v12 = 0
	v17 = (*uint8)(memmap.PtrOff(0x5D4594, 1320308))
	for {
		v13 = 0
		for {
			if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v11))), 4*1))) != 0 {
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v11)) + 12))) = uint32(v13 + v21 + 25)
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v11)) + 16))) = uint32(v22 + v12 + 25)
				(*(*func(*uint8, uint32))(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v11)) + 300))))((*uint8)(memmap.PtrOff(0x5D4594, 1320188)), *(*uint32)(unsafe.Pointer(v11)))
				nox_swprintf(&v23[0], (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v11))), 4*1))))
				nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
				nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer((*int16)(unsafe.Pointer(&v23[0])))), v13+v21+5, v22+v12+5)
				v14 = v22 + v12 + 50
				nox_swprintf(&v23[0], (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v11))), 4*34))))
				nox_xxx_drawSetTextColor_434390(int32(nox_color_yellow_2589772))
				nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer((*int16)(unsafe.Pointer(&v23[0])))), v13+v21+5, v14-v18-5)
			}
			v13 += 50
			v11 = (*uint8)(unsafe.Add(unsafe.Pointer(v11), 280))
			if v13 >= 100 {
				break
			}
		}
		v12 += 50
		v11 = (*uint8)(unsafe.Add(unsafe.Pointer(v17), 140))
		v17 = (*uint8)(unsafe.Add(unsafe.Pointer(v17), 140))
		if int32(uintptr(unsafe.Pointer(v17))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1320588))) {
			break
		}
	}
	return 1
}
func sub_4C1120(a1 int32, a2 int32, a3 **wchar2_t) int32 {
	var (
		v3  *uint32
		v4  **wchar2_t
		v5  *uint32
		v6  *wchar2_t
		a1a int2
	)
	a1a.field_0 = int32(uint16(uintptr(unsafe.Pointer(a3))))
	a1a.field_4 = int32(uint32(uintptr(unsafe.Pointer(a3))) >> 16)
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3704)))
	if nox_xxx_wndPointInWnd_46AAB0(v3, int32(uint16(uintptr(unsafe.Pointer(a3)))), int32(uint32(uintptr(unsafe.Pointer(a3)))>>16)) {
		*((*uint8)(unsafe.Pointer(&v4))) = uint8(sub_4C0910(&a1a))
	} else {
		v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3705)))
		if nox_xxx_wndPointInWnd_46AAB0(v5, a1a.field_0, a1a.field_4) {
			*((*uint8)(unsafe.Pointer(&v4))) = uint8(sub_4C11E0((*uint32)(unsafe.Pointer(&a1a))))
		} else {
			v4 = a3
		}
	}
	if *v4 != nil {
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(*v4))), 4*32))) = uint32(uintptr(unsafe.Pointer(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*2)))))
		v6 = nox_xxx_clientAskInfoMb_4BF050((*nox_drawable)(unsafe.Pointer(*v4)))
		nox_xxx_cursorSetTooltip_4776B0(v6)
	}
	return 1
}
func sub_4C11E0(a1 *uint32) int8 {
	var (
		v1  *uint32
		v2  int32
		v3  int32
		i   int32
		v5  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int4
	)
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3705)))
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(v1)), (*uint32)(unsafe.Pointer(&v8)), (*uint32)(unsafe.Pointer(&v9)))
	v2 = 0
	v7 = 0
	for 2 != 0 {
		v3 = 0
		for i = 0; i < 100; i += 50 {
			v10.field_0 = i + v8
			v10.field_8 = i + v8 + 50
			v10.field_4 = v2 + v9
			v10.field_C = v2 + v9 + 50
			v5 = nox_xxx_pointInRect_4281F0((*int2)(unsafe.Pointer(a1)), &v10)
			if v5 != 0 {
				return int8(uintptr(memmap.PtrOff(0x5D4594, uintptr((v7+v3*2)*140)+1320308)))
			}
			v3++
		}
		v2 += 50
		v7++
		if v2 < 100 {
			continue
		}
		break
	}
	return int8(v5)
}
func nox_xxx_closeP2PTradeWnd_4C12A0() int32 {
	var result int32
	nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))))
	result = 0
	dword_5d4594_1320940 = 0
	dword_5d4594_1320964 = 0
	return result
}
func sub_4C12C0() int32 {
	return int32(dword_5d4594_1320964)
}
func nox_xxx_showP2PTradeWnd_4C12D0() int32 {
	var result int32
	result = int32(dword_5d4594_1320964)
	if dword_5d4594_1320964 != 0 {
		result = nox_xxx_wndShowModalMB_46A8C0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320940))))))
	}
	return result
}
func nox_xxx_netP2PStartTrade_4C1320(a1 int32) int32 {
	var (
		v1 int32
		v3 *uint32
		v4 *uint32
		v5 int32
		v6 int32
	)
	v1 = int32(*memmap.PtrUint32(0x8531A0, 2576))
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 {
		return 0
	}
	if dword_5d4594_1320964 == 1 {
		return 0
	}
	dword_5d4594_1320964 = 1
	sub_4C1410()
	nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319844)), (*wchar2_t)(unsafe.Pointer(uintptr(a1+2))))
	nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320940))))), 1)
	nox_xxx_showP2PTradeWnd_4C12D0()
	nox_window_get_size((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320940))))), &v6, &v5)
	nox_window_setPos_46A9B0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 198, 193)
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3702)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), 16385, v1+4704, 0)
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3703)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))), 16385, int32(uintptr(memmap.PtrOff(0x5D4594, 1319844))), 0)
	sub_467BB0()
	return 1
}
func sub_4C1410() int32 {
	var (
		v0     *uint32
		v1     *uint32
		v2     *uint8
		v3     *uint8
		v4     int32
		v5     *uint8
		v6     *uint8
		v7     int32
		v8     *uint32
		v9     *uint32
		v10    *uint32
		result int32
		v12    [64]wchar2_t
	)
	*memmap.PtrUint16(0x5D4594, 1320240) = 0
	*memmap.PtrUint16(0x5D4594, 1320868) = 0
	*memmap.PtrUint16(0x5D4594, 1320100) = 0
	v0 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3702)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v0)))))), 16385, int32(uintptr(memmap.PtrOff(0x5D4594, 1320976))), 0)
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3703)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), 16385, int32(uintptr(memmap.PtrOff(0x5D4594, 1320980))), 0)
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1319284))
	for {
		v3 = v2
		v4 = 2
		for {
			if *(*uint32)(unsafe.Pointer(v3)) != 0 {
				nox_xxx_spriteDelete_45A4B0((*nox_drawable)(unsafe.Pointer(*(**uint64)(unsafe.Pointer(v3)))))
			}
			*(*uint32)(unsafe.Pointer(v3)) = 0
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1))) = 0
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 280))
			v4--
			if v4 == 0 {
				break
			}
		}
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 140))
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1319564))) {
			break
		}
	}
	v5 = (*uint8)(memmap.PtrOff(0x5D4594, 1320308))
	for {
		v6 = v5
		v7 = 2
		for {
			if *(*uint32)(unsafe.Pointer(v6)) != 0 {
				nox_xxx_spriteDelete_45A4B0((*nox_drawable)(unsafe.Pointer(*(**uint64)(unsafe.Pointer(v6)))))
			}
			*(*uint32)(unsafe.Pointer(v6)) = 0
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*1))) = 0
			v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 280))
			v7--
			if v7 == 0 {
				break
			}
		}
		v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 140))
		if int32(uintptr(unsafe.Pointer(v5))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1320588))) {
			break
		}
	}
	nox_swprintf(&v12[0], (*wchar2_t)(memmap.PtrOff(0x5D4594, 1319972)), 0)
	v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3711)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))), 16385, int32(uintptr(unsafe.Pointer(&v12[0]))), 0)
	v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3712)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v9)))))), 16385, int32(uintptr(unsafe.Pointer(&v12[0]))), 0)
	v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3713)))
	result = nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v10)))))), 16385, int32(uintptr(unsafe.Pointer(&v12[0]))), 0)
	dword_5d4594_1320944 = 0
	dword_5d4594_1320948 = 0
	dword_5d4594_1320968 = 0
	dword_5d4594_1320972 = 0
	dword_5d4594_1320932 = 0
	dword_5d4594_1320936 = 0
	return result
}
func sub_4C1590() int32 {
	var result int32
	result = int32(dword_5d4594_1320964)
	if dword_5d4594_1320964 != 0 {
		sub_4C1410()
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320940))))), 1)
		nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320940))))), 0)
		dword_5d4594_1320964 = 0
		result = sub_467C10()
	}
	return result
}
func sub_4C1710(a1 int32, a2 int32) int32 {
	var (
		result int32
		i      *uint32
		v4     *uint32
		v5     int32
	)
	result = 0
	for i = (*uint32)(unsafe.Pointer(uintptr(a1 + 8))); *i != uint32(a2); i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) {
		if func() int32 {
			p := &result
			*p++
			return *p
		}() >= 32 {
			return result
		}
	}
	if result < 31 {
		v4 = (*uint32)(unsafe.Pointer(uintptr(a1 + result*4 + 8)))
		v5 = 31 - result
		for {
			result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))
			*v4 = uint32(result)
			v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
			v5--
			if v5 == 0 {
				break
			}
		}
	}
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 132))) = 0
	return result
}
func sub_4C1760(a1 int32, a2 int32) int32 {
	var (
		v2 int32
		i  *uint32
	)
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 4))) == 0 {
		return 0
	}
	v2 = 0
	for i = (*uint32)(unsafe.Pointer(uintptr(a1 + 8))); *i != uint32(a2); i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) {
		if func() int32 {
			p := &v2
			*p++
			return *p
		}() >= 32 {
			return 0
		}
	}
	return 1
}
func nox_xxx_tradeClientAddItem_4C1790(a1 int32) *byte {
	var (
		result *byte
		v2     int32
		v3     *byte
		v4     *uint32
		v5     int32
		v6     *int32
		v7     *uint8
		v8     int32
		v9     int32
		v10    int32
	)
	result = *(**byte)(unsafe.Pointer(&dword_5d4594_1320964))
	if dword_5d4594_1320964 == 0 {
		return result
	}
	v2 = a1
	dword_5d4594_1320944 = 0
	dword_5d4594_1320948 = 0
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 2)))) == 1 {
		v3 = *(**byte)(unsafe.Pointer(&dword_5d4594_1320932))
		if dword_5d4594_1320932 != 0 {
			result = (*byte)(unsafe.Pointer(uintptr(sub_4C18E0(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 3)))), *(**uint32)(unsafe.Pointer(&dword_5d4594_1320932))))))
			if result != nil {
				goto LABEL_12
			}
			result = sub_4C1910(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 3)))))
		} else {
			result = sub_4C1910(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 3)))))
		}
	} else {
		v3 = *(**byte)(unsafe.Pointer(&dword_5d4594_1320936))
		if dword_5d4594_1320936 != 0 {
			result = (*byte)(unsafe.Pointer(uintptr(sub_4C18E0(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 3)))), *(**uint32)(unsafe.Pointer(&dword_5d4594_1320936))))))
			if result != nil {
				goto LABEL_12
			}
			result = sub_4C19C0(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 3)))))
		} else {
			result = sub_4C19C0(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 3)))))
		}
	}
	v3 = result
LABEL_12:
	if v3 != nil {
		if *(*uint32)(unsafe.Pointer(v3)) == 0 {
			v4 = &nox_new_drawable_for_thing(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 3))))).field_0
			*(*uint32)(unsafe.Pointer(v3)) = uint32(uintptr(unsafe.Pointer(v4)))
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*28))&0x13001000 != 0 {
				v5 = int32(-11 - a1)
				v6 = (*int32)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*108))))
				v7 = (*uint8)(unsafe.Pointer(uintptr(a1 + 11)))
				v10 = int32(-11 - a1)
				for {
					if int32(*v7) == -1 {
						*v6 = 0
					} else {
						v8 = int32(uintptr(nox_xxx_modifGetDescById_413330(int32(*v7))))
						v5 = v10
						*v6 = v8
					}
					v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 1))
					v6 = (*int32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
					if int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v7), v5))))) >= 4 {
						break
					}
				}
			}
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1))) = 0
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*34))) = 0
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1)))*4+8)) = uint32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 5))))
		v9 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*34))))
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1)))++
		result = (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 7))) + uint32(v9))))
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*34))) = uint32(uintptr(unsafe.Pointer(result)))
		dword_5d4594_1320932 = 0
		dword_5d4594_1320936 = 0
	}
	return result
}
func sub_4C18E0(a1 int32, a2 *uint32) int32 {
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*1)) == 0 {
		return 1
	}
	if *(*uint32)(unsafe.Pointer(uintptr(*a2 + 108))) != uint32(a1) || *(*uint32)(unsafe.Pointer(uintptr(*a2 + 112)))&0x13001000 != 0 {
		return 0
	}
	return 1
}
func sub_4C1910(a1 int32) *byte {
	var (
		v1 int32
		v2 *uint8
		v3 int32
		v4 *uint8
		v5 int32
		v6 int32
		v7 *uint8
		v8 int32
		v9 *uint8
	)
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1319284))
	for 2 != 0 {
		v3 = 0
		v4 = v2
		for {
			v5 = int32(*(*uint32)(unsafe.Pointer(v4)))
			if *(*uint32)(unsafe.Pointer(v4)) != 0 && *(*uint32)(unsafe.Pointer(uintptr(v5 + 108))) == uint32(a1) && (*(*uint32)(unsafe.Pointer(uintptr(v5 + 112)))&0x13001000) == 0 {
				return (*byte)(memmap.PtrOff(0x5D4594, uintptr((v1+v3*2)*140)+1319284))
			}
			v3++
			v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 280))
			if v3 >= 2 {
				break
			}
		}
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 140))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) < int32(uintptr(memmap.PtrOff(0x5D4594, 1319564))) {
			continue
		}
		break
	}
	v6 = 0
	v7 = (*uint8)(memmap.PtrOff(0x5D4594, 1319284))
	for 2 != 0 {
		v8 = 0
		v9 = v7
		for {
			if *(*uint32)(unsafe.Pointer(v9)) == 0 {
				return (*byte)(memmap.PtrOff(0x5D4594, uintptr((v6+v8*2)*140)+1319284))
			}
			v8++
			v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 280))
			if v8 >= 2 {
				break
			}
		}
		v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 140))
		v6++
		if int32(uintptr(unsafe.Pointer(v7))) < int32(uintptr(memmap.PtrOff(0x5D4594, 1319564))) {
			continue
		}
		break
	}
	return nil
}
func sub_4C19C0(a1 int32) *byte {
	var (
		v1 int32
		v2 *uint8
		v3 int32
		v4 *uint8
		v5 int32
		v6 int32
		v7 *uint8
		v8 int32
		v9 *uint8
	)
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1320308))
	for 2 != 0 {
		v3 = 0
		v4 = v2
		for {
			v5 = int32(*(*uint32)(unsafe.Pointer(v4)))
			if *(*uint32)(unsafe.Pointer(v4)) != 0 && *(*uint32)(unsafe.Pointer(uintptr(v5 + 108))) == uint32(a1) && (*(*uint32)(unsafe.Pointer(uintptr(v5 + 112)))&0x13001000) == 0 {
				return (*byte)(memmap.PtrOff(0x5D4594, uintptr((v1+v3*2)*140)+1320308))
			}
			v3++
			v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 280))
			if v3 >= 2 {
				break
			}
		}
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 140))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) < int32(uintptr(memmap.PtrOff(0x5D4594, 1320588))) {
			continue
		}
		break
	}
	v6 = 0
	v7 = (*uint8)(memmap.PtrOff(0x5D4594, 1320308))
	for 2 != 0 {
		v8 = 0
		v9 = v7
		for {
			if *(*uint32)(unsafe.Pointer(v9)) == 0 {
				return (*byte)(memmap.PtrOff(0x5D4594, uintptr((v6+v8*2)*140)+1320308))
			}
			v8++
			v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 280))
			if v8 >= 2 {
				break
			}
		}
		v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 140))
		v6++
		if int32(uintptr(unsafe.Pointer(v7))) < int32(uintptr(memmap.PtrOff(0x5D4594, 1320588))) {
			continue
		}
		break
	}
	return nil
}
func sub_4C1B50(a1 int32) int32 {
	var result int32
	result = int32(dword_5d4594_1320964)
	if dword_5d4594_1320964 != 0 {
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1320240)), (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), *(*uint32)(unsafe.Pointer(uintptr(a1 + 2))))
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 6))) != 0 {
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1320868)), (*wchar2_t)(unsafe.Pointer(internCStr("(%d)"))), *(*uint32)(unsafe.Pointer(uintptr(a1 + 6))))
		} else {
			nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1320868)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1320984)))
		}
		result = nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1320100)), (*wchar2_t)(unsafe.Pointer(internCStr("%d"))), *(*uint32)(unsafe.Pointer(uintptr(a1 + 10))))
	}
	return result
}
func sub_4C1BC0(a1 int32) int32 {
	var (
		v1     uint32
		result int32
	)
	result = int32(dword_5d4594_1320964)
	if dword_5d4594_1320964 != 0 {
		result = a1
		dword_5d4594_1320944 = uint32(int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 2)))) & 1)
		*((*uint8)(unsafe.Pointer(&v1))) = *(*uint8)(unsafe.Pointer(uintptr(a1 + 2)))
		dword_5d4594_1320948 = (v1 >> 1) & 1
	}
	return result
}
func nox_xxx_prepareP2PTrade_4C1BF0() int32 {
	var (
		result int32
		v1     int32
		v2     *uint32
		v3     *uint32
	)
	result = int32(dword_5d4594_1320964)
	v1 = int32(*memmap.PtrUint32(0x8531A0, 2576))
	if dword_5d4594_1320964 != 0 {
		if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
			sub_4C1410()
			v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3702)))
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), 16385, v1+4704, 0)
			v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3703)))
			result = nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), 16385, int32(uintptr(memmap.PtrOff(0x5D4594, 1319844))), 0)
		}
	}
	return result
}
func sub_4C1CA0(a1 int32) int32 {
	var result int32
	*memmap.PtrUint32(0x587000, 184448) = uint32(a1)
	if a1 == 3 {
		nox_xxx_wndSetIcon_46AE60(*(*int32)(unsafe.Pointer(&dword_5d4594_1321040)), *memmap.PtrInt32(0x5D4594, 1321020))
		sub_46AEC0(*(*int32)(unsafe.Pointer(&dword_5d4594_1321040)), *memmap.PtrInt32(0x5D4594, 1321016))
		result = nox_xxx_wndSetIconLit_46AEA0(*(*int32)(unsafe.Pointer(&dword_5d4594_1321040)), *memmap.PtrInt32(0x5D4594, 1321016))
	} else if a1 == 4 {
		nox_xxx_wndSetIcon_46AE60(*(*int32)(unsafe.Pointer(&dword_5d4594_1321040)), *memmap.PtrInt32(0x5D4594, 1321028))
		sub_46AEC0(*(*int32)(unsafe.Pointer(&dword_5d4594_1321040)), *(*int32)(unsafe.Pointer(&dword_5d4594_1321024)))
		result = nox_xxx_wndSetIconLit_46AEA0(*(*int32)(unsafe.Pointer(&dword_5d4594_1321040)), *(*int32)(unsafe.Pointer(&dword_5d4594_1321024)))
	} else {
		result = a1 - 5
		if a1 == 5 {
			nox_xxx_wndSetIcon_46AE60(*(*int32)(unsafe.Pointer(&dword_5d4594_1321040)), *memmap.PtrInt32(0x5D4594, 1321012))
			sub_46AEC0(*(*int32)(unsafe.Pointer(&dword_5d4594_1321040)), *memmap.PtrInt32(0x5D4594, 1321008))
			result = nox_xxx_wndSetIconLit_46AEA0(*(*int32)(unsafe.Pointer(&dword_5d4594_1321040)), *memmap.PtrInt32(0x5D4594, 1321008))
		}
	}
	return result
}
func nox_xxx_guiDrawSummonBox_4C1FE0(a1 *uint32) int32 {
	var (
		v2   *uint8
		v3   int32
		v4   int32
		v5   int32
		v6   int32
		v7   int32
		v8   int32
		v9   int32
		v10  int32
		v11  int32
		v13  int32
		v14  *int32
		v15  *uint32
		v17  int32
		v18  int32
		v19  int8
		v20  int32
		v21  int32
		v22  int32 = 0
		v23  int32 = 0
		a1a  int2
		v26  int32
		v27  int32
		v28  int32
		v29  int32
		mpos nox_point = nox_client_getMousePos_4309F0()
		v24  nox_point = mpos
	)
	if int32(*memmap.PtrUint8(0x5D4594, 1321200)) == 1 {
		dword_5d4594_1320992 += 20
		if dword_5d4594_1320992 >= uint32(*memmap.PtrInt32(0x5D4594, 1321004)) {
			dword_5d4594_1320992 = *memmap.PtrUint32(0x5D4594, 1321004)
			*memmap.PtrUint8(0x5D4594, 1321200) = 2
		}
	} else if int32(*memmap.PtrUint8(0x5D4594, 1321200)) == 3 {
		dword_5d4594_1320992 -= 20
		if dword_5d4594_1320992 <= uint32(*memmap.PtrInt32(0x5D4594, 1321000)) {
			dword_5d4594_1320992 = *memmap.PtrUint32(0x5D4594, 1321000)
			*memmap.PtrUint8(0x5D4594, 1321200) = 0
			nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321032))))), 1)
			nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321040))))), 1)
		}
	}
	nox_window_setPos_46A9B0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321032)))), *(*int32)(unsafe.Pointer(&dword_5d4594_1320988)), *(*int32)(unsafe.Pointer(&dword_5d4594_1320992)))
	nox_window_setPos_46A9B0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321040)))), int32(dword_5d4594_1320988+27), int32(dword_5d4594_1320992+12))
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(a1)), (*uint32)(unsafe.Pointer(&v28)), (*uint32)(unsafe.Pointer(&v29)))
	nox_window_get_size((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), &v21, &v20)
	nox_xxx_guiFontHeightMB_43F320(nil)
	if *memmap.PtrUint32(0x5D4594, 1320996) != 0 {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1320996)))), *(*int32)(unsafe.Pointer(&dword_5d4594_1320988)), *(*int32)(unsafe.Pointer(&dword_5d4594_1320992)))
	}
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1321064))
	for {
		if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), -int(4*1)))) != 0 {
			switch *(*uint8)(unsafe.Add(unsafe.Pointer(v2), 8)) {
			case 1:
				v22 = 1
				v23 = 1
			case 2:
				v22 = 1
				v23 = 2
			case 4:
				v22 = 2
				v23 = 2
			}
			v3 = int32(uint32(v28) + *(*uint32)(unsafe.Pointer(v2))*38 + 2)
			v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*1))))
			a1a.field_0 = int32(uint32(v28) + *(*uint32)(unsafe.Pointer(v2))*38 + 2)
			v5 = v29 + v4*38 + 2
			v21 = v22*38 - 4
			v20 = v23*38 - 4
			if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*4))) != 0 {
				nox_client_drawSetColor_434460(int32(nox_color_yellow_2589772))
				v18 = v20
				v17 = v21
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*4))) = 0
				nox_client_drawRectFilledOpaque_49CE30(v3, v5, v17, v18)
			} else {
				v6 = nox_xxx_guiDrawSummon_4C2440(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), -int(4*2))))))
				if v6 != 0 {
					nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(v6))), v3, v5)
				} else {
					v7 = v3 + v21/2
					v8 = v5 + v20/2
					nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 956))
					nox_client_drawPoint_4B0BC0(v7, v8, 9)
					nox_video_drawCircleColored_4C3270(v7, v8, 9, *memmap.PtrInt32(0x852978, 4))
					v3 = a1a.field_0
				}
			}
			if sub_495180(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), -int(4*3))))), (*uint16)(unsafe.Pointer(&v27)), (*uint16)(unsafe.Pointer(&v26)), (*uint8)(unsafe.Pointer(&v19))) != 0 {
				if int32(uint16(int16(v26))) != 0 {
					v9 = v20 * int32(uint16(int16(v27))) / int32(uint16(int16(v26)))
				} else {
					v9 = 0
				}
				if int32(v19) != 0 {
					nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 984))
				} else {
					nox_client_drawSetColor_434460(int32(nox_color_violet_2598268))
				}
				nox_client_drawRectFilledOpaque_49CE30(v21+v3-2, v5, 2, v20)
				if int32(v19) != 0 {
					nox_client_drawSetColor_434460(*memmap.PtrInt32(0x8531A0, 2572))
				} else {
					nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 940))
				}
				nox_client_drawRectFilledOpaque_49CE30(v21+v3-2, v20+v5-v9, 2, v9)
			}
			mpos = v24
		}
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 32))
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321192))) {
			break
		}
	}
	v10 = bool2int32(nox_xxx_wndPointInWnd_46AAB0(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321040)), mpos.x, mpos.y))
	if nox_xxx_wndPointInWnd_46AAB0(a1, mpos.x, mpos.y) || v10 != 0 || *memmap.PtrUint32(0x5D4594, 1321212) == 1 {
		v11 = mpos.y
		a1a.field_0 = (mpos.x - v28) / 38
		a1a.field_4 = (v11 - v29) / 38
		v13 = nox_xxx_wndSummonGet_4C2410(&a1a)
		*memmap.PtrUint32(0x5D4594, 1321212) = 0
		v14 = (*int32)(unsafe.Pointer(sub_4C2D60()))
		if v14 != nil {
			for {
				v15 = &nox_xxx_netSpriteByCodeDynamic_45A6F0(*v14).field_0
				if v15 != nil {
					if v14 == (*int32)(unsafe.Pointer(uintptr(v13))) || v10 != 0 {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*30)) |= 0x40000000
						*memmap.PtrUint32(0x5D4594, 1321212) = 1
					} else {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*30)) &= 0xBFFFFFFF
					}
				}
				v14 = (*int32)(unsafe.Pointer(sub_4C2D90(int32(uintptr(unsafe.Pointer(v14))))))
				if v14 == nil {
					break
				}
			}
			mpos = v24
		}
	}
	if dword_5d4594_1321044 != 0 && !nox_xxx_wndPointInWnd_46AAB0(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321044)), mpos.x, mpos.y) {
		nox_xxx_guiHideSummonWindow_4C2470()
	}
	return 1
}
func nox_xxx_wndSummonGet_4C2410(a1 *int2) int32 {
	var (
		result int32
		v2     int32
		v3     int32
	)
	result = 0
	if a1 != nil {
		v2 = a1.field_0
		if a1.field_0 >= 0 && v2 < 2 {
			v3 = a1.field_4
			if v3 >= 0 && v3 < 2 {
				result = int32(*memmap.PtrUint32(0x5D4594, uintptr((v3+v2*2)*4)+1321180))
			}
		}
	}
	return result
}
func nox_xxx_guiDrawSummon_4C2440(a1 int32) int32 {
	var (
		v1 *byte
		v2 int32
	)
	v1 = nox_get_thing_name(a1)
	if v1 == nil {
		return 0
	}
	v2 = nox_xxx_guide_427010(v1)
	return sub_427430(v2)
}
func nox_xxx_guiHideSummonWindow_4C2470() int32 {
	var result int32
	nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321044)))))
	dword_5d4594_1321044 = 0
	dword_5d4594_1321204 = 0
	nox_xxx_clientPlaySoundSpecial_452D80(920, 100)
	result = int32(dword_5d4594_1321040)
	*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1321040 + 36))) &= 0xFFFFFFFD
	return result
}
func sub_4C24A0() int32 {
	return 1
}
func nox_xxx_wndSummonBigButtonProc_4C24B0(a1 int32, a2 int32, a3 uint32) int32 {
	var a1a int2
	switch a2 {
	case 5, 6:
		return 1
	case 7:
		dword_5d4594_1321204 = 0
		a1a.field_4 = int32(a3 >> 16)
		a1a.field_0 = int32(uint16(a3))
		nox_xxx_wndSummonCreateList_4C2560(&a1a)
		*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1321040 + 36))) |= 2
		return 1
	case 17:
		*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1321040 + 36))) |= 2
		return 0
	case 18:
		*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1321040 + 36))) &= 0xFFFFFFFD
		return 0
	default:
		return 0
	}
}
func sub_4C2A00(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int16) int32 {
	var v5 *uint8
	nox_xxx_drawSetTextColor_434390(a4)
	v5 = (*uint8)(memmap.PtrOff(0x587000, 184520))
	for {
		nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer(a5)), int32(uint32(a1)+*(*uint32)(unsafe.Pointer(v5))), int32(uint32(a2)+*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*1)))))
		v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 8))
		if int32(uintptr(unsafe.Pointer(v5))) >= int32(uintptr(memmap.PtrOff(0x587000, 184552))) {
			break
		}
	}
	nox_xxx_drawSetTextColor_434390(a3)
	return nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer(a5)), a1, a2)
}
func nox_client_orderCreature(creature int32, command int32) {
	var buf [4]uint8 = [4]uint8{}
	buf[0] = 0x78
	if creature != 0 {
		*(*uint16)(unsafe.Pointer(&buf[1])) = *(*uint16)(unsafe.Pointer(uintptr(creature)))
	} else {
		if command == 1 {
			return
		}
		*(*uint16)(unsafe.Pointer(&buf[1])) = 0
	}
	buf[3] = uint8(int8(command))
	nox_netlist_addToMsgListCli_40EBC0(31, 0, &buf[0], 4)
	nox_xxx_guiHideSummonWindow_4C2470()
	if command == 0 {
		nox_xxx_clientPlaySoundSpecial_452D80(777, 100)
	} else {
		nox_xxx_clientPlaySoundSpecial_452D80(898, 100)
	}
}
func nox_xxx_clientOrderCreature_4C2A60(a1 int32, a2 uint32) int32 {
	var result int32
	if a2 >= 5 {
		if a2 <= 6 {
			return 1
		}
		if a2 == 7 {
			*((*uint8)(unsafe.Pointer(&a2))) = 120
			result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 32))))
			if result == 2 || dword_5d4594_1321204 == 0 && result == 1 {
				return 1
			}
			nox_client_orderCreature(int32(dword_5d4594_1321204), int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 32)))))
			return 1
		}
	}
	return 0
}
func nox_xxx_wndSummonProc_4C2B10(a1 *uint32, a2 uint32, a3 uint32) int32 {
	var (
		v5  int2
		a1a int2
	)
	if a2 >= 5 {
		if a2 <= 6 {
			return 1
		}
		if a2 == 7 {
			v5.field_4 = int32(a3 >> 16)
			v5.field_0 = int32(uint16(a3))
			nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(a1)), &a2, &a3)
			a1a.field_0 = (v5.field_0 - int32(a2)) / 38
			a1a.field_4 = (v5.field_4 - int32(a3)) / 38
			dword_5d4594_1321204 = uint32(nox_xxx_wndSummonGet_4C2410(&a1a))
			if dword_5d4594_1321204 != 0 {
				nox_xxx_wndSummonCreateList_4C2560(&v5)
			}
			return 1
		}
	}
	return 0
}
func sub_4C2BD0() int32 {
	return 0
}
func sub_4C2BE0() int32 {
	return 1
}
func sub_4C2BF0() *int32 {
	var (
		v0     *int32
		result *int32
		v2     int32
	)
	v0 = mem_getI32Ptr(0x5D4594, 1321180)
	for {
		result = v0
		v2 = 2
		for {
			*result = 0
			result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*2))
			v2--
			if v2 == 0 {
				break
			}
		}
		v0 = (*int32)(unsafe.Add(unsafe.Pointer(v0), 4*1))
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321188))) {
			break
		}
	}
	return result
}
func sub_4C2C20(a1 *uint32, a2 int32, a3 uint32) int32 {
	var (
		v3  *wchar2_t
		a2a int2
	)
	a2a.field_4 = int32(a3 >> 16)
	a2a.field_0 = int32(uint16(a3))
	v3 = (*wchar2_t)(unsafe.Pointer(uintptr(sub_4C2C60(a1, &a2a))))
	nox_xxx_cursorSetTooltip_4776B0(v3)
	return 1
}
func sub_4C2C60(a1 *uint32, a2 *int2) int32 {
	var (
		v4     int32
		result int32
		v6     int32
		a1a    int2
	)
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(a1)), (*uint32)(unsafe.Pointer(&a1)), (*uint32)(unsafe.Pointer(&v6)))
	a1a.field_0 = (a2.field_0 - int32(uintptr(unsafe.Pointer(a1)))) / 38
	a1a.field_4 = (a2.field_4 - v6) / 38
	v4 = nox_xxx_wndSummonGet_4C2410(&a1a)
	if v4 != 0 {
		result = int32(uintptr(unsafe.Pointer(nox_get_thing_pretty_name(int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 4))))))))
	} else {
		result = 0
	}
	return result
}
func sub_4C2D60() *byte {
	var (
		v0 int32
		v1 *uint8
	)
	v0 = 0
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1321060))
	for *(*uint32)(unsafe.Pointer(v1)) == 0 {
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 32))
		v0++
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321188))) {
			return nil
		}
	}
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v0*32)+1321052))
}
func sub_4C2D90(a1 int32) *byte {
	var (
		v1 int32
		v2 *uint8
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 24))) + 1)
	if v1 >= 4 {
		return nil
	}
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v1*32)+1321060))
	for *(*uint32)(unsafe.Pointer(v2)) == 0 {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 32))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321188))) {
			return nil
		}
	}
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v1*32)+1321052))
}
func sub_4C2DD0(a1 int32) int32 {
	var v1 int32
	v1 = int32(dword_5d4594_1321208)
	if dword_5d4594_1321208 == 0 {
		v1 = nox_xxx_getNameId_4E3AA0(internCStr("CarnivorousPlant"))
		dword_5d4594_1321208 = uint32(v1)
	}
	return bool2int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 4))) != uint32(v1))
}
func sub_4C2E00() int32 {
	var v0 *byte
	if dword_5d4594_1321208 == 0 {
		dword_5d4594_1321208 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("CarnivorousPlant")))
	}
	v0 = sub_4C2D60()
	if v0 == nil {
		return 0
	}
	for sub_4C2DD0(int32(uintptr(unsafe.Pointer(v0)))) == 0 {
		v0 = sub_4C2D90(int32(uintptr(unsafe.Pointer(v0))))
		if v0 == nil {
			return 0
		}
	}
	return 1
}
func nox_xxx_cliSummonCreat_4C2E50(a1 int32, a2 int32, a3 int32) int8 {
	var v3 *byte
	v3 = sub_4C2D60()
	if v3 != nil {
		for *(*uint32)(unsafe.Pointer(v3)) != uint32(a1) || *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1))) != uint32(a2) {
			v3 = sub_4C2D90(int32(uintptr(unsafe.Pointer(v3))))
			if v3 == nil {
				goto LABEL_5
			}
		}
		return int8(uintptr(unsafe.Pointer(v3)))
	}
LABEL_5:
	v3 = sub_4C2F20()
	if v3 != nil {
		*(*uint32)(unsafe.Pointer(v3)) = uint32(a1)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1))) = uint32(a2)
		*(*byte)(unsafe.Add(unsafe.Pointer(v3), 20)) = byte(int8(sub_4C2EF0(a2)))
		sub_4C2F70()
		*((*uint8)(unsafe.Pointer(&v3))) = *memmap.PtrUint8(0x5D4594, 1321200)
		if int32(*memmap.PtrUint8(0x5D4594, 1321200)) == 0 || int32(*memmap.PtrUint8(0x5D4594, 1321200)) == 3 {
			if a3 == 0 {
				nox_xxx_clientPlaySoundSpecial_452D80(801, 100)
			}
			*memmap.PtrUint8(0x5D4594, 1321200) = 1
			nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321032))))), 0)
			*((*uint8)(unsafe.Pointer(&v3))) = uint8(int8(nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321040))))), 0)))
		}
		dword_5d4594_1321196++
	}
	return int8(uintptr(unsafe.Pointer(v3)))
}
func sub_4C2EF0(a1 int32) int32 {
	var (
		v1 int32
		v3 int32
	)
	v1 = int32(nox_get_thing(a1).sub_class)
	if v1&1 != 0 {
		return 1
	}
	v3 = -bool2int32((v1 & 2) != 0)
	*((*uint8)(unsafe.Pointer(&v3))) = uint8(int8(v3 & 0xFE))
	return v3 + 4
}
func sub_4C2F20() *byte {
	var (
		v0     int32
		v1     *uint8
		result *byte
	)
	v0 = 0
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1321060))
	for *(*uint32)(unsafe.Pointer(v1)) != 0 {
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 32))
		v0++
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321188))) {
			return nil
		}
	}
	libc.MemSet(memmap.PtrOff(0x5D4594, uintptr(v0*32)+1321052), 0, 0x20)
	*memmap.PtrUint32(0x5D4594, uintptr(v0*32)+1321060) = 1
	result = (*byte)(memmap.PtrOff(0x5D4594, uintptr(v0*32)+1321052))
	*memmap.PtrUint32(0x5D4594, uintptr(v0*32)+1321076) = uint32(v0)
	return result
}
func sub_4C2F70() *byte {
	var (
		i      int32
		result *byte
		j      *byte
	)
	sub_4C2BF0()
	for i = 1; ; i = 4 {
		for {
			result = sub_4C2D60()
			for j = result; result != nil; j = result {
				if int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(j), 20)))) == i {
					sub_4C2FD0(int32(uintptr(unsafe.Pointer(j))))
				}
				result = sub_4C2D90(int32(uintptr(unsafe.Pointer(j))))
			}
			if i != 1 {
				break
			}
			i = 2
		}
		if i != 2 {
			break
		}
	}
	return result
}
func sub_4C2FD0(a1 int32) int32 {
	var (
		v1     int32
		v2     *int32
		v3     int32
		result int32
	)
	v1 = 0
	v2 = (*int32)(unsafe.Pointer(uintptr(a1 + 12)))
	for {
		v3 = int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 20))))
		*v2 = int32(*memmap.PtrUint32(0x587000, uintptr(v1*8)+184456))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) = *memmap.PtrUint32(0x587000, uintptr(v1*8)+184460)
		if sub_4C30C0(v2, v3) != 0 {
			break
		}
		result = int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 20))))
		v1 += result
		if v1 >= 4 {
			return result
		}
	}
	return sub_4C3030((*int32)(unsafe.Pointer(uintptr(a1+12))), int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 20)))), a1)
}
func sub_4C3030(a1 *int32, a2 int32, a3 int32) int32 {
	var (
		v3     int32
		result int32
		v5     int32
		v6     int32
		v7     *uint8
	)
	if a2 == 1 {
		v3 = 1
		a2 = 1
	} else if a2 == 2 {
		v3 = 1
		a2 = 2
	} else {
		v3 = 2
		if a2 == 4 {
			a2 = 2
		} else {
			v3 = a2
		}
	}
	result = a2
	v5 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	if v5 < v5+a2 {
		for {
			v6 = *a1
			if *a1 < *a1+v3 {
				v7 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr((v5+v6*2)*4)+1321180))
				for {
					*(*uint32)(unsafe.Pointer(v7)) = uint32(a3)
					v6++
					v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 8))
					if v6 >= v3+*a1 {
						break
					}
				}
			}
			v5++
			result = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) + a2
			if v5 >= result {
				break
			}
		}
	}
	return result
}
func sub_4C30C0(a1 *int32, a2 int32) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 int32
		v8 int32
		v9 *uint8
	)
	switch a2 {
	case 1:
		v2 = 1
		v3 = 1
	case 2:
		v2 = 1
		v3 = 2
	case 4:
		v2 = 2
		v3 = 2
	default:
		v2 = a2
		v3 = a2
	}
	v4 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	v5 = v4 + v3
	if v4 >= v4+v3 {
		return 1
	}
	v6 = *a1
	v7 = *a1 + v2
	for {
		v8 = *a1
		if v6 < v7 {
			v9 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr((v4+v6*2)*4)+1321180))
			for *(*uint32)(unsafe.Pointer(v9)) == 0 {
				v8++
				v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 8))
				if v8 >= v7 {
					goto LABEL_14
				}
			}
			return 0
		}
	LABEL_14:
		if func() int32 {
			p := &v4
			*p++
			return *p
		}() >= v5 {
			return 1
		}
	}
}
func nox_xxx_cliSummonOnDieOrBanish_4C3140(a1 int32, a2 unsafe.Pointer) {
	var (
		result *int32
		v3     *int32
		v4     *uint32
	)
	result = (*int32)(unsafe.Pointer(sub_4C31D0(a1)))
	v3 = result
	if result == nil {
		return
	}
	if result == *(**int32)(unsafe.Pointer(&dword_5d4594_1321204)) {
		nox_xxx_guiHideSummonWindow_4C2470()
	}
	v4 = &nox_xxx_netSpriteByCodeDynamic_45A6F0(a1).field_0
	if v4 != nil {
		*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*30)) &= 0xBFFFFFFF
	}
	sub_4C3030((*int32)(unsafe.Add(unsafe.Pointer(v3), 4*3)), int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v3))), 20)))), 0)
	sub_4C3210(int32(uintptr(unsafe.Pointer(v3))))
	sub_4C2F70()
	dword_5d4594_1321196--
	if dword_5d4594_1321196 == 0 {
		if a2 == nil {
			nox_xxx_clientPlaySoundSpecial_452D80(802, 100)
		}
		*memmap.PtrUint8(0x5D4594, 1321200) = 3
	}
}
func sub_4C31D0(a1 int32) *byte {
	var (
		v1 int32
		v2 *uint8
	)
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1321052))
	for *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*2))) == 0 || *(*uint32)(unsafe.Pointer(v2)) != uint32(a1) {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 32))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321180))) {
			return nil
		}
	}
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v1*32)+1321052))
}
func sub_4C3210(a1 int32) int32 {
	var result int32
	result = a1
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))) = 0
	return result
}
func nox_xxx_sprite_4C3220(a1 *nox_drawable) int32 {
	return bool2int32(sub_4C31D0(int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(a1))) + 128))))) != nil)
}
func sub_4C3260() int32 {
	return bool2int32(sub_4C2D60() != nil)
}
func nox_xxx_spriteDrawCircleMB_4C32A0(a1 int32, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4 *uint8
		v5 int32
		v6 int32
		v8 int32
		v9 int32
	)
	v8 = int32((uint32(a3) * *memmap.PtrUint32(0x587000, 192088)) >> 4)
	v9 = int32((uint32(a3) * *memmap.PtrUint32(0x587000, 192092)) >> 4)
	nox_client_drawSetColor_434460(a4)
	nox_client_drawEnableAlpha_434560(1)
	v4 = (*uint8)(memmap.PtrOff(0x587000, 192220))
	for {
		v5 = int32((uint32(a3) * *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), -int(4*1))))) >> 4)
		v6 = int32((*(*uint32)(unsafe.Pointer(v4)) * uint32(a3)) >> 4)
		nox_client_drawAddPoint_49F500(a1+v8, a2+v9)
		nox_client_drawAddPoint_49F500(v5+a1, v6+a2)
		nox_client_drawLineFromPoints_49E4B0()
		v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 128))
		v8 = v5
		v9 = v6
		if int32(uintptr(unsafe.Pointer(v4))) >= int32(uintptr(memmap.PtrOff(0x587000, 194140))) {
			break
		}
	}
	nox_client_drawAddPoint_49F500(int32(uint32(a1)+((uint32(a3)**memmap.PtrUint32(0x587000, 192088))>>4)), int32(uint32(a2)+((uint32(a3)**memmap.PtrUint32(0x587000, 192092))>>4)))
	nox_client_drawAddPoint_49F500(a1+v5, a2+v6)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawEnableAlpha_434560(0)
	return 1
}
func sub_4C3390() int32 {
	*memmap.PtrUint32(0x5D4594, 1321220) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("VoteInProgress")))))
	dword_5d4594_1321216 = uint32(uintptr(unsafe.Pointer(nox_window_new(nil, 136, nox_win_width-50, nox_win_height/2-100, 50, 50, nil))))
	nox_xxx_wndSetIcon_46AE60(*(*int32)(unsafe.Pointer(&dword_5d4594_1321216)), *memmap.PtrInt32(0x5D4594, 1321220))
	nox_window_set_all_funcs((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321216)))), nil, func(arg1 *nox_window, arg2 unsafe.Pointer) int32 {
		return sub_4C3410(&arg1.id)
	}, nil)
	nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321216))))), 1)
	return 1
}
func sub_4C3410(a1 *int32) int32 {
	var (
		v1 *int32
		v2 int32
		v4 int32
	)
	v1 = a1
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(a1)), (*uint32)(unsafe.Pointer(&a1)), (*uint32)(unsafe.Pointer(&v4)))
	v2 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*25))
	a1 = (*int32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(a1))), *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*24))))))
	nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*15))))), int32(uintptr(unsafe.Pointer(a1))), v2+v4)
	return 1
}
func sub_4C3460(a1 int32) int32 {
	return nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321216))))), a1)
}
func sub_4C34A0() int32 {
	var result int32
	result = nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321216)))))
	dword_5d4594_1321216 = 0
	return result
}
func sub_4C3500() int32 {
	var v0 *uint32
	v0 = (*uint32)(unsafe.Pointer(nox_new_window_from_file(internCStr("yesno.wnd"), nil)))
	dword_5d4594_1321224 = uint32(uintptr(unsafe.Pointer(v0)))
	if v0 != nil {
		nox_window_setPos_46A9B0((*nox_window)(unsafe.Pointer(v0)), (nox_win_width-320)/2, (nox_win_height-240)/2)
		v0 = *(**uint32)(unsafe.Pointer(&dword_5d4594_1321224))
	}
	nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v0)))))), 1)
	return int32(dword_5d4594_1321224)
}
func sub_4C35B0(a1 int32) int32 {
	if wndIsShown_nox_xxx_wndIsShown_46ACC0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321228)))))) != 0 {
		return 0
	}
	sub_413A00(0)
	if a1 != 0 {
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321228))))), 1)
	} else {
		sub_4C3620()
		nox_common_writecfgfile(internCStr("nox.cfg"))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321228))))), 1)
		sub_472280()
		sub_4ADA40()
	}
	return 1
}
func sub_4C3A60(a1 *uint32, a2 uint32, a3 uint32, a4 int32) int32 {
	if a2 < 0x13 || a2 > 0x14 {
		return nox_xxx_wndListboxProcWithoutData10_4A28E0(a1, int32(a2), a3, a4)
	} else {
		return 0
	}
}
func sub_4C3EB0(a1 int32, a2 int32, a3 uint32, a4 int32) int32 {
	switch a2 {
	case 6, 7:
		sub_4C4100(0x10000)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))), 1)
		return 1
	case 10, 11:
		sub_4C4100(0x10002)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))), 1)
		return 1
	case 14, 15:
		sub_4C4100(0x10001)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))), 1)
		return 1
	case 19:
		sub_4C4100(0x10003)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))), 1)
		return 1
	case 20:
		sub_4C4100(0x10004)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))), 1)
		return 1
	case 21:
		if a3 == 1 {
			if a4 == 2 {
				nox_xxx_windowFocus_46B500(nil)
				nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))))
				nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))), 1)
				if dword_5d4594_1321252 != 0 {
					nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321252))))), 16403, -1, 0)
				}
			}
			return 1
		} else if a4 == 1 && sub_4C3FC0(a3) != 0 {
			sub_4C4100(0x10000)
			nox_xxx_windowFocus_46B500(nil)
			nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))))
			nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))), 1)
			return 1
		} else {
			return 0
		}
	default:
		return 0
	}
}
func sub_4C3FC0(a1 uint32) int32 {
	var v6 *wchar2_t = nox_xxx_keybind_titleByKeyZero_42EA00(a1)
	if v6 == nil {
		return 0
	}
	if dword_5d4594_1321252 == 0 {
		return 1
	}
	var v7 int32 = 0
	var v8 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1321244))) + 32))))
	if int32(*(*uint16)(unsafe.Pointer(uintptr(v8 + 44)))) > 0 {
		for {
			{
				var v9 *wchar2_t = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321244))))), 16406, v7, 0))))
				if nox_wcscmp(v9, v6) == 0 {
					nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321244))))), 16407, int32(uintptr(memmap.PtrOff(0x587000, 185444))), v7)
				}
				v7++
			}
			if v7 >= int32(*(*int16)(unsafe.Pointer(uintptr(v8 + 44)))) {
				break
			}
		}
	}
	var v10 int32 = 0
	var v11 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1321248))) + 32))))
	if int32(*(*uint16)(unsafe.Pointer(uintptr(v11 + 44)))) > 0 {
		for {
			{
				var v12 *wchar2_t = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321248))))), 16406, v10, 0))))
				if nox_wcscmp(v12, v6) == 0 {
					nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321248))))), 16407, int32(uintptr(memmap.PtrOff(0x587000, 185448))), v10)
				}
				v10++
			}
			if v10 >= int32(*(*int16)(unsafe.Pointer(uintptr(v11 + 44)))) {
				break
			}
		}
	}
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321252))))), 16407, int32(uintptr(unsafe.Pointer(v6))), int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1321252 + 32))) + 48)))))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321252))))), 16403, -1, 0)
	dword_5d4594_1321252 = 0
	return 1
}
func sub_4C4100(a1 uint32) int32 {
	var (
		v1 *byte
		v2 int32
		v3 int32
		v4 *wchar2_t
		v5 int32
		v6 int32
		v7 *wchar2_t
	)
	v1 = (*byte)(unsafe.Pointer(nox_xxx_keybind_titleByKey_42EA00(a1)))
	if dword_5d4594_1321252 == 0 {
		return 1
	}
	v2 = 0
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1321244))) + 32))))
	if int32(*(*uint16)(unsafe.Pointer(uintptr(v3 + 44)))) > 0 {
		for {
			v4 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321244))))), 16406, v2, 0))))
			if nox_wcscmp(v4, (*wchar2_t)(unsafe.Pointer(v1))) == 0 {
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321244))))), 16407, int32(uintptr(memmap.PtrOff(0x587000, 185452))), v2)
			}
			v2++
			if v2 >= int32(*(*int16)(unsafe.Pointer(uintptr(v3 + 44)))) {
				break
			}
		}
	}
	v5 = 0
	v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1321248))) + 32))))
	if int32(*(*uint16)(unsafe.Pointer(uintptr(v6 + 44)))) > 0 {
		for {
			v7 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321248))))), 16406, v5, 0))))
			if nox_wcscmp(v7, (*wchar2_t)(unsafe.Pointer(v1))) == 0 {
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321248))))), 16407, int32(uintptr(memmap.PtrOff(0x587000, 185456))), v5)
			}
			v5++
			if v5 >= int32(*(*int16)(unsafe.Pointer(uintptr(v6 + 44)))) {
				break
			}
		}
	}
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321252))))), 16407, int32(uintptr(unsafe.Pointer(v1))), int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1321252 + 32))) + 48)))))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321252))))), 16403, -1, 0)
	dword_5d4594_1321252 = 0
	return 1
}
func sub_4C4220() int32 {
	var result int32
	nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))))
	nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321232)))))
	result = 0
	dword_5d4594_1321228 = 0
	dword_5d4594_1321232 = 0
	dword_5d4594_1321236 = nil
	dword_5d4594_1321240 = nil
	dword_5d4594_1321244 = nil
	dword_5d4594_1321248 = nil
	return result
}
func sub_4C4260() {
	sub_4C3B70()
	nox_xxx_wndShowModalMB_46A8C0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321228))))))
	sub_413A00(1)
}
func sub_4C4280() int32 {
	return bool2int32(wndIsShown_nox_xxx_wndIsShown_46ACC0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321228)))))) == 0)
}
func nox_xxx_drawObject_4C4770_draw(a1 *int32, dr *nox_drawable, a3 int32) {
	var (
		a2   *uint8 = (*uint8)(unsafe.Pointer(dr))
		v3   *uint8
		v4   *byte
		v5   *uint32
		v6   *uint32
		v7   int32
		v8   int32
		v9   int32
		v10  int32
		v11  int32
		v12  int32
		v13  int32
		v14  int32
		v15  int32
		v16  int32
		v17  int32
		v18  uint8
		v19  uint8
		v20  int32
		v21  int32
		v22  int32
		v23  int32
		v24  int32
		v25  int32
		v26  int32
		v27  int32
		v28  *uint8
		v29  int16
		v30  int32
		v31  int32
		v32  int32
		v33  int32
		v34  int32
		v35  int32
		v36  float64
		v37  float64
		v38  uint8
		v39  uint8
		v40  int32
		v41  int32
		v42  int32
		v43  int32
		v44  int32
		v45  int32
		v46  int32
		v47  int32
		v48  int32
		v49  int32
		v50  int32
		v53  int32
		v54  int32
		a1a  int2
		a2a  int2
		a4   int32
		a3a  int32
		v59a int32
		v59b int32
		v60  int64
		v61  uint8
		v62  uint8
		v63  uint8
		v64  uint8
	)
	v53 = 0
	v54 = 0
	if dword_5d4594_1321520 == 0 {
		dword_5d4594_1321520 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Ghost")))
	}
	v3 = a2
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 112)))&4 != 0 {
		v4 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*32)))))))
		if nox_player_netCode_85319C == *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*32))) {
			if v4 != nil && *(*byte)(unsafe.Add(unsafe.Pointer(v4), 3680))&1 != 0 {
				v54 = 1
			}
		} else if v4 != nil && *(*byte)(unsafe.Add(unsafe.Pointer(v4), 3680))&1 != 0 {
			return
		}
		v5 = nox_xxx_objGetTeamByNetCode_418C80(int32(nox_player_netCode_85319C))
		if v5 != nil {
			v6 = nox_xxx_objGetTeamByNetCode_418C80(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*32)))))
			if v6 != nil {
				if nox_player_netCode_85319C == *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*32))) || nox_xxx_servCompareTeams_419150(int32(uintptr(unsafe.Pointer(v5))), int32(uintptr(unsafe.Pointer(v6)))) != 0 {
					v53 = 1
				}
			}
		}
	}
	v7 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*3))))
	a3a = 0
	v8 = *a1
	v9 = v7 - *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
	v10 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	v11 = int32(*((*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(a2))), unsafe.Sizeof(int16(0))*53))))
	v59a = v9 + *a1 - int32(*a2)
	v12 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*4))))
	v13 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*4))) - uint32(v11) - uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 1))) - uint32(*((*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(a2))), unsafe.Sizeof(int16(0))*52)))))
	v14 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
	v59b = v10 + v13 - v14
	a4 = nox_win_width
	if *memmap.PtrUint32(0x587000, 80808) != 0 {
		v15 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*30))))
		if (uint32(v15)&0x40000000) == 0 && (v15&1) == 0 && (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 112)))&0x80) != 0 {
			v16 = v9 + v8
			a1a.field_0 = v16
			v17 = v10 + v12 - v14
			v18 = *(*uint8)(unsafe.Add(unsafe.Pointer(a2), 299))
			v19 = *(*uint8)(unsafe.Add(unsafe.Pointer(a2), 299))
			a1a.field_4 = v17
			v20 = int32(v19) * 8
			v21 = v16 + *memmap.PtrInt32(0x587000, uintptr(v20)+196184)
			v22 = v17 + *memmap.PtrInt32(0x587000, uintptr(v20)+196188)
			a2a.field_0 = v21
			a2a.field_4 = v22
			if int32(v18) < 0x18 && int32(v18) != 0 && (int32(v18) < 8 || int32(v18) > 0x10) {
				v23 = (v21 + v16) >> 1
				v24 = (v22 + v17) >> 1
				if sub_4C5630(v23-5, v23-5, v24) != 0 {
					a1a.field_0 -= 2
					a2a.field_0 -= 2
				} else if sub_4C5630(v23+5, v23+5, v24) != 0 {
					a1a.field_0 += 2
					a2a.field_0 += 2
				}
			} else {
				v25 = (v22 + v17) >> 1
				v26 = (v21 + v16) >> 1
				if sub_4C5630(v26, v26, v25-5) != 0 {
					v27 = a2a.field_4 - 2
					a1a.field_4 -= 2
					a2a.field_4 = v27
				} else if sub_4C5630(v26, v26, v25+5) != 0 {
					v27 = a2a.field_4 + 2
					a1a.field_4 += 2
					a2a.field_4 = v27
				}
			}
			if sub_4C42A0(&a1a, &a2a, &a3a, &a4) == 0 {
				return
			}
		}
	}
	if (*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*28)))&0x80000) != 0 && (*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*30)))&0x1000000) != 0 || (*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*30)))&0x40000000) != 0 {
		v28 = (*uint8)(memmap.PtrOff(0x587000, 185472))
	} else {
		v28 = (*uint8)(unsafe.Pointer(sub_469920((*nox_point)(unsafe.Pointer((*int2)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(a2), 12)))))))))
	}
	v29 = int16(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(a2))), unsafe.Sizeof(uint16(0))*52))))
	var a2b int32 = 0
	if int32(v29) >= 0 {
		v30 = 0
	} else {
		if *memmap.PtrInt32(0x5D4594, 1321512) < 0 && a2 == *(**uint8)(memmap.PtrOff(0x5D4594, 1321516)) {
			a2b = 1
		}
		v30 = int32(-v29)
	}
	*memmap.PtrUint32(0x5D4594, 1321516) = uint32(uintptr(unsafe.Pointer(a2)))
	v31 = int32(*((*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(a2))), unsafe.Sizeof(int16(0))*52))))
	a1a.field_0 = v30
	*memmap.PtrUint32(0x5D4594, 1321512) = uint32(v31)
	if nox_client_drawable_testBuff_4356C0((*nox_drawable)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a2)))))), 25) {
		nox_xxx_draw_434600(1)
		nox_draw_setColorMultAndIntensity_433E40(int32(nox_color_blue_2650684))
	} else if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 112)))&2) != 0 && (func() uint32 {
		v32 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*30))))
		return uint32(v32) & 0x40000000
	}()) != 0 && (v32&0x8020) == 0 {
		nox_xxx_draw_434600(1)
		nox_draw_setColorMultAndIntensity_433E40(int32(nox_color_blue_2650684))
	} else {
		sub_4345F0(1)
		*((*uint8)(unsafe.Pointer(&v34))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v28), 8))
		v33 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v28), 4)))
		*((*uint8)(unsafe.Pointer(&v35))) = *v28
		nox_draw_setColorMultAndIntensityRGB_433CD0(uint8(int8(v35)), uint8(int8(v33)), uint8(int8(v34)))
	}
	if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*120))) != 0 {
		v60 = int64(gameFrame() - *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*85))))
		v36 = float64(v60)
		v60 = int64(gameFPS())
		v37 = 1.0 - v36/float64(int32(gameFPS()))
		if v37 < 0.0 {
			v37 = 0.001
		}
		v38 = uint8(int8(int64(v37 * 255.0)))
		v63 = uint8(int8(int64(v37 * 255.0)))
		if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*27))) == dword_5d4594_1321520 {
			v39 = uint8(sub_4C4EC0((*uint32)(unsafe.Pointer(a1)), int32(uintptr(unsafe.Pointer(v3)))))
			if int32(v39) < int32(v38) {
				v64 = v39
				nox_client_drawEnableAlpha_434560(1)
				nox_client_drawSetAlpha_434580(v64)
			} else {
				nox_client_drawEnableAlpha_434560(1)
				nox_client_drawSetAlpha_434580(v63)
			}
		} else {
			if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*30)))&0x4000000 != 0 {
				v63 = uint8(int8(int32(v38) >> 1))
			}
			nox_client_drawEnableAlpha_434560(1)
			nox_client_drawSetAlpha_434580(v63)
		}
	} else if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*27))) == dword_5d4594_1321520 {
		v61 = uint8(sub_4C4EC0((*uint32)(unsafe.Pointer(a1)), int32(uintptr(unsafe.Pointer(a2)))))
		nox_client_drawEnableAlpha_434560(1)
		nox_client_drawSetAlpha_434580(v61)
	} else if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a2))), 4*30)))&0x4000000 != 0 {
		nox_client_drawEnableAlpha_434560(1)
		nox_client_drawSetAlpha_434580(0x80)
	}
	if nox_client_drawable_testBuff_4356C0((*nox_drawable)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), 0) || v54 != 0 || *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*27))) == dword_5d4594_1321520 && *memmap.PtrUint32(0x852978, 8) != 0 && nox_client_drawable_testBuff_4356C0((*nox_drawable)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x852978, 8)))), 21) {
		if *memmap.PtrUint32(0x8531A0, 2576) != 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x8531A0, 2576) + 3680))))&1) != 0 {
			nox_client_drawEnableAlpha_434560(1)
			nox_client_drawSetAlpha_434580(0x80)
		} else {
			v40 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*8))))
			v41 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*9))))
			v42 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*3))) - uint32(v40))
			v43 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*4))) - uint32(v41))
			v44 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*3))) - uint32(v40))
			if v42 < 0 {
				v44 = int32(uint32(v40) - *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*3))))
			}
			if v44 < 4 {
				v45 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*4))) - uint32(v41))
				if v43 < 0 {
					v45 = int32(uint32(v41) - *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*4))))
				}
				if v45 < 4 {
					v46 = int32(*memmap.PtrUint32(0x852978, 8))
					if *memmap.PtrUint32(0x852978, 8) == 0 {
						goto LABEL_82
					}
					if !nox_client_drawable_testBuff_4356C0((*nox_drawable)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x852978, 8)))), 21) {
						*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v4))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v53))
						if v53 == 0 {
							return
						}
					}
				}
			}
			v46 = int32(*memmap.PtrUint32(0x852978, 8))
		LABEL_82:
			if v42 != 0 || v43 != 0 {
				v47 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*5))) - *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*10))))
				if v47 == 0 {
					v47 = 1
				}
				v48 = nox_double2int(math.Sqrt(float64(v42*v42+v43*v43))) / v47
				v30 = a1a.field_0
				v42 = v48
				v46 = int32(*memmap.PtrUint32(0x852978, 8))
			}
			if v46 == 0 {
				goto LABEL_123
			}
			if v54 != 0 {
				*((*uint8)(unsafe.Pointer(&v49))) = 128
				v62 = uint8(int8(v49))
				goto LABEL_B
			}
			if v53 == 0 && nox_client_drawable_testBuff_4356C0((*nox_drawable)(unsafe.Pointer(uintptr(v46))), 21) {
				nox_xxx_draw_434600(1)
				nox_draw_setColorMultAndIntensity_433E40(*memmap.PtrInt32(0x8531A0, 2572))
				v62 = math.MaxUint8
				nox_client_drawEnableAlpha_434560(1)
				nox_client_drawSetAlpha_434580(v62)
				goto LABEL_A
			}
		LABEL_123:
			if v42 < 8 {
				v49 = (v42 << 7) / 8
				v62 = uint8(int8(v49))
				if int32(uint8(int8(v49))) == 0 {
					*((*uint8)(unsafe.Pointer(&v49))) = 1
					v62 = uint8(int8(v49))
				}
			} else {
				*((*uint8)(unsafe.Pointer(&v49))) = 128
				v62 = uint8(int8(v49))
			}
		LABEL_B:
			if v53 != 0 && int32(uint8(int8(v49))) <= 1 {
				if (func() int32 {
					v50 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*28))))
					return v50 & 2
				}()) != 0 && *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*69))) == 8 || (v50&4) != 0 && *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*69))) == 0 {
					nox_xxx_draw_434600(1)
					nox_draw_setColorMultAndIntensity_433E40(*memmap.PtrInt32(0x8531A0, 2572))
					v62 = 128
				}
			}
			nox_client_drawEnableAlpha_434560(1)
			nox_client_drawSetAlpha_434580(v62)
		}
	}
LABEL_A:
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 112)))&4) == 0 && nox_client_drawable_testBuff_4356C0((*nox_drawable)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), 23) && !nox_common_gameFlags_check_40A5C0(2048) {
		nox_xxx_draw_434600(1)
		if int32(uint8(gameFrame()))&1 != 0 {
			nox_draw_setColorMultAndIntensity_433E40(int32(nox_color_white_2523948))
		} else {
			nox_draw_setColorMultAndIntensity_433E40(int32(nox_color_blue_2650684))
		}
	}
	if !nox_client_drawable_testBuff_4356C0((*nox_drawable)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), 23) && nox_client_drawable_testBuff_4356C0((*nox_drawable)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), 11) {
		nox_xxx_draw_434600(1)
		nox_draw_setColorMultAndIntensity_433E40(*memmap.PtrInt32(0x85B3FC, 956))
	}
	if a2b != 0 {
		nox_xxx_wndDraw_49F7F0()
		sub_49F7C0_def()
	} else {
		sub_47D370(v30)
	}
	nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(a3))), v59a, v59b)
	sub_4345F0(0)
	nox_client_drawEnableAlpha_434560(0)
	nox_xxx_draw_434600(0)
	if a2b != 0 {
		sub_49F860()
	}
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*1))) = 1
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v4))), unsafe.Sizeof(uint16(0))*0)) = *memmap.PtrUint16(0x973F18, 88)
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*2))) = *memmap.PtrUint16(0x973F18, 88)
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*3))) = *memmap.PtrUint16(0x973F18, 76)
	*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*2))) = uint32(a3)
}
func sub_4C4EC0(a1 *uint32, a2 int32) int8 {
	var (
		v3 int32
		v4 int32
		v5 int32
	)
	if *memmap.PtrUint32(0x852978, 8) != 0 && nox_client_drawable_testBuff_4356C0((*nox_drawable)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x852978, 8)))), 21) {
		return -1
	}
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 12))) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8))/2 - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9))/2 - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	v5 = int32(128 - uint32((v3*v3+v4*v4)<<7) / *memmap.PtrUint32(0x587000, 185464))
	if v5 < 0 {
		return 0
	}
	if v5 > 128 {
		*((*uint8)(unsafe.Pointer(&v5))) = 128
	}
	return int8(v5)
}
func nox_xxx_drawShinySpot_4C4F40(vp *nox_draw_viewport_t, dr *nox_drawable) int16 {
	var (
		a1 *uint32 = (*uint32)(unsafe.Pointer(vp))
		a2 int32   = int32(uintptr(unsafe.Pointer(dr)))
		v2 *byte
		v3 int32
		v4 int32
		v5 uint32
		v6 int32
	)
	v2 = *(**byte)(memmap.PtrOff(0x5D4594, 1321524))
	if *memmap.PtrUint32(0x5D4594, 1321524) == 0 {
		v2 = (*byte)(unsafe.Pointer(nox_xxx_gLoadAnim_42FA20(internCStr("ShinySpot"))))
		*memmap.PtrUint32(0x5D4594, 1321524) = uint32(uintptr(unsafe.Pointer(v2)))
	}
	v3 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*24))))
	v4 = int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 8))))
	v5 = (gameFrame() + *(*uint32)(unsafe.Pointer(uintptr(a2 + 128)))) / uint32(v4*8)
	v6 = int32(((gameFrame() + *(*uint32)(unsafe.Pointer(uintptr(a2 + 128)))) % uint32(v4*8)) >> 1)
	if v6 < v4 {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 4))) + uint32(v6*4))))))), int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 12)))-*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4))+*a1-64), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1))-uint32(*(*int16)(unsafe.Pointer(uintptr(a2 + 106))))-uint32(*(*int16)(unsafe.Pointer(uintptr(a2 + 104))))-*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5))+*(*uint32)(unsafe.Pointer(uintptr(a2 + 16)))-64))
	}
	return int16(uint16(v5))
}
func nox_xxx_colorInit_4C4FD0() int32 {
	var result int32
	*memmap.PtrUint32(0x5D4594, 1321536) = nox_color_rgb_4344A0(math.MaxUint8, 200, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1321796) = nox_color_rgb_4344A0(math.MaxUint8, 0, math.MaxUint8)
	result = int32(nox_color_rgb_4344A0(100, 40, 100))
	*memmap.PtrUint32(0x5D4594, 1321532) = uint32(result)
	return result
}
func sub_4C5020(a1 int32) int32 {
	var result int32
	result = int32(dword_5d4594_1321800)
	if *(*int32)(unsafe.Pointer(&dword_5d4594_1321800)) < 32 {
		result = int32(dword_5d4594_1321800 + 1)
		*memmap.PtrUint32(0x5D4594, uintptr(result*8)+1321532) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 1)))
		*memmap.PtrUint32(0x5D4594, uintptr(result*8)+1321536) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 5)))
		dword_5d4594_1321800 = uint32(result)
	}
	return result
}
func sub_4C5050() {
	dword_5d4594_1321800 = 0
}
func sub_4C5060(a1p *nox_draw_viewport_t) int32 {
	var (
		a1     *uint32 = (*uint32)(unsafe.Pointer(a1p))
		result int32
		v2     *uint16
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v10    int32
		a1a    int2
		v12    int2
		a2     int2
		v14    int2
	)
	result = int32(*memmap.PtrUint32(0x852978, 8))
	if *memmap.PtrUint32(0x852978, 8) != 0 {
		result = int32(dword_5d4594_1321800)
		v10 = 0
		if dword_5d4594_1321800 > 0 {
			v2 = mem_getU16Ptr(0x5D4594, 1321540)
			for {
				v3 = int32(*a1 + uint32(*v2) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
				v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) + uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*1))) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
				v5 = sub_4992B0(v3, v4)
				v6 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*3))) - int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*1)))
				if v3 <= 0 || uint32(v3) >= *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8))-1 || v4 <= 0 || uint32(v4) >= *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9))-1 {
					v5 = 0
				}
				v14.field_0 = v3 + int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*2))) - int32(*v2)
				v14.field_4 = v4 + v6
				v12.field_0 = v3
				v12.field_4 = v4
				v7 = sub_498C20(&v12, &v14, int32(uintptr(unsafe.Pointer(a1))))
				if v7 != 0 {
					v8 = 0
					for a1a = v12; v8 < v7; v5 = 1 - v5 {
						*(*uint64)(unsafe.Pointer(&a2)) = sub_499290(v8)
						if v5 != 0 {
							sub_4C51D0(&a1a, &a2)
						}
						a1a = a2
						v8++
					}
					if v5 != 0 {
						sub_4C51D0(&a1a, &v14)
					}
				} else if v5 != 0 {
					sub_4C51D0(&v12, &v14)
				}
				result = v10 + 1
				v2 = (*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*4))
				v10++
				if v10 >= *(*int32)(unsafe.Pointer(&dword_5d4594_1321800)) {
					break
				}
			}
		}
	}
	return result
}
func sub_4C51D0(a1 *int2, a2 *int2) int32 {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v11 int32
	)
	v2 = a1.field_4
	v3 = a1.field_0
	v4 = a2.field_0 - a1.field_0
	v5 = a2.field_4 - v2
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1321532))
	nox_client_drawEnableAlpha_434560(1)
	nox_client_drawAddPoint_49F500(v3, v2)
	nox_xxx_rasterPointRel_49F570(v4, v5)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawEnableAlpha_434560(0)
	v6 = v2 - 22
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1321536))
	nox_client_drawAddPoint_49F500(v3, v6)
	nox_xxx_rasterPointRel_49F570(v4, v5)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1321796))
	v7 = v4
	if v4 < 0 {
		v7 = -v4
	}
	v8 = v5
	if v5 < 0 {
		v8 = -v5
	}
	if v7 <= v8 {
		nox_client_drawAddPoint_49F500(v3-1, v6)
		v11 = v6 + v5
		nox_client_drawAddPoint_49F500(v4+v3-1, v11)
		nox_client_drawLineFromPoints_49E4B0()
		nox_client_drawAddPoint_49F500(v3+1, v6)
		nox_client_drawAddPoint_49F500(v4+v3+1, v11)
	} else {
		nox_client_drawAddPoint_49F500(v3, v6-1)
		v9 = v3 + v4
		nox_client_drawAddPoint_49F500(v9, v6+v5-1)
		nox_client_drawLineFromPoints_49E4B0()
		nox_client_drawAddPoint_49F500(v3, v6+1)
		nox_client_drawAddPoint_49F500(v9, v6+v5+1)
	}
	return nox_client_drawLineFromPoints_49E4B0()
}
func nox_xxx_sprite_4CA540(a1 *uint32, a2 int32) int32 {
	var (
		v2  *uint32
		v3  float64
		v4  float64
		v5  float64
		v6  float64
		v7  int32
		v8  int32
		v9  int32
		v11 float32
		v12 float32
		v13 float32
		v14 float32
	)
	v2 = (*uint32)(unsafe.Pointer(uintptr(a2)))
	v3 = 0.0
	v4 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 468))))
	v5 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 472))))
	v6 = 0.0
	v7 = int32(gameFrame() - *(*uint32)(unsafe.Pointer(uintptr(a2 + 316))) + 1)
	for {
		v7--
		v13 = float32(-(v5 * float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 476))))))
		v4 = v4 - v4*float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 476))))
		v5 = v5 + float64(v13)
		v3 = v3 + v4
		v6 = v6 + v5
		if v7 == 0 {
			break
		}
	}
	v14 = float32(v6)
	v11 = float32(float64(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*81)))) + v3)
	v8 = nox_float2int(v11)
	v12 = float32(float64(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*82)))) + float64(v14))
	v9 = nox_float2int(v12)
	if v8 > 0 && v9 > 0 && v8 < 5888 && v9 < 5888 {
		nox_xxx_updateSpritePosition_49AA90((*nox_drawable)(unsafe.Pointer(v2)), v8, v9)
		if sub_4992B0(int32(*a1+*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3))-*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4))+*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1))-*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))) != 0 {
			return 1
		}
	}
	nox_xxx_spriteDeleteStatic_45A4E0_drawable((*nox_drawable)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))))
	return 0
}
func sub_4CA650(a1 int32, a2 int32) int32 {
	var (
		v2     int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    uint16
		v13    int32
		v14    int32
		result int32
		v16    int32
		v17    int32
	)
	v2 = a2
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
	v4 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 434)))) - v3
	v5 = int32(uint32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 432)))) - *(*uint32)(unsafe.Pointer(uintptr(a2 + 12))))
	v6 = int32(sub_48C6B0(v5, v4))
	v7 = v6
	v8 = int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 443))))
	v17 = v8
	v7++
	v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 12))))
	v10 = v5 * v8 / v7
	v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))))
	v16 = v9 + v10
	v12 = *(*uint16)(unsafe.Pointer(uintptr(v2 + 432)))
	v13 = v9 - int32(v12)
	v14 = v11 + v4*v17/v7
	if v7 <= 10 || v13*(v16-int32(v12))+(v11-int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 434)))))*(v14-int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 434))))) < 0 {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable((*nox_drawable)(unsafe.Pointer(uintptr(v2))))
		result = 0
	} else {
		nox_xxx_updateSpritePosition_49AA90((*nox_drawable)(unsafe.Pointer(uintptr(v2))), v16, v14)
		result = 1
	}
	return result
}
func sub_4CA720(a1 int32, a2 int32) int32 {
	var (
		v2     int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		result int32
	)
	v2 = int32(gameFrame() - *(*uint32)(unsafe.Pointer(uintptr(a2 + 316))))
	if v2 >= 60 || (func() bool {
		v3 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 432))))
		return cmath.Abs(int64(*(*uint32)(unsafe.Pointer(uintptr(a2 + 12)))-uint32(uint16(int16(v3))))) < 10
	}()) && cmath.Abs(int64(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16)))-uint32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 434)))))) < 10 {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable((*nox_drawable)(unsafe.Pointer(uintptr(a2))))
		result = 0
	} else {
		v4 = int32(*(*int16)(unsafe.Pointer(uintptr(a2 + 440)))) - v2*int32(*(*int16)(unsafe.Pointer(uintptr(a2 + 440))))/60
		v5 = (v2 << 8) / 120
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 443)))) != 0 {
			v6 = v5 + int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 442))))
		} else {
			v6 = int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 442)))) - v5
		}
		if v6 < 0 {
			v6 += int32(uint32(math.MaxUint8-v6) >> 8 << 8)
		}
		if v6 >= 256 {
			v6 += int32((uint32(v6) >> 8) * 4294967040)
		}
		v7 = v4 * *memmap.PtrInt32(0x587000, uintptr(v6*8)+192088)
		v8 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 434)))) + v4**memmap.PtrInt32(0x587000, uintptr(v6*8)+192092)/16
		nox_xxx_updateSpritePosition_49AA90((*nox_drawable)(unsafe.Pointer(uintptr(a2))), v3+v7/16, v8)
		*(*uint32)(unsafe.Pointer(uintptr(a2 + 32))) = uint32(v3 + v7/16)
		*(*uint32)(unsafe.Pointer(uintptr(a2 + 36))) = uint32(v8)
		result = 1
	}
	return result
}
func sub_4CA860() int32 {
	var (
		v0 *uint8
		v1 int64
		v3 int32
	)
	v3 = 0
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 1322584))
	for {
		v1 = int64(math.Atan2(float64(v3)**mem_getDoublePtr(0x581450, 9960), 1.0)**mem_getDoublePtr(0x581450, 9952) + *(*float64)(unsafe.Pointer(&qword_581450_9544)))
		*(*uint16)(unsafe.Pointer(v0)) = uint16(int16(v1))
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 2))
		v3++
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1522584))) {
			break
		}
	}
	return int32(v1)
}
func sub_4CA8B0(a1 int32, a2 int32) int32 {
	var (
		v2     int32
		result int32
		v4     int32
		v5     int32
		v6     int8
	)
	v2 = a2
	if a2 == 0 {
		if a1 <= 0 {
			return 56250
		}
		return 18750
	}
	v4 = a1
	if a2 >= 0 {
		if a1 >= 0 {
			v6 = 1
		} else {
			v6 = 4
			v4 = -v4
		}
	} else {
		if a1 >= 0 {
			v6 = 2
		} else {
			v4 = -a1
			v6 = 3
		}
		v2 = -a2
	}
	v5 = v4 * 1000 / v2
	if uint32(v5) >= 100000 {
		v5 = 99999
	}
	result = int32(*memmap.PtrInt16(0x5D4594, uintptr(v5*2)+1322584))
	switch v6 {
	case 2:
		return 37500 - result
	case 3:
		result += 37500
	case 4:
		result = int32(75000 - uint32(result))
	}
	return result
}
func sub_4CA960(a1 *uint32, a2 int8, a3 *float4, a4 *float2) {
	var (
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		a1a int2
	)
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	a1a.field_0 = int32(*a1 * 23)
	a1a.field_4 = v4 * 23
	switch a2 {
	case 1:
		v6 = nox_float2int(11.5)
		sub_4CAA90(&a1a, a3, a4, v6, 23)
	case 2:
		v5 = nox_float2int(11.5)
		sub_4CAC30(&a1a, a3, a4, 0, v5)
	case 4:
		v8 = nox_float2int(11.5)
		sub_4CAC30(&a1a, a3, a4, v8, 23)
	case 6:
		sub_4CAC30(&a1a, a3, a4, 0, 23)
	case 8:
		v7 = nox_float2int(11.5)
		sub_4CAA90(&a1a, a3, a4, 0, v7)
	case 9:
		sub_4CAA90(&a1a, a3, a4, 0, 23)
	default:
		return
	}
}
func sub_4CAA90(a1 *int2, a2 *float4, a3 *float2, a4 int32, a5 int32) {
	var (
		v5  int32
		v6  int32
		v7  float64
		v8  int32
		v9  float64
		v11 float64
		v13 float64
		v14 float64
		v15 float64
		v16 float64
		v17 float64
		v18 float32
		v19 float32
		v20 float32
		v21 float64
		v22 float32
		v23 float32
	)
	v5 = a5 + a1.field_0
	v6 = a1.field_4 - a5 + 22
	v22 = float32(float64(a1.field_0 + a4))
	v7 = float64(v5)
	v23 = float32(v7)
	v18 = float32(v7 + float64(v6))
	v8 = nox_float2int(v18)
	if a2.field_8 == a2.field_0 {
		v9 = float64(a2.field_8)
		a3.field_0 = a2.field_8
		a3.field_4 = float32(float64(v8) - v9)
	} else {
		v11 = float64(a2.field_C)
		if v11 == float64(a2.field_4) {
			a3.field_4 = a2.field_C
			a3.field_0 = float32(float64(v8) - v11)
		} else {
			v13 = (v11 - float64(a2.field_4)) / float64(a2.field_8-a2.field_0)
			if v13 == -1.0 {
				v13 = -0.99000001
			}
			v14 = float64(v8)
			v20 = float32(v14)
			v15 = float64(nox_double2float((v14 - (float64(a2.field_4) - v13*float64(a2.field_0))) / (v13 + *(*float64)(unsafe.Pointer(&qword_581450_9512)))))
			v16 = cmath.Modf(v15, &v21)
			v19 = nox_double2float(v16)
			v17 = float64(nox_double2float(v21))
			a3.field_0 = float32(v17)
			if float64(v19) <= *(*float64)(unsafe.Pointer(&qword_581450_9544)) {
				if float64(v19) < *mem_getDoublePtr(0x581450, 9968) {
					a3.field_0 = float32(v17 - 1.0)
				}
			} else {
				a3.field_0 = float32(v17 + 1.0)
			}
			if float64(a3.field_0) >= float64(v22) {
				if float64(a3.field_0) > float64(v23) {
					a3.field_0 = v23
				}
				a3.field_4 = v20 - a3.field_0
			} else {
				a3.field_0 = v22
				a3.field_4 = v20 - a3.field_0
			}
		}
	}
}
func sub_4CAC30(a1 *int2, a2 *float4, a3 *float2, a4 int32, a5 int32) {
	var (
		v5  int32
		v6  int32
		v7  int32
		v8  float64
		v9  float64
		v10 float64
		v11 float64
		v12 float64
		v13 float32
		v14 float32
		v15 float32
		v16 float64
		v17 float32
		v18 float32
	)
	v5 = a4 + a1.field_4
	v6 = a5 + a1.field_0
	v17 = float32(float64(a1.field_0 + a4))
	v18 = float32(float64(v6))
	v13 = float32(float64(v5) - float64(v17))
	v7 = nox_float2int(v13)
	if a2.field_8 == a2.field_0 {
		a3.field_0 = a2.field_8
		a3.field_4 = float32(float64(v7) + float64(a2.field_8))
	} else if a2.field_C == a2.field_4 {
		a3.field_0 = float32(float64(a2.field_C) - float64(v7))
		a3.field_4 = a2.field_C
	} else {
		v8 = float64((a2.field_C - a2.field_4) / (a2.field_8 - a2.field_0))
		if v8 == 1.0 {
			v8 = 0.99000001
		}
		v9 = float64(v7)
		v15 = float32(v9)
		v10 = float64(nox_double2float((v9 - (float64(a2.field_4) - v8*float64(a2.field_0))) / (v8 - *(*float64)(unsafe.Pointer(&qword_581450_9512)))))
		v11 = cmath.Modf(v10, &v16)
		v14 = nox_double2float(v11)
		v12 = float64(nox_double2float(v16))
		a3.field_0 = float32(v12)
		if float64(v14) <= *(*float64)(unsafe.Pointer(&qword_581450_9544)) {
			if float64(v14) < *mem_getDoublePtr(0x581450, 9968) {
				a3.field_0 = float32(v12 - 1.0)
			}
		} else {
			a3.field_0 = float32(v12 + 1.0)
		}
		if float64(a3.field_0) >= float64(v17) {
			if float64(a3.field_0) > float64(v18) {
				a3.field_0 = v18
			}
			a3.field_4 = v15 + a3.field_0
		} else {
			a3.field_0 = v17
			a3.field_4 = v15 + a3.field_0
		}
	}
}
func sub_4CADD0() int32 {
	var (
		result int32
		v1     int32
		v2     *uint32
	)
	result = int32(*memmap.PtrUint32(0x5D4594, 1522584))
	if *memmap.PtrUint32(0x5D4594, 1522584) == 0 {
		v1 = 0
		for {
			v2 = (*uint32)(alloc.Calloc1(1, 0x3C))
			if v2 == nil {
				nox_exit(-1)
			}
			v1++
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4)) = *memmap.PtrUint32(0x5D4594, 1522584)
			*memmap.PtrUint32(0x5D4594, 1522584) = uint32(uintptr(unsafe.Pointer(v2)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = *memmap.PtrUint32(0x5D4594, 1522592)
			*memmap.PtrUint32(0x5D4594, 1522592) = uint32(uintptr(unsafe.Pointer(v2)))
			if v1 >= 10 {
				break
			}
		}
		*memmap.PtrUint32(0x5D4594, 1522588) += 10
		result = int32(*memmap.PtrUint32(0x5D4594, 1522584))
	}
	*memmap.PtrUint32(0x5D4594, 1522584) = *(*uint32)(unsafe.Pointer(uintptr(result + 16)))
	return result
}
func sub_4CAE40(a1 int32) int32 {
	var result int32
	result = a1
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) = *memmap.PtrUint32(0x5D4594, 1522584)
	*memmap.PtrUint32(0x5D4594, 1522584) = uint32(a1)
	return result
}
func sub_4CAE60() int32 {
	var (
		result int32
		v1     int32
	)
	result = int32(*memmap.PtrUint32(0x5D4594, 1522592))
	v1 = 0
	for *memmap.PtrUint32(0x5D4594, 1522584) = 0; result != 0; result = int32(*(*uint32)(unsafe.Pointer(uintptr(result + 8)))) {
		*(*uint32)(unsafe.Pointer(uintptr(result + 16))) = uint32(v1)
		v1 = result
		*memmap.PtrUint32(0x5D4594, 1522584) = uint32(result)
	}
	return result
}
func sub_4CAE90(a1 int32) int32 {
	var result int32
	result = a1
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))) = dword_5d4594_1522596
	dword_5d4594_1522596 = uint32(a1)
	return result
}
func sub_4CAEB0() int32 {
	var result int32
	result = int32(dword_5d4594_1522596)
	if dword_5d4594_1522596 != 0 {
		dword_5d4594_1522596 = *(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1522596 + 12)))
	}
	return result
}
func sub_4CAED0(a1 int32) int32 {
	var result int32
	result = sub_4CADD0()
	*(*uint32)(unsafe.Pointer(uintptr(result + 24))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 24)))
	*(*uint32)(unsafe.Pointer(uintptr(result + 28))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 28)))
	*(*uint32)(unsafe.Pointer(uintptr(result + 32))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 32)))
	*(*uint8)(unsafe.Pointer(uintptr(result + 36))) = *(*uint8)(unsafe.Pointer(uintptr(a1 + 36)))
	*(*uint32)(unsafe.Pointer(uintptr(result + 40))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 40)))
	*(*uint32)(unsafe.Pointer(uintptr(result + 44))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 44)))
	*(*uint8)(unsafe.Pointer(uintptr(result + 48))) = *(*uint8)(unsafe.Pointer(uintptr(a1 + 48)))
	*(*uint8)(unsafe.Pointer(uintptr(result + 56))) = *(*uint8)(unsafe.Pointer(uintptr(a1 + 56)))
	*(*uint32)(unsafe.Pointer(uintptr(result + 20))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 20)))
	return result
}
func nox_gui_newProgressBar_4CAF10(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int32, a7 *uint32) *nox_window {
	var (
		v7 int32
		v8 *uint32
	)
	v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a7), 4*2)))
	if (v7 & 0x1000) == 0 {
		return nil
	}
	v8 = (*uint32)(unsafe.Pointer(nox_window_new((*nox_window)(unsafe.Pointer(uintptr(a1))), int32(uint32(a2)&0xFFFFFFF7), a3, a4, a5, a6, sub_4CAF80)))
	sub_4CAFB0(int32(uintptr(unsafe.Pointer(v8))))
	if v8 != nil {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(a7), 4*4)) == 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(a7), 4*4)) = uint32(uintptr(unsafe.Pointer(v8)))
		}
		nox_gui_windowCopyDrawData_46AF80((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))), unsafe.Pointer(a7))
	}
	return (*nox_window)(unsafe.Pointer(v8))
}
func sub_4CAF80(a1 int32, a2 int32, a3 int32, a4 int32) int32 {
	if a2 == 16416 && a3 >= 0 && a3 <= 100 {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 32))) = uint32(a3)
	}
	return 0
}
func sub_4CAFB0(a1 int32) int32 {
	var result int32
	result = a1
	if a1 != 0 {
		if int32(int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 4))))) >= 0 {
			result = nox_window_set_all_funcs((*nox_window)(unsafe.Pointer(uintptr(a1))), nil, func(arg1 *nox_window, arg2 unsafe.Pointer) int32 {
				return sub_4CAFF0((*uint32)(unsafe.Pointer(arg1)), (*uint32)(arg2))
			}, nil)
		} else {
			result = nox_window_set_all_funcs((*nox_window)(unsafe.Pointer(uintptr(a1))), nil, func(arg1 *nox_window, arg2 unsafe.Pointer) int32 {
				return sub_4CB1A0((*uint32)(unsafe.Pointer(arg1)), int32(uintptr(arg2)))
			}, nil)
		}
	}
	return result
}
func sub_4CAFF0(a1 *uint32, a2 *uint32) int32 {
	var (
		v2    int32
		v3    int32
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		xLeft int32
		yTop  int32
		v11   int32
		v12   int32
		v13   int32
		v14   int32
		v15   [64]wchar2_t
	)
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*17)))
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*9)))
	v14 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*7)))
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*5)))
	v11 = v2
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(a1)), (*uint32)(unsafe.Pointer(&xLeft)), (*uint32)(unsafe.Pointer(&yTop)))
	if uint32(v4) != 0x80000000 {
		nox_client_drawSetColor_434460(v4)
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3))))
	}
	if uint32(v3) != 0x80000000 {
		v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) * *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)) / 100)
		nox_client_drawSetColor_434460(v3)
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, v5, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3))))
	}
	if uint32(v11) != 0x80000000 {
		if (*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) & 0x2000) == 0x2000 {
			nox_draw_enableTextSmoothing_43F670(1)
		}
		nox_swprintf(&v15[0], (*wchar2_t)(unsafe.Pointer(internCStr("%i%%"))), *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)))
		nox_xxx_drawGetStringSize_43F840(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*50)))), &v15[0], &v13, &v12, 64)
		v6 = int32(uint32(xLeft) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))/2 - uint32(v13/2))
		v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3))/2 - uint32(v12/2) + uint32(yTop) + 1)
		nox_xxx_drawSetTextColor_434390(v11)
		nox_xxx_drawStringWrap_43FAF0(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*50)))), &v15[0], v6, v7, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))), 0)
		nox_draw_enableTextSmoothing_43F670(0)
	}
	if uint32(v14) != 0x80000000 {
		nox_client_drawSetColor_434460(v14)
		nox_client_drawBorderLines_49CC70(xLeft, yTop, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3))))
	}
	return 1
}
func sub_4CB1A0(a1 *uint32, a2 int32) int32 {
	var (
		v2    int32
		v3    *uint32
		v4    int32
		xLeft int32
		yTop  int32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 24))))
	v3 = a1
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(a1)), (*uint32)(unsafe.Pointer(&xLeft)), (*uint32)(unsafe.Pointer(&yTop)))
	nox_xxx_wndDraw_49F7F0()
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2)) * *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*8)) / 100)
	nox_client_copyRect_49F6F0(xLeft, yTop, v4, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3))))
	if v2 != 0 && v4 > 0 {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(v2))), xLeft, yTop)
	}
	sub_49F860()
	return 1
}
func sub_4CB880() int32 {
	var (
		result int32
		v1     **uint32
		v2     *uint32
		v3     *uint32
		v4     int32
		v5     int32
		v6     *uint32
		v7     int32
		v8     *uint32
		v9     *uint32
	)
	nox_game_addStateCode_43BDD0(900)
	result = int32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("InputCfg.wnd"), unsafe.Pointer(funAddr(sub_4CBE70))))))
	dword_5d4594_1522604 = uint32(result)
	if result != 0 {
		nox_xxx_wndSetWindowProc_46B300(result, func(arg1 int32, arg2 int32, arg3 int32, arg4 int32) int32 {
			return sub_4A18E0(unsafe.Pointer(uintptr(arg1)), arg2, arg3, arg4)
		})
		result = int32(uintptr(unsafe.Pointer(nox_gui_makeAnimation_43C5B0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), 0, 0, 0, -480, 0, 20, 0, -40))))
		nox_wnd_xxx_1522608 = (*nox_gui_animation)(unsafe.Pointer(uintptr(result)))
		if result != 0 {
			nox_wnd_xxx_1522608.field_0 = 900
			nox_wnd_xxx_1522608.field_12 = sub_4CBB70
			nox_wnd_xxx_1522608.fnc_done_out = sub_4CBBB0
			dword_5d4594_1522616 = nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), 910)
			dword_5d4594_1522620 = nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), 911)
			dword_5d4594_1522624 = nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), 912)
			dword_5d4594_1522628 = nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), 913)
			result = int32(uintptr(unsafe.Pointer(dword_5d4594_1522616)))
			if dword_5d4594_1522616 != nil {
				v1 = *(***uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1522616))) + 32)))
				**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*7)) = 921
				**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*8)) = 922
				**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*9)) = 920
				nox_xxx_wndSetProc_46B2C0(*(*int32)(unsafe.Pointer(&dword_5d4594_1522616)), func(arg1 int32, arg2 int32, arg3 int32, arg4 int32) int32 {
					return sub_4CBF60(arg1, uint32(arg2), arg3, arg4)
				})
				sub_46B120((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522620)))), (*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522616))))))
				sub_46B120((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522624)))), (*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522616))))))
				sub_46B120((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522628)))), (*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522616))))))
				nox_xxx_wndSetWindowProc_46B300(*(*int32)(unsafe.Pointer(&dword_5d4594_1522624)), func(arg1 int32, arg2 int32, arg3 int32, arg4 int32) int32 {
					return sub_4CC140((*uint32)(unsafe.Pointer(uintptr(arg1))), uint32(arg2), uint32(arg3), arg4)
				})
				nox_xxx_wndSetWindowProc_46B300(*(*int32)(unsafe.Pointer(&dword_5d4594_1522628)), func(arg1 int32, arg2 int32, arg3 int32, arg4 int32) int32 {
					return sub_4CC140((*uint32)(unsafe.Pointer(uintptr(arg1))), uint32(arg2), uint32(arg3), arg4)
				})
				v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), 921)))
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522620))))), 16408, int32(uintptr(unsafe.Pointer(v2))), 0)
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522624))))), 16408, int32(uintptr(unsafe.Pointer(v2))), 0)
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522628))))), 16408, int32(uintptr(unsafe.Pointer(v2))), 0)
				v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), 922)))
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522620))))), 16409, int32(uintptr(unsafe.Pointer(v3))), 0)
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522624))))), 16409, int32(uintptr(unsafe.Pointer(v3))), 0)
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522628))))), 16409, int32(uintptr(unsafe.Pointer(v3))), 0)
				sub_4CBBF0()
				v4 = 971
				v5 = int32(sub_47DBC0()) + 971
				if v5 > 971 {
					for {
						v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), v4)))
						nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v6)))))), 1)
						v4++
						if v4 >= v5 {
							break
						}
					}
				}
				v7 = nox_client_mousePriKey_430AF0()
				v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), v7+971)))
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))), 16392, 1, 0)
				dword_5d4594_1522612 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), 980))))
				sub_46B120((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522612)))), nil)
				nox_xxx_wndSetProc_46B2C0(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612)), func(arg1 int32, arg2 int32, arg3 int32, arg4 int32) int32 {
					return sub_4CBE70(arg1, arg2, (*int32)(unsafe.Pointer(uintptr(arg3))), arg4)
				})
				nox_xxx_wndSetWindowProc_46B300(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612)), func(arg1 int32, arg2 int32, arg3 int32, arg4 int32) int32 {
					return sub_4CC170(arg1, arg2, (*byte)(unsafe.Pointer(uintptr(arg3))), arg4)
				})
				nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))), 1)
				v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522612)))), 981)))
				sub_46AEE0(int32(uintptr(unsafe.Pointer(v9))), int32(uintptr(memmap.PtrOff(0x5D4594, 1522636))))
				result = 1
			}
		}
	}
	return result
}
func sub_4CBB70() int32 {
	sub_4CBD30()
	nox_common_writecfgfile(internCStr("nox.cfg"))
	nox_wnd_xxx_1522608.state = nox_gui_anim_state(NOX_GUI_ANIM_OUT)
	sub_43BE40(2)
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100)
	return 1
}
func sub_4CBBB0() int32 {
	var v0 func() int32
	v0 = nox_wnd_xxx_1522608.field_13
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_1522608)
	nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))))
	nox_xxx_windowDestroyMB_46C4E0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522612)))))
	v0()
	return 1
}
func sub_4CC140(a1 *uint32, a2 uint32, a3 uint32, a4 int32) int32 {
	if a2 < 0x13 || a2 > 0x14 {
		return nox_xxx_wndListboxProcWithoutData10_4A28E0(a1, int32(a2), a3, a4)
	} else {
		return 0
	}
}
func sub_4CC170(a1 int32, a2 int32, a3 *byte, a4 int32) int32 {
	switch a2 {
	case 6, 7:
		sub_4CC3C0(0x10000)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))), 1)
		return 1
	case 10, 11:
		sub_4CC3C0(0x10002)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))), 1)
		return 1
	case 14, 15:
		sub_4CC3C0(0x10001)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))), 1)
		return 1
	case 19:
		sub_4CC3C0(0x10003)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))), 1)
		return 1
	case 20:
		sub_4CC3C0(0x10004)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))))
		nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))), 1)
		return 1
	case 21:
		if uintptr(unsafe.Pointer(a3)) == uintptr(1) {
			if a4 == 2 {
				nox_xxx_windowFocus_46B500(nil)
				nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))))
				nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))), 1)
				if dword_5d4594_1522632 != 0 {
					nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522632))))), 16403, -1, 0)
				}
			}
			return 1
		} else if a4 == 1 && sub_4CC280(uint32(uintptr(unsafe.Pointer(a3)))) != 0 {
			sub_4CC3C0(0x10000)
			nox_xxx_windowFocus_46B500(nil)
			nox_xxx_wnd_46C6E0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))))
			nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))), 1)
			return 1
		} else {
			return 0
		}
	default:
		return 0
	}
}
func sub_4CC280(a1 uint32) int32 {
	var v6 *wchar2_t = nox_xxx_keybind_titleByKeyZero_42EA00(a1)
	if v6 == nil {
		return 0
	}
	if dword_5d4594_1522632 == 0 {
		return 1
	}
	var v7 int32 = 0
	var v8 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1522624))) + 32))))
	if int32(*(*uint16)(unsafe.Pointer(uintptr(v8 + 44)))) > 0 {
		for {
			{
				var v9 *wchar2_t = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522624))))), 16406, v7, 0))))
				if nox_wcscmp(v9, v6) == 0 {
					nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522624))))), 16407, int32(uintptr(memmap.PtrOff(0x587000, 187824))), v7)
				}
				v7++
			}
			if v7 >= int32(*(*int16)(unsafe.Pointer(uintptr(v8 + 44)))) {
				break
			}
		}
	}
	var v10 int32 = 0
	var v11 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1522628))) + 32))))
	if int32(*(*uint16)(unsafe.Pointer(uintptr(v11 + 44)))) > 0 {
		for {
			{
				var v12 *wchar2_t = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522628))))), 16406, v10, 0))))
				if nox_wcscmp(v12, v6) == 0 {
					nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522628))))), 16407, int32(uintptr(memmap.PtrOff(0x587000, 187828))), v10)
				}
				v10++
			}
			if v10 >= int32(*(*int16)(unsafe.Pointer(uintptr(v11 + 44)))) {
				break
			}
		}
	}
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522632))))), 16407, int32(uintptr(unsafe.Pointer(v6))), int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1522632 + 32))) + 48)))))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522632))))), 16403, -1, 0)
	dword_5d4594_1522632 = 0
	return 1
}
func sub_4CC3C0(a1 uint32) int32 {
	var (
		v1 *byte
		v2 int32
		v3 int32
		v4 *wchar2_t
		v5 int32
		v6 int32
		v7 *wchar2_t
	)
	v1 = (*byte)(unsafe.Pointer(nox_xxx_keybind_titleByKey_42EA00(a1)))
	if dword_5d4594_1522632 == 0 {
		return 1
	}
	v2 = 0
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1522624))) + 32))))
	if int32(*(*uint16)(unsafe.Pointer(uintptr(v3 + 44)))) > 0 {
		for {
			v4 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522624))))), 16406, v2, 0))))
			if nox_wcscmp(v4, (*wchar2_t)(unsafe.Pointer(v1))) == 0 {
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522624))))), 16407, int32(uintptr(memmap.PtrOff(0x587000, 187832))), v2)
			}
			v2++
			if v2 >= int32(*(*int16)(unsafe.Pointer(uintptr(v3 + 44)))) {
				break
			}
		}
	}
	v5 = 0
	v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1522628))) + 32))))
	if int32(*(*uint16)(unsafe.Pointer(uintptr(v6 + 44)))) > 0 {
		for {
			v7 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522628))))), 16406, v5, 0))))
			if nox_wcscmp(v7, (*wchar2_t)(unsafe.Pointer(v1))) == 0 {
				nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522628))))), 16407, int32(uintptr(memmap.PtrOff(0x587000, 187836))), v5)
			}
			v5++
			if v5 >= int32(*(*int16)(unsafe.Pointer(uintptr(v6 + 44)))) {
				break
			}
		}
	}
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522632))))), 16407, int32(uintptr(unsafe.Pointer(v1))), int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1522632 + 32))) + 48)))))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522632))))), 16403, -1, 0)
	dword_5d4594_1522632 = 0
	return 1
}
func nox_xxx_updDrawUndeadKiller_4CCCF0() int32 {
	return 1
}
func sub_4CCD00(a1 int32, a2 int32) int32 {
	var i uint32
	for i = *(*uint32)(unsafe.Pointer(uintptr(a2 + 432))); i < gameFrame(); i++ {
		if float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 436)))) > 0.0 {
			*(*float32)(unsafe.Pointer(uintptr(a2 + 436))) = *(*float32)(unsafe.Pointer(uintptr(a2 + 440))) + *(*float32)(unsafe.Pointer(uintptr(a2 + 436)))
			*(*float32)(unsafe.Pointer(uintptr(a2 + 440))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 440)))) - 1.0)
		}
		if float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 436)))) <= 0.0 {
			*(*uint32)(unsafe.Pointer(uintptr(a2 + 436))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(a2 + 440))) = 0
		}
	}
	*(*uint16)(unsafe.Pointer(uintptr(a2 + 104))) = uint16(int16(int64(*(*float32)(unsafe.Pointer(uintptr(a2 + 436))))))
	*(*uint8)(unsafe.Pointer(uintptr(a2 + 296))) = uint8(int8(int64(*(*float32)(unsafe.Pointer(uintptr(a2 + 440))))))
	*(*uint32)(unsafe.Pointer(uintptr(a2 + 432))) = gameFrame()
	return 1
}
func nox_xxx_updDrawFist_4CCDB0(a1 int32, a2 int32) int32 {
	var (
		i  uint32
		v3 float64
		v4 float64
		v5 float64
	)
	for i = *(*uint32)(unsafe.Pointer(uintptr(a2 + 432))); i < gameFrame(); i++ {
		v3 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 436))) + *(*float32)(unsafe.Pointer(uintptr(a2 + 440))))
		*(*float32)(unsafe.Pointer(uintptr(a2 + 436))) = float32(v3)
		if v3 >= 0.0 {
			*(*float32)(unsafe.Pointer(uintptr(a2 + 440))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 440)))) - 0.5)
		} else {
			v4 = float64(-*(*float32)(unsafe.Pointer(uintptr(a2 + 440))) * *(*float32)(unsafe.Pointer(uintptr(a2 + 444))))
			*(*uint32)(unsafe.Pointer(uintptr(a2 + 436))) = 0
			v5 = v4 * 0.1
			*(*float32)(unsafe.Pointer(uintptr(a2 + 440))) = float32(v5)
			if v5 < 2.0 {
				*(*uint32)(unsafe.Pointer(uintptr(a2 + 436))) = 0
				*(*uint32)(unsafe.Pointer(uintptr(a2 + 440))) = 0
			}
		}
	}
	*(*uint16)(unsafe.Pointer(uintptr(a2 + 104))) = uint16(int16(int64(*(*float32)(unsafe.Pointer(uintptr(a2 + 436))))))
	*(*uint8)(unsafe.Pointer(uintptr(a2 + 296))) = uint8(int8(int64(*(*float32)(unsafe.Pointer(uintptr(a2 + 440))))))
	*(*uint32)(unsafe.Pointer(uintptr(a2 + 432))) = gameFrame()
	return 1
}
func sub_4CCE70(a1 int32, a2 *uint32) int32 {
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*120)) == 0 && nox_xxx_checkGameFlagPause_413A50() == 0 {
		sub_4CCEA0(a2, 5)
	}
	return 1
}
func sub_4CD090(a1 int32, a2 *uint32) int32 {
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*120)) == 0 && nox_xxx_checkGameFlagPause_413A50() == 0 {
		sub_4CCEA0(a2, 4)
	}
	return 1
}
func sub_4CD0C0(a1 int32, a2 *uint32) int32 {
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*120)) == 0 && nox_xxx_checkGameFlagPause_413A50() == 0 {
		sub_4CCEA0(a2, 3)
	}
	return 1
}
func sub_4CD0F0(a1 int32, a2 *uint32) int32 {
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*120)) == 0 && nox_xxx_checkGameFlagPause_413A50() == 0 {
		sub_4CCEA0(a2, 2)
	}
	return 1
}
func sub_4CD120(a1 int32, a2 *uint32) int32 {
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*120)) == 0 && nox_xxx_checkGameFlagPause_413A50() == 0 {
		sub_4CCEA0(a2, 1)
	}
	return 1
}
func sub_4CD400(a1 *uint32, a2 int32) int32 {
	var v2 int32
	v2 = int32(dword_5d4594_1522968)
	if dword_5d4594_1522968 == 0 {
		v2 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CharmOrb"))
		dword_5d4594_1522968 = uint32(v2)
	}
	sub_4CD150(v2, a1, a2, 1)
	sub_4CD150(*(*int32)(unsafe.Pointer(&dword_5d4594_1522968)), a1, a2, 0)
	return 1
}
