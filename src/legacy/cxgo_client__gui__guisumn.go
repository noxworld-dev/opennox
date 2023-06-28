package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_guiSummonCreatureLoad_4C1D80() int32 {
	var (
		v0 *wchar2_t
		v1 *uint32
		v2 *byte
		v3 *uint32
		v4 *uint32
		v5 int32
		v6 *uint8
	)
	*memmap.PtrUint32(0x5D4594, 1321004) = 0
	*memmap.PtrUint32(0x5D4594, 1321000) = 4294967151
	dword_5d4594_1320988 = uint32(nox_win_width - 95)
	dword_5d4594_1320992 = 4294967151
	dword_5d4594_1321032 = uint32(uintptr(unsafe.Pointer(nox_window_new(nil, 8, int(nox_win_width)-95, -145, 87, 115, nil))))
	nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(dword_5d4594_1321032)), sub_4C2BD0, sub_4C24A0, nil)
	dword_5d4594_1321036 = uint32(uintptr(unsafe.Pointer(nox_window_new((*gui.Window)(dword_5d4594_1321032), 136, 5, 38, 76, 76, nil))))
	nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(dword_5d4594_1321036)), nox_xxx_wndSummonProc_4C2B10, nox_xxx_guiDrawSummonBox_4C1FE0, sub_4C2C20)
	v0 = nox_strman_loadString_40F1D0(internCStr("ToolTipSummon"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guisumn.c"), 818)
	nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(unsafe.Add(dword_5d4594_1321036, 36)), v0)
	*memmap.PtrPtr(0x5D4594, 1320996) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("CreatureCageBottom")))
	v1 = (*uint32)(unsafe.Pointer(nox_window_new((*gui.Window)(dword_5d4594_1321036), 160, 0, 0, 1, 1, nil)))
	v2 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("CreatureCageTop"))))
	nox_xxx_wndSetIcon_46AE60(int32(uintptr(unsafe.Pointer(v1))), int32(uintptr(unsafe.Pointer(v2))))
	nox_xxx_wndSetOffsetMB_46AE40(int32(uintptr(unsafe.Pointer(v1))), -5, -38)
	v3 = (*uint32)(unsafe.Pointer(nox_window_new((*gui.Window)(dword_5d4594_1321032), 8, 19, 0, 48, 39, nil)))
	nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(v3)), sub_4C2BE0, sub_4C24A0, nil)
	*memmap.PtrPtr(0x5D4594, 1321008) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("CreatureCageHuntButtonLit")))
	*memmap.PtrPtr(0x5D4594, 1321012) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("CreatureCageHuntButton")))
	*memmap.PtrPtr(0x5D4594, 1321016) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("CreatureCageGuardButtonLit")))
	*memmap.PtrPtr(0x5D4594, 1321020) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("CreatureCageGuardButton")))
	dword_5d4594_1321024 = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("CreatureCageEscortButtonLit")))))
	*memmap.PtrPtr(0x5D4594, 1321028) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("CreatureCageEscortButton")))
	v4 = (*uint32)(unsafe.Pointer(nox_window_new(nil, 168, int(dword_5d4594_1320988+27), int(dword_5d4594_1320992+12), 34, 34, nil)))
	dword_5d4594_1321040 = uint32(uintptr(unsafe.Pointer(v4)))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*11)))
	*(*uint8)(unsafe.Add(unsafe.Pointer(&v5), 1)) |= 1
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*11)) = uint32(v5)
	nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(dword_5d4594_1321040)), nox_xxx_wndSummonBigButtonProc_4C24B0, nil, sub_4C2CE0)
	nox_xxx_wndSetIcon_46AE60(dword_5d4594_1321040, *memmap.PtrInt32(0x5D4594, 1321028))
	sub_46AEC0(dword_5d4594_1321040, dword_5d4594_1321024)
	nox_xxx_wndSetIconLit_46AEA0(dword_5d4594_1321040, dword_5d4594_1321024)
	nox_xxx_wndSetOffsetMB_46AE40(dword_5d4594_1321040, -27, -12)
	*memmap.PtrUint8(0x5D4594, 1321200) = 0
	nox_window_set_hidden((*gui.Window)(dword_5d4594_1321032), 1)
	nox_window_set_hidden((*gui.Window)(dword_5d4594_1321040), 1)
	v6 = (*uint8)(memmap.PtrOff(0x5D4594, 1321060))
	for {
		*(*uint32)(unsafe.Pointer(v6)) = 0
		v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 32))
		if int32(uintptr(unsafe.Pointer(v6))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321188))) {
			break
		}
	}
	sub_4C2BF0()
	dword_5d4594_1321044 = 0
	dword_5d4594_1321204 = 0
	dword_5d4594_1321196 = 0
	return 1
}
func nox_xxx_wndSummonCreateList_4C2560(a1 *int2) {
	var (
		v1  **byte
		v2  *uint16
		v3  int32
		v4  bool
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		i   int32
		v10 *uint32
		v12 int32
		v13 int32
	)
	nox_xxx_screenWidth_587000_184452 = 0
	v1 = (**byte)(memmap.PtrOff(0x587000, 184344))
	for {
		if v1 != (**byte)(memmap.PtrOff(0x587000, 184352)) {
			v2 = nox_strman_loadString_40F1D0(*v1, nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guisumn.c"), 588)
			nox_xxx_drawGetStringSize_43F840(nil, v2, &v12, &v13, nox_win_width)
			if nox_xxx_screenWidth_587000_184452 < uint32(v12) {
				nox_xxx_screenWidth_587000_184452 = uint32(v12)
			}
		}
		v1 = (**byte)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*byte)(nil))*1))
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x587000, 184368))) {
			break
		}
	}
	nox_xxx_screenWidth_587000_184452 += 8
	v3 = nox_xxx_guiFontHeightMB_43F320(nil) + 2
	v5 = int32(uint32(a1.field_0) - nox_xxx_screenWidth_587000_184452/2)
	v4 = v5 < 0
	v12 = int32(uint32(a1.field_0) - nox_xxx_screenWidth_587000_184452/2)
	v6 = v3*5 + 12
	if v4 {
		v5 = 0
	} else {
		if nox_xxx_screenWidth_587000_184452+uint32(v5) < uint32(nox_win_width) {
			goto LABEL_11
		}
		v5 = int32(uint32(nox_win_width) - nox_xxx_screenWidth_587000_184452 - 1)
	}
	v12 = v5
LABEL_11:
	v7 = a1.field_4 - v6/2
	v13 = v7
	if v7 < 0 {
		v7 = 0
		v13 = v7
		goto LABEL_16
	}
	if v6+v7 >= nox_win_height {
		v7 = nox_win_width - v6 - 1
		v13 = v7
	}
LABEL_16:
	dword_5d4594_1321044 = uint32(uintptr(unsafe.Pointer(nox_window_new(nil, 40, int(v5), int(v7), int(nox_xxx_screenWidth_587000_184452), int(v3*5+12), nil))))
	nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(dword_5d4594_1321044)), nil, sub_4C26F0, nil)
	nox_xxx_wndShowModalMB_46A8C0((*gui.Window)(dword_5d4594_1321044))
	v8 = 0
	for i = 0; i < 6; i++ {
		if i != 2 {
			v10 = (*uint32)(unsafe.Pointer(nox_window_new((*gui.Window)(dword_5d4594_1321044), 8, 0, int(v8), int(nox_xxx_screenWidth_587000_184452), int(v3+1), nil)))
			nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(v10)), nox_xxx_clientOrderCreature_4C2A60, sub_4C27F0, nil)
			*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*8)) = uint32(i)
			v8 += v3 + 2
		}
	}
	nox_xxx_clientPlaySoundSpecial_452D80(791, 100)
}
func sub_4C27F0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1     = (*uint32)(win.C())
		result int32
		v2     *uint16
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     *int16
		v10    int32
		v11    int32
		v12    int32
	)
	if dword_5d4594_1321208 == 0 {
		dword_5d4594_1321208 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("CarnivorousPlant")))
	}
	if dword_5d4594_1321204 != 0 || (func() bool {
		result = 1
		return *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)) != 1
	}()) {
		v2 = nox_strman_loadString_40F1D0(*(**byte)(memmap.PtrOff(0x587000, uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)))*4+184344)), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guisumn.c"), 446)
		nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(a1)), &v11, &v10)
		nox_xxx_drawGetStringSize_43F840(nil, v2, &v12, nil, 0)
		var mpos nox_point = nox_client_getMousePos_4309F0()
		nox_xxx_guiFontHeightMB_43F320(nil)
		v4 = int32((nox_xxx_screenWidth_587000_184452-uint32(v12))/2 + 1)
		if nox_xxx_wndPointInWnd_46AAB0(a1, mpos.x, mpos.y) {
			sub_4C2A00(v11+v4, v10+3, int32(nox_color_yellow_2589772), int32(nox_color_black_2650656), (*int16)(unsafe.Pointer(v2)))
			if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)) != *memmap.PtrUint32(0x587000, 184552) {
				*memmap.PtrUint32(0x587000, 184552) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8))
				nox_xxx_clientPlaySoundSpecial_452D80(920, 100)
				return 1
			}
			return 1
		}
		if dword_5d4594_1321204 != 0 {
			if sub_4C2DD0(dword_5d4594_1321204) != 0 {
				sub_4C2A00(v11+v4, v10+3, int32(nox_color_white_2523948), int32(nox_color_black_2650656), (*int16)(unsafe.Pointer(v2)))
				return 1
			}
			v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)))
			if v5 != 4 && v5 != 5 {
				sub_4C2A00(v11+v4, v10+3, int32(nox_color_white_2523948), int32(nox_color_black_2650656), (*int16)(unsafe.Pointer(v2)))
				return 1
			}
			v6 = int32(*memmap.PtrUint32(0x85B3FC, 956))
			v9 = (*int16)(unsafe.Pointer(v2))
			v8 = int32(nox_color_black_2650656)
		} else {
			v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8)))
			if v7 != 4 && v7 != 5 {
				sub_4C2A00(v11+v4, v10+3, int32(nox_color_blue_2650684), int32(nox_color_black_2650656), (*int16)(unsafe.Pointer(v2)))
				return 1
			}
			v9 = (*int16)(unsafe.Pointer(v2))
			if sub_4C2E00() == 0 {
				sub_4C2A00(v11+v4, v10+3, *memmap.PtrInt32(0x85B3FC, 956), int32(nox_color_black_2650656), (*int16)(unsafe.Pointer(v2)))
				return 1
			}
			v6 = int32(nox_color_blue_2650684)
			v8 = int32(nox_color_black_2650656)
		}
		sub_4C2A00(v11+v4, v10+3, v6, v8, v9)
		return 1
	}
	return int(result)
}
func sub_4C2CE0(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	var (
		v0 *wchar2_t
		v2 *wchar2_t
		v3 *wchar2_t
	)
	switch *memmap.PtrUint32(0x587000, 184448) {
	case 3:
		v3 = nox_strman_loadString_40F1D0(internCStr("ccs:GUARD"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guisumn.c"), 785)
		nox_xxx_cursorSetTooltip_4776B0(v3)
	case 4:
		v2 = nox_strman_loadString_40F1D0(internCStr("ccs:ESCORT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guisumn.c"), 782)
		nox_xxx_cursorSetTooltip_4776B0(v2)
		return 1
	case 5:
		v0 = nox_strman_loadString_40F1D0(internCStr("ccs:HUNT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guisumn.c"), 788)
		nox_xxx_cursorSetTooltip_4776B0(v0)
		return 1
	}
	return 1
}
