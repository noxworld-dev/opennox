package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var dword_5d4594_1321236 *gui.Window = nil
var dword_5d4594_1321240 *gui.Window = nil
var dword_5d4594_1321248 *gui.Window = nil
var dword_5d4594_1321244 *gui.Window = nil

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
	v0 = int32(dword_5d4594_1321240.WidgetData)
	sub_42CD90()
	for i = 0; i < int32(*(*int16)(unsafe.Add(v0, 44))); i++ {
		v2 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1321240, 16406, uintptr(i), 0)))
		v3 = int32(uintptr(unsafe.Pointer(nox_xxx_bindevent_bindNameByTitle_42EA40(v2))))
		v4 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1321244, 16406, uintptr(i), 0)))
		v5 = nox_xxx_keybind_nameByTitle_42E960(v4)
		v6 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1321248, 16406, uintptr(i), 0)))
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
		v1 **uint32
		v4 int32
		v5 int32
		v7 int32
	)
	dword_5d4594_1321228 = nox_new_window_from_file(internCStr("InputCfg.wnd"), sub_4C3A90)
	if dword_5d4594_1321228 == nil {
		return 0
	}
	dword_5d4594_1321236 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, 910)
	dword_5d4594_1321240 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, 911)
	dword_5d4594_1321244 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, 912)
	dword_5d4594_1321248 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, 913)
	if dword_5d4594_1321236 == nil {
		return 0
	}
	v1 = (**uint32)(dword_5d4594_1321236.WidgetData)
	**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*7)) = 921
	**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*8)) = 922
	**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*9)) = 920
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_1321236, sub_4C3CD0)
	sub_46B120(dword_5d4594_1321240, dword_5d4594_1321236)
	sub_46B120(dword_5d4594_1321244, dword_5d4594_1321236)
	sub_46B120(dword_5d4594_1321248, dword_5d4594_1321236)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1321244, sub_4C3A60)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1321248, sub_4C3A60)
	v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, 921)
	nox_window_call_field_94_fnc(dword_5d4594_1321240, 16408, uintptr(unsafe.Pointer(v2)), 0)
	nox_window_call_field_94_fnc(dword_5d4594_1321244, 16408, uintptr(unsafe.Pointer(v2)), 0)
	nox_window_call_field_94_fnc(dword_5d4594_1321248, 16408, uintptr(unsafe.Pointer(v2)), 0)
	v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, 922)
	nox_window_call_field_94_fnc(dword_5d4594_1321240, 16409, uintptr(unsafe.Pointer(v3)), 0)
	nox_window_call_field_94_fnc(dword_5d4594_1321244, 16409, uintptr(unsafe.Pointer(v3)), 0)
	nox_window_call_field_94_fnc(dword_5d4594_1321248, 16409, uintptr(unsafe.Pointer(v3)), 0)
	v4 = 971
	v5 = int32(sub_47DBC0()) + 971
	if v5 > 971 {
		for {
			v6 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, v4)
			nox_xxx_wnd_46ABB0(v6, 1)
			v4++
			if v4 >= v5 {
				break
			}
		}
	}
	v7 = nox_client_mousePriKey_430AF0()
	v8 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, v7+971)
	nox_window_call_field_94_fnc(v8, 16392, 1, 0)
	nox_window_setPos_46A9B0(dword_5d4594_1321228, int32((uint32(nox_win_width)-dword_5d4594_1321228.SizeVal.X)/2), 0)
	dword_5d4594_1321232 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, 980)
	sub_46B120(dword_5d4594_1321232, nil)
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_1321232, sub_4C3A90)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1321232, sub_4C3EB0)
	nox_window_set_hidden(dword_5d4594_1321232, 1)
	nox_window_setPos_46A9B0(dword_5d4594_1321232, int32((uint32(nox_win_width)-dword_5d4594_1321232.SizeVal.X)/2), int32(dword_5d4594_1321232.Off.Y))
	v9 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321232, 981)
	sub_46AEE0(v9, int32(uintptr(memmap.PtrOff(0x5D4594, 1321256))))
	v10 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, 932)
	nox_xxx_wnd_46ABB0(v10, 1)
	nox_window_set_hidden(dword_5d4594_1321228, 1)
	return 1
}
func sub_4C3CD0(win *gui.Window, a2, a3, a4 uintptr) uintptr {
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
			nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(a1), 0x4009, a3, a4)
			v8 = sub_4A4800(v7)
			nox_window_call_field_94_fnc(dword_5d4594_1321240, 16412, uintptr(v8), 0)
			nox_window_call_field_94_fnc(dword_5d4594_1321244, 16412, uintptr(v8), 0)
			nox_window_call_field_94_fnc(dword_5d4594_1321248, 16412, uintptr(v8), 0)
		} else if a2 == 16400 {
			v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 32)))
			if int32(*(*uint32)(unsafe.Add(v5, 48))) >= 0 {
				dword_5d4594_1321252 = uint32(a3)
				v9 = int32(nox_window_call_field_94_fnc(dword_5d4594_1321240, 16406, uintptr(*(*uint32)(unsafe.Add(v5, 48))), 0))
				v6 = nox_strman_loadString_40F1D0(internCStr("InputCfg.wnd:PressKey"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GuiInput.c"), 436)
				nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1321256)), internWStr("%s\n'%s'"), v6, v9)
				nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1321232)
				nox_xxx_windowFocus_46B500(dword_5d4594_1321232)
				sub_46C690(dword_5d4594_1321232)
				return nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(a1), 0x4010, a3, a4)
			}
		}
	} else {
		if a2 != 16391 {
			if a2 == 23 {
				return 1
			}
			if a2 != 0x4000 {
				return nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(a1), a2, a3, a4)
			}
		}
		if unsafe.Pointer(a3) == nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, 921) || unsafe.Pointer(a3) == nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1321228, 922) {
			nox_window_call_field_94_fnc(dword_5d4594_1321240, a2, a3, 0)
			nox_window_call_field_94_fnc(dword_5d4594_1321244, a2, a3, 0)
			nox_window_call_field_94_fnc(dword_5d4594_1321248, a2, a3, 0)
			return nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(a1), a2, a3, a4)
		}
	}
	return nox_xxx_wndListboxProcPre_4A30D0((*gui.Window)(a1), a2, a3, a4)
}
