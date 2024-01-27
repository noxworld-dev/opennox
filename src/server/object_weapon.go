package server

import (
	"strings"

	"github.com/noxworld-dev/opennox-lib/strman"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

type weaponRecord struct {
	Name    string // 0, 0
	TypeInd int    // 1, 4
	Bit     uint32 // 2, 8
}

type serverWeapons struct {
	table [PlayerWeaponCnt]weaponRecord
	sm    *strman.StringManager
	ready bool
}

func (s *Server) Sub4537F0_Weapon() {
	for i := 0; i < PlayerWeaponCnt; i++ {
		if ind := s.Weapons.Sub_415840(1 << i); ind != 0 {
			s.Types.ByInd(ind).SetAllowed(true)
		}
	}
}

func (s *Server) Sub415A30(a1 string) *ObjectType {
	v1 := s.Weapons.Sub_415910(a1)
	if v1 == 0 {
		return nil
	}
	v2 := s.Weapons.Sub_415840(v1)
	if v2 == 0 {
		return nil
	}
	return s.Types.ByInd(v2)
}

func (s *Server) Nox_xxx_equipWeapon_4157C0() {
	if s.Weapons.ready {
		return
	}
	s.Weapons.sm = s.Strings()
	s.Weapons.table = weaponTable
	for i := range s.Weapons.table {
		it := &s.Weapons.table[i]
		if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameHost) {
			it.TypeInd = s.Types.IndByID(it.Name)
		} else {
			it.TypeInd = s.Types.ClientTypeByID(it.Name)
		}
	}
	s.Weapons.ready = true
}

func (s *serverWeapons) Sub_415840(bit uint32) int {
	for i := range s.table {
		it := &s.table[i]
		if it.Bit == bit {
			return it.TypeInd
		}
	}
	return 0
}

func (s *serverWeapons) Nox_xxx_ammoCheck_415880(typ int) uint32 {
	for i := range s.table {
		it := &s.table[i]
		if it.TypeInd == typ {
			return it.Bit
		}
	}
	return 0
}

func (s *serverWeapons) Sub_415910(name string) uint32 {
	name = strings.ToLower(name)
	for i := range s.table {
		it := &s.table[i]
		if strings.ToLower(it.Name) == name {
			return it.Bit
		}
	}
	return 0
}

func (s *serverWeapons) Nox_xxx_weaponInventoryEquipFlags_415820(item *Object) uint32 {
	if item == nil {
		return 0
	}
	return s.Nox_xxx_ammoCheck_415880(int(item.TypeInd))
}

func (s *serverWeapons) Sub_4159B0(bit uint32) string {
	for i := range s.table {
		it := &s.table[i]
		if it.Bit == bit {
			return it.Name
		}
	}
	return ""
}

var weaponTable = [PlayerWeaponCnt]weaponRecord{
	{"Bow", 0, 0x4},
	{"CrossBow", 0, 0x8},
	{"Longsword", 0, 0x200},
	{"GreatSword", 0, 0x400},
	{"MorningStar", 0, 0x800},
	{"BattleAxe", 0, 0x1000},
	{"OgreAxe", 0, 0x2000},
	{"Sword", 0, 0x100},
	{"WarHammer", 0, 0x4000},
	{"RoundChakram", 0, 0x40},
	{"FanChakram", 0, 0x80},
	{"Quiver", 0, 0x2},
	{"StaffWooden", 0, 0x8000},
	{"SulphorousFlareWand", 0, 0x10000},
	{"SulphorousShowerWand", 0, 0x20000},
	{"LesserFireballWand", 0, 0x80000},
	{"DemonsBreathWand", 0, 0x80000},
	{"DeathRayWand", 0, 0x400000},
	{"InfinitePainWand", 0, 0x200000},
	{"FireStormWand", 0, 0x100000},
	{"ForceWand", 0, 0x40000},
	{"OblivionHalberd", 0, 0x800000},
	{"OblivionHeart", 0, 0x1000000},
	{"OblivionWierdling", 0, 0x2000000},
	{"OblivionOrb", 0, 0x4000000},
	{"Flag", 0, 0x1},
}
