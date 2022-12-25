package gui

import "unsafe"

type SliderData struct {
	Min    uint32
	Max    uint32
	Field2 uint32
	Field3 uint32
}

func (d *SliderData) CWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}
