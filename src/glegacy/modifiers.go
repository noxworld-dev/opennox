package legacy

/*
#include "defs.h"

void nullsub_22();
void nullsub_36();
void nullsub_38();
void nullsub_39();
void nullsub_40();
void nullsub_41();
void nullsub_42();
void nullsub_43();
void nullsub_44();

int nox_xxx_spellCastCleansingFlame_52D5C0(int a1, nox_object_t* a2p, nox_object_t* a3p, nox_object_t* a4p, void* a5p, int a6);

void sub_4DFE10(int a1, int a2);
float* sub_4E0370(int a1, int a2, int a3, int a4, int a5, float* a6);
float* sub_4E0380(int a1, int a2, int a3, int a4, int a5, float* a6);
float* nox_xxx_effectDamageMultiplier_4E04C0(int a1, int a2, int a3, int a4, float* a5);
void nox_xxx_attribContinualReplen_4E02C0(int a1, uint32_t* a2);
void nox_xxx_confuseEffect_4E0670(int a1, int a2, int a3, int a4);
void nox_xxx_drainMEffect_4E0740(int a1, int a2, int a3, int a4, int* a5);
void nox_xxx_sympathyEffect_4E08E0(int a1, int a2, int a3, int a4, int* a5);
int nox_xxx_effectProjectileSpeed_4E09B0(int a1, int a2, int a3, int a4, int a5);
void nox_xxx_buff_4DFD80(int a1, int a2);
void nox_xxx_checkPoisonProtectEnch_4DFDE0(int a1, int a2);
int nox_xxx_gripEffect_4E0480(int a1, int a2, int a3, int a4, int a5, int* a6);
void nox_xxx_effectRegeneration_4E01D0(int a1, int a2);
void nox_xxx_stunEffect_4E04D0(int a1, int a2, int a3, int a4);
void nox_xxx_fireEffect_4E0550(void* a1, nox_object_t* a2, nox_object_t* a3, nox_object_t* a4);
void nox_xxx_fireRingEffect_4E05B0(void* a1, nox_object_t* a2, nox_object_t* a3, nox_object_t* a4);
void nox_xxx_blueFREffect_4E05F0(void* a1, nox_object_t* a2, nox_object_t* a3, nox_object_t* a4);
void nox_xxx_recoilEffect_4E0640(int a1, int a2, int a3, int a4);
void nox_xxx_lightngEffect_4E06F0(int a1, int a2, int a3, int a4);
void nox_xxx_vampirismEffect_4E07C0(int a1, int a2, int a3, int a4, int* a5);
void nox_xxx_poisonEffect_4E0850(int a1, int a2, int a3, int a4);
int nox_xxx_inversionEffect_4E03D0(int a1, int a2, int a3, int a4, int a5, int* a6);
void sub_4DFB50(int a1, int a2);
void sub_4DFB80(int a1, int a2);
void nox_xxx_effectSpeedEngage_4DFC30(int a1, int a2);
void nox_xxx_effectSpeedDisengage_4DFCA0(int a1, int a2);
void sub_4DFD10(int a1, int a2);
void nox_xxx_modifFireProtection_4DFD40(int a1, int a2, int a3);
void sub_4DFDB0(int a1, int a2);
void sub_4E0140(int a1, int a2);
void sub_4E0170(int a1, int a2);
*/

import (
	"unsafe"

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
	server.RegisterModifDamageEffect("DamageMultiplierEffect", nox_xxx_effectDamageMultiplier_4E04C0, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("StunEffect", nox_xxx_stunEffect_4E04D0, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("FireEffect", nox_xxx_fireEffect_4E0550, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("FireRingEffect", nox_xxx_fireRingEffect_4E05B0, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("BlueFireRingEffect", nox_xxx_blueFREffect_4E05F0, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("FrostEffect", nullsub_38, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("RecoilEffect", nox_xxx_recoilEffect_4E0640, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("ConfuseEffect", nox_xxx_confuseEffect_4E0670, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("LightningEffect", nox_xxx_lightngEffect_4E06F0, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("DrainManaEffect", nox_xxx_drainMEffect_4E0740, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("VampirismEffect", nox_xxx_vampirismEffect_4E07C0, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("PoisonEffect", nox_xxx_poisonEffect_4E0850, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("PanicEffect", nullsub_39, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("SympathyEffect", nox_xxx_sympathyEffect_4E08E0, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("ReadinessEffect", nullsub_22, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("ProjectileSpeedEffect", nox_xxx_effectProjectileSpeed_4E09B0, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("ReplenishmentEffect", nullsub_36, server.ModEffectParseInt)

	server.RegisterModifDefendEffect("ArmorMultiplierEffect", sub_4E0370, server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("DurabilityMultiplierEffect", sub_4E0380, server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("ResilienceEffect", nullsub_40, server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("InversionEffect", nox_xxx_inversionEffect_4E03D0, server.ModEffectParseInt)
	server.RegisterModifDefendEffect("GripEffect", nox_xxx_gripEffect_4E0480, server.ModEffectParseInt)
	server.RegisterModifDefendEffect("BreakingEffect", nullsub_41, server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("PunctureProneEffect", nullsub_42, server.ModEffectParseFloat)

	server.RegisterModifUpdateEffect("RegenerationUpdate", nox_xxx_effectRegeneration_4E01D0, server.ModEffectParseInt)
	server.RegisterModifUpdateEffect("ParasiteUpdate", nullsub_43, server.ModEffectParseInt)
	server.RegisterModifUpdateEffect("AttractionUpdate", nullsub_44, server.ModEffectParseInt)
	server.RegisterModifUpdateEffect("ContinualReplenishmentUpdate", nox_xxx_attribContinualReplen_4E02C0, server.ModEffectParseInt)

	server.RegisterModifEngageEffect("BrillianceEngage", sub_4DFB50, server.ModEffectParseInt)
	server.RegisterModifEngageEffect("BrillianceDisengage", sub_4DFB80, server.ModEffectParseInt)
	server.RegisterModifEngageEffect("SpeedEngage", nox_xxx_effectSpeedEngage_4DFC30, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("SpeedDisengage", nox_xxx_effectSpeedDisengage_4DFCA0, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("FireProtectEngage", sub_4DFD10, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("FireProtectDisengage", nox_xxx_modifFireProtection_4DFD40, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("LightningProtectEngage", nox_xxx_buff_4DFD80, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("LightningProtectDisengage", sub_4DFDB0, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("PoisonProtectEngage", nox_xxx_checkPoisonProtectEnch_4DFDE0, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("PoisonProtectDisengage", sub_4DFE10, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("RegenerationEngage", sub_4E0140, nil)
	server.RegisterModifEngageEffect("RegenerationDisengage", sub_4E0170, nil)
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
func nox_xxx_modifGetIdByName_413290(name *char) int32 {
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
func nox_xxx_fireEffect_4E0550(a1 unsafe.Pointer, a2p, a3p, a4p *nox_object_t) {
	Nox_xxx_fireEffect_4E0550(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p))
}

// nox_xxx_fireRingEffect_4E05B0
func nox_xxx_fireRingEffect_4E05B0(a1 unsafe.Pointer, a2p, a3p, a4p *nox_object_t) {
	Nox_xxx_fireRingEffect_4E05B0(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p))
}

// nox_xxx_blueFREffect_4E05F0
func nox_xxx_blueFREffect_4E05F0(a1 unsafe.Pointer, a2p, a3p, a4p *nox_object_t) {
	Nox_xxx_blueFREffect_4E05F0(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p))
}
