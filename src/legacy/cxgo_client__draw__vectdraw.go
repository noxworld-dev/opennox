package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func sub_4BC5D0(dr *client.Drawable, a2 unsafe.Pointer) int32 {
	var (
		a1     = dr
		result int32
		v3     int32
		v4     int32
	)
	switch *(*uint32)(unsafe.Add(a2, 44)) {
	case 0:
		result = int32((gameFrame() - a1.Field_79) / uint32(int32(*(*int16)(unsafe.Add(a2, 42)))+1))
		v4 = int32(*(*int16)(unsafe.Add(a2, 40)))
		if result >= v4 {
			result = v4 - 1
		}
	case 1:
		result = int32((gameFrame() - a1.Field_79) / uint32(int32(*(*int16)(unsafe.Add(a2, 42)))+1))
		if result >= int32(*(*int16)(unsafe.Add(a2, 40))) {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
			result = -1
		}
	case 2:
		result = int32((gameFrame() + a1.Field_32) / uint32(int32(*(*int16)(unsafe.Add(a2, 42)))+1))
		v3 = int32(*(*int16)(unsafe.Add(a2, 40)))
		if result >= v3 {
			result %= v3
		}
	case 4:
		result = nox_common_randomIntMinMax_415FF0(0, int32(*(*int16)(unsafe.Add(a2, 40)))-1, internCStr("C:\\NoxPost\\src\\Client\\Draw\\vectdraw.c"), 19)
	case 5:
		result = int32(a1.Field_77)
	default:
		result = 0
	}
	return result
}
func nox_thing_vector_animate_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*int32)(vp.C())
	return sub_4BC6B0(a1, dr, int32(*(*uint32)(unsafe.Pointer(&dr.Field_76))))
}
func nox_things_vector_animate_draw_parse(obj *client.ObjectType, f *binfile.MemFile, attr_value *byte) bool {
	var (
		v2     *uint32
		v3     *uint32
		result int32
	)
	v2 = (*uint32)(alloc.Calloc1(1, 0x30))
	v3 = v2
	*v2 = 48
	result = nox_xxx_spriteLoadVectoAnimatedImpl_44BFA0(int32(uintptr(unsafe.Pointer(v2))), f)
	if result == 0 {
		return result != 0
	}
	obj.DrawFunc.Set(nox_thing_vector_animate_draw)
	obj.Field_5c = unsafe.Pointer(v3)
	result = 1
	return result != 0
}
