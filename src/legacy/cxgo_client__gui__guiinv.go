package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func nox_xxx_spritePickup_461660(a1 int32, a2 int32, a3 unsafe.Pointer) int32 {
	var (
		v3 *int32
		v4 *wchar2_t
		v6 int32
		v7 int32
		a4 int2
	)
	if a2 != dword_5d4594_1062560 && uint32(a2) != *memmap.PtrUint32(0x5D4594, 1049728) && uint32(a2) != *memmap.PtrUint32(0x5D4594, 1049724) && a2 != dword_5d4594_1062556 && a2 != dword_5d4594_1062564 {
		v3 = sub_461970(a1, a2)
		if v3 != nil {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*v3)), 112)))&0x10 != 0 {
				sub_472310()
			}
		} else {
			if sub_4617C0(a1, a2, a3, &a4) == 0 {
				v4 = nox_strman_loadString_40F1D0(internCStr("InventoryFull"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 682)
				nox_xxx_printCentered_445490(v4)
				return 0
			}
			v6 = a4.field_0
			v7 = a4.field_4
			if nox_client_inventory_grid_1050020[a4.field_4+NOX_INVENTORY_ROW_COUNT*a4.field_0].field_0.Flags28()&0x10 != 0 {
				sub_472310()
				v7 = a4.field_4
				v6 = a4.field_0
			}
			if nox_client_inventory_grid_1050020[v7+NOX_INVENTORY_ROW_COUNT*v6].field_0.Flags28()&0x3001000 != 0 {
				dword_5d4594_1062516 = 0
				if v7 >= 3 {
					dword_5d4594_1062516 = (v7*5 - 10) * 10
				}
			}
		}
		v8 := nox_get_thing(a2)
		if v8 != nil {
			if v8.ObjClass&0x1001000 != 0 {
				sub_4673F0(a4.field_0, a4.field_4)
			}
		}
	}
	return 1
}
func sub_4617C0(a1 int32, a2 int32, a3 unsafe.Pointer, a4 *int2) int32 {
	var (
		v4     uint16
		i      uint16
		result int32
		v7     int32
		v8     int32
		v9     *uint8
		v10    *uint32
		v11    *wchar2_t
		v12    int32
		v13    int32
		v14    int32
		v15    *uint32
	)
	v4 = 0
	for {
		for i = 0; int32(i) < 4; i++ {
			if int32(nox_client_inventory_grid_1050020[int32(v4)+NOX_INVENTORY_ROW_COUNT*int32(i)].field_140) == 0 {
				v7 = int32(i)
				v8 = int32(v4)
				v9 = (*uint8)(unsafe.Pointer(&nox_client_inventory_grid_1050020[int32(v4)+NOX_INVENTORY_ROW_COUNT*int32(i)]))
				v10 = (*uint32)(nox_new_drawable_for_thing(a2).C())
				*(*uint32)(unsafe.Pointer(v9)) = uint32(uintptr(unsafe.Pointer(v10)))
				if v10 != nil {
					*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*30)) |= 0x40000000
					v12 = int32(*(*uint32)(unsafe.Pointer(v9)))
					*((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*1))) = uint32(a1)
					*(*uint8)(unsafe.Add(unsafe.Pointer(v9), 140)) = 1
					if *(*uint32)(unsafe.Add(v12, 112))&0x13001000 != 0 {
						alloc.Memcpy(unsafe.Add(v12, 432), a3, 0x14)
						v8 = int32(v4)
					}
					if a4 != nil {
						a4.field_0 = v7
						a4.field_4 = v8
					}
					if sub_461930() != 0 && dword_5d4594_1062480 == 0 {
						if (func() uint32 {
							v13 = int32(*(*uint32)(unsafe.Pointer(v9)))
							v14 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v9)), 112)))
							return uint32(v14) & 0x1000000
						}()) != 0 && (int32(*(*uint8)(unsafe.Add(v13, 116)))&2) == 0 || v14&0x1000 != 0 {
							v15 = (*uint32)(nox_xxx_getProjectileClassById_413250(int32(*(*uint32)(unsafe.Add(v13, 108)))))
							if v15 == nil || int32(uint8(int8(1<<int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))))))&int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v15), 62)))) != 0 {
								nox_xxx_clientSetAltWeapon_461550(int32(uintptr(unsafe.Pointer(v9))))
								*((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*34))) = 1
							}
						}
					}
					result = 1
				} else {
					v11 = nox_strman_loadString_40F1D0(internCStr("DrawablesExhausted"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 550)
					nox_xxx_printCentered_445490(v11)
					result = 0
				}
				return result
			}
		}
		if int32(func() uint16 {
			p := &v4
			*p++
			return *p
		}()) < 0x14 {
			continue
		}
		break
	}
	return 0
}
func sub_461A80(a1 int32) {
	var (
		v1 int32
		v2 *byte
		v3 *uint64
		v4 *uint64
		v5 *wchar2_t
	)
	v1 = 0
	v2 = sub_461EF0(a1)
	if v2 != nil {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(**(**uint32)(unsafe.Pointer(v2)))), 112)))&0x10 != 0 {
			v1 = 1
		}
		sub_461E60((***uint64)(unsafe.Pointer(v2)))
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v2)), 132)) = 0
		sub_461B50()
		v3 = (*uint64)(unsafe.Pointer(uintptr(sub_461F90(a1))))
		if v3 != nil {
			nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(v3)))
		}
		if v1 != 0 {
			sub_472310()
		}
	} else {
		v4 = *(**uint64)(memmap.PtrOff(0x5D4594, 1049848))
		if *memmap.PtrUint32(0x5D4594, 1049848) != 0 && *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 128)) == uint32(a1) {
			if int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 112)))&0x10 != 0 {
				sub_472310()
				v4 = *(**uint64)(memmap.PtrOff(0x5D4594, 1049848))
			}
			nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(v4)))
			*memmap.PtrUint32(0x5D4594, 1049848) = 0
			dword_5d4594_1049856 = 0
			nox_xxx_cursorResetDraggedItem_4776A0()
		} else {
			v5 = nox_strman_loadString_40F1D0(internCStr("DroppedNotFound"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1439)
			nox_xxx_printCentered_445490(v5)
		}
	}
}
func sub_462040(a1 int32) {
	var (
		v1  int32
		v2  *byte
		v3  unsafe.Pointer
		v4  unsafe.Pointer
		v7  *wchar2_t
		v8  int32
		v9  int32
		v10 int32
		v11 *byte
		v12 *uint8
		v13 int32
		v14 *uint8
		v16 int16
		v17 *int32
		v18 int16
		v19 int16
		v20 int32
	)
	v1 = a1
	v2 = sub_461EF0(a1)
	if v2 != nil {
		v20 = sub_4622E0(**(**unsafe.Pointer)(unsafe.Pointer(v2)))
		v3 = **(**unsafe.Pointer)(unsafe.Pointer(v2))
	} else {
		if *memmap.PtrUint32(0x5D4594, 1049848) == 0 || *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 128)) != uint32(a1) {
			v7 = nox_strman_loadString_40F1D0(internCStr("EquippedNotFound"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1605)
			nox_xxx_printCentered_445490(v7)
			return
		}
		v20 = sub_4622E0(*memmap.PtrPtr(0x5D4594, 1049848))
		v3 = *memmap.PtrPtr(0x5D4594, 1049848)
	}
	v4 = unsafe.Add(v3, 432)
	v19 = int16(*(*uint16)(unsafe.Add(v3, 294)))
	v18 = int16(*(*uint16)(unsafe.Add(v3, 292)))
	if v20 == 9 {
		v7 = nox_strman_loadString_40F1D0(internCStr("TooManyEquipped"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1701)
		nox_xxx_printCentered_445490(v7)
		return
	}
	v5 := nox_new_drawable_for_thing(int32(*(*uint32)(unsafe.Add(v3, 108))))
	v6 := v5
	if v5 == nil {
		v7 = nox_strman_loadString_40F1D0(internCStr("DrawablesExhausted"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1619)
		nox_xxx_printCentered_445490(v7)
		return
	}
	v8 = int32(v5.Flags30Val)
	v6.Field_32 = uint32(v1)
	v6.Flags30Val = uint32(v8) | 0x40000000
	alloc.Memcpy(unsafe.Add(unsafe.Pointer(v6), 4*108), v4, 0x18)
	*((*uint16)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(uint16(0))*146))) = uint16(v18)
	*((*uint16)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(uint16(0))*147))) = uint16(v19)
	sub_4623E0(v6, v20)
	v9 = 0
	if v2 != nil {
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v2)), 132)) = 1
		if *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v2)), 136)) != 0 {
			nox_xxx_clientSetAltWeapon_461550(nil)
			*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v2)), 136)) = 0
		}
	}
	if v6.Flags28Val&0x1000000 != 0 && v6.Flags29Val&0xC != 0 {
		v10 = 1
		if dword_5d4594_1062488 != 0 && (func() *byte {
			v11 = sub_461EF0(int32(dword_5d4594_1062488))
			return v11
		}()) != nil {
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(**(**uint32)(unsafe.Pointer(v11)))), 128)) = *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v11)), 4))
			nox_xxx_clientEquip_4623B0(int32(**(**uint32)(unsafe.Pointer(v11))))
		} else {
			v12 = (*uint8)(unsafe.Pointer(&nox_client_inventory_grid_1050020[0]))
			var v15 int32 = 0
			for {
				if v10 == 0 {
					break
				}
				v13 = 0
				v14 = v12
				for int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v14), 140))) == 0 || (int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v14)), 115)))&1) == 0 || *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v14)), 116)) != 2 {
					v13++
					v14 = (*uint8)(unsafe.Add(unsafe.Pointer(v14), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
					if v13 >= 4 {
						goto LABEL_26
					}
				}
				v15 = v9 + NOX_INVENTORY_ROW_COUNT*v13
				nox_client_inventory_grid_1050020[v15].field_0.Field_32 = nox_client_inventory_grid_1050020[v15].field_4
				nox_xxx_clientEquip_4623B0(nox_client_inventory_grid_1050020[v15].field_0)
				v10 = 0
			LABEL_26:
				v12 = (*uint8)(unsafe.Add(unsafe.Pointer(v12), unsafe.Sizeof(nox_inventory_cell_t{})))
				v9++
				if int32(uintptr(unsafe.Pointer(v12))) >= int32(uintptr(unsafe.Pointer(&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT-1]))) {
					break
				}
			}
		}
	}
	if v20 == 0 {
		dword_5d4594_1062488 = v6.Field_32
	}
	v16 = int16(*((*uint16)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(uint16(0))*224))))
	if int32(v16) >= 0 {
		sub_470D90(int32(v16), int32(*((*int16)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(int16(0))*225)))))
	}
	if dword_5d4594_1062496 != 0 {
		v17 = (*int32)(unsafe.Pointer(sub_461EF0(int32(dword_5d4594_1062496))))
		if v17 != nil {
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*v17)), 136)) = 1
			nox_xxx_clientSetAltWeapon_461550(*v17)
			dword_5d4594_1062496 = 0
		}
	}
}
func sub_462740() int32 {
	var (
		v0 *wchar2_t
		v1 *uint32
	)
	if wndIsShown_nox_xxx_wndIsShown_46ACC0(dword_5d4594_1062476) != 0 {
		return 0
	}
	nox_window_set_hidden(dword_5d4594_1062476, 1)
	dword_5d4594_1063116 = nil
	dword_5d4594_1063120 = 0
	v0 = nox_strman_loadString_40F1D0(internCStr("thing.db:IdentifyDescription"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2361)
	nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1063124)), v0)
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1062476, 9156)))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v1)), 16399, 0, 0)
	nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_1062456)
	dword_5d4594_1049864 = 0
	nox_client_setCursorType_477610(0)
	return 1
}
func sub_4627F0(a1 *uint32) int32 {
	var (
		v2     int32
		v3     int32
		result int32
		v5     *wchar2_t
		v6     *uint32
		v7     *wchar2_t
		v8     *wchar2_t
		v9     *uint32
		v10    *uint32
		v11    *wchar2_t
		v12    *wchar2_t
		v13    *wchar2_t
		v14    *wchar2_t
		v15    unsafe.Pointer
		v16    int32
		v17    *float32
		v18    float64
		v19    int32
		v20    int32
		v21    *wchar2_t
		v22    *wchar2_t
		v23    int32
		v24    int32
		v25    int32
		v26    *uint32
		v27    int32
		v28    float64
		v29    int32
		v30    float64
		v31    float64
		v32    float64
		v33    int32
		v34    *wchar2_t
		v35    *wchar2_t
		v36    *wchar2_t
		v37    *wchar2_t
		v38    *wchar2_t
		v39    int32
		v40    *uint32
		v41    *wchar2_t
		v42    *wchar2_t
		v43    int32
		v44    int32
		v45    *wchar2_t
		v46    int32
		v47    int32
		v48    *wchar2_t
		v49    int32
		v50    *uint32
		v51    *wchar2_t
		v52    *wchar2_t
		v53    *wchar2_t
		v54    *wchar2_t
		v55    *wchar2_t
		v56    int32
		v57    float64
		v58    float64
		v59    float64
		v60    float64
		v61    float64
		v62    float64
		v63    int32
		v64    int32
		v65    float32
		v66    int32
		v67    int32
		v68    float32
		v69    float32
		v70    float32
		v71    float32
		v72    float32
		v73    int32
		v74    int2
	)
	v75, free75 := alloc.Make([]wchar2_t{}, 256)
	defer free75()
	v76, freev76 := alloc.Make([]wchar2_t{}, 256)
	defer freev76()
	v73 = 1
	var mpos nox_point = nox_client_getMousePos_4309F0()
	nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
	v2 = 0
	nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
	nox_client_drawRectFilledOpaque_49CE30(int32(*a1+11), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1))+15), 200, 200)
	sub_463370(dword_5d4594_1062456, &mpos, (*uint32)(unsafe.Pointer(&v74)))
	if nox_xxx_pointInRect_4281F0(&v74, (*int4)(memmap.PtrOff(0x587000, 136352))) != 0 || nox_xxx_pointInRect_4281F0(&v74, (*int4)(memmap.PtrOff(0x587000, 136368))) != 0 {
		if nox_xxx_pointInRect_4281F0(&v74, (*int4)(memmap.PtrOff(0x587000, 136368))) != 0 && (v74.field_4-13)/50 != 1 {
			nox_client_setCursorType_477610(7)
			goto LABEL_14
		}
	} else {
		if nox_xxx_pointInRect_4281F0(&v74, (*int4)(memmap.PtrOff(0x587000, 136336))) != 0 {
			nox_client_setCursorType_477610(0)
			goto LABEL_14
		}
		if sub_478030() == 0 {
			nox_client_setCursorType_477610(7)
			goto LABEL_14
		}
		if sub_479870() == 0 || (func() bool {
			*((*uint8)(unsafe.Pointer(&v3))) = uint8(int8(bool2int32(sub_479880((*uint32)(unsafe.Pointer(&v74))))))
			return v3 == 0
		}()) {
			nox_client_setCursorType_477610(7)
			goto LABEL_14
		}
	}
	nox_client_setCursorType_477610(6)
LABEL_14:
	result = int32(dword_5d4594_1063116)
	if dword_5d4594_1063116 == 0 {
		if dword_5d4594_1063120 != 0 {
			dword_5d4594_1063120 = 0
			v5 = nox_strman_loadString_40F1D0(internCStr("thing.db:IdentifyDescription"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2529)
			nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1063124)), v5)
			v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1062476, 9156)))
			result = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v6)), 16399, 0, 0))
		}
		return result
	}
	if dword_5d4594_1063120 == dword_5d4594_1063116 {
		return result
	}
	dword_5d4594_1063120 = dword_5d4594_1063116
	v7 = nox_strman_loadString_40F1D0(internCStr("IdentifyItem"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2545)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1063124)), internWStr("%s "), v7)
	v8 = nox_xxx_clientAskInfoMb_4BF050((*client.Drawable)(dword_5d4594_1063116))
	nox_wcscpy(&v75[0], v8)
	if nox_wcscmp(&v75[0], (*wchar2_t)(memmap.PtrOff(0x5D4594, 1063652))) == 0 {
		dword_5d4594_1063120 = 0
	}
	nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1063124)), &v75[0])
	v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1062476, 9151)))
	sub_46AEE0(int32(uintptr(unsafe.Pointer(v9))), int32(uintptr(memmap.PtrOff(0x5D4594, 1063124))))
	v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1062476, 9156)))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16399, 0, 0)
	if noxflags.HasGame(2048) {
		if int32(*(*uint16)(unsafe.Add(dword_5d4594_1063116, 294))) != 0 {
			sub_4633B0(dword_5d4594_1063116, &v71, &v68)
			v63 = int32(v68)
			v56 = int32(v71)
			v11 = nox_strman_loadString_40F1D0(internCStr("IdentifyDurability"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2575)
			nox_swprintf(&v75[0], v11, v56, v63)
		} else {
			v12 = nox_strman_loadString_40F1D0(internCStr("IdentifyDurabilityIndestructable"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2583)
			nox_wcscpy(&v75[0], v12)
		}
	} else {
		switch sub_57B190(*(*uint16)(unsafe.Add(dword_5d4594_1063116, 292)), *(*uint16)(unsafe.Add(dword_5d4594_1063116, 294))) {
		case 0:
			v13 = nox_strman_loadString_40F1D0(internCStr("IdentifyDurabilityNoDamage"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2595)
			nox_swprintf(&v75[0], v13)
		case 1:
			v52 = nox_strman_loadString_40F1D0(internCStr("IdentifyDurabilitySlight"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2599)
			nox_swprintf(&v75[0], v52)
		case 2:
			v53 = nox_strman_loadString_40F1D0(internCStr("IdentifyDurabilityModerate"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2603)
			nox_swprintf(&v75[0], v53)
		case 3:
			v13 = nox_strman_loadString_40F1D0(internCStr("IdentifyDurabilitySevere"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2607)
			nox_swprintf(&v75[0], v13)
		case 4:
			v51 = nox_strman_loadString_40F1D0(internCStr("IdentifyDurabilityIndestructable"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2591)
			nox_swprintf(&v75[0], v51)
		default:
		}
	}
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(memmap.PtrOff(0x5D4594, 1063656)), math.MaxUint32)
	v64 = int32(*(*uint8)(unsafe.Add(dword_5d4594_1063116, 298)))
	v14 = nox_strman_loadString_40F1D0(internCStr("IdentifyWeight"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2620)
	nox_swprintf(&v75[0], v14, v64)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(memmap.PtrOff(0x5D4594, 1063660)), math.MaxUint32)
	v15 = dword_5d4594_1063116
	v16 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1063116, 112)))
	if (uint32(v16) & 0x2000000) == 0 {
		if (uint32(v16) & 0x1001000) == 0 {
			goto LABEL_72
		}
		v23 = int32(*memmap.PtrUint32(0x8531A0, 2576))
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v68), 4*0)) = dword_5d4594_1063116 + 432
		v69 = 1.0
		v70 = *mem_getFloatPtr(0x8531A0, 2576)
		if *memmap.PtrUint32(0x5D4594, 1063644) == 0 {
			*memmap.PtrUint32(0x5D4594, 1063644) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ArcherArrow")))
			v24 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ArcherBolt"))
			v23 = int32(*memmap.PtrUint32(0x8531A0, 2576))
			*memmap.PtrUint32(0x5D4594, 1063648) = uint32(v24)
			v15 = dword_5d4594_1063116
		}
		if v23 == 0 || (int32(*(*uint8)(unsafe.Add(v15, 116)))&2) == 0 {
			goto LABEL_50
		}
		v25 = int32(*(*uint32)(unsafe.Add(v23, 4)))
		if v25&4 != 0 {
			v26 = (*uint32)(nox_xxx_getProjectileClassById_413250(*memmap.PtrInt32(0x5D4594, 1063644)))
			v2 = 4
		} else {
			if (v25 & 8) == 0 {
				goto LABEL_50
			}
			v26 = (*uint32)(nox_xxx_getProjectileClassById_413250(*memmap.PtrInt32(0x5D4594, 1063648)))
			v2 = 8
		}
		if v26 != nil {
			goto LABEL_51
		}
		v15 = dword_5d4594_1063116
	LABEL_50:
		v26 = (*uint32)(nox_xxx_getProjectileClassById_413250(int32(*(*uint32)(unsafe.Add(v15, 108)))))
	LABEL_51:
		v71 = float32(sub_4626C0(dword_5d4594_1063116))
		v72 = float32(sub_462700(dword_5d4594_1063116))
		v27 = int32(*(*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(&v68), 4*0))))
		if *(*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(&v68), 4*0))) != 0 && *(*unsafe.Pointer)(unsafe.Add(v27, 40)) == ccall.FuncAddr(nox_xxx_effectDamageMultiplier_4E04C0) {
			v69 = *(*float32)(unsafe.Add(v27, 44))
		}
		v28 = nox_xxx_calcBoltDamage_4EF1E0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v70), 4*0))))), 2239))), unsafe.Pointer(v26))
		v29 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v26), 4*1)))
		v70 = float32(v28*float64(v69) + float64(v71) + float64(v72))
		if uint32(v29) == *memmap.PtrUint32(0x5D4594, 1063648) && noxflags.HasGame(2048) {
			v30 = nox_xxx_gamedataGetFloat_419D40((*byte)(memmap.PtrOff(0x587000, 137632)))
		} else {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v68), 4*0)) = uint32(*((*uint16)(unsafe.Add(unsafe.Pointer(v26), unsafe.Sizeof(uint16(0))*36))))
			v30 = float64(*(*int32)(unsafe.Add(unsafe.Pointer(&v68), 4*0)))
		}
		v68 = float32(v30 * float64(v69))
		v31 = float64(v70 - v68 - v72 - v71)
		v69 = float32(v31)
		if v31 < 0.0 {
			v32 = float64(v70 - v69)
			v69 = 0.0
			v70 = float32(v32)
		}
		v33 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1063116, 116)))
		if v33&0xC != 0 {
			v34 = nox_strman_loadString_40F1D0(internCStr("WeaponDamageLabelNA"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2770)
			nox_swprintf(&v75[0], v34)
		} else if (v33&2) == 0 || v2 != 0 {
			v58 = float64(v70)
			v55 = nox_strman_loadString_40F1D0(internCStr("WeaponDamageLabel"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2776)
			nox_swprintf(&v75[0], v55, v58)
		} else {
			v57 = float64(v70)
			v54 = nox_strman_loadString_40F1D0(internCStr("WeaponDamageLabelUnknownPlus"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2773)
			nox_swprintf(&v75[0], v54, v57)
		}
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
		nox_wcscpy(&v75[0], internWStr("  "))
		v59 = float64(v68)
		v35 = nox_strman_loadString_40F1D0(internCStr("BaseDamageLabel"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2785)
		nox_swprintf(&v76[0], v35, v59)
		nox_wcscat(&v75[0], &v76[0])
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
		nox_wcscpy(&v75[0], internWStr("  "))
		v60 = float64(v69)
		v36 = nox_strman_loadString_40F1D0(internCStr("StrengthDamageLabel"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2792)
		nox_swprintf(&v76[0], v36, v60)
		nox_wcscat(&v75[0], &v76[0])
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
		if float64(v72) > 0.0 {
			nox_wcscpy(&v75[0], internWStr("  "))
			v61 = float64(v72)
			v37 = nox_strman_loadString_40F1D0(internCStr("FireDamageLabel"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2801)
			nox_swprintf(&v76[0], v37, v61)
			nox_wcscat(&v75[0], &v76[0])
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
		}
		if float64(v71) > 0.0 {
			nox_wcscpy(&v75[0], internWStr("  "))
			v62 = float64(v71)
			v38 = nox_strman_loadString_40F1D0(internCStr("ElectricalDamageLabel"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2811)
			nox_swprintf(&v76[0], v38, v62)
			nox_wcscat(&v75[0], &v76[0])
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
		}
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(memmap.PtrOff(0x5D4594, 1063668)), math.MaxUint32)
		goto LABEL_71
	}
	v17 = (*float32)(nox_xxx_equipClothFindDefByTT_413270(int32(*(*uint32)(unsafe.Add(dword_5d4594_1063116, 108)))))
	v18 = 1.0
	v19 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1063116, 432)))
	if v19 != 0 && *(*unsafe.Pointer)(unsafe.Add(v19, 76)) == ccall.FuncAddr(sub_4E0370) {
		v18 = float64(*(*float32)(unsafe.Add(v19, 80)))
	}
	v65 = float32(v18*float64(*(*float32)(unsafe.Add(unsafe.Pointer(v17), unsafe.Sizeof(float32(0))*16)))*1000.0 + 0.5)
	v20 = int32(v65)
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1063116, 116)))&2 != 0 {
		v21 = nox_strman_loadString_40F1D0(internCStr("ArmorValueLabelNA"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2647)
		nox_swprintf(&v75[0], v21)
	} else {
		v66 = v20
		v22 = nox_strman_loadString_40F1D0(internCStr("ArmorValueLabel"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2649)
		nox_swprintf(&v75[0], v22, v66)
	}
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(memmap.PtrOff(0x5D4594, 1063664)), math.MaxUint32)
LABEL_71:
	v15 = dword_5d4594_1063116
LABEL_72:
	v39 = int32(*(*uint32)(unsafe.Add(v15, 112)))
	if uint32(v39)&0x13001000 != 0 {
		if uint32(v39)&0x11001000 != 0 {
			v40 = (*uint32)(nox_xxx_getProjectileClassById_413250(int32(*(*uint32)(unsafe.Add(v15, 108)))))
		} else {
			v40 = (*uint32)(nox_xxx_equipClothFindDefByTT_413270(int32(*(*uint32)(unsafe.Add(v15, 108)))))
		}
		if v40 != nil {
			v15 = dword_5d4594_1063116
			v43 = int32(dword_5d4594_1063116 + 432)
			if *(*uint32)(unsafe.Add(dword_5d4594_1063116, 112))&0x10000000 != 0 {
				goto LABEL_91
			}
			v44 = int32(*(*uint32)(unsafe.Add(dword_5d4594_1063116, 440)))
			if v44 != 0 && *(*uint32)(unsafe.Add(v44, 16)) != 0 {
				v45 = nox_strman_loadString_40F1D0(internCStr("IdentifySpecialAttributes"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2851)
				nox_swprintf(&v75[0], v45)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
				v46 = 0
				nox_wcscpy(&v75[0], internWStr("  "))
				nox_swprintf(&v76[0], *(**wchar2_t)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v43, 8)), 16)))
				nox_wcscat(&v75[0], &v76[0])
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
				v15 = dword_5d4594_1063116
			} else {
				v46 = v73
			}
			v47 = int32(*(*uint32)(unsafe.Add(v43, 12)))
			if v47 != 0 && *(*uint32)(unsafe.Add(v47, 16)) != 0 {
				if v46 == 1 {
					v48 = nox_strman_loadString_40F1D0(internCStr("IdentifySpecialAttributes"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2868)
					nox_swprintf(&v75[0], v48)
					nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
					v73 = 0
					v46 = 0
				}
				nox_wcscpy(&v75[0], internWStr("  "))
				nox_swprintf(&v76[0], *(**wchar2_t)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v43, 12)), 16)))
				nox_wcscat(&v75[0], &v76[0])
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
				v15 = dword_5d4594_1063116
			}
			if v46 != 0 {
				goto LABEL_91
			}
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(memmap.PtrOff(0x5D4594, 1063672)), math.MaxUint32)
		} else {
			v41 = nox_strman_loadString_40F1D0(internCStr("IdentifySpecialAttributes"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2835)
			nox_swprintf(&v75[0], v41)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
			v42 = nox_strman_loadString_40F1D0(internCStr("IdentifyUnknown"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2837)
			nox_swprintf(&v75[0], v42)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(unsafe.Pointer(&v75[0])), math.MaxUint32)
		}
		v15 = dword_5d4594_1063116
	}
LABEL_91:
	v49 = int32(uintptr(unsafe.Pointer(nox_get_thing_desc(int32(*(*uint32)(unsafe.Add(v15, 108)))))))
	if v49 != 0 {
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16397, uintptr(v49), math.MaxUint32)
	}
	v67 = nox_get_thing_pretty_image(int32(*(*uint32)(unsafe.Add(dword_5d4594_1063116, 108))))
	v50 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1062476, 9155)))
	return nox_xxx_wndSetIcon_46AE60(int32(uintptr(unsafe.Pointer(v50))), v67)
}
func nox_client_makePlayerStatsDlg_463880(a1 *int32) {
	var (
		v77 [256]wchar2_t
		v1  int32   = nox_xxx_guiFontHeightMB_43F320(nil)
		v2  int32   = nox_xxx_guiFontHeightMB_43F320(dword_5d4594_1063636)
		v68 int32   = v1 - v2
		v51 float32 = float32(float64(v1-v2)*0.5 + 0.5)
		v3  int32   = int32(v51)
		v73 int32   = v3
		v72 int32   = int32(nox_color_white_2523948)
		v6  int32   = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*0))
		v7  int32   = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		v4  int32   = int32(*memmap.PtrUint32(0x8531A0, 2576))
	)
	if v4 == 0 {
		return
	}
	sub_57B350()
	var v70 *float32 = nox_xxx_plrGetMaxVarsPtr_57B360(int32(*(*uint8)(unsafe.Add(v4, 2251))))
	var v71 *float32 = nox_xxx_plrGetMaxVarsPtr_57B360(0)
	var v8 int32 = v6 + 11
	var v9 int32 = v7 + 15
	nox_xxx_drawSetTextColor_434390(v72)
	nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
	nox_client_drawRectFilledOpaque_49CE30(v8, v9, 200, 200)
	var v10 int32 = v8 + 2
	var v11 int32 = v9 + v1*2 + 3
	var v52 int32 = int32(*(*byte)(unsafe.Add(v4, 3684)))
	var v12 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("StatsLevel"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1878)
	nox_swprintf(&v77[0], v12, v52)
	nox_xxx_drawStringWrap_43FAF0(nil, &v77[0], v10, v11, 200, 0)
	var v13 int32 = v11 + v1 + 1
	if noxflags.HasGame(2048) {
		var (
			v53 int32     = int32(int64(nox_xxx_gamedataGetFloatTable_419D70(internCStr("XPTable"), int32(*(*byte)(unsafe.Add(v4, 3684))+1))))
			v41 int32     = int32(*memmap.PtrUint32(0x5D4594, 1062544))
			v14 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("StatsEXP"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1886)
		)
		nox_swprintf(&v77[0], v14, v41, v53)
		nox_xxx_drawStringWrap_43FAF0(nil, &v77[0], v10, v13, 200, 0)
	}
	var v15 int32 = v1*2 + 2 + v13
	var v16 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("StatsHealth"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1896)
	nox_xxx_drawStringWrap_43FAF0(nil, v16, v10, v15, 200, 0)
	nox_client_drawSetColor_434460(int32(nox_color_violet_2598268))
	nox_client_drawRectFilledOpaque_49CE30(v10+60, v15, 90, v1)
	var v54 float32 = float32(float64(int32(*(*uint32)(unsafe.Add(v4, 2247))*90)) / float64(*v70))
	var v67 int32 = int32(v54)
	nox_client_drawSetColor_434460(int32(nox_color_red_2589776))
	nox_client_drawRectFilledOpaque_49CE30(v10+60, v15, v67, v1)
	v68 = sub_470CC0() * 90
	var v55 float32 = float32(float64(v68) / float64(*v70))
	v67 = int32(v55)
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 940))
	nox_client_drawRectFilledOpaque_49CE30(v10+60, v15, v67, v1)
	var v56 int32 = int32(*v70)
	var v42 int32 = int32(*(*uint32)(unsafe.Add(v4, 2247)))
	var v17 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("MinMaxFormat"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1914)
	nox_swprintf(&v77[0], v17, v42, v56)
	nox_xxx_drawGetStringSize_43F840(dword_5d4594_1063636, &v77[0], &v67, nil, 0)
	var v69 float32 = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(&v69), 4*0)) = uint32(v15 + v73)
	nox_xxx_drawStringWrap_43FAF0(dword_5d4594_1063636, &v77[0], v10-v67+193, v15+v73, 200, 0)
	var v18 int32 = sub_470CC0()
	nox_swprintf(&v77[0], internWStr("%d"), v18)
	nox_xxx_drawStringWrap_43FAF0(dword_5d4594_1063636, &v77[0], v10+45, *(*int32)(unsafe.Add(unsafe.Pointer(&v69), 4*0)), 200, 0)
	var v19 int32 = v15 + v1 + 1
	if int32(*(*uint8)(unsafe.Add(v4, 2251))) != 0 {
		nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 944))
		nox_client_drawRectFilledOpaque_49CE30(v10+60, v19, 90, v1)
		v68 = int32(*(*uint32)(unsafe.Add(v4, 2243)) * 90)
		var v57 float32 = float32(float64(v68) / float64(*(*float32)(unsafe.Add(unsafe.Pointer(v70), unsafe.Sizeof(float32(0))*1))))
		v67 = int32(v57)
		var v20 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("StatsMana"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1941)
		nox_xxx_drawStringWrap_43FAF0(nil, v20, v10, v19, 200, 0)
		nox_client_drawSetColor_434460(int32(nox_color_blue_2650684))
		nox_client_drawRectFilledOpaque_49CE30(v10+60, v19, v67, v1)
		v68 = nox_xxx_cliGetMana_470DD0() * 90
		var v58 float32 = float32(float64(v68) / float64(*(*float32)(unsafe.Add(unsafe.Pointer(v70), unsafe.Sizeof(float32(0))*1))))
		v67 = int32(v58)
		nox_client_drawSetColor_434460(int32(nox_color_cyan_2649820))
		nox_client_drawRectFilledOpaque_49CE30(v10+60, v19, v67, v1)
		var v59 int32 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v70), unsafe.Sizeof(float32(0))*1)))
		var v43 int32 = int32(*(*uint32)(unsafe.Add(v4, 2243)))
		var v21 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("MinMaxFormat"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1952)
		nox_swprintf(&v77[0], v21, v43, v59)
		nox_xxx_drawGetStringSize_43F840(dword_5d4594_1063636, &v77[0], &v67, nil, 0)
		nox_xxx_drawStringWrap_43FAF0(dword_5d4594_1063636, &v77[0], v10-v67+193, v19+v73, 200, 0)
		var v22 int32 = nox_xxx_cliGetMana_470DD0()
		nox_swprintf(&v77[0], internWStr("%d"), v22)
		nox_xxx_drawStringWrap_43FAF0(dword_5d4594_1063636, &v77[0], v10+45, v19+v73, 200, 0)
		v19 += v1 + 1
	}
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 956))
	nox_client_drawRectFilledOpaque_49CE30(v10+60, v19, 90, v1)
	v68 = int32(*(*uint32)(unsafe.Add(v4, 2239)) * 90)
	var v60 float32 = float32(float64(v68) / float64(*(*float32)(unsafe.Add(unsafe.Pointer(v70), unsafe.Sizeof(float32(0))*3))))
	v67 = int32(v60)
	var v23 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("StatsStrength"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1975)
	nox_xxx_drawStringWrap_43FAF0(nil, v23, v10, v19, 200, 0)
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 2597996))
	nox_client_drawRectFilledOpaque_49CE30(v10+60, v19, v67, v1)
	var v61 int32 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v70), unsafe.Sizeof(float32(0))*3)))
	var v44 int32 = int32(*(*uint32)(unsafe.Add(v4, 2239)))
	var v24 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("MinMaxFormat"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1982)
	nox_swprintf(&v77[0], v24, v44, v61)
	nox_xxx_drawGetStringSize_43F840(dword_5d4594_1063636, &v77[0], &v67, nil, 0)
	nox_xxx_drawStringWrap_43FAF0(dword_5d4594_1063636, &v77[0], v10-v67+193, v19+v73, 200, 0)
	nox_swprintf(&v77[0], internWStr("%d"), *(*uint32)(unsafe.Add(v4, 2239)))
	nox_xxx_drawStringWrap_43FAF0(dword_5d4594_1063636, &v77[0], v10+45, v19+v73, 200, 0)
	var v25 int32 = v19 + v1 + 1
	nox_client_drawSetColor_434460(int32(nox_color_orange_2614256))
	nox_client_drawRectFilledOpaque_49CE30(v10+60, v25, 90, v1)
	v68 = int32(*(*uint32)(unsafe.Add(v4, 2235)) * 90)
	var v62 float32 = float32(float64(v68)/float64(*(*float32)(unsafe.Add(unsafe.Pointer(v70), unsafe.Sizeof(float32(0))*2))) + 0.5)
	v67 = int32(v62)
	var v26 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("StatsSpeed"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2006)
	nox_xxx_drawStringWrap_43FAF0(nil, v26, v10, v25, 200, 0)
	nox_client_drawSetColor_434460(int32(nox_color_yellow_2589772))
	nox_client_drawRectFilledOpaque_49CE30(v10+60, v25, v67, v1)
	nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
	v69 = float32(float64(*mem_getFloatPtr(0x5D4594, 1063100)) / (float64(*(*float32)(unsafe.Add(unsafe.Pointer(v71), unsafe.Sizeof(float32(0))*2))) * 1e-06))
	if int32(*memmap.PtrUint8(0x5D4594, 1062541))&2 != 0 {
		v69 = float32((float64(v67)+float64(v69))*1.25 - float64(v67))
	}
	if int32(*memmap.PtrUint8(0x5D4594, 1062540))&0x10 != 0 {
		v69 = float32((float64(v67)+float64(v69))*0.5 - float64(v67))
	}
	if float64(v69) >= 0.0 {
		if float64(v69) > 0.0 {
			v68 = int32(COERCE_FLOAT(uint32(int32(v69))))
			if v67+v68 > 90 {
				v68 = 90 - v67
			}
			nox_client_drawSetColor_434460(int32(nox_color_yellow_2589772))
			nox_client_drawRectFilledOpaque_49CE30(v67+v10+60, v25, v68, v1)
			nox_xxx_drawSetTextColor_434390(int32(nox_color_blue_2650684))
		}
	} else {
		nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 944))
		var v45 float32 = -v69
		var v46 int32 = int32(v45)
		var v27 int32 = int32(v69)
		nox_client_drawRectFilledOpaque_49CE30(v67+v27+v10+60, v25, v46, v1)
	}
	v68 = int32(float32(float64(v69) * 100.0 * 0.011111111))
	var v63 float32 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v70), unsafe.Sizeof(float32(0))*2))) * 100.0 / float64(*(*float32)(unsafe.Add(unsafe.Pointer(v71), unsafe.Sizeof(float32(0))*2))))
	var v64 int32 = int32(v63)
	var v47 float32 = float32(float64(*(*int32)(unsafe.Add(v4, 2235)))*100.0/float64(*(*float32)(unsafe.Add(unsafe.Pointer(v71), unsafe.Sizeof(float32(0))*2))) + float64(v68) + 0.5)
	var v48 int32 = int32(v47)
	var v28 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("MinMaxFormat"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2045)
	nox_swprintf(&v77[0], v28, v48, v64)
	var v76 int32 = 0
	nox_xxx_drawGetStringSize_43F840(dword_5d4594_1063636, &v77[0], &v76, nil, 0)
	*(*uint32)(unsafe.Add(unsafe.Pointer(&v69), 4*0)) = uint32(v25 + v73)
	nox_xxx_drawStringWrap_43FAF0(dword_5d4594_1063636, &v77[0], v10-v76+193, v25+v73, 200, 0)
	nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
	var v65 float32 = float32(float64(*(*int32)(unsafe.Add(v4, 2235)))*100.0/float64(*(*float32)(unsafe.Add(unsafe.Pointer(v71), unsafe.Sizeof(float32(0))*2))) + float64(v68) + 0.5)
	var v29 int32 = int32(v65)
	nox_swprintf(&v77[0], internWStr("%d"), v29)
	nox_xxx_drawStringWrap_43FAF0(dword_5d4594_1063636, &v77[0], v10+45, *(*int32)(unsafe.Add(unsafe.Pointer(&v69), 4*0)), 200, 0)
	nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
	var v30 int32 = v1*2 + 2 + v25
	if nox_strman_get_lang_code() == 6 || nox_strman_get_lang_code() == 8 {
		v10 += 39
	}
	nox_xxx_drawSetTextColor_434390(v72)
	var v31 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("StatsArmorLabel"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2072)
	nox_wcscpy(&v77[0], v31)
	var v75 int32 = 0
	nox_xxx_drawGetStringSize_43F840(nil, &v77[0], &v75, nil, 0)
	nox_xxx_drawStringWrap_43FAF0(nil, &v77[0], v10, v30, 0, 0)
	var v49 float32 = float32(float64(*mem_getFloatPtr(0x5D4594, 1062548))*1000.0 + 0.5)
	var v50 int32 = int32(v49)
	var v32 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("MinMaxFormat"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2076)
	nox_swprintf(&v77[0], v32, v50, 1000)
	nox_xxx_drawStringWrap_43FAF0(nil, &v77[0], v75+v10+5, v30, 0, 0)
	var v74 int32 = v30 + v1 + 1
	var itemsWeight int32 = 0
	for i := int32(0); i < NOX_INVENTORY_ROW_COUNT; i++ {
		var (
			v71a *nox_inventory_cell_t = &nox_client_inventory_grid_1050020[i]
			v33  *uint8                = &v71a.field_140
		)
		for j := int32(0); j < NOX_INVENTORY_COL_COUNT; j++ {
			if int32(*v33) != 0 {
				itemsWeight += int32(*v33) * int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v33), -int(4*35)))))), 298)))
			}
			v33 = (*uint8)(unsafe.Add(unsafe.Pointer(v33), NOX_INVENTORY_ROW_COUNT*unsafe.Sizeof(nox_inventory_cell_t{})))
		}
	}
	nox_xxx_drawSetTextColor_434390(v72)
	var v35 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("DollWeight"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2098)
	nox_xxx_drawGetStringSize_43F840(nil, v35, &v67, nil, 0)
	var v36 int32 = v74
	var v40 int32 = v74
	var v39 int32 = v10 + v75 - v67
	var v37 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("DollWeight"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2099)
	nox_xxx_drawStringWrap_43FAF0(nil, v37, v39, v40, 0, 0)
	if itemsWeight > int32(*(*uint16)(unsafe.Add(v4, 3652))) {
		v72 = int32(*memmap.PtrUint32(0x85B3FC, 940))
	}
	nox_xxx_drawSetTextColor_434390(v72)
	var v66 int32 = int32(*(*uint16)(unsafe.Add(v4, 3652)))
	var v38 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("MinMaxFormat"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 2107)
	nox_swprintf(&v77[0], v38, itemsWeight, v66)
	nox_xxx_drawStringWrap_43FAF0(nil, &v77[0], v75+v10+5, v36, 0, 0)
}
func sub_4649B0(a1 int32, a2 int32, a3 int32) int32 {
	var (
		result int32
		v4     *uint8
		v5     uint8
		v6     *uint32
		v7     *wchar2_t
		v8     *uint8
		v9     int32
		v10    int32
	)
	result = sub_464B40(a2, a3)
	if result == 0 {
		return 0
	}
	v4 = (*uint8)(unsafe.Pointer(&nox_client_inventory_grid_1050020[a3+NOX_INVENTORY_ROW_COUNT*a2]))
	v5 = nox_client_inventory_grid_1050020[a3+NOX_INVENTORY_ROW_COUNT*a2].field_140
	if int32(v5) != 0 {
		if *(*uint32)(unsafe.Add(a1, 112))&0x4000000 != 0 {
			return 0
		}
		if *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v4)), 108)) != *(*uint32)(unsafe.Add(a1, 108)) {
			return 0
		}
	}
	if int32(v5) >= 0x20 {
		return 0
	}
	if int32(v5) == 0 {
		v6 = (*uint32)(nox_new_drawable_for_thing(int32(*(*uint32)(unsafe.Add(a1, 108)))).C())
		*(*uint32)(unsafe.Pointer(v4)) = uint32(uintptr(unsafe.Pointer(v6)))
		if v6 == nil {
			v7 = nox_strman_loadString_40F1D0(internCStr("DrawablesExhausted"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 898)
			nox_xxx_printCentered_445490(v7)
			return 0
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*30)) |= 0x40000000
		alloc.Memcpy(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v4)), 432), unsafe.Add(a1, 432), 0x18)
		*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v4)), 292)) = *(*uint16)(unsafe.Add(a1, 292))
		*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v4)), 294)) = *(*uint16)(unsafe.Add(a1, 294))
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), int32(func() uint8 {
		p := (*uint8)(unsafe.Add(unsafe.Pointer(v4), 140))
		x := *p
		*p++
		return x
	}())*4+4)) = *(*uint32)(unsafe.Add(a1, 128))
	*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*33))) = 0
	for i := range array_5D4594_1049872 {
		v8 = (*uint8)(unsafe.Pointer(&array_5D4594_1049872[i]))
		v9 = int32(*(*uint32)(unsafe.Pointer(v8)))
		if *(*uint32)(unsafe.Pointer(v8)) != 0 {
			for *(*uint32)(unsafe.Add(v9, 128)) != *(*uint32)(unsafe.Add(a1, 128)) {
				v9 = int32(*(*uint32)(unsafe.Add(v9, 368)))
				if v9 == 0 {
					goto LABEL_17
				}
			}
			v10 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*34))))
			*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*33))) = 1
			if v10 != 0 {
				nox_xxx_clientSetAltWeapon_461550(nil)
				*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*34))) = 0
			}
			return 1
		}
	LABEL_17:
	}
	return 1
}
func sub_464BD0(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	var (
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v19 int32
		v20 int32
		v21 int32
		v26 int32
		v28 *uint32
		v29 *wchar2_t
		v30 int32
		v31 int32
		v32 int32
		v33 int32
		v34 int32
		v36 int32
		v37 int32
		v38 int32
		v40 *uint32
		v41 int32
		v42 int32
		v45 int32
		v47 int32
		v48 int32
		v49 unsafe.Pointer
		v50 *wchar2_t
		v51 int2
		v52 int32
		v53 int32
		v54 int32
		v55 int32
		v56 int2
		v57 int2
		v58 int2
		v59 int2
	)
	v59.field_4 = int32(a3 >> 16)
	v59.field_0 = int32(uint16(a3))
	sub_463370(dword_5d4594_1062456, (*nox_point)(unsafe.Pointer(&v59)), (*uint32)(unsafe.Pointer(&v56)))
	if sub_45D9B0() != 0 || int32(*memmap.PtrUint8(0x5D4594, 1049868)) != 2 {
		return 1
	}
	switch a2 {
	case 5:
		if nox_xxx_playerAnimCheck_4372B0() != 0 {
			return 1
		}
		if dword_5d4594_1049864 == 5 {
			v8 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136352)))
			if v8 != 0 {
				v9 = (v56.field_0 - 314) / 50
				v10 = int32((dword_5d4594_1062512 + uint32(v56.field_4) - 13) / 50)
				if sub_464B40(v9, v10) == 0 {
					return 1
				}
				var v11 = v10 + NOX_INVENTORY_ROW_COUNT*v9
				if int32(nox_client_inventory_grid_1050020[v11].field_140) != 0 {
					var dr = nox_client_inventory_grid_1050020[v11].field_0
					dword_5d4594_1063116 = unsafe.Pointer(dr)
					dr.Field_32 = nox_client_inventory_grid_1050020[v11].field_4
				} else {
					dword_5d4594_1063116 = nil
				}
				return 1
			}
			if sub_478030() != 0 {
				if sub_479870() != 0 {
					*((*uint8)(unsafe.Pointer(&v14))) = uint8(int8(bool2int32(sub_479880((*uint32)(unsafe.Pointer(&v56))))))
					if v14 != 0 {
						dword_5d4594_1063116 = uint32(sub_4798A0((*uint32)(unsafe.Pointer(&v56))))
						return 1
					}
				}
			}
		} else if dword_5d4594_1049864 == 6 {
			v15 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136352)))
			if v15 != 0 {
				v16 = (v56.field_0 - 314) / 50
				v17 = int32((dword_5d4594_1062512 + uint32(v56.field_4) - 13) / 50)
				if sub_464B40(v16, v17) != 0 {
					var v18 int32 = v17 + NOX_INVENTORY_ROW_COUNT*v16
					if int32(nox_client_inventory_grid_1050020[v18].field_140) != 0 {
						v19 = int32(uintptr(unsafe.Pointer(nox_client_inventory_grid_1050020[v18].field_0)))
						v20 = int32(nox_client_inventory_grid_1050020[v18].field_4)
						*(*uint32)(unsafe.Add(v19, 128)) = uint32(v20)
						if v19 != 0 {
							nox_xxx_trade_4657B0(int16(v20))
							return 1
						}
					}
				}
			}
		} else if int32(*memmap.PtrUint8(0x5D4594, 1049870)) != 1 || (func() bool {
			v21 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136336)))
			return v21 != 1
		}()) {
			if int32(*memmap.PtrUint8(0x5D4594, 1049869)) != 0 || nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136384))) != 0 || nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136400))) != 0 {
				if nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136384))) == 1 {
					return 0
				}
				if nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136400))) == 1 {
					return 0
				}
			} else {
				nox_xxx_wndSetCaptureMain_46ADC0(dword_5d4594_1062456)
				if sub_479590() == 3 {
					nox_xxx_clientTradeMB_4657E0(&v56)
				} else {
					sub_4658A0(dword_5d4594_1062456, &v56)
				}
				if *memmap.PtrUint32(0x5D4594, 1049848) != 0 {
					nox_xxx_cursorSetDraggedItem_477690((*client.Drawable)(*memmap.PtrPtr(0x5D4594, 1049848)))
					nox_xxx_setKeybTimeout_4160D0(0)
					*(*int2)(memmap.PtrOff(0x5D4594, 1062572)) = v56
					nox_xxx_clientPlaySoundSpecial_452D80(791, 100)
					return 1
				}
			}
		}
		return 1
	case 7:
		if nox_xxx_playerAnimCheck_4372B0() != 0 || dword_5d4594_1049864 == 6 {
			return 1
		}
		if int32(*memmap.PtrUint8(0x5D4594, 1049869)) == 0 {
			v26 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136368)))
			if v26 != 0 {
				if (v56.field_4-13)/50 == 1 {
					if dword_5d4594_1049864 != 5 {
						sub_465CA0()
						return 1
					}
					sub_462740()
					return 1
				}
			}
		}
		fallthrough
	case 6:
		if nox_xxx_playerAnimCheck_4372B0() != 0 || dword_5d4594_1049864 == 6 {
			return 1
		}
		var v43 int32 = 0
		if dword_5d4594_1049864 == 5 {
			if nox_xxx_cursorGetTypePrev_477630() == 7 {
				sub_462740()
				return 1
			}
		} else {
			nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_1062456)
		}
		if dword_5d4594_1049864 == 4 {
			v58 = v59
			sub_473970(&v58, &v58)
			v28 = (*uint32)(nox_drawable_find_49ABF0((*nox_point)(unsafe.Pointer(&v58)), 20).C())
			if v28 != nil {
				v57.field_0 = nox_win_width / 2
				v57.field_4 = nox_win_height / 2
				sub_473970(&v57, &v57)
				if (uint32(v57.field_0)-*(*uint32)(unsafe.Add(unsafe.Pointer(v28), 4*3)))*(uint32(v57.field_0)-*(*uint32)(unsafe.Add(unsafe.Pointer(v28), 4*3)))+(uint32(v57.field_4)-*(*uint32)(unsafe.Add(unsafe.Pointer(v28), 4*4)))*(uint32(v57.field_4)-*(*uint32)(unsafe.Add(unsafe.Pointer(v28), 4*4))) <= 5625 {
					dword_5d4594_1049864 = 0
					return 1
				}
				v29 = nox_strman_loadString_40F1D0(internCStr("ObjectTooFar"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 3858)
			} else {
				v29 = nox_strman_loadString_40F1D0(internCStr("NoObject"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 3869)
			}
			nox_xxx_printCentered_445490(v29)
			dword_5d4594_1049864 = 0
			return 1
		}
		if *memmap.PtrUint32(0x5D4594, 1049848) == 0 {
			return 1
		}
		if !nox_xxx_wndPointInWnd_46AAB0(dword_5d4594_1062456, v59.field_0, v59.field_4) || (func() int32 {
			v30 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136384)))
			return v30
		}()) != 0 || (func() int32 {
			v31 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136400)))
			return v31
		}()) != 0 {
			v58 = v59
			sub_473970(&v58, &v57)
			if dword_5d4594_1049856 == 1 {
				if sub_4C12C0() == 0 {
					nox_xxx_clientDrop_465BE0(&v57)
				}
			} else {
				v47 = dword_5d4594_1049800_inventory_click_row_index + dword_5d4594_1049796_inventory_click_column_index*14 + dword_5d4594_1049796_inventory_click_column_index*7
				v48 = int32(nox_client_inventory_grid_1050020[v47].field_140)
				if int32(nox_client_inventory_grid_1050020[v47].field_140) != 0 {
					v49 = nil
					nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_1062456)
					if *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 112))&0x13001000 != 0 {
						v49 = unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 432)
					}
					sub_4C05F0(0, 0)
					v53 = int32(*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 108)))
					v52 = int32(*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 128)))
					v51 = v58
					v50 = nox_strman_loadString_40F1D0(internCStr("DropLabel"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 4148)
					nox_gui_itemAmountDialog_4C0430(v50, v51.field_0, v51.field_4, v52, v53, v49, v48+1, 0, sub_465CD0, nil)
				} else if sub_4C12C0() == 0 {
					nox_xxx_clientDrop_465BE0(&v57)
				}
			}
			if dword_5d4594_1049856 != 0 {
				goto LABEL_121
			}
			v55 = dword_5d4594_1049800_inventory_click_row_index
			v54 = dword_5d4594_1049796_inventory_click_column_index
			sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), v54, v55)
			goto LABEL_121
		}
		v32 = int32(*memmap.PtrUint32(0x5D4594, 1062572) - uint32(v56.field_0))
		v33 = int32(*memmap.PtrUint32(0x5D4594, 1062576) - uint32(v56.field_4))
		if !nox_xxx_checkKeybTimeout_4160F0(0, gameFPS()/3) && v32*v32+v33*v33 < 100 {
			v34 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136352)))
			if v34 == 0 {
				goto LABEL_121
			}
			if sub_4C12C0() == 0 {
				if *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 112))&0x3001000 != 0 {
					var v35 int32 = dword_5d4594_1049800_inventory_click_row_index + NOX_INVENTORY_ROW_COUNT*dword_5d4594_1049796_inventory_click_column_index
					if nox_client_inventory_grid_1050020[v35].field_136 != 0 {
						nox_xxx_clientSetAltWeapon_461550(nil)
						nox_client_inventory_grid_1050020[v35].field_136 = 0
					} else if nox_client_inventory_grid_1050020[v35].field_132 != 0 {
						nox_xxx_clientDequip_464B70(*memmap.PtrInt32(0x5D4594, 1049848))
					} else {
						nox_xxx_clientKeyEquip_465C30(dword_5d4594_1049796_inventory_click_column_index, dword_5d4594_1049800_inventory_click_row_index)
					}
				} else {
					nox_xxx_clientUse_465C70(*memmap.PtrInt32(0x5D4594, 1049848))
				}
			}
			sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), dword_5d4594_1049796_inventory_click_column_index, dword_5d4594_1049800_inventory_click_row_index)
			goto LABEL_121
		}
		v36 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136336)))
		if v36 != 0 && int32(*memmap.PtrUint8(0x5D4594, 1049870)) == 0 {
			if dword_5d4594_1049856 == 0 {
				nox_xxx_clientEquip_4623B0(*memmap.PtrInt32(0x5D4594, 1049848))
				sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), dword_5d4594_1049796_inventory_click_column_index, dword_5d4594_1049800_inventory_click_row_index)
			}
			goto LABEL_121
		}
		v37 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136352)))
		if v37 == 0 {
			v55 = dword_5d4594_1049800_inventory_click_row_index
			v54 = dword_5d4594_1049796_inventory_click_column_index
			sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), v54, v55)
			goto LABEL_121
		}
		v38 = int32(*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 108)))
		if uint32(v38) == dword_5d4594_1062560 || uint32(v38) == *memmap.PtrUint32(0x5D4594, 1049728) || uint32(v38) == *memmap.PtrUint32(0x5D4594, 1049724) || uint32(v38) == dword_5d4594_1062556 || uint32(v38) == dword_5d4594_1062564 {
			sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), dword_5d4594_1049796_inventory_click_column_index, dword_5d4594_1049800_inventory_click_row_index)
			goto LABEL_121
		}
		dword_5d4594_1049804 = uint32((v56.field_0 - 314) / 50)
		dword_5d4594_1049808 = (dword_5d4594_1062512 + uint32(v56.field_4) - 13) / 50
		if sub_464B40((v56.field_0-314)/50, int32((dword_5d4594_1062512+uint32(v56.field_4)-13)/50)) == 0 {
			goto LABEL_121
		}
		if dword_5d4594_1049856 != 0 {
			var v39 int32 = int32(dword_5d4594_1049808 + NOX_INVENTORY_ROW_COUNT*dword_5d4594_1049804)
			if int32(nox_client_inventory_grid_1050020[v39].field_140) != 0 && (func() *uint32 {
				v40 = (*uint32)(nox_client_inventory_grid_1050020[v39].field_0.C())
				return v40
			}()) != nil && ((func() uint32 {
				v41 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v40), 4*28)))
				return uint32(v41) & 0x2000000
			}()) != 0 && *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 112))&0x2000000 != 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(v40), 4*29)) == *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 116)) || uint32(v41)&0x1001000 != 0 && *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1049848), 112))&0x1001000 != 0) {
				v42 = int32(nox_client_inventory_grid_1050020[v39].field_4)
				*memmap.PtrUint32(0x5D4594, 1049860) = 1
				*(*uint32)(unsafe.Add(unsafe.Pointer(v40), 4*32)) = uint32(v42)
				nox_xxx_clientEquip_4623B0(int32(uintptr(unsafe.Pointer(v40))))
			} else {
				*memmap.PtrUint32(0x5D4594, 1049860) = 1
				nox_xxx_clientDequip_464B70(*memmap.PtrInt32(0x5D4594, 1049848))
			}
			goto LABEL_121
		}
		if int32(nox_client_inventory_grid_1050020[dword_5d4594_1049800_inventory_click_row_index+NOX_INVENTORY_ROW_COUNT*dword_5d4594_1049796_inventory_click_column_index].field_140) != 0 {
			v55 = dword_5d4594_1049800_inventory_click_row_index
			v54 = dword_5d4594_1049796_inventory_click_column_index
			sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), v54, v55)
			goto LABEL_121
		}
		if sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), int32(dword_5d4594_1049804), int32(dword_5d4594_1049808)) == 0 {
			sub_4649B0(*memmap.PtrInt32(0x5D4594, 1049848), dword_5d4594_1049796_inventory_click_column_index, dword_5d4594_1049800_inventory_click_row_index)
			goto LABEL_121
		}
		nox_xxx_clientPlaySoundSpecial_452D80(792, 100)
		v43 = dword_5d4594_1049800_inventory_click_row_index + NOX_INVENTORY_ROW_COUNT*dword_5d4594_1049796_inventory_click_column_index
		v45 = int32(nox_client_inventory_grid_1050020[v43].field_136)
		if v45 != 0 {
			var v46 int32 = int32(dword_5d4594_1049808 + NOX_INVENTORY_ROW_COUNT*dword_5d4594_1049804)
			nox_client_inventory_grid_1050020[v46].field_136 = uint32(v45)
			nox_client_inventory_grid_1050020[v43].field_136 = 0
			dword_5d4594_1062480 = &nox_client_inventory_grid_1050020[v46]
		}
		sub_461B50()
	LABEL_121:
		nox_xxx_cursorResetDraggedItem_4776A0()
		if dword_5d4594_1049856 == 0 {
			nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(*(**uint64)(memmap.PtrOff(0x5D4594, 1049848)))))
		}
		*memmap.PtrUint32(0x5D4594, 1049848) = 0
		dword_5d4594_1049856 = 0
		return 1
	case 8:
		return 1
	case 9:
		if dword_5d4594_1049864 == 5 {
			sub_462740()
			return 1
		}
		return 0
	case 19:
		if nox_xxx_playerAnimCheck_4372B0() != 0 {
			return 1
		}
		v6 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136384)))
		if v6 != 0 {
			if dword_5d4594_1049864 == 5 {
				return 1
			}
			return 0
		}
		v7 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136400)))
		if v7 != 0 {
			if dword_5d4594_1049864 == 5 {
				return 1
			}
			return 0
		}
		nox_window_call_field_94_fnc(dword_5d4594_1062456, 16391, uintptr(*memmap.PtrInt32(0x5D4594, 1062500)), 0)
		return 1
	case 20:
		if nox_xxx_playerAnimCheck_4372B0() != 0 {
			return 1
		}
		v4 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136384)))
		if v4 != 0 {
			if dword_5d4594_1049864 == 5 {
				return 1
			}
			return 0
		}
		v5 = nox_xxx_pointInRect_4281F0(&v56, (*int4)(memmap.PtrOff(0x587000, 136400)))
		if v5 != 0 {
			if dword_5d4594_1049864 == 5 {
				return 1
			}
			return 0
		}
		nox_window_call_field_94_fnc(dword_5d4594_1062456, 16391, uintptr(*memmap.PtrInt32(0x5D4594, 1062504)), 0)
		return 1
	default:
		if dword_5d4594_1049864 == 5 {
			return 1
		}
		return 0
	}
}
func nox_xxx_cliInventorySpriteUpd_465A30() {
	var inventory_item_idx int32 = dword_5d4594_1049800_inventory_click_row_index + NOX_INVENTORY_ROW_COUNT*dword_5d4594_1049796_inventory_click_column_index
	if int32(nox_client_inventory_grid_1050020[inventory_item_idx].field_140) != 0 {
		var v1 *uint32 = (*uint32)(nox_new_drawable_for_thing(int32(nox_client_inventory_grid_1050020[inventory_item_idx].field_0.Field_27)).C())
		*memmap.PtrPtr(0x5D4594, 1049848) = unsafe.Pointer(v1)
		if v1 != nil {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*30)) |= 0x40000000
			*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 128)) = nox_client_inventory_grid_1050020[inventory_item_idx].field_4
			alloc.Memcpy(unsafe.Add(unsafe.Pointer(v1), 432), unsafe.Pointer(&nox_client_inventory_grid_1050020[inventory_item_idx].field_0.Field_108_1), 24)
			*(*uint16)(unsafe.Add(unsafe.Pointer(v1), 292)) = nox_client_inventory_grid_1050020[inventory_item_idx].field_0.Field_73_1
			*(*uint16)(unsafe.Add(unsafe.Pointer(v1), 294)) = nox_client_inventory_grid_1050020[inventory_item_idx].field_0.Field_73_2
			var v3 [2]*int32
			v3[0] = (*int32)(unsafe.Pointer(&nox_client_inventory_grid_1050020[inventory_item_idx].field_0))
			v3[1] = nil
			sub_461E60((***uint64)(unsafe.Pointer(&v3[0])))
		} else {
			var v2 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("DrawablesExhausted"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 1123)
			nox_xxx_printCentered_445490(v2)
		}
	}
}
func sub_466160(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	var v0 *wchar2_t
	if int32(*memmap.PtrUint8(0x5D4594, 1049868)) == 2 {
		v0 = nox_strman_loadString_40F1D0(internCStr("CloseInventoryTT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 410)
	} else {
		v0 = nox_strman_loadString_40F1D0(internCStr("OpenInventoryTT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 414)
	}
	nox_xxx_cursorSetTooltip_4776B0(v0)
	return 1
}
func sub_4661D0(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	var (
		v0 *wchar2_t
		v2 *wchar2_t
	)
	if dword_5d4594_1062480 != 0 {
		v0 = nox_xxx_clientAskInfoMb_4BF050((*client.Drawable)(unsafe.Pointer(*dword_5d4594_1062480)))
		nox_xxx_cursorSetTooltip_4776B0(v0)
	} else {
		v2 = nox_strman_loadString_40F1D0(internCStr("ToolTipWeapon2Area"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 3331)
		nox_xxx_cursorSetTooltip_4776B0(v2)
	}
	return 1
}
func sub_466660(a1 int32, a2 *int2) *wchar2_t {
	var (
		v2     int32
		v3     int32
		result *wchar2_t
		v5     *wchar2_t
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v13    int32
	)
	v2 = nox_xxx_pointInRect_4281F0(a2, (*int4)(memmap.PtrOff(0x587000, 136336)))
	if v2 == 0 {
		if int32(*memmap.PtrUint8(0x5D4594, 1049869)) == 0 {
			v6 = nox_xxx_pointInRect_4281F0(a2, (*int4)(memmap.PtrOff(0x587000, 136368)))
			if v6 != 0 {
				v7 = a2.field_4 - 13
				v8 = v7 / 50
				v9 = 20
				dword_5d4594_1049796_inventory_click_column_index = v7 / 50
			} else {
				v10 = nox_xxx_pointInRect_4281F0(a2, (*int4)(memmap.PtrOff(0x587000, 136352)))
				if v10 == 0 {
					return nil
				}
				v8 = (a2.field_0 - 314) / 50
				dword_5d4594_1049796_inventory_click_column_index = (a2.field_0 - 314) / 50
				v9 = int32((uint32(a2.field_4) + dword_5d4594_1062512 - 13) / 50)
			}
			dword_5d4594_1049800_inventory_click_row_index = v9
			if sub_464B40(v8, v9) != 0 {
				var v12 int32 = dword_5d4594_1049800_inventory_click_row_index + NOX_INVENTORY_ROW_COUNT*dword_5d4594_1049796_inventory_click_column_index
				if int32(nox_client_inventory_grid_1050020[v12].field_140) != 0 {
					v13 = int32(uintptr(unsafe.Pointer(nox_client_inventory_grid_1050020[v12].field_0)))
					*(*uint32)(unsafe.Add(v13, 128)) = nox_client_inventory_grid_1050020[v12].field_4
					return nox_xxx_clientAskInfoMb_4BF050((*client.Drawable)(v13))
				}
			}
		}
		return nil
	}
	if int32(*memmap.PtrUint8(0x5D4594, 1049870)) == 1 {
		return nil
	}
	v3 = sub_465990((*uint32)(unsafe.Pointer(a2)))
	if v3 == -1 {
		return nox_strman_loadString_40F1D0(internCStr("DollRegionError"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 3155)
	}
	v5 = *(**wchar2_t)(unsafe.Pointer(&array_5D4594_1049872[v3]))
	if v5 != nil {
		result = nox_xxx_clientAskInfoMb_4BF050((*client.Drawable)(unsafe.Pointer(v5)))
	} else {
		result = nox_strman_loadString_40F1D0(internCStr("ToolTipDrag"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 3159)
	}
	return result
}
func nox_xxx_inventroryOnHovewerSub_4667E0(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	var (
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  *wchar2_t
		v9  int32
		v10 *wchar2_t
		v11 int32
		v12 *wchar2_t
		v13 int32
		v14 *wchar2_t
		v15 int2
	)
	v3 = 40
	v15.field_0 = int32(uint16(a3))
	v15.field_4 = int32(a3 >> 16)
	v4 = 0
	for v3 <= int32(uint16(a3)) {
		v3 += 35
		v4++
	}
	v5 = 0
	for {
		if uint32(1<<v5)&*memmap.PtrUint32(0x5D4594, 1062540) != 0 && v5 != 31 {
			v4--
		}
		if v4 < 0 {
			break
		}
		v5++
		if v5 >= 32 {
			break
		}
	}
	if v5 != 32 {
		v6 = nox_xxx_getEnchantSpell_424920(v5)
		v7 = nox_xxx_spellTitle_424930(v6)
		nox_xxx_cursorSetTooltip_4776B0(v7)
		return 1
	}
	v9 = 0
	for {
		if (1<<v9)&int32(*memmap.PtrUint8(0x5D4594, 1062536)) != 0 {
			v4--
		}
		if v4 < 0 {
			break
		}
		v9++
		if v9 >= 6 {
			break
		}
	}
	if v9 != 6 {
		v10 = sub_413480(1 << v9)
		nox_xxx_cursorSetTooltip_4776B0(v10)
		return 1
	}
	if !noxflags.HasGame(4096) {
		nox_xxx_cursorSetTooltip_4776B0(nil)
		return 1
	}
	v11 = nox_xxx_pointInRect_4281F0(&v15, (*int4)(memmap.PtrOff(0x5D4594, 1049812)))
	if v11 == 1 {
		v12 = nox_strman_loadString_40F1D0(internCStr("thing.db:AnkhGUI"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 4385)
		nox_xxx_cursorSetTooltip_4776B0(v12)
		return 1
	}
	v13 = nox_xxx_pointInRect_4281F0(&v15, (*int4)(memmap.PtrOff(0x5D4594, 1049828)))
	if v13 == 1 && sub_4BFD30() == 1 {
		v14 = nox_strman_loadString_40F1D0(internCStr("GeneralPrint:TooltipKeyIcon"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 4388)
		nox_xxx_cursorSetTooltip_4776B0(v14)
		return 1
	} else {
		nox_xxx_cursorSetTooltip_4776B0(nil)
		return 1
	}
}
func sub_466E20(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	a1 := (*uint32)(win.C())
	var v1 *wchar2_t
	switch *a1 {
	case 0x2391:
		v1 = nox_strman_loadString_40F1D0(internCStr("JournalModeTT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 424)
		nox_xxx_cursorSetTooltip_4776B0(v1)
		return 1
	case 0x2392:
		v1 = nox_strman_loadString_40F1D0(internCStr("InventoryModeTT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 428)
		nox_xxx_cursorSetTooltip_4776B0(v1)
		return 1
	case 0x2393:
		v1 = nox_strman_loadString_40F1D0(internCStr("StatsModeTT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 432)
		nox_xxx_cursorSetTooltip_4776B0(v1)
		return 1
	case 0x2394:
		v1 = nox_strman_loadString_40F1D0(internCStr("PaperDollModeTT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 436)
		nox_xxx_cursorSetTooltip_4776B0(v1)
		return 1
	case 0x2397:
		v1 = nox_strman_loadString_40F1D0(internCStr("CloseInventoryTT"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 440)
		nox_xxx_cursorSetTooltip_4776B0(v1)
		return 1
	default:
		return 0
	}
}
func nox_xxx_inventoryNameSignInit_4671E0() int32 {
	var (
		result int32
		v1     int32
		v2     *wchar2_t
		v3     int32
		v4     *wchar2_t
		v5     [100]byte
	)
	nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1062588)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1063676)))
	if noxflags.HasGame(4096) || nox_xxx_isQuest_4D6F50() != 0 || (func() int32 {
		result = sub_4D6F70()
		return result
	}()) != 0 {
		result = int32(dword_5d4594_1049844)
		if dword_5d4594_1049844 > NOX_PLAYER_MAX_LEVEL {
			result = NOX_PLAYER_MAX_LEVEL
		}
		v1 = int32(*memmap.PtrUint32(0x8531A0, 2576))
	} else {
		v1 = int32(*memmap.PtrUint32(0x8531A0, 2576))
		if *memmap.PtrUint32(0x8531A0, 2576) == 0 {
			return result
		}
		result = int32(*(*byte)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 3684)))
	}
	if v1 != 0 {
		nox_sprintf(&v5[0], internCStr("experience:%s%d"), *memmap.PtrUint32(0x587000, uintptr(int32(*(*uint8)(unsafe.Add(v1, 2251)))*4+29456)), result)
		v4 = nox_strman_loadString_40F1D0(&v5[0], nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 4763)
		v3 = int32(*memmap.PtrUint32(0x8531A0, 2576) + 4704)
		v2 = nox_strman_loadString_40F1D0(internCStr("ElaborateNameFormat"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 4761)
		result = nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1062588)), v2, v3, v4)
	}
	return result
}
func sub_467750(a1 int32, a2 int8) int32 {
	if a1 != 0 {
		var v2 *uint32 = (*uint32)(unsafe.Pointer(sub_461EF0(a1)))
		if v2 != nil {
			if dword_5d4594_1062480 != 0 {
				*(*uint32)(unsafe.Add(dword_5d4594_1062480, 136)) = 0
			}
			dword_5d4594_1062480 = *v2
			*(*uint32)(unsafe.Add(dword_5d4594_1062480, 136)) = 1
			return 1
		}
	} else {
		if dword_5d4594_1062480 != 0 {
			*(*uint32)(unsafe.Add(dword_5d4594_1062480, 136)) = 0
			dword_5d4594_1062480 = nil
		}
	}
	if int32(a2) != 0 {
		if int32(a2) != 1 {
			return 0
		}
		var v5 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("Weapon2CantUse"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\guiinv.c"), 5379)
		nox_xxx_printCentered_445490(v5)
		if dword_5d4594_1062484 == 0 {
			return 0
		}
		var v6 *int32 = (*int32)(unsafe.Pointer(sub_461EF0(int32(dword_5d4594_1062484))))
		if v6 != nil {
			nox_xxx_clientSetAltWeapon_461550(*v6)
			return 0
		}
	}
	dword_5d4594_1062484 = 0
	return 0
}
