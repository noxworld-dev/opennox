package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_modifGetDescById_413330      func(a1 int32) unsafe.Pointer
	Nox_xxx_equipClothFindDefByTT_413270 func(a1 int32) unsafe.Pointer
	Sub_4A5E90_A                         func()
	Nox_xxx_fireEffect_4E0550            server.ModifierDamageFunc
	Nox_xxx_fireRingEffect_4E05B0        server.ModifierDamageFunc
	Nox_xxx_blueFREffect_4E05F0          server.ModifierDamageFunc
)

var _ = [1]struct{}{}[88-unsafe.Sizeof(server.Modifier{})]

var _ = [1]struct{}{}[144-unsafe.Sizeof(server.ModifierEff{})]

func init() {
	server.RegisterModifDamageEffectFloat("DamageMultiplierEffect", nox_xxx_effectDamageMultiplier_4E04C0)
	server.RegisterModifDamageEffectInt("StunEffect", nox_xxx_stunEffect_4E04D0)
	server.RegisterModifDamageEffectFloat("FireEffect", nox_xxx_fireEffect_4E0550)
	server.RegisterModifDamageEffectInt("FireRingEffect", nox_xxx_fireRingEffect_4E05B0)
	server.RegisterModifDamageEffectInt("BlueFireRingEffect", nox_xxx_blueFREffect_4E05F0)
	server.RegisterModifDamageEffectInt("FrostEffect", nullsub_38)
	server.RegisterModifDamageEffectFloat("RecoilEffect", nox_xxx_recoilEffect_4E0640)
	server.RegisterModifDamageEffectInt("ConfuseEffect", nox_xxx_confuseEffect_4E0670)
	server.RegisterModifDamageEffectFloat("LightningEffect", nox_xxx_lightngEffect_4E06F0)
	server.RegisterModifDamageEffectFloat("DrainManaEffect", nox_xxx_drainMEffect_4E0740)
	server.RegisterModifDamageEffectFloat("VampirismEffect", nox_xxx_vampirismEffect_4E07C0)
	server.RegisterModifDamageEffectInt("PoisonEffect", nox_xxx_poisonEffect_4E0850)
	server.RegisterModifDamageEffectInt("PanicEffect", nullsub_39)
	server.RegisterModifDamageEffectFloat("SympathyEffect", nox_xxx_sympathyEffect_4E08E0)
	server.RegisterModifDamageEffectInt("ReadinessEffect", nullsub_22)
	server.RegisterModifDamageEffectFloat("ProjectileSpeedEffect", nox_xxx_effectProjectileSpeed_4E09B0)
	server.RegisterModifDamageEffectInt("ReplenishmentEffect", nullsub_36)

	server.RegisterModifDefendEffectFloat("ArmorMultiplierEffect", sub_4E0370)
	server.RegisterModifDefendEffectFloat("DurabilityMultiplierEffect", sub_4E0380)
	server.RegisterModifDefendEffectFloat("ResilienceEffect", nullsub_40)
	server.RegisterModifDefendEffectInt("InversionEffect", nox_xxx_inversionEffect_4E03D0)
	server.RegisterModifDefendEffectInt("GripEffect", nox_xxx_gripEffect_4E0480)
	server.RegisterModifDefendEffectFloat("BreakingEffect", nullsub_41)
	server.RegisterModifDefendEffectFloat("PunctureProneEffect", nullsub_42)

	server.RegisterModifUpdateEffectInt("RegenerationUpdate", nox_xxx_effectRegeneration_4E01D0)
	server.RegisterModifUpdateEffectInt("ParasiteUpdate", nullsub_43)
	server.RegisterModifUpdateEffectInt("AttractionUpdate", nullsub_44)
	server.RegisterModifUpdateEffectInt("ContinualReplenishmentUpdate", nox_xxx_attribContinualReplen_4E02C0)

	server.RegisterModifEngageEffectInt("BrillianceEngage", ccall.FuncAddr(sub_4DFB50))
	server.RegisterModifEngageEffectInt("BrillianceDisengage", ccall.FuncAddr(sub_4DFB80))
	server.RegisterModifEngageEffectFloat("SpeedEngage", ccall.FuncAddr(nox_xxx_effectSpeedEngage_4DFC30))
	server.RegisterModifEngageEffectFloat("SpeedDisengage", ccall.FuncAddr(nox_xxx_effectSpeedDisengage_4DFCA0))
	server.RegisterModifEngageEffectFloat("FireProtectEngage", ccall.FuncAddr(sub_4DFD10))
	server.RegisterModifEngageEffectFloat("FireProtectDisengage", ccall.FuncAddr(nox_xxx_modifFireProtection_4DFD40))
	server.RegisterModifEngageEffectFloat("LightningProtectEngage", ccall.FuncAddr(nox_xxx_buff_4DFD80))
	server.RegisterModifEngageEffectFloat("LightningProtectDisengage", ccall.FuncAddr(sub_4DFDB0))
	server.RegisterModifEngageEffectFloat("PoisonProtectEngage", ccall.FuncAddr(nox_xxx_checkPoisonProtectEnch_4DFDE0))
	server.RegisterModifEngageEffectFloat("PoisonProtectDisengage", ccall.FuncAddr(sub_4DFE10))
	server.RegisterModifEngageEffectVoid("RegenerationEngage", ccall.FuncAddr(sub_4E0140))
	server.RegisterModifEngageEffectVoid("RegenerationDisengage", ccall.FuncAddr(sub_4E0170))
}

// nox_xxx_modifGetModifListByType_4133B0
func nox_xxx_modifGetModifListByType_4133B0(a1 int) unsafe.Pointer {
	return GetServer().S().Modif.Nox_xxx_modifGetModifListByType_4133B0(a1)
}

// nox_xxx_modifGetDescById_413330
func nox_xxx_modifGetDescById_413330(a1 int32) unsafe.Pointer {
	return Nox_xxx_modifGetDescById_413330(a1)
}

// nox_xxx_modifGetIdByName_413290
func nox_xxx_modifGetIdByName_413290(name *byte) int32 {
	return GetServer().S().Modif.Nox_xxx_modifGetIdByName413290(GoString(name))
}

// nox_xxx_getProjectileClassById_413250
func nox_xxx_getProjectileClassById_413250(a1 int32) unsafe.Pointer {
	return GetServer().S().Modif.Nox_xxx_getProjectileClassById413250(a1).C()
}

// nox_xxx_equipClothFindDefByTT_413270
func nox_xxx_equipClothFindDefByTT_413270(a1 int32) unsafe.Pointer {
	return Nox_xxx_equipClothFindDefByTT_413270(a1)
}

// sub_4A5E90_A
func sub_4A5E90_A() { Sub_4A5E90_A() }

// nox_xxx_fireEffect_4E0550
func nox_xxx_fireEffect_4E0550(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object, a5, a6 unsafe.Pointer) {
	Nox_xxx_fireEffect_4E0550(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p), a5, a6)
}

// nox_xxx_fireRingEffect_4E05B0
func nox_xxx_fireRingEffect_4E05B0(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object, a5, a6 unsafe.Pointer) {
	Nox_xxx_fireRingEffect_4E05B0(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p), a5, a6)
}

// nox_xxx_blueFREffect_4E05F0
func nox_xxx_blueFREffect_4E05F0(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object, a5, a6 unsafe.Pointer) {
	Nox_xxx_blueFREffect_4E05F0(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p), a5, a6)
}
