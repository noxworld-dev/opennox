#include "client__shell__mainmenu.h"
#include "client__gui__window.h"

#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "client__shell__noxworld.h"
#include "client__shell__optsback.h"
#include "client__shell__selchar.h"
#include "client__video__draw_common.h"
#include "common__random.h"
#include "common__strman.h"
#include "input_common.h"
#include "operators.h"

extern uint32_t nox_client_gui_flag_815132;

//----- (004A22A0) --------------------------------------------------------
int sub_4A22A0(int a1, int* a2) {
	int v2;             // edx
	int v3;             // ecx
	unsigned char* v4;  // esi
	int v5;             // eax
	int v6;             // eax
	bool v7;            // zf
	int v8;             // eax
	int v9;             // eax
	unsigned char* v10; // esi
	int v11;            // eax
	int xLeft;          // [esp+4h] [ebp-8h]
	int yTop;           // [esp+8h] [ebp-4h]

	nox_xxx_bookGet_430B40_get_mouse_prev_seq();
	nox_client_wndGetPosition_46AA60((uint32_t*)a1, &xLeft, &yTop);
	if ((signed char)*(uint8_t*)(a1 + 4) >= 0) {
		if (a2[5] != 0x80000000) {
			nox_client_drawSetColor_434460(a2[5]);
			nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, *(uint32_t*)(a1 + 8), *(uint32_t*)(a1 + 12));
		}
	} else {
		v2 = *(uint32_t*)(a1 + 100);
		xLeft += *(uint32_t*)(a1 + 96);
		v3 = v2 + yTop;
		LOBYTE(v2) = *(uint8_t*)(a1 + 36);
		yTop = v3;
		if (v2 & 2) {
			nox_client_drawImageAt_47D2C0(a2[10], xLeft, v3);
		} else {
			nox_client_drawImageAt_47D2C0(a2[6], xLeft, v3);
		}
	}
	if (*getMemU32Ptr(0x587000, 168836)) {
		v4 = getMemAt(0x587000, 168868);
		do {
			v5 = *((uint32_t*)v4 + 2);
			if (v5) {
				*((uint32_t*)v4 + 2) = v5 - 1;
			}
			v6 = *((uint32_t*)v4 + 1);
			if (v6) {
				*((uint32_t*)v4 + 1) = v6 - 1;
				*((uint32_t*)v4 + 2) =
					nox_common_randomIntMinMax_415FF0(60, 120, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 180);
			}
			v7 = (*(uint32_t*)v4)-- == 1;
			v8 = *((uint32_t*)v4 - 5);
			if (v7) {
				if (v8) {
					*((uint32_t*)v4 - 5) = 0;
					*(uint32_t*)v4 = nox_common_randomIntMinMax_415FF0(
						*((uint32_t*)v4 - 4), *((uint32_t*)v4 - 3), "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 211);
					*((uint32_t*)v4 + 2) =
						nox_common_randomIntMinMax_415FF0(60, 90, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 214);
				} else {
					*((uint32_t*)v4 - 5) = 1;
					*(uint32_t*)v4 = nox_common_randomIntMinMax_415FF0(
						*((uint32_t*)v4 - 2), *((uint32_t*)v4 - 1), "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 199);
				}
			} else if (!v8 && !*((uint32_t*)v4 + 2) && !*((uint32_t*)v4 + 1) &&
					   nox_common_randomIntMinMax_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 228) >
						   75) {
				*((uint32_t*)v4 + 1) =
					nox_common_randomIntMinMax_415FF0(4, 8, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 229);
			}
			v9 = *((uint32_t*)v4 + 4);
			v4 += 48;
		} while (v9);
	}
	if (*getMemU32Ptr(0x587000, 168832)) {
		v10 = getMemAt(0x587000, 168872);
		do {
			if (!*((uint32_t*)v10 - 6) && !*(uint32_t*)v10) {
				nox_client_drawImageAt_47D2C0(*((uint32_t*)v10 - 9), *((uint32_t*)v10 - 8), *((uint32_t*)v10 - 7));
			}
			v11 = *((uint32_t*)v10 + 2);
			v10 += 48;
		} while (v11);
	}
	return 1;
}
