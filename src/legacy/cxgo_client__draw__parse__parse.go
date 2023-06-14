package legacy

import (
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_xxx_spriteLoadStaticRandomData_44C000(attr_value *byte, f *binfile.MemFile) unsafe.Pointer {
	var (
		v2     *uint32
		v4     *uint32
		result unsafe.Pointer
		v7     int32
		v8     *uint8
		v10    int32
		v12    int8
		v13    *byte
		v14    uint8
		v15    uint8
		v16    int32
	)
	v2 = (*uint32)(alloc.Calloc1(1, 0xC))
	v4 = v2
	*v2 = 12
	v15 = nox_memfile_read_u8(f)
	*((*uint8)(unsafe.Add(unsafe.Pointer(v4), 8))) = v15
	result = alloc.Calloc1(int(v15), 4)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = uint32(uintptr(result))
	if result != nil {
		v7 = 0
		v16 = 0
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v4), 8)))) != 0 {
			v8 = attr_value
			for {
				v10 = nox_memfile_read_i32(f)
				*v8 = *memmap.PtrUint8(0x5D4594, 830852)
				if v10 == -1 {
					v12 = nox_memfile_read_i8(f)
					*((*uint8)(unsafe.Pointer(&v13))) = uint8(v12)
					v14 = uint8(nox_memfile_read_i8(f))
					nox_memfile_read(unsafe.Pointer(v8), 1, int32(v14), f)
					v10 = -1
					*(*uint8)(unsafe.Add(unsafe.Pointer(v8), v14)) = 0
					v7 = v16
				}
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) + uint32(func() int32 {
					p := &v7
					x := *p
					*p++
					return x
				}()*4)))) = uint32(uintptr(unsafe.Pointer(nox_xxx_readImgMB_42FAA0(v10, int8(uintptr(unsafe.Pointer(v13))), v8))))
				v16 = v7
				if v7 >= int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v4), 8)))) {
					break
				}
			}
		}
		result = unsafe.Pointer(v4)
	}
	return result
}
func nox_xxx_spriteLoadVectoAnimatedImpl_44BFA0(a1 int32, f *binfile.MemFile) int32 {
	if nox_xxx_loadVectorAnimated_44B8B0(a1, f) == 0 {
		return 0
	}
	return nox_xxx_loadVectorAnimated_44BC50(a1, f)
}
func nox_xxx_loadVectorAnimated_44B8B0(a1 int32, f *binfile.MemFile) int32 {
	*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 40)) = uint16(nox_memfile_read_u8(f))
	*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 42)) = uint16(nox_memfile_read_u8(f))
	var anim_kind_length uint8 = nox_memfile_read_u8(f)
	var animation_kind [256]byte
	nox_memfile_read(unsafe.Pointer(&animation_kind[0]), 1, int32(anim_kind_length), f)
	animation_kind[anim_kind_length] = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 44)) = uint32(get_animation_kind_id_44B4C0(&animation_kind[0]))
	return 1
}
func nox_xxx_loadVectorAnimated_44BC50(a1 int32, f *binfile.MemFile) int32 {
	var (
		v2  int32
		v3  int32
		v4  unsafe.Pointer
		v5  int32
		v7  int32
		v9  int8
		v11 int32
		v13 int32
		v14 int32
		v15 *byte
		v16 [128]byte
	)
	v2 = 0
	v14 = 0
	for {
		if v2 >= 16 {
			v13 = v2 + 4
		} else {
			v13 = v2
		}
		v3 = a1
		v4 = alloc.Calloc1(int(*(*int16)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 40))), 4)
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v13+a1)), 4)) = uint32(uintptr(v4))
		if v4 == nil {
			break
		}
		v5 = 0
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 40))) > 0 {
			for {
				v7 = nox_memfile_read_i32(f)
				v16[0] = *memmap.PtrUint8(0x5D4594, 830844)
				if v7 == -1 {
					v9 = nox_memfile_read_i8(f)
					*((*uint8)(unsafe.Pointer(&v15))) = uint8(v9)
					v11 = int32(nox_memfile_read_u8(f))
					nox_memfile_read(unsafe.Pointer(&v16[0]), 1, v11, f)
					v16[v11] = 0
					v3 = a1
				}
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v13+v3)), 4)) + uint32(func() int32 {
					p := &v5
					*p++
					return *p
				}()*4) - 4))) = uint32(uintptr(unsafe.Pointer(nox_xxx_readImgMB_42FAA0(v7, int8(uintptr(unsafe.Pointer(v15))), &v16[0]))))
				if v5 >= int32(*(*int16)(unsafe.Add(unsafe.Pointer(uintptr(v3)), 40))) {
					break
				}
			}
			v2 = v14
		}
		v2 += 4
		v14 = v2
		if v2 >= 32 {
			return 1
		}
	}
	return 0
}
func get_animation_kind_id_44B4C0(a1 *byte) int32 {
	if libc.StrCmp(a1, internCStr("OneShot")) == 0 {
		return 0
	}
	if libc.StrCmp(a1, internCStr("OneShotRemove")) == 0 {
		return 1
	}
	if libc.StrCmp(a1, internCStr("Loop")) == 0 {
		return 2
	}
	if libc.StrCmp(a1, internCStr("LoopAndFade")) == 0 {
		return 3
	}
	if libc.StrCmp(a1, internCStr("Random")) == 0 {
		return 4
	}
	if libc.StrCmp(a1, internCStr("Slave")) != 0 {
		return 0
	}
	return 5
}
