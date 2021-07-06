package main

/*
#include "defs.h"
static int go_nox_drawable_call_draw_func(nox_draw_viewport_t* vp, nox_drawable* dr) {
	return dr->draw_func(vp, dr);
}
*/
import "C"
import (
	"unsafe"

	"nox/v1/common/types"
)

func asDrawable(p *C.nox_drawable) *Drawable {
	return (*Drawable)(unsafe.Pointer(p))
}

type Drawable C.nox_drawable

func (s *Drawable) C() *C.nox_drawable {
	return (*C.nox_drawable)(unsafe.Pointer(s))
}

func (s *Drawable) Pos() types.Point {
	return types.Point{
		X: int(s.pos.x),
		Y: int(s.pos.y),
	}
}

func (s *Drawable) SetPos(p types.Point) {
	s.pos.x = C.int(p.X)
	s.pos.y = C.int(p.Y)
}

func (s *Drawable) Flags28() uint {
	return uint(s.flags28)
}

func (s *Drawable) Flags29() uint {
	return uint(s.flags29)
}

func (s *Drawable) Flags30() uint {
	return uint(s.flags30)
}

func (s *Drawable) Flags70() uint {
	return uint(s.flags70)
}

func (s *Drawable) Field32() uint32 {
	return uint32(s.field_32) // TODO: NPC ID?
}

func (s *Drawable) DrawFunc(vp *Viewport) int {
	return int(C.go_nox_drawable_call_draw_func(vp.C(), s.C()))
}
