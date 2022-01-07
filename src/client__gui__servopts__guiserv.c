#include "client__gui__servopts__guiserv.h"
#include "client__gui__window.h"
#include "common__strman.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME5_2.h"
#include "MixPatch.h"
#include "client__video__draw_common.h"
#include "common__magic__speltree.h"
#include "defs.h"
#include "operators.h"
#include "server__script__builtin.h"

#include "client__gui__gamewin__gamewin.h"
#include "client__gui__servopts__playrlst.h"
#include "client__system__parsecmd.h"

extern nox_window* dword_5d4594_1046512;
extern uint32_t dword_587000_129656;
extern uint32_t dword_5d4594_1046360;
extern uint32_t dword_5d4594_1046524;
extern uint32_t dword_5d4594_1046356;
extern uint32_t dword_5d4594_1046540;
extern uint32_t dword_5d4594_1046536;
extern uint32_t dword_5d4594_1046528;
extern uint32_t dword_5d4594_1046500;
extern uint32_t dword_5d4594_1046520;
extern uint32_t dword_5d4594_1046504;
extern uint32_t dword_5d4594_1046516;
extern uint32_t dword_5d4594_1046532;
extern uint32_t dword_5d4594_1046508;
extern uint32_t dword_5d4594_1046496;
extern uint32_t dword_5d4594_1046492;
extern int nox_win_width;
extern int nox_win_height;

typedef struct {
	const char* name;
	const wchar_t* title;
	unsigned int mode;
	bool hide;
} nox_gui_gamemode;

nox_gui_gamemode nox_gui_gamemodes[] = {
	{"CTF", 0, 0x20, 0},      {"Arena", 0, 0x100, 0},  {"Highlander", 0, 0x400, 0},     {"KotR", 0, 0x10, 0},
	{"Flagball", 0, 0x40, 0}, {"Quest", 0, 0x1000, 1}, {"Noxworld.c:Chat", 0, 0x80, 0}, {0},
};
int nox_gui_gamemode_cnt = sizeof(nox_gui_gamemodes) / sizeof(nox_gui_gamemode) - 1;

int nox_gui_gamemode_loaded_1046548 = 0;

//----- (00457410) --------------------------------------------------------
void nox_gui_gamemode_load_457410() {
	if (nox_gui_gamemode_loaded_1046548) {
		return;
	}
	for (int i = 0; i < nox_gui_gamemode_cnt; i++) {
		nox_gui_gamemode* p = &nox_gui_gamemodes[i];
		if (!p->name) {
			break;
		}
		p->title = nox_strman_loadString_40F1D0(p->name, 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 212);
	}
	nox_gui_gamemode_loaded_1046548 = 1;
}

//----- (004573C0) --------------------------------------------------------
wchar_t* nox_xxx_guiServerOptionsGetGametypeName_4573C0(short mode) {
	mode &= 0x17F0;

	if (!nox_gui_gamemode_loaded_1046548) {
		nox_gui_gamemode_load_457410();
	}

	for (int i = 0; i < nox_gui_gamemode_cnt; i++) {
		nox_gui_gamemode* p = &nox_gui_gamemodes[i];
		if (p->mode == mode) {
			return p->title;
		}
	}
	return nox_gui_gamemodes[1].title;
}

//----- (00457A10) --------------------------------------------------------
void sub_457A10() {
	uint32_t* v0; // eax
	uint32_t* v1; // esi
	int v3;       // eax
	int v6;       // edi
	int v7;       // edx

	v0 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10120);
	v1 = v0;

	int max = 0;
	int cnt = 0;
	for (int i = 0; i < nox_gui_gamemode_cnt; i++) {
		nox_gui_gamemode* p = &nox_gui_gamemodes[i];
		if (p->hide) {
			continue;
		}
		cnt++;
		int w = 0;
		nox_xxx_drawGetStringSize_43F840(v1[59], p->title, &w, 0, 0);
		if (w > max) {
			max = w;
		}
	}
	v3 = cnt * (nox_xxx_guiFontHeightMB_43F320(v0[59]) + 1);
	v1[7] = v1[5] + v3 + 2;
	v1[3] = v3 + 2;
	v6 = max + 7;
	v7 = v1[6] - v6;
	v1[2] = v6;
	v1[4] = v7;
}

//----- (00459650) --------------------------------------------------------
int sub_459650(wchar_t* title) {
	for (int i = 0; i < nox_gui_gamemode_cnt; i++) {
		nox_gui_gamemode* p = &nox_gui_gamemodes[i];
		if (!nox_wcscmp(p->title, title)) {
			return p->mode;
		}
	}
	return 0;
}

//----- (00459C10) --------------------------------------------------------
int sub_459C10() {
	wchar_t* v0; // eax

	v0 = (wchar_t*)nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10119);
	return sub_459650(v0 + 54);
}

//----- (004596A0) --------------------------------------------------------
void nox_xxx_windowServerOptionsFillGametypeList_4596A0() {
	void* v0 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10120);
	nox_window_call_field_94(v0, 16399, 0, 0);

	for (int i = 0; i < nox_gui_gamemode_cnt; i++) {
		nox_gui_gamemode* p = &nox_gui_gamemodes[i];
		if (!p->hide) {
			nox_window_call_field_94(v0, 16397, p->title, -1);
		}
	}
}

//----- (00457500) --------------------------------------------------------
int nox_xxx_guiServerOptsLoad_457500() {
	int v1;        // esi
	uint32_t* v2;  // eax
	uint32_t* v3;  // eax
	uint32_t* v4;  // edi
	char* v5;      // ebx
	uint32_t* v6;  // esi
	uint32_t* v7;  // ebp
	uint32_t* v8;  // eax
	char* v9;      // esi
	wchar_t* v10;  // esi
	wchar_t* v11;  // eax
	wchar_t* v12;  // eax
	uint32_t* v13; // eax
	char* v14;     // [esp+0h] [ebp-8h]
	uint32_t* v15; // [esp+4h] [ebp-4h]

	if (!nox_gui_xxx_check_446360()) {
		if (dword_5d4594_1046492) {
			nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
			nox_xxx_guiServerOptionsTryHide_4574D0();
			return 1;
		}
		if (nox_common_gameFlags_check_40A5C0(1)) {
			sub_459D50(1);
			if (dword_587000_129656) {
				nox_common_list_clear_425760(getMemAt(0x5D4594, 1045956));
			}
		}
		v1 = nox_strman_get_lang_code();
		if (nox_xxx_guiFontHeightMB_43F320(0) > 10) {
			v1 = 2;
		}
		dword_5d4594_1046492 = nox_new_window_from_file(*(const char**)getMemAt(0x587000, 129760 + 4 * v1),
														nox_xxx_guiServerOptionsProcPre_4585D0);
		nox_draw_setTabWidth_43FE20(100);
		nox_window_setPos_46A9B0(*(uint32_t**)&dword_5d4594_1046492,
								 nox_win_width - *(uint32_t*)(dword_5d4594_1046492 + 8) - 10, 0);
		nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1046492, nox_xxx_guiServerOptionsProc_458590);
		nox_xxx_wndSetDrawFn_46B340(*(int*)&dword_5d4594_1046492, nox_xxx_windowServerOptionsDrawProc_458500);
		dword_5d4594_1046512 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10101);
		dword_5d4594_1046496 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10114);
		dword_5d4594_1046500 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10183);
		dword_5d4594_1046504 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10197);
		dword_5d4594_1046508 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10199);
		dword_5d4594_1046524 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10150);
		dword_5d4594_1046516 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10134);
		dword_5d4594_1046520 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10135);
		dword_5d4594_1046536 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10153);
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10331);
		nox_gui_winSetFunc96_46B070((int)v2, nox_xxx_options_457AA0);
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10333);
		nox_gui_winSetFunc96_46B070((int)v3, nox_xxx_options_457B00);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046524, *(int*)&dword_5d4594_1046492);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046532, *(int*)&dword_5d4594_1046492);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046536, *(int*)&dword_5d4594_1046492);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046500, *(int*)&dword_5d4594_1046492);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046504, *(int*)&dword_5d4594_1046492);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046508, *(int*)&dword_5d4594_1046492);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046524, nox_xxx_guiServerOptionsProcPre_4585D0);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046532, nox_xxx_guiServerOptionsProcPre_4585D0);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046536, nox_xxx_guiServerOptionsProcPre_4585D0);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046500, nox_xxx_guiServerOptionsProcPre_4585D0);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046504, nox_xxx_guiServerOptionsProcPre_4585D0);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046508, nox_xxx_guiServerOptionsProcPre_4585D0);
		*getMemU32Ptr(0x5D4594, 1046352) = nox_xxx_gLoadImg_42F970("UITabs1");
		dword_5d4594_1046356 = nox_xxx_gLoadImg_42F970("UITabs2");
		dword_5d4594_1046360 = nox_xxx_gLoadImg_42F970("UITabs3");
		v4 = *(uint32_t**)(dword_5d4594_1046496 + 32);
		v14 = nox_xxx_gLoadImg_42F970("UISlider");
		v5 = nox_xxx_gLoadImg_42F970("UISliderLit");
		v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046500, 10182);
		v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046500, 10180);
		v15 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046500, 10181);
		*(uint32_t*)(v6[100] + 8) = 16;
		*(uint32_t*)(v6[100] + 12) = 10;
		sub_4B5700((int)v6, 0, 0, (int)v14, (int)v5, (int)v5);
		nox_xxx_wnd_46B280((int)v6, *(int*)&dword_5d4594_1046496);
		nox_xxx_wnd_46B280((int)v7, *(int*)&dword_5d4594_1046496);
		nox_xxx_wnd_46B280((int)v15, *(int*)&dword_5d4594_1046496);
		v4[9] = v6;
		v4[7] = v7;
		v4[8] = v15;
		v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10160);
		v8[9] |= 4u;
		v9 = sub_4165D0(0);
		if (nox_common_gameFlags_check_40A5C0(1)) {
			sub_4161E0();
		}
		nox_gui_gamemode_load_457410();
		sub_457B60((int)v9);
		sub_457A10();
		if (nox_common_gameFlags_check_40A5C0(1)) {
			sub_4165F0(0, 1);
			sub_4165D0(1);
		} else {
			v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10159);
			v11 = nox_strman_loadString_40F1D0("servopts.wnd:teams", 0,
											   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1811);
			nox_window_call_field_94((int)v10, 16385, (int)v11, -1);
			v12 = nox_strman_loadString_40F1D0("servopts.wnd:TeamTT", 0,
											   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1812);
			nox_xxx_wndWddSetTooltip_46B000(v10 + 18, v12);
			v13 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10149);
			nox_window_set_hidden((int)v13, 0);
			nox_window_set_hidden(*(int*)&dword_5d4594_1046508, 1);
			sub_46ACE0(*(uint32_t**)&dword_5d4594_1046492, 10145, 10146, 1);
		}
		if (dword_587000_129656) {
			if (sub_4D6F30() || nox_xxx_isQuest_4D6F50()) {
				nox_server_parseCmdText_443C80(L"execrul OTQuest.rul", 1);
			} else if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				nox_server_parseCmdText_443C80(L"execrul server.rul", 1);
			}
		}
		dword_587000_129656 = 0;
	}
	return 1;
}

//----- (00457AA0) --------------------------------------------------------
int nox_xxx_options_457AA0(int a1, uint8_t* a2) {
	wchar_t* v2; // eax

	if (*a2 & 4) {
		v2 = nox_strman_loadString_40F1D0("AutoAssignOnTT", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
										  446);
	} else {
		v2 = nox_strman_loadString_40F1D0("AutoAssignOffTT", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
										  450);
	}
	nox_xxx_cursorSetTooltip_4776B0(v2);
	return 1;
}

//----- (00457B00) --------------------------------------------------------
int nox_xxx_options_457B00(int a1, uint8_t* a2) {
	wchar_t* v2; // eax

	if (*a2 & 4) {
		v2 = nox_strman_loadString_40F1D0("TeamDamageOnTT", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
										  465);
	} else {
		v2 = nox_strman_loadString_40F1D0("TeamDamageOffTT", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
										  469);
	}
	nox_xxx_cursorSetTooltip_4776B0(v2);
	return 1;
}

//----- (00457FE0) --------------------------------------------------------
int sub_457FE0() {
	uint32_t* v0; // esi
	wchar_t* v1;  // eax
	wchar_t* v2;  // eax
	wchar_t* v3;  // eax
	wchar_t* v5;  // [esp-4h] [ebp-8h]
	wchar_t* v6;  // [esp-4h] [ebp-8h]

	v0 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10210);
	if (nox_common_gameFlags_check_40A5C0(0x4000)) {
		v5 = nox_strman_loadString_40F1D0("Servopts.wnd:Individual", 0,
										  "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 380);
		v1 = nox_strman_loadString_40F1D0("Servopts.wnd:Ladder", 0,
										  "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 379);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1045700), L"%s %s", v1, v5);
	} else if (nox_common_gameFlags_check_40A5C0(0x8000)) {
		v6 = nox_strman_loadString_40F1D0("Servopts.wnd:Clan", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
										  385);
		v2 = nox_strman_loadString_40F1D0("Servopts.wnd:Ladder", 0,
										  "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 384);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1045700), L"%s %s", v2, v6);
	} else {
		v3 = nox_strman_loadString_40F1D0("WindowDir:Empty", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
										  389);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1045700), v3);
	}
	return nox_window_call_field_94((int)v0, 16385, (int)getMemAt(0x5D4594, 1045700), -1);
}

//----- (004580E0) --------------------------------------------------------
int sub_4580E0(int a1) {
	wchar_t* v1;  // eax
	wchar_t* v2;  // eax
	short v3;     // ax
	wchar_t* v4;  // eax
	wchar_t* v5;  // eax
	uint32_t* v6; // eax
	uint32_t* v7; // eax
	uint32_t* v8; // eax
	int v10;      // [esp-4h] [ebp-4h]

	v1 = nox_strman_loadString_40F1D0("SettingsMsg", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 736);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1045968), v1, a1);
	if (nox_common_gameFlags_check_40A5C0(128)) {
		v2 = nox_strman_loadString_40F1D0("GameType", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 739);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1046096), v2);
	} else {
		v3 = nox_common_gameFlags_getVal_40A5B0();
		v10 = nox_xxx_guiServerOptionsGetGametypeName_4573C0(v3);
		v4 = nox_strman_loadString_40F1D0("GameTypeIs", 0, (const char*)getMemAt(0x587000, 131072), 743);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1046096), v4, v10);
	}
	if (nox_common_gameFlags_check_40A5C0(1)) {
		v5 = nox_strman_loadString_40F1D0("GoMessage", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 748);
	} else {
		v5 = nox_strman_loadString_40F1D0("OptsMessage", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 752);
	}
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1046224), v5);
	v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10121);
	nox_window_call_field_94((int)v6, 16385, (int)getMemAt(0x5D4594, 1045968), -1);
	v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10118);
	nox_window_call_field_94((int)v7, 16385, (int)getMemAt(0x5D4594, 1046096), -1);
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10117);
	return nox_window_call_field_94((int)v8, 16385, (int)getMemAt(0x5D4594, 1046224), -1);
}

//----- (00458230) --------------------------------------------------------
void nox_client_guiserv_updateMapList_458230(int mode, char* current, bool a3) {
	char v19[58];
	char v20[58];
	wchar_t v21[100];

	nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16399, 0, 0);
	int v18 = -1;
	*getMemU32Ptr(0x5D4594, 1046552) = mode;
	int v17 = 0;
	for (nox_map_list_item* it = nox_common_maplist_first_4D09B0(); it; it = nox_common_maplist_next_4D09C0(it)) {
		if (!it->field_6) {
			continue;
		}
		if ((sub_4CFFC0(it) & mode) == 0) {
			continue;
		}
		strcpy(v19, it->name);
		memcpy(v20, v19, 0x38u);
		*(uint16_t*)&v20[56] = *(uint16_t*)&v19[56];
		sub_57A1E0((int*)v19, 0, 0, 1, mode);
		sub_57A1E0((int*)v20, "user.rul", 0, 3, mode);
		int v6 = -1;
		for (int i = 0; i < 20; i += 4) {
			if (*(uint32_t*)&v19[i + 24] != *(uint32_t*)&v20[i + 24]) {
				v6 = 6;
			}
		}
		if (v6 == -1) {
			for (int j = 0; j < 4; ++j) {
				if (v19[j + 44] != v20[j + 44]) {
					v6 = 6;
				}
			}
			if (v6 == -1 && *(uint32_t*)&v19[48] != *(uint32_t*)&v20[48]) {
				v6 = 6;
			}
		}
		int v16 = it->field_8_1;
		int v15 = it->field_8_0;
		wchar_t* v9 =
			nox_strman_loadString_40F1D0("RecPlayers", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 823);
		nox_swprintf(v21, v9, it->name, v15, v16);
		nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16397, v21, v6);
		if (_strcmpi(current, it->name) == 0) {
			v18 = v17;
			nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16403, v17, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16412, v17, 0);
		}
		++v17;
	}
	if (v18 < 0) {
		nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16403, 0, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16412, 0, 0);
	}
	if (!a3) {
		return;
	}
	char* v11 = sub_4165B0();
	int v12 = nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16404, 0, 0);
	if (v12 < 0) {
		*v11 = 0;
	} else {
		int v13 = nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16406, v12, 0);
		nox_sprintf((char*)v21, "%S", v13);
		char* v14 = strtok((char*)v21, "\t");
		if (!v14) {
			*v11 = 0;
		} else {
			strcpy(v11, v14);
		}
	}
	sub_57A1E0((int*)v11, "user.rul", 0, 7, mode);
	sub_459880((int)v11);
}
//----- (004585D0) --------------------------------------------------------
int nox_xxx_guiServerOptionsProcPre_4585D0(int a1, unsigned int a2, int a3, int a4) {
	uint32_t* v4;           // esi
	char* v5;               // ebp
	int result;             // eax
	int v7;                 // eax
	int v8;                 // ebx
	int v9;                 // edi
	int* v10;               // eax
	int v11;                // edi
	uint32_t* v12;          // esi
	uint32_t* v13;          // eax
	uint32_t* v14;          // eax
	uint32_t* v15;          // eax
	int v16;                // edi
	uint32_t* v17;          // eax
	char* v18;              // esi
	int v19;                // edi
	short v20;              // ax
	bool v21;               // cc
	wchar_t* v22;           // eax
	wchar_t* v23;           // eax
	wchar_t* v24;           // eax
	char* v25;              // esi
	uint32_t* v26;          // esi
	int v27;                // edi
	int v28;                // eax
	char* v29;              // esi
	uint32_t* v30;          // edi
	int v31;                // eax
	wchar_t* v32;           // ebp
	int v33;                // edi
	unsigned int v34;       // ecx
	int v35;                // eax
	char* v36;              // edi
	char* v37;              // ebx
	wchar_t* v38;           // [esp-10h] [ebp-F0h]
	wchar_t* v39;           // [esp-10h] [ebp-F0h]
	wchar_t WideCharStr[4]; // [esp+10h] [ebp-D0h]
	char v41[100];          // [esp+18h] [ebp-C8h]
	char v42[100];          // [esp+7Ch] [ebp-64h]

	if (a2 > 16391) {
		if (a2 == 16400) {
			v28 = nox_xxx_wndGetID_46B0A0((int*)a3) - 10114;
			if (v28) {
				if (v28 == 6) {
					v29 = sub_4165B0();
					v30 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10119);
					v31 = nox_window_call_field_94(a3, 16404, 0, 0);
					if (v31 >= 0 && v31 < *(short*)(*(uint32_t*)(a3 + 32) + 44)) {
						v32 = (wchar_t*)nox_window_call_field_94(a3, 16406, a4, 0);
						nox_window_call_field_94((int)v30, 16385, (int)v32, -1);
						v33 = *((uint16_t*)v29 + 26) & 0x17F0;
						*((uint16_t*)v29 + 26) &= 0xE80Fu;
						*((uint16_t*)v29 + 26) |= sub_459650(v32);
						if (v33 != (*((uint16_t*)v29 + 26) & 0x17F0)) {
							nox_client_guiserv_updateMapList_458230(*((unsigned short*)v29 + 26),
																	(char*)getMemAt(0x5D4594, 1046556), 1);
						}
						nox_window_set_hidden(a3, 1);
						nox_xxx_wndClearCaptureMain_46ADE0(a3);
						*((uint16_t*)v29 + 27) = nox_xxx_servGamedataGet_40A020(*((uint16_t*)v29 + 26));
						v29[56] = sub_40A180(*((uint16_t*)v29 + 26));
						sub_457460((int)v29);
						sub_459D50(1);
						if (v29[53] & 0x10) {
							nox_xxx_spellEnableAll_424BD0();
							sub_4537F0();
							sub_459700();
						}
						LOWORD(v34) = *((uint16_t*)v29 + 26);
						sub_457F30((v34 >> 12) & 1);
						return 1;
					}
				}
			} else if (nox_window_call_field_94(a3, 16404, 0, 0) >= 0) {
				v35 = nox_window_call_field_94(a3, 16406, a4, 0);
				nox_sprintf(v42, "%S", v35);
				v36 = strtok(v42, "\t");
				v37 = sub_4165B0();
				if (!v36) {
					v36 = "";
				}
				strcpy(v37, v36);
				sub_57A1E0((int*)v37, "user.rul", 0, 7, *((uint16_t*)v37 + 26));
				sub_459880((int)v37);
				sub_459D50(1);
			}
		}
		return 1;
	}
	if (a2 == 16391) {
		v9 = nox_xxx_wndGetID_46B0A0((int*)a3);
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
		switch (v9) {
		case 10119:
			v26 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10120);
			nox_window_set_hidden((int)v26, 0);
			nox_xxx_wndSetCaptureMain_46ADC0((int)v26);
			nox_xxx_wndShowModalMB_46A8C0((int)v26);
			nox_xxx_windowServerOptionsFillGametypeList_4596A0();
			return 1;
		case 10122:
			v27 = (*(uint8_t*)(a3 + 36) & 4) != 0;
			if (!nox_common_gameFlags_check_40A5C0(49152)) {
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046500, v27);
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046504, v27);
			}
			sub_459D50(1);
			return 1;
		case 10141:
			sub_459700();
			return 1;
		case 10145:
			v18 = nox_xxx_cliGamedataGet_416590(1);
			sub_459AA0((int)v18);
			sub_4165F0(1, 0);
			v19 = nox_xxx_getTeamCounter_417DD0();
			if (nox_common_gameFlags_check_40A5C0(128) && (v20 = *((uint16_t*)v18 + 26), v20 & 0x60)) {
				if (v20 < 0) {
					v21 = v19 <= 2;
				} else {
					v21 = v19 <= 2;
					if (v19 < 2) {
						v22 = nox_strman_loadString_40F1D0("NeedTeams", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1363);
						nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_1046492,
														  (int)getMemAt(0x5D4594, 1046560), (int)v22, 56, sub_459150,
														  0);
						sub_44A360(1);
						return 1;
					}
				}
				if (!v21) {
					v38 = nox_strman_loadString_40F1D0("TooManyTeams", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1371);
					v23 = nox_strman_loadString_40F1D0("Notice", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1370);
					nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_1046492, (int)v23, (int)v38, 33, 0, 0);
					sub_44A360(1);
					return 1;
				}
			} else if (nox_common_gameFlags_check_40A5C0(128) && nox_common_gameFlags_check_40A5C0(16) &&
					   nox_xxx_CheckGameplayFlags_417DA0(4) && v19 > 2) {
				v39 = nox_strman_loadString_40F1D0("TooManyTeams", 0,
												   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1384);
				v24 = nox_strman_loadString_40F1D0("Notice", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
												   1383);
				nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_1046492, (int)v24, (int)v39, 33, 0, 0);
				sub_44A360(1);
				return 1;
			}
			sub_459150();
#ifndef NOX_CGO
			OnLibraryNotice_261();
#endif // NOX_CGO
			result = 1;
			break;
		case 10146:
			v25 = sub_4165B0();
			if (nox_common_gameFlags_check_40A5C0(128)) {
				if ((int)v25[53] < 0) {
					nox_server_teamsZzz_419030(1);
				}
				*((uint16_t*)v25 + 26) &= 0x3FFFu;
			}
			goto LABEL_58;
		case 10149:
		LABEL_58:
			nox_xxx_guiServerOptionsHide_4597E0(0);
			return 1;
		case 10152:
			v10 = (int*)nox_xxx_cliGamedataGet_416590(1);
			nox_xxx_loadAdvancedWnd_4BDC10(v10);
			return 1;
		case 10159:
			v11 = *(uint32_t*)(a3 + 396);
			sub_46B120((uint32_t*)a3, 0);
			sub_46B120((uint32_t*)a3, v11);
			v12 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10196);
			if (nox_common_gameFlags_check_40A5C0(1)) {
				nox_window_set_hidden((int)v12, 0);
				sub_46ACE0(*(uint32_t**)&dword_5d4594_1046492, 10161, 10163, 0);
				sub_46AD20(*(uint32_t**)&dword_5d4594_1046492, 10161, 10163, 1);
				sub_4593B0(0);
				v13 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10163);
				v13[9] |= 4u;
				v14 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10161);
				v14[9] &= 0xFFFFFFFB;
				v15 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10162);
				v15[9] &= 0xFFFFFFFB;
				sub_46ACE0(*(uint32_t**)&dword_5d4594_1046492, 10141, 10141, 1);
			} else {
				nox_window_set_hidden((int)v12, 1);
				dword_5d4594_1046532 = nox_xxx_guiServerPlayersLoad_456270(*(int*)&dword_5d4594_1046492);
				sub_46ACE0(*(uint32_t**)&dword_5d4594_1046492, 10141, 10141, 1);
			}
			nox_window_set_hidden(*(int*)&dword_5d4594_1046524, 1);
			return 1;
		case 10160:
			v16 = *(uint32_t*)(a3 + 396);
			sub_46B120((uint32_t*)a3, 0);
			sub_46B120((uint32_t*)a3, v16);
			if (dword_5d4594_1046532) {
				sub_456D60(1);
				dword_5d4594_1046532 = 0;
			}
			if (dword_5d4594_1046528) {
				sub_4557D0(1);
				dword_5d4594_1046528 = 0;
			}
			if (dword_5d4594_1046536) {
				sub_4AD820();
				dword_5d4594_1046540 = 0;
			}
			sub_46ACE0(*(uint32_t**)&dword_5d4594_1046492, 10161, 10163, 1);
			if (nox_common_gameFlags_check_40A5C0(1)) {
				sub_46ACE0(*(uint32_t**)&dword_5d4594_1046492, 10141, 10141, 0);
			}
			v17 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10196);
			nox_window_set_hidden((int)v17, 1);
			nox_window_set_hidden(*(int*)&dword_5d4594_1046524, 0);
			return 1;
		case 10161:
			sub_4593B0(1);
			return 1;
		case 10162:
			sub_4593B0(2);
			return 1;
		case 10163:
			sub_4593B0(0);
			return 1;
		case 10330:
			if (nox_xxx_CheckGameplayFlags_417DA0(4)) {
				nox_xxx_toggleAllTeamFlags_418690(0);
				nox_server_teamsZzz_419030(1);
				sub_46AD20(*(uint32_t**)&dword_5d4594_1046508, 10331, 10333, 0);
				result = 1;
			} else {
				nox_xxx_wndGuiTeamCreate_4185B0();
				if (nox_xxx_CheckGameplayFlags_417DA0(2)) {
					sub_4181F0(0);
				} else {
					nox_xxx_toggleAllTeamFlags_418690(1);
				}
				sub_46AD20(*(uint32_t**)&dword_5d4594_1046508, 10331, 10333, 1);
				result = 1;
			}
			return result;
		case 10331:
			if (nox_xxx_CheckGameplayFlags_417DA0(2)) {
				nox_xxx_UnsetGameplayFlags_417D70(2);
				nox_xxx_toggleAllTeamFlags_418690(1);
			} else {
				nox_xxx_toggleAllTeamFlags_418690(0);
				sub_418390();
			}
			return 1;
		case 10332:
			sub_4181F0(1);
			return 1;
		case 10333:
			if (nox_xxx_CheckGameplayFlags_417DA0(1)) {
				nox_xxx_UnsetGameplayFlags_417D70(1);
			} else {
				nox_xxx_SetGameplayFlag_417D50(1);
			}
			return 1;
		default:
			return 1;
		}
		return result;
	}
	if (a2 == 23) {
		return 0;
	}
	if (a2 != 16387) {
		return 1;
	}
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, a4);
	v5 = sub_4165B0();
	if (!v4) {
		return 0;
	}
	if ((unsigned short)a3 == 1) {
		if (a4 == 10101) {
			v4[26] = *getMemU32Ptr(0x5D4594, 2523948);
			return 1;
		}
		return 1;
	}
	v7 = nox_window_call_field_94((int)v4, 16413, 0, 0);
	nox_sprintf(v41, "%S", v7);
	if (!v41[0]) { // TODO: was if (!v41 || ...
		return 1;
	}
	v8 = atoi(v41);
	if (v8 < 0) {
		v8 = 0;
	}
	if (a4 == 10101) {
		v4[26] = nox_color_rgb_4344A0(230, 165, 65);
		strcpy(v5 + 9, v41);
		nox_xxx_gameSetServername_40A440(v41);
		return 1;
	}
	if (a4 == 10134) {
		*((uint16_t*)v5 + 27) = v8;
		sub_459D50(1);
		return 1;
	}
	if (a4 != 10135) {
		return 1;
	}
	if (v8 > 255) {
		LOBYTE(v8) = -1;
		_itow(255, WideCharStr, 10);
		nox_window_call_field_94((int)v4, 16414, (int)WideCharStr, -1);
	}
	v5[56] = v8;
	sub_459D50(1);
	return 1;
}
//----- (00459880) --------------------------------------------------------
int sub_459880(int a1) {
	short v1;        // ax
	wchar_t* v2;     // eax
	uint32_t* v4;    // eax
	int v5;          // ecx
	unsigned int v6; // ecx

	v1 = *(uint16_t*)(a1 + 52);
	if (v1 & 0x20) {
		if (!*(uint8_t*)(a1 + 57) && nox_common_gameFlags_check_40A5C0(1)) {
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046516, 1);
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046520, 1);
		}
		v2 = nox_strman_loadString_40F1D0("Servopts.wnd:CaptureLimit", 0,
										  "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1900);
	} else {
		LOBYTE(v1) = *(uint8_t*)(a1 + 57);
		if (v1 & 0x400) {
			if (!LOBYTE(v1) && nox_common_gameFlags_check_40A5C0(1)) {
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046516, 1);
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046520, 1);
			}
			v2 = nox_strman_loadString_40F1D0("Servopts.wnd:DeathLimit", 0,
											  "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1912);
		} else {
			if (!LOBYTE(v1) && nox_common_gameFlags_check_40A5C0(1) && !nox_common_gameFlags_check_40A5C0(49152)) {
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046516, 1);
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046520, 1);
			}
			v2 = nox_strman_loadString_40F1D0("Servopts.wnd:KillLimit", 0,
											  "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1926);
		}
	}
	nox_wcscpy((wchar_t*)(dword_5d4594_1046516 + 108), v2);
	sub_4580E0(a1);
	sub_459A40((char*)(a1 + 9));
	if (nox_common_gameFlags_check_40A5C0(1) && !nox_common_gameFlags_check_40A5C0(49152)) {
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046500, *(uint8_t*)(a1 + 57) == 0);
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046504, *(uint8_t*)(a1 + 57) == 0);
	}
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10122);
	v5 = v4[9];
	if (*(uint8_t*)(a1 + 57)) {
		v6 = v5 | 4;
	} else {
		v6 = v5 & 0xFFFFFFFB;
	}
	v4[9] = v6;
	sub_453F70((const void*)(a1 + 24));
	sub_4535E0((int*)(a1 + 44));
	return sub_4535F0(*(uint32_t*)(a1 + 48));
}

//----- (00459CD0) --------------------------------------------------------
int sub_459CD0() {
	int result;       // eax
	unsigned char v1; // al
	wchar_t* v2;      // eax
	uint32_t* v3;     // eax
	int v4;           // [esp-4h] [ebp-4h]

	result = dword_5d4594_1046492;
	if (dword_5d4594_1046492) {
		if (sub_40A740() || nox_common_gameFlags_check_40A5C0(0x8000)) {
			v1 = sub_417DE0();
		} else {
			v1 = nox_xxx_getTeamCounter_417DD0();
		}
		v4 = v1;
		v2 = nox_strman_loadString_40F1D0("NumTeamsMsg", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 2071);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1046364), v2, v4);
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1046492, 10110);
		result = nox_window_call_field_94((int)v3, 16385, (int)getMemAt(0x5D4594, 1046364), -1);
	}
	return result;
}
