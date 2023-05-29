package legacy

/*
#include "defs.h"
#include "GAME3_3.h"
#include "GAME4_3.h"
int nox_xxx_pickupGold_4F3A60_obj_pickup(int a1, int a2, int a3);
int nox_objectPickupAudEvent_4F3D50(nox_object_t* a1, nox_object_t* a2, int a3);
*/

import "github.com/noxworld-dev/opennox/v1/server"

var (
	Nox_objectPickupAudEvent_4F3D50 func(cobj1 *server.Object, cobj2 *server.Object, a3 int) int
)

func init() {
	server.RegisterObjectPickup("DefaultPickup", nox_xxx_pickupDefault_4F31E0)
	server.RegisterObjectPickup("FoodPickup", nox_xxx_pickupFood_4F3350)
	server.RegisterObjectPickup("UsePickup", nox_xxx_pickupUse_4F34D0)
	server.RegisterObjectPickup("ArmorPickup", nox_xxx_pickupArmor_53E7F0)
	server.RegisterObjectPickup("WeaponPickup", sub_53A720)
	server.RegisterObjectPickup("OblivionPickup", nox_xxx_sendMsgOblivionPickup_53A9C0)
	server.RegisterObjectPickup("TreasurePickup", nox_xxx_pickupTreasure_4F3580)
	server.RegisterObjectPickup("TrapPickup", nox_xxx_pickupTrap_4F3510)
	server.RegisterObjectPickup("PotionPickup", nox_xxx_pickupPotion_4F37D0)
	server.RegisterObjectPickup("GoldPickup", nox_xxx_pickupGold_4F3A60_obj_pickup)
	server.RegisterObjectPickup("AmmoPickup", nox_xxx_pickupAmmo_4F3B00)
	server.RegisterObjectPickup("SpellBookPickup", nox_xxx_pickupSpellbook_4F3C60)
	server.RegisterObjectPickup("AbilityBookPickup", nox_xxx_pickupAbilitybook_4F3CE0)
	server.RegisterObjectPickup("CrownPickup", sub_4F3400)
	server.RegisterObjectPickup("AudEventPickup", nox_objectPickupAudEvent_4F3D50)
	server.RegisterObjectPickup("AnkhTradablePickup", sub_4F3DD0)
}

// nox_objectPickupAudEvent_4F3D50
func nox_objectPickupAudEvent_4F3D50(cobj1 *nox_object_t, cobj2 *nox_object_t, a3 int) int {
	return Nox_objectPickupAudEvent_4F3D50(asObjectS(cobj1), asObjectS(cobj2), a3)
}
func Nox_xxx_pickupDefault_4F31E0(a1 *server.Object, a2 *server.Object, a3 int) int {
	return int(nox_xxx_pickupDefault_4F31E0(asObjectC(a1), asObjectC(a2), int(a3)))
}
