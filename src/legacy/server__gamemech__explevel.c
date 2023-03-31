#include "server__gamemech__explevel.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "common__gamemech__pausefx.h"
#include "common__strman.h"
extern uint32_t dword_5d4594_2516328;
extern uint32_t dword_5d4594_2516348;

//----- (0056F980) --------------------------------------------------------
uint32_t* sub_56F980(int a1, unsigned char a2) {
	uint32_t* result; // eax
	int v3;           // ecx

	result = (uint32_t*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = dword_5d4594_2516348 ^ (a2 + (dword_5d4594_2516348 ^ result[1]));
			result[1] = v3;
			dword_5d4594_2516328 ^= v3;
			result = (uint32_t*)nox_xxx_protectData_56F5C0();
		}
	}
	return result;
}

//----- (004EF2E0) --------------------------------------------------------
void sub_4EF2E0_exp_level(int a1) {
	int v1;      // esi
	wchar2_t* v2; // eax

	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	if ((nox_xxx_gameGet_4DB1B0() != 1 || !sub_4DB1C0()) &&
		nox_xxx_gamedataGetFloatTable_419D70("XPTable", *(char*)(v1 + 3684) + 1) <= *(float*)(a1 + 28)) {
		++*(uint8_t*)(v1 + 3684);
		sub_56F980(*(uint32_t*)(v1 + 4644), 1u);
		nox_xxx_plrReadVals_4EEDC0(a1, 1);
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			sub_57AF30(a1, 0);
		} else {
			nox_xxx_aud_501960(902, a1, 2, *(uint32_t*)(a1 + 36));
			v2 = nox_strman_loadString_40F1D0("LevelUP", 0, "C:\\NoxPost\\src\\Server\\GameMech\\explevel.c", 253);
			nox_xxx_netSendLineMessage_4D9EB0(a1, v2);
		}
	}
}

//----- (004EF3A0) --------------------------------------------------------
void nox_xxx_plyrGiveExp_4EF3A0_exp_level(int a1, float a2) {
	int v2;      // ecx
	wchar2_t* v3; // eax

	v2 = *(uint32_t*)(a1 + 748);
	*(float*)(a1 + 28) = a2 + *(float*)(a1 + 28);
	sub_56FA40(*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4604), a2);
	sub_4D81A0(a1);
	v3 = nox_strman_loadString_40F1D0("health.c:gainpoints", 0, "C:\\NoxPost\\src\\Server\\GameMech\\explevel.c", 381);
	nox_xxx_netSendLineMessage_4D9EB0(a1, v3, (unsigned int)(long long)a2);
	sub_4EF2E0_exp_level(a1);
}
