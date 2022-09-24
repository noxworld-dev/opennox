package opennox

/*
#include "defs.h"
#include "GAME3_3.h"
#include "GAME4_3.h"
void sub_536AC0(char* val, nox_objectType_t* a1);
*/
import "C"
import (
	"strings"
	"unsafe"
)

func nox_xxx_parseDrop_536A20(objt *ObjectType, _ *MemFile, str string, _ []byte) error {
	name := str
	if i := strings.IndexAny(str, " \t\n\r"); i > 0 {
		name = str[:i]
		str = str[i+1:]
	}
	t, ok := noxObjectDropTable[name]
	if !ok {
		// TODO: add "unknown" drop as a nop types
		return nil
	}
	objt.func_drop = t.Func
	if t.ParseFunc != nil {
		t.ParseFunc(objt, str)
	}
	return nil
}

var noxObjectDropTable = map[string]struct {
	Func      unsafe.Pointer
	ParseFunc func(objt *ObjectType, val string)
}{
	"DefaultDrop":  {Func: C.nox_xxx_dropDefault_4ED290},
	"ArmorDrop":    {Func: C.nox_xxx_dropArmor_53EB70},
	"WeaponDrop":   {Func: C.nox_xxx_dropWeapon_53AB10},
	"TreasureDrop": {Func: C.nox_xxx_dropTreasure_4ED710},
	"GlyphDrop":    {Func: C.sub_4ED500},
	"PotionDrop":   {Func: C.sub_4EDDE0},
	"TrapDrop":     {Func: C.nox_xxx_dropTrap_4ED580},
	"FoodDrop":     {Func: C.nox_xxx_dropFood_4EDE50},
	"CrownDrop":    {Func: C.nox_xxx_dropCrown_4ED5E0},
	"AudEventDrop": {Func: C.sub_4EE2F0, ParseFunc: func(objt *ObjectType, val string) {
		cstr := CString(val)
		defer StrFree(cstr)
		C.sub_536AC0(cstr, objt.C())
	}},
	"AnkhTradableDrop": {Func: C.nox_xxx_dropAnkhTradable_4EE370},
}
