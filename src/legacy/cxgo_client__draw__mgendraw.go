package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func nox_thing_monster_gen_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := vp
	var (
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     uint32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    int32
		v15    int32
		v16    int32
		v17    int32
		result int32
	)
	var v19 *uint8
	var v20 int32
	var v21 *uint8
	v2 = dr
	v3 = int32(dr.Flags70())
	v4 = int32(*(*uint32)(unsafe.Pointer(&dr.Field_76)))
	if v3&0x100 != 0 {
		v5 = 1
	} else if v3&0x200 != 0 {
		v5 = 2
	} else {
		if (dr.Flags70() & 0xC00) != 0 {
			v5 = 3
		} else {
			v5 = 0
		}
	}
	v6 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v5+v4)), 24)))
	v19 = (*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v5+v4)), 24))
	v21 = (*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v5+v4)), 29))
	v20 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v4+v5*4)), 4)))
	switch *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v4+v5*4)), 36)) {
	case 0:
		v7 = v5 + v4 + 29
	case 2:
		v7 = int32((gameFrame() + *(*uint32)(unsafe.Add(v2, 128))) / (uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v5+v4)), 29))) + 1))
		if v7 >= v6 {
			v7 %= v6
		}
	case 4:
		v7 = nox_common_randomIntMinMax_415FF0(0, v6, internCStr("C:\\NoxPost\\src\\client\\Draw\\MGenDraw.c"), 86)
	case 5:
		v7 = int32(*(*uint32)(unsafe.Add(v2, 308)))
	default:
		return 0
	}
	v8 = int32(*(*uint32)(unsafe.Add(v2, 280)))
	if v8&0x800 != 0 {
		v9 = *(*uint32)(unsafe.Add(v2, 120)) & 0xDFFFFFFF
		v7 = v6 - 1
		*(*uint32)(unsafe.Add(v2, 112)) &= 0xFFF7FFFF
		*(*uint32)(unsafe.Add(v2, 120)) = v9
	}
	v10 = int32(*(*uint32)(unsafe.Add(v2, 432)))
	if v10 != 0 {
		v7 = int32((uint32(int32(*v21)+1)*uint32(*v19) - uint32(v10)) / (uint32(*v21) + 1))
		if v7 >= v6 {
			v7 = v6 - 1
		}
		if v7 < 0 {
			v7 = 0
		}
		v11 = v10 - 1
		*(*uint32)(unsafe.Add(v2, 432)) = uint32(v11)
		if v11 == 0 {
			v12 = int32(*(*uint32)(unsafe.Add(v2, 280)))
			*(*uint8)(unsafe.Add(unsafe.Pointer(&v12), 1)) = uint8(int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(&v12), 1)))&0xFB | 8))
			*(*uint32)(unsafe.Add(v2, 280)) = uint32(v12)
		}
	}
	nox_xxx_drawObject_4C4770_draw(a1, (*client.Drawable)(v2), int32(*(*uint32)(unsafe.Pointer(uintptr(v20 + v7*4)))))
	v13 = int32(*(*uint32)(unsafe.Add(v2, 280)))
	if (v13 & 0xC00) == 0 {
		v14 = int32(*(*uint8)(unsafe.Add(v4, 28)))
		v15 = int32((gameFrame() + *(*uint32)(unsafe.Add(v2, 128))) / (uint32(*(*uint8)(unsafe.Add(v4, 33))) + 1))
		if v15 >= v14 {
			v15 %= v14
		}
		nox_xxx_drawObject_4C4770_draw(a1, (*client.Drawable)(v2), int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v4, 20)) + uint32(v15*4))))))
	}
	v16 = int32(*(*uint32)(unsafe.Add(v2, 280)))
	if v16&0x800 == 0 {
		return 1
	}
	v17 = int32(*(*uint32)(unsafe.Add(v2, 120)))
	*((*uint8)(unsafe.Pointer(&v17))) = uint8(int8(v17 | 1))
	*(*uint32)(unsafe.Add(v2, 120)) = uint32(v17)
	return 1
}
