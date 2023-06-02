package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_guiSpelllistLoad_453850(a1 int32) int32 {
	var (
		v9  *uint32
		v10 *uint32
	)
	dword_5d4594_1045484 = uint32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("spelllst.wnd"), sub_453C00))))
	nox_xxx_wndSetDrawFn_46B340(*(**nox_window)(unsafe.Pointer(&dword_5d4594_1045484)), sub_453B80)
	sub_46B120((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045484)))), (*nox_window)(unsafe.Pointer(uintptr(a1))))
	nox_xxx_wnd_46B280(*(*int32)(unsafe.Pointer(&dword_5d4594_1045484)), a1)
	dword_5d4594_1045480 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045484)))), 1110))))
	dword_5d4594_1045508 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045484)))), 1112))))
	sub_453B00()
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045480))))), 16399, 0, 0)
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045508))))), 16399, 0, 0)
	var wbuf [64]wchar2_t = [64]wchar2_t{}
	for i := int32(1); i < NOX_SPELLS_MAX; i++ {
		if !nox_xxx_spellIsValid_424B50(i) {
			continue
		}
		var flags int32 = int32(nox_xxx_spellFlags_424A70(i))
		if (uint32(flags) & 0x15000) != 0 {
			continue
		}
		if uint32(flags)&0x1000000 != 0 || uint32(flags)&0x2000000 != 0 && uint32(flags)&0x4000000 != 0 {
			var v7 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("Common"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c"), 307)
			nox_wcscpy(&wbuf[0], v7)
		} else {
			if (uint32(flags) & 0x6000000) == 0 {
				continue
			}
			wbuf[0] = 0
			if uint32(flags)&0x2000000 != 0 {
				var v5 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("SpellWizard"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c"), 314)
				nox_wcscat(&wbuf[0], v5)
			}
			if uint32(flags)&0x4000000 != 0 {
				var v6 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("SpellConjurer"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c"), 318)
				nox_wcscat(&wbuf[0], v6)
			}
		}
		nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045508))))), 16397, uintptr(unsafe.Pointer(&wbuf[0])), math.MaxUint32)
		var title *wchar2_t = nox_xxx_spellTitle_424930(i)
		nox_wcsncpy(&wbuf[0], title, uint32(unsafe.Sizeof([64]wchar2_t{})/2-1))
		nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045480))))), 16397, uintptr(unsafe.Pointer(&wbuf[0])), math.MaxUint32)
	}
	v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045484)))), 1113)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045480))))), 16408, uintptr(unsafe.Pointer(v9)), 0)
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045508))))), 16408, uintptr(unsafe.Pointer(v9)), 0)
	v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045484)))), 1114)))
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045480))))), 16409, uintptr(unsafe.Pointer(v10)), 0)
	nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045508))))), 16409, uintptr(unsafe.Pointer(v10)), 0)
	sub_454040((*uint32)(memmap.PtrOff(0x5D4594, 1045488)))
	sub_454120()
	if !nox_common_gameFlags_check_40A5C0(1) || nox_common_gameFlags_check_40A5C0(49152) {
		sub_46AD20(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045484)), 1115, 1133, 0)
	}
	return int32(dword_5d4594_1045484)
}
func sub_453C00(a1 *nox_window, a2, a3, a4 uintptr) uintptr {
	var (
		v3  *int32
		v4  int32
		v5  *int16
		v6  int32
		v7  int32
		v8  int32
		i   int32
		v11 int32
		v12 *wchar2_t
		v13 int32
		v14 *wchar2_t
		v15 *byte
		v16 *wchar2_t
		v17 *wchar2_t
		v18 *wchar2_t
		v19 [15]int32
		v20 *byte
		v21 int32
	)
	if a2 == 0x4000 {
		if unsafe.Pointer(a3) == unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045484)))), 1113)) || unsafe.Pointer(a3) == unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045484)))), 1114)) {
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045480))))), 0x4000, uintptr(unsafe.Pointer(a3)), 0)
			nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045508))))), 0x4000, uintptr(unsafe.Pointer(a3)), 0)
			sub_454120()
		}
		return 0
	}
	if a2 != 16391 {
		return 0
	}
	v3 = (*int32)(unsafe.Pointer(a3))
	v4 = nox_xxx_wndGetID_46B0A0((*nox_window)(unsafe.Pointer(a3)))
	v21 = v4
	switch v4 {
	case 1113, 1114:
		nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045480))))), 0x4000, uintptr(unsafe.Pointer(v3)), 0)
		nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045508))))), 0x4000, uintptr(unsafe.Pointer(v3)), 0)
		sub_454120()
		return 0
	case 1115, 1116:
		v5 = *(**int16)(unsafe.Pointer(uintptr(dword_5d4594_1045480 + 32)))
		v6 = 0
		v20 = sub_4165B0()
		if int32(*v5) > 0 {
			v7 = 0
			for {
				if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*6)))+uint32(v7) != 4294967292 {
					v8 = nox_xxx_spellByTitle_424960((*wchar2_t)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*6))) + uint32(v7) + 4))))
					if v8 != 0 {
						if v21 == 1115 {
							if !nox_common_gameFlags_check_40A5C0(64) && (*(*byte)(unsafe.Add(unsafe.Pointer(v20), 52))&0x40) == 0 || v8 != 132 {
								sub_453FA0(int32(uintptr(memmap.PtrOff(0x5D4594, 1045488))), v8, 1)
							}
						} else {
							sub_453FA0(int32(uintptr(memmap.PtrOff(0x5D4594, 1045488))), v8, 0)
						}
					}
				}
				v6++
				v7 += 524
				if v6 >= int32(*v5) {
					break
				}
			}
		}
		if dword_5d4594_2650652 != 0 {
			sub_57A1E0(&v19[0], nil, nil, 4, 6128)
			for i = 0; i < 5; i++ {
				*memmap.PtrUint32(0x5D4594, uintptr(i*4)+1045488) &= uint32(v19[i+6])
			}
		}
		sub_454120()
		sub_459D50(1)
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
		return 0
	case 1120, 1121, 1122, 1123, 1124, 1125, 1126, 1127, 1128, 1129, 1130, 1131, 1132, 1133:
		v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1045480 + 32))))
		v12 = (*wchar2_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v11 + 24))) + uint32((sub_4A4800(int32(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1045480 + 32)))))+v4-1120)*524) + 4)))
		if v12 == nil {
			sub_459D50(1)
			nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
			return 0
		}
		v13 = nox_xxx_spellByTitle_424960(v12)
		if v13 == 0 {
			sub_459D50(1)
			nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
			return 0
		}
		if dword_5d4594_2650652 == 0 || (func() int32 {
			sub_57A1E0(&v19[0], nil, nil, 4, 6128)
			return sub_454000(int32(uintptr(unsafe.Pointer(&v19[6]))), v13)
		}()) != 0 {
			v15 = sub_4165B0()
			if (nox_common_gameFlags_check_40A5C0(64) || *(*byte)(unsafe.Add(unsafe.Pointer(v15), 52))&0x40 != 0) && v13 == 132 {
				*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*9)) ^= 4
				v18 = nox_strman_loadString_40F1D0(internCStr("plyrspel.c:Illegal"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c"), 226)
				v16 = nox_strman_loadString_40F1D0(internCStr("Notice"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c"), 225)
				nox_xxx_dialogMsgBoxCreate_449A10((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045484))))), (*wchar2_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v16)))))), (*wchar2_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v18)))))), 33, nil, nil)
				sub_44A360(1)
			} else {
				if *(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*9))&4 != 0 {
					sub_453FA0(int32(uintptr(memmap.PtrOff(0x5D4594, 1045488))), v13, 0)
				} else {
					sub_453FA0(int32(uintptr(memmap.PtrOff(0x5D4594, 1045488))), v13, 1)
				}
				sub_459D50(1)
				nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
				return 0
			}
		} else {
			*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*9)) ^= 4
			v17 = nox_strman_loadString_40F1D0(internCStr("NotInternet"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c"), 211)
			v14 = nox_strman_loadString_40F1D0(internCStr("Notice"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c"), 210)
			nox_xxx_dialogMsgBoxCreate_449A10((*nox_window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045484))))), (*wchar2_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v14)))))), (*wchar2_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v17)))))), 33, nil, nil)
			sub_44A360(1)
		}
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
		return 0
	default:
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
		return 0
	}
}
