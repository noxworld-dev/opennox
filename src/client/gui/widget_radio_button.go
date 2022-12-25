package gui

import "unsafe"

type RadioButtonData struct {
	Field0 uint32
}

func (d *RadioButtonData) CWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}
