package opennox

/*
#include "defs.h"
#include "GAME1.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_2.h"
int nox_xxx_mapReadWriteObjData_4F4530(nox_object_t* a1p, int a2);
int nox_xxx_xfer_4F3E30(unsigned short a1, nox_object_t* a2, int a3);
*/
import "C"
import (
	"fmt"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/server"
)

type XferFunc func(obj *Object, a2 unsafe.Pointer) error

func init() {
	server.RegisterObjectXfer("DefaultXfer", C.nox_xxx_XFerDefault_4F49A0)
	server.RegisterObjectXfer("SpellPagePedestalXfer", C.nox_xxx_XFerSpellPagePedistal_4F4A20)
	server.RegisterObjectXfer("SpellRewardXfer", C.nox_xxx_XFerSpellReward_4F5F30)
	server.RegisterObjectXfer("AbilityRewardXfer", C.nox_xxx_XFerAbilityReward_4F6240)
	server.RegisterObjectXfer("FieldGuideXfer", C.nox_xxx_XFerFieldGuide_4F6390)
	server.RegisterObjectXfer("ReadableXfer", C.nox_xxx_XFerReadable_4F4AB0)
	server.RegisterObjectXfer("ExitXfer", C.nox_xxx_XFerExit_4F4B90)
	server.RegisterObjectXfer("DoorXfer", C.nox_xxx_XFerDoor_4F4CB0)
	server.RegisterObjectXfer("TriggerXfer", C.nox_xxx_unitTriggerXfer_4F4E50)
	server.RegisterObjectXfer("MonsterXfer", C.nox_xxx_XFerMonster_528DB0)
	server.RegisterObjectXfer("HoleXfer", C.nox_xxx_XFerHole_4F51D0)
	server.RegisterObjectXfer("TransporterXfer", C.nox_xxx_XFerTransporter_4F5300)
	server.RegisterObjectXfer("ElevatorXfer", C.nox_xxx_XFerElevator_4F53D0)
	server.RegisterObjectXfer("ElevatorShaftXfer", C.nox_xxx_XFerElevatorShaft_4F54A0)
	server.RegisterObjectXfer("MoverXfer", C.nox_xxx_XFerMover_4F5730)
	server.RegisterObjectXfer("GlyphXfer", C.nox_xxx_XFerGlyph_4F5890)
	server.RegisterObjectXfer("InvisibleLightXfer", C.nox_xxx_XFerInvLight_4F5AA0)
	server.RegisterObjectXfer("SentryXfer", C.nox_xxx_XFerSentry_4F5E50)
	server.RegisterObjectXfer("WeaponXfer", C.nox_xxx_XFerWeapon_4F64A0)
	server.RegisterObjectXfer("ArmorXfer", C.nox_xxx_XFerArmor_4F6860)
	server.RegisterObjectXfer("TeamXfer", C.nox_xxx_XFerTeam_4F6D20)
	server.RegisterObjectXfer("GoldXfer", C.nox_xxx_XFerGold_4F6EC0)
	server.RegisterObjectXfer("AmmoXfer", C.nox_xxx_XFerAmmo_4F6B20)
	server.RegisterObjectXfer("NPCXfer", C.nox_xxx_XFerNPC_52ADE0)
	server.RegisterObjectXfer("ObeliskXfer", C.nox_xxx_XFerObelisk_4F6F60)
	server.RegisterObjectXfer("ToxicCloudXfer", C.nox_xxx_XFerToxicCloud_4F70A0)
	server.RegisterObjectXfer("MonsterGeneratorXfer", C.nox_xxx_XFerMonsterGen_4F7130)
	server.RegisterObjectXfer("RewardMarkerXfer", C.nox_xxx_XFerRewardMarker_4F74D0)
}

//export nox_xxx_xfer_saveObj_51DF90
func nox_xxx_xfer_saveObj_51DF90(a1 *nox_object_t) C.int {
	return C.int(nox_xxx_xfer_saveObj51DF90(cryptfile.Global(), asObjectC(a1)))
}

func nox_xxx_xfer_saveObj51DF90(cf *cryptfile.CryptFile, a1p *Object) int {
	if a1p.Flags().Has(object.FlagDestroyed) {
		return 1
	}
	a1 := uint16(sub_42C2E0(C.int(a1p.TypeInd)))
	if a1 == 0 {
		return 0
	}
	cf.WriteU16(a1)
	cf.SectionStart()
	if err := a1p.CallXfer(nil); err != nil {
		mapLog.Println("nox_xxx_xfer_saveObj51DF90:", err)
		return 0
	}
	cf.SectionEnd()
	for it := a1p.FirstItem(); it != nil; it = it.NextItem() {
		nox_xxx_xfer_saveObj51DF90(cf, it)
	}
	return 1
}

//export nox_xxx_XFerDefault_4F49A0
func nox_xxx_XFerDefault_4F49A0(a1p *nox_object_t, a2 unsafe.Pointer) C.int {
	if err := nox_xxx_XFerDefault4F49A0(cryptfile.Global(), asObjectC(a1p), a2); err != nil {
		mapLog.Println("nox_xxx_XFerDefault_4F49A0:", err)
		return 0
	}
	return 1
}

func nox_xxx_XFerDefault4F49A0(cf *cryptfile.CryptFile, v1 *Object, a2 unsafe.Pointer) error {
	a1, _ := cf.ReadWriteU16(60)
	if int16(a1) > 60 {
		return fmt.Errorf("default xfer: unexpected value 1: %d", a1)
	}
	v2 := v1.Field34
	if C.nox_xxx_mapReadWriteObjData_4F4530(v1.CObj(), C.int(a1)) == 0 {
		return fmt.Errorf("default xfer: nox_xxx_mapReadWriteObjData_4F4530 failed")
	}
	if v1.Field34 == 0 || !cf.ReadOnly() {
		v1.Field34 = v2
		return nil
	}
	if C.nox_xxx_xfer_4F3E30(C.ushort(a1), v1.CObj(), C.int(v1.Field34)) == 0 {
		return fmt.Errorf("default xfer: nox_xxx_xfer_4F3E30 failed")
	}
	v1.Field34 = v2
	return nil
}

//export nox_xxx_XFer_ReadShopItem_52A840
func nox_xxx_XFer_ReadShopItem_52A840(a1 unsafe.Pointer, a2 int) {
	s := noxServer
	cf := cryptfile.Global()
	if a2 < 50 {
		// TODO: why it's unused?
		_, _ = cf.ReadU32()
	}
	b1, _ := cf.ReadU8()
	*(*uint8)(unsafe.Add(a1, 4)) = b1

	tname, _ := cf.ReadString8()
	var typ *server.ObjectType
	if tname != "" {
		typ = s.ObjectTypeByID(tname)
		*(*int32)(unsafe.Add(a1, 0)) = int32(typ.Ind())
	}
	if a2 >= 47 {
		name, _ := cf.ReadString8()
		if name != "" {
			var v4 int
			switch typ.Xfer {
			case C.nox_xxx_XFerFieldGuide_4F6390:
				v4 = s.ObjectTypeID(name)
			case C.nox_xxx_XFerAbilityReward_4F6240:
				v4 = int(s.abilities.nox_xxx_abilityNameToN_424D80(name))
			default:
				v4 = int(spell.ParseID(name))
			}
			*(*uint32)(unsafe.Add(a1, 8)) = uint32(v4)
		}
	}
	var mods [4]*noxModifierEff
	for i := range mods {
		mname, _ := cf.ReadString8()
		if mname == "" {
			continue
		}
		mod := nox_xxx_modifGetIdByName413290(mname)
		if mod >= 0 && mod != 255 {
			mods[i] = nox_xxx_modifGetDescById413330(mod)
		}
	}

	*(*unsafe.Pointer)(unsafe.Add(a1, 12)) = mods[0].C()
	*(*unsafe.Pointer)(unsafe.Add(a1, 16)) = mods[1].C()
	*(*unsafe.Pointer)(unsafe.Add(a1, 20)) = mods[2].C()
	*(*unsafe.Pointer)(unsafe.Add(a1, 24)) = mods[3].C()
}

//export nox_xxx_XFer_WriteShopItem_52A5F0
func nox_xxx_XFer_WriteShopItem_52A5F0(a1 unsafe.Pointer) {
	cf := cryptfile.Global()
	cf.WriteU8(*(*uint8)(unsafe.Add(a1, 4)))
	typ := noxServer.ObjectTypeByInd(int(*(*int32)(unsafe.Add(a1, 0))))
	cf.WriteString8(typ.ID())
	pind := int(*(*int32)(unsafe.Add(a1, 8)))
	var pname string
	switch typ.Xfer {
	case C.nox_xxx_XFerFieldGuide_4F6390:
		pname = noxServer.ObjectTypeByInd(pind).ID()
	case C.nox_xxx_XFerAbilityReward_4F6240:
		pname = Ability(pind).String()
	default:
		pname = spell.ID(pind).String()
	}
	cf.WriteString8(pname)
	mods := [4]*C.obj_412ae0_t{
		*(**C.obj_412ae0_t)(unsafe.Add(a1, 12)),
		*(**C.obj_412ae0_t)(unsafe.Add(a1, 16)),
		*(**C.obj_412ae0_t)(unsafe.Add(a1, 20)),
		*(**C.obj_412ae0_t)(unsafe.Add(a1, 24)),
	}
	for _, m := range mods {
		if m != nil {
			cf.WriteString8(GoString(m.field_0))
		} else {
			cf.WriteString8("")
		}
	}
}
