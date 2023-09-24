package server

type MoverUpdateData struct {
	Field_0 uint8   // 0, 0
	_       [3]byte // 0, 1
	Field_1 float32 // 1, 4
	Field_2 int32   // 2, 8
	Field_3 uint32  // 3, 12
	Field_4 uint32  // 4, 16
	Field_5 uint32  // 5, 20
	Field_6 uint32  // 6, 24
	Field_7 *Object // 7, 28
	Field_8 uint32  // 8, 32
}

func (obj *Object) UpdateDataMover() *MoverUpdateData {
	return (*MoverUpdateData)(obj.UpdateData)
}
