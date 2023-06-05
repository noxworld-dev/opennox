package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_thing_spider_spit_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := (*uint32)(vp.C())
	var (
		v2  *uint32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		a2  int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	v2 = (*uint32)(unsafe.Pointer(uintptr(a2)))
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	v4 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 104)))
	v16 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	v13 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4)))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)))
	v12 = v4
	v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*8)))
	v7 = int32(uint32(v16+v13) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) - uint32(v4))
	v14 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*9)))
	v8 = int32(*a1 + uint32(v6) - uint32(v3))
	v9 = int32(uint32(v5) + *a1 - uint32(v3))
	v10 = int32(uint32(v16+v14) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) - uint32(v12))
	if v5-v6 >= 0 {
		v15 = v5 - v6
	} else {
		v15 = v6 - v5
	}
	if v13-v14 >= 0 {
		v17 = v13 - v14
	} else {
		v17 = v14 - v13
	}
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 956))
	if v15 <= v17 {
		nox_client_drawAddPoint_49F500(v9+1, v7)
		nox_client_drawAddPoint_49F500(v8-1, v10)
		nox_client_drawLineFromPoints_49E4B0()
		nox_client_drawAddPoint_49F500(v9-1, v7)
		nox_client_drawAddPoint_49F500(v8-1, v10)
	} else {
		nox_client_drawAddPoint_49F500(v9, v7+1)
		nox_client_drawAddPoint_49F500(v8, v10+1)
		nox_client_drawLineFromPoints_49E4B0()
		nox_client_drawAddPoint_49F500(v9, v7+1)
		nox_client_drawAddPoint_49F500(v8, v10-1)
	}
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawRectFilledOpaque_49CE30(v9-1, v7-1, 4, 4)
	nox_client_drawSetColor_434460(int32(nox_color_white_2523948))
	nox_client_drawAddPoint_49F500(v9, v7)
	nox_client_drawAddPoint_49F500(v8, v10)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawRectFilledOpaque_49CE30(v9, v7, 2, 2)
	return 1
}
