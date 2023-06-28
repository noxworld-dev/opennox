package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_49B4B0(a1 *uint16) int32 {
	var (
		v1     *wchar2_t
		v2     *wchar2_t
		v3     *wchar2_t
		v4     *uint32
		v5     *uint32
		v6     *uint32
		v7     *uint32
		v8     *uint32
		v9     *uint32
		result int32
		v11    int32
		v12    int32
		v13    int32
		v14    int32
		v15    int32
	)
	nox_window_set_hidden((*gui.Window)(dword_5d4594_1303452), 0)
	nox_xxx_wnd_46ABB0((*gui.Window)(dword_5d4594_1303452), 1)
	nox_xxx_clientPlaySoundSpecial_452D80(1007, 100)
	nox_window_get_size((*gui.Window)(dword_5d4594_1303452), &v15, &v14)
	nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(dword_5d4594_1303452)), nox_win_width/2-v15/2, nox_win_height/2-v14/2)
	v11 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(uint16(0))*1)))
	v1 = nox_strman_loadString_40F1D0(internCStr("GGOver.wnd:GeneratorsDestroyed"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c"), 178)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1302172)), v1, v11)
	v12 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(uint16(0))*2)))
	v2 = nox_strman_loadString_40F1D0(internCStr("GGOver.wnd:NumSecretsFound"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c"), 181)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1301916)), v2, v12)
	v13 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(uint16(0))*3)))
	v3 = nox_strman_loadString_40F1D0(internCStr("GGOver.wnd:Kills"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c"), 183)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1302428)), v3, v13)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1303196)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1303460)))
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1303452)), 10710)))
	sub_46AEE0(int32(uintptr(unsafe.Pointer(v4))), int32(uintptr(memmap.PtrOff(0x5D4594, 1302172))))
	v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1303452)), 10705)))
	sub_46AEE0(int32(uintptr(unsafe.Pointer(v5))), int32(uintptr(memmap.PtrOff(0x5D4594, 1302940))))
	v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1303452)), 10706)))
	sub_46AEE0(int32(uintptr(unsafe.Pointer(v6))), int32(uintptr(memmap.PtrOff(0x5D4594, 1302684))))
	v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1303452)), 10707)))
	sub_46AEE0(int32(uintptr(unsafe.Pointer(v7))), int32(uintptr(memmap.PtrOff(0x5D4594, 1301916))))
	v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1303452)), 10708)))
	sub_46AEE0(int32(uintptr(unsafe.Pointer(v8))), int32(uintptr(memmap.PtrOff(0x5D4594, 1302428))))
	v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1303452)), 10711)))
	sub_46AEE0(int32(uintptr(unsafe.Pointer(v9))), int32(uintptr(memmap.PtrOff(0x5D4594, 1303196))))
	result = int32(gameFrame())
	*memmap.PtrUint32(0x5D4594, 1303456) = gameFrame()
	return result
}
func sub_49B6E0() int32 {
	var (
		result int32
		v1     int32
		v2     *wchar2_t
		v3     *uint32
		v4     int32
	)
	result = int32(dword_5d4594_1303452)
	if dword_5d4594_1303452 == 0 {
		return result
	}
	result = wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(dword_5d4594_1303452))
	if result != 0 {
		return result
	}
	v1 = int32(*memmap.PtrUint32(0x5D4594, 1303456) + gameFPS()*30 - gameFrame())
	if v1 < 0 {
		v1 = 0
	}
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 && int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2064))) == 31 {
		nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1301852)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1303464)))
	} else {
		v4 = int32(uint32(v1) / gameFPS())
		v2 = nox_strman_loadString_40F1D0(internCStr("Rules.c:Time"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c"), 265)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1301852)), internWStr("%s - %d"), v2, v4)
	}
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1303452)), 10712)))
	result = sub_46AEE0(int32(uintptr(unsafe.Pointer(v3))), int32(uintptr(memmap.PtrOff(0x5D4594, 1301852))))
	return result
}
