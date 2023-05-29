package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"unsafe"
)

func nox_xxx_clientAskInfoMb_4BF050(a1p *nox_drawable) *wchar2_t {
	var (
		a1     *wchar2_t = (*wchar2_t)(unsafe.Pointer(a1p))
		v1     *int32
		v2     int32
		v3     *wchar2_t
		v4     *uint32
		v5     *wchar2_t
		result *wchar2_t
		v7     int32
		v8     int32
		v9     *wchar2_t
		v10    int32
		v11    *wchar2_t
		v12    *wchar2_t
		v13    int32
		v14    *wchar2_t
		v15    int32
		v16    *wchar2_t
		v17    *wchar2_t
		v18    int32
		v19    int32
		v20    *wchar2_t
		v21    *wchar2_t
		v22    *wchar2_t
		v23    *wchar2_t
		v24    int32
		v25    int32
		v26    *wchar2_t
		v27    *wchar2_t
		v28    *wchar2_t
		v29    int32
		v30    *wchar2_t
		v31    *wchar2_t
		v32    *wchar2_t
		v33    int32
		v34    *wchar2_t
		v35    *wchar2_t
	)
	*memmap.PtrUint16(0x5D4594, 1317000) = 0
	nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1319048)))
	v1 = (*int32)(unsafe.Pointer(a1))
	if a1 == nil {
		return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
	}
	v2 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*28))))
	if (uint32(v2) & 0x13001000) == 0 {
		if (v2 & 0x100) == 0 {
			result = nox_get_thing_pretty_name(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*27)))))
			if result != nil {
				return result
			}
			return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
		}
		v18 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*29))))
		*((*uint8)(unsafe.Pointer(&a1))) = 243
		if v18&1 != 0 {
			v19 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108))
			if v19 == 0 {
				*((*uint8)(unsafe.Pointer(&a1))) = 226
				*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&a1))), 1)))) = uint16(nox_xxx_netGetUnitCodeCli_578B00(int32(uintptr(unsafe.Pointer(v1)))))
				*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&a1))), unsafe.Sizeof((*wchar2_t)(nil))-1)) = 1
				*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108)) = 137
				goto LABEL_93
			}
			if v19 != 137 {
				if nox_strman_get_lang_code() != 6 {
					v22 = nox_strman_loadString_40F1D0(internCStr("BookOf"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ToolTip.c"), 292)
					nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr("%s "))), v22)
					v23 = nox_xxx_spellTitle_424930(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108)))
					nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v23)
					goto LABEL_93
				}
				v20 = nox_xxx_spellTitle_424930(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108)))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v20)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				v21 = nox_strman_loadString_40F1D0(internCStr("BookOf"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ToolTip.c"), 288)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v21)
				goto LABEL_93
			}
			return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
		}
		if v18&2 != 0 {
			v24 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108))
			if v24 == 0 {
				*((*uint8)(unsafe.Pointer(&a1))) = 226
				*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&a1))), 1)))) = uint16(nox_xxx_netGetUnitCodeCli_578B00(int32(uintptr(unsafe.Pointer(v1)))))
				*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&a1))), unsafe.Sizeof((*wchar2_t)(nil))-1)) = 2
				*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108)) = 41
				goto LABEL_93
			}
			if v24 == 41 {
				return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
			}
			if nox_strman_get_lang_code() == 3 || nox_strman_get_lang_code() == 5 {
				v27 = nox_strman_loadString_40F1D0(internCStr("LoreScroll"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ToolTip.c"), 313)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v27)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				v28 = (*wchar2_t)(unsafe.Pointer(uintptr(nox_xxx_guiCreatureGetName_427240(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108))))))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v28)
			} else {
				v25 = nox_xxx_guiCreatureGetName_427240(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108)))
				nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr("%s "))), v25)
				v26 = nox_strman_loadString_40F1D0(internCStr("LoreScroll"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ToolTip.c"), 320)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v26)
			}
		} else if v18&4 != 0 {
			v29 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108))
			if v29 == 0 {
				*((*uint8)(unsafe.Pointer(&a1))) = 226
				*(*uint16)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&a1))), 1)))) = uint16(nox_xxx_netGetUnitCodeCli_578B00(int32(uintptr(unsafe.Pointer(v1)))))
				*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&a1))), unsafe.Sizeof((*wchar2_t)(nil))-1)) = 4
				*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108)) = 6
				goto LABEL_93
			}
			if v29 == 6 {
				return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
			}
			if nox_strman_get_lang_code() == 6 {
				v30 = nox_xxx_abilityGetName_0_425260(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108)))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v30)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				v21 = nox_strman_loadString_40F1D0(internCStr("BookOf"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ToolTip.c"), 342)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v21)
				goto LABEL_93
			}
			v31 = nox_strman_loadString_40F1D0(internCStr("BookOf"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ToolTip.c"), 346)
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr("%s "))), v31)
			v32 = nox_xxx_abilityGetName_0_425260(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108)))
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v32)
		} else {
			result = nox_get_thing_pretty_name(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*27)))
			if result != nil {
				return result
			}
		}
	LABEL_93:
		if int32(uint8(uintptr(unsafe.Pointer(a1)))) != 243 {
			nox_xxx_netClientSend2_4E53C0(31, unsafe.Pointer(&a1), 4, 0, 1)
			return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
		}
		return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
	}
	v3 = nil
	v34 = nil
	v35 = nil
	a1 = nil
	if uint32(v2)&0x11001000 != 0 {
		v4 = (*uint32)(nox_xxx_getProjectileClassById_413250(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*27))))
	} else {
		v4 = (*uint32)(nox_xxx_equipClothFindDefByTT_413270(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*27))))
	}
	if v4 != nil {
		v7 = int32(uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*28))) & 0x1000000)
		if v7 == 0 || uint32(v7) == 0x1000000 && (uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*29)))&0x7800000) == 0 {
			v8 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*108))
			if v8 != 0 {
				v9 = *(**wchar2_t)(unsafe.Pointer(uintptr(v8 + 8)))
				if v9 != nil {
					v3 = v9
				}
			}
			v10 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*109))
			if v10 != 0 {
				v11 = *(**wchar2_t)(unsafe.Pointer(uintptr(v10 + 8)))
				if v11 != nil {
					v34 = v11
				}
			}
		}
		v12 = (*wchar2_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2)))))
		if v7 == 0 || (uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*29)))&0x7800000) == 0 {
			v13 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*110))
			if v13 != 0 {
				v14 = *(**wchar2_t)(unsafe.Pointer(uintptr(v13 + 8)))
				if v14 != nil {
					v35 = v14
				}
			}
			v15 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*111))
			if v15 != 0 {
				v16 = *(**wchar2_t)(unsafe.Pointer(uintptr(v15 + 12)))
				if v16 != nil {
					a1 = v16
				}
			}
		}
		switch nox_strman_get_lang_code() {
		case 2:
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v12)
			if v35 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v35)
			}
			v17 = a1
			if a1 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v17)
			}
			if v34 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v34)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			}
			if v3 == nil {
				return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
			}
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v3)
			result = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
		case 3:
			if v3 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v3)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			}
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v12)
			if v34 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v34)
			}
			if v35 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v35)
			}
			if a1 == nil {
				return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
			}
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), a1)
			result = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
		case 5:
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v12)
			if v34 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v34)
			}
			if v3 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v3)
			}
			if v35 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v35)
			}
			if a1 == nil {
				return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
			}
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), a1)
			result = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
		case 6:
			if v3 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v3)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			}
			if v35 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v35)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			}
			if a1 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), a1)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			}
			if v34 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v34)
			}
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v12)
			result = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
		default:
			if v3 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v3)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			}
			if v34 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v34)
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			}
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v12)
			if v35 != nil {
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
				nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v35)
			}
			if a1 == nil {
				return (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
			}
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), (*wchar2_t)(unsafe.Pointer(internCStr(" "))))
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), a1)
			result = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
		}
	} else {
		v33 = int32(uintptr(unsafe.Pointer(nox_get_thing_name(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*27))))))
		v5 = nox_strman_loadString_40F1D0(internCStr("NoArmsInfo"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ToolTip.c"), 53)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000)), v5, v33)
		result = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1317000))
	}
	return result
}
