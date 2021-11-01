#include "GAME1_2.h"
#include "GAME2_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "common__strman.h"
extern uint32_t dword_5d4594_2487580;
extern uint32_t dword_5d4594_2487672;
extern uint32_t dword_5d4594_2487576;
extern uint32_t dword_5d4594_1550916;

//----- (004D42C0) --------------------------------------------------------
int sub_4D42C0() { return dword_5d4594_1550916; }

//----- (00522AD0) --------------------------------------------------------
float* nox_xxx_mapgen_522AD0(float* a1, int a2) {
	int v2;        // eax
	double v4;     // st7
	double v5;     // st7
	float* v6;     // ebx
	double v7;     // st7
	float a3;      // [esp+0h] [ebp-34h]
	float a4;      // [esp+4h] [ebp-30h]
	int2 a2a;      // [esp+14h] [ebp-20h]
	float2 a1a;    // [esp+1Ch] [ebp-18h]
	float v13 = 0; // [esp+24h] [ebp-10h]
	float v14 = 0; // [esp+28h] [ebp-Ch]
	float2 v15;    // [esp+2Ch] [ebp-8h]

	v2 = *(uint32_t*)(a2 + 60);
	if (*((uint8_t*)a1 + v2 + 216)) {
		return 0;
	}
	switch (v2) {
	case 0:
		a1a.field_0 = a1[7] * 0.5 + a1[9] + 1.0;
		v4 = a1[10] + 10.0;
		a1a.field_4 = v4;
		break;
	case 1:
		a1a.field_0 = a1[7] * 0.5 + a1[9] + 1.0;
		v4 = a1[12] - 10.0;
		a1a.field_4 = v4;
		break;
	case 2:
		v5 = a1[11] - 10.0;
		a1a.field_0 = v5;
		v4 = a1[8] * 0.5 + a1[10] + 1.0;
		a1a.field_4 = v4;
		break;
	case 3:
		v5 = a1[9] + 10.0;
		a1a.field_0 = v5;
		v4 = a1[8] * 0.5 + a1[10] + 1.0;
		a1a.field_4 = v4;
		break;
	default:
		break;
	}
	nox_xxx_mapGenGetObjID_527940((char*)a2);
	v6 = nox_xxx_mapGenPlaceObj_5279B0(&a1a);
	if (v6) {
		nox_xxx_mapGenRoundFloatToPtr_520DF0(&a1a, &a2a);
		switch (*(uint32_t*)(a2 + 60)) {
		case 0:
			v13 = 3.0;
			v7 = 2.0;
			--a2a.field_0;
			break;
		case 1:
			v7 = 2.0;
			--a2a.field_0;
			a2a.field_4 -= 2;
			v13 = 3.0;
			break;
		case 2:
			a2a.field_0 -= 2;
			v13 = 2.0;
			v7 = 3.0;
			--a2a.field_4;
			break;
		case 3:
			v13 = 2.0;
			v7 = 3.0;
			--a2a.field_4;
			break;
		default:
			v7 = v14;
			break;
		}
		v15.field_0 = (double)a2a.field_0 * 32.526913;
		v15.field_4 = (double)a2a.field_4 * 32.526913;
		a4 = v7 * 32.526913;
		a3 = v13 * 32.526913;
		sub_521BC0((int)a1, &v15, a3, a4);
	}
	return v6;
}

//----- (005259E0) --------------------------------------------------------
int sub_5259E0() { return dword_5d4594_2487576; }

//----- (00527D50) --------------------------------------------------------
int sub_527D50(int a1, char* a2) {
	char* v3; // eax

	if (!a1) {
		return 0;
	}
	if (!a2) {
		return 0;
	}
	v3 = (char*)nox_xxx_getUnitName_4E39D0(a1);
	if (*(int (**)(int))(nox_xxx_objectTypeByID_4E3B60(v3) + 212) != nox_xxx_XFerExit_4F4B90) {
		return 0;
	}
	strncpy(*(char**)(a1 + 700), a2, 0x50u);
	return 1;
}

//----- (00522A40) --------------------------------------------------------
int nox_xxx_mapGenMakeExit_522A40(int a1) {
	if (!*(uint32_t*)(a1 + 472)) {
		return 1;
	}
	for (int v2 = sub_5259E0(); v2; v2 = *(uint32_t*)(v2 + 68)) {
		if (*(uint32_t*)v2 != 1) {
			continue;
		}
		int v3 = 0;
		int v4 = a1 + 216;
		while (v3 < *(int*)(a1 + 472)) {
			float* v5 = nox_xxx_mapgen_522AD0((float*)v2, v4);
			if (v5) {
				sub_527D50((int)v5, (char*)(a1 + 476));
				return 1;
			}
			++v3;
			v4 += 64;
		}
	}
	return 0;
}

//----- (005259D0) --------------------------------------------------------
double sub_5259D0() { return *(float*)&dword_5d4594_2487580; }

//----- (00526A90) --------------------------------------------------------
void sub_526A90() { free(*(void**)&dword_5d4594_2487672); }

//----- (005228B0) --------------------------------------------------------
void nox_xxx_mapGenFinishPopulate_5228B0_mapgen_populate(int a1) {
	wchar_t* v1; // eax
	wchar_t* v2; // eax
	wchar_t* v3; // eax
	int i;       // ebp
	int j;       // esi
	float* v6;   // eax
	float v8;    // [esp+8h] [ebp-8h]
	float v9;    // [esp+Ch] [ebp-4h]

	nox_xxx_mapGenSetFlags_5235F0(157);
	if (!nox_xxx_mapGenMakeExit_522A40(a1)) {
		v1 = nox_strman_loadString_40F1D0("NoExit", 0, "C:\\NoxPost\\src\\Server\\MapGen\\Generate\\populate.c", 848);
		nox_xxx_printToAll_4D9FD0(0, v1);
		v2 = nox_strman_loadString_40F1D0("NoExit", 0, "C:\\NoxPost\\src\\Server\\MapGen\\Generate\\populate.c", 849);
		nox_xxx_printToAll_4D9FD0(0, v2);
		v3 = nox_strman_loadString_40F1D0("NoExit", 0, "C:\\NoxPost\\src\\Server\\MapGen\\Generate\\populate.c", 850);
		nox_xxx_printToAll_4D9FD0(0, v3);
	}
	sub_5259D0();
	for (i = sub_4D42C0(); i; i = *(uint32_t*)(i + 64)) {
		nox_xxx_mapGenSetFlags_5235F0(157);
		if (*(uint32_t*)(i + 372) && !(*(uint8_t*)(i + 52) & 2)) {
			nox_xxx_mapgen_522340(a1, i);
		}
		if (*(uint32_t*)(a1 + 60)) {
			for (j = *(uint32_t*)(i + 368); j; j = *(uint32_t*)(j + 24)) {
				if (*(uint32_t*)j) {
					nox_xxx_tileGetDefByName_51D4D0("CrystalBlue");
				} else {
					nox_xxx_tileGetDefByName_51D4D0("CrystalRed");
				}
				sub_5245A0(a1, (float*)(j + 4), (long long)((*(float*)(j + 12) - *(float*)(j + 4) + 0.5) * 0.030743772),
						   (long long)((*(float*)(j + 16) - *(float*)(j + 8) + 0.5) * 0.030743772));
			}
		}
	}
	v6 = (float*)sub_4D42C0();
	v8 = (v6[11] + v6[9]) * 0.5;
	v9 = (v6[12] + v6[10]) * 0.5;
	nox_xxx_mapGenGetObjID_527940("PlayerStart");
	nox_xxx_mapGenPlaceObj_5279B0(&v8);
	sub_469B90((int*)(a1 + 536));
	sub_526A90();
}
