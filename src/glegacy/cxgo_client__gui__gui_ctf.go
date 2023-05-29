package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"unsafe"
)

func sub_455C30() int32 {
	var (
		result int32
		v1     int32
		v2     *wchar2_t
		v3     *wchar2_t
	)
	if dword_5d4594_1045604 != 0 {
		return 1
	}
	result = int32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("GUI_CTF.wnd"), nil))))
	dword_5d4594_1045604 = uint32(result)
	if result != 0 {
		v1 = 8811
		for {
			v2 = (*wchar2_t)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(uintptr(result))), v1)))
			nox_window_set_all_funcs((*nox_window)(unsafe.Pointer(v2)), nil, func(arg1 *nox_window, arg2 unsafe.Pointer) int32 {
				return sub_455CD0((*uint8)(unsafe.Pointer(arg1)), (*uint32)(arg2))
			}, nil)
			v3 = nox_strman_loadString_40F1D0(internCStr("FlagHomeTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c"), 201)
			nox_xxx_wndWddSetTooltip_46B000((*nox_window_data)(unsafe.Pointer((*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(wchar2_t(0))*18)))), v3)
			if func() int32 {
				p := &v1
				*p++
				return *p
			}() > 8826 {
				break
			}
			result = int32(dword_5d4594_1045604)
		}
		sub_455A00(0)
		*memmap.PtrUint32(0x5D4594, 1045632) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("FlagTeamBorder")))))
		result = 1
	}
	return result
}
func sub_455D80(a1 uint8, a2 int8) {
	var (
		result *wchar2_t
		v3     *wchar2_t
		v4     *wchar2_t
	)
	*memmap.PtrUint8(0x5D4594, uint32(a1)+1045611) = uint8(a2)
	result = (*wchar2_t)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045604)))), int32(a1)+8810)))
	v3 = result
	if result != nil {
		if *(*wchar2_t)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(wchar2_t(0))*2))&0x20 != 0 {
			if int32(a2) != 0 {
				if int32(a2) == 1 {
					v4 = nox_strman_loadString_40F1D0(internCStr("YourFlagCarriedTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c"), 234)
				} else {
					if int32(a2) != 2 {
						return
					}
					v4 = nox_strman_loadString_40F1D0(internCStr("FlagAwayTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c"), 238)
				}
			} else {
				v4 = nox_strman_loadString_40F1D0(internCStr("FlagHomeTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c"), 242)
			}
		} else if int32(a2) != 0 {
			if int32(a2) == 1 {
				v4 = nox_strman_loadString_40F1D0(internCStr("TheirFlagCarriedTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c"), 252)
			} else {
				if int32(a2) != 2 {
					return
				}
				v4 = nox_strman_loadString_40F1D0(internCStr("FlagAwayTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c"), 256)
			}
		} else {
			v4 = nox_strman_loadString_40F1D0(internCStr("FlagHomeTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c"), 260)
		}
		nox_xxx_wndWddSetTooltip_46B000((*nox_window_data)(unsafe.Pointer((*wchar2_t)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(wchar2_t(0))*18)))), v4)
	}
}
