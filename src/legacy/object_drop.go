package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_objectDropAudEvent_4EE2F0 func(cobj1 *server.Object, cobj2 *server.Object, a3 *types.Pointf) int
)

func init() {
	server.RegisterObjectDrop("DefaultDrop", ccall.FuncAddr(nox_xxx_dropDefault_4ED290))
	server.RegisterObjectDrop("ArmorDrop", ccall.FuncAddr(nox_xxx_dropArmor_53EB70))
	server.RegisterObjectDrop("WeaponDrop", ccall.FuncAddr(nox_xxx_dropWeapon_53AB10))
	server.RegisterObjectDrop("TreasureDrop", ccall.FuncAddr(nox_xxx_dropTreasure_4ED710))
	server.RegisterObjectDrop("GlyphDrop", ccall.FuncAddr(nox_GlyphDrop_4ED500))
	server.RegisterObjectDrop("PotionDrop", ccall.FuncAddr(sub_4EDDE0))
	server.RegisterObjectDrop("TrapDrop", ccall.FuncAddr(nox_xxx_dropTrap_4ED580))
	server.RegisterObjectDrop("FoodDrop", ccall.FuncAddr(nox_xxx_dropFood_4EDE50))
	server.RegisterObjectDrop("CrownDrop", ccall.FuncAddr(nox_xxx_dropCrown_4ED5E0))
	server.RegisterObjectDrop("AudEventDrop", ccall.FuncAddr(nox_objectDropAudEvent_4EE2F0))
	server.RegisterObjectDrop("AnkhTradableDrop", ccall.FuncAddr(nox_xxx_dropAnkhTradable_4EE370))
}

// nox_objectDropAudEvent_4EE2F0
func nox_objectDropAudEvent_4EE2F0(cobj1 *server.Object, cobj2 *server.Object, a3 *float2) int {
	return Nox_objectDropAudEvent_4EE2F0(asObjectS(cobj1), asObjectS(cobj2), (*types.Pointf)(unsafe.Pointer(a3)))
}

func Nox_xxx_dropDefault_4ED290(obj1 *server.Object, obj2 *server.Object, a3 *types.Pointf) int {
	return int(nox_xxx_dropDefault_4ED290(asObjectC(obj1), asObjectC(obj2), (*float2)(unsafe.Pointer(a3))))
}
