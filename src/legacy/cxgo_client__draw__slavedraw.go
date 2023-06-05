package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func nox_thing_slave_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := (*uint32)(vp.C())
	nox_xxx_drawObject_4C4770_draw((*int32)(unsafe.Pointer(a1)), dr, int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(&dr.Field_76)))), 4)) + dr.Field_77*4)))))
	if ccall.FuncAddr(nox_thing_slave_draw) == ccall.FuncAddr(Nox_thing_static_random_draw) {
		return 0
	}
	return 1
}
func nox_things_slave_draw_parse(obj *nox_thing, f *nox_memfile, attr_value *byte) bool {
	obj.DrawFunc.Set(nox_thing_slave_draw)
	var v3 unsafe.Pointer = nox_xxx_spriteLoadStaticRandomData_44C000(attr_value, f)
	obj.Field_5c = v3
	obj.Field_60 = 0
	return v3 != nil
}
