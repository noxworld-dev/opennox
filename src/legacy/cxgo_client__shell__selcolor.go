package legacy

import (
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	memmap "github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_game_showSelColor_4A5D00() int {
	var (
		v0     *byte
		result int32
		i      int32
		v3     *uint32
		j      int32
		v5     *uint32
		v6     *wchar2_t
		v7     *uint32
	)
	nox_game_addStateCode_43BDD0(700)
	v0 = nox_xxx_getHostInfoPtr_431770()
	dword_5d4594_1307784 = uint32(uintptr(unsafe.Pointer(v0)))
	*(*byte)(unsafe.Add(unsafe.Pointer(v0), 67)) = 0
	result = int32(uintptr(unsafe.Pointer(nox_new_window_from_file(internCStr("SelColor.wnd"), sub_4A7330))))
	dword_5d4594_1308084 = uint32(result)
	if result != 0 {
		nox_xxx_wndSetWindowProc_46B300((*gui.Window)(result), guiSelProc2)
		result = int32(uintptr(unsafe.Pointer(nox_gui_makeAnimation_43C5B0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 0, 0, 0, -440, 0, 20, 0, -40))))
		nox_wnd_xxx_1308092 = (*gui.Anim)(result)
		if result != 0 {
			nox_wnd_xxx_1308092.StateID = 700
			nox_wnd_xxx_1308092.Func12Ptr.Set(sub_4A6890)
			nox_wnd_xxx_1308092.FncDoneOutPtr.Set(sub_4A6C90)
			sub_4A5E90()
			for i = 720; i <= 729; i++ {
				v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), i)))
				nox_xxx_wndSetDrawFn_46B340((*gui.Window)(unsafe.Pointer(v3)), sub_4A6D20)
			}
			for j = 761; j <= 792; j++ {
				v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), j)))
				nox_xxx_wndSetDrawFn_46B340((*gui.Window)(unsafe.Pointer(v5)), sub_4A6D20)
			}
			if dword_587000_171388 != 0 {
				v6 = nox_strman_loadString_40F1D0(internCStr("DefaultName"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\SelColor.c"), 1138)
				nox_window_call_field_94_fnc((*gui.Window)(dword_5d4594_1308152), 16414, uintptr(unsafe.Pointer(v6)), 0)
			}
			nox_xxx_wndRetNULL_46A8A0()
			dword_5d4594_1308088 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 760))))
			nox_xxx_wndSetProc_46B2C0(dword_5d4594_1308088, sub_4A7330)
			nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1308088, sub_4A7270)
			sub_46B120((*gui.Window)(unsafe.Pointer(dword_5d4594_1308088)), nil)
			sub_4BFAD0()
			v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1308084)), 740)))
			nox_xxx_wndSetDrawFn_46B340((*gui.Window)(unsafe.Pointer(v7)), sub_4A6DC0)
			result = 1
		}
	}
	return int(result)
}
func sub_4A68C0() *wchar2_t {
	var (
		v0     *wchar2_t
		v1     *wchar2_t
		v2     *wchar2_t
		v3     *uint8
		v4     int32
		v5     int32
		v6     int32
		v7     *uint8
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    *uint8
		v13    int32
		v14    int32
		v15    int32
		v16    *uint8
		v17    int32
		v18    int32
		v19    int32
		v20    *uint8
		result *wchar2_t
	)
	v0 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc((*gui.Window)(dword_5d4594_1308152), 16413, 0, 0)))
	if *v0 == 0 {
		v1 = nox_strman_loadString_40F1D0(internCStr("DefaultName"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\SelColor.c"), 225)
		nox_wcscpy(v0, v1)
	}
	nox_wcscpy(dword_5d4594_1307784, v0)
	if sub_4A6B50(dword_5d4594_1307784) == 0 {
		v2 = nox_strman_loadString_40F1D0(internCStr("DefaultName"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\SelColor.c"), 232)
		nox_wcscpy(dword_5d4594_1307784, v2)
	}
	v3 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(((*(*uint32)(unsafe.Add(dword_5d4594_1308096, 32))>>16)+uint32(int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308096, 32))))*32)))*3+1307796))
	v4 = int32(dword_5d4594_1307784 + 71)
	*(*uint16)(unsafe.Add(dword_5d4594_1307784, 71)) = *(*uint16)(unsafe.Pointer(v3))
	*(*uint8)(unsafe.Add(v4, 2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v3), 2))
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308136, 4)))&8 != 0 {
		v7 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(((*(*uint32)(unsafe.Add(dword_5d4594_1308100, 32))>>16)+uint32(int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308100, 32))))*32)))*3+1307796))
		v8 = int32(dword_5d4594_1307784 + 68)
		*(*uint16)(unsafe.Add(dword_5d4594_1307784, 68)) = *(*uint16)(unsafe.Pointer(v7))
		*(*uint8)(unsafe.Add(v8, 2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v7), 2))
	} else {
		v5 = int32(dword_5d4594_1307784 + 71)
		v6 = int32(dword_5d4594_1307784 + 68)
		*(*uint16)(unsafe.Add(dword_5d4594_1307784, 68)) = *(*uint16)(unsafe.Add(dword_5d4594_1307784, 71))
		*(*uint8)(unsafe.Add(v6, 2)) = *(*uint8)(unsafe.Add(v5, 2))
	}
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308140, 4)))&8 != 0 {
		v11 = int32(dword_5d4594_1307784 + 74)
		v12 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(((*(*uint32)(unsafe.Add(dword_5d4594_1308104, 32))>>16)+uint32(int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308104, 32))))*32)))*3+1307796))
		*(*uint16)(unsafe.Add(dword_5d4594_1307784, 74)) = *(*uint16)(unsafe.Pointer(v12))
		*(*uint8)(unsafe.Add(v11, 2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v12), 2))
	} else {
		v9 = int32(dword_5d4594_1307784 + 71)
		v10 = int32(dword_5d4594_1307784 + 74)
		*(*uint16)(unsafe.Add(dword_5d4594_1307784, 74)) = *(*uint16)(unsafe.Add(dword_5d4594_1307784, 71))
		*(*uint8)(unsafe.Add(v10, 2)) = *(*uint8)(unsafe.Add(v9, 2))
	}
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308144, 4)))&8 != 0 {
		v15 = int32(dword_5d4594_1307784 + 77)
		v16 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(((*(*uint32)(unsafe.Add(dword_5d4594_1308108, 32))>>16)+uint32(int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308108, 32))))*32)))*3+1307796))
		*(*uint16)(unsafe.Add(dword_5d4594_1307784, 77)) = *(*uint16)(unsafe.Pointer(v16))
		*(*uint8)(unsafe.Add(v15, 2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v16), 2))
	} else {
		v13 = int32(dword_5d4594_1307784 + 71)
		v14 = int32(dword_5d4594_1307784 + 77)
		*(*uint16)(unsafe.Add(dword_5d4594_1307784, 77)) = *(*uint16)(unsafe.Add(dword_5d4594_1307784, 71))
		*(*uint8)(unsafe.Add(v14, 2)) = *(*uint8)(unsafe.Add(v13, 2))
	}
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308148, 4)))&8 != 0 {
		v19 = int32(dword_5d4594_1307784 + 80)
		v20 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(((*(*uint32)(unsafe.Add(dword_5d4594_1308112, 32))>>16)+uint32(int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308112, 32))))*32)))*3+1307796))
		*(*uint16)(unsafe.Add(dword_5d4594_1307784, 80)) = *(*uint16)(unsafe.Pointer(v20))
		*(*uint8)(unsafe.Add(v19, 2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v20), 2))
	} else {
		v17 = int32(dword_5d4594_1307784 + 71)
		v18 = int32(dword_5d4594_1307784 + 80)
		*(*uint16)(unsafe.Add(dword_5d4594_1307784, 80)) = *(*uint16)(unsafe.Add(dword_5d4594_1307784, 71))
		*(*uint8)(unsafe.Add(v18, 2)) = *(*uint8)(unsafe.Add(v17, 2))
	}
	*(*uint8)(unsafe.Add(dword_5d4594_1307784, 83)) = uint8(*(*uint32)(unsafe.Add(dword_5d4594_1308116, 32)) >> 16)
	*(*uint8)(unsafe.Add(dword_5d4594_1307784, 84)) = uint8(*(*uint32)(unsafe.Add(dword_5d4594_1308120, 32)) >> 16)
	*(*uint8)(unsafe.Add(dword_5d4594_1307784, 85)) = uint8(*(*uint32)(unsafe.Add(dword_5d4594_1308124, 32)) >> 16)
	*(*uint8)(unsafe.Add(dword_5d4594_1307784, 86)) = uint8(*(*uint32)(unsafe.Add(dword_5d4594_1308128, 32)) >> 16)
	result = dword_5d4594_1307784
	*(*uint8)(unsafe.Add(dword_5d4594_1307784, 87)) = uint8(*(*uint32)(unsafe.Add(dword_5d4594_1308132, 32)) >> 16)
	return result
}
func sub_4A75C0() int32 {
	var (
		v0  *wchar2_t
		v1  *wchar2_t
		v2  *wchar2_t
		v3  int8
		v4  *uint8
		v5  int16
		v6  int16
		v7  uint8
		v8  int32
		v9  int8
		v10 *uint8
		v11 int32
		v12 *uint8
		v13 *byte
		v14 int16
		v15 uint8
		v16 *byte
		v17 int32
		v18 *byte
		i   int32
		v20 *FILE
		v21 *byte
		v23 int8
		v24 [16]byte
		v25 [1280]byte
	)
	if noxflags.HasGame(2048) {
		nox_savegame_rm_4DBE10(internCStr("WORKING"), 0)
	}
	libc.MemSet(unsafe.Pointer(&v25[0]), 0, 0x4FC)
	*(*uint16)(unsafe.Pointer(&v25[1276])) = 0
	v0 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc((*gui.Window)(dword_5d4594_1308152), 16413, 0, 0)))
	if *v0 == 0 {
		v1 = nox_strman_loadString_40F1D0(internCStr("DefaultName"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\SelColor.c"), 605)
		nox_wcscpy(v0, v1)
	}
	nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v25[1224])), v0)
	if sub_4A6B50((*wchar2_t)(unsafe.Pointer(&v25[1224]))) == 0 {
		v2 = nox_strman_loadString_40F1D0(internCStr("DefaultName"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\SelColor.c"), 612)
		nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v25[1224])), v2)
	}
	v3 = int8(*(*uint8)(unsafe.Add(dword_5d4594_1307784, 66)))
	v25[1276] = 1
	v25[1274] = byte(v3)
	v4 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(((*(*uint32)(unsafe.Add(dword_5d4594_1308096, 32))>>16)+uint32(int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308096, 32))))*32)))*3+1307796))
	*(*uint16)(unsafe.Pointer(&v25[1204])) = *(*uint16)(unsafe.Pointer(v4))
	v5 = int16(*(*uint16)(unsafe.Pointer(v4)))
	v25[1206] = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), 2))
	v23 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 2)))
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308136, 4)))&8 != 0 {
		v8 = int32((*(*uint32)(unsafe.Add(dword_5d4594_1308100, 32)) >> 16) + uint32(int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308100, 32))))*32))
		*(*uint16)(unsafe.Pointer(&v25[1207])) = *memmap.PtrUint16(0x5D4594, uintptr(v8*3)+1307796)
		v7 = *memmap.PtrUint8(0x5D4594, uintptr(v8*3)+1307798)
	} else {
		v6 = int16(*(*uint16)(unsafe.Pointer(v4)))
		v7 = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), 2))
		*(*uint16)(unsafe.Pointer(&v25[1207])) = uint16(v6)
	}
	v25[1209] = v7
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308140, 4)))&8 != 0 {
		v10 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(((*(*uint32)(unsafe.Add(dword_5d4594_1308104, 32))>>16)+uint32(int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308104, 32))))*32)))*3+1307796))
		*(*uint16)(unsafe.Pointer(&v25[1210])) = *(*uint16)(unsafe.Pointer(v10))
		v25[1212] = *(*uint8)(unsafe.Add(unsafe.Pointer(v10), 2))
		v9 = v23
	} else {
		v9 = v23
		*(*uint16)(unsafe.Pointer(&v25[1210])) = uint16(v5)
		v25[1212] = byte(v23)
	}
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308144, 4)))&8 != 0 {
		v11 = int32((*(*uint32)(unsafe.Add(dword_5d4594_1308108, 32)) >> 16) + uint32(int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308108, 32))))*32))
		*(*uint16)(unsafe.Pointer(&v25[1213])) = *memmap.PtrUint16(0x5D4594, uintptr(v11*3)+1307796)
		v25[1215] = *memmap.PtrUint8(0x5D4594, uintptr(v11*3)+1307798)
	} else {
		*(*uint16)(unsafe.Pointer(&v25[1213])) = uint16(v5)
		v25[1215] = byte(v9)
	}
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1308148, 4)))&8 != 0 {
		v12 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(((*(*uint32)(unsafe.Add(dword_5d4594_1308112, 32))>>16)+uint32(int32(uint16(*(*uint32)(unsafe.Add(dword_5d4594_1308112, 32))))*32)))*3+1307796))
		*(*uint16)(unsafe.Pointer(&v25[1216])) = *(*uint16)(unsafe.Pointer(v12))
		v25[1218] = *(*uint8)(unsafe.Add(unsafe.Pointer(v12), 2))
	} else {
		*(*uint16)(unsafe.Pointer(&v25[1216])) = uint16(v5)
		v25[1218] = byte(v9)
	}
	v25[1219] = byte(*(*uint32)(unsafe.Add(dword_5d4594_1308116, 32)) >> 16)
	v25[1220] = byte(*(*uint32)(unsafe.Add(dword_5d4594_1308120, 32)) >> 16)
	v25[1221] = byte(*(*uint32)(unsafe.Add(dword_5d4594_1308124, 32)) >> 16)
	v25[1222] = byte(*(*uint32)(unsafe.Add(dword_5d4594_1308128, 32)) >> 16)
	v25[1223] = byte(*(*uint32)(unsafe.Add(dword_5d4594_1308132, 32)) >> 16)
	v13 = nox_fs_root()
	v14 = int16(*memmap.PtrUint16(0x587000, 171768))
	libc.StrCpy(&v25[4], v13)
	v15 = *memmap.PtrUint8(0x587000, 171770)
	v16 = &v25[libc.StrLen(&v25[4])+4]
	*(*uint32)(unsafe.Pointer(v16)) = *memmap.PtrUint32(0x587000, 171764)
	*((*uint16)(unsafe.Add(unsafe.Pointer(v16), unsafe.Sizeof(uint16(0))*2))) = uint16(v14)
	*(*byte)(unsafe.Add(unsafe.Pointer(v16), 6)) = v15
	if noxflags.HasGame(2048) {
		v17 = int32(*memmap.PtrUint32(0x587000, 171776))
		v18 = &v25[libc.StrLen(&v25[4])+4]
		*(*uint32)(unsafe.Pointer(v18)) = *memmap.PtrUint32(0x587000, 171772)
		*((*uint32)(unsafe.Add(unsafe.Pointer(v18), 4*1))) = uint32(v17)
		*(*uint16)(unsafe.Pointer(&v25[libc.StrLen(&v25[4])+4])) = *memmap.PtrUint16(0x587000, 171780)
	}
	nox_fs_mkdir(&v25[4])
	nox_fs_set_workdir(&v25[4])
	i = 0
	if noxflags.HasGame(2048) {
		libc.StrCpy(&v24[0], internCStr("Player.plr"))
	} else {
		for i = 0; i < 100; i++ {
			nox_sprintf(&v24[0], internCStr("%.6s%2.2d.plr"), &v25[1224], i)
			v20 = nox_fs_open(&v24[0])
			if v20 == nil {
				break
			}
			nox_fs_close(v20)
		}
	}
	v21 = nox_fs_root()
	nox_fs_set_workdir(v21)
	if i > 99 {
		return 0
	}
	libc.StrCat(&v25[4], &v24[0])
	if noxflags.HasGame(2048) {
		if v25[1274] == 0 {
			nox_xxx_gameSetMapPath_409D70(internCStr("war01a.map"))
		} else if v25[1274] == 1 {
			nox_xxx_gameSetMapPath_409D70(internCStr("wiz01a.map"))
		} else if v25[1274] == 2 {
			nox_xxx_gameSetMapPath_409D70(internCStr("con01a.map"))
		}
	}
	return sub_41CEE0(unsafe.Pointer(&v25[0]), 1)
}
