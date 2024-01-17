package legacy

import (
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
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
	if result == nil {
		return result
	}
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
	return result
}
func nox_xxx_spriteLoadVectoAnimatedImpl_44BFA0(a1 *client.AnimationVector, f *binfile.MemFile) int32 {
	if nox_xxx_loadVectorAnimated_44B8B0(a1, f) == 0 {
		return 0
	}
	return nox_xxx_loadVectorAnimated_44BC50(a1, f)
}
func nox_xxx_loadVectorAnimated_44B8B0(a1 *client.AnimationVector, f *binfile.MemFile) int32 {
	a1.Size40 = uint16(nox_memfile_read_u8(f))
	a1.Val42 = uint16(nox_memfile_read_u8(f))
	n := nox_memfile_read_u8(f)
	var buf [256]byte
	nox_memfile_read(unsafe.Pointer(&buf[0]), 1, int32(n), f)
	buf[n] = 0
	a1.Kind44 = uint32(get_animation_kind_id_44B4C0(&buf[0]))
	return 1
}
func nox_xxx_loadVectorAnimated_44BC50(ani *client.AnimationVector, f *binfile.MemFile) int32 {
	var buf [128]byte
	for i := 0; i < 8; i++ {
		k := i
		if i >= 4 {
			k = i + 1
		}
		arr, _ := alloc.Make([]noxrender.ImageHandle{}, int(ani.Size40))
		ani.Field4[k] = &arr[0]
		if arr == nil {
			return 0
		}
		if int32(ani.Size40) > 0 {
			for j := 0; j < int(ani.Size40); j++ {
				id := nox_memfile_read_i32(f)
				var v15 byte
				buf[0] = *memmap.PtrUint8(0x5D4594, 830844)
				if id == -1 {
					v15 = byte(nox_memfile_read_i8(f))
					n := int32(nox_memfile_read_u8(f))
					nox_memfile_read(unsafe.Pointer(&buf[0]), 1, n, f)
					buf[n] = 0
				}
				arr[j] = nox_xxx_readImgMB_42FAA0(id, int8(v15), &buf[0])
			}
		}
	}
	return 1
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
