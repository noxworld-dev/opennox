package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_video_drawCursorSelectCircle_4773C0(a1p *nox_draw_viewport_t) {
	var (
		a1 *uint32 = (*uint32)(unsafe.Pointer(a1p))
		v1 int32
		v2 int32
		v3 *uint32
		v4 int32
		v5 int32
	)
	if dword_5d4594_1096640 != nil {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(dword_5d4594_1096640)), 112)))&6 != 0 && sub_495A80(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(dword_5d4594_1096640)), 128)))) == 0 {
			v4 = nox_common_randomIntMinMax_415FF0(0, 1, internCStr("C:\\NoxPost\\src\\Client\\Draw\\selectdw.c"), 440)
			if v4 == 0 {
				v3 = (*uint32)(unsafe.Pointer(uintptr(nox_color_violet_2598268)))
				goto LABEL_15
			}
			if v4 == 1 {
				v3 = *(**uint32)(memmap.PtrOff(0x85B3FC, 940))
				goto LABEL_15
			}
		} else {
			v1 = nox_common_randomIntMinMax_415FF0(0, 2, internCStr("C:\\NoxPost\\src\\Client\\Draw\\selectdw.c"), 423)
			if v1 == 0 {
				v3 = (*uint32)(unsafe.Pointer(uintptr(nox_color_white_2523948)))
				goto LABEL_15
			}
			v2 = v1 - 1
			if v2 == 0 {
				v3 = (*uint32)(unsafe.Pointer(uintptr(nox_color_blue_2650684)))
				goto LABEL_15
			}
			if v2 == 1 {
				v3 = (*uint32)(unsafe.Pointer(uintptr(nox_color_cyan_2649820)))
				goto LABEL_15
			}
		}
		v3 = a1
	LABEL_15:
		v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(dword_5d4594_1096640)), 112)))
		if (v5 & 0x200) == 0 {
			nox_video_drawCursorSelectCircle2_477470(a1, int32(uintptr(unsafe.Pointer(v3))), *(*int32)(unsafe.Pointer(&dword_5d4594_1096640)))
		}
	}
}
