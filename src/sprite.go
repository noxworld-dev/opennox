package main

/*
#include "defs.h"
*/
import "C"
import (
	"unsafe"

	"nox/v1/common/types"
)

func asSprite(p *C.nox_drawable) *Sprite {
	return (*Sprite)(unsafe.Pointer(p))
}

type Sprite C.nox_drawable

func (s *Sprite) C() *C.nox_drawable {
	return (*C.nox_drawable)(unsafe.Pointer(s))
}

func (s *Sprite) posMB() types.Point {
	return types.Point{
		X: int(s.field_3),
		Y: int(s.field_4),
	}
}

func (s *Sprite) Flags28() uint {
	return uint(s.flags28)
}

func (s *Sprite) Flags29() uint {
	return uint(s.flags29)
}

func (s *Sprite) Flags30() uint {
	return uint(s.flags30)
}

func (s *Sprite) Flags70() uint {
	return uint(s.flags70)
}
