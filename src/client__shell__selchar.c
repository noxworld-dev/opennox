#include "client__shell__selchar.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "client__gui__guisave.h"
#include "client__gui__window.h"
#include "client__shell__mainmenu.h"
#include "client__shell__optsback.h"
#include "common/fs/nox_fs.h"
#include "common__strman.h"
#include "server__system__server.h"
extern uint32_t dword_5d4594_1307780;

char nox_savegame_name_1307752[9] = {0};
nox_gui_animation* nox_wnd_xxx_1307748 = 0;
void* dword_5d4594_1307764 = 0;
void* dword_5d4594_1307744 = 0;
void* dword_5d4594_1307776 = 0;
void* dword_5d4594_1307768 = 0;

//----- (004A4DB0) --------------------------------------------------------
int nox_game_showSelChar_4A4DB0() {
	int result;   // eax
	uint32_t* v1; // esi
	uint32_t* v2; // esi
	uint32_t* v3; // esi
	wchar_t* v4;  // eax
	uint32_t* v5; // eax
	uint32_t* v6; // eax
	uint32_t* v7; // esi
	wchar_t* v8;  // eax
	uint32_t* v9; // eax

	nox_client_setCursorType_477610(0);
	if (sub_4D6F30()) {
		sub_4D6F90(1);
	}
	nox_game_addStateCode_43BDD0(500);
	sub_4A1BE0(1);
	result = nox_new_window_from_file("SelChar.wnd", nox_xxx_windowSelCharProc_4A5710);
	dword_5d4594_1307764 = result;
	if (!result) {
		return 0;
	}
	nox_xxx_wndSetWindowProc_46B300(result, sub_4A18E0);
	result = nox_gui_makeAnimation_43C5B0(dword_5d4594_1307764, 0, 0, 0, -440, 0, 20, 0, -40);
	nox_wnd_xxx_1307748 = result;
	if (!result) {
		return 0;
	}
	nox_wnd_xxx_1307748->field_0 = 500;
	nox_wnd_xxx_1307748->field_12 = sub_4A50A0;
	nox_wnd_xxx_1307748->fnc_done_out = sub_4A50D0;
	dword_5d4594_1307744 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 510);
	dword_5d4594_1307776 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 511);
	dword_5d4594_1307768 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 512);
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_1307744, nox_xxx_windowSelCharProc_4A5710);
	sub_46B120(dword_5d4594_1307776, dword_5d4594_1307744);
	sub_46B120(dword_5d4594_1307768, dword_5d4594_1307744);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v5 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 504);
		nox_window_set_hidden(v5, 1);
		v6 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 505);
		nox_window_set_hidden(v6, 1);
		v7 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 509);
		v8 = nox_strman_loadString_40F1D0("LoadLabel", 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 746);
		sub_46AEE0(v7, v8);
	} else {
		v1 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 504);
		nox_window_call_field_94(dword_5d4594_1307744, 16408, v1, 0);
		nox_window_call_field_94(dword_5d4594_1307776, 16408, v1, 0);
		nox_window_call_field_94(dword_5d4594_1307768, 16408, v1, 0);
		v2 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 505);
		nox_window_call_field_94(dword_5d4594_1307744, 16409, v2, 0);
		nox_window_call_field_94(dword_5d4594_1307776, 16409, v2, 0);
		nox_window_call_field_94(dword_5d4594_1307768, 16409, v2, 0);
		v3 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 509);
		v4 = nox_strman_loadString_40F1D0("LoadCharLabel", 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 735);
		sub_46AEE0(v3, v4);
	}
	nox_xxx_findAutosaves_4A5150();
	sub_4A19F0("OptsBack.wnd:Back");
	nox_xxx_wndRetNULL_46A8A0();
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		nox_xxx_setAdminFlag();
	} else {
		nox_xxx_clearAdminFlag();
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
		v9 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 502);
		nox_window_call_field_94(dword_5d4594_1307764, 16391, v9, 0);
	}
	return 1;
}

//----- (004A5150) --------------------------------------------------------
int nox_xxx_findAutosaves_4A5150() {
	size_t v0;                             // ebp
	uint32_t* v1;                          // eax
	char* v2;                              // edi
	int result;                            // eax
	HANDLE v7;                             // eax
	void* v8;                              // esi
	size_t v9;                             // ebp
	HANDLE v10;                            // edi
	int v11;                               // esi
	int v12;                               // esi
	size_t v13;                            // ebx
	wchar_t* v14;                          // eax
	unsigned int v15;                      // edi
	wchar_t* v16;                          // eax
	char* v17;                             // eax
	uint32_t* v18;                         // eax
	uint32_t* v19;                         // eax
	uint32_t* v20;                         // esi
	uint32_t* v21;                         // eax
	uint32_t* v22;                         // eax
	uint32_t* v23;                         // eax
	int v24;                               // [esp-Ch] [ebp-C18h]
	wchar_t* v25;                          // [esp-Ch] [ebp-C18h]
	wchar_t* v26;                          // [esp-8h] [ebp-C14h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+Ch] [ebp-C00h]
	char v28[64];                          // [esp+14Ch] [ebp-AC0h]
	wchar_t v29[64];                       // [esp+18Ch] [ebp-A80h]
	wchar_t v30[256];                      // [esp+20Ch] [ebp-A00h]
	char PathName[1024];                   // [esp+40Ch] [ebp-800h]
	char v32[1024];                        // [esp+80Ch] [ebp-400h]

	v0 = 0;
	v1 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 501);
	nox_xxx_wnd_46ABB0((int)v1, 1);
	v2 = nox_fs_root();
	strcpy(PathName, v2);
	strcat(PathName, "\\Save\\");
	nox_fs_mkdir(PathName);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		dword_5d4594_1307780 = calloc(NOX_SAVEGAME_XXX_MAX, sizeof(nox_savegame_xxx));
		return nox_savegame_sub_46CE40(dword_5d4594_1307744, dword_5d4594_1307776, dword_5d4594_1307768, *(uint8_t**)&dword_5d4594_1307780);
	}
	nox_fs_set_workdir(PathName);
	strcpy(v32, PathName);
	v7 = FindFirstFileA("*.plr", &FindFileData);
	v8 = v7;
	if (v7 != (HANDLE)-1) {
		if (!(FindFileData.dwFileAttributes & 0x10)) {
			v0 = 1;
		}
		if (FindNextFileA(v7, &FindFileData)) {
			do {
				if (!(FindFileData.dwFileAttributes & 0x10)) {
					++v0;
				}
			} while (FindNextFileA(v8, &FindFileData));
		}
		FindClose(v8);
	}
	dword_5d4594_1307780 = calloc(v0, sizeof(nox_savegame_xxx));
	v9 = 0;
	v10 = FindFirstFileA("*.plr", &FindFileData);
	if (v10 != (HANDLE)-1) {
		if (!(FindFileData.dwFileAttributes & 0x10)) {
			nox_sprintf(PathName, "%s%s", v32, FindFileData.cFileName);
			sub_41A000(PathName, *(uint8_t**)&dword_5d4594_1307780);
			if (sub_4A5690(*(uint8_t**)&dword_5d4594_1307780) == 1) {
				v9 = 1;
			}
		}
		if (FindNextFileA(v10, &FindFileData)) {
			v11 = sizeof(nox_savegame_xxx) * v9;
			do {
				if (!(FindFileData.dwFileAttributes & 0x10)) {
					nox_sprintf(PathName, "%s%s", v32, FindFileData.cFileName);
					sub_41A000(PathName, (uint8_t*)(v11 + dword_5d4594_1307780));
					if (sub_4A5690((uint8_t*)(v11 + dword_5d4594_1307780)) == 1) {
						++v9;
						v11 += sizeof(nox_savegame_xxx);
					}
				}
			} while (FindNextFileA(v10, &FindFileData));
		}
		FindClose(v10);
	}
	qsort(dword_5d4594_1307780, v9, sizeof(nox_savegame_xxx), sub_4A4CB0);
	if (v9) {
		v12 = 0;
		v13 = v9;
		do {
			nox_sprintf(v28, "nox.str:%s", *getMemU32Ptr(0x587000, 29456 + 4 * *(unsigned char*)(v12 + dword_5d4594_1307780 + 1274)));
			v26 = nox_strman_loadString_40F1D0(v28, 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 285);
			v24 = v12 + dword_5d4594_1307780 + 1224;
			v14 = nox_strman_loadString_40F1D0("GuiInv.c:ElaborateNameFormat", 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 283);
			nox_swprintf(v30, v14, v24, v26);
			if (*(uint8_t*)(v12 + dword_5d4594_1307780) & 4) {
				// save game text
				v15 = *(unsigned char*)(v12 + dword_5d4594_1307780 + 1277);
				if (v15 < 1) {
					v15 = 1;
				}
				nox_wcscat(v30, L" - ");
				v16 = nox_strman_loadString_40F1D0("Noxworld.c:Stage", 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 298);
				nox_wcscat(v30, v16);
				nox_swprintf(v29, L" %d", v15);
				nox_wcscat(v30, v29);
			}
			nox_window_call_field_94(dword_5d4594_1307744, 16397, (int)getMemAt(0x587000, 170708), 14);
			nox_window_call_field_94(dword_5d4594_1307768, 16397, (int)v30, 14);
			if (*(uint8_t*)(v12 + dword_5d4594_1307780) & 4) {
				v25 = nox_strman_loadString_40F1D0("Noxworld.c:Quest", 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 316);
			} else {
				v25 = nox_strman_loadString_40F1D0("Multiplayer", 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 325);
			}
			nox_window_call_field_94(dword_5d4594_1307776, 16397, (int)v25, 14);
			v12 += sizeof(nox_savegame_xxx);
			--v13;
		} while (v13);
	}
	v17 = nox_fs_root();
	nox_fs_set_workdir(v17);
	if (v9) {
		v18 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 503);
		nox_xxx_wnd_46ABB0(v18, 1);
		v19 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 502);
		nox_xxx_wnd_46ABB0(v19, 1);
		v20 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 501);
		if ((nox_xxx_isQuest_4D6F50() || sub_4D6F70()) && nox_client_countPlayerFiles04_4DC7D0() >= 14) {
			nox_xxx_wnd_46ABB0(v20, 0);
		} else {
			nox_xxx_wnd_46ABB0(v20, 1);
		}
	} else {
		v21 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 503);
		nox_xxx_wnd_46ABB0(v21, 0);
		v22 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 502);
		nox_xxx_wnd_46ABB0(v22, 0);
		v23 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1307764, 501);
		nox_xxx_wnd_46ABB0(v23, 1);
	}
	result = dword_5d4594_1307776;
	if (*(uint16_t*)(*(uint32_t*)((uint32_t)dword_5d4594_1307776 + 32) + 46)) {
		nox_window_call_field_94(dword_5d4594_1307776, 16403, 0, 0);
		result = nox_window_call_field_94(dword_5d4594_1307768, 16403, 0, 0);
	}
	return result;
}
//----- (004A5710) --------------------------------------------------------
int nox_xxx_windowSelCharProc_4A5710(int a1, unsigned int a2, nox_window* a3p, int a4) {
	int* a3 = a3p;
	int v5;                             // eax
	wchar_t* v6;                        // eax
	int v7;                             // ebx
	int v8;                             // eax
	bool v9;                            // zf
	int v10;                            // eax
	char* v11;                          // eax
	char* v12;                          // eax
	int v13;                            // eax
	int v14;                            // eax
	wchar_t* v15;                       // [esp-18h] [ebp-938h]
	int v16;                            // [esp-14h] [ebp-934h]
	int (*v17)();                       // [esp-10h] [ebp-930h]
	int v18;                            // [esp-10h] [ebp-930h]
	int v19;                            // [esp-Ch] [ebp-92Ch]
	char v20[12];                       // [esp+4h] [ebp-91Ch]
	char v21[16];                       // [esp+10h] [ebp-910h]
	char v22[1024];                     // [esp+20h] [ebp-900h]
	char v23[sizeof(nox_savegame_xxx)]; // [esp+420h] [ebp-500h]

	if (a2 <= 0x4007) {
		if (a2 != 16391) {
			if (a2 == 2) {
				if (nox_xxx_wndGetID_46B0A0(a3) == 500) {
					free(dword_5d4594_1307780);
					return 0;
				}
			} else if (a2 == 16389) {
				nox_xxx_clientPlaySoundSpecial_452D80(920, 100);
				return 1;
			}
			return 0;
		}
		switch (nox_xxx_wndGetID_46B0A0(a3)) {
		case 501:
			nox_server_SetFirstObjectScriptID_4E3C60(1000000000);
			sub_4A50A0();
			nox_wnd_xxx_1307748->field_13 = nox_game_showSelClass_4A4840;
			goto LABEL_40;
		case 502:
			v7 = *(uint32_t*)((uint32_t)dword_5d4594_1307776 + 32);
			v8 = *(uint32_t*)(v7 + 48);
			if (v8 != -1) {
				if (!strlen((const char*)(dword_5d4594_1307780 + sizeof(nox_savegame_xxx) * v8 + 4))) {
					goto LABEL_38;
				}
				nox_savegame_nameFromPath_4DC970((char*)(dword_5d4594_1307780 + sizeof(nox_savegame_xxx) * v8 + 4),
												 v20);
				if ((!nox_common_gameFlags_check_40A5C0(2048) ||
					 nox_client_copySave_4DC100((int)v20, "WORKING")) &&
					sub_41A000((char*)(dword_5d4594_1307780 + sizeof(nox_savegame_xxx) * *(uint32_t*)(v7 + 48) + 4),
							   v23)) {
					memcpy(getMemAt(0x85B3FC, 10980), v23, 0x4FCu);
					*getMemU16Ptr(0x85B3FC, 12256) = *(uint16_t*)&v23[1276];
					nox_game_decStateInd_43BDC0();
					if (getMemByte(0x85B3FC, 12254) == 0) {
						nox_xxx_gameSetMapPath_409D70("war01a.map");
					} else if (getMemByte(0x85B3FC, 12254) == 1) {
						nox_xxx_gameSetMapPath_409D70("wiz01a.map");
					} else if (getMemByte(0x85B3FC, 12254) == 2) {
						nox_xxx_gameSetMapPath_409D70("con01a.map");
					}
					if (nox_common_gameFlags_check_40A5C0(2048)) {
						nox_xxx_gameSetSwitchSolo_4DB220(1);
						nox_xxx_gameSetNoMPFlag_4DB230(1);
						nox_sprintf(v21, "%s.map",
									dword_5d4594_1307780 + sizeof(nox_savegame_xxx) * *(uint32_t*)(v7 + 48) + 1156);
						v9 = nox_client_checkSaveMapExistsTmp_4DB2A0(v21) == 0;
						v10 = *(uint32_t*)(v7 + 48);
						v19 = dword_5d4594_1307780 + sizeof(nox_savegame_xxx) * v10 + 1156;
						v18 = dword_5d4594_1307780 + sizeof(nox_savegame_xxx) * v10 + 1156;
						if (v9) {
							v12 = nox_fs_root();
							nox_sprintf(v22, "%s\\Maps\\%s\\%s.map", v12, v18, v19);
						} else {
							v11 = nox_fs_root();
							nox_sprintf(v22, "%s\\Save\\%s\\%s\\%s.map", v11, "WORKING", v18, v19);
						}
						nox_xxx_gameSetSoloSavePath_4DB270(v22);
						nox_xxx_gameSetMapPath_409D70(v21);
						nox_xxx_mapLoadOrSaveMB_4DCC70(1);
						v13 = sub_41D090(
							(char*)(dword_5d4594_1307780 + sizeof(nox_savegame_xxx) * *(uint32_t*)(v7 + 48) + 4));
						nox_server_SetFirstObjectScriptID_4E3C60(v13);
					} else if (sub_4D6F30()) {
						sub_4DCE60(*(unsigned char*)(dword_5d4594_1307780 +
													 sizeof(nox_savegame_xxx) * *(uint32_t*)(v7 + 48) + 1277));
						sub_4DCE80((const char*)(dword_5d4594_1307780 +
												 sizeof(nox_savegame_xxx) * *(uint32_t*)(v7 + 48) + 1156));
						v14 = sub_41D090(
							(char*)(dword_5d4594_1307780 + sizeof(nox_savegame_xxx) * *(uint32_t*)(v7 + 48) + 4));
						nox_server_SetFirstObjectScriptID_4E3C60(v14);
					}
					sub_4A24C0(0);
					sub_4A50A0();
					nox_wnd_xxx_1307748->field_13 = 0;
				}
			}
			goto LABEL_40;
		case 503:
			v5 = *(uint32_t*)(*(uint32_t*)((uint32_t)dword_5d4594_1307776 + 32) + 48);
			if (v5 == -1) {
				goto LABEL_40;
			}
			*getMemU32Ptr(0x5D4594, 1307772) = *(uint32_t*)(*(uint32_t*)((uint32_t)dword_5d4594_1307776 + 32) + 48);
			nox_savegame_nameFromPath_4DC970((char*)(dword_5d4594_1307780 + sizeof(nox_savegame_xxx) * v5 + 4),
											 nox_savegame_name_1307752);
			if (nox_common_gameFlags_check_40A5C0(2048) && !strcmp(nox_savegame_name_1307752, "AUTOSAVE")) {
				nox_xxx_clientPlaySoundSpecial_452D80(925, 100);
				v17 = 0;
				v16 = 33;
				v15 = nox_strman_loadString_40F1D0("GUISave.c:AutoSaveDeleteNotAllowed", 0,
												   "C:\\NoxPost\\src\\client\\shell\\selchar.c", 466);
				v6 = nox_strman_loadString_40F1D0("GUISave.c:AutoSaveDeleteTitle", 0,
												  "C:\\NoxPost\\src\\client\\shell\\selchar.c", 465);
			} else {
				if (!strlen((const char*)(dword_5d4594_1307780 +
										  sizeof(nox_savegame_xxx) * *getMemU32Ptr(0x5D4594, 1307772) + 4))) {
				LABEL_38:
					nox_xxx_clientPlaySoundSpecial_452D80(925, 100);
					goto LABEL_40;
				}
				v17 = sub_4A5C70;
				v16 = 56;
				if (nox_common_gameFlags_check_40A5C0(2048)) {
					v15 = nox_strman_loadString_40F1D0("GUISave.c:DeleteSaveMessage", 0,
													   "C:\\NoxPost\\src\\client\\shell\\selchar.c", 480);
					v6 = nox_strman_loadString_40F1D0("GUISave.c:DeleteSaveTitle", 0,
													  "C:\\NoxPost\\src\\client\\shell\\selchar.c", 479);
				} else {
					v15 = nox_strman_loadString_40F1D0("GUISave.c:DeleteCharacterMessage", 0,
													   "C:\\NoxPost\\src\\client\\shell\\selchar.c", 488);
					v6 = nox_strman_loadString_40F1D0("GUISave.c:DeleteCharacterTitle", 0,
													  "C:\\NoxPost\\src\\client\\shell\\selchar.c", 487);
				}
			}
			nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v6, (int)v15, v16, v17, 0);
		LABEL_40:
			nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
			return 1;
		case 504:
		case 505:
			nox_window_call_field_94(dword_5d4594_1307744, 0x4000, (int)a3, 0);
			nox_window_call_field_94(dword_5d4594_1307776, 0x4000, (int)a3, 0);
			nox_window_call_field_94(dword_5d4594_1307768, 0x4000, (int)a3, 0);
			goto LABEL_40;
		default:
			goto LABEL_40;
		}
	}
	if (a2 == 16400) {
		nox_window_call_field_94(dword_5d4594_1307744, 16403, a4, 0);
		nox_window_call_field_94(dword_5d4594_1307776, 16403, a4, 0);
		nox_window_call_field_94(dword_5d4594_1307768, 16403, a4, 0);
	}
	return 0;
}
