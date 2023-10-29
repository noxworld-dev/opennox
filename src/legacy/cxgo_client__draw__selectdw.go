package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
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
func nox_video_drawCursorSelectCircle2_477470(a1 *noxrender.Viewport, a2 int32, a3 *client.Drawable) {
	var (
		v3 int32
		v4 int32
		v7 float32
	)
	if a3 != nil {
		if a3.Shape.Kind == 2 {
			v4 = int32(a3.Shape.Circle.R)
			v3 = v4 + 6
		} else if a3.Shape.Kind != 3 {
			v3 = 6
		} else {
			v7 = a3.Shape.Box.H + a3.Shape.Box.W
			v4 = int32(v7) / 2
			v3 = v4 + 6
		}
		v5 := int32(a1.Screen.Min.X + a3.PosVec.X - a1.World.Min.X)
		v6 := int32(a3.PosVec.Y + int(a1.Screen.Min.Y) - int(a1.World.Min.Y))
		nox_client_drawSetColor_434460(a2)
		nox_client_drawEnableAlpha_434560(1)
		nox_client_drawSetAlpha_434580(0x80)
		nox_video_drawCircle_4B0B90(v5, v6, v3-1)
		nox_video_drawCircle_4B0B90(v5, v6, v3+1)
		nox_client_drawEnableAlpha_434560(0)
		nox_video_drawCircle_4B0B90(v5, v6, v3)
	}
}
