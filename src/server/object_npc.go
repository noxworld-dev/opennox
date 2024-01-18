package server

import "unsafe"

var _ = [1]struct{}{}[1316-unsafe.Sizeof(NPC{})]

type NPC struct {
	LiveVal     byte
	_           [3]byte
	IDVal       int32
	Color8      [6]uint32                      // 2, 8
	Weapon      [PlayerWeaponCnt]EquipmentData // 8, 32
	Armor       [PlayerArmorCnt]EquipmentData  // 170, 680
	WeaponEquip uint32                         // 326, 1304
	ArmorEquip  uint32                         // 327, 1308
	Field1312   uint32                         // 328, 1312
}
