package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/cmath"
	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var dword_5d4594_1522616 *gui.Window = nil
var dword_5d4594_1522620 *gui.Window = nil
var dword_5d4594_1522624 *gui.Window = nil
var dword_5d4594_1522628 *gui.Window = nil
var nox_wnd_xxx_1522608 *gui.Anim = nil
var nox_gui_itemAmount_item_1319256 *client.Drawable
var nox_gui_itemAmount_dialog_1319228 *gui.Window

func sub_4B9470(a1 unsafe.Pointer) int32 {
	var (
		v1 *byte
		v2 int32
		v3 *uint8
	)
	if a1 == nil {
		return 0
	}
	v1 = *(**byte)(memmap.PtrOff(0x587000, 177488))
	v2 = 0
	if *memmap.PtrUint32(0x587000, 177488) == 0 {
		return 0
	}
	v3 = (*uint8)(memmap.PtrOff(0x587000, 177488))
	for libc.StrCmp(*(**byte)(a1), v1) != 0 {
		v1 = (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2)))))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 8))
		v2++
		if v1 == nil {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v2*8)+177492))
}
func sub_4B94E0(dr *client.Drawable) int32 {
	if dr.ObjClass&0x10000000 == 0 {
		return 0
	}
	return sub_4B9470(unsafe.Pointer(dr.Field_109))
}
func sub_4B95D0(dr *client.Drawable) {
	var (
		v2 int32
		v3 int32
		v5 int32
		v6 *uint8
		v7 *int32
		v8 **uint32
		v9 int32
		a1 = dr
	)
	r1 := nox_xxx_getProjectileClassById_413250(int32(a1.TypeIDVal))
	v4 := r1
	if r1 == nil {
		return
	}
	v5 = 1
	v6 = (*uint8)(unsafe.Add(unsafe.Pointer(r1), 4*4))
	for {
		*(*uint8)(unsafe.Pointer(&v3)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v6), 1))
		*(*uint8)(unsafe.Pointer(&v2)) = *v6
		r3 := *(*uint8)(unsafe.Add(unsafe.Pointer(v6), -1))
		nox_draw_setMaterial_4340A0(func() int32 {
			p := &v5
			x := *p
			*p++
			return x
		}(), int32(r3), v2, v3)
		v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 3))
		if v5 >= 7 {
			break
		}
	}
	v7 = v4.ColorIndexes()
	v8 = (**uint32)(unsafe.Add(unsafe.Pointer(a1), 432))
	v9 = 4
	for {
		r4 := *v8
		if *v8 != nil {
			*(*uint8)(unsafe.Pointer(&v3)) = *(*uint8)(unsafe.Add(unsafe.Pointer(r4), 26))
			*(*uint8)(unsafe.Pointer(&v2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(r4), 25))
			r5 := *(*uint8)(unsafe.Add(unsafe.Pointer(r4), 24))
			nox_draw_setMaterial_4340A0(*v7, int32(r5), v2, v3)
		}
		v8 = (**uint32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof((*uint32)(nil))*1))
		v7 = (*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1))
		v9--
		if v9 == 0 {
			break
		}
	}
}
func sub_4B9650(a1 int32) {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 *uint8
	)
	r := nox_xxx_getProjectileClassById_413250(a1)
	if r == nil {
		return
	}
	v4 = 1
	v5 = (*uint8)(unsafe.Add(unsafe.Pointer(r), 4*4))
	for {
		*(*uint8)(unsafe.Pointer(&v3)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v5), 1))
		*(*uint8)(unsafe.Pointer(&v2)) = *v5
		r3 := *(*uint8)(unsafe.Add(unsafe.Pointer(v5), -1))
		nox_draw_setMaterial_4340A0(func() int32 {
			p := &v4
			x := *p
			*p++
			return x
		}(), int32(r3), v2, v3)
		v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 3))
		if v4 >= 7 {
			break
		}
	}
}
func sub_4B96F0(dr *client.Drawable) {
	var (
		v2 int32
		v3 int32
		v5 int32
		v6 *uint8
		v7 *int32
		v8 **uint32
		v9 int32
		a1 = dr
	)
	r1 := nox_xxx_equipClothFindDefByTT_413270(int32(a1.TypeIDVal))
	v4 := r1
	if r1 == nil {
		return
	}
	v5 = 1
	v6 = (*uint8)(unsafe.Add(unsafe.Pointer(r1), 4*4))
	for {
		*(*uint8)(unsafe.Pointer(&v3)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v6), 1))
		*(*uint8)(unsafe.Pointer(&v2)) = *v6
		r3 := *(*uint8)(unsafe.Add(unsafe.Pointer(v6), -1))
		nox_draw_setMaterial_4340A0(func() int32 {
			p := &v5
			x := *p
			*p++
			return x
		}(), int32(r3), v2, v3)
		v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 3))
		if v5 >= 7 {
			break
		}
	}
	v7 = v4.ColorIndexes()
	v8 = (**uint32)(unsafe.Add(unsafe.Pointer(a1), 432))
	v9 = 4
	for {
		r4 := *v8
		if *v8 != nil {
			*(*uint8)(unsafe.Pointer(&v3)) = *(*uint8)(unsafe.Add(unsafe.Pointer(r4), 26))
			*(*uint8)(unsafe.Pointer(&v2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(r4), 25))
			r5 := *(*uint8)(unsafe.Add(unsafe.Pointer(r4), 24))
			nox_draw_setMaterial_4340A0(*v7, int32(r5), v2, v3)
		}
		v8 = (**uint32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof((*uint32)(nil))*1))
		v7 = (*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1))
		v9--
		if v9 == 0 {
			break
		}
	}
}
func sub_4BA670(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) {
	var (
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  float64
		v10 float64
		v11 float64
		v12 float64
		v13 float64
		v14 float64
		v15 float64
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 *uint8
		v21 float32
		a4a Point32
		a3a Point32
		a2a Point32
		a1a Point32
		v26 float32
	)
	v5 = a5
	v6 = a4 - a2
	v7 = a5 - a3
	v8 = int32(sub_48C6B0(a4-a2, a5-a3))
	dword_5d4594_1316408 = uint32(v8/40 + 1)
	if v8/40+2 >= 30 {
		dword_5d4594_1316408 = 28
	}
	a1a.X = a2
	v9 = float64(*memmap.PtrFloat32(0x587000, uintptr(a1)*8+194136))
	v10 = float64(*memmap.PtrFloat32(0x587000, uintptr(a1)*8+194140))
	v11 = float64(a4 - a2)
	v12 = float64(v7)
	a1a.Y = a3
	a2a.X = a4
	a2a.Y = v5
	dword_5d4594_1313880 = float32(v12)
	v26 = float32(math.Sqrt(v12*float64(dword_5d4594_1313880)+v11*v11) + 0.0099999998)
	*memmap.PtrFloat32(0x5D4594, 1313876) = float32(v11 / float64(v26))
	v13 = float64(dword_5d4594_1313880 / v26)
	dword_5d4594_1313880 = float32(v13)
	v14 = v13*v10 + float64(*memmap.PtrFloat32(0x5D4594, 1313876))*v9
	if v14 < 0.0 {
		v14 = v14 * 0.2
	}
	v15 = (1.0 - v14) * float64(v8) * 2.3
	*memmap.PtrFloat32(0x5D4594, 1313868) = float32(v9 * v15)
	*memmap.PtrFloat32(0x5D4594, 1313872) = float32(v10 * v15)
	a3a.X = int32(*memmap.PtrFloat32(0x5D4594, 1313868))
	v16 = int32(*memmap.PtrFloat32(0x5D4594, 1313872))
	a4a.X = v6
	v17 = 0
	a3a.Y = v16
	a4a.Y = v7
	a5 = 0
	for {
		if v17 != 0 {
			*memmap.PtrFloat32(0x5D4594, uintptr(v17)*4+1313856) = float32(float64(*memmap.PtrFloat32(0x5D4594, uintptr(v17)*4+1313856)) + 0.25)
		} else {
			*memmap.PtrFloat32(0x5D4594, 1313856) = float32(float64(*memmap.PtrFloat32(0x5D4594, 1313856)) + 0.2)
		}
		v18 = int32(dword_5d4594_1316408)
		if float64(*memmap.PtrFloat32(0x5D4594, uintptr(v17)*4+1313856)) >= 1.0 {
			v19 = int32(dword_5d4594_1316408 + 1)
			if dword_5d4594_1316408+1 > 0 {
				v20 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr((v19+v17*30)*28)+1313872))
				for {
					*(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*6)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v20), -int(4*1)))
					*(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*7)) = *(*uint32)(unsafe.Pointer(v20))
					*(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*8)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*1))
					*(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*9)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*2))
					*(*uint32)(unsafe.Add(unsafe.Pointer(v20), 4*5)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v20), -int(4*2)))
					v20 = (*uint8)(unsafe.Add(unsafe.Pointer(v20), -28))
					v19--
					if v19 == 0 {
						break
					}
				}
			}
			*memmap.PtrUint32(0x5D4594, uintptr(v17)*4+1313856) = 0
			*memmap.PtrUint32(0x5D4594, uintptr(v17)*840+1313908) = 0
		}
		v21 = *memmap.PtrFloat32(0x5D4594, uintptr(v17)*4+1313856)
		dword_5d4594_1316412 = 0
		sub_4BEDE0(&a1a, &a2a, &a3a, &a4a, v18, v21, sub_4BA8B0, unsafe.Pointer(&a5))
		v17 = func() int32 {
			p := &a5
			*p++
			return *p
		}()
		if a5 >= 3 {
			break
		}
	}
}
func Nox_xxx_prepareLightningEffects_4BAB30() {
	*memmap.PtrUint32(0x5D4594, 1316464) = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316488) = nox_color_rgb_4344A0(128, 128, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316424) = nox_color_rgb_4344A0(128, 128, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316428) = nox_color_rgb_4344A0(64, 64, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316516) = nox_color_rgb_4344A0(200, 200, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316512) = nox_color_rgb_4344A0(128, 128, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316496) = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1316468) = nox_color_rgb_4344A0(math.MaxUint8, math.MaxUint8, 0)
	*memmap.PtrUint32(0x5D4594, 1316460) = nox_color_rgb_4344A0(30, 160, 30)
	*memmap.PtrUint32(0x5D4594, 1316444) = nox_color_rgb_4344A0(60, 140, 60)
	*memmap.PtrUint32(0x5D4594, 1316504) = nox_color_rgb_4344A0(40, 225, 40)
	*memmap.PtrUint32(0x5D4594, 1316480) = nox_color_rgb_4344A0(150, 220, 150)
	*memmap.PtrUint32(0x5D4594, 1316520) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BlueSpark")))
	*memmap.PtrUint32(0x5D4594, 1316524) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("YellowSpark")))
	*memmap.PtrUint32(0x5D4594, 1316528) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GreenSpark")))
}
func nox_xxx_spriteDrawMonsterHP_4BC080(a1 *noxrender.Viewport, a2 *client.Drawable, a3 uint16, a4 uint16, a5 int8) {
	if a2 == nil {
		return
	}
	v5 := int32(a1.Screen.Min.X + a2.PosVec.X - a1.World.Min.X)
	v10 := a2.Shape.Circle.R + a2.Shape.Circle.R
	v6 := int32(v10) + v5
	v7 := int32(a2.PosVec.Y + a1.Screen.Min.Y - int(uint32(a2.ZVal)) - a1.World.Min.Y)
	v11 := a2.ZSizeMax - a2.ZSizeMin
	v8 := int32(v11)
	if v8 < 30 {
		v8 = 30
	}
	v12 := a2.ZSizeMin + a2.ZSizeMax
	v9 := v7 + int32(v12)/(-2) - v8/2
	if int32(a4) == 0 {
		return
	}
	nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
	nox_client_drawRectFilledOpaque_49CE30(v6, v9, 2, v8)
	if int32(a5) != 0 {
		nox_client_drawSetColor_434460(*memmap.PtrInt32(0x8531A0, 2572))
	} else {
		nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 940))
	}
	nox_client_drawRectFilledOpaque_49CE30(v6, v8+v9-v8*int32(a3)/int32(a4), 2, v8*int32(a3)/int32(a4))
}
func sub_4BC6B0(vp *noxrender.Viewport, dr *client.Drawable, ani *client.AnimationVector) int {
	fi := sub_4BC5D0(dr, ani)
	if fi < 0 {
		return 0
	}
	frames := ani.FramesSlice(int(dr.AnimDir))
	nox_xxx_drawObject_4C4770_draw(vp, dr, frames[fi])
	return 1
}
func sub_4BC720(a1 unsafe.Pointer) {
	result := *(*unsafe.Pointer)(unsafe.Add(a1, 304))
	*(*uint32)(unsafe.Add(a1, 432)) = uint32(int32(*(*uint8)(unsafe.Add(result, 27))) * (int32(*(*uint8)(unsafe.Add(result, 32))) + 1))
}
func nox_xxx_updDrawMonsterGen_4BC920(vp *noxrender.Viewport, dr *client.Drawable) int {
	return 1
}
func sub_4BD280(a1 int32, a2 int32) unsafe.Pointer {
	v2 := a2 + 4
	result := alloc.Calloc1(1, uintptr(a1*(a2+4)+4))
	if result == nil {
		return nil
	}
	v4 := (*uint32)(unsafe.Add(result, 4*1))
	*(*uint32)(result) = uint32(uintptr(unsafe.Add(result, 4*1)))
	if a1 != 1 {
		v5 := a1 - 1
		for {
			v5--
			*v4 = uint32(uintptr(unsafe.Add(unsafe.Pointer(v4), v2)))
			v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), v2))
			if v5 == 0 {
				break
			}
		}
	}
	*v4 = 0
	return result
}
func sub_4BD2D0(lpMem unsafe.Pointer) {
	alloc.FreePtr(lpMem)
}
func sub_4BD2E0(a1p unsafe.Pointer) unsafe.Pointer {
	a1 := (*unsafe.Pointer)(a1p)
	result := *a1
	if *a1 == nil {
		return result
	}
	v2 := *(*unsafe.Pointer)(result)
	result = unsafe.Add(result, 4*1)
	*a1 = v2
	return result
}
func sub_4BD300(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	*(*unsafe.Pointer)(unsafe.Add(a2, -4)) = *(*unsafe.Pointer)(a1)
	*(*unsafe.Pointer)(a1) = unsafe.Add(a2, -4)
}
func sub_4BD340(a1 unsafe.Pointer, a2 int32, a3 int32, a4 int32) unsafe.Pointer {
	v4 := alloc.Calloc1(1, 0x1C)
	libc.MemSet(v4, 0, 0x1C)
	*(*unsafe.Pointer)(v4) = a1
	*(*uint32)(unsafe.Add(v4, 4*6)) = uint32(a4)
	*(*uint32)(unsafe.Add(v4, 4*1)) = uint32(uintptr(sub_4BD280(a2/(a4+24), a4+24)))
	*(*uint32)(unsafe.Add(v4, 4*2)) = uint32(uintptr(sub_4BD280(a3, 84)))
	nox_common_list_clear_425760((*nox_list_item_t)(unsafe.Add(v4, 4*3)))
	if *(*uint32)(unsafe.Add(v4, 4*1)) != 0 && *(*uint32)(unsafe.Add(v4, 4*2)) != 0 {
		return v4
	}
	sub_4BD3C0(v4)
	return nil
}
func sub_4BD3C0(lpMem unsafe.Pointer) {
	for i := unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Add(lpMem, 4*3)))); i != nil; i = unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Add(lpMem, 4*3)))) {
		sub_4BD690(i)
	}
	if *(*uint32)(unsafe.Add(lpMem, 4*1)) != 0 {
		sub_4BD2D0(*(*unsafe.Pointer)(unsafe.Add(lpMem, unsafe.Sizeof(unsafe.Pointer(nil))*1)))
	}
	if *(*uint32)(unsafe.Add(lpMem, 4*2)) != 0 {
		sub_4BD2D0(*(*unsafe.Pointer)(unsafe.Add(lpMem, unsafe.Sizeof(unsafe.Pointer(nil))*2)))
	}
	alloc.FreePtr(lpMem)
}
func sub_4BD420(a1 unsafe.Pointer, a2 int32) unsafe.Pointer {
	result := *(*unsafe.Pointer)(unsafe.Add(a1, 12))
	if result == unsafe.Add(a1, 12) {
		return nil
	}
	for *(*uint32)(unsafe.Add(result, 4*4)) != uint32(a2) || *(*uint32)(unsafe.Add(result, 4*5)) == 0 {
		result = *(*unsafe.Pointer)(result)
		if result == unsafe.Add(a1, 12) {
			return nil
		}
	}
	return result
}
func sub_4BD470(a1 unsafe.Pointer, a2 int32) unsafe.Pointer {
	var (
		v8 *byte
	)
	v2 := sub_4BD420(a1, a2)
	v3 := v2
	if v2 != nil {
		nox_common_list_remove_425920(v2)
		sub_425900((*uint32)(unsafe.Add(a1, unsafe.Sizeof((*uint32)(nil))*3)), (*uint32)(v3))
		return v3
	}
	if sub_486B60(*(*unsafe.Pointer)(a1), a2) == 0 {
		return nil
	}
	v5 := sub_4BD2E0(unsafe.Pointer(*(**uint32)(unsafe.Add(a1, unsafe.Sizeof((*uint32)(nil))*2))))
	if v5 == nil {
		sub_4BD600(a1)
		v5 = sub_4BD2E0(unsafe.Pointer(*(**uint32)(unsafe.Add(a1, unsafe.Sizeof((*uint32)(nil))*2))))
		if v5 == nil {
			sub_486E00(*(*unsafe.Pointer)(a1))
			return nil
		}
	}
	*(*uint32)(unsafe.Add(v5, 4*4)) = uint32(a2)
	*(*uint32)(unsafe.Add(v5, 4*13)) = uint32(uintptr(a1))
	sub_425770(v5)
	*(*uint32)(unsafe.Add(v5, 4*3)) = 0
	sub_487C30((*uint32)(unsafe.Add(v5, 4*6)))
	nullsub_10(uint32(uintptr(unsafe.Add(v5, 4*14))))
	*(*uint32)(unsafe.Add(v5, 4*11)) = uint32(uintptr(unsafe.Add(v5, 4*14)))
	v6 := *(*int32)(unsafe.Add(*(*unsafe.Pointer)(a1), 4*71))
	v10 := *(*int32)(unsafe.Add(*(*unsafe.Pointer)(a1), 4*71))
	if v6 == 0 {
		sub_486AA0(*(*unsafe.Pointer)(a1), int32(*(*uint32)(unsafe.Add(v5, 4*4))), (*uint32)(unsafe.Add(v5, 4*14)))
		sub_425900((*uint32)(unsafe.Add(a1, unsafe.Sizeof((*uint32)(nil))*3)), (*uint32)(v5))
		*(*uint32)(unsafe.Add(v5, 4*5)) = 1
		sub_486E00(*(*unsafe.Pointer)(a1))
		return v5
	}
	for {
		v7 := *(*int32)(unsafe.Add(a1, unsafe.Sizeof((*uint32)(nil))*6))
		if v7 > v6 {
			v7 = v6
		}
		v8 = (*byte)(sub_4BD2E0(unsafe.Pointer(*(**uint32)(unsafe.Add(a1, unsafe.Sizeof((*uint32)(nil))*1)))))
		if v8 == nil {
			for sub_4BD600(a1) != 0 {
				v8 = (*byte)(sub_4BD2E0(unsafe.Pointer(*(**uint32)(unsafe.Add(a1, unsafe.Sizeof((*uint32)(nil))*1)))))
				if v8 != nil {
					goto LABEL_17
				}
			}
			sub_4BD690(v5)
			return nil
		}
	LABEL_17:
		sub_487D30((*uint32)(unsafe.Pointer(v8)), int32(uintptr(unsafe.Add(unsafe.Pointer(v8), 24))), v7)
		sub_487C50(unsafe.Add(v5, 4*6), (*uint32)(unsafe.Pointer(v8)))
		v9 := sub_486DB0(*(*unsafe.Pointer)(a1), (*byte)(unsafe.Add(unsafe.Pointer(v8), 24)), v7)
		if v9 != v7 {
			sub_4BD690(v5)
			return nil
		}
		v10 = v10 - v9
		if v10 == 0 {
			sub_486AA0(*(*unsafe.Pointer)(a1), int32(*(*uint32)(unsafe.Add(v5, 4*4))), (*uint32)(unsafe.Add(v5, 4*14)))
			sub_425900((*uint32)(unsafe.Add(a1, unsafe.Sizeof((*uint32)(nil))*3)), (*uint32)(v5))
			*(*uint32)(unsafe.Add(v5, 4*5)) = 1
			sub_486E00(*(*unsafe.Pointer)(a1))
			return v5
		}
		v6 = v10
	}
}
func sub_4BD600(a1 unsafe.Pointer) int32 {
	v1 := sub_425960(unsafe.Add(a1, 12))
	if v1 == nil {
		return 0
	}
	for sub_4BD680(v1) != 0 {
		v1 = sub_425960(v1)
		if v1 == nil {
			return 0
		}
	}
	sub_4BD690(v1)
	return 1
}
func sub_4BD650(a1 unsafe.Pointer) {
	*(*uint32)(unsafe.Add(a1, 12))++
}
func sub_4BD660(a1 unsafe.Pointer) {
	result := int32(*(*uint32)(unsafe.Add(a1, 12)) - 1)
	*(*uint32)(unsafe.Add(a1, 12)) = uint32(result)
	if result < 0 {
		*(*uint32)(unsafe.Add(a1, 12)) = 0
	}
}
func sub_4BD680(a1 unsafe.Pointer) int32 {
	return int32(*(*uint32)(unsafe.Add(a1, 12)))
}
func sub_4BD690(a1 unsafe.Pointer) {
	if *(*unsafe.Pointer)(unsafe.Add(a1, 4)) != a1 {
		nox_common_list_remove_425920(a1)
	}
	for i := (**uint32)(unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Add(a1, 32))))); i != nil; i = (**uint32)(unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Add(a1, 32))))) {
		nox_common_list_remove_425920(unsafe.Pointer(i))
		sub_487D60(unsafe.Pointer(i))
		sub_4BD300(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 52)), 4)), unsafe.Pointer(i))
	}
	sub_4BD300(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 52)), 8)), a1)
}
func sub_4BD710(a1 int32) int32 {
	return a1 + 24
}
func sub_4BD720(a1 unsafe.Pointer) *uint32 {
	var v1 *uint32
	v1 = (*uint32)(alloc.Calloc1(1, 0x138))
	libc.MemSet(unsafe.Pointer(v1), 0, 0x138)
	sub_425770(unsafe.Pointer(v1))
	sub_4BDC00(unsafe.Add(unsafe.Pointer(v1), 4*30))
	sub_4864A0((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*44)))
	sub_4BD7C0(v1)
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*33)) = a1
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*43)) = *(*uint32)(unsafe.Add(a1, 256))
	if ccall.AsFunc[func(unsafe.Pointer) int](*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 256)), 4)))(unsafe.Pointer(v1)) == 0 {
		return v1
	}
	if v1 != nil {
		sub_4BD7A0(unsafe.Pointer(v1))
	}
	return nil
}
func sub_4BD7A0(lpMem unsafe.Pointer) {
	ccall.AsFunc[func(unsafe.Pointer)](*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(lpMem, 4*43)))), 8)))(lpMem)
	alloc.FreePtr(lpMem)
}
func sub_4BD7C0(a1 *uint32) {
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*69)) = uint32(uintptr(ccall.FuncAddr(sub_4BD8C0)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*70)) = uint32(uintptr(ccall.FuncAddr(sub_4BD940)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*71)) = uint32(uintptr(ccall.FuncAddr(sub_4BD9B0)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*34)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*35)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*36)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*38)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) = 1
	sub_4BDC00(unsafe.Add(unsafe.Pointer(a1), 4*30))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*30)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*29)) = *memmap.PtrUint32(0x5D4594, 1193340)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*28)) = 0
	sub_4864A0((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*72)) = 0
}
func sub_4BD840(a3 unsafe.Pointer) {
	v1 := *(*unsafe.Pointer)(unsafe.Add(a3, 132))
	v2 := unsafe.Add(a3, 176)
	sub_4864A0((*uint32)(unsafe.Add(a3, 176)))
	sub_486570(unsafe.Add(a3, 176), (*uint32)(unsafe.Add(a3, 16)))
	sub_486620((*uint32)(unsafe.Add(a3, 16)))
	if *(*uint32)(unsafe.Add(a3, 112)) != 0 {
		sub_486570(v2, *(**uint32)(unsafe.Add(a3, 112)))
		sub_486620(*(**uint32)(unsafe.Add(a3, 112)))
	}
	v3 := *(**uint32)(unsafe.Add(a3, 116))
	if v3 != nil {
		sub_486570(v2, v3)
	}
	sub_486570(v2, (*uint32)(unsafe.Add(v1, 88)))
	result := int32(*(*uint32)(unsafe.Add(v1, 184)))
	if result != 0 {
		sub_486570(v2, *(**uint32)(unsafe.Add(v1, 184)))
	}
}
func sub_4BD8C0(a1 unsafe.Pointer) {
	var (
		result int32
		v4     int32
	)
	v1 := ccall.AsFunc[func(unsafe.Pointer) int32](*(*unsafe.Pointer)(unsafe.Add(a1, 136)))
	if v1 != nil {
		result = v1(a1)
		if result != 0 {
			*(*uint32)(unsafe.Add(a1, 300)) = 0
			*(*uint32)(unsafe.Add(a1, 304)) = 0
			*(*uint32)(unsafe.Add(a1, 296)) = 0
			return
		}
	} else {
		if *(*uint32)(unsafe.Add(a1, 292)) != 0 {
			v3 := unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Pointer(*(**int32)(unsafe.Add(a1, 292))))))
			*(*unsafe.Pointer)(unsafe.Add(a1, 292)) = v3
			if v3 != nil {
				*(*uint32)(unsafe.Add(a1, 296)) = *(*uint32)(unsafe.Add(v3, 12))
				v4 = int32(*(*uint32)(unsafe.Add(v3, 16)))
				*(*uint32)(unsafe.Add(a1, 300)) = uint32(v4)
				*(*uint32)(unsafe.Add(a1, 304)) = uint32(v4)
				return
			}
		}
		*(*uint32)(unsafe.Add(a1, 300)) = 0
	}
}
func sub_4BD940(a1 unsafe.Pointer) {
	if *(*uint32)(unsafe.Add(a1, 128)) != 0 {
		if *(*int32)(unsafe.Add(a1, 128)) != -1 {
			*(*uint32)(unsafe.Add(a1, 128))--
		}
		sub_4BDB90(a1, unsafe.Pointer(*(**uint32)(unsafe.Add(a1, 288))))
	} else {
		sub_4BDB90(a1, nil)
	}
	v1 := ccall.AsFunc[func(unsafe.Pointer)](*(*unsafe.Pointer)(unsafe.Add(a1, 140)))
	if v1 != nil {
		v1(a1)
	}
	if *(*uint32)(unsafe.Add(a1, 288)) != 0 {
		_ = sub_43F0D0
		ccall.AsFunc[func(unsafe.Pointer)](*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 172)), 36)))(a1)
	}
}
func sub_4BD9B0(a2p unsafe.Pointer) int32 {
	a2 := (*uint32)(a2p)
	var (
		v1     int32
		result int32
	)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*72)) = 0
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*31)))
	*(*uint8)(unsafe.Pointer(&v1)) = uint8(int8(v1 & 0xFA))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*31)) = uint32(v1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*32)) = 0
	sub_4864A0((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*4)))
	v2 := ccall.AsFunc[func(unsafe.Pointer) int32](*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*36)))
	if v2 != nil {
		result = v2(unsafe.Pointer(a2))
	} else {
		result = 0
	}
	return result
}
func sub_4BDA60(p unsafe.Pointer) {
	sub_4BDA80(p)
	sub_486E90(p)
	sub_4BD7A0(p)
}
func sub_4BDA80(a1 unsafe.Pointer) int32 {
	var (
		result int32 = 0
	)
	if int32(*(*uint8)(unsafe.Add(a1, 124)))&5 != 0 {
		ccall.AsFunc[func(unsafe.Pointer)](*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 172)), 16)))(a1)
	}
	result2 := ccall.AsFunc[func(unsafe.Pointer) int32](*(*unsafe.Pointer)(unsafe.Add(a1, 148)))
	if result2 != nil {
		result = result2(a1)
	}
	*(*uint32)(unsafe.Add(a1, 288)) = 0
	return result
}
func sub_4BDB20(a1 unsafe.Pointer) {
	*(*uint32)(unsafe.Add(a1, 124)) |= 0x10
}
func sub_4BDB30(a1 unsafe.Pointer) {
	*(*uint32)(unsafe.Add(a1, 124)) &= 0xFFFFFFEF
}
func sub_4BDB40(a2 unsafe.Pointer) int32 {
	if int32(*(*uint8)(unsafe.Add(a2, 124)))&5 != 0 {
		return -2146500608
	}
	if *(*uint32)(unsafe.Add(a2, 288)) == 0 {
		return -2147024896
	}
	sub_486520(unsafe.Add(a2, 16))
	sub_4BD840(a2)
	result := ccall.AsFunc[func(unsafe.Pointer) int](*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a2, 172)), 12)))(a2)
	if result == 0 {
		*(*uint32)(unsafe.Add(a2, 124)) |= 1
	}
	return int32(result)
}
func sub_4BDB90(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	*(*unsafe.Pointer)(unsafe.Add(a1, 4*72)) = a2
	if a2 != nil {
		v2 := sub_487C80(a2)
		*(*unsafe.Pointer)(unsafe.Add(a1, 4*73)) = v2
		if v2 != nil {
			*(*uint32)(unsafe.Add(a1, 4*74)) = *(*uint32)(unsafe.Add(v2, 12))
			v3 := int32(*(*uint32)(unsafe.Add(v2, 16)))
			*(*uint32)(unsafe.Add(a1, 4*75)) = uint32(v3)
			*(*uint32)(unsafe.Add(a1, 4*76)) = uint32(v3)
			*(*uint32)(a2) = 0
		} else {
			v4 := (*uint32)(*(*unsafe.Pointer)(unsafe.Add(a1, 4*72)))
			*(*uint32)(unsafe.Add(a1, 4*74)) = *v4
			v5 := int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))
			*(*uint32)(unsafe.Add(a1, 4*75)) = uint32(v5)
			*(*uint32)(unsafe.Add(a1, 4*76)) = uint32(v5)
		}
	}
}
func sub_4BDC00(a1 unsafe.Pointer) {
	*(*uint32)(unsafe.Add(a1, 8)) = 0
	*(*uint32)(unsafe.Add(a1, 4)) = 0
}
func nox_xxx_loadAdvancedWnd_4BDC10(a1 *int32) {
	dword_5d4594_1316708 = nox_new_window_from_file(internCStr("advanced.wnd"), nox_xxx_windowAdvancedServProc_4BDDB0)
	sub_46B120(dword_5d4594_1316708, nil)
	sub_46C690(dword_5d4594_1316708)
	nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1316708)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1316708, sub_4BDDA0)
	nox_xxx_windowFocus_46B500(dword_5d4594_1316708)
	sub_4BDC70(a1)
}
func sub_4BDC70(a1 *int32) {
	if noxflags.HasGame(1) {
		v1 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316708, 10167)
		v1.DrawData().Field0 |= 4
		dword_5d4594_1316704 = 0
	} else {
		v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316708, 10164)
		v2.DrawData().Field0 |= 4
		v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316708, 10167)
		nox_xxx_wnd_46ABB0(v3, 0)
		dword_5d4594_1316704 = 1
	}
	sub_453F70((*DataZzz)(unsafe.Add(unsafe.Pointer(a1), 4*6)))
	sub_4535E0((*int32)(unsafe.Add(unsafe.Pointer(a1), 4*11)))
	sub_4535F0(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*12)))
	sub_4BDD10()
}
func sub_4BDD10() {
	switch dword_5d4594_1316704 {
	case 0:
		v2 := sub_4165B0()
		v1 := sub_4CEBA0(dword_5d4594_1316708.C(), v2)
		dword_5d4594_1316712 = unsafe.Pointer(v1)
	case 1:
		dword_5d4594_1316712 = nox_xxx_guiSpelllistLoad_453850(dword_5d4594_1316708.C())
		nox_xxx_windowFocus_46B500((*gui.Window)(dword_5d4594_1316712))
		return
	case 2:
		v1 := nox_xxx_guiObjlistLoad_4530C0(dword_5d4594_1316708.C(), 0x1000000)
		dword_5d4594_1316712 = v1
	case 3:
		v1 := nox_xxx_guiObjlistLoad_4530C0(dword_5d4594_1316708.C(), 0x2000000)
		dword_5d4594_1316712 = v1
	default:
		nox_xxx_windowFocus_46B500((*gui.Window)(dword_5d4594_1316712))
		return
	}
	nox_xxx_windowFocus_46B500((*gui.Window)(dword_5d4594_1316712))
}
func sub_4BDDA0(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	return 1
}
func nox_xxx_windowAdvancedServProc_4BDDB0(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v3     int32
		result int32
		v5     *byte
	)
	if a2 == 23 {
		return 1
	}
	if a2 != 16391 {
		return 1
	}
	v3 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	switch v3 {
	case 10148:
		v5 = sub_4165B0()
		alloc.Memcpy(unsafe.Add(unsafe.Pointer(v5), 24), unsafe.Pointer(sub_453F90()), 0x14)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*11)) = *(*uint32)(unsafe.Pointer(sub_453600()))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*12)) = uint32(sub_453610())
		sub_4BDF30()
		return 1
	case 10164:
		if dword_5d4594_1316712 != nil {
			nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(dword_5d4594_1316712))
			dword_5d4594_1316712 = nil
		}
		dword_5d4594_1316704 = 1
		sub_4BDD10()
		result = 1
	case 10165:
		if dword_5d4594_1316712 != nil {
			nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(dword_5d4594_1316712))
			dword_5d4594_1316712 = nil
		}
		dword_5d4594_1316704 = 2
		sub_4BDD10()
		result = 1
	case 10166:
		if dword_5d4594_1316712 != nil {
			nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(dword_5d4594_1316712))
			dword_5d4594_1316712 = nil
		}
		dword_5d4594_1316704 = 3
		sub_4BDD10()
		result = 1
	case 10167:
		if dword_5d4594_1316712 != nil {
			nox_xxx_windowDestroyMB_46C4E0((*gui.Window)(dword_5d4594_1316712))
			dword_5d4594_1316712 = nil
		}
		dword_5d4594_1316704 = 0
		sub_4BDD10()
		result = 1
	default:
		return 1
	}
	return uintptr(result)
}
func sub_4BDF30() {
	if dword_5d4594_1316708 == nil {
		return
	}
	nox_xxx_wnd_46C6E0(dword_5d4594_1316708)
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1316708)
	dword_5d4594_1316708 = nil
	dword_5d4594_1316712 = nil
	nox_xxx_windowFocus_46B500(nil)
}
func sub_4BDF70(a1 *int32) {
	if dword_5d4594_1316708 != nil {
		sub_4BDF90(a1)
	}
}
func sub_4BDF90(a1 *int32) int32 {
	var (
		result  int32 = 0
		result2 func() int32
	)
	sub_453F70((*DataZzz)(unsafe.Add(unsafe.Pointer(a1), 4*6)))
	sub_4535E0((*int32)(unsafe.Add(unsafe.Pointer(a1), 4*11)))
	sub_4535F0(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*12)))
	result2 = ccall.AsFunc[func() int32](*(*unsafe.Pointer)(memmap.PtrOff(0x587000, uintptr(dword_5d4594_1316704)*4+180016)))
	if result2 != nil {
		result = result2()
	}
	return result
}
func sub_4BDFD0() int32 {
	var (
		v1  int32
		v5  int32
		v9  int32
		v10 int32
	)
	v0 := sub_416640()
	v1 = nox_strman_get_lang_code()
	v2 := v0
	if nox_xxx_guiFontHeightMB_43F320(nil) > 10 {
		v1 = 2
	}
	var v3 *gui.Window
	if false {
		v3 = nox_new_window_from_file(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1*4)+180088)), sub_4BE330)
	} else {
		v3 = nox_new_window_from_file(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1*4)+180048)), sub_4BE330)
	}
	dword_5d4594_1316972 = v3
	sub_46B120(v3, nil)
	sub_46C690(dword_5d4594_1316972)
	nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1316972)
	nox_xxx_windowFocus_46B500(dword_5d4594_1316972)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1316972, sub_4BE320)
	v4 := nox_xxx_wndGetChildByID_46B0C0(nil, 10100)
	nox_gui_getWindowOffs_46AA20(v4, (*uint32)(unsafe.Pointer(&v10)), (*uint32)(unsafe.Pointer(&v9)))
	if false {
		v5 = v9 + 55
	} else {
		v5 = v9 + 80
	}
	nox_window_setPos_46A9B0(dword_5d4594_1316972, v10+15, v5)
	v6 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2104)
	nox_xxx_wnd_46B280(v6, dword_5d4594_1316972)
	nox_xxx_wndSetProc_46B2C0(v6, sub_4BE330)
	if false {
		v7 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2119)
		nox_xxx_wnd_46B280(v7, dword_5d4594_1316972)
	}
	return sub_4BE120(v2)
}
func sub_4BE120(a1 *DataYyy2) int32 {
	var (
		v2  int32
		v3  uint32
		v5  int32
		v6  uint32
		v10 *gui.Window
	)
	var v15 int32
	v16, free16 := alloc.Make([]wchar2_t{}, 16)
	defer free16()
	v1 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2102)
	v2 = int32(v1.DrawData().Field0)
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 58)) != 0 {
		v3 = uint32(v2 | 4)
	} else {
		v3 = uint32(v2) & 0xFFFFFFFB
	}
	v1.DrawData().Field0 = v3
	v4 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2103)
	v5 = int32(v4.DrawData().Field0)
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 62)) != 0 {
		v6 = uint32(v5 | 4)
	} else {
		v6 = uint32(v5) & 0xFFFFFFFB
	}
	v4.DrawData().Field0 = v6
	v7 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2110)
	nox_swprintf(&v16[0], internWStr("%d"), *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 70)))
	nox_window_call_field_94_fnc(v7, 16414, uintptr(unsafe.Pointer(&v16[0])), math.MaxUint32)
	switch *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 66)) {
	case 0:
		v8 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2110)
		nox_xxx_wnd_46ABB0(v8, 0)
		v15 = 2106
		v10 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, v15)
		v10.DrawData().Field0 |= 4
	case 1:
		v9 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2110)
		nox_xxx_wnd_46ABB0(v9, 0)
		v10 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2107)
		v10.DrawData().Field0 |= 4
	case 2:
		v11 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2110)
		nox_xxx_wnd_46ABB0(v11, 0)
		v10 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2108)
		v10.DrawData().Field0 |= 4
	case 3:
		v12 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2110)
		nox_xxx_wnd_46ABB0(v12, 1)
		v15 = 2109
		v10 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, v15)
		v10.DrawData().Field0 |= 4
	default:
	}
	if !(false) {
		return 0
	}
	v14 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2119)
	nox_window_call_field_94_fnc(v14, 16394, uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 74))), 0)
	sub_4BE2C0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 74))))
	return 0
}
func sub_4BE320(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	return 1
}
func sub_4BE330(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var v7 *wchar2_t
	var v8 int32
	var v9 int32
	var v21 *wchar2_t
	var v22 int32
	if a2 > 0x4007 {
		if a2 == 16393 {
			sub_4BE2C0(int32(a4))
			nox_xxx_gameSetAudioFadeoutMb_501AC0(int32(a4))
		} else if a2 == 16415 {
			v20 := sub_416640()
			v21 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16413, 0, 0)))
			if v21 != nil {
				if *v21 != 0 {
					v22 = int32(libc.WStrtol(v21, nil, 10))
					if v22 < 0 {
						v22 = 0
					}
					if nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) == 2110 {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v20), 70)) = uint32(v22)
						return 1
					}
				}
			}
		}
		return 1
	}
	if a2 != 16391 {
		if !(a2 != 23 && a2 == 16387) {
			return 1
		}
		v4 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, int32(a4))
		v5 := sub_416640()
		if v4 == nil {
			return 0
		}
		if int32(uint16(a3)) == 1 {
			return 0
		}
		v7 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(v4, 16413, 0, 0)))
		if !(v7 != nil && *v7 != 0) {
			return 1
		}
		v8 = int32(libc.WStrtol(v7, nil, 10))
		if v8 < 0 {
			v8 = 0
		}
		if a4 == 2110 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 70)) = uint32(v8)
			return 1
		}
		return 1
	}
	v9 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	switch v9 {
	case 2102:
		v10 := sub_416640()
		*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 58)) ^= 1
		return 1
	case 2103:
		v11 := sub_416640()
		*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 62)) ^= 1
		return 1
	case 2106:
		v12 := sub_416640()
		v13 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2110)
		nox_xxx_wnd_46ABB0(v13, 0)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v12), 66)) = 0
		sub_40A6A0(1)
		return 1
	case 2107:
		v14 := sub_416640()
		v15 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2110)
		nox_xxx_wnd_46ABB0(v15, 0)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 66)) = 1
		sub_40A6A0(1)
		return 1
	case 2108:
		v16 := sub_416640()
		v17 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2110)
		nox_xxx_wnd_46ABB0(v17, 0)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v16), 66)) = 2
		sub_40A6A0(1)
		return 1
	case 2109:
		v18 := sub_416640()
		v19 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1316972, 2110)
		nox_xxx_wnd_46ABB0(v19, 1)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v18), 66)) = 3
		sub_40A6A0(1)
		return 1
	case 2130:
		sub_4BE610()
		return 1
	default:
		return 1
	}
}
func sub_4BE610() {
	if dword_5d4594_1316972 == nil {
		return
	}
	nox_xxx_wnd_46C6E0(dword_5d4594_1316972)
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1316972)
	dword_5d4594_1316972 = nil
	nox_xxx_windowFocus_46B500(nil)
}
func sub_4BE800(a1 int32) {
	*memmap.PtrUint32(0x5D4594, 1316980) = uint32(a1)
}
func sub_4BE810(a1 int32, a2 int32, a3 int32, a4 int8) {
	*memmap.PtrUint32(0x5D4594, 1316988) = uint32(a1)
	*memmap.PtrUint32(0x5D4594, 1316984) = uint32(a2)
	*memmap.PtrUint32(0x5D4594, 1316992) = uint32(a3)
	*memmap.PtrUint8(0x5D4594, 1316996) = uint8(a4)
}
func sub_4BEAD0(a1 *Point32, a2 *Point32, a3 *Point32, a4 *Point32, a5 int32, a6 int32) {
	var (
		v6  int32
		v7  float64
		v8  *uint8
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 *uint8
		v17 int32
		v18 float64
		v19 float64
		v20 float64
		v21 float64
		v22 float64
		v23 float64
		v24 float64
		v25 float64
		v26 float64
		v27 int32
		v28 int32
		i   int32
		v30 int32
		v31 int32
		v32 int32
		v33 bool
		v34 int32
		v35 int32
		v36 int32
		v37 int32
		v38 int32
		v39 int32
		v40 [8]int32
		v41 int32
		v42 int32
		v43 float32
		v44 int32
		v45 int32
		v46 float32
		v47 int32
		v48 int32
	)
	v36 = a1.X
	v41 = a1.Y
	v6 = a4.Y
	v34 = a4.X
	v7 = 1.0 / float64(a5)
	v35 = a2.X
	v39 = a2.Y
	v42 = a3.X
	v38 = a3.Y
	v44 = v6
	v8 = (*uint8)(memmap.PtrOff(0x581450, 9876))
	v45 = 0
	for {
		v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1)))
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*2)))
		v37 = v9
		v11 = int32(uint32(v39) * *(*uint32)(unsafe.Pointer(v8)))
		v12 = int32(uint32(v35)**(*uint32)(unsafe.Pointer(v8)) + uint32(v34*v10) + uint32(v42*v9))
		v13 = v36
		v14 = int32(uint32(v41) * *(*uint32)(unsafe.Add(unsafe.Pointer(v8), -int(4*1))))
		v15 = int32(uint32(v36)**(*uint32)(unsafe.Add(unsafe.Pointer(v8), -int(4*1))) + uint32(v12))
		v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 16))
		v40[v45+4] = v15
		*(*int32)(unsafe.Add(unsafe.Pointer(&v40[0]), v45*4)) = v14 + v11 + v38*v37 + v44*v10
		v45++
		if int32(uintptr(unsafe.Pointer(v8))) >= int32(uintptr(memmap.PtrOff(0x581450, 9940))) {
			break
		}
	}
	*memmap.PtrFloat32(0x587000, 180484) = float32(v7)
	v16 = (*uint8)(memmap.PtrOff(0x587000, 180468))
	v17 = 0
	dword_587000_180480 = uint32(float32(v7 * v7))
	dword_587000_180476 = uint32(float32(v7 * v7 * v7))
	*memmap.PtrFloat32(0x587000, 180496) = float32(dword_587000_180480 + dword_587000_180480)
	v18 = float64(dword_587000_180476) * 6.0
	*memmap.PtrFloat32(0x587000, 180492) = float32(v18)
	*memmap.PtrFloat32(0x587000, 180508) = float32(v18)
	v19 = float64(v40[7])
	v20 = float64(v40[6])
	v21 = float64(v40[5])
	v22 = float64(v40[4])
	v23 = float64(v40[3])
	v24 = float64(v40[2])
	v43 = float32(float64(v40[1]))
	v46 = float32(float64(v40[0]))
	for {
		v25 = v22 * float64(*(*float32)(unsafe.Add(unsafe.Pointer(v16), -int(unsafe.Sizeof(float32(0))*2))))
		v26 = v21 * float64(*(*float32)(unsafe.Add(unsafe.Pointer(v16), -int(unsafe.Sizeof(float32(0))*1))))
		v16 = (*uint8)(unsafe.Add(unsafe.Pointer(v16), 16))
		*(*float32)(unsafe.Add(unsafe.Pointer(&v40[0]), v17*4)) = float32(v25 + v26 + v20*float64(*(*float32)(unsafe.Add(unsafe.Pointer(v16), -int(unsafe.Sizeof(float32(0))*4)))) + v19*float64(*(*float32)(unsafe.Add(unsafe.Pointer(v16), -int(unsafe.Sizeof(float32(0))*3)))))
		v17++
		*(*float32)(unsafe.Pointer(&v40[v17+3])) = float32(float64(v46**(*float32)(unsafe.Add(unsafe.Pointer(v16), -int(unsafe.Sizeof(float32(0))*6)))+v43**(*float32)(unsafe.Add(unsafe.Pointer(v16), -int(unsafe.Sizeof(float32(0))*5)))) + v24*float64(*(*float32)(unsafe.Add(unsafe.Pointer(v16), -int(unsafe.Sizeof(float32(0))*4)))) + v23*float64(*(*float32)(unsafe.Add(unsafe.Pointer(v16), -int(unsafe.Sizeof(float32(0))*3)))))
		if int32(uintptr(unsafe.Pointer(v16))) >= int32(uintptr(memmap.PtrOff(0x587000, 180532))) {
			break
		}
	}
	if a5 > 0 {
		v47 = a5
		for {
			*(*float32)(unsafe.Pointer(&v40[0])) = *(*float32)(unsafe.Pointer(&v40[0])) + *(*float32)(unsafe.Pointer(&v40[1]))
			*(*float32)(unsafe.Pointer(&v40[1])) = *(*float32)(unsafe.Pointer(&v40[2])) + *(*float32)(unsafe.Pointer(&v40[1]))
			*(*float32)(unsafe.Pointer(&v40[2])) = *(*float32)(unsafe.Pointer(&v40[3])) + *(*float32)(unsafe.Pointer(&v40[2]))
			*(*float32)(unsafe.Pointer(&v40[4])) = *(*float32)(unsafe.Pointer(&v40[4])) + *(*float32)(unsafe.Pointer(&v40[5]))
			*(*float32)(unsafe.Pointer(&v40[5])) = *(*float32)(unsafe.Pointer(&v40[6])) + *(*float32)(unsafe.Pointer(&v40[5]))
			*(*float32)(unsafe.Pointer(&v40[6])) = *(*float32)(unsafe.Pointer(&v40[7])) + *(*float32)(unsafe.Pointer(&v40[6]))
			v27 = int32(*(*float32)(unsafe.Pointer(&v40[0])))
			v28 = int32(*(*float32)(unsafe.Pointer(&v40[4])))
			nox_client_drawAddPoint_49F500(v13, v41)
			nox_client_drawAddPoint_49F500(v27, v28)
			nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1316980))
			nox_client_drawLineFromPoints_49E4B0()
			if a6 != 0 {
				v48 = 0
				for i = v13 - v28; ; i = v13 - v28 {
					if v48 != 0 {
						v30 = 1
					} else {
						v30 = -1
					}
					if i >= 0 {
						v31 = i
					} else {
						v31 = v28 - v13
					}
					if i < 0 {
						i = v28 - v13
					}
					if v31 <= i {
						nox_client_drawAddPoint_49F500(v30+v27, v28)
						nox_client_drawAddPoint_49F500(v13+v30, v41)
					} else {
						nox_client_drawAddPoint_49F500(v27, v30+v28)
						nox_client_drawAddPoint_49F500(v13, v41+v30)
					}
					nox_client_drawLineFromPoints_49E4B0()
					if func() int32 {
						p := &v48
						*p++
						return *p
					}() >= 2 {
						break
					}
				}
			}
			if *memmap.PtrUint32(0x5D4594, 1316988) != 0 {
				nox_client_drawAddPoint_49F500(v13, v41)
				nox_client_drawAddPoint_49F500(v27, v28)
				nox_draw_set54RGB32_434040(*memmap.PtrInt32(0x5D4594, 1316984))
				sub_434080(*memmap.PtrInt32(0x5D4594, 1316992))
				v32 = int32(*memmap.PtrUint8(0x5D4594, 1316996))
				sub_49E4F0(v32)
			}
			v13 = v27
			v33 = v47 == 1
			v41 = v28
			v47--
			if v33 {
				break
			}
		}
	}
}
func sub_4BEDE0(a1 *Point32, a2 *Point32, a3 *Point32, a4 *Point32, a5 int32, a6 float32, a7 func(*Point32, *Point32, unsafe.Pointer), a8 unsafe.Pointer) {
	var (
		v8  int32
		v9  float64
		v10 *uint8
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 float64
		v17 float64
		v18 float64
		v19 float32
		v20 float32
		v21 float32
		v22 float32
		v23 int32
		v24 float32
		v25 int32
		v26 float32
		v27 int32
		v28 float32
		v29 int32
		v30 float32
		v31 int32
		v32 float32
		v33 int32
		v34 float32
		v35 [5]Point32
		v36 *Point32
		v37 float32
		v38 *Point32
		v39 float32
		v40 int32
		v41 float32
		v42 int32
		v43 float32
		v44 float32
		v45 float32
	)
	v8 = a1.X
	v33 = a1.Y
	v35[2].Y = a1.Y
	v25 = v8
	v35[2].X = v8
	v27 = a2.X
	v9 = 1.0 / float64(a5)
	v23 = a3.X
	v29 = a3.Y
	v21 = 0.0
	v40 = a4.X
	v31 = a2.Y
	v42 = a4.Y
	v10 = (*uint8)(memmap.PtrOff(0x581450, 9876))
	v38 = nil
	for {
		v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*1)))
		v12 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*2)))
		v36 = (*Point32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v10), -int(4*1))))))
		v13 = int32(uint32(v27)**(*uint32)(unsafe.Pointer(v10)) + uint32(v25)*uint32(uintptr(unsafe.Pointer(v36))) + uint32(v23*v11) + uint32(v40*v12))
		v14 = int32(uint32(v33)*uint32(uintptr(unsafe.Pointer(v36))) + uint32(v31)**(*uint32)(unsafe.Pointer(v10)) + uint32(v29*v11) + uint32(v42*v12))
		v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v10), 16))
		*(*int32)(unsafe.Add(unsafe.Pointer(&v35[0].X), uint32(uintptr(unsafe.Pointer(v38))))) = v13
		*(*int32)(unsafe.Add(unsafe.Pointer(&v35[3].X), uint32(uintptr(unsafe.Pointer(v38))))) = v14
		v38 = (*Point32)(unsafe.Add(unsafe.Pointer(v38), 4))
		if int32(uintptr(unsafe.Pointer(v10))) >= int32(uintptr(memmap.PtrOff(0x581450, 9940))) {
			break
		}
	}
	v15 = a5
	if a5 > 0 {
		v16 = v9 * float64(a6)
		v41 = float32(v16 + v9)
		v45 = float32(float64(v35[0].X))
		v43 = float32(float64(v35[0].Y))
		v34 = float32(float64(v35[1].X))
		v32 = float32(float64(v35[1].Y))
		v28 = float32(float64(v35[3].X))
		v30 = float32(float64(v35[3].Y))
		v26 = float32(float64(v35[4].X))
		v24 = float32(float64(v35[4].Y))
		for {
			v17 = float64(v41 + v21)
			v22 = float32(v17)
			if v17 > 1.0 {
				v22 = 1.0
			}
			v18 = float64(v22 * v22)
			v44 = float32(v18)
			v37 = float32(v18 * float64(v22))
			v19 = v43*v44 + v45*v37 + v34*v22 + v32
			v35[0].X = int32(v19)
			v20 = v30*v44 + v28*v37 + v26*v22 + v24
			v35[0].Y = int32(v20)
			v39 = float32(v16)
			v21 = v22 - v39
			a7(&v35[2], &v35[0], a8)
			v15--
			v35[2].X = v35[0].X
			v35[2].Y = v35[0].Y
			if v15 == 0 {
				break
			}
		}
	}
}
func nox_xxx_clientReportSecondaryWeapon_4BF010(a1 *client.Drawable) int32 {
	var v3 [3]byte
	v3[0] = 224
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(nox_xxx_netGetUnitCodeCli_578B00(a1))
	return nox_xxx_netClientSend2_4E53C0(31, unsafe.Pointer(&v3[0]), 3, 1)
}
func sub_4BF7E0(a1 *uint32) {
	var (
		v1  int32
		v2  int32
		v3  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v13 int32
		v14 *uint8
		v15 *uint8
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) + 15)
	v2 = int32(*a1 + 11)
	v13 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) + 15)
	nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
	nox_client_drawRectFilledOpaque_49CE30(v2, v1, 200, 200)
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v3), unsafe.Sizeof(uint16(0))*0)) = *memmap.PtrUint16(0x852978, 8)
	if *memmap.PtrUint32(0x852978, 8) == 0 {
		return
	}
	v4 := *memmap.PtrPtr(0x8531A0, 2576)
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 {
		return
	}
	nox_draw_setMaterial_4341D0(1, int32(*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2296))))
	nox_draw_setMaterial_4341D0(2, int32(*(*uint32)(unsafe.Add(v4, 2304))))
	nox_draw_setMaterial_4341D0(3, int32(*(*uint32)(unsafe.Add(v4, 2312))))
	nox_draw_setMaterial_4341D0(4, int32(*(*uint32)(unsafe.Add(v4, 2308))))
	nox_draw_setMaterial_4341D0(5, int32(*(*uint32)(unsafe.Add(v4, 2300))))
	nox_draw_setMaterial_4341D0(6, int32(*(*uint32)(unsafe.Add(v4, 2292))))
	if *(*uint32)(unsafe.Add(v4, 2292)) == *(*uint32)(unsafe.Add(v4, 2296)) {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x973A20, uintptr(int32(*(*uint8)(unsafe.Add(v4, 2252)))*4+24))), v2, v1)
	} else {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x973A20, uintptr(int32(*(*uint8)(unsafe.Add(v4, 2252)))*4+16))), v2, v1)
	}
	v5 = 0
	v14 = (*uint8)(memmap.PtrOff(0x973A20, uintptr(int32(*(*uint8)(unsafe.Add(v4, 2252)))*104+32)))
	for {
		if *(*uint32)(v4)&uint32(1<<v5) != 0 && (uint32(1<<v5)&0x3000000) == 0 {
			v6 = int32(sub_415CD0(uint32(int32(uintptr(1 << v5)))))
			sub_4BF9F0(1<<v5, v6, v2, v13, unsafe.Pointer(v14), v5, 0)
		}
		v5++
		if v5 >= 26 {
			break
		}
	}
	if int32(*(*uint8)(v4))&2 != 0 {
		v7 = int32(sub_415CD0(uint32(int32(uintptr(2)))))
		sub_4BF9F0(2, v7, v2, v13, unsafe.Pointer(v14), 0, 1)
	}
	v8 = 0
	for {
		if *(*uint32)(v4)&uint32(1<<v8) != 0 && uint32(1<<v8)&0x3000000 != 0 {
			v9 = int32(sub_415CD0(uint32(int32(uintptr(1 << v8)))))
			sub_4BF9F0(1<<v8, v9, v2, v13, unsafe.Pointer(v14), v8, 0)
		}
		v8++
		if v8 >= 26 {
			break
		}
	}
	v10 = 0
	v15 = (*uint8)(memmap.PtrOff(0x973A20, uintptr(int32(*(*uint8)(unsafe.Add(v4, 2252)))*108+256)))
	for {
		v3 := int32(*(*uint32)(unsafe.Add(v4, 4)))
		if v3&(1<<v10) != 0 {
			v11 = sub_415840(uint32(int32(uintptr(1 << v10))))
			sub_4BF9F0(1<<v10, v11, v2, v13, unsafe.Pointer(v15), v10, 0)
		}
		v10++
		if v10 >= 27 {
			break
		}
	}
}
func sub_4BF9F0(a1 int32, a2 int32, a3 int32, a4 int32, a5 unsafe.Pointer, a6 int32, a7 int32) {
	var (
		v13 unsafe.Pointer
		v14 int32
		v15 unsafe.Pointer
		v16 *int32
		v18 int32
	)
	v7 := sub_461600(a2)
	v8 := v7
	if v7 == nil {
		return
	}
	var v9p unsafe.Pointer
	if v7.ObjClass&0x2000000 != 0 {
		v9p = unsafe.Pointer(nox_xxx_equipClothFindDefByTT_413270(int32(v7.TypeIDVal)))
	} else {
		v9p = unsafe.Pointer(nox_xxx_getProjectileClassById_413250(int32(v7.TypeIDVal)))
	}
	v12 := v9p
	if v9p != nil {
		v13 = unsafe.Add(unsafe.Pointer(v8), 432)
		v14 = 1
		v15 = unsafe.Add(v9p, 4*4)
		for {
			v9 := *(*uint8)(unsafe.Add(v15, 1))
			v11 := *(*uint8)(v15)
			v10 := *(*uint8)(unsafe.Add(v15, -1))
			nox_draw_setMaterial_4340A0(func() int32 {
				p := &v14
				x := *p
				*p++
				return x
			}(), int32(v10), int32(v11), int32(v9))
			v15 = unsafe.Add(v15, 3)
			if v14 >= 7 {
				break
			}
		}
		v16 = (*int32)(unsafe.Add(v12, 4*9))
		v17 := (*unsafe.Pointer)(v13)
		v18 = 4
		for {
			v19p := *v17
			if *v17 != nil {
				v11 := *(*uint8)(unsafe.Add(v19p, 26))
				v10 := *(*uint8)(unsafe.Add(v19p, 25))
				v19 := *(*uint8)(unsafe.Add(v19p, 24))
				nox_draw_setMaterial_4340A0(*v16, int32(v19), int32(v10), int32(v11))
			}
			v17 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v17), unsafe.Sizeof((*uint8)(nil))*1))
			v16 = (*int32)(unsafe.Add(unsafe.Pointer(v16), 4*1))
			v18--
			if v18 == 0 {
				break
			}
		}
	}
	if a7 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1319052)), a3, a4)
	} else {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*(*unsafe.Pointer)(unsafe.Add(a5, a6*4))), a3, a4)
	}
}
func sub_4BFAD0() int32 {
	var (
		v0 int32
		v1 int32
		i  int32
		v4 *byte
		v5 int32
		v6 int32
	)
	v0 = 0
	v1 = 0
	for i = 0; i < 8; i += 4 {
		v3 := nox_xxx_gLoadImg_42F970(*(**byte)(memmap.PtrOff(0x587000, uintptr(i)+180960)))
		v4 = *(**byte)(memmap.PtrOff(0x587000, uintptr(i)+180968))
		*memmap.PtrPtr(0x973A20, uintptr(i+16)) = unsafe.Pointer(v3)
		*memmap.PtrT[noxrender.ImageHandle](0x973A20, uintptr(i+24)) = nox_xxx_gLoadImg_42F970(v4)
		v5 = 26
		for {
			*memmap.PtrT[noxrender.ImageHandle](0x973A20, uintptr(v1+32)) = nox_xxx_gLoadImg_42F970(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1)+180976)))
			v1 += 4
			v5--
			if v5 == 0 {
				break
			}
		}
		v6 = 27
		for {
			*memmap.PtrT[noxrender.ImageHandle](0x973A20, uintptr(v0+256)) = nox_xxx_gLoadImg_42F970(*(**byte)(memmap.PtrOff(0x587000, uintptr(v0)+181184)))
			v0 += 4
			v6--
			if v6 == 0 {
				break
			}
		}
	}
	*memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319052) = nox_xxx_gLoadImg_42F970(internCStr("MaleMedievalCloakTop"))
	return 1
}
func sub_4BFB70(a1 int32) {
	if dword_5d4594_1319056 != 0 {
		dword_5d4594_1319056 = uint32(a1)
	} else {
		if a1 == 1 {
			nox_xxx_clientPlaySoundSpecial_452D80(1022, 100)
		}
		dword_5d4594_1319056 = uint32(a1)
	}
}
func sub_4BFBB0(a1 *uint32) {
	if dword_5d4594_1319056 != 0 {
		if dword_5d4594_1319056 == 1 {
			if a1 == nil {
				sub_4BFC70()
				sub_4BFB70(0)
			}
		}
	} else if uintptr(unsafe.Pointer(a1)) == uintptr(1) {
		sub_4BFBF0()
		sub_4BFB70(1)
	}
}
func sub_4BFBF0() {
	var (
		v1 int32
		v2 int32
	)
	if dword_5d4594_1319060 == nil {
		return
	}
	nox_window_set_hidden(dword_5d4594_1319060, 0)
	nox_xxx_wnd_46ABB0(dword_5d4594_1319060, 1)
	nox_window_get_size(dword_5d4594_1319060, &v2, &v1)
	nox_window_setPos_46A9B0(dword_5d4594_1319060, nox_win_width/2-v2/2, nox_win_height/2-v1/2)
	nox_xxx_windowFocus_46B500(nil)
}
func sub_4BFC70() {
	if dword_5d4594_1319060 != nil {
		nox_window_set_hidden(dword_5d4594_1319060, 1)
		nox_xxx_windowFocus_46B500(nil)
	}
}
func sub_4BFC90() int32 {
	result := nox_new_window_from_file(internCStr("SKey.wnd"), sub_4BFCD0)
	dword_5d4594_1319060 = result
	if result == nil {
		return 0
	}
	sub_4BFB70(0)
	sub_4BFC70()
	return 1
}
func sub_4BFCD0(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var v3 int32
	if a2 != 16391 {
		return 0
	}
	v3 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	if v3 == 10803 {
		sub_4BFC70()
	}
	return 0
}
func sub_4BFD10() {
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1319060)
	dword_5d4594_1319060 = nil
	sub_4BFB70(0)
}
func sub_4BFD30() int32 {
	return int32(dword_5d4594_1319056)
}
func sub_4BFD40() {
	if dword_5d4594_1319268 == 1 {
		nox_window_set_hidden(nox_gui_itemAmount_dialog_1319228, 1)
		nox_xxx_wnd_46ABB0(nox_gui_itemAmount_dialog_1319228, 0)
		nox_xxx_wnd_46C6E0(nox_gui_itemAmount_dialog_1319228)
		if nox_gui_itemAmount_item_1319256 != nil {
			nox_xxx_spriteDelete_45A4B0(nox_gui_itemAmount_item_1319256)
		}
		nox_gui_itemAmount_item_1319256 = nil
		dword_5d4594_1319268 = 0
	} else {
		nox_xxx_wnd_46ABB0(nox_gui_itemAmount_dialog_1319228, 1)
		sub_46C690(nox_gui_itemAmount_dialog_1319228)
		nox_xxx_wndShowModalMB_46A8C0(nox_gui_itemAmount_dialog_1319228)
		dword_5d4594_1319268 = 1
	}
}
func sub_4BFDD0(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	switch a2 {
	case 5, 9, 13:
		if !nox_xxx_wndPointInWnd_46AAB0(win, int32(uint16(a3)), int32(a3>>16)) {
			sub_4BFE40()
		}
		return 1
	case 6, 7, 10, 11, 14, 15:
		return 1
	default:
		return 0
	}
}
func sub_4BFE40() int32 {
	var (
		v0 *wchar2_t
		v1 uint32
		v3 int32
		v4 int32
		v5 Point32
	)
	if dword_5d4594_1319268 != 1 {
		return 0
	}
	v0 = sub_46AF00(dword_5d4594_1319232)
	v1 = uint32(libc.WStrtol(v0, nil, 10))
	if v1 > dword_5d4594_1319248 {
		v1 = dword_5d4594_1319248
	}
	nox_gui_getWindowOffs_46AA20(nox_gui_itemAmount_dialog_1319228, (*uint32)(unsafe.Pointer(&v3)), (*uint32)(unsafe.Pointer(&v4)))
	v5.X = v3 + dword_587000_183456
	v5.Y = v4 + dword_587000_183460
	if fnc := *memmap.PtrPtr(0x5D4594, 1319100); fnc != nil {
		ccall.AsFunc[ItemDialogFunc](fnc)(unsafe.Pointer(&v5), memmap.Int32(0x5D4594, 1319244), memmap.Uint32(0x5D4594, 1319240), int32(v1), memmap.Uint32(0x5D4594, 1319252))
	}
	sub_4BFD40()
	return 1
}
func nox_gui_itemAmount_init_4BFEF0() int32 {
	dword_5d4594_1319264 = 0
	nox_gui_itemAmount_dialog_1319228 = nox_new_window_from_file(internCStr("MultMove.wnd"), sub_4C01C0)
	if nox_gui_itemAmount_dialog_1319228 == nil {
		return 0
	}
	nox_window_set_all_funcs(nox_gui_itemAmount_dialog_1319228, sub_4BFDD0, sub_4C0030, nil)
	dword_5d4594_1319232 = nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3601)
	dword_5d4594_1319236 = nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3607)
	nox_window_set_hidden(nox_gui_itemAmount_dialog_1319228, 1)
	nox_xxx_wnd_46ABB0(nox_gui_itemAmount_dialog_1319228, 0)
	*memmap.PtrUint32(0x5D4594, 1319108) = 0
	*memmap.PtrUint32(0x5D4594, 1319112) = 0
	*memmap.PtrUint32(0x5D4594, 1319116) = uint32(nox_win_width)
	*memmap.PtrUint32(0x5D4594, 1319120) = uint32(nox_win_height)
	*memmap.PtrUint32(0x5D4594, 1319140) = uint32(nox_win_width)
	*memmap.PtrUint32(0x5D4594, 1319144) = uint32(nox_win_height)
	*memmap.PtrUint32(0x5D4594, 1319124) = 0
	*memmap.PtrUint32(0x5D4594, 1319128) = 0
	*memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319196) = nox_xxx_gLoadImg_42F970(internCStr("MultiMoveBase"))
	*memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319200) = nox_xxx_gLoadImg_42F970(internCStr("MultiMoveUpLit"))
	*memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319204) = nox_xxx_gLoadImg_42F970(internCStr("MultiMoveDownLit"))
	*memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319208) = nox_xxx_gLoadImg_42F970(internCStr("MultiMoveYesPressed"))
	*memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319212) = nox_xxx_gLoadImg_42F970(internCStr("MultiMoveNoPressed"))
	*memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319216) = nox_xxx_gLoadImg_42F970(internCStr("MultiMoveBaseNoTag"))
	*memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319220) = nox_xxx_gLoadImg_42F970(internCStr("MultiMoveYesPressedNoTag"))
	*memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319224) = nox_xxx_gLoadImg_42F970(internCStr("MultiMoveNoPressedNoTag"))
	return 1
}
func sub_4C0030(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1 = win
		v5 int32
		v6 int32
	)
	nox_client_drawRectFilledAlpha_49CF10(0, 0, nox_win_width, nox_win_height)
	nox_gui_getWindowOffs_46AA20(a1, (*uint32)(unsafe.Pointer(&v5)), (*uint32)(unsafe.Pointer(&v6)))
	v1 := *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319196)
	if dword_5d4594_1319264 == 0 {
		v1 = *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319216)
	}
	nox_client_drawImageAt_47D2C0(v1, v5, v6)
	nox_gui_itemAmount_item_1319256.PosVec.X = int(v5 + dword_587000_183456)
	nox_gui_itemAmount_item_1319256.PosVec.Y = int(v6 + dword_587000_183460)
	nox_gui_itemAmount_item_1319256.DrawFunc.Get()((*noxrender.Viewport)(memmap.PtrOff(0x5D4594, 1319108)), nox_gui_itemAmount_item_1319256)
	if nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3603).DrawData().Field0&4 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1319204)), v5, v6)
	}
	if nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3602).DrawData().Field0&4 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1319200)), v5, v6)
	}
	if nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3604).DrawData().Field0&4 != 0 {
		v2 := *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319208)
		if dword_5d4594_1319264 == 0 {
			v2 = *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319220)
		}
		nox_client_drawImageAt_47D2C0(v2, v5, v6)
	}
	if nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3605).DrawData().Field0&4 == 0 {
		return 1
	}
	v3 := *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319212)
	if dword_5d4594_1319264 == 0 {
		v3 = *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1319224)
	}
	nox_client_drawImageAt_47D2C0(v3, v5, v6)
	return 1
}
func sub_4C01C0(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v3     int32
		result int32
		v5     *wchar2_t
		v6     uint32
		v7     *wchar2_t
		v8     uint32
		v9     *wchar2_t
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    Point32
	)
	if a2 != 16391 || dword_5d4594_1319268 != 1 {
		return 0
	}
	v3 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	switch v3 {
	case 3602:
		v7 = sub_46AF00(dword_5d4594_1319232)
		v8 = uint32(libc.WStrtol(v7, nil, 10) + 1)
		if v8 > dword_5d4594_1319248 {
			return 0
		}
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319164)), internWStr("%d"), v8)
		sub_46AEE0(dword_5d4594_1319232, int32(uintptr(memmap.PtrOff(0x5D4594, 1319164))))
		if dword_5d4594_1319264 == 0 {
			return 0
		}
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319068)), internWStr("%d"), dword_5d4594_1319260*v8)
		sub_46AEE0(dword_5d4594_1319236, int32(uintptr(memmap.PtrOff(0x5D4594, 1319068))))
		result = 0
	case 3603:
		v9 = sub_46AF00(dword_5d4594_1319232)
		v10 = int32(libc.WStrtol(v9, nil, 10))
		v11 = v10
		if v10 > 1 {
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319164)), internWStr("%d"), v10-1)
			sub_46AEE0(dword_5d4594_1319232, int32(uintptr(memmap.PtrOff(0x5D4594, 1319164))))
			if dword_5d4594_1319264 != 0 {
				nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319068)), internWStr("%d"), dword_5d4594_1319260*uint32(v11-1))
				sub_46AEE0(dword_5d4594_1319236, int32(uintptr(memmap.PtrOff(0x5D4594, 1319068))))
			}
		}
		return 0
	case 3604, 3606:
		v5 = sub_46AF00(dword_5d4594_1319232)
		v6 = uint32(libc.WStrtol(v5, nil, 10))
		if v6 > dword_5d4594_1319248 {
			v6 = dword_5d4594_1319248
		}
		nox_gui_getWindowOffs_46AA20(nox_gui_itemAmount_dialog_1319228, (*uint32)(unsafe.Pointer(&v12)), (*uint32)(unsafe.Pointer(&v13)))
		v14.X = v12 + dword_587000_183456
		v14.Y = v13 + dword_587000_183460
		if fnc := *memmap.PtrPtr(0x5D4594, 1319160); fnc != nil {
			ccall.AsFunc[ItemDialogFunc](fnc)(unsafe.Pointer(&v14), memmap.Int32(0x5D4594, 1319244), memmap.Uint32(0x5D4594, 1319240), int32(v6), memmap.Uint32(0x5D4594, 1319252))
		}
		sub_4BFD40()
		result = 0
	case 3605:
		sub_4BFE40()
		result = 0
	default:
		return 0
	}
	return uintptr(result)
}
func nox_gui_itemAmount_free_4C03E0() {
	if nox_gui_itemAmount_item_1319256 != nil {
		nox_xxx_spriteDelete_45A4B0(nox_gui_itemAmount_item_1319256)
	}
	nox_gui_itemAmount_item_1319256 = nil
	nox_xxx_windowDestroyMB_46C4E0(nox_gui_itemAmount_dialog_1319228)
	nox_gui_itemAmount_dialog_1319228 = nil
	dword_5d4594_1319232 = nil
	dword_5d4594_1319236 = nil
	dword_5d4594_1319264 = 0
}

type ItemDialogFunc func(a1 unsafe.Pointer, a2 int32, a3 uint32, a4 int32, a5 uint32)

func nox_gui_itemAmountDialog_4C0430(title *wchar2_t, x int32, y int32, a4 int32, a5 int32, a6 unsafe.Pointer, a7 int32, a8 int32, accept, cancel ItemDialogFunc) {
	v10 := nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3606)
	sub_46AEE0(v10, int32(uintptr(unsafe.Pointer(title))))
	nox_gui_itemAmount_item_1319256 = nox_new_drawable_for_thing(a5)
	nox_gui_itemAmount_item_1319256.ObjFlags |= 0x40000000
	if a6 != nil {
		nox_gui_itemAmount_item_1319256.Union = *(*client.DrawableUnion)(a6)
	}
	*memmap.PtrPtr(0x5D4594, 1319160) = ccall.FuncAddr(accept)
	*memmap.PtrPtr(0x5D4594, 1319100) = ccall.FuncAddr(cancel)
	*memmap.PtrUint32(0x5D4594, 1319240) = uint32(a5)
	*memmap.PtrUint32(0x5D4594, 1319244) = uint32(a4)
	dword_5d4594_1319248 = uint32(a7)
	*memmap.PtrUint32(0x5D4594, 1319252) = uint32(a8)
	sub_4BFD40()
	sub_4C0560(x, y)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319164)), internWStr("%d"), 1)
	sub_46AEE0(dword_5d4594_1319232, int32(uintptr(memmap.PtrOff(0x5D4594, 1319164))))
	if dword_5d4594_1319264 != 0 {
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319068)), internWStr("%d"), dword_5d4594_1319260)
		sub_46AEE0(dword_5d4594_1319236, int32(uintptr(memmap.PtrOff(0x5D4594, 1319068))))
	} else {
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319068)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1319272)))
		sub_46AEE0(dword_5d4594_1319236, int32(uintptr(memmap.PtrOff(0x5D4594, 1319068))))
	}
}
func sub_4C0560(a1 int32, a2 int32) int32 {
	var v5, v6 int32
	nox_window_get_size(nox_gui_itemAmount_dialog_1319228, &v5, &v6)
	v2 := a1 - dword_587000_183456
	v3 := a2 - dword_587000_183460
	if a1-dword_587000_183456 < 0 {
		v2 = 0
	}
	if v3 < 0 {
		v3 = 0
	}
	if v2+v5 >= nox_win_width {
		v2 = nox_win_width - v5
	}
	if v3+v6 >= nox_win_height {
		v3 = nox_win_height - v6
	}
	return nox_window_setPos_46A9B0(nox_gui_itemAmount_dialog_1319228, v2, v3)
}
func sub_4C05F0(a1 int32, a2 int32) {
	dword_5d4594_1319264 = uint32(a1)
	dword_5d4594_1319260 = uint32(a2)
}
func nox_xxx_func_4C0610() int32 {
	var v1 [2]byte
	v1[0] = 201
	v1[1] = 14
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, &v1[0], 2)
}
func sub_4C0630(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	var (
		v6  int32
		v7  int32
		v9  int32
		v10 int32
		v15 int32
		a1a Point32
	)
	a1a.Y = int32(a3 >> 16)
	a1a.X = int32(uint16(a3))
	if a2 == 5 {
		v12 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3704)
		if !(nox_xxx_wndPointInWnd_46AAB0(v12, a1a.X, a1a.Y)) {
			return 1
		}
		v13 := sub_4C0910(&a1a)
		v14 := v13
		if *(*uint32)(unsafe.Add(v13, 4*1)) == 0 {
			return 1
		}
		nox_xxx_wndSetCaptureMain_46ADC0(dword_5d4594_1320940)
		nox_xxx_setKeybTimeout_4160D0(2)
		*(*Point32)(memmap.PtrOff(0x5D4594, 1319276)) = a1a
		dword_5d4594_1320968 = *(**client.Drawable)(v14)
		dword_5d4594_1320968.NetCode32 = *(*uint32)(unsafe.Add(v14, 4*uintptr(*(*uint32)(unsafe.Add(v14, 4*1))+1)))
		*(*uint32)(unsafe.Add(v14, 4*uintptr(*(*uint32)(unsafe.Add(v14, 4*1))+1))) = 0
		nox_xxx_cursorSetDraggedItem_477690(dword_5d4594_1320968)
		v15 = int32(*(*uint32)(unsafe.Add(v14, 4*1)) - 1)
		*(*uint32)(unsafe.Add(v14, 4*1)) = uint32(v15)
		if v15 == 0 {
			*(*uint32)(v14) = 0
		}
		dword_5d4594_1320972 = v14
		*memmap.PtrUint32(0x5D4594, 1320304) = 0
		nox_xxx_clientPlaySoundSpecial_452D80(791, 100)
		return 1
	}
	if a2 <= 5 || a2 > 7 {
		return 0
	}
	v3 := nox_xxx_wndGetCaptureMain_46AE00()
	v4 := dword_5d4594_1320940
	if v3 == dword_5d4594_1320940 {
		nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_1320940)
		v4 = dword_5d4594_1320940
	}
	if dword_5d4594_1320968 == nil {
		return 1
	}
	if *memmap.PtrUint32(0x5D4594, 1320304) != 0 {
		if *memmap.PtrUint32(0x5D4594, 1320304) == 1 {
			v8 := nox_xxx_wndGetChildByID_46B0C0(v4, 3705)
			if !nox_xxx_wndPointInWnd_46AAB0(v8, a1a.X, a1a.Y) || (func() bool {
				v9 = int32(*memmap.PtrUint32(0x5D4594, 1319276) - uint32(a1a.X))
				v10 = int32(*memmap.PtrUint32(0x5D4594, 1319280) - uint32(a1a.Y))
				return !nox_xxx_checkKeybTimeout_4160F0(3, gameFPS()/3)
			}()) && v9*v9+v10*v10 < 100 {
				nox_xxx_clientTrade_0_4C08E0(dword_5d4594_1320968)
			}
		}
	} else {
		v5 := nox_xxx_wndGetChildByID_46B0C0(v4, 3704)
		if nox_xxx_wndPointInWnd_46AAB0(v5, a1a.X, a1a.Y) {
			v6 = int32(*memmap.PtrUint32(0x5D4594, 1319276) - uint32(a1a.X))
			v7 = int32(*memmap.PtrUint32(0x5D4594, 1319280) - uint32(a1a.Y))
			if !nox_xxx_checkKeybTimeout_4160F0(2, gameFPS()/3) && v6*v6+v7*v7 < 100 {
				nox_xxx_clientTrade_0_4C08E0(dword_5d4594_1320968)
			}
		} else {
			nox_xxx_clientTrade_0_4C08E0(dword_5d4594_1320968)
		}
	}
	*(*uint32)(unsafe.Add(dword_5d4594_1320972, func() uint32 {
		p := (*uint32)(unsafe.Add(dword_5d4594_1320972, 4))
		x := *p
		*p++
		return x
	}()*4+8)) = dword_5d4594_1320968.NetCode32
	if *(*uint32)(unsafe.Add(dword_5d4594_1320972, 4)) == 1 {
		*(**client.Drawable)(dword_5d4594_1320972) = dword_5d4594_1320968
	}
	nox_xxx_cursorResetDraggedItem_4776A0()
	dword_5d4594_1320968 = nil
	dword_5d4594_1320972 = nil
	return 1
}
func nox_xxx_clientTrade_0_4C08E0(a1 *client.Drawable) int32 {
	var v2 [4]byte
	v2[0] = 201
	v2[1] = 16
	*(*uint16)(unsafe.Pointer(&v2[2])) = uint16(nox_xxx_netGetUnitCodeCli_578B00(a1))
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, &v2[0], 4)
}
func sub_4C0910(a1 *Point32) unsafe.Pointer {
	var (
		v2  int32
		v3  int32
		i   int32
		v7  int32
		v8  int32
		v9  int32
		v10 int4
	)
	v1 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3704)
	nox_client_wndGetPosition_46AA60(v1, &v8, &v9)
	v2 = 0
	v7 = 0
	for {
		v3 = 0
		for i = 0; i < 100; i += 50 {
			v10.field_0 = i + v8
			v10.field_8 = i + v8 + 50
			v10.field_4 = v2 + v9
			v10.field_C = v2 + v9 + 50
			v5 := nox_xxx_pointInRect_4281F0(a1, &v10)
			if v5 != 0 {
				return memmap.PtrOff(0x5D4594, uintptr((v7+v3*2)*140)+1319284)
			}
			v3++
		}
		v2 += 50
		v7++
		if v2 < 100 {
			continue
		}
		break
	}
	return nil
}
func sub_4C0C90(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var v3 int32
	if a2 != 16391 {
		return 0
	}
	v3 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	if v3 == 3708 {
		nox_xxx_clientTrade_4C0CE0()
	} else if v3 == 3710 {
		nox_xxx_func_4C0610()
		return 0
	}
	return 0
}
func nox_xxx_clientTrade_4C0CE0() int32 {
	var v1 [2]byte
	v1[0] = 201
	v1[1] = 17
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, &v1[0], 2)
}
func sub_4C0D00(win *gui.Window, draw *gui.WindowData) int {
	var (
		v6  *uint8
		v7  int32
		v8  int32
		v9  int32
		v11 *uint8
		v12 int32
		v13 int32
		v14 int32
		v16 *uint8
		v17 *uint8
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 int32
		v23 [32]wchar2_t
	)
	nox_gui_getWindowOffs_46AA20(dword_5d4594_1320940, (*uint32)(unsafe.Pointer(&v21)), (*uint32)(unsafe.Pointer(&v22)))
	nox_window_get_size(dword_5d4594_1320940, &v20, &v19)
	nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1320164)), v21, v22)
	v0 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3711)
	nox_window_call_field_94_fnc(v0, 16385, uintptr(memmap.PtrOff(0x5D4594, 1320240)), 0)
	v1 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3712)
	nox_window_call_field_94_fnc(v1, 16385, uintptr(memmap.PtrOff(0x5D4594, 1320868)), 0)
	v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3713)
	nox_window_call_field_94_fnc(v2, 16385, uintptr(memmap.PtrOff(0x5D4594, 1320100)), 0)
	nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1320184)), int32(uint32(v21)+*memmap.PtrUint32(0x587000, 183696)-64), int32(uint32(v22)+*memmap.PtrUint32(0x587000, 183700)-64))
	nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1320184)), int32(uint32(v21)+*memmap.PtrUint32(0x587000, 183704)-64), int32(uint32(v22)+*memmap.PtrUint32(0x587000, 183708)-64))
	v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3708)
	if dword_5d4594_1320944 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1320172)), v21, v22)
	} else if v3.DrawData().Field0&4 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1320168)), v21, v22)
	}
	if dword_5d4594_1320948 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1320176)), v21, v22)
	}
	v4 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3710)
	if *memmap.PtrUint32(0x5D4594, 1320960) != 0 || v4.DrawData().Field0&4 != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1320180)), v21, v22)
	}
	v5 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3704)
	nox_client_wndGetPosition_46AA60(v5, &v21, &v22)
	v6 = (*uint8)(memmap.PtrOff(0x5D4594, 1319284))
	v18 = nox_xxx_guiFontHeightMB_43F320(nil)
	v7 = 0
	v16 = (*uint8)(memmap.PtrOff(0x5D4594, 1319284))
	for {
		v8 = 0
		for {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1)) != 0 {
				*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v6)), 12)) = uint32(v8 + v21 + 25)
				*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v6)), 16)) = uint32(v22 + v7 + 25)
				ccall.AsFunc[func(*uint8, uint32)](*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v6)), 300)))((*uint8)(memmap.PtrOff(0x5D4594, 1320188)), *(*uint32)(unsafe.Pointer(v6)))
				nox_swprintf(&v23[0], internWStr("%d"), *(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1)))
				nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
				nox_xxx_drawString_43F6E0(nil, &v23[0], v8+v21+5, v22+v7+5)
				v9 = v22 + v7 + 50
				nox_swprintf(&v23[0], internWStr("%d"), *(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*34)))
				nox_xxx_drawSetTextColor_434390(int32(nox_color_yellow_2589772))
				nox_xxx_drawString_43F6E0(nil, &v23[0], v8+v21+5, v9-v18-5)
			}
			v8 += 50
			v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 280))
			if v8 >= 100 {
				break
			}
		}
		v7 += 50
		v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v16), 140))
		v16 = (*uint8)(unsafe.Add(unsafe.Pointer(v16), 140))
		if int32(uintptr(unsafe.Pointer(v16))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1319564))) {
			break
		}
	}
	v10 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3705)
	nox_client_wndGetPosition_46AA60(v10, &v21, &v22)
	v11 = (*uint8)(memmap.PtrOff(0x5D4594, 1320308))
	v12 = 0
	v17 = (*uint8)(memmap.PtrOff(0x5D4594, 1320308))
	for {
		v13 = 0
		for {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*1)) != 0 {
				*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v11)), 12)) = uint32(v13 + v21 + 25)
				*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v11)), 16)) = uint32(v22 + v12 + 25)
				ccall.AsFunc[func(*uint8, uint32)](*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v11)), 300)))((*uint8)(memmap.PtrOff(0x5D4594, 1320188)), *(*uint32)(unsafe.Pointer(v11)))
				nox_swprintf(&v23[0], internWStr("%d"), *(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*1)))
				nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
				nox_xxx_drawString_43F6E0(nil, &v23[0], v13+v21+5, v22+v12+5)
				v14 = v22 + v12 + 50
				nox_swprintf(&v23[0], internWStr("%d"), *(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*34)))
				nox_xxx_drawSetTextColor_434390(int32(nox_color_yellow_2589772))
				nox_xxx_drawString_43F6E0(nil, &v23[0], v13+v21+5, v14-v18-5)
			}
			v13 += 50
			v11 = (*uint8)(unsafe.Add(unsafe.Pointer(v11), 280))
			if v13 >= 100 {
				break
			}
		}
		v12 += 50
		v11 = (*uint8)(unsafe.Add(unsafe.Pointer(v17), 140))
		v17 = (*uint8)(unsafe.Add(unsafe.Pointer(v17), 140))
		if int32(uintptr(unsafe.Pointer(v17))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1320588))) {
			break
		}
	}
	return 1
}
func sub_4C1120(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	var (
		v4  unsafe.Pointer
		v6  *wchar2_t
		a1a Point32
	)
	a1a.X = int32(uint16(a3))
	a1a.Y = int32(uint32(a3) >> 16)
	v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3704)
	if nox_xxx_wndPointInWnd_46AAB0(v3, int32(uint16(a3)), int32(uint32(a3)>>16)) {
		v4 = sub_4C0910(&a1a)
	} else {
		v5 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3705)
		if nox_xxx_wndPointInWnd_46AAB0(v5, a1a.X, a1a.Y) {
			v4 = sub_4C11E0((*uint32)(unsafe.Pointer(&a1a)))
		} else {
			v4 = unsafe.Pointer(a3)
		}
	}
	if *(*unsafe.Pointer)(v4) == nil {
		return 1
	}
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(v4), 4*32)) = uint32(uintptr(unsafe.Pointer(*(**wchar2_t)(unsafe.Add(v4, unsafe.Sizeof((*wchar2_t)(nil))*2)))))
	v6 = nox_xxx_clientAskInfoMb_4BF050((*client.Drawable)(unsafe.Pointer(*(*unsafe.Pointer)(v4))))
	nox_xxx_cursorSetTooltip_4776B0(v6)
	return 1
}
func sub_4C11E0(a1 *uint32) unsafe.Pointer {
	var (
		v2  int32
		v3  int32
		i   int32
		v5  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int4
	)
	v1 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3705)
	nox_client_wndGetPosition_46AA60(v1, &v8, &v9)
	v2 = 0
	v7 = 0
	for {
		v3 = 0
		for i = 0; i < 100; i += 50 {
			v10.field_0 = i + v8
			v10.field_8 = i + v8 + 50
			v10.field_4 = v2 + v9
			v10.field_C = v2 + v9 + 50
			v5 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(a1)), &v10)
			if v5 != 0 {
				return memmap.PtrOff(0x5D4594, uintptr((v7+v3*2)*140)+1320308)
			}
			v3++
		}
		v2 += 50
		v7++
		if v2 < 100 {
			continue
		}
		break
	}
	return nil
}
func nox_xxx_closeP2PTradeWnd_4C12A0() {
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1320940)
	dword_5d4594_1320940 = nil
	dword_5d4594_1320964 = 0
}
func sub_4C12C0() int32 {
	return int32(dword_5d4594_1320964)
}
func nox_xxx_showP2PTradeWnd_4C12D0() {
	if dword_5d4594_1320964 != 0 {
		nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1320940)
	}
}
func nox_xxx_netP2PStartTrade_4C1320(a1 unsafe.Pointer) int32 {
	var (
		v1 int32
		v5 int32
		v6 int32
	)
	v1 = int32(*memmap.PtrUint32(0x8531A0, 2576))
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 {
		return 0
	}
	if dword_5d4594_1320964 == 1 {
		return 0
	}
	dword_5d4594_1320964 = 1
	sub_4C1410()
	nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1319844)), (*wchar2_t)(unsafe.Add(a1, 2)))
	nox_xxx_wnd_46ABB0(dword_5d4594_1320940, 1)
	nox_xxx_showP2PTradeWnd_4C12D0()
	nox_window_get_size(dword_5d4594_1320940, &v6, &v5)
	nox_window_setPos_46A9B0(dword_5d4594_1320940, 198, 193)
	v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3702)
	nox_window_call_field_94_fnc(v3, 16385, uintptr(v1+4704), 0)
	v4 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3703)
	nox_window_call_field_94_fnc(v4, 16385, uintptr(memmap.PtrOff(0x5D4594, 1319844)), 0)
	sub_467BB0()
	return 1
}
func sub_4C1410() {
	var (
		v4 int32
		v5 *uint8
		v6 *uint8
		v7 int32
	)
	v12, free12 := alloc.Make([]wchar2_t{}, 64)
	defer free12()
	*memmap.PtrUint16(0x5D4594, 1320240) = 0
	*memmap.PtrUint16(0x5D4594, 1320868) = 0
	*memmap.PtrUint16(0x5D4594, 1320100) = 0
	v0 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3702)
	nox_window_call_field_94_fnc(v0, 16385, uintptr(memmap.PtrOff(0x5D4594, 1320976)), 0)
	v1 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3703)
	nox_window_call_field_94_fnc(v1, 16385, uintptr(memmap.PtrOff(0x5D4594, 1320980)), 0)
	v2 := memmap.PtrOff(0x5D4594, 1319284)
	for {
		v3 := v2
		v4 = 2
		for {
			if *(*uint32)(unsafe.Pointer(v3)) != 0 {
				nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(*(**uint64)(unsafe.Pointer(v3)))))
			}
			*(*uint32)(unsafe.Pointer(v3)) = 0
			*(*uint32)(unsafe.Add(v3, 4*1)) = 0
			v3 = unsafe.Add(v3, 280)
			v4--
			if v4 == 0 {
				break
			}
		}
		v2 = unsafe.Add(v2, 140)
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1319564))) {
			break
		}
	}
	v5 = (*uint8)(memmap.PtrOff(0x5D4594, 1320308))
	for {
		v6 = v5
		v7 = 2
		for {
			if *(*uint32)(unsafe.Pointer(v6)) != 0 {
				nox_xxx_spriteDelete_45A4B0((*client.Drawable)(unsafe.Pointer(*(**uint64)(unsafe.Pointer(v6)))))
			}
			*(*uint32)(unsafe.Pointer(v6)) = 0
			*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1)) = 0
			v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 280))
			v7--
			if v7 == 0 {
				break
			}
		}
		v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 140))
		if int32(uintptr(unsafe.Pointer(v5))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1320588))) {
			break
		}
	}
	nox_swprintf(&v12[0], (*wchar2_t)(memmap.PtrOff(0x5D4594, 1319972)), 0)
	v8 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3711)
	nox_window_call_field_94_fnc(v8, 16385, uintptr(unsafe.Pointer(&v12[0])), 0)
	v9 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3712)
	nox_window_call_field_94_fnc(v9, 16385, uintptr(unsafe.Pointer(&v12[0])), 0)
	v10 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3713)
	nox_window_call_field_94_fnc(v10, 16385, uintptr(unsafe.Pointer(&v12[0])), 0)
	dword_5d4594_1320944 = 0
	dword_5d4594_1320948 = 0
	dword_5d4594_1320968 = nil
	dword_5d4594_1320972 = nil
	dword_5d4594_1320932 = nil
	dword_5d4594_1320936 = nil
}
func sub_4C1590() {
	if dword_5d4594_1320964 == 0 {
		return
	}
	sub_4C1410()
	nox_window_set_hidden(dword_5d4594_1320940, 1)
	nox_xxx_wnd_46ABB0(dword_5d4594_1320940, 0)
	dword_5d4594_1320964 = 0
	sub_467C10()
}
func sub_4C1710(a1 unsafe.Pointer, a2 int32) int32 {
	var (
		result int32
		i      *uint32
		v4     *uint32
		v5     int32
	)
	result = 0
	for i = (*uint32)(unsafe.Add(a1, 8)); *i != uint32(a2); i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) {
		if func() int32 {
			p := &result
			*p++
			return *p
		}() >= 32 {
			return result
		}
	}
	if result < 31 {
		v4 = (*uint32)(unsafe.Add(a1, result*4+8))
		v5 = 31 - result
		for {
			result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))
			*v4 = uint32(result)
			v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
			v5--
			if v5 == 0 {
				break
			}
		}
	}
	*(*uint32)(unsafe.Add(a1, 132)) = 0
	return result
}
func sub_4C1760(a1 unsafe.Pointer, a2 int32) int32 {
	var (
		v2 int32
		i  *uint32
	)
	if *(*uint32)(unsafe.Add(a1, 4)) == 0 {
		return 0
	}
	v2 = 0
	for i = (*uint32)(unsafe.Add(a1, 8)); *i != uint32(a2); i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) {
		if func() int32 {
			p := &v2
			*p++
			return *p
		}() >= 32 {
			return 0
		}
	}
	return 1
}
func nox_xxx_tradeClientAddItem_4C1790(a1 unsafe.Pointer) {
	var (
		v3 unsafe.Pointer
		v7 *uint8
		v9 int32
	)
	if dword_5d4594_1320964 == 0 {
		return
	}
	v2 := a1
	dword_5d4594_1320944 = 0
	dword_5d4594_1320948 = 0
	if int32(*(*uint8)(unsafe.Add(a1, 2))) == 1 {
		v3 = dword_5d4594_1320932
		if dword_5d4594_1320932 == nil {
			v3 = sub_4C1910(int32(*(*uint16)(unsafe.Add(a1, 3))))
		} else if sub_4C18E0(int32(*(*uint16)(unsafe.Add(a1, 3))), dword_5d4594_1320932) {

		} else {
			v3 = sub_4C1910(int32(*(*uint16)(unsafe.Add(a1, 3))))
		}
	} else {
		v3 = dword_5d4594_1320936
		if dword_5d4594_1320936 == nil {
			v3 = sub_4C19C0(int32(*(*uint16)(unsafe.Add(a1, 3))))
		} else if sub_4C18E0(int32(*(*uint16)(unsafe.Add(a1, 3))), dword_5d4594_1320936) {

		} else {
			v3 = sub_4C19C0(int32(*(*uint16)(unsafe.Add(a1, 3))))
		}
	}
	if v3 == nil {
		return
	}
	if *(*uint32)(unsafe.Pointer(v3)) == 0 {
		v4 := nox_new_drawable_for_thing(int32(*(*uint16)(unsafe.Add(a1, 3))))
		*(*uint32)(unsafe.Pointer(v3)) = uint32(uintptr(unsafe.Pointer(v4)))
		if v4.ObjClass&0x13001000 != 0 {
			v6 := (**server.ModifierEff)(unsafe.Add(unsafe.Pointer(v4), 4*108))
			v7 = (*uint8)(unsafe.Add(a1, 11))
			for {
				if int32(*v7) == -1 {
					*v6 = nil
				} else {
					v8 := nox_xxx_modifGetDescById_413330(int32(*v7))
					*v6 = v8
				}
				v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 1))
				v6 = (**server.ModifierEff)(unsafe.Add(unsafe.Pointer(v6), 4*1))
				if uintptr(unsafe.Pointer(v7))-uintptr(a1)-11 >= 4 {
					break
				}
			}
		}
		*(*uint32)(unsafe.Add(v3, 4*1)) = 0
		*(*uint32)(unsafe.Add(v3, 4*34)) = 0
	}
	*(*uint32)(unsafe.Add(v3, *(*uint32)(unsafe.Add(v3, 4*1))*4+8)) = uint32(*(*uint16)(unsafe.Add(v2, 5)))
	v9 = int32(*(*uint32)(unsafe.Add(v3, 4*34)))
	*(*uint32)(unsafe.Add(v3, 4*1))++
	r10 := (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v2, 7)) + uint32(v9))))
	*(*uint32)(unsafe.Add(v3, 4*34)) = uint32(uintptr(unsafe.Pointer(r10)))
	dword_5d4594_1320932 = nil
	dword_5d4594_1320936 = nil
}
func sub_4C18E0(a1 int32, a2 unsafe.Pointer) bool {
	if *(*uint32)(unsafe.Add(a2, 4*1)) == 0 {
		return true
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(a2))), 108)) != uint32(a1) || *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(a2))), 112))&0x13001000 != 0 {
		return false
	}
	return true
}
func sub_4C1910(a1 int32) unsafe.Pointer {
	var (
		v1 int32
		v3 int32
		v6 int32
		v8 int32
	)
	v1 = 0
	v2 := memmap.PtrOff(0x5D4594, 1319284)
	for {
		v3 = 0
		v4 := v2
		for {
			v5 := *(*unsafe.Pointer)(v4)
			if *(*uint32)(unsafe.Pointer(v4)) != 0 && *(*uint32)(unsafe.Add(v5, 108)) == uint32(a1) && (*(*uint32)(unsafe.Add(v5, 112))&0x13001000) == 0 {
				return memmap.PtrOff(0x5D4594, uintptr((v1+v3*2)*140)+1319284)
			}
			v3++
			v4 = unsafe.Add(v4, 280)
			if v3 >= 2 {
				break
			}
		}
		v2 = unsafe.Add(v2, 140)
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1319564))) {
			break
		}
	}
	v6 = 0
	v7 := memmap.PtrOff(0x5D4594, 1319284)
	for {
		v8 = 0
		v9 := v7
		for {
			if *(*uint32)(unsafe.Pointer(v9)) == 0 {
				return memmap.PtrOff(0x5D4594, uintptr((v6+v8*2)*140)+1319284)
			}
			v8++
			v9 = unsafe.Add(v9, 280)
			if v8 >= 2 {
				break
			}
		}
		v7 = unsafe.Add(v7, 140)
		v6++
		if int32(uintptr(unsafe.Pointer(v7))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1319564))) {
			break
		}
	}
	return nil
}
func sub_4C19C0(a1 int32) unsafe.Pointer {
	var (
		v1 int32
		v3 int32
		v6 int32
		v8 int32
	)
	v1 = 0
	v2 := memmap.PtrOff(0x5D4594, 1320308)
	for {
		v3 = 0
		v4 := v2
		for {
			v5 := *(*unsafe.Pointer)(unsafe.Pointer(v4))
			if *(*uint32)(unsafe.Pointer(v4)) != 0 && *(*uint32)(unsafe.Add(v5, 108)) == uint32(a1) && (*(*uint32)(unsafe.Add(v5, 112))&0x13001000) == 0 {
				return memmap.PtrOff(0x5D4594, uintptr((v1+v3*2)*140)+1320308)
			}
			v3++
			v4 = unsafe.Add(v4, 280)
			if v3 >= 2 {
				break
			}
		}
		v2 = unsafe.Add(v2, 140)
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) < int32(uintptr(memmap.PtrOff(0x5D4594, 1320588))) {
			continue
		}
		break
	}
	v6 = 0
	v7 := memmap.PtrOff(0x5D4594, 1320308)
	for {
		v8 = 0
		v9 := v7
		for {
			if *(*uint32)(unsafe.Pointer(v9)) == 0 {
				return memmap.PtrOff(0x5D4594, uintptr((v6+v8*2)*140)+1320308)
			}
			v8++
			v9 = unsafe.Add(v9, 280)
			if v8 >= 2 {
				break
			}
		}
		v7 = unsafe.Add(v7, 140)
		v6++
		if int32(uintptr(unsafe.Pointer(v7))) < int32(uintptr(memmap.PtrOff(0x5D4594, 1320588))) {
			continue
		}
		break
	}
	return nil
}
func sub_4C1B50(a1 unsafe.Pointer) {
	if dword_5d4594_1320964 == 0 {
		return
	}
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1320240)), internWStr("%d"), *(*uint32)(unsafe.Add(a1, 2)))
	if *(*uint32)(unsafe.Add(a1, 6)) != 0 {
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1320868)), internWStr("(%d)"), *(*uint32)(unsafe.Add(a1, 6)))
	} else {
		nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1320868)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1320984)))
	}
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1320100)), internWStr("%d"), *(*uint32)(unsafe.Add(a1, 10)))
}
func sub_4C1BC0(a1 unsafe.Pointer) {
	if dword_5d4594_1320964 == 0 {
		return
	}
	dword_5d4594_1320944 = uint32(int32(*(*uint8)(unsafe.Add(a1, 2))) & 1)
	v1 := *(*uint8)(unsafe.Add(a1, 2))
	dword_5d4594_1320948 = uint32(v1>>1) & 1
}
func nox_xxx_prepareP2PTrade_4C1BF0() {
	v1 := int32(*memmap.PtrUint32(0x8531A0, 2576))
	if dword_5d4594_1320964 != 0 {
		if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
			sub_4C1410()
			v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3702)
			nox_window_call_field_94_fnc(v2, 16385, uintptr(v1+4704), 0)
			v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1320940, 3703)
			nox_window_call_field_94_fnc(v3, 16385, uintptr(memmap.PtrOff(0x5D4594, 1319844)), 0)
		}
	}
}
func sub_4C1CA0(a1 int32) {
	*memmap.PtrUint32(0x587000, 184448) = uint32(a1)
	if a1 == 3 {
		nox_xxx_wndSetIcon_46AE60(dword_5d4594_1321040, *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1321020))
		sub_46AEC0(dword_5d4594_1321040, *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1321016))
		nox_xxx_wndSetIconLit_46AEA0(dword_5d4594_1321040, *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1321016))
	} else if a1 == 4 {
		nox_xxx_wndSetIcon_46AE60(dword_5d4594_1321040, *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1321028))
		sub_46AEC0(dword_5d4594_1321040, dword_5d4594_1321024)
		nox_xxx_wndSetIconLit_46AEA0(dword_5d4594_1321040, dword_5d4594_1321024)
	} else if a1 == 5 {
		nox_xxx_wndSetIcon_46AE60(dword_5d4594_1321040, *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1321012))
		sub_46AEC0(dword_5d4594_1321040, *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1321008))
		nox_xxx_wndSetIconLit_46AEA0(dword_5d4594_1321040, *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1321008))
	}
}
func nox_xxx_guiDrawSummonBox_4C1FE0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1   = win
		v2   *uint8
		v3   int32
		v4   int32
		v5   int32
		v7   int32
		v8   int32
		v9   int32
		v10  int32
		v11  int32
		v17  int32
		v18  int32
		v19  int8
		v20  int32
		v21  int32
		v22  int32 = 0
		v23  int32 = 0
		a1a  Point32
		v26  int32
		v27  int32
		v28  int32
		v29  int32
		mpos = nox_client_getMousePos_4309F0()
		v24  = mpos
	)
	if int32(*memmap.PtrUint8(0x5D4594, 1321200)) == 1 {
		dword_5d4594_1320992 += 20
		if dword_5d4594_1320992 >= uint32(*memmap.PtrInt32(0x5D4594, 1321004)) {
			dword_5d4594_1320992 = *memmap.PtrUint32(0x5D4594, 1321004)
			*memmap.PtrUint8(0x5D4594, 1321200) = 2
		}
	} else if int32(*memmap.PtrUint8(0x5D4594, 1321200)) == 3 {
		dword_5d4594_1320992 -= 20
		if dword_5d4594_1320992 <= uint32(*memmap.PtrInt32(0x5D4594, 1321000)) {
			dword_5d4594_1320992 = *memmap.PtrUint32(0x5D4594, 1321000)
			*memmap.PtrUint8(0x5D4594, 1321200) = 0
			nox_window_set_hidden(dword_5d4594_1321032, 1)
			nox_window_set_hidden(dword_5d4594_1321040, 1)
		}
	}
	nox_window_setPos_46A9B0(dword_5d4594_1321032, int32(dword_5d4594_1320988), int32(dword_5d4594_1320992))
	nox_window_setPos_46A9B0(dword_5d4594_1321040, int32(dword_5d4594_1320988+27), int32(dword_5d4594_1320992+12))
	nox_client_wndGetPosition_46AA60(a1, &v28, &v29)
	nox_window_get_size(a1, &v21, &v20)
	nox_xxx_guiFontHeightMB_43F320(nil)
	if *memmap.PtrUint32(0x5D4594, 1320996) != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1320996)), int32(dword_5d4594_1320988), int32(dword_5d4594_1320992))
	}
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1321064))
	for {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), -int(4*1))) != 0 {
			switch *(*uint8)(unsafe.Add(unsafe.Pointer(v2), 8)) {
			case 1:
				v22 = 1
				v23 = 1
			case 2:
				v22 = 1
				v23 = 2
			case 4:
				v22 = 2
				v23 = 2
			}
			v3 = int32(uint32(v28) + *(*uint32)(unsafe.Pointer(v2))*38 + 2)
			v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)))
			a1a.X = int32(uint32(v28) + *(*uint32)(unsafe.Pointer(v2))*38 + 2)
			v5 = v29 + v4*38 + 2
			v21 = v22*38 - 4
			v20 = v23*38 - 4
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4)) != 0 {
				nox_client_drawSetColor_434460(int32(nox_color_yellow_2589772))
				v18 = v20
				v17 = v21
				*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4)) = 0
				nox_client_drawRectFilledOpaque_49CE30(v3, v5, v17, v18)
			} else {
				v6 := nox_xxx_guiDrawSummon_4C2440(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), -int(4*2)))))
				if v6 != nil {
					nox_client_drawImageAt_47D2C0(v6, v3, v5)
				} else {
					v7 = v3 + v21/2
					v8 = v5 + v20/2
					nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 956))
					nox_client_drawPoint_4B0BC0(v7, v8, 9)
					nox_video_drawCircleColored_4C3270(v7, v8, 9, *memmap.PtrInt32(0x852978, 4))
					v3 = a1a.X
				}
			}
			if sub_495180(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), -int(4*3)))), (*uint16)(unsafe.Pointer(&v27)), (*uint16)(unsafe.Pointer(&v26)), (*uint8)(unsafe.Pointer(&v19))) != 0 {
				if int32(uint16(int16(v26))) != 0 {
					v9 = v20 * int32(uint16(int16(v27))) / int32(uint16(int16(v26)))
				} else {
					v9 = 0
				}
				if int32(v19) != 0 {
					nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 984))
				} else {
					nox_client_drawSetColor_434460(int32(nox_color_violet_2598268))
				}
				nox_client_drawRectFilledOpaque_49CE30(v21+v3-2, v5, 2, v20)
				if int32(v19) != 0 {
					nox_client_drawSetColor_434460(*memmap.PtrInt32(0x8531A0, 2572))
				} else {
					nox_client_drawSetColor_434460(*memmap.PtrInt32(0x85B3FC, 940))
				}
				nox_client_drawRectFilledOpaque_49CE30(v21+v3-2, v20+v5-v9, 2, v9)
			}
			mpos = v24
		}
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 32))
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321192))) {
			break
		}
	}
	v10 = bool2int32(nox_xxx_wndPointInWnd_46AAB0(dword_5d4594_1321040, mpos.X, mpos.Y))
	if nox_xxx_wndPointInWnd_46AAB0(a1, mpos.X, mpos.Y) || v10 != 0 || *memmap.PtrUint32(0x5D4594, 1321212) == 1 {
		v11 = mpos.Y
		a1a.X = (mpos.X - v28) / 38
		a1a.Y = (v11 - v29) / 38
		v13 := nox_xxx_wndSummonGet_4C2410(&a1a)
		*memmap.PtrUint32(0x5D4594, 1321212) = 0
		v14 := sub_4C2D60()
		if v14 != nil {
			for {
				v15 := nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(*(*int32)(v14)))
				if v15 != nil {
					if v14 == v13 || v10 != 0 {
						v15.ObjFlags |= 0x40000000
						*memmap.PtrUint32(0x5D4594, 1321212) = 1
					} else {
						v15.ObjFlags &= 0xBFFFFFFF
					}
				}
				v14 = sub_4C2D90(v14)
				if v14 == nil {
					break
				}
			}
			mpos = v24
		}
	}
	if dword_5d4594_1321044 != nil && !nox_xxx_wndPointInWnd_46AAB0(dword_5d4594_1321044, mpos.X, mpos.Y) {
		nox_xxx_guiHideSummonWindow_4C2470()
	}
	return 1
}
func nox_xxx_wndSummonGet_4C2410(a1 *Point32) unsafe.Pointer {
	if a1 == nil {
		return nil
	}
	v2 := a1.X
	if !(a1.X >= 0 && v2 < 2) {
		return nil
	}
	v3 := a1.Y
	if v3 >= 0 && v3 < 2 {
		return *memmap.PtrPtr(0x5D4594, uintptr((v3+v2*2)*4)+1321180)
	}
	return nil
}
func nox_xxx_guiDrawSummon_4C2440(a1 int32) noxrender.ImageHandle {
	v1 := nox_get_thing_name(a1)
	if v1 == nil {
		return nil
	}
	v2 := nox_xxx_guide_427010(v1)
	return sub_427430(v2)
}
func nox_xxx_guiHideSummonWindow_4C2470() {
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1321044)
	dword_5d4594_1321044 = nil
	dword_5d4594_1321204 = nil
	nox_xxx_clientPlaySoundSpecial_452D80(920, 100)
	dword_5d4594_1321040.DrawData().Field0 &= 0xFFFFFFFD
}
func sub_4C24A0(win *gui.Window, draw *gui.WindowData) int {
	return 1
}
func nox_xxx_wndSummonBigButtonProc_4C24B0(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	var a1a Point32
	switch a2 {
	case 5, 6:
		return 1
	case 7:
		dword_5d4594_1321204 = nil
		a1a.Y = int32(a3 >> 16)
		a1a.X = int32(uint16(a3))
		nox_xxx_wndSummonCreateList_4C2560(&a1a)
		dword_5d4594_1321040.DrawData().Field0 |= 2
		return 1
	case 17:
		dword_5d4594_1321040.DrawData().Field0 |= 2
		return 0
	case 18:
		dword_5d4594_1321040.DrawData().Field0 &= 0xFFFFFFFD
		return 0
	default:
		return 0
	}
}
func sub_4C2A00(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int16) int32 {
	var v5 *uint8
	nox_xxx_drawSetTextColor_434390(a4)
	v5 = (*uint8)(memmap.PtrOff(0x587000, 184520))
	for {
		nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer(a5)), int32(uint32(a1)+*(*uint32)(unsafe.Pointer(v5))), int32(uint32(a2)+*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1))))
		v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 8))
		if int32(uintptr(unsafe.Pointer(v5))) >= int32(uintptr(memmap.PtrOff(0x587000, 184552))) {
			break
		}
	}
	nox_xxx_drawSetTextColor_434390(a3)
	return nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer(a5)), a1, a2)
}
func nox_client_orderCreature(creature unsafe.Pointer, command int32) {
	var buf [4]uint8
	buf[0] = 0x78
	if creature != nil {
		*(*uint16)(unsafe.Pointer(&buf[1])) = *(*uint16)(creature)
	} else {
		if command == 1 {
			return
		}
		*(*uint16)(unsafe.Pointer(&buf[1])) = 0
	}
	buf[3] = uint8(int8(command))
	nox_netlist_addToMsgListCli_40EBC0(31, 0, &buf[0], 4)
	nox_xxx_guiHideSummonWindow_4C2470()
	if command == 0 {
		nox_xxx_clientPlaySoundSpecial_452D80(777, 100)
	} else {
		nox_xxx_clientPlaySoundSpecial_452D80(898, 100)
	}
}
func nox_xxx_clientOrderCreature_4C2A60(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	a1 := win
	if a2 < 5 {
		return 0
	}
	if a2 <= 6 {
		return 1
	}
	if a2 == 7 {
		*(*uint8)(unsafe.Pointer(&a2)) = 120
		result := int32(uintptr(a1.WidgetData))
		if result == 2 || dword_5d4594_1321204 == nil && result == 1 {
			return 1
		}
		nox_client_orderCreature(dword_5d4594_1321204, result)
		return 1
	}
	return 0
}
func nox_xxx_wndSummonProc_4C2B10(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	var (
		a1  = win
		v5  Point32
		a1a Point32
	)
	if a2 < 5 {
		return 0
	}
	if a2 <= 6 {
		return 1
	}
	if a2 == 7 {
		v5.Y = int32(a3 >> 16)
		v5.X = int32(uint16(a3))
		var x, y int32
		nox_client_wndGetPosition_46AA60(a1, &x, &y)
		a1a.X = (v5.X - int32(x)) / 38
		a1a.Y = (v5.Y - int32(y)) / 38
		dword_5d4594_1321204 = nox_xxx_wndSummonGet_4C2410(&a1a)
		if dword_5d4594_1321204 != nil {
			nox_xxx_wndSummonCreateList_4C2560(&v5)
		}
		return 1
	}
	return 0
}
func sub_4C2BD0(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	return 0
}
func sub_4C2BE0(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	return 1
}
func sub_4C2BF0() *int32 {
	var (
		v0     *int32
		result *int32
		v2     int32
	)
	v0 = memmap.PtrInt32(0x5D4594, 1321180)
	for {
		result = v0
		v2 = 2
		for {
			*result = 0
			result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*2))
			v2--
			if v2 == 0 {
				break
			}
		}
		v0 = (*int32)(unsafe.Add(unsafe.Pointer(v0), 4*1))
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321188))) {
			break
		}
	}
	return result
}
func sub_4C2C20(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	a1 := win
	var a2a Point32
	a2a.Y = int32(a3 >> 16)
	a2a.X = int32(uint16(a3))
	v3 := sub_4C2C60(a1, &a2a)
	nox_xxx_cursorSetTooltip_4776B0(v3)
	return 1
}
func sub_4C2C60(a1p *gui.Window, a2 *Point32) *wchar2_t {
	var (
		a1, v6 int32
		a1a    Point32
	)
	nox_client_wndGetPosition_46AA60(a1p, &a1, &v6)
	a1a.X = (a2.X - a1) / 38
	a1a.Y = (a2.Y - v6) / 38
	v4 := nox_xxx_wndSummonGet_4C2410(&a1a)
	if v4 != nil {
		return nox_get_thing_pretty_name(int32(*(*uint32)(unsafe.Add(v4, 4))))
	}
	return nil
}
func sub_4C2D60() unsafe.Pointer {
	var (
		v0 int32
		v1 *uint8
	)
	v0 = 0
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1321060))
	for *(*uint32)(unsafe.Pointer(v1)) == 0 {
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 32))
		v0++
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321188))) {
			return nil
		}
	}
	return memmap.PtrOff(0x5D4594, uintptr(v0*32)+1321052)
}
func sub_4C2D90(a1 unsafe.Pointer) unsafe.Pointer {
	var (
		v1 int32
		v2 *uint8
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 24)) + 1)
	if v1 >= 4 {
		return nil
	}
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v1*32)+1321060))
	for *(*uint32)(unsafe.Pointer(v2)) == 0 {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 32))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321188))) {
			return nil
		}
	}
	return memmap.PtrOff(0x5D4594, uintptr(v1*32)+1321052)
}
func sub_4C2DD0(a1 unsafe.Pointer) int32 {
	v1 := int32(dword_5d4594_1321208)
	if dword_5d4594_1321208 == 0 {
		v1 = nox_xxx_getNameId_4E3AA0(internCStr("CarnivorousPlant"))
		dword_5d4594_1321208 = uint32(v1)
	}
	return bool2int32(*(*uint32)(unsafe.Add(a1, 4)) != uint32(v1))
}
func sub_4C2E00() int32 {
	if dword_5d4594_1321208 == 0 {
		dword_5d4594_1321208 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("CarnivorousPlant")))
	}
	v0 := sub_4C2D60()
	if v0 == nil {
		return 0
	}
	for sub_4C2DD0(v0) == 0 {
		v0 = sub_4C2D90(v0)
		if v0 == nil {
			return 0
		}
	}
	return 1
}
func nox_xxx_cliSummonCreat_4C2E50(a1 int32, a2 int32, a3 int32) int8 {
	var v3 *byte
	v3 = (*byte)(sub_4C2D60())
	if v3 != nil {
		for *(*uint32)(unsafe.Pointer(v3)) != uint32(a1) || *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) != uint32(a2) {
			v3 = (*byte)(sub_4C2D90(unsafe.Pointer(v3)))
			if v3 == nil {
				goto LABEL_5
			}
		}
		return int8(uintptr(unsafe.Pointer(v3)))
	}
LABEL_5:
	v3 = sub_4C2F20()
	if v3 == nil {
		return int8(uintptr(unsafe.Pointer(v3)))
	}
	*(*uint32)(unsafe.Pointer(v3)) = uint32(a1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = uint32(a2)
	*(*byte)(unsafe.Add(unsafe.Pointer(v3), 20)) = byte(int8(sub_4C2EF0(a2)))
	sub_4C2F70()
	*(*uint8)(unsafe.Pointer(&v3)) = *memmap.PtrUint8(0x5D4594, 1321200)
	if int32(*memmap.PtrUint8(0x5D4594, 1321200)) == 0 || int32(*memmap.PtrUint8(0x5D4594, 1321200)) == 3 {
		if a3 == 0 {
			nox_xxx_clientPlaySoundSpecial_452D80(801, 100)
		}
		*memmap.PtrUint8(0x5D4594, 1321200) = 1
		nox_window_set_hidden(dword_5d4594_1321032, 0)
		*(*uint8)(unsafe.Pointer(&v3)) = uint8(int8(nox_window_set_hidden(dword_5d4594_1321040, 0)))
	}
	dword_5d4594_1321196++
	return int8(uintptr(unsafe.Pointer(v3)))
}
func sub_4C2EF0(a1 int32) int32 {
	var (
		v1 int32
		v3 int32
	)
	v1 = int32(nox_get_thing(a1).ObjSubClass)
	if v1&1 != 0 {
		return 1
	}
	v3 = -bool2int32((v1 & 2) != 0)
	*(*uint8)(unsafe.Pointer(&v3)) = uint8(int8(v3 & 0xFE))
	return v3 + 4
}
func sub_4C2F20() *byte {
	var (
		v0     int32
		v1     *uint8
		result *byte
	)
	v0 = 0
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1321060))
	for *(*uint32)(unsafe.Pointer(v1)) != 0 {
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 32))
		v0++
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321188))) {
			return nil
		}
	}
	libc.MemSet(memmap.PtrOff(0x5D4594, uintptr(v0*32)+1321052), 0, 0x20)
	*memmap.PtrUint32(0x5D4594, uintptr(v0*32)+1321060) = 1
	result = (*byte)(memmap.PtrOff(0x5D4594, uintptr(v0*32)+1321052))
	*memmap.PtrUint32(0x5D4594, uintptr(v0*32)+1321076) = uint32(v0)
	return result
}
func sub_4C2F70() {
	var (
		i int32
		j *byte
	)
	sub_4C2BF0()
	for i = 1; ; i = 4 {
		for {
			result := sub_4C2D60()
			for j = (*byte)(result); result != nil; j = (*byte)(result) {
				if int32(*(*byte)(unsafe.Add(unsafe.Pointer(j), 20))) == i {
					sub_4C2FD0(unsafe.Pointer(j))
				}
				result = sub_4C2D90(unsafe.Pointer(j))
			}
			if i != 1 {
				break
			}
			i = 2
		}
		if i != 2 {
			break
		}
	}
}
func sub_4C2FD0(a1 unsafe.Pointer) int32 {
	var (
		v1     int32
		v2     *int32
		v3     int32
		result int32
	)
	v1 = 0
	v2 = (*int32)(unsafe.Add(a1, 12))
	for {
		v3 = int32(*(*uint8)(unsafe.Add(a1, 20)))
		*v2 = int32(*memmap.PtrUint32(0x587000, uintptr(v1*8)+184456))
		*(*uint32)(unsafe.Add(a1, 16)) = *memmap.PtrUint32(0x587000, uintptr(v1*8)+184460)
		if sub_4C30C0(v2, v3) != 0 {
			break
		}
		result = int32(*(*uint8)(unsafe.Add(a1, 20)))
		v1 += result
		if v1 >= 4 {
			return result
		}
	}
	return sub_4C3030((*int32)(unsafe.Add(a1, 12)), int32(*(*uint8)(unsafe.Add(a1, 20))), a1)
}
func sub_4C3030(a1 *int32, a2 int32, a3 unsafe.Pointer) int32 {
	var (
		v3     int32
		result int32
		v5     int32
		v6     int32
		v7     *uint8
	)
	if a2 == 1 {
		v3 = 1
		a2 = 1
	} else if a2 == 2 {
		v3 = 1
		a2 = 2
	} else {
		v3 = 2
		if a2 == 4 {
			a2 = 2
		} else {
			v3 = a2
		}
	}
	result = a2
	v5 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	if v5 >= v5+a2 {
		return result
	}
	for {
		v6 = *a1
		if *a1 < *a1+v3 {
			v7 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr((v5+v6*2)*4)+1321180))
			for {
				*(*unsafe.Pointer)(unsafe.Pointer(v7)) = a3
				v6++
				v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 8))
				if v6 >= v3+*a1 {
					break
				}
			}
		}
		v5++
		result = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) + a2
		if v5 >= result {
			break
		}
	}
	return result
}
func sub_4C30C0(a1 *int32, a2 int32) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 int32
		v8 int32
		v9 *uint8
	)
	switch a2 {
	case 1:
		v2 = 1
		v3 = 1
	case 2:
		v2 = 1
		v3 = 2
	case 4:
		v2 = 2
		v3 = 2
	default:
		v2 = a2
		v3 = a2
	}
	v4 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	v5 = v4 + v3
	if v4 >= v4+v3 {
		return 1
	}
	v6 = *a1
	v7 = *a1 + v2
	for {
		v8 = *a1
		if v6 < v7 {
			v9 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr((v4+v6*2)*4)+1321180))
			for *(*uint32)(unsafe.Pointer(v9)) == 0 {
				v8++
				v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 8))
				if v8 >= v7 {
					goto LABEL_14
				}
			}
			return 0
		}
	LABEL_14:
		if func() int32 {
			p := &v4
			*p++
			return *p
		}() >= v5 {
			return 1
		}
	}
}
func nox_xxx_cliSummonOnDieOrBanish_4C3140(a1 int32, a2 unsafe.Pointer) {
	var (
		v4 *uint32
	)
	result := sub_4C31D0(a1)
	v3 := result
	if result == nil {
		return
	}
	if result == dword_5d4594_1321204 {
		nox_xxx_guiHideSummonWindow_4C2470()
	}
	v4 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(a1)).C())
	if v4 != nil {
		*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*30)) &= 0xBFFFFFFF
	}
	sub_4C3030((*int32)(unsafe.Add(v3, 4*3)), int32(*(*uint8)(unsafe.Add(v3, 20))), nil)
	sub_4C3210(v3)
	sub_4C2F70()
	dword_5d4594_1321196--
	if dword_5d4594_1321196 == 0 {
		if a2 == nil {
			nox_xxx_clientPlaySoundSpecial_452D80(802, 100)
		}
		*memmap.PtrUint8(0x5D4594, 1321200) = 3
	}
}
func sub_4C31D0(a1 int32) unsafe.Pointer {
	var (
		v1 int32
		v2 *uint8
	)
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 1321052))
	for *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) == 0 || *(*uint32)(unsafe.Pointer(v2)) != uint32(a1) {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 32))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1321180))) {
			return nil
		}
	}
	return memmap.PtrOff(0x5D4594, uintptr(v1*32)+1321052)
}
func sub_4C3210(a1 unsafe.Pointer) {
	*(*uint32)(unsafe.Add(a1, 8)) = 0
}
func nox_xxx_sprite_4C3220(a1 *client.Drawable) int32 {
	return bool2int32(sub_4C31D0(int32(a1.NetCode32)) != nil)
}
func sub_4C3260() int32 {
	return bool2int32(sub_4C2D60() != nil)
}
func nox_xxx_spriteDrawCircleMB_4C32A0(a1 int32, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4 *uint8
		v5 int32
		v6 int32
		v8 int32
		v9 int32
	)
	v8 = int32((uint32(a3) * *memmap.PtrUint32(0x587000, 192088)) >> 4)
	v9 = int32((uint32(a3) * *memmap.PtrUint32(0x587000, 192092)) >> 4)
	nox_client_drawSetColor_434460(a4)
	nox_client_drawEnableAlpha_434560(1)
	v4 = (*uint8)(memmap.PtrOff(0x587000, 192220))
	for {
		v5 = int32((uint32(a3) * *(*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*1)))) >> 4)
		v6 = int32((*(*uint32)(unsafe.Pointer(v4)) * uint32(a3)) >> 4)
		nox_client_drawAddPoint_49F500(a1+v8, a2+v9)
		nox_client_drawAddPoint_49F500(v5+a1, v6+a2)
		nox_client_drawLineFromPoints_49E4B0()
		v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 128))
		v8 = v5
		v9 = v6
		if int32(uintptr(unsafe.Pointer(v4))) >= int32(uintptr(memmap.PtrOff(0x587000, 194140))) {
			break
		}
	}
	nox_client_drawAddPoint_49F500(int32(uint32(a1)+((uint32(a3)**memmap.PtrUint32(0x587000, 192088))>>4)), int32(uint32(a2)+((uint32(a3)**memmap.PtrUint32(0x587000, 192092))>>4)))
	nox_client_drawAddPoint_49F500(a1+v5, a2+v6)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawEnableAlpha_434560(0)
	return 1
}
func sub_4C3390() int32 {
	*memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1321220) = nox_xxx_gLoadImg_42F970(internCStr("VoteInProgress"))
	dword_5d4594_1321216 = nox_window_new(nil, 136, int(nox_win_width)-50, int(nox_win_height)/2-100, 50, 50, nil)
	nox_xxx_wndSetIcon_46AE60(dword_5d4594_1321216, *memmap.PtrT[noxrender.ImageHandle](0x5D4594, 1321220))
	nox_window_set_all_funcs(dword_5d4594_1321216, nil, sub_4C3410, nil)
	nox_window_set_hidden(dword_5d4594_1321216, 1)
	return 1
}
func sub_4C3410(win *gui.Window, draw *gui.WindowData) int {
	v1 := win
	var a1, v4 int32
	nox_client_wndGetPosition_46AA60(win, &a1, &v4)
	v2 := v1.DrawData().ImgPtVal.Y
	a1 += int32(v1.DrawData().ImgPtVal.X)
	nox_client_drawImageAt_47D2C0(v1.DrawData().BgImageHnd, a1, int32(v2+int(v4)))
	return 1
}
func sub_4C3460(a1 int32) int32 {
	return nox_window_set_hidden(dword_5d4594_1321216, a1)
}
func sub_4C34A0() {
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1321216)
	dword_5d4594_1321216 = nil
}
func sub_4C3500() *gui.Window {
	v0 := nox_new_window_from_file(internCStr("yesno.wnd"), nil)
	dword_5d4594_1321224 = v0
	if v0 != nil {
		nox_window_setPos_46A9B0(v0, (nox_win_width-320)/2, (nox_win_height-240)/2)
		v0 = dword_5d4594_1321224
	}
	nox_window_set_hidden(v0, 1)
	return dword_5d4594_1321224
}
func sub_4C35B0(a1 int32) int32 {
	if wndIsShown_nox_xxx_wndIsShown_46ACC0(dword_5d4594_1321228) != 0 {
		return 0
	}
	sub_413A00(0)
	if a1 != 0 {
		nox_window_set_hidden(dword_5d4594_1321228, 1)
	} else {
		sub_4C3620()
		nox_common_writecfgfile(internCStr("nox.cfg"))
		nox_window_set_hidden(dword_5d4594_1321228, 1)
		sub_472280()
		sub_4ADA40()
	}
	return 1
}
func sub_4C3A60(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	if p2 < 0x13 || p2 > 0x14 {
		return nox_xxx_wndListboxProcWithoutData10_4A28E0(win, p2, p3, p4)
	} else {
		return 0
	}
}
func sub_4C3EB0(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	switch a2 {
	case 6, 7:
		sub_4C4100(0x10000)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0(dword_5d4594_1321232)
		nox_window_set_hidden(dword_5d4594_1321232, 1)
		return 1
	case 10, 11:
		sub_4C4100(0x10002)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0(dword_5d4594_1321232)
		nox_window_set_hidden(dword_5d4594_1321232, 1)
		return 1
	case 14, 15:
		sub_4C4100(0x10001)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0(dword_5d4594_1321232)
		nox_window_set_hidden(dword_5d4594_1321232, 1)
		return 1
	case 19:
		sub_4C4100(0x10003)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0(dword_5d4594_1321232)
		nox_window_set_hidden(dword_5d4594_1321232, 1)
		return 1
	case 20:
		sub_4C4100(0x10004)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0(dword_5d4594_1321232)
		nox_window_set_hidden(dword_5d4594_1321232, 1)
		return 1
	case 21:
		if a3 == 1 {
			if a4 != 2 {
				return 1
			}
			nox_xxx_windowFocus_46B500(nil)
			nox_xxx_wnd_46C6E0(dword_5d4594_1321232)
			nox_window_set_hidden(dword_5d4594_1321232, 1)
			if dword_5d4594_1321252 != nil {
				nox_window_call_field_94_fnc(dword_5d4594_1321252, 16403, math.MaxUint32, 0)
			}
			return 1
		} else if a4 == 1 && sub_4C3FC0(uint32(a3)) != 0 {
			sub_4C4100(0x10000)
			nox_xxx_windowFocus_46B500(nil)
			nox_xxx_wnd_46C6E0(dword_5d4594_1321232)
			nox_window_set_hidden(dword_5d4594_1321232, 1)
			return 1
		} else {
			return 0
		}
	default:
		return 0
	}
}
func sub_4C3FC0(a1 uint32) int32 {
	var v6 *wchar2_t = nox_xxx_keybind_titleByKeyZero_42EA00(a1)
	if v6 == nil {
		return 0
	}
	if dword_5d4594_1321252 == nil {
		return 1
	}
	var v7 int32 = 0
	v8 := dword_5d4594_1321244.WidgetData
	if int32(*(*uint16)(unsafe.Add(v8, 44))) > 0 {
		for {
			{
				var v9 *wchar2_t = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1321244, 16406, uintptr(v7), 0)))
				if nox_wcscmp(v9, v6) == 0 {
					nox_window_call_field_94_fnc(dword_5d4594_1321244, 16407, uintptr(memmap.PtrOff(0x587000, 185444)), uintptr(v7))
				}
				v7++
			}
			if v7 >= int32(*(*int16)(unsafe.Add(v8, 44))) {
				break
			}
		}
	}
	var v10 int32 = 0
	v11 := dword_5d4594_1321248.WidgetData
	if int32(*(*uint16)(unsafe.Add(v11, 44))) > 0 {
		for {
			{
				var v12 *wchar2_t = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1321248, 16406, uintptr(v10), 0)))
				if nox_wcscmp(v12, v6) == 0 {
					nox_window_call_field_94_fnc(dword_5d4594_1321248, 16407, uintptr(memmap.PtrOff(0x587000, 185448)), uintptr(v10))
				}
				v10++
			}
			if v10 >= int32(*(*int16)(unsafe.Add(v11, 44))) {
				break
			}
		}
	}
	nox_window_call_field_94_fnc(dword_5d4594_1321252, 16407, uintptr(unsafe.Pointer(v6)), uintptr(*(*uint32)(unsafe.Add(dword_5d4594_1321252.WidgetData, 48))))
	nox_window_call_field_94_fnc(dword_5d4594_1321252, 16403, math.MaxUint32, 0)
	dword_5d4594_1321252 = nil
	return 1
}
func sub_4C4100(a1 uint32) int32 {
	var (
		v1 *byte
		v2 int32
		v4 *wchar2_t
		v5 int32
		v7 *wchar2_t
	)
	v1 = (*byte)(unsafe.Pointer(nox_xxx_keybind_titleByKey_42EA00(a1)))
	if dword_5d4594_1321252 == nil {
		return 1
	}
	v2 = 0
	v3 := dword_5d4594_1321244.WidgetData
	if int32(*(*uint16)(unsafe.Add(v3, 44))) > 0 {
		for {
			v4 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1321244, 16406, uintptr(v2), 0)))
			if nox_wcscmp(v4, (*wchar2_t)(unsafe.Pointer(v1))) == 0 {
				nox_window_call_field_94_fnc(dword_5d4594_1321244, 16407, uintptr(memmap.PtrOff(0x587000, 185452)), uintptr(v2))
			}
			v2++
			if v2 >= int32(*(*int16)(unsafe.Add(v3, 44))) {
				break
			}
		}
	}
	v5 = 0
	v6 := dword_5d4594_1321248.WidgetData
	if int32(*(*uint16)(unsafe.Add(v6, 44))) > 0 {
		for {
			v7 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1321248, 16406, uintptr(v5), 0)))
			if nox_wcscmp(v7, (*wchar2_t)(unsafe.Pointer(v1))) == 0 {
				nox_window_call_field_94_fnc(dword_5d4594_1321248, 16407, uintptr(memmap.PtrOff(0x587000, 185456)), uintptr(v5))
			}
			v5++
			if v5 >= int32(*(*int16)(unsafe.Add(v6, 44))) {
				break
			}
		}
	}
	nox_window_call_field_94_fnc(dword_5d4594_1321252, 16407, uintptr(unsafe.Pointer(v1)), uintptr(*(*uint32)(unsafe.Add(dword_5d4594_1321252.WidgetData, 48))))
	nox_window_call_field_94_fnc(dword_5d4594_1321252, 16403, math.MaxUint32, 0)
	dword_5d4594_1321252 = nil
	return 1
}
func Sub_4C4220() {
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1321228)
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1321232)
	dword_5d4594_1321228 = nil
	dword_5d4594_1321232 = nil
	dword_5d4594_1321236 = nil
	dword_5d4594_1321240 = nil
	dword_5d4594_1321244 = nil
	dword_5d4594_1321248 = nil
}
func sub_4C4260() {
	sub_4C3B70()
	nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1321228)
	sub_413A00(1)
}
func sub_4C4280() int32 {
	return bool2int32(wndIsShown_nox_xxx_wndIsShown_46ACC0(dword_5d4594_1321228) == 0)
}
func nox_xxx_drawObject_4C4770_draw(a1 *noxrender.Viewport, dr *client.Drawable, a3 noxrender.ImageHandle) {
	var (
		a2   = dr
		v4   *byte
		v7   int32
		v8   int32
		v9   int32
		v10  int32
		v11  int32
		v12  int32
		v13  int32
		v14  int32
		v15  int32
		v16  int32
		v17  int32
		v18  uint8
		v19  uint8
		v20  int32
		v21  int32
		v22  int32
		v23  int32
		v24  int32
		v25  int32
		v26  int32
		v27  int32
		v28  *uint8
		v29  int16
		v30  int32
		v31  int32
		v32  int32
		v33  int32
		v34  int32
		v35  int32
		v36  float64
		v37  float64
		v38  uint8
		v39  uint8
		v40  int32
		v41  int32
		v42  int32
		v43  int32
		v44  int32
		v45  int32
		v46  *client.Drawable
		v47  int32
		v48  int32
		v49  int32
		v50  int32
		v53  int32
		v54  int32
		a1a  Point32
		a2a  Point32
		a4   int32
		a3a  int32
		v59a int32
		v59b int32
		v60  int64
		v61  uint8
		v62  uint8
		v63  uint8
		v64  uint8
	)
	v53 = 0
	v54 = 0
	if dword_5d4594_1321520 == 0 {
		dword_5d4594_1321520 = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Ghost")))
	}
	v3 := a2
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 112)))&4 != 0 {
		v4 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(a2.NetCode32))))
		if nox_player_netCode_85319C == a2.NetCode32 {
			if v4 != nil && *(*byte)(unsafe.Add(unsafe.Pointer(v4), 3680))&1 != 0 {
				v54 = 1
			}
		} else if v4 != nil && *(*byte)(unsafe.Add(unsafe.Pointer(v4), 3680))&1 != 0 {
			return
		}
		v5 := nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
		if v5 != nil {
			v6 := nox_xxx_objGetTeamByNetCode_418C80(a2.NetCode32)
			if v6 != nil {
				if nox_player_netCode_85319C == a2.NetCode32 || nox_xxx_servCompareTeams_419150(v5, v6) != 0 {
					v53 = 1
				}
			}
		}
	}
	v7 = int32(a2.PosVec.X)
	a3a = 0
	v8 = int32(a1.Screen.Min.X)
	v9 = v7 - int32(a1.World.Min.X)
	v10 = int32(a1.Screen.Min.Y)
	v11 = int32(a2.ZVal2)
	v59a = v9 + int32(a1.Screen.Min.X) - int32(a2.Field_0)
	v12 = int32(a2.PosVec.Y)
	v13 = int32(a2.PosVec.Y - int(uint32(v11)) - int(uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 1)))) - int(uint32(a2.ZVal)))
	v14 = int32(a1.World.Min.Y)
	v59b = v10 + v13 - v14
	a4 = nox_win_width
	if *memmap.PtrUint32(0x587000, 80808) != 0 {
		v15 = int32(a2.ObjFlags)
		if (uint32(v15)&0x40000000) == 0 && (v15&1) == 0 && (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 112)))&0x80) != 0 {
			v16 = v9 + v8
			a1a.X = v16
			v17 = v10 + v12 - v14
			v18 = a2.Field_74_4
			v19 = a2.Field_74_4
			a1a.Y = v17
			v20 = int32(v19) * 8
			v21 = v16 + *memmap.PtrInt32(0x587000, uintptr(v20)+196184)
			v22 = v17 + *memmap.PtrInt32(0x587000, uintptr(v20)+196188)
			a2a.X = v21
			a2a.Y = v22
			if int32(v18) < 0x18 && int32(v18) != 0 && (int32(v18) < 8 || int32(v18) > 0x10) {
				v23 = (v21 + v16) >> 1
				v24 = (v22 + v17) >> 1
				if sub_4C5630(v23-5, v23-5, v24) != 0 {
					a1a.X -= 2
					a2a.X -= 2
				} else if sub_4C5630(v23+5, v23+5, v24) != 0 {
					a1a.X += 2
					a2a.X += 2
				}
			} else {
				v25 = (v22 + v17) >> 1
				v26 = (v21 + v16) >> 1
				if sub_4C5630(v26, v26, v25-5) != 0 {
					v27 = a2a.Y - 2
					a1a.Y -= 2
					a2a.Y = v27
				} else if sub_4C5630(v26, v26, v25+5) != 0 {
					v27 = a2a.Y + 2
					a1a.Y += 2
					a2a.Y = v27
				}
			}
			if sub_4C42A0(&a1a, &a2a, &a3a, &a4) == 0 {
				return
			}
		}
	}
	if (a2.ObjClass&0x80000) != 0 && (a2.ObjFlags&0x1000000) != 0 || (a2.ObjFlags&0x40000000) != 0 {
		v28 = (*uint8)(memmap.PtrOff(0x587000, 185472))
	} else {
		v28 = (*uint8)(sub_469920((*Point32)(unsafe.Add(unsafe.Pointer(a2), 12))))
	}
	v29 = int16(a2.ZVal)
	var a2b int32 = 0
	if int32(v29) >= 0 {
		v30 = 0
	} else {
		if *memmap.PtrInt32(0x5D4594, 1321512) < 0 && a2 == *(**client.Drawable)(memmap.PtrOff(0x5D4594, 1321516)) {
			a2b = 1
		}
		v30 = int32(-v29)
	}
	*memmap.PtrPtr(0x5D4594, 1321516) = unsafe.Pointer(a2)
	v31 = int32(a2.ZVal)
	a1a.X = v30
	*memmap.PtrUint32(0x5D4594, 1321512) = uint32(v31)
	if nox_client_drawable_testBuff_4356C0(a2, 25) {
		nox_xxx_draw_434600(1)
		nox_draw_setColorMultAndIntensity_433E40(int32(nox_color_blue_2650684))
	} else if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 112)))&2) != 0 && (func() uint32 {
		v32 = int32(a2.ObjFlags)
		return uint32(v32) & 0x40000000
	}()) != 0 && (v32&0x8020) == 0 {
		nox_xxx_draw_434600(1)
		nox_draw_setColorMultAndIntensity_433E40(int32(nox_color_blue_2650684))
	} else {
		sub_4345F0(1)
		*(*uint8)(unsafe.Pointer(&v34)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v28), 8))
		v33 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v28), 4)))
		*(*uint8)(unsafe.Pointer(&v35)) = *v28
		nox_draw_setColorMultAndIntensityRGB_433CD0(uint8(int8(v35)), uint8(int8(v33)), uint8(int8(v34)))
	}
	if a2.Field_120 != 0 {
		v60 = int64(gameFrame() - a2.Field_85)
		v36 = float64(v60)
		v60 = int64(gameFPS())
		v37 = 1.0 - v36/float64(int32(gameFPS()))
		if v37 < 0.0 {
			v37 = 0.001
		}
		v38 = uint8(int8(int64(v37 * 255.0)))
		v63 = uint8(int8(int64(v37 * 255.0)))
		if v3.TypeIDVal == dword_5d4594_1321520 {
			v39 = uint8(sub_4C4EC0((*uint32)(unsafe.Pointer(a1)), unsafe.Pointer(v3)))
			if int32(v39) < int32(v38) {
				v64 = v39
				nox_client_drawEnableAlpha_434560(1)
				nox_client_drawSetAlpha_434580(v64)
			} else {
				nox_client_drawEnableAlpha_434560(1)
				nox_client_drawSetAlpha_434580(v63)
			}
		} else {
			if v3.ObjFlags&0x4000000 != 0 {
				v63 = uint8(int8(int32(v38) >> 1))
			}
			nox_client_drawEnableAlpha_434560(1)
			nox_client_drawSetAlpha_434580(v63)
		}
	} else if a2.TypeIDVal == dword_5d4594_1321520 {
		v61 = uint8(sub_4C4EC0((*uint32)(unsafe.Pointer(a1)), unsafe.Pointer(a2)))
		nox_client_drawEnableAlpha_434560(1)
		nox_client_drawSetAlpha_434580(v61)
	} else if a2.ObjFlags&0x4000000 != 0 {
		nox_client_drawEnableAlpha_434560(1)
		nox_client_drawSetAlpha_434580(0x80)
	}
	if nox_client_drawable_testBuff_4356C0(v3, 0) || v54 != 0 || v3.TypeIDVal == dword_5d4594_1321520 && *memmap.PtrUint32(0x852978, 8) != 0 && nox_client_drawable_testBuff_4356C0((*client.Drawable)(*memmap.PtrPtr(0x852978, 8)), 21) {
		if *memmap.PtrUint32(0x8531A0, 2576) != 0 && (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 3680)))&1) != 0 {
			nox_client_drawEnableAlpha_434560(1)
			nox_client_drawSetAlpha_434580(0x80)
		} else {
			v40 = int32(v3.Field_8)
			v41 = int32(v3.Field_9)
			v42 = int32(v3.PosVec.X - int(uint32(v40)))
			v43 = int32(v3.PosVec.Y - int(uint32(v41)))
			v44 = int32(v3.PosVec.X - int(uint32(v40)))
			if v42 < 0 {
				v44 = int32(int(v40) - v3.PosVec.X)
			}
			if v44 < 4 {
				v45 = int32(v3.PosVec.Y - int(uint32(v41)))
				if v43 < 0 {
					v45 = int32(int(v41) - v3.PosVec.Y)
				}
				if v45 < 4 {
					v46 = *memmap.PtrT[*client.Drawable](0x852978, 8)
					if *memmap.PtrUint32(0x852978, 8) == 0 {
						goto LABEL_82
					}
					if !nox_client_drawable_testBuff_4356C0((*client.Drawable)(*memmap.PtrPtr(0x852978, 8)), 21) {
						*(*uint16)(unsafe.Add(unsafe.Pointer(&v4), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v53))
						if v53 == 0 {
							return
						}
					}
				}
			}
			v46 = *memmap.PtrT[*client.Drawable](0x852978, 8)
		LABEL_82:
			if v42 != 0 || v43 != 0 {
				v47 = int32(v3.Field_5 - v3.Field_10)
				if v47 == 0 {
					v47 = 1
				}
				v48 = int32(math.Sqrt(float64(v42*v42+v43*v43))) / v47
				v30 = a1a.X
				v42 = v48
				v46 = *memmap.PtrT[*client.Drawable](0x852978, 8)
			}
			if v46 == nil {
				goto LABEL_123
			}
			if v54 != 0 {
				*(*uint8)(unsafe.Pointer(&v49)) = 128
				v62 = uint8(int8(v49))
				goto LABEL_B
			}
			if v53 == 0 && nox_client_drawable_testBuff_4356C0(v46, 21) {
				nox_xxx_draw_434600(1)
				nox_draw_setColorMultAndIntensity_433E40(*memmap.PtrInt32(0x8531A0, 2572))
				v62 = math.MaxUint8
				nox_client_drawEnableAlpha_434560(1)
				nox_client_drawSetAlpha_434580(v62)
				goto LABEL_A
			}
		LABEL_123:
			if v42 < 8 {
				v49 = (v42 << 7) / 8
				v62 = uint8(int8(v49))
				if int32(uint8(int8(v49))) == 0 {
					*(*uint8)(unsafe.Pointer(&v49)) = 1
					v62 = uint8(int8(v49))
				}
			} else {
				*(*uint8)(unsafe.Pointer(&v49)) = 128
				v62 = uint8(int8(v49))
			}
		LABEL_B:
			if v53 != 0 && int32(uint8(int8(v49))) <= 1 {
				if (func() int32 {
					v50 = int32(v3.ObjClass)
					return v50 & 2
				}()) != 0 && v3.AnimInd == 8 || (v50&4) != 0 && v3.AnimInd == 0 {
					nox_xxx_draw_434600(1)
					nox_draw_setColorMultAndIntensity_433E40(*memmap.PtrInt32(0x8531A0, 2572))
					v62 = 128
				}
			}
			nox_client_drawEnableAlpha_434560(1)
			nox_client_drawSetAlpha_434580(v62)
		}
	}
LABEL_A:
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 112)))&4) == 0 && nox_client_drawable_testBuff_4356C0(v3, 23) && !noxflags.HasGame(2048) {
		nox_xxx_draw_434600(1)
		if int32(uint8(gameFrame()))&1 != 0 {
			nox_draw_setColorMultAndIntensity_433E40(int32(nox_color_white_2523948))
		} else {
			nox_draw_setColorMultAndIntensity_433E40(int32(nox_color_blue_2650684))
		}
	}
	if !nox_client_drawable_testBuff_4356C0(v3, 23) && nox_client_drawable_testBuff_4356C0(v3, 11) {
		nox_xxx_draw_434600(1)
		nox_draw_setColorMultAndIntensity_433E40(*memmap.PtrInt32(0x85B3FC, 956))
	}
	if a2b != 0 {
		nox_xxx_wndDraw_49F7F0()
		sub_49F7C0_def()
	} else {
		sub_47D370(v30)
	}
	nox_client_drawImageAt_47D2C0(a3, v59a, v59b)
	sub_4345F0(0)
	nox_client_drawEnableAlpha_434560(0)
	nox_xxx_draw_434600(0)
	if a2b != 0 {
		sub_49F860()
	}
	*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*1)) = 1
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v4), unsafe.Sizeof(uint16(0))*0)) = *memmap.PtrUint16(0x973F18, 88)
	*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*2)) = *memmap.PtrUint16(0x973F18, 88)
	*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*3)) = *memmap.PtrUint16(0x973F18, 76)
	v3.Field_2 = unsafe.Pointer(a3)
}
func sub_4C4EC0(a1 *uint32, a2 unsafe.Pointer) int8 {
	var (
		v3 int32
		v4 int32
		v5 int32
	)
	if *memmap.PtrUint32(0x852978, 8) != 0 && nox_client_drawable_testBuff_4356C0((*client.Drawable)(*memmap.PtrPtr(0x852978, 8)), 21) {
		return -1
	}
	v3 = int32(*(*uint32)(unsafe.Add(a2, 12)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*8))/2 - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	v4 = int32(*(*uint32)(unsafe.Add(a2, 16)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*9))/2 - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	v5 = int32(128 - uint32((v3*v3+v4*v4)<<7) / *memmap.PtrUint32(0x587000, 185464))
	if v5 < 0 {
		return 0
	}
	if v5 > 128 {
		v5 = 128
	}
	return int8(v5)
}
func nox_xxx_drawShinySpot_4C4F40(vp *noxrender.Viewport, dr *client.Drawable) int16 {
	var (
		a1 = vp
		a2 = dr
		v2 *byte
		v4 int32
		v5 uint32
		v6 int32
	)
	v2 = *(**byte)(memmap.PtrOff(0x5D4594, 1321524))
	if *memmap.PtrUint32(0x5D4594, 1321524) == 0 {
		v2 = (*byte)(unsafe.Pointer(nox_xxx_gLoadAnim_42FA20(internCStr("ShinySpot"))))
		*memmap.PtrPtr(0x5D4594, 1321524) = unsafe.Pointer(v2)
	}
	v3 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*24))
	v4 = int32(*(*uint8)(unsafe.Add(v3, 8)))
	v5 = (gameFrame() + a2.NetCode32) / uint32(v4*8)
	v6 = int32(((gameFrame() + a2.NetCode32) % uint32(v4*8)) >> 1)
	if v6 < v4 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v3, 4)) + uint32(v6*4))))), int32(a2.PosVec.X-a1.World.Min.X+a1.Screen.Min.X-64), int32(a1.Screen.Min.Y-int(uint32(a2.ZVal2))-int(uint32(a2.ZVal))-a1.World.Min.Y+a2.PosVec.Y-64))
	}
	return int16(uint16(v5))
}
func nox_xxx_colorInit_4C4FD0() {
	*memmap.PtrUint32(0x5D4594, 1321536) = nox_color_rgb_4344A0(math.MaxUint8, 200, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1321796) = nox_color_rgb_4344A0(math.MaxUint8, 0, math.MaxUint8)
	*memmap.PtrUint32(0x5D4594, 1321532) = nox_color_rgb_4344A0(100, 40, 100)
}
func sub_4C5020(a1 unsafe.Pointer) {
	if dword_5d4594_1321800 >= 32 {
		return
	}
	result := int32(dword_5d4594_1321800 + 1)
	*memmap.PtrUint32(0x5D4594, uintptr(result*8)+1321532) = *(*uint32)(unsafe.Add(a1, 1))
	*memmap.PtrUint32(0x5D4594, uintptr(result*8)+1321536) = *(*uint32)(unsafe.Add(a1, 5))
	dword_5d4594_1321800 = result
}
func sub_4C5050() {
	dword_5d4594_1321800 = 0
}
func sub_4C5060(a1p *noxrender.Viewport) int32 {
	var (
		a1     = a1p
		result int32
		v2     *uint16
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v10    int32
		a1a    Point32
		v12    Point32
		a2     Point32
		v14    Point32
	)
	result = int32(*memmap.PtrUint32(0x852978, 8))
	if *memmap.PtrUint32(0x852978, 8) == 0 {
		return result
	}
	result = dword_5d4594_1321800
	v10 = 0
	if dword_5d4594_1321800 <= 0 {
		return result
	}
	v2 = memmap.PtrUint16(0x5D4594, 1321540)
	for {
		v3 = int32(a1.Screen.Min.X + int(uint32(*v2)) - a1.World.Min.X)
		v4 = int32(a1.Screen.Min.Y + int(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*1)))) - a1.World.Min.Y)
		v5 = sub_4992B0(v3, v4)
		v6 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*3))) - int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*1)))
		if v3 <= 0 || int(v3) >= a1.Size.X-1 || v4 <= 0 || int(v4) >= a1.Size.Y-1 {
			v5 = 0
		}
		v14.X = v3 + int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*2))) - int32(*v2)
		v14.Y = v4 + v6
		v12.X = v3
		v12.Y = v4
		v7 = sub_498C20(&v12, &v14, int32(uintptr(unsafe.Pointer(a1))))
		if v7 != 0 {
			v8 = 0
			for a1a = v12; v8 < v7; v5 = 1 - v5 {
				a2 = sub_499290(v8)
				if v5 != 0 {
					sub_4C51D0(&a1a, &a2)
				}
				a1a = a2
				v8++
			}
			if v5 != 0 {
				sub_4C51D0(&a1a, &v14)
			}
		} else if v5 != 0 {
			sub_4C51D0(&v12, &v14)
		}
		result = v10 + 1
		v2 = (*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*4))
		v10++
		if v10 >= dword_5d4594_1321800 {
			break
		}
	}
	return result
}
func sub_4C51D0(a1 *Point32, a2 *Point32) int32 {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v11 int32
	)
	v2 = a1.Y
	v3 = a1.X
	v4 = a2.X - a1.X
	v5 = a2.Y - v2
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1321532))
	nox_client_drawEnableAlpha_434560(1)
	nox_client_drawAddPoint_49F500(v3, v2)
	nox_xxx_rasterPointRel_49F570(v4, v5)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawEnableAlpha_434560(0)
	v6 = v2 - 22
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1321536))
	nox_client_drawAddPoint_49F500(v3, v6)
	nox_xxx_rasterPointRel_49F570(v4, v5)
	nox_client_drawLineFromPoints_49E4B0()
	nox_client_drawSetColor_434460(*memmap.PtrInt32(0x5D4594, 1321796))
	v7 = v4
	if v4 < 0 {
		v7 = -v4
	}
	v8 = v5
	if v5 < 0 {
		v8 = -v5
	}
	if v7 <= v8 {
		nox_client_drawAddPoint_49F500(v3-1, v6)
		v11 = v6 + v5
		nox_client_drawAddPoint_49F500(v4+v3-1, v11)
		nox_client_drawLineFromPoints_49E4B0()
		nox_client_drawAddPoint_49F500(v3+1, v6)
		nox_client_drawAddPoint_49F500(v4+v3+1, v11)
	} else {
		nox_client_drawAddPoint_49F500(v3, v6-1)
		v9 = v3 + v4
		nox_client_drawAddPoint_49F500(v9, v6+v5-1)
		nox_client_drawLineFromPoints_49E4B0()
		nox_client_drawAddPoint_49F500(v3, v6+1)
		nox_client_drawAddPoint_49F500(v9, v6+v5+1)
	}
	return nox_client_drawLineFromPoints_49E4B0()
}
func nox_xxx_sprite_4CA540(a1 *noxrender.Viewport, a2 *client.Drawable) int {
	var (
		v3  float64
		v4  float64
		v5  float64
		v6  float64
		v7  int32
		v8  int32
		v9  int32
		v11 float32
		v12 float32
		v13 float32
		v14 float32
	)
	v2 := a2
	v3 = 0.0
	v4 = float64(a2.Field_117)
	v5 = float64(a2.Field_118)
	v6 = 0.0
	v7 = int32(gameFrame() - a2.AnimStart + 1)
	for {
		v7--
		v13 = float32(-(v5 * float64(a2.Field_119)))
		v4 = v4 - v4*float64(a2.Field_119)
		v5 = v5 + float64(v13)
		v3 = v3 + v4
		v6 = v6 + v5
		if v7 == 0 {
			break
		}
	}
	v14 = float32(v6)
	v11 = float32(float64(int32(v2.Field_81)) + v3)
	v8 = int32(v11)
	v12 = float32(float64(int32(v2.Field_82)) + float64(v14))
	v9 = int32(v12)
	if v8 > 0 && v9 > 0 && v8 < 5888 && v9 < 5888 {
		nox_xxx_updateSpritePosition_49AA90(v2, v8, v9)
		if sub_4992B0(int32(a1.Screen.Min.X+v2.PosVec.X-a1.World.Min.X), int32(v2.PosVec.Y+a1.Screen.Min.Y-a1.World.Min.Y)) != 0 {
			return 1
		}
	}
	nox_xxx_spriteDeleteStatic_45A4E0_drawable(v2)
	return 0
}
func sub_4CA650(vp *noxrender.Viewport, dr *client.Drawable) int {
	a2 := dr
	var (
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 uint16
		v13 int32
		v14 int32
		v16 int32
		v17 int32
	)
	v2 := a2
	v3 = int32(a2.PosVec.Y)
	v4 = int32(a2.Field_108_2) - v3
	v5 = int32(int(*(*uint16)(unsafe.Add(unsafe.Pointer(a2), 432))) - a2.PosVec.X)
	v6 = int32(sub_48C6B0(v5, v4))
	v7 = v6
	v8 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 443)))
	v17 = v8
	v7++
	v9 = int32(v2.PosVec.X)
	v10 = v5 * v8 / v7
	v11 = int32(v2.PosVec.Y)
	v16 = v9 + v10
	v12 = *(*uint16)(unsafe.Add(unsafe.Pointer(v2), 432))
	v13 = v9 - int32(v12)
	v14 = v11 + v4*v17/v7
	if v7 <= 10 || v13*(v16-int32(v12))+(v11-int32(v2.Field_108_2))*(v14-int32(v2.Field_108_2)) < 0 {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(v2)
		return 0
	} else {
		nox_xxx_updateSpritePosition_49AA90(v2, v16, v14)
		return 1
	}
}
func sub_4CA720(a1 int32, a2 *client.Drawable) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 int32
		v8 int32
	)
	v2 = int32(gameFrame() - a2.AnimStart)
	if v2 >= 60 || (func() bool {
		v3 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(a2), 432)))
		return cmath.Abs(int64(a2.PosVec.X-int(uint32(uint16(int16(v3)))))) < 10
	}()) && cmath.Abs(int64(a2.PosVec.Y-int(uint32(a2.Field_108_2)))) < 10 {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(a2)
		return 0
	} else {
		v4 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(a2), 440))) - v2*int32(*(*int16)(unsafe.Add(unsafe.Pointer(a2), 440)))/60
		v5 = (v2 << 8) / 120
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 443))) != 0 {
			v6 = v5 + int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 442)))
		} else {
			v6 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 442))) - v5
		}
		if v6 < 0 {
			v6 += int32(uint32(math.MaxUint8-v6) >> 8 << 8)
		}
		if v6 >= 256 {
			v6 += int32((uint32(v6) >> 8) * 4294967040)
		}
		v7 = v4 * *memmap.PtrInt32(0x587000, uintptr(v6*8)+192088)
		v8 = int32(a2.Field_108_2) + v4**memmap.PtrInt32(0x587000, uintptr(v6*8)+192092)/16
		nox_xxx_updateSpritePosition_49AA90(a2, v3+v7/16, v8)
		a2.Field_8 = uint32(v3 + v7/16)
		a2.Field_9 = uint32(v8)
		return 1
	}
}
func nox_gui_newProgressBar_4CAF10(a1 *gui.Window, a2 nox_window_flags, a3, a4, a5, a6 int, a7 *uint32) *gui.Window {
	v7 := *(*uint32)(unsafe.Add(unsafe.Pointer(a7), 4*2))
	if (v7 & 0x1000) == 0 {
		return nil
	}
	v8 := nox_window_new(a1, a2&0xFFFFFFF7, a3, a4, a5, a6, sub_4CAF80)
	sub_4CAFB0(v8)
	if v8 == nil {
		return v8
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a7), 4*4)) == 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(a7), 4*4)) = uint32(uintptr(unsafe.Pointer(v8)))
	}
	nox_gui_windowCopyDrawData_46AF80(v8, (*gui.WindowData)(unsafe.Pointer(a7)))
	return v8
}
func sub_4CAF80(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	if a2 == 16416 && a3 >= 0 && a3 <= 100 {
		win.WidgetData = unsafe.Pointer(a3)
	}
	return 0
}
func sub_4CAFB0(a1 *gui.Window) {
	if a1 == nil {
		return
	}
	if int32(int8(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))) >= 0 {
		nox_window_set_all_funcs(a1, nil, sub_4CAFF0, nil)
	} else {
		nox_window_set_all_funcs(a1, nil, sub_4CB1A0, nil)
	}
}
func sub_4CAFF0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win
		a2    = draw
		v2    int32
		v3    int32
		v4    int32
		v5    int32
		v6    int32
		v7    int32
		xLeft int32
		yTop  int32
		v11   int32
		v12   int32
		v13   int32
		v14   int32
		v15   [64]wchar2_t
	)
	v2 = int32(a2.TextColorVal)
	v3 = int32(a2.HlColorVal)
	v14 = int32(a2.EnColorVal)
	v4 = int32(a2.BgColorVal)
	v11 = v2
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop)
	if uint32(v4) != 0x80000000 {
		nox_client_drawSetColor_434460(v4)
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, int32(a1.SizeVal.X), int32(a1.SizeVal.Y))
	}
	if uint32(v3) != 0x80000000 {
		v5 = int32(a1.SizeVal.X * int(uintptr(a1.WidgetData)) / 100)
		nox_client_drawSetColor_434460(v3)
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, v5, int32(a1.SizeVal.Y))
	}
	if uint32(v11) != 0x80000000 {
		if (a1.Flags & 0x2000) == 0x2000 {
			nox_draw_enableTextSmoothing_43F670(1)
		}
		nox_swprintf(&v15[0], internWStr("%i%%"), a1.WidgetData)
		nox_xxx_drawGetStringSize_43F840(a2.FontPtr, &v15[0], &v13, &v12, 64)
		v6 = int32(uint32(xLeft) + uint32(a1.SizeVal.X)/2 - uint32(v13/2))
		v7 = int32(a1.SizeVal.Y/2 - int(uint32(v12/2)) + int(uint32(yTop)) + 1)
		nox_xxx_drawSetTextColor_434390(v11)
		nox_xxx_drawStringWrap_43FAF0(a2.FontPtr, &v15[0], v6, v7, int32(a1.SizeVal.X), 0)
		nox_draw_enableTextSmoothing_43F670(0)
	}
	if uint32(v14) != 0x80000000 {
		nox_client_drawSetColor_434460(v14)
		nox_client_drawBorderLines_49CC70(xLeft, yTop, int32(a1.SizeVal.X), int32(a1.SizeVal.Y))
	}
	return 1
}
func sub_4CB1A0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win
		a2    = draw
		xLeft int32
		yTop  int32
	)
	v2 := a2.BgImageHnd
	v3 := a1
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop)
	nox_xxx_wndDraw_49F7F0()
	v4 := int32(v3.SizeVal.X * int(uintptr(v3.WidgetData)) / 100)
	nox_client_copyRect_49F6F0(xLeft, yTop, v4, int32(v3.SizeVal.Y))
	if v2 != nil && v4 > 0 {
		nox_client_drawImageAt_47D2C0(v2, xLeft, yTop)
	}
	sub_49F860()
	return 1
}
func sub_4CB880() int {
	var (
		v1 **uint32
		v4 int32
		v5 int32
		v7 int32
	)
	nox_game_addStateCode_43BDD0(900)
	dword_5d4594_1522604 = nox_new_window_from_file(internCStr("InputCfg.wnd"), sub_4CBE70)
	if dword_5d4594_1522604 == nil {
		return 0
	}
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1522604, guiSelProc2)
	nox_wnd_xxx_1522608 = nox_gui_makeAnimation_43C5B0(dword_5d4594_1522604, 0, 0, 0, -480, 0, 20, 0, -40)
	if nox_wnd_xxx_1522608 == nil {
		return 0
	}
	nox_wnd_xxx_1522608.StateID = 900
	nox_wnd_xxx_1522608.Func12Ptr.Set(sub_4CBB70)
	nox_wnd_xxx_1522608.FncDoneOutPtr.Set(sub_4CBBB0)
	dword_5d4594_1522616 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1522604, 910)
	dword_5d4594_1522620 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1522604, 911)
	dword_5d4594_1522624 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1522604, 912)
	dword_5d4594_1522628 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1522604, 913)
	if dword_5d4594_1522616 == nil {
		return 0
	}
	v1 = (**uint32)(dword_5d4594_1522616.WidgetData)
	**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*7)) = 921
	**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*8)) = 922
	**(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*9)) = 920
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_1522616, sub_4CBF60)
	sub_46B120(dword_5d4594_1522620, dword_5d4594_1522616)
	sub_46B120(dword_5d4594_1522624, dword_5d4594_1522616)
	sub_46B120(dword_5d4594_1522628, dword_5d4594_1522616)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1522624, sub_4CC140)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1522628, sub_4CC140)
	v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1522604, 921)
	nox_window_call_field_94_fnc(dword_5d4594_1522620, 16408, uintptr(unsafe.Pointer(v2)), 0)
	nox_window_call_field_94_fnc(dword_5d4594_1522624, 16408, uintptr(unsafe.Pointer(v2)), 0)
	nox_window_call_field_94_fnc(dword_5d4594_1522628, 16408, uintptr(unsafe.Pointer(v2)), 0)
	v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1522604, 922)
	nox_window_call_field_94_fnc(dword_5d4594_1522620, 16409, uintptr(unsafe.Pointer(v3)), 0)
	nox_window_call_field_94_fnc(dword_5d4594_1522624, 16409, uintptr(unsafe.Pointer(v3)), 0)
	nox_window_call_field_94_fnc(dword_5d4594_1522628, 16409, uintptr(unsafe.Pointer(v3)), 0)
	sub_4CBBF0()
	v4 = 971
	v5 = int32(sub_47DBC0()) + 971
	if v5 > 971 {
		for {
			v6 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1522604, v4)
			nox_xxx_wnd_46ABB0(v6, 1)
			v4++
			if v4 >= v5 {
				break
			}
		}
	}
	v7 = nox_client_mousePriKey_430AF0()
	v8 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1522604, v7+971)
	nox_window_call_field_94_fnc(v8, 16392, 1, 0)
	dword_5d4594_1522612 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1522604, 980)
	sub_46B120(dword_5d4594_1522612, nil)
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_1522612, sub_4CBE70)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1522612, sub_4CC170)
	nox_window_set_hidden(dword_5d4594_1522612, 1)
	v9 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1522612, 981)
	sub_46AEE0(v9, int32(uintptr(memmap.PtrOff(0x5D4594, 1522636))))
	return 1
}
func sub_4CBB70() int {
	sub_4CBD30()
	nox_common_writecfgfile(internCStr("nox.cfg"))
	nox_wnd_xxx_1522608.SetState(NOX_GUI_ANIM_OUT)
	sub_43BE40(2)
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100)
	return 1
}
func sub_4CBBB0() int {
	v0 := nox_wnd_xxx_1522608.Func13Ptr.Get()
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_1522608)
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1522604)
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1522612)
	v0()
	return 1
}
func sub_4CC140(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	if a2 < 0x13 || a2 > 0x14 {
		return nox_xxx_wndListboxProcWithoutData10_4A28E0(win, a2, a3, a4)
	} else {
		return 0
	}
}
func sub_4CC170(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	switch a2 {
	case 6, 7:
		sub_4CC3C0(0x10000)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0(dword_5d4594_1522612)
		nox_window_set_hidden(dword_5d4594_1522612, 1)
		return 1
	case 10, 11:
		sub_4CC3C0(0x10002)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0(dword_5d4594_1522612)
		nox_window_set_hidden(dword_5d4594_1522612, 1)
		return 1
	case 14, 15:
		sub_4CC3C0(0x10001)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0(dword_5d4594_1522612)
		nox_window_set_hidden(dword_5d4594_1522612, 1)
		return 1
	case 19:
		sub_4CC3C0(0x10003)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0(dword_5d4594_1522612)
		nox_window_set_hidden(dword_5d4594_1522612, 1)
		return 1
	case 20:
		sub_4CC3C0(0x10004)
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wnd_46C6E0(dword_5d4594_1522612)
		nox_window_set_hidden(dword_5d4594_1522612, 1)
		return 1
	case 21:
		if a3 == uintptr(1) {
			if a4 != 2 {
				return 1
			}
			nox_xxx_windowFocus_46B500(nil)
			nox_xxx_wnd_46C6E0(dword_5d4594_1522612)
			nox_window_set_hidden(dword_5d4594_1522612, 1)
			if dword_5d4594_1522632 != nil {
				nox_window_call_field_94_fnc(dword_5d4594_1522632, 16403, math.MaxUint32, 0)
			}
			return 1
		} else if a4 == 1 && sub_4CC280(uint32(a3)) != 0 {
			sub_4CC3C0(0x10000)
			nox_xxx_windowFocus_46B500(nil)
			nox_xxx_wnd_46C6E0(dword_5d4594_1522612)
			nox_window_set_hidden(dword_5d4594_1522612, 1)
			return 1
		} else {
			return 0
		}
	default:
		return 0
	}
}
func sub_4CC280(a1 uint32) int32 {
	var v6 *wchar2_t = nox_xxx_keybind_titleByKeyZero_42EA00(a1)
	if v6 == nil {
		return 0
	}
	if dword_5d4594_1522632 == nil {
		return 1
	}
	var v7 int32 = 0
	v8 := dword_5d4594_1522624.WidgetData
	if int32(*(*uint16)(unsafe.Add(v8, 44))) > 0 {
		for {
			{
				var v9 *wchar2_t = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1522624, 16406, uintptr(v7), 0)))
				if nox_wcscmp(v9, v6) == 0 {
					nox_window_call_field_94_fnc(dword_5d4594_1522624, 16407, uintptr(memmap.PtrOff(0x587000, 187824)), uintptr(v7))
				}
				v7++
			}
			if v7 >= int32(*(*int16)(unsafe.Add(v8, 44))) {
				break
			}
		}
	}
	var v10 int32 = 0
	v11 := dword_5d4594_1522628.WidgetData
	if int32(*(*uint16)(unsafe.Add(v11, 44))) > 0 {
		for {
			{
				var v12 *wchar2_t = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1522628, 16406, uintptr(v10), 0)))
				if nox_wcscmp(v12, v6) == 0 {
					nox_window_call_field_94_fnc(dword_5d4594_1522628, 16407, uintptr(memmap.PtrOff(0x587000, 187828)), uintptr(v10))
				}
				v10++
			}
			if v10 >= int32(*(*int16)(unsafe.Add(v11, 44))) {
				break
			}
		}
	}
	nox_window_call_field_94_fnc(dword_5d4594_1522632, 16407, uintptr(unsafe.Pointer(v6)), uintptr(*(*uint32)(unsafe.Add(dword_5d4594_1522632.WidgetData, 48))))
	nox_window_call_field_94_fnc(dword_5d4594_1522632, 16403, math.MaxUint32, 0)
	dword_5d4594_1522632 = nil
	return 1
}
func sub_4CC3C0(a1 uint32) int32 {
	var (
		v1 *byte
		v2 int32
		v4 *wchar2_t
		v5 int32
		v7 *wchar2_t
	)
	v1 = (*byte)(unsafe.Pointer(nox_xxx_keybind_titleByKey_42EA00(a1)))
	if dword_5d4594_1522632 == nil {
		return 1
	}
	v2 = 0
	v3 := dword_5d4594_1522624.WidgetData
	if int32(*(*uint16)(unsafe.Add(v3, 44))) > 0 {
		for {
			v4 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1522624, 16406, uintptr(v2), 0)))
			if nox_wcscmp(v4, (*wchar2_t)(unsafe.Pointer(v1))) == 0 {
				nox_window_call_field_94_fnc(dword_5d4594_1522624, 16407, uintptr(memmap.PtrOff(0x587000, 187832)), uintptr(v2))
			}
			v2++
			if v2 >= int32(*(*int16)(unsafe.Add(v3, 44))) {
				break
			}
		}
	}
	v5 = 0
	v6 := dword_5d4594_1522628.WidgetData
	if int32(*(*uint16)(unsafe.Add(v6, 44))) > 0 {
		for {
			v7 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1522628, 16406, uintptr(v5), 0)))
			if nox_wcscmp(v7, (*wchar2_t)(unsafe.Pointer(v1))) == 0 {
				nox_window_call_field_94_fnc(dword_5d4594_1522628, 16407, uintptr(memmap.PtrOff(0x587000, 187836)), uintptr(v5))
			}
			v5++
			if v5 >= int32(*(*int16)(unsafe.Add(v6, 44))) {
				break
			}
		}
	}
	nox_window_call_field_94_fnc(dword_5d4594_1522632, 16407, uintptr(unsafe.Pointer(v1)), uintptr(*(*uint32)(unsafe.Add(dword_5d4594_1522632.WidgetData, 48))))
	nox_window_call_field_94_fnc(dword_5d4594_1522632, 16403, math.MaxUint32, 0)
	dword_5d4594_1522632 = nil
	return 1
}
func nox_xxx_updDrawUndeadKiller_4CCCF0(vp *noxrender.Viewport, dr *client.Drawable) int {
	return 1
}
func sub_4CCD00(vp *noxrender.Viewport, dr *client.Drawable) int {
	a2 := dr
	var i uint32
	for i = *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 432)); i < gameFrame(); i++ {
		if *(*float32)(unsafe.Pointer(&a2.Field_109)) > 0.0 {
			*(*float32)(unsafe.Pointer(&a2.Field_109)) = *(*float32)(unsafe.Pointer(&a2.Field_110)) + *(*float32)(unsafe.Pointer(&a2.Field_109))
			*(*float32)(unsafe.Pointer(&a2.Field_110)) = *(*float32)(unsafe.Pointer(&a2.Field_110)) - 1.0
		}
		if *(*float32)(unsafe.Pointer(&a2.Field_109)) <= 0.0 {
			a2.Field_109 = 0
			a2.Field_110 = 0
		}
	}
	a2.ZVal = uint16(int16(*(*float32)(unsafe.Pointer(&a2.Field_109))))
	a2.VelZ = int8(*(*float32)(unsafe.Pointer(&a2.Field_110)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 432)) = gameFrame()
	return 1
}
func nox_xxx_updDrawFist_4CCDB0(vp *noxrender.Viewport, dr *client.Drawable) int {
	a2 := dr
	var (
		i  uint32
		v3 float64
		v4 float64
		v5 float64
	)
	for i = *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 432)); i < gameFrame(); i++ {
		v3 = float64(*(*float32)(unsafe.Pointer(&a2.Field_109)) + *(*float32)(unsafe.Pointer(&a2.Field_110)))
		*(*float32)(unsafe.Pointer(&a2.Field_109)) = float32(v3)
		if v3 >= 0.0 {
			*(*float32)(unsafe.Pointer(&a2.Field_110)) = *(*float32)(unsafe.Pointer(&a2.Field_110)) - 0.5
		} else {
			v4 = float64(-*(*float32)(unsafe.Pointer(&a2.Field_110)) * *(*float32)(unsafe.Pointer(&a2.Field_111)))
			*(*float32)(unsafe.Pointer(&a2.Field_109)) = 0
			v5 = v4 * 0.1
			*(*float32)(unsafe.Pointer(&a2.Field_110)) = float32(v5)
			if v5 < 2.0 {
				*(*float32)(unsafe.Pointer(&a2.Field_109)) = 0
				*(*float32)(unsafe.Pointer(&a2.Field_110)) = 0
			}
		}
	}
	a2.ZVal = uint16(int16(*(*float32)(unsafe.Pointer(&a2.Field_109))))
	a2.VelZ = int8(*(*float32)(unsafe.Pointer(&a2.Field_110)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 432)) = gameFrame()
	return 1
}
func sub_4CCE70(vp *noxrender.Viewport, dr *client.Drawable) int {
	if dr.Field_120 == 0 && nox_xxx_checkGameFlagPause_413A50() == 0 {
		sub_4CCEA0(dr, 5)
	}
	return 1
}
func sub_4CD090(vp *noxrender.Viewport, dr *client.Drawable) int {
	if dr.Field_120 == 0 && nox_xxx_checkGameFlagPause_413A50() == 0 {
		sub_4CCEA0(dr, 4)
	}
	return 1
}
func sub_4CD0C0(vp *noxrender.Viewport, dr *client.Drawable) int {
	if dr.Field_120 == 0 && nox_xxx_checkGameFlagPause_413A50() == 0 {
		sub_4CCEA0(dr, 3)
	}
	return 1
}
func sub_4CD0F0(vp *noxrender.Viewport, dr *client.Drawable) int {
	if dr.Field_120 == 0 && nox_xxx_checkGameFlagPause_413A50() == 0 {
		sub_4CCEA0(dr, 2)
	}
	return 1
}
func sub_4CD120(vp *noxrender.Viewport, dr *client.Drawable) int {
	if dr.Field_120 == 0 && nox_xxx_checkGameFlagPause_413A50() == 0 {
		sub_4CCEA0(dr, 1)
	}
	return 1
}
func sub_4CD400(vp *noxrender.Viewport, dr *client.Drawable) int {
	v2 := dword_5d4594_1522968
	if dword_5d4594_1522968 == 0 {
		v2 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CharmOrb"))
		dword_5d4594_1522968 = v2
	}
	sub_4CD150(v2, vp, dr, 1)
	sub_4CD150(dword_5d4594_1522968, vp, dr, 0)
	return 1
}
