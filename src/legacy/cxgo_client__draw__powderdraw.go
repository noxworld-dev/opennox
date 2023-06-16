package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_thing_black_powder_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*uint32)(vp.C())
	var (
		v2 int32
		v3 int32
		a2 int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	v2 = int32(*a1 + *(*uint32)(unsafe.Add(a2, 12)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	v3 = int32(*(*uint32)(unsafe.Add(a2, 16)) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 956))
	nox_client_drawRectFilledOpaque_49CE30(v2-1, v3-1, 3, 3)
	nox_client_drawRectFilledOpaque_49CE30(v2-5, v3, 1, 1)
	nox_client_drawRectFilledOpaque_49CE30(v2, v3+7, 1, 1)
	nox_client_drawRectFilledOpaque_49CE30(v2+8, v3-2, 1, 1)
	return 1
}
