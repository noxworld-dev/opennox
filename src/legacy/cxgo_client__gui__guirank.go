package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var dword_5d4594_1090048 *gui.Window = nil

func sub_46DC60(a1 int32, a2 uint8, a3 int32) *wchar2_t {
	var result *wchar2_t
	if a3 != 0 {
		return (*wchar2_t)(unsafe.Pointer(uintptr(sub_46DC00(a1, a2, a3))))
	}
	result = nox_strman_loadString_40F1D0(internCStr("InternalError"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1050)
	if result != nil {
		result = (*wchar2_t)(unsafe.Pointer(uintptr(sub_46DC00(a1, a2, int32(uintptr(unsafe.Pointer(result)))))))
	}
	return result
}
func nox_xxx_guiDrawRank_46E870() int32 {
	var (
		v0     int32
		v1     *uint16
		v2     int32
		v3     *uint16
		v4     *uint16
		v5     int32
		v6     *uint16
		v7     int32
		v8     *uint16
		v9     *uint16
		v10    *uint16
		v11    *uint16
		v12    *uint16
		v13    int32
		v14    int32
		v15    *uint8
		v16    int32
		v17    int32
		v18    int32
		v19    int32
		v20    int32
		v21    *uint32
		v22    int32
		v23    int32
		v24    *uint32
		v25    int32
		v26    *uint32
		v27    int32
		v28    *uint32
		v29    int32
		v30    int32
		result int32
		v32    int32
		v33    int32
		v34    int32
		v35    int32
		v36    int32
		v37    int32
		v38    int32
		v39    int32
		v40    int32
		v41    int32
		v42    int32
		v43    int32
		v44    int32
		v45    [3]int32
		v46    int32
		v47    int32
		v48    [56]byte
		v49    [332]byte
		v50    [16]wchar2_t
	)
	_ = v50
	dword_587000_145668 = 6
	sub_46F030()
	v0 = nox_xxx_guiFontHeightMB_43F320(nil)
	v46 = v0
	*memmap.PtrUint32(0x5D4594, 1084036) = 80
	v32 = nox_win_width
	v1 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("Flag"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1641)))
	nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Pointer(v1)), &v41, &v44, v32)
	v2 = v41
	if v41 < 18 {
		v2 = 18
		v41 = 18
	}
	*memmap.PtrUint32(0x5D4594, 1084040) = uint32(v2 + 14)
	v33 = nox_win_width
	v3 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("Score"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1649)))
	nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Pointer(v3)), &v41, &v44, v33)
	v34 = nox_win_width
	v4 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("HealthHeading"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1650)))
	nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Pointer(v4)), &v42, &v43, v34)
	v5 = v41
	if v42 > v41 {
		v5 = v42
		v41 = v42
	}
	*memmap.PtrUint32(0x5D4594, 1084048) = uint32(v5 + 7)
	v35 = nox_win_width
	v6 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("Ping"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1657)))
	nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Pointer(v6)), &v41, &v44, v35)
	nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Pointer(mem_getU16Ptr(0x587000, 145972))), &v42, &v43, nox_win_width)
	v7 = v41
	if v42 > v41 {
		v7 = v42
		v41 = v42
	}
	*memmap.PtrUint32(0x5D4594, 1084052) = uint32(v7 + 7)
	v36 = nox_win_width
	v8 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("Class"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1667)))
	nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Pointer(v8)), &v41, &v44, v36)
	v37 = nox_win_width
	v9 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("Warrior"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1668)))
	nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Pointer(v9)), &v42, &v43, v37)
	if v42 > v41 {
		v41 = v42
	}
	v38 = nox_win_width
	v10 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("Wizard"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1671)))
	nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Pointer(v10)), &v42, &v43, v38)
	if v42 > v41 {
		v41 = v42
	}
	v39 = nox_win_width
	v11 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("Conjurer"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1674)))
	nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Pointer(v11)), &v42, &v43, v39)
	if v42 > v41 {
		v41 = v42
	}
	v40 = nox_win_width
	v12 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("LivesHeading"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1677)))
	nox_xxx_drawGetStringSize_43F840(nil, (*wchar2_t)(unsafe.Pointer(v12)), &v42, &v43, v40)
	v13 = v41
	if v42 > v41 {
		v13 = v42
		v41 = v42
	}
	v14 = 0
	*memmap.PtrUint32(0x5D4594, 1084044) = uint32(v13 + 7)
	v15 = (*uint8)(memmap.PtrOff(0x5D4594, 1084036))
	for {
		v16 = int32(*(*uint32)(unsafe.Pointer(v15)))
		v15 = (*uint8)(unsafe.Add(unsafe.Pointer(v15), 4))
		v14 += v16
		if int32(uintptr(unsafe.Pointer(v15))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1084056))) {
			break
		}
	}
	dword_5d4594_1090040 = uint32(v14)
	dword_5d4594_1090044 = uint32(439 - v0)
	dword_5d4594_1090048 = nox_window_new(nil, 1560, 0, int(v0)+40, 1, 1, nil)
	nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1090048)))), sub_46F060, sub_46F080, nil)
	*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1090048))) + 56))) = 0x80000000
	*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1090048))) + 64))) = 0x80000000
	*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1090048))) + 72))) = 0x80000000
	*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1090048))) + 80))) = 0x80000000
	*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(dword_5d4594_1090048))) + 88))) = 0x80000000
	*(*[332]byte)(unsafe.Pointer(&v49[0])) = [332]byte{}
	nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v49[72])), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1090136)))
	*(*uint32)(unsafe.Pointer(&v49[68])) = *memmap.PtrUint32(0x85B3FC, 940)
	*(*uint32)(unsafe.Pointer(&v49[20])) = 0x80000000
	*(*[56]byte)(unsafe.Pointer(&v48[0])) = [56]byte{}
	*(*uint16)(unsafe.Pointer(&v48[6])) = 0
	*(*uint32)(unsafe.Pointer(&v48[12])) = 0
	*(*uint32)(unsafe.Pointer(&v48[16])) = 0
	*(*uint32)(unsafe.Pointer(&v49[28])) = 0x80000000
	*(*uint32)(unsafe.Pointer(&v49[36])) = 0x80000000
	*(*uint32)(unsafe.Pointer(&v49[44])) = 0x80000000
	*(*uint32)(unsafe.Pointer(&v49[52])) = 0x80000000
	v17 = 0
	v47 = v0 * 3
	v18 = v0*3 + 1
	*(*uint32)(unsafe.Pointer(&v49[8])) = 32
	*(*uint32)(unsafe.Pointer(&v48[2])) = uint32(uint16(int16(v0 + 1)))
	libc.StrCpy(&v48[0], internCStr("@"))
	*(*uint32)(unsafe.Pointer(&v48[8])) = 1
	v19 = (v0 + 1) * 2
	v20 = v0 * 2
	for {
		v21 = (*uint32)(unsafe.Pointer(nox_gui_newScrollListBox_4A4310((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090048))))), 1088, int(uint32(v17)*dword_5d4594_1090040), int(v18), int(dword_5d4594_1090040), int(dword_5d4594_1090044-uint32(v19)), int32(uintptr(unsafe.Pointer(&v49[0]))), (*nox_scrollListBox_data)(unsafe.Pointer((*int16)(unsafe.Pointer(&v48[0])))))))
		v22 = int32(*memmap.PtrUint32(0x5D4594, 1084036))
		v23 = int32(dword_5d4594_1090044 - uint32(v19))
		*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090052) = uint32(uintptr(unsafe.Pointer(v21)))
		v24 = (*uint32)(unsafe.Pointer(nox_gui_newScrollListBox_4A4310((*gui.Window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v21)))))), 1088, 0, int(v20), int(v22), int(v23), int32(uintptr(unsafe.Pointer(&v49[0]))), (*nox_scrollListBox_data)(unsafe.Pointer((*int16)(unsafe.Pointer(&v48[0])))))))
		v25 = int32(dword_5d4594_1090044)
		*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090060) = uint32(uintptr(unsafe.Pointer(v24)))
		v26 = (*uint32)(unsafe.Pointer(nox_gui_newScrollListBox_4A4310((*gui.Window)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090052)))), 1088, int(*memmap.PtrInt32(0x5D4594, 1084036)), int(v20), int(*memmap.PtrInt32(0x5D4594, 1084040)), int(v25-v19), int32(uintptr(unsafe.Pointer(&v49[0]))), (*nox_scrollListBox_data)(unsafe.Pointer((*int16)(unsafe.Pointer(&v48[0])))))))
		v27 = int32(dword_5d4594_1090044)
		*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090068) = uint32(uintptr(unsafe.Pointer(v26)))
		*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090076) = uint32(uintptr(unsafe.Pointer(nox_gui_newScrollListBox_4A4310((*gui.Window)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090052)))), 1088, int(*memmap.PtrUint32(0x5D4594, 1084036)+*memmap.PtrUint32(0x5D4594, 1084040)), int(v20), int(*memmap.PtrInt32(0x5D4594, 1084044)), int(v27-v19), int32(uintptr(unsafe.Pointer(&v49[0]))), (*nox_scrollListBox_data)(unsafe.Pointer((*int16)(unsafe.Pointer(&v48[0]))))))))
		v28 = (*uint32)(unsafe.Pointer(nox_gui_newScrollListBox_4A4310((*gui.Window)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090052)))), 1088, int(*memmap.PtrUint32(0x5D4594, 1084036)+*memmap.PtrUint32(0x5D4594, 1084040)+*memmap.PtrUint32(0x5D4594, 1084044)), int(v20), int(*memmap.PtrInt32(0x5D4594, 1084048)), int(dword_5d4594_1090044-uint32(v19)), int32(uintptr(unsafe.Pointer(&v49[0]))), (*nox_scrollListBox_data)(unsafe.Pointer((*int16)(unsafe.Pointer(&v48[0])))))))
		v29 = int32(dword_5d4594_1090044)
		*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090084) = uint32(uintptr(unsafe.Pointer(v28)))
		*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090092) = uint32(uintptr(unsafe.Pointer(nox_gui_newScrollListBox_4A4310((*gui.Window)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090052)))), 1088, int(*memmap.PtrUint32(0x5D4594, 1084036)+*memmap.PtrUint32(0x5D4594, 1084040)+*memmap.PtrUint32(0x5D4594, 1084048)+*memmap.PtrUint32(0x5D4594, 1084044)), int(v20), int(*memmap.PtrInt32(0x5D4594, 1084052)), int(v29-v19), int32(uintptr(unsafe.Pointer(&v49[0]))), (*nox_scrollListBox_data)(unsafe.Pointer((*int16)(unsafe.Pointer(&v48[0]))))))))
		nox_xxx_wndSetProc_46B2C0((*gui.Window)(*memmap.PtrPtr(0x5D4594, uintptr(v17*4)+1090052)), nox_xxx_Proc_46F070)
		sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, uintptr(v17*4)+1090060)))), (*gui.Window)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090052)))))
		sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, uintptr(v17*4)+1090068)))), (*gui.Window)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090052)))))
		sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, uintptr(v17*4)+1090076)))), (*gui.Window)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090052)))))
		sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, uintptr(v17*4)+1090084)))), (*gui.Window)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090052)))))
		sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, uintptr(v17*4)+1090092)))), (*gui.Window)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v17*4)+1090052)))))
		v17++
		if v17 >= 2 {
			break
		}
	}
	*(*uint32)(unsafe.Pointer(&v49[8])) = 2048
	*(*uint32)(unsafe.Pointer(&v49[68])) = nox_color_yellow_2589772
	v45[0] = int32(uintptr(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("yourrank"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1772))))
	v30 = v46 + 1
	v45[1] = 0
	v45[2] = 0
	dword_5d4594_1090100 = unsafe.Pointer(nox_gui_newStaticText_489300((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090048))))), 1088, 0, v46, *(*int32)(unsafe.Pointer(&dword_5d4594_1090040)), v46+1, (*nox_window_data)(unsafe.Pointer(&v49[0])), (*nox_staticText_data)(unsafe.Pointer(&v45[0]))))
	*(*uint32)(unsafe.Pointer(&v49[68])) = nox_color_white_2523948
	v45[0] = int32(uintptr(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("WindowDir:Empty"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1782))))
	dword_5d4594_1090112 = uint32(uintptr(unsafe.Pointer(nox_gui_newStaticText_489300((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090048))))), 1088, 0, v20, *(*int32)(unsafe.Pointer(&dword_5d4594_1090040)), v30, (*nox_window_data)(unsafe.Pointer(&v49[0])), (*nox_staticText_data)(unsafe.Pointer(&v45[0]))))))
	*(*uint32)(unsafe.Pointer(&v49[68])) = *memmap.PtrUint32(0x85B3FC, 940)
	v45[0] = int32(uintptr(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("WindowDir:Empty"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1790))))
	dword_5d4594_1090108 = uint32(uintptr(unsafe.Pointer(nox_gui_newStaticText_489300((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090048))))), 1088, 0, v47, *(*int32)(unsafe.Pointer(&dword_5d4594_1090040)), v30, (*nox_window_data)(unsafe.Pointer(&v49[0])), (*nox_staticText_data)(unsafe.Pointer(&v45[0]))))))
	*(*uint32)(unsafe.Pointer(&v49[68])) = *memmap.PtrUint32(0x8531A0, 2572)
	v45[0] = int32(uintptr(unsafe.Pointer(nox_strman_loadString_40F1D0(internCStr("TeamPlayerRank"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1798))))
	*memmap.PtrUint32(0x5D4594, 1090104) = uint32(uintptr(unsafe.Pointer(nox_gui_newStaticText_489300((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090048))))), 1088, 0, 0, *(*int32)(unsafe.Pointer(&dword_5d4594_1090040)), v30, (*nox_window_data)(unsafe.Pointer(&v49[0])), (*nox_staticText_data)(unsafe.Pointer(&v45[0]))))))
	result = int32(uintptr(unsafe.Pointer(dword_5d4594_1090048)))
	dword_587000_145664 = 1
	return result
}
func sub_46F030() *wchar2_t {
	var (
		i      int32
		result *wchar2_t
	)
	for i = 0; i < 12; i += 4 {
		result = nox_strman_loadString_40F1D0(*(**byte)(memmap.PtrOff(0x587000, uintptr(i)+145676)), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 167)
		*memmap.PtrUint32(0x5D4594, uintptr(i)+1084056) = uint32(uintptr(unsafe.Pointer(result)))
	}
	return result
}
func sub_46F080(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = int32(uintptr(win.C()))
		a2    = int32(uintptr(draw.C()))
		v2    *byte
		v4    *byte
		v5    int16
		v6    int32
		v7    *uint32
		v8    int32
		v9    int32
		v10   *wchar2_t
		v11   *wchar2_t
		v12   uint8
		v13   uint8
		v14   int32
		v15   int32
		v16   int32
		v17   int32
		v18   int32
		v19   uint8
		v20   *byte
		v21   *wchar2_t
		v22   *wchar2_t
		v23   *wchar2_t
		v24   *wchar2_t
		v25   int32
		v26   *wchar2_t
		v27   int32
		v28   int32
		v29   int32
		v30   int32
		v31   uint8
		v32   uint8
		v33   int32
		v34   int32
		v35   *byte
		v36   int32
		v37   int32
		xLeft int32
		yTop  int32
		v40   uint8
	)
	v2 = nil
	v35 = nil
	if !nox_common_gameFlags_check_40A5C0(8) && dword_587000_145668 != 6 {
		dword_5d4594_1090120 = dword_587000_145668 - 1
		if *(*int32)(unsafe.Pointer(&dword_587000_145668))-1 < 0 {
			dword_5d4594_1090120 = 5
		}
		sub_4703F0()
		dword_587000_145668 = 6
		if dword_5d4594_1090120 == 0 {
			return 1
		}
	}
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(uintptr(a1))), (*uint32)(unsafe.Pointer(&xLeft)), (*uint32)(unsafe.Pointer(&yTop)))
	v4 = nox_xxx_cliGamedataGet_416590(0)
	if nox_common_gameFlags_check_40A5C0(1) {
		v5 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
		v6 = int32(uint16(nox_xxx_servGamedataGet_40A020(v5)))
	} else {
		v6 = int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v4))), unsafe.Sizeof(uint16(0))*27))))
	}
	v34 = v6
	if int32(int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 4))))) >= 0 {
		if *(*uint32)(unsafe.Pointer(uintptr(a2 + 20))) != 0x80000000 {
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))), int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12)))))
		}
	} else {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a2 + 24)))))), xLeft, yTop)
	}
	if dword_587000_145664 != 0 || gameFrame() > (*memmap.PtrUint32(0x5D4594, 1090124)+gameFPS()) {
		set_dword_5d4594_3799468(1)
		*memmap.PtrUint32(0x5D4594, 1090124) = gameFrame()
		dword_587000_145672 = math.MaxUint32
		v33 = 0
		sub_46DB80()
		sub_46DCC0()
		dword_587000_145664 = 0
		v7 = nox_xxx_objGetTeamByNetCode_418C80(int32(nox_player_netCode_85319C))
		if v7 != nil {
			v2 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v7))), 4)))))))
			v35 = v2
		}
		if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
			v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x8531A0, 2576) + 3680))))
			if (v8&1) == 0 || v8&0x20 != 0 {
				v33 = 1
			}
		}
		v9 = int32(dword_5d4594_1090120)
		if int32(*memmap.PtrUint8(0x5D4594, 1090116)) != 0 && (dword_5d4594_1090120 == 2 || dword_5d4594_1090120 == 3) {
			v10 = nox_strman_loadString_40F1D0(internCStr("team"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1338)
			sub_46DC60(*memmap.PtrInt32(0x5D4594, 1090060), 9, int32(uintptr(unsafe.Pointer(v10))))
			sub_46DC60(*memmap.PtrInt32(0x5D4594, 1090068), 9, int32(uintptr(memmap.PtrOff(0x587000, 146512))))
			sub_46DC60(*memmap.PtrInt32(0x5D4594, 1090076), 9, int32(uintptr(memmap.PtrOff(0x587000, 146516))))
			v11 = nox_strman_loadString_40F1D0(internCStr("score"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1341)
			sub_46DC60(*memmap.PtrInt32(0x5D4594, 1090084), 9, int32(uintptr(unsafe.Pointer(v11))))
			sub_46DC60(*memmap.PtrInt32(0x5D4594, 1090092), 9, int32(uintptr(memmap.PtrOff(0x587000, 146564))))
			v12 = 0
			v31 = 0
			if int32(*memmap.PtrUint8(0x5D4594, 1090116)) != 0 {
				for {
					v13 = sub_46FEB0(v31)
					v14 = int32(v31) * 56
					sub_46DC30(*memmap.PtrInt32(0x5D4594, 1090060), v13, (*wchar2_t)(memmap.PtrOff(0x587000, 146568)), memmap.PtrOff(0x5D4594, uintptr(v14)+1087204))
					sub_46DC30(*memmap.PtrInt32(0x5D4594, 1090068), v13, (*wchar2_t)(memmap.PtrOff(0x587000, 146576)))
					sub_46DC30(*memmap.PtrInt32(0x5D4594, 1090076), v13, (*wchar2_t)(memmap.PtrOff(0x587000, 146580)))
					sub_46DC30(*memmap.PtrInt32(0x5D4594, 1090084), v13, (*wchar2_t)(memmap.PtrOff(0x587000, 146584)), *memmap.PtrUint32(0x5D4594, uintptr(v14)+1087252))
					sub_46DC30(*memmap.PtrInt32(0x5D4594, 1090092), v13, (*wchar2_t)(memmap.PtrOff(0x587000, 146592)))
					v31 = func() uint8 {
						p := &v12
						*p++
						return *p
					}()
					if int32(v12) >= int32(*memmap.PtrUint8(0x5D4594, 1090116)) {
						break
					}
				}
			} else {
				v13 = uint8(int8(a1))
			}
			sub_46DC30(*memmap.PtrInt32(0x5D4594, 1090060), v13, (*wchar2_t)(memmap.PtrOff(0x587000, 146596)))
			sub_46DC30(*memmap.PtrInt32(0x5D4594, 1090068), v13, (*wchar2_t)(memmap.PtrOff(0x587000, 146600)))
			sub_46DC30(*memmap.PtrInt32(0x5D4594, 1090076), v13, (*wchar2_t)(memmap.PtrOff(0x587000, 146604)))
			sub_46DC30(*memmap.PtrInt32(0x5D4594, 1090084), v13, (*wchar2_t)(memmap.PtrOff(0x587000, 146608)))
			sub_46DC30(*memmap.PtrInt32(0x5D4594, 1090092), v13, (*wchar2_t)(memmap.PtrOff(0x587000, 146612)))
			v9 = int32(dword_5d4594_1090120)
		}
		v36 = int32(*(*int16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, 1090060) + 32))) + 46))))
		if int32(*memmap.PtrUint8(0x5D4594, 1090117)) != 0 && (v9 == 2 || v9 == 4 || v9 == 5) {
			sub_46F8F0(0, 0)
			v9 = int32(dword_5d4594_1090120)
			if dword_5d4594_1090120 == 4 {
				if int32(*memmap.PtrUint8(0x5D4594, 1090117)) <= 3 {
					*((*uint8)(unsafe.Pointer(&a2))) = *memmap.PtrUint8(0x5D4594, 1090117)
				} else {
					*((*uint8)(unsafe.Pointer(&a2))) = 3
				}
			} else {
				*((*uint8)(unsafe.Pointer(&a2))) = *memmap.PtrUint8(0x5D4594, 1090117)
			}
			v32 = 0
			if int32(uint8(int8(a2))) != 0 {
				for {
					v15 = 0
					v16 = int32(v32) >> 4
					if int32(v32) == 16 {
						sub_46F8F0(1, v36)
					}
					if nox_common_gameFlags_check_40A5C0(1024) && v34 > 0 && *memmap.PtrInt32(0x5D4594, uintptr(int32(v32)*80)+1084196) >= v34 {
						v15 = 1
					}
					v17 = int32(v32) * 80
					v18 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v17)+1084208))
					if (v18&1) == 0 || v18&0x20 != 0 || v15 != 0 {
						if *memmap.PtrInt32(0x5D4594, uintptr(int32(v32)*80)+1084184) == -1 {
							v40 = 3
							if v18&0x20 != 0 || v15 != 0 {
								v40 = 2
							}
						} else {
							v19 = sub_46FE60(int32(*memmap.PtrUint32(0x5D4594, uintptr(int32(v32)*80)+1084184)))
							v40 = sub_46FEB0(v19)
							if int32(*memmap.PtrUint8(0x5D4594, uintptr(int32(v32)*80)+1084208))&0x20 != 0 || v15 != 0 {
								v40 -= 2
							}
						}
					} else {
						v40 = 9
					}
					if *memmap.PtrUint32(0x5D4594, uintptr(int32(v32)*80)+1084192) == nox_player_netCode_85319C {
						dword_587000_145672 = uint32(*(*int16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v16*4)+1090060) + 32))) + 46))))
						*memmap.PtrUint32(0x5D4594, 1088996) = uint32(int32(v32) >> 4)
					}
					sub_46DC30(int32(*memmap.PtrUint32(0x5D4594, uintptr(v16*4)+1090060)), v40, (*wchar2_t)(memmap.PtrOff(0x587000, 146616)), memmap.PtrOff(0x5D4594, uintptr(v17)+1084132))
					sub_46DC30(int32(*memmap.PtrUint32(0x5D4594, uintptr(v16*4)+1090076)), v40, (*wchar2_t)(memmap.PtrOff(0x587000, 146624)), *memmap.PtrUint32(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, uintptr(int32(v32)*80)+1084188))*4)+1084056))
					if dword_5d4594_1090120 != 5 || *memmap.PtrUint32(0x5D4594, uintptr(int32(v32)*80)+1084196) > 0 {
						sub_46DC30(int32(*memmap.PtrUint32(0x5D4594, uintptr(v16*4)+1090084)), v40, (*wchar2_t)(memmap.PtrOff(0x587000, 146632)), *memmap.PtrUint32(0x5D4594, uintptr(int32(v32)*80)+1084196))
					} else {
						sub_46DC30(int32(*memmap.PtrUint32(0x5D4594, uintptr(v16*4)+1090084)), v40, (*wchar2_t)(memmap.PtrOff(0x587000, 146640)))
					}
					sub_46DC30(int32(*memmap.PtrUint32(0x5D4594, uintptr(v16*4)+1090092)), v40, (*wchar2_t)(memmap.PtrOff(0x587000, 146648)), *memmap.PtrUint32(0x5D4594, uintptr(int32(v32)*80)+1084200))
					if dword_5d4594_1090120 == 5 {
						v20 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*memmap.PtrUint32(0x5D4594, uintptr(int32(v32)*80)+1084192)))))
						if v20 != nil {
							sub_46DC30(int32(*memmap.PtrUint32(0x5D4594, uintptr(v16*4)+1090068)), v40, (*wchar2_t)(memmap.PtrOff(0x587000, 146656)), (*byte)(unsafe.Add(unsafe.Pointer(v20), 2096)))
						}
					} else {
						v21 = sub_46FB50(int32(*memmap.PtrUint32(0x5D4594, uintptr(int32(v32)*80)+1084204)), (*uint8)(unsafe.Pointer(&v37)))
						sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(v16*4)+1090068)), uint8(int8(v37)), int32(uintptr(unsafe.Pointer(v21))))
					}
					v32++
					if int32(v32) >= int32(uint8(int8(a2))) {
						break
					}
				}
				v9 = int32(dword_5d4594_1090120)
				v2 = v35
			}
		} else if v9 == 1 {
			sub_46FFD0()
			v9 = int32(dword_5d4594_1090120)
		}
		switch v9 {
		case 1, 2, 4, 5:
			switch v9 {
			case 2:
				v22 = nox_strman_loadString_40F1D0(internCStr("TeamPlayerRank"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1475)
			case 4:
				v22 = nox_strman_loadString_40F1D0(internCStr("Top3"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1479)
			case 5:
				v22 = nox_strman_loadString_40F1D0(internCStr("WolRank"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1483)
			case 1:
				v22 = nox_strman_loadString_40F1D0(internCStr("Noxworld.c:Quest"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1487)
			default:
				v22 = (*wchar2_t)(unsafe.Pointer(uintptr(a2)))
			}
			if !nox_common_gameFlags_check_40A5C0(1) || !nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				if dword_5d4594_1090120 == 1 {
					v28 = nox_gui_getQuestStage_450B10()
					v23 = nox_strman_loadString_40F1D0(internCStr("Noxworld.c:Stage"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1499)
					nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1086692)), (*wchar2_t)(unsafe.Pointer(internCStr("%s %d"))), v23, v28)
				} else {
					v29 = int32(*memmap.PtrUint8(0x5D4594, 1090118))
					v27 = int32(uint8(sub_46FEE0()))
					v24 = nox_strman_loadString_40F1D0(internCStr("yourrank"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1501)
					nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1086692)), (*wchar2_t)(unsafe.Pointer(internCStr("%s %d / %d"))), v24, v27, v29)
				}
			}
		case 3:
			if v2 != nil {
				v33 = 1
				v25 = int32(uint8(sub_46FF70(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*13)))))))
			} else {
				v25 = 0
			}
			v22 = nox_strman_loadString_40F1D0(internCStr("Teams"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1519)
			if !nox_common_gameFlags_check_40A5C0(1) || !nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				v30 = int32(*memmap.PtrUint8(0x5D4594, 1090116))
				v26 = nox_strman_loadString_40F1D0(internCStr("yourteamrank"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 1525)
				nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1086692)), (*wchar2_t)(unsafe.Pointer(internCStr("%s %d / %d"))), v26, v25, v30)
			}
		default:
			v22 = (*wchar2_t)(unsafe.Pointer(uintptr(a2)))
		}
		if v33 != 0 {
			if wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090100)))))) != 0 {
				nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090100))))), 0)
			}
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090100))))), 16385, uintptr(memmap.PtrOff(0x5D4594, 1086692)), 0)
		} else if wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090100)))))) == 0 {
			nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090100))))), 1)
		}
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1090104)))), 16385, uintptr(unsafe.Pointer(v22)), 0)
		sub_46FC50()
		sub_46FD80()
	}
	if int32(dword_587000_145672) >= 0 {
		sub_46FAE0()
	}
	return 1
}
func sub_46F8F0(a1 int32, a2 int32) *wchar2_t {
	var (
		v2 int32
		v3 *wchar2_t
		v4 *wchar2_t
		v6 *wchar2_t
		v7 *wchar2_t
		v8 *wchar2_t
	)
	v2 = a2
	if a2 > 0 {
		for {
			sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1090060)), 9, int32(uintptr(memmap.PtrOff(0x587000, 147124))))
			sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1090068)), 9, int32(uintptr(memmap.PtrOff(0x587000, 147128))))
			sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1090076)), 9, int32(uintptr(memmap.PtrOff(0x587000, 147132))))
			sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1090084)), 9, int32(uintptr(memmap.PtrOff(0x587000, 147136))))
			sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1090092)), 9, int32(uintptr(memmap.PtrOff(0x587000, 147140))))
			v2--
			if v2 == 0 {
				break
			}
		}
	}
	v3 = nox_strman_loadString_40F1D0(internCStr("player"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 189)
	sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1090060)), 9, int32(uintptr(unsafe.Pointer(v3))))
	sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1090068)), 9, int32(uintptr(memmap.PtrOff(0x587000, 147188))))
	if dword_5d4594_1090120 == 1 {
		v6 = nox_strman_loadString_40F1D0(internCStr("LivesHeading"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 193)
	} else {
		v6 = nox_strman_loadString_40F1D0(internCStr("class"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 195)
	}
	sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1090076)), 9, int32(uintptr(unsafe.Pointer(v6))))
	if dword_5d4594_1090120 == 5 {
		v7 = nox_strman_loadString_40F1D0(internCStr("rank"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 199)
		sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1090084)), 9, int32(uintptr(unsafe.Pointer(v7))))
	} else {
		if dword_5d4594_1090120 == 1 {
			v8 = nox_strman_loadString_40F1D0(internCStr("HealthHeading"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 201)
		} else {
			v8 = nox_strman_loadString_40F1D0(internCStr("score"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 203)
		}
		sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1090084)), 9, int32(uintptr(unsafe.Pointer(v8))))
	}
	if dword_5d4594_1090120 == 1 {
		v4 = nox_strman_loadString_40F1D0(internCStr("class"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 207)
	} else {
		v4 = nox_strman_loadString_40F1D0(internCStr("ping"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 209)
	}
	return sub_46DC60(int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+1090092)), 9, int32(uintptr(unsafe.Pointer(v4))))
}
func sub_46FB50(a1 int32, a2 *uint8) *wchar2_t {
	var (
		v2     *wchar2_t
		result *wchar2_t
		v4     *wchar2_t
		v5     *wchar2_t
		v6     *wchar2_t
	)
	switch a1 {
	case 4:
		v2 = nox_strman_loadString_40F1D0(internCStr("Ball"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 244)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1090024)), (*wchar2_t)(unsafe.Pointer(internCStr("<%s"))), v2)
		*a2 = 4
		result = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1090024))
	case 1:
		v4 = nox_strman_loadString_40F1D0(internCStr("King"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 250)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1090024)), (*wchar2_t)(unsafe.Pointer(internCStr("<%s"))), v4)
		result = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1090024))
		*a2 = 4
	case 2:
		v5 = nox_strman_loadString_40F1D0(internCStr("Flag"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 256)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1090024)), (*wchar2_t)(unsafe.Pointer(internCStr("<%s"))), v5)
		result = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1090024))
		*a2 = 7
	case 3:
		v6 = nox_strman_loadString_40F1D0(internCStr("Flag"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 262)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1090024)), (*wchar2_t)(unsafe.Pointer(internCStr("<%s"))), v6)
		*a2 = 13
		result = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1090024))
	default:
		result = (*wchar2_t)(memmap.PtrOff(0x587000, 147724))
		*a2 = 4
	}
	return result
}
func sub_46FC50() int8 {
	var (
		v0 int16
		v1 int16
		v2 int32
		v3 int32
		v4 *wchar2_t
		v6 int32
		v7 int32
	)
	if sub_40A220() != 0 && (!nox_common_gameFlags_check_40A5C0(1) || sub_40A300() != 0 || int32(func() uint8 {
		v0 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
		return sub_40A180(v0)
	}()) != 0) {
		if !nox_common_gameFlags_check_40A5C0(1) || sub_40A300() != 0 || int32(func() uint8 {
			v1 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
			*((*uint8)(unsafe.Pointer(&v2))) = sub_40A180(v1)
			return uint8(int8(v2))
		}()) != 0 {
			if wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090108)))))) != 0 {
				nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090108))))), 0)
			}
			v3 = sub_40A230()
			v7 = v3 % 60000 / 1000
			v6 = v3 / 60000
			v4 = nox_strman_loadString_40F1D0(internCStr("TimeRemaining"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 352)
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1084068)), v4, v6, v7)
			*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090108))))), 16385, uintptr(memmap.PtrOff(0x5D4594, 1084068)), 0)))
		}
	} else {
		v2 = wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090108))))))
		if v2 == 0 {
			*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090108))))), 1)))
		}
	}
	return int8(v2)
}
func sub_46FD80() int32 {
	var (
		result int32
		v1     int16
		v2     int32
		v3     *wchar2_t
		v4     int32
	)
	if nox_common_gameFlags_check_40A5C0(4224) {
		result = wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090112))))))
		if result == 0 {
			result = nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090112))))), 1)
		}
	} else {
		if wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090112)))))) != 0 {
			nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090112))))), 0)
		}
		if nox_common_gameFlags_check_40A5C0(1) {
			v1 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
			v2 = int32(uint16(nox_xxx_servGamedataGet_40A020(v1)))
		} else {
			v2 = int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(nox_xxx_cliGamedataGet_416590(0)))), unsafe.Sizeof(uint16(0))*27))))
		}
		v4 = v2
		v3 = nox_strman_loadString_40F1D0(internCStr("LessonLimit"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guirank.c"), 390)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1083972)), v3, v4)
		result = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1090112))))), 16385, uintptr(memmap.PtrOff(0x5D4594, 1083972)), 0))
	}
	return result
}
