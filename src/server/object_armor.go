package server

import (
	"strings"

	"github.com/noxworld-dev/opennox-lib/strman"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

type armorRecord struct {
	Name             string    // 0, 0
	NameStr          strman.ID // 1, 4
	TypeInd          int       // 2, 8
	Bit              uint32    // 3, 12
	DestroyedName    string    // 4, 16
	DestroyedTypeInd int       // 5, 20
}

type serverArmor struct {
	table [PlayerArmorCnt]armorRecord
	sm    *strman.StringManager
	ready bool
}

func (s *Server) Sub4537F0_Armor() {
	for i := 0; i < PlayerArmorCnt; i++ {
		if ind := s.Armor.Sub_415CD0(1 << i); ind != 0 {
			s.Types.ByInd(ind).SetAllowed(true)
		}
	}
}

func (s *Server) Sub415EC0(id string) *ObjectType {
	v1 := s.Armor.Sub_415DF0(id)
	if v1 == 0 {
		return nil
	}
	v2 := s.Armor.Sub_415CD0(v1)
	if v2 == 0 {
		return nil
	}
	return s.Types.ByInd(v2)
}

func (s *Server) Nox_xxx_equipArmor_415AB0() {
	if s.Armor.ready {
		return
	}
	s.Armor.sm = s.Strings()
	s.Armor.table = armorTable
	for i := range s.Armor.table {
		it := &s.Armor.table[i]
		if it.DestroyedName == "" {
			it.DestroyedName = "INVALID"
		}
		if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameHost) {
			it.TypeInd = s.Types.IndByID(it.Name)
			it.DestroyedTypeInd = s.Types.IndByID(it.DestroyedName)
		} else {
			it.TypeInd = s.Types.ClientTypeByID(it.Name)
			it.DestroyedTypeInd = s.Types.ClientTypeByID(it.DestroyedName)
		}
		if it.TypeInd == 0 {
			Log.Printf("cannot find type ID for armor %q", it.Name)
		}
	}
	s.Armor.ready = true
}

func (s *serverArmor) sub_415C90(item *Object) int {
	for i := range s.table {
		it := &s.table[i]
		if it.TypeInd == int(item.TypeInd) {
			return i
		}
	}
	return -1
}

func (s *serverArmor) Sub_415CD0(bit uint32) int {
	for i := range s.table {
		it := &s.table[i]
		if it.Bit == bit {
			return it.TypeInd
		}
	}
	return 0
}

func (s *serverArmor) Sub_415D10(typ int) uint32 {
	for i := range s.table {
		it := &s.table[i]
		if it.TypeInd == typ {
			return it.Bit
		}
	}
	return 0
}

func (s *serverArmor) Nox_xxx_unitArmorInventoryEquipFlags_415C70(obj *Object) uint32 {
	v1 := s.sub_415C90(obj)
	if v1 < 0 {
		return 0
	}
	return s.table[v1].Bit
}

func (s *serverArmor) Sub_415DF0(name string) uint32 {
	name = strings.ToLower(name)
	for i := range s.table {
		it := &s.table[i]
		if strings.ToLower(it.Name) == name {
			return it.Bit
		}
	}
	return 0
}

func (s *serverArmor) Sub_415E40(bit uint32) string {
	for i := range s.table {
		it := &s.table[i]
		if it.Bit == bit {
			return it.Name
		}
	}
	return ""
}

func (s *serverArmor) Sub_415B60(obj *Object) string {
	for i := range s.table {
		it := &s.table[i]
		if it.TypeInd == int(obj.TypeInd) {
			return s.sm.GetStringInFile(it.NameStr, "ArmrLook.c")
		}
	}
	return s.sm.GetStringInFile("result:ERROR", "ArmrLook.c")
}

var armorTable = [PlayerArmorCnt]armorRecord{
	{"LeatherArmor", "LeatherArmorName", 0, 0x8000, "LeatherArmorDestroyed", 0},
	{"ChainTunic", "ChainTunicName", 0, 0x10000, "", 0},
	{"Breastplate", "SteelBreastplateName", 0, 0x20000, "BreastplateDestroyed", 0},
	{"LeatherHelm", "LeatherHelmetName", 0, 0x200000, "LeatherHelmDestroyed", 0},
	{"SteelHelm", "SteelHelmetName", 0, 0x400000, "SteelHelmDestroyed", 0},
	{"SteelShield", "SteelShieldName", 0, 0x2000000, "SteelShieldDestroyed", 0},
	{"WoodenShield", "WoodenShieldName", 0, 0x1000000, "WoodenShieldDestroyed", 0},
	{"StreetShirt", "StreetShirtName", 0, 0x400, "", 0},
	{"StreetPants", "StreetPantsName", 0, 0x4, "", 0},
	{"StreetSneakers", "StreetSneakersName", 0, 0x1, "", 0},
	{"LeatherBoots", "LeatherBootsName", 0, 0x40, "", 0},
	{"LeatherArmoredBoots", "LeatherArmoredBootsName", 0, 0x80, "", 0},
	{"PlateBoots", "PlateBootsName", 0, 0x100, "", 0},
	{"MedievalPants", "MedievalPantsName", 0, 0x8, "", 0},
	{"LeatherLeggings", "LeatherLeggingsName", 0, 0x10, "", 0},
	{"ChainLeggings", "ChainLeggingsName", 0, 0x20, "", 0},
	{"PlateLeggings", "PlateLeggingsName", 0, 0x200, "", 0},
	{"MedievalShirt", "MedievalShirtName", 0, 0x800, "", 0},
	{"WizardRobe", "WizardRobeName", 0, 0x4000, "", 0},
	{"LeatherArmbands", "LeatherArmbandsName", 0, 0x1000, "", 0},
	{"PlateArms", "PlateArmsName", 0, 0x2000, "", 0},
	{"MedievalCloak", "MedievalCloakName", 0, 0x2, "", 0},
	{"ChainCoif", "ChainCoifName", 0, 0x40000, "", 0},
	{"WizardHelm", "WizardHelmName", 0, 0x80000, "", 0},
	{"ConjurerHelm", "ConjurerHelmName", 0, 0x100000, "", 0},
	{"OrnateHelm", "OrnateHelmName", 0, 0x800000, "", 0},
}
