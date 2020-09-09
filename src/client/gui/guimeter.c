#include "guimeter.h"

#include "../../proto.h"
#include "gamewin/gamewin.h"
#include "tooltip.h"

extern _DWORD dword_5d4594_1090828;
extern _DWORD dword_5d4594_1096272;
extern _DWORD dword_5d4594_1090292;
extern _DWORD dword_5d4594_1091364;
extern _DWORD dword_5d4594_1096276;
extern _DWORD dword_5d4594_1096264;
extern _DWORD dword_5d4594_1096256;
extern _DWORD dword_5d4594_1096280;
extern _DWORD dword_5d4594_1096260;
extern _DWORD dword_5d4594_1096284;
extern _DWORD dword_5d4594_1096288;
extern _DWORD dword_5d4594_1093156;
extern _DWORD dword_5d4594_1096252;
extern _DWORD dword_5d4594_1093136;
extern _DWORD dword_5d4594_3799468;
extern _DWORD nox_client_renderBubbles_80844;
extern _DWORD dword_5d4594_1090276;
extern int nox_win_width;
extern int nox_win_height;

//----- (004710B0) --------------------------------------------------------
int sub_4710B0() {
	wchar_t* v0; // eax
	wchar_t* v1; // esi
	wchar_t* v2; // eax
	int v3;      // eax
	wchar_t* v4; // esi
	wchar_t* v5; // eax
	int result;  // eax
	wchar_t* v7; // eax

	v0 = (wchar_t*)sub_4615C0();
	v1 = v0;
	if (v0) {
		v2 = sub_4BF050(v0);
		nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1091968), v2);
		if (v1[58] & 0xC) {
			v3 = *getMemU32Ptr(0x5D4594, 1096292);
			if (!*getMemU32Ptr(0x5D4594, 1096292)) {
				v3 = sub_4E3AA0((CHAR*)getMemAt(0x587000, 148392));
				*getMemU32Ptr(0x5D4594, 1096292) = v3;
			}
			v4 = (wchar_t*)sub_461600(v3);
			if (v4) {
				nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1091968), L"\n");
				v5 = sub_4BF050(v4);
				nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1091968), v5);
			}
		}
		sub_4776B0((wchar_t*)getMemAt(0x5D4594, 1091968));
		result = 1;
	} else {
		v7 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 148444), 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 881);
		sub_4776B0(v7);
		result = 1;
	}
	return result;
}

//----- (00471160) --------------------------------------------------------
int __cdecl sub_471160(int a1, int a2, int a3, int a4, int a5) {
	wchar_t* v5; // eax
	wchar_t* v6; // eax
	int result;  // eax

	dword_5d4594_1093136 = nox_window_new(a1, 1032, a2, a3, a4, a5, 0);
	dword_5d4594_1093156 = nox_window_new(a1, 1032, a2 - 17, a3 - 15, 15, 15, 0);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1093136, 0, sub_471250, 0);
	v5 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 148504), 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 921);
	sub_46B000((wchar_t*)(dword_5d4594_1093136 + 36), v5);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1093156, 0, sub_471450, 0);
	v6 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 148560), 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 925);
	sub_46B000((wchar_t*)(dword_5d4594_1093156 + 36), v6);
	result = dword_5d4594_1093136;
	*(_DWORD*)(dword_5d4594_1093136 + 32) = 5;
	*(_DWORD*)(dword_5d4594_1093156 + 32) = 6;
	return result;
}

//----- (004714E0) --------------------------------------------------------
int sub_4714E0() {
	int v1;              // edi
	unsigned __int8* v2; // esi
	wchar_t* v3;         // eax
	wchar_t* v5;         // eax
	wchar_t* v6;         // eax
	_DWORD* v8;          // esi
	char* v9;            // eax
	wchar_t* v10;        // eax
	wchar_t* v11;        // eax
	_DWORD* v12;         // esi
	char* v13;           // eax
	wchar_t* v14;        // eax
	char v15[32];        // [esp+4h] [ebp-20h]

	if (!*getMemU32Ptr(0x5D4594, 2618908))
		return 0;
	dword_5d4594_1096288 = sub_43F360((char*)getMemAt(0x587000, 148576));
	dword_5d4594_1096264 = 0;
	dword_5d4594_1096256 = 0;
	dword_5d4594_1096260 = 0;
	*getMemU32Ptr(0x5D4594, 1091908) = 0;
	*getMemU32Ptr(0x5D4594, 1091912) = 0;
	*getMemU32Ptr(0x5D4594, 1091916) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1091920) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1091940) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1091944) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1091924) = 0;
	*getMemU32Ptr(0x5D4594, 1091928) = 0;
	v1 = 0;
	v2 = getMemAt(0x5D4594, 1092996);
	do {
		nox_sprintf(v15, "HealthMana%d", ++v1);
		*(_DWORD*)v2 = sub_42F970(v15);
		v2 += 4;
	} while ((int)v2 < (int)getMemAt(0x5D4594, 1093036));
	if (!*getMemU32Ptr(0x5D4594, 1096268)) {
		*getMemU32Ptr(0x5D4594, 1096268) = sub_44CFC0((CHAR*)getMemAt(0x587000, 148600));
		dword_5d4594_1096272 = sub_44CFC0((CHAR*)getMemAt(0x587000, 148612));
		dword_5d4594_1096276 = sub_44CFC0((CHAR*)getMemAt(0x587000, 148624));
		dword_5d4594_1096280 = sub_44CFC0((CHAR*)getMemAt(0x587000, 148644));
		dword_5d4594_1096284 = sub_44CFC0((CHAR*)getMemAt(0x587000, 148656));
	}
	dword_5d4594_1090276 = nox_window_new(0, 136, nox_win_width - 91, nox_win_height - 201, 91, 201, 0);
	sub_46AE60(*(int*)&dword_5d4594_1090276, *(int*)getMemAt(0x5D4594, 1092996));
	dword_5d4594_1091364 = nox_window_new(*(int*)&dword_5d4594_1090276, 8, 6, 166, 28, 30, 0);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1091364, sub_471B90, sub_471A80, 0);
	v3 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 148704), 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1029);
	sub_46B000((wchar_t*)(dword_5d4594_1091364 + 36), v3);
	*(_DWORD*)(dword_5d4594_1091364 + 32) = 2;
	*getMemU16Ptr(0x5D4594, 1091384) = 0;
	nox_thing* t4 = nox_get_thing(*(int*)&dword_5d4594_1096276);
	if (t4) {
		nox_drawable_link_thing(getMemAt(0x5D4594, 1091388), t4->field_1c);
		*getMemU32Ptr(0x5D4594, 1091368) = getMemAt(0x5D4594, 1091388);
		if (true) // TODO: byte_5D4594 != (unsigned __int8*)-1091388
			*getMemU32Ptr(0x5D4594, 1091508) |= 0x40000000u;
	} else {
		*getMemU32Ptr(0x5D4594, 1091368) = 0;
	}
	*getMemU32Ptr(0x5D4594, 1091380) = dword_5d4594_1096276;
	dword_5d4594_1090292 = nox_window_new(*(int*)&dword_5d4594_1090276, 8, 34, 166, 28, 30, 0);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1090292, sub_471B90, sub_471A80, 0);
	v5 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 148764), 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1060);
	sub_46B000((wchar_t*)(dword_5d4594_1090292 + 36), v5);
	*(_DWORD*)(dword_5d4594_1090292 + 32) = 0;
	*getMemU16Ptr(0x5D4594, 1090312) = 0;
	*getMemU32Ptr(0x5D4594, 1090296) = 0;
	*getMemU32Ptr(0x5D4594, 1090308) = 0;
	if (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 2618908) + 2251)) {
		dword_5d4594_1090828 = nox_window_new(*(int*)&dword_5d4594_1090276, 8, 62, 166, 28, 30, 0);
		nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1090828, sub_471B90, sub_471A80, 0);
		v6 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 148820), 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1083);
		sub_46B000((wchar_t*)(dword_5d4594_1090828 + 36), v6);
		*(_DWORD*)(dword_5d4594_1090828 + 32) = 1;
		*getMemU16Ptr(0x5D4594, 1090848) = 0;
		nox_thing* t7 = nox_get_thing(*(int*)&dword_5d4594_1096272);
		if (t7) {
			nox_drawable_link_thing(getMemAt(0x5D4594, 1090852), t7->field_1c);
			*getMemU32Ptr(0x5D4594, 1090832) = getMemAt(0x5D4594, 1090852);
			if (true) // TODO: byte_5D4594 != (unsigned __int8*)-1090852
				*getMemU32Ptr(0x5D4594, 1090972) |= 0x40000000u;
		} else {
			*getMemU32Ptr(0x5D4594, 1090832) = 0;
		}
		*getMemU32Ptr(0x5D4594, 1090844) = dword_5d4594_1096272;
		*getMemU32Ptr(0x5D4594, 1091900) = sub_42F970("PoisonTube");
		v8 = nox_window_new(*(int*)&dword_5d4594_1090276, 136, 0, 0, 91, 159, 0);
		v9 = sub_42F970("HealthManaTubes");
		sub_46AE60((int)v8, (int)v9);
		*getMemU32Ptr(0x5D4594, 1093056) = nox_window_new((int)v8, 8, 60, 34, 25, 125, 0);
		nox_window_set_all_funcs(*(_DWORD**)getMemAt(0x5D4594, 1093056), sub_472100, sub_471D10, 0);
		v10 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 148900), 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1122);
		sub_46B000((wchar_t*)(*getMemU32Ptr(0x5D4594, 1093056) + 36), v10);
		*(_DWORD*)(*getMemU32Ptr(0x5D4594, 1093056) + 32) = 1;
		*getMemU32Ptr(0x5D4594, 1093036) = nox_window_new((int)v8, 8, 34, 34, 25, 125, 0);
		nox_window_set_all_funcs(*(_DWORD**)getMemAt(0x5D4594, 1093036), sub_472100, sub_471D10, 0);
		v11 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 148952), 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1135);
		sub_46B000((wchar_t*)(*getMemU32Ptr(0x5D4594, 1093036) + 36), v11);
		*(_DWORD*)(*getMemU32Ptr(0x5D4594, 1093036) + 32) = 0;
		*getMemU32Ptr(0x5D4594, 1093076) = nox_window_new(0, 8, 0, 0, 0, 0, 0);
		nox_window_set_all_funcs(*(_DWORD**)getMemAt(0x5D4594, 1093076), 0, sub_471C00, 0);
		*(_DWORD*)(*getMemU32Ptr(0x5D4594, 1093076) + 32) = 0;
		*getMemU32Ptr(0x5D4594, 1093096) = nox_window_new(0, 8, 0, 0, 0, 0, 0);
		nox_window_set_all_funcs(*(_DWORD**)getMemAt(0x5D4594, 1093096), 0, sub_471C00, 0);
		*(_DWORD*)(*getMemU32Ptr(0x5D4594, 1093096) + 32) = 1;
		*getMemU32Ptr(0x5D4594, 1093176) = 1;
	} else {
		*getMemU32Ptr(0x5D4594, 1091900) = sub_42F970("WarriorPoisonTube");
		v12 = nox_window_new(*(int*)&dword_5d4594_1090276, 136, 0, 0, 91, 159, 0);
		v13 = sub_42F970("WarriorHealthTube");
		sub_46AE60((int)v12, (int)v13);
		*getMemU32Ptr(0x5D4594, 1093036) = nox_window_new((int)v12, 8, 34, 34, 25, 125, 0);
		nox_window_set_all_funcs(*(_DWORD**)getMemAt(0x5D4594, 1093036), sub_472100, sub_471D10, 0);
		v14 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 149048), 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1173);
		sub_46B000((wchar_t*)(*getMemU32Ptr(0x5D4594, 1093036) + 36), v14);
		*(_DWORD*)(*getMemU32Ptr(0x5D4594, 1093036) + 32) = 0;
		*getMemU32Ptr(0x5D4594, 1093076) = nox_window_new(0, 24, 0, 0, 0, 0, 0);
		nox_window_set_all_funcs(*(_DWORD**)getMemAt(0x5D4594, 1093076), 0, sub_471C00, 0);
		*(_DWORD*)(*getMemU32Ptr(0x5D4594, 1093076) + 32) = 0;
	}
	sub_472280();
	sub_470B00();
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		dword_5d4594_1096252 = 1;
	} else {
		dword_5d4594_1096252 = 0;
		nox_window_set_hidden(*(int*)getMemAt(0x5D4594, 1093076), 1);
		nox_window_set_hidden(*(int*)getMemAt(0x5D4594, 1093096), 1);
	}
	return 1;
}

//----- (00471D10) --------------------------------------------------------
int __cdecl sub_471D10(int xLeft) {
	_DWORD* v1;           // ebx
	int v2;               // esi
	unsigned __int8* v3;  // edi
	int v4;               // ecx
	int result;           // eax
	int v6;               // ebx
	int* v7;              // edi
	int v8;               // esi
	unsigned __int8* v9;  // esi
	int v10;              // edi
	int v11;              // eax
	int v12;              // eax
	int v13;              // ecx
	int v14;              // eax
	int v15;              // eax
	int v16;              // eax
	int yTop;             // [esp+Ch] [ebp-14h]
	int v18;              // [esp+10h] [ebp-10h]
	int v19;              // [esp+14h] [ebp-Ch]
	unsigned __int8* v20; // [esp+18h] [ebp-8h]
	unsigned __int8* v21; // [esp+1Ch] [ebp-4h]

	v1 = (_DWORD*)xLeft;
	v18 = *(_DWORD*)(xLeft + 32);
	v2 = v18;
	v3 = getMemAt(0x5D4594, sizeof(nox_window_yyy) * v18 + 1093036);
	v20 = getMemAt(0x5D4594, sizeof(nox_window_yyy) * v18 + 1093036);
	if (!v18 && dword_5d4594_1096264) {
		nox_client_wndGetPosition_46AA60(*(_DWORD**)&dword_5d4594_1090276, &xLeft, &yTop);
		nox_client_drawImageAt_47D2C0(*(int*)getMemAt(0x5D4594, 1091900), xLeft, yTop);
	}
	nox_client_wndGetPosition_46AA60(v1, &xLeft, &yTop);
	xLeft += 5;
	if (dword_5d4594_3799468) {
		nox_client_drawSetColor_434460(*(int*)getMemAt(0x5D4594, 2650656));
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, 15, 125);
	}
	v4 = *((_DWORD*)v3 + 2);
	if (v4) {
		v6 = 125 * *((_DWORD*)v3 + 1) / v4;
		nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, 15, 125 - v6);
		nox_client_drawSetColor_434460(*((_DWORD*)v3 + 3));
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop - v6 + 125, 15, v6);
		nox_client_drawEnableAlpha_434560(0);
		nox_client_drawAddPoint_49F500(xLeft, yTop - v6 + 125);
		sub_49F570(14, 0);
		nox_client_drawLineFromPoints_49E4B0();
		if (v2 < 2 && nox_client_renderBubbles_80844 == 1) {
			v19 = 64;
			v7 = (int*)getMemAt(0x5D4594, 1536 * v2 + 1093188);
			v21 = getMemAt(0x5D4594, 1536 * v2 + 1093188);
			do {
				if (v7[2]) {
					v8 = *(v7 - 1) >> 4;
					if (v8 >= 125 - v6) {
						if (dword_5d4594_1096264)
							nox_client_drawSetColor_434460(*((_DWORD*)v20 + 3));
						else
							nox_client_drawSetColor_434460(v7[3]);
						if (*v7 <= 2)
							nox_client_drawRectFilledOpaque_49CE30(xLeft + *(v7 - 2), yTop + v8, *v7, *v7);
						else
							sub_4720C0(xLeft + *(v7 - 2), yTop + v8);
						*(v7 - 1) -= v7[1];
					} else {
						v7[2] = 0;
					}
					v2 = v18;
				}
				v7 += 6;
				--v19;
			} while (v19);
			if (v6 > 1) {
				v9 = v21;
				v10 = 64;
				do {
					if (!*((_DWORD*)v9 + 2)) {
						v11 = sub_415FF0(1, 100, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 668);
						if (v11 >= 80)
							*(_DWORD*)v9 = (v11 >= 95) + 2;
						else
							*(_DWORD*)v9 = 1;
						v12 = sub_415FF0(0, 14, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 676);
						v13 = *(_DWORD*)v9;
						*((_DWORD*)v9 - 2) = v12;
						if (v13 + v12 > 15)
							*((_DWORD*)v9 - 2) = 15 - v13;
						*((_DWORD*)v9 - 1) = 16 * (125 - v13);
						*((_DWORD*)v9 + 1) = sub_415FF0(4, 48, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 684);
						*((_DWORD*)v9 + 2) = 1;
						LOBYTE(v19) = sub_415FF0(0, 64, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 688);
						if (v18)
							v14 = sub_4344A0(v19, v19, 255);
						else
							v14 = sub_4344A0(255, v19, v19);
						*((_DWORD*)v9 + 3) = v14;
					}
					v9 += 24;
					--v10;
				} while (v10);
				v2 = v18;
			}
		}
		if (!v2) {
			if (*(int*)&dword_5d4594_1096260 <= 0) {
				v16 = dword_5d4594_1096256 >> 3;
			} else {
				v15 = dword_5d4594_1096260 + dword_5d4594_1096256;
				dword_5d4594_1096256 = v15;
				--dword_5d4594_1096260;
				v16 = v15 >> 3;
				if (v16 >= 10) {
					v16 = 0;
					dword_5d4594_1096256 = 0;
				}
			}
			sub_46AE60(*(int*)&dword_5d4594_1090276, *getMemU32Ptr(0x5D4594, 4 * v16 + 1092996));
		}
		sub_472080();
		result = 1;
	} else {
		nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, 15, 125);
		result = 1;
	}
	return result;
}
