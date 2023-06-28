package legacy

import (
	"math"
	"unicode"
	"unsafe"

	"github.com/chewxy/math32"
	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_wnd_xxx_1308092 *gui.Anim = nil
var nox_wnd_xxx_1309740 *gui.Anim = nil
var dword_5d4594_1307292 unsafe.Pointer = nil
var dword_5d4594_1308156 unsafe.Pointer = nil
var dword_5d4594_1308160 unsafe.Pointer = nil
var dword_5d4594_1308164 unsafe.Pointer = nil

func sub_4A2560(a1 *uint32, a2 int32) int32 {
	var (
		v2 float64
		v3 float64
	)
	v2 = float64(uint32(*(*int16)(unsafe.Add(a2, 44))) - *a1)
	v3 = float64(uint32(*(*int16)(unsafe.Add(a2, 46))) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	return bool2int32(math.Sqrt(v3*v3+v2*v2) <= *mem_getDoublePtr(0x581450, 9720))
}
func sub_4A25C0(a1 *uint32, a2 *int32) int32 {
	var (
		v2 int32
		v3 *int32
	)
	v2 = 0
	v3 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(a2)))))
	if v3 == nil {
		return 0
	}
	for {
		if sub_4A2560(a1, int32(uintptr(unsafe.Pointer(v3)))) != 0 {
			v2++
		}
		v3 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v3)))))
		if v3 == nil {
			break
		}
	}
	return v2
}
func sub_4A2610(win *gui.Window, a2 *uint32, a3 *int32) int32 {
	var (
		a1  = int32(uintptr(win.C()))
		i   *int32
		v4  int32
		v5  *uint32
		v6  *uint32
		v7  *uint32
		v8  *uint32
		v9  *byte
		v10 int32
		v11 *uint8
		v13 *uint32
		v14 *byte
		v15 [2]int32
		v16 [64]byte
	)
	v17, free17 := alloc.Make([]wchar2_t{}, 128)
	defer free17()
	dword_5d4594_1307720 = 0
	for i = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(a3))))); i != nil; i = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(i))))) {
		if sub_4A2560(a2, int32(uintptr(unsafe.Pointer(i)))) != 0 {
			v4 = int32(dword_5d4594_1307720)
			*memmap.PtrPtr(0x5D4594, uintptr(dword_5d4594_1307720)*4+1307316) = unsafe.Pointer(i)
			dword_5d4594_1307720 = uint32(v4 + 1)
		}
	}
	if dword_5d4594_1307720 > 0 {
		dword_5d4594_1307716 = uint32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("proxlist.wnd"), win.GetFunc94()))))
		sub_4A2830(int32(*a2+216), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*1))+27), (*uint32)(unsafe.Pointer(&v15[0])))
		nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(dword_5d4594_1307716)), v15[0], v15[1])
		nox_xxx_wnd_46B280(dword_5d4594_1307716, a1)
		v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1307716)), 10064)))
		v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1307716)), 10062)))
		v13 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1307716)), 10063)))
		v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1307716)), 10061)))
		v8 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v7), 4*8)))
		v14 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("UISlider"))))
		v9 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("UISliderLit"))))
		sub_4B5700(int32(uintptr(unsafe.Pointer(v5))), 0, 0, unsafe.Pointer(v14), unsafe.Pointer(v9), unsafe.Pointer(v9))
		nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v5))), int32(uintptr(unsafe.Pointer(v7))))
		nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v6))), int32(uintptr(unsafe.Pointer(v7))))
		nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v13))), int32(uintptr(unsafe.Pointer(v7))))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*9)) = uint32(uintptr(unsafe.Pointer(v5)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*7)) = uint32(uintptr(unsafe.Pointer(v6)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*8)) = uint32(uintptr(unsafe.Pointer(v13)))
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v5), 4*100)), 8)) = 16
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v5), 4*100)), 12)) = 10
		v10 = 0
		if dword_5d4594_1307720 > 0 {
			v11 = (*uint8)(memmap.PtrOff(0x5D4594, 1307316))
			for {
				if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v11)), 120))) != 0 {
					libc.StrNCpy(&v16[0], (*byte)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v11)), 120)), 0xF)
					v16[15] = 0
				} else {
					nox_sprintAddrPort_43BC80((*byte)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v11)), 12)), *(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v11)), 109)), &v16[0])
				}
				nox_swprintf(&v17[0], internWStr("%S   %dms"), &v16[0], *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v11)), 96)))
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v7)), 16397, uintptr(unsafe.Pointer(&v17[0])), math.MaxUint32)
				v10++
				v11 = (*uint8)(unsafe.Add(unsafe.Pointer(v11), 4))
				if v10 >= dword_5d4594_1307720 {
					break
				}
			}
		}
	}
	return int32(dword_5d4594_1307716)
}
func sub_4A2830(a1 int32, a2 int32, a3 *uint32) *uint32 {
	var result *uint32
	result = a3
	*a3 = uint32(a1 - 100)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) = uint32(a2 - 20)
	if a1-100+200 > 600 {
		*a3 = 400
	}
	if a2-20+200 > 451 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) = 251
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) < 27 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*1)) = 27
	}
	if int32(*a3) < 216 {
		*a3 = 216
	}
	return result
}
func sub_4A2890() int32 {
	var result int32
	result = int32(dword_5d4594_1307716)
	if dword_5d4594_1307716 != 0 {
		result = nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(dword_5d4594_1307716)))
		dword_5d4594_1307716 = 0
	}
	return result
}
func sub_4A28B0() int32 {
	return bool2int32(dword_5d4594_1307716 != 0)
}
func sub_4A28C0(a1 int32) int32 {
	var result int32
	if a1 < dword_5d4594_1307720 {
		result = int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1307316))
	} else {
		result = 0
	}
	return result
}
func nox_xxx_wndListboxProcWithoutData10_4A28E0(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	var (
		a1 = (*uint32)(win.C())
		a3 = uint32(p3)
		a4 = int32(p4)
		v4 *uint32
		v5 int32
	)
	var v7 int32
	var v8 int32
	var v9 int32
	var v10 int32
	var v11 int32
	var v12 uint32
	var v13 uint32
	var v14 int32
	var v15 int32
	var v16 int32
	var v17 uint32
	var v18 uint32
	var v19 int32
	var v20 int32
	var v21 int32
	var v22 int32
	v4 = a1
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)))
	switch a2 {
	case 5, 17, 18:
		return 1
	case 6, 7:
		v12 = a3
		a3 = *(*uint32)(unsafe.Add(v5, 48))
		v13 = v12 >> 16
		nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(a1)), (*uint32)(unsafe.Pointer(&a1)), &a4)
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*54))) != 0 {
			v14 = nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), 4*59)))
			a4 += v14 + 1
		}
		v15 = 0
		*(*uint32)(unsafe.Add(v5, 48)) = 4294967294
		v16 = 0
		for {
			if v16 > 0 && *(*int32)(unsafe.Pointer(uintptr(uint32(v16) + *(*uint32)(unsafe.Add(v5, 24)) - 524))) > int32(*(*int16)(unsafe.Add(v5, 52)))+int32(*(*int16)(unsafe.Add(v5, 54))) || v15 == int32(*(*int16)(unsafe.Add(v5, 44))) {
				*(*uint32)(unsafe.Add(v5, 48)) = math.MaxUint32
			} else if *(*int32)(unsafe.Pointer(uintptr(uint32(v16) + *(*uint32)(unsafe.Add(v5, 24))))) <= int32(v13+uint32(*(*int16)(unsafe.Add(v5, 54)))-uint32(a4)) {
				v15++
				v16 += 524
				continue
			}
			break
		}
		v17 = a3
		if uint32(v15) == a3 && *(*uint32)(unsafe.Add(v5, 20)) == 0 {
			*(*uint32)(unsafe.Add(v5, 48)) = math.MaxUint32
		}
		if *(*int32)(unsafe.Add(v5, 48)) == -2 && v15 < int32(*(*int16)(unsafe.Add(v5, 44))) {
			*(*uint32)(unsafe.Add(v5, 48)) = uint32(v15)
		}
		if *(*int32)(unsafe.Add(v5, 48)) < 0 {
			if *(*uint32)(unsafe.Add(v5, 20)) != 0 {
				*(*uint32)(unsafe.Add(v5, 48)) = v17
			}
		}
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), 4*13))), 16400, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
		return 1
	case 8:
		v22 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*11)))
		if v22&0x100 != 0 {
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*13))), 0x4000, uintptr(unsafe.Pointer(a1)), 0)
		}
		return 1
	case 10, 11:
		v18 = a3 >> 16
		nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(a1)), &a3, &a4)
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*54))) != 0 {
			v19 = nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), 4*59)))
			a4 += v19 + 1
		}
		v20 = 0
		v21 = 0
		for (v21 <= 0 || *(*uint32)(unsafe.Pointer(uintptr(uint32(v21) + *(*uint32)(unsafe.Add(v5, 24)) - 524))) <= uint32(int32(*(*int16)(unsafe.Add(v5, 52)))+int32(*(*int16)(unsafe.Add(v5, 54))))) && v20 != int32(*(*int16)(unsafe.Add(v5, 44))) {
			if *(*uint32)(unsafe.Pointer(uintptr(uint32(v21) + *(*uint32)(unsafe.Add(v5, 24))))) > v18+uint32(*(*int16)(unsafe.Add(v5, 54)))-uint32(a4) {
				nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), 4*13))), 16401, uintptr(unsafe.Pointer(v4)), uintptr(v20))
				return 1
			}
			v20++
			v21 += 524
		}
		v20 = -1
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), 4*13))), 16401, uintptr(unsafe.Pointer(v4)), uintptr(v20))
		return 1
	case 19:
		v8 = int32(*(*uint32)(unsafe.Add(v5, 48)))
		if v8 == -1 {
			*(*uint32)(unsafe.Add(v5, 48)) = 0
			nox_xxx_wndListBox_4A2D10(win, 0, 1)
		} else if v8 > 0 {
			v11 = v8 - 1
			*(*uint32)(unsafe.Add(v5, 48)) = uint32(v11)
			if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v5, 24)) + uint32(v11*524)))) < uint32(*(*int16)(unsafe.Add(v5, 54))) {
				nox_xxx_wndListBox_4A2D10(win, -1, 1)
			}
		}
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), 4*13))), 16400, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
		return 1
	case 20:
		v7 = int32(*(*uint32)(unsafe.Add(v5, 48)))
		if v7 == -1 {
			*(*uint32)(unsafe.Add(v5, 48)) = 0
			nox_xxx_wndListBox_4A2D10(win, 0, 1)
		} else if v7 < int32(*(*int16)(unsafe.Add(v5, 44)))-1 {
			v9 = v7 + 1
			v10 = int32(*(*int16)(unsafe.Add(v5, 52))) + int32(*(*int16)(unsafe.Add(v5, 54)))
			*(*uint32)(unsafe.Add(v5, 48)) = uint32(v9)
			if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v5, 24)) + uint32(v9*524)))) > uint32(v10) {
				nox_xxx_wndListBox_4A2D10(win, 1, 1)
			}
		}
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), 4*13))), 16400, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
		return 1
	case 21:
		switch a3 {
		case 0xF, 0xCD:
			if a4 != 2 {
				return 1
			}
			nox_xxx_wndRetNULL_46A8A0()
			return 1
		case 0x1C, 0x39:
			if a4 != 1 {
				return 1
			}
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*13))), 16400, uintptr(unsafe.Pointer(a1)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
			return 1
		case 0xC8:
			if a4 != 2 {
				return 1
			}
			v8 = int32(*(*uint32)(unsafe.Add(v5, 48)))
			if v8 == -1 {
				*(*uint32)(unsafe.Add(v5, 48)) = 0
				nox_xxx_wndListBox_4A2D10(win, 0, 1)
			} else if v8 > 0 {
				v11 = v8 - 1
				*(*uint32)(unsafe.Add(v5, 48)) = uint32(v11)
				if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v5, 24)) + uint32(v11*524)))) < uint32(*(*int16)(unsafe.Add(v5, 54))) {
					nox_xxx_wndListBox_4A2D10(win, -1, 1)
				}
			}
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), 4*13))), 16400, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
			return 1
		case 0xCB:
			if a4 != 2 {
				return 1
			}
			nox_xxx_wndRetNULL_0_46A8B0()
			return 1
		case 0xD0:
			if a4 != 2 {
				return 1
			}
			v7 = int32(*(*uint32)(unsafe.Add(v5, 48)))
			if v7 == -1 {
				*(*uint32)(unsafe.Add(v5, 48)) = 0
				nox_xxx_wndListBox_4A2D10(win, 0, 1)
			} else if v7 < int32(*(*int16)(unsafe.Add(v5, 44)))-1 {
				v9 = v7 + 1
				v10 = int32(*(*int16)(unsafe.Add(v5, 52))) + int32(*(*int16)(unsafe.Add(v5, 54)))
				*(*uint32)(unsafe.Add(v5, 48)) = uint32(v9)
				if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v5, 24)) + uint32(v9*524)))) > uint32(v10) {
					nox_xxx_wndListBox_4A2D10(win, 1, 1)
				}
			}
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), 4*13))), 16400, uintptr(unsafe.Pointer(v4)), uintptr(*(*uint32)(unsafe.Add(v5, 48))))
			return 1
		default:
			return 0
		}
	default:
		return 0
	}
}
func nox_xxx_wndListBox_4A2D10(win *gui.Window, a2 int32, a3 int32) int32 {
	a1 := int32(uintptr(win.C()))
	var (
		v3     int32
		v4     int32
		v5     int32
		result int32
		v7     int32
	)
	v3 = int32(*(*uint32)(unsafe.Add(a1, 32)))
	v4 = a2 + sub_4A4800(win.WidgetData)
	if v4 >= 0 {
		v5 = int32(*(*int16)(unsafe.Add(v3, 44)))
		if v4 >= v5 {
			v4 = v5 - 1
		}
	} else {
		v4 = 0
	}
	if a3 != 0 {
		if v4 <= 0 {
			*(*uint16)(unsafe.Add(v3, 54)) = 0
		} else {
			*(*uint16)(unsafe.Add(v3, 54)) = uint16(int16(int32(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v3, 24)) + uint32(v4*524) - 524)))) + 1))
		}
	}
	result = int32(*(*uint32)(unsafe.Add(v3, 36)))
	if result != 0 {
		result = int32(*(*uint32)(unsafe.Add(result, 32)))
		v7 = int32(*(*uint32)(unsafe.Add(v3, 40)) - uint32(*(*int16)(unsafe.Add(v3, 52))) + 3)
		*(*uint32)(unsafe.Add(result, 4)) = uint32(v7)
		if v7 < 0 {
			*(*uint32)(unsafe.Add(result, 4)) = 0
		}
		*(*float32)(unsafe.Add(result, 8)) = float32(float64(int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 36)), 12))-*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 36)), 400)), 12)))) / float64(*(*int32)(unsafe.Add(result, 4))))
		if a3 != 0 {
			result = int32(nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v3, 36))), 16394, uintptr(*(*uint32)(unsafe.Add(result, 4))-uint32(*(*int16)(unsafe.Add(v3, 54)))), 0))
		}
	}
	return result
}
func nox_xxx_wndListboxProcWithData10_4A2DE0(win *gui.Window, a2, p3, a4 uintptr) uintptr {
	var (
		a1     = int32(uintptr(win.C()))
		a3     = uint32(p3)
		v4     int32
		result int32
	)
	_ = result
	var v7 uint32
	var v8 int32
	var v9 uint32
	var v10 int32
	var v11 int32
	var v12 *int32
	var v13 int32
	var v14 int32
	var v15 int32
	var v16 uint32
	var v17 int32
	var v18 uint32
	var v19 int32
	var v20 int32
	var v21 int32
	v4 = a1

	sdata := (*nox_scrollListBox_data)(win.WidgetData)
	v5 := int32(uintptr(unsafe.Pointer(sdata)))
	switch a2 {
	case 5, 17, 18:
		return 1
	case 6, 7:
		v7 = a3 >> 16
		nox_client_wndGetPosition_46AA60((*gui.Window)(a1), (*uint32)(unsafe.Pointer(&a2)), &a3)
		if int32(*(*uint16)(unsafe.Add(a1, 108))) != 0 {
			v8 = nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(a1, 236)))
			v9 = a3 + uint32(v8) + 1
			a3 += uint32(v8 + 1)
		} else {
			v9 = a3
		}
		v10 = 0
		v11 = 0
		for {
			if v11 > 0 {
				if *(*uint32)(unsafe.Pointer(uintptr(uint32(v11) + *(*uint32)(unsafe.Add(v5, 24)) - 524))) > uint32(int32(*(*int16)(unsafe.Add(v5, 52)))+int32(*(*int16)(unsafe.Add(v5, 54)))) {
					v10 = -1
					v4 = a1
					break
				}
				v4 = a1
			}
			if v10 == int32(*(*int16)(unsafe.Add(v5, 44))) {
				v10 = -1
				break
			} else if *(*uint32)(unsafe.Pointer(uintptr(uint32(v11) + *(*uint32)(unsafe.Add(v5, 24))))) <= v7+uint32(*(*int16)(unsafe.Add(v5, 54)))-v9 {
				v4 = a1
				v10++
				v11 += 524
			} else {
				v4 = a1
				break
			}
		}
		v12 = *(**int32)(unsafe.Add(v5, 48))
		v13 = 0
		v14 = *v12
		if *v12 >= 0 {
			v15 = int32(*(*uint32)(unsafe.Add(v5, 48)))
			for {
				if v14 == v10 {
					sub_4A3090(sdata, int(v13))
					nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v4, 52))), 16400, uintptr(v4), uintptr(v10))
					return 1
				}
				v14 = int32(*(*uint32)(unsafe.Add(v15, 4)))
				v15 += 4
				v13++
				if v14 < 0 {
					break
				}
			}
		}
		*(*int32)(unsafe.Add(unsafe.Pointer(v12), 4*uintptr(v13))) = v10
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v5, 48))+uint32(v13*4))), 4)) = math.MaxUint32
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v4, 52))), 16400, uintptr(v4), uintptr(v10))
		return 1
	case 8:
		v21 = int32(*(*uint32)(unsafe.Add(a1, 44)))
		if v21&0x100 != 0 {
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 0x4000, uintptr(a1), 0)
		}
		return 1
	case 10, 11:
		v16 = a3 >> 16
		nox_client_wndGetPosition_46AA60((*gui.Window)(a1), (*uint32)(unsafe.Pointer(&a2)), &a3)
		if int32(*(*uint16)(unsafe.Add(a1, 108))) != 0 {
			v17 = nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(a1, 236)))
			v18 = a3 + uint32(v17) + 1
			a3 += uint32(v17 + 1)
		} else {
			v18 = a3
		}
		v19 = 0
		v20 = 0
		for {
			if v20 > 0 {
				if *(*uint32)(unsafe.Pointer(uintptr(uint32(v20) + *(*uint32)(unsafe.Add(v5, 24)) - 524))) > uint32(int32(*(*int16)(unsafe.Add(v5, 52)))+int32(*(*int16)(unsafe.Add(v5, 54)))) {
					v19 = -1
					nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16401, uintptr(a1), uintptr(v19))
					return 1
				}
				v4 = a1
			}
			if v19 != int32(*(*int16)(unsafe.Add(v5, 44))) {
				if *(*uint32)(unsafe.Pointer(uintptr(uint32(v20) + *(*uint32)(unsafe.Add(v5, 24))))) <= v16+uint32(*(*int16)(unsafe.Add(v5, 54)))-v18 {
					v4 = a1
					v19++
					v20 += 524
					continue
				}
				nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16401, uintptr(a1), uintptr(v19))
				return 1
			}
			break
		}
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v4, 52))), 16401, uintptr(v4), math.MaxUint32)
		return 1
	case 19:
		if *(*uint32)(unsafe.Add(v5, 28)) == 0 || int32(*(*int16)(unsafe.Add(v5, 54))) <= 0 {
			return 1
		}
		nox_xxx_wndListBox_4A2D10(win, -1, 1)
		return 1
	case 20:
		if *(*uint32)(unsafe.Add(v5, 32)) == 0 || int32(*(*int16)(unsafe.Add(v5, 52)))+int32(*(*int16)(unsafe.Add(v5, 54))) > *(*int32)(unsafe.Add(v5, 40)) {
			return 1
		}
		nox_xxx_wndListBox_4A2D10(win, 1, 1)
		return 1
	case 21:
		if a3 != 15 {
			return 0
		}
		if a4 != 2 {
			return 1
		}
		nox_xxx_wndRetNULL_46A8A0()
		return 1
	default:
		return 0
	}
}
func sub_4A3090(d *nox_scrollListBox_data, i int) {
	alloc.Memcpy(unsafe.Add(unsafe.Pointer(d.field_12), i*4), unsafe.Add(unsafe.Pointer(d.field_12), uint32(i+1)*4), uintptr(int(d.count)-i)*4)
	*(*uint32)(unsafe.Add(unsafe.Pointer(d.field_12), (d.count-1)*4)) = math.MaxUint32
}
func nox_xxx_wndListboxProcPre_4A30D0(win *gui.Window, ev, a3, a4 uintptr) uintptr {
	var (
		v9   *uint32
		v10  *uint32
		v11  *uint32
		v12  int32
		v13  int16
		v14  *uint32
		v15  int32
		v16  *wchar2_t
		v17  *wchar2_t
		v18  int16
		v19  int16
		v20  int32
		v21  int32
		v22  int32
		v23  int32
		v24  int32
		v25  int32
		v26  *uint32
		v27  int32
		v28  int32
		v29  int16
		v30  int16
		v31  int32
		v32  int16
		v33  **wchar2_t
		v34  int32
		v35  *wchar2_t
		v36  int32
		v38  int32
		v39  int16
		v40  int32
		v41  *uint32
		v42  int32
		v43  int32
		v44  int32
		v45  int16
		v46  int32
		v4   *uint32   = (*uint32)(unsafe.Pointer(win))
		ind  int32     = 0
		wstr *wchar2_t = nil
	)
	sdata := (*nox_scrollListBox_data)(win.WidgetData)
	if ev > 16402 {
		switch ev {
		case 0x4013:
			ind := int(a3)
			if ind < 0 || ind >= int(sdata.count) {
				if sdata.field_4 != 0 {
					libc.MemSet(unsafe.Pointer(sdata.field_12), math.MaxUint8, int(int32(sdata.count)*4))
					return 0
				}
				sdata.field_12 = (*uint32)(unsafe.Pointer(uintptr(math.MaxUint32)))
				return 0
			}
			items := sdata.Items()
			it := &items[ind]
			if it.text[0] == 0 {
				return 0
			}
			if sdata.field_4 != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(sdata.field_12), 4*0)) = uint32(ind)
				*(*uint32)(unsafe.Add(unsafe.Pointer(sdata.field_12), 4*1)) = math.MaxUint32
				return 0
			}
			v38 = int32(sdata.field_13_1)
			sdata.field_12 = (*uint32)(ind)
			if it.field_0 < uint32(v38) {
				nox_window_call_field_94_fnc(win, 16412, uintptr(ind), 0)
				return 0
			}
			v39 = int16(sdata.field_13_0)
			if it.field_0 > uint32(v38+int32(v39)) {
				if ind <= 0 {
					sdata.field_13_1 = 0
				} else {
					v37 := int32(uintptr(unsafe.Pointer(it)))
					sdata.field_13_1 = uint16(int16(int32(*(*uint16)(v37)) - int32(v39)))
				}
				nox_xxx_wndListBox_4A2D10(win, 0, 1)
			}
			return 0
		case 0x4014:
			return uintptr(unsafe.Pointer(sdata.field_12))
		case 0x4015:
			ind := int(a3)
			if ind < 0 || ind >= int(sdata.count) {
				if sdata.field_4 == 0 {
					return 0
				}
				libc.MemSet(unsafe.Pointer(sdata.field_12), math.MaxUint8, int(int32(sdata.count)*4))
				return 0
			}
			items := sdata.Items()
			it := &items[ind]
			if it.text[0] == 0 || sdata.field_4 == 0 {
				return 0
			}
			v33 = (**wchar2_t)(unsafe.Pointer(sdata.field_12))
			v34 = 0
			v35 = *v33
			if int32(uintptr(unsafe.Pointer(*v33))) < 0 {
				*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v33), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(v34))) = (*wchar2_t)(ind)
				*(*uint32)(unsafe.Add(unsafe.Pointer(sdata.field_12), 4*uintptr(v34+1))) = math.MaxUint32
				return 0
			}
			v36 = int32(uintptr(unsafe.Pointer(sdata.field_12)))
			for unsafe.Pointer(v35) != ind {
				v35 = *(**wchar2_t)(unsafe.Add(v36, 4))
				v36 += 4
				v34++
				if int32(uintptr(unsafe.Pointer(v35))) < 0 {
					*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v33), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(v34))) = (*wchar2_t)(ind)
					*(*uint32)(unsafe.Add(unsafe.Pointer(sdata.field_12), 4*uintptr(v34+1))) = math.MaxUint32
					return 0
				}
			}
			sub_4A3090(sdata, int(v34))
			return 0
		case 0x4016:
			ind = int32(a3)
			if ind < 0 || ind >= int32(sdata.count) {
				return 0
			}
			return uintptr(unsafe.Pointer(&((*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(ind)))).text[0]))
		case 0x4017:
			ind = int32(a4)
			wstr = (*wchar2_t)(unsafe.Pointer(a3))
			if ind < 0 || ind >= int32(sdata.count) {
				return 0
			}
			nox_wcsncpy(&((*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(ind)))).text[0], wstr, math.MaxUint8)
			((*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(ind)))).text[nox_wcslen(wstr)] = 0
			return 0
		case 0x4018:
			sdata.field_7 = unsafe.Pointer(a3)
			return 0
		case 0x4019:
			sdata.field_8 = unsafe.Pointer(a3)
			return 0
		case 0x401A:
			sdata.field_9 = unsafe.Pointer(a3)
			return 0
		case 0x401B:
			ind = int32(a3)
			v40 = int32(sdata.field_11_0)
			if v40 < ind {
				return 0
			}
			libc.MemMove(unsafe.Pointer(sdata.items), unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(ind)), int(uint32(v40-ind)*uint32(unsafe.Sizeof(nox_scrollListBox_item{}))))
			sdata.field_11_0 -= uint16(int16(ind))
			sdata.field_11_1 = sdata.field_11_0
			if sdata.field_4 != 0 {
				v41 = sdata.field_12
				v42 = 0
				if int32(*v41) >= 0 {
					for {
						v43 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v41), 4*uintptr(v42))))
						if ind < v43 {
							sub_4A3090(sdata, func() int {
								p := &v42
								x := *p
								*p--
								return int(x)
							}())
						} else {
							*(*uint32)(unsafe.Add(unsafe.Pointer(v41), 4*uintptr(v42))) = uint32(v43 - ind)
						}
						v41 = sdata.field_12
						v42++
						if int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v41), 4*uintptr(v42)))) < 0 {
							break
						}
					}
				}
			} else {
				v44 = int32(uintptr(unsafe.Pointer(sdata.field_12)))
				if v44 > 0 {
					sdata.field_12 = (*uint32)(unsafe.Pointer(uintptr(v44 - ind)))
				}
			}
			if int32(sdata.field_13_1) > 0 {
				nox_xxx_wndListBox_4A2D10(win, -ind, 1)
			}
			nox_xxx_wndListBox_4A3A70(win)
			return 1
		case 0x401C:
			ind = int32(a3)
			if ind-1 >= 0 && ind-1 < int32(sdata.count) {
				sdata.field_13_1 = uint16(((*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(ind-1)))).field_0 + 1)
			} else {
				sdata.field_13_1 = 0
			}
			v45 = int16(sdata.field_13_0)
			v46 = int32(sdata.field_10)
			if int32(sdata.field_13_1)+int32(v45) >= v46 {
				sdata.field_13_1 = uint16(int16(v46 - int32(v45)))
			}
			nox_xxx_wndListBox_4A2D10(win, 0, 1)
			return 0
		default:
			return 0
		}
		return 0
	}
	if ev == 16402 {
		if int32(a3) >= 0 {
			v32 = int16(sdata.field_11_0)
			if int32(a3) <= int32(v32) {
				sdata.field_11_1 = uint16(a3)
			} else {
				sdata.field_11_1 = uint16(v32)
			}
		} else {
			sdata.field_11_1 = 0
		}
		return 0
	}
	if ev > 0x4007 {
		switch ev {
		case 0x4009:
			v29 = int16(sdata.field_13_0)
			v30 = int16(int32(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(sdata.field_9, 32)), 4))) - int32(a4))
			v31 = int32(sdata.field_10 - uint32(v29) + 1)
			sdata.field_13_1 = uint16(v30)
			if int32(v30) > v31 {
				sdata.field_13_1 = uint16(int16(int32(sdata.field_10) - int32(v29) + 1))
			}
			if int32(sdata.field_13_1) < 0 {
				sdata.field_13_1 = 0
			}
			nox_xxx_wndListBox_4A2D10(win, 0, 0)
			return 0
		case 16397:
			v18 = int16(sdata.field_11_1)
			v19 = int16(sdata.field_11_0)
			if int32(v18) != int32(v19) {
				if int32(v19) < int32(sdata.count) {
					v20 = int32(v19) - 1
					if v20 >= int32(v18) {
						v21 = v20 * 524
						for {
							v20--
							v22 = int32(uintptr(unsafe.Add(unsafe.Pointer(&sdata.items.field_0), 4*uintptr(v21))))
							v21 -= 524
							alloc.Memcpy(unsafe.Add(v22, 524), v22, 0x20C)
							if v20 < int32(sdata.field_11_1) {
								break
							}
						}
						v4 = (*uint32)(unsafe.Pointer(win))
					}
					nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), v4)
				} else {
					if sdata.field_2 == 0 {
						return 0
					}
					nox_window_call_field_94_fnc(win, 16411, 1, 0)
					v23 = int32(sdata.field_11_0) - 1
					if v23 >= int32(sdata.field_11_1) {
						v24 = v23 * 524
						for {
							v23--
							v25 = int32(uint32(uintptr(unsafe.Pointer(sdata.items))) + uint32(v24))
							v24 -= 524
							alloc.Memcpy(unsafe.Add(v25, 524), v25, 0x20C)
							if v23 < int32(sdata.field_11_1) {
								break
							}
						}
						v4 = (*uint32)(unsafe.Pointer(win))
					}
					nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), v4)
				}
			} else if int32(v18) >= int32(sdata.count) {
				if sdata.field_2 == 0 {
					return 0
				}
				nox_window_call_field_94_fnc(win, 16411, 1, 0)
				nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), (*uint32)(unsafe.Pointer(win)))
			} else {
				nox_xxx_wndListBoxAddLine_4A3AC0((*wchar2_t)(unsafe.Pointer(a3)), int32(a4), (*uint32)(unsafe.Pointer(win)))
			}
			if sdata.field_1 != 0 {
				for ((*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(int32(sdata.field_11_1)-1)))).field_0 >= uint32(int32(sdata.field_13_1)+int32(sdata.field_13_0)) {
					nox_xxx_wndListBox_4A2D10(win, 1, 1)
				}
			}
			v26 = sdata.field_12
			if sdata.field_4 != 0 {
				if int32(*v26) >= 0 {
					v27 = 0
					for {
						v28 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v26), 4*uintptr(v27))))
						if int32(sdata.field_11_1) < v28 {
							*(*uint32)(unsafe.Add(unsafe.Pointer(v26), 4*uintptr(v27))) = uint32(v28 + 1)
						}
						v26 = sdata.field_12
						v27++
						if int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v26), 4*uintptr(v27)))) < 0 {
							break
						}
					}
					return 1
				}
			} else if int32(sdata.field_11_1) < int32(uintptr(unsafe.Pointer(v26))) {
				sdata.field_12 = (*uint32)(unsafe.Add(unsafe.Pointer(v26), 1))
			}
			return 1
		case 0x400E:
			ind = int32(a3)
			v12 = int32(sdata.field_11_0)
			if ind < 0 || ind >= v12 {
				return 0
			}
			for i := ind; i < v12-1; i++ {
				alloc.Memcpy(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(i)), unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(i+1)), unsafe.Sizeof(nox_scrollListBox_item{}))
			}
			v13 = int16(func() uint16 {
				p := &sdata.field_11_0
				*p--
				return *p
			}())
			*(*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(v13))) = nox_scrollListBox_item{}
			sdata.field_11_1 = uint16(v13)
			(*nox_scrollListBox_item)(unsafe.Add(unsafe.Pointer(sdata.items), unsafe.Sizeof(nox_scrollListBox_item{})*uintptr(v13))).text[0] = 0
			if sdata.field_4 != 0 {
				v14 = sdata.field_12
				v15 = 0
				if int32(*v14) >= 0 {
					for {
						v16 = (*wchar2_t)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v14), 4*uintptr(v15))))
						if ind >= int32(uintptr(unsafe.Pointer(v16))) {
							if ind == unsafe.Pointer(v16) {
								sub_4A3090(sdata, func() int {
									p := &v15
									x := *p
									*p--
									return int(x)
								}())
							}
						} else {
							*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*uintptr(v15))) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v16), -1)))
						}
						v14 = sdata.field_12
						v15++
						if int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*uintptr(v15)))) < 0 {
							break
						}
					}
					nox_xxx_wndListBox_4A3A70(win)
					return 0
				}
			} else {
				v17 = (*wchar2_t)(unsafe.Pointer(sdata.field_12))
				if ind < int32(uintptr(unsafe.Pointer(v17))) {
					sdata.field_12 = (*uint32)(unsafe.Add(unsafe.Pointer(v17), -1))
					nox_xxx_wndListBox_4A3A70(win)
					return 0
				}
				if ind == unsafe.Pointer(v17) {
					sdata.field_12 = (*uint32)(unsafe.Pointer(uintptr(math.MaxUint32)))
				}
			}
			nox_xxx_wndListBox_4A3A70(win)
			return 0
		case 0x400F:
			items := sdata.Items()
			for i := range items {
				items[i] = nox_scrollListBox_item{}
			}
			if a3 != 1 {
				sdata.field_13_1 = 0
			}
			if sdata.field_4 != 0 {
				libc.MemSet(unsafe.Pointer(sdata.field_12), math.MaxUint8, int(int32(sdata.count)*4))
			} else {
				sdata.field_12 = (*uint32)(unsafe.Pointer(uintptr(math.MaxUint32)))
			}
			sdata.field_11_1 = 0
			sdata.field_11_0 = 0
			sdata.field_10 = 0
			nox_xxx_wndListBox_4A2D10(win, 0, 1)
			return 0
		default:
			return 0
		}
	}
	if ev == 16391 {
		if unsafe.Pointer(a3) == sdata.field_7 {
			if int32(sdata.field_13_1) > 0 {
				nox_xxx_wndListBox_4A2D10(win, -1, 1)
				return 0
			}
		} else if unsafe.Pointer(a3) == sdata.field_8 && uint32(int32(sdata.field_13_0)+int32(sdata.field_13_1)) <= sdata.field_10 {
			nox_xxx_wndListBox_4A2D10(win, 1, 1)
			return 0
		}
		return 0
	}
	if ev == 16385 {
		wstr = (*wchar2_t)(unsafe.Pointer(a3))
		nox_wcsncpy(&win.DrawData().TextBuf()[0], wstr, 63)
		win.DrawData().TextBuf()[nox_wcslen(wstr)] = 0
		return 0
	}
	if ev == 16388 {
		v9 = (*uint32)(sdata.field_7)
		if v9 != nil {
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(v9)), int32(uint32(int32(a3))-*(*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*2))), 0)
		}
		v10 = (*uint32)(sdata.field_8)
		if v10 != nil {
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(v10)), int32(uint32(int32(a3))-*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*2))), int32(uint32(a4)-*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*3))))
		}
		v11 = (*uint32)(sdata.field_9)
		if v11 != nil {
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(v11)), int32(uint32(int32(a3))-*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*2))), int32(*(*uint32)(unsafe.Add(sdata.field_7, 12))))
			sub_46AB20((*uint32)(sdata.field_9), int32(*(*uint32)(unsafe.Add(sdata.field_9, 8))), int32(uint32(a4)-*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(sdata.field_9, 400)), 12))*2))
		}
		sdata.field_13_0 = uint16(int16(a4))
		if win.DrawData().TextBuf()[0] != 0 {
			sdata.field_13_0 -= uint16(int16(nox_xxx_guiFontHeightMB_43F320(win.DrawData().FontC())))
		}
		return 0
	}
	if ev > 0x4000 {
		return 0
	}
	if ev == 0x4000 {
		if unsafe.Pointer(a3) == sdata.field_7 {
			if int32(sdata.field_13_1) > 0 {
				nox_xxx_wndListBox_4A2D10(win, -1, 1)
				return 0
			}
		} else if unsafe.Pointer(a3) == sdata.field_8 && uint32(int32(sdata.field_13_0)+int32(sdata.field_13_1)) <= sdata.field_10 {
			nox_xxx_wndListBox_4A2D10(win, 1, 1)
			return 0
		}
		return 0
	}
	if ev == 2 {
		if sdata != nil {
			alloc.Free(sdata.items)
			if sdata.field_4 != 0 {
				alloc.Free(sdata.field_12)
			}
			alloc.Free(sdata)
		}
		win.WidgetData = nil
		return 0
	}
	if ev == 23 {
		if a3 != 0 {
			win.DrawData().Field0 |= 2
		} else {
			win.DrawData().Field0 &= 0xFFFFFFFD
		}
		var v7 int32 = nox_xxx_wndGetID_46B0A0(win)
		nox_window_call_field_94_fnc(win.DrawData().Window, 16387, a3, uintptr(v7))
		return 1
	}
	return 0
}
func nox_xxx_wndListBox_4A3A70(win *gui.Window) int32 {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 int32
		v5 int32
	)
	v1 = 0
	v2 = 0
	v3 = int32(uintptr(win.WidgetData))
	if int32(*(*uint16)(unsafe.Add(v3, 44))) > 0 {
		v4 = 0
		for {
			v5 = int32(uint32(v4) + *(*uint32)(unsafe.Add(v3, 24)))
			v1++
			v4 += 524
			v2 += int32(*(*uint8)(unsafe.Add(v5, 520))) + 1
			*(*uint32)(v5) = uint32(v2)
			if v1 >= int32(*(*int16)(unsafe.Add(v3, 44))) {
				break
			}
		}
	}
	*(*uint32)(unsafe.Add(v3, 40)) = uint32(v2)
	return nox_xxx_wndListBox_4A2D10(win, 0, 1)
}
func nox_xxx_wndListBoxAddLine_4A3AC0(a1 *wchar2_t, a2 int32, a3 *uint32) int32 {
	var (
		v3 *uint32
		v4 int32
		v5 int32
		v6 *wchar2_t
		v7 *wchar2_t
	)
	v3 = a3
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*8)))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*2)) - 7)
	if *(*uint32)(unsafe.Add(v4, 12)) != 0 {
		v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*2)) - 17)
	}
	if a2 >= 17 || a2 < 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v4, 24))+uint32(int32(*(*int16)(unsafe.Add(v4, 46)))*524))), 516)) = *(*uint32)(unsafe.Add(unsafe.Pointer(a3), 4*26))
	} else {
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v4, 24))+uint32(int32(*(*int16)(unsafe.Add(v4, 46)))*524))), 516)) = **(**uint32)(memmap.PtrOff(0x85B3FC, uintptr(a2*4+132)))
	}
	v6 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v4, 24))+uint32(int32(*(*int16)(unsafe.Add(v4, 46)))*524))), 4))
	if a1 != nil {
		nox_wcsncpy(v6, a1, math.MaxUint8)
		*(*wchar2_t)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(wchar2_t(0))*math.MaxUint8)) = 0
		v7 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(wchar2_t(0))*uintptr(nox_wcslen(v6)-1)))
		if *v7 == 10 {
			*v7 = 0
		}
	} else {
		*v6 = 32
		*(*wchar2_t)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(wchar2_t(0))*1)) = 0
	}
	if (*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) & 0x4000) == 0x4000 {
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v4, 24))+uint32(int32(*(*int16)(unsafe.Add(v4, 46)))*524))), 520)) = uint8(int8(nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*59)))))
	} else {
		nox_xxx_drawGetStringSize_43F840(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*59)), v6, nil, (*int32)(unsafe.Pointer(&a3)), v5)
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v4, 24))+uint32(int32(*(*int16)(unsafe.Add(v4, 46)))*524))), 520)) = uint8(uintptr(unsafe.Pointer(a3)))
	}
	*(*uint16)(unsafe.Add(v4, 46))++
	*(*uint16)(unsafe.Add(v4, 44))++
	return nox_xxx_wndListBox_4A3A70(AsWindowP(unsafe.Pointer(v3)))
}
func nox_xxx_wndListboxInit_4A3C00(a1 *gui.Window, a2 int32) {
	if a1 != nil {
		if int32(int8(*(*uint8)(unsafe.Add(a1.C(), 4)))) >= 0 {
			nox_xxx_wndSetDrawFn_46B340(a1, nox_xxx_wndListboxDrawNoImage_4A3C50)
		} else {
			nox_xxx_wndSetDrawFn_46B340(a1, nox_xxx_wndListboxDrawWithImage_4A3FC0)
		}
		if *(*uint32)(unsafe.Add(a2, 16)) != 0 {
			nox_xxx_wndSetWindowProc_46B300(a1, nox_xxx_wndListboxProcWithData10_4A2DE0)
		} else {
			nox_xxx_wndSetWindowProc_46B300(a1, nox_xxx_wndListboxProcWithoutData10_4A28E0)
		}
	}
}
func nox_xxx_wndListboxDrawNoImage_4A3C50(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = (*uint32)(win.C())
		a2    = int32(uintptr(draw.C()))
		v2    int32
		v3    int32
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		v8    int32
		v9    int32
		v10   int32
		v11   int32
		v12   int32
		v13   *int32
		v14   int32
		v15   *int16
		v16   int32
		v17   int32
		v19   int32
		v20   int32
		v21   int32
		v22   int32
		v23   int32
		v24   int32
		yTop  int32
		xLeft int32
		v27   int32
		i     int32
		v29   int32
		v30   [256]int16
	)
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)))
	v20 = int32(*(*uint32)(unsafe.Add(a2, 28)))
	v23 = int32(*(*uint32)(unsafe.Add(a2, 20)))
	nox_client_wndGetPosition_46AA60(win, &xLeft, &yTop)
	v3 = nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(a2, 200)))
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
	v22 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
	if (*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) & 0x2000) == 0x2000 {
		nox_draw_enableTextSmoothing_43F670(1)
	}
	nox_xxx_wndDraw_49F7F0()
	if *(*uint32)(unsafe.Add(v2, 12)) != 0 {
		v22 -= 10
	}
	if int32(*(*uint16)(unsafe.Add(a2, 72))) != 0 {
		nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(a2, 68))))
		nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(a2, 200)), (*wchar2_t)(unsafe.Add(a2, 72)), xLeft+1, yTop, v22, v3)
		v4 += -1 - v3
		yTop += v3 + 1
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1))&8 == 0 {
		v5 = int32(*(*uint32)(unsafe.Add(a2, 44)))
		v6 = v20
	} else if int32(*(*uint8)(a2))&2 != 0 {
		v6 = int32(*(*uint32)(unsafe.Add(a2, 36)))
		v5 = v23
	} else {
		v5 = v23
		v6 = v20
	}
	if uint32(v5) != 0x80000000 {
		nox_client_drawSetColor_434460(v5)
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, v22, v4)
	}
	if uint32(v6) != 0x80000000 {
		nox_client_drawSetColor_434460(v6)
		nox_client_drawBorderLines_49CC70(xLeft, yTop, v22, v4)
	}
	nox_client_copyRect_49F6F0(xLeft, yTop, v22, v4)
	v7 = int32(*(*int16)(unsafe.Add(v2, 54)))
	v8 = yTop - v7
	v21 = yTop - v7
	if *(*uint32)(unsafe.Add(a2, 68)) != 0x80000000 {
		v9 = 0
		v24 = 0
		for i = 0; ; i = v9 {
			if v9 > 0 && *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v2, 24)) + uint32(v9) - 524))) > uint32(int32(*(*int16)(unsafe.Add(v2, 54)))+int32(*(*int16)(unsafe.Add(v2, 52)))) || v24 == int32(*(*int16)(unsafe.Add(v2, 44))) {
				break
			}
			v10 = int32(*(*uint32)(unsafe.Add(v2, 24)) + uint32(v9))
			if *(*uint32)(v10) < uint32(*(*int16)(unsafe.Add(v2, 54))) {
				v21 = v8 + int32(*(*uint8)(unsafe.Add(v10, 520))) + 1
				goto LABEL_38
			}
			v11 = int32(*(*uint8)(unsafe.Add(v10, 520)))
			v19 = int32(*(*uint32)(unsafe.Add(v10, 516)))
			v12 = v11 + 1
			v27 = v11 + 1
			nox_xxx_drawSetTextColor_434390(v19)
			if *(*uint32)(unsafe.Add(v2, 16)) != 0 {
				v13 = *(**int32)(unsafe.Add(v2, 48))
				v14 = *v13
				if *v13 >= 0 {
					for v24 != v14 {
						v14 = *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1))
						v13 = (*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1))
						if v14 < 0 {
							goto LABEL_32
						}
					}
					if *(*uint32)(unsafe.Add(a2, 52)) != 0x80000000 {
						nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(a2, 52))))
						nox_client_drawRectFilledOpaque_49CE30(xLeft, v21, v22, v12)
					}
				}
			} else if uint32(v24) == *(*uint32)(unsafe.Add(v2, 48)) {
				if *(*uint32)(unsafe.Add(a2, 52)) != 0x80000000 {
					nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(a2, 52))))
					nox_client_drawRectFilledOpaque_49CE30(xLeft, v21, v22, v12)
				}
			}
		LABEL_32:
			nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v2, 24))+uint32(v9))), 516))))
			if (*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) & 0x4000) == 0x4000 {
				nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v30[0])), (*wchar2_t)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v2, 24))+uint32(v9))), 4)))
				v15 = &v30[nox_wcslen((*wchar2_t)(unsafe.Pointer(&v30[0])))]
				v16 = v22 - 7
				for {
					v17 = int32(*(*uint32)(unsafe.Add(a2, 200)))
					*v15 = 0
					v15 = (*int16)(unsafe.Add(unsafe.Pointer(v15), -int(unsafe.Sizeof(int16(0))*1)))
					nox_xxx_drawGetStringSize_43F840(v17, (*wchar2_t)(unsafe.Pointer(&v30[0])), &v29, nil, 0)
					if v29 <= v16 {
						break
					}
				}
				nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(a2, 200)), (*wchar2_t)(unsafe.Pointer(&v30[0])), xLeft+5, v21+2, v16, v27)
				v9 = i
				v12 = v27
			} else {
				nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(a2, 200)), (*wchar2_t)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v2, 24))+uint32(v9))), 4)), xLeft+5, v21+2, v22-7, v12)
			}
			v21 += v12
		LABEL_38:
			v8 = v21
			v9 += 524
			v24++
		}
	}
	sub_49F860()
	nox_draw_enableTextSmoothing_43F670(0)
	return 1
}
func nox_xxx_wndListboxDrawWithImage_4A3FC0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = (*uint32)(win.C())
		a2    = int32(uintptr(draw.C()))
		v2    int32
		v3    int32
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		v8    int32
		v9    int32
		v10   int32
		v11   int32
		v12   int32
		v13   int32
		v14   *int32
		v15   int32
		v16   *int16
		v17   int32
		v18   int32
		v20   int32
		v21   int32
		v22   int32
		yTop  int32
		xLeft int32
		v25   int32
		v26   int32
		i     int32
		v28   int32
		v29   int32
		v30   [256]int16
	)
	v2 = int32(*(*uint32)(unsafe.Add(a2, 24)))
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)))
	v28 = int32(*(*uint32)(unsafe.Add(a2, 28)))
	i = v2
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(a1)), &xLeft, &yTop)
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
	v22 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
	if (*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) & 0x2000) == 0x2000 {
		nox_draw_enableTextSmoothing_43F670(1)
	}
	nox_xxx_wndDraw_49F7F0()
	if *(*uint32)(unsafe.Add(v3, 12)) != 0 {
		v22 -= 10
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1))&8 != 0 {
		v5 = i
	} else {
		v5 = int32(*(*uint32)(unsafe.Add(a2, 48)))
	}
	if v5 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(v5), xLeft, yTop)
	}
	if int32(*(*uint16)(unsafe.Add(a2, 72))) != 0 {
		nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(a2, 68))))
		nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(a2, 200)), (*wchar2_t)(unsafe.Add(a2, 72)), xLeft+1, yTop, v22, 0)
		v6 = nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(a2, 200)))
		v20 = int32(*(*uint32)(unsafe.Add(a2, 200)))
		yTop += v6 + 1
		v4 += -1 - nox_xxx_guiFontHeightMB_43F320(v20)
	}
	if uint32(v28) != 0x80000000 {
		nox_client_drawSetColor_434460(v28)
		nox_client_drawBorderLines_49CC70(xLeft, yTop, v22, v4)
	}
	nox_client_copyRect_49F6F0(xLeft, yTop, v22, v4)
	v7 = int32(*(*int16)(unsafe.Add(v3, 54)))
	v8 = int32(*(*uint32)(unsafe.Add(a2, 68)))
	v9 = yTop - v7
	v25 = yTop - v7
	if uint32(v8) != 0x80000000 {
		v10 = 0
		v26 = 0
		for i = 0; ; i = v10 {
			if v10 > 0 && *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v3, 24)) + uint32(v10) - 524))) > uint32(int32(*(*int16)(unsafe.Add(v3, 54)))+int32(*(*int16)(unsafe.Add(v3, 52)))) || v26 == int32(*(*int16)(unsafe.Add(v3, 44))) {
				break
			}
			v11 = int32(uint32(v10) + *(*uint32)(unsafe.Add(v3, 24)))
			if *(*uint32)(v11) < uint32(*(*int16)(unsafe.Add(v3, 54))) {
				v25 = v9 + int32(*(*uint8)(unsafe.Add(v11, 520))) + 1
				goto LABEL_35
			}
			v12 = int32(*(*uint8)(unsafe.Add(v11, 520)))
			v21 = int32(*(*uint32)(unsafe.Add(v11, 516)))
			v13 = v12 + 1
			v28 = v12 + 1
			nox_xxx_drawSetTextColor_434390(v21)
			if *(*uint32)(unsafe.Add(v3, 16)) != 0 {
				v14 = *(**int32)(unsafe.Add(v3, 48))
				v15 = *v14
				if *v14 >= 0 {
					for v26 != v15 {
						v15 = *(*int32)(unsafe.Add(unsafe.Pointer(v14), 4*1))
						v14 = (*int32)(unsafe.Add(unsafe.Pointer(v14), 4*1))
						if v15 < 0 {
							goto LABEL_29
						}
					}
					if *(*uint32)(unsafe.Add(a2, 52)) != 0x80000000 {
						nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(a2, 52))))
						nox_client_drawRectFilledOpaque_49CE30(xLeft, v25, v22, v13)
					}
				}
			} else if uint32(v26) == *(*uint32)(unsafe.Add(v3, 48)) {
				if *(*uint32)(unsafe.Add(a2, 52)) != 0x80000000 {
					nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(a2, 52))))
					nox_client_drawRectFilledOpaque_49CE30(xLeft, v25, v22, v13)
				}
			}
		LABEL_29:
			nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(v10)+*(*uint32)(unsafe.Add(v3, 24)))), 516))))
			if (*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) & 0x4000) == 0x4000 {
				nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v30[0])), (*wchar2_t)(unsafe.Add(unsafe.Pointer(uintptr(uint32(v10)+*(*uint32)(unsafe.Add(v3, 24)))), 4)))
				v16 = &v30[nox_wcslen((*wchar2_t)(unsafe.Pointer(&v30[0])))]
				v17 = v22 - 7
				for {
					v18 = int32(*(*uint32)(unsafe.Add(a2, 200)))
					*v16 = 0
					v16 = (*int16)(unsafe.Add(unsafe.Pointer(v16), -int(unsafe.Sizeof(int16(0))*1)))
					nox_xxx_drawGetStringSize_43F840(v18, (*wchar2_t)(unsafe.Pointer(&v30[0])), &v29, nil, 0)
					if v29 <= v17 {
						break
					}
				}
				nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(a2, 200)), (*wchar2_t)(unsafe.Pointer(&v30[0])), xLeft+5, v25+2, v17, v28)
				v10 = i
				v13 = v28
			} else {
				nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(a2, 200)), (*wchar2_t)(unsafe.Add(unsafe.Pointer(uintptr(uint32(v10)+*(*uint32)(unsafe.Add(v3, 24)))), 4)), xLeft+5, v25+2, v22-7, v13)
			}
			v25 += v13
		LABEL_35:
			v9 = v25
			v10 += 524
			v26++
		}
	}
	sub_49F860()
	nox_draw_enableTextSmoothing_43F670(0)
	return 1
}
func sub_4A4800(a1 unsafe.Pointer) int32 {
	var (
		result int32
		v2     *uint32
		v3     int32
		v4     int32
	)
	result = 0
	v2 = *(**uint32)(unsafe.Add(a1, 24))
	v3 = int32(*(*int16)(unsafe.Add(a1, 54)))
	if *v2 <= uint32(v3) {
		for result < int32(*(*int16)(unsafe.Add(a1, 44))) {
			v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*131)))
			v2 = (*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*131))
			result++
			if v4 > v3 {
				return result
			}
		}
		result = 0
	}
	return result
}
func sub_4A5E90() int32 {
	var i **byte
	_ = i
	var v1 *uint32
	var v2 *uint32
	var v3 *uint32
	var v4 *uint32
	var v5 *uint32
	var v6 *uint32
	var v7 *uint32
	var v8 *uint32
	var v9 *uint32
	var v10 *uint32
	var result int32
	if *memmap.PtrUint32(0x587000, 171384) != 0 {
		sub_4A62B0()
	}
	sub_4A5E90_A()
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 720)))
	dword_5d4594_1308096 = uint32(uintptr(unsafe.Pointer(v1)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*8)) = 131074
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 721)))
	dword_5d4594_1308100 = uint32(uintptr(unsafe.Pointer(v2)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*8)) = 589825
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 722)))
	dword_5d4594_1308104 = uint32(uintptr(unsafe.Pointer(v3)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*8)) = 589825
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 723)))
	dword_5d4594_1308108 = uint32(uintptr(unsafe.Pointer(v4)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*8)) = 589825
	v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 724)))
	dword_5d4594_1308112 = uint32(uintptr(unsafe.Pointer(v5)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*8)) = 589825
	v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 725)))
	dword_5d4594_1308116 = uint32(uintptr(unsafe.Pointer(v6)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*8)) = uint32(int32(*memmap.PtrUint16(0x587000, 171372)) << 16)
	v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 726)))
	dword_5d4594_1308120 = uint32(uintptr(unsafe.Pointer(v7)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*8)) = uint32(int32(*memmap.PtrUint16(0x587000, 171374)) << 16)
	v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 727)))
	dword_5d4594_1308124 = uint32(uintptr(unsafe.Pointer(v8)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*8)) = uint32(int32(*memmap.PtrUint16(0x587000, 171376)) << 16)
	v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 728)))
	dword_5d4594_1308128 = uint32(uintptr(unsafe.Pointer(v9)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*8)) = uint32(int32(*memmap.PtrUint16(0x587000, 171378)) << 16)
	v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 729)))
	dword_5d4594_1308132 = uint32(uintptr(unsafe.Pointer(v10)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*8)) = uint32(int32(*memmap.PtrUint16(0x587000, 171380)) << 16)
	dword_5d4594_1308136 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 711))))
	dword_5d4594_1308140 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 712))))
	dword_5d4594_1308144 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 713))))
	dword_5d4594_1308148 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 714))))
	dword_5d4594_1308152 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 751))))
	result = int32(dword_587000_171388)
	if dword_587000_171388 == 0 {
		nox_window_call_field_94_fnc((*gui.Window)(dword_5d4594_1308152), 16414, uintptr(dword_5d4594_1307784), 0)
		sub_4A61E0(dword_5d4594_1308096, 2, (*uint8)(unsafe.Add(dword_5d4594_1307784, 71)))
		sub_4A61E0(dword_5d4594_1308100, 1, (*uint8)(unsafe.Add(dword_5d4594_1307784, 68)))
		sub_4A61E0(dword_5d4594_1308104, 1, (*uint8)(unsafe.Add(dword_5d4594_1307784, 74)))
		sub_4A61E0(dword_5d4594_1308108, 1, (*uint8)(unsafe.Add(dword_5d4594_1307784, 77)))
		sub_4A61E0(dword_5d4594_1308112, 1, (*uint8)(unsafe.Add(dword_5d4594_1307784, 80)))
		*(*uint32)(unsafe.Add(dword_5d4594_1308116, 32)) = uint32(int32(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 83))) << 16)
		*(*uint32)(unsafe.Add(dword_5d4594_1308120, 32)) = uint32(int32(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 84))) << 16)
		*(*uint32)(unsafe.Add(dword_5d4594_1308124, 32)) = uint32(int32(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 85))) << 16)
		*(*uint32)(unsafe.Add(dword_5d4594_1308128, 32)) = uint32(int32(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 86))) << 16)
		result = int32(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 87))) << 16
		*(*uint32)(unsafe.Add(dword_5d4594_1308132, 32)) = uint32(result)
	}
	return result
}
func sub_4A61E0(a1 *uint32, a2 int32, a3 *uint8) *uint8 {
	var (
		v3     uint32
		result *uint8
		v5     *uint32
		v6     *uint32
	)
	v3 = 0
	result = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(a2*96)+1307797))
	for int32(*(*uint8)(unsafe.Add(unsafe.Pointer(result), -1))) != int32(*a3) || int32(*result) != int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a3), 1))) || int32(*(*uint8)(unsafe.Add(unsafe.Pointer(result), 1))) != int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a3), 2))) {
		v3++
		result = (*uint8)(unsafe.Add(unsafe.Pointer(result), 3))
		if v3 >= 0x20 {
			goto LABEL_9
		}
	}
	if a2 == 1 {
		v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), int32(*a1-10))))
		nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v5)), 1)
		result = (*uint8)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), int32(*a1+10))))
		*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*9)) |= 6
	}
LABEL_9:
	if v3 == 32 && a2 == 1 {
		v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), int32(*a1-10))))
		result = (*uint8)(unsafe.Pointer(uintptr(nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v6)), 0))))
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v3), unsafe.Sizeof(uint16(0))*0)) = 9
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)) = uint32(int32(uint16(int16(a2))) | int32(uint16(v3))<<16)
	return result
}
func sub_4A62B0() {
	var (
		v0 *uint8
		v1 int32
		v3 int32
		v5 *uint8
		v6 int32
		v7 [16]byte
	)
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 1307796))
	v1 = 0
	v5 = (*uint8)(memmap.PtrOff(0x5D4594, 1307796))
	for {
		{
			*v0 = 0
			v6 = v1 + 1
			*(*uint8)(unsafe.Add(unsafe.Pointer(v0), 1)) = 0
			*(*uint8)(unsafe.Add(unsafe.Pointer(v0), 2)) = 0
			nox_sprintf(&v7[0], internCStr("UserColor%d"), v1+1)
			var v2 *obj_412ae0_t = (*obj_412ae0_t)(nox_xxx_modifGetModifListByType_4133B0(2))
			if v2 != nil {
				for libc.StrCmp(&v7[0], v2.field_0) != 0 {
					v2 = nox_xxx_modifNext_4133C0(v2)
					if v2 == nil {
						goto LABEL_7
					}
				}
				v3 = int32(uintptr(unsafe.Pointer(&v2.field_6)))
				*(*uint16)(unsafe.Pointer(v5)) = *(*uint16)(v3)
				*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 2)) = *(*uint8)(unsafe.Add(v3, 2))
			LABEL_7:
				v0 = v5
			}
			v1 = v6
			v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 3))
			v5 = v0
		}
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1307892))) {
			break
		}
	}
	*memmap.PtrUint8(0x5D4594, 1307989) = 222
	*memmap.PtrUint8(0x5D4594, 1307991) = 222
	*memmap.PtrUint8(0x5D4594, 1307995) = 154
	*memmap.PtrUint8(0x5D4594, 1308000) = 154
	*memmap.PtrUint8(0x5D4594, 1308038) = 154
	*memmap.PtrUint8(0x5D4594, 1307988) = 233
	*memmap.PtrUint8(0x5D4594, 1307990) = 205
	*memmap.PtrUint8(0x5D4594, 1307992) = 182
	*memmap.PtrUint8(0x5D4594, 1307993) = 168
	*memmap.PtrUint8(0x5D4594, 1307994) = 218
	*memmap.PtrUint8(0x5D4594, 1307996) = 110
	*memmap.PtrUint8(0x5D4594, 1307997) = 236
	*memmap.PtrUint8(0x5D4594, 1307998) = 202
	*memmap.PtrUint8(0x5D4594, 1307999) = 178
	*memmap.PtrUint8(0x5D4594, 1308001) = 131
	*memmap.PtrUint8(0x5D4594, 1308002) = 105
	*memmap.PtrUint8(0x5D4594, 1308003) = 117
	*memmap.PtrUint8(0x5D4594, 1308004) = 95
	*memmap.PtrUint8(0x5D4594, 1308005) = 74
	*memmap.PtrUint8(0x5D4594, 1308006) = 239
	*memmap.PtrUint8(0x5D4594, 1308007) = 233
	*memmap.PtrUint8(0x5D4594, 1308008) = 193
	*memmap.PtrUint8(0x5D4594, 1308009) = 228
	*memmap.PtrUint8(0x5D4594, 1308010) = 228
	*memmap.PtrUint8(0x5D4594, 1308011) = 193
	*memmap.PtrUint8(0x5D4594, 1308012) = 203
	*memmap.PtrUint8(0x5D4594, 1308013) = 185
	*memmap.PtrUint8(0x5D4594, 1308014) = 156
	*memmap.PtrUint8(0x5D4594, 1308015) = 200
	*memmap.PtrUint8(0x5D4594, 1308016) = 164
	*memmap.PtrUint8(0x5D4594, 1308017) = 110
	*memmap.PtrUint8(0x5D4594, 1308018) = 169
	*memmap.PtrUint8(0x5D4594, 1308019) = 131
	*memmap.PtrUint8(0x5D4594, 1308020) = 79
	*memmap.PtrUint8(0x5D4594, 1308021) = 243
	*memmap.PtrUint8(0x5D4594, 1308022) = 158
	*memmap.PtrUint8(0x5D4594, 1308023) = 119
	*memmap.PtrUint8(0x5D4594, 1308024) = 115
	*memmap.PtrUint8(0x5D4594, 1308025) = 77
	*memmap.PtrUint8(0x5D4594, 1308026) = 34
	*memmap.PtrUint8(0x5D4594, 1308027) = 91
	*memmap.PtrUint8(0x5D4594, 1308028) = 55
	*memmap.PtrUint8(0x5D4594, 1308029) = 20
	*memmap.PtrUint8(0x5D4594, 1308030) = 249
	*memmap.PtrUint8(0x5D4594, 1308031) = 205
	*memmap.PtrUint8(0x5D4594, 1308032) = 138
	*memmap.PtrUint8(0x5D4594, 1308033) = 240
	*memmap.PtrUint8(0x5D4594, 1308034) = 235
	*memmap.PtrUint8(0x5D4594, 1308035) = 171
	*memmap.PtrUint8(0x5D4594, 1308036) = 134
	*memmap.PtrUint8(0x5D4594, 1308037) = 143
	*memmap.PtrUint8(0x5D4594, 1308039) = 135
	*memmap.PtrUint8(0x5D4594, 1308040) = 102
	*memmap.PtrUint8(0x5D4594, 1308041) = 67
	*memmap.PtrUint8(0x5D4594, 1308042) = 115
	*memmap.PtrUint8(0x5D4594, 1308043) = 80
	*memmap.PtrUint8(0x5D4594, 1308044) = 46
	*memmap.PtrUint8(0x5D4594, 1308045) = 165
	*memmap.PtrUint8(0x5D4594, 1308046) = 93
	*memmap.PtrUint8(0x5D4594, 1308047) = 70
	*memmap.PtrUint8(0x5D4594, 1308048) = 99
	*memmap.PtrUint8(0x5D4594, 1308049) = 65
	*memmap.PtrUint8(0x5D4594, 1308050) = 37
	*memmap.PtrUint8(0x5D4594, 1308051) = 83
	*memmap.PtrUint8(0x5D4594, 1308052) = 52
	*memmap.PtrUint8(0x5D4594, 1308053) = 29
	*memmap.PtrUint8(0x5D4594, 1308054) = 168
	*memmap.PtrUint8(0x5D4594, 1308055) = math.MaxInt8
	*memmap.PtrUint8(0x5D4594, 1308056) = 84
	*memmap.PtrUint8(0x5D4594, 1308057) = 171
	*memmap.PtrUint8(0x5D4594, 1308058) = 160
	*memmap.PtrUint8(0x5D4594, 1308059) = 96
	*memmap.PtrUint8(0x5D4594, 1308060) = 141
	*memmap.PtrUint8(0x5D4594, 1308061) = 136
	*memmap.PtrUint8(0x5D4594, 1308062) = 118
	*memmap.PtrUint8(0x5D4594, 1308063) = math.MaxInt8
	*memmap.PtrUint8(0x5D4594, 1308065) = 82
	*memmap.PtrUint8(0x5D4594, 1308064) = 116
	*memmap.PtrUint8(0x5D4594, 1308080) = 116
	*memmap.PtrUint8(0x5D4594, 1308082) = 116
	*memmap.PtrUint8(0x5D4594, 1307898) = math.MaxUint8
	*memmap.PtrUint8(0x5D4594, 1307904) = math.MaxUint8
	*memmap.PtrUint8(0x5D4594, 1308066) = 96
	*memmap.PtrUint8(0x5D4594, 1307908) = 68
	*memmap.PtrUint8(0x5D4594, 1307909) = 68
	*memmap.PtrUint8(0x5D4594, 1307926) = 68
	*memmap.PtrUint8(0x5D4594, 1307936) = 68
	*memmap.PtrUint8(0x5D4594, 1308067) = 84
	*memmap.PtrUint8(0x5D4594, 1307937) = 214
	*memmap.PtrUint8(0x5D4594, 1307938) = 214
	*memmap.PtrUint8(0x5D4594, 1307939) = 214
	*memmap.PtrUint8(0x5D4594, 1308068) = 51
	*memmap.PtrUint8(0x5D4594, 1308069) = 162
	*memmap.PtrUint8(0x5D4594, 1308070) = 129
	*memmap.PtrUint8(0x5D4594, 1308071) = 100
	*memmap.PtrUint8(0x5D4594, 1308072) = 78
	*memmap.PtrUint8(0x5D4594, 1308073) = 64
	*memmap.PtrUint8(0x5D4594, 1308074) = 46
	*memmap.PtrUint8(0x5D4594, 1308075) = 65
	*memmap.PtrUint8(0x5D4594, 1308076) = 50
	*memmap.PtrUint8(0x5D4594, 1308077) = 45
	*memmap.PtrUint8(0x5D4594, 1308078) = 171
	*memmap.PtrUint8(0x5D4594, 1308079) = 158
	*memmap.PtrUint8(0x5D4594, 1308081) = 175
	*memmap.PtrUint8(0x5D4594, 1308083) = 131
	*memmap.PtrUint8(0x5D4594, 1307892) = 243
	*memmap.PtrUint8(0x5D4594, 1307893) = 183
	*memmap.PtrUint8(0x5D4594, 1307894) = 159
	*memmap.PtrUint8(0x5D4594, 1307895) = 199
	*memmap.PtrUint8(0x5D4594, 1307896) = 132
	*memmap.PtrUint8(0x5D4594, 1307897) = 58
	*memmap.PtrUint8(0x5D4594, 1307899) = 170
	*memmap.PtrUint8(0x5D4594, 1307900) = 86
	*memmap.PtrUint8(0x5D4594, 1307901) = 146
	*memmap.PtrUint8(0x5D4594, 1307902) = 121
	*memmap.PtrUint8(0x5D4594, 1307903) = 106
	*memmap.PtrUint8(0x5D4594, 1307905) = 251
	*memmap.PtrUint8(0x5D4594, 1307906) = 186
	*memmap.PtrUint8(0x5D4594, 1307907) = 247
	*memmap.PtrUint8(0x5D4594, 1307910) = 63
	*memmap.PtrUint8(0x5D4594, 1307911) = 187
	*memmap.PtrUint8(0x5D4594, 1307912) = 239
	*memmap.PtrUint8(0x5D4594, 1307913) = 196
	*memmap.PtrUint8(0x5D4594, 1307914) = 194
	*memmap.PtrUint8(0x5D4594, 1307915) = 177
	*memmap.PtrUint8(0x5D4594, 1307916) = 253
	*memmap.PtrUint8(0x5D4594, 1307917) = 246
	*memmap.PtrUint8(0x5D4594, 1307918) = 102
	*memmap.PtrUint8(0x5D4594, 1307919) = 115
	*memmap.PtrUint8(0x5D4594, 1307920) = 77
	*memmap.PtrUint8(0x5D4594, 1307921) = 34
	*memmap.PtrUint8(0x5D4594, 1307922) = 229
	*memmap.PtrUint8(0x5D4594, 1307923) = 121
	*memmap.PtrUint8(0x5D4594, 1307924) = 25
	*memmap.PtrUint8(0x5D4594, 1307925) = 82
	*memmap.PtrUint8(0x5D4594, 1307927) = 60
	*memmap.PtrUint8(0x5D4594, 1307928) = 235
	*memmap.PtrUint8(0x5D4594, 1307929) = 229
	*memmap.PtrUint8(0x5D4594, 1307930) = 137
	*memmap.PtrUint8(0x5D4594, 1307931) = 147
	*memmap.PtrUint8(0x5D4594, 1307932) = 0
	*memmap.PtrUint8(0x5D4594, 1307933) = 0
	*memmap.PtrUint8(0x5D4594, 1307934) = 0
	*memmap.PtrUint8(0x5D4594, 1307935) = 37
	*memmap.PtrUint8(0x5D4594, 1307940) = 149
	*memmap.PtrUint8(0x5D4594, 1307941) = 108
	*memmap.PtrUint8(0x5D4594, 1307942) = 43
	*memmap.PtrUint8(0x5D4594, 1307943) = 52
	*memmap.PtrUint8(0x5D4594, 1307944) = 25
	*memmap.PtrUint8(0x5D4594, 1307945) = 0
	*memmap.PtrUint8(0x5D4594, 1307946) = 150
	*memmap.PtrUint8(0x5D4594, 1307947) = 55
	*memmap.PtrUint8(0x5D4594, 1307952) = 150
	*memmap.PtrUint8(0x5D4594, 1307955) = 131
	*memmap.PtrUint8(0x5D4594, 1307956) = 104
	*memmap.PtrUint8(0x5D4594, 1307961) = 117
	*memmap.PtrUint8(0x5D4594, 1307962) = 117
	*memmap.PtrUint8(0x5D4594, 1307963) = 117
	*memmap.PtrUint8(0x5D4594, 1307981) = 104
	*memmap.PtrUint8(0x5D4594, 1307948) = 0
	*memmap.PtrUint8(0x5D4594, 1307950) = 0
	*memmap.PtrUint8(0x5D4594, 1307984) = 0
	*memmap.PtrUint32(0x587000, 171384) = 0
	*memmap.PtrUint8(0x5D4594, 1307949) = 9
	*memmap.PtrUint8(0x5D4594, 1307951) = 12
	*memmap.PtrUint8(0x5D4594, 1307953) = 146
	*memmap.PtrUint8(0x5D4594, 1307954) = 81
	*memmap.PtrUint8(0x5D4594, 1307957) = 179
	*memmap.PtrUint8(0x5D4594, 1307958) = 121
	*memmap.PtrUint8(0x5D4594, 1307959) = 165
	*memmap.PtrUint8(0x5D4594, 1307960) = 66
	*memmap.PtrUint8(0x5D4594, 1307964) = 100
	*memmap.PtrUint8(0x5D4594, 1307965) = 130
	*memmap.PtrUint8(0x5D4594, 1307966) = 125
	*memmap.PtrUint8(0x5D4594, 1307967) = 56
	*memmap.PtrUint8(0x5D4594, 1307968) = 48
	*memmap.PtrUint8(0x5D4594, 1307969) = 40
	*memmap.PtrUint8(0x5D4594, 1307970) = 108
	*memmap.PtrUint8(0x5D4594, 1307971) = 81
	*memmap.PtrUint8(0x5D4594, 1307972) = 58
	*memmap.PtrUint8(0x5D4594, 1307973) = 52
	*memmap.PtrUint8(0x5D4594, 1307974) = 40
	*memmap.PtrUint8(0x5D4594, 1307975) = 39
	*memmap.PtrUint8(0x5D4594, 1307976) = 143
	*memmap.PtrUint8(0x5D4594, 1307977) = 142
	*memmap.PtrUint8(0x5D4594, 1307978) = 124
	*memmap.PtrUint8(0x5D4594, 1307979) = 56
	*memmap.PtrUint8(0x5D4594, 1307980) = 29
	*memmap.PtrUint8(0x5D4594, 1307982) = 15
	*memmap.PtrUint8(0x5D4594, 1307983) = 88
	*memmap.PtrUint8(0x5D4594, 1307985) = 87
	*memmap.PtrUint8(0x5D4594, 1307986) = 53
	*memmap.PtrUint8(0x5D4594, 1307987) = 53
}
func sub_4A6890() int {
	nox_wnd_xxx_1308092.SetState(NOX_GUI_ANIM_OUT)
	sub_43BE40(2)
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100)
	sub_4A68C0()
	return 1
}
func sub_4A6B50(a1 *wchar2_t) int32 {
	var (
		v1  *wchar2_t
		v2  int32
		v3  int32
		v4  int32
		v5  *int16
		v6  wchar2_t
		v7  int32
		i   *wchar2_t
		v10 int32
		v11 int32
		v12 [26]int16
	)
	v1 = a1
	v2 = 0
	v3 = 1
	v10 = 0
	v4 = int32(nox_wcslen(a1))
	if v4 >= 1 {
		v5 = &v12[0]
		v11 = v4
		for {
			if unicode.IsSpace(rune(*v1)) {
				if v3 == 0 {
					*v5 = int16(*v1)
					v5 = (*int16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(int16(0))*1))
					v10++
				}
			} else {
				if v3 == 1 {
					v6 = *v1
					if *v1 == 42 || v6 == 63 || v6 == 60 || v6 == 62 || v6 == 92 || v6 == 47 || v6 == 58 || v6 == 34 || v6 == 124 {
						*v1 = 45
					}
				}
				*v5 = int16(*v1)
				v5 = (*int16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(int16(0))*1))
				v10++
				v3 = 0
				v2 = 1
			}
			v1 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(wchar2_t(0))*1))
			v11--
			if v11 == 0 {
				break
			}
		}
		v12[v10] = 0
		if v2 != 0 {
			nox_wcscpy(a1, (*wchar2_t)(unsafe.Pointer(&v12[0])))
			v7 = int32(nox_wcslen((*wchar2_t)(unsafe.Pointer(&v12[0]))) - 1)
			if v7 >= 0 {
				for i = (*wchar2_t)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(wchar2_t(0))*uintptr(v7))); unicode.IsSpace(rune(*i)); i = (*wchar2_t)(unsafe.Add(unsafe.Pointer(i), -int(unsafe.Sizeof(wchar2_t(0))*1))) {
					if func() int32 {
						p := &v7
						*p--
						return *p
					}() < 0 {
						return v2
					}
				}
				*(*wchar2_t)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(wchar2_t(0))*uintptr(v7+1))) = 0
			}
		}
	}
	return v2
}
func sub_4A6C90() int {
	v0 := nox_wnd_xxx_1308092.Func13Ptr.Get()
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_1308092)
	nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)))
	nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308088)))
	if v0 != nil {
		v0()
	} else {
		nox_client_resetScreenParticles_431510()
		nox_gui_draw()
		if !noxflags.HasGame(0x2000) {
			nox_client_guiXxxDestroy_4A24A0()
			return 1
		}
		nox_xxx_serverHost_43B4D0()
		return 1
	}
	return 1
}
func sub_4A6D20(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = int32(uintptr(win.C()))
		v1    int32
		v2    uint16
		v3    int32
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		v8    int32
		v10   int32
		yTop  int32
		xLeft int32
		v13   int32
	)
	v1 = a1
	v2 = *(*uint16)(unsafe.Add(a1, 32))
	v3 = int32(*(*uint32)(unsafe.Add(a1, 32)) >> 16)
	nox_client_wndGetPosition_46AA60((*gui.Window)(a1), &xLeft, &yTop)
	v4 = int32(*(*uint32)(unsafe.Add(a1, 20)))
	v5 = int32(*(*uint32)(unsafe.Add(a1, 16)))
	v6 = int32(uint16(int16(v3))) + int32(v2)*32
	v13 = int32(*(*uint32)(unsafe.Add(a1, 28)) - uint32(v4))
	v7 = int32(*(*uint32)(unsafe.Add(v1, 24)) - uint32(v5))
	*(*uint8)(unsafe.Pointer(&v5)) = *memmap.PtrUint8(0x5D4594, uintptr(v6*3)+1307798)
	*(*uint8)(unsafe.Pointer(&v4)) = *memmap.PtrUint8(0x5D4594, uintptr(v6*3)+1307797)
	v10 = v5
	*(*uint8)(unsafe.Pointer(&v5)) = *memmap.PtrUint8(0x5D4594, uintptr(v6*3)+1307796)
	v8 = int32(nox_color_rgb_4344A0(v5, v4, v10))
	nox_client_drawSetColor_434460(v8)
	nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, v7, v13)
	return 1
}
func sub_4A6DC0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1  = (*uint32)(win.C())
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
		v12 int32
		v13 int32
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
		v24 *int32
		v25 int32
		v26 int32
		v27 int32
		i   int32
		v29 int32
		v30 int32
		v31 int32
		v32 int32
		v33 int32
		j   int32
		v35 int32
		v36 int32
		v37 int32
		v38 int32
		v39 int32
		v40 int32
		v41 int32
		v42 int32
		k   int32
		v44 int32
		v45 int32
		v46 int32
		v47 int32
		v48 int32
		v49 int32
		v50 int32
		v52 int32
		v53 int32
		v54 int32
		v55 int32
	)
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(a1)), &v54, &v55)
	v1 = int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308096, 32))>>16)) + int32(*(*uint16)(unsafe.Add(dword_5d4594_1308096, 32)))*32
	v2 = int32(*memmap.PtrUint8(0x5D4594, uintptr(v1*3)+1307798))
	*(*uint8)(unsafe.Pointer(&v3)) = *memmap.PtrUint8(0x5D4594, uintptr(v1*3)+1307797)
	*(*uint8)(unsafe.Pointer(&v1)) = *memmap.PtrUint8(0x5D4594, uintptr(v1*3)+1307796)
	v4 = int32(nox_color_rgb_4344A0(v1, v3, v2))
	nox_draw_setMaterial_4341D0(6, v4)
	v5 = int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308100, 32))>>16)) + int32(*(*uint16)(unsafe.Add(dword_5d4594_1308100, 32)))*32
	v6 = int32(*memmap.PtrUint8(0x5D4594, uintptr(v5*3)+1307798))
	*(*uint8)(unsafe.Pointer(&v7)) = *memmap.PtrUint8(0x5D4594, uintptr(v5*3)+1307797)
	*(*uint8)(unsafe.Pointer(&v5)) = *memmap.PtrUint8(0x5D4594, uintptr(v5*3)+1307796)
	v8 = int32(nox_color_rgb_4344A0(v5, v7, v6))
	nox_draw_setMaterial_4341D0(1, v8)
	v9 = int32(dword_5d4594_1308144)
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308144, 4)))&8 != 0 {
		v10 = int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308108, 32)) >> 16))
		v11 = v10 + int32(*(*uint16)(unsafe.Add(dword_5d4594_1308108, 32)))*32
		*(*uint8)(unsafe.Pointer(&v9)) = *memmap.PtrUint8(0x5D4594, uintptr(v11*3)+1307797)
		v12 = int32(nox_color_rgb_4344A0(int32(*memmap.PtrUint8(0x5D4594, uintptr(v11*3)+1307796)), v9, int32(*memmap.PtrUint8(0x5D4594, uintptr((v10+int32(*(*uint16)(unsafe.Add(dword_5d4594_1308108, 32)))*32)*3)+1307798))))
		nox_draw_setMaterial_4341D0(2, v12)
	} else {
		nox_draw_setMaterial_4341D0(2, v4)
	}
	nox_draw_setMaterial_4341D0(3, v4)
	v13 = int32(dword_5d4594_1308148)
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308148, 4)))&8 != 0 {
		v14 = int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308112, 32)) >> 16))
		v15 = v14 + int32(*(*uint16)(unsafe.Add(dword_5d4594_1308112, 32)))*32
		*(*uint8)(unsafe.Pointer(&v13)) = *memmap.PtrUint8(0x5D4594, uintptr(v15*3)+1307797)
		*(*uint8)(unsafe.Pointer(&v15)) = *memmap.PtrUint8(0x5D4594, uintptr(v15*3)+1307796)
		v16 = int32(nox_color_rgb_4344A0(v15, v13, int32(*memmap.PtrUint8(0x5D4594, uintptr((v14+int32(*(*uint16)(unsafe.Add(dword_5d4594_1308112, 32)))*32)*3)+1307798))))
		nox_draw_setMaterial_4341D0(4, v16)
	} else {
		nox_draw_setMaterial_4341D0(4, v4)
	}
	v17 = int32(dword_5d4594_1308140)
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308140, 4)))&8 != 0 {
		v18 = int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308104, 32)) >> 16))
		v19 = v18 + int32(*(*uint16)(unsafe.Add(dword_5d4594_1308104, 32)))*32
		*(*uint8)(unsafe.Pointer(&v17)) = *memmap.PtrUint8(0x5D4594, uintptr(v19*3)+1307797)
		*(*uint8)(unsafe.Pointer(&v19)) = *memmap.PtrUint8(0x5D4594, uintptr(v19*3)+1307796)
		v20 = int32(nox_color_rgb_4344A0(v19, v17, int32(*memmap.PtrUint8(0x5D4594, uintptr((v18+int32(*(*uint16)(unsafe.Add(dword_5d4594_1308104, 32)))*32)*3)+1307798))))
		nox_draw_setMaterial_4341D0(5, v20)
	} else {
		nox_draw_setMaterial_4341D0(5, v4)
	}
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308136, 4)))&8 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x973A20, uintptr(int32(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 67)))*4+16))), v54, v55)
	} else {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x973A20, uintptr(int32(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 67)))*4+24))), v54, v55)
	}
	v21 = 0
	v22 = int32(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 67)))
	v23 = v22 * 3
	v24 = mem_getI32Ptr(0x973A20, uint32(v22*104+32))
	for {
		v25 = v21
		v26 = 1 << v21
		if 1<<v21 == 4 {
			v27 = 1
			for i = 3; i < 21; i += 3 {
				v29 = int32(uintptr(dword_5d4594_1308156))
				*(*uint8)(unsafe.Pointer(&v25)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(uint32(i)+uint32(uintptr(dword_5d4594_1308156)))), 14))
				*(*uint8)(unsafe.Pointer(&v23)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(uint32(i)+uint32(uintptr(dword_5d4594_1308156)))), 13))
				*(*uint8)(unsafe.Pointer(&v29)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(uint32(i)+uint32(uintptr(dword_5d4594_1308156)))), 12))
				nox_draw_setMaterial_4340A0(func() int32 {
					p := &v27
					x := *p
					*p++
					return x
				}(), v29, v23, v25)
			}
			v30 = int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308116, 32))>>16)) + int32(*(*uint16)(unsafe.Add(dword_5d4594_1308116, 32)))*32
			v31 = int32(*memmap.PtrUint8(0x5D4594, uintptr(v30*3)+1307798))
			*(*uint8)(unsafe.Pointer(&v23)) = *memmap.PtrUint8(0x5D4594, uintptr(v30*3)+1307797)
			*(*uint8)(unsafe.Pointer(&v30)) = *memmap.PtrUint8(0x5D4594, uintptr(v30*3)+1307796)
			v32 = int32(nox_color_rgb_4344A0(v30, v23, v31))
			nox_draw_setMaterial_4341D0(int32(*(*uint32)(unsafe.Add(dword_5d4594_1308156, 40))), v32)
		} else if v26 == 1024 {
			v33 = 1
			for j = 3; j < 21; j += 3 {
				v35 = int32(uintptr(dword_5d4594_1308160))
				*(*uint8)(unsafe.Pointer(&v25)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(dword_5d4594_1308160))+uint32(j))), 14))
				*(*uint8)(unsafe.Pointer(&v23)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(dword_5d4594_1308160))+uint32(j))), 13))
				*(*uint8)(unsafe.Pointer(&v35)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(dword_5d4594_1308160))+uint32(j))), 12))
				nox_draw_setMaterial_4340A0(func() int32 {
					p := &v33
					x := *p
					*p++
					return x
				}(), v35, v23, v25)
			}
			v36 = int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308120, 32))>>16)) + int32(*(*uint16)(unsafe.Add(dword_5d4594_1308120, 32)))*32
			v37 = int32(*memmap.PtrUint8(0x5D4594, uintptr(v36*3)+1307798))
			*(*uint8)(unsafe.Pointer(&v23)) = *memmap.PtrUint8(0x5D4594, uintptr(v36*3)+1307797)
			*(*uint8)(unsafe.Pointer(&v36)) = *memmap.PtrUint8(0x5D4594, uintptr(v36*3)+1307796)
			v38 = int32(nox_color_rgb_4344A0(v36, v23, v37))
			nox_draw_setMaterial_4341D0(int32(*(*uint32)(unsafe.Add(dword_5d4594_1308160, 40))), v38)
			v39 = int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308124, 32))>>16)) + int32(*(*uint16)(unsafe.Add(dword_5d4594_1308124, 32)))*32
			v40 = int32(*memmap.PtrUint8(0x5D4594, uintptr(v39*3)+1307798))
			*(*uint8)(unsafe.Pointer(&v41)) = *memmap.PtrUint8(0x5D4594, uintptr(v39*3)+1307797)
			*(*uint8)(unsafe.Pointer(&v39)) = *memmap.PtrUint8(0x5D4594, uintptr(v39*3)+1307796)
			v52 = int32(nox_color_rgb_4344A0(v39, v41, v40))
			nox_draw_setMaterial_4341D0(int32(*(*uint32)(unsafe.Add(dword_5d4594_1308160, 44))), v52)
		} else {
			if v26 != 1 {
				goto LABEL_27
			}
			v42 = 1
			for k = 3; k < 21; k += 3 {
				v44 = int32(uintptr(dword_5d4594_1308164))
				*(*uint8)(unsafe.Pointer(&v25)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(uint32(k)+uint32(uintptr(dword_5d4594_1308164)))), 14))
				*(*uint8)(unsafe.Pointer(&v23)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(uint32(k)+uint32(uintptr(dword_5d4594_1308164)))), 13))
				*(*uint8)(unsafe.Pointer(&v44)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(uint32(k)+uint32(uintptr(dword_5d4594_1308164)))), 12))
				nox_draw_setMaterial_4340A0(func() int32 {
					p := &v42
					x := *p
					*p++
					return x
				}(), v44, v23, v25)
			}
			v45 = int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308128, 32))>>16)) + int32(*(*uint16)(unsafe.Add(dword_5d4594_1308128, 32)))*32
			v46 = int32(*memmap.PtrUint8(0x5D4594, uintptr(v45*3)+1307798))
			*(*uint8)(unsafe.Pointer(&v23)) = *memmap.PtrUint8(0x5D4594, uintptr(v45*3)+1307797)
			*(*uint8)(unsafe.Pointer(&v45)) = *memmap.PtrUint8(0x5D4594, uintptr(v45*3)+1307796)
			v47 = int32(nox_color_rgb_4344A0(v45, v23, v46))
			nox_draw_setMaterial_4341D0(int32(*(*uint32)(unsafe.Add(dword_5d4594_1308164, 40))), v47)
			v48 = int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308132, 32))>>16)) + int32(*(*uint16)(unsafe.Add(dword_5d4594_1308132, 32)))*32
			v49 = int32(*memmap.PtrUint8(0x5D4594, uintptr(v48*3)+1307798))
			*(*uint8)(unsafe.Pointer(&v50)) = *memmap.PtrUint8(0x5D4594, uintptr(v48*3)+1307797)
			*(*uint8)(unsafe.Pointer(&v48)) = *memmap.PtrUint8(0x5D4594, uintptr(v48*3)+1307796)
			v53 = int32(nox_color_rgb_4344A0(v48, v50, v49))
			nox_draw_setMaterial_4341D0(int32(*(*uint32)(unsafe.Add(dword_5d4594_1308164, 36))), v53)
		}
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(unsafe.Pointer(uintptr(*v24))), v54, v55)
	LABEL_27:
		v21++
		v24 = (*int32)(unsafe.Add(unsafe.Pointer(v24), 4*1))
		if v21 >= 26 {
			break
		}
	}
	return 1
}
func sub_4A7270(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	a1 := int32(uintptr(win.C()))
	var (
		v3 int32
		v5 int2
	)
	if a2 != 5 {
		return 0
	}
	v5.field_4 = int32(a3 >> 16)
	v5.field_0 = int32(uint16(a3))
	v3 = nox_xxx_pointInRect_4281F0(&v5, (*int4)(unsafe.Add(a1, 16)))
	if v3 != 0 {
		return 0
	}
	sub_4A72D0(0xDEAD)
	return 1
}
func sub_4A72D0(a1 uint16) *uint32 {
	var result *uint32
	nox_xxx_wnd_46C6E0((*gui.Window)(dword_5d4594_1308088))
	result = (*uint32)(unsafe.Pointer(uintptr(nox_window_set_hidden((*gui.Window)(dword_5d4594_1308088), 1))))
	if int32(a1) < 0x20 {
		result = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308088)), dword_5d4594_1307792)))
		if result != nil {
			*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*8)) = uint32(int32(*memmap.PtrUint16(0x5D4594, 1307788)) | int32(a1)<<16)
		}
	}
	return result
}
func sub_4A7330(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v5 int32
		v6 int32
		v7 *uint32
	)
	if a2 == 16389 {
		nox_xxx_clientPlaySoundSpecial_452D80(920, 100)
		return 1
	} else if a2 == 16391 {
		v5 = int32(a4 >> 16)
		v6 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
		switch v6 {
		case 720:
			dword_5d4594_1307792 = uint32(v6)
			sub_4A7530(2)
			sub_4A7580(int32(uint16(a4)), v5)
		case 721, 722, 723, 724:
			dword_5d4594_1307792 = uint32(v6)
			sub_4A7530(1)
			sub_4A7580(int32(uint16(a4)), v5)
		case 725, 726, 727, 728, 729:
			dword_5d4594_1307792 = uint32(v6)
			sub_4A7530(0)
			sub_4A7580(int32(uint16(a4)), v5)
		case 731, 732, 733, 734:
			v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), v6-20)))
			if v7 != nil {
				nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v7)), int32((^*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1))>>3)&1))
			}
		case 761, 762, 763, 764, 765, 766, 767, 768, 769, 770, 771, 772, 773, 774, 775, 776, 777, 778,
			779, 780, 781, 782, 783, 784, 785, 786, 787, 788, 789, 790, 791, 792:
			sub_4A72D0(uint16(int16(v6 - 761)))
		case 799:
			if *memmap.PtrUint32(0x5D4594, 1308168) == 1 {
				nox_game_decStateInd_43BDC0()
			}
			nox_game_decStateInd_43BDC0()
			nox_game_decStateInd_43BDC0()
			dword_587000_171388 = 1
			if sub_4A75C0() != 0 {
				if int32(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 66))) == 0 {
					nox_xxx_gameSetMapPath_409D70(internCStr("war01a.map"))
				} else if int32(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 66))) == 1 {
					nox_xxx_gameSetMapPath_409D70(internCStr("wiz01a.map"))
				} else if int32(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 66))) == 2 {
					nox_xxx_gameSetMapPath_409D70(internCStr("con01a.map"))
				}
				sub_4A24C0(0)
				sub_4A6890()
				nox_wnd_xxx_1308092.Func13Ptr.Set(nil)
			}
		default:
		}
		nox_xxx_clientPlaySoundSpecial_452D80(921, 100)
		return 1
	} else {
		return 0
	}
}
func sub_4A7530(a1 uint16) *uint32 {
	var (
		v1     int32
		result *uint32
	)
	v1 = 761
	*memmap.PtrUint32(0x5D4594, 1307788) = uint32(a1)
	for {
		result = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308088)), v1)))
		if result != nil {
			*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*8)) = uint32(int32(a1) | int32(uint16(int16(v1-761)))<<16)
		}
		v1++
		if v1 > 792 {
			break
		}
	}
	return result
}
func sub_4A7580(a1 int32, a2 int32) int32 {
	nox_xxx_wndShowModalMB_46A8C0((*gui.Window)(dword_5d4594_1308088))
	sub_46C690((*gui.Window)(dword_5d4594_1308088))
	return nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308088)), int32(uint32(a1)-*(*uint32)(unsafe.Add(dword_5d4594_1308088, 8))), int32(uint32(a2)-*(*uint32)(unsafe.Add(dword_5d4594_1308088, 12))/2))
}
func sub_4A7A60(a1 int32) int32 {
	var result int32
	result = a1
	dword_587000_171388 = uint32(a1)
	return result
}
func sub_4A7A70(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1308168) = uint32(a1)
	return result
}
func sub_4A7A80(a1 *byte) int32 {
	var (
		result int32
		v2     uint32
		v3     int8
		v4     *uint8
		v5     *byte
	)
	if a1 == nil {
		return 0
	}
	v2 = uint32(libc.StrLen(a1) + 1)
	v3 = int8(uint8(v2))
	v2 >>= 2
	alloc.Memcpy(memmap.PtrOff(0x5D4594, 1308644), unsafe.Pointer(a1), uintptr(v2*4))
	v5 = (*byte)(unsafe.Add(unsafe.Pointer(a1), v2*4))
	v4 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v2)*4+1308644))
	*(*uint8)(unsafe.Pointer(&v2)) = uint8(v3)
	result = 1
	alloc.Memcpy(unsafe.Pointer(v4), unsafe.Pointer(v5), uintptr(v2&3))
	return result
}
func sub_4A7AC0(a1 *byte) int32 {
	var (
		result int32
		v2     uint32
		v3     int8
		v4     *uint8
		v5     *byte
	)
	if a1 == nil {
		return 0
	}
	v2 = uint32(libc.StrLen(a1) + 1)
	v3 = int8(uint8(v2))
	v2 >>= 2
	alloc.Memcpy(memmap.PtrOff(0x5D4594, 1308172), unsafe.Pointer(a1), uintptr(v2*4))
	v5 = (*byte)(unsafe.Add(unsafe.Pointer(a1), v2*4))
	v4 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v2)*4+1308172))
	*(*uint8)(unsafe.Pointer(&v2)) = uint8(v3)
	result = 1
	alloc.Memcpy(unsafe.Pointer(v4), unsafe.Pointer(v5), uintptr(v2&3))
	return result
}
func sub_4A7B00(a1 *byte) int32 {
	var (
		result int32
		v2     uint32
		v3     int8
		v4     *uint8
		v5     *byte
	)
	if a1 == nil {
		return 0
	}
	v2 = uint32(libc.StrLen(a1) + 1)
	v3 = int8(uint8(v2))
	v2 >>= 2
	alloc.Memcpy(memmap.PtrOff(0x5D4594, 1308352), unsafe.Pointer(a1), uintptr(v2*4))
	v5 = (*byte)(unsafe.Add(unsafe.Pointer(a1), v2*4))
	v4 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v2)*4+1308352))
	*(*uint8)(unsafe.Pointer(&v2)) = uint8(v3)
	result = 1
	alloc.Memcpy(unsafe.Pointer(v4), unsafe.Pointer(v5), uintptr(v2&3))
	return result
}
func sub_4A7B40(a1 *byte) int32 {
	var (
		v2 *byte
		v3 int32
		v4 *uint8
	)
	if a1 == nil {
		return 0
	}
	v2 = *(**byte)(memmap.PtrOff(0x587000, 171856))
	v3 = 0
	if *memmap.PtrUint32(0x587000, 171856) != 0 {
		v4 = (*uint8)(memmap.PtrOff(0x587000, 171856))
		for nox_strcmpi(v2, a1) != 0 {
			v2 = (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2)))))
			v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 8))
			v3++
			if v2 == nil {
				return 1
			}
		}
		*memmap.PtrUint32(0x5D4594, 1308184) = *memmap.PtrUint32(0x587000, uintptr(v3*8)+171860)
	}
	return 1
}
func sub_4A7BA0(a1 *byte) int32 {
	var result int32
	result = int32(uintptr(unsafe.Pointer(a1)))
	if a1 != nil {
		*memmap.PtrUint32(0x5D4594, 1308740) = uint32(libc.Atoi(libc.GoString(a1)))
		result = 1
	}
	return result
}
func sub_4A7BC0(a1 *byte) int32 {
	var (
		result int32
		v2     uint32
		v3     int8
		v4     *uint8
		v5     *byte
	)
	if a1 == nil {
		return 0
	}
	v2 = uint32(libc.StrLen(a1) + 1)
	v3 = int8(uint8(v2))
	v2 >>= 2
	alloc.Memcpy(memmap.PtrOff(0x5D4594, 1308324), unsafe.Pointer(a1), uintptr(v2*4))
	v5 = (*byte)(unsafe.Add(unsafe.Pointer(a1), v2*4))
	v4 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v2)*4+1308324))
	*(*uint8)(unsafe.Pointer(&v2)) = uint8(v3)
	result = 1
	alloc.Memcpy(unsafe.Pointer(v4), unsafe.Pointer(v5), uintptr(v2&3))
	return result
}
func sub_4A7C00(a1 *byte) int32 {
	var (
		result int32
		v2     uint32
		v3     int8
		v4     *uint8
		v5     *byte
	)
	if a1 == nil {
		return 0
	}
	v2 = uint32(libc.StrLen(a1) + 1)
	v3 = int8(uint8(v2))
	v2 >>= 2
	alloc.Memcpy(memmap.PtrOff(0x5D4594, 1308364), unsafe.Pointer(a1), uintptr(v2*4))
	v5 = (*byte)(unsafe.Add(unsafe.Pointer(a1), v2*4))
	v4 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v2)*4+1308364))
	*(*uint8)(unsafe.Pointer(&v2)) = uint8(v3)
	result = 1
	alloc.Memcpy(unsafe.Pointer(v4), unsafe.Pointer(v5), uintptr(v2&3))
	return result
}
func sub_4A7C40(a1 *byte) int32 {
	var result int32
	result = int32(uintptr(unsafe.Pointer(a1)))
	if a1 != nil {
		*memmap.PtrUint32(0x5D4594, 1308188) = uint32(libc.Atoi(libc.GoString(a1)))
		result = 1
	}
	return result
}
func sub_4A7C60(a1 *byte) int32 {
	var (
		v1 *byte
		v2 *byte
	)
	if a1 == nil {
		return 0
	}
	*memmap.PtrUint32(0x5D4594, 1308736) = 0
	*memmap.PtrUint32(0x5D4594, 1308732) = 0
	v1 = libc.StrTok(a1, internCStr(",\t\r\n"))
	if v1 != nil {
		*memmap.PtrUint32(0x5D4594, 1308732) = uint32(libc.Atoi(libc.GoString(v1)))
	}
	v2 = libc.StrTok(nil, internCStr(" \t\r\n"))
	if v2 != nil {
		*memmap.PtrUint32(0x5D4594, 1308736) = uint32(libc.Atoi(libc.GoString(v2)))
	}
	if *memmap.PtrUint32(0x5D4594, 1308732) != 0 && *memmap.PtrUint32(0x5D4594, 1308736) != 0 {
		return 1
	} else {
		return 0
	}
}
func sub_4A7CE0(a1 *byte) int32 {
	var result int32
	result = int32(uintptr(unsafe.Pointer(a1)))
	if a1 != nil {
		*memmap.PtrUint32(0x5D4594, 1308728) = uint32(libc.Atoi(libc.GoString(a1)))
		result = 1
	}
	return result
}
func sub_4A7D00(a1 *byte) int32 {
	var (
		result int32
		v2     uint32
		v3     int8
		v4     *uint8
		v5     *byte
	)
	if a1 == nil {
		return 0
	}
	result = 0
	if libc.StrLen(a1) <= 0x80 {
		v2 = uint32(libc.StrLen(a1) + 1)
		v3 = int8(uint8(v2))
		v2 >>= 2
		alloc.Memcpy(memmap.PtrOff(0x5D4594, 1308192), unsafe.Pointer(a1), uintptr(v2*4))
		v5 = (*byte)(unsafe.Add(unsafe.Pointer(a1), v2*4))
		v4 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v2)*4+1308192))
		*(*uint8)(unsafe.Pointer(&v2)) = uint8(v3)
		result = 1
		alloc.Memcpy(unsafe.Pointer(v4), unsafe.Pointer(v5), uintptr(v2&3))
	}
	return result
}
func sub_4A7D50(a1 *byte) int32 {
	var result int32
	result = int32(uintptr(unsafe.Pointer(a1)))
	if a1 != nil {
		*memmap.PtrUint32(0x5D4594, 1308348) = uint32(libc.Atoi(libc.GoString(a1)))
		result = 1
	}
	return result
}
func sub_4A7EF0() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 1308732))
}
func nox_xxx_wndButtonProc_4A7F50(win *gui.Window, ev, a3, a4 uintptr) uintptr {
	switch ev {
	case 5:
		win.DrawData().Field0 |= 4
		return 1
	case 6, 7:
		if (win.DrawData().Field0 & 4) == 0 {
			return 0
		}
		nox_window_call_field_94_fnc(win.DrawData().Window, 0x4000|7, uintptr(unsafe.Pointer(win)), a3)
		win.DrawData().Field0 &= 0xFFFFFFFB
		return 1
	case 8:
		nox_window_call_field_94_fnc(win.DrawData().Window, 0x4000, uintptr(unsafe.Pointer(win)), a3)
		return 1
	case 17:
		if win.DrawData().Style&0x100 != 0 {
			win.DrawData().Field0 |= 2
			nox_window_call_field_94_fnc(win.DrawData().Window, 0x4000|5, uintptr(unsafe.Pointer(win)), a3)
			nox_xxx_windowFocus_46B500(win)
		}
		return 1
	case 18:
		if win.DrawData().Style&0x100 != 0 {
			win.DrawData().Field0 &= 0xFFFFFFFD
			nox_window_call_field_94_fnc(win.DrawData().Window, 0x4000|6, uintptr(unsafe.Pointer(win)), a3)
		}
		if win.DrawData().Field0&4 != 0 {
			win.DrawData().Field0 &= 0xFFFFFFFB
		}
		return 1
	case 21:
		switch a3 {
		case 15, 205, 208:
			if a4 == 2 {
				nox_xxx_wndRetNULL_46A8A0()
			}
			return 1
		case 28, 57:
			if a4 != 1 {
				win.DrawData().Field0 |= 4
				return 1
			}
			if win.DrawData().Field0&4 != 0 {
				nox_window_call_field_94_fnc(win.DrawData().Window, 0x4000|7, uintptr(unsafe.Pointer(win)), 0)
				win.DrawData().Field0 &= 0xFFFFFFFB
			}
			return 1
		case 200, 203:
			if a4 == 2 {
				nox_xxx_wndRetNULL_0_46A8B0()
			}
			return 1
		default:
			return 0
		}
	default:
		return 0
	}
}
func nox_xxx_wndButtonDrawNoImg_4A81D0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = int32(uintptr(win.C()))
		a2    = int32(uintptr(draw.C()))
		v2    int32
		v3    int32
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		v9    int32
		xLeft int32
		yTop  int32
	)
	v2 = a2
	v3 = int32(*(*uint32)(unsafe.Add(a2, 28)))
	v4 = int32(*(*uint32)(unsafe.Add(a2, 20)))
	nox_client_wndGetPosition_46AA60((*gui.Window)(a1), &xLeft, &yTop)
	if int32(*(*uint8)(unsafe.Add(a1, 4)))&8 != 0 {
		if *(*uint32)(v2)&4 != 0 {
			v4 = int32(*(*uint32)(unsafe.Add(v2, 52)))
		} else if *(*uint32)(v2)&2 != 0 {
			v3 = int32(*(*uint32)(unsafe.Add(v2, 36)))
		}
	} else {
		v4 = int32(*(*uint32)(unsafe.Add(v2, 44)))
	}
	if uint32(v3) != 0x80000000 {
		nox_client_drawSetColor_434460(v3)
		nox_client_drawBorderLines_49CC70(xLeft, yTop, int32(*(*uint32)(unsafe.Add(a1, 8))), int32(*(*uint32)(unsafe.Add(a1, 12))))
	}
	if uint32(v4) != 0x80000000 {
		nox_client_drawSetColor_434460(v4)
		nox_client_drawRectFilledOpaque_49CE30(xLeft+1, yTop+1, int32(*(*uint32)(unsafe.Add(a1, 8))-2), int32(*(*uint32)(unsafe.Add(a1, 12))-2))
	}
	if int32(*(*uint16)(unsafe.Add(v2, 72))) != 0 {
		v5 = int32(uint32(xLeft) + *(*uint32)(unsafe.Add(a1, 8))/2)
		v6 = int32(uint32(yTop) + *(*uint32)(unsafe.Add(a1, 12))/2)
		if (*(*uint32)(unsafe.Add(a1, 4)) & 0x2000) == 0x2000 {
			nox_draw_enableTextSmoothing_43F670(1)
		}
		nox_xxx_drawGetStringSize_43F840(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), &a2, nil, 0)
		if *(*uint32)(unsafe.Add(v2, 68)) != 0x80000000 {
			nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(v2, 68))))
			v9 = int32(*(*uint32)(unsafe.Add(a1, 8)))
			v7 = nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(v2, 200)))
			nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), v5-a2/2, v6-v7/2, v9, 0)
		}
		nox_draw_enableTextSmoothing_43F670(0)
	}
	return 1
}
func nox_xxx_wndButtonInit_4A8340(a1 int32) int32 {
	var result int32
	if int32(int8(*(*uint8)(unsafe.Add(a1, 4)))) >= 0 {
		result = nox_window_set_all_funcs((*gui.Window)(a1), nox_xxx_wndButtonProc_4A7F50, nox_xxx_wndButtonDrawNoImg_4A81D0, nil)
	} else {
		result = nox_window_set_all_funcs((*gui.Window)(a1), nox_xxx_wndButtonProc_4A7F50, nox_xxx_wndButtonDraw_4A8380, nil)
	}
	return result
}
func nox_xxx_wndButtonDraw_4A8380(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1p = (*uint32)(win.C())
		a2p = int32(uintptr(draw.C()))
		v2  int32
		v3  *uint32
		v4  int32
		v5  int32
		v7  int32
		v8  int32
		v10 int32
		v11 int32
	)
	v2 = a2p
	v3 = a1p
	v4 = int32(*(*uint32)(unsafe.Add(a2p, 32)))
	v5 = int32(*(*uint32)(unsafe.Add(a2p, 24)))
	var a1, a2 uint32
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(a1p)), &a1, &a2)
	if *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1))&8 != 0 {
		if *(*uint32)(v2)&4 != 0 {
			v4 = int32(*(*uint32)(unsafe.Add(v2, 56)))
		} else if *(*uint32)(v2)&2 != 0 {
			v4 = int32(*(*uint32)(unsafe.Add(v2, 40)))
		}
	} else {
		v5 = int32(*(*uint32)(unsafe.Add(v2, 48)))
	}
	if v5 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(v5), int32(a1+*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*24))), int32(a2+*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*25))))
	}
	if v4 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(v4), int32(a1+*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*24))), int32(a2+*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*25))))
	}
	if int32(*(*uint16)(unsafe.Add(v2, 72))) != 0 {
		v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) & 0x2000)
		a1 += *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2)) / 2
		a2 += *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3)) / 2
		if v7 == 0x2000 {
			nox_draw_enableTextSmoothing_43F670(1)
		}
		nox_xxx_drawGetStringSize_43F840(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), &v11, nil, 0)
		if *(*uint32)(unsafe.Add(v2, 68)) != 0x80000000 {
			nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(v2, 68))))
			v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2)))
			v8 = nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(v2, 200)))
			nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), int32(a1)-v11/2, int32(a2)-v8/2, v10, 0)
		}
		nox_draw_enableTextSmoothing_43F670(0)
	}
	return 1
}
func nox_xxx_wndRadioButtonProc_4A84E0(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		a1  = (*uint32)(win.C())
		v4  int32
		v5  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		i   *uint32
		v12 int32
		v13 int32
		j   *uint32
	)
	switch a2 {
	case 5:
		return 1
	case 6, 7:
		v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)))
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*99)))
		if v9&4 != 0 {
			if v9&2 != 0 {
				return 1
			} else {
				return 0
			}
		}
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*13))), 16391, uintptr(unsafe.Pointer(a1)), a3)
		if v10 != 0 {
			for i = *(**uint32)(unsafe.Add(v10, 400)); i != nil; i = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*97))) {
				if i != a1 && *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*10)) == *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*10)) {
					*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*9)) &= 0xFFFFFFFB
				}
			}
		}
		v12 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)))
		*(*uint8)(unsafe.Pointer(&v12)) = uint8(int8(v12 | 4))
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)) = uint32(v12)
		return 1
	case 8:
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*13))), 0x4000, uintptr(unsafe.Pointer(a1)), a3)
		return 1
	case 17:
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*11)))
		if (v4 & 0x100) == 0 {
			return 1
		}
		v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)))
		*(*uint8)(unsafe.Pointer(&v5)) = uint8(int8(v5 | 2))
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)) = uint32(v5)
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*13))), 16389, uintptr(unsafe.Pointer(a1)), a3)
		nox_xxx_windowFocus_46B500((*gui.Window)(unsafe.Pointer(a1)))
		return 1
	case 18:
		v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*11)))
		if (v7 & 0x100) == 0 {
			return 1
		}
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*13)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)) &= 0xFFFFFFFD
		nox_window_call_field_94_fnc((*gui.Window)(v8), 16390, uintptr(unsafe.Pointer(a1)), a3)
		return 1
	case 21:
		switch a3 {
		case 15, 205, 208:
			if a4 != 2 {
				return 1
			}
			nox_xxx_wndRetNULL_46A8A0()
			return 1
		case 28, 57:
			if a4 != 2 {
				return 1
			}
			v13 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*99)))
			if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9))&4 != 0 {
				return 1
			}
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*13))), 16391, uintptr(unsafe.Pointer(a1)), 0)
			if v13 != 0 {
				for j = *(**uint32)(unsafe.Add(v13, 400)); j != nil; j = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(j), 4*97))) {
					if j != a1 && *(*uint32)(unsafe.Add(unsafe.Pointer(j), 4*10)) == *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*10)) {
						*(*uint32)(unsafe.Add(unsafe.Pointer(j), 4*9)) &= 0xFFFFFFFB
					}
				}
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9)) ^= 4
			return 1
		case 200, 203:
			if a4 == 2 {
				nox_xxx_wndRetNULL_0_46A8B0()
			}
			return 1
		default:
			return 0
		}
	default:
		return 0
	}
}
func nox_xxx_wndRadioButtonSetAllFn_4A87E0(a1 int32) int32 {
	var result int32
	if int32(int8(*(*uint8)(unsafe.Add(a1, 4)))) >= 0 {
		result = nox_window_set_all_funcs((*gui.Window)(a1), nox_xxx_wndRadioButtonProc_4A84E0, nox_xxx_wndRadioButtonDrawNoImg_4A8820, nil)
	} else {
		result = nox_window_set_all_funcs((*gui.Window)(a1), nox_xxx_wndRadioButtonProc_4A84E0, nox_xxx_wndRadioButtonDraw_4A8A20, nil)
	}
	return result
}
func nox_xxx_wndRadioButtonDrawNoImg_4A8820(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1  = int32(uintptr(win.C()))
		a2  = int32(uintptr(draw.C()))
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
	)
	v2 = a2
	v3 = a1
	v12 = int32(*(*uint32)(unsafe.Add(a2, 28)))
	a2 = int32(*(*uint32)(unsafe.Add(a2, 20)))
	nox_client_wndGetPosition_46AA60((*gui.Window)(a1), &v14, &v15)
	if int32(*(*uint8)(unsafe.Add(v3, 4)))&8 != 0 {
		if int32(*(*uint8)(v2))&2 != 0 {
			v12 = int32(*(*uint32)(unsafe.Add(v2, 36)))
		}
	} else {
		a2 = int32(*(*uint32)(unsafe.Add(v2, 44)))
	}
	v4 = v14 + 4
	v5 = int32(*(*uint32)(unsafe.Add(v3, 12))/2 + uint32(v15) - 5)
	v13 = nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(v2, 200)))
	if uint32(a2) != 0x80000000 {
		nox_client_drawSetColor_434460(a2)
		nox_client_drawRectFilledOpaque_49CE30(v4, v5, 10, 10)
	}
	if uint32(v12) != 0x80000000 {
		nox_client_drawSetColor_434460(v12)
		nox_client_drawBorderLines_49CC70(v4, v5, 10, 10)
	}
	if int32(*(*uint8)(v2))&4 != 0 && *(*uint32)(unsafe.Add(v2, 52)) != 0x80000000 {
		nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(v2, 52))))
		nox_client_drawRectFilledOpaque_49CE30(v4+1, v5+1, 8, 8)
	}
	if (*(*uint32)(unsafe.Add(v3, 4)) & 0x2000) == 0x2000 {
		nox_draw_enableTextSmoothing_43F670(1)
	}
	if **(**uint32)(unsafe.Add(v3, 32)) != 0 {
		v6 = int32(*(*uint32)(unsafe.Add(v3, 12)))
		v14 += int32(*(*uint32)(unsafe.Add(v3, 8)) / 2)
		v7 = v6/2 + v15
		v8 = int32(*(*uint32)(unsafe.Add(v2, 200)))
		v15 = v7
		nox_xxx_drawGetStringSize_43F840(v8, (*wchar2_t)(unsafe.Add(v2, 72)), &a1, nil, 0)
		if *(*uint32)(unsafe.Add(v2, 68)) != 0x80000000 {
			nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(v2, 68))))
			v11 = int32(*(*uint32)(unsafe.Add(v3, 8)))
			v9 = nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(v2, 200)))
			nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), v14-a1/2, v15-v9/2, v11, 0)
		}
	} else if *(*uint32)(unsafe.Add(v2, 68)) != 0x80000000 {
		nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(v2, 68))))
		nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), v4+14, v5-v13/2+5, int32(*(*uint32)(unsafe.Add(v3, 8))), 0)
	}
	nox_draw_enableTextSmoothing_43F670(0)
	return 1
}
func nox_xxx_wndRadioButtonDraw_4A8A20(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1  = int32(uintptr(win.C()))
		a2  = int32(uintptr(draw.C()))
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v12 int32
		v13 int32
		v14 int32
	)
	v2 = a2
	v3 = int32(*(*uint32)(unsafe.Add(a2, 32)))
	v4 = int32(*(*uint32)(unsafe.Add(a2, 24)))
	nox_client_wndGetPosition_46AA60((*gui.Window)(a1), &v13, &v14)
	if int32(*(*uint8)(unsafe.Add(a1, 4)))&8 != 0 {
		if int32(*(*uint8)(v2))&2 != 0 {
			v3 = int32(*(*uint32)(unsafe.Add(v2, 40)))
		}
	} else {
		v4 = int32(*(*uint32)(unsafe.Add(v2, 48)))
	}
	if v4 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(v4), int32(uint32(v13)+*(*uint32)(unsafe.Add(v2, 60))), int32(uint32(v14)+*(*uint32)(unsafe.Add(v2, 64))))
	}
	if int32(*(*uint8)(v2))&4 != 0 {
		v5 = int32(*(*uint32)(unsafe.Add(v2, 56)))
		if v5 != 0 {
			nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(v5), int32(uint32(v13)+*(*uint32)(unsafe.Add(v2, 60))), int32(uint32(v14)+*(*uint32)(unsafe.Add(v2, 64))))
		}
	} else if v3 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(v3), int32(uint32(v13)+*(*uint32)(unsafe.Add(v2, 60))), int32(uint32(v14)+*(*uint32)(unsafe.Add(v2, 64))))
	}
	if (*(*uint32)(unsafe.Add(a1, 4)) & 0x2000) == 0x2000 {
		nox_draw_enableTextSmoothing_43F670(1)
	}
	if **(**uint32)(unsafe.Add(a1, 32)) != 0 {
		v6 = int32(*(*uint32)(unsafe.Add(a1, 8)))
		v7 = int32(*(*uint32)(unsafe.Add(v2, 200)))
		v14 += int32(*(*uint32)(unsafe.Add(a1, 12)) / 2)
		v13 += v6 / 2
		nox_xxx_drawGetStringSize_43F840(v7, (*wchar2_t)(unsafe.Add(v2, 72)), &a2, nil, 0)
		if *(*uint32)(unsafe.Add(v2, 68)) != 0x80000000 {
			nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(v2, 68))))
			v12 = int32(*(*uint32)(unsafe.Add(a1, 8)))
			v8 = nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(v2, 200)))
			nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), v13-a2/2, v14-v8/2, v12, 0)
		}
	} else {
		v9 = int32(*(*uint32)(unsafe.Add(a1, 12)) - uint32(nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(v2, 200)))))
		v10 = int32(*(*uint32)(unsafe.Add(v2, 68)))
		v14 += v9 / 2
		v13 += 28
		if uint32(v10) != 0x80000000 {
			nox_xxx_drawSetTextColor_434390(v10)
			nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), v13, v14, int32(*(*uint32)(unsafe.Add(a1, 8))), 0)
		}
	}
	nox_draw_enableTextSmoothing_43F670(0)
	return 1
}
func nox_xxx_wndCheckBoxProc_4A8C00(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		a1 = int32(uintptr(win.C()))
		v4 int32
		v5 int32
		v7 int32
		v8 int32
		v9 int32
	)
	switch a2 {
	case 5:
		return 1
	case 6, 7:
		v8 = a1
		if (int32(*(*uint8)(unsafe.Add(a1, 36))) & 2) == 0 {
			return 0
		}
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16391, uintptr(a1), a3)
		*(*uint32)(unsafe.Add(v8, 36)) ^= 4
		return 1
	case 8:
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 0x4000, uintptr(a1), a3)
		return 1
	case 17:
		v4 = int32(*(*uint32)(unsafe.Add(a1, 44)))
		if v4&0x100 != 0 {
			v5 = int32(*(*uint32)(unsafe.Add(a1, 52)))
			*(*uint32)(unsafe.Add(a1, 36)) |= 2
			nox_window_call_field_94_fnc((*gui.Window)(v5), 16389, uintptr(a1), a3)
			nox_xxx_windowFocus_46B500((*gui.Window)(a1))
		}
		return 1
	case 18:
		v7 = int32(*(*uint32)(unsafe.Add(a1, 44)))
		if v7&0x100 != 0 {
			v9 = int32(*(*uint32)(unsafe.Add(a1, 52)))
			*(*uint32)(unsafe.Add(a1, 36)) &= 0xFFFFFFFD
			nox_window_call_field_94_fnc((*gui.Window)(v9), 16390, uintptr(a1), a3)
		}
		return 1
	case 21:
		switch a3 {
		case 15, 205, 208:
			if a4 != 2 {
				return 1
			}
			nox_xxx_wndRetNULL_46A8A0()
			return 1
		case 28, 57:
			if a4 == 2 {
				v8 = a1
				nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v8, 52))), 16391, uintptr(v8), 0)
				*(*uint32)(unsafe.Add(v8, 36)) ^= 4
			}
			return 1
		case 200, 203:
			if a4 == 2 {
				nox_xxx_wndRetNULL_0_46A8B0()
			}
			return 1
		default:
			return 0
		}
	default:
		return 0
	}
}
func nox_xxx_wndCheckBoxInit_4A8E60(a1 int32) {
	if int32(int8(*(*uint8)(unsafe.Add(a1, 4)))) >= 0 {
		nox_window_set_all_funcs((*gui.Window)(a1), nox_xxx_wndCheckBoxProc_4A8C00, nox_xxx_wndDrawCheckBoxNoImg_4A8EA0, nil)
	} else {
		nox_window_set_all_funcs((*gui.Window)(a1), nox_xxx_wndCheckBoxProc_4A8C00, nox_xxx_wndDrawCheckBox_4A9050, nil)
	}
}
func nox_xxx_wndDrawCheckBoxNoImg_4A8EA0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = int32(uintptr(win.C()))
		a2    = int32(uintptr(draw.C()))
		v2    int32
		v3    int32
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		v9    int32
		xLeft int32
		yTop  int32
		v12   int32
	)
	v2 = a2
	v3 = int32(*(*uint32)(unsafe.Add(a2, 28)))
	v12 = int32(*(*uint32)(unsafe.Add(a2, 20)))
	nox_client_wndGetPosition_46AA60((*gui.Window)(a1), &xLeft, &yTop)
	if int32(*(*uint8)(unsafe.Add(a1, 4)))&8 != 0 {
		if int32(*(*uint8)(v2))&2 != 0 {
			v3 = int32(*(*uint32)(unsafe.Add(v2, 36)))
		}
	} else {
		v12 = int32(*(*uint32)(unsafe.Add(v2, 44)))
	}
	v4 = int32(uint32(yTop) + *(*uint32)(unsafe.Add(a1, 12))/2 - 5)
	v5 = xLeft + 4
	if uint32(v12) != 0x80000000 {
		nox_client_drawSetColor_434460(v12)
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, int32(*(*uint32)(unsafe.Add(a1, 8))), int32(*(*uint32)(unsafe.Add(a1, 12))))
	}
	if uint32(v3) != 0x80000000 {
		nox_client_drawSetColor_434460(v3)
		nox_client_drawBorderLines_49CC70(v5, v4, 10, 10)
	}
	if int32(*(*uint8)(v2))&4 != 0 {
		if *(*uint32)(unsafe.Add(v2, 52)) != 0x80000000 {
			nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(v2, 52))))
			nox_client_drawRectFilledOpaque_49CE30(v5+1, v4+1, 8, 8)
			if uint32(v3) != 0x80000000 {
				nox_client_drawSetColor_434460(v3)
				nox_client_drawAddPoint_49F500(v5, v4)
				nox_xxx_rasterPointRel_49F570(9, 9)
				nox_client_drawLineFromPoints_49E4B0()
				nox_client_drawAddPoint_49F500(v5, v4+9)
				nox_xxx_rasterPointRel_49F570(9, -9)
				nox_client_drawLineFromPoints_49E4B0()
			}
		}
	}
	v6 = 5 - nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(v2, 200)))/2 + v4
	v7 = v5 + 14
	nox_xxx_drawGetStringSize_43F840(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), &v9, nil, 0)
	if *(*uint32)(unsafe.Add(v2, 68)) != 0x80000000 {
		if (*(*uint32)(unsafe.Add(a1, 4)) & 0x2000) == 0x2000 {
			nox_draw_enableTextSmoothing_43F670(1)
		}
		nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(v2, 68))))
		nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), v7, v6, int32(*(*uint32)(unsafe.Add(a1, 8))), 0)
		nox_draw_enableTextSmoothing_43F670(0)
	}
	return 1
}
func nox_xxx_wndDrawCheckBox_4A9050(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1  = (*uint32)(win.C())
		a2  = int32(uintptr(draw.C()))
		v2  int32
		v3  *uint32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v11 int32
		v12 int32
		v13 int32
	)
	v2 = a2
	v3 = a1
	v11 = int32(*(*uint32)(unsafe.Add(a2, 32)))
	a2 = int32(*(*uint32)(unsafe.Add(a2, 24)))
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(a1)), &v12, &v13)
	v4 = int32(uint32(v13) + *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3))/2)
	if *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1))&8 != 0 {
		if int32(*(*uint8)(v2))&2 != 0 {
			v11 = int32(*(*uint32)(unsafe.Add(v2, 40)))
		}
	} else {
		a2 = int32(*(*uint32)(unsafe.Add(v2, 48)))
	}
	v5 = v4 - 5
	v6 = v12 + 4
	if a2 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(a2), int32(uint32(v6)+*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*24))), int32(uint32(v5)+*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*25))))
	}
	if int32(*(*uint8)(v2))&4 != 0 {
		v7 = int32(*(*uint32)(unsafe.Add(v2, 56)))
		if v7 == 0 {
			goto LABEL_12
		}
	} else {
		v7 = v11
		if v11 == 0 {
			goto LABEL_12
		}
	}
	nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(v7), int32(uint32(v6)+*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*24))), int32(uint32(v5)+*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*25))))
LABEL_12:
	v8 = 5 - nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(v2, 200)))/2 + v5
	v9 = v6 + 16
	nox_xxx_drawGetStringSize_43F840(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), (*int32)(unsafe.Pointer(&a1)), nil, 0)
	if *(*uint32)(unsafe.Add(v2, 68)) != 0x80000000 {
		if (*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) & 0x2000) == 0x2000 {
			nox_draw_enableTextSmoothing_43F670(1)
		}
		nox_xxx_drawSetTextColor_434390(int32(*(*uint32)(unsafe.Add(v2, 68))))
		nox_xxx_drawStringWrap_43FAF0(*(*unsafe.Pointer)(unsafe.Add(v2, 200)), (*wchar2_t)(unsafe.Add(v2, 72)), v9, v8, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2))), 0)
		nox_draw_enableTextSmoothing_43F670(0)
	}
	return 1
}
func nox_gui_newButtonOrCheckbox_4A91A0(parent *gui.Window, a2 nox_window_flags, a3, a4, a5, a6 int, draw *gui.WindowData) *gui.Window {
	if draw.Style&1 != 0 {
		var btn *gui.Window = nox_window_new(parent, a2, a3, a4, a5, a6, nox_xxx_wndButtonProcPre_4A9250)
		if btn == nil {
			return nil
		}
		nox_xxx_wndButtonInit_4A8340(int32(uintptr(unsafe.Pointer(btn))))
		if draw.Window == nil {
			draw.Window = btn
		}
		nox_gui_windowCopyDrawData_46AF80(btn, unsafe.Pointer(draw))
		return btn
	}
	if draw.Style&4 != 0 {
		var btn *gui.Window = nox_window_new(parent, a2, a3, a4, a5, a6, nox_xxx_wndCheckboxProcMB_4A92C0)
		if btn == nil {
			return nil
		}
		nox_xxx_wndCheckBoxInit_4A8E60(int32(uintptr(unsafe.Pointer(btn))))
		if draw.Window == nil {
			draw.Window = btn
		}
		nox_gui_windowCopyDrawData_46AF80(btn, unsafe.Pointer(draw))
		return btn
	}
	return nil
}
func nox_xxx_wndButtonProcPre_4A9250(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	var (
		a1 int32     = int32(uintptr(win.C()))
		a3 *wchar2_t = (*wchar2_t)(unsafe.Pointer(p3))
		v4 int32
		v5 int32
	)
	if a2 == 23 {
		if a3 == nil {
			v4 = int32(*(*uint32)(unsafe.Add(a1, 36)))
			*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(v4 & 0xFD))
			*(*uint32)(unsafe.Add(a1, 36)) = uint32(v4)
		}
		v5 = nox_xxx_wndGetID_46B0A0((*gui.Window)(a1))
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16387, uintptr(unsafe.Pointer(a3)), uintptr(v5))
		return 1
	} else {
		if a2 == 16385 {
			nox_wcsncpy((*wchar2_t)(unsafe.Add(a1, 108)), a3, 0x3F)
			*(*uint16)(unsafe.Add(a1, 234)) = 0
		}
		return 0
	}
}
func nox_xxx_wndCheckboxProcMB_4A92C0(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	var (
		a1 int32     = int32(uintptr(win.C()))
		a3 *wchar2_t = (*wchar2_t)(unsafe.Pointer(p3))
		v4 int32
		v5 int32
	)
	if a2 == 23 {
		if a3 == nil {
			v4 = int32(*(*uint32)(unsafe.Add(a1, 36)))
			*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(v4 & 0xFD))
			*(*uint32)(unsafe.Add(a1, 36)) = uint32(v4)
		}
		v5 = nox_xxx_wndGetID_46B0A0((*gui.Window)(a1))
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16387, uintptr(unsafe.Pointer(a3)), uintptr(v5))
		return 1
	} else {
		if a2 == 16385 {
			nox_wcsncpy((*wchar2_t)(unsafe.Add(a1, 108)), a3, 0x3F)
			*(*uint16)(unsafe.Add(a1, 234)) = 0
		}
		return 0
	}
}
func nox_xxx_wndRadioButtonProcPre_4A93C0(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	var (
		a1 int32     = int32(uintptr(win.C()))
		a3 *wchar2_t = (*wchar2_t)(unsafe.Pointer(p3))
		v3 int32
		i  *uint32
		v5 int32
		v7 int32
		v8 int32
	)
	if a2 != 23 {
		if a2 == 16385 {
			nox_wcsncpy((*wchar2_t)(unsafe.Add(a1, 108)), a3, 0x3F)
			*(*uint16)(unsafe.Add(a1, 234)) = 0
		} else if a2 == 16392 {
			v3 = int32(*(*uint32)(unsafe.Add(a1, 396)))
			if (int32(*(*uint8)(unsafe.Add(a1, 36))) & 4) == 0 {
				if uintptr(unsafe.Pointer(a3)) == uintptr(1) {
					nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16391, uintptr(a1), 0)
				}
				if v3 != 0 {
					for i = *(**uint32)(unsafe.Add(v3, 400)); i != nil; i = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*97))) {
						if i != (*uint32)(a1) && *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*10)) == *(*uint32)(unsafe.Add(a1, 40)) {
							*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*9)) &= 0xFFFFFFFB
						}
					}
				}
				v5 = int32(*(*uint32)(unsafe.Add(a1, 36)))
				*(*uint8)(unsafe.Pointer(&v5)) = uint8(int8(v5 | 4))
				*(*uint32)(unsafe.Add(a1, 36)) = uint32(v5)
				return 0
			}
		}
		return 0
	}
	if a3 == nil {
		v7 = int32(*(*uint32)(unsafe.Add(a1, 36)))
		*(*uint8)(unsafe.Pointer(&v7)) = uint8(int8(v7 & 0xFD))
		*(*uint32)(unsafe.Add(a1, 36)) = uint32(v7)
	}
	v8 = nox_xxx_wndGetID_46B0A0((*gui.Window)(a1))
	nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16387, uintptr(unsafe.Pointer(a3)), uintptr(v8))
	return 1
}
func nox_xxx_compassGenStrings_4A9C80() int32 {
	var (
		v0 int32
		v1 *uint8
		v2 int32
		v3 *uint8
		v5 [64]byte
	)
	*memmap.PtrUint32(0x5D4594, 1309664) = 0
	v0 = 0
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1309644))
	for {
		nox_sprintf(&v5[0], internCStr("Compass%d"), func() int32 {
			p := &v0
			*p++
			return *p
		}())
		*(*uint32)(unsafe.Pointer(v1)) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(&v5[0]))))
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 4))
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1309660))) {
			break
		}
	}
	v2 = 0
	v3 = (*uint8)(memmap.PtrOff(0x5D4594, 1309516))
	for {
		nox_sprintf(&v5[0], internCStr("CompassMainArrow%d"), func() int32 {
			p := &v2
			*p++
			return *p
		}())
		*(*uint32)(unsafe.Pointer(v3)) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(&v5[0]))))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
		if int32(uintptr(unsafe.Pointer(v3))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1309644))) {
			break
		}
	}
	return 1
}
func Nox_game_showOptions_4AA6B0() int {
	var (
		v1  *uint32
		v2  *byte
		v3  int32
		v4  int32
		v5  uint32
		v6  *uint32
		v7  *byte
		v8  int32
		v9  int32
		v10 uint32
		v11 *uint32
		v12 *byte
		v13 int32
		v14 int32
		v15 uint32
		v16 *byte
		v17 *byte
		v18 *byte
		v19 *byte
		v20 *byte
		v21 *byte
	)
	nox_game_addStateCode_43BDD0(300)
	dword_5d4594_1309720 = unsafe.Pointer(nox_new_window_from_file(internCStr("Options.wnd"), sub_4AABE0))
	if dword_5d4594_1309720 == nil {
		return 0
	}
	if nox_client_advVideoOpts_New_4CB590((*gui.Window)(dword_5d4594_1309720)) == 0 {
		return 0
	}
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1309720, guiSelProc2)
	nox_draw_setTabWidth_43FE20(15)
	nox_wnd_xxx_1309740 = nox_gui_makeAnimation_43C5B0((*gui.Window)(dword_5d4594_1309720), 0, 0, 0, -480, 0, 20, 0, -40)
	if nox_wnd_xxx_1309740 == nil {
		return 0
	}
	nox_wnd_xxx_1309740.StateID = 300
	nox_wnd_xxx_1309740.Func12Ptr.Set(sub_4AA9C0)
	nox_wnd_xxx_1309740.FncDoneOutPtr.Set(sub_4AAA10)
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(dword_5d4594_1309720), 351)))
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*100)), 8)) = 24
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*100)), 12)) = 20
	v19 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v16 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v2 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSlider"))))
	sub_4B5700(int32(uintptr(unsafe.Pointer(v1))), 0, 0, unsafe.Pointer(v2), unsafe.Pointer(v16), unsafe.Pointer(v19))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v1)), 16395, 0, 0x4000)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v1)), 16394, uintptr(*(*uint32)(unsafe.Add(dword_587000_127004, 4))>>16), 0)
	dword_5d4594_1309728 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(dword_5d4594_1309720), 361))))
	v3 = sub_453070()
	v4 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1309728, 36)))
	if v3 == 1 {
		v5 = uint32(v4 | 4)
	} else {
		v5 = uint32(v4) & 0xFFFFFFFB
	}
	*(*uint32)(unsafe.Add(dword_5d4594_1309728, 36)) = v5
	v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(dword_5d4594_1309720), 352)))
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v6), 4*100)), 8)) = 24
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v6), 4*100)), 12)) = 20
	v20 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v17 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v7 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSlider"))))
	sub_4B5700(int32(uintptr(unsafe.Pointer(v6))), 0, 0, unsafe.Pointer(v7), unsafe.Pointer(v17), unsafe.Pointer(v20))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v6)), 16395, 0, 0x4000)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v6)), 16394, uintptr(*(*uint32)(unsafe.Add(dword_587000_122852, 4))>>16), 0)
	dword_5d4594_1309732 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(dword_5d4594_1309720), 362))))
	v8 = sub_44D990()
	v9 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1309732, 36)))
	if v8 == 1 {
		v10 = uint32(v9 | 4)
	} else {
		v10 = uint32(v9) & 0xFFFFFFFB
	}
	*(*uint32)(unsafe.Add(dword_5d4594_1309732, 36)) = v10
	v11 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(dword_5d4594_1309720), 353)))
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v11), 4*100)), 8)) = 24
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v11), 4*100)), 12)) = 20
	v21 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v18 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v12 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSlider"))))
	sub_4B5700(int32(uintptr(unsafe.Pointer(v11))), 0, 0, unsafe.Pointer(v12), unsafe.Pointer(v18), unsafe.Pointer(v21))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v11)), 16395, 0, 0x4000)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v11)), 16394, uintptr(*(*uint32)(unsafe.Add(dword_587000_93164, 4))>>16), 0)
	dword_5d4594_1309736 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(dword_5d4594_1309720), 363))))
	v13 = sub_43DC30()
	v14 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1309736, 36)))
	if v13 == 1 {
		v15 = uint32(v14 | 4)
	} else {
		v15 = uint32(v14) & 0xFFFFFFFB
	}
	*(*uint32)(unsafe.Add(dword_5d4594_1309736, 36)) = v15
	nox_xxx_wndRetNULL_46A8A0()
	sub_4A19F0(internCStr("OptsBack.wnd:Back"))
	sub_4A1A40(0)
	sub_4AAA70()
	return 1
}
func sub_4AAA70() *uint32 {
	var v0 *uint32
	_ = v0
	var v1 *uint32
	var v4 int32
	var result *uint32
	var v6 int32
	_ = v6
	var v7 int32
	nox_video_setMenuOptions((*gui.Window)(dword_5d4594_1309720))
	if nox_video_getFullScreen() == 0 {
		v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(dword_5d4594_1309720), 331)))
	} else {
		v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(dword_5d4594_1309720), 332)))
	}
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v1)), 16392, 1, 0)
	v4 = nox_video_getCutSize_4766D0()
	*memmap.PtrUint32(0x587000, 172884) = uint32(v4)
	if v4 > 69 {
		if v4 <= 79 {
			result = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(dword_5d4594_1309720), 312)))
			goto LABEL_22
		}
		if v4 <= 89 {
			result = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(dword_5d4594_1309720), 313)))
			goto LABEL_22
		}
		v7 = 314
	} else {
		v7 = 311
	}
	result = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(dword_5d4594_1309720), v7)))
LABEL_22:
	if result != nil {
		result = (*uint32)(unsafe.Pointer(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(result)), 16392, 1, 0)))
	}
	return result
}
func sub_4AABE0(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v4     int32
		v5     int32
		result int32 = 0
		v7     int32
		v8     int32
		v12    unsafe.Pointer
		v15    int32
		v17    int32
	)
	switch a2 {
	case 16389:
		nox_xxx_clientPlaySoundSpecial_452D80(920, 100)
		result = 1
	case 16391:
		v4 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
		if v4 >= 380 {
			return uintptr(nox_gui_menu_proc_ext(v4))
		}
		if v4 > 341 {
			if v4 > 363 {
				if v4 == 2099 {
					sub_4AAA70()
				}
			} else if v4 == 363 {
				if sub_43DC30() == 1 {
					sub_43DC00()
				} else {
					sub_43DC10()
					sub_486320(dword_587000_93164, *(*uint32)(unsafe.Add(dword_587000_93164, 4))>>16)
				}
			} else {
				v5 = v4 - 361
				if v5 != 0 {
					if v5 == 1 {
						if sub_44D990() == 1 {
							sub_44D960()
						} else {
							sub_44D970()
						}
					}
				} else if sub_453070() == 1 {
					sub_453050()
				} else {
					nox_xxx____setargv_9_453060()
				}
			}
		} else if v4 == 341 {
			sub_4AA9C0()
			nox_wnd_xxx_1309740.FncDoneOutPtr.Set(sub_4AB0C0)
			nox_wnd_xxx_1309740.Func13Ptr.Set(sub_4CB880)
		} else {
			switch v4 {
			case 311:
				nox_video_setCutSize_4766A0(65)
			case 312:
				nox_video_setCutSize_4766A0(75)
			case 313:
				nox_video_setCutSize_4766A0(85)
			case 314:
				nox_video_setCutSize_4766A0(100)
			case 332:
				nox_xxx_normalWndBits_587000_172880 = 16
				fallthrough
			case 333:
				nox_video_setFullScreen(1)
			case 331:
				nox_xxx_normalWndBits_587000_172880 = 8
				fallthrough
			case 334:
				nox_video_setFullScreen(0)
			default:
			}
		}
		nox_xxx_clientPlaySoundSpecial_452D80(921, 100)
		result = 1
	case 16393:
		v7 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
		v8 = int32(uintptr(unsafe.Pointer(nox_client_getWin1064916_46C720())))
		switch v7 {
		case 351:
			sub_486320(dword_587000_127004, int32(a4))
			if v8 != 0 && *(*uint32)(unsafe.Add(v8, 396)) == uint32(a3) {
				return 0
			}
			if a4 != 0 {
				if sub_453070() != 0 {
					nox_xxx_clientPlaySoundSpecial_452D80(768, 100)
					return 0
				}
				v15 = int32(dword_5d4594_1309728)
				v16 := ccall.AsFunc[func(int32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309728, 372)))
				if v16 == nil {
					nox_xxx_clientPlaySoundSpecial_452D80(768, 100)
					return 0
				}
				v16(v15, 21, 28, 2)
				nox_xxx_clientPlaySoundSpecial_452D80(768, 100)
				return 0
			}
			if sub_453070() != 1 {
				return 0
			}
			v14 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309728, 372)))
			if v14 == nil {
				return 0
			}
			v14(dword_5d4594_1309728, 21, 28, 2)
			result = 0
		case 352:
			sub_486320(dword_587000_122852, int32(a4))
			if a4 != 0 {
				if sub_44D990() != 0 {
					sub_4AA650()
					return 0
				}
				v12 = dword_5d4594_1309732
				v13 := ccall.AsFunc[func(unsafe.Pointer, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309732, 372)))
				if v13 == nil {
					sub_4AA650()
					return 0
				}
				v13(v12, 21, 28, 2)
				sub_4AA650()
				return 0
			}
			if sub_44D990() != 1 {
				return 0
			}
			v11 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309732, 372)))
			if v11 == nil {
				return 0
			}
			v11(dword_5d4594_1309732, 21, 28, 2)
			result = 0
		case 353:
			sub_486320(dword_587000_93164, int32(a4))
			if a4 != 0 {
				if sub_43DC30() != 0 {
					return 0
				}
				v10 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309736, 372)))
				if v10 == nil {
					return 0
				}
				v10(dword_5d4594_1309736, 21, 28, 2)
				result = 0
			} else {
				if sub_43DC30() != 1 {
					return 0
				}
				v9 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309736, 372)))
				if v9 == nil {
					return 0
				}
				v9(dword_5d4594_1309736, 21, 28, 2)
				result = 0
			}
		case 316:
			nox_video_setGammaSlider(int32(a4))
		case 318:
			nox_input_setSensitivity(math32.Pow(10.0, float32(float64(a4)/50.0-1.0)))
		default:
			return 0
		}
	case 16396:
		v17 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) - 351
		if v17 != 0 {
			if v17 != 1 {
				return 0
			}
			sub_486320(dword_587000_122852, int32(a4))
			if a4 != 0 {
				if sub_44D990() == 0 {
					v12 = dword_5d4594_1309732
					v13 := ccall.AsFunc[func(unsafe.Pointer, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309732, 372)))
					if v13 != nil {
						v13(v12, 21, 28, 2)
					}
				}
				sub_4AA650()
				return 0
			} else {
				if sub_44D990() != 1 {
					return 0
				}
				v18 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309732, 372)))
				if v18 == nil {
					return 0
				}
				v18(dword_5d4594_1309732, 21, 28, 2)
				result = 0
			}
		} else {
			sub_486320(dword_587000_127004, int32(a4))
			if a4 != 0 {
				if sub_453070() == 0 {
					v15 = int32(dword_5d4594_1309728)
					v16 := ccall.AsFunc[func(int32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309728, 372)))
					if v16 != nil {
						v16(v15, 21, 28, 2)
					}
				}
				nox_xxx_clientPlaySoundSpecial_452D80(768, 100)
				return 0
			}
			if sub_453070() != 1 {
				return 0
			}
			v19 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309728, 372)))
			if v19 == nil {
				return 0
			}
			v19(dword_5d4594_1309728, 21, 28, 2)
			result = 0
		}
	default:
		return 0
	}
	return uintptr(result)
}
func sub_4AB0C0() int {
	v0 := nox_wnd_xxx_1309740.Func13Ptr.Get()
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_1309740)
	nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(dword_5d4594_1309720))
	v0()
	return 1
}
func sub_4AB260() int32 {
	*memmap.PtrPtr(0x5D4594, 1309752) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("DisconnectIcon")))
	dword_5d4594_1309756 = uint32(uintptr(unsafe.Pointer(nox_window_new(nil, 136, int(nox_win_width)-50, int(nox_win_height)/2+3, 50, 50, nil))))
	nox_xxx_wndSetIcon_46AE60(dword_5d4594_1309756, *memmap.PtrInt32(0x5D4594, 1309752))
	nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(dword_5d4594_1309756)), nil, sub_4AB420, nil)
	dword_5d4594_1309748 = uint32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("discon.wnd"), sub_4AB390))))
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1309748, sub_4AB340)
	sub_46B120((*gui.Window)(unsafe.Pointer(dword_5d4594_1309748)), nil)
	nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309748)), int32(uint32(nox_win_width/2)-*(*uint32)(unsafe.Add(dword_5d4594_1309748, 24))/2), int32(uint32(nox_win_height/2)-*(*uint32)(unsafe.Add(dword_5d4594_1309748, 28))/2))
	return 1
}
func sub_4AB340(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	if a2 != 21 {
		return 0
	}
	if a3 == 1 {
		return 1
	}
	if a3 == 57 {
		var mpos nox_point = nox_client_getMousePos_4309F0()
		nox_window_call_field_93(win, 5, mpos.x|mpos.y<<16, 0)
	}
	return 0
}
func sub_4AB390(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v3     int32
		result int32
	)
	if a2 == 23 {
		return 1
	}
	if a2 != 16391 {
		return 0
	}
	v3 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) - 576
	if v3 == 0 {
		sub_43CF40()
		return 0
	}
	if v3 != 1 {
		return 0
	}
	sub_446380()
	if dword_5d4594_2650652 != 0 && sub_41E2F0() == 9 {
		sub_41F4B0()
		sub_41EC30()
		sub_446490(0)
		nox_xxx____setargv_4_44B000()
		sub_4AB4D0(0)
		result = 0
	} else {
		sub_43B750()
		sub_4AB4D0(0)
		result = 0
	}
	return uintptr(result)
}
func sub_4AB420(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1 = (*int32)(win.C())
		v1 *int32
		v2 int32
		v4 int32
	)
	v1 = a1
	nox_client_wndGetPosition_46AA60(win, (*uint32)(unsafe.Pointer(&a1)), &v4)
	v2 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*25))
	a1b := (*int32)(unsafe.Add(unsafe.Pointer(a1), *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*24))))
	nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*15))), int32(uintptr(unsafe.Pointer(a1b))), v2+v4)
	return 1
}
func sub_4AB470() int32 {
	var result int32
	nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309748)))
	nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309756)))
	result = 0
	dword_5d4594_1309756 = 0
	dword_5d4594_1309748 = 0
	return result
}
func sub_4AB4A0(a1 int32) int32 {
	var result int32
	if a1 != 0 {
		result = nox_window_set_hidden((*gui.Window)(dword_5d4594_1309756), 0)
	} else {
		result = nox_window_set_hidden((*gui.Window)(dword_5d4594_1309756), 1)
	}
	return result
}
func sub_4AB4D0(a1 int32) int32 {
	var result int32
	if a1 != 0 {
		nox_video_stopAllFades_44E040()
		nox_window_set_hidden((*gui.Window)(dword_5d4594_1309748), 0)
		nox_xxx_wndShowModalMB_46A8C0((*gui.Window)(dword_5d4594_1309748))
		sub_46C690((*gui.Window)(dword_5d4594_1309748))
		nox_xxx_windowFocus_46B500((*gui.Window)(dword_5d4594_1309748))
		result = nox_xxx_wnd_46ABB0((*gui.Window)(dword_5d4594_1309748), 1)
	} else {
		nox_window_set_hidden((*gui.Window)(dword_5d4594_1309748), 1)
		nox_xxx_wnd_46C6E0((*gui.Window)(dword_5d4594_1309748))
		nox_xxx_windowFocus_46B500(nil)
		result = nox_xxx_wnd_46ABB0((*gui.Window)(dword_5d4594_1309748), 0)
	}
	return result
}
func sub_4ABDA0(a1 int32, a2 int16, a3 int16, a4 *uint32) unsafe.Pointer {
	var (
		v4  int32
		v7  uint32
		v8  int32
		v9  float32
		v10 int8
		v11 float32
		v12 int32
		v13 [2]int32
		v14 float32
		v15 int32
		v16 int32
		v17 float32
		v18 int32
		v19 [256]byte
	)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v15)), 4)
	*a4 += 4
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v16)), 4)
	*a4 += 4
	if int32(a3) < 40 || int32(a2) < 4 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13[0])), 8)
		*a4 += 8
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 4)
		*a4 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v17)), 4)
		v9 = v11
		*a4 += 4
		v13[0] = int32(v9)
		v13[1] = int32(v17)
	}
	if int32(a3) >= 10 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 1)
		*a4++
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v19[0], uint32(uint8(int8(v12))))
		*a4 += uint32(uint8(int8(v12)))
	}
	if int32(a3) >= 20 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 1)
		*a4++
	}
	if int32(a3) >= 30 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 1)
		*a4++
	}
	if int32(a3) >= 40 {
		nox_xxx_cryptSeekCur_40E0A0(4)
		*a4 += 4
		if int32(a2) >= 2 {
			if int32(a2) < 5 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 4)
				*a4 += 4
				v11 = v14
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 2)
				*a4 += 2
			}
			v4 = int32(uint16(int16(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(&v11), unsafe.Sizeof(uint16(0))*0))) * 4)))
			nox_xxx_cryptSeekCur_40E0A0(v4)
			*a4 += uint32(v4)
		}
		if int32(a2) >= 3 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 4)
			*a4 += 4
		}
	}
	result := unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(a1, v13[0], v13[1]))
	v6 := result
	if result != nil {
		v7 = *(*uint32)(unsafe.Add(result, 120)) & 0xEEBF7E9D
		*(*uint32)(unsafe.Add(result, 120)) = v7
		*(*uint32)(unsafe.Add(result, 120)) = uint32(v16) | v7
		v8 = int32(*(*uint32)(unsafe.Add(result, 280)))
		*(*uint8)(unsafe.Pointer(&v8)) = uint8(int8(v8 & 0xA1))
		*(*uint32)(unsafe.Add(v6, 280)) = uint32(v8)
		*(*uint32)(unsafe.Add(v6, 280)) = uint32(v18 | v8)
		*(*uint32)(unsafe.Add(v6, 128)) = uint32(v15)
		*(*uint8)(unsafe.Add(v6, 28)) = uint8(v10)
		if !noxflags.HasGame(1) && int32(*(*uint8)(unsafe.Add(v6, 28))) != 0 && ((*(*uint32)(unsafe.Add(v6, 112))&0x10000000) == 0 || !noxflags.HasGame(128)) {
			nox_xxx_createAtImpl_4191D0(*(*uint8)(unsafe.Add(v6, 28)), unsafe.Add(v6, 24), 0, int32(*(*uint32)(unsafe.Add(v6, 128))), 0)
		}
		result = v6
	}
	return result
}
func nox_xxx_spriteLoadFromMap_4AC020(thingInd int32, a2 int16, a3 *uint32) unsafe.Pointer {
	var (
		v3  *uint32
		v4  int16
		v5  int16
		v6  bool
		v7  int32
		v10 bool
		v11 int32
		v12 int32
		v13 int8
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 uint8
		v19 int32
		v20 float32
		v21 int32
		v22 int32
		v23 int32
		v24 int32
		v25 int32
		v26 int32
		v27 int32
		v28 int32
		v29 int32
		v30 float32
		v31 float32
	)
	v3 = a3
	v4 = a2
	v5 = 1
	v23 = 1
	if int32(a2) < 40 {
		return sub_4ABDA0(thingInd, v5, v4, v3)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v23)), 2)
	v5 = int16(v23)
	v6 = int32(int16(v23)) < 61
	*v3 += 2
	if v6 {
		return sub_4ABDA0(thingInd, v5, v4, v3)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v25)), 4)
	*v3 += 4
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v29)), 4)
	*v3 += 4
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v30)), 4)
	*v3 += 4
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v31)), 4)
	v20 = v31
	*v3 += 4
	v22 = int32(v20)
	v7 = int32(v30)
	v9 := unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(thingInd, v7, v22))
	if v9 == nil {
		return nil
	}
	*(*uint32)(unsafe.Add(v9, 128)) = uint32(v25)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
	v10 = int32(uint8(int8(a2))) == 0
	*v3++
	if !v10 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v26)), 4)
		v11 = v26
		*v3 += 4
		*(*uint32)(unsafe.Add(v9, 120)) = uint32(v11) | (*(*uint32)(unsafe.Add(v9, 120)) & 0xEEBF7E9D)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a3)), 1)
		v12 = int32(uint8(uintptr(unsafe.Pointer(a3))))
		v21 = int32(uint8(uintptr(unsafe.Pointer(a3))))
		*v3++
		nox_xxx_cryptSeekCur_40E0A0(v21)
		*v3 += uint32(v12)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&thingInd)), 1)
		v13 = int8(thingInd)
		*v3++
		*(*uint8)(unsafe.Add(v9, 28)) = uint8(v13)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a3)), 1)
		*v3++
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v27)), 2)
		v14 = int32(uint16(int16(v27))) * 4
		v19 = int32(uint16(int16(v27))) * 4
		*v3 += 2
		nox_xxx_cryptSeekCur_40E0A0(v19)
		*v3 += uint32(v14)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v28)), 4)
		v15 = v28
		*v3 += 4
		v16 = int32(*(*uint32)(unsafe.Add(v9, 280)))
		*(*uint8)(unsafe.Pointer(&v16)) = uint8(int8(v16 & 0xA1))
		*(*uint32)(unsafe.Add(v9, 280)) = uint32(v15 | v16)
		if int32(int16(v23)) >= 63 {
			nox_xxx_cryptSeekCur_40E0A0(2)
			*v3 += 2
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v24)), 4)
			*v3 += 4
			nox_xxx_cryptSeekCur_40E0A0(v24)
			*v3 += uint32(v24)
			nox_xxx_cryptSeekCur_40E0A0(4)
			*v3 += 4
		}
		if int32(int16(v23)) >= 64 {
			nox_xxx_cryptSeekCur_40E0A0(4)
			*v3 += 4
		}
	}
	if !noxflags.HasGame(1) {
		v17 = int32(*memmap.PtrUint32(0x5D4594, 1309788))
		if *memmap.PtrUint32(0x5D4594, 1309788) == 0 {
			v17 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("FlagMarker"))
			*memmap.PtrUint32(0x5D4594, 1309788) = uint32(v17)
		}
		v18 = *(*uint8)(unsafe.Add(v9, 28))
		if int32(v18) != 0 {
			if *(*uint32)(unsafe.Add(v9, 108)) != uint32(v17) {
				nox_xxx_createAtImpl_4191D0(v18, unsafe.Add(v9, 24), 0, int32(*(*uint32)(unsafe.Add(v9, 128))), 0)
			}
		}
	}
	return v9
}
func Nox_client_mapSpecialRWObjectData_4AC610(a1 unsafe.Pointer) int32 {
	var (
		v1 uint16
		v2 uint16
		v3 int32
		v4 int32
		v5 int32
		v6 int32
	)
	v6 = 1
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6)), 2)
	if int32(int16(v6)) > 1 {
		return 0
	}
	if nox_crypt_IsReadOnly() == 0 {
		return 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 2)
	if int32(uint16(int16(v4))) != 0 {
		for {
			nox_xxx_fileCryptReadCrcMB_426C20((*uint8)(unsafe.Pointer(&v5)), 4)
			v1 = uint16(int16(nox_xxx_objectTOCgetTT_42C2B0(uint16(int16(v4)))))
			v2 = v1
			if int32(v1) == 0 {
				break
			}
			if sub_44D090(int32(v1)) != 0 {
				v3 = nox_xxx_clientLoadSomeObject_4AC6E0(v2)
				v5 -= v3
			}
			if v5 > 0 {
				nox_xxx_cryptSeekCur_40E0A0(v5)
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 2)
			if int32(uint16(int16(v4))) == 0 {
				return 1
			}
		}
		return 0
	}
	return 1
}
func nox_xxx_clientLoadSomeObject_4AC6E0(a1 uint16) int32 {
	if *memmap.PtrUint32(0x5D4594, 1309792) == 0 {
		*memmap.PtrUint32(0x5D4594, 1309792) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ColorLight")))
		*memmap.PtrUint32(0x5D4594, 1309796) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ColorLightMovable")))
		*memmap.PtrUint32(0x5D4594, 1309800) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("TeamBase")))
		*memmap.PtrUint32(0x5D4594, 1309804) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("PressurePlate")))
	}
	if uint32(a1) == *memmap.PtrUint32(0x5D4594, 1309792) || uint32(a1) == *memmap.PtrUint32(0x5D4594, 1309796) {
		return nox_xxx_colorLightClientLoad_4AC980(int32(a1))
	}
	if uint32(a1) == *memmap.PtrUint32(0x5D4594, 1309800) {
		return nox_xxx_cliLoadTeamBase_4ACE00(int32(a1))
	}
	if uint32(a1) == *memmap.PtrUint32(0x5D4594, 1309804) {
		return sub_4ACEF0(int32(a1))
	}
	if sub_44D060(int32(a1)) != 0 {
		return sub_4AD040(int32(a1))
	}
	if sub_44D040(int32(a1)) != 0 {
		return sub_4AC7B0(int32(a1))
	}
	return 0
}
func sub_4AC7B0(a1 int32) int32 {
	var (
		result int32
		v4     int32
		v5     int8
		v6     float32
		v7     int32
		v9     float64
		v10    float64
		v11    int32
		v12    int32
		v13    float32
		v14    int32
	)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 2)
	v11 = 2
	v1 := nox_xxx_spriteLoadFromMap_4AC020(a1, int16(v12), (*uint32)(unsafe.Pointer(&v11)))
	v2 := v1
	if v1 != nil {
		v4 = int32(*(*uint32)(unsafe.Add(v1, 112)))
		if (v4 & 0x80) == 0 {
			if v4&0x200 != 0 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 4)
				v9 = float64(a1)
				v11 += 8
				v13 = float32(v9)
				*(*float32)(unsafe.Add(v2, 56)) = float32(v9)
				v10 = float64(v14)
				*(*float32)(unsafe.Add(v2, 60)) = float32(v10)
				if float64(v13) > 60.0 {
					*(*uint32)(unsafe.Add(v2, 56)) = 1114636288
				}
				if v10 > 60.0 {
					*(*uint32)(unsafe.Add(v2, 60)) = 1114636288
				}
				nox_shape_box_calc((*server.Shape)(unsafe.Add(v2, 44)))
			}
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13)), 4)
			v11 += 4
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 4)
			v5 = int8(v14)
			v11 += 4
			*(*uint8)(unsafe.Add(v2, 433)) = uint8(int8(v14))
			*(*uint8)(unsafe.Add(v2, 432)) = 0
			if int32(v5) != 0 {
				*(*uint8)(unsafe.Add(v2, 432)) = 1
			}
			v6 = v13
			a1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(&v13), 4*0)))
			if int32(int16(v12)) >= 41 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
				v6 = a1
				v11 += 4
			}
			*(*uint8)(unsafe.Add(v2, 299)) = *(*uint8)(unsafe.Pointer(&v13))
			v7 = int32(*(*uint32)(unsafe.Add(v2, 12)) + uint32(*memmap.PtrInt32(0x587000, uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v6), 4*0))))*8+196184)/2))
			sub_410390(v2, v7/23, int32((*(*uint32)(unsafe.Add(v2, 16))+uint32(*memmap.PtrInt32(0x587000, uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v6), 4*0))))*8+196188)/2))/23))
		}
		*(*uint32)(unsafe.Add(v2, 288)) = 0
		nox_xxx_spriteSetActiveMB_45A990_drawable(v2)
		result = v11
	} else {
		nox_xxx_spriteLoadError_4356E0()
		result = 0
	}
	return result
}
func nox_xxx_colorLightClientLoad_4AC980(a1 int32) int32 {
	var (
		v4 *uint16
		v5 *uint8
		v6 *uint8
		v7 int32
		v8 int32
	)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 2)
	v7 = 2
	v1 := nox_xxx_spriteLoadFromMap_4AC020(a1, int16(v8), (*uint32)(unsafe.Pointer(&v7)))
	v2 := v1
	if v1 == nil {
		nox_xxx_spriteLoadError_4356E0()
		return 0
	}
	if int32(int16(v8)) >= 2 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 136)), 4)
		v7 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 140)), 4)
		v7 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 144)), 4)
		v7 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 148)), 4)
		v7 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 152)), 0xC)
		v4 = (*uint16)(unsafe.Add(v2, 164))
		v7 += 12
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 164)), 2)
		v7 += 2
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 166)), 2)
		v7 += 2
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 168)), 4)
		v7 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 176)), 2)
		v7 += 2
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 178)), 0x30)
		v7 += 48
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 226)), 0x10)
		v7 += 16
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 242)), 0x10)
		v7 += 16
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 258)), 2)
		v7 += 2
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 260)), 2)
		v7 += 2
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 262)), 2)
		v7 += 2
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 264)), 4)
		v7 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 270)), 2)
		v7 += 2
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 272)), 2)
		v7 += 2
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 274)), 1)
		v7++
		if int32(int16(v8)) > 40 {
			if int32(int16(v8)) >= 42 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 172)), 4)
				v7 += 4
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
				v7++
				*(*uint32)(unsafe.Add(v2, 172)) = uint32(uint8(int8(a1)))
			}
		}
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 136)), 4)
		v7 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 140)), 4)
		v7 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 144)), 4)
		v7 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 148)), 4)
		v7 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 152)), 0xC)
		v4 = (*uint16)(unsafe.Add(v2, 164))
		v7 += 12
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 164)), 2)
		v7 += 2
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 166)), 2)
		v7 += 2
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 168)), 4)
		v7 += 4
		*(*uint16)(unsafe.Add(v2, 176)) = 0
		*(*uint16)(unsafe.Add(v2, 258)) = 0
		*(*uint16)(unsafe.Add(v2, 260)) = 0
		*(*uint16)(unsafe.Add(v2, 262)) = 0
		*(*uint32)(unsafe.Add(v2, 264)) = 0
		*(*uint16)(unsafe.Add(v2, 270)) = 0
		*(*uint8)(unsafe.Add(v2, 274)) = 128
		if nox_crypt_IsReadOnly() != 1 {
			goto LABEL_24
		}
		if float64(*(*float32)(unsafe.Add(v2, 140))) <= 63.0 && float64(*(*int32)(unsafe.Add(v2, 148)))**mem_getDoublePtr(0x581450, 9752) <= *mem_getDoublePtr(0x581450, 9744) {
			goto LABEL_13
		}
		sub_484CE0(unsafe.Add(v2, 136), 63.0)
	}
	if nox_crypt_IsReadOnly() == 1 {
		goto LABEL_13
	} else {
		goto LABEL_24
	}
LABEL_13:
	*(*uint8)(unsafe.Add(v2, 432)) = 0
	*(*uint8)(unsafe.Add(v2, 433)) = 0
	*(*uint8)(unsafe.Add(v2, 434)) = 0
	v5 = (*uint8)(unsafe.Add(v2, 242))
	v6 = (*uint8)(unsafe.Add(v2, 179))
	for {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), -1))) != 0 || int32(*v6) != 0 || int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 1))) != 0 {
			*(*uint8)(unsafe.Add(v2, 432))++
		}
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v5), -16))) != 0 {
			*(*uint8)(unsafe.Add(v2, 433))++
		}
		if int32(*v5) != 0 {
			*(*uint8)(unsafe.Add(v2, 434))++
		}
		v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 3))
		v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 1))
		if uintptr(unsafe.Pointer(v5))-uintptr(unsafe.Add(v2, 242)) >= 16 {
			break
		}
	}
	a1 = int32(*v4)
	*(*uint16)(unsafe.Add(v2, 268)) = uint16(int16(int64(float64(a1) * *mem_getDoublePtr(0x581450, 9752) * *mem_getDoublePtr(0x581450, 9736))))
LABEL_24:
	*(*uint32)(unsafe.Add(v2, 288)) = 0
	nox_xxx_spriteSetActiveMB_45A990_drawable(v2)
	return v7
}
func nox_xxx_cliLoadTeamBase_4ACE00(a1 int32) int32 {
	var (
		result int32
		i      int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     [256]byte
	)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 2)
	v6 = 2
	v1 := nox_xxx_spriteLoadFromMap_4AC020(a1, int16(v8), (*uint32)(unsafe.Pointer(&v6)))
	v2 := v1
	if v1 != nil {
		*(*uint32)(unsafe.Add(v1, 288)) = 0
		nox_xxx_spriteSetActiveMB_45A990_drawable(v1)
		for i = 0; i < 16; i += 4 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 1)
			v6++
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v9[0], uint32(uint8(int8(v7))))
			v6 += int32(uint8(int8(v7)))
			v9[uint8(int8(v7))] = 0
			v5 = nox_xxx_modifGetIdByName_413290(&v9[0])
			*(*uint32)(unsafe.Add(v2, 432+i)) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v5)))
			*(*uint16)(unsafe.Add(v2, 448)) = math.MaxUint16
			*(*uint16)(unsafe.Add(v2, 450)) = math.MaxUint16
		}
		result = v6
	} else {
		nox_xxx_spriteLoadError_4356E0()
		result = 0
	}
	return result
}
func sub_4ACEF0(a1 int32) int32 {
	var (
		result int32
		v4     *uint8
		v5     int32
		v6     int32
		v7     int32
		v8     *uint8
	)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 2)
	v5 = 2
	v1 := nox_xxx_spriteLoadFromMap_4AC020(a1, int16(v7), (*uint32)(unsafe.Pointer(&v5)))
	v2 := v1
	if v1 != nil {
		v4 = (*uint8)(unsafe.Add(v1, 432))
		*(*uint32)(unsafe.Add(v1, 288)) = 0
		nox_xxx_spriteSetActiveMB_45A990_drawable(v1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6)), 4)
		*(*float32)(unsafe.Add(v2, 56)) = float32(float64(v6))
		v5 += 4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6)), 4)
		*(*float32)(unsafe.Add(v2, 60)) = float32(float64(v6))
		v5 += 4
		nox_shape_box_calc((*server.Shape)(unsafe.Add(v2, 44)))
		*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 4)) = 10
		*v4 = 90
		*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 1)) = 90
		*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 2)) = 90
		*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 3)) = 10
		*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 5)) = 10
		v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 5))
		if int32(int16(v7)) >= 41 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v4, 1)
			v5++
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 1)), 1)
			v5++
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 2)), 1)
			v5++
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 3)), 1)
			v5++
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 4)), 1)
			v5++
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v8, 1)
			v5++
		}
		result = v5
	} else {
		nox_xxx_spriteLoadError_4356E0()
		result = 0
	}
	return result
}
func sub_4AD040(a1 int32) int32 {
	var (
		result int32
		v3     int32
		v4     int32
		v5     int32
	)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 2)
	v3 = 2
	v1 := nox_xxx_spriteLoadFromMap_4AC020(a1, int16(v4), (*uint32)(unsafe.Pointer(&v3)))
	if v1 != nil {
		if int32(int16(v4)) >= 61 {
			*(*uint8)(unsafe.Pointer(&a1)) = 0
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 4)
			v3 += 4
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
			v3++
			if int32(uint8(int8(a1))) == 1 {
				sub_459DD0((*client.Drawable)(v1), 1)
			}
		}
		*(*uint32)(unsafe.Add(v1, 288)) = 0
		nox_xxx_spriteSetActiveMB_45A990_drawable(v1)
		result = v3
	} else {
		nox_xxx_spriteLoadError_4356E0()
		result = 0
	}
	return result
}
func sub_4AD570(win *gui.Window, draw *gui.WindowData) int {
	var (
		v1   *uint32
		mpos nox_point = nox_client_getMousePos_4309F0()
	)
	if false {
		v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1309812, 10317)))
		if wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(unsafe.Pointer(v1))) == 0 && !nox_xxx_wndPointInWnd_46AAB0(v1, mpos.x, mpos.y) {
			nox_xxx_wndClearCaptureMain_46ADE0((*gui.Window)(unsafe.Pointer(v1)))
			nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v1)), 1)
		}
	}
	return 1
}
func nox_xxx_windowServerOptionsGeneralProc_4AD5D0(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v4  *uint32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 *uint32
		v12 int32
		v13 *uint32
	)
	if a2 == 16391 {
		v12 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
		switch v12 {
		case 10301:
			if nox_server_doPlayersAutoRespawn_40A5F0() != 0 {
				nox_xxx_ruleSetNoRespawn_40A5E0(0)
			} else {
				nox_xxx_ruleSetNoRespawn_40A5E0(1)
			}
			return 0
		case 10302:
			nox_server_sendMotd_108752 ^= 1
			return 0
		case 10304:
			if sub_4D0D70() != 0 {
				sub_4D0D90(0)
			} else {
				sub_4D0D90(1)
			}
			return 0
		case 10305:
			sub_409EF0(2)
			return 0
		case 10306:
			sub_409EF0(0x2000)
			if sub_409F40(0x2000) != 0 {
				return 0
			}
			sub_4D7EA0()
			return 0
		case 10316:
			v13 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1309812, 10317)))
			nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v13)), 0)
			nox_xxx_wndShowModalMB_46A8C0((*gui.Window)(unsafe.Pointer(v13)))
			nox_xxx_wndSetCaptureMain_46ADC0((*gui.Window)(unsafe.Pointer(v13)))
			return 0
		case 10319:
			sub_4BDFD0()
			return 0
		default:
			return 0
		}
	} else if a2 == 16393 {
		nox_xxx_rateUpdate_40A6D0(4 - int32(a4))
		return 0
	} else if a2 != 16400 || nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) != 10317 || (func() bool {
		v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1309812, 10316)))
		v5 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16404, 0, 0))
		v6 = v5
		return v5 < 0
	}()) || v5 >= int32(*(*int16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a3), 4*8)), 44))) {
		return 0
	} else {
		v7 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16406, a4, 0))
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v4)), 16385, uintptr(v7), math.MaxUint32)
		nox_server_connectionType_3596 = uint32(v6 + 1)
		v8 = sub_40A710(v6 + 1)
		nox_xxx_rateUpdate_40A6D0(v8)
		v9 = 4 - nox_xxx_rateGet_40A6C0()
		v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1309812, 10312)))
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16394, uintptr(v9), 0)
		nox_window_set_hidden((*gui.Window)(unsafe.Pointer(a3)), 1)
		nox_xxx_wndClearCaptureMain_46ADE0((*gui.Window)(unsafe.Pointer(a3)))
		return 0
	}
}
func sub_4AD820() int32 {
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1309812)
	dword_5d4594_1309812 = nil
	return sub_4BE610()
}
func sub_4AD9B0(a1 int32) int32 {
	if wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(dword_5d4594_1309820)) != 0 {
		return 0
	}
	sub_413A00(0)
	sub_44D8F0()
	if a1 != 0 {
		nox_window_set_hidden((*gui.Window)(dword_5d4594_1309820), 1)
		nox_window_set_hidden((*gui.Window)(dword_5d4594_1309824), 1)
	} else {
		nox_common_writecfgfile(internCStr("nox.cfg"))
		nox_window_set_hidden((*gui.Window)(dword_5d4594_1309820), 1)
		nox_window_set_hidden((*gui.Window)(dword_5d4594_1309824), 1)
		sub_445C40()
	}
	return 1
}
func sub_4ADA40() int32 {
	var (
		v0 int32
		v1 *uint32
		v3 int32
	)
	sub_413A00(1)
	nox_xxx_wndShowModalMB_46A8C0((*gui.Window)(dword_5d4594_1309820))
	nox_xxx_wndShowModalMB_46A8C0((*gui.Window)(dword_5d4594_1309824))
	nox_client_advVideoOptsLoad_4CB330()
	v0 = nox_video_getCutSize_4766D0()
	if v0 > 69 {
		if v0 <= 79 {
			v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), 312)))
			goto LABEL_9
		}
		if v0 <= 89 {
			v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), 313)))
			goto LABEL_9
		}
		v3 = 314
	} else {
		v3 = 311
	}
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), v3)))
LABEL_9:
	if v1 != nil {
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v1)), 16392, 0, 0)
	}
	return nox_draw_setTabWidth_43FE20(15)
}
func nox_game_initOptionsInGame_4ADAD0() int32 {
	var (
		v1  *uint32
		v2  *byte
		v3  int32
		v4  int32
		v5  uint32
		v6  *uint32
		v7  *byte
		v8  int32
		v9  int32
		v10 uint32
		v11 *uint32
		v12 *byte
		v13 int32
		v14 int32
		v15 uint32
		v16 *uint32
	)
	_ = v16
	var v17 *uint32
	var i int32
	var v19 *uint32
	var v20 int32
	var v21 *int32
	var v22 *uint32
	var v23 int32
	var v24 *uint32
	var v25 *byte
	var v26 *byte
	var v27 *byte
	var v28 *byte
	var v29 *byte
	var v30 *byte
	var v31 int32
	_ = v31
	dword_5d4594_1309820 = uint32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("Options.wnd"), nox_xxx_windowOptionsProc_4ADF30))))
	if dword_5d4594_1309820 == 0 {
		return 0
	}
	if nox_client_advVideoOpts_New_4CB590((*gui.Window)(dword_5d4594_1309820)) == 0 {
		return 0
	}
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), 351)))
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*100)), 8)) = 24
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*100)), 12)) = 20
	v28 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v25 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v2 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSlider"))))
	sub_4B5700(int32(uintptr(unsafe.Pointer(v1))), 0, 0, unsafe.Pointer(v2), unsafe.Pointer(v25), unsafe.Pointer(v28))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v1)), 16395, 0, 0x4000)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v1)), 16394, uintptr(*(*uint32)(unsafe.Add(dword_587000_127004, 4))>>16), 0)
	dword_5d4594_1309828 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), 361))))
	v3 = sub_453070()
	v4 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1309828, 36)))
	if v3 == 1 {
		v5 = uint32(v4 | 4)
	} else {
		v5 = uint32(v4) & 0xFFFFFFFB
	}
	*(*uint32)(unsafe.Add(dword_5d4594_1309828, 36)) = v5
	v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), 352)))
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v6), 4*100)), 8)) = 24
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v6), 4*100)), 12)) = 20
	v29 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v26 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v7 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSlider"))))
	sub_4B5700(int32(uintptr(unsafe.Pointer(v6))), 0, 0, unsafe.Pointer(v7), unsafe.Pointer(v26), unsafe.Pointer(v29))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v6)), 16395, 0, 0x4000)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v6)), 16394, uintptr(*(*uint32)(unsafe.Add(dword_587000_122852, 4))>>16), 0)
	dword_5d4594_1309836 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), 362))))
	v8 = sub_44D990()
	v9 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1309836, 36)))
	if v8 == 1 {
		v10 = uint32(v9 | 4)
	} else {
		v10 = uint32(v9) & 0xFFFFFFFB
	}
	*(*uint32)(unsafe.Add(dword_5d4594_1309836, 36)) = v10
	v11 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), 353)))
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v11), 4*100)), 8)) = 24
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v11), 4*100)), 12)) = 20
	v30 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v27 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSliderLit"))))
	v12 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("OptionsVolumeSlider"))))
	sub_4B5700(int32(uintptr(unsafe.Pointer(v11))), 0, 0, unsafe.Pointer(v12), unsafe.Pointer(v27), unsafe.Pointer(v30))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v11)), 16395, 0, 0x4000)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v11)), 16394, uintptr(*(*uint32)(unsafe.Add(dword_587000_93164, 4))>>16), 0)
	dword_5d4594_1309832 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), 363))))
	v13 = sub_43DC30()
	v14 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1309832, 36)))
	if v13 == 1 {
		v15 = uint32(v14 | 4)
	} else {
		v15 = uint32(v14) & 0xFFFFFFFB
	}
	*(*uint32)(unsafe.Add(dword_5d4594_1309832, 36)) = v15
	nox_video_setMenuOptions((*gui.Window)(dword_5d4594_1309820))
	if nox_video_getFullScreen() != 0 {
		v17 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), 333)))
	} else {
		v17 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), 334)))
	}
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v17)), 16392, 1, 0)
	for i = 320; i <= 332; i++ {
		v19 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), i)))
		if v19 != nil && (*(*uint32)(unsafe.Add(unsafe.Pointer(v19), 4*9))&4) == 0 {
			nox_xxx_wndClearFlag_46AD80(int32(uintptr(unsafe.Pointer(v19))), 8)
		}
	}
	dword_5d4594_1309824 = uint32(uintptr(unsafe.Pointer(nox_window_new(nil, 32, 0, 0, 1, 1, nil))))
	v20 = int32(*memmap.PtrUint32(0x587000, 174072))
	if *memmap.PtrInt32(0x587000, 174072) != -1 {
		v21 = mem_getI32Ptr(0x587000, 174080)
		for {
			v22 = (*uint32)(unsafe.Pointer(nox_window_new((*gui.Window)(dword_5d4594_1309824), 0, int(v20), int(*(*int32)(unsafe.Add(unsafe.Pointer(v21), -int(4*1)))), int(*v21), int(*(*int32)(unsafe.Add(unsafe.Pointer(v21), 4*1))), nil)))
			nox_xxx_wndSetDrawFn_46B340((*gui.Window)(unsafe.Pointer(v22)), sub_4ADEF0)
			v20 = *(*int32)(unsafe.Add(unsafe.Pointer(v21), 4*2))
			v21 = (*int32)(unsafe.Add(unsafe.Pointer(v21), 4*4))
			if v20 == -1 {
				break
			}
		}
	}
	v23 = int32(uint32(nox_win_width) - *(*uint32)(unsafe.Add(dword_5d4594_1309820, 8)))
	nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), v23/2, 0)
	nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309824)), v23/2, 0)
	v24 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)), 371)))
	nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v24)), 0)
	nox_window_set_hidden((*gui.Window)(dword_5d4594_1309820), 1)
	nox_window_set_hidden((*gui.Window)(dword_5d4594_1309824), 1)
	return 1
}
func sub_4ADEF0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = (*uint32)(win.C())
		xLeft int32
		yTop  int32
	)
	nox_client_wndGetPosition_46AA60(win, &xLeft, &yTop)
	nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3))))
	return 1
}
func nox_xxx_windowOptionsProc_4ADF30(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		result int32 = 0
		v5     int32
		v6     int32
		v10    unsafe.Pointer
		v13    int32
		v15    int32
	)
	switch a2 {
	case 16389:
		nox_xxx_clientPlaySoundSpecial_452D80(920, 100)
		return 1
	case 16391:
		switch nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) {
		case 311:
			nox_draw_setCutSize_476700(65, 0)
		case 312:
			nox_draw_setCutSize_476700(75, 0)
		case 313:
			nox_draw_setCutSize_476700(85, 0)
		case 314:
			nox_draw_setCutSize_476700(100, 0)
		case 341:
			sub_4AD9B0(0)
			sub_445C40()
			sub_4C4260()
		case 361:
			if sub_453070() == 1 {
				sub_453050()
			} else {
				nox_xxx____setargv_9_453060()
			}
		case 362:
			if sub_44D990() == 1 {
				sub_44D960()
			} else {
				sub_44D970()
			}
		case 363:
			if sub_43DC30() == 1 {
				sub_43DC00()
			} else {
				sub_43DC10()
				sub_486320(dword_587000_93164, *(*uint32)(unsafe.Add(dword_587000_93164, 4))>>16)
			}
		case 371:
			sub_4AD9B0(0)
		default:
		}
		nox_xxx_clientPlaySoundSpecial_452D80(921, 100)
		return 1
	case 16393:
		v5 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
		v6 = int32(uintptr(unsafe.Pointer(nox_client_getWin1064916_46C720())))
		switch v5 {
		case 351:
			sub_486320(dword_587000_127004, int32(a4))
			if v6 != 0 && *(*uint32)(unsafe.Add(v6, 396)) == uint32(a3) {
				return 0
			}
			if a4 != 0 {
				if sub_453070() != 0 {
					nox_xxx_clientPlaySoundSpecial_452D80(768, 100)
					return 0
				}
				v13 = int32(dword_5d4594_1309828)
				v14 := ccall.AsFunc[func(int32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309828, 372)))
				if v14 == nil {
					nox_xxx_clientPlaySoundSpecial_452D80(768, 100)
					return 0
				}
				v14(v13, 21, 28, 2)
				nox_xxx_clientPlaySoundSpecial_452D80(768, 100)
				return 0
			}
			if sub_453070() != 1 {
				return 0
			}
			v12 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309828, 372)))
			if v12 == nil {
				return 0
			}
			v12(dword_5d4594_1309828, 21, 28, 2)
			result = 0
		case 352:
			sub_486320(dword_587000_122852, int32(a4))
			if a4 != 0 {
				if sub_44D990() != 0 {
					sub_4AA650()
					return 0
				}
				v10 = dword_5d4594_1309836
				v11 := ccall.AsFunc[func(unsafe.Pointer, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309836, 372)))
				if v11 == nil {
					sub_4AA650()
					return 0
				}
				v11(v10, 21, 28, 2)
				sub_4AA650()
				return 0
			}
			if sub_44D990() != 1 {
				return 0
			}
			v9 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309836, 372)))
			if v9 == nil {
				return 0
			}
			v9(dword_5d4594_1309836, 21, 28, 2)
			return 0
		case 353:
			sub_486320(dword_587000_93164, int32(a4))
			if a4 != 0 {
				if sub_43DC30() != 0 {
					return 0
				}
				v8 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309832, 372)))
				if v8 == nil {
					return 0
				}
				v8(dword_5d4594_1309832, 21, 28, 2)
				result = 0
			} else {
				if sub_43DC30() != 1 {
					return 0
				}
				v7 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309832, 372)))
				if v7 == nil {
					return 0
				}
				v7(dword_5d4594_1309832, 21, 28, 2)
				result = 0
			}
		case 316:
			nox_video_setGammaSlider(int32(a4))
		case 318:
			nox_input_setSensitivity(math32.Pow(10.0, float32(float64(a4)/50.0-1.0)))
		default:
			return 0
		}
	case 16396:
		v15 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) - 351
		if v15 != 0 {
			if v15 != 1 {
				return 0
			}
			sub_486320(dword_587000_122852, int32(a4))
			if a4 != 0 {
				if sub_44D990() == 0 {
					v10 = dword_5d4594_1309836
					v11 := ccall.AsFunc[func(unsafe.Pointer, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309836, 372)))
					if v11 != nil {
						v11(v10, 21, 28, 2)
					}
				}
				sub_4AA650()
				return 0
			} else {
				if sub_44D990() != 1 {
					return 0
				}
				v16 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309836, 372)))
				if v16 == nil {
					return 0
				}
				v16(dword_5d4594_1309836, 21, 28, 2)
				return 0
			}
		} else {
			sub_486320(dword_587000_127004, int32(a4))
			if a4 != 0 {
				if sub_453070() == 0 {
					v13 = int32(dword_5d4594_1309828)
					v14 := ccall.AsFunc[func(int32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309828, 372)))
					if v14 != nil {
						v14(v13, 21, 28, 2)
					}
				}
				nox_xxx_clientPlaySoundSpecial_452D80(768, 100)
				return 0
			}
			if sub_453070() != 1 {
				return 0
			}
			v17 := ccall.AsFunc[func(uint32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1309828, 372)))
			if v17 == nil {
				return 0
			}
			v17(dword_5d4594_1309828, 21, 28, 2)
			return 0
		}
	default:
		return 0
	}
	return uintptr(result)
}
func sub_4AE3B0() int32 {
	var result int32
	result = nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(unsafe.Pointer(dword_5d4594_1309820)))
	dword_5d4594_1309820 = 0
	return result
}
func sub_4AE3D0() int32 {
	var result int32
	if wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(dword_5d4594_1309820)) != 0 {
		result = sub_4C4280()
	} else {
		result = 1
	}
	return result
}
func sub_4AEE30() int64 {
	var (
		v0     int32
		v1     *uint8
		result int64
	)
	v0 = 0
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1309840))
	for {
		result = int64(math.Sin(float64(v0+192)**mem_getDoublePtr(0x581450, 9768)**mem_getDoublePtr(0x581450, 9760)) * qword_581450_9552)
		*(*uint32)(unsafe.Pointer(v1)) = uint32(int32(result))
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 4))
		v0++
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1311120))) {
			break
		}
	}
	return result
}
func sub_4B4860(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		a1  = int32(uintptr(win.C()))
		v4  int32
		v5  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
	)
	v4 = int32(*(*uint32)(unsafe.Add(a1, 32)))
	switch a2 {
	case 5:
		return 1
	case 6, 7:
		v9 = int32(a3)
		v10 = int32(uint16(int16(a3)))
		nox_client_wndGetPosition_46AA60((*gui.Window)(a1), (*uint32)(unsafe.Pointer(&a4)), (*uint32)(unsafe.Pointer(&a3)))
		if v10 > *(*int32)(unsafe.Add(a1, 8))+int32(uint32(a4))-10 {
			v10 = int32(*(*uint32)(unsafe.Add(a1, 8)) + uint32(a4) - 10)
		}
		nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(a1, 400)))), v10-int32(uint32(a4))-5, 0)
		nox_window_call_field_94_fnc((*gui.Window)(a1), 0x4000, 0, uintptr(v9))
		return 1
	case 8:
		v8 = int32(*(*uint32)(unsafe.Add(a1, 44)))
		if (v8 & 0x100) == 0 {
			return 1
		}
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 0x4000, uintptr(a1), 0)
		return 1
	case 17:
		v5 = int32(*(*uint32)(unsafe.Add(a1, 44)))
		if (v5 & 0x100) == 0 {
			return 1
		}
		nox_xxx_wndSetRectColor2MB_46AFE0((*gui.Window)(a1), int32(*(*uint32)(unsafe.Add(a1, 72))))
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16389, uintptr(a1), 0)
		nox_xxx_windowFocus_46B500((*gui.Window)(a1))
		return 1
	case 18:
		v7 = int32(*(*uint32)(unsafe.Add(a1, 44)))
		if v7&0x100 != 0 {
			nox_xxx_wndSetRectColor2MB_46AFE0((*gui.Window)(a1), int32(*(*uint32)(unsafe.Add(a1, 64))))
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16390, uintptr(a1), 0)
		}
		return 1
	case 21:
		switch a3 {
		case 15, 208:
			if a4 != 2 {
				return 1
			}
			nox_xxx_wndRetNULL_46A8A0()
			return 1
		case 200:
			if a4 == 2 {
				nox_xxx_wndRetNULL_0_46A8B0()
			}
			return 1
		case 203:
			if a4 != 2 {
				return 1
			}
			v13 = int32(*(*uint32)(unsafe.Add(v4, 12)))
			if v13 >= *(*int32)(unsafe.Add(v4, 4))-1 {
				return 1
			}
			v14 = v13 + 2
			*(*uint32)(unsafe.Add(v4, 12)) = uint32(v14)
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16393, uintptr(a1), uintptr(v14))
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(a1, 400)))), int32(int64(float64(int32(*(*uint32)(unsafe.Add(v4, 12))-*(*uint32)(v4)))*float64(*(*float32)(unsafe.Add(v4, 8))))), 0)
			return 1
		case 205:
			if a4 != 2 {
				return 1
			}
			v11 = int32(*(*uint32)(unsafe.Add(v4, 12)))
			if v11 <= *(*int32)(v4)+1 {
				return 1
			}
			v12 = v11 - 2
			*(*uint32)(unsafe.Add(v4, 12)) = uint32(v12)
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16393, uintptr(a1), uintptr(v12))
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(a1, 400)))), int32(int64(float64(int32(*(*uint32)(unsafe.Add(v4, 12))-*(*uint32)(v4)))*float64(*(*float32)(unsafe.Add(v4, 8))))), 0)
			return 1
		default:
			return 0
		}
	default:
		return 0
	}
}
func nox_xxx_wndScrollBoxDraw_4B4BA0(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		a1  = int32(uintptr(win.C()))
		v4  int32
		v5  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
	)
	v4 = int32(*(*uint32)(unsafe.Add(a1, 32)))
	switch a2 {
	case 5:
		return 1
	case 6, 7:
		v9 = int32(a3)
		v10 = int32(a3 >> 16)
		var (
			tmp uint32
			py  uint32
		)
		nox_client_wndGetPosition_46AA60((*gui.Window)(a1), &tmp, &py)
		if v10 > *(*int32)(unsafe.Add(a1, 12))+int32(py)-10 {
			v10 = int32(*(*uint32)(unsafe.Add(a1, 12)) + py - 10)
		}
		nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(a1, 400)))), 0, v10-int32(py)-5)
		nox_window_call_field_94_fnc((*gui.Window)(a1), 0x4000, 0, uintptr(v9))
		return 1
	case 8:
		v8 = int32(*(*uint32)(unsafe.Add(a1, 44)))
		if (v8 & 0x100) == 0 {
			return 1
		}
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 0x4000, uintptr(a1), 0)
		return 1
	case 17:
		v5 = int32(*(*uint32)(unsafe.Add(a1, 44)))
		if (v5 & 0x100) == 0 {
			return 1
		}
		nox_xxx_wndSetRectColor2MB_46AFE0((*gui.Window)(a1), int32(*(*uint32)(unsafe.Add(a1, 72))))
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16389, uintptr(a1), 0)
		nox_xxx_windowFocus_46B500((*gui.Window)(a1))
		return 1
	case 18:
		v7 = int32(*(*uint32)(unsafe.Add(a1, 44)))
		if v7&0x100 != 0 {
			nox_xxx_wndSetRectColor2MB_46AFE0((*gui.Window)(a1), int32(*(*uint32)(unsafe.Add(a1, 64))))
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16390, uintptr(a1), 0)
		}
		return 1
	case 21:
		switch a3 {
		case 0xF, 0xCD:
			if a4 != 2 {
				return 1
			}
			nox_xxx_wndRetNULL_46A8A0()
			return 1
		case 0xC8:
			if a4 != 2 {
				return 1
			}
			v11 = int32(*(*uint32)(unsafe.Add(v4, 12)))
			if v11 >= *(*int32)(unsafe.Add(v4, 4))-1 {
				return 1
			}
			v12 = v11 + 2
			*(*uint32)(unsafe.Add(v4, 12)) = uint32(v12)
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16393, uintptr(a1), uintptr(v12))
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(a1, 400)))), 0, int32(int64(float64(int32(*(*uint32)(unsafe.Add(v4, 4))-*(*uint32)(unsafe.Add(v4, 12))))*float64(*(*float32)(unsafe.Add(v4, 8))))))
			return 1
		case 0xCB:
			if a4 == 2 {
				nox_xxx_wndRetNULL_0_46A8B0()
			}
			return 1
		case 0xD0:
			if a4 != 2 {
				return 1
			}
			v13 = int32(*(*uint32)(unsafe.Add(v4, 12)))
			if v13 <= *(*int32)(v4)+1 {
				return 1
			}
			v14 = v13 - 2
			*(*uint32)(unsafe.Add(v4, 12)) = uint32(v14)
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16393, uintptr(a1), uintptr(v14))
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(a1, 400)))), 0, int32(int64(float64(int32(*(*uint32)(unsafe.Add(v4, 4))-*(*uint32)(unsafe.Add(v4, 12))))*float64(*(*float32)(unsafe.Add(v4, 8))))))
			return 1
		default:
			return 0
		}
	default:
		return 0
	}
}
func nox_gui_newSlider_4B4EE0(a1 *gui.Window, a2 nox_window_flags, a3, a4, a5, a6 int, a7 *uint32, a8 *float32) *gui.Window {
	var (
		v8  int32
		v9  int32
		v10 *uint32
		v11 int32
		v12 float64
		v13 *float32
	)
	v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a7), 4*2)))
	if v8&0x10 != 0 {
		v9 = int32(a6)
		v10 = (*uint32)(unsafe.Pointer(nox_window_new(a1, a2|0x100, a3, a4, a5, a6, sub_4B5010)))
		sub_4B51A0(int32(uintptr(unsafe.Pointer(v10))))
	} else {
		if (v8 & 8) == 0 {
			return nil
		}
		v9 = int32(a6)
		v10 = (*uint32)(unsafe.Pointer(nox_window_new(a1, a2|0x100, a3, a4, a5, a6, nox_xxx_wndScrollBoxProc_4B5320)))
		nox_xxx_wndScrollBoxSetAllFn_4B5500(AsWindowP(unsafe.Pointer(v10)), nil)
	}
	if v10 != nil {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(a7), 4*4)) == 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(a7), 4*4)) = uint32(uintptr(unsafe.Pointer(v10)))
		}
		nox_gui_windowCopyDrawData_46AF80((*gui.Window)(unsafe.Pointer(v10)), unsafe.Pointer(a7))
		nox_xxx_wndScrollBoxButtonCreate_4B5640(int32(uintptr(unsafe.Pointer(v10))), a2|0x100, unsafe.Pointer(a7))
		v11 = int32(*(*uint32)(unsafe.Pointer(a8)))
		if *(*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*1)) == *(*uint32)(unsafe.Pointer(a8)) {
			*(*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*1)) = uint32(v11 + 1)
		}
		if *(*uint32)(unsafe.Add(unsafe.Pointer(a7), 4*2))&0x10 != 0 {
			v12 = float64(a5-10) / float64(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*1))-uint32(v11)))
		} else {
			v12 = float64(v9-10) / float64(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a8), 4*1))-uint32(v11)))
		}
		*(*float32)(unsafe.Add(unsafe.Pointer(a8), unsafe.Sizeof(float32(0))*2)) = float32(v12)
		v13 = (*float32)(alloc.Calloc1(1, 0x10))
		*v13 = *a8
		*(*float32)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(float32(0))*1)) = *(*float32)(unsafe.Add(unsafe.Pointer(a8), unsafe.Sizeof(float32(0))*1))
		*(*float32)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(float32(0))*2)) = *(*float32)(unsafe.Add(unsafe.Pointer(a8), unsafe.Sizeof(float32(0))*2))
		*(*float32)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(float32(0))*3)) = *(*float32)(unsafe.Add(unsafe.Pointer(a8), unsafe.Sizeof(float32(0))*3))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*8)) = uint32(uintptr(unsafe.Pointer(v13)))
	}
	return (*gui.Window)(unsafe.Pointer(v10))
}
func sub_4B5010(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		a1  = int32(uintptr(win.C()))
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int64
		v14 int32
		v15 int32
		v16 int32
		v17 float64
		v18 *int32
	)
	v4 = a1
	v5 = int32(*(*uint32)(unsafe.Add(a1, 32)))
	if a2 > 0x4000 {
		if a2 == 16394 {
			if int32(a3) >= *(*int32)(v5) && int32(a3) <= *(*int32)(unsafe.Add(v5, 4)) {
				v17 = float64(a3)
				*(*uint32)(unsafe.Add(v5, 12)) = uint32(a3)
				nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(v4, 400)))), int32(int64(v17*float64(*(*float32)(unsafe.Add(v5, 8))))), 0)
			}
		} else if a2 == 16395 {
			v14 = int32(a3)
			v15 = int32(a4)
			*(*uint32)(v5) = uint32(a3)
			*(*uint32)(unsafe.Add(v5, 4)) = uint32(v15)
			v16 = int32(*(*uint32)(unsafe.Add(v4, 8)) - 10)
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(v14)
			*(*float32)(unsafe.Add(v5, 8)) = float32(float64(v16) / float64(v15-v14))
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(v4, 400)))), 0, 0)
			return 0
		}
		return 0
	}
	if a2 == 0x4000 {
		v10 = int32(uint16(int16(a4)))
		nox_client_wndGetPosition_46AA60((*gui.Window)(a1), (*uint32)(unsafe.Pointer(&a3)), &a1)
		if v10 < int32(a3) {
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(v4, 400)))), 0, 0)
			v11 = int32(*(*uint32)(v5))
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(v11)
			nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v4, 52))), 16393, uintptr(v4), uintptr(*(*uint32)(unsafe.Add(v5, 12))))
			return 0
		}
		v12 = int32(*(*uint32)(unsafe.Add(v4, 8)))
		if v10 < v12+int32(a3) {
			v13 = int64(float64(v10-int32(a3)) / float64(*(*float32)(unsafe.Add(v5, 8))))
			v11 = int32(*(*uint32)(unsafe.Add(v5, 4)))
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(int32(v13))
			if int32(v13) > v11 {
				*(*uint32)(unsafe.Add(v5, 12)) = uint32(v11)
				nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v4, 52))), 16393, uintptr(v4), uintptr(*(*uint32)(unsafe.Add(v5, 12))))
				return 0
			}
		} else {
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(v4, 400)))), int32(uint32(v12)-*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 400)), 8))), 0)
			*(*uint32)(unsafe.Add(v5, 12)) = *(*uint32)(unsafe.Add(v5, 4))
		}
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v4, 52))), 16393, uintptr(v4), uintptr(*(*uint32)(unsafe.Add(v5, 12))))
		return 0
	}
	if a2 == 2 {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(a1, 32)))
		return 0
	}
	if a2 != 23 {
		return 0
	}
	v6 = int32(a3)
	v7 = int32(*(*uint32)(unsafe.Add(a1, 36)))
	if a3 != 0 {
		*(*uint8)(unsafe.Pointer(&v7)) = uint8(int8(v7 | 2))
	} else {
		*(*uint8)(unsafe.Pointer(&v7)) = uint8(int8(v7 & 0xFD))
	}
	v18 = (*int32)(a1)
	*(*uint32)(unsafe.Add(a1, 36)) = uint32(v7)
	v8 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(v18)))
	nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v4, 52))), 16387, uintptr(v6), uintptr(v8))
	return 1
}
func sub_4B51A0(a1 int32) int32 {
	if a1 == 0 {
		return 0
	}
	if int32(int8(*(*uint8)(unsafe.Add(a1, 4)))) >= 0 {
		return nox_window_set_all_funcs((*gui.Window)(a1), sub_4B4860, sub_4B51E0, nil)
	} else {
		return nox_window_set_all_funcs((*gui.Window)(a1), sub_4B4860, sub_4B52C0, nil)
	}
}
func sub_4B51E0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = int32(uintptr(win.C()))
		a2    = int32(uintptr(draw.C()))
		v2    int32
		v3    int32
		v4    int32
		xLeft int32
		yTop  int32
	)
	v2 = int32(*(*uint32)(unsafe.Add(a2, 28)))
	v3 = int32(*(*uint32)(unsafe.Add(a2, 20)))
	nox_client_wndGetPosition_46AA60((*gui.Window)(a1), &xLeft, &yTop)
	if int32(*(*uint8)(unsafe.Add(a1, 4)))&8 != 0 {
		if int32(*(*uint8)(a2))&2 != 0 && *(*uint32)(unsafe.Add(a2, 36)) != 0x80000000 {
			nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(a2, 36))))
			nox_client_drawBorderLines_49CC70(xLeft, yTop, int32(*(*uint32)(unsafe.Add(a1, 8))), int32(*(*uint32)(unsafe.Add(a1, 12))))
		}
	} else {
		v3 = int32(*(*uint32)(unsafe.Add(a2, 44)))
	}
	if uint32(v3) != 0x80000000 {
		nox_client_drawSetColor_434460(v3)
		nox_client_drawRectFilledOpaque_49CE30(xLeft+1, yTop+1, int32(*(*uint32)(unsafe.Add(a1, 8))-2), int32(*(*uint32)(unsafe.Add(a1, 12))-2))
	}
	v4 = int32(uint32(yTop) + *(*uint32)(unsafe.Add(a1, 12))/2)
	if uint32(v2) != 0x80000000 {
		nox_client_drawSetColor_434460(v2)
		nox_client_drawRectFilledOpaque_49CE30(xLeft, v4-1, int32(*(*uint32)(unsafe.Add(a1, 8))), 3)
	}
	return 1
}
func sub_4B52C0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1 = int32(uintptr(win.C()))
		a2 = int32(uintptr(draw.C()))
		v2 int32
		v4 int32
		v5 int32
	)
	v2 = int32(*(*uint32)(unsafe.Add(a2, 24)))
	nox_client_wndGetPosition_46AA60((*gui.Window)(a1), &v4, &v5)
	if (int32(*(*uint8)(unsafe.Add(a1, 4))) & 8) == 0 {
		v2 = int32(*(*uint32)(unsafe.Add(a2, 48)))
	}
	if v2 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(v2), v4, v5)
	}
	return 1
}
func nox_xxx_wndScrollBoxProc_4B5320(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		a1  = int32(uintptr(win.C()))
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int64
		v9  int32
		v11 int32
		v12 int32
		v13 int32
		v14 uint32
		v15 int32
		v16 int32
		v17 float64
		v18 int32
		v19 int32
		v20 *int32
	)
	v4 = a1
	v5 = int32(*(*uint32)(unsafe.Add(a1, 32)))
	if a2 > 0x4007 {
		if a2 == 16394 {
			if int32(a3) >= *(*int32)(v5) {
				v18 = int32(*(*uint32)(unsafe.Add(v5, 4)))
				if int32(a3) <= v18 {
					v19 = v18 - int32(a3)
					*(*uint32)(unsafe.Add(v5, 12)) = uint32(a3)
					nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(v4, 400)))), 0, int32(int64(float64(v19)*float64(*(*float32)(unsafe.Add(v5, 8))))))
				}
			}
		} else if a2 == 16395 {
			v14 = uint32(a4)
			v15 = int32(a3)
			*(*uint32)(unsafe.Add(v5, 4)) = uint32(a4)
			*(*uint32)(v5) = uint32(v15)
			a3b := int32(v14 - uint32(v15))
			v16 = int32(*(*uint32)(unsafe.Add(v4, 12)))
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(v15)
			v17 = float64(a3b)
			*(*float32)(unsafe.Add(v5, 8)) = float32(float64(v16-10) / v17)
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(v4, 400)))), 0, int32(int64(v17*float64(*(*float32)(unsafe.Add(v5, 8))))))
			return 0
		}
		return 0
	}
	switch a2 {
	case 0x4007:
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(a1, 52))), 16396, uintptr(a1), uintptr(*(*uint32)(unsafe.Add(v5, 12))))
		return 0
	case 2:
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(a1, 32)))
		return 0
	case 0x17:
		v11 = int32(a3)
		v12 = int32(*(*uint32)(unsafe.Add(a1, 36)))
		if a3 != 0 {
			*(*uint8)(unsafe.Pointer(&v12)) = uint8(int8(v12 | 2))
		} else {
			*(*uint8)(unsafe.Pointer(&v12)) = uint8(int8(v12 & 0xFD))
		}
		v20 = (*int32)(a1)
		*(*uint32)(unsafe.Add(a1, 36)) = uint32(v12)
		v13 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(v20)))
		nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v4, 52))), 16387, uintptr(v11), uintptr(v13))
		return 1
	}
	if a2 != 0x4000 {
		return 0
	}
	v6 = int32(a4 >> 16)
	nox_client_wndGetPosition_46AA60((*gui.Window)(a1), &a1, (*uint32)(unsafe.Pointer(&a3)))
	if v6 >= int32(a3) {
		v7 = int32(*(*uint32)(unsafe.Add(v4, 12)))
		if v6 < v7+int32(a3) {
			v8 = int64(float64(v6-int32(a3)) / float64(*(*float32)(unsafe.Add(v5, 8))))
			v9 = int32(*(*uint32)(unsafe.Add(v5, 4)))
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(int32(v8))
			if int32(v8) > v9 {
				*(*uint32)(unsafe.Add(v5, 12)) = uint32(v9)
			}
			*(*uint32)(unsafe.Add(v5, 12)) = uint32(v9) - *(*uint32)(unsafe.Add(v5, 12))
		} else {
			nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(v4, 400)))), 0, int32(uint32(v7)-*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 400)), 12))))
			*(*uint32)(unsafe.Add(v5, 12)) = *(*uint32)(v5)
		}
	} else {
		nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Add(v4, 400)))), 0, 0)
		*(*uint32)(unsafe.Add(v5, 12)) = *(*uint32)(unsafe.Add(v5, 4))
	}
	nox_window_call_field_94_fnc((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v4, 52))), 16393, uintptr(v4), uintptr(*(*uint32)(unsafe.Add(v5, 12))))
	return 0
}
func nox_xxx_wndScrollBoxSetAllFn_4B5500(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1 = int32(uintptr(win.C()))
	)
	if win == nil {
		return 0
	}
	if int32(int8(*(*uint8)(unsafe.Add(a1, 4)))) >= 0 {
		return int(nox_window_set_all_funcs(win, nox_xxx_wndScrollBoxDraw_4B4BA0, nox_xxx_wndScrollBoxDraw_4B5540, nil))
	} else {
		return int(nox_window_set_all_funcs(win, nox_xxx_wndScrollBoxDraw_4B4BA0, nox_xxx_wndScrollBoxDraw_4B5620, nil))
	}
}
func nox_xxx_wndScrollBoxDraw_4B5540(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = int32(uintptr(win.C()))
		a2    = int32(uintptr(draw.C()))
		v2    int32
		v3    int32
		v4    int32
		xLeft int32
		yTop  int32
	)
	v2 = int32(*(*uint32)(unsafe.Add(a2, 28)))
	v3 = int32(*(*uint32)(unsafe.Add(a2, 20)))
	nox_client_wndGetPosition_46AA60((*gui.Window)(a1), &xLeft, &yTop)
	if int32(*(*uint8)(unsafe.Add(a1, 4)))&8 != 0 {
		if int32(*(*uint8)(a2))&2 != 0 {
			v2 = int32(*(*uint32)(unsafe.Add(a2, 52)))
			if *(*uint32)(unsafe.Add(a2, 36)) != 0x80000000 {
				nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(a2, 36))))
				nox_client_drawBorderLines_49CC70(xLeft, yTop, int32(*(*uint32)(unsafe.Add(a1, 8))), int32(*(*uint32)(unsafe.Add(a1, 12))))
			}
		}
	} else {
		v3 = int32(*(*uint32)(unsafe.Add(a2, 44)))
	}
	if uint32(v3) != 0x80000000 {
		nox_client_drawSetColor_434460(v3)
		nox_client_drawRectFilledOpaque_49CE30(xLeft+1, yTop+1, int32(*(*uint32)(unsafe.Add(a1, 8))-2), int32(*(*uint32)(unsafe.Add(a1, 12))-2))
	}
	v4 = int32(uint32(xLeft) + *(*uint32)(unsafe.Add(a1, 8))/2)
	if uint32(v2) != 0x80000000 {
		nox_client_drawSetColor_434460(v2)
		nox_client_drawRectFilledOpaque_49CE30(v4-1, yTop+4, 3, int32(*(*uint32)(unsafe.Add(a1, 12))-8))
	}
	return 1
}
func nox_xxx_wndScrollBoxDraw_4B5620(win *gui.Window, draw *gui.WindowData) int {
	var (
		v2 int32
		v3 int32
	)
	nox_client_wndGetPosition_46AA60(win, &v2, &v3)
	return 1
}
func nox_xxx_wndScrollBoxButtonCreate_4B5640(a1 *gui.Window, a2 nox_window_flags, a3 unsafe.Pointer) int32 {
	var (
		v3     int32
		result int32
		v6     [332]byte
	)
	v3 = int32(*(*uint32)(unsafe.Add(a3, 68)))
	*(*uint32)(unsafe.Pointer(&v6[0])) = 0
	libc.MemSet(unsafe.Pointer(&v6[4]), 0, 0x148)
	v4 := a2
	*(*unsafe.Pointer)(unsafe.Pointer(&v6[16])) = a1.C()
	*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(a2&0xEF | 0xC))
	*(*uint32)(unsafe.Pointer(&v6[8])) = 1
	*(*uint32)(unsafe.Pointer(&v6[68])) = uint32(v3)
	if (v4 & 0x80) == 0 {
		*(*uint32)(unsafe.Pointer(&v6[52])) = *(*uint32)(unsafe.Add(a3, 52))
		*(*uint32)(unsafe.Pointer(&v6[28])) = *(*uint32)(unsafe.Add(a3, 20))
		*(*uint32)(unsafe.Pointer(&v6[20])) = *(*uint32)(unsafe.Add(a3, 28))
	} else {
		*(*uint32)(unsafe.Pointer(&v6[32])) = *(*uint32)(unsafe.Add(a3, 32))
		*(*uint32)(unsafe.Pointer(&v6[48])) = *(*uint32)(unsafe.Add(a3, 48))
		*(*uint32)(unsafe.Pointer(&v6[56])) = *(*uint32)(unsafe.Add(a3, 56))
		*(*uint32)(unsafe.Pointer(&v6[24])) = *(*uint32)(unsafe.Add(a3, 24))
		*(*uint32)(unsafe.Pointer(&v6[40])) = *(*uint32)(unsafe.Add(a3, 40))
	}
	if int32(*(*uint8)(unsafe.Add(a3, 8)))&0x10 != 0 {
		result = int32(uintptr(unsafe.Pointer(nox_gui_newButtonOrCheckbox_4A91A0(a1, v4, 0, 0, 10, int(*(*uint32)(unsafe.Add(a1.C(), 12))), (*gui.WindowData)(unsafe.Pointer(&v6[0]))))))
	} else {
		result = int32(uintptr(unsafe.Pointer(nox_gui_newButtonOrCheckbox_4A91A0(a1, v4, 0, 0, int(*(*uint32)(unsafe.Add(a1.C(), 8))), 10, (*gui.WindowData)(unsafe.Pointer(&v6[0]))))))
	}
	return result
}
func sub_4B5700(a1p *gui.Window, a2 int32, a3 int32, a4 unsafe.Pointer, a5 unsafe.Pointer, a6 unsafe.Pointer) {
	a1 := a1p.C()
	if a1p != nil {
		v6 := *(*unsafe.Pointer)(unsafe.Add(a1, 400))
		v7 := int32(*(*uint32)(unsafe.Add(v6, 4)))
		*(*uint8)(unsafe.Pointer(&v7)) = uint8(int8(v7 | 0x80))
		*(*uint32)(unsafe.Add(v6, 4)) = uint32(v7)
		nox_xxx_wndButtonInit_4A8340(int32(*(*uint32)(unsafe.Add(a1, 400))))
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 400)), 60)) = uint32(a2)
		*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 400)), 68)) = a4
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 400)), 84)) = uint32(a3)
		*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 400)), 92)) = a5
		*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 400)), 76)) = a6
	}
}
func sub_4B5CD0() int32 {
	var (
		v0     int8
		v1     *uint8
		v2     int32
		v3     *uint8
		v4     int32
		v5     int32
		v6     int32
		v7     *uint8
		v8     int32
		v9     *uint8
		result int32
		v12    int32
	)
	v0 = 0
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1312500))
	for {
		*(*uint8)(unsafe.Pointer(&v12)) = uint8(int8(int32(v0) / 63))
		*(*uint32)(unsafe.Pointer(v1)) = nox_color_rgb_4344A0(int32(uint8(int8(int32(v0)/63)))/3, int32(uint8(int8(int32(v0)/63)))*3/5, v12)
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 4))
		v0--
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1312756))) {
			break
		}
	}
	v2 = 0
	v3 = (*uint8)(memmap.PtrOff(0x5D4594, 1312756))
	for {
		*(*uint8)(unsafe.Pointer(&v12)) = uint8(int8(v2 / 32))
		v4 = int32(nox_color_rgb_4344A0(v12, v12, 0))
		*(*uint8)(unsafe.Pointer(&v5)) = uint8(int8(-1 - v12))
		*(*uint32)(unsafe.Pointer(v3)) = uint32(v4)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*32)) = nox_color_rgb_4344A0(math.MaxUint8, v5, 0)
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
		v2 += math.MaxUint8
		if int32(uintptr(unsafe.Pointer(v3))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1312884))) {
			break
		}
	}
	v6 = 0
	v7 = (*uint8)(memmap.PtrOff(0x5D4594, 1313012))
	for {
		*(*uint8)(unsafe.Pointer(&v12)) = uint8(int8(v6 / 63))
		*(*uint32)(unsafe.Pointer(v7)) = nox_color_rgb_4344A0(v12, v12, v12)
		v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 4))
		v6 += math.MaxUint8
		if int32(uintptr(unsafe.Pointer(v7))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1313268))) {
			break
		}
	}
	v8 = 0
	v9 = (*uint8)(memmap.PtrOff(0x5D4594, 1313268))
	for {
		result = int32(nox_color_rgb_4344A0(v8/63, 50, 50))
		*(*uint32)(unsafe.Pointer(v9)) = uint32(result)
		v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 4))
		v8 += math.MaxUint8
		if int32(uintptr(unsafe.Pointer(v9))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1313524))) {
			break
		}
	}
	return result
}
func sub_4B63B0(a1 *int2, a2 *int2) int32 {
	var (
		v2 int32
		v3 int32
	)
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1312492))
	nox_client_drawAddPoint_49F500(a1.field_0, a1.field_4)
	nox_client_drawAddPoint_49F500(a2.field_0, a2.field_4)
	nox_client_drawLineFromPoints_49E4B0()
	v2 = a2.field_0 - a1.field_0
	v3 = a2.field_4 - a1.field_4
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1312496))
	if v2 < 0 {
		v2 = -v2
	}
	if v3 < 0 {
		v3 = -v3
	}
	if v2 <= v3 {
		nox_client_drawAddPoint_49F500(a1.field_0-1, a1.field_4)
		nox_client_drawAddPoint_49F500(a2.field_0-1, a2.field_4)
		nox_client_drawLineFromPoints_49E4B0()
		nox_client_drawAddPoint_49F500(a1.field_0+1, a1.field_4)
		nox_client_drawAddPoint_49F500(a2.field_0+1, a2.field_4)
	} else {
		nox_client_drawAddPoint_49F500(a1.field_0, a1.field_4-1)
		nox_client_drawAddPoint_49F500(a2.field_0, a2.field_4-1)
		nox_client_drawLineFromPoints_49E4B0()
		nox_client_drawAddPoint_49F500(a1.field_0, a1.field_4+1)
		nox_client_drawAddPoint_49F500(a2.field_0, a2.field_4+1)
	}
	return nox_client_drawLineFromPoints_49E4B0()
}
func sub_4B64C0() int32 {
	var (
		v0 uint8
		v1 *uint8
		v2 int32
		v3 int32
		v5 int32
		v6 int32
		v7 int32
		v8 int32
	)
	*memmap.PtrUint32(0x5D4594, 1313524) = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, 0)
	*memmap.PtrUint32(0x5D4594, 1313528) = nox_color_rgb_4344A0(math.MaxUint8, 100, 0)
	dword_5d4594_1313532 = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, 0)
	dword_5d4594_1313536 = nox_color_rgb_4344A0(0, 0, math.MaxUint8)
	dword_5d4594_1313540 = nox_color_rgb_4344A0(0, 200, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1313544) = nox_color_rgb_4344A0(0, 200, 200)
	*memmap.PtrUint32(0x5D4594, 1313548) = nox_color_rgb_4344A0(50, math.MaxUint8, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1313552) = nox_color_rgb_4344A0(math.MaxUint8, 0, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1313556) = nox_color_rgb_4344A0(math.MaxUint8, 200, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1313560) = nox_color_rgb_4344A0(math.MaxUint8, 200, 0)
	dword_5d4594_1313564 = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, 100)
	*memmap.PtrUint32(0x5D4594, 1313568) = nox_color_rgb_4344A0(100, math.MaxUint8, 50)
	*memmap.PtrUint32(0x5D4594, 1313572) = nox_color_rgb_4344A0(150, math.MaxUint8, 150)
	*memmap.PtrUint32(0x5D4594, 1313576) = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, 0)
	*memmap.PtrUint32(0x5D4594, 1313580) = nox_color_rgb_4344A0(0, 220, 0)
	*memmap.PtrUint32(0x5D4594, 1313584) = nox_color_rgb_4344A0(150, math.MaxUint8, 150)
	*memmap.PtrUint32(0x5D4594, 1313588) = nox_color_rgb_4344A0(200, 200, 200)
	*memmap.PtrUint32(0x5D4594, 1313592) = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, math.MaxUint8)
	*(*uint8)(unsafe.Pointer(&v8)) = math.MaxUint8
	*(*uint8)(unsafe.Pointer(&v7)) = math.MaxUint8
	*(*uint8)(unsafe.Pointer(&v6)) = math.MaxUint8
	v0 = 0
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1313656))
	v2 = 1085
	v5 = 600
	v3 = 765
	for {
		if int32(v0) > 3 {
			if int32(v0) > 7 {
				*(*uint8)(unsafe.Pointer(&v8)) = uint8(int8(v2/9 - 1))
			} else {
				*(*uint8)(unsafe.Pointer(&v7)) = uint8(int8(v5/4 - 1))
			}
		} else {
			*(*uint8)(unsafe.Pointer(&v6)) = uint8(int8(v3 / 3))
		}
		*(*uint32)(unsafe.Pointer(v1)) = nox_color_rgb_4344A0(v8, v7, v6)
		v0++
		v3 -= math.MaxUint8
		v2 -= 155
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), -4))
		v5 -= 200
		if int32(v0) >= 0x10 {
			break
		}
	}
	return sub_4B5CD0()
}
func sub_4B6880(a1 *uint32, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4     int32
		v5     int32
		v6     int32
		result int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    bool
		v13    int32
		xLeft  int2
		v15    int32
	)
	v4 = a2
	v5 = int32(*(*uint32)(unsafe.Add(a2, 448)) - *(*uint32)(unsafe.Add(a2, 444)))
	v15 = int32(*(*uint32)(unsafe.Add(a2, 448)) - gameFrame())
	v6 = v15
	if v15 == v5 {
		v6 = func() int32 {
			p := &v15
			*p--
			return *p
		}()
	}
	if v6 > 0 {
		v8 = int32(*a1 + *(*uint32)(unsafe.Add(v4, 12)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		v9 = int32(*(*uint32)(unsafe.Add(v4, 16)) - uint32(*(*int16)(unsafe.Add(v4, 106))) - uint32(*(*int16)(unsafe.Add(v4, 104))) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
		v11 = v10 + v9
		v12 = uint32(v8-10) < *a1
		xLeft.field_0 = v8
		xLeft.field_4 = v11
		if !v12 && v11-10 >= v10 && uint32(v8+10) < *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) && uint32(v11+10) < *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) {
			v13 = v15 * 4 / v5
			sub_4B6720(&xLeft, a4, v13*2+1, int8(v15*5/v5))
			nox_client_drawSetColor_434460(a3)
			nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, v13)
		}
		result = 1
	} else {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable((*client.Drawable)(v4))
		result = 0
	}
	return result
}
func sub_4B6970(a1 *uint32, dr *client.Drawable, a3 int32, a4 int32) int {
	var (
		v4 int32
		v5 int32
		a2 int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	v4 = int32(*(*uint32)(unsafe.Add(a2, 440)))
	*(*uint32)(unsafe.Add(a2, 432)) += uint32(v4 * *memmap.PtrInt32(0x587000, uintptr(int32(*(*uint8)(unsafe.Add(a2, 299)))*8)+192088))
	v5 = int32(uint32(v4**memmap.PtrInt32(0x587000, uintptr(int32(*(*uint8)(unsafe.Add(a2, 299)))*8)+192092)) + *(*uint32)(unsafe.Add(a2, 436)))
	*(*uint32)(unsafe.Add(a2, 436)) = uint32(v5)
	nox_xxx_updateSpritePosition_49AA90((*client.Drawable)(a2), int32(*(*uint32)(unsafe.Add(a2, 432))>>12), v5>>12)
	sub_4B69F0(a2)
	return int(sub_4B6880(a1, a2, a3, a4))
}
func sub_4B69F0(a1 int32) int16 {
	var (
		v1     int8
		result int16
		v3     int32
	)
	v1 = int8(*(*uint8)(unsafe.Add(a1, 296)))
	*(*uint16)(unsafe.Add(a1, 104)) += uint16(v1)
	result = int16(*(*uint16)(unsafe.Add(a1, 104)))
	if int32(result) >= 0 {
		if int32(uint8(gameFrame()))&1 != 0 {
			*(*uint8)(unsafe.Add(a1, 296)) = uint8(int8(int32(v1) - 1))
		}
	} else {
		*(*uint16)(unsafe.Add(a1, 104)) = uint16(int16(int32(-result)))
		result = int16(int32(v1) * 26209)
		v3 = int32(v1) * (-9) / 10
		*(*uint8)(unsafe.Add(a1, 296)) = uint8(int8(v3))
		if int32(int8(v3)) < 2 {
			*(*uint16)(unsafe.Add(a1, 104)) = 0
			*(*uint8)(unsafe.Add(a1, 296)) = 0
		}
	}
	return result
}
func sub_4B6B80(a1 *int32, dr *client.Drawable, a3 int32) int {
	var (
		v3    int32
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		v8    int32
		v10   int32
		v11   int32
		v12   int32
		v13   int32
		v14   int32
		v15   int32
		v16   int8
		v17   int8
		v18   int8
		v19   int32
		xLeft int2
		v21   int32
		a2    int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	v3 = a2
	if *memmap.PtrUint32(0x5D4594, 1313660) == 0 {
		*memmap.PtrUint32(0x5D4594, 1313660) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DrainManaOrb")))
		*memmap.PtrUint32(0x5D4594, 1313664) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("HealOrb")))
		*memmap.PtrUint32(0x5D4594, 1313668) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CharmOrb")))
		*memmap.PtrUint32(0x5D4594, 1313672) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("WhiteOrb")))
		*memmap.PtrUint32(0x5D4594, 1313676) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ManaBombOrb")))
		*memmap.PtrUint32(0x5D4594, 1313680) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("WhiteMoveOrb")))
		*memmap.PtrUint32(0x5D4594, 1313684) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BlueMoveOrb")))
	}
	v4 = int32(*(*uint32)(unsafe.Add(a2, 108)))
	if uint32(v4) == *memmap.PtrUint32(0x5D4594, 1313660) || uint32(v4) == *memmap.PtrUint32(0x5D4594, 1313684) {
		v5 = int32(dword_5d4594_1313540)
		v21 = int32(dword_5d4594_1313536)
		v19 = v5
		goto LABEL_14
	}
	if uint32(v4) == *memmap.PtrUint32(0x5D4594, 1313668) {
		v5 = int32(*memmap.PtrUint32(0x5D4594, 1313584))
		v21 = int32(*memmap.PtrUint32(0x5D4594, 1313580))
		v19 = v5
		goto LABEL_14
	}
	if uint32(v4) == *memmap.PtrUint32(0x5D4594, 1313672) || uint32(v4) == *memmap.PtrUint32(0x5D4594, 1313676) || uint32(v4) == *memmap.PtrUint32(0x5D4594, 1313680) {
		v21 = int32(*memmap.PtrUint32(0x5D4594, 1313588))
		v19 = int32(*memmap.PtrUint32(0x5D4594, 1313592))
	} else {
		v21 = int32(*memmap.PtrUint32(0x5D4594, 1313528))
		v19 = int32(dword_5d4594_1313532)
	}
LABEL_14:
	if a3 != 0 {
		v6 = int32(uint32(*(*uint16)(unsafe.Add(v3, 432))) - *(*uint32)(unsafe.Add(v3, 12)))
		v7 = int32(uint32(*(*uint16)(unsafe.Add(v3, 434))) - *(*uint32)(unsafe.Add(v3, 16)))
		v8 = int32(sub_48C6B0(v6, v7))
		if v8+1 <= 10 {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable((*client.Drawable)(v3))
			return 0
		}
		nox_xxx_updateSpritePosition_49AA90((*client.Drawable)(v3), int32(*(*uint32)(unsafe.Add(v3, 12))+uint32(v6*int32(*(*uint8)(unsafe.Add(v3, 443)))/(v8+1))), int32(*(*uint32)(unsafe.Add(v3, 16))+uint32(v7*int32(*(*uint8)(unsafe.Add(v3, 443)))/(v8+1))))
	}
	v10 = *a1
	v11 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	v12 = int32(*(*uint32)(unsafe.Add(v3, 16)) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))))
	xLeft.field_0 = int32(*(*uint32)(unsafe.Add(v3, 12)) + uint32(*a1) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))))
	xLeft.field_4 = v12 + v11 - 22
	v13 = int32(*(*uint8)(unsafe.Add(v3, 444)))
	if xLeft.field_0-v13 < v10 {
		return 1
	}
	if xLeft.field_4-v13 < v11 {
		return 1
	}
	if v13+xLeft.field_0 >= *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) {
		return 1
	}
	if v13+xLeft.field_4 >= *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) {
		return 1
	}
	sub_4B6720(&xLeft, v21, v13, 5)
	nox_client_drawSetColor_434460(v19)
	nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, int32(*(*uint8)(unsafe.Add(v3, 444)))>>1)
	v14 = int32(*(*uint32)(unsafe.Add(v3, 32)) - *(*uint32)(unsafe.Add(v3, 12)))
	v15 = int32(*(*uint32)(unsafe.Add(v3, 36)) - *(*uint32)(unsafe.Add(v3, 16)))
	nox_client_drawSetColor_434460(v19)
	nox_client_drawAddPoint_49F500(xLeft.field_0, xLeft.field_4)
	nox_xxx_rasterPointRel_49F570(v14, v15)
	nox_client_drawLineFromPoints_49E4B0()
	v16 = int8(*(*uint8)(unsafe.Add(v3, 445)))
	if int32(v16) == 0 {
		return 1
	}
	v17 = int8(int32(*(*uint8)(unsafe.Add(v3, 446))) - 1)
	*(*uint8)(unsafe.Add(v3, 446)) = uint8(v17)
	if int32(v17) != 0 {
		return 1
	}
	*(*uint8)(unsafe.Add(v3, 446)) = uint8(v16)
	v18 = int8(int32(*(*uint8)(unsafe.Add(v3, 444))) - 1)
	*(*uint8)(unsafe.Add(v3, 444)) = uint8(v18)
	if int32(v18) != 0 {
		return 1
	}
	nox_xxx_spriteDeleteStatic_45A4E0_drawable((*client.Drawable)(v3))
	return 0
}
func nox_xxx_netHandleSummonPacket_4B7C40(a1 int16, a2 *uint16, a3 uint16, a4 uint8, a5 int16) *uint32 {
	var (
		v5     int32
		result *uint32
		v7     *uint32
		v8     *uint32
		v9     int32
		v10    int32
		v11    int32
	)
	v10 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(uint16(0))*1)))
	v9 = int32(*a2)
	v5 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SummonEffect"))
	result = (*uint32)(nox_xxx_spriteLoadAdd_45A360_drawable(v5, v9, v10).C())
	v7 = result
	if result != nil {
		result = (*uint32)(nox_new_drawable_for_thing(int32(a3)).C())
		v8 = result
		if result != nil {
			*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3)) = uint32(*a2)
			*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4)) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(uint16(0))*1)))
			*(*uint8)(unsafe.Add(unsafe.Pointer(result), 297)) = uint8(int8(nox_xxx_math_509EA0(int32(a4))))
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v11), unsafe.Sizeof(uint16(0))*1)) = uint16(a1)
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v11), unsafe.Sizeof(uint16(0))*0)) = uint16(a5)
			*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*69)) = 8
			*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*108)) = uint32(uintptr(unsafe.Pointer(v8)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*109)) = uint32(v11)
			result = (*uint32)(unsafe.Pointer(uintptr(gameFrame())))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*79)) = gameFrame()
		}
	}
	return result
}
func sub_4B7EE0(a1 int16) {
	if *memmap.PtrUint32(0x5D4594, 1313744) == 0 {
		*memmap.PtrUint32(0x5D4594, 1313744) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SummonEffect")))
	}
	if dword_5d4594_1313740 == 0 {
		dword_5d4594_1313740 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BlueSpark")))
	}
	var v2 int32 = int32(uintptr(unsafe.Pointer(sub_45A060())))
	if v2 == 0 {
		return
	}
	for *(*uint32)(unsafe.Add(v2, 108)) != *memmap.PtrUint32(0x5D4594, 1313744) || int32(*(*uint16)(unsafe.Add(v2, 438))) != int32(a1) {
		v2 = int32(uintptr(unsafe.Pointer(nox_drawable_next_45A070((*client.Drawable)(v2)))))
		if v2 == 0 {
			return
		}
	}
	nox_xxx_makePointFxCli_499610(dword_5d4594_1313740, 50, 1000, 30, int32(*(*uint32)(unsafe.Add(v2, 12))), int32(*(*uint32)(unsafe.Add(v2, 16))))
	nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(*(**uint64)(unsafe.Add(v2, 432)))))
	nox_xxx_spriteDeleteStatic_45A4E0_drawable((*client.Drawable)(v2))
}
func nox_xxx_spriteShieldLoad_4B7F90() int32 {
	var result int32
	*memmap.PtrUint32(0x5D4594, 1313748) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldNW")))
	*memmap.PtrUint32(0x5D4594, 1313752) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldN")))
	*memmap.PtrUint32(0x5D4594, 1313756) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldNE")))
	*memmap.PtrUint32(0x5D4594, 1313760) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldW")))
	*memmap.PtrUint32(0x5D4594, 1313768) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldE")))
	*memmap.PtrUint32(0x5D4594, 1313772) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldSW")))
	*memmap.PtrUint32(0x5D4594, 1313776) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldS")))
	result = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldSE"))
	*memmap.PtrUint32(0x5D4594, 1313780) = uint32(result)
	*memmap.PtrUint32(0x5D4594, 1313764) = 0
	*memmap.PtrUint32(0x5D4594, 1313784) = 1
	return result
}
func nox_xxx_fxShield_4B8090(a1 uint32, a2 int32) *uint32 {
	var (
		v2     int32
		v3     int32
		result *uint32
		v5     int32
		v6     *uint32
		v7     int4
	)
	if *memmap.PtrUint32(0x5D4594, 1313784) == 0 {
		nox_xxx_spriteShieldLoad_4B7F90()
	}
	v2 = a2
	switch a2 {
	case 0:
		nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldNW"))
	case 1:
		nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ShpericalShieldN"))
	case 2:
		nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldNW"))
	case 3:
		nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldW"))
	case 5:
		nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldE"))
	case 6:
		nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldSW"))
	case 7:
		nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldS"))
	case 8:
		nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SphericalShieldSE"))
	default:
	}
	if nox_xxx_netTestHighBit_578B70(a1) != 0 {
		v3 = nox_xxx_netClearHighBit_578B30(int16(uint16(a1)))
		result = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(v3).C())
	} else {
		v5 = nox_xxx_netClearHighBit_578B30(int16(uint16(a1)))
		result = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(v5).C())
	}
	v6 = result
	if result != nil {
		v7.field_0 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3)) - 10)
		v7.field_4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4)) - 10)
		v7.field_8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3)) + 10)
		v7.field_C = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4)) + 10)
		dword_5d4594_1313788 = 0
		nox_xxx_forEachSprite_49AB00(&v7, nox_xxx_spriteScanForShield_4B81E0, unsafe.Pointer(&a1))
		result = dword_5d4594_1313788
		if dword_5d4594_1313788 != 1 {
			result = (*uint32)(nox_xxx_spriteLoadAdd_45A360_drawable(int32(*memmap.PtrUint32(0x5D4594, uintptr(v2*4)+1313748)), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*3))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*4))+3)).C())
			if result != nil {
				*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*108)) = a1
			}
		}
	}
	return result
}
func nox_xxx_spriteScanForShield_4B81E0(it *client.Drawable, a2 unsafe.Pointer) {
	a1 := int32(uintptr(it.C()))
	var v2 *uint8
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1313748))
	for {
		if *(*uint32)(unsafe.Add(a1, 108)) == *(*uint32)(unsafe.Pointer(v2)) && *(*uint32)(unsafe.Add(a1, 432)) == *(*uint32)(a2) {
			dword_5d4594_1313788 = 1
		}
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 4))
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1313784))) {
			break
		}
	}
}
func nox_xxx_gameDeleteSpiningCrownSkull_4B8220() int32 {
	var result int32
	if dword_5d4594_1313792 != 0 {
		nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(dword_5d4594_1313792)))
	}
	dword_5d4594_1313792 = 0
	if dword_5d4594_1313796 != nil {
		nox_xxx_spriteDelete_45A4B0((*client.Drawable)(dword_5d4594_1313796))
	}
	result = int32(uintptr(dword_5d4594_1313800))
	if dword_5d4594_1313800 != nil {
		result = nox_xxx_spriteDelete_45A4B0((*client.Drawable)(dword_5d4594_1313800))
	}
	dword_5d4594_1313796 = nil
	dword_5d4594_1313800 = nil
	return result
}
func sub_4B8960(a1 *int32, dr *client.Drawable, a3 int32, a4 *uint32, a5 int32, a6 int32) {
	var (
		a2  int32 = int32(uintptr(unsafe.Pointer(dr)))
		v6  *uint8
		v7  int32
		v8  int32
		v9  int8
		v10 int32
		v11 int32
		i   int32
		v13 int32
		v14 int32
		v15 int32
		v16 uint8
		v17 int32
		j   int32
		v19 int32
		v20 int32
		k   int32
		v22 int32
		v23 int32
		v24 int32
		l   int32
		v27 int32
		v28 int32
		v29 *int32
		v30 int32
		v31 int32
	)
	v6 = (*uint8)(unsafe.Pointer(dr))
	v28 = bool2int32(nox_client_drawable_testBuff_4356C0(dr, 23))
	v7 = 0
	v30 = 0
	v31 = 0
	if int32(uint8(gameFrame()))&1 != 0 {
		v27 = int32(nox_color_white_2523948)
	} else {
		v27 = int32(nox_color_blue_2650684)
	}
	v8 = a3
	if a3&2 != 0 {
		v9 = int8(*(*uint8)(unsafe.Add(a2, 297)))
		if int32(v9) == 6 || int32(v9) == 7 || int32(v9) == 8 {
			v10 = int32(*(*uint32)(unsafe.Add(a2, 276)))
			if v10 != 6 && v10 != 35 && v10 != 39 && v10 != 40 {
				for ((1 << v7) & 2) == 0 {
					if func() int32 {
						p := &v7
						*p++
						return *p
					}() >= 26 {
						goto LABEL_22
					}
				}
				v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a5+v7*4)), 52)))
				if v11 != 0 {
					if v28 != 0 {
						for i = 1; i < 7; i++ {
							nox_draw_setMaterial_4341D0(i, v27)
						}
						v6 = (*uint8)(unsafe.Pointer(dr))
					} else {
						sub_4B8CA0(a4, (*byte)(unsafe.Pointer(uintptr(2))))
					}
					nox_xxx_drawObject_4C4770_draw(a1, (*client.Drawable)(unsafe.Pointer(v6)), int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v11+int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 297)))*4)), 4)) + uint32(a6*4))))))
					v8 = a3
					v30 = 1
				}
			}
		}
	}
LABEL_22:
	v13 = 0
	v29 = (*int32)(unsafe.Add(a5, 52))
	for {
		v14 = 1 << v13
		if ((1 << v13) & 2) == 0 {
			v15 = int32(uint32(v14) & 0x3000000)
			if (uint32(v14)&0x3000000) == 0 || (func() bool {
				v16 = *(*uint8)(unsafe.Add(unsafe.Pointer(v6), 297))
				return int32(v16) != 3
			}()) && int32(v16) != 0 && int32(v16) != 6 && int32(v16) != 7 {
				if v14&v8 != 0 && ((v14&0xC00) == 0 || (v8&0x4000) == 0) {
					v17 = *v29
					if *v29 != 0 {
						if v28 != 0 {
							for j = 1; j < 7; j++ {
								nox_draw_setMaterial_4341D0(j, v27)
							}
							v6 = (*uint8)(unsafe.Pointer(dr))
						} else {
							sub_4B8CA0(a4, (*byte)(unsafe.Pointer(uintptr(1<<v13))))
						}
						nox_xxx_drawObject_4C4770_draw(a1, (*client.Drawable)(unsafe.Pointer(v6)), int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v17+int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 297)))*4)), 4)) + uint32(a6*4))))))
						if v15 != 0 {
							v31 = 1
						}
						v8 = a3
					}
				}
			}
		}
		v13++
		v29 = (*int32)(unsafe.Add(unsafe.Pointer(v29), 4*1))
		if v13 >= 26 {
			break
		}
	}
	if a3&2 != 0 && v30 == 0 {
		v19 = 0
		for ((1 << v19) & 2) == 0 {
			if func() int32 {
				p := &v19
				*p++
				return *p
			}() >= 26 {
				goto LABEL_55
			}
		}
		v20 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a5+v19*4)), 52)))
		if v20 != 0 {
			if v28 != 0 {
				for k = 1; k < 7; k++ {
					nox_draw_setMaterial_4341D0(k, v27)
				}
				v6 = (*uint8)(unsafe.Pointer(dr))
			} else {
				sub_4B8CA0(a4, (*byte)(unsafe.Pointer(uintptr(2))))
			}
			nox_xxx_drawObject_4C4770_draw(a1, (*client.Drawable)(unsafe.Pointer(v6)), int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v20+int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 297)))*4)), 4)) + uint32(a6*4))))))
			v8 = a3
		}
	}
LABEL_55:
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v22), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v31))
	if v31 == 0 && uint32(v8)&0x3000000 != 0 {
		v23 = 0
		if (uint32(v8) & 0x1000000) != 0 {
			v22 = 0x1000000
		} else {
			v22 = 0x2000000
		}
		for ((1 << v23) & v22) == 0 {
			if func() int32 {
				p := &v23
				*p++
				return *p
			}() >= 26 {
				return
			}
		}
		v24 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a5+v23*4)), 52)))
		if v24 != 0 {
			if v28 != 0 {
				for l = 1; l < 7; l++ {
					nox_draw_setMaterial_4341D0(l, v27)
				}
				v6 = (*uint8)(unsafe.Pointer(dr))
			} else {
				sub_4B8CA0(a4, (*byte)(v22))
			}
			nox_xxx_drawObject_4C4770_draw(a1, (*client.Drawable)(unsafe.Pointer(v6)), int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v24+int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 297)))*4)), 4)) + uint32(a6*4))))))
		}
	}
}
func sub_4B8CA0(a1 *uint32, a2 *byte) *uint32 {
	var (
		result *uint32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     *uint32
		v8     int32
		v9     *uint8
		v10    *uint32
		v11    int32
		v12    *int32
		v13    int32
		v14    **uint32
		v15    int32
	)
	result = a1
	v3 = 0
	for (*byte)(unsafe.Pointer(uintptr(*result))) != a2 {
		v3++
		result = (*uint32)(unsafe.Add(unsafe.Pointer(result), 4*6))
		if v3 >= 26 {
			return result
		}
	}
	v4 = sub_415CD0(int32(uintptr(unsafe.Pointer(a2))))
	result = (*uint32)(nox_xxx_equipClothFindDefByTT_413270(v4))
	v7 = result
	if result != nil {
		v8 = 1
		v9 = (*uint8)(unsafe.Add(unsafe.Pointer(result), 4*4))
		for {
			*(*uint8)(unsafe.Pointer(&result)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v9), 1))
			*(*uint8)(unsafe.Pointer(&v6)) = *v9
			*(*uint8)(unsafe.Pointer(&v5)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v9), -1))
			nox_draw_setMaterial_4340A0(func() int32 {
				p := &v8
				x := *p
				*p++
				return x
			}(), v5, v6, int32(uintptr(unsafe.Pointer(result))))
			v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 3))
			if v8 >= 7 {
				break
			}
		}
		v10 = a1
		v11 = v3 * 3
		v12 = (*int32)(unsafe.Add(unsafe.Pointer(v7), 4*9))
		v13 = 4
		v14 = (**uint32)(unsafe.Add(unsafe.Pointer(a1), 4*uintptr(v11*2+1)))
		for {
			result = *v14
			if *v14 != nil {
				*(*uint8)(unsafe.Pointer(&v5)) = *(*uint8)(unsafe.Add(unsafe.Pointer(result), 26))
				*(*uint8)(unsafe.Pointer(&v10)) = *(*uint8)(unsafe.Add(unsafe.Pointer(result), 25))
				v15 = v5
				*(*uint8)(unsafe.Pointer(&v5)) = *(*uint8)(unsafe.Add(unsafe.Pointer(result), 24))
				nox_draw_setMaterial_4340A0(*v12, v5, int32(uintptr(unsafe.Pointer(v10))), v15)
			}
			v14 = (**uint32)(unsafe.Add(unsafe.Pointer(v14), unsafe.Sizeof((*uint32)(nil))*1))
			v12 = (*int32)(unsafe.Add(unsafe.Pointer(v12), 4*1))
			v13--
			if v13 == 0 {
				break
			}
		}
	}
	return result
}
func sub_4B8D40(a1 *int32, dr *client.Drawable, a3 int32, a4 *uint32, a5 int32, a6 int32) {
	var (
		v6  *uint8
		v7  int32
		v8  *int32
		v10 int32
		i   int32
		v13 int32
		v14 int32
	)
	v6 = (*uint8)(unsafe.Pointer(dr))
	v14 = bool2int32(nox_client_drawable_testBuff_4356C0(dr, 25))
	if int32(uint8(gameFrame()))&1 != 0 {
		v13 = int32(nox_color_white_2523948)
	} else {
		v13 = int32(nox_color_blue_2650684)
	}
	v7 = 1
	v8 = (*int32)(unsafe.Add(a5, 160))
	for {
		if (1<<v7)&a3 != 0 {
			v10 = *v8
			if *v8 != 0 {
				if v14 != 0 {
					for i = 1; i < 7; i++ {
						nox_draw_setMaterial_4341D0(i, v13)
					}
					v6 = (*uint8)(unsafe.Pointer(dr))
				} else {
					sub_4B8E10(a4, (*byte)(unsafe.Pointer(uintptr(1<<v7))))
				}
				nox_xxx_drawObject_4C4770_draw(a1, (*client.Drawable)(unsafe.Pointer(v6)), int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v10+int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 297)))*4)), 4)) + uint32(a6*4))))))
			}
		}
		v7++
		v8 = (*int32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
		if v7 >= 27 {
			break
		}
	}
}
func sub_4B8E10(a1 *uint32, a2 *byte) *uint32 {
	var (
		result *uint32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     *uint32
		v8     int32
		v9     *uint8
		v10    *uint32
		v11    int32
		v12    *int32
		v13    int32
		v14    **uint32
		v15    int32
	)
	result = a1
	v3 = 0
	for (*byte)(unsafe.Pointer(uintptr(*result))) != a2 {
		v3++
		result = (*uint32)(unsafe.Add(unsafe.Pointer(result), 4*6))
		if v3 >= 27 {
			return result
		}
	}
	v4 = sub_415840(int32(uintptr(unsafe.Pointer(a2))))
	result = (*uint32)(nox_xxx_getProjectileClassById_413250(v4))
	v7 = result
	if result != nil {
		v8 = 1
		v9 = (*uint8)(unsafe.Add(unsafe.Pointer(result), 4*4))
		for {
			*(*uint8)(unsafe.Pointer(&result)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v9), 1))
			*(*uint8)(unsafe.Pointer(&v6)) = *v9
			*(*uint8)(unsafe.Pointer(&v5)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v9), -1))
			nox_draw_setMaterial_4340A0(func() int32 {
				p := &v8
				x := *p
				*p++
				return x
			}(), v5, v6, int32(uintptr(unsafe.Pointer(result))))
			v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 3))
			if v8 >= 7 {
				break
			}
		}
		v10 = a1
		v11 = v3 * 3
		v12 = (*int32)(unsafe.Add(unsafe.Pointer(v7), 4*9))
		v13 = 4
		v14 = (**uint32)(unsafe.Add(unsafe.Pointer(a1), 4*uintptr(v11*2+1)))
		for {
			result = *v14
			if *v14 != nil {
				*(*uint8)(unsafe.Pointer(&v5)) = *(*uint8)(unsafe.Add(unsafe.Pointer(result), 26))
				*(*uint8)(unsafe.Pointer(&v10)) = *(*uint8)(unsafe.Add(unsafe.Pointer(result), 25))
				v15 = v5
				*(*uint8)(unsafe.Pointer(&v5)) = *(*uint8)(unsafe.Add(unsafe.Pointer(result), 24))
				nox_draw_setMaterial_4340A0(*v12, v5, int32(uintptr(unsafe.Pointer(v10))), v15)
			}
			v14 = (**uint32)(unsafe.Add(unsafe.Pointer(v14), unsafe.Sizeof((*uint32)(nil))*1))
			v12 = (*int32)(unsafe.Add(unsafe.Pointer(v12), 4*1))
			v13--
			if v13 == 0 {
				break
			}
		}
	}
	return result
}
func nox_xxx_drawOtherPlayerHP_4B8EB0(a1 *uint32, dr *client.Drawable, a3 uint16, a4 int8) {
	var (
		a2 int32 = int32(uintptr(unsafe.Pointer(dr)))
		v4 int32
		v5 int32
		v6 int32
		v7 float32
	)
	if a2 != 0 {
		v4 = int32(*a1 + *(*uint32)(unsafe.Add(a2, 12)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		v7 = *(*float32)(unsafe.Add(a2, 48)) + *(*float32)(unsafe.Add(a2, 48))
		v5 = int32(v7) + v4
		v6 = int32(*(*uint32)(unsafe.Add(a2, 16)) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - uint32(*(*int16)(unsafe.Add(a2, 104))) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) - 48)
		nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
		nox_client_drawRectFilledOpaque_49CE30(v5, v6, 2, 48)
		if int32(a4) != 0 {
			nox_client_drawSetColor_434460(*memmap.PtrInt32(0x8531A0, 2572))
		} else {
			nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 940))
		}
		nox_client_drawRectFilledOpaque_49CE30(v5, v6-int32(a3)*48/100+48, 2, int32(a3)*48/100)
		if int32(a4) != 0 {
			nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 984))
		} else {
			nox_client_drawSetColor_434460(int32(nox_color_violet_2598268))
		}
		nox_client_drawBorderLines_49CC70(v5-1, v6-1, 4, 50)
	}
}
func sub_4B8FA0(dr *client.Drawable, a2 *int32, a3 *int32) int32 {
	var (
		v3 int32
		v4 int32
		v5 bool
		v6 int32
		v8 int32
		v9 int32
	)
	v3 = int32(uintptr(dr.Field_76))
	if dr.Field_69 != 0 || sub_48D830(dr) == 0 {
		if dr.Field_69 != 4 {
			v4 = int32(dr.Field_69)
		} else if !nox_client_drawable_testBuff_4356C0(dr, 31) {
			v4 = int32(dr.Field_69)
		} else {
			v4 = 53
		}
	} else {
		v4 = 19
	}
	v5 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v3+v4*264)), 44))) == 0
	v6 = v3 + v4*264 + 4
	if v5 {
		return 0
	}
	v8 = sub_4BC5D0(dr, v6)
	if v8 < 0 {
		return 0
	}
	v9 = int32(*(*int16)(unsafe.Add(v6, 40)))
	if v8 >= v9 {
		v8 = v9 - 1
	}
	if a2 != nil {
		*a2 = v6
	}
	if a3 != nil {
		*a3 = v8
	}
	return int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v6, 48))+uint32(int32(dr.Field_74_2)*4))), 4)) + uint32(v8*4)))))
}
