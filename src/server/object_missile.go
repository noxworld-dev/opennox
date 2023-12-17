package server

type MissileUpdateData struct {
	Owner    *Object // 0, 0
	Target   *Object // 1, 4
	Field_8  uint32  // 2, 8
	SpellID  int32   // 3, 12
	Field_16 uint32  // 4, 16
	Field_20 uint32  // 5, 20
	Field_24 uint32  // 6, 24
}

func (obj *Object) UpdateDataMissile() *MissileUpdateData {
	return (*MissileUpdateData)(obj.UpdateData)
}
