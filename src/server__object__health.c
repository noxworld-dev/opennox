#include "server__gamemech__explevel.h"

#include "GAME1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "common__strman.h"

//----- (004EF270) --------------------------------------------------------
double nox_xxx_unitGiveXP_4EF270(int a1, float a2) {
	int v3;    // ecx
	double v4; // st7
	float v5;  // [esp+Ch] [ebp+8h]

	if (*(float*)(a1 + 28) >= (double)a2) {
		return 0.0;
	}
	v3 = *(uint32_t*)(a1 + 748);
	v4 = (a2 - *(float*)(a1 + 28)) * *getMemFloatPtr(0x587000, 206148) + 1.0;
	v5 = v4;
	*(float*)(a1 + 28) = v4 + *(float*)(a1 + 28);
	sub_56FA40(*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4604), v5);
	sub_4D81A0(a1);
	sub_4EF2E0_exp_level(a1);
	return v5;
}

//----- (004EE500) --------------------------------------------------------
void nox_xxx_soloMonsterKillReward_4EE500_obj_health(int a1) {
	int v1;      // ebx
	int v2;      // esi
	int v3;      // ebp
	int v4;      // edi
	int v5;      // eax
	double v6;   // st7
	wchar_t* v7; // eax

	v1 = a1;
	if (!a1) {
		return;
	}
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		return;
	}
	v2 = *(uint32_t*)(a1 + 520);
	if (!v2) {
		return;
	}
	v3 = 1;
	v4 = nox_xxx_findParentChainPlayer_4EC580(*(uint32_t*)(a1 + 520));
	if (!(*(uint8_t*)(v4 + 8) & 4)) {
		return;
	}
	v5 = 0;
	if (v2 != v4) {
		while (v2 != v4) {
			if (v5) {
				break;
			}
			if (*(uint8_t*)(v2 + 8) & 2) {
				v3 = nox_xxx_creatureIsMonitored_500CC0(v4, v2);
				v5 = 1;
			}
			v2 = *(uint32_t*)(v2 + 508);
		}
		if (!v3) {
			return;
		}
		v1 = a1;
	}
	v6 = nox_xxx_unitGiveXP_4EF270(v4, *(float*)(v1 + 28));
	if (v6 > 0.0) {
		v7 = nox_strman_loadString_40F1D0("gainpoints", 0, "C:\\NoxPost\\src\\Server\\Object\\health.c", 172);
		nox_xxx_netSendLineMessage_4D9EB0(v4, v7, (unsigned int)(long long)v6);
	}
	return;
}
