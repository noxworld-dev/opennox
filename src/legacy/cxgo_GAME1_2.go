package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/cnet"
	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

var nox_win_width int32 = 0
var nox_win_height int32 = 0
var ptr_5D4594_754088 *obj_5D4594_754088_t = nil
var ptr_5D4594_754088_cnt int32 = 0
var ptr_5D4594_754092 *obj_5D4594_754088_t = nil
var ptr_5D4594_754092_cnt int32 = 0
var nox_screenParticles_head *Nox_screenParticle = nil
var dword_5d4594_806052 *Nox_screenParticle = nil
var dword_5d4594_814624 unsafe.Pointer = nil
var dword_5d4594_805984 unsafe.Pointer = nil

func nox_xxx_wallMath_427F30(a1 *int2, a2 *int32) int32 {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v9  int32
		v10 int32
		v12 int32
		v13 int32
	)
	v2 = a1.field_0
	if float64(a1.field_0) < 57.5 {
		return 0
	}
	v3 = a1.field_4
	if float64(v3) < 57.5 {
		return 0
	}
	if v2 > 5888 {
		return 0
	}
	if v3 > 5888 {
		return 0
	}
	v4 = v2 / 23
	v5 = v3 / 23
	v6 = *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*1)) / 23
	v12 = *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*2)) / 23
	v13 = *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*3)) / 23
	v7 = *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*4)) / 23
	v9 = *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*5)) / 23
	if v3/23 < v6 || v5 > *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*7))/23 || v4 < v12 || v4 > v7 {
		return 0
	}
	if v5 > v13 {
		if v4 < v5+v12-v13 {
			return 0
		}
		v10 = *a2 / 23
	} else {
		v10 = *a2 / 23
		if v4 < v10+v6-v5 {
			return 0
		}
	}
	if v5 > v9 {
		if v4 > v7+v9-v5 {
			return 0
		}
	} else if v4 > v5+v10-v6 {
		return 0
	}
	return 1
}
func sub_428170(a1p unsafe.Pointer, a2 *int4) int32 {
	var (
		a1 *uint32 = (*uint32)(a1p)
		v2 int32
		v3 int32
	)
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	if uint32(v2) >= *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*7)) {
		a2.field_C = v2
		a2.field_4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*7)))
	} else {
		a2.field_4 = v2
		a2.field_C = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*7)))
	}
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
	if uint32(v3) >= *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) {
		a2.field_8 = v3
		a2.field_0 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	} else {
		a2.field_0 = v3
		a2.field_8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	}
	if a2.field_0 < 0 {
		a2.field_0 = 0
	}
	if a2.field_4 < 0 {
		a2.field_4 = 0
	}
	if a2.field_8 >= 5888 {
		a2.field_8 = 5887
	}
	if a2.field_C >= 5888 {
		a2.field_C = 5887
	}
	return 0
}
func nox_xxx_pointInRect_4281F0(a1 *int2, a2 *int4) int32 {
	var (
		v2     int32
		result bool
	)
	result = false
	if a1.field_0 >= a2.field_0 && a1.field_0 <= a2.field_8 {
		v2 = a1.field_4
		if v2 >= a2.field_4 && v2 <= a2.field_C {
			result = true
		}
	}
	return bool2int32(result)
}
func sub_428220(a1 *float2, a2 *float4) int32 {
	return bool2int32(float64(a1.field_0) >= float64(a2.field_0) && float64(a1.field_0) <= float64(a2.field_8) && float64(a1.field_4) >= float64(a2.field_4) && float64(a1.field_4) <= float64(a2.field_C))
}
func nox_shape_box_calc(s *nox_shape) {
	const mul float32 = 0.35354999
	px := s.Box.W * mul
	py := s.Box.H * mul
	v := float64(-px + py)
	s.Box.LeftTop = float32(v)
	s.Box.LeftTop2 = float32(v)
	v = float64(-px - py)
	s.Box.LeftBottom = float32(v)
	s.Box.LeftBottom2 = float32(v)
	v = float64(+px + py)
	s.Box.RightTop = float32(v)
	s.Box.RightTop2 = float32(v)
	v = float64(+px - py)
	s.Box.RightBottom = float32(v)
	s.Box.RightBottom2 = float32(v)
}
func sub_4282D0(a1 *byte, a2 int32) *byte {
	var result *byte
	result = libc.StrNCpy((*byte)(memmap.PtrOff(0x5D4594, 741316)), a1, 0x10)
	*memmap.PtrUint32(0x5D4594, 741304) = uint32(a2)
	return result
}
func sub_4282F0(a1 int32, a2 int32, a3 uint32) unsafe.Pointer {
	var (
		v3     int32
		v4     uint32
		i      uint32
		v6     uint32
		result unsafe.Pointer
		v8     uint32
		v9     int32
		v10    int32
		v11    int32
		j      int32
	)
	v3 = a1
	v4 = 0
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 608))) != 0 {
		for i = 0; i < uint32(*(*int32)(unsafe.Pointer(&dword_5d4594_741332))); i++ {
			alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 608))) + i*4))))
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 608))) + i*4))) = 0
		}
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 608))))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 608))) = 0
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 612))) != 0 {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 612))))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 612))) = 0
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 616))) != 0 {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 616))))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 616))) = 0
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 620))) != 0 {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 620))))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 620))) = 0
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 624))) != 0 {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 624))))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 624))) = 0
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 628))) != 0 {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 628))))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 628))) = 0
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 632))) != 0 {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 632))))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 632))) = 0
	}
	v6 = a3 * 4
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 608))) = uint32(uintptr(alloc.Calloc1(int(a3), 4)))
	if a3 != 0 {
		for {
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 608))) + func() uint32 {
				p := &v4
				x := *p
				*p++
				return x
			}()*4))) = uint32(uintptr(alloc.Calloc1(1, 0xA)))
			if v4 >= a3 {
				break
			}
		}
	}
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 612))) = uint32(uintptr(alloc.Calloc1(1, uintptr(v6))))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 616))) = uint32(uintptr(alloc.Calloc1(1, uintptr(v6))))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 620))) = uint32(uintptr(alloc.Calloc1(1, uintptr(a3))))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 624))) = uint32(uintptr(alloc.Calloc1(1, uintptr(a3))))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 628))) = uint32(uintptr(alloc.Calloc1(1, uintptr(v6))))
	result = alloc.Calloc1(1, uintptr(a3))
	v8 = 0
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 632))) = uint32(uintptr(result))
	if a3 != 0 {
		v9 = a2 + 16
		for j = a2 + 16; ; v9 = j {
			libc.StrCpy(*(**byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 608))) + v8*4))), (*byte)(unsafe.Pointer(uintptr(v9-16))))
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 612))) + v8*4))) = *(*uint32)(unsafe.Pointer(uintptr(v9 - 4)))
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 616))) + v8*4))) = *(*uint32)(unsafe.Pointer(uintptr(v9)))
			*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 620))) + v8))) = *(*uint8)(unsafe.Pointer(uintptr(v9 + 4)))
			*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 624))) + v8))) = *(*uint8)(unsafe.Pointer(uintptr(v9 + 5)))
			*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 632))) + v8))) = *(*uint8)(unsafe.Pointer(uintptr(v9 + 12)))
			v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(v9 + 8))))
			v11 = int32(libc.GetTime(nil) - libc.Time(v10))
			v8++
			*(*uint32)(unsafe.Pointer(uintptr(j + 8))) = uint32(v11)
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 628))) + v8*4 - 4))) = uint32(v11)
			result = unsafe.Pointer(uintptr(a3))
			j += 32
			if v8 >= a3 {
				break
			}
		}
		*(*uint16)(unsafe.Pointer(uintptr(v3 + 6))) = uint16(a3)
		dword_5d4594_741332 = a3
	} else {
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 6))) = 0
		dword_5d4594_741332 = 0
	}
	return result
}
func sub_428540(a1 int32, a2 *byte, a3 int32) uint32 {
	var (
		result uint32
		v4     *byte
		v5     int8
	)
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 636))) != 0 {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 636))))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 636))) = 0
	}
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 636))) = uint32(uintptr(alloc.Calloc1(int(a3), 2)))
	result = 0
	if a3*2 != 0 {
		v4 = a2
		for {
			v5 = int8(*v4)
			v4 = (*byte)(unsafe.Add(unsafe.Pointer(v4), 2))
			*(*uint8)(unsafe.Pointer(uintptr(result + *(*uint32)(unsafe.Pointer(uintptr(a1 + 636)))))) = uint8(v5)
			*(*uint8)(unsafe.Pointer(uintptr(result + *(*uint32)(unsafe.Pointer(uintptr(a1 + 636))) + 1))) = uint8(*((*byte)(unsafe.Add(unsafe.Pointer(v4), -1))))
			result += 2
			if result >= uint32(a3*2) {
				break
			}
		}
		*memmap.PtrUint32(0x5D4594, 741308) = uint32(a3)
	} else {
		*memmap.PtrUint32(0x5D4594, 741308) = uint32(a3)
	}
	return result
}
func sub_4285C0(a1 *int16) *byte {
	var (
		result *byte
		v2     *int16
		v3     unsafe.Pointer
		v4     uint32
		v5     bool
		v6     unsafe.Pointer
		v7     unsafe.Pointer
		v8     unsafe.Pointer
		v9     unsafe.Pointer
		v10    unsafe.Pointer
		v11    unsafe.Pointer
		v12    *byte
		v13    int32
		v14    uint32
		v15    uint32
		v16    uint32
		v17    uint32
		v18    uint32
		v19    uint32
		v20    int32
	)
	result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_player_4E3CE0())))
	v2 = a1
	*a1 = int16(uintptr(unsafe.Pointer(result)))
	if int32(int16(uintptr(unsafe.Pointer(result)))) <= 0 {
		dword_5d4594_741332 = uint32(*a1)
	} else {
		v3 = alloc.Calloc1(int(int16(uintptr(unsafe.Pointer(result)))), 4)
		v4 = 0
		v5 = int32(*a1) == 0
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*134))) = uint32(uintptr(v3))
		if !v5 {
			for {
				*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*134))) + func() uint32 {
					p := &v4
					x := *p
					*p++
					return x
				}()*4))) = uint32(uintptr(alloc.Calloc1(1, 0xA)))
				if v4 >= uint32(*a1) {
					break
				}
			}
		}
		v6 = alloc.Calloc1(int(*a1), 4)
		v19 = uint32(*a1)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*135))) = uint32(uintptr(v6))
		v7 = alloc.Calloc1(1, uintptr(v19))
		v18 = uint32(int32(*a1) * 4)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*144))) = uint32(uintptr(v7))
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*136))) = uint32(uintptr(alloc.Calloc1(1, uintptr(v18))))
		v8 = alloc.Calloc1(int(*a1), 4)
		v17 = uint32(int32(*a1) * 4)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*137))) = uint32(uintptr(v8))
		v9 = alloc.Calloc1(1, uintptr(v17))
		v16 = uint32(int32(*a1) * 4)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*138))) = uint32(uintptr(v9))
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*139))) = uint32(uintptr(alloc.Calloc1(1, uintptr(v16))))
		v10 = alloc.Calloc1(int(*a1), 4)
		v15 = uint32(int32(*a1) * 4)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*140))) = uint32(uintptr(v10))
		v11 = alloc.Calloc1(1, uintptr(v15))
		v14 = uint32(int32(*a1) * 4)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*141))) = uint32(uintptr(v11))
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*142))) = uint32(uintptr(alloc.Calloc1(1, uintptr(v14))))
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*143))) = uint32(uintptr(alloc.Calloc1(int(*a1), 4)))
		v20 = 0
		result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
		v12 = result
		if result != nil {
			for {
				if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*1198))) != 0 {
					libc.StrCpy(*(**byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*134))) + uint32(v20*4)))), (*byte)(unsafe.Add(unsafe.Pointer(v12), 2096)))
					v13 = int32(nox_xxx_net_getIP_554200(int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v12), 2064)))) + 1))
					*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*135))) + uint32(v20*4)))) = cnet.Htonl(uint32(v13))
					*(*uint8)(unsafe.Pointer(uintptr(uint32(v20) + *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*144)))))) = uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v12), 2251)))
					*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*136))) + uint32(v20*4)))) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*1172)))
					*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*137))) + uint32(v20*4)))) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*1172)))
					*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*138))) + uint32(v20*4)))) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*1166)))
					*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*139))) + uint32(v20*4)))) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*1165)))
					*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*140))) + uint32(v20*4)))) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*1167)))
					*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*141))) + uint32(v20*4)))) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*1168)))
					*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*142))) + uint32(v20*4)))) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*1171)))
					*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*143))) + uint32(func() int32 {
						p := &v20
						x := *p
						*p++
						return x
					}()*4)))) = sub_4D6540(int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v12), 2064)))))
				}
				v12 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*nox_playerInfo)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v12)))))))))
				if v12 == nil {
					break
				}
			}
			result = (*byte)(unsafe.Pointer(uintptr(*v2)))
			dword_5d4594_741332 = uint32(*v2)
		} else {
			dword_5d4594_741332 = uint32(*v2)
		}
	}
	return result
}
func sub_428810(a1 int32, a2 int32) int32 {
	var (
		v2 *uint16
		v3 *uint16
		v4 int32
		v6 [72]byte
	)
	v2 = sub_42ADA0(a1, a2, *memmap.PtrInt16(0x5D4594, 741308), mem_getU32Ptr(0x5D4594, 741312))
	v3 = sub_42A8B0((*uint8)(unsafe.Pointer(v2)), mem_getI32Ptr(0x5D4594, 741312))
	alloc.Free(v2)
	v4 = 1
	if sub_420360(&v6[0], (*uint16)(unsafe.Pointer(&a2))) != 0 {
		panic("abort")
	}
	alloc.Free(v3)
	return v4
}
func sub_428890(a1 *int16) int32 {
	var (
		v1 *uint16
		v2 *uint16
		v3 int32
		v5 [72]byte
	)
	v1 = sub_42B810(a1, mem_getU32Ptr(0x5D4594, 741300))
	v2 = sub_42A8B0((*uint8)(unsafe.Pointer(v1)), mem_getI32Ptr(0x5D4594, 741300))
	alloc.Free(v1)
	v3 = 1
	if sub_420360(&v5[0], (*uint16)(unsafe.Pointer(&a1))) != 0 {
		panic("abort")
	}
	alloc.Free(v2)
	return v3
}
func sub_4289D0(a1 *unsafe.Pointer) unsafe.Pointer {
	var (
		i      uint32
		result unsafe.Pointer
	)
	if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*134)) != nil {
		for i = 0; i < uint32(*(*int32)(unsafe.Pointer(&dword_5d4594_741332))); i++ {
			alloc.FreePtr(*((*unsafe.Pointer)(unsafe.Add(unsafe.Pointer((*unsafe.Pointer)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*134)))), unsafe.Sizeof(unsafe.Pointer(nil))*uintptr(i)))))
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*134)))), 4*uintptr(i)))) = 0
		}
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*134)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*134)) = nil
	}
	if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*135)) != nil {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*135)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*135)) = nil
	}
	if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*144)) != nil {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*144)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*144)) = nil
	}
	if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*136)) != nil {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*136)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*136)) = nil
	}
	if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*137)) != nil {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*137)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*137)) = nil
	}
	if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*138)) != nil {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*138)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*138)) = nil
	}
	if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*139)) != nil {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*139)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*139)) = nil
	}
	if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*140)) != nil {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*140)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*140)) = nil
	}
	if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*141)) != nil {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*141)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*141)) = nil
	}
	if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*142)) != nil {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*142)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*142)) = nil
	}
	result = *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*143))
	if result != nil {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*143)))
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(unsafe.Pointer(nil))*143)) = nil
	}
	return result
}
func nox_server_mapRWObjectTOC_428B30() int32 {
	var (
		v1  int32
		v2  uint16
		v3  int32
		v4  int32
		v5  *byte
		i   int32
		v7  uint16
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 [256]byte
	)
	v11 = 1
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 2)
	if int32(int16(v11)) > 1 {
		return 0
	}
	sub_42BFB0()
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v9)), 2)
		for i = 0; int32(uint16(int16(i))) < int32(uint16(int16(v9))); i++ {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 2)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12[0])), uint32(uint8(int8(v8))))
			v12[uint8(int8(v8))] = 0
			if !nox_common_gameFlags_check_40A5C0(2) || nox_common_gameFlags_check_40A5C0(1) {
				v7 = uint16(int16(nox_xxx_getNameId_4E3AA0(&v12[0])))
			} else {
				v7 = uint16(int16(nox_xxx_getTTByNameSpriteMB_44CFC0(&v12[0])))
			}
			sub_42C310(int32(v7), uint16(int16(v10)))
		}
		return 1
	}
	sub_42BFE0()
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v1))), unsafe.Sizeof(uint16(0))*0)) = sub_42C300()
	v9 = v1
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v9)), 2)
	v2 = 0
	if nox_xxx_unitDefGetCount_4E3AC0() == 0 {
		return 1
	}
	v3 = 0
	for {
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v4))), unsafe.Sizeof(uint16(0))*0)) = sub_42C2E0(v3)
		v10 = v4
		if int32(uint16(int16(v4))) != 0 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 2)
			v5 = nox_xxx_getUnitNameByThingType_4E3A80(v3)
			*((*uint8)(unsafe.Pointer(&v8))) = uint8(int8(libc.StrLen(v5)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(v5)), uint32(uint8(int8(v8))))
		}
		v3 = int32(func() uint16 {
			p := &v2
			*p++
			return *p
		}())
		if uint32(v2) >= uint32(nox_xxx_unitDefGetCount_4E3AC0()) {
			break
		}
	}
	return 1
}
func nox_server_mapRWPolygons_428CD0(a1 int32) int32 {
	var (
		i   *byte
		v3  *byte
		j   uint32
		k   *byte
		v6  *byte
		v7  *byte
		v8  *byte
		v9  uint32
		v10 *uint8
		v11 *uint16
		v12 *uint8
		v13 *byte
		v14 int32
		v15 uint32
		v16 bool
		v17 *byte
		v18 float64
		v19 float64
		v20 float64
		v21 float64
		v22 *byte
		v23 *byte
		v24 *uint8
		v25 uint32
		v26 int32
		v27 int32
		v28 uint32
		v29 [2]float32
		v30 int32
		v31 int32
		v32 [12]byte
	)
	v30 = 0
	if a1 != 0 {
		return 1
	}
	v26 = 4
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v26)), 2)
	if int32(int16(v26)) > 4 {
		return 0
	}
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v25)), 4)
		v9 = 1
		if v25 >= 1 {
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v29[0])), 8)
				if nox_xxx_polygonSetAngle_420D40(*(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&v29[0]))), 4*0)), *(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&v29[1]))), 4*0)), v9, a1) == nil {
					return 0
				}
				if int32(int16(v26)) < 3 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v31)), 4)
				}
				if func() uint32 {
					p := &v9
					*p++
					return *p
				}() > v25 {
					break
				}
			}
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v25)), 4)
		v28 = 1
		if v25 >= 1 {
			for {
				v10 = sub_421230()
				if v10 == nil {
					return 0
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v27)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v10), 4)), uint32(uint8(int8(v27))))
				*(*uint8)(unsafe.Add(unsafe.Pointer(v10), int32(uint8(int8(v27)))+4)) = 0
				if int32(int16(v26)) >= 3 || (func() bool {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v31)), 4)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v32[0])), 0xC)
					*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 104)) = uint8(v32[0])
					*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 105)) = uint8(v32[4])
					*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 106)) = uint8(v32[8])
					return int32(int16(v26)) >= 3
				}()) {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
					*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 104)) = uint8(int8(a1))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
					*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 105)) = uint8(int8(a1))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
					*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 106)) = uint8(int8(a1))
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v10), 130)), 1)
				v11 = (*uint16)(unsafe.Add(unsafe.Pointer(v10), 128))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v10), 128)), 2)
				v12 = (*uint8)(alloc.Calloc1(int(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v10))), unsafe.Sizeof(uint16(0))*64)))), 4))
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*27))) = uint32(uintptr(unsafe.Pointer(v12)))
				if v12 == nil {
					return 0
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v12, uint32(int32(*v11)*4))
				sub_421040(int32(uintptr(unsafe.Pointer(v10))))
				v13 = nox_xxx_polygonGetAngle_421030(int32(**((**uint32)(unsafe.Add(unsafe.Pointer((**uint32)(unsafe.Pointer(v10))), unsafe.Sizeof((*uint32)(nil))*27)))))
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*22))) = uint32(int32(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v13))), unsafe.Sizeof(float32(0))*1)))))
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*23))) = uint32(int32(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v13))), unsafe.Sizeof(float32(0))*2)))))
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*24))) = uint32(int32(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v13))), unsafe.Sizeof(float32(0))*1)))))
				v14 = int32(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v13))), unsafe.Sizeof(float32(0))*2))))
				v15 = 1
				v16 = int32(*v11) <= 1
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*25))) = uint32(v14)
				if !v16 {
					for {
						v17 = nox_xxx_polygonGetAngle_421030(int32(*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*27))) + v15*4)))))
						v18 = float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v17))), unsafe.Sizeof(float32(0))*1))))
						v29[0] = *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v17))), unsafe.Sizeof(float32(0))*1)))
						if v18 >= float64(*((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v10))), 4*22)))) {
							v19 = float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v17))), unsafe.Sizeof(float32(0))*1))))
							v29[0] = *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v17))), unsafe.Sizeof(float32(0))*1)))
							if v19 > float64(*((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v10))), 4*24)))) {
								*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*24))) = uint32(int32(v29[0]))
							}
						} else {
							*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*22))) = uint32(int32(v29[0]))
						}
						v20 = float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v17))), unsafe.Sizeof(float32(0))*2))))
						v29[0] = *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v17))), unsafe.Sizeof(float32(0))*2)))
						if v20 >= float64(*((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v10))), 4*23)))) {
							v21 = float64(*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v17))), unsafe.Sizeof(float32(0))*2))))
							v29[0] = *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v17))), unsafe.Sizeof(float32(0))*2)))
							if v21 > float64(*((*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(v10))), 4*25)))) {
								*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*25))) = uint32(int32(v29[0]))
							}
						} else {
							*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*23))) = uint32(int32(v29[0]))
						}
						v15++
						if v15 >= uint32(*v11) {
							break
						}
					}
				}
				if int32(int16(v26)) >= 2 {
					v22 = *(**byte)(unsafe.Pointer(v10))
					nox_xxx_xferReadScriptHandler_4F5580(int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v10), 112))))), *(**byte)(unsafe.Pointer(v10)))
					if v22 != nil {
						v23 = (*byte)(unsafe.Add(unsafe.Pointer(v22), 128))
					} else {
						v23 = nil
					}
					nox_xxx_xferReadScriptHandler_4F5580(int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v10), 120))))), v23)
				}
				if int32(int16(v26)) >= 4 {
					v24 = (*uint8)(unsafe.Add(unsafe.Pointer(v10), 132))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v24, 4)
					if int32(*v24)&1 != 0 {
						v30++
					}
				}
				if func() uint32 {
					p := &v28
					*p++
					return *p
				}() > v25 {
					break
				}
			}
		}
		sub_4D72D0(v30)
		return 1
	}
	v25 = 0
	for i = nox_xxx_polygon_420CA0(); i != nil; v25++ {
		i = nox_xxx_polygon_420CD0((*uint32)(unsafe.Pointer(i)))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v25)), 4)
	v3 = nox_xxx_polygon_420CA0()
	for j = 0; j < v25; j++ {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(v3)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v3), 4)), 8)
		v3 = nox_xxx_polygon_420CD0((*uint32)(unsafe.Pointer(v3)))
	}
	v25 = 0
	for k = nox_xxx_polygonGetNext_4210A0(); k != nil; v25++ {
		k = sub_4210E0(int32(uintptr(unsafe.Pointer(k))))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v25)), 4)
	v6 = nox_xxx_polygonGetNext_4210A0()
	v28 = 0
	if v25 <= 0 {
		return 1
	}
	for {
		v7 = *(**byte)(unsafe.Pointer(v6))
		*((*uint8)(unsafe.Pointer(&v27))) = uint8(int8(libc.StrLen((*byte)(unsafe.Add(unsafe.Pointer(v6), 4)))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v27)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v6), 4)), uint32(uint8(int8(v27))))
		*((*uint8)(unsafe.Pointer(&a1))) = uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v6), 104)))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
		*((*uint8)(unsafe.Pointer(&a1))) = uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v6), 105)))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
		*((*uint8)(unsafe.Pointer(&a1))) = uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v6), 106)))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v6), 130)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v6), 128)), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(*((**uint8)(unsafe.Add(unsafe.Pointer((**uint8)(unsafe.Pointer(v6))), unsafe.Sizeof((*uint8)(nil))*27))), uint32(int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v6))), unsafe.Sizeof(uint16(0))*64))))*4))
		nox_xxx_xferReadScriptHandler_4F5580(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v6), 112))))), v7)
		if v7 != nil {
			v8 = (*byte)(unsafe.Add(unsafe.Pointer(v7), 128))
		} else {
			v8 = nil
		}
		nox_xxx_xferReadScriptHandler_4F5580(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v6), 120))))), v8)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v6), 132)), 4)
		v6 = sub_4210E0(int32(uintptr(unsafe.Pointer(v6))))
		v28++
		if v28 >= v25 {
			break
		}
	}
	return 1
}
func nox_server_mapRWAmbientData_429200() int32 {
	var (
		result int32
		v1     *byte
		v2     int32
		v3     [3]int32
	)
	v2 = 1
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v2)), 2)
	if int32(int16(v2)) < 1 {
		return 0
	}
	if nox_crypt_IsReadOnly() != 0 {
		if nox_crypt_IsReadOnly() == 1 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3[0])), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3[1])), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3[2])), 4)
			sub_469B90(&v3[0])
			if nox_common_gameFlags_check_40A5C0(2097154) {
				sub_4349C0((*uint32)(unsafe.Pointer(&v3[0])))
			}
		}
		result = 1
	} else {
		v1 = nox_xxx_getAmbientColor_469BB0()
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(v1)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 4)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 8)), 4)
		result = 1
	}
	return result
}
func nox_server_mapRWWindowWalls_4292C0(a1 *uint32) int32 {
	var (
		result int32
		v2     *uint32
		v3     *byte
		v4     *uint32
		v5     int32
		v6     int32
		v7     int2
		v9     int4
	)
	v5 = 2
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 2)
	if int32(int16(v5)) > 2 {
		return 0
	}
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 741336)), 2)
		v6 = 0
		if int32(*memmap.PtrUint16(0x5D4594, 741336)) > 0 {
			v2 = a1
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 8)
				if a1 != nil {
					v3 = nox_xxx_mapGetWallSize_426A70()
					sub_428170(unsafe.Pointer(a1), &v9)
					v7.field_0 += int32(uint32(v9.field_0/23) - *(*uint32)(unsafe.Pointer(v3)))
					v7.field_4 += int32(uint32(v9.field_4/23) - *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1))))
				}
				if nox_common_gameFlags_check_40A5C0(0x400000) {
					v4 = nox_xxx_cliWallGet_5042F0(v7.field_0, v7.field_4)
					if v4 != nil {
						v2 = (*uint32)(unsafe.Pointer(uintptr(*v4)))
					}
				} else {
					v2 = (*uint32)(nox_server_getWallAtGrid_410580(v7.field_0, v7.field_4))
				}
				if v2 != nil {
					*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 4))) |= 0x40
					if int32(int16(v5)) < 2 {
						*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 2))) = 0
					}
				}
				v6++
				if v6 >= int32(*memmap.PtrInt16(0x5D4594, 741336)) {
					break
				}
			}
		}
		result = 1
	} else {
		*memmap.PtrUint16(0x5D4594, 741336) = 0
		nox_xxx_wallForeachFn_410640(ccall.FuncAddr(sub_429450), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 741336)), 2)
		nox_xxx_wallForeachFn_410640(ccall.FuncAddr(sub_4294B0), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))
		result = 1
	}
	return result
}
func sub_429450(a1 *uint8, a2 *uint32) {
	var (
		v2 int32
		v3 int2
	)
	if a2 == nil || (func() int32 {
		v2 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 6)))
		v3.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 5))) * 23
		v3.field_4 = v2 * 23
		return nox_xxx_wallMath_427F30(&v3, (*int32)(unsafe.Pointer(a2)))
	}()) != 0 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))&0x40 != 0 {
			*memmap.PtrUint16(0x5D4594, 741336)++
		}
	}
}
func sub_4294B0(a1 *uint8, a2 *uint32) {
	var (
		v2 int32
		v3 int32
		v4 int2
	)
	if a2 == nil || (func() int32 {
		v2 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 6)))
		v4.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 5))) * 23
		v4.field_4 = v2 * 23
		return nox_xxx_wallMath_427F30(&v4, (*int32)(unsafe.Pointer(a2)))
	}()) != 0 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))&0x40 != 0 {
			v3 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 6)))
			v4.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 5)))
			v4.field_4 = v3
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 8)
		}
	}
}
func nox_xxx_wallBreakableCounterClear_429520() {
	*memmap.PtrUint32(0x5D4594, 741344) = 0
}
func nox_server_mapRWDestructableWalls_429530(a1 *uint32) int32 {
	var (
		result int32
		v2     *uint32
		v3     *byte
		v4     *uint32
		v5     int32
		v6     int32
		v7     int2
		v9     int4
	)
	v5 = 1
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 2)
	if int32(int16(v5)) > 1 {
		return 0
	}
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 741340)), 2)
		v6 = 0
		if int32(*memmap.PtrUint16(0x5D4594, 741340)) > 0 {
			v2 = a1
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 8)
				if a1 != nil {
					v3 = nox_xxx_mapGetWallSize_426A70()
					sub_428170(unsafe.Pointer(a1), &v9)
					v7.field_0 += int32(uint32(v9.field_0/23) - *(*uint32)(unsafe.Pointer(v3)))
					v7.field_4 += int32(uint32(v9.field_4/23) - *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1))))
				}
				if nox_common_gameFlags_check_40A5C0(0x400000) {
					v4 = nox_xxx_cliWallGet_5042F0(v7.field_0, v7.field_4)
					if v4 != nil {
						v2 = (*uint32)(unsafe.Pointer(uintptr(*v4)))
					}
				} else {
					v2 = (*uint32)(nox_server_getWallAtGrid_410580(v7.field_0, v7.field_4))
				}
				if v2 != nil {
					*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 4))) |= 8
					*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v2))), unsafe.Sizeof(uint16(0))*5))) = *memmap.PtrUint16(0x5D4594, 741344)
					*memmap.PtrUint32(0x5D4594, 741344)++
					if !nox_common_gameFlags_check_40A5C0(0x400000) {
						nox_xxx_wallBreackableListAdd_410840(int32(uintptr(unsafe.Pointer(v2))))
					}
				}
				v6++
				if v6 >= int32(*memmap.PtrInt16(0x5D4594, 741340)) {
					break
				}
			}
		}
		result = 1
	} else {
		*memmap.PtrUint16(0x5D4594, 741340) = 0
		nox_xxx_wallForeachFn_410640(ccall.FuncAddr(nox_xxx_wall_4296E0), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 741340)), 2)
		nox_xxx_wallForeachFn_410640(ccall.FuncAddr(sub_429740), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))
		result = 1
	}
	return result
}
func nox_xxx_wall_4296E0(a1 *uint8, a2 *uint32) {
	var (
		v2 int32
		v3 int2
	)
	if a2 == nil || (func() int32 {
		v2 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 6)))
		v3.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 5))) * 23
		v3.field_4 = v2 * 23
		return nox_xxx_wallMath_427F30(&v3, (*int32)(unsafe.Pointer(a2)))
	}()) != 0 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))&8 != 0 {
			*memmap.PtrUint16(0x5D4594, 741340)++
		}
	}
}
func sub_429740(a1 *uint8, a2 *uint32) {
	var (
		v2 int32
		v3 int32
		v4 int2
	)
	if a2 == nil || (func() int32 {
		v2 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 6)))
		v4.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 5))) * 23
		v4.field_4 = v2 * 23
		return nox_xxx_wallMath_427F30(&v4, (*int32)(unsafe.Pointer(a2)))
	}()) != 0 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))&8 != 0 {
			v3 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 6)))
			v4.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 5)))
			v4.field_4 = v3
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 8)
		}
	}
}
func nox_xxx_wallSecretCounterClear_4297B0() {
	*memmap.PtrUint32(0x5D4594, 741352) = 0
}
func nox_server_mapRWSecretWalls_4297C0(a1 *uint32) int32 {
	var (
		v2  *byte
		v3  *int32
		v4  *uint8
		v5  *byte
		v6  *int32
		v7  int32
		v8  int8
		v9  int32
		v10 int32 = 0
		v11 int32
		v12 int4
	)
	v9 = 2
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v9)), 2)
	if int32(int16(v9)) > 2 {
		return 0
	}
	if nox_crypt_IsReadOnly() == 0 {
		*memmap.PtrUint16(0x5D4594, 741348) = 0
		nox_xxx_wallForeachFn_410640(ccall.FuncAddr(sub_429A00), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 741348)), 2)
		nox_xxx_wallForeachFn_410640(ccall.FuncAddr(sub_429A60), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))))))
		return 1
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 741348)), 2)
	v11 = 0
	if int32(*memmap.PtrUint16(0x5D4594, 741348)) <= 0 {
		return 1
	}
	for {
		v2 = (*byte)(alloc.Calloc1(1, 0x20))
		v3 = (*int32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v2), 4))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 4)), 8)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 16)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 20)), 1)
		v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 21))
		*(*byte)(unsafe.Add(unsafe.Pointer(v2), 21)) = 0
		if int32(int16(v9)) >= 2 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 21)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 22)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 24)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 28)), 4)
		}
		if a1 != nil {
			v5 = nox_xxx_mapGetWallSize_426A70()
			sub_428170(unsafe.Pointer(a1), &v12)
			*v3 += int32(uint32(v12.field_0/23) - *(*uint32)(unsafe.Pointer(v5)))
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*2))) += uint32(v12.field_4/23) - *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*1)))
		}
		if !nox_common_gameFlags_check_40A5C0(0x400000) {
			v10 = int32(uintptr(nox_server_getWallAtGrid_410580(*v3, int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*2)))))))
			v7 = v10
		} else {
			v6 = (*int32)(unsafe.Pointer(nox_xxx_cliWallGet_5042F0(*v3, int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*2)))))))
			if v6 == nil {
				v7 = v10
			} else {
				v7 = *v6
				v10 = v7
			}
		}
		if v7 != 0 {
			v8 = int8(*(*uint8)(unsafe.Pointer(uintptr(v7 + 4))))
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 28))) = uint32(uintptr(unsafe.Pointer(v2)))
			*(*uint8)(unsafe.Pointer(uintptr(v7 + 4))) = uint8(int8(int32(v8) | 4))
			*(*uint16)(unsafe.Pointer(uintptr(v7 + 10))) = *memmap.PtrUint16(0x5D4594, 741352)
			*memmap.PtrUint32(0x5D4594, 741352)++
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*3))) = uint32(v7)
			if int32(*v4) == 0 {
				if *(*byte)(unsafe.Add(unsafe.Pointer(v2), 20))&8 != 0 {
					*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*7))) = math.MaxUint32
					*v4 = 3
					*(*byte)(unsafe.Add(unsafe.Pointer(v2), 22)) = 23
				} else {
					*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*7))) = 0
					*v4 = 1
					*(*byte)(unsafe.Add(unsafe.Pointer(v2), 22)) = 0
				}
			}
			if !nox_common_gameFlags_check_40A5C0(0x400000) {
				nox_xxx_wallSecretBlock_410760((*uint32)(unsafe.Pointer(v2)))
			}
		}
		v11++
		if v11 >= int32(*memmap.PtrInt16(0x5D4594, 741348)) {
			return 1
		}
	}
}
func sub_429A00(a1 *uint8, a2 *uint32) {
	var (
		v2 int32
		v3 int2
	)
	if a2 == nil || (func() int32 {
		v2 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 6)))
		v3.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 5))) * 23
		v3.field_4 = v2 * 23
		return nox_xxx_wallMath_427F30(&v3, (*int32)(unsafe.Pointer(a2)))
	}()) != 0 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))&4 != 0 {
			*memmap.PtrUint16(0x5D4594, 741348)++
		}
	}
}
func sub_429A60(a1 int32, a2 *uint32) {
	var (
		v2 int32
		v3 int32
		v4 *uint8
		v5 int2
	)
	if a2 == nil || (func() int32 {
		v2 = int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 6))))
		v5.field_0 = int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 5)))) * 23
		v5.field_4 = v2 * 23
		return nox_xxx_wallMath_427F30(&v5, (*int32)(unsafe.Pointer(a2)))
	}()) != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 4))))&4 != 0 {
			v3 = int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 6))))
			v4 = *(**uint8)(unsafe.Pointer(uintptr(a1 + 28)))
			v5.field_0 = int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 5))))
			v5.field_4 = v3
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 8)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 16)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 20)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 21)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 22)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 24)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 28)), 4)
		}
	}
}
func nox_server_mapRWWallMap_429B20(a1 *uint32) int32 {
	var (
		v2  *uint32
		v3  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 *uint8
		v11 *uint8
		v12 *nox_player_polygon_check_data
		v13 int32
		v14 int32
		v15 int8
		v16 int8
		v17 *uint8
		v18 int32
		v19 *uint8
		v20 *uint8
		v21 *uint8
		v22 int8
		v23 int8
		v24 int32
		v25 int32
		v26 int32
		v27 int32
		v28 int32
		v29 int32
		v30 int32
		v31 int32
		v32 int2
		v33 int4
	)
	v31 = nox_xxx_wallGet_426A30()
	if int32(*memmap.PtrUint8(0x5D4594, 741372)) == 0 {
		*memmap.PtrUint8(0x5D4594, 741372) = uint8(int8(nox_xxx_wallTileByName_410D60(internCStr("MagicWallSystemUseOnly"))))
	}
	nox_xxx_wallSecretCounterClear_4297B0()
	nox_xxx_wallBreakableCounterClear_429520()
	v28 = 7
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v28)), 2)
	if int32(int16(v28)) > 7 {
		return 0
	}
	if int32(int16(v28)) < 6 {
		return sub_42A150(int16(v28), a1)
	}
	v2 = a1
	if nox_crypt_IsReadOnly() == 0 {
		if a1 != nil {
			sub_428170(unsafe.Pointer(a1), &v33)
			*memmap.PtrUint32(0x5D4594, 741360) = uint32(v33.field_0 / 23)
			v3 = v33.field_8 / 23
			dword_5d4594_741356 = uint32(v33.field_8 / 23)
			*memmap.PtrUint32(0x5D4594, 741368) = uint32(v33.field_4 / 23)
			v5 = v33.field_C / 23
			dword_5d4594_741364 = uint32(v5)
		} else {
			*memmap.PtrUint32(0x5D4594, 741368) = 256
			*memmap.PtrUint32(0x5D4594, 741360) = 256
			dword_5d4594_741364 = 0
			dword_5d4594_741356 = 0
			nox_xxx_wallForeachFn_410640(ccall.FuncAddr(sub_42A0F0), nil)
			v3 = int32(dword_5d4594_741356)
			v5 = int32(dword_5d4594_741364)
		}
		v25 = int32(uint32(v3) - *memmap.PtrUint32(0x5D4594, 741360) + 1)
		v27 = int32(uint32(v5) - *memmap.PtrUint32(0x5D4594, 741368) + 1)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 741360)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 741368)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v25)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v27)), 4)
	v26 = 0
	v29 = 0
	if nox_crypt_IsReadOnly() != 0 {
		if v2 != nil {
			sub_428170(unsafe.Pointer(v2), &v33)
			v13 = int32(uint32(v33.field_0/23) - *memmap.PtrUint32(0x5D4594, 741360))
			*memmap.PtrUint32(0x5D4594, 741360) = uint32(v33.field_0 / 23)
			v29 = v13
			v14 = int32(uint32(v33.field_4/23) - *memmap.PtrUint32(0x5D4594, 741368))
			*memmap.PtrUint32(0x5D4594, 741368) = uint32(v33.field_4 / 23)
			v26 = v14
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 1)
		v15 = v22
		if int32(v22) == -1 {
			return 1
		}
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
			*((*uint8)(unsafe.Pointer(&v30))) = uint8(int8(v29 + int32(v15)))
			*((*uint8)(unsafe.Pointer(&a1))) = uint8(int8(v26 + int32(uint8(uintptr(unsafe.Pointer(a1))))))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v24)), 1)
			v16 = int8(int32(uint8(int8(v24))) >> 7)
			*((*uint8)(unsafe.Pointer(&v24))) = uint8(int8(v24 & math.MaxInt8))
			if nox_common_gameFlags_check_40A5C0(0x400000) {
				v17 = (*uint8)(unsafe.Pointer(uintptr(*sub_504290(int8(v30), int8(uintptr(unsafe.Pointer(a1)))))))
			} else {
				v18 = int32(uint8(int8(v30)))
				v19 = (*uint8)(nox_server_getWallAtGrid_410580(int32(uint8(int8(v30))), int32(uint8(uintptr(unsafe.Pointer(a1))))))
				v17 = v19
				if v19 != nil {
					if v31&1 != 0 {
						*v19 = nox_xxx_wall_42A6C0(*v19, uint8(int8(v24)))
					} else {
						*v19 = uint8(int8(v24))
					}
					goto LABEL_46
				}
				v17 = (*uint8)(nox_xxx_wallCreateAt_410250(v18, int32(uint8(uintptr(unsafe.Pointer(a1))))))
				if v17 == nil {
					return 0
				}
			}
			*v17 = uint8(int8(v24))
		LABEL_46:
			if int32(v16) != 0 {
				*(*uint8)(unsafe.Add(unsafe.Pointer(v17), 4)) |= 0x80
			}
			v20 = (*uint8)(unsafe.Add(unsafe.Pointer(v17), 1))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v17), 1)), 1)
			v21 = (*uint8)(unsafe.Add(unsafe.Pointer(v17), 2))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v17), 2)), 1)
			if v31&1 != 0 && int32(*v21) >= int32(nox_xxx_mapWallMaxVariation_410DD0(int32(*v20), int32(*v17), 0)) {
				*v21 = 0
			}
			*(*uint8)(unsafe.Add(unsafe.Pointer(v17), 7)) = nox_xxx_mapWallGetHpByTile_410E20(int32(*v20))
			if int32(uint16(int16(v28))) == 6 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v24)), 1)
				*(*uint8)(unsafe.Add(unsafe.Pointer(v17), 8)) = 1
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v17))), 4*3))) = 0
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v17), 8)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v24)), 1)
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v17))), 4*3))) = uint32(uint8(int8(v24)))
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 1)
			v15 = v22
			if int32(v22) == -1 {
				return 1
			}
		}
	}
	v6 = int32(*memmap.PtrUint32(0x5D4594, 741368))
	v26 = int32(*memmap.PtrUint32(0x5D4594, 741368))
	if *memmap.PtrUint32(0x5D4594, 741368) <= uint32(*memmap.PtrInt32(0x5D4594, 741368)+v27) {
		v7 = v25
		v8 = int32(*memmap.PtrUint32(0x5D4594, 741360))
		for {
			v9 = v8
			v29 = v8
			if v8 <= v8+v7 {
				for {
					v10 = (*uint8)(nox_server_getWallAtGrid_410580(v9, v26))
					v11 = v10
					if v10 != nil {
						if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 1))) != int32(*memmap.PtrUint8(0x5D4594, 741372)) {
							if v2 == nil || (func() int32 {
								v32.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 5))) * 23
								v32.field_4 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v10), 6))) * 23
								return nox_xxx_wallMath_427F30(&v32, (*int32)(unsafe.Pointer(v2)))
							}()) != 0 {
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v11), 5)), 1)
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v11), 6)), 1)
								if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v11), 4))) >= 0 {
									*((*uint8)(unsafe.Pointer(&v24))) = *v11
								} else {
									*((*uint8)(unsafe.Pointer(&v24))) = uint8(int8(int32(*v11) | 0x80))
								}
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v24)), 1)
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v11), 1)), 1)
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v11), 2)), 1)
								v32.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v11), 5)))*23 + 11
								v32.field_4 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v11), 6)))*23 + 11
								v12 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v32, 0)
								if v12 != nil || (func() *nox_player_polygon_check_data {
									v12 = (*nox_player_polygon_check_data)(unsafe.Pointer(sub_421990(&v32, 10.0, 0)))
									return v12
								}()) != nil {
									v23 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v12.field_0[32]))), 2)))
								} else {
									v23 = 100
								}
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v23)), 1)
								if nox_common_gameFlags_check_40A5C0(0x200000) {
									*((*uint8)(unsafe.Pointer(&v24))) = 0
								} else {
									*((*uint8)(unsafe.Pointer(&v24))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v11), 12))
								}
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v24)), 1)
								v2 = a1
								v9 = v29
							}
						}
					}
					v8 = int32(*memmap.PtrUint32(0x5D4594, 741360))
					v7 = v25
					v29 = func() int32 {
						p := &v9
						*p++
						return *p
					}()
					if v9 > *memmap.PtrInt32(0x5D4594, 741360)+v25 {
						break
					}
				}
				v6 = int32(*memmap.PtrUint32(0x5D4594, 741368))
			}
			v26++
			if v26 > v6+v27 {
				break
			}
		}
	}
	v22 = -1
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 1)
	return 1
}
func sub_42A0F0(a1 int32) int32 {
	var result int32
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 5)))) < *memmap.PtrInt32(0x5D4594, 741360) {
		*memmap.PtrUint32(0x5D4594, 741360) = uint32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 5))))
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 5)))) > *(*int32)(unsafe.Pointer(&dword_5d4594_741356)) {
		dword_5d4594_741356 = uint32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 5))))
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 6)))) < *memmap.PtrInt32(0x5D4594, 741368) {
		*memmap.PtrUint32(0x5D4594, 741368) = uint32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 6))))
	}
	result = int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 6))))
	if result > *(*int32)(unsafe.Pointer(&dword_5d4594_741364)) {
		dword_5d4594_741364 = uint32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 6))))
	}
	return result
}
func sub_42A150(a1 int16, a2 *uint32) int32 {
	var (
		v2  int32
		v3  *uint32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 *uint8
		v14 *nox_player_polygon_check_data
		v16 int32
		v17 int32
		v18 uint8
		v19 int8
		v20 **uint8
		v21 *uint8
		v22 *uint8
		v23 uint8
		v24 int16
		v25 *uint8
		v26 int8
		v27 int32
		v28 int32
		v29 int32
		v30 int32
		v31 int32
		v32 int2
		v33 int4
	)
	v2 = nox_xxx_wallGet_426A30()
	v3 = a2
	v30 = v2
	v4 = 0
	if nox_crypt_IsReadOnly() == 0 {
		if a2 != nil {
			sub_428170(unsafe.Pointer(a2), &v33)
			*memmap.PtrUint32(0x5D4594, 741360) = uint32(v33.field_0 / 23)
			v5 = v33.field_8 / 23
			dword_5d4594_741356 = uint32(v33.field_8 / 23)
			*memmap.PtrUint32(0x5D4594, 741368) = uint32(v33.field_4 / 23)
			v6 = v33.field_C / 23
			dword_5d4594_741364 = uint32(v33.field_C / 23)
		} else {
			*memmap.PtrUint32(0x5D4594, 741368) = 256
			*memmap.PtrUint32(0x5D4594, 741360) = 256
			dword_5d4594_741364 = 0
			dword_5d4594_741356 = 0
			nox_xxx_wallForeachFn_410640(ccall.FuncAddr(sub_42A0F0), nil)
			v5 = int32(dword_5d4594_741356)
			v6 = int32(dword_5d4594_741364)
		}
		v28 = int32(uint32(v5) - *memmap.PtrUint32(0x5D4594, 741360) + 1)
		v29 = int32(uint32(v6) - *memmap.PtrUint32(0x5D4594, 741368) + 1)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 741360)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 741368)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v28)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v29)), 4)
	if nox_crypt_IsReadOnly() == 0 {
		v7 = int32(*memmap.PtrUint32(0x5D4594, 741368))
		v8 = int32(*memmap.PtrUint32(0x5D4594, 741368))
		if *memmap.PtrUint32(0x5D4594, 741368) > uint32(*memmap.PtrInt32(0x5D4594, 741368)+v29) {
			return 1
		}
		v9 = v28
		v10 = int32(*memmap.PtrUint32(0x5D4594, 741360))
		for {
			v11 = v10
			if v10 > v10+v9 {
				goto LABEL_27
			}
			for {
				v12 = int32(uintptr(nox_server_getWallAtGrid_410580(v11, v8)))
				v13 = (*uint8)(unsafe.Pointer(uintptr(v12)))
				if v3 != nil {
					if v12 == 0 {
						*((*uint8)(unsafe.Pointer(&v27))) = math.MaxUint8
						goto LABEL_19
					}
					v32.field_0 = int32(*(*uint8)(unsafe.Pointer(uintptr(v12 + 5)))) * 23
					v32.field_4 = int32(*(*uint8)(unsafe.Pointer(uintptr(v12 + 6)))) * 23
					if nox_xxx_wallMath_427F30(&v32, (*int32)(unsafe.Pointer(v3))) == 0 {
						v13 = nil
						*((*uint8)(unsafe.Pointer(&v27))) = math.MaxUint8
						goto LABEL_19
					}
				}
				if v13 == nil {
					*((*uint8)(unsafe.Pointer(&v27))) = math.MaxUint8
				} else if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v13), 4))) >= 0 {
					*((*uint8)(unsafe.Pointer(&v27))) = *v13
				} else {
					*((*uint8)(unsafe.Pointer(&v27))) = uint8(int8(int32(*v13) | 0x80))
				}
			LABEL_19:
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v27)), 1)
				if int32(uint8(int8(v27))) != math.MaxUint8 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v13), 1)), 1)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v13), 2)), 1)
					v32.field_0 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v13), 5)))*23 + 11
					v32.field_4 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v13), 6)))*23 + 11
					v14 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v32, 0)
					if v14 != nil || (func() *nox_player_polygon_check_data {
						v14 = (*nox_player_polygon_check_data)(unsafe.Pointer(sub_421990(&v32, 10.0, 0)))
						return v14
					}()) != nil {
						v26 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v14.field_0[32]))), 2)))
					} else {
						v26 = 1
					}
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v26)), 1)
					*((*uint8)(unsafe.Pointer(&a1))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v13), 12))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
				}
				v10 = int32(*memmap.PtrUint32(0x5D4594, 741360))
				v9 = v28
				v11++
				if v11 > *memmap.PtrInt32(0x5D4594, 741360)+v28 {
					break
				}
			}
			v7 = int32(*memmap.PtrUint32(0x5D4594, 741368))
		LABEL_27:
			v8++
			if v8 > v7+v29 {
				break
			}
		}
		return 1
	}
	if v3 != nil {
		sub_428170(unsafe.Pointer(v3), &v33)
		*memmap.PtrUint32(0x5D4594, 741360) = uint32(v33.field_0 / 23)
		*memmap.PtrUint32(0x5D4594, 741368) = uint32(v33.field_4 / 23)
	}
	v31 = 0
	if v29 < 0 {
		return 1
	}
	v16 = v28
	for {
		v17 = 0
		if v16 >= 0 {
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v27)), 1)
				if int32(uint8(int8(v27))) != math.MaxUint8 {
					v18 = uint8(int8(v27))
					*((*uint8)(unsafe.Pointer(&v27))) = uint8(int8(v27 & math.MaxInt8))
					v19 = int8(int32(v18) >> 7)
					if !nox_common_gameFlags_check_40A5C0(0x400000) {
						v22 = (*uint8)(nox_server_getWallAtGrid_410580(int32(uint32(v17)+*memmap.PtrUint32(0x5D4594, 741360)), int32(uint32(v4)+*memmap.PtrUint32(0x5D4594, 741368))))
						v21 = v22
						if v22 != nil {
							if v30&1 != 0 {
								v23 = nox_xxx_wall_42A6C0(*v22, uint8(int8(v27)))
							} else {
								v23 = uint8(int8(v27))
							}
						} else {
							v21 = (*uint8)(nox_xxx_wallCreateAt_410250(int32(uint32(v17)+*memmap.PtrUint32(0x5D4594, 741360)), int32(uint32(v4)+*memmap.PtrUint32(0x5D4594, 741368))))
							if v21 == nil {
								return 0
							}
							v23 = uint8(int8(v27))
						}
						*v21 = v23
					} else {
						v20 = (**uint8)(unsafe.Pointer(sub_504290(int8(v17+int32(*memmap.PtrUint8(0x5D4594, 741360))), int8(v4+int32(*memmap.PtrUint8(0x5D4594, 741368))))))
						v21 = *v20
						**v20 = uint8(int8(v27))
					}
					if int32(v19) != 0 {
						*(*uint8)(unsafe.Add(unsafe.Pointer(v21), 4)) |= 0x80
					}
					v24 = a1
					if int32(a1) < 2 {
						*(*uint8)(unsafe.Add(unsafe.Pointer(v21), 1)) = 0
						*(*uint8)(unsafe.Add(unsafe.Pointer(v21), 7)) = nox_xxx_mapWallGetHpByTile_410E20(0)
						*(*uint8)(unsafe.Add(unsafe.Pointer(v21), 8)) = 1
					} else {
						v25 = (*uint8)(unsafe.Add(unsafe.Pointer(v21), 1))
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v21), 1)), 1)
						if int32(v24) >= 3 {
							nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v21), 2)), 1)
						} else {
							sub_42A650(v21)
						}
						if v30&1 != 0 && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v21), 2))) >= int32(nox_xxx_mapWallMaxVariation_410DD0(int32(*v25), int32(*v21), 0)) {
							*(*uint8)(unsafe.Add(unsafe.Pointer(v21), 2)) = 0
						}
						*(*uint8)(unsafe.Add(unsafe.Pointer(v21), 7)) = nox_xxx_mapWallGetHpByTile_410E20(int32(*v25))
						if int32(v24) < 4 {
							*(*uint8)(unsafe.Add(unsafe.Pointer(v21), 8)) = 1
						} else {
							nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v21), 8)), 1)
						}
						*((*uint8)(unsafe.Pointer(&a2))) = 0
						if int32(v24) >= 5 {
							nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
						}
						v4 = v31
						*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v21))), 4*3))) = uint32(uint8(uintptr(unsafe.Pointer(a2))))
					}
				}
				v16 = v28
				v17++
				if v17 > v28 {
					break
				}
			}
		}
		v4++
		v31 = v4
		if v4 > v29 {
			break
		}
	}
	return 1
}
func sub_42A650(a1 *uint8) int32 {
	var (
		v1     uint8
		result int32
	)
	v1 = *a1
	*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 2)) = 0
	if int32(v1) == 0 {
		*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 2)) = uint8(int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 5))) % 3))
	}
	if int32(v1) == 1 {
		*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 2)) = uint8(int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 5))) % 3))
	}
	result = int32(uintptr(nox_xxx_getWallSprite_46A3B0(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 1))), int32(v1), int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 2))), (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))>>2)&2)))
	if result == 0 {
		*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 2)) = 0
	}
	return result
}
func nox_xxx_wall_42A6C0(a1 uint8, a2 uint8) uint8 {
	return *memmap.PtrUint8(0x587000, uintptr(a1)*13+71276+uintptr(a2))
}
func nox_server_mapRWMapInfo_42A6E0() int32 {
	var vers int32 = 3
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&vers)), 2)
	if vers > 3 {
		return 0
	}
	if vers >= 1 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 2408)), 64)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 2472)), 512)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 2984)), 16)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3000)), 64)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3064)), 64)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3128)), 128)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3256)), 128)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3384)), 256)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3640)), 128)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3768)), 32)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3800)), 4)
		if vers == 2 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3804)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3805)), 1)
		} else if nox_crypt_IsReadOnly() == 1 {
			*memmap.PtrUint8(0x973F18, 3804) = 2
			*memmap.PtrUint8(0x973F18, 3805) = 16
		}
	}
	if vers < 3 {
		*memmap.PtrUint8(0x973F18, 3806) = *memmap.PtrUint8(0x5D4594, 741376)
		*memmap.PtrUint8(0x973F18, 3838) = *memmap.PtrUint8(0x5D4594, 741380)
	} else {
		var v2 int32 = int32(libc.StrLen((*byte)(memmap.PtrOff(0x973F18, 3806))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v2)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3806)), uint32(v2))
		*memmap.PtrUint8(0x973F18, uintptr(v2+3806)) = 0
		v2 = int32(libc.StrLen((*byte)(memmap.PtrOff(0x973F18, 3838))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v2)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x973F18, 3838)), uint32(v2))
		*memmap.PtrUint8(0x973F18, uintptr(v2+3838)) = 0
	}
	return 1
}
func sub_42A8B0(a1 *uint8, a2 *int32) *uint16 {
	var (
		v2     int32
		v3     *uint8
		v4     *uint8
		result *uint16
		v6     int32
		v7     unsafe.Pointer
		v8     int32
		v9     *uint16
		v10    [12]uint8
	)
	*(*uint16)(unsafe.Pointer(&v10[0])) = 0
	*(*uint16)(unsafe.Pointer(&v10[2])) = 0
	v2 = *a2
	*(*uint32)(unsafe.Pointer(&v10[4])) = 0
	v3 = (*uint8)(alloc.Calloc1(int(v2), 2))
	sub_42A970(a1, v3, a2)
	v4 = sub_42AC50(v3, (*uint32)(unsafe.Pointer(a2)))
	if v3 != nil {
		alloc.Free(v3)
	}
	if v4 != nil {
		v6 = *a2
		v7 = alloc.Calloc1(1, 0x10)
		if v7 != nil {
			v8 = sub_42C910(int32(uintptr(v7)), (*byte)(memmap.PtrOff(0x587000, 71480)), unsafe.Pointer(v4), uint16(int16(v6)))
		} else {
			v8 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v10[0])), v8)
		alloc.Free(v4)
		v9 = sub_42C480((*uint32)(unsafe.Pointer(&v10[0])), (*uint32)(unsafe.Pointer(a2)))
		sub_42C330((*uint32)(unsafe.Pointer(&v10[0])))
		result = v9
	} else {
		sub_42C330((*uint32)(unsafe.Pointer(&v10[0])))
		result = nil
	}
	return result
}
func sub_42A970(a1 *uint8, a2 *uint8, a3 *int32) int32 {
	var (
		v3     int32
		v4     int8
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     *int32
		v10    *uint8
		v11    int32
		v12    int8
		result int32
		v14    int32
		v15    int32
		v16    int32
		v17    int8
		v18    uint8
		v19    [256]int32
	)
	v3 = 0
	v4 = 1
	*(*[256]int32)(unsafe.Pointer(&v19[0])) = [256]int32{}
	v18 = 1
	v5 = *a3
	if *a3 > 0 {
		for {
			v6 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), func() int32 {
				p := &v3
				x := *p
				*p++
				return x
			}())))
			v19[v6]++
			if v3 >= v5 {
				break
			}
		}
	}
	v7 = v19[0]
	v17 = 0
	v8 = 0
	v9 = &v19[0]
	for *v9 != 0 {
		if *v9 < v7 {
			v7 = *v9
			v17 = int8(v8)
		}
		v8++
		v9 = (*int32)(unsafe.Add(unsafe.Pointer(v9), 4*1))
		if v8 >= 256 {
			goto LABEL_10
		}
	}
	v17 = int8(v8)
LABEL_10:
	v10 = a1
	v11 = 1
	*a2 = uint8(v17)
	v12 = int8(*a1)
	result = 1
	v14 = *a3
	if *a3 < 1 {
		*a3 = 1
	} else {
		for {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v10), v11))) != int32(v12) || v11 >= v14 {
				if int32(uint8(v4)) <= 3 {
					if int32(v18) > 0 {
						v16 = int32(v18)
						for {
							if int32(v12) == int32(v17) {
								*(*uint8)(unsafe.Add(unsafe.Pointer(a2), func() int32 {
									p := &result
									x := *p
									*p++
									return x
								}())) = uint8(v12)
							}
							*(*uint8)(unsafe.Add(unsafe.Pointer(a2), func() int32 {
								p := &result
								x := *p
								*p++
								return x
							}())) = uint8(v12)
							v16--
							if v16 == 0 {
								break
							}
						}
					}
				} else {
					*(*uint8)(unsafe.Add(unsafe.Pointer(a2), result)) = uint8(v17)
					v15 = result + 1
					*(*uint8)(unsafe.Add(unsafe.Pointer(a2), func() int32 {
						p := &v15
						x := *p
						*p++
						return x
					}())) = uint8(v4)
					*(*uint8)(unsafe.Add(unsafe.Pointer(a2), v15)) = uint8(v12)
					result = v15 + 1
				}
				v10 = a1
				v4 = 1
				v12 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), v11)))
			} else {
				v4++
			}
			v11++
			v18 = uint8(v4)
			v14 = *a3
			if v11 > *a3 {
				break
			}
		}
		*a3 = result
	}
	return result
}
func sub_42AAA0(a1 *int32) float64 {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  *uint8
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v13 int32
	)
	if *a1 < 0 || *memmap.PtrUint32(0x5D4594, 741656) == 0 {
		*memmap.PtrUint32(0x5D4594, 741656) = 1
		v1 = *a1
		if *a1 < 0 {
			v1 = -v1
		}
		v2 = 1
		v3 = 21
		v4 = int32((161803398 - uint32(v1)) % 1000000000)
		*memmap.PtrUint32(0x5D4594, 741604) = (161803398 - uint32(v1)) % 1000000000
		for {
			*memmap.PtrUint32(0x5D4594, uintptr((v3%55)*4)+741384) = uint32(v2)
			v2 = int32(uint32(v4-v2) + (func() uint32 {
				if v4-v2 < 0 {
					return 0x3B9ACA00
				}
				return 0
			}()))
			v4 = int32(*memmap.PtrUint32(0x5D4594, uintptr((v3%55)*4)+741384))
			v3 += 21
			if v3 > 1134 {
				break
			}
		}
		v5 = 4
		for {
			v6 = 1
			v7 = (*uint8)(memmap.PtrOff(0x5D4594, 741388))
			for {
				v8 = int32(*(*uint32)(unsafe.Pointer(v7)) - *memmap.PtrUint32(0x5D4594, uintptr(((v6+30)%55)*4)+741388))
				*(*uint32)(unsafe.Pointer(v7)) = uint32(v8)
				if v8 < 0 {
					*(*uint32)(unsafe.Pointer(v7)) = uint32(v8) + 1000000000
				}
				v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 4))
				v6++
				if int32(uintptr(unsafe.Pointer(v7))) > int32(uintptr(memmap.PtrOff(0x5D4594, 741604))) {
					break
				}
			}
			v5--
			if v5 == 0 {
				break
			}
		}
		dword_5d4594_741648 = 0
		dword_5d4594_741652 = 31
		*a1 = 1
	}
	v9 = int32(func() uint32 {
		p := &dword_5d4594_741648
		*p++
		return *p
	}())
	if dword_5d4594_741648 == 56 {
		v9 = 1
		dword_5d4594_741648 = 1
	}
	v10 = int32(func() uint32 {
		p := &dword_5d4594_741652
		*p++
		return *p
	}())
	if dword_5d4594_741652 == 56 {
		v10 = 1
		dword_5d4594_741652 = 1
	}
	v11 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v9*4)+741384) - *memmap.PtrUint32(0x5D4594, uintptr(v10*4)+741384))
	v13 = v11
	if v11 < 0 {
		v11 += 1000000000
		v13 = v11
	}
	*memmap.PtrUint32(0x5D4594, uintptr(v9*4)+741384) = uint32(v11)
	return float64(v13) * *mem_getDoublePtr(0x581450, 8368)
}
func sub_42ABF0(a1 int32, a2 int32, a3 int32) {
	var (
		v3 float64
		i  int32
	)
	if a3 > 0 {
		a3 = -a3
	}
	v3 = sub_42AAA0(&a3)
	for i = 0; i < a2; i++ {
		var v5 int32 = int32(v3 * 255.0)
		if v5 < 0 {
			v5 = -v5
		}
		*(*uint8)(unsafe.Pointer(uintptr(i + a1))) = uint8(int8(v5))
		v3 = sub_42AAA0(&a3)
	}
}
func sub_42AC50(a1 *uint8, a2 *uint32) *uint8 {
	var (
		v2     *uint32
		v3     unsafe.Pointer
		v4     uint32
		v5     *uint8
		result *uint8
		v7     libc.Time
		v8     int32
		v9     uint32
		v10    libc.Time
		v11    uint8
		v12    int32
		v13    int32
		v14    *uint8
		v15    int32
		v16    int8
		v17    int32
		v18    unsafe.Pointer
		v19    libc.Time
		lpMem  unsafe.Pointer
		v21    int32
		v22    uint32
		v23    float32
		v24    uint8
	)
	v2 = a2
	v19 = 0
	v3 = alloc.Calloc1(1, uintptr(*a2))
	v4 = *a2 + 5
	lpMem = v3
	v5 = (*uint8)(alloc.Calloc1(1, uintptr(v4)))
	if int32(*a2) >= 15 {
		v7 = libc.GetTime(nil)
		v8 = int32(v7)
		if v7 > 0 {
			v8 = int32(-v7)
		}
		v9 = cnet.Htonl(uint32(v8))
		v17 = int32(*a2)
		v22 = v9
		sub_42ABF0(int32(uintptr(v3)), v17, v8)
		v10 = libc.GetTime(nil)
		v19 = v10
		if v10 > 0 {
			v19 = -v10
		}
		if int32(*a2) >= 241 {
			v23 = 241.0
		} else {
			v23 = float32(float64(int32(*a2 - 14)))
		}
		v11 = uint8(uint64(int64(sub_42AAA0((*int32)(unsafe.Pointer(&v19)))*float64(v23))) + 10)
		v12 = 0
		v13 = 0
		v24 = v11
		if int32(*v2) > 0 {
			v21 = int32(v11)
			v14 = a1
			v15 = int32(uintptr(unsafe.Pointer((*uint8)(lpMem))) - uintptr(unsafe.Pointer(a1)))
			for {
				if v13 == 5 {
					*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 5)) = v11
					v13 = 6
				}
				if v13 == v21 {
					*(*uint32)(unsafe.Add(unsafe.Pointer(v5), v13)) = v22
					v13 += 4
				}
				v16 = int8(int32(*v14) ^ int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v14), v15))))
				v13++
				v12++
				v14 = (*uint8)(unsafe.Add(unsafe.Pointer(v14), 1))
				*(*uint8)(unsafe.Add(unsafe.Pointer(v5), v13-1)) = uint8(v16)
				if v12 >= int32(*v2) {
					break
				}
				v11 = v24
			}
		}
		v18 = lpMem
		*v2 += 5
		alloc.FreePtr(v18)
		result = v5
	} else {
		*a2 = 4294967294
		alloc.FreePtr(v3)
		alloc.Free(v5)
		result = nil
	}
	return result
}
func sub_42ADA0(a1 int32, a2 int32, a3 int16, a4 *uint32) *uint16 {
	var (
		v4   int32
		v5   int32
		v6   unsafe.Pointer
		v7   int32
		v8   int32
		v9   unsafe.Pointer
		v10  int32
		v11  int32
		v12  unsafe.Pointer
		v13  int32
		v14  int32
		v15  unsafe.Pointer
		v16  int32
		v17  unsafe.Pointer
		v18  int32
		v19  int32
		v20  unsafe.Pointer
		v21  int32
		v22  int32
		v23  unsafe.Pointer
		v24  int32
		v25  unsafe.Pointer
		v26  int32
		v27  int32
		v28  unsafe.Pointer
		v29  int32
		v30  int32
		v31  unsafe.Pointer
		v32  int32
		v33  int32
		v34  unsafe.Pointer
		v35  int32
		v36  int32
		v37  unsafe.Pointer
		v38  int32
		v39  unsafe.Pointer
		v40  int32
		v41  unsafe.Pointer
		v42  int32
		v43  unsafe.Pointer
		v44  int32
		v45  unsafe.Pointer
		v46  int32
		v47  unsafe.Pointer
		v48  int32
		v49  int32
		v50  unsafe.Pointer
		v51  int32
		v52  int32
		v53  unsafe.Pointer
		v54  int32
		v55  int32
		v56  unsafe.Pointer
		v57  int32
		v58  int32
		v59  unsafe.Pointer
		v60  int32
		v61  unsafe.Pointer
		v62  int32
		v63  unsafe.Pointer
		v64  int32
		v65  unsafe.Pointer
		v66  int32
		v67  int32
		v68  unsafe.Pointer
		v69  int32
		v70  int32
		v71  unsafe.Pointer
		v72  int32
		v73  unsafe.Pointer
		v74  int32
		v75  unsafe.Pointer
		v76  int32
		v77  unsafe.Pointer
		v78  int32
		v79  unsafe.Pointer
		v80  int32
		v81  unsafe.Pointer
		v82  int32
		v83  int32
		v84  int8
		v85  unsafe.Pointer
		v86  int32
		v87  unsafe.Pointer
		v88  int32
		v89  int16
		v90  unsafe.Pointer
		v91  int32
		v92  int32
		v93  *byte
		v94  unsafe.Pointer
		v95  int32
		v96  int32
		v97  unsafe.Pointer
		v98  int32
		v99  int32
		v100 unsafe.Pointer
		v101 int32
		v102 unsafe.Pointer
		v103 int32
		v104 unsafe.Pointer
		v105 int32
		v106 int32
		v107 unsafe.Pointer
		v108 int32
		v109 unsafe.Pointer
		v110 int32
		v111 unsafe.Pointer
		v112 unsafe.Pointer
		v113 int32
		v114 int32
		v115 *uint16
		v117 int8
		v118 [12]byte
		v119 int8
		v120 int8
		v121 int8
		v122 int8
		v123 int8
		v124 int8
		v125 int8
		v126 int8
		v127 int8
		v128 int8
		v129 int8
	)
	v4 = a1
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
	*(*uint16)(unsafe.Pointer(&v118[0])) = 0
	*(*uint16)(unsafe.Pointer(&v118[2])) = 0
	*(*uint32)(unsafe.Pointer(&v118[4])) = 0
	v6 = alloc.Calloc1(1, 0x10)
	if v6 != nil {
		v7 = sub_42C8B0(int32(uintptr(v6)), internCStr("MXPL"), int8(v5))
	} else {
		v7 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v7)
	v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
	v9 = alloc.Calloc1(1, 0x10)
	if v9 != nil {
		v10 = sub_42C8B0(int32(uintptr(v9)), internCStr("IDNO"), int8(v8))
	} else {
		v10 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v10)
	v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	v12 = alloc.Calloc1(1, 0x10)
	if v12 != nil {
		v13 = sub_42C8B0(int32(uintptr(v12)), internCStr("GSKU"), int8(v11))
	} else {
		v13 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v13)
	v14 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 20))))
	v15 = alloc.Calloc1(1, 0x10)
	if v15 != nil {
		v16 = sub_42C8B0(int32(uintptr(v15)), internCStr("GSTY"), int8(v14))
	} else {
		v16 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v16)
	v119 = int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 24))))
	v17 = alloc.Calloc1(1, 0x10)
	if v17 != nil {
		v18 = sub_42C7F0(int32(uintptr(v17)), internCStr("CLGM"), v119)
	} else {
		v18 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v18)
	v19 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 32))))
	v20 = alloc.Calloc1(1, 0x10)
	if v20 != nil {
		v21 = sub_42C8B0(int32(uintptr(v20)), internCStr("LIMT"), int8(v19))
	} else {
		v21 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v21)
	v22 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 36))))
	v23 = alloc.Calloc1(1, 0x10)
	if v23 != nil {
		v24 = sub_42C8B0(int32(uintptr(v23)), internCStr("TLMT"), int8(v22))
	} else {
		v24 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v24)
	v120 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 40))))
	v25 = alloc.Calloc1(1, 0x10)
	if v25 != nil {
		v26 = sub_42C7F0(int32(uintptr(v25)), internCStr("RSTC"), v120)
	} else {
		v26 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v26)
	v27 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 44))))
	v28 = alloc.Calloc1(1, 0x10)
	if v28 != nil {
		v29 = sub_42C8B0(int32(uintptr(v28)), internCStr("MINE"), int8(v27))
	} else {
		v29 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v29)
	v30 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 48))))
	v31 = alloc.Calloc1(1, 0x10)
	if v31 != nil {
		v32 = sub_42C8B0(int32(uintptr(v31)), internCStr("MAXE"), int8(v30))
	} else {
		v32 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v32)
	v33 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 52))))
	v34 = alloc.Calloc1(1, 0x10)
	if v34 != nil {
		v35 = sub_42C8B0(int32(uintptr(v34)), internCStr("MINP"), int8(v33))
	} else {
		v35 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v35)
	v36 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 56))))
	v37 = alloc.Calloc1(1, 0x10)
	if v37 != nil {
		v38 = sub_42C8B0(int32(uintptr(v37)), internCStr("MAXP"), int8(v36))
	} else {
		v38 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v38)
	v121 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 60))))
	v39 = alloc.Calloc1(1, 0x10)
	if v39 != nil {
		v40 = sub_42C7F0(int32(uintptr(v39)), internCStr("VIDM"), v121)
	} else {
		v40 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v40)
	v122 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 61))))
	v41 = alloc.Calloc1(1, 0x10)
	if v41 != nil {
		v42 = sub_42C7F0(int32(uintptr(v41)), internCStr("SVRS"), v122)
	} else {
		v42 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v42)
	v123 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 25))))
	v43 = alloc.Calloc1(1, 0x10)
	if v43 != nil {
		v44 = sub_42C7F0(int32(uintptr(v43)), internCStr("NTMS"), v123)
	} else {
		v44 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v44)
	v45 = alloc.Calloc1(1, 0x10)
	if v45 != nil {
		v46 = sub_42C8E0(int32(uintptr(v45)), internCStr("SCEN"), (*byte)(unsafe.Pointer(uintptr(v4+96))))
	} else {
		v46 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v46)
	v47 = alloc.Calloc1(1, 0x10)
	if v47 != nil {
		v48 = sub_42C8E0(int32(uintptr(v47)), internCStr("GNAM"), (*byte)(unsafe.Pointer(uintptr(v4+352))))
	} else {
		v48 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v48)
	v49 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 64))))
	v50 = alloc.Calloc1(1, 0x10)
	if v50 != nil {
		v51 = sub_42C8B0(int32(uintptr(v50)), internCStr("SPL1"), int8(v49))
	} else {
		v51 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v51)
	v52 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 68))))
	v53 = alloc.Calloc1(1, 0x10)
	if v53 != nil {
		v54 = sub_42C8B0(int32(uintptr(v53)), internCStr("SPL2"), int8(v52))
	} else {
		v54 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v54)
	v55 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 72))))
	v56 = alloc.Calloc1(1, 0x10)
	if v56 != nil {
		v57 = sub_42C8B0(int32(uintptr(v56)), internCStr("SPL3"), int8(v55))
	} else {
		v57 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v57)
	v58 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 88))))
	v59 = alloc.Calloc1(1, 0x10)
	if v59 != nil {
		v60 = sub_42C8B0(int32(uintptr(v59)), internCStr("ARMR"), int8(v58))
	} else {
		v60 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v60)
	v124 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 84))))
	v61 = alloc.Calloc1(1, 0x10)
	if v61 != nil {
		v62 = sub_42C7F0(int32(uintptr(v61)), internCStr("WPN1"), v124)
	} else {
		v62 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v62)
	v125 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 85))))
	v63 = alloc.Calloc1(1, 0x10)
	if v63 != nil {
		v64 = sub_42C7F0(int32(uintptr(v63)), internCStr("WPN2"), v125)
	} else {
		v64 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v64)
	v126 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 86))))
	v65 = alloc.Calloc1(1, 0x10)
	if v65 != nil {
		v66 = sub_42C7F0(int32(uintptr(v65)), internCStr("WPN3"), v126)
	} else {
		v66 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v66)
	v67 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 92))))
	v68 = alloc.Calloc1(1, 0x10)
	if v68 != nil {
		v69 = sub_42C8B0(int32(uintptr(v68)), internCStr("STAF"), int8(v67))
	} else {
		v69 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v69)
	v70 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 28))))
	v71 = alloc.Calloc1(1, 0x10)
	if v71 != nil {
		v72 = sub_42C8B0(int32(uintptr(v71)), internCStr("DURA"), int8(v70))
	} else {
		v72 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v72)
	v73 = alloc.Calloc1(1, 0x10)
	if v73 != nil {
		v74 = sub_42C7F0(int32(uintptr(v73)), internCStr("FINI"), 1)
	} else {
		v74 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v74)
	v127 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 26))))
	v75 = alloc.Calloc1(1, 0x10)
	if v75 != nil {
		v76 = sub_42C7F0(int32(uintptr(v75)), internCStr("TRNY"), v127)
	} else {
		v76 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v76)
	switch a2 {
	case 0:
		*memmap.PtrUint32(0x5D4594, 741668) = 0
		v77 = alloc.Calloc1(1, 0x10)
		if v77 != nil {
			v78 = sub_42C8B0(int32(uintptr(v77)), internCStr("SEQU"), 0)
		} else {
			v78 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v78)
		v79 = alloc.Calloc1(1, 0x10)
		if v79 != nil {
			v80 = sub_42C7F0(int32(uintptr(v79)), internCStr("ENDF"), 0)
		} else {
			v80 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v80)
		v81 = alloc.Calloc1(1, 0x10)
		if v81 != nil {
			v82 = sub_42C820(int32(uintptr(v81)), (*byte)(memmap.PtrOff(0x587000, 71872)), -1)
			sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v82)
			break
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), 0)
	case 2:
		v83 = int32(*memmap.PtrUint32(0x5D4594, 741668) + 1)
		*memmap.PtrUint32(0x5D4594, 741668) = uint32(v83)
		v84 = int8(v83)
		v85 = alloc.Calloc1(1, 0x10)
		if v85 != nil {
			v86 = sub_42C8B0(int32(uintptr(v85)), internCStr("SEQU"), v84)
		} else {
			v86 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v86)
		v87 = alloc.Calloc1(1, 0x10)
		if v87 != nil {
			v88 = sub_42C7F0(int32(uintptr(v87)), internCStr("ENDF"), 1)
		} else {
			v88 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v88)
		v89 = int16(*(*uint16)(unsafe.Pointer(uintptr(v4 + 6))))
		v90 = alloc.Calloc1(1, 0x10)
		if v90 != nil {
			v91 = sub_42C820(int32(uintptr(v90)), (*byte)(memmap.PtrOff(0x587000, 71896)), int8(v89))
		} else {
			v91 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v91)
		v92 = 0
		for *memmap.PtrUint32(0x5D4594, 741660) = 0; v92 < int32(*(*int16)(unsafe.Pointer(uintptr(v4 + 6)))); *memmap.PtrUint32(0x5D4594, 741660) = uint32(v92) {
			*memmap.PtrUint8(0x587000, 71491) = uint8(int8(v92 + 48))
			v93 = *(**byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 608))) + uint32(v92*4))))
			v94 = alloc.Calloc1(1, 0x10)
			if v94 != nil {
				v95 = sub_42C8E0(int32(uintptr(v94)), internCStr("LGL?"), v93)
			} else {
				v95 = 0
			}
			sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v95)
			*memmap.PtrUint8(0x587000, 71499) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			v96 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 612))) + *memmap.PtrUint32(0x5D4594, 741660)*4))))
			v97 = alloc.Calloc1(1, 0x10)
			if v97 != nil {
				v98 = sub_42C8B0(int32(uintptr(v97)), internCStr("IPL?"), int8(v96))
			} else {
				v98 = 0
			}
			sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v98)
			*memmap.PtrUint8(0x587000, 71515) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			v99 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 616))) + *memmap.PtrUint32(0x5D4594, 741660)*4))))
			v100 = alloc.Calloc1(1, 0x10)
			if v100 != nil {
				v101 = sub_42C8B0(int32(uintptr(v100)), internCStr("CNL?"), int8(v99))
			} else {
				v101 = 0
			}
			sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v101)
			*memmap.PtrUint8(0x587000, 71507) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			v128 = int8(*(*uint8)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, 741660) + *(*uint32)(unsafe.Pointer(uintptr(v4 + 620)))))))
			v102 = alloc.Calloc1(1, 0x10)
			if v102 != nil {
				v103 = sub_42C7F0(int32(uintptr(v102)), internCStr("CLL?"), v128)
			} else {
				v103 = 0
			}
			sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v103)
			*memmap.PtrUint8(0x587000, 71523) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			v129 = int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 624))) + *memmap.PtrUint32(0x5D4594, 741660)))))
			v104 = alloc.Calloc1(1, 0x10)
			if v104 != nil {
				v105 = sub_42C7F0(int32(uintptr(v104)), internCStr("CMP?"), v129)
			} else {
				v105 = 0
			}
			sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v105)
			*memmap.PtrUint8(0x587000, 71531) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			v106 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 628))) + *memmap.PtrUint32(0x5D4594, 741660)*4))))
			v107 = alloc.Calloc1(1, 0x10)
			if v107 != nil {
				v108 = sub_42C8B0(int32(uintptr(v107)), internCStr("DUR?"), int8(v106))
			} else {
				v108 = 0
			}
			sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v108)
			*memmap.PtrUint8(0x587000, 71539) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			v117 = int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 632))) + *memmap.PtrUint32(0x5D4594, 741660)))))
			v109 = alloc.Calloc1(1, 0x10)
			if v109 != nil {
				v110 = sub_42C7F0(int32(uintptr(v109)), internCStr("PAR?"), v117)
			} else {
				v110 = 0
			}
			sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v110)
			v92 = int32(*memmap.PtrUint32(0x5D4594, 741660) + 1)
		}
		v111 = *(*unsafe.Pointer)(unsafe.Pointer(uintptr(v4 + 636)))
		v112 = alloc.Calloc1(1, 0x10)
		if v112 != nil {
			v113 = sub_42C910(int32(uintptr(v112)), (*byte)(memmap.PtrOff(0x587000, 71904)), v111, uint16(int16(int32(a3)*2)))
			sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), v113)
			break
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v118[0])), 0)
	case 1:
		*memmap.PtrUint32(0x5D4594, 741668)++
		sub_42BDC0((*uint32)(unsafe.Pointer(&v118[0])), internCStr("SEQU"), int8(*memmap.PtrUint8(0x5D4594, 741668)))
		sub_42BCE0((*uint32)(unsafe.Pointer(&v118[0])), internCStr("ENDF"), 0)
		sub_42BD50((*uint32)(unsafe.Pointer(&v118[0])), (*byte)(memmap.PtrOff(0x587000, 71928)), int8(uint8(*(*uint16)(unsafe.Pointer(uintptr(v4 + 6))))))
		v114 = 0
		for *memmap.PtrUint32(0x5D4594, 741660) = 0; v114 < int32(*(*int16)(unsafe.Pointer(uintptr(v4 + 6)))); *memmap.PtrUint32(0x5D4594, 741660) = uint32(v114) {
			*memmap.PtrUint8(0x587000, 71491) = uint8(int8(v114 + 48))
			sub_42BE30((*uint32)(unsafe.Pointer(&v118[0])), (*byte)(memmap.PtrOff(0x587000, 71488)), *(**byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 608))) + uint32(v114*4)))))
			*memmap.PtrUint8(0x587000, 71499) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			sub_42BDC0((*uint32)(unsafe.Pointer(&v118[0])), internCStr("IPL?"), int8(uint8(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 612))) + *memmap.PtrUint32(0x5D4594, 741660)*4))))))
			*memmap.PtrUint8(0x587000, 71515) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			sub_42BDC0((*uint32)(unsafe.Pointer(&v118[0])), internCStr("CNL?"), int8(uint8(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 616))) + *memmap.PtrUint32(0x5D4594, 741660)*4))))))
			*memmap.PtrUint8(0x587000, 71507) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			sub_42BCE0((*uint32)(unsafe.Pointer(&v118[0])), internCStr("CLL?"), int8(*(*uint8)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, 741660) + *(*uint32)(unsafe.Pointer(uintptr(v4 + 620))))))))
			*memmap.PtrUint8(0x587000, 71523) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			sub_42BCE0((*uint32)(unsafe.Pointer(&v118[0])), internCStr("CMP?"), int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 624))) + *memmap.PtrUint32(0x5D4594, 741660))))))
			*memmap.PtrUint8(0x587000, 71531) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			sub_42BDC0((*uint32)(unsafe.Pointer(&v118[0])), internCStr("DUR?"), int8(uint8(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 628))) + *memmap.PtrUint32(0x5D4594, 741660)*4))))))
			*memmap.PtrUint8(0x587000, 71539) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741660)) + 48))
			sub_42BCE0((*uint32)(unsafe.Pointer(&v118[0])), internCStr("PAR?"), int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 632))) + *memmap.PtrUint32(0x5D4594, 741660))))))
			v114 = int32(*memmap.PtrUint32(0x5D4594, 741660) + 1)
		}
		sub_42BEA0((*uint32)(unsafe.Pointer(&v118[0])), (*byte)(memmap.PtrOff(0x587000, 71936)), *(*unsafe.Pointer)(unsafe.Pointer(uintptr(v4 + 636))), uint16(int16(int32(a3)*2)))
	}
	v115 = sub_42C480((*uint32)(unsafe.Pointer(&v118[0])), a4)
	sub_42C330((*uint32)(unsafe.Pointer(&v118[0])))
	return v115
}
func sub_42B810(a1 *int16, a2 *uint32) *uint16 {
	var (
		v2  *int16
		v3  int32
		v4  unsafe.Pointer
		v5  int32
		v6  int32
		v7  unsafe.Pointer
		v8  int32
		v9  int32
		v10 unsafe.Pointer
		v11 int32
		v12 unsafe.Pointer
		v13 int32
		v14 unsafe.Pointer
		v15 int32
		v16 int32
		v17 unsafe.Pointer
		v18 int32
		v19 unsafe.Pointer
		v20 int32
		v21 int16
		v22 unsafe.Pointer
		v23 int32
		v24 int8
		v25 unsafe.Pointer
		v26 int32
		v27 int32
		v28 *byte
		v29 unsafe.Pointer
		v30 int32
		v31 int32
		v32 unsafe.Pointer
		v33 int32
		v34 unsafe.Pointer
		v35 int32
		v36 int32
		v37 unsafe.Pointer
		v38 int32
		v39 int32
		v40 unsafe.Pointer
		v41 int32
		v42 int32
		v43 unsafe.Pointer
		v44 int32
		v45 int32
		v46 unsafe.Pointer
		v47 int32
		v48 int32
		v49 unsafe.Pointer
		v50 int32
		v51 int32
		v52 unsafe.Pointer
		v53 int32
		v54 int32
		v55 unsafe.Pointer
		v56 int32
		v57 *uint16
		v59 [12]byte
		v60 int8
		v61 int8
	)
	v2 = a1
	v3 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*1))))
	*(*uint16)(unsafe.Pointer(&v59[0])) = 0
	*(*uint16)(unsafe.Pointer(&v59[2])) = 0
	*(*uint32)(unsafe.Pointer(&v59[4])) = 0
	v4 = alloc.Calloc1(1, 0x10)
	if v4 != nil {
		v5 = sub_42C8B0(int32(uintptr(v4)), internCStr("IDNO"), int8(v3))
	} else {
		v5 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v5)
	v6 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*2))))
	v7 = alloc.Calloc1(1, 0x10)
	if v7 != nil {
		v8 = sub_42C8B0(int32(uintptr(v7)), internCStr("GSKU"), int8(v6))
	} else {
		v8 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v8)
	v9 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*3))))
	v10 = alloc.Calloc1(1, 0x10)
	if v10 != nil {
		v11 = sub_42C8B0(int32(uintptr(v10)), internCStr("GSTY"), int8(v9))
	} else {
		v11 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v11)
	v12 = alloc.Calloc1(1, 0x10)
	if v12 != nil {
		v13 = sub_42C8E0(int32(uintptr(v12)), internCStr("SCEN"), (*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(a1))), 24)))
	} else {
		v13 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v13)
	v14 = alloc.Calloc1(1, 0x10)
	if v14 != nil {
		v15 = sub_42C8E0(int32(uintptr(v14)), internCStr("GNAM"), (*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(a1))), 280)))
	} else {
		v15 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v15)
	v16 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*5))))
	v17 = alloc.Calloc1(1, 0x10)
	if v17 != nil {
		v18 = sub_42C8B0(int32(uintptr(v17)), internCStr("DURA"), int8(v16))
	} else {
		v18 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v18)
	v60 = int8(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(a1))), 16))))
	v19 = alloc.Calloc1(1, 0x10)
	if v19 != nil {
		v20 = sub_42C7F0(int32(uintptr(v19)), internCStr("TRNY"), v60)
	} else {
		v20 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v20)
	v21 = *v2
	v22 = alloc.Calloc1(1, 0x10)
	if v22 != nil {
		v23 = sub_42C820(int32(uintptr(v22)), (*byte)(memmap.PtrOff(0x587000, 72000)), int8(v21))
	} else {
		v23 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v23)
	v24 = int8(*memmap.PtrUint8(0x5D4594, 741672))
	v25 = alloc.Calloc1(1, 0x10)
	if v25 != nil {
		v26 = sub_42C8B0(int32(uintptr(v25)), internCStr("SEQU"), v24)
	} else {
		v26 = 0
	}
	sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v26)
	v27 = 0
	for *memmap.PtrUint32(0x5D4594, 741664) = 0; v27 < int32(*v2); *memmap.PtrUint32(0x5D4594, 741664) = uint32(v27) {
		*memmap.PtrUint8(0x587000, 71547) = uint8(int8(v27 + 48))
		v28 = *(**byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*134))) + uint32(v27*4))))
		v29 = alloc.Calloc1(1, 0x10)
		if v29 != nil {
			v30 = sub_42C8E0(int32(uintptr(v29)), internCStr("LGLS"), v28)
		} else {
			v30 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v30)
		*memmap.PtrUint8(0x587000, 71555) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741664)) + 48))
		v31 = int32(*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*135))) + *memmap.PtrUint32(0x5D4594, 741664)*4))))
		v32 = alloc.Calloc1(1, 0x10)
		if v32 != nil {
			v33 = sub_42C8B0(int32(uintptr(v32)), internCStr("IPLS"), int8(v31))
		} else {
			v33 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v33)
		*memmap.PtrUint8(0x587000, 71563) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741664)) + 48))
		v61 = int8(*(*uint8)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, 741664) + *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*144)))))))
		v34 = alloc.Calloc1(1, 0x10)
		if v34 != nil {
			v35 = sub_42C7F0(int32(uintptr(v34)), internCStr("CLLS"), v61)
		} else {
			v35 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v35)
		*memmap.PtrUint8(0x587000, 71571) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741664)) + 48))
		v36 = int32(*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*136))) + *memmap.PtrUint32(0x5D4594, 741664)*4))))
		v37 = alloc.Calloc1(1, 0x10)
		if v37 != nil {
			v38 = sub_42C8B0(int32(uintptr(v37)), internCStr("CSTS"), int8(v36))
		} else {
			v38 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v38)
		*memmap.PtrUint8(0x587000, 71579) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741664)) + 48))
		v39 = int32(*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*137))) + *memmap.PtrUint32(0x5D4594, 741664)*4))))
		v40 = alloc.Calloc1(1, 0x10)
		if v40 != nil {
			v41 = sub_42C8B0(int32(uintptr(v40)), internCStr("HSTS"), int8(v39))
		} else {
			v41 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v41)
		*memmap.PtrUint8(0x587000, 71587) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741664)) + 48))
		v42 = int32(*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*138))) + *memmap.PtrUint32(0x5D4594, 741664)*4))))
		v43 = alloc.Calloc1(1, 0x10)
		if v43 != nil {
			v44 = sub_42C8B0(int32(uintptr(v43)), internCStr("MKLS"), int8(v42))
		} else {
			v44 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v44)
		*memmap.PtrUint8(0x587000, 71595) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741664)) + 48))
		v45 = int32(*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*139))) + *memmap.PtrUint32(0x5D4594, 741664)*4))))
		v46 = alloc.Calloc1(1, 0x10)
		if v46 != nil {
			v47 = sub_42C8B0(int32(uintptr(v46)), internCStr("ANKS"), int8(v45))
		} else {
			v47 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v47)
		*memmap.PtrUint8(0x587000, 71603) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741664)) + 48))
		v48 = int32(*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*140))) + *memmap.PtrUint32(0x5D4594, 741664)*4))))
		v49 = alloc.Calloc1(1, 0x10)
		if v49 != nil {
			v50 = sub_42C8B0(int32(uintptr(v49)), internCStr("GNDS"), int8(v48))
		} else {
			v50 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v50)
		*memmap.PtrUint8(0x587000, 71611) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741664)) + 48))
		v51 = int32(*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*141))) + *memmap.PtrUint32(0x5D4594, 741664)*4))))
		v52 = alloc.Calloc1(1, 0x10)
		if v52 != nil {
			v53 = sub_42C8B0(int32(uintptr(v52)), internCStr("SECS"), int8(v51))
		} else {
			v53 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v53)
		*memmap.PtrUint8(0x587000, 71619) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741664)) + 48))
		v54 = int32(*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*142))) + *memmap.PtrUint32(0x5D4594, 741664)*4))))
		v55 = alloc.Calloc1(1, 0x10)
		if v55 != nil {
			v56 = sub_42C8B0(int32(uintptr(v55)), internCStr("BPTS"), int8(v54))
		} else {
			v56 = 0
		}
		sub_42C360((*uint32)(unsafe.Pointer(&v59[0])), v56)
		*memmap.PtrUint8(0x587000, 71627) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 741664)) + 48))
		sub_42BDC0((*uint32)(unsafe.Pointer(&v59[0])), internCStr("SCRS"), int8(uint8(*(*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*143))) + *memmap.PtrUint32(0x5D4594, 741664)*4))))))
		v27 = int32(*memmap.PtrUint32(0x5D4594, 741664) + 1)
	}
	v57 = sub_42C480((*uint32)(unsafe.Pointer(&v59[0])), a2)
	*memmap.PtrUint32(0x5D4594, 741672)++
	sub_42C330((*uint32)(unsafe.Pointer(&v59[0])))
	return v57
}
func sub_42BCE0(this *uint32, a2 *byte, a3 int8) int32 {
	var (
		v3 *uint32
		v4 unsafe.Pointer
		v5 int32
	)
	v3 = this
	v4 = alloc.Calloc1(1, 0x10)
	if v4 != nil {
		v5 = sub_42C7F0(int32(uintptr(v4)), a2, a3)
	} else {
		v5 = 0
	}
	return sub_42C360(v3, v5)
}
func sub_42BD50(this *uint32, a2 *byte, a3 int8) int32 {
	var (
		v3 *uint32
		v4 unsafe.Pointer
		v5 int32
	)
	v3 = this
	v4 = alloc.Calloc1(1, 0x10)
	if v4 != nil {
		v5 = sub_42C820(int32(uintptr(v4)), a2, a3)
	} else {
		v5 = 0
	}
	return sub_42C360(v3, v5)
}
func sub_42BDC0(this *uint32, a2 *byte, a3 int8) int32 {
	var (
		v3 *uint32
		v4 unsafe.Pointer
		v5 int32
	)
	v3 = this
	v4 = alloc.Calloc1(1, 0x10)
	if v4 != nil {
		v5 = sub_42C8B0(int32(uintptr(v4)), a2, a3)
	} else {
		v5 = 0
	}
	return sub_42C360(v3, v5)
}
func sub_42BE30(this *uint32, a2 *byte, a3 *byte) int32 {
	var (
		v3 *uint32
		v4 unsafe.Pointer
		v5 int32
	)
	v3 = this
	v4 = alloc.Calloc1(1, 0x10)
	if v4 != nil {
		v5 = sub_42C8E0(int32(uintptr(v4)), a2, a3)
	} else {
		v5 = 0
	}
	return sub_42C360(v3, v5)
}
func sub_42BEA0(this *uint32, a2 *byte, a3 unsafe.Pointer, a4 uint16) int32 {
	var (
		v4 *uint32
		v5 unsafe.Pointer
		v6 int32
	)
	v4 = this
	v5 = alloc.Calloc1(1, 0x10)
	if v5 != nil {
		v6 = sub_42C910(int32(uintptr(v5)), a2, a3, a4)
	} else {
		v6 = 0
	}
	return sub_42C360(v4, v6)
}
func sub_42C330(this *uint32) {
	var (
		v1 *uint32
		v2 *uint32
	)
	v1 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(this), 4*1)))))
	if v1 != nil {
		for {
			v2 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*3)))))
			if v1 != nil {
				sub_42CC50((*unsafe.Pointer)(unsafe.Pointer(v1)))
				alloc.Free(v1)
			}
			v1 = v2
			if v2 == nil {
				break
			}
		}
	}
}
func sub_42C360(this *uint32, a2 int32) int32 {
	var result int32
	result = a2
	*(*uint32)(unsafe.Pointer(uintptr(a2 + 12))) = *(*uint32)(unsafe.Add(unsafe.Pointer(this), 4*1))
	*(*uint32)(unsafe.Add(unsafe.Pointer(this), 4*1)) = uint32(a2)
	return result
}
func sub_42C480(this *uint32, a2 *uint32) *uint16 {
	var (
		v2 *uint32
		i  int32
		v4 uint32
		v5 *uint16
		v6 int32
		v7 *uint32
		v8 *byte
		v9 int32
	)
	v2 = this
	*a2 = 4
	for i = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(this), 4*1))); i != 0; i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 12)))) {
		v4 = *a2 + 8
		*a2 = v4
		*a2 = uint32(*(*uint16)(unsafe.Pointer(uintptr(i + 6)))) + v4 + uint32(-((int32(uint8(*(*uint16)(unsafe.Pointer(uintptr(i + 6)))))+int32(uint8(v4)))&3)&3)
	}
	v5 = (*uint16)(alloc.Calloc1(1, uintptr(*a2)))
	*v5 = cnet.Htons(*(*uint16)(unsafe.Pointer(a2)))
	*(*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*1)) = cnet.Htons(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v2))), unsafe.Sizeof(uint16(0))*1))))
	v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)))
	v7 = (*uint32)(unsafe.Pointer((*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*2))))
	if v6 == 0 {
		return v5
	}
	for {
		sub_42CC70(v6)
		*v7 = *(*uint32)(unsafe.Pointer(uintptr(v6)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1)) = *(*uint32)(unsafe.Pointer(uintptr(v6 + 4)))
		v8 = (*byte)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*2))))
		alloc.Memcpy(unsafe.Pointer(v8), *(*unsafe.Pointer)(unsafe.Pointer(uintptr(v6 + 8))), uintptr(cnet.Ntohs(*(*uint16)(unsafe.Pointer(uintptr(v6 + 6))))))
		v9 = int32(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v8), cnet.Ntohs(*(*uint16)(unsafe.Pointer(uintptr(v6 + 6)))))))))
		v7 = (*uint32)(unsafe.Pointer(uintptr((-(int32(cnet.Ntohs(*(*uint16)(unsafe.Pointer(uintptr(v6 + 6))))) & 3) & 3) + v9)))
		sub_42CCE0((*uint16)(unsafe.Pointer(uintptr(v6))))
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 12))))
		if v6 == 0 {
			break
		}
	}
	return v5
}
func sub_42C770(this *unsafe.Pointer) int32 {
	var (
		v1     *unsafe.Pointer
		result int32
	)
	v1 = this
	alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(this), unsafe.Sizeof(unsafe.Pointer(nil))*2)))
	result = 0
	libc.StrCpy((*byte)(unsafe.Pointer(v1)), (*byte)(memmap.PtrOff(0x5D4594, 741688)))
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v1))), unsafe.Sizeof(uint16(0))*2))) = 0
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v1))), unsafe.Sizeof(uint16(0))*3))) = 0
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(unsafe.Pointer(nil))*2)) = nil
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(unsafe.Pointer(nil))*3)) = nil
	return result
}
func sub_42C7F0(this int32, a2 *byte, a3 int8) int32 {
	var v3 int32
	v3 = this
	*(*uint32)(unsafe.Pointer(uintptr(this + 8))) = 0
	sub_42C9A0((*unsafe.Pointer)(unsafe.Pointer(uintptr(this))), a2, a3)
	return v3
}
func sub_42C820(this int32, a2 *byte, a3 int8) int32 {
	var v3 int32
	v3 = this
	*(*uint32)(unsafe.Pointer(uintptr(this + 8))) = 0
	sub_42CA00((*unsafe.Pointer)(unsafe.Pointer(uintptr(this))), a2, a3)
	return v3
}
func sub_42C8B0(this int32, a2 *byte, a3 int8) int32 {
	var v3 int32
	v3 = this
	*(*uint32)(unsafe.Pointer(uintptr(this + 8))) = 0
	sub_42CB20((*unsafe.Pointer)(unsafe.Pointer(uintptr(this))), a2, a3)
	return v3
}
func sub_42C8E0(this int32, a2 *byte, a3 *byte) int32 {
	var v3 int32
	v3 = this
	*(*uint32)(unsafe.Pointer(uintptr(this + 8))) = 0
	sub_42CB80((*unsafe.Pointer)(unsafe.Pointer(uintptr(this))), a2, a3)
	return v3
}
func sub_42C910(this int32, a2 *byte, a3 unsafe.Pointer, a4 uint16) int32 {
	var v4 int32
	v4 = this
	*(*uint32)(unsafe.Pointer(uintptr(this + 8))) = 0
	sub_42CBF0((*unsafe.Pointer)(unsafe.Pointer(uintptr(this))), a2, a3, a4)
	return v4
}
func sub_42C9A0(this *unsafe.Pointer, a2 *byte, a3 int8) *byte {
	var (
		v3     *unsafe.Pointer
		result *byte
		v5     uint32
	)
	v3 = this
	sub_42C770(this)
	libc.StrNCpy((*byte)(unsafe.Pointer(v3)), a2, 4)
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*2))) = 2
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*3))) = 1
	result = (*byte)(alloc.Calloc1(1, 1))
	v5 = uint32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*3))))
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(unsafe.Pointer(nil))*2)) = unsafe.Pointer(result)
	alloc.Memcpy(unsafe.Pointer(result), unsafe.Pointer(&a3), uintptr(v5))
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(unsafe.Pointer(nil))*3)) = nil
	return result
}
func sub_42CA00(this *unsafe.Pointer, a2 *byte, a3 int8) *byte {
	var (
		v3     *unsafe.Pointer
		result *byte
		v5     uint32
	)
	v3 = this
	sub_42C770(this)
	libc.StrNCpy((*byte)(unsafe.Pointer(v3)), a2, 4)
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*2))) = 3
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*3))) = 2
	result = (*byte)(alloc.Calloc1(1, 2))
	v5 = uint32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*3))))
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(unsafe.Pointer(nil))*2)) = unsafe.Pointer(result)
	var a3i int32 = int32(a3)
	alloc.Memcpy(unsafe.Pointer(result), unsafe.Pointer(&a3i), uintptr(v5))
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(unsafe.Pointer(nil))*3)) = nil
	return result
}
func sub_42CB20(this *unsafe.Pointer, a2 *byte, a3 int8) *byte {
	var (
		v3     *unsafe.Pointer
		result *byte
		v5     uint32
	)
	v3 = this
	sub_42C770(this)
	libc.StrNCpy((*byte)(unsafe.Pointer(v3)), a2, 4)
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*2))) = 6
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*3))) = 4
	result = (*byte)(alloc.Calloc1(1, 4))
	v5 = uint32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*3))))
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(unsafe.Pointer(nil))*2)) = unsafe.Pointer(result)
	var a3i int32 = int32(a3)
	alloc.Memcpy(unsafe.Pointer(result), unsafe.Pointer(&a3i), uintptr(v5))
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(unsafe.Pointer(nil))*3)) = nil
	return result
}
func sub_42CB80(this *unsafe.Pointer, a2 *byte, a3 *byte) *byte {
	var (
		v3     *unsafe.Pointer
		v4     uint32
		result *byte
		v6     uint16
	)
	v3 = this
	sub_42C770(this)
	libc.StrNCpy((*byte)(unsafe.Pointer(v3)), a2, 4)
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*2))) = 7
	v4 = uint32(libc.StrLen(a3) + 1)
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*3))) = uint16(v4)
	result = (*byte)(alloc.Calloc1(1, uintptr(uint16(v4))))
	v6 = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*3)))
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(unsafe.Pointer(nil))*2)) = unsafe.Pointer(result)
	alloc.Memcpy(unsafe.Pointer(result), unsafe.Pointer(a3), uintptr(v6))
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(unsafe.Pointer(nil))*3)) = nil
	return result
}
func sub_42CBF0(this *unsafe.Pointer, a2 *byte, a3 unsafe.Pointer, a4 uint16) unsafe.Pointer {
	var (
		v4     *unsafe.Pointer
		result unsafe.Pointer
		v6     uint32
	)
	v4 = this
	sub_42C770(this)
	libc.StrNCpy((*byte)(unsafe.Pointer(v4)), a2, 4)
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v4))), unsafe.Sizeof(uint16(0))*2))) = 20
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v4))), unsafe.Sizeof(uint16(0))*3))) = a4
	result = alloc.Calloc1(1, uintptr(a4))
	v6 = uint32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v4))), unsafe.Sizeof(uint16(0))*3))))
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*2)) = result
	alloc.Memcpy(result, a3, uintptr(v6))
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*3)) = nil
	return result
}
func sub_42CC70(this int32) uint16 {
	var (
		v1     int32
		v2     uint16
		v3     uint16
		result uint16
	)
	v1 = this
	switch *(*uint16)(unsafe.Pointer(uintptr(this + 4))) {
	case 3, 4:
		**(**uint16)(unsafe.Pointer(uintptr(this + 8))) = cnet.Htons(**(**uint16)(unsafe.Pointer(uintptr(this + 8))))
	case 5, 6:
		**(**uint32)(unsafe.Pointer(uintptr(this + 8))) = cnet.Htonl(**(**uint32)(unsafe.Pointer(uintptr(this + 8))))
	default:
	}
	v2 = cnet.Htons(*(*uint16)(unsafe.Pointer(uintptr(v1 + 4))))
	v3 = *(*uint16)(unsafe.Pointer(uintptr(v1 + 6)))
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 4))) = v2
	result = cnet.Htons(v3)
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 6))) = result
	return result
}
func sub_42CCE0(this *uint16) int16 {
	var (
		v1 *uint16
		v2 uint16
		v3 uint16
		v4 uint32
	)
	v1 = this
	v2 = cnet.Ntohs(*(*uint16)(unsafe.Add(unsafe.Pointer(this), unsafe.Sizeof(uint16(0))*2)))
	v3 = *(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*3))
	*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*2)) = v2
	*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*3)) = cnet.Ntohs(v3)
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v4))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*2))) - 3))
	switch *(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*2)) {
	case 3, 4:
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v4))), unsafe.Sizeof(uint16(0))*0)) = cnet.Ntohs(**((**uint16)(unsafe.Add(unsafe.Pointer((**uint16)(unsafe.Pointer(v1))), unsafe.Sizeof((*uint16)(nil))*2))))
		**((**uint16)(unsafe.Add(unsafe.Pointer((**uint16)(unsafe.Pointer(v1))), unsafe.Sizeof((*uint16)(nil))*2))) = uint16(v4)
	case 5, 6:
		v4 = cnet.Ntohl(**((**uint32)(unsafe.Add(unsafe.Pointer((**uint32)(unsafe.Pointer(v1))), unsafe.Sizeof((*uint32)(nil))*2))))
		**((**uint32)(unsafe.Add(unsafe.Pointer((**uint32)(unsafe.Pointer(v1))), unsafe.Sizeof((*uint32)(nil))*2))) = v4
	default:
		return int16(uint16(v4))
	}
	return int16(uint16(v4))
}
func nox_xxx_clientTalk_42E7B0(a1p *nox_drawable) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1 int32
		v2 int16
	)
	v1 = a1
	if a1 != 0 && (*memmap.PtrUint32(0x8531A0, 2576) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x8531A0, 2576) + 3680))))&3) == 0) && sub_478030() != 1 && nox_gui_xxx_check_446360() != 1 {
		v2 = int16(*(*uint16)(unsafe.Pointer(uintptr(v1 + 128))))
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*0)) = 464
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*1)) = uint16(v2)
		nox_netlist_addToMsgListCli_40EBC0(31, 0, (*uint8)(unsafe.Pointer(&a1)), 4)
	}
}
func nox_xxx_clientCollideOrUse_42E810(a1p *nox_drawable) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1 int32
	)
	if a1 != 0 && (*memmap.PtrUint32(0x8531A0, 2576) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x8531A0, 2576) + 3680))))&3) == 0) {
		v1 = a1
		*((*uint8)(unsafe.Pointer(&a1))) = 123
		*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&a1))), 1)))) = uint16(nox_xxx_netGetUnitCodeCli_578B00(v1))
		nox_netlist_addToMsgListCli_40EBC0(31, 0, (*uint8)(unsafe.Pointer(&a1)), 3)
	}
}
func nox_xxx_clientTrade_42E850(a1p *nox_drawable) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1 int32
	)
	v1 = a1
	if a1 != 0 && (*memmap.PtrUint32(0x8531A0, 2576) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x8531A0, 2576) + 3680))))&3) == 0) && sub_47A260() != 1 && nox_gui_xxx_check_446360() != 1 {
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*0)) = 5577
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*1)) = uint16(nox_xxx_netGetUnitCodeCli_578B00(v1))
		nox_netlist_addToMsgListCli_40EBC0(31, 0, (*uint8)(unsafe.Pointer(&a1)), 4)
	}
}
func sub_42EB90(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 754052) = uint32(a1)
	return result
}
func sub_42EBA0() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 754052))
}
func sub_42EDC0() {
	if ptr_5D4594_754088 != nil {
		alloc.Free(ptr_5D4594_754088)
		ptr_5D4594_754088 = nil
	}
	if ptr_5D4594_754092 != nil {
		alloc.Free(ptr_5D4594_754092)
		ptr_5D4594_754092 = nil
	}
}
func sub_430AA0(a1 int32) int32 {
	var result int32
	result = a1 - 1
	if a1 == 1 {
		dword_5d4594_805820 = 1
		nox_xxx_useAudio_587000_80772 = 9
	} else {
		result = a1 - 2
		if a1 == 2 {
			dword_5d4594_805820 = 2
			nox_xxx_useAudio_587000_80772 = 13
		} else {
			dword_5d4594_805820 = 0
			nox_xxx_useAudio_587000_80772 = 5
		}
	}
	return result
}
func nox_client_mousePriKey_430AF0() int32 {
	return int32(dword_5d4594_805820)
}
func nox_xxx_cursor_430B00() int32 {
	return int32(nox_xxx_useAudio_587000_80772)
}
func nox_client_setMousePos_430B10(x int32, y int32) {
	nox_client_changeMousePos_430A00(x, y, true)
}
func sub_430B50(a1 int32, a2 int32, a3 int32, a4 int32) int32 {
	var result int32
	dword_5d4594_3807140 = uint32(a1)
	result = a4
	dword_5d4594_3807136 = uint32(a2)
	dword_5d4594_3807116 = uint32(a3)
	dword_5d4594_3807152 = uint32(a4)
	return result
}
func sub_431270() {
	if dword_5d4594_805984 != nil {
		sub_487680(dword_5d4594_805984)
		dword_5d4594_805984 = nil
	}
}
func sub_431290() {
	if dword_5d4594_805984 != nil {
		sub_487970(int32(uintptr(dword_5d4594_805984)), -1)
	}
}
func sub_431370() int32 {
	return bool2int32(sub_488B60() != 0)
}
func sub_431380() {
	sub_488BA0()
	sub_4896E0()
}
func nox_client_newScreenParticle_431540(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int32, a7 int8, a8 int8, a9 int8, a10 int8) *Nox_screenParticle {
	var (
		v10 int32
		v11 int32
	)
	if nox_alloc_screenParticles_806044 == nil {
		return nil
	}
	switch a1 {
	case 0:
		v10 = int32(*memmap.PtrUint32(0x5D4594, 806016))
		v11 = int32(*memmap.PtrUint32(0x5D4594, 806036))
	case 1:
		v10 = int32(*memmap.PtrUint32(0x5D4594, 806028))
		v11 = int32(*memmap.PtrUint32(0x5D4594, 806004))
	case 2:
		v10 = int32(*memmap.PtrUint32(0x5D4594, 806032))
		v11 = int32(*memmap.PtrUint32(0x5D4594, 806040))
	case 3:
		v10 = int32(*memmap.PtrUint32(0x5D4594, 806020))
		v11 = int32(*memmap.PtrUint32(0x5D4594, 806012))
	case 4:
		v10 = int32(*memmap.PtrUint32(0x5D4594, 806008))
		v11 = int32(*memmap.PtrUint32(0x5D4594, 806024))
	default:
		return nil
	}
	var p *Nox_screenParticle = (*Nox_screenParticle)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(nox_alloc_screenParticles_806044)))
	if p == nil {
		p = dword_5d4594_806052
		if p == nil {
			return nil
		}
		sub_4316C0(p)
	}
	p.Field_24 = uint32(a2 << 16)
	p.Field_28 = uint32(a3 << 16)
	p.Field_40[0] = uint8(a7)
	p.Field_40[1] = uint8(a8)
	p.Field_40[2] = uint8(a9)
	p.Field_40[3] = uint8(a8)
	p.Draw_fnc = ccall.FuncAddr(nox_client_screenParticleDraw_489700)
	p.Field_16 = uint32(a4 << 16)
	p.Field_20 = uint32(a5 << 16)
	p.Field_36 = uint32(a6 << 16)
	*(*uint8)(unsafe.Pointer(&p.Field_32)) = uint8(a10)
	p.Field_4 = uint32(a1)
	p.Field_8 = uint32(v10)
	p.Field_12 = uint32(v11)
	nox_client_addScreenParticle_431680(p)
	if p.Field_36 == 0 && int32(p.Field_40[1]) == 0 {
		p.Field_40[1] = 3
		p.Field_40[2] = 2
		p.Field_40[3] = 3
	}
	return p
}
func nox_client_addScreenParticle_431680(p *Nox_screenParticle) {
	p.Field_44 = nox_screenParticles_head
	p.Field_48 = nil
	if nox_screenParticles_head != nil {
		nox_screenParticles_head.Field_48 = p
	} else {
		dword_5d4594_806052 = p
	}
	nox_screenParticles_head = p
}
func sub_4316C0(p *Nox_screenParticle) {
	if p == dword_5d4594_806052 {
		dword_5d4594_806052 = p.Field_48
	}
	var v2 *Nox_screenParticle = p.Field_44
	if v2 != nil {
		v2.Field_48 = p.Field_48
	}
	var v3 *Nox_screenParticle = p.Field_48
	if v3 != nil {
		v3.Field_44 = p.Field_44
	} else {
		nox_screenParticles_head = p.Field_44
	}
}
func sub_431700(a1 *uint64) {
	sub_4316C0((*Nox_screenParticle)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))))
	nox_alloc_class_free_obj_first((*nox_alloc_class)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&nox_alloc_screenParticles_806044)))), unsafe.Pointer(a1))
}
func nox_client_screenParticlesDraw_431720(rdr *nox_draw_viewport_t) {
	if rdr == nil {
		return
	}
	sub_430B50(int32(rdr.Screen.Min.X), int32(rdr.Screen.Min.Y), int32(rdr.Screen.Max.X), int32(rdr.Screen.Max.Y))
	var p2 *Nox_screenParticle = nil
	for p := (*Nox_screenParticle)(nox_screenParticles_head); p != nil; p = p2 {
		set_dword_5d4594_3799468(1)
		p2 = p.Field_44
		ccall.AsFunc[func(*nox_draw_viewport_t, *Nox_screenParticle)](p.Draw_fnc)(rdr, p)
	}
}
func nox_xxx_getHostInfoPtr_431770() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 807172))
}
func nox_xxx_copyServerIPAndPort_431790(a1 *byte) *byte {
	var result *byte
	result = a1
	if a1 != nil {
		result = libc.StrNCpy((*byte)(memmap.PtrOff(0x5D4594, 806060)), a1, 0x17)
	}
	return result
}
func sub_435040() {
	var (
		buf  [256]pixel8888
		data *uint8
	)
	data = (*uint8)(memmap.PtrOff(0x973F18, 3880))
	for i := int32(0); i < 256; i++ {
		buf[i].field_0 = int8(i)
		buf[i].field_1 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(data), i*4+0)))
		buf[i].field_2 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(data), i*4+1)))
		buf[i].field_3 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(data), i*4+2)))
	}
	sub_48C580(&buf[0], 256)
	data = (*uint8)(memmap.PtrOff(0x5D4594, 809604))
	for i := int32(0); i < 256; i++ {
		*(*uint8)(unsafe.Add(unsafe.Pointer(data), i*4+0)) = uint8(buf[i].field_1)
		*(*uint8)(unsafe.Add(unsafe.Pointer(data), i*4+1)) = uint8(buf[i].field_2)
		*(*uint8)(unsafe.Add(unsafe.Pointer(data), i*4+2)) = uint8(buf[i].field_3)
		*(*uint8)(unsafe.Add(unsafe.Pointer(data), i*4+3)) = 0
		*memmap.PtrUint8(0x5D4594, uintptr(i)+808304) = uint8(buf[i].field_0)
	}
}
func sub_435120(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	var (
		result *byte
		v3     *uint8
		v4     int32
		v5     int8
		v6     *byte
		v7     int8
		v8     int8
	)
	result = (*byte)(a2)
	v3 = (*uint8)(a1)
	v4 = 256
	for {
		v5 = int8(*result)
		v6 = (*byte)(unsafe.Add(unsafe.Pointer(result), 1))
		*v3 = uint8(v5)
		v7 = int8(*func() *byte {
			p := &v6
			x := *p
			*p = (*byte)(unsafe.Add(unsafe.Pointer(*p), 1))
			return x
		}())
		*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 1)) = uint8(v7)
		v8 = int8(*v6)
		*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 3)) = 4
		*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 2)) = uint8(v8)
		result = (*byte)(unsafe.Add(unsafe.Pointer(v6), 1))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
		v4--
		if v4 == 0 {
			break
		}
	}
}
func sub_435150(a1 *uint8, a2 *byte) {
	var (
		v2     *byte
		result *uint8
		v4     int32
		v5     int8
		v6     *uint8
	)
	v2 = a2
	result = a1
	v4 = 256
	for {
		v5 = int8(*v2)
		v2 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 4))
		*result = uint8(v5)
		v6 = (*uint8)(unsafe.Add(unsafe.Pointer(result), 1))
		*func() *uint8 {
			p := &v6
			x := *p
			*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
			return x
		}() = uint8(*((*byte)(unsafe.Add(unsafe.Pointer(v2), -3))))
		*v6 = uint8(*((*byte)(unsafe.Add(unsafe.Pointer(v2), -2))))
		result = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 1))
		v4--
		if v4 == 0 {
			break
		}
	}
}
func nox_xxx_initTime_435570() int64 {
	var result int64
	result = int64(nox_platform_get_ticks())
	*memmap.PtrUint64(0x5D4594, 811908) = uint64(result)
	return result
}
func sub_435690(a1 *uint32) *uint32 {
	var result *uint32
	result = a1
	*a1 = *memmap.PtrUint32(0x5D4594, 811364)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) = *memmap.PtrUint32(0x5D4594, 811368)
	return result
}
func nox_client_drawable_testBuff_4356C0(dr *nox_drawable, a2 int8) bool {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(dr)))
		result int32
	)
	result = a1
	if a1 != 0 {
		result = bool2int32((uint32(1<<int32(a2)) & *(*uint32)(unsafe.Pointer(uintptr(a1 + 124)))) != 0)
	}
	return result != 0
}
func nox_xxx_spriteLoadError_4356E0() {
	*memmap.PtrUint32(0x587000, 85720) = 0
}
func sub_435700(a1 *wchar2_t, a2 int32) *wchar2_t {
	var result *wchar2_t
	result = nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 811376)), a1)
	*memmap.PtrUint32(0x5D4594, 811060) = uint32(a2)
	return result
}
func nox_xxx_cliToggleObsWindow_4357A0() int32 {
	var result int32
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x8531A0, 2576) + 3680))))&1 != 0 {
		result = nox_xxx_showObserverWindow_48CA70(0)
	} else {
		result = nox_xxx_showObserverWindow_48CA70(1)
	}
	return result
}
func sub_435F60() int32 {
	var result int32
	result = int32(1 - dword_5d4594_811904)
	dword_5d4594_811904 = 1 - dword_5d4594_811904
	return result
}
func sub_436550() int32 {
	var v0 int32
	if sub_459DA0() != 0 || nox_gui_xxx_check_446360() != 0 || sub_49CB40() != 0 || sub_49C810() != 0 || sub_446950() != 0 || sub_4706A0() != 0 || nox_gui_console_flagXxx_451410() != 0 {
		v0 = int32(gameFrame())
	} else {
		v0 = int32(gameFrame())
		if gameFrame() != 2 {
			return bool2int32(gameFrame()-*memmap.PtrUint32(0x5D4594, 811920) == 1)
		}
	}
	*memmap.PtrUint32(0x5D4594, 811920) = uint32(v0)
	return 1
}
func sub_437100() {
	var result int32
	_ = result
	var flag int32 = nox_client_getRenderGUI()
	if *memmap.PtrUint32(0x5D4594, 811064) != uint32(flag) && !nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		*memmap.PtrUint32(0x5D4594, 811064) = uint32(flag)
		sub_4721A0(flag)
		sub_460EA0(flag)
		nox_window_set_visible_unk5(flag)
		sub_45D500(flag)
		sub_455A00(flag)
		sub_455F10(flag)
		sub_4706C0(flag)
		if flag == 0 {
			sub_478000()
		}
	}
}
func nox_xxx_playerAnimCheck_4372B0() int32 {
	var (
		v0     int32
		result int32
	)
	result = 1
	if *memmap.PtrUint32(0x852978, 8) != 0 {
		v0 = int32(*(*uint32)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x852978, 8) + 276))))
		if v0 != 1 && v0 != 2 && v0 != 51 {
			result = 0
		}
	}
	return result
}
func nox_xxx_clientIsObserver_4372E0() int32 {
	var result int32
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 && *(*uint32)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x8531A0, 2576) + 2092))) == 1 {
		result = bool2int32((*(*uint32)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x8531A0, 2576) + 3680))) & 3) != 0)
	} else {
		result = 0
	}
	return result
}
func sub_437320(a1 int32) int32 {
	var (
		v1     int32
		v2     *uint8
		v3     int32
		v4     int32
		result int32
	)
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x587000, 87484))
	for {
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 96))) <= uint32(*(*int32)(unsafe.Pointer(v2))) {
			break
		}
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 4))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 87496))) {
			break
		}
	}
	if v1 > 2 {
		v1 = 2
	}
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 28))) + 36)
	v4 = v1 * 16
	if *(*int32)(unsafe.Pointer(&dword_587000_87412)) == -1 {
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 28))) + 76))) = *memmap.PtrUint32(0x5D4594, uintptr(v4)+814568)
		*(*uint32)(unsafe.Pointer(uintptr(v3 + 24))) = *memmap.PtrUint32(0x5D4594, uintptr(v4)+814564)
		result = int32(*memmap.PtrUint32(0x5D4594, uintptr(v4)+814564))
	} else {
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 28))) + 76))) = *memmap.PtrUint32(0x5D4594, uintptr(v4)+814560)
		*(*uint32)(unsafe.Pointer(uintptr(v3 + 24))) = *memmap.PtrUint32(0x5D4594, uintptr(v4)+814556)
		result = int32(*memmap.PtrUint32(0x5D4594, uintptr(v4)+814556))
	}
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 48))) = uint32(result)
	return result
}
func sub_4375C0(a1 int32) {
	if nox_wol_server_result_cnt_815088 != 0 {
		sub_46AD20(*(**uint32)(unsafe.Pointer(&nox_wol_wnd_world_814980)), 10070, int32(nox_wol_server_result_cnt_815088+10069), a1)
	}
}
func sub_437860(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     *uint8
	)
	result = 0
	v3 = (*uint8)(memmap.PtrOff(0x587000, 87532))
	for a1 <= int32(*((*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(v3))), -int(unsafe.Sizeof(int16(0))*2))))) || a1 >= int32(*(*int16)(unsafe.Pointer(v3))) || a2 <= int32(*((*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(v3))), -int(unsafe.Sizeof(int16(0))*1))))) || a2 >= int32(*((*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(v3))), unsafe.Sizeof(int16(0))*1)))) {
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 8))
		result++
		if int32(uintptr(unsafe.Pointer(v3))) >= int32(uintptr(memmap.PtrOff(0x587000, 87564))) {
			return 0
		}
	}
	return result
}
func sub_4379C0() {
	if dword_587000_87408 == 1 {
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_gameList_815012))))), 16399, 0, 0)
	}
}
func sub_438330() int {
	v0 := nox_wnd_xxx_815040.Func13Ptr.Get()
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_815040)
	if !nox_common_gameFlags_check_40A5C0(0x10000000) {
		nox_client_guiXxx_43A9D0()
	}
	if v0 != nil {
		v0()
	}
	return 1
}
func sub_438370() int {
	if nox_wnd_xxx_815040.State() == NOX_GUI_ANIM_OUT_DONE {
		return sub_438330()
	}
	nox_wnd_xxx_815040.SetState(NOX_GUI_ANIM_OUT)
	sub_43BE40(2)
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100)
	return 1
}
func sub_438480() {
	nox_xxx_wndSetProc_46B2C0(*(**gui.Window)(unsafe.Pointer(&nox_wol_wnd_gameList_815012)), sub_439050)
	nox_xxx_wndSetWindowProc_46B300(*(**gui.Window)(unsafe.Pointer(&nox_wol_wnd_gameList_815012)), sub_438EF0)
	sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_815016)))), (*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_gameList_815012))))))
	nox_xxx_wndSetWindowProc_46B300(*(**gui.Window)(unsafe.Pointer(&dword_5d4594_815016)), sub_438EF0)
	sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_815020)))), (*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_gameList_815012))))))
	nox_xxx_wndSetWindowProc_46B300(*(**gui.Window)(unsafe.Pointer(&dword_5d4594_815020)), sub_438EF0)
	sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_815024)))), (*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_gameList_815012))))))
	nox_xxx_wndSetWindowProc_46B300(*(**gui.Window)(unsafe.Pointer(&dword_5d4594_815024)), sub_438EF0)
	sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_815028)))), (*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_gameList_815012))))))
	nox_xxx_wndSetWindowProc_46B300(*(**gui.Window)(unsafe.Pointer(&dword_5d4594_815028)), sub_438EF0)
	sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_815032)))), (*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_gameList_815012))))))
	nox_xxx_wndSetWindowProc_46B300(*(**gui.Window)(unsafe.Pointer(&dword_5d4594_815032)), sub_438EF0)
	**(**uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_815004))) + 32))) + 28))) = 10035
	**(**uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_815004))) + 32))) + 32))) = 10036
	**(**uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_815004))) + 32))) + 36))) = 10032
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815016))))), 16408, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 28)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815020))))), 16408, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 28)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815024))))), 16408, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 28)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815028))))), 16408, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 28)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815032))))), 16408, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 28)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815016))))), 16409, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 32)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815020))))), 16409, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 32)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815024))))), 16409, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 32)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815028))))), 16409, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 32)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815032))))), 16409, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 32)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815016))))), 16410, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 36)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815020))))), 16410, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 36)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815024))))), 16410, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 36)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815028))))), 16410, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 36)))), 0)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815032))))), 16410, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(nox_wol_wnd_gameList_815012 + 32))) + 36)))), 0)
}
func sub_438C80(win *gui.Window, draw *gui.WindowData) int {
	var (
		v2   [404]byte
		mpos nox_point = nox_client_getMousePos_4309F0()
	)
	if wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815000)))))) == 0 {
		alloc.Memcpy(unsafe.Pointer(&v2[0]), *(*unsafe.Pointer)(unsafe.Pointer(&dword_5d4594_815000)), 404)
		*(*uint32)(unsafe.Pointer(&v2[16])) -= 32
		*(*uint32)(unsafe.Pointer(&v2[20])) -= 32
		*(*uint32)(unsafe.Pointer(&v2[8])) += 64
		*(*uint32)(unsafe.Pointer(&v2[12])) += 64
		if dword_5d4594_815044 == 0 && !nox_xxx_wndPointInWnd_46AAB0((*uint32)(unsafe.Pointer(&v2[0])), mpos.x, mpos.y) {
			nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815000))))), 1)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_gameList_815012))))), 16403, math.MaxUint32, 0)
			dword_5d4594_815056 = 0
			nox_xxx_wnd_46C6E0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815000))))))
			nox_xxx_windowFocus_46B500((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_world_814980))))))
		}
	}
	if sub_4A28B0() != 0 && !nox_xxx_wndPointInWnd_46AAB0(*(**uint32)(memmap.PtrOff(0x5D4594, 815036)), mpos.x, mpos.y) {
		sub_4A2890()
		nox_xxx_windowFocus_46B500((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_world_814980))))))
	}
	if nox_game_createOrJoin_815048 != 0 && sub_438DD0(uint32(mpos.x), uint32(mpos.y)) != 0 {
		nox_client_setCursorType_477610(9)
	} else if sub_44A4A0() == 0 {
		nox_client_setCursorType_477610(0)
	}
	return 1
}
func sub_438DD0(a1 uint32, a2 uint32) int32 {
	if *(*int32)(unsafe.Pointer(&dword_587000_87412)) == -1 {
		if a1 > 0xD8 && a1 < 0x258 && a2 > 0x1B && a2 < 0x1C3 {
			return 1
		}
	} else if a1 > 0xE2 && a1 < 0x24E && a2 > 0x25 && a2 < 0x1B9 {
		return 1
	}
	return 0
}
func sub_438E30(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1 = (*uint32)(win.C())
		v1 *uint32
		v2 int32
		v3 int32
		v4 **int16
		v6 int32
	)
	v1 = a1
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(a1)), (*uint32)(unsafe.Pointer(&v6)), (*uint32)(unsafe.Pointer(&a1)))
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*25)))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*9))&6 != 0 {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*19))))), int32(uint32(v6)+*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*24))), int32(uintptr(unsafe.Pointer(a1)))+v2)
	} else {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*15))))), int32(uint32(v6)+*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*24))), int32(uintptr(unsafe.Pointer(a1)))+v2)
	}
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*100)))
	if v3 == 0 {
		return 1
	}
	for {
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 4))))&0x10) == 0 && *(*uint32)(unsafe.Pointer(uintptr(v3 + 44))) == 2048 {
			v4 = *(***int16)(unsafe.Pointer(uintptr(v3 + 32)))
			nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
			nox_xxx_drawStringStyle_43F7B0(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 236))))), (*wchar2_t)(unsafe.Pointer(*v4)), int32(uint32(v6)+*(*uint32)(unsafe.Pointer(uintptr(v3 + 16)))), int32(uint32(int32(uintptr(unsafe.Pointer(a1))))+*(*uint32)(unsafe.Pointer(uintptr(v3 + 20)))))
		}
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 388))))
		if v3 == 0 {
			break
		}
	}
	return 1
}
func sub_438EF0(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	var (
		a1 = (*uint32)(win.C())
		a2 = int32(p2)
		v5 int32
		v6 int32
	)
	if a2 == 19 {
		v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)))
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_gameList_815012))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v6 + 28)))), 0)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815016))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v6 + 28)))), 0)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815020))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v6 + 28)))), 0)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815024))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v6 + 28)))), 0)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815028))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v6 + 28)))), 0)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815032))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v6 + 28)))), 0)
		return 0
	} else if a2 == 20 {
		v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)))
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_gameList_815012))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 32)))), 0)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815016))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 32)))), 0)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815020))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 32)))), 0)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815024))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 32)))), 0)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815028))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 32)))), 0)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815032))))), 16391, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 32)))), 0)
		return 0
	} else {
		return nox_xxx_wndListboxProcWithoutData10_4A28E0(win, p2, p3, p4)
	}
}
func sub_439050(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	var (
		a1 = int32(uintptr(win.C()))
		a2 = uint32(p2)
		a3 = (*int32)(unsafe.Pointer(p3))
		a4 = uint32(p4)
		v4 int32
		v5 int32
		v7 int32
	)
	if a2 > 0x400F {
		if a2 == 16400 {
			v7 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
			if v7 >= 10038 && v7 <= 10042 {
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815016))))), 16403, uintptr(p4), 0)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815020))))), 16403, uintptr(p4), 0)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815024))))), 16403, uintptr(p4), 0)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815028))))), 16403, uintptr(p4), 0)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815032))))), 16403, uintptr(p4), 0)
				if a4 < uint32(*(*int32)(unsafe.Pointer(&nox_wol_server_result_cnt_815088))) {
					var pos nox_point = nox_client_getMousePos_4309F0()
					dword_5d4594_814624 = unsafe.Pointer(sub_4A04C0(int32(a4)))
					nox_client_gui_serverInfoBlockCheckExp_439370((*int2)(unsafe.Pointer(&pos)), int32(uintptr(dword_5d4594_814624)))
				}
			}
		} else if a2 == 16403 || a2 == 16412 {
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815016))))), uintptr(a2), uintptr(unsafe.Pointer(a3)), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815020))))), uintptr(a2), uintptr(unsafe.Pointer(a3)), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815024))))), uintptr(a2), uintptr(unsafe.Pointer(a3)), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815028))))), uintptr(a2), uintptr(unsafe.Pointer(a3)), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815032))))), uintptr(a2), uintptr(unsafe.Pointer(a3)), 0)
		}
	} else if a2 >= 0x400E {
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815016))))), uintptr(a2), uintptr(unsafe.Pointer(a3)), uintptr(a4))
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815020))))), uintptr(a2), uintptr(unsafe.Pointer(a3)), uintptr(a4))
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815024))))), uintptr(a2), uintptr(unsafe.Pointer(a3)), uintptr(a4))
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815028))))), uintptr(a2), uintptr(unsafe.Pointer(a3)), uintptr(a4))
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815032))))), uintptr(a2), uintptr(unsafe.Pointer(a3)), uintptr(a4))
	} else {
		switch a2 {
		case 0x17:
			return 1
		case 0x4000:
			if unsafe.Pointer(a3) == unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&nox_wol_wnd_gameList_815012)))), 10043)) || unsafe.Pointer(a3) == unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&nox_wol_wnd_gameList_815012)))), 10044)) {
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815016))))), 0x4000, uintptr(unsafe.Pointer(a3)), 0)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815020))))), 0x4000, uintptr(unsafe.Pointer(a3)), 0)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815024))))), 0x4000, uintptr(unsafe.Pointer(a3)), 0)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815028))))), 0x4000, uintptr(unsafe.Pointer(a3)), 0)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815032))))), 0x4000, uintptr(unsafe.Pointer(a3)), 0)
			}
		case 0x4009:
			v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 32))))
			nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(unsafe.Pointer(uintptr(a1))), 0x4009, uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(a3)))), uintptr(a4))
			v5 = sub_4A4800(v4)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815016))))), 16412, uintptr(v5), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815020))))), 16412, uintptr(v5), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815024))))), 16412, uintptr(v5), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815028))))), 16412, uintptr(v5), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815032))))), 16412, uintptr(v5), 0)
		}
	}
	return nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(unsafe.Pointer(uintptr(a1))), uintptr(a2), uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(a3)))), uintptr(a4))
}
func sub_439450(a1 int32, a2 int32, a3 *uint32) *uint32 {
	var (
		result *uint32
		v4     int32
	)
	result = a3
	*a3 = uint32(a1 - 65)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) = uint32(a2 - 20)
	if a1-65+130 > 600 {
		*a3 = 470
	}
	if a2-20+120 > 451 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) = 331
	}
	if dword_587000_87408 == 1 {
		v4 = 55
		if *(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) >= 55 {
			goto LABEL_10
		}
	} else {
		v4 = 27
		if *(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) >= 27 {
			goto LABEL_10
		}
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) = uint32(v4)
LABEL_10:
	if int32(*a3) < 216 {
		*a3 = 216
	}
	return result
}
func sub_439CC0(a1 int32, a2 *byte) *byte {
	var (
		v2     uint32
		result *byte
	)
	v2 = uint32(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(libc.StrStr((*byte)(unsafe.Pointer(uintptr(a1+52))), internCStr("'s_game"))), int32(-52-a1))))))
	result = libc.StrNCpy(a2, (*byte)(unsafe.Pointer(uintptr(a1+52))), int(v2))
	*(*byte)(unsafe.Add(unsafe.Pointer(a2), v2)) = 0
	return result
}
func sub_439D00(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	if a2 == 5 {
		if nox_xxx_wndGetID_46B0A0(win) == 10020 && nox_game_createOrJoin_815048 == 1 {
			sub_439D90(uint32(uint16(a3)), uint32(a3)>>16)
			return 1
		}
		return 0
	}
	if a2 != 21 {
		return 0
	}
	if a3 != 1 {
		if a3 != 28 && a3 == 57 {
			var mpos nox_point = nox_client_getMousePos_4309F0()
			nox_window_call_field_93(win, 5, mpos.x|mpos.y<<16, 0)
		}
		return 0
	}
	if a4 == 2 {
		sub_4373A0()
	}
	return 1
}
func sub_439D90(a1 uint32, a2 uint32) int32 {
	var (
		result int32
		v3     int16
	)
	result = sub_438DD0(a1, a2)
	if result != 0 {
		v3 = int16(uint16(a2 + uint32(*memmap.PtrUint16(0x587000, uintptr(dword_587000_87412)*8+87530)) - 27))
		*memmap.PtrUint16(0x5D4594, 814916) = uint16(a1 + uint32(*memmap.PtrUint16(0x587000, uintptr(dword_587000_87412)*8+87528)) - 216)
		*memmap.PtrUint16(0x5D4594, 814918) = uint16(v3)
		sub_43B460()
		if sub_43BDB0()&2 != 0 {
			nox_xxx_setQuest_4D6F60(1)
		}
		if nox_xxx_isQuest_4D6F50() != 0 {
			if nox_client_countPlayerFiles04_4DC7D0() != 0 {
				sub_4A7A70(1)
				nox_game_showSelChar_4A4DB0()
				return nox_client_setCursorType_477610(0)
			}
		} else if nox_client_countPlayerFiles02_4DC630() != 0 {
			sub_4A7A70(1)
			nox_game_showSelChar_4A4DB0()
			return nox_client_setCursorType_477610(0)
		}
		sub_4A7A70(0)
		Nox_game_showSelClass_4A4840()
		nox_client_setCursorType_477610(0)
	}
	return result
}
func sub_43A920() int32 {
	var result int32
	nox_xxx_windowFocus_46B500((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_world_814980))))))
	if sub_43BE30() == 0 || *memmap.PtrUint32(0x5D4594, 815084) == 0 {
		sub_44A400()
	}
	result = sub_43AF90(0)
	dword_5d4594_815044 = 0
	return result
}
func nox_client_guiXxx_43A9D0() int32 {
	nox_xxx_wndClearCaptureMain_46ADE0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_814984))))))
	sub_489FB0()
	sub_4A2890()
	if dword_5d4594_815000 != nil && *(*uint32)(unsafe.Add(dword_5d4594_815000, 396)) == 0 {
		nox_xxx_wnd_46C6E0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815000))))))
		nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_815000)))))
		dword_5d4594_815000 = nil
	}
	if nox_wol_wnd_world_814980 != nil {
		nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&nox_wol_wnd_world_814980)))))
		nox_wol_wnd_world_814980 = nil
	}
	sub_43A920()
	nox_xxx_windowFocus_46B500(nil)
	nox_wol_server_result_cnt_815088 = 0
	sub_49FFA0(0)
	sub_554D10()
	nox_client_setCursorType_477610(0)
	return sub_43DE40(nil)
}
func sub_43AA70() *byte {
	var (
		v0     *byte
		v1     *byte
		v2     *byte
		v3     int8
		v4     int8
		v5     int8
		v6     *byte
		result *byte
		v8     int16
		v9     [32]byte
		v10    [268]byte
	)
	if dword_5d4594_528252 != 0 && dword_5d4594_528256 != 0 {
		nox_xxx_networkLog_printf_413D30(internCStr("RECON: Posting server to WOL"))
	}
	nox_game_createOrJoin_815048 = 0
	dword_5d4594_815052 = 1
	v0 = nox_xxx_cliGamedataGet_416590(0)
	v1 = (*byte)(sub_416640())
	alloc.Memcpy(unsafe.Add(unsafe.Pointer(v1), 111), unsafe.Pointer(v0), 0x3A)
	*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 163)))) = uint16(nox_common_gameFlags_getVal_40A5B0())
	*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 135)))) = math.MaxUint32
	*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 139)))) = math.MaxUint32
	*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 143)))) = math.MaxUint32
	*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 147)))) = math.MaxUint32
	*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 151)))) = math.MaxUint32
	*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 155)))) = math.MaxUint32
	*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 159)))) = math.MaxUint32
	v2 = nox_xxx_serverOptionsGetServername_40A4C0()
	libc.StrNCpy((*byte)(unsafe.Add(unsafe.Pointer(v1), 120)), v2, 0xF)
	libc.StrCpy((*byte)(unsafe.Add(unsafe.Pointer(v1), 111)), nox_xxx_mapGetMapName_409B40())
	if nox_xxx_isQuest_4D6F50() != 0 {
		if dword_5d4594_528256 != 0 {
			*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 165)))) = uint16(int16(nox_game_getQuestStage_4E3CC0()))
		} else {
			*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 165)))) = 1
		}
	}
	*(*byte)(unsafe.Add(unsafe.Pointer(v1), 104)) = byte(int8(nox_xxx_servGetPlrLimit_409FA0()))
	v3 = int8(nox_common_playerInfoCount_416F40())
	*(*byte)(unsafe.Add(unsafe.Pointer(v1), 103)) = byte(v3)
	if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		*(*byte)(unsafe.Add(unsafe.Pointer(v1), 103)) = byte(int8(int32(v3) - 1))
		*(*byte)(unsafe.Add(unsafe.Pointer(v1), 104))--
	}
	v4 = int8(sub_43BE50_get_video_mode_id())
	v5 = int8(*(*byte)(unsafe.Add(unsafe.Pointer(v1), 102)))
	*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*12))) = NOX_CLIENT_VERS_CODE
	*(*byte)(unsafe.Add(unsafe.Pointer(v1), 102)) = byte(int8(int32(v5)&0x80 | int32(v4)))
	*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v1))), 4*11))) = *memmap.PtrUint32(0x5D4594, 814916)
	*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(v1), 109)))) = uint16(int16(nox_xxx_servGetPort_40A430()))
	nox_client_setServerConnectAddr_435720(internCStr("localhost"))
	if false {
		*(*[268]byte)(unsafe.Pointer(&v10[0])) = [268]byte{}
		v6 = sub_41FA40()
		nox_sprintf(&v9[0], internCStr("%s%s"), v6, memmap.PtrOff(0x587000, 90752))
		libc.StrCpy(&v10[52], &v9[0])
		*(*uint32)(unsafe.Pointer(&v10[0])) = uint32(sub_420100())
		*(*uint32)(unsafe.Pointer(&v10[4])) = 1
		*(*uint32)(unsafe.Pointer(&v10[8])) = 32
		*(*uint32)(unsafe.Pointer(&v10[12])) = 0
		*(*uint32)(unsafe.Pointer(&v10[16])) = 0
		*(*uint32)(unsafe.Pointer(&v10[20])) = 1
		*(*uint32)(unsafe.Pointer(&v10[24])) = 1
		*(*uint32)(unsafe.Pointer(&v10[44])) = 0
		*(*uint32)(unsafe.Pointer(&v10[28])) = 0
		*(*uint32)(unsafe.Pointer(&v10[224])) = NOX_CLIENT_VERS_CODE
		*(*uint32)(unsafe.Pointer(&v10[32])) = *memmap.PtrUint32(0x5D4594, 814916)
		v10[sub_425550((*uint8)(unsafe.Add(unsafe.Pointer(v1), 100)), (*uint8)(unsafe.Pointer(&v10[69])), 552)+69] = 0
	}
	result = nox_xxx_cliGamedataGet_416590(1)
	v8 = int16(int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*26)))) & 0xE90F)
	*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v8))), unsafe.Sizeof(int16(0))-1)) |= 1
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*26))) = uint16(v8)
	return result
}
func sub_43AF30() int32 {
	return int32(dword_5d4594_815052)
}
func sub_43AF40() int32 {
	return int32(nox_game_createOrJoin_815048)
}
func sub_43AF80() int32 {
	return int32(dword_5d4594_814548)
}
func sub_43AF90(a1 int32) int32 {
	var result int32
	result = a1
	dword_5d4594_814548 = uint32(a1)
	return result
}
func nox_client_setConnError_43AFA0(a1 int32) {
	nox_client_connError_814552 = uint32(a1)
	sub_43AF90(2)
}
func nox_client_getServerAddr_43B300() uint32 {
	var result uint32
	if dword_5d4594_815056 != 0 {
		result = uint32(cnet.ParseAddr(libc.GoString((*byte)(unsafe.Pointer(uintptr(uint32(uintptr(dword_5d4594_814624)) + 12))))))
	} else {
		result = 0
	}
	return result
}
func nox_client_getServerPort_43B320() int32 {
	if dword_5d4594_815056 != 0 {
		return int32(*memmap.PtrUint32(0x5D4594, 814604))
	}
	return 0
}
func sub_43B340() int32 {
	var result int32
	if dword_5d4594_815056 != 0 {
		result = int32(*(*uint16)(unsafe.Pointer(uintptr(uint32(uintptr(dword_5d4594_814624)) + 163))))
	} else {
		result = 0
	}
	return result
}
func sub_43B460() int32 {
	sub_438370()
	nox_wnd_xxx_815040.FncDoneOutPtr.Set(sub_43B490)
	nox_xxx_wnd_46C6E0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815000))))))
	return nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_814984))))), 0)
}
func sub_43B490() int {
	if nox_game_getStateCode_43BE10() == 1700 {
		return sub_438330()
	}
	nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&nox_wol_wnd_world_814980))))), 1)
	nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_815000))))), 1)
	nox_client_setCursorType_477610(0)
	return 1
}
