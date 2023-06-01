package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

var dword_5d4594_1321236 *nox_window = nil
var dword_5d4594_1321240 *nox_window = nil
var dword_5d4594_1321248 *nox_window = nil
var dword_5d4594_1321244 *nox_window = nil

func sub_4C3620() *byte {
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
	v0 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1321240))) + 32))))
	sub_42CD90()
	for i = 0; i < int32(*(*int16)(unsafe.Pointer(uintptr(v0 + 44)))); i++ {
		v2 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321240))))), 16406, i, 0))))
		v3 = int32(uintptr(unsafe.Pointer(nox_xxx_bindevent_bindNameByTitle_42EA40(v2))))
		v4 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321244))))), 16406, i, 0))))
		v5 = nox_xxx_keybind_nameByTitle_42E960(v4)
		v6 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321248))))), 16406, i, 0))))
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
	v8 = nox_strman_loadString_40F1D0(internCStr("bindevent:ToggleQuitMenu"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GuiInput.c"), 191)
	v9 = int32(uintptr(unsafe.Pointer(nox_xxx_bindevent_bindNameByTitle_42EA40(v8))))
	v10 = nox_strman_loadString_40F1D0(internCStr("keybind:Esc"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GuiInput.c"), 192)
	result = nox_xxx_keybind_nameByTitle_42E960(v10)
	if result != nil {
		nox_sprintf(&v12[0], internCStr("%s = %s"), result, v9)
		result = (*byte)(unsafe.Pointer(uintptr(nox_client_parseConfigHotkeysLine_42CF50(&v12[0]))))
	}
	return result
}
func sub_4C3760() int32 {
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
		v10    *uint32
		v11    *wchar2_t
	)
	_ = v11
	result = int32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("InputCfg.wnd"), ccall.FuncAddr(sub_4C3A90)))))
	dword_5d4594_1321228 = uint32(result)
	if result != 0 {
		dword_5d4594_1321236 = nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(uintptr(result))), 910)
		dword_5d4594_1321240 = nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), 911)
		dword_5d4594_1321244 = nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), 912)
		dword_5d4594_1321248 = nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), 913)
		result = int32(uintptr(unsafe.Pointer(dword_5d4594_1321236)))
		if dword_5d4594_1321236 != nil {
			v1 = *(***uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1321236))) + 32)))
			**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*7)) = 921
			**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*8)) = 922
			**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*9)) = 920
			nox_xxx_wndSetProc_46B2C0(*(*int32)(unsafe.Pointer(&dword_5d4594_1321236)), ccall.FuncAddr(sub_4C3CD0))
			sub_46B120((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321240)))), (*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321236))))))
			sub_46B120((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321244)))), (*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321236))))))
			sub_46B120((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321248)))), (*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321236))))))
			nox_xxx_wndSetWindowProc_46B300(*(*int32)(unsafe.Pointer(&dword_5d4594_1321244)), ccall.FuncAddr(sub_4C3A60))
			nox_xxx_wndSetWindowProc_46B300(*(*int32)(unsafe.Pointer(&dword_5d4594_1321248)), ccall.FuncAddr(sub_4C3A60))
			v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), 921)))
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321240))))), 16408, int32(uintptr(unsafe.Pointer(v2))), 0)
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321244))))), 16408, int32(uintptr(unsafe.Pointer(v2))), 0)
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321248))))), 16408, int32(uintptr(unsafe.Pointer(v2))), 0)
			v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), 922)))
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321240))))), 16409, int32(uintptr(unsafe.Pointer(v3))), 0)
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321244))))), 16409, int32(uintptr(unsafe.Pointer(v3))), 0)
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321248))))), 16409, int32(uintptr(unsafe.Pointer(v3))), 0)
			v4 = 971
			v5 = int32(sub_47DBC0()) + 971
			if v5 > 971 {
				for {
					v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), v4)))
					nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v6)))))), 1)
					v4++
					if v4 >= v5 {
						break
					}
				}
			}
			v7 = nox_client_mousePriKey_430AF0()
			v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), v7+971)))
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))), 16392, 1, 0)
			nox_window_setPos_46A9B0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), int32((uint32(nox_win_width)-*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1321228 + 8))))/2), 0)
			dword_5d4594_1321232 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), 980))))
			sub_46B120((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321232)))), nil)
			nox_xxx_wndSetProc_46B2C0(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232)), ccall.FuncAddr(sub_4C3A90))
			nox_xxx_wndSetWindowProc_46B300(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232)), ccall.FuncAddr(sub_4C3EB0))
			nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))), 1)
			nox_window_setPos_46A9B0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321232)))), int32((uint32(nox_win_width)-*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1321232 + 8))))/2), int32(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1321232 + 20)))))
			v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321232)))), 981)))
			sub_46AEE0(int32(uintptr(unsafe.Pointer(v9))), int32(uintptr(memmap.PtrOff(0x5D4594, 1321256))))
			v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), 932)))
			nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v10)))))), 1)
			nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321228))))), 1)
			result = 1
		}
	}
	return result
}
func sub_4C3CD0(a1 int32, a2 uint32, a3 int32, a4 int32) int32 {
	var (
		v5 int32
		v6 *wchar2_t
		v7 int32
		v8 int32
		v9 int32
	)
	if a2 > 0x4007 {
		if a2 == 16393 {
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 32))))
			nox_xxx_wndListboxProcPre_4A30D0((*nox_window)(unsafe.Pointer(uintptr(a1))), 0x4009, uint32(uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(uintptr(a3)))))), a4)
			v8 = sub_4A4800(v7)
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321240))))), 16412, v8, 0)
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321244))))), 16412, v8, 0)
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321248))))), 16412, v8, 0)
		} else if a2 == 16400 {
			v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a3 + 32))))
			if int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 48)))) >= 0 {
				dword_5d4594_1321252 = uint32(a3)
				v9 = nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321240))))), 16406, int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 48)))), 0)
				v6 = nox_strman_loadString_40F1D0(internCStr("InputCfg.wnd:PressKey"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GuiInput.c"), 436)
				nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1321256)), (*wchar2_t)(unsafe.Pointer(internCStr("%s\n'%s'"))), v6, v9)
				nox_xxx_wndShowModalMB_46A8C0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))))
				nox_xxx_windowFocus_46B500((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))))
				sub_46C690((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321232))))))
				return nox_xxx_wndListboxProcPre_4A30D0((*nox_window)(unsafe.Pointer(uintptr(a1))), 0x4010, uint32(uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(uintptr(a3)))))), a4)
			}
		}
	} else {
		if a2 != 16391 {
			if a2 == 23 {
				return 1
			}
			if a2 != 0x4000 {
				return nox_xxx_wndListboxProcPre_4A30D0((*nox_window)(unsafe.Pointer(uintptr(a1))), a2, uint32(uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(uintptr(a3)))))), a4)
			}
		}
		if unsafe.Pointer((*uint32)(unsafe.Pointer(uintptr(a3)))) == unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), 921)) || unsafe.Pointer((*uint32)(unsafe.Pointer(uintptr(a3)))) == unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1321228)))), 922)) {
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321240))))), int32(a2), a3, 0)
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321244))))), int32(a2), a3, 0)
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1321248))))), int32(a2), a3, 0)
			return nox_xxx_wndListboxProcPre_4A30D0((*nox_window)(unsafe.Pointer(uintptr(a1))), a2, uint32(uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(uintptr(a3)))))), a4)
		}
	}
	return nox_xxx_wndListboxProcPre_4A30D0((*nox_window)(unsafe.Pointer(uintptr(a1))), a2, uint32(uintptr(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(uintptr(a3)))))), a4)
}
