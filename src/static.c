#include "common__object__modifier.h"

#include "client__drawable__drawdb.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME5_2.h"

void nullsub_38() {}
void nullsub_39() {}
void nullsub_40() {}
void nullsub_41() {}
void nullsub_42() {}
void nullsub_43() {}
void nullsub_44() {}

table_26792_t table_26792[] = {
	{"DamageMultiplierEffect", &nox_xxx_effectDamageMultiplier_4E04C0, &nox_xxx_effectFloatValueLoad_4235C0},
	{"StunEffect", &nox_xxx_stunEffect_4E04D0, &nox_xxx_effectDwordValueLoad_423780},
	{"FireEffect", &nox_xxx_fireEffect_4E0550, &nox_xxx_effectFloatValueLoad_4235C0},
	{"FireRingEffect", &nox_xxx_fireRingEffect_4E05B0, &nox_xxx_effectDwordValueLoad_423780},
	{"BlueFireRingEffect", &nox_xxx_blueFREffect_4E05F0, &nox_xxx_effectDwordValueLoad_423780},
	{"FrostEffect", &nullsub_38, &nox_xxx_effectDwordValueLoad_423780},
	{"RecoilEffect", &nox_xxx_recoilEffect_4E0640, &nox_xxx_effectFloatValueLoad_4235C0},
	{"ConfuseEffect", &nox_xxx_confuseEffect_4E0670, &nox_xxx_effectDwordValueLoad_423780},
	{"LightningEffect", &nox_xxx_lightngEffect_4E06F0, &nox_xxx_effectFloatValueLoad_4235C0},
	{"DrainManaEffect", &nox_xxx_drainMEffect_4E0740, &nox_xxx_effectFloatValueLoad_4235C0},
	{"VampirismEffect", &nox_xxx_vampirismEffect_4E07C0, &nox_xxx_effectFloatValueLoad_4235C0},
	{"PoisonEffect", &nox_xxx_poisonEffect_4E0850, &nox_xxx_effectDwordValueLoad_423780},
	{"PanicEffect", &nullsub_39, &nox_xxx_effectDwordValueLoad_423780},
	{"SympathyEffect", &nox_xxx_sympathyEffect_4E08E0, &nox_xxx_effectFloatValueLoad_4235C0},
	{"ReadinessEffect", &nullsub_22, &nox_xxx_effectDwordValueLoad_423780},
	{"ProjectileSpeedEffect", &nox_xxx_effectProjectileSpeed_4E09B0, &nox_xxx_effectFloatValueLoad_4235C0},
	{"ReplenishmentEffect", &nullsub_36, &nox_xxx_effectDwordValueLoad_423780},
};
int table_26792_cnt = sizeof(table_26792) / sizeof(table_26792_t);

table_27008_t table_27008[] = {
	{"ArmorMultiplierEffect", &sub_4E0370, &nox_xxx_effectFloatValueLoad_4235C0},
	{"DurabilityMultiplierEffect", &sub_4E0380, &nox_xxx_effectFloatValueLoad_4235C0},
	{"ResilienceEffect", &nullsub_40, &nox_xxx_effectFloatValueLoad_4235C0},
	{"InversionEffect", &nox_xxx_inversionEffect_4E03D0, &nox_xxx_effectDwordValueLoad_423780},
	{"GripEffect", &nox_xxx_gripEffect_4E0480, &nox_xxx_effectDwordValueLoad_423780},
	{"BreakingEffect", &nullsub_41, &nox_xxx_effectFloatValueLoad_4235C0},
	{"PunctureProneEffect", &nullsub_42, &nox_xxx_effectFloatValueLoad_4235C0},
};
int table_27008_cnt = sizeof(table_27008) / sizeof(table_27008_t);

table_27104_t table_27104[] = {
	{"RegenerationUpdate", &nox_xxx_effectRegeneration_4E01D0, &nox_xxx_effectDwordValueLoad_423780},
	{"ParasiteUpdate", &nullsub_43, &nox_xxx_effectDwordValueLoad_423780},
	{"AttractionUpdate", &nullsub_44, &nox_xxx_effectDwordValueLoad_423780},
	{"ContinualReplenishmentUpdate", &nox_xxx_attribContinualReplen_4E02C0, &nox_xxx_effectDwordValueLoad_423780},
};
int table_27104_cnt = sizeof(table_27104) / sizeof(table_27104_t);

table_27168_t table_27168[] = {
	{"BrillianceEngage", &sub_4DFB50, &nox_xxx_effectDwordValueLoad_423780},
	{"BrillianceDisengage", &sub_4DFB80, &nox_xxx_effectDwordValueLoad_423780},
	{"SpeedEngage", &nox_xxx_effectSpeedEngage_4DFC30, &nox_xxx_effectFloatValueLoad_4235C0},
	{"SpeedDisengage", &nox_xxx_effectSpeedDisengage_4DFCA0, &nox_xxx_effectFloatValueLoad_4235C0},
	{"FireProtectEngage", &sub_4DFD10, &nox_xxx_effectFloatValueLoad_4235C0},
	{"FireProtectDisengage", &nox_xxx_modifFireProtection_4DFD40, &nox_xxx_effectFloatValueLoad_4235C0},
	{"LightningProtectEngage", &nox_xxx_buff_4DFD80, &nox_xxx_effectFloatValueLoad_4235C0},
	{"LightningProtectDisengage", &sub_4DFDB0, &nox_xxx_effectFloatValueLoad_4235C0},
	{"PoisonProtectEngage", &nox_xxx_checkPoisonProtectEnch_4DFDE0, &nox_xxx_effectFloatValueLoad_4235C0},
	{"PoisonProtectDisengage", &sub_4DFE10, &nox_xxx_effectFloatValueLoad_4235C0},
	{"RegenerationEngage", &sub_4E0140, 0},
	{"RegenerationDisengage", &sub_4E0170, 0},
};
int table_27168_cnt = sizeof(table_27168) / sizeof(table_27168_t);

table_28760_t table_28760[] = {
	{"DESC", &nox_xxx_parseEnchDesc_412100_parse_desc},
	{"PRIMARYDESC", &nox_xxx_parseEnchDesc_412100_parse_desc},
	{"SECONDARYDESC", &nox_xxx_parseEnchDescSecondary_4121B0_parse_second_desc},
	{"IDENTIFYDESC", &nox_xxx_parseIdentifyDesc_412260_parse_ident_desc},
	{"WORTH", &nox_xxx_parseEnchWorth_412310_parse_worth},
	{"COLOR", &nox_xxx_parseEnchColor_412360_parse_color},
	{"ATTACKEFFECT", &nox_xxx_parseEnchEffect_412380_parse_attack_effect},
	{"ATTACKPREHITEFFECT", &nox_xxx_parseEnchEffect_412380_parse_attack_effect},
	{"ATTACKPREDAMAGEEFFECT", &nox_xxx_parseEnchEffect_412380_parse_attack_effect},
	{"DEFENDEFFECT", &nox_xxx_parseEnchDefend_412490_parse_defend_effect},
	{"DEFENDCOLLIDEEFFECT", &nox_xxx_parseEnchDefend_412490_parse_defend_effect},
	{"ENGAGEEFFECT", &nox_xxx_parseEnchEngageOrDisEng_412580_parse_engage_effect},
	{"DISENGAGEEFFECT", &nox_xxx_parseEnchEngageOrDisEng_412580_parse_engage_effect},
	{"UPDATEEFFECT", &nox_xxx_parseEnchUpdate_412670_parse_update_effect},
	{"ALLOWED_WEAPONS", &nox_xxx_parseEnchAllowedWeapon_412740_parse_allowed_weapons},
	{"ALLOWED_ARMOR", &nox_xxx_parseEnchAllowedArmor_4128A0_parse_allowed_armor},
	{"ALLOWED_POSITION", &nox_xxx_parseAllowedPosition_4128C0_parse_allowed_pos},
};
int table_28760_cnt = sizeof(table_28760) / sizeof(table_28760_t);

#define NOX_VERSION_STRING "1.2b"
char nox_version_string_102944[7] = NOX_VERSION_STRING;
