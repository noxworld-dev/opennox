package opennox

/*
#include "defs.h"
#include "GAME3_3.h"
#include "GAME4_3.h"
int nox_xxx_pickupGold_4F3A60_obj_pickup(int a1, int a2, int a3);
int nox_objectPickupAudEvent_4F3D50(nox_object_t* a1, nox_object_t* a2, int a3);
*/
import "C"
import (
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func nox_xxx_parsePickup_536710(objt *ObjectType, _ *MemFile, str string, _ []byte) error {
	name := str
	if i := strings.IndexAny(str, " \t\n\r"); i > 0 {
		name = str[:i]
		str = str[i+1:]
	}
	t, ok := noxObjectPickupTable[name]
	if !ok {
		// TODO: add "unknown" pickup as a nop types
		return nil
	}
	objt.func_pickup = t.Func
	if t.ParseFunc != nil {
		t.ParseFunc(objt, str)
	}
	return nil
}

var noxObjectPickupTable = map[string]struct {
	Func      unsafe.Pointer
	ParseFunc func(objt *ObjectType, val string)
}{
	"DefaultPickup":     {Func: C.nox_xxx_pickupDefault_4F31E0},
	"FoodPickup":        {Func: C.nox_xxx_pickupFood_4F3350},
	"UsePickup":         {Func: C.nox_xxx_pickupUse_4F34D0},
	"ArmorPickup":       {Func: C.nox_xxx_pickupArmor_53E7F0},
	"WeaponPickup":      {Func: C.sub_53A720},
	"OblivionPickup":    {Func: C.nox_xxx_sendMsgOblivionPickup_53A9C0},
	"TreasurePickup":    {Func: C.nox_xxx_pickupTreasure_4F3580},
	"TrapPickup":        {Func: C.nox_xxx_pickupTrap_4F3510},
	"PotionPickup":      {Func: C.nox_xxx_pickupPotion_4F37D0},
	"GoldPickup":        {Func: C.nox_xxx_pickupGold_4F3A60_obj_pickup},
	"AmmoPickup":        {Func: C.nox_xxx_pickupAmmo_4F3B00},
	"SpellBookPickup":   {Func: C.nox_xxx_pickupSpellbook_4F3C60},
	"AbilityBookPickup": {Func: C.nox_xxx_pickupAbilitybook_4F3CE0},
	"CrownPickup":       {Func: C.sub_4F3400},
	"AudEventPickup": {Func: C.nox_objectPickupAudEvent_4F3D50, ParseFunc: func(objt *ObjectType, val string) {
		if snd := sound.ByName(val); snd != 0 {
			objectPickupSoundTable[objt.ind] = snd
		}
	}},
	"AnkhTradablePickup": {Func: C.sub_4F3DD0},
}

var objectPickupSoundTable = make(map[uint16]sound.ID)

//export nox_objectPickupAudEvent_4F3D50
func nox_objectPickupAudEvent_4F3D50(cobj1 *nox_object_t, cobj2 *nox_object_t, a3 C.int) C.int {
	if cobj1 == nil || cobj2 == nil {
		return 0
	}
	ok := C.nox_xxx_pickupDefault_4F31E0(cobj1, cobj2, a3)
	if ok == 0 {
		return ok
	}
	obj2 := asObjectC(cobj2)
	if snd := objectPickupSoundTable[uint16(obj2.objTypeInd())]; snd != 0 {
		nox_xxx_aud_501960(snd, asUnitC(cobj1), 0, 0)
	}
	return ok
}
