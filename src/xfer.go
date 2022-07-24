package opennox

/*
#include "defs.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_2.h"
short sub_42C2E0(int a1);
int nox_xxx_mapReadWriteObjData_4F4530(nox_object_t* a1p, int a2);
int nox_xxx_xfer_4F3E30(unsigned short a1, nox_object_t* a2, int a3);
*/
import "C"
import (
	"fmt"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
)

type XferFunc func(obj *Object, a2 unsafe.Pointer) error

var noxObjectXfers = map[string]unsafe.Pointer{
	"DefaultXfer":           C.nox_xxx_XFerDefault_4F49A0,
	"SpellPagePedestalXfer": C.nox_xxx_XFerSpellPagePedistal_4F4A20,
	"SpellRewardXfer":       C.nox_xxx_XFerSpellReward_4F5F30,
	"AbilityRewardXfer":     C.nox_xxx_XFerAbilityReward_4F6240,
	"FieldGuideXfer":        C.nox_xxx_XFerFieldGuide_4F6390,
	"ReadableXfer":          C.nox_xxx_XFerReadable_4F4AB0,
	"ExitXfer":              C.nox_xxx_XFerExit_4F4B90,
	"DoorXfer":              C.nox_xxx_XFerDoor_4F4CB0,
	"TriggerXfer":           C.nox_xxx_unitTriggerXfer_4F4E50,
	"MonsterXfer":           C.nox_xxx_XFerMonster_528DB0,
	"HoleXfer":              C.nox_xxx_XFerHole_4F51D0,
	"TransporterXfer":       C.nox_xxx_XFerTransporter_4F5300,
	"ElevatorXfer":          C.nox_xxx_XFerElevator_4F53D0,
	"ElevatorShaftXfer":     C.nox_xxx_XFerElevatorShaft_4F54A0,
	"MoverXfer":             C.nox_xxx_XFerMover_4F5730,
	"GlyphXfer":             C.nox_xxx_XFerGlyph_4F5890,
	"InvisibleLightXfer":    C.nox_xxx_XFerInvLight_4F5AA0,
	"SentryXfer":            C.nox_xxx_XFerSentry_4F5E50,
	"WeaponXfer":            C.nox_xxx_XFerWeapon_4F64A0,
	"ArmorXfer":             C.nox_xxx_XFerArmor_4F6860,
	"TeamXfer":              C.nox_xxx_XFerTeam_4F6D20,
	"GoldXfer":              C.nox_xxx_XFerGold_4F6EC0,
	"AmmoXfer":              C.nox_xxx_XFerAmmo_4F6B20,
	"NPCXfer":               C.nox_xxx_XFerNPC_52ADE0,
	"ObeliskXfer":           C.nox_xxx_XFerObelisk_4F6F60,
	"ToxicCloudXfer":        C.nox_xxx_XFerToxicCloud_4F70A0,
	"MonsterGeneratorXfer":  C.nox_xxx_XFerMonsterGen_4F7130,
	"RewardMarkerXfer":      C.nox_xxx_XFerRewardMarker_4F74D0,
}

func nox_xxx_parseXFer_5360A0(objt *ObjectType, _ *MemFile, str string, _ []byte) error {
	name := firstWord(str)
	xfer := noxObjectXfers[name]
	if xfer == nil {
		return fmt.Errorf("unsupported xfer: %q", name)
	}
	objt.func_xfer = xfer
	return nil
}

//export nox_xxx_xfer_saveObj_51DF90
func nox_xxx_xfer_saveObj_51DF90(a1 *nox_object_t) C.int {
	return C.int(nox_xxx_xfer_saveObj51DF90(asObjectC(a1)))
}

func nox_xxx_xfer_saveObj51DF90(a1p *Object) int {
	if a1p.Flags().Has(object.FlagDestroyed) {
		return 1
	}
	a1 := uint16(C.sub_42C2E0(C.int(a1p.objTypeInd())))
	if a1 == 0 {
		return 0
	}
	cryptFileWriteU16(a1)
	nox_xxx_crypt_426C90()
	if err := a1p.callXfer(nil); err != nil {
		mapLog.Println("nox_xxx_xfer_saveObj51DF90:", err)
		return 0
	}
	nox_xxx_crypt_426D40()
	for it := a1p.FirstItem(); it != nil; it = it.NextItem() {
		nox_xxx_xfer_saveObj51DF90(it)
	}
	return 1
}

//export nox_xxx_XFerDefault_4F49A0
func nox_xxx_XFerDefault_4F49A0(a1p *nox_object_t, a2 unsafe.Pointer) C.int {
	if err := nox_xxx_XFerDefault4F49A0(asObjectC(a1p), a2); err != nil {
		mapLog.Println("nox_xxx_XFerDefault_4F49A0:", err)
		return 0
	}
	return 1
}

func nox_xxx_XFerDefault4F49A0(v1 *Object, a2 unsafe.Pointer) error {
	a1, _ := cryptFileReadWriteU16(60)
	if int16(a1) > 60 {
		return fmt.Errorf("default xfer: unexpected value 1: %d", a1)
	}
	v2 := v1.field_34
	if C.nox_xxx_mapReadWriteObjData_4F4530(v1.CObj(), C.int(a1)) == 0 {
		return fmt.Errorf("default xfer: nox_xxx_mapReadWriteObjData_4F4530 failed")
	}
	if v1.field_34 == 0 || nox_xxx_cryptGetXxx() != 1 {
		v1.field_34 = v2
		return nil
	}
	if C.nox_xxx_xfer_4F3E30(C.ushort(a1), v1.CObj(), C.int(v1.field_34)) == 0 {
		return fmt.Errorf("default xfer: nox_xxx_xfer_4F3E30 failed")
	}
	v1.field_34 = v2
	return nil
}
