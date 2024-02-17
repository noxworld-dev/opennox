package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_4BE2C0(a1 int32) uintptr {
	*(*uint32)(unsafe.Add(unsafe.Pointer(sub_416640()), 74)) = uint32(a1)
	v1 := nox_strman_loadString_40F1D0(internCStr("AudCullDesc"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\advserv.c"), 71)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1316716)), v1, a1)
	v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2120)
	return nox_window_call_field_94_fnc(v2, 16385, uintptr(memmap.PtrOff(0x5D4594, 1316716)), math.MaxUint32)
}
