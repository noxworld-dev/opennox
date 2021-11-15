#include "client__system__client.h"

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
extern uint32_t dword_5d4594_811896;
extern uint32_t dword_5d4594_2618900;
extern uint32_t dword_5d4594_2614264;
extern uint32_t dword_5d4594_805836;
extern uint32_t nox_player_netCode_85319C;
extern uint32_t nox_client_gui_flag_815132;
extern int nox_win_width;
extern int nox_win_height;
extern nox_draw_viewport_t nox_draw_viewport;
extern unsigned int nox_frame_xxx_2598000;

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
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
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
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2523948));
	for (wchar_t* tok = nox_wcstok(v25, L"\n\r"); tok; tok = nox_wcstok(0, L"\n\r")) {
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
		nox_xxx_drawGetStringSize_43F840(0, tok, &v22, 0, 0);
		nox_xxx_drawString_43FAF0(0, tok, v17 + (220 - v22) / 2, v18, 220, 0);
		v18 += nox_xxx_guiFontHeightMB_43F320(0);
	}
}

//----- (00436100) --------------------------------------------------------
#ifndef NOX_CGO
void nox_xxx_clientDrawAll_436100_draw() {
	unsigned long long v0 = nox_platform_get_ticks();
	int v3 = 0;
	if ((unsigned int)(v0 - *getMemU32Ptr(0x5D4594, 814532)) < *getMemIntPtr(0x587000, 85748)) {
		v3 = 0;
	} else {
		v3 = 1;
		nox_ticks_reset_416D40();
	}
	if (!(!*getMemU32Ptr(0x587000, 85724) || v3 || !nox_common_gameFlags_check_40A5C0(1) || nox_ticks_check_416D70() ||
		  nox_client_gui_flag_815132 || nox_xxx_checkGameFlagPause_413A50() ||
		  nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING))) {
		nox_common_setEngineFlag(NOX_ENGINE_FLAG_PAUSE);
		return;
	}
	nox_common_resetEngineFlag(NOX_ENGINE_FLAG_PAUSE);
	*getMemU64Ptr(0x5D4594, 814532) = v0;
	*getMemU32Ptr(0x5D4594, 811916) = nox_frame_xxx_2598000;
	int v6 = nox_draw_viewport.x1;
	int v7 = nox_draw_viewport.y1;
	if (*getMemU32Ptr(0x587000, 85744)) {
		nox_draw_viewport.height = nox_draw_viewport.width * nox_win_height / nox_win_width;
		v6 = (nox_win_width - nox_draw_viewport.width) / 2;
		v7 = (nox_win_height - nox_draw_viewport.height) / 2;
		nox_draw_viewport.x1 = v6;
		nox_draw_viewport.y1 = v7;
		nox_draw_viewport.x2 = v6 + nox_draw_viewport.width - 1;
		nox_draw_viewport.y2 = v7 + nox_draw_viewport.height - 1;
	}
	sub_430B50(v6, v7, nox_draw_viewport.x2, nox_draw_viewport.y2);
	if (nox_player_netCode_85319C) {
		*getMemU32Ptr(0x852978, 8) = nox_xxx_netSpriteByCodeDynamic_45A6F0(nox_player_netCode_85319C);
	}
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		nox_xxx_clientDrawAll_436100_draw_A();
	} else if (*getMemU32Ptr(0x852978, 8) && nox_client_isConnected_43C700()) {
		nox_xxx_drawAllMB_475810_draw(&nox_draw_viewport);
		nox_xxx_drawMinimapAndLines_4738E0();
	} else {
		nox_xxx_drawSelectColor_434350(*getMemIntPtr(0x85B3FC, 952));
		sub_440900();
	}
	if (dword_5d4594_811896) {
		sub_4365C0();
	}
	if (dword_5d4594_811904) {
		sub_436F50();
	}
	if (nox_common_gameFlags_check_40A5C0(8)) {
		unsigned long long v13 = nox_platform_get_ticks() - *getMemU64Ptr(0x5D4594, 811908);
		if (v13 > 0x2710 && !nox_common_gameFlags_check_40A5C0(1)) {
			nox_common_gameFlags_unset_40A540(8);
		}
	}
	if (nox_common_gameFlags_check_40A5C0(8)) {
		nox_xxx_clientDrawAll_436100_draw_B();
	}
	if (*getMemU32Ptr(0x587000, 85744)) {
		sub_430B50(0, 0, nox_win_width - 1, nox_win_height - 1);
		sub_440900();
		*getMemU32Ptr(0x587000, 85744) = 0;
	}
}
#endif // NOX_CGO

//----- (004365C0) --------------------------------------------------------
int sub_4365C0() {
	int v0;          // edi
	int v1;          // esi
	uint32_t v2;     // ecx
	unsigned int v3; // eax
	short* v4;       // eax
	int v5;          // esi
	wchar_t* v6;     // eax
	int v7;          // ebx
	wchar_t* v8;     // eax
	wchar_t* v9;     // eax
	wchar_t* v10;    // eax
	wchar_t* v11;    // eax
	int v12;         // edi
	char* i;         // esi
	wchar_t* v14;    // eax
	int v16;         // [esp-10h] [ebp-28h]
	int v17;         // [esp-Ch] [ebp-24h]
	int v18;         // [esp-8h] [ebp-20h]
	int v19;         // [esp-8h] [ebp-20h]
	int v20;         // [esp-8h] [ebp-20h]
	wchar_t* v21;    // [esp-8h] [ebp-20h]
	int v22;         // [esp-8h] [ebp-20h]
	int v23;         // [esp-4h] [ebp-1Ch]
	int v24;         // [esp-4h] [ebp-1Ch]
	int v25;         // [esp-4h] [ebp-1Ch]
	int v26;         // [esp-4h] [ebp-1Ch]
	int v27;         // [esp-4h] [ebp-1Ch]
	int v28;         // [esp-4h] [ebp-1Ch]
	int v29;         // [esp+Ch] [ebp-Ch]
	int v30;         // [esp+10h] [ebp-8h]
	int v31;         // [esp+14h] [ebp-4h]

	v0 = nox_win_width - 177;
	v1 = nox_win_height - 80;
	if (*getMemIntPtr(0x5D4594, 814520) >= *getMemIntPtr(0x587000, 85740)) {
		*getMemU32Ptr(0x587000, 85740) = *getMemU32Ptr(0x5D4594, 814520) + 10;
		v2 = nox_platform_get_ticks();
		v3 = 0x2710 / (v2 - *getMemU32Ptr(0x5D4594, 814528));
		*getMemU32Ptr(0x5D4594, 814524) = v2;
		*getMemU32Ptr(0x5D4594, 814528) = v2;
		*getMemU32Ptr(0x587000, 85732) = v3;
	}
	sub_436AA0(*getMemIntPtr(0x587000, 85732));
	nox_xxx_drawTimingMB_436C40();
	nox_xxx_drawPing_436DF0(*(int*)&dword_5d4594_2614264);
	if (dword_5d4594_805836) {
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x8531A0, 2572));
		v23 = v1;
		v18 = v0;
		v4 = (short*)nox_strman_loadString_40F1D0("MMX", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1150);
	} else {
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x85B3FC, 940));
		v23 = v1;
		v18 = v0;
		v4 = (short*)nox_strman_loadString_40F1D0("NoMMX", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1155);
	}
	nox_xxx_drawString_43F6E0(0, v4, v18, v23);
	v5 = v1 + 10;
	v24 = nox_frame_xxx_2598000;
	v6 = nox_strman_loadString_40F1D0("Frame", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1159);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 810900), v6, v24);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 810900), v0, v5);
	v5 += 10;
	v7 = sub_43C760();
	v8 = nox_strman_loadString_40F1D0("PacketSize", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1165);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 810900), v8, v7);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 810900), v0, v5);
	nox_xxx_drawBandwith_436970(v7);
	v5 += 10;
	v25 = nox_get_drawable_count();
	v9 = nox_strman_loadString_40F1D0("DrawCount", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1172);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 810900), v9, v25);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 810900), v0, v5);
	v5 += 10;
	v26 = *getMemU32Ptr(0x85B3FC, 120);
	v19 = dword_5d4594_2618900;
	v10 = nox_strman_loadString_40F1D0("LatePackets", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1177);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 810900), v10, v19, v26);
	nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 810900), v0, v5);
	v5 += 10;
	v27 = *getMemU32Ptr(0x587000, 85732);
	v20 = dword_5d4594_2614264;
	v11 = nox_strman_loadString_40F1D0("Latency", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1181);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 810900), v11, v20, v27);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 952));
	nox_client_drawRectFilledOpaque_49CE30(v0 + 80, v5, 16, 8);
	nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 810900), v0, v5);
	v12 = 200;
	for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
		if (i[3680] & 8) {
			v21 = nox_strman_loadString_40F1D0("Muted", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1201);
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 810900), v21, i + 4704);
		} else {
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 810900), L"%s", i + 4704);
		}
		nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 810900), 10, v12);
		sub_4E5630(i[2064], &v31, &v30, &v29);
		v28 = v29;
		v22 = v30;
		v17 = v31;
		if (i[2064] == 31) {
			v16 = sub_553ED0(0);
			v14 = nox_strman_loadString_40F1D0("TransferStats", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1211);
		} else {
			v16 = sub_553ED0((unsigned char)i[2064] + 1);
			v14 = nox_strman_loadString_40F1D0("TransferStats", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1216);
		}
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 810900), v14, v16, v17, v22, v28);
		nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 810900), 70, v12);
		v12 += 10;
	}
	return ++*getMemU32Ptr(0x5D4594, 814520);
}

//----- (00436970) --------------------------------------------------------
int nox_xxx_drawBandwith_436970(int a1) {
	int v1;     // esi
	short* v2;  // eax
	int v3;     // ecx
	int v4;     // ebx
	int v5;     // edi
	int v6;     // ebp
	int result; // eax
	int v8;     // [esp-4h] [ebp-18h]
	int v9;     // [esp+10h] [ebp-4h]
	int v10;    // [esp+18h] [ebp+4h]

	v9 = nox_win_height - 1;
	v1 = nox_win_height - 31;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v8 = v1 - nox_xxx_guiFontHeightMB_43F320(0);
	v2 = (short*)nox_strman_loadString_40F1D0("Bandwidth", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 323);
	nox_xxx_drawString_43F6E0(0, v2, 0, v8);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 956));
	nox_client_drawBorderLines_49CC70(0, v1, nox_win_width, 31);
	v3 = *getMemU32Ptr(0x5D4594, 812452);
	*getMemU32Ptr(0x5D4594, 811940 + 4 * *getMemU32Ptr(0x5D4594, 812452)) = a1 / 4;
	if (a1 / 4 > 30) {
		*getMemU32Ptr(0x5D4594, 811940 + 4 * v3) = 30;
	}
	v4 = (v3 + 1) % 128;
	*getMemU32Ptr(0x5D4594, 812452) = (v3 + 1) % 128;
	v5 = 0;
	v6 = nox_win_width / 128;
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2589772));
	v10 = 127;
	do {
		nox_client_drawAddPoint_49F500(v5, v9 - *getMemU32Ptr(0x5D4594, 811940 + 4 * v4));
		v5 += v6;
		nox_client_drawAddPoint_49F500(v5, v9 - *getMemU32Ptr(0x5D4594, 811940 + 4 * ((v4 + 1) % 128)));
		nox_client_drawLineFromPoints_49E4B0();
		v4 = (v4 + 1) % 128;
		result = --v10;
	} while (v10);
	return result;
}

//----- (00436AA0) --------------------------------------------------------
int sub_436AA0(int a1) {
	int v1;     // esi
	int v2;     // ebx
	short* v3;  // eax
	int v4;     // edi
	int v5;     // ebp
	int v6;     // ecx
	int v7;     // esi
	int v8;     // ebp
	int v9;     // edi
	int v10;    // eax
	int v11;    // eax
	bool v12;   // cc
	int result; // eax
	int v14;    // [esp-4h] [ebp-18h]
	int v15;    // [esp+10h] [ebp-4h]
	int v16;    // [esp+18h] [ebp+4h]

	v1 = nox_xxx_guiFontHeightMB_43F320(0);
	v2 = v1 + 30;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v14 = v1 - nox_xxx_guiFontHeightMB_43F320(0);
	v3 = (short*)nox_strman_loadString_40F1D0("FPS", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 368);
	nox_xxx_drawString_43F6E0(0, v3, 0, v14);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 956));
	v4 = v1;
	v5 = 4;
	do {
		nox_client_drawAddPoint_49F500(0, v4);
		nox_client_drawAddPoint_49F500(nox_win_width, v4);
		nox_client_drawLineFromPoints_49E4B0();
		v4 += 10;
		--v5;
	} while (v5);
	nox_client_drawAddPoint_49F500(0, v1);
	nox_client_drawAddPoint_49F500(0, v1 + 30);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(nox_win_width - 1, v1);
	nox_client_drawAddPoint_49F500(nox_win_width - 1, v1 + 30);
	nox_client_drawLineFromPoints_49E4B0();
	v6 = *getMemU32Ptr(0x5D4594, 812968) + 1;
	*getMemU32Ptr(0x5D4594, 812456 + 4 * *getMemU32Ptr(0x5D4594, 812968)) = 10 * a1 / 10;
	*getMemU32Ptr(0x5D4594, 812968) = v6 % 128;
	v7 = v6 % 128;
	v16 = 127;
	v8 = nox_win_width / 128;
	v9 = 0;
	do {
		v15 = (v7 + 1) % 128;
		v10 = *getMemU32Ptr(0x5D4594, 812456 + 4 * v7);
		if (v10 >= 10) {
			v12 = v10 < 20;
			v11 = *getMemU32Ptr(0x5D4594, 2589772);
			if (!v12) {
				v11 = *getMemU32Ptr(0x8531A0, 2572);
			}
		} else {
			v11 = *getMemU32Ptr(0x85B3FC, 940);
		}
		nox_client_drawSetColor_434460(v11);
		nox_client_drawAddPoint_49F500(v9, v2 - *getMemU32Ptr(0x5D4594, 812456 + 4 * v7));
		v7 = (v7 + 1) % 128;
		v9 += v8;
		nox_client_drawAddPoint_49F500(v9, v2 - *getMemU32Ptr(0x5D4594, 812456 + 4 * v15));
		nox_client_drawLineFromPoints_49E4B0();
		result = --v16;
	} while (v16);
	return result;
}

//----- (00436C40) --------------------------------------------------------
int nox_xxx_drawTimingMB_436C40() {
	short* v0;     // eax
	int v1;        // ecx
	signed int v2; // edx
	signed int v3; // edx
	int v4;        // ebx
	int v5;        // ebp
	int v6;        // edi
	int v7;        // esi
	int v8;        // ebp
	bool v9;       // zf
	int result;    // eax
	int v11;       // [esp-4h] [ebp-Ch]
	int v12;       // [esp+0h] [ebp-8h]
	int v13;       // [esp+4h] [ebp-4h]

	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v11 = 60 - nox_xxx_guiFontHeightMB_43F320(0);
	v0 = (short*)nox_strman_loadString_40F1D0("CSTiming", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 428);
	nox_xxx_drawString_43F6E0(0, v0, 0, v11);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 956));
	nox_client_drawBorderLines_49CC70(0, 60, nox_win_width, 31);
	v1 = *getMemU32Ptr(0x5D4594, 813996);
	v2 = 30 * *getMemU32Ptr(0x5D4594, 811928) / 0x64u;
	*getMemU32Ptr(0x5D4594, 812972 + 4 * *getMemU32Ptr(0x5D4594, 813996)) = v2;
	if (v2 > 30) {
		*getMemU32Ptr(0x5D4594, 812972 + 4 * v1) = 30;
	}
	v3 = 30 * *getMemU32Ptr(0x5D4594, 811936) / 0x64u;
	*getMemU32Ptr(0x5D4594, 813484 + 4 * v1) = v3;
	if (v3 > 30) {
		*getMemU32Ptr(0x5D4594, 813484 + 4 * v1) = 30;
	}
	v4 = (v1 + 1) % 128;
	*getMemU32Ptr(0x5D4594, 813996) = (v1 + 1) % 128;
	v12 = 127;
	v5 = nox_win_width / 128;
	v13 = nox_win_width / 128;
	v6 = 0;
	while (1) {
		v7 = (v4 + 1) % 128;
		nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 980));
		nox_client_drawAddPoint_49F500(v6, 90 - *getMemU32Ptr(0x5D4594, 812972 + 4 * v4));
		v8 = v6 + v5;
		nox_client_drawAddPoint_49F500(v8, 90 - *getMemU32Ptr(0x5D4594, 812972 + 4 * v7));
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 940));
		nox_client_drawAddPoint_49F500(v6, 90 - *getMemU32Ptr(0x5D4594, 813484 + 4 * v4));
		nox_client_drawAddPoint_49F500(v8, 90 - *getMemU32Ptr(0x5D4594, 813484 + 4 * v7));
		nox_client_drawLineFromPoints_49E4B0();
		v6 = v8;
		result = v12 - 1;
		v9 = v12 == 1;
		v4 = (v4 + 1) % 128;
		--v12;
		if (v9) {
			break;
		}
		v5 = v13;
	}
	return result;
}

//----- (00436DF0) --------------------------------------------------------
int nox_xxx_drawPing_436DF0(int a1) {
	int v1;     // esi
	short* v2;  // eax
	int v3;     // eax
	int v4;     // edx
	int v5;     // edi
	int v6;     // ebp
	int v7;     // ebx
	int v8;     // eax
	int v9;     // eax
	bool v10;   // cc
	bool v11;   // zf
	int result; // eax
	int v13;    // [esp-4h] [ebp-18h]
	int v14;    // [esp+10h] [ebp-4h]
	int v15;    // [esp+18h] [ebp+4h]

	v1 = nox_win_height - 80;
	v14 = nox_win_height - 80 + 30;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v13 = v1 - nox_xxx_guiFontHeightMB_43F320(0);
	v2 = (short*)nox_strman_loadString_40F1D0("Ping", 0, "C:\\NoxPost\\src\\client\\System\\client.c", 478);
	nox_xxx_drawString_43F6E0(0, v2, 0, v13);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 956));
	nox_client_drawBorderLines_49CC70(0, v1, nox_win_width, 31);
	v3 = *getMemU32Ptr(0x5D4594, 814512);
	v4 = 30 * a1 / 500;
	*getMemU32Ptr(0x5D4594, 814000 + 4 * *getMemU32Ptr(0x5D4594, 814512)) = v4;
	if (v4 > 30) {
		*getMemU32Ptr(0x5D4594, 814000 + 4 * v3) = 30;
	}
	v5 = (v3 + 1) % 128;
	*getMemU32Ptr(0x5D4594, 814512) = (v3 + 1) % 128;
	v15 = 127;
	v6 = nox_win_width / 128;
	v7 = 0;
	do {
		v8 = *getMemU32Ptr(0x5D4594, 814000 + 4 * v5);
		if (v8 >= 100) {
			v10 = v8 < 350;
			v9 = *getMemU32Ptr(0x5D4594, 2589772);
			if (!v10) {
				v9 = *getMemU32Ptr(0x85B3FC, 940);
			}
		} else {
			v9 = *getMemU32Ptr(0x8531A0, 2572);
		}
		nox_client_drawSetColor_434460(v9);
		nox_client_drawAddPoint_49F500(v7, v14 - *getMemU32Ptr(0x5D4594, 814000 + 4 * v5));
		nox_client_drawAddPoint_49F500(v7 + v6, v14 - *getMemU32Ptr(0x5D4594, 814000 + 4 * ((v5 + 1) % 128)));
		nox_client_drawLineFromPoints_49E4B0();
		v7 += v6;
		result = v15 - 1;
		v11 = v15 == 1;
		v5 = (v5 + 1) % 128;
		--v15;
	} while (!v11);
	return result;
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
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
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
