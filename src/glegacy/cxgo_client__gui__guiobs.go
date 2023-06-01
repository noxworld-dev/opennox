package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func sub_48C9F0(a1 *int32) int32 {
	var (
		v1 *int32
		v2 *wchar2_t
		v4 int32
	)
	v1 = a1
	nox_client_wndGetPosition_46AA60((*nox_window)(unsafe.Pointer(a1)), (*uint32)(unsafe.Pointer(&v4)), (*uint32)(unsafe.Pointer(&a1)))
	v4 += *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*24))
	a1 = (*int32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(a1))), *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*25))))))
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
		v2 = nox_strman_loadString_40F1D0(internCStr("observermode"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guiobs.c"), 41)
		nox_xxx_wndWddSetTooltip_46B000((*nox_window_data)(unsafe.Pointer(uintptr(dword_5d4594_1193712+36))), v2)
		nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*15))))), v4, int32(uintptr(unsafe.Pointer(a1))))
	}
	return 1
}
func sub_48C980() int32 {
	*memmap.PtrUint32(0x5D4594, 1193716) = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("ObserverIcon")))))
	dword_5d4594_1193712 = uint32(uintptr(unsafe.Pointer(nox_window_new(nil, 136, nox_win_width-50, nox_win_height/2-100, 50, 50, funAddrP(nil)))))
	nox_xxx_wndSetIcon_46AE60(*(*int32)(unsafe.Pointer(&dword_5d4594_1193712)), *memmap.PtrInt32(0x5D4594, 1193716))
	nox_window_set_all_funcs((*nox_window)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&dword_5d4594_1193712)))), funAddrP(nil), funAddrP(sub_48C9F0), funAddrP(nil))
	return 1
}
