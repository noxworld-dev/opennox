package gui

import "unsafe"

type EntryFieldData struct {
	Text       [512]uint16
	Field_1024 uint32
	Field_1028 uint32
	Field_1032 uint32
	Field_1036 uint32
	Field_1040 uint16
	Field_1042 int16
	Field_1044 uint32
	Field_1048 uint32
	Field_1052 uint32
}

func (d *EntryFieldData) CWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}
