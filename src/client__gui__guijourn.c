#include "client__gui__guijourn.h"

#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2_3.h"
#include "common__strman.h"
#include "operators.h"

extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_red_2589776;
extern uint32_t nox_color_blue_2650684;
extern uint32_t nox_color_green_2614268;
extern uint32_t nox_color_cyan_2649820;
extern uint32_t nox_color_yellow_2589772;
extern uint32_t nox_color_violet_2598268;
extern uint32_t nox_color_black_2650656;
extern uint32_t nox_color_orange_2614256;

//----- (00469BC0) --------------------------------------------------------
void nox_xxx_cliBuildJournalString_469BC0() {
	int v0;            // esi
	int v1;            // eax
	int v2;            // ebx
	int i;             // ebp
	int v4;            // eax
	int v5;            // eax
	int v6;            // eax
	wchar_t* v7;       // eax
	wchar_t* v8;       // [esp-20h] [ebp-1078h]
	wchar_t* v9;       // [esp-20h] [ebp-1078h]
	wchar_t* v10;      // [esp-20h] [ebp-1078h]
	int v11;           // [esp+4h] [ebp-1054h]
	int v12;           // [esp+8h] [ebp-1050h]
	char v13[76];      // [esp+Ch] [ebp-104Ch]
	wchar_t v14[2048]; // [esp+58h] [ebp-1000h]

	v0 = *getMemU32Ptr(0x8531A0, 2576);
	if (*getMemU32Ptr(0x8531A0, 2576)) {
		v1 = nox_xxx_guiFontHeightMB_43F320(0);
		v2 = *(uint32_t*)(v0 + 3644);
		v11 = v1;
		for (i = -v1; v2; i += v11 + v12) {
			strcpy(v13, "Journal:");
			HIWORD(v4) = 0;
			strcat(&v13, (const char*)v2);
			LOWORD(v4) = *(uint16_t*)(v2 + 72);
			v5 = v4 - 2;
			if (v5) {
				v6 = v5 - 2;
				if (v6) {
					if (v6 == 4) {
						v8 = nox_strman_loadString_40F1D0("Journal:HintLabel", 0,
														  "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 64);
						nox_wcscpy(v14, v8);
					} else {
						v14[0] = 0;
					}
				} else {
					v9 = nox_strman_loadString_40F1D0("Journal:CompletedLabel", 0,
													  "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 60);
					nox_wcscpy(v14, v9);
				}
			} else {
				v10 = nox_strman_loadString_40F1D0("Journal:QuestLabel", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c",
												   56);
				nox_wcscpy(v14, v10);
			}
			nox_wcscat(v14, L" ");
			v7 = nox_strman_loadString_40F1D0((char*)&v13, 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 74);
			nox_wcscat(v14, v7);
			nox_xxx_drawGetStringSize_43F840(0, v14, 0, &v12, 240);
			v2 = *(uint32_t*)(v2 + 64);
		}
		*getMemU32Ptr(0x5D4594, 1064848) = i <= 0 ? 0 : i;
	}
}

//----- (00469D40) --------------------------------------------------------
void nox_xxx_guiDrawJournal_469D40(int xLeft, int yTop, int a3) {
	int v3;            // esi
	int v4;            // ebp
	int v5;            // ebx
	int i;             // eax
	int v7;            // eax
	int v8;            // edi
	wchar_t* v9;       // eax
	wchar_t* v10;      // eax
	wchar_t* v11;      // eax
	wchar_t* v12;      // eax
	int v13;           // esi
	int v14;           // [esp+10h] [ebp-1054h]
	int v15;           // [esp+14h] [ebp-1050h]
	char v16[76];      // [esp+18h] [ebp-104Ch]
	wchar_t v17[2048]; // [esp+64h] [ebp-1000h]

	v3 = *getMemU32Ptr(0x8531A0, 2576);
	v4 = yTop - a3;
	if (*getMemU32Ptr(0x8531A0, 2576)) {
		nox_client_drawSetColor_434460(nox_color_black_2650656);
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, 260, 150);
		v5 = *(uint32_t*)(v3 + 3644);
		if (v5) {
			for (i = *(uint32_t*)(v5 + 64); i; i = *(uint32_t*)(i + 64)) {
				v5 = i;
			}
			v14 = nox_xxx_guiFontHeightMB_43F320(0);
			do {
				HIWORD(v7) = 0;
				strcpy(v16, "Journal:");
				strcat(v16, (const char*)v5);
				LOWORD(v7) = *(uint16_t*)(v5 + 72);
				switch (v7) {
				case 1:
					v8 = nox_color_white_2523948;
					goto LABEL_12;
				case 2:
					v8 = *getMemU32Ptr(0x85B3FC, 940);
					v9 = nox_strman_loadString_40F1D0("Journal:QuestLabel", 0,
													  "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 135);
					nox_wcscpy(v17, v9);
					break;
				case 4:
					v8 = *getMemU32Ptr(0x85B3FC, 956);
					v10 = nox_strman_loadString_40F1D0("Journal:CompletedLabel", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 140);
					nox_wcscpy(v17, v10);
					break;
				case 8:
					v8 = nox_color_yellow_2589772;
					v11 = nox_strman_loadString_40F1D0("Journal:HintLabel", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 145);
					nox_wcscpy(v17, v11);
					break;
				default:
					v8 = *getMemU32Ptr(0x8531A0, 2572);
				LABEL_12:
					v17[0] = 0;
					break;
				}
				nox_wcscat(v17, L" ");
				v12 = nox_strman_loadString_40F1D0((char*)&v16, 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 155);
				nox_wcscat(v17, v12);
				nox_xxx_drawGetStringSize_43F840(0, &v17, 0, &v15, 240);
				v13 = v15 + v4;
				if (v15 + v4 > yTop) {
					nox_xxx_drawSetTextColor_434390(v8);
					nox_xxx_drawStringWrap_43FAF0(0, &v17, xLeft + 10, v4, 240, 0);
				}
				v4 = v13 + v14;
				if (v13 + v14 > yTop + 150) {
					break;
				}
				v5 = *(uint32_t*)(v5 + 68);
			} while (v5);
		}
	}
}
