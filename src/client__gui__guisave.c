#include "client__gui__guisave.h"
#include "client__gui__window.h"
#include "common__strman.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_3.h"
#include "GAME3_2.h"
#include "common/fs/nox_fs.h"

extern uint32_t dword_5d4594_1082868;
extern uint32_t dword_5d4594_1082860;
extern uint32_t dword_5d4594_1082864;
nox_window* dword_5d4594_1082856 = 0;
extern int nox_win_width;
extern int nox_win_height;
extern nox_savegame_xxx nox_savegame_arr_1064948[NOX_SAVEGAME_XXX_MAX];

//----- (0046C730) --------------------------------------------------------
int nox_savegame_sub_46C730() {
	uint32_t* v1; // eax
	uint32_t* v2; // eax
	int i;        // esi
	uint32_t* v4; // eax
	wchar_t* v5;  // eax
	wchar_t* v6;  // eax

	nox_window* win = nox_new_window_from_file("SelChar.wnd", nox_savegame_sub_46C920);
	dword_5d4594_1082856 = win;
	if (!win) {
		return 0;
	}
	win->flags |= 0x20;
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1082856, sub_46CCA0);
	dword_5d4594_1082860 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 510);
	dword_5d4594_1082864 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 511);
	dword_5d4594_1082868 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 512);
	nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1082860, nox_savegame_sub_46C920);
	sub_46B120(*(uint32_t**)&dword_5d4594_1082864, *(int*)&dword_5d4594_1082860);
	sub_46B120(*(uint32_t**)&dword_5d4594_1082868, *(int*)&dword_5d4594_1082860);
	*getMemU32Ptr(0x5D4594, 1082872) = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 501);
	*getMemU32Ptr(0x5D4594, 1082876) = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 502);
	*getMemU32Ptr(0x5D4594, 1082880) = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 503);
	v1 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 504);
	nox_window_set_hidden((int)v1, 1);
	v2 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 505);
	nox_window_set_hidden((int)v2, 1);
	for (i = 500; i <= 512; ++i) {
		v4 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, i);
		if (v4) {
			nox_xxx_wnd_46AD60((int)v4, 1024);
		}
	}
	v5 = nox_strman_loadString_40F1D0("SaveGUISave", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 341);
	sub_46AEE0(*getMemIntPtr(0x5D4594, 1082872), (int)v5);
	v6 = nox_strman_loadString_40F1D0("SaveGUILoad", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 342);
	sub_46AEE0(*getMemIntPtr(0x5D4594, 1082876), (int)v6);
	nox_window_setPos_46A9B0(dword_5d4594_1082856,
							 (nox_win_width - *(int*)((int)dword_5d4594_1082856 + 8)) / 2, 0);
	nox_window_set_hidden(dword_5d4594_1082856, 1);
	nox_xxx_wnd_46ABB0(dword_5d4594_1082856, 0);
	return 1;
}

//----- (0046C920) --------------------------------------------------------
int nox_savegame_sub_46C920(uint32_t* a1, int a2, int* a3, int a4) {
	int v5;        // esi
	int v6;        // eax
	wchar_t* v7;   // eax
	int v8;        // edx
	int v9;        // eax
	uint32_t* v10; // eax
	wchar_t* v11;  // eax
	wchar_t* v12;  // [esp-10h] [ebp-24h]
	wchar_t* v13;  // [esp-10h] [ebp-24h]
	char v14[12];  // [esp+8h] [ebp-Ch]

	if (a2 != 16391) {
		if (a2 != 16400) {
			return 0;
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_1082860, 16403, a4, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1082864, 16403, a4, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1082868, 16403, a4, 0);
		return 0;
	}
	v5 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	if (v5 == 501) {
		v8 = *(uint32_t*)(*(uint32_t*)(dword_5d4594_1082864 + 32) + 48);
		if (v8 < 0) {
			return 0;
		}
		v9 = *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 120);
		if ((v9 & 0x8000) != 0) {
			v10 = nox_xxx_wndGetChildByID_46B0C0(a1, 501);
			nox_xxx_wnd_46ABB0((int)v10, 0);
			return 0;
		}
		if (strlen(&nox_savegame_arr_1064948[v8].path)) {
			nox_savegame_nameFromPath_4DC970(&nox_savegame_arr_1064948[v8].path, (char*)getMemAt(0x5D4594, 1082840));
			nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_1082856);
			v13 = nox_strman_loadString_40F1D0("GUISave.c:OverwriteSaveMessage", 0,
											   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 184);
			v11 = nox_strman_loadString_40F1D0("GUISave.c:OverwriteSaveTitle", 0,
											   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 183);
			nox_xxx_dialogMsgBoxCreate_449A10(dword_5d4594_1082856, (int)v11, (int)v13, 56, sub_46CC70,
											  sub_46CC90);
			return 0;
		}
		if (v8) {
			nox_sprintf(v14, "SAVE%04d", v8);
		} else {
			strcpy(v14, "AUTOSAVE");
		}
		sub_4DB130(v14);
		sub_4DB170(1, 0, 0);
		sub_46D6F0();
		return 0;
	} else if (v5 == 502) {
		v6 = *(uint32_t*)(*(uint32_t*)(dword_5d4594_1082864 + 32) + 48);
		if (v6 >= 0 && strlen(&nox_savegame_arr_1064948[v6].path)) {
			if (nox_xxx_playerAnimCheck_4372B0()) {
				nox_savegame_sub_46CBD0();
				return 0;
			}
			v12 = nox_strman_loadString_40F1D0("GUIQuit.c:ReallyLoadMessage", 0,
											   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 233);
			v7 =
				nox_strman_loadString_40F1D0("SelChar.c:LoadLabel", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 232);
			nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v7, (int)v12, 24, nox_savegame_sub_46CBD0, sub_44A400);
			return 0;
		}
		nox_xxx_clientPlaySoundSpecial_452D80(925, 100);
		return 0;
	} else if (v5 == 503) {
		if (sub_450560()) {
			sub_450580();
			sub_43DDA0();
			nox_xxx_setContinueMenuOrHost_43DDD0(0);
			nox_game_exit_xxx_43DE60();
			sub_446060();
			sub_46D6F0();
			return 0;
		}
		sub_46D6F0();
		return 0;
	}
	return 0;
}

//----- (0046CBD0) --------------------------------------------------------
int nox_savegame_sub_46CBD0() {
	int result;  // eax
	wchar_t* v1; // eax
	wchar_t* v2; // [esp-Ch] [ebp-1Ch]
	char v3[12]; // [esp+4h] [ebp-Ch]

	result = 0;
	int i = *(uint32_t*)(*(uint32_t*)(dword_5d4594_1082864 + 32) + 48);
	if (!strlen(&nox_savegame_arr_1064948[i].path)) {
		return 0;
	}
	nox_savegame_nameFromPath_4DC970(&nox_savegame_arr_1064948[i].path, v3);
	if (!sub_4DB790(v3)) {
		v2 = nox_strman_loadString_40F1D0("SaveErrorTitle", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 75);
		v1 = nox_strman_loadString_40F1D0("SaveErrorTitle", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 74);
		nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v1, (int)v2, 33, 0, 0);
	}
	if (sub_450560()) {
		sub_4505B0();
	}
	sub_44A400();
	return sub_46D6F0();
}

//----- (0046CE40) --------------------------------------------------------
int nox_savegame_sub_46CE40(int a1, int a2, int a3, nox_savegame_xxx* sarr) {
	char* v5;            // eax
	int v9;              // esi
	int v21;             // esi
	uint32_t* v22;       // eax
	uint32_t* v23;       // eax
	uint32_t* v24;       // eax
	int v40;             // [esp+14h] [ebp-1210h]
	char v41[12];        // [esp+18h] [ebp-120Ch]
	wchar_t v42[512];    // [esp+24h] [ebp-1200h]
	char DateStr[256];   // [esp+424h] [ebp-E00h]
	char TimeStr[256];   // [esp+524h] [ebp-D00h]
	char v45[1024];      // [esp+624h] [ebp-C00h]
	char PathName[1024]; // [esp+A24h] [ebp-800h]
	char Buffer[1024];   // [esp+E24h] [ebp-400h]

	nox_fs_workdir(&Buffer, 1024);
	v5 = nox_fs_root();
	nox_sprintf(&PathName, "%s\\Save\\", v5);
	nox_fs_mkdir(&PathName);
	nox_window_call_field_94(a1, 16399, 0, 0);
	nox_window_call_field_94(a2, 16399, 0, 0);
	nox_window_call_field_94(a3, 16399, 0, 0);
	nox_sprintf(&v45, "%sAUTOSAVE\\Player.plr", &PathName);

	int v4 = 0;
	if (sub_41A000(&v45, &sarr[0])) {
		v4 = 1;
	}
	for (int i = 1; i < NOX_SAVEGAME_XXX_MAX; i++) {
		nox_sprintf(&v45, "%sSAVE%04d\\Player.plr", &PathName, i);
		if (sub_41A000(&v45, &sarr[i])) {
			++v4;
		}
	};
	v9 = 0;
	v40 = 0;
	while (1) {
		nox_savegame_xxx* sv = &sarr[v9];
		if (strlen(&sv->path)) {
			nox_savegame_nameFromPath_4DC970(&sv->path, &v41);
			nox_sprintf(&DateStr, "nox.str:%s", *getMemU32Ptr(0x587000, 29456 + 4 * sv->player_class));
			wchar_t* v39 = nox_strman_loadString_40F1D0(&DateStr, 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 667);
			wchar_t* v13 = nox_strman_loadString_40F1D0("the", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 666);
			nox_swprintf(&v42, v13, &sv->player_name, v39);
			if (!strcmp(&v41, "AUTOSAVE")) {
				nox_wcscat(&v42, L" ");
				wchar_t* v14 =
					nox_strman_loadString_40F1D0("AutoSaveLabel", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 674);
				nox_wcscat(&v42, v14);
			} else {
				nox_wcscat(&v42, L" - ");
				wchar_t* v17;
				switch (sv->stage) {
				case 1:;
					char v16 = sv->player_class;
					if (!v16) {
						v17 = nox_strman_loadString_40F1D0("WolChat.c:Nox_Lobby_3", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 688);
					} else if (v16 != 1) {
						v17 = nox_strman_loadString_40F1D0("Noxworld.wnd:VillageIx", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 692);
					} else {
						v17 = nox_strman_loadString_40F1D0("NPC:Horvath", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c",
														   690);
					}
					break;
				case 2:;
					char v18 = sv->player_class;
					if (!v18) {
						v17 = nox_strman_loadString_40F1D0("War02a.scr:Sign5", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 699);
					} else if (v18 != 1) {
						v17 = nox_strman_loadString_40F1D0("NPC:Aldwyn", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c",
														   703);
					} else {
						v17 = nox_strman_loadString_40F1D0("Noxworld.wnd:Galava", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 701);
					}
					break;
				case 3:;
					char v19 = sv->player_class;
					if (!v19) {
						v17 = nox_strman_loadString_40F1D0("Noxworld.wnd:VillageIx", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 710);
					} else if (v19 != 1) {
						v17 = nox_strman_loadString_40F1D0("Noxworld.wnd:Mines", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 714);
					} else {
						v17 = nox_strman_loadString_40F1D0("WolChat.c:Nox_Lobby_9", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 712);
					}
					break;
				case 4:
					v17 = nox_strman_loadString_40F1D0("Noxworld.wnd:FieldValor", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 718);
					break;
				case 5:
					v17 = nox_strman_loadString_40F1D0("Noxworld.wnd:HamletBrin", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 720);
					break;
				case 6:
					v17 = nox_strman_loadString_40F1D0("NPC:Horrendous", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c",
													   722);
					break;
				case 7:
					v17 = nox_strman_loadString_40F1D0("Noxworld.wnd:Galava", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 724);
					break;
				case 8:
					v17 = nox_strman_loadString_40F1D0("Noxworld.wnd:TempleIx", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 726);
					break;
				case 9:
					v17 = nox_strman_loadString_40F1D0("Noxworld.wnd:DismalSwamp", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 728);
					break;
				case 10:;
					v17 = nox_strman_loadString_40F1D0("Noxworld.wnd:LandDead", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 730);
					break;
				case 11:;
					char v20 = sv->player_class;
					if (!v20) {
						v17 = nox_strman_loadString_40F1D0("WolChat.c:Nox_Lobby_47", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 735);
					} else if (v20 == 1) {
						v17 = nox_strman_loadString_40F1D0("NPC:Hecubah", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c",
														   737);
					} else {
						v17 = nox_strman_loadString_40F1D0("Noxworld.wnd:GrokkTorr", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 739);
					}
					break;
				default:
					v17 = nox_strman_loadString_40F1D0("GuiInv.c:IdentifyUnknown", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 743);
					break;
				}
				nox_wcscat(&v42, v17);
			}
			v21 = sub_46CD70(sv);
			nox_window_call_field_94(a1, 16397, (int)getMemAt(0x587000, 145320), v21);
			nox_window_call_field_94(a3, 16397, (int)&v42, v21);
			GetDateFormatA(LOCALE_SYSTEM_DEFAULT, DATE_SHORTDATE, &sv->timestamp, 0, &DateStr, sizeof(DateStr));
			GetTimeFormatA(LOCALE_SYSTEM_DEFAULT, TIME_FORCE24HOURFORMAT | TIME_NOTIMEMARKER | TIME_NOSECONDS,
						   &sv->timestamp, 0, &TimeStr, sizeof(TimeStr));
			nox_swprintf(&v42, L"%S, %S ", &DateStr, &TimeStr);
			nox_window_call_field_94(a2, 16397, (int)&v42, v21);
			v9 = v40;
		} else {
			nox_window_call_field_94(a1, 16397, (int)getMemAt(0x587000, 143900), 3);
			if (v9) {
				wchar_t* v11 =
					nox_strman_loadString_40F1D0("EmptySlot", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 645);
				nox_window_call_field_94(a2, 16397, (int)v11, 3);
				wchar_t* v12 =
					nox_strman_loadString_40F1D0("EmptySlot", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 650);
				nox_window_call_field_94(a3, 16397, (int)v12, 3);
			} else {
				nox_window_call_field_94(a2, 16397, (int)getMemAt(0x587000, 143904), 3);
				nox_window_call_field_94(a3, 16397, (int)getMemAt(0x587000, 143908), 3);
			}
		}
		v40 = ++v9;
		if (v9 >= NOX_SAVEGAME_XXX_MAX) {
			break;
		}
	}
	v22 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 503);
	if (v4 <= 0) {
		nox_xxx_wnd_46ABB0((int)v22, 0);
		v24 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 502);
		nox_xxx_wnd_46ABB0((int)v24, 0);
		nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 501);
	} else {
		nox_xxx_wnd_46ABB0((int)v22, 1);
		v23 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 502);
		nox_xxx_wnd_46ABB0((int)v23, 1);
	}
	int ind = nox_savegame_findLatestSave_46CDC0(sarr);
	if (ind == -1) {
		return -1;
	}
	nox_window_call_field_94(a1, 16403, ind, 0);
	nox_window_call_field_94(a2, 16403, ind, 0);
	return nox_window_call_field_94(a3, 16403, ind, 0);
}

//----- (0046D580) --------------------------------------------------------
void nox_savegame_sub_46D580() {
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		return;
	}
	uint32_t* v1; // esi
	int v2;       // eax
	wchar_t* v3;  // eax
	uint32_t* v4; // esi
	wchar_t* v5;  // eax
	wchar_t* v6;  // eax

	memset(nox_savegame_arr_1064948, 0, NOX_SAVEGAME_XXX_MAX * sizeof(nox_savegame_xxx));
	nox_savegame_sub_46CE40(*(int*)&dword_5d4594_1082860, *(int*)&dword_5d4594_1082864, *(int*)&dword_5d4594_1082868,
							nox_savegame_arr_1064948);
	nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1082856);
	nox_xxx_wnd_46ABB0(dword_5d4594_1082856, 1);
	nox_xxx_wndSetCaptureMain_46ADC0(dword_5d4594_1082856);
	v1 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 501);
	if (sub_450560() && !sub_450570() || (v2 = *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 276), v2 == 2) || v2 == 1 ||
		v2 == 51) {
		nox_xxx_wnd_46ABB0((int)v1, 0);
	} else {
		nox_xxx_wnd_46ABB0((int)v1, 1);
	}
	if (sub_450560()) {
		v3 = nox_strman_loadString_40F1D0("SaveGUIQuit", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 860);
		sub_46AEE0(*getMemIntPtr(0x5D4594, 1082880), (int)v3);
		v4 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 509);
		v5 = nox_strman_loadString_40F1D0("LoadLabel", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 862);
	} else {
		v6 = nox_strman_loadString_40F1D0("SaveGUICancel", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 866);
		sub_46AEE0(*getMemIntPtr(0x5D4594, 1082880), (int)v6);
		v4 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1082856, 509);
		v5 = nox_strman_loadString_40F1D0("SaveLoadLabel", 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 868);
	}
	sub_46AEE0((int)v4, (int)v5);
	sub_413A00(1);
}
