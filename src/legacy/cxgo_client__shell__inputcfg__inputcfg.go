package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_4CBD30() *byte {
	var (
		v0     int32
		i      int32
		v2     *wchar2_t
		v3     int32
		v4     *wchar2_t
		v5     *byte
		v6     *wchar2_t
		v7     *byte
		v8     *wchar2_t
		v9     int32
		v10    *wchar2_t
		result *byte
		v12    [256]byte
	)
	v0 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1522620))) + 32))))
	sub_42CD90()
	for i = 0; i < int32(*(*int16)(unsafe.Pointer(uintptr(v0 + 44)))); i++ {
		v2 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522620))))), 16406, uintptr(i), 0))))
		v3 = int32(uintptr(unsafe.Pointer(nox_xxx_bindevent_bindNameByTitle_42EA40(v2))))
		v4 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522624))))), 16406, uintptr(i), 0))))
		v5 = nox_xxx_keybind_nameByTitle_42E960(v4)
		v6 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522628))))), 16406, uintptr(i), 0))))
		v7 = nox_xxx_keybind_nameByTitle_42E960(v6)
		if v7 != nil {
			nox_sprintf(&v12[0], internCStr("%s = %s"), v7, v3)
			nox_client_parseConfigHotkeysLine_42CF50(&v12[0])
		}
		if v5 != nil {
			nox_sprintf(&v12[0], internCStr("%s = %s"), v5, v3)
			nox_client_parseConfigHotkeysLine_42CF50(&v12[0])
		}
	}
	v8 = nox_strman_loadString_40F1D0(internCStr("bindevent:ToggleQuitMenu"), nil, internCStr("C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c"), 192)
	v9 = int32(uintptr(unsafe.Pointer(nox_xxx_bindevent_bindNameByTitle_42EA40(v8))))
	v10 = nox_strman_loadString_40F1D0(internCStr("keybind:Esc"), nil, internCStr("C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c"), 193)
	result = nox_xxx_keybind_nameByTitle_42E960(v10)
	if result != nil {
		nox_sprintf(&v12[0], internCStr("%s = %s"), result, v9)
		result = (*byte)(unsafe.Pointer(uintptr(nox_client_parseConfigHotkeysLine_42CF50(&v12[0]))))
	}
	return result
}
func sub_4CBF60(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		a1 = int32(uintptr(win.C()))
		v5 int32
		v6 *wchar2_t
		v8 int32
		v9 int32
	)
	if a2 > 0x4007 {
		if a2 == 16393 {
			v7 := win.WidgetData
			nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(unsafe.Pointer(uintptr(a1))), 0x4009, uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(uintptr(a3))))), a4)
			v8 = sub_4A4800(v7)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522620))))), 16412, uintptr(v8), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522624))))), 16412, uintptr(v8), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522628))))), 16412, uintptr(v8), 0)
		} else if a2 == 16400 {
			v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a3 + 32))))
			if int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 48)))) >= 0 {
				dword_5d4594_1522632 = uint32(a3)
				v9 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522620))))), 16406, uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 48)))), 0))
				v6 = nox_strman_loadString_40F1D0(internCStr("InputCfg.wnd:PressKey"), nil, internCStr("C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c"), 424)
				nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1522636)), (*wchar2_t)(unsafe.Pointer(internCStr("%s\n'%s'"))), v6, v9)
				nox_xxx_wndShowModalMB_46A8C0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))))
				nox_xxx_windowFocus_46B500((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))))
				sub_46C690((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522612))))))
				return nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(unsafe.Pointer(uintptr(a1))), 0x4010, uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(uintptr(a3))))), a4)
			}
		}
	} else {
		if a2 != 16391 {
			if a2 == 23 {
				return 1
			}
			if a2 != 0x4000 {
				return nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(unsafe.Pointer(uintptr(a1))), a2, uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(uintptr(a3))))), a4)
			}
		}
		if unsafe.Pointer((*uint32)(unsafe.Pointer(uintptr(a3)))) == unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), 921)) || unsafe.Pointer((*uint32)(unsafe.Pointer(uintptr(a3)))) == unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1522604)))), 922)) {
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522620))))), uintptr(a2), uintptr(a3), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522624))))), uintptr(a2), uintptr(a3), 0)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1522628))))), uintptr(a2), uintptr(a3), 0)
			return nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(unsafe.Pointer(uintptr(a1))), a2, uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(uintptr(a3))))), a4)
		}
	}
	return nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(unsafe.Pointer(uintptr(a1))), a2, uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(uintptr(a3))))), a4)
}
