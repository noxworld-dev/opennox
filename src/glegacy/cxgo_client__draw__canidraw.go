package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_thing_cond_animate_draw(a1 *uint32, dr *nox_drawable) int32 {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v10 int32
	)
	v2 = int32(uintptr(dr.Field_76))
	if dr.Flags30()&0x1000000 != 0 {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 4))))
		v4 = int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 24))))
		v5 = int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 29))))
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 36))))
	} else {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 8))))
		v4 = int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 25))))
		v5 = int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 30))))
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 40))))
	}
	v7 = v6 - 2
	if v7 != 0 {
		v8 = v7 - 2
		if v8 != 0 {
			if v8 != 1 {
				return 0
			}
			v10 = int32(dr.Field_77)
		} else {
			v10 = nox_common_randomIntMinMax_415FF0(0, v4, internCStr("C:\\NoxPost\\src\\client\\Draw\\CAniDraw.c"), 57)
		}
	} else {
		v10 = int32((gameFrame() + dr.Field_32) / uint32(v5+1))
		if v10 >= v4 {
			v10 %= v4
		}
	}
	nox_xxx_drawObject_4C4770_draw((*int32)(unsafe.Pointer(a1)), dr, int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + v10*4)))))
	return 1
}
func nox_things_cond_animate_draw_parse(obj *nox_thing, f *nox_memfile, attr_value *byte) bool {
	var (
		v3  *uint32
		v6  *uint8
		v7  *uint8
		v9  uint8
		v11 uint8
		v13 *uint32
		v14 unsafe.Pointer
		v16 int32
		v18 int8
		v20 *uint32
		v21 *byte
		v22 int32
		v23 int32
		v24 *uint32
		v25 uint8
		v26 uint8
		v27 uint8
		v28 int32
	)
	v3 = (*uint32)(alloc.Calloc(1, 0x38))
	*v3 = 16
	v24 = v3
	v25 = nox_memfile_read_u8(f)
	v23 = int32(v25)
	if int32(v25) <= 0 {
		obj.Field_5c = unsafe.Pointer(v3)
		obj.DrawFunc = nox_thing_cond_animate_draw
		obj.Field_60 = 0
		return true
	}
	v6 = (*uint8)(unsafe.Pointer(attr_value))
	v20 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
	v7 = (*uint8)(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*6))))
	v22 = int32(4294967272 - uint32(uintptr(unsafe.Pointer(v3))))
	for {
		v9 = nox_memfile_read_u8(f)
		*v7 = v9
		v11 = nox_memfile_read_u8(f)
		*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 5)) = v11
		v26 = nox_memfile_read_u8(f)
		nox_memfile_read(unsafe.Pointer(v6), 1, int32(v26), f)
		*(*uint8)(unsafe.Add(unsafe.Pointer(v6), v26)) = 0
		v13 = v20
		*(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*8)) = uint32(get_animation_kind_id_44B4C0((*byte)(unsafe.Pointer(v6))))
		v14 = alloc.Calloc(int(*v7), 4)
		*v20 = uint32(uintptr(v14))
		if v14 == nil {
			break
		}
		v28 = 0
		if int32(*v7) != 0 {
			for {
				v16 = int32(nox_memfile_read_u32(f))
				*v6 = *memmap.PtrUint8(0x5D4594, 830836)
				if v16 == -1 {
					v18 = int8(nox_memfile_read_u8(f))
					*((*uint8)(unsafe.Pointer(&v21))) = uint8(v18)
					v27 = nox_memfile_read_u8(f)
					nox_memfile_read(unsafe.Pointer(v6), 1, int32(v27), f)
					v16 = -1
					*(*uint8)(unsafe.Add(unsafe.Pointer(v6), v27)) = 0
					v13 = v20
				}
				*(*uint32)(unsafe.Pointer(uintptr(*v13 + uint32(func() int32 {
					p := &v28
					x := *p
					*p++
					return x
				}()*4)))) = uint32(uintptr(unsafe.Pointer(nox_xxx_readImgMB_42FAA0(v16, int8(uintptr(unsafe.Pointer(v21))), (*byte)(unsafe.Pointer(v6))))))
				if v28 >= int32(*v7) {
					break
				}
			}
		}
		v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 1))
		v20 = (*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*1))
		if int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v7), v22))))) >= v23 {
			v3 = v24
			obj.Field_5c = unsafe.Pointer(v3)
			obj.DrawFunc = nox_thing_cond_animate_draw
			obj.Field_60 = 0
			return true
		}
	}
	return false
}
