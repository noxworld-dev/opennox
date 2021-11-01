#include "client__gui__guimsg.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "common__strman.h"
#include "operators.h"

//----- (004D8060) --------------------------------------------------------
int nox_xxx_netAbilityReport_4D8060(int a1, int a2, int a3) {
	int result; // eax
	int v4;     // eax

	result = a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		v4 = *(uint32_t*)(a1 + 748);
		LOBYTE(a1) = -51;
		BYTE1(a1) = a2;
		BYTE2(a1) = *(uint8_t*)(*(uint32_t*)(v4 + 276) + 4 * a2 + 3696);
		if (a3) {
			BYTE2(a1) |= 0x80u;
		}
		result = nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064), (int)&a1, 3, 0, 1);
	}
	return result;
}

//----- (004FB960) --------------------------------------------------------
void nox_xxx_abilGetSuccess_4FB960_ability(int a1) {
	wchar_t* v1; // eax

	v1 = nox_strman_loadString_40F1D0(*(char**)getMemAt(0x587000, 217092 + 4 * a1), 0,
									  "C:\\NoxPost\\src\\Server\\Ability\\Ability.c", 75);
	nox_xxx_printCentered_445490(v1);
}

//----- (004FB9C0) --------------------------------------------------------
int nox_xxx_abilityRewardServ_4FB9C0_ability(int a1, int a2, int a3) {
	int v3;       // eax
	int v4;       // ecx
	int v5;       // edx
	uint32_t* v6; // ecx
	uint32_t* v7; // ecx
	int i;        // edi
	int result;   // eax
	wchar_t* v10; // eax

	if (!(*(uint8_t*)(a1 + 8) & 4)) {
		return 0;
	}
	if (a2 <= 0 || a2 >= 6) {
		v10 = nox_strman_loadString_40F1D0("AwardAbilityError", 0, "C:\\NoxPost\\src\\Server\\Ability\\Ability.c", 108);
		nox_xxx_netSendLineMessage_4D9EB0(a1, v10);
		return 0;
	}
	v3 = *(uint32_t*)(a1 + 748);
	v4 = *(uint32_t*)(v3 + 276);
	v5 = *(uint32_t*)(v4 + 4 * a2 + 3696);
	v6 = (uint32_t*)(v4 + 4 * a2 + 3696);
	if (v5) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "use.c:HadAbility", 0);
		result = 0;
	} else {
		*v6 = 5;
		v7 = (uint32_t*)(*(uint32_t*)(v3 + 276) + 4 * a2 + 3696);
		if (*v7 > 5) {
			*v7 = 5;
		}
		nox_xxx_playerAwardSpellProtection_56FCE0(*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4636), a2,
												  *(uint32_t*)(*(uint32_t*)(v3 + 276) + 4 * a2 + 3696));
		nox_xxx_netAbilityReport_4D8060(a1, a2, a3);
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			nox_xxx_netSendRewardNotify_4FAD50(a1, 2, a1, a2);
			if (!sub_419E60(a1)) {
				for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
					if (i != a1) {
						nox_xxx_netSendRewardNotify_4FAD50(i, 2, a1, a2);
					}
				}
			}
		}
		result = 1;
	}
	return result;
}
