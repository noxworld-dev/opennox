package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_456140(a1 uint8) {
	var (
		v2 int32
		v3 *wchar2_t
		v4 *wchar2_t
		v5 *wchar2_t
		v6 *wchar2_t
	)
	*memmap.PtrUint8(0x5D4594, 1045644) = a1
	v2 = int32(dword_5d4594_1045636 + 36)
	switch a1 {
	case 0:
		*(*uint32)(unsafe.Add(v2, 24)) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("BallAtHome")))))
		v3 = nox_strman_loadString_40F1D0(internCStr("BallHomeTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guifb.c"), 165)
		nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(v2), v3)
	case 1:
		*(*uint32)(unsafe.Add(v2, 24)) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("BallAway")))))
		v4 = nox_strman_loadString_40F1D0(internCStr("BallAwayTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guifb.c"), 170)
		nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(v2), v4)
	case 2:
		*(*uint32)(unsafe.Add(v2, 24)) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("BallRed")))))
		v5 = nox_strman_loadString_40F1D0(internCStr("BallRedTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guifb.c"), 175)
		nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(v2), v5)
	case 4:
		*(*uint32)(unsafe.Add(v2, 24)) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("BallBlue")))))
		v6 = nox_strman_loadString_40F1D0(internCStr("BallBlueTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guifb.c"), 180)
		nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(v2), v6)
	}
}
