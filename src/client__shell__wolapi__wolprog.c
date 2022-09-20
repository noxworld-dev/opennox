#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "common__strman.h"
extern uint32_t dword_5d4594_1064192;

//----- (00468110) --------------------------------------------------------
int sub_468110_wol_prog() {
	int result;   // eax
	uint32_t* v1; // eax
	uint32_t* v2; // esi
	wchar_t* v3;  // eax

	result = dword_5d4594_1064192;
	if (dword_5d4594_1064192) {
		v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1064192, 1804);
		nox_window_set_hidden((int)v1, 0);
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1064192, 1805);
		v3 = nox_strman_loadString_40F1D0("startingdownload", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolprog.c",
										  192);
		result = nox_window_call_field_94((int)v2, 16385, (int)v3, 0);
	}
	return result;
}

//----- (00468170) --------------------------------------------------------
int sub_468170_wol_prog() {
	int result;   // eax
	uint32_t* v1; // esi
	int v2;       // eax
	wchar_t* v3;  // eax
	uint32_t* v4; // eax
	int v5;       // [esp+4h] [ebp-10h]
	int v6;       // [esp+8h] [ebp-Ch]
	int v7;       // [esp+Ch] [ebp-8h]
	int v8;       // [esp+10h] [ebp-4h]

	result = dword_5d4594_1064192;
	if (dword_5d4594_1064192) {
		v6 = 0;
		v5 = 0;
		v8 = 0;
		v7 = 0;
		v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1064192, 1804);
		sub_41E590(&v6, &v5, &v8, &v7);
		if (v6) {
			v2 = 100 * v6 / v5;
		} else {
			v2 = 0;
		}
		nox_window_call_field_94((int)v1, 16416, v2, 0);
		v3 = nox_strman_loadString_40F1D0("byteprogress", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolprog.c", 226);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1063680), v3, v6, v5, v8 / 3600, v8 / 60, v8 % 60, v7 / 3600, v7 / 60,
					 v7 % 60);
		v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1064192, 1805);
		result = nox_window_call_field_94((int)v4, 16385, (int)getMemAt(0x5D4594, 1063680), 0);
	}
	return result;
}

//----- (004682B0) --------------------------------------------------------
void sub_4682B0_wol_prog() {
	uint32_t* v0; // esi
	wchar_t* v1;  // eax
	uint32_t* v3; // eax
	uint32_t* v4; // eax

	if (dword_5d4594_1064192) {
		v0 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1064192, 1805);
		v1 =
			nox_strman_loadString_40F1D0("PatchComplete", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolprog.c", 250);
		if (v1) {
			nox_window_call_field_94((int)v0, 16385, (int)v1, 0);
		}
	}
	if (!sub_41E540()) {
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1064192, 1806);
		nox_window_set_hidden((int)v3, 1);
		v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1064192, 1807);
		nox_window_set_hidden((int)v4, 0);
		nox_game_exit_xxx2();
	}
}
