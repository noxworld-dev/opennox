package server

import "github.com/noxworld-dev/opennox/v1/legacy/common/alloc"

type SpellProjectileUpdateData struct {
	Field0  *Object // 0, 0
	Field4  uint32  // 1, 4
	Field8  *Object // 2, 8
	Spell12 uint32  // 3, 12
	Level16 uint32  // 4, 16
	Field20 uint32  // 5, 20
	Field24 uint32  // 6, 24
}

func (obj *Object) UpdateDataSpellProjectile() *SpellProjectileUpdateData {
	if alloc.IsDead(obj.UpdateData) {
		panic("object already deleted")
	}
	// TODO: verify this conversion by checking ObjectType
	return (*SpellProjectileUpdateData)(obj.UpdateData)
}
