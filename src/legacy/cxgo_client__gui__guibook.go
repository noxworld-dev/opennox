package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var obj_5d4594_1046620 types.Pointf

func nox_xxx_bookShowMB_45AD70(a1 int32) {
	var (
		result uint32
		v2     *wchar2_t
	)
	result = uint32(nox_xxx_guiCursor_477600())
	if result != 0 {
		return
	}
	if nox_xxx_playerAnimCheck_4372B0() != 0 && (func() uint32 {
		result = uint32(bool2int32(noxflags.HasGame(2048)))
		return result
	}()) != 0 {
		return
	}
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 || nox_xxx_guiSpellSortList_45ADF0(int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251)))) != 0 {
		nox_xxx_book_45B010(a1)
	} else {
		v2 = nox_strman_loadString_40F1D0(internCStr("EmptyBook"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 377)
		nox_xxx_printCentered_445490(v2)
		nox_xxx_clientPlaySoundSpecial_452D80(925, 100)
	}
}
func nox_xxx_bookDrawList_45BD40(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1          = int32(uintptr(win.C()))
		v1          int32
		v2          int32
		v3          int32
		v4          int32
		v5          int32
		v6          int32
		v7          int32
		v8          int32
		v9          int8
		v10         *uint16
		v11         *int16
		v12         *uint16
		v13         *uint16
		v14         int32
		v15         *wchar2_t
		v16         int32
		v17         int32
		v18         int32
		v19         *wchar2_t
		v20         int32
		v21         *wchar2_t
		v22         *wchar2_t
		v23         int32
		v24         *uint16
		v25         int32
		v26         *uint16
		v27         int32
		v28         *uint16
		v29         *uint16
		v30         int32
		v31         int32
		v32         int32
		v33         *uint16
		v34         int32
		v35         *uint16
		v36         *uint16
		v37         int32
		v38         int16
		v39         *uint16
		v40         int32
		v41         int32
		v42         *uint16
		v43         int32
		v44         int32
		v45         *wchar2_t
		v46         int32
		v47         int32
		v48         *uint16
		v49         *uint16
		v50         *uint16
		v51         *uint16
		v52         *wchar2_t
		v53         *uint16
		v55         int32
		v56         int32
		v57         int32
		v58         int32
		v59         int32
		v60         int32
		v61         int32
		v62         int32
		v63         int32
		v64         int32
		v65         int32
		v66         int32
		v67         int32
		v68         int32
		WideCharStr [4]wchar2_t
		v70         int32
		v71         [256]wchar2_t
	)
	nox_gui_getWindowOffs_46AA20((*gui.Window)(unsafe.Pointer(uintptr(a1))), (*uint32)(unsafe.Pointer(&v66)), (*uint32)(unsafe.Pointer(&v67)))
	v1 = v66 - 24
	v2 = v67 - 76
	v3 = nox_xxx_guiFontHeightMB_43F320(nil)
	dword_5d4594_1046656 = uint32(v3 + 2)
	nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x5D4594, 1046880))
	nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(*memmap.PtrPtr(0x5D4594, 1046856)), v1, v2)
	if dword_5d4594_1046872 != 0 {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(*memmap.PtrPtr(0x5D4594, 1046660)), v1, v2)
	} else {
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(*memmap.PtrPtr(0x5D4594, 1046644)), v1, v2)
	}
	if dword_5d4594_1046868 == 3 {
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*(*int32)(unsafe.Pointer(&dword_5d4594_1046928)), v1, v2)
		goto LABEL_75
	}
	if dword_5d4594_1046868 == 2 {
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*(*int32)(unsafe.Pointer(&dword_5d4594_1046924)), v1, v2)
		goto LABEL_75
	}
	if nox_xxx_aNox_cfg_0_587000_132132 != 0 {
		v4 = int32(dword_5d4594_1046936)
		*(*uint32)(unsafe.Pointer(&WideCharStr[0])) = 141/dword_5d4594_1046656 - 1
		if dword_5d4594_1046936 == 0 {
			nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1046944))))), 1)
			v4 = int32(dword_5d4594_1046936)
		}
		v5 = 0
		v6 = v66 + 78
		v7 = v67 + 19
		if *(*uint32)(unsafe.Pointer(&WideCharStr[0]))*2 > 0 {
			for {
				v8 = int32(uint32(v5) + *(*uint32)(unsafe.Pointer(&WideCharStr[0]))*2*uint32(v4))
				if uint32(v8) >= uint32(*memmap.PtrInt32(0x5D4594, 1047508))-dword_5d4594_1047512 {
					break
				}
				if uint32(v5) == *(*uint32)(unsafe.Pointer(&WideCharStr[0])) {
					v6 = v66 + 199
					v7 = v67 + 19
				}
				nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x5D4594, 1046880))
				v9 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(dword_5d4594_1047516)), 2251)))
				if dword_5d4594_1046868 == 1 {
					if int32(v9) == 2 && !nox_xxx_spellIsEnabled_424B70(int32(*memmap.PtrUint32(0x5D4594, uintptr(v8*4)+1046960)+74)) {
						nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x5D4594, 1046884))
					}
					v10 = (*uint16)(unsafe.Pointer(uintptr(nox_xxx_guiCreatureGetName_427240(int32(*memmap.PtrUint32(0x5D4594, uintptr(v8*4)+1046960))))))
					nox_xxx_drawGetStringSize_43F840(nil, v10, &v65, nil, 128)
					v62 = v7
					v60 = v6 - v65/2
					v11 = (*int16)(unsafe.Pointer(uintptr(nox_xxx_guiCreatureGetName_427240(int32(*memmap.PtrUint32(0x5D4594, uintptr(v8*4)+1046960))))))
				} else if int32(v9) != 0 {
					if !nox_xxx_spellIsEnabled_424B70(int32(*memmap.PtrUint32(0x5D4594, uintptr(v8*4)+1046960))) {
						nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x5D4594, 1046884))
					}
					v13 = nox_xxx_spellTitle_424930(int32(*memmap.PtrUint32(0x5D4594, uintptr(v8*4)+1046960)))
					nox_xxx_drawGetStringSize_43F840(nil, v13, &v65, nil, 128)
					v62 = v7
					v60 = v6 - v65/2
					v11 = (*int16)(unsafe.Pointer(nox_xxx_spellTitle_424930(int32(*memmap.PtrUint32(0x5D4594, uintptr(v8*4)+1046960)))))
				} else {
					v12 = nox_xxx_abilityGetName_0_425260(int32(*memmap.PtrUint32(0x5D4594, uintptr(v8*4)+1046960)))
					nox_xxx_drawGetStringSize_43F840(nil, v12, &v65, nil, 128)
					v62 = v7
					v60 = v6 - v65/2
					v11 = (*int16)(unsafe.Pointer(nox_xxx_abilityGetName_0_425260(int32(*memmap.PtrUint32(0x5D4594, uintptr(v8*4)+1046960)))))
				}
				nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer(v11)), v60, v62)
				v7 += int32(dword_5d4594_1046656)
				if uint32(func() int32 {
					p := &v5
					*p++
					return *p
				}()) >= *(*uint32)(unsafe.Pointer(&WideCharStr[0]))*2 {
					break
				}
				v4 = int32(dword_5d4594_1046936)
			}
		}
		goto LABEL_75
	}
	if dword_5d4594_1046868 == 1 {
		v14 = v67 + 51
		v15 = nox_strman_loadString_40F1D0(internCStr("Size"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 978)
		nox_swprintf(&v71[0], internWStr("%s "), v15)
		v16 = int32(nox_xxx_guideGetUnitSize_427460(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)))) - 1
		if v16 != 0 {
			v17 = v16 - 1
			if v17 != 0 {
				if v17 == 2 {
					v18 = 76
					v19 = nox_strman_loadString_40F1D0(internCStr("Large"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 995)
					nox_wcscat(&v71[0], v19)
					v20 = 0
				} else {
					v18 = int32(*(*uint32)(unsafe.Pointer(&WideCharStr[0])))
					v20 = int32(*(*uint32)(unsafe.Pointer(&WideCharStr[0])))
				}
			} else {
				v18 = 38
				v21 = nox_strman_loadString_40F1D0(internCStr("Medium"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 989)
				nox_wcscat(&v71[0], v21)
				v20 = 0
			}
		} else {
			v18 = 38
			v22 = nox_strman_loadString_40F1D0(internCStr("Small"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 983)
			nox_wcscat(&v71[0], v22)
			v20 = 19
		}
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(dword_5d4594_1047516)), 2251))) == 2 && (*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(dword_5d4594_1047516)), 4232)) != 0 || noxflags.HasGame(0x2000) && !noxflags.HasGame(4096)) {
			nox_xxx_drawGetStringSize_43F840(nil, &v71[0], &v70, nil, 0)
			nox_xxx_drawStringWrap_43FAF0(nil, &v71[0], (108-v70)/2+v66+24, v14, 128, 0)
		}
		v23 = v14 + v3 + 2
		v24 = (*uint16)(unsafe.Pointer(uintptr(nox_xxx_guiCreatureGetName_427240(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960))))))
		nox_xxx_bookGetStringSize_43FA80(nil, v24, &v70, &v68, 108)
		if v68 <= v3 {
			v25 = (108-v70)/2 + v66 + 24
		} else {
			v25 = v66 + 24
		}
		v55 = v25
		v26 = (*uint16)(unsafe.Pointer(uintptr(nox_xxx_guiCreatureGetName_427240(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960))))))
		nox_xxx_bookDrawString_43FA80_43FD80(nil, v26, v55, v23, 128, 0)
		v63 = v23 + v20 + v68 + 2
		v61 = (108-v18)/2 + v66 + 24
		v27 = nox_xxx_bookGetCreatureImg_427400(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)))
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(v27))), v61, v63)
		v28 = (*uint16)(unsafe.Pointer(uintptr(nox_xxx_guideGetDescById_4272E0(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960))))))
		v29 = v28
		v30 = v67 + 52
		if v28 != nil {
			nox_xxx_drawGetStringSize_43F840(nil, v28, nil, (*int32)(unsafe.Pointer(&WideCharStr[0])), 92)
			v31 = int32(*(*uint32)(unsafe.Pointer(&WideCharStr[0])))
			v32 = v66 + 153
			v37 = (141-v31)/2 + v67 + 17
			if v37 > v30 {
				v37 = v30
			}
			nox_xxx_drawStringWrap_43FAF0(nil, v29, v32, v37, 92, 0)
			goto LABEL_75
		}
	} else {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(dword_5d4594_1047516)), 2251))) == 0 {
			sub_425450(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)))
			v33 = nox_xxx_abilityGetName_0_425260(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)))
			nox_xxx_bookGetStringSize_43FA80(nil, v33, &v70, &v68, 108)
			if v68 <= v3 {
				v34 = (108-v70)/2 + v66 + 24
			} else {
				v34 = v66 + 24
			}
			v58 = v67 + 53
			v56 = v34
			v35 = nox_xxx_abilityGetName_0_425260(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)))
			nox_xxx_bookDrawString_43FA80_43FD80(nil, v35, v56, v58, 128, 0)
			v36 = sub_4252F0(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)))
			v29 = v36
			v30 = v67 + 52
			if v36 == nil {
				goto LABEL_75
			}
			nox_xxx_drawGetStringSize_43F840(nil, v36, nil, (*int32)(unsafe.Pointer(&WideCharStr[0])), 92)
			v31 = int32(*(*uint32)(unsafe.Pointer(&WideCharStr[0])))
			v32 = v66 + 153
			v37 = (141-v31)/2 + v67 + 17
			if v37 > v30 {
				v37 = v30
			}
			nox_xxx_drawStringWrap_43FAF0(nil, v29, v32, v37, 92, 0)
			goto LABEL_75
		}
		v38 = int16(uint16(nox_xxx_spellFlags_424A70(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)))))
		v39 = nox_xxx_spellTitle_424930(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)))
		nox_xxx_bookGetStringSize_43FA80(nil, v39, &v65, &v68, 108)
		if v68 <= v3 {
			v40 = (108-v65)/2 + v66 + 24
		} else {
			v40 = v66 + 24
		}
		v41 = v67 + 53
		v59 = v67 + 53
		v57 = v40
		v42 = nox_xxx_spellTitle_424930(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)))
		nox_xxx_bookDrawString_43FA80_43FD80(nil, v42, v57, v59, 128, 0)
		v43 = v41 + v68 + 2
		v44 = nox_xxx_spellManaCost_4249A0(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)), 1)
		v45 = nox_strman_loadString_40F1D0(internCStr("ManaCost"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1115)
		nox_swprintf(&v71[0], internWStr("%s "), v45)
		if v44 != 0 {
			nox_itow(v44, &WideCharStr[0], 10)
			nox_wcscat(&v71[0], &WideCharStr[0])
		} else if nox_xxx_spellHasFlags_424A50(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)), 0x800000) {
			nox_wcscat(&v71[0], internWStr("0"))
		} else {
			nox_wcscat(&v71[0], internWStr("*"))
		}
		nox_xxx_drawGetStringSize_43F840(nil, &v71[0], &v65, nil, 0)
		v46 = v43 + 2
		nox_xxx_drawStringWrap_43FAF0(nil, &v71[0], (108-v65)/2+v66+24, v46, 128, 0)
		v47 = v46 + v3 + 2
		if int32(v38)&0x100 != 0 {
			v48 = nox_strman_loadString_40F1D0(internCStr("SpellInstant"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1173)
			nox_xxx_drawGetStringSize_43F840(nil, v48, &v65, nil, 0)
			nox_xxx_drawStringWrap_43FAF0(nil, v48, (108-v65)/2+v66+24, v47, 128, 0)
			v47 += v3
		}
		if int32(v38)&4 != 0 {
			v49 = nox_strman_loadString_40F1D0(internCStr("SpellTargeted"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1181)
			nox_xxx_drawGetStringSize_43F840(nil, v49, &v65, nil, 0)
			nox_xxx_drawStringWrap_43FAF0(nil, v49, (108-v65)/2+v66+24, v47, 128, 0)
			v47 += v3
		}
		if int32(v38)&8 != 0 {
			v50 = nox_strman_loadString_40F1D0(internCStr("SpellAtLocation"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1189)
			nox_xxx_drawGetStringSize_43F840(nil, v50, &v65, nil, 0)
			nox_xxx_drawStringWrap_43FAF0(nil, v50, (108-v65)/2+v66+24, v47, 128, 0)
			v47 += v3
		}
		if int32(v38)&0x20 != 0 {
			v51 = nox_strman_loadString_40F1D0(internCStr("SpellHostile"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1197)
			nox_xxx_drawGetStringSize_43F840(nil, v51, &v65, nil, 0)
			nox_xxx_drawStringWrap_43FAF0(nil, v51, (108-v65)/2+v66+24, v47, 128, 0)
			v47 += v3
		}
		v64 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(dword_5d4594_1047516+*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)*4)), 3696)))
		v52 = nox_strman_loadString_40F1D0(internCStr("PowerLevel"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1206)
		nox_swprintf(&v71[0], v52, v64)
		nox_xxx_drawGetStringSize_43F840(nil, &v71[0], &v65, nil, 0)
		nox_xxx_drawStringWrap_43FAF0(nil, &v71[0], (108-v65)/2+v66+24, v3+v47, 128, 0)
		v53 = nox_xxx_spellDescription_424A30(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)))
		v29 = v53
		v30 = v67 + 52
		if v53 != nil {
			nox_xxx_drawGetStringSize_43F840(nil, v53, nil, (*int32)(unsafe.Pointer(&WideCharStr[0])), 92)
			v32 = v66 + 153
			v37 = int32((141-*(*uint32)(unsafe.Pointer(&WideCharStr[0])))/2 + uint32(v67) + 17)
			if v37 > v30 {
				v37 = v30
			}
			nox_xxx_drawStringWrap_43FAF0(nil, v29, v32, v37, 92, 0)
			goto LABEL_75
		}
	}
LABEL_75:
	if nox_xxx_aNox_cfg_0_587000_132132 == 0 && *(*int32)(unsafe.Pointer(&dword_5d4594_1046932)) >= *memmap.PtrInt32(0x5D4594, 1047508)-*(*int32)(unsafe.Pointer(&dword_5d4594_1047512))-1 {
		nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1046948))))), 1)
	}
	return 1
}
func nox_xxx_book_45CF00(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	a1 := (*uint32)(win.C())
	var (
		v1 *wchar2_t
		v3 *wchar2_t
		v4 *wchar2_t
	)
	if *a1 == 1310 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(dword_5d4594_1047516)), 2251))) == 0 {
			v3 = nox_strman_loadString_40F1D0(internCStr("ToolTipAbilityTab"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1640)
			nox_xxx_cursorSetTooltip_4776B0(v3)
			return 1
		}
		v4 = nox_strman_loadString_40F1D0(internCStr("ToolTipSpellTab"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1644)
		nox_xxx_cursorSetTooltip_4776B0(v4)
	} else if *a1 == 1320 {
		v1 = nox_strman_loadString_40F1D0(internCStr("ToolTipGuideTab"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1649)
		nox_xxx_cursorSetTooltip_4776B0(v1)
		return 1
	}
	return 1
}
func nox_xxx_bookDrawFn_45C7D0(win *gui.Window, draw *gui.WindowData) int {
	var (
		v1  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 float64
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int8
		v18 int8
		v19 int8
		v20 int8
		v21 int32
		v22 int32
		v23 int32
		v24 int32
		v25 int32
	)
	if dword_5d4594_1046652 != 0 {
		v1 = 3
	} else {
		v1 = 0
	}
	if dword_5d4594_1047520 == 0 {
		return 1
	}
	if dword_5d4594_1046648 != 0 && uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq())-dword_5d4594_1046648 < (gameFPS()*2) {
		return 1
	}
	nox_client_wndGetPosition_46AA60(win, (*uint32)(unsafe.Pointer(&v25)), (*uint32)(unsafe.Pointer(&v24)))
	if dword_5d4594_1046648 != 0 {
		v3 = 50
		for {
			v19 = int8(nox_common_randomIntMinMax_415FF0(3, 6, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1287))
			v17 = int8(nox_common_randomIntMinMax_415FF0(2, 5, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1286))
			v16 = nox_common_randomIntMinMax_415FF0(-10, -1, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1284)
			v15 = nox_common_randomIntMinMax_415FF0(-10, 10, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1283)
			v4 = nox_common_randomIntMinMax_415FF0(0, 30, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1282)
			v13 = v24 + v4
			v5 = nox_common_randomIntMinMax_415FF0(0, 30, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1281)
			nox_client_newScreenParticle_431540(v1, v25+v5, v13, v15, v16, 1, v17, v19, 2, 1)
			v3--
			if v3 == 0 {
				break
			}
		}
		nox_xxx_clientPlaySoundSpecial_452D80(795, 100)
		dword_5d4594_1046648 = 0
	}
	v6 = 2
	for {
		v20 = int8(nox_common_randomIntMinMax_415FF0(2, 4, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1331))
		v18 = int8(nox_common_randomIntMinMax_415FF0(1, 2, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1330))
		v7 = nox_common_randomIntMinMax_415FF0(0, 30, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1326)
		v14 = v24 + v7
		v8 = nox_common_randomIntMinMax_415FF0(0, 30, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 1325)
		nox_client_newScreenParticle_431540(v1, v25+v8, v14, 0, 0, 0, v18, v20, 1, 1)
		v6--
		if v6 == 0 {
			break
		}
	}
	v22 = v24
	v21 = v25
	if dword_5d4594_1046652 == 1 {
		v9 = int32(uintptr(unsafe.Pointer(nox_xxx_spellGetAbilityIcon_425310(*(*int32)(unsafe.Pointer(&dword_5d4594_1047524)), 0))))
	} else {
		v9 = int32(uintptr(nox_xxx_spellIcon_424A90(*(*int32)(unsafe.Pointer(&dword_5d4594_1047524)))))
	}
	nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(v9))), v21, v22)
	*(*float32)(unsafe.Pointer(&dword_5d4594_1046636)) = *(*float32)(unsafe.Pointer(&dword_5d4594_1046636)) + obj_5d4594_1046620.X
	*(*float32)(unsafe.Pointer(&dword_5d4594_1046640)) = *(*float32)(unsafe.Pointer(&dword_5d4594_1046640)) + obj_5d4594_1046620.Y
	if float64(*memmap.PtrInt32(0x5D4594, 1046668)) <= float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1046636))) && float64(*memmap.PtrInt32(0x5D4594, 1046672)) <= float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1046640))) {
		nox_xxx_book_45DBE0(*(*unsafe.Pointer)(memmap.PtrOff(0x5D4594, 1046676)), *(*int32)(unsafe.Pointer(&dword_5d4594_1047524)), *(*int32)(unsafe.Pointer(&dword_5d4594_1046852)))
		sub_45D810()
		goto LABEL_27
	}
	if float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1046636))) > float64(*mem_getFloatPtr(0x5D4594, *memmap.PtrUint32(0x5D4594, 1046628)*8+1046692)) {
		v10 = int32(*memmap.PtrUint32(0x5D4594, 1046628) + 1)
		*memmap.PtrUint32(0x5D4594, 1046628) = uint32(v10)
		if v10 < *memmap.PtrInt32(0x5D4594, 1046680) {
			if v10 <= *memmap.PtrInt32(0x5D4594, 1046680)-1 {
				obj_5d4594_1046620.X = *mem_getFloatPtr(0x5D4594, uint32(v10*8)+1046692) - *mem_getFloatPtr(0x5D4594, uint32(v10*8)+1046684)
				obj_5d4594_1046620.Y = *mem_getFloatPtr(0x5D4594, uint32(v10*8)+1046696) - *mem_getFloatPtr(0x5D4594, uint32(v10*8)+1046688)
				nox_xxx_utilNormalizeVector_509F20(&obj_5d4594_1046620)
				if nox_win_width < 1000 {
					if nox_win_width < 750 {
						v11 = 6.0
					} else {
						v11 = 8.0
					}
				} else {
					v11 = 10.0
				}
				obj_5d4594_1046620.X = float32(float64(obj_5d4594_1046620.X) * v11)
				obj_5d4594_1046620.Y = float32(float64(obj_5d4594_1046620.Y) * v11)
			}
			goto LABEL_27
		}
		nox_xxx_book_45DBE0(*(*unsafe.Pointer)(memmap.PtrOff(0x5D4594, 1046676)), *(*int32)(unsafe.Pointer(&dword_5d4594_1047524)), *(*int32)(unsafe.Pointer(&dword_5d4594_1046852)))
		sub_45D810()
	}
LABEL_27:
	v23 = int32(*(*float32)(unsafe.Pointer(&dword_5d4594_1046640)))
	v12 = int32(*(*float32)(unsafe.Pointer(&dword_5d4594_1046636)))
	nox_window_setPos_46A9B0(win, v12, v23)
	return 1
}
func sub_45D870() {
	var (
		v1  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int8
		v9  int32
		v10 int32
	)
	if dword_5d4594_1047520 != 0 {
		if dword_5d4594_1046652 != 1 {
			v1 = 0
		} else {
			v1 = 3
		}
		v9 = (int32(*memmap.PtrUint32(0x5D4594, 1046668)) - int32(*(*float32)(unsafe.Pointer(&dword_5d4594_1046636)))) / 50
		v10 = (int32(*memmap.PtrUint32(0x5D4594, 1046672)) - int32(*(*float32)(unsafe.Pointer(&dword_5d4594_1046640)))) / 50
		v3 = int32(*(*float32)(unsafe.Pointer(&dword_5d4594_1046636)))
		v4 = int32(*(*float32)(unsafe.Pointer(&dword_5d4594_1046640)))
		v5 = 50
		for {
			v8 = int8(nox_common_randomIntMinMax_415FF0(3, 4, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 2483))
			v7 = v4 - nox_common_randomIntMinMax_415FF0(0, 30, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 2479)
			v6 = nox_common_randomIntMinMax_415FF0(0, 30, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guibook.c"), 2478)
			nox_client_newScreenParticle_431540(v1, v3+v6, v7, 0, 0, 1, v8, 0, 0, 1)
			v3 += v9
			v4 += v10
			v5--
			if v5 == 0 {
				break
			}
		}
		nox_xxx_book_45DBE0(*(*unsafe.Pointer)(memmap.PtrOff(0x5D4594, 1046676)), *(*int32)(unsafe.Pointer(&dword_5d4594_1047524)), *(*int32)(unsafe.Pointer(&dword_5d4594_1046852)))
		sub_45D810()
	}
}
