package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_xxx_guiServerPlayersLoad_456270(a1 int32) int32 {
	var (
		v1  int32
		v3  *uint32
		v4  *uint32
		v5  *byte
		v6  *uint32
		v7  *uint32
		v8  *uint32
		v9  *uint32
		v10 *wchar2_t
		v11 *uint32
		v12 *uint32
		v13 *byte
		v14 *uint32
		v15 *uint32
		v16 *uint32
	)
	v1 = nox_strman_get_lang_code()
	if nox_xxx_guiFontHeightMB_43F320(nil) > 10 {
		v1 = 2
	}
	if dword_5d4594_1045684 != 0 {
		return 0
	}
	dword_5d4594_1045684 = uint32(uintptr(unsafe.Pointer(nox_new_window_from_file(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1*4)+129048)), sub_4567C0))))
	dword_5d4594_1045688 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10507))))
	dword_5d4594_1045692 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10509))))
	sub_46B120((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), (*gui.Window)(unsafe.Pointer(uintptr(a1))))
	nox_xxx_wndSetDrawFn_46B340(*(**gui.Window)(unsafe.Pointer(&dword_5d4594_1045684)), sub_456640)
	nox_xxx_wndRetNULL_46A8A0()
	nox_common_list_clear_425760((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 1045652)))
	nox_common_list_clear_425760((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 1045668)))
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10501)))
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10502)))
	v14 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*8)))))
	v13 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("UISlider"))))
	v5 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("UISliderLit"))))
	v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10517)))
	v15 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10515)))
	v11 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10516)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*100)))), 8)) = 16
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*100)))), 12)) = 10
	sub_4B5700(int32(uintptr(unsafe.Pointer(v6))), 0, 0, int32(uintptr(unsafe.Pointer(v13))), int32(uintptr(unsafe.Pointer(v5))), int32(uintptr(unsafe.Pointer(v5))))
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v6))), int32(uintptr(unsafe.Pointer(v3))))
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v15))), int32(uintptr(unsafe.Pointer(v3))))
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v11))), int32(uintptr(unsafe.Pointer(v3))))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*9)) = uint32(uintptr(unsafe.Pointer(v6)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*7)) = uint32(uintptr(unsafe.Pointer(v15)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*8)) = uint32(uintptr(unsafe.Pointer(v11)))
	v7 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*8)))))
	v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10520)))
	v16 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10518)))
	v12 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10519)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*100)))), 8)) = 16
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*100)))), 12)) = 10
	sub_4B5700(int32(uintptr(unsafe.Pointer(v8))), 0, 0, int32(uintptr(unsafe.Pointer(v13))), int32(uintptr(unsafe.Pointer(v5))), int32(uintptr(unsafe.Pointer(v5))))
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v8))), int32(uintptr(unsafe.Pointer(v4))))
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v16))), int32(uintptr(unsafe.Pointer(v4))))
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v12))), int32(uintptr(unsafe.Pointer(v4))))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*9)) = uint32(uintptr(unsafe.Pointer(v8)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*7)) = uint32(uintptr(unsafe.Pointer(v16)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*8)) = uint32(uintptr(unsafe.Pointer(v12)))
	sub_456500()
	v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10504)))
	if noxflags.HasGame(128) {
		v10 = nox_strman_loadString_40F1D0(internCStr("Title1"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c"), 631)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v9)), 16385, uintptr(unsafe.Pointer(v10)), math.MaxUint32)
	}
	return int32(dword_5d4594_1045684)
}
func sub_4567C0(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v3  *byte
		v4  int32
		v5  *uint32
		v6  int32
		v7  *uint32
		v8  int32
		v9  *int32
		v10 *int32
		i   int32
		v12 *wchar2_t
		v13 *byte
		v14 *byte
		v15 *uint32
		v16 int32
		v17 *uint32
		v18 *uint32
		v20 *uint32
		v21 int32
		v22 *byte
		v23 *wchar2_t
		v24 *uint32
		v25 int32
		v26 *byte
		v27 *wchar2_t
		v28 *wchar2_t
		v29 *byte
		v30 [56]wchar2_t
	)
	if a2 != 16391 {
		if a2 != 16400 {
			return 0
		}
		if nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) == 10502 {
			v3 = sub_4165B0()
			if nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16404, 0, 0) < 0 {
				nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045688))))), 0)
				nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045692))))), 0)
			} else if noxflags.HasGame(0x8000) || *(*byte)(unsafe.Add(unsafe.Pointer(v3), 53)) < 0 {
				nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045688))))), 0)
				nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045692))))), 0)
			} else {
				if noxflags.HasGame(1) {
					nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045692))))), 1)
				}
				if noxflags.HasGame(128) || *memmap.PtrUint32(0x5D4594, 1045696) == 0 {
					nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045688))))), 1)
				} else {
					nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045688))))), 0)
				}
			}
			if noxflags.HasGame(1) && nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
				nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045688))))), 0)
			}
		}
	}
	v4 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	if v4 > 10507 {
		if v4 == 10509 {
			v28 = nox_strman_loadString_40F1D0(internCStr("NewName"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c"), 504)
			v27 = nox_strman_loadString_40F1D0(internCStr("Rename"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c"), 504)
			nox_xxx_dialogMsgBoxCreate_449A10((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045684))))), (*wchar2_t)(unsafe.Pointer(v27)), (*wchar2_t)(unsafe.Pointer(v28)), 163, nil, nil)
		}
		return 0
	}
	if v4 == 10507 {
		v24 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10502)))
		v25 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v24)), 16404, 0, 0))
		sub_456D00(v25, &v30[0])
		v26 = sub_418A40(&v30[0])
		if v26 != nil {
			sub_456BB0(int32(uintptr(unsafe.Pointer(v26))))
			return 0
		}
		return 0
	}
	if v4 == 4001 {
		v20 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10502)))
		v21 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v20)), 16404, 0, 0))
		sub_456D00(v21, &v30[0])
		v22 = sub_418A40(&v30[0])
		if v22 != nil {
			v23 = (*wchar2_t)(unsafe.Pointer(uintptr(sub_449E60(-88))))
			if sub_4190F0(v23) == 0 {
				nox_xxx_teamRenameMB_418CD0((*wchar2_t)(unsafe.Pointer(v22)), v23)
				return 0
			}
		}
		return 0
	}
	if v4 != 10503 {
		return 0
	}
	v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10502)))
	v6 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v5)), 16404, 0, 0))
	if v6 >= 0 {
		sub_456D00(v6, &v30[0])
		v29 = sub_418A40(&v30[0])
		if v29 != nil {
			v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10501)))
			v8 = int32(uintptr(unsafe.Pointer(v7)))
			v9 = (*int32)(unsafe.Pointer(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v7)), 16404, 0, 0)))
			v10 = v9
			for i = *v9; i >= 0; v10 = (*int32)(unsafe.Add(unsafe.Pointer(v10), 4*1)) {
				v12 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(v8))), 16406, uintptr(i), 0)))
				v13 = nox_xxx_playerByName_4170D0(v12)
				v14 = v13
				if v13 != nil {
					if (*(*byte)(unsafe.Add(unsafe.Pointer(v13), 3680))&1) == 0 && (*(*byte)(unsafe.Add(unsafe.Pointer(v13), 4))&1) == 0 {
						v15 = nox_xxx_objGetTeamByNetCode_418C80(int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*515)))))
						v16 = int32(uintptr(unsafe.Pointer(v15)))
						if v15 != nil {
							if nox_xxx_servObjectHasTeam_419130(unsafe.Pointer(v15)) != 0 {
								sub_4196D0(unsafe.Pointer(uintptr(v16)), unsafe.Pointer(v29), int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*515)))), 1)
							} else {
								nox_xxx_createAtImpl_4191D0(*(*byte)(unsafe.Add(unsafe.Pointer(v29), 57)), unsafe.Pointer(uintptr(v16)), 1, int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*515)))), 1)
							}
						}
					}
				}
				i = *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*1))
			}
		}
	}
	v17 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10502)))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v17)), 16403, math.MaxUint32, 0)
	v18 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10501)))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v18)), 16403, math.MaxUint32, 0)
	return 0
}
func sub_457010(a1 int32, a2 *wchar2_t) int32 {
	var (
		v2     *byte
		result int32
		v4     *uint32
		v5     int32
		v6     uint8
		v7     uint8
		v8     *wchar2_t
	)
	v9, free9 := alloc.Make([]wchar2_t{}, 56)
	defer free9()
	v2 = sub_4165B0()
	result = int32(dword_5d4594_1045684)
	if dword_5d4594_1045684 != 0 {
		v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10502)))
		v5 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v4)), 16404, 0, 0))
		nox_wcscpy(&v9[0], a2)
		if noxflags.HasGame(96) || *(*byte)(unsafe.Add(unsafe.Pointer(v2), 52))&0x60 != 0 {
			v6 = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 57))
			if int32(v6) < 3 {
				if int32(v6) == 1 {
					v8 = nox_strman_loadString_40F1D0(internCStr("RedFlag"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c"), 778)
				} else {
					v8 = nox_strman_loadString_40F1D0(internCStr("BlueFlag"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c"), 782)
				}
				nox_wcscat(&v9[0], v8)
			}
		}
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v4)), 16398, uintptr(v5), 0)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v4)), 16402, uintptr(v5), 0)
		v7 = sub_457120(a1)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v4)), 16397, uintptr(unsafe.Pointer(&v9[0])), uintptr(v7))
		result = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v4)), 16403, uintptr(v5), 0))
	}
	return result
}
func sub_457230(a1 *wchar2_t) *byte {
	var (
		v1     *byte
		result *byte
		v3     *uint32
		v4     *byte
		v5     int8
		v6     *uint32
		v7     *wchar2_t
	)
	v8, free8 := alloc.Make([]wchar2_t{}, 56)
	defer free8()
	v1 = sub_4165B0()
	result = *(**byte)(unsafe.Pointer(&dword_5d4594_1045684))
	if dword_5d4594_1045684 != 0 {
		v3 = (*uint32)(alloc.Calloc1(1, 0x48))
		result = sub_418A40(a1)
		v4 = result
		if result != nil {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*15)) = uint32(*(*byte)(unsafe.Add(unsafe.Pointer(result), 57)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*17)) = uint32(*(*byte)(unsafe.Add(unsafe.Pointer(result), 56)))
			*((*uint8)(unsafe.Add(unsafe.Pointer(v3), 64))) = sub_457120(int32(uintptr(unsafe.Pointer(result))))
			sub_425770(unsafe.Pointer(v3))
			nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(uintptr(memmap.PtrOff(0x5D4594, 1045668)))), (*nox_list_item_t)(unsafe.Pointer(v3)))
			nox_wcscpy((*wchar2_t)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(wchar2_t(0))*6)), a1)
			nox_wcscpy(&v8[0], a1)
			if noxflags.HasGame(96) || *(*byte)(unsafe.Add(unsafe.Pointer(v1), 52))&0x60 != 0 {
				v5 = int8(*(*byte)(unsafe.Add(unsafe.Pointer(v4), 57)))
				if int32(uint8(v5)) < 3 {
					if int32(v5) == 1 {
						v7 = nox_strman_loadString_40F1D0(internCStr("RedFlag"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c"), 893)
					} else {
						v7 = nox_strman_loadString_40F1D0(internCStr("BlueFlag"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c"), 897)
					}
					nox_wcscat(&v8[0], v7)
				}
			}
			v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045684)))), 10502)))
			result = (*byte)(unsafe.Pointer(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v6)), 16397, uintptr(unsafe.Pointer(&v8[0])), uintptr(*((*uint8)(unsafe.Add(unsafe.Pointer(v3), 64)))))))
		}
	}
	return result
}
