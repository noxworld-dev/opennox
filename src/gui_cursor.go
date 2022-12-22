package opennox

import "C"
import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/internal/ccall"
)

const cursorSize = 64

//export nox_client_setCursorType_477610
func nox_client_setCursorType_477610(v C.int) C.int {
	noxClient.Nox_client_setCursorType(gui.Cursor(v))
	return v
}

//export nox_xxx_cursorGetTypePrev_477630
func nox_xxx_cursorGetTypePrev_477630() C.int {
	return C.int(noxClient.CursorPrev)
}

func (c *Client) getCursorAnimFrame(ref *noxImageRef, dt int) *noxrender.Image {
	if ref == nil {
		return nil
	}
	anim := ref.field24ptr()
	ts := int(c.GetInputSeq()) + dt
	imgs := anim.Images()
	switch anim.anim_type {
	case 0: // OneShot
		ind := (ts - int(anim.field_3)) / (int(anim.field_2_1) + 1)
		if ind+1 >= len(imgs) {
			ind = len(imgs) - 1
			if anim.on_end != nil {
				ccall.CallVoidPtr(unsafe.Pointer(anim.on_end), unsafe.Pointer(ref.C()))
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

func (c *Client) sub_4BE710(ref *noxImageRef, pos image.Point, ind int) {
	anim := ref.field24ptr()
	imgs := anim.Images()
	img := asImage(imgs[ind])
	if c.flag3798728 {
		c.r.noxDrawCursor(img, pos)
	} else {
		c.r.DrawImageAt(img, pos)
	}
}
