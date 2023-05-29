package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Sub_4FC670                         func(a1 int)
	Nox_xxx_playerExecuteAbil_4FBB70   func(cu *server.Object, a2 int)
	Sub_4FC0B0                         func(a1 *server.Object, a2 int)
	Nox_xxx_playerCancelAbils_4FC180   func(cu *server.Object)
	Sub_4FC300                         func(cu *server.Object, a2 int)
	Nox_xxx_abilityGetName_0_425260    func(ca int) string
	Nox_xxx_abilityCooldown_4252D0     func(ca int) int
	Sub_4252F0                         func(ca int) string
	Nox_xxx_spellGetAbilityIcon_425310 func(abil, icon int) noxrender.ImageHandle
	Nox_xxx_bookFirstKnownAbil_425330  func() int
	Nox_xxx_bookNextKnownAbil_425350   func(a1 int) int
	Sub_425450                         func(a1 int) int
	Nox_xxx_netAbilRepotState_4D8100   func(a1 *server.Object, a2 server.Ability, a3 byte)
)

// sub_4FC670
func sub_4FC670(a1 int) { Sub_4FC670(a1) }

// nox_xxx_playerExecuteAbil_4FBB70
func nox_xxx_playerExecuteAbil_4FBB70(cu *nox_object_t, a2 int) {
	Nox_xxx_playerExecuteAbil_4FBB70(asObjectS(cu), a2)
}

// sub_4FC0B0
func sub_4FC0B0(a1 *nox_object_t, a2 int) { Sub_4FC0B0(asObjectS(a1), a2) }

// nox_xxx_playerCancelAbils_4FC180
func nox_xxx_playerCancelAbils_4FC180(cu *nox_object_t) {
	Nox_xxx_playerCancelAbils_4FC180(asObjectS(cu))
}

// sub_4FC300
func sub_4FC300(cu *nox_object_t, a2 int) { Sub_4FC300(asObjectS(cu), a2) }

// sub_4FC070
func sub_4FC070(a1 *nox_object_t, a2, dt int) {
	GetServer().S().Abils.Sub4FC070(asObjectS(a1), server.Ability(a2), dt)
}

// sub_4FC030
func sub_4FC030(a1 *nox_object_t, a2 int) int {
	return GetServer().S().Abils.Sub4FC030(asObjectS(a1), server.Ability(a2))
}

// sub_4FC440
func sub_4FC440(a1 *nox_object_t, a2 int) {
	GetServer().S().Abils.Sub4FC440(asObjectS(a1), server.Ability(a2))
}

// nox_xxx_abilityGetName_425250
func nox_xxx_abilityGetName_425250(a1 int) *char {
	return internCStr(server.Ability(a1).String())
}

// sub_4FBE60
func sub_4FBE60(a1 unsafe.Pointer, abil int) int {
	return GetServer().S().Abils.GetCooldown(a1, server.Ability(abil))
}

// sub_4FBEA0
func sub_4FBEA0(a1 unsafe.Pointer, abil, cd int) {
	GetServer().S().Abils.SetCooldown(a1, server.Ability(abil), cd)
}

// nox_xxx_abilityGetName_0_425260
func nox_xxx_abilityGetName_0_425260(ca int) *wchar2_t {
	return internWStr(Nox_xxx_abilityGetName_0_425260(ca))
}

// nox_common_playerIsAbilityActive_4FC250
func nox_common_playerIsAbilityActive_4FC250(a1 *nox_object_t, a2 int) int {
	return bool2int(GetServer().S().Abils.IsActive(asObjectS(a1), server.Ability(a2)))
}

// nox_xxx_probablyWarcryCheck_4FC3E0
func nox_xxx_probablyWarcryCheck_4FC3E0(a1 *nox_object_t, a2 int) int {
	return bool2int(GetServer().S().Abils.IsActiveVal(asObjectS(a1), server.Ability(a2)))
}

// nox_xxx_abilityCooldown_4252D0
func nox_xxx_abilityCooldown_4252D0(ca int) int { return Nox_xxx_abilityCooldown_4252D0(ca) }

// sub_4252F0
func sub_4252F0(ca int) *wchar2_t { return internWStr(Sub_4252F0(ca)) }

// nox_xxx_spellGetAbilityIcon_425310
func nox_xxx_spellGetAbilityIcon_425310(abil, icon int) *nox_video_bag_image_t {
	return (*nox_video_bag_image_t)(Nox_xxx_spellGetAbilityIcon_425310(abil, icon))
}

// nox_xxx_bookFirstKnownAbil_425330
func nox_xxx_bookFirstKnownAbil_425330() int { return Nox_xxx_bookFirstKnownAbil_425330() }

// nox_xxx_bookNextKnownAbil_425350
func nox_xxx_bookNextKnownAbil_425350(a1 int) int { return Nox_xxx_bookNextKnownAbil_425350(a1) }

// sub_425450
func sub_425450(a1 int) int { return Sub_425450(a1) }

// nox_xxx_netAbilRepotState_4D8100
func nox_xxx_netAbilRepotState_4D8100(a1 *nox_object_t, a2, a3 char) {
	Nox_xxx_netAbilRepotState_4D8100(asObjectS(a1), server.Ability(a2), byte(a3))
}
