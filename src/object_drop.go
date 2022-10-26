package opennox

/*
#include "GAME3_3.h"
#include "GAME4_3.h"
int nox_objectDropAudEvent_4EE2F0(nox_object_t* a1, nox_object_t* a2, float2* a3);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func nox_xxx_parseDrop_536A20(objt *ObjectType, d *things.ProcFunc) error {
	t, ok := noxObjectDropTable[d.Name]
	if !ok {
		// TODO: add "unknown" drop as a nop types
		return nil
	}
	objt.func_drop = t.Func
	if t.ParseFunc != nil {
		t.ParseFunc(objt, d.Args)
	}
	return nil
}

var noxObjectDropTable = map[string]struct {
	Func      unsafe.Pointer
	ParseFunc func(objt *ObjectType, args []string)
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
	"AudEventDrop": {Func: C.nox_objectDropAudEvent_4EE2F0, ParseFunc: func(objt *ObjectType, args []string) {
		if len(args) != 0 {
			if snd := sound.ByName(args[0]); snd != 0 {
				objectDropSoundTable[objt.ind] = snd
			}
		}
	}},
	"AnkhTradableDrop": {Func: C.nox_xxx_dropAnkhTradable_4EE370},
}

var objectDropSoundTable = make(map[uint16]sound.ID)

//export nox_objectDropAudEvent_4EE2F0
func nox_objectDropAudEvent_4EE2F0(cobj1 *nox_object_t, cobj2 *nox_object_t, a3 *C.float2) C.int {
	if cobj1 == nil || cobj2 == nil || a3 == nil {
		return 0
	}
	ok := C.nox_xxx_dropDefault_4ED290(cobj1, cobj2, a3)
	if ok == 0 {
		return ok
	}
	obj2 := asObjectC(cobj2)
	if snd := objectDropSoundTable[uint16(obj2.objTypeInd())]; snd != 0 {
		nox_xxx_aud_501960(snd, asUnitC(cobj1), 0, 0)
	}
	return ok
}
