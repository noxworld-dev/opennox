package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_thing_static_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := (*uint32)(vp.C())
	if (dr.Flags28()&0x40000) == 0 || dr.Flags30()&0x1000000 != 0 {
		nox_xxx_drawObject_4C4770_draw((*int32)(unsafe.Pointer(a1)), dr, int32(*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(dr.Field_76)), 4))))))
	}
	return 1
}
func Nox_thing_static_random_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := (*uint32)(vp.C())
	nox_xxx_drawObject_4C4770_draw((*int32)(unsafe.Pointer(a1)), dr, int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(dr.Field_76)), 4)))) + dr.Field_77*4)))))
	return 1
}
func nox_things_static_draw_parse(obj *nox_thing, f *nox_memfile, attr_value *byte) bool {
	var (
		a3   *uint8 = (*uint8)(unsafe.Pointer(attr_value))
		v6   *byte
		v8   int32
		v11  uint8
		data *uint32 = (*uint32)(alloc.Calloc1(1, 8))
	)
	if data == nil {
		return false
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(data), 4*0)) = 8
	v6 = (*byte)(unsafe.Pointer(a3))
	v8 = int32(nox_memfile_read_u32(f))
	*a3 = *memmap.PtrUint8(0x5D4594, 830856)
	if v8 == -1 {
		*((*uint8)(unsafe.Pointer(&a3))) = nox_memfile_read_u8(f)
		v11 = nox_memfile_read_u8(f)
		nox_memfile_read(unsafe.Pointer(v6), 1, int32(v11), f)
		*(*byte)(unsafe.Add(unsafe.Pointer(v6), v11)) = 0
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(data), 4*1)) = uint32(uintptr(unsafe.Pointer(nox_xxx_readImgMB_42FAA0(v8, int8(uintptr(unsafe.Pointer(a3))), v6))))
	obj.DrawFunc.Set(nox_thing_static_draw)
	obj.Field_5c = unsafe.Pointer(data)
	return true
}
func nox_things_static_random_draw_parse(obj *nox_thing, f *nox_memfile, attr_value *byte) bool {
	obj.DrawFunc.Set(Nox_thing_static_random_draw)
	obj.Field_5c = nox_xxx_spriteLoadStaticRandomData_44C000(attr_value, f)
	return obj.Field_5c != nil
}
