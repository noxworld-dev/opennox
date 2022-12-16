package client

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

type ObjectType struct {
	Name           *byte          // 0, 0x0
	PrettyName     *uint16        // 1, 0x4, 4
	Desc           *uint16        // 2, 0x8, 8
	HWidth         uint8          // 3, 0xc, 12
	HHeight        uint8          // 3, 0xd, 13
	Weight         uint8          // 3, 0xe, 14
	Field_f        uint8          // 3, 0xf, 15
	Field_10       uint32         // 4, 0x10, 16
	ShapeKind      uint16         // 5, 0x14, 20
	Z              uint16         // 5, 0x16, 22
	LightDir       uint16         // 6, 0x18, 24
	LightPenumbra  uint16         // 6, 0x1a, 26
	Field_1c       int32          // 7, 0x1c, 28, ID? index?
	ObjClass       uint32         // 8, 0x20, 32
	ObjSubClass    uint32         // 9, 0x24, 36
	ObjFlags       int32          // 10, 0x28, 40
	LightIntensity float32        // 11, 0x2c, 44
	LightColorR    int32          // 12, 0x30, 48
	LightColorG    int32          // 13, 0x34, 52
	LightColorB    int32          // 14, 0x38, 56
	Field_3c       uint32         // 15, 0x3c
	ShapeR         float32        // 16, 0x40, 64
	ZSizeMin       float32        // 17, 0x44, 68
	ZSizeMax       float32        // 18, 0x48, 72
	ShapeW         float32        // 19, 0x4c, 76
	ShapeH         float32        // 20, 0x50, 80
	Field_54       uint32         // 21, 0x54
	DrawFunc       unsafe.Pointer // 22, 0x58, 88, same as nox_drawable->draw_func
	Field_5c       unsafe.Pointer // 23, 0x5c, 92
	Field_60       uint32         // 24, 0x60, 96
	ClientUpdate   uint32         // 25, 0x64, 100
	AudioLoop      uint32         // 26, 0x68, 104
	ObjNext        *ObjectType    // 27, 0x6c, 108
	PrettyImage    uint32         // 28, 0x70, 112
	MenuIcon       int32          // 29, 0x74, 116
	Lifetime       int32          // 30, 0x78, 120
	Health         uint16         // 31, 0x7c, 124
	Field_7e       uint16         // 31, 0x7e, 126
}

func (t *ObjectType) C() unsafe.Pointer {
	return unsafe.Pointer(t)
}

func (t *ObjectType) ID() string {
	if t == nil || t.Name == nil {
		return ""
	}
	n := alloc.StrLen(t.Name)
	name := unsafe.Slice(t.Name, n)
	return string(name)
}

func (t *ObjectType) Index() int {
	if t == nil {
		return 0
	}
	return int(t.Field_1c)
}
