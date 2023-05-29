package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"unsafe"
)

func nox_thing_slave_draw(a1 *int32, dr *nox_drawable) int32 {
	nox_xxx_drawObject_4C4770_draw(a1, dr, int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(&dr.field_76)) + 4))) + dr.field_77*4)))))
	if funAddr(nox_thing_slave_draw) == funAddr(nox_thing_static_random_draw) {
		return 0
	}
	return 1
}
func nox_things_slave_draw_parse(obj *nox_thing, f *nox_memfile, attr_value *byte) bool {
	obj.draw_func = func(arg1 *uint32, arg2 *nox_drawable) int32 {
		return nox_thing_slave_draw((*int32)(unsafe.Pointer(arg1)), arg2)
	}
	var v3 unsafe.Pointer = nox_xxx_spriteLoadStaticRandomData_44C000(attr_value, f)
	obj.field_5c = v3
	obj.field_60 = 0
	return v3 != nil
}
