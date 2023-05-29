package legacy

import (
	"unsafe"
)

func sub_4BE2C0(a1 int32) int32 {
	var (
		v1 *wchar2_t
		v2 *uint32
	)
	*(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(sub_416640())) + 74))) = uint32(a1)
	v1 = nox_strman_loadString_40F1D0(internCStr("AudCullDesc"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\advserv.c"), 71)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1316716)), v1, a1)
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1316972)))), 2120)))
	return nox_window_call_field_94_fnc((*nox_window)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), 16385, int32(uintptr(memmap.PtrOff(0x5D4594, 1316716))), -1)
}
