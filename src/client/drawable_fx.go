package client

import "unsafe"

type DrawableFX struct {
	Field0  uint32      // 0, 0
	Field4  uint32      // 1, 4
	Field8  uint32      // 2, 8
	Field12 uint32      // 3, 12
	Next    *DrawableFX // 4, 16
	Field20 uint32      // 5, 20
	Field24 uint32      // 6, 24
	Field28 uint32      // 7, 28
	Field32 uint32      // 8, 32
	Field36 uint32      // 9, 36
	Field40 uint32      // 10, 40
	Field44 uint32      // 11, 44
	Field48 uint32      // 12, 48
	Field52 uint32      // 13, 52
	Field56 uint32      // 14, 56
	Field60 *Drawable   // 15, 60
	Field64 *DrawableFX // 16, 64
	Field68 uint32      // 17, 68
	Field72 uint32      // 18, 72
	Field76 uint32      // 19, 76
}

func (fx *DrawableFX) C() unsafe.Pointer {
	return unsafe.Pointer(fx)
}
