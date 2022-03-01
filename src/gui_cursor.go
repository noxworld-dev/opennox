package nox

import "C"
import (
	"unsafe"

	"nox/v1/client/gui"
	"nox/v1/common/types"
)

const cursorSize = 64

var (
	nox_client_mouseCursorType           = gui.CursorSelect
	nox_xxx_cursorTypePrev_587000_151528 = gui.Cursor17
	dword_5d4594_3798728                 bool
	dword_5d4594_1097208                 int
	dword_5d4594_1097212                 types.Point
)

func nox_client_setCursorType(v gui.Cursor) {
	nox_client_mouseCursorType = v
}

func nox_client_getCursorType() gui.Cursor {
	return nox_client_mouseCursorType
}

//export nox_client_setCursorType_477610
func nox_client_setCursorType_477610(v C.int) C.int {
	nox_client_setCursorType(gui.Cursor(v))
	return v
}

//export nox_client_getCursorType_477620
func nox_client_getCursorType_477620() C.int {
	return C.int(nox_client_getCursorType())
}

//export nox_xxx_cursorGetTypePrev_477630
func nox_xxx_cursorGetTypePrev_477630() C.int {
	return C.int(nox_xxx_cursorTypePrev_587000_151528)
}

func getCursorAnimFrame(ref *noxImageRef, dt int) *Image { // sub_4BE640
	if ref == nil {
		return nil
	}
	anim := ref.field24ptr()
	ts := int(getInputSeq()) + dt
	imgs := anim.Images()
	switch anim.anim_type {
	case 0: // OneShot
		ind := (ts - int(anim.field_3)) / (int(anim.field_2_1) + 1)
		if ind+1 >= len(imgs) {
			ind = len(imgs) - 1
			if anim.on_end != nil {
				cgoCallVoidPtrFunc(unsafe.Pointer(anim.on_end), unsafe.Pointer(ref.C()))
			}
		}
		return asImage(imgs[ind])
	case 2: // Loop
		ind := ts / (int(anim.field_2_1) + 1)
		ind %= len(imgs)
		return asImage(imgs[ind])
	default:
		return nil
	}
}

func (r *NoxRender) sub_4BE710(ref *noxImageRef, pos types.Point, ind int) {
	anim := ref.field24ptr()
	imgs := anim.Images()
	img := asImage(imgs[ind])
	if dword_5d4594_3798728 {
		r.noxDrawCursor(img, pos)
	} else {
		r.DrawImageAt(img, pos)
	}
}
