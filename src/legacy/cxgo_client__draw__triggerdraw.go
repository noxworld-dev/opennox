package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func nox_thing_trigger_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := (*uint32)(vp.C())
	var (
		v2  int32 = int32(*a1 - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		v3  int32 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
		v4  int32 = int32(dr.PosVec.X) + v2 + int32(dr.Shape.Box.LeftTop)
		v12 int32 = int32(dr.PosVec.Y) + v3 + int32(dr.Shape.Box.LeftBottom)
		v7  int32 = int32(dr.PosVec.X) + v2 + int32(dr.Shape.Box.RightBottom2)
		v8  int32 = int32(dr.PosVec.Y) + v3 + int32(dr.Shape.Box.RightTop2)
		v9  int32 = int32(dr.PosVec.X) + v2 + int32(dr.Shape.Box.LeftBottom2)
		v10 int32 = int32(dr.PosVec.Y) + v3 + int32(dr.Shape.Box.LeftTop2)
		v11 int32 = int32(dr.PosVec.X) + v2 + int32(dr.Shape.Box.RightTop)
		v5  int32 = int32(dr.PosVec.Y) + v3 + int32(dr.Shape.Box.RightBottom)
	)
	nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
	nox_client_drawEnableAlpha_434560(1)
	nox_client_drawAddPoint_49F500(v4, v12)
	nox_client_drawAddPoint_49F500(v11, v5)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v7, v8)
	nox_client_drawAddPoint_49F500(v11, v5)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v4, v12)
	nox_client_drawAddPoint_49F500(v9, v10)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawAddPoint_49F500(v7, v8)
	nox_client_drawAddPoint_49F500(v9, v10)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawEnableAlpha_434560(0)
	return 1
}
