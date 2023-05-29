package legacy

import "unsafe"

func nox_thing_trigger_draw(a1 *uint32, dr *nox_drawable) int32 {
	var (
		v2  int32 = int32(*a1 - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		v3  int32 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
		v4  int32 = dr.pos.x + v2 + nox_float2int(dr.shape.box_left_top)
		v12 int32 = dr.pos.y + v3 + nox_float2int(dr.shape.box_left_bottom)
		v7  int32 = dr.pos.x + v2 + nox_float2int(dr.shape.box_right_bottom_2)
		v8  int32 = dr.pos.y + v3 + nox_float2int(dr.shape.box_right_top_2)
		v9  int32 = dr.pos.x + v2 + nox_float2int(dr.shape.box_left_bottom_2)
		v10 int32 = dr.pos.y + v3 + nox_float2int(dr.shape.box_left_top_2)
		v11 int32 = dr.pos.x + v2 + nox_float2int(dr.shape.box_right_top)
		v5  int32 = dr.pos.y + v3 + nox_float2int(dr.shape.box_right_bottom)
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
