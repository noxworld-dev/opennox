package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_4710B0(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	var (
		v0     *wchar2_t
		v1     *wchar2_t
		v2     *wchar2_t
		v3     int32
		v4     *wchar2_t
		v5     *wchar2_t
		result int32
		v7     *wchar2_t
	)
	v0 = (*wchar2_t)(unsafe.Pointer(uintptr(sub_4615C0())))
	v1 = v0
	if v0 != nil {
		v2 = nox_xxx_clientAskInfoMb_4BF050((*client.Drawable)(unsafe.Pointer(v0)))
		nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1091968)), v2)
		if *(*wchar2_t)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(wchar2_t(0))*58))&0xC != 0 {
			v3 = int32(*memmap.PtrUint32(0x5D4594, 1096292))
			if *memmap.PtrUint32(0x5D4594, 1096292) == 0 {
				v3 = nox_xxx_getNameId_4E3AA0(internCStr("Quiver"))
				*memmap.PtrUint32(0x5D4594, 1096292) = uint32(v3)
			}
			v4 = (*wchar2_t)(unsafe.Pointer(uintptr(sub_461600(v3))))
			if v4 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1091968)), internWStr("\n"))
				v5 = nox_xxx_clientAskInfoMb_4BF050((*client.Drawable)(unsafe.Pointer(v4)))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1091968)), v5)
			}
		}
		nox_xxx_cursorSetTooltip_4776B0((*wchar2_t)(memmap.PtrOff(0x5D4594, 1091968)))
		result = 1
	} else {
		v7 = nox_strman_loadString_40F1D0(internCStr("ToolTipCurWeapon"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 881)
		nox_xxx_cursorSetTooltip_4776B0(v7)
		result = 1
	}
	return int(result)
}
func sub_471160(a1 *gui.Window, a2, a3, a4, a5 int) {
	nox_windows_arr_1093036[5].Win = nox_window_new(a1, 1032, a2, a3, a4, a5, nil)
	nox_windows_arr_1093036[6].Win = nox_window_new(a1, 1032, a2-17, a3-15, 15, 15, nil)
	nox_window_set_all_funcs(nox_windows_arr_1093036[5].Win, nil, sub_471250, nil)
	v5 := nox_strman_loadString_40F1D0(internCStr("ToolTipCharges"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 921)
	nox_xxx_wndWddSetTooltip_46B000(nox_windows_arr_1093036[5].Win.DrawData(), v5)
	nox_window_set_all_funcs(nox_windows_arr_1093036[6].Win, nil, sub_471450, nil)
	v6 := nox_strman_loadString_40F1D0(internCStr("ToolTipCharges"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 925)
	nox_xxx_wndWddSetTooltip_46B000(nox_windows_arr_1093036[6].Win.DrawData(), v6)
	nox_windows_arr_1093036[5].Win.WidgetData = unsafe.Pointer(uintptr(5))
	nox_windows_arr_1093036[6].Win.WidgetData = unsafe.Pointer(uintptr(6))
}
func nox_xxx_guiHealthManaInit_4714E0() int32 {
	var (
		v1  int32
		v2  *uint8
		v3  *wchar2_t
		v5  *wchar2_t
		v6  *wchar2_t
		v8  *uint32
		v9  *byte
		v10 *wchar2_t
		v11 *wchar2_t
		v12 *uint32
		v13 *byte
		v14 *wchar2_t
		v15 [32]byte
	)
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 {
		return 0
	}
	dword_5d4594_1096288 = nox_xxx_guiFontPtrByName_43F360(internCStr("small"))
	dword_5d4594_1096264 = 0
	dword_5d4594_1096256 = 0
	dword_5d4594_1096260 = 0
	*memmap.PtrUint32(0x5D4594, 1091908) = 0
	*memmap.PtrUint32(0x5D4594, 1091912) = 0
	*memmap.PtrUint32(0x5D4594, 1091916) = uint32(nox_win_width)
	*memmap.PtrUint32(0x5D4594, 1091920) = uint32(nox_win_height)
	*memmap.PtrUint32(0x5D4594, 1091940) = uint32(nox_win_width)
	*memmap.PtrUint32(0x5D4594, 1091944) = uint32(nox_win_height)
	*memmap.PtrUint32(0x5D4594, 1091924) = 0
	*memmap.PtrUint32(0x5D4594, 1091928) = 0
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1092996))
	var v2i int32 = 0
	for {
		nox_sprintf(&v15[0], internCStr("HealthMana%d"), func() int32 {
			p := &v1
			*p++
			return *p
		}())
		*(*uint32)(unsafe.Pointer(v2)) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(&v15[0]))))
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 4))
		v2i++
		if v2i >= 10 {
			break
		}
	}
	if *memmap.PtrUint32(0x5D4594, 1096268) == 0 {
		*memmap.PtrUint32(0x5D4594, 1096268) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("RedPotion")))
		dword_5d4594_1096272 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BluePotion")))
		dword_5d4594_1096276 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CurePoisonPotion")))
		dword_5d4594_1096280 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("RedApple")))
		dword_5d4594_1096284 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Meat")))
	}
	dword_5d4594_1090276 = nox_window_new(nil, 136, int(nox_win_width)-91, int(nox_win_height)-201, 91, 201, nil)
	nox_xxx_wndSetIcon_46AE60(dword_5d4594_1090276, *memmap.PtrInt32(0x5D4594, 1092996))
	dword_5d4594_1091364 = uint32(uintptr(unsafe.Pointer(nox_window_new(dword_5d4594_1090276, 8, 6, 166, 28, 30, nil))))
	nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(dword_5d4594_1091364)), nox_xxx_guiBottleSlotProc_471B90, nox_xxx_guiBottleSlotDrawFn_471A80, nil)
	v3 = nox_strman_loadString_40F1D0(internCStr("CurePoisonSlotTT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 1029)
	nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(unsafe.Add(dword_5d4594_1091364, 36)), v3)
	*(*uint32)(unsafe.Add(dword_5d4594_1091364, 32)) = 2
	*memmap.PtrUint16(0x5D4594, 1091384) = 0
	var t4 *client.ObjectType = nox_get_thing(int32(dword_5d4594_1096276))
	if t4 != nil {
		nox_drawable_link_thing((*client.Drawable)(memmap.PtrOff(0x5D4594, 1091388)), t4.Field_1c)
		*memmap.PtrUint32(0x5D4594, 1091368) = uint32(uintptr(memmap.PtrOff(0x5D4594, 1091388)))
		if true {
			*memmap.PtrUint32(0x5D4594, 1091508) |= 0x40000000
		}
	} else {
		*memmap.PtrUint32(0x5D4594, 1091368) = 0
	}
	*memmap.PtrUint32(0x5D4594, 1091380) = dword_5d4594_1096276
	dword_5d4594_1090292 = uint32(uintptr(unsafe.Pointer(nox_window_new(dword_5d4594_1090276, 8, 34, 166, 28, 30, nil))))
	nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(dword_5d4594_1090292)), nox_xxx_guiBottleSlotProc_471B90, nox_xxx_guiBottleSlotDrawFn_471A80, nil)
	v5 = nox_strman_loadString_40F1D0(internCStr("HealthSlotTT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 1060)
	nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(unsafe.Add(dword_5d4594_1090292, 36)), v5)
	*(*uint32)(unsafe.Add(dword_5d4594_1090292, 32)) = 0
	*memmap.PtrUint16(0x5D4594, 1090312) = 0
	*memmap.PtrUint32(0x5D4594, 1090296) = 0
	*memmap.PtrUint32(0x5D4594, 1090308) = 0
	if int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))) != 0 {
		dword_5d4594_1090828 = uint32(uintptr(unsafe.Pointer(nox_window_new(dword_5d4594_1090276, 8, 62, 166, 28, 30, nil))))
		nox_window_set_all_funcs((*gui.Window)(unsafe.Pointer(dword_5d4594_1090828)), nox_xxx_guiBottleSlotProc_471B90, nox_xxx_guiBottleSlotDrawFn_471A80, nil)
		v6 = nox_strman_loadString_40F1D0(internCStr("ManaSlotTT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 1083)
		nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(unsafe.Add(dword_5d4594_1090828, 36)), v6)
		*(*uint32)(unsafe.Add(dword_5d4594_1090828, 32)) = 1
		*memmap.PtrUint16(0x5D4594, 1090848) = 0
		var t7 *client.ObjectType = nox_get_thing(int32(dword_5d4594_1096272))
		if t7 != nil {
			nox_drawable_link_thing((*client.Drawable)(memmap.PtrOff(0x5D4594, 1090852)), t7.Field_1c)
			*memmap.PtrUint32(0x5D4594, 1090832) = uint32(uintptr(memmap.PtrOff(0x5D4594, 1090852)))
			if true {
				*memmap.PtrUint32(0x5D4594, 1090972) |= 0x40000000
			}
		} else {
			*memmap.PtrUint32(0x5D4594, 1090832) = 0
		}
		*memmap.PtrUint32(0x5D4594, 1090844) = dword_5d4594_1096272
		*memmap.PtrPtr(0x5D4594, 1091900) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("PoisonTube")))
		v8 = (*uint32)(unsafe.Pointer(nox_window_new(dword_5d4594_1090276, 136, 0, 0, 91, 159, nil)))
		v9 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("HealthManaTubes"))))
		nox_xxx_wndSetIcon_46AE60(int32(uintptr(unsafe.Pointer(v8))), int32(uintptr(unsafe.Pointer(v9))))
		nox_windows_arr_1093036[1].Win = nox_window_new((*gui.Window)(unsafe.Pointer(v8)), 8, 60, 34, 25, 125, nil)
		nox_window_set_all_funcs(nox_windows_arr_1093036[1].Win, nox_xxx_guiHealthManaTubeProc_472100, nox_xxx_guiHealthManaTubeDraw_471D10, nil)
		v10 = nox_strman_loadString_40F1D0(internCStr("ToolTipMana"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 1122)
		nox_xxx_wndWddSetTooltip_46B000(nox_windows_arr_1093036[1].Win.DrawData(), v10)
		nox_windows_arr_1093036[1].Win.WidgetData = unsafe.Pointer(uintptr(1))
		nox_windows_arr_1093036[0].Win = nox_window_new((*gui.Window)(unsafe.Pointer(v8)), 8, 34, 34, 25, 125, nil)
		nox_window_set_all_funcs(nox_windows_arr_1093036[0].Win, nox_xxx_guiHealthManaTubeProc_472100, nox_xxx_guiHealthManaTubeDraw_471D10, nil)
		v11 = nox_strman_loadString_40F1D0(internCStr("ToolTipHealth"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 1135)
		nox_xxx_wndWddSetTooltip_46B000(nox_windows_arr_1093036[0].Win.DrawData(), v11)
		nox_windows_arr_1093036[0].Win.WidgetData = nil
		nox_windows_arr_1093036[2].Win = nox_window_new(nil, 8, 0, 0, 0, 0, nil)
		nox_window_set_all_funcs(nox_windows_arr_1093036[2].Win, nil, nox_xxx_drawHealthManaBar_471C00, nil)
		nox_windows_arr_1093036[2].Win.WidgetData = nil
		nox_windows_arr_1093036[3].Win = nox_window_new(nil, 8, 0, 0, 0, 0, nil)
		nox_window_set_all_funcs(nox_windows_arr_1093036[3].Win, nil, nox_xxx_drawHealthManaBar_471C00, nil)
		nox_windows_arr_1093036[3].Win.WidgetData = unsafe.Pointer(uintptr(1))
		*memmap.PtrUint32(0x5D4594, 1093176) = 1
	} else {
		*memmap.PtrPtr(0x5D4594, 1091900) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("WarriorPoisonTube")))
		v12 = (*uint32)(unsafe.Pointer(nox_window_new(dword_5d4594_1090276, 136, 0, 0, 91, 159, nil)))
		v13 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("WarriorHealthTube"))))
		nox_xxx_wndSetIcon_46AE60(int32(uintptr(unsafe.Pointer(v12))), int32(uintptr(unsafe.Pointer(v13))))
		nox_windows_arr_1093036[0].Win = nox_window_new((*gui.Window)(unsafe.Pointer(v12)), 8, 34, 34, 25, 125, nil)
		nox_window_set_all_funcs(nox_windows_arr_1093036[0].Win, nox_xxx_guiHealthManaTubeProc_472100, nox_xxx_guiHealthManaTubeDraw_471D10, nil)
		v14 = nox_strman_loadString_40F1D0(internCStr("ToolTipHealth"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 1173)
		nox_xxx_wndWddSetTooltip_46B000(nox_windows_arr_1093036[0].Win.DrawData(), v14)
		nox_windows_arr_1093036[0].Win.WidgetData = nil
		nox_windows_arr_1093036[2].Win = nox_window_new(nil, 24, 0, 0, 0, 0, nil)
		nox_window_set_all_funcs(nox_windows_arr_1093036[2].Win, nil, nox_xxx_drawHealthManaBar_471C00, nil)
		nox_windows_arr_1093036[2].Win.WidgetData = nil
	}
	sub_472280()
	nox_xxx_guiHealthManaColorInit_470B00()
	if noxflags.HasGame(4096) {
		dword_5d4594_1096252 = 1
	} else {
		dword_5d4594_1096252 = 0
		nox_window_set_hidden(nox_windows_arr_1093036[2].Win, 1)
		nox_window_set_hidden(nox_windows_arr_1093036[3].Win, 1)
	}
	return 1
}
func nox_xxx_guiHealthManaTubeDraw_471D10(win *gui.Window, draw *gui.WindowData) int {
	var (
		xLeft = int32(uintptr(win.C()))
		v1    *uint32
		v2    int32
		v3    *uint8
		v4    int32
		v6    int32
		v7    *int32
		v8    int32
		v9    *uint8
		v10   int32
		v11   int32
		v12   int32
		v13   int32
		v14   int32
		v15   int32
		v16   int32
		yTop  int32
		v18   int32
		v19   int32
		v20   *uint8
		v21   *uint8
	)
	v1 = (*uint32)(xLeft)
	v18 = int32(*(*uint32)(unsafe.Add(xLeft, 32)))
	v2 = v18
	v3 = (*uint8)(unsafe.Pointer(&nox_windows_arr_1093036[v18]))
	v20 = v3
	if v18 == 0 && dword_5d4594_1096264 != 0 {
		nox_client_wndGetPosition_46AA60(dword_5d4594_1090276, &xLeft, &yTop)
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1091900)), xLeft, yTop)
	}
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(v1)), &xLeft, &yTop)
	xLeft += 5
	if get_dword_5d4594_3799468() != 0 {
		nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, 15, 125)
	}
	v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2))))
	if v4 != 0 {
		v6 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1))) * 125 / uint32(v4))
		nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, 15, 125-v6)
		nox_client_drawSetColor_434460(int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3)))))
		nox_client_drawEnableAlpha_434560(1)
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop-v6+125, 15, v6)
		nox_client_drawEnableAlpha_434560(0)
		nox_client_drawAddPoint_49F500(xLeft, yTop-v6+125)
		nox_xxx_rasterPointRel_49F570(14, 0)
		nox_client_drawLineFromPoints_49E4B0()
		if v2 < 2 && nox_client_renderBubbles_80844 == 1 {
			v19 = 64
			v7 = mem_getI32Ptr(0x5D4594, uint32(v2*1536)+1093188)
			v21 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v2*1536)+1093188))
			for {
				if *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*2)) != 0 {
					v8 = *((*int32)(unsafe.Add(unsafe.Pointer(v7), -int(4*1)))) >> 4
					if v8 >= 125-v6 {
						if dword_5d4594_1096264 != 0 {
							nox_client_drawSetColor_434460(int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*3)))))
						} else {
							nox_client_drawSetColor_434460(*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*3)))
						}
						if *v7 <= 2 {
							nox_client_drawRectFilledOpaque_49CE30(xLeft+*((*int32)(unsafe.Add(unsafe.Pointer(v7), -int(4*2)))), yTop+v8, *v7, *v7)
						} else {
							sub_4720C0(xLeft+*((*int32)(unsafe.Add(unsafe.Pointer(v7), -int(4*2)))), yTop+v8)
						}
						*((*int32)(unsafe.Add(unsafe.Pointer(v7), -int(4*1)))) -= *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1))
					} else {
						*(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*2)) = 0
					}
					v2 = v18
				}
				v7 = (*int32)(unsafe.Add(unsafe.Pointer(v7), 4*6))
				v19--
				if v19 == 0 {
					break
				}
			}
			if v6 > 1 {
				v9 = v21
				v10 = 64
				for {
					if *((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*2))) == 0 {
						v11 = nox_common_randomIntMinMax_415FF0(1, 100, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 668)
						if v11 >= 80 {
							*(*uint32)(unsafe.Pointer(v9)) = uint32(bool2int32(v11 >= 95) + 2)
						} else {
							*(*uint32)(unsafe.Pointer(v9)) = 1
						}
						v12 = nox_common_randomIntMinMax_415FF0(0, 14, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 676)
						v13 = int32(*(*uint32)(unsafe.Pointer(v9)))
						*((*uint32)(unsafe.Add(unsafe.Pointer(v9), -int(4*2)))) = uint32(v12)
						if v13+v12 > 15 {
							*((*uint32)(unsafe.Add(unsafe.Pointer(v9), -int(4*2)))) = uint32(15 - v13)
						}
						*((*uint32)(unsafe.Add(unsafe.Pointer(v9), -int(4*1)))) = uint32((125 - v13) * 16)
						*((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*1))) = uint32(nox_common_randomIntMinMax_415FF0(4, 48, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 684))
						*((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*2))) = 1
						*((*uint8)(unsafe.Pointer(&v19))) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, 64, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guimeter.c"), 688)))
						if v18 != 0 {
							v14 = int32(nox_color_rgb_4344A0(v19, v19, math.MaxUint8))
						} else {
							v14 = int32(nox_color_rgb_4344A0(math.MaxUint8, v19, v19))
						}
						*((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*3))) = uint32(v14)
					}
					v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 24))
					v10--
					if v10 == 0 {
						break
					}
				}
				v2 = v18
			}
		}
		if v2 == 0 {
			if dword_5d4594_1096260 <= 0 {
				v16 = int32(dword_5d4594_1096256 >> 3)
			} else {
				v15 = int32(dword_5d4594_1096260 + dword_5d4594_1096256)
				dword_5d4594_1096256 = uint32(v15)
				dword_5d4594_1096260--
				v16 = v15 >> 3
				if v16 >= 10 {
					v16 = 0
					dword_5d4594_1096256 = 0
				}
			}
			nox_xxx_wndSetIcon_46AE60(dword_5d4594_1090276, int32(*memmap.PtrUint32(0x5D4594, uintptr(v16*4)+1092996)))
		}
		sub_472080()
		return 1
	} else {
		nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, 15, 125)
		return 1
	}
}
