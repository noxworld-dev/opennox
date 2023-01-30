package gui

import "unsafe"

type ScrollListBoxItem struct {
	Field_0   uint32      // 0, 0
	Text      [256]uint16 // 1, 4
	Field_129 uint32      // 129, 516
	Field_130 uint32      // 130, 520
}

type ScrollListBoxData struct {
	Count       uint16             // 0, 0
	Line_height uint16             // 0, 2
	Field_1     uint32             // 1, 4
	Field_2     uint32             // 2, 8
	Field_3     uint32             // 3, 12
	Field_4     uint32             // 4, 16
	Field_5     uint32             // 5, 20
	Items       *ScrollListBoxItem // 6, 24
	Field_7     unsafe.Pointer     // 7, 28
	Field_8     unsafe.Pointer     // 8, 32
	Field_9     unsafe.Pointer     // 9, 36
	Field_10    uint32             // 10, 40
	Field_11_0  uint16             // 11, 44
	Field_11_1  uint16             // 11, 46
	Field_12    *uint32            // 12, 48, []*void? []int32?
	Field_13_0  uint16             // 13, 52
	Field_13_1  uint16             // 13, 54
}

func (d *ScrollListBoxData) CWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}
