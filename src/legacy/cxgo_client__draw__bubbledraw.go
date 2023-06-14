package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func nox_thing_bubble_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*uint32)(vp.C())
	var (
		v2    uint32
		v4    int32
		v5    int32
		v6    int8
		v7    int8
		v8    int8
		v9    uint8
		v10   int8
		v11   int8
		v12   int8
		v13   bool
		v14   int8
		v15   int8
		v16   int8
		xLeft int2
		a2    int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441))) == 3 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 440))) == 0 {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
			return 0
		}
	} else {
		v2 = *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 356))
		if v2 != 0 && v2 <= gameFrame() {
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441)) = 3
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 442)) = 4
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 443)) = 4
			nox_xxx_spriteTransparentDecay_49B950((*client.Drawable)(unsafe.Pointer(uintptr(a2))), int32(gameFPS()))
		}
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441))) == 3 {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 440))) == 0 {
				nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
				return 0
			}
		}
	}
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	xLeft.field_0 = int32(*a1 + *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 12)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	v5 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 440)))
	xLeft.field_4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 16)) + uint32(v4) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) - uint32(*(*int16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 104))))
	sub_4B6720(&xLeft, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 432))), v5, int8(v5+3))
	nox_client_drawSetColor_434460(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 436))))
	nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 440)))>>1)
	if int32(uint8(gameFrame()))&3 != 0 {
		*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 104)) += uint16(*(*byte)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 446)))
	}
	v6 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 442)))
	if int32(v6) != 0 {
		v7 = int8(int32(v6) - 1)
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 442)) = uint8(v7)
		if int32(v7) == 0 {
			v8 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441)))
			if int32(v8) == 1 {
				v9 = uint8(int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 440))) + 1))
				*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 440)) = v9
				if int32(v9) >= 5 {
					*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441)) = 2
				}
			} else {
				v13 = int32(v8) == 2
				v14 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 440)))
				if v13 {
					v15 = int8(int32(v14) - 1)
					*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 440)) = uint8(v15)
					if int32(v15) == 0 {
						*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 441)) = 1
					}
				} else {
					v16 = int8(int32(v14) - 1)
					*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 440)) = uint8(v16)
					if int32(v16) == 0 {
						nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
						return 0
					}
				}
			}
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 442)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 443))
		}
	}
	v10 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 445)))
	if int32(v10) != 0 {
		v11 = int8(int32(v10) - 1)
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 445)) = uint8(v11)
		if int32(v11) == 0 {
			v12 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 444)))
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 446)) = -*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 446))
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 445)) = uint8(v12)
		}
	}
	if int32(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 104)))) >= 0 {
		return 1
	}
	nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
	return 0
}
