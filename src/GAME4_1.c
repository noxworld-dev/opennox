#include <math.h>

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__system__ctrlevnt.h"
#include "common__binfile.h"
#include "common__crypt.h"
#include "common__net_list.h"
#include "common__random.h"
#include "operators.h"
#include "common__system__team.h"
#include "server__gamemech__explevel.h"
#include "server__magic__plyrspel.h"
#include "server__network__mapsend.h"
#include "server__system__trade.h"

#include "client__gui__window.h"
#include "client__video__draw_common.h"
#include "common__magic__speltree.h"
#include "server__script__script.h"

extern uint32_t dword_5d4594_2386172;
extern uint32_t dword_5d4594_3835364;
extern uint32_t dword_5d4594_1599708;
extern uint32_t dword_5d4594_2386168;
extern uint32_t dword_5d4594_2386164;
extern uint32_t dword_5d4594_1599688;
extern uint32_t dword_587000_234176;
extern uint32_t dword_5d4594_2487244;
extern uint32_t dword_5d4594_1599696;
extern uint32_t dword_587000_237036;
extern void* nox_alloc_pendingOwn_2386916;
extern uint32_t dword_5d4594_2386228;
extern void* nox_alloc_spawn_2386216;
extern uint32_t dword_587000_230092;
extern uint32_t dword_5d4594_3835348;
extern void* nox_alloc_tradeSession_2386492;
extern uint32_t dword_5d4594_2386564;
extern uint32_t dword_5d4594_2386920;
extern void* nox_alloc_monsterList_2386220;
extern uint32_t dword_5d4594_2388640;
extern uint32_t dword_5d4594_2386160;
extern uint32_t dword_5d4594_1599712;
extern uint32_t dword_5d4594_2386924;
extern uint32_t dword_5d4594_2386500;
extern uint32_t dword_5d4594_2386576;
extern uint32_t dword_5d4594_2386212;
extern nox_object_t* nox_xxx_host_player_unit_3843628;
extern uint32_t dword_5d4594_2386180;
extern void* nox_alloc_tradeItems_2386496;
extern void* nox_alloc_visitNode_2386184;
extern uint32_t dword_5d4594_2388648;
extern uint32_t dword_5d4594_2386152;
extern uint32_t dword_5d4594_2386224;
extern uint32_t nox_gameDisableMapDraw_5d4594_2650672;
extern uint32_t dword_5d4594_2650652;
extern nox_server_xxx nox_server_xxx_1599716[NOX_SERVER_XXX_SIZE * NOX_SERVER_XXX_SIZE];

uint32_t nox_xxx_wallSounds_2386840 = 0;
void* dword_5d4594_2386176 = 0;

//----- (005098A0) --------------------------------------------------------
int sub_5098A0() {
	int v0;        // ebp
	int v1;        // ebx
	signed int v2; // esi
	char* i;       // eax
	signed int v4; // ecx
	int v5;        // edi
	int v6;        // ebp
	int v7;        // eax
	signed int v8; // eax
	int result;    // eax
	char* v10;     // [esp+10h] [ebp-8h]
	int v11;       // [esp+14h] [ebp-4h]

	v0 = 0;
	v11 = 0;
	v10 = 0;
	v1 = 0;
	v2 = 2147483648;
	for (i = nox_server_teamFirst_418B10(); i; i = nox_server_teamNext_418B60((int)i)) {
		v4 = *((uint32_t*)i + 13);
		if (v4 >= v2) {
			v1 = v4 == v2 && v0;
			v2 = *((uint32_t*)i + 13);
			v10 = i;
			v0 = (int)i;
		}
	}
	v5 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (v5) {
		do {
			v6 = *(uint32_t*)(v5 + 748);
			if (!nox_xxx_servObjectHasTeam_419130(v5 + 48)) {
				v7 = *(uint32_t*)(v6 + 276);
				if (!(*(uint8_t*)(v7 + 3680) & 1)) {
					v8 = *(uint32_t*)(v7 + 2136);
					if (v8 >= v2) {
						v1 = v8 == v2 && v11;
						v2 = v8;
						v11 = v5;
					}
				}
			}
			v5 = nox_xxx_getNextPlayerUnit_4DA7F0(v5);
		} while (v5);
		v0 = (int)v10;
	}
	nox_xxx_setGameFlags_40A4D0(8);
	if (v1) {
		return nox_xxx_netSendDMTeamWinner_4D8BF0(0, 1);
	}
	result = v11;
	if (v11) {
		return nox_xxx_netSendDMWinner_4D8B90(v11, 1);
	}
	if (v0) {
		result = nox_xxx_netSendDMTeamWinner_4D8BF0(v0, 1);
	}
	return result;
}

//----- (005099B0) --------------------------------------------------------
int sub_5099B0() {
	int v0;     // edi
	int v1;     // ebx
	int v2;     // esi
	char* i;    // eax
	int v4;     // ecx
	int result; // eax

	v0 = 0;
	v1 = 0;
	v2 = -1;
	for (i = nox_server_teamFirst_418B10(); i; i = nox_server_teamNext_418B60((int)i)) {
		v4 = *((uint32_t*)i + 13);
		if (v4 >= v2) {
			v1 = v4 == v2 && v0;
			v2 = *((uint32_t*)i + 13);
			v0 = (int)i;
		}
	}
	nox_xxx_setGameFlags_40A4D0(8);
	if (!v0 || v1) {
		if (nox_common_gameFlags_check_40A5C0(64)) {
			result = nox_xxx_netFlagballWinner_4D8C40(0);
		} else {
			result = nox_xxx_netFlagWinner_4D8C40_4D8C80(0, 1);
		}
	} else if (nox_common_gameFlags_check_40A5C0(64)) {
		result = nox_xxx_netFlagballWinner_4D8C40(v0);
	} else {
		result = nox_xxx_netFlagWinner_4D8C40_4D8C80(v0, 1);
	}
	return result;
}

//----- (00509A60) --------------------------------------------------------
void nox_server_checkVictory_509A60() {
	if (nox_common_gameFlags_check_40A5C0(1024)) {
		char* v6 = 0;
		short v7 = nox_common_gameFlags_getVal_40A5B0();
		unsigned short v0 = nox_xxx_servGamedataGet_40A020(v7);
		int v8 = v0;
		if (v8 < 1) {
			return;
		}
		int v9 = 0;
		for (int i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
			int v11 = *(uint32_t*)(*(uint32_t*)(i + 748) + 276);
			if (!(*(uint8_t*)(v11 + 3680) & 1) && *(uint32_t*)(v11 + 2140) < v8) {
				if (nox_xxx_servObjectHasTeam_419130(i + 48)) {
					char* v0 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(i + 52));
					if (v6) {
						if (v6 != v0) {
							return;
						}
					} else {
						v6 = v0;
					}
				} else {
					if (v9 || v6) {
						return;
					}
					v9 = i;
				}
			}
		}
		if (!nox_xxx_gamePlayIsAnyPlayers_40A8A0()) {
			return;
		}
		nox_xxx_setGameFlags_40A4D0(8);
		if (v6) {
			nox_xxx_netSendDMTeamWinner_4D8BF0((int)v6, 0);
		} else if (v9) {
			nox_xxx_netSendDMWinner_4D8B90(v9, 0);
		} else {
			nox_xxx_netSendDMWinner_4D8B90(0, 0);
		}
		return;
	}
	if (nox_common_gameFlags_check_40A5C0(512)) {
		return;
	}
	short v1 = nox_common_gameFlags_getVal_40A5B0();
	unsigned short v0a = nox_xxx_servGamedataGet_40A020(v1);
	int v2 = v0a;
	if (!v0a) {
		return;
	}
	for (char* v3 = nox_server_teamFirst_418B10(); v3; v3 = nox_server_teamNext_418B60(v3)) {
		if (*((int*)v3 + 13) >= v2) {
			nox_xxx_setGameFlags_40A4D0(8);
			nox_xxx_netSendDMTeamWinner_4D8BF0(v3, 0);
			return;
		}
	}
	for (int v4 = nox_xxx_getFirstPlayerUnit_4DA7C0(); v4; v4 = nox_xxx_getNextPlayerUnit_4DA7F0(v4)) {
		int v5 = *(uint32_t*)(*(uint32_t*)(v4 + 748) + 276);
		if (!(*(uint8_t*)(v5 + 3680) & 1) && *(int*)(v5 + 2136) >= v2) {
			nox_xxx_setGameFlags_40A4D0(8);
			nox_xxx_netSendDMWinner_4D8B90(v4, 0);
			break;
		}
	}
}
// 509BEA: variable 'v0' is possibly undefined

//----- (00509C30) --------------------------------------------------------
void sub_509C30(nox_playerInfo* pl) {
	int a1 = pl;
	char* v1; // edx

	if (!dword_5d4594_1599688) {
		nox_common_list_clear_425760(getMemAt(0x5D4594, 1599676));
		dword_5d4594_1599688 = 1;
	}
	v1 = (char*)calloc(1, 0x20u);
	*((uint32_t*)v1 + 6) = *(uint32_t*)(a1 + 2068);
	strcpy(v1 + 12, (const char*)(a1 + 2096));
	v1[28] = *(uint8_t*)(a1 + 2251);
	sub_4257F0(getMemIntPtr(0x5D4594, 1599676), v1);
}

//----- (00509CB0) --------------------------------------------------------
int* sub_509CB0() {
	int* result; // eax
	int* v1;     // esi
	int* v2;     // edi

	result = *(int**)&dword_5d4594_1599688;
	if (dword_5d4594_1599688) {
		result = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 1599676));
		v1 = result;
		if (result) {
			do {
				v2 = nox_common_list_getNextSafe_4258A0(v1);
				nox_common_list_remove_425920((uint32_t**)v1);
				free(v1);
				v1 = v2;
			} while (v2);
		}
	}
	return result;
}

//----- (00509CF0) --------------------------------------------------------
int sub_509CF0(const char* a1, char a2, int a3) {
	int* v3; // edi

	v3 = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 1599676));
	if (!v3) {
		return 1;
	}
	while (strcmp((const char*)v3 + 12, a1) || a2 == *((uint8_t*)v3 + 28) && a3 == v3[6]) {
		v3 = nox_common_list_getNextSafe_4258A0(v3);
		if (!v3) {
			return 1;
		}
	}
	return 0;
}

//----- (00509D80) --------------------------------------------------------
int sub_509D80(int a1) {
	int* v1; // edi

	v1 = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 1599676));
	if (!v1) {
		return 0;
	}
	while (strcmp((const char*)v1 + 12, (const char*)(a1 + 2096))) {
		v1 = nox_common_list_getNextSafe_4258A0(v1);
		if (!v1) {
			return 0;
		}
	}
	return 1;
}

//----- (00509E00) --------------------------------------------------------
int nox_xxx_xferDirectionToAngle_509E00(uint32_t* a1) {
	return *getMemU32Ptr(0x587000, 230072 + 4 * (*a1 + 3 * a1[1]));
}

//----- (00509E20) --------------------------------------------------------
int nox_xxx_xferIndexedDirection_509E20(int a1, int2* a2) {
	int v2;     // ecx
	int v3;     // ecx
	int result; // eax

	v2 = *getMemIntPtr(0x587000, 192088 + 8 * a1);
	if (v2 <= *(int*)&dword_587000_230092) {
		a2->field_0 = (v2 >= -*(int*)&dword_587000_230092) - 1;
	} else {
		a2->field_0 = 1;
	}
	v3 = *getMemIntPtr(0x587000, 192092 + 8 * a1);
	result = dword_587000_230092;
	if (v3 <= *(int*)&dword_587000_230092) {
		result = -*(int*)&dword_587000_230092;
		if (v3 >= -*(int*)&dword_587000_230092) {
			a2->field_4 = 0;
		} else {
			a2->field_4 = -1;
		}
	} else {
		a2->field_4 = 1;
	}
	return result;
}

//----- (00509E90) --------------------------------------------------------
int nox_xxx_mathDirection4ToAngle_509E90(int a1) { return *getMemU32Ptr(0x587000, 230056 + 4 * a1); }

//----- (00509EA0) --------------------------------------------------------
int nox_xxx_math_509EA0(int a1) {
	int2 a2; // [esp+0h] [ebp-8h]

	nox_xxx_xferIndexedDirection_509E20(a1, &a2);
	return a2.field_4 + a2.field_0 + 2 * a2.field_4 + 4;
}

//----- (00509ED0) --------------------------------------------------------
int nox_xxx_math_509ED0(float2* a1) {
	int result; // eax
	float v2;   // [esp+0h] [ebp-4h]

	v2 = (atan2(a1->field_4, a1->field_0) + 6.2831855) * 40.743664 + 0.5;
	result = nox_float2int(v2);
	if (result < 0) {
		result += (unsigned int)(255 - result) >> 8 << 8;
	}
	if (result >= 256) {
		result += -256 * ((unsigned int)result >> 8);
	}
	return result;
}

//----- (00509F20) --------------------------------------------------------
void nox_xxx_utilNormalizeVector_509F20(float2* a1) {
	double v1; // st7

	v1 = nox_double2float(sqrt(a1->field_0 * a1->field_0 + a1->field_4 * a1->field_4));
	a1->field_0 = a1->field_0 / v1;
	a1->field_4 = a1->field_4 / v1;
}

//----- (00509FF0) --------------------------------------------------------
int sub_509FF0(int a1) {
	int result; // eax

	result = a1;
	if (*(uint8_t*)(*(uint32_t*)a1 + 16) & 0x20) {
		*(uint32_t*)a1 = 0;
	}
	return result;
}

//----- (0050A010) --------------------------------------------------------
int nox_xxx_monsterActionIsCondition_50A010(int a1) {
	int result; // eax

	result = a1 < 39;
	LOBYTE(result) = a1 > 39;
	return result;
}

//----- (0050A020) --------------------------------------------------------
int nox_xxx_mobActionGet_50A020(int a1) {
	return *(uint32_t*)(*(uint32_t*)(a1 + 748) + 24 * (*(char*)(*(uint32_t*)(a1 + 748) + 544) + 23));
}

//----- (0050A040) --------------------------------------------------------
int sub_50A040(int a1) {
	int v1; // ebx
	int v2; // esi
	int* i; // edi
	int v4; // eax

	v1 = *(uint32_t*)(a1 + 748);
	v2 = *(char*)(v1 + 544) - 1;
	if (v2 < 0) {
		return 38;
	}
	for (i = (int*)(v1 + 8 * (3 * v2 + 69));; i -= 6) {
		v4 = nox_xxx_monsterActionIsCondition_50A010(*i);
		if (!v4) {
			break;
		}
		if (--v2 < 0) {
			return 38;
		}
	}
	return *(uint32_t*)(v1 + 8 * (3 * v2 + 69));
}
// 50A06B: variable 'v4' is possibly undefined

//----- (0050A090) --------------------------------------------------------
int nox_xxx_monsterIsActionScheduled_50A090(int a1, int a2) {
	int v2;      // ecx
	int v3;      // eax
	uint32_t* i; // ecx

	v2 = *(uint32_t*)(a1 + 748);
	v3 = *(char*)(v2 + 544) - 1;
	if (v3 < 0) {
		return 0;
	}
	for (i = (uint32_t*)(v2 + 8 * (3 * v3 + 69)); *i != a2; i -= 6) {
		if (--v3 < 0) {
			return 0;
		}
	}
	return 1;
}

//----- (0050A0D0) --------------------------------------------------------
int nox_xxx_checkMobAction_50A0D0(nox_object_t* a1p, int a2) {
	int a1 = a1p;
	int v2;      // ecx
	int v3;      // eax
	uint32_t* i; // ecx

	v2 = *(uint32_t*)(a1 + 748);
	v3 = *(char*)(v2 + 544);
	if (v3 < 0) {
		return 0;
	}
	for (i = (uint32_t*)(v2 + 8 * (3 * v3 + 69)); *i != a2; i -= 6) {
		if (--v3 < 0) {
			return 0;
		}
	}
	return 1;
}

//----- (0050A360) --------------------------------------------------------
int* nox_xxx_monsterAction_50A360(int a1, int a2) {
	int* result; // eax

	if (*(uint8_t*)(a1 + 8) & 2 &&
		*(uint32_t*)(*(uint32_t*)(a1 + 748) + 24 * (*(char*)(*(uint32_t*)(a1 + 748) + 544) + 23)) != a2) {
		result = nox_xxx_monsterPushAction_50A260(a1, a2);
	} else {
		result = 0;
	}
	return result;
}

//----- (0050A3A0) --------------------------------------------------------
void nox_xxx_monsterClearActionStack_50A3A0(int a1) {
	if (*(uint8_t*)(a1 + 8) & 2) {
		while (!sub_5341F0(a1)) {
			nox_xxx_monsterPopAction_50A160(a1);
		}
	}
}

//----- (0050A3D0) --------------------------------------------------------
int nox_xxx_monsterCallDieFn_50A3D0(uint32_t* a1) {
	int v1;     // ebx
	int i;      // edi
	int result; // eax
	int v4;     // ecx
	int v5;     // eax
	int v6;     // eax
	int v7;     // ecx
	int v8;     // edi
	int v9;     // ecx
	int v10;    // eax
	int v11;    // eax
	int v12;    // esi

	v1 = a1[187];
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		sub_50E1E0((int)a1);
	}
	for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
		if ((uint32_t*)nox_xxx_playerGetPossess_4DDF30(i) == a1) {
			nox_xxx_playerObserveClear_4DDEF0(i);
		}
	}
	nox_xxx_monsterClearActionStack_50A3A0((int)a1);
	nox_xxx_monsterPushAction_50A260((int)a1, 31);
	nox_xxx_monsterPushAction_50A260((int)a1, 30);
	result = nox_xxx_unitIsZombie_534A40((int)a1);
	if (!result) {
		v4 = a1[4];
		LOBYTE(v4) = v4 & 0x7F;
		a1[4] = v4;
		nox_xxx_action_4DA9F0(a1);
		nox_xxx_unitClearBuffs_4FF580((int)a1);
		if ((signed char)*(uint8_t*)(v1 + 1440) >= 0) {
			if (!nox_common_gameFlags_check_40A5C0(4096)) {
				goto LABEL_13;
			}
			v5 = nox_common_randomInt_415FA0(5, 8);
		} else {
			v5 = nox_common_randomInt_415FA0(10, 20);
		}
		nox_xxx_unitSetDecayTime_511660(a1, gameFPS() * v5);
	LABEL_13:
		v6 = a1[127];
		if (v6 && *(uint8_t*)(v6 + 8) & 4) {
			v7 = a1[3];
			v8 = *(uint32_t*)(v6 + 748);
			LOBYTE(v7) = v7 & 0x7F;
			a1[3] = v7;
			nox_xxx_netFxShield_0_4D9200(*(unsigned char*)(*(uint32_t*)(v8 + 276) + 2064), (int)a1);
			nox_xxx_netUnmarkMinimapObj_417300(*(unsigned char*)(*(uint32_t*)(v8 + 276) + 2064), (int)a1, 1);
		}
		v9 = a1[3];
		BYTE1(v9) &= 0xFEu;
		a1[3] = v9;
		nox_xxx_unitTransferSlaves_4EC4B0(a1);
		nox_xxx_unitClearOwner_4EC300(a1);
		v10 = a1[3];
		if (!(v10 & 0x2000)) {
			nox_xxx_dropAllItems_4EDA40(a1);
		}
		if (!nox_common_gameFlags_check_40A5C0(2048) && *(uint32_t*)(v1 + 2188) == 2 && *(uint32_t*)(v1 + 2184) == 2) {
			if (a1[130]) {
				v11 = nox_xxx_findParentChainPlayer_4EC580(a1[130]);
				if (*(uint8_t*)(v11 + 8) & 4) {
					sub_4FC0B0(v11, 1);
				}
			}
		}
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (result) {
			v12 = a1[130];
			if (v12) {
				result = nox_xxx_findParentChainPlayer_4EC580(v12);
				if (*(uint8_t*)(result + 8) & 4) {
					result = sub_4D6170(result);
				}
			}
		}
	}
	return result;
}

//----- (0050A850) --------------------------------------------------------
char nox_xxx_updateNPCAnimData_50A850(nox_object_t* a1p) {
	int a1 = a1p;
	uint8_t* v1;       // esi
	unsigned char* v2; // eax
	unsigned char v3;  // cl
	unsigned char v4;  // cl
	unsigned char v5;  // dl
	unsigned char v6;  // cl

	v1 = *(uint8_t**)(a1 + 748);
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		v2 = *(unsigned char**)&v1[24 * (char)v1[544] + 552];
		if (v2 == (unsigned char*)16 || v2 == (unsigned char*)17) {
			v1[483] = 0;
			return (char)v2;
		}
	}
	LOBYTE(v2) = v1[483];
	if (!(uint8_t)v2) {
		v2 = nox_xxx_unitNPCActionToAnim_533D00(a1);
		if (v2) {
			v1[480] = v2[9];
			if (!v2[9]) {
				goto LABEL_13;
			}
			v3 = v1[482] + 1;
			v1[482] = v3;
			if (v3 >= v2[10] + 1) {
				v4 = v1[481];
				v1[482] = 0;
				v1[481] = ++v4;
				v5 = v4;
				v6 = v2[9];
				if (v5 >= v6) {
					if (*((uint32_t*)v2 + 3)) {
						v1[481] = 0;
						return (char)v2;
					}
					v1[481] = v6 - 1;
				LABEL_13:
					v1[483] = 1;
					return (char)v2;
				}
			}
		}
	}
	return (char)v2;
}

//----- (0050A910) --------------------------------------------------------
int nox_xxx_mobAction_50A910(nox_object_t* a1p) {
	int a1 = a1p;
	int v1;       // ecx
	int v2;       // eax
	int result;   // eax
	uint32_t* v4; // esi
	int v5;       // edi
	uint32_t* v6; // ebx
	int v7;       // eax
	int v8;       // eax
	int v9;       // ecx
	int v10;      // eax
	int v11;      // ecx
	int v12;      // [esp+0h] [ebp-8h]
	int v13;      // [esp+4h] [ebp-4h]

	v1 = *(uint32_t*)(a1 + 748);
	v12 = v1;
	v2 = *(uint32_t*)(v1 + 1216);
	if (v2 && *(uint32_t*)(v2 + 16) & 0x8020) {
		*(uint32_t*)(v1 + 1216) = 0;
	}
	result = *(char*)(v1 + 544);
	if (result >= 0) {
		v4 = (uint32_t*)(v1 + 8 * (3 * result + 69));
		v13 = result + 1;
		while (1) {
			v5 = 0;
			if (*getMemU32Ptr(0x587000, 230388 + 16 * *v4) > 0) {
				v6 = v4 + 1;
				do {
					if (*getMemU32Ptr(0x587000, 230392 + 4 * (v5 + 4 * *v4)) == 1 && *v6) {
						sub_509FF0((int)v6);
					}
					++v5;
					v6 += 2;
				} while (v5 < *getMemIntPtr(0x587000, 230388 + 16 * *v4));
				v1 = v12;
			}
			switch (*v4) {
			case 3:
				v7 = v4[3];
				if (v7) {
					goto LABEL_26;
				}
				break;
			case 7:
			case 8:
				v10 = v4[3];
				if (v10) {
					if (nox_xxx_unitCanInteractWith_5370E0(a1, v10, 0) || nox_xxx_checkMobAction_50A0D0(a1, 3)) {
						v7 = v4[3];
						v11 = *(uint32_t*)(v7 + 56);
						goto LABEL_27;
					}
					v4[3] = 0;
				}
				break;
			case 0xF:
				v7 = *(uint32_t*)(v1 + 1196);
				if (v7) {
				LABEL_26:
					v11 = *(uint32_t*)(v7 + 56);
				LABEL_27:
					v4[1] = v11;
					v4[2] = *(uint32_t*)(v7 + 60);
				}
				break;
			case 0x11:
				v8 = v4[3];
				if (v8 && nox_xxx_unitCanInteractWith_5370E0(a1, v8, 0)) {
					v9 = v4[3];
					v4[1] = *(uint32_t*)(v9 + 56);
					v4[2] = *(uint32_t*)(v9 + 60);
				}
				break;
			default:
				break;
			}
			v4 -= 6;
			result = --v13;
			if (!v13) {
				break;
			}
			v1 = v12;
		}
	}
	return result;
}

//----- (0050AAE0) --------------------------------------------------------
int nox_xxx_minimapFirstMonster_50AAE0() {
	int v0; // eax

	v0 = nox_server_getFirstObject_4DA790();
	dword_5d4594_1599696 = v0;
	if (!v0) {
		return 0;
	}
	while (!(*(uint8_t*)(v0 + 8) & 2)) {
		v0 = nox_server_getNextObject_4DA7A0(v0);
		dword_5d4594_1599696 = v0;
		if (!v0) {
			return 0;
		}
	}
	return v0 + 56;
}

//----- (0050AB10) --------------------------------------------------------
int nox_xxx_minimapNextMonster_50AB10() {
	int v0; // eax

	v0 = nox_server_getNextObject_4DA7A0(*(int*)&dword_5d4594_1599696);
	dword_5d4594_1599696 = v0;
	if (!v0) {
		return 0;
	}
	while (!(*(uint8_t*)(v0 + 8) & 2)) {
		v0 = nox_server_getNextObject_4DA7A0(v0);
		dword_5d4594_1599696 = v0;
		if (!v0) {
			return 0;
		}
	}
	return v0 + 56;
}

//----- (0050AB50) --------------------------------------------------------
short sub_50AB50(int a1, int a2) {
	if (a1 < 0 || a1 >= 256 || a2 < 0 || a2 >= 256) {
		return 0;
	}
	return nox_server_xxx_1599716[a2 + (a1 << 8)].field_8;
}

//----- (0050AB90) --------------------------------------------------------
int nox_xxx_allocVisitNodesArray_50AB90() {
	int result; // eax

	result = nox_new_alloc_class("VisitNodes", 16, 1024);
	nox_alloc_visitNode_2386184 = result;
	if (result) {
		dword_5d4594_2386176 = calloc(1, 0x2000u);
		if (dword_5d4594_2386176) {
			dword_5d4594_2386172 = 0;
			result = 1;
		} else {
			nox_free_alloc_class(*(void**)&nox_alloc_visitNode_2386184);
			result = 0;
		}
	}
	return result;
}

//----- (0050ABF0) --------------------------------------------------------
void sub_50ABF0() {
	free(dword_5d4594_2386176);
	nox_free_alloc_class(*(void**)&nox_alloc_visitNode_2386184);
	nox_alloc_visitNode_2386184 = 0;
}

//----- (0050AC20) --------------------------------------------------------
int sub_50AC20(int a3, uint16_t* a2) {
	unsigned short* v2; // ecx
	unsigned short v3;  // dx
	unsigned short v4;  // ax
	unsigned short v5;  // dx
	short v6;           // ax
	uint32_t* v7;       // esi
	uint16_t* v8;       // edi
	int result;         // eax
	int v10;            // eax
	int v11;            // esi
	int v12;            // esi
	short v13;          // ax
	uint16_t* v14;      // edi
	short v15;          // ax
	uint16_t* v16;      // edi
	float v17;          // [esp+0h] [ebp-18h]
	float v18;          // [esp+0h] [ebp-18h]
	float v19;          // [esp+0h] [ebp-18h]
	float v20;          // [esp+0h] [ebp-18h]
	int v21;            // [esp+Ch] [ebp-Ch]
	float2 a1;          // [esp+10h] [ebp-8h]

	v2 = (unsigned short*)a3;
	v3 = *(uint16_t*)(a3 + 2);
	a3 = *(unsigned short*)a3;
	v21 = v3;
	if (!(nox_server_xxx_1599716[v3 + (a3 << 8)].field_8 & 0x3C)) {
		return 0;
	}
	dword_5d4594_2386152 = 0;
	v4 = *v2;
	v5 = v2[1];
	a1.field_0 = (double)a3 * 23.0;
	v6 = nox_server_xxx_1599716[v5 + (v4 << 8)].field_8;
	a1.field_4 = (double)v21 * 23.0;
	if (v6 & 0x10) {
		a3 = 2048;
		sub_517B70(&a1, sub_50AE80, (int)&a3);
		if (dword_5d4594_2386152) {
			v7 = (uint32_t*)(*(uint32_t*)(dword_5d4594_2386152 + 700) + 8);
			if (*(int*)(dword_5d4594_2386152 + 700) != -8) {
				if (*(uint32_t*)(dword_5d4594_2386152 + 16) & 0x1000000) {
					v8 = a2;
					*a2 = (short)*(int*)v7 / 23;
					result = 1;
					v8[1] = (int)v7[1] / 23;
					return result;
				}
			}
		}
		return 0;
	}
	if (v6 & 0x20) {
		a3 = 1024;
		sub_517B70(&a1, sub_50AE80, (int)&a3);
		v10 = dword_5d4594_2386152;
		if (!dword_5d4594_2386152) {
			return 0;
		}
		v11 = *(uint32_t*)(*(uint32_t*)(dword_5d4594_2386152 + 748) + 12);
		goto LABEL_18;
	}
	if (v6 & 4) {
		a3 = 0x4000;
		sub_517B70(&a1, sub_50AE80, (int)&a3);
		if (dword_5d4594_2386152) {
			v12 = *(uint32_t*)(*(uint32_t*)(dword_5d4594_2386152 + 748) + 4);
			if (v12) {
				if (*(uint32_t*)(dword_5d4594_2386152 + 16) & 0x1000000) {
					v17 = *(float*)(v12 + 56) * 0.043478262;
					v13 = nox_float2int(v17);
					v14 = a2;
					*a2 = v13;
					v18 = *(float*)(v12 + 60) * 0.043478262;
					v14[1] = nox_float2int(v18);
					return 1;
				}
			}
		}
		return 0;
	}
	if (v6 & 8) {
		a3 = 0x8000;
		sub_517B70(&a1, sub_50AE80, (int)&a3);
		v10 = dword_5d4594_2386152;
		if (dword_5d4594_2386152) {
			v11 = *(uint32_t*)(*(uint32_t*)(dword_5d4594_2386152 + 748) + 4);
		LABEL_18:
			if (v11 && *(uint32_t*)(v10 + 16) & 0x1000000) {
				v19 = *(float*)(v11 + 56) * 0.043478262;
				v15 = nox_float2int(v19);
				v16 = a2;
				*a2 = v15;
				v20 = *(float*)(v11 + 60) * 0.043478262;
				v16[1] = nox_float2int(v20);
				return 1;
			}
			return 0;
		}
	}
	return 0;
}

//----- (0050AE80) --------------------------------------------------------
void sub_50AE80(int a1, int a2) {
	if (*(uint32_t*)(a1 + 8) & *(uint32_t*)a2) {
		dword_5d4594_2386152 = a1;
	}
}

//----- (0050AEA0) --------------------------------------------------------
int sub_50AEA0(int a1, float2* a2, uint32_t* a3) {
	unsigned short* v3; // ecx
	unsigned short v4;  // dx
	unsigned short v5;  // ax
	unsigned short v6;  // dx
	short v7;           // ax
	int v9;             // [esp+0h] [ebp-Ch]
	float2 a1a;         // [esp+4h] [ebp-8h]

	v3 = (unsigned short*)a1;
	v4 = *(uint16_t*)(a1 + 2);
	a1 = *(unsigned short*)a1;
	v9 = v4;
	if (!(nox_server_xxx_1599716[v4 + (a1 << 8)].field_8 & 0x3C)) {
		return 0;
	}
	dword_5d4594_2386152 = 0;
	v5 = *v3;
	v6 = v3[1];
	a1a.field_0 = (double)a1 * 23.0;
	v7 = nox_server_xxx_1599716[v6 + (v5 << 8)].field_8;
	a1a.field_4 = (double)v9 * 23.0;
	if (v7 & 0x10) {
		a1 = 2048;
	} else if (v7 & 0x20) {
		a1 = 1024;
	} else if (v7 & 4) {
		a1 = 0x4000;
	} else if (v7 & 8) {
		a1 = 0x8000;
	}
	sub_517B70(&a1a, sub_50AE80, (int)&a1);
	if (!dword_5d4594_2386152 || !(*(uint32_t*)(dword_5d4594_2386152 + 16) & 0x1000000)) {
		return 0;
	}
	*a2 = *(float2*)(dword_5d4594_2386152 + 56);
	*a3 = *(uint32_t*)(dword_5d4594_2386152 + 36);
	return 1;
}

//----- (0050B2C0) --------------------------------------------------------
int nox_xxx_aiTestUnitDangerous_50B2C0(int a1) {
	int v1;             // ebp
	int result;         // eax
	double v3;          // st7
	int v4;             // eax
	double v5;          // st7
	int v6;             // ebx
	int v7;             // esi
	int v8;             // eax
	int v9;             // ecx
	unsigned char* v10; // edi
	float* v11;         // esi
	int v12;            // eax
	short v13;          // ax
	float v14;          // [esp+0h] [ebp-74h]
	float v15;          // [esp+0h] [ebp-74h]
	float v16;          // [esp+0h] [ebp-74h]
	float v17;          // [esp+0h] [ebp-74h]
	int v18;            // [esp+14h] [ebp-60h]
	int v19;            // [esp+18h] [ebp-5Ch]
	int v20;            // [esp+1Ch] [ebp-58h]
	float v21;          // [esp+20h] [ebp-54h]
	float v22;          // [esp+24h] [ebp-50h]
	float2 a2;          // [esp+28h] [ebp-4Ch]
	int v24;            // [esp+30h] [ebp-44h]
	char v25[60];       // [esp+38h] [ebp-3Ch]
	int a1a;            // [esp+78h] [ebp+4h]

	v1 = a1;
	result = *(uint32_t*)(a1 + 8);
	if (!(result & 0xC080) && (result & 0x2000 || !(*(uint8_t*)(a1 + 16) & 0x49)) &&
		(result & 0x2008 || *(uint8_t*)(a1 + 16) & 2)) {
		if (result & 0x10000) {
			memcpy(v25, (const void*)(a1 + 172), sizeof(v25));
			if (*(uint32_t*)(a1 + 172) == 2) {
				v3 = *(float*)&dword_587000_234176 + *(float*)(a1 + 176);
				*(float*)(a1 + 176) = v3;
				*(float*)(a1 + 180) = v3 * v3;
			} else if (*(uint32_t*)(a1 + 172) == 3) {
				*(float*)(a1 + 184) =
					*(float*)&dword_587000_234176 + *(float*)&dword_587000_234176 + *(float*)(a1 + 184);
				*(float*)(a1 + 188) =
					*(float*)&dword_587000_234176 + *(float*)&dword_587000_234176 + *(float*)(a1 + 188);
				nox_shape_box_calc((nox_shape*)(a1 + 172));
			}
			nox_xxx_objectUnkUpdateCoords_4E7290(a1);
		}
		v14 = *(float*)(a1 + 232) * 0.043478262;
		v4 = nox_float2int(v14);
		v5 = *(float*)(a1 + 236) * 0.043478262;
		v6 = v4;
		v24 = v4;
		v15 = v5;
		v7 = nox_float2int(v15);
		v16 = *(float*)(a1 + 240) * 0.043478262;
		v19 = nox_float2int(v16);
		v17 = *(float*)(a1 + 244) * 0.043478262;
		v8 = nox_float2int(v17);
		v9 = v7;
		v20 = v8;
		for (a1a = v7; v9 <= v8; a1a = v9) {
			v18 = v6;
			if (v6 <= v19) {
				v10 = &(nox_server_xxx_1599716[v9 + (v6 << 8)].field_8);
				do {
					v11 = getMemFloatPtr(0x587000, 234108);
					while (1) {
						v21 = (double)v18 * 23.0;
						a2.field_0 = v21 + *(v11 - 1);
						v22 = (double)a1a * 23.0;
						a2.field_4 = v22 + *v11;
						if (sub_547DB0(v1, &a2)) {
							break;
						}
						v11 += 2;
						if ((int)v11 >= (int)getMemAt(0x587000, 234180)) {
							goto LABEL_25;
						}
					}
					*((uint32_t*)v10 - 1) = dword_5d4594_2386164;
					v12 = *(uint32_t*)(v1 + 8);
					if (v12 & 8 || *(uint8_t*)(v1 + 16) & 2) {
						v13 = *(uint16_t*)v10 | 0x100;
						*(uint16_t*)v10 = v13;
						if (!(*(uint8_t*)(v1 + 16) & 0x10)) {
							HIBYTE(v13) |= 2u;
							*(uint16_t*)v10 = v13;
						}
					} else if (v12 & 0x2000) {
						v10[1] |= 4u;
					}
				LABEL_25:
					++v6;
					v10 += 3072;
					v18 = v6;
				} while (v6 <= v19);
				v9 = a1a;
				v8 = v20;
				v6 = v24;
			}
			++v9;
		}
		result = *(uint32_t*)(v1 + 8);
		if (result & 0x10000) {
			memcpy((void*)(v1 + 172), v25, 0x3Cu);
			result = nox_xxx_objectUnkUpdateCoords_4E7290(v1);
		}
	}
	return result;
}

//----- (0050B500) --------------------------------------------------------
void sub_50B500() { dword_5d4594_2386168 = 0; }

//----- (0050B510) --------------------------------------------------------
int sub_50B510() {
	int result; // eax

	result = 0;
	dword_5d4594_2386168 = 0;
	dword_5d4594_2386172 = 0;
	return result;
}

//----- (0050B520) --------------------------------------------------------
int sub_50B520() {
	int result; // eax
	int i;      // esi

	result = gameFrame();
	if ((unsigned int)(gameFrame() - dword_5d4594_2386172) >= 0xF) {
		dword_5d4594_2386172 = gameFrame();
		++dword_5d4594_2386164;
		result = nox_server_getFirstObject_4DA790();
		for (i = result; result; i = result) {
			nox_xxx_aiTestUnitDangerous_50B2C0(i);
			result = nox_server_getNextObject_4DA7A0(i);
		}
		dword_5d4594_2386168 = 1;
	}
	return result;
}

//----- (0050B810) --------------------------------------------------------
int sub_50B810(int a1, float* a2) {
	int v2;     // esi
	int v3;     // edi
	int result; // eax
	float v5;   // [esp+0h] [ebp-10h]
	float v6;   // [esp+0h] [ebp-10h]

	v5 = *a2 * 0.043478262;
	v2 = nox_float2int(v5);
	v6 = a2[1] * 0.043478262;
	v3 = nox_float2int(v6);
	if (sub_50B870(a1, v2, v3)) {
		result = 0;
	} else {
		result = nox_xxx_pathfind_preCheckWalls2_50B8A0(a1, v2, v3);
	}
	return result;
}

//----- (0050B870) --------------------------------------------------------
int sub_50B870(int a1, int a2, int a3) { return sub_57B630(a1, a2, a3) != -1; }

//----- (0050B8A0) --------------------------------------------------------
int nox_xxx_pathfind_preCheckWalls2_50B8A0(int a1, int a2, int a3) {
	int result; // eax

	if (sub_50B950(a1, a2, a3)) {
		result = 0;
	} else {
		result = sub_50B8E0(a1, a2, a3) == 0;
	}
	return result;
}

//----- (0050B8E0) --------------------------------------------------------
unsigned int sub_50B8E0(int a1, int a2, int a3) {
	unsigned int v4; // eax
	int v5;          // ecx

	int ind = (a3 + (a2 << 8));
	if (nox_server_xxx_1599716[ind].field_4 != dword_5d4594_2386164) {
		return 0;
	}
	HIWORD(v4) = HIWORD(a1);
	v5 = *(uint32_t*)(a1 + 16);
	if (v5 & 0x4000) {
		LOWORD(v4) = nox_server_xxx_1599716[ind].field_8;
		return (v4 >> 9) & 1;
	}
	if (nox_server_xxx_1599716[ind].field_8 & 0x100) {
		return 1;
	}
	if (sub_534020(a1) || !(nox_server_xxx_1599716[ind].field_8 & 0x400)) {
		return 0;
	}
	return 1;
}

//----- (0050B950) --------------------------------------------------------
int sub_50B950(int a1, int a2, int a3) {
	int v3;     // ecx
	int result; // eax

	v3 = *(uint32_t*)(a1 + 16);
	if (v3 & 0x4000) {
		result = (nox_server_xxx_1599716[a3 + (a2 << 8)].field_8 >> 1) & 0x1;
	} else {
		result = nox_server_xxx_1599716[a3 + (a2 << 8)].field_8 & 0x1;
	}
	return result;
}

//----- (0050B9A0) --------------------------------------------------------
int nox_xxx_genPathToPoint_50B9A0(int a1, int a2, int a3, float* a4) {
	*(uint8_t*)(*(uint32_t*)(a3 + 748) + 2172) = 0;
	nox_xxx_pathFind_50BA00(0, a3, (float*)(a3 + 56), a4, 0, 0);
	if (dword_5d4594_2386180 > a2 && !dword_5d4594_1599712) {
		dword_5d4594_1599712 = 1;
	}
	return nox_xxx_appendWorkPath_50C990(a1, 0, a2);
}

//----- (0050BA00) --------------------------------------------------------
void* nox_xxx_pathFind_50BA00(int a1, int a2, float* a3, float* a4, int (*a5)(int, int, int), int a6) {
	int v6;              // eax
	double v7;           // st7
	int v8;              // eax
	double v9;           // st7
	void* result;        // eax
	unsigned short* v11; // eax
	unsigned short v12;  // cx
	unsigned short v13;  // dx
	unsigned short* v14; // ebx
	unsigned short* v15; // esi
	int v16;             // edx
	int v17;             // edi
	int v18;             // eax
	int v19;             // edi
	int v20;             // edx
	int v21;             // ecx
	unsigned short v22;  // bp
	int v23;             // ebp
	int v24;             // ebx
	unsigned short v25;  // ax
	int v26;             // ecx
	float v27;           // edx
	float v28;           // eax
	int v29;             // ecx
	int v30;             // edi
	uint16_t* v31;       // eax
	unsigned short* v32; // eax
	unsigned short* v33; // ebp
	unsigned short* v34; // esi
	unsigned short* v35; // edi
	int v36;             // eax
	int v37;             // eax
	bool v38;            // zf
	int v39;             // eax
	int v40;             // eax
	int v41;             // eax
	int v42;             // eax
	int v43;             // eax
	int v44;             // eax
	unsigned short* v45; // esi
	unsigned short* v46; // edi
	int v47;             // [esp-4h] [ebp-70h]
	int v48;             // [esp-4h] [ebp-70h]
	int v49;             // [esp-4h] [ebp-70h]
	int v50;             // [esp-4h] [ebp-70h]
	float v51;           // [esp+0h] [ebp-6Ch]
	float v52;           // [esp+0h] [ebp-6Ch]
	float v53;           // [esp+0h] [ebp-6Ch]
	float v54;           // [esp+0h] [ebp-6Ch]
	int v55;             // [esp+0h] [ebp-6Ch]
	int v56;             // [esp+0h] [ebp-6Ch]
	int v57;             // [esp+0h] [ebp-6Ch]
	int v58;             // [esp+0h] [ebp-6Ch]
	int v59;             // [esp+14h] [ebp-58h]
	char v60;            // [esp+18h] [ebp-54h]
	int v61;             // [esp+1Ch] [ebp-50h]
	int i;               // [esp+20h] [ebp-4Ch]
	int v63;             // [esp+24h] [ebp-48h]
	int v64;             // [esp+28h] [ebp-44h]
	int v65;             // [esp+2Ch] [ebp-40h]
	int v66;             // [esp+30h] [ebp-3Ch]
	int v67;             // [esp+34h] [ebp-38h]
	short v68[2];        // [esp+38h] [ebp-34h]
	int v69;             // [esp+3Ch] [ebp-30h]
	int v70;             // [esp+40h] [ebp-2Ch]
	unsigned char* v71;  // [esp+44h] [ebp-28h]
	unsigned char* v72;  // [esp+48h] [ebp-24h]
	int v73;             // [esp+4Ch] [ebp-20h]
	int v74;             // [esp+50h] [ebp-1Ch]
	int2 a2a;            // [esp+54h] [ebp-18h]
	float4 v76;          // [esp+5Ch] [ebp-10h]
	unsigned short* v77; // [esp+78h] [ebp+Ch]

	v67 = 0;
	v64 = 0;
	v65 = 0;
	v59 = a1 != 0 ? 0 : 999999;
	dword_5d4594_1599712 = 0;
	++dword_5d4594_2386160;
	if (!dword_5d4594_2386168) {
		sub_50B520();
	}
	v51 = *a3 * 0.043478262;
	v6 = nox_float2int(v51);
	v7 = a3[1] * 0.043478262;
	a2a.field_0 = v6;
	v52 = v7;
	a2a.field_4 = nox_float2int(v52);
	nox_xxx_pathfind_preCheckWalls_50C8D0(a2, &a2a);
	v61 = 0;
	v63 = !nox_xxx_pathfind_preCheckWalls2_50B8A0(a2, a2a.field_0, a2a.field_4);
	if (a5 && !a5(a2, a2a.field_0, a2a.field_4)) {
		v61 = 1;
	}
	v53 = *a4 * 0.043478262;
	v8 = nox_float2int(v53);
	v9 = a4[1] * 0.043478262;
	v73 = v8;
	v54 = v9;
	v74 = nox_float2int(v54);
	result = *(void**)&nox_alloc_visitNode_2386184;
	if (!nox_alloc_visitNode_2386184) {
		dword_5d4594_2386180 = 0;
		dword_5d4594_1599712 = 2;
		return result;
	}
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_visitNode_2386184);
	v11 = (unsigned short*)nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_visitNode_2386184);
	*v11 = a2a.field_0;
	v11[1] = a2a.field_4;
	v12 = *v11;
	v13 = v11[1];
	*((uint32_t*)v11 + 1) = 0;
	*((uint32_t*)v11 + 2) = 0;
	v14 = v11;
	v66 = 0;
	nox_server_xxx_1599716[v13 + (v12 << 8)].field_0 = dword_5d4594_2386160;
	while (2) {
		v15 = v14;
		v14 = 0;
		v77 = 0;
		if (!v15) {
			goto LABEL_40;
		}
		while (2) {
			v16 = *v15;
			v17 = v15[1];
			v18 = ((unsigned short)v16 - v73) * ((unsigned short)v16 - v73) +
				  ((unsigned short)v17 - v74) * ((unsigned short)v17 - v74);
			if (a1) {
				if (v18 > v59) {
					v67 = (int)v15;
					v59 = ((unsigned short)v16 - v73) * ((unsigned short)v16 - v73) +
						  ((unsigned short)v17 - v74) * ((unsigned short)v17 - v74);
				}
			} else {
				if (v18 < v59) {
					v67 = (int)v15;
					v59 = ((unsigned short)v16 - v73) * ((unsigned short)v16 - v73) +
						  ((unsigned short)v17 - v74) * ((unsigned short)v17 - v74);
				}
				if (!v63 && !v61 && v16 == v73 && v17 == v74) {
					dword_5d4594_1599712 = 0;
					return (void*)sub_50C320(a2, (int)v15, a4);
				}
			}
			v69 = nox_common_randomInt_415FA0(0, 7);
			for (i = 0; i < 8; ++i) {
				v19 = (i + v69) % 8;
				v20 = *getMemU32Ptr(0x587000, 234216 + 8 * v19);
				v21 = *getMemU32Ptr(0x587000, 234220 + 8 * v19);
				v22 = *v15;
				v72 = getMemAt(0x587000, 234216 + 8 * v19);
				v23 = v20 + v22;
				v24 = v21 + v15[1];
				v71 = getMemAt(0x587000, 234220 + 8 * v19);
				if (v23 < 0 || v23 >= 256 || v24 < 0 || v24 >= 256 ||
					nox_server_xxx_1599716[v24 + (v23 << 8)].field_0 == dword_5d4594_2386160) {
					continue;
				}
				nox_server_xxx_1599716[v24 + (v23 << 8)].field_0 = dword_5d4594_2386160;
				if (v23 == v73 && v24 == v74) {
					v25 = v15[1];
					v70 = 23 * *v15 + 11;
					v76.field_0 = (double)v70;
					v26 = 23 * v25;
					v27 = *a4;
					v28 = a4[1];
					v70 = v26 + 11;
					v76.field_8 = v27;
					v76.field_4 = (double)(v26 + 11);
					v76.field_C = v28;
					if (nox_xxx_mapTraceObstacles_50B580(a2, &v76)) {
						v29 = *(uint32_t*)(a2 + 16);
						if (v29 & 0x4000) {
							if (nox_xxx_mapTraceRay_535250(&v76, 0, 0, 5)) {
								goto LABEL_31;
							}
						} else if (nox_xxx_mapTraceRay_535250(&v76, 0, 0, 1)) {
						LABEL_31:
							v30 = a2;
							goto LABEL_32;
						}
					}
				}
				if (v19 < 4) {
					v30 = a2;
				} else {
					v60 = ~(*(uint16_t*)(a2 + 16) >> 8) & 0xD8 | 0x98;
					sub_57B4D0(a2);
					switch (v19) {
					case 4:
						v36 = (unsigned char)sub_57B500(*v15, v15[1] + 1, v60);
						if (v36 != 1 && v36 != 6 && v36 != 10 && v36 != 9 && v36 != 255) {
							continue;
						}
						LOBYTE(v37) = sub_57B500(*v15 + 1, v15[1], v60);
						goto LABEL_54;
					case 5:
						v39 = (unsigned char)sub_57B500(*v15 - 1, v15[1], v60);
						if (v39 != 1 && v39 != 6 && v39 != 10 && v39 != 9 && v39 != 255) {
							continue;
						}
						LOBYTE(v37) = sub_57B500(*v15, v15[1] - 1, v60);
					LABEL_54:
						v37 = (unsigned char)v37;
						if ((unsigned char)v37 == 1 || v37 == 4 || v37 == 7) {
							goto LABEL_86;
						}
						v38 = v37 == 8;
						break;
					case 6:
						v40 = (unsigned char)sub_57B500(*v15, v15[1] + 1, v60);
						if (v40 && v40 != 5 && v40 != 9 && v40 != 8 && v40 != 255) {
							continue;
						}
						v37 = (unsigned char)sub_57B500(*v15 - 1, v15[1], v60);
						if (!v37 || v37 == 3 || v37 == 10) {
							goto LABEL_86;
						}
						v38 = v37 == 7;
						break;
					case 7:
						v41 = (unsigned char)sub_57B500(*v15 + 1, v15[1], v60);
						if (v41 && v41 != 5 && v41 != 9 && v41 != 8 && v41 != 255) {
							continue;
						}
						v42 = (unsigned char)sub_57B500(*v15, v15[1] - 1, v60);
						if (v42) {
							if (v42 != 3 && v42 != 10 && v42 != 7 && v42 != 255) {
								continue;
							}
						}
						goto LABEL_86;
					default:
						goto LABEL_86;
					}
					if (!v38 && v37 != 255) {
						continue;
					}
				LABEL_86:
					v30 = a2;
					if (sub_50B950(a2, *v15, *(uint32_t*)v71 + v15[1]) ||
						sub_50B950(a2, *(uint32_t*)v72 + *v15, v15[1])) {
						continue;
					}
				}
				if (sub_50B870(v30, v23, v24)) {
					continue;
				}
				if (v73 != v23 || v74 != v24) {
					if (!sub_50C830(v30, v23, v24)) {
						continue;
					}
				} else if (!sub_50C830(v30, v23, v24)) {
					continue;
				}
				v43 = nox_xxx_pathfind_preCheckWalls2_50B8A0(v30, v23, v24);
				if (v63) {
					if (v43) {
						v64 = 1;
					} else if (!sub_50B950(v30, *v15, v15[1]) && sub_50B950(v30, v23, v24)) {
						continue;
					}
				} else {
					if (!v43) {
						continue;
					}
					if (a5) {
						v44 = a5(v30, v23, v24);
						if (v61) {
							if (v44) {
								v65 = 1;
							}
						} else if (!v44) {
							continue;
						}
					}
				}
			LABEL_32:
				v31 = nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_visitNode_2386184);
				if (!v31) {
					v55 = *(uint32_t*)(v30 + 36);
					v47 = nox_xxx_getUnitName_4E39D0(v30);
					nox_ai_debug_printf_5341A0("%d: %s(#%d), buildPath: Exhausted search storage\n",
											   gameFrame(), v47, v55);
				LABEL_130:
					dword_5d4594_1599712 = 1;
					return (void*)sub_50C320(v30, v67, 0);
				}
				*v31 = v23;
				v31[1] = v24;
				*((uint32_t*)v31 + 1) = v15;
				*((uint32_t*)v31 + 2) = v77;
				v77 = v31;
			}
			if (!sub_50AC20((int)v15, v68)) {
				goto LABEL_38;
			}
			*((uint8_t*)v15 + 12) |= 2u;
			v32 = (unsigned short*)nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_visitNode_2386184);
			if (!v32) {
				v30 = a2;
				v56 = *(uint32_t*)(a2 + 36);
				v48 = nox_xxx_getUnitName_4E39D0(a2);
				nox_ai_debug_printf_5341A0("%d: %s(#%d), buildPath: Exhausted search storage\n", gameFrame(),
										   v48, v56);
				goto LABEL_130;
			}
			*(uint32_t*)v32 = *(uint32_t*)v68;
			*((uint32_t*)v32 + 1) = v15;
			*((uint32_t*)v32 + 2) = v77;
			v77 = v32;
		LABEL_38:
			v15 = (unsigned short*)*((uint32_t*)v15 + 2);
			if (v15) {
				continue;
			}
			break;
		}
		v14 = v77;
	LABEL_40:
		v33 = 0;
		if (v64) {
			v34 = v14;
			if (v14) {
				do {
					v35 = (unsigned short*)*((uint32_t*)v34 + 2);
					if (nox_xxx_pathfind_preCheckWalls2_50B8A0(a2, *v34, v34[1])) {
						v33 = v34;
					} else if (v33) {
						*((uint32_t*)v33 + 2) = *((uint32_t*)v34 + 2);
					} else {
						v14 = (unsigned short*)*((uint32_t*)v34 + 2);
					}
					v34 = v35;
				} while (v35);
				v33 = 0;
			}
			v63 = 0;
			v64 = 0;
		}
		if (v65) {
			v45 = v14;
			if (v14) {
				do {
					v46 = (unsigned short*)*((uint32_t*)v45 + 2);
					if (a5(a2, *v45, v45[1])) {
						v33 = v45;
					} else if (v33) {
						*((uint32_t*)v33 + 2) = *((uint32_t*)v45 + 2);
					} else {
						v14 = (unsigned short*)*((uint32_t*)v45 + 2);
					}
					v45 = v46;
				} while (v46);
			}
			v61 = 0;
			v65 = 0;
		}
		if (v14) {
			if (a6 && v66 >= a6) {
				v58 = *(uint32_t*)(a2 + 36);
				v50 = nox_xxx_getUnitName_4E39D0(a2);
				nox_ai_debug_printf_5341A0("%d: %s(#%d), buildPath: Reached search depth limit\n",
										   gameFrame(), v50, v58);
				goto LABEL_134;
			}
			++v66;
			continue;
		}
		break;
	}
	v57 = *(uint32_t*)(a2 + 36);
	v49 = nox_xxx_getUnitName_4E39D0(a2);
	nox_ai_debug_printf_5341A0("%d: %s(#%d), buildPath: Exhausted search space\n", gameFrame(), v49, v57);
LABEL_134:
	v30 = a2;
	dword_5d4594_1599712 = 2;
	return (void*)sub_50C320(v30, v67, 0);
}

//----- (0050C320) --------------------------------------------------------
int sub_50C320(int a1, int a2, uint32_t* a3) {
	int result;         // eax
	unsigned short* v4; // edi
	int v5;             // esi
	uint32_t* v6;       // eax
	unsigned short* v7; // esi
	int v8;             // ebp
	int v9;             // eax
	char v10;           // cl
	int v11;            // ebx
	int v12;            // ecx
	unsigned short v13; // ax
	int v14;            // edx
	unsigned short v15; // ax
	int v16;            // ecx
	unsigned short v17; // ax
	double v18;         // st7
	double v19;         // st7
	double v20;         // st7
	int v21;            // ecx
	uint32_t* v22;      // eax
	uint32_t* v23;      // edx
	int v24;            // eax
	int v25;            // [esp+Ch] [ebp-1Ch]
	float2 v26;         // [esp+10h] [ebp-18h]
	float4 v27;         // [esp+18h] [ebp-10h]

	result = a1;
	v4 = (unsigned short*)a2;
	v5 = *(uint32_t*)(a1 + 748);
	v25 = *(uint32_t*)(a1 + 748);
	if (!a2) {
		dword_5d4594_2386180 = 0;
		return result;
	}
	v6 = a3;
	if (a3) {
		*(uint32_t*)((int)dword_5d4594_2386176 + 0) = *a3;
		*(uint32_t*)((int)dword_5d4594_2386176 + 4) = v6[1];
	} else if (*(uint8_t*)(a2 + 12) & 2 && sub_50AEA0(a2, &v26, &a1)) {
		*(float*)((int)dword_5d4594_2386176 + 0) = v26.field_0;
		*(float*)((int)dword_5d4594_2386176 + 4) = v26.field_4;
		if (*(uint8_t*)(v5 + 2172) < 8u) {
			*(uint32_t*)(v5 + 4 * (unsigned char)(*(uint8_t*)(v5 + 2172))++ + 2140) = a1;
		}
	} else {
		a2 = *v4;
		*(float*)((int)dword_5d4594_2386176 + 0) = (double)a2 * 23.0 + 11.5;
		a2 = v4[1];
		*(float*)((int)dword_5d4594_2386176 + 4) = (double)a2 * 23.0 + 11.5;
	}
	v7 = (unsigned short*)*((uint32_t*)v4 + 1);
	v8 = 1;
	if (v7) {
		while (1) {
			v9 = *v7 - *v4;
			v10 = *((uint8_t*)v7 + 12);
			v11 = v7[1] - v4[1];
			a2 = *v7 - *v4;
			if (!(v10 & 2)) {
				goto LABEL_19;
			}
			if (!sub_50AEA0((int)v7, &v26, &a1)) {
				break;
			}
			v12 = v25;
			*(float*)((int)dword_5d4594_2386176 + 8 * v8) = v26.field_0;
			*(float*)((int)dword_5d4594_2386176 + 8 * v8 + 4) = v26.field_4;
			if (*(uint8_t*)(v25 + 2172) < 8u) {
				a2 = a2 * a2 + v11 * v11;
				if ((double)a2 > 4761.0) {
					goto LABEL_17;
				}
				v13 = v7[1];
				a2 = 23 * *v7 + 11;
				v14 = 23 * v13;
				v15 = *v4;
				v27.field_0 = (double)a2;
				a2 = v14 + 11;
				v16 = 23 * v15;
				v17 = v4[1];
				v27.field_4 = (double)(v14 + 11);
				v27.field_8 = (double)(v16 + 11);
				a2 = 23 * v17 + 11;
				v27.field_C = (double)a2;
				if (!nox_xxx_mapTraceRay_535250(&v27, 0, 0, 1)) {
					v12 = v25;
				LABEL_17:
					*(uint32_t*)(v12 + 4 * (unsigned char)(*(uint8_t*)(v12 + 2172))++ + 2140) = a1;
					goto LABEL_38;
				}
			}
		LABEL_38:
			v4 = v7;
			v7 = (unsigned short*)*((uint32_t*)v7 + 1);
			++v8;
			if (!v7) {
				goto LABEL_39;
			}
		}
		v9 = a2;
	LABEL_19:
		if (v9 <= 0) {
			if (v9 < 0) {
				if (v11 > 0) {
					a2 = *v7;
					*(float*)((int)dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 23.0 - 2.3;
					a2 = v7[1];
					v20 = (double)a2;
				LABEL_29:
					*(float*)((int)dword_5d4594_2386176 + 8 * v8 + 4) = v20 * 23.0 + 2.3;
					goto LABEL_38;
				}
				if (v11 < 0) {
					a2 = *v7;
					*(float*)((int)dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 23.0 - 2.3;
					a2 = v7[1];
					v18 = (double)a2;
					goto LABEL_37;
				}
				a2 = *v7;
				*(float*)((int)dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 23.0 - 2.3;
				a2 = v7[1];
				v19 = (double)a2;
				goto LABEL_25;
			}
			if (v11 > 0) {
				a2 = *v7;
				*(float*)((int)dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 11.5;
				a2 = v7[1];
				v20 = (double)a2;
				goto LABEL_29;
			}
			if (v11 < 0) {
				a2 = *v7;
				*(float*)((int)dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 11.5;
				a2 = v7[1];
				v18 = (double)a2;
				goto LABEL_37;
			}
		} else {
			if (v11 <= 0) {
				if (v11 < 0) {
					a2 = *v7;
					*(float*)((int)dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 2.3;
					a2 = v7[1];
					v18 = (double)a2;
				LABEL_37:
					*(float*)((int)dword_5d4594_2386176 + 8 * v8 + 4) = v18 * 23.0 + 23.0 - 2.3;
					goto LABEL_38;
				}
				a2 = *v7;
				*(float*)((int)dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 2.3;
				a2 = v7[1];
				v19 = (double)a2;
			LABEL_25:
				*(float*)((int)dword_5d4594_2386176 + 8 * v8 + 4) = v19 * 23.0 + 11.5;
				goto LABEL_38;
			}
			a2 = *v7;
			*(float*)((int)dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 2.3;
			a2 = v7[1];
			*(float*)((int)dword_5d4594_2386176 + 8 * v8 + 4) = (double)a2 * 23.0 + 2.3;
		}
		goto LABEL_38;
	}
LABEL_39:
	v21 = 0;
	dword_5d4594_2386180 = v8;
	for (result = v8 / 2; v21 < *(int*)&dword_5d4594_2386180 / 2; result = dword_5d4594_2386180 / 2) {
		v22 = (uint32_t*)((int)dword_5d4594_2386176 + 8 * v21);
		v23 = (uint32_t*)((int)dword_5d4594_2386176 + 8 * (v8 - v21) - 8);
		v26 = *(float2*)((int)dword_5d4594_2386176 + 8 * v21);
		*v22 = *v23;
		v22[1] = v23[1];
		v24 = dword_5d4594_2386180 - v21++;
		*(float*)((int)dword_5d4594_2386176 + 8 * v24 - 8) = v26.field_0;
		*(float*)((int)dword_5d4594_2386176 + 8 * v24 - 4) = v26.field_4;
		v8 = dword_5d4594_2386180;
	}
	return result;
}

//----- (0050C830) --------------------------------------------------------
int sub_50C830(int a1, int a2, int a3) {
	int v3;    // ecx
	float* v4; // esi
	float2 v6; // [esp+4h] [ebp-8h]
	float v7;  // [esp+10h] [ebp+4h]
	float v8;  // [esp+14h] [ebp+8h]

	v3 = *(uint32_t*)(a1 + 16);
	if (v3 & 0x4000 || sub_534020(a1)) {
		return 1;
	}
	v4 = getMemFloatPtr(0x587000, 234188);
	v8 = (double)(23 * a2);
	while (1) {
		v6.field_0 = v8 + *(v4 - 1);
		v7 = (double)(23 * a3);
		v6.field_4 = v7 + *v4;
		if (nox_xxx_tileNFromPoint_411160(&v6) == 6) {
			break;
		}
		v4 += 2;
		if ((int)v4 >= (int)getMemAt(0x587000, 234220)) {
			return 1;
		}
	}
	return 0;
}

//----- (0050C8D0) --------------------------------------------------------
void nox_xxx_pathfind_preCheckWalls_50C8D0(int a1, int2* a2) {
	int v2;         // ecx
	int v3;         // edx
	long double v4; // st7
	float v5;       // [esp+Ch] [ebp-4h]
	float v6;       // [esp+Ch] [ebp-4h]

	if (sub_50B870(a1, a2->field_0, a2->field_4)) {
		v2 = a2->field_0;
		v3 = a2->field_4;
		v5 = (double)v3 * 23.0 + 11.5;
		v4 = *(float*)(a1 + 56) - ((double)a2->field_0 * 23.0 + 11.5);
		v6 = *(float*)(a1 + 60) - v5;
		if (fabs(v6) >= fabs(v4)) {
			if (v6 <= 0.0) {
				a2->field_4 = v3 - 1;
			} else {
				a2->field_4 = v3 + 1;
			}
		} else if (v4 <= 0.0) {
			a2->field_0 = v2 - 1;
		} else {
			a2->field_0 = v2 + 1;
		}
	}
}

//----- (0050C990) --------------------------------------------------------
int nox_xxx_appendWorkPath_50C990(int a1, int a2, int a3) {
	int v3;       // ecx
	int v4;       // esi
	int v5;       // eax
	uint32_t* v6; // edi

	v3 = 0;
	if (*(int*)&dword_5d4594_2386180 <= 0) {
		return a2;
	}
	v4 = a2;
	v5 = a1 + 8 * a2;
	while (v4 != a3 - 1) {
		++v4;
		v5 += 8;
		v6 = (uint32_t*)((int)dword_5d4594_2386176 + 8 * v3++);
		*(uint32_t*)(v5 - 8) = *v6;
		*(uint32_t*)(v5 - 4) = v6[1];
		if (v3 >= *(int*)&dword_5d4594_2386180) {
			return v4;
		}
	}
	nox_ai_debug_printf_5341A0("appendWorkPath: Path truncated.\n");
	return v4;
}

//----- (0050CA00) --------------------------------------------------------
int nox_xxx_generateRetreatPath_50CA00(int a1, int a2, int a3, float* a4) {
	*(uint8_t*)(*(uint32_t*)(a3 + 748) + 2172) = 0;
	nox_xxx_pathFind_50BA00(1, a3, (float*)(a3 + 56), a4, sub_50CA60, 6);
	if (dword_5d4594_2386180 > a2 && !dword_5d4594_1599712) {
		dword_5d4594_1599712 = 1;
	}
	return nox_xxx_appendWorkPath_50C990(a1, 0, a2);
}

//----- (0050CA60) --------------------------------------------------------
int sub_50CA60(int a4, int a2, int a3) {
	float2 a1; // [esp+0h] [ebp-8h]

	dword_5d4594_1599708 = 0;
	a1.field_0 = (double)a2 * 23.0 + 11.5;
	a1.field_4 = (double)a3 * 23.0 + 11.5;
	nox_xxx_unitsGetInCircle_517F90(&a1, 100.0, sub_50CAC0, a4);
	return dword_5d4594_1599708 == 0;
}

//----- (0050CAC0) --------------------------------------------------------
void sub_50CAC0(int a1, int a2) {
	if (dword_5d4594_1599708 != 1) {
		if (nox_xxx_unitIsEnemyTo_5330C0(a2, a1)) {
			dword_5d4594_1599708 = 1;
		}
	}
}

//----- (0050CAF0) --------------------------------------------------------
int nox_xxx_pathFindStatus_50CAF0() { return dword_5d4594_1599712; }

//----- (0050CB00) --------------------------------------------------------
int sub_50CB00() { return dword_5d4594_2386180; }

//----- (0050CB10) --------------------------------------------------------
void* sub_50CB10() { return dword_5d4594_2386176; }

//----- (0050CB20) --------------------------------------------------------
int sub_50CB20(int a1, float* a2) {
	int v2;              // eax
	double v3;           // st7
	unsigned short* v4;  // eax
	int v5;              // ecx
	unsigned short* v6;  // ebp
	int v7;              // esi
	int v8;              // edi
	unsigned char* v9;   // ebx
	int v10;             // esi
	int v11;             // edi
	uint16_t* v12;       // eax
	float v14;           // [esp+0h] [ebp-24h]
	float v15;           // [esp+0h] [ebp-24h]
	int v16;             // [esp+0h] [ebp-24h]
	int2 a2a;            // [esp+14h] [ebp-10h]
	float2 v18;          // [esp+1Ch] [ebp-8h]
	unsigned short* v19; // [esp+2Ch] [ebp+8h]

	++dword_5d4594_2386160;
	v14 = *a2 * 0.043478262;
	v2 = nox_float2int(v14);
	v3 = a2[1] * 0.043478262;
	a2a.field_0 = v2;
	v15 = v3;
	a2a.field_4 = nox_float2int(v15);
	nox_xxx_pathfind_preCheckWalls_50C8D0(a1, &a2a);
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_visitNode_2386184);
	v4 = (unsigned short*)nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_visitNode_2386184);
	*v4 = a2a.field_0;
	v4[1] = a2a.field_4;
	v5 = v4[1] + (*v4 << 8);
	*((uint32_t*)v4 + 1) = 0;
	*((uint32_t*)v4 + 2) = 0;
	nox_server_xxx_1599716[v5].field_0 = dword_5d4594_2386160;
	do {
		v6 = v4;
		v19 = 0;
		if (!v4) {
			break;
		}
		do {
			v7 = *v6;
			v8 = v6[1];
			if (nox_server_xxx_1599716[(unsigned short)v8 + (v7 << 8)].field_8 & 0x40 && !sub_50B870(a1, v7, v8)) {
				v18.field_0 = (double)(23 * v7 + 11);
				v18.field_4 = (double)(23 * v8 + 11);
				return sub_518740(&v18, 0x80u);
			}
			v9 = getMemAt(0x587000, 234284);
			do {
				v10 = *v6 + *((uint32_t*)v9 - 1);
				v11 = *(uint32_t*)v9 + v6[1];
				if (v10 >= 0 && v10 < 256 && v11 >= 0 && v11 < 256 &&
					nox_server_xxx_1599716[v11 + (v10 << 8)].field_0 != dword_5d4594_2386160) {
					v16 = *(uint32_t*)v9 + v6[1];
					nox_server_xxx_1599716[v11 + (v10 << 8)].field_0 = dword_5d4594_2386160;
					if (!sub_50B870(a1, v10, v16)) {
						if (sub_50C830(a1, v10, v11)) {
							v12 = nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_visitNode_2386184);
							if (v12) {
								*v12 = v10;
								v12[1] = v11;
								*((uint32_t*)v12 + 1) = v6;
								*((uint32_t*)v12 + 2) = v19;
								v19 = v12;
							}
						}
					}
				}
				v9 += 8;
			} while ((int)v9 < (int)getMemAt(0x587000, 234316));
			v6 = (unsigned short*)*((uint32_t*)v6 + 2);
		} while (v6);
		v4 = v19;
	} while (v19);
	return 0;
}

//----- (0050D220) --------------------------------------------------------
int nox_xxx_creatureSetDetailedPath_50D220(int a1, int a2) {
	int result; // eax
	int v3;     // esi
	int v4;     // edi

	result = 0;
	v3 = *(uint32_t*)(a1 + 748);
	v4 = *(uint32_t*)(v3 + 280);
	*(uint32_t*)(v3 + 268) = 0;
	if ((unsigned int)(gameFrame() - v4) >= 0xA) {
		*(uint32_t*)(v3 + 272) = *(uint32_t*)a2;
		*(uint32_t*)(v3 + 276) = *(uint32_t*)(a2 + 4);
		*(uint32_t*)(v3 + 8) = nox_xxx_genPathToPoint_50B9A0(v3 + 12, 32, a1, (float*)a2);
		result = nox_xxx_pathFindStatus_50CAF0();
		*(uint8_t*)(v3 + 284) = result;
		*(uint32_t*)(v3 + 280) = gameFrame();
	} else {
		*(uint32_t*)(v3 + 8) = 0;
		*(uint8_t*)(v3 + 284) = 1;
	}
	return result;
}

//----- (0050D2A0) --------------------------------------------------------
int sub_50D2A0(int a1, int a2) {
	uint32_t* v2; // esi
	int result;   // eax

	v2 = *(uint32_t**)(a1 + 748);
	v2[92] = *(uint32_t*)a2;
	v2[93] = *(uint32_t*)(a2 + 4);
	result = sub_547F20(a1, (float*)a2);
	v2[74] = result;
	v2[91] = 0;
	return result;
}

//----- (0050D2E0) --------------------------------------------------------
int sub_50D2E0(int a1) {
	int v1;       // esi
	int v2;       // edi
	int v3;       // edx
	int v4;       // ecx
	double v5;    // st7
	double v6;    // st6
	uint32_t* v8; // edi
	int v9;       // eax

	v1 = *(uint32_t*)(a1 + 748);
	v2 = *(uint32_t*)(v1 + 296);
	if (v2 && !*(uint32_t*)(v1 + 8)) {
		v3 = *(uint32_t*)(v1 + 364);
		v4 = *(uint32_t*)(v1 + 4 * v3 + 300);
		v5 = *(float*)(v4 + 8) - *(float*)(a1 + 56);
		v6 = *(float*)(v4 + 12) - *(float*)(a1 + 60);
		if (v6 * v6 + v5 * v5 < 64.0) {
			if (v3 == v2 - 1) {
				*(uint32_t*)(v1 + 296) = 0;
				return 1;
			}
			*(uint32_t*)(v1 + 364) = v3 + 1;
			v4 = *(uint32_t*)(v1 + 4 * (v3 + 1) + 300);
		}
		v8 = (uint32_t*)(v4 + 8);
		nox_xxx_creatureSetDetailedPath_50D220(a1, v4 + 8);
		if (!*(uint8_t*)(v1 + 284)) {
			v9 = *(uint32_t*)(v1 + 8);
			*(uint32_t*)(v1 + 8 * v9 + 4) = *v8;
			*(uint32_t*)(v1 + 8 * v9 + 8) = v8[1];
		}
	}
	return nox_xxx_creatureActuallyMove_50D3B0((float*)a1) && *(uint8_t*)(v1 + 284) == 2;
}

//----- (0050D3B0) --------------------------------------------------------
int nox_xxx_creatureActuallyMove_50D3B0(float* a1) {
	int v1;     // esi
	int v2;     // ebp
	float v3;   // edx
	int v4;     // edi
	float* v5;  // ebx
	double v6;  // st7
	double v7;  // st6
	double v8;  // st5
	float* v10; // edi
	double v11; // st7
	double v12; // st7
	short v13;  // ax
	int v14;    // eax
	double v15; // st7
	float* v16; // [esp+10h] [ebp-2Ch]
	float v17;  // [esp+14h] [ebp-28h]
	float* v18; // [esp+18h] [ebp-24h]
	int v19;    // [esp+1Ch] [ebp-20h]
	float v20;  // [esp+1Ch] [ebp-20h]
	float v21;  // [esp+20h] [ebp-1Ch]
	float2 v22; // [esp+24h] [ebp-18h]
	float4 v23; // [esp+2Ch] [ebp-10h]
	float v24;  // [esp+40h] [ebp+4h]

	v1 = *((uint32_t*)a1 + 187);
	v2 = 0;
	if (*(uint32_t*)(v1 + 8)) {
		v3 = a1[15];
		v23.field_0 = a1[14];
		v23.field_4 = v3;
		v4 = *(uint32_t*)(v1 + 268);
		v16 = 0;
		v18 = 0;
		v19 = 0;
		v17 = 10000000.0;
		if (v4 >= *(int*)(v1 + 8)) {
		LABEL_14:
			*(uint32_t*)(v1 + 8) = 0;
			return 0;
		}
		v5 = (float*)(v1 + 8 * v4 + 12);
		do {
			v23.field_8 = *v5;
			v23.field_C = v5[1];
			if (nox_xxx_mapTraceRay_535250(&v23, 0, 0, 132)) {
				v6 = v23.field_8 - a1[14];
				v7 = v23.field_C - a1[15];
				v8 = v7 * v7 + v6 * v6;
				if (v8 > 64.0) {
					if (!v16 || v17 > v8) {
						v17 = v8;
						v16 = v5;
						v2 = v4;
					}
				} else {
					if (v4 == *(uint32_t*)(v1 + 8) - 1) {
						*(uint32_t*)(v1 + 8) = 0;
						return 1;
					}
					v18 = v5;
					v19 = v4;
				}
			}
			++v4;
			v5 += 2;
		} while (v4 < *(int*)(v1 + 8));
		if (!v16) {
			if (!v18) {
				goto LABEL_14;
			}
			v2 = v19;
		}
		v10 = a1;
		*getMemU32Ptr(0x5D4594, 2386204) = v2;
		*(uint32_t*)(v1 + 268) = v2;
		v20 = *(float*)(v1 + 8 * v2 + 12) - a1[14];
		v11 = *(float*)(v1 + 8 * v2 + 16) - a1[15];
		v21 = v11;
		v24 = sqrt(v11 * v21 + v20 * v20) + *getMemDoublePtr(0x581450, 10288);
		if (v2 <= 0) {
			v22.field_0 = *(float*)(v1 + 20) - *(float*)(v1 + 12);
			v12 = *(float*)(v1 + 24) - *(float*)(v1 + 16);
		} else {
			v22.field_0 = *(float*)(v1 + 8 * v2 + 12) - *(float*)(v1 + 8 * v2 + 4);
			v12 = *(float*)(v1 + 8 * v2 + 16) - *(float*)(v1 + 8 * v2 + 8);
		}
		v22.field_4 = v12;
		v13 = nox_xxx_math_509ED0(&v22);
		*((uint16_t*)v10 + 62) = v13;
		*((uint16_t*)v10 + 63) = v13;
		v14 = *(uint32_t*)(v1 + 1440);
		if (v14 & 0x4000) {
			v15 = *(float*)(*(uint32_t*)(v1 + 484) + 96) * v10[136];
		} else {
			v15 = v10[136];
		}
		v10[22] = v15 * v20 / v24;
		v10[23] = v15 * v21 / v24;
	}
	return 0;
}

//----- (0050D5A0) --------------------------------------------------------
int nox_xxx_creatureSetMovePath_50D5A0(int a1) {
	int v1;     // esi
	double v2;  // st7
	float* v3;  // edi
	double v4;  // st6
	float v6;   // edx
	char v7;    // al
	bool v8;    // zf
	int v9;     // eax
	double v10; // st7
	double v11; // st6
	double v12; // st7
	double v13; // st6
	float4 v14; // [esp+Ch] [ebp-10h]

	v1 = *(uint32_t*)(a1 + 748);
	v2 = *(float*)(v1 + 24 * *(char*)(v1 + 544) + 556) - *(float*)(a1 + 56);
	v3 = (float*)(v1 + 24 * *(char*)(v1 + 544) + 556);
	v4 = *(float*)(v1 + 24 * *(char*)(v1 + 544) + 560) - *(float*)(a1 + 60);
	if (sqrt(v4 * v4 + v2 * v2) + *getMemDoublePtr(0x581450, 10288) <= 8.0) {
		return 1;
	}
	v6 = *(float*)(a1 + 60);
	v14.field_0 = *(float*)(a1 + 56);
	v14.field_4 = v6;
	v14.field_8 = *v3;
	v7 = (*(uint32_t*)(a1 + 16) >> 12) & 4;
	v14.field_C = v3[1];
	v8 = nox_xxx_mapTraceRay_535250(&v14, 0, 0, v7) == 0;
	v9 = *(uint32_t*)(v1 + 8);
	if (v8) {
		if (!v9) {
			if (!*(uint32_t*)(v1 + 296) || (unsigned int)(gameFrame() - *(uint32_t*)(v1 + 280)) > 0xA &&
											   (v12 = *(float*)(v1 + 368) - *v3, v13 = *(float*)(v1 + 372) - v3[1],
												v13 * v13 + v12 * v12 > 10000.0)) {
				sub_50D2A0(a1, (int)v3);
			}
			if (*(uint32_t*)(v1 + 296)) {
			LABEL_16:
				if (sub_50D2E0(a1)) {
					*(uint32_t*)(v1 + 8) = 0;
					*(uint32_t*)(v1 + 296) = 0;
					return 1;
				}
				return 0;
			}
			nox_ai_debug_printf_5341A0(" ** Waypoint path failed, doing detailed path\n");
			nox_xxx_creatureSetDetailedPath_50D220(a1, (int)v3);
		}
	} else if (!v9 || (unsigned int)(gameFrame() - *(uint32_t*)(v1 + 280)) > 0xA &&
						  (v10 = *(float*)(v1 + 272) - *v3, v11 = *(float*)(v1 + 276) - v3[1],
						   v11 * v11 + v10 * v10 > 2500.0)) {
		nox_xxx_creatureSetDetailedPath_50D220(a1, (int)v3);
	}
	if (*(uint32_t*)(v1 + 296)) {
		goto LABEL_16;
	}
	if (*(uint32_t*)(v1 + 8) && nox_xxx_creatureActuallyMove_50D3B0((float*)a1)) {
		*(uint32_t*)(v1 + 8) = 0;
		return 1;
	}
	return 0;
}

//----- (0050D780) --------------------------------------------------------
int nox_xxx_allocMonsterRelatedArrays_50D780() {
	int result; // eax

	result = nox_new_alloc_class("SpawnClass", 12, 96);
	nox_alloc_spawn_2386216 = result;
	if (result) {
		dword_5d4594_2386212 = 0;
		result = nox_new_alloc_class("MonsterListClass", 148, 96);
		nox_alloc_monsterList_2386220 = result;
		if (result) {
			dword_5d4594_2386224 = 0;
			dword_5d4594_2386228 = 0;
			result = 1;
		}
	}
	return result;
}

//----- (0050D7E0) --------------------------------------------------------
void sub_50D7E0() {
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_spawn_2386216);
	dword_5d4594_2386212 = 0;
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_monsterList_2386220);
	dword_5d4594_2386224 = 0;
	dword_5d4594_2386228 = 0;
}

//----- (0050D820) --------------------------------------------------------
void sub_50D820() {
	nox_free_alloc_class(*(void**)&nox_alloc_spawn_2386216);
	nox_alloc_spawn_2386216 = 0;
	dword_5d4594_2386212 = 0;
	nox_free_alloc_class(*(void**)&nox_alloc_monsterList_2386220);
	nox_alloc_monsterList_2386220 = 0;
	dword_5d4594_2386224 = 0;
	dword_5d4594_2386228 = 0;
}

//----- (0050D8D0) --------------------------------------------------------
void sub_50D8D0() {
	int* v0; // edi
	int* v1; // ebp
	int v2;  // ebx
	int v3;  // esi
	int v4;  // eax

	v0 = *(int**)&dword_5d4594_2386212;
	if (dword_5d4594_2386212) {
		do {
			v1 = (int*)v0[1];
			v2 = 1;
			v3 = nox_xxx_getFirstPlayerUnit_4DA7C0();
			if (!v3) {
				goto LABEL_13;
			}
			do {
				v4 = *(uint32_t*)(v3 + 748);
				if (*(uint32_t*)(*(uint32_t*)(v4 + 276) + 4792) == 1 && !*(uint32_t*)(v4 + 312) &&
					nox_xxx_calcDistance_4E6C00(v3, *v0) < 700.0) {
					v2 = 0;
				}
				v3 = nox_xxx_getNextPlayerUnit_4DA7F0(v3);
			} while (v3);
			if (v2 == 1) {
			LABEL_13:
				nox_xxx_delayedDeleteObject_4E5CC0(*v0);
			}
			v0 = v1;
		} while (v1);
	}
}

//----- (0050D960) --------------------------------------------------------
int sub_50D960() {
	int v0;             // ebx
	int v1;             // edi
	int v2;             // eax
	int* v3;            // ebp
	int v4;             // ecx
	uint32_t* v5;       // esi
	uint32_t* v6;       // eax
	int v7;             // eax
	int i;              // edx
	double v9;          // st7
	int v10;            // edi
	float* v11;         // ecx
	int v12;            // esi
	int j;              // edx
	int k;              // ecx
	int v15;            // ebx
	int v16;            // eax
	int v17;            // eax
	int v18;            // eax
	int v19;            // esi
	int v20;            // edi
	int v21;            // eax
	int v22;            // esi
	int v23;            // ebp
	int v24;            // edx
	unsigned char* v25; // eax
	int* v26;           // esi
	int* v27;           // ebx
	char v28;           // cl
	unsigned char* v29; // eax
	int v30;            // eax
	int v31;            // eax
	int v32;            // eax
	float v34;          // [esp+0h] [ebp-40h]
	int v35;            // [esp+14h] [ebp-2Ch]
	int v36;            // [esp+18h] [ebp-28h]
	int v37;            // [esp+18h] [ebp-28h]
	float4 a2;          // [esp+20h] [ebp-20h]
	float4 v39;         // [esp+30h] [ebp-10h]

	v34 = nox_xxx_gamedataGetFloat_419D40("MaxOnscreenMonsterCount");
	v35 = nox_float2int(v34);
	v36 = 0;
	memset(getMemAt(0x5D4594, 2386232), 0, 0x80u);
	v0 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (v0) {
		do {
			v1 = *(uint32_t*)(v0 + 748);
			*getMemU32Ptr(0x5D4594, 2386232 + 4 * *(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064)) = 0;
			v2 = *(uint32_t*)(v1 + 276);
			if (*(uint32_t*)(v2 + 4792)) {
				v3 = *(int**)&dword_5d4594_2386212;
				a2.field_0 = *(float*)(v0 + 56) - (double)*(unsigned short*)(v2 + 10) - 100.0;
				a2.field_4 = *(float*)(v0 + 60) - (double)*(unsigned short*)(*(uint32_t*)(v1 + 276) + 12) - 100.0;
				a2.field_8 = (double)*(unsigned short*)(*(uint32_t*)(v1 + 276) + 10) + *(float*)(v0 + 56) + 100.0;
				a2.field_C = (double)*(unsigned short*)(*(uint32_t*)(v1 + 276) + 12) + *(float*)(v0 + 60) + 100.0;
				if (dword_5d4594_2386212) {
					do {
						if (sub_428220((float2*)(*v3 + 56), &a2)) {
							v39.field_0 = *(float*)(v0 + 56);
							v39.field_4 = *(float*)(v0 + 60);
							v4 = *v3;
							v39.field_8 = *(float*)(*v3 + 56);
							v39.field_C = *(float*)(v4 + 60);
							if (nox_xxx_mapTraceRay_535250(&v39, 0, 0, 69)) {
								v5 = sub_50DE60(*v3);
								if (!v5) {
									v6 = nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_monsterList_2386220);
									v5 = v6;
									if (!v6) {
										break;
									}
									v6[35] = dword_5d4594_2386224;
									if (dword_5d4594_2386224) {
										*(uint32_t*)(dword_5d4594_2386224 + 144) = v6;
									}
									dword_5d4594_2386224 = v6;
									++dword_5d4594_2386228;
									*v6 = *v3;
								}
								v5[2] |= 1 << *(uint8_t*)(*(uint32_t*)(v1 + 276) + 2064);
								v7 = *(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064);
								++*getMemU32Ptr(0x5D4594, 2386232 + 4 * v7);
								if (*getMemU32Ptr(0x5D4594, 2386232 + 4 * *(unsigned char*)(*(uint32_t*)(v1 + 276) +
																							2064)) > v35) {
									v36 = 1;
								}
								*(float*)&v5[*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064) + 3] =
									nox_xxx_calcDistance_4E6C00(*v3, v0);
							}
						}
						v3 = (int*)v3[1];
					} while (v3);
				}
			}
			v0 = nox_xxx_getNextPlayerUnit_4DA7F0(v0);
		} while (v0);
		if (v36) {
			for (i = dword_5d4594_2386224; i; i = *(uint32_t*)(i + 140)) {
				v9 = 0.0;
				v10 = 0;
				v11 = (float*)(i + 12);
				v12 = 32;
				do {
					if (*v11 != 0.0) {
						v9 = v9 + *v11;
						++v10;
					}
					++v11;
					--v12;
				} while (v12);
				*(float*)(i + 4) = v9 / (double)v10;
			}
			for (j = dword_5d4594_2386224; j; j = *(uint32_t*)(j + 140)) {
				for (k = *(uint32_t*)(j + 140); k; k = *(uint32_t*)(k + 140)) {
					if (*(float*)(k + 4) > (double)*(float*)(j + 4)) {
						v15 = *(uint32_t*)(j + 140);
						if (v15 == k) {
							v16 = *(uint32_t*)(j + 144);
							*(uint32_t*)(k + 144) = v16;
							if (v16) {
								*(uint32_t*)(v16 + 140) = k;
							}
							v17 = *(uint32_t*)(k + 140);
							*(uint32_t*)(j + 140) = v17;
							if (v17) {
								*(uint32_t*)(v17 + 144) = j;
							}
							*(uint32_t*)(j + 144) = k;
							*(uint32_t*)(k + 140) = j;
						} else {
							v18 = *(uint32_t*)(j + 144);
							v19 = *(uint32_t*)(k + 140);
							v20 = *(uint32_t*)(k + 144);
							if (v18) {
								*(uint32_t*)(v18 + 140) = k;
							}
							if (v20) {
								*(uint32_t*)(v20 + 140) = j;
							}
							if (v15) {
								*(uint32_t*)(v15 + 144) = k;
							}
							if (v19) {
								*(uint32_t*)(v19 + 144) = j;
							}
							*(uint32_t*)(j + 144) = v20;
							*(uint32_t*)(j + 140) = v19;
							*(uint32_t*)(k + 144) = v18;
							*(uint32_t*)(k + 140) = v15;
						}
						if (j == dword_5d4594_2386224) {
							dword_5d4594_2386224 = k;
						}
						v21 = k;
						k = j;
						j = v21;
					}
				}
			}
			while (1) {
				v22 = 0;
				v23 = 0;
				v24 = 0;
				v25 = getMemAt(0x5D4594, 2386232);
				do {
					if (*(uint32_t*)v25 > v22) {
						v22 = *(uint32_t*)v25;
						v23 = v24;
					}
					v25 += 4;
					++v24;
				} while ((int)v25 < (int)getMemAt(0x5D4594, 2386360));
				if (v22 <= v35) {
					break;
				}
				v26 = *(int**)&dword_5d4594_2386224;
				v37 = 1;
				if (dword_5d4594_2386224) {
					do {
						if (v37 != 1) {
							break;
						}
						v27 = (int*)v26[35];
						if (v26[2] & (1 << v23)) {
							nox_xxx_delayedDeleteObject_4E5CC0(*v26);
							v28 = 0;
							v29 = getMemAt(0x5D4594, 2386232);
							do {
								if ((1 << v28) & v26[2]) {
									--*(uint32_t*)v29;
								}
								v29 += 4;
								++v28;
							} while ((int)v29 < (int)getMemAt(0x5D4594, 2386360));
							v30 = v26[35];
							if (v30) {
								*(uint32_t*)(v30 + 144) = v26[36];
							}
							v31 = v26[36];
							if (v31) {
								*(uint32_t*)(v31 + 140) = v26[35];
							} else {
								dword_5d4594_2386224 = v26[35];
							}
							nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_monsterList_2386220, v26);
							v32 = *getMemU32Ptr(0x5D4594, 2386232 + 4 * v23);
							--dword_5d4594_2386228;
							if (v32 <= v35) {
								v37 = 0;
							}
						}
						v26 = v27;
					} while (v27);
				}
			}
		}
	}
	return sub_50DE10();
}

//----- (0050DE10) --------------------------------------------------------
int sub_50DE10() {
	int result; // eax
	int v1;     // esi

	result = dword_5d4594_2386224;
	if (dword_5d4594_2386224) {
		do {
			v1 = *(uint32_t*)(result + 140);
			nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_monsterList_2386220, (uint64_t*)result);
			result = v1;
			--dword_5d4594_2386228;
		} while (v1);
		dword_5d4594_2386224 = 0;
	} else {
		dword_5d4594_2386224 = 0;
	}
	return result;
}

//----- (0050DE60) --------------------------------------------------------
uint32_t* sub_50DE60(int a1) {
	uint32_t* result; // eax

	result = *(uint32_t**)&dword_5d4594_2386224;
	if (!dword_5d4594_2386224) {
		return 0;
	}
	while (*result != a1) {
		result = (uint32_t*)result[35];
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (0050DE80) --------------------------------------------------------
int sub_50DE80(int a1, float* a2) {
	int v2;     // edi
	int v3;     // esi
	int v4;     // eax
	int v5;     // ecx
	float v7;   // [esp+0h] [ebp-20h]
	float4 a2a; // [esp+10h] [ebp-10h]

	v7 = nox_xxx_gamedataGetFloat_419D40("MaxOnscreenMonsterCount");
	v2 = nox_float2int(v7);
	v3 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (!v3) {
		return 1;
	}
	while (1) {
		v4 = *(uint32_t*)(v3 + 748);
		v5 = *(uint32_t*)(v4 + 276);
		if (*(uint32_t*)(v5 + 4792)) {
			a2a.field_0 = *(float*)(v3 + 56) - (double)*(unsigned short*)(v5 + 10) - 100.0;
			a2a.field_4 = *(float*)(v3 + 60) - (double)*(unsigned short*)(*(uint32_t*)(v4 + 276) + 12) - 100.0;
			a2a.field_8 = (double)*(unsigned short*)(*(uint32_t*)(v4 + 276) + 10) + *(float*)(v3 + 56) + 100.0;
			a2a.field_C = (double)*(unsigned short*)(*(uint32_t*)(v4 + 276) + 12) + *(float*)(v3 + 60) + 100.0;
			if (sub_428220((float2*)a2, &a2a)) {
				*getMemU32Ptr(0x5D4594, 2386208) = 0;
				nox_xxx_getUnitsInRect_517C10(&a2a, sub_50DFB0, v3);
				if (*getMemU32Ptr(0x5D4594, 2386208) >= v2) {
					break;
				}
			}
		}
		v3 = nox_xxx_getNextPlayerUnit_4DA7F0(v3);
		if (!v3) {
			return 1;
		}
	}
	return 0;
}

//----- (0050DFB0) --------------------------------------------------------
void sub_50DFB0(float* a1, int a2) {
	float v2;  // ecx
	float v3;  // eax
	float v4;  // ecx
	float4 v5; // [esp+4h] [ebp-10h]

	if ((uint8_t)a1[2] & 2 && !((uint32_t)a1[4] & 0x20) &&
		(((uint32_t)a1[4] & 0x8000) != 0x8000 || nox_xxx_unitIsZombie_534A40((int)a1))) {
		v2 = *(float*)(a2 + 56);
		v3 = a1[14];
		v5.field_4 = *(float*)(a2 + 60);
		v5.field_0 = v2;
		v4 = a1[15];
		v5.field_8 = v3;
		v5.field_C = v4;
		if (nox_xxx_mapTraceRay_535250(&v5, 0, 0, 69) == 1) {
			++*getMemU32Ptr(0x5D4594, 2386208);
		}
	}
}

//----- (0050E030) --------------------------------------------------------
int sub_50E030(int a1, uint32_t* a2) {
	int v2;        // ebp
	uint32_t* v3;  // esi
	int result;    // eax
	uint32_t* v5;  // edi
	int v6;        // eax
	uint32_t* v7;  // eax
	int v8;        // ecx
	int* v9;       // edx
	uint32_t* v10; // edi
	int v11;       // esi
	int v12;       // ebp
	uint32_t* v13; // edx
	int v14;       // esi

	v2 = *(uint32_t*)(a1 + 748);
	v3 = (uint32_t*)a2[187];
	if (!v3[549]) {
		result = nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_spawn_2386216);
		v5 = (uint32_t*)result;
		if (!result) {
			return result;
		}
		sub_50E110(result);
		*v5 = a2;
		++*(uint8_t*)(v2 + 86);
		v3[549] = v5;
		v3[548] = a1;
		v6 = a2[3];
		if (v6 & 0x2000) {
			v7 = nox_xxx_newObjectByTypeID_4E3810("Glyph");
			if (v7) {
				v8 = v7[173];
				v9 = v3 + 511;
				v10 = (uint32_t*)v7[173];
				v11 = 3;
				do {
					v12 = *v9;
					++v9;
					*v10 = v12;
					++v10;
					--v11;
				} while (v11);
				*(uint32_t*)(v8 + 24) = 0;
				*(uint32_t*)(v8 + 28) = a2[14];
				*(uint32_t*)(v8 + 32) = a2[15];
				*(uint8_t*)(v8 + 20) = 0;
				v13 = (uint32_t*)v8;
				v14 = 3;
				do {
					if (*v13) {
						++*(uint8_t*)(v8 + 20);
					}
					++v13;
					--v14;
				} while (v14);
			}
			nox_xxx_inventoryPutImpl_4F3070((int)a2, (int)v7, 1);
		}
	}
	return 1;
}

//----- (0050E110) --------------------------------------------------------
int sub_50E110(int a1) {
	int result; // eax

	result = a1;
	*(uint32_t*)(a1 + 8) = 0;
	*(uint32_t*)(a1 + 4) = dword_5d4594_2386212;
	if (dword_5d4594_2386212) {
		*(uint32_t*)(dword_5d4594_2386212 + 8) = a1;
	}
	dword_5d4594_2386212 = a1;
	return result;
}

//----- (0050E140) --------------------------------------------------------
void sub_50E140(int a1) {
	int v1; // esi
	int v2; // eax

	if (a1) {
		v1 = *(uint32_t*)(a1 + 748);
		v2 = *(uint32_t*)(v1 + 2192);
		if (v2) {
			--*(uint8_t*)(*(uint32_t*)(v2 + 748) + 86);
			*(uint32_t*)(v1 + 2192) = 0;
		}
		if (*(uint32_t*)(v1 + 2196)) {
			sub_50E1B0(*(uint32_t*)(v1 + 2196));
			nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_spawn_2386216, *(uint64_t**)(v1 + 2196));
			*(uint32_t*)(v1 + 2196) = 0;
		}
	}
}

//----- (0050E1B0) --------------------------------------------------------
int sub_50E1B0(int a1) {
	int result; // eax
	int v2;     // ecx
	int v3;     // ecx

	result = a1;
	v2 = *(uint32_t*)(a1 + 4);
	if (v2) {
		*(uint32_t*)(v2 + 8) = *(uint32_t*)(a1 + 8);
	}
	v3 = *(uint32_t*)(a1 + 8);
	if (v3) {
		result = *(uint32_t*)(a1 + 4);
		*(uint32_t*)(v3 + 4) = result;
	} else {
		dword_5d4594_2386212 = *(uint32_t*)(a1 + 4);
	}
	return result;
}

//----- (0050E1E0) --------------------------------------------------------
void sub_50E1E0(int object) {
	if (object) {
		if (!nox_xxx_unitIsZombie_534A40(object)) {
			sub_50E140(object);
		}
	}
}

//----- (0050E210) --------------------------------------------------------
void sub_50E210(nox_object_t* a1p) {
	int a1 = a1p;
	int v1; // esi
	int v2; // eax
	int v3; // esi
	int v4; // edi

	v1 = *(uint32_t*)(a1 + 748);
	if (!*getMemU32Ptr(0x5D4594, 2386360)) {
		*getMemU32Ptr(0x5D4594, 2386360) = nox_xxx_getNameId_4E3AA0("Glyph");
	}
	if (*(uint8_t*)(a1 + 8) & 2) {
		v2 = *(uint32_t*)(a1 + 12);
		if (v2 & 0x2000) {
			if (*(uint32_t*)(v1 + 2196)) {
				v3 = nox_xxx_inventoryGetFirst_4E7980(a1);
				if (v3) {
					do {
						v4 = nox_xxx_inventoryGetNext_4E7990(v3);
						if (*(unsigned short*)(v3 + 4) == *getMemU32Ptr(0x5D4594, 2386360)) {
							nox_xxx_delayedDeleteObject_4E5CC0(v3);
						}
						v3 = v4;
					} while (v4);
				}
			}
		}
	}
	sub_50E140(a1);
}

//----- (0050E2A0) --------------------------------------------------------
int nox_xxx_registerShopClasses_50E2A0() {
	int result; // eax

	result = nox_new_alloc_class("TradeSessions", 64, 64);
	nox_alloc_tradeSession_2386492 = result;
	if (result) {
		nox_alloc_tradeItems_2386496 = nox_new_alloc_class("TradeItems", 16, 500);
		if (nox_alloc_tradeItems_2386496) {
			memset(getMemAt(0x5D4594, 2386364), 0, 0x80u);
			dword_5d4594_2386500 = 0;
			result = 1;
		} else {
			nox_xxx_deleteShopInventories_50E300();
			result = 0;
		}
	}
	return result;
}

//----- (0050E300) --------------------------------------------------------
int nox_xxx_deleteShopInventories_50E300() {
	int result; // eax

	if (nox_alloc_tradeSession_2386492) {
		nox_free_alloc_class(*(void**)&nox_alloc_tradeSession_2386492);
	}
	nox_alloc_tradeSession_2386492 = 0;
	if (nox_alloc_tradeItems_2386496) {
		nox_free_alloc_class(*(void**)&nox_alloc_tradeItems_2386496);
	}
	result = 0;
	memset(getMemAt(0x5D4594, 2386364), 0, 0x80u);
	nox_alloc_tradeItems_2386496 = 0;
	dword_5d4594_2386500 = 0;
	return result;
}

//----- (0050E360) --------------------------------------------------------
int sub_50E360() {
	uint32_t* v0; // edi
	int* i;       // esi
	int result;   // eax

	v0 = *(uint32_t**)&dword_5d4594_2386500;
	if (dword_5d4594_2386500) {
		do {
			if (v0[4]) {
				for (i = (int*)v0[5]; i; i = (int*)i[2]) {
					nox_xxx_objectFreeMem_4E38A0(*i);
				}
				v0[5] = 0;
			}
			v0 = (uint32_t*)v0[14];
		} while (v0);
	}
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_tradeSession_2386492);
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_tradeItems_2386496);
	result = 0;
	memset(getMemAt(0x5D4594, 2386364), 0, 0x80u);
	dword_5d4594_2386500 = 0;
	return result;
}

//----- (0050E3D0) --------------------------------------------------------
int nox_objectTypeGetWorth(char* a1);
int nox_xxx_shopGetItemCost_50E3D0(int a1, int a2, float a3) {
	float v3;            // ebp
	int v4;              // edi
	int v5;              // ebx
	int v6;              // eax
	int v7;              // eax
	int v8;              // eax
	double v9;           // st7
	int v11;             // esi
	int v12;             // edi
	double v13;          // st7
	int v14;             // eax
	uint8_t* v15;        // esi
	double v16;          // st7
	int v17;             // eax
	double v18;          // st7
	int v19;             // ecx
	int v20;             // ecx
	unsigned short* v21; // ecx
	double v22;          // st7
	int v23;             // eax
	double v24;          // st7
	float v26;           // [esp+0h] [ebp-20h]
	int v27;             // [esp+14h] [ebp-Ch]
	float v28;           // [esp+18h] [ebp-8h]
	int v29;             // [esp+28h] [ebp+8h]
	float v30;           // [esp+28h] [ebp+8h]
	float v31;           // [esp+2Ch] [ebp+Ch]

	v3 = a3;
	v4 = 0;
	v27 = 0;
	v31 = (double)*(unsigned int*)(LODWORD(a3) + 32);
	if (!*getMemU32Ptr(0x5D4594, 2386504)) {
		*getMemU32Ptr(0x5D4594, 2386504) = nox_xxx_getNameId_4E3AA0("Diamond");
		*getMemU32Ptr(0x5D4594, 2386508) = nox_xxx_getNameId_4E3AA0("Ruby");
		*getMemU32Ptr(0x5D4594, 2386512) = nox_xxx_getNameId_4E3AA0("Emerald");
	}
	v5 = a2;
	if (a2 && *(uint32_t*)(a2 + 16)) {
		v6 = *(uint32_t*)(a2 + 8);
		if (*(uint8_t*)(v6 + 8) & 4) {
			v6 = *(uint32_t*)(a2 + 12);
		}
		v27 = *(uint32_t*)(v6 + 692);
		v4 = *(uint32_t*)(v6 + 692);
	}
	v7 = *(uint32_t*)(LODWORD(v3) + 8);
	if (v7 & 0x100) {
		v8 = *(uint32_t*)(LODWORD(v3) + 12);
		if (v8 & 1) {
			v9 = (double)(unsigned short)nox_xxx_spellPrice_424C40(**(uint8_t**)(LODWORD(v3) + 736));
		LABEL_16:
			v31 = v9;
			goto LABEL_17;
		}
		if (v8 & 2) {
			int worth = nox_objectTypeGetWorth(*(char**)(LODWORD(v3) + 736));
			if (worth >= 0) {
				v31 = (double)worth;
			}
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				v9 = nox_xxx_gamedataGetFloat_419D40("QuestGuideWorthMultiplier") * v31;
				goto LABEL_16;
			}
		}
	}
LABEL_17:
	if (*(uint32_t*)(LODWORD(v3) + 8) & 0x13001000) {
		v11 = *(uint32_t*)(LODWORD(v3) + 692);
		v12 = 4;
		do {
			if (*(uint32_t*)v11) {
				*(float*)&v29 = (double)*(int*)(*(uint32_t*)v11 + 20);
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					v13 = nox_xxx_gamedataGetFloat_419D40("QuestModifierWorthMultiplier") * *(float*)&v29;
				} else {
					v13 = *(float*)&v29;
				}
				v31 = v13 + v31;
			}
			v11 += 4;
			--v12;
		} while (v12);
		v4 = v27;
	}
	v14 = *(uint32_t*)(LODWORD(v3) + 8);
	v30 = v31;
	if (v14 & 0x1000000 && *(uint8_t*)(LODWORD(v3) + 12) & 0x82) {
		v15 = *(uint8_t**)(LODWORD(v3) + 736);
		if (!v15[2] && *v15) {
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				v16 = nox_xxx_gamedataGetFloat_419D40("DefaultAmmoAmountQuest");
			} else {
				v16 = nox_xxx_gamedataGetFloat_419D40("DefaultAmmoAmount");
			}
			v26 = v16;
			v17 = nox_float2int(v26);
			v18 = (double)v17;
			v19 = (unsigned char)v15[1];
			if (v19 > v17) {
				v28 = v31 / v18;
				v31 = (double)(v19 - v17) * v28 + v31;
			} else {
				v31 = (double)(unsigned char)v15[1] / v18 * v31;
			}
		}
	} else if (v14 & 0x1000) {
		if (*(uint32_t*)(LODWORD(v3) + 12) & 0x47F0000) {
			v20 = *(uint32_t*)(LODWORD(v3) + 736);
			if (*(uint8_t*)(v20 + 109)) {
				v4 = v27;
				v31 = (double)*(unsigned char*)(v20 + 108) / (double)*(unsigned char*)(v20 + 109) * v31;
			}
		}
	}
	if (v4 && v5 && *(uint32_t*)(v5 + 16) && a1) {
		v31 = v31 * *(float*)(v4 + 1716);
		v30 = v30 * *(float*)(v4 + 1716);
	}
	v21 = *(unsigned short**)(LODWORD(v3) + 556);
	if (v21 && v21[2]) {
		v31 = (double)*v21 / (double)v21[2] * v31;
	}
	if (v4 && !a1) {
		v22 = nox_common_gameFlags_check_40A5C0(4096) ? nox_xxx_gamedataGetFloat_419D40("QuestSellMultiplier")
													  : *(float*)(v4 + 1720);
		v23 = *(unsigned short*)(LODWORD(v3) + 4);
		if ((unsigned short)v23 != *getMemU32Ptr(0x5D4594, 2386504) && v23 != *getMemU32Ptr(0x5D4594, 2386512) &&
			v23 != *getMemU32Ptr(0x5D4594, 2386508)) {
			v31 = v22 * v31;
			v30 = v22 * v30;
		}
	}
	if (nox_common_gameFlags_check_40A5C0(4096) && !a1 && *(uint32_t*)(LODWORD(v3) + 8) & 0x3001000 &&
		*(uint8_t*)(*(uint32_t*)(LODWORD(v3) + 748) + 4) & 1) {
		v30 = 0.0;
	} else if (v31 >= 1.0) {
		goto LABEL_64;
	}
	v31 = 1.0;
LABEL_64:
	if (v30 < 1.0) {
		v30 = 1.0;
	}
	if (a1 == 2) {
		v24 = nox_xxx_gamedataGetFloat_419D40("RepairCoefficient") * (v30 - v31);
		v31 = v24;
		if (v24 < 1.0) {
			v31 = 1.0;
		}
	}
	return nox_float2int(v31);
}

//----- (0050E820) --------------------------------------------------------
int sub_50E820(int a1, int a2) {
	int v3; // ecx
	int v5; // [esp+0h] [ebp-4h]

	HIWORD(v5) = *(uint16_t*)(a2 + 36);
	v3 = *(uint32_t*)(a1 + 748);
	LOWORD(v5) = 2505;
	return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), (int)&v5, 4, 0, 1);
}

//----- (0050E870) --------------------------------------------------------
uint32_t* nox_xxx_createShopStruct_50E870() {
	uint32_t* v0; // eax
	uint32_t* v1; // esi

	v0 = nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_tradeSession_2386492);
	v1 = v0;
	if (!v0) {
		return 0;
	}
	v0[2] = 0;
	v0[3] = 0;
	v0[6] = 0;
	v0[7] = 0;
	v0[8] = 0;
	v0[9] = 0;
	v0[10] = 0;
	v0[11] = 0;
	v0[5] = 0;
	v0[12] = nox_xxx_newObjectByTypeID_4E3810("Gold");
	v1[13] = nox_xxx_newObjectByTypeID_4E3810("Gold");
	v1[15] = 0;
	v1[14] = dword_5d4594_2386500;
	if (dword_5d4594_2386500) {
		*(uint32_t*)(dword_5d4594_2386500 + 60) = v1;
	}
	dword_5d4594_2386500 = v1;
	return v1;
}

//----- (0050E970) --------------------------------------------------------
void nox_xxx_loadShopItems_50E970(int a1) {
	int v1;                // edi
	int v2;                // eax
	int v3;                // esi
	unsigned int v4;       // esi
	uint32_t* v5;          // eax
	char** v6;             // eax
	unsigned char* v7;     // esi
	uint32_t* v8;          // eax
	int v9;                // ecx
	uint32_t* v10;         // eax
	int v11;               // edi
	uint32_t* v12;         // ebx
	int v13;               // eax
	unsigned int v14;      // esi
	uint32_t* v15;         // eax
	uint32_t* v16;         // eax
	uint32_t* v17;         // eax
	uint32_t* v18;         // eax
	uint32_t* v19;         // eax
	uint32_t* v20;         // eax
	uint32_t* v21;         // eax
	uint32_t* v22;         // eax
	uint32_t* v23;         // eax
	uint32_t* v24;         // eax
	uint32_t* v25;         // eax
	uint32_t* v26;         // eax
	uint32_t* v27;         // eax
	uint32_t* v28;         // eax
	uint32_t* v29;         // eax
	uint32_t* v30;         // eax
	uint32_t* v31;         // eax
	uint32_t* v32;         // eax
	uint8_t* v33;          // esi
	unsigned char* v34;    // ebp
	uint32_t* v35;         // eax
	int v36;               // ebx
	int v37;               // eax
	int v38;               // edx
	int v39;               // eax
	float v40;             // [esp+0h] [ebp-38h]
	int v41;               // [esp+14h] [ebp-24h]
	int v42;               // [esp+18h] [ebp-20h]
	uint8_t* v43;          // [esp+20h] [ebp-18h]
	unsigned char v44[20]; // [esp+24h] [ebp-14h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 8);
	if (v2 && *(uint8_t*)(v2 + 8) & 2 && *(uint8_t*)(v2 + 12) & 8 ||
		(v2 = *(uint32_t*)(a1 + 12)) != 0 && *(uint8_t*)(v2 + 8) & 2 && *(uint8_t*)(v2 + 12) & 8) {
		v3 = v2;
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			v40 = nox_xxx_gamedataGetFloat_419D40("ShopAnkhCutoffStage");
			v4 = nox_float2int(v40);
			if (nox_game_getQuestStage_4E3CC0() < v4) {
				v5 = nox_xxx_newObjectByTypeID_4E3810("AnkhTradable");
				if (v5) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v5);
				}
			}
			if (*getMemU32Ptr(0x587000, 234816)) {
				v6 = (char**)getMemAt(0x587000, 234816);
				v7 = getMemAt(0x587000, 234816);
				do {
					v8 = nox_xxx_newObjectByTypeID_4E3810(*v6);
					if (v8) {
						nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v8);
					}
					v9 = *((uint32_t*)v7 + 1);
					v7 += 4;
					v6 = (char**)v7;
				} while (v9);
			}
			v10 = nox_xxx_newObjectByTypeID_4E3810("RewardMarker");
			v11 = (int)v10;
			if (v10) {
				v12 = (uint32_t*)v10[173];
				v13 = nox_game_getQuestStage_4E3CC0();
				*v12 = 8;
				v14 = v13 + 2;
				v15 = nox_server_rewardgen_activateMarker_4F0720(v11, v13 + 2);
				if (v15) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v15);
				}
				*v12 = 8;
				v16 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v16) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v16);
				}
				*v12 = 8;
				v17 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v17) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v17);
				}
				*v12 = 8;
				v18 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v18) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v18);
				}
				*v12 = 16;
				v19 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v19) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v19);
				}
				*v12 = 16;
				v20 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v20) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v20);
				}
				*v12 = 16;
				v21 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v21) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v21);
				}
				*v12 = 16;
				v22 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v22) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v22);
				}
				*v12 = 1;
				v23 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v23) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v23);
				}
				*v12 = 1;
				v24 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v24) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v24);
				}
				*v12 = 1;
				v25 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v25) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v25);
				}
				*v12 = 1;
				v26 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v26) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v26);
				}
				*v12 = 1;
				v27 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v27) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v27);
				}
				*v12 = 1;
				v28 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v28) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v28);
				}
				*v12 = 4;
				v29 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v29) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v29);
				}
				*v12 = 4;
				v30 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v30) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v30);
				}
				*v12 = 4;
				v31 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v31) {
					nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v31);
				}
				if (nox_common_randomInt_415FA0(0, 100) > 90) {
					*v12 = 2;
					v32 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
					if (v32) {
						nox_xxx_addItemToShopSession_50EE00(a1, *(float*)&v32);
					}
				}
				nox_xxx_delayedDeleteObject_4E5CC0(v11);
			}
		} else {
			v33 = *(uint8_t**)(v3 + 692);
			v43 = v33;
			if (v33) {
				if (*v33) {
					v42 = 0;
					if (*v33) {
						v34 = v33 + 8;
						do {
							v41 = 0;
							if (*v34) {
								do {
									uint32_t v34p = *((uint32_t*)v34 - 1);
									v35 = nox_xxx_newObjectWithTypeInd_4E3450(v34p);
									v36 = (int)v35;
									if (v35) {
										if (v35[2] & 0x13001000) {
											v37 = *((uint32_t*)v34 + 2);
											v38 = *((uint32_t*)v34 + 4);
											*(uint32_t*)&v44[4] = *((uint32_t*)v34 + 3);
											*(uint32_t*)v44 = v37;
											v39 = *((uint32_t*)v34 + 5);
											*(uint32_t*)&v44[8] = v38;
											*(uint32_t*)&v44[12] = v39;
											nox_xxx_modifSetItemAttrs_4E4990(v36, (int*)v44);
										}
										if (*(int (**)(int*))(v36 + 704) == nox_xxx_XFerSpellReward_4F5F30) {
											**(uint8_t**)(v36 + 736) = v34[4];
										}
										if (*(int (**)(int*))(v36 + 704) == nox_xxx_XFerAbilityReward_4F6240) {
											**(uint8_t**)(v36 + 736) = v34[4];
										}
										if (*(int (**)(int*))(v36 + 704) == nox_xxx_XFerFieldGuide_4F6390) {
											strcpy(*(char**)(v36 + 736),
												   (const char*)nox_xxx_getUnitNameByThingType_4E3A80(
													   *((uint32_t*)v34 + 1)));
											v1 = a1;
											v33 = v43;
										}
										nox_xxx_addItemToShopSession_50EE00(v1, *(float*)&v36);
									}
									++v41;
								} while (v41 < *v34);
							}
							v34 += 28;
							++v42;
						} while (v42 < (unsigned char)*v33);
					}
				}
			}
		}
	}
}

//----- (0050EE00) --------------------------------------------------------
float* nox_xxx_addItemToShopSession_50EE00(int a1, float a2) {
	float* result;   // eax
	float* v3;       // esi
	unsigned int v4; // ebx
	int v5;          // edi
	uint32_t* i;     // eax
	int v7;          // eax

	result = (float*)nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_tradeItems_2386496);
	v3 = result;
	if (result) {
		*result = a2;
		*((uint32_t*)result + 1) = nox_xxx_shopGetItemCost_50E3D0(1, a1, a2);
		v4 = sub_50EEC0(v3);
		if (*(uint32_t*)(a1 + 20)) {
			if (v4 <= sub_50EEC0(*(uint32_t**)(a1 + 20))) {
				v3[3] = 0.0;
				v3[2] = *(float*)(a1 + 20);
				*(uint32_t*)(*(uint32_t*)(a1 + 20) + 12) = v3;
				*(uint32_t*)(a1 + 20) = v3;
				result = v3;
			} else {
				v5 = *(uint32_t*)(a1 + 20);
				for (i = *(uint32_t**)(v5 + 8); i; i = *(uint32_t**)(v5 + 8)) {
					if (v4 <= sub_50EEC0(i)) {
						break;
					}
					v5 = *(uint32_t*)(v5 + 8);
				}
				v3[2] = *(float*)(v5 + 8);
				v7 = *(uint32_t*)(v5 + 8);
				if (v7) {
					*(uint32_t*)(v7 + 12) = v3;
				}
				*(uint32_t*)(v5 + 8) = v3;
				*((uint32_t*)v3 + 3) = v5;
				result = v3;
			}
		} else {
			v3[2] = 0.0;
			v3[3] = 0.0;
			*(uint32_t*)(a1 + 20) = v3;
			result = v3;
		}
	}
	return result;
}

//----- (0050EEC0) --------------------------------------------------------
int sub_50EEC0(uint32_t* a1) {
	int v1;            // ecx
	int v2;            // eax
	unsigned char* v3; // edx

	v1 = 16781312;
	v2 = 255;
	v3 = getMemAt(0x581450, 10308);
	do {
		if (*(uint32_t*)(*a1 + 8) & v1 && (!*(uint32_t*)v3 || *(uint32_t*)v3 & *(uint32_t*)(*a1 + 12))) {
			break;
		}
		v1 = *((uint32_t*)v3 + 1);
		v3 += 8;
		--v2;
	} while (v1);
	return a1[1] | (v2 << 24);
}

//----- (0050F2B0) --------------------------------------------------------
int sub_50F2B0(int a1, uint32_t* a2) {
	int v2;             // eax
	int v3;             // ecx
	int v4;             // esi
	int v5;             // edx
	unsigned short* v6; // ecx
	int i;              // eax
	char v9[18];        // [esp+8h] [ebp-14h]

	v2 = *a2;
	v3 = a2[1];
	v4 = *(uint32_t*)(a1 + 748);
	v5 = *(uint32_t*)(*a2 + 692);
	v9[0] = -55;
	v9[1] = 8;
	*(uint16_t*)&v9[4] = *(uint16_t*)(v2 + 36);
	*(uint16_t*)&v9[2] = *(uint16_t*)(v2 + 4);
	*(uint32_t*)&v9[6] = v3;
	v6 = *(unsigned short**)(v2 + 556);
	if (v6) {
		*(uint32_t*)&v9[10] = *v6;
	} else {
		*(uint32_t*)&v9[10] = 0;
	}
	if (*(uint32_t*)(v2 + 8) & 0x13001000) {
		for (i = 0; i < 4; ++i) {
			if (*(uint32_t*)v5) {
				v9[i + 14] = *(uint8_t*)(*(uint32_t*)v5 + 4);
			} else {
				v9[i + 14] = -1;
			}
			v5 += 4;
		}
	} else {
		*(uint32_t*)&v9[14] = -1;
	}
	return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064), (int)v9, 18, 0, 1);
}

//----- (0050F3A0) --------------------------------------------------------
void sub_50F3A0(uint32_t* a1) {
	int* i; // edi
	int* j; // edi

	for (i = (int*)a1[8]; i; i = (int*)i[2]) {
		nox_xxx_inventoryPutImpl_4F3070(a1[2], *i, 1);
	}
	nox_xxx_playerAddGold_4FA590(a1[2], **(uint32_t**)(a1[12] + 692));
	sub_50F450(a1[2]);
	for (j = (int*)a1[9]; j; j = (int*)j[2]) {
		nox_xxx_inventoryPutImpl_4F3070(a1[3], *j, 1);
	}
	nox_xxx_playerAddGold_4FA590(a1[3], **(uint32_t**)(a1[13] + 692));
	sub_50F450(a1[3]);
	sub_50F490(a1, a1[2]);
	sub_50F490(a1, a1[3]);
	sub_510000((int)a1);
}

//----- (0050F450) --------------------------------------------------------
int sub_50F450(int a1) {
	int v2;     // edx
	char v4[2]; // [esp+0h] [ebp-2h]

	v2 = *(uint32_t*)(a1 + 748);
	*(uint16_t*)v4 = 457;
	return nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v4, 2, 0, 1);
}

//----- (0050F490) --------------------------------------------------------
int sub_50F490(uint32_t* a1, int a2) {
	int result; // eax

	result = a2;
	*a1 = 0;
	if (*(uint8_t*)(a2 + 8) & 4) {
		result = *(uint32_t*)(a2 + 748);
		if (*(uint32_t**)(result + 280) == a1) {
			*(uint32_t*)(result + 280) = 0;
		}
	}
	return result;
}

//----- (0050F4C0) --------------------------------------------------------
void nox_xxx_shopExit_50F4C0(uint32_t* a1) {
	int v1; // eax
	int v2; // eax
	int v3; // edi

	sub_50F490(a1, a1[2]);
	sub_50F490(a1, a1[3]);
	v1 = a1[2];
	if (*(uint8_t*)(v1 + 8) & 4) {
		nox_xxx_unitUnFreeze_4E7A60(v1, 0);
	} else {
		nox_xxx_unitUnFreeze_4E7A60(a1[3], 0);
	}
	v2 = a1[2];
	if (*(uint8_t*)(v2 + 8) & 4) {
		nox_xxx_sendEndTradeMsg_50F560(v2);
		v3 = a1[2];
	} else {
		nox_xxx_sendEndTradeMsg_50F560(a1[3]);
		v3 = a1[3];
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		*getMemU32Ptr(0x5D4594, 2386364 + 4 * *(unsigned char*)(*(uint32_t*)(*(uint32_t*)(v3 + 748) + 276) + 2064)) =
			a1;
	} else {
		sub_510000((int)a1);
	}
}

//----- (0050F560) --------------------------------------------------------
int nox_xxx_sendEndTradeMsg_50F560(int a1) {
	int v2;   // edx
	short v4; // [esp+0h] [ebp-2h]

	v2 = *(uint32_t*)(a1 + 748);
	v4 = 713;
	return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), (int)&v4, 2, 0, 1);
}

//----- (0050F5A0) --------------------------------------------------------
void nox_xxx_tradeAccept_50F5A0(int a1, int a2) {
	int v2; // eax
	int v3; // eax
	int v4; // ecx
	int v5; // eax
	int v6; // eax
	int v7; // [esp-34h] [ebp-3Ch]

	v2 = *(uint32_t*)(a1 + 8);
	if (v2 == a2) {
		*(uint32_t*)(a1 + 24) = 1;
	} else if (*(uint32_t*)(a1 + 12) == a2) {
		*(uint32_t*)(a1 + 28) = 1;
	}
	if (*(uint8_t*)(v2 + 8) & 4) {
		sub_50F720(v2, (uint32_t*)a1);
	}
	v3 = *(uint32_t*)(a1 + 12);
	if (*(uint8_t*)(v3 + 8) & 4) {
		sub_50F720(v3, (uint32_t*)a1);
	}
	if (*(uint32_t*)(a1 + 24) == 1 && *(uint32_t*)(a1 + 28) == 1) {
		sub_50F790(a1, *(uint32_t*)(a1 + 12), *(int**)(a1 + 32));
		sub_50F790(a1, *(uint32_t*)(a1 + 8), *(int**)(a1 + 36));
		sub_50F7F0(*(uint32_t*)(a1 + 12), *(uint32_t*)(a1 + 48));
		sub_50F7F0(*(uint32_t*)(a1 + 8), *(uint32_t*)(a1 + 52));
		sub_50F6B0(*(uint32_t*)(a1 + 32));
		v7 = *(uint32_t*)(a1 + 36);
		*(uint32_t*)(a1 + 32) = 0;
		sub_50F6B0(v7);
		v4 = *(uint32_t*)(a1 + 48);
		*(uint32_t*)(a1 + 36) = 0;
		**(uint32_t**)(v4 + 692) = 0;
		**(uint32_t**)(*(uint32_t*)(a1 + 52) + 692) = 0;
		v5 = *(uint32_t*)(a1 + 16);
		*(uint32_t*)(a1 + 40) = 0;
		*(uint32_t*)(a1 + 44) = 0;
		if (v5 == 1) {
			v6 = *(uint32_t*)(a1 + 8);
			if (*(uint8_t*)(v6 + 8) & 4) {
				sub_50F6E0(v6);
			} else {
				sub_50F6E0(*(uint32_t*)(a1 + 12));
			}
		} else {
			sub_50F3A0((uint32_t*)a1);
		}
	}
}

//----- (0050F6B0) --------------------------------------------------------
int sub_50F6B0(int a1) {
	int result; // eax
	int v2;     // esi

	result = a1;
	if (a1) {
		do {
			v2 = *(uint32_t*)(result + 8);
			nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_tradeItems_2386496, (uint64_t*)result);
			result = v2;
		} while (v2);
	}
	return result;
}

//----- (0050F6E0) --------------------------------------------------------
int sub_50F6E0(int a1) {
	int v2;   // edx
	short v4; // [esp+0h] [ebp-2h]

	v2 = *(uint32_t*)(a1 + 748);
	v4 = 1993;
	return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), (int)&v4, 2, 0, 1);
}

//----- (0050F720) --------------------------------------------------------
int sub_50F720(int a1, uint32_t* a2) {
	int v2;  // edx
	int v3;  // edi
	int v4;  // esi
	char v5; // al
	char v6; // al

	v2 = a1;
	v3 = a2[6];
	v4 = *(uint32_t*)(a1 + 748);
	v5 = 0;
	LOWORD(a1) = 969;
	BYTE2(a1) = 0;
	if (v3) {
		v5 = (a2[2] != v2) + 1;
		BYTE2(a1) = (a2[2] != v2) + 1;
	}
	if (a2[7]) {
		if (a2[3] == v2) {
			v6 = v5 | 1;
		} else {
			v6 = v5 | 2;
		}
		BYTE2(a1) = v6;
	}
	return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064), (int)&a1, 3, 0, 1);
}

//----- (0050F790) --------------------------------------------------------
void sub_50F790(int a1, int a2, int* a3) {
	int* i;    // esi
	float* v4; // eax
	int v5;    // ecx

	for (i = a3; i; i = (int*)i[2]) {
		if (*(uint8_t*)(a2 + 8) & 4) {
			nox_xxx_inventoryPutImpl_4F3070(a2, *i, 1);
		} else {
			v4 = nox_xxx_addItemToShopSession_50EE00(a1, *(float*)i);
			if (v4) {
				v5 = *(uint32_t*)(a1 + 8);
				if (*(uint8_t*)(v5 + 8) & 4) {
					sub_50F2B0(v5, v4);
				} else {
					sub_50F2B0(*(uint32_t*)(a1 + 12), v4);
				}
			}
		}
	}
}

//----- (0050F7F0) --------------------------------------------------------
uint32_t* sub_50F7F0(int a1, int a2) {
	uint32_t* result; // eax

	result = (uint32_t*)a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		result = nox_xxx_playerAddGold_4FA590(a1, **(uint32_t**)(a2 + 692));
	}
	return result;
}

//----- (0050FA00) --------------------------------------------------------
int nox_xxx_tradeP2PUpdStuff_50FA00(int a1, uint32_t* a2) {
	int v2;      // edx
	int v3;      // esi
	int v4;      // edx
	int v5;      // edx
	char v7[14]; // [esp+4h] [ebp-10h]

	v7[0] = -55;
	v2 = a2[2];
	v3 = *(uint32_t*)(a1 + 748);
	v7[1] = 6;
	if (v2 == a1) {
		v4 = a2[3];
		*(uint32_t*)&v7[2] = **(uint32_t**)(a2[12] + 692);
		if (*(uint8_t*)(v4 + 8) & 4) {
			v5 = a2[13];
			*(uint32_t*)&v7[6] = 0;
		} else {
			v5 = a2[13];
			*(uint32_t*)&v7[6] = a2[11] - a2[10];
		}
		*(uint32_t*)&v7[10] = **(uint32_t**)(v5 + 692);
	} else if (a2[3] == a1) {
		*(uint32_t*)&v7[2] = **(uint32_t**)(a2[13] + 692);
		if (*(uint8_t*)(v2 + 8) & 4) {
			*(uint32_t*)&v7[6] = 0;
		} else {
			*(uint32_t*)&v7[6] = a2[10] - a2[11];
		}
		*(uint32_t*)&v7[10] = **(uint32_t**)(a2[12] + 692);
	}
	return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), (int)v7, 14, 0, 1);
}

//----- (0050FB90) --------------------------------------------------------
uint32_t* sub_50FB90(uint32_t* a1) {
	int v1;           // ecx
	uint32_t* result; // eax
	int* v3;          // edi
	int v4;           // eax
	int* v5;          // edi
	int v6;           // eax
	int v7;           // ecx
	unsigned int v8;  // ecx
	unsigned int v9;  // edi
	unsigned int v10; // eax
	int v11;          // eax
	unsigned int v12; // edi
	unsigned int v13; // eax
	int v14;          // ecx

	v1 = a1[2];
	result = (uint32_t*)(*(uint32_t*)(v1 + 8) & 4);
	if (result != (uint32_t*)4 || (*(uint8_t*)(a1[3] + 8) & 4) != 4) {
		v3 = *(int**)(a1[12] + 692);
		if (result) {
			nox_xxx_playerAddGold_4FA590(v1, *v3);
		}
		*v3 = 0;
		v4 = a1[3];
		v5 = *(int**)(a1[13] + 692);
		if (*(uint8_t*)(v4 + 8) & 4) {
			nox_xxx_playerAddGold_4FA590(v4, *v5);
		}
		*v5 = 0;
		v6 = sub_50FD20(a1, a1[2]);
		v7 = a1[3];
		a1[10] = v6;
		result = (uint32_t*)sub_50FD20(a1, v7);
		v8 = a1[10];
		a1[11] = result;
		if ((unsigned int)result <= v8) {
			if ((unsigned int)result < v8) {
				v12 = v8 - (uint32_t)result;
				if (*(uint8_t*)(a1[3] + 8) & 4) {
					v13 = nox_xxx_playerGetGold_4FA6B0(a1[3]);
					if (v13 < v12) {
						a1[11] += v13;
						**(uint32_t**)(a1[13] + 692) += v13;
						result = nox_xxx_playerSubGold_4FA5D0(a1[3], v13);
					} else {
						v14 = a1[13];
						a1[11] += v12;
						**(uint32_t**)(v14 + 692) += v12;
						result = nox_xxx_playerSubGold_4FA5D0(a1[3], v12);
					}
				} else {
					a1[11] = v8;
					result = *(uint32_t**)(a1[13] + 692);
					*result += v12;
				}
			}
		} else {
			v9 = (unsigned int)result - v8;
			if (*(uint8_t*)(a1[2] + 8) & 4) {
				v10 = nox_xxx_playerGetGold_4FA6B0(a1[2]);
				if (v10 < v9) {
					a1[10] += v10;
					**(uint32_t**)(a1[12] + 692) += v10;
					result = nox_xxx_playerSubGold_4FA5D0(a1[2], v10);
				} else {
					a1[10] += v9;
					**(uint32_t**)(a1[12] + 692) += v9;
					result = nox_xxx_playerSubGold_4FA5D0(a1[2], v9);
				}
			} else {
				v11 = a1[12];
				a1[10] = v9 + v8;
				result = *(uint32_t**)(v11 + 692);
				*result += v9;
			}
		}
	}
	return result;
}

//----- (0050FD20) --------------------------------------------------------
int sub_50FD20(uint32_t* a1, int a2) {
	int v2;     // edx
	int v3;     // ecx
	int result; // eax
	int v5;     // edx

	if (a1[2] == a2) {
		v2 = a1[12];
		v3 = a1[8];
	} else {
		v2 = a1[13];
		v3 = a1[9];
	}
	for (result = **(uint32_t**)(v2 + 692); v3; result += v5) {
		v5 = *(uint32_t*)(v3 + 4);
		v3 = *(uint32_t*)(v3 + 8);
	}
	return result;
}

//----- (0050FE20) --------------------------------------------------------
int nox_xxx_tradeP2PAddOfferMB_50FE20(int a1, int a2) {
	int* v2;    // edi
	int v3;     // ebp
	int result; // eax
	float* v5;  // eax
	int v6;     // ecx
	int v7;     // eax
	int v8;     // eax
	int v9;     // eax
	int v10;    // eax

	v2 = sub_50FFE0(*(uint32_t**)(a1 + 32), a2);
	if (v2) {
		v3 = *(uint32_t*)(a1 + 8);
	} else {
		result = sub_50FFE0(*(uint32_t**)(a1 + 36), a2);
		v2 = (int*)result;
		if (!result) {
			return result;
		}
		v3 = *(uint32_t*)(a1 + 12);
	}
	if (*(uint8_t*)(v3 + 8) & 4) {
		nox_xxx_inventoryPutImpl_4F3070(v3, *v2, 1);
	} else {
		v5 = nox_xxx_addItemToShopSession_50EE00(a1, *(float*)v2);
		if (v5) {
			v6 = *(uint32_t*)(a1 + 8);
			if (!(*(uint8_t*)(v6 + 8) & 4)) {
				v6 = *(uint32_t*)(a1 + 12);
			}
			sub_50F2B0(v6, v5);
		}
	}
	v7 = v2[2];
	if (v7) {
		*(uint32_t*)(v7 + 12) = v2[3];
	}
	v8 = v2[3];
	if (v8) {
		*(uint32_t*)(v8 + 8) = v2[2];
	}
	if (*(uint32_t*)(a1 + 8) == v3) {
		if (*(int**)(a1 + 32) == v2) {
			*(uint32_t*)(a1 + 32) = v2[2];
		}
	} else if (*(int**)(a1 + 36) == v2) {
		*(uint32_t*)(a1 + 36) = v2[2];
	}
	sub_50FB90((uint32_t*)a1);
	*(uint32_t*)(a1 + 24) = 0;
	*(uint32_t*)(a1 + 28) = 0;
	v9 = *(uint32_t*)(a1 + 8);
	if (*(uint8_t*)(v9 + 8) & 4) {
		if (!(*(uint8_t*)(*(uint32_t*)(a1 + 12) + 8) & 4) && *(uint32_t*)(a1 + 44) <= *(int*)(a1 + 40)) {
			*(uint32_t*)(a1 + 28) = 1;
		}
	} else if (*(uint32_t*)(a1 + 40) <= *(int*)(a1 + 44)) {
		*(uint32_t*)(a1 + 24) = 1;
	}
	if (*(uint8_t*)(v9 + 8) & 4) {
		nox_xxx_tradeP2PUpdStuff_50FA00(v9, (uint32_t*)a1);
		sub_50FF90(*(uint32_t*)(a1 + 8), a1, *v2);
		sub_50F720(*(uint32_t*)(a1 + 8), (uint32_t*)a1);
	}
	v10 = *(uint32_t*)(a1 + 12);
	if (*(uint8_t*)(v10 + 8) & 4) {
		nox_xxx_tradeP2PUpdStuff_50FA00(v10, (uint32_t*)a1);
		sub_50FF90(*(uint32_t*)(a1 + 12), a1, *v2);
		sub_50F720(*(uint32_t*)(a1 + 12), (uint32_t*)a1);
	}
	nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_tradeItems_2386496, v2);
	return 1;
}

//----- (0050FF90) --------------------------------------------------------
int sub_50FF90(int a1, int a2, int a3) {
	int v4; // ecx
	int v6; // [esp+0h] [ebp-4h]

	HIWORD(v6) = *(uint16_t*)(a3 + 36);
	v4 = *(uint32_t*)(a1 + 748);
	LOWORD(v6) = 1481;
	return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064), (int)&v6, 4, 0, 1);
}

//----- (0050FFE0) --------------------------------------------------------
uint32_t* sub_50FFE0(uint32_t* a1, int a2) {
	uint32_t* result; // eax

	result = a1;
	if (!a1) {
		return 0;
	}
	while (*(uint32_t*)(*result + 36) != a2) {
		result = (uint32_t*)result[2];
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (00510000) --------------------------------------------------------
void sub_510000(int a1) {
	int* v1; // esi
	int* v2; // ebx
	int v3;  // eax
	int v4;  // eax

	v1 = *(int**)(a1 + 20);
	if (v1) {
		do {
			v2 = (int*)v1[2];
			nox_xxx_objectFreeMem_4E38A0(*v1);
			nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_tradeItems_2386496, v1);
			v1 = v2;
		} while (v2);
	}
	nox_xxx_objectFreeMem_4E38A0(*(uint32_t*)(a1 + 48));
	nox_xxx_objectFreeMem_4E38A0(*(uint32_t*)(a1 + 52));
	sub_50F6B0(*(uint32_t*)(a1 + 32));
	sub_50F6B0(*(uint32_t*)(a1 + 36));
	v3 = *(uint32_t*)(a1 + 56);
	if (v3) {
		*(uint32_t*)(v3 + 60) = *(uint32_t*)(a1 + 60);
	}
	v4 = *(uint32_t*)(a1 + 60);
	if (v4) {
		*(uint32_t*)(v4 + 56) = *(uint32_t*)(a1 + 56);
	}
	if (a1 == dword_5d4594_2386500) {
		dword_5d4594_2386500 = *(uint32_t*)(a1 + 56);
	}
	nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_tradeSession_2386492, (uint64_t*)a1);
}

//----- (005103A0) --------------------------------------------------------
int nox_xxx_getSomeShopData_5103A0(int a1, int a2) {
	int v2;      // eax
	uint8_t* v3; // edi
	int v4;      // esi
	int i;       // ebx

	v2 = *(uint32_t*)(a1 + 8);
	if (*(uint8_t*)(v2 + 8) & 4) {
		v2 = *(uint32_t*)(a1 + 12);
	}
	v3 = *(uint8_t**)(v2 + 692);
	v4 = 0;
	if (!*v3) {
		return -1;
	}
	for (i = (int)(v3 + 4); !sub_5103F0(a2, i); i += 28) {
		if (++v4 >= (unsigned char)*v3) {
			return -1;
		}
	}
	return v4;
}

//----- (005103F0) --------------------------------------------------------
int sub_5103F0(int a1, int a2) {
	int v2;       // ebp
	int v3;       // esi
	uint32_t* v4; // edx
	int v5;       // edx

	v2 = 0;
	if (!a1 || !a2) {
		return 0;
	}
	if (*(uint16_t*)(a1 + 4) == *(uint32_t*)a2) {
		v3 = *(uint32_t*)(a1 + 8);
		v2 = 1;
		if (v3 & 0x13001000) {
			v4 = *(uint32_t**)(a1 + 692);
			if (*(uint32_t*)(a2 + 12) != *v4) {
				v2 = 0;
			}
			if (*(uint32_t*)(a2 + 16) != v4[1]) {
				v2 = 0;
			}
			if (*(uint32_t*)(a2 + 20) != v4[2]) {
				v2 = 0;
			}
			if (*(uint32_t*)(a2 + 24) != v4[3]) {
				v2 = 0;
			}
		}
		if (v3 & 0x100) {
			v5 = *(uint32_t*)(a1 + 12);
			if (v5 & 1 || v5 & 4) {
				if (**(unsigned char**)(a1 + 736) != *(uint32_t*)(a2 + 8)) {
					return 0;
				}
			} else if (strcmp(*(const char**)(a1 + 736),
							  (const char*)nox_xxx_getUnitNameByThingType_4E3A80(*(uint32_t*)(a2 + 8)))) {
				v2 = 0;
			}
		}
	}
	return v2;
}

//----- (005108D0) --------------------------------------------------------
uint32_t* sub_5108D0(int a1, int a2, int a3) {
	int v3;           // edi
	uint32_t* result; // eax
	int v5;           // ebx
	int v6;           // ecx
	int v7;           // ecx
	unsigned char v8; // dl
	uint16_t* v9;     // ecx
	short v10;        // dx
	char v11[8];      // [esp+Ch] [ebp-8h]

	v3 = 0;
	result = *(uint32_t**)(a1 + 504);
	v5 = *(uint32_t*)(a1 + 748);
	v11[0] = -55;
	v11[1] = 31;
	*(uint16_t*)&v11[2] = a3;
	if (result) {
		while (result[9] != a3) {
			result = (uint32_t*)result[124];
			if (!result) {
				return result;
			}
		}
		v6 = result[2];
		if (v6 & 0x1000) {
			if (result[3] & 0x47F0000) {
				v7 = result[184];
				v8 = *(uint8_t*)(v7 + 109);
				if (*(uint8_t*)(v7 + 108) < v8) {
					if (v8) {
						v3 = 1;
					}
				}
			}
		}
		v9 = (uint16_t*)result[139];
		if (v9 && (v10 = v9[2], *v9 != v10) && v10 || v3) {
			*(uint32_t*)&v11[4] = nox_xxx_shopGetItemCost_50E3D0(2, a2, *(float*)&result);
			result = (uint32_t*)nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v5 + 276) + 2064), v11, 8,
															  0, 1);
		} else {
			nox_xxx_aud_501960(925, a1, 0, 0);
		}
	}
	return result;
}

//----- (00510AE0) --------------------------------------------------------
uint32_t* sub_510AE0(int* a1, int a2, uint32_t* a3) {
	uint32_t* result; // eax
	int v4;           // esi
	int v5;           // ebp
	unsigned int v6;  // eax
	int v7;           // eax
	int v8;           // ebx

	result = (uint32_t*)nox_xxx_playerGetGold_4FA6B0((int)a1);
	v4 = a1[126];
	v5 = a1[187];
	if (v4) {
		result = a3;
		while (*(uint32_t**)(v4 + 36) != a3) {
			v4 = *(uint32_t*)(v4 + 496);
			if (!v4) {
				return result;
			}
		}
		v6 = nox_xxx_shopGetItemCost_50E3D0(2, a2, *(float*)&v4);
		nox_xxx_playerSubGold_4FA5D0((int)a1, v6);
		nox_xxx_unitSetHP_4E4560(v4, *(uint16_t*)(*(uint32_t*)(v4 + 556) + 4));
		nox_xxx_itemReportHealth_4D87A0(*(unsigned char*)(*(uint32_t*)(v5 + 276) + 2064), (uint32_t*)v4);
		v7 = *(uint32_t*)(v4 + 8);
		if (v7 & 0x1000 && *(uint32_t*)(v4 + 12) & 0x47F0000) {
			v8 = *(uint32_t*)(v4 + 736);
			if (nox_xxx_rechargeItem_53C520(v4, 100)) {
				nox_xxx_netReportCharges_4D82B0(*(unsigned char*)(*(uint32_t*)(v5 + 276) + 2064), (uint32_t*)v4,
												*(uint8_t*)(v8 + 108), *(uint8_t*)(v8 + 109));
			}
		}
		sub_4D8870(*(unsigned char*)(*(uint32_t*)(v5 + 276) + 2064), (int)a1);
		nox_xxx_aud_501960(803, (int)a1, 2, a1[9]);
	}
	return result;
}

//----- (00510D10) --------------------------------------------------------
void sub_510D10(int* a1, int a2, int a3, unsigned int a4) {
	unsigned short result; // ax
	int v5;                // ebp
	int v6;                // ebx
	int v7;                // esi
	int v8;                // eax

	nox_xxx_playerGetGold_4FA6B0((int)a1);
	result = a4;
	v5 = a1[187];
	v6 = 0;
	if (a4) {
		while (1) {
			v7 = a1[126];
			if (!v7) {
				break;
			}
			while (1) {
				result = *(uint16_t*)(v7 + 4);
				if (result == a3) {
					break;
				}
				v7 = *(uint32_t*)(v7 + 496);
				if (!v7) {
					return;
				}
			}
			sub_4ED0C0((int)a1, (int*)v7);
			nox_xxx_delayedDeleteObject_4E5CC0(v7);
			v8 = nox_xxx_shopGetItemCost_50E3D0(0, a2, *(float*)&v7);
			nox_xxx_playerAddGold_4FA590((int)a1, v8);
			sub_4D8870(*(unsigned char*)(*(uint32_t*)(v5 + 276) + 2064), (int)a1);
			result = a4;
			if (++v6 >= a4) {
				nox_xxx_aud_501960(307, (int)a1, 2, a1[9]);
				return;
			}
		}
	}
}

//----- (00510DC0) --------------------------------------------------------
void nox_xxx_shopCancelSession_510DC0(uint32_t* a1) {
	if (a1[4]) {
		nox_xxx_shopExit_50F4C0(a1);
	} else {
		sub_50F3A0(a1);
	}
}

//----- (00510DE0) --------------------------------------------------------
int sub_510DE0(int a1, int a2) {
	int v2;       // eax
	uint32_t* v3; // eax

	v2 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 280);
	if (!v2) {
		return 0;
	}
	v3 = *(uint32_t**)(v2 + 20);
	if (!v3) {
		return 0;
	}
	while (*(uint32_t*)(*v3 + 36) != a2) {
		v3 = (uint32_t*)v3[2];
		if (!v3) {
			return 0;
		}
	}
	return *v3;
}

//----- (00510E20) --------------------------------------------------------
void sub_510E20(int a1) {
	if (*getMemU32Ptr(0x5D4594, 2386364 + 4 * a1)) {
		sub_510000(*getMemU32Ptr(0x5D4594, 2386364 + 4 * a1));
	}
	*getMemU32Ptr(0x5D4594, 2386364 + 4 * a1) = 0;
}

//----- (00510E50) --------------------------------------------------------
void sub_510E50() { dword_5d4594_2386564 = 0; }

//----- (00510E60) --------------------------------------------------------
signed int nox_xxx_updateSentryGlobe_510E60(int a1) {
	signed int result; // eax
	int v2;            // edi
	float v3;          // eax
	float v4;          // ecx
	float v5;          // eax
	float v6;          // ecx
	float2 a2;         // [esp+8h] [ebp-30h]
	int v8[2];         // [esp+10h] [ebp-28h]
	float4 a1a;        // [esp+18h] [ebp-20h]
	float4 v10;        // [esp+28h] [ebp-10h]

	result = *(uint32_t*)(a1 + 16);
	v2 = *(uint32_t*)(a1 + 748);
	if (result >= 0) {
		*(uint32_t*)(a1 + 500) = 0;
		*(uint32_t*)(a1 + 496) = dword_5d4594_2386564;
		if (dword_5d4594_2386564) {
			*(uint32_t*)(dword_5d4594_2386564 + 500) = a1;
		}
		dword_5d4594_2386564 = a1;
		result = *(uint32_t*)(a1 + 16) | 0x80000000;
		*(uint32_t*)(a1 + 16) = result;
	}
	if (*(uint8_t*)(a1 + 16) & 0x20) {
		result = (signed int)nox_xxx_sentryUpdateList_510FD0((uint32_t*)a1);
	}
	if (*(uint32_t*)(a1 + 16) & 0x1000000) {
		v3 = *(float*)(a1 + 60);
		a1a.field_0 = *(float*)(a1 + 56);
		a1a.field_4 = v3;
		a1a.field_8 = cos(*(float*)v2) * 600.0 + *(float*)(a1 + 56);
		a1a.field_C = sin(*(float*)v2) * 600.0 + *(float*)(a1 + 60);
		if (nox_xxx_mapTraceRay_535250(&a1a, &a2, 0, 5)) {
			v4 = a1a.field_C;
			*(float*)(a1 + 156) = a1a.field_8;
			*(float*)(a1 + 160) = v4;
		} else {
			v5 = a2.field_0;
			v6 = a2.field_4;
			*(float*)(a1 + 156) = a2.field_0;
			*(float*)(a1 + 160) = v6;
			a1a.field_8 = v5;
			a1a.field_C = v6;
		}
		*(float*)v2 = *(float*)(v2 + 8) + *(float*)v2;
		if (a1a.field_0 >= (double)a1a.field_8) {
			v10.field_8 = a1a.field_0;
			v10.field_0 = a1a.field_8;
		} else {
			v10.field_0 = a1a.field_0;
			v10.field_8 = a1a.field_8;
		}
		if (a1a.field_4 >= (double)a1a.field_C) {
			v10.field_C = a1a.field_4;
			v10.field_4 = a1a.field_C;
		} else {
			v10.field_4 = a1a.field_4;
			v10.field_C = a1a.field_C;
		}
		v8[0] = a1;
		v8[1] = (int)&a1a;
		nox_xxx_getUnitsInRect_517C10(&v10, nox_xxx_sentry_511020, (int)v8);
	} else {
		*(uint32_t*)v2 = *(uint32_t*)(v2 + 4);
	}
	return result;
}

//----- (00510FD0) --------------------------------------------------------
uint32_t* nox_xxx_sentryUpdateList_510FD0(uint32_t* a1) {
	uint32_t* result; // eax
	int v2;           // ecx
	int v3;           // ecx

	result = a1;
	if (a1[4] < 0) {
		v2 = a1[125];
		if (v2) {
			*(uint32_t*)(v2 + 496) = a1[124];
		} else {
			dword_5d4594_2386564 = a1[124];
		}
		v3 = a1[124];
		if (v3) {
			*(uint32_t*)(v3 + 500) = a1[125];
		}
	}
	a1[4] &= 0x7FFFFFFFu;
	return result;
}

//----- (00511020) --------------------------------------------------------
void nox_xxx_sentry_511020(int a1, int a2) {
	int v2; // eax
	double v3;
	int v6;    // eax
	int v7;    // [esp-Ch] [ebp-20h]
	float2 a3; // [esp+Ch] [ebp-8h]

	v2 = *(uint32_t*)(a1 + 16);
	if (!(v2 & 0x41) &&
		(!(v2 & 0x10) || nox_common_gameFlags_check_40A5C0(4096) && *(uint8_t*)(a1 + 8) & 2 &&
							 (*(uint32_t*)(a1 + 16) & 0x8000) != 0x8000) &&
		*(uint32_t*)(a1 + 556) && nox_xxx_mathPointOnTheLine_57C8A0(*(float4**)(a2 + 4), (float2*)(a1 + 56), &a3)) {
		v3 = *(float*)(a1 + 60) - a3.field_4;
		if (*(float*)(a1 + 176) * *(float*)(a1 + 176) >
			v3 * v3 + (*(float*)(a1 + 56) - a3.field_0) * (*(float*)(a1 + 56) - a3.field_0)) {
			v7 = *(uint32_t*)a2;
			v6 = nox_xxx_findParentChainPlayer_4EC580(*(uint32_t*)a2);
			(*(void (**)(int, int, int, int, int))(a1 + 716))(a1, v6, v7, 500, 16);
			nox_xxx_aud_501960(298, a1, 0, 0);
		}
	}
}

//----- (00511100) --------------------------------------------------------
void sub_511100(int a1) {
	int v1;    // edi
	char* v2;  // eax
	int v3;    // esi
	double v4; // st7
	double v5; // st7
	float v6;  // [esp+8h] [ebp-20h]
	float v7;  // [esp+Ch] [ebp-1Ch]
	float v8;  // [esp+14h] [ebp-14h]
	float v9;  // [esp+18h] [ebp-10h]
	float v10; // [esp+1Ch] [ebp-Ch]
	float v11; // [esp+20h] [ebp-8h]
	float i;   // [esp+24h] [ebp-4h]
	float v13; // [esp+2Ch] [ebp+4h]

	v1 = a1;
	v2 = nox_common_playerInfoFromNum_417090(a1);
	v3 = dword_5d4594_2386564;
	v4 = (double)*((unsigned short*)v2 + 5);
	v9 = *((float*)v2 + 908) - v4;
	v13 = (double)*((unsigned short*)v2 + 6);
	v10 = *((float*)v2 + 909) - v13;
	v11 = v4 + *((float*)v2 + 908);
	for (i = v13 + *((float*)v2 + 909); v3; v3 = *(uint32_t*)(v3 + 496)) {
		if (*(uint32_t*)(v3 + 16) & 0x1000000) {
			if (*(float*)(v3 + 56) >= (double)*(float*)(v3 + 156)) {
				v5 = *(float*)(v3 + 56);
				v6 = *(float*)(v3 + 156);
			} else {
				v5 = *(float*)(v3 + 156);
				v6 = *(float*)(v3 + 56);
			}
			if (*(float*)(v3 + 60) >= (double)*(float*)(v3 + 160)) {
				v8 = *(float*)(v3 + 60);
				v7 = *(float*)(v3 + 160);
			} else {
				v7 = *(float*)(v3 + 60);
				v8 = *(float*)(v3 + 160);
			}
			if (v9 < v5 && v11 > (double)v6 && v10 < (double)v8 && i > (double)v7) {
				sub_511250(v1, (float*)v3);
			}
		} else {
			**(uint32_t**)(v3 + 748) = *(uint32_t*)(*(uint32_t*)(v3 + 748) + 4);
		}
	}
}

//----- (00511250) --------------------------------------------------------
int sub_511250(int a1, float* a2) {
	short v2;   // ax
	float v3;   // ecx
	short v4;   // ax
	float v5;   // edx
	char v7[9]; // [esp+4h] [ebp-Ch]

	v7[0] = -107;
	v2 = sub_419A30(a2[14]);
	v3 = a2[15];
	*(uint16_t*)&v7[1] = v2;
	v4 = sub_419A30(v3);
	v5 = a2[39];
	*(uint16_t*)&v7[3] = v4;
	*(uint16_t*)&v7[5] = sub_419A30(v5);
	*(uint16_t*)&v7[7] = sub_419A30(a2[40]);
	return nox_netlist_addToMsgListCli_40EBC0(a1, 1, v7, 9);
}

//----- (00511660) --------------------------------------------------------
int nox_xxx_unitSetDecayTime_511660(nox_object_t* a1p, int a2) {
	uint32_t* a1 = a1p;
	int result;      // eax
	unsigned int v3; // edx
	int v4;          // ecx
	int v5;          // eax
	int v6;          // eax

	result = a1[4];
	if (!(result & 0x10000)) {
		if (result & 0x400000) {
			nox_xxx_decay_5116F0((int)a1);
		}
		v3 = gameFrame() + a2;
		v4 = 0;
		a1[34] = gameFrame() + a2;
		v5 = dword_5d4594_2386576;
		if (!dword_5d4594_2386576) {
			goto LABEL_14;
		}
		do {
			if (v3 < *(int*)(v5 + 136)) {
				break;
			}
			v4 = v5;
			v5 = *(uint32_t*)(v5 + 468);
		} while (v5);
		if (v4) {
			*(uint32_t*)(v4 + 468) = a1;
			if (!v5) {
				v6 = a1[4];
				a1[117] = 0;
				result = v6 | 0x400000;
				a1[4] = result;
				return result;
			}
		} else {
		LABEL_14:
			dword_5d4594_2386576 = a1;
		}
		a1[117] = v5;
		result = a1[4] | 0x400000;
		a1[4] = result;
	}
	return result;
}

//----- (005116F0) --------------------------------------------------------
int nox_xxx_decay_5116F0(nox_object_t* item) {
	int result; // eax
	int v2;     // ecx

	result = item->obj_flags;
	if (result & 0x400000) {
		v2 = 0;
		item->obj_flags = result & 0xFFBFFFFF;
		result = dword_5d4594_2386576;
		if (dword_5d4594_2386576) {
			while (result != item) {
				v2 = result;
				result = *(uint32_t*)(result + 468);
				if (!result) {
					return result;
				}
			}
			if (result) {
				if (v2) {
					result = *(uint32_t*)&item->field_117;
					*(uint32_t*)(v2 + 468) = result;
				} else {
					dword_5d4594_2386576 = *(uint32_t*)&item->field_117;
				}
			}
		}
	}
	return result;
}

//----- (00511750) --------------------------------------------------------
void nox_xxx_decay_511750() {
	uint32_t* v0; // esi
	uint32_t* v1; // edi
	int v2;       // edx

	v0 = *(uint32_t**)&dword_5d4594_2386576;
	if (dword_5d4594_2386576) {
		do {
			v1 = (uint32_t*)v0[117];
			if (v0[123]) {
				nox_xxx_decay_5116F0((int)v0);
			} else {
				if (v0[34] > gameFrame()) {
					return;
				}
				nox_xxx_decay_5116F0((int)v0);
				v2 = v0[5];
				LOBYTE(v2) = v2 | 0x80;
				v0[5] = v2;
				nox_xxx_delayedDeleteObject_4E5CC0((int)v0);
			}
			v0 = v1;
		} while (v1);
	}
}

//----- (005117B0) --------------------------------------------------------
int nox_xxx_decayDestroy_5117B0() {
	int result; // eax
	int v1;     // esi

	result = dword_5d4594_2386576;
	if (dword_5d4594_2386576) {
		do {
			v1 = *(uint32_t*)(result + 468);
			nox_xxx_decay_5116F0(result);
			result = v1;
		} while (v1);
		dword_5d4594_2386576 = 0;
	} else {
		dword_5d4594_2386576 = 0;
	}
	return result;
}

//----- (005117F0) --------------------------------------------------------
char sub_5117F0(nox_object_t* a1) {
	char result; // al

	result = a1;
	if (!(*(uint8_t*)((int)a1 + 8) & 1)) {
		result = nox_xxx_unitHasCollideOrUpdateFn_537610(a1);
	}
	return result;
}

//----- (00511810) --------------------------------------------------------
void nox_xxx_unit_511810(nox_object_t* a1) {
	if (!(*(uint8_t*)((int)a1 + 8) & 1)) {
		if (sub_537580(a1)) {
			sub_5375A0(a1);
		}
	}
}

//----- (005118A0) --------------------------------------------------------
int nox_xxx_updateObjectsVelocity_5118A0(float step) {
	int i;             // esi
	int result;        // eax
	int j;             // esi
	double v4;         // st7
	float v5;          // ecx
	float* v6;         // edi
	unsigned char* v7; // edx
	char v8;           // al
	int v9;            // eax
	double v10;        // st7
	double v11;        // st6
	float v12;         // [esp+8h] [ebp-24h]
	float v13;         // [esp+10h] [ebp-1Ch]
	float2 v15;        // [esp+14h] [ebp-18h]
	float4 v16;        // [esp+1Ch] [ebp-10h]

	if (!*getMemU32Ptr(0x5D4594, 2386580)) {
		*getMemU32Ptr(0x5D4594, 2386580) = nox_xxx_getNameId_4E3AA0("SmallFlameCleanse");
		*getMemU32Ptr(0x5D4594, 2386584) = nox_xxx_getNameId_4E3AA0("SmallFlameCleanse");
		*getMemU32Ptr(0x5D4594, 2386588) = nox_xxx_getNameId_4E3AA0("MediumFlameCleanse");
		*getMemU32Ptr(0x5D4594, 2386592) = nox_xxx_getNameId_4E3AA0("FlameCleanse");
		*getMemU32Ptr(0x5D4594, 2386596) = nox_xxx_getNameId_4E3AA0("LargeFlameCleanse");
		*getMemU32Ptr(0x5D4594, 2386600) = nox_xxx_getNameId_4E3AA0("SmallBlueFlameCleanse");
		*getMemU32Ptr(0x5D4594, 2386604) = nox_xxx_getNameId_4E3AA0("SmallBlueFlameCleanse");
		*getMemU32Ptr(0x5D4594, 2386608) = nox_xxx_getNameId_4E3AA0("MediumBlueFlameCleanse");
		*getMemU32Ptr(0x5D4594, 2386612) = nox_xxx_getNameId_4E3AA0("BlueFlameCleanse");
		*getMemU32Ptr(0x5D4594, 2386616) = nox_xxx_getNameId_4E3AA0("LargeBlueFlameCleanse");
	}
	for (i = sub_537740(); i; i = sub_537750(i)) {
		sub_5481C0(i);
	}
	nox_xxx_updateSprings_5113A0();
	result = sub_537740();
	for (j = result; result; j = result) {
		if (*(uint8_t*)(j + 16) & 2 || *(uint8_t*)(j + 8) & 2 && nox_xxx_checkMobAction_50A0D0(j, 67)) {
			*(uint32_t*)(j + 100) = 0;
			*(uint32_t*)(j + 96) = 0;
			*(uint32_t*)(j + 84) = 0;
			*(uint32_t*)(j + 80) = 0;
		} else {
			if (nox_xxx_testUnitBuffs_4FF350(j, 5) || nox_xxx_testUnitBuffs_4FF350(j, 25) ||
				nox_xxx_testUnitBuffs_4FF350(j, 28)) {
				v4 = *(float*)(j + 96);
				v13 = *(float*)(j + 100);
			} else {
				v4 = *(float*)(j + 96) + *(float*)(j + 88);
				v13 = *(float*)(j + 100) + *(float*)(j + 92);
			}
			v5 = *(float*)(j + 64);
			v6 = (float*)(j + 64);
			// update velocity
			*(float*)(j + 80) += (v4 - *(float*)(j + 80) * *(float*)(j + 112)) * step;
			*(float*)(j + 84) += (v13 - *(float*)(j + 84) * *(float*)(j + 112)) * step;
			v16.field_0 = v5;
			v16.field_4 = *(float*)(j + 68);
			v7 = getMemAt(0x5D4594, 2386580);
			// calc new pos
			v16.field_8 = step * *(float*)(j + 80) + *(float*)(j + 64);
			v16.field_C = step * *(float*)(j + 84) + *(float*)(j + 68);
			v8 = (*(uint32_t*)(j + 16) >> 12) & 4 | 1;
			while (*(unsigned short*)(j + 4) != *(uint32_t*)v7) {
				v7 += 4;
				if ((int)v7 >= (int)getMemAt(0x5D4594, 2386620)) {
					goto LABEL_20;
				}
			}
			v8 = (*(uint32_t*)(j + 16) >> 12) & 4 | 0x41;
		LABEL_20:
			if (nox_xxx_mapTraceRay_535250(&v16, 0, 0, v8)) {
				// sets new pos
				*(float*)(j + 64) = v16.field_8;
				*(float*)(j + 68) = v16.field_C;
			}
			v9 = *(uint32_t*)(j + 16);
			if (!(v9 & 0x4000) && *(uint32_t*)(j + 556) && nox_xxx_tileNFromPoint_411160((float2*)(j + 64)) == 6) {
				v15.field_0 = 0.0;
				v15.field_4 = 0.0;
				nox_xxx_collSysAddCollision_548630(j, 6u, &v15);
			}
			v10 = *v6 - *(float*)(j + 56);
			if (v10 < 0.0) {
				v10 = -v10;
			}
			v11 = *(float*)(j + 68) - *(float*)(j + 60);
			if (v11 < 0.0) {
				v11 = -v11;
			}
			if (v10 > 0.0099999998 || (v12 = v11, v12 > 0.0099999998)) {
				nox_xxx_unitNeedSync_4E44F0(j);
				nox_xxx_objectUnkUpdateCoords_4E7290(j);
				nox_xxx_moveUpdateSpecial_517970(j);
			}
		}
		result = sub_537750(j);
	}
	return result;
}

//----- (00511C50) --------------------------------------------------------
nox_object_t* nox_xxx_script_511C50(int a1) {
	uint32_t* v1; // esi

	if (dword_587000_237036) {
		sub_511D20();
	}
	v1 = *(uint32_t**)getMemAt(0x5D4594, 2386820);
	if (!*getMemU32Ptr(0x5D4594, 2386820)) {
		return 0;
	}
	while (*(uint8_t*)(*v1 + 16) & 0x20 || *(uint32_t*)(*v1 + 44) != a1) {
		v1 = (uint32_t*)v1[2];
		if (!v1) {
			return 0;
		}
	}
	sub_511CE0(getMemAt(0x5D4594, 2386820), (int)v1);
	sub_511CB0(getMemAt(0x5D4594, 2386820), (int)v1);
	return *v1;
}

//----- (00511CB0) --------------------------------------------------------
int sub_511CB0(uint32_t* a1, int a2) {
	int result; // eax

	result = a2;
	*(uint32_t*)(a2 + 4) = 0;
	*(uint32_t*)(a2 + 8) = *a1;
	if (*a1) {
		*(uint32_t*)(*a1 + 4) = a2;
	} else {
		a1[1] = a2;
	}
	*a1 = a2;
	return result;
}

//----- (00511CE0) --------------------------------------------------------
int sub_511CE0(uint32_t* a1, int a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // ecx

	result = a2;
	v3 = *(uint32_t*)(a2 + 8);
	if (v3) {
		*(uint32_t*)(v3 + 4) = *(uint32_t*)(a2 + 4);
	} else {
		a1[1] = *(uint32_t*)(a2 + 4);
	}
	v4 = *(uint32_t*)(a2 + 4);
	if (v4) {
		*(uint32_t*)(v4 + 8) = *(uint32_t*)(a2 + 8);
	} else {
		result = *(uint32_t*)(a2 + 8);
		*a1 = result;
	}
	return result;
}

//----- (00511D20) --------------------------------------------------------
int sub_511D20() {
	unsigned char* v0; // esi
	int result;        // eax

	v0 = getMemAt(0x5D4594, 2386628);
	*getMemU32Ptr(0x5D4594, 2386820) = 0;
	*getMemU32Ptr(0x5D4594, 2386824) = 0;
	*getMemU32Ptr(0x5D4594, 2386620) = 0;
	*getMemU32Ptr(0x5D4594, 2386624) = 0;
	do {
		result = sub_511CB0(getMemAt(0x5D4594, 2386620), (int)v0);
		v0 += 12;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 2386820));
	dword_587000_237036 = 0;
	return result;
}

//----- (00511D70) --------------------------------------------------------
int nox_xxx_scriptPrepareFoundUnit_511D70(nox_object_t* obj) {
	int a1 = obj;
	int* v1;    // eax
	int v2;     // esi
	int result; // eax
	int v4;     // [esp-8h] [ebp-8h]

	v1 = (int*)sub_511DC0();
	if (v1) {
		*v1 = a1;
		result = sub_511CB0(getMemAt(0x5D4594, 2386820), (int)v1);
	} else {
		v2 = *getMemU32Ptr(0x5D4594, 2386824);
		v4 = *getMemU32Ptr(0x5D4594, 2386824);
		**(uint32_t**)getMemAt(0x5D4594, 2386824) = a1;
		sub_511CE0(getMemAt(0x5D4594, 2386820), v4);
		result = sub_511CB0(getMemAt(0x5D4594, 2386820), v2);
	}
	return result;
}

//----- (00511DC0) --------------------------------------------------------
int sub_511DC0() {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 2386620);
	if (!*getMemU32Ptr(0x5D4594, 2386620)) {
		return 0;
	}
	*getMemU32Ptr(0x5D4594, 2386620) = *(uint32_t*)(*getMemU32Ptr(0x5D4594, 2386620) + 8);
	return result;
}

//----- (00511DE0) --------------------------------------------------------
int sub_511DE0(nox_object_t* a1) {
	int result;   // eax
	uint32_t* v2; // esi

	result = dword_587000_237036;
	if (!dword_587000_237036) {
		v2 = *(uint32_t**)getMemAt(0x5D4594, 2386820);
		if (*getMemU32Ptr(0x5D4594, 2386820)) {
			result = a1;
			while (*v2 != a1) {
				v2 = (uint32_t*)v2[2];
				if (!v2) {
					return result;
				}
			}
			sub_511CE0(getMemAt(0x5D4594, 2386820), (int)v2);
			result = sub_511CB0(getMemAt(0x5D4594, 2386620), (int)v2);
		}
	}
	return result;
}

//----- (00511E20) --------------------------------------------------------
int sub_511E20() {
	int result; // eax
	int v1;     // esi
	int v2;     // edi

	result = dword_587000_237036;
	if (!dword_587000_237036) {
		v1 = *getMemU32Ptr(0x5D4594, 2386820);
		if (*getMemU32Ptr(0x5D4594, 2386820)) {
			do {
				v2 = *(uint32_t*)(v1 + 8);
				sub_511CE0(getMemAt(0x5D4594, 2386820), v1);
				result = sub_511CB0(getMemAt(0x5D4594, 2386620), v1);
				v1 = v2;
			} while (v2);
		}
	}
	return result;
}

//----- (00511F80) --------------------------------------------------------
void nox_xxx_wallOpen_511F80(int a1) {
	int v1;    // edx
	int v2;    // ecx
	char v3;   // al
	int v4;    // eax
	char* v5;  // eax
	int v6;    // eax
	float2 v7; // [esp+0h] [ebp-8h]
	int v8;    // [esp+Ch] [ebp+4h]

	v1 = a1;
	if (*(uint8_t*)(a1 + 4) & 4) {
		v2 = *(uint32_t*)(a1 + 28);
		v3 = *(uint8_t*)(v2 + 21);
		if (v3 != 3 && v3 != 4) {
			v4 = *(uint32_t*)(v2 + 4);
			*(uint8_t*)(v2 + 21) = 4;
			v8 = 23 * *(uint32_t*)(v2 + 8);
			v7.field_0 = (double)(23 * v4) + 11.5;
			v7.field_4 = (double)v8 + 11.5;
			if (!nox_xxx_wallSounds_2386840) {
				v5 = nox_xxx_wallFindOpenSound_410EE0(*(unsigned char*)(v1 + 1));
				v6 = nox_xxx_utilFindSound_40AF50(v5);
				nox_xxx_audCreate_501A30(v6, &v7, 0, 0);
			}
		}
	}
}

//----- (00512070) --------------------------------------------------------
void nox_xxx_wallClose_512070(int a1) {
	int v1;    // edx
	int v2;    // ecx
	char v3;   // al
	int v4;    // eax
	char* v5;  // eax
	int v6;    // eax
	float2 v7; // [esp+0h] [ebp-8h]
	int v8;    // [esp+Ch] [ebp+4h]

	v1 = a1;
	if (*(uint8_t*)(a1 + 4) & 4) {
		v2 = *(uint32_t*)(a1 + 28);
		v3 = *(uint8_t*)(v2 + 21);
		if (v3 != 1 && v3 != 2) {
			v4 = *(uint32_t*)(v2 + 4);
			*(uint8_t*)(v2 + 21) = 2;
			v8 = 23 * *(uint32_t*)(v2 + 8);
			v7.field_0 = (double)(23 * v4) + 11.5;
			v7.field_4 = (double)v8 + 11.5;
			if (!nox_xxx_wallSounds_2386840) {
				v5 = nox_xxx_wallFindCloseSound_410F20(*(unsigned char*)(v1 + 1));
				v6 = nox_xxx_utilFindSound_40AF50(v5);
				nox_xxx_audCreate_501A30(v6, &v7, 0, 0);
			}
		}
	}
}

//----- (00512160) --------------------------------------------------------
void nox_xxx_wallToggle_512160(int a1) {
	int v1;    // eax
	char v2;   // cl
	int v3;    // ecx
	char* v4;  // eax
	int v5;    // ecx
	int v6;    // eax
	float2 v7; // [esp+4h] [ebp-8h]

	if (*(uint8_t*)(a1 + 4) & 4) {
		v1 = *(uint32_t*)(a1 + 28);
		v2 = *(uint8_t*)(v1 + 21);
		if (v2 == 1 || v2 == 2) {
			v5 = *(uint32_t*)(v1 + 4);
			*(uint8_t*)(v1 + 21) = 4;
			v7.field_0 = (double)(23 * v5) + 11.5;
			v7.field_4 = (double)(int)(23 * *(uint32_t*)(v1 + 8)) + 11.5;
			if (nox_xxx_wallSounds_2386840) {
				return;
			}
			v4 = nox_xxx_wallFindOpenSound_410EE0(*(unsigned char*)(a1 + 1));
		} else {
			v3 = *(uint32_t*)(v1 + 4);
			*(uint8_t*)(v1 + 21) = 2;
			v7.field_0 = (double)(23 * v3) + 11.5;
			v7.field_4 = (double)(int)(23 * *(uint32_t*)(v1 + 8)) + 11.5;
			if (nox_xxx_wallSounds_2386840) {
				return;
			}
			v4 = nox_xxx_wallFindCloseSound_410F20(*(unsigned char*)(a1 + 1));
		}
		v6 = nox_xxx_utilFindSound_40AF50(v4);
		nox_xxx_audCreate_501A30(v6, &v7, 0, 0);
	}
}

//----- (005122C0) --------------------------------------------------------
int nox_xxx_wallPreDestroyByPtr_5122C0(int a1) {
	int v1;  // edx
	int2 v3; // [esp+0h] [ebp-8h]

	v1 = *(unsigned char*)(a1 + 6);
	v3.field_0 = *(unsigned char*)(a1 + 5);
	v3.field_4 = v1;
	return nox_xxx_wallPreDestroy_534DA0(&v3);
}

//----- (005125A0) --------------------------------------------------------
float* nox_xxx_monsterLookAt_5125A0(nox_object_t* obj, int a2) {
	int a1 = obj;
	float* result; // eax
	int v3;        // edx
	float v4;      // [esp+0h] [ebp-8h]
	float v5;      // [esp+4h] [ebp-4h]

	result = (float*)nox_xxx_mathDirection4ToAngle_509E90(a2);
	if (*(uint8_t*)(a1 + 8) & 2) {
		v3 = *(uint32_t*)(a1 + 16);
		if ((v3 & 0x8000) == 0) {
			v4 = *getMemFloatPtr(0x587000, 194136 + 8 * (uint32_t)result) * 10.0 + *(float*)(a1 + 56);
			v5 = *getMemFloatPtr(0x587000, 194140 + 8 * (uint32_t)result) * 10.0 + *(float*)(a1 + 60);
			result = (float*)nox_xxx_monsterPushAction_50A260(a1, 25);
			if (result) {
				result[1] = v4;
				result[2] = v5;
			}
		}
	}
	return result;
}

//----- (00514110) --------------------------------------------------------
void nox_xxx_monsterWalkTo_514110(nox_object_t* obj, float x, float y) {
	int a1 = obj;
	int* result; // eax
	int* v4;     // eax

	result = *(int**)(a1 + 16);
	if (SBYTE1(result) >= 0 && *(uint8_t*)(a1 + 8) & 2) {
		nox_xxx_monsterClearActionStack_50A3A0(a1);
		v4 = nox_xxx_monsterPushAction_50A260(a1, 32);
		if (v4) {
			v4[1] = 8;
		}
		result = nox_xxx_monsterPushAction_50A260(a1, 8);
		if (result) {
			((float*)result)[1] = x;
			((float*)result)[2] = y;
			result[3] = 0;
		}
	}
}

//----- (00515680) --------------------------------------------------------
void nox_xxx_monsterGoPatrol_515680(int a1, int a2) {
	int v2;    // ebx
	int v3;    // eax
	int* v4;   // edi
	float2 v5; // [esp+8h] [ebp-8h]

	v2 = *(uint32_t*)(a1 + 748);
	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 2) {
			v3 = *(uint32_t*)(a1 + 16);
			if ((v3 & 0x8000) == 0) {
				v5.field_0 = *(float*)(a2 + 8) - *(float*)a2;
				v5.field_4 = *(float*)(a2 + 12) - *(float*)(a2 + 4);
				nox_xxx_monsterClearActionStack_50A3A0(a1);
				v4 = nox_xxx_monsterPushAction_50A260(a1, 4);
				if (v4) {
					v4[1] = *(uint32_t*)a2;
					v4[2] = *(uint32_t*)(a2 + 4);
					v4[3] = nox_xxx_math_509ED0(&v5);
				}
				*(uint32_t*)(v2 + 1312) = *(uint32_t*)(a2 + 16);
			}
		}
	}
}

//----- (005157A0) --------------------------------------------------------
void nox_xxx_unitHunt_5157A0(nox_object_t* obj) {
	int a1 = obj;
	int result; // eax

	if (a1 && *(uint8_t*)(a1 + 8) & 2) {
		result = *(int*)(a1 + 16);
		if (SBYTE1(result) >= 0) {
			nox_xxx_monsterClearActionStack_50A3A0(a1);
			nox_xxx_monsterPushAction_50A260(a1, 5);
		}
	}
}

//----- (00515820) --------------------------------------------------------
void nox_xxx_unitIdle_515820(nox_object_t* obj) {
	int a1 = obj;
	int result; // eax

	if (a1 && *(uint8_t*)(a1 + 8) & 2) {
		result = *(int*)(a1 + 16);
		if (SBYTE1(result) >= 0) {
			nox_xxx_monsterClearActionStack_50A3A0(a1);
			nox_xxx_monsterPushAction_50A260(a1, 0);
		}
	}
}

//----- (005158C0) --------------------------------------------------------
void nox_xxx_unitSetFollow_5158C0(nox_object_t* obj1, nox_object_t* obj2) {
	int a1 = obj1;
	int a2 = obj2;
	int v2;  // eax
	int* v3; // eax

	if (a1) {
		if (a2) {
			if (*(uint8_t*)(a1 + 8) & 2) {
				if (a1 != a2) {
					v2 = *(uint32_t*)(a1 + 16);
					if ((v2 & 0x8000) == 0) {
						nox_xxx_monsterClearActionStack_50A3A0(a1);
						v3 = nox_xxx_monsterPushAction_50A260(a1, 3);
						if (v3) {
							v3[1] = *(uint32_t*)(a2 + 56);
							v3[2] = *(uint32_t*)(a2 + 60);
							v3[3] = a2;
						}
					}
				}
			}
		}
	}
}

//----- (00515980) --------------------------------------------------------
int nox_xxx_monsterSetAgressiveness_515980(int a1, uint32_t* a2) {
	int result; // eax

	result = *(uint32_t*)(a1 + 748);
	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 2) {
			*(uint32_t*)(result + 1308) = *a2;
			*(uint32_t*)(result + 1304) = *a2;
		}
	}
	return result;
}

//----- (00515A30) --------------------------------------------------------
void nox_xxx_monsterActionMelee_515A30(int a1, float2* a2) {
	int v2;    // eax
	int* v3;   // eax
	float* v4; // edi
	float* v5; // eax

	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 2) {
			v2 = *(uint32_t*)(a1 + 16);
			if ((v2 & 0x8000) == 0) {
				if (nox_xxx_monsterCanMelee_534220(a1)) {
					nox_xxx_monsterClearActionStack_50A3A0(a1);
					v3 = nox_xxx_monsterPushAction_50A260(a1, 32);
					if (v3) {
						v3[1] = 16;
					}
					nox_xxx_monsterPushAction_50A260(a1, 16);
					v4 = (float*)nox_xxx_monsterPushAction_50A260(a1, 51);
					if (v4) {
						v4[1] = sub_534470(a1) + *(float*)(a1 + 176);
						v4[3] = a2->field_0;
						v4[4] = a2->field_4;
					}
					v5 = (float*)nox_xxx_monsterPushAction_50A260(a1, 7);
					if (v5) {
						v5[1] = a2->field_0;
						v5[2] = a2->field_4;
						v5[3] = 0;
					}
				}
			}
		}
	}
}

//----- (00515B80) --------------------------------------------------------
void nox_xxx_monsterMissileAttack_515B80(int a1, uint32_t* a2) {
	int v2;  // eax
	int* v3; // eax
	int* v4; // eax

	if (a1) {
		if (a2) {
			if (*(uint8_t*)(a1 + 8) & 2) {
				v2 = *(uint32_t*)(a1 + 16);
				if ((v2 & 0x8000) == 0) {
					if (nox_xxx_monsterCanShoot_534280(a1)) {
						nox_xxx_monsterClearActionStack_50A3A0(a1);
						v3 = nox_xxx_monsterPushAction_50A260(a1, 32);
						if (v3) {
							v3[1] = 17;
						}
						v4 = nox_xxx_monsterPushAction_50A260(a1, 17);
						if (v4) {
							v4[1] = *a2;
							v4[2] = a2[1];
							v4[3] = 0;
						}
					}
				}
			}
		}
	}
}

//----- (00515C80) --------------------------------------------------------
int sub_515C80(int a1, uint8_t* a2) {
	int result; // eax

	result = a1;
	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 2) {
			result = *(uint32_t*)(a1 + 748);
			*(uint8_t*)(result + 1332) = *a2;
		}
	}
	return result;
}

//----- (00515D30) --------------------------------------------------------
void nox_xxx_mobSetFightTarg_515D30(int a1, int a2) {
	int v2;  // ebx
	int v3;  // eax
	int* v4; // eax
	int* v5; // eax

	v2 = *(uint32_t*)(a1 + 748);
	if (a1) {
		if (a2) {
			if (*(uint8_t*)(a1 + 8) & 2) {
				if (a1 != a2) {
					v3 = *(uint32_t*)(a1 + 16);
					if ((v3 & 0x8000) == 0) {
						nox_xxx_monsterClearActionStack_50A3A0(a1);
						*(uint32_t*)(v2 + 1216) = a2;
						nox_xxx_frameCounterSetCopyToNextFrame_5281D0();
						v4 = nox_xxx_monsterPushAction_50A260(a1, 32);
						if (v4) {
							v4[1] = 15;
						}
						v5 = nox_xxx_monsterPushAction_50A260(a1, 15);
						if (v5) {
							v5[1] = *(uint32_t*)(a2 + 56);
							v5[2] = *(uint32_t*)(a2 + 60);
							v5[3] = gameFrame();
						}
					}
				}
			}
		}
	}
}

//----- (00515F70) --------------------------------------------------------
void nox_server_scriptFleeFrom_515F70(int a1, uint32_t* a2) {
	int v2;  // eax
	int* v3; // eax
	int* v4; // eax
	int* v5; // eax
	int v6;  // edx
	int v7;  // edx

	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 2) {
			v2 = *(uint32_t*)(a1 + 16);
			if ((v2 & 0x8000) == 0 && !nox_xxx_checkMobAction_50A0D0(a1, 24)) {
				v3 = nox_xxx_monsterPushAction_50A260(a1, 32);
				if (v3) {
					v3[1] = 24;
				}
				v4 = nox_xxx_monsterPushAction_50A260(a1, 41);
				if (v4) {
					v4[1] = gameFrame() + a2[1];
				}
				v5 = nox_xxx_monsterPushAction_50A260(a1, 24);
				if (v5) {
					v6 = *a2;
					v5[1] = *(uint32_t*)(*a2 + 56);
					v7 = *(uint32_t*)(v6 + 60);
					v5[3] = 0;
					v5[2] = v7;
				}
			}
		}
	}
}

//----- (00516090) --------------------------------------------------------
void sub_516090(int a1, uint32_t* a2) {
	int v2;  // eax
	int* v3; // eax
	int* v4; // eax

	if (a1) {
		if (a2) {
			if (*(uint8_t*)(a1 + 8) & 2) {
				v2 = *(uint32_t*)(a1 + 16);
				if ((v2 & 0x8000) == 0) {
					v3 = nox_xxx_monsterPushAction_50A260(a1, 32);
					if (v3) {
						v3[1] = 1;
					}
					v4 = nox_xxx_monsterPushAction_50A260(a1, 1);
					if (v4) {
						v4[1] = gameFrame() + *a2;
					}
				}
			}
		}
	}
}

//----- (00516570) --------------------------------------------------------
int sub_516570() {
	uint8_t* v2 = 0;
	int v1 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (v1) {
		do {
			v2 = *(uint8_t**)(*(uint32_t*)(v1 + 748) + 276);
			if (v2[2064] == 31) {
				break;
			}
			v1 = nox_xxx_getNextPlayerUnit_4DA7F0(v1);
		} while (v1);
	}
	nox_gameDisableMapDraw_5d4594_2650672 = 1;
	if (!v2) {
		return 0;
	}
	return nox_xxx_netSendChapterEnd_4D9560((unsigned char)v2[2064], getMemByte(0x5D4594, 2386828), *getMemIntPtr(0x5D4594, 2386832));
}

//----- (00516A80) --------------------------------------------------------
void sub_516A80(int a1, int a2, int a3, int a4) {
	int v4;       // eax
	uint32_t* v5; // eax
	int v6;       // ecx

	if (!*getMemU32Ptr(0x5D4594, 2386904)) {
		*getMemU32Ptr(0x5D4594, 2386904) = nox_xxx_getNameId_4E3AA0("Glyph");
	}
	v4 = nox_xxx_inventoryGetFirst_4E7980(a1);
	if (v4) {
		while (*(unsigned short*)(v4 + 4) != *getMemU32Ptr(0x5D4594, 2386904)) {
			v4 = nox_xxx_inventoryGetNext_4E7990(v4);
			if (!v4) {
				goto LABEL_8;
			}
		}
		nox_xxx_delayedDeleteObject_4E5CC0(v4);
	}
LABEL_8:
	v5 = nox_xxx_newObjectByTypeID_4E3810("Glyph");
	if (v5) {
		v6 = v5[173];
		*(uint32_t*)v6 = a2;
		*(uint32_t*)(v6 + 4) = a3;
		*(uint32_t*)(v6 + 8) = a4;
		*(uint8_t*)(v6 + 20) = 0;
		if (a2) {
			*(uint8_t*)(v6 + 20) = 1;
		}
		if (a3) {
			++*(uint8_t*)(v6 + 20);
		}
		if (a4) {
			++*(uint8_t*)(v6 + 20);
		}
		*(uint32_t*)(v6 + 24) = 0;
		*(uint32_t*)(v6 + 28) = *(uint32_t*)(a1 + 56);
		*(uint32_t*)(v6 + 32) = *(uint32_t*)(a1 + 60);
		nox_xxx_inventoryPutImpl_4F3070(a1, (int)v5, 1);
	}
}

//----- (00516D00) --------------------------------------------------------
unsigned int sub_516D00(nox_object_t* a1p) {
	int a1 = a1p;
	unsigned int result; // eax
	int v2;              // edx

	result = a1;
	if (a1 && *(uint8_t*)(a1 + 8) & 2) {
		v2 = *(uint32_t*)(a1 + 16);
		if ((v2 & 0x8000) != 0) {
			*(uint32_t*)(*(uint32_t*)(a1 + 748) + 1440) &= 0xFFEFFFFF;
			result = nox_xxx_mobRaiseZombie_534AB0(a1);
		}
	}
	return result;
}

//----- (00516EE0) --------------------------------------------------------
int nox_xxx_allocPendingOwnsArray_516EE0() {
	dword_5d4594_2386920 = 0;
	nox_alloc_pendingOwn_2386916 = nox_new_alloc_class("PendingOwn", 12, 512);
	return nox_alloc_pendingOwn_2386916 != 0;
}

//----- (00516F10) --------------------------------------------------------
int sub_516F10() {
	int result; // eax

	nox_free_alloc_class(*(void**)&nox_alloc_pendingOwn_2386916);
	result = 0;
	nox_alloc_pendingOwn_2386916 = 0;
	dword_5d4594_2386920 = 0;
	return result;
}

//----- (00516F30) --------------------------------------------------------
void sub_516F30() {
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_pendingOwn_2386916);
	dword_5d4594_2386920 = 0;
}

//----- (00516F90) --------------------------------------------------------
uint32_t* sub_516F90(int a1, int a2) {
	uint32_t* result; // eax

	result = nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_pendingOwn_2386916);
	if (result) {
		*result = a1;
		result[1] = a2;
		result[2] = dword_5d4594_2386920;
		dword_5d4594_2386920 = result;
	}
	return result;
}

//----- (00516FC0) --------------------------------------------------------
void sub_516FC0() {
	int* v0; // esi
	int v1;  // edi
	int v2;  // eax

	v0 = *(int**)&dword_5d4594_2386920;
	if (dword_5d4594_2386920) {
		do {
			v1 = sub_4ECF10(*v0);
			v2 = sub_4ECF10(v0[1]);
			if (v1 && v2) {
				nox_xxx_unitSetOwner_4EC290(v1, v2);
			}
			v0 = (int*)v0[2];
		} while (v0);
	}
	sub_516F30();
}

//----- (00517010) --------------------------------------------------------
int nox_xxx_loadMonsterBin_517010() {
	int result;   // eax
	FILE* v1;     // esi
	char v2[256]; // [esp+4h] [ebp-100h]

	dword_5d4594_2386924 = 0;
	result = nox_binfile_open_408CC0("monster.bin", 0);
	v1 = (FILE*)result;
	if (result) {
		result = nox_binfile_cryptSet_408D40(result, 23);
		if (result) {
			while (nox_xxx_readStr_517090(v1, v2) && nox_xxx_servParseMonsterDef_517170(v1, v2)) {
				;
			}
			nox_binfile_close_408D90(v1);
			result = 1;
		}
	}
	return result;
}

//----- (00517090) --------------------------------------------------------
int nox_xxx_readStr_517090(FILE* a1, uint8_t* a2) {
	uint8_t* v2;          // ebx
	int v3;               // ecx
	int v4;               // edi
	int v5;               // ebp
	int v6;               // eax
	uint16_t CharType[2]; // [esp+10h] [ebp-4h]

	v2 = a2;
	v3 = 0;
	*(uint32_t*)CharType = 0;
	v4 = 1;
	do {
		while (1) {
			v5 = v3;
			nox_binfile_fread_408E40((char*)CharType, 1, 1, a1);
			if (nox_binfile_lastErr_409370(a1) == -1) {
				return 0;
			}
			v3 = *(uint32_t*)CharType;
			v6 = isspace(CharType[0]);
			if (v6) {
				break;
			}
			v4 = 0;
			if (v3 != 47 || v5 != 47) {
				*v2++ = v3;
			} else {
				sub_517140(a1);
				v2 = a2;
				v3 = *(uint32_t*)CharType;
				v4 = 1;
			}
		}
	} while (v4);
	*v2 = 0;
	return 1;
}

//----- (00517140) --------------------------------------------------------
int sub_517140(FILE* a1) {
	FILE* v1;   // esi
	int result; // eax

	v1 = a1;
	do {
		LOBYTE(a1) = 0;
		nox_binfile_fread_408E40((char*)&a1, 1, 1, v1);
		result = nox_binfile_lastErr_409370(v1);
	} while (result != -1 && (uint8_t)a1 != 10);
	return result;
}

//----- (00517170) --------------------------------------------------------
int nox_xxx_servParseMonsterDef_517170(FILE* a1, const char* a2) {
	int result;        // eax
	uint32_t* v3;      // ebx
	unsigned char* v4; // esi
	int v5;            // eax
	char* v6;          // edi
	int v7;            // edi
	unsigned char* v8; // esi
	int v9;            // [esp+10h] [ebp-104h]
	char v10[256];     // [esp+14h] [ebp-100h]

	result = (int)calloc(1u, 0xF8u);
	v3 = (uint32_t*)result;
	if (result) {
		strcpy((char*)result, a2);
		while (1) {
			if (!nox_xxx_readStr_517090(a1, v10) || !_strcmpi("END", v10)) {
				v3[61] = dword_5d4594_2386924;
				dword_5d4594_2386924 = v3;
				return 1;
			}
			if (nox_common_gameFlags_check_40A5C0(2048) || nox_common_gameFlags_check_40A5C0(0x200000)) {
				if (_strcmpi("ARENA", v10)) {
					if (_strcmpi("SOLO", v10)) {
						goto LABEL_10;
					}
				} else {
					sub_517140(a1);
				}
			} else {
			LABEL_10:
				if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
					goto LABEL_14;
				}
				if (_strcmpi("SOLO", v10)) {
					if (_strcmpi("ARENA", v10)) {
					LABEL_14:
						v4 = getMemAt(0x587000, 248192);
						if (*getMemU32Ptr(0x587000, 248192)) {
							do {
								if (!_strcmpi(*(const char**)v4, v10)) {
									break;
								}
								v5 = *((uint32_t*)v4 + 3);
								v4 += 12;
							} while (v5);
						}
						if (!*(uint32_t*)v4) {
							free(v3);
							return 0;
						}
						v6 = (char*)v3 + *((uint32_t*)v4 + 2);
						switch (*((uint32_t*)v4 + 1)) {
						case 0:
							nox_xxx_readStr_517090(a1, v10);
							*(uint32_t*)v6 = atoi(v10);
							continue;
						case 1:
							nox_xxx_readStr_517090(a1, v10);
							*(float*)v6 = atof(v10);
							continue;
						case 2:
							nox_xxx_readStr_517090(a1, v10);
							*(uint32_t*)v6 = nox_xxx_utilFindSound_40AF50(v10);
							continue;
						case 3:
							nox_xxx_readStr_517090(a1, v10);
							if (nox_xxx_monsterLoadStrikeFn_549040((int)v3, v10)) {
								continue;
							}
							return 0;
						case 4:
							nox_xxx_readStr_517090(a1, v10);
							if (nox_xxx_monsterLoadDieFn_5490E0((int)v3, v10)) {
								continue;
							}
							return 0;
						case 5:
							nox_xxx_readStr_517090(a1, v10);
							if (nox_xxx_monsterLoadDeadFn_549180((int)v3, v10)) {
								continue;
							}
							return 0;
						case 6:
							v9 = 0;
							nox_xxx_readStr_517090(a1, v10);
							set_bitmask_flags_from_plus_separated_names_423930(
								v10, &v9, (const char**)getMemAt(0x587000, 247536));
							*(uint16_t*)v6 = v9;
							continue;
						case 7:
							nox_xxx_readStr_517090(a1, v6);
							if (!strcmp("NULL", v6)) {
								*v6 = 0;
							}
							continue;
						case 8:
							nox_xxx_readStr_517090(a1, v10);
							v3[31] = 18;
							v7 = 0;
							v8 = getMemAt(0x587000, 247464);
							break;
						default:
							continue;
						}
						while (_strcmpi(v10, (const char*)(*(uint32_t*)v8 + 7))) {
							v8 += 4;
							++v7;
							if ((int)v8 >= (int)getMemAt(0x587000, 247536)) {
								goto LABEL_27;
							}
						}
						v3[31] = v7;
					LABEL_27:
						if (v3[31] == 18) {
							return 0;
						}
					}
				} else {
					sub_517140(a1);
				}
			}
		}
	}
	return result;
}

//----- (005174F0) --------------------------------------------------------
uint32_t* nox_xxx_monsterListFree_5174F0() {
	uint32_t* result; // eax
	uint32_t* v1;     // esi

	result = *(uint32_t**)&dword_5d4594_2386924;
	if (dword_5d4594_2386924) {
		do {
			v1 = (uint32_t*)result[61];
			free(result);
			result = v1;
		} while (v1);
		dword_5d4594_2386924 = 0;
	}
	return result;
}

//----- (00517520) --------------------------------------------------------
int nox_xxx_monsterList_517520() {
	int v0; // esi
	int v1; // eax

	v0 = dword_5d4594_2386924;
	if (!dword_5d4594_2386924) {
		return 1;
	}
	while (1) {
		v1 = nox_xxx_getNameId_4E3AA0((char*)v0);
		*(uint32_t*)(v0 + 240) = v1;
		if (!v1) {
			break;
		}
		v0 = *(uint32_t*)(v0 + 244);
		if (!v0) {
			return 1;
		}
	}
	nox_xxx_monsterListFree_5174F0();
	return 0;
}

//----- (00517560) --------------------------------------------------------
uint32_t* nox_xxx_monsterDefByTT_517560(int a1) {
	uint32_t* result; // eax

	result = *(uint32_t**)&dword_5d4594_2386924;
	if (!dword_5d4594_2386924) {
		return 0;
	}
	while (result[60] != a1) {
		result = (uint32_t*)result[61];
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (00517870) --------------------------------------------------------
short sub_517870(nox_object_t* a1p) {
	int a1 = a1p;
	int v1;             // eax
	int v2;             // edi
	unsigned short* v3; // ebx

	v1 = *(uint32_t*)(a1 + 16);
	if (v1 & 0x200) {
		sub_5178E0(0, (unsigned short*)(a1 + 256));
		if (!(*(uint8_t*)(a1 + 8) & 1)) {
			v2 = 0;
			if (*(uint8_t*)(a1 + 336)) {
				v3 = (unsigned short*)(a1 + 272);
				do {
					sub_5178E0(1, v3);
					++v2;
					v3 += 8;
				} while (v2 < *(unsigned char*)(a1 + 336));
			}
			*(uint8_t*)(a1 + 336) = 0;
		}
		v1 = *(uint32_t*)(a1 + 16);
		BYTE1(v1) &= 0xFDu;
		*(uint32_t*)(a1 + 16) = v1;
	}
	return v1;
}

//----- (00517F00) --------------------------------------------------------
int* nox_xxx_secretWallCheckUnits_517F00(float* a1, int (*a2)(int*, int), int a3) {
	int* result; // eax
	int* i;      // esi
	double v5;   // st7
	double v6;   // st7

	result = (int*)nox_xxx_wallSecretGetFirstWall_410780();
	for (i = result; result; i = result) {
		v5 = (double)(23 * i[1]);
		if (v5 > *a1 && v5 < a1[2]) {
			v6 = (double)(23 * i[2]);
			if (v6 > a1[1] && v6 < a1[3]) {
				a2(i, a3);
			}
		}
		result = (int*)nox_xxx_wallSecretNext_410790(i);
	}
	return result;
}

//----- (00518040) --------------------------------------------------------
int sub_518040(int arg0, float a2, int arg8, int a4) {
	int result; // eax
	double v5;  // st7
	double v6;  // st7
	int a3[4];  // [esp+0h] [ebp-20h]
	float4 a1;  // [esp+10h] [ebp-10h]

	result = arg0;
	if (arg0) {
		v5 = *(float*)arg0 - a2;
		a3[2] = arg8;
		a3[0] = arg0;
		*(float*)&a3[1] = a2;
		a1.field_0 = v5;
		v6 = *(float*)(arg0 + 4) - a2;
		a3[3] = a4;
		a1.field_4 = v6;
		a1.field_8 = a2 + *(float*)arg0;
		a1.field_C = a2 + *(float*)(arg0 + 4);
		nox_xxx_getUnitsInRect_517C10(&a1, sub_5180B0, (int)a3);
	}
	return result;
}

//----- (005180B0) --------------------------------------------------------
void sub_5180B0(int a1, int a2) {
	float2* v2;     // eax
	double v3;      // st7
	long double v4; // st7
	long double v5; // st7
	float2* v6;     // eax
	double v7;      // st7
	float2 v8;

	if (a1 && a2) {
		if (*(uint32_t*)(a1 + 172) == 2) {
			v6 = *(float2**)a2;
			*(float*)&v8 = **(float**)a2 - *(float*)(a1 + 56);
			v7 = v6->field_4 - *(float*)(a1 + 60);
			v8.field_4 = v7;
			v4 = sqrt(v7 * v8.field_4 + v8.field_0 * v8.field_0) - *(float*)(a1 + 176);
		} else {
			if (*(uint32_t*)(a1 + 172) == 3) {
				v5 = sub_54A990((float2*)*(uint32_t*)a2, *(float*)(a2 + 4), a1, &v8);
				goto LABEL_9;
			}
			v2 = *(float2**)a2;
			*(float*)&v8 = **(float**)a2 - *(float*)(a1 + 56);
			v3 = v2->field_4 - *(float*)(a1 + 60);
			v8.field_4 = v3;
			v4 = sqrt(v3 * v8.field_4 + v8.field_0 * v8.field_0);
		}
		v5 = *(float*)(a2 + 4) - v4;
	LABEL_9:
		if (v5 > 0.0) {
			(*(void (**)(int, uint32_t))(a2 + 8))(a1, *(uint32_t*)(a2 + 12));
		}
	}
}

//----- (00518770) --------------------------------------------------------
int sub_518770() {
	int result; // eax
	result = nox_xxx_getNameId_4E3AA0("TeleportPentagram");
	*getMemU32Ptr(0x5D4594, 2386972) = result;
	if (!result) {
		return 0;
	}
	result = nox_xxx_getNameId_4E3AA0("PressurePlate");
	*getMemU32Ptr(0x5D4594, 2386976) = result;
	if (!result) {
		return 0;
	}
	result = nox_xxx_getNameId_4E3AA0("Spike");
	*getMemU32Ptr(0x5D4594, 2386980) = result;
	if (!result) {
		return 0;
	}
	result = nox_xxx_getNameId_4E3AA0("PeriodicSpike");
	*getMemU32Ptr(0x5D4594, 2386984) = result;
	if (!result) {
		return 0;
	}
	return 1;
}

//----- (005187E0) --------------------------------------------------------
int nox_xxx_netSendPhantomPlrMb_5187E0(int a1, int a2) {
	short v2;     // ax
	float v3;     // ecx
	short v4;     // ax
	float v5;     // edx
	int v6;       // eax
	char v7;      // al
	int2 a2a;     // [esp+4h] [ebp-14h]
	char v10[11]; // [esp+Ch] [ebp-Ch]

	v10[0] = 48;
	*(uint16_t*)&v10[3] = *(uint16_t*)(a2 + 4);
	v2 = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a2);
	v3 = *(float*)(a2 + 56);
	*(uint16_t*)&v10[1] = v2;
	v4 = nox_float2int(v3);
	v5 = *(float*)(a2 + 60);
	*(uint16_t*)&v10[5] = v4;
	v6 = nox_float2int(v5);
	*(uint16_t*)&v10[7] = v6;
	if (*(uint8_t*)(a2 + 8) & 1 && *(uint8_t*)(a2 + 12) & 0x30) {
		LOWORD(v6) = *(uint16_t*)(a2 + 124);
		v10[10] = v6 >> 3;
	} else {
		v10[10] = -1;
	}
	nox_xxx_xferIndexedDirection_509E20(*(short*)(a2 + 124), &a2a);
	if ((unsigned char)(LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4) <= 3u) {
		v7 = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4;
	} else {
		v7 = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 3;
	}
	v10[9] = 16 * v7;
	return nox_netlist_addToMsgListSrv_40EF40(a1, v10, 11);
}

//----- (005188A0) --------------------------------------------------------
int nox_xxx_netSendSimpleObj_5188A0(int a1, int a2) {
	short* v2; // eax
	int v3;    // ebx
	short v4;  // ax
	short v5;  // cx
	short v6;  // dx
	short v7;  // ax
	float v8;  // ecx
	char v10[9];

	if (*(uint32_t*)(a2 + 8) & 0x20000) {
		v2 = *(short**)(a2 + 556);
		if (v2) {
			v3 = *(uint32_t*)(a2 + 748);
			if ((unsigned int)(gameFrame() - *(uint32_t*)(a2 + 536)) > 2) {
				v4 = *v2;
				v5 = *(uint16_t*)(v3 + 2 * a1 + 96);
				if (v4 != v5) {
					nox_xxx_netReportHealthDelta_4D8760(a1, *(uint32_t*)(a2 + 36), v4 - v5);
					*(uint16_t*)(v3 + 2 * a1 + 96) = **(uint16_t**)(a2 + 556);
				}
			}
		}
	}
	v6 = *(uint16_t*)(a2 + 4);
	v10[0] = 47;
	*(uint16_t*)&v10[3] = v6;
	*(uint16_t*)&v10[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a2);
	v7 = nox_float2int(*(float*)(a2 + 56));
	v8 = *(float*)(a2 + 60);
	*(uint16_t*)&v10[5] = v7;
	*(uint16_t*)&v10[7] = nox_float2int(v8);
	return nox_netlist_addToMsgListSrv_40EF40(a1, v10, 9);
}

//----- (00518960) --------------------------------------------------------
int nox_xxx_netSendComplexObject_518960(int a1, uint32_t* a2, int a3) {
	int v3;       // ebx
	uint32_t* v4; // esi
	short* v5;    // eax
	int v6;       // edi
	short v7;     // ax
	short v8;     // cx
	short v9;     // dx
	short v10;    // ax
	float v11;    // ecx
	short v12;    // ax
	int v13;      // edi
	char v14;     // al
	char v15;     // al
	int2 a2a;     // [esp+Ch] [ebp-14h]
	char v18[11]; // [esp+14h] [ebp-Ch]

	v3 = a1;
	v4 = a2;
	if (a3) {
		v5 = (short*)a2[139];
		if (v5) {
			v6 = a2[187];
			if ((unsigned int)(gameFrame() - a2[134]) > 2) {
				v7 = *v5;
				v8 = *(uint16_t*)(v6 + 2 * a1 + 412);
				if (v7 != v8) {
					nox_xxx_netReportHealthDelta_4D8760(a1, a2[9], v7 - v8);
					*(uint16_t*)(v6 + 2 * v3 + 412) = *(uint16_t*)v4[139];
				}
			}
		}
	}
	v9 = *((uint16_t*)v4 + 2);
	v18[0] = 48;
	*(uint16_t*)&v18[3] = v9;
	*(uint16_t*)&v18[1] = nox_xxx_netGetUnitCodeServ_578AC0(v4);
	v10 = nox_float2int(*((float*)v4 + 14));
	v11 = *((float*)v4 + 15);
	*(uint16_t*)&v18[5] = v10;
	v12 = nox_float2int(v11);
	v13 = v4[187];
	*(uint16_t*)&v18[7] = v12;
	v18[9] = nox_xxx_mobActionToAnimation_533790((int)v4);
	v14 = *((uint8_t*)v4 + 12);
	v18[10] = *(uint8_t*)(v13 + 481);
	if (v14 & 0x10 && *(uint8_t*)(v13 + 2094) && nox_common_randomInt_415FA0(0, 10) >= 8) {
		v18[9] = 14;
		nox_xxx_animPlayerGetFrameRange_4F9F90(50, &a3, &a1);
		v18[10] = nox_common_randomInt_415FA0(0, a3);
	}
	nox_xxx_xferIndexedDirection_509E20(*((short*)v4 + 62), &a2a);
	LOBYTE(a3) = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4;
	if ((unsigned char)a3 <= 3u) {
		v15 = a3;
	} else {
		v15 = a3 - 1;
	}
	v18[9] |= 16 * v15;
	return nox_netlist_addToMsgListSrv_40EF40(v3, v18, 11);
}

//----- (00518AE0) --------------------------------------------------------
int nox_xxx_netSpriteUpdate_518AE0(int a1, int a2, uint32_t* a3) {
	uint32_t* v3;      // esi
	short v4;          // ax
	int v5;            // ecx
	int v7;            // eax
	char v8;           // dl
	int v9;            // eax
	char v10;          // dl
	unsigned char v11; // cl
	int v12;           // esi
	int v13;           // esi
	unsigned char v14; // al
	char v15;          // dl

	v3 = a3;
	v4 = nox_xxx_netGetUnitCodeServ_578AC0(a3);
	v5 = v3[2];
	*(uint16_t*)((char*)&a3 + 1) = v4;
	if (v5 & 0x400000 && v3[3] & 0x18) {
		HIBYTE(a3) = *(uint8_t*)v3[187];
		LOBYTE(a3) = -77;
		return nox_xxx_netSendPacket1_4E5390(a2, (int)&a3, 4, 0, 1);
	}
	v7 = *((unsigned short*)v3 + 2);
	if ((unsigned short)v7 == *getMemU32Ptr(0x5D4594, 2386972)) {
		v8 = *(uint8_t*)(v3[187] + 20);
		LOBYTE(a3) = 57;
		HIBYTE(a3) = v8;
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, &a3, 4);
	}
	if (v7 == *getMemU32Ptr(0x5D4594, 2386980)) {
		v9 = v3[4];
		LOBYTE(a3) = 57;
		HIBYTE(a3) = ~HIBYTE(v9) & 1;
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, &a3, 4);
	}
	if (v7 == *getMemU32Ptr(0x5D4594, 2386976)) {
		v10 = *(uint8_t*)v3[187];
		LOBYTE(a3) = -76;
		HIBYTE(a3) = v10 & 1;
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, &a3, 4);
	}
	if (v5 & 0x4000) {
		v11 = *(uint8_t*)(v3[187] + 16);
		LOBYTE(a3) = 57;
		HIBYTE(a3) = v11 >> 2;
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, &a3, 4);
	}
	if ((v5 & 0x8000) != 0) {
		v12 = v3[187];
		if (v12 && (v13 = *(uint32_t*)(v12 + 4)) != 0) {
			v14 = *(uint8_t*)(*(uint32_t*)(v13 + 748) + 16);
			LOBYTE(a3) = 57;
			HIBYTE(a3) = v14 >> 2;
		} else {
			HIBYTE(a3) = 0;
			LOBYTE(a3) = 57;
		}
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, &a3, 4);
	}
	if ((v5 & 0x80u) != 0) {
		v15 = *(uint8_t*)(v3[187] + 12);
		LOBYTE(a3) = -78;
		HIBYTE(a3) = v15;
		return nox_netlist_addToMsgListCli_40EBC0(a2, 1, &a3, 4);
	}
	nox_xxx_netUpdateObjectSpecial_527E50(a1, v3);
	return 0;
}

//----- (00518C30) --------------------------------------------------------
int nox_xxx_netPlayerObjSend_518C30(nox_object_t* a1p, nox_object_t* a2p, int a3, signed int a4) {
	int a1 = a1p;
	uint32_t* a2 = a2p;
	int v4;         // ebx
	uint32_t* v5;   // esi
	int v6;         // edi
	int v7;         // ebp
	short* v8;      // eax
	short v9;       // ax
	short v10;      // cx
	short v11;      // ax
	short v12;      // ax
	float v13;      // ecx
	short v14;      // ax
	float v15;      // edx
	char v16;       // al
	char v17;       // al
	signed int v18; // eax
	char v19;       // al
	int result;     // eax
	int2 a2a;       // [esp+10h] [ebp-14h]
	char v22[12];   // [esp+18h] [ebp-Ch]
	int v23;        // [esp+28h] [ebp+4h]

	v4 = a1;
	v5 = a2;
	v23 = *(uint32_t*)(a1 + 748);
	v6 = a2[187];
	v7 = *(unsigned char*)(*(uint32_t*)(v23 + 276) + 2064);
	if (a4) {
		v8 = (short*)a2[139];
		if (v8) {
			if ((unsigned int)(gameFrame() - a2[134]) > 2) {
				v9 = *v8;
				v10 = *(uint16_t*)(v6 + 2 * v7 + 12);
				if (v9 != v10) {
					nox_xxx_netReportHealthDelta_4D8760(v7, a2[9], v9 - v10);
					*(uint16_t*)(v6 + 2 * v7 + 12) = *(uint16_t*)v5[139];
				}
			}
		}
	}
	if ((uint32_t*)v4 == v5) {
		nox_xxx_playerReportAnything_4D9900(v4);
	}
	*(uint32_t*)(*(uint32_t*)(v23 + 276) + 4 * *(unsigned char*)(*(uint32_t*)(v6 + 276) + 2064) + 4452) =
		gameFrame();
	v11 = *((uint16_t*)v5 + 2);
	v22[0] = -61;
	*(uint16_t*)&v22[3] = v11;
	v12 = nox_xxx_netGetUnitCodeServ_578AC0(v5);
	v13 = *((float*)v5 + 14);
	*(uint16_t*)&v22[1] = v12;
	v14 = nox_float2int(v13);
	v15 = *((float*)v5 + 15);
	*(uint16_t*)&v22[5] = v14;
	*(uint16_t*)&v22[7] = nox_float2int(v15);
	v22[9] = 0;
	v22[11] = nox_common_mapPlrActionToStateId_4FA2B0((int)v5);
	v16 = *(uint8_t*)(v6 + 88);
	if (v16 == 1 || v16 == 10 || v16 == 2 || v16 == 15 || v16 == 16 || v16 == 17 || v16 == 14 || v16 == 20 ||
		v16 == 18 || v16 == 19 || v16 == 21 || v16 == 22 || v16 == 24 || v16 == 25 || v16 == 27 || v16 == 28 ||
		v16 == 29 || v16 == 26 || v16 == 30 || v16 == 32) {
		v22[10] = *(uint8_t*)(v6 + 236);
	} else {
		v22[10] = -1;
	}
	if (*(uint16_t*)(v6 + 160) && nox_common_randomInt_415FA0(0, 10) >= 8) {
		v22[11] = 50;
		v22[10] = -1;
	}
	v17 = *(uint8_t*)(v6 + 88);
	if ((v17 == 3 || v17 == 4) && v5[131] == 16) {
		v22[11] = 51;
		v22[10] = -1;
	}
	if (*(uint8_t*)(v6 + 88) != 30 && *(uint32_t*)(v6 + 164)) {
		nox_xxx_animPlayerGetFrameRange_4F9F90(52, &a4, (int*)&a2);
		v18 = (gameFrame() - *(uint32_t*)(v6 + 164)) / ((unsigned int)a2 + 1);
		if (v18 >= a4 || (unsigned int)(gameFrame() - *(uint32_t*)(v6 + 164)) >= 4) {
			*(uint32_t*)(v6 + 164) = 0;
		} else {
			v22[11] = 52;
			v22[10] = v18;
		}
	}
	nox_xxx_xferIndexedDirection_509E20(*((short*)v5 + 62), &a2a);
	LOBYTE(a2) = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4;
	if ((unsigned char)a2 <= 3u) {
		v19 = (char)a2;
	} else {
		v19 = (uint8_t)a2 - 1;
	}
	v22[9] |= 16 * v19;
	if (a3) {
		result = nox_netlist_addToMsgListSrv_40EF40(*(unsigned char*)(*(uint32_t*)(v23 + 276) + 2064), v22, 12);
	} else {
		result = nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(*(uint32_t*)(v23 + 276) + 2064), 1, v22, 12);
	}
	return result;
}

//----- (00518EE0) --------------------------------------------------------
void nox_xxx_netUpdate_518EE0(nox_object_t* obj) {
	uint32_t* v1; // ebx
	int v2;       // esi
	int v3;       // edi
	int result;   // eax
	int v5;       // eax
	int v6;       // eax
	int v7;       // eax
	int v8;       // eax
	int v9;       // eax
	int v10;      // eax
	int v11;      // eax
	int v12;      // eax
	int v14;      // ebx
	char v17[3];  // [esp+Ch] [ebp-20h]
	int v18;      // [esp+10h] [ebp-1Ch]
	char v19[5];  // [esp+14h] [ebp-18h]
	float4 a1;    // [esp+1Ch] [ebp-10h]

	v1 = obj;
	v2 = obj->data_update;
	v3 = *(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064);
	nox_netlist_initPlayerBufs_40F020(v3);
	if (v3 != 31 && !((gameFrame() + v3) % (unsigned int)(15 * gameFPS()))) {
		nox_xxx_netReportUnitHeight_4D9020(v3, (int)obj);
	}
	if (!dword_5d4594_2650652 || !(gameFrame() % (unsigned int)nox_xxx_rateGet_40A6C0()) ||
		nox_common_gameFlags_check_40A5C0(8)) {
		if (*(uint8_t*)(*(uint32_t*)(v2 + 276) + 3680) & 0x40) {
			v19[0] = 40;
			*(uint32_t*)&v19[1] = gameFrame();
			nox_netlist_addToMsgListSrv_40EF40(v3, v19, 5);
			nox_xxx_playerUnsetStatus_417530(*(uint32_t*)(v2 + 276), 64);
		} else {
			v17[0] = 39;
			*(uint16_t*)&v17[1] = (unsigned short)gameFrame();
			nox_netlist_addToMsgListSrv_40EF40(v3, v17, 3);
		}
	}
	if (!dword_5d4594_2650652 || (uint32_t*)obj == *(uint32_t**)&nox_xxx_host_player_unit_3843628 ||
		nox_common_gameFlags_check_40A5C0(8) || !(gameFrame() % (unsigned int)nox_xxx_rateGet_40A6C0())) {
		if (*(uint8_t*)(*(uint32_t*)(v2 + 276) + 3680) & 3 || nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ)) {
			result = nox_xxx_netPlayerObjSendCamera_519330((int)obj);
			if (!result) {
				return;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ)) {
				nox_xxx_netPlayerObjSend_518C30((int)obj, obj, 1, 1);
			}
		} else {
			result = nox_xxx_netPlayerObjSend_518C30((int)obj, obj, 1, 1);
			if (!result) {
				return;
			}
		}
		v5 = *(uint32_t*)(v2 + 276);
		v18 = *(unsigned short*)(v5 + 10);
		a1.field_0 = *(float*)(v5 + 3632) - (double)v18 - 100.0;
		v6 = *(uint32_t*)(v2 + 276);
		v18 = *(unsigned short*)(v6 + 12);
		a1.field_4 = *(float*)(v6 + 3636) - (double)v18 - 100.0;
		v7 = *(uint32_t*)(v2 + 276);
		v18 = *(unsigned short*)(v7 + 10);
		a1.field_8 = (double)v18 + *(float*)(v7 + 3632) + 100.0;
		v8 = *(uint32_t*)(v2 + 276);
		v18 = *(unsigned short*)(v8 + 12);
		a1.field_C = (double)v18 + *(float*)(v8 + 3636) + 100.0;
		nox_xxx_getUnitsInRectAdv_517ED0(&a1, nox_xxx_unitAroundPlayerFn_5193B0, (int)obj);
		v9 = *(uint32_t*)(v2 + 276);
		v18 = *(unsigned short*)(v9 + 10);
		a1.field_0 = *(float*)(v9 + 3632) - (double)v18 - 128.0;
		v10 = *(uint32_t*)(v2 + 276);
		v18 = *(unsigned short*)(v10 + 12);
		a1.field_4 = *(float*)(v10 + 3636) - (double)v18 - 128.0;
		v11 = *(uint32_t*)(v2 + 276);
		v18 = *(unsigned short*)(v11 + 10);
		a1.field_8 = (double)v18 + *(float*)(v11 + 3632) + 128.0;
		v12 = *(uint32_t*)(v2 + 276);
		v18 = *(unsigned short*)(v12 + 12);
		a1.field_C = (double)v18 + *(float*)(v12 + 3636) + 128.0;
		nox_xxx_secretWallCheckUnits_517F00(&a1, sub_519660, (int)obj);
		if (sub_519710(v2)) {
			sub_519760((int)obj, &a1.field_0);
		}
		if ((unsigned char)gameFrame() & 8) {
			v14 = 1 << *(uint8_t*)(*(uint32_t*)(v2 + 276) + 2064);

			for (int cur_obj = nox_server_getFirstObject_4DA790(); cur_obj;
				 cur_obj = nox_server_getNextObject_4DA7A0(cur_obj)) {
				if (!(*(uint32_t*)(cur_obj + 8) & 0x20400000) &&
					!nox_xxx_playerMapTracksObj_4173D0(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), cur_obj) &&
					(*(float*)(cur_obj + 232) > (double)a1.field_8 || *(float*)(cur_obj + 240) < (double)a1.field_0 ||
					 *(float*)(cur_obj + 236) > (double)a1.field_C || *(float*)(cur_obj + 244) < (double)a1.field_4)) {
					if (v14 & *(uint32_t*)(cur_obj + 148)) {
						nox_xxx_netObjectOutOfSight_528A60(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064),
														   (uint32_t*)cur_obj);
						*(uint32_t*)(cur_obj + 152) |= v14;
						*(uint32_t*)(cur_obj + 148) &= ~v14;
					}
				}
			}
			for (nox_object_t* cur_obj = nox_xxx_getFirstUpdatable2Object_4DA840(); cur_obj;
				 cur_obj = nox_xxx_getNextUpdatable2Object_4DA850(cur_obj)) {
				if (!(cur_obj->obj_class & 0x20400000) &&
					!nox_xxx_playerMapTracksObj_4173D0(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), cur_obj) &&
					(cur_obj->collide_x1 > (double)a1.field_8 ||
					 cur_obj->collide_x2 < (double)a1.field_0 ||
					 cur_obj->collide_y1 > (double)a1.field_C ||
					 cur_obj->collide_y2 < (double)a1.field_4)) {
					if (v14 & cur_obj->field_37) {
						nox_xxx_netObjectOutOfSight_528A60(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064),
														   (uint32_t*)cur_obj);
						*(uint32_t*)&cur_obj->field_38 |= v14;
						cur_obj->field_37 &= ~v14;
					}
				}
			}

			v1 = obj;
		}
	}
	if (!dword_5d4594_2650652 || !(gameFrame() % (unsigned int)nox_xxx_rateGet_40A6C0()) ||
		nox_common_gameFlags_check_40A5C0(8)) {
		sub_4FF7B0(*(uint32_t*)(v2 + 276));
		sub_511100(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064));
	}
	nox_xxx_netUpdateRemotePlr_501CA0((int)v1);
}

//----- (00519330) --------------------------------------------------------
int nox_xxx_netPlayerObjSendCamera_519330(int a1) {
	int v1;      // esi
	char v3[12]; // [esp+8h] [ebp-Ch]

	v1 = *(uint32_t*)(a1 + 748);
	v3[0] = -61;
	*(uint16_t*)&v3[3] = 0;
	*(uint16_t*)&v3[1] = 0;
	*(uint16_t*)&v3[5] = (long long)*(float*)(*(uint32_t*)(v1 + 276) + 3632);
	*(uint16_t*)&v3[7] = (long long)*(float*)(*(uint32_t*)(v1 + 276) + 3636);
	v3[9] = 0;
	v3[10] = -1;
	v3[11] = 0;
	return nox_netlist_addToMsgListSrv_40EF40(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064), v3, 12);
}

//----- (005193B0) --------------------------------------------------------
char nox_xxx_unitAroundPlayerFn_5193B0(uint32_t* a1, int a2) {
	int v2; // ebx
	int v3; // eax

	v2 = *(uint32_t*)(a2 + 748);
	if ((uint32_t*)a2 != a1 ||
		(nox_xxx_netUpdateObjectSpecial_527E50(a2, a1), v3 = *(uint32_t*)(v2 + 276), *(uint8_t*)(v3 + 3680) & 1)) {
		if (!nox_common_gameFlags_check_40A5C0(0x2000) ||
			(LOBYTE(v3) = (unsigned char)gameFrame(), *(uint32_t*)(v2 + 272) != gameFrame())) {
			LOBYTE(v3) = nox_xxx_netSendObjects2Plr_519410(a2, (int)a1);
		}
	}
	return v3;
}

//----- (00519410) --------------------------------------------------------
char nox_xxx_netSendObjects2Plr_519410(nox_object_t* a1p, nox_object_t* a2p) {
	int a1 = a1p;
	int a2 = a2p;
	int v2;     // ebx
	int v3;     // ecx
	int v4;     // eax
	int v5;     // edi
	int v6;     // ebp
	int v7;     // eax
	int v8;     // eax
	float v9;   // ecx
	float v10;  // edx
	int v11;    // eax
	int v13;    // [esp+10h] [ebp-14h]
	float4 v14; // [esp+14h] [ebp-10h]

	v4 = *(uint32_t*)(a1 + 748);
	v13 = v4;
	v2 = 0;
	v3 = *(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064);
	LOBYTE(v4) = *(uint8_t*)(a2 + 16);
	v5 = v3;
	if (!(v4 & 0x20) && !(*(uint32_t*)(a2 + 8) & 0x40000000)) {
		v6 = 1 << v3;
		if (a2 != a1 && v6 & *(uint32_t*)(a2 + 140)) {
			nox_xxx_netFriendAddRemove_4D97A0(v3, (uint32_t*)a2, (v6 & *(uint32_t*)(a2 + 144)) != 0);
			LOBYTE(v4) = ~(uint8_t)v6;
			*(uint32_t*)(a2 + 140) &= ~v6;
		}
		if (v6 & *(uint32_t*)(a2 + 152) || *(uint8_t*)(a2 + 8) & 1) {
			v7 = *(uint32_t*)(a2 + 16);
			if (!(v7 & 0x800) || nox_xxx_unitHasThatParent_4EC4F0(a2, a1) ||
				(v4 = nox_common_gameFlags_check_40A5C0(512)) != 0) {
				v8 = *(uint32_t*)(v13 + 276);
				v14.field_0 = *(float*)(v8 + 3632);
				v9 = *(float*)(a2 + 60);
				v10 = *(float*)(v8 + 3636);
				v14.field_8 = *(float*)(a2 + 56);
				v4 = *(uint32_t*)(a2 + 8);
				v14.field_4 = v10;
				v14.field_C = v9;
				if (v4 & 0x20400000 || (v4 = nox_xxx_playerMapTracksObj_4173D0(v5, a2)) != 0 ||
					(v4 = nox_xxx_mapTraceRay_535250(&v14, 0, 0, 69)) != 0) {
					if (v6 & *(uint32_t*)(a2 + 148)) {
						if (*(uint8_t*)(a2 + 20) & 0x20) {
							return v4;
						}
					} else if (*(uint32_t*)(a2 + 4 * v5 + 560) & 0xFFF) {
						*(uint32_t*)(a2 + 4 * v5 + 560) |= (*(uint32_t*)(a2 + 4 * v5 + 560) & 0xFFF) << 16;
					}
					v11 = *(uint32_t*)(a2 + 8);
					if (v11 & 0x400000) {
						v2 = nox_xxx_netSpriteUpdate_518AE0(a1, v5, (uint32_t*)a2);
					} else if (v11 & 0x200000) {
						if (v11 & 2) {
							v2 = nox_xxx_netSendComplexObject_518960(v5, (uint32_t*)a2, 1);
						} else if (v11 & 4) {
							v2 = nox_xxx_netPlayerObjSend_518C30(a1, (uint32_t*)a2, 1, 1);
						} else {
							v2 = nox_xxx_netSendPhantomPlrMb_5187E0(v5, a2);
						}
					} else if (v11 & 0x100000) {
						v2 = nox_xxx_netSendSimpleObj_5188A0(v5, a2);
					} else {
						*(uint32_t*)(a2 + 152) = 0;
					}
					LOBYTE(v4) = nox_xxx_netUpdateObjectSpecial_527E50(a1, (uint32_t*)a2);
					if (v2) {
						v4 = v6 | *(uint32_t*)(a2 + 148);
						*(uint32_t*)(a2 + 152) &= ~v6;
						*(uint32_t*)(a2 + 148) = v4;
					}
				} else if (v6 & *(uint32_t*)(a2 + 148)) {
					if (*(uint8_t*)(a2 + 8) & 6) {
						nox_xxx_netObjectOutOfSight_528A60(v5, (uint32_t*)a2);
					} else {
						nox_xxx_netObjectInShadows_528A90(v5, (uint32_t*)a2);
					}
					v4 = ~v6 & *(uint32_t*)(a2 + 148);
					*(uint32_t*)(a2 + 152) |= v6;
					*(uint32_t*)(a2 + 148) = v4;
				}
			}
		}
	}
	return v4;
}

//----- (00519660) --------------------------------------------------------
int sub_519660(int a1, int a2) {
	int v2;     // esi
	int result; // eax
	int v4;     // ebx
	int v5;     // [esp-4h] [ebp-10h]

	v2 = 1 << *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a2 + 748) + 276) + 2064);
	result = (v2 & *(uint32_t*)(a1 + 28)) != 0;
	switch (*(unsigned char*)(a1 + 21)) {
	case 1u:
	case 4u:
		v4 = 0;
		break;
	case 2u:
	case 3u:
		v4 = 1;
		break;
	default:
		v4 = a2;
		break;
	}
	if (result != v4) {
		v5 = nox_server_getWallAtGrid_410580(*(uint32_t*)(a1 + 4), *(uint32_t*)(a1 + 8));
		if (v4) {
			sub_4DF120(v5);
			result = v2 | *(uint32_t*)(a1 + 28);
		} else {
			sub_4DF180(v5);
			result = ~v2 & *(uint32_t*)(a1 + 28);
		}
		*(uint32_t*)(a1 + 28) = result;
	}
	return result;
}

//----- (00519710) --------------------------------------------------------
int sub_519710(int a1) {
	int result; // eax

	result = sub_417270(*(unsigned char*)(*(uint32_t*)(a1 + 276) + 2064));
	if (result) {
		result = result > 60 || gameFrame() - *(uint32_t*)(a1 + 268) > (unsigned int)(60 / result);
	}
	return result;
}

//----- (00519830) --------------------------------------------------------
int nox_xxx_netMapSendClear_519830(int a1, char a2) {
	int result; // eax

	result = a1;
	if (a1) {
		*(uint32_t*)(a1 + 40) = 0;
		*(uint8_t*)a1 = a2;
		*(uint16_t*)(a1 + 2) = 0;
		*(uint16_t*)(a1 + 4) = 0;
		*(uint32_t*)(a1 + 8) = 0;
		*(uint32_t*)(a1 + 12) = 0;
		*(uint32_t*)(a1 + 16) = 1;
		*(uint16_t*)(a1 + 20) = 512;
		*(uint32_t*)(a1 + 24) = 0;
		*(uint8_t*)(a1 + 28) = 2;
		*(uint32_t*)(a1 + 32) = 0;
		*(uint32_t*)(a1 + 44) = 0;
	}
	return result;
}

//----- (00519870) --------------------------------------------------------
int nox_xxx_netMapSendStop_519870() {
	char v0;           // di
	unsigned char* v1; // esi
	int result;        // eax

	v0 = 0;
	v1 = getMemAt(0x5D4594, 2387148);
	*getMemU16Ptr(0x5D4594, 2388636) = 0;
	*getMemU16Ptr(0x5D4594, 2388638) = 0;
	dword_5d4594_2388640 = 0;
	dword_5d4594_2388648 = 0;
	do {
		result = nox_xxx_netMapSendClear_519830((int)v1, v0);
		v1 += 48;
		++v0;
	} while ((int)v1 < (int)getMemAt(0x5D4594, 2388636));
	return result;
}

//----- (005198B0) --------------------------------------------------------
void nox_xxx_mapSendCancelAll_5198B0(unsigned char a1) {
	char v1;           // bl
	unsigned char* v2; // esi

	v1 = 0;
	v2 = getMemAt(0x5D4594, 2387150);
	do {
		if (*(uint16_t*)v2 == 1) {
			*(uint16_t*)v2 = 0;
			nullsub_27(v2 - 2);
			nox_xxx_netSendMapAbort_519C80_net_mapsend(v2 - 2, a1);
			++*getMemU16Ptr(0x5D4594, 2388638);
			if (*((uint16_t*)v2 + 1) == 1) {
				if (*(uint32_t*)(v2 + 6)) {
					free(*(void**)(v2 + 6));
				}
			}
			nox_xxx_netMapSendClear_519830((int)(v2 - 2), v1);
		}
		v2 += 48;
		++v1;
	} while ((int)v2 < (int)getMemAt(0x5D4594, 2388638));
}
// 519920: using guessed type void  nullsub_27(uint32_t);

//----- (00519E80) --------------------------------------------------------
void sub_519E80(int a1) {
	nox_common_playerInfoFromNum_417090(a1);
	sub_4DE410(getMemByte(0x5D4594, 2387148 + 48 * a1));
}

//----- (0051A100) --------------------------------------------------------
void* sub_51A100() {
	void* result; // eax

	if (dword_5d4594_2388648) {
		nox_xxx_mapSendCancelAll_5198B0(0);
	}
	result = *(void**)&dword_5d4594_2388640;
	if (dword_5d4594_2388640) {
		free(*(void**)&dword_5d4594_2388640);
	}
	*getMemU32Ptr(0x5D4594, 2388644) = 0;
	return result;
}

//----- (0051A130) --------------------------------------------------------
int sub_51A130() { return dword_5d4594_2388648; }

//----- (0051A500) --------------------------------------------------------
int sub_51A500(int a1) {
	int v1;           // ecx
	int v2;           // edx
	unsigned char* i; // eax
	int v4;           // esi

	if (!*getMemU32Ptr(0x5D4594, 2388664)) {
		sub_51A550();
	}
	if (!a1) {
		return 0;
	}
	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 249904)) {
		return 0;
	}
	HIWORD(v2) = 0;
	for (i = getMemAt(0x587000, 249904);; i += 16) {
		LOWORD(v2) = *(uint16_t*)(a1 + 4);
		if (*((uint32_t*)i - 1) == v2) {
			break;
		}
		v4 = *((uint32_t*)i + 4);
		++v1;
		if (!v4) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 249908 + 16 * v1);
}

//----- (0051A550) --------------------------------------------------------
char* sub_51A550() {
	char* result;      // eax
	unsigned char* v1; // esi

	result = *(char**)getMemAt(0x587000, 249904);
	if (*getMemU32Ptr(0x587000, 249904)) {
		v1 = getMemAt(0x587000, 249896);
		do {
			*((uint32_t*)v1 + 3) = nox_xxx_getNameId_4E3AA0(result);
			*((uint32_t*)v1 + 1) = nox_xxx_getNameId_4E3AA0(*(char**)v1);
			result = (char*)*((uint32_t*)v1 + 6);
			v1 += 16;
		} while (result);
		*getMemU32Ptr(0x5D4594, 2388664) = 1;
	} else {
		*getMemU32Ptr(0x5D4594, 2388664) = 1;
	}
	return result;
}

//----- (0051A5A0) --------------------------------------------------------
void* nox_xxx_objectTypeByIndHealthData(int a1);
void nox_xxx_spawnHecubahQuest_51A5A0(int* a1) {
	uint32_t* v1;  // edi
	uint32_t* v2;  // esi
	int v3;        // eax
	int v4;        // eax
	double v5;     // st7
	int v6;        // eax
	uint32_t* v7;  // esi
	int v8;        // eax
	uint32_t* v9;  // eax
	int v10;       // eax
	uint32_t* v11; // eax
	int v12;       // eax
	uint32_t* v13; // eax
	int v14;       // eax
	uint32_t* v15; // eax
	float v16;     // [esp+8h] [ebp-8h]
	float v17;     // [esp+Ch] [ebp-4h]

	v1 = nox_xxx_newObjectByTypeID_4E3810("Hecubah");
	v16 = sub_4E40F0();
	if (v1) {
		v2 = (uint32_t*)v1[187];
		v3 = v2[121];
		if (v3) {
			v4 = *(uint32_t*)(v3 + 72);
		} else {
			v4 = *(unsigned short*)((int)nox_xxx_objectTypeByIndHealthData(*((unsigned short*)v1 + 2)) + 4);
		}
		if (v16 < 1.0) {
			v16 = 1.0;
		}
		v5 = (double)v4 * v16;
		v17 = v5;
		nox_xxx_unitSetHP_4E4560((int)v1, (long long)v5);
		*(uint16_t*)(v1[139] + 4) = nox_float2int(v17);
		if (!*(uint16_t*)v1[139]) {
			nox_xxx_unitSetHP_4E4560((int)v1, 1u);
		}
		v6 = v1[139];
		if (!*(uint16_t*)(v6 + 4)) {
			*(uint16_t*)(v6 + 4) = 1;
		}
		v2[411] = 0x10000000;
		v2[423] = 0x10000000;
		v2[340] = 4;
		v2[326] = 1062501089;
		v2[510] = 3;
		v2[410] = 0x8000000;
		v2[444] = 0x20000000;
		v2[388] = 0x40000000;
		v2[415] = 0x40000000;
		nox_xxx_gamedataGetFloat_419D40("HecubahQuestSkill");
		v2[330] = 1062836634;
		nox_xxx_createAt_4DAA50((int)v1, 0, *(float*)a1, *((float*)a1 + 1));
		v7 = nox_xxx_newObjectByTypeID_4E3810("RewardMarker");
		if (v7) {
			v8 = nox_game_getQuestStage_4E3CC0();
			v9 = nox_server_rewardgen_activateMarker_4F0720((int)v7, v8 + 2);
			if (v9) {
				nox_xxx_inventoryPutImpl_4F3070((int)v1, (int)v9, 0);
			}
			v10 = nox_game_getQuestStage_4E3CC0();
			v11 = nox_server_rewardgen_activateMarker_4F0720((int)v7, v10 + 2);
			if (v11) {
				nox_xxx_inventoryPutImpl_4F3070((int)v1, (int)v11, 0);
			}
			v12 = nox_game_getQuestStage_4E3CC0();
			v13 = nox_server_rewardgen_activateMarker_4F0720((int)v7, v12 + 2);
			if (v13) {
				nox_xxx_inventoryPutImpl_4F3070((int)v1, (int)v13, 0);
			}
			v14 = nox_game_getQuestStage_4E3CC0();
			v15 = nox_server_rewardgen_activateMarker_4F0720((int)v7, v14 + 2);
			if (v15) {
				nox_xxx_inventoryPutImpl_4F3070((int)v1, (int)v15, 0);
			}
			nox_xxx_objectFreeMem_4E38A0((int)v7);
		}
	}
}

//----- (0051A7A0) --------------------------------------------------------
void nox_xxx_spawnNecroQuest_51A7A0(int* a1) {
	uint32_t* v1; // edi
	uint32_t* v2; // esi
	int v3;       // eax
	int v4;       // eax
	double v5;    // st7
	int v6;       // eax
	uint32_t* v7; // esi
	int v8;       // eax
	uint32_t* v9; // eax
	float v10;    // [esp+8h] [ebp-8h]
	float v11;    // [esp+Ch] [ebp-4h]

	v1 = nox_xxx_newObjectByTypeID_4E3810("Necromancer");
	v10 = sub_4E40F0();
	if (v1) {
		v2 = (uint32_t*)v1[187];
		v3 = v2[121];
		if (v3) {
			v4 = *(uint32_t*)(v3 + 72);
		} else {
			v4 = *(unsigned short*)((int)nox_xxx_objectTypeByIndHealthData(*((unsigned short*)v1 + 2)) + 4);
		}
		if (v10 < 1.0) {
			v10 = 1.0;
		}
		v5 = (double)v4 * v10;
		v11 = v5;
		nox_xxx_unitSetHP_4E4560((int)v1, (long long)v5);
		*(uint16_t*)(v1[139] + 4) = nox_float2int(v11);
		if (!*(uint16_t*)v1[139]) {
			nox_xxx_unitSetHP_4E4560((int)v1, 1u);
		}
		v6 = v1[139];
		if (!*(uint16_t*)(v6 + 4)) {
			*(uint16_t*)(v6 + 4) = 1;
		}
		v2[340] = 4;
		v2[411] = 0x10000000;
		v2[423] = 0x10000000;
		v2[326] = 1062501089;
		v2[510] = 1;
		v2[410] = 0x8000000;
		v2[444] = 0x20000000;
		v2[415] = 0x40000000;
		nox_xxx_createAt_4DAA50((int)v1, 0, *(float*)a1, *((float*)a1 + 1));
		v7 = nox_xxx_newObjectByTypeID_4E3810("RewardMarker");
		if (v7) {
			v8 = nox_game_getQuestStage_4E3CC0();
			v9 = nox_server_rewardgen_activateMarker_4F0720((int)v7, v8 + 2);
			if (v9) {
				nox_xxx_inventoryPutImpl_4F3070((int)v1, (int)v9, 0);
			}
			nox_xxx_objectFreeMem_4E38A0((int)v7);
		}
	}
}

//----- (0051A930) --------------------------------------------------------
int nox_xxx_getQuestStage_51A930() { return *getMemU32Ptr(0x5D4594, 2388660); }

//----- (0051A940) --------------------------------------------------------
int sub_51A940(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 2388656) = a1;
	return result;
}

//----- (0051A950) --------------------------------------------------------
int sub_51A950() { return *getMemU32Ptr(0x5D4594, 2388656); }

//----- (0051B810) --------------------------------------------------------
void sub_51B810(nox_object_t* a1p) {
	int a1 = a1p;
	float* v1; // eax
	double v2; // st7
	int v3;    // edx
	double v4; // st7
	int v6;    // [esp-4h] [ebp-4h]
	float v7;  // [esp+4h] [ebp+4h]

	v1 = (float*)a1;
	v6 = a1;
	v2 = *(float*)(a1 + 88) + *(float*)(a1 + 80);
	v3 = *(uint32_t*)(a1 + 68);
	*(uint32_t*)(a1 + 56) = *(uint32_t*)(a1 + 64);
	*(uint32_t*)(a1 + 60) = v3;
	v4 = v2 * *(float*)(a1 + 112);
	*(float*)(a1 + 80) = v4;
	v7 = (v1[23] + v1[21]) * v1[28];
	v1[21] = v7;
	v1[16] = v4 + v1[16];
	v1[17] = v7 + v1[17];
	nox_xxx_objectUnkUpdateCoords_4E7290(v6);
}

//----- (0051B860) --------------------------------------------------------
char sub_51B860(int a1) { return nox_xxx_unitHasCollideOrUpdateFn_537610(a1); }

//----- (0051B870) --------------------------------------------------------
void nox_xxx_updateFallLogic_51B870(nox_object_t* a1p) {
	int a1 = a1p;
	int v1;         // esi
	int v2;         // ecx
	double v3;      // st7
	double v4;      // st7
	double v5;      // st7
	double v6;      // st6
	long double v7; // st6
	double v8;      // st7
	double v9;      // st7
	float v10;      // [esp+0h] [ebp-14h]
	float v11;      // [esp+0h] [ebp-14h]
	float v12;      // [esp+0h] [ebp-14h]
	float v13;      // [esp+10h] [ebp-4h]
	int v14;        // [esp+18h] [ebp+4h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 16);
	v3 = *(float*)(a1 + 104);
	if (v2 & 0x40000) {
		v10 = v3 + *(float*)(a1 + 108);
		nox_xxx_unitRaise_4E46F0(a1, v10);
		v4 = *(float*)(a1 + 108) - 1.0;
		*(uint32_t*)(a1 + 88) = 0;
		*(uint32_t*)(a1 + 92) = 0;
		*(uint32_t*)(a1 + 80) = 0;
		*(uint32_t*)(a1 + 84) = 0;
		*(float*)(a1 + 108) = v4;
		v5 = *(float*)(a1 + 56) - *(float*)(a1 + 156);
		v6 = *(float*)(a1 + 60) - *(float*)(a1 + 160);
		v13 = v6;
		v7 = sqrt(v6 * v13 + v5 * v5);
		*(float*)&v14 = v7;
		if (v7 > 0.0) {
			*(float*)(v1 + 88) = v5 * -3.0 / *(float*)&v14;
			*(float*)(v1 + 92) = v13 * -3.0 / *(float*)&v14;
		}
		if (*(float*)(v1 + 104) < -50.0) {
			nox_xxx_unitRaise_4E46F0(v1, 90.0);
			*(uint32_t*)(v1 + 16) &= 0xFFFBFFFF;
			nox_xxx_unitMove_4E7010(v1, (float2*)(v1 + 164));
		}
	} else if (v3 != 0.0 || *(float*)(a1 + 108) != 0.0) {
		if (0x800000 & v2) {
			v11 = *(float*)(a1 + 104) + *(float*)(a1 + 108);
			nox_xxx_unitRaise_4E46F0(a1, v11);
			if (*(float*)(a1 + 104) >= 0.0) {
				*(float*)(a1 + 108) = *(float*)(a1 + 108) - 0.5;
			} else {
				nox_xxx_unitRaise_4E46F0(a1, 0.0);
				v8 = -*(float*)(a1 + 108) * *(float*)(a1 + 116) * 0.1;
				*(float*)(a1 + 108) = v8;
				if (v8 < 2.0) {
					nox_xxx_unitRaise_4E46F0(a1, 0.0);
					*(uint32_t*)(a1 + 108) = 0;
				}
			}
		} else if (!(v2 & 0x100000)) {
			if (*(float*)(a1 + 104) > 0.0) {
				if (*(float*)(a1 + 108) <= 0.0) {
					*(uint32_t*)(a1 + 16) = v2 | 0x20000;
				}
				v12 = *(float*)(a1 + 104) + *(float*)(a1 + 108);
				nox_xxx_unitRaise_4E46F0(a1, v12);
				*(float*)(a1 + 108) = *(float*)(a1 + 108) - 1.0;
			}
			if (*(float*)(a1 + 104) <= 0.0) {
				v9 = *(float*)(a1 + 108);
				*(uint32_t*)(a1 + 16) &= 0xFFFDFFFF;
				if (v9 < 0.0 && !(*(uint8_t*)(a1 + 8) & 1)) {
					nox_xxx_unitHasCollideOrUpdateFn_537610(a1);
					if (*(float*)(a1 + 108) < -10.0) {
						if (*(uint8_t*)(a1 + 8) & 4) {
							nox_xxx_aud_501960(280, a1, 0, 0);
						}
					}
				}
				nox_xxx_unitRaise_4E46F0(a1, 0.0);
				*(uint32_t*)(a1 + 108) = 0;
			}
		}
	}
}

//----- (0051D0E0) --------------------------------------------------------
void sub_51D0E0() { dword_5d4594_2487244 = 0; }

//----- (0051D0F0) --------------------------------------------------------
int sub_51D0F0(char a1) {
	*getMemU8Ptr(0x973F18, 35972) = a1;
	return 1;
}

//----- (0051D100) --------------------------------------------------------
int sub_51D100(int a1) {
	if (a1 != 1 && a1) {
		return 0;
	}
	*getMemU32Ptr(0x973F18, 35976) = a1;
	return 1;
}

//----- (0051D120) --------------------------------------------------------
uint32_t* sub_51D120(float* a1) {
	uint32_t* result; // eax
	uint32_t* v2;     // esi
	float2 v3;        // [esp+4h] [ebp-8h]

	result = (float*)nox_xxx_mapGenFixCoords_4D3D90((float2*)a1, &v3);
	if (result) {
		result = nox_xxx_waypointNew_5798F0(v3.field_0, v3.field_4);
		v2 = result;
		if (result) {
			if (dword_5d4594_2487244) {
				if (*getMemU32Ptr(0x973F18, 35976) == 1) {
					sub_51D300(*(int*)&dword_5d4594_2487244, (int)result, getMemByte(0x973F18, 35972));
					sub_51D300((int)v2, *(int*)&dword_5d4594_2487244, getMemByte(0x973F18, 35972));
				}
			}
			dword_5d4594_2487244 = v2;
			result = v2;
		}
	}
	return result;
}

//----- (0051D1A0) --------------------------------------------------------
float* sub_51D1A0(float2* a1) {
	float* result; // eax
	float2 a2;     // [esp+0h] [ebp-8h]

	result = (float*)nox_xxx_mapGenFixCoords_4D3D90(a1, &a2);
	if (result) {
		result = sub_579AD0(a2.field_0, a2.field_4);
	}
	return result;
}

//----- (0051D2C0) --------------------------------------------------------
int sub_51D2C0(int a1, int a2) { return sub_51D300(a1, a2, getMemByte(0x973F18, 35972)); }

//----- (0051D300) --------------------------------------------------------
int sub_51D300(int a1, int a2, char a3) {
	unsigned char v3; // al
	int v4;           // ecx
	int v5;           // esi
	uint8_t* v6;      // eax

	v3 = *(uint8_t*)(a1 + 476);
	if (v3 >= 0x1Fu || a1 == a2) {
		return 0;
	}
	v4 = 0;
	v5 = v3;
	if ((int)v3 > 0) {
		v6 = (uint8_t*)(a1 + 96);
		do {
			if (*((uint32_t*)v6 - 1) == a2 && *v6 == a3) {
				break;
			}
			++v4;
			v6 += 8;
		} while (v4 < v5);
	}
	if (v4 != v5) {
		return 0;
	}
	*(uint32_t*)(a1 + 8 * v5 + 92) = a2;
	*(uint8_t*)(a1 + 8 * (unsigned char)(*(uint8_t*)(a1 + 476))++ + 96) = a3;
	return 1;
}

//----- (0051D3F0) --------------------------------------------------------
float2* sub_51D3F0(float2* a1, float2* a2) {
	float2* result; // eax
	float2* v3;     // esi

	result = a1;
	if (a1) {
		if (a2) {
			result = (float2*)sub_51D1A0(a1);
			v3 = result;
			if (result) {
				result = (float2*)sub_51D1A0(a2);
				if (result) {
					result = (float2*)sub_51D2C0((int)v3, (int)result);
				}
			}
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (0051D4D0) --------------------------------------------------------
int nox_xxx_tileGetDefByName_51D4D0(char* a1) {
	int v1;         // ebx
	int v2;         // edi
	const char* v3; // esi

	v1 = 0;
	v2 = 0;
	v3 = (const char*)getMemAt(0x85B3FC, 32484);
	do {
		if (!_strcmpi(v3, a1)) {
			v1 = 1;
			*getMemU32Ptr(0x973F18, 35912) = v2;
		}
		v3 += 60;
		++v2;
	} while ((int)v3 < (int)getMemAt(0x85B3FC, 43044));
	if (!_strcmpi(a1, "NONE")) {
		*getMemU32Ptr(0x973F18, 35912) = 255;
		return 1;
	}
	if (v1) {
		return 1;
	}
	*getMemU32Ptr(0x973F18, 35912) = 0;
	return 0;
}

//----- (0051D540) --------------------------------------------------------
int nox_xxx_tileCheckImage_51D540(int a1) {
	int result; // eax

	if (a1 < 0 || a1 >= 176) {
		*getMemU32Ptr(0x973F18, 35912) = 0;
		result = 0;
	} else {
		*getMemU32Ptr(0x973F18, 35912) = a1;
		result = 1;
	}
	return result;
}

//----- (0051D570) --------------------------------------------------------
int nox_xxx_tileCheckImageVari_51D570(int a1) {
	int result; // eax

	if (a1 <= getMemByte(0x85B3FC, 32536 + 60 * *getMemU32Ptr(0x973F18, 35912)) *
					  getMemByte(0x85B3FC, 32537 + 60 * *getMemU32Ptr(0x973F18, 35912)) -
				  1) {
		dword_5d4594_3835348 = a1;
		result = 1;
	} else {
		dword_5d4594_3835348 = 0;
		result = 0;
	}
	return result;
}

//----- (0051D5C0) --------------------------------------------------------
int nox_xxx_tile_51D5C0(int a1) {
	if (a1 != 1 && a1) {
		return 0;
	}
	*getMemU32Ptr(0x973F18, 35916) = a1;
	return 1;
}

//----- (0051D5E0) --------------------------------------------------------
float* sub_51D5E0(float* a1) {
	float* result; // eax
	float2 v2;     // [esp+0h] [ebp-8h]

	result = a1;
	if (a1) {
		if (*getMemU32Ptr(0x973F18, 35912) == 255 ||
			(nox_xxx_mapGenFixCoords_4D3D90((float2*)a1, &v2), (result = (float*)sub_51D8F0(&v2)) != 0) &&
				(dword_5d4594_3835364 != 1 || (result = (float*)sub_527380(&v2.field_0)) != 0)) {
			result = (float*)1;
		}
	}
	return result;
}

//----- (0051D8F0) --------------------------------------------------------
int sub_51D8F0(float2* a1) {
	double v1;  // st7
	double v2;  // st6
	int v3;     // esi
	int v4;     // edi
	int v5;     // ebp
	int v6;     // edx
	int result; // eax
	int v8;     // [esp+10h] [ebp-20h]
	int v9;     // [esp+14h] [ebp-1Ch]
	int v10;    // [esp+18h] [ebp-18h]
	int v11;    // [esp+1Ch] [ebp-14h]
	int v12;    // [esp+20h] [ebp-10h]
	char v13;   // [esp+24h] [ebp-Ch]
	int v14;    // [esp+28h] [ebp-8h]
	int v15;    // [esp+2Ch] [ebp-4h]
	float v16;  // [esp+34h] [ebp+4h]

	v9 = dword_5d4594_3835348;
	v1 = a1->field_0 + 11.5;
	v8 = *getMemU32Ptr(0x973F18, 35912);
	v10 = 0;
	v13 = 0;
	v11 = -1;
	v12 = -1;
	v14 = 255;
	v15 = 0;
	v2 = a1->field_4 + 11.5;
	v3 = (long long)(v1 * 0.021739131);
	v16 = v2;
	v4 = (long long)(v2 * 0.021739131);
	v5 = (int)(long long)v1 % 46;
	v6 = (long long)v16 % 46;
	if (*getMemU32Ptr(0x973F18, 35912) == 255) {
		result = sub_51D9C0(v3, v4, v5, v6, 0);
	} else {
		result = sub_51D9C0(v3, v4, v5, v6, (int)&v8);
	}
	return result;
}

//----- (0051D9C0) --------------------------------------------------------
int sub_51D9C0(int a1, int a2, int a3, int a4, int a5) {
	int result; // eax

	if (a1 - 1 <= 0 || a1 >= 127 || a2 - 1 <= 0 || a2 >= 127) {
		return 0;
	}
	if (a3 <= a4) {
		if (46 - a3 <= a4) {
			result = sub_51DA70(a1, a2, a5, 2, 0);
		} else {
			result = sub_51DA70(a1 - 1, a2, a5, 1, 0);
		}
	} else if (46 - a3 <= a4) {
		result = sub_51DA70(a1, a2, a5, 1, 0);
	} else {
		result = sub_51DA70(a1, a2 - 1, a5, 2, 0);
	}
	return result;
}
