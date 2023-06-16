package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_4BE2C0(a1 int32) uintptr {
	var (
		v1 *wchar2_t
		v2 *uint32
	)
	*(*uint32)(unsafe.Add(sub_416640(), 74)) = uint32(a1)
	v1 = nox_strman_loadString_40F1D0(internCStr("AudCullDesc"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\advserv.c"), 71)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1316716)), v1, a1)
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1316972)), 2120)))
	return nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v2)), 16385, uintptr(memmap.PtrOff(0x5D4594, 1316716)), math.MaxUint32)
}
