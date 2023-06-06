package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_gui_4AD320(a1 int32) int32 {
	var (
		v1  int32
		v3  *uint32
		v4  *uint32
		v5  *uint32
		v6  *uint32
		v7  **byte
		v8  *wchar2_t
		v9  *uint32
		v10 *uint32
	)
	v1 = nox_strman_get_lang_code()
	if nox_xxx_guiFontHeightMB_43F320(nil) > 10 {
		v1 = 2
	}
	if dword_5d4594_1309812 != 0 {
		return 0
	}
	v3 = (*uint32)(unsafe.Pointer(nox_new_window_from_file(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1*4)+173556)), nox_xxx_windowServerOptionsGeneralProc_4AD5D0)))
	dword_5d4594_1309812 = uint32(uintptr(unsafe.Pointer(v3)))
	sub_46B120((*gui.Window)(unsafe.Pointer(v3)), (*gui.Window)(unsafe.Pointer(uintptr(a1))))
	nox_xxx_wndSetDrawFn_46B340(*(**gui.Window)(unsafe.Pointer(&dword_5d4594_1309812)), sub_4AD570)
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10306)))
	if noxflags.HasGame(1056) {
		nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v4)), 0)
	}
	nox_xxx_wndRetNULL_46A8A0()
	sub_4AD840()
	if false {
		sub_4AD4B0()
		v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10310)))
		nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v5))), *(*int32)(unsafe.Pointer(&dword_5d4594_1309812)))
		nox_xxx_wndSetProc_46B2C0((*gui.Window)(unsafe.Pointer(v5)), nox_xxx_windowServerOptionsGeneralProc_4AD5D0)
		v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10317)))
		v7 = (**byte)(memmap.PtrOff(0x587000, 173540))
		for {
			v8 = nox_strman_loadString_40F1D0(*v7, nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\general.c"), 308)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v6)), 16397, uintptr(unsafe.Pointer(v8)), math.MaxUint32)
			v7 = (**byte)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof((*byte)(nil))*1))
			if int32(uintptr(unsafe.Pointer(v7))) >= int32(uintptr(memmap.PtrOff(0x587000, 173556))) {
				break
			}
		}
	} else {
		v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10319)))
		nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v9)), 1)
	}
	if nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
		v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10304)))
		nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v10)), 0)
	}
	return int32(dword_5d4594_1309812)
}
func sub_4AD4B0() int32 {
	var (
		v0     *uint32
		v1     *uint32
		v2     int32
		v3     int32
		v4     **byte
		v5     *uint16
		result int32
		v7     int32
		v8     int32
		v9     int32
	)
	v0 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10317)))
	v1 = v0
	v2 = nox_xxx_guiFontHeightMB_43F320(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*59))))) + 1
	v3 = 0
	v4 = (**byte)(memmap.PtrOff(0x587000, 173540))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*7)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*5)) + uint32(v2*4) + 2
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*3)) = uint32(v2*4 + 2)
	for {
		v5 = (*uint16)(unsafe.Pointer(nox_strman_loadString_40F1D0(*v4, nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\general.c"), 92)))
		nox_xxx_drawGetStringSize_43F840(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*59)))), (*wchar2_t)(unsafe.Pointer(v5)), &v9, nil, 0)
		if v9 > v3 {
			v3 = v9
		}
		v4 = (**byte)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*byte)(nil))*1))
		if int32(uintptr(unsafe.Pointer(v4))) >= int32(uintptr(memmap.PtrOff(0x587000, 173556))) {
			break
		}
	}
	result = int32(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10316).Size().X)
	v7 = v3 + 7
	if v7 <= result {
		v7 = result
	}
	v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*6)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*2)) = uint32(v7)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*4)) = uint32(v8 - v7)
	return result
}
func sub_4AD840() int32 {
	var (
		result int32
		v1     *uint32
		v2     *uint32
		v3     *uint32
		v4     *uint32
		v5     *uint32
		v6     *uint32
		v7     *wchar2_t
		v8     *uint32
		v9     int32
	)
	result = int32(dword_5d4594_1309812)
	if dword_5d4594_1309812 != 0 {
		if nox_server_doPlayersAutoRespawn_40A5F0() != 0 {
			v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10301)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*9)) |= 4
			if noxflags.HasGame(1024) {
				nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v1)), 0)
			}
		}
		if nox_server_sendMotd_108752 != 0 {
			v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10302)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*9)) |= 4
		}
		if sub_4D0D70() != 0 {
			v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10304)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*9)) |= 4
		}
		if sub_409F40(2) != 0 {
			v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10305)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*9)) |= 4
		}
		if sub_409F40(0x2000) != 0 {
			v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10306)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*9)) |= 4
		}
		if false {
			v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10316)))
			v7 = nox_strman_loadString_40F1D0(*(**byte)(memmap.PtrOff(0x587000, uintptr(nox_server_connectionType_3596)*4+173536)), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\general.c"), 391)
			nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v6)), 16385, uintptr(unsafe.Pointer(v7)), math.MaxUint32)
			v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1309812)))), 10312)))
			v9 = nox_xxx_rateGet_40A6C0()
			result = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v8)), 16394, uintptr(4-v9), 0))
		}
	}
	return result
}
