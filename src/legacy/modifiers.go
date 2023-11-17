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
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_modifGetDescById_413330      func(a1 int32) unsafe.Pointer
	Nox_xxx_equipClothFindDefByTT_413270 func(a1 int32) unsafe.Pointer
	Sub_4A5E90_A                         func()
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
	server.RegisterModifDamageEffect("DamageMultiplierEffect", C.nox_xxx_effectDamageMultiplier_4E04C0, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("StunEffect", C.nox_xxx_stunEffect_4E04D0, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("FireEffect", C.nox_xxx_fireEffect_4E0550, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("FireRingEffect", C.nox_xxx_fireRingEffect_4E05B0, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("BlueFireRingEffect", C.nox_xxx_blueFREffect_4E05F0, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("FrostEffect", C.nullsub_38, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("RecoilEffect", C.nox_xxx_recoilEffect_4E0640, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("ConfuseEffect", C.nox_xxx_confuseEffect_4E0670, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("LightningEffect", C.nox_xxx_lightngEffect_4E06F0, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("DrainManaEffect", C.nox_xxx_drainMEffect_4E0740, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("VampirismEffect", C.nox_xxx_vampirismEffect_4E07C0, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("PoisonEffect", C.nox_xxx_poisonEffect_4E0850, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("PanicEffect", C.nullsub_39, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("SympathyEffect", C.nox_xxx_sympathyEffect_4E08E0, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("ReadinessEffect", C.nullsub_22, server.ModEffectParseInt)
	server.RegisterModifDamageEffect("ProjectileSpeedEffect", C.nox_xxx_effectProjectileSpeed_4E09B0, server.ModEffectParseFloat)
	server.RegisterModifDamageEffect("ReplenishmentEffect", C.nullsub_36, server.ModEffectParseInt)

	server.RegisterModifDefendEffect("ArmorMultiplierEffect", C.sub_4E0370, server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("DurabilityMultiplierEffect", C.sub_4E0380, server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("ResilienceEffect", C.nullsub_40, server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("InversionEffect", C.nox_xxx_inversionEffect_4E03D0, server.ModEffectParseInt)
	server.RegisterModifDefendEffect("GripEffect", C.nox_xxx_gripEffect_4E0480, server.ModEffectParseInt)
	server.RegisterModifDefendEffect("BreakingEffect", C.nullsub_41, server.ModEffectParseFloat)
	server.RegisterModifDefendEffect("PunctureProneEffect", C.nullsub_42, server.ModEffectParseFloat)

	server.RegisterModifUpdateEffect("RegenerationUpdate", C.nox_xxx_effectRegeneration_4E01D0, server.ModEffectParseInt)
	server.RegisterModifUpdateEffect("ParasiteUpdate", C.nullsub_43, server.ModEffectParseInt)
	server.RegisterModifUpdateEffect("AttractionUpdate", C.nullsub_44, server.ModEffectParseInt)
	server.RegisterModifUpdateEffect("ContinualReplenishmentUpdate", C.nox_xxx_attribContinualReplen_4E02C0, server.ModEffectParseInt)

	server.RegisterModifEngageEffect("BrillianceEngage", C.sub_4DFB50, server.ModEffectParseInt)
	server.RegisterModifEngageEffect("BrillianceDisengage", C.sub_4DFB80, server.ModEffectParseInt)
	server.RegisterModifEngageEffect("SpeedEngage", C.nox_xxx_effectSpeedEngage_4DFC30, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("SpeedDisengage", C.nox_xxx_effectSpeedDisengage_4DFCA0, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("FireProtectEngage", C.sub_4DFD10, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("FireProtectDisengage", C.nox_xxx_modifFireProtection_4DFD40, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("LightningProtectEngage", C.nox_xxx_buff_4DFD80, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("LightningProtectDisengage", C.sub_4DFDB0, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("PoisonProtectEngage", C.nox_xxx_checkPoisonProtectEnch_4DFDE0, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("PoisonProtectDisengage", C.sub_4DFE10, server.ModEffectParseFloat)
	server.RegisterModifEngageEffect("RegenerationEngage", C.sub_4E0140, nil)
	server.RegisterModifEngageEffect("RegenerationDisengage", C.sub_4E0170, nil)
}

//export nox_xxx_modifGetModifListByType_4133B0
func nox_xxx_modifGetModifListByType_4133B0(a1 int) unsafe.Pointer {
	return GetServer().S().Modif.Nox_xxx_modifGetModifListByType_4133B0(a1)
}

//export nox_xxx_modifGetDescById_413330
func nox_xxx_modifGetDescById_413330(a1 int32) unsafe.Pointer {
	return Nox_xxx_modifGetDescById_413330(a1)
}

//export nox_xxx_modifGetIdByName_413290
func nox_xxx_modifGetIdByName_413290(name *C.char) int32 {
	return GetServer().S().Modif.Nox_xxx_modifGetIdByName413290(GoString(name))
}

//export nox_xxx_getProjectileClassById_413250
func nox_xxx_getProjectileClassById_413250(a1 int32) unsafe.Pointer {
	return GetServer().S().Modif.Nox_xxx_getProjectileClassById413250(a1).C()
}

//export nox_xxx_equipClothFindDefByTT_413270
func nox_xxx_equipClothFindDefByTT_413270(a1 int32) unsafe.Pointer {
	return Nox_xxx_equipClothFindDefByTT_413270(a1)
}

//export sub_4A5E90_A
func sub_4A5E90_A() { Sub_4A5E90_A() }

//export nox_xxx_fireEffect_4E0550
func nox_xxx_fireEffect_4E0550(a1 unsafe.Pointer, a2p, a3p, a4p *nox_object_t) {
	GetServer().S().Nox_xxx_fireEffect_4E0550(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p))
}

//export nox_xxx_fireRingEffect_4E05B0
func nox_xxx_fireRingEffect_4E05B0(a1 unsafe.Pointer, a2p, a3p, a4p *nox_object_t) {
	Nox_xxx_fireRingEffect_4E05B0(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p))
}

//export nox_xxx_blueFREffect_4E05F0
func nox_xxx_blueFREffect_4E05F0(a1 unsafe.Pointer, a2p, a3p, a4p *nox_object_t) {
	Nox_xxx_blueFREffect_4E05F0(a1, asObjectS(a2p), asObjectS(a3p), asObjectS(a4p))
}
