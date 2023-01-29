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
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectPickup("DefaultPickup", C.nox_xxx_pickupDefault_4F31E0)
	server.RegisterObjectPickup("FoodPickup", C.nox_xxx_pickupFood_4F3350)
	server.RegisterObjectPickup("UsePickup", C.nox_xxx_pickupUse_4F34D0)
	server.RegisterObjectPickup("ArmorPickup", C.nox_xxx_pickupArmor_53E7F0)
	server.RegisterObjectPickup("WeaponPickup", C.sub_53A720)
	server.RegisterObjectPickup("OblivionPickup", C.nox_xxx_sendMsgOblivionPickup_53A9C0)
	server.RegisterObjectPickup("TreasurePickup", C.nox_xxx_pickupTreasure_4F3580)
	server.RegisterObjectPickup("TrapPickup", C.nox_xxx_pickupTrap_4F3510)
	server.RegisterObjectPickup("PotionPickup", C.nox_xxx_pickupPotion_4F37D0)
	server.RegisterObjectPickup("GoldPickup", C.nox_xxx_pickupGold_4F3A60_obj_pickup)
	server.RegisterObjectPickup("AmmoPickup", C.nox_xxx_pickupAmmo_4F3B00)
	server.RegisterObjectPickup("SpellBookPickup", C.nox_xxx_pickupSpellbook_4F3C60)
	server.RegisterObjectPickup("AbilityBookPickup", C.nox_xxx_pickupAbilitybook_4F3CE0)
	server.RegisterObjectPickup("CrownPickup", C.sub_4F3400)
	server.RegisterObjectPickup("AudEventPickup", C.nox_objectPickupAudEvent_4F3D50)
	server.RegisterObjectPickup("AnkhTradablePickup", C.sub_4F3DD0)
}

//export nox_objectPickupAudEvent_4F3D50
func nox_objectPickupAudEvent_4F3D50(cobj1 *nox_object_t, cobj2 *nox_object_t, a3 int) int {
	s := noxServer
	if cobj1 == nil || cobj2 == nil {
		return 0
	}
	ok := int(C.nox_xxx_pickupDefault_4F31E0(cobj1, cobj2, C.int(a3)))
	if ok == 0 {
		return ok
	}
	obj2 := asObjectC(cobj2)
	if snd := s.PickupSound(obj2.TypeInd); snd != 0 {
		s.AudioEventObj(snd, asObjectC(cobj1), 0, 0)
	}
	return ok
}
