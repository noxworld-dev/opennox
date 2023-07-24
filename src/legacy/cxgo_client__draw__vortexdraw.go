package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_thing_vortex_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := vp
	var (
		v2     int32
		v3     int32
		v4     int32
		v5     bool
		v6     int8
		v7     int32
		v8     int32
		v9     int32
		result int32
	)
	var v11 float32
	var xLeft Point32
	var a2a Point32
	var a3 Point32
	var a2 int32 = int32(uintptr(unsafe.Pointer(dr)))
	if *memmap.PtrUint32(0x5D4594, 1313820) == 0 {
		dword_5d4594_1313816 = nox_color_rgb_4344A0(170, 170, 170)
		*memmap.PtrUint32(0x5D4594, 1313820) = 1
	}
	v2 = int32(*(*uint8)(unsafe.Add(a2, 448))) * 8
	v3 = int32(*(*uint8)(unsafe.Add(a2, 450)))
	a2a.X = int32(*(*uint32)(unsafe.Add(a2, 440)) + uint32(v3**memmap.PtrInt32(0x587000, uintptr(v2)+192088)/16))
	a2a.Y = int32(*(*uint32)(unsafe.Add(a2, 444)) + uint32(v3**memmap.PtrInt32(0x587000, uintptr(v2)+192092)/16))
	sub_4739E0((*uint32)(unsafe.Pointer(a1)), &a2a, &xLeft)
	v4 = xLeft.Y - int32(*(*int16)(unsafe.Add(a2, 104)))
	v5 = xLeft.X <= *a1
	xLeft.Y -= int32(*(*int16)(unsafe.Add(a2, 104)))
	if v5 || xLeft.X >= a1.Screen.Max.X || v4 <= a1.Screen.Min.Y || v4 >= a1.Screen.Max.Y {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		return 0
	}
	if a2a.Y >= *(*int32)(unsafe.Add(a2, 444)) {
		sub_4B6720(&xLeft, int32(*(*uint32)(unsafe.Add(a2, 432))), 3, 5)
		nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(a2, 436))))
		nox_xxx_drawPointMB_499B70(xLeft.X, xLeft.Y, 3)
	} else {
		sub_4B6720(&xLeft, int32(dword_5d4594_1313816), 2, 4)
		nox_client_drawSetColor_434460(int32(dword_5d4594_1313816))
		nox_xxx_drawPointMB_499B70(xLeft.X, xLeft.Y, 2)
	}
	nox_client_drawAddPoint_49F500(xLeft.X, xLeft.Y)
	v6 = int8(*(*uint8)(unsafe.Add(a2, 449)))
	v7 = int32(*(*uint8)(unsafe.Add(a2, 448))) - int32(v6)*2
	if int32(v6) > 0 {
		if v7 < 0 {
			v7 += 0x100
		} else {
			v7 += 0
		}
	} else if v7 >= 256 {
		v7 -= 256
	}
	v8 = int32(*(*uint8)(unsafe.Add(a2, 450)))
	a2a.X = int32(*(*uint32)(unsafe.Add(a2, 440)) + uint32(v8)**memmap.PtrUint32(0x587000, uintptr(v7*8)+192088)/16)
	a2a.Y = int32(*(*uint32)(unsafe.Add(a2, 444)) + uint32(v8)**memmap.PtrUint32(0x587000, uintptr(v7*8)+192092)/16)
	sub_4739E0((*uint32)(unsafe.Pointer(a1)), &a2a, &xLeft)
	xLeft.Y -= int32(*(*int16)(unsafe.Add(a2, 104)))
	nox_client_drawAddPoint_49F500(xLeft.X, xLeft.Y)
	if a2a.Y >= *(*int32)(unsafe.Add(a2, 444)) {
		nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(a2, 436))))
	} else {
		nox_client_drawSetColor_434460(int32(dword_5d4594_1313816))
	}
	nox_client_drawLineFromPoints_49E4B0()
	*(*uint8)(unsafe.Add(a2, 448)) += *(*uint8)(unsafe.Add(a2, 449))
	*(*uint16)(unsafe.Add(a2, 104)) += uint16(*(*uint8)(unsafe.Add(a2, 451)))
	sub_4739E0((*uint32)(unsafe.Pointer(a1)), (*Point32)(unsafe.Add(a2, 12)), &a3)
	v11 = float32(float64(*(*int16)(unsafe.Add(a2, 104))) * 0.0024999999 * 50.0)
	v9 = int32(v11)
	if 50-v9 <= 0 {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		return 0
	} else {
		*(*uint8)(unsafe.Add(a2, 450)) = uint8(int8(50 - v9))
		return 1
	}
}
