package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_thing_harpoon_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	return nox_thing_slave_draw(vp, dr)
}
func nox_thing_harpoon_rope_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := vp
	var (
		v2  int32
		v3  int32
		v4  uint16
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  *client.Drawable
		v11 *client.Drawable
		v12 int32
		v13 int32
		v14 int32
		a1a Point32
		a2a Point32
		v18 int32
		a2  = dr
	)
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 432))) == 0 {
		v2 = int32(a1.World.Min.X)
		v3 = *a1
		v4 = *(*uint16)(unsafe.Add(unsafe.Pointer(a2), 439))
		a1a.X = *a1 + int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a2), 437))) - v2
		v5 = int32(a1.World.Min.Y)
		v6 = int32(a1.Screen.Min.Y)
		a1a.Y = int32(v4) - v5 + v6 - 20
		v7 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a2), 441))) - v2
		v8 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a2), 443))) - v5
		a2a.X = v3 + v7
		a2a.Y = v8 + v6 - 20
		*memmap.PtrUint32(0x5D4594, 1312492) = nox_color_rgb_4344A0(144, 104, 64)
		*memmap.PtrUint32(0x5D4594, 1312496) = nox_color_rgb_4344A0(24, 16, 0)
		sub_4B63B0(&a1a, &a2a)
		return 1
	}
	if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 437))) != 0 {
		v9 = nox_xxx_netSpriteByCodeStatic_45A720(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 437)))
	} else {
		v9 = nox_xxx_netSpriteByCodeDynamic_45A6F0(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 437)))
	}
	v10 := v9
	if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 441))) != 0 {
		v11 = nox_xxx_netSpriteByCodeStatic_45A720(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 441)))
	} else {
		v11 = nox_xxx_netSpriteByCodeDynamic_45A6F0(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 441)))
	}
	if v10 != nil && v11 != nil {
		v12 = int32(a1.World.Min.X)
		v13 = *a1
		v14 = int32(a1.Screen.Min.Y)
		v18 = int32(a1.World.Min.Y)
		a1a.X = int32(uint32(v13) + v10.PosVec.X - uint32(v12))
		a1a.Y = int32(uint32(v14) + v10.PosVec.Y - uint32(v18))
		a2a.X = int32(uint32(v13) + v11.PosVec.X - uint32(v12))
		a2a.Y = int32(uint32(v14) + v11.PosVec.Y - uint32(v11.ZVal2) - uint32(v11.ZVal) - uint32(v18))
		a1a.X += int32(*memmap.PtrUint32(0x587000, uintptr(int32(v10.AnimDir)*8)+175864))
		a1a.Y += int32(*memmap.PtrUint32(0x587000, uintptr(int32(v10.AnimDir)*8)+175868))
		a2a.Y -= 8
		*memmap.PtrUint32(0x5D4594, 1312492) = nox_color_rgb_4344A0(144, 104, 64)
		*memmap.PtrUint32(0x5D4594, 1312496) = nox_color_rgb_4344A0(24, 16, 0)
		sub_4B63B0(&a1a, &a2a)
		return 1
	}
	return 1
}
