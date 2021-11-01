#include "client__gui__servopts__general.h"
#include "client__gui__window.h"
#include "common__strman.h"

#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2_1.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_2.h"
extern uint32_t nox_server_sendMotd_108752;
extern uint32_t nox_server_connectionType_3596;
extern uint32_t dword_5d4594_1309812;

//----- (004AD320) --------------------------------------------------------
int  nox_xxx_gui_4AD320(int a1) {
	int v1;      // esi
	uint32_t* v3;  // eax
	uint32_t* v4;  // esi
	uint32_t* v5;  // esi
	uint32_t* v6;  // edi
	char** v7;   // esi
	wchar_t* v8; // eax
	uint32_t* v9;  // eax
	uint32_t* v10; // eax

	v1 = nox_strman_get_lang_code();
	if (nox_xxx_guiFontHeightMB_43F320(0) > 10)
		v1 = 2;
	if (dword_5d4594_1309812)
		return 0;
	if (nox_xxx_check_flag_aaa_43AF70() == 1)
		v3 = nox_new_window_from_file(*(const char**)getMemAt(0x587000, 173596 + 4 * v1), nox_xxx_windowServerOptionsGeneralProc_4AD5D0);
	else
		v3 = nox_new_window_from_file(*(const char**)getMemAt(0x587000, 173556 + 4 * v1), nox_xxx_windowServerOptionsGeneralProc_4AD5D0);
	dword_5d4594_1309812 = v3;
	sub_46B120(v3, a1);
	nox_xxx_wndSetDrawFn_46B340(*(int*)&dword_5d4594_1309812, sub_4AD570);
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10306);
	if (nox_common_gameFlags_check_40A5C0(1056))
		nox_xxx_wnd_46ABB0((int)v4, 0);
	nox_xxx_wndRetNULL_46A8A0();
	sub_4AD840();
	if (nox_xxx_check_flag_aaa_43AF70() == 1) {
		sub_4AD4B0();
		v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10310);
		nox_xxx_wnd_46B280((int)v5, *(int*)&dword_5d4594_1309812);
		nox_xxx_wndSetProc_46B2C0((int)v5, nox_xxx_windowServerOptionsGeneralProc_4AD5D0);
		v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10317);
		v7 = (char**)getMemAt(0x587000, 173540);
		do {
			v8 = nox_strman_loadString_40F1D0(*v7, 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\general.c", 308);
			nox_window_call_field_94((int)v6, 16397, (int)v8, -1);
			++v7;
		} while ((int)v7 < (int)getMemAt(0x587000, 173556));
	} else {
		v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10319);
		nox_window_set_hidden((int)v9, 1);
	}
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10304);
		nox_xxx_wnd_46ABB0((int)v10, 0);
	}
	return dword_5d4594_1309812;
}

//----- (004AD4B0) --------------------------------------------------------
int sub_4AD4B0() {
	uint32_t* v0;           // eax
	uint32_t* v1;           // esi
	int v2;               // eax
	int v3;               // edi
	char** v4;            // ebx
	unsigned short* v5; // eax
	int result;           // eax
	int v7;               // edi
	int v8;               // ecx
	int v9;               // [esp+Ch] [ebp-4h]

	v0 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10317);
	v1 = v0;
	v2 = nox_xxx_guiFontHeightMB_43F320(v0[59]) + 1;
	v3 = 0;
	v4 = (char**)getMemAt(0x587000, 173540);
	v1[7] = v1[5] + 4 * v2 + 2;
	v1[3] = 4 * v2 + 2;
	do {
		v5 = nox_strman_loadString_40F1D0(*v4, 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\general.c", 92);
		nox_xxx_drawGetStringSize_43F840(v1[59], v5, &v9, 0, 0);
		if (v9 > v3)
			v3 = v9;
		++v4;
	} while ((int)v4 < (int)getMemAt(0x587000, 173556));
	result = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10316)->width;
	v7 = v3 + 7;
	if (v7 <= result)
		v7 = result;
	v8 = v1[6];
	v1[2] = v7;
	v1[4] = v8 - v7;
	return result;
}

//----- (004AD840) --------------------------------------------------------
int sub_4AD840() {
	int result;  // eax
	uint32_t* v1;  // esi
	uint32_t* v2;  // eax
	uint32_t* v3;  // eax
	uint32_t* v4;  // eax
	uint32_t* v5;  // eax
	uint32_t* v6;  // esi
	wchar_t* v7; // eax
	uint32_t* v8;  // esi
	int v9;      // eax

	result = dword_5d4594_1309812;
	if (dword_5d4594_1309812) {
		if (nox_server_doPlayersAutoRespawn_40A5F0()) {
			v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10301);
			v1[9] |= 4u;
			if (nox_common_gameFlags_check_40A5C0(1024))
				nox_xxx_wnd_46ABB0((int)v1, 0);
		}
		if (nox_server_sendMotd_108752) {
			v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10302);
			v2[9] |= 4u;
		}
		if (sub_4D0D70()) {
			v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10304);
			v3[9] |= 4u;
		}
		if (sub_409F40(2)) {
			v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10305);
			v4[9] |= 4u;
		}
		if (sub_409F40(0x2000)) {
			v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10306);
			v5[9] |= 4u;
		}
		result = nox_xxx_check_flag_aaa_43AF70();
		if (result == 1) {
			v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10316);
			v7 = nox_strman_loadString_40F1D0(*(char**)getMemAt(0x587000, 173536 + 4 * nox_server_connectionType_3596), 0,
									   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\general.c", 391);
			nox_window_call_field_94((int)v6, 16385, (int)v7, -1);
			v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1309812, 10312);
			v9 = nox_xxx_rateGet_40A6C0();
			result = nox_window_call_field_94((int)v8, 16394, 4 - v9, 0);
		}
	}
	return result;
}
