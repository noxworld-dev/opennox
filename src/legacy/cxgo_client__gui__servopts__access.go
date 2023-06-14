package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_454640() int32 {
	var (
		v0     *uint32
		v1     *uint32
		v2     int32
		v3     *uint16
		v4     *uint16
		v5     *uint16
		v6     int32
		v7     int32
		result int32
		v9     int32
		v10    int32
	)
	v0 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045516)))), 10123)))
	v1 = v0
	v2 = nox_xxx_guiFontHeightMB_43F320(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*59))))) + 1
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*7)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*5)) + uint32(v2*4) + 2
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*3)) = uint32(v2*4 + 2)
	v3 = nox_strman_loadString_40F1D0(internCStr("WARRIOR"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c"), 88)
	nox_xxx_drawGetStringSize_43F840(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*59)))), v3, &v9, nil, 0)
	v4 = nox_strman_loadString_40F1D0(internCStr("WIZARD"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c"), 89)
	nox_xxx_drawGetStringSize_43F840(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*59)))), v4, &v10, nil, 0)
	if v10 > v9 {
		v9 = v10
	}
	v5 = nox_strman_loadString_40F1D0(internCStr("CONJURER"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c"), 94)
	nox_xxx_drawGetStringSize_43F840(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*59)))), v5, &v10, nil, 0)
	v6 = v9
	if v10 > v9 {
		v6 = v10
	}
	v7 = v6 + 7
	v9 = v7
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*2)) = uint32(v7)
	result = int32(uint32(v9) + *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*4)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*6)) = uint32(result)
	return result
}
func sub_454740() *int32 {
	var (
		v0  *byte
		v1  *uint32
		v2  *wchar2_t
		v3  *uint32
		v4  *uint32
		v5  *uint32
		v6  *wchar2_t
		v7  *wchar2_t
		v8  *wchar2_t
		v9  int8
		v10 int32
		v11 int32
		i   *byte
	)
	WideCharStr, free := alloc.Make([]wchar2_t{}, 18)
	defer free()
	v0 = (*byte)(sub_416640())
	v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045516)))), 10136)))
	v2 = nox_xxx_sysopGetPass_40A630()
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v1)), 16414, uintptr(unsafe.Pointer(v2)), 0)
	if int32(*(*int16)(unsafe.Add(unsafe.Pointer(v0), 105))) != -1 {
		nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045584))))), 1)
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, 1045568))), 36)) |= 4
		nox_itow(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v0), 105))), &WideCharStr[0], 10)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045584))))), 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), 0)
	}
	if int32(*(*int16)(unsafe.Add(unsafe.Pointer(v0), 107))) != -1 {
		nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045588))))), 1)
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, 1045572))), 36)) |= 4
		nox_itow(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v0), 107))), &WideCharStr[0], 10)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045588))))), 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), 0)
	}
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045516)))), 10124)))
	if int32(*(*byte)(unsafe.Add(unsafe.Pointer(v0), 102))) < 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*9)) |= 4
	}
	if *(*byte)(unsafe.Add(unsafe.Pointer(v0), 100))&0x20 != 0 {
		nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045556))))), 1)
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, 1045524))), 36)) |= 4
	}
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045556))))), 16414, uintptr(unsafe.Add(unsafe.Pointer(v0), 78)), 0)
	if sub_4D6F30() != 0 {
		nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045520))))), 0)
	} else {
		nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045520))))), 1)
		if *(*byte)(unsafe.Add(unsafe.Pointer(v0), 100))&0x10 != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(dword_5d4594_1045520)), 36)) = 4
		} else {
			v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045516)))), 10206)))
			nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v4)), 0)
		}
	}
	v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1045516)))), 10207)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*9)) |= 4
	dword_5d4594_1045596 = dword_5d4594_1045528
	v6 = nox_strman_loadString_40F1D0(internCStr("WARRIOR"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c"), 242)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045552))))), 16397, uintptr(unsafe.Pointer(v6)), math.MaxUint32)
	v7 = nox_strman_loadString_40F1D0(internCStr("WIZARD"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c"), 243)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045552))))), 16397, uintptr(unsafe.Pointer(v7)), math.MaxUint32)
	v8 = nox_strman_loadString_40F1D0(internCStr("CONJURER"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c"), 244)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045552))))), 16397, uintptr(unsafe.Pointer(v8)), math.MaxUint32)
	if *(*byte)(unsafe.Add(unsafe.Pointer(v0), 100))&0x10 != 0 {
		nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045532))))), 0)
		nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Pointer(&dword_5d4594_1045528))))), 1)
	}
	v9 = int8(*(*byte)(unsafe.Add(unsafe.Pointer(v0), 100)))
	if int32(v9) != 0 {
		v10 = 0
		v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(dword_5d4594_1045552)), 32)))
		if int32(v9)&1 != 0 {
			**(**uint32)(unsafe.Add(unsafe.Pointer(uintptr(v11)), 48)) = 0
			v10 = 1
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v11)), 48)))), 4)) = math.MaxUint32
		}
		if *(*byte)(unsafe.Add(unsafe.Pointer(v0), 100))&2 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v11)), 48)) + uint32(func() int32 {
				p := &v10
				*p++
				return *p
			}()*4) - 4))) = 1
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v11)), 48)) + uint32(v10*4)))) = math.MaxUint32
		}
		if *(*byte)(unsafe.Add(unsafe.Pointer(v0), 100))&4 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v11)), 48)) + uint32(v10*4)))) = 2
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v11)), 48))+uint32(v10*4))), 4)) = math.MaxUint32
		}
	}
	nox_itow(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v0), 104))), &WideCharStr[0], 10)
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1045592)))), 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), 0)
	for i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); i != nil; i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(i))))) {
		if *(*byte)(unsafe.Add(unsafe.Pointer(i), 2064)) != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
			sub_455920((*wchar2_t)(unsafe.Add(unsafe.Pointer(i), 4704)))
		}
	}
	return sub_455800()
}
