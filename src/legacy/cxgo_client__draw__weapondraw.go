package legacy

import "unsafe"

func nox_thing_weapon_draw(a1 *int32, dr *nox_drawable) int32 {
	sub_4B95D0(dr)
	return nox_thing_static_draw((*uint32)(unsafe.Pointer(a1)), dr)
}
func nox_thing_weapon_animate_draw(a1 *int32, dr *nox_drawable) int32 {
	sub_4B95D0(dr)
	return nox_thing_animate_draw((*uint32)(unsafe.Pointer(a1)), dr)
}
func nox_thing_spherical_shield_draw(a1 *int32, dr *nox_drawable) int32 {
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
		v4 = &nox_xxx_netSpriteByCodeStatic_45A720(v3).Field_0
	} else {
		v5 = nox_xxx_netClearHighBit_578B30(int16(v2))
		v4 = &nox_xxx_netSpriteByCodeDynamic_45A6F0(v5).Field_0
	}
	if v4 != nil {
		nox_xxx_updateSpritePosition_49AA90(dr, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*3))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*4))+3))
		result = nox_thing_animate_draw((*uint32)(unsafe.Pointer(a1)), dr)
	} else {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		result = 0
	}
	return result
}
