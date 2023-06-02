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
	Nox_xxx_fireEffect_4E0550            func(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object)
	Nox_xxx_fireRingEffect_4E05B0        func(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object)
	Nox_xxx_blueFREffect_4E05F0          func(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object)
)

var _ = [1]struct{}{}[88-unsafe.Sizeof(server.Modifier{})]

var _ = [1]struct{}{}[144-unsafe.Sizeof(server.ModifierEff{})]

var (
	_ = nox_xxx_fireEffect_4E0550
	_ = nox_xxx_fireRingEffect_4E05B0
	_ = nox_xxx_blueFREffect_4E05F0
)

func init() {
	server.RegisterModifDamageEffect("DamageMultiplierEffect", ccall.FuncAddr(nox_xxx_effectDamageMultiplier_4E04C0), server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("StunEffect", ccall.FuncAddr(nox_xxx_stunEffect_4E04D0), server.ModEffectParseInt)
	server.RegisterModifDamageEffect("FireEffect", ccall.FuncAddr(nox_xxx_fireEffect_4E0550), server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("FireRingEffect", ccall.FuncAddr(nox_xxx_fireRingEffect_4E05B0), server.ModEffectParseInt)
	server.RegisterModifDamageEffect("BlueFireRingEffect", ccall.FuncAddr(nox_xxx_blueFREffect_4E05F0), server.ModEffectParseInt)
	server.RegisterModifDamageEffect("FrostEffect", ccall.FuncAddr(nullsub_38), server.ModEffectParseInt)
	server.RegisterModifDamageEffect("RecoilEffect", ccall.FuncAddr(nox_xxx_recoilEffect_4E0640), server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("ConfuseEffect", ccall.FuncAddr(nox_xxx_confuseEffect_4E0670), server.ModEffectParseInt)
	server.RegisterModifDamageEffect("LightningEffect", ccall.FuncAddr(nox_xxx_lightngEffect_4E06F0), server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("DrainManaEffect", ccall.FuncAddr(nox_xxx_drainMEffect_4E0740), server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("VampirismEffect", ccall.FuncAddr(nox_xxx_vampirismEffect_4E07C0), server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("PoisonEffect", ccall.FuncAddr(nox_xxx_poisonEffect_4E0850), server.ModEffectParseInt)
	server.RegisterModifDamageEffect("PanicEffect", ccall.FuncAddr(nullsub_39), server.ModEffectParseInt)
	server.RegisterModifDamageEffect("SympathyEffect", ccall.FuncAddr(nox_xxx_sympathyEffect_4E08E0), server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("ReadinessEffect", ccall.FuncAddr(nullsub_22), server.ModEffectParseInt)
	server.RegisterModifDamageEffect("ProjectileSpeedEffect", ccall.FuncAddr(nox_xxx_effectProjectileSpeed_4E09B0), server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("ReplenishmentEffect", ccall.FuncAddr(nullsub_36), server.ModEffectParseInt)

	server.RegisterModifDefendEffect("ArmorMultiplierEffect", ccall.FuncAddr(sub_4E0370), server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("DurabilityMultiplierEffect", ccall.FuncAddr(sub_4E0380), server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("ResilienceEffect", ccall.FuncAddr(nullsub_40), server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("InversionEffect", ccall.FuncAddr(nox_xxx_inversionEffect_4E03D0), server.ModEffectParseInt)
	server.RegisterModifDefendEffect("GripEffect", ccall.FuncAddr(nox_xxx_gripEffect_4E0480), server.ModEffectParseInt)
	server.RegisterModifDefendEffect("BreakingEffect", ccall.FuncAddr(nullsub_41), server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("PunctureProneEffect", ccall.FuncAddr(nullsub_42), server.ModEffectParseFloat)

	server.RegisterModifUpdateEffect("RegenerationUpdate", ccall.FuncAddr(nox_xxx_effectRegeneration_4E01D0), server.ModEffectParseInt)
	server.RegisterModifUpdateEffect("ParasiteUpdate", ccall.FuncAddr(nullsub_43), server.ModEffectParseInt)
	server.RegisterModifUpdateEffect("AttractionUpdate", ccall.FuncAddr(nullsub_44), server.ModEffectParseInt)
	server.RegisterModifUpdateEffect("ContinualReplenishmentUpdate", ccall.FuncAddr(nox_xxx_attribContinualReplen_4E02C0), server.ModEffectParseInt)

	server.RegisterModifEngageEffect("BrillianceEngage", ccall.FuncAddr(sub_4DFB50), server.ModEffectParseInt)
	server.RegisterModifEngageEffect("BrillianceDisengage", ccall.FuncAddr(sub_4DFB80), server.ModEffectParseInt)
	server.RegisterModifEngageEffect("SpeedEngage", ccall.FuncAddr(nox_xxx_effectSpeedEngage_4DFC30), server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("SpeedDisengage", ccall.FuncAddr(nox_xxx_effectSpeedDisengage_4DFCA0), server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("FireProtectEngage", ccall.FuncAddr(sub_4DFD10), server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("FireProtectDisengage", ccall.FuncAddr(nox_xxx_modifFireProtection_4DFD40), server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("LightningProtectEngage", ccall.FuncAddr(nox_xxx_buff_4DFD80), server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("LightningProtectDisengage", ccall.FuncAddr(sub_4DFDB0), server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("PoisonProtectEngage", ccall.FuncAddr(nox_xxx_checkPoisonProtectEnch_4DFDE0), server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("PoisonProtectDisengage", ccall.FuncAddr(sub_4DFE10), server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("RegenerationEngage", ccall.FuncAddr(sub_4E0140), nil)
	server.RegisterModifEngageEffect("RegenerationDisengage", ccall.FuncAddr(sub_4E0170), nil)
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
func nox_xxx_fireEffect_4E0550(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object) {
	Nox_xxx_fireEffect_4E0550(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p))
}

// nox_xxx_fireRingEffect_4E05B0
func nox_xxx_fireRingEffect_4E05B0(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object) {
	Nox_xxx_fireRingEffect_4E05B0(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p))
}

// nox_xxx_blueFREffect_4E05F0
func nox_xxx_blueFREffect_4E05F0(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object) {
	Nox_xxx_blueFREffect_4E05F0(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p))
}
