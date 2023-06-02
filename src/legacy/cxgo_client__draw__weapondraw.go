package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func nox_thing_weapon_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	sub_4B95D0(dr)
	return nox_thing_static_draw(vp, dr)
}
func nox_thing_weapon_animate_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	sub_4B95D0(dr)
	return nox_thing_animate_draw(vp, dr)
}
func nox_thing_spherical_shield_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	var (
		v2     int32
		v3     int32
		v4     *uint32
		v5     int32
		result int32
		a2     *uint32 = (*uint32)(unsafe.Pointer(dr))
	)
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*108)))
	if nox_xxx_netTestHighBit_578B70(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*108))) != 0 {
		v3 = nox_xxx_netClearHighBit_578B30(int16(v2))
		v4 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(v3).C())
	} else {
		v5 = nox_xxx_netClearHighBit_578B30(int16(v2))
		v4 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(v5).C())
	}
	if v4 != nil {
		nox_xxx_updateSpritePosition_49AA90(dr, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*3))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*4))+3))
		result = int32(nox_thing_animate_draw(vp, dr))
	} else {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		result = 0
	}
	return int(result)
}
