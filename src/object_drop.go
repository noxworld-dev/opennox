package opennox

/*
#include "GAME3_3.h"
#include "GAME4_3.h"
int nox_objectDropAudEvent_4EE2F0(nox_object_t* a1, nox_object_t* a2, float2* a3);
*/
import "C"
import (
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectDrop("DefaultDrop", C.nox_xxx_dropDefault_4ED290)
	server.RegisterObjectDrop("ArmorDrop", C.nox_xxx_dropArmor_53EB70)
	server.RegisterObjectDrop("WeaponDrop", C.nox_xxx_dropWeapon_53AB10)
	server.RegisterObjectDrop("TreasureDrop", C.nox_xxx_dropTreasure_4ED710)
	server.RegisterObjectDrop("GlyphDrop", C.sub_4ED500)
	server.RegisterObjectDrop("PotionDrop", C.sub_4EDDE0)
	server.RegisterObjectDrop("TrapDrop", C.nox_xxx_dropTrap_4ED580)
	server.RegisterObjectDrop("FoodDrop", C.nox_xxx_dropFood_4EDE50)
	server.RegisterObjectDrop("CrownDrop", C.nox_xxx_dropCrown_4ED5E0)
	server.RegisterObjectDrop("AudEventDrop", C.nox_objectDropAudEvent_4EE2F0)
	server.RegisterObjectDrop("AnkhTradableDrop", C.nox_xxx_dropAnkhTradable_4EE370)
}

//export nox_objectDropAudEvent_4EE2F0
func nox_objectDropAudEvent_4EE2F0(cobj1 *nox_object_t, cobj2 *nox_object_t, a3 *C.float2) C.int {
	s := noxServer
	if cobj1 == nil || cobj2 == nil || a3 == nil {
		return 0
	}
	ok := C.nox_xxx_dropDefault_4ED290(cobj1, cobj2, a3)
	if ok == 0 {
		return ok
	}
	obj2 := asObjectC(cobj2)
	if snd := s.DropSound(obj2.TypeInd); snd != 0 {
		s.AudioEventObj(snd, asObjectC(cobj1), 0, 0)
	}
	return ok
}
