package legacy

import "unsafe"

func nox_thing_armor_draw(a1 *int32, dr *nox_drawable) int32 {
	sub_4B96F0(dr)
	return nox_thing_static_draw((*uint32)(unsafe.Pointer(a1)), dr)
}
func nox_thing_armor_animate_draw(a1 *int32, dr *nox_drawable) int32 {
	sub_4B96F0(dr)
	return nox_thing_animate_draw((*uint32)(unsafe.Pointer(a1)), dr)
}
