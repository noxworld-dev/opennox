#include "client__shell__mainmenu.h"
#include "client__gui__window.h"

#include "common__random.h"
#include "common__strman.h"
#include "client__shell__noxworld.h"
#include "client__shell__selchar.h"
#include "client__shell__optsback.h"
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
#include "client__video__draw_common.h"
#include "input_common.h"
#include "operators.h"

extern uint32_t nox_client_gui_flag_815132;

nox_gui_animation* nox_wnd_xxx_1307308 = 0;
nox_window* nox_win_main_bg = 0;
nox_window* nox_win_main_menu = 0;

//----- (004A24F0) --------------------------------------------------------
int sub_4A24F0() { return nox_xxx_windowFocus_46B500(nox_win_main_bg); }

//----- (004A1D40) --------------------------------------------------------
int sub_4A1D40() {
	nox_wnd_xxx_1307308->state = NOX_GUI_ANIM_OUT;
	*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1307304) + 64) = 2;
	sub_43BE40(2);
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100);
	return 1;
}

//----- (004A2500) --------------------------------------------------------
int sub_4A2500() {
	nox_xxx_setFrameLimit_43DDE0(1);
	nox_window_set_hidden(nox_win_main_bg, 0);
	nox_window_set_hidden(nox_win_main_menu, 0);
	return sub_4A24F0();
}

//----- (004A2530) --------------------------------------------------------
int sub_4A2530() {
	nox_xxx_setFrameLimit_43DDE0(0);
	nox_window_set_hidden(nox_win_main_bg, 1);
	return nox_window_set_hidden(nox_win_main_menu, 1);
}

//----- (004A1D80) --------------------------------------------------------
int sub_4A1D80() {
	int (*v0)(void); // esi

	v0 = nox_wnd_xxx_1307308->field_13;
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_1307308);
	nox_gui_freeAnimation_43C570(*(void**)getMemAt(0x5D4594, 1307304));
	nox_xxx_windowDestroyMB_46C4E0(nox_win_main_menu);
	v0();
	return 1;
}

//----- (004A24C0) --------------------------------------------------------
int  sub_4A24C0(int a1) {
	uint32_t* v1; // eax
	int result; // eax

	v1 = nox_xxx_wndGetChildByID_46B0C0(nox_win_main_bg, 99);
	result = nox_window_set_hidden((int)v1, a1);
	if (!a1)
		result = sub_43E8C0(1);
	return result;
}

//----- (004A2210) --------------------------------------------------------
int nox_xxx_wndLoadMainBG_4A2210() {
	uint32_t* v1;          // esi
	const char* v2;      // eax
	unsigned char* v3; // esi

	nox_client_gui_flag_815132 = 1;
	nox_win_main_bg = nox_new_window_from_file("MainBG.wnd", sub_4A2490);
	if (!sub_4A1A60()) {
		return 0;
	}
	v1 = nox_xxx_wndGetChildByID_46B0C0(nox_win_main_bg, 98);
	nox_xxx_wndSetWindowProc_46B300((int)v1, sub_4A18E0);
	nox_xxx_wndSetDrawFn_46B340((int)v1, sub_4A22A0);
	v2 = *(const char**)getMemAt(0x587000, 168832);
	if (*getMemU32Ptr(0x587000, 168832)) {
		v3 = getMemAt(0x587000, 168832);
		do {
			*((uint32_t*)v3 + 1) = nox_xxx_gLoadImg_42F970(v2);
			v2 = (const char*)*((uint32_t*)v3 + 12);
			v3 += 48;
		} while (v2);
	}
	nox_xxx_windowFocus_46B500(nox_win_main_bg);
	return 1;
}

//----- (004A1C00) --------------------------------------------------------
int nox_game_showMainMenu_4A1C00() {
	uint32_t* v1; // esi
	uint32_t* v2; // esi
	uint32_t* v3; // eax

	sub_4D6F40(0);
	sub_4D6F90(0);
	nox_game_addStateCode_43BDD0(100);
	nox_win_main_menu = nox_new_window_from_file("MainMenu.wnd", nox_xxx_windowMainMenuProc_4A1DC0);
	if (!nox_win_main_menu) {
		return 0;
	}
	nox_xxx_wndSetWindowProc_46B300(nox_win_main_menu, sub_4A18E0);
	v1 = nox_xxx_wndGetChildByID_46B0C0(nox_win_main_menu, 110);
	nox_xxx_wndSetProc_46B2C0((int)v1, nox_xxx_windowMainMenuProc_4A1DC0);
	nox_wnd_xxx_1307308 = nox_gui_makeAnimation_43C5B0(v1, 0, 0, 0, -270, 0, 20, 0, -40);
	if (!nox_wnd_xxx_1307308) {
		return 0;
	}
	nox_wnd_xxx_1307308->field_0 = 100;
	nox_wnd_xxx_1307308->field_12 = sub_4A1D40;
	nox_wnd_xxx_1307308->fnc_done_out = sub_4A1D80;
	v2 = nox_xxx_wndGetChildByID_46B0C0(nox_win_main_menu, 120);
	nox_xxx_wndSetProc_46B2C0((int)v2, nox_xxx_windowMainMenuProc_4A1DC0);
	*getMemU32Ptr(0x5D4594, 1307304) = nox_gui_makeAnimation_43C5B0(v2, 0, 270, 0, 510, 0, -20, 0, 40);
	if (!*getMemU32Ptr(0x5D4594, 1307304)) {
		return 0;
	}
	sub_4A19F0("OptsBack.wnd:Quit");
	nox_xxx_unknown_libname_11_4D1650();
	sub_578CD0();
	sub_43D9B0(25, 100);
	if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
		v3 = nox_xxx_wndGetChildByID_46B0C0(nox_win_main_menu, 112);
		nox_window_call_field_94(nox_win_main_menu, 16391, (int)v3, 0);
	}
	return 1;
}

//----- (004A1DC0) --------------------------------------------------------
int  nox_xxx_windowMainMenuProc_4A1DC0(int a1, int a2, int* a3, int a4) {
	wchar_t* v5;   // eax
	int v6;        // eax
	wchar_t* v7;   // eax
	int v8;        // eax
	wchar_t* v9;   // [esp-10h] [ebp-94h]
	char v10[128]; // [esp+4h] [ebp-80h]

	if (a2 == 16389) {
		nox_xxx_clientPlaySoundSpecial_452D80(920, 100);
	} else {
		if (a2 != 16391)
			return 0;
		if (nox_wnd_xxx_1307308->state != NOX_GUI_ANIM_IN_DONE && !nox_common_gameFlags_check_40A5C0(0x2000000)) {
		LABEL_32:
			nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
		} else {
			switch (nox_xxx_wndGetID_46B0A0(a3)) {
			case 111:
				if (nox_xxx_checkHasSoloMaps_40ABD0() && nox_xxx_testCDAndSolo_413840()) {
					nox_xxx_setGameFlags_40A4D0(2048);
					nox_common_gameFlags_unset_40A540(0x2000);
					nox_common_gameFlags_unset_40A540(0x10000);
					nox_xxx_gameSetAudioFadeoutMb_501AC0(0);
					nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ADMIN | NOX_ENGINE_FLAG_GODMODE);
					sub_4D6F40(0);
					sub_4D6F90(0);
					nox_xxx_setQuest_4D6F60(0);
					sub_4D6F80(0);
					nox_xxx_cliShowHideTubes_470AA0(0);
					sub_461440(0);
					sub_4A1D40();
					nox_xxx_cliSetMinimapZoom_472520(1110);
					if (!nox_xxx_parseGamedataBinPre_4D1630()) {
						nox_xxx_setContinueMenuOrHost_43DDD0(0);
						nox_client_gui_flag_815132 = 0;
						return 0;
					}
					if (sub_4DC550()) {
						sub_4A7A70(1);
						nox_wnd_xxx_1307308->field_13 = nox_game_showSelChar_4A4DB0;
					} else {
						sub_4A7A70(0);
						nox_wnd_xxx_1307308->field_13 = nox_game_showSelClass_4A4840;
					}
					nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				} else {
					v9 = nox_strman_loadString_40F1D0("caution", 0,
											   "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 341);
					v5 = nox_strman_loadString_40F1D0("solo", 0,
											   "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 341);
					nox_xxx_dialogMsgBoxCreate_449A10(nox_win_main_menu, (int)v5, (int)v9, 33, 0, 0);
					sub_44A360(1);
					sub_44A4B0();
					nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				}
				return 1;
			case 112:
				// prepare to start a server
				sub_4A1D40();
				nox_common_setEngineFlag(NOX_ENGINE_FLAG_ADMIN);
				nox_common_resetEngineFlag(NOX_ENGINE_FLAG_GODMODE);
				nox_xxx_setGameFlags_40A4D0(0x2000);
				nox_xxx_setGameFlags_40A4D0(0x10000);
				nox_common_gameFlags_unset_40A540(2048);
				sub_461440(0);
				sub_4D6F40(0);
				sub_4D6F90(0);
				nox_xxx_setQuest_4D6F60(0);
				sub_4D6F80(0);
				if (!sub_473670())
					nox_client_toggleMap_473610();
				nox_xxx_cliShowHideTubes_470AA0(0);
				nox_xxx_cliSetMinimapZoom_472520(2300);
				if (!nox_xxx_parseGamedataBinPre_4D1630()) {
					nox_xxx_setContinueMenuOrHost_43DDD0(0);
					nox_client_gui_flag_815132 = 0;
					return 0;
				}
				goto LABEL_26;
			case 121:
				if (!nox_game_setMovieFile_4CB230("Intro.vqa", v10))
					goto LABEL_32;
				sub_4A1D40();
				sub_4B0300(v10);
				sub_4B0640(nox_game_switchStates_43C0A0);
				nox_wnd_xxx_1307308->field_13 = nox_client_drawGeneralCallback_4A2200;
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
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
					v7 = nox_strman_loadString_40F1D0("GeneralPrint:InformExpansion", 0,
											   "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 416);
					nox_xxx_dialogMsgBoxCreate_449A10(nox_win_main_menu, 0, (int)v7, 33, 0, 0);
					sub_44A360(0);
					sub_44A4B0();
					nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
					return 1;
				}
				sub_4A1D40();
				nox_common_setEngineFlag(NOX_ENGINE_FLAG_ADMIN);
				nox_common_resetEngineFlag(NOX_ENGINE_FLAG_GODMODE);
				nox_xxx_setGameFlags_40A4D0(0x2000);
				nox_xxx_setGameFlags_40A4D0(0x10000);
				nox_common_gameFlags_unset_40A540(2048);
				sub_4D6F40(1);
				sub_4D6F90(1);
				nox_game_setQuestStage_4E3CD0(0);
				sub_4D7440(0);
				nox_xxx_cliSetMinimapZoom_472520(2300);
				if (!sub_473670())
					nox_client_toggleMap_473610();
				sub_461440(0);
				if (!nox_xxx_parseGamedataBinPre_4D1630()) {
					nox_xxx_setContinueMenuOrHost_43DDD0(0);
					nox_client_gui_flag_815132 = 0;
					return 0;
				}
			LABEL_26:
#ifdef __EMSCRIPTEN__
				sub_4AA450();
				nox_wnd_xxx_1307308->field_13 = nox_game_showGameSel_4379F0;
				sub_43AF50(0);
#else // !__EMSCRIPTEN__
#ifndef NO_WOLAPI
				nox_wnd_xxx_1307308->field_13 = nox_game_showOnlineOrLAN_413800;
#else // NO_WOLAPI
				//sub_4AA450();
				nox_wnd_xxx_1307308->field_13 = nox_game_showGameSel_4379F0;
				sub_43AF50(0);
#endif // NO_WOLAPI
#endif // __EMSCRIPTEN__
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				break;
			default:
				goto LABEL_32;
			}
		}
	}
	return 1;
}

//----- (004A22A0) --------------------------------------------------------
int  sub_4A22A0(int a1, int* a2) {
	int v2;               // edx
	int v3;               // ecx
	unsigned char* v4;  // esi
	int v5;               // eax
	int v6;               // eax
	bool v7;              // zf
	int v8;               // eax
	int v9;               // eax
	unsigned char* v10; // esi
	int v11;              // eax
	int xLeft;            // [esp+4h] [ebp-8h]
	int yTop;             // [esp+8h] [ebp-4h]

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
		if (v2 & 2)
			nox_client_drawImageAt_47D2C0(a2[10], xLeft, v3);
		else
			nox_client_drawImageAt_47D2C0(a2[6], xLeft, v3);
	}
	if (*getMemU32Ptr(0x587000, 168836)) {
		v4 = getMemAt(0x587000, 168868);
		do {
			v5 = *((uint32_t*)v4 + 2);
			if (v5)
				*((uint32_t*)v4 + 2) = v5 - 1;
			v6 = *((uint32_t*)v4 + 1);
			if (v6) {
				*((uint32_t*)v4 + 1) = v6 - 1;
				*((uint32_t*)v4 + 2) = nox_common_randomIntMinMax_415FF0(60, 120, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 180);
			}
			v7 = (*(uint32_t*)v4)-- == 1;
			v8 = *((uint32_t*)v4 - 5);
			if (v7) {
				if (v8) {
					*((uint32_t*)v4 - 5) = 0;
					*(uint32_t*)v4 = nox_common_randomIntMinMax_415FF0(*((uint32_t*)v4 - 4), *((uint32_t*)v4 - 3),
											  "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 211);
					*((uint32_t*)v4 + 2) = nox_common_randomIntMinMax_415FF0(60, 90, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 214);
				} else {
					*((uint32_t*)v4 - 5) = 1;
					*(uint32_t*)v4 = nox_common_randomIntMinMax_415FF0(*((uint32_t*)v4 - 2), *((uint32_t*)v4 - 1),
											  "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 199);
				}
			} else if (!v8 && !*((uint32_t*)v4 + 2) && !*((uint32_t*)v4 + 1) &&
					   nox_common_randomIntMinMax_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 228) > 75) {
				*((uint32_t*)v4 + 1) = nox_common_randomIntMinMax_415FF0(4, 8, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 229);
			}
			v9 = *((uint32_t*)v4 + 4);
			v4 += 48;
		} while (v9);
	}
	if (*getMemU32Ptr(0x587000, 168832)) {
		v10 = getMemAt(0x587000, 168872);
		do {
			if (!*((uint32_t*)v10 - 6) && !*(uint32_t*)v10)
				nox_client_drawImageAt_47D2C0(*((uint32_t*)v10 - 9), *((uint32_t*)v10 - 8), *((uint32_t*)v10 - 7));
			v11 = *((uint32_t*)v10 + 2);
			v10 += 48;
		} while (v11);
	}
	return 1;
}
