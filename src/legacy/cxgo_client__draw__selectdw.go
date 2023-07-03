package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_video_drawCursorSelectCircle_4773C0(vp *noxrender.Viewport) {
	if dword_5d4594_1096640 == nil {
		return
	}
	var v3 uint32
	if int32(*(*uint8)(unsafe.Add(dword_5d4594_1096640.C(), 112)))&6 != 0 && sub_495A80(int32(dword_5d4594_1096640.Field_32)) == 0 {
		switch nox_common_randomIntMinMax_415FF0(0, 1, internCStr("C:\\NoxPost\\src\\Client\\Draw\\selectdw.c"), 440) {
		case 0:
			v3 = nox_color_violet_2598268
		case 1:
			v3 = *(*uint32)(memmap.PtrOff(0x85B3FC, 940))
		}
	} else {
		switch nox_common_randomIntMinMax_415FF0(0, 2, internCStr("C:\\NoxPost\\src\\Client\\Draw\\selectdw.c"), 423) {
		case 0:
			v3 = nox_color_white_2523948
		case 1:
			v3 = nox_color_blue_2650684
		case 2:
			v3 = nox_color_cyan_2649820
		}
	}
	v5 := dword_5d4594_1096640.Flags28Val
	if (v5 & 0x200) == 0 {
		nox_video_drawCursorSelectCircle2_477470(vp, int32(v3), dword_5d4594_1096640)
	}
}
