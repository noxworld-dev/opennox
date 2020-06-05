#include "mainmenu.h"

#include "../../proto.h"
#include "noxworld.h"
#include "selchar.h"

extern _DWORD dword_5d4594_1307308;
extern _DWORD dword_5d4594_815132;
extern nox_window* nox_win_main_menu;

//----- (004A1DC0) --------------------------------------------------------
int __cdecl sub_4A1DC0(int a1, int a2, int* a3, int a4) {
	int v4;        // eax
	wchar_t* v5;   // eax
	int v6;        // eax
	wchar_t* v7;   // eax
	int v8;        // eax
	wchar_t* v9;   // [esp-10h] [ebp-94h]
	char v10[128]; // [esp+4h] [ebp-80h]

	if (a2 == 16389) {
		sub_452D80(920, 100);
	} else {
		if (a2 != 16391)
			return 0;
		if (*(_BYTE*)(dword_5d4594_1307308 + 64) && !nox_common_gameFlags_check_40A5C0(0x2000000)) {
		LABEL_32:
			sub_452D80(921, 100);
		} else {
			switch (sub_46B0A0(a3)) {
			case 111:
				if (sub_40ABD0() && sub_413840()) {
					sub_40A4D0(2048);
					nox_common_gameFlags_unset_40A540(0x2000);
					nox_common_gameFlags_unset_40A540(0x10000);
					sub_501AC0(0);
					v4 = *(_DWORD*)&nox_common_engineFlags;
					LOBYTE(v4) = nox_common_engineFlags & 0xCF;
					*(_DWORD*)&nox_common_engineFlags = v4;
					sub_4D6F40(0);
					sub_4D6F90(0);
					sub_4D6F60(0);
					sub_4D6F80(0);
					sub_470AA0(0);
					sub_461440(0);
					sub_4A1D40();
					sub_472520(1110);
					if (!sub_4D1630()) {
						sub_43DDD0(0);
						dword_5d4594_815132 = 0;
						return 0;
					}
					if (sub_4DC550()) {
						sub_4A7A70(1);
						*(_DWORD*)(dword_5d4594_1307308 + 52) = sub_4A4DB0;
					} else {
						sub_4A7A70(0);
						*(_DWORD*)(dword_5d4594_1307308 + 52) = sub_4A4840;
					}
					sub_452D80(921, 100);
				} else {
					v9 = loadString_sub_40F1D0((char*)&byte_587000[169256], 0,
								   "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 341);
					v5 = loadString_sub_40F1D0((char*)&byte_587000[169304], 0,
								   "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 341);
					sub_449A10(nox_win_main_menu, (int)v5, (int)v9, 33, 0, 0);
					sub_44A360(1);
					sub_44A4B0();
					sub_452D80(921, 100);
				}
				return 1;
			case 112:
				sub_4A1D40();
				*(_DWORD*)&nox_common_engineFlags =
				    *(_DWORD*)&nox_common_engineFlags & 0xFFFFFFDF | 0x10;
				sub_40A4D0(0x2000);
				sub_40A4D0(0x10000);
				nox_common_gameFlags_unset_40A540(2048);
				sub_461440(0);
				sub_4D6F40(0);
				sub_4D6F90(0);
				sub_4D6F60(0);
				sub_4D6F80(0);
				if (!sub_473670())
					sub_473610();
				sub_470AA0(0);
				sub_472520(2300);
				if (sub_4D1630())
					goto LABEL_26;
				sub_43DDD0(0);
				dword_5d4594_815132 = 0;
				return 0;
			case 121:
				if (!sub_4CB230("Intro.vqa", v10))
					goto LABEL_32;
				sub_4A1D40();
				sub_4B0300(v10);
				sub_4B0640(sub_43C0A0);
				*(_DWORD*)(dword_5d4594_1307308 + 52) = sub_4A2200;
				sub_452D80(921, 100);
				return 1;
			case 122:
				if (sub_44E560()) {
					nox_client_lockScreenBriefing_450160(255, 1, 0);
					sub_4A2530();
				}
				v8 = a3[9];
				LOBYTE(v8) = v8 & 0xFD;
				a3[9] = v8;
				goto LABEL_32;
			case 131:
				LOBYTE(v6) = nox_client_checkQuestExp_SKU2_4D7700();
				if (!v6) {
					v7 = loadString_sub_40F1D0((char*)&byte_587000[169352], 0,
								   "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 416);
					sub_449A10(nox_win_main_menu, 0, (int)v7, 33, 0, 0);
					sub_44A360(0);
					sub_44A4B0();
					sub_452D80(921, 100);
					return 1;
				}
				sub_4A1D40();
				*(_DWORD*)&nox_common_engineFlags =
				    *(_DWORD*)&nox_common_engineFlags & 0xFFFFFFDF | 0x10;
				sub_40A4D0(0x2000);
				sub_40A4D0(0x10000);
				nox_common_gameFlags_unset_40A540(2048);
				sub_4D6F40(1);
				sub_4D6F90(1);
				sub_4E3CD0(0);
				sub_4D7440(0);
				sub_472520(2300);
				if (!sub_473670())
					sub_473610();
				sub_461440(0);
				if (!sub_4D1630()) {
					sub_43DDD0(0);
					dword_5d4594_815132 = 0;
					return 0;
				}
			LABEL_26:
#ifdef __EMSCRIPTEN__
				sub_4AA450();
				*(_DWORD*)(dword_5d4594_1307308 + 52) = sub_4379F0;
				sub_43AF50(0);
#else
				*(_DWORD*)(dword_5d4594_1307308 + 52) = sub_4AA270;
#endif
				sub_452D80(921, 100);
				break;
			default:
				goto LABEL_32;
			}
		}
	}
	return 1;
}

//----- (004A22A0) --------------------------------------------------------
int __cdecl sub_4A22A0(int a1, int* a2) {
	int v2;               // edx
	int v3;               // ecx
	unsigned __int8* v4;  // esi
	int v5;               // eax
	int v6;               // eax
	bool v7;              // zf
	int v8;               // eax
	int v9;               // eax
	unsigned __int8* v10; // esi
	int v11;              // eax
	int xLeft;            // [esp+4h] [ebp-8h]
	int yTop;             // [esp+8h] [ebp-4h]

	sub_430B40_get_mouse_prev_seq();
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if ((signed char)*(_BYTE*)(a1 + 4) >= 0) {
		if (a2[5] != 0x80000000) {
			nox_client_drawSetColor_434460(a2[5]);
			nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
		}
	} else {
		v2 = *(_DWORD*)(a1 + 100);
		xLeft += *(_DWORD*)(a1 + 96);
		v3 = v2 + yTop;
		LOBYTE(v2) = *(_BYTE*)(a1 + 36);
		yTop = v3;
		if (v2 & 2)
			nox_client_drawImageAt_47D2C0(a2[10], xLeft, v3);
		else
			nox_client_drawImageAt_47D2C0(a2[6], xLeft, v3);
	}
	if (*(_DWORD*)&byte_587000[168836]) {
		v4 = &byte_587000[168868];
		do {
			v5 = *((_DWORD*)v4 + 2);
			if (v5)
				*((_DWORD*)v4 + 2) = v5 - 1;
			v6 = *((_DWORD*)v4 + 1);
			if (v6) {
				*((_DWORD*)v4 + 1) = v6 - 1;
				*((_DWORD*)v4 + 2) =
				    sub_415FF0(60, 120, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 180);
			}
			v7 = (*(_DWORD*)v4)-- == 1;
			v8 = *((_DWORD*)v4 - 5);
			if (v7) {
				if (v8) {
					*((_DWORD*)v4 - 5) = 0;
					*(_DWORD*)v4 = sub_415FF0(*((_DWORD*)v4 - 4), *((_DWORD*)v4 - 3),
								  "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 211);
					*((_DWORD*)v4 + 2) =
					    sub_415FF0(60, 90, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 214);
				} else {
					*((_DWORD*)v4 - 5) = 1;
					*(_DWORD*)v4 = sub_415FF0(*((_DWORD*)v4 - 2), *((_DWORD*)v4 - 1),
								  "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 199);
				}
			} else if (!v8 && !*((_DWORD*)v4 + 2) && !*((_DWORD*)v4 + 1) &&
				   sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 228) > 75) {
				*((_DWORD*)v4 + 1) =
				    sub_415FF0(4, 8, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 229);
			}
			v9 = *((_DWORD*)v4 + 4);
			v4 += 48;
		} while (v9);
	}
	if (*(_DWORD*)&byte_587000[168832]) {
		v10 = &byte_587000[168872];
		do {
			if (!*((_DWORD*)v10 - 6) && !*(_DWORD*)v10)
				nox_client_drawImageAt_47D2C0(*((_DWORD*)v10 - 9), *((_DWORD*)v10 - 8), *((_DWORD*)v10 - 7));
			v11 = *((_DWORD*)v10 + 2);
			v10 += 48;
		} while (v11);
	}
	return 1;
}
