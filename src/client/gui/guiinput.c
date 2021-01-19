#include "guiinput.h"

#include "../../proto.h"

extern _DWORD dword_5d4594_1321236;
extern _DWORD dword_5d4594_1321240;
extern _DWORD dword_5d4594_1321252;
extern _DWORD dword_5d4594_1321232;
extern _DWORD dword_5d4594_1321248;
extern _DWORD dword_5d4594_1321244;
extern _DWORD dword_5d4594_1321228;
extern int nox_win_width;
extern int nox_win_height;

//----- (004C3620) --------------------------------------------------------
char* sub_4C3620() {
	int v0;        // ebp
	int i;         // esi
	wchar_t* v2;   // eax
	int v3;        // edi
	wchar_t* v4;   // eax
	char* v5;      // ebx
	wchar_t* v6;   // eax
	char* v7;      // eax
	wchar_t* v8;   // eax
	int v9;        // esi
	wchar_t* v10;  // eax
	char* result;  // eax
	char v12[256]; // [esp+8h] [ebp-100h]

	v0 = *(_DWORD*)(dword_5d4594_1321240 + 32);
	sub_42CD90();
	for (i = 0; i < *(__int16*)(v0 + 44); ++i) {
		v2 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1321240, 16406, i, 0);
		v3 = sub_42EA40(v2);
		v4 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1321244, 16406, i, 0);
		v5 = sub_42E960(v4);
		v6 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1321248, 16406, i, 0);
		v7 = sub_42E960(v6);
		if (v7) {
			nox_sprintf(v12, "%s = %s", v7, v3);
			sub_42CF50(v12);
		}
		if (v5) {
			nox_sprintf(v12, "%s = %s", v5, v3);
			sub_42CF50(v12);
		}
	}
	v8 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 185172), 0, "C:\\NoxPost\\src\\client\\Gui\\GuiInput.c", 191);
	v9 = sub_42EA40(v8);
	v10 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 185240), 0, "C:\\NoxPost\\src\\client\\Gui\\GuiInput.c", 192);
	result = sub_42E960(v10);
	if (result) {
		nox_sprintf(v12, "%s = %s", result, v9);
		result = (char*)sub_42CF50(v12);
	}
	return result;
}

//----- (004C3760) --------------------------------------------------------
int sub_4C3760() {
	int result;   // eax
	_DWORD** v1;  // eax
	_DWORD* v2;   // esi
	_DWORD* v3;   // esi
	int v4;       // esi
	int v5;       // edi
	_DWORD* v6;   // eax
	int v7;       // eax
	_DWORD* v8;   // eax
	_DWORD* v9;   // eax
	_DWORD* v10;  // esi
	wchar_t* v11; // eax

	result = nox_new_window_from_file("InputCfg.wnd", sub_4C3A90);
	dword_5d4594_1321228 = result;
	if (result) {
		dword_5d4594_1321236 = nox_xxx_wndGetChildByID_46B0C0((_DWORD*)result, 910);
		dword_5d4594_1321240 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321228, 911);
		dword_5d4594_1321244 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321228, 912);
		dword_5d4594_1321248 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321228, 913);
		result = dword_5d4594_1321236;
		if (dword_5d4594_1321236) {
			v1 = *(_DWORD***)(dword_5d4594_1321236 + 32);
			*v1[7] = 921;
			*v1[8] = 922;
			*v1[9] = 920;
			nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1321236, sub_4C3CD0);
			sub_46B120(*(_DWORD**)&dword_5d4594_1321240, *(int*)&dword_5d4594_1321236);
			sub_46B120(*(_DWORD**)&dword_5d4594_1321244, *(int*)&dword_5d4594_1321236);
			sub_46B120(*(_DWORD**)&dword_5d4594_1321248, *(int*)&dword_5d4594_1321236);
			nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1321244, sub_4C3A60);
			nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1321248, sub_4C3A60);
			v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321228, 921);
			nox_window_call_field_94(*(int*)&dword_5d4594_1321240, 16408, (int)v2, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1321244, 16408, (int)v2, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1321248, 16408, (int)v2, 0);
			v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321228, 922);
			nox_window_call_field_94(*(int*)&dword_5d4594_1321240, 16409, (int)v3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1321244, 16409, (int)v3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1321248, 16409, (int)v3, 0);
			v4 = 971;
			v5 = sub_47DBC0() + 971;
			if (v5 > 971) {
				do {
					v6 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321228, v4);
					nox_xxx_wnd_46ABB0((int)v6, 1);
					++v4;
				} while (v4 < v5);
			}
			v7 = nox_xxx_cursor_430AF0();
			v8 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321228, v7 + 971);
			nox_window_call_field_94((int)v8, 16392, 1, 0);
			nox_wnd_nox_xxx_wndDraw_46A9B0(*(_DWORD**)&dword_5d4594_1321228,
							   (nox_win_width - *(_DWORD*)(dword_5d4594_1321228 + 8)) / 2, 0);
			dword_5d4594_1321232 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321228, 980);
			sub_46B120(*(_DWORD**)&dword_5d4594_1321232, 0);
			nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1321232, sub_4C3A90);
			nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1321232, sub_4C3EB0);
			nox_window_set_hidden(*(int*)&dword_5d4594_1321232, 1);
			nox_wnd_nox_xxx_wndDraw_46A9B0(*(_DWORD**)&dword_5d4594_1321232,
							   (nox_win_width - *(_DWORD*)(dword_5d4594_1321232 + 8)) / 2,
							   *(_DWORD*)(dword_5d4594_1321232 + 20));
			v9 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321232, 981);
			sub_46AEE0((int)v9, (int)getMemAt(0x5D4594, 1321256));
			v10 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321228, 932);
			v11 =
				nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 185316), 0, "C:\\NoxPost\\src\\client\\Gui\\GuiInput.c", 603);
			sub_46AEE0((int)v10, (int)v11);
			nox_xxx_wnd_46ABB0((int)v10, 1);
			nox_window_set_hidden(*(int*)&dword_5d4594_1321228, 1);
			result = 1;
		}
	}
	return result;
}

//----- (004C3CD0) --------------------------------------------------------
int __cdecl sub_4C3CD0(int a1, unsigned int a2, int a3, int a4) {
	int v5;      // eax
	wchar_t* v6; // eax
	int v7;      // esi
	int v8;      // esi
	int v9;      // [esp-4h] [ebp-10h]

	if (a2 > 0x4007) {
		if (a2 == 16393) {
			v7 = *(_DWORD*)(a1 + 32);
			nox_xxx_wndListboxProcPre_4A30D0(a1, 0x4009u, (wchar_t*)a3, a4);
			v8 = sub_4A4800(v7);
			nox_window_call_field_94(*(int*)&dword_5d4594_1321240, 16412, v8, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1321244, 16412, v8, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1321248, 16412, v8, 0);
		} else if (a2 == 16400) {
			v5 = *(_DWORD*)(a3 + 32);
			if ((int)*(_DWORD*)(v5 + 48) >= 0) {
				dword_5d4594_1321252 = a3;
				v9 = nox_window_call_field_94(*(int*)&dword_5d4594_1321240, 16406, *(_DWORD*)(v5 + 48), 0);
				v6 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 185404), 0, "C:\\NoxPost\\src\\client\\Gui\\GuiInput.c",
										   436);
				nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1321256), L"%s\n'%s'", v6, v9);
				nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1321232);
				nox_xxx_windowDestroyChildsMB_46B500(*(int*)&dword_5d4594_1321232);
				sub_46C690(*(int*)&dword_5d4594_1321232);
				return nox_xxx_wndListboxProcPre_4A30D0(a1, 0x4010u, (wchar_t*)a3, a4);
			}
		}
	} else {
		if (a2 != 16391) {
			if (a2 == 23)
				return 1;
			if (a2 != 0x4000)
				return nox_xxx_wndListboxProcPre_4A30D0(a1, a2, (wchar_t*)a3, a4);
		}
		if ((_DWORD*)a3 == nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321228, 921) ||
			(_DWORD*)a3 == nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321228, 922)) {
			nox_window_call_field_94(*(int*)&dword_5d4594_1321240, a2, a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1321244, a2, a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1321248, a2, a3, 0);
			return nox_xxx_wndListboxProcPre_4A30D0(a1, a2, (wchar_t*)a3, a4);
		}
	}
	return nox_xxx_wndListboxProcPre_4A30D0(a1, a2, (wchar_t*)a3, a4);
}
