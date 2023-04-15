package server

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type TileDef struct {
	NameBuf [32]byte       // 0, 0
	Data32  unsafe.Pointer // 8, 32, TODO: []noxrender.ImageHandle
	Field36 int32          // 9, 36
	Field40 int32          // 10, 40
	Field44 uint16         // 11, 44
	Field46 uint16         // 11, 46
	Color48 uint32         // 12, 48
	Field52 byte           // 13, 52
	Field53 byte           // 13, 53
	Field54 byte           // 13, 54
	Field55 byte           // 13, 55
	Field56 byte           // 14, 56
	Field57 byte           // 14, 57
	Field58 byte           // 14, 58
	Field59 byte           // 14, 59
}

func (t *TileDef) Name() string {
	return alloc.GoStringS(t.NameBuf[:])
}
