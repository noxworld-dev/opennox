package legacy

import (
	"github.com/noxworld-dev/opennox/v1/server"
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
	server.RegisterObjectDrop("AnkhTradableDrop", nox_xxx_dropAnkhTradable_4EE370)
}
