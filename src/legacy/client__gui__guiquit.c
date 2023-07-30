#include "client__gui__guiquit.h"
#include "client__gui__window.h"
#include "common__strman.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_1.h"
#include "client__gui__guisave.h"
#include "client__gui__guivote.h"
#include "client__gui__servopts__guiserv.h"
#include "client__system__parsecmd.h"
#include "common__system__team.h"
#include "common__log.h"
#include "operators.h"

extern uint32_t nox_player_netCode_85319C;


nox_window* nox_wnd_quitMenu_825760 = 0;

//----- (00445840) --------------------------------------------------------
int nox_xxx_menuGameOnButton_445840(uint32_t* a1, int a2, int* a3, int a4) {
	int v3;        // esi
	int v4;        // eax
	int result;    // eax
	int v6;        // eax
	int v7;        // eax
	char* v8;      // eax
	int v9;        // eax
	int v10;       // eax
	int v12;       // eax
	wchar2_t* v13;  // eax
	int v14;       // eax
	wchar2_t* v15;  // eax
	int v16;       // eax
	int v17;       // eax
	int v18;       // ecx
	uint32_t* v19; // eax
	int v20;       // eax
	int v21;       // eax
	wchar2_t* v22;  // [esp-18h] [ebp-18h]
	wchar2_t* v23;  // [esp-18h] [ebp-18h]

	if (a2 != 16391) {
		return 0;
	}
	v3 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	switch (v3) {
	case 9001:
		sub_445C40();
		sub_413A00(1);
		if (!nox_common_gameFlags_check_40A5C0(2048) || nox_xxx_playerAnimCheck_4372B0()) {
			sub_445B40();
			v17 = a3[9];
			LOBYTE(v17) = v17 & 0xFD;
			a3[9] = v17;
			result = 0;
		} else {
			v23 = nox_strman_loadString_40F1D0("GUIQuit.c:ReallyLoadMessage", 0,
											   "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 199);
			v15 =
				nox_strman_loadString_40F1D0("SelChar.c:LoadLabel", 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 198);
			nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v15, (int)v23, 56, sub_445B40, sub_445BA0);
			v16 = a3[9];
			LOBYTE(v16) = v16 & 0xFD;
			a3[9] = v16;
			result = 0;
		}
		break;
	case 9002:
		v18 = *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 120);
		if ((v18 & 0x8000) == 0) {
			sub_445C40();
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				nox_setSaveFileName_4DB130("AUTOSAVE");
				sub_4DB170(1, 0, 0);
			}
			v21 = a3[9];
			LOBYTE(v21) = v21 & 0xFD;
			a3[9] = v21;
			result = 0;
			break;
		}
		v19 = nox_xxx_wndGetChildByID_46B0C0(a1, v3);
		nox_xxx_wnd_46ABB0((int)v19, 0);
		v20 = a3[9];
		LOBYTE(v20) = v20 & 0xFD;
		a3[9] = v20;
		result = 0;
		break;
	case 9003:
		sub_445C40();
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			nox_savegame_sub_46D580();
		} else {
			nox_xxx_netSavePlayer_41CE00();
		}
		if (sub_43C6E0()) {
			v21 = a3[9];
			LOBYTE(v21) = v21 & 0xFD;
			a3[9] = v21;
			result = 0;
			break;
		}
		sub_43CF70();
		v12 = a3[9];
		LOBYTE(v12) = v12 & 0xFD;
		a3[9] = v12;
		result = 0;
		break;
	case 9004:
		nox_xxx_wndClearCaptureMain_46ADE0(nox_wnd_quitMenu_825760);
		v22 = nox_strman_loadString_40F1D0("GUIQuit.c:ReallyQuitMessage", 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c",
										   185);
		v13 = nox_strman_loadString_40F1D0("GUIQuit.c:ReallyQuitTitle", 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c",
										   184);
		nox_xxx_dialogMsgBoxCreate_449A10(nox_wnd_quitMenu_825760, (int)v13, (int)v22, 56, nox_xxx_quitDialogYes_445B20,
										  nox_xxx_quitDialogNo_445B30);
		v14 = a3[9];
		LOBYTE(v14) = v14 & 0xFD;
		a3[9] = v14;
		result = 0;
		break;
	case 9005:
		sub_445C40();
		sub_4ADA40();
		v4 = a3[9];
		LOBYTE(v4) = v4 & 0xFD;
		a3[9] = v4;
		result = 0;
		break;
	case 9006:
		sub_445C40();
		v9 = a3[9];
		LOBYTE(v9) = v9 & 0xFD;
		a3[9] = v9;
		result = 0;
		break;
	case 9007:
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v8 = nox_common_playerInfoGetByID_417040(nox_player_netCode_85319C);
			nox_xxx_serverHandleClientConsole_443E90((int)v8, 0, 0);
			sub_445C40();
			v9 = a3[9];
			LOBYTE(v9) = v9 & 0xFD;
			a3[9] = v9;
			result = 0;
		} else {
			nox_xxx_netServerCmd_440950_empty();
			sub_445C40();
			v7 = a3[9];
			LOBYTE(v7) = v7 & 0xFD;
			a3[9] = v7;
			result = 0;
		}
		break;
	case 9008:
		sub_445C40();
		nox_xxx_guiServerOptsLoad_457500();
		v10 = a3[9];
		LOBYTE(v10) = v10 & 0xFD;
		a3[9] = v10;
		result = 0;
		break;
	case 9009:
		sub_445C40();
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			sub_48CB10(4);
		} else {
			sub_48CB10(0);
		}
		v6 = a3[9];
		LOBYTE(v6) = v6 & 0xFD;
		a3[9] = v6;
		result = 0;
		break;
	default:
		v21 = a3[9];
		LOBYTE(v21) = v21 & 0xFD;
		a3[9] = v21;
		result = 0;
		break;
	}
	return result;
}

//----- (00445C40) --------------------------------------------------------
void sub_445C40() {
	int result;    // eax
	uint32_t* v1;  // eax
	uint32_t* v2;  // eax
	uint32_t* v3;  // eax
	uint32_t* v4;  // eax
	uint32_t* v5;  // eax
	uint32_t* v6;  // esi
	uint32_t* v7;  // eax
	uint32_t* v8;  // eax
	uint32_t* v9;  // eax
	uint32_t* v10; // eax
	uint32_t* v11; // esi
	uint32_t* v12; // eax
	uint32_t* v13; // esi
	uint32_t* v14; // eax
	uint32_t* v15; // eax
	uint32_t* v16; // eax
	uint32_t* v17; // eax
	uint32_t* v18; // eax
	uint32_t* v19; // eax
	wchar2_t* v20;  // [esp-4h] [ebp-8h]
	wchar2_t* v21;  // [esp-4h] [ebp-8h]

	if (nox_xxx_wndGetFlags_46ADA0(nox_wnd_quitMenu_825760) & 0x10) {
		if (!*getMemU32Ptr(0x852978, 8) || !nox_common_gameFlags_check_40A5C0(2048) ||
			(result = *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 276), result != 2) && result != 1 && result != 51) {
			if (sub_45D9B0() != 1) {
				if (nox_xxx_checkGameFlagPause_413A50() != 1) {
					nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
					nox_xxx_wndShowModalMB_46A8C0(nox_wnd_quitMenu_825760);
					nox_wnd_quitMenu_825760->flags |= 8u;
					nox_xxx_wndSetCaptureMain_46ADC0(nox_wnd_quitMenu_825760);
					if (nox_common_gameFlags_check_40A5C0(2048)) {
						v20 = nox_strman_loadString_40F1D0("SoloSaveLabel", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 396);
						v1 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9003);
						sub_46AEE0((int)v1, (int)v20);
						v2 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9001);
						nox_window_set_hidden((int)v2, 0);
						v3 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9002);
						nox_window_set_hidden((int)v3, 0);
						v4 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9007);
						nox_window_set_hidden((int)v4, 1);
						v5 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9008);
						nox_window_set_hidden((int)v5, 1);
						v6 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9009);
						nox_window_set_hidden((int)v6, 1);
						v7 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9004);
						nox_window_setPos_46A9B0(v7, v6[4], v6[5]);
						sub_413A00(1);
						sub_46AB20(nox_wnd_quitMenu_825760, 220, 285);
					} else {
						v21 = nox_strman_loadString_40F1D0("MultiplayerSaveLabel", 0,
														   "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 427);
						v8 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9003);
						sub_46AEE0((int)v8, (int)v21);
						v9 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9001);
						nox_window_set_hidden((int)v9, 1);
						v10 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9002);
						nox_window_set_hidden((int)v10, 1);
						v11 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9007);
						nox_window_set_hidden((int)v11, 0);
						nox_xxx_wnd_46ABB0((int)v11, 1);
						v12 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9008);
						nox_window_set_hidden((int)v12, 0);
						v13 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9009);
						nox_window_set_hidden((int)v13, 0);
						sub_46AEE0((int)v13, (int)getMemAt(0x5D4594, 825772));
						if (nox_common_gameFlags_check_40A5C0(49152) || !nox_xxx_getTeamCounter_417DD0()) {
							nox_xxx_wnd_46ABB0((int)v13, 0);
						} else {
							nox_xxx_wnd_46ABB0((int)v13, 1);
						}
						v14 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9004);
						nox_window_setPos_46A9B0(v14, v13[4], v13[5] + 45);
						sub_46AB20(nox_wnd_quitMenu_825760, 220, 330);
						if (nox_common_gameFlags_check_40A5C0(4096)) {
							v15 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9007);
							nox_xxx_wnd_46ABB0((int)v15, 0);
							v16 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9003);
							nox_xxx_wnd_46ABB0((int)v16, 0);
						}
						if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
							v17 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9007);
							nox_xxx_wnd_46ABB0((int)v17, 0);
							v18 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9005);
							nox_xxx_wnd_46ABB0((int)v18, 0);
							v19 = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9003);
							nox_xxx_wnd_46ABB0((int)v19, 0);
						}
					}
				}
			}
		}
	} else {
		nox_xxx_windowFocus_46B500(0);
		nox_xxx_wndClearCaptureMain_46ADE0(nox_wnd_quitMenu_825760);
		nox_window_set_hidden(nox_wnd_quitMenu_825760, 1);
		nox_wnd_quitMenu_825760->flags &= 0xFFFFFFF7;
		sub_413A00(0);
	}
}
