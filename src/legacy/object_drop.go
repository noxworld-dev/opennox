package legacy

import (
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_objectDropAudEvent_4EE2F0 func(cobj1 *server.Object, cobj2 *server.Object, a3 *types.Pointf) int
)

func init() {
	server.RegisterObjectDrop("DefaultDrop", Nox_xxx_dropDefault_4ED290)
	server.RegisterObjectDrop("ArmorDrop", nox_xxx_dropArmor_53EB70)
	server.RegisterObjectDrop("WeaponDrop", nox_xxx_dropWeapon_53AB10)
	server.RegisterObjectDrop("TreasureDrop", nox_xxx_dropTreasure_4ED710)
	server.RegisterObjectDrop("GlyphDrop", nox_GlyphDrop_4ED500)
	server.RegisterObjectDrop("PotionDrop", sub_4EDDE0)
	server.RegisterObjectDrop("TrapDrop", nox_xxx_dropTrap_4ED580)
	server.RegisterObjectDrop("FoodDrop", nox_xxx_dropFood_4EDE50)
	server.RegisterObjectDrop("CrownDrop", nox_xxx_dropCrown_4ED5E0)
	server.RegisterObjectDrop("AudEventDrop", nox_objectDropAudEvent_4EE2F0)
	server.RegisterObjectDrop("AnkhTradableDrop", nox_xxx_dropAnkhTradable_4EE370)
}

// nox_objectDropAudEvent_4EE2F0
func nox_objectDropAudEvent_4EE2F0(cobj1 *server.Object, cobj2 *server.Object, a3 *types.Pointf) int {
	return Nox_objectDropAudEvent_4EE2F0(asObjectS(cobj1), asObjectS(cobj2), a3)
}
