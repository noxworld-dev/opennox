#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3_3.h"
#include "GAME5_2.h"
#include "common__random.h"
#include "common__strman.h"

extern uint32_t dword_5d4594_811904;
extern uint32_t nox_player_netCode_85319C;
extern uint32_t nox_client_gui_flag_815132;
extern int nox_win_width;
extern int nox_win_height;

extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_red_2589776;
extern uint32_t nox_color_blue_2650684;
extern uint32_t nox_color_green_2614268;
extern uint32_t nox_color_cyan_2649820;
extern uint32_t nox_color_yellow_2589772;
extern uint32_t nox_color_violet_2598268;
extern uint32_t nox_color_black_2650656;
extern uint32_t nox_color_orange_2614256;

void nox_xxx_clientDrawAll_436100_draw_A() {
	if (!sub_436550()) {
		nox_common_resetEngineFlag(NOX_ENGINE_FLAG_9);
	} else {
		nox_common_setEngineFlag(NOX_ENGINE_FLAG_9);
	}
	if (!*getMemU32Ptr(0x5D4594, 814540)) {
		*getMemU32Ptr(0x5D4594, 814540) = nox_xxx_gLoadImg_42F970("MenuSystemBG");
	}
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_9)) {
		void* v10 = nox_xxx_guiFontPtrByName_43F360("large");
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 814540), 0, 0);
		wchar_t* v11 =
			nox_strman_loadString_40F1D0("InProgress", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1550);
		int v22 = 0;
		nox_xxx_drawGetStringSize_43F840(v10, v11, &v22, 0, 0);
		nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
		int v21 = nox_win_height / 2;
		int v20 = (nox_win_width - v22) / 2;
		wchar_t* v12 =
			nox_strman_loadString_40F1D0("InProgress", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1553);
		nox_xxx_drawString_43F6E0(v10, v12, v20, v21);
	}
}

void nox_xxx_clientDrawAll_436100_draw_B() {
	wchar_t v25[128];
	nox_wcscpy(v25, (const wchar_t*)getMemAt(0x5D4594, 811376));
	int v14 = (nox_win_width - 310) / 2;
	int v16 = (nox_win_height - 200) / 2;
	int* v15 = getMemIntPtr(0x5D4594, 811888 + 4 * *getMemU32Ptr(0x5D4594, 811060));
	if (!*v15) {
		*v15 = nox_xxx_gLoadImg_42F970(*(const char**)getMemAt(0x587000, 85712 + 4 * *getMemU32Ptr(0x5D4594, 811060)));
	}
	nox_client_drawImageAt_47D2C0(*v15, v14, v16);
	int v22 = 0;
	int v23 = 0;
	nox_xxx_drawGetStringSize_43F840(0, v25, &v22, &v23, 220);
	int v17 = v14 + 45;
	int v18 = v16 + (49 - v23) / 2 + 143;
	nox_client_drawSetColor_434460(nox_color_white_2523948);
	for (wchar_t* tok = nox_wcstok(v25, L"\n\r"); tok; tok = nox_wcstok(0, L"\n\r")) {
		nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
		nox_xxx_drawGetStringSize_43F840(0, tok, &v22, 0, 0);
		nox_xxx_drawStringWrap_43FAF0(0, tok, v17 + (220 - v22) / 2, v18, 220, 0);
		v18 += nox_xxx_guiFontHeightMB_43F320(0);
	}
}

//----- (00436F50) --------------------------------------------------------
int sub_436F50() {
	int v0;      // ebx
	int v2;      // edi
	int v3;      // esi
	char* v4;    // eax
	int result;  // eax
	int v6;      // esi
	wchar_t* v7; // eax
	int v8;      // [esp-8h] [ebp-14h]
	wchar_t* v9; // [esp-4h] [ebp-10h]

	v0 = nox_xxx_guiFontHeightMB_43F320(0);
	nox_draw_viewport_t* rdr = nox_draw_getViewport_437250();
	v2 = rdr->x1 + 10;
	v3 = rdr->y1 + 90;
	nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
	v4 = nox_server_currentMapGetFilename_409B30();
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 811120), L"%S", v4);
	nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 811120), v2, v3);
	result = *getMemU32Ptr(0x852978, 8);
	v6 = v0 + v3;
	if (*getMemU32Ptr(0x852978, 8)) {
		if (*getMemU32Ptr(0x8531A0, 2576)) {
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 811120), L"X:%d\tY:%d",
						 *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 12), *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 16));
			nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 811120), v2, v6);
			v9 = nox_strman_loadString_40F1D0(
				*(char**)getMemAt(0x587000, 29456 + 4 * *(unsigned char*)(*getMemU32Ptr(0x8531A0, 2576) + 2251)), 0,
				"C:\\NoxPost\\src\\client\\System\\client.c", 1357);
			v8 = *(char*)(*getMemU32Ptr(0x8531A0, 2576) + 3684);
			v7 = nox_strman_loadString_40F1D0("PlayerInfo", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1355);
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 811120), v7, v8, v9);
			result = nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 811120), v2, v0 + v6);
		}
	}
	return result;
}

//----- (004358A0) --------------------------------------------------------
char* nox_xxx_getRandomName_4358A0() {
	int v0;             // ecx
	const char** v1;    // eax
	const char* v2;     // edx
	const char* v4[34]; // [esp+0h] [ebp-88h]

	v0 = *getMemU32Ptr(0x5D4594, 814516);
	v4[0] = "Dweezle";
	v4[1] = "Glork";
	v4[2] = "Floogle";
	v4[3] = "Goombah";
	v4[4] = "Kraun";
	v4[5] = "Kloog";
	v4[6] = "Zurg";
	v4[7] = "Darg";
	v4[8] = "Arfingle";
	v4[9] = "Buurl";
	v4[10] = "Gurgin";
	v4[11] = "Grok";
	v4[12] = "Hurlong";
	v4[13] = "Luric";
	v4[14] = "Lupis";
	v4[15] = "Mallik";
	v4[16] = "Thrall";
	v4[17] = "Norwood";
	v4[18] = "Nulik";
	v4[19] = "Orin";
	v4[20] = "Olaf";
	v4[21] = "Orguk";
	v4[22] = "Pervis";
	v4[23] = "Paavik";
	v4[24] = "Qix";
	v4[25] = "Xevin";
	v4[26] = "Xurcon";
	v4[27] = "Markoan";
	v4[28] = "Yuric";
	v4[29] = "Yoovis";
	v4[30] = "Yalek";
	v4[31] = "Zug";
	v4[32] = "Zivik";
	v4[33] = 0;
	if (!*getMemU32Ptr(0x5D4594, 814516)) // TODO: byte_587000 != (unsigned char*)-85792
	{
		v1 = v4;
		do {
			v2 = v1[1];
			++v1;
			++v0;
		} while (v2);
		*getMemU32Ptr(0x5D4594, 814516) = v0;
	}
	return (char*)v4[nox_common_randomIntMinMax_415FF0(0, v0 - 1, "C:\\NoxPost\\src\\client\\System\\client.c", 559)];
}
