package server

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

const maxNPCs = 1024

type serverNPCs struct {
	arr []NPC
}

func (s *serverNPCs) Init() {
	s.arr, _ = alloc.Make([]NPC{}, maxNPCs)
}

func (s *serverNPCs) New(id int) *NPC { // nox_new_npc
	for i := range s.arr {
		cur := &s.arr[i]
		if cur.LiveVal == 0 {
			s.Set(cur, id)
			return cur
		}
	}
	return nil
}

func (s *serverNPCs) ByID(id int) *NPC { // nox_npc_by_id
	for i := range s.arr {
		cur := &s.arr[i]
		if int(cur.IDVal) == id && cur.LiveVal != 0 {
			return cur
		}
	}
	return nil
}

func (s *serverNPCs) Set(ptr *NPC, id int) { // nox_init_npc
	*ptr = NPC{}
	ptr.LiveVal = 1
	ptr.IDVal = int32(id)
}

func (s *serverNPCs) Set328(id int, v int) *NPC {
	p := s.ByID(id)
	if p != nil {
		p.Field1312 = uint32(v)
	}
	return p
}

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

func (npc *NPC) C() unsafe.Pointer {
	return unsafe.Pointer(npc)
}
