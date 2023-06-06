package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_thing_animate_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := (*uint32)(vp.C())
	var (
		v2 int32
		v3 int32
		v4 int32
		v6 int32
		v7 int32
	)
	v2 = int32(uintptr(dr.Field_76))
	switch *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 12)) {
	case 0:
		v3 = int32((gameFrame() - dr.Field_79) / (uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 9))) + 1))
		v7 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 8)))
		if v3 >= v7 {
			v3 = v7 - 1
		}
	case 1:
		v3 = int32((gameFrame() - dr.Field_79) / (uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 9))) + 1))
		if v3 >= int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 8))) {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
			return 0
		}
	case 2:
		if dr.Flags30()&0x1000000 != 0 {
			v3 = int32((gameFrame() + dr.Field_32) / (uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 9))) + 1))
			v4 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 8)))
			if v3 >= v4 {
				v3 %= v4
			}
			break
		}
		if dr.Flags28()&0x10000000 != 0 {
			if noxflags.HasGame(32) {
				v3 = int32((gameFrame() + dr.Field_32) / (uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 9))) + 1))
				v4 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 8)))
				if v3 >= v4 {
					v3 %= v4
				}
				break
			}
			if dr.Flags28()&0x10000000 != 0 {
				return 1
			}
		}
		v3 = 0
	case 3:
		v6 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 8))) * 2
		nox_client_drawEnableAlpha_434560(1)
		v3 = int32((gameFrame() - dr.Field_79) / (uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 9))) + 1))
		if v3 >= v6 {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
			return 0
		}
		nox_client_drawSetAlpha_434580(uint8(int8(-56 - v3*200/v6)))
		v4 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 8)))
		if v3 >= v4 {
			v3 %= v4
		}
	case 4:
		v3 = nox_common_randomIntMinMax_415FF0(0, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 8)))-1, internCStr("C:\\NoxPost\\src\\Client\\Draw\\animdraw.c"), 24)
	case 5:
		v3 = int32(dr.Field_77)
	default:
		return 1
	}
	nox_xxx_drawObject_4C4770_draw((*int32)(unsafe.Pointer(a1)), dr, int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 4)) + uint32(v3*4))))))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 12)) == 3 {
		nox_client_drawEnableAlpha_434560(0)
	}
	return 1
}
func nox_thing_animate_state_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	a1 := (*uint32)(vp.C())
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int32
	)
	v2 = int32(dr.Flags70())
	v3 = int32(uintptr(dr.Field_76))
	if v2&2 != 0 {
		dr.Field_79 = gameFrame()
		v4 = 0
	} else if v2&4 != 0 {
		v4 = 1
	} else {
		v4 = (int32(uint8(int8(v2))) >> 2) & 2
	}
	v5 = v4*48 + v3 + 4
	if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v5)), 44)) == 2 {
		dr.Field_79 = gameFrame()
	}
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v5)), 40))) != 0 {
		return sub_4BC6B0((*int32)(unsafe.Pointer(a1)), dr, v5)
	} else {
		return 1
	}
}
func nox_things_animate_draw_parse(obj *nox_thing, f *nox_memfile, attr_value *byte) bool {
	var (
		a3     *uint8 = (*uint8)(unsafe.Pointer(attr_value))
		v3     *uint32
		v5     *uint32
		v6     *uint8
		v8     int8
		v10    int8
		result int32
		v13    int32
		v15    int32
		v17    int8
		v19    *byte
		v20    uint8
		v21    uint8
		v22    int32
	)
	v3 = (*uint32)(alloc.Calloc1(1, 0x10))
	v5 = v3
	v6 = a3
	*v3 = 16
	v8 = int8(nox_memfile_read_u8(f))
	*((*uint8)(unsafe.Add(unsafe.Pointer(v5), 8))) = uint8(v8)
	v10 = int8(nox_memfile_read_u8(f))
	*((*uint8)(unsafe.Add(unsafe.Pointer(v5), 9))) = uint8(v10)
	v20 = nox_memfile_read_u8(f)
	nox_memfile_read(unsafe.Pointer(a3), 1, int32(v20), f)
	*(*uint8)(unsafe.Add(unsafe.Pointer(a3), v20)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*3)) = uint32(get_animation_kind_id_44B4C0((*byte)(unsafe.Pointer(a3))))
	result = int32(uintptr(alloc.Calloc1(int(*((*uint8)(unsafe.Add(unsafe.Pointer(v5), 8)))), 4)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) = uint32(result)
	if result == 0 {
		return false
	}
	v13 = 0
	v22 = 0
	if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v5), 8)))) != 0 {
		for {
			v15 = int32(nox_memfile_read_u32(f))
			*v6 = *memmap.PtrUint8(0x5D4594, 830832)
			if v15 == -1 {
				v17 = int8(nox_memfile_read_u8(f))
				*((*uint8)(unsafe.Pointer(&v19))) = uint8(v17)
				v21 = nox_memfile_read_u8(f)
				nox_memfile_read(unsafe.Pointer(v6), 1, int32(v21), f)
				v15 = -1
				*(*uint8)(unsafe.Add(unsafe.Pointer(v6), v21)) = 0
				v13 = v22
			}
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) + uint32(func() int32 {
				p := &v13
				x := *p
				*p++
				return x
			}()*4)))) = uint32(uintptr(unsafe.Pointer(nox_xxx_readImgMB_42FAA0(v15, int8(uintptr(unsafe.Pointer(v19))), (*byte)(unsafe.Pointer(v6))))))
			v22 = v13
			if v13 >= int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v5), 8)))) {
				break
			}
		}
	}
	obj.Field_5c = unsafe.Pointer(v5)
	obj.DrawFunc.Set(nox_thing_animate_draw)
	return true
}
func sub_44BE90(a1 int32, f *nox_memfile) int32 {
	var (
		v2     int32
		result int32
		v4     int32
		v6     int32
		v8     int8
		v10    int32
		v11    *byte
		v12    [128]byte
	)
	v2 = a1
	result = int32(uintptr(alloc.Calloc1(int(*(*int16)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 40))), 4)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 4)) = uint32(result)
	if result != 0 {
		v4 = 0
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 40))) > 0 {
			for {
				v6 = nox_memfile_read_i32(f)
				v12[0] = *memmap.PtrUint8(0x5D4594, 830848)
				if v6 == -1 {
					v8 = int8(nox_memfile_read_u8(f))
					*((*uint8)(unsafe.Pointer(&v11))) = uint8(v8)
					v10 = int32(nox_memfile_read_u8(f))
					nox_memfile_read(unsafe.Pointer(&v12[0]), 1, v10, f)
					v12[v10] = 0
					v2 = a1
				}
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 4)) + uint32(func() int32 {
					p := &v4
					x := *p
					*p++
					return x
				}()*4)))) = uint32(uintptr(unsafe.Pointer(nox_xxx_readImgMB_42FAA0(v6, int8(uintptr(unsafe.Pointer(v11))), &v12[0]))))
				if v4 >= int32(*(*int16)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 40))) {
					break
				}
			}
		}
		result = 1
	}
	return result
}
func nox_things_animate_state_draw_parse(obj *nox_thing, f *nox_memfile, attr_value *byte) bool {
	var (
		data_sz      uint32  = 0x94
		draw_cb_data *uint32 = (*uint32)(alloc.Calloc1(1, uintptr(data_sz)))
	)
	*(*uint32)(unsafe.Add(unsafe.Pointer(draw_cb_data), 4*0)) = data_sz
	for {
		var cmd int32 = int32(nox_memfile_read_u32(f))
		if uint32(cmd) == 0x454E4420 {
			break
		}
		var params int32 = int32(nox_memfile_read_u32(f))
		if (params & 0xE) == 0 {
			return false
		}
		var n uint8
		n = nox_memfile_read_u8(f)
		nox_memfile_skip(f, int32(n))
		n = nox_memfile_read_u8(f)
		nox_memfile_skip(f, int32(n))
		var offset_idx uint8 = 0
		if params&2 != 0 {
			offset_idx = 0
		} else if params&4 != 0 {
			offset_idx = 1
		} else if params&8 != 0 {
			offset_idx = 2
		}
		var v9 int32 = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(draw_cb_data), 4*uintptr(int32(offset_idx)*12+1))))))
		if nox_xxx_loadVectorAnimated_44B8B0(v9, f) == 0 {
			return false
		}
		if sub_44BE90(v9, f) == 0 {
			return false
		}
	}
	obj.Field_54 = 2
	obj.DrawFunc.Set(nox_thing_animate_state_draw)
	obj.Field_5c = unsafe.Pointer(draw_cb_data)
	return true
}
