#include "client__system__parsecmd.h"

#include "client__gui__guicon.h"
#include "client__gui__guimsg.h"
#include "client__gui__servopts__general.h"
#include "client__gui__servopts__guiserv.h"
#include "common__log.h"
#include "common__strman.h"
#include "common__system__settings.h"
#include "server__script__script.h"
#include "common__system__team.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "client__video__draw_common.h"
#include "common__magic__speltree.h"
#include "static.h"

void sub_4E3BC0(nox_objectType_t* a1);

extern uint32_t nox_xxx_xxxRenderGUI_587000_80832;
extern uint32_t nox_server_connectionType_3596;
extern uint32_t dword_5d4594_805836;
extern uint32_t nox_client_renderGUI_80828;
extern uint32_t dword_5d4594_2650652;
extern uint32_t nox_player_netCode_85319C;

nox_playerInfo* nox_console_playerWhoSent_823692 = 0;

unsigned int nox_client_consoleIsServer_823684 = 0;

//----- (00440E10) --------------------------------------------------------
int nox_cmd_set_sysop(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 3) {
		return 0;
	}
	nox_xxx_sysopSetPass_40A610(tokens[tokInd]);
	wchar_t* s =
		nox_strman_loadString_40F1D0("sysoppasswordset", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1352);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

//----- (00441550) --------------------------------------------------------
int nox_cmd_show_game(int tokInd, int tokCnt, wchar_t** tokens) {
	char* v2;        // esi
	int v4;          // edi
	int v5;          // eax
	wchar_t* v6;     // eax
	short v7;        // ax
	wchar_t* v8;     // eax
	wchar_t* v9;     // eax
	char* v11;       // eax
	char* v12;       // [esp-18h] [ebp-5Ch]
	int v13;         // [esp-10h] [ebp-54h]
	int v14;         // [esp-Ch] [ebp-50h]
	char* v15;       // [esp-8h] [ebp-4Ch]
	int v16;         // [esp-8h] [ebp-4Ch]
	int v17;         // [esp-8h] [ebp-4Ch]
	wchar_t v18[32]; // [esp+4h] [ebp-40h]

	v2 = sub_4165B0();
	if (tokCnt != 2) {
		return 0;
	}
	v4 = nox_common_playerInfoCount_416F40();
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		--v4;
	}
	v5 = nox_client_getVersionBuild_409AC0();
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 102952), nox_version_string_102944, v5);
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		v15 = nox_xxx_serverOptionsGetServername_40A4C0();
		v6 = nox_strman_loadString_40F1D0("Name", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1801);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 103028), v6, v15);
		v7 = nox_common_gameFlags_getVal_40A5B0();
		v16 = nox_xxx_guiServerOptionsGetGametypeName_4573C0(v7);
		v8 = nox_strman_loadString_40F1D0("Type", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1802);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 103088), v8, v16);
		v17 = sub_40A180(*((uint16_t*)v2 + 26));
		v14 = (unsigned short)nox_xxx_servGamedataGet_40A020(*((uint16_t*)v2 + 26));
		v13 = nox_xxx_servGetPlrLimit_409FA0();
		v12 = nox_server_currentMapGetFilename_409B30();
		v9 = nox_strman_loadString_40F1D0("GameInfo", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1803);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v9, v12, v4, v13, v14, v17);
		v11 = nox_net_ip2str(nox_xxx_net_getIP_554200(0));
		nox_swprintf(v18, L"%S", v11);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 103160), v18);
	}
	return 1;
}

//----- (00440A20) --------------------------------------------------------
void sub_440A20(wchar_t* a1, ...) {
	va_list va; // [esp+8h] [ebp+8h]

	va_start(va, a1);
	nox_vswprintf((wchar_t*)getMemAt(0x5D4594, 822660), a1, va);
	nox_xxx_printCentered_445490((wchar_t*)getMemAt(0x5D4594, 822660));
}

//----- (004424F0) --------------------------------------------------------
int nox_cmd_set_cycle(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;
	if (tokCnt == 3) {
		if (!_nox_wcsicmp(tokens[tokInd], L"on")) {
			sub_4D0D90(1);
			v3 = nox_strman_loadString_40F1D0("MapCycleOn", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2614);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3);
			sub_4AD840();
			return 1;
		}
		if (!_nox_wcsicmp(tokens[tokInd], L"off")) {
			sub_4D0D90(0);
			v3 = nox_strman_loadString_40F1D0("MapCycleOff", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2621);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3);
			sub_4AD840();
			return 1;
		}
	}
	return 0;
}

//----- (00442590) --------------------------------------------------------
int nox_cmd_set_weapons(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;
	wchar_t* v5;
	if (tokCnt == 3) {
		if (!_nox_wcsicmp(tokens[tokInd], L"on")) {
			sub_409E70(1);
			nox_server_gameSettingsUpdated_40A670();
			v5 = nox_strman_loadString_40F1D0("cmd_token:on", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2644);
			v3 = nox_strman_loadString_40F1D0("weapons", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2645);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
			return 1;
		}
		if (!_nox_wcsicmp(tokens[tokInd], L"off")) {
			sub_409EC0(1);
			nox_server_gameSettingsUpdated_40A670();
			v5 = nox_strman_loadString_40F1D0("cmd_token:off", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2652);
			v3 = nox_strman_loadString_40F1D0("weapons", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2653);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
			return 1;
		}
	}
	return 0;
}

//----- (00442670) --------------------------------------------------------
int nox_cmd_set_staffs(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;
	wchar_t* v5;
	if (tokCnt == 3) {
		if (!_nox_wcsicmp(tokens[tokInd], L"on")) {
			sub_409E70(16);
			nox_server_gameSettingsUpdated_40A670();
			v5 = nox_strman_loadString_40F1D0("cmd_token:on", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2674);
			v3 = nox_strman_loadString_40F1D0("staffs", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2675);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
			return 1;
		}
		if (!_nox_wcsicmp(tokens[tokInd], L"off")) {
			sub_409EC0(16);
			nox_server_gameSettingsUpdated_40A670();
			v5 = nox_strman_loadString_40F1D0("cmd_token:off", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2682);
			v3 = nox_strman_loadString_40F1D0("staffs", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2683);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
			return 1;
		}
	}
	return 0;
}
//----- (00442840) --------------------------------------------------------
int nox_cmd_set_name(int tokInd, int tokCnt, wchar_t** tokens) {
	int v3;          // ebx
	unsigned int v5; // edx
	char* v6;        // edi
	char* v7;        // edi
	char* v8;        // esi
	char v9;         // cl
	int v10;         // edx
	wchar_t* v11;    // eax
	uint32_t* v12;   // [esp+4h] [ebp-104h]
	char v13[128];   // [esp+8h] [ebp-100h]
	char v14[128];   // [esp+88h] [ebp-80h]

	v3 = tokInd;
	if (tokCnt < 3) {
		return 0;
	}
	v13[0] = 0;
	if (tokInd < tokCnt) {
		v12 = &tokens[tokInd];
		do {
			nox_sprintf(v14, "%S", *v12);
			v5 = strlen(v14) + 1;
			v6 = &v13[strlen(v13)];
			memcpy(v6, v14, 4 * (v5 >> 2));
			v8 = &v14[4 * (v5 >> 2)];
			v7 = &v6[4 * (v5 >> 2)];
			v9 = v5;
			v10 = v3 + 1;
			memcpy(v7, v8, v9 & 3);
			if (v3 + 1 < tokCnt) {
				*(uint16_t*)&v13[strlen(v13)] = *getMemU16Ptr(0x587000, 104484);
			}
			++v3;
			++v12;
		} while (v10 < tokCnt);
		if (v13[0]) {
			nox_xxx_gameSetServername_40A440(v13);
			v11 = nox_strman_loadString_40F1D0("setgamename", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2766);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v11, v13);
		}
	}
	return 1;
}
// 442840: using guessed type char var_100[128];
// 442840: using guessed type char var_80[128];

//----- (00442950) --------------------------------------------------------
int nox_cmd_set_mnstrs(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3; // eax
	wchar_t* v5; // [esp-4h] [ebp-10h]

	if (tokCnt == 3 || tokCnt == 4) {
		if (_nox_wcsicmp(tokens[2], *(const wchar_t**)getMemAt(0x587000, 94468 + 4*6))) {
			if (!_nox_wcsicmp(tokens[tokInd], L"on")) {
				sub_409E70(4);
				nox_server_gameSettingsUpdated_40A670();
				v5 = nox_strman_loadString_40F1D0("cmd_token:on", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2810);
				v3 = nox_strman_loadString_40F1D0("monsters", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2811);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
				return 1;
			}
			if (!_nox_wcsicmp(tokens[tokInd], L"off")) {
				sub_409EC0(4);
				nox_server_gameSettingsUpdated_40A670();
				v5 = nox_strman_loadString_40F1D0("cmd_token:off", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2818);
				v3 = nox_strman_loadString_40F1D0("monsters", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2819);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
				return 1;
			}
		} else if (tokCnt != 3) {
			if (!_nox_wcsicmp(tokens[3], L"on")) {
				sub_409E70(8);
				nox_server_gameSettingsUpdated_40A670();
				v5 = nox_strman_loadString_40F1D0("cmd_token:on", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2788);
				v3 = nox_strman_loadString_40F1D0("monsterrespawn", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2789);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
				return 1;
			}
			if (!_nox_wcsicmp(tokens[3], L"off")) {
				sub_409E70(8);
				nox_server_gameSettingsUpdated_40A670();
				v5 = nox_strman_loadString_40F1D0("cmd_token:off", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2796);
				v3 = nox_strman_loadString_40F1D0("monsterrespawn", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2797);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
				return 1;
			}
		}
	}
	return 0;
}

//----- (00442B00) --------------------------------------------------------
int nox_cmd_set_spell(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;   // eax
	int v4;        // esi
	char* v5;      // ebx
	wchar_t* v7;   // eax
	int v8;        // [esp-4h] [ebp-74h]
	int v9;        // [esp-4h] [ebp-74h]
	char v10[100]; // [esp+Ch] [ebp-64h]

	if (tokCnt == 4) {
		if (nox_common_gameFlags_check_40A5C0(128)) {
			v8 = tokens[2];
			v3 = nox_strman_loadString_40F1D0("NotInChat", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3293);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
			return 1;
		}
		v4 = nox_xxx_spellByTitle_424960(tokens[2]);
		if (v4 || (nox_sprintf(v10, "%S", tokens[2]), (v4 = nox_xxx_spellNameToN_4243F0(v10)) != 0)) {
			if (!_nox_wcsicmp(tokens[3], L"on")) {
				v5 = sub_4165B0();
				if ((nox_common_gameFlags_check_40A5C0(64) || v5[52] & 0x40) && v4 == 132) {
					return 1;
				}
				if (nox_xxx_spellIsEnabled_424B70(v4)) {
					return 1;
				}
				nox_xxx_spellEnable_424B90(v4);
				nox_server_gameSettingsUpdated_40A670();
				v8 = tokens[2];
				v3 = nox_strman_loadString_40F1D0("spellenabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3324);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
				return 1;
			}
			if (!_nox_wcsicmp(tokens[3], L"off")) {
				if (!nox_xxx_spellIsEnabled_424B70(v4)) {
					return 1;
				}
				nox_xxx_spellDisable_424BB0(v4);
				nox_server_gameSettingsUpdated_40A670();
				v8 = tokens[2];
				v3 = nox_strman_loadString_40F1D0("spelldisabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3333);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
				return 1;
			}
		} else {
			v9 = tokens[2];
			v7 = nox_strman_loadString_40F1D0("invalidspell", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3342);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v7, v9);
		}
	}
	return 0;
}

//----- (004E5DB0) --------------------------------------------------------
void nox_xxx_deleteAllObjectsOfType_4E5DB0(int a1) {
	const nox_object_t* v1 = nox_server_getFirstObject_4DA790();
	if (v1) {
		nox_object_t* v2;
		do {
			v2 = nox_server_getNextObject_4DA7A0(v1);
			int v3 = *(uint32_t*)&v1->field_126;
			if (v3) {
				int v4;
				do {
					v4 = *(uint32_t*)(v3 + 496);
					if (*(unsigned short*)(v3 + 4) == a1) {
						nox_xxx_delayedDeleteObject_4E5CC0(v3);
					}
					v3 = v4;
				} while (v4);
			}
			if (v1->typ_ind == a1) {
				nox_xxx_delayedDeleteObject_4E5CC0(v1);
			}
			v1 = v2;
		} while (v2);
	}
}

//----- (00415A60) --------------------------------------------------------
int sub_415A60(wchar_t* a1) {
	char* v1; // eax
	int v2;   // eax

	v1 = (char*)sub_415960(a1);
	if (v1 && (v2 = sub_415840(v1)) != 0) {
		return nox_xxx_objectTypeByInd_4E3B70(v2);
	}
	return 0;
}

//----- (00442C90) --------------------------------------------------------
int nox_cmd_set_weapon(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;        // eax
	wchar_t* v4;        // eax
	unsigned short* v6; // esi
	wchar_t* v7;        // eax
	int v8;             // [esp-4h] [ebp-70h]
	int v9;             // [esp-4h] [ebp-70h]
	int v10;            // [esp-4h] [ebp-70h]
	char v11[100];      // [esp+8h] [ebp-64h]

	if (tokCnt == 4) {
		if (nox_common_gameFlags_check_40A5C0(128)) {
			v8 = tokens[2];
			v3 = nox_strman_loadString_40F1D0("NotInChat", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3361);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
			return 1;
		}
		if (_nox_wcsicmp(tokens[2], *(const wchar_t**)getMemAt(0x587000, 94468 + 4*6))) {
			v6 = (unsigned short*)sub_415A60(tokens[2]);
			if (v6 || (nox_sprintf(v11, "%S", tokens[2]), (v6 = (unsigned short*)sub_415A30(v11)) != 0)) {
				if (!_nox_wcsicmp(tokens[3], L"on")) {
					if (nox_xxx_getUnitDefDd10_4E3BA0(*v6)) {
						return 1;
					}
					sub_4E3BF0((int)v6);
					nox_server_gameSettingsUpdated_40A670();
					v8 = tokens[2];
					v3 = nox_strman_loadString_40F1D0("weaponEnabled", 0,
													  "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3401);
					nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
					return 1;
				}
				if (!_nox_wcsicmp(tokens[3], L"off")) {
					if (!nox_xxx_getUnitDefDd10_4E3BA0(*v6) || nox_xxx_ammoCheck_415880((char*)*v6) == 1) {
						return 1;
					}
					sub_4E3BC0((int)v6);
					nox_xxx_deleteAllObjectsOfType_4E5DB0(*v6);
					nox_server_gameSettingsUpdated_40A670();
					v8 = tokens[2];
					v3 = nox_strman_loadString_40F1D0("weaponDisabled", 0,
													  "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3414);
					nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
					return 1;
				}
			} else {
				v10 = tokens[2];
				v7 = nox_strman_loadString_40F1D0("invalidweapon", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3423);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v7, v10);
			}
		} else {
			if (!_nox_wcsicmp(tokens[3], L"on")) {
				sub_409E70(2);
				v9 = tokens[3];
				v4 = nox_strman_loadString_40F1D0("weaponsrespawn", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3370);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v4, v9);
				sub_4AD840();
				return 1;
			}
			if (!_nox_wcsicmp(tokens[3], L"off")) {
				sub_409E70(2);
				v9 = tokens[3];
				v4 = nox_strman_loadString_40F1D0("weaponsrespawn", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3377);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v4, v9);
				sub_4AD840();
				return 1;
			}
		}
	}
	return 0;
}

//----- (00415EF0) --------------------------------------------------------
int sub_415EF0(wchar_t* a1) {
	char* v1; // eax
	int v2;   // eax

	v1 = (char*)sub_415DA0(a1);
	if (v1 && (v2 = sub_415CD0(v1)) != 0) {
		return nox_xxx_objectTypeByInd_4E3B70(v2);
	}
	return 0;
}

//----- (00442ED0) --------------------------------------------------------
int nox_cmd_set_armor(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;        // eax
	unsigned short* v4; // esi
	wchar_t* v6;        // eax
	int v7;             // [esp-4h] [ebp-70h]
	int v8;             // [esp-4h] [ebp-70h]
	char v9[100];       // [esp+8h] [ebp-64h]

	if (tokCnt == 4) {
		if (nox_common_gameFlags_check_40A5C0(128)) {
			v7 = tokens[2];
			v3 = nox_strman_loadString_40F1D0("NotInChat", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3442);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v7);
			return 1;
		}
		v4 = (unsigned short*)sub_415EF0(tokens[2]);
		if (v4 || (nox_sprintf(v9, "%S", tokens[2]), (v4 = (unsigned short*)sub_415EC0(v9)) != 0)) {
			if (!_nox_wcsicmp(tokens[3], L"on")) {
				if (!nox_xxx_getUnitDefDd10_4E3BA0(*v4)) {
					sub_4E3BF0((int)v4);
					nox_server_gameSettingsUpdated_40A670();
					v7 = tokens[2];
					v3 = nox_strman_loadString_40F1D0("armorEnabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
													  3462);
					nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v7);
					return 1;
				}
				return 1;
			}
			if (!_nox_wcsicmp(tokens[3], L"off")) {
				if (nox_xxx_getUnitDefDd10_4E3BA0(*v4)) {
					sub_4E3BC0((int)v4);
					nox_xxx_deleteAllObjectsOfType_4E5DB0(*v4);
					nox_server_gameSettingsUpdated_40A670();
					v7 = tokens[2];
					v3 = nox_strman_loadString_40F1D0("armorDisabled", 0,
													  "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3473);
					nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v7);
					return 1;
				}
				return 1;
			}
		} else {
			v8 = tokens[2];
			v6 = nox_strman_loadString_40F1D0("invalidarmor", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3481);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v6, v8);
		}
	}
	return 0;
}

//----- (00443050) --------------------------------------------------------
int nox_cmd_set_staff(int tokInd, int tokCnt, wchar_t** tokens) {
	int v3;       // edi
	wchar_t* v4;  // eax
	wchar_t* v6;  // eax
	int v7;       // [esp-4h] [ebp-8Ch]
	int v8;       // [esp-4h] [ebp-8Ch]
	char v9[128]; // [esp+8h] [ebp-80h]

	if (tokCnt == 4) {
		nox_sprintf(v9, "%S", tokens[2]);
		v3 = nox_xxx_objectTypeByID_4E3B60(v9);
		if (v3) {
			if (!_nox_wcsicmp(tokens[3], L"on")) {
				sub_4E3BF0(v3);
				v7 = tokens[2];
				v4 = nox_strman_loadString_40F1D0("staffEnabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3535);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v4, v7);
				return 1;
			}
			if (!_nox_wcsicmp(tokens[3], L"off")) {
				sub_4E3BC0(v3);
				v7 = tokens[2];
				v4 = nox_strman_loadString_40F1D0("staffDisabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3541);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v4, v7);
				return 1;
			}
		} else {
			v8 = tokens[2];
			v6 = nox_strman_loadString_40F1D0("invalidstaff", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3548);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v6, v8);
		}
	}
	return 0;
}

//----- (00443160) --------------------------------------------------------
int nox_cmd_ban(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v4; // edi
	char* v5;    // eax
	char* v6;    // esi
	wchar_t* v7; // eax
	wchar_t* v8; // eax
	int v9;      // [esp-Ch] [ebp-Ch]

	if (tokCnt != 2) {
		return 0;
	}
	v4 = tokens[tokInd];
	v5 = nox_xxx_playerByName_4170D0(tokens[tokInd]);
	v6 = v5;
	if (v5) {
		if (v5[2064] == 31) {
			v8 = nox_strman_loadString_40F1D0("cantbanyourself", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
											  3580);
			sub_440A20(v8);
			return 1;
		}
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			sub_4DCFB0(*((uint32_t*)v6 + 514));
		} else {
			nox_xxx_playerDisconnByPlrID_4DEB00((unsigned char)v6[2064]);
		}
		sub_416770(0, v4, v6 + 2112);
		v9 = (int)(v6 + 4704);
		v7 = nox_strman_loadString_40F1D0("banned", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3577);
	} else {
		sub_416770(0, v4, 0);
		v9 = (int)v4;
		v7 = nox_strman_loadString_40F1D0("banDisallow", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3585);
	}
	sub_440A20(v7, v9);
	return 1;
}

//----- (00443250) --------------------------------------------------------
int nox_cmd_allow_user(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* s =
		nox_strman_loadString_40F1D0("notyetimplemented", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3698);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

//----- (00443280) --------------------------------------------------------
int nox_cmd_allow_ip(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* s =
		nox_strman_loadString_40F1D0("notyetimplemented", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3704);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

//----- (004432B0) --------------------------------------------------------
int nox_cmd_kick(int tokInd, int tokCnt, wchar_t** tokens) {
	char* v4;    // eax
	char* v5;    // esi
	wchar_t* v6; // eax
	wchar_t* v7; // eax

	if (tokCnt != 2) {
		return 0;
	}
	v4 = nox_xxx_playerByName_4170D0(tokens[tokInd]);
	v5 = v4;
	if (!v4) {
		return 1;
	}
	if (v4[2064] == 31) {
		v7 = nox_strman_loadString_40F1D0("cantkickyourself", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3745);
		sub_440A20(v7);
		return 1;
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		sub_4DCFB0(*((uint32_t*)v5 + 514));
	} else {
		nox_xxx_playerCallDisconnect_4DEAB0((unsigned char)v5[2064], 4);
		v6 = nox_strman_loadString_40F1D0("kicked", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3739);
		sub_440A20(v6, v5 + 4704);
	}
	return 1;
}

//----- (00443380) --------------------------------------------------------
int nox_cmd_set_players(int tokInd, int tokCnt, wchar_t** tokens) {
	int v3;            // esi
	const wchar_t* v5; // eax
	int v6;            // eax
	wchar_t* v7;       // eax

	v3 = 0;
	if (tokCnt != 3) {
		return 0;
	}
	v5 = tokens[2];
	if (v5) {
		v6 = nox_wcstol(v5, 0, 10);
		v3 = v6;
		if (v6 >= 0) {
			if (v6 > 999) {
				v3 = 999;
			}
		} else {
			v3 = 0;
		}
		if (nox_xxx_servGetPlrLimit_409FA0() == v3) {
			return 1;
		}
		nox_xxx_servSetPlrLimit_409F80(v3);
		sub_455800();
	}
	v7 = nox_strman_loadString_40F1D0("playersset", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3779);
	sub_440A20(v7, v3);
	return 1;
}

//----- (00443480) --------------------------------------------------------
int nox_cmd_set_spellpts(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* s =
		nox_strman_loadString_40F1D0("notyetimplemented", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3830);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

//----- (004434B0) --------------------------------------------------------
int nox_cmd_list_users(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v0;     // eax
	char* i;         // esi
	wchar_t* v2;     // eax
	wchar_t* v3;     // eax
	wchar_t v5[128]; // [esp+4h] [ebp-100h]

	v0 = nox_strman_loadString_40F1D0("userslist", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3839);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v0);
	for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
		v5[0] = 0;
		nox_wcscat(v5, (const wchar_t*)i + 2352);
		if (nox_client_consoleIsServer_823684 && i[3680] & 4) {
			nox_wcscat(v5, L", ");
			v2 = nox_strman_loadString_40F1D0("SysMuted", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3851);
			nox_wcscat(v5, v2);
		}
		if (i[3680] & 8) {
			nox_wcscat(v5, L", ");
			v3 = nox_strman_loadString_40F1D0("ClientMuted", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3857);
			nox_wcscat(v5, v3);
		}
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 106604), v5);
	}
	return 1;
}

//----- (0057A0F0) --------------------------------------------------------
int sub_57A0F0(wchar_t* a1) {
	if (!nox_common_gameFlags_check_40A5C0(2)) {
		return 0;
	}
	if (!a1) {
		return 0;
	}
	char* v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1) {
		return 0;
	}
	nox_xxx_playerUnsetStatus_417530((int)v1, 8);
	return 1;
}

//----- (0057A130) --------------------------------------------------------
int sub_57A130(wchar_t* a1) {
	if (!a1) {
		return 0;
	}
	char* v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1) {
		return 0;
	}
	nox_xxx_playerUnsetStatus_417530((int)v1, 4);
	return 1;
}

//----- (00443610) --------------------------------------------------------
int nox_cmd_unmute(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t** v3; // esi
	int v4;       // eax
	int v5;       // eax
	wchar_t* v6;  // eax
	wchar_t* v8;  // [esp-4h] [ebp-14h]

	if (tokCnt < 2 || tokCnt > 3) {
		return 0;
	}
	v3 = &tokens[tokInd];
	if (!nox_client_consoleIsServer_823684) {
		v5 = sub_57A0F0(*v3);
	} else {
		if (_nox_wcsicmp(tokens[tokInd], *(const wchar_t**)getMemAt(0x587000, 94468 + 4*7))) {
			v5 = sub_57A0F0(*v3);
		} else {
			v4 = tokInd + 1;
			if (tokInd + 1 != tokCnt - 1) {
				return 0;
			}
			v3 = &tokens[v4];
			v5 = sub_57A130(*v3);
		}
	}
	v8 = *v3;
	if (v5) {
		v6 = nox_strman_loadString_40F1D0("UnMuted", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3923);
	} else {
		v6 = nox_strman_loadString_40F1D0("UserNotFound", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3921);
	}
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v6, v8);
	return 1;
}

//----- (0057A080) --------------------------------------------------------
int sub_57A080(wchar_t* a1) {
	if (!nox_common_gameFlags_check_40A5C0(2)) {
		return 0;
	}
	if (!a1) {
		return 0;
	}
	char* v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1 || v1[2064] == 31) {
		return 0;
	}
	nox_xxx_netNeedTimestampStatus_4174F0((int)v1, 8);
	return 1;
}

//----- (0057A0C0) --------------------------------------------------------
int sub_57A0C0(wchar_t* a1) {
	if (!a1) {
		return 0;
	}
	char* v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1) {
		return 0;
	}
	nox_xxx_netNeedTimestampStatus_4174F0((int)v1, 4);
	return 1;
}

//----- (004436E0) --------------------------------------------------------
int nox_cmd_mute(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t** v3; // esi
	int v4;       // eax
	int v5;       // eax
	wchar_t* v6;  // eax
	wchar_t* v8;  // [esp-4h] [ebp-14h]

	if (tokCnt < 2 || tokCnt > 3) {
		return 0;
	}
	v3 = &tokens[tokInd];
	if (!nox_client_consoleIsServer_823684) {
		v5 = sub_57A080(*v3);
	} else {
		if (_nox_wcsicmp(tokens[tokInd], *(const wchar_t**)getMemAt(0x587000, 94468 + 4*7))) {
			v5 = sub_57A080(*v3);
		} else {
			v4 = tokInd + 1;
			if (tokInd + 1 != tokCnt - 1) {
				return 0;
			}
			v3 = &tokens[v4];
			v5 = sub_57A0C0(*v3);
		}
	}
	v8 = *v3;
	if (v5) {
		v6 = nox_strman_loadString_40F1D0("Muted", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3961);
	} else {
		v6 = nox_strman_loadString_40F1D0("UserNotFound", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3959);
	}
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v6, v8);
	return 1;
}

//----- (00443810) --------------------------------------------------------
int nox_cmd_exec_rul(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	wchar_t buf[128];
	nox_wcscpy(buf, tokens[1]);
	if (!nox_wcschr(buf, 0x2Eu)) {
		nox_wcscat(buf, L".rul");
	}
	wchar_t* s = nox_strman_loadString_40F1D0("ExecutingRul", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4002);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s, buf);
	nox_xxx_doExecrul_4438A0(buf);
	return 1;
}

//----- (00443E90) --------------------------------------------------------
int nox_xxx_serverHandleClientConsole_443E90(nox_playerInfo* pl, char a2, wchar_t* a3) {
	int v3;        // ecx
	int result;    // eax
	int v5;        // edi
	wchar_t* v6;   // ebx
	int v7;        // eax
	int v8;        // eax
	wchar_t* v9;   // eax
	wchar_t* v10;  // esi
	int v11;       // edi
	wchar_t* v12;  // eax
	wchar_t* v13;  // eax
	char* v14;     // esi
	int v15;       // eax
	wchar_t* v16;  // eax
	char* v17;     // esi
	wchar_t* v18;  // eax
	int v19;       // [esp-8h] [ebp-94h]
	int v20;       // [esp-8h] [ebp-94h]
	wchar_t* v21;  // [esp-4h] [ebp-90h]
	char v22[128]; // [esp+Ch] [ebp-80h]

	if (!pl || !pl->playerUnit) {
		return 0;
	}
	if (a3) {
		nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 818228), a3);
	} else {
		*getMemU16Ptr(0x5D4594, 818228) = 0;
	}
	v3 = pl;
	nox_console_playerWhoSent_823692 = pl;
	if (a2 != 4 && a2 != 5 && a2) {
		if (nox_common_gameFlags_check_40A5C0(49152)) {
			return 1;
		}
	}
	switch (a2) {
	case 0:
		if (nox_common_gameFlags_check_40A5C0(8) || nox_common_gameFlags_check_40A5C0(4096) ||
			*(uint8_t*)((int)pl + 3680) & 1) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		v5 = *getMemI16Ptr(0x5D4594, 818228) == -4083 && *getMemI16Ptr(0x5D4594, 818230) == -3923 &&
			 !*getMemU16Ptr(0x5D4594, 818232);
		if (nox_xxx_playerGoObserver_4E6860(pl, v5, 0) != 1) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		v6 = nox_strman_loadString_40F1D0("set", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4287);
		v7 = nox_xxx_gamePlayIsAnyPlayers_40A8A0();
		if (v7) {
			if (!v5) {
				nox_xxx_netNeedTimestampStatus_4174F0(pl, 256);
			}
			if (nox_common_gameFlags_check_40A5C0(1024) && sub_40A770() == 1) {
				sub_5095E0();
			}
		}
		v8 = pl->playerUnit;
		if (v8) {
			nox_xxx_netChangeTeamMb_419570(v8 + 48, pl->netCode);
		}
		v21 = v6;
		v9 = nox_strman_loadString_40F1D0("observermode", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4308);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v9, v21);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	case 1:
		if (!sub_4D12A0(pl->playerInd) && pl->playerInd != nox_player_netCode_85319C &&
			!nox_common_gameFlags_check_40A5C0(2048)) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		nox_wcstok((wchar_t*)getMemAt(0x5D4594, 818228), L" ");
		v10 = nox_wcstok(0, L" ");
		nox_sprintf(v22, "%S", v10);
		v11 = nox_script_indexByEvent(v22);
		if (v11 != -1 && nox_console_playerWhoSent_823692) {
			v12 = nox_strman_loadString_40F1D0("ExecutingFunction", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
											   4332);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v12, v10);
			nox_script_callByIndex_507310(v11, nox_console_playerWhoSent_823692->playerUnit,
										  nox_console_playerWhoSent_823692->playerUnit);
			nox_console_playerWhoSent_823692 = 0;
		} else {
			v21 = v10;
			v9 = nox_strman_loadString_40F1D0("InvalidFunction", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
											  4329);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v9, v21);
			nox_console_playerWhoSent_823692 = 0;
		}
		return 1;
	case 2:
		if (!sub_4D12A0(pl->playerInd) && pl->playerInd != nox_player_netCode_85319C &&
			!nox_common_gameFlags_check_40A5C0(2048)) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		v19 = (char*)nox_console_playerWhoSent_823692 + 4704;
		v13 = nox_strman_loadString_40F1D0("RemoteSysop", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4345);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v13, v19, a3);
		nox_server_parseCmdText_443C80(a3, 0);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	case 3:
		nox_xxx_printToAll_4D9FD0(0, a3);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	case 4:
		if (!(*(uint8_t*)(v3 + 3680) & 1) && !(nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ))) {
			if (nox_common_gameFlags_check_40A5C0(1)) {
				v16 = nox_strman_loadString_40F1D0("notinobserver", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												   4392);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v16);
				nox_console_playerWhoSent_823692 = 0;
				return 1;
			}
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		if (!*a3) {
			nox_xxx_playerCameraUnlock_4E6040(*(uint32_t*)(v3 + 2056));
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		v17 = nox_common_playerInfoGetFirst_416EA0();
		if (!v17) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		do {
			if (!_nox_wcsicmp(a3, (const wchar_t*)v17 + 2352)) {
				nox_xxx_playerCameraFollow_4E6060(nox_console_playerWhoSent_823692->playerUnit,
												  *((uint32_t*)v17 + 514));
			}
			v17 = nox_common_playerInfoGetNext_416EE0((int)v17);
		} while (v17);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	case 5:
		nox_xxx_printToAll_4D9FD0(16, a3);
		v14 = nox_common_playerInfoGetFirst_416EA0();
		if (!v14) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		do {
			v15 = *((uint32_t*)v14 + 514);
			if (v15) {
				nox_xxx_aud_501960(902, v15, 0, 0);
			}
			v14 = nox_common_playerInfoGetNext_416EE0((int)v14);
		} while (v14);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	default:
		v20 = v3 + 4704;
		v18 = nox_strman_loadString_40F1D0("invalidattempt", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4400);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v18, v20, a3);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	}
	return result;
}
// 443FC8: variable 'v7' is possibly undefined

//----- (00440CC0) --------------------------------------------------------
int nox_cmd_offonly1(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_xxx_wndGuiTeamCreate_4185B0();
	return 1;
}

//----- (00440CE0) --------------------------------------------------------
int nox_cmd_offonly2(int tokInd, int tokCnt, wchar_t** tokens) {
	int result;        // eax
	char* v4;          // ebx
	const wchar_t* v5; // eax
	int v6;            // edi
	unsigned char* v7; // esi

	if (tokCnt != 3) {
		return 0;
	}
	result = (int)getMemAt(0x5D4594, 822660);
	if (true) // TODO: byte_5D4594 != (unsigned char*)-822660
	{
		v4 = nox_xxx_cliGamedataGet_416590(1);
		v5 = *(const wchar_t**)getMemAt(0x587000, 94400);
		v6 = 0;
		if (*getMemU32Ptr(0x587000, 94400)) {
			v7 = getMemAt(0x587000, 94400);
			while (_nox_wcsicmp(v5, tokens[tokInd])) {
				v5 = (const wchar_t*)*((uint32_t*)v7 + 2);
				v7 += 8;
				++v6;
				if (!v5) {
					return 1;
				}
			}
			*((uint16_t*)v4 + 26) &= 0xE80Fu;
			*((uint16_t*)v4 + 26) |= *getMemU16Ptr(0x587000, 94404 + 8 * v6);
		}
		result = 1;
	}
	return result;
}

//----- (00440FD0) --------------------------------------------------------
int nox_cmd_set_fr(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_xxx_setFrameLimit_43DDE0(1);
	return 1;
}

//----- (00440FF0) --------------------------------------------------------
int nox_cmd_unset_fr(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_xxx_setFrameLimit_43DDE0(0);
	return 1;
}

//----- (00441010) --------------------------------------------------------
int nox_cmd_set_net_debug(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_common_setEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG);
	return 1;
}

//----- (00441030) --------------------------------------------------------
int nox_cmd_unset_net_debug(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG);
	return 1;
}

//----- (00441460) --------------------------------------------------------
int nox_cmd_show_gui(int tokInd, int tokCnt, wchar_t** tokens) {
	int v0 = nox_client_renderGUI_80828 ^ 1;
	nox_client_renderGUI_80828 = v0;
	nox_xxx_xxxRenderGUI_587000_80832 = v0;
	return 1;
}

//----- (004414D0) --------------------------------------------------------
int nox_cmd_show_netstat(int tokInd, int tokCnt, wchar_t** tokens) {
	sub_470A60();
	return 1;
}

//----- (004414E0) --------------------------------------------------------
int nox_cmd_show_info(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
	sub_435F60();
	return 1;
}

//----- (00441500) --------------------------------------------------------
int nox_cmd_show_mem(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_server_currentMapGetFilename_409B30();
	nox_xxx_gameLoopMemDump_413E30();
	return 1;
}

//----- (00441530) --------------------------------------------------------
int nox_cmd_show_rank(int tokInd, int tokCnt, wchar_t** tokens) {
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		sub_4703F0();
	}
	return 1;
}

//----- (004416B0) --------------------------------------------------------
int nox_cmd_show_motd(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_xxx_motd_4467F0();
	return 1;
}

//----- (004416D0) --------------------------------------------------------
int nox_cmd_show_seq(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	sub_48D7B0();
	return 1;
}

//----- (00441740) --------------------------------------------------------
int nox_cmd_list_maps(int tokInd, int tokCnt, wchar_t** tokens) {
	int* v0;       // esi
	int i;         // edi
	bool v2;       // zf
	signed int v3; // edi

	memset(getMemAt(0x5D4594, 822404), 0, 0x100u);
	v0 = nox_common_maplist_first_4D09B0();
	for (i = 1; v0; ++i) {
		sub_4417E0((wchar_t*)getMemAt(0x5D4594, 822404), (const char*)v0 + 12);
		if (!(i % 4)) {
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 103276),
										  getMemAt(0x5D4594, 822404));
			*getMemU16Ptr(0x5D4594, 822404) = 0;
		}
		v0 = nox_common_maplist_next_4D09C0(v0);
	}
	v3 = (i - 1) & 0x80000003;
	v2 = v3 == 0;
	if (v3 < 0) {
		v2 = (((uint8_t)v3 - 1) | 0xFFFFFFFC) == (unsigned int)-1;
	}
	if (!v2) {
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 103284),
									  getMemAt(0x5D4594, 822404));
	}
	return 1;
}

//----- (00441870) --------------------------------------------------------
int nox_cmd_log_file(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt == 3) {
		if (tokens[2]) {
			nox_common_setEngineFlag(NOX_ENGINE_FLAG_LOG_TO_FILE);
			char v4[256];
			nox_sprintf(v4, "%S", tokens[2]);
			return nox_xxx_log_4_reopen_413A80(v4);
		}
	}
	return 0;
}

//----- (004418D0) --------------------------------------------------------
int nox_cmd_log_console(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_common_setEngineFlag(NOX_ENGINE_FLAG_LOG_TO_CONSOLE);
	return 1;
}

//----- (004418F0) --------------------------------------------------------
int nox_cmd_log_stop(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_xxx_log_4_close_413C00();
	return 1;
}

//----- (00441D20) --------------------------------------------------------
int nox_cmd_set(int tokInd, int tokCnt, wchar_t** tokens) { return 1; }

//----- (00441D30) --------------------------------------------------------
int nox_cmd_cheat_ability(int tokInd, int tokCnt, wchar_t** tokens) {
	char* i; // esi

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			if (*((uint32_t*)i + 514)) {
				nox_xxx_playerCancelAbils_4FC180(*((uint32_t*)i + 514));
			}
		}
	}
	return 1;
}

//----- (00441F50) --------------------------------------------------------
int nox_cmd_cheat_level(int tokInd, int tokCnt, wchar_t** tokens) {
	char* i;          // esi
	unsigned char v5; // al

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		if (tokCnt < 3) {
			return 0;
		}
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			if (*((uint32_t*)i + 514)) {
				v5 = nox_wcstol(tokens[2], 0, 10);
				sub_4EF410(*((uint32_t*)i + 514), v5);
			}
		}
	}
	return 1;
}

//----- (00442340) --------------------------------------------------------
int nox_cmd_window(int tokInd, int tokCnt, wchar_t** tokens) {
	const wchar_t* v3; // eax
	int v4;            // eax
	int v6;            // eax

	if (tokCnt > 1) {
		v3 = tokens[tokInd];
		if (*v3 != 43 && *v3 != 45) {
			v4 = nox_wcstol(v3, 0, 10);
			nox_draw_setCutSize_476700(v4, 0);
			return 1;
		}
		v6 = nox_wcstol(v3, 0, 10);
		nox_draw_setCutSize_476700(0, v6);
	}
	return 1;
}

//----- (00442750) --------------------------------------------------------
int nox_cmd_set_qual_modem(int tokInd, int tokCnt, wchar_t** tokens) {
	dword_5d4594_2650652 = 1;
	int v0 = sub_40A710(4);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 4;
	sub_4AD840();
	return 1;
}

//----- (00442780) --------------------------------------------------------
int nox_cmd_set_qual_isdn(int tokInd, int tokCnt, wchar_t** tokens) {
	dword_5d4594_2650652 = 1;
	int v0 = sub_40A710(3);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 3;
	sub_4AD840();
	return 1;
}

//----- (004427B0) --------------------------------------------------------
int nox_cmd_set_qual_cable(int tokInd, int tokCnt, wchar_t** tokens) {
	dword_5d4594_2650652 = 1;
	int v0 = sub_40A710(2);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 2;
	sub_4AD840();
	return 1;
}

//----- (004427E0) --------------------------------------------------------
int nox_cmd_set_qual_t1(int tokInd, int tokCnt, wchar_t** tokens) {
	dword_5d4594_2650652 = 1;
	int v0 = sub_40A710(1);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 1;
	sub_4AD840();
	return 1;
}

//----- (00442810) --------------------------------------------------------
int nox_cmd_set_qual_lan(int tokInd, int tokCnt, wchar_t** tokens) {
	dword_5d4594_2650652 = 0;
	int v0 = sub_40A710(1);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 1;
	sub_4AD840();
	return 1;
}

//----- (00443400) --------------------------------------------------------
int nox_cmd_set_time(int tokInd, int tokCnt, wchar_t** tokens) {
	char* v4;          // esi
	const wchar_t* v5; // eax
	unsigned char v6;  // al

	if (tokCnt != 3) {
		return 0;
	}
	v4 = sub_4165B0();
	v5 = tokens[2];
	if (v5) {
		v6 = nox_wcstol(v5, 0, 10);
		sub_40A040_settings(*((uint16_t*)v4 + 26), v6);
	}
	return 1;
}

//----- (00443440) --------------------------------------------------------
int nox_cmd_set_lessons(int tokInd, int tokCnt, wchar_t** tokens) {
	const wchar_t* v4; // esi
	char* v5;          // edi
	unsigned short v6; // ax

	if (tokCnt != 3) {
		return 0;
	}
	v4 = tokens[2];
	v5 = sub_4165B0();
	if (v4) {
		v6 = nox_wcstol(v4, 0, 10);
		sub_409FB0_settings(*((uint16_t*)v5 + 26), v6);
	}
	return 1;
}

//----- (004435D0) --------------------------------------------------------
int nox_cmd_menu_options(int tokInd, int tokCnt, wchar_t** tokens) {
	if (!nox_common_gameFlags_check_40A5C0(8) && nox_common_gameFlags_check_40A5C0(0x2000)) {
		nox_xxx_guiServerOptsLoad_457500();
	}
	return 1;
}

//----- (00443600) --------------------------------------------------------
int nox_cmd_menu_vidopt(int tokInd, int tokCnt, wchar_t** tokens) {
	sub_4ADA40();
	return 1;
}

//----- (004420F0) --------------------------------------------------------
int nox_cmd_reenter(int tokInd, int tokCnt, wchar_t** tokens) {
	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		sub_40AA60(1);
	}
	return 1;
}
