#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "client/system/parsecmd.h"
#include "common/system/team.h"
#include "server/mapgen/generate/populate.h"
#include "server/network/playback.h"
#include "server/network/sdecode.h"
#include "server/system/server.h"
#include "server/xfer/savegame/savegame.h"

#include "client/gui/chathelp.h"
#include "client/gui/conntype.h"
#include "client/gui/servopts/guiserv.h"

#include "client/drawable/update/cloud.h"
#include "client/drawable/update/dball.h"

#include "proto.h"

extern _DWORD dword_587000_108752;
extern _DWORD dword_5d4594_1548736;
extern _DWORD dword_5d4594_1563084;
extern _DWORD dword_5d4594_1563080;
extern _DWORD dword_5d4594_1556856;
extern _DWORD dword_5d4594_1548480;
extern _DWORD dword_5d4594_1563044;
extern _DWORD dword_5d4594_1548732;
extern _DWORD dword_5d4594_1548704;
extern _DWORD dword_5d4594_1523048;
extern _DWORD dword_5d4594_1563096;
extern _DWORD dword_5d4594_1523044;
extern _DWORD dword_5d4594_1523032;
extern _DWORD dword_5d4594_1563088;
extern _DWORD dword_5d4594_1556848;
extern _DWORD dword_587000_312796;
extern _DWORD dword_587000_54276;
extern _DWORD dword_5d4594_3835312;
extern _DWORD dword_5d4594_1563052;
extern _DWORD dword_587000_312812;
extern _DWORD dword_587000_312828;
extern _DWORD dword_5d4594_1556852;
extern _DWORD dword_587000_312824;
extern _DWORD dword_587000_312792;
extern _DWORD dword_5d4594_1556148;
extern _DWORD dword_5d4594_3835388;
extern _DWORD dword_587000_312808;
extern _DWORD dword_5d4594_1563092;
extern _DWORD dword_5d4594_3835348;
extern _DWORD dword_5d4594_1556112;
extern _DWORD dword_5d4594_3835352;
extern _DWORD dword_5d4594_1550912;
extern _DWORD dword_5d4594_1523036;
extern _DWORD dword_5d4594_1548700;
extern _DWORD dword_5d4594_3835356;
extern _DWORD dword_587000_312788;
extern _DWORD dword_5d4594_3596;
extern _DWORD dword_587000_312784;
extern _DWORD dword_587000_312800;
extern _DWORD dword_587000_312816;
extern _DWORD dword_587000_312804;
extern _DWORD dword_5d4594_1550916;
extern _DWORD dword_587000_312820;
extern _DWORD dword_5d4594_2649712;
extern _DWORD dword_5d4594_3843628;
extern _DWORD dword_5d4594_3835396;
extern _DWORD dword_5d4594_1523024;
extern _DWORD dword_5d4594_1556844;
extern _DWORD dword_5d4594_1556860;
extern _DWORD dword_5d4594_1523028;
extern _DWORD dword_587000_197428;
extern _DWORD dword_5d4594_1548476;
extern _DWORD dword_587000_197424;
extern _DWORD dword_5d4594_2650652;
extern int nox_win_width;
extern int nox_win_height;

extern obj_5D4594_2650668_t** ptr_5D4594_2650668;
extern int ptr_5D4594_2650668_cap;

// 4CD756: variable 'v5' is possibly undefined
// 4CD767: variable 'v7' is possibly undefined
// 4CD78B: variable 'v9' is possibly undefined
// 4CD79C: variable 'v11' is possibly undefined

//----- (004CDF80) --------------------------------------------------------
int __cdecl sub_4CDF80(int a1, int a2) {
	sub_4CDFA0(a2, (_DWORD*)3);
	return 1;
}

//----- (004CE0A0) --------------------------------------------------------
int __cdecl sub_4CE0A0(int a1, int a2) {
	sub_4CDFA0(a2, (_DWORD*)1);
	return 1;
}

//----- (004CE1D0) --------------------------------------------------------
int __cdecl sub_4CE1D0(int a1, int a2) {
	if (byte_5D4594[2598000] & 1)
		sub_4CE200(a1, a2, 1, 75);
	return 1;
}

//----- (004CE340) --------------------------------------------------------
int __cdecl sub_4CE340(int a1, int a2) {
	*(_WORD*)(a2 + 104) += *(unsigned __int8*)(a2 + 432);
	return 1;
}

//----- (004CE360) --------------------------------------------------------
int __cdecl sub_4CE360(int a1, int a2) {
	if (byte_5D4594[2598000] & 1)
		sub_4CE200(a1, a2, 1, 35);
	return 1;
}

//----- (004CE390) --------------------------------------------------------
int __cdecl sub_4CE390(_DWORD* a1, int a2) {
	int result; // eax
	int v3;     // edx
	int v4;     // ecx
	int v5;     // ecx
	int v6;     // edx

	if (*(_BYTE*)(a2 + 432) || *(_BYTE*)(a2 + 433) || *(_BYTE*)(a2 + 434)) {
		v3 = *(_DWORD*)(a2 + 12);
		v4 = a1[4];
		if (v3 >= v4 - 100 && v3 <= a1[8] + v4 + 100) {
			v5 = a1[5];
			v6 = *(_DWORD*)(a2 + 16);
			if (v6 >= v5 - 100 && v6 <= a1[9] + v5 + 100 && !nox_common_gameFlags_check_40A5C0(0x200000)) {
				sub_4CE440(a2);
				sub_4CE610(a2);
				sub_4CE760(a2);
				sub_4CE960(a2);
				sub_4CE8C0(a2);
			}
		}
		result = 1;
	} else {
		sub_49BCD0((_DWORD*)a2);
		result = 1;
	}
	return result;
}

//----- (004CE440) --------------------------------------------------------
void __cdecl sub_4CE440(int a1) {
	int v1;     // esi
	char v2;    // bl
	double v3;  // st7
	__int64 v4; // rax
	double v5;  // st7
	double v6;  // st7
	char v7;    // bl
	char v8;    // bl
	int v9;     // eax
	double v10; // st7
	int v11;    // ecx
	char v12;   // [esp+Fh] [ebp-15h]
	float v13;  // [esp+10h] [ebp-14h]
	int v14;    // [esp+18h] [ebp-Ch]
	char v15;   // [esp+28h] [ebp+4h]

	v1 = a1;
	v2 = *(_BYTE*)(a1 + 432);
	v12 = *(_BYTE*)(a1 + 432);
	if (v2 > 1 && *(_WORD*)(a1 + 258)) {
		v3 = (double)*(unsigned int*)&byte_5D4594[2598000] / (double)(*(unsigned __int16*)(a1 + 258) * v2);
		v4 = (__int64)v3;
		v5 = v3 - (double)(int)(__int64)v3;
		if (*(_BYTE*)(a1 + 176) & 1) {
			v6 = v5 * (double)v2;
			v15 = (__int64)v6;
			v7 = v15 + 1;
			if ((char)(v15 + 1) >= v12)
				v7 = 0;
		} else {
			v6 = v5 * (double)v2;
			if (v4 & 1) {
				v8 = v2 - (unsigned __int64)(__int64)v6 - 1;
				v15 = v8;
				v7 = v8 - 1;
				if (v7 < 0)
					v7 = 0;
			} else {
				v15 = (__int64)v6;
				v7 = v15 + 1;
				if ((char)(v15 + 1) >= v12)
					v7 = v12 - 1;
			}
		}
		v13 = (double)*(unsigned __int16*)(v1 + 258);
		v9 = v7;
		v10 = (double)(unsigned __int8)(__int64)((v6 - (double)(int)(__int64)v6) * v13);
		v11 = v1 + 2 * v15 + v15;
		v14 = *(unsigned __int8*)(v15 + v1 + 2 * v15 + 120 + 60);
		sub_484BE0(
		    (_DWORD*)(v1 + 136),
		    (__int64)((double)(*(unsigned __int8*)(v9 + v1 + 2 * v9 + 178) - *(unsigned __int8*)(v11 + 178)) /
				  v13 * v10 +
			      (double)*(unsigned __int8*)(v11 + 178)),
		    (__int64)((double)(*(unsigned __int8*)(v9 + v1 + 2 * v9 + 179) - *(unsigned __int8*)(v11 + 179)) /
				  v13 * v10 +
			      (double)*(unsigned __int8*)(v11 + 179)),
		    (__int64)((double)(*(unsigned __int8*)(v9 + v1 + 2 * v9 + 120 + 60) - v14) / v13 * v10 +
			      (double)v14));
	}
}

//----- (004CE610) --------------------------------------------------------
void __cdecl sub_4CE610(int a1) {
	int v1;     // esi
	double v2;  // st7
	__int64 v3; // rax
	double v4;  // st7
	double v5;  // st7
	__int64 v6; // rax
	char v7;    // bl
	float v8;   // [esp+0h] [ebp-20h]
	char v9;    // [esp+24h] [ebp+4h]
	float v10;  // [esp+24h] [ebp+4h]

	v1 = a1;
	v9 = *(_BYTE*)(a1 + 433);
	if (v9 > 1 && *(_WORD*)(v1 + 260)) {
		v2 = (double)*(unsigned int*)&byte_5D4594[2598000] / (double)(*(unsigned __int16*)(v1 + 260) * v9);
		v3 = (__int64)v2;
		v4 = v2 - (double)(int)(__int64)v2;
		if (*(_BYTE*)(v1 + 176) & 4) {
			v5 = v4 * (double)v9;
			v6 = (__int64)v5;
			v7 = (unsigned __int64)(__int64)v5 + 1;
			if (v7 >= v9)
				v7 = 0;
		} else {
			v5 = v4 * (double)v9;
			if (v3 & 1) {
				LOBYTE(v6) = v9 - (unsigned __int64)(__int64)v5 - 1;
				v7 = v9 - (unsigned __int64)(__int64)v5 - 2;
				if (v7 < 0)
					v7 = 0;
			} else {
				v6 = (__int64)v5;
				v7 = (unsigned __int64)(__int64)v5 + 1;
				if (v7 >= v9)
					v7 = v9 - 1;
			}
		}
		v10 = (double)*(unsigned __int16*)(v1 + 260);
		v8 = (double)(unsigned __int8)(__int64)((v5 - (double)(int)(__int64)v5) * v10) *
			 ((double)(*(unsigned __int8*)(v7 + v1 + 226) - *(unsigned __int8*)((char)v6 + v1 + 226)) /
			  v10) +
		     (double)*(unsigned __int8*)((char)v6 + v1 + 226);
		sub_484D70_light_intensity(v1 + 136, v8);
	}
}

//----- (004CE760) --------------------------------------------------------
int __cdecl sub_4CE760(int a1) {
	int v1;     // esi
	int result; // eax
	char v3;    // bl
	double v4;  // st7
	__int64 v5; // rax
	double v6;  // st7
	double v7;  // st7
	__int64 v8; // rax
	char v9;    // bl
	char v10;   // bl
	char v11;   // [esp+20h] [ebp+4h]
	float v12;  // [esp+20h] [ebp+4h]

	v1 = a1;
	result = *(_DWORD*)(a1 + 168);
	v3 = *(_BYTE*)(a1 + 434);
	v11 = *(_BYTE*)(a1 + 434);
	if (!result && *(_WORD*)(v1 + 262) > 0u && v3 > 1) {
		v4 = (double)*(unsigned int*)&byte_5D4594[2598000] / (double)(*(unsigned __int16*)(v1 + 262) * v3);
		v5 = (__int64)v4;
		v6 = v4 - (double)(int)(__int64)v4;
		if (*(_BYTE*)(v1 + 176) & 0x10) {
			v7 = v6 * (double)v3;
			v8 = (__int64)v7;
			v9 = (unsigned __int64)(__int64)v7 + 1;
			if (v9 >= v11)
				v9 = 0;
		} else {
			v7 = v6 * (double)v3;
			if (v5 & 1) {
				v10 = v3 - (unsigned __int64)(__int64)v7 - 1;
				LOBYTE(v8) = v10;
				v9 = v10 - 1;
				if (v9 < 0)
					v9 = 0;
			} else {
				v8 = (__int64)v7;
				v9 = (unsigned __int64)(__int64)v7 + 1;
				if (v9 >= v11)
					v9 = v11 - 1;
			}
		}
		v12 = (double)*(unsigned __int16*)(v1 + 262);
		result = sub_484C30(
		    v1 + 136, (__int64)((double)(unsigned __int8)(__int64)((v7 - (double)(int)(__int64)v7) * v12) *
					    ((double)(*(unsigned __int8*)(v9 + v1 + 242) -
						      *(unsigned __int8*)((char)v8 + v1 + 242)) /
					     v12) +
					(double)*(unsigned __int8*)((char)v8 + v1 + 242)));
	}
	return result;
}

//----- (004CE8C0) --------------------------------------------------------
void __cdecl sub_4CE8C0(int a1) {
	_DWORD* v1; // eax
	int v2;     // esi
	double v3;  // st7
	int v4;     // [esp+10h] [ebp-8h]

	if (*(_BYTE*)(a1 + 176) & 0x40) {
		v1 = sub_45A720(*(_DWORD*)(a1 + 264));
		if (v1) {
			v2 = v1[4] - *(_DWORD*)(a1 + 16);
			v4 = v1[3] - *(_DWORD*)(a1 + 12);
			v3 = nox_double2float(acos((double)v4 / sqrt((double)(v4 * v4 + v2 * v2)))) * 57.295776;
			if (v2 < 0)
				v3 = 360.0 - v3;
			sub_484C00(a1 + 136, (__int64)v3);
		}
	}
}

//----- (004CE960) --------------------------------------------------------
__int16 __cdecl sub_4CE960(int a1) {
	int v1;     // eax
	__int16 v2; // cx
	double v3;  // st7
	double v4;  // st6
	double v5;  // st5
	__int64 v6; // rax

	v1 = *(_DWORD*)(a1 + 168);
	if (!v1) {
		v2 = *(_WORD*)(a1 + 176);
		if ((v2 & 0x80u) != 0) {
			LOWORD(v1) = *(_WORD*)(a1 + 270);
			if ((_WORD)v1) {
				if ((v2 & 0x100) == 256)
					v5 = (double)(*(unsigned __int16*)(a1 + 272) - *(unsigned __int16*)(a1 + 268));
				else
					v5 = 360.0;
				v4 = (double)*(unsigned int*)&byte_5D4594[2649704];
				v3 = (double)(__int16)v1;
				v6 = (__int64)(((double)*(unsigned int*)&byte_5D4594[2598000] / (v5 / v3 * v4) -
						(double)(int)(__int64)((double)*(unsigned int*)&byte_5D4594[2598000] /
								       (v5 / v3 * v4))) *
						   (v5 / v3 * v4) * (v3 / v4) +
					       (double)*(unsigned __int16*)(a1 + 268));
				if ((int)v6 >= 0) {
					if ((int)v6 >= 360)
						LODWORD(v6) = v6 - 360;
				} else {
					LODWORD(v6) = v6 + 360;
				}
				LOWORD(v1) = sub_484C00(a1 + 136, v6);
			}
		}
	}
	return v1;
}

//----- (004CEA90) --------------------------------------------------------
int __cdecl sub_4CEA90(float* a1, int2* a2, int a3) {
	int v3;  // ebx
	int v4;  // ebp
	int v5;  // esi
	int v7;  // [esp+10h] [ebp-18h]
	int v8;  // [esp+14h] [ebp-14h]
	int v9;  // [esp+18h] [ebp-10h]
	int v10; // [esp+1Ch] [ebp-Ch]
	int v11; // [esp+20h] [ebp-8h]

	v3 = a2->field_0 + nox_float2int(*a1);
	v4 = a2->field_4 + nox_float2int(a1[1]);
	v9 = a2->field_0 + nox_float2int(a1[2]);
	v10 = a2->field_4 + nox_float2int(a1[3]);
	v7 = a2->field_0 + nox_float2int(a1[4]);
	v8 = a2->field_4 + nox_float2int(a1[5]);
	v11 = a2->field_0 + nox_float2int(a1[6]);
	v5 = a2->field_4 + nox_float2int(a1[7]);
	nox_client_drawSetColor_434460(a3);
	nox_client_drawAddPoint_49F500(v3, v4);
	nox_client_drawAddPoint_49F500(v7, v8);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v11, v5);
	nox_client_drawAddPoint_49F500(v7, v8);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v3, v4);
	nox_client_drawAddPoint_49F500(v9, v10);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v11, v5);
	nox_client_drawAddPoint_49F500(v9, v10);
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (004CEBA0) --------------------------------------------------------
int __cdecl sub_4CEBA0(int a1, char* a2) {
	_DWORD* v2; // eax
	_DWORD* v3; // edi
	char* v4;   // ebx
	_DWORD* v5; // esi
	_DWORD* v6; // ebp
	_DWORD* v8; // [esp+10h] [ebp-4h]
	char* v9;   // [esp+18h] [ebp+4h]

	dword_5d4594_1523024 = nox_new_window_from_file("rulelist.wnd", sub_4CF060);
	dword_5d4594_1523028 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1523024, 10170);
	dword_5d4594_1523032 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1523024, 10171);
	dword_5d4594_1523036 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1523024, 10172);
	*(_DWORD*)&byte_5D4594[1523040] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1523024, 10173);
	dword_5d4594_1523044 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1523024, 10174);
	dword_5d4594_1523048 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1523024, 10175);
	v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1523024, 10176);
	sub_46B340((int)v2, sub_4CEED0);
	sub_46B120(*(_DWORD**)&dword_5d4594_1523024, a1);
	v3 = *(_DWORD**)(dword_5d4594_1523028 + 32);
	v9 = sub_42F970("UISlider");
	v4 = sub_42F970("UISliderLit");
	v5 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1523024, 10179);
	v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1523024, 10177);
	v8 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1523024, 10178);
	*(_DWORD*)(v5[100] + 8) = 16;
	*(_DWORD*)(v5[100] + 12) = 10;
	sub_4B5700((int)v5, 0, 0, (int)v9, (int)v4, (int)v4);
	sub_46B280((int)v5, *(int*)&dword_5d4594_1523028);
	sub_46B280((int)v6, *(int*)&dword_5d4594_1523028);
	sub_46B280((int)v8, *(int*)&dword_5d4594_1523028);
	v3[9] = v5;
	v3[7] = v6;
	v3[8] = v8;
	sub_4CED40(a2);
	return dword_5d4594_1523024;
}

//----- (004CED40) --------------------------------------------------------
HANDLE __cdecl sub_4CED40(char* a1) {
	HANDLE result;                         // eax
	HANDLE v2;                             // ebp
	struct _WIN32_FIND_DATAA FindFileData; // [esp+8h] [ebp-248h]
	CHAR FileName[64];                     // [esp+148h] [ebp-108h]
	wchar_t v5[100];                       // [esp+188h] [ebp-C8h]

	nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16399, 0, 0);
	nox_sprintf(FileName, "maps\\%s\\*.rul", a1);
	result = FindFirstFileA(FileName, &FindFileData);
	v2 = result;
	if (result != (HANDLE)-1) {
		FindFileData.cFileName[strlen(FindFileData.cAlternateFileName) + 256] = 0;
		if (_strcmpi(a1, FindFileData.cAlternateFileName) &&
		    _strcmpi("user", FindFileData.cAlternateFileName)) {
			nox_swprintf(v5, L"%S", FindFileData.cAlternateFileName);
			nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16397, (int)v5, -1);
		}
		while (FindNextFileA(v2, &FindFileData)) {
			FindFileData.cFileName[strlen(FindFileData.cAlternateFileName) + 256] = 0;
			if (_strcmpi(a1, FindFileData.cAlternateFileName)) {
				if (_strcmpi("user", FindFileData.cAlternateFileName)) {
					nox_swprintf(v5, L"%S", FindFileData.cAlternateFileName);
					nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16397, (int)v5, -1);
				}
			}
		}
		result = (HANDLE)FindClose(v2);
	}
	return result;
}

//----- (004CEED0) --------------------------------------------------------
int __cdecl sub_4CEED0(int a1, int a2) {
	int v2;     // eax
	char v3;    // cl
	_WORD* v4;  // esi
	_DWORD* v5; // eax
	int xLeft;  // [esp+8h] [ebp-8h]
	int yTop;   // [esp+Ch] [ebp-4h]

	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if ((signed char)*(_BYTE*)(a1 + 4) >= 0) {
		if (*(_DWORD*)(a2 + 20) != 0x80000000)
			nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
	} else {
		nox_client_drawImageAt_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
	}
	v2 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16404, 0, 0);
	v3 = *(_BYTE*)(*(_DWORD*)&byte_5D4594[1523040] + 4);
	if (v2 < 0) {
		if (v3 & 8)
			sub_46ABB0(*(int*)&byte_5D4594[1523040], 0);
		if (*(_BYTE*)(dword_5d4594_1523044 + 4) & 8)
			sub_46ABB0(*(int*)&dword_5d4594_1523044, 0);
		if (*(_BYTE*)(dword_5d4594_1523048 + 4) & 8)
			sub_46ABB0(*(int*)&dword_5d4594_1523048, 0);
	} else {
		if (!(v3 & 8))
			sub_46ABB0(*(int*)&byte_5D4594[1523040], 1);
		if (!(*(_BYTE*)(dword_5d4594_1523044 + 4) & 8) && !nox_common_gameFlags_check_40A5C0(49152))
			sub_46ABB0(*(int*)&dword_5d4594_1523044, 1);
		if (!(*(_BYTE*)(dword_5d4594_1523048 + 4) & 8))
			sub_46ABB0(*(int*)&dword_5d4594_1523048, 1);
	}
	v4 = (_WORD*)nox_window_call_field_94(*(int*)&dword_5d4594_1523032, 16413, 0, 0);
	v5 = (_DWORD*)sub_46B4F0();
	if (v5 && *v5 == 10171) {
		if (v4 && *v4) {
			if (!(*(_BYTE*)(dword_5d4594_1523036 + 4) & 8)) {
				sub_46ABB0(*(int*)&dword_5d4594_1523036, 1);
				return 1;
			}
		} else if (*(_BYTE*)(dword_5d4594_1523036 + 4) & 8) {
			sub_46ABB0(*(int*)&dword_5d4594_1523036, 0);
		}
	}
	return 1;
}

//----- (004CF060) --------------------------------------------------------
int __cdecl sub_4CF060(int a1, unsigned int a2, int* a3, int a4) {
	_DWORD* v4;         // esi
	const char* v6;     // eax
	const char* v7;     // esi
	char* v8;           // eax
	int v9;             // esi
	int v10;            // eax
	int v11;            // eax
	char* v12;          // eax
	char* v13;          // eax
	char* v14;          // esi
	int v15;            // eax
	int v16;            // eax
	char* v17;          // eax
	char* v18;          // edi
	int v19;            // eax
	int v20;            // esi
	int v21;            // eax
	const wchar_t* v22; // edi
	char* v23;          // eax
	char* v24;          // eax
	int v25;            // esi
	int v26;            // ebx
	const wchar_t* v27; // eax
	char v28[16];       // [esp+Ch] [ebp-10h]

	if (a2 > 0x4007) {
		if (a2 == 16400)
			sub_46B0A0(a3);
		return 1;
	}
	if (a2 != 16391) {
		if (a2 != 23 && a2 == 16387) {
			v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1523024, a4);
			sub_416630();
			sub_416640();
			if (!v4)
				return 0;
			if ((unsigned __int16)a3 == 1)
				return 0;
			v6 = (const char*)nox_window_call_field_94((int)v4, 16413, 0, 0);
			v7 = v6;
			if (v6) {
				if (*v6) {
					atoi(v6);
					if (a4 == 10171) {
						v8 = sub_4165B0();
						if (!_strcmpi(v7, v8) || !_strcmpi(v7, "user")) {
							sub_46ABB0(*(int*)&dword_5d4594_1523036, 0);
							return 1;
						}
					}
				}
			}
		}
		return 1;
	}
	v9 = sub_46B0A0(a3);
	sub_452D80(766, 100);
	switch (v9) {
	case 10172:
		sub_416580();
		v22 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1523032, 16413, 0, 0);
		nox_sprintf(v28, "%S%s", v22, &byte_587000[191640]);
		v23 = sub_4165B0();
		sub_459AA0((int)v23);
		v24 = sub_4165B0();
		sub_57AAA0(v28, v24, 0);
		v25 = 0;
		v26 = *(_DWORD*)(dword_5d4594_1523028 + 32);
		if (*(short*)(v26 + 44) <= 0)
			goto LABEL_22;
		break;
	case 10173:
		sub_416580();
		v10 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16404, 0, 0);
		v11 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16406, v10, 0);
		nox_sprintf(v28, "%S%s", v11, &byte_587000[191592]);
		v12 = sub_4165B0();
		sub_459AA0((int)v12);
		v13 = sub_4165B0();
		sub_57AAA0(v28, v13, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16403, -1, 0);
		return 1;
	case 10174:
		sub_416580();
		v14 = sub_4165B0();
		v15 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16404, 0, 0);
		v16 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16406, v15, 0);
		nox_sprintf(v28, "%S%s", v16, &byte_587000[191608]);
		sub_57A1E0((int*)v14, v28, 0, 7, *((_WORD*)v14 + 26));
		sub_453F70(v14 + 24);
		sub_4535E0((int*)v14 + 11);
		sub_4535F0(*((_DWORD*)v14 + 12));
		v17 = sub_4165B0();
		sub_459880((int)v17);
		nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16403, -1, 0);
		sub_459D50(1);
		return 1;
	case 10175:
		v18 = sub_4165B0();
		v19 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16404, 0, 0);
		v20 = v19;
		v21 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16406, v19, 0);
		nox_sprintf(v28, "%S%s", v21, &byte_587000[191624]);
		sub_57A9F0(v18, v28);
		nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16398, v20, 0);
		return 1;
	default:
		return 1;
	}
	while (1) {
		v27 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16406, v25, 0);
		if (!_nox_wcsicmp(v22, v27))
			break;
		if (++v25 >= *(__int16*)(v26 + 44)) {
		LABEL_22:
			nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16397, (int)v22, -1);
			nox_window_call_field_94(*(int*)&dword_5d4594_1523032, 16414, (int)&byte_5D4594[1523056], 0);
			sub_46ABB0(*(int*)&dword_5d4594_1523036, 0);
			return 1;
		}
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_1523032, 16414, (int)&byte_5D4594[1523052], 0);
	return 1;
}

//----- (004CF460) --------------------------------------------------------
void sub_4CF460() { nox_srand(0x7D2u); }

//----- (004CF470) --------------------------------------------------------
int __cdecl sub_4CF470(char* a1, int a2) {
	int v2;              // ebx
	int v4;              // [esp+8h] [ebp-408h]
	int v5;              // [esp+Ch] [ebp-404h]
	CHAR FileName[1024]; // [esp+10h] [ebp-400h]

	v2 = 0;
	if (!a2)
		return 6;
	if (a1) {
		if (strchr(a1, 92)) {
			strcpy(FileName, a1);
		} else {
			strcpy(FileName, "maps\\");
			strncat(FileName, a1, strlen(a1) - 4);
			*(_WORD*)&FileName[strlen(FileName)] = *(_WORD*)&byte_587000[191672];
			strcat(FileName, a1);
		}
		if (_access(FileName, 0) != -1) {
			v4 = 0;
			if (_access(FileName, 2) == -1)
				v2 = 1;
			if (sub_426910(FileName, 1, 19)) {
				v2 |= 2u;
				sub_426AC0_file3_fread(&v5, 4u);
				if (v5 != -86065425 && v5 == -86050098) {
					sub_426C20(&v4, 4u);
					if (v4 == a2)
						v2 |= 4u;
				}
				sub_4269F0();
			}
		}
	}
	return v2;
}

//----- (004CF990) --------------------------------------------------------
char sub_4CF990() {
	char* v0;            // esi
	char* v1;            // eax
	unsigned __int16 v2; // ax
	int v3;              // eax
	BOOL v4;             // esi
	__int16 v5;          // ax

	v0 = sub_4165B0();
	if (nox_common_gameFlags_check_40A5C0(1024) && (*(int*)&byte_5D4594[3803228] < 0 || !(v0[53] & 4)))
		sub_40A5E0(0);
	sub_455C10();
	sub_456050();
	if (nox_common_gameFlags_check_40A5C0(4096) && *(int*)&byte_5D4594[3803228] < 0) {
		sub_4D6B10(1);
		sub_419030(1);
	}
	v1 = sub_409B40();
	if (sub_4CFE10(v1)) {
		v2 = sub_4CFFA0((int)&byte_5D4594[3801836]);
		if (byte_5D4594[3803228] & 1) {
			nox_common_gameFlags_unset_40A540(6128);
			sub_417E10();
			LOBYTE(v3) = sub_40A4D0(2048);
		} else if (byte_5D4594[3803228] & 2) {
			v4 = nox_common_gameFlags_check_40A5C0(128);
			nox_common_gameFlags_unset_40A540(6128);
			LOBYTE(v3) = sub_40A4D0(4096);
			if (v4)
				LOBYTE(v3) = nox_server_setupQuestGame_4D6C70();
		} else if ((int)*(_DWORD*)&byte_5D4594[3803228] >= 0) {
			if (!(*((_WORD*)v0 + 26) & v2))
				*((_WORD*)v0 + 26) =
				    sub_4CFC90((int)&byte_5D4594[3801836]) | *((_WORD*)v0 + 26) & 0xE80F;
			if (!(v0[52] & 0x10))
				sub_4CFC30();
			v5 = *((_WORD*)v0 + 26);
			if (v5 & 0x20) {
				v3 = sub_417EA0();
				if (v3) {
					nox_common_gameFlags_unset_40A540(6128);
					LOBYTE(v3) = sub_40A4D0(32);
				}
			} else if (v5 & 0x40) {
				LOBYTE(v3) = sub_417F30();
				if (v3) {
					nox_common_gameFlags_unset_40A540(6128);
					sub_40A4D0(64);
					LOBYTE(v3) = sub_424BB0(132);
				}
			} else if (v5 & 0x10) {
				v3 = sub_4180D0();
				if (v3) {
					nox_common_gameFlags_unset_40A540(6128);
					LOBYTE(v3) = sub_40A4D0(16);
				}
			} else if (v5 & 0x400) {
				if (!nox_common_gameFlags_check_40A5C0(1024))
					sub_40A5E0(1);
				nox_common_gameFlags_unset_40A540(6128);
				LOBYTE(v3) = sub_40A4D0(1024);
			} else {
				nox_common_gameFlags_unset_40A540(6128);
				LOBYTE(v3) = sub_40A4D0(256);
			}
		} else {
			sub_40A1F0(0);
			nox_common_gameFlags_unset_40A540(6128);
			sub_40A4D0(128);
			LOBYTE(v3) = sub_417DD0();
			if ((_BYTE)v3) {
				sub_418640();
				v3 = sub_417DA0(2);
				if (!v3) {
					v3 = nox_common_gameFlags_check_40A5C0(0x8000);
					if (!v3)
						LOBYTE(v3) = (unsigned int)sub_418690(1);
				}
			}
		}
	} else {
		v3 = nox_common_gameFlags_check_40A5C0(512);
		if (!v3) {
			nox_common_gameFlags_unset_40A540(6128);
			sub_40A4D0(256);
			LOBYTE(v3) = sub_4D0D90(1);
		}
	}
	return v3;
}
// 4CFAF1: variable 'v2' is possibly undefined
// 4CFB53: variable 'v3' is possibly undefined

//----- (004CFC30) --------------------------------------------------------
void sub_4CFC30() {
	int v0; // esi
	int v1; // edi

	if (!*(_DWORD*)&byte_5D4594[1523076])
		*(_DWORD*)&byte_5D4594[1523076] = sub_4E3AA0((CHAR*)&byte_587000[191720]);
	v0 = sub_4DA790();
	if (v0) {
		do {
			v1 = sub_4DA7A0(v0);
			if (*(unsigned __int16*)(v0 + 4) == *(_DWORD*)&byte_5D4594[1523076]) {
				sub_4E5CC0(v0);
				sub_4EC6A0(v0);
			}
			v0 = v1;
		} while (v1);
	}
}

//----- (004CFC90) --------------------------------------------------------
int __cdecl sub_4CFC90(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)(a1 + 1392);
	if (v1 & 4)
		return 256;
	if (v1 & 0x20)
		return 1024;
	if (v1 & 8)
		return 32;
	if (v1 & 0x10)
		return 16;
	if (v1 & 0x40)
		return 64;
	return (v1 & 2) != 0 ? 4096 : 128;
}

//----- (004CFCE0) --------------------------------------------------------
int sub_4CFCE0() {
	_DWORD* v0; // eax
	int v1;     // esi
	int v3;     // [esp+4h] [ebp-114h]
	int v4;     // [esp+8h] [ebp-110h]
	int v5[2];
	int v7;       // [esp+14h] [ebp-104h]
	char v8[256]; // [esp+18h] [ebp-100h]

	sub_426AC0_file3_fread(&v5[0], 4u);
	sub_426AC0_file3_fread(&v5[1], 4u);
	sub_426A80(&v5);
	while (1) {
		LOBYTE(v3) = 0;
		sub_426AC0_file3_fread(&v3, 1u);
		if (!(_BYTE)v3)
			break;
		sub_426AC0_file3_fread(v8, (unsigned __int8)v3);
		sub_426C20(&v7, 4u);
		if (!sub_426EA0(0, v8, &v4)) {
			if (v4 == 1)
				return 0;
			v0 = sub_4E3810(v8);
			v1 = (int)v0;
			if (!v0 || !((int(__cdecl*)(_DWORD*, _DWORD))v0[176])(v0, 0))
				goto LABEL_9;
			sub_4F3F50(v1, 0, 0);
		}
	}
	if (!sub_579CA0()) {
	LABEL_9:
		sub_4269F0();
		return 0;
	}
	sub_4DAF10();
	if (nox_common_gameFlags_check_40A5C0(1)) {
		sub_5799C0();
		sub_4DAC00();
	}
	sub_4DB090();
	return 1;
}

//----- (004CFDF0) --------------------------------------------------------
int __cdecl sub_4CFDF0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1523072] = a1;
	return result;
}

//----- (004CFE00) --------------------------------------------------------
int sub_4CFE00() { return *(_DWORD*)&byte_5D4594[1523072]; }

//----- (004CFE10) --------------------------------------------------------
int __cdecl sub_4CFE10(const char* a1) {
	char* v1;           // edi
	unsigned __int8 v2; // cl
	int result;         // eax
	int v4;             // [esp+10h] [ebp-108h]
	int v5;             // [esp+14h] [ebp-104h]
	char v6[256];       // [esp+18h] [ebp-100h]

	strcpy(v6, "maps\\");
	strcat(v6, a1);
	*(_WORD*)&v6[strlen(v6)] = *(_WORD*)&byte_587000[191736];
	strcat(v6, a1);
	v1 = &v6[strlen(v6)];
	v2 = byte_587000[191744];
	strcat(v1, ".map");
	v1[4] = v2;
	result = sub_426910(v6, 1, 19);
	if (result) {
		sub_426AC0_file3_fread(&v4, 4u);
		if (v4 != -86065425) {
			if (v4 != -86050098) {
				sub_4269F0();
				return 0;
			}
			sub_426C20(&v5, 4u);
		}
		sub_426AC0_file3_fread(v6, 0x20u);
		if (nox_server_mapRWMapInfo_42A6E0()) {
			sub_4269F0();
			result = 1;
		} else {
			sub_4269F0();
			result = 0;
		}
	}
	return result;
}

//----- (004CFF50) --------------------------------------------------------
int __cdecl sub_4CFF50(int a1) {
	int result; // eax

	result = 0;
	if (a1 & 1)
		result = 512;
	if (a1 & 2)
		BYTE1(result) |= 0x10u;
	if (a1 & 4)
		BYTE1(result) |= 1u;
	if (a1 & 0x20)
		BYTE1(result) |= 4u;
	if (a1 & 8)
		LOBYTE(result) = result | 0x20;
	if (a1 & 0x10)
		LOBYTE(result) = result | 0x10;
	if (a1 & 0x40)
		LOBYTE(result) = result | 0x40;
	if (a1 < 0)
		LOBYTE(result) = result | 0x80;
	return result;
}

//----- (004CFFA0) --------------------------------------------------------
int __cdecl sub_4CFFA0(int a1) { return sub_4CFF50(*(_DWORD*)(a1 + 1392)); }

//----- (004CFFC0) --------------------------------------------------------
int __cdecl sub_4CFFC0(int a1) { return sub_4CFF50(*(_DWORD*)(a1 + 28)); }

//----- (004CFFE0) --------------------------------------------------------
int __cdecl sub_4CFFE0(int a1) {
	int result; // eax

	result = sub_4DA870();
	if (!result)
		return 0;
	while (*(_DWORD*)(result + 44) != a1) {
		result = sub_4DA880(result);
		if (!result)
			return 0;
	}
	return result;
}

//----- (004D0010) --------------------------------------------------------
int __cdecl sub_4D0010(_DWORD* a1, int a2) {
	int i;                  // eax
	_DWORD* v3;             // edi
	CHAR* v4;               // eax
	int(__cdecl * v5)(int); // eax
	int v6;                 // esi
	int v7;                 // eax
	int v8;                 // ecx
	int v9;                 // eax
	int v10;                // ecx
	int v11;                // esi
	int v12;                // eax
	int v13;                // ecx
	int v14;                // esi
	char* v15;              // eax
	int v16;                // ecx
	int v17;                // esi
	char* v18;              // eax
	int v19;                // esi
	_DWORD* v20;            // eax
	int v21;                // eax
	int v22;                // esi
	char* v23;              // eax

	for (i = sub_4DA870(); i; i = sub_4DA880(i)) {
		*(_DWORD*)(i + 44) = *(_DWORD*)(i + 40);
		*(_DWORD*)(i + 40) = a2++;
	}
	v3 = (_DWORD*)sub_4DA870();
	if (v3) {
		while (1) {
			v4 = (CHAR*)sub_4E39D0((int)v3);
			v5 = *(int(__cdecl**)(int))(sub_4E3B60(v4) + 212);
			if (v5 != sub_4F53D0)
				break;
			v6 = v3[187];
			v7 = sub_4CFFE0(*(_DWORD*)(v6 + 8));
			if (!v7)
				goto LABEL_7;
			v8 = *(_DWORD*)(v7 + 40);
			*(_DWORD*)(v6 + 4) = v7;
			*(_DWORD*)(v6 + 8) = v8;
		LABEL_28:
			v3 = (_DWORD*)sub_4DA880((int)v3);
			if (!v3)
				return a2;
		}
		if (v5 != sub_4F54A0) {
			if (v5 == sub_4F5300) {
				v11 = v3[187];
				v12 = sub_4CFFE0(*(_DWORD*)(v11 + 16));
				if (v12) {
					v13 = *(_DWORD*)(v12 + 40);
					*(_DWORD*)(v11 + 12) = v12;
					*(_DWORD*)(v11 + 16) = v13;
				} else {
					*(_DWORD*)(v11 + 16) = 0;
					*(_DWORD*)(v11 + 12) = 0;
				}
			} else if (v5 == sub_4F51D0) {
				v14 = v3[175];
				v15 = sub_426A70();
				v16 = *(_DWORD*)(v14 + 12);
				*(_DWORD*)(v14 + 8) += *a1 - 23 * *(_DWORD*)v15;
				*(_DWORD*)(v14 + 12) = a1[1] - 23 * *((_DWORD*)v15 + 1) + v16;
			} else if (v5 == sub_4F4B90) {
				v17 = v3[175];
				v18 = sub_426A70();
				*(float*)(v17 + 80) = (double)(int)(*a1 - 23 * *(_DWORD*)v18) + *(float*)(v17 + 80);
				*(float*)(v17 + 84) =
				    (double)(int)(a1[1] - 23 * *((_DWORD*)v18 + 1)) + *(float*)(v17 + 84);
			} else if (v5 == sub_4F5730) {
				v19 = v3[187];
				v20 = (_DWORD*)sub_579C60(*(_DWORD*)(v19 + 8));
				if (v20)
					*(_DWORD*)(v19 + 8) = *v20;
				else
					*(_DWORD*)(v19 + 8) = 0;
				v21 = sub_4CFFE0(*(_DWORD*)(v19 + 32));
				if (v21)
					*(_DWORD*)(v19 + 32) = *(_DWORD*)(v21 + 40);
				else
					*(_DWORD*)(v19 + 32) = 0;
			} else if (v5 == sub_4F5890) {
				v22 = v3[173];
				v23 = sub_426A70();
				*(float*)(v22 + 28) = (double)(int)(*a1 - 23 * *(_DWORD*)v23) + *(float*)(v22 + 28);
				*(float*)(v22 + 32) =
				    (double)(int)(a1[1] - 23 * *((_DWORD*)v23 + 1)) + *(float*)(v22 + 32);
			}
			goto LABEL_28;
		}
		v6 = v3[187];
		v9 = sub_4CFFE0(*(_DWORD*)(v6 + 8));
		if (v9) {
			v10 = *(_DWORD*)(v9 + 40);
			*(_DWORD*)(v6 + 4) = v9;
			*(_DWORD*)(v6 + 8) = v10;
			goto LABEL_28;
		}
	LABEL_7:
		*(_DWORD*)(v6 + 8) = 0;
		*(_DWORD*)(v6 + 4) = 0;
		goto LABEL_28;
	}
	return a2;
}

//----- (004D0250) --------------------------------------------------------
int __cdecl sub_4D0250(char* a1, char* a2, int a3, int a4) {
	int result;    // eax
	FILE* v5;      // esi
	_DWORD* v6;    // edi
	int v7;        // ebp
	_DWORD* v8;    // esi
	int i;         // eax
	int j;         // eax
	int v11;       // esi
	int k;         // eax
	int l;         // eax
	int v14;       // [esp+10h] [ebp-148h]
	int v15;       // [esp+14h] [ebp-144h]
	int v16;       // [esp+18h] [ebp-140h]
	int v17[2];    // [esp+1Ch] [ebp-13Ch]
	int v19;       // [esp+24h] [ebp-134h]
	int v20;       // [esp+28h] [ebp-130h]
	int v21;       // [esp+2Ch] [ebp-12Ch]
	int v22;       // [esp+30h] [ebp-128h]
	int v23;       // [esp+34h] [ebp-124h]
	int v24;       // [esp+38h] [ebp-120h]
	int v25;       // [esp+3Ch] [ebp-11Ch]
	int v26;       // [esp+40h] [ebp-118h]
	int v27;       // [esp+44h] [ebp-114h]
	int4 v28;      // [esp+48h] [ebp-110h]
	char v29[256]; // [esp+58h] [ebp-100h]

	if (a3 <= 0)
		return 0;
	result = sub_426910(a1, 1, -1);
	if (result) {
		v5 = sub_426A60();
		fread(&v16, 4u, 1u, v5);
		if (v16 == a4) {
			fread(&v17[0], 4u, 1u, v5);
			fread(&v17[1], 4u, 1u, v5);
			sub_426A80(v17);
			fread(&v19, 4u, 1u, v5);
			fread(&v20, 4u, 1u, v5);
			fread(&v25, 4u, 1u, v5);
			fread(&v26, 4u, 1u, v5);
			fread(&v21, 4u, 1u, v5);
			fread(&v22, 4u, 1u, v5);
			fread(&v23, 4u, 1u, v5);
			fread(&v24, 4u, 1u, v5);
			v6 = a2;
			if (!a2)
				v6 = &v19;
			sub_428170(v6, &v28);
			v7 = sub_426A30();
			sub_426A20(5);
			sub_426A50(1);
			while (1) {
				sub_426AC0_file3_fread(&v15, 1u);
				if (!(_BYTE)v15)
					break;
				sub_426AC0_file3_fread(v29, (unsigned __int8)v15);
				sub_426AC0_file3_fread(&v27, 4u);
				if (!sub_426EA0((int)v6, v29, &v14)) {
					if (v14 == 1)
						goto LABEL_20;
					v8 = sub_4E3810(v29);
					if (!v8) {
						sub_426A50(0);
						return 0;
					}
					if (!((int(__cdecl*)(_DWORD*, int4*))v8[176])(v8, &v28)) {
						sub_426A20(v7);
						sub_4E38A0((int)v8);
						sub_4269F0();
						return 0;
					}
					sub_4F3F50((int)v8, 0, &v28.field_0);
				}
			}
			for (i = sub_4DA870(); i; i = sub_4DA880(i))
				*(_DWORD*)(i + 16) |= 0x80000000;
			sub_426A50(0);
			sub_426A20(v7);
			sub_4269F0();
			if (!sub_579D20()) {
			LABEL_20:
				sub_426A20(v7);
				sub_4269F0();
				return 0;
			}
			for (j = sub_579890(); j; j = sub_5798A0(j))
				*(_DWORD*)(j + 480) |= 0x80000000;
			v11 = sub_4D0010(&v28, a3);
			for (k = sub_579890(); k; k = sub_5798A0(k))
				*(_DWORD*)(k + 4) = 0;
			for (l = sub_4DA870(); l; l = sub_4DA880(l))
				*(_DWORD*)(l + 44) = 0;
			sub_5799C0();
			sub_4DB030();
			result = v11;
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (004D0550) --------------------------------------------------------
int __cdecl sub_4D0550(char* a1) {
	int result;         // eax
	unsigned int v2;    // kr08_4
	char v3;            // cl
	int v4;             // edx
	unsigned __int8 v5; // al
	char* v6;           // edi
	char* v7;           // edi
	unsigned __int8 v8; // cl
	unsigned __int8 v9; // [esp+4h] [ebp-104h]
	char v10[256];      // [esp+8h] [ebp-100h]

	result = 0;
	if (a1) {
		v10[0] = 0;
		strncat(v10, a1, strlen(a1));
		v2 = strlen(v10) + 1;
		v3 = v2 - 1;
		v9 = v2 - 1;
		if ((_BYTE)v2 != 1) {
			while (v10[v9] != 92) {
				v9 = --v3;
				if (!v3)
					goto LABEL_7;
			}
			v10[v9 + 1] = 0;
		}
	LABEL_7:
		v4 = *(_DWORD*)&byte_587000[191752];
		v5 = byte_587000[191756];
		v6 = &v10[strlen(v10)];
		*(_DWORD*)v6 = *(_DWORD*)&byte_587000[191748];
		*((_DWORD*)v6 + 1) = v4;
		v6[8] = v5;
		if (!sub_4D0670(v10)) {
			v10[0] = 0;
			strncat(v10, a1, strlen(a1) - 4);
			v7 = &v10[strlen(v10) + 1];
			v8 = byte_587000[191764];
			*(_DWORD*)--v7 = *(_DWORD*)&byte_587000[191760];
			v7[4] = v8;
			sub_4D0670(v10);
		}
		if (sub_43AF70() == 1)
			sub_4D0670((char*)&byte_587000[191768]);
		result = 1;
	}
	return result;
}

//----- (004D0670) --------------------------------------------------------
int __cdecl sub_4D0670(char* a1) {
	int v1;          // ebp
	FILE* v2;        // eax
	FILE* v3;        // esi
	char* v4;        // eax
	int v5;          // eax
	char v7[255];    // [esp+Ch] [ebp-300h]
	wchar_t v8[256]; // [esp+10Ch] [ebp-200h]

	v1 = 6128;
	v2 = fopen(a1, "r");
	v3 = v2;
	if (!v2)
		return 0;
	if (!feof(v3)) {
		do {
			memset(v7, 0, 0xFCu);
			*(_WORD*)&v7[252] = 0;
			v7[254] = 0;
			fgets(v7, 255, v3);
			v4 = strchr(v7, 10);
			if (v4)
				*v4 = 0;
			if (v7[0]) {
				nox_swprintf(v8, L"%S", v7);
				v5 = sub_57AE30(v7);
				if (v5) {
					v1 = v5;
				} else if (nox_common_gameFlags_check_40A5C0(v1)) {
					nox_server_parseCmdText_443C80(v8, 1);
				}
			}
		} while (!feof(v3));
	}
	fclose(v3);
	return 1;
}

//----- (004D0760) --------------------------------------------------------
_DWORD* __cdecl sub_4D0760(int a1) {
	int* v1; // edi

	v1 = sub_425890((int*)&byte_5D4594[1523060]);
	if (!v1)
		return sub_4258E0((int)&byte_5D4594[1523060], (_DWORD*)a1);
	while (strcmp((const char*)(a1 + 12), (const char*)v1 + 12) > 0) {
		v1 = sub_4258A0(v1);
		if (!v1)
			return sub_4258E0((int)&byte_5D4594[1523060], (_DWORD*)a1);
	}
	return sub_4258E0((int)v1, (_DWORD*)a1);
}

//----- (004D07F0) --------------------------------------------------------
HANDLE sub_4D07F0() {
	HANDLE result;                         // eax
	HANDLE v1;                             // ebp
	char* v2;                              // ebp
	HANDLE v3;                             // [esp+4h] [ebp-150h]
	char v4[12];                           // [esp+8h] [ebp-14Ch]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+14h] [ebp-140h]

	sub_425760(&byte_5D4594[1523060]);
	result = FindFirstFileA((LPCSTR)&byte_587000[191796], &FindFileData);
	v1 = result;
	v3 = result;
	if (result != (HANDLE)-1) {
		do {
			if (FindFileData.dwFileAttributes & 0x10 &&
			    (_strnicmp(FindFileData.cFileName, "wiz", 3u) &&
				 _strnicmp(FindFileData.cFileName, "war", 3u) &&
				 _strnicmp(FindFileData.cFileName, "con", 3u) ||
			     FindFileData.cFileName[3] < 48 || FindFileData.cFileName[3] > 57) &&
			    strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..")) {
				strncpy(v4, FindFileData.cFileName, 8u);
				v4[8] = 0;
				if (sub_4CFE10(v4)) {
					v2 = (char*)nox_malloc(0x24u);
					sub_425770(v2);
					strcpy(v2 + 12, v4);
					*((_DWORD*)v2 + 6) = 1;
					*((_DWORD*)v2 + 7) = *(_DWORD*)&byte_5D4594[3803228];
					v2[33] = byte_5D4594[3803233];
					v2[32] = byte_5D4594[3803232];
					sub_4D0760((int)v2);
					v1 = v3;
				}
			}
		} while (FindNextFileA(v1, &FindFileData));
		result = (HANDLE)FindClose(v1);
	}
	return result;
}

//----- (004D0970) --------------------------------------------------------
void sub_4D0970() {
	int* result; // eax
	int* v1;     // esi
	int* v2;     // edi

	result = sub_425890((int*)&byte_5D4594[1523060]);
	v1 = result;
	if (result) {
		do {
			v2 = sub_4258A0(v1);
			sub_425920((_DWORD**)v1);
			free(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (004D09B0) --------------------------------------------------------
int* sub_4D09B0() { return sub_425890((int*)&byte_5D4594[1523060]); }

//----- (004D09C0) --------------------------------------------------------
int* __cdecl sub_4D09C0(int* a1) { return sub_4258A0(a1); }

//----- (004D09D0) --------------------------------------------------------
int* __cdecl sub_4D09D0(char* a1) {
	int* v1; // esi

	v1 = sub_4D09B0();
	if (!v1)
		return 0;
	while (_strcmpi(a1, (const char*)v1 + 12) || !v1[6]) {
		v1 = sub_4D09C0(v1);
		if (!v1)
			return 0;
	}
	return v1;
}

//----- (004D0A20) --------------------------------------------------------
void sub_4D0A20() { nox_srand(0x7D3u); }

//----- (004D0A30) --------------------------------------------------------
FILE* sub_4D0A30() {
	int v0;        // ebp
	FILE* result;  // eax
	FILE* v7;      // ebx
	int v8;        // eax
	int v9;        // edx
	int v10;       // eax
	int v11;       // ebx
	char* v12;     // eax
	int v13;       // eax
	int v14;       // ebx
	FILE* v15;     // [esp+10h] [ebp-108h]
	char v16[128]; // [esp+18h] [ebp-100h]
	char v17[128]; // [esp+98h] [ebp-80h]

	v0 = 1;
	memset(&byte_5D4594[1548428], 0, 0x18u);
	strcpy((char*)&byte_5D4594[1524108], sub_409E10());
	strcat((char*)&byte_5D4594[1524108], "\\mapcycle.txt");
	result = fopen((const char*)&byte_5D4594[1524108], "r");
	v7 = result;
	v15 = result;
	if (result) {
		if (fgets(v16, 127, result)) {
			sub_4D0CC0(v16);
			v8 = sub_4D0C80(v16);
			if (v8 < 0) {
				v9 = *(_DWORD*)&byte_5D4594[1548432];
				strcpy((char*)&byte_5D4594[128 * *(_DWORD*)&byte_5D4594[1548432] + 1532428], v16);
				*(_DWORD*)&byte_5D4594[1548432] = v9 + 1;
			} else {
				v0 = v8;
			}
		}
		while (!feof(v7)) {
			if (fgets(v16, 127, v7)) {
				sub_4D0CC0(v16);
				v10 = sub_4D0C80(v16);
				if (v10 < 0) {
					if (*(int*)&byte_5D4594[4 * v0 + 1548428] < 25 && v16[0]) {
						v11 = sub_4D0C70(v0);
						strcpy(v17, v16);
						v12 = strtok(v17, ".\n");
						if (sub_4CFE10(v12)) {
							v13 = sub_4CFFA0((int)&byte_5D4594[3801836]);
							if (v13 & v11) {
								v14 = *(_DWORD*)&byte_5D4594[4 * v0 + 1548428];
								strcpy(
								    (char*)&byte_5D4594[128 * (v14 + 20 * v0 + 5 * v0) +
											1529228],
								    v16);
								*(_DWORD*)&byte_5D4594[4 * v0 + 1548428] = v14 + 1;
							}
						}
						v7 = v15;
					}
				} else {
					v0 = v10;
				}
			}
		}
		result = (FILE*)fclose(v7);
	} else {
		*(_DWORD*)&byte_5D4594[1548484] = 0;
	}
	return result;
}
// 4D0BF1: variable 'v13' is possibly undefined

//----- (004D0C70) --------------------------------------------------------
int __cdecl sub_4D0C70(int a1) { return *(_DWORD*)&byte_587000[8 * a1 + 191836]; }

//----- (004D0C80) --------------------------------------------------------
int __cdecl sub_4D0C80(char* a1) {
	int v1;          // edi
	const char** v2; // esi

	v1 = 0;
	v2 = (const char**)&byte_587000[191832];
	while (_strcmpi(*v2, a1)) {
		v2 += 2;
		++v1;
		if ((int)v2 >= (int)&byte_587000[191880])
			return -1;
	}
	return v1;
}

//----- (004D0CC0) --------------------------------------------------------
void __cdecl sub_4D0CC0(char* a1) {
	char* v1; // eax
	char* v2; // eax

	if (a1) {
		v1 = strchr(a1, 13);
		if (v1)
			*v1 = 0;
		v2 = strchr(a1, 10);
		if (v2)
			*v2 = 0;
	}
}

//----- (004D0D50) --------------------------------------------------------
int __cdecl sub_4D0D50(int a1) {
	int result;          // eax
	unsigned __int8* v2; // ecx

	result = 0;
	v2 = &byte_587000[191836];
	while (!(a1 & *(_DWORD*)v2)) {
		v2 += 8;
		++result;
		if ((int)v2 >= (int)&byte_587000[191884])
			return 0;
	}
	return result;
}

//----- (004D0D70) --------------------------------------------------------
BOOL sub_4D0D70() { return *(_DWORD*)&byte_5D4594[1548484] || *(_DWORD*)&nox_common_engineFlags & 0x40000; }

//----- (004D0D90) --------------------------------------------------------
int __cdecl sub_4D0D90(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1548484] = a1;
	return result;
}

//----- (004D0DA0) --------------------------------------------------------
void sub_4D0DA0() {
	memset(&byte_5D4594[1548452], 0, 0x18u);
	memset(&byte_5D4594[1548428], 0, 0x18u);
}

//----- (004D0DC0) --------------------------------------------------------
int __cdecl sub_4D0DC0(int a1, int a2) {
	int result; // eax

	result = sub_4D0D50(a1);
	*(_DWORD*)&byte_5D4594[4 * result + 1548452] = a2;
	return result;
}

//----- (004D0DE0) --------------------------------------------------------
int __cdecl sub_4D0DE0(int a1) { return *(_DWORD*)&byte_5D4594[4 * sub_4D0D50(a1) + 1548452]; }

//----- (004D0E00) --------------------------------------------------------
int sub_4D0E00() {
	int* i;               // ebp
	int v3;               // edx
	unsigned __int8 v4;   // al
	unsigned __int8* v5;  // edi
	int v6;               // eax
	int result;           // eax
	int v8;               // ecx
	int v9;               // ebp
	unsigned __int8* v10; // ebx
	int v11;              // edi
	int v12;              // esi
	int v13;              // [esp+10h] [ebp-4h]

	nox_srand_time();
	dword_5d4594_1548476 = 0;
	for (i = sub_4D09B0(); i; i = sub_4D09C0(i)) {
		if (i[6]) {
			if (sub_4CFFC0((int)i) & 0x1000) {
				if (*(int*)&dword_5d4594_1548476 < 128) {
					v3 = 32 * dword_5d4594_1548476;
					strcpy((char*)&byte_5D4594[32 * dword_5d4594_1548476 + 1525136],
					       (const char*)i + 12);
					v4 = byte_587000[192004];
					v5 = &byte_5D4594[v3 + 1525136 +
							  strlen((const char*)&byte_5D4594[v3 + 1525136])];
					*(_DWORD*)v5 = *(_DWORD*)&byte_587000[192000];
					v5[4] = v4;
					v6 = dword_5d4594_1548476 + 1;
					*(_DWORD*)&byte_5D4594[v3 + 1525132] = 0;
					dword_5d4594_1548476 = v6;
				}
			}
		}
	}
	result = dword_5d4594_1548476;
	v8 = 1;
	if (dword_5d4594_1548476 > 0) {
		v9 = 1;
		v10 = &byte_5D4594[1525132];
		do {
			if (!*(_DWORD*)v10) {
				*(_DWORD*)v10 = v8++;
				v13 = v8;
				v11 = v9;
				if (v9 < result) {
					v12 = (int)(v10 + 32);
					do {
						if (!_strnicmp((const char*)v10 + 4, (const char*)(v12 + 4), 6u))
							*(_DWORD*)v12 = *(_DWORD*)v10;
						result = dword_5d4594_1548476;
						++v11;
						v12 += 32;
					} while (v11 < *(int*)&dword_5d4594_1548476);
					v8 = v13;
				}
			}
			++v9;
			v10 += 32;
		} while (v9 - 1 < result);
	}
	return result;
}
// 4D0E3E: variable 'v2' is possibly undefined

//----- (004D0F30) --------------------------------------------------------
void sub_4D0F30() {
	int v0;              // ecx
	unsigned __int8* v1; // eax

	v0 = dword_5d4594_1548476;
	dword_5d4594_1548480 = 1000;
	if (dword_5d4594_1548476 > 0) {
		v1 = &byte_5D4594[1525160];
		do {
			*((_DWORD*)v1 - 1) = 0;
			*(_DWORD*)v1 = 0;
			v1 += 32;
			--v0;
		} while (v0);
	}
}

//----- (004D0F60) --------------------------------------------------------
char* sub_4D0F60() // quest setup 2
{
	int v1;               // esi
	unsigned __int8* v2;  // ecx
	int v3;               // edx
	int v4;               // ebx
	unsigned __int8* v5;  // esi
	int v6;               // ebp
	unsigned __int8* v7;  // eax
	int v8;               // ecx
	int v9;               // edx
	int v10;              // ecx
	unsigned __int8* v11; // eax
	int v12;              // eax
	int v13;              // edi
	int v14;              // edx
	unsigned __int8* i;   // ecx
	int v16;              // [esp+4h] [ebp-8h]

	if (!dword_5d4594_1548476)
		return 0;
	if (dword_5d4594_1548476 == 1)
		return (char*)&byte_5D4594[1525136];
	v1 = 0;
	v16 = 0;
	if (*(int*)&dword_5d4594_1548476 <= 0)
		return (char*)&byte_5D4594[32 * nox_common_randomInt_415FA0(0, dword_5d4594_1548476 - 1) +
					   1525136];
	v2 = &byte_5D4594[1525156];
	v3 = dword_5d4594_1548476;
	do {
		if (*(_DWORD*)v2 > v1) {
			v16 = *(_DWORD*)v2;
			v1 = *(_DWORD*)v2;
		}
		v2 += 32;
		--v3;
	} while (v3);
	if (!v1)
		return (char*)&byte_5D4594[32 * nox_common_randomInt_415FA0(0, dword_5d4594_1548476 - 1) +
					   1525136];
	v4 = 1;
	v5 = &byte_5D4594[1525156];
	v6 = dword_5d4594_1548476;
	do {
		if (dword_5d4594_1548476 > 1) {
			v7 = &byte_5D4594[1525188];
			v8 = dword_5d4594_1548476 - 1;
			do {
				if (*(_DWORD*)v5 != *(_DWORD*)v7)
					v4 = 0;
				v7 += 32;
				--v8;
			} while (v8);
		}
		v5 += 32;
		--v6;
	} while (v6);
	if (v4 == 1)
		++v16;
	v9 = 0;
	v10 = 0;
	v11 = &byte_5D4594[1525132];
	do {
		if (*((_DWORD*)v11 + 6) < v16 && v10 != *(_DWORD*)&byte_587000[191880] &&
		    *(_DWORD*)v11 != *(_DWORD*)&byte_5D4594[32 * *(_DWORD*)&byte_587000[191880] + 1525132] &&
		    dword_5d4594_1548480 - *((_DWORD*)v11 + 7) > 4) {
			++v9;
		}
		++v10;
		v11 += 32;
	} while (v10 < *(int*)&dword_5d4594_1548476);
	v12 = nox_common_randomInt_415FA0(0, v9 - 1);
	v13 = 0;
	v14 = 0;
	if (*(int*)&dword_5d4594_1548476 <= 0)
		return (char*)&byte_5D4594[32 * v12 + 1525136];
	for (i = &byte_5D4594[1525132];; i += 32) {
		if (*((_DWORD*)i + 6) >= v16 || v14 == *(_DWORD*)&byte_587000[191880] ||
		    *(_DWORD*)i == *(_DWORD*)&byte_5D4594[32 * *(_DWORD*)&byte_587000[191880] + 1525132] ||
		    dword_5d4594_1548480 - *((_DWORD*)i + 7) <= 4) {
			goto LABEL_36;
		}
		if (v13 == v12)
			break;
		++v13;
	LABEL_36:
		if (++v14 >= *(int*)&dword_5d4594_1548476)
			return (char*)&byte_5D4594[32 * v12 + 1525136];
	}
	return (char*)&byte_5D4594[32 * v14 + 1525136];
}

//----- (004D11A0) --------------------------------------------------------
_DWORD* sub_4D11A0() {
	_DWORD* result; // eax

	result = *(_DWORD**)&byte_5D4594[1548504];
	if (!*(_DWORD*)&byte_5D4594[1548504]) {
		result = sub_425760(&byte_5D4594[1548492]);
		*(_DWORD*)&byte_5D4594[1548504] = 1;
	}
	return result;
}

//----- (004D11D0) --------------------------------------------------------
void sub_4D11D0() {
	int* result; // eax
	int* v1;     // esi
	int* v2;     // edi

	result = sub_425890((int*)&byte_5D4594[1548492]);
	v1 = result;
	if (result) {
		do {
			v2 = sub_4258A0(v1);
			sub_425920((_DWORD**)v1);
			free(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (004D1210) --------------------------------------------------------
void* __cdecl sub_4D1210(int a1) {
	void* result; // eax
	void* v2;     // esi
	_DWORD* v3;   // eax

	result = (void*)sub_4D12A0(a1);
	if (!result) {
		result = sub_417090(a1);
		v2 = result;
		if (result) {
			v3 = nox_malloc(0x10u);
			v3[3] = v2;
			result = sub_4258E0((int)&byte_5D4594[1548492], v3);
		}
	}
	return result;
}

//----- (004D1250) --------------------------------------------------------
int* __cdecl sub_4D1250(int a1) {
	int* result; // eax
	int* v2;     // esi

	result = sub_425890((int*)&byte_5D4594[1548492]);
	v2 = result;
	if (result) {
		while (*(unsigned __int8*)(v2[3] + 2064) != a1) {
			result = sub_4258A0(v2);
			v2 = result;
			if (!result)
				return result;
		}
		sub_425920((_DWORD**)v2);
		free(v2);
	}
	return result;
}

//----- (004D12A0) --------------------------------------------------------
int __cdecl sub_4D12A0(int a1) {
	int* v1; // eax

	v1 = sub_425890((int*)&byte_5D4594[1548492]);
	if (!v1)
		return 0;
	while (*(unsigned __int8*)(v1[3] + 2064) != a1) {
		v1 = sub_4258A0(v1);
		if (!v1)
			return 0;
	}
	return 1;
}

//----- (004D12E0) --------------------------------------------------------
void __cdecl sub_4D12E0(int a1) {
	int v1;     // edi
	int v2;     // esi
	int v3;     // edi
	_DWORD* v4; // eax
	int v5;     // esi
	_DWORD* v6; // eax
	int i;      // esi
	int v11[3]; // [esp+0h] [ebp-Ch]

	v11[0] = 25;
	v11[1] = 25;
	v11[2] = 25;
	sub_40A4D0(0x80000);
	sub_516F30();
	sub_421B10();
	sub_469B90(v11);
	if (nox_common_gameFlags_check_40A5C0(2))
		sub_4349C0(v11);
	sub_511E60();
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v1 = a1;
		sub_4FCEB0(a1);
	} else {
		sub_4FCEB0(0);
		v1 = a1;
	}
	sub_4FF790();
	v2 = sub_4DA7C0();
	if (v2) {
		do {
			v3 = *(_DWORD*)(v2 + 748);
			sub_4F7950(v2);
			*(_DWORD*)(v3 + 296) = 0;
			sub_4E7A60(v2, 1);
			v4 = *(_DWORD**)(v3 + 280);
			*(_WORD*)(v3 + 160) = 0;
			if (v4)
				sub_510DC0(v4);
			*(_DWORD*)(v3 + 280) = 0;
			if (*(int(__cdecl**)(_DWORD*))(v2 + 744) == sub_4FAB20)
				sub_4FA700(v2);
			v2 = sub_4DA7F0(v2);
		} while (v2);
		v1 = a1;
	}
	do {
		sub_4DAC00();
		sub_4E5BF0(v1);
		sub_4FEEF0();
		sub_4E5EC0();
	} while (sub_4DA870());
	v5 = sub_4DA790();
	if (v5) {
		do {
			*(_DWORD*)(v5 + 520) = 0;
			if (sub_4E5B50(v5) && *(_BYTE*)(v5 + 8) & 2) {
				v6 = *(_DWORD**)(v5 + 748);
				v6[309] = -1;
				v6[307] = -1;
				v6[317] = -1;
				v6[311] = -1;
				v6[313] = -1;
				v6[315] = -1;
				v6[319] = -1;
				v6[321] = -1;
				v6[323] = -1;
				v6[325] = -1;
				v6[98] = 0;
				v6[101] = 0;
			}
			v5 = sub_4DA7A0(v5);
		} while (v5);
		v1 = a1;
	}
	sub_50D1C0();
	for (i = sub_4DA840(); i; i = sub_4DA850(i)) {
		if (sub_4E5B80(i))
			sub_4E81D0(i);
	}
	sub_4ECFE0();
	sub_511E20();
	sub_410160();
	if (v1)
		sub_4FCAC0(v1, 1);
	else
		sub_4FCAC0(0, 0);
	for (int j = 0; j < ptr_5D4594_2650668_cap * 44; j += 44) {
		for (int k = 0; k < ptr_5D4594_2650668_cap; k++) {
			*(_BYTE*)((_DWORD)(ptr_5D4594_2650668[k]) + j) = 0;
			*(_DWORD*)((_DWORD)(ptr_5D4594_2650668[k]) + j + 4) = 255;
			*(_DWORD*)((_DWORD)(ptr_5D4594_2650668[k]) + j + 24) = 255;
			sub_422200((_DWORD)(ptr_5D4594_2650668[k]) + j + 4);
			sub_422200((_DWORD)(ptr_5D4594_2650668[k]) + j + 24);
		}
	}
	sub_410730();
	sub_410810();
	sub_579DD0();
	sub_511840();
	sub_5117B0();
	sub_5112F0();
	sub_57C440();
	sub_57C000();
	sub_510E50();
	sub_4D1610();
	sub_4EC5B0();
	sub_50E360();
	sub_50D7E0();
	sub_4E4F80();
	nox_common_gameFlags_unset_40A540(0x80000);
}
// 511840: using guessed type int sub_511840(void);

//----- (004D15B0) --------------------------------------------------------
void sub_4D15B0() { *(_DWORD*)&byte_5D4594[1548508] = 1; }

//----- (004D15C0) --------------------------------------------------------
void sub_4D15C0() { *(_DWORD*)&byte_5D4594[1548508] = 0; }

//----- (004D15D0) --------------------------------------------------------
int sub_4D15D0() { return *(_DWORD*)&byte_5D4594[1548508]; }

//----- (004D15E0) --------------------------------------------------------
void sub_4D15E0() { nox_srand(0x141Eu); }

//----- (004D1600) --------------------------------------------------------
int sub_4D1600() { return *(_DWORD*)&byte_5D4594[1548528]; }

//----- (004D1610) --------------------------------------------------------
void sub_4D1610() { *(_DWORD*)&byte_5D4594[1548528] = 0; }

//----- (004D1620) --------------------------------------------------------
int sub_4D1620() {
	int result; // eax

	if (*(_DWORD*)&byte_5D4594[1548532])
		result = *(_DWORD*)&byte_5D4594[1548532] + 56;
	else
		result = 0;
	return result;
}

//----- (004D1630) --------------------------------------------------------
int sub_4D1630() {
	int result; // eax

	result = sub_419B30();
	if (result) {
		sub_424DF0();
		sub_57B200();
		result = sub_517010() != 0;
	}
	return result;
}

//----- (004D1650) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
_DWORD* sub_4D1650() {
	sub_419DB0();
	return sub_5174F0();
}

//----- (004D1660) --------------------------------------------------------
int sub_4D1660() {
	int result; // eax
	int v1;     // eax

	sub_4D15C0();
	dword_5d4594_2649712 = 2147483648;
	dword_5d4594_3843628 = 0;
	sub_4D7B40();
	sub_41E4B0(0);
	sub_4E3C70();
	sub_56F1C0();
	sub_416E30();
	sub_40EE60();
	sub_4E4EF0();
	sub_4E4ED0();
	result = sub_501860();
	if (result) {
		result = sub_4E2B60();
		if (result) {
			sub_4463E0(1);
			sub_417C60();
			sub_4259C0();
			sub_4D7C60();
			sub_4E3320();
			result = sub_518770();
			if (result) {
				nox_common_gameFlags_check_40A5C0(0x200000);
				result = sub_4E3360(0x1388u);
				if (result) {
					result = sub_517AE0();
					if (result) {
						result = sub_50AB90();
						if (result) {
							result = sub_4FC9B0();
							if (result) {
								result = sub_5112C0();
								if (result) {
									result = sub_57C410();
									if (result) {
										result = sub_57BFB0();
										if (result) {
											result = sub_4ECA60();
											if (result) {
												result = sub_50E2A0();
												if (result) {
													result =
													    sub_50D780();
													if (result) {
														result =
														    sub_5066D0();
														if (result) {
															result =
															    sub_4FF730();
															if (result) {
																result =
																    sub_517520();
																if (result) {
																	sub_416920();
																	if (!nox_common_gameFlags_check_40A5C0(
																		2048)) {
																		v1 =
																		    sub_40A430();
																		*(_DWORD*)&byte_5D4594
																		    [1548516] =
																		    sub_4DEBC0(
																			v1);
																		if (!nox_common_gameFlags_check_40A5C0(
																			0x2000000))
																			sub_413CC0();
																	}
																	sub_4FB990();
																	result =
																	    sub_516EE0();
																	if (result) {
																		sub_421B10();
																		sub_4DB0A0();
																		sub_4D0F30();
																		result =
																		    1;
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
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (004D17F0) --------------------------------------------------------
int sub_4D17F0() {
	int result; // eax

	sub_4E79B0(0);
	if (!memcmp(nox_server_currentMapGetFilename_409B30(), &byte_5D4594[1548720], 1u))
		sub_409D70((char*)&byte_587000[196452]);
	sub_519870();
	result = sub_4D1860_server();
	if (result) {
		sub_43DDF0(sub_4D2580_server);
		sub_40EE90(1);
		sub_40A4D0(0x20000);
		sub_4DEF00();
		sub_40A690();
		result = 1;
	}
	return result;
}

//----- (004D23C0) --------------------------------------------------------
int sub_4D23C0() {
	char* i; // esi
	int v2;  // [esp-Ch] [ebp-14h]

	for (i = sub_416EA0(); i; i = sub_416EE0((int)i)) {
		if (*((_DWORD*)i + 514)) {
			dword_5d4594_2649712 &= ~(1 << i[2064]);
			v2 = *((_DWORD*)i + 514);
			i[3676] = 2;
			sub_4EF7D0(v2, 1, 0);
			*((_DWORD*)i + 535) = 0;
			*((_DWORD*)i + 534) = 0;
		}
	}
	sub_51A100();
	nox_common_gameFlags_unset_40A540(0x20000);
	sub_4DEF00();
	sub_40A690();
	return 1;
}

//----- (004D2450) --------------------------------------------------------
char* __cdecl sub_4D2450(char* a1) {
	char* v1;      // eax
	char v3[1024]; // [esp+4h] [ebp-DB8h]
	char v4[1024]; // [esp+404h] [ebp-9B8h]
	char v5[1464]; // [esp+804h] [ebp-5B8h]

	qmemcpy(v5, &byte_5D4594[3801836], sizeof(v5));
	strncpy(v4, a1, strlen(a1) - 4);
	v4[strlen(a1) - 4] = 0;
	sub_4CFE10(v4);
	sub_4CFDF0(*(int*)&byte_5D4594[3803228]);
	qmemcpy(&byte_5D4594[3801836], v5, 0x5B8u);
	*(_DWORD*)&byte_5D4594[1548524] = 1;
	strcpy(v3, a1);
	v1 = strchr(v3, 58);
	if (v1) {
		*v1 = 0;
		strcpy((char*)&byte_5D4594[1548536], v1 + 1);
		*(_DWORD*)&byte_5D4594[1548664] = 1;
	} else {
		*(_DWORD*)&byte_5D4594[1548664] = 0;
	}
	if (sub_51A130())
		sub_5198B0(0);
	return sub_409D70(v3);
}

//----- (004D2FF0) --------------------------------------------------------
char* sub_4D2FF0() {
	char* result; // eax
	int v1;       // esi

	result = (char*)sub_40AA70(0);
	if (result || (result = sub_416EA0(), (v1 = (int)result) == 0)) {
		dword_5d4594_1548704 = 1;
	} else {
		do {
			if (*(_BYTE*)(v1 + 3680) & 1)
				sub_4174F0(v1, 256);
			result = sub_416EE0(v1);
			v1 = (int)result;
		} while (result);
		dword_5d4594_1548704 = 1;
	}
	return result;
}

//----- (004D3050) --------------------------------------------------------
char* sub_4D3050() {
	char* result; // eax
	bool v1;      // zf
	int i;        // esi
	char v3[5];   // [esp+0h] [ebp-8h]

	v3[0] = -41;
	if (!dword_5d4594_1548700 ||
	    (result = sub_416EE0(*(int*)&dword_5d4594_1548700), (dword_5d4594_1548700 = result) == 0)) {
		result = sub_416EA0();
		dword_5d4594_1548700 = result;
	}
	if (result) {
		while (result[2064] != 31) {
			v1 = sub_554240((unsigned __int8)result[2064]) == 0;
			result = *(char**)&dword_5d4594_1548700;
			if (!v1)
				break;
			result = sub_416EE0(*(int*)&dword_5d4594_1548700);
			dword_5d4594_1548700 = result;
			if (!result) {
				result = sub_416EA0();
				dword_5d4594_1548700 = result;
			}
		}
		if (result) {
			*(_WORD*)&v3[1] = *((_WORD*)result + 1030);
			*(_WORD*)&v3[3] = sub_554240((unsigned __int8)result[2064]);
			result = sub_416EA0();
			for (i = (int)result; result; i = (int)result) {
				sub_40EBC0(*(unsigned __int8*)(i + 2064), 1, v3, 5);
				result = sub_416EE0(i);
			}
		}
	}
	return result;
}

//----- (004D3200) --------------------------------------------------------
BOOL sub_4D3200() {
	char* v0;            // eax
	CHAR FileName[1024]; // [esp+0h] [ebp-400h]

	sub_50D1E0();
	sub_4DB100();
	sub_421B10();
	sub_516F10();
	sub_4FF770();
	sub_4D33B0();
	sub_4D3530();
	sub_416E30();
	sub_446490((void*)1);
	sub_4259F0();
	sub_4D12E0(0);
	sub_40A380();
	sub_4E4DE0();
	sub_57C460();
	sub_57C030();
	sub_511310();
	sub_4FCA80();
	sub_50ABF0();
	sub_517B30();
	sub_5018D0();
	sub_4ECA90();
	sub_506720();
	sub_50D820();
	sub_50E300();
	sub_416950();
	sub_4E3420();
	sub_4E2A20();
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		sub_4DEC60(*(unsigned int*)&byte_5D4594[1548516]);
		if (!nox_common_gameFlags_check_40A5C0(0x2000000))
			sub_413D00();
	}
	sub_56F3B0();
	nullsub_23();
	sub_40EE60();
	v0 = sub_409E10();
	nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v0);
	return DeleteFileA(FileName);
}
// 4E3440: using guessed type void nullsub_23(void);

//----- (004D3310) --------------------------------------------------------
int __cdecl sub_4D3310(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1548716] = a1;
	return result;
}

//----- (004D3320) --------------------------------------------------------
int sub_4D3320() { return *(_DWORD*)&byte_5D4594[1548716]; }

//----- (004D3330) --------------------------------------------------------
int sub_4D3330() {
	int result; // eax

	result = nox_common_gameFlags_check_40A5C0(0x2000000);
	if (result) {
		sub_413D30((char*)&byte_587000[197384]);
		sub_43DDD0(0);
		result = sub_43DE60();
	}
	return result;
}

//----- (004D3360) --------------------------------------------------------
void sub_4D3360() { nox_srand(0x141Fu); }

//----- (004D3370) --------------------------------------------------------
int __cdecl sub_4D3370(char* a1) {
	dword_587000_197424 = _open(a1, 33537, 384);
	if (*(int*)&dword_587000_197424 == -1)
		return 0;
	*(_DWORD*)&nox_common_engineFlags |= 0x200000u;
	return 1;
}

//----- (004D33B0) --------------------------------------------------------
unsigned int sub_4D33B0() {
	unsigned int result; // eax

	if (*(int*)&dword_587000_197424 != -1)
		_close(*(int*)&dword_587000_197424);
	dword_587000_197424 = -1;
	result = *(_DWORD*)&nox_common_engineFlags & 0xFFDFFFFF;
	*(_DWORD*)&nox_common_engineFlags &= 0xFFDFFFFF;
	return result;
}

//----- (004D33E0) --------------------------------------------------------
int __cdecl sub_4D33E0(void* a1, int a2) {
	int result; // eax

	result = dword_587000_197424;
	if (*(int*)&dword_587000_197424 != -1 && a1 && a2 >= 1) {
		_write(*(int*)&dword_587000_197424, &byte_5D4594[2598000], 4u);
		_write(*(int*)&dword_587000_197424, &byte_587000[197432], 1u);
		_write(*(int*)&dword_587000_197424, &a2, 4u);
		result = _write(*(int*)&dword_587000_197424, a1, 2 * a2);
	}
	return result;
}

//----- (004D3450) --------------------------------------------------------
int __cdecl sub_4D3450(int a1, void* a2, unsigned int a3) {
	int result; // eax

	result = dword_587000_197424;
	if (*(int*)&dword_587000_197424 != -1) {
		_write(*(int*)&dword_587000_197424, &byte_5D4594[2598000], 4u);
		_write(*(int*)&dword_587000_197424, &byte_587000[197433], 1u);
		_write(*(int*)&dword_587000_197424, (const void*)(a1 + 2064), 1u);
		_write(*(int*)&dword_587000_197424, &a3, 4u);
		result = _write(*(int*)&dword_587000_197424, a2, a3);
	}
	return result;
}

//----- (004D34C0) --------------------------------------------------------
int __cdecl sub_4D34C0(char* a1) {
	char* v2; // eax

	dword_587000_197428 = _open(a1, 0x8000);
	if (*(int*)&dword_587000_197428 == -1)
		return 0;
	dword_5d4594_1548732 = 0;
	dword_5d4594_1548736 = 0;
	*(_DWORD*)&byte_5D4594[1548728] = 0;
	byte_5D4594[1548724] = 0;
	*(_DWORD*)&nox_common_engineFlags |= 0x400000u;
	v2 = sub_417040(255);
	sub_4E6860((int)v2, 0, 1);
	return 1;
}

//----- (004D3530) --------------------------------------------------------
void sub_4D3530() {
	char* v0; // eax

	if (*(int*)&dword_587000_197428 != -1)
		_close(*(int*)&dword_587000_197428);
	dword_587000_197428 = -1;
	dword_5d4594_1548732 = 0;
	dword_5d4594_1548736 = 0;
	*(_DWORD*)&nox_common_engineFlags &= 0xFFBFFFFF;
	v0 = sub_417040(255);
	sub_4E6AA0((int)v0);
}

//----- (004D3860) --------------------------------------------------------
void __cdecl sub_4D3860(void* a1) {
	if (*(_DWORD*)&nox_common_engineFlags & 0x200000 && (*(int*)&dword_587000_197424 != -1)) {
		sub_415F30(*(int*)&dword_587000_197424);
		_write(*(int*)&dword_587000_197424, a1, 0x99u);
	} else if (*(_DWORD*)&nox_common_engineFlags & 0x400000) {
		if (*(int*)&dword_587000_197428 != -1) {
			sub_415F50(*(int*)&dword_587000_197428);
			_read(*(int*)&dword_587000_197428, a1, 0x99u);
		}
	}
}

//----- (004D38D0) --------------------------------------------------------
int sub_4D38D0() {
	int result; // eax
	int v2;     // [esp+0h] [ebp-4h]

	if (*(_DWORD*)&nox_common_engineFlags & 0x200000 && *(int*)&dword_587000_197424 != -1) {
		_write(*(int*)&dword_587000_197424, &byte_5D4594[2598000], 4u);
		_write(*(int*)&dword_587000_197424, &byte_587000[197434], 1u);
		*(_DWORD*)&byte_5D4594[1549764] = nox_server_currentMapGetFilename_409B30();
		byte_5D4594[1548725] = strlen(*(const char**)&byte_5D4594[1549764]) + 1;
		_write(*(int*)&dword_587000_197424, &byte_5D4594[1548725], 1u);
		_write(*(int*)&dword_587000_197424, *(const void**)&byte_5D4594[1549764], byte_5D4594[1548725]);
		v2 = 66458;
		_write(*(int*)&dword_587000_197424, &v2, 4u);
		result = 0;
	} else if (*(_DWORD*)&nox_common_engineFlags & 0x400000 && *(int*)&dword_587000_197428 != -1) {
		result = sub_4D3580_net_playback(0);
	} else {
		result = 0;
	}
	return result;
}

//----- (004D39B0) --------------------------------------------------------
void sub_4D39B0() {
	if (*(_DWORD*)&nox_common_engineFlags & 0x200000) {
		if (*(int*)&dword_587000_197424 != -1) {
			_write(*(int*)&dword_587000_197424, &byte_5D4594[2598000], 4u);
			_write(*(int*)&dword_587000_197424, &byte_587000[197435], 1u);
		}
	}
}

//----- (004D39F0) --------------------------------------------------------
int __cdecl sub_4D39F0(const char* a3) {
	unsigned int v1;      // ecx
	char v2;              // dl
	unsigned __int8* v3;  // edi
	const char* v4;       // esi
	int v5;               // edx
	int v6;               // eax
	unsigned __int8* v7;  // edi
	unsigned int v8;      // ecx
	unsigned __int8* v9;  // edi
	const char* v10;      // esi
	unsigned __int8* v11; // edi
	int v12;              // ecx
	int v13;              // edx
	int v14;              // eax
	char* v15;            // edi
	unsigned __int8 v16;  // cl
	int result;           // eax
	char v18[2048];       // [esp+10h] [ebp-800h]

	*(_QWORD*)&byte_5D4594[1549772] = sub_416BB0();
	memset(&byte_5D4594[3835340], 0, 0x48u);
	*(_DWORD*)&byte_5D4594[3835340] = 0;
	*(_DWORD*)&byte_5D4594[3835344] = 0;
	dword_5d4594_3835348 = 0;
	dword_5d4594_3835356 = 255;
	dword_5d4594_3835352 = 0;
	*(_DWORD*)&byte_5D4594[3835360] = 0;
	*(_DWORD*)&byte_5D4594[3835364] = 1;
	*(_DWORD*)&byte_5D4594[3835368] = 1;
	*(_DWORD*)&byte_5D4594[3835372] = 1;
	*(_DWORD*)&byte_5D4594[3835376] = 0;
	*(_DWORD*)&byte_5D4594[3835380] = 0;
	*(_DWORD*)&byte_5D4594[3835384] = 0;
	dword_5d4594_3835388 = 0;
	*(_DWORD*)&byte_5D4594[3835392] = 1;
	dword_5d4594_3835396 = -1;
	byte_5D4594[3835400] = 2;
	*(_DWORD*)&byte_5D4594[3835404] = 0;
	*(_DWORD*)&byte_5D4594[3835408] = 0;
	sub_51D0E0();
	if (a3) {
		v1 = strlen(a3) + 1;
		v2 = v1;
		v1 >>= 2;
		qmemcpy(&byte_5D4594[3841580], a3, 4 * v1);
		v4 = &a3[4 * v1];
		v3 = &byte_5D4594[4 * v1 + 3841580];
		LOBYTE(v1) = v2;
		v5 = *(_DWORD*)&byte_587000[197560];
		qmemcpy(v3, v4, v1 & 3);
		strcpy((char*)&byte_5D4594[3835436], a3);
		v6 = *(_DWORD*)&byte_587000[197564];
		v7 = &byte_5D4594[strlen((const char*)&byte_5D4594[3835436]) + 3835436];
		*(_DWORD*)v7 = *(_DWORD*)&byte_587000[197556];
		*((_DWORD*)v7 + 1) = v5;
		*((_DWORD*)v7 + 2) = v6;
		v8 = strlen(a3) + 1;
		LOBYTE(v5) = v8;
		v8 >>= 2;
		qmemcpy(&byte_5D4594[3837484], a3, 4 * v8);
		v10 = &a3[4 * v8];
		v9 = &byte_5D4594[4 * v8 + 3837484];
		LOBYTE(v8) = v5;
		LOWORD(v5) = *(_WORD*)&byte_587000[197576];
		qmemcpy(v9, v10, v8 & 3);
		v11 = &byte_5D4594[strlen((const char*)&byte_5D4594[3837484]) + 3837485];
		v12 = *(_DWORD*)&byte_587000[197572];
		*(_DWORD*)--v11 = *(_DWORD*)&byte_587000[197568];
		LOBYTE(v6) = byte_587000[197578];
		*((_DWORD*)v11 + 1) = v12;
		*((_WORD*)v11 + 4) = v5;
		v11[10] = v6;
		DeleteFileA((LPCSTR)&byte_5D4594[3835436]);
		DeleteFileA((LPCSTR)&byte_5D4594[3837484]);
	} else {
		byte_5D4594[3841580] = byte_5D4594[1549780];
		byte_5D4594[3839532] = byte_5D4594[1549784];
		byte_5D4594[3835436] = byte_5D4594[1549788];
		byte_5D4594[3837484] = byte_5D4594[1549792];
	}
	sub_5028E0();
	v13 = *(_DWORD*)&byte_587000[197584];
	strcpy(v18, a3);
	v14 = *(_DWORD*)&byte_587000[197588];
	v15 = &v18[strlen(v18)];
	*(_DWORD*)v15 = *(_DWORD*)&byte_587000[197580];
	v16 = byte_587000[197592];
	*((_DWORD*)v15 + 1) = v13;
	*((_DWORD*)v15 + 2) = v14;
	v15[12] = v16;
	sub_502A50(v18);
	sub_502AB0(v18);
	result = sub_502B10();
	dword_5d4594_3835312 = 0;
	*(_DWORD*)&byte_5D4594[3835308] = 0;
	*(_DWORD*)&byte_5D4594[1599580] = 0;
	return result;
}
// 4D39F0: using guessed type char var_800[2048];

//----- (004D3C30) --------------------------------------------------------
__int64 sub_4D3C30() {
	sub_503F40();
	sub_51D0E0();
	sub_502DF0();
	return sub_416BB0();
}

//----- (004D3C50) --------------------------------------------------------
void __cdecl sub_4D3C50(const void* a1) { qmemcpy(&byte_5D4594[3835340], a1, 0x48u); }

//----- (004D3C70) --------------------------------------------------------
unsigned __int8* sub_4D3C70() { return &byte_5D4594[3835340]; }

//----- (004D3C80) --------------------------------------------------------
_DWORD* __cdecl sub_4D3C80(_DWORD* a1) {
	_DWORD* result; // eax
	int v2;         // ebp
	int v3;         // ecx
	int v4;         // edi
	int v5;         // esi
	int v6;         // edx
	int v7;         // ebx
	int v8;         // ecx
	int v9;         // esi
	int v10;        // [esp+10h] [ebp-10h]
	int v11;        // [esp+14h] [ebp-Ch]
	int v12;        // [esp+1Ch] [ebp-4h]

	result = a1;
	v2 = a1[3];
	v10 = *a1;
	v3 = a1[1];
	v11 = a1[1];
	if (v2 < v3) {
		v3 = a1[3];
		v10 = a1[2];
		v11 = a1[3];
	}
	if (a1[5] < v3) {
		v10 = a1[4];
		v3 = a1[5];
		v11 = a1[5];
	}
	if (a1[7] < v3) {
		v10 = a1[6];
		v11 = a1[7];
	}
	v4 = a1[2];
	v12 = a1[3];
	if (*a1 < v4) {
		v4 = *a1;
		v12 = a1[1];
	}
	if (a1[4] < v4) {
		v4 = a1[4];
		v12 = a1[5];
	}
	v5 = a1[6];
	if (v5 < v4) {
		v4 = a1[6];
		v12 = a1[7];
	}
	v6 = a1[4];
	v7 = a1[5];
	if (*a1 > v6) {
		v6 = *a1;
		v7 = a1[1];
	}
	if (a1[2] > v6) {
		v7 = a1[3];
		v6 = a1[2];
	}
	if (v5 > v6) {
		v6 = a1[6];
		v7 = a1[7];
	}
	v8 = a1[7];
	v9 = a1[6];
	if (a1[1] > v8) {
		v9 = *a1;
		v8 = a1[1];
	}
	if (v2 > v8) {
		v9 = a1[2];
		v8 = a1[3];
	}
	if (a1[5] > v8) {
		v9 = a1[4];
		v8 = a1[5];
	}
	a1[6] = v9;
	*a1 = v10;
	a1[2] = v4;
	a1[7] = v8;
	a1[1] = v11;
	a1[4] = v6;
	a1[5] = v7;
	a1[3] = v12;
	return result;
}

//----- (004D3D90) --------------------------------------------------------
int __cdecl sub_4D3D90(float2* a1, float2* a2) {
	if (!a1 || !a2)
		return 0;
	a2->field_0 = (a1->field_4 + a1->field_0) * 0.70710677 + 2957.0;
	a2->field_4 = (a1->field_4 - a1->field_0) * 0.70710677 + 2956.0;
	if (a2->field_0 <= 80.5)
		a2->field_0 = 82.5;
	if (a2->field_4 <= 80.5)
		a2->field_4 = 81.5;
	if (a2->field_0 >= 5853.5)
		a2->field_0 = 5851.5;
	if (a2->field_4 >= 5853.5)
		a2->field_4 = 5852.5;
	return 1;
}

//----- (004D3E30) --------------------------------------------------------
int __cdecl sub_4D3E30(float2* a1, float2* a2) {
	int result; // eax

	if (!a1 || !a2)
		return 0;
	if (a1->field_0 <= 80.5)
		a1->field_0 = 82.5;
	if (a1->field_4 <= 80.5)
		a1->field_4 = 81.5;
	if (a1->field_0 >= 5853.5)
		a1->field_0 = 5851.5;
	if (a1->field_4 >= 5853.5)
		a1->field_4 = 5852.5;
	result = 1;
	a2->field_0 = (a1->field_0 - 1.0 - a1->field_4) * 0.70710677;
	a2->field_4 = (a1->field_4 + a1->field_0 - 5912.0) * 0.70710677;
	return result;
}

//----- (004D3ED0) --------------------------------------------------------
BOOL __cdecl sub_4D3ED0(float2* a1) {
	BOOL result; // eax
	float v2;    // [esp+0h] [ebp-8h]
	float v3;    // [esp+4h] [ebp-4h]

	result = 0;
	if (a1) {
		v2 = (a1->field_4 + a1->field_0) * 0.70710677 + 2957.0;
		v3 = (a1->field_4 - a1->field_0) * 0.70710677 + 2956.0;
		if (v2 > 80.5 && v3 > 80.5 && v2 < 5853.5 && v3 < 5853.5)
			result = 1;
	}
	return result;
}

//----- (004D3F60) --------------------------------------------------------
int __cdecl sub_4D3F60(int a1) {
	if (a1 != 1 && a1)
		return 0;
	*(_DWORD*)&byte_5D4594[3835408] = 1;
	return 1;
}

//----- (004D3F80) --------------------------------------------------------
int __cdecl sub_4D3F80(int a1) {
	int result; // eax

	switch (a1) {
	case 0:
		result = 1;
		break;
	case 1:
		result = 2;
		break;
	case 2:
		result = 5;
		break;
	case 3:
		result = 0;
		break;
	case 5:
		result = 8;
		break;
	case 6:
		result = 3;
		break;
	case 7:
		result = 6;
		break;
	case 8:
		result = 7;
		break;
	default:
		result = -1;
		break;
	}
	return result;
}

//----- (004D3FF0) --------------------------------------------------------
int __cdecl sub_4D3FF0(int a1) {
	int result; // eax

	switch (a1) {
	case 0:
		result = 3;
		break;
	case 1:
		result = 0;
		break;
	case 2:
		result = 1;
		break;
	case 3:
		result = 6;
		break;
	case 5:
		result = 2;
		break;
	case 6:
		result = 7;
		break;
	case 7:
		result = 8;
		break;
	case 8:
		result = 5;
		break;
	default:
		result = -1;
		break;
	}
	return result;
}

//----- (004D4060) --------------------------------------------------------
float2* __cdecl sub_4D4060(float2* a1, float2* a2, int a3) {
	double v3;      // st7
	double v4;      // st6
	int v5;         // esi
	int v6;         // edx
	int v7;         // ecx
	double v8;      // st7
	float2* result; // eax
	double v10;     // st7
	int v11;        // [esp+Ch] [ebp-8h]
	float v12;      // [esp+10h] [ebp-4h]
	float2* v13;    // [esp+18h] [ebp+4h]

	v3 = a1->field_0 + 11.5;
	v4 = a1->field_4 + 11.5;
	v13 = (float2*)(__int64)(v3 * 0.021739131);
	v12 = v4;
	v11 = (__int64)(v4 * 0.021739131);
	v5 = (int)(__int64)v3 % 46;
	v6 = (__int64)v12 % 46;
	v7 = 2 * a3;
	if (v5 <= v6) {
		if (v7 - v5 <= v6) {
			result = a2;
			a2->field_0 = (double)(int)v13 * 46.0 + 11.0;
			v10 = (double)v11;
			goto LABEL_8;
		}
		v8 = (double)(int)((unsigned __int64)(__int64)(v3 * 0.021739131) - 1) * 46.0;
	LABEL_6:
		result = a2;
		a2->field_0 = v8 + 34.0;
		a2->field_4 = (double)v11 * 46.0 + 11.0;
		return result;
	}
	v8 = (double)(int)v13 * 46.0;
	if (v7 - v5 <= v6)
		goto LABEL_6;
	result = a2;
	a2->field_0 = v8 + 11.0;
	v10 = (double)(int)((unsigned __int64)(__int64)(v4 * 0.021739131) - 1);
LABEL_8:
	result->field_4 = v10 * 46.0 + 34.0;
	return result;
}

//----- (004D4160) --------------------------------------------------------
void sub_4D4160() {
	int v0;                      // edi
	int v1;                      // esi
	int v2;                      // eax
	int v3;                      // eax
	int v4;                      // eax
	char* v5;                    // eax
	char* v6;                    // eax
	float2 v8;                   // [esp+8h] [ebp-808h]
	CHAR FileName[1024];         // [esp+10h] [ebp-800h]
	CHAR ExistingFileName[1024]; // [esp+410h] [ebp-400h]

	sub_40A4D0(0x400000);
	sub_51D4D0((char*)&byte_587000[197596]);
	v8.field_4 = 0.0;
	v8.field_0 = 0.0;
	v0 = 20;
	do {
		v1 = 20;
		do {
			sub_51D5E0(&v8);
			--v1;
			v8.field_0 = v8.field_0 + 32.526913;
		} while (v1);
		--v0;
		v8.field_0 = 0.0;
		v8.field_4 = v8.field_4 + 32.526913;
	} while (v0);
	v8.field_4 = 0.0;
	v8.field_0 = 0.0;
	v2 = sub_5029A0((char*)&byte_587000[197608]);
	sub_503830(v2);
	sub_503B30(&v8);
	v8.field_4 = 65.053825;
	v8.field_0 = 65.053825;
	v3 = sub_5029A0((char*)&byte_587000[197620]);
	sub_503830(v3);
	sub_503B30(&v8);
	v8.field_4 = 195.16147;
	v8.field_0 = 195.16147;
	v4 = sub_5029A0((char*)&byte_587000[197632]);
	sub_503830(v4);
	sub_503B30(&v8);
	v5 = sub_409E10();
	nox_sprintf(FileName, "%s\\nc.obj", v5);
	v6 = sub_409E10();
	nox_sprintf(ExistingFileName, "%s\\blend.obj", v6);
	DeleteFileA(FileName);
	MoveFileA(ExistingFileName, FileName);
	nox_common_gameFlags_unset_40A540(0x400000);
}

//----- (004D42D0) --------------------------------------------------------
int __cdecl sub_4D42D0(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1550916 = a1;
	return result;
}

//----- (004D42E0) --------------------------------------------------------
unsigned int __cdecl sub_4D42E0(const char* a1) {
	unsigned int result; // eax

	result = strlen(a1) + 1;
	qmemcpy(&byte_587000[197860], a1, result);
	return result;
}

//----- (004D4310) --------------------------------------------------------
char* sub_4D4310() { return (char*)&byte_587000[197860]; }

//----- (004D4320) --------------------------------------------------------
BOOL sub_4D4320() {
	int v0;                      // esi
	int v1;                      // eax
	char* v2;                    // eax
	char* v3;                    // eax
	BOOL result;                 // eax
	int i;                       // eax
	char* v6;                    // eax
	char* v7;                    // eax
	char* v8;                    // [esp-8h] [ebp-C10h]
	char* v9;                    // [esp-4h] [ebp-C0Ch]
	char* v10;                   // [esp-4h] [ebp-C0Ch]
	CHAR PathName[1024];         // [esp+8h] [ebp-C00h]
	CHAR FileName[1024];         // [esp+408h] [ebp-800h]
	CHAR ExistingFileName[1024]; // [esp+808h] [ebp-400h]

	v0 = 100;
	sub_4D12E0(1);
	sub_40A4D0(0x400000);
	sub_4DA3C0(&byte_5D4594[1550924]);
	memset(&byte_5D4594[3801836], 0, 0x5B8u);
	while (1) {
		v1 = sub_4D44E0();
		if (v1 == 1)
			break;
		if (v1) {
			if (--v0)
				continue;
		}
		return 0;
	}
	v2 = sub_409E10();
	nox_sprintf(FileName, "%s\\nc.obj", v2);
	v3 = sub_409E10();
	nox_sprintf(ExistingFileName, "%s\\blend.obj", v3);
	if (_access(FileName, 0) == -1 || (result = DeleteFileA(FileName))) {
		if (_access(ExistingFileName, 0) == -1 || (result = MoveFileA(ExistingFileName, FileName))) {
			for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
				*(_DWORD*)(i + 44) = 0;
			sub_4D5DB0((int)&byte_5D4594[3801836]);
			v9 = sub_4D4310();
			v6 = sub_409E10();
			nox_sprintf(PathName, "%s\\Maps\\$%s", v6, v9);
			_mkdir(PathName);
			v10 = sub_4D4310();
			v8 = sub_4D4310();
			v7 = sub_409E10();
			nox_sprintf(PathName, "%s\\Maps\\$%s\\$%s.map", v7, v8, v10);
			if (!sub_51E010(PathName, 1))
				return 0;
			sub_4D12E0(1);
			sub_4DA3E0(*(int*)&byte_5D4594[1550924]);
			*(_DWORD*)&byte_5D4594[1550924] = 0;
			nox_common_gameFlags_unset_40A540(0x400000);
			result = 1;
		}
	}
	return result;
}

//----- (004D44E0) --------------------------------------------------------
int sub_4D44E0() {
	const char* v0; // eax
	int result;     // eax
	int v2;         // esi
	int v3;         // esi
	float* v4;      // edi
	double v5;      // st7
	char* i;        // esi
	int* j;         // esi
	int* k;         // esi
	float2 a2;      // [esp+4h] [ebp-8h]

	dword_5d4594_1550916 = 0;
	v0 = (const char*)sub_57C490("theme");
	if (v0)
		sub_4D42E0(v0);
	sub_526C40(0);
	sub_51D100(0);
	result = sub_51E260((int*)&byte_5D4594[1549796], (int)&byte_587000[197860]);
	if (result) {
		*(_DWORD*)&byte_5D4594[1549864] = (__int64)(*(float*)&byte_5D4594[1549860] * 0.030743772);
		sub_526AB0(*(unsigned int*)&byte_5D4594[1549872]);
		sub_526950();
		result = sub_5213E0();
		if (result) {
			result = sub_520EA0((int)&byte_5D4594[1549796]);
			if (result) {
				sub_4D4F40(&byte_5D4594[1549796]);
				if (sub_525D20((int)&byte_5D4594[1549796])) {
					sub_4D52F0();
					if (sub_5266F0((int)&byte_5D4594[1549796])) {
						if (!sub_526830((int)&byte_5D4594[1549796])) {
							v2 = 0;
						LABEL_25:
							sub_521A40();
							sub_521400();
							sub_520F80();
							sub_520D50(&byte_5D4594[1549796]);
							return v2;
						}
						sub_5259F0(*(int*)&dword_5d4594_1550916, 0, 0.0);
						sub_525AF0(*(int*)&dword_5d4594_1550916);
						if (*(_DWORD*)&byte_5D4594[1549980]) {
							v3 = (__int64)(*(float*)&byte_5D4594[1549860] * 0.030743772);
							v4 = sub_521940(2 * v3 + 1, 2 * v3 + 1);
							v5 = (double)-v3 * 32.526913;
							a2.field_0 = v5;
							a2.field_4 = v5;
							sub_521880(v4, &a2);
							for (i = (char*)sub_521710(); i; i = (char*)sub_521720((int)i))
								sub_521BC0((int)v4, (float2*)(i + 20), *((float*)i + 7),
									   *((float*)i + 8));
							sub_524070((int)&byte_5D4594[1549796], (int)v4);
							sub_524E00((int)&byte_5D4594[1549796], (int)v4);
							sub_522340((int)&byte_5D4594[1549796], (int)v4);
							sub_521A10(v4);
						}
						if (sub_524310((int)&byte_5D4594[1549796])) {
							for (j = (int*)sub_521710(); j; j = (int*)sub_521720((int)j)) {
								if (sub_5238F0(j)) {
									sub_5235F0(156);
									sub_524E00((int)&byte_5D4594[1549796], (int)j);
								}
							}
							for (k = (int*)sub_521710(); k; k = (int*)sub_521720((int)k)) {
								if (!sub_5238F0(k)) {
									sub_5235F0(156);
									sub_524E00((int)&byte_5D4594[1549796], (int)k);
								}
							}
							sub_522D30((int)&byte_5D4594[1549796]);
							sub_4D4790();
							sub_522F40(&byte_5D4594[1549796]);
							sub_521710();
							sub_5228B0_mapgen_populate((int)&byte_5D4594[1549796]);
							v2 = 1;
							goto LABEL_25;
						}
					}
				}
				v2 = 2;
				goto LABEL_25;
			}
		}
	}
	return result;
}

//----- (004D4790) --------------------------------------------------------
float* sub_4D4790() {
	float* result; // eax
	float* v1;     // edi
	int* v2;       // esi
	int v3;        // ebx
	int v4;        // ebp
	int v5;        // eax
	int* v6;       // ebp
	int v7;        // eax
	float* v8;     // eax
	double v9;     // st7
	double v10;    // st7
	float* v11;    // eax
	double v12;    // st7
	double v13;    // st7
	double v14;    // st7
	double v15;    // st7
	int v16;       // eax
	int v17;       // eax
	int* v18;      // ebp
	int v19;       // ecx
	float* v20;    // eax
	double v21;    // st7
	double v22;    // st7
	double v23;    // st7
	float* v24;    // eax
	double v25;    // st7
	double v26;    // st7
	double v27;    // st7
	int v28;       // eax
	int v29;       // [esp+8h] [ebp-40h]
	int v30;       // [esp+Ch] [ebp-3Ch]
	int v31;       // [esp+Ch] [ebp-3Ch]
	int v32;       // [esp+10h] [ebp-38h]
	int v33;       // [esp+14h] [ebp-34h]
	float2 v34;    // [esp+18h] [ebp-30h]
	float2 a2;     // [esp+20h] [ebp-28h]
	float v36;     // [esp+28h] [ebp-20h]
	float v37;     // [esp+2Ch] [ebp-1Ch]
	float2 v38;    // [esp+30h] [ebp-18h]
	float2 v39;    // [esp+38h] [ebp-10h]
	int2 a1;       // [esp+40h] [ebp-8h]

	result = (float*)sub_521710();
	v1 = result;
	v2 = 0;
	if (!result)
		return result;
	v3 = v33;
	do {
		if (*(_DWORD*)v1 != 1)
			goto LABEL_117;
		sub_5235F0(156);
		v4 = 0;
		v32 = 0;
		while (1) {
			if (!*((_BYTE*)v1 + v4 + 216) && sub_526AC0(1, 100) <= *(int*)&byte_5D4594[1549848]) {
				switch (v4) {
				case 0:
				case 1:
					a1.field_0 = (int)v1[1];
					if (v4 == 1)
						a1.field_4 = *((_DWORD*)v1 + 2) + *((_DWORD*)v1 + 4);
					else
						a1.field_4 = *((_DWORD*)v1 + 2) - 1;
					v31 = 0;
					if (*((int*)v1 + 3) <= 0)
						goto LABEL_115;
					while (1) {
						v17 = sub_521290(&a1);
						v18 = (int*)v17;
						if (v17) {
							if ((int*)v17 != v2)
								goto LABEL_72;
							if (*(_BYTE*)(v17 + 52) & 2)
								++v29;
						}
						if ((int*)v17 != v2 || (v19 = v31, v31 == *((_DWORD*)v1 + 3) - 1)) {
						LABEL_72:
							if (v2 && v29 >= 3) {
								v34.field_0 =
								    (double)((v3 + v31) / 2) * 32.526913 + v1[9];
								if (v32 == 1)
									v34.field_4 = v1[12];
								else
									v34.field_4 = v1[10];
								sub_527030(&v34);
								v34.field_0 = v34.field_0 - 16.263456;
								if (v29 < 4)
									sub_527940((char*)&byte_587000[198320]);
								else
									sub_527940((char*)&byte_587000[198304]);
								v20 = sub_5279B0(&v34.field_0);
								if (v20)
									sub_527C60((int)v20, 5);
								a2.field_0 = v34.field_0;
								if (v32 == 1)
									a2.field_4 = v34.field_4 - 32.526913;
								else
									a2.field_4 = v34.field_4;
								sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
								if (sub_5238F0(v2)) {
									v21 = a2.field_4;
									if (v32 == 1)
										v22 = v21 + 32.526913;
									else
										v22 = v21 - 32.526913;
									a2.field_4 = v22;
									sub_521BC0((int)v2, &a2, 32.526913, 32.526913);
								}
								v23 = v34.field_0 + 16.263456;
								if (v29 < 4) {
									v37 = v34.field_4;
								} else {
									v34.field_0 = v23 + 32.526913;
									sub_527030(&v34);
									v34.field_0 = v34.field_0 + 16.263456;
									sub_527940((char*)&byte_587000[198332]);
									v24 = sub_5279B0(&v34.field_0);
									if (v24)
										sub_527C60((int)v24, 3);
									v25 = v34.field_0 - 32.526913;
									v37 = v34.field_4;
									v36 = v25;
									a2.field_0 = v25;
									if (v32 == 1)
										a2.field_4 = v34.field_4 - 32.526913;
									else
										a2.field_4 = v34.field_4;
									sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
									if (sub_5238F0(v2)) {
										v26 = a2.field_4;
										if (v32 == 1)
											v27 = v26 + 32.526913;
										else
											v27 = v26 - 32.526913;
										a2.field_4 = v27;
										sub_521BC0((int)v2, &a2, 32.526913,
											   32.526913);
									}
									v23 = v36;
								}
								v39.field_0 = v23;
								v39.field_4 = v37 - 32.526913;
								v38.field_0 = v23;
								v38.field_4 = v37 + 32.526913;
								sub_522C80(&v39.field_0);
								sub_522C80(&v38.field_0);
								sub_51D3F0(&v39, &v38);
								sub_51D3F0(&v38, &v39);
								if (v32 == 1) {
									sub_522CA0((int)v1, &v39.field_0);
									if (*v2 == 1)
										sub_522CA0((int)v2, &v38.field_0);
								} else {
									sub_522CA0((int)v1, &v38.field_0);
									if (*v2 == 1)
										sub_522CA0((int)v2, &v39.field_0);
								}
								sub_521900((int)v1, (int)v2, v32);
								v28 = sub_523960(v32);
								sub_521900((int)v2, (int)v1, v28);
							}
							v19 = v31;
							v3 = v31;
							v29 = 1;
							v2 = v18;
							if (v18 && *v18 == 1 && v32 == 1)
								v2 = 0;
						}
						++a1.field_0;
						v31 = v19 + 1;
						if (v19 + 1 >= *((_DWORD*)v1 + 3))
							goto LABEL_114;
					}
				case 2:
				case 3:
					if (v4 == 2)
						a1.field_0 = *((_DWORD*)v1 + 1) + *((_DWORD*)v1 + 3);
					else
						a1.field_0 = *((_DWORD*)v1 + 1) - 1;
					v30 = 0;
					a1.field_4 = (int)v1[2];
					if (*((int*)v1 + 4) <= 0)
						goto LABEL_115;
					break;
				default:
					goto LABEL_115;
				}
				while (1) {
					v5 = sub_521290(&a1);
					v6 = (int*)v5;
					if (v5) {
						if ((int*)v5 != v2)
							goto LABEL_19;
						if (*(_BYTE*)(v5 + 52) & 2)
							++v29;
					}
					if ((int*)v5 != v2 || (v7 = v30, v30 == *((_DWORD*)v1 + 4) - 1)) {
					LABEL_19:
						if (v2 && v29 >= 3) {
							if (v32 == 2)
								v34.field_0 = v1[11];
							else
								v34.field_0 = v1[9];
							v34.field_4 = (double)((v3 + v30) / 2) * 32.526913 + v1[10];
							sub_527030(&v34);
							v34.field_4 = v34.field_4 - 16.263456;
							if (v29 < 4)
								sub_527940((char*)&byte_587000[198276]);
							else
								sub_527940((char*)&byte_587000[198260]);
							v8 = sub_5279B0(&v34.field_0);
							if (v8)
								sub_527C60((int)v8, 7);
							if (v32 == 2)
								a2.field_0 = v34.field_0 - 32.526913;
							else
								a2.field_0 = v34.field_0;
							a2.field_4 = v34.field_4;
							sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
							if (sub_5238F0(v2)) {
								v9 = a2.field_0;
								if (v32 == 2)
									v10 = v9 + 32.526913;
								else
									v10 = v9 - 32.526913;
								a2.field_0 = v10;
								sub_521BC0((int)v2, &a2, 32.526913, 32.526913);
							}
							if (v29 < 4) {
								v15 = v34.field_4 + 16.263456;
								v36 = v34.field_0;
							} else {
								v34.field_4 = v34.field_4 + 16.263456 + 32.526913;
								sub_527030(&v34);
								v34.field_4 = v34.field_4 + 16.263456;
								sub_527940((char*)&byte_587000[198288]);
								v11 = sub_5279B0(&v34.field_0);
								if (v11)
									sub_527C60((int)v11, 1);
								v12 = v34.field_4 - 32.526913;
								v36 = v34.field_0;
								v37 = v12;
								if (v32 == 2)
									a2.field_0 = v34.field_0 - 32.526913;
								else
									a2.field_0 = v34.field_0;
								a2.field_4 = v12;
								sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
								if (sub_5238F0(v2)) {
									v13 = a2.field_0;
									if (v32 == 2)
										v14 = v13 + 32.526913;
									else
										v14 = v13 - 32.526913;
									a2.field_0 = v14;
									sub_521BC0((int)v2, &a2, 32.526913, 32.526913);
								}
								v15 = v37;
							}
							v39.field_0 = v36 - 32.526913;
							v39.field_4 = v15;
							v38.field_0 = v36 + 32.526913;
							v38.field_4 = v15;
							sub_522C80(&v39.field_0);
							sub_522C80(&v38.field_0);
							sub_51D3F0(&v39, &v38);
							sub_51D3F0(&v38, &v39);
							if (v32 == 2) {
								sub_522CA0((int)v1, &v39.field_0);
								if (*v2 == 1)
									sub_522CA0((int)v2, &v38.field_0);
							} else {
								sub_522CA0((int)v1, &v38.field_0);
								if (*v2 == 1)
									sub_522CA0((int)v2, &v39.field_0);
							}
							sub_521900((int)v1, (int)v2, v32);
							v16 = sub_523960(v32);
							sub_521900((int)v2, (int)v1, v16);
						}
						v7 = v30;
						v29 = 1;
						v3 = v30;
						v2 = v6;
						if (v6 && *v6 == 1 && v32 == 3)
							v2 = 0;
					}
					++a1.field_4;
					v30 = v7 + 1;
					if (v7 + 1 >= *((_DWORD*)v1 + 4)) {
					LABEL_114:
						v4 = v32;
						break;
					}
				}
			}
		LABEL_115:
			v32 = ++v4;
			if (v4 >= 4)
				break;
			v2 = 0;
		}
		v2 = 0;
	LABEL_117:
		result = (float*)sub_521720((int)v1);
		v1 = result;
	} while (result);
	return result;
}
// 4D47A7: variable 'v33' is possibly undefined
// 4D4853: variable 'v29' is possibly undefined

//----- (004D4F40) --------------------------------------------------------
float* __cdecl sub_4D4F40(_DWORD* a1) {
	float* v1;      // edi
	float* result;  // eax
	double v3;      // st7
	int v4;         // ebp
	int* v5;        // ebx
	float* v6;      // esi
	int v7;         // eax
	double v8;      // st7
	int v9;         // esi
	int v10;        // edi
	int v11;        // ecx
	int v12;        // esi
	int* v13;       // ebp
	int v14;        // edi
	int v15;        // ebx
	float* v16;     // esi
	int v17;        // esi
	int v18;        // ebx
	int v19;        // edi
	signed int v20; // esi
	int v21;        // eax
	float2 v22;     // [esp+10h] [ebp-220h]
	int v24;        // [esp+18h] [ebp-218h]
	int* v25;       // [esp+1Ch] [ebp-214h]
	float* v26;     // [esp+20h] [ebp-210h]
	int v27;        // [esp+24h] [ebp-20Ch]
	float2 v28;     // [esp+28h] [ebp-208h]
	int v30[128];   // [esp+30h] [ebp-200h]

	v1 = 0;
	dword_5d4594_1550912 = 0;
	if (*a1 == 1) {
		v26 = 0;
		v24 = 0;
		v22.field_0 = 0.0;
		v22.field_4 = 0.0;
		v25 = (int*)&byte_587000[197924];
	LABEL_5:
		v4 = 0;
		v5 = &v30[v24];
		v27 = *v25;
		while (1) {
			result = (float*)nox_calloc(1u, 0x178u);
			v6 = result;
			*v5 = (int)result;
			if (!result)
				break;
			v7 = v27;
			*(_DWORD*)v6 = v27;
			switch (v7) {
			case 2:
				v22.field_4 = v22.field_4 - 162.63457;
				*((_DWORD*)v6 + 3) = 4;
				*((_DWORD*)v6 + 4) = 5;
				sub_521900((int)v6, (int)v1, 1);
				sub_521900((int)v1, (int)v6, 0);
				break;
			case 3:
				if (*(_DWORD*)v1 == 4) {
					v22.field_0 = v22.field_0 + 32.526913;
					v8 = v22.field_4 + 130.10765;
				} else {
					v8 = v22.field_4 + 162.63457;
				}
				v22.field_4 = v8;
				*((_DWORD*)v6 + 3) = 4;
				*((_DWORD*)v6 + 4) = 5;
				sub_521900((int)v6, (int)v1, 0);
				sub_521900((int)v1, (int)v6, 1);
				break;
			case 4:
				if (v1) {
					v22.field_0 = v22.field_0 + 162.63457;
					sub_521900((int)v6, (int)v1, 3);
					sub_521900((int)v1, (int)v6, 2);
				}
				*((_DWORD*)v6 + 3) = 5;
				*((_DWORD*)v6 + 4) = 4;
				break;
			case 5:
				if (*(_DWORD*)v1 == 3)
					v22.field_4 = v22.field_4 + 32.526913;
				v22.field_0 = v22.field_0 - 162.63457;
				*((_DWORD*)v6 + 3) = 5;
				*((_DWORD*)v6 + 4) = 4;
				sub_521900((int)v6, (int)v1, 2);
				sub_521900((int)v1, (int)v6, 3);
				if (v4 == 5)
					v26 = v6;
				break;
			default:
				break;
			}
			v28.field_0 = v22.field_0 - 878.22662;
			v28.field_4 = v22.field_4 - 878.22662;
			v6[7] = (double)*((int*)v6 + 3) * 32.526913;
			v6[8] = (double)*((int*)v6 + 4) * 32.526913;
			sub_521880(v6, &v28);
			sub_521730(v6);
			v1 = v6;
			v9 = v24 + 1;
			++v5;
			++v4;
			++v24;
			if (v4 >= 10) {
				++v25;
				if ((int)v25 < (int)&byte_587000[197940])
					goto LABEL_5;
				v10 = v30[0];
				v11 = v9;
				v12 = v30[v9 - 1];
				v13 = &v30[v11];
				sub_521900(v12, v30[0], 2);
				sub_521900(v10, v12, 3);
				v14 = (int)v26;
				v15 = 0;
				v22.field_0 = v26[5];
				v22.field_4 = v26[8] + v26[6];
				while (1) {
					result = (float*)nox_calloc(1u, 0x178u);
					v16 = result;
					*v13 = (int)result;
					if (!result)
						break;
					*(_DWORD*)result = 3;
					*((_DWORD*)result + 3) = 4;
					*((_DWORD*)result + 4) = 5;
					sub_521900((int)result, v14, 0);
					sub_521900(v14, (int)v16, 1);
					v16[7] = (double)*((int*)v16 + 3) * 32.526913;
					v16[8] = (double)*((int*)v16 + 4) * 32.526913;
					sub_521880(v16, &v22);
					sub_521730(v16);
					v14 = (int)v16;
					v17 = v24 + 1;
					++v13;
					++v15;
					v22.field_4 = v22.field_4 + 162.63457;
					++v24;
					if (v15 >= 8) {
						v18 = v17;
						v19 = v17 / 5;
						if (v17 / 5 < 1)
							v19 = 1;
						v20 = sub_526AC0(0, v19);
						do {
							v21 = v30[v20];
							*(_DWORD*)(v21 + 84) = dword_5d4594_1550912;
							dword_5d4594_1550912 = v21;
							v20 += sub_526AC0(1, v19);
						} while (v20 < v18);
						result = (float*)v30[v18 - 1];
						dword_5d4594_1550916 = v30[v18 - 1];
						return result;
					}
				}
				return result;
			}
		}
	} else {
		result = sub_521990((int)a1);
		dword_5d4594_1550916 = result;
		if (result) {
			v3 = (double)(int)a1[17];
			v22.field_0 = 0.0;
			v22.field_4 = v3 * 32.526913 - result[8] + 97.580734;
			sub_521880(result, &v22);
			sub_521730(*(_DWORD**)&dword_5d4594_1550916);
			result = *(float**)&dword_5d4594_1550916;
			*(_DWORD*)(dword_5d4594_1550916 + 84) = dword_5d4594_1550912;
			dword_5d4594_1550912 = dword_5d4594_1550916;
		}
	}
	return result;
}
// 4D4F40: using guessed type int var_200[128];

//----- (004D52F0) --------------------------------------------------------
void sub_4D52F0() {
	_DWORD* v0; // esi

	v0 = *(_DWORD**)&dword_5d4594_1550912;
	if (dword_5d4594_1550912) {
		do {
			switch (*v0) {
			case 1:
				sub_4D5350(v0, 0, 0, 0, 0);
				break;
			case 2:
			case 3:
				sub_4D5350(v0, 0, 0, v0[3], 0);
				break;
			case 4:
			case 5:
				sub_4D5350(v0, 0, 0, v0[4], 0);
				break;
			default:
				break;
			}
			v0 = (_DWORD*)v0[21];
		} while (v0);
	}
}

//----- (004D5350) --------------------------------------------------------
int __cdecl sub_4D5350(_DWORD* a1, int a2, int a3, int a4, int a5) {
	int v5;     // esi
	int result; // eax

	v5 = a2 + 1;
	if (a2 + 1 >= *(int*)&byte_5D4594[1549868])
		return 0;
	sub_5235F0(155);
	if (*a1 == 1)
		result = sub_4D53B0((int)a1, v5, a3, a4, a5);
	else
		result = sub_4D5630((int)a1, v5, a3, a4, a5);
	return result;
}

//----- (004D53B0) --------------------------------------------------------
int __cdecl sub_4D53B0(int a1, int a2, int a3, int a4, int a5) {
	float* v5;      // ebx
	int v6;         // eax
	int v7;         // esi
	int v8;         // eax
	int v9;         // edi
	int v10;        // eax
	int v11;        // ebp
	int v12;        // eax
	int v13;        // eax
	signed int v14; // eax
	int v15;        // eax
	int v16;        // esi
	int v17;        // ebp
	float* v18;     // esi
	double v19;     // st7
	double v20;     // st7
	int v21;        // eax
	int v22;        // eax
	int* v23;       // eax
	int v24;        // edi
	int v25;        // eax
	int v26;        // eax
	int v28;        // [esp+10h] [ebp-1Ch]
	float2 a2a;     // [esp+14h] [ebp-18h]
	int v30;        // [esp+1Ch] [ebp-10h]
	int v31;        // [esp+20h] [ebp-Ch]
	int v32;        // [esp+24h] [ebp-8h]
	int v33;        // [esp+28h] [ebp-4h]
	int v34;        // [esp+30h] [ebp+4h]

	v5 = (float*)a1;
	v6 = sub_5218B0(a1, 0);
	v7 = v6 != 0 ? 0 : 2;
	v30 = v6 != 0 ? 0 : 2;
	v8 = sub_5218B0(a1, 1);
	v9 = v8 != 0 ? 0 : 3;
	v31 = v8 != 0 ? 0 : 3;
	v10 = sub_5218B0(a1, 2);
	v11 = v10 != 0 ? 0 : 4;
	v32 = v10 != 0 ? 0 : 4;
	v12 = -(sub_5218B0(a1, 3) != 0);
	LOBYTE(v12) = v12 & 0xFB;
	v13 = v12 + 5;
	v33 = v13;
	if (v7 || v9 || v11 || v13) {
		v14 = sub_526AC0(0, 3);
		v34 = 0;
		while (1) {
			v15 = (v14 + 1) % 4;
			v16 = *(&v30 + v15);
			v28 = v15;
			if (!v16)
				goto LABEL_6;
			v17 = sub_526AC0(*(_DWORD*)&byte_5D4594[1549808] - *(_DWORD*)&byte_5D4594[1549812],
					 *(_DWORD*)&byte_5D4594[1549812] + *(_DWORD*)&byte_5D4594[1549808]);
			v18 = sub_523EC0((int)&byte_5D4594[1549796], v16, v17);
			if (!v18)
				return 0;
			switch (*(_DWORD*)v18) {
			case 2:
				a2a.field_0 = sub_521B00((int)v5, (int)v18);
				v19 = v5[6] - v18[8];
				goto LABEL_15;
			case 3:
				a2a.field_0 = sub_521B00((int)v5, (int)v18);
				v19 = v5[8] + v5[6];
				goto LABEL_15;
			case 4:
				v20 = v5[7] + v5[5];
				goto LABEL_14;
			case 5:
				v20 = v5[5] - v18[7];
			LABEL_14:
				a2a.field_0 = v20;
				v19 = sub_521B30((int)v5, (int)v18);
			LABEL_15:
				a2a.field_4 = v19;
				break;
			default:
				break;
			}
			sub_521880(v18, &a2a);
			if (!sub_5217A0((int)&byte_5D4594[1549796], (int)v18)) {
			LABEL_17:
				sub_521A10(v18);
				goto LABEL_26;
			}
			v21 = sub_523920(*(_DWORD*)v18);
			v22 = sub_523960(v21);
			sub_521900((int)v18, (int)v5, v22);
			v23 = (int*)sub_521200((int)v18);
			v24 = (int)v23;
			if (v23)
				break;
			sub_521730(v18);
			if (sub_4D5350(v18, a2, 1, v17, (int)v5))
				goto LABEL_25;
			sub_521760((int)v18);
			sub_521A10(v18);
		LABEL_26:
			if (++v34 >= 8)
				return 1;
		LABEL_6:
			v14 = v28;
		}
		if (sub_5238F0(v23) || *(_BYTE*)(v24 + 52) & 2 || v24 == a5 ||
		    sub_526AC0(1, 100) > *(int*)&byte_5D4594[1549844] || !sub_523A10((int)v18, (float*)v24)) {
			goto LABEL_17;
		}
		sub_521730(v18);
		v25 = sub_523920(*(_DWORD*)v18);
		sub_521A70((int)v18, v24, v25);
	LABEL_25:
		v26 = sub_523920(*(_DWORD*)v18);
		sub_521900((int)v5, (int)v18, v26);
		goto LABEL_26;
	}
	return 1;
}

//----- (004D5630) --------------------------------------------------------
int __cdecl sub_4D5630(int a1, int a2, int a3, int a4, int a5) {
	int v5;     // esi
	int v6;     // eax
	int v7;     // ebp
	float* v8;  // edi
	double v9;  // st7
	double v10; // st7
	int v11;    // eax
	float* v13; // eax
	float* v14; // edi
	double v15; // st7
	double v16; // st7
	int v17;    // eax
	float* v18; // ebp
	int v19;    // ebx
	int v20;    // eax
	int v21;    // eax
	float* v22; // edi
	double v23; // st7
	double v24; // st7
	double v25; // st7
	int v26;    // eax
	float* v27; // ebp
	int v28;    // ebx
	int v29;    // eax
	int v30;    // eax
	float* v31; // eax
	int* v32;   // edi
	double v33; // st7
	double v34; // st7
	double v35; // st7
	double v36; // st7
	int v37;    // eax
	int v38;    // eax
	float* v39; // ebp
	int v40;    // ebx
	int v41;    // eax
	int v42;    // eax
	BOOL v43;   // [esp+10h] [ebp-14h]
	BOOL v44;   // [esp+14h] [ebp-10h]
	int v45;    // [esp+18h] [ebp-Ch]
	float2 a2a; // [esp+1Ch] [ebp-8h]
	int v47;    // [esp+28h] [ebp+4h]
	int v48;    // [esp+28h] [ebp+4h]
	int v49;    // [esp+28h] [ebp+4h]

	v5 = a1;
	v43 = 0;
	v44 = 0;
	if (a3 >= *(int*)&byte_5D4594[1549816] || (v6 = sub_4D5D20((_DWORD*)a1), v45 = v6, v6 == 1)) {
		v7 = 0;
		while (1) {
			v8 = sub_521990((int)&byte_5D4594[1549796]);
			if (!v8)
				return 0;
			switch (*(_DWORD*)a1) {
			case 2:
				a2a.field_0 = sub_521B60((int)v8, a1);
				v9 = *(float*)(a1 + 24) - v8[8];
				goto LABEL_11;
			case 3:
				a2a.field_0 = sub_521B60((int)v8, a1);
				v9 = *(float*)(a1 + 32) + *(float*)(a1 + 24);
				goto LABEL_11;
			case 4:
				v10 = *(float*)(a1 + 28) + *(float*)(a1 + 20);
				goto LABEL_10;
			case 5:
				v10 = *(float*)(a1 + 20) - v8[7];
			LABEL_10:
				a2a.field_0 = v10;
				v9 = sub_521B90((int)v8, a1);
			LABEL_11:
				a2a.field_4 = v9;
				break;
			default:
				break;
			}
			sub_521880(v8, &a2a);
			if (!sub_521820((int)&byte_5D4594[1549796], (int)v8)) {
				sub_521A10(v8);
				if (++v7 < 10)
					continue;
			}
			if (v7 == 10)
				return 0;
			sub_521730(v8);
			v11 = sub_523920(*(_DWORD*)a1);
			sub_521A70(a1, (int)v8, v11);
			sub_4D5350(v8, a2, 0, 0, (int)v8);
			return 1;
		}
	}
	if (v6 != 2 && v6 != 8 && v6 != 32 && v6 != 64)
		goto LABEL_43;
	v13 = sub_523EC0((int)&byte_5D4594[1549796], *(_DWORD*)&byte_587000[4 * *(_DWORD*)a1 + 197812], a4);
	v14 = v13;
	if (!v13)
		return 0;
	switch (*(_DWORD*)a1) {
	case 2:
		v15 = *(float*)(a1 + 20) - v13[7];
		a2a.field_4 = *(float*)(a1 + 24);
		a2a.field_0 = v15;
		break;
	case 3:
		a2a.field_0 = *(float*)(a1 + 28) + *(float*)(a1 + 20);
		v16 = *(float*)(a1 + 32) + *(float*)(a1 + 24) - v13[8];
		goto LABEL_26;
	case 4:
		a2a.field_0 = *(float*)(a1 + 28) + *(float*)(a1 + 20) - v13[7];
		v16 = *(float*)(a1 + 24) - v13[8];
		goto LABEL_26;
	case 5:
		v16 = *(float*)(a1 + 32) + *(float*)(a1 + 24);
		a2a.field_0 = *(float*)(a1 + 20);
	LABEL_26:
		a2a.field_4 = v16;
		break;
	default:
		break;
	}
	sub_521880(v13, &a2a);
	v47 = sub_5239B0(*(_DWORD*)a1);
	sub_521900((int)v14, v5, v47);
	if (!sub_5217A0((int)&byte_5D4594[1549796], (int)v14))
		goto LABEL_100;
	v17 = sub_521200((int)v14);
	v18 = (float*)v17;
	if (!v17) {
		v43 = 1;
		v19 = 0;
		goto LABEL_34;
	}
	if (*(_DWORD*)v17 != 1 || *(_BYTE*)(v17 + 52) & 2 || v17 == a5 ||
	    sub_526AC0(1, 100) > *(int*)&byte_5D4594[1549844]) {
	LABEL_100:
		v43 = 0;
		goto LABEL_41;
	}
	v43 = sub_523A10((int)v14, v18);
	v19 = 1;
	if (!v43)
		goto LABEL_41;
LABEL_34:
	sub_521730(v14);
	if (!v19) {
		if (sub_4D5350(v14, a2, a3 + 1, a4, a5))
			goto LABEL_39;
		sub_521760((int)v14);
		v43 = 0;
	LABEL_41:
		sub_521A10(v14);
		if (v45 == 2 || v45 == 8)
			return 0;
		goto LABEL_43;
	}
	v20 = sub_523920(*(_DWORD*)v14);
	sub_521A70((int)v14, (int)v18, v20);
LABEL_39:
	v21 = sub_523960(v47);
	sub_521900(v5, (int)v14, v21);
LABEL_43:
	if (v45 != 4 && v45 != 16 && v45 != 32 && v45 != 64)
		goto LABEL_71;
	v22 = sub_523EC0((int)&byte_5D4594[1549796], *(_DWORD*)&byte_587000[4 * *(_DWORD*)v5 + 197836], a4);
	if (!v22)
		return 0;
	switch (*(_DWORD*)v5) {
	case 2:
		v23 = *(float*)(v5 + 28) + *(float*)(v5 + 20);
		a2a.field_4 = *(float*)(v5 + 24);
		a2a.field_0 = v23;
		break;
	case 3:
		a2a.field_0 = *(float*)(v5 + 20) - v22[7];
		v24 = *(float*)(v5 + 32) + *(float*)(v5 + 24);
		goto LABEL_53;
	case 4:
		a2a.field_0 = *(float*)(v5 + 28) + *(float*)(v5 + 20) - v22[7];
		v25 = *(float*)(v5 + 32) + *(float*)(v5 + 24);
		goto LABEL_54;
	case 5:
		v24 = *(float*)(v5 + 24);
		a2a.field_0 = *(float*)(v5 + 20);
	LABEL_53:
		v25 = v24 - v22[8];
	LABEL_54:
		a2a.field_4 = v25;
		break;
	default:
		break;
	}
	sub_521880(v22, &a2a);
	v48 = sub_523970(*(_DWORD*)v5);
	sub_521900((int)v22, v5, v48);
	if (!sub_5217A0((int)&byte_5D4594[1549796], (int)v22))
		goto LABEL_101;
	v26 = sub_521200((int)v22);
	v27 = (float*)v26;
	if (!v26) {
		v44 = 1;
		v28 = 0;
		goto LABEL_62;
	}
	if (*(_DWORD*)v26 != 1 || *(_BYTE*)(v26 + 52) & 2 || v26 == a5 ||
	    sub_526AC0(1, 100) > *(int*)&byte_5D4594[1549844]) {
	LABEL_101:
		v44 = 0;
		goto LABEL_69;
	}
	v44 = sub_523A10((int)v22, v27);
	v28 = 1;
	if (!v44)
		goto LABEL_69;
LABEL_62:
	sub_521730(v22);
	if (!v28) {
		if (sub_4D5350(v22, a2, a3 + 1, a4, a5))
			goto LABEL_67;
		sub_521760((int)v22);
		v44 = 0;
	LABEL_69:
		sub_521A10(v22);
		if (v45 == 4 || v45 == 16)
			return 0;
		goto LABEL_71;
	}
	v29 = sub_523920(*(_DWORD*)v22);
	sub_521A70((int)v22, (int)v27, v29);
LABEL_67:
	v30 = sub_523960(v48);
	sub_521900(v5, (int)v22, v30);
LABEL_71:
	if (v43 || v44) {
		if (v45 != 32 && v45 != 8 && v45 != 16)
			return 1;
		v31 = sub_523EC0((int)&byte_5D4594[1549796], *(_DWORD*)v5, a4);
		v32 = (int*)v31;
		if (v31) {
			switch (*(_DWORD*)v5) {
			case 2:
				v33 = *(float*)(v5 + 24);
				a2a.field_0 = *(float*)(v5 + 20);
				a2a.field_4 = v33 - v31[8];
				break;
			case 3:
				v34 = *(float*)(v5 + 32) + *(float*)(v5 + 24);
				a2a.field_0 = *(float*)(v5 + 20);
				a2a.field_4 = v34;
				break;
			case 4:
				v35 = *(float*)(v5 + 28) + *(float*)(v5 + 20);
				a2a.field_4 = *(float*)(v5 + 24);
				a2a.field_0 = v35;
				break;
			case 5:
				v36 = *(float*)(v5 + 20) - v31[7];
				a2a.field_4 = *(float*)(v5 + 24);
				a2a.field_0 = v36;
				break;
			default:
				break;
			}
			sub_521880(v31, &a2a);
			v37 = sub_523920(*(_DWORD*)v5);
			v49 = sub_523960(v37);
			sub_521900((int)v32, v5, v49);
			if (sub_5217A0((int)&byte_5D4594[1549796], (int)v32)) {
				v38 = sub_521200((int)v32);
				v39 = (float*)v38;
				if (!v38) {
					v40 = 0;
				LABEL_89:
					sub_521730(v32);
					if (v40) {
						v41 = sub_523920(*v32);
						sub_521A70((int)v32, (int)v39, v41);
					LABEL_96:
						v42 = sub_523960(v49);
						sub_521900(v5, (int)v32, v42);
						return 1;
					}
					if (sub_4D5350(v32, a2, a3 + 1, a4, a5))
						goto LABEL_96;
					sub_521760((int)v32);
					goto LABEL_94;
				}
				if (*(_DWORD*)v38 == 1 && !(*(_BYTE*)(v38 + 52) & 2) && v38 != a5 &&
				    sub_526AC0(1, 100) <= *(int*)&byte_5D4594[1549844]) {
					v40 = 1;
					if (sub_523A10((int)v32, v39))
						goto LABEL_89;
				}
			}
		LABEL_94:
			sub_521A10(v32);
			return 1;
		}
	}
	return 0;
}

//----- (004D5D20) --------------------------------------------------------
int __cdecl sub_4D5D20(_DWORD* a1) {
	int result; // eax

	if (*a1 == 2 || *a1 == 3) {
		if (a1[3] >= a1[4])
			return 1;
	} else if (a1[4] >= a1[3]) {
		return 1;
	}
	if (sub_526AC0(1, 100) > *(int*)&byte_5D4594[1549820]) {
		if (sub_526AC0(1, 100) > *(int*)&byte_5D4594[1549824])
			result = sub_526AC0(1, 100) >= 50 ? 4 : 2;
		else
			result = 1;
	} else {
		sub_526AC0(1, 100);
		result = 32;
	}
	return result;
}

//----- (004D5DB0) --------------------------------------------------------
unsigned int __cdecl sub_4D5DB0(int a1) {
	unsigned int result;           // eax
	struct _SYSTEMTIME SystemTime; // [esp+Ch] [ebp-410h]
	CHAR DateStr[1024];            // [esp+1Ch] [ebp-400h]

	strcpy((char*)a1, "Generated Map");
	strcpy((char*)(a1 + 64), "Generated Map");
	*(_WORD*)(a1 + 576) = *(_WORD*)&byte_587000[198380];
	*(_DWORD*)(a1 + 592) = *(_DWORD*)&byte_587000[198384];
	strcpy((char*)(a1 + 656), "http://www.westwood.com");
	strcpy((char*)(a1 + 720), "http://www.westwood.com");
	strcpy((char*)(a1 + 848), "http://www.westwood.com");
	strcpy((char*)(a1 + 976), "Generated Map");
	strcpy((char*)(a1 + 1232), "Westwood Studios");
	GetLocalTime(&SystemTime);
	GetDateFormatA(0x800u, 0, &SystemTime, (LPCSTR)&byte_587000[198496], DateStr, 1024);
	result = strlen(DateStr) + 1;
	qmemcpy((void*)(a1 + 1360), DateStr, result);
	*(_DWORD*)(a1 + 1392) = 3;
	return result;
}

//----- (004D5F30) --------------------------------------------------------
BOOL sub_4D5F30() {
	int v0;                      // esi
	int v1;                      // eax
	char* v2;                    // eax
	char* v3;                    // eax
	BOOL result;                 // eax
	CHAR FileName[1024];         // [esp+8h] [ebp-800h]
	CHAR ExistingFileName[1024]; // [esp+408h] [ebp-400h]

	v0 = 100;
	sub_40A4D0(0x400000);
	memset(&byte_5D4594[3801836], 0, 0x5B8u);
	while (1) {
		v1 = sub_4D44E0();
		if (v1 == 1)
			break;
		if (v1) {
			if (--v0)
				continue;
		}
		return 0;
	}
	v2 = sub_409E10();
	nox_sprintf(FileName, "%s\\nc.obj", v2);
	v3 = sub_409E10();
	nox_sprintf(ExistingFileName, "%s\\blend.obj", v3);
	result = DeleteFileA(FileName);
	if (!result)
		return result;
	if (!MoveFileA(ExistingFileName, FileName))
		return 0;
	sub_4D5DB0((int)&byte_5D4594[3801836]);
	nox_common_gameFlags_unset_40A540(0x400000);
	return 1;
}

//----- (004D6000) --------------------------------------------------------
int __cdecl sub_4D6000(int a1) {
	int result; // eax
	int v2;     // esi

	result = 0;
	if (a1) {
		v2 = *(_DWORD*)(a1 + 748);
		*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4652) = 0;
		*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4656) = 0;
		*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4660) = 0;
		*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4664) = 0;
		*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4668) = 0;
		*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4672) = 0;
		*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4676) = 0;
		*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4680) = 0;
		*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4684) = 0;
		*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4688) = sub_4E3CC0();
		result = *(_DWORD*)(v2 + 276);
		*(_DWORD*)(result + 4692) = 63;
	}
	return result;
}

//----- (004D60B0) --------------------------------------------------------
int sub_4D60B0() {
	int result; // eax
	int i;      // esi

	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_4D6000(i);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004D60E0) --------------------------------------------------------
_DWORD* __cdecl sub_4D60E0(int a1) {
	_DWORD* result; // eax
	int v2;         // ecx

	result = (_DWORD*)a1;
	if ((*(_BYTE*)(a1 + 16) & 0x20) != 32) {
		v2 = *(_DWORD*)(a1 + 748);
		result = *(_DWORD**)(v2 + 276);
		if (result[1198] == 1) {
			++result[1163];
			result = *(_DWORD**)(v2 + 276);
			result[1173] |= 1u;
		}
	}
	return result;
}

//----- (004D6130) --------------------------------------------------------
int __cdecl sub_4D6130(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		if ((*(_BYTE*)(a1 + 16) & 0x20) != 32) {
			v2 = *(_DWORD*)(a1 + 748);
			++*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4660);
			result = *(_DWORD*)(v2 + 276);
			*(_DWORD*)(result + 4692) |= 2u;
		}
	}
	return result;
}

//----- (004D6170) --------------------------------------------------------
int __cdecl sub_4D6170(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		if ((*(_BYTE*)(a1 + 16) & 0x20) != 32) {
			v2 = *(_DWORD*)(a1 + 748);
			++*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4664);
			result = *(_DWORD*)(v2 + 276);
			*(_DWORD*)(result + 4692) |= 4u;
		}
	}
	return result;
}

//----- (004D61B0) --------------------------------------------------------
void __cdecl sub_4D61B0(int a1) {
	int v2; // eax
	if (a1) {
		if ((*(_BYTE*)(a1 + 16) & 0x20) != 32) {
			v2 = *(_DWORD*)(a1 + 748);
			++*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4668);
			int result = *(_DWORD*)(v2 + 276);
			*(_DWORD*)(result + 4692) |= 8u;
		}
	}
}

//----- (004D61F0) --------------------------------------------------------
int __cdecl sub_4D61F0(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		if ((*(_BYTE*)(a1 + 16) & 0x20) != 32) {
			v2 = *(_DWORD*)(a1 + 748);
			++*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4672);
			++*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4676);
			result = *(_DWORD*)(v2 + 276);
			*(_DWORD*)(result + 4692) |= 0x10u;
		}
	}
	return result;
}

//----- (004D6240) --------------------------------------------------------
int __cdecl sub_4D6240(int a1, int a2) {
	int result; // eax
	int v3;     // eax

	result = a1;
	if (a1) {
		if ((*(_BYTE*)(a1 + 16) & 0x20) != 32) {
			v3 = *(_DWORD*)(a1 + 748);
			*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4684) += a2;
			result = *(_DWORD*)(v3 + 276);
			*(_DWORD*)(result + 4692) |= 0x20u;
		}
	}
	return result;
}

//----- (004D6290) --------------------------------------------------------
int __cdecl sub_4D6290(int a1) {
	int result;  // eax
	int v2;      // eax
	char v3[16]; // [esp+0h] [ebp-10h]

	result = a1;
	if (a1) {
		v2 = *(_DWORD*)(a1 + 748);
		v3[0] = -16;
		v3[1] = 11;
		*(_WORD*)&v3[2] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4652);
		*(_WORD*)&v3[4] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4656);
		*(_WORD*)&v3[6] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4660);
		*(_WORD*)&v3[8] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4664);
		*(_WORD*)&v3[10] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4668);
		*(_WORD*)&v3[12] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4672);
		*(_WORD*)&v3[14] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4684);
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v3, 16, 0, 1);
	}
	return result;
}

//----- (004D6360) --------------------------------------------------------
int __cdecl sub_4D6360(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(_DWORD*)(a1 + 748);
		LOWORD(a1) = 1520;
		HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4652);
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D63B0) --------------------------------------------------------
int __cdecl sub_4D63B0(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(_DWORD*)(a1 + 748);
		LOWORD(a1) = 1776;
		HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4660);
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D6400) --------------------------------------------------------
int __cdecl sub_4D6400(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(_DWORD*)(a1 + 748);
		LOWORD(a1) = 2032;
		HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4664);
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D6450) --------------------------------------------------------
int __cdecl sub_4D6450(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(_DWORD*)(a1 + 748);
		LOWORD(a1) = 2288;
		HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4668);
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D64A0) --------------------------------------------------------
int __cdecl sub_4D64A0(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(_DWORD*)(a1 + 748);
		LOWORD(a1) = 2544;
		HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4672);
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D64F0) --------------------------------------------------------
int __cdecl sub_4D64F0(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(_DWORD*)(a1 + 748);
		LOWORD(a1) = 2800;
		HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4684);
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D6540) --------------------------------------------------------
unsigned int __cdecl sub_4D6540(int a1) {
	int v1;              // edi
	unsigned int* v2;    // eax
	unsigned int* v3;    // ebx
	unsigned int result; // eax
	unsigned int v5;     // ebp
	int i;               // edi
	unsigned int* v7;    // esi
	unsigned int v8;     // eax
	int v9;              // eax
	float v10;           // [esp+0h] [ebp-28h]
	unsigned int v11;    // [esp+14h] [ebp-14h]
	unsigned int v12;    // [esp+18h] [ebp-10h]
	float v13;           // [esp+20h] [ebp-8h]
	unsigned int v14;    // [esp+2Ch] [ebp+4h]

	v1 = sub_4E3CE0();
	v2 = (unsigned int*)sub_417090(a1);
	v3 = v2;
	if (!v2 || !v2[1198])
		return 0;
	if (v1 == 1) {
		result = sub_4D66E0(v2[1167], v2[1168], v2[1166], v2[1172]);
	} else {
		v5 = 0;
		v11 = 0;
		v14 = 0;
		v12 = 1;
		v13 = 1.0;
		for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
			v7 = *(unsigned int**)(*(_DWORD*)(i + 748) + 276);
			if (v3[1198]) {
				v8 = sub_4D66E0(v7[1167], v7[1168], 0, v7[1172]);
				if (v8 > v5)
					v5 = v8;
				v11 += v7[1167];
				v12 = v7[1172];
				v14 += v7[1168];
			}
		}
		v9 = sub_4D66E0(v11, v14, 0, v12);
		if (v5 > 0)
			v13 = (double)(unsigned int)v9 / (double)v5;
		v10 = (double)(unsigned int)sub_4D66E0(v3[1167], v3[1168], v3[1166], v3[1172]) * v13;
		result = nox_float2int(v10);
	}
	if (result > 0x3B9AC9FF)
		result = 999999999;
	return result;
}

//----- (004D66E0) --------------------------------------------------------
int __cdecl sub_4D66E0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4) {
	float v5; // [esp+4h] [ebp-10h]

	v5 = nox_double2float(pow((double)a4, *(long double*)&byte_581450[10088])) *
	     ((double)a1 * 10.0 + (double)a2 * 35.0 + (double)a3 * 0.1);
	return nox_float2int(v5);
}

//----- (004D6770) --------------------------------------------------------
int __cdecl sub_4D6770(int a1) {
	char* v1;    // ebp
	int v2;      // ebx
	int v3;      // edi
	char* v4;    // esi
	int v5;      // eax
	char v7[90]; // [esp+Ch] [ebp-5Ch]

	v1 = sub_417090(a1);
	memset(v7, 0, 0x58u);
	*(_WORD*)&v7[88] = 0;
	v7[0] = -16;
	v7[1] = 12;
	*(_WORD*)&v7[2] = sub_4D7300();
	v2 = 0;
	v3 = sub_4DA7C0();
	if (v3) {
		v4 = &v7[8];
		do {
			v5 = *(_DWORD*)(v3 + 748);
			if (*(_DWORD*)(*(_DWORD*)(v5 + 276) + 4792) == 1 && v2 < 6) {
				*((_WORD*)v4 - 1) = *(_WORD*)(v3 + 36);
				*(_WORD*)v4 = *(_WORD*)(*(_DWORD*)(v5 + 276) + 4668);
				*((_WORD*)v4 + 3) = *(_WORD*)(*(_DWORD*)(v5 + 276) + 4664);
				*((_WORD*)v4 + 1) = *(_WORD*)(*(_DWORD*)(v5 + 276) + 4672);
				*((_WORD*)v4 + 2) = *(_WORD*)(*(_DWORD*)(v5 + 276) + 4680);
				*((_DWORD*)v4 + 2) = sub_4D6540(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064));
				++v2;
				v4 += 14;
				*(_WORD*)&v7[4] = *((_WORD*)v1 + 2344);
			}
			v3 = sub_4DA7F0(v3);
		} while (v3);
	}
	return sub_4E5390(a1, (int)v7, 90, 0, 1);
}

//----- (004D6880) --------------------------------------------------------
int __cdecl sub_4D6880(int a1, int a2) {
	char v3[69]; // [esp+8h] [ebp-48h]

	memset(v3, 0, 0x44u);
	v3[68] = 0;
	v3[0] = -16;
	v3[1] = 13;
	if (a2)
		v3[4] |= 1u;
	if (sub_51A950())
		v3[4] |= 2u;
	*(_WORD*)&v3[2] = sub_4E3CC0();
	nox_server_currentMapGetFilename_409B30();
	strcpy(&v3[5], sub_4D6940());
	nox_server_currentMapGetFilename_409B30();
	strcpy(&v3[37], sub_4D6950());
	return sub_4E5390(a1, (int)v3, 69, 0, 1);
}

//----- (004D6940) --------------------------------------------------------
char* sub_4D6940() { return (char*)&byte_5D4594[3803266]; }

//----- (004D6950) --------------------------------------------------------
char* sub_4D6950() { return (char*)&byte_5D4594[3803234]; }

//----- (004D6960) --------------------------------------------------------
int __cdecl sub_4D6960(int a1) {
	char v2[69]; // [esp+8h] [ebp-48h]

	memset(v2, 0, 0x44u);
	v2[68] = 0;
	v2[0] = -16;
	v2[1] = 14;
	v2[4] = 0;
	if (sub_51A950())
		v2[4] |= 2u;
	*(_WORD*)&v2[2] = sub_4E3CC0();
	nox_server_currentMapGetFilename_409B30();
	strcpy(&v2[5], sub_4D6940());
	nox_server_currentMapGetFilename_409B30();
	strcpy(&v2[37], sub_4D6950());
	return sub_4E5390(a1, (int)v2, 69, 0, 1);
}

//----- (004D6A20) --------------------------------------------------------
int __cdecl sub_4D6A20(int a1, int a2) {
	__int16 v3; // cx
	int v5;     // [esp+0h] [ebp-4h]

	v3 = *(_WORD*)(a2 + 40);
	LOWORD(v5) = 4080;
	HIWORD(v5) = v3;
	return sub_4E5420(a1, &v5, 4, 0, 1);
}

//----- (004D6A60) --------------------------------------------------------
int sub_4D6A60() {
	int result; // eax
	int i;      // esi

	dword_587000_312784 = 1077936128;
	dword_587000_312788 = 1065353216;
	dword_587000_312792 = 1065353216;
	dword_587000_312796 = 1065353216;
	dword_587000_312800 = 1077936128;
	dword_587000_312804 = 1077936128;
	dword_587000_312808 = 1065353216;
	dword_587000_312812 = 1065353216;
	dword_587000_312816 = 1077936128;
	dword_587000_312820 = 1077936128;
	dword_587000_312824 = 1065353216;
	dword_587000_312828 = 1065353216;
	sub_57B200();
	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_4EEDC0(i, 0);
		sub_4D9C20(i);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004D6B10) --------------------------------------------------------
int __cdecl sub_4D6B10(int a1) {
	int result; // eax
	int i;      // esi

	dword_587000_312784 = *(_DWORD*)&byte_5D4594[1556076];
	dword_587000_312788 = *(_DWORD*)&byte_5D4594[1556084];
	dword_587000_312792 = *(_DWORD*)&byte_5D4594[1556064];
	dword_587000_312796 = *(_DWORD*)&byte_5D4594[1556072];
	dword_587000_312800 = *(_DWORD*)&byte_5D4594[1556060];
	dword_587000_312804 = *(_DWORD*)&byte_5D4594[1556096];
	dword_587000_312808 = *(_DWORD*)&byte_5D4594[1550932];
	dword_587000_312812 = *(_DWORD*)&byte_5D4594[1556080];
	dword_587000_312816 = *(_DWORD*)&byte_5D4594[1556088];
	dword_587000_312820 = *(_DWORD*)&byte_5D4594[1556068];
	dword_587000_312824 = *(_DWORD*)&byte_5D4594[1556100];
	dword_587000_312828 = *(_DWORD*)&byte_5D4594[1556092];
	sub_57B200();
	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_4EEDC0(i, 0);
		if (a1)
			sub_4D9C20(i);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004D6BE0) --------------------------------------------------------
int sub_4D6BE0() {
	int result; // eax

	*(_DWORD*)&byte_5D4594[1556076] = dword_587000_312784;
	*(_DWORD*)&byte_5D4594[1556084] = dword_587000_312788;
	*(_DWORD*)&byte_5D4594[1556064] = dword_587000_312792;
	*(_DWORD*)&byte_5D4594[1556072] = dword_587000_312796;
	*(_DWORD*)&byte_5D4594[1556060] = dword_587000_312800;
	*(_DWORD*)&byte_5D4594[1556096] = dword_587000_312804;
	*(_DWORD*)&byte_5D4594[1550932] = dword_587000_312808;
	result = dword_587000_312820;
	*(_DWORD*)&byte_5D4594[1556080] = dword_587000_312812;
	*(_DWORD*)&byte_5D4594[1556088] = dword_587000_312816;
	*(_DWORD*)&byte_5D4594[1556068] = dword_587000_312820;
	*(_DWORD*)&byte_5D4594[1556100] = dword_587000_312824;
	*(_DWORD*)&byte_5D4594[1556092] = dword_587000_312828;
	return result;
}

//----- (004D6C70) --------------------------------------------------------
int nox_server_setupQuestGame_4D6C70() {
	int* v0;                 // ebp
	int v1;                  // eax
	int i;                   // eax
	int v3;                  // edi
	int v4;                  // ebx
	int v5;                  // eax
	int v6;                  // esi
	int v7;                  // eax
	int v8;                  // eax
	char v9;                 // al
	_DWORD* v10;             // esi
	int v11;                 // eax
	int v12;                 // eax
	char* v13;               // eax
	char* v14;               // edi
	wchar_t* v15;            // eax
	int j;                   // esi
	unsigned __int8 v18[20]; // [esp+10h] [ebp-14h]

	nox_common_gameFlags_unset_40A540(6128);
	sub_40A4D0(4096);
	v0 = 0;
	if (!sub_4D6F30())
		sub_4E3CD0(0);
	sub_4D0F30();
	v1 = *(_DWORD*)&nox_common_engineFlags;
	LOBYTE(v1) = nox_common_engineFlags & 0xEF;
	*(_DWORD*)&nox_common_engineFlags = v1;
	nox_common_gameFlags_unset_40A540(0x10000);
	sub_4D9CF0(255);
	for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
		*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 4792) = 0;
	v3 = sub_4DA7C0();
	if (v3) {
		while (1) {
			sub_4D6000(v3);
			v4 = *(_DWORD*)(v3 + 748);
			if (nox_common_gameFlags_check_40A5C0(1) && *(_DWORD*)&nox_common_engineFlags & 0x40000 &&
			    (v5 = *(_DWORD*)(v4 + 276), *(_BYTE*)(v5 + 2064) == 31)) {
				*(_DWORD*)(v5 + 4792) = v0;
			} else {
				*(_DWORD*)(*(_DWORD*)(v4 + 276) + 4792) = sub_4E4100();
			}
			if (*(_DWORD*)(*(_DWORD*)(v4 + 276) + 4792) == 1)
				sub_4D9D20(255, v3);
			sub_4EFE80(v3);
			sub_4FA5D0(v3, *(_DWORD*)(*(_DWORD*)(v4 + 276) + 2164));
			v6 = *(_DWORD*)(v3 + 504);
			if ((int*)v6 != v0)
				break;
		LABEL_21:
			v9 = *(_BYTE*)(*(_DWORD*)(v4 + 276) + 2251);
			if (v9) {
				if (v9 == 1) {
					v10 = sub_4EF750(v3, (CHAR*)&byte_587000[198552], v0, 1, 1);
					*(_DWORD*)v18 = v0;
					*(_DWORD*)&v18[4] = v0;
					v11 = sub_413290("Replenishment1");
					*(_DWORD*)&v18[8] = sub_413330(v11);
					*(_DWORD*)&v18[12] = v0;
					*(_WORD*)&v18[16] = (_WORD)v0;
					*(_WORD*)&v18[18] = (_WORD)v0;
					sub_4E4990((int)v10, (int*)v18);
				} else if (v9 == 2) {
					sub_4EF750(v3, (CHAR*)&byte_587000[198588], v0, 1, 1);
				}
			} else {
				sub_4EF750(v3, (CHAR*)&byte_587000[198544], v0, 1, 1);
			}
			v12 = *(_DWORD*)(v4 + 276);
			if (*(int**)(v12 + 4792) == v0)
				sub_4E6860(v12, (char)v0, (int)v0);
			v3 = sub_4DA7F0(v3);
			if ((int*)v3 == v0)
				goto LABEL_30;
		}
		while (1) {
			v7 = *(_DWORD*)(v6 + 8);
			v0 = *(int**)(v6 + 496);
			if (!(v7 & 0x1000000))
				break;
			v8 = *(_DWORD*)(v6 + 12);
			if (v8 & 0x8200)
				goto LABEL_19;
		LABEL_20:
			v6 = (int)v0;
			if (!v0)
				goto LABEL_21;
		}
		if (!(v7 & 0x2000000) || sub_415D10((char*)*(unsigned __int16*)(v6 + 4)) & 0x405)
			goto LABEL_20;
	LABEL_19:
		sub_4E5CC0(v6);
		goto LABEL_20;
	}
LABEL_30:
	sub_417D50(4);
	sub_419030(1);
	v13 = sub_4186D0((char)v0);
	v14 = v13;
	v13[56] = 9;
	v15 = sub_418C20(9);
	if (v15 != (wchar_t*)v0)
		sub_418800((wchar_t*)v14, v15, 1);
	sub_4184D0((wchar_t*)v14);
	for (j = sub_4DA7C0(); (int*)j != v0; j = sub_4DA7F0(j)) {
		if (*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(j + 748) + 276) + 4792) == 1)
			sub_4191D0(v14[57], j + 48, 1, *(_DWORD*)(j + 36), (int)v0);
	}
	sub_4D6BE0();
	return sub_4D6A60();
}

//----- (004D6F30) --------------------------------------------------------
int sub_4D6F30() { return *(_DWORD*)&byte_5D4594[1556156]; }

//----- (004D6F40) --------------------------------------------------------
int __cdecl sub_4D6F40(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1556156] = a1;
	return result;
}

//----- (004D6F50) --------------------------------------------------------
int sub_4D6F50() { return *(_DWORD*)&byte_5D4594[1556160]; }

//----- (004D6F60) --------------------------------------------------------
int __cdecl sub_4D6F60(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1556160] = a1;
	return result;
}

//----- (004D6F70) --------------------------------------------------------
int sub_4D6F70() { return *(_DWORD*)&byte_5D4594[1556164]; }

//----- (004D6F80) --------------------------------------------------------
int __cdecl sub_4D6F80(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1556164] = a1;
	return result;
}

//----- (004D6F90) --------------------------------------------------------
int __cdecl sub_4D6F90(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1556104] = a1;
	return result;
}

//----- (004D6FA0) --------------------------------------------------------
int sub_4D6FA0() { return *(_DWORD*)&byte_5D4594[1556104]; }

//----- (004D6FB0) --------------------------------------------------------
int __cdecl sub_4D6FB0(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1556148 = a1;
	return result;
}

//----- (004D6FC0) --------------------------------------------------------
int sub_4D6FC0() { return dword_5d4594_1556148; }

//----- (004D7080) --------------------------------------------------------
int nox_server_conCmdHandler_startSoloQuest_4D7080() {
	dword_5d4594_1556112 = 1;
	sub_44E0B0(1);
	*(_DWORD*)&byte_5D4594[1556152] = sub_416A00();
	sub_4169E0();
	return sub_4D6FB0(30);
}

//----- (004D70B0) --------------------------------------------------------
char* sub_4D70B0() {
	char* result; // eax

	result = *(char**)&byte_5D4594[1556152];
	if (!*(_DWORD*)&byte_5D4594[1556152])
		result = sub_4169F0();
	return result;
}

//----- (004D70C0) --------------------------------------------------------
BOOL __cdecl sub_4D70C0(int a1) {
	return nox_common_gameFlags_check_40A5C0(4096) || a1 != 37 && a1 != 38 && a1 != 40 && a1 != 39;
}

//----- (004D7100) --------------------------------------------------------
BOOL __cdecl sub_4D7100(int a1) {
	return nox_common_gameFlags_check_40A5C0(4096) || a1 != 111 && a1 != 112 && a1 != 114 && a1 != 113;
}

//----- (004D7150) --------------------------------------------------------
int sub_4D7150() {
	int result; // eax
	int i;      // edi
	int* v2;    // esi
	int v3;     // eax

	result = *(_DWORD*)&byte_5D4594[1556144];
	if (*(_DWORD*)&byte_5D4594[1556144]) {
		if (*(_DWORD*)&byte_5D4594[2598000] > *(int*)&byte_5D4594[1556144]) {
			result = sub_4DA7C0();
			for (i = result; result; i = result) {
				v2 = *(int**)(i + 748);
				v3 = v2[69];
				if ((*(_BYTE*)(v3 + 3680) & 1) == 1 && *(_DWORD*)(v3 + 4792) == 1 && !v2[78] &&
				    !v2[79] && (*(_DWORD*)(v3 + 3680) & 0x10) == 16) {
					sub_4DF3C0(v2[69]);
					sub_4E6AA0(v2[69]);
					sub_4E6040(i);
				}
				result = sub_4DA7F0(i);
			}
		}
	}
	return result;
}

//----- (004D71E0) --------------------------------------------------------
int __cdecl sub_4D71E0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1556136] = a1;
	return result;
}

//----- (004D71F0) --------------------------------------------------------
unsigned int sub_4D71F0() {
	unsigned int result; // eax
	int v1;              // esi
	char v2;             // al

	result = *(_DWORD*)&byte_5D4594[1556136];
	if (*(_DWORD*)&byte_5D4594[1556136]) {
		if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)&byte_5D4594[1556136]) >= 0x2328) {
			v1 = 0;
			result = sub_4DA7C0();
			if (result) {
				do {
					if (*(_DWORD*)(*(_DWORD*)(result + 748) + 308))
						v1 = 1;
					result = sub_4DA7F0(result);
				} while (result);
				if (v1) {
					result = sub_4E3CE0();
					if (result > 1) {
						sub_4D71E0(0);
						result = sub_4D72C0();
						if (!result) {
							sub_4D72B0(1);
							v2 = sub_4D72C0();
							result = sub_4D7280(255, v2);
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (004D7280) --------------------------------------------------------
int __cdecl sub_4D7280(int a1, char a2) {
	int v2;     // ecx
	char v4[3]; // [esp+0h] [ebp-4h]
	char v5;    // [esp+3h] [ebp-1h]

	v5 = HIBYTE(v2);
	v4[0] = -16;
	v4[1] = 24;
	v4[2] = a2;
	return sub_4E5390(a1, (int)v4, 3, 0, 1);
}

//----- (004D72B0) --------------------------------------------------------
int __cdecl sub_4D72B0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1556140] = a1;
	return result;
}

//----- (004D72C0) --------------------------------------------------------
int sub_4D72C0() { return *(_DWORD*)&byte_5D4594[1556140]; }

//----- (004D72D0) --------------------------------------------------------
int __cdecl sub_4D72D0(int a1) {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[1556128];
	*(_DWORD*)&byte_5D4594[1556132] = *(_DWORD*)&byte_5D4594[1556128];
	*(_DWORD*)&byte_5D4594[1556128] = a1;
	return result;
}

//----- (004D72F0) --------------------------------------------------------
int sub_4D72F0() { return *(_DWORD*)&byte_5D4594[1556128]; }

//----- (004D7300) --------------------------------------------------------
int sub_4D7300() { return *(_DWORD*)&byte_5D4594[1556132]; }

//----- (004D7310) --------------------------------------------------------
int sub_4D7310() {
	int v0; // ebx
	int v1; // ebp
	int v2; // esi
	int v3; // edi
	int i;  // eax

	v0 = 0;
	v1 = 99999;
	v2 = sub_4DA7C0();
	if (!v2)
		return 0;
	do {
		if (*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v2 + 748) + 276) + 4792) == 1) {
			v3 = 0;
			for (i = sub_4E7980(v2); i; i = sub_4E7990(i)) {
				if (*(_BYTE*)(i + 8) & 0x40)
					++v3;
			}
			if (v3 <= v1) {
				v1 = v3;
				v0 = v2;
			}
		}
		v2 = sub_4DA7F0(v2);
	} while (v2);
	return v0;
}

//----- (004D7390) --------------------------------------------------------
void __cdecl sub_4D7390(int a1) {
	int v1; // esi
	int v2; // ebx
	int v3; // edi

	if (a1) {
		if (sub_4E3CE0()) {
			v1 = sub_4E7980(a1);
			if (v1) {
				do {
					v2 = sub_4E7990(v1);
					if (*(_BYTE*)(v1 + 8) & 0x40) {
						v3 = sub_4D7310();
						if (v3) {
							sub_4ED0C0(a1, (int*)v1);
							sub_4F3070(v3, v1, 1);
							sub_4DA2C0(v3, "GeneralPrint:GainedKey", 0);
							sub_501960(820, v3, 0, 0);
						}
					}
					v1 = v2;
				} while (v2);
			}
			sub_4EDD00(a1, 64);
		} else {
			sub_4EDD00(a1, 64);
		}
	}
}

//----- (004D7430) --------------------------------------------------------
int sub_4D7430() { return *(_DWORD*)&byte_5D4594[1556116]; }

//----- (004D7440) --------------------------------------------------------
int __cdecl sub_4D7440(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1556116] = a1;
	return result;
}

//----- (004D7450) --------------------------------------------------------
int __cdecl sub_4D7450(int a1, __int16 a2) {
	char v3[4]; // [esp+0h] [ebp-4h]

	v3[0] = -16;
	v3[1] = 29;
	*(_WORD*)&v3[2] = a2;
	return sub_4E5420(a1, v3, 4, 0, 1);
}

//----- (004D7480) --------------------------------------------------------
void __cdecl sub_4D7480(int a1) {
	int v1;     // edi
	int v2;     // eax
	float2* v3; // ebx

	if (a1 && *(_BYTE*)(a1 + 8) & 4) {
		v1 = *(_DWORD*)(a1 + 748);
		v2 = *(_DWORD*)(v1 + 316);
		if (v2) {
			v3 = *(float2**)(v2 + 700);
			sub_4E6AA0(*(_DWORD*)(v1 + 276));
			sub_4E6040(a1);
			*(_DWORD*)(v1 + 316) = 0;
			sub_4E7010(a1, v3 + 10);
			sub_501960(312, a1, 2, *(_DWORD*)(a1 + 36));
			sub_522FF0(129, v3 + 10);
		}
	}
}

//----- (004D74F0) --------------------------------------------------------
int __cdecl sub_4D74F0(int a1) {
	int result; // eax

	result = a1;
	if (a1 <= 4)
		return 5;
	if (a1 <= 9)
		return 10;
	if (a1 <= 14)
		return 15;
	if (a1 <= 19)
		result = 20;
	return result;
}

//----- (004D7520) --------------------------------------------------------
char __cdecl sub_4D7520(int a1) {
	int v1; // eax
	int i;  // esi
	int v3; // eax
	int v4; // esi
	int v5; // edi

	LOBYTE(v1) = byte_5D4594[1556120];
	if (*(_DWORD*)&byte_5D4594[1556120] == 1) {
		if (a1)
			goto LABEL_19;
		for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
			v3 = *(_DWORD*)(i + 748);
			if (*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4792) && *(_DWORD*)(v3 + 316))
				sub_4D7480(i);
		}
		v1 = sub_4DA790();
		v4 = v1;
		if (!v1) {
		LABEL_19:
			*(_DWORD*)&byte_5D4594[1556120] = a1;
		} else {
			do {
				v5 = sub_4DA7A0(v4);
				LOBYTE(v1) = *(_BYTE*)(v4 + 8);
				if (v1 & 0x20 && *(_BYTE*)(v4 + 12) & 2)
					LOBYTE(v1) = sub_4E7600(v4);
				v4 = v5;
			} while (v5);
			*(_DWORD*)&byte_5D4594[1556120] = 0;
		}
	} else {
		*(_DWORD*)&byte_5D4594[1556120] = a1;
	}
	return v1;
}

//----- (004D75E0) --------------------------------------------------------
int sub_4D75E0() { return *(_DWORD*)&byte_5D4594[1556120]; }

//----- (004D75F0) --------------------------------------------------------
int __cdecl sub_4D75F0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1556108] = a1;
	return result;
}

//----- (004D7600) --------------------------------------------------------
int sub_4D7600() {
	int v0;     // edi
	int v1;     // esi
	int result; // eax
	int v3;     // ecx
	int i;      // esi
	int v5;     // eax

	v0 = sub_4E3CE0();
	v1 = 0;
	result = *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)&byte_5D4594[1556108];
	if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)&byte_5D4594[1556108]) >= 0x1E && v0) {
		for (result = sub_4DA7C0(); result; result = sub_4DA7F0(result)) {
			v3 = *(_DWORD*)(result + 748);
			if (*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4792) && *(_DWORD*)(v3 + 316))
				++v1;
		}
		if (v0 == v1) {
			result = sub_4E8F60();
			if (!result) {
				result = sub_4DA7C0();
				for (i = result; result; i = result) {
					v5 = *(_DWORD*)(i + 748);
					if (*(_DWORD*)(*(_DWORD*)(v5 + 276) + 4792) && *(_DWORD*)(v5 + 316)) {
						sub_4D7480(i);
						if (v0 <= 1)
							sub_4DA2C0(i, "Gauntlet.c:WarpRestrictedSolo", 0);
						else
							sub_4DA2C0(i, "Gauntlet.c:WarpRestrictedMulti", 0);
					}
					result = sub_4DA7F0(i);
				}
			}
		}
	}
	return result;
}

//----- (004D76E0) --------------------------------------------------------
int __cdecl sub_4D76E0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1556124] = a1;
	return result;
}

//----- (004D76F0) --------------------------------------------------------
int sub_4D76F0() { return *(_DWORD*)&byte_5D4594[1556124]; }

//----- (004D7700) --------------------------------------------------------
bool nox_client_checkQuestExp_SKU2_4D7700() {
	HKEY phkResult;   // [esp+8h] [ebp-90h]
	BYTE Data[4];     // [esp+Ch] [ebp-8Ch]
	DWORD cbData;     // [esp+10h] [ebp-88h]
	DWORD Type;       // [esp+14h] [ebp-84h]
	CHAR SubKey[128]; // [esp+18h] [ebp-80h]

	strcpy(SubKey, "SOFTWARE\\Westwood\\Nox");
	*(_DWORD*)Data = -1;
	cbData = 4;
	if (!RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult)) {
		RegQueryValueExA(phkResult, (LPCSTR)&byte_587000[198712], 0, &Type, Data, &cbData);
		RegCloseKey(phkResult);
	}
	return *(_DWORD*)Data >= 9472;
}

//----- (004D7790) --------------------------------------------------------
BOOL sub_4D7790() {
	char* v0;            // eax
	CHAR FileName[1024]; // [esp+0h] [ebp-400h]

	v0 = sub_409E10();
	nox_sprintf(FileName, "%s\\Maps\\G_Lava", v0);
	return _access(FileName, 0) == 0;
}

//----- (004D77D0) --------------------------------------------------------
LSTATUS __cdecl sub_4D77D0(int a1) {
	LSTATUS result;   // eax
	BYTE Data[4];     // [esp+0h] [ebp-88h]
	HKEY phkResult;   // [esp+4h] [ebp-84h]
	CHAR SubKey[128]; // [esp+8h] [ebp-80h]

	result = a1 - 4096;
	switch (a1) {
	case 4096:
		*(_DWORD*)Data = 9472;
		goto LABEL_8;
	case 4098:
		*(_DWORD*)Data = 9474;
		goto LABEL_8;
	case 4099:
		*(_DWORD*)Data = 9475;
		goto LABEL_8;
	case 4101:
		*(_DWORD*)Data = 9477;
		goto LABEL_8;
	case 4102:
		*(_DWORD*)Data = 9478;
		goto LABEL_8;
	case 4105:
		*(_DWORD*)Data = 9481;
	LABEL_8:
		strcpy(SubKey, "SOFTWARE\\Westwood\\Nox");
		result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult);
		if (!result) {
			RegSetValueExA(phkResult, (LPCSTR)&byte_587000[198756], 0, 4u, Data, 4u);
			result = RegCloseKey(phkResult);
		}
		break;
	default:
		return result;
	}
	return result;
}

//----- (004D78C0) --------------------------------------------------------
LSTATUS nox_common_readSKU_fromRegistry_4D78C0() {
	LSTATUS result;   // eax
	BYTE Data[4];     // [esp+8h] [ebp-90h]
	HKEY phkResult;   // [esp+Ch] [ebp-8Ch]
	DWORD cbData;     // [esp+10h] [ebp-88h]
	DWORD Type;       // [esp+14h] [ebp-84h]
	CHAR SubKey[128]; // [esp+18h] [ebp-80h]

	strcpy(SubKey, "SOFTWARE\\Westwood\\Nox");
	*(_DWORD*)Data = -1;
	cbData = 4;
	result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult);
	if (!result) {
		RegQueryValueExA(phkResult, (LPCSTR)&byte_587000[198784], 0, &Type, Data, &cbData);
		result = RegCloseKey(phkResult);
	}
	if (*(int*)Data < 9472) {
		result = sub_4D7790();
		if (result == 1)
			result = sub_4D77D0(*(int*)Data);
	}
	return result;
}

//----- (004D7960) --------------------------------------------------------
int __cdecl sub_4D7960(char a1) {
	int result; // eax

	result = 1 << a1;
	*(_DWORD*)&byte_5D4594[1556300] |= 1 << a1;
	return result;
}

//----- (004D7980) --------------------------------------------------------
BOOL __cdecl sub_4D7980(char a1) { return (*(_DWORD*)&byte_5D4594[1556300] & (1 << a1)) != 0; }

//----- (004D79A0) --------------------------------------------------------
int __cdecl sub_4D79A0(char a1) {
	int result; // eax

	result = ~(1 << a1);
	*(_DWORD*)&byte_5D4594[1556300] &= result;
	return result;
}

//----- (004D79C0) --------------------------------------------------------
int __cdecl sub_4D79C0(int a1) {
	int v1;     // esi
	int result; // eax
	int v3;     // ecx

	v1 = *(_DWORD*)(a1 + 748);
	sub_4D9D20(255, a1);
	sub_4D6000(a1);
	for (result = sub_4DA7C0(); result; result = sub_4DA7F0(result)) {
		v3 = *(_DWORD*)(result + 748);
		*(_BYTE*)(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + v3 + 452) = 0;
		*(_DWORD*)(v3 + 4 * *(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + 324) = 0;
		*(_BYTE*)(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + v3 + 484) = 0;
		*(_BYTE*)(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + v3 + 516) = 0;
	}
	return result;
}

//----- (004D7A60) --------------------------------------------------------
int __cdecl sub_4D7A60(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[4 * a1 + 1556172] = *(_DWORD*)&byte_5D4594[2598000];
	return result;
}

//----- (004D7A80) --------------------------------------------------------
int sub_4D7A80() {
	unsigned __int8* v0; // ebp
	int v1;              // edi
	int v2;              // esi
	char* v3;            // eax
	int v4;              // eax
	int v5;              // edi
	int v6;              // ecx
	int result;          // eax

	v0 = &byte_5D4594[1556172];
	v1 = 324 - (_DWORD)&byte_5D4594[1556172];
	v2 = 484;
	do {
		v3 = sub_417090(v2 - 484);
		if (v3 && *((_DWORD*)v3 + 523) && *((_DWORD*)v3 + 514) && *((_DWORD*)v3 + 1198) == 1)
			goto LABEL_12;
		if (*(_DWORD*)v0 && *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)v0 >
					(unsigned int)(30 * *(_DWORD*)&byte_5D4594[2649704])) {
			v4 = sub_4DA7C0();
			if (v4) {
				v5 = (int)&v0[v1];
				do {
					v6 = *(_DWORD*)(v4 + 748);
					*(_BYTE*)(v2 + v6 - 32) = 0;
					*(_DWORD*)(v5 + v6) = 0;
					*(_BYTE*)(v2 + v6) = 0;
					*(_BYTE*)(v2 + v6 + 32) = 0;
					v4 = sub_4DA7F0(v4);
				} while (v4);
				v1 = 324 - (_DWORD)&byte_5D4594[1556172];
			}
		LABEL_12:
			*(_DWORD*)v0 = 0;
		}
		++v2;
		v0 += 4;
		result = v2 - 484;
	} while (v2 - 484 < 32);
	return result;
}

//----- (004D7B40) --------------------------------------------------------
int sub_4D7B40() {
	int result; // eax

	result = 0;
	memset(&byte_5D4594[1556172], 0, 0x80u);
	return result;
}

//----- (004D7B60) --------------------------------------------------------
int __cdecl sub_4D7B60(int a1) {
	int result; // eax
	int i;      // esi
	char v3[7]; // [esp+4h] [ebp-8h]

	v3[0] = -46;
	*(_WORD*)&v3[1] = sub_578AC0((_DWORD*)a1);
	*(_WORD*)&v3[3] = *(_WORD*)(a1 + 4);
	v3[5] = 1;
	v3[6] = 2;
	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), v3, 7, 0, 1);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004D7BE0) --------------------------------------------------------
int __cdecl sub_4D7BE0(int a1) {
	int result; // eax
	int i;      // esi
	char v3[7]; // [esp+4h] [ebp-8h]

	v3[0] = -46;
	*(_WORD*)&v3[1] = sub_578AC0((_DWORD*)a1);
	*(_WORD*)&v3[3] = *(_WORD*)(a1 + 4);
	v3[5] = 2;
	v3[6] = 2;
	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), v3, 7, 0, 1);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004D7C60) --------------------------------------------------------
int sub_4D7C60() {
	int result; // eax
	float v1;   // [esp+0h] [ebp-4h]
	float v2;   // [esp+0h] [ebp-4h]

	*(_DWORD*)&byte_5D4594[1556316] = 0;
	*(float*)&byte_5D4594[1556308] = sub_419D40(&byte_587000[198788]);
	v1 = sub_419D40(&byte_587000[198804]);
	*(_DWORD*)&byte_5D4594[1556312] = nox_float2int(v1);
	v2 = sub_419D40(&byte_587000[198820]);
	result = nox_float2int(v2);
	*(_DWORD*)&byte_5D4594[1556304] = result;
	return result;
}

//----- (004D7CC0) --------------------------------------------------------
int sub_4D7CC0() {
	int result; // eax
	int i;      // ecx
	int v2;     // edx
	double v3;  // st7
	double v4;  // st6
	int j;      // esi
	_DWORD* v6; // edi
	int v7;     // eax

	sub_416BB0();
	result = sub_409F40(0x2000);
	if (result) {
		if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)&byte_5D4594[1556316]) >
		    *(int*)&byte_5D4594[1556312]) {
			for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
				if (!(*(_DWORD*)(i + 16) & 0x8020)) {
					v2 = *(_DWORD*)(i + 748);
					if (!(*(_BYTE*)(*(_DWORD*)(v2 + 276) + 3680) & 1)) {
						v3 = *(float*)(i + 60) - *(float*)(v2 + 252);
						v4 = *(float*)(i + 56) - *(float*)(v2 + 248);
						if (v4 * v4 + v3 * v3 < *(float*)&byte_5D4594[1556308])
							*(_DWORD*)(v2 + 256) = *(_DWORD*)&byte_5D4594[2598000];
						*(_DWORD*)(v2 + 248) = *(_DWORD*)(i + 56);
						*(_DWORD*)(v2 + 252) = *(_DWORD*)(i + 60);
					}
				}
			}
			*(_DWORD*)&byte_5D4594[1556316] = *(_DWORD*)&byte_5D4594[2598000];
		}
		result = sub_4DA7C0();
		for (j = result; result; j = result) {
			if (!(*(_DWORD*)(j + 16) & 0x8020)) {
				v6 = *(_DWORD**)(j + 748);
				if (!(*(_BYTE*)(v6[69] + 3680) & 1)) {
					v7 = v6[65];
					if ((unsigned int)(*(_DWORD*)&byte_5D4594[1556316] - v6[64]) >
					    *(int*)&byte_5D4594[1556304]) {
						if (v7) {
							sub_4D7BE0(j);
							v6[65] = 0;
						}
					} else if (!v7) {
						if (!nox_common_gameFlags_check_40A5C0(32) || *(_BYTE*)(v6[69] + 4) & 1)
							sub_501960(774, j, 0, 0);
						sub_4D7B60(j);
						v6[65] = 1;
					}
				}
			}
			result = sub_4DA7F0(j);
		}
	}
	return result;
}

//----- (004D7E50) --------------------------------------------------------
int __cdecl sub_4D7E50(int a1) {
	int result; // eax
	_DWORD* v2; // esi

	result = a1;
	if (*(_BYTE*)(a1 + 8) & 4) {
		v2 = *(_DWORD**)(a1 + 748);
		v2[62] = 0;
		v2[63] = 0;
		v2[64] = *(_DWORD*)&byte_5D4594[2598000];
		if (v2[65])
			result = sub_4D7BE0(a1);
		v2[65] = 0;
	}
	return result;
}

//----- (004D7EA0) --------------------------------------------------------
int sub_4D7EA0() {
	int result; // eax
	int i;      // esi

	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_4D7E50(i);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004D7ED0) --------------------------------------------------------
void sub_4D7ED0() { nox_srand(0x2310u); }

//----- (004D7EE0) --------------------------------------------------------
int __cdecl sub_4D7EE0(int a1, char a2) {
	char v3[2]; // [esp+0h] [ebp-2h]

	v3[0] = -19;
	v3[1] = a2;
	return sub_4E5390(a1, (int)v3, 2, 0, 1);
}

//----- (004D7F10) --------------------------------------------------------
int __cdecl sub_4D7F10(int a1) {
	char v2[2]; // [esp+0h] [ebp-2h]

	v2[0] = -20;
	v2[1] = sub_40A6C0();
	return sub_4E5390(a1, (int)v2, 2, 0, 1);
}

//----- (004D7F40) --------------------------------------------------------
int __cdecl sub_4D7F40(int a1, _DWORD* a2, char a3) {
	int v3; // esi

	v3 = *(_DWORD*)(a1 + 748);
	LOBYTE(a1) = -38;
	*(_WORD*)((char*)&a1 + 1) = sub_578AC0(a2);
	HIBYTE(a1) = a3;
	return sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), &a1, 4, 0, 1);
}

//----- (004D80C0) --------------------------------------------------------
int __cdecl sub_4D80C0(int a1, char a2) {
	int result; // eax
	int v3;     // eax

	result = a1;
	if (*(_BYTE*)(a1 + 8) & 4) {
		v3 = *(_DWORD*)(a1 + 748);
		LOBYTE(a1) = -21;
		BYTE1(a1) = a2;
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), &a1, 2, 0, 1);
	}
	return result;
}

//----- (004D8100) --------------------------------------------------------
int __cdecl sub_4D8100(int a1, char a2, char a3) {
	int result; // eax
	int v4;     // edx

	result = a1;
	if (*(_BYTE*)(a1 + 8) & 4) {
		BYTE2(a1) = a3;
		v4 = *(_DWORD*)(result + 748);
		BYTE1(a1) = a2;
		LOBYTE(a1) = -50;
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), &a1, 3, 0, 1);
	}
	return result;
}

//----- (004D8150) --------------------------------------------------------
int __cdecl sub_4D8150(int a1, char a2, char a3) {
	int result; // eax
	int v4;     // edx

	result = a1;
	if (*(_BYTE*)(a1 + 8) & 4) {
		BYTE2(a1) = a3;
		v4 = *(_DWORD*)(result + 748);
		BYTE1(a1) = a2;
		LOBYTE(a1) = -49;
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), &a1, 3, 0, 1);
	}
	return result;
}

//----- (004D81A0) --------------------------------------------------------
void __cdecl sub_4D81A0(int a1) {
	double v1;  // st7
	int v2;     // ecx
	char v3[5]; // [esp+4h] [ebp-8h]

	if (*(_BYTE*)(a1 + 8) & 4) {
		v1 = *(float*)(a1 + 28);
		v3[0] = 110;
		v2 = *(_DWORD*)(a1 + 748);
		*(_DWORD*)&v3[1] = (__int64)v1;
		sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v3, 5, 0, 1);
	}
}

//----- (004D81F0) --------------------------------------------------------
int __cdecl sub_4D81F0(int a1, _DWORD* a2) {
	char v3[7]; // [esp+4h] [ebp-8h]

	v3[0] = 107;
	*(_WORD*)&v3[1] = sub_578AC0(a2);
	*(_DWORD*)&v3[3] = a2[33];
	return sub_4E5420(a1, v3, 7, 0, 1);
}

//----- (004D8230) --------------------------------------------------------
int __cdecl sub_4D8230(int a1, _DWORD* a2) {
	char v3[7]; // [esp+4h] [ebp-8h]

	v3[0] = 101;
	*(_WORD*)&v3[1] = sub_578AC0(a2);
	*(_DWORD*)&v3[3] = a2[5];
	return sub_4E5420(a1, v3, 7, 0, 1);
}

//----- (004D8270) --------------------------------------------------------
int __cdecl sub_4D8270(int a1) {
	int v1;     // ecx
	int v2;     // eax
	char v4[5]; // [esp+0h] [ebp-8h]

	v1 = *(_DWORD*)(a1 + 16);
	v2 = *(_DWORD*)(a1 + 748);
	v4[0] = 102;
	*(_DWORD*)&v4[1] = v1;
	return sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v4, 5, 0, 1);
}

//----- (004D82B0) --------------------------------------------------------
int __cdecl sub_4D82B0(int a1, _DWORD* a2, char a3, char a4) {
	char v5[5]; // [esp+0h] [ebp-8h]

	v5[0] = 100;
	*(_WORD*)&v5[1] = sub_578AC0(a2);
	v5[3] = a3;
	v5[4] = a4;
	return sub_4E5390(a1, (int)v5, 5, 0, 0);
}

//----- (004D82F0) --------------------------------------------------------
_DWORD* __cdecl sub_4D82F0(int a1, _DWORD* a2) {
	_DWORD* result; // eax
	int v3;         // ecx
	int v4;         // edi
	int v5;         // esi
	int v6;         // edx
	_DWORD* v7;     // ecx
	int v8;         // ecx
	int v9;         // eax
	int v10;        // edx
	int v11;        // ecx
	int v12;        // esi
	int v13;        // edx
	_DWORD* v14;    // ecx
	int v15;        // ecx
	int v16;        // eax
	int v17;        // edx
	int v18;        // ecx
	char v19[11];   // [esp+8h] [ebp-Ch]

	result = a2;
	v3 = a2[2];
	v4 = 0;
	if (v3 & 0x11001000) {
		v5 = a2[173];
		v6 = 4;
		v7 = (_DWORD*)a2[173];
		do {
			if (*v7)
				v4 = 1;
			++v7;
			--v6;
		} while (v6);
		if (v4) {
			v8 = a2[123];
			v19[0] = 81;
			*(_WORD*)&v19[1] = *(_WORD*)(v8 + 36);
			if (*(_BYTE*)(v8 + 8) & 4)
				v19[2] |= 0x80u;
			*(_DWORD*)&v19[3] = sub_415820((int)a2);
			v9 = 0;
			v10 = v5;
			do {
				if (*(_DWORD*)v10)
					v19[v9 + 7] = *(_BYTE*)(*(_DWORD*)v10 + 4);
				else
					v19[v9 + 7] = -1;
				++v9;
				v10 += 4;
			} while (v9 < 4);
			result = (_DWORD*)sub_4E5390(a1, (int)v19, 11, 0, 0);
		} else {
			v11 = a2[123];
			v19[0] = 80;
			*(_WORD*)&v19[1] = *(_WORD*)(v11 + 36);
			if (*(_BYTE*)(v11 + 8) & 4)
				v19[2] |= 0x80u;
			*(_DWORD*)&v19[3] = sub_415820((int)a2);
			result = (_DWORD*)sub_4E5390(a1, (int)v19, 7, 0, 0);
		}
	} else if (v3 & 0x2000000) {
		v12 = a2[173];
		v13 = 4;
		v14 = (_DWORD*)a2[173];
		do {
			if (*v14)
				v4 = 1;
			++v14;
			--v13;
		} while (v13);
		if (v4) {
			v15 = a2[123];
			v19[0] = 82;
			*(_WORD*)&v19[1] = *(_WORD*)(v15 + 36);
			if (*(_BYTE*)(v15 + 8) & 4)
				v19[2] |= 0x80u;
			*(_DWORD*)&v19[3] = sub_415C70((int)a2);
			v16 = 0;
			v17 = v12;
			do {
				if (*(_DWORD*)v17)
					v19[v16 + 7] = *(_BYTE*)(*(_DWORD*)v17 + 4);
				else
					v19[v16 + 7] = -1;
				++v16;
				v17 += 4;
			} while (v16 < 4);
			result = (_DWORD*)sub_4E5390(a1, (int)v19, 11, 0, 0);
		} else {
			v18 = a2[123];
			v19[0] = 79;
			*(_WORD*)&v19[1] = *(_WORD*)(v18 + 36);
			if (*(_BYTE*)(v18 + 8) & 4)
				v19[2] |= 0x80u;
			*(_DWORD*)&v19[3] = sub_415C70((int)a2);
			result = (_DWORD*)sub_4E5390(a1, (int)v19, 7, 0, 0);
		}
	}
	return result;
}

//----- (004D84C0) --------------------------------------------------------
int __cdecl sub_4D84C0(int a1, int a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // ecx
	int v5;     // eax
	int v6;     // ecx
	char v7[7]; // [esp+0h] [ebp-8h]

	result = a2;
	v3 = *(_DWORD*)(a2 + 8);
	if (v3 & 0x11001000) {
		v4 = *(_DWORD*)(a2 + 492);
		v7[0] = 84;
		*(_WORD*)&v7[1] = *(_WORD*)(v4 + 36);
		v5 = sub_415820(a2);
	} else {
		if (!(v3 & 0x2000000))
			return result;
		v6 = *(_DWORD*)(a2 + 492);
		v7[0] = 83;
		*(_WORD*)&v7[1] = *(_WORD*)(v6 + 36);
		v5 = sub_415C70(a2);
	}
	*(_DWORD*)&v7[3] = v5;
	return sub_4E5390(a1, (int)v7, 7, 0, 0);
}

//----- (004D8540) --------------------------------------------------------
_DWORD* __cdecl sub_4D8540(int a1, _DWORD* a2, int a3) {
	_DWORD* result; // eax
	char v4[3];     // [esp+4h] [ebp-4h]

	v4[0] = 96;
	*(_WORD*)&v4[1] = sub_578AC0(a2);
	sub_4E5390(a1, (int)v4, 3, 0, 0);
	result = (_DWORD*)a3;
	if (a3)
		result = sub_4D82F0(255, a2);
	return result;
}

//----- (004D8590) --------------------------------------------------------
int __cdecl sub_4D8590(int a1, _DWORD* a2) {
	int v2;     // ecx
	char v4[3]; // [esp+0h] [ebp-4h]
	char v5;    // [esp+3h] [ebp-1h]

	v5 = HIBYTE(v2);
	v4[0] = 97;
	*(_WORD*)&v4[1] = sub_578AC0(a2);
	return sub_4E5390(a1, (int)v4, 3, 0, 0);
}

//----- (004D85C0) --------------------------------------------------------
int __cdecl sub_4D85C0(int a1, _DWORD* a2) {
	int result; // eax
	_WORD* v3;  // eax
	char v4[7]; // [esp+4h] [ebp-8h]

	result = a2[139];
	if (result) {
		v4[0] = -35;
		*(_WORD*)&v4[1] = sub_578AC0(a2);
		v3 = (_WORD*)a2[139];
		*(_WORD*)&v4[3] = *v3;
		*(_WORD*)&v4[5] = v3[2];
		result = sub_4E5390(a1, (int)v4, 7, 0, 1);
	}
	return result;
}

//----- (004D8620) --------------------------------------------------------
int __cdecl sub_4D8620(int a1, _DWORD* a2) {
	_DWORD* v2;      // esi
	int result;      // eax
	unsigned int v4; // ecx
	_DWORD* v5;      // [esp-4h] [ebp-8h]

	v2 = a2;
	result = a2[139];
	if (result) {
		v5 = a2;
		LOBYTE(a2) = 65;
		*(_WORD*)((char*)&a2 + 1) = sub_578AC0(v5);
		LOWORD(v4) = *(_WORD*)v2[139];
		HIBYTE(a2) = v4 >> 1;
		result = sub_4E5390(a1, (int)&a2, 4, 0, 1);
	}
	return result;
}
// 4D8656: variable 'v4' is possibly undefined

//----- (004D8670) --------------------------------------------------------
int __cdecl sub_4D8670(int a1, _DWORD* a2) {
	int result;           // eax
	__int16 v3;           // ax
	unsigned __int16* v4; // ecx
	char v5[5];           // [esp+4h] [ebp-8h]

	result = a2[139];
	if (result) {
		v5[0] = -60;
		v5[1] = 12;
		v3 = sub_578AC0(a2);
		v4 = (unsigned __int16*)a2[139];
		*(_WORD*)&v5[2] = v3;
		v5[4] = 100 * *v4 / v4[2];
		result = sub_4E5390(a1, (int)v5, 5, 0, 1);
	}
	return result;
}

//----- (004D86E0) --------------------------------------------------------
char* __cdecl sub_4D86E0(int a1) {
	int v1;       // edi
	char* result; // eax
	char* v3;     // esi

	v1 = a1;
	result = sub_417090(a1);
	v3 = result;
	if (result) {
		result = (char*)*((_DWORD*)result + 514);
		if (result) {
			if (*((_DWORD*)result + 139)) {
				LOBYTE(a1) = 67;
				*(_WORD*)((char*)&a1 + 1) = **(_WORD**)(*((_DWORD*)v3 + 514) + 556);
				sub_4E5390(v1, (int)&a1, 3, 0, 1);
				result = (char*)nox_common_gameFlags_check_40A5C0(4096);
				if (result)
					result = (char*)sub_4D8670(v1 | 0x80, *((_DWORD**)v3 + 514));
			}
		}
	}
	return result;
}

//----- (004D8760) --------------------------------------------------------
__int16 __cdecl sub_4D8760(int a1, __int16 a2, __int16 a3) {
	__int16 result; // ax
	char v4[5];     // [esp+0h] [ebp-8h]

	result = a3;
	if (a3 < 0) {
		*(_WORD*)&v4[3] = a3;
		v4[0] = 66;
		*(_WORD*)&v4[1] = a2;
		result = sub_4E5420(a1, v4, 5, 0, 1);
	}
	return result;
}

//----- (004D87A0) --------------------------------------------------------
int __cdecl sub_4D87A0(int a1, _DWORD* a2) {
	int result; // eax
	_WORD* v3;  // eax
	char v4[7]; // [esp+4h] [ebp-8h]

	result = a2[139];
	if (result) {
		if (*(_WORD*)(result + 4)) {
			v4[0] = 68;
			*(_WORD*)&v4[1] = sub_578AC0(a2);
			v3 = (_WORD*)a2[139];
			*(_WORD*)&v4[3] = *v3;
			*(_WORD*)&v4[5] = v3[2];
			result = sub_4E5390(a1, (int)v4, 7, 0, 0);
		}
	}
	return result;
}

//----- (004D8800) --------------------------------------------------------
int __cdecl sub_4D8800(int a1, int a2) {
	int result; // eax
	int v3;     // eax

	result = a2;
	if (*(_BYTE*)(a2 + 8) & 4) {
		v3 = *(_DWORD*)(a2 + 748);
		LOBYTE(a2) = 71;
		BYTE1(a2) = *(_BYTE*)(v3 + 91);
		result = sub_4E5390(a1, (int)&a2, 2, 0, 1);
	}
	return result;
}

//----- (004D8840) --------------------------------------------------------
int __cdecl sub_4D8840(int a1, int a2) {
	char v3;    // cl
	__int16 v5; // [esp+0h] [ebp-2h]

	v3 = *(_BYTE*)(a2 + 440);
	LOBYTE(v5) = 91;
	HIBYTE(v5) = v3;
	return sub_4E5420(a1, &v5, 2, 0, 1);
}

//----- (004D8870) --------------------------------------------------------
int __cdecl sub_4D8870(int a1, int a2) {
	int result; // eax
	int v3;     // eax
	char v4[5]; // [esp+0h] [ebp-8h]

	result = a2;
	if (*(_BYTE*)(a2 + 8) & 4) {
		v3 = *(_DWORD*)(a2 + 748);
		v4[0] = 74;
		*(_DWORD*)&v4[1] = *(_DWORD*)(*(_DWORD*)(v3 + 276) + 2164);
		result = sub_4E5420(a1, v4, 5, 0, 1);
	}
	return result;
}

//----- (004D88C0) --------------------------------------------------------
int __cdecl sub_4D88C0(int a1, int a2) {
	int result; // eax
	int v3;     // esi
	char v4[7]; // [esp+4h] [ebp-8h]

	result = a2;
	v3 = *(_DWORD*)(a2 + 748);
	if (*(_BYTE*)(a2 + 8) & 4 && (!v3 || *(_BYTE*)(*(_DWORD*)(v3 + 276) + 2251))) {
		v4[0] = -34;
		*(_WORD*)&v4[1] = sub_578AC0((_DWORD*)a2);
		*(_WORD*)&v4[3] = *(_WORD*)(v3 + 4);
		*(_WORD*)&v4[5] = *(_WORD*)(v3 + 8);
		result = sub_4E5450(a1, v4, 7, 0, 1);
	}
	return result;
}

//----- (004D8930) --------------------------------------------------------
int __cdecl sub_4D8930(int a1, int a2) {
	int result; // eax
	int v3;     // esi
	char v4[5]; // [esp+4h] [ebp-8h]

	result = a2;
	v3 = *(_DWORD*)(a2 + 748);
	if (*(_BYTE*)(a2 + 8) & 4 && (!v3 || *(_BYTE*)(*(_DWORD*)(v3 + 276) + 2251))) {
		v4[0] = 69;
		*(_WORD*)&v4[1] = sub_578AC0((_DWORD*)a2);
		*(_WORD*)&v4[3] = *(_WORD*)(v3 + 4);
		result = sub_4E5450(a1, v4, 5, 0, 1);
	}
	return result;
}

//----- (004D8990) --------------------------------------------------------
char __cdecl sub_4D8990(int a1, int a2, char a3) {
	char result; // al
	int v4;      // edi
	__int16 v5;  // ax
	int v6;      // ecx
	__int16 v7;  // ax
	char v8[14]; // [esp+8h] [ebp-10h]

	result = *(_BYTE*)(a2 + 8);
	v4 = *(_DWORD*)(a2 + 748);
	if (result & 4) {
		v8[0] = 72;
		v5 = sub_578AC0((_DWORD*)a2);
		v6 = *(_DWORD*)(a2 + 556);
		*(_WORD*)&v8[1] = v5;
		*(_WORD*)&v8[5] = *(_WORD*)(v4 + 8);
		v7 = *(_WORD*)(a2 + 490);
		*(_WORD*)&v8[3] = *(_WORD*)(v6 + 4);
		*(_WORD*)&v8[7] = v7;
		*(_WORD*)&v8[9] = *(_WORD*)(*(_DWORD*)(v4 + 276) + 2235);
		*(_WORD*)&v8[11] = *(_WORD*)(*(_DWORD*)(v4 + 276) + 2239);
		v8[13] = a3;
		result = sub_4E5420(a1, v8, 14, 0, 1);
	}
	return result;
}

//----- (004D8A30) --------------------------------------------------------
int __cdecl sub_4D8A30(int a1, int a2) {
	char v3[5]; // [esp+0h] [ebp-8h]

	v3[0] = 73;
	*(_DWORD*)&v3[1] = a2;
	return sub_4E5420(a1, v3, 5, 0, 1);
}

//----- (004D8A60) --------------------------------------------------------
int __cdecl sub_4D8A60(int a1, int a2) {
	__int16 v3; // ax
	__int16 v4; // cx
	char v5[5]; // [esp+4h] [ebp-8h]

	if (*(_DWORD*)(a2 + 8) & 0x13001000)
		return sub_4D8AD0(a1, a2);
	v5[0] = 75;
	v3 = sub_578AC0((_DWORD*)a2);
	v4 = *(_WORD*)(a2 + 4);
	*(_WORD*)&v5[1] = v3;
	*(_WORD*)&v5[3] = v4;
	sub_4E5390(a1, (int)v5, 5, 0, 0);
	return sub_4D87A0(a1, (_DWORD*)a2);
}

//----- (004D8AD0) --------------------------------------------------------
int __cdecl sub_4D8AD0(int a1, int a2) {
	int v2;     // esi
	int v3;     // eax
	int v4;     // edx
	char v6[9]; // [esp+8h] [ebp-Ch]

	v6[0] = 76;
	v2 = *(_DWORD*)(a2 + 692);
	*(_WORD*)&v6[1] = sub_578AC0((_DWORD*)a2);
	*(_WORD*)&v6[3] = *(_WORD*)(a2 + 4);
	v3 = 0;
	v4 = v2;
	do {
		if (*(_DWORD*)v4)
			v6[v3 + 5] = *(_BYTE*)(*(_DWORD*)v4 + 4);
		else
			v6[v3 + 5] = -1;
		++v3;
		v4 += 4;
	} while (v3 < 4);
	sub_4E5390(a1, (int)v6, 9, 0, 0);
	return sub_4D87A0(a1, (_DWORD*)a2);
}

//----- (004D8B50) --------------------------------------------------------
int __cdecl sub_4D8B50(int a1, int a2) {
	char v3[5]; // [esp+4h] [ebp-8h]

	v3[0] = 77;
	*(_WORD*)&v3[1] = sub_578AC0((_DWORD*)a2);
	*(_WORD*)&v3[3] = *(_WORD*)(a2 + 4);
	return sub_4E5390(a1, (int)v3, 5, 0, 0);
}

//----- (004D8B90) --------------------------------------------------------
int __cdecl sub_4D8B90(int a1, char a2) {
	int result; // eax
	char v3[8]; // [esp+0h] [ebp-8h]

	result = a1;
	if (a1) {
		if (!(*(_BYTE*)(a1 + 8) & 4))
			return result;
		v3[0] = 88;
		*(_WORD*)&v3[1] = sub_578AC0((_DWORD*)a1);
	} else {
		v3[0] = 88;
		*(_WORD*)&v3[1] = 0;
	}
	v3[3] = a2;
	*(_DWORD*)&v3[4] = *(_DWORD*)&byte_5D4594[2598000];
	return sub_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8BF0) --------------------------------------------------------
int __cdecl sub_4D8BF0(int a1, char a2) {
	char v3[8]; // [esp+0h] [ebp-8h]

	v3[0] = 89;
	if (a1)
		*(_WORD*)&v3[1] = *(unsigned __int8*)(a1 + 57);
	else
		*(_WORD*)&v3[1] = 0;
	v3[3] = a2;
	*(_DWORD*)&v3[4] = *(_DWORD*)&byte_5D4594[2598000];
	return sub_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8C40) --------------------------------------------------------
int __cdecl sub_4D8C40(int a1) {
	__int16 v1; // cx
	char v3[8]; // [esp+0h] [ebp-8h]

	v1 = *(unsigned __int8*)(a1 + 57);
	v3[0] = 86;
	*(_WORD*)&v3[1] = v1;
	v3[3] = 0;
	*(_DWORD*)&v3[4] = *(_DWORD*)&byte_5D4594[2598000];
	return sub_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8C80) --------------------------------------------------------
int __cdecl sub_4D8C80(int a1, char a2) {
	char v3[8]; // [esp+0h] [ebp-8h]

	v3[0] = 87;
	if (a1)
		*(_WORD*)&v3[1] = *(unsigned __int8*)(a1 + 57);
	else
		*(_WORD*)&v3[1] = -1;
	v3[3] = a2;
	*(_DWORD*)&v3[4] = *(_DWORD*)&byte_5D4594[2598000];
	return sub_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8CD0) --------------------------------------------------------
int __cdecl sub_4D8CD0(int a1) {
	int result; // eax
	int v2;     // esi
	char v3[7]; // [esp+4h] [ebp-8h]

	result = a1;
	v2 = *(_DWORD*)(a1 + 748);
	if (*(_BYTE*)(a1 + 8) & 4) {
		v3[0] = 85;
		*(_WORD*)&v3[1] = sub_578AC0((_DWORD*)a1);
		*(_WORD*)&v3[3] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 2152);
		*(_WORD*)&v3[5] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 2156);
		result = sub_4E5420(255, v3, 7, 0, 1);
	}
	return result;
}

//----- (004D8D40) --------------------------------------------------------
char* __cdecl sub_4D8D40(int a1) {
	char* result;        // eax
	char* i;             // esi
	char* v3;            // esi
	double v4;           // st7
	int v5;              // esi
	int v6;              // eax
	float v7;            // [esp+0h] [ebp-Ch]
	unsigned __int8* v8; // [esp+4h] [ebp-8h]
	int v9;              // [esp+10h] [ebp+4h]

	result = (char*)a1;
	if (*(_BYTE*)(a1 + 8) & 4) {
		++*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2140);
		result = (char*)nox_common_gameFlags_check_40A5C0(1024);
		if (result) {
			if (sub_40AA00() && !sub_40AA20()) {
				for (i = sub_416EA0(); i; i = sub_416EE0((int)i)) {
					if (i[3680] & 1)
						sub_4174F0((int)i, 256);
				}
				sub_40AA30(1);
			}
			result = (char*)nox_common_gameFlags_check_40A5C0(0x4000000);
			if (!result) {
				result = (char*)sub_40A300();
				if (!result) {
					result = (char*)sub_40AA00();
					if (result) {
						if (!sub_417DA0(4)) {
							v5 = sub_40A770();
							result = (char*)sub_40AA40();
							if (v5 >= (int)result)
								return result;
							v8 = &byte_587000[198928];
							v4 = sub_419D40(&byte_587000[198960]);
							goto LABEL_22;
						}
						v9 = sub_417DD0();
						result = (char*)sub_40AA40();
						if (v9 < (int)result) {
							result = sub_418B10();
							v3 = result;
							if (result) {
								while (sub_40A830((int)v3) != 1) {
									result = sub_418B60((int)v3);
									v3 = result;
									if (!result)
										return result;
								}
								v8 = &byte_587000[198872];
								v4 = sub_419D40(&byte_587000[198904]);
							LABEL_22:
								v7 = v4;
								v6 = nox_float2int(v7);
								return (char*)sub_40A2A0(v6, (const char*)v8);
							}
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (004D8E90) --------------------------------------------------------
int __cdecl sub_4D8E90(int a1, int a2) {
	int result; // eax

	result = a1;
	if (*(_BYTE*)(a1 + 8) & 4) {
		result = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
		*(_DWORD*)(result + 2136) += a2;
	}
	return result;
}

//----- (004D8EC0) --------------------------------------------------------
int __cdecl sub_4D8EC0(int a1, int a2) {
	int result; // eax

	result = a1;
	if (*(_BYTE*)(a1 + 8) & 4) {
		result = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
		*(_DWORD*)(result + 2136) -= a2;
	}
	return result;
}

//----- (004D8EF0) --------------------------------------------------------
int __cdecl sub_4D8EF0(int a1) {
	int v1;      // eax
	char v3[11]; // [esp+0h] [ebp-Ch]

	v3[0] = 78;
	v1 = *(_DWORD*)(a1 + 748);
	*(_WORD*)&v3[1] = *(_WORD*)(a1 + 36);
	*(_DWORD*)&v3[3] = *(_DWORD*)(*(_DWORD*)(v1 + 276) + 2136);
	*(_DWORD*)&v3[7] = *(_DWORD*)(*(_DWORD*)(v1 + 276) + 2140);
	return sub_4E5390(255, (int)v3, 11, 0, 1);
}

//----- (004D8F50) --------------------------------------------------------
int __cdecl sub_4D8F50(int a1, int a2) {
	char v3[13]; // [esp+0h] [ebp-10h]

	v3[0] = -45;
	*(_DWORD*)&v3[1] = a2;
	*(_DWORD*)&v3[5] = sub_40A230();
	*(_DWORD*)&v3[9] = *(_DWORD*)&byte_5D4594[2598000];
	return sub_4E5390(a1, (int)v3, 13, 0, 1);
}

//----- (004D8F90) --------------------------------------------------------
int __cdecl sub_4D8F90(int a1, _DWORD* a2) {
	char v3[7]; // [esp+4h] [ebp-8h]

	v3[0] = 90;
	*(_WORD*)&v3[1] = sub_578AC0(a2);
	*(_DWORD*)&v3[3] = a2[85];
	return sub_4E5390(a1, (int)v3, 7, 0, 1);
}

//----- (004D8FD0) --------------------------------------------------------
void __cdecl sub_4D8FD0(int a1, _DWORD* a2) {
	_DWORD* v2; // esi

	v2 = a2;
	if ((unsigned int)0x800000 & a2[2]) {
		*(_WORD*)((char*)&a2 + 1) = sub_578AC0(a2);
		LOBYTE(a2) = 56 - ((v2[4] & 0x1000000) != 0);
		sub_4E5420(a1, &a2, 3, 0, 1);
	}
}

//----- (004D9020) --------------------------------------------------------
int __cdecl sub_4D9020(int a1, int a2) {
	int v2;      // esi
	__int16 v3;  // ax
	double v4;   // st7
	__int64 v5;  // rax
	double v6;   // st7
	__int64 v7;  // rax
	double v8;   // st7
	int result;  // eax
	__int16 v10; // ax
	double v11;  // st7
	__int16 v12; // ax
	double v13;  // st7
	_DWORD* v14; // [esp-4h] [ebp-10h]
	char v15[6]; // [esp+4h] [ebp-8h]

	v2 = a2;
	if (*(_BYTE*)(a2 + 20) & 0x20) {
		v3 = *(_WORD*)(a2 + 36);
		v15[0] = -97;
		v4 = *(float*)(a2 + 104);
		*(_WORD*)&v15[1] = v3;
		v5 = (__int64)v4;
		v6 = *(float*)(a2 + 108);
		v15[3] = v5;
		v7 = (__int64)v6;
		v8 = *(float*)(a2 + 116);
		v15[4] = v7;
		v15[5] = (__int64)v8;
		result = sub_40EBC0(a1, 1, v15, 6);
	} else {
		v14 = (_DWORD*)a2;
		if (*(float*)(a2 + 104) < 0.0) {
			LOBYTE(a2) = 95;
			v12 = sub_578AC0(v14);
			v13 = *(float*)(v2 + 104);
			*(_WORD*)((char*)&a2 + 1) = v12;
			v11 = -v13;
		} else {
			LOBYTE(a2) = 94;
			v10 = sub_578AC0(v14);
			v11 = *(float*)(v2 + 104);
			*(_WORD*)((char*)&a2 + 1) = v10;
		}
		HIBYTE(a2) = (__int64)v11;
		result = sub_40EBC0(a1, 1, &a2, 4);
	}
	return result;
}

//----- (004D90E0) --------------------------------------------------------
int __cdecl sub_4D90E0(int a1, char a2) {
	char v3[2]; // [esp+0h] [ebp-2h]

	v3[0] = -105;
	v3[1] = a2;
	return sub_40EBC0(a1, 1, v3, 2);
}

//----- (004D9110) --------------------------------------------------------
int __cdecl sub_4D9110(float* a1, int a2) {
	int result; // eax
	int i;      // edi
	int v4;     // esi
	double v5;  // st7
	double v6;  // st6
	double v7;  // st5

	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		v4 = *(_DWORD*)(*(_DWORD*)(i + 748) + 276);
		v5 = *a1 - *(float*)(v4 + 3632);
		v6 = a1[1] - *(float*)(v4 + 3636);
		v7 = v6 * v6 + v5 * v5;
		if (v7 < 90000.0)
			sub_4D90E0(*(unsigned __int8*)(v4 + 2064), (__int64)((1.0 - v7 * 0.000011111111) * (double)a2));
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004D91A0) --------------------------------------------------------
int __cdecl sub_4D91A0(int a1, int a2) {
	char v3[5]; // [esp+8h] [ebp-8h]

	v3[0] = 108;
	*(_WORD*)&v3[1] = sub_578AC0((_DWORD*)a2);
	*(_WORD*)&v3[3] = *(_WORD*)(a2 + 4);
	if (nox_common_gameFlags_check_40A5C0(0x8000000))
		v3[4] |= 0x80u;
	sub_4E5390(a1, (int)v3, 5, 0, 1);
	return sub_4D85C0(a1, (_DWORD*)a2);
}

//----- (004D9200) --------------------------------------------------------
int __cdecl sub_4D9200(int a1, int a2) {
	int v4; // [esp+0h] [ebp-4h]

	LOBYTE(v4) = 109;
	*(_WORD*)((char*)&v4 + 1) = *(_WORD*)(a2 + 36);
	if (nox_common_gameFlags_check_40A5C0(0x8000000))
		BYTE2(v4) |= 0x80u;
	return sub_4E5390(a1, (int)&v4, 3, 0, 1);
}

//----- (004D9250) --------------------------------------------------------
int __cdecl sub_4D9250(int a1, int a2) {
	char v3[5]; // [esp+8h] [ebp-8h]

	v3[0] = -37;
	*(_WORD*)&v3[1] = sub_578AC0((_DWORD*)a2);
	*(_WORD*)&v3[3] = *(_WORD*)(a2 + 4);
	sub_4E5390(a1, (int)v3, 5, 0, 1);
	return sub_4D85C0(a1, (_DWORD*)a2);
}

//----- (004D92A0) --------------------------------------------------------
int __cdecl sub_4D92A0(int a1, _DWORD* a2) {
	int v2;     // ecx
	char v4[3]; // [esp+0h] [ebp-4h]
	char v5;    // [esp+3h] [ebp-1h]

	v5 = HIBYTE(v2);
	v4[0] = -36;
	*(_WORD*)&v4[1] = sub_578AC0(a2);
	return sub_4E5390(a1, (int)v4, 3, 0, 1);
}

//----- (004D92D0) --------------------------------------------------------
int __cdecl sub_4D92D0(int a1, int a2) {
	int result; // eax
	int v3;     // edi
	int v4;     // eax
	int v5;     // edx
	char v6[7]; // [esp+8h] [ebp-8h]

	result = *(_DWORD*)&byte_5D4594[1556320];
	v3 = *(_DWORD*)(a2 + 692);
	if (!*(_DWORD*)&byte_5D4594[1556320]) {
		result = sub_4E3AA0((CHAR*)&byte_587000[198984]);
		*(_DWORD*)&byte_5D4594[1556320] = result;
	}
	if (*(_DWORD*)(a2 + 8) & 0x13001000 || *(unsigned __int16*)(a2 + 4) == result) {
		v6[0] = 103;
		*(_WORD*)&v6[1] = sub_578AC0((_DWORD*)a2);
		v4 = 0;
		v5 = v3;
		do {
			if (*(_DWORD*)v5)
				v6[v4 + 3] = *(_BYTE*)(*(_DWORD*)v5 + 4);
			else
				v6[v4 + 3] = -1;
			++v4;
			v5 += 4;
		} while (v4 < 4);
		result = sub_4E5420(a1, v6, 7, 0, 1);
	}
	return result;
}

//----- (004D9360) --------------------------------------------------------
int __cdecl sub_4D9360(int a1, _DWORD* a2, char a3, int a4) {
	char v5[8]; // [esp+0h] [ebp-8h]

	v5[0] = 104;
	*(_WORD*)&v5[1] = sub_578AC0(a2);
	v5[7] = a3;
	*(_DWORD*)&v5[3] = a4;
	return sub_4E5420(a1, v5, 8, 0, 1);
}

//----- (004D93A0) --------------------------------------------------------
_DWORD* __cdecl sub_4D93A0(int a1, int a2) {
	int v2;         // eax
	char* v3;       // ecx
	int v4;         // eax
	int v5;         // esi
	int v6;         // edx
	char* v7;       // ebx
	_DWORD* result; // eax
	_DWORD* i;      // esi
	char v10[21];   // [esp+10h] [ebp-18h]

	v10[0] = 105;
	v2 = *(_DWORD*)(a2 + 748);
	*(_WORD*)&v10[1] = *(_WORD*)(a2 + 36);
	if (*(_BYTE*)(a2 + 540))
		v10[2] |= 0x80u;
	v3 = &v10[3];
	v4 = v2 + 2076;
	v5 = 6;
	do {
		v6 = v4;
		v7 = v3;
		v4 += 3;
		v3 += 3;
		--v5;
		*(_WORD*)v7 = *(_WORD*)v6;
		v7[2] = *(_BYTE*)(v6 + 2);
	} while (v5);
	result = (_DWORD*)sub_4E5390(a1, (int)v10, 21, 0, 1);
	for (i = *(_DWORD**)(a2 + 504); i; i = (_DWORD*)i[124]) {
		if (i[4] & 0x100)
			result = sub_4D82F0(a1, i);
	}
	return result;
}

//----- (004D9440) --------------------------------------------------------
int __cdecl sub_4D9440(int a1, int a2) {
	char v3[68]; // [esp+Ch] [ebp-44h]

	v3[0] = -43;
	v3[1] = 1;
	strcpy(&v3[2], (const char*)a2);
	*(_WORD*)&v3[66] = *(_WORD*)(a2 + 72);
	return sub_4E5420(a1, v3, 68, 0, 1);
}

//----- (004D94A0) --------------------------------------------------------
int __cdecl sub_4D94A0(int a1, const char* a2) {
	char v3[68]; // [esp+8h] [ebp-44h]

	v3[0] = -43;
	v3[1] = 2;
	strcpy(&v3[2], a2);
	return sub_4E5420(a1, v3, 68, 0, 1);
}

//----- (004D9500) --------------------------------------------------------
int __cdecl sub_4D9500(int a1, int a2) {
	char v3[68]; // [esp+Ch] [ebp-44h]

	v3[0] = -43;
	v3[1] = 3;
	strcpy(&v3[2], (const char*)a2);
	*(_WORD*)&v3[66] = *(_WORD*)(a2 + 72);
	return sub_4E5420(a1, v3, 68, 0, 1);
}

//----- (004D9560) --------------------------------------------------------
int __cdecl sub_4D9560(int a1, char a2, int a3) {
	int v3;     // ecx
	char v5[3]; // [esp+0h] [ebp-4h]
	char v6;    // [esp+3h] [ebp-1h]

	v6 = HIBYTE(v3);
	v5[1] = a2;
	v5[0] = -42;
	v5[2] = a3 == 1;
	return sub_4E5420(a1, v5, 3, 0, 1);
}

//----- (004D95A0) --------------------------------------------------------
int __cdecl sub_4D95A0(int a1, char a2, char a3, char a4, __int16 a5) {
	char v6[6]; // [esp+0h] [ebp-8h]

	v6[1] = a3;
	v6[3] = a4;
	v6[2] = a2;
	v6[0] = -40;
	*(_WORD*)&v6[4] = a5;
	return sub_4E5390(a1, (int)v6, 6, 0, 1);
}

//----- (004D95F0) --------------------------------------------------------
int __cdecl sub_4D95F0(int a1, char a2, __int16 a3) {
	char v4[4]; // [esp+0h] [ebp-4h]

	v4[1] = a2;
	v4[0] = -39;
	*(_WORD*)&v4[2] = a3;
	return sub_4E5390(a1, (int)v4, 4, 0, 1);
}

//----- (004D9630) --------------------------------------------------------
int __cdecl sub_4D9630(int a1, int a2, char a3) {
	char v4[6]; // [esp+0h] [ebp-8h]

	*(_DWORD*)&v4[1] = a2;
	v4[0] = -33;
	v4[5] = a3;
	return sub_4E5420(a1, v4, 6, 0, 1);
}

//----- (004D9670) --------------------------------------------------------
int __cdecl sub_4D9670(int a1, _DWORD* a2, char a3) {
	char v4[4]; // [esp+0h] [ebp-4h]

	v4[0] = -32;
	*(_WORD*)&v4[1] = sub_578AC0(a2);
	v4[3] = a3;
	return sub_4E5390(a1, (int)v4, 4, 0, 0);
}

//----- (004D96B0) --------------------------------------------------------
int __cdecl sub_4D96B0(int a1, _DWORD* a2) {
	int v2;     // ecx
	char v4[3]; // [esp+0h] [ebp-4h]
	char v5;    // [esp+3h] [ebp-1h]

	v5 = HIBYTE(v2);
	v4[0] = -31;
	*(_WORD*)&v4[1] = sub_578AC0(a2);
	return sub_4E5390(a1, (int)v4, 3, 0, 0);
}

//----- (004D96E0) --------------------------------------------------------
int __cdecl sub_4D96E0(int a1) {
	char v2[1]; // [esp+1h] [ebp-1h]

	v2[0] = 113;
	return sub_4E5390(a1, (int)v2, 1, 0, 0);
}

//----- (004D9700) --------------------------------------------------------
int __cdecl sub_4D9700(int a1) {
	int result; // eax

	result = a1;
	switch (a1) {
	case 0:
		result = sub_4DA390("report.c:NoComp");
		break;
	case 1:
		result = sub_4DA390("report.c:MinComp");
		break;
	case 2:
		result = sub_4DA390("report.c:AveComp");
		break;
	case 3:
		result = sub_4DA390("report.c:UserComp");
		break;
	default:
		return result;
	}
	return result;
}

//----- (004D9760) --------------------------------------------------------
int __cdecl sub_4D9760(int a1) {
	int result; // eax
	int v2;     // edx

	result = a1;
	if (*(_BYTE*)(a1 + 8) & 4) {
		v2 = *(_DWORD*)(a1 + 748);
		LOBYTE(a1) = -53;
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 1, 0, 1);
	}
	return result;
}

//----- (004D97A0) --------------------------------------------------------
int __cdecl sub_4D97A0(int a1, _DWORD* a2, int a3) {
	LOBYTE(a3) = (a3 != 1) + 52;
	*(_WORD*)((char*)&a3 + 1) = sub_578AC0(a2);
	return sub_4E5390(a1, (int)&a3, 3, 0, 1);
}

//----- (004D97E0) --------------------------------------------------------
int __cdecl sub_4D97E0(int a1) {
	char v2[1]; // [esp+1h] [ebp-1h]

	v2[0] = 54;
	return sub_4E5390(a1, (int)v2, 1, 0, 1);
}

//----- (004D9800) --------------------------------------------------------
int __cdecl sub_4D9800(int a1, int a2) {
	int v2;     // ecx
	char v4[3]; // [esp+0h] [ebp-4h]
	char v5;    // [esp+3h] [ebp-1h]

	v5 = HIBYTE(v2);
	v4[0] = -28;
	v4[1] = a1 != 0;
	v4[2] = a2 != 0;
	return sub_4E5390(255, (int)v4, 3, 0, 1);
}

//----- (004D9840) --------------------------------------------------------
void __cdecl sub_4D9840(_DWORD* a1, _DWORD* a2) {
	char v3[7]; // [esp+4h] [ebp-8h]

	if (a1 && a2) {
		v3[0] = -98;
		v3[1] = 7;
		v3[2] = 0;
		*(_WORD*)&v3[3] = sub_578AC0(a1);
		*(_WORD*)&v3[5] = sub_578AC0(a2);
	}
	sub_4E5390(255, (int)v3, 7, 0, 1);
}

//----- (004D98A0) --------------------------------------------------------
int __cdecl sub_4D98A0(_DWORD* a1, _DWORD* a2) {
	char v3[7]; // [esp+4h] [ebp-8h]

	if (a1 && a2) {
		v3[0] = -98;
		v3[1] = 14;
		v3[2] = 0;
		*(_WORD*)&v3[3] = sub_578AC0(a1);
		*(_WORD*)&v3[5] = sub_578AC0(a2);
	}
	return sub_4E5390(255, (int)v3, 7, 0, 1);
}

//----- (004D9900) --------------------------------------------------------
void __cdecl sub_4D9900(int a1) {
	int v1;     // ebp
	int v2;     // esi
	_WORD* v3;  // edi
	int v4;     // eax
	int v5;     // eax
	int i;      // edi
	char* v7;   // eax
	int j;      // edi
	int v9;     // ebx
	int v10;    // eax
	int k;      // edi
	int v12;    // ebx
	int v13;    // eax
	int v14;    // eax
	_WORD* v15; // [esp+Ch] [ebp-4h]
	int v16;    // [esp+14h] [ebp+4h]

	v1 = a1;
	if (a1 && *(_BYTE*)(a1 + 8) & 4) {
		v2 = *(_DWORD*)(a1 + 748);
		v3 = *(_WORD**)(a1 + 556);
		v15 = *(_WORD**)(a1 + 556);
		v16 = *(int*)(v2 + 228);
		if (*(float*)(v2 + 232) != *(float*)&v16) {
			sub_4D8A30(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v16);
			*(_DWORD*)(v2 + 232) = *(_DWORD*)(v2 + 228);
		}
		v4 = *(_DWORD*)(v2 + 276);
		if (*(_DWORD*)(v4 + 2168) != *(_DWORD*)(v4 + 2164)) {
			sub_4D8870(*(unsigned __int8*)(v4 + 2064), v1);
			*(_DWORD*)(*(_DWORD*)(v2 + 276) + 2168) = *(_DWORD*)(*(_DWORD*)(v2 + 276) + 2164);
		}
		v5 = *(_DWORD*)(v2 + 276);
		if (*(_BYTE*)(v5 + 2172) != *(_BYTE*)(v1 + 440)) {
			sub_4D8840(*(unsigned __int8*)(v5 + 2064), v1);
			*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2172) = *(_BYTE*)(v1 + 440);
		}
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			for (i = 0; i < 32; ++i) {
				v7 = sub_417090(i);
				if (v7 && *((_DWORD*)v7 + 514) &&
				    *(_DWORD*)(v2 + 320) != *(unsigned __int8*)(i + v2 + 452)) {
					sub_4D9D60(i, v1);
					*(_BYTE*)(i + v2 + 452) = *(_BYTE*)(v2 + 320);
				}
			}
			for (j = 0; j < 32; ++j) {
				v9 = 0;
				if (!*(_DWORD*)&byte_5D4594[1556324])
					*(_DWORD*)&byte_5D4594[1556324] = sub_4E3AA0((CHAR*)&byte_587000[199072]);
				if (sub_417090(j)) {
					v10 = sub_4E7980(v1);
					if (v10) {
						while (*(unsigned __int16*)(v10 + 4) !=
						       *(_DWORD*)&byte_5D4594[1556324]) {
							v10 = sub_4E7990(v10);
							if (!v10)
								goto LABEL_25;
						}
						v9 = 1;
					}
				LABEL_25:
					if (v9 != *(unsigned __int8*)(j + v2 + 484)) {
						sub_4D9DF0(j, v1, v9);
						*(_BYTE*)(j + v2 + 484) = v9;
					}
				}
			}
			for (k = 0; k < 32; ++k) {
				v12 = 0;
				if (!*(_DWORD*)&byte_5D4594[1556328])
					*(_DWORD*)&byte_5D4594[1556328] = sub_4E3AA0((CHAR*)&byte_587000[199084]);
				if (sub_417090(k)) {
					v13 = sub_4E7980(v1);
					if (v13) {
						while (*(unsigned __int16*)(v13 + 4) !=
						       *(_DWORD*)&byte_5D4594[1556328]) {
							v13 = sub_4E7990(v13);
							if (!v13)
								goto LABEL_37;
						}
						v12 = 1;
					}
				LABEL_37:
					if (v12 != *(unsigned __int8*)(k + v2 + 516)) {
						sub_4D9E30(k, v1, v12);
						*(_BYTE*)(k + v2 + 516) = v12;
					}
				}
			}
			v3 = v15;
		}
		v14 = *(_DWORD*)(v2 + 276);
		if (*(_BYTE*)(v14 + 2184)) {
			sub_4D85C0(*(unsigned __int8*)(v14 + 2064), (_DWORD*)v1);
			sub_4D88C0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v1);
			sub_4D8990(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v1,
				   *(_BYTE*)(*(_DWORD*)(v2 + 276) + 3684));
			*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2184) = 0;
		}
		if (sub_43AF70() == 1) {
			sub_528030(v1);
		} else {
			if (v3 && *v3 != *(_WORD*)(v2 + 10)) {
				sub_4D86E0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064));
				*(_WORD*)(v2 + 10) = *v3;
			}
			if (*(_WORD*)(v2 + 4) != *(_WORD*)(v2 + 6)) {
				sub_4D8930(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v1);
				*(_WORD*)(v2 + 6) = *(_WORD*)(v2 + 4);
			}
		}
	}
}

//----- (004D9C20) --------------------------------------------------------
int __cdecl sub_4D9C20(int a1) {
	int result;  // eax
	int v2;      // ecx
	int v3;      // edx
	char v4[17]; // [esp+0h] [ebp-14h]

	result = a1;
	if (a1) {
		v2 = *(_DWORD*)(a1 + 748);
		v4[0] = -17;
		if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251)) {
			if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251) == 1) {
				*(_DWORD*)&v4[1] = dword_587000_312816;
				*(_DWORD*)&v4[5] = dword_587000_312820;
				v3 = dword_587000_312828;
				*(_DWORD*)&v4[9] = dword_587000_312824;
			} else {
				result = *(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2251) - 2;
				if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251) != 2)
					return result;
				*(_DWORD*)&v4[1] = dword_587000_312800;
				*(_DWORD*)&v4[5] = dword_587000_312804;
				v3 = dword_587000_312812;
				*(_DWORD*)&v4[9] = dword_587000_312808;
			}
		} else {
			*(_DWORD*)&v4[1] = dword_587000_312784;
			*(_DWORD*)&v4[5] = dword_587000_312788;
			v3 = dword_587000_312796;
			*(_DWORD*)&v4[9] = dword_587000_312792;
		}
		*(_DWORD*)&v4[13] = v3;
		result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v4, 17, 0, 1);
	}
	return result;
}

//----- (004D9CF0) --------------------------------------------------------
int __cdecl sub_4D9CF0(int a1) {
	char v2[2]; // [esp+0h] [ebp-2h]

	v2[0] = -16;
	v2[1] = 0;
	return sub_4E5390(a1, (int)v2, 2, 0, 1);
}

//----- (004D9D20) --------------------------------------------------------
int __cdecl sub_4D9D20(int a1, int a2) {
	__int16 v3; // cx
	char v5[4]; // [esp+0h] [ebp-4h]

	v3 = *(_WORD*)(a2 + 36);
	*(_WORD*)v5 = 496;
	*(_WORD*)&v5[2] = v3;
	return sub_4E5390(a1, (int)v5, 4, 0, 1);
}

//----- (004D9D60) --------------------------------------------------------
int __cdecl sub_4D9D60(int a1, int a2) {
	int v2;     // edx
	char v4[5]; // [esp+0h] [ebp-8h]

	v4[0] = -16;
	v4[1] = 4;
	v2 = *(_DWORD*)(a2 + 748);
	*(_WORD*)&v4[3] = *(_WORD*)(a2 + 36);
	v4[2] = *(_BYTE*)(v2 + 320);
	return sub_4E5420(a1, v4, 5, 0, 1);
}

//----- (004D9DB0) --------------------------------------------------------
int __cdecl sub_4D9DB0(int a1, int a2, int a3) {
	char v4[8]; // [esp+0h] [ebp-8h]

	*(_WORD*)&v4[6] = *(_WORD*)(a2 + 36);
	v4[0] = -16;
	v4[1] = 21;
	*(_DWORD*)&v4[2] = a3;
	return sub_4E5420(a1, v4, 8, 0, 1);
}

//----- (004D9DF0) --------------------------------------------------------
int __cdecl sub_4D9DF0(int a1, int a2, char a3) {
	char v4[5]; // [esp+0h] [ebp-8h]

	*(_WORD*)&v4[3] = *(_WORD*)(a2 + 36);
	v4[0] = -16;
	v4[1] = 22;
	v4[2] = a3;
	return sub_4E5420(a1, v4, 5, 0, 1);
}

//----- (004D9E30) --------------------------------------------------------
int __cdecl sub_4D9E30(int a1, int a2, char a3) {
	char v4[5]; // [esp+0h] [ebp-8h]

	*(_WORD*)&v4[3] = *(_WORD*)(a2 + 36);
	v4[0] = -16;
	v4[1] = 23;
	v4[2] = a3;
	return sub_4E5420(a1, v4, 5, 0, 1);
}

//----- (004D9E70) --------------------------------------------------------
int __cdecl sub_4D9E70(int a1) {
	char v2[2]; // [esp+0h] [ebp-2h]

	v2[0] = -16;
	v2[1] = 20;
	return sub_4E5420(a1, v2, 2, 0, 1);
}

//----- (004D9EA0) --------------------------------------------------------
void sub_4D9EA0() { nox_srand(0x2311u); }

//----- (004D9EB0) --------------------------------------------------------
int sub_4D9EB0(int a1, wchar_t* a2, ...) {
	int result;      // eax
	int v3;          // esi
	char v4;         // al
	int v5;          // eax
	wchar_t v6[516]; // [esp+4h] [ebp-408h]
	va_list va;      // [esp+418h] [ebp+Ch]

	va_start(va, a2);
	result = a1;
	if (a1 && *(_BYTE*)(a1 + 8) & 4) {
		v3 = *(_DWORD*)(a1 + 748);
		nox_vswprintf(&v6[260], a2, va);
		LOBYTE(v6[0]) = -88;
		*(wchar_t*)((char*)v6 + 1) = 0;
		HIBYTE(v6[1]) = 0;
		if (sub_4100F0((__int16*)&v6[260]))
			v4 = HIBYTE(v6[1]) | 2;
		else
			v4 = HIBYTE(v6[1]) | 4;
		HIBYTE(v6[1]) = v4;
		v6[2] = 0;
		v6[3] = 0;
		LOBYTE(v6[5]) = 0;
		v6[4] = (unsigned __int8)(nox_wcslen(&v6[260]) + 1);
		if (v6[1] & 0x400) {
			nox_wcscpy((wchar_t*)((char*)&v6[5] + 1), &v6[260]);
			v5 = 2;
		} else {
			nox_sprintf((char*)&v6[5] + 1, "%S", &v6[260]);
			v5 = 1;
		}
		result = sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 1, v6, v5 * LOBYTE(v6[4]) + 11);
	}
	return result;
}

//----- (004D9FD0) --------------------------------------------------------
int sub_4D9FD0(char a1, wchar_t* a2, ...) {
	char v2;         // al
	int v3;          // edi
	int result;      // eax
	int i;           // esi
	wchar_t v6[516]; // [esp+Ch] [ebp-408h]
	va_list va;      // [esp+420h] [ebp+Ch]

	va_start(va, a2);
	nox_vswprintf(&v6[260], a2, va);
	LOBYTE(v6[0]) = -88;
	*(wchar_t*)((char*)v6 + 1) = 0;
	HIBYTE(v6[1]) = a1;
	if (sub_4100F0((__int16*)&v6[260]))
		v2 = HIBYTE(v6[1]) | 2;
	else
		v2 = HIBYTE(v6[1]) | 4;
	HIBYTE(v6[1]) = v2;
	v6[2] = 0;
	v6[3] = 0;
	LOBYTE(v6[5]) = 0;
	v6[4] = (unsigned __int8)(nox_wcslen(&v6[260]) + 1);
	if (v6[1] & 0x400) {
		nox_wcscpy((wchar_t*)((char*)&v6[5] + 1), &v6[260]);
		v3 = 2;
	} else {
		nox_sprintf((char*)&v6[5] + 1, "%S", &v6[260]);
		v3 = 1;
	}
	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), 1, v6,
			   v3 * LOBYTE(v6[4]) + 11);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004DA0F0) --------------------------------------------------------
int __cdecl sub_4DA0F0(int a1, int a2, int* a3) {
	int result; // eax
	int v4;     // edx
	char v5[6]; // [esp+0h] [ebp-8h]

	result = a2;
	switch (a2) {
	case 0:
	case 1:
	case 2:
	case 12:
	case 13:
	case 16:
	case 20:
	case 21:
		v5[1] = a2;
		v4 = *a3;
		v5[0] = -87;
		*(_DWORD*)&v5[2] = v4;
		result = sub_40EBC0(a1, 1, v5, 6);
		break;
	case 17:
		LOWORD(a2) = 4521;
		result = sub_40EBC0(a1, 1, &a2, 2);
		break;
	default:
		return result;
	}
	return result;
}

//----- (004DA180) --------------------------------------------------------
int __cdecl sub_4DA180(int a1, _BYTE* a2) {
	int result; // eax
	int i;      // esi
	int j;      // esi
	int k;      // esi
	char v6[6]; // [esp+8h] [ebp-8h]

	result = a1;
	switch (a1) {
	case 3:
	case 4:
	case 8:
	case 18:
	case 19:
	case 21:
		v6[1] = a1;
		v6[0] = -87;
		*(_DWORD*)&v6[2] = *(_DWORD*)a2;
		result = sub_4DA7C0();
		for (i = result; result; i = result) {
			sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), 1, v6, 6);
			result = sub_4DA7F0(i);
		}
		break;
	case 5:
	case 6:
	case 7:
	case 9:
	case 10:
	case 11:
		*a2 = -87;
		a2[1] = a1;
		result = sub_4DA7C0();
		for (j = result; result; j = result) {
			sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(j + 748) + 276) + 2064), 1, a2, 10);
			result = sub_4DA7F0(j);
		}
		break;
	case 14:
		*a2 = -87;
		a2[1] = a1;
		result = sub_4DA7C0();
		for (k = result; result; k = result) {
			sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(k + 748) + 276) + 2064), 1, a2, 11);
			result = sub_4DA7F0(k);
		}
		break;
	default:
		return result;
	}
	return result;
}

//----- (004DA2C0) --------------------------------------------------------
void __cdecl sub_4DA2C0(int a1, const char* a2, char a3) {
	int v3;      // edx
	char v4[52]; // [esp+Ch] [ebp-34h]

	if (a1 && *(_BYTE*)(a1 + 8) & 4 && a2 && !sub_419E60(a1) && strlen(a2) && strlen(a2) <= 0x30) {
		v4[2] = a3;
		v4[0] = -87;
		v4[1] = 15;
		v3 = *(_DWORD*)(a1 + 748);
		strcpy(&v4[3], a2);
		sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 1, v4, strlen(a2) + 4);
	}
}

//----- (004DA390) --------------------------------------------------------
int __cdecl sub_4DA390(const char* a1) {
	int result; // eax
	int i;      // esi

	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_4DA2C0(i, a1, 0);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004DA3C0) --------------------------------------------------------
int __cdecl sub_4DA3C0(_DWORD* a1) {
	int result; // eax

	result = dword_5d4594_1556844;
	*a1 = dword_5d4594_1556844;
	dword_5d4594_1556844 = 0;
	return result;
}

//----- (004DA3E0) --------------------------------------------------------
int __cdecl sub_4DA3E0(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1556844 = a1;
	return result;
}

//----- (004DA3F0) --------------------------------------------------------
BOOL __cdecl nox_server_strcmpWithoutMapname_4DA3F0(const char* a1, const char* a2) {
	char* v2;       // eax
	const char* v3; // edi
	const char* v4; // ebx
	char* v5;       // eax
	const char* v6; // ecx
	const char* v7; // esi
	BOOL result;    // eax

	strcpy((char*)&byte_5D4594[1556332], a1);
	strcpy((char*)&byte_5D4594[1556588], a2);
	v2 = strchr((const char*)&byte_5D4594[1556332], 58);
	if (v2) {
		v3 = (const char*)&byte_5D4594[1556332];
		*v2 = 0;
		v4 = v2 + 1;
	} else {
		v3 = 0;
		v4 = (const char*)&byte_5D4594[1556332];
	}
	v5 = strchr((const char*)&byte_5D4594[1556588], 58);
	if (v5) {
		v6 = (const char*)&byte_5D4594[1556588];
		*v5 = 0;
		v7 = v5 + 1;
	} else {
		v6 = 0;
		v7 = (const char*)&byte_5D4594[1556588];
	}
	if (v3 && v6 && _strcmpi(v3, v6))
		result = 0;
	else
		result = strcmp(v4, v7) == 0;
	return result;
}

//----- (004DA4F0) --------------------------------------------------------
int __cdecl sub_4DA4F0(char* a1) {
	int i;      // esi
	int result; // eax
	int v3;     // esi
	int v4;     // esi
	int v5;     // esi

	if (strchr(a1, 58)) {
		for (i = sub_4DA790(); i; i = sub_4DA7A0(i)) {
			result = sub_4DA5C0(i, a1);
			if (result)
				return result;
		}
		v3 = sub_4DA870();
		if (v3) {
			do {
				result = sub_4DA5C0(v3, a1);
				if (result)
					break;
				result = sub_4DA880(v3);
				v3 = result;
			} while (result);
			return result;
		}
		return 0;
	}
	v4 = sub_4DA790();
	if (v4) {
		while (1) {
			result = sub_4DA660(v4, a1);
			if (result)
				break;
			v4 = sub_4DA7A0(v4);
			if (!v4)
				goto LABEL_12;
		}
	} else {
	LABEL_12:
		v5 = sub_4DA870();
		if (!v5)
			return 0;
		while (1) {
			result = sub_4DA660(v5, a1);
			if (result)
				break;
			v5 = sub_4DA880(v5);
			if (!v5)
				return 0;
		}
	}
	return result;
}

//----- (004DA5C0) --------------------------------------------------------
int __cdecl sub_4DA5C0(int a1, const char* a2) {
	int v2; // edi

	v2 = a1;
	if (*(_DWORD*)a1 && !strcmp(*(const char**)a1, a2))
		return v2;
	v2 = *(_DWORD*)(a1 + 504);
	if (v2) {
		while (!*(_DWORD*)v2 || strcmp(*(const char**)v2, a2)) {
			v2 = *(_DWORD*)(v2 + 496);
			if (!v2)
				return 0;
		}
		return v2;
	}
	return 0;
}

//----- (004DA660) --------------------------------------------------------
int __cdecl sub_4DA660(int a1, const char* a2) {
	int i;               // edi
	char* v3;            // eax
	const char* v4;      // esi
	const char* v5;      // eax
	bool v6;             // cf
	unsigned __int8 v7;  // dl
	unsigned __int8 v8;  // bl
	int v9;              // eax
	const char* v10;     // eax
	unsigned __int8 v11; // dl
	unsigned __int8 v12; // bl
	char* v14;           // eax

	i = a1;
	if (*(_DWORD*)a1) {
		v3 = strchr(*(const char**)a1, 58);
		v4 = a2;
		if (v3) {
			v5 = v3 + 1;
			while (1) {
				v6 = *v5 < (unsigned int)*v4;
				if (*v5 != *v4)
					break;
				if (*v5) {
					v7 = v5[1];
					v8 = v4[1];
					v6 = v7 < v8;
					if (v7 != v8)
						break;
					v5 += 2;
					v4 += 2;
					if (v7)
						continue;
				}
				v9 = 0;
				goto LABEL_16;
			}
		} else {
			v10 = *(const char**)a1;
			while (1) {
				v6 = *v10 < (unsigned int)*v4;
				if (*v10 != *v4)
					break;
				if (*v10) {
					v11 = v10[1];
					v12 = v4[1];
					v6 = v11 < v12;
					if (v11 != v12)
						break;
					v10 += 2;
					v4 += 2;
					if (v11)
						continue;
				}
				v9 = 0;
				goto LABEL_16;
			}
		}
		v9 = -(int)v6 - ((int)v6 - 1);
	LABEL_16:
		if (!v9)
			return i;
	}
	for (i = *(_DWORD*)(a1 + 504); i; i = *(_DWORD*)(i + 496)) {
		if (*(_DWORD*)i) {
			v14 = strchr(*(const char**)i, 58);
			if (v14) {
				if (!strcmp(v14 + 1, a2))
					return i;
			} else if (!strcmp(*(const char**)i, a2)) {
				return i;
			}
		}
	}
	return 0;
}

//----- (004DA790) --------------------------------------------------------
int sub_4DA790() { return dword_5d4594_1556844; }

//----- (004DA7A0) --------------------------------------------------------
int __cdecl sub_4DA7A0(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 444);
	else
		result = 0;
	return result;
}

//----- (004DA7C0) --------------------------------------------------------
int sub_4DA7C0() {
	char* v0; // eax

	v0 = sub_416EA0();
	if (!v0)
		return 0;
	while (!*((_DWORD*)v0 + 514)) {
		v0 = sub_416EE0((int)v0);
		if (!v0)
			return 0;
	}
	return *((_DWORD*)v0 + 514);
}

//----- (004DA7F0) --------------------------------------------------------
int __cdecl sub_4DA7F0(int a1) {
	char* v1; // eax

	if (!a1)
		return 0;
	if (!(*(_BYTE*)(a1 + 8) & 4))
		return 0;
	v1 = sub_416EE0(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276));
	if (!v1)
		return 0;
	while (!*((_DWORD*)v1 + 514)) {
		v1 = sub_416EE0((int)v1);
		if (!v1)
			return 0;
	}
	return *((_DWORD*)v1 + 514);
}

//----- (004DA840) --------------------------------------------------------
int sub_4DA840() { return dword_5d4594_1556848; }

//----- (004DA850) --------------------------------------------------------
int __cdecl sub_4DA850(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 444);
	else
		result = 0;
	return result;
}

//----- (004DA870) --------------------------------------------------------
int sub_4DA870() { return dword_5d4594_1556860; }

//----- (004DA880) --------------------------------------------------------
int __cdecl sub_4DA880(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 444);
	else
		result = 0;
	return result;
}

//----- (004DA8A0) --------------------------------------------------------
int sub_4DA8A0() { return dword_5d4594_1556852; }

//----- (004DA8B0) --------------------------------------------------------
int __cdecl sub_4DA8B0(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 476);
	else
		result = 0;
	return result;
}

//----- (004DA8D0) --------------------------------------------------------
int __cdecl sub_4DA8D0(int a1) {
	int result; // eax

	result = a1;
	if (!*(_DWORD*)(a1 + 484) && !(*(_BYTE*)(a1 + 8) & 1)) {
		*(_DWORD*)(a1 + 480) = 0;
		*(_DWORD*)(a1 + 476) = dword_5d4594_1556852;
		if (dword_5d4594_1556852)
			*(_DWORD*)(dword_5d4594_1556852 + 480) = a1;
		dword_5d4594_1556852 = a1;
		*(_DWORD*)(a1 + 484) = 1;
		*(_DWORD*)(a1 + 520) = 0;
	}
	return result;
}

//----- (004DA920) --------------------------------------------------------
_DWORD* __cdecl sub_4DA920(_DWORD* a1) {
	_DWORD* result; // eax
	int v2;         // ecx
	int v3;         // ecx
	int v4;         // ecx

	result = a1;
	if (a1[121]) {
		v2 = a1[120];
		if (v2) {
			*(_DWORD*)(v2 + 476) = a1[119];
			v3 = a1[119];
			if (v3) {
				*(_DWORD*)(v3 + 480) = a1[120];
				a1[121] = 0;
				a1[130] = 0;
				return result;
			}
		} else {
			dword_5d4594_1556852 = a1[119];
			v4 = a1[119];
			if (v4)
				*(_DWORD*)(v4 + 480) = 0;
		}
		a1[121] = 0;
		a1[130] = 0;
	}
	return result;
}

//----- (004DA9A0) --------------------------------------------------------
_DWORD* __cdecl sub_4DA9A0(_DWORD* a1) {
	_DWORD* result; // eax
	int v2;         // ecx

	result = a1;
	v2 = a1[4];
	if (!(v2 & 0x410000)) {
		a1[118] = 0;
		a1[4] = v2 | 0x10000;
		a1[117] = dword_5d4594_1556856;
		if (dword_5d4594_1556856)
			*(_DWORD*)(dword_5d4594_1556856 + 472) = a1;
		dword_5d4594_1556856 = a1;
	}
	return result;
}

//----- (004DA9F0) --------------------------------------------------------
_DWORD* __cdecl sub_4DA9F0(_DWORD* a1) {
	_DWORD* result; // eax
	int v2;         // ecx
	int v3;         // ecx
	int v4;         // ecx

	result = a1;
	v2 = a1[4];
	if (v2 & 0x10000) {
		a1[4] = v2 & 0xFFFEFFFF;
		v3 = a1[118];
		if (v3)
			*(_DWORD*)(v3 + 468) = a1[117];
		else
			dword_5d4594_1556856 = a1[117];
		v4 = a1[117];
		if (v4)
			*(_DWORD*)(v4 + 472) = a1[118];
	}
	return result;
}

//----- (004DAA50) --------------------------------------------------------
char __cdecl sub_4DAA50(int a1, int a2, float a3, float a4) {
	int v4; // eax
	int v5; // eax
	int v6; // ecx
	int v7; // eax

	if (!*(_DWORD*)&byte_5D4594[1556864]) {
		*(_DWORD*)&byte_5D4594[1556864] = sub_4E3AA0((CHAR*)&byte_587000[199100]);
		*(_DWORD*)&byte_5D4594[1556868] = sub_4E3AA0((CHAR*)&byte_587000[199108]);
		*(_DWORD*)&byte_5D4594[1556872] = sub_4E3AA0((CHAR*)&byte_587000[199124]);
	}
	v4 = *(_DWORD*)(a1 + 16);
	if (!(v4 & 0x24)) {
		*(_DWORD*)(a1 + 16) = v4 & 0x35E9FEDB;
		*(float*)(a1 + 72) = a3;
		*(float*)(a1 + 56) = a3;
		*(float*)(a1 + 64) = a3;
		*(float*)(a1 + 76) = a4;
		*(float*)(a1 + 60) = a4;
		v5 = *(_DWORD*)(a1 + 56);
		*(float*)(a1 + 68) = a4;
		*(_DWORD*)(a1 + 156) = v5;
		*(float*)(a1 + 160) = a4;
		sub_4E7290(a1);
		if (*(_BYTE*)(a1 + 8) & 6)
			sub_4E7F10(a1);
		if (a2)
			sub_4EC290(a2, a1);
		v6 = *(_DWORD*)(a1 + 16);
		*(_DWORD*)(a1 + 80) = 0;
		*(_DWORD*)(a1 + 84) = 0;
		*(_DWORD*)(a1 + 88) = 0;
		*(_DWORD*)(a1 + 92) = 0;
		*(_DWORD*)(a1 + 16) = v6 | 4;
		*(_DWORD*)(a1 + 136) = *(_DWORD*)&byte_5D4594[2598000];
		*(_DWORD*)(a1 + 128) = *(_DWORD*)&byte_5D4594[2598000];
		if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) &&
		    (*(unsigned __int16*)(a1 + 4) == *(_DWORD*)&byte_5D4594[1556864] ||
		     *(_DWORD*)(a1 + 8) & 0x3001110) &&
		    !(*(_BYTE*)(a1 + 8) & 1)) {
			v7 = *(_DWORD*)(a1 + 16);
			LOBYTE(v7) = v7 | 0x40;
			*(_DWORD*)(a1 + 16) = v7;
		}
		*(_DWORD*)(a1 + 448) = 0;
		*(_DWORD*)(a1 + 444) = dword_5d4594_1556860;
		if (dword_5d4594_1556860)
			*(_DWORD*)(dword_5d4594_1556860 + 448) = a1;
		dword_5d4594_1556860 = a1;
		LOBYTE(v4) = *(_BYTE*)(a1 + 52);
		*(_DWORD*)(a1 + 16) |= 0x2000000u;
		if ((_BYTE)v4 && (!(*(_DWORD*)(a1 + 8) & 0x10000000) || (int)*(_DWORD*)&byte_5D4594[3803228] >= 0)) {
			if (nox_common_gameFlags_check_40A5C0(2048) || (v4 = sub_417DA0(4)) != 0)
				LOBYTE(v4) =
				    (unsigned int)sub_4191D0(*(_BYTE*)(a1 + 52), a1 + 48, 0, *(_DWORD*)(a1 + 36), 0);
		}
	}
	return v4;
}

//----- (004DAC00) --------------------------------------------------------
void sub_4DAC00() {
	int v0;                          // esi
	int v1;                          // eax
	int i;                           // ebp
	int v3;                          // eax
	void(__cdecl * v4)(int, _DWORD); // eax
	unsigned int v5;                 // ecx
	int v6;                          // eax

	v0 = dword_5d4594_1556860;
	if (dword_5d4594_1556860) {
		do {
			v1 = *(_DWORD*)(v0 + 508);
			for (i = *(_DWORD*)(v0 + 444); v1; v1 = *(_DWORD*)(v0 + 508)) {
				if (!(*(_BYTE*)(v1 + 16) & 0x20))
					break;
				sub_4EC290(*(_DWORD*)(v1 + 508), v0);
			}
			if (*(_BYTE*)(v0 + 8) & 1) {
				*(_DWORD*)(v0 + 448) = 0;
				*(_DWORD*)(v0 + 444) = dword_5d4594_1556848;
				if (dword_5d4594_1556848)
					*(_DWORD*)(dword_5d4594_1556848 + 448) = v0;
				dword_5d4594_1556848 = v0;
			} else {
				v3 = *(_DWORD*)(v0 + 16);
				if (v3 & 0x10000) {
					*(_DWORD*)(v0 + 16) = v3 & 0xFFFEFFFF;
					sub_4DA9A0((_DWORD*)v0);
				}
				if (*(_DWORD*)(v0 + 16) & 0x80000 && !nox_common_gameFlags_check_40A5C0(4096))
					sub_4EC5E0(v0);
				if ((*(_DWORD*)(v0 + 744) || *(float*)(v0 + 80) != 0.0 || *(float*)(v0 + 84) != 0.0) &&
				    (signed char)*(_BYTE*)(v0 + 8) >= 0) {
					sub_4DA8D0(v0);
				}
				*(_DWORD*)(v0 + 448) = 0;
				*(_DWORD*)(v0 + 444) = dword_5d4594_1556844;
				if (dword_5d4594_1556844)
					*(_DWORD*)(dword_5d4594_1556844 + 448) = v0;
				dword_5d4594_1556844 = v0;
			}
			sub_517640(v0);
			if (*(_DWORD*)(v0 + 696))
				sub_5117F0(v0);
			v4 = *(void(__cdecl**)(int, _DWORD))(v0 + 688);
			if (v4)
				v4(v0, 0);
			v5 = *(_DWORD*)(v0 + 8);
			if (v5 & 0x400000) {
				if (*(_DWORD*)(v0 + 12) & 0x18)
					v6 = 0;
				else
					v6 = (unsigned __int8)~*(_BYTE*)(v0 + 12) >> 7;
			} else {
				v6 = (v5 >> 29) & 1;
			}
			if (0x800000 & v5 || !v6) {
				sub_4E44F0(v0);
				if (!(*(_DWORD*)(v0 + 8) & 0x20400000))
					*(_DWORD*)(v0 + 148) = 0;
			} else {
				sub_4E44E0(v0);
				sub_527E00(v0);
				*(_DWORD*)(v0 + 148) = -1;
			}
			*(_DWORD*)(v0 + 16) &= 0xFDFFFFFF;
			v0 = i;
		} while (i);
		dword_5d4594_1556860 = 0;
	} else {
		dword_5d4594_1556860 = 0;
	}
}

//----- (004DADE0) --------------------------------------------------------
char __cdecl sub_4DADE0(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)(a1 + 16);
	if (v1 & 4) {
		LOBYTE(v1) = v1 & 0xFB;
		*(_DWORD*)(a1 + 16) = v1;
		sub_4E60A0(a1);
		if (!nox_common_gameFlags_check_40A5C0(0x80000))
			sub_5289D0(a1);
		sub_511810(a1);
		sub_4EC300(a1);
		sub_4EC470(a1);
		sub_517870(a1);
		sub_4DAE50(a1);
		sub_4ECFA0(a1);
		sub_511DE0(a1);
		LOBYTE(v1) = *(_BYTE*)(a1 + 8);
		if (v1 & 6)
			LOBYTE(v1) = sub_528990(a1);
	}
	return v1;
}

//----- (004DAE50) --------------------------------------------------------
int __cdecl sub_4DAE50(int a1) {
	int v1;     // eax
	int result; // eax
	int v3;     // esi
	int v4;     // eax
	int v5;     // esi

	sub_4DA9F0((_DWORD*)a1);
	if (*(_BYTE*)(a1 + 8) & 1) {
		v1 = *(_DWORD*)(a1 + 448);
		if (v1) {
			*(_DWORD*)(v1 + 444) = *(_DWORD*)(a1 + 444);
			result = *(_DWORD*)(a1 + 444);
			if (result)
				*(_DWORD*)(result + 448) = *(_DWORD*)(a1 + 448);
		} else {
			result = *(_DWORD*)(a1 + 444);
			dword_5d4594_1556848 = *(_DWORD*)(a1 + 444);
			v3 = *(_DWORD*)(a1 + 444);
			if (v3)
				*(_DWORD*)(v3 + 448) = 0;
		}
	} else {
		sub_4DA920((_DWORD*)a1);
		v4 = *(_DWORD*)(a1 + 448);
		if (v4) {
			*(_DWORD*)(v4 + 444) = *(_DWORD*)(a1 + 444);
			result = *(_DWORD*)(a1 + 444);
			if (result)
				*(_DWORD*)(result + 448) = *(_DWORD*)(a1 + 448);
		} else {
			result = *(_DWORD*)(a1 + 444);
			dword_5d4594_1556844 = *(_DWORD*)(a1 + 444);
			v5 = *(_DWORD*)(a1 + 444);
			if (v5)
				*(_DWORD*)(v5 + 448) = 0;
		}
	}
	return result;
}

//----- (004DAF10) --------------------------------------------------------
void sub_4DAF10() {
	_DWORD* v0; // edi
	_DWORD* v1; // esi
	int v2;     // eax
	int v3;     // ecx
	_DWORD* v4; // eax
	int v5;     // edx
	int v6;     // edx
	int v7;     // ecx
	int v8;     // edx
	_DWORD* v9; // eax

	v0 = *(_DWORD**)&dword_5d4594_1556860;
	v1 = *(_DWORD**)&dword_5d4594_1556860;
	if (dword_5d4594_1556860) {
		do {
			v2 = v1[2];
			if (v2 & 0x4000) {
				v3 = v1[187];
				v4 = v0;
				if (v0) {
					while (1) {
						v5 = v4[2];
						if ((v5 & 0x8000) != 0) {
							v6 = v4[187];
							if (*(_DWORD*)(v3 + 8) == v4[10])
								break;
						}
						v4 = (_DWORD*)v4[111];
						if (!v4)
							goto LABEL_9;
					}
					*(_DWORD*)(v3 + 4) = v4;
					*(_DWORD*)(v6 + 4) = v1;
					v0 = *(_DWORD**)&dword_5d4594_1556860;
				}
			}
		LABEL_9:
			if (v1[2] & 0x400) {
				v7 = v1[187];
				v8 = *(_DWORD*)(v7 + 16);
				*(_DWORD*)(v7 + 12) = 0;
				v0 = *(_DWORD**)&dword_5d4594_1556860;
				if (v8) {
					v9 = *(_DWORD**)&dword_5d4594_1556860;
					if (dword_5d4594_1556860) {
						while (!(v9[2] & 0x400) || v8 != v9[10]) {
							v9 = (_DWORD*)v9[111];
							if (!v9)
								goto LABEL_17;
						}
						*(_DWORD*)(v7 + 12) = v9;
						v0 = *(_DWORD**)&dword_5d4594_1556860;
					}
				}
			}
		LABEL_17:
			v1 = (_DWORD*)v1[111];
		} while (v1);
	}
}

//----- (004DAFD0) --------------------------------------------------------
_DWORD* __cdecl sub_4DAFD0(_DWORD* a1) {
	_DWORD* result; // eax
	int v2;         // ecx
	int v3;         // ecx
	int v4;         // ecx

	result = a1;
	v2 = a1[4];
	if (v2 & 4) {
		a1[4] = v2 & 0xFFFFFFFB;
		v3 = a1[112];
		if (v3) {
			*(_DWORD*)(v3 + 444) = a1[111];
			v4 = a1[111];
			if (v4) {
				result = (_DWORD*)a1[112];
				*(_DWORD*)(v4 + 448) = result;
			}
		} else {
			dword_5d4594_1556844 = a1[111];
			result = (_DWORD*)a1[111];
			if (result)
				result[112] = 0;
		}
	}
	return result;
}

//----- (004DB030) --------------------------------------------------------
_DWORD* sub_4DB030() {
	_DWORD* result; // eax
	_DWORD* v1;     // ecx
	int v2;         // edx

	result = *(_DWORD**)&dword_5d4594_1556860;
	if (dword_5d4594_1556860) {
		do {
			v1 = (_DWORD*)result[111];
			result[4] &= 0xFDFFFFFF;
			v2 = dword_5d4594_1556844;
			if (dword_5d4594_1556844) {
				*(_DWORD*)(dword_5d4594_1556844 + 448) = result;
				v2 = dword_5d4594_1556844;
			}
			result[111] = v2;
			result[112] = 0;
			dword_5d4594_1556844 = result;
			result = v1;
		} while (v1);
	}
	dword_5d4594_1556860 = 0;
	return result;
}

//----- (004DB090) --------------------------------------------------------
int sub_4DB090() { return *(_DWORD*)&byte_587000[201376]; }

//----- (004DB0A0) --------------------------------------------------------
int sub_4DB0A0() {
	byte_5D4594[1560984] = byte_5D4594[1563136];
	dword_5d4594_1563080 = 0;
	dword_5d4594_1563084 = 0;
	dword_5d4594_1563096 = 0;
	*(_DWORD*)&byte_5D4594[1563064] = 0;
	dword_5d4594_1563092 = 0;
	dword_5d4594_1563088 = 0;
	dword_5d4594_1563044 = 0;
	*(_DWORD*)&byte_5D4594[1563048] = 0;
	dword_5d4594_1563052 = 0;
	*(_DWORD*)&byte_5D4594[1563100] = 0;
	byte_5D4594[1563104] = byte_5D4594[1563140];
	return 1;
}

//----- (004DB100) --------------------------------------------------------
int sub_4DB100() {
	int result; // eax

	result = 0;
	dword_5d4594_1563080 = 0;
	dword_5d4594_1563084 = 0;
	dword_5d4594_1563096 = 0;
	*(_DWORD*)&byte_5D4594[1563064] = 0;
	dword_5d4594_1563092 = 0;
	dword_5d4594_1563088 = 0;
	*(_DWORD*)&byte_5D4594[1563072] = 0;
	*(_DWORD*)&byte_5D4594[1563068] = 0;
	return result;
}

//----- (004DB130) --------------------------------------------------------
unsigned int __cdecl sub_4DB130(const char* a1) {
	unsigned int result; // eax

	result = strlen(a1) + 1;
	qmemcpy(&byte_5D4594[1557900], a1, result);
	return result;
}

//----- (004DB170) --------------------------------------------------------
int __cdecl sub_4DB170(int a1, int a2, int a3) {
	int result; // eax

	dword_5d4594_1563092 = a3;
	dword_5d4594_1563088 = *(_DWORD*)&byte_5D4594[2598000];
	result = a1;
	dword_5d4594_1563084 = a2;
	dword_5d4594_1563080 = a1;
	dword_5d4594_1563096 = a2 != 0;
	if (!a1)
		result = sub_4DCBD0(0);
	return result;
}

//----- (004DB1B0) --------------------------------------------------------
int sub_4DB1B0() { return dword_5d4594_1563080; }

//----- (004DB1C0) --------------------------------------------------------
int sub_4DB1C0() { return dword_5d4594_1563084; }

//----- (004DB220) --------------------------------------------------------
int __cdecl sub_4DB220(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1563056] = a1;
	return result;
}

//----- (004DB230) --------------------------------------------------------
int __cdecl sub_4DB230(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1563060] = a1;
	return result;
}

//----- (004DB240) --------------------------------------------------------
int sub_4DB240() { return *(_DWORD*)&byte_5D4594[1563056]; }

//----- (004DB250) --------------------------------------------------------
int sub_4DB250() { return *(_DWORD*)&byte_5D4594[1563060]; }

//----- (004DB260) --------------------------------------------------------
char* sub_4DB260() { return (char*)&byte_5D4594[1559960]; }

//----- (004DB270) --------------------------------------------------------
unsigned int __cdecl sub_4DB270(const char* a1) {
	unsigned int result; // eax

	result = strlen(a1) + 1;
	qmemcpy(&byte_5D4594[1559960], a1, result);
	return result;
}

//----- (004DB2A0) --------------------------------------------------------
unsigned int __cdecl sub_4DB2A0(const char* a1) {
	char* v1;      // eax
	char* v2;      // eax
	char v4[24];   // [esp+4h] [ebp-418h]
	char v5[1024]; // [esp+1Ch] [ebp-400h]

	strcpy(v5, a1);
	v1 = strrchr(v5, 58);
	if (v1)
		*v1 = 0;
	strcpy(&v4[4], v5);
	v4[strlen(v5)] = 0;
	v2 = sub_409E10();
	nox_sprintf((char*)&byte_5D4594[1558936], "%s\\Save\\%s\\%s\\%s", v2, &byte_587000[199148], &v4[4], v5);
	return _access((LPCSTR)&byte_5D4594[1558936], 0) != -1 ? (unsigned int)&byte_5D4594[1558936] : 0;
}

//----- (004DB540) --------------------------------------------------------
BOOL __cdecl sub_4DB540(int a1) {
	char* v1;            // eax
	char PathName[1024]; // [esp+0h] [ebp-400h]

	v1 = sub_409E10();
	nox_sprintf(PathName, "%s\\Save\\%s", v1, a1);
	return _mkdir(PathName) != -1 || errno != 2;
}

//----- (004DB790) --------------------------------------------------------
char* __cdecl sub_4DB790(const char* a1) {
	char* v1;     // esi
	char* result; // eax

	sub_4DCC70(1);
	sub_40A4D0(0x8000000);
	sub_43F140(500);
	v1 = sub_4DB7E0_savegame(a1);
	sub_43F1A0();
	nox_common_gameFlags_unset_40A540(0x8000000);
	result = v1;
	*(_DWORD*)&byte_5D4594[1563068] = *(_DWORD*)&byte_5D4594[2598000];
	return result;
}

//----- (004DBE10) --------------------------------------------------------
int __cdecl sub_4DBE10(int a1, int a2) {
	int result;                            // eax
	char* v3;                              // eax
	int v4;                                // ebx
	HANDLE v5;                             // ebp
	char* v6;                              // ebp
	char* v7;                              // edx
	char* v8;                              // esi
	int v9;                                // ebp
	HANDLE v10;                            // ebx
	char* v11;                             // ebx
	char* v12;                             // edx
	char* v13;                             // esi
	bool v14;                              // zf
	char* v15;                             // eax
	HANDLE hFindFile;                      // [esp+0h] [ebp-2494Ch]
	HANDLE hFindFilea;                     // [esp+0h] [ebp-2494Ch]
	char* v18;                             // [esp+4h] [ebp-24948h]
	int v19;                               // [esp+8h] [ebp-24944h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+Ch] [ebp-24940h]
	CHAR PathName[1024];                   // [esp+14Ch] [ebp-24800h]
	CHAR FileName[1024];                   // [esp+54Ch] [ebp-24400h]
	char v23[16384];                       // [esp+94Ch] [ebp-24000h]
	char v24[131072];                      // [esp+494Ch] [ebp-20000h]

	result = a1;
	if (a1) {
		v3 = sub_409E10();
		nox_sprintf(&PathName, "%s\\Save\\%s", v3, a1);
		result = _access(&PathName, 0);
		if (result != -1) {
			nox_sprintf(&FileName, "%s\\Player.plr", &PathName);
			DeleteFileA(&FileName);
			SetCurrentDirectoryA(&PathName);
			v4 = 0;
			v5 = FindFirstFileA((LPCSTR)&byte_587000[199680], &FindFileData);
			hFindFile = v5;
			if (v5 != (HANDLE)-1) {
				if (FindFileData.dwFileAttributes & 0x10 && strcmp(FindFileData.cFileName, ".") &&
				    strcmp(FindFileData.cFileName, "..")) {
					v4 = 1;
					strcpy(v24, FindFileData.cFileName);
				}
				if (FindNextFileA(v5, &FindFileData)) {
					v6 = &v24[1024 * v4];
					do {
						if (FindFileData.dwFileAttributes & 0x10 &&
						    strcmp(FindFileData.cFileName, ".") &&
						    strcmp(FindFileData.cFileName, "..")) {
							v7 = v6;
							++v4;
							v6 += 1024;
							strcpy(v7, FindFileData.cFileName);
						}
					} while (FindNextFileA(hFindFile, &FindFileData));
					v5 = hFindFile;
				}
				FindClose(v5);
			}
			if (v4 > 0) {
				v8 = v24;
				v19 = v4;
				v18 = v24;
				do {
					SetCurrentDirectoryA(v8);
					v9 = 0;
					v10 = FindFirstFileA((LPCSTR)&byte_587000[199700], &FindFileData);
					hFindFilea = v10;
					if (v10 != (HANDLE)-1) {
						if (!(FindFileData.dwFileAttributes & 0x10)) {
							v9 = 1;
							strcpy(v23, FindFileData.cFileName);
						}
						if (FindNextFileA(v10, &FindFileData)) {
							v11 = &v23[1024 * v9];
							do {
								if (!(FindFileData.dwFileAttributes & 0x10)) {
									v12 = v11;
									++v9;
									v11 += 1024;
									strcpy(v12, FindFileData.cFileName);
								}
							} while (FindNextFileA(hFindFilea, &FindFileData));
							v10 = hFindFilea;
						}
						FindClose(v10);
						if (v9 > 0) {
							v13 = v23;
							do {
								DeleteFileA(v13);
								v13 += 1024;
								--v9;
							} while (v9);
						}
						v8 = v18;
					}
					SetCurrentDirectoryA((LPCSTR)&byte_587000[199704]);
					RemoveDirectoryA(v8);
					v8 += 1024;
					v14 = v19 == 1;
					v18 = v8;
					--v19;
				} while (!v14);
			}
			v15 = sub_409E10();
			SetCurrentDirectoryA(v15);
			result = a2;
			if (a2)
				result = RemoveDirectoryA(&PathName);
		}
	}
	return result;
}
// 4DBE10: using guessed type CHAR var_20000[131072];
// 4DBE10: using guessed type CHAR var_24000[16384];

//----- (004DC100) --------------------------------------------------------
int __cdecl sub_4DC100(int a1, int a2) {
	char* v2;                              // eax
	char* v3;                              // eax
	int result;                            // eax
	int v5;                                // ebp
	HANDLE v6;                             // ebx
	char* v7;                              // ebx
	char* v8;                              // edx
	int v9;                                // esi
	char* v10;                             // edi
	char* v11;                             // edi
	int v12;                               // ebp
	HANDLE v13;                            // ebx
	char* v14;                             // ebx
	char* v15;                             // edx
	char* v16;                             // esi
	bool v17;                              // cc
	char* v18;                             // eax
	HANDLE hFindFile;                      // [esp+10h] [ebp-25154h]
	HANDLE hFindFilea;                     // [esp+10h] [ebp-25154h]
	int v21;                               // [esp+14h] [ebp-25150h]
	char* v22;                             // [esp+18h] [ebp-2514Ch]
	int v23;                               // [esp+1Ch] [ebp-25148h]
	int v24;                               // [esp+20h] [ebp-25144h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+24h] [ebp-25140h]
	CHAR PathName[1024];                   // [esp+164h] [ebp-25000h]
	CHAR NewFileName[1024];                // [esp+564h] [ebp-24C00h]
	CHAR ExistingFileName[1024];           // [esp+964h] [ebp-24800h]
	CHAR v29[1024];                        // [esp+D64h] [ebp-24400h]
	char v30[16384];                       // [esp+1164h] [ebp-24000h]
	char v31[131072];                      // [esp+5164h] [ebp-20000h]

	v24 = 1;
	v2 = sub_409E10();
	nox_sprintf(&PathName, "%s\\Save\\%s", v2, a1);
	v3 = sub_409E10();
	nox_sprintf(&v29, "%s\\Save\\%s", v3, a2);
	if (!sub_4DB540(a2))
		return 0;
	sub_4DBE10(a2, 0);
	nox_sprintf(&ExistingFileName, "%s\\Player.plr", &PathName);
	nox_sprintf(&NewFileName, "%s\\Player.plr", &v29);
	result = CopyFileA(&ExistingFileName, &NewFileName, 0);
	if (result) {
		result = SetCurrentDirectoryA(&PathName);
		if (result) {
			v5 = 0;
			v21 = 0;
			v6 = FindFirstFileA((LPCSTR)&byte_587000[199764], &FindFileData);
			hFindFile = v6;
			if (v6 == (HANDLE)-1)
				goto LABEL_48;
			if (FindFileData.dwFileAttributes & 0x10 && strcmp(FindFileData.cFileName, ".") &&
			    strcmp(FindFileData.cFileName, "..")) {
				v21 = 1;
				strcpy(v31, FindFileData.cFileName);
				v5 = 1;
			}
			if (FindNextFileA(v6, &FindFileData)) {
				v7 = &v31[1024 * v5];
				do {
					if (FindFileData.dwFileAttributes & 0x10 &&
					    strcmp(FindFileData.cFileName, ".") &&
					    strcmp(FindFileData.cFileName, "..")) {
						v8 = v7;
						++v5;
						v7 += 1024;
						strcpy(v8, FindFileData.cFileName);
					}
				} while (FindNextFileA(hFindFile, &FindFileData));
				v6 = hFindFile;
				v21 = v5;
			}
			result = FindClose(v6);
			if (result) {
			LABEL_48:
				result = SetCurrentDirectoryA(&v29);
				if (result) {
					v9 = 0;
					if (v5 > 0) {
						v10 = v31;
						while (CreateDirectoryA(v10, 0)) {
							++v9;
							v10 += 1024;
							if (v9 >= v5)
								goto LABEL_24;
						}
						return 0;
					}
				LABEL_24:
					result = SetCurrentDirectoryA(&PathName);
					if (result) {
						v23 = 0;
						if (v5 > 0) {
							v11 = v31;
							v22 = v31;
							while (SetCurrentDirectoryA(v11)) {
								v12 = 0;
								v13 = FindFirstFileA((LPCSTR)&byte_587000[199784],
										     &FindFileData);
								hFindFilea = v13;
								if (v13 != (HANDLE)-1) {
									if (!(FindFileData.dwFileAttributes & 0x10)) {
										v12 = 1;
										strcpy(v30, FindFileData.cFileName);
										v11 = v22;
									}
									if (FindNextFileA(v13, &FindFileData)) {
										v14 = &v30[1024 * v12];
										do {
											if (!(FindFileData
												  .dwFileAttributes &
											      0x10)) {
												v15 = v14;
												++v12;
												v14 += 1024;
												strcpy(v15,
												       FindFileData
													   .cFileName);
											}
										} while (FindNextFileA(hFindFilea,
												       &FindFileData));
										v13 = hFindFilea;
										v11 = v22;
									}
									if (!FindClose(v13))
										return 0;
									if (v12 > 0) {
										v16 = v30;
										do {
											nox_sprintf(&ExistingFileName,
												    "%s\\%s\\%s",
												    &PathName, v11,
												    v16);
											nox_sprintf(&NewFileName,
												    "%s\\%s\\%s", &v29,
												    v11, v16);
											if (!CopyFileA(
												&ExistingFileName,
												&NewFileName, 0))
												v24 = 0;
											v16 += 1024;
											--v12;
										} while (v12);
									}
								}
								if (!SetCurrentDirectoryA((LPCSTR)&byte_587000[199812]))
									return 0;
								v11 += 1024;
								v17 = ++v23 < v21;
								v22 = v11;
								if (!v17)
									goto LABEL_45;
							}
							return 0;
						}
					LABEL_45:
						v18 = sub_409E10();
						result = SetCurrentDirectoryA(v18) ? v24 : 0;
					}
				}
			}
		}
	}
#ifdef __EMSCRIPTEN__
	EM_ASM(FS.syncfs(false, function(err){}));
#endif
	return result;
}
// 4DC100: using guessed type CHAR var_20000[131072];
// 4DC100: using guessed type char var_24000[16384];

//----- (004DC550) --------------------------------------------------------
int sub_4DC550() {
	int v0;              // ebx
	char* v1;            // edi
	char* v5;            // eax
	int v6;              // esi
	char* v7;            // eax
	char PathName[1024]; // [esp+Ch] [ebp-400h]

	v0 = 0;
	v1 = sub_409E10();
	strcpy(PathName, v1);
	strcat(PathName, "\\Save\\");
	CreateDirectoryA(PathName, 0);
	v5 = sub_409E10();
	nox_sprintf(PathName, "%s\\Save\\AUTOSAVE\\Player.plr", v5);
	if (_access(PathName, 0) != -1)
		v0 = 1;
	v6 = 13;
	do {
		v7 = sub_409E10();
		nox_sprintf(PathName, "%s\\Save\\SAVE%04d\\Player.plr", v7, v0);
		if (_access(PathName, 0) != -1)
			++v0;
		--v6;
	} while (v6);
	return v0;
}
// 4DC550: using guessed type CHAR PathName[1024];

//----- (004DC630) --------------------------------------------------------
int sub_4DC630() {
	int v0;                                // ebp
	char* v1;                              // edi
	HANDLE v5;                             // esi
	char* v6;                              // eax
	struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-E40h]
	char PathName[1024];                   // [esp+150h] [ebp-D00h]
	char v10[1280];                        // [esp+550h] [ebp-900h]
	char v11[1024];                        // [esp+A50h] [ebp-400h]

	v0 = 0;
	v1 = sub_409E10();
	strcpy(PathName, v1);
	strcat(PathName, "\\Save\\");
	strcpy(v11, PathName);
	CreateDirectoryA(PathName, 0);
	SetCurrentDirectoryA(PathName);
	v5 = FindFirstFileA("*.plr", &FindFileData);
	if (v5 != (HANDLE)-1) {
		if (!(FindFileData.dwFileAttributes & 0x10)) {
			nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
			sub_41A000(PathName, v10);
			if (v10[0] & 2)
				v0 = 1;
		}
		while (FindNextFileA(v5, &FindFileData)) {
			if (!(FindFileData.dwFileAttributes & 0x10)) {
				nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
				sub_41A000(PathName, v10);
				if (v10[0] & 2)
					++v0;
			}
		}
		FindClose(v5);
	}
	v6 = sub_409E10();
	SetCurrentDirectoryA(v6);
	return v0;
}
// 4DC630: using guessed type CHAR PathName[1024];

//----- (004DC7D0) --------------------------------------------------------
int sub_4DC7D0() {
	int v0;                                // ebp
	char* v1;                              // edi
	HANDLE v5;                             // esi
	char* v6;                              // eax
	struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-E40h]
	char PathName[1024];                   // [esp+150h] [ebp-D00h]
	char v10[1280];                        // [esp+550h] [ebp-900h]
	char v11[1024];                        // [esp+A50h] [ebp-400h]

	v0 = 0;
	v1 = sub_409E10();
	strcpy(PathName, v1);
	strcat(PathName, "\\Save\\");
	strcpy(v11, PathName);
	CreateDirectoryA(PathName, 0);
	SetCurrentDirectoryA(PathName);
	v5 = FindFirstFileA((LPCSTR)&byte_587000[199920], &FindFileData);
	if (v5 != (HANDLE)-1) {
		if (!(FindFileData.dwFileAttributes & 0x10)) {
			nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
			sub_41A000(PathName, v10);
			if (v10[0] & 4)
				v0 = 1;
		}
		while (FindNextFileA(v5, &FindFileData)) {
			if (!(FindFileData.dwFileAttributes & 0x10)) {
				nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
				sub_41A000(PathName, v10);
				if (v10[0] & 4)
					++v0;
			}
		}
		FindClose(v5);
	}
	v6 = sub_409E10();
	SetCurrentDirectoryA(v6);
	return v0;
}
// 4DC7D0: using guessed type CHAR PathName[1024];

//----- (004DC970) --------------------------------------------------------
char* __cdecl sub_4DC970(char* a1, char* a2) {
	char* result; // eax

	result = a1;
	if (a1 && a2) {
		result = strrchr(a1, 92);
		if (result) {
			result = strncpy(a2, result - 8, 8u);
			a2[8] = 0;
		}
	}
	return result;
}

//----- (004DC9B0) --------------------------------------------------------
char* __cdecl sub_4DC9B0(char* a1) {
	char* result; // eax
	char v2[12];  // [esp+0h] [ebp-Ch]

	if (!a1)
		return (char*)-1;
	result = strrchr(a1, 92);
	if (result) {
		strncpy(v2, result - 4, 4u);
		v2[4] = 0;
		result = (char*)atoi(v2);
	}
	return result;
}

//----- (004DCA00) --------------------------------------------------------
char* sub_4DCA00() {
	unsigned int v0;                       // ebp
	char* v1;                              // eax
	HANDLE v2;                             // ebx
	char* v3;                              // eax
	char* v4;                              // eax
	struct _WIN32_FIND_DATAA FindFileData; // [esp+8h] [ebp-D40h]
	CHAR FileName[1024];                   // [esp+148h] [ebp-C00h]
	CHAR PathName[1024];                   // [esp+548h] [ebp-800h]
	CHAR Buffer[1024];                     // [esp+948h] [ebp-400h]

	v0 = 2;
	GetCurrentDirectoryA(0x400u, Buffer);
	v1 = sub_409E10();
	nox_sprintf(PathName, "%s\\Save\\", v1);
	SetCurrentDirectoryA(PathName);
	v2 = FindFirstFileA("*", &FindFileData);
	if (v2 != (HANDLE)-1) {
		if (FindFileData.dwFileAttributes & 0x10) {
			if (strcmp(FindFileData.cFileName, "..")) {
				if (strcmp(FindFileData.cFileName, ".")) {
					nox_sprintf(FileName, "%s%s\\Player.plr", PathName, FindFileData.cFileName);
					if (_access(FileName, 0) != -1) {
						v3 = sub_4DC9B0(FileName);
						if ((unsigned int)v3 >= 2)
							v0 = (unsigned int)(v3 + 1);
					}
				}
			}
		}
		while (FindNextFileA(v2, &FindFileData)) {
			if (FindFileData.dwFileAttributes & 0x10) {
				if (strcmp(FindFileData.cFileName, "..")) {
					if (strcmp(FindFileData.cFileName, ".")) {
						nox_sprintf(FileName, "%s%s\\Player.plr", PathName,
							    FindFileData.cFileName);
						if (_access(FileName, 0) != -1) {
							v4 = sub_4DC9B0(FileName);
							if ((unsigned int)v4 >= v0)
								v0 = (unsigned int)(v4 + 1);
						}
					}
				}
			}
		}
		FindClose(v2);
	}
	SetCurrentDirectoryA(Buffer);
	if (v0 > 0x270F)
		return 0;
	nox_sprintf((char*)&byte_5D4594[1563032], "SAVE%04d", v0);
	return (char*)&byte_5D4594[1563032];
}

//----- (004DCBD0) --------------------------------------------------------
int __cdecl sub_4DCBD0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1563076] = a1;
	return result;
}

//----- (004DCBE0) --------------------------------------------------------
int sub_4DCBE0() { return *(_DWORD*)&byte_5D4594[1563076]; }

//----- (004DCBF0) --------------------------------------------------------
int __cdecl sub_4DCBF0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1563064] = a1;
	return result;
}

//----- (004DCC10) --------------------------------------------------------
int __cdecl sub_4DCC10(int a1) {
	int v1;     // esi
	int v2;     // eax
	int result; // eax

	v1 = 1;
	if (dword_5d4594_1563092 &&
	    (unsigned int)(dword_5d4594_1563092 + dword_5d4594_1563088) >
		*(int*)&byte_5D4594[2598000]) {
		v1 = 0;
	}
	if (*(_DWORD*)(*(_DWORD*)(a1 + 748) + 284))
		v1 = 0;
	v2 = *(_DWORD*)(a1 + 16);
	if (v2 & 2)
		v1 = 0;
	if ((v2 & 0x8000) != 0)
		v1 = 0;
	if (sub_45D9B0() == 1)
		result = 0;
	else
		result = v1;
	return result;
}

//----- (004DCC70) --------------------------------------------------------
int __cdecl sub_4DCC70(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1563072] = a1;
	return result;
}

//----- (004DCC90) --------------------------------------------------------
BOOL sub_4DCC90() {
	BOOL result; // eax

	result = 1;
	if (dword_5d4594_1563080 != 1)
		result = dword_5d4594_1563092 != 0;
	return result;
}

//----- (004DCCB0) --------------------------------------------------------
BOOL sub_4DCCB0() {
	BOOL result; // eax
	char* v1;    // eax
	int v2;      // esi
	int v3;      // eax

	if (!nox_common_gameFlags_check_40A5C0(2048))
		return 1;
	v1 = sub_417090(31);
	if (!v1 || (v2 = *((_DWORD*)v1 + 514)) == 0 || sub_4DCC90() || sub_4139B0() ||
	    (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)&byte_5D4594[1563068]) < 0x1E || sub_477600() ||
	    (v3 = *(_DWORD*)(v2 + 16), BYTE1(v3) & 0x40)) {
		result = 0;
	} else {
		result = sub_4DCC10(v2) != 0;
	}
	return result;
}

//----- (004DCD40) --------------------------------------------------------
int sub_4DCD40() {
	char* v0;            // eax
	int result;          // eax
	int i;               // esi
	int v3;              // eax
	int v4;              // edi
	CHAR FileName[1024]; // [esp+4h] [ebp-400h]

	*(_DWORD*)&byte_5D4594[1563048] = sub_416A00();
	sub_4169E0();
	dword_5d4594_1563044 = 1;
	v0 = sub_409E10();
	nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v0);
	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		v3 = *(_DWORD*)(i + 748);
		v4 = *(_DWORD*)(v3 + 276);
		if (*(_DWORD*)(v4 + 4792) && *(_DWORD*)(v3 + 552) != 1) {
			if (sub_41A140(FileName, *(unsigned __int8*)(v4 + 2064)))
				sub_41CFA0(FileName, *(unsigned __int8*)(v4 + 2064));
			DeleteFileA(FileName);
		}
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004DCE00) --------------------------------------------------------
int sub_4DCE00() {
	int result; // eax

	result = dword_5d4594_1563044;
	if (dword_5d4594_1563044) {
		result = sub_419F00();
		if (!result) {
			result = sub_4DCE30();
			dword_5d4594_1563044 = 0;
		}
	}
	return result;
}

//----- (004DCE30) --------------------------------------------------------
int sub_4DCE30() {
	if (!*(_DWORD*)&byte_5D4594[1563048])
		sub_4169F0();
	return sub_446140();
}

//----- (004DCE60) --------------------------------------------------------
int __cdecl sub_4DCE60(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1563100] = a1;
	return result;
}

//----- (004DCE70) --------------------------------------------------------
int sub_4DCE70() { return *(_DWORD*)&byte_5D4594[1563100]; }

//----- (004DCE80) --------------------------------------------------------
int __cdecl sub_4DCE80(const char* a1) {
	int result; // eax

	result = 0;
	if (a1) {
		strcpy((char*)&byte_5D4594[1563104], a1);
	} else {
		*(_DWORD*)&byte_5D4594[1563104] = 0;
		*(_DWORD*)&byte_5D4594[1563108] = 0;
		*(_DWORD*)&byte_5D4594[1563112] = 0;
		*(_DWORD*)&byte_5D4594[1563116] = 0;
		*(_DWORD*)&byte_5D4594[1563120] = 0;
	}
	return result;
}

//----- (004DCED0) --------------------------------------------------------
unsigned __int8* sub_4DCED0() { return &byte_5D4594[1563104]; }

//----- (004DCEE0) --------------------------------------------------------
void __cdecl sub_4DCEE0(const char* a1) {
	if (a1) {
		strcpy((char*)&byte_5D4594[1560984], a1);
		dword_5d4594_1563052 = 1;
	} else {
		dword_5d4594_1563052 = 0;
	}
}

//----- (004DCF80) --------------------------------------------------------
int __cdecl sub_4DCF80(int a1, char a2) {
	int v2;     // ecx
	char v4[3]; // [esp+0h] [ebp-4h]
	char v5;    // [esp+3h] [ebp-1h]

	v5 = HIBYTE(v2);
	v4[0] = -16;
	v4[1] = 28;
	v4[2] = a2;
	return sub_4E5390(a1, (int)v4, 3, 0, 0);
}

//----- (004DCFB0) --------------------------------------------------------
char __cdecl sub_4DCFB0(int a1) {
	char result;         // al
	int v2;              // edi
	int v3;              // esi
	int v4;              // ecx
	char* v5;            // eax
	CHAR FileName[1024]; // [esp+8h] [ebp-400h]

	result = a1;
	v2 = 1;
	if (a1) {
		v3 = *(_DWORD*)(a1 + 748);
		v4 = *(_DWORD*)(v3 + 276);
		result = *(_BYTE*)(v4 + 2064);
		if (result != 31) {
			if (*(_DWORD*)(v4 + 4792) && *(_DWORD*)(v3 + 552) != 1) {
				if (sub_419EE0(*(_BYTE*)(v4 + 2064)))
					goto LABEL_13;
				v5 = sub_409E10();
				nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v5);
				if (sub_41A140(FileName, *(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064)))
					v2 = sub_41CFA0(FileName, *(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064));
				result = DeleteFileA(FileName);
				if (v2)
				LABEL_13:
					result = sub_4D7960(*(_BYTE*)(*(_DWORD*)(v3 + 276) + 2064));
			} else {
				result = (unsigned int)sub_4DEAB0(*(unsigned __int8*)(v4 + 2064), 4);
			}
		}
	}
	return result;
}

//----- (004DD0B0) --------------------------------------------------------
char* __cdecl sub_4DD0B0(int a1) {
	char* result; // eax
	int v2;       // esi

	result = (char*)a1;
	if (a1) {
		v2 = *(_DWORD*)(a1 + 748);
		if (sub_4D7980(*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2064))) {
			result = sub_4DEAB0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), 4);
		} else {
			sub_419EB0(*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2064), 0);
			result = (char*)sub_4DCF80(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), 0);
		}
	}
	return result;
}

//----- (004DD130) --------------------------------------------------------
void sub_4DD130() { nox_srand(0x49C3B96u); }

//----- (004DD140) --------------------------------------------------------
LPVOID __cdecl sub_4DD140(int a1) {
	LPVOID result; // eax
	int v3;        // [esp+0h] [ebp-4h]

	result = sub_4464D0(1, &v3);
	if (result)
		result = (LPVOID)sub_40BC60(a1, 1, "MOTD", (int)result, v3, 1);
	return result;
}

//----- (004DD180) --------------------------------------------------------
char* __cdecl sub_4DD180(int a1) {
	char* result; // eax
	char* v2;     // edi
	int v3;       // eax
	int i;        // esi
	int v5;       // eax

	result = sub_417090(a1);
	v2 = result;
	if (result) {
		sub_4174F0((int)result, 16);
		if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(128)) {
			v3 = *((_DWORD*)v2 + 514);
			if (v3) {
				sub_4FF5B0(v3, 23);
				sub_4FF380(*((_DWORD*)v2 + 514), 23, 5 * *(_WORD*)&byte_5D4594[2649704], 5);
			}
			for (i = sub_4DA790(); i; i = sub_4DA7A0(i)) {
				if (*(_DWORD*)(i + 8) & 0x10000000)
					sub_417190(a1, i, 1);
			}
		}
		if ((v2[3680] & 1) == 1) {
			v5 = *((_DWORD*)v2 + 514);
			*((_DWORD*)v2 + 908) = *(_DWORD*)(v5 + 56);
			*((_DWORD*)v2 + 909) = *(_DWORD*)(v5 + 60);
			if (nox_common_gameFlags_check_40A5C0(512))
				sub_4E6AA0((int)v2);
		}
		sub_4DF1E0(a1);
		if (nox_common_gameFlags_check_40A5C0(4096) && sub_40A300() == 1)
			sub_4D9E70(a1);
		if (a1 == 31 && nox_common_gameFlags_check_40A5C0(128)) {
			if (!dword_5d4594_3596 && sub_43AF70() == 1) {
				sub_49C820();
				return (char*)sub_4D9C20(*((_DWORD*)v2 + 514));
			}
			if (dword_587000_54276 == 1) {
				sub_49C560();
				return (char*)sub_4D9C20(*((_DWORD*)v2 + 514));
			}
			sub_457500();
		}
		result = (char*)sub_4D9C20(*((_DWORD*)v2 + 514));
	}
	return result;
}

//----- (004DD310) --------------------------------------------------------
void sub_4DD310() { *(_DWORD*)&byte_5D4594[1563280] = 1; }

//----- (004DD320) --------------------------------------------------------
_DWORD* __cdecl sub_4DD320(int a1, int a2) {
	unsigned __int8 v2;  // si
	int v3;              // esi
	_DWORD* result;      // eax
	char* v5;            // esi
	unsigned __int8* v6; // eax
	char v7;             // al
	char* v8;            // ebp
	unsigned int v9;     // ecx
	int v10;             // eax
	int v11;             // eax
	void* v12;           // eax
	int v13;             // esi
	int v14;             // edx
	int v15;             // edi
	int v16;             // eax
	int v17;             // ecx
	int v18;             // eax
	int v19;             // edx
	size_t v20;          // eax
	int v21;             // eax
	int v22;             // eax
	int v23;             // ecx
	char* v24;           // eax
	int v25;             // [esp-1Ch] [ebp-F4h]
	int v26;             // [esp-8h] [ebp-E0h]
	int v27;             // [esp+Ch] [ebp-CCh]
	float2 v28;          // [esp+10h] [ebp-C8h]
	char v29[60];        // [esp+18h] [ebp-C0h]
	char v30[132];       // [esp+54h] [ebp-84h]

	v2 = *(_BYTE*)(a2 + 152);
	*(_BYTE*)(a2 + 152) = v2 & 0x7F;
	v3 = v2 >> 7;
	if (a1 != 31) {
		result = (_DWORD*)nox_common_gameFlags_check_40A5C0(4096);
		if (!result && v3 == 1)
			return result;
		if (nox_common_gameFlags_check_40A5C0(4096) && !v3)
			return 0;
	}
	v5 = sub_416640();
	sub_40ED10(a1, 1);
	sub_4E4F40(a1);
	sub_4E4F30(a1);
	if (*(_BYTE*)(a2 + 67)) {
		v6 = &byte_587000[200088];
	} else if (*(_DWORD*)&byte_5D4594[1563280]) {
		v6 = &byte_587000[200068];
	} else {
		v6 = &byte_587000[200076];
	}
	result = sub_4E3810((CHAR*)v6);
	v27 = (int)result;
	if (result) {
		if (a1 != 31) {
			v7 = v5[100];
			if (v7) {
				if ((unsigned __int8)(1 << *(_BYTE*)(a2 + 66)) & (unsigned __int8)v7)
					return 0;
			}
		}
		v8 = sub_417000(a1);
		v8[2064] = a1;
		if ((int)v5[102] >= 0) {
			*((_WORD*)v8 + 5) = *(_DWORD*)(a2 + 97) >> 1;
			v10 = *(_DWORD*)(a2 + 101) >> 1;
		} else {
			v9 = *(_DWORD*)(a2 + 97);
			if (nox_win_width >= (int)v9) {
				*((_WORD*)v8 + 5) = v9 >> 1;
				*((_WORD*)v8 + 6) = *(_DWORD*)(a2 + 101) >> 1;
			LABEL_23:
				strcpy(v8 + 2112, (const char*)(a2 + 105));
				v8[2135] = *(_BYTE*)(a2 + 152);
				nox_swprintf((wchar_t*)v8 + 1036, L"%S", a2 + 142);
				strcpy(v8 + 2096, (const char*)(a2 + 128));
				v11 = *(_DWORD*)(a2 + 138);
				*((_DWORD*)v8 + 517) = v11;
				if (v11) {
					v12 = sub_425A70(v11);
					if (!v12)
						v12 = sub_425AD0(*((_DWORD*)v8 + 517), (wchar_t*)v8 + 1036);
					sub_425B30((int)v12, a1);
				}
				*((_DWORD*)v8 + 899) = *(_DWORD*)&byte_5D4594[2598000];
				v8[3676] = 2;
				*((_DWORD*)v8 + 920) = 0;
				qmemcpy(v8 + 2185, (const void*)a2, 0x61u);
				nox_wcscpy((wchar_t*)v8 + 2352, (const wchar_t*)(v8 + 2185));
				*((_WORD*)v8 + 1137) = 0;
				sub_4DDA00((int)v8);
				sub_461460((int)v8);
				v13 = v27;
				*((_DWORD*)v8 + 514) = v27;
				v14 = *(_DWORD*)(v13 + 36);
				*((_DWORD*)v8 + 538) = 0;
				*((_DWORD*)v8 + 515) = v14;
				*((_DWORD*)v8 + 539) = sub_4D1600();
				v15 = *(_DWORD*)(v13 + 748);
				*(_DWORD*)(v15 + 276) = v8;
				*((_DWORD*)v8 + 1146) = sub_56F400(**(unsigned __int16**)(v13 + 556));
				*((_DWORD*)v8 + 1148) = sub_56F400(*(unsigned __int16*)(*(_DWORD*)(v13 + 556) + 4));
				*((_DWORD*)v8 + 1149) = sub_56F400(*(unsigned __int16*)(v15 + 4));
				*((_DWORD*)v8 + 1150) = sub_56F400(*(unsigned __int16*)(v15 + 8));
				*((_DWORD*)v8 + 1151) = sub_56F440(*(_DWORD*)(v13 + 28));
				*((_DWORD*)v8 + 1152) = sub_56F440(*(_DWORD*)(v13 + 120));
				*((_DWORD*)v8 + 1153) = sub_56F400(*(_DWORD*)(v13 + 340));
				v16 = sub_56F400((unsigned __int8)v8[2251]);
				v17 = *(_DWORD*)(v8 + 2235);
				*((_DWORD*)v8 + 1154) = v16;
				v18 = sub_56F400(v17);
				v19 = *(_DWORD*)(v8 + 2239);
				*((_DWORD*)v8 + 1155) = v18;
				*((_DWORD*)v8 + 1156) = sub_56F400(v19);
				v20 = nox_wcslen((const wchar_t*)(v8 + 2185));
				v21 = sub_56FAE0((int*)(v8 + 2185), 2 * v20);
				*((_DWORD*)v8 + 1157) = sub_56F400(v21);
				*((_DWORD*)v8 + 1158) = sub_56F400(0);
				*((_DWORD*)v8 + 1159) = sub_56F400(0);
				*((_DWORD*)v8 + 1147) = sub_56F400(*((_DWORD*)v8 + 541));
				v22 = sub_56F400(0);
				v25 = v8[3684];
				*((_DWORD*)v8 + 1160) = v22;
				*((_DWORD*)v8 + 1161) = sub_56F400(v25);
				*((_DWORD*)v8 + 1162) = -1;
				*((_DWORD*)v8 + 1175) = 1;
				if (dword_5d4594_2650652)
					sub_41D670((int)(v8 + 2096));
				sub_4D7F10(a1);
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					sub_4E6860((int)v8, 0, 1);
				} else if (nox_common_gameFlags_check_40A5C0(512)) {
					sub_417630((int)v8);
				} else if (v8[2064] == 31 && *(_DWORD*)&nox_common_engineFlags & 0x40000) {
					sub_4E6860((int)v8, 0, 1);
				} else if (nox_common_gameFlags_check_40A5C0(128)) {
					if (sub_40A740()) {
						if (!sub_40AA70((int)v8))
							sub_4E6860((int)v8, 0, 1);
					} else if (sub_417DA0(4)) {
						sub_4DF3C0((int)v8);
					}
				} else if (!nox_common_gameFlags_check_40A5C0(2048)) {
					sub_4E6860((int)v8, 1, 1);
				}
				sub_4DDB40((_DWORD*)v13);
				if (v8[2064] == 31)
					dword_5d4594_3843628 = v13;
				sub_4DDA90((int)v30, (int)v8);
				v23 = a1;
				LOBYTE(v23) = a1 | 0x80;
				sub_4E5420(v23, v30, 129, 0, 0);
				v8[3676] = 2;
				if (sub_43AF70() == 1 && !nox_common_gameFlags_check_40A5C0(128))
					sub_425F10((int)v8);
				sub_4DAA50(v13, 0, 2944.0, 2944.0);
				sub_4DAC00();
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					if (!sub_4E8210(v13, (int)&v28))
						sub_4F7AB0(&v28, v13);
				} else {
					sub_4F7AB0(&v28, v13);
				}
				sub_4E7010(v13, &v28);
				sub_422140((int)v8);
				if (a1 != 31) {
					if (sub_459D70() == 2) {
						v26 = (unsigned __int8)v8[2064];
						v24 = sub_416590(1);
						sub_4DD9B0(1, v24, v26);
					} else {
						sub_459AA0((int)v29);
						sub_4DD9B0(1, v29, (unsigned __int8)v8[2064]);
					}
				}
				if (nox_common_gameFlags_check_40A5C0(49152)) {
					if (!(v8[3680] & 1))
						sub_509C30((int)v8);
				}
				if (!nox_common_gameFlags_check_40A5C0(2048)) {
					if (nox_common_gameFlags_check_40A5C0(4096)) {
						sub_4D6960(a1);
						return *(_DWORD**)(v13 + 36);
					}
					LOWORD(v27) = 484;
					BYTE2(v27) = 1;
					sub_4E5420(a1, &v27, 3, 0, 0);
				}
				return *(_DWORD**)(v13 + 36);
			}
			*((_WORD*)v8 + 5) = nox_win_width / 2;
			v10 = nox_win_height / 2;
		}
		*((_WORD*)v8 + 6) = v10;
		goto LABEL_23;
	}
	return result;
}

//----- (004DD9B0) --------------------------------------------------------
int __cdecl sub_4DD9B0(char a1, const void* a2, int a3) {
	char v4[60]; // [esp+8h] [ebp-3Ch]

	v4[0] = -79;
	v4[1] = a1;
	qmemcpy(&v4[2], a2, 0x3Au);
	return sub_4E5390(a3, (int)v4, 60, 0, 0);
}

//----- (004DDA00) --------------------------------------------------------
char* __cdecl sub_4DDA00(int a1) {
	int i;        // ebx
	char* result; // eax
	int v3;       // esi

	for (i = 2;; ++i) {
		result = sub_416EA0();
		v3 = (int)result;
		if (!result)
			break;
		while (*(_BYTE*)(a1 + 2064) == *(_BYTE*)(v3 + 2064) ||
		       nox_wcscmp((const wchar_t*)(a1 + 4704), (const wchar_t*)(v3 + 4704))) {
			result = sub_416EE0(v3);
			v3 = (int)result;
			if (!result)
				return result;
		}
		nox_swprintf((wchar_t*)(a1 + 2274), L" %d", i);
		nox_swprintf((wchar_t*)(a1 + 4704), L"%s%s", a1 + 2185, a1 + 2274);
	}
	return result;
}

//----- (004DDA90) --------------------------------------------------------
unsigned int __cdecl sub_4DDA90(int a1, int a2) {
	unsigned int result; // eax

	*(_BYTE*)a1 = 45;
	*(_WORD*)(a1 + 1) = *(_WORD*)(a2 + 2060);
	*(_WORD*)(a1 + 100) = *(_WORD*)(a2 + 2136);
	*(_WORD*)(a1 + 102) = *(_WORD*)(a2 + 2140);
	*(_DWORD*)(a1 + 104) = *(_DWORD*)a2;
	*(_DWORD*)(a1 + 108) = *(_DWORD*)(a2 + 4);
	*(_BYTE*)(a1 + 116) = *(_BYTE*)(a2 + 2152);
	*(_BYTE*)(a1 + 117) = *(_BYTE*)(a2 + 2156);
	*(_BYTE*)(a1 + 118) = *(_BYTE*)(a2 + 3676) == 3;
	*(_DWORD*)(a1 + 112) = *(_DWORD*)(a2 + 3680) & 0x423;
	result = strlen((const char*)(a2 + 2096)) + 1;
	qmemcpy((void*)(a1 + 119), (const void*)(a2 + 2096), result);
	qmemcpy((void*)(a1 + 3), (const void*)(a2 + 2185), 0x61u);
	return result;
}

//----- (004DDB40) --------------------------------------------------------
_DWORD* __cdecl sub_4DDB40(_DWORD* a1) {
	int v1;       // ebx
	int v2;       // eax
	char* v3;     // ebp
	char v5[256]; // [esp+10h] [ebp-100h]

	*(_DWORD*)&v5[1] = *(_DWORD*)&byte_5D4594[2598000];
	v1 = a1[187];
	v5[0] = 40;
	sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), 1, v5, 5);
	v5[0] = 44;
	*(_WORD*)&v5[1] = sub_578AC0(a1);
	v2 = *(_DWORD*)(v1 + 276);
	*(_DWORD*)&v5[3] = *(_DWORD*)(v2 + 2068);
	sub_40EBC0(*(unsigned __int8*)(v2 + 2064), 1, v5, 7);
	sub_4161E0();
	v3 = sub_416590(0);
	v5[8] = -81;
	*(_DWORD*)&v5[9] = *(_DWORD*)&byte_5D4594[2598000];
	*(_DWORD*)&v5[17] = nox_common_gameFlags_getVal_40A5B0() & 0x7FFF0;
	*(_DWORD*)&v5[21] = sub_409E60();
	*(_DWORD*)&v5[13] = 66458;
	v5[25] = sub_409FA0();
	v5[26] = sub_40A020(*((_WORD*)v3 + 26));
	v5[27] = sub_40A180(*((_WORD*)v3 + 26));
	sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), 1, &v5[8], 20);
	v5[28] = -80;
	strcpy(&v5[29], sub_40A4C0());
	qmemcpy(&v5[45], v3 + 24, 0x1Cu);
	if (sub_40A220() && (sub_40A300() || sub_40A180(*((_WORD*)v3 + 26))))
		*(_DWORD*)&v5[73] = sub_40A230();
	else
		*(_DWORD*)&v5[73] = 0;
	sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), 1, &v5[28], 49);
	sub_4DDA90((int)&v5[124], *(_DWORD*)(v1 + 276));
	sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), 1, &v5[124], 129);
	sub_4DDDC0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064));
	v5[80] = 43;
	strcpy(&v5[81], nox_server_currentMapGetFilename_409B30());
	*(_DWORD*)&v5[113] = sub_409B00();
	*(_DWORD*)&v5[117] = *(_DWORD*)&byte_5D4594[2598000];
	sub_552640(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + 1, &v5[80], 41, 3);
	return sub_4DDE10(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), *(_DWORD*)(v1 + 276));
}

//----- (004DDDC0) --------------------------------------------------------
FILE* __cdecl sub_4DDDC0(int a1) {
	FILE* result;        // eax
	int v2;              // esi
	unsigned __int8* v3; // eax

	result = (FILE*)nox_common_gameFlags_check_40A5C0(2);
	v2 = a1;
	if (!result || a1 != 31) {
		v3 = sub_40ED60(a1, 1u, &a1);
		if (v3)
			sub_552640(v2 + 1, v3, a1, 3);
		result = sub_40ED10(v2, 1);
	}
	return result;
}

//----- (004DDE10) --------------------------------------------------------
_DWORD* __cdecl sub_4DDE10(int a1, int a2) {
	_DWORD* result; // eax
	int i;          // esi
	int v4;         // eax

	result = *(_DWORD**)(a2 + 2056);
	if (result) {
		if (!*(_DWORD*)&byte_5D4594[1563276])
			*(_DWORD*)&byte_5D4594[1563276] = sub_4E3AA0((CHAR*)&byte_587000[200132]);
		result = *(_DWORD**)(a2 + 2056);
		for (i = result[126]; i; i = *(_DWORD*)(i + 496)) {
			v4 = *(_DWORD*)(i + 16);
			if (!(v4 & 0x100)) {
				result = *(_DWORD**)&byte_5D4594[1563276];
				if (*(unsigned __int16*)(i + 4) != *(_DWORD*)&byte_5D4594[1563276])
					continue;
			}
			result = sub_4D82F0(a1, (_DWORD*)i);
		}
	}
	return result;
}

//----- (004DDE80) --------------------------------------------------------
int __cdecl sub_4DDE80(int a1, int a2) {
	int v2;     // edi
	int result; // eax

	v2 = *(_DWORD*)(a1 + 748);
	if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 3680) & 1)
		sub_4E6AA0(*(_DWORD*)(v2 + 276));
	if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 3680) & 2)
		sub_4DDEF0(a1);
	sub_4174F0(*(_DWORD*)(v2 + 276), 2);
	sub_4E6040(a1);
	result = sub_4E6060(a1, a2);
	*(_DWORD*)(a1 + 744) = sub_4E62F0;
	return result;
}

//----- (004DDEF0) --------------------------------------------------------
int __cdecl sub_4DDEF0(int a1) {
	int result; // eax

	result = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
	if (*(_BYTE*)(result + 3680) & 2) {
		sub_417530(result, 2);
		result = sub_4E6040(a1);
		*(_DWORD*)(a1 + 744) = sub_4F8100;
	}
	return result;
}

//----- (004DDF30) --------------------------------------------------------
int __cdecl sub_4DDF30(int a1) {
	int v1;     // eax
	int result; // eax

	v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
	if (*(_BYTE*)(v1 + 3680) & 2)
		result = *(_DWORD*)(v1 + 3628);
	else
		result = 0;
	return result;
}

//----- (004DDF60) --------------------------------------------------------
int __cdecl sub_4DDF60(int a1) {
	int v1;               // ebx
	char* v2;             // esi
	int v3;               // eax
	int v4;               // edi
	int v5;               // ebp
	char* i;              // edi
	int v7;               // eax
	char* v8;             // eax
	char* j;              // edi
	unsigned __int8* v10; // eax
	int k;                // esi
	int v13;              // [esp+Ch] [ebp+4h]

	sub_416640();
	v1 = a1;
	v2 = sub_417090(a1);
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		if (a1 != 31) {
			if (v2) {
				v3 = *((_DWORD*)v2 + 514);
				if (v3)
					*(_DWORD*)(*(_DWORD*)(v3 + 748) + 552) = 1;
			}
		}
		sub_4D9CF0(a1);
		if (v2 && *((_DWORD*)v2 + 514))
			sub_4D6000(*((_DWORD*)v2 + 514));
	}
	sub_57B920(v2 + 16);
	v13 = *((_DWORD*)v2 + 514);
	dword_5d4594_2649712 |= 1 << v1;
	v4 = *(_DWORD*)(v13 + 56);
	v5 = *(_DWORD*)(v13 + 60);
	sub_4DE300(v1);
	*((_DWORD*)v2 + 1175) = 0;
	(*(void(__cdecl**)(int, _DWORD))(v13 + 688))(v13, 0);
	v2[3676] = 3;
	if (!nox_common_gameFlags_check_40A5C0(512)) {
		*((_DWORD*)v2 + 908) = v4;
		*((_DWORD*)v2 + 909) = v5;
	}
	if (dword_587000_108752 && nox_common_gameFlags_check_40A5C0(0x2000) &&
	    !nox_common_gameFlags_check_40A5C0(4096))
		sub_4DD140(v1);
	for (i = sub_416EA0(); i; i = sub_416EE0((int)i)) {
		v7 = *((_DWORD*)i + 514);
		if (v7) {
			if (i != v2) {
				sub_417190(v1, v7, 1);
				sub_417190((unsigned __int8)i[2064], *((_DWORD*)v2 + 514), 1);
				sub_4DF360((unsigned __int8)i[2064], *((_DWORD*)v2 + 514));
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					sub_4D8670((unsigned __int8)i[2064], *((_DWORD**)v2 + 514));
					sub_4D8670(v1, *((_DWORD**)i + 514));
				}
			}
		}
	}
	sub_4DE380(v1);
	sub_4DF2E0(v1);
	if (nox_common_gameFlags_check_40A5C0(1024) && !sub_40AA70((int)v2))
		sub_4174F0((int)v2, 256);
	if (sub_43AF70() == 1) {
		sub_4161E0();
		sub_416690();
	}
	sub_4E8110(v1);
	if (nox_common_gameFlags_check_40A5C0(64)) {
		v8 = sub_4E8310();
		sub_4D95F0(v1, *v8, *((_WORD*)v8 + 1));
	} else if (nox_common_gameFlags_check_40A5C0(32)) {
		for (j = sub_418B10(); j; j = sub_418B60((int)j)) {
			v10 = sub_4E8320(j[57]);
			sub_4D95A0(v1, *v10, v10[2], v10[1], *((_WORD*)v10 + 2));
		}
	}
	sub_4175C0((int)v2);
	if (sub_409F40(0x2000))
		sub_4DE270((int)v2);
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		for (k = sub_4DA7C0(); k; k = sub_4DA7F0(k)) {
			if (*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(k + 748) + 276) + 4792) == 1)
				sub_4D9D20(v1, k);
		}
	}
	if (nox_common_gameFlags_check_40A5C0(4096))
		sub_4D7A60(v1);
	return *(_DWORD*)(v13 + 36);
}

//----- (004DE270) --------------------------------------------------------
int __cdecl sub_4DE270(int a1) {
	int result; // eax
	int i;      // esi
	int v3;     // [esp-1Ch] [ebp-28h]
	char v4[7]; // [esp+4h] [ebp-8h]

	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		if (*(_DWORD*)(i + 36) != *(_DWORD*)(a1 + 2060)) {
			if (*(_DWORD*)(*(_DWORD*)(i + 748) + 260)) {
				v4[0] = -46;
				*(_WORD*)&v4[1] = sub_578AC0((_DWORD*)i);
				v3 = *(unsigned __int8*)(a1 + 2064);
				*(_WORD*)&v4[3] = *(_WORD*)(i + 4);
				v4[5] = 1;
				v4[6] = 2;
				sub_4E5420(v3, v4, 7, 0, 1);
			}
		}
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004DE300) --------------------------------------------------------
char* __cdecl sub_4DE300(int a1) {
	char* result; // eax
	int i;        // esi
	char v3[132]; // [esp+4h] [ebp-84h]

	result = sub_416EA0();
	for (i = (int)result; result; i = (int)result) {
		if (*(unsigned __int8*)(i + 2064) != a1 &&
		    (*(_BYTE*)(i + 2064) != 31 || !(*(_DWORD*)&nox_common_engineFlags & 0x40000))) {
			sub_4DDA90((int)v3, i);
			sub_4E5390(a1, (int)v3, 129, 0, 0);
			sub_4DDE10(a1, i);
		}
		result = sub_416EE0(i);
	}
	return result;
}

//----- (004DE380) --------------------------------------------------------
int __cdecl sub_4DE380(int a1) {
	int result; // eax
	int i;      // esi
	int v3;     // eax

	if (!*(_DWORD*)&byte_5D4594[1563284])
		*(_DWORD*)&byte_5D4594[1563284] = sub_4E3AA0((CHAR*)&byte_587000[200140]);
	if (!*(_DWORD*)&byte_5D4594[1563272])
		*(_DWORD*)&byte_5D4594[1563272] = sub_4E3AA0((CHAR*)&byte_587000[200152]);
	result = sub_4DA790();
	for (i = result; result; i = result) {
		if (*(_BYTE*)(i + 16) & 4) {
			v3 = *(unsigned __int16*)(i + 4);
			if ((unsigned __int16)v3 == *(_DWORD*)&byte_5D4594[1563284] ||
			    v3 == *(_DWORD*)&byte_5D4594[1563272])
				sub_417190(a1, i, 1);
		}
		result = sub_4DA7A0(i);
	}
	return result;
}

//----- (004DE410) --------------------------------------------------------
_DWORD* __cdecl sub_4DE410(int a1) {
	int v1;          // ebp
	int v2;          // edi
	_DWORD* result;  // eax
	_DWORD* i;       // esi
	int v5;          // ecx
	int v6;          // ebx
	unsigned int v7; // edi
	int v8;          // [esp+10h] [ebp+4h]

	v1 = a1;
	v2 = 1 << a1;
	v8 = 1 << a1;
	result = (_DWORD*)sub_4DA790();
	for (i = result; result; i = result) {
		v5 = i[2];
		i[38] |= v2;
		if (!(v5 & 0x20400000))
			i[37] &= ~v2;
		i[v1 + 140] &= 0xFFFu;
		if (i[2] & 0x20400000) {
			v6 = 0x10000;
			v7 = 1;
			do {
				if (sub_4E4C90((int)i, v7))
					i[v1 + 140] |= v6;
				v7 *= 2;
				v6 *= 2;
			} while (v7 < 0x10000);
			v2 = v8;
		}
		result = (_DWORD*)sub_4DA7A0((int)i);
	}
	return result;
}

//----- (004DE4D0) --------------------------------------------------------
int __cdecl sub_4DE4D0(char a1) {
	int v1;     // esi
	int result; // eax
	char v3;    // cl

	v1 = 1 << a1;
	for (result = sub_4DA790(); result; result = sub_4DA7A0(result)) {
		v3 = *(_BYTE*)(result + 16);
		*(_DWORD*)(result + 152) |= v1;
		if (!(v3 & 0x20) && !(*(_DWORD*)(result + 8) & 0x20400006))
			*(_DWORD*)(result + 148) &= ~v1;
	}
	return result;
}

//----- (004DE530) --------------------------------------------------------
char __cdecl sub_4DE530(int a1, char a2) {
	int v2;      // ebp
	char* v3;    // eax
	int v4;      // esi
	char* v5;    // edi
	char* i;     // edi
	int v7;      // eax
	int j;       // eax
	int v9;      // edx
	char result; // al
	int v11;     // eax
	char v12[3]; // [esp+10h] [ebp-8h]
	int v13;     // [esp+14h] [ebp-4h]

	v2 = a1;
	v13 = 1 << a1;
	sub_4D79A0(a1);
	sub_419EB0(v2, 0);
	sub_4E80C0(v2);
	v3 = sub_417090(v2);
	v4 = (int)v3;
	if (v3) {
		if (*((_DWORD*)v3 + 514))
			sub_506740(*((_DWORD*)v3 + 514));
		if (*(_DWORD*)(v4 + 4792) && *(_DWORD*)(v4 + 2056) && nox_common_gameFlags_check_40A5C0(4096)) {
			sub_501960(1011, *(_DWORD*)(v4 + 2056), 0, 0);
			*(_DWORD*)(v4 + 4792) = 0;
			if (!sub_4E3CE0()) {
				v5 = sub_4D0F60();
				sub_4E3CD0(0);
				sub_4D2450(v5);
			}
			sub_4D7390(*(_DWORD*)(v4 + 2056));
			sub_4DE790(*(_DWORD*)(v4 + 2056));
		}
	}
	if (sub_43AF70() == 1 && !nox_common_gameFlags_check_40A5C0(128))
		sub_425E90(v4, a2);
	for (i = sub_416EA0(); i; i = sub_416EE0((int)i)) {
		v7 = *((_DWORD*)i + 514);
		if (v7 && i != (char*)v4) {
			sub_417300(v2, v7, 3);
			sub_417300((unsigned __int8)i[2064], *(_DWORD*)(v4 + 2056), 3);
		}
	}
	if (*(_DWORD*)(v4 + 2056)) {
		for (j = sub_4DA790(); j; j = sub_4DA7A0(j)) {
			if ((*(_BYTE*)(j + 8) & 0x80) && *(_DWORD*)(j + 508) == *(_DWORD*)(v4 + 2056))
				*(_DWORD*)(j + 508) = 0;
		}
	}
	sub_40C0E0(v2 + 1);
	sub_4DE410(v2);
	if (v4) {
		v12[0] = -82;
		v9 = v2;
		LOBYTE(v9) = v2 | 0x80;
		*(_WORD*)&v12[1] = *(_WORD*)(*(_DWORD*)(v4 + 2056) + 36);
		sub_4E5420(v9, v12, 3, 0, 0);
	}
	if (a2 == 4) {
		LOBYTE(a1) = -59;
		sub_552640(v2 + 1, &a1, 1, 3);
	}
	result = sub_4E55F0(v2);
	if (v4) {
		sub_4E5AD0(*(_DWORD*)(v4 + 2056));
		if (nox_common_gameFlags_check_40A5C0(4096))
			sub_4DE790(*(_DWORD*)(v4 + 2056));
		else
			sub_4EDA40(*(_DWORD**)(v4 + 2056));
		v11 = v13;
		*(_DWORD*)(v4 + 2140) = 0;
		*(_DWORD*)(v4 + 2136) = 0;
		dword_5d4594_2649712 &= ~v11;
		*(_BYTE*)(v4 + 3676) = 2;
		result = sub_417530(v4, 16);
	}
	return result;
}

//----- (004DE790) --------------------------------------------------------
void __cdecl sub_4DE790(int a1) {
	int v1; // esi
	int v2; // edi

	v1 = sub_4E7980(a1);
	if (v1) {
		do {
			v2 = sub_4E7990(v1);
			sub_4E5CC0(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (004DE7C0) --------------------------------------------------------
char* __cdecl sub_4DE7C0(int a1) {
	int v1;               // edi
	char* v2;             // esi
	int* v3;              // eax
	int v4;               // ebp
	int v5;               // eax
	int i;                // eax
	int v7;               // ecx
	int v8;               // eax
	char* result;         // eax
	unsigned __int8* v11; // eax
	int v12;              // eax
	int v13;              // eax
	unsigned __int8* v14; // eax

	v1 = a1;
	v2 = sub_417090(a1);
	if (sub_4D12A0(v1))
		sub_4D1250(v1);
	if (*((_DWORD*)v2 + 517)) {
		v3 = sub_425A70(*((_DWORD*)v2 + 517));
		if (v3)
			sub_425B60(v3, v1);
	}
	v4 = *(_DWORD*)(*((_DWORD*)v2 + 514) + 748);
	if (*(_DWORD*)(v4 + 280))
		sub_510DC0(*(_DWORD**)(v4 + 280));
	*(_DWORD*)(v4 + 280) = 0;
	sub_510E20((unsigned __int8)v2[2064]);
	sub_4FF990(1 << v2[2064]);
	if (!nox_common_gameFlags_check_40A5C0(2))
		*((_DWORD*)v2 + 523) = 0;
	sub_56F4F0((int*)v2 + 1146);
	sub_56F4F0((int*)v2 + 1148);
	sub_56F4F0((int*)v2 + 1149);
	sub_56F4F0((int*)v2 + 1150);
	sub_56F4F0((int*)v2 + 1151);
	sub_56F4F0((int*)v2 + 1152);
	sub_56F4F0((int*)v2 + 1153);
	sub_56F4F0((int*)v2 + 1154);
	sub_56F4F0((int*)v2 + 1155);
	sub_56F4F0((int*)v2 + 1156);
	sub_56F4F0((int*)v2 + 1157);
	sub_56F4F0((int*)v2 + 1158);
	sub_56F4F0((int*)v2 + 1159);
	sub_56F4F0((int*)v2 + 1147);
	sub_56F4F0((int*)v2 + 1160);
	sub_56F4F0((int*)v2 + 1161);
	LOBYTE(a1) = 46;
	*(_WORD*)((char*)&a1 + 1) = sub_578AC0(*((_DWORD**)v2 + 514));
	v5 = v1;
	LOBYTE(v5) = v1 | 0x80;
	sub_4E5420(v5, &a1, 3, 0, 0);
	sub_4E5CC0(*((_DWORD*)v2 + 514));
	*((_DWORD*)v2 + 514) = 0;
	for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
		v7 = *(_DWORD*)(i + 748);
		*(_BYTE*)(v1 + v7 + 452) = 0;
		*(_DWORD*)(v7 + 4 * v1 + 324) = 0;
		*(_BYTE*)(v1 + v7 + 484) = 0;
		*(_BYTE*)(v1 + v7 + 516) = 0;
	}
	v8 = sub_40A8A0();
	if (v8) {
		if (nox_common_gameFlags_check_40A5C0(1024) && !sub_446180() && sub_40A770() == 1)
			sub_5095E0();
	} else {
		sub_40A1F0(0);
		sub_416E50(1);
		sub_417D00();
		sub_40A970();
	}
	sub_4E55F0(v1);
	sub_4E4F40(v1);
	sub_4E4F30(v1);
	if (sub_43AF70() == 1) {
		sub_4161E0();
		sub_416690();
	}
	result = (char*)nox_common_gameFlags_check_40A5C0(4096);
	if (result) {
		if (sub_4E9010() == 1) {
			v11 = sub_4E8E50();
			result = sub_4D2450((char*)v11);
		} else if (sub_4E8F60()) {
			sub_4D60B0();
			sub_4D76E0(1);
			v12 = sub_4E3CC0();
			v13 = sub_4D74F0(v12);
			sub_4E3CD0(v13 - 1);
			v14 = sub_4E8E50();
			result = sub_4D2450((char*)v14);
		} else {
			result = (char*)sub_4DA7C0();
			if (result) {
				while (!*(_DWORD*)(*((_DWORD*)result + 187) + 312)) {
					result = (char*)sub_4DA7F0((int)result);
					if (!result)
						return result;
				}
				result = (char*)sub_4E8E60();
			}
		}
	}
	return result;
}
// 4DE9A4: variable 'v8' is possibly undefined
// 4DE9E1: variable 'v9' is possibly undefined

//----- (004DEAB0) --------------------------------------------------------
char* __cdecl sub_4DEAB0(int a1, char a2) {
	char* result; // eax
	char* v3;     // esi

	result = sub_417090(a1);
	v3 = result;
	if (result) {
		sub_4DE530((unsigned __int8)result[2064], a2);
		sub_4DE7C0((unsigned __int8)v3[2064]);
		result = (char*)sub_4DEC50((unsigned __int8)v3[2064]);
	}
	return result;
}

//----- (004DEB00) --------------------------------------------------------
char* __cdecl sub_4DEB00(int a1) {
	char* result; // eax

	result = sub_417090(a1);
	if (result)
		result = sub_4DEAB0((unsigned __int8)result[2064], 4);
	return result;
}

//----- (004DEBC0) --------------------------------------------------------
int __cdecl sub_4DEBC0(int a1) {
	int result;  // eax
	char v2[40]; // [esp+4h] [ebp-28h]

	memset(v2, 0, sizeof(v2));
	*(_DWORD*)&v2[16] = sub_409FA0();
	*(_DWORD*)&v2[20] = 2048;
	*(_DWORD*)&v2[8] = a1;
	*(_DWORD*)&v2[12] = 0;
	sub_5520B0(200, 1024);
	*(_DWORD*)&v2[36] = sub_4DEC30;
	*(_DWORD*)&v2[32] = sub_4DF630;
	result = sub_554380((size_t*)v2);
	OnLibraryNotice(256, 0);
	*(_DWORD*)&byte_5D4594[1563148] = result;
	return result;
}

//----- (004DEC30) --------------------------------------------------------
int __cdecl sub_4DEC30(int a1, unsigned __int8* a2, signed int a3) {
	sub_51BAD0_net_sdecode(a1 - 1, a2, a3);
	return 1;
}

//----- (004DEC50) --------------------------------------------------------
int __cdecl sub_4DEC50(int a1) { return sub_5545B0(a1 + 1); }

//----- (004DEC60) --------------------------------------------------------
int __cdecl sub_4DEC60(unsigned int a1) {
	sub_5545B0(a1);
	sub_5546A0(a1);
	OnLibraryNotice(257, 0);
	return sub_552450();
}

//----- (004DEF00) --------------------------------------------------------
int sub_4DEF00() {
	char* v0;    // ebx
	char v2[20]; // [esp+Ch] [ebp-48h]
	char v3[49]; // [esp+20h] [ebp-34h]

	v0 = sub_416590(0);
	v2[0] = -81;
	*(_DWORD*)&v2[1] = *(_DWORD*)&byte_5D4594[2598000];
	*(_DWORD*)&v2[9] = nox_common_gameFlags_getVal_40A5B0() & 0x7FFF0;
	*(_DWORD*)&v2[13] = sub_409E60();
	*(_DWORD*)&v2[5] = 66458;
	v2[17] = sub_409FA0();
	v2[18] = sub_40A020(*((_WORD*)v0 + 26));
	v2[19] = sub_40A180(*((_WORD*)v0 + 26));
	v3[0] = -80;
	strcpy(&v3[1], sub_40A4C0());
	qmemcpy(&v3[17], v0 + 24, 0x1Cu);
	if (sub_40A220() && (sub_40A300() || sub_40A180(*((_WORD*)v0 + 26))))
		*(_DWORD*)&v3[45] = sub_40A230();
	else
		*(_DWORD*)&v3[45] = 0;
	sub_4E5390(159, (int)v2, 20, 0, 0);
	return sub_4E5390(159, (int)v3, 49, 0, 0);
}

//----- (004DF020) --------------------------------------------------------
char* sub_4DF020() {
	char* result;        // eax
	int v1;              // ecx
	unsigned __int8* v2; // edi
	char* v3;            // esi
	bool v4;             // zf
	char* i;             // esi
	char v6[60];         // [esp+8h] [ebp-3Ch]

	result = sub_459AA0((int)v6);
	v1 = 29;
	v2 = &byte_5D4594[1563214];
	v3 = v6;
	v4 = 1;
	do {
		if (!v1)
			break;
		v4 = *(_WORD*)v3 == *(_WORD*)v2;
		v3 += 2;
		v2 += 2;
		--v1;
	} while (v4);
	if (!v4) {
		result = sub_416EA0();
		for (i = result; result; i = result) {
			if (i[2064] != 31)
				sub_4DD9B0(1, v6, (unsigned __int8)i[2064]);
			result = sub_416EE0((int)i);
		}
		qmemcpy(&byte_5D4594[1563214], v6, 0x38u);
		*(_WORD*)&byte_5D4594[1563270] = *(_WORD*)&v6[56];
	}
	return result;
}

//----- (004DF0A0) --------------------------------------------------------
int __cdecl sub_4DF0A0(int a1, int a2) {
	int result; // eax
	int i;      // esi
	char v4[3]; // [esp+4h] [ebp-4h]

	v4[0] = 58;
	*(_WORD*)&v4[1] = *(_WORD*)(a1 + 10);
	if (a2 != 32)
		return sub_4E5420(a2, v4, 3, 0, 1);
	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), v4, 3, 0, 1);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004DF120) --------------------------------------------------------
int __cdecl sub_4DF120(int a1) {
	int result; // eax
	int i;      // esi
	char v3[3]; // [esp+4h] [ebp-4h]

	v3[0] = 59;
	*(_WORD*)&v3[1] = *(_WORD*)(a1 + 10);
	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), v3, 3, 0, 1);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004DF180) --------------------------------------------------------
int __cdecl sub_4DF180(int a1) {
	int result; // eax
	int i;      // esi
	char v3[3]; // [esp+4h] [ebp-4h]

	v3[0] = 60;
	*(_WORD*)&v3[1] = *(_WORD*)(a1 + 10);
	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), v3, 3, 0, 1);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004DF1E0) --------------------------------------------------------
int __cdecl sub_4DF1E0(int a1) {
	int* i;     // esi
	int v2;     // eax
	int result; // eax
	int j;      // esi
	char v5;    // al

	for (i = (int*)sub_410870(); i; i = (int*)sub_410880(i)) {
		v2 = i[1];
		if (*(_BYTE*)(v2 + 4) & 0x20)
			sub_4DF0A0(v2, a1);
	}
	sub_4DF2A0(a1);
	if (sub_5071C0())
		sub_507190(a1, 1);
	result = nox_common_gameFlags_check_40A5C0(4096);
	if (result) {
		for (j = sub_4DA790(); j; j = sub_4DA7A0(j)) {
			if ((*(_BYTE*)(j + 8) & 0x80) && *(_BYTE*)(*(_DWORD*)(j + 748) + 48))
				sub_4D6A20(a1, j);
		}
		result = sub_4D72C0();
		if (result == 1) {
			v5 = sub_4D72C0();
			result = sub_4D7280(a1, v5);
		}
	}
	return result;
}

//----- (004DF2A0) --------------------------------------------------------
int* __cdecl sub_4DF2A0(char a1) {
	int v1;      // esi
	int* result; // eax

	v1 = 1 << a1;
	for (result = (int*)sub_410780(); result; result = (int*)sub_410790(result)) {
		if (result[5] & 8)
			result[7] |= v1;
		else
			result[7] &= ~v1;
	}
	return result;
}

//----- (004DF2E0) --------------------------------------------------------
void __cdecl sub_4DF2E0(int a1) {
	char* i; // ebx
	int j;   // esi

	if (a1 != 31) {
		for (i = sub_418B10(); i; i = sub_418B60((int)i)) {
			sub_4197C0((wchar_t*)i, a1);
			for (j = sub_4DA7C0(); j; j = sub_4DA7F0(j)) {
				if (sub_419180(j + 48, i[57]))
					sub_4198A0(j + 48, a1, *(_DWORD*)(j + 36));
			}
		}
	}
}

//----- (004DF360) --------------------------------------------------------
int __cdecl sub_4DF360(int a1, int a2) {
	__int16 v2; // ax
	float v3;   // ecx
	__int16 v4; // ax
	float v5;   // edx
	char v7[9]; // [esp+4h] [ebp-Ch]

	v7[0] = 47;
	*(_WORD*)&v7[3] = *(_WORD*)(a2 + 4);
	v2 = sub_578AC0((_DWORD*)a2);
	v3 = *(float*)(a2 + 56);
	*(_WORD*)&v7[1] = v2;
	v4 = nox_float2int(v3);
	v5 = *(float*)(a2 + 60);
	*(_WORD*)&v7[5] = v4;
	*(_WORD*)&v7[7] = nox_float2int(v5);
	return sub_4E5390(a1, (int)v7, 9, 0, 1);
}

//----- (004DF3C0) --------------------------------------------------------
char __cdecl sub_4DF3C0(int a1) {
	int v1;   // edi
	char* v2; // eax
	char* v3; // ebx
	char* v4; // ebx
	char* v5; // esi
	int v6;   // ebx
	BOOL v7;  // eax
	int v8;   // esi
	int v9;   // ebx

	v1 = *(_DWORD*)(a1 + 2056);
	v2 = sub_416640();
	v3 = v2;
	if (!v1)
		return (char)v2;
	if (!sub_40A740() && !nox_common_gameFlags_check_40A5C0(0x8000)) {
		LOBYTE(v2) = sub_417DD0();
		if ((_BYTE)v2) {
			v2 = sub_4189D0();
			v4 = v2;
			if (v2) {
				v2 = (char*)sub_419130(v1 + 48);
				if (!v2)
					LOBYTE(v2) =
					    (unsigned int)sub_4191D0(v4[57], v1 + 48, 1, *(_DWORD*)(v1 + 36), 1);
			}
		}
		return (char)v2;
	}
	v2 = *(char**)(a1 + 2068);
	if (!v2)
		return (char)v2;
	v5 = sub_418AE0(*(_DWORD*)(a1 + 2068));
	if (v5) {
		v6 = v1 + 48;
		v7 = sub_419130(v1 + 48);
		goto LABEL_11;
	}
	v8 = (unsigned __int8)v3[52];
	if ((nox_common_gameFlags_check_40A5C0(96) || nox_common_gameFlags_check_40A5C0(16) && sub_417DA0(4)) && v8 > 2)
		v8 = 2;
	v2 = (char*)(unsigned __int8)sub_417DE0();
	if ((int)v2 < v8) {
		if (!nox_common_gameFlags_check_40A5C0(96) ||
		    (v9 = (unsigned __int8)sub_417DE0(), v2 = (char*)sub_417DC0(), v9 < (int)v2)) {
			v2 = sub_418A10();
			v5 = v2;
			if (v2) {
				sub_418800((wchar_t*)v2, (wchar_t*)(a1 + 2072), 0);
				sub_418830((int)v5, *(_DWORD*)(a1 + 2068));
				sub_4184D0((wchar_t*)v5);
				v6 = v1 + 48;
				v7 = sub_419130(v1 + 48);
			LABEL_11:
				if (v7)
					LOBYTE(v2) = sub_4196D0(v6, (int)v5, *(_DWORD*)(v1 + 36), 0);
				else
					LOBYTE(v2) = (unsigned int)sub_4191D0(v5[57], v6, 1, *(_DWORD*)(v1 + 36), 0);
				return (char)v2;
			}
		}
	}
	return (char)v2;
}

//----- (004DF550) --------------------------------------------------------
int sub_4DF550() { return *(_DWORD*)&byte_5D4594[1563148]; }

//----- (004DF560) --------------------------------------------------------
void sub_4DF560() { nox_srand(0x49C3B97u); }

//----- (004DF570) --------------------------------------------------------
void sub_4DF570() { nox_srand(0x22FEu); }

//----- (004DF580) --------------------------------------------------------
int __cdecl sub_4DF580(int a1, _DWORD* a2) {
	int v2; // eax
	int v3; // ecx
	int v4; // ebx
	int v5; // ecx
	int v6; // eax
	int v7; // ecx

	v2 = *(unsigned __int16*)(a1 + 5);
	if ((unsigned __int16)v2 - (int)*a2 >= 0)
		v3 = (unsigned __int16)v2 - *a2;
	else
		v3 = *a2 - v2;
	v4 = a2[2];
	if (v3 >= v4)
		return 0;
	v5 = a2[1];
	v6 = *(unsigned __int16*)(a1 + 7);
	v7 = (unsigned __int16)v6 - v5 >= 0 ? (unsigned __int16)v6 - v5 : v5 - v6;
	if (v7 >= v4)
		return 0;
	*(_DWORD*)&byte_5D4594[1563300] = a1;
	return 1;
}

//----- (004DF5E0) --------------------------------------------------------
int __cdecl sub_4DF5E0(int a1, int a2) {
	int v3[3]; // [esp+0h] [ebp-Ch]

	v3[0] = *(_DWORD*)&byte_5D4594[1563292];
	v3[1] = *(_DWORD*)&byte_5D4594[1563296];
	v3[2] = a2;
	*(_DWORD*)&byte_5D4594[1563300] = 0;
	sub_40F0F0(a1, (int(__cdecl*)(_DWORD, int))sub_4DF580, (int)v3);
	return *(_DWORD*)&byte_5D4594[1563300];
}

//----- (004DF630) --------------------------------------------------------
int __cdecl sub_4DF630(int a1, char* a2, unsigned int a3) {
	char* v3;        // edi
	int v4;          // ebx
	char* v5;        // ebp
	char* v6;        // eax
	int** v7;        // esi
	unsigned int v8; // eax
	int** v9;        // eax
	char* v10;       // edi
	int v11;         // eax
	char* v13;       // edi
	_BYTE* v14;      // eax
	int** i;         // esi
	signed int v16;  // eax
	int** j;         // eax
	signed int v18;  // eax

	v3 = a2;
	v4 = a1 - 1;
	v5 = &a2[a3];
	v6 = sub_417090(a1 - 1);
	*(_DWORD*)&byte_5D4594[1563308] = 0;
	*(_DWORD*)&byte_5D4594[1563312] = 0;
	*(_DWORD*)&byte_5D4594[1563304] = v6 + 16;
	v7 = sub_40F080(a1 - 1, &a3);
	if (sub_4DF7F0(v7)) {
		v8 = a3;
		qmemcpy(a2, v7, a3);
		v3 = &a2[v8];
		v9 = sub_40F080(v4, &a3);
		if (v9) {
			*v3 = -92;
			v10 = v3 + 1;
			v11 = sub_4DF810(v10, (int)v5, (int)v9);
			if (!v11)
				return v10 - a2 - 1;
			v13 = &v10[v11];
			do {
				v14 = sub_4DF8F0(v4, v13, (int)v5);
				v13 = &v13[(_DWORD)v14];
			} while (v14);
			v3 = &v13[sub_4DF8C0(v13, (int)v5)];
		}
	}
	for (i = sub_40EEB0(v4, 1, &a3); i; i = sub_40EEB0(v4, 1, &a3)) {
		if (*(char*)i != -107 || *(int*)&dword_5d4594_2650652 != 1 ||
		    !(*(_DWORD*)&byte_5D4594[2598000] % (unsigned int)sub_40A6C0())) {
			v16 = sub_4DFAF0(v3, (int)v5, i, a3);
			if (!v16)
				return v3 - a2;
			v3 += v16;
		}
	}
	*(_DWORD*)&byte_5D4594[1563312] = v3 - a2;
	if (!dword_5d4594_2650652 || !(*(_DWORD*)&byte_5D4594[2598000] % (unsigned int)sub_40A6C0()) ||
	    nox_common_gameFlags_check_40A5C0(8)) {
		sub_4E5770(v4, 1);
		for (j = sub_40EEB0(v4, 1, &a3); j; j = sub_40EEB0(v4, 1, &a3)) {
			v18 = sub_4DFAF0(v3, (int)v5, j, a3);
			if (!v18)
				break;
			v3 += v18;
		}
	}
	return v3 - a2;
}

//----- (004DF7F0) --------------------------------------------------------
BOOL __cdecl sub_4DF7F0(_BYTE* a1) { return a1 && (*a1 == 39 || *a1 == 40); }

//----- (004DF810) --------------------------------------------------------
int __cdecl sub_4DF810(char* a1, int a2, int a3) {
	char v4;   // al
	bool v5;   // zf
	char* v6;  // eax
	char v7;   // cl
	_BYTE* v8; // eax
	_BYTE* v9; // eax

	if (*(char*)a3 != -61)
		return 0;
	if (a2 - (int)a1 < 16)
		return 0;
	*(_WORD*)(a3 + 5) &= 0xFFFEu;
	*(_WORD*)(a3 + 7) &= 0xFFFEu;
	v4 = sub_57B930(*(int*)&byte_5D4594[1563304], *(unsigned __int16*)(a3 + 1), *(unsigned __int16*)(a3 + 3),
			*(unsigned int*)&byte_5D4594[2598000]);
	v5 = v4 == -1;
	*a1 = v4;
	v6 = a1 + 1;
	if (v5) {
		*(_DWORD*)v6 = *(_DWORD*)(a3 + 1);
		v6 = a1 + 5;
	}
	*(_DWORD*)v6 = *(_DWORD*)(a3 + 5);
	v7 = *(_BYTE*)(a3 + 9);
	v8 = v6 + 4;
	*v8 = v7;
	if (*(char*)(a3 + 10) != -1) {
		*v8++ = v7 | 0x80;
		*v8 = *(_BYTE*)(a3 + 10);
	}
	v9 = v8 + 1;
	*v9 = *(_BYTE*)(a3 + 11);
	*(_DWORD*)&byte_5D4594[1563292] = *(unsigned __int16*)(a3 + 5);
	*(_DWORD*)&byte_5D4594[1563296] = *(unsigned __int16*)(a3 + 7);
	return (char*)v9 - a1 + 1;
}

//----- (004DF8C0) --------------------------------------------------------
int __cdecl sub_4DF8C0(_BYTE* a1, int a2) {
	if (a2 - (int)a1 < 3)
		return 0;
	*a1 = 0;
	a1[1] = 0;
	a1[2] = 0;
	return 3;
}

//----- (004DF8F0) --------------------------------------------------------
_BYTE* __cdecl sub_4DF8F0(int a1, _BYTE* a2, int a3) {
	_BYTE* v3; // ebp
	int v4;    // edi
	int v6;    // esi
	int v7;    // eax
	int v8;    // edi

	v3 = a2;
	v4 = 127;
	if (!sub_40F0B0(a1))
		return 0;
	v6 = sub_4DF5E0(a1, 127);
	if (!v6) {
		while (1) {
			v4 += 127;
			if (v4 > 4064)
				return 0;
			v6 = sub_4DF5E0(a1, v4);
			if (v6) {
				if (v4 <= 127)
					break;
				*a2 = 0;
				v7 = 1;
				v3 = a2 + 1;
				goto LABEL_9;
			}
		}
	}
	v7 = 0;
LABEL_9:
	v8 = sub_4DF9B0((int)v3, a3, v6, v7);
	if (v8 == -1)
		return (_BYTE*)(v3 - a2);
	sub_40F000(a1, v6);
	return &v3[v8 - (_DWORD)a2];
}

//----- (004DF9B0) --------------------------------------------------------
int __cdecl sub_4DF9B0(int a1, int a2, int a3, int a4) {
	char v4;              // al
	unsigned __int16* v5; // esi
	unsigned __int16 v6;  // ax
	_WORD* v7;            // esi
	_BYTE* v8;            // esi
	_BYTE* v10;           // esi
	char v11;             // al
	float v12;            // [esp+0h] [ebp-14h]
	float v13;            // [esp+0h] [ebp-14h]

	if (a2 - a1 < 8 || a4 && a2 - a1 < 10)
		return -1;
	v4 = sub_57B930(*(int*)&byte_5D4594[1563304], *(unsigned __int16*)(a3 + 1), *(unsigned __int16*)(a3 + 3),
			*(unsigned int*)&byte_5D4594[2598000]);
	*(_BYTE*)a1 = v4;
	v5 = (unsigned __int16*)(a1 + 1);
	if (v4 == -1) {
		*v5 = *(_WORD*)(a3 + 1);
		*(_WORD*)(a1 + 3) = *(_WORD*)(a3 + 3);
		v5 = (unsigned __int16*)(a1 + 5);
	}
	if (a4) {
		v6 = *(_WORD*)(a3 + 5);
		if (v6 > 0x1770u || *(_WORD*)(a3 + 7) > 0x1770u)
			return 0;
		*v5 = v6;
		v7 = v5 + 1;
		*v7 = *(_WORD*)(a3 + 7);
		v8 = v7 + 1;
	} else {
		v12 = (double)*(unsigned __int16*)(a3 + 5);
		*(_BYTE*)v5 = nox_float2int(v12) - byte_5D4594[1563292];
		v10 = (char*)v5 + 1;
		v13 = (double)*(unsigned __int16*)(a3 + 7);
		*v10 = nox_float2int(v13) - byte_5D4594[1563296];
		v8 = v10 + 1;
	}
	*(_DWORD*)&byte_5D4594[1563292] = *(unsigned __int16*)(a3 + 5);
	*(_DWORD*)&byte_5D4594[1563296] = *(unsigned __int16*)(a3 + 7);
	if (*(char*)a3 == 48 || *(char*)a3 == -61) {
		v11 = *(_BYTE*)(a3 + 9);
		*v8 = v11;
		if (*(char*)(a3 + 10) != -1) {
			*v8++ = v11 | 0x80;
			*v8 = *(_BYTE*)(a3 + 10);
		}
		if (*(char*)a3 == -61)
			*++v8 = *(_BYTE*)(a3 + 11);
		++v8;
	}
	return (int)&v8[-a1];
}

//----- (004DFAF0) --------------------------------------------------------
signed int __cdecl sub_4DFAF0(void* a1, int a2, const void* a3, signed int a4) {
	signed int result; // eax

	result = a4;
	if (a2 - (int)a1 < a4)
		return 0;
	qmemcpy(a1, a3, a4);
	return result;
}

//----- (004DFB20) --------------------------------------------------------
int sub_4DFB20() { return *(_DWORD*)&byte_5D4594[1563312]; }

//----- (004DFB30) --------------------------------------------------------
void sub_4DFB30() { nox_srand(0x22FFu); }

//----- (004DFB40) --------------------------------------------------------
void sub_4DFB40() { nox_srand(0x2274u); }

//----- (004DFB50) --------------------------------------------------------
_DWORD* __cdecl sub_4DFB50(int a1, int a2) {
	*(_BYTE*)(a2 + 440) |= 8u;
	return sub_501960(75, a2, 0, 0);
}

//----- (004DFB80) --------------------------------------------------------
_DWORD* __cdecl sub_4DFB80(int a1, int a2) {
	if (!sub_4DFBB0(a2, 8))
		*(_BYTE*)(a2 + 440) &= 0xF7u;
	return sub_501960(76, a2, 0, 0);
}

//----- (004DFBB0) --------------------------------------------------------
int __cdecl sub_4DFBB0(int a1, char a2) {
	_DWORD* v2;          // ebp
	int v3;              // eax
	int v4;              // edi
	int v5;              // esi
	unsigned __int8* v6; // eax

	if (!a1)
		return 0;
	if (!a2)
		return 0;
	v2 = *(_DWORD**)(a1 + 504);
	if (!v2)
		return 0;
	while (1) {
		v3 = v2[4];
		if (v3 & 0x100) {
			if (v2[2] & 0x13001000)
				break;
		}
	LABEL_13:
		v2 = (_DWORD*)v2[124];
		if (!v2)
			return 0;
	}
	v4 = 0;
	v5 = v2[173];
	while (!*(_DWORD*)v5) {
	LABEL_12:
		++v4;
		v5 += 4;
		if (v4 >= 4)
			goto LABEL_13;
	}
	v6 = &byte_587000[200164];
	while (*(_DWORD*)(*(_DWORD*)v5 + 112) != *((_DWORD*)v6 - 1) || a2 != *v6) {
		v6 += 20;
		if ((int)v6 >= (int)&byte_587000[200284])
			goto LABEL_12;
	}
	return 1;
}

//----- (004DFC30) --------------------------------------------------------
void __cdecl sub_4DFC30(int a1, int a2) {
	int v2; // esi
	int v3; // edx
	int v5; // [esp+Ch] [ebp+8h]

	v2 = a2;
	if (a2) {
		if (*(_BYTE*)(a2 + 8) & 4) {
			v3 = *(_DWORD*)(a2 + 748);
			*(_BYTE*)(a2 + 440) |= 0x10u;
			*(float*)&v5 = *(float*)(a1 + 120) + *(float*)(a2 + 552);
			*(float*)(v2 + 552) = *(float*)&v5;
			sub_4D9360(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (_DWORD*)v2, 0, v5);
			sub_501960(59, v2, 0, 0);
		}
	}
}

//----- (004DFCA0) --------------------------------------------------------
void __cdecl sub_4DFCA0(int a1, int a2) {
	int v2; // esi
	int v3; // edx
	int v4; // [esp+Ch] [ebp+8h]

	v2 = a2;
	if (a2 && *(_BYTE*)(a2 + 8) & 4) {
		if (!sub_4DFBB0(a2, 16))
			*(_BYTE*)(a2 + 440) &= 0xEFu;
		v3 = *(_DWORD*)(a2 + 748);
		*(float*)&v4 = *(float*)(a2 + 552) - *(float*)(a1 + 120);
		*(float*)(v2 + 552) = *(float*)&v4;
		sub_4D9360(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (_DWORD*)v2, 0, v4);
		sub_501960(60, v2, 0, 0);
	}
}

//----- (004DFD10) --------------------------------------------------------
_DWORD* __cdecl sub_4DFD10(int a1, int a2) {
	*(_BYTE*)(a2 + 440) |= 1u;
	return sub_501960(102, a2, 0, 0);
}

//----- (004DFD40) --------------------------------------------------------
void __cdecl sub_4DFD40(int a1, int a2, int a3) {
	if (a2 && a3) {
		if (!sub_4DFBB0(a2, 1))
			*(_BYTE*)(a2 + 440) &= 0xFEu;
		sub_501960(103, a2, 0, 0);
	}
}

//----- (004DFD80) --------------------------------------------------------
_DWORD* __cdecl sub_4DFD80(int a1, int a2) {
	*(_BYTE*)(a2 + 440) |= 4u;
	return sub_501960(106, a2, 0, 0);
}

//----- (004DFDB0) --------------------------------------------------------
_DWORD* __cdecl sub_4DFDB0(int a1, int a2) {
	if (!sub_4DFBB0(a2, 4))
		*(_BYTE*)(a2 + 440) &= 0xFBu;
	return sub_501960(107, a2, 0, 0);
}

//----- (004DFDE0) --------------------------------------------------------
_DWORD* __cdecl sub_4DFDE0(int a1, int a2) {
	*(_BYTE*)(a2 + 440) |= 2u;
	return sub_501960(110, a2, 0, 0);
}

//----- (004DFE10) --------------------------------------------------------
_DWORD* __cdecl sub_4DFE10(int a1, int a2) {
	if (!sub_4DFBB0(a2, 2))
		*(_BYTE*)(a2 + 440) &= 0xFDu;
	return sub_501960(111, a2, 0, 0);
}

//----- (004DFE40) --------------------------------------------------------
double __cdecl sub_4DFE40(_DWORD* a1) {
	double v1;           // st7
	double result;       // st7
	_DWORD* v3;          // edx
	int v4;              // eax
	int* v5;             // ecx
	int v6;              // esi
	int v7;              // eax
	int* v8;             // ecx
	int v9;              // edx
	int v10;             // eax
	unsigned __int8 v11; // al
	float v12;           // [esp+4h] [ebp-4h]

	v1 = 0.0;
	v12 = 0.0;
	if (!a1)
		return 0.0;
	v3 = (_DWORD*)a1[126];
	if (v3) {
		do {
			v4 = v3[4];
			if (v4 & 0x100 && v3[2] & 0x13001000) {
				v5 = (int*)v3[173];
				v6 = 4;
				do {
					v7 = *v5;
					if (*v5 && *(_DWORD * (__cdecl**)(int, int))(v7 + 112) == sub_4DFD10)
						v1 = v1 + *(float*)(v7 + 120);
					++v5;
					--v6;
				} while (v6);
			}
			v3 = (_DWORD*)v3[124];
		} while (v3);
		v12 = v1;
	}
	if (a1[2] & 0x13001000) {
		v8 = (int*)a1[173];
		v9 = 4;
		do {
			v10 = *v8;
			if (*v8 && *(_DWORD * (__cdecl**)(int, int))(v10 + 112) == sub_4DFD10)
				v1 = v1 + *(float*)(v10 + 120);
			++v8;
			--v9;
		} while (v9);
		v12 = v1;
	}
	if (v1 > 0.5)
		v12 = 0.5;
	if (sub_4FF350((int)a1, 17)) {
		v11 = sub_4FF570((int)a1, 17);
		result = sub_419D70(&byte_587000[200656], (unsigned int)v11 - 1) + v12;
	} else {
		result = v12;
	}
	if (result > 0.60000002)
		result = 0.60000002;
	return result;
}

//----- (004DFF40) --------------------------------------------------------
double __cdecl sub_4DFF40(_DWORD* a1) {
	double v1;           // st7
	double result;       // st7
	_DWORD* v3;          // edx
	int v4;              // eax
	int* v5;             // ecx
	int v6;              // esi
	int v7;              // eax
	int* v8;             // ecx
	int v9;              // edx
	int v10;             // eax
	unsigned __int8 v11; // al
	float v12;           // [esp+4h] [ebp-4h]

	v1 = 0.0;
	v12 = 0.0;
	if (!a1)
		return 0.0;
	v3 = (_DWORD*)a1[126];
	if (v3) {
		do {
			v4 = v3[4];
			if (v4 & 0x100 && v3[2] & 0x13001000) {
				v5 = (int*)v3[173];
				v6 = 4;
				do {
					v7 = *v5;
					if (*v5 && *(_DWORD * (__cdecl**)(int, int))(v7 + 112) == sub_4DFD80)
						v1 = v1 + *(float*)(v7 + 120);
					++v5;
					--v6;
				} while (v6);
			}
			v3 = (_DWORD*)v3[124];
		} while (v3);
		v12 = v1;
	}
	if (a1[2] & 0x13001000) {
		v8 = (int*)a1[173];
		v9 = 4;
		do {
			v10 = *v8;
			if (*v8 && *(_DWORD * (__cdecl**)(int, int))(v10 + 112) == sub_4DFD80)
				v1 = v1 + *(float*)(v10 + 120);
			++v8;
			--v9;
		} while (v9);
		v12 = v1;
	}
	if (v1 >= 0.5)
		v12 = 0.5;
	if (sub_4FF350((int)a1, 20)) {
		v11 = sub_4FF570((int)a1, 20);
		result = sub_419D70(&byte_587000[200676], (unsigned int)v11 - 1) + v12;
	} else {
		result = v12;
	}
	if (result > 0.60000002)
		result = 0.60000002;
	return result;
}

//----- (004E0040) --------------------------------------------------------
double __cdecl sub_4E0040(_DWORD* a1) {
	double v1;           // st7
	double result;       // st7
	_DWORD* v3;          // edx
	int v4;              // eax
	int* v5;             // ecx
	int v6;              // esi
	int v7;              // eax
	int* v8;             // ecx
	int v9;              // edx
	int v10;             // eax
	unsigned __int8 v11; // al
	float v12;           // [esp+4h] [ebp-4h]

	v1 = 0.0;
	v12 = 0.0;
	if (!a1)
		return 0.0;
	v3 = (_DWORD*)a1[126];
	if (v3) {
		do {
			v4 = v3[4];
			if (v4 & 0x100 && v3[2] & 0x13001000) {
				v5 = (int*)v3[173];
				v6 = 4;
				do {
					v7 = *v5;
					if (*v5 && *(_DWORD * (__cdecl**)(int, int))(v7 + 112) == sub_4DFDE0)
						v1 = v1 + *(float*)(v7 + 120);
					++v5;
					--v6;
				} while (v6);
			}
			v3 = (_DWORD*)v3[124];
		} while (v3);
		v12 = v1;
	}
	if (a1[2] & 0x13001000) {
		v8 = (int*)a1[173];
		v9 = 4;
		do {
			v10 = *v8;
			if (*v8 && *(_DWORD * (__cdecl**)(int, int))(v10 + 112) == sub_4DFDE0)
				v1 = v1 + *(float*)(v10 + 120);
			++v8;
			--v9;
		} while (v9);
		v12 = v1;
	}
	if (v1 > 0.69999999)
		v12 = 0.69999999;
	if (sub_4FF350((int)a1, 18)) {
		v11 = sub_4FF570((int)a1, 18);
		result = sub_419D70(&byte_587000[200704], (unsigned int)v11 - 1) + v12;
	} else {
		result = v12;
	}
	if (result > 0.89999998)
		result = 0.89999998;
	return result;
}

//----- (004E0140) --------------------------------------------------------
_DWORD* __cdecl sub_4E0140(int a1, int a2) {
	*(_BYTE*)(a2 + 440) |= 0x20u;
	return sub_501960(123, a2, 0, 0);
}

//----- (004E0170) --------------------------------------------------------
void __cdecl sub_4E0170(int a1, int a2) {
	if (a2 && *(_BYTE*)(a2 + 8) & 4) {
		if (!sub_4DFBB0(a2, 32))
			*(_BYTE*)(a2 + 440) &= 0xDFu;
		sub_501960(124, a2, 0, 0);
	}
}

//----- (004E01B0) --------------------------------------------------------
void sub_4E01B0() { nox_srand(0x2275u); }

//----- (004E01C0) --------------------------------------------------------
void sub_4E01C0() { nox_srand(0x227Eu); }

//----- (004E01D0) --------------------------------------------------------
void __cdecl sub_4E01D0(int a1, int a2) {
	_DWORD* v2;          // esi
	unsigned __int16 v3; // di
	unsigned int v4;     // edi
	int v5;              // eax

	if (a2) {
		v2 = *(_DWORD**)(a2 + 492);
		if (v2) {
			if (v2[139]) {
				if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - v2[134]) >=
					*(int*)&byte_5D4594[2649704] &&
				    !(v2[4] & 0x8020)) {
					v3 = sub_4EE7A0(*(_DWORD*)(a2 + 492));
					if ((unsigned __int16)sub_4EE780((int)v2) < v3) {
						v4 = *(_DWORD*)(a1 + 108);
						if (*(_DWORD*)(a2 + 8) & 0x2000000) {
							v5 = sub_415C70(a2);
							if (v5 & 0x4000)
								v4 /= 3u;
						}
						if (!(*(_DWORD*)&byte_5D4594[2598000] %
						      (v4 * *(_DWORD*)&byte_5D4594[2649704] /
						       (unsigned __int16)sub_4EE7A0((int)v2))))
							sub_4EE460((int)v2, 1);
					}
				}
			}
		}
	}
}

//----- (004E02C0) --------------------------------------------------------
void __cdecl sub_4E02C0(int a1, _DWORD* a2) {
	int v2;             // eax
	int v3;             // ecx
	unsigned __int8 v4; // dl
	unsigned __int8 v5; // al
	int v6;             // esi
	int v7;             // edx
	int v8;             // ecx

	if (a2) {
		if (!(*(_DWORD*)&byte_5D4594[2598000] % *(_DWORD*)(a1 + 108))) {
			v2 = a2[2];
			v3 = a2[184];
			if (v2 & 0x1000) {
				v4 = *(_BYTE*)(v3 + 108);
				v5 = *(_BYTE*)(v3 + 109);
				v6 = v4++;
				*(_BYTE*)(v3 + 108) = v4;
				if (v4 > v5)
					*(_BYTE*)(v3 + 108) = v5;
				v7 = *(unsigned __int8*)(v3 + 108);
				if (v6 != v7) {
					v8 = a2[123];
					if (v8) {
						if (*(_BYTE*)(v8 + 8) & 4)
							sub_4D82B0(
							    *(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(v8 + 748) + 276) +
										2064),
							    a2, v7, v5);
					}
				}
			}
		}
	}
}

//----- (004E0350) --------------------------------------------------------
void sub_4E0350() { nox_srand(0x227Fu); }

//----- (004E0360) --------------------------------------------------------
void sub_4E0360() { nox_srand(0x2260u); }

//----- (004E0370) --------------------------------------------------------
float* __cdecl sub_4E0370(int a1, int a2, int a3, int a4, int a5, float* a6) {
	float* result; // eax

	result = a6;
	*a6 = *(float*)(a1 + 80) * *a6;
	return result;
}

//----- (004E0380) --------------------------------------------------------
float* __cdecl sub_4E0380(int a1, int a2, int a3, int a4, int a5, float* a6) {
	float* result; // eax

	result = a6;
	*a6 = (1.0 - *(float*)(a1 + 80) + 1.0) * *a6;
	return result;
}

//----- (004E03D0) --------------------------------------------------------
BOOL __cdecl sub_4E03D0(int a1, int a2, int a3, int a4, int a5, BOOL* a6) {
	BOOL result; // eax

	result = *(_DWORD*)(a1 + 96) >= 1;
	*a6 = result;
	return result;
}

//----- (004E03F0) --------------------------------------------------------
int __cdecl sub_4E03F0(int a1, int a2, int a3, int a4) {
	int v4;                                             // esi
	int v5;                                             // edi
	_DWORD* v6;                                         // eax
	int v7;                                             // eax
	BOOL(__cdecl * v8)(int, int, int, int, int, BOOL*); // ecx
	bool v9;                                            // cc
	_DWORD* i;                                          // [esp+10h] [ebp-4h]
	int v12;                                            // [esp+20h] [ebp+Ch]

	v4 = a3;
	if (!a3 || !(*(_DWORD*)(a3 + 8) & 0x3001000))
		return 0;
	v5 = a4;
	v6 = (_DWORD*)(*(_DWORD*)(a3 + 692) + 8);
	v12 = 2;
	for (i = v6;; ++i) {
		v7 = *v6;
		if (v7) {
			v8 = *(BOOL(__cdecl**)(int, int, int, int, int, BOOL*))(v7 + 88);
			if (v8 == sub_4E0480) {
				v8(v7, v4, a2, v5, a1, &a4);
				if (!a4)
					break;
			}
		}
		v6 = i + 1;
		v9 = ++v12 < 4;
		if (!v9)
			return 0;
	}
	return 1;
}

//----- (004E0480) --------------------------------------------------------
BOOL __cdecl sub_4E0480(int a1, int a2, int a3, int a4, int a5, BOOL* a6) {
	BOOL result; // eax

	result = *(_DWORD*)(a1 + 96) < 1;
	*a6 = result;
	return result;
}

//----- (004E04A0) --------------------------------------------------------
void sub_4E04A0() { nox_srand(0x2261u); }

//----- (004E04B0) --------------------------------------------------------
void sub_4E04B0() { nox_srand(0x226Au); }

//----- (004E04C0) --------------------------------------------------------
float* __cdecl sub_4E04C0(int a1, int a2, int a3, int a4, float* a5) {
	float* result; // eax

	result = a5;
	*a5 = *(float*)(a1 + 44) * *a5;
	return result;
}

//----- (004E04D0) --------------------------------------------------------
void __cdecl sub_4E04D0(int a1, int a2, int a3, int a4) {
	int v4;    // esi
	int v5;    // ecx
	int v6;    // eax
	int v8;    // eax
	int v9[3]; // [esp+4h] [ebp-Ch]

	v4 = a4;
	if (*(_BYTE*)(a4 + 8) & 6) {
		v5 = *(_DWORD*)(a4 + 60);
		v9[1] = *(_DWORD*)(a4 + 56);
		v6 = *(_DWORD*)(a1 + 60);
		v9[2] = v5;
		v9[0] = a4;
		sub_52C2C0(74, a3, a3, a3, v9, v6);
		if (*(_BYTE*)(v4 + 8) & 4) {
			v8 = *(_DWORD*)(v4 + 748);
			a4 = 0;
			sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), 13, &a4);
		}
	}
}

//----- (004E0550) --------------------------------------------------------
_DWORD* __cdecl sub_4E0550(int a1, int a2, int a3, int a4) {
	_DWORD* result; // eax
	float v5;       // [esp+8h] [ebp+4h]

	result = (_DWORD*)a1;
	v5 = *(float*)(a1 + 56);
	if (a4) {
		(*(void(__cdecl**)(int, int, int, _DWORD, int))(a4 + 716))(a4, a3, a2, (__int64)v5, 7);
		sub_5231B0((float*)(a4 + 56), (__int64)(v5 * 10.0));
		result = sub_501960(224, a4, 0, 0);
	}
	return result;
}

//----- (004E05B0) --------------------------------------------------------
int __cdecl sub_4E05B0(int a1, int a2, int a3) {
	int result; // eax
	int v4;     // edx
	int v5[3];  // [esp+0h] [ebp-Ch]

	result = a3;
	if (a3) {
		v4 = *(_DWORD*)(a3 + 60);
		v5[1] = *(_DWORD*)(a3 + 56);
		v5[2] = v4;
		v5[0] = 0;
		result = sub_52D5C0(10, a3, a3, a3, (int)v5, *(_DWORD*)(a1 + 48));
	}
	return result;
}

//----- (004E05F0) --------------------------------------------------------
int __cdecl sub_4E05F0(int a1, int a2, int a3) {
	int result; // eax
	int v4;     // edx
	int v5[3];  // [esp+0h] [ebp-Ch]

	result = a3;
	if (a3) {
		v4 = *(_DWORD*)(a3 + 60);
		v5[1] = *(_DWORD*)(a3 + 56);
		v5[2] = v4;
		v5[0] = 0;
		result = sub_52D5C0(11, a3, a3, a3, (int)v5, *(_DWORD*)(a1 + 48));
	}
	return result;
}

//----- (004E0640) --------------------------------------------------------
void __cdecl sub_4E0640(int a1, int a2, int a3, int a4) {
	if (a2) {
		if (a4)
			sub_52DF80(a2 + 56, a4, *(float*)(a1 + 56));
	}
}

//----- (004E0670) --------------------------------------------------------
void __cdecl sub_4E0670(int a1, int a2, int a3, int a4) {
	int v4;    // esi
	int v5;    // ecx
	int v6;    // eax
	int v8;    // eax
	int v9[3]; // [esp+4h] [ebp-Ch]

	v4 = a4;
	if (*(_BYTE*)(a4 + 8) & 6) {
		v5 = *(_DWORD*)(a4 + 60);
		v9[1] = *(_DWORD*)(a4 + 56);
		v6 = *(_DWORD*)(a1 + 60);
		v9[2] = v5;
		v9[0] = a4;
		sub_52C1E0(12, a3, a3, a3, v9, v6);
		if (*(_BYTE*)(v4 + 8) & 4) {
			v8 = *(_DWORD*)(v4 + 748);
			a4 = 1;
			sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), 13, &a4);
		}
	}
}

//----- (004E06F0) --------------------------------------------------------
void __cdecl sub_4E06F0(int a1, int a2, int a3, int a4) {
	if (a4) {
		(*(void(__cdecl**)(int, int, int, _DWORD, int))(a4 + 716))(a4, a3, a2, (__int64)*(float*)(a1 + 56), 9);
		sub_522FF0(129, (float2*)(a4 + 56));
		sub_501960(225, a4, 0, 0);
	}
}

//----- (004E0740) --------------------------------------------------------
void __cdecl sub_4E0740(int a1, int a2, int a3, int a4, int* a5) {
	int v5;              // edi
	unsigned __int16 v6; // ax
	__int16 v7;          // si

	if (a3 && a4 && *(_BYTE*)(a4 + 8) & 6) {
		v5 = (__int64)(*(float*)(a1 + 68) * (double)*a5);
		if (!v5)
			v5 = 1;
		v6 = sub_4EEC80(a4);
		v7 = v6;
		if (v6 < v5) {
			sub_4EEBF0(a4, v6);
			sub_4EEB80(a3, v7);
		} else {
			sub_4EEBF0(a4, v5);
			sub_4EEB80(a3, v5);
		}
	}
}

//----- (004E07C0) --------------------------------------------------------
void __cdecl sub_4E07C0(int a1, int a2, int a3, int a4, int* a5) {
	int v5; // eax
	int v6; // esi
	int v7; // eax

	if (a3) {
		if (a4) {
			v5 = *(_DWORD*)(a4 + 8);
			if (v5 & 6) {
				if (!(v5 & 2) || !(*(_BYTE*)(a4 + 12) & 0x40)) {
					v6 = (__int64)((double)*a5 * *(float*)(a1 + 68));
					if (!v6)
						v6 = 1;
					v7 = (unsigned __int16)sub_4EE780(a4);
					if (v7 < v6)
						sub_4EE460(a3, v7);
					else
						sub_4EE460(a3, v6);
				}
			}
		}
	}
}

//----- (004E0850) --------------------------------------------------------
void __cdecl sub_4E0850(int a1, int a2, int a3, int a4) {
	int v4; // esi
	int v5; // eax

	v4 = a4;
	if ((!(*(_BYTE*)(a4 + 8) & 4) || *(_BYTE*)(*(_DWORD*)(a4 + 748) + 88) != 16 ||
	     !(nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a4 + 56), *(__int16*)(a4 + 124),
							   (float2*)(a3 + 56)) &
	       1)) &&
	    *(_BYTE*)(v4 + 8) & 6 && sub_4EE7E0(v4, 1, *(_DWORD*)(a1 + 72))) {
		if (*(_BYTE*)(v4 + 8) & 4) {
			v5 = *(_DWORD*)(v4 + 748);
			a4 = 2;
			sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), 13, &a4);
		}
	}
}

//----- (004E08E0) --------------------------------------------------------
void __cdecl sub_4E08E0(int a1, int a2, int a3, int a4, int* a5) {
	int v5;    // edi
	int v6;    // esi
	int v7;    // eax
	int v8;    // [esp-8h] [ebp-Ch]
	int v9;    // [esp+10h] [ebp+Ch]
	float v10; // [esp+14h] [ebp+10h]

	v5 = a3;
	if (a3 && a4 && *(_BYTE*)(a4 + 8) & 6) {
		v8 = a4;
		v10 = *(float*)(a1 + 68);
		v6 = *a5;
		v9 = *a5;
		v7 = (unsigned __int16)sub_4EE780(v8);
		if (v7 < v6)
			v9 = v7;
		sub_4EE5E0(v5, (__int64)((double)v9 * v10));
	}
}

//----- (004E0960) --------------------------------------------------------
int __cdecl sub_4E0960(int a1) {
	int v1; // esi
	int v2; // edx
	int i;  // ecx

	v1 = *(_DWORD*)(a1 + 692);
	if (!a1 || !(*(_DWORD*)(a1 + 8) & 0x13001000))
		return 0;
	v2 = 2;
	for (i = v1 + 8; !*(_DWORD*)i || *(int (**)())(*(_DWORD*)i + 40) != nullsub_22; i += 4) {
		if (++v2 >= 4)
			return 0;
	}
	return *(_DWORD*)(*(_DWORD*)(v1 + 4 * v2) + 48);
}
// 4E0950: using guessed type void nullsub_22();

//----- (004E09B0) --------------------------------------------------------
int __cdecl sub_4E09B0(int a1, int a2, int a3, int a4, int a5) {
	int result; // eax

	result = a5;
	*(float*)(a5 + 544) = *(float*)(a1 + 44) * *(float*)(a5 + 544);
	return result;
}

//----- (004E09E0) --------------------------------------------------------
void sub_4E09E0() { nox_srand(0x226Bu); }

//----- (004E09F0) --------------------------------------------------------
void sub_4E09F0() { nox_srand(0x7DCu); }

//----- (004E0A00) --------------------------------------------------------
int __cdecl sub_4E0A00(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)&byte_587000[200728];
	do {
		if (!strcmp(a1, *v2))
			break;
		++v2;
		++v1;
	} while ((int)v2 < (int)&byte_587000[200800]);
	return v1;
}

//----- (004E0A70) --------------------------------------------------------
int __cdecl sub_4E0A70(int a1, int a2) {
	int result; // eax
	double v3;  // st7
	double v4;  // st6
	__int16 v5; // cx
	double v6;  // st5
	double v7;  // st6
	int v8;     // edx
	float v9;   // [esp+0h] [ebp-10h]
	float v10;  // [esp+4h] [ebp-Ch]
	float v11;  // [esp+8h] [ebp-8h]
	float v12;  // [esp+8h] [ebp-8h]
	float v13;  // [esp+14h] [ebp+4h]

	result = a1;
	v3 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
	v4 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
	*(_WORD*)(a1 + 124) += 128;
	v5 = *(_WORD*)(a1 + 124);
	v11 = -v4;
	v13 = sqrt(v4 * v4 + v3 * v3) + 0.1;
	v6 = (v4 * *(float*)(result + 84) + v3 * *(float*)(result + 80)) / v13;
	v9 = v6 * v3 / v13;
	v10 = v6 * v4 / v13;
	v7 = (v11 * *(float*)(result + 80) + v3 * *(float*)(result + 84)) / v13;
	v12 = v7 * v11 / v13;
	*(float*)(result + 80) = v12 - v9;
	*(float*)(result + 84) = v3 * v7 / v13 - v10;
	if (v5 >= 256)
		*(_WORD*)(result + 124) = v5 - 256;
	v8 = *(_DWORD*)(result + 76);
	*(_DWORD*)(result + 64) = *(_DWORD*)(result + 72);
	*(_DWORD*)(result + 68) = v8;
	return result;
}

//----- (004E0B30) --------------------------------------------------------
int __cdecl sub_4E0B30(int a1, int a2, int a3, int a4, int a5) {
	int v6;                        // edi
	int v7;                        // eax
	int v8;                        // eax
	int v9;                        // eax
	int v10;                       // edi
	int v11;                       // eax
	int v12;                       // ebp
	int v13;                       // eax
	int v14;                       // eax
	int v15;                       // ebp
	double v16;                    // st7
	double v17;                    // st7
	int v18;                       // eax
	int v19;                       // ebx
	int v20;                       // eax
	int v21;                       // edx
	int v22;                       // eax
	char v23;                      // al
	_DWORD* v24;                   // eax
	int v25;                       // edx
	int v26;                       // ecx
	int v27;                       // eax
	int v28;                       // eax
	void(__cdecl * v29)(int, int); // eax
	unsigned __int8 v30;           // al
	double v31;                    // st7
	unsigned __int16 v32;          // bp
	int v33;                       // eax
	float v34;                     // ecx
	int v35;                       // eax
	float v36;                     // edx
	char v37;                      // al
	int v38;                       // ebp
	int v39;                       // eax
	int v40;                       // eax
	float v41;                     // [esp+0h] [ebp-28h]
	float v42;                     // [esp+4h] [ebp-24h]
	float v43;                     // [esp+4h] [ebp-24h]
	float v44;                     // [esp+4h] [ebp-24h]
	int v45[4];                    // [esp+18h] [ebp-10h]
	float v46;                     // [esp+30h] [ebp+8h]
	float v47;                     // [esp+30h] [ebp+8h]

	if (!a1)
		return 1;
	if (sub_4FF350(a1, 23)) {
		if (!(byte_5D4594[2598000] & 3)) {
			sub_501960(71, a1, 0, 0);
			return 1;
		}
		return 1;
	}
	v6 = a5;
	if (*(_BYTE*)(a1 + 8) & 2) {
		v7 = *(_DWORD*)(a1 + 748);
		*(_DWORD*)(v7 + 2188) = 0;
		if (v6 == 1 || v6 == 12 || v6 == 7 || v6 == 14 || v6 == 6)
			*(_DWORD*)(v7 + 1440) |= 0x80000u;
	}
	v8 = *(_DWORD*)(a1 + 16);
	if ((v8 & 0x8000) == 0) {
		v10 = a2;
		if (!sub_417DA0(1)) {
			v11 = sub_4EC580(a2);
			v12 = v11;
			if (v11) {
				if (*(_BYTE*)(v11 + 8) & 6 && !sub_5330C0(a1, v11) &&
				    (a1 != v12 || nox_common_gameFlags_check_40A5C0(4096)))
					return 1;
			}
		}
		if (a2 && a3 && !sub_5330C0(a1, a2) && *(_BYTE*)(a1 + 8) & 6 && sub_4E1400(a2, (_DWORD*)a3) &&
			!sub_4E1470(a3) ||
		    *(_BYTE*)(a1 + 16) & 2) {
			return 1;
		}
		if (a2) {
			if (sub_4FF350(a1, 22)) {
				if (*(_BYTE*)(a2 + 8) & 6) {
					if (a3) {
						if (sub_4E1400(a2, (_DWORD*)a3)) {
							sub_501960(135, a2, 0, 0);
							sub_4FF5B0(a1, 22);
							v41 = sub_419D70(&byte_587000[201116], 4);
							v13 = nox_float2int(v41);
							(*(void(__cdecl**)(int, int, _DWORD, int, int))(a2 + 716))(
							    a2, a1, 0, v13, 9);
							if (*(_BYTE*)(a2 + 8) & 4)
								sub_4FA020((_DWORD*)a2, 23);
						}
					}
				}
			}
		}
		if (*(_BYTE*)(a1 + 8) & 2) {
			v14 = *(_DWORD*)(a1 + 12);
			v15 = a5;
			if (v14 & 0x200 && a5 == 5)
				return 1;
			if (v14 & 0x400) {
				if (a5 == 1 || a5 == 12)
					return 1;
				if (a5 == 7) {
					a4 /= 2;
				LABEL_53:
					v16 = sub_4DFE40((_DWORD*)a1);
					if (v16 != 0.0 && !(byte_5D4594[2598000] & 3))
						sub_501960(104, a1, 0, 0);
					v46 = v16;
					v42 = (1.0 - v46) * (double)a4;
					a4 = nox_float2int(v42);
					if (!a4)
						a4 = 1;
				LABEL_58:
					if (v15 == 9 || v15 == 17) {
						v17 = sub_4DFF40((_DWORD*)a1);
						if (v17 != 0.0 && !(byte_5D4594[2598000] & 3))
							sub_501960(108, a1, 0, 0);
						v47 = v17;
						v43 = (1.0 - v47) * (double)a4;
						a4 = nox_float2int(v43);
						if (!a4)
							a4 = 1;
						v18 = *(_DWORD*)(a1 + 8);
						if (v18 & 4) {
							*(_WORD*)(*(_DWORD*)(a1 + 748) + 160) = 2;
						} else if (v18 & 2 && *(_BYTE*)(a1 + 12) & 0x10) {
							*(_BYTE*)(*(_DWORD*)(a1 + 748) + 2094) = 2;
						}
					}
					if (!v10) {
						*(_DWORD*)(a1 + 528) = 0;
						*(_DWORD*)(a1 + 532) = 0;
						if (v15 == 12)
							sub_4FF5B0(a1, 0);
						v19 = a3;
					LABEL_87:
						v22 = *(_DWORD*)(a1 + 8);
						if (v22 & 4 || v22 & 2 && *(_BYTE*)(a1 + 12) & 0x10)
							sub_4E1320(a1, v10, v19, &a4, v15);
						if (v19)
							*(_DWORD*)(a1 + 520) = v19;
						else
							*(_DWORD*)(a1 + 520) = v10;
						v23 = *(_BYTE*)(a1 + 8);
						*(_DWORD*)(a1 + 524) = v15;
						*(_DWORD*)(a1 + 536) = *(_DWORD*)&byte_5D4594[2598000];
						if (v23 & 2) {
							v24 = *(_DWORD**)(a1 + 748);
							v25 = v24[360];
							v26 = v24[547];
							BYTE1(v25) |= 2u;
							v24[360] = v25;
							if (!v26) {
								v24[547] = 2;
								v24[546] = v15;
							}
						}
						if (v19 && *(_DWORD*)(v19 + 8) & 0x1001000)
							sub_4E13B0(a1, v10, v19, (int)&a4);
						if (a1 != v19 || !(*(_DWORD*)(a1 + 8) & 0x1001000)) {
							if (!v10 || !(*(_BYTE*)(v10 + 8) & 2) ||
							    !*(_DWORD*)(v10 + 748) || (v27 = sub_424300(v10)) == 0 ||
							    (v28 = *(_DWORD*)(v27 + 32)) == 0 || sub_501940(v28) <= 0) {
								v29 = *(void(__cdecl**)(int, int))(a1 + 720);
								if (v29) {
									if (v19)
										v29(a1, v19);
									else
										v29(a1, v10);
								} else if (v19) {
									sub_532E20(a1, v19);
								} else {
									sub_532E20(a1, v10);
								}
							}
						}
						if (v10 && *(_BYTE*)(a1 + 8) & 6 && sub_4FF350(v10, 13)) {
							sub_501960(163, a3, 0, 0);
							v30 = sub_4FF570(v10, 13);
							v31 = sub_419D70(&byte_587000[201128], (unsigned int)v30 - 1);
							v44 = v31 * (double)a4;
							v32 = nox_float2int(v44);
							if (v32 < 1u)
								v32 = 1;
							sub_4EE460(v10, v32);
							v45[0] = nox_float2int(*(float*)(v10 + 56));
							v33 = nox_float2int(*(float*)(v10 + 60));
							v34 = *(float*)(a1 + 56);
							v45[1] = v33;
							v35 = nox_float2int(v34);
							v36 = *(float*)(a1 + 60);
							v45[2] = v35;
							v45[3] = nox_float2int(v36);
							sub_523270(162, (__int16*)v45, v32);
						}
						sub_4E1230(v10, a1, a4);
						if (*(_BYTE*)(a1 + 8) & 4) {
							if (a4 >= 20) {
								v37 = *(_BYTE*)(*(_DWORD*)(a1 + 748) + 88);
								if (v37 != 1 && v37 != 15)
									sub_4FA020((_DWORD*)a1, 30);
							}
						}
						if (nox_common_gameFlags_check_40A5C0(6144))
							sub_4FB050(v10, a1, &a4);
						if (!v10)
							goto LABEL_137;
						if (*(_BYTE*)(v10 + 8) & 2) {
							v38 = v10;
						} else {
							v39 = *(_DWORD*)(v10 + 508);
							if (!v39 || !(*(_BYTE*)(v39 + 8) & 2)) {
							LABEL_137:
								if (sub_4FF350(a1, 26) && a5 != 5) {
									v40 = a3;
									if (!a3)
										v40 = v10;
									if (a5 != 15 || v10 != a1)
										sub_52F710(a1, &a4, a5, v40);
									if (!a4)
										return 0;
								}
								sub_4EE5E0(a1, a4);
								return 1;
							}
							v38 = *(_DWORD*)(v10 + 508);
						}
						if (v38 && sub_5330C0(a1, v38))
							sub_532880(v38);
						goto LABEL_137;
					}
					v19 = a3;
					if (a3) {
						if (*(_DWORD*)(a3 + 8) & 0x1001000) {
							*(_DWORD*)(a1 + 528) = *(_DWORD*)(v10 + 72);
							*(_DWORD*)(a1 + 532) = *(_DWORD*)(v10 + 76);
						} else {
							*(_DWORD*)(a1 + 528) = *(_DWORD*)(a3 + 72);
							*(_DWORD*)(a1 + 532) = *(_DWORD*)(a3 + 76);
						}
						if (a3 == v10 || !(*(_BYTE*)(a1 + 8) & 2))
							goto LABEL_83;
						v20 = *(_DWORD*)(a1 + 748);
						HIWORD(v21) = 0;
						*(_DWORD*)(v20 + 2188) = 1;
						LOWORD(v21) = *(_WORD*)(a3 + 4);
					} else {
						*(_DWORD*)(a1 + 528) = *(_DWORD*)(v10 + 72);
						*(_DWORD*)(a1 + 532) = *(_DWORD*)(v10 + 76);
						if (v15 != 10 && v15 != 2 || !(*(_BYTE*)(a1 + 8) & 2))
							goto LABEL_83;
						v20 = *(_DWORD*)(a1 + 748);
						HIWORD(v21) = 0;
						*(_DWORD*)(v20 + 2188) = 1;
						LOWORD(v21) = *(_WORD*)(v10 + 4);
					}
					*(_DWORD*)(v20 + 2184) = v21;
				LABEL_83:
					sub_4FF5B0(a1, 0);
					goto LABEL_87;
				}
			} else if (v14 & 0x800) {
				if (a5 == 9)
					return 1;
				if (a5 == 17)
					return 1;
			}
		} else {
			v15 = a5;
		}
		if (v15 != 1 && v15 != 12 && v15 != 7)
			goto LABEL_58;
		goto LABEL_53;
	}
	if (!sub_534A40(a1))
		return 1;
	v9 = a3;
	if (!a3)
		v9 = a2;
	*(_DWORD*)(a1 + 520) = v9;
	*(_DWORD*)(a1 + 524) = v6;
	*(_DWORD*)(a1 + 536) = *(_DWORD*)&byte_5D4594[2598000];
	return 1;
}

//----- (004E1230) --------------------------------------------------------
void __cdecl sub_4E1230(int a1, int a2, int a3) {
	int v3;   // eax
	int v4;   // esi
	char* v5; // eax

	if (*(_BYTE*)(a2 + 8) & 4 && a3 >= 30) {
		v3 = *(_DWORD*)&byte_5D4594[1563316];
		if (!*(_DWORD*)&byte_5D4594[1563316]) {
			v3 = sub_4E3AA0((CHAR*)&byte_587000[201144]);
			*(_DWORD*)&byte_5D4594[1563316] = v3;
		}
		v4 = *(_DWORD*)(a2 + 516);
		if (v4) {
			while (*(unsigned __int16*)(v4 + 4) != v3) {
				v4 = *(_DWORD*)(v4 + 512);
				if (!v4)
					return;
			}
			*(_DWORD*)(v4 + 16) &= 0xFFFFFFBF;
			sub_52DF80(a2 + 56, v4, 30.0);
			sub_4EC300(v4);
			sub_4EB9B0(v4, a2);
			if (sub_419130(v4 + 48)) {
				v5 = sub_418AB0(*(unsigned __int8*)(a1 + 52));
				if (v5)
					sub_4196D0(v4 + 48, (int)v5, *(_DWORD*)(v4 + 36), 0);
			} else {
				sub_4191D0(*(_BYTE*)(a1 + 52), v4 + 48, 1, *(_DWORD*)(v4 + 36), 0);
			}
			sub_501960(926, a2, 0, 0);
		}
	}
}

//----- (004E1320) --------------------------------------------------------
int __cdecl sub_4E1320(int a1, int a2, int a3, int* a4, int a5) {
	int result; // eax
	_DWORD* v6; // esi
	int v7;     // ebp
	int* v8;    // ebx
	int v9;     // eax
	int2 v10;   // [esp+4h] [ebp-8h]
	int v11;    // [esp+20h] [ebp+14h]

	result = a1;
	v6 = *(_DWORD**)(a1 + 504);
	if (v6) {
		v7 = a5;
		do {
			result = v6[4];
			if (result & 0x100) {
				v11 = 2;
				v8 = (int*)(v6[173] + 8);
				do {
					v9 = *v8;
					if (*v8) {
						if (*(_DWORD*)(v9 + 76)) {
							v10.field_0 = *a4;
							v10.field_4 = v7;
							(*(void(__cdecl**)(int, _DWORD*, int, int, int, int2*))(
							    v9 + 76))(v9, v6, a1, a3, a2, &v10);
							*a4 = v10.field_0;
						}
					}
					++v8;
					result = --v11;
				} while (v11);
			}
			v6 = (_DWORD*)v6[124];
		} while (v6);
	}
	return result;
}

//----- (004E13B0) --------------------------------------------------------
int __cdecl sub_4E13B0(int a1, int a2, int a3, int a4) {
	int v4;                                      // edi
	int* v5;                                     // esi
	int v6;                                      // eax
	void(__cdecl * v7)(int, int, int, int, int); // ecx
	int result;                                  // eax
	int v9;                                      // [esp+1Ch] [ebp+Ch]

	v4 = a3;
	v9 = 4;
	v5 = *(int**)(v4 + 692);
	do {
		v6 = *v5;
		if (*v5) {
			v7 = *(void(__cdecl**)(int, int, int, int, int))(v6 + 64);
			if (v7)
				v7(v6, v4, a2, a1, a4);
		}
		++v5;
		result = --v9;
	} while (v9);
	return result;
}

//----- (004E1400) --------------------------------------------------------
int __cdecl sub_4E1400(int a1, _DWORD* a2) {
	int v2;     // eax
	int result; // eax
	int v4;     // eax

	if (a2) {
		v4 = a2[2];
		if (v4 & 0x1000) {
			if (!(a2[3] & 0x47F0000))
				return 1;
			if (*(_BYTE*)(a2[184] + 96) & 2)
				return 1;
		} else if (v4 & 0x1000000 && !(a2[3] & 0x47F00FE)) {
			return 1;
		}
		result = ((unsigned __int8)v4 >> 1) & 1;
	} else {
		v2 = *(_DWORD*)(a1 + 8);
		if (v2 & 4)
			return 1;
		result = v2 & 2 && *(_BYTE*)(a1 + 12) & 0x10;
	}
	return result;
}

//----- (004E1470) --------------------------------------------------------
BOOL __cdecl sub_4E1470(int a1) {
	int v1;      // ecx
	BOOL result; // eax

	result = 0;
	if (a1) {
		if (*(_DWORD*)(a1 + 8) & 0x1000000) {
			v1 = *(_DWORD*)(a1 + 12);
			if (v1 & 0x4000)
				result = 1;
		}
	}
	return result;
}

//----- (004E14A0) --------------------------------------------------------
int sub_4E14A0() { return 0; }

//----- (004E14B0) --------------------------------------------------------
int __cdecl sub_4E14B0(int a1, int a2, int a3, int a4, int a5) {
	int result; // eax

	if (a1 && *(_DWORD*)(a1 + 8) & 0x1001000 && (*(_DWORD*)(a1 + 492) || a5 == 12))
		result = sub_4E0B30(a1, a2, a3, a4, a5);
	else
		result = 0;
	return result;
}

//----- (004E1500) --------------------------------------------------------
int __cdecl sub_4E1500(int a1, int a2, int a3, int a4, int a5) {
	int v5;     // eax
	int result; // eax

	if (*(_DWORD*)(a1 + 8) & 0x2000000 && (*(_DWORD*)(a1 + 492) || a5 == 12) &&
	    (a5 != 2 || !(*(_BYTE*)(a1 + 24) & 0x10) ? (v5 = a4) : (v5 = 2 * a4), v5)) {
		result = sub_4E0B30(a1, a2, a3, v5, a5);
	} else {
		result = 0;
	}
	return result;
}

//----- (004E1560) --------------------------------------------------------
void __cdecl sub_4E1560(int a1, int a2, int a3, int a4, float a5, int a6) {
	float* v6;                                           // edi
	int v7;                                              // eax
	void(__cdecl * v8)(int, int, int, int, int, float*); // ecx
	int v9;                                              // eax
	unsigned __int16 v10;                                // di
	unsigned __int16 v11;                                // ax

	if (a1) {
		if (*(_DWORD*)(a1 + 556)) {
			v6 = *(float**)(a1 + 748);
			if (!(*(_DWORD*)(a1 + 8) & 0x1000000) || !(*(_DWORD*)(a1 + 12) & 0x7800000)) {
				v7 = *(_DWORD*)(*(_DWORD*)(a1 + 692) + 4);
				if (v7) {
					v8 = *(void(__cdecl**)(int, int, int, int, int, float*))(v7 + 76);
					if (v8)
						v8(v7, a1, a2, a4, a3, &a5);
				}
				a5 = a5 + *v6;
				v9 = nox_float2int(a5);
				*v6 = a5 - (double)v9;
				if (v9 > 0) {
					v10 = **(_WORD**)(a1 + 556);
					(*(void(__cdecl**)(int, int, int, int, int))(a1 + 716))(a1, a3, a4, v9, a6);
					if (a2) {
						if (*(_BYTE*)(a2 + 8) & 4) {
							v11 = **(_WORD**)(a1 + 556);
							if (v10 != v11)
								sub_4E1650(
								    *(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a2 +
													      748) +
												   276) +
											2064),
								    (_DWORD*)a1, v10, v11);
						}
					}
				}
			}
		}
	}
}

//----- (004E1650) --------------------------------------------------------
int __cdecl sub_4E1650(int a1, _DWORD* a2, unsigned __int16 a3, unsigned __int16 a4) {
	int result; // eax
	int v5;     // edi

	result = a2[139];
	if (result) {
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			result = sub_4D87A0(a1, a2);
		} else {
			v5 = sub_57B190(a3, *(_WORD*)(a2[139] + 4));
			result = sub_57B190(a4, *(_WORD*)(a2[139] + 4));
			if (v5 != result)
				result = sub_4D87A0(a1, a2);
		}
	}
	return result;
}

//----- (004E16D0) --------------------------------------------------------
void __cdecl sub_4E16D0(int a1, int a2, int a3, int a4, float a5, int a6) {
	float* v6;                                           // edi
	int v7;                                              // eax
	void(__cdecl * v8)(int, int, int, int, int, float*); // ecx
	int v9;                                              // eax
	unsigned __int16 v10;                                // di
	unsigned __int16 v11;                                // ax

	if (a1 && *(_DWORD*)(a1 + 556)) {
		v6 = *(float**)(a1 + 748);
		v7 = *(_DWORD*)(*(_DWORD*)(a1 + 692) + 4);
		if (v7) {
			v8 = *(void(__cdecl**)(int, int, int, int, int, float*))(v7 + 76);
			if (v8)
				v8(v7, a1, a2, a4, a3, &a5);
		}
		a5 = a5 + *v6;
		v9 = nox_float2int(a5);
		*v6 = a5 - (double)v9;
		if (v9 > 0) {
			v10 = **(_WORD**)(a1 + 556);
			(*(void(__cdecl**)(int, int, int, int, int))(a1 + 716))(a1, a3, a4, v9, a6);
			if (*(_BYTE*)(a2 + 8) & 4) {
				v11 = **(_WORD**)(a1 + 556);
				if (v10 != v11)
					sub_4E1650(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) + 2064),
						   (_DWORD*)a1, v10, v11);
			}
		}
	}
}
