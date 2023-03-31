package legacy

import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Sub_4FC670                              func(a1 int)
	Nox_xxx_playerExecuteAbil_4FBB70        func(cu *server.Object, a2 int)
	Sub_4FC0B0                              func(a1 *server.Object, a2 int)
	Nox_xxx_playerCancelAbils_4FC180        func(cu *server.Object)
	Sub_4FC300                              func(cu *server.Object, a2 int)
	Sub_4FC070                              func(a1 *server.Object, a2, dt int)
	Sub_4FC030                              func(a1 *server.Object, a2 int) int
	Sub_4FC440                              func(a1 *server.Object, a2 int)
	Sub_4FBE60                              func(a1 unsafe.Pointer, abil int) int
	Sub_4FBEA0                              func(a1 unsafe.Pointer, abil, cd int)
	Nox_xxx_abilityGetName_0_425260         func(ca int) string
	Nox_common_playerIsAbilityActive_4FC250 func(a1 *server.Object, a2 int) int
	Nox_xxx_probablyWarcryCheck_4FC3E0      func(a1 *server.Object, a2 int) int
	Nox_xxx_abilityCooldown_4252D0          func(ca int) int
	Sub_4252F0                              func(ca int) string
	Nox_xxx_spellGetAbilityIcon_425310      func(abil, icon int) noxrender.ImageHandle
	Nox_xxx_bookFirstKnownAbil_425330       func() int
	Nox_xxx_bookNextKnownAbil_425350        func(a1 int) int
	Sub_425450                              func(a1 int) int
	Nox_xxx_netAbilRepotState_4D8100        func(a1 *server.Object, a2 server.Ability, a3 byte)
)

//export sub_4FC670
func sub_4FC670(a1 int) { Sub_4FC670(a1) }

//export nox_xxx_playerExecuteAbil_4FBB70
func nox_xxx_playerExecuteAbil_4FBB70(cu *nox_object_t, a2 int) {
	Nox_xxx_playerExecuteAbil_4FBB70(asObjectS(cu), a2)
}

//export sub_4FC0B0
func sub_4FC0B0(a1 *nox_object_t, a2 int) { Sub_4FC0B0(asObjectS(a1), a2) }

//export nox_xxx_playerCancelAbils_4FC180
func nox_xxx_playerCancelAbils_4FC180(cu *nox_object_t) {
	Nox_xxx_playerCancelAbils_4FC180(asObjectS(cu))
}

//export sub_4FC300
func sub_4FC300(cu *nox_object_t, a2 int) { Sub_4FC300(asObjectS(cu), a2) }

//export sub_4FC070
func sub_4FC070(a1 *nox_object_t, a2, dt int) { Sub_4FC070(asObjectS(a1), a2, dt) }

//export sub_4FC030
func sub_4FC030(a1 *nox_object_t, a2 int) int { return Sub_4FC030(asObjectS(a1), a2) }

//export sub_4FC440
func sub_4FC440(a1 *nox_object_t, a2 int) { Sub_4FC440(asObjectS(a1), a2) }

//export nox_xxx_abilityGetName_425250
func nox_xxx_abilityGetName_425250(a1 int) *C.char {
	return internCStr(server.Ability(a1).String())
}

//export sub_4FBE60
func sub_4FBE60(a1 unsafe.Pointer, abil int) int { return Sub_4FBE60(a1, abil) }

//export sub_4FBEA0
func sub_4FBEA0(a1 unsafe.Pointer, abil, cd int) { Sub_4FBEA0(a1, abil, cd) }

//export nox_xxx_abilityGetName_0_425260
func nox_xxx_abilityGetName_0_425260(ca int) *wchar2_t {
	return internWStr(Nox_xxx_abilityGetName_0_425260(ca))
}

//export nox_common_playerIsAbilityActive_4FC250
func nox_common_playerIsAbilityActive_4FC250(a1 *nox_object_t, a2 int) int {
	return Nox_common_playerIsAbilityActive_4FC250(asObjectS(a1), a2)
}

//export nox_xxx_probablyWarcryCheck_4FC3E0
func nox_xxx_probablyWarcryCheck_4FC3E0(a1 *nox_object_t, a2 int) int {
	return Nox_xxx_probablyWarcryCheck_4FC3E0(asObjectS(a1), a2)
}

//export nox_xxx_abilityCooldown_4252D0
func nox_xxx_abilityCooldown_4252D0(ca int) int { return Nox_xxx_abilityCooldown_4252D0(ca) }

//export sub_4252F0
func sub_4252F0(ca int) *wchar2_t { return internWStr(Sub_4252F0(ca)) }

//export nox_xxx_spellGetAbilityIcon_425310
func nox_xxx_spellGetAbilityIcon_425310(abil, icon int) *nox_video_bag_image_t {
	return (*nox_video_bag_image_t)(Nox_xxx_spellGetAbilityIcon_425310(abil, icon))
}

//export nox_xxx_bookFirstKnownAbil_425330
func nox_xxx_bookFirstKnownAbil_425330() int { return Nox_xxx_bookFirstKnownAbil_425330() }

//export nox_xxx_bookNextKnownAbil_425350
func nox_xxx_bookNextKnownAbil_425350(a1 int) int { return Nox_xxx_bookNextKnownAbil_425350(a1) }

//export sub_425450
func sub_425450(a1 int) int { return Sub_425450(a1) }

//export nox_xxx_netAbilRepotState_4D8100
func nox_xxx_netAbilRepotState_4D8100(a1 *nox_object_t, a2, a3 C.char) {
	Nox_xxx_netAbilRepotState_4D8100(asObjectS(a1), server.Ability(a2), byte(a3))
}
