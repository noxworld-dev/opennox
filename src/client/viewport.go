package client

import (
	"image"
	"unsafe"
)

type Viewport struct {
	Screen  image.Rectangle // 0, 0
	World   image.Rectangle // 4, 16
	Size    image.Point     // 8, 32
	Field10 uint            // 10, 40
	Field11 uint            // 11, 44
	Field12 int             // 12, 48
}

func (vp *Viewport) C() unsafe.Pointer {
	return unsafe.Pointer(vp)
}

func (vp *Viewport) ToScreenPos(pos image.Point) image.Point { // sub_4739E0
	return pos.Sub(vp.World.Min).Add(vp.Screen.Min)
}

func (vp *Viewport) ToWorldPos(pos image.Point) image.Point {
	return pos.Sub(vp.Screen.Min).Add(vp.World.Min)
}
