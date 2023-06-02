package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func sub_4C09D0() int32 {
	var (
		v0  *uint32
		v2  *wchar2_t
		v3  *wchar2_t
		v4  *wchar2_t
		v5  *wchar2_t
		v6  *wchar2_t
		v7  *uint32
		v8  *uint32
		v9  *wchar2_t
		v10 *wchar2_t
		v11 *wchar2_t
		v12 *wchar2_t
		v13 *wchar2_t
		v14 *wchar2_t
		v15 *uint8
		v16 *uint8
		v17 int32
		v18 *uint8
		v19 *uint8
		v20 int32
		v21 *wchar2_t
	)
	v0 = (*uint32)(unsafe.Pointer(nox_new_window_from_file(internCStr("Trade.wnd"), sub_4C0C90)))
	dword_5d4594_1320940 = uint32(uintptr(unsafe.Pointer(v0)))
	if v0 == nil {
		return 0
	}
	nox_window_set_all_funcs((*nox_window)(unsafe.Pointer(v0)), sub_4C0630, sub_4C0D00, nil)
	v2 = nox_strman_loadString_40F1D0(internCStr("TradeMain"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUITrade.c"), 692)
	nox_xxx_wndWddSetTooltip_46B000((*nox_window_data)(unsafe.Pointer(uintptr(dword_5d4594_1320940+36))), v2)
	v3 = (*wchar2_t)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3702)))
	v4 = nox_strman_loadString_40F1D0(internCStr("TradePlayerName"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUITrade.c"), 695)
	nox_xxx_wndWddSetTooltip_46B000((*nox_window_data)(unsafe.Pointer((*wchar2_t)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(wchar2_t(0))*18)))), v4)
	v5 = (*wchar2_t)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3703)))
	v6 = nox_strman_loadString_40F1D0(internCStr("TradeVendorName"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUITrade.c"), 698)
	nox_xxx_wndWddSetTooltip_46B000((*nox_window_data)(unsafe.Pointer((*wchar2_t)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(wchar2_t(0))*18)))), v6)
	v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3704)))
	nox_gui_winSetFunc96_46B070((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v7)))))), ccall.FuncAddr(sub_4C1120))
	v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3705)))
	nox_gui_winSetFunc96_46B070((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))), ccall.FuncAddr(sub_4C1120))
	v9 = (*wchar2_t)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3708)))
	v10 = nox_strman_loadString_40F1D0(internCStr("TradePlayerAccept"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUITrade.c"), 709)
	nox_xxx_wndWddSetTooltip_46B000((*nox_window_data)(unsafe.Pointer((*wchar2_t)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(wchar2_t(0))*18)))), v10)
	v11 = (*wchar2_t)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3709)))
	v12 = nox_strman_loadString_40F1D0(internCStr("TradeVendorAccept"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUITrade.c"), 712)
	nox_xxx_wndWddSetTooltip_46B000((*nox_window_data)(unsafe.Pointer((*wchar2_t)(unsafe.Add(unsafe.Pointer(v11), unsafe.Sizeof(wchar2_t(0))*18)))), v12)
	v13 = (*wchar2_t)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1320940)))), 3710)))
	v14 = nox_strman_loadString_40F1D0(internCStr("TradeCancel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUITrade.c"), 715)
	nox_xxx_wndWddSetTooltip_46B000((*nox_window_data)(unsafe.Pointer((*wchar2_t)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(wchar2_t(0))*18)))), v14)
	nox_window_set_hidden((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320940))))), 1)
	nox_xxx_wnd_46ABB0((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1320940))))), 0)
	v15 = (*uint8)(memmap.PtrOff(0x5D4594, 1319288))
	for {
		v16 = v15
		v17 = 2
		for {
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v16))), -int(4*1)))) = 0
			*(*uint32)(unsafe.Pointer(v16)) = 0
			v16 = (*uint8)(unsafe.Add(unsafe.Pointer(v16), 280))
			v17--
			if v17 == 0 {
				break
			}
		}
		v15 = (*uint8)(unsafe.Add(unsafe.Pointer(v15), 140))
		if int32(uintptr(unsafe.Pointer(v15))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1319568))) {
			break
		}
	}
	v18 = (*uint8)(memmap.PtrOff(0x5D4594, 1320312))
	for {
		v19 = v18
		v20 = 2
		for {
			*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v19))), -int(4*1)))) = 0
			*(*uint32)(unsafe.Pointer(v19)) = 0
			v19 = (*uint8)(unsafe.Add(unsafe.Pointer(v19), 280))
			v20--
			if v20 == 0 {
				break
			}
		}
		v18 = (*uint8)(unsafe.Add(unsafe.Pointer(v18), 140))
		if int32(uintptr(unsafe.Pointer(v18))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1320592))) {
			break
		}
	}
	v21 = nox_strman_loadString_40F1D0(internCStr("TotalValueLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUITrade.c"), 749)
	nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319972)), v21)
	*memmap.PtrUint32(0x5D4594, 1320188) = 0
	*memmap.PtrUint32(0x5D4594, 1320192) = 0
	*memmap.PtrUint32(0x5D4594, 1320196) = uint32(nox_win_width)
	*memmap.PtrUint32(0x5D4594, 1320200) = uint32(nox_win_height)
	*memmap.PtrUint32(0x5D4594, 1320220) = uint32(nox_win_width)
	*memmap.PtrUint32(0x5D4594, 1320224) = uint32(nox_win_height)
	*memmap.PtrUint32(0x5D4594, 1320204) = 0
	*memmap.PtrUint32(0x5D4594, 1320208) = 0
	*memmap.PtrUint32(0x5D4594, 1320164) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("TradeBase")))))
	*memmap.PtrUint32(0x5D4594, 1320168) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("TradeLeftAcceptPushed")))))
	*memmap.PtrUint32(0x5D4594, 1320172) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("TradeLeftAcceptLit")))))
	*memmap.PtrUint32(0x5D4594, 1320176) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("TradeRightAcceptLit")))))
	*memmap.PtrUint32(0x5D4594, 1320180) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("TradeCancelLit")))))
	*memmap.PtrUint32(0x5D4594, 1320184) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("TradeGold")))))
	return 1
}
func sub_4C15D0(a1 int32) int32 {
	var (
		result int32
		v2     int32
		v3     *uint8
		v4     int32
		v5     int32
		v6     *uint8
		v7     int32
		v8     *uint8
		v9     int32
		v10    int32
		v11    *wchar2_t
		v12    *uint8
	)
	result = int32(dword_5d4594_1320964)
	v2 = 0
	v12 = nil
	if dword_5d4594_1320964 != 0 {
		v3 = (*uint8)(memmap.PtrOff(0x5D4594, 1319284))
		for {
			v4 = 0
			v5 = int32(uintptr(unsafe.Pointer(v3)))
			for {
				if sub_4C1760(v5, int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 2))))) != 0 {
					v6 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr((v2+v4*2)*140)+1319284))
					goto LABEL_18
				}
				v4++
				v5 += 280
				if v4 >= 2 {
					break
				}
			}
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 140))
			v2++
			if int32(uintptr(unsafe.Pointer(v3))) < int32(uintptr(memmap.PtrOff(0x5D4594, 1319564))) {
				continue
			}
			break
		}
		v7 = 0
		v8 = (*uint8)(memmap.PtrOff(0x5D4594, 1320308))
		for {
			v9 = 0
			v10 = int32(uintptr(unsafe.Pointer(v8)))
			for {
				if sub_4C1760(v10, int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 2))))) != 0 {
					v12 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr((v7+v9*2)*140)+1320308))
					goto LABEL_17
				}
				v9++
				v10 += 280
				if v9 >= 2 {
					break
				}
			}
			v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 140))
			v7++
			if int32(uintptr(unsafe.Pointer(v8))) < int32(uintptr(memmap.PtrOff(0x5D4594, 1320588))) {
				continue
			}
			break
		}
		v11 = nox_strman_loadString_40F1D0(internCStr("TradeGUIItemNotFound"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUITrade.c"), 1141)
		nox_xxx_printCentered_445490(v11)
	LABEL_17:
		v6 = v12
	LABEL_18:
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*34))) -= *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*34))) / *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*1)))
		sub_4C1710(int32(uintptr(unsafe.Pointer(v6))), int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 2)))))
		result = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*1))) - 1)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*1))) = uint32(result)
		if result == 0 {
			result = nox_xxx_spriteDelete_45A4B0((*nox_drawable)(unsafe.Pointer(*(**uint64)(unsafe.Pointer(v6)))))
			*(*uint32)(unsafe.Pointer(v6)) = 0
		}
	}
	return result
}
