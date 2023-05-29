package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_cliShowHelpGui_49C560() *uint32 {
	var (
		v0     int32
		result *uint32
		v2     *uint32
		v3     *wchar2_t
		v4     *wchar2_t
		v5     *wchar2_t
		v6     *byte
		v7     *byte
		v8     *byte
	)
	v0 = nox_strman_get_lang_code()
	if nox_xxx_guiFontHeightMB_43F320(nil) > 10 {
		v0 = 2
	}
	result = (*uint32)(unsafe.Pointer(nox_new_window_from_file(*(**byte)(memmap.PtrOff(0x587000, uint32(v0*4)+164512)), unsafe.Pointer(funAddr(nox_xxx_wnd_49C760)))))
	dword_5d4594_1305680 = uint32(uintptr(unsafe.Pointer(result)))
	if result != nil {
		sub_46B120((*nox_window)(unsafe.Pointer(result)), nil)
		nox_xxx_wndShowModalMB_46A8C0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1305680))))))
		sub_46C690((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1305680))))))
		nox_xxx_windowFocus_46B500((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1305680))))))
		nox_window_setPos_46A9B0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1305680)))), (nox_win_width-*(*int32)(unsafe.Pointer(uintptr(dword_5d4594_1305680 + 8))))/2, (nox_win_height-*(*int32)(unsafe.Pointer(uintptr(dword_5d4594_1305680 + 12))))/2)
		if nox_common_gameFlags_check_40A5C0(1) {
			v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1305680)))), 4102)))
			v6 = (*byte)(unsafe.Pointer(sub_42E8E0(45, 1)))
			v3 = nox_strman_loadString_40F1D0(internCStr("Sanchlp.wnd:Help"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\chathelp.c"), 85)
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304656)), v3, v6)
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304656)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			v7 = (*byte)(unsafe.Pointer(sub_42E8E0(8, 1)))
			v4 = nox_strman_loadString_40F1D0(internCStr("cdecode.c:KeyToChat"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\chathelp.c"), 87)
		} else {
			v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1305680)))), 4102)))
			v8 = (*byte)(unsafe.Pointer(sub_42E8E0(45, 1)))
			v5 = nox_strman_loadString_40F1D0(internCStr("Sanchlp.wnd:ClientHelp"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\chathelp.c"), 94)
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304656)), v5, v8)
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304656)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			v7 = (*byte)(unsafe.Pointer(sub_42E8E0(8, 1)))
			v4 = nox_strman_loadString_40F1D0(internCStr("cdecode.c:KeyToChat"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\chathelp.c"), 96)
		}
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304400)), v4, v7)
		nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304656)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1304400)))
		nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), 16385, int32(uintptr(memmap.PtrOff(0x5D4594, 1304656))), 0)
		if nox_common_gameFlags_check_40A5C0(1) {
			if sub_459DA0() == 0 {
				nox_xxx_guiServerOptsLoad_457500()
			}
			sub_459D80(1)
		}
		if nox_common_gameFlags_check_40A5C0(4096) || (func() *uint32 {
			result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_isQuest_4D6F50())))
			return result
		}()) != nil {
			result = (*uint32)(unsafe.Pointer(uintptr(sub_49C7A0())))
		}
	}
	return result
}
