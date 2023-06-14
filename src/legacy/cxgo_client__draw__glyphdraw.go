package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_thing_glyph_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	var (
		v3 int8
		v4 int32
		v5 int32
		v6 int32
		a2 *uint32 = (*uint32)(dr.C())
	)
	if !noxflags.HasGame(2) || *memmap.PtrUint32(0x852978, 8) == 0 {
		goto LABEL_10
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*30))&0x40000000 != 0 {
		*((*uint8)(unsafe.Pointer(&a2))) = math.MaxUint8
		goto LABEL_10
	}
	if nox_client_drawable_testBuff_4356C0((*client.Drawable)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x852978, 8)))), 21) {
		nox_xxx_draw_434600(1)
		nox_draw_setColorMultAndIntensity_433E40(*memmap.PtrInt32(0x8531A0, 2572))
		v3 = -1
		*((*uint8)(unsafe.Pointer(&a2))) = uint8(v3)
		goto LABEL_10
	}
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)) - *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 12)))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*4)) - *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 16)))
	v6 = v4*v4 + v5*v5
	if v6 >= 22500 {
		return 1
	}
	v3 = int8(-56 - v6*200/22500)
	*((*uint8)(unsafe.Pointer(&a2))) = uint8(v3)
LABEL_10:
	nox_client_drawEnableAlpha_434560(1)
	nox_client_drawSetAlpha_434580(uint8(uintptr(unsafe.Pointer(a2))))
	v7 := nox_thing_animate_draw(vp, dr)
	nox_client_drawEnableAlpha_434560(0)
	nox_xxx_draw_434600(0)
	return v7
}
