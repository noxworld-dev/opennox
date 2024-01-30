package gui

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type ScrollListBoxItem struct {
	Field_0   uint32      // 0, 0
	TextBuf   [256]uint16 // 1, 4
	Field_129 uint32      // 129, 516
	Field_130 uint32      // 130, 520
}

func (it *ScrollListBoxItem) Text() string {
	return alloc.GoString16S(it.TextBuf[:])
}

func (it *ScrollListBoxItem) SetText(s string) {
	alloc.StrCopyZero16(it.TextBuf[:], s)
}

type ScrollListBoxData struct {
	Count      uint16             // 0, 0
	LineHeight uint16             // 0, 2
	Field_1    uint32             // 1, 4
	Field_2    uint32             // 2, 8
	HasScroll  uint32             // 3, 12
	HasData    uint32             // 4, 16
	Field_5    uint32             // 5, 20
	ItemsPtr   *ScrollListBoxItem // 6, 24
	UpButton   *Window            // 7, 28
	DownButton *Window            // 8, 32
	Slider     *Window            // 9, 36
	Field_10   uint32             // 10, 40
	Field_11_0 uint16             // 11, 44
	Field_11_1 uint16             // 11, 46
	Field_12   uintptr            // 12, 48; used as []int32 when HasData == 1, otherwise int32
	Field_13_0 uint16             // 13, 52
	Field_13_1 uint16             // 13, 54
}

func (d *ScrollListBoxData) CWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

func (d *ScrollListBoxData) Field12() int {
	return int(int32(uint32(d.Field_12)))
}

func (d *ScrollListBoxData) SetField12(v int) {
	d.Field_12 = uintptr(uint32(int32(v)))
}

func (d *ScrollListBoxData) Field12Ptr() *int32 {
	return (*int32)(unsafe.Pointer(d.Field_12))
}

func (d *ScrollListBoxData) SetField12Ptr(v *int32) {
	d.Field_12 = uintptr(unsafe.Pointer(v))
}

func (d *ScrollListBoxData) Field12Slice() []int32 {
	if d == nil || d.Field_12 == 0 || d.Count == 0 {
		return nil
	}
	return unsafe.Slice(d.Field12Ptr(), d.Count)
}

func (d *ScrollListBoxData) SetField12Slice(v []int32) {
	if len(v) == 0 {
		d.SetField12Ptr(nil)
	} else {
		d.SetField12Ptr(&v[0])
	}
}

func (d *ScrollListBoxData) Items() []ScrollListBoxItem {
	if d == nil || d.ItemsPtr == nil || d.Count == 0 {
		return nil
	}
	return unsafe.Slice(d.ItemsPtr, d.Count)
}
