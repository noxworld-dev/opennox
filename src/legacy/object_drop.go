package legacy

/*
#include "GAME3_3.h"
#include "GAME4_3.h"
int nox_objectDropAudEvent_4EE2F0(nox_object_t* a1, nox_object_t* a2, float2* a3);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_objectDropAudEvent_4EE2F0 func(cobj1 *server.Object, cobj2 *server.Object, a3 *types.Pointf) int
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
func nox_objectDropAudEvent_4EE2F0(cobj1 *nox_object_t, cobj2 *nox_object_t, a3 *C.float2) int {
	return Nox_objectDropAudEvent_4EE2F0(asObjectS(cobj1), asObjectS(cobj2), (*types.Pointf)(unsafe.Pointer(a3)))
}

func Nox_xxx_dropDefault_4ED290(obj1 *server.Object, obj2 *server.Object, a3 *types.Pointf) int {
	return int(C.nox_xxx_dropDefault_4ED290(asObjectC(obj1), asObjectC(obj2), (*C.float2)(unsafe.Pointer(a3))))
}
