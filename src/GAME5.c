#include <float.h>
#include <math.h>
#include <stdio.h>

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2_2.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "common__random.h"
#include "common__crypt.h"
#include "operators.h"
#include "server__dbase__objdb.h"
#include "server__script__script.h"
#include "common__system__team.h"

#include "client__gui__window.h"
#include "client__video__draw_common.h"
extern uint32_t dword_5d4594_2491716;
extern uint32_t dword_5d4594_2490504;
extern void* nox_alloc_hit_2491548;
extern uint32_t dword_5d4594_2491580;
extern uint32_t dword_587000_292488;
extern uint32_t dword_5d4594_2491676;
extern uint32_t dword_5d4594_2491588;
extern uint32_t dword_5d4594_2491592;
extern uint32_t dword_5d4594_2491704;
extern uint32_t dword_5d4594_2490508;
extern uint32_t dword_5d4594_2489460;
extern uint32_t dword_5d4594_2491544;
extern uint32_t dword_5d4594_2491552;
extern uint32_t dword_5d4594_2491616;
extern uint32_t dword_587000_292492;
extern nox_object_t* nox_xxx_host_player_unit_3843628;
extern uint32_t dword_5d4594_2495920;
extern uint32_t dword_5d4594_2650652;
extern uint32_t nox_player_netCode_85319C;
extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;
extern nox_net_struct_t* nox_net_struct_arr[NOX_NET_STRUCT_MAX];
extern nox_net_struct2_t nox_net_struct2_arr[NOX_NET_STRUCT_MAX];

nox_alloc_class* nox_alloc_gQueue_3844300 = 0;

//-------------------------------------------------------------------------
// Function declarations

//----- (00545020) --------------------------------------------------------
char nox_xxx_mobActionRandomWalk_545020(int a1) {
	int v1;    // edi
	short v2;  // ax
	int v3;    // ecx
	double v4; // st7
	int v5;    // eax

	v1 = *(uint32_t*)(a1 + 748);
	v2 = sub_545090(a1);
	*(uint16_t*)(a1 + 124) = v2;
	*(uint16_t*)(a1 + 126) = v2;
	v3 = *(uint32_t*)(v1 + 1440);
	if (v3 & 0x4000) {
		v4 = *(float*)(*(uint32_t*)(v1 + 484) + 96) * *(float*)(a1 + 544);
	} else {
		v4 = *(float*)(a1 + 544);
	}
	v5 = 8 * v2;
	*(float*)(a1 + 88) = v4 * *getMemFloatPtr(0x587000, 194136 + v5);
	*(float*)(a1 + 92) = v4 * *getMemFloatPtr(0x587000, 194140 + v5);
	return nox_xxx_monsterMoveAudio_534030(a1);
}

//----- (00545090) --------------------------------------------------------
int sub_545090(int a1) {
	int v1;    // esi
	int v2;    // ecx
	float2 v4; // [esp+4h] [ebp-8h]

	v1 = *(short*)(a1 + 124) + nox_common_randomInt_415FA0(-20, 20);
	if (v1 < 0) {
		v1 += (unsigned int)(255 - v1) >> 8 << 8;
	}
	if (v1 >= 256) {
		v1 += -256 * ((unsigned int)v1 >> 8);
	}
	v2 = *(uint32_t*)(a1 + 12);
	if (!(v2 & 0x400)) {
		v4.field_0 = *getMemFloatPtr(0x587000, 194136 + 8 * v1) * 30.0 + *(float*)(a1 + 56);
		v4.field_4 = *getMemFloatPtr(0x587000, 194140 + 8 * v1) * 30.0 + *(float*)(a1 + 60);
		if (nox_xxx_tileNFromPoint_411160(&v4) == 6) {
			v1 += 64;
		}
		if (v1 >= 256) {
			v1 += -256 * ((unsigned int)v1 >> 8);
		}
	}
	return v1;
}

//----- (00545140) --------------------------------------------------------
char nox_xxx_mobActionConfuse_545140(int a1) {
	int* v1;   // eax
	double v2; // st7

	if (nox_common_randomInt_415FA0(0, 100) >= 15) {
		LOBYTE(v1) = nox_xxx_mobActionRandomWalk_545020(a1);
		return (char)v1;
	}
	if (nox_xxx_monsterCanMelee_534220(a1)) {
		if (!nox_xxx_monsterCanShoot_534280(a1) || nox_common_randomInt_415FA0(0, 100) < 50) {
			LOBYTE(v1) = (unsigned int)nox_xxx_monsterPushAction_50A260(a1, 16);
			return (char)v1;
		}
	} else {
		v1 = (int*)nox_xxx_monsterCanShoot_534280(a1);
		if (!v1) {
			return (char)v1;
		}
	}
	v1 = nox_xxx_monsterPushAction_50A260(a1, 17);
	if (v1) {
		*((float*)v1 + 1) = *getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a1 + 124)) * 10.0 + *(float*)(a1 + 56);
		v2 = *getMemFloatPtr(0x587000, 194140 + 8 * *(short*)(a1 + 124)) * 10.0 + *(float*)(a1 + 60);
		v1[3] = 0;
		*((float*)v1 + 2) = v2;
	}
	return (char)v1;
}

//----- (00545210) --------------------------------------------------------
char sub_545210(int a1) {
	return sub_545240(a1, (float*)(*(uint32_t*)(a1 + 748) + 24 * *(char*)(*(uint32_t*)(a1 + 748) + 544) + 556));
}

//----- (00545240) --------------------------------------------------------
char sub_545240(int a1, float* a2) {
	int v2;    // esi
	double v3; // st7
	double v4; // st6
	int v5;    // eax
	double v6; // st7
	int v7;    // eax
	float2 v9;
	float v11; // [esp+10h] [ebp+4h]

	v2 = a1;
	v3 = *a2 - *(float*)(a1 + 56);
	v4 = a2[1] - *(float*)(a1 + 60);
	v5 = *(short*)(a1 + 124);
	v9.field_4 = v4;
	v11 = sqrt(v4 * v9.field_4 + v3 * v3) + 0.001;
	v9.field_0 = v3 / v11;
	v6 = v9.field_4 / v11;
	v9.field_4 = v6;
	if (v6 * *getMemFloatPtr(0x587000, 194136 + 8 * v5) - v9.field_0 * *getMemFloatPtr(0x587000, 194140 + 8 * v5) >=
		0.0) {
		*(uint16_t*)(v2 + 126) += 8;
	} else {
		*(uint16_t*)(v2 + 126) -= 8;
	}
	for (; *(uint16_t*)(v2 + 126) < 0; *(uint16_t*)(v2 + 126) += 256) {
		;
	}
	for (; *(uint16_t*)(v2 + 126) >= 256; *(uint16_t*)(v2 + 126) -= 256) {
		;
	}
	v7 = sub_534120(v2, &v9);
	if (v7) {
		LOBYTE(v7) = nox_xxx_monsterPopAction_50A160(v2);
	}
	return v7;
}

//----- (00545300) --------------------------------------------------------
char sub_545300(int a1) {
	int v1;      // eax
	char result; // al

	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 24 * (*(char*)(*(uint32_t*)(a1 + 748) + 544) + 23) + 4);
	if (v1) {
		result = sub_545240(a1, (float*)(v1 + 56));
	} else {
		result = nox_xxx_monsterPopAction_50A160(a1);
	}
	return result;
}

//----- (00545340) --------------------------------------------------------
char sub_545340(int a1) {
	float* v1;  // ecx
	int v2;     // eax
	float2* v3; // edx
	int v4;     // eax

	v1 = getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a1 + 124));
	v2 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 24 * *(char*)(*(uint32_t*)(a1 + 748) + 544) + 556);
	v3 = (float2*)getMemAt(0x587000, 194136 + 8 * v2);
	if (*getMemFloatPtr(0x587000, 194140 + 8 * v2) * *v1 - v1[1] * v3->field_0 >= 0.0) {
		*(uint16_t*)(a1 + 126) += 8;
	} else {
		*(uint16_t*)(a1 + 126) -= 8;
	}
	for (; *(uint16_t*)(a1 + 126) < 0; *(uint16_t*)(a1 + 126) += 256) {
		;
	}
	for (; *(uint16_t*)(a1 + 126) >= 256; *(uint16_t*)(a1 + 126) -= 256) {
		;
	}
	v4 = sub_534120(a1, v3);
	if (v4) {
		LOBYTE(v4) = nox_xxx_monsterPopAction_50A160(a1);
	}
	return v4;
}

//----- (005453E0) --------------------------------------------------------
char sub_5453E0(int a1) {
	short v1; // cx

	v1 = *(uint16_t*)(*(uint32_t*)(a1 + 748) + 24 * *(char*)(*(uint32_t*)(a1 + 748) + 544) + 556);
	for (*(uint16_t*)(a1 + 126) = v1; *(uint16_t*)(a1 + 126) < 0; *(uint16_t*)(a1 + 126) += 256) {
		;
	}
	for (; *(uint16_t*)(a1 + 126) >= 256; *(uint16_t*)(a1 + 126) -= 256) {
		;
	}
	*(uint16_t*)(a1 + 124) = *(uint16_t*)(a1 + 126);
	return nox_xxx_monsterPopAction_50A160(a1);
}

//----- (00545440) --------------------------------------------------------
char nox_xxx_mobActionRetreat_545440(int a1) {
	int v1;  // ebx
	int* v2; // eax
	int* v3; // edi
	int v4;  // ecx
	int v5;  // ecx

	v1 = *(uint32_t*)(a1 + 748);
	if (sub_545580(a1)) {
		if (*(uint32_t*)(v1 + 1196)) {
			if (nox_xxx_testUnitBuffs_4FF350(a1, 29) || (v2 = (int*)nox_xxx_mobCastRelated_541050(a1)) == 0) {
				v3 = nox_xxx_monsterPushAction_50A260(a1, 41);
				if (v3) {
					v3[1] = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(4 * nox_gameFPS, 6 * nox_gameFPS);
				}
				v2 = nox_xxx_monsterPushAction_50A260(a1, 24);
				if (v2) {
					v4 = *(uint32_t*)(v1 + 1196);
					v2[1] = *(uint32_t*)(v4 + 56);
					v5 = *(uint32_t*)(v4 + 60);
					v2[3] = 0;
					v2[2] = v5;
				}
			}
		} else {
			v2 = (int*)nox_xxx_monsterCanResumeAttack_545520(a1);
			if (!v2) {
				LOBYTE(v2) = (unsigned int)nox_xxx_mobRetreatCheckEdibles_5455E0(a1);
			}
		}
	} else {
		LOBYTE(v2) = nox_xxx_monsterPopAction_50A160(a1);
	}
	return (char)v2;
}

//----- (00545520) --------------------------------------------------------
int nox_xxx_monsterCanResumeAttack_545520(int a1) {
	unsigned short* v1; // ecx
	double v2;          // st7

	v1 = *(unsigned short**)(a1 + 556);
	if (v1[2]) {
		v2 = (double)*v1 / (double)v1[2];
	} else {
		v2 = 1.0;
	}
	return v2 >= *(float*)(*(uint32_t*)(a1 + 748) + 1344);
}

//----- (00545580) --------------------------------------------------------
int sub_545580(int a1) {
	int result; // eax

	if (!nox_xxx_monsterCanResumeAttack_545520(a1) || (result = nox_xxx_monsterCanCast2_5455B0(a1))) {
		result = 1;
	}
	return result;
}

//----- (005455B0) --------------------------------------------------------
int nox_xxx_monsterCanCast2_5455B0(int a1) {
	return *(uint8_t*)(*(uint32_t*)(a1 + 748) + 1440) & 0x20 && nox_xxx_testUnitBuffs_4FF350(a1, 29);
}

//----- (005455E0) --------------------------------------------------------
int* nox_xxx_mobRetreatCheckEdibles_5455E0(int a1) {
	int v1;      // edi
	int* v2;     // eax
	int* v3;     // eax
	int* result; // eax
	int v5;      // edx
	int v6;      // [esp-4h] [ebp-Ch]

	if (nox_common_gameFlags_check_40A5C0(4096)) {
		v6 = 1142947840;
	} else {
		v6 = 1132068864;
	}
	v1 = nox_xxx_mobSearchEdible_544A00(a1, *(float*)&v6);
	if (v1) {
		nox_xxx_monsterPushAction_50A260(a1, 64);
		nox_xxx_monsterPushAction_50A260(a1, 56);
		v2 = nox_xxx_monsterPushAction_50A260(a1, 48);
		if (v2) {
			v2[1] = *(uint32_t*)(v1 + 56);
			v2[2] = *(uint32_t*)(v1 + 60);
			v2[3] = v1;
		}
		v3 = nox_xxx_monsterPushAction_50A260(a1, 11);
		if (v3) {
			v3[1] = v1;
		}
		result = nox_xxx_monsterPushAction_50A260(a1, 7);
		if (result) {
			result[1] = *(uint32_t*)(v1 + 56);
			v5 = *(uint32_t*)(v1 + 60);
			result[3] = v1;
			result[2] = v5;
		}
	} else {
		nox_xxx_monsterPushAction_50A260(a1, 64);
		nox_xxx_monsterPushAction_50A260(a1, 56);
		nox_xxx_monsterPushAction_50A260(a1, 58);
		result = nox_xxx_monsterPushAction_50A260(a1, 10);
		if (result) {
			result[1] = 0;
			*((uint8_t*)result + 12) = -128;
		}
	}
	return result;
}

//----- (005456B0) --------------------------------------------------------
int sub_5456B0(int a1) { return sub_534750(a1); }

//----- (005456C0) --------------------------------------------------------
int sub_5456C0(int a1) { return sub_534780(a1); }

//----- (005456D0) --------------------------------------------------------
void sub_5456D0(int a1) {
	int v1;    // edi
	int v2;    // eax
	double v3; // st7
	double v4; // st6
	int* v5;   // eax
	int* v6;   // eax
	int v7;    // ecx

	v1 = *(uint32_t*)(a1 + 748);
	if (*(uint32_t*)(a1 + 508) && sub_545580(a1)) {
		v2 = *(uint32_t*)(a1 + 508);
		v3 = *(float*)(a1 + 56) - *(float*)(v2 + 56);
		v4 = *(float*)(a1 + 60) - *(float*)(v2 + 60);
		if ((*(float*)(v1 + 1316) + 30.0) * (*(float*)(v1 + 1316) + 30.0) < v4 * v4 + v3 * v3) {
			v5 = nox_xxx_monsterPushAction_50A260(a1, 49);
			if (v5) {
				v5[1] = *(uint32_t*)(v1 + 1316);
				v5[3] = *(uint32_t*)(a1 + 508);
			}
			v6 = nox_xxx_monsterPushAction_50A260(a1, 7);
			if (v6) {
				v7 = *(uint32_t*)(a1 + 508);
				v6[1] = *(uint32_t*)(v7 + 56);
				v6[2] = *(uint32_t*)(v7 + 60);
				v6[3] = *(uint32_t*)(a1 + 508);
			}
		}
	} else {
		nox_xxx_monsterPopAction_50A160(a1);
	}
}

//----- (00545790) --------------------------------------------------------
long long sub_545790(int a1) {
	int v1;           // ecx
	long long result; // rax

	v1 = 16;
	result = *(unsigned int*)(a1 + 748);
	do {
		--v1;
	} while (v1);
	*(uint32_t*)(result + 300) = 0;
	*(uint32_t*)(result + 364) = 0;
	return result;
}

//----- (005457C0) --------------------------------------------------------
int sub_5457C0(int a1) {
	int result; // eax

	result = *(uint32_t*)(a1 + 748);
	*(uint32_t*)(result + 24 * *(char*)(result + 544) + 556) = 0;
	return result;
}

//----- (005457E0) --------------------------------------------------------
char nox_xxx_mobActionRoam_5457E0(int* a1) {
	int* v1;           // esi
	int v2;            // ebp
	int* v3;           // eax
	int* v4;           // eax
	int* v5;           // eax
	int* v6;           // esi
	int v7;            // ecx
	int v8;            // edi
	int v9;            // eax
	int v10;           // eax
	int* v11;          // esi
	int v12;           // ecx
	double v13;        // st7
	double v14;        // st6
	int v15;           // eax
	int v16;           // eax
	int v17;           // eax
	int v19;           // [esp-4h] [ebp-14h]
	int v20;           // [esp-4h] [ebp-14h]
	int v21;           // [esp-4h] [ebp-14h]
	unsigned char v22; // [esp+14h] [ebp+4h]

	v1 = a1;
	v2 = a1[187];
	if (sub_5343C0((int)a1) || nox_xxx_monsterCanAttackAtWill_534390((int)a1)) {
		v3 = (int*)sub_545E60(a1);
		if (v3) {
			return (char)v3;
		}
	}
	if (*(uint32_t*)(v2 + 1440) & 0x20000 && !*(uint32_t*)(v2 + 1196) && nox_xxx_testUnitBuffs_4FF350((int)a1, 0) &&
		!((unsigned char)nox_frame_xxx_2598000 & 0x1F) && nox_common_randomInt_415FA0(0, 100) < 10) {
		v4 = nox_xxx_monsterPushAction_50A260((int)a1, 66);
		if (v4) {
			v4[1] = 1125515264;
		}
		v5 = nox_xxx_monsterPushAction_50A260((int)a1, 62);
		if (v5) {
			v5[1] = 0;
		}
		v3 = nox_xxx_monsterPushAction_50A260((int)a1, 1);
		v6 = v3;
		if (v3) {
			v3 = (int*)(nox_frame_xxx_2598000 + nox_gameFPS * nox_common_randomInt_415FA0(3, 10));
			v6[1] = (int)v3;
		}
		return (char)v3;
	}
	if (nox_xxx_monsterCanAttackAtWill_534390((int)a1)) {
		if (*(uint32_t*)(v2 + 1196)) {
			v3 = nox_xxx_monsterPushAction_50A260((int)a1, 15);
			if (v3) {
				v7 = *(uint32_t*)(v2 + 1196);
				v3[1] = *(uint32_t*)(v7 + 56);
				v3[2] = *(uint32_t*)(v7 + 60);
				v3[3] = nox_frame_xxx_2598000;
			}
			return (char)v3;
		}
		v3 = (int*)sub_5466F0(a1);
		if (v3) {
			return (char)v3;
		}
	}
	v8 = v2 + 24 * (*(char*)(v2 + 544) + 23);
	v22 = *(uint8_t*)(v2 + 24 * (*(char*)(v2 + 544) + 23) + 12);
	if (!sub_547EE0(*(uint32_t*)(v8 + 4), v22)) {
		*(uint32_t*)(v8 + 4) = 0;
	}
	if (!*(uint32_t*)(v8 + 4)) {
		v9 = sub_518740((float2*)v1 + 7, v22);
		*(uint32_t*)(v8 + 4) = v9;
		if (!v9 && *(char*)(v8 + 12) == -128) {
			*(uint32_t*)(v8 + 4) = sub_50CB20((int)v1, (float*)v1 + 14);
		}
		if (!*(uint32_t*)(v8 + 4)) {
			v19 = v1[9];
			v10 = nox_xxx_getUnitName_4E39D0((int)v1);
			nox_ai_debug_printf_5341A0("%d: %s(#%d) Cannot find any waypoints\n", nox_frame_xxx_2598000, v10, v19);
			nox_xxx_monsterPopAction_50A160((int)v1);
			v3 = nox_xxx_monsterPushAction_50A260((int)v1, 1);
			v11 = v3;
			if (v3) {
				v3 = (int*)(nox_frame_xxx_2598000 + nox_common_randomInt_415FA0((int)nox_gameFPS, 2 * nox_gameFPS));
				v11[1] = (int)v3;
			}
			return (char)v3;
		}
		sub_545B00(v2, *(uint32_t*)(v8 + 4));
	}
	v12 = *(uint32_t*)(v8 + 4);
	v13 = *(float*)(v12 + 8) - *((float*)v1 + 14);
	v14 = *(float*)(v12 + 12) - *((float*)v1 + 15);
	if (v14 * v14 + v13 * v13 <= 64.0) {
		v3 = (int*)nox_xxx_monsterRoamDeadEnd_545BB0((int)v1, *(uint32_t*)(v8 + 4));
		if (!v3) {
			return (char)v3;
		}
		*(uint32_t*)(v2 + 280) = 0;
	}
	if (!*(uint32_t*)(v2 + 8)) {
		nox_xxx_creatureSetDetailedPath_50D220((int)v1, *(uint32_t*)(v8 + 4) + 8);
	}
	if (*(uint8_t*)(v2 + 284) == 2) {
		v20 = v1[9];
		v15 = nox_xxx_getUnitName_4E39D0((int)v1);
		nox_ai_debug_printf_5341A0("%d: %s(#%d) Cannot compute path to waypoint, choosing other\n",
								   nox_frame_xxx_2598000, v15, v20);
		v16 = sub_545B60(v2, v22);
		if (!v16) {
			v21 = v1[9];
			v17 = nox_xxx_getUnitName_4E39D0((int)v1);
			nox_ai_debug_printf_5341A0("%d: %s(#%d) No previous waypoint, giving up.\n", nox_frame_xxx_2598000, v17,
									   v21);
			LOBYTE(v3) = nox_xxx_monsterPopAction_50A160((int)v1);
			return (char)v3;
		}
		v3 = (int*)nox_xxx_monsterRoamDeadEnd_545BB0((int)v1, v16);
		if (!v3) {
			return (char)v3;
		}
	}
	if (nox_xxx_creatureActuallyMove_50D3B0((float*)v1)) {
		*(uint32_t*)(v2 + 8) = 0;
	}
	LOBYTE(v3) = nox_xxx_monsterMoveAudio_534030((int)v1);
	return (char)v3;
}

//----- (00545B00) --------------------------------------------------------
void sub_545B00(int a1, int a2) {
	int v3;       // ecx
	uint32_t* v4; // edx
	int i;        // ecx

	v3 = *(uint32_t*)(a1 + 364) + 1;
	*(uint32_t*)(a1 + 364) = v3;
	if (v3 >= 16) {
		*(uint32_t*)(a1 + 364) = 0;
	}
	v4 = (uint32_t*)(a1 + 300);
	*(uint32_t*)(a1 + 4 * *(uint32_t*)(a1 + 364) + 300) = a2;
	for (i = 0; i < 16; ++i) {
		if (*v4 == a2 && i != *(uint32_t*)(a1 + 364)) {
			*v4 = 0;
		}
		++v4;
	}
}

//----- (00545B60) --------------------------------------------------------
int sub_545B60(int a1, unsigned char a2) {
	int v2; // ebx
	int v3; // esi
	int v4; // eax

	v2 = 1;
	while (1) {
		v3 = *(int*)(a1 + 364) - v2 + (*(int*)(a1 + 364) - v2 < 0 ? 0x10 : 0);
		v4 = *(uint32_t*)(a1 + 4 * v3 + 300);
		if (v4) {
			if (sub_547EE0(v4, a2)) {
				break;
			}
		}
		if (++v2 >= 16) {
			return 0;
		}
	}
	return *(uint32_t*)(a1 + 4 * v3 + 300);
}

//----- (00545BB0) --------------------------------------------------------
int nox_xxx_monsterRoamDeadEnd_545BB0(int a1, int a2) {
	int v2;           // esi
	unsigned char v3; // cl
	int v4;           // edi
	int v5;           // edi
	int result;       // eax
	int v7;           // eax
	int v8;           // [esp-4h] [ebp-14h]

	v2 = *(uint32_t*)(a1 + 748);
	v3 = *(uint8_t*)(v2 + 24 * (*(char*)(v2 + 544) + 23) + 12);
	v4 = v2 + 24 * (*(char*)(v2 + 544) + 23);
	*(uint32_t*)(v2 + 8) = 0;
	if (*(uint8_t*)(a2 + 476) && (*(uint32_t*)(v4 + 4) = sub_545C60(v2, a2, v3), *(uint8_t*)(a2 + 476)) &&
		(v5 = *(uint32_t*)(v4 + 4)) != 0) {
		sub_545B00(v2, v5);
		result = 1;
	} else {
		v8 = *(uint32_t*)(a1 + 36);
		v7 = nox_xxx_getUnitName_4E39D0(a1);
		nox_ai_debug_printf_5341A0("%d: %s(#%d) Reached dead end, giving up.\n", nox_frame_xxx_2598000, v7, v8);
		nox_xxx_monsterPopAction_50A160(a1);
		result = 0;
	}
	return result;
}

//----- (00545C60) --------------------------------------------------------
int sub_545C60(int a1, int a2, unsigned char a3) {
	int v3;        // edi
	int* v4;       // ebp
	int* v5;       // ebx
	int v6;        // esi
	int v7;        // eax
	uint32_t* v8;  // ecx
	int v9;        // ebp
	int v10;       // ecx
	int v11;       // edi
	int v12;       // esi
	int v13;       // eax
	int v14;       // ecx
	uint32_t* v15; // edx
	int v17;       // [esp+10h] [ebp-84h]
	int v18[32];   // [esp+14h] [ebp-80h]

	v3 = 0;
	v17 = 0;
	if (!*(uint8_t*)(a2 + 476)) {
		goto LABEL_27;
	}
	v4 = v18;
	v5 = (int*)(a2 + 92);
	do {
		v6 = *v5;
		if (sub_547EE0(*v5, a3)) {
			v7 = 0;
			v8 = (uint32_t*)(a1 + 300);
			do {
				if (v6 == *v8) {
					break;
				}
				++v7;
				++v8;
			} while (v7 < 16);
			if (v7 == 16) {
				*v4 = v6;
				++v4;
				++v17;
			}
		}
		++v3;
		v5 += 2;
	} while (v3 < *(unsigned char*)(a2 + 476));
	if (v17) {
		return v18[nox_common_randomInt_415FA0(0, v17 - 1)];
	}
LABEL_27:
	v9 = 0;
	while (1) {
		v10 = *(uint32_t*)(a1 + 364);
		v11 = v10 + v9 + 1;
		if (v11 >= 16) {
			v11 = v10 + v9 - 15;
		}
		v12 = *(uint32_t*)(a1 + 4 * v11 + 300);
		if (v12) {
			v13 = 0;
			v14 = *(unsigned char*)(a2 + 476);
			if (v14 > 0) {
				v15 = (uint32_t*)(a2 + 92);
				do {
					if (v12 == *v15) {
						break;
					}
					++v13;
					v15 += 2;
				} while (v13 < v14);
			}
			if (v13 != v14 && sub_547EE0(v12, a3)) {
				break;
			}
		}
		if (++v9 >= 16) {
			return 0;
		}
	}
	return *(uint32_t*)(a1 + 4 * v11 + 300);
}
// 545C60: using guessed type int var_80[32];

//----- (00545DA0) --------------------------------------------------------
int sub_545DA0(int a1) {
	uint32_t* v1; // edi
	int* v2;      // ebx
	int* v3;      // eax

	v1 = *(uint32_t**)(a1 + 748);
	if (!v1[97] || nox_frame_xxx_2598000 - v1[101] >= (unsigned int)(3 * nox_gameFPS)) {
		return 0;
	}
	nox_xxx_monsterPushAction_50A260(a1, 59);
	nox_xxx_monsterPushAction_50A260(a1, 56);
	v2 = nox_xxx_monsterPushAction_50A260(a1, 1);
	if (v2) {
		v2[1] = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0((int)nox_gameFPS, 2 * nox_gameFPS);
	}
	v3 = nox_xxx_monsterPushAction_50A260(a1, 25);
	if (v3) {
		v3[1] = v1[99];
		v3[2] = v1[100];
	}
	v1[97] = 0;
	return 1;
}

//----- (00546010) --------------------------------------------------------
int* nox_xxx_mobActionGuard_546010(int a1) {
	int v1;          // ebp
	int v2;          // edi
	int* result;     // eax
	int v4;          // ecx
	int v5;          // eax
	double v6;       // st7
	double v7;       // st6
	int* v8;         // eax
	int* v9;         // eax
	int* v10;        // eax
	int* v11;        // eax
	int v12;         // ecx
	double v13;      // st7
	double v14;      // st6
	int v15;         // edx
	int v16;         // edi
	int* v17;        // eax
	int v18;         // edx
	int v19;         // eax
	int v20;         // ecx
	double v21;      // st7
	long double v22; // st6
	float2 a2;       // [esp+10h] [ebp-8h]

	v1 = *(uint32_t*)(a1 + 748);
	v2 = v1 + 24 * (*(char*)(v1 + 544) + 23);
	if (sub_534440(a1) || (result = (int*)sub_545E60((int*)a1)) == 0) {
		if (*(uint32_t*)(v1 + 1196)) {
			if (nox_xxx_monsterCanAttackAtWill_534390(a1)) {
				result = nox_xxx_monsterPushAction_50A260(a1, 15);
				if (result) {
					v4 = *(uint32_t*)(v1 + 1196);
					result[1] = *(uint32_t*)(v4 + 56);
					result[2] = *(uint32_t*)(v4 + 60);
					result[3] = nox_frame_xxx_2598000;
				}
				return result;
			}
			if (sub_5343C0(a1)) {
				v5 = *(uint32_t*)(v1 + 1196);
				v6 = *(float*)(v2 + 4) - *(float*)(v5 + 56);
				v7 = *(float*)(v2 + 8) - *(float*)(v5 + 60);
				if (*(float*)(v1 + 1312) * *(float*)(v1 + 1312) > v7 * v7 + v6 * v6) {
					if (nox_xxx_unitIsPlant_534A10(a1)) {
						v8 = nox_xxx_monsterPushAction_50A260(a1, 63);
						if (v8) {
							*((float*)v8 + 1) = *(float*)(v1 + 1312) * 1.05;
						}
					} else {
						v9 = nox_xxx_monsterPushAction_50A260(a1, 43);
						if (v9) {
							v9[1] = 0;
						}
						v10 = nox_xxx_monsterPushAction_50A260(a1, 52);
						if (v10) {
							*((float*)v10 + 1) = *(float*)(v1 + 1312) * 1.5;
							v10[3] = *(uint32_t*)(v2 + 4);
							v10[4] = *(uint32_t*)(v2 + 8);
						}
						nox_xxx_monsterPushAction_50A260(a1, 40);
					}
					v11 = nox_xxx_monsterPushAction_50A260(a1, 15);
					if (v11) {
						v12 = *(uint32_t*)(v1 + 1196);
						v11[1] = *(uint32_t*)(v12 + 56);
						v11[2] = *(uint32_t*)(v12 + 60);
						v11[3] = nox_frame_xxx_2598000;
					}
				}
			}
		}
		if (nox_xxx_unitIsMimic_534840(a1) || (result = (int*)nox_xxx_monsterLookAtDamager_5466B0(a1)) == 0) {
			if (nox_xxx_monsterCanAttackAtWill_534390(a1)) {
				result = (int*)sub_5466F0((uint32_t*)a1);
				if (result) {
					return result;
				}
			} else if (!nox_xxx_unitIsMimic_534840(a1)) {
				result = (int*)sub_545DA0(a1);
				if (result) {
					return result;
				}
			}
			if (((unsigned char)nox_frame_xxx_2598000 + *(uint8_t*)(a1 + 36)) & 0xF) {
				goto LABEL_49;
			}
			v13 = *(float*)(v2 + 4) - *(float*)(a1 + 56);
			v14 = *(float*)(v2 + 8) - *(float*)(a1 + 60);
			if (v14 * v14 + v13 * v13 > 64.0) {
				if (nox_xxx_monsterCanAttackAtWill_534390(a1)) {
					nox_xxx_monsterPushAction_50A260(a1, 56);
					nox_xxx_monsterPushAction_50A260(a1, 59);
				}
				nox_xxx_monsterPushAction_50A260(a1, 44);
				result = nox_xxx_monsterPushAction_50A260(a1, 7);
				if (result) {
					result[1] = *(uint32_t*)(v2 + 4);
					v15 = *(uint32_t*)(v2 + 8);
					result[3] = 0;
					result[2] = v15;
				}
				return result;
			}
			if (nox_xxx_unitIsMimic_534840(a1)) {
				v16 = *(uint32_t*)(v2 + 12);
				if (!sub_534120(a1, (float2*)getMemAt(0x587000, 194136 + 8 * v16))) {
					v17 = nox_xxx_monsterPushAction_50A260(a1, 27);
					if (v17) {
						goto LABEL_48;
					}
				}
			} else {
				if (*(uint8_t*)(v1 + 1129) > 0u) {
					v16 = *(uint32_t*)(v1 + 1196);
					if (!v16) {
						v16 = *(uint32_t*)(v1 + 1132);
						v18 = v1 + 1132;
						v19 = 0;
						v20 = *(unsigned char*)(v1 + 1129);
						if (v20 > 0) {
							while (!(*(uint8_t*)(*(uint32_t*)v18 + 8) & 4)) {
								++v19;
								v18 += 4;
								if (v19 >= v20) {
									goto LABEL_43;
								}
							}
							v16 = *(uint32_t*)(v1 + 4 * v19 + 1132);
						}
					}
				LABEL_43:
					a2.field_0 = *(float*)(v16 + 56) - *(float*)(a1 + 56);
					v21 = *(float*)(v16 + 60) - *(float*)(a1 + 60);
					v22 = sqrt(v21 * v21 + a2.field_0 * a2.field_0) + 0.001;
					a2.field_0 = a2.field_0 / v22;
					a2.field_4 = v21 / v22;
					if (sub_534120(a1, &a2)) {
						goto LABEL_49;
					}
					v17 = nox_xxx_monsterPushAction_50A260(a1, 26);
					if (!v17) {
						goto LABEL_49;
					}
					goto LABEL_48;
				}
				v16 = *(uint32_t*)(v2 + 12);
				if (!sub_534120(a1, (float2*)getMemAt(0x587000, 194136 + 8 * v16))) {
					nox_xxx_monsterPushAction_50A260(a1, 56);
					v17 = nox_xxx_monsterPushAction_50A260(a1, 27);
					if (v17) {
					LABEL_48:
						v17[1] = v16;
						goto LABEL_49;
					}
				}
			}
		LABEL_49:
			if (nox_xxx_unitIsMimic_534840(a1) ||
				(unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(v1 + 548)) <= nox_gameFPS >> 1 ||
				*(float*)(a1 + 56) == *(float*)(a1 + 72) && *(float*)(a1 + 60) == *(float*)(a1 + 76)) {
				result = (int*)nox_xxx_testUnitBuffs_4FF350(a1, 29);
				if (!result) {
					result = (int*)nox_xxx_mobHealSomeone_5411A0(a1);
				}
			} else {
				result = nox_xxx_monsterPushAction_50A260(a1, 25);
				if (result) {
					result[1] = *(uint32_t*)(a1 + 72);
					result[2] = *(uint32_t*)(a1 + 76);
				}
			}
			return result;
		}
	}
	return result;
}

//----- (00546410) --------------------------------------------------------
int sub_546410(int a1) { return sub_534780(a1); }

//----- (00546420) --------------------------------------------------------
int sub_546420(int a1) { return sub_534780(a1); }

//----- (00546430) --------------------------------------------------------
char nox_xxx_mobActionEscort_546430(int* a1) {
	int v1;       // ebx
	uint32_t* v2; // edi
	int v3;       // eax
	int* v4;      // eax
	int v5;       // ecx
	int v6;       // eax
	double v7;    // st7
	double v8;    // st6
	int* v9;      // eax
	int v10;      // ecx

	v1 = a1[187];
	v2 = (uint32_t*)(v1 + 24 * (*(char*)(v1 + 544) + 23));
	if (!*(uint32_t*)(v1 + 24 * (*(char*)(v1 + 544) + 23) + 12)) {
		v3 = nox_xxx_monsterGetObjEscortName_546600((int)a1);
		v2[3] = v3;
		if (!v3) {
			LOBYTE(v4) = nox_xxx_monsterPopAction_50A160((int)a1);
			return (char)v4;
		}
		v2[1] = *(uint32_t*)(v3 + 56);
		v2[2] = *(uint32_t*)(v3 + 60);
	}
	if (nox_xxx_monsterCanAttackAtWill_534390((int)a1)) {
		if (*(uint32_t*)(v1 + 1196)) {
			v4 = nox_xxx_monsterPushAction_50A260((int)a1, 15);
			if (v4) {
				v5 = *(uint32_t*)(v1 + 1196);
				v4[1] = *(uint32_t*)(v5 + 56);
				v4[2] = *(uint32_t*)(v5 + 60);
				v4[3] = nox_frame_xxx_2598000;
			}
			return (char)v4;
		}
		v4 = (int*)nox_xxx_monsterLookAtDamager_5466B0((int)a1);
		if (v4) {
			return (char)v4;
		}
	} else if (sub_5343C0((int)a1)) {
		v4 = (int*)sub_545E60(a1);
		if (v4) {
			return (char)v4;
		}
		v4 = (int*)nox_xxx_monsterLookAtDamager_5466B0((int)a1);
		if (v4) {
			return (char)v4;
		}
	}
	v6 = v2[3];
	v7 = *((float*)a1 + 14) - *(float*)(v6 + 56);
	v8 = *((float*)a1 + 15) - *(float*)(v6 + 60);
	if ((*(float*)(v1 + 1316) + 30.0) * (*(float*)(v1 + 1316) + 30.0) >= v8 * v8 + v7 * v7) {
		if (!nox_xxx_monsterCanAttackAtWill_534390((int)a1) || (v4 = (int*)sub_5466F0(a1)) == 0) {
			v4 = (int*)nox_xxx_testUnitBuffs_4FF350((int)a1, 29);
			if (!v4) {
				LOBYTE(v4) = nox_xxx_mobHealSomeone_5411A0((int)a1);
			}
		}
	} else {
		if (sub_5343C0((int)a1) || nox_xxx_monsterCanAttackAtWill_534390((int)a1)) {
			nox_xxx_monsterPushAction_50A260((int)a1, 44);
		}
		if (nox_xxx_monsterCanAttackAtWill_534390((int)a1)) {
			nox_xxx_monsterPushAction_50A260((int)a1, 56);
		}
		v9 = nox_xxx_monsterPushAction_50A260((int)a1, 49);
		if (v9) {
			v9[1] = *(uint32_t*)(v1 + 1316);
			v9[3] = v2[3];
		}
		v4 = nox_xxx_monsterPushAction_50A260((int)a1, 7);
		if (v4) {
			v10 = v2[3];
			v4[1] = *(uint32_t*)(v10 + 56);
			v4[2] = *(uint32_t*)(v10 + 60);
			v4[3] = v2[3];
		}
	}
	return (char)v4;
}

//----- (00546600) --------------------------------------------------------
int nox_xxx_monsterGetObjEscortName_546600(int a1) {
	char* v1;   // ebx
	int v2;     // esi
	int i;      // eax
	int v4;     // esi
	int result; // eax
	int v6;     // ecx

	v1 = (char*)(*(uint32_t*)(a1 + 748) + 1364);
	if (!strcmp(v1, "**PLAYER**")) {
		v2 = 0;
		for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
			++v2;
		}
		v4 = nox_common_randomInt_415FA0(0, v2 - 1);
		result = nox_xxx_getFirstPlayerUnit_4DA7C0();
		if (result) {
			while (1) {
				v6 = v4--;
				if (!v6) {
					break;
				}
				result = nox_xxx_getNextPlayerUnit_4DA7F0(result);
				if (!result) {
					*v1 = 0;
					return result;
				}
			}
		}
	} else {
		if (!strcmp((const char*)(*(uint32_t*)(a1 + 748) + 1364), "**OWNER**")) {
			result = *(uint32_t*)(a1 + 508);
			*v1 = 0;
			return result;
		}
		result = nox_xxx_getObjectByScrName_4DA4F0((char*)(*(uint32_t*)(a1 + 748) + 1364));
	}
	*v1 = 0;
	return result;
}

//----- (005466B0) --------------------------------------------------------
int nox_xxx_monsterLookAtDamager_5466B0(int a1) {
	int* v1; // eax

	if (!sub_5347A0(a1)) {
		return 0;
	}
	v1 = nox_xxx_monsterPushAction_50A260(a1, 25);
	if (v1) {
		v1[1] = *(uint32_t*)(a1 + 528);
		v1[2] = *(uint32_t*)(a1 + 532);
	}
	return 1;
}

//----- (005466F0) --------------------------------------------------------
int sub_5466F0(uint32_t* a1) {
	int v1;    // ebx
	float* v2; // edi
	float v3;  // ecx
	float v4;  // eax
	float v5;  // ecx
	int* v6;   // eax
	int* v7;   // eax
	float4 v9; // [esp+8h] [ebp-10h]

	v1 = a1[187];
	if (!*(uint32_t*)(v1 + 388) || nox_frame_xxx_2598000 - *(uint32_t*)(v1 + 404) >= (unsigned int)(3 * nox_gameFPS)) {
		return 0;
	}
	if (sub_534020((int)a1) || nox_xxx_tileNFromPoint_411160((float2*)(v1 + 396)) != 6) {
		v2 = (float*)(v1 + 396);
		if (sub_50B810((int)a1, (float*)(v1 + 396))) {
			v3 = *((float*)a1 + 14);
			v4 = *v2;
			v9.field_4 = *((float*)a1 + 15);
			v9.field_0 = v3;
			v5 = *(float*)(v1 + 400);
			v9.field_8 = v4;
			v9.field_C = v5;
			if (nox_xxx_mapTraceRay_535250(&v9, 0, 0, 9)) {
				sub_545DA0((int)a1);
			} else {
				nox_xxx_monsterPushAction_50A260((int)a1, 59);
				nox_xxx_monsterPushAction_50A260((int)a1, 56);
				nox_xxx_monsterPushAction_50A260((int)a1, 70);
				v6 = nox_xxx_monsterPushAction_50A260((int)a1, 69);
				if (v6) {
					v6[1] = *(uint32_t*)v2;
					v6[2] = *(uint32_t*)(v1 + 400);
				}
				v7 = nox_xxx_monsterPushAction_50A260((int)a1, 7);
				if (v7) {
					v7[1] = *(uint32_t*)v2;
					v7[2] = *(uint32_t*)(v1 + 400);
					v7[3] = 0;
				}
			}
		}
	}
	*(uint32_t*)(v1 + 388) = 0;
	return 1;
}

//----- (00546820) --------------------------------------------------------
int nox_xxx_monsterIdleStarted_546820(int a1) {
	int result; // eax

	result = *(uint32_t*)(a1 + 748);
	*(uint32_t*)(result + 24 * *(char*)(result + 544) + 556) = nox_frame_xxx_2598000;
	return result;
}

//----- (00546850) --------------------------------------------------------
int* nox_xxx_monsterUpdateIdleLogic_546850(int a1) {
	int v1;      // edi
	int* result; // eax
	int v3;      // ecx

	v1 = *(uint32_t*)(a1 + 748);
	if (nox_frame_xxx_2598000 - *(uint32_t*)(v1 + 24 * *(char*)(v1 + 544) + 556) == *(short*)(v1 + 1220)) {
		nox_xxx_scriptCallByEventBlock_502490((int*)(v1 + 1224), 0, a1, 5);
	}
	if (!(*(uint32_t*)(a1 + 16) & 0x1000000)) {
		goto LABEL_23;
	}
	if (sub_5343C0(a1) || nox_xxx_monsterCanAttackAtWill_534390(a1)) {
		if (*(uint32_t*)(v1 + 1196)) {
			result = nox_xxx_monsterPushAction_50A260(a1, 15);
			if (result) {
				v3 = *(uint32_t*)(v1 + 1196);
				result[1] = *(uint32_t*)(v3 + 56);
				result[2] = *(uint32_t*)(v3 + 60);
				result[3] = nox_frame_xxx_2598000;
			}
			return result;
		}
		result = (int*)sub_5466F0((uint32_t*)a1);
		if (result) {
			return result;
		}
	}
	if (sub_534440(a1) || (result = (int*)sub_545E60((int*)a1)) == 0) {
	LABEL_23:
		if (nox_xxx_unitIsMimic_534840(a1)) {
			goto LABEL_24;
		}
		result = (int*)nox_xxx_monsterLookAtDamager_5466B0(a1);
		if (result) {
			return result;
		}
		if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(v1 + 548)) <= (int)nox_gameFPS >> 1 ||
			*(float*)(a1 + 56) == *(float*)(a1 + 72) && *(float*)(a1 + 60) == *(float*)(a1 + 76)) {
		LABEL_24:
			result = (int*)nox_xxx_testUnitBuffs_4FF350(a1, 29);
			if (!result) {
				result = (int*)nox_xxx_mobHealSomeone_5411A0(a1);
			}
		} else {
			result = nox_xxx_monsterPushAction_50A260(a1, 25);
			if (result) {
				result[1] = *(uint32_t*)(a1 + 72);
				result[2] = *(uint32_t*)(a1 + 76);
			}
		}
	}
	return result;
}

//----- (005469B0) --------------------------------------------------------
void nox_xxx_mobAction_5469B0(int a1) {
	int v1; // edi
	int v2; // eax
	int v3; // eax

	v1 = *(uint32_t*)(a1 + 748);
	if (*(uint8_t*)(a1 + 8) & 2) {
		if (!nox_xxx_monsterCanAttackAtWill_534390(a1) && !*(uint32_t*)(v1 + 1196) && *(float*)(v1 + 524) <= 300.0) {
			v2 = nox_xxx_mobActionGet_50A020(a1);
			if ((!v2 || v2 == 4) && nox_frame_xxx_2598000 >= *(int*)(v1 + 528)) {
				*(uint32_t*)(v1 + 528) =
					nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(20 * nox_gameFPS, 60 * nox_gameFPS);
				v3 = nox_xxx_monsterGetSoundSet_424300(a1);
				if (v3) {
					nox_xxx_aud_501960(*(uint32_t*)(v3 + 16), a1, 0, 0);
				}
			}
		}
	}
}

//----- (00547120) --------------------------------------------------------
short nox_xxx_unitIsDangerous_547120(int a1, int a2) {
	int v2; // edx
	int v3; // eax

	if (!*getMemU32Ptr(0x5D4594, 2489468)) {
		*getMemU32Ptr(0x5D4594, 2489468) = nox_xxx_getNameId_4E3AA0("ToxicCloud");
		*getMemU32Ptr(0x5D4594, 2489472) = nox_xxx_getNameId_4E3AA0("SmallToxicCloud");
	}
	v2 = *(uint32_t*)(a1 + 8);
	if (v2 & 0x2000) {
		v3 = sub_534020(a2);
		if (!v3) {
			dword_5d4594_2489460 = 0;
		}
	} else {
		v3 = *(unsigned short*)(a1 + 4);
		if ((unsigned short)v3 == *getMemU32Ptr(0x5D4594, 2489468) || v3 == *getMemU32Ptr(0x5D4594, 2489472)) {
			v3 = *(uint32_t*)(a2 + 12);
			if (!(v3 & 0x200)) {
				dword_5d4594_2489460 = 0;
			}
		} else if (v2 & 0x10000) {
			dword_5d4594_2489460 = 0;
		}
	}
	return v3;
}

//----- (005471B0) --------------------------------------------------------
void nox_xxx_monsterPopAttackActions_5471B0(int a1) {
	int v1; // esi
	v1 = *(uint32_t*)(a1 + 748);
	while (1) {
		switch (*(uint32_t*)(v1 + 24 * (*(char*)(v1 + 544) + 23))) {
		case 0x10:
		case 0x11:
		case 0x12:
		case 0x13:
		case 0x14:
		case 0x19:
		case 0x1A:
		case 0x1B:
		case 0x1C:
			nox_xxx_monsterPopAction_50A160(a1);
			break;
		default:
			return;
		}
	}
}

//----- (00547210) --------------------------------------------------------
char nox_xxx_monsterMainAIFn_547210(int a1) {
	int v1;          // esi
	int v2;          // ebp
	int* v3;         // eax
	int** v4;        // ecx
	int* v5;         // ecx
	uint32_t* v6;    // ecx
	uint32_t* v7;    // edi
	int v8;          // eax
	double v9;       // st7
	double v10;      // st6
	int v11;         // eax
	int* v12;        // eax
	int* v13;        // eax
	int* v14;        // eax
	int* v15;        // eax
	int* v16;        // eax
	int v17;         // eax
	int v18;         // eax
	int v19;         // ecx
	long double v20; // st7
	int v21;         // ecx
	int v22;         // edx
	int* v23;        // eax
	int* v24;        // eax
	int* v25;        // eax
	int v26;         // edx
	int v27;         // edx
	int v28;         // ecx
	int v29;         // eax
	int** v30;       // edi
	int* v31;        // eax
	double v32;      // st7
	double v33;      // st6
	int v34;         // eax
	int* v35;        // edi
	int v36;         // edi
	int v37;         // edi
	int v39;         // [esp-4h] [ebp-28h]
	int** v40;       // [esp+10h] [ebp-14h]
	float v41;       // [esp+14h] [ebp-10h]
	float v42;       // [esp+14h] [ebp-10h]
	int v43[3];      // [esp+18h] [ebp-Ch]
	int* v44;        // [esp+28h] [ebp+4h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 748);
	v3 = (int*)*(char*)(v2 + 544);
	v4 = (int**)(v2 + 8 * (3 * (uint32_t)v3 + 69));
	v40 = v4;
	v5 = *v4;
	if ((!v5 || v5 == (int*)4) &&
		((unsigned char)nox_frame_xxx_2598000 + *(uint8_t*)(a1 + 36) - *(uint8_t*)(v2 + 548)) & 0xF) {
		return (char)v3;
	}
	v3 = (int*)((char*)v3 - 1);
	if ((int)v3 < 0) {
	LABEL_8:
		v3 = *(int**)(a1 + 16);
		if (SBYTE1(v3) < 0) {
			return (char)v3;
		}
		v44 = (int*)nox_xxx_monsterGetSoundSet_424300(a1);
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			if (!nox_xxx_guiCursor_477600()) {
				if (*(uint8_t*)(v1 + 20) & 0x10) {
					if (nox_xxx_host_player_unit_3843628) {
						if (!(*(uint8_t*)((uint32_t)nox_xxx_host_player_unit_3843628 + 16) & 2) &&
							!nox_xxx_checkMobAction_50A0D0(v1, 2)) {
							v7 = *(uint32_t**)((uint32_t)nox_xxx_host_player_unit_3843628 + 748);
							v8 = v7[69];
							v9 = (double)*(int*)(v8 + 2284) - *(float*)(v1 + 56);
							v10 = (double)*(int*)(v8 + 2288) - *(float*)(v1 + 60);
							if (v10 * v10 + v9 * v9 < 100.0 &&
								nox_xxx_findObjectAtCursor_54AF40(*(int*)&nox_xxx_host_player_unit_3843628) == v1) {
								v11 = *(uint32_t*)(v1 + 60);
								*(uint32_t*)(v1 + 72) = *(uint32_t*)(v1 + 56);
								*(uint32_t*)(v1 + 92) = 0;
								*(uint32_t*)(v1 + 88) = 0;
								*(uint32_t*)(v1 + 100) = 0;
								*(uint32_t*)(v1 + 96) = 0;
								*(uint32_t*)(v1 + 84) = 0;
								*(uint32_t*)(v1 + 80) = 0;
								*(uint32_t*)(v1 + 76) = v11;
								nox_xxx_monsterPushAction_50A260(v1, 71);
								v12 = nox_xxx_monsterPushAction_50A260(v1, 2);
								if (v12) {
									v12[1] = nox_gameFPS;
								}
								nox_xxx_monsterPushAction_50A260(v1, 67);
								v13 = nox_xxx_monsterPushAction_50A260(v1, 2);
								if (v13) {
									v13[1] = 999999;
								}
								v3 = nox_xxx_monsterPushAction_50A260(v1, 26);
								if (v3) {
									v3[1] = nox_xxx_host_player_unit_3843628;
								}
								if (!v7[71] && !v7[70]) {
									LOBYTE(v3) = (uint8_t)v44;
									if (v44) {
										LOBYTE(v3) = (unsigned int)nox_xxx_aud_501960(v44[1], v1, 0, 0);
									}
								}
								return (char)v3;
							}
						}
					}
				}
			}
		}
		if (nox_xxx_testUnitBuffs_4FF350(v1, 3) && !nox_xxx_checkMobAction_50A0D0(v1, 36)) {
			v14 = nox_xxx_monsterPushAction_50A260(v1, 62);
			v40 = (int**)v14;
			if (v14) {
				v14[1] = 3;
			}
			nox_xxx_monsterPushAction_50A260(v1, 36);
		}
		if (nox_xxx_testUnitBuffs_4FF350(v1, 29) || (v3 = (int*)nox_xxx_mobCastInversion_5408D0(v1)) == 0) {
			if (nox_xxx_testUnitBuffs_4FF350(v1, 11) && nox_xxx_monsterIsMoveing_534320(v1) &&
				!nox_xxx_checkMobAction_50A0D0(v1, 24)) {
				v15 = nox_xxx_monsterPushAction_50A260(v1, 62);
				if (v15) {
					v15[1] = 11;
				}
				v16 = nox_xxx_monsterPushAction_50A260(v1, 24);
				if (v16) {
					v16[1] = *(uint32_t*)(v1 + 56);
					v16[2] = *(uint32_t*)(v1 + 60);
					v16[3] = 0;
				}
				LOBYTE(v3) = (uint8_t)v44;
				if (v44) {
					LOBYTE(v3) = (unsigned int)nox_xxx_aud_501960(v44[12], v1, 0, 0);
				}
				return (char)v3;
			}
			if (!((unsigned char)nox_frame_xxx_2598000 & 0xF) &&
				(sub_5343C0(v1) || nox_xxx_monsterCanAttackAtWill_534390(v1))) {
				if (nox_xxx_checkMobAction_50A0D0(v1, 4)) {
					if (nox_xxx_mobActionGet_50A020(v1) != 4 && !nox_xxx_checkMobAction_50A0D0(v1, 15)) {
						v17 = nox_xxx_enemyAggro_5335D0(v1, 100.0);
						if (v17) {
							if (*(uint8_t*)(v17 + 8) & 6) {
								v18 = *(uint32_t*)(v2 + 1440);
								v19 = *(uint32_t*)(v2 + 1196);
								BYTE1(v18) |= 2u;
								*(uint32_t*)(v2 + 1440) = v18;
								*(uint32_t*)(v1 + 520) = v19;
								*(uint32_t*)(v1 + 524) = 11;
								*(uint32_t*)(v1 + 536) = nox_frame_xxx_2598000;
							}
						}
					}
				}
			}
			if (!sub_534440(v1)) {
				if (nox_xxx_monsterIsMoveing_534320(v1)) {
					if (!sub_5408A0(v1) && !nox_xxx_testUnitBuffs_4FF350(v1, 3) &&
						!nox_xxx_mobGetMoveAttemptTime_534810(v1)) {
						if (*(uint32_t*)(v2 + 1196)) {
							v20 = nox_xxx_calcDistance_4E6C00(v1, *(uint32_t*)(v2 + 1196));
							if (v20 < *(float*)(v2 + 1356)) {
								if (*(uint8_t*)(v2 + 1440) & 0x20) {
									if (*(uint32_t*)(v2 + 1504)) {
										if (!nox_xxx_testUnitBuffs_4FF350(v1, 29) &&
											nox_frame_xxx_2598000 >= *(int*)(v2 + 1484)) {
											v41 = v20;
											if (*(float*)(v2 + 1356) * 0.5 > v41) {
												v21 = *(uint32_t*)(v1 + 56);
												v22 = *(uint32_t*)(v1 + 60);
												v43[0] = v1;
												v43[1] = v21;
												v43[2] = v22;
												nox_xxx_mobCast_541300(4, (uint32_t*)v1, (int)v43);
												v3 = (int*)(nox_frame_xxx_2598000 +
															nox_common_randomInt_415FA0(*(unsigned short*)(v2 + 1480),
																						*(unsigned short*)(v2 + 1482)));
												*(uint32_t*)(v2 + 1484) = v3;
												return (char)v3;
											}
										}
									}
								}
								if (!nox_xxx_checkMobAction_50A0D0(v1, 24) && *(float*)(v2 + 1356) != 0.0) {
									v23 = nox_xxx_monsterPushAction_50A260(v1, 28);
									if (v23) {
										v23[1] = *(short*)(v1 + 124) + 128;
									}
									nox_xxx_monsterPushAction_50A260(v1, 68);
									v24 = nox_xxx_monsterPushAction_50A260(v1, 63);
									if (v24) {
										*((float*)v24 + 1) = *(float*)(v2 + 1356) + 30.0;
									}
									v25 = nox_xxx_monsterPushAction_50A260(v1, 24);
									if (v25) {
										v26 = *(uint32_t*)(v2 + 1196);
										v25[1] = *(uint32_t*)(v26 + 56);
										v27 = *(uint32_t*)(v26 + 60);
										v25[3] = 0;
										v25[2] = v27;
									}
									v3 = (int*)nox_common_randomInt_415FA0(0, 1);
									if (v3) {
										LOBYTE(v3) = (uint8_t)v44;
										if (v44) {
											LOBYTE(v3) = (unsigned int)nox_xxx_aud_501960(v44[12], v1, 0, 0);
										}
									}
									return (char)v3;
								}
							}
						}
					}
				}
			}
			if (*(uint16_t*)(*(uint32_t*)(v1 + 556) + 4) && nox_xxx_monsterIsMoveing_534320(v1) &&
				!nox_xxx_mobGetMoveAttemptTime_534810(v1) && !nox_xxx_checkMobAction_50A0D0(v1, 24) &&
				!nox_xxx_checkMobAction_50A0D0(v1, 6) && !nox_xxx_checkMobAction_50A0D0(v1, 14)) {
				v42 = (double)**(unsigned short**)(v1 + 556) / (double)*(unsigned short*)(*(uint32_t*)(v1 + 556) + 4);
				v28 = *(uint8_t*)(v2 + 1440) & 0x20 && nox_xxx_testUnitBuffs_4FF350(v1, 29);
				if (v42 <= (double)*(float*)(v2 + 1336) || v28) {
					nox_xxx_monsterPopAttackActions_5471B0(v1);
					nox_xxx_monsterPushAction_50A260(v1, 68);
					if (((*(uint8_t*)(v2 + 1440) & 0x80) || *(uint8_t*)(v1 + 12) & 0x80) &&
						nox_common_gameFlags_check_40A5C0(2048)) {
						nox_xxx_monsterPushAction_50A260(v1, 14);
					} else {
						nox_xxx_monsterPushAction_50A260(v1, 6);
					}
					if (v44) {
						nox_xxx_aud_501960(v44[13], v1, 0, 0);
					}
					LOBYTE(v3) = (unsigned int)nox_xxx_scriptCallByEventBlock_502490((int*)(v2 + 1256), 0, v1, 4);
					return (char)v3;
				}
			}
			if (*(uint8_t*)(v1 + 12) & 0x10 && (v29 = *(uint32_t*)(v2 + 2056), BYTE1(v29) & 4)) {
				v30 = v40;
				if (*v40 != (int*)16 && *v40 != (int*)17 && nox_xxx_monsterTestBlockShield_533E70(v1)) {
					v3 = *v40;
					if (*v40 != (int*)1 && v3 != (int*)23) {
						nox_xxx_monsterPopAttackActions_5471B0(v1);
						v3 = nox_xxx_monsterPushAction_50A260(v1, 1);
						if (v3) {
							v3[1] = nox_frame_xxx_2598000 + nox_gameFPS;
						}
					}
					return (char)v3;
				}
			} else {
				v30 = v40;
			}
			if (nox_xxx_monsterHasShield_5342C0(v1) && *v30 != (int*)16 && *v30 != (int*)17 &&
				nox_xxx_monsterTestBlockShield_533E70(v1)) {
				v3 = (int*)nox_xxx_checkMobAction_50A0D0(v1, 21);
				if (!v3) {
					nox_xxx_monsterPopAttackActions_5471B0(v1);
					v3 = nox_xxx_monsterPushAction_50A260(v1, 21);
					if (v3) {
						v3[1] = nox_frame_xxx_2598000 + (nox_gameFPS >> 1);
					}
				}
				return (char)v3;
			}
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				if (!sub_534440(v1) && !nox_xxx_testUnitBuffs_4FF350(v1, 3)) {
					if (*(uint8_t*)(*(uint32_t*)(v2 + 484) + 92) & 8) {
						if (!nox_xxx_checkMobAction_50A0D0(v1, 9)) {
							if (nox_xxx_monsterTestBlockShield_533E70(v1)) {
								v3 = (int*)nox_xxx_monsterCheckDodgeables_547C50(v1);
								if (v3) {
									return (char)v3;
								}
							}
						}
					}
				}
			}
			v31 = *v30;
			if (*v30 == (int*)7 || v31 == (int*)37 || v31 == (int*)8 || v31 == (int*)10 || v31 == (int*)24) {
				v32 = *(float*)(v2 + 500) - *(float*)(v1 + 56);
				v33 = *(float*)(v2 + 504) - *(float*)(v1 + 60);
				if (v33 * v33 + v32 * v32 > 225.0) {
					*(uint32_t*)(v2 + 496) = nox_frame_xxx_2598000;
					*(uint32_t*)(v2 + 500) = *(uint32_t*)(v1 + 56);
					*(uint32_t*)(v2 + 504) = *(uint32_t*)(v1 + 60);
				} else if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(v2 + 496)) > (int)nox_gameFPS >> 1) {
					v39 = *(uint32_t*)(v1 + 36);
					v34 = nox_xxx_getUnitName_4E39D0(v1);
					nox_ai_debug_printf_5341A0("%d: %s(#%d) FRUSTRATED\n", nox_frame_xxx_2598000, v34, v39);
					*(uint32_t*)(v2 + 1440) |= 0x200000u;
					if (nox_xxx_checkMobAction_50A0D0(v1, 6) || nox_xxx_checkMobAction_50A0D0(v1, 14) ||
						nox_xxx_checkMobAction_50A0D0(v1, 24)) {
						*(uint32_t*)(v2 + 508) = nox_frame_xxx_2598000;
					}
					if (nox_xxx_checkMobAction_50A0D0(v1, 15)) {
						nox_xxx_monsterCheckDodgeables_547C50(v1);
					} else if (nox_common_randomInt_415FA0(0, 100) >= 33 ||
							   !nox_xxx_monsterCheckDodgeables_547C50(v1)) {
						v35 = nox_xxx_monsterPushAction_50A260(v1, 1);
						if (v35) {
							v35[1] =
								nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(nox_gameFPS >> 1, 2 * nox_gameFPS);
						}
					}
					LOBYTE(v3) = (unsigned char)nox_frame_xxx_2598000;
					*(uint32_t*)(v2 + 496) = nox_frame_xxx_2598000;
					*(uint32_t*)(v2 + 500) = *(uint32_t*)(v1 + 56);
					*(uint32_t*)(v2 + 504) = *(uint32_t*)(v1 + 60);
					return (char)v3;
				}
			}
			v3 = (int*)sub_534440(v1);
			if (!v3) {
				v3 = (int*)sub_5347C0(v1);
				if (v3) {
					if (!((unsigned char)nox_frame_xxx_2598000 & 0xF)) {
						v3 = (int*)nox_xxx_mobSearchEdible_544A00(v1, 75.0);
						v36 = (int)v3;
						if (v3) {
							nox_xxx_inventoryServPlace_4F36F0(v1, (int)v3, 1, 1);
							LOBYTE(v3) = *(uint8_t*)(v36 + 12);
							if ((unsigned char)v3 & 0x90) {
								LOBYTE(v3) = nox_xxx_useByNetCode_53F8E0(v1, v36);
							}
						}
					}
				}
			}
			if (*(uint32_t*)(v2 + 1440) & 0x20000) {
				v3 = *(int**)(*(uint32_t*)(v2 + 2180) + 276);
				if (!*((uint8_t*)v3 + 2251) && !v3[1] && !((unsigned char)nox_frame_xxx_2598000 & 0xF)) {
					v3 = (int*)sub_544AE0(v1, 75.0);
					v37 = (int)v3;
					if (v3) {
						nox_xxx_mobMorphToPlayer_4FAAF0((uint32_t*)v1);
						nox_xxx_inventoryServPlace_4F36F0(v1, v37, 1, 1);
						LOBYTE(v3) = nox_xxx_mobMorphFromPlayer_4FAAC0((uint32_t*)v1);
					}
				}
			}
		}
	} else {
		v6 = (uint32_t*)(v2 + 8 * (3 * (uint32_t)v3 + 69));
		while (*v6 != 61) {
			v3 = (int*)((char*)v3 - 1);
			v6 -= 6;
			if ((int)v3 < 0) {
				goto LABEL_8;
			}
		}
	}
	return (char)v3;
}

//----- (00547C50) --------------------------------------------------------
int nox_xxx_monsterCheckDodgeables_547C50(int a1) {
	float* v1;  // esi
	int v2;     // edi
	int v3;     // eax
	double v4;  // st7
	float v5;   // eax
	double v6;  // st7
	double v7;  // st7
	int* v9;    // eax
	int* v10;   // eax
	float v11;  // [esp+8h] [ebp-18h]
	float v12;  // [esp+Ch] [ebp-14h]
	float4 v13; // [esp+10h] [ebp-10h]
	float v14;  // [esp+24h] [ebp+4h]

	v1 = (float*)a1;
	v2 = 0;
	v3 = *(short*)(a1 + 124);
	v4 = *getMemFloatPtr(0x587000, 194140 + 8 * v3);
	v12 = *getMemFloatPtr(0x587000, 194136 + 8 * v3);
	v5 = *(float*)(a1 + 60);
	v13.field_0 = *(float*)(a1 + 56);
	v11 = -v4;
	v13.field_4 = v5;
	while (1) {
		v6 = nox_common_randomFloat_416030(2.0, 3.0) * v1[44];
		v14 = v6;
		if (v6 > 15.0) {
			v14 = 15.0;
		}
		v7 = v14;
		if (nox_common_randomInt_415FA0(0, 100) < 50) {
			v7 = -v7;
		}
		v13.field_8 = v7 * v11 + v1[14];
		v13.field_C = v7 * v12 + v1[15];
		if (nox_xxx_mapTraceRay_535250(&v13, 0, 0, 1)) {
			if (nox_xxx_mapTraceObstacles_50B580((int)v1, &v13) &&
				nox_xxx_tileNFromPoint_411160((float2*)&v13.field_8) != 6) {
				break;
			}
		}
		if (++v2 >= 5) {
			return 0;
		}
	}
	nox_xxx_monsterPopAttackActions_5471B0((int)v1);
	v9 = nox_xxx_monsterPushAction_50A260((int)v1, 41);
	if (v9) {
		v9[1] = nox_frame_xxx_2598000 + nox_gameFPS;
	}
	v10 = nox_xxx_monsterPushAction_50A260((int)v1, 9);
	if (v10) {
		v10[1] = LODWORD(v13.field_8);
		v10[2] = LODWORD(v13.field_C);
		v10[3] = 0;
	}
	return 1;
}

//----- (00547DB0) --------------------------------------------------------
int sub_547DB0(int a1, float2* a2) {
	double v3; // st7
	double v4; // st6
	float v5;  // [esp+0h] [ebp-10h]
	float v6;  // [esp+4h] [ebp-Ch]
	float v7;  // [esp+8h] [ebp-8h]
	float v8;  // [esp+Ch] [ebp-4h]

	if (*(uint32_t*)(a1 + 172) == 1) {
		return 0;
	}
	if (*(uint32_t*)(a1 + 172) != 2) {
		if (*(uint32_t*)(a1 + 172) == 3) {
			v5 = *(float*)(a1 + 192) + *(float*)(a1 + 64);
			v6 = *(float*)(a1 + 196) + *(float*)(a1 + 68);
			if ((v6 - v5 + a2->field_0 - a2->field_4) * 0.70709997 < 0.0 &&
				(*(float*)(a1 + 204) + *(float*)(a1 + 68) - (*(float*)(a1 + 200) + *(float*)(a1 + 64)) + a2->field_0 -
				 a2->field_4) *
						0.70709997 >
					0.0) {
				v7 = *(float*)(a1 + 208) + *(float*)(a1 + 64);
				v8 = *(float*)(a1 + 212) + *(float*)(a1 + 68);
				if ((v8 + v7 - a2->field_0 - a2->field_4) * 0.70709997 > 0.0 &&
					(v6 + v5 - a2->field_0 - a2->field_4) * 0.70709997 < 0.0) {
					return 1;
				}
			}
		}
		return 0;
	}
	v3 = *(float*)(a1 + 64) - a2->field_0;
	v4 = *(float*)(a1 + 68) - a2->field_4;
	if (v4 * v4 + v3 * v3 > *(float*)(a1 + 180)) {
		return 0;
	}
	return 1;
}

//----- (00547EE0) --------------------------------------------------------
int sub_547EE0(int a1, unsigned char a2) { return a1 && *(uint8_t*)(a1 + 480) & 1 && sub_579EE0(a1, a2); }

//----- (00547F10) --------------------------------------------------------
int sub_547F10() {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 2490500);
	*getMemU32Ptr(0x5D4594, 2490500) = 0;
	return result;
}

//----- (00547F20) --------------------------------------------------------
int sub_547F20(int a1, float* a2) {
	int v2;       // ebx
	uint32_t* v3; // edi
	int v4;       // eax
	int result;   // eax

	v2 = *(uint32_t*)(a1 + 748);
	v3 = (uint32_t*)sub_50CB20(a1, (float*)(a1 + 56));
	v4 = sub_50CB20(a1, a2);
	if (v3 && v4 && v3 != (uint32_t*)v4) {
		result = nox_xxx_BuildWaypointPath_547F70(v3, v4, (uint32_t*)(v2 + 300), 16);
	} else {
		result = 0;
	}
	return result;
}

//----- (00547F70) --------------------------------------------------------
int nox_xxx_BuildWaypointPath_547F70(uint32_t* a1, int a2, uint32_t* a3, int a4) {
	uint32_t* v4;       // edi
	int v5;             // ebx
	int v6;             // ebp
	uint32_t* v7;       // esi
	int v8;             // ebx
	unsigned char* v9;  // eax
	int v10;            // esi
	uint32_t* v11;      // ecx
	unsigned char* v12; // eax
	uint32_t* v14;      // [esp+14h] [ebp+4h]

	v4 = a1;
	if (sub_547EE0((int)a1, 0x80u) && sub_547EE0(a2, 0x80u)) {
		++dword_5d4594_2490504;
		a1[127] = 0;
		a1[128] = 0;
		a1[126] = dword_5d4594_2490504;
		do {
			v14 = 0;
			if (!v4) {
				break;
			}
			do {
				if (v4 == (uint32_t*)a2) {
					v8 = 0;
					*getMemU32Ptr(0x5D4594, 2490500) = 0;
					v9 = getMemAt(0x5D4594, 2489476);
					while (1) {
						*(uint32_t*)v9 = v4;
						v4 = (uint32_t*)v4[127];
						v9 += 4;
						++v8;
						if (v9 == getMemAt(0x5D4594, 2490500)) {
							break;
						}
						if (!v4) {
							goto LABEL_20;
						}
					}
					nox_ai_debug_printf_5341A0("BuildWaypointPath: Node list exceeded internal buffer.\n");
				LABEL_20:
					v10 = 0;
					if (v8 > 0) {
						v11 = a3;
						v12 = getMemAt(0x5D4594, 2489472 + 4 * v8);
						do {
							*v11 = *(uint32_t*)v12;
							if (v10 == a4) {
								break;
							}
							++v10;
							v12 -= 4;
							++v11;
						} while (v10 < v8);
					}
					if (v10 != v8) {
						nox_ai_debug_printf_5341A0("BuildWaypointPath: Node list too long.\n");
						*getMemU32Ptr(0x5D4594, 2490500) = 1;
					}
					return v10;
				}
				v5 = 0;
				if (*((uint8_t*)v4 + 476)) {
					v6 = (int)(v4 + 23);
					do {
						v7 = *(uint32_t**)v6;
						if (*(uint32_t*)(*(uint32_t*)v6 + 504) != dword_5d4594_2490504) {
							if (sub_547EE0((int)v7, 0x80u)) {
								v7[127] = v4;
								v7[128] = v14;
								v14 = v7;
								v7[126] = dword_5d4594_2490504;
							}
						}
						++v5;
						v6 += 8;
					} while (v5 < *((unsigned char*)v4 + 476));
				}
				v4 = (uint32_t*)v4[128];
			} while (v4);
			v4 = v14;
		} while (v14);
	}
	*getMemU32Ptr(0x5D4594, 2490500) = 2;
	return 0;
}

//----- (00548100) --------------------------------------------------------
void sub_548100(int2* a1, int a2) {
	int v2;    // eax
	int v3;    // ecx
	int v4;    // edx
	int v5;    // esi
	int v6;    // edx
	char* v7;  // eax
	int v8;    // eax
	float2 v9; // [esp+0h] [ebp-8h]
	int v10;   // [esp+Ch] [ebp+4h]

	v2 = nox_server_getWallAtGrid_410580(a1->field_0, a1->field_4);
	if (v2) {
		if (*(uint8_t*)(v2 + 4) & 4) {
			if (*(uint8_t*)(a2 + 8) & 6) {
				v3 = *(uint32_t*)(v2 + 28);
				if (*(uint8_t*)(v3 + 21) == 1) {
					if (*(uint8_t*)(v3 + 20) & 2) {
						*(uint8_t*)(v3 + 21) = 4;
						v4 = *(uint32_t*)(v3 + 4);
						*(uint8_t*)(v3 + 22) = 0;
						v5 = 23 * v4;
						v10 = 23 * *(uint32_t*)(v3 + 8);
						v6 = *(unsigned char*)(v2 + 1);
						v9.field_0 = (double)v5 + 11.5;
						v9.field_4 = (double)v10 + 11.5;
						v7 = nox_xxx_wallFindOpenSound_410EE0(v6);
						v8 = nox_xxx_utilFindSound_40AF50(v7);
						nox_xxx_audCreate_501A30(v8, &v9, 0, 0);
					}
				}
			}
		}
	}
}

//----- (005481C0) --------------------------------------------------------
void sub_5481C0(int a1) {
	*(uint32_t*)(a1 + 96) = 0;
	*(uint32_t*)(a1 + 100) = 0;
	if (!(*(uint8_t*)(a1 + 16) & 0x60)) {
		nox_xxx_getUnitsInRect_517C10((float4*)(a1 + 232), sub_548220, a1);
		if (!(*(uint8_t*)(a1 + 16) & 8)) {
			if (*(uint32_t*)(a1 + 172) == 2) {
				sub_54FEF0(a1);
			} else if (*(uint32_t*)(a1 + 172) == 3) {
				sub_5504B0(a1);
			}
		}
	}
}

//----- (00548220) --------------------------------------------------------
void sub_548220(int* a1, float* a2) {
	int v2; // eax
	int v3; // ecx
	int v4; // eax

	if (sub_548360((int)a2, (int)a1)) {
		v2 = *((uint32_t*)a2 + 2);
		if (v2 & 0x4000) {
			sub_551AE0((int)a2, (int)a1, 0);
		} else {
			v3 = a1[2];
			if (v3 & 0x4000) {
				sub_551AE0((int)a1, (int)a2, 1);
			} else if ((v2 & 0x8000) == 0) {
				if ((v3 & 0x8000) == 0) {
					if ((v2 & 0x80u) == 0) {
						if (*((uint32_t*)a2 + 43) == 2) {
							if ((v3 & 0x80u) == 0) {
								if (a1[43] == 2) {
									nox_xxx_collisionCheckCircleCircle_550D00((int)a2, (int)a1);
								} else if (a1[43] == 3) {
									sub_54AD50((int)a2, (int)a1, 0);
								}
							} else {
								sub_5488B0(a1, a2, 1);
							}
						} else if (*((uint32_t*)a2 + 43) == 3) {
							if ((v3 & 0x80u) == 0) {
								if (a1[43] == 2) {
									sub_54AD50((int)a1, (int)a2, 1);
								} else if (a1[43] == 3) {
									sub_550F80(a2, (int)a1);
								}
							} else {
								sub_551250((unsigned int)a1, a2, 1);
							}
						}
					} else {
						v4 = a1[43];
						if (v4 == 2) {
							sub_5488B0((int*)a2, (float*)a1, 0);
						} else if (v4 == 3) {
							sub_551250((unsigned int)a2, (float*)a1, 0);
						}
					}
				} else {
					sub_551C40((int)a1, (int)a2);
				}
			} else {
				sub_551C40((int)a2, (int)a1);
			}
		}
	}
}

//----- (00548360) --------------------------------------------------------
int sub_548360(int a1, int a2) {
	int v2;         // eax
	int v3;         // ebp
	int (*v4)(int); // ecx
	int (*v5)(int); // esi
	int v6;         // ebx
	int v7;         // eax
	int v8;         // edx
	short v9;       // cx
	int result;     // eax
	int v11;        // ecx
	int v12;        // [esp+0h] [ebp-Ch]
	int v13;        // [esp+4h] [ebp-8h]
	int v14;        // [esp+14h] [ebp+8h]

	if (dword_5d4594_2490508) {
		v2 = *getMemU32Ptr(0x5D4594, 2490516);
	} else {
		dword_5d4594_2490508 = nox_xxx_getNameId_4E3AA0("Trigger");
		*getMemU32Ptr(0x5D4594, 2490512) = nox_xxx_getNameId_4E3AA0("BlackPowder");
		v2 = nox_xxx_getNameId_4E3AA0("TelekinesisHand");
		*getMemU32Ptr(0x5D4594, 2490516) = v2;
	}
	v3 = a2;
	v4 = *(int (**)(int))(a1 + 696);
	if (v4 == nox_xxx_collidePentagram_4EAB20 && *(unsigned short*)(a2 + 4) == v2) {
		goto LABEL_56;
	}
	v5 = *(int (**)(int))(a2 + 696);
	if (v5 == nox_xxx_collidePentagram_4EAB20 && *(unsigned short*)(a1 + 4) == v2) {
		goto LABEL_56;
	}
	v6 = *(uint32_t*)(a1 + 8);
	v12 = *(uint32_t*)(a1 + 8) & 0x80;
	if (v12) {
		if (*(uint8_t*)(a2 + 16) & 9) {
			goto LABEL_56;
		}
	}
	v14 = *(uint32_t*)(a2 + 8);
	if (v14 & 0x80) {
		if (*(uint8_t*)(a1 + 16) & 9) {
			goto LABEL_56;
		}
	}
	v7 = *(uint32_t*)(a1 + 16);
	v13 = *(uint32_t*)(a1 + 16);
	if (v7 & 0x60) {
		goto LABEL_56;
	}
	v8 = *(uint32_t*)(v3 + 16);
	if (v8 & 0x60 || a1 == v3 || !v4 || !v5) {
		goto LABEL_56;
	}
	if (v6 & 2 && v7 & 0x4000) {
		v9 = v14;
		if (v14 & 0xCC00) {
			return sub_5485B0(a1, v3);
		}
	} else {
		v9 = v14;
	}
	if (v9 & 2 && v8 & 0x4000 && v6 & 0xCC00) {
		return sub_5485B0(v3, a1);
	}
	if (v6 & 0x2000 && *(unsigned short*)(v3 + 4) == *getMemU32Ptr(0x5D4594, 2490512)) {
		return 1;
	}
	if (v9 & 0x2000 && *(unsigned short*)(a1 + 4) == *getMemU32Ptr(0x5D4594, 2490512)) {
		return 1;
	}
	if ((v11 = *(uint32_t*)(a1 + 16), v13 & 8) && v8 & 8 || v12 && v8 & 8 || v14 & 0x80 && v13 & 8 ||
		*(unsigned short*)(a1 + 4) != dword_5d4594_2490508 && *(unsigned short*)(v3 + 4) != dword_5d4594_2490508 &&
			(v13 & 0x11 && v8 & 0x24000 || v8 & 0x11 && v11 & 0x24000) ||
		v12 && v14 & 0x80 || v6 & 0x4000 && v14 & 0x4000 || (v6 & 0x8000) != 0 && (v14 & 0x8000) != 0 ||
		v11 & 0x400 && nox_xxx_unitsHaveSameTeam_4EC520(a1, v3)) {
	LABEL_56:
		result = 0;
	} else {
		result = 1;
	}
	return result;
}

//----- (005485B0) --------------------------------------------------------
int sub_5485B0(int a1, int a2) {
	int v2;      // ecx
	int v3;      // eax
	int v4;      // edx
	uint32_t* i; // ecx

	v2 = *(uint32_t*)(a1 + 748);
	v3 = 0;
	v4 = *(unsigned char*)(v2 + 2172);
	if (v4 <= 0) {
		return 0;
	}
	for (i = (uint32_t*)(v2 + 2140); *i != *(uint32_t*)(a2 + 36); ++i) {
		if (++v3 >= v4) {
			return 0;
		}
	}
	return 1;
}

//----- (00548630) --------------------------------------------------------
void nox_xxx_collSysAddCollision_548630(int a1, unsigned int a2, float2* a3) {
	int v3;       // esi
	int v4;       // esi
	uint32_t* v5; // eax
	int v6;       // ecx
	int* v7;      // eax
	int v8;       // ecx

	v3 = *(uint32_t*)(a1 + 36);
	if (a2 > 6) {
		v3 += *(uint32_t*)(a2 + 36);
	}
	v4 = v3 % 256;
	v5 = *(uint32_t**)getMemAt(0x5D4594, 2490520 + 4 * v4);
	if (v5) {
		while (1) {
			v6 = v5[2];
			if (v6 == a1 && v5[3] == a2) {
				break;
			}
			if (v6 == a2 && v5[3] == a1) {
				break;
			}
			v5 = (uint32_t*)*v5;
			if (!v5) {
				goto LABEL_9;
			}
		}
	} else {
	LABEL_9:
		v7 = (int*)nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_hit_2491548);
		if (v7) {
			v7[2] = a1;
			v7[3] = a2;
			*((float2*)v7 + 2) = *a3;
			v7[6] = v4;
			*v7 = *getMemU32Ptr(0x5D4594, 2490520 + 4 * v4);
			v8 = dword_5d4594_2491544;
			*getMemU32Ptr(0x5D4594, 2490520 + 4 * v4) = v7;
			v7[1] = v8;
			dword_5d4594_2491544 = v7;
		}
	}
}

//----- (005486D0) --------------------------------------------------------
void nox_xxx_allocHitArray_5486D0() {
	char* v0; // edx
	int i;    // eax

	v0 = *(char**)&nox_alloc_hit_2491548;
	if (!nox_alloc_hit_2491548) {
		v0 = nox_new_alloc_class("Hit", 28, 1024);
		nox_alloc_hit_2491548 = v0;
		memset(getMemAt(0x5D4594, 2490520), 0, 0x400u);
	}
	for (i = dword_5d4594_2491544; i; i = *(uint32_t*)(i + 4)) {
		*getMemU32Ptr(0x5D4594, 2490520 + 4 * *(uint32_t*)(i + 24)) = 0;
	}
	nox_alloc_class_free_all(v0);
	dword_5d4594_2491544 = 0;
}

//----- (00548740) --------------------------------------------------------
void nox_xxx_collide_548740() {
	int i;           // esi
	unsigned int v1; // ecx
	int v2;          // eax
	float2 v3;       // [esp+4h] [ebp-8h]

	for (i = dword_5d4594_2491544; i; i = *(uint32_t*)(i + 4)) {
		v1 = *(uint32_t*)(i + 12);
		if (v1 > 6 || !v1) {
			(*(void (**)(uint32_t, unsigned int, int))(*(uint32_t*)(i + 8) + 696))(*(uint32_t*)(i + 8), v1, i + 16);
			if (*(uint32_t*)(i + 12)) {
				nox_xxx_collide_4FDF90(*(uint32_t*)(i + 8), *(uint32_t*)(i + 12));
			}
		}
		v2 = *(uint32_t*)(i + 12);
		if (v2 == 6) {
			(*(void (**)(uint32_t, uint32_t, uint32_t, int, int))(*(uint32_t*)(i + 8) + 716))(*(uint32_t*)(i + 8), 0, 0,
																							  2, 12);
			nox_xxx_unitHasCollideOrUpdateFn_537610(*(uint32_t*)(i + 8));
		} else if (v2) {
			v3.field_0 = -*(float*)(i + 16);
			v3.field_4 = -*(float*)(i + 20);
			(*(void (**)(uint32_t, uint32_t, float2*))(*(uint32_t*)(i + 12) + 696))(*(uint32_t*)(i + 12),
																					*(uint32_t*)(i + 8), &v3);
			nox_xxx_collide_4FDF90(*(uint32_t*)(i + 12), *(uint32_t*)(i + 8));
			if (*(uint8_t*)(*(uint32_t*)(i + 8) + 16) & 8) {
				nox_xxx_unitHasCollideOrUpdateFn_537610(*(uint32_t*)(i + 12));
			} else if (*(uint8_t*)(*(uint32_t*)(i + 12) + 16) & 8) {
				nox_xxx_unitHasCollideOrUpdateFn_537610(*(uint32_t*)(i + 8));
			}
		}
		nullsub_30(*(uint32_t*)(i + 8));
	}
}
// 5485F0: using guessed type void  nullsub_30(uint32_t);

//----- (00548830) --------------------------------------------------------
void sub_548830(int a1) {
	if (!*(uint32_t*)(a1 + 28)) {
		*(uint32_t*)(a1 + 36) = dword_5d4594_2491552;
		dword_5d4594_2491552 = a1;
		*(uint32_t*)(a1 + 28) = 1;
	}
}

//----- (00548860) --------------------------------------------------------
void sub_548860(int a1, short a2) {
	int v2; // eax

	v2 = *(uint32_t*)(a1 + 748);
	for (*(uint16_t*)(v2 + 40) += a2; *(uint16_t*)(v2 + 40) < 0; *(uint16_t*)(v2 + 40) += 256) {
		;
	}
	for (; *(uint16_t*)(v2 + 40) >= 256; *(uint16_t*)(v2 + 40) -= 256) {
		;
	}
	sub_548830(v2);
}

//----- (005488B0) --------------------------------------------------------
void sub_5488B0(int* a1, float* a2, int a3) {
	int* v3;                     // edi
	int v4;                      // ebx
	float v5;                    // ecx
	int v6;                      // eax
	float* v7;                   // esi
	float* v8;                   // ebp
	double v9;                   // st7
	double v10;                  // st6
	long double v11;             // st6
	double v12;                  // st7
	float v13;                   // et1
	long double v14;             // st7
	float v15;                   // et1
	long double v16;             // st7
	int v17;                     // eax
	float* v18;                  // eax
	double v19;                  // st7
	double v20;                  // st7
	float v21;                   // [esp+0h] [ebp-44h]
	float v22;                   // [esp+4h] [ebp-40h]
	int v23;                     // [esp+4h] [ebp-40h]
	float v24;                   // [esp+18h] [ebp-2Ch]
	int* v25;                    // [esp+1Ch] [ebp-28h]
	volatile unsigned char* v26; // [esp+20h] [ebp-24h]
	float2 v27;                  // [esp+24h] [ebp-20h]
	float2 a3a;                  // [esp+2Ch] [ebp-18h]
	float4 a1a;                  // [esp+34h] [ebp-10h]
	signed int v30;              // [esp+48h] [ebp+4h]
	float v31;                   // [esp+48h] [ebp+4h]
	float v32;                   // [esp+4Ch] [ebp+8h]
	float v33;                   // [esp+4Ch] [ebp+8h]

	v3 = a1;
	v4 = a1[187];
	v5 = *((float*)a1 + 17);
	LODWORD(a1a.field_0) = a1[16];
	a1a.field_4 = v5;
	v6 = *(short*)(v4 + 40) + 160;
	if (v6 >= 256) {
		v6 = *(short*)(v4 + 40) - 96;
	}
	v26 = getMemAt(0x587000, 192092 + 8 * v6);
	v7 = a2;
	v25 = getMemIntPtr(0x587000, 192088 + 8 * v6);
	v30 = 2 * *(int*)v26;
	v8 = a2 + 16;
	a1a.field_8 = (double)(2 * *getMemIntPtr(0x587000, 192088 + 8 * v6)) + a1a.field_0;
	a1a.field_C = (double)v30 + a1a.field_4;
	sub_57C790(&a1a, (float2*)a2 + 8, &a3a, 32.0);
	v9 = a2[16] - a3a.field_0;
	v10 = a2[17] - a3a.field_4;
	v27.field_4 = v10;
	v11 = sqrt(v10 * v27.field_4 + v9 * v9);
	v31 = v11;
	if (v11 == 0.0) {
		v31 = 0.1;
	}
	if (v31 < (double)a2[44]) {
		v27.field_0 = v9 / v31;
		v27.field_4 = v27.field_4 / v31;
		nox_xxx_collSysAddCollision_548630((int)a2, (unsigned int)v3, &v27);
		*(uint32_t*)(v4 + 44) = nox_frame_xxx_2598000;
		if (a3 == 1) {
			v32 = a2[44] - v31;
			v24 = -(v27.field_4 * v7[21]) - v27.field_0 * v7[20];
			v12 = nox_xxx_objectGetMass_4E4A70((int)v7);
			v13 = *(float*)&dword_587000_292492;
			v14 = sqrt(v12 * v13 * 4.0);
			v15 = *(float*)&dword_587000_292492;
			v16 = v14 * v24 * 0.25 + v15 * v32;
			v22 = v16 * v27.field_4;
			v21 = v16 * v27.field_0;
			sub_548600((int)v7, v21, v22);
		}
		v17 = *((uint32_t*)v7 + 4);
		if (v17 & 0x8000000) {
			if (!(v17 & 8)) {
				nox_xxx_unitHasCollideOrUpdateFn_537610((int)v7);
			}
			*((uint32_t*)v7 + 4) &= 0xF7FFFFFF;
		}
		nox_xxx_unitHasCollideOrUpdateFn_537610((int)v3);
		if (!nox_xxx_servObjectHasTeam_419130((int)(v3 + 12)) || *(uint32_t*)(v4 + 12) != *(uint32_t*)(v4 + 4) ||
			nox_xxx_servCompareTeams_419150((int)(v3 + 12), (int)(v7 + 12))) {
			if (!a3 && !*(uint8_t*)(v4 + 1)) {
				v18 = (float*)v3[127];
				if (!v18 || v18 == v7) {
					v33 = v7[44] - v31;
					v19 = v33 * v7[30];
					if ((double)*v25 * (v7[17] - *((float*)v3 + 17)) -
							(double)*(int*)v26 * (*v8 - *((float*)v3 + 16)) <=
						0.0) {
						v20 = v19 + *(float*)(v4 + 32);
					} else {
						v20 = *(float*)(v4 + 32) - v19;
					}
					*(float*)(v4 + 32) = v20;
					sub_548830(v4);
					nox_xxx_unitAddToUpdatable_4DA8D0((int)v3);
				}
			}
		} else if (nox_frame_xxx_2598000 > (unsigned int)v3[34]) {
			v23 = *((unsigned char*)v3 + 52);
			v3[34] = nox_frame_xxx_2598000 + nox_gameFPS;
			nox_xxx_clientGetTeamColor_418AB0(v23);
			nox_xxx_netPriMsgToPlayer_4DA2C0((int)v7, "objcoll.c:GateLockedMechanism", 0);
		}
	}
}

//----- (00548B60) --------------------------------------------------------
void sub_548B60() {
	int v0;   // esi
	int v1;   // eax
	int v2;   // ecx
	short v3; // ax
	short v4; // ax
	short v5; // ax
	int v6;   // eax
	int v7;   // eax
	int v8;   // eax
	float v9; // [esp+0h] [ebp-14h]

	v0 = dword_5d4594_2491552;
	if (dword_5d4594_2491552) {
		while (1) {
			v9 = *(float*)(v0 + 32) + *(float*)(v0 + 32) + 0.5;
			v1 = nox_float2int(v9);
			v2 = v1;
			if (v1 < 0) {
				v2 = -v1;
			}
			if (v2 > 4) {
				LOWORD(v2) = 4;
			}
			if (*(float*)(v0 + 32) >= -0.0099999998) {
				if (*(float*)(v0 + 32) <= 0.0099999998) {
					goto LABEL_15;
				}
				if (*(uint32_t*)(v0 + 12) == (*(uint32_t*)(v0 + 4) + 12) % 32) {
					goto LABEL_15;
				}
				*(uint16_t*)(v0 + 40) += v2;
				v5 = *(uint16_t*)(v0 + 40);
				if (v5 < 256) {
					goto LABEL_15;
				}
				v4 = v5 - 256;
			} else {
				if (*(int*)(v0 + 12) == *(int*)(v0 + 4) - 12 + (*(int*)(v0 + 4) - 12 < 0 ? 0x20 : 0)) {
					goto LABEL_15;
				}
				*(uint16_t*)(v0 + 40) -= v2;
				v3 = *(uint16_t*)(v0 + 40);
				if (v3 >= 0) {
					goto LABEL_15;
				}
				v4 = v3 + 256;
			}
			*(uint16_t*)(v0 + 40) = v4;
		LABEL_15:
			v6 = 32 * *(short*)(v0 + 40) / 256;
			*(uint32_t*)(v0 + 12) = v6;
			if (v6 < 0) {
				do {
					v7 = *(uint32_t*)(v0 + 12);
					*(uint32_t*)(v0 + 12) = v7 + 32;
				} while (v7 + 32 < 0);
			}
			if (*(uint32_t*)(v0 + 12) >= 32) {
				do {
					v8 = *(uint32_t*)(v0 + 12) - 32;
					*(uint32_t*)(v0 + 12) = v8;
				} while (v8 >= 32);
			}
			*(uint32_t*)(v0 + 28) = 0;
			*(uint32_t*)(v0 + 32) = 0;
			v0 = *(uint32_t*)(v0 + 36);
			if (!v0) {
				dword_5d4594_2491552 = 0;
				return;
			}
		}
	}
	dword_5d4594_2491552 = 0;
}

//----- (00548C80) --------------------------------------------------------
void nox_xxx_scriptSetDialog_548C80(int a1, char a2, int a3, int a4) {
	int v4; // eax

	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 2) {
			v4 = *(uint32_t*)(a1 + 748);
			if (a3 != -1 && a4 != -1) {
				*(uint32_t*)(v4 + 2096) = a3;
				*(uint32_t*)(v4 + 2100) = a4;
				*(uint8_t*)(v4 + 2104) = a2;
				nox_xxx_unitSetXStatus_4E4800(a1, (int*)0x10);
			}
		}
	}
}

//----- (00548CD0) --------------------------------------------------------
void nox_xxx_script_forcedialog_548CD0(int a1, int a2) {
	int v2; // ecx
	int v3; // eax

	if (a1) {
		if (a2) {
			if (*(uint8_t*)(a1 + 8) & 4) {
				if (*(uint8_t*)(a2 + 8) & 2) {
					if (!(*(uint32_t*)(a1 + 16) & 0x8020)) {
						v2 = *(uint32_t*)(a2 + 748);
						if (*(uint8_t*)(a2 + 20) & 0x10) {
							v3 = *(uint32_t*)(v2 + 2096);
							if (v3 != -1 && *(int*)(v2 + 2100) != -1) {
								nox_script_callByIndex_507310(v3, a1, a2);
							}
						}
					}
				}
			}
		}
	}
}

//----- (00548D30) --------------------------------------------------------
void nox_xxx_scriptDialog_548D30(int a1, char a2) {
	int v2; // ebx
	int v3; // edi
	int v5; // ebp
	int v6; // esi

	v2 = a1;
	v3 = *(uint32_t*)(a1 + 748);
	nox_xxx_unitUnFreeze_4E7A60(a1, 0);
	v5 = *(uint32_t*)(v3 + 284);
	if (v5) {
		v6 = *(uint32_t*)(v5 + 748);
		if (*(int*)(v6 + 2096) != -1 && *(int*)(v6 + 2100) != -1) {
			LOWORD(a1) = 1232;
			nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), &a1, 2, 0, 1);
			*(uint32_t*)(v3 + 284) = 0;
			if (*(uint8_t*)(v6 + 2104) == 1) {
				*(uint8_t*)(v6 + 2105) = a2;
			} else {
				*(uint8_t*)(v6 + 2105) = 0;
			}
			nox_script_callByIndex_507310(*(uint32_t*)(v6 + 2100), v2, v5);
		}
	}
}

//----- (00548DE0) --------------------------------------------------------
char nox_xxx_startShopDialog_548DE0(int a1, int a2, int a3, const char* a4) {
	char result;  // al
	int v5;       // ebx
	int v6;       // ebp
	wchar_t* v7;  // eax
	char v8[135]; // [esp+10h] [ebp-88h]

	result = a1;
	v5 = *(uint32_t*)(a2 + 748);
	v6 = *(uint32_t*)(a1 + 748);
	if (a1 && *(uint8_t*)(a1 + 8) & 4 && a4) {
		*(uint32_t*)(v6 + 284) = a2;
		v8[0] = -48;
		v8[1] = 3;
		strcpy(&v8[2], a4);
		v7 = sub_4E39F0_obj_db((const char**)a2);
		nox_wcsncpy((wchar_t*)&v8[34], v7, 0x1Fu);
		*(uint16_t*)&v8[96] = 0;
		v8[134] = *(uint8_t*)(v5 + 2104);
		*(uint32_t*)&v8[98] = a3;
		if (*(uint8_t*)(v5 + 2106)) {
			strcpy(&v8[102], (const char*)(v5 + 2106));
		} else {
			strcpy(&v8[102], "ShopKeeperPic");
		}
		nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v6 + 276) + 2064), v8, 135, 0, 1);
		result = nox_xxx_unitFreeze_4E79C0(a1, 0);
	}
	return result;
}

//----- (00548F40) --------------------------------------------------------
int sub_548F40(int a1) {
	int result; // eax

	if (a1 && *(uint8_t*)(a1 + 8) & 2) {
		result = *(unsigned char*)(*(uint32_t*)(a1 + 748) + 2105);
	} else {
		result = 0;
	}
	return result;
}

//----- (00548F70) --------------------------------------------------------
char nox_xxx_scriptGetDialogIdx_548F70(const char* a1) {
	const char* v1;    // eax
	int v2;            // ebp
	unsigned char* v3; // edi
	int v4;            // eax

	v1 = *(const char**)getMemAt(0x587000, 287000);
	v2 = 0;
	if (*getMemU32Ptr(0x587000, 287000)) {
		v3 = getMemAt(0x587000, 287000);
		while (strcmp(v1, a1)) {
			v1 = (const char*)*((uint32_t*)v3 + 2);
			v3 += 8;
			++v2;
			if (!v1) {
				goto LABEL_5;
			}
		}
		v4 = getMemByte(0x587000, 287004 + 8 * v2);
	} else {
	LABEL_5:
		LOBYTE(v4) = 0;
	}
	return v4;
}

//----- (00548FE0) --------------------------------------------------------
void sub_548FE0(int a1, const char* a2) {
	if (a1 && a2 && *(uint8_t*)(a1 + 8) & 2 && *(uint8_t*)(a1 + 12) & 8 && strlen(a2) < 0x20) {
		strcpy((char*)(*(uint32_t*)(a1 + 692) + 1684), a2);
	}
}

//----- (00549040) --------------------------------------------------------
int nox_xxx_monsterLoadStrikeFn_549040(int a1, char* a2) {
	int result;        // eax
	const char* v3;    // esi
	int v4;            // ebp
	unsigned char* v5; // edi

	if (_strcmpi("NULL", a2)) {
		v3 = *(const char**)getMemAt(0x587000, 287096);
		v4 = 0;
		if (*getMemU32Ptr(0x587000, 287096)) {
			v5 = getMemAt(0x587000, 287096);
			while (strcmp(a2, v3)) {
				v3 = (const char*)*((uint32_t*)v5 + 2);
				v5 += 8;
				++v4;
				if (!v3) {
					goto LABEL_7;
				}
			}
			*(uint32_t*)(a1 + 236) = *getMemU32Ptr(0x587000, 287100 + 8 * v4);
			result = 1;
		} else {
		LABEL_7:
			result = 0;
		}
	} else {
		*(uint32_t*)(a1 + 236) = 0;
		result = 1;
	}
	return result;
}

//----- (005490E0) --------------------------------------------------------
int nox_xxx_monsterLoadDieFn_5490E0(int a1, char* a2) {
	int result;        // eax
	const char* v3;    // esi
	int v4;            // ebp
	unsigned char* v5; // edi

	if (_strcmpi("NULL", a2)) {
		v3 = *(const char**)getMemAt(0x587000, 287280);
		v4 = 0;
		if (*getMemU32Ptr(0x587000, 287280)) {
			v5 = getMemAt(0x587000, 287280);
			while (strcmp(a2, v3)) {
				v3 = (const char*)*((uint32_t*)v5 + 2);
				v5 += 8;
				++v4;
				if (!v3) {
					goto LABEL_7;
				}
			}
			*(uint32_t*)(a1 + 228) = *getMemU32Ptr(0x587000, 287284 + 8 * v4);
			result = 1;
		} else {
		LABEL_7:
			result = 0;
		}
	} else {
		*(uint32_t*)(a1 + 228) = 0;
		result = 1;
	}
	return result;
}

//----- (00549180) --------------------------------------------------------
int nox_xxx_monsterLoadDeadFn_549180(int a1, char* a2) {
	int result;        // eax
	const char* v3;    // esi
	int v4;            // ebp
	unsigned char* v5; // edi

	if (_strcmpi("NULL", a2)) {
		v3 = *(const char**)getMemAt(0x587000, 287192);
		v4 = 0;
		if (*getMemU32Ptr(0x587000, 287192)) {
			v5 = getMemAt(0x587000, 287192);
			while (strcmp(a2, v3)) {
				v3 = (const char*)*((uint32_t*)v5 + 2);
				v5 += 8;
				++v4;
				if (!v3) {
					goto LABEL_7;
				}
			}
			*(uint32_t*)(a1 + 232) = *getMemU32Ptr(0x587000, 287196 + 8 * v4);
			result = 1;
		} else {
		LABEL_7:
			result = 0;
		}
	} else {
		*(uint32_t*)(a1 + 232) = 0;
		result = 1;
	}
	return result;
}

//----- (00549220) --------------------------------------------------------
int nox_xxx_strikeOgre_549220(float a1) {
	float2* v1; // eax
	double v2;  // st7
	int v4;     // [esp-4h] [ebp-4h]
	float v5;   // [esp+4h] [ebp+4h]

	v4 = LODWORD(a1);
	v1 = (float2*)(LODWORD(a1) + 56);
	v2 = *(float*)(*(uint32_t*)(*(uint32_t*)(LODWORD(a1) + 748) + 484) + 112) + *(float*)(LODWORD(a1) + 176);
	*getMemU32Ptr(0x5D4594, 2491556) = 0;
	v5 = v2 + *getMemFloatPtr(0x587000, 287328);
	nox_xxx_unitsGetInCircle_517F90(v1, v5, (int)sub_549270, v4);
	return *getMemU32Ptr(0x5D4594, 2491556);
}

//----- (00549270) --------------------------------------------------------
void sub_549270(int a1, int a2) {
	int v2;     // edi
	int v3;     // ebp
	double v4;  // st7
	double v5;  // st6
	float* v6;  // ebx
	int v7;     // eax
	float* v8;  // eax
	float v9;   // edx
	float v10;  // ecx
	float v11;  // edx
	float4 v12; // [esp+10h] [ebp-10h]
	float v13;  // [esp+28h] [ebp+8h]

	v2 = a2;
	v3 = *(uint32_t*)(a2 + 748);
	if (a2 != a1) {
		v4 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
		v5 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
		v6 = (float*)(a2 + 56);
		v7 = *(uint32_t*)(v3 + 484);
		v12.field_4 = v5;
		v13 = sqrt(v5 * v12.field_4 + v4 * v4) + 0.0099999998;
		if (v13 - (*(float*)(a1 + 176) + *(float*)(v2 + 176)) <= *(float*)(v7 + 112)) {
			v8 = getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(v2 + 124));
			if (v12.field_4 / v13 * v8[1] + v4 / v13 * *v8 > 0.40000001) {
				v9 = *v6;
				v10 = *(float*)(a1 + 56);
				v12.field_4 = *(float*)(v2 + 60);
				v12.field_0 = v9;
				v11 = *(float*)(a1 + 60);
				v12.field_8 = v10;
				v12.field_C = v11;
				if (nox_xxx_mapTraceRay_535250(&v12, 0, 0, 5)) {
					(*(void (**)(int, int, int, uint32_t, uint32_t))(a1 + 716))(
						a1, v2, v2, *(uint32_t*)(*(uint32_t*)(v3 + 484) + 116),
						*(uint32_t*)(*(uint32_t*)(v3 + 484) + 124));
					nox_xxx_objectApplyForce_52DF80(v2 + 56, a1, *(float*)(*(uint32_t*)(v3 + 484) + 120));
					*getMemU32Ptr(0x5D4594, 2491556) = 1;
				}
			}
		}
	}
}

//----- (00549380) --------------------------------------------------------
int nox_xxx_strikeMonsterDefault_549380(float a1) {
	float v1;   // edi
	int v2;     // ebp
	int v3;     // esi
	float v4;   // eax
	float v5;   // edx
	float v6;   // eax
	int result; // eax
	float4 v8;  // [esp+10h] [ebp-10h]
	float v9;   // [esp+24h] [ebp+4h]

	v1 = a1;
	v2 = *(uint32_t*)(LODWORD(a1) + 748);
	v3 = nox_xxx_monsterPickMeleeTarget_549440(SLODWORD(a1), 0);
	if (v3) {
		v4 = *(float*)(LODWORD(a1) + 56);
		v5 = *(float*)(v3 + 56);
		v8.field_4 = *(float*)(LODWORD(a1) + 60);
		v8.field_0 = v4;
		v6 = *(float*)(v3 + 60);
		v8.field_8 = v5;
		v8.field_C = v6;
		result = nox_xxx_mapTraceRay_535250(&v8, 0, 0, 5);
		if (!result) {
			return result;
		}
		(*(void (**)(int, uint32_t, uint32_t, uint32_t, uint32_t))(v3 + 716))(
			v3, LODWORD(a1), LODWORD(a1), *(uint32_t*)(*(uint32_t*)(v2 + 484) + 116),
			*(uint32_t*)(*(uint32_t*)(v2 + 484) + 124));
		v9 = *(float*)(*(uint32_t*)(v2 + 484) + 120);
		if (v9 > 0.0) {
			nox_xxx_objectApplyForce_52DF80(LODWORD(v1) + 56, v3, v9);
		}
	}
	return 1;
}

//----- (00549440) --------------------------------------------------------
int nox_xxx_monsterPickMeleeTarget_549440(int a3, int a2) {
	int v2;    // ecx
	double v3; // st7
	double v4; // st7
	int v5;    // edx
	float4 a1; // [esp+0h] [ebp-10h]

	v2 = *(uint32_t*)(a3 + 748);
	v3 = *(float*)(*(uint32_t*)(v2 + 484) + 112) + *(float*)(a3 + 176) + *getMemFloatPtr(0x587000, 287328);
	a1.field_0 = *(float*)(a3 + 56) - v3;
	a1.field_4 = *(float*)(a3 + 60) - v3;
	a1.field_8 = v3 + *(float*)(a3 + 56);
	v4 = v3 + *(float*)(a3 + 60);
	*getMemU32Ptr(0x5D4594, 2491568) = a2;
	a1.field_C = v4;
	v5 = *(uint32_t*)(*(uint32_t*)(v2 + 484) + 112);
	*getMemU32Ptr(0x5D4594, 2491564) = 0;
	*getMemU32Ptr(0x5D4594, 2491572) = v5;
	nox_xxx_getUnitsInRect_517C10(&a1, sub_5494C0, a3);
	return *getMemU32Ptr(0x5D4594, 2491564);
}

//----- (005494C0) --------------------------------------------------------
void sub_5494C0(float* a1, int a2) {
	int v2;    // edi
	int v3;    // eax
	double v4; // st7
	float* v5; // eax
	double v6; // st7
	float v7;  // [esp+Ch] [ebp-4h]
	int v8;    // [esp+18h] [ebp+8h]

	v2 = a2;
	if ((float*)a2 != a1 && (!((uint8_t)a1[4] & 0x11) || (uint8_t)a1[2] & 6)) {
		if ((uint8_t)a1[2] & 6 || (v3 = *((uint32_t*)a1 + 139)) != 0 && *(uint16_t*)(v3 + 4)) {
			if (nox_xxx_unitIsEnemyTo_5330C0(a2, (int)a1) || *getMemU32Ptr(0x5D4594, 2491568)) {
				v4 = a1[14] - *(float*)(a2 + 56);
				v7 = a1[15] - *(float*)(a2 + 60);
				v5 = getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a2 + 124));
				*(float*)&v8 = sqrt(v7 * v7 + v4 * v4) + 0.001;
				if (v7 / *(float*)&v8 * v5[1] + v4 / *(float*)&v8 * *v5 > 0.5) {
					v6 = *(float*)&v8 - (a1[44] + *(float*)(v2 + 176));
					if (v6 < *getMemFloatPtr(0x5D4594, 2491572)) {
						*getMemFloatPtr(0x5D4594, 2491572) = v6;
						*getMemU32Ptr(0x5D4594, 2491564) = a1;
					}
				}
			}
		}
	}
}

//----- (005495B0) --------------------------------------------------------
int nox_xxx_strikeScorpion_5495B0(float a1) {
	int v1;     // edi
	int v2;     // ebp
	int v3;     // esi
	float v4;   // eax
	float v5;   // edx
	float v6;   // eax
	int result; // eax
	float4 v8;  // [esp+10h] [ebp-10h]
	float v9;   // [esp+24h] [ebp+4h]

	v1 = LODWORD(a1);
	v2 = *(uint32_t*)(LODWORD(a1) + 748);
	v3 = nox_xxx_monsterPickMeleeTarget_549440(SLODWORD(a1), 0);
	if (v3) {
		v4 = *(float*)(LODWORD(a1) + 56);
		v5 = *(float*)(v3 + 56);
		v8.field_4 = *(float*)(LODWORD(a1) + 60);
		v8.field_0 = v4;
		v6 = *(float*)(v3 + 60);
		v8.field_8 = v5;
		v8.field_C = v6;
		result = nox_xxx_mapTraceRay_535250(&v8, 0, 0, 5);
		if (!result) {
			return result;
		}
		(*(void (**)(int, uint32_t, uint32_t, uint32_t, uint32_t))(v3 + 716))(
			v3, LODWORD(a1), LODWORD(a1), *(uint32_t*)(*(uint32_t*)(v2 + 484) + 116),
			*(uint32_t*)(*(uint32_t*)(v2 + 484) + 124));
		v9 = *(float*)(*(uint32_t*)(v2 + 484) + 120);
		if (v9 > 0.0) {
			nox_xxx_objectApplyForce_52DF80(v1 + 56, v3, v9);
		}
		if (sub_549690(v1, v3)) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(v3, "aifunc.c:PoisonedByScorpion", 0);
		}
	}
	return 1;
}

//----- (00549690) --------------------------------------------------------
int sub_549690(int a1, int a2) {
	int v2;     // ecx
	int v3;     // esi
	int result; // eax

	v2 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 484);
	result = 0;
	if (*(uint32_t*)(v2 + 136)) {
		v3 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 484);
		if (nox_common_randomInt_415FA0(1, 100) <= *(int*)(v2 + 136)) {
			if (nox_xxx_activatePoison_4EE7E0(a2, *(uint32_t*)(v3 + 140), *(uint32_t*)(v3 + 144))) {
				result = 1;
			}
		}
	}
	return result;
}

//----- (00549700) --------------------------------------------------------
int nox_xxx_strikeVileZombie_549700(float a1) {
	int v1;     // edi
	int v2;     // ebp
	int v3;     // esi
	float v4;   // eax
	float v5;   // edx
	float v6;   // eax
	int result; // eax
	float4 v8;  // [esp+10h] [ebp-10h]
	float v9;   // [esp+24h] [ebp+4h]

	v1 = LODWORD(a1);
	v2 = *(uint32_t*)(LODWORD(a1) + 748);
	v3 = nox_xxx_monsterPickMeleeTarget_549440(SLODWORD(a1), 0);
	if (v3) {
		v4 = *(float*)(LODWORD(a1) + 56);
		v5 = *(float*)(v3 + 56);
		v8.field_4 = *(float*)(LODWORD(a1) + 60);
		v8.field_0 = v4;
		v6 = *(float*)(v3 + 60);
		v8.field_8 = v5;
		v8.field_C = v6;
		result = nox_xxx_mapTraceRay_535250(&v8, 0, 0, 5);
		if (!result) {
			return result;
		}
		(*(void (**)(int, uint32_t, uint32_t, uint32_t, uint32_t))(v3 + 716))(
			v3, LODWORD(a1), LODWORD(a1), *(uint32_t*)(*(uint32_t*)(v2 + 484) + 116),
			*(uint32_t*)(*(uint32_t*)(v2 + 484) + 124));
		v9 = *(float*)(*(uint32_t*)(v2 + 484) + 120);
		if (v9 > 0.0) {
			nox_xxx_objectApplyForce_52DF80(v1 + 56, v3, v9);
		}
		if (sub_549690(v1, v3)) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(v3, "aifunc.c:PoisonedByZombie", 0);
		}
	}
	return 1;
}

//----- (005497E0) --------------------------------------------------------
int nox_xxx_strikeStoneGolem_5497E0(float a1) {
	*getMemU32Ptr(0x5D4594, 2491560) = 0;
	return nox_xxx_sendEquakeAfterGolem_549800(a1);
}

//----- (00549800) --------------------------------------------------------
int nox_xxx_sendEquakeAfterGolem_549800(float a1) {
	float2* v1; // esi
	double v2;  // st7
	int v4;     // [esp-4h] [ebp-8h]
	float v5;   // [esp+8h] [ebp+4h]

	v4 = LODWORD(a1);
	v1 = (float2*)(LODWORD(a1) + 56);
	v2 = *(float*)(*(uint32_t*)(*(uint32_t*)(LODWORD(a1) + 748) + 484) + 112) + *(float*)(LODWORD(a1) + 176);
	*getMemU32Ptr(0x5D4594, 2491576) = 0;
	v5 = v2 + *getMemFloatPtr(0x587000, 287328);
	nox_xxx_unitsGetInCircle_517F90(v1, v5, (int)nox_xxx_monsterAttackAreaDamage_549860, v4);
	nox_xxx_earthquakeSend_4D9110(&v1->field_0, 30);
	return *getMemU32Ptr(0x5D4594, 2491576);
}

//----- (00549860) --------------------------------------------------------
void nox_xxx_monsterAttackAreaDamage_549860(int a1, float a2) {
	int v2;    // esi
	bool v3;   // zf
	float v4;  // ecx
	float v5;  // eax
	float v6;  // ecx
	float4 v7; // [esp+10h] [ebp-10h]
	int v8;    // [esp+28h] [ebp+8h]
	float v9;  // [esp+28h] [ebp+8h]

	v2 = LODWORD(a2);
	v3 = LODWORD(a2) == a1;
	v8 = *(uint32_t*)(LODWORD(a2) + 748);
	if (!v3) {
		if (nox_server_testTwoPointsAndDirection_4E6E50((float2*)(v2 + 56), *(short*)(v2 + 124), (float2*)(a1 + 56)) &
			1) {
			if (nox_xxx_calcDistance_4E6C00(v2, a1) <= *(float*)(*(uint32_t*)(v8 + 484) + 112)) {
				v4 = *(float*)(v2 + 56);
				v5 = *(float*)(a1 + 56);
				v7.field_4 = *(float*)(v2 + 60);
				v7.field_0 = v4;
				v6 = *(float*)(a1 + 60);
				v7.field_8 = v5;
				v7.field_C = v6;
				if (nox_xxx_mapTraceRay_535250(&v7, 0, 0, 5)) {
					(*(void (**)(int, int, int, uint32_t, uint32_t))(a1 + 716))(
						a1, v2, v2, *(uint32_t*)(*(uint32_t*)(v8 + 484) + 116),
						*(uint32_t*)(*(uint32_t*)(v8 + 484) + 124));
					if (*(uint8_t*)(a1 + 8) & 6) {
						*getMemU32Ptr(0x5D4594, 2491576) = 1;
					}
					v9 = *(float*)(*(uint32_t*)(v8 + 484) + 120);
					if (v9 > 0.0) {
						nox_xxx_objectApplyForce_52DF80(v2 + 56, a1, v9);
					}
				}
			}
		}
	}
}

//----- (00549960) --------------------------------------------------------
int nox_xxx_strikeMechGolem_549960(float a1) {
	*getMemU32Ptr(0x5D4594, 2491560) = 1;
	return nox_xxx_sendEquakeAfterGolem_549800(a1);
}

//----- (00549980) --------------------------------------------------------
int nox_xxx_strikeWasp_549980(float a1) {
	float v1;  // edi
	int v2;    // ebp
	int v3;    // esi
	float v4;  // eax
	float v5;  // edx
	float v6;  // eax
	float4 v8; // [esp+10h] [ebp-10h]
	float v9;  // [esp+24h] [ebp+4h]

	v1 = a1;
	v2 = *(uint32_t*)(LODWORD(a1) + 748);
	v3 = nox_xxx_monsterPickMeleeTarget_549440(SLODWORD(a1), 0);
	if (!v3) {
		return 0;
	}
	v4 = *(float*)(LODWORD(a1) + 56);
	v5 = *(float*)(v3 + 56);
	v8.field_4 = *(float*)(LODWORD(a1) + 60);
	v8.field_0 = v4;
	v6 = *(float*)(v3 + 60);
	v8.field_8 = v5;
	v8.field_C = v6;
	if (!nox_xxx_mapTraceRay_535250(&v8, 0, 0, 5)) {
		return 0;
	}
	(*(void (**)(int, uint32_t, uint32_t, uint32_t, uint32_t))(v3 + 716))(v3, LODWORD(a1), LODWORD(a1),
																		  *(uint32_t*)(*(uint32_t*)(v2 + 484) + 116),
																		  *(uint32_t*)(*(uint32_t*)(v2 + 484) + 124));
	if (sub_549690(SLODWORD(a1), v3)) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(v3, "aifunc.c:PoisonedByWasp", 0);
	}
	v9 = *(float*)(*(uint32_t*)(v2 + 484) + 120);
	if (v9 > 0.0) {
		nox_xxx_objectApplyForce_52DF80(LODWORD(v1) + 56, v3, v9);
	}
	return 1;
}

//----- (00549A60) --------------------------------------------------------
int nox_xxx_strikeGhost_549A60(float a1) {
	int v1;     // edi
	int v2;     // ebp
	int v3;     // esi
	float v4;   // eax
	float v5;   // edx
	float v6;   // eax
	int result; // eax
	int* v8;    // eax
	int* v9;    // ebx
	int* v10;   // eax
	float4 v11; // [esp+10h] [ebp-10h]
	float v12;  // [esp+24h] [ebp+4h]

	v1 = LODWORD(a1);
	v2 = *(uint32_t*)(LODWORD(a1) + 748);
	v3 = nox_xxx_monsterPickMeleeTarget_549440(SLODWORD(a1), 0);
	if (v3) {
		v4 = *(float*)(LODWORD(a1) + 56);
		v5 = *(float*)(v3 + 56);
		v11.field_4 = *(float*)(LODWORD(a1) + 60);
		v11.field_0 = v4;
		v6 = *(float*)(v3 + 60);
		v11.field_8 = v5;
		v11.field_C = v6;
		result = nox_xxx_mapTraceRay_535250(&v11, 0, 0, 5);
		if (!result) {
			return result;
		}
		(*(void (**)(int, uint32_t, uint32_t, uint32_t, uint32_t))(v3 + 716))(
			v3, LODWORD(a1), LODWORD(a1), *(uint32_t*)(*(uint32_t*)(v2 + 484) + 116),
			*(uint32_t*)(*(uint32_t*)(v2 + 484) + 124));
		v12 = *(float*)(*(uint32_t*)(v2 + 484) + 120);
		if (v12 > 0.0) {
			nox_xxx_objectApplyForce_52DF80(v1 + 56, v3, v12);
		}
		nox_xxx_buffApplyTo_4FF380(v3, 5, 2 * (uint16_t)nox_gameFPS, 3);
		v8 = nox_xxx_monsterPushAction_50A260(v1, 25);
		if (v8) {
			v8[1] = *(uint32_t*)(v3 + 56);
			v8[2] = *(uint32_t*)(v3 + 60);
		}
		v9 = nox_xxx_monsterPushAction_50A260(v1, 41);
		if (v9) {
			v9[1] = nox_frame_xxx_2598000 + nox_common_randomInt_415FA0(2 * nox_gameFPS, 4 * nox_gameFPS);
		}
		v10 = nox_xxx_monsterPushAction_50A260(v1, 24);
		if (v10) {
			v10[1] = *(uint32_t*)(v3 + 56);
			v10[2] = *(uint32_t*)(v3 + 60);
			v10[3] = 0;
		}
	}
	return 1;
}

//----- (00549BB0) --------------------------------------------------------
int nox_xxx_strikeBomber_549BB0() { return 1; }

//----- (00549BC0) --------------------------------------------------------
int nox_xxx_strikeSpider_549BC0(float a1) {
	int v1;    // edi
	int v2;    // ebp
	int v3;    // esi
	float v4;  // eax
	float v5;  // edx
	float v6;  // eax
	float4 v8; // [esp+10h] [ebp-10h]
	float v9;  // [esp+24h] [ebp+4h]

	v1 = LODWORD(a1);
	v2 = *(uint32_t*)(LODWORD(a1) + 748);
	v3 = nox_xxx_monsterPickMeleeTarget_549440(SLODWORD(a1), 0);
	if (!v3) {
		return 0;
	}
	v4 = *(float*)(LODWORD(a1) + 56);
	v5 = *(float*)(v3 + 56);
	v8.field_4 = *(float*)(LODWORD(a1) + 60);
	v8.field_0 = v4;
	v6 = *(float*)(v3 + 60);
	v8.field_8 = v5;
	v8.field_C = v6;
	if (!nox_xxx_mapTraceRay_535250(&v8, 0, 0, 5)) {
		return 0;
	}
	(*(void (**)(int, uint32_t, uint32_t, uint32_t, uint32_t))(v3 + 716))(v3, LODWORD(a1), LODWORD(a1),
																		  *(uint32_t*)(*(uint32_t*)(v2 + 484) + 116),
																		  *(uint32_t*)(*(uint32_t*)(v2 + 484) + 124));
	v9 = *(float*)(*(uint32_t*)(v2 + 484) + 120);
	if (v9 > 0.0) {
		nox_xxx_objectApplyForce_52DF80(v1 + 56, v3, v9);
	}
	if (sub_549690(v1, v3)) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(v3, "aifunc.c:Poisoned", 0);
	}
	return 1;
}

//----- (00549CA0) --------------------------------------------------------
int nox_xxx_strikeSpittingSpider_549CA0(float a1) {
	int v1;    // edi
	int v2;    // ebp
	int v3;    // esi
	float v4;  // eax
	float v5;  // edx
	float v6;  // eax
	float4 v8; // [esp+10h] [ebp-10h]
	float v9;  // [esp+24h] [ebp+4h]

	v1 = LODWORD(a1);
	v2 = *(uint32_t*)(LODWORD(a1) + 748);
	v3 = nox_xxx_monsterPickMeleeTarget_549440(SLODWORD(a1), 0);
	if (!v3) {
		return 0;
	}
	v4 = *(float*)(LODWORD(a1) + 56);
	v5 = *(float*)(v3 + 56);
	v8.field_4 = *(float*)(LODWORD(a1) + 60);
	v8.field_0 = v4;
	v6 = *(float*)(v3 + 60);
	v8.field_8 = v5;
	v8.field_C = v6;
	if (!nox_xxx_mapTraceRay_535250(&v8, 0, 0, 5)) {
		return 0;
	}
	(*(void (**)(int, uint32_t, uint32_t, uint32_t, uint32_t))(v3 + 716))(v3, LODWORD(a1), LODWORD(a1),
																		  *(uint32_t*)(*(uint32_t*)(v2 + 484) + 116),
																		  *(uint32_t*)(*(uint32_t*)(v2 + 484) + 124));
	v9 = *(float*)(*(uint32_t*)(v2 + 484) + 120);
	if (v9 > 0.0) {
		nox_xxx_objectApplyForce_52DF80(v1 + 56, v3, v9);
	}
	if (sub_549690(v1, v3)) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(v3, "aifunc.c:Poisoned", 0);
	}
	return 1;
}

//----- (00549D80) --------------------------------------------------------
int sub_549D80(int a1) {
	int v1; // esi

	v1 = nox_common_gameFlags_check_40A5C0(2048) ? 30 : 96;
	nox_xxx_mapPushUnitsAround_52E040(a1 + 56, 96.0, 1092616192, 100.0, a1, 0, 0);
	nox_xxx_mapDamageUnitsAround_4E25B0(a1 + 56, 96.0, 10.0, v1, 7, a1, 0);
	nox_xxx_netSparkExplosionFx_5231B0((float*)(a1 + 56), 128);
	nox_xxx_aud_501960(42, a1, 0, 0);
	nox_xxx_delayedDeleteObject_4E5CC0(a1);
	return 1;
}

//----- (00549E00) --------------------------------------------------------
int sub_549E00(int a1) {
	nox_xxx_mapPushUnitsAround_52E040(a1 + 56, 150.0, 1092616192, 150.0, a1, 0, 0);
	nox_xxx_mapDamageUnitsAround_4E25B0(a1 + 56, 150.0, 10.0, 148, 7, a1, 0);
	nox_xxx_netSparkExplosionFx_5231B0((float*)(a1 + 56), 255);
	nox_xxx_aud_501960(42, a1, 0, 0);
	nox_xxx_delayedDeleteObject_4E5CC0(a1);
	return 1;
}

//----- (00549E70) --------------------------------------------------------
int sub_549E70(int a1) {
	nox_xxx_netSendPointFx_522FF0(129, (float2*)(a1 + 56));
	return 1;
}

//----- (00549E90) --------------------------------------------------------
int sub_549E90(int a1) {
	char** v1;         // eax
	unsigned char* v2; // edi
	float* v3;         // esi
	double v4;         // st7
	int v5;            // ecx
	int v6;            // eax
	int v7;            // ecx
	float v9;          // [esp+0h] [ebp-18h]
	float2 a3;         // [esp+10h] [ebp-8h]

	nox_xxx_aud_501960(494, a1, 0, 0);
	nox_xxx_netSendPointFx_522FF0(138, (float2*)(a1 + 56));
	if (*getMemU32Ptr(0x587000, 287976)) {
		v1 = (char**)getMemAt(0x587000, 287976);
		v2 = getMemAt(0x587000, 287976);
		do {
			v3 = (float*)nox_xxx_newObjectByTypeID_4E3810(*v1);
			if (!v3) {
				break;
			}
			sub_4ED970(30.0, (float2*)(a1 + 56), &a3);
			nox_xxx_createAt_4DAA50((int)v3, 0, a3.field_0, a3.field_4);
			v9 = nox_common_randomFloat_416030(10.0, 70.0);
			nox_xxx_unitRaise_4E46F0((int)v3, v9);
			v4 = nox_common_randomFloat_416030(-2.0, 0.0);
			v5 = *((uint32_t*)v3 + 4);
			v3[27] = v4;
			v3[29] = 2.0;
			*((uint32_t*)v3 + 4) = 0x800000 | v5;
			v6 = nox_common_randomInt_415FA0(10, 20);
			nox_xxx_unitSetDecayTime_511660(v3, nox_gameFPS * v6);
			v7 = *((uint32_t*)v2 + 1);
			v2 += 4;
			v1 = (char**)v2;
		} while (v7);
	}
	return 1;
}

//----- (00549FA0) --------------------------------------------------------
int sub_549FA0(int a1) {
	float2* v1; // edi
	int v2;     // ebp
	int v3;     // edx
	float* v4;  // esi
	double v5;  // st7
	int v6;     // eax
	float v8;   // [esp+0h] [ebp-1Ch]
	float v9;   // [esp+0h] [ebp-1Ch]
	float2 a3;  // [esp+14h] [ebp-8h]
	int v11;    // [esp+20h] [ebp+4h]

	nox_xxx_aud_501960(487, a1, 0, 0);
	v1 = (float2*)(a1 + 56);
	nox_xxx_netSendPointFx_522FF0(138, (float2*)(a1 + 56));
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v11 = nox_common_randomInt_415FA0(20, 30);
	} else {
		v11 = 6;
	}
	v2 = 0;
	if (v11 > 0) {
		v3 = dword_5d4594_2491580;
		do {
			v4 = (float*)nox_xxx_newObjectByTypeID_4E3810(*(char**)getMemAt(0x587000, 288240 + 4 * v3));
			if (!v4) {
				break;
			}
			sub_4ED970(30.0, v1, &a3);
			nox_xxx_createAt_4DAA50((int)v4, 0, a3.field_0, a3.field_4);
			v8 = nox_common_randomFloat_416030(10.0, 70.0);
			nox_xxx_unitRaise_4E46F0((int)v4, v8);
			v4[27] = nox_common_randomFloat_416030(-2.0, 0.0);
			v5 = (double)getMemByte(0x587000, 287332 + dword_5d4594_2491580);
			*((uint32_t*)v4 + 4) |= 0x800000;
			v4[29] = v5;
			v9 = nox_common_randomFloat_416030(5.0, 20.0);
			nox_xxx_objectApplyForce_52DF80((int)v1, (int)v4, v9);
			v6 = nox_common_gameFlags_check_40A5C0(2048) ? nox_common_randomInt_415FA0(10, 20)
														 : nox_common_randomInt_415FA0(5, 10);
			nox_xxx_unitSetDecayTime_511660(v4, nox_gameFPS * v6);
			v3 = (dword_5d4594_2491580 + 1) % *getMemU32Ptr(0x587000, 287344);
			++v2;
			dword_5d4594_2491580 = (dword_5d4594_2491580 + 1) % *getMemU32Ptr(0x587000, 287344);
		} while (v2 < v11);
	}
	return 1;
}

//----- (0054A150) --------------------------------------------------------
int sub_54A150(int a1) {
	int v1;       // edi
	uint32_t* v2; // ebx
	int v3;       // esi
	uint32_t* v4; // ebp
	int v6;       // [esp+Ch] [ebp-4h]
	int v7;       // [esp+14h] [ebp+4h]

	v1 = a1;
	v2 = (uint32_t*)(a1 + 56);
	v6 = *(uint32_t*)(a1 + 748);
	nox_xxx_netSendPointFx_522FF0(133, (float2*)(a1 + 56));
	nox_xxx_aud_501960(368, a1, 0, 0);
	v3 = *(uint32_t*)(a1 + 504);
	if (v3) {
		v4 = *(uint32_t**)(v3 + 692);
		v7 = *(uint32_t*)(v3 + 508);
		sub_4ED0C0(v1, (int*)v3);
		nox_xxx_unitSetOwner_4EC290(v7, v3);
		v4[7] = *v2;
		v4[8] = *(uint32_t*)(v1 + 60);
		v4[6] = 0;
		*(uint16_t*)(v3 + 126) = *(uint16_t*)(v1 + 124);
		*(uint16_t*)(v3 + 124) = *(uint16_t*)(v1 + 124);
		*(uint32_t*)(v3 + 64) = *(uint32_t*)(v1 + 64);
		*(uint32_t*)(v3 + 68) = *(uint32_t*)(v1 + 68);
		*(uint32_t*)(v3 + 56) = *v2;
		*(uint32_t*)(v3 + 60) = v2[1];
		nox_xxx_trapBAH_537C10(v3, *(uint32_t*)(v6 + 2176));
	} else {
		nox_xxx_mapDamageUnitsAround_4E25B0((int)v2, 50.0, 30.0, 10, 7, a1, 0);
		nox_xxx_mapPushUnitsAround_52E040((int)v2, 50.0, 1106247680, 30.0, a1, 0, 0);
	}
	return 1;
}

//----- (0054A250) --------------------------------------------------------
int sub_54A250(int a1) {
	nox_xxx_netSendPointFx_522FF0(129, (float2*)(a1 + 56));
	return 1;
}

//----- (0054A270) --------------------------------------------------------
int nox_xxx_monsterDeadTroll_54A270(int a1) {
	int v1;       // eax
	uint32_t* v2; // eax
	uint32_t* v3; // edi
	float v5;     // [esp+0h] [ebp-14h]

	v1 = *getMemU32Ptr(0x5D4594, 2491584);
	if (!*getMemU32Ptr(0x5D4594, 2491584)) {
		v1 = nox_xxx_getNameId_4E3AA0("SmallToxicCloud");
		*getMemU32Ptr(0x5D4594, 2491584) = v1;
	}
	v2 = nox_xxx_newObjectWithTypeInd_4E3450(v1);
	if (v2) {
		v3 = (uint32_t*)v2[187];
		nox_xxx_createAt_4DAA50((int)v2, a1, *(float*)(a1 + 56), *(float*)(a1 + 60));
		nox_xxx_aud_501960(644, a1, 0, 0);
		v5 = nox_xxx_gamedataGetFloat_419D40("SmallToxicCloudLifetime") * (double)(int)nox_gameFPS;
		*v3 = nox_float2int(v5);
	}
	return 1;
}

//----- (0054A310) --------------------------------------------------------
int sub_54A310(int a1) {
	int v1; // esi

	v1 = nox_common_randomInt_415FA0(0, 100);
	sub_54A4C0(a1);
	if (v1 > 20) {
		if (v1 <= 50) {
			sub_54A390(a1, "Sword", "WeaponPower1", "Material2", 0, 0, 0);
			return 1;
		}
		sub_54A390(a1, "WoodenShield", 0, "Material2", 0, 0, 0);
	}
	return 1;
}

//----- (0054A390) --------------------------------------------------------
void sub_54A390(int a1, char* a2, const char* a3, const char* a4, const char* a5, const char* a6, int a7) {
	int result;            // eax
	int v8;                // esi
	int v9;                // eax
	int v10;               // eax
	int v11;               // eax
	int v12;               // eax
	float2 a3a;            // [esp+4h] [ebp-1Ch]
	unsigned char v14[20]; // [esp+Ch] [ebp-14h]

	if (nox_common_gameFlags_check_40A5C0(2048)) {
		result = (int)nox_xxx_newObjectByTypeID_4E3810(a2);
		v8 = result;
		if (result) {
			sub_4ED970(50.0, (float2*)(a1 + 56), &a3a);
			nox_xxx_createAt_4DAA50(v8, 0, a3a.field_0, a3a.field_4);
			if (*(uint32_t*)(v8 + 8) & 0x13001000 && (a3 || a4 || a5 || a6)) {
				v9 = nox_xxx_modifGetIdByName_413290(a3);
				*(uint32_t*)v14 = nox_xxx_modifGetDescById_413330(v9);
				v10 = nox_xxx_modifGetIdByName_413290(a4);
				*(uint32_t*)&v14[4] = nox_xxx_modifGetDescById_413330(v10);
				v11 = nox_xxx_modifGetIdByName_413290(a5);
				*(uint32_t*)&v14[8] = nox_xxx_modifGetDescById_413330(v11);
				v12 = nox_xxx_modifGetIdByName_413290(a6);
				*(uint32_t*)&v14[12] = nox_xxx_modifGetDescById_413330(v12);
				nox_xxx_modifSetItemAttrs_4E4990(v8, (int*)v14);
			}
			if (a7 && *(uint32_t*)(v8 + 8) & 0x1000000 && *(uint8_t*)(v8 + 12) & 0x82) {
				*(uint8_t*)(*(uint32_t*)(v8 + 736) + 1) = a7;
			}
			result = *(uint32_t*)(v8 + 8);
			if (result & 0x2000000) {
				sub_53EAE0(v8);
			} else if (result & 0x1001000) {
				sub_53AAB0(v8);
			}
		}
	}
}

//----- (0054A4C0) --------------------------------------------------------
void sub_54A4C0(int a1) {
	float2* v1; // edi
	float* v2;  // esi
	double v3;  // st7
	int v4;     // ecx
	int v5;     // eax
	int v6;     // eax
	int v7;     // eax
	int v8;     // edx
	float* v9;  // esi
	double v10; // st7
	int v11;    // ecx
	int v12;    // eax
	bool v13;   // cc
	float v15;  // [esp+0h] [ebp-18h]
	float v16;  // [esp+0h] [ebp-18h]
	float v17;  // [esp+0h] [ebp-18h]
	int v18;    // [esp+Ch] [ebp-Ch]
	float2 a3;  // [esp+10h] [ebp-8h]
	int v20;    // [esp+1Ch] [ebp+4h]

	nox_xxx_aud_501960(356, a1, 0, 0);
	v1 = (float2*)(a1 + 56);
	nox_xxx_netSendPointFx_522FF0(138, (float2*)(a1 + 56));
	v2 = (float*)nox_xxx_newObjectByTypeID_4E3810("Skull");
	if (v2) {
		sub_4ED970(20.0, v1, &a3);
		nox_xxx_createAt_4DAA50((int)v2, 0, a3.field_0, a3.field_4);
		nox_xxx_unitRaise_4E46F0((int)v2, 40.0);
		v3 = nox_common_randomFloat_416030(-2.0, 0.0);
		v4 = *((uint32_t*)v2 + 4);
		v2[27] = v3;
		v2[29] = 4.0;
		*((uint32_t*)v2 + 4) = 0x800000 | v4;
		v15 = nox_common_randomFloat_416030(5.0, 25.0);
		nox_xxx_objectApplyForce_52DF80((int)v1, (int)v2, v15);
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			v5 = nox_common_randomInt_415FA0(10, 20);
			nox_xxx_unitSetDecayTime_511660(v2, nox_gameFPS * v5);
			v6 = nox_common_randomInt_415FA0(10, 20);
		} else {
			v7 = nox_common_randomInt_415FA0(2, 5);
			nox_xxx_unitSetDecayTime_511660(v2, nox_gameFPS * v7);
			v6 = nox_common_randomInt_415FA0(5, 10);
		}
		v20 = v6;
		v18 = 0;
		if (v6 > 0) {
			v8 = dword_5d4594_2491588;
			do {
				v9 = (float*)nox_xxx_newObjectByTypeID_4E3810(*(char**)getMemAt(0x587000, 288868 + 4 * v8));
				if (!v9) {
					break;
				}
				sub_4ED970(20.0, v1, &a3);
				nox_xxx_createAt_4DAA50((int)v9, 0, a3.field_0, a3.field_4);
				v16 = nox_common_randomFloat_416030(10.0, 35.0);
				nox_xxx_unitRaise_4E46F0((int)v9, v16);
				v10 = nox_common_randomFloat_416030(-2.0, 0.0);
				v11 = *((uint32_t*)v9 + 4);
				v9[27] = v10;
				v9[29] = 4.0;
				*((uint32_t*)v9 + 4) = 0x800000 | v11;
				v17 = nox_common_randomFloat_416030(5.0, 25.0);
				nox_xxx_objectApplyForce_52DF80((int)v1, (int)v9, v17);
				v12 = nox_common_gameFlags_check_40A5C0(2048) ? nox_common_randomInt_415FA0(10, 20)
															  : nox_common_randomInt_415FA0(2, 5);
				nox_xxx_unitSetDecayTime_511660(v9, nox_gameFPS * v12);
				v8 = (dword_5d4594_2491588 + 1) % *getMemU32Ptr(0x587000, 287348);
				v13 = ++v18 < v20;
				dword_5d4594_2491588 = (dword_5d4594_2491588 + 1) % *getMemU32Ptr(0x587000, 287348);
			} while (v13);
		}
	}
}

//----- (0054A750) --------------------------------------------------------
int sub_54A750(int a1) {
	int v1; // esi

	v1 = nox_common_randomInt_415FA0(0, 100);
	sub_54A4C0(a1);
	if (v1 > 20) {
		if (v1 <= 50) {
			sub_54A390(a1, "Sword", "WeaponPower1", "Material2", 0, 0, 0);
			return 1;
		}
		sub_54A390(a1, "SteelShield", 0, "Material2", 0, 0, 0);
	}
	return 1;
}

//----- (0054A7D0) --------------------------------------------------------
int sub_54A7D0(int a1) {
	int v1; // eax

	v1 = nox_common_randomInt_415FA0(0, 100);
	if (v1 > 20) {
		if (v1 <= 50) {
			sub_54A390(a1, "Sword", "WeaponPower1", "Material1", 0, 0, 0);
			return 1;
		}
		sub_54A390(a1, "WoodenShield", 0, "Material1", 0, 0, 0);
	}
	return 1;
}

//----- (0054A850) --------------------------------------------------------
int sub_54A850(int a1) {
	if (nox_common_randomInt_415FA0(0, 100) > 25) {
		sub_54A390(a1, "StaffWooden", "WeaponPower1", 0, 0, 0, 0);
	}
	return 1;
}

//----- (0054A890) --------------------------------------------------------
int sub_54A890(int a1) {
	int v1; // eax

	v1 = nox_common_randomInt_415FA0(0, 100);
	if (v1 > 20) {
		if (v1 <= 50) {
			sub_54A390(a1, "Bow", 0, 0, 0, 0, 0);
			return 1;
		}
		sub_54A390(a1, "Quiver", 0, 0, 0, 0, 0);
	}
	return 1;
}

//----- (0054A900) --------------------------------------------------------
int sub_54A900(int a1) {
	if (nox_common_randomInt_415FA0(0, 100) > 25) {
		sub_54A390(a1, "OgreAxe", "WeaponPower1", "Material2", 0, 0, 0);
	}
	return 1;
}

//----- (0054A950) --------------------------------------------------------
int sub_54A950(int a1) {
	if (nox_common_randomInt_415FA0(0, 100) > 25) {
		sub_54A390(a1, "FanChakram", 0, 0, 0, 0, 5);
	}
	return 1;
}

//----- (0054A990) --------------------------------------------------------
double sub_54A990(float2* a1, float a2, int a3, float2* a4) {
	int v4;          // ecx
	float2* v5;      // edx
	double result;   // st7
	char v7;         // al
	int v8;          // eax
	double v9;       // st7
	long double v10; // st7
	double v11;      // st7
	long double v12; // st7
	double v13;      // st7
	long double v14; // st7
	char v15;        // [esp+0h] [ebp-30h]
	float v16;       // [esp+0h] [ebp-30h]
	float v17;       // [esp+4h] [ebp-2Ch]
	float v18;       // [esp+8h] [ebp-28h]
	float v19;       // [esp+8h] [ebp-28h]
	float v20;       // [esp+Ch] [ebp-24h]
	float v21;       // [esp+10h] [ebp-20h]
	float v22;       // [esp+14h] [ebp-1Ch]
	float v23;       // [esp+18h] [ebp-18h]
	float v24;       // [esp+1Ch] [ebp-14h]
	float v25;       // [esp+20h] [ebp-10h]
	float v26;       // [esp+24h] [ebp-Ch]
	float v27;       // [esp+28h] [ebp-8h]
	float v28;       // [esp+2Ch] [ebp-4h]
	float v29;       // [esp+34h] [ebp+4h]
	float v30;       // [esp+34h] [ebp+4h]
	float v31;       // [esp+3Ch] [ebp+Ch]
	float v32;       // [esp+3Ch] [ebp+Ch]

	v4 = a3;
	v5 = a1;
	result = -1.0;
	v15 = 0;
	v21 = *(float*)(a3 + 192) + *(float*)(a3 + 64);
	v22 = *(float*)(a3 + 196) + *(float*)(a3 + 68);
	v25 = *(float*)(a3 + 200) + *(float*)(a3 + 64);
	v26 = *(float*)(a3 + 204) + *(float*)(a3 + 68);
	v23 = *(float*)(a3 + 208) + *(float*)(a3 + 64);
	v24 = *(float*)(a3 + 212) + *(float*)(a3 + 68);
	v27 = *(float*)(a3 + 216) + *(float*)(a3 + 64);
	v28 = *(float*)(a3 + 220) + *(float*)(a3 + 68);
	v31 = (v22 - v21 + a1->field_0 - a1->field_4) * 0.70709997;
	v29 = (v26 - v25 + a1->field_0 - a1->field_4) * 0.70709997;
	v17 = (v24 + v23 - v5->field_0 - v5->field_4) * 0.70709997;
	v18 = (v22 + v21 - v5->field_0 - v5->field_4) * 0.70709997;
	if (v31 <= 0.0) {
		if (v29 < 0.0) {
			v15 = 2;
		}
	} else {
		v15 = 1;
	}
	if (v17 >= 0.0) {
		if (v18 <= 0.0) {
			goto LABEL_10;
		}
		v7 = v15 | 4;
	} else {
		v7 = v15 | 8;
	}
	v15 = v7;
LABEL_10:
	switch (v15) {
	case 0:
		v19 = v5->field_0 - *(float*)(v4 + 64);
		v20 = v5->field_4 - *(float*)(v4 + 68);
		if (v19 == 0.0 && v20 == 0.0) {
			v8 = nox_common_randomInt_415FA0(0, 3);
			v19 = *getMemFloatPtr(0x587000, 289928 + 8 * v8);
			v20 = *getMemFloatPtr(0x587000, 289932 + 8 * v8);
		}
		result = sqrt(v20 * v20 + v19 * v19);
		if (result == 0.0) {
			result = 0.1;
		}
		a4->field_0 = v19 / result;
		a4->field_4 = v20 / result;
		return result;
	case 1:
		result = a2 - v31;
		a4->field_0 = 0.70709997;
		a4->field_4 = -0.70709997;
		return result;
	case 2:
		result = a2 - -v29;
		a4->field_0 = -0.70709997;
		a4->field_4 = 0.70709997;
		return result;
	case 4:
		result = a2 - v18;
		a4->field_0 = -0.70709997;
		a4->field_4 = -0.70709997;
		return result;
	case 5:
		v30 = v5->field_0 - v21;
		v9 = v5->field_4 - v22;
		goto LABEL_22;
	case 6:
		v30 = v5->field_0 - v25;
		v13 = v5->field_4 - v26;
		v16 = v13;
		v14 = sqrt(v13 * v16 + v30 * v30);
		v32 = v14;
		if (v14 == 0.0) {
			v32 = 0.1;
		}
		result = a2 - v32;
		if (result >= 0.0) {
			goto LABEL_32;
		}
		return result;
	case 8:
		result = a2 - -v17;
		a4->field_0 = 0.70709997;
		a4->field_4 = 0.70709997;
		return result;
	case 9:
		v30 = v5->field_0 - v23;
		v9 = v5->field_4 - v24;
	LABEL_22:
		v16 = v9;
		v10 = sqrt(v9 * v16 + v30 * v30);
		v32 = v10;
		if (v10 == 0.0) {
			goto LABEL_26;
		}
		goto LABEL_27;
	case 0xA:
		v30 = v5->field_0 - v27;
		v11 = v5->field_4 - v28;
		v16 = v11;
		v12 = sqrt(v11 * v16 + v30 * v30);
		v32 = v12;
		if (v12 == 0.0) {
		LABEL_26:
			v32 = 0.1;
		}
	LABEL_27:
		result = a2 - v32;
		if (result >= 0.0) {
		LABEL_32:
			a4->field_0 = v30 / v32;
			a4->field_4 = v16 / v32;
		}
		break;
	default:
		return result;
	}
	return result;
}

//----- (0054AD50) --------------------------------------------------------
void sub_54AD50(int a1, int a2, int a3) {
	int v3;     // esi
	int v4;     // edi
	int v5;     // ebp
	double v6;  // st7
	float v7;   // eax
	float v8;   // edx
	float v9;   // eax
	int v10;    // ebx
	int v11;    // eax
	double v12; // st7
	double v13; // st7
	double v14; // st6
	double v15; // st7
	double v16; // st7
	float v17;  // [esp+0h] [ebp-34h]
	float v18;  // [esp+4h] [ebp-30h]
	float v19;  // [esp+18h] [ebp-1Ch]
	float2 a4;  // [esp+1Ch] [ebp-18h]
	float4 a1a; // [esp+24h] [ebp-10h]
	int v22;    // [esp+38h] [ebp+4h]
	int v23;    // [esp+38h] [ebp+4h]
	float a3c;  // [esp+3Ch] [ebp+8h]
	int a3a;    // [esp+3Ch] [ebp+8h]
	int a3b;    // [esp+3Ch] [ebp+8h]
	float v27;  // [esp+40h] [ebp+Ch]

	v3 = a1;
	v4 = a2;
	v5 = 1;
	v6 = sub_54A990((float2*)(a1 + 64), *(float*)(a1 + 176), a2, &a4);
	if (v6 >= 0.0) {
		if (!(*(uint32_t*)(a1 + 8) & 0x2204) || !(*(uint32_t*)(a2 + 8) & 0x2204) ||
			(v7 = *(float*)(a1 + 56), v8 = *(float*)(a2 + 56), a1a.field_4 = *(float*)(a1 + 60), a1a.field_0 = v7,
			 v9 = *(float*)(a2 + 60), a1a.field_8 = v8, a1a.field_C = v9, nox_xxx_mapTraceRay_535250(&a1a, 0, 0, 0))) {
			nox_xxx_collSysAddCollision_548630(a1, a2, &a4);
			if ((*(uint8_t*)(a1 + 16) & 8) == 8 || (*(uint8_t*)(a2 + 16) & 8) == 8) {
				v5 = 0;
			}
			v10 = a3;
			if (a3 || !(*(uint8_t*)(a1 + 8) & 6) || (v11 = *(uint32_t*)(a2 + 16), !(v11 & 0x2000))) {
				if (v5) {
					a3c = v6;
					v12 = *(float*)&dword_587000_292488 * a3c;
					a1a.field_4 = a4.field_0;
					*(float*)&v22 = a4.field_0 * v12;
					*(float*)&a3a = a4.field_4 * v12;
					v13 = *(float*)(v3 + 80) - *(float*)(v4 + 80);
					v14 = *(float*)(v3 + 84) - *(float*)(v4 + 84);
					a1a.field_0 = -a4.field_4;
					v19 = a1a.field_0 * v13 + v14 * a4.field_0;
					v27 = nox_xxx_objectGetMass_4E4A70(v3);
					if (nox_xxx_objectGetMass_4E4A70(v4) <= v27) {
						v15 = nox_xxx_objectGetMass_4E4A70(v4);
					} else {
						v15 = nox_xxx_objectGetMass_4E4A70(v3);
					}
					v16 = v15 * v19;
					*(float*)&v23 = *(float*)&v22 - v16 * a1a.field_0 * 0.69999999;
					*(float*)&a3b = *(float*)&a3a - v16 * a1a.field_4 * 0.69999999;
					if (v10) {
						v18 = -*(float*)&a3b;
						v17 = -*(float*)&v23;
						sub_548600(v4, v17, v18);
					} else {
						sub_548600(v3, *(float*)&v23, *(float*)&a3b);
					}
				}
			}
			if (*(uint32_t*)(v3 + 16) & 0x8000000) {
				nox_xxx_unitHasCollideOrUpdateFn_537610(v3);
				*(uint32_t*)(v3 + 16) &= 0xF7FFFFFF;
			}
			if (*(uint32_t*)(v4 + 16) & 0x8000000) {
				nox_xxx_unitHasCollideOrUpdateFn_537610(v4);
				*(uint32_t*)(v4 + 16) &= 0xF7FFFFFF;
			}
		}
	}
}

//----- (0054AF40) --------------------------------------------------------
nox_object_t* nox_xxx_findObjectAtCursor_54AF40(nox_object_t* a1p) {
	int a1 = a1p;
	int v1;     // eax
	double v2;  // st7
	float2 a1a; // [esp+0h] [ebp-8h]

	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	a1a.field_0 = (double)*(int*)(v1 + 2284);
	v2 = (double)*(int*)(v1 + 2288);
	dword_5d4594_2491592 = a1;
	a1a.field_4 = v2;
	*getMemU32Ptr(0x5D4594, 2491596) = 0;
	*getMemU32Ptr(0x5D4594, 2491600) = 0;
	nox_xxx_unitsGetInCircle_517F90(&a1a, 100.0, (int)nox_xxx_playerCursorScanFn_54AFB0, (int)&a1a);
	return *getMemU32Ptr(0x5D4594, 2491596);
}

//----- (0054AFB0) --------------------------------------------------------
void nox_xxx_playerCursorScanFn_54AFB0(int a1, float* a2) {
	float* v2;  // esi
	char* v3;   // eax
	int v4;     // eax
	double v5;  // st7
	float v6;   // ecx
	int v7;     // eax
	double v8;  // st7
	double v9;  // st6
	double v10; // st7
	double v11; // st6
	double v12; // st7
	float v13;  // [esp+0h] [ebp-28h]
	float v14;  // [esp+10h] [ebp-18h]
	float2 a3;  // [esp+18h] [ebp-10h]
	float2 a1a; // [esp+20h] [ebp-8h]
	float v17;  // [esp+2Ch] [ebp+4h]

	if (!*getMemU32Ptr(0x5D4594, 2491604)) {
		*getMemU32Ptr(0x5D4594, 2491604) = nox_xxx_getNameId_4E3AA0("Polyp");
	}
	v2 = (float*)a1;
	if (a1 != dword_5d4594_2491592 && !(*(uint32_t*)(a1 + 16) & 0x8020) &&
		(!nox_xxx_testUnitBuffs_4FF350(a1, 0) || nox_xxx_testUnitBuffs_4FF350(*(int*)&dword_5d4594_2491592, 21)) &&
		(*(uint32_t*)(a1 + 8) & 0x80000206 || *(unsigned short*)(a1 + 4) == *getMemU32Ptr(0x5D4594, 2491604))) {
		if (nox_xxx_mapCheck_537110(a1, *(int*)&dword_5d4594_2491592)) {
			if (!(*(uint8_t*)(a1 + 8) & 4) ||
				(*(uint32_t*)(a1 + 36) != nox_player_netCode_85319C ||
				 !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) &&
					(v3 = nox_common_playerInfoGetByID_417040(*(uint32_t*)(a1 + 36))) != 0 && !(v3[3680] & 1)) {
				if ((*(uint32_t*)(a1 + 8) & 0x200) != 512 || (v4 = *(uint32_t*)(a1 + 16), BYTE1(v4) & 0x40)) {
					v5 = *(float*)(a1 + 60) - *(float*)(a1 + 104);
					v14 = v5;
					v17 = v5;
					if (*((uint32_t*)v2 + 43) == 2) {
						v13 = v2[44] * v2[44];
						v7 = nox_float2int(v13);
						a3.field_0 = v2[14] - v2[44];
						a1a.field_0 = v2[44] + v2[14];
						if (a2[1] > (double)v17) {
							v8 = *a2 - v2[14];
							v9 = a2[1] - v17;
							if ((double)v7 <= v9 * v9 + v8 * v8) {
								return;
							}
							goto LABEL_38;
						}
						v10 = *a2;
						if (a2[1] < (double)v14) {
							v11 = a2[1] - v14;
							if ((double)v7 <= v11 * v11 + (v10 - v2[14]) * (v10 - v2[14])) {
								return;
							}
							goto LABEL_38;
						}
						if (v10 > a3.field_0 && *a2 < (double)a1a.field_0) {
						LABEL_38:
							v12 = v2[26] + v2[15];
							if (v12 > *getMemFloatPtr(0x5D4594, 2491600)) {
								*getMemFloatPtr(0x5D4594, 2491600) = v12;
								*getMemU32Ptr(0x5D4594, 2491596) = v2;
							}
							return;
						}
					} else if (*((uint32_t*)v2 + 43) == 3) {
						v6 = v2[14];
						a1a.field_4 = v5;
						a3.field_0 = *a2;
						a1a.field_0 = v6;
						a3.field_4 = a2[1];
						if (nox_xxx_map_57B850(&a1a, v2 + 43, &a3)) {
							goto LABEL_38;
						}
						a1a.field_4 = v5;
						if (nox_xxx_map_57B850(&a1a, v2 + 43, &a3) || v2[50] + v2[14] < *a2 && *a2 < (double)v2[14] &&
																		  v14 + v2[51] < a2[1] &&
																		  v17 + v2[51] > a2[1]) {
							goto LABEL_38;
						}
						if (*a2 >= (double)v2[14] && v2[52] + v2[14] > *a2 && v14 + v2[53] < a2[1] &&
							v17 + v2[53] > a2[1]) {
							goto LABEL_38;
						}
					}
				}
			}
		}
	}
}

//----- (0054B2D0) --------------------------------------------------------
int sub_54B2D0(int* a1, int a2, uint32_t* a3) {
	int v3;   // ebp
	int* v4;  // edi
	int v5;   // edx
	int v6;   // ebx
	int v7;   // eax
	int v8;   // kr04_4
	int* v9;  // ebx
	int* v11; // edi
	int v12;  // ebx
	int v13;  // eax
	int v14;  // kr0C_4
	int* v15; // ebx
	int* v16; // edi
	int v17;  // ebx
	int v18;  // ebx
	int v19;  // eax
	int v20;  // kr14_4
	int* v21; // ebx
	int v22;  // ecx
	int* v23; // edi
	int v24;  // ebx
	int v25;  // eax
	int v26;  // ecx
	int v27;  // ebx
	int v28;  // eax
	int v29;  // kr1C_4
	int* v30; // ebx
	int v31;  // ecx
	int v32;  // [esp-4h] [ebp-1Ch]
	int v33;  // [esp-4h] [ebp-1Ch]
	int2 a4;  // [esp+10h] [ebp-8h]
	int v35;  // [esp+20h] [ebp+8h]
	int v36;  // [esp+20h] [ebp+8h]
	int v37;  // [esp+20h] [ebp+8h]
	int v38;  // [esp+20h] [ebp+8h]
	int a2a;  // [esp+24h] [ebp+Ch]
	int a2b;  // [esp+24h] [ebp+Ch]
	int a2c;  // [esp+24h] [ebp+Ch]
	int a2d;  // [esp+24h] [ebp+Ch]
	int a2e;  // [esp+24h] [ebp+Ch]
	int a2f;  // [esp+24h] [ebp+Ch]
	int a2g;  // [esp+24h] [ebp+Ch]
	int a2h;  // [esp+24h] [ebp+Ch]

	v3 = a1[4 * a2 + 22];
	switch (a2) {
	case 0:
		v4 = a3;
		a2a = 0;
		v5 = v4[4];
		v6 = v4[3] - v3;
		a4.field_0 = v4[1] + v4[3] / 2;
		a4.field_4 = v5 + v4[2] - 1;
		if (v6 >= 0) {
			do {
				if (sub_54B810(a1[37], (int)v4, a1 + 20, &a4, a1[22])) {
					return 1;
				}
				v7 = v4[1];
				if (++a4.field_0 > v7 + v6) {
					a4.field_0 = v7;
				}
				++a2a;
			} while (a2a <= v6);
		}
		a2b = 0;
		v8 = v4[4];
		v35 = v8 - v3;
		a4.field_4 = v4[2] + v8 / 2;
		if (v8 - v3 < 0) {
			return 0;
		}
		v9 = a1 + 22;
		do {
			a4.field_0 = v4[1];
			if (sub_54BD90(a1[37], (int)v4, a1 + 20, &a4.field_0, *v9)) {
				return 1;
			}
			v32 = *v9;
			a4.field_0 = a4.field_0 + v4[3] - 1;
			if (sub_54BD90(a1[37], (int)v4, a1 + 20, &a4.field_0, v32)) {
				return 1;
			}
			if (++a4.field_4 > v4[2] + v35) {
				a4.field_4 = v4[2];
			}
			++a2b;
		} while (a2b <= v35);
		return 0;
	case 1:
		v11 = a3;
		a2c = 0;
		v12 = v11[3] - v3;
		a4.field_0 = v11[1] + v11[3] / 2;
		a4.field_4 = v11[2];
		if (v12 < 0) {
			goto LABEL_20;
		}
		while (!sub_54B810((int)v11, a1[37], &a4.field_0, (int2*)a1 + 12, a1[26])) {
			v13 = v11[1];
			if (++a4.field_0 > v13 + v12) {
				a4.field_0 = v13;
			}
			if (++a2c > v12) {
			LABEL_20:
				a2d = 0;
				v14 = v11[4];
				v36 = v14 - v3;
				a4.field_4 = v11[2] + v14 / 2;
				if (v14 - v3 < 0) {
					return 0;
				}
				v15 = a1 + 26;
				while (1) {
					a4.field_0 = v11[1];
					if (sub_54BF20(a1[37], (int)v11, a1 + 24, &a4.field_0, *v15)) {
						break;
					}
					v33 = *v15;
					a4.field_0 = a4.field_0 + v11[3] - 1;
					if (sub_54BF20(a1[37], (int)v11, a1 + 24, &a4.field_0, v33)) {
						break;
					}
					if (++a4.field_4 > v11[2] + v36) {
						a4.field_4 = v11[2];
					}
					if (++a2d > v36) {
						return 0;
					}
				}
				return 1;
			}
		}
		return 1;
	case 2:
		v16 = a3;
		a2e = 0;
		v17 = v16[3];
		a4.field_0 = v16[1];
		v18 = v17 - v3;
		a4.field_4 = v16[2] + v16[4] / 2;
		if (v18 < 0) {
			goto LABEL_33;
		}
		while (!sub_54BB20(a1[37], (int)v16, a1 + 28, &a4, a1[30])) {
			v19 = v16[2];
			if (++a4.field_4 > v19 + v18) {
				a4.field_4 = v19;
			}
			if (++a2e > v18) {
			LABEL_33:
				a2f = 0;
				v20 = v16[3];
				v37 = v20 - v3;
				a4.field_0 = v16[1] + v20 / 2;
				if (v20 - v3 < 0) {
					return 0;
				}
				v21 = a1 + 30;
				while (1) {
					a4.field_4 = v16[2];
					if (sub_54BD90((int)v16, a1[37], &a4.field_0, a1 + 28, *v21)) {
						break;
					}
					v22 = *v21;
					a4.field_4 = a4.field_4 + v16[4] - 1;
					if (sub_54BF20((int)v16, a1[37], &a4.field_0, a1 + 28, v22)) {
						break;
					}
					if (++a4.field_0 > v16[1] + v37) {
						a4.field_0 = v16[1];
					}
					if (++a2f > v37) {
						return 0;
					}
				}
				return 1;
			}
		}
		return 1;
	case 3:
		v23 = a3;
		a2g = 0;
		v24 = v23[3];
		v25 = v23[4];
		v26 = v23[2];
		a4.field_0 = v23[1] + v24 - 1;
		v27 = v24 - v3;
		a4.field_4 = v26 + v25 / 2;
		if (v27 < 0) {
			goto LABEL_46;
		}
		break;
	default:
		return 0;
	}
	while (!sub_54BB20((int)v23, a1[37], &a4.field_0, a1 + 32, a1[34])) {
		v28 = v23[2];
		if (++a4.field_4 > v28 + v27) {
			a4.field_4 = v28;
		}
		if (++a2g > v27) {
		LABEL_46:
			a2h = 0;
			v29 = v23[3];
			v38 = v29 - v3;
			a4.field_0 = v23[1] + v29 / 2;
			if (v29 - v3 < 0) {
				return 0;
			}
			v30 = a1 + 34;
			while (1) {
				a4.field_4 = v23[2];
				if (sub_54BD90((int)v23, a1[37], &a4.field_0, a1 + 32, *v30)) {
					break;
				}
				v31 = *v30;
				a4.field_4 = a4.field_4 + v23[4] - 1;
				if (sub_54BF20((int)v23, a1[37], &a4.field_0, a1 + 32, v31)) {
					break;
				}
				if (++a4.field_0 > v23[1] + v38) {
					a4.field_0 = v23[1];
				}
				if (++a2h > v38) {
					return 0;
				}
			}
			return 1;
		}
	}
	return 1;
}

//----- (0054B810) --------------------------------------------------------
int sub_54B810(int a1, int a2, int* a3, int2* a4, int a5) {
	int* v5;    // ebx
	int2* v6;   // esi
	int v7;     // eax
	float* v8;  // eax
	int v10;    // ecx
	int v11;    // edx
	int v12;    // eax
	int v13;    // ecx
	int v14;    // edi
	float* v15; // eax
	double v16; // st7
	float* v17; // eax
	float* v18; // eax
	float2 a2a; // [esp+10h] [ebp-8h]
	int v20;    // [esp+24h] [ebp+Ch]
	int2* v21;  // [esp+28h] [ebp+10h]
	int2* v22;  // [esp+28h] [ebp+10h]
	int v23;    // [esp+2Ch] [ebp+14h]
	int v24;    // [esp+2Ch] [ebp+14h]

	v5 = a3;
	v6 = a4;
	v7 = a4->field_0 - *a3;
	v20 = a4->field_0 - *a3;
	if (v20 < 0) {
		v7 = -v7;
	}
	*getMemU32Ptr(0x5D4594, 2491608) = 0;
	if (v7) {
		if (v7 < 3) {
			return 0;
		}
		v10 = v5[1];
		v11 = a4->field_4;
		v12 = v5[1];
		*getMemU32Ptr(0x5D4594, 2491608) = 0;
		v13 = v10 - (v12 - v11) / 2;
		v14 = v13 - 1;
		v21 = (int2*)(v13 - 1);
		v15 = sub_523E30(2, a5, v5[1] - (v13 - 1));
		*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = v15;
		a2a.field_0 = (double)*v5 * 32.526913;
		v16 = (double)(int)v21 * 32.526913;
		a2a.field_4 = v16;
		nox_xxx_mapGenSetRoomPos_521880(v15, &a2a);
		++*getMemU32Ptr(0x5D4594, 2491608);
		if (v20 <= 0) {
			v17 = sub_523E30(5, a5, *v5 - v6->field_0);
			a2a.field_4 = v16;
			*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = v17;
			a2a.field_0 = (double)v6->field_0 * 32.526913;
			sub_521A70(*getMemIntPtr(0x5D4594, 2491612), *(int*)&dword_5d4594_2491616, 3);
		} else {
			*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) =
				sub_523E30(4, a5, v6->field_0 - *v5);
			v22 = (int2*)(a5 + *v5);
			a2a.field_4 = v16;
			a2a.field_0 = (double)(int)v22 * 32.526913;
			sub_521A70(*getMemIntPtr(0x5D4594, 2491612), *(int*)&dword_5d4594_2491616, 2);
		}
		nox_xxx_mapGenSetRoomPos_521880(*(uint32_t**)getMemAt(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)),
										&a2a);
		++*getMemU32Ptr(0x5D4594, 2491608);
		v18 = sub_523E30(2, a5, v14 - v6->field_4 - 1);
		*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = v18;
		v24 = v6->field_4 + 1;
		a2a.field_0 = (double)v6->field_0 * 32.526913;
		a2a.field_4 = (double)v24 * 32.526913;
		nox_xxx_mapGenSetRoomPos_521880(v18, &a2a);
		sub_521A70(*(int*)&dword_5d4594_2491616, *getMemIntPtr(0x5D4594, 2491620), 0);
	} else {
		v8 = sub_523E30(2, a5, v5[1] - a4->field_4 - 1);
		*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = v8;
		v23 = a4->field_4 + 1;
		a2a.field_0 = (double)a4->field_0 * 32.526913;
		a2a.field_4 = (double)v23 * 32.526913;
		nox_xxx_mapGenSetRoomPos_521880(v8, &a2a);
	}
	++*getMemU32Ptr(0x5D4594, 2491608);
	return sub_54BA60(a1, a2, 0, 1);
}

//----- (0054BA60) --------------------------------------------------------
int sub_54BA60(int a1, int a2, int a3, int a4) {
	int v4;            // eax
	int v5;            // esi
	int* v6;           // edi
	int v7;            // esi
	unsigned char* v8; // edi
	int result;        // eax
	int v10;           // edi
	void** v11;        // esi

	v4 = *getMemU32Ptr(0x5D4594, 2491608);
	v5 = 0;
	if (*getMemIntPtr(0x5D4594, 2491608) <= 0) {
	LABEL_5:
		v7 = 0;
		if (v4 > 0) {
			v8 = getMemAt(0x5D4594, 2491612);
			do {
				nox_xxx_mapGenAddNewRoom_521730(*(uint32_t**)v8);
				++v7;
				v8 += 4;
			} while (v7 < *getMemIntPtr(0x5D4594, 2491608));
		}
		sub_521A70(a1, *getMemIntPtr(0x5D4594, 2491612), a3);
		sub_521A70(a2, *getMemU32Ptr(0x5D4594, 2491608 + 4 * *getMemU32Ptr(0x5D4594, 2491608)), a4);
		result = 1;
	} else {
		v6 = getMemIntPtr(0x5D4594, 2491612);
		while (!sub_521200(*v6)) {
			v4 = *getMemU32Ptr(0x5D4594, 2491608);
			++v5;
			++v6;
			if (v5 >= *getMemIntPtr(0x5D4594, 2491608)) {
				goto LABEL_5;
			}
		}
		v10 = 0;
		if (*getMemU32Ptr(0x5D4594, 2491608) > 0) {
			v11 = (void**)getMemAt(0x5D4594, 2491612);
			do {
				sub_521A10(*v11);
				++v10;
				++v11;
			} while (v10 < *getMemIntPtr(0x5D4594, 2491608));
		}
		result = 0;
	}
	return result;
}

//----- (0054BB20) --------------------------------------------------------
int sub_54BB20(int a1, int a2, int* a3, uint32_t* a4, int a5) {
	uint32_t* v5; // ebp
	int v6;       // eax
	float* v7;    // eax
	int v9;       // ecx
	int v10;      // eax
	int v11;      // edi
	int v12;      // ebx
	float* v13;   // eax
	float* v14;   // eax
	float2 a2a;   // [esp+10h] [ebp-8h]
	int v16;      // [esp+28h] [ebp+10h]
	int v17;      // [esp+2Ch] [ebp+14h]

	v5 = a4;
	v6 = a4[1] - a3[1];
	v16 = v6;
	if (v6 < 0) {
		v6 = -v6;
	}
	*getMemU32Ptr(0x5D4594, 2491608) = 0;
	if (v6) {
		if (v6 < 3) {
			return 0;
		}
		v9 = *a3;
		v10 = *v5 - *a3;
		*getMemU32Ptr(0x5D4594, 2491608) = 0;
		v11 = v9 + v10 / 2;
		v12 = a5;
		v13 = sub_523E30(4, a5, v11 - *a3 + a5 - 1);
		*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = v13;
		a2a.field_0 = (double)(*a3 + 1) * 32.526913;
		a2a.field_4 = (double)a3[1] * 32.526913;
		nox_xxx_mapGenSetRoomPos_521880(v13, &a2a);
		++*getMemU32Ptr(0x5D4594, 2491608);
		if (v16 <= 0) {
			*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = sub_523E30(2, a5, a3[1] - v5[1]);
			a2a.field_0 = (double)v11 * 32.526913;
			a2a.field_4 = (double)(int)v5[1] * 32.526913;
			sub_521A70(*getMemIntPtr(0x5D4594, 2491612), *(int*)&dword_5d4594_2491616, 0);
		} else {
			*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = sub_523E30(3, a5, v5[1] - a3[1]);
			v17 = a3[1] + a5;
			a2a.field_0 = (double)v11 * 32.526913;
			a2a.field_4 = (double)v17 * 32.526913;
			sub_521A70(*getMemIntPtr(0x5D4594, 2491612), *(int*)&dword_5d4594_2491616, 1);
		}
		nox_xxx_mapGenSetRoomPos_521880(*(uint32_t**)getMemAt(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)),
										&a2a);
		++*getMemU32Ptr(0x5D4594, 2491608);
		v14 = sub_523E30(4, v12, *v5 - v11 - v12);
		*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = v14;
		a2a.field_0 = (double)(v12 + v11) * 32.526913;
		a2a.field_4 = (double)(int)v5[1] * 32.526913;
		nox_xxx_mapGenSetRoomPos_521880(v14, &a2a);
		sub_521A70(*(int*)&dword_5d4594_2491616, *getMemIntPtr(0x5D4594, 2491620), 2);
	} else {
		v7 = sub_523E30(4, a5, *v5 - *a3 - 1);
		*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = v7;
		a2a.field_0 = (double)(*a3 + 1) * 32.526913;
		a2a.field_4 = (double)a3[1] * 32.526913;
		nox_xxx_mapGenSetRoomPos_521880(v7, &a2a);
	}
	++*getMemU32Ptr(0x5D4594, 2491608);
	return sub_54BA60(a1, a2, 2, 3);
}

//----- (0054BD90) --------------------------------------------------------
int sub_54BD90(int a1, int a2, int* a3, int* a4, int a5) {
	int v6;     // ecx
	int v7;     // ebx
	int v8;     // ebx
	float* v9;  // eax
	int v10;    // esi
	float2 a2a; // [esp+Ch] [ebp-8h]

	if (a4[1] > a3[1] - a5) {
		return 0;
	}
	v6 = *a3;
	v7 = *a4;
	*getMemU32Ptr(0x5D4594, 2491608) = 0;
	v8 = v7 - v6;
	v9 = sub_523E30(2, a5, a3[1] - a4[1]);
	*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = v9;
	a2a.field_0 = (double)*a3 * 32.526913;
	a2a.field_4 = (double)a4[1] * 32.526913;
	nox_xxx_mapGenSetRoomPos_521880(v9, &a2a);
	++*getMemU32Ptr(0x5D4594, 2491608);
	if (v8 <= 0) {
		*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = sub_523E30(5, a5, *a3 - *a4 - 1);
		a2a.field_0 = (double)(*a4 + 1) * 32.526913;
		a2a.field_4 = (double)a4[1] * 32.526913;
		sub_521A70(*getMemIntPtr(0x5D4594, 2491612), *(int*)&dword_5d4594_2491616, 3);
		v10 = 2;
	} else {
		*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = sub_523E30(4, a5, *a4 - *a3 - a5);
		a2a.field_0 = (double)(a5 + *a3) * 32.526913;
		a2a.field_4 = (double)a4[1] * 32.526913;
		sub_521A70(*getMemIntPtr(0x5D4594, 2491612), *(int*)&dword_5d4594_2491616, 2);
		v10 = 3;
	}
	nox_xxx_mapGenSetRoomPos_521880(*(uint32_t**)getMemAt(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)),
									&a2a);
	++*getMemU32Ptr(0x5D4594, 2491608);
	return sub_54BA60(a1, a2, 0, v10);
}

//----- (0054BF20) --------------------------------------------------------
int sub_54BF20(int a1, int a2, int* a3, int* a4, int a5) {
	int* v5;    // esi
	int v7;     // ebx
	int v8;     // ebp
	float* v9;  // eax
	int v10;    // esi
	float2 a2a; // [esp+8h] [ebp-8h]
	int v12;    // [esp+1Ch] [ebp+Ch]

	v5 = a3;
	if (a4[1] <= a3[1]) {
		return 0;
	}
	v7 = *a3;
	v8 = *a4;
	*getMemU32Ptr(0x5D4594, 2491608) = 0;
	v9 = sub_523E30(3, a5, a4[1] - a3[1] + a5 - 1);
	*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = v9;
	v12 = a3[1] + 1;
	a2a.field_0 = (double)*v5 * 32.526913;
	a2a.field_4 = (double)v12 * 32.526913;
	nox_xxx_mapGenSetRoomPos_521880(v9, &a2a);
	++*getMemU32Ptr(0x5D4594, 2491608);
	if (v8 - v7 <= 0) {
		*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = sub_523E30(5, a5, *v5 - *a4 - 1);
		a2a.field_0 = (double)(*a4 + 1) * 32.526913;
		a2a.field_4 = (double)a4[1] * 32.526913;
		sub_521A70(*getMemIntPtr(0x5D4594, 2491612), *(int*)&dword_5d4594_2491616, 3);
		v10 = 2;
	} else {
		*getMemU32Ptr(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)) = sub_523E30(4, a5, *a4 - *v5 - a5);
		a2a.field_0 = (double)(a5 + *v5) * 32.526913;
		a2a.field_4 = (double)a4[1] * 32.526913;
		sub_521A70(*getMemIntPtr(0x5D4594, 2491612), *(int*)&dword_5d4594_2491616, 2);
		v10 = 3;
	}
	nox_xxx_mapGenSetRoomPos_521880(*(uint32_t**)getMemAt(0x5D4594, 2491612 + 4 * *getMemU32Ptr(0x5D4594, 2491608)),
									&a2a);
	++*getMemU32Ptr(0x5D4594, 2491608);
	return sub_54BA60(a1, a2, 1, v10);
}

//----- (0054C0C0) --------------------------------------------------------
short nox_xxx_monsterAutoSpells_54C0C0(int a1) {
	int v1;   // esi
	int v2;   // eax
	short v3; // ax
	short v4; // ax

	v1 = *(uint32_t*)(a1 + 748);
	if (!*getMemU32Ptr(0x5D4594, 2491640)) {
		*getMemU32Ptr(0x5D4594, 2491624) = nox_xxx_getNameId_4E3AA0("UrchinShaman");
		*getMemU32Ptr(0x5D4594, 2491628) = nox_xxx_getNameId_4E3AA0("Wizard");
		*getMemU32Ptr(0x5D4594, 2491632) = nox_xxx_getNameId_4E3AA0("WizardWhite");
		*getMemU32Ptr(0x5D4594, 2491636) = nox_xxx_getNameId_4E3AA0("Beholder");
		*getMemU32Ptr(0x5D4594, 2491640) = nox_xxx_getNameId_4E3AA0("Lich");
		*getMemU32Ptr(0x5D4594, 2491644) = nox_xxx_getNameId_4E3AA0("LichLord");
		*getMemU32Ptr(0x5D4594, 2491648) = nox_xxx_getNameId_4E3AA0("Demon");
		*getMemU32Ptr(0x5D4594, 2491652) = nox_xxx_getNameId_4E3AA0("WizardGreen");
		*getMemU32Ptr(0x5D4594, 2491656) = nox_xxx_getNameId_4E3AA0("WillOWisp");
	}
	v2 = *(unsigned short*)(a1 + 4);
	if ((unsigned short)v2 != *getMemU32Ptr(0x5D4594, 2491624)) {
		if (v2 == *getMemU32Ptr(0x5D4594, 2491628) || v2 == *getMemU32Ptr(0x5D4594, 2491632)) {
			*(uint32_t*)(v1 + 2040) = 3;
			*(uint32_t*)(v1 + 1540) = 0x8000000;
			*(uint32_t*)(v1 + 1640) = 0x8000000;
			LOWORD(v2) = 0;
			*(uint32_t*)(v1 + 1644) = 0x10000000;
			*(uint32_t*)(v1 + 1776) = 0x20000000;
			*(uint32_t*)(v1 + 1596) = 0x40000000;
			*(uint32_t*)(v1 + 1688) = 0x40000000;
			*(uint32_t*)(v1 + 1660) = 0x40000000;
			*(uint32_t*)(v1 + 1584) = 0x40000000;
			*(uint32_t*)(v1 + 1504) = 2147483648;
		} else if (v2 == *getMemU32Ptr(0x5D4594, 2491636)) {
			*(uint32_t*)(v1 + 2040) = 3;
			*(uint32_t*)(v1 + 1584) = 0x40000000;
			v2 = nox_common_gameFlags_check_40A5C0(4096);
			if (!v2) {
				*(uint32_t*)(v1 + 1504) = 2147483648;
				*(uint8_t*)(v1 + 2036) = 1;
				return v2;
			}
		} else {
			if (v2 == *getMemU32Ptr(0x5D4594, 2491640)) {
				*(uint32_t*)(v1 + 2040) = 3;
				*(uint32_t*)(v1 + 1540) = 0x8000000;
				*(uint32_t*)(v1 + 1640) = 0x8000000;
				*(uint32_t*)(v1 + 1772) = 0x10000000;
				*(uint32_t*)(v1 + 1776) = 0x20000000;
				*(uint32_t*)(v1 + 1620) = 0x20000000;
				LOWORD(v2) = 0;
				*(uint32_t*)(v1 + 1644) = 2147483648;
				*(uint32_t*)(v1 + 1596) = 0x40000000;
				*(uint32_t*)(v1 + 1660) = 0x40000000;
				*(uint32_t*)(v1 + 1584) = 0x40000000;
				*(uint8_t*)(v1 + 2036) = 1;
				return v2;
			}
			if (v2 == *getMemU32Ptr(0x5D4594, 2491644)) {
				*(uint32_t*)(v1 + 2040) = 3;
				*(uint32_t*)(v1 + 1540) = 0x8000000;
				*(uint32_t*)(v1 + 1640) = 0x8000000;
				*(uint32_t*)(v1 + 1772) = 0x10000000;
				*(uint16_t*)(v1 + 1472) = 3 * (uint16_t)nox_gameFPS;
				LOWORD(v2) = (uint16_t)nox_gameFPS;
				*(uint32_t*)(v1 + 1612) = 0x40000000;
				*(uint32_t*)(v1 + 1644) = 2147483648;
				*(uint8_t*)(v1 + 2036) = 1;
				*(uint16_t*)(v1 + 1474) = 5 * v2;
				return v2;
			}
			if (v2 == *getMemU32Ptr(0x5D4594, 2491648)) {
				LOWORD(v2) = 0;
				*(uint32_t*)(v1 + 2040) = 3;
				*(uint32_t*)(v1 + 1540) = 0x8000000;
				*(uint32_t*)(v1 + 1784) = 0x20000000;
				*(uint32_t*)(v1 + 1596) = 0x40000000;
				*(uint32_t*)(v1 + 1528) = 0x40000000;
				*(uint32_t*)(v1 + 1644) = 2147483648;
				*(uint8_t*)(v1 + 2036) = 1;
				return v2;
			}
			if (v2 == *getMemU32Ptr(0x5D4594, 2491652)) {
				LOWORD(v2) = 0;
				*(uint32_t*)(v1 + 2040) = 3;
				*(uint32_t*)(v1 + 1640) = 0x8000000;
				*(uint32_t*)(v1 + 1536) = 0x20000000;
				*(uint32_t*)(v1 + 1720) = 0x40000000;
				*(uint32_t*)(v1 + 1728) = 0x40000000;
				*(uint32_t*)(v1 + 1688) = 0x40000000;
				*(uint32_t*)(v1 + 1504) = 2147483648;
				*(uint8_t*)(v1 + 2036) = 1;
				return v2;
			}
			if (v2 == *getMemU32Ptr(0x5D4594, 2491656)) {
				*(uint32_t*)(v1 + 2040) = 3;
				*(uint32_t*)(v1 + 1660) = 0x40000000;
				*(uint8_t*)(v1 + 2036) = 1;
				return v2;
			}
		}
		*(uint8_t*)(v1 + 2036) = 1;
		return v2;
	}
	*(uint32_t*)(v1 + 2040) = 2;
	*(uint32_t*)(v1 + 1640) = 0x8000000;
	*(uint16_t*)(v1 + 1448) = 0;
	*(uint16_t*)(v1 + 1450) = nox_gameFPS >> 1;
	*(uint32_t*)(v1 + 1536) = 0x20000000;
	*(uint16_t*)(v1 + 1464) = 3 * (uint16_t)nox_gameFPS;
	v3 = (uint16_t)nox_gameFPS;
	*(uint16_t*)(v1 + 1472) = 0;
	*(uint16_t*)(v1 + 1466) = 5 * v3;
	*(uint32_t*)(v1 + 1720) = 0x40000000;
	*(uint32_t*)(v1 + 1696) = 0x40000000;
	v4 = (uint16_t)nox_gameFPS;
	*(uint32_t*)(v1 + 1752) = 2147483648;
	*(uint16_t*)(v1 + 1474) = 3 * v4;
	*(uint16_t*)(v1 + 1480) = (uint16_t)nox_gameFPS;
	LOWORD(v2) = (uint16_t)nox_gameFPS;
	*(uint8_t*)(v1 + 2036) = 1;
	*(uint16_t*)(v1 + 1482) = 3 * v2;
	return v2;
}

//----- (0054C480) --------------------------------------------------------
char nox_xxx_monsterCreateFn_54C480(int a1) {
	int v1;         // esi
	const char* v2; // eax
	uint32_t* v3;   // eax
	double v4;      // st7
	int v5;         // eax
	double v6;      // st7
	short v7;       // cx
	short v8;       // cx
	short v9;       // cx
	int v10;        // eax
	int v11;        // ecx

	v1 = *(uint32_t*)(a1 + 748);
	v2 = (const char*)nox_xxx_getUnitName_4E39D0(a1);
	*(uint32_t*)(v1 + 488) = nox_xxx_getDefaultSoundSet_424350(v2);
	v3 = nox_xxx_monsterDefByTT_517560(*(unsigned short*)(a1 + 4));
	*(uint32_t*)(v1 + 484) = v3;
	if (v3) {
		v4 = (double)(int)v3[16];
		v5 = *(uint32_t*)(a1 + 556);
		*(float*)(a1 + 28) = v4;
		*(uint16_t*)(v5 + 4) = *(uint16_t*)(*(uint32_t*)(v1 + 484) + 68);
		**(uint16_t**)(a1 + 556) = *(uint16_t*)(*(uint32_t*)(v1 + 484) + 68);
		*(uint16_t*)(*(uint32_t*)(a1 + 556) + 2) = *(uint16_t*)(*(uint32_t*)(v1 + 484) + 68);
		v6 = (double)*(int*)(*(uint32_t*)(v1 + 484) + 76) * 0.03125;
		*(float*)(a1 + 548) = v6;
		*(float*)(a1 + 544) = v6;
		*(uint32_t*)(v1 + 1336) = *(uint32_t*)(*(uint32_t*)(v1 + 484) + 80);
		*(uint8_t*)(v1 + 1340) = 1;
		*(uint32_t*)(v1 + 1344) = *(uint32_t*)(*(uint32_t*)(v1 + 484) + 84);
		*(uint8_t*)(v1 + 1348) = 1;
		*(uint32_t*)(v1 + 1440) = *(uint32_t*)(*(uint32_t*)(v1 + 484) + 92);
		*(uint8_t*)(v1 + 1444) = 1;
		*(uint32_t*)(v1 + 1356) = *(uint32_t*)(*(uint32_t*)(v1 + 484) + 88);
	}
	*(uint8_t*)(v1 + 544) = 0;
	*(uint32_t*)(v1 + 552) = 0;
	*(uint32_t*)(v1 + 1360) = 0;
	*(uint32_t*)(v1 + 1308) = 1056964608;
	*(uint32_t*)(v1 + 1304) = 1056964608;
	*(uint32_t*)(v1 + 1320) = 1056964608;
	*(uint32_t*)(v1 + 1328) = 1056964608;
	*(uint32_t*)(v1 + 1312) = 1125515264;
	*(uint32_t*)(v1 + 1316) = 1106247680;
	*(uint8_t*)(v1 + 1332) = -1;
	*(uint8_t*)(v1 + 1324) = 30;
	*(uint32_t*)(v1 + 1352) = 1065353216;
	*(uint32_t*)(v1 + 1228) = -1;
	*(uint32_t*)(v1 + 1236) = -1;
	*(uint32_t*)(v1 + 1244) = -1;
	*(uint32_t*)(v1 + 1252) = -1;
	*(uint32_t*)(v1 + 1260) = -1;
	*(uint32_t*)(v1 + 1268) = -1;
	*(uint32_t*)(v1 + 1276) = -1;
	*(uint32_t*)(v1 + 1284) = -1;
	*(uint32_t*)(v1 + 1292) = -1;
	*(uint32_t*)(v1 + 1300) = -1;
	*(uint32_t*)(v1 + 2040) = 1;
	*(uint16_t*)(v1 + 1448) = 0;
	*(uint16_t*)(v1 + 1450) = nox_gameFPS >> 1;
	*(uint16_t*)(v1 + 1456) = 3 * (uint16_t)nox_gameFPS;
	*(uint16_t*)(v1 + 1458) = 10 * (uint16_t)nox_gameFPS;
	*(uint16_t*)(v1 + 1464) = 3 * (uint16_t)nox_gameFPS;
	v7 = (uint16_t)nox_gameFPS;
	*(uint16_t*)(v1 + 1472) = 0;
	*(uint16_t*)(v1 + 1466) = 6 * v7;
	v8 = (uint16_t)nox_gameFPS;
	*(uint16_t*)(v1 + 1480) = 0;
	*(uint16_t*)(v1 + 1474) = 3 * v8;
	v9 = (uint16_t)nox_gameFPS;
	*(uint32_t*)(v1 + 2096) = -1;
	*(uint32_t*)(v1 + 2100) = -1;
	*(uint32_t*)v1 = -559023410;
	*(uint16_t*)(v1 + 1482) = 6 * v9;
	nox_xxx_monsterAutoSpells_54C0C0(a1);
	LOBYTE(v10) = *(uint8_t*)(a1 + 12);
	if (v10 & 8) {
		v10 = *(uint32_t*)(a1 + 692);
		*(uint32_t*)(v10 + 1716) = 1065353216;
		*(uint32_t*)(v10 + 1720) = 1051372091;
	}
	if (*(uint8_t*)(a1 + 12) & 0x20) {
		v10 = v1 + 2077;
		v11 = 6;
		do {
			*(uint8_t*)(v10 - 1) = -46;
			*(uint8_t*)v10 = -82;
			*(uint8_t*)(v10 + 1) = 121;
			v10 += 3;
			--v11;
		} while (v11);
	}
	*(uint32_t*)(v1 + 4) = 0;
	*(uint32_t*)(v1 + 288) = 0;
	*(uint32_t*)(v1 + 292) = 0;
	return v10;
}

//----- (0054C710) --------------------------------------------------------
int nox_xxx_createWeapon_54C710(int a1) {
	int v1;       // esi
	int v2;       // ebx
	uint32_t* v3; // edi
	uint16_t* v4; // eax
	int v5;       // eax
	int v6;       // eax
	int v7;       // eax
	int v8;       // eax
	int v9;       // eax
	uint8_t* v10; // edi
	double v11;   // st7
	char v12;     // al
	int result;   // eax
	int v14;      // edi
	float v15;    // [esp+0h] [ebp-14h]
	float v16;    // [esp+0h] [ebp-14h]
	float v17;    // [esp+0h] [ebp-14h]
	float v18;    // [esp+0h] [ebp-14h]
	float v19;    // [esp+0h] [ebp-14h]
	float v20;    // [esp+18h] [ebp+4h]
	float v21;    // [esp+18h] [ebp+4h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 692);
	v3 = nox_xxx_getProjectileClassById_413250(*(unsigned short*)(a1 + 4));
	if (!*getMemU32Ptr(0x5D4594, 2491660)) {
		*getMemU32Ptr(0x5D4594, 2491660) = nox_xxx_getNameId_4E3AA0("OblivionHeart");
		*getMemU32Ptr(0x5D4594, 2491664) = nox_xxx_getNameId_4E3AA0("OblivionWierdling");
		*getMemU32Ptr(0x5D4594, 2491668) = nox_xxx_getNameId_4E3AA0("OblivionOrb");
	}
	if (v3) {
		v4 = *(uint16_t**)(a1 + 556);
		if (v4) {
			*v4 = *((uint16_t*)v3 + 26);
			*(uint16_t*)(*(uint32_t*)(a1 + 556) + 4) = *((uint16_t*)v3 + 26);
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				v20 = nox_xxx_gamedataGetFloat_419D40("QuestDurabilityMultiplier");
				v15 = (double)**(unsigned short**)(v1 + 556) * v20;
				**(uint16_t**)(v1 + 556) = nox_float2int(v15);
				v16 = (double)*(unsigned short*)(*(uint32_t*)(v1 + 556) + 4) * v20;
				*(uint16_t*)(*(uint32_t*)(v1 + 556) + 4) = nox_float2int(v16);
			}
		}
	}
	v5 = *(unsigned short*)(v1 + 4);
	if ((unsigned short)v5 == *getMemU32Ptr(0x5D4594, 2491660)) {
		v6 = nox_xxx_modifGetIdByName_413290("Lightning4");
		*(uint32_t*)(v2 + 8) = nox_xxx_modifGetDescById_413330(v6);
	} else if (v5 == *getMemU32Ptr(0x5D4594, 2491664)) {
		v7 = nox_xxx_modifGetIdByName_413290("Vampirism2");
		*(uint32_t*)(v2 + 8) = nox_xxx_modifGetDescById_413330(v7);
		v8 = nox_xxx_modifGetIdByName_413290("Lightning3");
		*(uint32_t*)(v2 + 12) = nox_xxx_modifGetDescById_413330(v8);
	}
	if (*(uint32_t*)(v1 + 8) & 0x1000000) {
		v9 = *(uint32_t*)(v1 + 12);
		if (v9 & 0x82) {
			v10 = *(uint8_t**)(v1 + 736);
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				v11 = nox_xxx_gamedataGetFloat_419D40("DefaultAmmoAmountQuest");
			} else {
				v11 = nox_xxx_gamedataGetFloat_419D40("DefaultAmmoAmount");
			}
			v17 = v11;
			v12 = nox_float2int(v17);
			v10[1] = v12;
			v10[2] = 0;
			*v10 = v12;
		} else if (v9 & 0xC) {
			**(uint8_t**)(v1 + 736) = 0;
		}
	}
	result = nox_common_gameFlags_check_40A5C0(4096);
	if (result) {
		result = *(uint32_t*)(v1 + 8);
		if (result & 0x1000) {
			if (*(uint32_t*)(v1 + 12) & 0x47F0000) {
				v14 = *(uint32_t*)(v1 + 736);
				v21 = nox_xxx_gamedataGetFloat_419D40("QuestStaffChargeMultiplier");
				if (*(uint32_t*)(v1 + 12) & 0x40000) {
					v21 = v21 + v21;
				}
				v18 = (double)*(unsigned char*)(v14 + 109) * v21;
				*(uint8_t*)(v14 + 109) = nox_float2int(v18);
				v19 = (double)*(unsigned char*)(v14 + 108) * v21;
				result = nox_float2int(v19);
				*(uint8_t*)(v14 + 108) = result;
			}
		}
	}
	return result;
}

//----- (0054C950) --------------------------------------------------------
uint32_t* sub_54C950(int a1) {
	int v1;           // esi
	uint32_t* result; // eax
	uint16_t* v3;     // ecx
	float v4;         // [esp+0h] [ebp-Ch]
	float v5;         // [esp+0h] [ebp-Ch]
	float v6;         // [esp+10h] [ebp+4h]

	v1 = a1;
	result = nox_xxx_equipClothFindDefByTT_413270(*(unsigned short*)(a1 + 4));
	if (result) {
		v3 = *(uint16_t**)(a1 + 556);
		if (v3) {
			*v3 = *((uint16_t*)result + 26);
			*(uint16_t*)(*(uint32_t*)(a1 + 556) + 4) = *((uint16_t*)result + 26);
			result = (uint32_t*)nox_common_gameFlags_check_40A5C0(4096);
			if (result) {
				v6 = nox_xxx_gamedataGetFloat_419D40("QuestDurabilityMultiplier");
				v4 = (double)**(unsigned short**)(v1 + 556) * v6;
				**(uint16_t**)(v1 + 556) = nox_float2int(v4);
				v5 = (double)*(unsigned short*)(*(uint32_t*)(v1 + 556) + 4) * v6;
				result = (uint32_t*)nox_float2int(v5);
				*(uint16_t*)(*(uint32_t*)(v1 + 556) + 4) = (uint16_t)result;
			}
		}
	}
	return result;
}

//----- (0054CA10) --------------------------------------------------------
int nox_xxx_createFnObelisk_54CA10(int a1) {
	**(uint32_t**)(a1 + 748) = 50;
	nullsub_35(a1, 1117782016);
	nox_xxx_unitNeedSync_4E44F0(a1);
	return 0;
}
// 4E4770: using guessed type void  nullsub_35(uint32_t, uint32_t);

//----- (0054CA50) --------------------------------------------------------
int* nox_xxx_createFnAnim_54CA50(int a1) { return nox_xxx_unitSetXStatus_4E4800(a1, (int*)2); }

//----- (0054CA60) --------------------------------------------------------
uint8_t* nox_xxx_createTrigger_54CA60(int a1) {
	uint8_t* result; // eax

	result = *(uint8_t**)(a1 + 748);
	result[54] = 90;
	result[55] = 90;
	result[56] = 90;
	result[57] = 10;
	result[58] = 10;
	result[59] = 10;
	return result;
}

//----- (0054CA90) --------------------------------------------------------
uint32_t* nox_xxx_createMonsterGen_54CA90(int a1) {
	uint32_t* result; // eax

	result = *(uint32_t**)(a1 + 748);
	result[23] = 2;
	result[13] = -1;
	result[15] = -1;
	result[19] = -1;
	result[17] = -1;
	return result;
}

//----- (0054CAC0) --------------------------------------------------------
uint32_t* nox_xxx_createRewardMarker_54CAC0(int a1) {
	uint32_t* result; // eax

	result = *(uint32_t**)(a1 + 692);
	*result = 255;
	result[53] = 0;
	return result;
}

//----- (0054CAE0) --------------------------------------------------------
int nox_xxx_dieImpEgg_54CAE0(int a1) {
	int result; // eax

	nox_xxx_aud_501960(764, a1, 0, 0);
	result = *(uint32_t*)(a1 + 16);
	LOBYTE(result) = result | 0x40;
	*(uint32_t*)(a1 + 16) = result;
	return result;
}

//----- (0054CB10) --------------------------------------------------------
void nox_xxx_diePolyp_54CB10(int a1) {
	int v1;       // eax
	uint32_t* v2; // eax
	uint32_t* v3; // edi
	float v4;     // [esp+0h] [ebp-14h]

	v1 = *getMemU32Ptr(0x5D4594, 2491672);
	if (!*getMemU32Ptr(0x5D4594, 2491672)) {
		v1 = nox_xxx_getNameId_4E3AA0("ToxicCloud");
		*getMemU32Ptr(0x5D4594, 2491672) = v1;
	}
	v2 = nox_xxx_newObjectWithTypeInd_4E3450(v1);
	if (v2) {
		v3 = (uint32_t*)v2[187];
		nox_xxx_createAt_4DAA50((int)v2, 0, *(float*)(a1 + 56), *(float*)(a1 + 60));
		v4 = nox_xxx_gamedataGetFloat_419D40("ToxicCloudLifetime") * (double)(int)nox_gameFPS;
		*v3 = nox_float2int(v4);
	}
	nox_xxx_aud_501960(284, a1, 0, 0);
	nox_xxx_delayedDeleteObject_4E5CC0(a1);
}

//----- (0054CBB0) --------------------------------------------------------
void nox_xxx_diePotion_54CBB0(int a1) {
	nox_xxx_aud_501960(753, a1, 0, 0);
	nox_xxx_delayedDeleteObject_4E5CC0(a1);
}

//----- (0054CBD0) --------------------------------------------------------
void sub_54CBD0(int a1) {
	int v1;          // edi
	unsigned int v2; // eax

	v1 = *(uint32_t*)(a1 + 748);
	v2 = nox_xxx_playerGetGold_4FA6B0(a1);
	nox_xxx_playerSubGold_4FA5D0(a1, v2 >> 1);
	sub_54D080(a1);
	sub_54CC40(a1);
	sub_54CD30(a1);
	if (!*(uint8_t*)(*(uint32_t*)(v1 + 276) + 2251)) {
		sub_54CD30(a1);
	}
	sub_54CE00(a1);
	sub_54CE00(a1);
	sub_54CEE0(a1);
	sub_54CEE0(a1);
	sub_54CFB0(a1);
}

//----- (0054CC40) --------------------------------------------------------
void sub_54CC40(int a1) {
	int v1;       // ebp
	int v2;       // edi
	int v3;       // eax
	int v4;       // eax
	uint32_t* v5; // eax
	int v6;       // edx
	int v7;       // ecx
	int v8;       // ebx
	int v9;       // esi
	int v10;      // eax

	v1 = *(uint32_t*)(a1 + 748);
	v2 = nox_xxx_inventoryGetFirst_4E7980(a1);
	if (v2) {
		while (1) {
			v3 = *(uint32_t*)(v2 + 16);
			if (v3 & 0x100) {
				if (*(uint32_t*)(v2 + 8) & 0x1001000 && !(*(uint8_t*)(v2 + 12) & 2)) {
					break;
				}
			}
			v2 = nox_xxx_inventoryGetNext_4E7990(v2);
			if (!v2) {
				return;
			}
		}
		v4 = *(uint32_t*)(v2 + 12);
		if (!(v4 & 0x10000)) {
			if (!(v4 & 0x104)) {
				goto LABEL_24;
			}
			v5 = *(uint32_t**)(v2 + 692);
			v6 = 1;
			v7 = 4;
			do {
				if (*v5) {
					v6 = 0;
				}
				++v5;
				--v7;
			} while (v7);
			if (v6 != 1) {
			LABEL_24:
				v8 = 0;
				v9 = nox_xxx_inventoryGetFirst_4E7980(a1);
				if (v9) {
					do {
						if (*(uint32_t*)(v9 + 8) & 0x1001000) {
							v10 = *(uint32_t*)(v9 + 16);
							if (!(v10 & 0x100) &&
								nox_xxx_playerClassCanUseItem_57B3D0(v9, *(uint8_t*)(*(uint32_t*)(v1 + 276) + 2251))) {
								v8 = 1;
							}
						}
						v9 = nox_xxx_inventoryGetNext_4E7990(v9);
					} while (v9);
					if (v8) {
						nox_xxx_delayedDeleteObject_4E5CC0(v2);
					}
				}
			}
		}
	}
}

//----- (0054CD30) --------------------------------------------------------
void sub_54CD30(int a1) {
	int v1; // edi
	int v2; // esi
	int v3; // eax
	int v4; // ebx
	int v5; // edi
	int i;  // esi
	int v7; // eax

	v1 = 0;
	v2 = nox_xxx_inventoryGetFirst_4E7980(a1);
	if (v2) {
		do {
			v3 = *(uint32_t*)(v2 + 16);
			if (v3 & 0x100 && *(uint32_t*)(v2 + 8) & 0x2000000 &&
				!(sub_415D10((char*)*(unsigned short*)(v2 + 4)) & 0x405)) {
				++v1;
			}
			v2 = nox_xxx_inventoryGetNext_4E7990(v2);
		} while (v2);
		if (v1) {
			v4 = nox_common_randomInt_415FA0(0, v1 - 1);
			v5 = 0;
			for (i = nox_xxx_inventoryGetFirst_4E7980(a1); i; i = nox_xxx_inventoryGetNext_4E7990(i)) {
				v7 = *(uint32_t*)(i + 16);
				if (v7 & 0x100 && *(uint32_t*)(i + 8) & 0x2000000 &&
					!(sub_415D10((char*)*(unsigned short*)(i + 4)) & 0x405)) {
					if (v5 == v4) {
						nox_xxx_delayedDeleteObject_4E5CC0(i);
						return;
					}
					++v5;
				}
			}
		}
	}
}

//----- (0054CE00) --------------------------------------------------------
void sub_54CE00(int a1) {
	int v1;       // edi
	int v2;       // eax
	int v3;       // ebp
	int v4;       // esi
	uint32_t* v5; // edi
	uint32_t* v6; // ebx
	int v7;       // ebx
	int v8;       // ebp
	int i;        // esi
	int v10;      // eax
	int v12;      // [esp-14h] [ebp-24h]

	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	a1 = v1;
	LOBYTE(v2) = *(uint8_t*)(v1 + 2251);
	if ((uint8_t)v2 == 2 || (uint8_t)v2 == 1) {
		v3 = 0;
		v4 = 0;
		v5 = (uint32_t*)(v1 + 3696);
		v6 = v5;
		do {
			if (*v6 && sub_4F24E0(v4)) {
				++v3;
			}
			++v4;
			++v6;
		} while (v4 < 137);
		v2 = nox_common_randomInt_415FA0(0, v3 - 1);
		v7 = 0;
		v8 = v2;
		for (i = 0; i < 137; ++i) {
			if (*v5) {
				v2 = sub_4F24E0(i);
				if (v2) {
					if (v7 == v8) {
						v10 = a1;
						*(uint32_t*)(a1 + 4 * i + 3696) = 0;
						v12 = *(unsigned char*)(v10 + 2064);
						LOWORD(a1) = 4592;
						HIWORD(a1) = i;
						LOBYTE(v2) = nox_xxx_netSendPacket0_4E5420(v12, &a1, 4, 0, 1);
						return;
					}
					++v7;
				}
			}
			++v5;
		}
	}
}

//----- (0054CEE0) --------------------------------------------------------
void sub_54CEE0(int a1) {
	int v2;       // edi
	int v3;       // ebp
	int v4;       // esi
	uint32_t* v5; // edi
	uint32_t* v6; // ebx
	int v7;       // ebx
	int v8;       // ebp
	int i;        // esi
	int v10;      // eax
	int v11;      // [esp-14h] [ebp-24h]

	v2 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	a1 = v2;
	if (*(uint8_t*)(v2 + 2251) == 2) {
		v3 = 0;
		v4 = 0;
		v5 = (uint32_t*)(v2 + 4244);
		v6 = v5;
		do {
			if (*v6 == 1 && sub_4F2530(v4)) {
				++v3;
			}
			++v4;
			++v6;
		} while (v4 < 41);
		v8 = nox_common_randomInt_415FA0(0, v3 - 1);
		v7 = 0;
		for (i = 0; i < 41; ++i) {
			if (*v5 == 1) {
				if (sub_4F2530(i)) {
					if (v7 == v8) {
						v10 = a1;
						*(uint32_t*)(a1 + 4 * i + 4244) = 0;
						v11 = *(unsigned char*)(v10 + 2064);
						LOWORD(a1) = 5104;
						HIWORD(a1) = i;
						nox_xxx_netSendPacket0_4E5420(v11, &a1, 4, 0, 1);
						return;
					}
					++v7;
				}
			}
			++v5;
		}
	}
}

//----- (0054CFB0) --------------------------------------------------------
char sub_54CFB0(int a1) {
	int v1;       // ebx
	int v2;       // eax
	int v3;       // ebp
	int v4;       // esi
	uint32_t* v5; // edi
	int v6;       // ebp
	int v7;       // esi
	uint32_t* v8; // edi
	int v10;      // [esp-14h] [ebp-24h]

	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	LOBYTE(v2) = *(uint8_t*)(v1 + 2251);
	if (!(uint8_t)v2) {
		v3 = 0;
		v4 = 0;
		v5 = (uint32_t*)(v1 + 3696);
		do {
			if (*v5 && sub_4F2570(v4)) {
				++v3;
			}
			++v4;
			++v5;
		} while (v4 < 6);
		v2 = nox_common_randomInt_415FA0(1, v3);
		v6 = 1;
		a1 = v2;
		v7 = 1;
		v8 = (uint32_t*)(v1 + 3700);
		do {
			if (*v8) {
				v2 = sub_4F2570(v7);
				if (v2) {
					if (v6 == a1) {
						*(uint32_t*)(v1 + 4 * v7 + 3696) = 0;
						v10 = *(unsigned char*)(v1 + 2064);
						LOWORD(a1) = 4848;
						HIWORD(a1) = v7;
						LOBYTE(v2) = nox_xxx_netSendPacket0_4E5420(v10, &a1, 4, 0, 1);
						return v2;
					}
					++v6;
				}
			}
			++v7;
			++v8;
		} while (v7 < 6);
	}
	return v2;
}

//----- (0054D080) --------------------------------------------------------
void sub_54D080(int a1) {
	char v1; // bl
	int v2;  // ebp
	int i;   // eax
	int v4;  // ecx
	int v5;  // eax
	int v6;  // ecx
	int v7;  // edi
	int v8;  // esi
	int v9;  // eax
	int v10; // edi
	int v11; // edi
	int v12; // edi
	int v13; // [esp+10h] [ebp-Ch]
	int v14; // [esp+10h] [ebp-Ch]
	int v15; // [esp+14h] [ebp-8h]
	int v16; // [esp+14h] [ebp-8h]
	int v17; // [esp+18h] [ebp-4h]
	int v18; // [esp+18h] [ebp-4h]
	int v19; // [esp+20h] [ebp+4h]

	v1 = 0;
	v17 = 0;
	v13 = 0;
	v15 = 0;
	if (!dword_5d4594_2491676) {
		dword_5d4594_2491676 = nox_xxx_getNameId_4E3AA0("Diamond");
		*getMemU32Ptr(0x5D4594, 2491680) = nox_xxx_getNameId_4E3AA0("Emerald");
		*getMemU32Ptr(0x5D4594, 2491684) = nox_xxx_getNameId_4E3AA0("Ruby");
	}
	v2 = a1;
	for (i = nox_xxx_inventoryGetFirst_4E7980(a1); i; i = nox_xxx_inventoryGetNext_4E7990(i)) {
		v4 = *(unsigned short*)(i + 4);
		if ((unsigned short)v4 == dword_5d4594_2491676) {
			++v17;
		} else if (v4 == *getMemU32Ptr(0x5D4594, 2491680)) {
			++v13;
		} else if (v4 == *getMemU32Ptr(0x5D4594, 2491684)) {
			++v15;
		}
	}
	v5 = v17;
	if (v17 & 1) {
		v5 = v17 - 1;
		v1 = 1;
	}
	if (v13 & 1) {
		v1 |= 2u;
		--v13;
	}
	v6 = v15;
	if (v15 & 1) {
		v6 = v15 - 1;
		v1 |= 4u;
	}
	v14 = v13 / 2;
	v7 = v5 / 2;
	v18 = v5 / 2;
	v16 = v6 / 2;
	v8 = nox_xxx_inventoryGetFirst_4E7980(a1);
	if (v8) {
		while (1) {
			v19 = nox_xxx_inventoryGetNext_4E7990(v8);
			v9 = *(unsigned short*)(v8 + 4);
			if ((unsigned short)v9 == dword_5d4594_2491676) {
				if (v1 & 1) {
					v10 = nox_xxx_shopGetItemCost_50E3D0(1, 0, *(float*)&v8);
					nox_xxx_delayedDeleteObject_4E5CC0(v8);
					nox_xxx_playerAddGold_4FA590(v2, v10 / 2);
					v1 &= 0xFEu;
				} else if (v7 > 0) {
					nox_xxx_delayedDeleteObject_4E5CC0(v8);
					v18 = v7 - 1;
				}
			} else if (v9 == *getMemU32Ptr(0x5D4594, 2491680)) {
				if (v1 & 2) {
					v11 = nox_xxx_shopGetItemCost_50E3D0(1, 0, *(float*)&v8);
					nox_xxx_delayedDeleteObject_4E5CC0(v8);
					nox_xxx_playerAddGold_4FA590(v2, v11 / 2);
					v1 &= 0xFDu;
				} else if (v14 > 0) {
					nox_xxx_delayedDeleteObject_4E5CC0(v8);
					--v14;
				}
			} else if (v9 == *getMemU32Ptr(0x5D4594, 2491684)) {
				if (v1 & 4) {
					v12 = nox_xxx_shopGetItemCost_50E3D0(1, 0, *(float*)&v8);
					nox_xxx_delayedDeleteObject_4E5CC0(v8);
					nox_xxx_playerAddGold_4FA590(v2, v12 / 2);
					v1 &= 0xFBu;
				} else if (v16 > 0) {
					nox_xxx_delayedDeleteObject_4E5CC0(v8);
					--v16;
				}
			}
			v8 = v19;
			if (!v19) {
				break;
			}
			v7 = v18;
		}
	}
}

//----- (0054D2B0) --------------------------------------------------------
int nox_xxx_diePlayer_54D2B0(int a1) {
	int v1;                // edi
	int v2;                // ebp
	int v3;                // esi
	uint32_t* v4;          // eax
	char* v5;              // eax
	int v6;                // ebx
	char v7;               // cl
	int v8;                // eax
	int v9;                // edx
	short v10;             // ax
	short v11;             // dx
	int v12;               // eax
	int v13;               // edx
	short v14;             // ax
	int v15;               // edx
	int v16;               // eax
	int v17;               // edx
	int result;            // eax
	int v19;               // eax
	int v20;               // eax
	float v21;             // [esp+0h] [ebp-28h]
	char* v22;             // [esp+14h] [ebp-14h]
	unsigned char v23[14]; // [esp+18h] [ebp-10h]
	int v24;               // [esp+2Ch] [ebp+4h]

	v1 = a1;
	v2 = 0;
	v3 = *(uint32_t*)(a1 + 748);
	if (!*getMemU32Ptr(0x5D4594, 2491688)) {
		*getMemU32Ptr(0x5D4594, 2491688) = nox_xxx_getNameId_4E3AA0("AnkhTradable");
	}
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_4DB170(0, 0, 0);
	}
	v24 = *(uint32_t*)(a1 + 520);
	if (v24) {
		v24 = nox_xxx_findParentChainPlayer_4EC580(v24);
	}
	v4 = *(uint32_t**)(v3 + 276);
	if (v4[900] && nox_frame_xxx_2598000 - v4[902] < (unsigned int)(10 * nox_gameFPS)) {
		v5 = nox_common_playerInfoFromNum_417090(v4[901]);
		v6 = (int)v5;
		v22 = v5;
		if (v5) {
			if (*((uint32_t*)v5 + 523) && *((uint32_t*)v5 + 514)) {
				v2 = nox_server_getObjectFromNetCode_4ECCB0(*((uint32_t*)v5 + 515));
			} else {
				v22 = 0;
				v2 = 0;
				v6 = 0;
			}
			if (v24 == v2) {
				v2 = 0;
			}
			if (v1 == v2) {
				v2 = 0;
			}
		}
	} else {
		v22 = 0;
		v6 = 0;
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		v7 = 0;
		v23[10] = 0;
		*(uint32_t*)v23 = 0;
		*(uint32_t*)&v23[4] = 0;
		*(uint16_t*)&v23[8] = 0;
		if (v24 && *(uint8_t*)(v24 + 8) & 4) {
			*(uint16_t*)&v23[2] = *(uint16_t*)(v24 + 36);
		}
		v8 = *(uint32_t*)(v1 + 520);
		if (v8) {
			v9 = *(uint32_t*)(v8 + 8);
			if (v9 & 2) {
				v23[10] = 1;
				v10 = *(uint16_t*)(v8 + 4);
			LABEL_30:
				*(uint16_t*)&v23[8] = v10;
				goto LABEL_31;
			}
			if (v9 & 4) {
				v7 = *(uint8_t*)(v3 + 304);
				v11 = *(uint16_t*)(v3 + 300);
				v23[10] = *(uint8_t*)(v3 + 304);
				*(uint16_t*)&v23[8] = v11;
			} else {
				v12 = *(uint32_t*)(v8 + 508);
				if (v12) {
					v13 = *(uint32_t*)(v12 + 8);
					if (v13 & 4) {
						v7 = *(uint8_t*)(v3 + 304);
						v14 = *(uint16_t*)(v3 + 300);
						v23[10] = *(uint8_t*)(v3 + 304);
						*(uint16_t*)&v23[8] = v14;
					} else if (v13 & 2) {
						v23[10] = 1;
						*(uint16_t*)&v23[8] = *(uint16_t*)(v12 + 4);
					LABEL_31:
						if (v2 && *(uint8_t*)(v2 + 8) & 4) {
							*(uint16_t*)&v23[4] = *(uint16_t*)(v2 + 36);
						}
						*(uint16_t*)&v23[6] = *(uint16_t*)(v1 + 36);
						nox_xxx_netInformTextMsg2_4DA180(14, v23);
						if (v23[10] == 2 && *(uint16_t*)&v23[8] == 2) {
							sub_4FC0B0(v24, 1);
						}
						v6 = (int)v22;
						*(uint32_t*)(v3 + 304) = 0;
						goto LABEL_38;
					}
				}
			}
		}
		if (v7) {
			goto LABEL_31;
		}
		v10 = *(uint16_t*)(v3 + 300);
		v23[10] = *(uint8_t*)(v3 + 304);
		goto LABEL_30;
	}
LABEL_38:
	if (*(uint32_t*)(v1 + 524) == 16) {
		nox_xxx_aud_501960(299, v1, 0, 0);
	} else if (*(uint8_t*)(*(uint32_t*)(v3 + 276) + 2252)) {
		nox_xxx_aud_501960(331, v1, 0, 0);
	} else {
		nox_xxx_aud_501960(321, v1, 0, 0);
	}
	v15 = *(uint32_t*)(v1 + 16);
	BYTE1(v15) |= 0x80u;
	*(uint32_t*)(v1 + 16) = v15;
	nox_xxx_playerSetState_4FA020((uint32_t*)v1, 3);
	*(uint8_t*)(v3 + 188) = 0;
	*(uint32_t*)(v3 + 216) = 0;
	*(uint32_t*)(v3 + 192) = 0;
	*(uint32_t*)(v3 + 196) = 0;
	*(uint32_t*)(v3 + 200) = 0;
	*(uint32_t*)(v3 + 204) = 0;
	*(uint32_t*)(v3 + 208) = 0;
	*(uint8_t*)(v3 + 212) = 0;
	v16 = nox_xxx_gamePlayIsAnyPlayers_40A8A0();
	if (v16) {
		if (nox_common_gameFlags_check_40A5C0(256)) {
			nox_xxx_playerUpdateScore_54D980(v1, v24, v2, v6);
		} else if (nox_common_gameFlags_check_40A5C0(16)) {
			nox_xxx_playerHandleKotrDeath_54DC40(v1, v24);
		} else if (nox_common_gameFlags_check_40A5C0(1024)) {
			nox_xxx_playerHandleElimDeath_54D7A0(v1, v24);
		}
	}
	if (nox_common_gameFlags_check_40A5C0(1024) && nox_xxx_servGamedataGet_40A020(1024) &&
		*(uint32_t*)(*(uint32_t*)(v3 + 276) + 2140) >= (int)(unsigned short)nox_xxx_servGamedataGet_40A020(1024)) {
		nox_xxx_playerRemoveSpawnedStuff_4E5AD0(v1);
	}
	*(uint32_t*)(v1 + 16) |= 0x10u;
	nox_xxx_action_4DA9F0((uint32_t*)v1);
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		nox_xxx_dropAllItems_4EDA40((uint32_t*)v1);
	}
	nox_xxx_netNotifyPlayerDied_54DF00(v1);
	v17 = *(uint32_t*)(v3 + 276);
	*(uint16_t*)(v3 + 4) = 0;
	nox_xxx_protectMana_56F9E0(*(uint32_t*)(v17 + 4596), 0);
	nox_xxx_setUnitBuffFlags_4E48F0(v1, 0);
	nox_xxx_playerCancelAbils_4FC180(v1);
	*(uint32_t*)(*(uint32_t*)(v3 + 276) + 3600) = 0;
	nox_xxx_playerCancelSpells_4FEAE0(v1);
	nox_xxx_unitClearBuffs_4FF580(v1);
	if (*(uint32_t*)(v3 + 280)) {
		nox_xxx_shopCancelSession_510DC0(*(uint32_t**)(v3 + 280));
	}
	*(uint32_t*)(v3 + 280) = 0;
	result = nox_common_gameFlags_check_40A5C0(4096);
	if (result) {
		v19 = *(uint32_t*)(v3 + 320);
		if (v19) {
			*(uint32_t*)(v3 + 320) = v19 - 1;
			result = sub_4D6130(v1);
		} else {
			v20 = *(uint32_t*)(v3 + 276);
			*(uint32_t*)(v3 + 548) = nox_frame_xxx_2598000;
			v23[0] = -16;
			v23[1] = 2;
			*(uint16_t*)&v23[8] = *(uint16_t*)(v20 + 4688);
			*(uint16_t*)&v23[2] = *(uint16_t*)(v20 + 4668);
			*(uint16_t*)&v23[6] = *(uint16_t*)(v20 + 4664);
			*(uint16_t*)&v23[4] = *(uint16_t*)(v20 + 4672);
			*(uint32_t*)&v23[10] = 0;
			nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(v20 + 2064), v23, 14, 0, 1);
			sub_4D6000(v1);
			sub_54CBD0(v1);
			v21 = nox_xxx_gamedataGetFloat_419D40("QuestGameStartingExtraLives");
			*(uint32_t*)(v3 + 320) = nox_float2int(v21);
			result = *(uint32_t*)(v3 + 276);
			*(uint8_t*)(*(unsigned char*)(result + 2064) + v3 + 452) = *(uint8_t*)(v3 + 320);
		}
	}
	return result;
}
// 54D56D: variable 'v16' is possibly undefined

//----- (0054D7A0) --------------------------------------------------------
void nox_xxx_playerHandleElimDeath_54D7A0(int a1, int a2) {
	int v2;   // edi
	int v3;   // ebx
	char* v4; // ebp
	int v5;   // eax
	int v6;   // [esp-4h] [ebp-18h]
	int v7;   // [esp-4h] [ebp-18h]
	char* v8; // [esp+10h] [ebp-4h]
	int v9;   // [esp+18h] [ebp+4h]

	v2 = a1;
	v3 = 0;
	v4 = 0;
	v8 = 0;
	v6 = a1 + 48;
	v9 = *(uint32_t*)(a1 + 748);
	if (nox_xxx_servObjectHasTeam_419130(v6)) {
		v8 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(v2 + 52));
	}
	if (a2) {
		v3 = *(uint32_t*)(a2 + 748);
		if (nox_xxx_servObjectHasTeam_419130(a2 + 48)) {
			v4 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a2 + 52));
		}
	}
	if (a2 == v2) {
		nox_xxx_playerSubLessons_4D8EC0(v2, 1);
		nox_xxx_playerIncrementElimDeath_4D8D40(v2);
		nox_xxx_netReportLesson_4D8EF0(v2);
		if (v8) {
			nox_xxx_netChangeTeamID_419090((int)v8, *((uint32_t*)v8 + 13) + 1);
		}
		if (dword_5d4594_2650652) {
			if (v3) {
				sub_425CA0(*(uint32_t*)(v3 + 276), *(uint32_t*)(v3 + 276));
			}
		}
		return;
	}
	if (a2) {
		if (*(uint8_t*)(a2 + 8) & 4) {
			if (v4) {
				if (v4 == v8) {
					nox_xxx_playerSubLessons_4D8EC0(a2, 1);
					nox_xxx_netReportLesson_4D8EF0(a2);
					if (dword_5d4594_2650652 && v3) {
						sub_425CA0(*(uint32_t*)(v3 + 276), *(uint32_t*)(v3 + 276));
					}
					goto LABEL_32;
				}
			} else if (!v8) {
				nox_xxx_changeScore_4D8E90(a2, 1);
				nox_xxx_netReportLesson_4D8EF0(a2);
				if (dword_5d4594_2650652 && v3 && v9) {
					sub_425CA0(*(uint32_t*)(v3 + 276), *(uint32_t*)(v9 + 276));
				}
				goto LABEL_32;
			}
			nox_xxx_changeScore_4D8E90(a2, 1);
			nox_xxx_netReportLesson_4D8EF0(a2);
			if (dword_5d4594_2650652) {
				if (v3 && v9) {
					v5 = *(uint32_t*)(v3 + 276);
					v7 = *(uint32_t*)(v9 + 276);
				LABEL_31:
					sub_425CA0(v5, v7);
					goto LABEL_32;
				}
			}
		}
	} else if (dword_5d4594_2650652 && v9) {
		v5 = *(uint32_t*)(v9 + 276);
		v7 = *(uint32_t*)(v9 + 276);
		goto LABEL_31;
	}
LABEL_32:
	nox_xxx_playerIncrementElimDeath_4D8D40(v2);
	nox_xxx_netReportLesson_4D8EF0(v2);
	if (v8) {
		nox_xxx_netChangeTeamID_419090((int)v8, *((uint32_t*)v8 + 13) + 1);
	}
}

//----- (0054D980) --------------------------------------------------------
void nox_xxx_playerUpdateScore_54D980(int a1, int a2, int a3, int a4) {
	int v4;       // ebx
	char* v5;     // edi
	int v6;       // ebp
	int v7;       // eax
	char* result; // eax
	char* v9;     // esi
	int v10;      // edi
	int v11;      // ecx
	int v12;      // [esp-4h] [ebp-20h]
	int v13;      // [esp-4h] [ebp-20h]
	char* v14;    // [esp+10h] [ebp-Ch]
	char* v15;    // [esp+14h] [ebp-8h]
	char* v16;    // [esp+18h] [ebp-4h]
	int v17;      // [esp+20h] [ebp+4h]

	v4 = a1;
	v5 = 0;
	v12 = a1 + 48;
	v14 = 0;
	v15 = 0;
	v17 = *(uint32_t*)(a1 + 748);
	v6 = 0;
	v16 = 0;
	if (nox_xxx_servObjectHasTeam_419130(v12)) {
		v14 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(v4 + 52));
	}
	if (a2) {
		v6 = *(uint32_t*)(a2 + 748);
		if (nox_xxx_servObjectHasTeam_419130(a2 + 48)) {
			v5 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a2 + 52));
		}
	}
	if (a4) {
		if (a3) {
			v16 = *(char**)(a3 + 748);
			if (nox_xxx_servObjectHasTeam_419130(a3 + 48)) {
				v15 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a3 + 52));
			}
		}
	}
	if (a2 == v4) {
		goto LABEL_31;
	}
	if (a2) {
		if (!(*(uint8_t*)(a2 + 8) & 4)) {
		LABEL_30:
			nox_xxx_playerIncrementElimDeath_4D8D40(v4);
			result = (char*)nox_xxx_netReportLesson_4D8EF0(v4);
			v9 = v14;
			goto LABEL_36;
		}
		if (v5) {
			if (v5 == v14) {
				nox_xxx_playerSubLessons_4D8EC0(a2, 1);
				nox_xxx_netReportLesson_4D8EF0(a2);
				nox_xxx_netChangeTeamID_419090((int)v5, *((uint32_t*)v5 + 13) - 1);
				if (!dword_5d4594_2650652 || !v6) {
					goto LABEL_30;
				}
				v7 = *(uint32_t*)(v6 + 276);
				v13 = *(uint32_t*)(v6 + 276);
			LABEL_29:
				sub_425CA0(v7, v13);
				goto LABEL_30;
			}
		} else if (!v14) {
			nox_xxx_changeScore_4D8E90(a2, 1);
			nox_xxx_netReportLesson_4D8EF0(a2);
			if (!dword_5d4594_2650652 || !v6 || !v17) {
				goto LABEL_30;
			}
			v7 = *(uint32_t*)(v6 + 276);
			v13 = *(uint32_t*)(v17 + 276);
			goto LABEL_29;
		}
		nox_xxx_changeScore_4D8E90(a2, 1);
		nox_xxx_netReportLesson_4D8EF0(a2);
		nox_xxx_netChangeTeamID_419090((int)v5, *((uint32_t*)v5 + 13) + 1);
		if (dword_5d4594_2650652 && v6 && v17) {
			sub_425CA0(*(uint32_t*)(v6 + 276), *(uint32_t*)(v17 + 276));
		}
		goto LABEL_30;
	}
	if (a3) {
		goto LABEL_30;
	}
LABEL_31:
	nox_xxx_playerSubLessons_4D8EC0(v4, 1);
	nox_xxx_netReportLesson_4D8EF0(v4);
	v9 = v14;
	if (v14) {
		nox_xxx_netChangeTeamID_419090((int)v14, *((uint32_t*)v14 + 13) - 1);
	}
	result = *(char**)&dword_5d4594_2650652;
	if (dword_5d4594_2650652 && v6) {
		result = sub_425CA0(*(uint32_t*)(v6 + 276), *(uint32_t*)(v6 + 276));
	}
LABEL_36:
	if (!a3) {
		return;
	}
	if (v5) {
		result = v15;
		if (v5 == v15) {
			return;
		}
		v10 = (int)v15;
	} else {
		v10 = (int)v15;
		if (!v15) {
			goto LABEL_44;
		}
	}
	if (v9) {
		if (v9 == (char*)v10) {
			return;
		}
	LABEL_49:
		nox_xxx_changeScore_4D8E90(a3, 1);
		nox_xxx_netReportLesson_4D8EF0(a3);
		if (v10) {
			nox_xxx_netChangeTeamID_419090(v10, *(uint32_t*)(v10 + 52) + 1);
		}
		result = *(char**)&dword_5d4594_2650652;
		if (dword_5d4594_2650652) {
			result = v16;
			if (v16) {
				v11 = v17;
				if (v17) {
					sub_425CA0(*((uint32_t*)result + 69), *(uint32_t*)(v11 + 276));
					return;
				}
			}
		}
		return;
	}
	if (v10) {
		goto LABEL_49;
	}
LABEL_44:
	nox_xxx_changeScore_4D8E90(a3, 1);
	nox_xxx_netReportLesson_4D8EF0(a3);
	if (dword_5d4594_2650652) {
		result = v16;
		if (v16) {
			v11 = v17;
			if (v17) {
				sub_425CA0(*((uint32_t*)result + 69), *(uint32_t*)(v11 + 276));
				return;
			}
		}
	}
}

//----- (0054DC40) --------------------------------------------------------
void nox_xxx_playerHandleKotrDeath_54DC40(int a1, int a2) {
	char* v2;     // edi
	char* v3;     // ebx
	char* result; // eax
	int v5;       // ebp
	double v6;    // st7
	int v7;       // ebx
	int v8;       // ebx
	int v9;       // eax
	double v10;   // st7
	int v11;      // eax
	float v12;    // [esp+0h] [ebp-18h]
	float v13;    // [esp+0h] [ebp-18h]
	int v14;      // [esp+0h] [ebp-18h]
	float v15;    // [esp+0h] [ebp-18h]
	int v16;      // [esp+14h] [ebp-4h]

	v2 = 0;
	v3 = 0;
	v16 = *(uint32_t*)(a1 + 748);
	result = (char*)nox_xxx_servObjectHasTeam_419130(a1 + 48);
	if (result) {
		result = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a1 + 52));
		v3 = result;
	}
	if (a2) {
		v5 = *(uint32_t*)(a2 + 748);
		result = (char*)nox_xxx_servObjectHasTeam_419130(a2 + 48);
		if (result) {
			result = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a2 + 52));
			v2 = result;
		}
		if (*(uint8_t*)(a2 + 8) & 4) {
			if (a2 == a1 || v3 == v2 && v3) {
				if (!nox_xxx_unitIsCrown_4E7BE0(a2)) {
					goto LABEL_44;
				}
				nox_xxx_playerSubLessons_4D8EC0(a2, 1);
				nox_xxx_netReportLesson_4D8EF0(a2);
				if (v2) {
					nox_xxx_netChangeTeamID_419090((int)v2, *((uint32_t*)v2 + 13) - 1);
				}
				if (!dword_5d4594_2650652 || !v5) {
					goto LABEL_44;
				}
				v9 = *(uint32_t*)(v5 + 276);
				v14 = *(uint32_t*)(v5 + 276);
			} else {
				if (!v2 || v2 == v3) {
					if (nox_xxx_unitIsCrown_4E7BE0(a2) || nox_xxx_unitIsCrown_4E7BE0(a1)) {
						if (nox_xxx_unitIsCrown_4E7BE0(a2)) {
							v10 = nox_xxx_gamedataGetFloat_419D40("KotRKingKillsPawnPoints");
						} else {
							v10 = nox_xxx_gamedataGetFloat_419D40("KotRPawnKillsKingPoints");
						}
						v15 = v10;
						v11 = nox_float2int(v15);
						nox_xxx_changeScore_4D8E90(a2, v11);
						nox_xxx_netReportLesson_4D8EF0(a2);
						if (dword_5d4594_2650652 && v5 && v16) {
							sub_425CA0(*(uint32_t*)(v5 + 276), *(uint32_t*)(v16 + 276));
						}
						if (!nox_xxx_CheckGameplayFlags_417DA0(4) && nox_xxx_unitIsCrown_4E7BE0(a1)) {
							sub_4ED050(a1, a2);
						}
					}
					goto LABEL_44;
				}
				if (nox_xxx_unitIsCrown_4E7BE0(a2)) {
					if (nox_xxx_unitIsCrown_4E7BE0(a1)) {
						v6 = nox_xxx_gamedataGetFloat_419D40("KotRKingKillsKingPoints");
					} else {
						v6 = nox_xxx_gamedataGetFloat_419D40("KotRKingKillsPawnPoints");
					}
					v12 = v6;
					v7 = nox_float2int(v12);
					nox_xxx_changeScore_4D8E90(a2, v7);
					nox_xxx_netChangeTeamID_419090((int)v2, v7 + *((uint32_t*)v2 + 13));
					nox_xxx_netReportLesson_4D8EF0(a2);
					if (dword_5d4594_2650652 && v5) {
						if (v16) {
							sub_425CA0(*(uint32_t*)(v5 + 276), *(uint32_t*)(v16 + 276));
						}
					}
					goto LABEL_44;
				}
				if (!nox_xxx_unitIsCrown_4E7BE0(a1) ||
					(v13 = nox_xxx_gamedataGetFloat_419D40("KotRPawnKillsKingPoints"), v8 = nox_float2int(v13),
					 nox_xxx_changeScore_4D8E90(a2, v8),
					 nox_xxx_netChangeTeamID_419090((int)v2, v8 + *((uint32_t*)v2 + 13)),
					 nox_xxx_netReportLesson_4D8EF0(a2), !dword_5d4594_2650652) ||
					!v5 || !v16) {
				LABEL_44:
					nox_xxx_playerIncrementElimDeath_4D8D40(a1);
					nox_xxx_netReportLesson_4D8EF0(a1);
					return;
				}
				v9 = *(uint32_t*)(v5 + 276);
				v14 = *(uint32_t*)(v16 + 276);
			}
			sub_425CA0(v9, v14);
			goto LABEL_44;
		}
	}
}

//----- (0054DF00) --------------------------------------------------------
void nox_xxx_netNotifyPlayerDied_54DF00(int a1) {
	int v1 = 0; // ecx
	short v2;   // cx
	int v4;     // [esp+0h] [ebp-4h]

	v4 = v1;
	v2 = *(uint16_t*)(a1 + 36);
	LOBYTE(v4) = -24;
	*(uint16_t*)((char*)&v4 + 1) = v2;
	nox_xxx_netSendPacket1_4E5390(255, (int)&v4, 3, 0, 0);
}

//----- (0054DF30) --------------------------------------------------------
char nox_xxx_dieGlyph_54DF30(int a1) { return nox_xxx_trapBAH_537C10(a1, 0); }

//----- (0054DFA0) --------------------------------------------------------
void nox_xxx_dieBarrel_54DFA0(int a1) {
	int v1;       // eax
	uint32_t* v2; // eax

	v1 = *getMemU32Ptr(0x5D4594, 2491696);
	if (!*getMemU32Ptr(0x5D4594, 2491696)) {
		v1 = nox_xxx_getNameId_4E3AA0("BarrelBreaking");
		*getMemU32Ptr(0x5D4594, 2491696) = v1;
	}
	v2 = nox_xxx_newObjectWithTypeInd_4E3450(v1);
	if (v2) {
		nox_xxx_createAt_4DAA50((int)v2, 0, *(float*)(a1 + 56), *(float*)(a1 + 60));
	}
	nox_xxx_aud_501960(286, a1, 0, 0);
	nox_xxx_spawnSomeBarrel_4E7470(a1, a1 + 56);
	nox_xxx_delayedDeleteObject_4E5CC0(a1);
}

//----- (0054E010) --------------------------------------------------------
void nox_xxx_dieCreateObject_54E010(int a1) {
	int v1;       // edi
	uint32_t* v2; // eax
	int v3;       // edi

	v1 = *(uint32_t*)(a1 + 728);
	v2 = nox_xxx_newObjectByTypeID_4E3810(*(char**)(a1 + 728));
	if (v2) {
		nox_xxx_createAt_4DAA50((int)v2, 0, *(float*)(a1 + 56), *(float*)(a1 + 60));
	}
	v3 = *(uint32_t*)(v1 + 128);
	if (v3) {
		nox_xxx_aud_501960(v3, a1, 0, 0);
	}
	nox_xxx_delayedDeleteObject_4E5CC0(a1);
}

//----- (0054E070) --------------------------------------------------------
short nox_xxx_dieSpawnObject_54E070(int a1) {
	int v1;       // edi
	uint32_t* v2; // eax
	int v3;       // edi
	int v4;       // eax

	v1 = *(uint32_t*)(a1 + 728);
	v2 = nox_xxx_newObjectByTypeID_4E3810(*(char**)(a1 + 728));
	if (v2) {
		nox_xxx_createAt_4DAA50((int)v2, 0, *(float*)(a1 + 56), *(float*)(a1 + 60));
	}
	v3 = *(uint32_t*)(v1 + 128);
	if (v3) {
		nox_xxx_aud_501960(v3, a1, 0, 0);
	}
	v4 = *(uint32_t*)(a1 + 16);
	BYTE1(v4) |= 0x80u;
	*(uint32_t*)(a1 + 16) = v4;
	return v4;
}

//----- (0054E460) --------------------------------------------------------
void nox_xxx_dieMarker_54E460(int a1) {
	int v1;       // eax
	int v2;       // edx
	int v3;       // eax
	uint32_t* v4; // ecx

	v1 = nox_xxx_findParentChainPlayer_4EC580(a1);
	if (v1) {
		v2 = *(uint32_t*)(v1 + 748);
		v3 = 0;
		v4 = (uint32_t*)(v2 + 116);
		while (*v4 != a1) {
			++v3;
			++v4;
			if (v3 >= 4) {
				goto LABEL_7;
			}
		}
		*(uint32_t*)(v2 + 4 * v3 + 116) = 0;
	}
LABEL_7:
	nox_xxx_netSendPointFx_522FF0(138, (float2*)(a1 + 56));
	nox_xxx_delayedDeleteObject_4E5CC0(a1);
}

//----- (0054E4B0) --------------------------------------------------------
void nox_xxx_dieBoulder_54E4B0(int a1) {
	int v1;     // esi
	float2* v2; // edi
	int v3;     // ebp
	int v4;     // ebx
	int v5;     // edx
	float* v6;  // esi
	double v7;  // st7
	int v8;     // eax
	float v9;   // [esp+0h] [ebp-20h]
	float v10;  // [esp+0h] [ebp-20h]
	float2 a3;  // [esp+18h] [ebp-8h]

	v1 = a1;
	nox_xxx_aud_501960(757, a1, 0, 0);
	v2 = (float2*)(a1 + 56);
	nox_xxx_netSendPointFx_522FF0(138, (float2*)(a1 + 56));
	v3 = nox_common_randomInt_415FA0(20, 30);
	v4 = 0;
	if (v3 <= 0) {
	LABEL_6:
		nox_xxx_delayedDeleteObject_4E5CC0(v1);
	} else {
		v5 = dword_5d4594_2491704;
		while (1) {
			v6 = (float*)nox_xxx_newObjectByTypeID_4E3810(*(char**)getMemAt(0x587000, 291512 + 4 * v5));
			if (!v6) {
				break;
			}
			sub_4ED970(30.0, v2, &a3);
			nox_xxx_createAt_4DAA50((int)v6, 0, a3.field_0, a3.field_4);
			v9 = nox_common_randomFloat_416030(10.0, 70.0);
			nox_xxx_unitRaise_4E46F0((int)v6, v9);
			v6[27] = nox_common_randomFloat_416030(-2.0, 0.0);
			v7 = (double)getMemByte(0x587000, 290328 + dword_5d4594_2491704);
			*((uint32_t*)v6 + 4) |= 0x800000;
			v6[29] = v7;
			v10 = nox_common_randomFloat_416030(5.0, 20.0);
			nox_xxx_objectApplyForce_52DF80((int)v2, (int)v6, v10);
			v8 = nox_common_randomInt_415FA0(45, 75);
			nox_xxx_unitSetDecayTime_511660(v6, nox_gameFPS * v8);
			v5 = (dword_5d4594_2491704 + 1) % *getMemU32Ptr(0x587000, 290340);
			++v4;
			dword_5d4594_2491704 = (dword_5d4594_2491704 + 1) % *getMemU32Ptr(0x587000, 290340);
			if (v4 >= v3) {
				v1 = a1;
				goto LABEL_6;
			}
		}
	}
}

//----- (0054E620) --------------------------------------------------------
int nox_xxx_dieGameBall_54E620(int a1) { return sub_417F50(a1); }

//----- (0054E630) --------------------------------------------------------
void nox_xxx_dieMonsterGen_54E630(int a1) {
	int v1;       // edi
	int v2;       // eax
	uint32_t* v3; // eax

	v1 = *(uint32_t*)(a1 + 748);
	sub_4D71E0(nox_frame_xxx_2598000);
	sub_4D7520(0);
	nox_xxx_scriptCallByEventBlock_502490((int*)(v1 + 56), *(uint32_t*)(a1 + 520), a1, 3);
	nox_xxx_aud_501960(1000, a1, 0, 0);
	nox_xxx_sendGeneratorBreakFX_523200((float*)(a1 + 56), 200);
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		if (*(uint32_t*)(a1 + 520)) {
			v2 = nox_xxx_findParentChainPlayer_4EC580(*(uint32_t*)(a1 + 520));
			if (*(uint8_t*)(v2 + 8) & 4) {
				sub_4D61B0(v2);
			}
		}
	}
	v3 = nox_xxx_newObjectByTypeID_4E3810("DestroyedGenerator");
	if (v3) {
		nox_xxx_createAt_4DAA50((int)v3, 0, *(float*)(a1 + 56), *(float*)(a1 + 60));
	}
	nox_xxx_delayedDeleteObject_4E5CC0(a1);
}

//----- (0054E6F0) --------------------------------------------------------
int sub_54E6F0(int a1, int a2) {
	int result; // eax

	result = sub_54E730(a2, a1);
	if (result) {
		result = !nox_xxx_unitsHaveSameTeam_4EC520(a1, a2) || nox_xxx_GetGameplayFlags_417D90() & 1;
	}
	return result;
}

//----- (0054E730) --------------------------------------------------------
int sub_54E730(int a1, int a2) {
	int v2;     // ecx
	int v3;     // eax
	int result; // eax
	int v5;     // eax

	if (*(uint8_t*)(a2 + 8) & 1) {
		goto LABEL_27;
	}
	v2 = *(uint32_t*)(a1 + 16);
	if (v2 & 0x20) {
		goto LABEL_27;
	}
	v3 = *(uint32_t*)(a2 + 16);
	if (v3 & 0x20 || !*(uint32_t*)(a1 + 696) || !*(uint32_t*)(a2 + 696) || v3 & 0x40) {
		goto LABEL_27;
	}
	if ((v3 & 0x80u) != 0) {
		return 1;
	}
	if (v2 & 0x11 && v3 & 0x4000 || v3 & 0x11 && v2 & 0x4000 ||
		(v2 & 0x400 || v3 & 0x400) && nox_xxx_unitsHaveSameTeam_4EC520(a2, a1) ||
		(v5 = *(uint32_t*)(a1 + 508)) != 0 && *(uint8_t*)(a1 + 8) & 1 && !(*(uint8_t*)(a1 + 12) & 2) &&
			*(uint8_t*)(v5 + 8) & 2 && *(uint8_t*)(a2 + 8) & 2 &&
			(!nox_xxx_unitIsEnemyTo_5330C0(v5, a2) || nox_xxx_unitsHaveSameTeam_4EC520(a2, *(uint32_t*)(a1 + 508)))) {
	LABEL_27:
		result = 0;
	} else {
		result = 1;
	}
	return result;
}

//----- (0054E810) --------------------------------------------------------
int sub_54E810(int a1, float2* a2, int a3) {
	int a3a[4]; // [esp+0h] [ebp-10h]

	a3a[0] = a1;
	a3a[1] = 0;
	a3a[2] = a3;
	a3a[3] = (int)a2;
	sub_517B70(a2, sub_54E850, (int)a3a);
	return a3a[1];
}

//----- (0054E850) --------------------------------------------------------
void sub_54E850(int a1, int a2) {
	int v2;       // eax
	float2* v3;   // ecx
	float2* v4;   // edx
	float v5;     // edx
	uint32_t* v6; // edx
	uint32_t* v7; // eax
	float4 a2a;   // [esp+8h] [ebp-20h]
	float4 a1a;   // [esp+18h] [ebp-10h]

	if ((signed char)*(uint8_t*)(a1 + 8) >= 0) {
		if (sub_54E730(*(uint32_t*)a2, a1) && sub_547DB0(a1, *(float2**)(a2 + 12))) {
			*(uint32_t*)(a2 + 4) = a1;
		}
	} else {
		v2 = *(uint32_t*)(a1 + 748);
		if (!(*(uint8_t*)(a1 + 12) & 4)) {
			v3 = *(float2**)(a2 + 8);
			a1a.field_0 = v3->field_0;
			v4 = *(float2**)(a2 + 12);
			a1a.field_4 = v3->field_4;
			a1a.field_8 = v4->field_0;
			v5 = v4->field_4;
			a2a.field_0 = *(float*)(a1 + 56);
			a1a.field_C = v5;
			a2a.field_4 = *(float*)(a1 + 60);
			a2a.field_8 = (double)*getMemIntPtr(0x587000, 196184 + 8 * *(uint32_t*)(v2 + 12)) + a2a.field_0;
			a2a.field_C = (double)*getMemIntPtr(0x587000, 196188 + 8 * *(uint32_t*)(v2 + 12)) + a2a.field_4;
			if (sub_427980(&a1a, &a2a)) {
				v6 = *(uint32_t**)(a2 + 8);
				v7 = *(uint32_t**)(a2 + 12);
				*v7 = *v6;
				v7[1] = v6[1];
				*(uint32_t*)(a2 + 4) = a1;
			}
		}
	}
}

//----- (0054E930) --------------------------------------------------------
char nox_xxx_updateMonsterGenerator_54E930(uint32_t* a1) {
	unsigned int v1; // esi
	int v2;          // edi
	int v3;          // ebp
	unsigned int v4; // eax
	unsigned int v5; // ebx
	unsigned int v6; // esi
	int v7;          // ecx
	double v8;       // st7
	int v9;          // ecx
	uint32_t* v10;   // eax
	int v11;         // edx
	int v12;         // esi
	float v14;       // [esp+0h] [ebp-24h]
	float v15;       // [esp+0h] [ebp-24h]
	float v16;       // [esp+0h] [ebp-24h]
	float v17;       // [esp+0h] [ebp-24h]
	float v18;       // [esp+0h] [ebp-24h]
	float v19;       // [esp+0h] [ebp-24h]
	float v20;       // [esp+0h] [ebp-24h]
	float v21;       // [esp+0h] [ebp-24h]
	long long v22;   // [esp+14h] [ebp-10h]
	float2 a2;       // [esp+1Ch] [ebp-8h]

	v1 = nox_game_getQuestStage_4E3CC0();
	v2 = a1[187];
	v3 = nox_xxx_getQuestStage_51A930();
	if (!dword_5d4594_2491716) {
		v14 = nox_xxx_gamedataGetFloat_419D40("QuestHardcoreStage");
		dword_5d4594_2491716 = nox_float2int(v14);
		v15 = nox_xxx_gamedataGetFloat_419D40("QuestHardcoreSpawnRateIncrease");
		*getMemU32Ptr(0x5D4594, 2491720) = nox_float2int(v15);
		*getMemFloatPtr(0x5D4594, 2491744) = nox_xxx_gamedataGetFloat_419D40("QuestHardcoreSpawnCap");
		v16 = nox_xxx_gamedataGetFloat_419D40("SpawnRateHighValue");
		*getMemU32Ptr(0x5D4594, 2491724) = nox_float2int(v16);
		v17 = nox_xxx_gamedataGetFloat_419D40("SpawnRateNormalValue");
		*getMemU32Ptr(0x5D4594, 2491728) = nox_float2int(v17);
		v18 = nox_xxx_gamedataGetFloat_419D40("SpawnRateLowValue");
		*getMemU32Ptr(0x5D4594, 2491732) = nox_float2int(v18);
		v19 = nox_xxx_gamedataGetFloat_419D40("SpawnRateVeryLowValue");
		*getMemU32Ptr(0x5D4594, 2491736) = nox_float2int(v19);
		v20 = nox_xxx_gamedataGetFloat_419D40("SpawnRateVeryVeryLowValue");
		*getMemU32Ptr(0x5D4594, 2491740) = nox_float2int(v20);
	}
	v4 = a1[5];
	if (!(v4 & 0x800)) {
		v4 = a1[4];
		if (v4 & 0x1000000) {
			if (!(v4 & 0x8020)) {
				nox_xxx_unitNeedSync_4E44F0((int)a1);
				v5 = nox_frame_xxx_2598000 - *(uint32_t*)(v2 + 88);
				switch (*(unsigned char*)(v2 + v3 + 80)) {
				case 0u:
					v4 = *getMemU32Ptr(0x5D4594, 2491724);
					break;
				case 1u:
					v4 = *getMemU32Ptr(0x5D4594, 2491728);
					break;
				case 2u:
					v4 = *getMemU32Ptr(0x5D4594, 2491732);
					break;
				case 3u:
					v4 = *getMemU32Ptr(0x5D4594, 2491736);
					break;
				case 4u:
					v4 = *getMemU32Ptr(0x5D4594, 2491740);
					break;
				default:
					v4 = (unsigned int)a1;
					break;
				}
				if (v1 >= *(int*)&dword_5d4594_2491716) {
					v6 = *getMemU32Ptr(0x5D4594, 2491720) * (v1 - dword_5d4594_2491716 + 1);
					if (v6 > v4) {
						v7 = 0;
					} else {
						v7 = v4 - v6;
					}
					v22 = v4;
					v8 = (double)v4;
					LODWORD(v22) = v7;
					if ((double)v22 / v8 < *getMemFloatPtr(0x5D4594, 2491744)) {
						v21 = v8 * *getMemFloatPtr(0x5D4594, 2491744);
						v7 = nox_float2int(v21);
					}
					v4 = v7;
				}
				if (v5 > v4) {
					LOBYTE(v4) = *(uint8_t*)(v2 + 86);
					if ((unsigned char)v4 < *(uint8_t*)(v2 + 87)) {
						if ((unsigned char)nox_frame_xxx_2598000 & 8) {
							v9 = 0;
							v10 = (uint32_t*)(v2 + 16 * v3);
							v11 = 4;
							do {
								if (*v10) {
									++v9;
								}
								++v10;
								--v11;
							} while (v11);
							v12 = *(uint32_t*)(v2 + 4 * (nox_common_randomInt_415FA0(0, v9 - 1) + 4 * v3));
							v4 = nox_xxx_mobGeneratorPick_54EBA0(a1, &a2, v12);
							if (v4 == 1) {
								LOBYTE(v4) = (unsigned int)nox_xxx_mobGeneratorSpawn_54F070((int)a1, (int)&a2, v12);
								*(uint32_t*)(v2 + 88) = nox_frame_xxx_2598000;
							}
						}
					}
				}
			}
		}
	}
	return v4;
}

//----- (0054EBA0) --------------------------------------------------------
int nox_xxx_mobGeneratorPick_54EBA0(uint32_t* a1, float2* a2, int a4) {
	float* v3;   // esi
	int v4;      // ebx
	int v5;      // edx
	int v6;      // eax
	float v7;    // edx
	float v8;    // ecx
	float v9;    // edx
	int v10;     // eax
	char* v11;   // eax
	int v13;     // [esp+18h] [ebp-A0h]
	float v14;   // [esp+1Ch] [ebp-9Ch]
	int* v15;    // [esp+20h] [ebp-98h]
	int v16;     // [esp+24h] [ebp-94h]
	float4 a1a;  // [esp+28h] [ebp-90h]
	int v18[32]; // [esp+38h] [ebp-80h]

	v13 = 0;
	v16 = a1[187];
	v3 = (float*)nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (!v3) {
		return 0;
	}
	v15 = v18;
	do {
		v4 = *((uint32_t*)v3 + 187);
		if (!((uint32_t)v3[4] & 0x8020)) {
			v5 = *(uint32_t*)(v4 + 276);
			if (!(*(uint8_t*)(v5 + 3680) & 1)) {
				v6 = *(uint32_t*)(v16 + 92);
				if (v6 & 1) {
					if (nox_xxx_calcDistance_4E6C00((int)a1, (int)v3) <= 300.0) {
						return nox_xxx_mgenSetCreaturePos_54ED50((int)a1, a2, 0, a4);
					}
				} else {
					if (!(v6 & 2)) {
						return 0;
					}
					v14 = nox_double2float(sqrt((double)(*(unsigned short*)(v5 + 12) * *(unsigned short*)(v5 + 12) +
														 *(unsigned short*)(v5 + 10) * *(unsigned short*)(v5 + 10))));
					if (nox_xxx_calcDistance_4E6C00((int)a1, (int)v3) <= v14) {
						v7 = *((float*)a1 + 14);
						v8 = v3[14];
						a1a.field_4 = *((float*)a1 + 15);
						a1a.field_0 = v7;
						v9 = v3[15];
						a1a.field_8 = v8;
						a1a.field_C = v9;
						if (nox_xxx_mapTraceRay_535250(&a1a, 0, 0, 69)) {
							*v15 = *(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064);
							++v13;
							++v15;
						}
					}
				}
			}
		}
		v3 = (float*)nox_xxx_getNextPlayerUnit_4DA7F0((int)v3);
	} while (v3);
	if (!v13) {
		return 0;
	}
	v10 = nox_common_randomInt_415FA0(0, v13 - 1);
	v11 = nox_common_playerInfoFromNum_417090(v18[v10]);
	return nox_xxx_mgenSetCreaturePos_54ED50((int)a1, a2, *((uint32_t*)v11 + 514), a4);
}
// 54EBA0: using guessed type int var_80[32];

//----- (0054ED50) --------------------------------------------------------
int nox_xxx_mgenSetCreaturePos_54ED50(int a1, float2* a2, int a3, int a4) {
	int v4;     // ecx
	char v5;    // al
	float v6;   // ecx
	short v7;   // ax
	float2 a1a; // [esp+10h] [ebp-18h]
	float4 v10; // [esp+18h] [ebp-10h]

	if (*(uint8_t*)(*(uint32_t*)(a1 + 748) + 92) & 2 && a3) {
		a1a.field_0 = *(float*)(a3 + 56) - *(float*)(a1 + 56);
		a1a.field_4 = *(float*)(a3 + 60) - *(float*)(a1 + 60);
		if (a1a.field_0 == 0.0) {
			a1a.field_0 = a1a.field_0 + 1.0;
		}
		if (a1a.field_4 == 0.0) {
			a1a.field_4 = a1a.field_4 + 1.0;
		}
		nox_xxx_utilNormalizeVector_509F20(&a1a);
		a1a.field_0 = a1a.field_0 * 45.0 + *(float*)(a1 + 56);
		a1a.field_4 = a1a.field_4 * 45.0 + *(float*)(a1 + 60);
		if (!sub_54EF00(&a1a.field_0)) {
			v10.field_8 = a1a.field_0;
			v10.field_0 = *(float*)(a1 + 56);
			v4 = *(uint32_t*)(a4 + 16);
			v10.field_C = a1a.field_4;
			v5 = 1;
			v10.field_4 = *(float*)(a1 + 60);
			if (v4 & 0x4000) {
				v5 = 5;
			}
			if (nox_xxx_mapTraceRay_535250(&v10, 0, 0, v5) && !nox_xxx_mapTileAllowTeleport_411A90(&a1a)) {
				v6 = a1a.field_4;
				a2->field_0 = a1a.field_0;
				a2->field_4 = v6;
				a1a.field_0 = *(float*)(a3 + 56) - a1a.field_0;
				a1a.field_4 = *(float*)(a3 + 60) - a1a.field_4;
				v7 = nox_xxx_math_509ED0(&a1a);
				goto LABEL_16;
			}
		}
	}
	if (sub_54EF90(45.0, a1 + 56, (int)a2, a4) == 1) {
		if (!a3) {
			return 1;
		}
		v10.field_0 = *(float*)(a3 + 56) - *(float*)(a1 + 56);
		v10.field_4 = *(float*)(a3 + 60) - *(float*)(a1 + 60);
		v7 = nox_xxx_math_509ED0((float2*)&v10);
	LABEL_16:
		*(uint16_t*)(a4 + 124) = v7;
		*(uint16_t*)(a4 + 126) = v7;
		return 1;
	}
	return 0;
}

//----- (0054EF00) --------------------------------------------------------
int sub_54EF00(float* a3) {
	float4 a1; // [esp+0h] [ebp-10h]

	*getMemU32Ptr(0x5D4594, 2491708) = 0;
	a1.field_0 = *a3 - 15.0;
	a1.field_4 = a3[1] - 15.0;
	a1.field_8 = *a3 + 15.0;
	a1.field_C = a3[1] + 15.0;
	nox_xxx_getUnitsInRect_517C10(&a1, sub_54EF60, (int)a3);
	return *getMemU32Ptr(0x5D4594, 2491708);
}

//----- (0054EF60) --------------------------------------------------------
void sub_54EF60(float* a1, int a2) {
	int v2; // ecx

	if (!((uint32_t)a1[2] & 0x20000)) {
		v2 = *((uint32_t*)a1 + 5);
		if (!(v2 & 0x800) && sub_547DB0((int)a1, (float2*)a2) == 1) {
			*getMemU32Ptr(0x5D4594, 2491708) = 1;
		}
	}
}

//----- (0054EF90) --------------------------------------------------------
int sub_54EF90(float a1, int a2, int a3, int a4) {
	float* v4;      // esi
	float v5;       // ecx
	char v6;        // bl
	int v7;         // eax
	int v8;         // edi
	long double v9; // st7
	float v11;      // edx
	float4 v12;     // [esp+Ch] [ebp-10h]
	int v13;        // [esp+24h] [ebp+8h]

	v4 = (float*)a2;
	v5 = *(float*)(a2 + 4);
	v6 = 1;
	v12.field_0 = *(float*)a2;
	v12.field_4 = v5;
	*(float*)&v13 = nox_common_randomFloat_416030(-3.1415927, 3.1415927);
	v7 = *(uint32_t*)(a4 + 16);
	if (v7 & 0x4000) {
		v6 = 5;
	}
	v8 = 0;
	while (1) {
		v9 = *(float*)&v13 + 1.8849558;
		*(float*)&v13 = v9;
		v12.field_8 = cos(v9) * a1 + *v4;
		v12.field_C = sin(*(float*)&v13) * a1 + v4[1];
		if (nox_xxx_mapTraceRay_535250(&v12, 0, 0, v6)) {
			if (!sub_54EF00(&v12.field_8) && !nox_xxx_mapTileAllowTeleport_411A90((float2*)&v12.field_8)) {
				break;
			}
		}
		if (++v8 >= 32) {
			return 0;
		}
	}
	v11 = v12.field_C;
	*(float*)a3 = v12.field_8;
	*(float*)(a3 + 4) = v11;
	return 1;
}

//----- (0054F070) --------------------------------------------------------
void* nox_xxx_objectTypeByIndHealthData(int a1);
uint32_t* nox_xxx_mobGeneratorSpawn_54F070(int a1, int a2, int a3) {
	int v3;           // edi
	uint32_t* result; // eax
	uint32_t* v5;     // esi
	int v6;           // ebp
	int v7;           // ebp
	int v8;           // ebp
	uint16_t* v9;     // eax
	int v10;          // eax
	int v11;          // eax
	float v12;        // edx
	int v13;          // eax
	double v14;       // st7
	float v15;        // [esp+0h] [ebp-30h]
	float v16;        // [esp+0h] [ebp-30h]
	float v17;        // [esp+0h] [ebp-30h]
	float v18;        // [esp+4h] [ebp-2Ch]
	float v19;        // [esp+4h] [ebp-2Ch]
	int v20;          // [esp+14h] [ebp-1Ch]
	float2 a1a;       // [esp+18h] [ebp-18h]
	int4 v22;         // [esp+20h] [ebp-10h]
	int v23;          // [esp+34h] [ebp+4h]

	v3 = a1;
	v20 = *(uint32_t*)(a1 + 748);
	nox_xxx_getQuestStage_51A930();
	if (!*getMemU32Ptr(0x5D4594, 2491712)) {
		*getMemU32Ptr(0x5D4594, 2491712) = nox_xxx_getNameId_4E3AA0("Beholder");
	}
	result = (uint32_t*)sub_50DE80(a1, (float*)a2);
	if (result) {
		result = nox_xxx_newObjectWithTypeInd_4E3450(*(unsigned short*)(a3 + 4));
		v5 = result;
		if (result) {
			v6 = result[187];
			v23 = result[187];
			nox_xxx_unitCreatureCopyUC_54F2B0(a3, (int)result);
			v7 = *(uint32_t*)(v6 + 484);
			if (v7) {
				v15 = sub_4E40F0() * (double)*(int*)(v7 + 72);
				*(uint16_t*)v5[139] = nox_float2int(v15);
				v16 = sub_4E40F0() * (double)*(int*)(v7 + 72);
			} else {
				v8 = nox_xxx_objectTypeByIndHealthData(*((unsigned short*)v5 + 2));
				v17 = sub_4E40F0() * (double)*(unsigned short*)v8;
				*(uint16_t*)v5[139] = nox_float2int(v17);
				v16 = sub_4E40F0() * (double)*(unsigned short*)(v8 + 4);
			}
			*(uint16_t*)(v5[139] + 4) = nox_float2int(v16);
			v9 = (uint16_t*)v5[139];
			if (!*v9) {
				*v9 = 1;
			}
			v10 = v5[139];
			if (!*(uint16_t*)(v10 + 4)) {
				*(uint16_t*)(v10 + 4) = 1;
			}
			if (*((unsigned short*)v5 + 2) == *getMemU32Ptr(0x5D4594, 2491712)) {
				*(uint32_t*)(v23 + 1504) = 0;
			}
			if (sub_50E030(v3, v5)) {
				nox_xxx_createAt_4DAA50((int)v5, 0, *(float*)a2, *(float*)(a2 + 4));
				nox_xxx_scriptCallByEventBlock_502490((int*)(v20 + 64), (int)v5, v3, 2);
				v11 = nox_float2int(*(float*)(v3 + 56));
				v12 = *(float*)(v3 + 60);
				v22.field_0 = v11;
				v13 = nox_float2int(v12);
				v14 = *(float*)a2 - *(float*)(v3 + 56);
				v22.field_4 = v13 - 50;
				a1a.field_0 = v14;
				a1a.field_4 = *(float*)(a2 + 4) - *(float*)(v3 + 60);
				nox_xxx_utilNormalizeVector_509F20(&a1a);
				v18 = a1a.field_0 * 30.0 + *(float*)a2;
				v22.field_8 = nox_float2int(v18);
				v19 = a1a.field_4 * 30.0 + *(float*)(a2 + 4);
				v22.field_C = nox_float2int(v19);
				nox_xxx_sendGeneratorSpawnFX_523830(&v22, 10);
				result = nox_xxx_aud_501960(1002, (int)v5, 0, 0);
			} else {
				result = (uint32_t*)nox_xxx_objectFreeMem_4E38A0((int)v5);
			}
		}
	}
	return result;
}

//----- (0054F2B0) --------------------------------------------------------
void nox_xxx_unitCreatureCopyUC_54F2B0(int a1, int a2) {
	int v2;       // ebp
	int v3;       // edi
	uint32_t* v4; // eax
	uint32_t* v5; // esi
	int v6;       // eax
	short result; // ax

	v2 = a1;
	memcpy(*(void**)(a2 + 748), *(const void**)(a1 + 748), 0x898u);
	if (*(uint8_t*)(a1 + 12) & 0x10) {
		v3 = nox_xxx_inventoryGetFirst_4E7980(a1);
		if (v3) {
			do {
				v4 = nox_xxx_newObjectWithTypeInd_4E3450(*(unsigned short*)(v3 + 4));
				v5 = v4;
				if (v4) {
					if (v4[2] & 0x13001000) {
						nox_xxx_modifSetItemAttrs_4E4990((int)v4, *(int**)(v3 + 692));
					}
					nox_xxx_inventoryPutImpl_4F3070(a2, (int)v5, 0);
					if (*(uint32_t*)(v3 + 16) & 0x100) {
						v6 = v5[2];
						if (v6 & 0x1001000) {
							nox_xxx_NPCEquipWeapon_53A2C0(a2, (int)v5);
						} else if (v6 & 0x2000000) {
							nox_xxx_NPCEquipArmor_53E520(a2, v5);
						}
					}
				}
				v3 = nox_xxx_inventoryGetNext_4E7990(v3);
			} while (v3);
			v2 = a1;
		}
	}
	result = *(uint16_t*)(v2 + 124);
	*(uint16_t*)(a2 + 124) = result;
	*(uint16_t*)(a2 + 126) = result;
}

//----- (0054F740) --------------------------------------------------------
void nox_xxx_unitUpdateMover_54F740(int a1) {
	float* v1;         // edi
	unsigned char* v2; // esi
	int v3;            // eax
	int v4;            // ebp
	int v5;            // eax
	uint32_t* v6;      // ebp
	double v7;         // st7
	double v8;         // st7
	int v9;            // ecx
	char v10;          // al
	int v11;           // eax
	int v12;           // esi
	double v13;        // st7
	double v14;        // st6
	float v15;         // [esp+14h] [ebp-4h]
	float v16;         // [esp+1Ch] [ebp+4h]

	v1 = (float*)a1;
	v2 = *(unsigned char**)(a1 + 748);
	if (!*((uint32_t*)v2 + 8)) {
		goto LABEL_33;
	}
	if (!*((uint32_t*)v2 + 7)) {
		v3 = nox_xxx_netGetUnitByExtent_4ED020(*((uint32_t*)v2 + 8));
		*((uint32_t*)v2 + 7) = v3;
		if (!v3) {
			goto LABEL_33;
		}
	}
	if (*((uint32_t*)v2 + 4) && !*((uint32_t*)v2 + 3)) {
		*((uint32_t*)v2 + 3) = nox_server_getWaypointById_579C40(*((uint32_t*)v2 + 4));
	}
	if (*((uint32_t*)v2 + 6) && !*((uint32_t*)v2 + 5)) {
		*((uint32_t*)v2 + 5) = nox_server_getWaypointById_579C40(*((uint32_t*)v2 + 6));
	}
	v4 = *((uint32_t*)v2 + 7);
	v5 = *(uint32_t*)(v4 + 16);
	if (!(v5 & 4) || v5 & 0x20) {
		*((uint32_t*)v2 + 7) = 0;
	LABEL_33:
		nox_xxx_unitRemoveFromUpdatable_4DA920((uint32_t*)a1);
		return;
	}
	switch (*v2) {
	case 0u:
		if (*(uint32_t*)(a1 + 16) & 0x1000000) {
			v6 = nox_server_getWaypointById_579C40(*((uint32_t*)v2 + 2));
			if (v6) {
				nox_xxx_unitMove_4E7010(a1, (float2*)(*((uint32_t*)v2 + 7) + 56));
				v7 = (double)*((int*)v2 + 1);
				*v2 = 1;
				*((uint32_t*)v2 + 3) = v6;
				*((uint32_t*)v2 + 5) = 0;
				v8 = v7 * 0.25;
				*(float*)(a1 + 548) = v8;
				*(float*)(a1 + 544) = v8;
			} else {
				*v2 = 3;
			}
		}
		break;
	case 1u:
		if (*(uint32_t*)(a1 + 16) & 0x1000000) {
			if (*(float*)(a1 + 80) != 0.0 && *(float*)(a1 + 84) != 0.0) {
				v9 = *((uint32_t*)v2 + 3);
				if ((*(float*)(v9 + 12) - *(float*)(a1 + 60)) * *(float*)(a1 + 84) +
						(*(float*)(v9 + 8) - *(float*)(a1 + 56)) * *(float*)(a1 + 80) <=
					0.0) {
					v10 = *(uint8_t*)(v9 + 476);
					if (v10) {
						if (v10 == 1) {
							*((uint32_t*)v2 + 5) = v9;
							*((uint32_t*)v2 + 3) = *(uint32_t*)(v9 + 92);
						} else {
							do {
								v11 = nox_common_randomInt_415FA0(0, *(unsigned char*)(v9 + 476) - 1);
								v9 = *((uint32_t*)v2 + 3);
							} while (*(uint32_t*)(v9 + 8 * v11 + 92) == *((uint32_t*)v2 + 5));
							*((uint32_t*)v2 + 5) = v9;
							*((uint32_t*)v2 + 3) = *(uint32_t*)(v9 + 8 * v11 + 92);
						}
					} else {
						*v2 = 3;
						nox_xxx_unitMove_4E7010(v4, (float2*)(v9 + 8));
					}
				}
			}
			if (*v2 == 1) {
				nox_xxx_unitMove_4E7010(*((uint32_t*)v2 + 7), (float2*)(a1 + 56));
				v12 = *((uint32_t*)v2 + 3);
				v13 = *(float*)(v12 + 8) - *(float*)(a1 + 56);
				v14 = *(float*)(v12 + 12) - *(float*)(a1 + 60);
				v15 = v14;
				v16 = sqrt(v14 * v15 + v13 * v13) + 0.1;
				v1[20] = v13 * (double)v1[136] / v16;
				if (v1[20] == 0.0) {
					v1[20] = FLT_MIN; // We need a minimal value so we don't end up checked as
									  // "uninitialized"
				}
				v1[21] = v15 * (double)v1[136] / v16;
				if (v1[21] == 0.0) {
					v1[21] = FLT_MIN; // We need a minimal value so we don't end up checked as
									  // "uninitialized"
				}
			}
		} else {
			*v2 = 2;
		}
		break;
	case 2u:
		if (*(uint32_t*)(a1 + 16) & 0x1000000) {
			nox_xxx_unitMove_4E7010(a1, (float2*)(v4 + 56));
			*v2 = 1;
		}
		break;
	case 3u:
		goto LABEL_33;
	default:
		return;
	}
}

//----- (0054F9A0) --------------------------------------------------------
int nox_xxx_updateShootingTrap_54F9A0(int a1) {
	int result; // eax
	int* v2;    // esi
	int v3;     // eax
	int v4;     // eax

	result = *(uint32_t*)(a1 + 16);
	v2 = *(int**)(a1 + 748);
	if (result & 0x1000000) {
		if (!*((uint8_t*)v2 + 48)) {
			*v2 = 0;
			v2[1] = 0;
		}
		v3 = *v2;
		*((uint8_t*)v2 + 48) = 1;
		if (!v3) {
			sub_54FBB0(a1);
			*v2 = nox_gameFPS;
		}
		if (*((uint8_t*)v2 + 8) == 1 && !v2[1]) {
			if (!*getMemU32Ptr(0x5D4594, 2491780)) {
				*getMemU32Ptr(0x5D4594, 2491780) = nox_xxx_getNameId_4E3AA0("ArrowTrap1");
				*getMemU32Ptr(0x5D4594, 2491784) = nox_xxx_getNameId_4E3AA0("ArrowTrap2");
			}
			nox_xxx_createArrowTrapProjectile_54FA80(a1, v2[3]);
			v4 = *(unsigned short*)(a1 + 4);
			if ((unsigned short)v4 == *getMemU32Ptr(0x5D4594, 2491780)) {
				nox_xxx_sendArrowTrapFX_5238A0((float*)(a1 + 56), 1);
			} else if (v4 == *getMemU32Ptr(0x5D4594, 2491784)) {
				nox_xxx_sendArrowTrapFX_5238A0((float*)(a1 + 56), 2);
			}
			v2[1] = 30;
		}
		if (*v2) {
			--*v2;
		}
		result = v2[1];
		if (result) {
			v2[1] = --result;
		}
	} else {
		*((uint8_t*)v2 + 48) = 0;
	}
	return result;
}

//----- (0054FA80) --------------------------------------------------------
void nox_xxx_createArrowTrapProjectile_54FA80(int a1, int a2) {
	double v2; // st7
	int v3;    // eax
	int v4;    // eax
	int v5;    // esi
	short v6;  // ax
	int* v7;   // esi
	float v9;  // [esp+0h] [ebp-18h]
	float v10; // [esp+10h] [ebp-8h]
	float v11; // [esp+14h] [ebp-4h]

	v2 = *(float*)(a1 + 176) + 4.0;
	v3 = 8 * *(short*)(a1 + 124);
	v10 = v2 * *getMemFloatPtr(0x587000, 194136 + v3) + *(float*)(a1 + 56);
	v11 = v2 * *getMemFloatPtr(0x587000, 194140 + v3) + *(float*)(a1 + 60);
	v4 = (int)nox_xxx_newObjectWithTypeInd_4E3450(a2);
	v5 = v4;
	if (v4) {
		nox_xxx_createAt_4DAA50(v4, a1, v10, v11);
		v6 = *(uint16_t*)(a1 + 124);
		*(uint16_t*)(v5 + 124) = v6;
		*(uint16_t*)(v5 + 126) = v6;
		*(float*)(v5 + 80) = *getMemFloatPtr(0x587000, 194136 + 8 * *(short*)(a1 + 124)) * *(float*)(v5 + 544);
		*(float*)(v5 + 84) = *getMemFloatPtr(0x587000, 194140 + 8 * *(short*)(a1 + 124)) * *(float*)(v5 + 544);
		if (!*getMemU32Ptr(0x5D4594, 2491768)) {
			*getMemU32Ptr(0x5D4594, 2491768) = nox_xxx_getNameId_4E3AA0("MercArcherArrow");
			*getMemU32Ptr(0x5D4594, 2491772) = nox_xxx_getNameId_4E3AA0("ArrowTrap1");
			*getMemU32Ptr(0x5D4594, 2491776) = nox_xxx_getNameId_4E3AA0("ArrowTrap2");
		}
		v4 = *(unsigned short*)(a1 + 4);
		if ((unsigned short)v4 == *getMemU32Ptr(0x5D4594, 2491772) || v4 == *getMemU32Ptr(0x5D4594, 2491776)) {
			v7 = *(int**)(v5 + 700);
			v9 = nox_xxx_gamedataGetFloat_419D40("ArrowTrapDamage");
			v4 = nox_float2int(v9);
			*v7 = v4;
			v7[1] = v4;
		}
		if (a2 == *getMemU32Ptr(0x5D4594, 2491768)) {
			LOWORD(v4) = (unsigned int)nox_xxx_aud_501960(889, a1, 0, 0);
		}
	}
}

//----- (0054FBB0) --------------------------------------------------------
void sub_54FBB0(int a1) {
	int v1 = *(uint32_t*)(a1 + 748);
	if (sub_54FBF0(a1)) {
		if (*(uint8_t*)(v1 + 8) != 1) {
			*(uint8_t*)(v1 + 8) = 1;
			*(uint32_t*)(v1 + 4) = 0;
		}
	} else {
		*(uint8_t*)(v1 + 8) = 0;
	}
}

//----- (0054FBF0) --------------------------------------------------------
int sub_54FBF0(int a3) {
	double v1; // st7
	float4 a1; // [esp+0h] [ebp-10h]

	a1.field_0 = *(float*)(a3 + 56) - 350.0;
	a1.field_4 = *(float*)(a3 + 60) - 350.0;
	a1.field_8 = *(float*)(a3 + 56) + 350.0;
	v1 = *(float*)(a3 + 60) + 350.0;
	*getMemU32Ptr(0x5D4594, 2491764) = 0;
	a1.field_C = v1;
	nox_xxx_getUnitsInRect_517C10(&a1, nox_xxx_unitIsAttackReachable_54FC50, a3);
	return *getMemU32Ptr(0x5D4594, 2491764);
}

//----- (0054FC50) --------------------------------------------------------
void nox_xxx_unitIsAttackReachable_54FC50(int a1, int a2) {
	if (*(uint8_t*)(a1 + 8) & 6 && !(*(uint32_t*)(a1 + 16) & 0x8020) && nox_xxx_unitIsEnemyTo_5330C0(a2, a1) &&
		nox_xxx_mapCheck_537110(a1, a2)) {
		if (nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a2 + 56), *(short*)(a2 + 124), (float2*)a1 + 7) & 1) {
			*getMemU32Ptr(0x5D4594, 2491764) = 1;
		}
	}
}

//----- (0054FCD0) --------------------------------------------------------
void nox_xxx_collideTrigger_54FCD0(int a1, int a2) {
	int* v2; // esi
	int v3;  // eax
	int v4;  // eax
	int v5;  // eax
	char v6; // al
	char v7; // al
	int v8;  // eax

	v2 = *(int**)(a1 + 748);
	if (*(uint32_t*)(a1 + 16) & 0x1000000) {
		if (*((uint8_t*)v2 + 8) != 5) {
			if (a2) {
				if (nox_xxx_objectGetMass_4E4A70(a2) > 0.0) {
					v4 = v2[11];
					if (!v4 || v4 & *(uint32_t*)(a2 + 8)) {
						v5 = v2[12];
						if (!v5 || !(v5 & *(uint32_t*)(a2 + 8))) {
							v6 = *((uint8_t*)v2 + 52);
							if (!v6 || *(uint8_t*)(a2 + 52) == v6) {
								v7 = *((uint8_t*)v2 + 53);
								if ((!v7 || *(char*)(a2 + 52) != v7) &&
									(v2[4] == -1 ||
									 *(uint32_t*)nox_xxx_scriptCallByEventBlock_502490(v2 + 3, a2, a1, 1))) {
									v8 = *v2;
									v2[1] = a2;
									LOBYTE(v8) = v8 | 1;
									*v2 = v8;
								}
							}
						}
					}
				}
			}
		}
	} else {
		v3 = *v2;
		v2[1] = 0;
		LOBYTE(v3) = v3 & 0xFE;
		*v2 = v3;
	}
}

//----- (0054FD80) --------------------------------------------------------
float* nox_xxx_createSpark_54FD80(float a1, float a2, int a3, int a4, float a5, float a6, float a7, int a8) {
	float* v8;        // esi
	uint32_t* v9;     // ebx
	int* v10;         // edi
	int v11;          // eax
	int v12;          // eax
	unsigned int v13; // ecx
	float* result;    // eax

	v8 = (float*)nox_xxx_newObjectByTypeID_4E3810("Spark");
	if (!v8) {
		return 0;
	}
	v9 = (uint32_t*)*((uint32_t*)v8 + 175);
	v10 = (int*)*((uint32_t*)v8 + 187);
	nox_xxx_createAt_4DAA50((int)v8, a8, a1, a2);
	v8[34] = *(float*)&nox_frame_xxx_2598000; // TODO: wrong type of dest, should be int
	*v10 = a4;
	v10[1] = a4;
	v10[3] = a3;
	v11 = *((uint32_t*)v8 + 2);
	BYTE1(v11) &= 0xDFu;
	v12 = v11 | 0x80000;
	v13 = (uint32_t)v8[4] & 0xFF7FFFBF;
	*((uint32_t*)v8 + 2) = v12;
	*((uint32_t*)v8 + 4) = v13;
	switch (a3) {
	case 0:
		*((uint32_t*)v8 + 4) = v13 | 0x40;
		goto LABEL_4;
	case 1:
		BYTE1(v12) |= 0x20u;
		*((uint32_t*)v8 + 2) = v12;
		*((uint32_t*)v8 + 4) = 0x800000 | v13;
		*v9 = 3;
		nox_xxx_unitRaise_4E46F0((int)v8, 28.0);
		v8[27] = a7;
		v8[29] = 7.0;
		v8[20] = a5;
		v8[21] = a6;
		return v8;
	case 2:
		*((uint32_t*)v8 + 4) = 0x800040 | v13;
		*v9 = 0;
		nox_xxx_unitRaise_4E46F0((int)v8, 28.0);
		v8[27] = a7;
		v8[29] = 7.0;
		v8[20] = a5;
		v8[21] = a6;
		return v8;
	case 4:
	LABEL_4:
		*((uint32_t*)v8 + 2) = v12 & 0xFFF7FFFF;
		goto LABEL_5;
	default:
	LABEL_5:
		*v9 = 0;
		nox_xxx_unitRaise_4E46F0((int)v8, 28.0);
		v8[27] = a7;
		v8[29] = 0.0;
		v8[20] = a5;
		v8[21] = a6;
		result = v8;
		break;
	}
	return result;
}

//----- (0054FEF0) --------------------------------------------------------
void sub_54FEF0(int a2) {
	float* v1; // edi
	int v2;    // esi
	int v3;    // ebx
	int v4;    // eax
	int i;     // ebp
	int v6;    // esi
	float v7;  // [esp+0h] [ebp-20h]
	float v8;  // [esp+0h] [ebp-20h]
	float v9;  // [esp+0h] [ebp-20h]
	float v10; // [esp+0h] [ebp-20h]
	int v11;   // [esp+14h] [ebp-Ch]
	int2 a1;   // [esp+18h] [ebp-8h]
	int a2a;   // [esp+24h] [ebp+4h]

	v1 = (float*)a2;
	if (!(*(uint32_t*)(a2 + 8) & 0x400000)) {
		v7 = *(float*)(a2 + 232) * 0.043478262;
		a2a = nox_float2int(v7);
		v8 = v1[59] * 0.043478262;
		v2 = nox_float2int(v8);
		v9 = v1[60] * 0.043478262;
		v3 = nox_float2int(v9);
		v10 = v1[61] * 0.043478262;
		v4 = nox_float2int(v10);
		v11 = v4;
		for (i = v2; i <= v4; ++i) {
			v6 = a2a;
			a1.field_4 = i;
			if (a2a <= v3) {
				do {
					a1.field_0 = v6;
					if (sub_54FFC0(&a1, (int)v1)) {
						sub_548100(&a1, (int)v1);
					}
					++v6;
				} while (v6 <= v3);
				v4 = v11;
			}
		}
	}
}

//----- (0054FFC0) --------------------------------------------------------
int sub_54FFC0(int2* a1, int a2) {
	int v2;           // ebx
	int v3;           // eax
	int v4;           // edi
	int v6;           // eax
	int v7;           // ecx
	unsigned char v8; // dl
	int v9;           // eax
	int v10;          // ebx
	int v11;          // eax
	int v12;          // esi
	char v13;         // [esp+Ch] [ebp-20h]
	int a5;           // [esp+10h] [ebp-1Ch]
	int a4;           // [esp+14h] [ebp-18h]
	int v16;          // [esp+18h] [ebp-14h]
	float2 a1a;       // [esp+1Ch] [ebp-10h]
	float2 a7;        // [esp+24h] [ebp-8h]

	v2 = a2;
	a4 = 0;
	a5 = 0;
	v16 = 0;
	v3 = *(uint32_t*)(a2 + 16);
	if (!(v3 & 0x4000) || *(uint32_t*)(a2 + 172) != 2 || (v13 = 0, *(float*)(a2 + 176) > 9.0)) {
		v13 = 64;
	}
	v4 = (unsigned char)sub_57B500(a1->field_0, a1->field_4, v13);
	if (v4 == 255) {
		return 0;
	}
	v6 = a1->field_0;
	v7 = a1->field_4;
	a1a.field_0 = (double)(23 * a1->field_0);
	v8 = getMemByte(0x587000, 313272 + 24*v4);
	a1a.field_4 = (double)(23 * v7);
	if (v8) {
		if (getMemByte(0x587000, 292496 + v4) & 2 && sub_57B500(v6 - 1, v7 - 1, v13) == -1) {
			a4 = 1;
		}
		if (getMemByte(0x587000, 292496 + v4) & 4 && sub_57B500(a1->field_0 + 1, a1->field_4 + 1, v13) == -1) {
			a5 = 1;
		}
		if (v4 == 7 || v4 == 10) {
			a5 = 1;
		} else if (v4 == 8 || v4 == 9) {
			a4 = 1;
			v9 = sub_550280((int)&a1a, *getMemFloatPtr(0x587000, 313272 + 4 + 24*v4),
							*getMemFloatPtr(0x587000, 313272 + 8 + 24*v4), 1, a5, a2 + 64, (int)&a7);
			goto LABEL_21;
		}
		v9 = sub_550280((int)&a1a, *getMemFloatPtr(0x587000, 313272 + 4 + 24*v4),
						*getMemFloatPtr(0x587000, 313272 + 8 + 24*v4), a4, a5, a2 + 64, (int)&a7);
	LABEL_21:
		if (v9) {
			if (*(uint8_t*)(a2 + 8) & 4) {
				v10 = *(uint32_t*)(a2 + 748);
				if (v10) {
					*(uint32_t*)(v10 + 296) = nox_server_getWallAtGrid_410580(a1->field_0, a1->field_4);
				}
				v2 = a2;
			}
			if (sub_550380(v4, v2, &a7)) {
				v16 = 1;
			}
		}
	}
	if (getMemByte(0x587000, 313272 + 12*1 + 24*v4)) {
		if (getMemByte(0x587000, 292496 + v4) & 8 && sub_57B500(a1->field_0 - 1, a1->field_4 + 1, v13) == -1) {
			a4 = 1;
		}
		if (getMemByte(0x587000, 292496 + v4) & 1 && sub_57B500(a1->field_0 + 1, a1->field_4 - 1, v13) == -1) {
			a5 = 1;
		}
		if (v4 == 7 || v4 == 8) {
			a4 = 1;
		} else if (v4 == 9 || v4 == 10) {
			v11 = sub_5502F0(&a1a, *getMemFloatPtr(0x587000, 313272 + 12*1 + 4 + 24*v4),
							 *getMemFloatPtr(0x587000, 313272 + 12*1 + 8 + 24*v4), a4, 1, (float2*)(v2 + 64), &a7);
			goto LABEL_42;
		}
		v11 = sub_5502F0(&a1a, *getMemFloatPtr(0x587000, 313272 + 12*1 + 4 + 24*v4), *getMemFloatPtr(0x587000, 313272 + 12*1 + 8 + 24*v4),
						 a4, a5, (float2*)(v2 + 64), &a7);
	LABEL_42:
		if (v11) {
			if (*(uint8_t*)(v2 + 8) & 4) {
				v12 = *(uint32_t*)(v2 + 748);
				if (v12) {
					*(uint32_t*)(v12 + 296) = nox_server_getWallAtGrid_410580(a1->field_0, a1->field_4);
				}
			}
			if (sub_550380(v4, v2, &a7)) {
				v16 = 1;
			}
		}
	}
	return v16;
}

//----- (00550280) --------------------------------------------------------
int sub_550280(int a1, float a2, float a3, int a4, int a5, int a6, int a7) {
	double v7; // st7

	v7 = (*(float*)a6 - *(float*)a1 + *(float*)(a6 + 4) - *(float*)(a1 + 4)) * 0.70709997 * 0.70709997;
	if (v7 < a2) {
		if (!a4) {
			return 0;
		}
		v7 = a2;
	}
	if (v7 > a3) {
		if (!a5) {
			return 0;
		}
		v7 = a3;
	}
	*(float*)a7 = v7 + *(float*)a1;
	*(float*)(a7 + 4) = v7 + *(float*)(a1 + 4);
	return 1;
}

//----- (005502F0) --------------------------------------------------------
int sub_5502F0(float2* a1, float a2, float a3, int a4, int a5, float2* a6, float2* a7) {
	double v7; // st7

	v7 = 23.0 -
		 ((a6->field_4 - a1->field_4) * 0.70709997 - (a6->field_0 - (a1->field_0 + 23.0)) * 0.70709997) * 0.70709997;
	if (v7 < a2) {
		if (!a4) {
			return 0;
		}
		v7 = a2;
	}
	if (v7 > a3) {
		if (!a5) {
			return 0;
		}
		v7 = a3;
	}
	a7->field_0 = v7 + a1->field_0;
	a7->field_4 = 23.0 - v7 + a1->field_4;
	return 1;
}

//----- (00550380) --------------------------------------------------------
int sub_550380(int a1, int a2, float2* a3) {
	float* v3;      // esi
	double v4;      // st7
	double v5;      // st6
	long double v6; // st6
	double v7;      // st7
	double v8;      // st7
	double v9;      // st7
	float v11;      // [esp+0h] [ebp-14h]
	float v12;      // [esp+4h] [ebp-10h]
	float2 v13;     // [esp+Ch] [ebp-8h]
	float v14;      // [esp+1Ch] [ebp+8h]
	float v15;      // [esp+20h] [ebp+Ch]
	float v16;      // [esp+20h] [ebp+Ch]

	v3 = (float*)a2;
	v4 = *(float*)(a2 + 64) - a3->field_0;
	v5 = *(float*)(a2 + 68) - a3->field_4;
	v15 = v5;
	v6 = sqrt(v5 * v15 + v4 * v4);
	v14 = v6;
	if (v6 == 0.0) {
		v14 = 0.0099999998;
	}
	if (v14 >= (double)v3[44]) {
		return 0;
	}
	v13.field_0 = v4 / v14;
	v7 = v15 / v14;
	v13.field_4 = v7;
	v8 = -v7 * v3[21] + -v13.field_0 * v3[20];
	v16 = v8;
	if (v8 > 0.0 && !sub_550480((int)v3)) {
		v3[20] = v16 * v13.field_0 + v3[20];
		v3[21] = v16 * v13.field_4 + v3[21];
	}
	v9 = (v3[44] - v14) * *(float*)&dword_587000_292492;
	v12 = v9 * v13.field_4;
	v11 = v9 * v13.field_0;
	sub_548600((int)v3, v11, v12);
	nox_xxx_collSysAddCollision_548630((int)v3, 0, &v13);
	return 1;
}

//----- (00550480) --------------------------------------------------------
int sub_550480(int a1) {
	int v1; // eax

	v1 = *getMemU32Ptr(0x5D4594, 2491788);
	if (!*getMemU32Ptr(0x5D4594, 2491788)) {
		v1 = nox_xxx_getNameId_4E3AA0("GameBall");
		*getMemU32Ptr(0x5D4594, 2491788) = v1;
	}
	return *(unsigned short*)(a1 + 4) == v1;
}

//----- (005504B0) --------------------------------------------------------
void sub_5504B0(int a2) {
	float* v1; // edi
	int v2;    // esi
	int v3;    // ebx
	int v4;    // eax
	int i;     // ebp
	int v6;    // esi
	float v7;  // [esp+0h] [ebp-20h]
	float v8;  // [esp+0h] [ebp-20h]
	float v9;  // [esp+0h] [ebp-20h]
	float v10; // [esp+0h] [ebp-20h]
	int v11;   // [esp+14h] [ebp-Ch]
	int2 a1;   // [esp+18h] [ebp-8h]
	int a2a;   // [esp+24h] [ebp+4h]

	v1 = (float*)a2;
	if (!(*(uint32_t*)(a2 + 8) & 0x400000)) {
		v7 = *(float*)(a2 + 232) * 0.043478262;
		a2a = nox_float2int(v7);
		v8 = v1[59] * 0.043478262;
		v2 = nox_float2int(v8);
		v9 = v1[60] * 0.043478262;
		v3 = nox_float2int(v9);
		v10 = v1[61] * 0.043478262;
		v4 = nox_float2int(v10);
		v11 = v4;
		for (i = v2; i <= v4; ++i) {
			v6 = a2a;
			a1.field_4 = i;
			if (a2a <= v3) {
				do {
					a1.field_0 = v6;
					if (sub_550580(&a1, v1)) {
						sub_548100(&a1, (int)v1);
					}
					++v6;
				} while (v6 <= v3);
				v4 = v11;
			}
		}
	}
}

//----- (00550580) --------------------------------------------------------
int sub_550580(int2* a1, float* a2) {
	int v2;            // ebp
	int v3;            // ecx
	double v5;         // st7
	double v6;         // st6
	unsigned char* v7; // edi
	double v8;         // st5
	char v9;           // bl
	double v10;        // st7
	float2 a5;         // [esp+8h] [ebp-30h]
	float2 a1a;        // [esp+10h] [ebp-28h]
	float2 a2a;        // [esp+18h] [ebp-20h]
	float2 a3;         // [esp+20h] [ebp-18h]
	float4 a4;         // [esp+28h] [ebp-10h]
	float v16;         // [esp+3Ch] [ebp+4h]

	v2 = 0;
	v3 = (unsigned char)sub_57B500(a1->field_0, a1->field_4, 64);
	if (v3 == 255) {
		return 0;
	}
	v5 = (double)(23 * a1->field_0);
	v6 = (double)(23 * a1->field_4);
	v7 = getMemAt(0x587000, 292520 + 24 * v3);
	a1a.field_0 = (a2[17] + a2[16]) * 0.70710677;
	a1a.field_4 = (a2[17] - a2[16]) * 0.70710677;
	a3.field_0 = (a2[19] + a2[18]) * 0.70710677;
	a3.field_4 = (a2[19] - a2[18]) * 0.70710677;
	v8 = a2[46] * 0.5;
	a4.field_0 = a1a.field_0 - v8;
	v16 = a2[47] * 0.5;
	a4.field_4 = a1a.field_4 - v16;
	a4.field_8 = v8 + a1a.field_0;
	a4.field_C = v16 + a1a.field_4;
	a2a.field_0 = (v6 + v5) * 0.70710677;
	a2a.field_4 = (v6 - v5) * 0.70710677;
	v9 = sub_550CB0(&a1a, &a2a);
	if (*v7) {
		if (!((unsigned char)v9 & v7[1])) {
			a5.field_0 = a2a.field_0 + 16.263456;
			v10 = a2a.field_4 - 16.263456;
			a5.field_4 = v10;
			a5.field_4 = v10 + *((float*)v7 + 1);
			if (sub_550A10((int)a2, &a1a, &a3, &a4, &a5, *((float*)v7 + 2))) {
				v2 = 1;
			}
		}
	}
	if (v7[12] && !((unsigned char)v9 & v7[13])) {
		a5 = a2a;
		a5.field_0 = a2a.field_0 + *((float*)v7 + 4);
		if (sub_550760((int)a2, &a1a, &a3, &a4, &a5, *((float*)v7 + 5))) {
			v2 = 1;
		}
	}
	return v2;
}

//----- (00550760) --------------------------------------------------------
int sub_550760(int a1, float2* a2, float2* a3, float4* a4, float2* a5, float a6) {
	float2* v6;      // edx
	float4* v7;      // edi
	double v8;       // st7
	double v9;       // st7
	double v10;      // st6
	double v11;      // st7
	double v12;      // st7
	float v13;       // et1
	double v14;      // st7
	float v15;       // et1
	double v16;      // st7
	float v17;       // et1
	long double v18; // st7
	double v19;      // st7
	double v20;      // st6
	double v21;      // st7
	float2 v23;      // [esp+8h] [ebp-18h]
	float2 v24;      // [esp+10h] [ebp-10h]
	float2 v25;      // [esp+18h] [ebp-8h]
	float v26;       // [esp+28h] [ebp+8h]
	float v27;       // [esp+30h] [ebp+10h]
	float v28;       // [esp+30h] [ebp+10h]
	float v29;       // [esp+30h] [ebp+10h]
	float v30;       // [esp+34h] [ebp+14h]
	float v31;       // [esp+34h] [ebp+14h]
	float v32;       // [esp+38h] [ebp+18h]
	float v33;       // [esp+38h] [ebp+18h]

	v6 = a5;
	v7 = a4;
	if (a4->field_0 <= (double)a5->field_0) {
		v30 = a5->field_0;
	} else {
		v30 = a4->field_0;
	}
	v8 = a6 + v6->field_0;
	if (a4->field_8 >= v8) {
		v27 = v8;
	} else {
		v27 = a4->field_8;
	}
	if (v30 > v8 || v27 < (double)v6->field_0) {
		return 0;
	}
	v9 = a2->field_4 - v6->field_4;
	v10 = a3->field_4 - v6->field_4;
	if (v10 * v9 < 0.0) {
		v11 = v6->field_4;
		v32 = v10;
		if (v32 >= 0.0) {
			v12 = v11 + 2.0;
		} else {
			v12 = v11 - 2.0;
		}
		a2->field_4 = v12;
		*(float*)(a1 + 64) = (a2->field_0 - a2->field_4) * 0.70710677;
		*(float*)(a1 + 68) = (a2->field_0 + a2->field_4) * 0.70710677;
		v7->field_4 = a2->field_4 - *(float*)(a1 + 188) * 0.5;
		v7->field_C = *(float*)(a1 + 188) * 0.5 + a2->field_4;
		v9 = a2->field_4 - v6->field_4;
	}
	if (v7->field_4 > (double)v6->field_4 || v7->field_C < (double)v6->field_4) {
		return 0;
	}
	v26 = (v27 - v30) / (v7->field_8 - v7->field_0);
	v31 = (*(float*)(a1 + 84) - *(float*)(a1 + 80)) * 0.70710677;
	if (v9 >= 0.0) {
		v28 = v6->field_4 - v7->field_4;
		v15 = *(float*)&dword_587000_292492;
		v14 = v15 * v28;
	} else {
		v28 = v7->field_C - v6->field_4;
		v13 = *(float*)&dword_587000_292492;
		v14 = -(v13 * v28);
	}
	v33 = v14;
	v16 = nox_xxx_objectGetMass_4E4A70(a1);
	v17 = *(float*)&dword_587000_292492;
	v18 = (sqrt(v16 * v17 * 4.0) * -v31 * 0.5 + v33) * v26;
	v23.field_0 = v18 * -0.70710677;
	v23.field_4 = v18 * 0.70710677;
	if (v28 >= 0.0) {
		v19 = 0.70710677;
		v24.field_0 = -0.70710677;
	} else {
		v19 = -0.70710677;
		v24.field_0 = 0.70710677;
	}
	v20 = v24.field_0 * *(float*)(a1 + 80) + v19 * *(float*)(a1 + 84);
	if (v20 < 0.0) {
		*(float*)(a1 + 80) = *(float*)(a1 + 80) - v20 * v24.field_0;
		*(float*)(a1 + 84) = *(float*)(a1 + 84) - v20 * v19;
	}
	v21 = -v19;
	v25.field_0 = v21;
	v29 = v21 * *(float*)(a1 + 80) + v24.field_0 * *(float*)(a1 + 84);
	v23.field_0 = v23.field_0 - nox_xxx_objectGetMass_4E4A70(a1) * v29 * v25.field_0 * 0.69999999;
	v23.field_4 = v23.field_4 - nox_xxx_objectGetMass_4E4A70(a1) * v29 * v24.field_0 * 0.69999999;
	sub_548600(a1, v23.field_0, v23.field_4);
	nox_xxx_collSysAddCollision_548630(a1, 0, &v23);
	return 1;
}

//----- (00550A10) --------------------------------------------------------
int sub_550A10(int a1, float2* a2, float2* a3, float4* a4, float2* a5, float a6) {
	float2* v6;      // edx
	float4* v7;      // edi
	double v8;       // st7
	double v9;       // st7
	double v10;      // st7
	double v11;      // st6
	double v12;      // st7
	double v13;      // st7
	float v14;       // et1
	double v15;      // st7
	float v16;       // et1
	double v17;      // st7
	float v18;       // et1
	long double v19; // st7
	double v20;      // st7
	double v21;      // st6
	double v22;      // st7
	float2 v24;      // [esp+8h] [ebp-18h]
	float2 v25;      // [esp+10h] [ebp-10h]
	float2 v26;      // [esp+18h] [ebp-8h]
	float v27;       // [esp+28h] [ebp+8h]
	float v28;       // [esp+30h] [ebp+10h]
	float v29;       // [esp+30h] [ebp+10h]
	float v30;       // [esp+30h] [ebp+10h]
	float v31;       // [esp+34h] [ebp+14h]
	float v32;       // [esp+34h] [ebp+14h]
	float v33;       // [esp+38h] [ebp+18h]
	float v34;       // [esp+38h] [ebp+18h]

	v6 = a5;
	v7 = a4;
	if (a5->field_4 >= (double)a4->field_4) {
		v8 = a5->field_4;
	} else {
		v8 = a4->field_4;
	}
	v31 = v8;
	v9 = a6 + v6->field_4;
	if (a4->field_C >= v9) {
		v28 = v9;
	} else {
		v28 = a4->field_C;
	}
	if (v31 > v9 || v28 < (double)v6->field_4) {
		return 0;
	}
	v10 = a2->field_0 - v6->field_0;
	v11 = a3->field_0 - v6->field_0;
	if (v11 * v10 < 0.0) {
		v12 = v6->field_0;
		v33 = v11;
		if (v33 >= 0.0) {
			v13 = v12 + 2.0;
		} else {
			v13 = v12 - 2.0;
		}
		a2->field_0 = v13;
		*(float*)(a1 + 64) = (a2->field_0 - a2->field_4) * 0.70710677;
		*(float*)(a1 + 68) = (a2->field_4 + a2->field_0) * 0.70710677;
		v7->field_0 = a2->field_0 - *(float*)(a1 + 184) * 0.5;
		v7->field_8 = *(float*)(a1 + 184) * 0.5 + a2->field_0;
		v10 = a2->field_0 - v6->field_0;
	}
	if (v7->field_0 > (double)v6->field_0 || v7->field_8 < (double)v6->field_0) {
		return 0;
	}
	v27 = (v28 - v31) / (v7->field_C - v7->field_4);
	v32 = (*(float*)(a1 + 80) + *(float*)(a1 + 84)) * 0.70710677;
	if (v10 >= 0.0) {
		v29 = v6->field_0 - v7->field_0;
		v16 = *(float*)&dword_587000_292492;
		v15 = v16 * v29;
	} else {
		v29 = v7->field_8 - v6->field_0;
		v14 = *(float*)&dword_587000_292492;
		v15 = -(v14 * v29);
	}
	v34 = v15;
	v17 = nox_xxx_objectGetMass_4E4A70(a1);
	v18 = *(float*)&dword_587000_292492;
	v19 = (sqrt(v17 * v18 * 4.0) * -v32 * 0.5 + v34) * v27 * 0.70710677;
	v24.field_0 = v19;
	v24.field_4 = v19;
	if (v29 >= 0.0) {
		v20 = 0.70710677;
		v25.field_0 = 0.70710677;
	} else {
		v20 = -0.70710677;
		v25.field_0 = -0.70710677;
	}
	v21 = v25.field_0 * *(float*)(a1 + 80) + v20 * *(float*)(a1 + 84);
	if (v21 < 0.0) {
		*(float*)(a1 + 80) = *(float*)(a1 + 80) - v21 * v25.field_0;
		*(float*)(a1 + 84) = *(float*)(a1 + 84) - v21 * v20;
	}
	v22 = -v20;
	v26.field_0 = v22;
	v30 = v22 * *(float*)(a1 + 80) + v25.field_0 * *(float*)(a1 + 84);
	v24.field_0 = v24.field_0 - nox_xxx_objectGetMass_4E4A70(a1) * v30 * v26.field_0 * 0.69999999;
	v24.field_4 = v24.field_4 - nox_xxx_objectGetMass_4E4A70(a1) * v30 * v25.field_0 * 0.69999999;
	sub_548600(a1, v24.field_0, v24.field_4);
	nox_xxx_collSysAddCollision_548630(a1, 0, &v24);
	return 1;
}

//----- (00550CB0) --------------------------------------------------------
char sub_550CB0(float2* a1, float2* a2) {
	double v2;   // st7
	char v3 = 0; // fps^1
	bool v4;     // c0
	char v5;     // c2
	bool v6;     // c3
	char v7;     // ah
	bool v8;     // c0
	bool v9;     // c3
	char result; // al
	float v11;   // [esp+0h] [ebp-8h]

	v11 = a1->field_0 - a2->field_0;
	v2 = a1->field_4 - a2->field_4;
	v4 = v11 < 16.263456;
	v5 = 0;
	v6 = v11 == 16.263456;
	v7 = v3;
	v8 = v2 < 0.0;
	v9 = v2 == 0.0;
	if (v7 & 0x41) {
		result = 8;
		if (v8 || v9) {
			result = 1;
		}
	} else if (v8 || v9) {
		result = 2;
	} else {
		result = 4;
	}
	return result;
}

//----- (00550D00) --------------------------------------------------------
void nox_xxx_collisionCheckCircleCircle_550D00(int a1, int a2) {
	int v2;         // esi
	int v3;         // edi
	int v4;         // eax
	long double v5; // st7
	double v6;      // st7
	int v7;         // ebp
	float v8;       // eax
	float v9;       // edx
	float v10;      // eax
	double v11;     // st7
	double v12;     // st6
	double v13;     // st6
	double v14;     // st5
	float v15;      // [esp+Ch] [ebp-20h]
	float v16;      // [esp+Ch] [ebp-20h]
	float v17;      // [esp+10h] [ebp-1Ch]
	float2 v18;     // [esp+14h] [ebp-18h]
	float4 a1a;     // [esp+1Ch] [ebp-10h]
	float v20;      // [esp+30h] [ebp+4h]
	float v21;      // [esp+30h] [ebp+4h]
	float v22;      // [esp+34h] [ebp+8h]
	float v23;      // [esp+34h] [ebp+8h]
	float v24;      // [esp+34h] [ebp+8h]

	v2 = a1;
	v3 = a2;
	v18.field_0 = *(float*)(a2 + 64) - *(float*)(a1 + 64);
	v18.field_4 = *(float*)(a2 + 68) - *(float*)(a1 + 68);
	if (v18.field_0 == 0.0 && v18.field_4 == 0.0) {
		v4 = nox_common_randomInt_415FA0(0, 3);
		v18.field_0 = *getMemFloatPtr(0x587000, 292784 + 8 * v4);
		v18.field_4 = *getMemFloatPtr(0x587000, 292788 + 8 * v4);
	}
	v5 = sqrt(v18.field_4 * v18.field_4 + v18.field_0 * v18.field_0);
	v22 = v5;
	if (v5 == 0.0) {
		v22 = 0.0099999998;
	}
	v6 = *(float*)(a1 + 176) + *(float*)(v3 + 176) - v22;
	v20 = v6;
	if (v6 > 0.0) {
		v7 = 1;
		if (!(*(uint32_t*)(v2 + 8) & 0x2204) || !(*(uint32_t*)(v3 + 8) & 0x2204) ||
			(v8 = *(float*)(v2 + 56), v9 = *(float*)(v3 + 56), a1a.field_4 = *(float*)(v2 + 60), a1a.field_0 = v8,
			 v10 = *(float*)(v3 + 60), a1a.field_8 = v9, a1a.field_C = v10,
			 nox_xxx_mapTraceRay_535250(&a1a, 0, 0, 0))) {
			nox_xxx_collSysAddCollision_548630(v3, v2, &v18);
			if ((*(uint8_t*)(v2 + 16) & 8) == 8 || (*(uint8_t*)(v3 + 16) & 8) == 8) {
				v7 = 0;
			}
			if ((!(*(uint8_t*)(v2 + 8) & 6) || (*(uint32_t*)(v3 + 16) & 0x2000) != 0x2000) && v7) {
				a1a.field_0 = v18.field_0 / v22;
				a1a.field_4 = v18.field_4 / v22;
				v15 = *(float*)(v2 + 80) - *(float*)(v3 + 80);
				v17 = *(float*)(v2 + 84) - *(float*)(v3 + 84);
				v23 = nox_xxx_objectGetMass_4E4A70(v2);
				if (nox_xxx_objectGetMass_4E4A70(v3) <= v23) {
					v11 = nox_xxx_objectGetMass_4E4A70(v3);
				} else {
					v11 = nox_xxx_objectGetMass_4E4A70(v2);
				}
				v12 = *(float*)&dword_587000_292488 * v20;
				v21 = -(v12 * a1a.field_0);
				v24 = -(v12 * a1a.field_4);
				if (!(*(uint8_t*)(v2 + 8) & 6) || !(*(uint8_t*)(v3 + 8) & 6)) {
					v13 = -a1a.field_4;
					v14 = v13 * v15 + v17 * a1a.field_0;
					v16 = v14;
					v21 = v21 - v14 * v13 * v11 * 0.69999999;
					v24 = v24 - v16 * v11 * a1a.field_0 * 0.69999999;
				}
				sub_548600(v2, v21, v24);
			}
			if (*(uint32_t*)(v2 + 16) & 0x8000000) {
				nox_xxx_unitHasCollideOrUpdateFn_537610(v2);
				*(uint32_t*)(v2 + 16) &= 0xF7FFFFFF;
			}
			if (*(uint32_t*)(v3 + 16) & 0x8000000) {
				nox_xxx_unitHasCollideOrUpdateFn_537610(v3);
				*(uint32_t*)(v3 + 16) &= 0xF7FFFFFF;
			}
		}
	}
}

//----- (00550F80) --------------------------------------------------------
void sub_550F80(float* a1, int a2) {
	float* v2;  // esi
	int v3;     // ebx
	double v4;  // st7
	double v5;  // st7
	int v6;     // eax
	double v7;  // st7
	double v8;  // st6
	double v9;  // st5
	double v10; // st4
	double v11; // st7
	float v12;  // et1
	double v13; // st7
	float v14;  // et1
	double v15; // st6
	float2 v16; // [esp+Ch] [ebp-38h]
	float v17;  // [esp+14h] [ebp-30h]
	float v18;  // [esp+18h] [ebp-2Ch]
	float v19;  // [esp+1Ch] [ebp-28h]
	float v20;  // [esp+20h] [ebp-24h]
	float v21;  // [esp+24h] [ebp-20h]
	float v22;  // [esp+28h] [ebp-1Ch]
	float v23;  // [esp+2Ch] [ebp-18h]
	float v24;  // [esp+30h] [ebp-14h]
	float v25;  // [esp+34h] [ebp-10h]
	float v26;  // [esp+38h] [ebp-Ch]
	float v27;  // [esp+3Ch] [ebp-8h]
	float v28;  // [esp+40h] [ebp-4h]
	float v29;  // [esp+48h] [ebp+4h]
	float v30;  // [esp+48h] [ebp+4h]

	v2 = a1;
	v3 = 1;
	v17 = (a1[16] + a1[17]) * 0.70710677;
	v18 = (a1[17] - a1[16]) * 0.70710677;
	v19 = (*(float*)(a2 + 64) + *(float*)(a2 + 68)) * 0.70710677;
	v20 = (*(float*)(a2 + 68) - *(float*)(a2 + 64)) * 0.70710677;
	v4 = a1[46] * 0.5;
	v21 = v17 - v4;
	v29 = a1[47] * 0.5;
	v22 = v18 - v29;
	v23 = v4 + v17;
	v24 = v29 + v18;
	v5 = *(float*)(a2 + 184) * 0.5;
	v25 = v19 - v5;
	v30 = *(float*)(a2 + 188) * 0.5;
	v26 = v20 - v30;
	v27 = v5 + v19;
	v28 = v30 + v20;
	if (v21 <= (double)v27 && v22 <= (double)v28 && v23 >= (double)v25 && v24 >= (double)v26) {
		v16.field_0 = *(float*)(a2 + 64) - v2[16];
		v16.field_4 = *(float*)(a2 + 68) - v2[17];
		nox_xxx_collSysAddCollision_548630(a2, (unsigned int)v2, &v16);
		if (((uint8_t)v2[4] & 8) == 8 || (*(uint8_t*)(a2 + 16) & 8) == 8) {
			v3 = 0;
		}
		if (!((uint8_t)v2[2] & 6) || (v6 = *(uint32_t*)(a2 + 16), !(v6 & 0x2000))) {
			if (v3) {
				if (v21 <= (double)v25) {
					v7 = v25;
				} else {
					v7 = v21;
				}
				if (v23 >= (double)v27) {
					v8 = v27;
				} else {
					v8 = v23;
				}
				if (v22 <= (double)v26) {
					v9 = v26;
				} else {
					v9 = v22;
				}
				if (v24 >= (double)v28) {
					v10 = v28;
				} else {
					v10 = v24;
				}
				v16.field_0 = v8 - v7;
				v16.field_4 = v10 - v9;
				if (v16.field_0 >= (double)v16.field_4) {
					if (v18 >= (double)v20) {
						v20 = v16.field_4;
					} else {
						v20 = -v16.field_4;
					}
					v11 = 0.0;
				} else {
					v11 = v16.field_0;
					if (v17 < (double)v19) {
						v11 = -v11;
					}
					v20 = 0.0;
				}
				v12 = *(float*)&dword_587000_292488;
				v13 = v11 * v12;
				v14 = *(float*)&dword_587000_292488;
				v15 = v20 * v14;
				v19 = (v13 - v15) * 0.70710677;
				v20 = (v15 + v13) * 0.70710677;
				sub_548600((int)v2, v19, v20);
			}
		}
		if ((uint32_t)v2[4] & 0x8000000) {
			nox_xxx_unitHasCollideOrUpdateFn_537610((int)v2);
			*((uint32_t*)v2 + 4) &= 0xF7FFFFFF;
		}
		if (*(uint32_t*)(a2 + 16) & 0x8000000) {
			nox_xxx_unitHasCollideOrUpdateFn_537610(a2);
			*(uint32_t*)(a2 + 16) &= 0xF7FFFFFF;
		}
	}
}

//----- (00551250) --------------------------------------------------------
void sub_551250(unsigned int a1, float* a2, int a3) {
	unsigned int v3; // edi
	float* v4;       // esi
	int v5;          // ebp
	double v6;       // st7
	double v7;       // st6
	double v8;       // st6
	int v9;          // ebx
	double v10;      // st7
	double v11;      // st6
	long double v12; // st6
	long double v13; // st7
	double v14;      // st6
	long double v15; // st7
	double v16;      // st7
	float v17;       // et1
	long double v18; // st7
	float v19;       // et1
	long double v20; // st7
	int v21;         // eax
	int v22;         // eax
	float* v23;      // eax
	int v24;         // ebx
	double v25;      // st7
	double v26;      // st7
	float v27;       // [esp+0h] [ebp-78h]
	float v28;       // [esp+4h] [ebp-74h]
	float2 v29;      // [esp+18h] [ebp-60h]
	float v30;       // [esp+20h] [ebp-58h]
	float v31;       // [esp+24h] [ebp-54h]
	float2 a4;       // [esp+28h] [ebp-50h]
	float2 v33;      // [esp+30h] [ebp-48h]
	float4 a2a;      // [esp+38h] [ebp-40h]
	float4 a3a;      // [esp+48h] [ebp-30h]
	float4 a1a;      // [esp+58h] [ebp-20h]
	float4 v37;      // [esp+68h] [ebp-10h]
	float v38;       // [esp+7Ch] [ebp+4h]
	float v39;       // [esp+7Ch] [ebp+4h]
	float v40;       // [esp+7Ch] [ebp+4h]
	float v41;       // [esp+80h] [ebp+8h]

	v3 = a1;
	v4 = a2;
	v5 = *(uint32_t*)(a1 + 748);
	v6 = (*(float*)(a1 + 68) + *(float*)(a1 + 64)) * 0.70710677;
	v29.field_4 = (*(float*)(a1 + 68) - *(float*)(a1 + 64)) * 0.70710677;
	v7 = a2[17] + a2[16];
	a1a.field_4 = v29.field_4;
	v30 = v7 * 0.70710677;
	v31 = (a2[17] - a2[16]) * 0.70710677;
	v8 = a2[46] * 0.5;
	a3a.field_0 = v30 - v8;
	v38 = a2[47] * 0.5;
	a3a.field_4 = v31 - v38;
	a3a.field_8 = v8 + v30;
	a3a.field_C = v38 + v31;
	a1a.field_0 = v6;
	v9 = *(short*)(v5 + 40) + 128;
	if (v9 >= 256) {
		v9 = *(short*)(v5 + 40) - 128;
	}
	a1a.field_8 = *getMemFloatPtr(0x587000, 194136 + 8 * v9) * 32.0 + v6;
	a1a.field_C = *getMemFloatPtr(0x587000, 194140 + 8 * v9) * 32.0 + v29.field_4;
	if (v6 >= a1a.field_8) {
		a2a.field_8 = v6;
		a2a.field_0 = a1a.field_8;
	} else {
		a2a.field_0 = v6;
		a2a.field_8 = a1a.field_8;
	}
	if (v29.field_4 >= (double)a1a.field_C) {
		a2a.field_4 = a1a.field_C;
		a2a.field_C = v29.field_4;
	} else {
		a2a.field_C = a1a.field_C;
		a2a.field_4 = v29.field_4;
	}
	if (a2a.field_0 <= (double)a3a.field_8 && a2a.field_4 <= (double)a3a.field_C &&
		a2a.field_8 >= (double)a3a.field_0 && a2a.field_C >= (double)a3a.field_4) {
		if (sub_551960(&a1a, &a2a, &a3a, &a4)) {
			v10 = v30 - a4.field_0;
			v11 = v31 - a4.field_4;
			v29.field_4 = v11;
			v12 = sqrt(v11 * v29.field_4 + v10 * v10);
			v39 = v12;
			if (v12 != 0.0) {
				v37.field_0 = v30;
				v37.field_4 = v31;
				*(float2*)&v37.field_8 = a4;
				v29.field_0 = v10 / v39;
				v29.field_4 = v29.field_4 / v39;
				if (sub_5516A0(&v37, &a3a, &v33, 1, 1) == 1) {
					v13 = sqrt((v33.field_4 - v31) * (v33.field_4 - v31) + (v33.field_0 - v30) * (v33.field_0 - v30));
					if (v13 != 0.0) {
						v14 = (v29.field_0 - v29.field_4) * 0.70710677;
						v29.field_4 = (v29.field_4 + v29.field_0) * 0.70710677;
						v29.field_0 = v14;
						v15 = v13 - v39;
						v40 = v15;
						if (v15 > 0.0) {
							nox_xxx_collSysAddCollision_548630((int)a2, v3, &v29);
							*(uint32_t*)(v5 + 44) = nox_frame_xxx_2598000;
							if (a3 == 1) {
								v41 = -(v29.field_4 * a2[21]) - v29.field_0 * a2[20];
								v16 = nox_xxx_objectGetMass_4E4A70((int)v4);
								v17 = *(float*)&dword_587000_292492;
								v18 = sqrt(v16 * v17 * 4.0);
								v19 = *(float*)&dword_587000_292492;
								v20 = v18 * v41 * 0.25 + v40 * v19;
								v28 = v20 * v29.field_4;
								v27 = v20 * v29.field_0;
								sub_548600((int)v4, v27, v28);
							}
							v21 = *((uint32_t*)v4 + 4);
							if (v21 & 0x8000000) {
								if (!(v21 & 8)) {
									nox_xxx_unitHasCollideOrUpdateFn_537610((int)v4);
								}
								*((uint32_t*)v4 + 4) &= 0xF7FFFFFF;
							}
							nox_xxx_unitHasCollideOrUpdateFn_537610(v3);
							if (!nox_xxx_servObjectHasTeam_419130(v3 + 48) ||
								*(uint32_t*)(v5 + 12) != *(uint32_t*)(v5 + 4) ||
								nox_xxx_servCompareTeams_419150(v3 + 48, (int)(v4 + 12))) {
								if (!a3 && !*(uint8_t*)(v5 + 1)) {
									v23 = *(float**)(v3 + 508);
									if (!v23 || v23 == v4) {
										v24 = v9 + 32;
										if (v24 >= 256) {
											v24 -= 256;
										}
										v25 = v40 * v4[30];
										if ((double)*getMemIntPtr(0x587000, 192088 + 8 * v24) *
													(v4[17] - *(float*)(v3 + 68)) -
												(double)*getMemIntPtr(0x587000, 192092 + 8 * v24) *
													(v4[16] - *(float*)(v3 + 64)) <=
											0.0) {
											v26 = v25 + *(float*)(v5 + 32);
										} else {
											v26 = *(float*)(v5 + 32) - v25;
										}
										*(float*)(v5 + 32) = v26;
										sub_548830(v5);
										nox_xxx_unitAddToUpdatable_4DA8D0(v3);
									}
								}
							} else if (nox_frame_xxx_2598000 > *(uint32_t*)(v3 + 136)) {
								v22 = *(unsigned char*)(v3 + 52);
								*(uint32_t*)(v3 + 136) = nox_frame_xxx_2598000 + nox_gameFPS;
								nox_xxx_clientGetTeamColor_418AB0(v22);
								nox_xxx_netPriMsgToPlayer_4DA2C0((int)v4, "objcoll.c:GateLockedMechanism", 0);
							}
						}
					}
				}
			}
		}
	}
}

//----- (005516A0) --------------------------------------------------------
int sub_5516A0(float4* a1, float4* a2, float2* a3, int a4, int a6) {
	int v5;     // ecx
	int v6;     // eax
	float2* v7; // edi
	int v9;     // [esp+10h] [ebp-8h]
	int v10;    // [esp+14h] [ebp-4h]

	v5 = 0;
	v6 = 0;
	v9 = 0;
	v10 = 0;
	if (a4 > 0) {
		v7 = a3;
		do {
			if (v10 >= 4) {
				break;
			}
			switch (v10) {
			case 0:
				v6 = sub_551780(a1, a2->field_0, a2->field_8, a2->field_4, v7, a6);
				break;
			case 1:
				v6 = sub_551870(a1, a2->field_8, a2->field_4, a2->field_C, v7, a6);
				break;
			case 2:
				v6 = sub_551780(a1, a2->field_0, a2->field_8, a2->field_C, v7, a6);
				break;
			case 3:
				v6 = sub_551870(a1, a2->field_0, a2->field_4, a2->field_C, v7, a6);
				break;
			default:
				break;
			}
			v5 = v9;
			if (v6) {
				v5 = v9 + 1;
				++v7;
				++v9;
			}
			++v10;
		} while (v5 < a4);
	}
	return v5;
}

//----- (00551780) --------------------------------------------------------
int sub_551780(float4* a1, float a2, float a3, float a4, float2* a5, int a6) {
	float4* v6; // ecx
	double v7;  // st7
	double v8;  // st7
	float v10;  // [esp+4h] [ebp+4h]
	float v11;  // [esp+4h] [ebp+4h]

	v6 = a1;
	v7 = a1->field_4 - a1->field_C;
	if (v7 == 0.0) {
		return 0;
	}
	v10 = (a4 - a1->field_C) / v7;
	if (v10 < 0.0 && !a6) {
		return 0;
	}
	if (v10 > 1.0) {
		return 0;
	}
	v8 = a2 - a3;
	if (v8 == 0.0) {
		return 0;
	}
	v11 = ((1.0 - v10) * v6->field_8 + v10 * v6->field_0 - a3) / v8;
	if (v11 < 0.0 || v11 > 1.0) {
		return 0;
	}
	a5->field_4 = a4;
	a5->field_0 = (1.0 - v11) * a3 + v11 * a2;
	return 1;
}

//----- (00551870) --------------------------------------------------------
int sub_551870(float4* a1, float a2, float a3, float a4, float2* a5, int a6) {
	float4* v6; // ecx
	double v7;  // st7
	double v8;  // st7
	float v10;  // [esp+4h] [ebp+4h]
	float v11;  // [esp+4h] [ebp+4h]

	v6 = a1;
	v7 = a1->field_0 - a1->field_8;
	if (v7 == 0.0) {
		return 0;
	}
	v10 = (a2 - a1->field_8) / v7;
	if (v10 < 0.0 && !a6) {
		return 0;
	}
	if (v10 > 1.0) {
		return 0;
	}
	v8 = a3 - a4;
	if (v8 == 0.0) {
		return 0;
	}
	v11 = ((1.0 - v10) * v6->field_C + v10 * v6->field_4 - a4) / v8;
	if (v11 < 0.0 || v11 > 1.0) {
		return 0;
	}
	a5->field_0 = a2;
	a5->field_4 = (1.0 - v11) * a4 + v11 * a3;
	return 1;
}

//----- (00551960) --------------------------------------------------------
int sub_551960(float4* a1, float4* a2, float4* a3, float2* a4) {
	int result;    // eax
	int v5;        // eax
	int v6;        // eax
	double v7;     // st7
	float2* v8;    // eax
	double v9;     // st7
	float2 a3a[2]; // [esp+8h] [ebp-10h]

	if (a2->field_0 < (double)a3->field_0 || a2->field_8 > (double)a3->field_8 || a2->field_4 < (double)a3->field_4 ||
		a2->field_C > (double)a3->field_C) {
		v5 = sub_5516A0(a1, a3, a3a, 2, 0) - 1;
		if (v5) {
			if (v5 == 1) {
				a4->field_0 = (a3a[1].field_0 + a3a[0].field_0) * 0.5;
				a4->field_4 = (a3a[1].field_4 + a3a[0].field_4) * 0.5;
				result = 1;
			} else {
				result = 0;
			}
		} else {
			v6 = sub_551A90((float2*)a1, a3);
			v7 = a3a[0].field_0;
			if (v6) {
				v8 = a4;
				a4->field_0 = (v7 + a1->field_0) * 0.5;
				v9 = a3a[0].field_4 + a1->field_4;
			} else {
				v8 = a4;
				a4->field_0 = (v7 + a1->field_8) * 0.5;
				v9 = a3a[0].field_4 + a1->field_C;
			}
			v8->field_4 = v9 * 0.5;
			result = 1;
		}
	} else {
		a4->field_0 = (a1->field_8 + a1->field_0) * 0.5;
		result = 1;
		a4->field_4 = (a1->field_C + a1->field_4) * 0.5;
	}
	return result;
}

//----- (00551A90) --------------------------------------------------------
int sub_551A90(float2* a1, float4* a2) {
	return a1->field_0 >= (double)a2->field_0 && a1->field_0 <= (double)a2->field_8 &&
		   a1->field_4 >= (double)a2->field_4 && a1->field_4 <= (double)a2->field_C;
}

//----- (00551AE0) --------------------------------------------------------
void sub_551AE0(int a1, int a2, int a3) {
	int v3;   // edi
	int v4;   // eax
	float v5; // [esp+0h] [ebp-10h]
	float v6; // [esp+0h] [ebp-10h]

	v3 = *(uint32_t*)(a1 + 748);
	if (!*getMemU32Ptr(0x5D4594, 2491808)) {
		sub_551BF0();
	}
	if (a3) {
		v4 = *(unsigned short*)(a2 + 4);
		if ((unsigned short)v4 != *getMemU32Ptr(0x5D4594, 2491792) && v4 != *getMemU32Ptr(0x5D4594, 2491796) &&
			v4 != *getMemU32Ptr(0x5D4594, 2491800) && v4 != *getMemU32Ptr(0x5D4594, 2491804)) {
			v5 = *(float*)(a2 + 104) - (double)*(int*)(v3 + 16);
			if (sub_419A10(v5) > 10.0) {
				if ((double)*(int*)(v3 + 16) > *(float*)(a2 + 104)) {
					if (*(uint32_t*)(a2 + 172) == 2) {
						sub_54AD50(a2, a1, 0);
					} else if (*(uint32_t*)(a2 + 172) == 3) {
						sub_550F80((float*)a2, a1);
					}
				}
			} else if (nox_xxx_map_57B850((float2*)(a1 + 64), (float*)(a1 + 172), (float2*)(a2 + 64))) {
				*(uint32_t*)(a2 + 16) = *(uint32_t*)(a2 + 16) & 0xFFFBFFFF | 0x100000;
				v6 = (double)*(int*)(v3 + 16) + 4.0;
				nox_xxx_unitRaise_4E46F0(a2, v6);
				*(uint32_t*)(a2 + 108) = 0;
			}
		}
	}
}

//----- (00551BF0) --------------------------------------------------------
void sub_551BF0() {
	*getMemU32Ptr(0x5D4594, 2491792) = nox_xxx_getNameId_4E3AA0("SmallFist");
	*getMemU32Ptr(0x5D4594, 2491796) = nox_xxx_getNameId_4E3AA0("MediumFist");
	*getMemU32Ptr(0x5D4594, 2491800) = nox_xxx_getNameId_4E3AA0("LargeFist");
	*getMemU32Ptr(0x5D4594, 2491804) = nox_xxx_getNameId_4E3AA0("Meteor");
	*getMemU32Ptr(0x5D4594, 2491808) = 1;
}

//----- (00551C40) --------------------------------------------------------
void sub_551C40(int a1, int a2) {
	int v2;       // edi
	int v3;       // ebp
	int v4;       // eax
	int v5;       // eax
	double v6;    // st7
	uint32_t* v7; // ebx
	float v8;     // [esp+0h] [ebp-14h]
	float v9;     // [esp+0h] [ebp-14h]
	float v10;    // [esp+18h] [ebp+4h]

	v2 = a1;
	v3 = *(uint32_t*)(a1 + 748);
	if (!*getMemU32Ptr(0x5D4594, 2491808)) {
		sub_551BF0();
	}
	if (*(uint32_t*)(v3 + 4)) {
		v4 = *(unsigned short*)(a2 + 4);
		if ((unsigned short)v4 != *getMemU32Ptr(0x5D4594, 2491792) && v4 != *getMemU32Ptr(0x5D4594, 2491796) &&
			v4 != *getMemU32Ptr(0x5D4594, 2491800) && v4 != *getMemU32Ptr(0x5D4594, 2491804)) {
			v5 = *(uint32_t*)(a2 + 172);
			if (v5 == 3) {
				if (*(float*)(a1 + 184) < (double)*(float*)(a2 + 184) ||
					*(float*)(a1 + 188) < (double)*(float*)(a2 + 188)) {
					return;
				}
			} else if (v5 == 2) {
				v6 = *(float*)(a2 + 176) + *(float*)(a2 + 176);
				if (v6 > *(float*)(a1 + 184) || v6 > *(float*)(a1 + 188)) {
					return;
				}
			}
			v7 = (uint32_t*)(a1 + 64);
			if (nox_xxx_map_57B850((float2*)(a1 + 64), (float*)(a1 + 172), (float2*)(a2 + 64))) {
				v10 = (double)(int)(*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(v3 + 4) + 748) + 16) - 64);
				v8 = *(float*)(a2 + 104) - v10;
				if (sub_419A10(v8) > 10.0) {
					if (v10 <= -10.0) {
						*(uint32_t*)(a2 + 16) |= 0x40000u;
						*(uint32_t*)(a2 + 156) = *v7;
						*(uint32_t*)(a2 + 160) = *(uint32_t*)(v2 + 68);
						*(uint32_t*)(a2 + 164) = *(uint32_t*)(*(uint32_t*)(v3 + 4) + 64);
						*(uint32_t*)(a2 + 168) = *(uint32_t*)(*(uint32_t*)(v3 + 4) + 68);
					}
				} else {
					v9 = v10 + 4.0;
					*(uint32_t*)(a2 + 16) = *(uint32_t*)(a2 + 16) & 0xFFFBFFFF | 0x100000;
					nox_xxx_unitRaise_4E46F0(a2, v9);
					*(uint32_t*)(a2 + 108) = 0;
				}
			}
		}
	}
}

//----- (00551E60) --------------------------------------------------------
nox_net_struct_t* nox_xxx_netStructByAddr_551E60(struct nox_net_sockaddr_in* addr) {
	for (int i = 0; i < NOX_NET_STRUCT_MAX; i++) {
		nox_net_struct_t* ns = nox_net_struct_arr[i];
		if (!ns) {
			continue;
		}
		if (addr->sin_port == ns->addr.sin_port && addr->sin_addr == ns->addr.sin_addr) {
			return ns;
		}
	}
	return 0;
}

//----- (00551EB0) --------------------------------------------------------
int nox_xxx_netRead2Xxx_551EB0(unsigned int id1, unsigned int id2, unsigned char a3, int a4, int a5) {
	nox_net_struct_t* ns2 = nox_net_struct_arr[id2];
	// fprintf(stderr, "551EB0: %d %d %d %d %d %d %d %d %d\n", ns2, ns2->field_38, ns2->data_39[0], id1,
	// a3, *(uint8_t *)(a4 + 4), a5,  nox_net_struct_arr[id1]->field_21, nox_xxx_servGetPlrLimit_409FA0());
	if (!ns2 || ns2->field_38 != 1 || ns2->data_39[0] > a3) {
		return 0;
	}
	nox_net_struct_t* ns1 = nox_net_struct_arr[id1];
	if (ns1->field_21 > (unsigned int)(nox_xxx_servGetPlrLimit_409FA0() - 1)) {
		nox_xxx_netStructReadPackets_5545B0(id2);
		return 1;
	}
	if (a5 > 3 && *(uint8_t*)(a4 + 4) == 32) {
		ns2->field_38 = 2;
		ns2->data_39[0] = -1;
		ns2->field_40 = 0;
		ns1->func_yyy(id2, a4 + 4, a5 - 4, ns2->data_3);
	}
	return 1;
}

//----- (00551F90) --------------------------------------------------------
int nox_xxx_sendto_551F90(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr_in* to) {
	nox_net_struct_t* ns = nox_xxx_netStructByAddr_551E60(to);
	if (!ns) {
		return nox_net_sendto(s, buf, len, to);
	}
	if (!ns->xor_key) {
		return nox_net_sendto(s, buf, len, to);
	}
	nox_xxx_cryptXorDst_56FE00(ns->xor_key, buf, len, getMemAt(0x5D4594, 2491812));
	return nox_net_sendto(s, (const char*)getMemAt(0x5D4594, 2491812), len, to);
}

//----- (00552010) --------------------------------------------------------
int nox_net_setPacketDrop_552010(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 2495940) = a1;
	return result;
}

//----- (005520B0) --------------------------------------------------------
int nox_xxx_allocNetGQueue_5520B0(int a1, int a2) {
	int* v3; // esi
	int* v4; // edi

	sub_43DE40((int)sub_5521A0);
	if (*getMemU32Ptr(0x5D4594, 2495924)) {
		return -14;
	}
	nox_alloc_gQueue_3844300 = 0;
	memset(nox_net_struct_arr, 0, sizeof(nox_net_struct_t*) * NOX_NET_STRUCT_MAX);
	memset(nox_net_struct2_arr, 0, sizeof(nox_net_struct2_t) * NOX_NET_STRUCT_MAX);
	*getMemU32Ptr(0x5D4594, 2512884) = a2;
	nox_alloc_gQueue_3844300 = nox_new_alloc_class("GQueue", a2, a1);
	if (!nox_alloc_gQueue_3844300) {
		return -1;
	}
	if (*getMemU32Ptr(0x5D4594, 2495924)) {
		v3 = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 2495908));
		if (v3) {
			do {
				v4 = nox_common_list_getNextSafe_4258A0(v3);
				sub_425920((uint32_t**)v3);
				free(v3);
				--*getMemU8Ptr(0x5D4594, 2500076);
				v3 = v4;
			} while (v4);
		}
	} else {
		nox_common_list_clear_425760(getMemAt(0x5D4594, 2495908));
	}
	*getMemU32Ptr(0x5D4594, 2495944) = 0;
	*getMemU32Ptr(0x5D4594, 2495948) = 0;
	*getMemU32Ptr(0x5D4594, 2495952) = 0;
	*getMemU32Ptr(0x5D4594, 2495956) = 0;
	*getMemU32Ptr(0x5D4594, 2495924) = 1;
	return 0;
}

//----- (005521A0) --------------------------------------------------------
int sub_5521A0() {
	int v2;           // eax
	int v3;           // ecx
	unsigned char v4; // bl
	char* v13;        // [esp+18h] [ebp-4h]

	v13 = sub_416640();
	uint32_t start = nox_platform_get_ticks();
	for (int i = 0; i < NOX_NET_STRUCT_MAX; i++) {
		nox_net_struct2_t* nx = &nox_net_struct2_arr[i];
		if (!nx->field_0) {
			continue;
		}
		v2 = nx->field_1_1;
		if (v2 >= 10) {
			if ((int)nx->field_1_0 > *getMemIntPtr(0x587000, 292940)) {
				goto LABEL_24;
			}
			int cnt = 0;
			int sum = 0;
			for (int i = 0; i < 10; i++) {
				if (nx->field_6[i] > 0) {
					cnt++;
					sum += nx->field_6[i];
				}
			}
			int avg = sum / cnt;
			if (*(short*)(v13 + 105) != -1 && avg < *(unsigned short*)(v13 + 105)) {
				sub_5523E0(0, i);
			}
			if (*(short*)(v13 + 107) != -1 && avg > *(unsigned short*)(v13 + 107)) {
			LABEL_24:
				sub_5523E0(1, i);
			}
			sub_552380(i);
		} else if ((int)(start - nx->ticks) > 2000) {
			v3 = *getMemU32Ptr(0x587000, 292940);
			nox_net_struct2_arr[i].field_6[v2] = -1;
			v4 = nx->field_1_0 + 1;
			nx->field_1_0 = v4;
			if (v4 <= v3) {
				nx->field_1_1++;
				sub_5522E0(i);
			} else {
				sub_5523E0(1, i);
			}
		}
	}
	return 1;
}

//----- (005522E0) --------------------------------------------------------
void sub_5522E0(int id) {
	int i = sub_4DF550();
	nox_net_struct_t* ns = nox_net_struct_arr[i];
	char buf[8];
	int v2 = nox_xxx_makePacketTime_552340(id, buf);
	int v3 = nox_xxx_sendto_551F90(ns->sock, buf, v2, &nox_net_struct2_arr[id].addr);
	sub_553F40(v3, 1);
}

//----- (00552340) --------------------------------------------------------
int nox_xxx_makePacketTime_552340(int id, unsigned char* buf) {
	nox_net_struct2_t* nx = &nox_net_struct2_arr[id];
	nx->ticks = nox_platform_get_ticks();
	buf[2] = 16;
	buf[3] = nx->field_1_1;
	*(unsigned int*)(&buf[4]) = nx->ticks;
	return 8;
}

//----- (00552380) --------------------------------------------------------
void sub_552380(int a1) {
	int i = sub_4DF550();
	nox_net_struct_t* ns = nox_net_struct_arr[i];
	char buf[4];
	buf[0] = 0;
	buf[1] = 0;
	buf[2] = 20;
	int v3 = nox_xxx_sendto_551F90(ns->sock, (char*)&buf, 3, &nox_net_struct2_arr[a1].addr);
	sub_553F40(v3, 1);
	nox_net_struct2_arr[a1].field_0 = 0;
}

//----- (005523E0) --------------------------------------------------------
void sub_5523E0(char a1, int a2) {
	int i = sub_4DF550();
	nox_net_struct_t* ns = nox_net_struct_arr[i];
	char buf[4];
	buf[0] = 0;
	buf[1] = 0;
	buf[2] = 19;
	buf[3] = a1;
	int v4 = nox_xxx_sendto_551F90(ns->sock, (char*)&buf, 4, &nox_net_struct2_arr[a2].addr);
	sub_553F40(v4, 1);
	nox_net_struct2_arr[a2].field_0 = 0;
}

//----- (00552460) --------------------------------------------------------
void nox_xxx_netMaybeSendAll_552460() {
	dword_5d4594_2495920 = nox_platform_get_ticks();
	if (dword_5d4594_2495920 - *getMemU32Ptr(0x5D4594, 2512888) <= 1000) {
		return;
	}
	for (int i = 0; i < NOX_NET_STRUCT_MAX; i++) {
		if (nox_net_struct_arr[i]) {
			sub_5551F0(i, 0, 0);
			nox_xxx_netSend_5552D0(i, 0, 0);
		}
	}
	*getMemU32Ptr(0x5D4594, 2512888) = dword_5d4594_2495920;
}

//----- (00552640) --------------------------------------------------------
int nox_xxx_netSendSock_552640(unsigned int id, const char* buf, signed int sz, char flags) {
	unsigned int v7;  // edi
	unsigned int v8;  // eax
	unsigned int v10; // ebx
	int v12;          // eax
	uint32_t v14;     // eax
	int v16;          // edi
	unsigned int v18; // [esp+10h] [ebp-8h]
	unsigned int v20; // [esp+1Ch] [ebp+4h]

	if (id >= NOX_NET_STRUCT_MAX) {
		return -3;
	}
	nox_net_struct_t* ns = nox_net_struct_arr[id];
	if (!ns) {
		return -3;
	}
	if (!buf) {
		return -2;
	}
	if (ns->id == -1) {
		v7 = NOX_NET_STRUCT_MAX;
		v8 = 0;
		v20 = NOX_NET_STRUCT_MAX;
		v18 = id;
	} else {
		v8 = id;
		v20 = id + 1;
		v7 = v20;
		v18 = ns->id;
	}
	if (flags & 1) {
		v10 = (unsigned int)buf; // TODO: this doesn't make sense!
		for (int i = v8; i < v7; i++) {
			nox_net_struct_t* ns2 = nox_net_struct_arr[i];
			if (ns2 && ns2->id == v18) {
				v12 = sub_555130(i, buf, sz);
				v10 = v12;
				if (v12 == -1) {
					return -1;
				}
				if (flags & 2) {
					nox_xxx_netSend_5552D0(i, v12, 1);
				}
			}
		}
		return v10;
	}
	v10 = sz;
	for (int i = v8; i < v7; i++) {
		nox_net_struct_t* ns2 = nox_net_struct_arr[i];
		if (!ns2) {
			continue;
		}
		if (ns2->id != v18) {
			continue;
		}
		if (v10 + 1 > (int)(ns2->data_2_end) - (int)(ns2->data_2_xxx)) {
			return -7;
		}
		v14 = WaitForSingleObject(ns2->mutex_yyy, 0x3E8u);
		if (v14 == -1 || v14 == 258) {
			return -16;
		}
		if (flags & 2) {
			ns2->data_2_xxx[0] = ns2->data_2_base[0];
			ns2->data_2_xxx[1] = ns2->data_2_base[1];
			memcpy(&ns2->data_2_xxx[2], buf, v10);
			v16 = nox_xxx_sendto_551F90(ns2->sock, ns2->data_2_xxx, v10 + 2, &ns2->addr);
			if (v16 == -1) {
				return -1;
			}
			sub_553F40(v10 + 2, 1);
			nox_xxx_netCountData_554030(v10 + 2, i);
			ReleaseMutex(ns2->mutex_yyy);
			return v16;
		}
		memcpy(ns2->data_2_xxx, buf, v10);
		ns2->data_2_xxx = &ns2->data_2_xxx[v10];
		if (!ReleaseMutex(ns2->mutex_yyy)) {
			ReleaseMutex(ns2->mutex_yyy);
		}
		v7 = v20;
	}
	return v10;
}
