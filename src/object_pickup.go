package opennox

/*
#include "defs.h"
#include "GAME3_3.h"
#include "GAME4_3.h"
void sub_5367B0(char* val, nox_objectType_t* a1);
int nox_xxx_pickupGold_4F3A60_obj_pickup(int a1, int a2, int a3);
*/
import "C"
import (
	"strings"
	"unsafe"
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
	"AudEventPickup": {Func: C.sub_4F3D50, ParseFunc: func(objt *ObjectType, val string) {
		cstr := CString(val)
		defer StrFree(cstr)
		C.sub_5367B0(cstr, objt.C())
	}},
	"AnkhTradablePickup": {Func: C.sub_4F3DD0},
}
