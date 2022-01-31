#include <math.h>

#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "common__random.h"
#include "server__ability__ability.h"
#include "server__magic__plyrgide.h"
#include "server__magic__plyrspel.h"
#include "server__object__health.h"

#include "common__gamemech__pausefx.h"

#include "MixPatch.h"
#include "client__video__draw_common.h"
#include "common/fs/nox_fs.h"
#include "common__magic__speltree.h"
#include "defs.h"
#include "operators.h"
#include "server__script__builtin.h"
#include "server__script__script.h"

extern uint32_t dword_5d4594_2488620;
extern uint32_t dword_5d4594_2488656;
extern uint32_t dword_5d4594_2488648;
extern uint32_t dword_5d4594_3835360;
extern uint32_t dword_5d4594_2488728;
extern uint32_t dword_5d4594_2488644;
extern uint32_t dword_5d4594_2489436;
extern uint32_t dword_5d4594_2488724;
extern uint32_t dword_5d4594_2489160;
extern uint32_t dword_5d4594_2487992;
extern uint32_t dword_5d4594_2488720;
extern uint32_t dword_5d4594_2487932;
extern uint32_t nox_xxx_lightningOwner_5d4594_2487900;
extern uint32_t dword_587000_261388;
extern uint32_t dword_5d4594_2487948;
extern uint32_t dword_5d4594_2488640;
extern uint32_t dword_5d4594_3835312;
extern uint32_t dword_5d4594_2488608;
extern uint32_t dword_5d4594_2488652;
extern uint32_t dword_5d4594_3835348;
extern uint32_t dword_5d4594_3835352;
extern uint32_t dword_5d4594_2489432;
extern uint32_t nox_xxx_lightningClosestTargetDistance_5d4594_2487912;
extern uint32_t dword_5d4594_2487980;
extern uint32_t dword_5d4594_3835356;
extern uint32_t nox_xxx_warriorMaxMana_587000_312788;
extern uint32_t nox_xxx_warriorMaxHealth_587000_312784;
extern uint32_t dword_5d4594_2487984;
extern uint32_t dword_5d4594_2487248;
extern uint32_t nox_xxx_conjurerMaxHealth_587000_312800;
extern uint32_t nox_xxx_wizardMaxHealth_587000_312816;
extern uint32_t nox_xxx_conjurerMaxMana_587000_312804;
extern uint32_t nox_xxx_wizardMaximumMana_587000_312820;
extern uint32_t dword_5d4594_2488660;
extern uint64_t qword_581450_10176;
extern uint64_t qword_581450_9512;
extern uint64_t qword_581450_9568;
extern uint64_t qword_581450_9544;
extern uint32_t dword_5d4594_2488604;
extern uint32_t nox_xxx_float_23_587000_264364;
extern uint32_t nox_xxx_lightningTargetArrayIndex_5d4594_2487904;
extern uint32_t nox_xxx_lightningTarget_5d4594_2487908;
extern uint32_t dword_5d4594_251572;
extern uint32_t dword_5d4594_2650652;
extern obj_5D4594_2650668_t** ptr_5D4594_2650668;
extern unsigned int nox_frame_xxx_2598000;
extern unsigned int gameex_flags;

unsigned int nox_gameFPS = 0;

//----- (0052F8A0) --------------------------------------------------------
int nox_xxx_onFrameLightning_52F8A0(float a1) {
	int source;                // esi
	int v2;                    // eax
	int v4;                    // eax
	int v5;                    // eax
	int v6;                    // edi
	int v7;                    // ecx
	int owner;                 // edx
	int spellLevel;            // ebx
	int v10;                   // eax
	int v11;                   // ecx
	int v12;                   // edi
	int target;                // eax
	int index;                 // ecx
	int v15;                   // ecx
	int v16;                   // ecx
	int v17;                   // ecx
	int v18;                   // ecx
	int secondBounceTarget;    // eax
	int v20;                   // ebx
	uint32_t* v21;             // edi
	uint32_t* j;               // ebp
	int v23;                   // eax
	int v24;                   // eax
	int v25;                   // ecx
	int v26;                   // eax
	int v27;                   // edi
	char v28;                  // al
	unsigned char v29;         // al
	int v30;                   // eax
	int v31;                   // ebp
	int i;                     // edi
	int v33;                   // eax
	int v34;                   // edi
	float range1;              // [esp+0h] [ebp-20h]
	float range2;              // [esp+0h] [ebp-20h]
	float range3;              // [esp+0h] [ebp-20h]
	float range4;              // [esp+0h] [ebp-20h]
	float lightningSearchTime; // [esp+8h] [ebp-18h]
	float range5;              // [esp+1Ch] [ebp-4h]
	float lightningRange;      // [esp+24h] [ebp+4h]
	float damage;              // [esp+24h] [ebp+4h]

	source = LODWORD(a1);
	v2 = *(uint32_t*)(LODWORD(a1) + 16);
	if (v2) {
		if (nox_xxx_testUnitBuffs_4FF350(v2, 8)) {
			return 1;
		}
	} else if (!*(uint32_t*)(LODWORD(a1) + 20)) {
		return 1;
	}
	lightningRange = nox_xxx_gamedataGetFloat_419D40("LightningRange");
	if (*(uint32_t*)(source + 20)) { // Is the source a trap?
		*getMemU32Ptr(0x5D4594, 2487820) = *(uint32_t*)(source + 28);
		*getMemU32Ptr(0x5D4594, 2487824) = *(uint32_t*)(source + 32);
		nox_xxx_unitsGetInCircle_517F90((float2*)(source + 28), lightningRange, nox_xxx_lightningSpellTrapEffect_530020,
										*(uint32_t*)(source + 16));
		return 1;
	}
	if (*(uint8_t*)(*(uint32_t*)(source + 16) + 8) & 4 && !nox_xxx_unitGetOldMana_4EEC80(*(uint32_t*)(source + 16))) {
		return 1;
	}
	if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(source + 60)) > 2 &&
		sub_4E6BD0(*(uint32_t*)(source + 16))) {
		return 1;
	}
	v4 = *(uint32_t*)(source + 16);
	if (*(uint8_t*)(v4 + 8) & 2 && sub_4FEA70(v4, (float2*)(source + 28))) {
		return 1;
	}
	v5 = *(uint32_t*)(source + 104);
	if (v5) {
		do {
			v6 = *(uint32_t*)(v5 + 116);
			sub_4FE980(v5);
			v5 = v6;
		} while (v6);
	}
	v7 = *(uint32_t*)(source + 8);
	*(uint32_t*)(source + 104) = *(uint32_t*)(source + 108);
	*(uint32_t*)(source + 108) = 0;
	nox_xxx_lightningTarget_5d4594_2487908 = 0;
	nox_xxx_lightningTargetArrayIndex_5d4594_2487904 = 0;
	owner = *(uint32_t*)(source + 16);
	*getMemU32Ptr(0x5D4594, 2487844) = 0;
	spellLevel = *getMemU32Ptr(0x587000, 260380 + 4 * v7);
	*getMemU32Ptr(0x5D4594, 2487848) = 0;
	nox_xxx_lightningOwner_5d4594_2487900 = owner;
	*getMemU32Ptr(0x5D4594, 2487852) = 0;
	*getMemU32Ptr(0x5D4594, 2487856) = 0;
	*getMemU32Ptr(0x5D4594, 2487860) = 0;
	v10 = *(uint32_t*)(source + 16);
	if (!(*(uint8_t*)(v10 + 8) & 4) || (v11 = *(uint32_t*)(v10 + 748), (v12 = *(uint32_t*)(v11 + 288)) == 0) ||
		(!nox_xxx_unitIsEnemyTo_5330C0(v10, *(uint32_t*)(v11 + 288)) ||
				 nox_xxx_calcDistance_4E6C00(*(uint32_t*)(source + 16), v12) > lightningRange
			 ? (target = nox_xxx_lightningTarget_5d4594_2487908)
			 : (target = v12, nox_xxx_lightningTarget_5d4594_2487908 = v12),
		 !target)) {
		*(float*)&nox_xxx_lightningClosestTargetDistance_5d4594_2487912 = lightningRange * lightningRange;
		nox_xxx_unitsGetInCircle_517F90((float2*)(source + 28), lightningRange, nox_xxx_lightningCanAttackCheck_52FF10,
										*(uint32_t*)(source + 16));
		target = nox_xxx_lightningTarget_5d4594_2487908;
		if (!nox_xxx_lightningTarget_5d4594_2487908) {
			for (i = *(uint32_t*)(source + 104); i; i = *(uint32_t*)(i + 116)) {
				if (*(uint32_t*)(i + 48)) {
					nox_xxx_netStopRaySpell_4FEF90(i, *(uint32_t**)(i + 48));
				}
			}
			v33 = *(uint32_t*)(source + 104);
			if (v33) {
				do {
					v34 = *(uint32_t*)(v33 + 116);
					sub_4FE980(v33);
					v33 = v34;
				} while (v34);
			}
			*(uint32_t*)(source + 104) = 0;
			return 0;
		}
	}
	// Should be 0
	index = nox_xxx_lightningTargetArrayIndex_5d4594_2487904;
	// ARRAY! First member of 2487844 is the target itself...
	*getMemU32Ptr(0x5D4594, 2487844 + 4 * nox_xxx_lightningTargetArrayIndex_5d4594_2487904) = target;

	nox_xxx_lightningTargetArrayIndex_5d4594_2487904 = index + 1;
	// Second level of magic allows ONE jump from main target
	if (spellLevel > 1) {
		nox_xxx_lightningTarget_5d4594_2487908 = 0;
		*(float*)&nox_xxx_lightningClosestTargetDistance_5d4594_2487912 = lightningRange * lightningRange;
		range1 = lightningRange * 0.94999999;
		nox_xxx_unitsGetInCircle_517F90((float2*)(*getMemU32Ptr(0x5D4594, 2487844) + 56), range1,
										nox_xxx_lightningCanAttackCheck_52FF10, *getMemIntPtr(0x5D4594, 2487844));
		if (nox_xxx_lightningTarget_5d4594_2487908) {
			v15 = nox_xxx_lightningTargetArrayIndex_5d4594_2487904;
			// THIS SETS *getMemU32Ptr(0x5D4594, 2487848)!!!
			// Second member of  2487844 is the first bounce target from main target
			*getMemU32Ptr(0x5D4594, 2487844 + 4 * nox_xxx_lightningTargetArrayIndex_5d4594_2487904) =
				nox_xxx_lightningTarget_5d4594_2487908;
			nox_xxx_lightningTargetArrayIndex_5d4594_2487904 = v15 + 1;
		}
	}

	// Third level of magic allows TWO jump from main target
	if (spellLevel > 2) {
		nox_xxx_lightningTarget_5d4594_2487908 = 0;
		*(float*)&nox_xxx_lightningClosestTargetDistance_5d4594_2487912 = lightningRange * lightningRange;
		range2 = lightningRange * 0.89999998;
		nox_xxx_unitsGetInCircle_517F90((float2*)(*getMemU32Ptr(0x5D4594, 2487844) + 56), range2,
										nox_xxx_lightningCanAttackCheck_52FF10, *getMemIntPtr(0x5D4594, 2487844));
		if (nox_xxx_lightningTarget_5d4594_2487908) {
			v16 = nox_xxx_lightningTargetArrayIndex_5d4594_2487904;
			// THIS SETS *getMemU32Ptr(0x5D4594, 2487852)!!!
			// Since the range is less than the first bounce target check, it always sets third member
			// Third member of  2487844 is the second bounce target from main target
			*getMemU32Ptr(0x5D4594, 2487844 + 4 * nox_xxx_lightningTargetArrayIndex_5d4594_2487904) =
				nox_xxx_lightningTarget_5d4594_2487908;
			nox_xxx_lightningTargetArrayIndex_5d4594_2487904 = v16 + 1;
		}
	}

	if (*getMemU32Ptr(0x5D4594, 2487848)) {
		// Fourth level of magic allows TWO jump from main target and ONE from secondary target
		// OR one jump from main target and one jump from secondary target
		if (spellLevel > 3) {
			nox_xxx_lightningTarget_5d4594_2487908 = 0;
			*(float*)&nox_xxx_lightningClosestTargetDistance_5d4594_2487912 = lightningRange * lightningRange;
			range3 = lightningRange * 0.85000002;
			nox_xxx_unitsGetInCircle_517F90((float2*)(*getMemU32Ptr(0x5D4594, 2487848) + 56), range3,
											nox_xxx_lightningCanAttackCheck_52FF10,
											*(int*)&*getMemU32Ptr(0x5D4594, 2487848));
			if (nox_xxx_lightningTarget_5d4594_2487908) {
				v17 = nox_xxx_lightningTargetArrayIndex_5d4594_2487904;
				// THIS SETS *getMemU32Ptr(0x5D4594, 2487852)
				// OR *getMemU32Ptr(0x5D4594, 2487856), if we have a second bounce already!!!
				// third member of 2487844 is the second bounce target.
				*getMemU32Ptr(0x5D4594, 2487844 + 4 * nox_xxx_lightningTargetArrayIndex_5d4594_2487904) =
					nox_xxx_lightningTarget_5d4594_2487908;
				nox_xxx_lightningTargetArrayIndex_5d4594_2487904 = v17 + 1;
			}
		}
	}
	if (*getMemU32Ptr(0x5D4594, 2487852)) {
		if (spellLevel > 4) {
			// FIFTH level of magic allows TWO jump from main target and ONE from EACH secondary target
			// OR one jump from main target and TWO consecutive jumps!!!
			nox_xxx_lightningTarget_5d4594_2487908 = 0;
			range5 = lightningRange * lightningRange; // Is this intentional???
			*(float*)&nox_xxx_lightningClosestTargetDistance_5d4594_2487912 = lightningRange * lightningRange;
			range4 = lightningRange * 0.80000001;
			nox_xxx_unitsGetInCircle_517F90((float2*)(*getMemU32Ptr(0x5D4594, 2487852) + 56), range4,
											nox_xxx_lightningCanAttackCheck_52FF10,
											*(int*)&*getMemU32Ptr(0x5D4594, 2487852));
			if (nox_xxx_lightningTarget_5d4594_2487908) {
				v18 = nox_xxx_lightningTargetArrayIndex_5d4594_2487904;
				// THIS SETS 2487860 OR 2487856
				*getMemU32Ptr(0x5D4594, 2487844 + 4 * nox_xxx_lightningTargetArrayIndex_5d4594_2487904) =
					nox_xxx_lightningTarget_5d4594_2487908;
				nox_xxx_lightningTargetArrayIndex_5d4594_2487904 = v18 + 1;
			}
		}
	}

	nox_xxx_lightningSpellDuration_52FFD0(source, *(uint32_t*)(source + 16), *getMemIntPtr(0x5D4594, 2487844));

	if (spellLevel > 1 && *getMemU32Ptr(0x5D4594, 2487848)) {
		nox_xxx_lightningSpellDuration_52FFD0(source, *getMemIntPtr(0x5D4594, 2487844),
											  *getMemU32Ptr(0x5D4594, 2487848));
	}

	secondBounceTarget = *getMemU32Ptr(0x5D4594, 2487852);
	if (spellLevel > 2 && *getMemU32Ptr(0x5D4594, 2487852)) {
		nox_xxx_lightningSpellDuration_52FFD0(source, *getMemIntPtr(0x5D4594, 2487844),
											  *getMemU32Ptr(0x5D4594, 2487852));
		secondBounceTarget = *getMemU32Ptr(0x5D4594, 2487852);
	}

	if (spellLevel > 3 && *getMemU32Ptr(0x5D4594, 2487856)) {
		if (*getMemU32Ptr(0x5D4594, 2487848)) {
			nox_xxx_lightningSpellDuration_52FFD0(source, *getMemU32Ptr(0x5D4594, 2487848),
												  *getMemU32Ptr(0x5D4594, 2487856));
		LABEL_54:
			secondBounceTarget = *getMemU32Ptr(0x5D4594, 2487852);
			goto LABEL_55;
		}
		if (secondBounceTarget) {
			nox_xxx_lightningSpellDuration_52FFD0(source, secondBounceTarget, *getMemU32Ptr(0x5D4594, 2487856));
			goto LABEL_54;
		}
	}
LABEL_55:
	if (spellLevel > 4) {
		// This is the fourth jump!!!
		if (*getMemU32Ptr(0x5D4594, 2487860)) {
			if (secondBounceTarget || (secondBounceTarget = *getMemU32Ptr(0x5D4594, 2487848)) != 0) {
				nox_xxx_lightningSpellDuration_52FFD0(source, secondBounceTarget, *getMemIntPtr(0x5D4594, 2487860));
			}
		}
	}
	// No main target
	if (!*getMemU32Ptr(0x5D4594, 2487844)) {
		return 0;
	}

	damage = nox_xxx_gamedataGetFloat_419D40("LightningDamage") + *(float*)(source + 76);
	v20 = nox_float2int(damage);
	*(float*)(source + 76) = damage - (double)v20;
	v21 = *(uint32_t**)(source + 108);
	for (j = *(uint32_t**)(source + 104); v21; v21 = (uint32_t*)v21[29]) {
		if (j) {
			v23 = j[12];
			if (v21[12] != v23 || v21[4] != j[4]) {
				if (v23) {
					nox_xxx_netStopRaySpell_4FEF90((int)j, (uint32_t*)j[12]);
				}
				nox_xxx_netStartDurationRaySpell_4FF130((int)v21);
			}
			j = (uint32_t*)j[29];
		} else {
			nox_xxx_netStartDurationRaySpell_4FF130((int)v21);
		}
		if (v20 > 0) {
			(*(void (**)(uint32_t, uint32_t, uint32_t, int, int))(v21[12] + 716))(v21[12], *(uint32_t*)(source + 16), 0,
																				  v20, 17);
		}
		v24 = v21[12];
		if (*(uint32_t*)(v24 + 16) & 0x8020) {
			nox_xxx_netSendPointFx_522FF0(129, (float2*)(v24 + 56));
		}
	}
	for (; j; j = (uint32_t*)j[29]) {
		if (j[12]) {
			nox_xxx_netStopRaySpell_4FEF90((int)j, (uint32_t*)j[12]);
		}
	}
	v25 = *(uint32_t*)(source + 16);
	if (*(uint8_t*)(v25 + 8) & 4) {
		v26 = *(uint32_t*)(source + 72);
		if (v26) {
			v27 = *(uint32_t*)(v26 + 736);
			v28 = *(uint8_t*)(v27 + 108);
			if (!v28) {
				return 1;
			}
			v29 = v28 - 1;
			*(uint8_t*)(v27 + 108) = v29;
			*(uint32_t*)(v27 + 112) = 100 * v29 / *(unsigned char*)(v27 + 109);
			v30 = *(uint32_t*)(source + 16);
			if (v30 && *(uint8_t*)(v30 + 8) & 4) {
				v31 = *(uint32_t*)(v30 + 748);
				nox_xxx_playerSetState_4FA020((uint32_t*)v30, 22);
				nox_xxx_netReportCharges_4D82B0(*(unsigned char*)(*(uint32_t*)(v31 + 276) + 2064),
												*(uint32_t**)(source + 72), *(uint8_t*)(v27 + 108),
												*(uint8_t*)(v27 + 109));
			}
			if (!*(uint8_t*)(v27 + 108)) {
				return 1;
			}
		} else {
			nox_xxx_playerSetState_4FA020((uint32_t*)v25, 10);
			nox_xxx_playerManaSub_4EEBF0(*(uint32_t*)(source + 16), 1);
			if (!nox_xxx_unitGetOldMana_4EEC80(*(uint32_t*)(source + 16))) {
				return 1;
			}
		}
	}
	if (!(nox_frame_xxx_2598000 % (nox_gameFPS / 3u))) {
		nox_xxx_aud_501960(78, *(uint32_t*)(source + 16), 0, 0);
		nox_xxx_aud_501960(78, *getMemIntPtr(0x5D4594, 2487844), 0, 0);
	}

	lightningSearchTime = nox_xxx_gamedataGetFloat_419D40("LightningSearchTime");
	*(uint32_t*)(source + 68) = nox_frame_xxx_2598000 + nox_float2int(lightningSearchTime);

	return 0;
}

//----- (0052FF10) --------------------------------------------------------
void nox_xxx_lightningCanAttackCheck_52FF10(int target, int source) {
	int owner;                         // eax
	int v3;                            // ecx
	int index;                         // eax
	unsigned char* ptrTargetFromArray; // ecx
	double xDistance;                  // st7
	double yDistance;                  // st6
	double distance;                   // st5

	if (*(uint32_t*)(target + 8) & 0x20006) { // Type check
		// Checks if the target is an enemy of the owner, if not, stop
		owner = nox_xxx_lightningOwner_5d4594_2487900;
		if (nox_xxx_lightningOwner_5d4594_2487900) {
			if (!nox_xxx_unitIsEnemyTo_5330C0(*(int*)&nox_xxx_lightningOwner_5d4594_2487900, target)) {
				return;
			}
			owner = nox_xxx_lightningOwner_5d4594_2487900;
		}
		if (!(*(uint8_t*)(target + 8) & 2) || (v3 = *(uint32_t*)(target + 12), (v3 & 0x8000) == 0)) {
			if (!(*(uint32_t*)(target + 16) & 0x8020) && target != source && target != owner) {
				index = 0;
				if (*(int*)&nox_xxx_lightningTargetArrayIndex_5d4594_2487904 <= 0) {
				LABEL_14:
					if (nox_xxx_unitCanInteractWith_5370E0(source, target, 0)) {
						xDistance = *(float*)(target + 56) - *(float*)(source + 56);
						yDistance = *(float*)(target + 60) - *(float*)(source + 60);
						distance = yDistance * yDistance + xDistance * xDistance;
						if (distance < *(float*)&nox_xxx_lightningClosestTargetDistance_5d4594_2487912) {
							*(float*)&nox_xxx_lightningClosestTargetDistance_5d4594_2487912 = distance;
							nox_xxx_lightningTarget_5d4594_2487908 = target;
						}
					}
				} else {
					ptrTargetFromArray = getMemAt(0x5D4594, 2487844);
					while (*(uint32_t*)ptrTargetFromArray != target) {
						++index;
						ptrTargetFromArray += 4;
						if (index >= *(int*)&nox_xxx_lightningTargetArrayIndex_5d4594_2487904) {
							goto LABEL_14;
						}
					}
				}
			}
		}
	}
}
//----- (0052FFD0) --------------------------------------------------------
uint32_t* nox_xxx_lightningSpellDuration_52FFD0(int source, int from, int to) {
	uint32_t* result; // eax
	int v4;           // ecx
	int v5;           // ecx

	result = nox_xxx_newSpellDuration_4FE950();
	if (result) {
		result[12] = to;
		result[4] = from;
		result[1] = 7;
		result[27] = 0;
		result[26] = 0;
		v4 = *(uint32_t*)(source + 108);
		result[28] = 0;
		result[29] = v4;
		v5 = *(uint32_t*)(source + 108);
		if (v5) {
			*(uint32_t*)(v5 + 112) = result;
		}
		*(uint32_t*)(source + 108) = result;
	}
	return result;
}

//----- (00530020) --------------------------------------------------------
void nox_xxx_lightningSpellTrapEffect_530020(int a1, int a2) {
	int v2;    // eax
	int v3;    // eax
	float v4;  // edx
	float v5;  // eax
	int v6;    // eax
	int v7;    // eax
	float v8;  // [esp+0h] [ebp-20h]
	float4 v9; // [esp+10h] [ebp-10h]

	if (a1 != a2) {
		v2 = *(uint32_t*)(a1 + 8);
		if (v2 & 6) {
			if (!(*(uint32_t*)(a1 + 16) & 0x8020)) {
				if (!(v2 & 2) || (v3 = *(uint32_t*)(a1 + 12), (v3 & 0x8000) == 0)) {
					if (!a2 || nox_xxx_unitIsEnemyTo_5330C0(a2, a1)) {
						v4 = *(float*)(a1 + 56);
						v9.field_4 = *getMemFloatPtr(0x5D4594, 2487824);
						v9.field_0 = *getMemFloatPtr(0x5D4594, 2487820);
						v5 = *(float*)(a1 + 60);
						v9.field_8 = v4;
						v9.field_C = v5;
						if (nox_xxx_mapTraceRay_535250(&v9, 0, 0, 9)) {
							v8 = nox_xxx_gamedataGetFloat_419D40("LightningGlyphDamage");
							v6 = nox_float2int(v8);
							(*(void (**)(int, uint32_t, uint32_t, int, int))(a1 + 716))(a1, 0, 0, v6, 17);
							nox_xxx_netSendPointFx_522FF0(129, (float2*)(a1 + 56));
							v7 = nox_xxx_spellGetAud44_424800(43, 0);
							nox_xxx_aud_501960(v7, a1, 0, 0);
						}
					}
				}
			}
		}
	}
}

//----- (00530100) --------------------------------------------------------
char sub_530100(uint32_t* a1) {
	int v1; // eax
	int v2; // esi
	int v3; // eax
	int v4; // esi
	int v5; // edi
	int v6; // edi

	v1 = a1[27];
	if (v1) {
		do {
			v2 = *(uint32_t*)(v1 + 116);
			sub_4FE980(v1);
			v1 = v2;
		} while (v2);
	}
	v3 = a1[26];
	a1[27] = 0;
	if (v3) {
		do {
			v4 = *(uint32_t*)(v3 + 116);
			sub_4FE980(v3);
			v3 = v4;
		} while (v4);
	}
	a1[26] = 0;
	v5 = a1[18];
	if (v5) {
		v6 = *(uint32_t*)(v5 + 736);
		v3 = *(uint32_t*)(v6 + 96);
		LOBYTE(v3) = v3 & 0xFB;
		*(uint32_t*)(v6 + 96) = v3;
	}
	return v3;
}

//----- (00530160) --------------------------------------------------------
int nox_xxx_spellTagCreature_530160(uint32_t* a1) {
	int v1;       // eax
	int v2;       // edi
	int v3;       // eax
	uint32_t* v4; // eax
	short v5;     // ax
	int v6;       // ecx
	short v7;     // dx
	float v9;     // [esp+0h] [ebp-14h]
	char v10[7];  // [esp+Ch] [ebp-8h]

	v1 = a1[4];
	v2 = *(uint32_t*)(v1 + 748);
	if (!v1) {
		return 1;
	}
	if (*(uint32_t*)(v1 + 16) & 0x8020) {
		return 1;
	}
	if (!(*(uint8_t*)(v1 + 8) & 4)) {
		return 1;
	}
	v3 = a1[12];
	if (!v3 || *(uint32_t*)(v3 + 16) & 0x8020) {
		return 1;
	}
	v9 = nox_xxx_gamedataGetFloat_419D40("TagDurationPerLevel");
	a1[17] = nox_frame_xxx_2598000 + a1[2] * nox_float2int(v9);
	nox_xxx_netMarkMinimapObject_417190(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), a1[12], 1);
	v4 = (uint32_t*)a1[12];
	v10[0] = -46;
	v5 = nox_xxx_netGetUnitCodeServ_578AC0(v4);
	v6 = a1[12];
	*(uint16_t*)&v10[1] = v5;
	v7 = *(uint16_t*)(v6 + 4);
	v10[5] = 1;
	*(uint16_t*)&v10[3] = v7;
	v10[6] = 1;
	nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v10, 7, 0, 1);
	return 0;
}

//----- (00530250) --------------------------------------------------------
unsigned int sub_530250(int a1) {
	int v1;              // eax
	unsigned int result; // eax

	v1 = *(uint32_t*)(a1 + 48);
	if (v1) {
		result = ((*(uint32_t*)(v1 + 16) & 0xFFu) >> 5) & 1;
	} else {
		result = 1;
	}
	return result;
}

//----- (00530270) --------------------------------------------------------
int sub_530270(int a1) {
	int result;   // eax
	int v2;       // edi
	uint32_t* v3; // edx
	short v4;     // cx
	char v5[7];   // [esp+8h] [ebp-8h]

	result = *(uint32_t*)(a1 + 16);
	if (result) {
		if (*(uint8_t*)(result + 8) & 4) {
			v2 = *(uint32_t*)(result + 748);
			result = *(uint32_t*)(a1 + 48);
			if (result) {
				if (!(*(uint8_t*)(result + 8) & 4)) {
					nox_xxx_netUnmarkMinimapObj_417300(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), result, 1);
				}
				v3 = *(uint32_t**)(a1 + 48);
				v5[0] = -46;
				*(uint16_t*)&v5[1] = nox_xxx_netGetUnitCodeServ_578AC0(v3);
				v4 = *(uint16_t*)(*(uint32_t*)(a1 + 48) + 4);
				v5[5] = 2;
				*(uint16_t*)&v5[3] = v4;
				v5[6] = 1;
				result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v5, 7, 0, 1);
			}
		}
	}
	return result;
}

//----- (00530310) --------------------------------------------------------
int nox_xxx_spellBlink2_530310(uint32_t* a1) {
	int result; // eax
	float v2;   // [esp+0h] [ebp-8h]

	if (!nox_common_gameFlags_check_40A5C0(4096) || (result = 1, a1[5] != 1)) {
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			v2 = nox_xxx_gamedataGetFloatTable_419D70("TeleportDelay", a1[2] - 1);
			a1[17] = nox_frame_xxx_2598000 + nox_float2int(v2);
			result = 0;
		} else {
			result = 0;
			a1[17] = nox_frame_xxx_2598000 + 1;
		}
	}
	return result;
}

//----- (00530380) --------------------------------------------------------
int nox_xxx_spellBlink1_530380(int* a1) {
	int v1;     // eax
	int v3;     // eax
	float2* v4; // ecx
	int v5;     // eax
	bool v6;    // zf
	int v7;     // eax
	int v8;     // eax
	int v9;     // [esp-Ch] [ebp-18h]
	int v10;    // [esp-Ch] [ebp-18h]
	int v11;    // [esp-8h] [ebp-14h]
	int v12;    // [esp-4h] [ebp-10h]
	float2 v13; // [esp+4h] [ebp-8h]

	v1 = a1[12];
	if (!v1) {
		return 1;
	}
	if (*(uint32_t*)(v1 + 16) & 0x8020) {
		return 1;
	}
	if (a1[17] - 1 == nox_frame_xxx_2598000) {
		if (nox_xxx_testUnitBuffs_4FF350(v1, 14)) {
			nox_xxx_aud_501960(231, a1[12], 0, 0);
			return 1;
		}
		if (nox_common_gameFlags_check_40A5C0(4096) && (v3 = a1[12], *(uint8_t*)(v3 + 8) & 4)) {
			v4 = *(float2**)(*(uint32_t*)(v3 + 748) + 308);
			if (v4) {
				sub_4ED970(60.0, v4 + 7, &v13);
			} else {
				nox_xxx_mapFindPlayerStart_4F7AB0(&v13, a1[12]);
			}
		} else if (!nox_xxx_waypoint_579F00(&v13, a1[12])) {
			nox_xxx_mapFindPlayerStart_4F7AB0(&v13, a1[12]);
		}
		nox_xxx_spellTeleportCreateWake_530560(a1[12], (int*)(a1[12] + 56), &v13);
		nox_xxx_netSendPointFx_522FF0(137, (float2*)(a1[12] + 56));
		v9 = a1[12];
		v5 = nox_xxx_spellGetAud44_424800(a1[1], 0);
		nox_xxx_aud_501960(v5, v9, 0, 0);
		if (!nox_xxx_testUnitBuffs_4FF350(a1[12], 0)) {
			nox_xxx_netSendPointFx_522FF0(137, (float2*)(a1[12] + 56));
			nox_xxx_netSendPointFx_522FF0(137, &v13);
		}
		nox_xxx_teleportToMB_4E7190((uint8_t*)a1[12], &v13.field_0);
		v6 = !nox_xxx_testUnitBuffs_4FF350(a1[12], 0);
		v7 = a1[12];
		if (v6) {
			nox_xxx_netSendPointFx_522FF0(137, (float2*)(v7 + 56));
			v12 = 0;
			v11 = 0;
			v10 = a1[12];
		} else {
			if (!(*(uint8_t*)(v7 + 8) & 4)) {
			LABEL_22:
				sub_4E7540(a1[4], a1[12]);
				return 1;
			}
			v12 = *(uint32_t*)(v7 + 36);
			v11 = 2;
			v10 = a1[12];
		}
		v8 = nox_xxx_spellGetAud44_424800(a1[1], 0);
		nox_xxx_aud_501960(v8, v10, v11, v12);
		goto LABEL_22;
	}
	return 0;
}

//----- (00530560) --------------------------------------------------------
uint32_t* nox_xxx_spellTeleportCreateWake_530560(int a1, int* a2, uint32_t* a3) {
	int v3;           // eax
	uint32_t* result; // eax
	uint32_t* v5;     // esi
	uint32_t* v6;     // eax

	v3 = *getMemU32Ptr(0x5D4594, 2487916);
	if (!*getMemU32Ptr(0x5D4594, 2487916)) {
		v3 = nox_xxx_getNameId_4E3AA0("TeleportWake");
		*getMemU32Ptr(0x5D4594, 2487916) = v3;
	}
	result = nox_xxx_newObjectWithTypeInd_4E3450(v3);
	v5 = result;
	if (result) {
		v6 = (uint32_t*)result[175];
		*v6 = *a3;
		v6[1] = a3[1];
		nox_xxx_createAt_4DAA50((int)v5, a1, *(float*)a2, *((float*)a2 + 1));
		result = (uint32_t*)(nox_frame_xxx_2598000 + nox_gameFPS);
		v5[34] = nox_frame_xxx_2598000 + nox_gameFPS;
	}
	return result;
}

//----- (005305D0) --------------------------------------------------------
int sub_5305D0(uint32_t* a1) {
	int v1;   // eax
	int v2;   // eax
	float v4; // [esp+0h] [ebp-8h]

	v1 = a1[3];
	if (*(uint8_t*)(v1 + 8) & 4) {
		v2 = *(uint32_t*)(v1 + 748);
		if (!v2 || !*(uint32_t*)(v2 + 4 * a1[1] - 372)) {
			return 1;
		}
	}
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v4 = nox_xxx_gamedataGetFloatTable_419D70("TeleportDelay", a1[2] - 1);
		a1[17] = nox_frame_xxx_2598000 + nox_float2int(v4);
	} else {
		a1[17] = nox_frame_xxx_2598000 + 1;
	}
	return 0;
}

//----- (00530650) --------------------------------------------------------
int sub_530650(int* a1) {
	int v1;     // ecx
	int v2;     // eax
	int v4;     // eax
	int v5;     // ebp
	int v6;     // edi
	int v7;     // edx
	int v8;     // ecx
	int v9;     // eax
	int v10;    // eax
	int v11;    // eax
	char v12;   // al
	int v13;    // eax
	int v14;    // [esp-10h] [ebp-24h]
	int v15;    // [esp-Ch] [ebp-20h]
	int v16;    // [esp-8h] [ebp-1Ch]
	int v17;    // [esp-4h] [ebp-18h]
	float2 v18; // [esp+Ch] [ebp-8h]

	v1 = a1[3];
	if (!v1) {
		return 1;
	}
	if (*(uint8_t*)(v1 + 16) & 0x20) {
		return 1;
	}
	v2 = a1[12];
	if (!v2 || *(uint32_t*)(v2 + 16) & 0x8020 || v2 != v1 && !a1[5]) {
		return 1;
	}
	if (a1[17] - 1 != nox_frame_xxx_2598000) {
		return 0;
	}
	if (nox_xxx_testUnitBuffs_4FF350(v2, 14)) {
		nox_xxx_aud_501960(231, a1[12], 0, 0);
		return 1;
	}
	v4 = a1[3];
	if (*(uint8_t*)(v4 + 8) & 4) {
		v5 = *(uint32_t*)(v4 + 748);
		v6 = a1[1] - 122;
		v7 = *(uint32_t*)(v5 + 4 * v6 + 116);
		if (!v7) {
			return 1;
		}
		v8 = a1[12];
		v18 = *(float2*)(v8 + 56);
		nox_xxx_spellTeleportCreateWake_530560(v8, (int*)(v8 + 56), (uint32_t*)(v7 + 56));
		v14 = a1[12];
		v9 = nox_xxx_spellGetAud44_424800(a1[1], 1);
		nox_xxx_aud_501960(v9, v14, 0, 0);
		nox_xxx_teleportToMB_4E7190((uint8_t*)a1[12], (float*)(*(uint32_t*)(v5 + 4 * v6 + 116) + 56));
		if (nox_xxx_testUnitBuffs_4FF350(a1[12], 0)) {
			v10 = a1[12];
			if (!(*(uint8_t*)(v10 + 8) & 4)) {
				goto LABEL_18;
			}
			v17 = *(uint32_t*)(v10 + 36);
			v16 = 2;
			v15 = a1[12];
		} else {
			nox_xxx_netSendPointFx_522FF0(137, &v18);
			nox_xxx_netSendPointFx_522FF0(137, (float2*)(a1[12] + 56));
			v17 = 0;
			v16 = 0;
			v15 = a1[12];
		}
		v11 = nox_xxx_spellGetAud44_424800(a1[1], 1);
		nox_xxx_aud_501960(v11, v15, v16, v17);
	LABEL_18:
		*(uint32_t*)(*(uint32_t*)(v5 + 4 * v6 + 116) + 136) = nox_frame_xxx_2598000;
		v12 = *(uint8_t*)(v6 + v5 + 156) - 1;
		*(uint8_t*)(v6 + v5 + 156) = v12;
		if (!v12) {
			nox_xxx_netSendPointFx_522FF0(129, (float2*)(*(uint32_t*)(v5 + 4 * v6 + 116) + 56));
			nox_xxx_delayedDeleteObject_4E5CC0(*(uint32_t*)(v5 + 4 * v6 + 116));
			*(uint32_t*)(v5 + 4 * v6 + 116) = 0;
		}
	}
	v13 = a1[4];
	if (!v13 || *(uint8_t*)(v13 + 16) & 0x20) {
		return 1;
	}
	sub_4E7540(v13, a1[12]);
	return 1;
}

//----- (00530820) --------------------------------------------------------
int nox_xxx_castTele_530820(int a1) {
	int result; // eax
	float v2;   // [esp+0h] [ebp-8h]

	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v2 = nox_xxx_gamedataGetFloatTable_419D70("TeleportDelay", *(uint32_t*)(a1 + 8) - 1);
		*(uint32_t*)(a1 + 68) = nox_frame_xxx_2598000 + nox_float2int(v2);
		result = 0;
	} else {
		result = 0;
		*(uint32_t*)(a1 + 68) = nox_frame_xxx_2598000 + 1;
	}
	return result;
}

//----- (00530880) --------------------------------------------------------
int sub_530880(int* a1) {
	int v1;       // eax
	int v2;       // eax
	int v4;       // eax
	int v5;       // edi
	int v6;       // edx
	int v7;       // ecx
	uint32_t* v8; // eax
	int v9;       // eax
	int v10;      // esi
	int v11;      // eax
	char v12;     // al
	int v13;      // [esp-Ch] [ebp-20h]
	float2 v14;   // [esp+Ch] [ebp-8h]

	v1 = a1[4];
	if (!v1) {
		return 1;
	}
	if (*(uint32_t*)(v1 + 16) & 0x8020) {
		return 1;
	}
	v2 = a1[12];
	if (!v2 || *(uint32_t*)(v2 + 16) & 0x8020) {
		return 1;
	}
	if (a1[17] - 1 != nox_frame_xxx_2598000) {
		return 0;
	}
	if (nox_xxx_testUnitBuffs_4FF350(v2, 14)) {
		nox_xxx_aud_501960(231, a1[12], 0, 0);
		return 1;
	}
	v4 = a1[4];
	if (*(uint8_t*)(v4 + 8) & 4) {
		v5 = *(uint32_t*)(v4 + 748);
		v6 = 0;
		v7 = 4;
		v8 = (uint32_t*)(v5 + 116);
		do {
			if (*v8) {
				++v6;
			}
			++v8;
			--v7;
		} while (v7);
		if (!v6) {
			return 1;
		}
		v9 = a1[12];
		v14 = *(float2*)(a1[12] + 56);
		do {
			v10 = nox_common_randomInt_415FA0(0, 3);
		} while (!*(uint32_t*)(v5 + 4 * v10 + 116));
		nox_xxx_spellTeleportCreateWake_530560(a1[12], (int*)(a1[12] + 56),
											   (uint32_t*)(*(uint32_t*)(v5 + 4 * v10 + 116) + 56));
		nox_xxx_teleportToMB_4E7190((uint8_t*)a1[12], (float*)(*(uint32_t*)(v5 + 4 * v10 + 116) + 56));
		if (!nox_xxx_testUnitBuffs_4FF350(a1[12], 0)) {
			nox_xxx_netSendPointFx_522FF0(137, &v14);
			nox_xxx_netSendPointFx_522FF0(137, (float2*)(a1[12] + 56));
		}
		v13 = a1[12];
		v11 = nox_xxx_spellGetAud44_424800(a1[1], 0);
		nox_xxx_aud_501960(v11, v13, 0, 0);
		v12 = *(uint8_t*)(v10 + v5 + 156) - 1;
		*(uint8_t*)(v10 + v5 + 156) = v12;
		if (!v12) {
			nox_xxx_netSendPointFx_522FF0(129, (float2*)(*(uint32_t*)(v5 + 4 * v10 + 116) + 56));
			nox_xxx_delayedDeleteObject_4E5CC0(*(uint32_t*)(v5 + 4 * v10 + 116));
			*(uint32_t*)(v5 + 4 * v10 + 116) = 0;
		}
	}
	sub_4E7540(a1[4], a1[12]);
	return 1;
}

//----- (00530B70) --------------------------------------------------------
int nox_xxx_castTTT_530B70(int* a1) {
	int v1;  // ecx
	int v2;  // eax
	int v4;  // eax
	int v5;  // eax
	int v6;  // eax
	int v7;  // [esp-Ch] [ebp-14h]
	int v8;  // [esp-Ch] [ebp-14h]
	int v9;  // [esp-8h] [ebp-10h]
	int v10; // [esp-4h] [ebp-Ch]

	v1 = a1[12];
	if (!v1) {
		return 1;
	}
	v2 = a1[4];
	if (!v2 || *(uint32_t*)(v1 + 16) & 0x8020 || *(uint32_t*)(v2 + 16) & 0x8020) {
		return 1;
	}
	if (a1[17] - 1 == nox_frame_xxx_2598000) {
		if (nox_xxx_testUnitBuffs_4FF350(v1, 14)) {
			nox_xxx_aud_501960(231, a1[12], 0, 0);
			return 1;
		}
		nox_xxx_netSendPointFx_522FF0(137, (float2*)(a1[12] + 56));
		v7 = a1[12];
		v4 = nox_xxx_spellGetAud44_424800(a1[1], 0);
		nox_xxx_aud_501960(v4, v7, 0, 0);
		nox_xxx_spellTeleportCreateWake_530560(a1[12], (int*)(a1[12] + 56), a1 + 13);
		nox_xxx_teleportToMB_4E7190((uint8_t*)a1[12], (float*)a1 + 13);
		if (nox_xxx_testUnitBuffs_4FF350(a1[12], 0)) {
			v6 = a1[12];
			if (!(*(uint8_t*)(v6 + 8) & 4)) {
			LABEL_14:
				sub_4E7540(a1[4], a1[12]);
				return 1;
			}
			v10 = *(uint32_t*)(v6 + 36);
			v9 = 2;
			v8 = a1[12];
			v5 = nox_xxx_spellGetAud44_424800(a1[1], 0);
		} else {
			nox_xxx_netSendPointFx_522FF0(137, (float2*)(a1[12] + 56));
			v10 = 0;
			v9 = 0;
			v8 = a1[12];
			v5 = nox_xxx_spellGetAud44_424800(a1[1], 0);
		}
		nox_xxx_aud_501960(v5, v8, v9, v10);
		goto LABEL_14;
	}
	return 0;
}

//----- (00530CA0) --------------------------------------------------------
int sub_530CA0(int a1) {
	int v1;     // ecx
	int v2;     // eax
	int v3;     // ecx
	int result; // eax
	float v5;   // [esp+0h] [ebp-8h]

	v1 = *(uint32_t*)(a1 + 16);
	if (!v1) {
		return 1;
	}
	if (*(uint8_t*)(a1 + 88) & 0x20) {
		return 1;
	}
	v2 = *(uint32_t*)(a1 + 48);
	if (!v2) {
		return 1;
	}
	if (*(uint32_t*)(v2 + 16) & 0x8020) {
		return 1;
	}
	if (v1 == v2) {
		return 1;
	}
	if (*(uint8_t*)(v2 + 8) & 2) {
		v3 = *(uint32_t*)(v2 + 12);
		if (v3 & 0x4000) {
			return 1;
		}
	}
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v5 = nox_xxx_gamedataGetFloatTable_419D70("TeleportDelay", *(uint32_t*)(a1 + 8) - 1);
		*(uint32_t*)(a1 + 68) = nox_frame_xxx_2598000 + nox_float2int(v5);
		result = 0;
	} else {
		result = 0;
		*(uint32_t*)(a1 + 68) = nox_frame_xxx_2598000 + 1;
	}
	return result;
}

//----- (00530D30) --------------------------------------------------------
int sub_530D30(int* a1) {
	int* v1;    // esi
	int v2;     // ecx
	int v3;     // eax
	int result; // eax
	int v5;     // eax
	int v6;     // ecx
	float2* v7; // ecx
	int v8;     // eax
	int v9;     // eax
	int v10;    // eax
	int v11;    // [esp-Ch] [ebp-24h]
	int v12;    // [esp-Ch] [ebp-24h]
	float* v13; // [esp-4h] [ebp-1Ch]
	float4 v14; // [esp+8h] [ebp-10h]
	int v18;    // [esp+1Ch] [ebp+4h]

	v1 = a1;
	v2 = a1[12];
	if (!v2) {
		return 1;
	}
	v3 = a1[4];
	if (!v3 || *(uint32_t*)(v2 + 16) & 0x8020 || *(uint32_t*)(v3 + 16) & 0x8020) {
		return 1;
	}
	if (a1[17] - 1 != nox_frame_xxx_2598000) {
		return 0;
	}
	if (nox_xxx_testUnitBuffs_4FF350(v2, 14) || nox_xxx_testUnitBuffs_4FF350(a1[4], 14)) {
		nox_xxx_aud_501960(231, a1[12], 0, 0);
		nox_xxx_aud_501960(231, a1[4], 0, 0);
		result = 1;
	} else {
		if (a1[5]) {
			goto LABEL_23;
		}
		if (!nox_xxx_unitCanInteractWith_5370E0(a1[4], a1[12], 0)) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(a1[4], "ExecDur.c:NeedClearLOSForSwap", 0);
			return 1;
		}
		v5 = a1[4];
		if (!(*(uint8_t*)(v5 + 8) & 4) ||
			(v6 = *(uint32_t*)(v5 + 748),
			 v14.field_0 = *(float*)(v5 + 56) - (double)*(unsigned short*)(*(uint32_t*)(v6 + 276) + 10),
			 v14.field_4 = *(float*)(v5 + 60) - (double)*(unsigned short*)(*(uint32_t*)(v6 + 276) + 12),
			 v14.field_8 = (double)*(unsigned short*)(*(uint32_t*)(v6 + 276) + 10) + *(float*)(v5 + 56),
			 v18 = *(unsigned short*)(*(uint32_t*)(v6 + 276) + 12), v7 = (float2*)(v1[12] + 56),
			 v14.field_C = (double)v18 + *(float*)(v5 + 60), sub_428220(v7, &v14))) {
		LABEL_23:
			v8 = v1[12];
			v14.field_0 = *(float*)(v8 + 56);
			v13 = (float*)(v1[4] + 56);
			v14.field_4 = *(float*)(v8 + 60);
			nox_xxx_teleportToMB_4E7190((uint8_t*)v8, v13);
			nox_xxx_teleportToMB_4E7190((uint8_t*)v1[4], &v14);
			if (!nox_xxx_testUnitBuffs_4FF350(v1[12], 0) && !nox_xxx_testUnitBuffs_4FF350(v1[4], 0)) {
				nox_xxx_netSendPointFx_522FF0(137, (float2*)(v1[4] + 56));
				nox_xxx_netSendPointFx_522FF0(137, (float2*)(v1[12] + 56));
			}
			v11 = v1[12];
			v9 = nox_xxx_spellGetAud44_424800(v1[1], 0);
			nox_xxx_aud_501960(v9, v11, 0, 0);
			v12 = v1[4];
			v10 = nox_xxx_spellGetAud44_424800(v1[1], 0);
			nox_xxx_aud_501960(v10, v12, 0, 0);
			sub_4E7540(v1[4], v1[12]);
			result = 1;
		} else {
			nox_xxx_netPriMsgToPlayer_4DA2C0(v1[4], "ExecDur.c:NeedClearLOSForSwap", 0);
			result = 1;
		}
	}
	return result;
}

//----- (00530F90) --------------------------------------------------------
int nox_xxx_manaBomb_530F90(uint32_t* a1) {
	int v1;       // ecx
	uint32_t* v2; // ebx
	float v4;     // [esp+0h] [ebp-10h]
	float v5;     // [esp+0h] [ebp-10h]

	if (!*getMemU32Ptr(0x5D4594, 2487920)) {
		*getMemU32Ptr(0x5D4594, 2487920) = nox_xxx_getNameId_4E3AA0("ManaBombCharge");
	}
	v4 = nox_xxx_gamedataGetFloatTable_419D70("ManaBombInitPower", a1[2] - 1);
	a1[18] = nox_float2int(v4);
	a1[19] = 0;
	a1[21] = 0;
	v1 = a1[4];
	if (v1 && !(*(uint8_t*)(v1 + 8) & 4) || a1[5]) {
		v5 = nox_xxx_gamedataGetFloat_419D40("ManaBombGlyphDuration");
		a1[17] = nox_frame_xxx_2598000 + nox_float2int(v5);
	} else {
		nox_xxx_buffApplyTo_4FF380(v1, 5, 10 * (uint16_t)nox_gameFPS, 5);
		nox_xxx_buffApplyTo_4FF380(a1[4], 14, 10 * (uint16_t)nox_gameFPS, 5);
		nox_xxx_buffApplyTo_4FF380(a1[4], 29, 10 * (uint16_t)nox_gameFPS, 5);
		a1[20] = *(uint32_t*)(a1[4] + 120);
		*(uint32_t*)(a1[4] + 120) = 1203982323;
		*(uint32_t*)(a1[4] + 84) = 0;
		*(uint32_t*)(a1[4] + 80) = 0;
		*(uint32_t*)(a1[4] + 92) = 0;
		*(uint32_t*)(a1[4] + 88) = 0;
		*(uint32_t*)(a1[4] + 100) = 0;
		*(uint32_t*)(a1[4] + 96) = 0;
	}
	v2 = nox_xxx_newObjectWithTypeInd_4E3450(*getMemIntPtr(0x5D4594, 2487920));
	if (v2) {
		nox_xxx_createAt_4DAA50((int)v2, 0, *((float*)a1 + 7), *((float*)a1 + 8));
		a1[19] = v2;
	}
	return 0;
}

//----- (005310C0) --------------------------------------------------------
int nox_xxx_manaBombBoom_5310C0(int* a1) {
	int v1;     // edi
	int v2;     // eax
	int v4;     // eax
	bool v5;    // zf
	int v6;     // edi
	float v7;   // edx
	int v8;     // eax
	int v9;     // eax
	float v10;  // [esp+0h] [ebp-28h]
	float v11;  // [esp+4h] [ebp-24h]
	int v12;    // [esp+10h] [ebp-18h]
	float v13;  // [esp+14h] [ebp-14h]
	float v14;  // [esp+14h] [ebp-14h]
	float2 v15; // [esp+20h] [ebp-8h]

	v1 = 0;
	v2 = a1[4];
	if (!v2 && !a1[5]) {
		return 1;
	}
	if (a1[17] - 1 == nox_frame_xxx_2598000) {
		v1 = 1;
	}
	if (v2 && *(uint8_t*)(v2 + 8) & 4 && !nox_xxx_unitGetOldMana_4EEC80(a1[4])) {
		v1 = 1;
	}
	if (a1[19]) {
		if (!a1[5] && (v4 = a1[4]) != 0 && *(uint8_t*)(v4 + 8) & 4) {
			if ((unsigned short)nox_xxx_unitGetOldMana_4EEC80(a1[4]) >= 0xFu) {
				goto LABEL_18;
			}
		} else if ((unsigned int)(a1[17] - nox_frame_xxx_2598000) >= 0xA) {
			goto LABEL_18;
		}
		nox_xxx_delayedDeleteObject_4E5CC0(a1[19]);
		a1[19] = 0;
	}
LABEL_18:
	v5 = v1 == 0;
	v6 = a1[18];
	if (!v5) {
		if (a1[5]) {
			v7 = *((float*)a1 + 8);
			v15.field_0 = *((float*)a1 + 7);
		} else {
			v8 = a1[4];
			if (!v8) {
				return 1;
			}
			v15.field_0 = *(float*)(v8 + 56);
			v7 = *(float*)(v8 + 60);
		}
		v15.field_4 = v7;
		nox_xxx_gameSetWallsDamage_4E25A0(1);
		v12 = a1[4];
		v11 = nox_xxx_gamedataGetFloat_419D40("ManaBombInRadius");
		v10 = nox_xxx_gamedataGetFloat_419D40("ManaBombOutRadius");
		nox_xxx_mapDamageUnitsAround_4E25B0(&v15, v10, v11, v6, 15, v12, 0);
		v13 = nox_xxx_gamedataGetFloat_419D40("ManaBombShakeMag");
		v9 = nox_float2int(v13);
		nox_xxx_earthquakeSend_4D9110(&v15, v9);
		nox_xxx_netSendPointFx_522FF0(129, &v15);
		nox_xxx_netSendPointFx_522FF0(154, &v15);
		nox_xxx_aud_501960(81, a1[4], 0, 0);
		a1[21] = 1;
		return 1;
	}
	v14 = nox_xxx_gamedataGetFloatTable_419D70("ManaBombDeltaPower", a1[2] - 1);
	a1[18] = v6 + nox_float2int(v14);
	if (!a1[5]) {
		if (sub_4E7BC0(a1[4])) {
			nox_xxx_playerManaSub_4EEBF0(a1[4], a1[2]);
		}
	}
	return 0;
}

//----- (00531290) --------------------------------------------------------
int sub_531290(int a1) {
	int v1;     // eax
	int result; // eax

	if (*(uint32_t*)(a1 + 76)) {
		nox_xxx_delayedDeleteObject_4E5CC0(*(uint32_t*)(a1 + 76));
		*(uint32_t*)(a1 + 76) = 0;
	}
	if (!*(uint32_t*)(a1 + 20)) {
		v1 = *(uint32_t*)(a1 + 16);
		if (v1) {
			if (*(uint8_t*)(v1 + 8) & 4) {
				nox_xxx_spellBuffOff_4FF5B0(v1, 5);
				nox_xxx_spellBuffOff_4FF5B0(*(uint32_t*)(a1 + 16), 14);
				nox_xxx_spellBuffOff_4FF5B0(*(uint32_t*)(a1 + 16), 29);
				*(uint32_t*)(*(uint32_t*)(a1 + 16) + 120) = *(uint32_t*)(a1 + 80);
			}
		}
	}
	result = *(uint32_t*)(a1 + 84);
	if (!result) {
		result = nox_xxx_netSendPointFx_522FF0(163, (float2*)(a1 + 28));
	}
	return result;
}

//----- (00531310) --------------------------------------------------------
int nox_xxx_spellTurnUndeadCreate_531310(uint32_t* a1) {
	int v1;       // ecx
	int v2;       // edi
	uint32_t* v3; // eax
	uint32_t* v4; // esi
	int v5;       // eax
	double v6;    // st7
	float v8;     // [esp+0h] [ebp-18h]
	float2 v9;    // [esp+10h] [ebp-8h]

	v8 = nox_xxx_gamedataGetFloatTable_419D70("TurnUndeadKillPoints", a1[2] - 1);
	a1[18] = nox_float2int(v8);
	if (!*getMemU32Ptr(0x5D4594, 2487924)) {
		*getMemU32Ptr(0x5D4594, 2487924) = nox_xxx_getNameId_4E3AA0("UndeadKiller");
	}
	if (a1[5]) {
		v1 = a1[6];
	} else {
		v1 = a1[4];
	}
	v2 = 0;
	v9 = *(float2*)(v1 + 56);
	do {
		v3 = nox_xxx_newObjectWithTypeInd_4E3450(*getMemIntPtr(0x5D4594, 2487924));
		v4 = v3;
		if (v3) {
			*(uint32_t*)v3[175] = a1;
			nox_xxx_createAt_4DAA50((int)v3, a1[4], v9.field_0, v9.field_4);
			*((uint16_t*)v4 + 63) = v2;
			v5 = 8 * (short)v2;
			*((uint16_t*)v4 + 62) = v2;
			*((float*)v4 + 20) = *getMemFloatPtr(0x587000, 194136 + v5) * 4.0;
			v6 = *getMemFloatPtr(0x587000, 194140 + v5) * 4.0;
			v4[28] = 0;
			*((float*)v4 + 21) = v6;
		}
		v2 += 6;
	} while (v2 < 256);
	nox_xxx_netSendPointFx_522FF0(160, &v9);
	return 0;
}

//----- (00531410) --------------------------------------------------------
int nox_xxx_spellTurnUndeadUpdate_531410() { return 0; }

//----- (00531420) --------------------------------------------------------
int nox_xxx_spellTurnUndeadDelete_531420(int a1) {
	int result; // eax
	int i;      // esi

	if (!*getMemU32Ptr(0x5D4594, 2487928)) {
		*getMemU32Ptr(0x5D4594, 2487928) = nox_xxx_getNameId_4E3AA0("UndeadKiller");
	}
	result = nox_server_getFirstObject_4DA790();
	for (i = result; result; i = result) {
		if (*(unsigned short*)(i + 4) == *getMemU32Ptr(0x5D4594, 2487928) && **(uint32_t**)(i + 700) == a1) {
			nox_xxx_delayedDeleteObject_4E5CC0(i);
		}
		result = nox_server_getNextObject_4DA7A0(i);
	}
	return result;
}

//----- (00531490) --------------------------------------------------------
int sub_531490(uint32_t* a1) {
	int v1;     // eax
	int v2;     // edi
	int result; // eax

	v1 = a1[12];
	v2 = 20 * a1[2] * nox_gameFPS;
	if (!v1) {
		return 1;
	}
	if (!(*(uint8_t*)(v1 + 8) & 4)) {
		return 1;
	}
	sub_4FF310(a1[12]);
	nox_xxx_buffApplyTo_4FF380(a1[12], 27, v2, a1[2]);
	result = 0;
	a1[17] = v2 + nox_frame_xxx_2598000;
	return result;
}

//----- (005314F0) --------------------------------------------------------
int sub_5314F0(int a1) {
	int v1;     // eax
	int result; // eax
	int v3;     // eax

	v1 = *(uint32_t*)(a1 + 48);
	if (!v1) {
		return 1;
	}
	if (nox_xxx_testUnitBuffs_4FF350(v1, 8)) {
		return 1;
	}
	v3 = *(uint32_t*)(a1 + 48);
	if (v3 && *(uint8_t*)(v3 + 8) & 2 && sub_4FEA70(v3, (float2*)(a1 + 28))) {
		result = 1;
	} else {
		result = (*(uint32_t*)(*(uint32_t*)(a1 + 48) + 16) & 0x8020) != 0;
	}
	return result;
}

//----- (00531560) --------------------------------------------------------
int sub_531560(int a1) {
	int result; // eax

	result = *(uint32_t*)(a1 + 48);
	if (result) {
		result = nox_xxx_spellBuffOff_4FF5B0(result, 27);
	}
	return result;
}

//----- (00531580) --------------------------------------------------------
int nox_xxx_plasmaSmth_531580(int a1) {
	int v1; // eax
	int v2; // eax

	*(uint32_t*)(a1 + 72) = 0;
	*(uint32_t*)(a1 + 76) = 0;
	*(uint32_t*)(a1 + 48) = 0;
	nox_xxx_netSendPointFx_522FF0(131, (float2*)(a1 + 28));
	v1 = *(uint32_t*)(a1 + 16);
	if (!v1 || !(*(uint8_t*)(v1 + 8) & 4)) {
		return 0;
	}
	v2 = *(uint32_t*)(*(uint32_t*)(v1 + 748) + 104);
	if (v2 && *(uint32_t*)(v2 + 12) & 0x4000000) {
		if (*(uint8_t*)(*(uint32_t*)(v2 + 736) + 96) & 4) {
			*(uint32_t*)(a1 + 72) = v2;
			*(uint8_t*)(a1 + 88) |= 2u;
		}
		return 0;
	}
	return 1;
}

//----- (00531600) --------------------------------------------------------
int nox_xxx_plasmaShot_531600(int a1) {
	int v1;            // eax
	int v2;            // eax
	int v3;            // edi
	int v4;            // eax
	int v5;            // eax
	int v6;            // ecx
	int v7;            // eax
	int v8;            // eax
	double v9;         // st7
	int v10;           // eax
	int v11;           // eax
	int v12;           // eax
	int v13;           // edi
	unsigned char v14; // al
	unsigned char v15; // al
	int v16;           // eax
	int v17;           // ebp
	uint32_t* v19;     // [esp-4h] [ebp-18h]
	float v20;         // [esp+0h] [ebp-14h]
	float v21;         // [esp+0h] [ebp-14h]

	if (!*getMemU32Ptr(0x5D4594, 2487936)) {
		*getMemU32Ptr(0x5D4594, 2487936) = nox_xxx_getNameId_4E3AA0("Hecubah");
		*getMemU32Ptr(0x5D4594, 2487940) = nox_xxx_getNameId_4E3AA0("HecubahWithOrb");
	}
	v1 = *(uint32_t*)(a1 + 16);
	if (!v1 || *(uint8_t*)(a1 + 88) & 0x20 || *(uint8_t*)(v1 + 8) & 2 && sub_4FEA70(v1, (float2*)(a1 + 28))) {
		return 1;
	}
	v2 = *(uint32_t*)(a1 + 48);
	if (!v2) {
		goto LABEL_16;
	}
	if (*(uint32_t*)(v2 + 16) & 0x8020) {
		goto LABEL_53;
	}
	if (nox_server_testTwoPointsAndDirection_4E6E50((float2*)(*(uint32_t*)(a1 + 16) + 56),
													*(short*)(*(uint32_t*)(a1 + 16) + 124), (float2*)(v2 + 56)) &
		2) {
		if (!*(uint32_t*)(a1 + 76)) {
			*(uint32_t*)(a1 + 76) = 3 * nox_gameFPS;
		}
	} else {
		*(uint32_t*)(a1 + 76) = 0;
	}
	if (nox_xxx_calcDistance_4E6C00(*(uint32_t*)(a1 + 48), *(uint32_t*)(a1 + 16)) > 400.0 ||
		!nox_xxx_unitCanInteractWith_5370E0(*(uint32_t*)(a1 + 16), *(uint32_t*)(a1 + 48), 0)) {
	LABEL_53:
		*(uint32_t*)(a1 + 48) = 0;
	LABEL_16:
		v3 = *(uint32_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 16) + 748) + 288);
		dword_5d4594_2487932 = 0;
		if (!v3) {
			goto LABEL_54;
		}
		if (nox_xxx_unitIsEnemyTo_5330C0(*(uint32_t*)(a1 + 16), v3) &&
			nox_xxx_calcDistance_4E6C00(*(uint32_t*)(a1 + 16), v3) <= 400.0) {
			dword_5d4594_2487932 = v3;
		}
		if (!dword_5d4594_2487932) {
		LABEL_54:
			*getMemU32Ptr(0x587000, 260404) = 1209810944;
			nox_xxx_unitsGetInCircle_517F90((float2*)(*(uint32_t*)(a1 + 16) + 56), 400.0, sub_531920,
											*(uint32_t*)(a1 + 16));
		}
		*(uint32_t*)(a1 + 48) = dword_5d4594_2487932;
		*(uint32_t*)(a1 + 76) = 0;
	}
	v4 = *(uint32_t*)(a1 + 76);
	if (v4) {
		v5 = v4 - 1;
		*(uint32_t*)(a1 + 76) = v5;
		if (!v5) {
			*(uint32_t*)(a1 + 48) = 0;
		}
	}
	v6 = *(uint32_t*)(a1 + 48);
	v7 = *(uint32_t*)(a1 + 36);
	if (v6) {
		if (v6 != v7) {
			if (v7) {
				nox_xxx_netStopRaySpell_4FEF90(a1, *(uint32_t**)(a1 + 36));
			}
			nox_xxx_netStartDurationRaySpell_4FF130(a1);
		}
		v8 = *(unsigned short*)(*(uint32_t*)(a1 + 48) + 4);
		if ((unsigned short)v8 == *getMemU32Ptr(0x5D4594, 2487936) || v8 == *getMemU32Ptr(0x5D4594, 2487940)) {
			v9 = nox_xxx_gamedataGetFloat_419D40("PlasmaDamageHecubah");
		} else {
			v9 = nox_xxx_gamedataGetFloat_419D40("PlasmaDamage");
		}
		v20 = v9;
		v10 = nox_float2int(v20);
		(*(void (**)(uint32_t, uint32_t, uint32_t, int, int))(*(uint32_t*)(a1 + 48) + 716))(
			*(uint32_t*)(a1 + 48), *(uint32_t*)(a1 + 16), 0, v10, 14);
		v11 = *(uint32_t*)(a1 + 48);
		if (*(uint32_t*)(v11 + 16) & 0x8020) {
			nox_xxx_netSendPointFx_522FF0(131, (float2*)(v11 + 56));
		}
		v19 = *(uint32_t**)(a1 + 16);
		*(uint32_t*)(a1 + 36) = *(uint32_t*)(a1 + 48);
		nox_xxx_playerSetState_4FA020(v19, 22);
		if (!(nox_frame_xxx_2598000 % (nox_gameFPS / 3u))) {
			nox_xxx_aud_501960(98, *(uint32_t*)(a1 + 16), 0, 0);
			nox_xxx_aud_501960(98, *(uint32_t*)(a1 + 48), 0, 0);
		}
		if (!*(uint32_t*)(a1 + 76)) {
			v21 = nox_xxx_gamedataGetFloat_419D40("PlasmaSearchTime");
			*(uint32_t*)(a1 + 68) = nox_frame_xxx_2598000 + nox_float2int(v21);
		}
		v12 = *(uint32_t*)(a1 + 72);
		if (v12) {
			v13 = *(uint32_t*)(v12 + 736);
			v14 = *(uint8_t*)(v13 + 108);
			if (v14 <= 0u) {
				return 1;
			}
			v15 = v14 - 1;
			*(uint8_t*)(v13 + 108) = v15;
			*(uint32_t*)(v13 + 112) = 100 * v15 / *(unsigned char*)(v13 + 109);
			v16 = *(uint32_t*)(a1 + 16);
			if (v16) {
				if (*(uint8_t*)(v16 + 8) & 4) {
					v17 = *(uint32_t*)(v16 + 748);
					nox_xxx_playerSetState_4FA020((uint32_t*)v16, 22);
					nox_xxx_netReportCharges_4D82B0(*(unsigned char*)(*(uint32_t*)(v17 + 276) + 2064),
													*(uint32_t**)(a1 + 72), *(uint8_t*)(v13 + 108),
													*(uint8_t*)(v13 + 109));
				}
			}
			if (*(uint8_t*)(v13 + 108) <= 0u) {
				return 1;
			}
		}
	} else if (v7) {
		nox_xxx_netStopRaySpell_4FEF90(a1, *(uint32_t**)(a1 + 36));
		*(uint32_t*)(a1 + 36) = 0;
	}
	return 0;
}

//----- (00531920) --------------------------------------------------------
void sub_531920(int a1, int a2) {
	int v2;    // eax
	int v3;    // eax
	double v4; // st7
	double v5; // st6
	double v6; // st5

	v2 = *(uint32_t*)(a1 + 8);
	if (v2 & 0x20006) {
		if (!(*(uint32_t*)(a1 + 16) & 0x8020) && a1 != a2) {
			if (!(v2 & 2) || (v3 = *(uint32_t*)(a1 + 12), (v3 & 0x8000) == 0)) {
				if (nox_xxx_unitIsEnemyTo_5330C0(a2, a1) &&
					nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a2 + 56), *(short*)(a2 + 124),
																(float2*)(a1 + 56)) &
							1 |
						0xC &&
					nox_xxx_unitCanInteractWith_5370E0(a2, a1, 0)) {
					v4 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
					v5 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
					v6 = v5 * v5 + v4 * v4;
					if (v6 < *getMemFloatPtr(0x587000, 260404)) {
						*getMemFloatPtr(0x587000, 260404) = v6;
						dword_5d4594_2487932 = a1;
					}
				}
			}
		}
	}
}

//----- (005319E0) --------------------------------------------------------
int sub_5319E0(int a1) {
	int result; // eax

	result = *(uint32_t*)(a1 + 72);
	if (result) {
		result = *(uint32_t*)(result + 736);
		*(uint32_t*)(result + 96) &= 0xFFFFFFFB;
	}
	return result;
}

//----- (00531A00) --------------------------------------------------------
int nox_xxx_spellCreateMoonglow_531A00(uint32_t* a1) {
	short v1;     // di
	int v2;       // eax
	uint32_t* v3; // eax
	int v4;       // ecx
	int v5;       // edx
	float v7;     // [esp+0h] [ebp-14h]
	float v8;     // [esp+Ch] [ebp-8h]
	float v9;     // [esp+10h] [ebp-4h]

	v7 = nox_xxx_gamedataGetFloat_419D40("MoonglowEnchantmentDuration");
	v1 = nox_float2int(v7);
	v2 = a1[12];
	if (!v2 || *(uint32_t*)(v2 + 16) & 0x8020) {
		return 1;
	}
	if ((*(uint8_t*)(v2 + 8) & 4) != 4) {
		nox_xxx_buffApplyTo_4FF380(v2, 15, v1, a1[2]);
		return 1;
	}
	v3 = nox_xxx_newObjectByTypeID_4E3810("Moonglow");
	a1[18] = v3;
	if (!v3) {
		return 1;
	}
	v4 = a1[12];
	v5 = *(uint32_t*)(*(uint32_t*)(v4 + 748) + 276);
	if (*(uint8_t*)(v5 + 3680) & 0x10) {
		v8 = (double)*(int*)(v5 + 2284);
		v9 = (double)*(int*)(v5 + 2288);
	} else {
		v8 = 2944.0;
		v9 = 2944.0;
	}
	nox_xxx_createAt_4DAA50((int)v3, v4, v8, v9);
	nox_xxx_buffApplyTo_4FF380(a1[12], 1, v1, a1[2]);
	return 0;
}

//----- (00531AF0) --------------------------------------------------------
int sub_531AF0(int a1) {
	int result; // eax

	result = *(uint32_t*)(a1 + 48);
	if (result) {
		if ((*(uint8_t*)(result + 8) & 4) == 4) {
			if (*(uint32_t*)(a1 + 72)) {
				nox_xxx_delayedDeleteObject_4E5CC0(*(uint32_t*)(a1 + 72));
			}
			*(uint32_t*)(a1 + 72) = 0;
			result = nox_xxx_spellBuffOff_4FF5B0(*(uint32_t*)(a1 + 48), 1);
		} else {
			result = nox_xxx_spellBuffOff_4FF5B0(result, 15);
		}
	}
	return result;
}

//----- (00531B40) --------------------------------------------------------
int* nox_xxx_TODOsomeCallingMeleeAttack_531B40(int a1, int a2) {
	int v2;         // ebx
	int* result;    // eax
	int v4;         // eax
	long double v5; // st7
	int v6;         // [esp-8h] [ebp-14h]
	int v7;         // [esp-4h] [ebp-10h]

	v2 = *(uint32_t*)(a1 + 748);
	if (nox_xxx_testUnitBuffs_4FF350(a1, 29) || (result = (int*)nox_xxx_mobCastRelated2_540D90(a1, a2)) == 0) {
		if (nox_xxx_monsterCanShoot_534280(a1)) {
			v4 = nox_xxx_monsterCanMelee_534220(a1);
			v7 = a2;
			v6 = a1;
			if (v4 && (v5 = nox_xxx_calcDistance_4E6C00(a1, a2), v7 = a2, v6 = a1,
					   v5 < *(float*)(*(uint32_t*)(v2 + 484) + 212) * 0.5)) {
				result = nox_xxx_monsterAction_531C60(a1, a2);
			} else {
				result = sub_531D50(v6, v7);
			}
		} else if (nox_xxx_monsterCanMelee_534220(a1)) {
			result = nox_xxx_monsterAction_531C60(a1, a2);
		} else {
			result = (int*)nox_xxx_monsterCanCast_534300(a1);
			if (!result) {
				result = sub_531C10(a1, a2);
			}
		}
	}
	return result;
}

//----- (00531C10) --------------------------------------------------------
int* sub_531C10(int a1, int a2) {
	int* v2;     // eax
	int* v3;     // eax
	int* result; // eax

	v2 = nox_xxx_monsterPushAction_50A260(a1, 60);
	if (v2) {
		v2[1] = a2;
	}
	v3 = nox_xxx_monsterPushAction_50A260(a1, 42);
	if (v3) {
		v3[1] = a2;
	}
	result = nox_xxx_monsterPushAction_50A260(a1, 7);
	if (result) {
		result[1] = *(uint32_t*)(a2 + 56);
		result[2] = *(uint32_t*)(a2 + 60);
		result[3] = a2;
	}
	return result;
}

//----- (00531C60) --------------------------------------------------------
int* nox_xxx_monsterAction_531C60(int a1, int a2) {
	int v2;      // ebx
	int* v3;     // eax
	int* v4;     // eax
	int* v5;     // eax
	double v6;   // st7
	int* v7;     // eax
	int* v8;     // eax
	int* v9;     // eax
	int v10;     // ecx
	int* result; // eax

	v2 = *(uint32_t*)(a1 + 748);
	v3 = nox_xxx_monsterPushAction_50A260(a1, 60);
	if (v3) {
		v3[1] = a2;
	}
	v4 = nox_xxx_monsterPushAction_50A260(a1, 42);
	if (v4) {
		v4[1] = a2;
	}
	if (nox_xxx_monsterCanShoot_534280(a1)) {
		v5 = nox_xxx_monsterPushAction_50A260(a1, 50);
		if (v5) {
			v6 = *(float*)(*(uint32_t*)(v2 + 484) + 212) * 0.60000002;
			v5[3] = a2;
			*((float*)v5 + 1) = v6;
		}
	}
	v7 = nox_xxx_monsterPushAction_50A260(a1, 45);
	if (v7) {
		v7[1] = a2;
	}
	nox_xxx_monsterPushAction_50A260(a1, 16);
	v8 = nox_xxx_monsterPushAction_50A260(a1, 26);
	if (v8) {
		v8[1] = a2;
	}
	v9 = nox_xxx_monsterPushAction_50A260(a1, 49);
	if (v9) {
		v10 = *(uint32_t*)(*(uint32_t*)(v2 + 484) + 112);
		v9[3] = a2;
		v9[1] = v10;
	}
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		nox_xxx_monsterPushAction_50A260(a1, 65);
		nox_xxx_monsterPushAction_50A260(a1, 40);
	}
	result = nox_xxx_monsterPushAction_50A260(a1, 7);
	if (result) {
		result[1] = *(uint32_t*)(a2 + 56);
		result[2] = *(uint32_t*)(a2 + 60);
		result[3] = a2;
	}
	return result;
}

//----- (00531D50) --------------------------------------------------------
int* sub_531D50(int a1, int a2) {
	int v2;      // ebx
	int* v3;     // eax
	int* v4;     // eax
	int* v5;     // eax
	int* v6;     // eax
	int* result; // eax
	int* v8;     // eax
	int* v9;     // eax
	int v10;     // edx

	v2 = *(uint32_t*)(a1 + 748);
	v3 = nox_xxx_monsterPushAction_50A260(a1, 60);
	if (v3) {
		v3[1] = a2;
	}
	v4 = nox_xxx_monsterPushAction_50A260(a1, 45);
	if (v4) {
		v4[1] = a2;
	}
	v5 = nox_xxx_monsterPushAction_50A260(a1, 17);
	if (v5) {
		v5[1] = *(uint32_t*)(a2 + 56);
		v5[2] = *(uint32_t*)(a2 + 60);
		v5[3] = a2;
	}
	v6 = nox_xxx_monsterPushAction_50A260(a1, 26);
	if (v6) {
		v6[1] = a2;
	}
	result = (int*)sub_534710(a1);
	if (!result) {
		v8 = nox_xxx_monsterPushAction_50A260(a1, 47);
		if (v8) {
			v8[1] = a2;
		}
		v9 = nox_xxx_monsterPushAction_50A260(a1, 49);
		if (v9) {
			v10 = *(uint32_t*)(*(uint32_t*)(v2 + 484) + 212);
			v9[3] = a2;
			v9[1] = v10;
		}
		nox_xxx_monsterPushAction_50A260(a1, 40);
		result = nox_xxx_monsterPushAction_50A260(a1, 7);
		if (result) {
			result[1] = *(uint32_t*)(a2 + 56);
			result[2] = *(uint32_t*)(a2 + 60);
			result[3] = a2;
		}
	}
	return result;
}

//----- (00531E20) --------------------------------------------------------
int nox_xxx_mobActionFightStart_531E20(float a1) {
	int* v1; // edi
	int v2;  // eax
	int v3;  // eax

	v1 = *(int**)(LODWORD(a1) + 748);
	v2 = nox_xxx_monsterGetSoundSet_424300(SLODWORD(a1));
	if (v2) {
		nox_xxx_aud_501960(*(uint32_t*)(v2 + 20), SLODWORD(a1), 0, 0);
	}
	nox_xxx_scriptCallByEventBlock_502490(v1 + 310, v1[299], SLODWORD(a1), 13);
	v3 = v1[360];
	BYTE1(v3) |= 1u;
	v1[360] = v3;
	nox_xxx_frameCounterSetCopy_5281E0();
	nox_xxx_unitUpdateSightMB_5281F0(a1);
	return sub_534750(SLODWORD(a1));
}

//----- (00531E90) --------------------------------------------------------
int sub_531E90(int a1) {
	int v1; // eax
	int v2; // edx

	v1 = *(uint32_t*)(a1 + 748);
	v2 = *(uint32_t*)(v1 + 1440);
	BYTE1(v2) &= 0xFEu;
	*(uint32_t*)(v1 + 1440) = v2;
	return sub_534780(a1);
}

//----- (00531EC0) --------------------------------------------------------
char nox_xxx_mobActionFight_531EC0(int a1) {
	int v1;    // esi
	int v2;    // ebx
	int* v3;   // eax
	float* v4; // ebp
	double v5; // st7
	double v6; // st6

	v1 = *(uint32_t*)(a1 + 748);
	v2 = v1 + 24 * (*(char*)(v1 + 544) + 23);
	if (nox_frame_xxx_2598000 - *(uint32_t*)(v1 + 24 * (*(char*)(v1 + 544) + 23) + 12) >
		(unsigned int)(10 * nox_gameFPS)) {
		goto LABEL_15;
	}
	if (*(uint32_t*)(v1 + 1196)) {
		*(uint32_t*)(v2 + 12) = nox_frame_xxx_2598000;
		if (nox_xxx_checkIsKillable_528190(*(uint32_t*)(v1 + 1196))) {
			if (nox_xxx_testUnitBuffs_4FF350(a1, 29) ||
				(v3 = (int*)nox_xxx_monsterBuffSelf_540B90(a1)) == 0 &&
					(v3 = (int*)nox_xxx_monsterCastOffensive_540F20(a1, *(uint32_t*)(v1 + 1196))) == 0) {
				LOBYTE(v3) = (unsigned int)nox_xxx_TODOsomeCallingMeleeAttack_531B40(a1, *(uint32_t*)(v1 + 1196));
			}
			return (char)v3;
		}
	LABEL_15:
		LOBYTE(v3) = nox_xxx_monsterPopAction_50A160(a1);
		return (char)v3;
	}
	if (sub_534710(a1)) {
		goto LABEL_15;
	}
	v4 = (float*)(v2 + 4);
	*getMemU32Ptr(0x5D4594, 2487944) = 0;
	nox_xxx_unitsGetInCircle_517F90((float2*)(v2 + 4), 30.0, sub_532040, v1);
	if (*getMemU32Ptr(0x5D4594, 2487944)) {
		nox_xxx_monsterPopAction_50A160(a1);
		v3 = *(int**)(v1 + 1200);
		if (*(int**)(v1 + 392) == v3) {
			*(uint32_t*)(v1 + 388) = 0;
		}
	} else {
		v5 = *v4 - *(float*)(a1 + 56);
		v6 = *(float*)(v2 + 8) - *(float*)(a1 + 60);
		if (v6 * v6 + v5 * v5 < 64.0) {
			goto LABEL_15;
		}
		nox_xxx_monsterPushAction_50A260(a1, 56);
		v3 = nox_xxx_monsterPushAction_50A260(a1, 7);
		if (v3) {
			v3[1] = *(uint32_t*)v4;
			v3[2] = *(uint32_t*)(v2 + 8);
			v3[3] = 0;
		}
	}
	return (char)v3;
}

//----- (00532040) --------------------------------------------------------
int sub_532040(int a1, int a2) {
	int result; // eax
	int v3;     // ecx

	result = a1;
	if (*(uint32_t*)(a1 + 36) == *(uint32_t*)(a2 + 1200)) {
		v3 = *(uint32_t*)(a1 + 16);
		if ((v3 & 0x8000) != 0) {
			*getMemU32Ptr(0x5D4594, 2487944) = 1;
		}
	}
	return result;
}

//----- (00532070) --------------------------------------------------------
char nox_xxx_monsterShieldBlockStart_532070(int a1) {
	int v1;          // edi
	unsigned int v2; // eax

	v1 = *(uint32_t*)(a1 + 748) + 24 * (*(char*)(*(uint32_t*)(a1 + 748) + 544) + 23);
	if (nox_xxx_monsterTestBlockShield_533E70(a1)) {
		*(uint32_t*)(v1 + 4) = nox_frame_xxx_2598000 + (nox_gameFPS >> 1);
	}
	v2 = *(uint32_t*)(v1 + 4);
	if (nox_frame_xxx_2598000 > v2) {
		nox_xxx_monsterPopAction_50A160(a1);
		LOBYTE(v2) = *(uint8_t*)(a1 + 12);
		if (!(v2 & 0x10)) {
			LOBYTE(v2) = (unsigned int)nox_xxx_monsterPushAction_50A260(a1, 22);
		}
	}
	return v2;
}

//----- (005320E0) --------------------------------------------------------
char nox_xxx_monsterShieldBlockStop_5320E0(int a1) {
	char result; // al

	result = a1;
	if (*(uint8_t*)(*(uint32_t*)(a1 + 748) + 483)) {
		result = nox_xxx_monsterPopAction_50A160(a1);
	}
	return result;
}

//----- (00532100) --------------------------------------------------------
char sub_532100(int a1) { return nox_xxx_monsterPopAction_50A160(a1); }

//----- (00532110) --------------------------------------------------------
char sub_532110(int a1) {
	char result; // al

	result = a1;
	if (*(uint8_t*)(*(uint32_t*)(a1 + 748) + 483)) {
		result = nox_xxx_monsterPopAction_50A160(a1);
	}
	return result;
}

//----- (00532130) --------------------------------------------------------
int* nox_xxx_mobActionMelee1_532130(int a1) {
	int v1;      // edi
	int* v2;     // eax
	int* result; // eax
	int v4;      // eax
	double v5;   // st7
	int v6;      // eax
	int v7;      // ecx
	int v8;      // eax
	int* v9;     // eax
	int* v10;    // edi
	int v11;     // ecx
	int v12;     // ecx
	int v13;     // [esp-4h] [ebp-1Ch]
	float4 v14;  // [esp+8h] [ebp-10h]

	v1 = *(uint32_t*)(a1 + 748);
	if (nox_frame_xxx_2598000 >= *(int*)(v1 + 512)) {
		if (*(uint8_t*)(a1 + 12) & 0x10) {
			v4 = nox_xxx_weaponGetStaminaByType_4F7E80(*(uint32_t*)(v1 + 2056));
			if (v4 > *(unsigned char*)(v1 + 1128)) {
				*(uint8_t*)(v1 + 1128) -= v4;
			} else {
				*(uint8_t*)(v1 + 1128) = 0;
			}
		}
		v14.field_0 = *(float*)(a1 + 56) - *(float*)&dword_587000_261388;
		v14.field_4 = *(float*)(a1 + 60) - *(float*)&dword_587000_261388;
		v14.field_8 = *(float*)&dword_587000_261388 + *(float*)(a1 + 56);
		v5 = *(float*)&dword_587000_261388 + *(float*)(a1 + 60);
		dword_5d4594_2487948 = 0;
		v14.field_C = v5;
		*getMemFloatPtr(0x5D4594, 2487952) = *(float*)&dword_587000_261388 + 1.0;
		nox_xxx_getUnitsInRect_517C10(&v14, sub_532390, a1);
		if (dword_5d4594_2487948 && !nox_xxx_unitIsEnemyTo_5330C0(a1, *(int*)&dword_5d4594_2487948) &&
			*(uint8_t*)(a1 + 12) & 0x10 && (v6 = *(uint32_t*)(v1 + 2064)) != 0 &&
			(v7 = *(uint32_t*)(v6 + 12), BYTE1(v7) & 0x40)) {
			v13 = *(uint32_t*)(a1 + 36);
			v8 = nox_xxx_getUnitName_4E39D0(a1);
			nox_ai_debug_printf_5341A0("%d: %s(#%d) Tried to MELEE_ATTACK but friend in the way\n",
									   nox_frame_xxx_2598000, v8, v13);
			nox_xxx_monsterPopAction_50A160(a1);
			v9 = nox_xxx_monsterPushAction_50A260(a1, 27);
			if (v9) {
				v9[1] = *(short*)(a1 + 124);
			}
			v10 = nox_xxx_monsterPushAction_50A260(a1, 41);
			if (v10) {
				v10[1] = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(nox_gameFPS >> 2, nox_gameFPS >> 1);
			}
			result = nox_xxx_monsterPushAction_50A260(a1, 24);
			if (result) {
				v11 = dword_5d4594_2487948 + 56;
				result[1] = *(uint32_t*)(dword_5d4594_2487948 + 56);
				v12 = *(uint32_t*)(v11 + 4);
				result[3] = 0;
				result[2] = v12;
			}
		} else {
			sub_5341D0(a1);
			*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000;
			*(uint32_t*)(v1 + 512) =
				nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(*(uint32_t*)(*(uint32_t*)(v1 + 484) + 128),
																	*(uint32_t*)(*(uint32_t*)(v1 + 484) + 132));
			result = (int*)nox_xxx_monsterGetSoundSet_424300(a1);
			if (result) {
				result = nox_xxx_aud_501960(result[6], a1, 0, 0);
			}
		}
	} else {
		v2 = nox_xxx_monsterPushAction_50A260(a1, 50);
		if (v2) {
			*((float*)v2 + 1) = *(float*)(*(uint32_t*)(v1 + 484) + 112) * 1.2;
			v2[3] = *(uint32_t*)(v1 + 1196);
		}
		result = nox_xxx_monsterPushAction_50A260(a1, 1);
		if (result) {
			result[1] = *(uint32_t*)(v1 + 512);
		}
	}
	return result;
}

//----- (00532390) --------------------------------------------------------
void sub_532390(int a1, int a2) {
	int v2;    // ecx
	int v3;    // eax
	double v4; // st7
	double v5; // st6
	float* v6; // edx
	double v7; // st7
	float v8;  // [esp+4h] [ebp-4h]
	float v9;  // [esp+Ch] [ebp+4h]

	v2 = a1;
	if (*(uint8_t*)(a1 + 8) & 6) {
		v3 = *(uint32_t*)(a1 + 16);
		if ((v3 & 0x8000) == 0) {
			v4 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
			v5 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
			v8 = v5;
			v9 = sqrt(v5 * v8 + v4 * v4) + 0.000099999997;
			v7 = v4 / v9;
			if (v9 < (double)*getMemFloatPtr(0x5D4594, 2487952)) {
				v6 = getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a2 + 124));
				if (v8 / v9 * v6[1] + v7 * *v6 > 0.5) {
					dword_5d4594_2487948 = v2;
					*getMemFloatPtr(0x5D4594, 2487952) = v9;
				}
			}
		}
	}
}

//----- (00532440) --------------------------------------------------------
char nox_xxx_mobActionMeleeAtt_532440(int a1) {
	int v1;         // edi
	int v2;         // ebx
	int v3;         // eax
	int v4;         // ecx
	int (*v5)(int); // eax
	int v6;         // eax
	int v7;         // ebx
	int v8;         // eax
	int v10;        // [esp-4h] [ebp-10h]

	v1 = *(uint32_t*)(a1 + 748);
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		if (*(uint32_t*)(v1 + 1440) & 0x20000) {
			nox_xxx_mobMorphToPlayer_4FAAF0((uint32_t*)a1);
		}
		v2 = nox_xxx_playerAttack_538960(a1);
		v3 = *(uint32_t*)(v1 + 1440);
		if (v3 & 0x20000) {
			LOBYTE(v3) = nox_xxx_mobMorphFromPlayer_4FAAC0((uint32_t*)a1);
		}
		if (!v2) {
			LOBYTE(v3) = nox_xxx_monsterPopAction_50A160(a1);
		}
	} else {
		v4 = *(uint32_t*)(v1 + 484);
		v5 = *(int (**)(int))(v4 + 236);
		if (v5) {
			if (*(unsigned char*)(v1 + 481) == *(uint32_t*)(v4 + 108) && !*(uint8_t*)(v1 + 482)) {
				v7 = v5(a1);
				v8 = nox_xxx_monsterGetSoundSet_424300(a1);
				if (v8) {
					if (v7) {
						nox_xxx_aud_501960(*(uint32_t*)(v8 + 32), a1, 0, 0);
					} else {
						nox_xxx_aud_501960(*(uint32_t*)(v8 + 36), a1, 0, 0);
					}
				}
			}
			LOBYTE(v3) = *(uint8_t*)(v1 + 483);
			if ((uint8_t)v3) {
				LOBYTE(v3) = nox_xxx_monsterPopAction_50A160(a1);
			}
		} else {
			v10 = *(uint32_t*)(a1 + 36);
			v6 = nox_xxx_getUnitName_4E39D0(a1);
			nox_ai_debug_printf_5341A0("%d: %s(#%d) Tried to MELEE_ATTACK but cannot\n", nox_frame_xxx_2598000, v6,
									   v10);
			LOBYTE(v3) = nox_xxx_monsterPopAction_50A160(a1);
		}
	}
	return v3;
}

//----- (00532540) --------------------------------------------------------
uint32_t* sub_532540(int a1) {
	uint32_t* v1;     // edi
	int* v2;          // eax
	uint32_t* result; // eax

	v1 = *(uint32_t**)(a1 + 748);
	if (nox_frame_xxx_2598000 >= v1[128]) {
		sub_5341D0(a1);
		*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000;
		v1[128] = nox_frame_xxx_2598000 +
				  nox_common_randomInt_415FA0(*(uint32_t*)(v1[121] + 220), *(uint32_t*)(v1[121] + 224));
		result = (uint32_t*)nox_xxx_monsterGetSoundSet_424300(a1);
		if (result) {
			result = nox_xxx_aud_501960(result[10], a1, 0, 0);
		}
	} else {
		v2 = nox_xxx_monsterPushAction_50A260(a1, 50);
		if (v2) {
			*((float*)v2 + 1) = *(float*)(v1[121] + 212) * 1.2;
			v2[3] = v1[299];
		}
		result = nox_xxx_monsterPushAction_50A260(a1, 1);
		if (result) {
			result[1] = v1[128];
		}
	}
	return result;
}

//----- (00532610) --------------------------------------------------------
char nox_xxx_mobActionMissileAtt_532610(int a1) {
	int v1;     // esi
	int v2;     // ebx
	int v3;     // eax
	int* v4;    // ebp
	int v5;     // eax
	float* v6;  // edi
	int v7;     // eax
	float v8;   // eax
	double v9;  // st7
	double v10; // st6
	int v11;    // eax
	float v12;  // edx
	short v13;  // ax
	int v14;    // eax
	float v16;  // [esp+8h] [ebp-2Ch]
	float v17;  // [esp+Ch] [ebp-28h]
	float v18;  // [esp+10h] [ebp-24h]
	float v19;  // [esp+10h] [ebp-24h]
	float v20;  // [esp+14h] [ebp-20h]
	float v21;  // [esp+18h] [ebp-1Ch]
	float2 v22; // [esp+1Ch] [ebp-18h]
	float4 v24; // [esp+24h] [ebp-10h]
	float v25;  // [esp+38h] [ebp+4h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 748);
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		v3 = nox_xxx_playerAttack_538960(a1);
		if (!v3) {
			LOBYTE(v3) = nox_xxx_monsterPopAction_50A160(a1);
		}
	} else {
		v4 = (int*)(v2 + 24 * (*(char*)(v2 + 544) + 23));
		v5 = *(uint32_t*)(v2 + 484);
		if (*(unsigned char*)(v2 + 481) == *(uint32_t*)(v5 + 216) && !*(uint8_t*)(v2 + 482)) {
			v6 = (float*)nox_xxx_newObjectByTypeID_4E3810((char*)(v5 + 148));
			if (v6) {
				v7 = v4[3];
				if (v7) {
					nox_xxx_projAddVelocitySmth_533080(a1, v7, v6[136], (int)&v22);
				} else {
					v8 = *(float*)(&v4[2]);
					v22.field_0 = *(float*)(&v4[1]);
					v22.field_4 = v8;
				}
				v9 = v22.field_0 - *(float*)(a1 + 56);
				v10 = v22.field_4 - *(float*)(a1 + 60);
				v18 = v10;
				v11 = 8 * *(short*)(a1 + 124);
				v12 = *(float*)(a1 + 60);
				v24.field_0 = *(float*)(a1 + 56);
				v24.field_4 = v12;
				v25 = sqrt(v10 * v18 + v9 * v9) + 0.1;
				v16 = *(float*)(v1 + 176) + 4.0;
				v20 = v9 * v6[136] / v25;
				v21 = v18 * v6[136] / v25;
				v17 = v16 * *getMemFloatPtr(0x587000, 194136 + v11) + *(float*)(v1 + 56);
				v19 = v16 * *getMemFloatPtr(0x587000, 194140 + v11) + *(float*)(v1 + 60);
				v24.field_8 = v17 + v20;
				v24.field_C = v19 + v21;
				if (nox_xxx_mapTraceRay_535250(&v24, 0, 0, 5)) {
					nox_xxx_createAt_4DAA50((int)v6, v1, v17, v19);
					v6[20] = v20;
					v6[21] = v21;
					v13 = *(uint16_t*)(v1 + 124);
					*((uint16_t*)v6 + 62) = v13;
					*((uint16_t*)v6 + 63) = v13;
				} else {
					nox_xxx_delayedDeleteObject_4E5CC0((int)v6);
				}
			}
			v14 = nox_xxx_monsterGetSoundSet_424300(v1);
			if (v14) {
				nox_xxx_aud_501960(*(uint32_t*)(v14 + 44), v1, 0, 0);
			}
		}
		LOBYTE(v3) = *(uint8_t*)(v2 + 483);
		if ((uint8_t)v3) {
			LOBYTE(v3) = nox_xxx_monsterPopAction_50A160(v1);
		}
	}
	return v3;
}

//----- (00532800) --------------------------------------------------------
char nox_xxx_monsterPlayHurtSound_532800(int a1) {
	int v1; // eax
	int v2; // edi

	LOBYTE(v1) = *(uint8_t*)(a1 + 8);
	v2 = *(uint32_t*)(a1 + 748);
	if (v1 & 2) {
		LOBYTE(v1) = (unsigned char)nox_frame_xxx_2598000;
		if (nox_frame_xxx_2598000 >= *(int*)(v2 + 532)) {
			*(uint32_t*)(v2 + 532) =
				nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(2 * nox_gameFPS, 4 * nox_gameFPS);
			v1 = nox_xxx_monsterGetSoundSet_424300(a1);
			if (v1) {
				LOBYTE(v1) = (unsigned int)nox_xxx_aud_501960(*(uint32_t*)(v1 + 8), a1, 0, 0);
			}
		}
	}
	return v1;
}

//----- (00532880) --------------------------------------------------------
int sub_532880(int a1) {
	int result; // eax

	result = *(uint32_t*)(a1 + 748);
	if (!*(uint32_t*)(result + 520)) {
		*(uint32_t*)(result + 520) = nox_frame_xxx_2598000;
	}
	return result;
}

//----- (005328B0) --------------------------------------------------------
int nox_xxx_soundPlayerDamageSound_5328B0(int a1, int a2) {
	unsigned short v2; // di
	int i;             // esi

	v2 = 1;
	if (!a2) {
		return 1;
	}
	for (i = *(uint32_t*)(a1 + 504); i; i = *(uint32_t*)(i + 496)) {
		if (*(uint32_t*)(i + 8) & 0x2000000 && *(uint8_t*)(i + 12) & 4) {
			if (sub_4133D0(i)) {
				v2 = 0x2000;
			} else if (*(uint16_t*)(i + 24) > v2) {
				v2 = *(uint16_t*)(i + 24);
			}
		}
	}
	sub_532930(a1, v2, *(uint16_t*)(a2 + 24));
	return 1;
}

//----- (00532930) --------------------------------------------------------
int sub_532930(int a1, unsigned short a2, unsigned short a3) {
	int result; // eax

	result = a2;
	if ((int)a2 <= 32) {
		if (a2 == 32) {
			result = a3;
			if ((int)a3 > 16) {
				if (a3 == 32) {
					result = nox_xxx_aud_501960(848, a1, 0, 0);
				} else if (a3 == 0x2000) {
					result = nox_xxx_aud_501960(868, a1, 0, 0);
				}
			} else if (a3 == 16) {
				result = nox_xxx_aud_501960(858, a1, 0, 0);
			} else {
				result = a3 - 1;
				switch (a3) {
				case 1u:
				case 2u:
				case 4u:
					result = nox_xxx_aud_501960(863, a1, 0, 0);
					break;
				case 8u:
					result = nox_xxx_aud_501960(853, a1, 0, 0);
					break;
				default:
					return result;
				}
			}
		} else {
			result = a2 - 1;
			switch (a2) {
			case 1u:
			case 2u:
			case 4u:
				result = a3;
				if ((int)a3 > 16) {
					if (a3 == 32) {
						result = nox_xxx_aud_501960(852, a1, 0, 0);
					} else if (a3 == 0x2000) {
						result = nox_xxx_aud_501960(872, a1, 0, 0);
					}
				} else if (a3 == 16) {
					result = nox_xxx_aud_501960(862, a1, 0, 0);
				} else {
					result = a3 - 1;
					switch (a3) {
					case 1u:
					case 2u:
					case 4u:
						result = nox_xxx_aud_501960(867, a1, 0, 0);
						break;
					case 8u:
						result = nox_xxx_aud_501960(857, a1, 0, 0);
						break;
					default:
						return result;
					}
				}
				break;
			case 8u:
				result = a3;
				if ((int)a3 > 16) {
					if (a3 == 32) {
						result = nox_xxx_aud_501960(850, a1, 0, 0);
					} else if (a3 == 0x2000) {
						result = nox_xxx_aud_501960(870, a1, 0, 0);
					}
				} else if (a3 == 16) {
					result = nox_xxx_aud_501960(860, a1, 0, 0);
				} else {
					result = a3 - 1;
					switch (a3) {
					case 1u:
					case 2u:
					case 4u:
						result = nox_xxx_aud_501960(865, a1, 0, 0);
						break;
					case 8u:
						result = nox_xxx_aud_501960(855, a1, 0, 0);
						break;
					default:
						return result;
					}
				}
				break;
			case 0x10u:
				result = a3;
				if ((int)a3 > 16) {
					if (a3 == 32) {
						result = nox_xxx_aud_501960(851, a1, 0, 0);
					} else if (a3 == 0x2000) {
						result = nox_xxx_aud_501960(871, a1, 0, 0);
					}
				} else if (a3 == 16) {
					result = nox_xxx_aud_501960(861, a1, 0, 0);
				} else {
					result = a3 - 1;
					switch (a3) {
					case 1u:
					case 2u:
					case 4u:
						result = nox_xxx_aud_501960(866, a1, 0, 0);
						break;
					case 8u:
						result = nox_xxx_aud_501960(856, a1, 0, 0);
						break;
					default:
						return result;
					}
				}
				break;
			default:
				return result;
			}
		}
		return result;
	}
	if (a2 != 64 && a2 != 1024) {
		if (a2 != 0x2000) {
			return result;
		}
		result = a3;
		if ((int)a3 > 16) {
			if (a3 == 32) {
				return nox_xxx_aud_501960(868, a1, 0, 0);
			}
			if (a3 != 0x2000) {
				return result;
			}
		} else if (a3 != 16) {
			result = a3 - 1;
			switch (a3) {
			case 1u:
			case 2u:
			case 4u:
				result = nox_xxx_aud_501960(872, a1, 0, 0);
				break;
			case 8u:
				result = nox_xxx_aud_501960(870, a1, 0, 0);
				break;
			default:
				return result;
			}
			return result;
		}
		return nox_xxx_aud_501960(871, a1, 0, 0);
	}
	result = a3;
	if ((int)a3 > 16) {
		if (a3 == 32) {
			result = nox_xxx_aud_501960(849, a1, 0, 0);
		} else if (a3 == 0x2000) {
			result = nox_xxx_aud_501960(869, a1, 0, 0);
		}
	} else if (a3 == 16) {
		result = nox_xxx_aud_501960(859, a1, 0, 0);
	} else {
		result = a3 - 1;
		switch (a3) {
		case 1u:
		case 2u:
		case 4u:
			result = nox_xxx_aud_501960(864, a1, 0, 0);
			break;
		case 8u:
			result = nox_xxx_aud_501960(854, a1, 0, 0);
			break;
		default:
			return result;
		}
	}
	return result;
}

//----- (00532E20) --------------------------------------------------------
int nox_xxx_soundDefaultDamageSound_532E20(int a1, int a2) {
	int v3; // eax

	if (a1 && *(uint32_t*)(a1 + 8) & 0x1001000 && *(uint32_t*)(a1 + 492)) {
		return 1;
	}
	if (a2 && *(uint16_t*)(a2 + 24) != 0x4000 && sub_532F70(*(uint32_t*)(a1 + 524))) {
		v3 = *(uint32_t*)(a1 + 556);
		if (v3 && *(uint16_t*)(v3 + 4) && sub_532FB0(*(uint16_t*)(a1 + 24))) {
			sub_532EC0(a1, *(uint16_t*)(a1 + 24));
			return 1;
		}
		sub_532930(a1, *(uint16_t*)(a1 + 24), *(uint16_t*)(a2 + 24));
	}
	return 1;
}

//----- (00532EC0) --------------------------------------------------------
uint32_t* sub_532EC0(int a1, unsigned short a2) {
	uint32_t* result; // eax

	result = (uint32_t*)a2;
	if ((int)a2 <= 64) {
		if (a2 != 64) {
			switch (a2) {
			case 8u:
				return nox_xxx_aud_501960(875, a1, 0, 0);
			case 0x10u:
				return nox_xxx_aud_501960(876, a1, 0, 0);
			case 0x20u:
				result = nox_xxx_aud_501960(873, a1, 0, 0);
				break;
			}
			return result;
		}
		return nox_xxx_aud_501960(874, a1, 0, 0);
	}
	if (a2 == 1024) {
		return nox_xxx_aud_501960(874, a1, 0, 0);
	}
	if (a2 == 4096) {
		result = nox_xxx_aud_501960(877, a1, 0, 0);
	}
	return result;
}

//----- (00532F70) --------------------------------------------------------
int sub_532F70(int a1) {
	int result; // eax

	switch (a1) {
	case 0:
	case 2:
	case 3:
	case 10:
	case 11:
		result = 1;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (00532FB0) --------------------------------------------------------
int sub_532FB0(short a1) { return a1 == 8 || a1 == 32 || a1 == 64; }

//----- (00532FE0) --------------------------------------------------------
int sub_532FE0(unsigned short a1, int a2) {
	if (a2) {
		sub_532930(a2, a1, *(uint16_t*)(a2 + 24));
	}
	return 1;
}

//----- (00533010) --------------------------------------------------------
int sub_533010(unsigned short a1, int a2) {
	if (a2) {
		sub_532EC0(a2, a1);
	}
	return 1;
}

//----- (00533030) --------------------------------------------------------
unsigned char* nox_xxx_unused_533030(int a1, int a2) {
	int v2; // edi
	int v3; // eax

	v2 = *(uint32_t*)(a1 + 748);
	v3 = nox_xxx_monsterGetSoundSet_424300(a1);
	if (v3) {
		nox_xxx_aud_501960(*(uint32_t*)(v3 + 68), a1, 0, 0);
	}
	return nox_xxx_scriptCallByEventBlock_502490((int*)(v2 + 1232), a2, a1, 12);
}

//----- (00533080) --------------------------------------------------------
int nox_xxx_projAddVelocitySmth_533080(int a1, int a2, float a3, int a4) {
	int result;     // eax
	double v5;      // st7
	double v6;      // st6
	long double v7; // st7

	result = a2;
	v5 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
	v6 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
	v7 = sqrt(v6 * v6 + v5 * v5) / a3;
	*(float*)a4 = v7 * *(float*)(a2 + 80) + *(float*)(a2 + 56);
	*(float*)(a4 + 4) = v7 * *(float*)(a2 + 84) + *(float*)(a2 + 60);
	return result;
}

//----- (005330C0) --------------------------------------------------------
int nox_xxx_unitIsEnemyTo_5330C0(nox_object_t* a1p, nox_object_t* a2p) {
	int a1 = a1p;
	int a2 = a2p;
	int v2; // edx
	int v3; // eax
	int v5; // ecx
	int v6; // edi
	int v7; // esi
	int v8; // eax

	if (!*getMemU32Ptr(0x5D4594, 2488512)) {
		*getMemU32Ptr(0x5D4594, 2488512) = nox_xxx_getNameId_4E3AA0("CarnivorousPlant");
		*getMemU32Ptr(0x5D4594, 2488516) = nox_xxx_getNameId_4E3AA0("Polyp");
		*getMemU32Ptr(0x5D4594, 2488520) = nox_xxx_getNameId_4E3AA0("WillOWisp");
	}
	if (a1) {
		if (a2) {
			if (a1 != a2) {
				v2 = *(uint32_t*)(a2 + 8);
				if (!(*(uint32_t*)(a2 + 8) & 2) || !(*(uint32_t*)(*(uint32_t*)(a2 + 748) + 1440) & 0x40000)) {
					v3 = *(uint32_t*)(a1 + 8) & 4;
					if (v3 && *(unsigned short*)(a2 + 4) == *getMemU32Ptr(0x5D4594, 2488516)) {
						return 1;
					}
					if (v3 && v2 & 0x20000) {
						return 1;
					}
					v5 = *(uint32_t*)(a1 + 8) & 2;
					if ((!v5 || !(v2 & 0x20000)) &&
						(!v3 || !(*(uint32_t*)(a2 + 8) & 2) || !(*(uint8_t*)(a2 + 12) & 0x20)) &&
						(!v5 || !(*(uint8_t*)(a1 + 12) & 0x20) || !(v2 & 4))) {
						if (nox_xxx_unitIsAFish_534B10(a1) || nox_xxx_unitIsAFrog_534B90(a1)) {
							if (!nox_xxx_unitIsAFish_534B10(a2) && !nox_xxx_unitIsAFrog_534B90(a2)) {
								return 1;
							}
						} else {
							if (nox_xxx_unitIsARat_534B60(a1)) {
								return !nox_xxx_unitIsARat_534B60(a2);
							}
							if (!nox_xxx_unitIsAFish_534B10(a2) &&
								(!(*(uint8_t*)(a2 + 8) & 2) || !(*(uint8_t*)(a2 + 12) & 8)) &&
								(!(*(uint8_t*)(a1 + 8) & 2) || !(*(uint8_t*)(a1 + 12) & 8)) &&
								!nox_xxx_testUnitBuffs_4FF350(a1, 28) && !nox_xxx_testUnitBuffs_4FF350(a2, 28) &&
								(!(*(uint8_t*)(a2 + 8) & 4) ||
								 !(*(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a2 + 748) + 276) + 3680) & 1))) {
								v6 = nox_xxx_findParentChainPlayer_4EC580(a1);
								v7 = nox_xxx_findParentChainPlayer_4EC580(a2);
								if (v6 != v7 && !nox_xxx_servCompareTeams_419150(v6 + 48, v7 + 48)) {
									v8 = *(uint32_t*)(v6 + 8);
									if (v8 & 4 && *(uint32_t*)(v7 + 8) & 0x20000) {
										return 1;
									}
									if (!(v8 & 2) || !(*(uint32_t*)(v7 + 8) & 0x20000)) {
										if (!nox_common_gameFlags_check_40A5C0(4096) && *(uint8_t*)(a1 + 8) & 2 &&
											*(unsigned short*)(a2 + 4) == *getMemU32Ptr(0x5D4594, 2488520)) {
											return nox_xxx_checkMobAction_50A0D0(a2, 15) != 0;
										}
										if (nox_xxx_servObjectHasTeam_419130(v6 + 48) ||
											nox_xxx_servObjectHasTeam_419130(v7 + 48) || !(*(uint8_t*)(v6 + 8) & 2) ||
											!(*(uint8_t*)(v7 + 8) & 2)) {
											return 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

//----- (00533360) --------------------------------------------------------
int sub_533360(nox_object_t* a1p, nox_object_t* a2p) {
	int a1 = a1p;
	int a2 = a2p;
	double v2;  // st7
	double v3;  // st6
	float* v4;  // eax
	int result; // eax
	float v6;   // [esp+Ch] [ebp-4h]
	float v7;   // [esp+18h] [ebp+8h]

	result = 0;
	if (nox_xxx_unitCanInteractWith_5370E0(a1, a2, 0)) {
		v2 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
		v3 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
		v6 = v3;
		v4 = getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a1 + 124));
		v7 = sqrt(v3 * v6 + v2 * v2) + 0.001;
		if (v6 / v7 * v4[1] + v2 / v7 * *v4 > 0.5) {
			result = 1;
		}
	}
	return result;
}

//----- (005333F0) --------------------------------------------------------
int nox_xxx_unused_5333F0(int a1) {
	int v2; // [esp+0h] [ebp-4h]

	v2 = 1142947840;
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		v2 = 1132068864;
	}
	dword_5d4594_2487984 = 0;
	dword_5d4594_2487980 = 1259902592;
	dword_5d4594_2487992 = 1;
	nox_xxx_unitsGetInCircle_517F90((float2*)(a1 + 56), *(float*)&v2, nox_xxx_fnPickEnemyAggro_533460, a1);
	return dword_5d4594_2487984;
}

//----- (00533460) --------------------------------------------------------
void nox_xxx_fnPickEnemyAggro_533460(nox_object_t* it, nox_object_t* self) {
	if (self == it) {
		return;
	}
	if ((it->obj_class & 0x20006) == 0) {
		return;
	}
	if (!nox_xxx_unitIsEnemyTo_5330C0(self, it)) {
		return;
	}
	if ((it->flags & 0x8000) != 0) {
		return;
	}
	if (!nox_xxx_unitCanInteractWith_5370E0(self, it, 0)) {
		return;
	}
	float dx = it->x - self->x;
	float dy = it->y - self->y;
	float dist = (float)sqrt(dy * dy + dx * dx) + 0.001;
	float* v5 = getMemFloatPtr(0x587000, 194136 + 8 * self->field_31_0);
	if (!dword_5d4594_2487992 || (dy / dist * v5[1] + dx / dist * v5[0] > 0.5)) {
		double v6 = dist;
		if (nox_xxx_testUnitBuffs_4FF350(it, 10)) {
			v6 = v6 * 0.33333334;
		}
		if (v6 < *(float*)&dword_5d4594_2487980) {
			*(float*)&dword_5d4594_2487980 = v6;
			dword_5d4594_2487984 = it;
		}
	}
}

//----- (00533570) --------------------------------------------------------
int sub_533570(nox_object_t* obj) {
	float v2 = 640.0;
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		v2 = 250.0;
	}
	dword_5d4594_2487984 = 0;
	dword_5d4594_2487992 = 0;
	dword_5d4594_2487980 = 1259902592;
	nox_xxx_unitsGetInCircle_517F90(&obj->x, v2, nox_xxx_fnPickEnemyAggro_533460, obj);
	return dword_5d4594_2487984;
}

//----- (005335D0) --------------------------------------------------------
int sub_5335D0(int a1, float a2) {
	dword_5d4594_2487984 = 0;
	dword_5d4594_2487992 = 0;
	*(float*)&dword_5d4594_2487980 = a2;
	nox_xxx_unitsGetInCircle_517F90((float2*)(a1 + 56), a2, nox_xxx_fnPickEnemyAggro_533460, a1);
	return dword_5d4594_2487984;
}

//----- (00533610) --------------------------------------------------------
int nox_xxx_unused_533610(int a1, int a2) {
	char* v2;   // esi
	char* v3;   // eax
	int result; // eax

	v2 = sub_533660(a1);
	v3 = sub_533660(a2);
	if (v2 && v3) {
		result = v2[130] == v3[130];
	} else {
		result = 1;
	}
	return result;
}

//----- (00533660) --------------------------------------------------------
char* sub_533660(int a1) {
	int v1;  // eax
	int2 v3; // [esp+4h] [ebp-8h]

	v1 = *(uint32_t*)(a1 + 8);
	if (v1 & 4) {
		return nox_xxx_polygonGetByIdx_4214A0(*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 3664));
	}
	if (!(v1 & 2)) {
		return 0;
	}
	v3.field_0 = nox_float2int(*(float*)(a1 + 56));
	v3.field_4 = nox_float2int(*(float*)(a1 + 60));
	return (char*)nox_xxx_polygonIsPlayerInPolygon_4217B0(&v3, 0);
}

//----- (005336D0) --------------------------------------------------------
long double sub_5336D0(int a1) {
	long double result; // st7

	dword_5d4594_2487984 = 0;
	dword_5d4594_2487980 = 1287568416;
	nox_xxx_unitsGetInCircle_517F90((float2*)(a1 + 56), 1000.0, sub_533720, a1);
	if (dword_5d4594_2487984) {
		result = sqrt(*(float*)&dword_5d4594_2487980);
	} else {
		result = -1.0;
	}
	return result;
}

//----- (00533720) --------------------------------------------------------
void sub_533720(int a1, int a2) {
	double v2; // st7
	double v3; // st6
	double v4; // st5

	if (*(uint8_t*)(a1 + 8) & 6 && nox_xxx_unitIsEnemyTo_5330C0(a2, a1) && !(*(uint32_t*)(a1 + 16) & 0x8020)) {
		v2 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
		v3 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
		v4 = v3 * v3 + v2 * v2;
		if (v4 < *(float*)&dword_5d4594_2487980) {
			*(float*)&dword_5d4594_2487980 = v4;
			dword_5d4594_2487984 = a1;
		}
	}
}

//----- (00533790) --------------------------------------------------------
int nox_xxx_mobActionToAnimation_533790(int a1) {
	int v1;          // edi
	char v2;         // al
	unsigned int v3; // esi
	int result;      // eax

	v1 = *(uint32_t*)(a1 + 748);
	v2 = *(uint8_t*)(v1 + 544);
	if (v2 == -1) {
	LABEL_15:
		v3 = 8;
	} else {
		switch (*(uint32_t*)(v1 + 24 * (v2 + 23))) {
		case 7:
		case 8:
		case 0xA:
		case 0xD:
		case 0x1D:
		case 0x24:
		case 0x25:
			v3 = (*(uint32_t*)(v1 + 1440) & 0x4000 | 0x30000u) >> 14;
			break;
		case 9:
			v3 = 12;
			break;
		case 0x10:
			v3 = 1;
			break;
		case 0x11:
			v3 = 3;
			break;
		case 0x12:
		case 0x13:
		case 0x14:
			v3 = 7;
			break;
		case 0x15:
		case 0x17:
			v3 = 5;
			break;
		case 0x16:
			v3 = 6;
			break;
		case 0x18:
			v3 = 13;
			break;
		case 0x1E:
			v3 = 9;
			break;
		case 0x1F:
			v3 = 10;
			break;
		case 0x21:
		case 0x23:
			v3 = 14;
			break;
		case 0x22:
			v3 = 15;
			break;
		default:
			goto LABEL_15;
		}
	}
	if (nox_xxx_unitIsMimic_534840(a1) && v3 == 8) {
		if (*(uint32_t*)(v1 + 1440) & 0x40000) {
			return 0;
		}
		return v3;
	}
	if (nox_xxx_unitIsPlant_534A10(a1) && v3 == 8) {
		if (!*(uint32_t*)(v1 + 1196)) {
			return 14;
		}
		return v3;
	}
	if (!nox_xxx_unitIsZombie_534A40(a1)) {
		return v3;
	}
	if (v3 != 9) {
		return v3;
	}
	result = 15;
	if (!(*(uint32_t*)(v1 + 1440) & 0x80000)) {
		return v3;
	}
	return result;
}

//----- (00533900) --------------------------------------------------------
void nox_xxx_orderUnit_533900(int owner, int creature, int orderType) {
	int i; // esi

	if (owner) {
		if (creature) {
			nox_xxx_enactUnitOrder_5339A0(owner, creature, orderType);
		} else {
			// Sends message to player. owner+8 might be isPlayer/isLocalPlayer
			if (*(uint8_t*)(owner + 8) & 4 && (orderType == 4 || orderType == 3 || orderType == 5)) {
				nox_xxx_orderUnitLocal_500C70(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(owner + 748) + 276) + 2064),
											  orderType);
			}
			// I think this loops through all of the owner's units
			for (i = *(uint32_t*)(owner + 516); i; i = *(uint32_t*)(i + 512)) {
				if (*(uint8_t*)(i + 8) & 2) {
					if (*(uint8_t*)(*(uint32_t*)(i + 748) + 1440) & 0x80) {
						nox_xxx_enactUnitOrder_5339A0(owner, i, orderType);
					}
				}
			}
		}
	}
}

//----- (005339A0) --------------------------------------------------------
void nox_xxx_enactUnitOrder_5339A0(int source, int unit, int orderId) {
	uint32_t* v3;     // edi
	int v4;           // eax
	uint32_t* v5;     // eax
	int sfxIdle;      // eax
	unsigned int v7;  // ebp
	int sfxGuard;     // eax
	int v9;           // eax
	int* v10;         // eax
	int v11;          // edi
	int sfxEscort;    // eax
	unsigned int v13; // edx
	int* v14;         // eax
	int v15;          // edx
	int sfxHunt;      // eax
	unsigned int v17; // ebp

	v3 = *(uint32_t**)(unit + 748);
	if (source && *(uint8_t*)(unit + 8) & 2) {
		if (nox_xxx_unitIsZombie_534A40(unit) && !orderId || (v4 = *(uint32_t*)(unit + 16), (v4 & 0x8000) == 0)) {
			if (v3[121] || (v5 = nox_xxx_monsterDefByTT_517560(*(unsigned short*)(unit + 4)), (v3[121] = v5) != 0)) {
				switch (orderId) {
				case 0:                                       // BANISH
					if (*(uint32_t*)(unit + 508) == source) { // 508 - unit owner?
						nox_xxx_banishUnit_5017F0(unit);
					}
					break;
				case 1:                                // OBSERVE
					if (*(uint8_t*)(source + 8) & 4) { // if source is player / local player ???
						nox_xxx_playerObserveMonster_4DDE80(source, unit);
					}
					break;
				case 2: // IDLE
					if (*(uint8_t*)(source + 8) & 4) {
						nox_xxx_monsterCmdSend_528BD0(unit, source, "MonUtil.c:idle", 0);
					}
					sfxIdle = nox_xxx_monsterGetSoundSet_424300(unit);
					if (sfxIdle) {
						nox_xxx_aud_501960(*(uint32_t*)(sfxIdle + 68), unit, 0, 0);
					}
					v7 = v3[360] & 0xFFFFFFBF;
					v3[326] = 1056964608;
					v3[360] = v7;
					nox_xxx_monsterClearActionStack_50A3A0(unit);
					nox_xxx_monsterPushAction_50A260(unit, 0);
					break;
				case 3: // GUARD
					if (nox_xxx_monsterIsMoveing_534320(unit)) {
						if (*(uint8_t*)(source + 8) & 4) {
							nox_xxx_monsterCmdSend_528BD0(unit, source, "MonUtil.c:guarding", 0);
						}
						sfxGuard = nox_xxx_monsterGetSoundSet_424300(unit);
						if (sfxGuard) {
							nox_xxx_aud_501960(*(uint32_t*)(sfxGuard + 68), unit, 0, 0);
						}
						v3[326] = 1056964608;
						if (nox_xxx_monsterCanShoot_534280(unit)) {
							v9 = v3[360];
							LOBYTE(v9) = v9 | 0x40;
							v3[360] = v9;
						}
						v3[328] = 1132068864;
						nox_xxx_monsterClearActionStack_50A3A0(unit);
						v10 = nox_xxx_monsterPushAction_50A260(unit, 4);
						if (v10) {
							v10[1] = *(uint32_t*)(unit + 56);
							v10[2] = *(uint32_t*)(unit + 60);
							v10[3] = *(short*)(unit + 124);
						}
					}
					break;
				case 4: // ESCORT
					v11 = *(uint32_t*)(unit + 748);
					if (nox_xxx_monsterIsMoveing_534320(unit)) {
						if (*(uint8_t*)(source + 8) & 4) {
							nox_xxx_monsterCmdSend_528BD0(unit, source, "MonUtil.c:escorting", 0);
						}
						sfxEscort = nox_xxx_monsterGetSoundSet_424300(unit);
						if (sfxEscort) {
							nox_xxx_aud_501960(*(uint32_t*)(sfxEscort + 68), unit, 0, 0);
						}
						v13 = *(uint32_t*)(v11 + 1440) & 0xFFFFFFBF;
						*(uint32_t*)(v11 + 1304) = 1062501089;
						*(uint32_t*)(v11 + 1440) = v13;
						nox_xxx_monsterClearActionStack_50A3A0(unit);
						v14 = nox_xxx_monsterPushAction_50A260(unit, 3);
						if (v14) {
							v14[1] = *(uint32_t*)(source + 56);
							v15 = *(uint32_t*)(source + 60);
							v14[3] = source;
							v14[2] = v15;
						}
					}
					break;
				case 5: // HUNT
					if (nox_xxx_monsterIsMoveing_534320(unit)) {
						sfxHunt = nox_xxx_monsterGetSoundSet_424300(unit);
						if (sfxHunt) {
							nox_xxx_aud_501960(*(uint32_t*)(sfxHunt + 68), unit, 0, 0);
						}
						if (*(uint8_t*)(source + 8) & 4) {
							nox_xxx_monsterCmdSend_528BD0(unit, source, "MonUtil.c:Hunting", 0);
						}
						v17 = v3[360] & 0xFFFFFFBF;
						v3[326] = 1062501089;
						v3[360] = v17;
						nox_xxx_monsterClearActionStack_50A3A0(unit);
						nox_xxx_monsterPushAction_50A260(unit, 5);
					}
					break;
				default:
					return;
				}
			}
		}
	}
}

//----- (00533C80) --------------------------------------------------------
int sub_533C80(int a1, int a2) {
	float* v2; // ecx

	v2 = getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a1 + 124));
	return (*(float*)(a2 + 60) - *(float*)(a1 + 60)) * v2[1] + (*(float*)(a2 + 56) - *(float*)(a1 + 56)) * *v2 > 0.0;
}

//----- (00533CC0) --------------------------------------------------------
void nox_xxx_mobCalcDir_533CC0(int a1, float* a2) {
	float2 v2; // [esp+4h] [ebp-8h]

	if (a1) {
		v2.field_0 = *a2 - *(float*)(a1 + 56);
		v2.field_4 = a2[1] - *(float*)(a1 + 60);
		*(uint16_t*)(a1 + 126) = nox_xxx_math_509ED0(&v2);
	}
}

//----- (00533D00) --------------------------------------------------------
unsigned char* nox_xxx_unitNPCActionToAnim_533D00(int a1) {
	int v1;                // esi
	int v2;                // eax
	int v3;                // eax
	int v4;                // eax
	unsigned char* result; // eax
	int v6;                // [esp+4h] [ebp-4h]

	v1 = *(uint32_t*)(a1 + 748);
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		v2 = *(char*)(v1 + 544) + 23;
		a1 = 0;
		v6 = 0;
		v3 = *(uint32_t*)(v1 + 24 * v2);
		switch (v3) {
		case 16:
		case 17:
			if (*(uint32_t*)(v1 + 2056) & 0xFFFFFFFC) {
				v4 = sub_4FA280(*(uint32_t*)(v1 + 2056) & 0xFFFFFFFC);
			} else {
				v4 = *(unsigned char*)(v1 + 2068);
			}
			nox_xxx_animPlayerGetFrameRange_4F9F90(v4, &a1, &v6);
			break;
		case 18:
		case 19:
		case 20:
			nox_xxx_animPlayerGetFrameRange_4F9F90(21, &a1, &v6);
			break;
		case 30:
			nox_xxx_animPlayerGetFrameRange_4F9F90(1, &a1, &v6);
			break;
		case 31:
			nox_xxx_animPlayerGetFrameRange_4F9F90(2, &a1, &v6);
			break;
		case 21:
			nox_xxx_animPlayerGetFrameRange_4F9F90(40, &a1, &v6);
			break;
		case 23:
			if (*(uint32_t*)(v1 + 2056) & 0x7FF8000) {
				nox_xxx_animPlayerGetFrameRange_4F9F90(30, &a1, &v6);
			} else {
				nox_xxx_animPlayerGetFrameRange_4F9F90(47, &a1, &v6);
			}
			break;
		}
		*getMemU32Ptr(0x5D4594, 2487968) = 0;
		*getMemU32Ptr(0x5D4594, 2487964) = 0;
		*getMemU32Ptr(0x5D4594, 2487972) = 0;
		*getMemU32Ptr(0x5D4594, 2487976) = 0;
		*getMemU8Ptr(0x5D4594, 2487973) = a1;
		*getMemU8Ptr(0x5D4594, 2487974) = v6;
		result = getMemAt(0x5D4594, 2487964);
	} else if (*(uint32_t*)(v1 + 476)) {
		result = (unsigned char*)(*(uint32_t*)(v1 + 476) + 16 * nox_xxx_mobActionToAnimation_533790(a1));
	} else {
		result = 0;
	}
	return result;
}

//----- (00533E70) --------------------------------------------------------
int nox_xxx_monsterTestBlockShield_533E70(int a1) {
	*getMemU32Ptr(0x5D4594, 2487956) = 0;
	*getMemU32Ptr(0x5D4594, 2487988) = 1315859240; // fp32 100
	sub_518170(a1 + 56, 100.0, sub_533EB0, a1);
	return *getMemU32Ptr(0x5D4594, 2487956);
}

//----- (00533EB0) --------------------------------------------------------
void sub_533EB0(int a1, int a2) {
	int v2;         // esi
	float v3;       // ecx
	int v4;         // ecx
	double v5;      // st7
	double v6;      // st6
	float* v7;      // ecx
	double v8;      // st7
	long double v9; // st5
	float v10;      // [esp+Ch] [ebp-18h]
	float v11;      // [esp+10h] [ebp-14h]
	float2 a3;      // [esp+14h] [ebp-10h]
	float v13;      // [esp+1Ch] [ebp-8h]
	float v14;      // [esp+28h] [ebp+4h]

	v2 = a1;
	v3 = *(float*)(a1 + 76);
	a3.field_0 = *(float*)(a1 + 72);
	a3.field_4 = v3;
	if (sub_54E6F0(a2, a1)) {
		if (nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a2 + 56), *(short*)(a2 + 124), &a3) & 1) {
			v4 = *(short*)(a2 + 124);
			v5 = *(float*)(a1 + 80) * *getMemFloatPtr(0x587000, 194136 + 8 * v4);
			v6 = *(float*)(a1 + 84) * *getMemFloatPtr(0x587000, 194140 + 8 * v4);
			v7 = getMemFloatPtr(0x587000, 194136 + 8 * v4);
			if (v5 + v6 < 0.0) {
				v10 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
				v11 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
				v8 = *v7 * v11 + -v7[1] * v10;
				if (v8 < 0.0) {
					v8 = -v8;
				}
				if (v8 < 20.0) {
					v9 = sqrt(*(float*)(a1 + 80) * *(float*)(a1 + 80) + *(float*)(a1 + 84) * *(float*)(a1 + 84));
					v13 = *(float*)(a1 + 80) / v9;
					v14 = sqrt(v11 * v11 + v10 * v10);
					if (*(float*)(v2 + 84) / v9 * -(v11 / v14) + v13 * -(v10 / v14) > 0.69999999) {
						if (nox_xxx_unitCanInteractWith_5370E0(a2, v2, 0)) {
							if (v14 < (double)*getMemFloatPtr(0x5D4594, 2487988)) {
								*getMemU32Ptr(0x5D4594, 2487956) = v2;
								*getMemFloatPtr(0x5D4594, 2487988) = v14;
							}
						}
					}
				}
			}
		}
	}
}

//----- (00534020) --------------------------------------------------------
int sub_534020(int a1) { return (*(uint32_t*)(a1 + 12) >> 10) & 1; }

//----- (00534030) --------------------------------------------------------
char nox_xxx_monsterMoveAudio_534030(int a1) {
	int v1;          // ebx
	char v2;         // al
	int v3;          // esi
	unsigned int v4; // ecx
	unsigned int v5; // edi
	unsigned int v6; // eax
	int v7;          // ecx
	unsigned int v9; // [esp+Ch] [ebp-8h]
	int v10;         // [esp+10h] [ebp-4h]

	v1 = a1;
	v2 = *(uint8_t*)(a1 + 12);
	v3 = *(uint32_t*)(a1 + 748);
	v10 = *(uint32_t*)(a1 + 748);
	if (v2 & 0x30) {
		nox_xxx_animPlayerGetFrameRange_4F9F90(4, &v9, &a1);
		v4 = *(uint32_t*)(v1 + 36) + nox_frame_xxx_2598000;
		v5 = v4 / (a1 + 1) % v9;
		v6 = (v4 - 1) / (a1 + 1) / v9;
		if (v5 != (v4 - 1) / (a1 + 1) % v9) {
			v6 = *(uint32_t*)(v10 + 484);
			if (v5 == *(uint32_t*)(v6 + 100) || v5 == *(uint32_t*)(v6 + 104)) {
				v6 = nox_xxx_monsterGetSoundSet_424300(v1);
				if (v6) {
					LOBYTE(v6) = (unsigned int)nox_xxx_aud_501960(*(uint32_t*)(v6 + 72), v1, 0, 0);
				}
			}
		}
	} else {
		v6 = *(uint32_t*)(v3 + 484);
		v7 = *(unsigned char*)(v3 + 481);
		if (v7 == *(uint32_t*)(v6 + 100) || v7 == *(uint32_t*)(v6 + 104)) {
			LOBYTE(v6) = *(uint8_t*)(v3 + 482);
			if (!(uint8_t)v6) {
				v6 = nox_xxx_monsterGetSoundSet_424300(a1);
				if (v6) {
					LOBYTE(v6) = (unsigned int)nox_xxx_aud_501960(*(uint32_t*)(v6 + 72), v1, 0, 0);
				}
			}
		}
	}
	return v6;
}

//----- (00534120) --------------------------------------------------------
int sub_534120(int a1, float2* a2) {
	return *getMemFloatPtr(0x587000, 194140 + 8 * *(short*)(a1 + 124)) * a2->field_4 +
			   *getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a1 + 124)) * a2->field_0 >
		   0.89999998;
}

//----- (00534160) --------------------------------------------------------
nox_object_t* sub_534160(int a1) {
	int result; // eax
	int i;      // ecx

	result = a1;
	if (a1) {
		for (i = *(uint32_t*)(a1 + 508); i; i = *(uint32_t*)(i + 508)) {
			if (*(uint8_t*)(result + 8) & 6) {
				break;
			}
			result = i;
		}
		if (result) {
			if (!(*(uint8_t*)(result + 8) & 6)) {
				result = 0;
			}
		}
	}
	return result;
}

//----- (005341A0) --------------------------------------------------------
#ifdef NOX_CGO
void nox_ai_debug_print(char* str);
#else // NOX_CGO
void nox_ai_debug_print(const char* str) {
	fprintf(stderr, "%s", str);
}
#endif // NOX_CGO
void nox_ai_debug_printf_5341A0(char* a1, ...) {
	// char debug[1024];
	va_list va; // [esp+8h] [ebp+8h]

	va_start(va, a1);
	// nox_vsprintf(debug, a1, va);
	// OutputDebugStringA(debug);
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_AI)) {
		nox_vsprintf((char*)getMemAt(0x5D4594, 2487996), a1, va);
		nox_ai_debug_print((char*)getMemAt(0x5D4594, 2487996));
	}
}

//----- (005341D0) --------------------------------------------------------
int sub_5341D0(int a1) {
	nox_xxx_spellBuffOff_4FF5B0(a1, 0);
	return nox_xxx_spellBuffOff_4FF5B0(a1, 23);
}

//----- (005341F0) --------------------------------------------------------
int sub_5341F0(nox_object_t* a1p) {
	int a1 = a1p;
	int v1; // eax

	v1 = *(uint32_t*)(a1 + 748);
	return !*(uint8_t*)(v1 + 544) && !*(uint32_t*)(v1 + 552);
}

//----- (00534220) --------------------------------------------------------
int nox_xxx_monsterCanMelee_534220(int a1) {
	int v1;     // edi
	int result; // eax

	v1 = *(uint32_t*)(a1 + 748);
	if (nox_xxx_monsterCanCast_534300(a1)) {
		goto LABEL_9;
	}
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		return !nox_xxx_monsterCanShoot_534280(a1);
	}
	if (*(float*)(*(uint32_t*)(v1 + 484) + 112) <= 0.0) {
	LABEL_9:
		result = 0;
	} else {
		result = 1;
	}
	return result;
}

//----- (00534280) --------------------------------------------------------
int nox_xxx_monsterCanShoot_534280(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = *(uint32_t*)(a1 + 748);
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		result = (*(uint32_t*)(v1 + 2056) & 0x47F00FE) != 0;
	} else {
		result = *(uint8_t*)(*(uint32_t*)(v1 + 484) + 148) != 0;
	}
	return result;
}

//----- (005342C0) --------------------------------------------------------
int nox_xxx_monsterHasShield_5342C0(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = *(uint32_t*)(a1 + 748);
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		result = (*(uint32_t*)(v1 + 2060) & 0x3000000) != 0;
	} else {
		result = (*(uint32_t*)(v1 + 1440) >> 2) & 1;
	}
	return result;
}

//----- (00534300) --------------------------------------------------------
int nox_xxx_monsterCanCast_534300(int a1) { return (*(uint32_t*)(*(uint32_t*)(a1 + 748) + 1440) >> 5) & 1; }

//----- (00534320) --------------------------------------------------------
int nox_xxx_monsterIsMoveing_534320(int a1) { return *(float*)(a1 + 548) >= 0.0099999998; }

//----- (00534340) --------------------------------------------------------
int sub_534340(int a1) {
	int v1; // eax

	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 24 * (*(char*)(*(uint32_t*)(a1 + 748) + 544) + 23));
	return !v1 || v1 == 1 || v1 == 4 || v1 == 25 || v1 == 26 || v1 == 27 || v1 == 23;
}

//----- (00534390) --------------------------------------------------------
int nox_xxx_monsterCanAttackAtWill_534390(int a1) { return *(float*)(*(uint32_t*)(a1 + 748) + 1304) > 0.66000003; }

//----- (005343C0) --------------------------------------------------------
int sub_5343C0(int a1) {
	int v1; // ecx

	v1 = *(uint32_t*)(a1 + 748);
	return *(float*)(v1 + 1304) < 0.66000003 && *(float*)(v1 + 1304) > 0.33000001;
}

//----- (00534400) --------------------------------------------------------
int sub_534400(int a1) {
	int v1; // ecx

	v1 = *(uint32_t*)(a1 + 748);
	return *(float*)(v1 + 1304) < 0.33000001 && *(float*)(v1 + 1304) > 0.079999998;
}

//----- (00534440) --------------------------------------------------------
int sub_534440(int a1) { return *(float*)(*(uint32_t*)(a1 + 748) + 1304) < 0.079999998; }

//----- (00534470) --------------------------------------------------------
double sub_534470(int a1) { return *(float*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 484) + 112); }

//----- (00534490) --------------------------------------------------------
char* nox_xxx_unused_534490(float a1) {
	int v1;    // edx
	float* v2; // ecx

	v1 = 0;
	v2 = getMemFloatPtr(0x587000, 261712);
	while (a1 != *v2) {
		v2 += 2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 261744)) {
			return *(char**)getMemAt(0x587000, 261716);
		}
	}
	return *(char**)getMemAt(0x587000, 261716 + 8 * v1);
}

//----- (005344C0) --------------------------------------------------------
double nox_xxx_unused_5344C0(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 261716);
	while (strcmp(*v2, a1)) {
		v2 += 2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 261748)) {
			return 0.5;
		}
	}
	return *getMemFloatPtr(0x587000, 261712 + 8 * v1);
}

//----- (00534530) --------------------------------------------------------
char* nox_xxx_unused_534530(int a1) {
	char* result; // eax

	if (a1 < 0 || a1 >= 5) {
		result = *(char**)getMemAt(0x587000, 261744);
	} else {
		result = *(char**)getMemAt(0x587000, 261744 + 4 * a1);
	}
	return result;
}

//----- (00534550) --------------------------------------------------------
int nox_xxx_unused_534550(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 261744);
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 261764)) {
			return 3;
		}
	}
	return v1;
}

//----- (005345B0) --------------------------------------------------------
char* sub_5345B0(int a1) {
	unsigned char* v1; // ecx
	int v2;            // eax

	v1 = getMemAt(0x587000, 262056);
	while (*(uint32_t*)v1 != a1) {
	LABEL_6:
		v1 += 4;
		if ((int)v1 >= (int)getMemAt(0x587000, 262072)) {
			return *(char**)getMemAt(0x587000, 261920);
		}
	}
	v2 = 0;
	while (v2 != a1) {
		if (++v2 >= 39) {
			goto LABEL_6;
		}
	}
	return *(char**)getMemAt(0x587000, 261768 + 4 * v2);
}

//----- (005345F0) --------------------------------------------------------
int nox_xxx_actionNByNameMB_5345F0(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 261768);
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 261924)) {
			return 38;
		}
	}
	return v1;
}

//----- (00534650) --------------------------------------------------------
char* sub_534650(int a1) {
	int v1; // eax

	v1 = 0;
	while (v1 != a1) {
		if (++v1 >= 72) {
			return 0;
		}
	}
	return *(char**)getMemAt(0x587000, 261768 + 4 * v1);
}

//----- (00534670) --------------------------------------------------------
int nox_xxx_actionByName_534670(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 261768);
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 262056)) {
			return 0;
		}
	}
	return v1;
}

//----- (005346D0) --------------------------------------------------------
int sub_5346D0(int a1) {
	int result; // eax

	result = *(uint32_t*)(a1 + 748);
	*(uint32_t*)(result + 8) = 0;
	*(uint32_t*)(result + 296) = 0;
	return result;
}

//----- (005346F0) --------------------------------------------------------
int nox_xxx_monsterResetEnemy_5346F0(int a1) {
	int result; // eax

	result = a1;
	*(uint32_t*)(*(uint32_t*)(a1 + 748) + 1196) = 0;
	return result;
}

//----- (00534710) --------------------------------------------------------
int sub_534710(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = *(uint32_t*)(a1 + 748);
	if (*(uint8_t*)(v1 + 1440) & 0x40) {
		result = 1;
	} else {
		result = *(uint32_t*)(v1 + 24 * (*(char*)(v1 + 544) + 23)) == 4;
	}
	return result;
}

//----- (00534750) --------------------------------------------------------
int sub_534750(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = *(uint32_t*)(a1 + 748);
	result = *(uint32_t*)(v1 + 1440);
	if (!(result & 0x10000)) {
		BYTE1(result) |= 0x40u;
		*(uint32_t*)(v1 + 1440) = result;
	}
	return result;
}

//----- (00534780) --------------------------------------------------------
int sub_534780(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = *(uint32_t*)(a1 + 748);
	result = *(uint32_t*)(v1 + 1440);
	if ((result & 0x8000) == 0) {
		BYTE1(result) &= 0xBFu;
		*(uint32_t*)(v1 + 1440) = result;
	}
	return result;
}

//----- (005347A0) --------------------------------------------------------
int sub_5347A0(nox_object_t* a1) { return (*(uint32_t*)(*(uint32_t*)((int)a1 + 748) + 1440) >> 9) & 1; }

//----- (005347C0) --------------------------------------------------------
int sub_5347C0(int a1) {
	unsigned short* v1; // eax
	unsigned short v2;  // cx
	int result;         // eax

	v1 = *(unsigned short**)(a1 + 556);
	result = 0;
	if (v1) {
		v2 = v1[2];
		if (*v1 < v2) {
			if (v2) {
				result = 1;
			}
		}
	}
	return result;
}

//----- (005347F0) --------------------------------------------------------
int nox_xxx_isNotPoisoned_5347F0(int a1) { return *(uint8_t*)(a1 + 540) != 0; }

//----- (00534810) --------------------------------------------------------
int nox_xxx_mobGetMoveAttemptTime_534810(nox_object_t* a1) {
	return nox_frame_xxx_2598000 - *(uint32_t*)(*(uint32_t*)((int)a1 + 748) + 508) < (unsigned int)(3 * nox_gameFPS);
}

//----- (00534840) --------------------------------------------------------
int nox_xxx_unitIsMimic_534840(int a1) {
	int v1; // eax

	v1 = *getMemU32Ptr(0x5D4594, 2488524);
	if (!*getMemU32Ptr(0x5D4594, 2488524)) {
		v1 = nox_xxx_getNameId_4E3AA0("Mimic");
		*getMemU32Ptr(0x5D4594, 2488524) = v1;
	}
	return *(unsigned short*)(a1 + 4) == v1;
}

//----- (00534870) --------------------------------------------------------
int* nox_xxx_unused_534870(int a1) {
	int* result; // eax

	result = (int*)nox_xxx_unitIsMimic_534840(a1);
	if (result) {
		nox_xxx_monsterPushAction_50A260(a1, 61);
		result = nox_xxx_monsterPushAction_50A260(a1, 33);
	}
	return result;
}

//----- (005348A0) --------------------------------------------------------
int* nox_xxx_unused_5348A0(int a1) {
	int* result; // eax

	result = (int*)nox_xxx_unitIsMimic_534840(a1);
	if (result) {
		nox_xxx_monsterPushAction_50A260(a1, 61);
		result = nox_xxx_monsterPushAction_50A260(a1, 34);
	}
	return result;
}

//----- (005348D0) --------------------------------------------------------
char nox_xxx_mobActionMorphToChest_5348D0(int a1) {
	int v1;      // esi
	char result; // al

	v1 = *(uint32_t*)(a1 + 748);
	result = *(uint8_t*)(v1 + 483);
	if (result) {
		nox_xxx_monsterPopAction_50A160(a1);
		*(uint32_t*)(v1 + 1440) |= 0x40000u;
		result = (unsigned int)nox_xxx_monsterMarkUpdate_4E8020(a1);
	}
	return result;
}

//----- (00534910) --------------------------------------------------------
char nox_xxx_mobActionMorphBackToSelf_534910(int a1) {
	int v1;      // esi
	char result; // al

	v1 = *(uint32_t*)(a1 + 748);
	result = *(uint8_t*)(v1 + 483);
	if (result) {
		nox_xxx_monsterPopAction_50A160(a1);
		*(uint32_t*)(v1 + 1440) &= 0xFFFBFFFF;
		result = (unsigned int)nox_xxx_monsterMarkUpdate_4E8020(a1);
	}
	return result;
}

//----- (00534950) --------------------------------------------------------
void nox_xxx_monsterMimicCheckMorph_534950(int a1) {
	int v1;    // ecx
	int v2;    // edx
	int v3;    // eax
	double v4; // st7
	double v5; // st6

	v1 = *(uint32_t*)(a1 + 748);
	v2 = *(uint32_t*)(v1 + 24 * (*(char*)(v1 + 544) + 23));
	v3 = v1 + 24 * (*(char*)(v1 + 544) + 23);
	if (v2 && (v2 != 4 || (v4 = *(float*)(v3 + 4) - *(float*)(a1 + 56), v5 = *(float*)(v3 + 8) - *(float*)(a1 + 60),
						   v5 * v5 + v4 * v4 > 64.0))) {
		if (v2 != 34 && *(uint32_t*)(v1 + 1440) & 0x40000) {
			nox_xxx_monsterPushAction_50A260(a1, 61);
			nox_xxx_monsterPushAction_50A260(a1, 34);
			goto LABEL_10;
		}
	} else if (!(*(uint32_t*)(v1 + 1440) & 0x40000) &&
			   (unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(v1 + 548)) > (int)nox_gameFPS) {
		nox_xxx_monsterPushAction_50A260(a1, 61);
		nox_xxx_monsterPushAction_50A260(a1, 33);
	LABEL_10:
		nox_xxx_aud_501960(460, a1, 0, 0);
		return;
	}
}

//----- (00534A10) --------------------------------------------------------
int nox_xxx_unitIsPlant_534A10(int a1) {
	int v1; // eax

	v1 = *getMemU32Ptr(0x5D4594, 2488528);
	if (!*getMemU32Ptr(0x5D4594, 2488528)) {
		v1 = nox_xxx_getNameId_4E3AA0("CarnivorousPlant");
		*getMemU32Ptr(0x5D4594, 2488528) = v1;
	}
	return *(unsigned short*)(a1 + 4) == v1;
}

//----- (00534A40) --------------------------------------------------------
int nox_xxx_unitIsZombie_534A40(int a1) {
	int v1; // eax

	if (!*getMemU32Ptr(0x5D4594, 2488532)) {
		*getMemU32Ptr(0x5D4594, 2488532) = nox_xxx_getNameId_4E3AA0("Zombie");
		*getMemU32Ptr(0x5D4594, 2488536) = nox_xxx_getNameId_4E3AA0("VileZombie");
	}
	v1 = *(unsigned short*)(a1 + 4);
	return (unsigned short)v1 == *getMemU32Ptr(0x5D4594, 2488532) || v1 == *getMemU32Ptr(0x5D4594, 2488536);
}

//----- (00534A90) --------------------------------------------------------
char nox_xxx_mobActionGetUp_534A90(int a1) {
	char result; // al

	result = a1;
	if (*(uint8_t*)(*(uint32_t*)(a1 + 748) + 483)) {
		result = nox_xxx_monsterPopAction_50A160(a1);
	}
	return result;
}

//----- (00534AB0) --------------------------------------------------------
unsigned int nox_xxx_mobRaiseZombie_534AB0(int a1) {
	unsigned int result; // eax

	result = nox_xxx_unitIsZombie_534A40(a1);
	if (result) {
		result = nox_xxx_mobActionGet_50A020(a1);
		if (result == 31) {
			nox_xxx_monsterPopAction_50A160(a1);
			nox_xxx_monsterPushAction_50A260(a1, 61);
			nox_xxx_monsterPushAction_50A260(a1, 35);
			nox_xxx_aud_501960(469, a1, 0, 0);
			nox_xxx_unitHPsetOnMax_4EE6F0(a1);
			result = *(uint32_t*)(a1 + 16) & 0xFFFF7FA7;
			*(uint32_t*)(a1 + 16) = result;
		}
	}
	return result;
}

//----- (00534B10) --------------------------------------------------------
int nox_xxx_unitIsAFish_534B10(int a1) {
	int v1; // eax
	int v2; // ecx

	v1 = *getMemU32Ptr(0x5D4594, 2488544);
	if (!*getMemU32Ptr(0x5D4594, 2488544)) {
		*getMemU32Ptr(0x5D4594, 2488540) = nox_xxx_getNameId_4E3AA0("FishBig");
		v1 = nox_xxx_getNameId_4E3AA0("FishSmall");
		*getMemU32Ptr(0x5D4594, 2488544) = v1;
	}
	v2 = *(unsigned short*)(a1 + 4);
	return (unsigned short)v2 == v1 || v2 == *getMemU32Ptr(0x5D4594, 2488540);
}

//----- (00534B60) --------------------------------------------------------
int nox_xxx_unitIsARat_534B60(int a1) {
	int v1; // eax

	v1 = *getMemU32Ptr(0x5D4594, 2488548);
	if (!*getMemU32Ptr(0x5D4594, 2488548)) {
		v1 = nox_xxx_getNameId_4E3AA0("Rat");
		*getMemU32Ptr(0x5D4594, 2488548) = v1;
	}
	return *(unsigned short*)(a1 + 4) == v1;
}

//----- (00534B90) --------------------------------------------------------
int nox_xxx_unitIsAFrog_534B90(int a1) {
	int v1; // eax

	v1 = *getMemU32Ptr(0x5D4594, 2488552);
	if (!*getMemU32Ptr(0x5D4594, 2488552)) {
		v1 = nox_xxx_getNameId_4E3AA0("GreenFrog");
		*getMemU32Ptr(0x5D4594, 2488552) = v1;
	}
	return *(unsigned short*)(a1 + 4) == v1;
}

//----- (00534BC0) --------------------------------------------------------
int nox_xxx_damageToMap_534BC0(int a1, int a2, int a3, int a4, int a5) {
	unsigned char* v5; // esi
	unsigned char v6;  // al
	int v7;            // eax
	int v8;            // ecx
	int result;        // eax
	unsigned char v10; // al
	int v11;           // ecx
	int v12;           // eax
	int v13;           // eax
	char* v14;         // eax
	uint32_t* v15;     // edi
	float v16;         // [esp+0h] [ebp-1Ch]
	int2 v17;

	v5 = (unsigned char*)nox_server_getWallAtGrid_410580(a1, a2);
	if (!*getMemU32Ptr(0x5D4594, 2488556)) {
		*getMemU32Ptr(0x5D4594, 2488556) = nox_xxx_wallTileByName_410D60("MagicWallSystemUseOnly");
	}
	if (!v5) {
		return 0;
	}
	v6 = v5[4];
	if (v6 & 0x20) {
		return 0;
	}
	if (!(v6 & 8)) {
		sub_532FE0(*getMemU16Ptr(0x85B3FC, 43080 + 12332 * v5[1]), a5);
		return 0;
	}
	if (!nox_common_gameFlags_check_40A5C0(4096) || !a5 || v5[1] != *getMemU32Ptr(0x5D4594, 2488556) ||
		(v7 = nox_xxx_findParentChainPlayer_4EC580(a5)) == 0 || (v8 = 99999999, !(*(uint8_t*)(v7 + 8) & 4))) {
		v8 = a3;
	}
	if (v5[7] - v8 > 0) {
		v10 = v5[7] - v8;
		v11 = v5[1];
		v5[7] = v10;
		*(float*)&v17.field_0 = (double)a1 * 23.0 + 11.5;
		*(float*)&v17.field_4 = (double)a2 * 23.0 + 11.5;
		v12 = nox_xxx_wallGetBrickTypeMB_410E40(v11);
		if (v12) {
			v13 = nox_common_randomInt_415FA0(0, v12 - 1);
			v14 = nox_xxx_wallGetBrickObj_410E60(v5[1], v13);
			v15 = nox_xxx_newObjectByTypeID_4E3810(v14);
			if (v15) {
				nox_xxx_createAt_4DAA50((int)v15, 0, *(float*)&v17.field_0, *(float*)&v17.field_4);
				v16 = nox_common_randomFloat_416030(10.0, 20.0);
				nox_xxx_objectApplyForce_52DF80((int)&v17, (int)v15, v16);
			}
		}
		sub_533010(*getMemU16Ptr(0x85B3FC, 43080 + 12332 * v5[1]), a5);
		result = 0;
	} else {
		v17.field_0 = a1;
		v17.field_4 = a2;
		result = nox_xxx_wallPreDestroy_534DA0(&v17);
	}
	return result;
}

//----- (00534DA0) --------------------------------------------------------
int nox_xxx_wallPreDestroy_534DA0(int* a1) {
	int v1;        // edi
	char v2;       // al
	double v3;     // st7
	char* v4;      // eax
	int v5;        // eax
	int v6;        // eax
	int v7;        // ebx
	int v8;        // eax
	int v9;        // ebp
	char* v10;     // eax
	uint32_t* v11; // esi
	int v13;       // [esp+0h] [ebp-24h]
	float v14;     // [esp+0h] [ebp-24h]
	float v15;     // [esp+4h] [ebp-20h]
	float v16;     // [esp+8h] [ebp-1Ch]
	float2 v17;    // [esp+1Ch] [ebp-8h]

	v1 = nox_server_getWallAtGrid_410580(*a1, a1[1]);
	if (!*getMemU32Ptr(0x5D4594, 2488560)) {
		*getMemU32Ptr(0x5D4594, 2488560) = nox_xxx_wallTileByName_410D60("MagicWallSystemUseOnly");
	}
	if (!v1) {
		return 0;
	}
	v2 = *(uint8_t*)(v1 + 4);
	if (!(v2 & 8) || v2 & 0x20) {
		return 0;
	}
	v13 = *(unsigned char*)(v1 + 1);
	v17.field_0 = (double)*a1 * 23.0 + 11.5;
	v3 = (double)a1[1];
	*(uint8_t*)(v1 + 7) = 0;
	v17.field_4 = v3 * 23.0 + 11.5;
	v4 = nox_xxx_wallSoundByTile_410EA0(v13);
	v5 = nox_xxx_utilFindSound_40AF50(v4);
	nox_xxx_audCreate_501A30(v5, &v17, 0, 0);
	nox_xxx_netSendPointFx_522FF0(138, &v17);
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		v6 = nox_xxx_wallGetBrickTypeMB_410E40(*(unsigned char*)(v1 + 1));
		if (v6) {
			v7 = nox_common_randomInt_415FA0(0, v6 - 1);
			v8 = nox_common_randomInt_415FA0(3, 6);
			if (v8 > 0) {
				v9 = v8;
				do {
					v10 = nox_xxx_wallGetBrickObj_410E60(*(unsigned char*)(v1 + 1), v7);
					v11 = nox_xxx_newObjectByTypeID_4E3810(v10);
					if (v11) {
						v15 = nox_common_randomFloat_416030(-2.0, 2.0) + v17.field_4;
						v14 = nox_common_randomFloat_416030(-2.0, 2.0) + v17.field_0;
						nox_xxx_createAt_4DAA50((int)v11, 0, v14, v15);
						v16 = nox_common_randomFloat_416030(4.0, 10.0);
						nox_xxx_objectApplyForce_52DF80((int)&v17, (int)v11, v16);
					}
					if (++v7 >= nox_xxx_wallGetBrickTypeMB_410E40(*(unsigned char*)(v1 + 1))) {
						v7 = 0;
					}
					--v9;
				} while (v9);
			}
		}
	}
	if (*(unsigned char*)(v1 + 1) == *getMemU32Ptr(0x5D4594, 2488560)) {
		nox_xxx_wallDestroyMagicwallSysuse_4FF840(v1);
	} else {
		nox_xxx_wallDestroyedByWallid_410520(*(uint16_t*)(v1 + 10));
		nox_xxx_wallSendDestroyed_4DF0A0(v1, 32);
	}
	return 1;
}

//----- (00534FC0) --------------------------------------------------------
bool nox_xxx_mapDamageToWalls_534FC0(int4* a1, int a2, float a3, int a4, int a5, int a6) {
	int4* v6;        // edx
	int v7;          // edi
	int v8;          // eax
	int v9;          // ecx
	int v10;         // ecx
	int v11;         // ecx
	int v12;         // ecx
	int v13;         // ebx
	int v14;         // esi
	char* v15;       // edi
	float* v16;      // eax
	double v17;      // st7
	double v18;      // st7
	double v19;      // st7
	double v20;      // st7
	long double v21; // st7
	float v22;       // eax
	int* v23;        // esi
	int v25;         // [esp+8h] [ebp-144h]
	float v26;       // [esp+Ch] [ebp-140h]
	float v27;       // [esp+Ch] [ebp-140h]
	float v28;       // [esp+10h] [ebp-13Ch]
	int v29;         // [esp+14h] [ebp-138h]
	float v30;       // [esp+18h] [ebp-134h]
	float v31;       // [esp+1Ch] [ebp-130h]
	int v32;         // [esp+20h] [ebp-12Ch]
	int v33;         // [esp+24h] [ebp-128h]
	float* v34;      // [esp+28h] [ebp-124h]
	float v35;       // [esp+2Ch] [ebp-120h]
	int v36[2];      // [esp+30h] [ebp-11Ch]
	float v37;       // [esp+38h] [ebp-114h]
	float4 v38;
	char v41[256]; // [esp+4Ch] [ebp-100h]

	v6 = a1;
	v7 = 0;
	v25 = 0;
	if (!a1 || !a2) {
		return 0;
	}
	v8 = a6;
	v29 = 0;
	if (a6) {
		v9 = *(uint32_t*)(a6 + 8);
		if (v9 & 6) {
			v10 = *(short*)(a6 + 124);
			v29 = 1;
		} else {
			if (!(v9 & 0x1001000)) {
				goto LABEL_10;
			}
			v11 = *(uint32_t*)(a6 + 492);
			if (!v11) {
				goto LABEL_10;
			}
			v10 = *(short*)(v11 + 124);
			v29 = 1;
		}
		v34 = getMemFloatPtr(0x587000, 194136 + 8 * v10);
	}
LABEL_10:
	v12 = a1->field_C;
	v13 = a1->field_4;
	v33 = a1->field_4;
	v37 = a3 * a3;
	if (v13 <= v12) {
		do {
			v14 = v6->field_0;
			v32 = v6->field_0;
			if (v6->field_0 <= v6->field_8) {
				v15 = &v41[8 * v7 + 4];
				do {
					if (nox_server_getWallAtGrid_410580(v14, v13)) {
						v16 = (float*)(v29 ? a6 + 56 : a2);
						v17 = (double)v32;
						v35 = v17;
						v26 = v17 * 23.0 + 11.5 - *v16;
						v18 = (double)v33;
						v31 = v18;
						v19 = v18 * 23.0 + 11.5 - v16[1];
						v28 = v19;
						v20 = v19 * v28 + v26 * v26;
						v30 = v20;
						if (v20 < v37) {
							if (!v29 || v30 <= 0.0 ||
								(v21 = sqrt(v30) + 0.5, v27 = v26 / v21,
								 v28 / v21 * v34[1] + v27 * *v34 > *(double*)&qword_581450_9544)) {
								v22 = *(float*)(a2 + 4);
								v38.field_0 = *(float*)a2;
								v38.field_4 = v22;
								v38.field_8 = v35 * 23.0 + 11.5;
								v36[1] = 0;
								v36[0] = 0;
								v38.field_C = v31 * 23.0 + 11.5;
								if ((nox_xxx_mapTraceRay_535250(&v38, 0, (int2*)v36, 1) == 1 ||
									 v36[0] == v14 && v36[1] == v13) &&
									v25 < 32) {
									*((uint32_t*)v15 - 1) = v14;
									*(uint32_t*)v15 = v13;
									++v25;
									v15 += 8;
								}
							}
						}
					}
					v32 = ++v14;
				} while (v14 <= a1->field_8);
				v7 = v25;
				v8 = a6;
				v6 = a1;
			}
			v33 = ++v13;
		} while (v13 <= v6->field_C);
	}
	if (v7 > 0) {
		v23 = (int*)v41;
		while (1) {
			nox_xxx_damageToMap_534BC0(*v23, v23[1], a4, a5, v8);
			v23 += 2;
			if (!--v7) {
				break;
			}
			v8 = a6;
		}
		v7 = v25;
	}
	return v7 > 0;
}
// 535128: variable 'v34' is possibly undefined

//----- (00535250) --------------------------------------------------------
int nox_xxx_mapTraceRay_535250(float4* a1, float2* a2, int2* a3, char a4) {
	int v4;     // edi
	int v5;     // ebx
	float v6;   // eax
	double v7;  // st7
	int v8;     // eax
	float v10;  // edx
	double v11; // st7
	int v12;    // eax
	float v13;  // ecx
	double v14; // st7
	double v15; // st7
	float v16;  // et1
	float v17;  // et1
	double v18; // st7
	float v19;  // et1
	double v20; // st7
	float v21;  // et1
	double v22; // st7
	float v23;  // et1
	int v24;    // eax
	float v25;  // et1
	int v26;    // edi
	int v27;    // eax
	int v28;    // ebx
	float v29;  // ecx
	double v30; // st7
	float v31;  // et1
	float v32;  // et1
	double v33; // st7
	float v34;  // et1
	float v35;  // et1
	double v36; // st7
	float v37;  // et1
	int v38;    // eax
	float v39;  // et1
	int v40;    // edi
	int v41;    // eax
	int v42;    // ebx
	float v43;  // edx
	float v44;  // [esp+8h] [ebp-5Ch]
	float v45;  // [esp+8h] [ebp-5Ch]
	float v46;  // [esp+8h] [ebp-5Ch]
	float v47;  // [esp+8h] [ebp-5Ch]
	float v48;  // [esp+1Ch] [ebp-48h]
	float v49;  // [esp+1Ch] [ebp-48h]
	float v50;  // [esp+20h] [ebp-44h]
	float v51;  // [esp+20h] [ebp-44h]
	int v52;    // [esp+24h] [ebp-40h]
	int v53;    // [esp+24h] [ebp-40h]
	float v54;  // [esp+24h] [ebp-40h]
	float v55;  // [esp+24h] [ebp-40h]
	float v56;  // [esp+28h] [ebp-3Ch]
	float v57;  // [esp+28h] [ebp-3Ch]
	float v58;  // [esp+28h] [ebp-3Ch]
	float a1c;  // [esp+2Ch] [ebp-38h]
	int a1a;    // [esp+2Ch] [ebp-38h]
	int a1b;    // [esp+2Ch] [ebp-38h]
	float v62;  // [esp+30h] [ebp-34h]
	float v63;  // [esp+34h] [ebp-30h]
	int v64;    // [esp+38h] [ebp-2Ch]
	int v65;    // [esp+38h] [ebp-2Ch]
	float v66;  // [esp+38h] [ebp-2Ch]
	int v67;    // [esp+38h] [ebp-2Ch]
	int v68;    // [esp+38h] [ebp-2Ch]
	float v69;  // [esp+3Ch] [ebp-28h]
	float v70;  // [esp+3Ch] [ebp-28h]
	float v71;  // [esp+40h] [ebp-24h]
	float v72;  // [esp+40h] [ebp-24h]
	double v73; // [esp+44h] [ebp-20h]
	float v74;  // [esp+4Ch] [ebp-18h]
	float v75;  // [esp+50h] [ebp-14h]
	float4 a4a; // [esp+54h] [ebp-10h]

	v44 = a1->field_0 * 0.043478262;
	v4 = nox_float2int(v44);
	v45 = a1->field_4 * 0.043478262;
	v5 = nox_float2int(v45);
	v46 = a1->field_8 * 0.043478262;
	v6 = COERCE_FLOAT(nox_float2int(v46));
	v7 = a1->field_C * 0.043478262;
	v74 = v6;
	v47 = v7;
	v8 = nox_float2int(v47);
	if (v4 < 0 || v4 >= 256 || v5 < 0 || v5 >= 256) {
		return 0;
	}
	if (v4 == LODWORD(v74)) {
		v52 = -1;
		if (a1->field_C >= (double)a1->field_4) {
			v52 = 1;
		}
		v64 = v8 + v52;
		if (v5 != v8 + v52) {
			while (!nox_xxx_mapTraceRayImpl_57C9A0(v4, v5, a1, &a4a, a4)) {
				v5 += v52;
				if (v5 == v64) {
					return 1;
				}
			}
			if (a2) {
				v10 = a4a.field_4;
				a2->field_0 = a4a.field_0;
				a2->field_4 = v10;
			}
		LABEL_14:
			if (a3) {
				a3->field_0 = v4;
				a3->field_4 = v5;
			}
			return 0;
		}
	} else {
		v11 = a1->field_8;
		if (v5 == v8) {
			if (v11 >= a1->field_0) {
				v12 = 1;
			} else {
				v12 = -1;
			}
			v53 = v12;
			v65 = LODWORD(v74) + v12;
			if (v4 != LODWORD(v74) + v12) {
				while (!nox_xxx_mapTraceRayImpl_57C9A0(v4, v5, a1, &a4a, a4)) {
					v4 += v53;
					if (v4 == v65) {
						return 1;
					}
				}
				if (a2) {
					v13 = a4a.field_4;
					a2->field_0 = a4a.field_0;
					a2->field_4 = v13;
				}
				goto LABEL_14;
			}
		} else {
			a1c = v11 - a1->field_0;
			v14 = a1->field_C - a1->field_4;
			v56 = v14;
			v62 = v14 / a1c;
			v63 = a1->field_4 - v56 * a1->field_0 / a1c;
			v66 = sub_419A10(a1c);
			if (sub_419A10(v56) >= v66) {
				if (a1->field_0 >= (double)a1->field_8) {
					v58 = a1->field_8;
					v55 = a1->field_0;
					v51 = -1.0;
				} else {
					v58 = a1->field_0;
					v55 = a1->field_8;
					v51 = 1.0;
				}
				v49 = 1.0;
				if (a1->field_4 >= (double)a1->field_C) {
					v49 = -1.0;
				}
				v30 = a1->field_0;
				if (v30 <= v55) {
					while (v30 >= v58) {
						v31 = *(float*)&nox_xxx_float_23_587000_264364;
						modf(v30 / v31, &v73);
						v32 = *(float*)&nox_xxx_float_23_587000_264364;
						v33 = nox_double2float(v32 * v73);
						if (v51 <= *(double*)&qword_581450_9568) {
							v70 = v33;
							v35 = *(float*)&nox_xxx_float_23_587000_264364;
							v74 = v33 + v35;
						} else {
							v74 = v33;
							v34 = *(float*)&nox_xxx_float_23_587000_264364;
							v70 = v33 + v34;
						}
						a1b = nox_double2int(v73);
						v36 = v74 * v62 + v63;
						if (v49 > *(double*)&qword_581450_9568 && v36 < a1->field_4 ||
							v49 < *(double*)&qword_581450_9568 && v36 > a1->field_4) {
							v36 = a1->field_4;
						}
						v72 = v70 * v62 + v63;
						if (v49 > *(double*)&qword_581450_9568 && v72 > (double)a1->field_C ||
							v49 < *(double*)&qword_581450_9568 && v72 < (double)a1->field_C) {
							v72 = a1->field_C;
						}
						v37 = *(float*)&nox_xxx_float_23_587000_264364;
						modf(v36 / v37, &v73);
						v38 = nox_double2int(v73 - v49);
						v39 = *(float*)&nox_xxx_float_23_587000_264364;
						v40 = v38;
						modf(v72 / v39, &v73);
						v41 = nox_double2int(v49 + v73);
						v42 = v40 >= v41 ? -1 : 1;
						v68 = v42 + v41;
						if (v40 != v42 + v41) {
							while (!nox_xxx_mapTraceRayImpl_57C9A0(a1b, v40, a1, &a4a, a4)) {
								v40 += v42;
								if (v40 == v68) {
									goto LABEL_80;
								}
							}
							if (a2) {
								v43 = a4a.field_4;
								a2->field_0 = a4a.field_0;
								a2->field_4 = v43;
							}
							if (a3) {
								a3->field_4 = v40;
								a3->field_0 = a1b;
								return 0;
							}
							return 0;
						}
					LABEL_80:
						v30 = v51 * 0.1 + v70;
						if (v30 > v55) {
							return 1;
						}
					}
				}
			} else {
				if (a1->field_4 >= (double)a1->field_C) {
					v57 = a1->field_C;
					v54 = a1->field_4;
					v50 = -1.0;
				} else {
					v57 = a1->field_4;
					v54 = a1->field_C;
					v50 = 1.0;
				}
				v48 = 1.0;
				if (a1->field_0 >= (double)a1->field_8) {
					v48 = -1.0;
				}
				v15 = a1->field_4;
				if (v15 <= v54) {
					while (v15 >= v57) {
						v16 = *(float*)&nox_xxx_float_23_587000_264364;
						modf(v15 / v16, &v73);
						v17 = *(float*)&nox_xxx_float_23_587000_264364;
						v18 = v17 * v73;
						if (v50 <= *(double*)&qword_581450_9568) {
							v20 = nox_double2float(v18);
							v71 = v20;
							v21 = *(float*)&nox_xxx_float_23_587000_264364;
							v75 = v20 + v21;
						} else {
							v75 = nox_double2float(v18);
							v19 = *(float*)&nox_xxx_float_23_587000_264364;
							v71 = v19 + v75;
						}
						a1a = nox_double2int(v73);
						v22 = (v75 - v63) / v62;
						if (v48 > *(double*)&qword_581450_9568 && v22 < a1->field_0 ||
							v48 < *(double*)&qword_581450_9568 && v22 > a1->field_0) {
							v22 = a1->field_0;
						}
						v69 = (v71 - v63) / v62;
						if (v48 > *(double*)&qword_581450_9568 && v69 > (double)a1->field_8 ||
							v48 < *(double*)&qword_581450_9568 && v69 < (double)a1->field_8) {
							v69 = a1->field_8;
						}
						v23 = *(float*)&nox_xxx_float_23_587000_264364;
						modf(v22 / v23, &v73);
						v24 = nox_double2int(v73 - v48);
						v25 = *(float*)&nox_xxx_float_23_587000_264364;
						v26 = v24;
						modf(v69 / v25, &v73);
						v27 = nox_double2int(v48 + v73);
						v28 = v26 >= v27 ? -1 : 1;
						v67 = v28 + v27;
						if (v26 != v28 + v27) {
							while (!nox_xxx_mapTraceRayImpl_57C9A0(v26, a1a, a1, &a4a, a4)) {
								v26 += v28;
								if (v26 == v67) {
									goto LABEL_51;
								}
							}
							if (a2) {
								v29 = a4a.field_4;
								a2->field_0 = a4a.field_0;
								a2->field_4 = v29;
							}
							if (a3) {
								a3->field_0 = v26;
								a3->field_4 = a1a;
								return 0;
							}
							return 0;
						}
					LABEL_51:
						v15 = v50 * 0.1 + v71;
						if (v15 > v54) {
							return 1;
						}
					}
				}
			}
		}
	}
	return 1;
}

//----- (00535970) --------------------------------------------------------
int nox_xxx_parseXP_535970(int a1, int a2, char* a3) {
	sscanf(a3, "%f", a1 + 44);
	return 1;
}

//----- (00535990) --------------------------------------------------------
int nox_xxx_parseExtent_535990(int a1, int a2, char* a3) { return nox_parse_shape((nox_shape*)(a1 + 60), a3); }

//----- (005359B0) --------------------------------------------------------
int nox_xxx_parseZSize_5359B0(int a1, int a2, char* a3) {
	int v5; // [esp+0h] [ebp-4h]

	sscanf(a3, "%d %d", &v5, &a3);
	if ((int)a3 < (int)v5) {
		a3 = v5;
	}
	*(float*)(a1 + 112) = (double)(int)v5;
	*(float*)(a1 + 116) = (double)(int)a3;
	return 1;
}

//----- (00535A00) --------------------------------------------------------
int nox_xxx_parseWorth_535A00(int a1, int a2, char* a3) {
	sscanf(a3, "%d", a1 + 48);
	return 1;
}

//----- (00535A20) --------------------------------------------------------
int nox_xxx_parseSpeed_535A20(int a1, int a2, char* a3) {
	double v3; // st7

	sscanf(a3, "%d", &a3);
	v3 = (double)(int)a3 * 0.03125;
	*(uint32_t*)(a1 + 132) = 0;
	*(float*)(a1 + 124) = v3;
	*(float*)(a1 + 128) = v3;
	return 1;
}

//----- (00535A60) --------------------------------------------------------
int nox_xxx_parseHealth_535A60(int a1, int a2, char* a3) {
	int result; // eax

	sscanf(a3, "%d", &a3);
	if (*(uint32_t*)(a1 + 136)) {
		free(*(void**)(a1 + 136));
	}
	result = (int)calloc(1u, 0x14u);
	*(uint32_t*)(a1 + 136) = result;
	if (result) {
		*(uint16_t*)(result + 4) = (uint16_t)a3;
		**(uint16_t**)(a1 + 136) = (uint16_t)a3;
		result = 1;
	}
	return result;
}

//----- (00535AD0) --------------------------------------------------------
int nox_xxx_parseFlags_535AD0(int a1, int a2, const char* a3) {
	*(uint32_t*)(a1 + 32) = 0;
	set_bitmask_flags_from_plus_separated_names_423930(a3, (uint32_t*)(a1 + 32),
													   (const char**)getMemAt(0x587000, 264368));
	return 1;
}

//----- (00535B00) --------------------------------------------------------
int nox_xxx_parseClass_535B00(int a1, int a2, const char* a3) {
	*(uint32_t*)(a1 + 24) = 0;
	set_bitmask_flags_from_plus_separated_names_423930(a3, (uint32_t*)(a1 + 24),
													   (const char**)getMemAt(0x587000, 264500));
	return 1;
}

//----- (00535B30) --------------------------------------------------------
int nox_xxx_parseSubclass_535B30(int a1, int a2, const char* a3) {
	*(uint32_t*)(a1 + 28) = 0;
	set_bitmask_flags_from_plus_separated_names_multiple_423A10(a3, (uint32_t*)(a1 + 28));
	return 1;
}

//----- (00535B60) --------------------------------------------------------
int nox_xxx_parseMass_535B60(int a1, int a2, char* a3) {
	sscanf(a3, "%f", a1 + 56);
	return 1;
}

//----- (00535B80) --------------------------------------------------------
int nox_xxx_parseCapacity_535B80(int a1, int a2, char* a3) {
	sscanf(a3, "%d", &a3);
	*(uint16_t*)(a1 + 122) = (uint16_t)a3;
	return 1;
}

//----- (00535BB0) --------------------------------------------------------
int nox_xxx_parseWeight_535BB0(int a1, int a2, char* a3) {
	sscanf(a3, "%d", &a3);
	*(uint8_t*)(a1 + 120) = (uint8_t)a3;
	return 1;
}

//----- (00535BE0) --------------------------------------------------------
int nox_xxx_parseMaterial_535BE0(int a1, int a2, const char* a3) {
	int v4; // [esp+0h] [ebp-4h]

	v4 = 0;
	set_bitmask_flags_from_plus_separated_names_423930(a3, &v4, (const char**)getMemAt(0x587000, 265912));
	*(uint16_t*)(a1 + 40) = v4;
	return 1;
}

//----- (00535C20) --------------------------------------------------------
int nox_xxx_parseLightIntensity_535C20(int a1, int a2, char* a3) { return 1; }

//----- (00535C30) --------------------------------------------------------
int nox_xxx_parseMenuIcon_535C30(int a1, int a2, char* a3) {
	int v2; // edx

	*(uint32_t*)(a1 + 12) = **(uint32_t**)(a2 + 8);
	v2 = *(uint32_t*)(a2 + 8) + 4;
	*(uint32_t*)(a2 + 8) = v2;
	if (*(int*)(a1 + 12) == -1) {
		*(uint32_t*)(a2 + 8) = v2 + 1;
		*(uint32_t*)(a2 + 8) = *(unsigned char*)(v2 + 1) + v2 + 1 + 1;
	}
	return 1;
}

//----- (00535C80) --------------------------------------------------------
int nox_xxx_parsePrettyImage_0_535C80(int a1, int a2) {
	int* v2;           // ecx
	int v3;            // edx
	int v4;            // ecx
	unsigned char* v5; // ecx

	v2 = *(int**)(a2 + 8);
	v3 = *v2;
	v4 = (int)(v2 + 1);
	*(uint32_t*)(a2 + 8) = v4;
	if (v3 == -1) {
		v5 = (unsigned char*)(v4 + 1);
		*(uint32_t*)(a2 + 8) = v5;
		*(uint32_t*)(a2 + 8) = &v5[*v5 + 1];
	}
	return 1;
}

//----- (00535CD0) --------------------------------------------------------
int nox_xxx_parseDraw_535CD0(int a1, uint32_t* a2, void* a3) {
	uint32_t* v3;       // ebp
	void* v4;           // ebx
	unsigned char* v5;  // eax
	int result;         // eax
	int v7;             // esi
	char* v8;           // eax
	uint32_t* v9;       // eax
	int v10;            // ecx
	char* v11;          // eax
	int v12;            // edi
	unsigned char* v13; // eax
	int v14;            // edi
	char* v15;          // esi
	unsigned char* v16; // eax
	int i;              // eax
	char* v18;          // ecx
	char v19;           // dl
	char* v20;          // eax
	char v21;           // cl
	char* v22;          // eax
	char v23;           // cl
	unsigned char* v24; // eax
	int v25;            // esi
	int* v26;           // eax
	int v27;            // ecx
	int v28;            // eax
	unsigned char* v29; // eax
	unsigned char v30;  // di
	uint32_t* v31;      // eax
	int v32;            // ecx
	unsigned char* v33; // eax
	const char** v34;   // ecx
	unsigned char* v35; // eax
	unsigned char v36;  // cl
	char v37;           // cl
	int v38;            // esi
	int* v39;           // ecx
	int v40;            // edx
	int v41;            // ecx
	unsigned char* v42; // ecx
	int v43;            // [esp-14h] [ebp-2Ch]
	uint32_t* v44;      // [esp-4h] [ebp-1Ch]
	int v45;            // [esp+10h] [ebp-8h]
	int v46;            // [esp+14h] [ebp-4h]
	char* v47;          // [esp+1Ch] [ebp+4h]
	unsigned char v48;  // [esp+1Ch] [ebp+4h]
	unsigned char v49;  // [esp+20h] [ebp+8h]
	unsigned char v50;  // [esp+20h] [ebp+8h]
	unsigned char v51;  // [esp+20h] [ebp+8h]
	unsigned char v52;  // [esp+20h] [ebp+8h]
	unsigned char v53;  // [esp+20h] [ebp+8h]
	unsigned char v54;  // [esp+20h] [ebp+8h]
	unsigned char v55;  // [esp+20h] [ebp+8h]
	int v56;            // [esp+24h] [ebp+Ch]
	int v57;            // [esp+24h] [ebp+Ch]

	v3 = a2;
	v4 = a3;
	v5 = (unsigned char*)a2[2];
	v44 = a2;
	v49 = *v5;
	v44[2] = v5 + 1;
	nox_memfile_read(a3, 1u, v49, (int)v44);
	*((uint8_t*)a3 + v49) = 0;
	nox_memfile_read64align_40AD60((char*)&v45, 4, 1, v3);
	result = 0;
	if (!strcmp((const char*)a3, "MonsterDraw")) {
		v7 = *(uint32_t*)(a1 + 192);
		if (!v7) {
			return result;
		}
		v8 = (char*)calloc(1u, 0x100u);
		v47 = v8;
		if (!v8) {
			return 0;
		}
		*(uint32_t*)(v7 + 476) = v8;
		while (1) {
			v9 = (uint32_t*)v3[2];
			v10 = *v9;
			v11 = (char*)(v9 + 1);
			v3[2] = v11;
			if (v10 != 1398030676) {
				break;
			}
			v12 = *v11;
			v13 = (unsigned char*)(v11 + 1);
			v3[2] = v13;
			if (v12 >= 16) {
				return 0;
			}
			v50 = *v13;
			v3[2] = v13 + 1;
			nox_memfile_read(v4, 1u, v50, (int)v3);
			*((uint8_t*)v4 + v50) = 0;
			v14 = 16 * v12;
			v15 = &v47[v14];
			v56 = (int)&v47[v14];
			*(uint32_t*)&v47[v14] = nox_xxx_utilFindSound_40AF50(v4);
			v16 = (unsigned char*)v3[2];
			v51 = *v16;
			v3[2] = v16 + 1;
			for (i = 0; i < v51; ++i) {
				v18 = (char*)v3[2];
				v19 = *v18;
				v3[2] = v18 + 1;
				v15[i + 4] = v19;
			}
			v15[8] = i;
			v20 = (char*)v3[2];
			v21 = *v20;
			v3[2] = v20 + 1;
			v15[9] = v21;
			v22 = (char*)v3[2];
			v23 = *v22;
			v3[2] = v22 + 1;
			v15[10] = v23;
			v24 = (unsigned char*)v3[2];
			v52 = *v24;
			v3[2] = v24 + 1;
			nox_memfile_read(v4, 1u, v52, (int)v3);
			*((uint8_t*)v4 + v52) = 0;
			*(uint32_t*)(v56 + 12) = !strcmp((const char*)v4, "Loop") || !strcmp((const char*)v4, "LoopAndFade");
			v45 = 8 * *(unsigned char*)(v56 + 9);
			if (v45 > 0) {
				v25 = v45;
				do {
					v26 = (int*)v3[2];
					v27 = *v26;
					v28 = (int)(v26 + 1);
					v3[2] = v28;
					if (v27 == -1) {
						v29 = (unsigned char*)(v28 + 1);
						v3[2] = v29;
						v3[2] = &v29[*v29 + 1];
					}
					--v25;
				} while (v25);
			}
		}
	} else {
		if (!strcmp((const char*)a3, "AnimateStateDraw")) {
			v3[2] += v45;
			return 1;
		}
		if (!strcmp((const char*)a3, "PlayerDraw")) {
			v30 = a1;
			while (1) {
				v31 = (uint32_t*)v3[2];
				v32 = *v31;
				v33 = (unsigned char*)(v31 + 1);
				v3[2] = v33;
				if (v32 == 1162757152) {
					break;
				}
				if (v32 == 1398030676) {
					v53 = *v33;
					v3[2] = v33 + 1;
					nox_memfile_read(v4, 1u, v53, (int)v3);
					*((uint8_t*)v4 + v53) = 0;
					v57 = 0;
					v34 = (const char**)getMemAt(0x587000, 268120);
					do {
						if (!strcmp(*v34, (const char*)v4)) {
							break;
						}
						++v34;
						++v57;
					} while ((int)v34 < (int)getMemAt(0x587000, 268340));
					if (v57 == 55) {
						return 0;
					}
					v35 = (unsigned char*)v3[2];
					v36 = *v35++;
					v3[2] = v35;
					v48 = v36;
					v37 = *v35++;
					v3[2] = v35;
					LOBYTE(v46) = v37;
					v54 = *v35;
					v3[2] = v35 + 1;
					nox_memfile_read(v4, 1u, v54, (int)v3);
					v30 = v48;
					v43 = (unsigned char)v46;
					*((uint8_t*)v4 + v54) = 0;
					nox_xxx_anim_4F9FB0(v57, v48, v43);
				} else if (v32 == 1397051733) {
					v55 = *v33;
					v3[2] = v33 + 1;
					nox_memfile_read(v4, 1u, v55, (int)v3);
					*((uint8_t*)v4 + v55) = 0;
					v45 = 8 * v30;
					if (8 * v30 > 0) {
						v38 = 8 * v30;
						do {
							v39 = (int*)v3[2];
							v40 = *v39;
							v41 = (int)(v39 + 1);
							v3[2] = v41;
							if (v40 == -1) {
								v42 = (unsigned char*)(v41 + 1);
								v3[2] = v42;
								v3[2] = &v42[*v42 + 1];
							}
							--v38;
						} while (v38);
					}
				}
			}
		} else {
			v3[2] += v45;
		}
	}
	return 1;
}

//----- (005360A0) --------------------------------------------------------
int nox_xxx_parseXFer_5360A0(int a1, int a2, char* a3) {
	char* v3;          // eax
	const char* v4;    // ecx
	int v5;            // ebp
	unsigned char* v6; // edi

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)getMemAt(0x587000, 269128);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 269128)) {
		v6 = getMemAt(0x587000, 269128);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 2);
			v6 += 8;
			++v5;
		} while (v4);
	}
	if (!*getMemU32Ptr(0x587000, 269128 + 8 * v5)) {
		return 0;
	}
	*(uint32_t*)(a1 + 212) = *getMemU32Ptr(0x587000, 269132 + 8 * v5);
	return 1;
}

//----- (00536130) --------------------------------------------------------
char* sub_536130(char* a1, int* a2) {
	char* result; // eax
	int v3;       // eax
	char* v4;     // eax

	result = strtok(a1, " ");
	if (result) {
		v3 = nox_xxx_enchantByName_424880(result);
		*a2 = v3;
		if (v3 == -1) {
			result = 0;
		} else {
			v4 = strtok(0, " ");
			a2[1] = atoi(v4);
			result = (char*)1;
		}
	}
	return result;
}

//----- (00536180) --------------------------------------------------------
char* sub_536180(char* a1, int* a2) {
	char* result; // eax

	result = strtok(a1, " ");
	if (result) {
		*a2 = nox_xxx_spellNameToN_4243F0(result);
		result = (char*)1;
	}
	return result;
}

//----- (005361B0) --------------------------------------------------------
char* sub_5361B0(char* a1, int a2) {
	char* result; // eax
	char v3;      // al
	double v4;    // [esp+4h] [ebp-8h]

	*(uint32_t*)a2 = 1;
	result = strtok(a1, " ");
	if (result) {
		v3 = atoi(result);
		*(uint8_t*)(a2 + 109) = v3;
		*(uint8_t*)(a2 + 108) = v3;
		*(uint32_t*)(a2 + 112) = 100;
		result = strtok(0, " ");
		if (result) {
			v4 = (double)nox_gameFPS;
			*(uint32_t*)(a2 + 100) = (long long)(v4 / atof(result));
			result = strtok(0, " ");
			if (result) {
				*(uint32_t*)(a2 + 92) = nox_xxx_spellNameToN_4243F0(result);
				result = (char*)1;
			}
		}
	}
	return result;
}

//----- (00536260) --------------------------------------------------------
char* sub_536260(char* a1, int a2) {
	char* result; // eax
	char v3;      // al
	char* v4;     // eax
	int v5;       // eax
	char* v6;     // eax
	double v7;    // [esp+Ch] [ebp-8h]
	double v8;

	*(uint32_t*)a2 = 0;
	result = strtok(a1, " ");
	if (result) {
		v3 = atoi(result);
		*(uint8_t*)(a2 + 109) = v3;
		*(uint8_t*)(a2 + 108) = v3;
		*(uint32_t*)(a2 + 112) = 100;
		result = strtok(0, " ");
		if (result) {
			strcpy((char*)(a2 + 4), result);
			*(uint32_t*)(a2 + 84) = 0;
			result = strtok(0, " ");
			if (result) {
				v7 = (double)nox_gameFPS;
				v8 = atof(result);
				if (v8 == 0.0) {
					*(uint32_t*)(a2 + 100) = 0;
				} else {
					*(uint32_t*)(a2 + 100) = (long long)(v7 / v8);
				}
				v4 = strtok(0, " ");
				if (v4 && !strcmp(v4, "MULTI_SHOT")) {
					v5 = *(uint32_t*)(a2 + 96);
					LOBYTE(v5) = v5 | 1;
					*(uint32_t*)(a2 + 96) = v5;
				}
				v6 = strtok(0, " ");
				if (v6) {
					*(uint32_t*)(a2 + 88) = nox_xxx_utilFindSound_40AF50(v6);
				}
				result = (char*)1;
			}
		}
	}
	return result;
}

//----- (00536390) --------------------------------------------------------
char* sub_536390(char* a1, int* a2) {
	char* result; // eax

	result = strtok(a1, " ");
	if (result) {
		*a2 = atoi(result);
		result = (char*)1;
	}
	return result;
}

//----- (005363C0) --------------------------------------------------------
char* sub_5363C0(char* a1, int* a2) {
	char* result; // eax

	result = strtok(a1, " ");
	if (result) {
		*a2 = atoi(result);
		result = (char*)1;
	}
	return result;
}

//----- (005363F0) --------------------------------------------------------
int nox_xxx_parseUseFn_5363F0(uint32_t* a1, int a2, char* a3) {
	char* v3;              // ebx
	const char* v4;        // eax
	int v5;                // ebp
	unsigned char* v6;     // edi
	int v7;                // ebp
	int result;            // eax
	int (*v9)(char*, int); // esi
	char* v10;             // [esp+1Ch] [ebp+Ch]

	v3 = strtok(a3, " \t\n\r");
	v10 = strtok(0, (const char*)getMemAt(0x5D4594, 2488564));
	v4 = *(const char**)getMemAt(0x587000, 269784);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 269784)) {
		v6 = getMemAt(0x587000, 269784);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 4);
			v6 += 16;
			++v5;
		} while (v4);
	}
	v7 = 16 * v5;
	if (!*getMemU32Ptr(0x587000, 269784 + v7)) {
		goto LABEL_13;
	}
	a1[50] = *getMemU32Ptr(0x587000, 269788 + v7);
	a1[52] = *getMemU32Ptr(0x587000, 269792 + v7);
	if (!*getMemU32Ptr(0x587000, 269792 + v7)) {
		goto LABEL_13;
	}
	result = (int)calloc(1u, *getMemU32Ptr(0x587000, 269792 + v7));
	a1[51] = result;
	if (!result) {
		return result;
	}
	v9 = *(int (**)(char*, int))getMemAt(0x587000, 269796 + v7);
	if (v9) {
		result = v9(v10, result);
	} else {
	LABEL_13:
		result = 1;
	}
	return result;
}

//----- (005364E0) --------------------------------------------------------
int sub_5364E0(char* a1, int a2) {
	unsigned int v2; // ecx
	char v3;         // al
	char* v4;        // edi
	char* v5;        // esi
	int result;      // eax
	char v7[256];    // [esp+Ch] [ebp-100h]

	sscanf(a1, "%s", v7);
	v2 = strlen(v7) + 1;
	v3 = v2;
	v2 >>= 2;
	memcpy((void*)(a2 + 16), v7, 4 * v2);
	v5 = &v7[4 * v2];
	v4 = (char*)(a2 + 16 + 4 * v2);
	LOBYTE(v2) = v3;
	result = 1;
	memcpy(v4, v5, v2 & 3);
	*(uint32_t*)(a2 + 12) = 0;
	return result;
}
// 5364E0: using guessed type char var_100[256];

//----- (00536550) --------------------------------------------------------
int sub_536550(char* a1, uint32_t* a2) {
	sscanf(a1, "%f %f", a2, a2 + 2);
	a2[1] = *a2;
	return 1;
}

//----- (00536580) --------------------------------------------------------
int sub_536580(char* a1, int a2) {
	sscanf(a1, "%d %d %d", a2, a2 + 4, a2 + 8);
	return 1;
}

//----- (005365B0) --------------------------------------------------------
int sub_5365B0(char* a1, int a2) {
	char* v2; // eax
	char* v3; // eax

	v2 = strtok(a1, " ");
	if (v2) {
		*(uint32_t*)(a2 + 36) = nox_xxx_utilFindSound_40AF50(v2);
	}
	v3 = strtok(0, " ");
	if (v3) {
		*(uint32_t*)(a2 + 40) = nox_xxx_utilFindSound_40AF50(v3);
	}
	return 1;
}

//----- (00536600) --------------------------------------------------------
int sub_536600(char* a1, int a2) {
	sscanf(a1, "%d", a2);
	return 1;
}

#ifndef NOX_CGO
//----- (00536620) --------------------------------------------------------
int nox_xxx_parseUpdate_536620(nox_objectType_t* a1p, int a2, char* a3) {
	uint32_t* a1 = a1p;
	char* v3;              // ebx
	const char* v4;        // eax
	int v5;                // ebp
	unsigned char* v6;     // edi
	int v7;                // ebp
	int (*v9)(char*, int); // esi
	char* v10;             // [esp+1Ch] [ebp+Ch]

	v3 = strtok(a3, " \t\n\r");
	v10 = strtok(0, (const char*)getMemAt(0x5D4594, 2488568));
	v4 = *(const char**)getMemAt(0x587000, 270328);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 270328)) {
		v6 = getMemAt(0x587000, 270328);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 4);
			v6 += 16;
			++v5;
		} while (v4);
	}
	v7 = 16 * v5;
	if (!*getMemU32Ptr(0x587000, 270328 + v7)) {
		return 1;
	}
	a1[47] = *getMemU32Ptr(0x587000, 270332 + v7);
	a1[49] = *getMemU32Ptr(0x587000, 270336 + v7);
	if (!*getMemU32Ptr(0x587000, 270336 + v7)) {
		return 1;
	}
	void* data = calloc(1u, *getMemU32Ptr(0x587000, 270336 + v7));
	a1[48] = data;
	if (!data) {
		return 0;
	}
	v9 = *(int (**)(char*, int))getMemAt(0x587000, 270340 + v7);
	if (v9) {
		return v9(v10, data);
	}
	return 1;
}
#endif // NOX_CGO

//----- (00536710) --------------------------------------------------------
int nox_xxx_parsePickup_536710(int a1, int a2, char* a3) {
	char* v3;          // eax
	const char* v4;    // ecx
	int v5;            // ebp
	unsigned char* v6; // edi
	void (*v7)(int);   // eax

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)getMemAt(0x587000, 272352);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 272352)) {
		v6 = getMemAt(0x587000, 272352);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 3);
			v6 += 12;
			++v5;
		} while (v4);
	}
	if (*getMemU32Ptr(0x587000, 272352 + 12 * v5)) {
		*(uint32_t*)(a1 + 184) = *getMemU32Ptr(0x587000, 272356 + 12 * v5);
		v7 = *(void (**)(int))getMemAt(0x587000, 272360 + 12 * v5);
		if (v7) {
			v7(a1);
		}
	}
	return 1;
}

//----- (005367B0) --------------------------------------------------------
char* sub_5367B0(short* a1) {
	unsigned char* v1; // eax
	int v2;            // ecx
	char* result;      // eax
	unsigned char* i;  // esi
	short v5;          // dx

	if (!*getMemU32Ptr(0x5D4594, 2488572)) {
		v1 = getMemAt(0x973F18, 15976);
		v2 = 51;
		do {
			*(uint16_t*)v1 = -1;
			*((uint16_t*)v1 + 1) = 0;
			v1 += 4;
			--v2;
		} while (v2);
		*getMemU32Ptr(0x5D4594, 2488572) = 1;
	}
	result = 0;
	for (i = getMemAt(0x973F18, 15976); *(short*)i != -1; i += 4) {
		if ((int)++result >= 50) {
			return result;
		}
	}
	result = strtok(0, " \t\n\r");
	if (result && *result) {
		result = (char*)nox_xxx_utilFindSound_40AF50(result);
		if ((uint16_t)result) {
			v5 = *a1;
			*((uint16_t*)i + 1) = (uint16_t)result;
			*(uint16_t*)i = v5;
		}
	}
	return result;
}

//----- (00536830) --------------------------------------------------------
int nox_xxx_parseCreateProc_536830(int a1, int a2, char* a3) {
	char* v3;          // eax
	const char* v4;    // ecx
	int v5;            // ebp
	unsigned char* v6; // edi

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)getMemAt(0x587000, 272808);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 272808)) {
		v6 = getMemAt(0x587000, 272808);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 3);
			v6 += 12;
			++v5;
		} while (v4);
	}
	if (*getMemU32Ptr(0x587000, 272808 + 12 * v5)) {
		*(uint32_t*)(a1 + 216) = *getMemU32Ptr(0x587000, 272812 + 12 * v5);
	}
	return 1;
}

//----- (005368C0) --------------------------------------------------------
int sub_5368C0(char* a1, int a2) {
	int* v2;  // esi
	char* v3; // eax
	char* v4; // eax

	v2 = *(int**)(a2 + 176);
	v3 = strtok(a1, " ");
	*v2 = atoi(v3);
	v4 = strtok(0, " ");
	v2[1] = atoi(v4);
	return 1;
}

//----- (00536910) --------------------------------------------------------
int sub_536910(int a1, int a2) {
	*(uint32_t*)(a2 + 36) = 2;
	return 1;
}

//----- (00536930) --------------------------------------------------------
int nox_xxx_parseInitProc_536930(uint32_t* a1, int a2, char* a3) {
	char* v3;                    // ebx
	const char* v4;              // eax
	int v5;                      // ebp
	unsigned char* v6;           // edi
	int v7;                      // ebp
	int result;                  // eax
	int (*v9)(char*, uint32_t*); // esi
	char* v10;                   // [esp+1Ch] [ebp+Ch]

	v3 = strtok(a3, " \t\n\r");
	v10 = strtok(0, (const char*)getMemAt(0x5D4594, 2488576));
	v4 = *(const char**)getMemAt(0x587000, 273112);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 273112)) {
		v6 = getMemAt(0x587000, 273112);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 4);
			v6 += 16;
			++v5;
		} while (v4);
	}
	v7 = 16 * v5;
	if (!*getMemU32Ptr(0x587000, 273112 + v7)) {
		goto LABEL_13;
	}
	a1[43] = *getMemU32Ptr(0x587000, 273116 + v7);
	a1[45] = *getMemU32Ptr(0x587000, 273120 + v7);
	if (!*getMemU32Ptr(0x587000, 273120 + v7)) {
		goto LABEL_13;
	}
	result = (int)calloc(1u, *getMemU32Ptr(0x587000, 273120 + v7));
	a1[44] = result;
	if (!result) {
		return result;
	}
	v9 = *(int (**)(char*, uint32_t*))getMemAt(0x587000, 273124 + v7);
	if (v9) {
		result = v9(v10, a1);
	} else {
	LABEL_13:
		result = 1;
	}
	return result;
}

//----- (00536A20) --------------------------------------------------------
int nox_xxx_parseDrop_536A20(int a1, int a2, char* a3) {
	char* v3;          // eax
	const char* v4;    // ecx
	int v5;            // ebp
	unsigned char* v6; // edi
	void (*v7)(int);   // eax

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)getMemAt(0x587000, 273768);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 273768)) {
		v6 = getMemAt(0x587000, 273768);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 3);
			v6 += 12;
			++v5;
		} while (v4);
	}
	if (*getMemU32Ptr(0x587000, 273768 + 12 * v5)) {
		*(uint32_t*)(a1 + 168) = *getMemU32Ptr(0x587000, 273772 + 12 * v5);
		v7 = *(void (**)(int))getMemAt(0x587000, 273776 + 12 * v5);
		if (v7) {
			v7(a1);
		}
	}
	return 1;
}

//----- (00536AC0) --------------------------------------------------------
char* sub_536AC0(short* a1) {
	unsigned char* v1; // eax
	int v2;            // ecx
	char* result;      // eax
	unsigned char* i;  // esi
	short v5;          // dx

	if (!*getMemU32Ptr(0x5D4594, 2488580)) {
		v1 = getMemAt(0x973F18, 15752);
		v2 = 51;
		do {
			*(uint16_t*)v1 = -1;
			*((uint16_t*)v1 + 1) = 0;
			v1 += 4;
			--v2;
		} while (v2);
		*getMemU32Ptr(0x5D4594, 2488580) = 1;
	}
	result = 0;
	for (i = getMemAt(0x973F18, 15752); *(short*)i != -1; i += 4) {
		if ((int)++result >= 50) {
			return result;
		}
	}
	result = strtok(0, " \t\n\r");
	if (result && *result) {
		result = (char*)nox_xxx_utilFindSound_40AF50(result);
		if ((uint16_t)result) {
			v5 = *a1;
			*((uint16_t*)i + 1) = (uint16_t)result;
			*(uint16_t*)i = v5;
		}
	}
	return result;
}

//----- (00536B40) --------------------------------------------------------
int sub_536B40(char* a1, int a2) {
	char v3[64]; // [esp+4h] [ebp-40h]

	sscanf(a1, "%s %s", a2, v3);
	*(uint32_t*)(a2 + 128) = nox_xxx_utilFindSound_40AF50(v3);
	return 1;
}

//----- (00536B80) --------------------------------------------------------
int nox_xxx_parseDieProc_536B80(int a1, int a2, char* a3) {
	char* v3;              // ebx
	const char* v4;        // eax
	int v5;                // ebp
	unsigned char* v6;     // edi
	int v7;                // ebp
	int result;            // eax
	int (*v9)(char*, int); // esi
	char* v10;             // [esp+1Ch] [ebp+Ch]

	v3 = strtok(a3, " \t\n\r");
	v10 = strtok(0, (const char*)getMemAt(0x5D4594, 2488584));
	v4 = *(const char**)getMemAt(0x587000, 274080);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 274080)) {
		v6 = getMemAt(0x587000, 274080);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 4);
			v6 += 16;
			++v5;
		} while (v4);
	}
	v7 = 16 * v5;
	if (!*getMemU32Ptr(0x587000, 274080 + v7)) {
		return 0;
	}
	*(uint32_t*)(a1 + 160) = *getMemU32Ptr(0x587000, 274084 + v7);
	if (!*getMemU32Ptr(0x587000, 274088 + v7)) {
		goto LABEL_14;
	}
	result = (int)calloc(1u, *getMemU32Ptr(0x587000, 274088 + v7));
	*(uint32_t*)(a1 + 164) = result;
	if (!result) {
		return result;
	}
	v9 = *(int (**)(char*, int))getMemAt(0x587000, 274092 + v7);
	if (v9) {
		result = v9(v10, result);
	} else {
	LABEL_14:
		result = 1;
	}
	return result;
}

//----- (00536C60) --------------------------------------------------------
int nox_xxx_parseDamageFn_536C60(int a1, int a2, char* a3) {
	char* v3;          // eax
	const char* v4;    // ecx
	int v5;            // ebp
	unsigned char* v6; // edi

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)getMemAt(0x587000, 274520);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 274520)) {
		v6 = getMemAt(0x587000, 274520);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 2);
			v6 += 8;
			++v5;
		} while (v4);
	}
	if (!*getMemU32Ptr(0x587000, 274520 + 8 * v5)) {
		return 0;
	}
	*(uint32_t*)(a1 + 152) = *getMemU32Ptr(0x587000, 274524 + 8 * v5);
	return 1;
}

//----- (00536CF0) --------------------------------------------------------
int nox_xxx_parseDamageSound_536CF0(int a1, int a2, char* a3) {
	char* v3;          // eax
	const char* v4;    // ecx
	int v5;            // ebp
	unsigned char* v6; // edi

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)getMemAt(0x587000, 274616);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 274616)) {
		v6 = getMemAt(0x587000, 274616);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 2);
			v6 += 8;
			++v5;
		} while (v4);
	}
	if (!*getMemU32Ptr(0x587000, 274616 + 8 * v5)) {
		return 0;
	}
	*(uint32_t*)(a1 + 156) = *getMemU32Ptr(0x587000, 274620 + 8 * v5);
	return 1;
}

//----- (00536D80) --------------------------------------------------------
int sub_536D80(char* a1, int a2) {
	sscanf(a1, "%d", a2);
	return 1;
}

//----- (00536DA0) --------------------------------------------------------
int sub_536DA0(char* a1, int* a2) {
	int v2;       // eax
	char v4[256]; // [esp+0h] [ebp-100h]

	sscanf(a1, "%s", v4);
	v2 = nox_xxx_utilFindSound_40AF50(v4);
	*a2 = v2;
	return v2 != 0;
}

//----- (00536DE0) --------------------------------------------------------
int sub_536DE0(char* a1, uint8_t* a2) {
	sscanf(a1, "%d", &a1);
	*a2 = (uint8_t)a1;
	return 1;
}

//----- (00536E10) --------------------------------------------------------
int nox_xxx_collideDamageLoad_536E10(char* a1, int a2) {
	char* v2; // eax
	char* v3; // eax
	int v4;   // eax

	v2 = strtok(a1, " ");
	*(uint8_t*)a2 = atoi(v2);
	v3 = strtok(0, " ");
	v4 = nox_xxx_parseDamageTypeByName_4E0A00(v3);
	*(uint32_t*)(a2 + 4) = v4;
	return v4 != 18;
}

//----- (00536E50) --------------------------------------------------------
int sub_536E50(char* a1, uint8_t* a2) {
	char* v2; // eax

	v2 = strtok(a1, " ");
	*a2 = atoi(v2);
	return 1;
}

//----- (00536E80) --------------------------------------------------------
int sub_536E80(char* a1, int* a2) {
	char* v2; // eax
	char* v3; // eax

	v2 = strtok(a1, " ");
	*a2 = atoi(v2);
	v3 = strtok(a1, " ");
	a2[1] = atoi(v3);
	return 1;
}

//----- (00536EC0) --------------------------------------------------------
int nox_xxx_parseCollide_536EC0(uint32_t* a1, int a2, char* a3) {
	char* v3;              // ebx
	const char* v4;        // eax
	int v5;                // ebp
	unsigned char* v6;     // edi
	int v7;                // ebp
	int result;            // eax
	int (*v9)(char*, int); // esi
	char* v10;             // [esp+1Ch] [ebp+Ch]

	v3 = strtok(a3, " \t\n\r");
	v10 = strtok(0, (const char*)getMemAt(0x5D4594, 2488588));
	v4 = *(const char**)getMemAt(0x587000, 274872);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 274872)) {
		v6 = getMemAt(0x587000, 274872);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 4);
			v6 += 16;
			++v5;
		} while (v4);
	}
	v7 = 16 * v5;
	if (!*getMemU32Ptr(0x587000, 274872 + v7)) {
		return 0;
	}
	a1[35] = *getMemU32Ptr(0x587000, 274876 + v7);
	a1[37] = *getMemU32Ptr(0x587000, 274880 + v7);
	if (!*getMemU32Ptr(0x587000, 274880 + v7)) {
		goto LABEL_14;
	}
	result = (int)calloc(1u, *getMemU32Ptr(0x587000, 274880 + v7));
	a1[36] = result;
	if (!result) {
		return result;
	}
	v9 = *(int (**)(char*, int))getMemAt(0x587000, 274884 + v7);
	if (v9) {
		result = v9(v10, result);
	} else {
	LABEL_14:
		result = 1;
	}
	return result;
}

//----- (00536FB0) --------------------------------------------------------
int nox_xxx_unitCanSee_536FB0(int a1, int a2, char a3) {
	int result; // eax
	int v4;     // eax
	int v5;     // eax
	int v6;     // eax

	if (!*getMemU32Ptr(0x5D4594, 2488592)) {
		*getMemU32Ptr(0x5D4594, 2488592) = nox_xxx_getNameId_4E3AA0("Pixie");
		*getMemU32Ptr(0x5D4594, 2488596) = nox_xxx_getNameId_4E3AA0("Hecubah");
		*getMemU32Ptr(0x5D4594, 2488600) = nox_xxx_getNameId_4E3AA0("Necromancer");
	}
	if (nox_xxx_testUnitBuffs_4FF350(a1, 2)) {
		return 0;
	}
	if (a3 & 1 || !nox_xxx_testUnitBuffs_4FF350(a2, 0)) {
		goto LABEL_10;
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		v4 = *(unsigned short*)(a1 + 4);
		if ((unsigned short)v4 == *getMemU32Ptr(0x5D4594, 2488596) || v4 == *getMemU32Ptr(0x5D4594, 2488600)) {
			goto LABEL_10;
		}
	} else if (nox_xxx_testUnitBuffs_4FF350(a1, 21)) {
		goto LABEL_10;
	}
	if (*(unsigned short*)(a1 + 4) != *getMemU32Ptr(0x5D4594, 2488592) || (v6 = *(uint32_t*)(a1 + 508)) == 0 ||
		!nox_xxx_testUnitBuffs_4FF350(v6, 21)) {
		if (*getMemFloatPtr(0x587000, 276732) >= fabs(*(float*)(a2 + 80)) &&
			*getMemFloatPtr(0x587000, 276732) >= fabs(*(float*)(a2 + 84))) {
			return 0;
		}
	}
LABEL_10:
	result = 1;
	if (*(uint8_t*)(a1 + 8) & 2) {
		v5 = *(uint32_t*)(a1 + 12);
		if (v5 & 0x2000) {
			if (nox_common_playerIsAbilityActive_4FC250(a2, 4)) {
				result = 0;
			}
		}
	}
	return result;
}

//----- (005370E0) --------------------------------------------------------
int nox_xxx_unitCanInteractWith_5370E0(nox_object_t* a1, nox_object_t* a2, char a3) {
	int result; // eax

	result = nox_xxx_unitCanSee_536FB0(a1, a2, a3);
	if (result) {
		result = nox_xxx_mapCheck_537110(a1, a2);
	}
	return result;
}

//----- (00537110) --------------------------------------------------------
int nox_xxx_mapCheck_537110(nox_object_t* a1p, int a2) {
	int a1 = a1p;
	int v2;     // eax
	int v3;     // esi
	int v4;     // eax
	int result; // eax
	float4 a1a; // [esp+4h] [ebp-2Ch]
	int a3[7];  // [esp+14h] [ebp-1Ch]

	v2 = *(uint32_t*)(a1 + 56);
	a3[4] = *(uint32_t*)(a1 + 60);
	a3[3] = v2;
	if (*(uint8_t*)(a2 + 8) < 0 && *(uint8_t*)(a2 + 12) & 4) {
		v3 = *(uint32_t*)(a2 + 748);
		*(float*)&a3[5] =
			(double)(*getMemIntPtr(0x587000, 196184 + 8 * *(uint32_t*)(v3 + 12)) / 2) + *(float*)(a2 + 56);
		*(float*)&a3[6] =
			(double)(*getMemIntPtr(0x587000, 196188 + 8 * *(uint32_t*)(v3 + 12)) / 2) + *(float*)(a2 + 60);
	} else {
		v4 = *(uint32_t*)(a2 + 60);
		a3[5] = *(uint32_t*)(a2 + 56);
		a3[6] = v4;
	}
	if (*(float*)&a3[3] >= (double)*(float*)&a3[5]) {
		a1a.field_8 = *(float*)&a3[3];
		LODWORD(a1a.field_0) = a3[5];
	} else {
		a1a.field_0 = *(float*)&a3[3];
		LODWORD(a1a.field_8) = a3[5];
	}
	if (*(float*)&a3[4] >= (double)*(float*)&a3[6]) {
		a1a.field_C = *(float*)&a3[4];
		LODWORD(a1a.field_4) = a3[6];
	} else {
		a1a.field_4 = *(float*)&a3[4];
		LODWORD(a1a.field_C) = a3[6];
	}
	a3[2] = a2;
	a3[0] = 1;
	a3[1] = a1;
	nox_xxx_getUnitsInRect_517C10(&a1a, nox_xxx_lineCollisionChk_537230, (int)a3);
	if (a3[0]) {
		result = nox_xxx_mapTraceRay_535250((float4*)&a3[3], 0, 0, 9);
	} else {
		result = 0;
	}
	return result;
}

//----- (00537230) --------------------------------------------------------
void nox_xxx_lineCollisionChk_537230(float* a1, int arg4) {
	int v2;     // ecx
	int v3;     // eax
	double v4;  // st7
	int v5;     // eax
	double v6;  // st6
	double v7;  // st7
	double v8;  // st7
	double v9;  // st7
	double v10; // st7
	float v11;  // [esp+14h] [ebp-2Ch]
	float v12;  // [esp+18h] [ebp-28h]
	float v13;  // [esp+1Ch] [ebp-24h]
	float v14;  // [esp+20h] [ebp-20h]
	float v15;  // [esp+24h] [ebp-1Ch]
	float2 a3;  // [esp+28h] [ebp-18h]
	float4 a2;  // [esp+30h] [ebp-10h]

	if (a1 != *(float**)(arg4 + 4) && a1 != *(float**)(arg4 + 8) && (uint32_t)a1[4] & 0x10000) {
		if ((signed char)*((uint8_t*)a1 + 8) >= 0) {
			v5 = *((uint32_t*)a1 + 43);
			if (v5 == 2) {
				if (nox_xxx_mathPointOnTheLine_57C8A0((float4*)(arg4 + 12), (float2*)a1 + 7, &a3)) {
					v6 = a3.field_4 - a1[15];
					if (v6 * v6 + (a3.field_0 - a1[14]) * (a3.field_0 - a1[14]) <= a1[45]) {
						*(uint32_t*)arg4 = 0;
					}
				}
			} else if (v5 == 3) {
				v14 = a1[48] + a1[14];
				v7 = a1[49] + a1[15];
				a2.field_0 = v14;
				v15 = v7;
				v8 = a1[50] + a1[14];
				a2.field_4 = v15;
				v12 = v8;
				v9 = a1[51] + a1[15];
				a2.field_8 = v12;
				v13 = v9;
				v10 = a1[52] + a1[14];
				a2.field_C = v13;
				v11 = a1[53] + a1[15];
				a3.field_0 = a1[54] + a1[14];
				a3.field_4 = a1[55] + a1[15];
				if (sub_427980((float4*)(arg4 + 12), &a2)) {
					goto LABEL_20;
				}
				a2.field_0 = v14;
				a2.field_4 = v15;
				a2.field_8 = v10;
				a2.field_C = v11;
				if (sub_427980((float4*)(arg4 + 12), &a2)) {
					goto LABEL_20;
				}
				a2.field_0 = a3.field_0;
				a2.field_4 = a3.field_4;
				a2.field_8 = v10;
				a2.field_C = v11;
				if (sub_427980((float4*)(arg4 + 12), &a2) ||
					(a2.field_0 = a3.field_0, a2.field_4 = a3.field_4, a2.field_8 = v12, a2.field_C = v13,
					 sub_427980((float4*)(arg4 + 12), &a2))) {
				LABEL_20:
					*(uint32_t*)arg4 = 0;
				}
			}
		} else {
			v2 = *((uint32_t*)a1 + 187);
			if (!((uint8_t)a1[3] & 4)) {
				v3 = 8 * *(uint32_t*)(v2 + 12);
				v4 = (double)*getMemIntPtr(0x587000, 196184 + v3) * 0.125;
				a3.field_4 = (double)*getMemIntPtr(0x587000, 196188 + v3) * 0.125;
				a2.field_0 = a1[14] - v4;
				a2.field_4 = a1[15] - a3.field_4;
				a2.field_8 = (double)*getMemIntPtr(0x587000, 196184 + 8 * *(uint32_t*)(v2 + 12)) + a2.field_0 + v4;
				a2.field_C =
					(double)*getMemIntPtr(0x587000, 196188 + 8 * *(uint32_t*)(v2 + 12)) + a2.field_4 + a3.field_4;
				if (sub_427980((float4*)(arg4 + 12), &a2)) {
					*(uint32_t*)arg4 = 0;
				}
			}
		}
	}
}

//----- (005374B0) --------------------------------------------------------
int nox_xxx_traceRay_5374B0(float4* a1) { return nox_xxx_mapTraceRay_535250(a1, 0, 0, 9); }

//----- (005374D0) --------------------------------------------------------
void sub_5374D0(nox_object_t* a1p) {
	uint32_t* a1 = a1p;
	int v1; // esi

	if (a1) {
		v1 = a1[187];
		if (v1) {
			if (*(uint32_t*)(v1 + 136)) {
				*(uint32_t*)(v1 + 132) = 0;
				sub_4FC300(a1, 3);
				nox_xxx_delayedDeleteObject_4E5CC0(*(uint32_t*)(v1 + 136));
				*(uint32_t*)(v1 + 136) = 0;
			}
		}
	}
}

//----- (00537520) --------------------------------------------------------
void nox_xxx_harpoonBreakForPlr_537520(nox_object_t* a1) {
	sub_5374D0(a1);
	nox_xxx_aud_501960(998, a1, 0, 0);
}

//----- (00537540) --------------------------------------------------------
void sub_537540(int a1) {
	uint32_t* i; // esi

	if (a1) {
		for (i = (uint32_t*)nox_xxx_getFirstPlayerUnit_4DA7C0(); i;
			 i = (uint32_t*)nox_xxx_getNextPlayerUnit_4DA7F0((int)i)) {
			if (*(uint32_t*)(i[187] + 132) == a1) {
				nox_xxx_harpoonBreakForPlr_537520(i);
			}
		}
	}
}

//----- (00537580) --------------------------------------------------------
int sub_537580(int a1) { return *(uint8_t*)(a1 + 464) & 1; }

//----- (00537590) --------------------------------------------------------
int sub_537590() { return dword_5d4594_2488604 == 0; }

//----- (005375A0) --------------------------------------------------------
void sub_5375A0(int a1) {
	int v1;  // eax
	int v2;  // ecx
	char v3; // al

	if (*(uint8_t*)(a1 + 464) & 1) {
		v1 = dword_5d4594_2488604;
		v2 = 0;
		if (dword_5d4594_2488604) {
			while (v1 != a1) {
				v2 = v1;
				v1 = *(uint32_t*)(v1 + 460);
				if (!v1) {
					return;
				}
			}
			if (v1) {
				if (v2) {
					*(uint32_t*)(v2 + 460) = *(uint32_t*)(a1 + 460);
				} else {
					dword_5d4594_2488604 = *(uint32_t*)(a1 + 460);
				}
				if (a1 == dword_5d4594_2488608) {
					dword_5d4594_2488608 = v2;
				}
				v3 = *(uint8_t*)(a1 + 464);
				*(uint32_t*)(a1 + 460) = -1;
				*(uint8_t*)(a1 + 464) = v3 & 0xFE;
			}
		}
	}
}

//----- (00537610) --------------------------------------------------------
char nox_xxx_unitHasCollideOrUpdateFn_537610(nox_object_t* a1p) {
	int a1 = a1p;
	int v1;               // eax
	int v2;               // edx
	int v3;               // edi
	void (*v4)(int, int); // ecx
	int v5;               // ecx

	v1 = *(uint32_t*)(a1 + 744);
	if (v1 || (v1 = *(uint32_t*)(a1 + 696)) != 0 && !(*(uint8_t*)(a1 + 16) & 0x40)) {
		if ((v2 = *(uint32_t*)(a1 + 8), !(v2 & 0x400000)) && !(*(uint8_t*)(a1 + 16) & 8) ||
			(v3 = nox_xxx_getNameId_4E3AA0("Spike"), v1 = nox_xxx_getNameId_4E3AA0("PeriodicSpike"),
			 v2 = *(uint32_t*)(a1 + 8), v2 & 0xE080) ||
			(v4 = *(void (**)(int, int))(a1 + 696), v4 == nox_xxx_collideFist_4EADF0) ||
			v4 == nox_xxx_collideUndeadKiller_4EBD40 || (v5 = *(unsigned short*)(a1 + 4), (unsigned short)v5 == v3) ||
			v5 == v1) {
			if (*(uint8_t*)(a1 + 16) & 4) {
				if (v2 & 0x2008) {
					sub_50B500();
				}
				nullsub_30(a1);
				LOBYTE(v1) = *(uint8_t*)(a1 + 464);
				if (!(v1 & 1)) {
					if (dword_5d4594_2488608) {
						*(uint32_t*)(dword_5d4594_2488608 + 460) = a1;
					} else {
						dword_5d4594_2488604 = a1;
					}
					dword_5d4594_2488608 = a1;
					LOBYTE(v1) = *(uint8_t*)(a1 + 464) | 1;
					*(uint32_t*)(a1 + 460) = 0;
					*(uint8_t*)(a1 + 464) = v1;
				}
			}
		}
	}
	return v1;
}
// 5485F0: using guessed type void  nullsub_30(uint32_t);

//----- (00537700) --------------------------------------------------------
int sub_537700() {
	int result;   // eax
	uint32_t* v1; // ecx

	result = dword_5d4594_2488604;
	v1 = (uint32_t*)(dword_5d4594_2488604 + 460);
	dword_5d4594_2488604 = *(uint32_t*)(dword_5d4594_2488604 + 460);
	if (!dword_5d4594_2488604) {
		dword_5d4594_2488608 = 0;
	}
	*v1 = -1;
	*(uint8_t*)(result + 464) &= 0xFEu;
	return result;
}

//----- (00537740) --------------------------------------------------------
int sub_537740() { return dword_5d4594_2488604; }

//----- (00537750) --------------------------------------------------------
int sub_537750(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		result = *(uint32_t*)(a1 + 460);
	}
	return result;
}

//----- (00537760) --------------------------------------------------------
unsigned int sub_537760() { return dword_5d4594_2488620 != 0 ? (unsigned int)getMemAt(0x5D4594, 2488612) : 0; }

//----- (00537770) --------------------------------------------------------
void sub_537770(nox_object_t* a1p) {
	int a1 = a1p;
	int v1;    // eax
	int v3;    // [esp+0h] [ebp-Ch]
	float2 v4; // [esp+4h] [ebp-8h]

	LOBYTE(v1) = getMemByte(0x5D4594, 2488624);
	if (!*getMemU32Ptr(0x5D4594, 2488624)) {
		*getMemU32Ptr(0x5D4594, 2488624) = nox_xxx_getNameId_4E3AA0("SmallFist");
		*getMemU32Ptr(0x5D4594, 2488628) = nox_xxx_getNameId_4E3AA0("MediumFist");
		v1 = nox_xxx_getNameId_4E3AA0("LargeFist");
		*getMemU32Ptr(0x5D4594, 2488632) = v1;
	}
	if (!(*(uint8_t*)(a1 + 16) & 0x60)) {
		dword_5d4594_2488620 = 0;
		LOBYTE(v1) = nox_xxx_projectileTraceHit_537850(a1, &v3, &v4);
		if ((uint8_t)v1) {
			if (!v3 || (v1 = *(unsigned short*)(v3 + 4), (unsigned short)v1 != *getMemU32Ptr(0x5D4594, 2488624)) &&
						   v1 != *getMemU32Ptr(0x5D4594, 2488628) && v1 != *getMemU32Ptr(0x5D4594, 2488632)) {
				(*(void (**)(int, int, float2*))(a1 + 696))(a1, v3, &v4);
				LOBYTE(v1) = v3;
				dword_5d4594_2488620 = 0;
				if (v3) {
					v4.field_0 = -v4.field_0;
					v4.field_4 = -v4.field_4;
					LOBYTE(v1) = (*(int (**)(int, int, float2*))(v3 + 696))(v3, a1, &v4);
				}
			}
		}
	}
}

//----- (00537850) --------------------------------------------------------
char nox_xxx_projectileTraceHit_537850(int a1, int* a2, float2* a3) {
	int v3;     // esi
	int v4;     // ebx
	double v5;  // st7
	double v6;  // st7
	int v7;     // edx
	float v8;   // eax
	int v9;     // eax
	float v10;  // eax
	float v11;  // ecx
	float v12;  // edx
	bool v13;   // al
	int v14;    // edx
	int v15;    // edi
	float v16;  // ecx
	double v17; // st7
	int v18;    // ebp
	double v19; // st7
	double v20; // st6
	double v21; // st7
	double v22; // st6
	double v23; // st5
	float v25;  // edx
	float v26;  // [esp+1Ch] [ebp-44h]
	float2 v27; // [esp+20h] [ebp-40h]
	float2 v28; // [esp+28h] [ebp-38h]
	int v29[2]; // [esp+30h] [ebp-30h]
	float2 a2a; // [esp+38h] [ebp-28h]
	float2 v31; // [esp+40h] [ebp-20h]
	int2 a3a;   // [esp+48h] [ebp-18h]
	float4 a1a; // [esp+50h] [ebp-10h]
	int v34;    // [esp+64h] [ebp+4h]
	int v35;    // [esp+64h] [ebp+4h]

	v3 = a1;
	v4 = 0;
	*(float*)&v34 = *(float*)(a1 + 64) - *(float*)(a1 + 56);
	v5 = *(float*)(v3 + 68) - *(float*)(v3 + 60);
	v26 = v5;
	v6 = v5 * v26 + *(float*)&v34 * *(float*)&v34;
	if (v6 <= 36.0) {
		v7 = *(uint32_t*)(v3 + 56);
		v8 = *(float*)(v3 + 64);
		v28.field_4 = *(float*)(v3 + 68);
		v29[0] = v7;
		v28.field_0 = v8;
		v29[1] = *(uint32_t*)(v3 + 60);
		v9 = sub_54E810(v3, &v28, (int)v29);
		if (!v9) {
			goto LABEL_4;
		}
		goto LABEL_3;
	}
	v15 = nox_double2int(sqrt(v6 * 0.027777778)) + 1;
	v16 = *(float*)(v3 + 60);
	v17 = (double)v15;
	v29[0] = *(uint32_t*)(v3 + 56);
	v18 = 0;
	*(float*)&v29[1] = v16;
	LODWORD(v28.field_0) = v29[0];
	v28.field_4 = v16;
	*(float*)&v35 = *(float*)&v34 / v17;
	v27.field_0 = v26 / v17;
	if (v15 > 0) {
		while (1) {
			v28.field_0 = v28.field_0 + *(float*)&v35;
			v28.field_4 = v28.field_4 + v27.field_0;
			v9 = sub_54E810(v3, &v28, (int)v29);
			if (v9) {
				break;
			}
			++v18;
			*(float2*)v29 = v28;
			if (v18 >= v15) {
				goto LABEL_4;
			}
		}
	LABEL_3:
		v4 = v9;
		v27.field_0 = *(float*)v29 - *(float*)(v9 + 56);
		v27.field_4 = *(float*)&v29[1] - *(float*)(v9 + 60);
	}
LABEL_4:
	v10 = *(float*)(v3 + 60);
	v11 = *(float*)(v3 + 64);
	a1a.field_0 = *(float*)(v3 + 56);
	v12 = *(float*)(v3 + 68);
	a1a.field_4 = v10;
	a1a.field_8 = v11;
	a1a.field_C = v12;
	if (nox_xxx_mapTraceRay_535250(&a1a, &a2a, &a3a, 5)) {
		v13 = 0;
	} else {
		*(int2*)getMemAt(0x5D4594, 2488612) = a3a;
		*(float2*)&a1a.field_8 = a2a;
		dword_5d4594_2488620 = 1;
		v13 = sub_57CDB0(&a3a, &a1a.field_0, &v31) != 0;
		v14 = *(uint32_t*)(v3 + 60);
		*(uint32_t*)(v3 + 64) = *(uint32_t*)(v3 + 56);
		*(uint32_t*)(v3 + 68) = v14;
	}
	if (v4) {
		if (!v13) {
			*a3 = v27;
			*a2 = v4;
			return 1;
		}
		v19 = *(float*)(v3 + 56) - *(float*)(v4 + 56);
		v20 = *(float*)(v3 + 60) - *(float*)(v4 + 60);
		v21 = v20 * v20 + v19 * v19;
		v22 = *(float*)(v3 + 56) - a2a.field_0;
		v23 = *(float*)(v3 + 60) - a2a.field_4;
		if (v21 < v23 * v23 + v22 * v22) {
			*a3 = v27;
			*a2 = v4;
			return 1;
		}
		goto LABEL_17;
	}
	if (v13) {
	LABEL_17:
		v25 = v31.field_4;
		a3->field_0 = v31.field_0;
		a3->field_4 = v25;
		*a2 = 0;
		return 1;
	}
	return 0;
}
// 537A87: variable 'v24' is possibly undefined

//----- (00537AF0) --------------------------------------------------------
uint32_t* nox_xxx_sMakeScorch_537AF0(int* a1, int a2) {
	uint32_t* result; // eax
	uint32_t* v3;     // esi
	int v4;           // eax
	int v5;           // [esp-18h] [ebp-18h]
	int v6;           // [esp-18h] [ebp-18h]
	int v7;           // [esp-18h] [ebp-18h]

	if (!*getMemU32Ptr(0x5D4594, 2488636)) {
		nox_xxx_scorchInit_537BD0();
	}
	if (a2) {
		if (a2 == 1) {
			v6 = *getMemU32Ptr(0x587000, 276836 + 8 * nox_common_randomInt_415FA0(0, 0));
			result = nox_xxx_newObjectWithTypeInd_4E3450(v6);
		} else {
			result = (uint32_t*)(a2 - 2);
			if (a2 != 2) {
				return result;
			}
			v5 = *getMemU32Ptr(0x587000, 276844 + 8 * nox_common_randomInt_415FA0(0, 0));
			result = nox_xxx_newObjectWithTypeInd_4E3450(v5);
		}
	} else {
		v7 = *getMemU32Ptr(0x587000, 276828 + 8 * nox_common_randomInt_415FA0(0, 0));
		result = nox_xxx_newObjectWithTypeInd_4E3450(v7);
	}
	v3 = result;
	if (result) {
		nox_xxx_createAt_4DAA50((int)result, 0, *(float*)a1, *((float*)a1 + 1));
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			v4 = nox_common_randomInt_415FA0(5, 8);
		} else {
			v4 = nox_common_randomInt_415FA0(10, 20);
		}
		result = (uint32_t*)nox_xxx_unitSetDecayTime_511660(v3, nox_gameFPS * v4);
	}
	return result;
}

//----- (00537BD0) --------------------------------------------------------
int nox_xxx_scorchInit_537BD0() {
	int result; // eax

	*getMemU32Ptr(0x587000, 276828) = nox_xxx_getNameId_4E3AA0(*(char**)getMemAt(0x587000, 276824));
	*getMemU32Ptr(0x587000, 276836) = nox_xxx_getNameId_4E3AA0(*(char**)getMemAt(0x587000, 276832));
	result = nox_xxx_getNameId_4E3AA0(*(char**)getMemAt(0x587000, 276840));
	*getMemU32Ptr(0x587000, 276844) = result;
	*getMemU32Ptr(0x5D4594, 2488636) = 1;
	return result;
}

//----- (00537C10) --------------------------------------------------------
char nox_xxx_trapBAH_537C10(int a1, int a2) {
	float2* v2;  // ebp
	char result; // al
	int v4;      // edi
	int v5;      // esi
	int v6;      // ecx
	char v7;     // al
	int* v8;     // ebx
	int v9;      // eax
	float v10;   // [esp+0h] [ebp-54h]
	int v11;     // [esp+18h] [ebp-3Ch]
	float4 a1a;  // [esp+1Ch] [ebp-38h]
	int v13[10]; // [esp+2Ch] [ebp-28h]
	int a3;      // [esp+58h] [ebp+4h]

	v2 = (float2*)a1;
	result = *(uint8_t*)(a1 + 16);
	v4 = *(uint32_t*)(a1 + 692);
	v11 = *(uint32_t*)(a1 + 692);
	if (!(result & 0x20)) {
		v5 = nox_xxx_findParentChainPlayer_4EC580(a1);
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
		if (v5) {
			if (*(uint8_t*)(v5 + 8) & 4) {
				v6 = *(uint32_t*)(v5 + 748);
				if (*(uint8_t*)(*(uint32_t*)(v6 + 276) + 2251) == 1) {
					v7 = *(uint8_t*)(v6 + 244);
					if (v7) {
						*(uint8_t*)(v6 + 244) = v7 - 1;
					}
				}
			}
		}
		if (a2) {
			v8 = (int*)(v4 + 24);
			*(uint32_t*)(v4 + 24) = a2;
		} else {
			v13[0] = 15;
			v13[1] = 1;
			v13[2] = 0;
			v13[3] = 6;
			v13[4] = 0;
			v13[5] = -1;
			v13[6] = 0;
			v13[7] = -1;
			v13[8] = 0x8000;
			v8 = (int*)(v4 + 24);
			v10 = nox_xxx_gamedataGetFloat_419D40("GlyphRange");
			*(uint32_t*)(v4 + 24) = sub_4E6EA0(a1, v10, (int)v13);
		}
		a3 = 0;
		if (*(uint8_t*)(v4 + 20)) {
			do {
				if ((!nox_xxx_spellHasFlags_424A50(*(uint32_t*)v4, 1) || a2) && !sub_4FD0E0(v5, *(uint32_t*)v4)) {
					if (*(uint8_t*)(v5 + 8) & 4) {
						v9 = nox_xxx_spellGetPower_4FE7B0(*(uint32_t*)v4, v5);
						nox_xxx_spellAccept_4FD400(*(uint32_t*)v4, v5, (uint32_t*)v5, (int)v2, v8, v9);
					} else {
						nox_xxx_spellAccept_4FD400(*(uint32_t*)v4, v5, (uint32_t*)v5, (int)v2, v8, 2);
					}
				}
				v4 += 4;
				++a3;
			} while (a3 < *(unsigned char*)(v11 + 20));
		}
		nox_xxx_netSendPointFx_522FF0(129, v2 + 7);
		nox_xxx_audCreate_501A30(40, v2 + 7, 0, 0);
		a1a.field_0 = v2[7].field_0 - 100.0;
		a1a.field_4 = v2[7].field_4 - 100.0;
		a1a.field_8 = v2[7].field_0 + 100.0;
		a1a.field_C = v2[7].field_4 + 100.0;
		nox_xxx_getUnitsInRect_517C10(&a1a, sub_537DD0, (int)v2);
	}
	return result;
}

//----- (00537DD0) --------------------------------------------------------
void sub_537DD0(float* a1, int a2) {
	int v2;    // eax
	float v3;  // edx
	float v4;  // ecx
	float v5;  // edx
	float4 v6; // [esp+8h] [ebp-10h]

	if (a1 != (float*)a2 && !((uint8_t)a1[4] & 0x20)) {
		v2 = dword_5d4594_2488640;
		if (!dword_5d4594_2488640) {
			v2 = nox_xxx_getNameId_4E3AA0("Glyph");
			dword_5d4594_2488640 = v2;
		}
		if (*((unsigned short*)a1 + 2) == v2) {
			v3 = *(float*)(a2 + 56);
			v4 = a1[14];
			v6.field_4 = *(float*)(a2 + 60);
			v6.field_0 = v3;
			v5 = a1[15];
			v6.field_8 = v4;
			v6.field_C = v5;
			if (nox_xxx_mapTraceRay_535250(&v6, 0, 0, 5) == 1) {
				*((uint32_t*)a1 + 186) = nox_xxx___mkgmtime_538280;
				nox_xxx_unitAddToUpdatable_4DA8D0((int)a1);
			}
		}
	}
}

//----- (00537E60) --------------------------------------------------------
int sub_537E60(int a1, int a2, int a3, int a4) {
	int v4;     // eax
	float4 a1a; // [esp+4h] [ebp-10h]

	a1a.field_0 = *(float*)(a4 + 56) - 300.0;
	a1a.field_4 = *(float*)(a4 + 60) - 300.0;
	a1a.field_8 = *(float*)(a4 + 56) + 300.0;
	a1a.field_C = *(float*)(a4 + 60) + 300.0;
	v4 = nox_xxx_spellGetAud44_424800(a1, 0);
	nox_xxx_aud_501960(v4, a3, 0, 0);
	while (1) {
		dword_5d4594_2488644 = 0;
		nox_xxx_getUnitsInRect_517C10(&a1a, sub_537F00, a4);
		if (!dword_5d4594_2488644) {
			break;
		}
		nox_xxx_trapBAH_537C10(*(int*)&dword_5d4594_2488644, 0);
	}
	return 1;
}

//----- (00537F00) --------------------------------------------------------
void sub_537F00(float* a1, int a2) {
	int v2;    // eax
	int v3;    // ebx
	float v4;  // edx
	float v5;  // ecx
	float v6;  // edx
	float4 v7; // [esp+0h] [ebp-10h]

	v2 = dword_5d4594_2488640;
	if (!dword_5d4594_2488640) {
		v2 = nox_xxx_getNameId_4E3AA0("Glyph");
		dword_5d4594_2488640 = v2;
	}
	if (*((unsigned short*)a1 + 2) == v2 && !((uint8_t)((uint32_t*)a1)[4] & 0x20)) {
		v3 = nox_xxx_findParentChainPlayer_4EC580(a2);
		if (nox_xxx_unitHasThatParent_4EC4F0((int)a1, v3) || !*((uint32_t*)a1 + 127) && !(*(uint8_t*)(v3 + 8) & 4)) {
			v4 = *(float*)(a2 + 56);
			v5 = a1[14];
			v7.field_4 = *(float*)(a2 + 60);
			v7.field_0 = v4;
			v6 = a1[15];
			v7.field_8 = v5;
			v7.field_C = v6;
			if (nox_xxx_mapTraceRay_535250(&v7, 0, 0, 5) == 1) {
				dword_5d4594_2488644 = a1;
			}
		}
	}
}

//----- (00537FA0) --------------------------------------------------------
int nox_xxx_castGlyph_537FA0(int a1, int a2, int a3, int a4, int a5) {
	int v5;        // edi
	int v6;        // esi
	uint32_t* v8;  // eax
	int v9;        // ebx
	int v10;       // ebp
	int v11;       // ecx
	uint8_t v12;   // eax
	int v13;       // ebx
	uint32_t* v14; // eax
	int* v15;      // edi
	int v16;       // edx
	int v17;       // edx
	int v18;       // eax
	int v19;       // [esp-Ch] [ebp-2Ch]
	float v20;     // [esp+0h] [ebp-20h]
	int v21;       // [esp+14h] [ebp-Ch]
	float2 v22;    // [esp+18h] [ebp-8h]
	float v23;     // [esp+24h] [ebp+4h]
	int* v24;      // [esp+24h] [ebp+4h]

	v5 = a3;
	if (*(uint8_t*)(a3 + 8) & 4) {
		v6 = *(uint32_t*)(a3 + 748);
		v20 = nox_xxx_gamedataGetFloat_419D40("MaxTrapCount");
		if (*(unsigned char*)(v6 + 244) >= nox_float2int(v20)) {
			a3 = 5;
		LABEL_6:
			nox_xxx_netInformTextMsg_4DA0F0(*(unsigned char*)(*(uint32_t*)(v6 + 276) + 2064), 0, &a3);
			return 0;
		}
		if (!*(uint8_t*)(v6 + 212)) {
			a3 = 7;
			goto LABEL_6;
		}
		v8 = nox_xxx_newObjectByTypeID_4E3810("Glyph");
		v9 = (int)v8;
		v21 = (int)v8;
		if (v8) {
			v10 = v8[173];
			if (*(uint8_t*)(*(uint32_t*)(v6 + 276) + 2251) != 2) {
				v13 = a4;
				nox_xxx_createAt_4DAA50((int)v8, v5, *(float*)(a4 + 56), *(float*)(a4 + 60));
				v19 = nox_xxx_spellGetAud44_424800(a1, 0);
				nox_xxx_aud_501960(v19, v13, 0, 0);
			LABEL_23:
				a4 = 0;
				v22.field_0 = 0.0;
				if (*(uint8_t*)(v6 + 212)) {
					v24 = (int*)v10;
					v15 = (int*)(v6 + 192);
					do {
						if (nox_xxx_spellIsEnabled_424B70(*v15)) {
							v16 = a4;
							*v24 = *v15;
							a4 = v16 + 1;
							++v24;
						}
						v17 = *(unsigned char*)(v6 + 212);
						++v15;
						++LODWORD(v22.field_0);
					} while (SLODWORD(v22.field_0) < v17);
				}
				*(uint8_t*)(v10 + 20) = a4;
				v18 = a5;
				*(uint32_t*)(v10 + 28) = *(uint32_t*)(a5 + 4);
				*(uint32_t*)(v10 + 32) = *(uint32_t*)(v18 + 8);
				*(uint32_t*)(v10 + 24) = 0;
				*(uint8_t*)(v6 + 212) = 0;
				*(uint16_t*)(v21 + 126) = *(uint16_t*)(v13 + 124);
				*(uint16_t*)(v21 + 124) = *(uint16_t*)(v13 + 124);
				if (*(uint8_t*)(*(uint32_t*)(v6 + 276) + 2251) == 1) {
					++*(uint8_t*)(v6 + 244);
				}
				return 1;
			}
			v23 = (double)sub_538250(v5);
			if (nox_xxx_gamedataGetFloat_419D40("MaxBomberCount") <= v23) {
				v11 = *(uint32_t*)(v6 + 276);
				a4 = 5;
				nox_xxx_netInformTextMsg_4DA0F0(*(unsigned char*)(v11 + 2064), 0, &a4);
				nox_xxx_delayedDeleteObject_4E5CC0(v9);
				return 0;
			}
			v12 = nox_xxx_checkSummonedCreaturesLimit_500D70(v5, 5);
			if (v12) {
				if (!dword_5d4594_2488648) {
					dword_5d4594_2488648 = nox_xxx_getNameId_4E3AA0("Bomber");
				}
				v13 = a4;
				sub_4ED970(50.0, (float2*)(a4 + 56), &v22);
				if (v5) {
					v14 = nox_xxx_unitDoSummonAt_5016C0(*(int*)&dword_5d4594_2488648, (int*)&v22, v5,
														*(uint8_t*)(v5 + 124));
				} else {
					v14 = nox_xxx_unitDoSummonAt_5016C0(*(int*)&dword_5d4594_2488648, (int*)&v22, 0, 0);
				}
				if (v14) {
					nox_xxx_inventoryPutImpl_4F3070((int)v14, v21, 1);
				}
				nox_xxx_aud_501960(367, v13, 0, 0);
				goto LABEL_23;
			}
			nox_xxx_delayedDeleteObject_4E5CC0(v9);
		}
		return 0;
	}
	return 1;
}
// 5380C1: variable 'v12' is possibly undefined

//----- (00538250) --------------------------------------------------------
int sub_538250(int a1) {
	int result; // eax
	int i;      // ecx

	result = 0;
	for (i = *(uint32_t*)(a1 + 516); i; i = *(uint32_t*)(i + 512)) {
		if (*(uint8_t*)(i + 8) & 2) {
			if (*(uint32_t*)(i + 12) & 0x2000) {
				++result;
			}
		}
	}
	return result;
}

//----- (00538280) --------------------------------------------------------
char nox_xxx___mkgmtime_538280(int a1) { return nox_xxx_trapBAH_537C10(a1, 0); }

//----- (00538290) --------------------------------------------------------
int nox_xxx_playerPreAttackEffects_538290(int a1, int a2, int a3, int a4) {
	int result;                          // eax
	int v5;                              // esi
	int v6;                              // ebp
	int* v7;                             // esi
	int v8;                              // eax
	void (*v9)(int, int, int, int, int); // ecx
	int v10;                             // [esp+10h] [ebp+4h]

	result = a3;
	if (a3) {
		v5 = *(uint32_t*)(a3 + 692);
		v6 = a1;
		if (nox_xxx_CheckGameplayFlags_417DA0(1) || !a2 || !(*(uint8_t*)(a2 + 8) & 6) ||
			(result = nox_xxx_unitIsEnemyTo_5330C0(a2, a1)) != 0) {
			result = nox_xxx_testUnitBuffs_4FF350(a1, 23);
			if (!result) {
				result = nox_xxx_testUnitBuffs_4FF350(a1, 27);
				if (!result) {
					v7 = (int*)(v5 + 8);
					v10 = 2;
					do {
						v8 = *v7;
						if (*v7) {
							v9 = *(void (**)(int, int, int, int, int))(v8 + 52);
							if (v9) {
								v9(v8, a3, a2, v6, a4);
							}
						}
						++v7;
						result = --v10;
					} while (v10);
				}
			}
		}
	}
	return result;
}

//----- (00538330) --------------------------------------------------------
int nox_xxx_playerTraceAttack_538330(int a1, int a2) {
	int v2;    // ebp
	int v3;    // eax
	int v4;    // ecx
	int v5;    // eax
	int v6;    // eax
	int v8;    // eax
	int v9;    // eax
	int v12;   // eax
	float a3;  // [esp+0h] [ebp-34h]
	float v15; // [esp+Ch] [ebp-28h]
	float v16; // [esp+Ch] [ebp-28h]
	float v17; // [esp+Ch] [ebp-28h]
	float v18; // [esp+Ch] [ebp-28h]
	float v19; // [esp+Ch] [ebp-28h]
	int v20;   // [esp+10h] [ebp-24h]
	int v21;   // [esp+20h] [ebp-14h]
	int4 a1a;  // [esp+24h] [ebp-10h]
	float v23; // [esp+38h] [ebp+4h]

	v2 = a1;
	v21 = 0;
	if (!a1 || !a2) {
		return 0;
	}
	dword_5d4594_2488656 = 0;
	dword_5d4594_2488660 = 0;
	v3 = *(uint32_t*)(a2 + 28);
	if (v3 && (v4 = *(uint32_t*)(v3 + 12), BYTE1(v4) & 0x40)) {
		sub_518040(a2 + 16, *(float*)(a2 + 8), sub_538510, a2);
		v21 = 25;
	} else {
		dword_5d4594_2488660 = 0;
		dword_5d4594_2488652 = *(uint32_t*)(a2 + 8);
		sub_518040(a1 + 56, *(float*)(a2 + 8), sub_5386A0, a1);
		if (dword_5d4594_2488660) {
			sub_538510(*(int*)&dword_5d4594_2488660, a2);
		}
	}
	v23 = (double)v21;
	v15 = *(float*)(a2 + 16) - *(float*)(a2 + 8) - v23;
	v5 = nox_float2int(v15);
	v16 = *(float*)(a2 + 20) - *(float*)(a2 + 8) - v23;
	a1a.field_0 = v5 / 23;
	v6 = nox_float2int(v16);
	v17 = *(float*)(a2 + 8) + *(float*)(a2 + 16) + v23;
	a1a.field_4 = v6 / 23;
	v8 = nox_float2int(v17);
	v18 = *(float*)(a2 + 20) + *(float*)(a2 + 8) + v23;
	a1a.field_8 = v8 / 23;
	v9 = nox_float2int(v18);
	v12 = *(uint32_t*)(a2 + 28);
	a1a.field_C = v9 / 23;
	if (!v12) {
		v12 = v2;
	}
	a3 = v23 + *(float*)(a2 + 8);
	nox_xxx_mapDamageToWalls_534FC0(&a1a, a2 + 16, a3, (long long)(*(float*)a2 + 0.5), *(unsigned char*)(a2 + 4), v12);
	if (*(uint32_t*)(a2 + 28)) {
		if (dword_5d4594_2488656) {
			v20 = *(unsigned char*)(a2 + 4);
			v19 = nox_xxx_gamedataGetFloat_419D40("ItemDamagePercentage") * *(float*)a2;
			nox_xxx_playerDamageWeapon_4E1560(*(uint32_t*)(a2 + 28), *(uint32_t*)(a2 + 12),
											  *(int*)&dword_5d4594_2488660, *(int*)&dword_5d4594_2488660, v19, v20);
		}
	}
	return dword_5d4594_2488656;
}

//----- (00538510) --------------------------------------------------------
void sub_538510(int a1, int a2) {
	int v2;     // eax
	int v3;     // eax
	int v4;     // eax
	float v5;   // ecx
	float v6;   // edx
	float v7;   // eax
	int v8;     // eax
	int v9;     // eax
	int v10;    // esi
	char v11;   // al
	float4 v12; // [esp+Ch] [ebp-10h]

	if (a1) {
		if (a2) {
			v2 = *(uint32_t*)(a2 + 12);
			if (v2) {
				if (a1 != v2) {
					if ((unsigned char)nox_server_testTwoPointsAndDirection_4E6E50(
							(float2*)(v2 + 56), *(short*)(v2 + 124), (float2*)(a1 + 56)) &
						*(uint8_t*)(a2 + 32)) {
						v3 = *(uint32_t*)(a1 + 16);
						if (!(v3 & 0x8040) && (*(uint32_t*)(a2 + 24) || !(v3 & 8))) {
							if (*(uint16_t*)(a1 + 24) != 0x4000) {
								dword_5d4594_2488656 = 1;
							}
							v4 = *(uint32_t*)(a2 + 12);
							v12.field_0 = *(float*)(v4 + 56);
							v5 = *(float*)(a1 + 60);
							v6 = *(float*)(v4 + 60);
							v7 = *(float*)(a1 + 56);
							v12.field_4 = v6;
							v12.field_8 = v7;
							v12.field_C = v5;
							if (nox_xxx_mapTraceRay_535250(&v12, 0, 0, 5)) {
								nox_xxx_playerPreAttackEffects_538290(a1, *(uint32_t*)(a2 + 12), *(uint32_t*)(a2 + 28),
																	  a2);
								(*(void (**)(int, uint32_t, uint32_t, uint32_t, uint32_t))(a1 + 716))(
									a1, *(uint32_t*)(a2 + 12), *(uint32_t*)(a2 + 28), (long long)(*(float*)a2 + 0.5),
									*(unsigned char*)(a2 + 4));
								if (nox_common_gameFlags_check_40A5C0(2048)) {
									if (*(uint8_t*)(*(uint32_t*)(a2 + 12) + 8) & 4) {
										if (!(*(uint8_t*)(a1 + 8) & 2)) {
											v8 = *(uint32_t*)(a1 + 556);
											if (v8) {
												if (*(uint16_t*)(v8 + 4)) {
													v9 = *(uint32_t*)(a1 + 16);
													if ((v9 & 0x8000) == 0 && !(v9 & 0x20)) {
														nox_xxx_netSendPointFx_522FF0(139, (float2*)(a1 + 56));
													}
												}
											}
										}
									}
								}
								if (!*(uint32_t*)(a2 + 28)) {
									v10 = *(uint32_t*)(a2 + 12);
									if (*(uint8_t*)(v10 + 8) & 4) {
										v11 = *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(v10 + 748) + 276) + 8);
									} else {
										v11 = *(uint8_t*)(*(uint32_t*)(v10 + 748) + 2068);
									}
									if (v11 == 25) {
										nox_xxx_objectApplyForce_52DF80(v10 + 56, a1, 20.0);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

//----- (005386A0) --------------------------------------------------------
void sub_5386A0(int a3, int a2) {
	int v2;    // eax
	int v3;    // eax
	double v4; // st7
	double v5; // st7
	float* v6; // eax
	double v7; // st7
	float2 a4; // [esp+8h] [ebp-8h]

	if (a2 != a3) {
		if (a2) {
			if (a3) {
				v2 = *(uint32_t*)(a3 + 16);
				if (!(v2 & 0x8049) && (*(uint8_t*)(a3 + 8) & 6 || !(v2 & 0x10) || (v2 & 0x80u) != 0) &&
					(nox_xxx_unitIsEnemyTo_5330C0(a2, a3) || !(*(uint8_t*)(a3 + 8) & 6))) {
					v3 = *(uint32_t*)(a3 + 16);
					if ((v3 & 0x8000) == 0) {
						if (nox_xxx_unitCanInteractWith_5370E0(a2, a3, 1)) {
							if (*(float*)&dword_5d4594_2488652 > 0.0) {
								a4.field_0 = *(float*)(a3 + 56) - *(float*)(a2 + 56);
								v4 = *(float*)(a3 + 60) - *(float*)(a2 + 60);
								a4.field_4 = v4;
								v5 = sqrt(v4 * a4.field_4 + a4.field_0 * a4.field_0);
								if (v5 != 0.0) {
									v6 = getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a2 + 124));
									if (a4.field_4 / v5 * v6[1] + a4.field_0 / v5 * *v6 > 0.5) {
										if (*(uint32_t*)(a3 + 172) == 2) {
											v5 = v5 - *(float*)(a3 + 176);
										} else if (*(uint32_t*)(a3 + 172) == 3) {
											v7 =
												sub_54A990((float2*)(a2 + 56), *(float*)&dword_5d4594_2488652, a3, &a4);
											if (v7 < 0.0) {
												return;
											}
											v5 = *(float*)&dword_5d4594_2488652 - v7;
										}
										if (v5 < 0.0) {
											v5 = 0.0;
										}
										if ((v5 < *(float*)&dword_5d4594_2488652 ||
											 dword_5d4594_2488660 && !(*(uint8_t*)(dword_5d4594_2488660 + 8) & 2) &&
												 (*(uint8_t*)(a3 + 8) & 2) == 2) &&
											(!dword_5d4594_2488660 || !(*(uint8_t*)(dword_5d4594_2488660 + 8) & 2))) {
											*(float*)&dword_5d4594_2488652 = v5;
											dword_5d4594_2488660 = a3;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

//----- (00538840) --------------------------------------------------------
int nox_xxx_itemApplyAttackEffect_538840(int a1, int a2, int a3) {
	int v3;                                   // edi
	int* v4;                                  // esi
	int v5;                                   // eax
	void (*v6)(int, int, int, uint32_t, int); // ecx
	int result;                               // eax
	int v8;                                   // [esp+14h] [ebp+4h]

	v3 = a1;
	v8 = 4;
	v4 = *(int**)(v3 + 692);
	do {
		v5 = *v4;
		if (*v4) {
			v6 = *(void (**)(int, int, int, uint32_t, int))(v5 + 40);
			if (v6) {
				v6(v5, v3, a2, 0, a3);
			}
		}
		++v4;
		result = --v8;
	} while (v8);
	return result;
}

//----- (00538890) --------------------------------------------------------
int nox_xxx_createHarpoonBolt_538890(int a1) {
	uint32_t* v1; // eax
	int v2;       // edi
	int v3;       // ebx
	double v4;    // st7
	int v5;       // eax
	int result;   // eax
	short v7;     // si
	float v8;     // [esp+0h] [ebp-18h]
	float v9;     // [esp+4h] [ebp-14h]

	if (!a1) {
		return 0;
	}
	v1 = nox_xxx_newObjectByTypeID_4E3810("HarpoonBolt");
	v2 = (int)v1;
	if (!v1) {
		return 0;
	}
	v3 = *(uint32_t*)(a1 + 748);
	v4 = *(float*)(a1 + 176) + 1.0;
	*(uint32_t*)(v1[175] + 4) = a1;
	v5 = 8 * *(short*)(a1 + 124);
	v9 = v4 * *getMemFloatPtr(0x587000, 194140 + v5) + *(float*)(a1 + 60);
	v8 = v4 * *getMemFloatPtr(0x587000, 194136 + v5) + *(float*)(a1 + 56);
	nox_xxx_createAt_4DAA50(v2, a1, v8, v9);
	result = 1;
	*(float*)(v2 + 80) = *getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a1 + 124)) * *(float*)(v2 + 544);
	*(float*)(v2 + 84) = *getMemFloatPtr(0x587000, 194140 + 8 * *(short*)(a1 + 124)) * *(float*)(v2 + 544);
	v7 = *(uint16_t*)(a1 + 124);
	*(uint16_t*)(v2 + 124) = v7;
	*(uint16_t*)(v2 + 126) = v7;
	*(uint32_t*)(v3 + 136) = v2;
	*(uint32_t*)(v3 + 140) = 0;
	return result;
}

//----- (00538960) --------------------------------------------------------
int nox_xxx_playerAttack_538960(int a1) {
	float* v1;         // edi
	int v2;            // eax
	int v3;            // eax
	int v4;            // ebp
	int v5;            // ebx
	char v6;           // dl
	float v7;          // edx
	float v8;          // eax
	char v9;           // al
	double v10;        // st7
	int v11;           // eax
	int v12;           // edx
	double v13;        // st7
	short v14;         // ax
	int v15;           // ecx
	int v16;           // edx
	double v17;        // st7
	int v18;           // eax
	int v19;           // eax
	char v20;          // cl
	int v21;           // ecx
	double v22;        // st7
	double v23;        // st7
	int v24;           // edi
	int v25;           // ebx
	int v26;           // edx
	double v27;        // st7
	double v28;        // st7
	double v29;        // st7
	int v30;           // eax
	float v31;         // edx
	double v32;        // st6
	uint32_t* v33;     // eax
	int v34;           // edi
	int v35;           // ebx
	short v36;         // ax
	double v37;        // st7
	int v38;           // eax
	float v39;         // edx
	char* v40;         // ebx
	double v41;        // st6
	uint32_t* v42;     // eax
	int v43;           // edi
	short v44;         // ax
	char v45;          // al
	int v46;           // edx
	double v47;        // st7
	double v48;        // st7
	int v49;           // edx
	double v50;        // st7
	double v51;        // st7
	int v52;           // edx
	double v53;        // st7
	double v54;        // st7
	int v55;           // eax
	int v56;           // eax
	int v57;           // edx
	double v58;        // st7
	double v59;        // st7
	int v60;           // edx
	double v61;        // st7
	double v62;        // st7
	uint32_t* v63;     // edi
	int v64;           // eax
	char v65;          // bl
	unsigned char v66; // bl
	uint32_t* v67;     // edi
	int v68;           // eax
	bool v69;          // cc
	int v70;           // eax
	int v71;           // ecx
	unsigned char v72; // al
	int v73;           // ecx
	float v75;         // [esp+0h] [ebp-C0h]
	short v76 = 0;     // [esp+17h] [ebp-A9h]
	int v77 = 0;       // [esp+1Ch] [ebp-A4h]
	int v78;           // [esp+20h] [ebp-A0h]
	int v79;           // [esp+24h] [ebp-9Ch]
	int v80;           // [esp+28h] [ebp-98h]
	int v81;           // [esp+2Ch] [ebp-94h]
	char v82[36];      // [esp+30h] [ebp-90h]
	float4 v83;
	int v86;      // [esp+64h] [ebp-5Ch]
	char v87[88]; // [esp+68h] [ebp-58h]

	v1 = 0;
	v2 = *(uint32_t*)(a1 + 8);
	if (v2 & 4) {
		v79 = *(uint32_t*)(a1 + 748);
		v3 = *(uint32_t*)(v79 + 276);
		v4 = *(uint32_t*)(v79 + 104);
		v5 = *(uint32_t*)(v3 + 4);
		v6 = *(uint8_t*)(v3 + 8);
		LOBYTE(v76) = *(uint8_t*)(v79 + 236);
	} else {
		if (!(v2 & 2) || !(*(uint8_t*)(a1 + 12) & 0x10)) {
			return 0;
		}
		v79 = *(uint32_t*)(a1 + 748);
		v5 = *(uint32_t*)(v79 + 2056);
		v4 = *(uint32_t*)(v79 + 2064);
		v6 = *(uint8_t*)(v79 + 2068);
		LOBYTE(v76) = *(uint8_t*)(v79 + 481);
	}
	LOBYTE(v80) = v6;
	if (v4) {
		v1 = (float*)nox_xxx_getProjectileClassById_413250(*(unsigned short*)(v4 + 4));
		if (!v1) {
			return 0;
		}
		*(uint32_t*)(v4 + 56) = *(uint32_t*)(a1 + 56);
		*(uint32_t*)(v4 + 60) = *(uint32_t*)(a1 + 60);
		*(uint32_t*)(v4 + 72) = *(uint32_t*)(a1 + 56);
		*(uint32_t*)(v4 + 76) = *(uint32_t*)(a1 + 60);
	} else if (!v6) {
		LOBYTE(v80) = nox_common_randomInt_415FA0(23, 24);
		if (!(*(uint8_t*)(a1 + 8) & 4)) {
			goto LABEL_171;
		}
		if (!*(uint8_t*)(*(uint32_t*)(v79 + 276) + 2251) && nox_common_randomInt_415FA0(0, 100) >= 75) {
			LOBYTE(v80) = 25;
		}
		if (*(uint8_t*)(a1 + 8) & 4) {
			*(uint8_t*)(*(uint32_t*)(v79 + 276) + 8) = v80;
		} else {
		LABEL_171:
			*(uint8_t*)(v79 + 2068) = v80;
		}
	}
	*(uint32_t*)&v82[28] = v4;
	v81 = nox_xxx_unitGetStrength_4F9FD0(a1);
	if (nox_common_playerIsAbilityActive_4FC250(a1, 2) && nox_xxx_probablyWarcryCheck_4FC3E0(a1, 2)) {
		nox_xxx_animPlayerGetFrameRange_4F9F90(46, &v77, &v78);
		HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
		if (v76 == 770) {
			v7 = *(float*)(a1 + 56);
			v8 = *(float*)(a1 + 60);
			LODWORD(v83.field_0) = a1;
			v83.field_4 = v7;
			v83.field_8 = v8;
			nox_xxx_earthquakeSend_4D9110((float*)(a1 + 56), 15);
			nox_xxx_unitsGetInCircle_517F90((float2*)(a1 + 56), 300.0, nox_xxx_warcryStunMonsters_539B90, a1);
			nox_xxx_castCounterSpell_52BBB0(13, a1, a1, a1);
		}
		if (HIBYTE(v76) >= v77) {
			sub_4FC440(a1, 2);
		}
		goto LABEL_159;
	}
	if (nox_common_playerIsAbilityActive_4FC250(a1, 1)) {
		if (!nox_xxx_testUnitBuffs_4FF350(a1, 25) && !nox_xxx_testUnitBuffs_4FF350(a1, 5)) {
			nox_xxx_animPlayerGetFrameRange_4F9F90(45, &v77, &v78);
			v9 = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
			v10 = *(float*)(a1 + 548) * 6.0;
			*(float*)(a1 + 544) = v10;
			HIBYTE(v76) = v9;
			v11 = 8 * *(short*)(a1 + 124);
			v12 = v77 - 1;
			*(float*)(a1 + 88) = v10 * *getMemFloatPtr(0x587000, 194136 + v11) + *(float*)(a1 + 88);
			*(float*)(a1 + 92) = v10 * *getMemFloatPtr(0x587000, 194140 + v11) + *(float*)(a1 + 92);
			if (HIBYTE(v76) >= v12) {
				HIBYTE(v76) = 0;
			}
			goto LABEL_159;
		}
		return 0;
	}
	if (!v4) {
		nox_xxx_animPlayerGetFrameRange_4F9F90((unsigned char)v80, &v77, &v78);
		if (*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)v79) {
			*(uint32_t*)v79 = nox_frame_xxx_2598000 + v77 * (v78 + 1);
		}
		HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
		if (HIBYTE(v76) < v77) {
			goto LABEL_159;
		}
		if ((unsigned char)v80 >= 0x17u) {
			if ((unsigned char)v80 <= 0x18u) {
				v13 = 0.039999999;
				v14 = 5;
				goto LABEL_39;
			}
			if ((uint8_t)v80 == 25) {
				v13 = 0.039999999;
				v14 = 10;
			LABEL_39:
				v15 = *(uint32_t*)(a1 + 56);
				v16 = *(uint32_t*)(a1 + 60);
				*(float*)&v87[64] = v13;
				*(uint16_t*)&v87[72] = v14;
				*(uint32_t*)&v82[16] = v15;
				*(uint32_t*)&v82[20] = v16;
				*(uint16_t*)&v87[60] = 0;
				*(float*)v82 = nox_xxx_calcBoltDamage_4EF1E0(v81, (int)v87);
				v17 = *(float*)(a1 + 176) + 20.0;
				v82[4] = 10;
				*(uint32_t*)&v82[12] = a1;
				*(uint32_t*)&v82[24] = 0;
				*(float*)&v82[8] = v17;
				v82[32] = 1;
				*(uint32_t*)&v82[28] = 0;
				v18 = nox_xxx_playerTraceAttack_538330(a1, (int)v82);
			LABEL_56:
				if (!v18) {
					nox_xxx_aud_501960(879, a1, 0, 0);
				}
				goto LABEL_159;
			}
		}
		v13 = 0.0;
		v14 = 0;
		goto LABEL_39;
	}
	if (v5 & 0x47F8000) {
		v19 = *(uint32_t*)(v4 + 736);
		v86 = *(uint32_t*)(v4 + 736);
		if ((v5 & 0x8000) != 0 || (v20 = *(uint8_t*)(v19 + 96), v80 = 31, v20 & 2)) {
			v80 = 29;
		}
		nox_xxx_animPlayerGetFrameRange_4F9F90(v80, &v77, &v78);
		if (*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)v79) {
			if (v80 == 29) {
				*(uint32_t*)v79 = nox_frame_xxx_2598000 + v77 * (v78 + 1);
			} else {
				*(uint32_t*)v79 = nox_frame_xxx_2598000;
			}
		}
		HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
		if (HIBYTE(v76) >= v77) {
			if (v5 & 0x47F0000) {
				*(uint32_t*)(v86 + 96) &= 0xFFFFFFFD;
			}
			goto LABEL_159;
		}
		if (v80 != 29 || HIBYTE(v76) != v77 / 2 || HIBYTE(v76) <= (unsigned char)v76) {
			if (*(uint8_t*)(a1 + 8) & 2) {
				if (v80 != 29 && v76 == 256) {
					v24 = *(uint32_t*)(v4 + 736);
					nox_xxx_useByNetCode_53F8E0(a1, v4);
					if (!*(uint8_t*)(v24 + 108)) {
						if (*(uint8_t*)(v24 + 109)) {
							nox_xxx_equipWeaponNPC_53A030(a1, v4);
						}
					}
				}
			}
			goto LABEL_159;
		}
		v21 = *(uint32_t*)(a1 + 60);
		*(uint32_t*)&v82[16] = *(uint32_t*)(a1 + 56);
		*(uint32_t*)&v82[20] = v21;
		*(float*)v82 = nox_xxx_calcBoltDamage_4EF1E0(v81, (int)v1);
		v22 = *(float*)(a1 + 176);
		v82[4] = 0;
		*(uint32_t*)&v82[12] = a1;
		v23 = v22 + v1[17];
		*(uint32_t*)&v82[24] = 0;
		v82[32] = 1;
		*(float*)&v82[8] = v23;
		nox_xxx_itemApplyAttackEffect_538840(v4, a1, (int)v82);
		v18 = nox_xxx_playerTraceAttack_538330(a1, (int)v82);
		goto LABEL_56;
	}
	if (v5 & 0x7800000) {
		v25 = ((v5 & 0x3800000) != 0) + 31;
		nox_xxx_animPlayerGetFrameRange_4F9F90(v25, &v77, &v78);
		if (*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)v79) {
			*(uint32_t*)v79 = nox_frame_xxx_2598000 + v77 * (v78 + 1);
		}
		HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
		if (v25 != 32 || HIBYTE(v76) != v77 / 2 || HIBYTE(v76) <= (unsigned char)v76) {
			goto LABEL_159;
		}
		v26 = *(uint32_t*)(a1 + 60);
		*(uint32_t*)&v82[16] = *(uint32_t*)(a1 + 56);
		*(uint32_t*)&v82[20] = v26;
		*(float*)v82 = nox_xxx_calcBoltDamage_4EF1E0(v81, (int)v1);
		v27 = *(float*)(a1 + 176);
		v82[4] = 0;
		*(uint32_t*)&v82[12] = a1;
		v28 = v27 + v1[17];
		*(uint32_t*)&v82[24] = 0;
		v82[32] = 1;
		*(float*)&v82[8] = v28;
		nox_xxx_itemApplyAttackEffect_538840(v4, a1, (int)v82);
		v18 = nox_xxx_playerTraceAttack_538330(a1, (int)v82);
		goto LABEL_56;
	}
	if (!(v5 & 0x40)) {
		if ((v5 & 0x80u) == 0) {
			if (v5 & 0x200) {
				nox_xxx_animPlayerGetFrameRange_4F9F90(28, &v77, &v78);
				if (*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)v79) {
					*(uint32_t*)v79 = nox_frame_xxx_2598000 + v77 * (v78 + 1);
				}
				HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned char)v76) {
					v46 = *(uint32_t*)(a1 + 60);
					*(uint32_t*)&v82[16] = *(uint32_t*)(a1 + 56);
					*(uint32_t*)&v82[20] = v46;
					*(float*)v82 = nox_xxx_calcBoltDamage_4EF1E0(v81, (int)v1);
					v47 = *(float*)(a1 + 176);
					v82[4] = 0;
					*(uint32_t*)&v82[12] = a1;
					v48 = v47 + v1[17];
					*(uint32_t*)&v82[24] = 0;
					v82[32] = 1;
					*(float*)&v82[8] = v48;
					nox_xxx_itemApplyAttackEffect_538840(v4, a1, (int)v82);
					if (!nox_xxx_playerTraceAttack_538330(a1, (int)v82)) {
						nox_xxx_aud_501960(880, a1, 0, 0);
					}
				}
			} else if (v5 & 0x100) {
				nox_xxx_animPlayerGetFrameRange_4F9F90(27, &v77, &v78);
				if (*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)v79) {
					*(uint32_t*)v79 = nox_frame_xxx_2598000 + v77 * (v78 + 1);
				}
				HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned char)v76) {
					v49 = *(uint32_t*)(a1 + 60);
					*(uint32_t*)&v82[16] = *(uint32_t*)(a1 + 56);
					*(uint32_t*)&v82[20] = v49;
					*(float*)v82 = nox_xxx_calcBoltDamage_4EF1E0(v81, (int)v1);
					v50 = *(float*)(a1 + 176);
					v82[4] = 0;
					*(uint32_t*)&v82[12] = a1;
					v51 = v50 + v1[17];
					*(uint32_t*)&v82[24] = 0;
					v82[32] = 1;
					*(float*)&v82[8] = v51;
					nox_xxx_itemApplyAttackEffect_538840(v4, a1, (int)v82);
					if (!nox_xxx_playerTraceAttack_538330(a1, (int)v82)) {
						nox_xxx_aud_501960(881, a1, 0, 0);
					}
				}
			} else if (v5 & 0x400) {
				nox_xxx_animPlayerGetFrameRange_4F9F90(37, &v77, &v78);
				if (*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)v79) {
					*(uint32_t*)v79 = nox_frame_xxx_2598000 + v77 * (v78 + 1);
				}
				HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned char)v76) {
					v52 = *(uint32_t*)(a1 + 60);
					*(uint32_t*)&v82[16] = *(uint32_t*)(a1 + 56);
					*(uint32_t*)&v82[20] = v52;
					*(float*)v82 = nox_xxx_calcBoltDamage_4EF1E0(v81, (int)v1);
					v53 = *(float*)(a1 + 176);
					v82[4] = 0;
					*(uint32_t*)&v82[12] = a1;
					v54 = v53 + v1[17];
					*(uint32_t*)&v82[24] = 0;
					v82[32] = 1;
					*(float*)&v82[8] = v54;
					nox_xxx_itemApplyAttackEffect_538840(v4, a1, (int)v82);
					if (!nox_xxx_playerTraceAttack_538330(a1, (int)v82)) {
						nox_xxx_aud_501960(881, a1, 0, 0);
					}
				}
			} else if (v5 & 0x4000) {
				nox_xxx_animPlayerGetFrameRange_4F9F90(39, &v77, &v78);
				if (*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)v79) {
					*(uint32_t*)v79 = nox_frame_xxx_2598000 + v77 * (v78 + 1);
				}
				HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned char)v76) {
					v55 = 8 * *(short*)(a1 + 124);
					*(float*)&v82[16] = *getMemFloatPtr(0x587000, 194136 + v55) * 35.0 + *(float*)(a1 + 56);
					*(float*)&v82[20] = *getMemFloatPtr(0x587000, 194140 + v55) * 35.0 + *(float*)(a1 + 60);
					*(float*)v82 = nox_xxx_calcBoltDamage_4EF1E0(v81, (int)v1);
					v82[4] = 2;
					*(uint32_t*)&v82[12] = a1;
					*(float*)&v82[8] = v1[17];
					*(uint32_t*)&v82[24] = 1;
					v82[32] = 1;
					nox_xxx_itemApplyAttackEffect_538840(v4, a1, (int)v82);
					nox_xxx_playerTraceAttack_538330(a1, (int)v82);
					v75 = (double)v81 * 0.1;
					v56 = nox_float2int(v75);
					nox_xxx_earthquakeSend_4D9110((float*)(a1 + 56), v56);
					nox_xxx_aud_501960(882, a1, 0, 0);
				}
			} else if (v5 & 0x800) {
				nox_xxx_animPlayerGetFrameRange_4F9F90(26, &v77, &v78);
				if (*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)v79) {
					*(uint32_t*)v79 = nox_frame_xxx_2598000 + v77 * (v78 + 1);
				}
				HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned char)v76) {
					v57 = *(uint32_t*)(a1 + 60);
					*(uint32_t*)&v82[16] = *(uint32_t*)(a1 + 56);
					*(uint32_t*)&v82[20] = v57;
					*(float*)v82 = nox_xxx_calcBoltDamage_4EF1E0(v81, (int)v1);
					v58 = *(float*)(a1 + 176);
					v82[4] = 2;
					*(uint32_t*)&v82[12] = a1;
					v59 = v58 + v1[17];
					*(uint32_t*)&v82[24] = 1;
					v82[32] = 1;
					*(float*)&v82[8] = v59;
					nox_xxx_itemApplyAttackEffect_538840(v4, a1, (int)v82);
					if (!nox_xxx_playerTraceAttack_538330(a1, (int)v82)) {
						nox_xxx_aud_501960(884, a1, 0, 0);
					}
				}
			} else if (v5 & 0x3000) {
				nox_xxx_animPlayerGetFrameRange_4F9F90(35, &v77, &v78);
				if (*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)v79) {
					*(uint32_t*)v79 = nox_frame_xxx_2598000 + v77 * (v78 + 1);
				}
				HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned char)v76) {
					v60 = *(uint32_t*)(a1 + 60);
					*(uint32_t*)&v82[16] = *(uint32_t*)(a1 + 56);
					*(uint32_t*)&v82[20] = v60;
					*(float*)v82 = nox_xxx_calcBoltDamage_4EF1E0(v81, (int)v1);
					v61 = *(float*)(a1 + 176);
					v82[4] = 0;
					*(uint32_t*)&v82[12] = a1;
					v62 = v61 + v1[17];
					*(uint32_t*)&v82[24] = 1;
					v82[32] = 1;
					*(float*)&v82[8] = v62;
					nox_xxx_itemApplyAttackEffect_538840(v4, a1, (int)v82);
					if (!nox_xxx_playerTraceAttack_538330(a1, (int)v82)) {
						nox_xxx_aud_501960(883, a1, 0, 0);
					}
				}
			} else if (v5 & 4) {
				nox_xxx_animPlayerGetFrameRange_4F9F90(33, &v77, &v78);
				if (*(uint8_t*)(a1 + 8) & 4) {
					v63 = (uint32_t*)v79;
					if (!*(uint32_t*)v79) {
						v64 = nox_xxx_itemCheckReadinessEffect_4E0960(v4);
						*v63 = nox_frame_xxx_2598000 + v77 * (v78 + 1) - v64;
					}
				}
				v65 = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
				v66 = nox_xxx_itemCheckReadinessEffect_4E0960(v4) + v65;
				HIBYTE(v76) = v66;
				if (v66 >= v77 - 1 && v66 > (unsigned char)v76) {
					nox_xxx_shootBowCrossbow1_539BD0(a1, v4);
					HIBYTE(v76) = v77;
				}
			} else if (v5 & 8) {
				nox_xxx_animPlayerGetFrameRange_4F9F90(34, &v77, &v78);
				if (*(uint8_t*)(a1 + 8) & 4) {
					v67 = (uint32_t*)v79;
					if (!*(uint32_t*)v79) {
						v68 = nox_xxx_itemCheckReadinessEffect_4E0960(v4);
						*v67 = nox_frame_xxx_2598000 + v77 * (v78 + 1) - v68;
					}
				}
				HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
				v69 = (int)HIBYTE(v76) < 1;
				if (HIBYTE(v76) == 1) {
					if (!(uint8_t)v76) {
						nox_xxx_shootBowCrossbow1_539BD0(a1, v4);
					}
					v69 = 0;
				}
				if (!v69) {
					HIBYTE(v76) += nox_xxx_itemCheckReadinessEffect_4E0960(v4);
				}
			}
			goto LABEL_159;
		}
		nox_xxx_animPlayerGetFrameRange_4F9F90(44, &v77, &v78);
		if (*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)v79) {
			*(uint32_t*)v79 = nox_frame_xxx_2598000 + v77 * (v78 + 1);
		}
		HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
		if (HIBYTE(v76) != v77 / 2 || HIBYTE(v76) <= (unsigned char)v76) {
			goto LABEL_159;
		}
		v37 = *(float*)(a1 + 176) + 4.0;
		v38 = 8 * *(short*)(a1 + 124);
		v39 = *(float*)(a1 + 60);
		v40 = *(char**)(v4 + 736);
		v41 = v37 * *getMemFloatPtr(0x587000, 194136 + v38) + *(float*)(a1 + 56);
		v83.field_0 = *(float*)(a1 + 56);
		v83.field_4 = v39;
		v83.field_8 = v41;
		v83.field_C = v37 * *getMemFloatPtr(0x587000, 194140 + v38) + *(float*)(a1 + 60);
		if (nox_xxx_mapTraceRay_535250(&v83, 0, 0, 4)) {
			v42 = nox_xxx_newObjectByTypeID_4E3810("FanChakramInMotion");
			v43 = (int)v42;
			if (v42) {
				*(uint32_t*)(v42[175] + 4) = a1;
				nox_xxx_createAt_4DAA50((int)v42, a1, v83.field_8, v83.field_C);
				nox_xxx_modifSetItemAttrs_4E4990(v43, *(int**)(v4 + 692));
				*(float*)(v43 + 80) =
					*getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a1 + 124)) * *(float*)(v43 + 544);
				*(float*)(v43 + 84) =
					*getMemFloatPtr(0x587000, 194140 + 8 * *(short*)(a1 + 124)) * *(float*)(v43 + 544);
				v44 = *(uint16_t*)(a1 + 124);
				*(uint16_t*)(v43 + 124) = v44;
				*(uint16_t*)(v43 + 126) = v44;
				nox_xxx_aud_501960(891, a1, 0, 0);
				if (!v40[2]) {
					v45 = v40[1] - 1;
					v40[1] = v45;
					if (v45) {
						if (*(uint8_t*)(a1 + 8) & 4) {
							nox_xxx_netReportCharges_4D82B0(*(unsigned char*)(*(uint32_t*)(v79 + 276) + 2064),
															(uint32_t*)v4, v45, *v40);
						}
					} else {
						sub_4ED0C0(a1, (int*)v4);
						nox_xxx_delayedDeleteObject_4E5CC0(v4);
						sub_539FB0((uint32_t*)a1);
					}
				}
				goto LABEL_159;
			}
			return 0;
		}
	LABEL_94:
		nox_xxx_aud_501960(323, a1, 0, 0);
		goto LABEL_159;
	}
	nox_xxx_animPlayerGetFrameRange_4F9F90(44, &v77, &v78);
	if (*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)v79) {
		*(uint32_t*)v79 = nox_frame_xxx_2598000 + v77 * (v78 + 1);
	}
	HIBYTE(v76) = (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) / (unsigned int)(v78 + 1);
	if (HIBYTE(v76) != v77 / 2 || HIBYTE(v76) <= (unsigned char)v76) {
		goto LABEL_159;
	}
	v29 = *(float*)(a1 + 176) + 4.0;
	v30 = 8 * *(short*)(a1 + 124);
	v31 = *(float*)(a1 + 60);
	v32 = v29 * *getMemFloatPtr(0x587000, 194136 + v30) + *(float*)(a1 + 56);
	v83.field_0 = *(float*)(a1 + 56);
	v83.field_4 = v31;
	v83.field_8 = v32;
	v83.field_C = v29 * *getMemFloatPtr(0x587000, 194140 + v30) + *(float*)(a1 + 60);
	if (!nox_xxx_mapTraceRay_535250(&v83, 0, 0, 5)) {
		goto LABEL_94;
	}
	v33 = nox_xxx_newObjectByTypeID_4E3810("RoundChakramInMotion");
	v34 = (int)v33;
	if (!v33) {
		return 0;
	}
	v35 = v33[187];
	sub_4ED0C0(a1, (int*)v4);
	nox_xxx_createAt_4DAA50(v34, a1, v83.field_8, v83.field_C);
	nox_xxx_inventoryPutImpl_4F3070(v34, v4, 1);
	nox_xxx_modifSetItemAttrs_4E4990(v34, *(int**)(v4 + 692));
	*(float*)(v34 + 80) = *getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a1 + 124)) * *(float*)(v34 + 544);
	*(float*)(v34 + 84) = *getMemFloatPtr(0x587000, 194140 + 8 * *(short*)(a1 + 124)) * *(float*)(v34 + 544);
	v36 = *(uint16_t*)(a1 + 124);
	*(uint16_t*)(v34 + 124) = v36;
	*(uint16_t*)(v34 + 126) = v36;
	*(uint8_t*)(v35 + 4) = 4;
	*(uint32_t*)(v35 + 16) = *(uint32_t*)(a1 + 56);
	*(uint32_t*)(v35 + 20) = *(uint32_t*)(a1 + 60);
	*(uint8_t*)(v35 + 24) = 2;
	nox_xxx_aud_501960(891, a1, 0, 0);
LABEL_159:
	v70 = *(uint32_t*)(a1 + 8);
	if (v70 & 4) {
		v71 = v79;
		v72 = HIBYTE(v76);
		*(uint8_t*)(v79 + 236) = HIBYTE(v76);
		if (HIBYTE(v76) >= v77) {
			*(uint8_t*)(v71 + 236) = v77 - 1;
		}
	} else if (v70 & 2 && *(uint8_t*)(a1 + 12) & 0x10) {
		v73 = v79;
		*(uint8_t*)(v79 + 481) = HIBYTE(v76);
		v72 = HIBYTE(v76);
		if (HIBYTE(v76) >= v77) {
			*(uint8_t*)(v73 + 481) = v77 - 1;
		}
	} else {
		v72 = HIBYTE(v76);
	}
	return v72 < v77;
}
// 539AF2: variable 'v76' is possibly undefined

//----- (00539B90) --------------------------------------------------------
short nox_xxx_warcryStunMonsters_539B90(int a1, int a2) {
	short result; // ax

	result = a2;
	if (a2) {
		result = a1;
		if (a1) {
			if (*(uint8_t*)(a1 + 8) & 2 && *(uint32_t*)(a1 + 12) & 0x20000 && !(*(uint32_t*)(a1 + 16) & 0x8020)) {
				nox_xxx_buffApplyTo_4FF380(a1, 5, 90, 3);
			}
		}
	}
	return result;
}

//----- (00539BD0) --------------------------------------------------------
int nox_xxx_shootBowCrossbow1_539BD0(int a1, int a2) {
	int v2;       // eax
	uint8_t* v3;  // edi
	char* v4;     // ebx
	uint32_t* v6; // esi
	int v7;       // eax
	int v8;       // eax

	v2 = nox_xxx_weaponInventoryEquipFlags_415820(a2);
	v3 = *(uint8_t**)(a2 + 736);
	v4 = (char*)v2;
	if (!*v3) {
		v6 = *(uint32_t**)(a1 + 504);
		if (v6) {
			while (1) {
				v7 = v6[4];
				if (v7 & 0x100) {
					if (nox_xxx_weaponInventoryEquipFlags_415820((int)v6) == 2) {
						v8 = v6[184];
						if (*(uint8_t*)(v8 + 1) || *(uint8_t*)(v8 + 2) == 1) {
							break;
						}
					}
				}
				v6 = (uint32_t*)v6[124];
				if (!v6) {
					goto LABEL_14;
				}
			}
			nox_xxx_shootBowCrossbow2_539D80(a1, (int)v6, a2, v4);
			return 1;
		}
	LABEL_14:
		if (nox_common_gameFlags_check_40A5C0(4096) && v4 == (char*)4) {
			nox_xxx_shootBowCrossbow2_539D80(a1, 0, a2, (char*)4);
		}
		if (!(*(uint8_t*)(a1 + 8) & 4)) {
			return 0;
		}
		if (nox_xxx_playerTryReloadQuiver_539FF0((uint32_t*)a1) == 1) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "pattack.c:ReloadQuiver", 0);
			*v3 = 0;
		} else {
			if (nox_common_gameFlags_check_40A5C0(4096) && v4 == (char*)4) {
				goto LABEL_25;
			}
			nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "pattack.c:NoQuiver", 0);
		}
		if (v4 != (char*)4) {
			if (v4 == (char*)8) {
				nox_xxx_aud_501960(888, a1, 0, 0);
			}
			goto LABEL_29;
		}
	LABEL_25:
		if (!nox_common_gameFlags_check_40A5C0(4096)) {
			nox_xxx_aud_501960(887, a1, 0, 0);
		}
	LABEL_29:
		nox_xxx_playerSetState_4FA020((uint32_t*)a1, 13);
		return 0;
	}
	nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "pattack.c:ReloadingQuiver", 0);
	if (v4 == (char*)4) {
		if (!nox_common_gameFlags_check_40A5C0(4096)) {
			nox_xxx_aud_501960(887, a1, 0, 0);
			--*v3;
			return 0;
		}
	} else if (v4 == (char*)8) {
		nox_xxx_aud_501960(888, a1, 0, 0);
	}
	--*v3;
	return 0;
}

//----- (00539D80) --------------------------------------------------------
uint32_t* nox_xxx_shootBowCrossbow2_539D80(int a1, int a2, int a3, char* a4) {
	double v4;        // st7
	char* v5;         // ebx
	int v6;           // eax
	double v7;        // st6
	double v8;        // st7
	float v9;         // eax
	uint32_t* result; // eax
	uint32_t* v11;    // eax
	int v12;          // edi
	short v13;        // ax
	int v14;          // edi
	char v15;         // al
	char v16;         // cl
	float v17;        // [esp+Ch] [ebp-18h]
	float v18;        // [esp+10h] [ebp-14h]
	float4 v19;       // [esp+14h] [ebp-10h]

	v4 = *(float*)(a1 + 176) + 4.0;
	if (a2) {
		v5 = *(char**)(a2 + 736);
	} else {
		v5 = a4;
	}
	v6 = 8 * *(short*)(a1 + 124);
	v7 = v4 * *getMemFloatPtr(0x587000, 194136 + v6);
	v19.field_4 = *(float*)(a1 + 60);
	v17 = v7 + *(float*)(a1 + 56);
	v8 = v4 * *getMemFloatPtr(0x587000, 194140 + v6);
	v9 = *(float*)(a1 + 56);
	v19.field_8 = v17;
	v19.field_0 = v9;
	v18 = v8 + *(float*)(a1 + 60);
	v19.field_C = v18;
	result = (uint32_t*)nox_xxx_mapTraceRay_535250(&v19, 0, 0, 5);
	if (result) {
		if (a2) {
			if (a4 == (char*)4) {
				v11 = nox_xxx_newObjectByTypeID_4E3810("ArcherArrow");
			} else {
				v11 = nox_xxx_newObjectByTypeID_4E3810("ArcherBolt");
			}
		} else {
			v11 = nox_xxx_newObjectByTypeID_4E3810("WeakArcherArrow");
		}
		v12 = (int)v11;
		if (v11) {
			*(uint32_t*)(v11[175] + 4) = a1;
			nox_xxx_createAt_4DAA50((int)v11, a1, v17, v18);
			if (a2) {
				nox_xxx_modifSetItemAttrs_4E4990(v12, *(int**)(a2 + 692));
			}
			nox_xxx_shootApplyEffects_539F40(a1, a3, v12);
			*(float*)(v12 + 80) = *getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a1 + 124)) * *(float*)(v12 + 544);
			*(float*)(v12 + 84) = *getMemFloatPtr(0x587000, 194140 + 8 * *(short*)(a1 + 124)) * *(float*)(v12 + 544);
			v13 = *(uint16_t*)(a1 + 124);
			*(uint16_t*)(v12 + 124) = v13;
			*(uint16_t*)(v12 + 126) = v13;
		}
		if (a2) {
			if (!v5[2]) {
				if (*(uint8_t*)(a1 + 8) & 4) {
					v14 = *(uint32_t*)(a1 + 748);
					v15 = v5[1] - 1;
					v16 = *v5;
					v5[1] = v15;
					nox_xxx_netReportCharges_4D82B0(*(unsigned char*)(*(uint32_t*)(v14 + 276) + 2064), (uint32_t*)a2,
													v15, v16);
					if (!v5[1]) {
						nox_xxx_delayedDeleteObject_4E5CC0(a2);
					}
				}
			}
		}
		if (a4 == (char*)4) {
			result = nox_xxx_aud_501960(885, a1, 0, 0);
		} else {
			result = nox_xxx_aud_501960(886, a1, 0, 0);
		}
	}
	return result;
}

//----- (00539F40) --------------------------------------------------------
int nox_xxx_shootApplyEffects_539F40(int a1, int a2, int a3) {
	int v3;                             // ebx
	int v4;                             // edi
	int* v5;                            // esi
	int v6;                             // eax
	int (*v7)(int, int, int, int, int); // ecx
	int result;                         // eax
	int v9;                             // [esp+18h] [ebp+8h]
	int v10;                            // [esp+1Ch] [ebp+Ch]

	v3 = a3;
	v4 = a2;
	v10 = *(uint32_t*)(a3 + 692);
	v9 = 2;
	v5 = (int*)(*(uint32_t*)(v4 + 692) + 8);
	do {
		v6 = *v5;
		if (*v5) {
			if (*(char (**)(int, int, int, int))(v6 + 52) == nox_xxx_recoilEffect_4E0640) {
				*(uint32_t*)(v10 + 12) = v6;
			} else {
				v7 = *(int (**)(int, int, int, int, int))(v6 + 40);
				if (v7 == nox_xxx_effectProjectileSpeed_4E09B0) {
					v7(v6, v4, a1, 0, v3);
				}
			}
		}
		++v5;
		result = --v9;
	} while (v9);
	return result;
}

//----- (00539FB0) --------------------------------------------------------
int sub_539FB0(uint32_t* a1) {
	nox_object_t* item;

	item = (nox_object_t*)a1[126];
	if (!item) {
		return 0;
	}
	while (nox_xxx_weaponInventoryEquipFlags_415820(item) != 128) {
		item = item->field_124;
		if (!item) {
			return 0;
		}
	}
	return nox_xxx_playerEquipWeapon_53A420(a1, item, 1, 1);
}

//----- (00539FF0) --------------------------------------------------------
int nox_xxx_playerTryReloadQuiver_539FF0(uint32_t* a1) {
	nox_object_t* item;

	item = (nox_object_t*)a1[126];
	if (!item) {
		return 0;
	}
	while (nox_xxx_weaponInventoryEquipFlags_415820(item) != 2) {
		item = item->field_124;
		if (!item) {
			return 0;
		}
	}
	return nox_xxx_playerEquipWeapon_53A420(a1, item, 1, 1);
}

//----- (0053A030) --------------------------------------------------------
int nox_xxx_equipWeaponNPC_53A030(int a1, int a2) {
	int v2;     // ebp
	int result; // eax
	int v4;     // eax
	int v5;     // ecx

	v2 = *(uint32_t*)(a1 + 748);
	if (!(*(uint32_t*)(a2 + 8) & 0x1001000)) {
		return 0;
	}
	v4 = *(uint32_t*)(a2 + 16);
	if (!(v4 & 0x100)) {
		return 0;
	}
	result = *(uint32_t*)(a1 + 504);
	if (!result) {
		return 0;
	}
	while (result != a2) {
		result = *(uint32_t*)(result + 496);
		if (!result) {
			return result;
		}
	}
	*(uint8_t*)(v2 + 2068) = 0;
	v5 = *(uint32_t*)(a2 + 16);
	BYTE1(v5) &= 0xFEu;
	*(uint32_t*)(a2 + 16) = v5;
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		nox_xxx_npcSetItemEquipFlags_4E4B20(a1, a2, 0);
	}
	if (*(uint8_t*)(a2 + 12) & 0xC) {
		sub_53A0F0(a1, 1, 1);
	}
	if (!(*(uint8_t*)(a2 + 12) & 2)) {
		*(uint32_t*)(v2 + 2064) = 0;
	}
	nox_xxx_itemApplyDisengageEffect_4F3030(a2, a1);
	sub_4FEB60(a1, a2);
	return 1;
}

//----- (0053A0F0) --------------------------------------------------------
void sub_53A0F0(int a1, int a2, int a3) {
	int v3; // esi
	int v4; // eax

	v3 = *(uint32_t*)(a1 + 504);
	if (v3) {
		while (1) {
			v4 = *(uint32_t*)(v3 + 16);
			if (v4 & 0x100) {
				if (nox_xxx_weaponInventoryEquipFlags_415820(v3) == 2) {
					break;
				}
			}
			v3 = *(uint32_t*)(v3 + 496);
			if (!v3) {
				return;
			}
		}
		nox_xxx_playerDequipWeapon_53A140((uint32_t*)a1, v3, a2, a3);
	}
}

//----- (0053A140) --------------------------------------------------------
int nox_xxx_playerDequipWeapon_53A140(uint32_t* a1, nox_object_t* item, int a3, int a4) {
	int eflags = nox_xxx_weaponInventoryEquipFlags_415820(item);
	if (a1[2] & 2) {
		return nox_xxx_equipWeaponNPC_53A030(a1, item);
	}
	if (!(a1[2] & 4) || !(item->obj_class & 0x1001000)) {
		return 0;
	}
	int v10 = a1[187];
	if (*(uint8_t*)(v10 + 88) == 1) {
		nox_xxx_playerSetState_4FA020(a1, 13);
	}
	void* v11 = *(uint32_t**)(v10 + 104);
	if (!v11 || v11 != item && eflags != 2) {
		return 0;
	}
	if (eflags & 0xC) {
		sub_53A0F0(a1, a3, a4);
	}
	sub_4FEB60(a1, item);
	if (eflags == 2) {
		item->flags &= 0xFFFFFEFF;
		*(uint32_t*)(*(uint32_t*)(v10 + 276) + 4) &= 0xFFFFFFFD;
		if (a3) {
			nox_xxx_netReportDequip_4D8590(*(unsigned char*)(*(uint32_t*)(v10 + 276) + 2064), item);
		}
		if (a4) {
			nox_xxx_netReportDequip_4D84C0(255, item);
		}
	} else if (*(uint32_t*)(v10 + 104)) {
		int v13 = *(uint32_t*)(v10 + 104);
		*(uint32_t*)(v13 + 16) &= 0xFFFFFEFF;
		*(uint32_t*)(*(uint32_t*)(v10 + 276) + 4) &= ~nox_xxx_weaponInventoryEquipFlags_415820(v13);
		if (a3) {
			nox_xxx_netReportDequip_4D8590(*(unsigned char*)(*(uint32_t*)(v10 + 276) + 2064), v13);
		}
		if (a4) {
			nox_xxx_netReportDequip_4D84C0(255, item);
		}
		*(uint32_t*)(v10 + 104) = 0;
	}
	nox_xxx_itemApplyDisengageEffect_4F3030(item, a1);
	// Following code is not present in the original exe(!) and it's responsible for automatically equipping shields
	// whenever possible.
	if (gameex_flags & 2) {
		sub_980523(a1);
		int v16 = a1[187];
		if (!*(uint32_t*)(v16 + 108) ||
			!(nox_xxx_weaponInventoryEquipFlags_415820(*(uint32_t*)(v16 + 108)) & 0x7FFE40C)) {
			int v17 = *(uint32_t*)(*(uint32_t*)(v16 + 276) + 2500);
			if (v17 && (unsigned char)*(uint32_t*)(v17 + 16) == 16) {
				nox_xxx_playerTryEquip_4F2F70(a1, v17);
			} else {
				void* v18 = sub_9805EB(a1);
				if (v18) {
					nox_xxx_playerTryEquip_4F2F70(a1, v18);
				}
			}
		}
	}
	return 1;
}

//----- (0053A2C0) --------------------------------------------------------
int nox_xxx_NPCEquipWeapon_53A2C0(int a1, nox_object_t* item) {
	int v2;     // ebp
	int result; // eax
	int v4;     // eax
	int v5;     // ecx
	int v6;     // eax
	int v7;     // edx
	int v8;     // ecx

	v2 = *(uint32_t*)(a1 + 748);
	if (!(*(uint32_t*)&item->obj_class & 0x1001000)) {
		return 0;
	}
	v4 = item->flags;
	if (v4 & 0x100) {
		return 0;
	}
	result = *(uint32_t*)(a1 + 504);
	if (!result) {
		return 0;
	}
	while (result != item) {
		result = *(uint32_t*)(result + 496);
		if (!result) {
			return result;
		}
	}
	*(uint8_t*)(v2 + 2068) = 0;
	if (!(*(uint8_t*)&item->field_3 & 0xC)) {
		sub_53A0F0(a1, 1, 1);
	}
	v5 = *(uint32_t*)&item->field_3;
	if (!(v5 & 2)) {
		v6 = *(uint32_t*)(a1 + 504);
		if (v6) {
			while (1) {
				v7 = *(uint32_t*)(v6 + 16);
				if (v7 & 0x100) {
					if (*(uint32_t*)(v6 + 8) & 0x1001000 && (!(v5 & 0xC) || !(*(uint8_t*)(v6 + 12) & 2))) {
						break;
					}
				}
				v6 = *(uint32_t*)(v6 + 496);
				if (!v6) {
					goto LABEL_22;
				}
			}
			nox_xxx_equipWeaponNPC_53A030(a1, v6);
		}
	}
LABEL_22:
	v8 = item->flags;
	BYTE1(v8) |= 1u;
	item->flags = v8;
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		nox_xxx_npcSetItemEquipFlags_4E4B20(a1, item, 1);
	}
	if (!(*(uint8_t*)&item->field_3 & 2)) {
		*(uint32_t*)(v2 + 2064) = item;
	}
	nox_xxx_itemApplyEngageEffect_4F2FF0(item, a1);
	if (nox_xxx_weaponInventoryEquipFlags_415820(item) & 0x7FFE40C) {
		sub_53A3D0((uint32_t*)a1);
	}
	return 1;
}

//----- (0053A3D0) --------------------------------------------------------
void sub_53A3D0(uint32_t* a1) {
	uint32_t* i; // esi
	int v2;      // eax

	if (a1) {
		for (i = (uint32_t*)a1[126]; i; i = (uint32_t*)i[124]) {
			if (i[2] & 0x2000000) {
				v2 = i[4];
				if (v2 & 0x100) {
					if (nox_xxx_unitArmorInventoryEquipFlags_415C70((int)i) & 0x3000000) {
						sub_53E430(a1, (int)i, 1, 1);
					}
				}
			}
		}
	}
}

//----- (0053A420) --------------------------------------------------------
int nox_xxx_playerEquipWeapon_53A420(uint32_t* a1, nox_object_t* item, int a3, int a4) {
	const int v4 = nox_xxx_weaponInventoryEquipFlags_415820(item);
	if (!(item->obj_class & 0x1001000)) {
		return 0;
	}
	const int v5 = item->flags;
	if (v5 & 0x100) {
		return 0;
	}
	const int v6 = a1[2]; // +8
	if (v6 & 2) {
		return nox_xxx_NPCEquipWeapon_53A2C0((int)a1, item);
	}
	if (!(v6 & 4)) {
		return 0;
	}
	const int v8 = a1[187]; // +748
	if (nox_xxx_probablyWarcryCheck_4FC3E0((int)a1, 2) || nox_xxx_probablyWarcryCheck_4FC3E0((int)a1, 1)) {
		return 0;
	}
	if (!nox_xxx_playerClassCanUseItem_57B3D0(item, *(uint8_t*)(*(uint32_t*)(v8 + 276) + 2251))) {
		nox_xxx_netPriMsgToPlayer_4DA2C0((int)a1, "weapon.c:WeaponEquipClassFail", 0);
		if (a4) {
			nox_xxx_aud_501960(925, (int)a1, 2, a1[9]);
		}
		return 0;
	}
	const bool v9 = nox_xxx_playerCheckStrength_4F3180((int)a1, item);
	if (!v9) {
		nox_xxx_netPriMsgToPlayer_4DA2C0((int)a1, "weapon.c:WeaponEquipStrengthFail", 0);
		if (a4) {
			nox_xxx_aud_501960(925, (int)a1, 2, a1[9]);
		}
		return 0;
	}
	int result = a1[126]; // +504
	if (!result) {
		return 0;
	}
	while (result != item) {
		result = *(uint32_t*)(result + 496);
		if (!result) {
			return result;
		}
	}
	if (*(uint8_t*)(v8 + 88) == 1) {
		nox_xxx_playerSetState_4FA020(a1, 13);
	}
	if (v4 == 2) {
		if (!(*(uint8_t*)(*(uint32_t*)(v8 + 276) + 4) & 0xC) && !sub_53A680((int)a1)) {
			nox_xxx_netPriMsgToPlayer_4DA2C0((int)a1, "weapon.c:BowNotFound", 0);
			if (a4) {
				nox_xxx_aud_501960(925, (int)a1, 2, a1[9]);
			}
			return 0;
		}
		sub_53A0F0((int)a1, 1, 1);
	}
	const int v10 = *(uint32_t*)(v8 + 104);
	if (v10 && v4 != 2 && !nox_xxx_playerDequipWeapon_53A140(a1, v10, 1, 1)) {
		return 0;
	}
	const int v11 = item->flags;
	BYTE1(v11) |= 1u;
	item->flags = v11;
	*(uint32_t*)(*(uint32_t*)(v8 + 276) + 4) |= v4;
	nox_xxx_netReportEquip_4D8540(*(unsigned char*)(*(uint32_t*)(v8 + 276) + 2064), (uint32_t*)item, a3);
	if (v4 != 2) {
		*(uint32_t*)(v8 + 104) = item;
	}
	const int v12 = item->obj_class;
	if (v12 & 0x1000 && item->field_3 & 0x47F0000) {
		nox_xxx_netReportCharges_4D82B0(*(unsigned char*)(*(uint32_t*)(v8 + 276) + 2064), (uint32_t*)item,
										*(uint8_t*)(*(uint32_t*)&item->field_184 + 108),
										*(uint8_t*)(*(uint32_t*)&item->field_184 + 109));
	} else if (v12 & 0x1000000) {
		if (v4 & 0x82) {
			nox_xxx_netReportCharges_4D82B0(*(unsigned char*)(*(uint32_t*)(v8 + 276) + 2064), (uint32_t*)item,
											*(uint8_t*)(*(uint32_t*)&item->field_184 + 1),
											**(uint8_t**)&item->field_184);
		} else if (v4 & 0xC) {
			**(uint8_t**)&item->field_184 = 0;
		}
	}
	nox_xxx_itemApplyEngageEffect_4F2FF0(item, (int)a1);
	if (v4 & 0x7FFE40C) {
		sub_53A3D0(a1);
	}
	return 1;
}
// 53A4E9: variable 'v9' is possibly undefined

//----- (0053A680) --------------------------------------------------------
int sub_53A680(int a1) {
	nox_object_t* item;

	item = *(nox_object_t**)(a1 + 504);
	if (!item) {
		return 0;
	}
	while (!(nox_xxx_weaponInventoryEquipFlags_415820(item) & 0xC)) {
		item = item->field_124;
		if (!item) {
			return 0;
		}
	}
	return nox_xxx_playerEquipWeapon_53A420((uint32_t*)a1, item, 1, 1);
}

//----- (0053A6C0) --------------------------------------------------------
void sub_53A6C0(int a1, nox_object_t* item) {
	int v2;   // edx
	short v3; // ax

	if (a1 && item) {
		v2 = *(uint32_t*)&item->obj_class;
		if (v2 & 0x1000) {
			nox_xxx_aud_501960(830, a1, 0, 0);
		} else {
			v3 = *(uint16_t*)&item->field_6_0;
			if (v3 & 0x10) {
				nox_xxx_aud_501960(842, a1, 0, 0);
			} else if (v3 & 8) {
				nox_xxx_aud_501960(844, a1, 0, 0);
			}
		}
	}
}

//----- (0053A720) --------------------------------------------------------
int sub_53A720(int a1, nox_object_t* item, int a3, int a4) {
	uint32_t* v4; // esi
	int v5;       // ebp
	int v6;       // ebx
	int v8;       // eax
	int v9;       // ebp
	int v10;      // eax
	int v11;      // eax
	float v12;    // [esp+0h] [ebp-14h]
	int v13;      // [esp+18h] [ebp+4h]

	v4 = (uint32_t*)a1;
	v5 = 0;
	if (*(uint8_t*)(a1 + 8) & 4) {
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			if (*(uint32_t*)&item->field_3 & 0x200000) {
				v12 = nox_xxx_gamedataGetFloat_419D40("ForceOfNatureStaffLimit");
				v6 = nox_float2int(v12);
				if (nox_xxx_inventoryCountObjects_4E7D30(a1, item->flags) >= v6) {
					nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "pickup.c:MaxSameItem", 0);
					nox_xxx_aud_501960(925, a1, 0, 0);
					return 0;
				}
			}
		}
	}
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096) && sub_409F40(2)) {
		if (!(*(uint8_t*)&item->field_3 & 0x82) && sub_4E7EC0(a1, item)) {
			v5 = 1;
		}
		if (*(uint8_t*)&item->field_3 & 0x40) {
			v8 = *(uint32_t*)(a1 + 516);
			if (v8) {
				while (!(*(uint32_t*)(v8 + 8) & 0x1000000) || !(*(uint8_t*)(v8 + 12) & 0x40)) {
					v8 = *(uint32_t*)(v8 + 512);
					if (!v8) {
						goto LABEL_18;
					}
				}
				goto LABEL_19;
			}
		}
	LABEL_18:
		if (v5 == 1) {
		LABEL_19:
			if (*(uint8_t*)(a1 + 8) & 4) {
				nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "weapon.c:CannotPickupDuplicateWeapon", 0);
				nox_xxx_aud_501960(925, a1, 2, *(uint32_t*)(a1 + 36));
			}
			return 0;
		}
	}
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096) &&
		*(uint8_t*)(a1 + 8) & 4 &&
		!nox_xxx_playerClassCanUseItem_57B3D0(item, *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2251))) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "weapon.c:WeaponEquipClassFail", 0);
		nox_xxx_aud_501960(925, a1, 2, *(uint32_t*)(a1 + 36));
		return 0;
	}
	if (nox_xxx_pickupDefault_4F31E0(a1, item, a3) != 1) {
		return 0;
	}
	if (*(uint8_t*)(a1 + 8) & 4) {
		v9 = 0;
		v13 = *(uint32_t*)(a1 + 748);
		if (!*(uint32_t*)(v13 + 104) && !sub_419E60((int)v4) && nox_xxx_weaponInventoryEquipFlags_415820(item) != 2) {
			v9 = nox_xxx_playerEquipWeapon_53A420(v4, item, a4, 0);
		}
		if (!sub_419E60((int)v4) && nox_xxx_weaponInventoryEquipFlags_415820(item) == 2) {
			v10 = *(uint32_t*)(*(uint32_t*)(v13 + 276) + 4);
			if (v10 & 0xC) {
				if (!(v10 & 2)) {
					v9 = nox_xxx_playerEquipWeapon_53A420(v4, item, a4, 0);
				}
			}
		}
		if (!v9) {
			v11 = *(uint32_t*)&item->obj_class;
			if (v11 & 0x1000 && *(uint32_t*)&item->field_3 & 0x47F0000) {
				nox_xxx_netReportCharges_4D82B0(*(unsigned char*)(*(uint32_t*)(v13 + 276) + 2064), item,
												*(uint8_t*)(*(uint32_t*)&item->field_184 + 108),
												*(uint8_t*)(*(uint32_t*)&item->field_184 + 109));
			} else if (v11 & 0x1000000 && *(uint8_t*)&item->field_3 & 0x82) {
				nox_xxx_netReportCharges_4D82B0(*(unsigned char*)(*(uint32_t*)(v13 + 276) + 2064), item,
												*(uint8_t*)(*(uint32_t*)&item->field_184 + 1),
												**(uint8_t**)&item->field_184);
			}
		}
	}
	sub_53A6C0((int)v4, item);
	nox_xxx_decay_5116F0(item);
	return 1;
}

//----- (0053A9C0) --------------------------------------------------------
int nox_xxx_sendMsgOblivionPickup_53A9C0(int a1, nox_object_t* item, int a3, int a4) {
	int v4; // edi
	int v5; // eax

	v4 = sub_53A720(a1, item, a3, a4);
	if (v4 == 1 && *(uint8_t*)(a1 + 8) & 4 && !sub_419E60(a1)) {
		v5 = *(uint32_t*)&item->field_3;
		if (0x800000 & v5) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "weapon.c:PickupHalberdOblivion", 0);
			nox_xxx_aud_501960(914, a1, 0, 0);
		} else if (v5 & 0x1000000) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "weapon.c:PickupHeartOblivion", 0);
			nox_xxx_aud_501960(915, a1, 0, 0);
		} else if (v5 & 0x2000000) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "weapon.c:PickupWierdlingOblivion", 0);
			nox_xxx_aud_501960(916, a1, 0, 0);
		} else if (v5 & 0x4000000) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "weapon.c:PickupOrbOblivion", 0);
			nox_xxx_aud_501960(917, a1, 0, 0);
		}
		sub_57AF30(a1, 1);
		nox_xxx_playerTryEquip_4F2F70((uint32_t*)a1, item);
	}
	return v4;
}

//----- (0053AAB0) --------------------------------------------------------
void sub_53AAB0(int a1) {
	int v2;   // ecx
	short v3; // cx

	if (a1) {
		v2 = *(uint32_t*)(a1 + 8);
		if (v2 & 0x1000) {
			nox_xxx_aud_501960(831, a1, 0, 0);
		} else {
			v3 = *(uint16_t*)(a1 + 24);
			if (v3 & 0x10) {
				nox_xxx_aud_501960(843, a1, 0, 0);
			} else if (v3 & 8) {
				nox_xxx_aud_501960(845, a1, 0, 0);
			}
		}
	}
}

//----- (0053AB10) --------------------------------------------------------
int nox_xxx_dropWeapon_53AB10(int a1, uint32_t* a2, int* a3) {
	if (nox_xxx_dropDefault_4ED290(a1, (int)a2, (float2*)a3) != 1) {
		return 0;
	}
	sub_53AAB0((int)a2);
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096)) {
		if (sub_409F40(2)) {
			nox_xxx_unitSetDecayTime_511660(a2, 25 * nox_gameFPS);
		}
	}
	return 1;
}

//----- (0053AB90) --------------------------------------------------------
void sub_53AB90(int a1, int a2) {
	int v2; // esi
	int v3; // eax

	if (a1) {
		v2 = *(uint32_t*)(a1 + 748);
		if (a2) {
			if (!nox_xxx_playerClassCanUseItem_57B3D0(a2, *(uint8_t*)(*(uint32_t*)(v2 + 276) + 2251)) ||
				(LOBYTE(v3) = nox_xxx_playerCheckStrength_4F3180(a1, a2), !v3)) {
				nox_xxx_netSendSecondaryWeapon_4D9670(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), 0, 1);
			}
		}
		*(uint32_t*)(v2 + 108) = a2;
	}
}
// 53ABD1: variable 'v3' is possibly undefined

//----- (0053AC10) --------------------------------------------------------
void nox_xxx_updateProjectile_53AC10(int a1) {
	void (*v1)(int, uint32_t, uint32_t); // eax

	if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128)) > 0x28) {
		v1 = *(void (**)(int, uint32_t, uint32_t))(a1 + 696);
		if (v1) {
			v1(a1, 0, 0);
		}
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053AC50) --------------------------------------------------------
char nox_xxx_updateDoor_53AC50(int a1) {
	uint32_t* v1; // edi
	int v2;       // ecx
	int v3;       // eax
	int v4;       // eax
	int v5;       // eax
	int v6;       // eax
	int v7;       // edi

	v1 = *(uint32_t**)(a1 + 748);
	v2 = v1[2];
	v3 = v1[1];
	if (v2 == v3) {
		if (v1[3] != v3) {
			v4 = *(uint32_t*)(a1 + 12);
			if (v4 & 4) {
				if (*(uint8_t*)(a1 + 24) & 8) {
					nox_xxx_aud_501960(245, a1, 0, 0);
				} else {
					nox_xxx_aud_501960(241, a1, 0, 0);
				}
			} else if (v4 & 1) {
				nox_xxx_aud_501960(247, a1, 0, 0);
			} else if (v4 & 0x1000) {
				nox_xxx_aud_501960(1014, a1, 0, 0);
			} else {
				nox_xxx_aud_501960(237, a1, 0, 0);
			}
			goto LABEL_24;
		}
		if (v2 == v3) {
			goto LABEL_24;
		}
	}
	if (v1[3] == v3) {
		v5 = *(uint32_t*)(a1 + 12);
		if (v5 & 4) {
			if (*(uint8_t*)(a1 + 24) & 8) {
				nox_xxx_aud_501960(246, a1, 0, 0);
			} else {
				nox_xxx_aud_501960(243, a1, 0, 0);
			}
		} else if (v5 & 1) {
			nox_xxx_aud_501960(248, a1, 0, 0);
		} else if (v5 & 0x1000) {
			nox_xxx_aud_501960(1015, a1, 0, 0);
		} else {
			nox_xxx_aud_501960(239, a1, 0, 0);
		}
		nox_xxx_unitRemoveFromUpdatable_4DA920((uint32_t*)a1);
	}
LABEL_24:
	v6 = v1[3];
	if (v1[2] != v6) {
		nox_xxx_unitNeedSync_4E44F0(a1);
		v6 = v1[3];
		v1[2] = v6;
	}
	if (*(uint32_t*)(a1 + 16) & 0x1000000) {
		if ((unsigned int)(nox_frame_xxx_2598000 - v1[11]) > (int)nox_gameFPS >> 1) {
			v7 = v1[1];
			if (v6 != v7) {
				if (v6 - v7 + (v6 - v7 < 0 ? 0x20 : 0) >= 16) {
					sub_548860(a1, 2);
				} else {
					sub_548860(a1, -2);
				}
				LOBYTE(v6) = nox_xxx_unitHasCollideOrUpdateFn_537610(a1);
			}
		}
	}
	return v6;
}

//----- (0053ADC0) --------------------------------------------------------
void nox_xxx_updateSpark_53ADC0(int a1) {
	int v1; // eax
	int v2; // ecx

	v1 = *(uint32_t*)(a1 + 748);
	v2 = *(uint32_t*)(v1 + 4);
	if (v2 <= 0) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	} else {
		*(uint32_t*)(v1 + 4) = v2 - 1;
		if (*(uint32_t*)(v1 + 12) == 4) {
			*(uint32_t*)(a1 + 112) = 1065353216;
		} else {
			*(uint32_t*)(a1 + 112) = 1064514355;
		}
	}
}

//----- (0053AE00) --------------------------------------------------------
char sub_53AE00(int a1) {
	uint8_t* v1; // esi
	int v2;      // eax
	bool v3;     // zf

	v1 = *(uint8_t**)(a1 + 748);
	if (v1[1]) {
		LOBYTE(v2) = v1[1] - 1;
		if (v1[1] == 1) {
			LOBYTE(v2) = *v1 - 1;
			v3 = *v1 == 1;
			*v1 = v2;
			if (v3) {
				LOWORD(v2) = nox_common_randomInt_415FA0(0, 255);
				*(uint16_t*)(a1 + 126) = v2;
				v1[1] = 0;
				*v1 = 2;
				v1[2] = 0;
			}
		}
	} else {
		v2 = 8 * *(short*)(a1 + 124);
		*(float*)(a1 + 88) = *getMemFloatPtr(0x587000, 194136 + v2) * 4.0;
		*(float*)(a1 + 92) = *getMemFloatPtr(0x587000, 194140 + v2) * 4.0;
		LOBYTE(v2) = *v1 - 1;
		v3 = *v1 == 1;
		*v1 = v2;
		if (v3) {
			LOBYTE(v2) = v1[2] + 1;
			v1[2] = v2;
			if ((uint8_t)v2 == 4) {
				v1[2] = 0;
				v1[1] = 1;
				LOBYTE(v2) = nox_common_randomInt_415FA0(5, 60);
				*v1 = v2;
			} else {
				*v1 = 2;
			}
		}
	}
	return v2;
}

//----- (0053AEC0) --------------------------------------------------------
float* nox_xxx_updateProjTrail_53AEC0(int a1) {
	float* v1;     // esi
	int v2;        // eax
	int v3;        // ebx
	double v4;     // st7
	double v5;     // st7
	int v6;        // edi
	float* result; // eax
	float v8;      // [esp+0h] [ebp-38h]
	float v9;      // [esp+4h] [ebp-34h]
	float v10;     // [esp+10h] [ebp-28h]
	float v11;     // [esp+14h] [ebp-24h]
	float v12;     // [esp+1Ch] [ebp-1Ch]
	float v13;     // [esp+1Ch] [ebp-1Ch]
	float v14;     // [esp+2Ch] [ebp-Ch]
	float v15;     // [esp+30h] [ebp-8h]
	int v16;       // [esp+34h] [ebp-4h]
	float v17;     // [esp+34h] [ebp-4h]
	int v18;       // [esp+3Ch] [ebp+4h]
	float v19;     // [esp+3Ch] [ebp+4h]
	float v20;     // [esp+3Ch] [ebp+4h]

	v1 = (float*)a1;
	v2 = 8 * *(short*)(a1 + 124);
	v3 = 0;
	v4 = *getMemFloatPtr(0x587000, 194136 + v2) * *(float*)(a1 + 544);
	v18 = 0;
	v1[22] = v4 * 0.25 + v1[22];
	v1[23] = *getMemFloatPtr(0x587000, 194140 + v2) * v1[136] * 0.25 + v1[23];
	v14 = (v1[14] - v1[18]) * 0.25;
	v15 = (v1[15] - v1[19]) * 0.25;
	do {
		v5 = (double)v18;
		v19 = v5;
		v12 = v5 * v14 + v1[18];
		v16 = nox_float2int(v12);
		v13 = v19 * v15 + v1[19];
		v6 = 2;
		v20 = (double)nox_float2int(v13);
		v17 = (double)v16;
		do {
			v11 = nox_common_randomFloat_416030(-2.0, 2.0);
			v10 = nox_common_randomFloat_416030(-2.0, 2.0);
			v9 = nox_common_randomFloat_416030(-4.0, 4.0) + v20;
			v8 = nox_common_randomFloat_416030(-4.0, 4.0) + v17;
			result = nox_xxx_createSpark_54FD80(v8, v9, 1, 6, v10, v11, 0.0, (int)v1);
			--v6;
		} while (v6);
		v18 = ++v3;
	} while (v3 < 4);
	return result;
}

//----- (0053B030) --------------------------------------------------------
void nox_xxx_updatePush_53B030(int a1) {
	nox_xxx_mapPushUnitsAround_52E040(a1 + 56, **(float**)(a1 + 748), 0, *(float*)(*(uint32_t*)(a1 + 748) + 8), 0, 0,
									  0);
}

//----- (0053B060) --------------------------------------------------------
char nox_xxx_updateToggle_53B060(uint32_t* a1) {
	unsigned int* v1; // esi
	unsigned int v2;  // eax

	v1 = (unsigned int*)a1[187];
	if (!(a1[4] & 0x1000000)) {
		v2 = *v1;
		LOBYTE(v2) = *v1 & 0xF6;
		*v1 = v2;
		return v2;
	}
	if (!(*(uint8_t*)v1 & 8)) {
		*((uint8_t*)v1 + 8) = 0;
		a1[34] = nox_frame_xxx_2598000;
		nox_xxx_servMarkObjAnimFrame_4E4880((int)a1, 0);
	}
	if (*((uint8_t*)v1 + 8)) {
		if (*((uint8_t*)v1 + 8) != 1) {
			if (*((uint8_t*)v1 + 8) == 3 && nox_frame_xxx_2598000 > a1[34] && !(*(uint8_t*)v1 & 1)) {
				*((uint8_t*)v1 + 8) = 1;
			}
			goto LABEL_18;
		}
		if (nox_frame_xxx_2598000 > a1[34] && *(uint8_t*)v1 & 1) {
			nox_xxx_aud_501960(v1[10], (int)a1, 0, 0);
			nox_xxx_servMarkObjAnimFrame_4E4880((int)a1, 0);
			nox_xxx_scriptCallByEventBlock_502490((int*)v1 + 7, 0, (int)a1, 11);
			*((uint8_t*)v1 + 8) = (*v1 & 2) != 0 ? 5 : 0;
		LABEL_17:
			a1[34] = nox_frame_xxx_2598000 + nox_gameFPS;
			goto LABEL_18;
		}
	} else if (nox_frame_xxx_2598000 > a1[34] && *(uint8_t*)v1 & 1) {
		nox_xxx_aud_501960(v1[9], (int)a1, 0, 0);
		nox_xxx_servMarkObjAnimFrame_4E4880((int)a1, 1);
		nox_xxx_scriptCallByEventBlock_502490((int*)v1 + 5, v1[1], (int)a1, 10);
		*((uint8_t*)v1 + 8) = 3;
		goto LABEL_17;
	}
LABEL_18:
	v2 = *v1;
	if (*v1 & 1) {
		LOBYTE(v2) = v2 | 4;
	} else {
		LOBYTE(v2) = v2 & 0xFB;
	}
	*v1 = v2;
	*v1 = v2 & 0xFFFFFFFE | 8;
	return v2;
}

//----- (0053B1B0) --------------------------------------------------------
char nox_xxx_updateTrigger_53B1B0(int a1) {
	int* v1; // esi
	int v2;  // eax
	int v3;  // ebx
	int v4;  // eax

	v1 = *(int**)(a1 + 748);
	if (!*getMemU32Ptr(0x5D4594, 2488680)) {
		*getMemU32Ptr(0x5D4594, 2488680) = nox_xxx_getNameId_4E3AA0("Trigger");
		*getMemU32Ptr(0x5D4594, 2488676) = nox_xxx_getNameId_4E3AA0("PressurePlate");
	}
	v2 = *(unsigned short*)(a1 + 4);
	if ((unsigned short)v2 == *getMemU32Ptr(0x5D4594, 2488680) || v2 == *getMemU32Ptr(0x5D4594, 2488676)) {
		v3 = 0;
	} else {
		v3 = nox_gameFPS;
	}
	if (*(uint32_t*)(a1 + 16) & 0x1000000) {
		if (!(*(uint8_t*)v1 & 8)) {
			*((uint8_t*)v1 + 8) = 0;
			*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000;
			nox_xxx_servMarkObjAnimFrame_4E4880(a1, 0);
		}
		if (*((uint8_t*)v1 + 8)) {
			if (*((uint8_t*)v1 + 8) == 1 && nox_frame_xxx_2598000 > *(int*)(a1 + 136) && !(*(uint8_t*)v1 & 1)) {
				nox_xxx_aud_501960(v1[10], a1, 0, 0);
				nox_xxx_servMarkObjAnimFrame_4E4880(a1, 0);
				nox_xxx_scriptCallByEventBlock_502490(v1 + 7, 0, a1, 9);
				*((uint8_t*)v1 + 8) = (*v1 & 2) != 0 ? 5 : 0;
			}
		} else if (*(uint8_t*)v1 & 1) {
			nox_xxx_aud_501960(v1[9], a1, 0, 0);
			nox_xxx_servMarkObjAnimFrame_4E4880(a1, 1);
			nox_xxx_scriptCallByEventBlock_502490(v1 + 5, v1[1], a1, 8);
			*((uint8_t*)v1 + 8) = 1;
			*(uint32_t*)(a1 + 136) = v3 + nox_frame_xxx_2598000;
		}
		v4 = *v1;
		if (*v1 & 1) {
			LOBYTE(v4) = v4 | 4;
		} else {
			LOBYTE(v4) = v4 & 0xFB;
		}
		*v1 = v4;
		LOBYTE(v4) = v4 & 0xFE | 8;
		*v1 = v4;
	} else {
		v4 = *v1;
		LOBYTE(v4) = *v1 & 0xF6;
		*v1 = v4;
	}
	return v4;
}

//----- (0053B300) --------------------------------------------------------
char sub_53B300(int a1) {
	int v1; // eax

	v1 = *(uint32_t*)(a1 + 16);
	if (v1 & 0x1000000) {
		LOBYTE(v1) = v1 & 0xBF;
	} else {
		LOBYTE(v1) = v1 | 0x40;
	}
	*(uint32_t*)(a1 + 16) = v1;
	return v1;
}

//----- (0053B320) --------------------------------------------------------
char nox_xxx_updateSwitch_53B320(uint32_t* a1) {
	int v1; // eax

	v1 = a1[4];
	if (v1 & 0x1000000) {
		if (a1[174] && v1 & 0x40) {
			LOBYTE(v1) = v1 & 0xBF;
			a1[4] = v1;
			LOBYTE(v1) = nox_xxx_unitHasCollideOrUpdateFn_537610((int)a1);
		} else {
			LOBYTE(v1) = v1 & 0xBF;
			a1[4] = v1;
		}
	} else {
		if (!a1[33]) {
			nox_xxx_unitNeedSync_4E44F0((int)a1);
			a1[33] = 1;
		}
		v1 = a1[4];
		LOBYTE(v1) = v1 | 0x40;
		a1[4] = v1;
	}
	return v1;
}

//----- (0053B380) --------------------------------------------------------
char nox_xxx_updateElevatorShaft_53B380(int a1) {
	int v1; // esi
	int v2; // eax
	int v3; // edi

	v1 = *(uint32_t*)(a1 + 748);
	v2 = *(uint32_t*)(v1 + 4);
	if (v2) {
		nox_xxx_unitHasCollideOrUpdateFn_537610(a1);
		v3 = *(uint32_t*)(*(uint32_t*)(v1 + 4) + 748);
		if (*(uint8_t*)(v3 + 12) == 1) {
			if (*(uint32_t*)(v3 + 16) <= 32) {
				nox_xxx_unitsGetInCircle_517F90((float2*)(a1 + 56), 64.0, nox_xxx_fnElevatorShaft_53B410, a1);
			}
			if (*(uint8_t*)(v1 + 12) != *(uint8_t*)(v3 + 12)) {
				nox_xxx_elevatorAud_53B490(a1, 0);
			}
		} else if (*(uint8_t*)(v3 + 12) == 3 && *(uint8_t*)(v1 + 12) != *(uint8_t*)(v3 + 12)) {
			nox_xxx_elevatorAud_53B490(a1, 1);
			LOBYTE(v2) = *(uint8_t*)(v3 + 12);
			*(uint8_t*)(v1 + 12) = v2;
			return v2;
		}
		LOBYTE(v2) = *(uint8_t*)(v3 + 12);
		*(uint8_t*)(v1 + 12) = v2;
	}
	return v2;
}

//----- (0053B410) --------------------------------------------------------
void nox_xxx_fnElevatorShaft_53B410(int a1, int a2) {
	int v2;   // edi
	int v3;   // ebx
	float v4; // [esp+0h] [ebp-10h]
	float v5; // [esp+0h] [ebp-10h]

	if (nox_xxx_map_57B850((float2*)(a2 + 56), (float*)(a2 + 172), (float2*)(a1 + 56))) {
		v2 = *(uint32_t*)(a2 + 748);
		v3 = *(uint32_t*)(*(uint32_t*)(v2 + 4) + 748);
		v4 = *(float*)(a1 + 104) + 64.0 - (double)*(int*)(v3 + 16);
		if (sub_419A10(v4) < 10.0) {
			nox_xxx_unitMove_4E7010(a1, (float2*)(*(uint32_t*)(v2 + 4) + 56));
			v5 = (double)*(int*)(v3 + 16);
			nox_xxx_unitRaise_4E46F0(a1, v5);
		}
	}
}

//----- (0053B490) --------------------------------------------------------
uint32_t* nox_xxx_elevatorAud_53B490(int a1, int a2) {
	uint32_t* result; // eax
	int v3;           // ecx
	int v4;           // ecx
	int v5;           // ecx
	int v6;           // ecx

	if (a2) {
		result = (uint32_t*)a1;
		v3 = *(unsigned short*)(a1 + 24);
		if ((unsigned short)v3 == 8) {
			result = nox_xxx_aud_501960(257, a1, 0, 0);
		} else if (v3 == 16) {
			v4 = *(uint32_t*)(a1 + 12);
			if (v4 & 0x20) {
				result = nox_xxx_aud_501960(253, a1, 0, 0);
			} else if (v4 & 0x40) {
				result = nox_xxx_aud_501960(259, a1, 0, 0);
			} else {
				result = nox_xxx_aud_501960(251, a1, 0, 0);
			}
		} else if (v3 == 32) {
			if (*(uint8_t*)(a1 + 12) & 2) {
				result = nox_xxx_aud_501960(255, a1, 0, 0);
			} else {
				result = nox_xxx_aud_501960(249, a1, 0, 0);
			}
		}
	} else {
		result = (uint32_t*)a1;
		v5 = *(unsigned short*)(a1 + 24);
		if ((unsigned short)v5 == 8) {
			result = nox_xxx_aud_501960(258, a1, 0, 0);
		} else if (v5 == 16) {
			v6 = *(uint32_t*)(a1 + 12);
			if (v6 & 0x20) {
				result = nox_xxx_aud_501960(254, a1, 0, 0);
			} else if (v6 & 0x40) {
				result = nox_xxx_aud_501960(260, a1, 0, 0);
			} else {
				result = nox_xxx_aud_501960(252, a1, 0, 0);
			}
		} else if (v5 == 32) {
			if (*(uint8_t*)(a1 + 12) & 2) {
				result = nox_xxx_aud_501960(256, a1, 0, 0);
			} else {
				result = nox_xxx_aud_501960(250, a1, 0, 0);
			}
		}
	}
	return result;
}

//----- (0053B5D0) --------------------------------------------------------
void nox_xxx_updateElevator_53B5D0(uint32_t* a1) {
	int v1; // esi
	int v2; // eax
	int v3; // eax
	int v4; // eax

	v1 = a1[187];
	switch (*(unsigned char*)(v1 + 12)) {
	case 0u:
		if (a1[4] & 0x1000000) {
			if ((unsigned int)(nox_frame_xxx_2598000 - a1[34]) > (int)nox_gameFPS) {
				*(uint8_t*)(v1 + 12) = 3;
				nox_xxx_elevatorAud_53B490((int)a1, 1);
			}
		}
		break;
	case 1u:
		v2 = *(uint32_t*)(v1 + 16);
		if (v2 > 0) {
			*(uint32_t*)(v1 + 16) = v2 - 2;
		} else {
			*(uint8_t*)(v1 + 12) = 0;
			a1[34] = nox_frame_xxx_2598000;
		}
		nox_xxx_unitNeedSync_4E44F0((int)a1);
		if (*(uint32_t*)(v1 + 4)) {
			nox_xxx_unitNeedSync_4E44F0(*(uint32_t*)(v1 + 4));
		}
		if ((double)*(int*)(v1 + 16) <= 20.0) {
			v3 = a1[4];
			LOBYTE(v3) = v3 | 0x10;
			a1[4] = v3;
		}
		break;
	case 2u:
		if (a1[4] & 0x1000000 && (unsigned int)(nox_frame_xxx_2598000 - a1[34]) > (int)nox_gameFPS) {
			*(uint8_t*)(v1 + 12) = 1;
			nox_xxx_elevatorAud_53B490((int)a1, 0);
		}
		break;
	case 3u:
		*(uint32_t*)(v1 + 16) += 2;
		nox_xxx_unitNeedSync_4E44F0((int)a1);
		if (*(uint32_t*)(v1 + 4)) {
			nox_xxx_unitNeedSync_4E44F0(*(uint32_t*)(v1 + 4));
		}
		if ((double)*(int*)(v1 + 16) >= 20.0) {
			v4 = a1[4];
			LOBYTE(v4) = v4 & 0xEF;
			a1[4] = v4;
		}
		if ((double)*(int*)(v1 + 16) >= 32.0) {
			nox_xxx_unitsGetInCircle_517F90((float2*)a1 + 7, 64.0, nox_xxx_elevatorFn_53B750, (int)a1);
		}
		if (*(uint32_t*)(v1 + 16) >= 64) {
			*(uint32_t*)(v1 + 16) = 64;
			*(uint8_t*)(v1 + 12) = 2;
			a1[34] = nox_frame_xxx_2598000;
		}
		break;
	default:
		return;
	}
}

//----- (0053B750) --------------------------------------------------------
void nox_xxx_elevatorFn_53B750(int a1, int a2) {
	int v2;    // ebx
	int v3;    // edi
	int v4;    // eax
	double v5; // st7
	float v6;  // [esp+0h] [ebp-10h]
	float v7;  // [esp+0h] [ebp-10h]

	if (nox_xxx_map_57B850((float2*)(a2 + 56), (float*)(a2 + 172), (float2*)(a1 + 56))) {
		v2 = *(uint32_t*)(a2 + 748);
		v3 = *(uint32_t*)(v2 + 4);
		if (v3) {
			v6 = *(float*)(a1 + 104) - (double)*(int*)(v2 + 16);
			if (sub_419A10(v6) < 10.0) {
				v4 = *(uint32_t*)(a1 + 172);
				if (v4 == 3) {
					if (*(float*)(v3 + 184) < (double)*(float*)(a1 + 184) ||
						*(float*)(v3 + 188) < (double)*(float*)(a1 + 188)) {
					LABEL_12:
						*(uint32_t*)(a1 + 16) &= 0xFFEFFFFF;
						nox_xxx_unitRaise_4E46F0(a1, 0.0);
						return;
					}
				} else if (v4 == 2) {
					v5 = *(float*)(a1 + 176) + *(float*)(a1 + 176);
					if (v5 > *(float*)(v3 + 184) || v5 > *(float*)(v3 + 188)) {
						goto LABEL_12;
					}
				}
				nox_xxx_unitMove_4E7010(a1, (float2*)(*(uint32_t*)(v2 + 4) + 56));
				v7 = (double)(int)(*(uint32_t*)(v2 + 16) - 64);
				nox_xxx_unitRaise_4E46F0(a1, v7);
				return;
			}
		}
	}
}

//----- (0053B860) --------------------------------------------------------
void nox_xxx_updatePhantomPlayer_53B860(int a1) {
	float* v1; // edx
	double v2; // st7
	double v3; // st6
	int v4;    // edx
	short v5;  // ax
	bool v6;   // sf
	float v7;  // [esp+8h] [ebp-4h]

	v1 = *(float**)(a1 + 748);
	v2 = *(float*)(*(uint32_t*)v1 + 56) - v1[1];
	v3 = *(float*)(*(uint32_t*)v1 + 60) - v1[2];
	v7 = v3;
	if (v3 * v7 + v2 * v2 <= 160000.0) {
		*(float*)(a1 + 64) = *(float*)(*(uint32_t*)v1 + 56) - v2;
		*(float*)(a1 + 68) = *(float*)(*(uint32_t*)v1 + 60) - v7;
		v4 = *(uint32_t*)v1;
		v5 = *(uint16_t*)(v4 + 124) + 128;
		v6 = (short)(*(uint16_t*)(v4 + 124) - 128) < 0;
		*(uint16_t*)(a1 + 126) = v5;
		while (*(uint16_t*)(a1 + 126) >= 256) {
			*(uint16_t*)(a1 + 126) -= 256;
		}
	} else {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053B8F0) --------------------------------------------------------
void nox_xxx_updateLifetime_53B8F0(int unit) {
	void (*deleteOverride)(int); // ecx

	if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(unit + 128)) > **(uint32_t**)(unit + 748)) {
		deleteOverride = *(void (**)(int))(unit + 724);
		*(uint32_t*)(unit + 16) |= 0x8000u;
		if (deleteOverride) {
			deleteOverride(unit);
		} else {
			nox_xxx_delayedDeleteObject_4E5CC0(unit);
		}
	}
}

//----- (0053B940) --------------------------------------------------------
void nox_xxx_spellFlyUpdate_53B940(int a1) {
	int v1;     // edi
	int* v2;    // esi
	double v3;  // st7
	int v4;     // eax
	int v5;     // eax
	int v6;     // eax
	int v7;     // eax
	int v8;     // eax
	int v9;     // esi
	double v10; // st7
	double v11; // st7
	double v12; // st6
	double v13; // st7
	double v14; // st6
	float v15;  // [esp+4h] [ebp-10h]
	int v16;    // [esp+4h] [ebp-10h]
	float v17;  // [esp+10h] [ebp-4h]
	float v18;  // [esp+18h] [ebp+4h]

	v1 = a1;
	v2 = *(int**)(a1 + 748);
	if (v2[1]) {
		v3 = nox_xxx_gamedataGetFloat_419D40("TargetedSpellLifetime");
	} else {
		v3 = nox_xxx_gamedataGetFloat_419D40("UnTargetedSpellLifetime");
	}
	v15 = v3;
	if (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128) <= (unsigned int)nox_float2int(v15)) {
		if (*v2 && *(uint8_t*)(*v2 + 16) & 0x20) {
			*v2 = 0;
		}
		v4 = v2[2];
		if (v4 && *(uint8_t*)(v4 + 16) & 0x20) {
			v2[2] = 0;
		}
		v5 = v2[1];
		if (v5) {
			v6 = *(uint32_t*)(v5 + 16);
			if (v6 & 0x20 || (v6 & 0x8000) != 0) {
				v2[1] = 0;
			}
		}
		if (!v2[1]) {
			v7 = *(uint32_t*)(a1 + 136);
			if ((unsigned int)(nox_frame_xxx_2598000 - v7) > (int)nox_gameFPS >> 2 || v7 == *(uint32_t*)(a1 + 128)) {
				v16 = *v2;
				v8 = nox_xxx_spellFlags_424A70(v2[3]);
				v2[1] = nox_xxx_spellFlySearchTarget_540610(0, a1, v8, 600.0, 0, v16);
				*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000;
			}
		}
		v9 = v2[1];
		if (v9) {
			v18 = *(float*)(v9 + 56) - *(float*)(a1 + 56);
			v10 = *(float*)(v9 + 60) - *(float*)(v1 + 60);
			v17 = v10;
			v11 = nox_double2float(sqrt(v10 * v17 + v18 * v18) + *(double*)&qword_581450_10176);
			v12 = v18 * *(float*)(v1 + 544);
			*(uint32_t*)(v1 + 112) = 1063675494;
			*(float*)(v1 + 88) = v12 / v11;
			*(float*)(v1 + 92) = v17 * *(float*)(v1 + 544) / v11;
		} else {
			v13 = nox_double2float(
				sqrt(*(float*)(a1 + 80) * *(float*)(a1 + 80) + *(float*)(a1 + 84) * *(float*)(a1 + 84)) +
				*(double*)&qword_581450_10176);
			v14 = *(float*)(a1 + 544) * *(float*)(a1 + 80);
			*(uint32_t*)(a1 + 112) = 1063675494;
			*(float*)(a1 + 88) = v14 / v13;
			*(float*)(a1 + 92) = *(float*)(a1 + 544) * *(float*)(a1 + 84) / v13;
		}
	} else {
		nox_xxx_netSendPointFx_522FF0(150, (float2*)(a1 + 56));
		sub_4E71F0(a1);
	}
}

//----- (0053BB00) --------------------------------------------------------
void nox_xxx_updateAntiSpellProj_53BB00(int a1) {
	int v1;          // ecx
	int v2;          // esi
	int v3;          // edi
	unsigned int v4; // eax
	int v5;          // edx
	int v6;          // eax
	double v7;       // st7
	double v8;       // st6
	double v9;       // st5
	long double v10; // st7
	long double v11; // st7
	float v12;       // [esp+0h] [ebp-30h]
	float v13;       // [esp+4h] [ebp-2Ch]
	int v14;         // [esp+Ch] [ebp-24h]
	float v15;       // [esp+10h] [ebp-20h]
	float v16;       // [esp+14h] [ebp-1Ch]
	float v17;       // [esp+2Ch] [ebp-4h]
	int v18;         // [esp+34h] [ebp+4h]

	v1 = nox_frame_xxx_2598000;
	v2 = a1;
	v3 = *(uint32_t*)(a1 + 748);
	v4 = nox_gameFPS;
	if (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128) <= (unsigned int)(5 * nox_gameFPS)) {
		v5 = *(uint32_t*)(v3 + 4);
		if (v5 && *(uint8_t*)(v5 + 16) & 0x20) {
			*(uint32_t*)(v3 + 4) = 0;
			v1 = nox_frame_xxx_2598000;
			v4 = nox_gameFPS;
		}
		if (!*(uint32_t*)(v3 + 4) && v1 - *(uint32_t*)(a1 + 136) > v4 >> 2) {
			*getMemU32Ptr(0x5D4594, 2488668) = 0;
			*getMemU32Ptr(0x5D4594, 2488672) = 1287568416;
			sub_518170(a1 + 56, 600.0, sub_53BD10, a1);
			*(uint32_t*)(v3 + 4) = *getMemU32Ptr(0x5D4594, 2488668);
			*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000;
		}
		v6 = *(uint32_t*)(v3 + 4);
		if (v6) {
			v7 = *(float*)(v6 + 56) - *(float*)(a1 + 56);
			v8 = *(float*)(v6 + 60) - *(float*)(a1 + 60);
			v9 = v7;
			v10 = sqrt(v8 * v8 + v7 * v7) + 0.1;
			*(float*)(a1 + 88) = v9 * *(float*)(a1 + 544) / v10;
			*(float*)(a1 + 92) = v8 * *(float*)(a1 + 544) / v10;
			if (v10 < 10.0) {
				nox_xxx_aud_501960(20, a1, 0, 0);
				nox_xxx_delayedDeleteObject_4E5CC0(a1);
				nox_xxx_delayedDeleteObject_4E5CC0(*(uint32_t*)(v3 + 4));
			}
		} else {
			v11 = sqrt(*(float*)(a1 + 80) * *(float*)(a1 + 80) + *(float*)(a1 + 84) * *(float*)(a1 + 84)) + 0.1;
			*(float*)(a1 + 88) = *(float*)(a1 + 544) * *(float*)(a1 + 80) / v11;
			*(float*)(a1 + 92) = *(float*)(a1 + 544) * *(float*)(a1 + 84) / v11;
		}
		v17 = *(float*)(a1 + 56);
		v18 = *(int*)(a1 + 60);
		v16 = nox_common_randomFloat_416030(-2.0, 2.0);
		v15 = nox_common_randomFloat_416030(-2.0, 2.0);
		v14 = nox_common_randomInt_415FA0(15, 30);
		v13 = nox_common_randomFloat_416030(-4.0, 4.0) + *(float*)&v18;
		v12 = nox_common_randomFloat_416030(-4.0, 4.0) + v17;
		nox_xxx_createSpark_54FD80(v12, v13, 3, v14, v15, v16, 0.0, v2);
	} else {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053BD10) --------------------------------------------------------
void sub_53BD10(int a1, int a2) {
	double v2; // st7
	double v3; // st6
	double v4; // st5

	if (!(*(uint8_t*)(a1 + 16) & 0x20) && (!(*(uint8_t*)(a1 + 8) & 1) || *(uint8_t*)(a1 + 12) & 2) && a2 != a1 &&
		(!*(uint32_t*)(a2 + 508) || !nox_xxx_unitHasThatParent_4EC4F0(a1, *(uint32_t*)(a2 + 508)))) {
		if (nox_xxx_unitCanInteractWith_5370E0(a2, a1, 0)) {
			v2 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
			v3 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
			v4 = v3 * v3 + v2 * v2;
			if (v4 < *getMemFloatPtr(0x5D4594, 2488672)) {
				*getMemFloatPtr(0x5D4594, 2488672) = v4;
				*getMemU32Ptr(0x5D4594, 2488668) = a1;
			}
		}
	}
}

//----- (0053BDA0) --------------------------------------------------------
int nox_xxx_updateMagicMissile_53BDA0(int a1) {
	int* v1;    // edi
	int v2;     // ecx
	int v3;     // eax
	int v4;     // eax
	int v5;     // eax
	int v6;     // edi
	short v7;   // cx
	short v8;   // ax
	int result; // eax
	double v10; // st7

	v1 = *(int**)(a1 + 748);
	v2 = *v1;
	if ((*(uint8_t*)(*v1 + 16) & 0x20) || (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128) > (unsigned int)(3 * nox_gameFPS))) {
		return (*(int (**)(int, uint32_t, uint32_t))(a1 + 696))(a1, 0, 0);
	}
	v3 = v1[1];
	if (v3) {
		v4 = *(uint32_t*)(v3 + 16);
		if (((v4 & 0x20) != 0) || ((v4 & 0x8000) != 0)) {
			v1[1] = 0;
		}
	}
	if (!v1[1] && !((unsigned char)nox_frame_xxx_2598000 & 7)) {
		v5 = nox_xxx_spellFlySearchTarget_540610(0, a1, 32, 600.0, 0, v2);
		v1[1] = v5;
		if (v5 == *(uint32_t*)(a1 + 508)) {
			v1[1] = 0;
		}
	}
	v6 = v1[1];
	if (v6) {
		v7 = *(uint16_t*)(a1 + 126);
		if ((*(float*)(v6 + 60) - *(float*)(a1 + 60)) * *getMemFloatPtr(0x587000, 194136 + 8 * v7) -
				(*(float*)(v6 + 56) - *(float*)(a1 + 56)) * *getMemFloatPtr(0x587000, 194140 + 8 * v7) >=
			0.0) {
			*(uint16_t*)(a1 + 126) = v7 + 42;
			if ((short)(v7 + 42) >= 256) {
				do {
					*(uint16_t*)(a1 + 126) -= 256;
				} while (*(uint16_t*)(a1 + 126) >= 256);
			}
		} else {
			v8 = v7 - 42;
			*(uint16_t*)(a1 + 126) = v7 - 42;
			if ((short)(v7 - 42) < 0) {
				do {
					v8 += 256;
				} while (v8 < 0);
				*(uint16_t*)(a1 + 126) = v8;
			}
		}
	}
	result = 8 * *(short*)(a1 + 126);
	*(float*)(a1 + 88) = *getMemFloatPtr(0x587000, 194136 + result) * *(float*)(a1 + 544);
	v10 = *getMemFloatPtr(0x587000, 194140 + result) * *(float*)(a1 + 544);
	*(uint32_t*)(a1 + 112) = 1061997773;
	*(float*)(a1 + 92) = v10;
	return result;
}

//----- (0053BEF0) --------------------------------------------------------
int nox_xxx_updateTeleportPentagram_53BEF0(int a1) {
	unsigned char* v1; // esi
	unsigned char v2;  // al
	unsigned char v3;  // al
	int result;        // eax
	int v5;            // eax
	uint8_t* v6;       // eax
	float4 a1a;        // [esp+Ch] [ebp-10h]

	v1 = *(unsigned char**)(a1 + 748);
	if (*v1) {
		if (*v1 <= 2u) {
			v2 = v1[9];
			if (v2 == v1[8]) {
				++v1[20];
				nox_xxx_unitNeedSync_4E44F0(a1);
				if (v1[20] == 9) {
					v3 = v1[8];
					v1[20] = 1;
					v1[8] = v3 + 1;
				}
				v1[9] = 0;
			} else {
				v1[9] = v2 + 1;
			}
		}
	} else {
		if (v1[20]) {
			nox_xxx_unitNeedSync_4E44F0(a1);
		}
		v1[20] = 0;
	}
	result = *v1;
	if (*v1) {
		v5 = result - 1;
		if (v5) {
			result = v5 - 1;
			if (!result && v1[8] >= 4u) {
				v1[20] = 0;
				*v1 = 0;
				*((uint32_t*)v1 + 1) = 0;
				return result;
			}
		} else {
			result = v1[8];
			if ((uint8_t)result) {
				if ((uint8_t)result == 4) {
					*v1 = 0;
					*((uint32_t*)v1 + 1) = 0;
					return result;
				}
			} else if (v1[20] == 8) {
				result = *((uint32_t*)v1 + 3);
				if (result) {
					a1a.field_0 = *(float*)(a1 + 56) - *(float*)(a1 + 176);
					a1a.field_4 = *(float*)(a1 + 60) - *(float*)(a1 + 176);
					a1a.field_8 = *(float*)(a1 + 56) + *(float*)(a1 + 176);
					a1a.field_C = *(float*)(a1 + 60) + *(float*)(a1 + 176);
					nox_xxx_getUnitsInRect_517C10(&a1a, nox_xxx_fnPentagramTeleport_53C060, result + 56);
					*((uint32_t*)v1 + 1) = 0;
					return result;
				}
			}
		}
	} else if (*((uint32_t*)v1 + 1)) {
		result = *((uint32_t*)v1 + 3);
		if (result) {
			if (*(uint32_t*)(a1 + 16) & 0x1000000) {
				v6 = *(uint8_t**)(result + 748);
				*v1 = 1;
				v1[8] = 0;
				v1[9] = 0;
				*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000;
				*v6 = 2;
				v6[8] = 0;
				v6[9] = 0;
				result = nox_frame_xxx_2598000;
				*(uint32_t*)(*((uint32_t*)v1 + 3) + 136) = nox_frame_xxx_2598000;
			}
		}
	}
	*((uint32_t*)v1 + 1) = 0;
	return result;
}

//----- (0053C060) --------------------------------------------------------
void nox_xxx_fnPentagramTeleport_53C060(float* a1, int a2) {
	if (!((uint32_t)a1[2] & 0x420000)) {
		nox_xxx_netSendPointFx_522FF0(137, (float2*)a1 + 7);
		nox_xxx_aud_501960(147, (int)a1, 0, 0);
		nox_xxx_teleportToMB_4E7190(a1, (float*)a2);
		nox_xxx_netSendPointFx_522FF0(137, (float2*)a1 + 7);
		nox_xxx_aud_501960(147, (int)a1, 0, 0);
	}
}

//----- (0053C0C0) --------------------------------------------------------
int nox_xxx_updateInvisiblePentagram_53C0C0(int a1) {
	int result; // eax
	int v2;     // esi
	int v3;     // ecx
	float4 a1a; // [esp+8h] [ebp-10h]

	result = a1;
	v2 = *(uint32_t*)(a1 + 748);
	if (*(uint32_t*)(v2 + 4)) {
		v3 = *(uint32_t*)(v2 + 12);
		if (v3) {
			if (*(uint32_t*)(a1 + 16) & 0x1000000) {
				a1a.field_0 = *(float*)(a1 + 56) - *(float*)(a1 + 176);
				a1a.field_4 = *(float*)(a1 + 60) - *(float*)(a1 + 176);
				a1a.field_8 = *(float*)(a1 + 176) + *(float*)(a1 + 56);
				a1a.field_C = *(float*)(a1 + 60) + *(float*)(a1 + 176);
				nox_xxx_getUnitsInRect_517C10(&a1a, sub_53C140, v3 + 56);
			}
		}
	}
	*(uint32_t*)(v2 + 4) = 0;
	return result;
}

//----- (0053C140) --------------------------------------------------------
void sub_53C140(float* a1, int a2) {
	if (!((uint32_t)a1[2] & 0x420000)) {
		nox_xxx_teleportToMB_4E7190(a1, (float*)a2);
	}
}

//----- (0053C160) --------------------------------------------------------
void nox_xxx_updateBlow_53C160(int a3) {
	double v1; // st7
	float v2;  // eax
	float v3;  // edx
	double v4; // st7
	float v5;  // ecx
	double v6; // st7
	float v7;  // eax
	int2 a2;   // [esp+4h] [ebp-18h]
	float4 a1; // [esp+Ch] [ebp-10h]

	if (*(uint32_t*)(a3 + 16) & 0x1000000) {
		nox_xxx_xferIndexedDirection_509E20(*(short*)(a3 + 124), &a2);
		if (a2.field_0 >= 0) {
			if (a2.field_4 < 0) {
				v4 = *(float*)(a3 + 60) - 400.0;
				v5 = *(float*)(a3 + 60);
				a1.field_0 = *(float*)(a3 + 56);
				a1.field_C = v5;
				a1.field_4 = v4;
				a1.field_8 = *(float*)(a3 + 56) + 400.0;
				goto LABEL_10;
			}
			v6 = *(float*)(a3 + 56) + 400.0;
			v7 = *(float*)(a3 + 60);
			a1.field_0 = *(float*)(a3 + 56);
			a1.field_4 = v7;
			a1.field_8 = v6;
		} else {
			a1.field_0 = *(float*)(a3 + 56) - 400.0;
			if (a2.field_4 < 0) {
				v1 = *(float*)(a3 + 60) - 400.0;
				v2 = *(float*)(a3 + 60);
				a1.field_8 = *(float*)(a3 + 56);
				a1.field_C = v2;
				a1.field_4 = v1;
			LABEL_10:
				nox_xxx_getUnitsInRectAdv_517ED0(&a1, sub_53C240, a3);
				return;
			}
			v3 = *(float*)(a3 + 56);
			a1.field_4 = *(float*)(a3 + 60);
			a1.field_8 = v3;
		}
		a1.field_C = *(float*)(a3 + 60) + 400.0;
		goto LABEL_10;
	}
}

//----- (0053C240) --------------------------------------------------------
void sub_53C240(float* a1, int arg4) {
	float* v2;      // esi
	int v3;         // edi
	double v4;      // st7
	long double v5; // st7
	double v6;      // st7
	double v7;      // st7
	double v8;      // st7
	double v9;      // st7
	float v10;      // [esp+8h] [ebp-10h]
	float v11;      // [esp+Ch] [ebp-Ch]
	int2 a2;        // [esp+10h] [ebp-8h]
	float v13;      // [esp+1Ch] [ebp+4h]
	float v14;      // [esp+1Ch] [ebp+4h]
	float v15;      // [esp+20h] [ebp+8h]
	float v16;      // [esp+20h] [ebp+8h]

	v2 = a1;
	if (!((uint8_t)a1[4] & 0x20) && !((uint32_t)a1[2] & 0x400000)) {
		v3 = arg4;
		v15 = a1[14] - *(float*)(arg4 + 56);
		v4 = a1[15] - *(float*)(v3 + 60);
		v13 = v4;
		v5 = sqrt(v4 * v13 + v15 * v15) + 0.1;
		v11 = v5;
		if (v5 < 400.0) {
			nox_xxx_xferIndexedDirection_509E20(*(short*)(v3 + 124), &a2);
			v6 = v15;
			if (v15 >= 0.0) {
				v10 = v15;
			} else {
				v10 = -v6;
			}
			if (v13 >= 0.0) {
				v16 = v13;
			} else {
				v16 = -v13;
			}
			switch (a2.field_4 + a2.field_0 + 2 * a2.field_4 + 4) {
			case 0:
				if (v6 < 0.0) {
					goto LABEL_12;
				}
				break;
			case 1:
				if (v13 < 0.0) {
					goto LABEL_29;
				}
				break;
			case 2:
				if (v6 > 0.0) {
				LABEL_12:
					if (v13 < 0.0) {
						goto LABEL_25;
					}
				}
				break;
			case 3:
				if (v6 < 0.0) {
					goto LABEL_21;
				}
				break;
			case 5:
				if (v6 > 0.0) {
				LABEL_21:
					if (v16 / v10 <= 0.26789999) {
						goto LABEL_35;
					}
				}
				break;
			case 6:
				if (v6 < 0.0 && v13 > 0.0) {
				LABEL_25:
					v7 = v16 / v10;
					if (v7 >= 0.57730001 && v7 <= 0.1732) {
						goto LABEL_35;
					}
				}
				break;
			case 7:
				if (v13 > 0.0) {
				LABEL_29:
					if (v16 / v10 <= 0.3732) {
						goto LABEL_35;
					}
				}
				break;
			case 8:
				if (v6 > 0.0 && v13 > 0.0) {
					v8 = v16 / v10;
					if (v8 >= 0.57730001 && v8 <= 0.1732) {
						goto LABEL_35;
					}
				}
				break;
			default:
			LABEL_35:
				if (nox_xxx_unitCanInteractWith_5370E0(v3, (int)v2, 0)) {
					v14 = (400.0 - v11) * (400.0 - v11) * (400.0 - v11) * 0.0000005;
					v9 = v14 / nox_xxx_objectGetMass_4E4A70((int)v2);
					v2[22] = v9 * *getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(v3 + 124)) + v2[22];
					v2[23] = v9 * *getMemFloatPtr(0x587000, 194140 + 8 * *(short*)(v3 + 124)) + v2[23];
				}
				break;
			}
		}
	}
}

//----- (0053C520) --------------------------------------------------------
int nox_xxx_rechargeItem_53C520(int a1, int a2) {
	int v2; // ecx
	int v3; // eax
	int v4; // eax
	int v5; // edx

	v2 = *(uint32_t*)(a1 + 736);
	if (!v2) {
		return 0;
	}
	v3 = *(uint32_t*)(v2 + 112);
	if (v3 >= 100) {
		return 0;
	}
	v4 = a2 + v3;
	*(uint32_t*)(v2 + 112) = v4 < 100 ? v4 : 100;
	v5 = *(uint32_t*)(v2 + 112) * *(unsigned char*)(v2 + 109) / 100;
	if (v5 == *(unsigned char*)(v2 + 108)) {
		return 0;
	}
	*(uint8_t*)(v2 + 108) = v5;
	return 1;
}

//----- (0053C580) --------------------------------------------------------
signed int nox_xxx_updateObelisk_53C580(int a1) {
	int v1;             // edi
	signed int* v2;     // esi
	int v3;             // ebp
	int v4;             // eax
	int v5;             // esi
	double v6;          // st7
	double v7;          // st6
	int v8;             // ebp
	uint32_t* v9;       // eax
	int v10;            // ecx
	int v11;            // ebx
	short v12;          // bx
	char v13;           // al
	short v14;          // ax
	int v15;            // eax
	unsigned short v16; // ax
	int v17;            // edx
	signed int result;  // eax
	float v19;          // [esp+0h] [ebp-20h]
	float v20;          // [esp+4h] [ebp-1Ch]
	int v21;            // [esp+14h] [ebp-Ch]
	int v22;            // [esp+18h] [ebp-8h]
	signed int v23;     // [esp+1Ch] [ebp-4h]
	signed int* v24;    // [esp+24h] [ebp+4h]

	v1 = a1;
	v23 = 1;
	v2 = *(signed int**)(a1 + 748);
	v24 = *(signed int**)(a1 + 748);
	v3 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	v21 = v3;
	if (!v3) {
		goto LABEL_50;
	}
	while (1) {
		v4 = *(uint32_t*)(v3 + 16);
		if ((v4 & 0x8000) != 0) {
			goto LABEL_47;
		}
		v5 = *(uint32_t*)(v3 + 748);
		if (nox_xxx_servObjectHasTeam_419130(v1 + 48)) {
			if (!nox_xxx_servCompareTeams_419150(v1 + 48, v3 + 48)) {
				goto LABEL_47;
			}
		}
		v6 = *(float*)(v1 + 56) - *(float*)(v3 + 56);
		v7 = *(float*)(v1 + 60) - *(float*)(v3 + 60);
		v22 = 0;
		if (v7 * v7 + v6 * v6 >= 2500.0 || !nox_xxx_mapCheck_537110(v1, v3)) {
			goto LABEL_47;
		}
		v23 = 0;
		if (*v24 >= 1) {
			v8 = nox_xxx_getRechargeRate_53C940(*(uint32_t**)(v5 + 104));
			if (!nox_common_gameFlags_check_40A5C0(0x2000) || nox_common_gameFlags_check_40A5C0(4096)) {
				if (!v8) {
				LABEL_24:
					v3 = v21;
					goto LABEL_25;
				}
			} else {
				v8 = 1;
			}
			v9 = *(uint32_t**)(v5 + 104);
			if (v9) {
				v10 = v9[2];
				if (v10 & 0x1000) {
					if (v9[3] & 0x47F0000) {
						v11 = v9[184];
						if (*(int*)(v11 + 112) < 100) {
							if (nox_common_gameFlags_check_40A5C0(4096)) {
								if (!(nox_frame_xxx_2598000 % (nox_gameFPS >> 1))) {
									nox_xxx_aud_501960(230, v1, 0, 0);
								}
							} else {
								v22 = 1;
								--*v24;
							}
							if (nox_xxx_rechargeItem_53C520(*(uint32_t*)(v5 + 104), v8)) {
								nox_xxx_netReportCharges_4D82B0(*(unsigned char*)(*(uint32_t*)(v5 + 276) + 2064),
																*(uint32_t**)(v5 + 104), *(uint8_t*)(v11 + 108),
																*(uint8_t*)(v11 + 109));
							}
						}
					}
				}
			}
			goto LABEL_24;
		}
	LABEL_25:
		if ((int)*v24 < 1 || *(uint16_t*)(v5 + 4) >= *(uint16_t*)(v5 + 8) || (int)*v24 <= 0) {
			goto LABEL_42;
		}
		v12 = 1;
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			v13 = *(uint8_t*)(*(uint32_t*)(v5 + 276) + 2251);
			if (v13) {
				if (v13 == 1) {
					v14 = nox_float2int(*(float*)&nox_xxx_wizardMaximumMana_587000_312820);
				} else {
					if (v13 != 2) {
						goto LABEL_36;
					}
					v14 = nox_float2int(*(float*)&nox_xxx_conjurerMaxMana_587000_312804);
				}
			} else {
				v14 = nox_float2int(*(float*)&nox_xxx_warriorMaxMana_587000_312788);
			}
			v12 = v14;
		}
	LABEL_36:
		v15 = *(uint32_t*)(v5 + 276);
		*(uint16_t*)(v5 + 4) += v12;
		nox_xxx_protectMana_56F9E0(*(uint32_t*)(v15 + 4596), v12);
		v16 = *(uint16_t*)(v5 + 8);
		if (*(uint16_t*)(v5 + 4) > v16) {
			v17 = *(uint32_t*)(v5 + 276);
			*(uint16_t*)(v5 + 4) = v16;
			nox_xxx_protectPlayerHPMana_56F870(*(uint32_t*)(v17 + 4596), v16);
		}
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			if (!(nox_frame_xxx_2598000 % (nox_gameFPS >> 1))) {
				nox_xxx_aud_501960(230, v1, 0, 0);
			}
		LABEL_42:
			if (!v22) {
				goto LABEL_47;
			}
			goto LABEL_43;
		}
		--*v24;
	LABEL_43:
		if (!(*v24 % 8)) {
			v19 = (double)(80 * *v24 / 50);
			nullsub_35(v1, LODWORD(v19));
			nox_xxx_unitNeedSync_4E44F0(v1);
		}
		if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(v1 + 136)) > (int)nox_gameFPS >> 1) {
			nox_xxx_aud_501960(230, v1, 0, 0);
			*(uint32_t*)(v1 + 136) = nox_frame_xxx_2598000;
		}
	LABEL_47:
		v21 = nox_xxx_getNextPlayerUnit_4DA7F0(v3);
		if (!v21) {
			break;
		}
		v3 = v21;
	}
	result = v23;
	if (v23) {
		v2 = v24;
	LABEL_50:
		result = nox_frame_xxx_2598000 / (nox_gameFPS >> 1);
		if (!(nox_frame_xxx_2598000 % (nox_gameFPS >> 1))) {
			result = *v2;
			if ((int)*v2 < 50) {
				if (!(result % 8)) {
					v20 = (double)(80 * result / 50);
					nullsub_35(v1, LODWORD(v20));
					result = nox_xxx_unitNeedSync_4E44F0(v1);
				}
				++*v2;
			}
		}
	}
	return result;
}
// 4E4770: using guessed type void  nullsub_35(uint32_t, uint32_t);

//----- (0053C940) --------------------------------------------------------
int nox_xxx_getRechargeRate_53C940(uint32_t* a1) {
	int v1;     // ecx
	int result; // eax
	int v3;     // edx
	int* i;     // ecx
	int v5;     // eax
	float v6;   // [esp+0h] [ebp-4h]

	if (!a1) {
		return 0;
	}
	v1 = a1[2];
	if (v1 & 0x1000 && a1[3] & 0x4000000) {
		v6 = nox_xxx_gamedataGetFloat_419D40("OblivionStaffRechargeRate");
		result = nox_float2int(v6);
	} else {
		v3 = 2;
		for (i = (int*)(a1[173] + 8);; ++i) {
			v5 = *i;
			if (*i) {
				if (*(int (**)())(v5 + 40) == nullsub_36) {
					break;
				}
			}
			if (++v3 >= 4) {
				return 0;
			}
		}
		result = *(uint32_t*)(v5 + 48);
	}
	return result;
}
// 4E09D0: using guessed type void nullsub_36();

//----- (0053C9A0) --------------------------------------------------------
void nox_xxx_updateBlackPowderBarrel_53C9A0(float* a1) {
	float* v1;     // ebx
	int v2;        // ecx
	int v3;        // edx
	float* v4;     // esi
	float v5;      // ecx
	int v6;        // ebp
	int v7;        // edi
	int v8;        // eax
	uint32_t* v9;  // eax
	uint32_t* v10; // edi
	int v11;       // eax
	float4 v12;    // [esp+4h] [ebp-10h]
	float v13;     // [esp+18h] [ebp+4h]

	v1 = a1;
	v2 = *((uint32_t*)a1 + 34);
	v3 = *((uint32_t*)a1 + 32);
	if (v2 == v3) {
		*((uint32_t*)a1 + 34) = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(1, 5);
	} else if (v2 == nox_frame_xxx_2598000) {
		if (!*getMemU32Ptr(0x5D4594, 2488684)) {
			*getMemU32Ptr(0x5D4594, 2488684) = nox_xxx_getNameId_4E3AA0("SmallFlame");
			*getMemU32Ptr(0x5D4594, 2488688) = nox_xxx_getNameId_4E3AA0("MediumFlame");
		}
		v4 = a1 + 14;
		nox_xxx_mapDamageUnitsAround_4E25B0((int)(a1 + 14), 100.0, 30.0, 30, 7, (int)a1, 0);
		nox_xxx_mapPushUnitsAround_52E040((int)(a1 + 14), 100.0, 1106247680, 60.0, (int)a1, 0, 0);
		v5 = a1[15];
		v12.field_0 = a1[14];
		v12.field_4 = v5;
		v6 = 4;
		do {
			v7 = nox_common_randomInt_415FA0(0, 1);
			v13 = nox_common_randomFloat_416030(0.0, 15.0) + 10.0;
			v8 = nox_common_randomInt_415FA0(0, 255);
			v12.field_8 = v13 * *getMemFloatPtr(0x587000, 194136 + 8 * v8) + *v4;
			v12.field_C = v13 * *getMemFloatPtr(0x587000, 194140 + 8 * v8) + v1[15];
			if (nox_xxx_mapTraceRay_535250(&v12, 0, 0, 1)) {
				v9 = nox_xxx_newObjectWithTypeInd_4E3450(*getMemU32Ptr(0x5D4594, 2488684 + 4 * v7));
				v10 = v9;
				if (v9) {
					nox_xxx_createAt_4DAA50((int)v9, 0, v12.field_8, v12.field_C);
					v11 = nox_common_randomInt_415FA0(5, 20);
					nox_xxx_unitSetDecayTime_511660(v10, nox_gameFPS * v11);
				}
			}
			--v6;
		} while (v6);
	} else if ((unsigned int)(nox_frame_xxx_2598000 - v3) >= (int)nox_gameFPS) {
		nox_xxx_delayedDeleteObject_4E5CC0((int)a1);
	}
}

//----- (0053CB60) --------------------------------------------------------
void nox_xxx_updateOneSecondDie_53CB60(int a1) {
	if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128)) >= (int)nox_gameFPS) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053CB90) --------------------------------------------------------
void nox_xxx_updateWaterBarrel_53CB90(int a1) {
	unsigned int v1; // eax
	float4 a1a;      // [esp+4h] [ebp-10h]

	v1 = nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128);
	if (v1 == 8) {
		*getMemU32Ptr(0x5D4594, 2488664) = 0;
		a1a.field_0 = *(float*)(a1 + 56) - 40.0;
		a1a.field_4 = *(float*)(a1 + 60) - 40.0;
		a1a.field_8 = *(float*)(a1 + 56) + 40.0;
		a1a.field_C = *(float*)(a1 + 60) + 40.0;
		nox_xxx_getUnitsInRect_517C10(&a1a, nox_xxx_waterBarrel_53CC30, a1 + 56);
		if (*getMemU32Ptr(0x5D4594, 2488664)) {
			nox_xxx_aud_501960(283, a1, 0, 0);
		}
	} else if (v1 >= 0x1E) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053CC30) --------------------------------------------------------
void nox_xxx_waterBarrel_53CC30(float* a1, int a2) {
	int v2;    // eax
	double v3; // st7
	double v4; // st6

	v2 = *((uint32_t*)a1 + 2);
	if (v2 & 0x2000) {
		v3 = *(float*)a2 - a1[14];
		v4 = *(float*)(a2 + 4) - a1[15];
		if (sqrt(v4 * v4 + v3 * v3) - a1[44] <= 40.0) {
			nox_xxx_delayedDeleteObject_4E5CC0((int)a1);
			*getMemU32Ptr(0x5D4594, 2488664) = 1;
		}
	}
}

//----- (0053CC90) --------------------------------------------------------
void nox_xxx_updateSelfDestruct_53CC90(int a1) {
	if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128)) > 2) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053CCB0) --------------------------------------------------------
void nox_xxx_updateBlackPowderBurn_53CCB0(int a1) {
	int v1; // edx
	int v2; // esi

	v1 = *(uint32_t*)(a1 + 136);
	v2 = *(uint32_t*)(a1 + 128);
	if (v1 == v2) {
		*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000 + 3;
	} else if (v1 == nox_frame_xxx_2598000) {
		nox_xxx_mapDamageUnitsAround_4E25B0(a1 + 56, 15.0, 15.0, 1, 1, a1, 0);
	} else if (nox_frame_xxx_2598000 - v2 >= (unsigned int)(2 * nox_gameFPS)) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053CD20) --------------------------------------------------------
void nox_xxx_updatePixie_53CD20(nox_object_t* obj) {
	int v19;         // eax
	float2 a2;       // [esp+10h] [ebp-18h]
	float4 a1a;      // [esp+18h] [ebp-10h]

	void* ud = obj->data_update;
	uint32_t* v1 = ud;
	if (!*getMemU32Ptr(0x5D4594, 2488696)) {
		int dt = (int)nox_xxx_gamedataGetFloat_419D40("PixieReturnTimeout");
		*getMemU32Ptr(0x5D4594, 2488696) = nox_gameFPS * dt;
	}
	unsigned int v4 = v1[5];
	if (nox_frame_xxx_2598000 > v4 && v4) {
		nox_xxx_delayedDeleteObject_4E5CC0(obj);
		return;
	}
	int v6 = v1[1];
	if (v6) {
		int v7 = *(uint32_t*)(v6 + 16);
		if (((v7 & 0x20) != 0) || ((v7 & 0x8000) != 0)) {
			v1[1] = 0;
		}
	}
	if (obj->flags & 0x1000000) {
		if ((nox_frame_xxx_2598000 - obj->field_34) > (nox_gameFPS / 4)) {
			int v8 = sub_533570(obj);
			v1[1] = v8;
			if (v8 == obj->owner) {
				v1[1] = 0;
			}
			obj->field_34 = nox_frame_xxx_2598000;
		}
	} else {
		v1[1] = 0;
	}
	int v9 = obj->owner;
	if (v9 && (*(uint8_t*)(v9 + 8) & 4) == 4 && (*(uint8_t*)(v9 + 16) & 2) == 2) {
		v1[1] = 0;
	}
	if (!v1[1]) {
		sub_518170(&obj->x, *getMemFloatPtr(0x587000, 277804), sub_53D010, obj);
		int v12 = obj->owner;
		if (obj->owner) {
			a1a.field_0 = obj->x;
			a1a.field_4 = obj->y;
			a1a.field_8 = *(float*)(v12 + 56);
			a1a.field_C = *(float*)(v12 + 60);
			if (!nox_xxx_mapTraceRay_535250(&a1a, 0, 0, 9)) {
				goto LABEL_29;
			}
			int v14 = obj->owner;
			a2.field_0 = *(float*)(v14 + 56) - obj->x;
			a2.field_4 = *(float*)(v14 + 60) - obj->y;
		} else {
			a1a.field_0 = obj->x;
			a1a.field_4 = obj->y;
			a1a.field_8 = obj->float_39;
			a1a.field_C = obj->float_40;
			if (!nox_xxx_mapTraceRay_535250(&a1a, 0, 0, 9)) {
				goto LABEL_29;
			}
			a2.field_0 = obj->float_39 - obj->x;
			a2.field_4 = obj->float_40 - obj->y;
		}
		nox_xxx_pixieIdleAnimate_53CF90(obj, &a2, 25);
		goto LABEL_29;
	}
	a2.field_0 = *(float*)(v1[1] + 56) - obj->x;
	a2.field_4 = *(float*)(v1[1] + 60) - obj->y;
	nox_xxx_pixieIdleAnimate_53CF90(obj, &a2, 32);
LABEL_29:
	v19 = 8 * obj->direction;
	obj->float_28 = 0.9;
	obj->force_x = *getMemFloatPtr(0x587000, 194136 + v19) * obj->speed_cur;
	obj->force_y = *getMemFloatPtr(0x587000, 194140 + v19) * obj->speed_cur;
	if (((unsigned char)nox_frame_xxx_2598000 & 8) && obj->owner) {
		if (nox_xxx_mapCheck_537110(obj, obj->owner) == 1) {
			v1[6] = nox_frame_xxx_2598000;
		}
		if ((unsigned int)(nox_frame_xxx_2598000 - v1[6]) > *getMemIntPtr(0x5D4594, 2488696)) {
			nox_xxx_teleportPixie_4FD050(obj, obj->owner);
			v1[6] = nox_frame_xxx_2598000;
		}
	}
}

//----- (0053CF90) --------------------------------------------------------
short nox_xxx_pixieIdleAnimate_53CF90(nox_object_t* a1p, float2* a2, short a3) {
	int a1 = a1p;
	short v3;     // dx
	short result; // ax

	v3 = *(uint16_t*)(a1 + 126);
	if (*getMemFloatPtr(0x587000, 194136 + 8 * v3) * a2->field_4 -
			*getMemFloatPtr(0x587000, 194140 + 8 * v3) * a2->field_0 >=
		0.0) {
		result = v3 + a3;
		*(uint16_t*)(a1 + 126) = v3 + a3;
		if ((short)(v3 + a3) >= 256) {
			result = -256;
			do {
				*(uint16_t*)(a1 + 126) -= 256;
			} while (*(uint16_t*)(a1 + 126) >= 256);
		}
	} else {
		result = v3 - a3;
		*(uint16_t*)(a1 + 126) = v3 - a3;
		if ((short)(v3 - a3) < 0) {
			do {
				result += 256;
			} while (result < 0);
			*(uint16_t*)(a1 + 126) = result;
		}
	}
	return result;
}

//----- (0053D010) --------------------------------------------------------
short sub_53D010(int a1, int a2) {
	int v2;     // eax
	float2 a2a; // [esp+0h] [ebp-8h]

	v2 = *getMemU32Ptr(0x5D4594, 2488692);
	if (!*getMemU32Ptr(0x5D4594, 2488692)) {
		v2 = nox_xxx_getNameId_4E3AA0("Pixie");
		*getMemU32Ptr(0x5D4594, 2488692) = v2;
	}
	if (*(unsigned short*)(a1 + 4) == v2) {
		LOWORD(v2) = a2;
		if (a1 != a2 && *(uint32_t*)(a2 + 508) == *(uint32_t*)(a1 + 508)) {
			a2a.field_0 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
			a2a.field_4 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
			LOWORD(v2) = nox_xxx_pixieIdleAnimate_53CF90(a2, &a2a, 16);
		}
	}
	return v2;
}

//----- (0053D080) --------------------------------------------------------
void nox_xxx_updateDeathBall_53D080(int a1) {
	int v1;   // esi
	int v2;   // ebx
	int v3;   // eax
	float v4; // [esp+0h] [ebp-1Ch]
	float v5; // [esp+8h] [ebp-14h]
	float v6; // [esp+18h] [ebp-4h]
	float v7; // [esp+20h] [ebp+4h]

	v1 = a1;
	v2 = nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128);
	if (nox_frame_xxx_2598000 % (nox_gameFPS / 3u)) {
		*getMemU32Ptr(0x5D4594, 2488700) = 0;
		v4 = nox_xxx_gamedataGetFloat_419D40("DeathBallCancelRange");
		sub_518170(a1 + 56, v4, sub_53D170, a1);
		if (*getMemU32Ptr(0x5D4594, 2488700) == 1) {
			nox_xxx_sMakeScorch_537AF0((int*)(a1 + 56), 1);
			nox_xxx_delayedDeleteObject_4E5CC0(a1);
		}
	}
	if (v2 > 10) {
		v6 = nox_xxx_gamedataGetFloat_419D40("DeathBallOutRadius");
		v7 = nox_xxx_gamedataGetFloat_419D40("DeathBallInRadius");
		v5 = nox_xxx_gamedataGetFloat_419D40("DeathBallNearbyDamage");
		v3 = nox_float2int(v5);
		nox_xxx_mapDamageUnitsAround_4E25B0(v1 + 56, v6, v7, v3, 2, v1, 0);
	}
	if (v2 > 4 * nox_gameFPS) {
		nox_xxx_delayedDeleteObject_4E5CC0(v1);
	}
}

//----- (0053D170) --------------------------------------------------------
void sub_53D170(int a1, int a2) {
	int v2;   // eax
	int v3;   // eax
	int v4;   // eax
	float v5; // edx
	float v6; // [esp-14h] [ebp-24h]
	int4 a1a; // [esp+0h] [ebp-10h]

	v2 = *getMemU32Ptr(0x5D4594, 2488704);
	if (!*getMemU32Ptr(0x5D4594, 2488704)) {
		v2 = nox_xxx_getNameId_4E3AA0("DeathBall");
		*getMemU32Ptr(0x5D4594, 2488704) = v2;
	}
	if (a1 != a2 && *(unsigned short*)(a1 + 4) == v2 && nox_xxx_mapCheck_537110(a2, a1)) {
		*getMemU32Ptr(0x5D4594, 2488700) = 1;
		if (!(*(uint8_t*)(a1 + 16) & 0x20)) {
			a1a.field_0 = nox_float2int(*(float*)(a2 + 56));
			v3 = nox_float2int(*(float*)(a2 + 60));
			v6 = *(float*)(a1 + 56);
			a1a.field_4 = v3;
			v4 = nox_float2int(v6);
			v5 = *(float*)(a1 + 60);
			a1a.field_8 = v4;
			a1a.field_C = nox_float2int(v5);
			nox_xxx_netSendFxGreenBolt_523790(&a1a, 10);
			nox_xxx_sMakeScorch_537AF0((int*)(a1 + 56), 1);
			nox_xxx_delayedDeleteObject_4E5CC0(a1);
		}
	}
}

//----- (0053D220) --------------------------------------------------------
void nox_xxx_updateDeathBallFragment_53D220(int a1) {
	int v1; // esi

	v1 = nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128);
	if (v1 > 10) {
		nox_xxx_mapDamageUnitsAround_4E25B0(a1 + 56, 25.0, 0.0, 20, 2, a1, 0);
	}
	if (v1 > 2 * nox_gameFPS) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053D270) --------------------------------------------------------
void nox_xxx_updateMoonglow_53D270(int a1) {
	int v1;    // eax
	int v2;    // ecx
	float2 v3; // [esp+4h] [ebp-8h]

	v1 = *(uint32_t*)(a1 + 508);
	if (v1) {
		if (*(uint8_t*)(v1 + 8) & 4) {
			v2 = *(uint32_t*)(v1 + 748);
			if (*(uint8_t*)(v1 + 16) & 0x20 ||
				nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128) > (unsigned int)(300 * nox_gameFPS)) {
				nox_xxx_delayedDeleteObject_4E5CC0(a1);
				nox_xxx_spellBuffOff_4FF5B0(*(uint32_t*)(a1 + 508), 1);
			} else {
				v3.field_0 = (double)*(int*)(*(uint32_t*)(v2 + 276) + 2284);
				v3.field_4 = (double)*(int*)(*(uint32_t*)(v2 + 276) + 2288);
				if (sub_517590(v3.field_0, v3.field_4)) {
					nox_xxx_unitMove_4E7010(a1, &v3);
				}
			}
		}
	} else {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053D330) --------------------------------------------------------
void nox_xxx_updateTelekinesis_53D330(int a1) {
	int v1;    // eax
	int v2;    // ecx
	int v3;    // eax
	int v4;    // [esp-Ch] [ebp-20h]
	float4 v5; // [esp+4h] [ebp-10h]

	v1 = *(uint32_t*)(a1 + 508);
	v2 = *(uint32_t*)(v1 + 748);
	if (*(uint32_t*)(v1 + 16) & 0x8020 ||
		nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128) > (unsigned int)(20 * nox_gameFPS)) {
		v4 = *(uint32_t*)(a1 + 508);
		v3 = nox_xxx_spellGetAud44_424800(127, 2);
		nox_xxx_aud_501960(v3, v4, 0, 0);
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
		nox_xxx_spellBuffOff_4FF5B0(*(uint32_t*)(a1 + 508), 24);
	} else {
		v5.field_8 = (double)*(int*)(*(uint32_t*)(v2 + 276) + 2284);
		v5.field_C = (double)*(int*)(*(uint32_t*)(v2 + 276) + 2288);
		v5.field_0 = *(float*)(v1 + 56);
		v5.field_4 = *(float*)(v1 + 60);
		if (nox_xxx_mapTraceRay_535250(&v5, 0, 0, 5)) {
			nox_xxx_unitMove_4E7010(a1, (float2*)&v5.field_8);
		}
	}
}

//----- (0053D400) --------------------------------------------------------
void nox_xxx_updateFist_53D400(int a1) {
	double v1; // st7
	double v2; // st7
	double v3; // st7
	float2 a2; // [esp+4h] [ebp-8h]

	if (*(float*)(a1 + 104) <= 0.0 && (int)*(uint32_t*)(a1 + 16) >= 0) {
		nox_xxx_aud_501960(48, a1, 0, 0);
		nox_xxx_sMakeScorch_537AF0((int*)(a1 + 56), 2);
		v1 = *(float*)(a1 + 176) + *(float*)(a1 + 56);
		*(uint32_t*)(a1 + 16) |= 0x80000000;
		a2.field_4 = *(float*)(a1 + 60);
		a2.field_0 = v1;
		nox_xxx_netSendPointFx_522FF0(138, &a2);
		v2 = *(float*)(a1 + 56) - *(float*)(a1 + 176);
		a2.field_4 = *(float*)(a1 + 60);
		a2.field_0 = v2;
		nox_xxx_netSendPointFx_522FF0(138, &a2);
		v3 = *(float*)(a1 + 176) + *(float*)(a1 + 60);
		a2.field_0 = *(float*)(a1 + 56);
		a2.field_4 = v3;
		nox_xxx_netSendPointFx_522FF0(138, &a2);
		nox_xxx_earthquakeSend_4D9110((float*)(a1 + 56), 30);
	}
	if (*(float*)(a1 + 104) >= 200.0 && *(int*)(a1 + 16) < 0) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
	if (nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128) > (unsigned int)(3 * nox_gameFPS)) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053D510) --------------------------------------------------------
void nox_xxx_updateFlameCleanse_53D510(int a1) {
	float v1;  // ecx
	float v2;  // eax
	float v3;  // ecx
	float4 v4; // [esp+4h] [ebp-10h]

	if (nox_frame_xxx_2598000 >= *(int*)(a1 + 136) ||
		(v1 = *(float*)(a1 + 156), v2 = *(float*)(a1 + 56), v4.field_4 = *(float*)(a1 + 160), v4.field_0 = v1,
		 v3 = *(float*)(a1 + 60), v4.field_8 = v2, v4.field_C = v3, !nox_xxx_mapTraceRay_535250(&v4, 0, 0, 65)) ||
		(unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128)) > 3 &&
			*(float*)(a1 + 72) == *(float*)(a1 + 56) && *(float*)(a1 + 76) == *(float*)(a1 + 60)) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053D5A0) --------------------------------------------------------
void nox_xxx_updateMeteorShower_53D5A0(float* a2) {
	uint32_t* v1; // ebx
	int v2;       // edi
	double v3;    // st7
	double v4;    // st7
	float v5;     // edx
	double v6;    // st6
	double v7;    // st7
	uint32_t* v8; // eax
	int v9;       // edi
	float a3;     // [esp+8h] [ebp-18h]
	float a4;     // [esp+Ch] [ebp-14h]
	float4 a1;    // [esp+10h] [ebp-10h]

	if (nox_frame_xxx_2598000 - *((uint32_t*)a2 + 32) < (unsigned int)(5 * nox_gameFPS)) {
		if (*((uint32_t*)a2 + 34) <= nox_frame_xxx_2598000) {
			v1 = (uint32_t*)*((uint32_t*)a2 + 187);
			v2 = nox_common_randomInt_415FA0(0, 255);
			v3 = nox_common_randomFloat_416030(4.0, 12.0);
			v4 = v3 * v3;
			v5 = a2[15];
			a1.field_0 = a2[14];
			v6 = v4 * *getMemFloatPtr(0x587000, 194136 + 8 * v2);
			a1.field_4 = v5;
			a3 = v6 + a2[14];
			v7 = v4 * *getMemFloatPtr(0x587000, 194140 + 8 * v2);
			a1.field_8 = a3;
			a4 = v7 + a2[15];
			a1.field_C = a4;
			if ((unsigned char)nox_xxx_traceRay_5374B0(&a1)) {
				v8 = nox_xxx_newObjectByTypeID_4E3810("Meteor");
				v9 = (int)v8;
				if (v8) {
					*(uint32_t*)v8[187] = *v1;
					nox_xxx_createAt_4DAA50((int)v8, (int)a2, a3, a4);
					*(uint32_t*)(v9 + 20) |= 0x20u;
					nox_xxx_unitRaise_4E46F0(v9, 255.0);
					*(uint32_t*)(v9 + 108) = -1056964608;
				}
			}
			*((uint32_t*)a2 + 34) = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(4, 8);
		}
	} else {
		nox_xxx_delayedDeleteObject_4E5CC0((int)a2);
	}
}

//----- (0053D6E0) --------------------------------------------------------
void nox_xxx_meteorExplode_53D6E0(int a6) {
	int* v1;      // ebx
	float* v2;    // edi
	uint32_t* v3; // eax
	int v4;       // eax
	float v5;     // [esp+4h] [ebp-20h]
	float v6;     // [esp+8h] [ebp-1Ch]
	float v7;     // [esp+Ch] [ebp-18h]
	float v8;     // [esp+10h] [ebp-14h]
	int4 a1;      // [esp+14h] [ebp-10h]

	if (*(float*)(a6 + 104) <= 0.0) {
		v1 = *(int**)(a6 + 748);
		nox_xxx_aud_501960(87, a6, 0, 0);
		v2 = (float*)(a6 + 56);
		nox_xxx_sMakeScorch_537AF0((int*)(a6 + 56), 2);
		nox_xxx_earthquakeSend_4D9110((float*)(a6 + 56), 10);
		v3 = nox_xxx_newObjectByTypeID_4E3810("MeteorExplode");
		if (v3) {
			nox_xxx_createAt_4DAA50((int)v3, 0, *v2, *(float*)(a6 + 60));
		}
		v4 = nox_xxx_findParentChainPlayer_4EC580(a6);
		nox_xxx_mapDamageUnitsAround_4E25B0(a6 + 56, 80.0, 30.0, *v1, 7, v4, 0);
		v5 = *v2 - 80.0;
		v6 = *(float*)(a6 + 60) - 80.0;
		v7 = *v2 + 80.0;
		v8 = *(float*)(a6 + 60) + 80.0;
		a1.field_0 = nox_float2int(v5) / 23;
		a1.field_4 = nox_float2int(v6) / 23;
		a1.field_8 = nox_float2int(v7) / 23;
		a1.field_C = nox_float2int(v8) / 23;
		nox_xxx_mapDamageToWalls_534FC0(&a1, a6 + 56, 80.0, *v1, 7, a6);
		nox_xxx_delayedDeleteObject_4E5CC0(a6);
	}
}

//----- (0053D850) --------------------------------------------------------
void nox_xxx_updateToxicCloud_53D850(int a1) {
	uint32_t* v1; // esi

	v1 = *(uint32_t**)(a1 + 748);
	if (*(uint32_t*)(a1 + 136) < nox_frame_xxx_2598000) {
		nox_xxx_unitsGetInCircle_517F90((float2*)(a1 + 56), 75.0, sub_53D8C0, a1);
		*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(5, 10);
	}
	if (*v1) {
		--*v1;
	}
	if (!*v1) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053D8C0) --------------------------------------------------------
void sub_53D8C0(int a1, int a2) {
	float v2;  // edx
	float v3;  // eax
	float v4;  // eax
	int v5;    // eax
	int v6;    // eax
	int v7;    // [esp-8h] [ebp-20h]
	float4 v8; // [esp+8h] [ebp-10h]

	if (*(uint8_t*)(a1 + 8) & 6) {
		v2 = *(float*)(a1 + 56);
		v3 = *(float*)(a2 + 56);
		v8.field_4 = *(float*)(a2 + 60);
		v8.field_0 = v3;
		v4 = *(float*)(a1 + 60);
		v8.field_8 = v2;
		v8.field_C = v4;
		if (nox_xxx_mapTraceRay_535250(&v8, 0, 0, 5)) {
			v7 = nox_common_randomInt_415FA0(3, 10);
			v5 = nox_xxx_findParentChainPlayer_4EC580(a2);
			(*(void (**)(int, int, int, int, int))(a1 + 716))(a1, v5, a2, v7, 5);
			v6 = nox_xxx_findParentChainPlayer_4EC580(a2);
			if (nox_xxx_unitIsEnemyTo_5330C0(v6, a1)) {
				nox_xxx_activatePoison_4EE7E0(a1, 1, 1);
			}
		}
	}
}

//----- (0053D960) --------------------------------------------------------
void nox_xxx_updateSmallToxicCloud_53D960(int a1) {
	uint32_t* v1; // esi

	v1 = *(uint32_t**)(a1 + 748);
	if (*(uint32_t*)(a1 + 136) < nox_frame_xxx_2598000) {
		nox_xxx_unitsGetInCircle_517F90((float2*)(a1 + 56), 35.0, nox_xxx_toxicCloudPoison_53D9D0, a1);
		*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(5, 10);
	}
	if (*v1) {
		--*v1;
	}
	if (!*v1) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053D9D0) --------------------------------------------------------
void nox_xxx_toxicCloudPoison_53D9D0(int a1, int a2) {
	float v2;  // edx
	float v3;  // eax
	float v4;  // eax
	int v5;    // eax
	int v6;    // eax
	float4 v7; // [esp+8h] [ebp-10h]

	if (*(uint8_t*)(a1 + 8) & 6) {
		v2 = *(float*)(a1 + 56);
		v3 = *(float*)(a2 + 56);
		v7.field_4 = *(float*)(a2 + 60);
		v7.field_0 = v3;
		v4 = *(float*)(a1 + 60);
		v7.field_8 = v2;
		v7.field_C = v4;
		if (nox_xxx_mapTraceRay_535250(&v7, 0, 0, 5)) {
			v5 = nox_xxx_findParentChainPlayer_4EC580(a2);
			(*(void (**)(int, int, int, uint32_t, int))(a1 + 716))(a1, v5, a2, 0, 5);
			v6 = nox_xxx_findParentChainPlayer_4EC580(a2);
			if (nox_xxx_unitIsEnemyTo_5330C0(v6, a1)) {
				nox_xxx_activatePoison_4EE7E0(a1, 1, 1);
			}
		}
	}
}

//----- (0053DA60) --------------------------------------------------------
void nox_xxx_updateArachnaphobia_53DA60(int* a1) {
	int v1;       // eax
	int v2;       // eax
	uint32_t* v3; // eax

	v1 = nox_frame_xxx_2598000;
	if ((unsigned int)a1[34] < nox_frame_xxx_2598000) {
		v2 = *getMemU32Ptr(0x5D4594, 2488708);
		if (!*getMemU32Ptr(0x5D4594, 2488708)) {
			v2 = nox_xxx_getNameId_4E3AA0("SmallSpider");
			*getMemU32Ptr(0x5D4594, 2488708) = v2;
		}
		v3 = nox_xxx_newObjectWithTypeInd_4E3450(v2);
		if (v3) {
			nox_xxx_createAt_4DAA50((int)v3, a1[127], *((float*)a1 + 14), *((float*)a1 + 15));
		}
		a1[34] = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(1, 5);
		v1 = nox_frame_xxx_2598000;
	}
	if (v1 - a1[32] > (unsigned int)(3 * nox_gameFPS)) {
		nox_xxx_delayedDeleteObject_4E5CC0((int)a1);
	}
}

//----- (0053DB00) --------------------------------------------------------
void nox_xxx_updateExpire_53DB00(int a1) {
	if (*(uint32_t*)(a1 + 128) > nox_frame_xxx_2598000 || *(uint32_t*)(a1 + 136) < nox_frame_xxx_2598000) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053DB30) --------------------------------------------------------
int* nox_xxx_updateBreak_53DB30(uint32_t* a1) {
	int* result; // eax

	result = (int*)a1[5];
	if ((unsigned char)result & 2) {
		result = (int*)a1[4];
		if (SBYTE1(result) < 0) {
			nox_xxx_unitUnsetXStatus_4E4780((int)a1, 2);
			nox_xxx_unitSetXStatus_4E4800((int)a1, (int*)4);
			result = (int*)a1[4];
			LOBYTE(result) = (unsigned char)result | 0x40;
			a1[34] = nox_frame_xxx_2598000 + 2 * nox_gameFPS;
			a1[4] = result;
		}
	} else if ((unsigned char)result & 4) {
		result = nox_frame_xxx_2598000;
		if (nox_frame_xxx_2598000 > a1[34]) {
			nox_xxx_unitUnsetXStatus_4E4780((int)a1, 4);
			result = nox_xxx_unitSetXStatus_4E4800((int)a1, (int*)8);
		}
	} else if ((unsigned char)result & 8) {
		result = nox_xxx_unitRemoveFromUpdatable_4DA920(a1);
	}
	return result;
}

//----- (0053DBB0) --------------------------------------------------------
int* nox_xxx_updateOpen_53DBB0(uint32_t* a1) {
	int* result; // eax

	result = (int*)a1[5];
	if ((unsigned char)result & 2) {
		result = (int*)a1[4];
		if (SBYTE1(result) < 0) {
			nox_xxx_unitUnsetXStatus_4E4780((int)a1, 2);
			nox_xxx_unitSetXStatus_4E4800((int)a1, (int*)4);
			result = nox_frame_xxx_2598000;
			a1[34] = nox_frame_xxx_2598000 + 2 * nox_gameFPS;
		}
	} else if ((unsigned char)result & 4) {
		result = nox_frame_xxx_2598000;
		if (nox_frame_xxx_2598000 > a1[34]) {
			nox_xxx_unitUnsetXStatus_4E4780((int)a1, 4);
			result = nox_xxx_unitSetXStatus_4E4800((int)a1, (int*)8);
		}
	} else if ((unsigned char)result & 8) {
		result = nox_xxx_unitRemoveFromUpdatable_4DA920(a1);
	}
	return result;
}

//----- (0053DC30) --------------------------------------------------------
void nox_xxx_updateBreakAndRemove_53DC30(uint32_t* a1) {
	int v1; // eax
	int v2; // eax

	switch (a1[5]) {
	case 2:
		v1 = a1[4];
		if ((v1 & 0x8000) != 0) {
			nox_xxx_unitUnsetXStatus_4E4780((int)a1, 2);
			nox_xxx_unitSetXStatus_4E4800((int)a1, (int*)4);
			a1[34] = nox_frame_xxx_2598000 + 2 * nox_gameFPS;
			v2 = a1[4];
			LOBYTE(v2) = v2 | 0x40;
			a1[4] = v2;
		}
		break;
	case 4:
		if (nox_frame_xxx_2598000 > a1[34]) {
			nox_xxx_unitUnsetXStatus_4E4780((int)a1, 4);
			nox_xxx_unitSetXStatus_4E4800((int)a1, (int*)8);
		}
		break;
	case 8:
		nox_xxx_unitRemoveFromUpdatable_4DA920(a1);
		nox_xxx_delayedDeleteObject_4E5CC0((int)a1);
		break;
	}
}

//----- (0053DCC0) --------------------------------------------------------
void nox_xxx_updateChakramInMotion_53DCC0(int a1) {
	int v1;    // edi
	int v2;    // esi
	int v3;    // eax
	int v4;    // eax
	int v5;    // eax
	int v6;    // eax
	int v7;    // eax
	double v8; // st7
	double v9; // st6
	float v10; // [esp+Ch] [ebp-4h]
	float v11; // [esp+14h] [ebp+4h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 748);
	v3 = nox_xxx_inventoryGetFirst_4E7980(a1);
	if (!v3 || *(uint8_t*)(v3 + 16) & 0x20) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
		return;
	}
	v4 = *(uint32_t*)(v2 + 12);
	if (v4 && *(uint8_t*)(v4 + 16) & 0x20) {
		*(uint32_t*)(v2 + 12) = 0;
	}
	v5 = *(uint32_t*)(a1 + 508);
	if (!v5 || *(uint8_t*)(v5 + 16) & 0x20) {
		*(uint8_t*)(v2 + 24) = 1;
		*(uint32_t*)(v2 + 8) = 0;
	} else {
		*(uint32_t*)(v2 + 16) = *(uint32_t*)(v5 + 56);
		*(uint32_t*)(v2 + 20) = *(uint32_t*)(v5 + 60);
		if (!nox_xxx_mapCheck_537110(a1, *(uint32_t*)(a1 + 508))) {
			*(uint32_t*)(v2 + 8) = 0;
		LABEL_12:
			if (!*(uint8_t*)(v2 + 24)) {
				v6 = *(uint32_t*)(v2 + 8);
				if (v6 && ((v7 = *(uint32_t*)(v6 + 16), v7 & 0x20) || (v7 & 0x8000) != 0)) {
					*(uint32_t*)(v2 + 8) = 0;
					*(uint8_t*)(v2 + 24) = 1;
				} else {
					v8 = *(float*)(v2 + 16) - *(float*)(a1 + 56);
					v9 = *(float*)(v2 + 20) - *(float*)(a1 + 60);
					v11 = v9;
					v10 = sqrt(v9 * v11 + v8 * v8) + *(double*)&qword_581450_10176;
					*(float*)(v1 + 80) = v8 * *(float*)(v1 + 544) / v10;
					*(float*)(v1 + 84) = v11 * *(float*)(v1 + 544) / v10;
				}
			}
			goto LABEL_19;
		}
		if (!*(uint8_t*)(v2 + 24)) {
			*(uint32_t*)(v2 + 8) = *(uint32_t*)(a1 + 508);
			goto LABEL_12;
		}
	}
LABEL_19:
	if (nox_frame_xxx_2598000 - *(uint32_t*)(v1 + 128) > (unsigned int)(5 * nox_gameFPS)) {
		*(uint8_t*)(v2 + 24) = 1;
		*(uint32_t*)(v2 + 8) = 0;
	}
}

//----- (0053DDF0) --------------------------------------------------------
int nox_xxx_updateFlag_53DDF0(int a1) {
	int v1;           // esi
	int v2;           // edi
	int result;       // eax
	int v4;           // eax
	int v5;           // edx
	char v6;          // [esp-18h] [ebp-24h]
	unsigned char v7; // [esp+8h] [ebp-4h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 748);
	result = *(uint32_t*)(v2 + 8);
	if (result) {
		v4 = sub_4ECBD0(a1);
		v5 = *(uint32_t*)(v2 + 8);
		a1 = v4;
		v7 = *(uint8_t*)(v1 + 52);
		result = 3 * nox_gameFPS;
		if (nox_frame_xxx_2598000 - v5 > (unsigned int)(30 * nox_gameFPS)) {
			nox_xxx_aud_501960(305, v1, 0, 0);
			v6 = a1;
			*(uint32_t*)(v2 + 8) = 0;
			sub_4E82C0(v7, 0, v6, 0);
			nox_xxx_unitMove_4E7010(v1, (float2*)v2);
			result = nox_xxx_netInformTextMsg2_4DA180(8, &a1);
		}
	}
	return result;
}

//----- (0053DE80) --------------------------------------------------------
int* nox_xxx_updateTrapDoor_53DE80(uint32_t* a1) {
	int v1;      // edi
	int* result; // eax

	v1 = a1[175];
	if (a1[4] & 0x1000000) {
		result = (int*)a1[5];
		if ((unsigned char)result & 2) {
			nox_xxx_unitUnsetXStatus_4E4780((int)a1, 2);
			result = nox_xxx_unitSetXStatus_4E4800((int)a1, (int*)8);
		} else if ((unsigned char)result & 4) {
			result = *(int**)(v1 + 16);
			if (nox_frame_xxx_2598000 >= (unsigned int)result) {
				nox_xxx_unitUnsetXStatus_4E4780((int)a1, 4);
				result = nox_xxx_unitSetXStatus_4E4800((int)a1, (int*)8);
			}
		} else {
			*(uint32_t*)(v1 + 24) = 0;
		}
	} else {
		result = *(int**)(v1 + 16);
		if (result) {
			if (nox_frame_xxx_2598000 >= (unsigned int)result) {
				nox_xxx_unitSetOnOff_4E4670((int)a1, 1);
				nox_xxx_unitUnsetXStatus_4E4780((int)a1, 2);
				nox_xxx_unitSetXStatus_4E4800((int)a1, (int*)4);
				*(uint32_t*)(v1 + 16) += 5 * nox_gameFPS;
				result = nox_xxx_aud_501960(874, (int)a1, 0, 0);
			}
		}
	}
	return result;
}

//----- (0053DF40) --------------------------------------------------------
void nox_xxx_updateGameBall_53DF40(int a3) {
	int v1;                // edi
	unsigned long long v2; // rax
	int v3;                // eax
	int v4;                // eax
	int v5;                // eax
	double v6;             // st7
	double v7;             // st7
	double v8;             // st7
	double v9;             // st6
	int v10;               // eax
	float4 v11;            // [esp+8h] [ebp-10h]

	v1 = *(uint32_t*)(a3 + 748);
	*(uint32_t*)(a3 + 112) = 1008981770;
	if (*(uint32_t*)v1 && *(uint8_t*)(*(uint32_t*)v1 + 16) & 0x20) {
		sub_4EB9B0(a3, 0);
		nox_xxx_netChangeTeamMb_419570(a3 + 48, *(uint32_t*)(a3 + 36));
		sub_4E8290(1, 0);
	}
	v2 = nox_platform_get_ticks() - *(uint64_t*)(v1 + 8);
	v11.field_4 = *((float*)&v2 + 1);
	if (v2 <= 20000) {
		v3 = *(uint32_t*)(a3 + 508);
		if (v3) {
			if (v3 != *(uint32_t*)v1 ||
				(unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(v1 + 16)) <= *(int*)(v1 + 20)) {
				*(uint32_t*)(a3 + 16) |= 0x40u;
				*(uint64_t*)(v1 + 8) = nox_platform_get_ticks();
				v5 = *(uint32_t*)(a3 + 508);
				if (*(uint32_t*)(v5 + 16) & 0x8020) {
					nox_xxx_unitClearOwner_4EC300(a3);
					sub_4EB9B0(a3, 0);
					nox_xxx_netChangeTeamMb_419570(a3 + 48, *(uint32_t*)(a3 + 36));
					sub_4E8290(1, 0);
				} else {
					v6 = *(float*)(v5 + 176) + *(float*)(a3 + 176);
					v11.field_0 = *(float*)(v5 + 56);
					v11.field_4 = *(float*)(v5 + 60);
					v7 = v6 + 10.0;
					v11.field_8 = v7 * *getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(v5 + 124)) + *(float*)(v5 + 56);
					v11.field_C = v7 * *getMemFloatPtr(0x587000, 194140 + 8 * *(short*)(v5 + 124)) + *(float*)(v5 + 60);
					if (nox_xxx_mapTraceRay_535250(&v11, 0, 0, 5)) {
						nox_xxx_unitMove_4E7010(a3, (float2*)&v11.field_8);
					}
				}
			} else {
				*(uint32_t*)(a3 + 16) &= 0xFFFFFFBF;
				*(uint32_t*)(a3 + 520) = 0;
				v4 = *(short*)(*(uint32_t*)(a3 + 508) + 124) + nox_common_randomInt_415FA0(-32, 32);
				if (v4 < 0) {
					v4 += (unsigned int)(255 - v4) >> 8 << 8;
				}
				if (v4 >= 256) {
					v4 += -256 * ((unsigned int)v4 >> 8);
				}
				v11.field_0 = *(float*)(a3 + 56) - *getMemFloatPtr(0x587000, 194136 + 8 * v4) * 20.0;
				v11.field_4 = *(float*)(a3 + 60) - *getMemFloatPtr(0x587000, 194140 + 8 * v4) * 20.0;
				nox_xxx_objectApplyForce_52DF80((int)&v11, a3, 30.0);
				nox_xxx_unitClearOwner_4EC300(a3);
				sub_4E8290(1, 0);
				nox_xxx_aud_501960(926, a3, 0, 0);
			}
		} else {
			v8 = *(float*)(a3 + 84);
			v9 = *(float*)(a3 + 80);
			v10 = *(uint32_t*)(a3 + 16);
			LOBYTE(v10) = v10 & 0xBF;
			*(uint32_t*)(a3 + 16) = v10;
			if (*(float*)(v1 + 24) > sqrt(v9 * v9 + v8 * v8)) {
				*(uint32_t*)v1 = 0;
			}
		}
	} else {
		sub_417F50(a3);
	}
}

//----- (0053E190) --------------------------------------------------------
void nox_xxx_updateUndeadKiller_53E190(int a1) {
	int v1; // eax

	v1 = **(uint32_t**)(a1 + 700);
	if (v1 && *(uint8_t*)(v1 + 88) & 1) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	} else if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 136)) > 0x46) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (0053E1D0) --------------------------------------------------------
void nox_xxx_updateCrown_53E1D0(int a1) {
	uint32_t* v1; // ecx
	int v2;       // eax
	int v3;       // eax
	double v4;    // st7
	double v5;    // st7
	float4 v6;    // [esp+4h] [ebp-10h]

	v1 = *(uint32_t**)(a1 + 748);
	v2 = v1[1];
	if (!v2 || *(uint32_t*)(v2 + 16) & 0x8020) {
		if (*v1 && *(uint8_t*)(*v1 + 16) & 0x20) {
			*v1 = 0;
		}
		v3 = *(uint32_t*)(a1 + 508);
		if (v3) {
			if (*(uint32_t*)(v3 + 16) & 0x8020) {
				nox_xxx_unitClearOwner_4EC300(a1);
			} else {
				v4 = *(float*)(v3 + 176) + *(float*)(a1 + 176);
				v6.field_0 = *(float*)(v3 + 56);
				v6.field_4 = *(float*)(v3 + 60);
				v5 = v4 + 10.0;
				v6.field_8 = v5 * *getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(v3 + 124)) + *(float*)(v3 + 56);
				v6.field_C = v5 * *getMemFloatPtr(0x587000, 194140 + 8 * *(short*)(v3 + 124)) + *(float*)(v3 + 60);
				if (nox_xxx_mapTraceRay_535250(&v6, 0, 0, 5)) {
					nox_xxx_unitMove_4E7010(a1, (float2*)&v6.field_8);
				}
			}
		}
	} else {
		sub_4F3400(v2, a1, 1);
	}
}

//----- (0053E2B0) --------------------------------------------------------
char sub_53E2B0(int a1) {
	int v1; // eax

	v1 = *(uint32_t*)(a1 + 16);
	if (!(v1 & 0x1000000)) {
		LOBYTE(v1) = v1 | 0x40;
		*(uint32_t*)(a1 + 744) = 0;
		*(uint32_t*)(a1 + 16) = v1;
	}
	return v1;
}

//----- (0053E2D0) --------------------------------------------------------
int sub_53E2D0(int a1) {
	int result; // eax

	if (*(uint32_t*)(a1 + 8) & 0x2000000) {
		result = (nox_xxx_unitArmorInventoryEquipFlags_415C70(a1) & 0xC0D) == 0;
	} else {
		result = 1;
	}
	return result;
}

//----- (0053E300) --------------------------------------------------------
int nox_xxx_recalculateArmorVal_53E300(uint32_t* a1) {
	uint32_t* i; // esi
	int v2;      // eax
	int result;  // eax
	float v4;    // [esp+8h] [ebp-4h]

	v4 = 0.0;
	for (i = (uint32_t*)a1[126]; i; i = (uint32_t*)i[124]) {
		if (i[2] & 0x2000000) {
			v2 = i[4];
			if (v2 & 0x100) {
				v4 = nox_xxx_itemApplyDefendEffect_415C00((int)i) + v4;
			}
		}
	}
	if (v4 > *(double*)&qword_581450_9512) {
		v4 = 1.0;
	}
	result = a1[2];
	if (result & 4) {
		result = a1[187];
		*(float*)(result + 228) = v4;
	} else if (result & 2) {
		result = LODWORD(v4);
		*(float*)(a1[187] + 2072) = v4;
	}
	return result;
}

//----- (0053E3A0) --------------------------------------------------------
int sub_53E3A0(int a1, nox_object_t* object) {
	int result; // eax
	int v3;     // ecx

	if (!(object->obj_class & 0x2000000)) {
		return 0;
	}
	v3 = object->flags;
	if (!(v3 & 0x100)) {
		return 0;
	}
	result = *(uint32_t*)(a1 + 504);
	if (!result) {
		return 0;
	}
	while (result != object) {
		result = *(uint32_t*)(result + 496);
		if (!result) {
			return result;
		}
	}
	BYTE1(v3) &= 0xFEu;
	object->flags = v3;
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		nox_xxx_npcSetItemEquipFlags_4E4B20(a1, object, 0);
	}
	object->flags &= 0xEFFFFFFF;
	nox_xxx_recalculateArmorVal_53E300((uint32_t*)a1);
	nox_xxx_itemApplyDisengageEffect_4F3030(object, a1);
	return 1;
}

//----- (0053E430) --------------------------------------------------------
int sub_53E430(uint32_t* a1, nox_object_t* object, int a3, int a4) {
	int v4;       // ecx
	int v5;       // eax
	int v7;       // eax
	int v8;       // ebp
	uint32_t* v9; // edi
	char v10;     // al

	if (!(object->obj_class & 0x2000000)) {
		return 0;
	}
	v4 = object->flags;
	if (!(v4 & 0x100)) {
		return 0;
	}
	v5 = a1[2];
	if (v5 & 2) {
		return sub_53E3A0((int)a1, object);
	}
	if (!(v5 & 4)) {
		return 0;
	}
	v7 = a1[126];
	v8 = a1[187];
	if (!v7) {
		return 0;
	}
	while (v7 != object) {
		v7 = *(uint32_t*)(v7 + 496);
		if (!v7) {
			return 0;
		}
	}
	object->flags = v4 & 0xEFFFFEFF;
	v9 = *(uint32_t**)(v8 + 276);
	*v9 &= ~nox_xxx_unitArmorInventoryEquipFlags_415C70(object);
	if (a3) {
		nox_xxx_netReportDequip_4D8590(*(unsigned char*)(*(uint32_t*)(v8 + 276) + 2064), object);
	}
	if (a4) {
		nox_xxx_netReportDequip_4D84C0(255, object);
	}
	nox_xxx_recalculateArmorVal_53E300(a1);
	nox_xxx_itemApplyDisengageEffect_4F3030(object, (int)a1);
	if (*(uint8_t*)&object->field_12 & 2) {
		v10 = *(uint8_t*)(v8 + 88);
		if (v10 == 15 || v10 == 16 || v10 == 17) {
			nox_xxx_playerSetState_4FA020(a1, 13);
		}
	}
	return 1;
}

//----- (0053E520) --------------------------------------------------------
int nox_xxx_NPCEquipArmor_53E520(int a1, uint32_t* a2) {
	uint32_t* v3; // eax
	uint32_t* v4; // ecx

	if (!(a2[2] & 0x2000000)) {
		return 0;
	}
	if (a2[4] & 0x100) {
		return 0;
	}
	v3 = *(uint32_t**)(a1 + 504);
	v4 = *(uint32_t**)(a1 + 504);
	if (!v4) {
		return 0;
	}
	while (v4 != a2) {
		v4 = (uint32_t*)v4[124];
		if (!v4) {
			return 0;
		}
	}
	if (v3) {
		while (!(v3[2] & 0x2000000) || !(v3[4] & 0x100) || v3[3] != a2[3]) {
			v3 = (uint32_t*)v3[124];
			if (!v3) {
				goto LABEL_18;
			}
		}
		sub_53E3A0(a1, (int)v3);
	}
LABEL_18:
	a2[4] |= 0x100u;
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		nox_xxx_npcSetItemEquipFlags_4E4B20(a1, (int)a2, 1);
	}
	if (!sub_53E2D0((int)a2)) {
		a2[4] |= 0x10000000u;
	}
	nox_xxx_recalculateArmorVal_53E300((uint32_t*)a1);
	nox_xxx_itemApplyEngageEffect_4F2FF0((int)a2, a1);
	if (a2[3] & 2) {
		sub_53E600((uint32_t*)a1);
	}
	return 1;
}

//----- (0053E600) --------------------------------------------------------
void sub_53E600(uint32_t* a1) {
	uint32_t* i; // esi
	int v2;      // eax

	if (a1) {
		for (i = (uint32_t*)a1[126]; i; i = (uint32_t*)i[124]) {
			v2 = i[4];
			if (v2 & 0x100 && i[2] & 0x1001000) {
				if (nox_xxx_weaponInventoryEquipFlags_415820((int)i) & 0x7FFE40C) {
					nox_xxx_playerDequipWeapon_53A140(a1, (int)i, 1, 1);
				}
			}
		}
	}
}

//----- (0053E650) --------------------------------------------------------
int nox_xxx_playerEquipArmor_53E650(uint32_t* a1, nox_object_t* item, int a3, int a4) {
	const int a2 = (int)item;
	int v4;        // eax
	int v5;        // eax
	int v7;        // ebx
	uint32_t* v8;  // ebp
	int v9;        // eax
	int v10;       // ecx
	uint32_t* v11; // ebp

	if (!(*(uint32_t*)&item->obj_class & 0x2000000)) {
		return 0;
	}
	v4 = item->flags;
	if (v4 & 0x100) {
		return 0;
	}
	v5 = a1[2];
	if (v5 & 2) {
		return nox_xxx_NPCEquipArmor_53E520((int)a1, (uint32_t*)a2);
	}
	if (!(v5 & 4)) {
		return 0;
	}
	v7 = a1[187];
	v8 = nox_xxx_armorHaveSameSubclass_53E7B0((int)a1, a2);
	if (!nox_xxx_playerClassCanUseItem_57B3D0(item, *(uint8_t*)(*(uint32_t*)(v7 + 276) + 2251))) {
		nox_xxx_netPriMsgToPlayer_4DA2C0((int)a1, "armor.c:ArmorEquipClassFail", 0);
		if (a4) {
			nox_xxx_aud_501960(925, (int)a1, 2, a1[9]);
		}
		return 0;
	}
	LOBYTE(v9) = nox_xxx_playerCheckStrength_4F3180((int)a1, item);
	if (!v9) {
		nox_xxx_netPriMsgToPlayer_4DA2C0((int)a1, "armor.c:ArmorEquipStrengthFail", 0);
		if (a4) {
			nox_xxx_aud_501960(925, (int)a1, 2, a1[9]);
		}
		return 0;
	}
	if (v8) {
		sub_53E430(a1, (int)v8, 1, 1);
	}
	v10 = item->flags;
	BYTE1(v10) |= 1u;
	item->flags = v10;
	v11 = *(uint32_t**)(v7 + 276);
	*v11 |= nox_xxx_unitArmorInventoryEquipFlags_415C70(item);
	nox_xxx_netReportEquip_4D8540(*(unsigned char*)(*(uint32_t*)(v7 + 276) + 2064), (uint32_t*)a2, a3);
	if (!sub_53E2D0(a2)) {
		item->flags |= 0x10000000u;
	}
	nox_xxx_recalculateArmorVal_53E300(a1);
	nox_xxx_itemApplyEngageEffect_4F2FF0(item, (int)a1);
	if (*(uint8_t*)&item->field_3 & 2) {
		sub_53E600(a1);
	}
	return 1;
}
// 53E6E7: variable 'v9' is possibly undefined

//----- (0053E7B0) --------------------------------------------------------
uint32_t* nox_xxx_armorHaveSameSubclass_53E7B0(int a1, int a2) {
	uint32_t* result; // eax

	result = *(uint32_t**)(a1 + 504);
	if (!result) {
		return 0;
	}
	while (!(result[4] & 0x100) || !(result[2] & 0x2000000) || result[3] != *(uint32_t*)(a2 + 12)) {
		result = (uint32_t*)result[124];
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (0053E7F0) --------------------------------------------------------
int nox_xxx_pickupArmor_53E7F0(int a1, int a2, int a3, int a4) {
	uint32_t* v5;  // eax
	int v6;        // ebp
	uint32_t* v7;  // esi
	int v8;        // eax
	uint32_t* v9;  // ecx
	int i;         // eax
	int v11;       // eax
	uint32_t* v12; // ecx
	int v13;       // eax
	int m;         // eax
	short v15;     // ax
	int v16;       // eax
	int j;         // eax
	uint32_t* v18; // ecx
	int k;         // eax
	int l;         // eax

	if (!*getMemU32Ptr(0x5D4594, 2488712)) {
		*getMemU32Ptr(0x5D4594, 2488712) = nox_xxx_getNameId_4E3AA0("StreetSneakers");
		*getMemU32Ptr(0x5D4594, 2488716) = nox_xxx_getNameId_4E3AA0("WizardRobe");
		dword_5d4594_2488720 = nox_xxx_getNameId_4E3AA0("WoodenShield");
		dword_5d4594_2488724 = nox_xxx_getNameId_4E3AA0("SteelShield");
	}
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096) && sub_409F40(2) &&
		sub_4E7EC0(a1, a2)) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "armor.c:CannotPickupDuplicateArmor", 0);
	LABEL_13:
		nox_xxx_aud_501960(925, a1, 2, *(uint32_t*)(a1 + 36));
		return 0;
	}
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096) &&
		*(uint8_t*)(a1 + 8) & 4 &&
		!nox_xxx_playerClassCanUseItem_57B3D0(a2, *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2251))) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "armor.c:ArmorEquipClassFail", 0);
		goto LABEL_13;
	}
	if (nox_xxx_pickupDefault_4F31E0(a1, a2, a3) != 1) {
		return 0;
	}
	if (*(uint8_t*)(a1 + 8) & 4) {
		v5 = nox_xxx_armorHaveSameSubclass_53E7B0(a1, a2);
		v6 = *(uint32_t*)(a1 + 748);
		v7 = v5;
		v8 = sub_419E60(a1);
		if (!v8) {
			if (v7) {
				LOWORD(v8) = *((uint16_t*)v7 + 2);
				if (v8 != dword_5d4594_2488720 && v8 != dword_5d4594_2488724 &&
					v8 != *getMemU32Ptr(0x5D4594, 2488712) && v8 != *getMemU32Ptr(0x5D4594, 2488716)) {
					goto LABEL_40;
				}
				if (v8 == *getMemU32Ptr(0x5D4594, 2488716)) {
					v9 = (uint32_t*)v7[173];
					for (i = 0; i < 4; ++i) {
						if (*v9) {
							break;
						}
						++v9;
					}
					if (i == 4) {
						nox_xxx_playerEquipArmor_53E650((uint32_t*)a1, a2, a4, 0);
					}
					goto LABEL_40;
				}
			}
			if (!(*(uint8_t*)(a2 + 12) & 2)) {
				goto LABEL_70;
			}
			if (!v7) {
				v11 = *(uint32_t*)(v6 + 104);
				if (!v11 || !(*(uint32_t*)(v11 + 12) & 0x7FFE40C)) {
					nox_xxx_playerEquipArmor_53E650((uint32_t*)a1, a2, a4, 0);
				}
				goto LABEL_40;
			}
			v12 = (uint32_t*)v7[173];
			v13 = *((unsigned short*)v7 + 2);
			if ((unsigned short)v13 != dword_5d4594_2488720) {
				if (v13 == dword_5d4594_2488724) {
					v16 = *(unsigned short*)(a2 + 4);
					if ((unsigned short)v16 == dword_5d4594_2488720) {
						for (j = 0; j < 4; ++j) {
							if (*v12) {
								break;
							}
							++v12;
						}
						if (j == 4) {
							v18 = *(uint32_t**)(a2 + 692);
							for (k = 0; k < 4; ++k) {
								if (*v18) {
									break;
								}
								++v18;
							}
							if (k != 4) {
								nox_xxx_playerEquipArmor_53E650((uint32_t*)a1, a2, a4, 0);
							}
						}
					} else if (v16 == dword_5d4594_2488724) {
						for (l = 0; l < 4; ++l) {
							if (*v12) {
								break;
							}
							++v12;
						}
						if (l == 4) {
							nox_xxx_playerEquipArmor_53E650((uint32_t*)a1, a2, a4, 0);
						}
					}
				}
				goto LABEL_40;
			}
			for (m = 0; m < 4; ++m) {
				if (*v12) {
					break;
				}
				++v12;
			}
			if (m == 4) {
			LABEL_70:
				nox_xxx_playerEquipArmor_53E650((uint32_t*)a1, a2, a4, 0);
			}
		}
	}
LABEL_40:
	v15 = *(uint16_t*)(a2 + 24);
	if (v15 & 0x10) {
		nox_xxx_aud_501960(804, a1, 0, 0);
	} else if (v15 & 8) {
		nox_xxx_aud_501960(810, a1, 0, 0);
	} else if (v15 & 4) {
		nox_xxx_aud_501960(807, a1, 0, 0);
	} else if (v15 & 2) {
		if (*(uint8_t*)(a2 + 12) & 0x20) {
			nox_xxx_aud_501960(816, a1, 0, 0);
		} else {
			nox_xxx_aud_501960(813, a1, 0, 0);
		}
	}
	nox_xxx_decay_5116F0(a2);
	return 1;
}

//----- (0053EAE0) --------------------------------------------------------
void sub_53EAE0(int a1) {
	short v2; // cx

	if (a1) {
		v2 = *(uint16_t*)(a1 + 24);
		if (v2 & 0x10) {
			nox_xxx_aud_501960(805, a1, 0, 0);
		} else if (v2 & 8) {
			nox_xxx_aud_501960(811, a1, 0, 0);
		} else if (v2 & 4) {
			nox_xxx_aud_501960(808, a1, 0, 0);
		} else if (v2 & 2) {
			if (*(uint8_t*)(a1 + 12) & 0x20) {
				nox_xxx_aud_501960(817, a1, 0, 0);
			} else {
				nox_xxx_aud_501960(814, a1, 0, 0);
			}
		}
	}
}

//----- (0053EB70) --------------------------------------------------------
int nox_xxx_dropArmor_53EB70(int a1, uint32_t* a2, int* a3) {
	if (nox_xxx_dropDefault_4ED290(a1, (int)a2, (float2*)a3) != 1) {
		return 0;
	}
	sub_53EAE0((int)a2);
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096)) {
		if (sub_409F40(2)) {
			nox_xxx_unitSetDecayTime_511660(a2, 25 * nox_gameFPS);
		}
	}
	return 1;
}

//----- (0053EBF0) --------------------------------------------------------
int nox_xxx_ItemIsDroppable_53EBF0(int a1) {
	unsigned char* i; // eax
	int v2;           // edx

	if (!a1) {
		return 0;
	}
	if (!dword_5d4594_2488728) {
		sub_53EC40();
	}
	if (!*getMemU32Ptr(0x587000, 279432)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 279432); *((uint32_t*)i + 1) != *(unsigned short*)(a1 + 4); i += 12) {
		v2 = *((uint32_t*)i + 3);
		if (!v2) {
			return 0;
		}
	}
	return 1;
}

//----- (0053EC40) --------------------------------------------------------
char* sub_53EC40() {
	char* result;      // eax
	unsigned char* v1; // esi

	result = *(char**)getMemAt(0x587000, 279432);
	if (*getMemU32Ptr(0x587000, 279432)) {
		v1 = getMemAt(0x587000, 279432);
		do {
			*((uint32_t*)v1 + 1) = nox_xxx_getNameId_4E3AA0(result);
			result = (char*)*((uint32_t*)v1 + 3);
			v1 += 12;
		} while (result);
		dword_5d4594_2488728 = 1;
	} else {
		dword_5d4594_2488728 = 1;
	}
	return result;
}

//----- (0053EC80) --------------------------------------------------------
int sub_53EC80(int a1, int a2) {
	int v2;           // edx
	unsigned char* i; // eax
	int v4;           // esi

	if (!a1) {
		return 0;
	}
	if (!dword_5d4594_2488728) {
		sub_53EC40();
	}
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 279432)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 279432); *((uint32_t*)i + 1) != *(unsigned short*)(a1 + 4); i += 12) {
		v4 = *((uint32_t*)i + 3);
		++v2;
		if (!v4) {
			return 0;
		}
	}
	return (a2 & *getMemU32Ptr(0x587000, 279440 + 12 * v2)) != 0;
}

//----- (0053ECE0) --------------------------------------------------------
int nox_xxx_useMushroom_53ECE0(int a1, int a2) {
	int v2; // eax

	if (*(uint8_t*)(a1 + 540)) {
		nox_xxx_removePoison_4EE9D0(a1);
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "Use.c:MushroomClean", 0);
		v2 = nox_xxx_spellGetAud44_424800(14, 1);
		nox_xxx_aud_501960(v2, a1, 0, 0);
	} else {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "Use.c:MushroomConfuse", 0);
	}
	nox_xxx_buffApplyTo_4FF380(a1, 3, 300, 5);
	nox_xxx_delayedDeleteObject_4E5CC0(a2);
	return 1;
}

//----- (0053ED60) --------------------------------------------------------
int nox_xxx_useEnchant_53ED60(int a1, int a2) {
	nox_xxx_buffApplyTo_4FF380(a1, **(uint32_t**)(a2 + 736), *(uint32_t*)(*(uint32_t*)(a2 + 736) + 4), 5);
	nox_xxx_delayedDeleteObject_4E5CC0(a2);
	return 1;
}

//----- (0053ED90) --------------------------------------------------------
int nox_xxx_useCast_53ED90(int a1, uint32_t* a2) {
	int* v2;   // ecx
	int v3;    // eax
	int v4;    // eax
	int v6[3]; // [esp+4h] [ebp-Ch]

	v6[0] = a1;
	v2 = (int*)a2[184];
	if (*(uint8_t*)(a1 + 8) & 4) {
		v3 = *(uint32_t*)(a1 + 748);
		*(float*)&v6[1] = (double)*(int*)(*(uint32_t*)(v3 + 276) + 2284);
		*(float*)&v6[2] = (double)*(int*)(*(uint32_t*)(v3 + 276) + 2288);
	} else {
		v4 = *(uint32_t*)(a1 + 60);
		v6[1] = *(uint32_t*)(a1 + 56);
		v6[2] = v4;
	}
	nox_xxx_spellAccept_4FD400(*v2, (int)a2, a2, (int)a2, v6, 4);
	nox_xxx_delayedDeleteObject_4E5CC0((int)a2);
	return 1;
}

//----- (0053EE10) --------------------------------------------------------
int nox_xxx_useConsume_53EE10(int a1, int a2) {
	uint16_t* v2; // eax
	int v3;       // eax

	if (*(uint8_t*)(a2 + 8) & 0x10) {
		if (!(*(uint8_t*)(a2 + 12) & 8)) {
			v2 = *(uint16_t**)(a1 + 556);
			if (v2) {
				if (*v2 < v2[2]) {
					nox_xxx_unitAdjustHP_4EE460(a1, **(uint32_t**)(a2 + 736));
					if (*(uint8_t*)(a1 + 8) & 4) {
						v3 = *(uint32_t*)(a2 + 12);
						if (*(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2252)) {
							if (v3 & 1) {
								nox_xxx_aud_501960(324, a1, 0, 0);
							} else if (v3 & 2) {
								nox_xxx_aud_501960(325, a1, 0, 0);
							} else if (v3 & 4) {
								nox_xxx_aud_501960(326, a1, 0, 0);
							}
						} else if (v3 & 1) {
							nox_xxx_aud_501960(314, a1, 0, 0);
						} else if (v3 & 2) {
							nox_xxx_aud_501960(315, a1, 0, 0);
						} else if (v3 & 4) {
							nox_xxx_aud_501960(316, a1, 0, 0);
						}
					} else {
						nox_xxx_aud_501960(334, a1, 0, 0);
					}
					nox_xxx_delayedDeleteObject_4E5CC0(a2);
				}
			}
		}
	}
	return 1;
}

//----- (0053EF00) --------------------------------------------------------
int nox_xxx_useCiderConfuse_53EF00(int a1, int a2) {
	int v2; // esi

	if (!a1 || !a2 || !*(uint32_t*)(a1 + 556)) {
		return 1;
	}
	nox_xxx_buffApplyTo_4FF380(a1, 3, 5 * (uint16_t)nox_gameFPS, 4);
	nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "Use.c:CiderConfuse", 0);
	v2 = nox_xxx_useConsume_53EE10(a1, a2);
	if (v2) {
		nox_xxx_delayedDeleteObject_4E5CC0(a2);
	}
	return v2;
}

//----- (0053EF70) --------------------------------------------------------
int nox_xxx_usePotion_53EF70(int a1, int a2) {
	int v2;       // ebp
	int v3;       // edi
	int result;   // eax
	int v5;       // edx
	uint16_t* v6; // edx
	char v7;      // al
	double v8;    // st7
	int v9;       // ecx
	char v10;     // al
	double v11;   // st7
	int v12;      // eax
	int v13;      // ecx
	int v14;      // ecx
	int v15;      // ecx
	int v16;      // eax
	int v17;      // ecx
	int v18;      // ecx
	int v19;      // ecx
	int v20;      // ecx
	int v21;      // ecx
	int v22;      // ecx
	float v23;    // [esp+0h] [ebp-20h]
	float v24;    // [esp+0h] [ebp-20h]
	int v25;      // [esp+10h] [ebp-10h]
	int v26[3];   // [esp+14h] [ebp-Ch]

	v2 = a2;
	v3 = **(uint32_t**)(a2 + 736);
	result = 0;
	v25 = **(uint32_t**)(a2 + 736);
	if (!(*(uint32_t*)(a1 + 8) & 4) || (v5 = *(uint32_t*)(a1 + 16), (v5 & 0x8000) == 0)) {
		if (!(*(uint8_t*)(a2 + 12) & 0x10) || (v6 = *(uint16_t**)(a1 + 556)) == 0) {
		LABEL_16:
			if (!(*(uint8_t*)(v2 + 12) & 0x20) || !(*(uint8_t*)(a1 + 8) & 4) ||
				(v9 = *(uint32_t*)(a1 + 748), *(uint16_t*)(v9 + 4) >= *(uint16_t*)(v9 + 8))) {
			LABEL_27:
				if (*(uint8_t*)(v2 + 12) & 0x40 && *(uint8_t*)(a1 + 8) & 4 && *(uint8_t*)(a1 + 540)) {
					nox_xxx_removePoison_4EE9D0(a1);
					v12 = nox_xxx_spellGetAud44_424800(14, 1);
					nox_xxx_aud_501960(v12, a1, 0, 0);
					result = 1;
				}
				v13 = *(uint32_t*)(v2 + 12);
				if (v13 & 0x100) {
					nox_xxx_buffApplyTo_4FF380(a1, 9, 120 * (uint16_t)nox_gameFPS, 3);
					result = 1;
				}
				v14 = *(uint32_t*)(v2 + 12);
				if (v14 & 0x200) {
					nox_xxx_buffApplyTo_4FF380(a1, 0, 120 * (uint16_t)nox_gameFPS, 3);
					result = 1;
				}
				v15 = *(uint32_t*)(v2 + 12);
				if (v15 & 0x400) {
					v16 = *(uint32_t*)(a1 + 56);
					v17 = *(uint32_t*)(a1 + 60);
					v26[0] = a1;
					v26[1] = v16;
					v26[2] = v17;
					nox_xxx_spellAccept_4FD400(51, a1, (uint32_t*)a1, a1, v26, v3);
					result = 1;
				}
				v18 = *(uint32_t*)(v2 + 12);
				if (v18 & 0x800) {
					nox_xxx_buffApplyTo_4FF380(a1, 17, 120 * (uint16_t)nox_gameFPS, 3);
					result = 1;
				}
				v19 = *(uint32_t*)(v2 + 12);
				if (v19 & 0x1000) {
					nox_xxx_buffApplyTo_4FF380(a1, 20, 120 * (uint16_t)nox_gameFPS, 3);
					result = 1;
				}
				v20 = *(uint32_t*)(v2 + 12);
				if (v20 & 0x2000) {
					nox_xxx_buffApplyTo_4FF380(a1, 18, 120 * (uint16_t)nox_gameFPS, 3);
					result = 1;
				}
				v21 = *(uint32_t*)(v2 + 12);
				if (v21 & 0x4000) {
					nox_xxx_buffApplyTo_4FF380(a1, 23, 120 * (uint16_t)nox_gameFPS, 3);
					result = 1;
				}
				v22 = *(uint32_t*)(v2 + 12);
				if ((v22 & 0x8000) != 0) {
					nox_xxx_buffApplyTo_4FF380(a1, 21, 120 * (uint16_t)nox_gameFPS, 3);
					result = 1;
				}
				if (*(uint32_t*)(v2 + 12) & 0x10000) {
					nox_xxx_buffApplyTo_4FF380(a1, 13, 120 * (uint16_t)nox_gameFPS, 3);
				} else if (!result) {
					return 1;
				}
				nox_xxx_delayedDeleteObject_4E5CC0(v2);
				return 1;
			}
			v10 = *(uint8_t*)(*(uint32_t*)(v9 + 276) + 2251);
			if (v10) {
				if (v10 == 1) {
					v11 = (double)v25 * *(float*)&nox_xxx_wizardMaximumMana_587000_312820;
				} else {
					if (v10 != 2) {
					LABEL_26:
						nox_xxx_playerManaAdd_4EEB80(a1, v3);
						nox_xxx_aud_501960(755, a1, 0, 0);
						result = 1;
						goto LABEL_27;
					}
					v11 = (double)v25 * *(float*)&nox_xxx_conjurerMaxMana_587000_312804;
				}
			} else {
				v11 = (double)v25 * *(float*)&nox_xxx_warriorMaxMana_587000_312788;
			}
			v24 = v11;
			v3 = nox_float2int(v24);
			goto LABEL_26;
		}
		if (*v6 >= v6[2]) {
		LABEL_15:
			v2 = a2;
			goto LABEL_16;
		}
		if (*(uint32_t*)(a1 + 8) & 4) {
			v7 = *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2251);
			switch (v7) {
			case 0:
				v8 = (double)v25 * *(float*)&nox_xxx_warriorMaxHealth_587000_312784;
			LABEL_13:
				v23 = v8;
				v3 = nox_float2int(v23);
				v25 = v3;
				break;
			case 1:
				v8 = (double)v25 * *(float*)&nox_xxx_wizardMaxHealth_587000_312816;
				goto LABEL_13;
			case 2:
				v8 = (double)v25 * *(float*)&nox_xxx_conjurerMaxHealth_587000_312800;
				goto LABEL_13;
			}
		}
		nox_xxx_unitAdjustHP_4EE460(a1, v3);
		nox_xxx_aud_501960(754, a1, 0, 0);
		result = 1;
		goto LABEL_15;
	}
	return result;
}

//----- (0053F290) --------------------------------------------------------
int nox_xxx_useLesserFireballStaff_53F290(int a1, uint32_t* a2) {
	int v2;            // esi
	int result;        // eax
	double v4;         // st7
	int v5;            // eax
	double v6;         // st6
	float v7;          // edx
	double v8;         // st7
	int v9;            // eax
	uint32_t* v10;     // eax
	int v11;           // ebx
	unsigned char v12; // al
	float4 v13;        // [esp+Ch] [ebp-10h]

	v2 = a2[184];
	if (!v2) {
		return 1;
	}
	if (!*(uint32_t*)(v2 + 84)) {
		*(uint32_t*)(v2 + 84) = nox_xxx_getNameId_4E3AA0((char*)(v2 + 4));
	}
	if (!*(uint8_t*)(v2 + 109) || *(uint8_t*)(v2 + 108)) {
		if (nox_frame_xxx_2598000 - *(uint32_t*)(v2 + 104) >=
			(unsigned int)(*(uint32_t*)(v2 + 100) - nox_xxx_itemCheckReadinessEffect_4E0960((int)a2))) {
			v4 = *(float*)(a1 + 176) + 4.0;
			v5 = 8 * *(short*)(a1 + 124);
			v6 = v4 * *getMemFloatPtr(0x587000, 194136 + v5);
			v7 = *(float*)(a1 + 60);
			v13.field_0 = *(float*)(a1 + 56);
			v13.field_4 = v7;
			v13.field_8 = v6 + *(float*)(a1 + 56);
			v8 = v4 * *getMemFloatPtr(0x587000, 194140 + v5) + *(float*)(a1 + 60);
			v13.field_8 = v13.field_8 + *(float*)(a1 + 80);
			v13.field_C = v8 + *(float*)(a1 + 84);
			if (!nox_xxx_mapTraceRay_535250(&v13, 0, 0, 5)) {
				v13.field_8 = v13.field_0;
				v13.field_C = v13.field_4;
			}
			nox_xxx_wandShot_53F480(a1, *(uint32_t*)(v2 + 84), (int*)&v13.field_8, (uint32_t*)*(short*)(a1 + 124));
			if (*(uint8_t*)(v2 + 96) & 1) {
				v9 = *(short*)(a1 + 124) + 8;
				if (v9 >= 256) {
					v9 += -256 * ((unsigned int)v9 >> 8);
				}
				nox_xxx_wandShot_53F480(a1, *(uint32_t*)(v2 + 84), (int*)&v13.field_8, (uint32_t*)v9);
				v10 = (uint32_t*)(*(short*)(a1 + 124) - 8);
				if ((int)v10 < 0) {
					v10 += 64 * ((unsigned int)(255 - (uint32_t)v10) >> 8);
				}
				nox_xxx_wandShot_53F480(a1, *(uint32_t*)(v2 + 84), (int*)&v13.field_8, v10);
			}
			nox_xxx_aud_501960(*(uint32_t*)(v2 + 88), a1, 0, 0);
			if (*(uint8_t*)(v2 + 109)) {
				v11 = *(unsigned char*)(v2 + 109);
				v12 = *(uint8_t*)(v2 + 108) - 1;
				*(uint8_t*)(v2 + 108) = v12;
				*(uint32_t*)(v2 + 112) = 100 * v12 / v11;
				if (*(uint8_t*)(a1 + 8) & 4) {
					nox_xxx_netReportCharges_4D82B0(
						*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2064), a2, v12, v11);
				}
			}
			*(uint32_t*)(v2 + 104) = nox_frame_xxx_2598000;
			result = 1;
		} else {
			result = 0;
		}
	} else {
		nox_xxx_aud_501960(222, a1, 0, 0);
		result = 0;
	}
	return result;
}

//----- (0053F480) --------------------------------------------------------
uint32_t* nox_xxx_wandShot_53F480(int a1, int a2, int* a3, uint32_t* a4) {
	uint32_t* result; // eax
	uint32_t* v5;     // esi

	result = nox_xxx_newObjectWithTypeInd_4E3450(a2);
	v5 = result;
	if (result) {
		nox_xxx_createAt_4DAA50((int)result, a1, *(float*)a3, *((float*)a3 + 1));
		result = a4;
		*((uint16_t*)v5 + 62) = (uint16_t)a4;
		*((uint16_t*)v5 + 63) = (uint16_t)a4;
		*((float*)v5 + 20) = *getMemFloatPtr(0x587000, 194136 + 8 * (uint32_t)a4) * *((float*)v5 + 136);
		*((float*)v5 + 21) = *getMemFloatPtr(0x587000, 194140 + 8 * (uint32_t)a4) * *((float*)v5 + 136);
		*((float*)v5 + 20) = *(float*)(a1 + 80) + *((float*)v5 + 20);
		*((float*)v5 + 21) = *(float*)(a1 + 84) + *((float*)v5 + 21);
	}
	return result;
}

//----- (0053F4F0) --------------------------------------------------------
int nox_xxx_useWandCastSpell_53F4F0(int a1, uint32_t* a2) {
	int v2;            // esi
	int v4;            // eax
	int v5;            // eax
	int v6;            // ecx
	int v7;            // eax
	int v8;            // eax
	unsigned char v9;  // al
	unsigned char v10; // cl
	int v11[3];        // [esp+Ch] [ebp-Ch]

	v2 = a2[184];
	if (!*getMemU32Ptr(0x5D4594, 2488732)) {
		*getMemU32Ptr(0x5D4594, 2488732) = nox_xxx_getNameId_4E3AA0("ForceWand");
	}
	if (*(uint8_t*)(v2 + 109) && !*(uint8_t*)(v2 + 108)) {
		nox_xxx_aud_501960(222, a1, 0, 0);
		return 0;
	}
	if (nox_frame_xxx_2598000 - *(uint32_t*)(v2 + 104) <
		(unsigned int)(*(uint32_t*)(v2 + 100) - 2 * nox_xxx_itemCheckReadinessEffect_4E0960((int)a2))) {
		return 0;
	}
	if (*(uint8_t*)(a1 + 8) & 4) {
		v4 = *(uint32_t*)(a1 + 748);
		*(float*)&v11[1] = (double)*(int*)(*(uint32_t*)(v4 + 276) + 2284);
		*(float*)&v11[2] = (double)*(int*)(*(uint32_t*)(v4 + 276) + 2288);
		v5 = *(uint32_t*)(v4 + 288);
		if (v5) {
			v11[0] = v5;
			goto LABEL_13;
		}
	} else {
		v6 = *(uint32_t*)(a1 + 60);
		v11[1] = *(uint32_t*)(a1 + 56);
		v11[2] = v6;
	}
	v11[0] = a1;
LABEL_13:
	v7 = *(uint32_t*)(v2 + 92);
	*(uint32_t*)(v2 + 96) |= 4u;
	if (nox_xxx_spellAccept_4FD400(v7, a1, (uint32_t*)a1, a1, v11, 4)) {
		*(uint32_t*)(v2 + 104) = nox_frame_xxx_2598000;
		v8 = a2[2];
		if (!(v8 & 0x1000) || !(a2[3] & 0x4040000)) {
			v9 = *(uint8_t*)(v2 + 109);
			if (v9) {
				v10 = *(uint8_t*)(v2 + 108) - 1;
				*(uint8_t*)(v2 + 108) = v10;
				*(uint32_t*)(v2 + 112) = 100 * v10 / v9;
				if (*(uint8_t*)(a1 + 8) & 4) {
					nox_xxx_netReportCharges_4D82B0(
						*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2064), a2, v10, v9);
				}
			}
		}
	}
	return 1;
}

//----- (0053F670) --------------------------------------------------------
int nox_xxx_useFireWand_53F670(int a1, int a2) {
	int v2;    // esi
	int v3;    // eax
	double v4; // st7
	float v6;  // [esp+0h] [ebp-38h]
	float v7;  // [esp+4h] [ebp-34h]
	float v8;  // [esp+28h] [ebp-10h]
	float v9;  // [esp+2Ch] [ebp-Ch]
	float v10; // [esp+30h] [ebp-8h]
	float v11; // [esp+34h] [ebp-4h]
	float v12; // [esp+3Ch] [ebp+4h]
	float v13; // [esp+3Ch] [ebp+4h]

	v2 = a1;
	v8 = 0.0;
	v3 = 8 * *(short*)(a1 + 124);
	v11 = *getMemFloatPtr(0x587000, 194136 + v3) * *(float*)(a1 + 176) * 1.5;
	v10 = *getMemFloatPtr(0x587000, 194140 + v3) * *(float*)(a1 + 176) * 1.5;
	do {
		v12 = nox_common_randomFloat_416030(12.0, 25.0);
		v9 = nox_common_randomFloat_416030(-2.0, 2.0) +
			 v12 * *getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(v2 + 124));
		v13 = nox_common_randomFloat_416030(-2.0, 2.0) +
			  v12 * *getMemFloatPtr(0x587000, 194140 + 8 * *(short*)(v2 + 124));
		v7 = v10 + *(float*)(v2 + 60);
		v6 = v11 + *(float*)(v2 + 56);
		nox_xxx_createSpark_54FD80(v6, v7, 1, 20, v9, v13, 0.0, 0);
		v4 = v8 + 1.0;
		v8 = v4;
	} while (v4 < 1.0);
	if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(a2 + 136)) > (int)nox_gameFPS) {
		nox_xxx_aud_501960(9, v2, 0, 0);
		*(uint32_t*)(a2 + 136) = nox_frame_xxx_2598000;
	}
	return 0;
}

//----- (0053F7C0) --------------------------------------------------------
int nox_xxx_useRead_53F7C0(int a1, int a2) {
	int v2; // esi
	int v3; // ecx

	if (*(uint8_t*)(a1 + 8) & 4) {
		v2 = *(uint32_t*)(a2 + 736);
		v3 = *(uint32_t*)(v2 + 256);
		if ((nox_frame_xxx_2598000 - v3 > (unsigned int)(3 * nox_gameFPS) || !v3) &&
			nox_xxx_mapCheck_537110(a1, a2) == 1) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(a1, (const char*)v2, 1);
			*(uint32_t*)(v2 + 256) = nox_frame_xxx_2598000;
		}
	}
	return 1;
}

//----- (0053F830) --------------------------------------------------------
int sub_53F830(int a1, int a2) {
	int v2; // esi
	int v3; // ebx
	int v4; // edi
	int v5; // ecx
	int v6; // eax
	int v7; // eax
	int v8; // edx

	v2 = a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		v3 = *(uint32_t*)(a1 + 748);
		v4 = *(uint32_t*)(a2 + 736);
		v5 = *(uint32_t*)(v4 + 256);
		if ((nox_frame_xxx_2598000 - v5 > (unsigned int)(3 * nox_gameFPS) || !v5) &&
			nox_xxx_mapCheck_537110(a1, a2) == 1) {
			if (sub_4D75E0()) {
				v6 = nox_game_getQuestStage_4E3CC0();
				v7 = nox_server_questNextStageThreshold_4D74F0(v6);
				v8 = *(uint32_t*)(v3 + 276);
				a1 = v7;
				nox_xxx_netInformTextMsg_4DA0F0(*(unsigned char*)(v8 + 2064), 21, &a1);
			} else {
				nox_xxx_netPriMsgToPlayer_4DA2C0(v2, "GeneralPrint:WarpClosed", 1);
			}
			*(uint32_t*)(v4 + 256) = nox_frame_xxx_2598000;
		}
	}
	return 1;
}

//----- (0053F8E0) --------------------------------------------------------
int nox_xxx_useByNetCode_53F8E0(int a1, int a2) {
	int result; // eax

	if (!a2) {
		return 1;
	}
	if (!*(uint32_t*)(a2 + 732)) {
		return 1;
	}
	result = sub_419E60(a1);
	if (result != 1) {
		result = (*(int (**)(int, int))(a2 + 732))(a1, a2);
	}
	return result;
}

//----- (0053F930) --------------------------------------------------------
int sub_53F930(int a1, int a2) {
	int v2;     // ebx
	int v3;     // esi
	int result; // eax

	if (!(*(uint8_t*)(a1 + 8) & 4)) {
		return 0;
	}
	v2 = *(uint32_t*)(a1 + 748);
	v3 = nox_xxx_guide_427010(*(const char**)(a2 + 736));
	if (nox_common_gameFlags_check_40A5C0(4096) && *(uint8_t*)(*(uint32_t*)(v2 + 276) + 2251) != 2) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "pickup.c:ObjectEquipClassFail", 0);
		return 0;
	}
	if (*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4 * v3 + 4244)) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "objcoll.c:AlreadyHaveGuide", 0);
		result = 0;
	} else {
		nox_xxx_awardBeastGuide_4FAE80_magic_plyrgide(a1, v3, 1);
		nox_xxx_delayedDeleteObject_4E5CC0(a2);
		result = 1;
	}
	return result;
}

//----- (0053F9E0) --------------------------------------------------------
int nox_xxx_useSpellReward_53F9E0(int a1, int a2) {
	unsigned char* v2; // ebx
	int v3;            // ebp
	int v4;            // edi
	int v5;            // ecx
	char v6;           // al

	v2 = *(unsigned char**)(a2 + 736);
	v3 = 0;
	v4 = *(uint32_t*)(a1 + 748);
	if (!(*(uint8_t*)(a1 + 8) & 4)) {
		return 0;
	}
	v5 = *(uint32_t*)(v4 + 276);
	v6 = *(uint8_t*)(v5 + 2251);
	if (v6 != 1 && v6 != 2) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "use.c:SpellRewardClassFail", 0);
	LABEL_7:
		nox_xxx_aud_501960(925, a1, 2, *(uint32_t*)(a1 + 36));
		return 0;
	}
	if (nox_xxx_playerCheckSpellClass_57AEA0(*(unsigned char*)(v5 + 2251), *v2)) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "use.c:SpellRewardClassFail", 0);
		goto LABEL_7;
	}
	if (nox_common_gameFlags_check_40A5C0(6144) && !*(uint32_t*)(*(uint32_t*)(v4 + 276) + 4 * *v2 + 3696)) {
		v3 = 1;
	}
	if (nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(a1, *v2, 1, v3, 0)) {
		nox_xxx_delayedDeleteObject_4E5CC0(a2);
	} else {
		nox_xxx_aud_501960(925, a1, 2, *(uint32_t*)(a1 + 36));
	}
	return 1;
}

//----- (0053FAE0) --------------------------------------------------------
int nox_xxx_useAbilityReward_53FAE0(int a1, int a2) {
	unsigned char* v2; // ebx
	int v3;            // ebp
	int v4;            // edi
	int result;        // eax

	v2 = *(unsigned char**)(a2 + 736);
	v3 = 0;
	v4 = *(uint32_t*)(a1 + 748);
	if (!(*(uint8_t*)(a1 + 8) & 4)) {
		return 0;
	}
	if (*(uint8_t*)(*(uint32_t*)(v4 + 276) + 2251)) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "pickup.c:ObjectEquipClassFail", 0);
		nox_xxx_aud_501960(925, a1, 2, *(uint32_t*)(a1 + 36));
		result = 0;
	} else {
		if (nox_common_gameFlags_check_40A5C0(6144) && !*(uint32_t*)(*(uint32_t*)(v4 + 276) + 4 * *v2 + 3696)) {
			v3 = 1;
		}
		if (nox_xxx_abilityRewardServ_4FB9C0_ability(a1, *v2, v3)) {
			nox_xxx_delayedDeleteObject_4E5CC0(a2);
		} else {
			nox_xxx_aud_501960(925, a1, 2, *(uint32_t*)(a1 + 36));
		}
		result = 1;
	}
	return result;
}

//----- (0053FBC0) --------------------------------------------------------
uint32_t* nox_xxx_respawnPlayerImpl_53FBC0(float* a1, int a2) {
	int v2;           // eax
	int v3;           // ebx
	float* v4;        // esi
	uint32_t* result; // eax
	uint32_t* v6;     // edi
	int v7;           // eax
	int v8;           // eax
	float v9;         // [esp+0h] [ebp-1Ch]
	float v10;        // [esp+4h] [ebp-18h]
	int* v11;         // [esp+24h] [ebp+8h]

	if (!*getMemU32Ptr(0x5D4594, 2488736)) {
		nox_xxx_createCorpse_53FCA0();
	}
	v2 = nox_xxx_math_509EA0(a2);
	v3 = 0;
	v4 = getMemFloatPtr(0x587000, 280376 + 88 * v2);
	v11 = getMemIntPtr(0x5D4594, 2488740 + 44 * v2);
	do {
		result = nox_xxx_newObjectWithTypeInd_4E3450(*v11);
		v6 = result;
		if (!result) {
			break;
		}
		if (dword_5d4594_2650652) {
			if (nox_common_gameFlags_check_40A5C0(0x2000)) {
				v7 = v6[4];
				LOBYTE(v7) = v7 | 0x40;
				v6[4] = v7;
			}
		}
		v10 = v4[1] + a1[1];
		v9 = *v4 + *a1;
		nox_xxx_createAt_4DAA50((int)v6, 0, v9, v10);
		v8 = nox_common_randomInt_415FA0(10, 20);
		result = (uint32_t*)nox_xxx_unitSetDecayTime_511660(v6, nox_gameFPS * v8);
		++v3;
		v4 += 2;
		++v11;
	} while (v3 < 11);
	return result;
}

//----- (0053FCA0) --------------------------------------------------------
void nox_xxx_createCorpse_53FCA0() {
	int i;             // ebx
	unsigned char* v1; // edi
	char v2[32];       // [esp+Ch] [ebp-20h]

	for (i = 0; i < 9; ++i) {
		switch (i) {
		case 0:
			v1 = getMemAt(0x587000, 281216);
			goto LABEL_11;
		case 1:
			v1 = getMemAt(0x587000, 281220);
			goto LABEL_11;
		case 2:
			v1 = getMemAt(0x587000, 281224);
			goto LABEL_11;
		case 3:
			v1 = getMemAt(0x587000, 281228);
			goto LABEL_11;
		case 5:
			v1 = getMemAt(0x587000, 281232);
			goto LABEL_11;
		case 6:
			v1 = getMemAt(0x587000, 281236);
			goto LABEL_11;
		case 7:
			v1 = getMemAt(0x587000, 281240);
			goto LABEL_11;
		case 8:
			v1 = getMemAt(0x587000, 281244);
		LABEL_11:
			nox_sprintf(v2, "CorpseSkull%s", v1);
			*getMemU32Ptr(0x5D4594, 2488740 + 44 * i) = nox_xxx_getNameId_4E3AA0(v2);
			nox_sprintf(v2, "CorpseRibCage%s", v1);
			*getMemU32Ptr(0x5D4594, 2488744 + 44 * i) = nox_xxx_getNameId_4E3AA0(v2);
			nox_sprintf(v2, "CorpsePelvis%s", v1);
			*getMemU32Ptr(0x5D4594, 2488748 + 44 * i) = nox_xxx_getNameId_4E3AA0(v2);
			nox_sprintf(v2, "CorpseLeftLowerLeg%s", v1);
			*getMemU32Ptr(0x5D4594, 2488752 + 44 * i) = nox_xxx_getNameId_4E3AA0(v2);
			nox_sprintf(v2, "CorpseLeftUpperLeg%s", v1);
			*getMemU32Ptr(0x5D4594, 2488756 + 44 * i) = nox_xxx_getNameId_4E3AA0(v2);
			nox_sprintf(v2, "CorpseLeftLowerArm%s", v1);
			*getMemU32Ptr(0x5D4594, 2488760 + 44 * i) = nox_xxx_getNameId_4E3AA0(v2);
			nox_sprintf(v2, "CorpseLeftUpperArm%s", v1);
			*getMemU32Ptr(0x5D4594, 2488764 + 44 * i) = nox_xxx_getNameId_4E3AA0(v2);
			nox_sprintf(v2, "CorpseRightLowerLeg%s", v1);
			*getMemU32Ptr(0x5D4594, 2488768 + 44 * i) = nox_xxx_getNameId_4E3AA0(v2);
			nox_sprintf(v2, "CorpseRightUpperLeg%s", v1);
			*getMemU32Ptr(0x5D4594, 2488772 + 44 * i) = nox_xxx_getNameId_4E3AA0(v2);
			nox_sprintf(v2, "CorpseRightLowerArm%s", v1);
			*getMemU32Ptr(0x5D4594, 2488776 + 44 * i) = nox_xxx_getNameId_4E3AA0(v2);
			nox_sprintf(v2, "CorpseRightUpperArm%s", v1);
			*getMemU32Ptr(0x5D4594, 2488780 + 44 * i) = nox_xxx_getNameId_4E3AA0(v2);
			break;
		default:
			continue;
		}
	}
	*getMemU32Ptr(0x5D4594, 2488736) = 1;
}

//----- (0053FEB0) --------------------------------------------------------
void nox_xxx_warriorBerserker_53FEB0(int a1) {
	int v1; // edi

	v1 = 0;
	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 4) {
			v1 = *(uint32_t*)(a1 + 748);
		}
		nox_xxx_cancelAllSpells_4FEE90(a1);
		if (nox_xxx_testUnitBuffs_4FF350(a1, 3)) {
			*(uint16_t*)(a1 + 126) = (unsigned char)(*(uint8_t*)(a1 + 124) + 4 * nox_common_randomInt_415FA0(-8, 8));
		}
		if (v1) {
			*(uint8_t*)(v1 + 236) = 0;
		}
		nox_xxx_playerSetState_4FA020((uint32_t*)a1, 1);
		nox_xxx_spellBuffOff_4FF5B0(a1, 0);
		nox_xxx_spellBuffOff_4FF5B0(a1, 23);
		nox_xxx_spellCancelDurSpell_4FEB10(67, a1);
		sub_4FC3C0(a1, 1, 1);
	}
}

//----- (0053FF40) --------------------------------------------------------
void nox_xxx_warriorWarcry_53FF40(int a1) {
	int v1; // eax

	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 4) {
			v1 = *(uint32_t*)(a1 + 748);
			if (v1) {
				*(uint8_t*)(v1 + 236) = 0;
			}
		}
		nox_xxx_playerSetState_4FA020((uint32_t*)a1, 1);
		nox_xxx_spell_4FE680(a1, 300.0);
		nox_xxx_unitsGetInCircle_517F90((float2*)(a1 + 56), 300.0, sub_53FFB0, a1);
		nox_xxx_spellBuffOff_4FF5B0(a1, 0);
		nox_xxx_spellBuffOff_4FF5B0(a1, 23);
		nox_xxx_spellCancelDurSpell_4FEB10(67, a1);
		sub_4FC3C0(a1, 2, 1);
	}
}

//----- (0053FFB0) --------------------------------------------------------
int sub_53FFB0(uint32_t* a1, uint32_t* a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // edx
	int v5[3];  // [esp+8h] [ebp-Ch]

	result = a1[2];
	if (result & 6 && !(a1[4] & 0x8020)) {
		if (result & 4) {
			result = a1[187];
			if (!result) {
				return result;
			}
			result = *(uint32_t*)(result + 276);
			if (!result) {
				return result;
			}
			if (!*(uint8_t*)(result + 2251)) {
				return result;
			}
			result = *(uint32_t*)(result + 3680) & 1;
			if ((uint8_t)result == 1) {
				return result;
			}
		} else if (result & 2 && !(*(uint8_t*)(a1[187] + 1440) & 0x20)) {
			return result;
		}
		result = nox_xxx_servCompareTeams_419150((int)(a2 + 12), (int)(a1 + 12));
		if (!result) {
			result = nox_xxx_mapCheck_537110((int)a1, (int)a2);
			if (result) {
				v3 = a1[14];
				v4 = a1[15];
				v5[0] = (int)a1;
				v5[1] = v3;
				v5[2] = v4;
				result = nox_xxx_spellAccept_4FD400(55, (int)a2, a2, (int)a2, v5, 5);
			}
		}
	}
	return result;
}

//----- (00540070) --------------------------------------------------------
int nox_xxx_warriorHarpoon_540070(uint32_t* a1) {
	int result; // eax
	int v2;     // edi

	result = nox_xxx_playerSetState_4FA020(a1, 32);
	if (a1) {
		v2 = a1[187];
		result = nox_xxx_createHarpoonBolt_538890((int)a1);
		if (v2) {
			*(uint32_t*)(v2 + 140) = 0;
		}
	}
	return result;
}

//----- (005400B0) --------------------------------------------------------
void nox_xxx_warriorTreadLightly_5400B0(uint32_t* a1, short a2) {
	int v2; // edi

	if (a1) {
		v2 = a1[187];
		if (v2) {
			if (*(uint8_t*)(v2 + 88) == 5) {
				nox_xxx_playerSetState_4FA020(a1, 13);
			}
			nox_xxx_buffApplyTo_4FF380((int)a1, 31, a2, *(uint32_t*)(*(uint32_t*)(v2 + 276) + 3712));
			sub_4FC3C0((int)a1, 4, 1);
			nox_xxx_frameCounterSetCopyToNextFrame_5281D0();
		}
	}
}

//----- (00540110) --------------------------------------------------------
void nox_xxx_warriorInfravis_540110(int a1, short a2) {
	if (a1) {
		nox_xxx_buffApplyTo_4FF380(a1, 21, a2, *(uint32_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 3716));
		sub_4FC3C0(a1, 5, 1);
	}
}

#ifndef NOX_CGO
//----- (00540160) --------------------------------------------------------
int nox_xxx_castMissilesOM_540160(int a1, int a2, int a3, int a4, int a5, int a6) {
	int v6;     // ebp
	int v7;     // edi
	int v8;     // eax
	int result; // eax
	int v10;    // ebx
	int v11;    // edi
	float v12;  // edx
	double v13; // st7
	double v14; // st6
	double v15; // st6
	float* v16; // esi
	int* v17;   // ebx
	double v18; // st7
	int v19;    // eax
	int v20;    // eax
	int v21;    // eax
	int v22;    // eax
	float v23;  // [esp+0h] [ebp-30h]
	float v24;  // [esp+0h] [ebp-30h]
	float v25;  // [esp+14h] [ebp-1Ch]
	float2 v26; // [esp+18h] [ebp-18h]
	float4 a1a; // [esp+20h] [ebp-10h]
	int v28;    // [esp+40h] [ebp+10h]
	int v29;    // [esp+48h] [ebp+18h]

	v6 = a4;
	v25 = *(float*)(a4 + 176) + 4.0;
	if (!*getMemU32Ptr(0x5D4594, 2489136)) {
		*getMemU32Ptr(0x5D4594, 2489136) = nox_xxx_getNameId_4E3AA0("MagicMissile");
	}
	v23 = nox_xxx_gamedataGetFloatTable_419D70("MagicMissileCount", a6 - 1);
	v28 = nox_float2int(v23);
	v7 = nox_xxx_unitIsUnitTT_4E7C80(a3, *getMemIntPtr(0x5D4594, 2489136));
	v24 = nox_xxx_gamedataGetFloatTable_419D70("MagicMissileCount", a6 - 1);
	v8 = nox_float2int(v24);
	if (v7 + v28 > v8) {
		v28 = v8 - v7;
	}
	if (v28) {
		v10 = 0;
		v29 = 0;
		if (v28 > 0) {
			v11 = a3;
			do {
				switch (v10) {
				case 0:
					v11 = *(short*)(v6 + 124);
					break;
				case 1:
					v11 = *(short*)(v6 + 124) - 16;
					break;
				case 2:
					v11 = *(short*)(v6 + 124) + 16;
					break;
				case 3:
					v11 = *(short*)(v6 + 124) - 32;
					break;
				case 4:
					v11 = *(short*)(v6 + 124) + 32;
					break;
				default:
					break;
				}
				if (v11 < 0) {
					v11 += (unsigned int)(255 - v11) >> 8 << 8;
				}
				if (v11 >= 256) {
					v11 += -256 * ((unsigned int)v11 >> 8);
				}
				v12 = *(float*)(v6 + 60);
				v13 = v25 * *getMemFloatPtr(0x587000, 194136 + 8 * v11) + *(float*)(v6 + 56);
				v14 = v25 * *getMemFloatPtr(0x587000, 194140 + 8 * v11);
				a1a.field_0 = *(float*)(v6 + 56);
				v15 = v14 + *(float*)(v6 + 60);
				a1a.field_4 = v12;
				a1a.field_C = v15;
				a1a.field_8 = v13 + *(float*)(v6 + 80);
				a1a.field_C = a1a.field_C + *(float*)(v6 + 84);
				if (nox_xxx_mapTraceRay_535250(&a1a, 0, 0, 5)) {
					v16 = (float*)nox_xxx_newObjectByTypeID_4E3810("MagicMissile");
					if (v16) {
						v17 = (int*)*((uint32_t*)v16 + 187);
						nox_xxx_createAt_4DAA50((int)v16, a3, a1a.field_8, a1a.field_C);
						v18 = nox_common_randomFloat_416030(0.80000001, 1.2) * v16[136];
						v16[136] = v18;
						v19 = 8 * (short)v11;
						*((uint16_t*)v16 + 63) = v11;
						*((uint16_t*)v16 + 62) = v11;
						v16[20] = v18 * *getMemFloatPtr(0x587000, 194136 + v19) * 0.1;
						v16[21] = v18 * *getMemFloatPtr(0x587000, 194140 + v19) * 0.1;
						v16[20] = v16[20] + *(float*)(v6 + 80);
						v16[21] = v16[21] + *(float*)(v6 + 84);
						if (*(uint8_t*)(v6 + 8) & 4) {
							v20 = *(uint32_t*)(v6 + 748);
							v26.field_0 = (double)*(int*)(*(uint32_t*)(v20 + 276) + 2284);
							v26.field_4 = (double)*(int*)(*(uint32_t*)(v20 + 276) + 2288);
							v21 = nox_xxx_spellFlySearchTarget_540610(&v26, (int)v16, 32, 600.0, 0, a3);
						} else {
							v21 = nox_xxx_spellFlySearchTarget_540610(0, (int)v16, 32, 600.0, 0, a3);
						}
						v17[1] = v21;
						v17[3] = a1;
						*v17 = a3;
						v10 = v29;
					}
				}
				v29 = ++v10;
			} while (v10 < v28);
		}
		v22 = nox_xxx_spellGetAud44_424800(a1, 0);
		nox_xxx_aud_501960(v22, v6, 0, 0);
		result = 1;
	} else {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a3, "mmissile.c:TooManyMissiles", 0);
		result = 0;
	}
	return result;
}
#endif // NOX_CGO

//----- (00540440) --------------------------------------------------------
int nox_xxx_castPixies_540440(int a1, int a2, int a3, int a4, int a5, int a6) {
	int v6;        // ebx
	int v7;        // eax
	int v8;        // esi
	int v9;        // eax
	int v10;       // ebp
	float v11;     // eax
	double v12;    // st7
	uint32_t* v13; // esi
	int* v14;      // edi
	int v15;       // eax
	float4 v17;    // [esp+Ch] [ebp-10h]
	float v18;     // [esp+2Ch] [ebp+10h]
	int v19;       // [esp+34h] [ebp+18h]

	v6 = a4;
	v7 = *getMemU32Ptr(0x5D4594, 2489140);
	v18 = *(float*)(a4 + 176) + 4.0;
	if (!*getMemU32Ptr(0x5D4594, 2489140)) {
		v7 = nox_xxx_getNameId_4E3AA0("Pixie");
		*getMemU32Ptr(0x5D4594, 2489140) = v7;
	}
	v8 = nox_xxx_unitIsUnitTT_4E7C80(a3, v7);
	if (v8 < (int)(long long)nox_xxx_gamedataGetFloatTable_419D70("PixieCount", a6 - 1)) {
		v9 = (unsigned long long)(long long)nox_xxx_gamedataGetFloatTable_419D70("PixieCount", a6 - 1) - v8;
		if (v9 > 0) {
			v19 = v9;
			do {
				v10 = nox_common_randomInt_415FA0(0, 255);
				v11 = *(float*)(v6 + 60);
				v12 = v18 * *getMemFloatPtr(0x587000, 194136 + 8 * v10) + *(float*)(v6 + 56);
				v17.field_0 = *(float*)(v6 + 56);
				v17.field_4 = v11;
				v17.field_8 = v12;
				v17.field_C = v18 * *getMemFloatPtr(0x587000, 194140 + 8 * v10) + *(float*)(v6 + 60);
				if (nox_xxx_mapTraceRay_535250(&v17, 0, 0, 5)) {
					v13 = nox_xxx_newObjectByTypeID_4E3810("Pixie");
					if (v13) {
						v14 = (int*)v13[187];
						nox_xxx_createAt_4DAA50((int)v13, a3, v17.field_8, v17.field_C);
						*((uint16_t*)v13 + 63) = v10;
						*((uint16_t*)v13 + 62) = v10;
						v13[20] = 0;
						v13[21] = 0;
						v14[1] = nox_xxx_spellFlySearchTarget_540610(0, (int)v13, 32, 600.0, 0, a3);
						*v14 = a3;
						v14[3] = a1;
						v13[39] = *(uint32_t*)(v6 + 56);
						v13[40] = *(uint32_t*)(v6 + 60);
						v14[5] = nox_frame_xxx_2598000 + nox_gameFPS * nox_common_randomInt_415FA0(30, 90);
						v14[6] = nox_frame_xxx_2598000;
					}
				}
				--v19;
			} while (v19);
		}
		v15 = nox_xxx_spellGetAud44_424800(a1, 0);
		nox_xxx_aud_501960(v15, v6, 0, 0);
	}
	return 1;
}

#ifndef NOX_CGO
//----- (00540610) --------------------------------------------------------
nox_object_t* nox_xxx_spellFlySearchTarget_540610(float2* a1, nox_object_t* a2p, int a3, float a4, int a5, nox_object_t* a6p) {
	int a2 = a2p;
	int a6 = a6p;
	int v6;     // ecx
	int v7;     // esi
	float v9;   // edx
	float v10;  // ecx
	float v11;  // edx
	float v12;  // edx
	int v13;    // ecx
	float v14;  // eax
	float4 v15; // [esp+10h] [ebp-38h]
	float4 a1a; // [esp+20h] [ebp-28h]
	int a3a[6]; // [esp+30h] [ebp-18h]

	if (a6) {
		if (*(uint8_t*)(a6 + 8) & 4) {
			if (a3 & 0x20) {
				v6 = *(uint32_t*)(a6 + 748);
				v7 = *(uint32_t*)(v6 + 288);
				if (v7) {
					if (nox_xxx_unitIsEnemyTo_5330C0(a6, *(uint32_t*)(v6 + 288)) && ((a5 == 1) || !a5 && a2 != v7)) {
						return v7;
					}
				}
			}
		}
	}
	*getMemU32Ptr(0x5D4594, 2489144) = a5;
	*getMemU32Ptr(0x5D4594, 2489152) = 0;
	*getMemU32Ptr(0x5D4594, 2489148) = 1287568416;
	if (!a1) {
		if (!a2) {
			return 0;
		}
		v12 = *(float*)(a2 + 60);
		a3a[3] = *(uint32_t*)(a2 + 56);
		*(float*)&a3a[4] = v12;
	} else if (a2) {
		v9 = *(float*)(a2 + 56);
		v10 = a1->field_0;
		v15.field_4 = *(float*)(a2 + 60);
		v15.field_0 = v9;
		v11 = a1->field_4;
		v15.field_8 = v10;
		v15.field_C = v11;
		if (nox_xxx_mapTraceRay_535250(&v15, 0, 0, 5)) {
			v12 = a1->field_4;
			a3a[3] = LODWORD(a1->field_0);
			*(float*)&a3a[4] = v12;
		} else {
			v13 = *(uint32_t*)(a2 + 60);
			a3a[3] = *(uint32_t*)(a2 + 56);
			a3a[4] = v13;
		}
	} else {
		v14 = a1->field_4;
		a3a[3] = LODWORD(a1->field_0);
		*(float*)&a3a[4] = v14;
	}
	a3a[1] = a2;
	a3a[0] = a3;
	*(float*)&a3a[2] = a4 * a4;
	a3a[5] = nox_xxx_findParentChainPlayer_4EC580(a2);
	a1a.field_0 = *(float*)&a3a[3] - a4;
	a1a.field_4 = *(float*)&a3a[4] - a4;
	a1a.field_8 = *(float*)&a3a[3] + a4;
	a1a.field_C = *(float*)&a3a[4] + a4;
	nox_xxx_getUnitsInRect_517C10(&a1a, sub_540780, (int)a3a);
	return *getMemU32Ptr(0x5D4594, 2489152);
}

//----- (00540780) --------------------------------------------------------
void sub_540780(float* a1, int a2) {
	float* v2; // esi
	int v3;    // eax
	int v4;    // ebx
	int v5;    // eax
	double v6; // st7
	double v7; // st6
	int v8;    // eax
	int v9;    // edi
	float v10; // [esp+Ch] [ebp+4h]

	v2 = a1;
	if (*getMemU32Ptr(0x5D4594, 2489144) || *(float**)(a2 + 4) != a1) {
		v3 = *((uint32_t*)a1 + 2);
		if (v3 & 0x20006) {
			if (!(v3 & 2) || (v4 = *((uint32_t*)a1 + 3), (v4 & 0x8000) == 0)) {
				if ((!(v3 & 4) || !(*(uint8_t*)(*(uint32_t*)(*((uint32_t*)a1 + 187) + 276) + 3680) & 1)) &&
					!((uint32_t)a1[4] & 0x8020)) {
					if (!(v3 & 2) || (v5 = *((uint32_t*)a1 + 3), !(v5 & 0x4000))) {
						nox_xxx_findParentChainPlayer_4EC580((int)a1);
						if (!(*(uint8_t*)a2 & 0x20) || nox_xxx_unitIsEnemyTo_5330C0(*(uint32_t*)(a2 + 4), (int)a1)) {
							v6 = *(float*)(a2 + 12) - a1[14];
							v7 = *(float*)(a2 + 16) - a1[15];
							v10 = v7 * v7 + v6 * v6;
							if (v10 <= (double)*(float*)(a2 + 8)) {
								v8 = *(uint32_t*)(a2 + 4);
								if (!v8 || nox_xxx_unitCanInteractWith_5370E0(v8, (int)v2, 0)) {
									v9 = *(uint32_t*)(a2 + 20);
									if ((!v9 || nox_xxx_unitCanInteractWith_5370E0(v9, (int)v2, 0)) &&
										v10 < (double)*getMemFloatPtr(0x5D4594, 2489148)) {
										*getMemU32Ptr(0x5D4594, 2489152) = v2;
										*getMemFloatPtr(0x5D4594, 2489148) = v7 * v7 + v6 * v6;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
#endif // NOX_CGO

//----- (005408A0) --------------------------------------------------------
int sub_5408A0(int a1) {
	int v1; // ecx

	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 24 * (*(char*)(*(uint32_t*)(a1 + 748) + 544) + 23));
	return v1 >= 18 && v1 <= 20;
}

//----- (005408D0) --------------------------------------------------------
int nox_xxx_mobCastInversion_5408D0(int a1) {
	int v1;       // ebx
	int v2;       // esi
	int* v3;      // edi
	uint32_t* v4; // ebp
	int v5;       // eax
	float v7;     // [esp+0h] [ebp-240h]
	int v8;       // [esp+18h] [ebp-228h]
	int v9[137];  // [esp+1Ch] [ebp-224h]

	v1 = *(uint32_t*)(a1 + 748);
	v8 = 0;
	if (!(*(uint32_t*)(a1 + 16) & 0x1000000)) {
		return 0;
	}
	if (!nox_xxx_monsterCanCast_534300(a1)) {
		return 0;
	}
	if (nox_frame_xxx_2598000 < *(int*)(v1 + 1452)) {
		return 0;
	}
	if (sub_5408A0(a1)) {
		return 0;
	}
	*getMemU32Ptr(0x5D4594, 2489156) = 0;
	v7 = nox_xxx_gamedataGetFloat_419D40("InversionRange") * 0.5;
	sub_518170(a1 + 56, v7, nox_xxx_unitIsMagicMissile_540B60, a1);
	if (!*getMemU32Ptr(0x5D4594, 2489156)) {
		return 0;
	}
	v2 = 1;
	v3 = v9;
	v4 = (uint32_t*)(v1 + 1492);
	do {
		if (*v4 & 0x8000000) {
			if (nox_xxx_spellHasFlags_424A50(v2, 16)) {
				*v3 = v2;
				++v3;
				++v8;
			}
		}
		++v2;
		++v4;
	} while (v2 < 137);
	if (!v8) {
		return 0;
	}
	v5 = nox_common_randomInt_415FA0(0, v8 - 1);
	nox_xxx_monsterCast_540A30(a1, v9[v5], a1);
	*(uint32_t*)(v1 + 1452) = nox_frame_xxx_2598000 +
							  nox_common_randomInt_415FA0(*(unsigned short*)(v1 + 1448), *(unsigned short*)(v1 + 1450));
	return 1;
}
// 5408D0: using guessed type int var_224[137];

#ifndef NOX_CGO
//----- (00540A30) --------------------------------------------------------
void nox_xxx_monsterCast_540A30(nox_object_t* a1p, int a2, nox_object_t* a3p) {
	int a1 = a1p;
	int a3 = a3p;
	int v3;      // esi
	int* v4;     // ebx
	int* result; // eax
	int* v6;     // eax
	int* v7;     // eax
	int* v8;     // eax
	int v9;      // edx
	int v10;     // [esp-8h] [ebp-14h]
	int v11;     // [esp+10h] [ebp+4h]

	v3 = a1;
	v10 = a1;
	v11 = *(uint32_t*)(a1 + 748);
	nox_xxx_monsterPushAction_50A260(v10, 61);
	if (nox_xxx_spellHasFlags_424A50(a2, 2)) {
		v4 = nox_xxx_monsterPushAction_50A260(v3, 41);
		if (v4) {
			v4[1] = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(nox_gameFPS >> 1, 2 * nox_gameFPS);
		}
		result = nox_xxx_monsterPushAction_50A260(v3, 20);
		if (result) {
			goto LABEL_7;
		}
	} else {
		result = nox_xxx_monsterPushAction_50A260(v3, 18);
		if (result) {
		LABEL_7:
			result[1] = a2;
			result[3] = a3;
			goto LABEL_8;
		}
	}
LABEL_8:
	if (a3 != v3) {
		result = (int*)nox_xxx_monsterIsActionScheduled_50A090(v3, 24);
		if (!result) {
			if (!nox_xxx_spellHasFlags_424A50(a2, 4)) {
				v6 = nox_xxx_monsterPushAction_50A260(v3, 26);
				if (v6) {
					v6[1] = a3;
				}
				v7 = nox_xxx_monsterPushAction_50A260(v3, 47);
				if (v7) {
					v7[1] = a3;
				}
			}
			v8 = nox_xxx_monsterPushAction_50A260(v3, 49);
			if (v8) {
				v9 = *(uint32_t*)(*(uint32_t*)(v11 + 484) + 212);
				v8[3] = a3;
				v8[1] = v9;
			}
			nox_xxx_monsterPushAction_50A260(v3, 40);
			result = nox_xxx_monsterPushAction_50A260(v3, 7);
			if (result) {
				result[1] = *(uint32_t*)(a3 + 56);
				result[2] = *(uint32_t*)(a3 + 60);
				result[3] = a3;
			}
		}
	}
}
#endif // NOX_CGO

//----- (00540B60) --------------------------------------------------------
int nox_xxx_unitIsMagicMissile_540B60(int a1, int a2) {
	int result; // eax

	result = a1;
	if (*(uint8_t*)(a1 + 8) & 1 && *(uint8_t*)(a1 + 12) & 2) {
		result = a2;
		if (*(uint32_t*)(*(uint32_t*)(a1 + 748) + 4) == a2) {
			*getMemU32Ptr(0x5D4594, 2489156) = 1;
		}
	}
	return result;
}

//----- (00540B90) --------------------------------------------------------
int nox_xxx_monsterBuffSelf_540B90(int a1) {
	int v1;       // edi
	int v2;       // ebp
	int v3;       // esi
	int* v4;      // ebx
	uint32_t* v5; // ebp
	int v6;       // esi
	int* v7;      // ebx
	int v8;       // ebp
	int v9;       // eax
	int v11;      // [esp+10h] [ebp-228h]
	int v12[137]; // [esp+14h] [ebp-224h]

	v1 = 0;
	v2 = *(uint32_t*)(a1 + 748);
	v11 = *(uint32_t*)(a1 + 748);
	if (!(*(uint32_t*)(a1 + 16) & 0x1000000) || !nox_xxx_monsterCanCast_534300(a1) ||
		nox_frame_xxx_2598000 < *(int*)(v2 + 1460) || sub_5408A0(a1)) {
		return 0;
	}
	v3 = 1;
	v4 = v12;
	v5 = (uint32_t*)(v2 + 1492);
	do {
		if (*v5 & 0x10000000) {
			if (nox_xxx_spellHasFlags_424A50(v3, 16)) {
				*v4 = v3;
				++v1;
				++v4;
			}
		}
		++v3;
		++v5;
	} while (v3 < 137);
	if (!v1) {
		return 0;
	}
	v6 = 0;
	if (v1 > 0) {
		v7 = v12;
		while (1) {
			v8 = a1;
			if (sub_540CE0(a1, *v7)) {
				return 0;
			}
			++v6;
			++v7;
			if (v6 >= v1) {
				goto LABEL_17;
			}
		}
	}
	v8 = a1;
LABEL_17:
	v9 = nox_common_randomInt_415FA0(0, v1 - 1);
	nox_xxx_monsterCast_540A30(v8, v12[v9], v8);
	*(uint32_t*)(v11 + 1460) = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(*(unsigned short*)(v11 + 1456),
																				   *(unsigned short*)(v11 + 1458));
	return 1;
}
// 540B90: using guessed type int var_224[137];

//----- (00540CE0) --------------------------------------------------------
int sub_540CE0(int a1, int a2) {
	int i;      // esi
	int result; // eax

	for (i = 0; i < 32; ++i) {
		if (nox_xxx_getEnchantSpell_424920(i) == a2) {
			break;
		}
	}
	if (i == 32) {
		result = 0;
	} else {
		result = nox_xxx_testUnitBuffs_4FF350(a1, i);
	}
	return result;
}

//----- (00540D20) --------------------------------------------------------
int sub_540D20(int a1) { return a1 >= 75 && a1 <= 114; }

//----- (00540D40) --------------------------------------------------------
int sub_540D40(int a1) {
	int v1; // esi

	v1 = nox_xxx_spellCastedFirst_4FE930();
	if (!v1) {
		return 0;
	}
	while (!sub_540D20(*(uint32_t*)(v1 + 4)) || *(uint32_t*)(v1 + 16) != a1) {
		v1 = nox_xxx_spellCastedNext_4FE940(v1);
		if (!v1) {
			return 0;
		}
	}
	return 1;
}

//----- (00540D90) --------------------------------------------------------
int nox_xxx_mobCastRelated2_540D90(int a1, int a2) {
	int v2;       // ebp
	int v3;       // ebx
	int v4;       // esi
	int* v5;      // edi
	uint32_t* v6; // ebx
	int v7;       // esi
	int v8;       // edi
	uint8_t v9;   // eax
	int v11;      // [esp+10h] [ebp-22Ch]
	int v12;      // [esp+14h] [ebp-228h]
	int v13[137]; // [esp+18h] [ebp-224h]

	v2 = 0;
	v3 = *(uint32_t*)(a1 + 748);
	v12 = *(uint32_t*)(a1 + 748);
	if (*(uint32_t*)(a1 + 16) & 0x1000000 && nox_xxx_monsterCanCast_534300(a1) &&
		nox_frame_xxx_2598000 >= *(int*)(v3 + 1476) && !sub_5408A0(a1)) {
		v4 = 1;
		v5 = v13;
		v11 = 1;
		v6 = (uint32_t*)(v3 + 1492);
		do {
			if (*v6 & 0x40000000 && nox_xxx_spellHasFlags_424A50(v4, 16)) {
				*v5 = v4;
				++v2;
				++v5;
				if (!sub_540D20(v4)) {
					v11 = 0;
				}
			}
			++v4;
			++v6;
		} while (v4 < 137);
		if (v2) {
			while (1) {
				while (1) {
					v7 = nox_common_randomInt_415FA0(0, v2 - 1);
					v8 = v13[v7];
					if (sub_540D20(v13[v7])) {
						break;
					}
				LABEL_19:
					if (v7 >= 0) {
						nox_xxx_monsterCast_540A30(a1, v13[v7], a2);
						*(uint32_t*)(v12 + 1476) =
							nox_frame_xxx_2598000 +
							nox_common_randomInt_415FA0(*(unsigned short*)(v12 + 1472), *(unsigned short*)(v12 + 1474));
						return 1;
					}
				}
				if (sub_540D40(a1)) {
					if (v11) {
						return 0;
					}
				} else {
					v9 = nox_xxx_checkSummonedCreaturesLimit_500D70(a1, v8 - 74);
					if (v9) {
						goto LABEL_19;
					}
					if (v11) {
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
// 540E9A: variable 'v9' is possibly undefined
// 540D90: using guessed type int var_224[137];

//----- (00540F20) --------------------------------------------------------
int nox_xxx_monsterCastOffensive_540F20(int a1, int a2) {
	int v2;       // edi
	int v3;       // esi
	int* v4;      // ebx
	uint32_t* v5; // ebp
	int v6;       // eax
	int v8;       // [esp+8h] [ebp-228h]
	int v9[137];  // [esp+Ch] [ebp-224h]

	v8 = 0;
	v2 = *(uint32_t*)(a1 + 748);
	if (!(*(uint32_t*)(a1 + 16) & 0x1000000) || !nox_xxx_monsterCanCast_534300(a1) ||
		nox_frame_xxx_2598000 < *(int*)(v2 + 1468) || sub_5408A0(a1)) {
		return 0;
	}
	v3 = 1;
	v4 = v9;
	v5 = (uint32_t*)(v2 + 1492);
	do {
		if (*v5 & 0x20000000) {
			if (nox_xxx_spellHasFlags_424A50(v3, 16)) {
				*v4 = v3;
				++v4;
				++v8;
			}
		}
		++v3;
		++v5;
	} while (v3 < 137);
	if (!v8) {
		return 0;
	}
	v6 = nox_common_randomInt_415FA0(0, v8 - 1);
	nox_xxx_monsterCast_540A30(a1, v9[v6], a2);
	*(uint32_t*)(v2 + 1468) = nox_frame_xxx_2598000 +
							  nox_common_randomInt_415FA0(*(unsigned short*)(v2 + 1464), *(unsigned short*)(v2 + 1466));
	return 1;
}
// 540F20: using guessed type int var_224[137];

//----- (00541050) --------------------------------------------------------
int nox_xxx_mobCastRelated_541050(int a1) {
	int v1;       // edi
	int v2;       // ebp
	int v3;       // esi
	int* v4;      // ebx
	uint32_t* v5; // ebp
	int v6;       // esi
	int* v7;      // ebx
	int v8;       // ebp
	int v9;       // eax
	int v11;      // [esp+10h] [ebp-228h]
	int v12[137]; // [esp+14h] [ebp-224h]

	v1 = 0;
	v2 = *(uint32_t*)(a1 + 748);
	v11 = *(uint32_t*)(a1 + 748);
	if (!(*(uint32_t*)(a1 + 16) & 0x1000000) || !nox_xxx_monsterCanCast_534300(a1) ||
		nox_frame_xxx_2598000 < *(int*)(v2 + 1484) || sub_5408A0(a1)) {
		return 0;
	}
	v3 = 1;
	v4 = v12;
	v5 = (uint32_t*)(v2 + 1492);
	do {
		if ((int)*v5 < 0) {
			if (nox_xxx_spellHasFlags_424A50(v3, 16)) {
				*v4 = v3;
				++v1;
				++v4;
			}
		}
		++v3;
		++v5;
	} while (v3 < 137);
	if (!v1) {
		return 0;
	}
	v6 = 0;
	if (v1 > 0) {
		v7 = v12;
		while (1) {
			v8 = a1;
			if (sub_540CE0(a1, *v7)) {
				return 0;
			}
			++v6;
			++v7;
			if (v6 >= v1) {
				goto LABEL_17;
			}
		}
	}
	v8 = a1;
LABEL_17:
	v9 = nox_common_randomInt_415FA0(0, v1 - 1);
	nox_xxx_monsterCast_540A30(v8, v12[v9], v8);
	*(uint32_t*)(v11 + 1484) = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(*(unsigned short*)(v11 + 1480),
																				   *(unsigned short*)(v11 + 1482));
	return 1;
}
// 541050: using guessed type int var_224[137];

//----- (005411A0) --------------------------------------------------------
int nox_xxx_mobHealSomeone_5411A0(int a3) {
	int v1;            // edi
	int v2;            // edx
	uint16_t* v3;      // ecx
	unsigned short v4; // ax
	int v6;            // eax
	double v7;         // st7
	float4 a1;         // [esp+8h] [ebp-10h]

	v1 = *(uint32_t*)(a3 + 748);
	if (!(*(uint32_t*)(a3 + 16) & 0x1000000) || !nox_xxx_monsterCanCast_534300(a3) ||
		(unsigned char)nox_frame_xxx_2598000 & 0x1F || sub_5408A0(a3)) {
		return 0;
	}
	v2 = *(uint32_t*)(v1 + 1440);
	if (v2 & 0x800) {
		v3 = *(uint16_t**)(a3 + 556);
		v4 = v3[2];
		if (v4) {
			if (*v3 < (unsigned int)(v4 >> 1)) {
				nox_xxx_monsterCast_540A30(a3, 41, a3);
				return 0;
			}
		}
	}
	if (!(v2 & 0x1000)) {
		return 0;
	}
	v6 = nox_common_gameFlags_check_40A5C0(4096);
	dword_5d4594_2489160 = 0;
	v7 = (double)(v6 ? 640 : 250);
	a1.field_0 = *(float*)(a3 + 56) - v7;
	a1.field_4 = *(float*)(a3 + 60) - v7;
	a1.field_8 = v7 + *(float*)(a3 + 56);
	a1.field_C = v7 + *(float*)(a3 + 60);
	nox_xxx_getUnitsInRect_517C10(&a1, nox_xxx_mobMayHealThis_5412A0, a3);
	if (!dword_5d4594_2489160) {
		return 0;
	}
	nox_xxx_monsterCast_540A30(a3, 41, *(int*)&dword_5d4594_2489160);
	return 1;
}

//----- (005412A0) --------------------------------------------------------
void nox_xxx_mobMayHealThis_5412A0(float* a1, int a2) {
	int v2; // eax

	if ((float*)a2 != a1 && !nox_xxx_unitIsEnemyTo_5330C0(a2, (int)a1)) {
		if (*((uint32_t*)a1 + 139)) {
			v2 = *((uint32_t*)a1 + 4);
			if ((v2 & 0x8000) == 0) {
				if (nox_xxx_unitCanInteractWith_5370E0(a2, (int)a1, 0)) {
					if (**((uint16_t**)a1 + 139) < (unsigned int)(*(uint16_t*)(*((uint32_t*)a1 + 139) + 4) >> 1)) {
						dword_5d4594_2489160 = a1;
					}
				}
			}
		}
	}
}

//----- (00541300) --------------------------------------------------------
char nox_xxx_mobCast_541300(int a1, uint32_t* a2, int a3) {
	int v3; // edi
	int v4; // eax

	v3 = a2[187];
	if (*(uint32_t*)(v3 + 1440) & 0x20000) {
		nox_xxx_mobMorphToPlayer_4FAAF0(a2);
	}
	nox_xxx_mobCalcDir_533CC0((int)a2, (float*)(a3 + 4));
	nox_xxx_castSpellByUser_4FDD20(a1, a2, (int*)a3);
	v4 = *(uint32_t*)(v3 + 1440);
	if (v4 & 0x20000) {
		LOBYTE(v4) = nox_xxx_mobMorphFromPlayer_4FAAC0(a2);
	}
	return v4;
}

//----- (00541360) --------------------------------------------------------
char nox_xxx_mobActionCastOnObj_541360(uint32_t* a1) {
	int v1;      // esi
	char result; // al

	v1 = a1[187];
	if (!*(uint32_t*)(v1 + 24 * *(char*)(v1 + 544) + 564) ||
		(nox_xxx_mobActionCast_5413B0(a1, 0), (result = *(uint8_t*)(v1 + 483)) != 0)) {
		result = nox_xxx_monsterPopAction_50A160((int)a1);
	}
	return result;
}

//----- (005413B0) --------------------------------------------------------
char nox_xxx_mobActionCast_5413B0(uint32_t* a1, int a2) {
	int v2;    // ecx
	int* v3;   // edi
	int v4;    // eax
	int v5;    // eax
	int v6;    // ecx
	int v8[3]; // [esp+8h] [ebp-Ch]

	v2 = a1[187];
	v3 = (int*)(v2 + 24 * (*(char*)(v2 + 544) + 23));
	LOBYTE(v4) = *(uint8_t*)(v2 + 482);
	if (!(uint8_t)v4) {
		LOBYTE(v4) = *(uint8_t*)(v2 + 481);
		if ((unsigned char)v4 == *(uint32_t*)(*(uint32_t*)(v2 + 484) + 216)) {
			if (a2) {
				LOBYTE(v4) = a2 - 1;
				if (a2 != 1) {
					return v4;
				}
				v5 = v3[3];
				v6 = v3[4];
				v8[0] = 0;
				v8[1] = v5;
				v8[2] = v6;
			} else {
				v8[0] = v3[3];
				nox_xxx_mobCastRandomRecoil_541490((int)a1, (float*)v8[0], (float2*)&v8[1]);
			}
			v4 = nox_xxx_testUnitBuffs_4FF350((int)a1, 29);
			if (!v4) {
				LOBYTE(v4) = nox_xxx_mobCast_541300(v3[1], a1, (int)v8);
			}
		} else if ((uint8_t)v4 == 1) {
			v4 = nox_xxx_monsterGetSoundSet_424300((int)a1);
			if (v4) {
				LOBYTE(v4) = (unsigned int)nox_xxx_aud_501960(*(uint32_t*)(v4 + 56), (int)a1, 0, 0);
			}
		}
	}
	return v4;
}

//----- (00541490) --------------------------------------------------------
void nox_xxx_mobCastRandomRecoil_541490(int a1, float* a2, float2* a3) {
	double v3; // st7
	float v4;  // [esp+4h] [ebp-14h]
	float v5;  // [esp+1Ch] [ebp+4h]
	float v6;  // [esp+1Ch] [ebp+4h]

	v5 = 1.0 - *(float*)(*(uint32_t*)(a1 + 748) + 1320);
	*a3 = *((float2*)a2 + 7);
	v4 = v5 + 1.0;
	v3 = nox_common_randomFloat_416030(v5, v4);
	a3->field_0 = a3->field_0 - v3 * a2[20] * 6.0;
	a3->field_4 = a3->field_4 - v3 * a2[21] * 6.0;
	v6 = v5 * 0.80000001 + 0.2;
	a3->field_0 = nox_common_randomFloat_416030(-60.0, 60.0) * v6 + a3->field_0;
	a3->field_4 = nox_common_randomFloat_416030(-60.0, 60.0) * v6 + a3->field_4;
}

//----- (00541560) --------------------------------------------------------
char nox_xxx_mobActionCastOnPoint_541560(uint32_t* a1) {
	int v1;      // edi
	char result; // al

	v1 = a1[187];
	nox_xxx_mobActionCast_5413B0(a1, 1);
	result = *(uint8_t*)(v1 + 483);
	if (result) {
		result = nox_xxx_monsterPopAction_50A160((int)a1);
	}
	return result;
}

//----- (00541590) --------------------------------------------------------
uint32_t* nox_xxx_mobActionCastStopMB_541590(int a1) {
	return nox_xxx_spellCancelDurSpell_4FEB10(
		*(uint32_t*)(*(uint32_t*)(a1 + 748) + 24 * *(char*)(*(uint32_t*)(a1 + 748) + 544) + 556), a1);
}

//----- (005415C0) --------------------------------------------------------
char nox_xxx_mobActionCastFinishMB_5415C0(int a1) {
	nox_xxx_spellCancelDurSpell_4FEB10(
		*(uint32_t*)(*(uint32_t*)(a1 + 748) + 24 * *(char*)(*(uint32_t*)(a1 + 748) + 544) + 556), a1);
	return nox_xxx_monsterPopAction_50A160(a1);
}

//----- (005415F0) --------------------------------------------------------
char nox_xxx_mobActionCastStart_5415F0(uint32_t* a1) {
	char result; // al

	if (*(uint32_t*)(a1[187] + 24 * *(char*)(a1[187] + 544) + 564)) {
		result = nox_xxx_mobActionCast_5413B0(a1, 0);
	} else {
		result = nox_xxx_monsterPopAction_50A160((int)a1);
	}
	return result;
}

//----- (00541630) --------------------------------------------------------
char sub_541630(int a1, int a2) {
	uint32_t* v2; // eax
	int v3;       // ecx

	v2 = (uint32_t*)(*(uint32_t*)(a1 + 748) + 24 * (*(char*)(*(uint32_t*)(a1 + 748) + 544) + 23));
	if (*v2 == 20) {
		v3 = v2[1];
		LOBYTE(v2) = a2;
		if (v3 == a2) {
			LOBYTE(v2) = nox_xxx_monsterPopAction_50A160(a1);
		}
	}
	return (char)v2;
}

//----- (00542BF0) --------------------------------------------------------
char* sub_542BF0(int a1, int a2, int a3) {
	int** v3;         // eax
	int* v4;          // ebx
	char* v5;         // esi
	char* v6;         // edx
	const char* v7;   // eax
	int v8;           // esi
	char* v9;         // eax
	char* v10;        // eax
	int (*v11)(int*); // eax
	const char* v12;  // edx
	char* v13;        // eax
	const char* v14;  // edx
	char* v15;        // eax
	const char* v16;  // edx
	const char* v17;  // edx
	char* v18;        // eax
	const char* v19;  // edx
	char* v20;        // eax
	const char* v21;  // edx
	char* v22;        // eax
	const char* v23;  // edx
	char* v24;        // eax
	const char* v25;  // edx
	char* v26;        // eax
	const char* v27;  // edx
	char* v28;        // eax
	const char* v29;  // edx
	char* v30;        // eax
	const char* v31;  // edx
	char* v32;        // eax
	const char* v33;  // edx
	const char* v34;  // edx
	const char* v35;  // eax
	char* v36;        // eax
	const char* v37;  // eax
	char* v38;        // eax
	const char* v39;  // eax
	char* v40;        // eax
	const char* v41;  // eax
	char* result;     // eax
	char* i;          // ebx
	char* v44;        // [esp-14h] [ebp-28h]
	char* v45;        // [esp-14h] [ebp-28h]
	char* v46;        // [esp-14h] [ebp-28h]
	char* v47;        // [esp-14h] [ebp-28h]
	int v48;          // [esp+10h] [ebp-4h]

	v3 = (int**)sub_5049D0();
	v48 = (int)v3;
	if (v3) {
		while (1) {
			v4 = *v3;
			if (((*v3)[4] & 0x80000000) == 0x80000000) {
				if (*v4) {
					v5 = sub_543620(*v4, a1);
					v6 = (char*)realloc((void*)*v4, strlen(v5) + 1);
					*v4 = (int)v6;
					strcpy(v6, v5);
				}
				v7 = (const char*)sub_508CB0(v4, 14);
				if (v7) {
					v8 = a3;
					if (strlen(v7)) {
						v9 = sub_5435C0((int)v7, a1, a2, a3);
						sub_509120(v4, 14, v9);
					}
				} else {
					v8 = a3;
				}
				v10 = (char*)nox_xxx_getUnitName_4E39D0((int)v4);
				v11 = *(int (**)(int*))(nox_xxx_objectTypeByID_4E3B60(v10) + 212);
				if (v11 == nox_xxx_unitTriggerXfer_4F4E50) {
					v12 = (const char*)sub_508CB0(v4, 1);
					if (strlen(v12)) {
						v13 = sub_5435C0((int)v12, a1, a2, v8);
						sub_509120(v4, 1, v13);
					}
					v14 = (const char*)sub_508CB0(v4, 2);
					if (strlen(v14)) {
						v15 = sub_5435C0((int)v14, a1, a2, v8);
						sub_509120(v4, 2, v15);
					}
					v16 = (const char*)sub_508CB0(v4, 0);
					if (strlen(v16)) {
						v44 = sub_5435C0((int)v16, a1, a2, v8);
						sub_509120(v4, 0, v44);
					}
				} else if (v11 == nox_xxx_XFerMonster_528DB0) {
					v17 = (const char*)sub_508CB0(v4, 3);
					if (strlen(v17)) {
						v18 = sub_5435C0((int)v17, a1, a2, v8);
						sub_509120(v4, 3, v18);
					}
					v19 = (const char*)sub_508CB0(v4, 5);
					if (strlen(v19)) {
						v20 = sub_5435C0((int)v19, a1, a2, v8);
						sub_509120(v4, 5, v20);
					}
					v21 = (const char*)sub_508CB0(v4, 4);
					if (strlen(v21)) {
						v22 = sub_5435C0((int)v21, a1, a2, v8);
						sub_509120(v4, 4, v22);
					}
					v23 = (const char*)sub_508CB0(v4, 6);
					if (strlen(v23)) {
						v24 = sub_5435C0((int)v23, a1, a2, v8);
						sub_509120(v4, 6, v24);
					}
					v25 = (const char*)sub_508CB0(v4, 7);
					if (strlen(v25)) {
						v26 = sub_5435C0((int)v25, a1, a2, v8);
						sub_509120(v4, 7, v26);
					}
					v27 = (const char*)sub_508CB0(v4, 8);
					if (strlen(v27)) {
						v28 = sub_5435C0((int)v27, a1, a2, v8);
						sub_509120(v4, 8, v28);
					}
					v29 = (const char*)sub_508CB0(v4, 9);
					if (strlen(v29)) {
						v30 = sub_5435C0((int)v29, a1, a2, v8);
						sub_509120(v4, 9, v30);
					}
					v31 = (const char*)sub_508CB0(v4, 10);
					if (strlen(v31)) {
						v32 = sub_5435C0((int)v31, a1, a2, v8);
						sub_509120(v4, 10, v32);
					}
					v33 = (const char*)sub_508CB0(v4, 11);
					if (strlen(v33)) {
						v45 = sub_5435C0((int)v33, a1, a2, v8);
						sub_509120(v4, 11, v45);
					}
				} else if (v11 == nox_xxx_XFerHole_4F51D0) {
					v34 = (const char*)sub_508CB0(v4, 12);
					if (strlen(v34)) {
						v46 = sub_5435C0((int)v34, a1, a2, v8);
						sub_509120(v4, 12, v46);
					}
				} else if (v11 == nox_xxx_XFerMonsterGen_4F7130) {
					v35 = (const char*)sub_508CB0(v4, 15);
					if (v35 && strlen(v35)) {
						v36 = sub_5435C0((int)v35, a1, a2, v8);
						sub_509120(v4, 15, v36);
					}
					v37 = (const char*)sub_508CB0(v4, 16);
					if (v37 && strlen(v37)) {
						v38 = sub_5435C0((int)v37, a1, a2, v8);
						sub_509120(v4, 16, v38);
					}
					v39 = (const char*)sub_508CB0(v4, 18);
					if (v39 && strlen(v39)) {
						v40 = sub_5435C0((int)v39, a1, a2, v8);
						sub_509120(v4, 18, v40);
					}
					v41 = (const char*)sub_508CB0(v4, 17);
					if (v41 && strlen(v41)) {
						v47 = sub_5435C0((int)v41, a1, a2, v8);
						sub_509120(v4, 17, v47);
					}
				}
				v4[4] &= 0x7FFFFFFFu;
				v3 = (int**)v48;
			}
			v48 = sub_5049E0((int)v3);
			if (!v48) {
				break;
			}
			v3 = (int**)v48;
		}
	}
	result = (char*)nox_xxx_waypointGetList_579860();
	for (i = result; result; i = result) {
		if (*((int*)i + 120) < 0) {
			if ((int)strlen(i + 16) > 0) {
				strcpy(i + 16, sub_543620((int)(i + 16), a1));
			}
			*((uint32_t*)i + 120) &= 0x7FFFFFFFu;
		}
		result = (char*)nox_xxx_waypointNext_579870((int)i);
	}
	return result;
}
// 543110: using guessed type char NewFileName[2048];

//----- (005435C0) --------------------------------------------------------
char* sub_5435C0(int a1, int a2, int a3, int a4) {
	nox_sprintf((char*)getMemAt(0x5D4594, 2489164), "%s%%%d%%%d%%%d", a1, a2, a3, a4);
	strlen((const char*)getMemAt(0x5D4594, 2489164));
	strcpy((char*)getMemAt(0x5D4594, 2489164), "ERROR_NAME_TOO_LONG!");
	return (char*)getMemAt(0x5D4594, 2489164);
}

//----- (00543620) --------------------------------------------------------
char* sub_543620(int a1, int a2) {
	nox_sprintf((char*)getMemAt(0x5D4594, 2489164), "%s%%%d", a1, a2);
	strlen((const char*)getMemAt(0x5D4594, 2489164));
	strcpy((char*)getMemAt(0x5D4594, 2489164), "ERROR_NAME_TOO_LONG!");
	return (char*)getMemAt(0x5D4594, 2489164);
}

//----- (00543680) --------------------------------------------------------
int sub_543680(float* a1) {
	int result; // eax
	float2 a2;  // [esp+0h] [ebp-30h]
	int2 v3;    // [esp+8h] [ebp-28h]
	int v4[8];  // [esp+10h] [ebp-20h]

	if (dword_5d4594_3835356 == 255) {
		return 1;
	}
	result = nox_xxx_mapGenFixCoords_4D3D90((float2*)a1, &a2);
	if (result) {
		v4[0] = *getMemU32Ptr(0x973F18, 35912);
		dword_5d4594_3835352 = 1;
		v4[1] = dword_5d4594_3835348;
		v4[6] = dword_5d4594_3835356;
		v4[7] = dword_5d4594_3835360;
		v3.field_0 = (long long)a2.field_0;
		v3.field_4 = (long long)a2.field_4;
		result = sub_5437E0(&v3.field_0, (int)v4, 46);
		dword_5d4594_3835352 = 0;
	}
	return result;
}

//----- (00543720) --------------------------------------------------------
void nox_xxx_unused_543720(int a1, int a2, int a3, int a4) {
	int result; // eax
	int v5;     // ecx

	if (dword_5d4594_2489432 >= 500) {
		*getMemU32Ptr(0x973F18, 7740) = 1;
	} else {
		result = 16 * dword_5d4594_2489432;
		v5 = dword_5d4594_2489432 + 1;
		*getMemU32Ptr(0x973F18, 7752 + result) = a1;
		*getMemU32Ptr(0x973F18, 7756 + result) = a2;
		*getMemU32Ptr(0x973F18, 7760 + result) = a3;
		*getMemU32Ptr(0x973F18, 7764 + result) = a4;
		dword_5d4594_2489432 = v5;
	}
}

//----- (00543770) --------------------------------------------------------
int nox_xxx_unused_543770(uint32_t* a1, uint32_t* a2, uint32_t* a3, uint32_t* a4) {
	int v4; // eax

	if (*(int*)&dword_5d4594_2489432 <= 0) {
		return 0;
	}
	v4 = dword_5d4594_2489432 - 1;
	dword_5d4594_2489432 = v4;
	*a1 = *getMemU32Ptr(0x973F18, 7752 + 16 * v4);
	*a2 = *getMemU32Ptr(0x973F18, 7756 + 16 * dword_5d4594_2489432);
	*a3 = *getMemU32Ptr(0x973F18, 7760 + 16 * dword_5d4594_2489432);
	*a4 = *getMemU32Ptr(0x973F18, 7764 + 16 * dword_5d4594_2489432);
	return 1;
}

//----- (005437E0) --------------------------------------------------------
int sub_5437E0(int* a1, int a2, int a3) {
	double v3;          // st7
	double v4;          // st6
	int v5;             // ebx
	double v6;          // st6
	int v7;             // edi
	int v8;             // esi
	int v9;             // edx
	int v10;            // ecx
	int v11;            // esi
	int v12;            // edx
	int v13;            // ebx
	int v14;            // ecx
	int v15;            // edx
	int v16;            // ebx
	unsigned char* v17; // edi
	int v18;            // edx
	int v19;            // eax
	int* v20;           // ecx
	int v21;            // edi
	int v23;            // [esp+Ch] [ebp-8h]
	float v24;          // [esp+10h] [ebp-4h]

	v3 = (double)*a1 + 11.5;
	v4 = (double)a1[1];
	v5 = (long long)(v3 * 0.021739131);
	v23 = (long long)(v3 * 0.021739131);
	v6 = v4 + 11.5;
	v24 = v6;
	v7 = (long long)(v6 * 0.021739131);
	a1 = (int*)(long long)(v6 * 0.021739131);
	v8 = (int)(long long)v3 % 46;
	*getMemU32Ptr(0x973F18, 22200) = 0;
	v9 = (long long)v24 % 46;
	dword_5d4594_2487248 = 0;
	if (v5 <= 0 || v5 >= 127 || v7 <= 0 || v7 >= 127) {
		v11 = a3;
	} else if (v8 <= v9) {
		if (a3 - v8 <= v9) {
			v15 = ptr_5D4594_2650668[v5];
			v11 = *(uint32_t*)(v15 + 44 * v7 + 24);
			sub_51DD50(v5, v7, 2, *(uint32_t*)(v15 + 44 * v7 + 24));
		} else {
			v13 = v5 - 1;
			v14 = ptr_5D4594_2650668[v13];
			v11 = *(uint32_t*)(v14 + 44 * v7 + 4);
			sub_51DD50(v13, v7, 1, *(uint32_t*)(v14 + 44 * v7 + 4));
		}
	} else if (a3 - v8 <= v9) {
		v12 = ptr_5D4594_2650668[v5];
		v11 = *(uint32_t*)(v12 + 44 * v7 + 4);
		sub_51DD50(v5, v7, 1, *(uint32_t*)(v12 + 44 * v7 + 4));
	} else {
		v10 = ptr_5D4594_2650668[v5];
		v11 = *(uint32_t*)(v10 + 44 * v7 - 20);
		sub_51DD50(v5, v7 - 1, 2, *(uint32_t*)(v10 + 44 * v7 - 20));
	}
	v16 = 0;
	if (dword_5d4594_2487248 > 0) {
		v17 = getMemAt(0x973F18, 16204);
		do {
			v18 = *((uint32_t*)v17 + 1);
			v19 = *((uint32_t*)v17 - 1);
			v20 = *(int**)v17;
			v23 = *((uint32_t*)v17 - 1);
			a1 = v20;
			a3 = v18;
			if (v18 & 2) {
				sub_51DD50(v19, (int)v20, 1, v11);
				sub_51DD50(v23, (int)a1 + 1, 1, v11);
				sub_51DD50(v23 - 1, (int)a1, 1, v11);
				sub_51DD50(v23 - 1, (int)a1 + 1, 1, v11);
			} else if (v18 & 1) {
				sub_51DD50(v19 + 1, (int)v20, 2, v11);
				sub_51DD50(v23 + 1, (int)a1 - 1, 2, v11);
				sub_51DD50(v23, (int)a1, 2, v11);
				sub_51DD50(v23, (int)a1 - 1, 2, v11);
			}
			++v16;
			v17 += 12;
		} while (v16 < *(int*)&dword_5d4594_2487248);
	}
	if (sub_51DE30(&v23, &a1, &a3)) {
		v21 = a2;
		do {
			if (a3 & 2) {
				sub_543BC0(v23, (int)a1, 1, v11, v21, 1);
				sub_543BC0(v23, (int)a1 + 1, 1, v11, v21, 4);
				sub_543BC0(v23 - 1, (int)a1, 1, v11, v21, 3);
				sub_543BC0(v23 - 1, (int)a1 + 1, 1, v11, v21, 6);
				sub_543BC0(v23, (int)a1 - 1, 2, v11, v21, 0);
				sub_543BC0(v23 + 1, (int)a1, 2, v11, v21, 2);
				sub_543BC0(v23 - 1, (int)a1, 2, v11, v21, 5);
				sub_543BC0(v23, (int)a1 + 1, 2, v11, v21, 7);
			} else if (a3 & 1) {
				sub_543BC0(v23 + 1, (int)a1, 2, v11, v21, 4);
				sub_543BC0(v23 + 1, (int)a1 - 1, 2, v11, v21, 1);
				sub_543BC0(v23, (int)a1, 2, v11, v21, 6);
				sub_543BC0(v23, (int)a1 - 1, 2, v11, v21, 3);
				sub_543BC0(v23, (int)a1 - 1, 1, v11, v21, 0);
				sub_543BC0(v23 + 1, (int)a1, 1, v11, v21, 2);
				sub_543BC0(v23 - 1, (int)a1, 1, v11, v21, 5);
				sub_543BC0(v23, (int)a1 + 1, 1, v11, v21, 7);
			}
		} while (sub_51DE30(&v23, &a1, &a3));
	}
	return *getMemU32Ptr(0x973F18, 22200) == 0;
}

//----- (00543BC0) --------------------------------------------------------
void sub_543BC0(int a1, int a2, int a3, int a4, int a5, int a6) {
	int v7; // ebx

	if (a1 > 0 && a1 < 127) {
		if (a2 > 0 && a2 < 127) {
			v7 = a3;
			if ((!(a3 & 1) || a2 != 1) && (!(a3 & 2) || a1 != 1)) {
				if (a3 & 2) {
					if (a4 == *(uint32_t*)((uint32_t)(ptr_5D4594_2650668[a1]) + 44 * a2 + 24)) {
						return;
					}
					v7 = a3;
				}
				if (!(a3 & 1) || a4 != *(uint32_t*)((uint32_t)(ptr_5D4594_2650668[a1]) + 44 * a2 + 4)) {
					if (a5) {
						*(uint32_t*)(a5 + 28) = a6;
						sub_51DA70(a1, a2, a5, v7, 1);
					}
				}
			}
		}
	}
}

//----- (00543C50) --------------------------------------------------------
int nox_xxx_tile_543C50(uint32_t* a1, int a2, int a3, int a4, int a5, int a6) {
	uint32_t* v6;   // edi
	uint32_t* v7;   // esi
	uint32_t** v8;  // eax
	int result;     // eax
	uint32_t** v10; // eax
	int v11;        // ebx
	int v12;        // eax
	uint32_t* v13;  // ebx
	uint32_t** v14; // edi
	uint32_t* j;    // ebp
	uint32_t* v16;  // esi
	int v17;        // eax
	int v18;        // eax
	uint32_t* v19;  // esi
	int v20;        // eax
	int i;          // ecx
	int v22;        // [esp+24h] [ebp+14h]

	if (a2 == 255 || a4 == 255) {
		v19 = a1;
		v20 = a1[4];
		if (v20) {
			for (i = *(uint32_t*)(v20 + 16); i; i = *(uint32_t*)(i + 16)) {
				v19 = (uint32_t*)v20;
				v20 = i;
			}
			nox_xxx_tileFreeTileOne_4221E0(v20);
			v19[4] = 0;
		}
		return 1;
	}
	v6 = a1;
	if (*a1 == 255) {
		return 1;
	}
	v7 = a1;
	if (a6) {
		v10 = (uint32_t**)(a1 + 4);
		v11 = 0;
		if (!a1[4]) {
			goto LABEL_45;
		}
		do {
			v7 = *v10;
			if (**v10 == a2 && v7[1] == a3 && v7[2] == a4 && sub_543E60((int)v7, a5)) {
				v11 = 1;
			}
			v10 = (uint32_t**)(v7 + 4);
		} while (v7[4]);
		if (!v11) {
		LABEL_45:
			v12 = nox_xxx_mapGenEdge_543EB0(a4, a5);
			v7[4] = nox_xxx_tileListAddNewSubtile_422160(a2, a3, a4, v12);
			return 1;
		}
		while (1) {
			v13 = v6;
			v22 = 0;
			if (!v6[4]) {
				break;
			}
			do {
				v13 = (uint32_t*)v13[4];
				if (*v13 == a2 && v13[1] == a3 && v13[2] == a4) {
					v14 = (uint32_t**)(v13 + 4);
					for (j = v13; j[4]; v14 = (uint32_t**)(j + 4)) {
						v16 = *v14;
						if (**v14 == a2 && v16[1] == a3 && (v17 = v16[2], v17 == a4) &&
							(v18 = sub_411490(v17, v16[3]), sub_543E60((int)v13, v18))) {
							v22 = 1;
							*v14 = (uint32_t*)v16[4];
							nox_xxx_tileFreeTileOne_4221E0((int)v16);
						} else {
							j = v16;
						}
					}
					v6 = a1;
				}
			} while (v13[4]);
			if (!v22) {
				return 1;
			}
		}
		return 1;
	}
	v8 = (uint32_t**)(a1 + 4);
	if (a1[4]) {
		while (1) {
			v7 = *v8;
			if (**v8 == a2 && v7[1] == a3 && v7[2] == a4 && v7[3] == a5) {
				break;
			}
			v8 = (uint32_t**)(v7 + 4);
			if (!v7[4]) {
				goto LABEL_11;
			}
		}
		result = 0;
	} else {
	LABEL_11:
		v7[4] = nox_xxx_tileListAddNewSubtile_422160(a2, a3, a4, a5);
		result = 1;
	}
	return result;
}

//----- (00543E60) --------------------------------------------------------
int sub_543E60(int a1, int a2) {
	int v2; // ecx
	int v4; // eax

	v2 = a2 + 12 * sub_411490(*(uint32_t*)(a1 + 8), *(uint32_t*)(a1 + 12));
	if (*getMemU32Ptr(0x587000, 282736 + 4 * v2) == 255) {
		return 0;
	}
	v4 = nox_xxx_mapGenEdge_543EB0(*(uint32_t*)(a1 + 8), *getMemU32Ptr(0x587000, 282736 + 4 * v2));
	if (v4 != *(uint32_t*)(a1 + 12)) {
		*(uint32_t*)(a1 + 12) = v4;
	}
	return 1;
}

//----- (00543EB0) --------------------------------------------------------
int nox_xxx_mapGenEdge_543EB0(int a1, int a2) {
	int v2;     // esi
	int v3;     // edi
	int result; // eax

	v2 = getMemByte(0x85B3FC, 28696 + 60 * a1);
	v3 = getMemByte(0x85B3FC, 28697 + 60 * a1);
	if (v2 == 3 && v3 == getMemByte(0x85B3FC, 28696 + 60 * a1)) {
		return a2;
	}
	result = a2;
	if (a2) {
		switch (a2) {
		case 1:
			result = nox_common_randomInt_415FA0(1, v2 - 2);
			break;
		case 2:
			result = v2 - 1;
			break;
		case 3:
			result = v2 + 2 * nox_common_randomInt_415FA0(0, v3 - 3);
			break;
		case 4:
			result = v2 + 2 * nox_common_randomInt_415FA0(0, v3 - 3) + 1;
			break;
		case 5:
			result = v2 + 2 * v3 - 4;
			break;
		case 6:
			result = nox_common_randomInt_415FA0(1, v2 - 2) + v2 + 2 * v3 - 4;
			break;
		case 7:
			result = 2 * (v2 + v3) - 5;
			break;
		default:
			result = a2 + 2 * (v2 + v3) - 12;
			break;
		}
	}
	return result;
}

//----- (00543FB0) --------------------------------------------------------
int sub_543FB0(const char* a1) {
	int v1;        // ebp
	const char* i; // edi

	if (!a1) {
		return -1;
	}
	v1 = 0;
	if (*(int*)&dword_5d4594_251572 <= 0) {
		return -1;
	}
	for (i = (const char*)getMemAt(0x85B3FC, 28644); strcmp(i, a1); i += 60) {
		if (++v1 >= *(int*)&dword_5d4594_251572) {
			return -1;
		}
	}
	return v1;
}

//----- (00544020) --------------------------------------------------------
int sub_544020(char* a1) {
	int v1;     // eax
	int result; // eax

	dword_5d4594_2489436 = 0;
	if (_strcmpi("NONE", a1)) {
		v1 = sub_543FB0(a1);
		result = nox_xxx_tileCheckByte3_544070(v1);
	} else {
		dword_5d4594_3835356 = 255;
		result = 1;
	}
	return result;
}

//----- (00544070) --------------------------------------------------------
int nox_xxx_tileCheckByte3_544070(int a1) {
	if (a1 < 0 || a1 >= *(int*)&dword_5d4594_251572) {
		return 0;
	}
	dword_5d4594_3835356 = a1;
	dword_5d4594_2489436 = 1;
	return 1;
}

//----- (005440A0) --------------------------------------------------------
int nox_xxx_tileCheckByte4_5440A0(int a1) {
	if (!dword_5d4594_2489436) {
		return 1;
	}
	if (*(int*)&dword_5d4594_3835356 == -1 || a1 < 0 || a1 >= *getMemU16Ptr(0x85B3FC, 28688 + 60 * a1)) {
		return 0;
	}
	dword_5d4594_3835360 = a1;
	return 1;
}

//----- (005440F0) --------------------------------------------------------
int sub_5440F0(int a1, signed int a2) {
	int v2;        // ebp
	int v3;        // ebx
	int v4;        // edi
	signed int v5; // eax
	int v6;        // eax
	int result;    // eax

	if (a1 < 0 || a1 >= 12 || *(int*)&dword_5d4594_3835356 == -1) {
		return 0;
	}
	v2 = *getMemU32Ptr(0x587000, 283312 + 4 * a1);
	v3 = getMemByte(0x85B3FC, 28697 + 60 * dword_5d4594_3835356);
	v4 = getMemByte(0x85B3FC, 28696 + 60 * dword_5d4594_3835356);
	if (v4 != 3 || v3 != getMemByte(0x85B3FC, 28696 + 60 * dword_5d4594_3835356)) {
		switch (a1) {
		case 0:
		case 3:
		case 4:
			v2 = v4 + v2 - 3;
			break;
		case 5:
		case 8:
		case 9:
		case 10:
		case 11:
			v2 = v2 + 2 * (v3 + v4 - 4) - 4;
			break;
		case 6:
		case 7:
			v2 = v4 + 2 * v3 - 6 + v2 - 3;
			break;
		default:
			break;
		}
	}
	v5 = a2;
	if (a2 == -1) {
		v6 = sub_544240(*(int*)&dword_5d4594_3835356);
		if (a1 && a1 != 2 && a1 != 4 && a1 != 6) {
			return nox_xxx_tileCheckByte4_5440A0(v2);
		}
		v5 = nox_xxx_mapGenRandFunc_526AC0(0, v6 - 1);
	}
	if (!v5) {
		return nox_xxx_tileCheckByte4_5440A0(v2);
	}
	if (a1 != 6 && a1 != 2) {
		if ((!a1 || a1 == 4) && v5 <= v3 - 3) {
			goto LABEL_24;
		}
		return 0;
	}
	if (v5 > v4 - 3) {
		return 0;
	}
LABEL_24:
	switch (a1) {
	case 0:
	case 4:
		v2 += 2 * v5;
		return nox_xxx_tileCheckByte4_5440A0(v2);
	case 2:
	case 6:
		result = nox_xxx_tileCheckByte4_5440A0(v5 + v2);
		break;
	default:
		return nox_xxx_tileCheckByte4_5440A0(v2);
	}
	return result;
}

//----- (00544240) --------------------------------------------------------
int sub_544240(int a1) {
	int result; // eax

	if (a1 < 0 || a1 >= *(int*)&dword_5d4594_251572) {
		result = 0;
	} else {
		result = getMemByte(0x85B3FC, 28696 + 60 * a1) - 2;
	}
	return result;
}

//----- (00544270) --------------------------------------------------------
int sub_544270(const char* a1) {
	int v1;        // ebp
	const char* i; // edi

	v1 = 0;
	if (*(int*)&dword_5d4594_251572 <= 0) {
		return -1;
	}
	for (i = (const char*)getMemAt(0x85B3FC, 28644); strcmp(i, a1); i += 60) {
		if (++v1 >= *(int*)&dword_5d4594_251572) {
			return -1;
		}
	}
	return v1;
}

//----- (005442D0) --------------------------------------------------------
int sub_5442D0(float* a1) {
	int result; // eax
	float2 a2;  // [esp+0h] [ebp-8h]

	if (!dword_5d4594_2489436) {
		return 1;
	}
	result = nox_xxx_mapGenFixCoords_4D3D90((float2*)a1, &a2);
	if (result) {
		result = nox_xxx_tileSubtile_544310(&a2);
	}
	return result;
}

//----- (00544310) --------------------------------------------------------
int nox_xxx_tileSubtile_544310(float2* a1) {
	double v1;  // st7
	double v2;  // st6
	int v3;     // esi
	int v4;     // edi
	int v5;     // ebp
	int v6;     // edx
	int result; // eax
	int v8[8];  // [esp+10h] [ebp-20h]
	float v9;   // [esp+34h] [ebp+4h]

	dword_5d4594_3835352 = 1;
	v1 = a1->field_0 + 11.5;
	v8[1] = dword_5d4594_3835348;
	v8[0] = *getMemU32Ptr(0x973F18, 35912);
	v8[2] = 0;
	LOBYTE(v8[5]) = 0;
	v8[3] = -1;
	v8[4] = -1;
	v8[6] = dword_5d4594_3835356;
	v8[7] = dword_5d4594_3835360;
	v2 = a1->field_4 + 11.5;
	v3 = (long long)(v1 * 0.021739131);
	v9 = v2;
	v4 = (long long)(v2 * 0.021739131);
	v5 = (int)(long long)v1 % 46;
	v6 = (long long)v9 % 46;
	if (*getMemU32Ptr(0x973F18, 35912) == 255) {
		result = sub_51D9C0(v3, v4, v5, v6, 0);
	} else {
		result = sub_51D9C0(v3, v4, v5, v6, (int)v8);
	}
	dword_5d4594_3835352 = 0;
	return result;
}

//----- (005443F0) --------------------------------------------------------
char nox_xxx_mobActionMoveTo_5443F0(int a1) {
	int v1;    // esi
	int v2;    // edi
	int v4;    // ebx
	double v5; // st7
	double v6; // st7
	double v7; // st6
	double v8; // st5
	double v9; // st6
	char v10;  // al
	int v11;   // ebp
	int* v12;  // ebx
	int* v13;  // edi
	float v14; // [esp+Ch] [ebp+4h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 748);
	if (!nox_xxx_monsterIsMoveing_534320(a1)) {
		return nox_xxx_monsterPopAction_50A160(a1);
	}
	v4 = v2 + 24 * (*(char*)(v2 + 544) + 23);
	if (sub_50A040(a1) == 3) {
		v5 = *(float*)(v2 + 1316) * 3.0;
		v14 = v5;
		v6 = v5 + 30.0;
		v7 = *(float*)(v4 + 4) - *(float*)(v1 + 56);
		v8 = *(float*)(v4 + 8) - *(float*)(v1 + 60);
		v9 = v8 * v8 + v7 * v7;
		if (v9 >= v14 * v14) {
			if (v9 > v6 * v6) {
				sub_534750(v1);
			}
		} else {
			sub_534780(v1);
		}
	}
	if (nox_xxx_creatureSetMovePath_50D5A0(v1) == 1) {
		v10 = *(uint8_t*)(v2 + 284);
		v11 = v10 == 2 || v10 == 1 && nox_frame_xxx_2598000 - *(uint32_t*)(v2 + 540) < (unsigned int)(5 * nox_gameFPS);
		if (v10 == 1) {
			*(uint32_t*)(v2 + 540) = nox_frame_xxx_2598000;
		}
		if (!v10 && !sub_547F10() && !*(uint32_t*)(v4 + 12)) {
			nox_xxx_mobCalcDir_533CC0(v1, (float*)(v4 + 4));
			nox_xxx_monsterPopAction_50A160(v1);
		}
		if (v11) {
			v12 = nox_xxx_monsterPushAction_50A260(v1, 41);
			if (v12) {
				v12[1] = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(2 * nox_gameFPS, 4 * nox_gameFPS);
			}
			nox_xxx_monsterPushAction_50A260(v1, 29);
			*(uint32_t*)(v2 + 1440) |= 0x200000u;
		}
		if (*(uint8_t*)(v2 + 284)) {
			v13 = nox_xxx_monsterPushAction_50A260(v1, 1);
			if (v13) {
				v13[1] = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(nox_gameFPS >> 1, (int)nox_gameFPS);
			}
		}
	}
	return nox_xxx_monsterMoveAudio_534030(v1);
}

//----- (005445C0) --------------------------------------------------------
char nox_xxx_mobActionMoveToFar_5445C0(int* a1) {
	int v1;  // edi
	int v2;  // eax
	int* v3; // eax
	int v4;  // ecx

	v1 = a1[187];
	if (!sub_5343C0((int)a1) && !nox_xxx_monsterCanAttackAtWill_534390((int)a1) || (v2 = sub_545E60(a1)) == 0) {
		if (nox_xxx_monsterCanAttackAtWill_534390((int)a1)) {
			if (*(uint32_t*)(v1 + 1196)) {
				v3 = nox_xxx_monsterPushAction_50A260((int)a1, 15);
				if (v3) {
					v4 = *(uint32_t*)(v1 + 1196);
					v3[1] = *(uint32_t*)(v4 + 56);
					v3[2] = *(uint32_t*)(v4 + 60);
					v3[3] = nox_frame_xxx_2598000;
				}
			}
		}
		LOBYTE(v2) = nox_xxx_mobActionMoveTo_5443F0((int)a1);
	}
	return v2;
}

//----- (00544640) --------------------------------------------------------
void nox_xxx_mobActionDodge_544640(int a1) {
	float* v1;      // esi
	int v2;         // edi
	double v3;      // st7
	double v4;      // st6
	long double v5; // st6
	double v6;      // st6
	float v7;       // [esp+Ch] [ebp-4h]
	float v8;       // [esp+14h] [ebp+4h]

	v1 = (float*)a1;
	v2 = *(uint32_t*)(a1 + 748);
	if (nox_xxx_monsterIsMoveing_534320(a1)) {
		if (!nox_xxx_testUnitBuffs_4FF350(a1, 3) && !nox_xxx_testUnitBuffs_4FF350(a1, 5) &&
			!nox_xxx_testUnitBuffs_4FF350(a1, 28)) {
			v3 = *(float*)(v2 + 24 * (*(char*)(v2 + 544) + 23) + 4) - *(float*)(a1 + 56);
			v4 = *(float*)(v2 + 24 * (*(char*)(v2 + 544) + 23) + 8) - *(float*)(a1 + 60);
			v7 = v4;
			v5 = sqrt(v4 * v7 + v3 * v3) + 0.000099999997;
			v8 = v5;
			if (v5 >= 8.0) {
				v6 = *(float*)(*(uint32_t*)(v2 + 484) + 96) * v1[136];
				v1[136] = v6;
				v1[22] = v6 * v3 / v8;
				v1[23] = v7 * v1[136] / v8;
			} else {
				nox_xxx_monsterPopAction_50A160((int)v1);
			}
		}
	} else {
		nox_xxx_monsterPopAction_50A160(a1);
	}
}

//----- (00544740) --------------------------------------------------------
int sub_544740(int a1) { return sub_534750(a1); }

//----- (00544750) --------------------------------------------------------
int sub_544750(int a1) { return sub_534780(a1); }

//----- (00544760) --------------------------------------------------------
char nox_xxx_mobActionFlee_544760(int a1) {
	int v1;    // esi
	int v2;    // eax
	int v3;    // ebx
	int v4;    // eax
	int v5;    // eax
	double v6; // st7
	double v7; // st6
	int v8;    // eax
	int v9;    // eax
	int v10;   // ebx
	int v11;   // eax

	v1 = *(uint32_t*)(a1 + 748);
	if (nox_xxx_monsterIsMoveing_534320(a1)) {
		v3 = v1 + 24 * (*(char*)(v1 + 544) + 23);
		v4 = *(uint32_t*)(v1 + 1196);
		if (v4) {
			*(uint32_t*)(v3 + 4) = *(uint32_t*)(v4 + 56);
			*(uint32_t*)(v3 + 8) = *(uint32_t*)(v4 + 60);
			v5 = *(uint32_t*)(v1 + 1196);
			v6 = *(float*)(v5 + 56) - *(float*)(a1 + 56);
			v7 = *(float*)(v5 + 60) - *(float*)(a1 + 60);
			if (*(float*)(v1 + 1356) * *(float*)(v1 + 1356) > v7 * v7 + v6 * v6 &&
				(unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(v1 + 280)) > nox_gameFPS >> 1) {
				*(uint32_t*)(v1 + 8) = 0;
			}
			if (nox_xxx_monsterCanCast_534300(a1) && !nox_xxx_testUnitBuffs_4FF350(a1, 29) && !sub_534400(a1) &&
				!sub_534440(a1)) {
				v8 = nox_xxx_checkMobAction_50A0D0(a1, 6) ? nox_xxx_mobCastRelated_541050(a1)
														  : nox_xxx_monsterBuffSelf_540B90(a1);
				if (!v8 && nox_xxx_unitCanInteractWith_5370E0(a1, *(uint32_t*)(v1 + 1196), 0)) {
					nox_xxx_monsterCastOffensive_540F20(a1, *(uint32_t*)(v1 + 1196));
				}
			}
		}
		v9 = nox_frame_xxx_2598000;
		if (*(uint32_t*)(v1 + 8) && nox_frame_xxx_2598000 - *(uint32_t*)(v1 + 280) > (unsigned int)(2 * nox_gameFPS)) {
			*(uint32_t*)(v1 + 8) = 0;
			v9 = nox_frame_xxx_2598000;
		}
		if (*(uint32_t*)(v1 + 8) || (unsigned int)(v9 - *(uint32_t*)(v1 + 280)) <= 0xA ||
			(v10 = v3 + 4, v11 = nox_xxx_generateRetreatPath_50CA00(v1 + 12, 32, a1, (float*)v10),
			 *(uint32_t*)(v1 + 8) = v11, *(uint32_t*)(v1 + 280) = nox_frame_xxx_2598000, *(uint32_t*)(v1 + 268) = 0,
			 v11 > 1)) {
			if (nox_xxx_creatureActuallyMove_50D3B0((float*)a1)) {
				*(uint32_t*)(v1 + 8) = 0;
			}
			LOBYTE(v2) = nox_xxx_monsterMoveAudio_534030(a1);
		} else {
			*(uint32_t*)v10 = *(uint32_t*)(a1 + 56);
			v2 = *(uint32_t*)(a1 + 60);
			*(uint32_t*)(v10 + 4) = v2;
		}
	} else {
		LOBYTE(v2) = nox_xxx_monsterPopAction_50A160(a1);
	}
	return v2;
}

//----- (00544920) --------------------------------------------------------
int nox_xxx_mobActionReturnToHome_544920(int a1) { return sub_534750(a1); }

//----- (00544930) --------------------------------------------------------
int sub_544930(int a1) { return sub_534780(a1); }

//----- (00544940) --------------------------------------------------------
int sub_544940(int a1) { return sub_534780(a1); }

//----- (00544950) --------------------------------------------------------
char sub_544950(int a1) { return nox_xxx_mobActionMoveTo_5443F0(a1); }

//----- (00544960) --------------------------------------------------------
char nox_xxx_mobActionWait_544960(int a1) {
	unsigned int v1; // eax

	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 24 * *(char*)(*(uint32_t*)(a1 + 748) + 544) + 556);
	if (v1 <= nox_frame_xxx_2598000) {
		LOBYTE(v1) = nox_xxx_monsterPopAction_50A160(a1);
	}
	return v1;
}

//----- (00544990) --------------------------------------------------------
char nox_xxx_mobActionWaitRelative_544990(int a1) {
	int v1;      // eax
	int v2;      // esi
	int v3;      // ecx
	char result; // al

	v1 = *(uint32_t*)(a1 + 748);
	v2 = *(uint32_t*)(v1 + 548);
	v3 = *(uint32_t*)(v1 + 24 * *(char*)(v1 + 544) + 556);
	result = (unsigned char)nox_frame_xxx_2598000;
	if (nox_frame_xxx_2598000 > (unsigned int)(v2 + v3)) {
		result = nox_xxx_monsterPopAction_50A160(a1);
	}
	return result;
}

//----- (005449D0) --------------------------------------------------------
int* nox_xxx_mobActionHunt_5449D0(int a1) {
	int* result; // eax

	*(uint32_t*)(*(uint32_t*)(a1 + 748) + 1304) = 1062501089;
	result = nox_xxx_monsterPushAction_50A260(a1, 10);
	if (result) {
		result[1] = 0;
		*((uint8_t*)result + 12) = -128;
	}
	return result;
}

//----- (00544A00) --------------------------------------------------------
int nox_xxx_mobSearchEdible_544A00(nox_object_t* a1, float a2) {
	*getMemU32Ptr(0x5D4594, 2489452) = 0;
	*getMemU32Ptr(0x5D4594, 2489444) = 1259902592;
	nox_xxx_unitsGetInCircle_517F90((float2*)((int)a1 + 56), a2, nox_xxx_mobSearchEdible2_544A40, a1);
	return *getMemU32Ptr(0x5D4594, 2489452);
}

//----- (00544A40) --------------------------------------------------------
void nox_xxx_mobSearchEdible2_544A40(int a1, int a2) {
	int v2;    // eax
	int v3;    // eax
	double v4; // st7
	double v5; // st6
	double v6; // st5

	if (*(uint8_t*)(a1 + 8) & 0x10) {
		v2 = *(uint32_t*)(a1 + 12);
		if (!(v2 & 4) && ((v2 & 0x80u) == 0 || nox_xxx_isNotPoisoned_5347F0(a2))) {
			v3 = *(uint32_t*)(a1 + 12);
			if (!(v3 & 8) || v3 & 0x10 && nox_common_gameFlags_check_40A5C0(0x2000) && *(uint8_t*)(a2 + 12) & 0x10) {
				if (nox_xxx_unitCanInteractWith_5370E0(a2, a1, 0)) {
					v4 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
					v5 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
					v6 = v5 * v5 + v4 * v4;
					if (v6 < *getMemFloatPtr(0x5D4594, 2489444)) {
						*getMemFloatPtr(0x5D4594, 2489444) = v6;
						*getMemU32Ptr(0x5D4594, 2489452) = a1;
					}
				}
			}
		}
	}
}

//----- (00544AE0) --------------------------------------------------------
int sub_544AE0(int a1, float a2) {
	*getMemU32Ptr(0x5D4594, 2489440) = 0;
	*getMemU32Ptr(0x5D4594, 2489448) = 1259902592;
	nox_xxx_unitsGetInCircle_517F90((float2*)(a1 + 56), a2, sub_544B20, a1);
	return *getMemU32Ptr(0x5D4594, 2489440);
}

//----- (00544B20) --------------------------------------------------------
void sub_544B20(int a1, int a2) {
	double v2; // st7
	double v3; // st6
	double v4; // st5

	if (*(uint32_t*)(a1 + 8) & 0x1000000 && nox_xxx_playerClassCanUseItem_57B3D0(a1, 0) &&
		nox_xxx_unitCanInteractWith_5370E0(a2, a1, 0)) {
		v2 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
		v3 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
		v4 = v3 * v3 + v2 * v2;
		if (v4 < *getMemFloatPtr(0x5D4594, 2489448)) {
			*getMemFloatPtr(0x5D4594, 2489448) = v4;
			*getMemU32Ptr(0x5D4594, 2489440) = a1;
		}
	}
}

//----- (00544B90) --------------------------------------------------------
char nox_xxx_mobActionPickupObject_544B90(int a1) {
	int v1;    // ecx
	int v2;    // edi
	int v3;    // ecx
	double v4; // st7
	double v5; // st6
	int v6;    // edi

	v1 = *(uint32_t*)(a1 + 748);
	v2 = v1 + 24 * (*(char*)(v1 + 544) + 23);
	v3 = *(uint32_t*)(v1 + 24 * (*(char*)(v1 + 544) + 23) + 4);
	if (v3) {
		v4 = *(float*)(v3 + 56) - *(float*)(a1 + 56);
		v5 = *(float*)(v3 + 60) - *(float*)(a1 + 60);
		if (v5 * v5 + v4 * v4 < 5625.0) {
			if (nox_xxx_unitCanInteractWith_5370E0(a1, v3, 0)) {
				nox_xxx_inventoryServPlace_4F36F0(a1, *(uint32_t*)(v2 + 4), 1, 1);
				v6 = *(uint32_t*)(v2 + 4);
				if (*(uint8_t*)(v6 + 12) & 0x10) {
					nox_xxx_useByNetCode_53F8E0(a1, v6);
				}
			}
		}
	}
	return nox_xxx_monsterPopAction_50A160(a1);
}

//----- (00544C40) --------------------------------------------------------
int nox_xxx_mobGenericDeath_544C40(int a1) {
	int v1;              // edi
	int v2;              // eax
	int result = 0;      // eax
	int (*result2)(int); // eax

	v1 = *(uint32_t*)(a1 + 748);
	v2 = nox_xxx_monsterGetSoundSet_424300(a1);
	if (v2) {
		nox_xxx_aud_501960(*(uint32_t*)(v2 + 60), a1, 0, 0);
	}
	nox_xxx_scriptCallByEventBlock_502490((int*)(v1 + 1264), 0, a1, 7);
	result2 = *(int (**)(int))(*(uint32_t*)(v1 + 484) + 228);
	if (result2) {
		result = result2(a1);
	}
	return result;
}

//----- (00544CA0) --------------------------------------------------------
void nox_xxx_zombieBurnDeleteCheck_544CA0(uint32_t* a1) {
	int v1; // edi

	v1 = a1[187];
	if (nox_xxx_unitIsZombie_534A40((int)a1)) {
		if (*(uint32_t*)(v1 + 1440) & 0x80000) {
			nox_xxx_zombieBurnDelete_544CE0(a1);
		}
	}
}

//----- (00544CE0) --------------------------------------------------------
void nox_xxx_zombieBurnDelete_544CE0(uint32_t* a1) {
	int v1; // eax
	int v2; // ecx
	int v3; // edi

	v1 = a1[127];
	if (v1 && *(uint8_t*)(v1 + 8) & 4) {
		v2 = a1[3];
		v3 = *(uint32_t*)(v1 + 748);
		LOBYTE(v2) = v2 & 0x7F;
		a1[3] = v2;
		nox_xxx_netFxShield_0_4D9200(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), (int)a1);
		nox_xxx_netUnmarkMinimapObj_417300(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), (int)a1, 1);
	}
	nox_xxx_soloMonsterKillReward_4EE500_obj_health((int)a1);
	nox_xxx_sMakeScorch_537AF0(a1 + 14, 1);
	nox_xxx_delayedDeleteObject_4E5CC0((int)a1);
}

//----- (00544D60) --------------------------------------------------------
char sub_544D60(int a1) {
	char result; // al

	result = a1;
	if (*(uint8_t*)(*(uint32_t*)(a1 + 748) + 483)) {
		result = nox_xxx_monsterPopAction_50A160(a1);
	}
	return result;
}

//----- (00544D80) --------------------------------------------------------
char nox_xxx_mobActionDead1_544D80(uint32_t* a1) {
	int v1;                // ebx
	void (*v2)(uint32_t*); // eax
	int v3;                // edi
	int v4;                // eax
	int v5;                // eax
	bool v6;               // zf
	float v8;              // [esp+0h] [ebp-10h]
	float v9;              // [esp+0h] [ebp-10h]

	v1 = a1[187];
	if (a1[131] == 14 && a1[3] & 0x10000) {
		nox_xxx_createReleasedSoul_544E60((int)a1);
	}
	a1[21] = 0;
	a1[20] = 0;
	a1[23] = 0;
	a1[22] = 0;
	a1[25] = 0;
	a1[24] = 0;
	v2 = *(void (**)(uint32_t*))(*(uint32_t*)(v1 + 484) + 232);
	if (v2) {
		v2(a1);
	}
	if (nox_xxx_unitIsZombie_534A40((int)a1)) {
		v8 = nox_xxx_gamedataGetFloatTable_419D70("ZombieDeadDuration", 0);
		v3 = nox_float2int(v8);
		v9 = nox_xxx_gamedataGetFloatTable_419D70("ZombieDeadDuration", 1);
		v4 = nox_float2int(v9);
		*(uint32_t*)(v1 + 492) = nox_common_randomInt_415FA0(v3, v4);
		v5 = a1[4];
		LOBYTE(v5) = v5 | 0x10;
		a1[4] = v5;
	} else {
		v6 = !nox_xxx_unitIsZombie_534A40((int)a1);
		v5 = a1[4];
		if (v6) {
			LOBYTE(v5) = v5 | 0x18;
		} else {
			LOBYTE(v5) = v5 | 0x10;
		}
		a1[4] = v5;
	}
	return v5;
}

//----- (00544E60) --------------------------------------------------------
void nox_xxx_createReleasedSoul_544E60(int a1) {
	int v1;       // eax
	uint32_t* v2; // eax
	uint32_t* v3; // esi
	short v4;     // di

	v1 = *getMemU32Ptr(0x5D4594, 2489456);
	if (!*getMemU32Ptr(0x5D4594, 2489456)) {
		v1 = nox_xxx_getNameId_4E3AA0("ReleasedSoul");
		*getMemU32Ptr(0x5D4594, 2489456) = v1;
	}
	v2 = nox_xxx_newObjectWithTypeInd_4E3450(v1);
	v3 = v2;
	if (v2) {
		nox_xxx_createAt_4DAA50((int)v2, 0, *(float*)(a1 + 56), *(float*)(a1 + 60));
		v4 = *(uint16_t*)(a1 + 124);
		*((uint16_t*)v3 + 63) = v4;
		*((uint16_t*)v3 + 62) = v4;
	}
}

//----- (00544EC0) --------------------------------------------------------
void nox_xxx_mobActionDead2_544EC0(int a1) {
	uint32_t* v1; // edi
	int v2;       // eax

	v1 = *(uint32_t**)(a1 + 748);
	if (nox_xxx_unitIsZombie_534A40(a1)) {
		v2 = v1[360];
		if (v2 & 0x80000) {
			nox_xxx_netSparkExplosionFx_5231B0((float*)(a1 + 56), 100);
			nox_xxx_zombieBurnDelete_544CE0((uint32_t*)a1);
		} else if ((unsigned int)(nox_frame_xxx_2598000 - v1[137]) > v1[123] && !(v2 & 0x100000)) {
			if (v1[299]) {
				nox_xxx_mobRaiseZombie_534AB0(a1);
			}
		}
	} else {
		nox_xxx_unitRemoveFromUpdatable_4DA920((uint32_t*)a1);
		*(uint32_t*)(a1 + 744) = 0;
		sub_544F70(a1);
		if (*(uint8_t*)(v1[121] + 92) & 1) {
			nox_xxx_delayedDeleteObject_4E5CC0(a1);
		}
	}
}

//----- (00544F70) --------------------------------------------------------
int sub_544F70(int a1) {
	int v1;           // ecx
	int result;       // eax
	int v3;           // edx
	uint32_t* v4;     // edx
	unsigned char v5; // dl
	int v6;           // ecx
	uint32_t* v7;     // esi

	v1 = 0;
	result = *(uint32_t*)(a1 + 748);
	v3 = *(uint32_t*)(result + 296);
	*(uint8_t*)(result + 2094) = 0;
	if (v3 > 0) {
		v4 = (uint32_t*)(result + 300);
		do {
			*v4 = 0;
			++v1;
			++v4;
		} while (v1 < *(int*)(result + 296));
	}
	v5 = *(uint8_t*)(result + 1129);
	v6 = 0;
	*(uint32_t*)(result + 296) = 0;
	*(uint32_t*)(result + 364) = 0;
	if (v5 > 0u) {
		v7 = (uint32_t*)(result + 1132);
		do {
			*v7 = 0;
			++v6;
			++v7;
		} while (v6 < *(unsigned char*)(result + 1129));
	}
	*(uint8_t*)(result + 1129) = 0;
	*(uint32_t*)(result + 1196) = 0;
	return result;
}

//----- (00544FF0) --------------------------------------------------------
unsigned char* nox_xxx_mobActionReportComplete_544FF0(int a1) {
	int v1; // edi

	v1 = *(uint32_t*)(a1 + 748);
	nox_xxx_monsterPopAction_50A160(a1);
	return nox_xxx_scriptCallByEventBlock_502490((int*)(v1 + 1288), 0, a1, 6);
}
