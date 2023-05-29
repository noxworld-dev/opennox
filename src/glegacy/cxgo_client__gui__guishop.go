package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"unsafe"
)

func sub_478730(a1 *int32) {
	var (
		v1     int32
		v2     int32
		v3     int32
		result *uint32
		v5     *uint8
		v6     uint32
		v7     uint32
		v8     int32
		v9     unsafe.Pointer
		v10    *wchar2_t
		v11    int32
		v12    int32
		v13    int32
		v14    int32
	)
	v1 = int32((uint32(*a1) - *memmap.PtrUint32(0x5D4594, 1098380)) / 50)
	v2 = int32((uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))) - *memmap.PtrUint32(0x5D4594, 1098384) + dword_5d4594_1107036) / 50)
	if v1 >= 6 {
		v1 = 5
	}
	if v2 >= 10 {
		v2 = 9
	}
	v3 = v2 + v1*10
	result = *(**uint32)(memmap.PtrOff(0x5D4594, uint32(v3*140)+1098640))
	v5 = (*uint8)(memmap.PtrOff(0x5D4594, uint32(v3*140)+1098636))
	if result == nil {
		return
	}
	v6 = uint32(sub_4674A0())
	v7 = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*34)))
	v8 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*1))))
	if v6 < uint32(v8)**((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*34))) {
		v8 = int32(v6 / v7)
	}
	if v8 == 0 {
		sub_479520(int32(v7 - v6))
		return
	}
	v9 = nil
	if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v5)) + 112)))&0x13001000 != 0 {
		v9 = unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v5)) + 432))
	}
	sub_4C05F0(1, int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*34)))))
	v14 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v5)) + 108))))
	v13 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*1)))*4+4)))
	v12 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	v11 = *a1
	v10 = nox_strman_loadString_40F1D0(internCStr("BuyLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIShop.c"), 328)
	nox_gui_itemAmountDialog_4C0430((*wchar2_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v10)))))), v11, v12, v13, v14, v9, v8, 0, unsafe.Pointer(funAddr(sub_478850)), nil)
}
func nox_client_tradeXxxBuyAccept_478880(a1 int32, a2 int16) {
	var v2 *wchar2_t
	if sub_467B00(a1, 1) != 0 {
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*0)) = 5833
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&a1))), unsafe.Sizeof(uint16(0))*1)) = uint16(a2)
		nox_netlist_addToMsgListCli_40EBC0(31, 0, (*uint8)(unsafe.Pointer(&a1)), 4)
	} else {
		nox_xxx_clientPlaySoundSpecial_452D80(925, 100)
		v2 = nox_strman_loadString_40F1D0(internCStr("pickup.c:CarryingTooMuch"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIShop.c"), 207)
		nox_xxx_printCentered_445490(v2)
	}
}
func sub_4788F0(a1 int32, a2 int32) {
	var (
		v2 *wchar2_t
		v3 [5]byte
	)
	if sub_467B00(a1, a2) != 0 {
		v3[0] = 201
		v3[1] = 23
		*(*uint16)(unsafe.Pointer(&v3[2])) = uint16(int16(a1))
		v3[4] = byte(int8(a2))
		nox_netlist_addToMsgListCli_40EBC0(31, 0, (*uint8)(unsafe.Pointer(&v3[0])), 5)
	} else {
		nox_xxx_clientPlaySoundSpecial_452D80(925, 100)
		v2 = nox_strman_loadString_40F1D0(internCStr("pickup.c:CarryingTooMuch"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIShop.c"), 233)
		nox_xxx_printCentered_445490(v2)
	}
}
func sub_478B10(a1 *int2) *wchar2_t {
	var (
		v1     *uint32
		result *wchar2_t
		v3     int32
		v4     int32
		v5     int32
		v6     int32
	)
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1098576)))), 3806)))
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(v1)), (*uint32)(unsafe.Pointer(&v5)), (*uint32)(unsafe.Pointer(&v6)))
	nox_window_get_size((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), &v4, &v3)
	nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(dword_5d4594_1098456))), a1.field_0, a1.field_4)
	result = *(**wchar2_t)(unsafe.Pointer(&dword_5d4594_1098596))
	if dword_5d4594_1098596 != 0 || (func() bool {
		result = nox_strman_loadString_40F1D0(internCStr("SellInstructions"), (**byte)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1098596)))), internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIShop.c"), 597)
		return (func() uint32 {
			dword_5d4594_1098596 = uint32(uintptr(unsafe.Pointer(result)))
			return dword_5d4594_1098596
		}()) != 0
	}()) {
		result = (*wchar2_t)(unsafe.Pointer(uintptr(nox_xxx_drawStringWrap_43FAF0(nil, result, v5+8, v6+8, v4-16, v3-16))))
	}
	return result
}
func sub_478BC0(a1 *int32) *wchar2_t {
	var (
		v1     *uint32
		result *wchar2_t
		v3     int32
		v4     int32
		v5     int32
		v6     int32
	)
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1098576)))), 3806)))
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(v1)), (*uint32)(unsafe.Pointer(&v5)), (*uint32)(unsafe.Pointer(&v6)))
	nox_window_get_size((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), &v4, &v3)
	nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
	nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(dword_5d4594_1098456))), *a1, *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	result = *(**wchar2_t)(unsafe.Pointer(&dword_5d4594_1098600))
	if dword_5d4594_1098600 != 0 || (func() bool {
		result = nox_strman_loadString_40F1D0(internCStr("RepairInstructions"), (**byte)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1098600)))), internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIShop.c"), 628)
		return (func() uint32 {
			dword_5d4594_1098600 = uint32(uintptr(unsafe.Pointer(result)))
			return dword_5d4594_1098600
		}()) != 0
	}()) {
		result = (*wchar2_t)(unsafe.Pointer(uintptr(nox_xxx_drawStringWrap_43FAF0(nil, result, v5+8, v6+8, v4-16, v3-16))))
	}
	return result
}
func nox_xxx_cliStartShopDlg_478FD0(a1 *wchar2_t, a2 *byte, a3 int32) int32 {
	var v3 *uint32
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1098576)))), 3810)))
	sub_445C20()
	dword_5d4594_1098624 = 1
	dword_5d4594_1098628 = 1
	nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1098576))))), 0)
	nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1098576))))), 1)
	nox_xxx_wndShowModalMB_46A8C0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1098576))))))
	*memmap.PtrUint32(0x5D4594, 1098612) = uint32(nox_client_getRenderGUI())
	nox_client_setRenderGUI(0)
	sub_467BB0()
	if a1 != nil {
		nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1097300)), a1)
	} else {
		nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1097300)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1107044)))
	}
	sub_46AEE0(int32(uintptr(unsafe.Pointer(v3))), int32(uintptr(memmap.PtrOff(0x5D4594, 1097300))))
	if libc.StrLen(a2) != 0 {
		dword_5d4594_1098604 = uint32(uintptr(unsafe.Pointer(nox_strman_loadString_40F1D0(a2, (**byte)(memmap.PtrOff(0x5D4594, 1098608)), internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIShop.c"), 1128))))
	} else {
		dword_5d4594_1098604 = 0
		*memmap.PtrUint32(0x5D4594, 1098608) = 0
	}
	nox_xxx_getShopPic_4790F0(a3)
	if *memmap.PtrUint32(0x5D4594, 1098608) != 0 {
		nox_xxx_playDialogFile_44D900((*byte)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1098608)))), 100)
	}
	dword_5d4594_1107036 = 0
	return nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1098580))))), 16394, *(*int32)(unsafe.Pointer(&dword_5d4594_1098592)), 0, internCStr(__FILE__), __LINE__)
}
func sub_479520(a1 int32) {
	var (
		v1 *wchar2_t
		v2 *wchar2_t
	)
	v1 = nox_strman_loadString_40F1D0(internCStr("NotEnoughGold"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIShop.c"), 1346)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1097352)), v1, a1)
	v2 = nox_strman_loadString_40F1D0(internCStr("ShopInformationTitle"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIShop.c"), 1350)
	nox_xxx_dialogMsgBoxCreate_449A10((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1098576))))), (*wchar2_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), (*wchar2_t)(unsafe.Pointer(uintptr(int32(uintptr(memmap.PtrOff(0x5D4594, 1097352)))))), 33, nil, nil)
	nox_xxx_clientPlaySoundSpecial_452D80(925, 100)
}
func sub_479680() {
	dword_5d4594_1098616 = 0
}
func sub_4795E0(a1 int32, a2 int32) int32 {
	var (
		v2     unsafe.Pointer
		result int32
		v5     int32
		v9     int32
		v10    int32
	)
	v2 = nil
	var mpos nox_point = nox_client_getMousePos_4309F0()
	result = int32(dword_5d4594_1098616)
	if dword_5d4594_1098616 != 1 {
		result = sub_4676D0(a1)
		v5 = result
		if result != 0 {
			if *(*uint32)(unsafe.Pointer(uintptr(result + 112)))&0x13001000 != 0 {
				v2 = unsafe.Pointer(uintptr(result + 432))
			}
			sub_4C05F0(1, a2)
			v10 = sub_467700(a1)
			v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 108))))
			var str *wchar2_t = nox_strman_loadString_40F1D0(internCStr("SellLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIShop.c"), 1504)
			result = nox_gui_itemAmountDialog_4C0430(str, mpos.x, mpos.y, a1, v9, v2, v10, 0, unsafe.Pointer(funAddr(sub_479690)), unsafe.Pointer(funAddr(sub_479680)))
			dword_5d4594_1098616 = 1
		}
	}
	return result
}
func sub_479740(a1 int32, a2 uint32) {
	var (
		v2  unsafe.Pointer
		v4  int32
		v5  int32
		v6  *wchar2_t
		v7  int32
		v8  int32
		v9  int32
		v10 uint32
	)
	v2 = nil
	var mpos nox_point = nox_client_getMousePos_4309F0()
	v10 = uint32(sub_4674A0())
	if dword_5d4594_1098620 != 1 {
		v4 = sub_4676D0(a1)
		v5 = v4
		if v4 != 0 {
			if *(*uint32)(unsafe.Pointer(uintptr(v4 + 112)))&0x13001000 != 0 {
				v2 = unsafe.Pointer(uintptr(v4 + 432))
			}
			sub_4C05F0(1, int32(a2))
			if a2 > v10 {
				sub_479520(int32(a2 - v10))
				sub_467680()
			} else {
				v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 108))))
				v8 = mpos.y
				v7 = mpos.x
				v6 = nox_strman_loadString_40F1D0(internCStr("RepairLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIShop.c"), 1580)
				nox_gui_itemAmountDialog_4C0430((*wchar2_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v6)))))), v7, v8, a1, v9, v2, 1, 0, unsafe.Pointer(funAddr(sub_479820)), unsafe.Pointer(funAddr(sub_479810)))
				dword_5d4594_1098620 = 1
			}
		}
	}
}
