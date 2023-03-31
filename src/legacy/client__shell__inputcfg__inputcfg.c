#include "client__shell__inputcfg__inputcfg.h"
#include "client__system__ctrlevnt.h"

#include "GAME3.h"
#include "client__gui__window.h"
#include "common__strman.h"
extern nox_window* dword_5d4594_1522620;
extern nox_window* dword_5d4594_1522624;
extern nox_window* dword_5d4594_1522628;
extern uint32_t dword_5d4594_1522632;
extern uint32_t dword_5d4594_1522612;
extern uint32_t dword_5d4594_1522604;

//----- (004CBD30) --------------------------------------------------------
char* sub_4CBD30() {
	int v0;        // ebp
	int i;         // esi
	wchar2_t* v2;   // eax
	int v3;        // edi
	wchar2_t* v4;   // eax
	char* v5;      // ebx
	wchar2_t* v6;   // eax
	char* v7;      // eax
	wchar2_t* v8;   // eax
	int v9;        // esi
	wchar2_t* v10;  // eax
	char* result;  // eax
	char v12[256]; // [esp+8h] [ebp-100h]

	v0 = *(uint32_t*)((uint32_t)dword_5d4594_1522620 + 32);
	sub_42CD90();
	for (i = 0; i < *(short*)(v0 + 44); ++i) {
		v2 = (wchar2_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1522620, 16406, i, 0);
		v3 = nox_xxx_bindevent_bindNameByTitle_42EA40(v2);
		v4 = (wchar2_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16406, i, 0);
		v5 = nox_xxx_keybind_nameByTitle_42E960(v4);
		v6 = (wchar2_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16406, i, 0);
		v7 = nox_xxx_keybind_nameByTitle_42E960(v6);
		if (v7) {
			nox_sprintf(v12, "%s = %s", v7, v3);
			nox_client_parseConfigHotkeysLine_42CF50(v12);
		}
		if (v5) {
			nox_sprintf(v12, "%s = %s", v5, v3);
			nox_client_parseConfigHotkeysLine_42CF50(v12);
		}
	}
	v8 = nox_strman_loadString_40F1D0("bindevent:ToggleQuitMenu", 0,
									  "C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c", 192);
	v9 = nox_xxx_bindevent_bindNameByTitle_42EA40(v8);
	v10 = nox_strman_loadString_40F1D0("keybind:Esc", 0, "C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c", 193);
	result = nox_xxx_keybind_nameByTitle_42E960(v10);
	if (result) {
		nox_sprintf(v12, "%s = %s", result, v9);
		result = (char*)nox_client_parseConfigHotkeysLine_42CF50(v12);
	}
	return result;
}

//----- (004CBF60) --------------------------------------------------------
int sub_4CBF60(int a1, unsigned int a2, int a3, int a4) {
	int v5;      // eax
	wchar2_t* v6; // eax
	int v7;      // esi
	int v8;      // esi
	int v9;      // [esp-4h] [ebp-10h]

	if (a2 > 0x4007) {
		if (a2 == 16393) {
			v7 = *(uint32_t*)(a1 + 32);
			nox_xxx_wndListboxProcPre_4A30D0(a1, 0x4009u, (wchar2_t*)a3, a4);
			v8 = sub_4A4800(v7);
			nox_window_call_field_94(*(int*)&dword_5d4594_1522620, 16412, v8, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16412, v8, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16412, v8, 0);
		} else if (a2 == 16400) {
			v5 = *(uint32_t*)(a3 + 32);
			if ((int)*(uint32_t*)(v5 + 48) >= 0) {
				dword_5d4594_1522632 = a3;
				v9 = nox_window_call_field_94(*(int*)&dword_5d4594_1522620, 16406, *(uint32_t*)(v5 + 48), 0);
				v6 = nox_strman_loadString_40F1D0("InputCfg.wnd:PressKey", 0,
												  "C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c", 424);
				nox_swprintf((wchar2_t*)getMemAt(0x5D4594, 1522636), L"%s\n'%s'", v6, v9);
				nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1522612);
				nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_1522612);
				sub_46C690(*(int*)&dword_5d4594_1522612);
				return nox_xxx_wndListboxProcPre_4A30D0(a1, 0x4010u, (wchar2_t*)a3, a4);
			}
		}
	} else {
		if (a2 != 16391) {
			if (a2 == 23) {
				return 1;
			}
			if (a2 != 0x4000) {
				return nox_xxx_wndListboxProcPre_4A30D0(a1, a2, (wchar2_t*)a3, a4);
			}
		}
		if ((uint32_t*)a3 == nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1522604, 921) ||
			(uint32_t*)a3 == nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1522604, 922)) {
			nox_window_call_field_94(*(int*)&dword_5d4594_1522620, a2, a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1522624, a2, a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1522628, a2, a3, 0);
			return nox_xxx_wndListboxProcPre_4A30D0(a1, a2, (wchar2_t*)a3, a4);
		}
	}
	return nox_xxx_wndListboxProcPre_4A30D0(a1, a2, (wchar2_t*)a3, a4);
}
