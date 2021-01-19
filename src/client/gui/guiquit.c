#include "guiquit.h"

#include "../../proto.h"
#include "../system/parsecmd.h"
#include "guisave.h"
#include "guivote.h"
#include "servopts/guiserv.h"

extern _DWORD dword_5d4594_825764;
extern _DWORD dword_5d4594_825752;
extern _DWORD dword_5d4594_825768;
extern _DWORD dword_5d4594_825760;
extern _DWORD dword_5d4594_2650652;
extern int nox_win_width;
extern int nox_win_height;

//----- (00445790) --------------------------------------------------------
int nox_xxx_wndLoadQuiteMenu_445790() {
	int result;  // eax
	wchar_t* v1; // eax

	result = nox_new_window_from_file("QuitMenu.wnd", nox_xxx_menuGameOnButton_445840);
	dword_5d4594_825760 = result;
	if (result) {
		nox_window_set_all_funcs((_DWORD*)result, sub_445BB0, nox_xxx_wndDrawQuiteMenu_445BC0, 0);
		*(_DWORD*)(dword_5d4594_825760 + 56) = *getMemU32Ptr(0x5D4594, 2650656);
		*(_DWORD*)(dword_5d4594_825760 + 16) = (nox_win_width - *(_DWORD*)(dword_5d4594_825760 + 8)) / 2;
		*(_DWORD*)(dword_5d4594_825760 + 24) =
			*(_DWORD*)(dword_5d4594_825760 + 8) + *(_DWORD*)(dword_5d4594_825760 + 16);
		sub_445C40();
		dword_5d4594_825752 = 0;
		dword_5d4594_825768 = 0;
		v1 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108044), 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 309);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 825772), L"%s", v1);
		result = 1;
	}
	return result;
}

//----- (00445840) --------------------------------------------------------
int __cdecl nox_xxx_menuGameOnButton_445840(_DWORD* a1, int a2, int* a3, int a4) {
	int v3;       // esi
	int v4;       // eax
	int result;   // eax
	int v6;       // eax
	int v7;       // eax
	char* v8;     // eax
	int v9;       // eax
	int v10;      // eax
	int v12;      // eax
	wchar_t* v13; // eax
	int v14;      // eax
	wchar_t* v15; // eax
	int v16;      // eax
	int v17;      // eax
	int v18;      // ecx
	_DWORD* v19;  // eax
	int v20;      // eax
	int v21;      // eax
	wchar_t* v22; // [esp-18h] [ebp-18h]
	wchar_t* v23; // [esp-18h] [ebp-18h]

	if (a2 != 16391)
		return 0;
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
			v23 =
				nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108224), 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 199);
			v15 =
				nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108288), 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 198);
			nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v15, (int)v23, 56, sub_445B40, sub_445BA0);
			v16 = a3[9];
			LOBYTE(v16) = v16 & 0xFD;
			a3[9] = v16;
			result = 0;
		}
		break;
	case 9002:
		v18 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 120);
		if ((v18 & 0x8000) == 0) {
			sub_445C40();
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				sub_4DB130("AUTOSAVE");
				sub_4DB170(1, 0, 0);
			}
			goto LABEL_27;
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
		if (nox_common_gameFlags_check_40A5C0(2048))
			nox_savegame_sub_46D580();
		else
			nox_xxx_netSavePlayer_41CE00();
		if (sub_43C6E0())
			goto LABEL_27;
		sub_43CF70();
		v12 = a3[9];
		LOBYTE(v12) = v12 & 0xFD;
		a3[9] = v12;
		result = 0;
		break;
	case 9004:
		nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_825760);
		v22 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108096), 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 185);
		v13 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108160), 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 184);
		nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_825760, (int)v13, (int)v22, 56, nox_xxx_quitDialogYes_445B20, nox_xxx_quitDialogNo_445B30);
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
		goto LABEL_11;
	case 9007:
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v8 = nox_common_playerInfoGetByID_417040(*getMemIntPtr(0x5D4594, 2616328));
			nox_xxx_serverHandleClientConsole_443E90((int)v8, 0, 0);
		LABEL_11:
			sub_445C40();
			v9 = a3[9];
			LOBYTE(v9) = v9 & 0xFD;
			a3[9] = v9;
			result = 0;
		} else {
			nox_xxx_netServerCmd_440950(0, 0);
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
		if (nox_common_gameFlags_check_40A5C0(4096))
			sub_48CB10(4);
		else
			sub_48CB10(0);
		v6 = a3[9];
		LOBYTE(v6) = v6 & 0xFD;
		a3[9] = v6;
		result = 0;
		break;
	default:
	LABEL_27:
		v21 = a3[9];
		LOBYTE(v21) = v21 & 0xFD;
		a3[9] = v21;
		result = 0;
		break;
	}
	return result;
}
//----- (00445B40) --------------------------------------------------------
void* sub_445B40() {
	void* result; // eax
	wchar_t* v1;  // eax
	wchar_t* v2;  // [esp-10h] [ebp-10h]

	sub_413A00(0);
	result = sub_4DB790("AUTOSAVE");
	if (!result) {
		v2 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108368), 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 88);
		v1 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108432), 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 87);
		result = nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v1, (int)v2, 33, 0, 0);
	}
	return result;
}

//----- (00445C40) --------------------------------------------------------
void sub_445C40() {
	int result;   // eax
	_DWORD* v1;   // eax
	_DWORD* v2;   // eax
	_DWORD* v3;   // eax
	_DWORD* v4;   // eax
	_DWORD* v5;   // eax
	_DWORD* v6;   // esi
	_DWORD* v7;   // eax
	_DWORD* v8;   // eax
	_DWORD* v9;   // eax
	_DWORD* v10;  // eax
	_DWORD* v11;  // esi
	_DWORD* v12;  // eax
	_DWORD* v13;  // esi
	_DWORD* v14;  // eax
	_DWORD* v15;  // eax
	_DWORD* v16;  // eax
	_DWORD* v17;  // eax
	_DWORD* v18;  // eax
	_DWORD* v19;  // eax
	wchar_t* v20; // [esp-4h] [ebp-8h]
	wchar_t* v21; // [esp-4h] [ebp-8h]

	if (nox_xxx_wndGetFlags_46ADA0(*(int*)&dword_5d4594_825760) & 0x10) {
		if (!*getMemU32Ptr(0x5D4594, 2614252) || !nox_common_gameFlags_check_40A5C0(2048) ||
			(result = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 276), result != 2) && result != 1 && result != 51) {
			if (sub_45D9B0() != 1) {
				if (nox_xxx_checkGFlagNoParticles_413A50() != 1) {
					nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
					nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_825760);
					*(_DWORD*)(dword_5d4594_825760 + 4) |= 8u;
					nox_xxx_wndSetCaptureMain_46ADC0(*(int*)&dword_5d4594_825760);
					if (nox_common_gameFlags_check_40A5C0(2048)) {
						v20 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108496), 0,
													"C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 396);
						v1 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9003);
						sub_46AEE0((int)v1, (int)v20);
						v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9001);
						nox_window_set_hidden((int)v2, 0);
						v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9002);
						nox_window_set_hidden((int)v3, 0);
						v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9007);
						nox_window_set_hidden((int)v4, 1);
						v5 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9008);
						nox_window_set_hidden((int)v5, 1);
						v6 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9009);
						nox_window_set_hidden((int)v6, 1);
						v7 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9004);
						nox_wnd_nox_xxx_wndDraw_46A9B0(v7, v6[4], v6[5]);
						sub_413A00(1);
						sub_46AB20(*(_DWORD**)&dword_5d4594_825760, 220, 285);
					} else {
						v21 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108548), 0,
													"C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 427);
						v8 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9003);
						sub_46AEE0((int)v8, (int)v21);
						v9 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9001);
						nox_window_set_hidden((int)v9, 1);
						v10 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9002);
						nox_window_set_hidden((int)v10, 1);
						v11 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9007);
						nox_window_set_hidden((int)v11, 0);
						nox_xxx_wnd_46ABB0((int)v11, 1);
						v12 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9008);
						nox_window_set_hidden((int)v12, 0);
						v13 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9009);
						nox_window_set_hidden((int)v13, 0);
						sub_46AEE0((int)v13, (int)getMemAt(0x5D4594, 825772));
						if (nox_common_gameFlags_check_40A5C0(49152) || !nox_xxx_getTeamCounter_417DD0())
							nox_xxx_wnd_46ABB0((int)v13, 0);
						else
							nox_xxx_wnd_46ABB0((int)v13, 1);
						v14 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9004);
						nox_wnd_nox_xxx_wndDraw_46A9B0(v14, v13[4], v13[5] + 45);
						sub_46AB20(*(_DWORD**)&dword_5d4594_825760, 220, 330);
						if (nox_common_gameFlags_check_40A5C0(4096)) {
							v15 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9007);
							nox_xxx_wnd_46ABB0((int)v15, 0);
							v16 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9003);
							nox_xxx_wnd_46ABB0((int)v16, 0);
						}
						if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
							v17 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9007);
							nox_xxx_wnd_46ABB0((int)v17, 0);
							v18 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9005);
							nox_xxx_wnd_46ABB0((int)v18, 0);
							v19 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_825760, 9003);
							nox_xxx_wnd_46ABB0((int)v19, 0);
						}
					}
				}
			}
		}
	} else {
		nox_xxx_windowDestroyChildsMB_46B500(0);
		nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_825760);
		nox_window_set_hidden(*(int*)&dword_5d4594_825760, 1);
		*(_DWORD*)(dword_5d4594_825760 + 4) &= 0xFFFFFFF7;
		sub_413A00(0);
	}
}

//----- (00446190) --------------------------------------------------------
void sub_446190() {
	wchar_t* v1; // eax
	wchar_t* v2; // eax
	wchar_t* v3; // [esp-12h] [ebp-14h]
	char v4;     // [esp+1h] [ebp-1h]

	dword_5d4594_825764 = 0;
	if (nox_common_gameFlags_check_40A5C0(1)) {
		v1 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108608), 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 667);
		nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 108632), v1);
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
		sub_43C260();
		sub_41E300(9);
		nox_xxx____setargv_4_44B000();
	} else if (sub_4D6F50()) {
		if (sub_4D6F30())
			sub_43C2F0();
		sub_4D70B0();
		sub_4D6F40(0);
		sub_4D6F90(0);
	}
	if (!dword_5d4594_825768) {
		dword_5d4594_825752 = 0;
		dword_5d4594_825768 = *getMemU32Ptr(0x5D4594, 2598000);
		if (nox_common_gameFlags_check_40A5C0(1)) {
			if (sub_43AF70() == 1 && nox_common_gameFlags_check_40A5C0(49152))
				sub_416150(15, 0);
			sub_509CB0();
		}
		if (nox_common_gameFlags_check_40A5C0(1)) {
			dword_5d4594_825752 = nox_common_playerInfoCount_416F40() - 1;
			sub_467440(0);
			if (dword_5d4594_825752 > 0) {
				v4 = -57;
				nox_xxx_netSendPacket0_4E5420(159, &v4, 1, 0, 1);
				v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108672), 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c",
										   737);
				v2 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 108724), 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c",
										   736);
				nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v2, (int)v3, 0, 0, 0);
				sub_44A360(1);
				goto LABEL_20;
			}
		} else if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
			goto LABEL_20;
		}
		sub_446380();
	}
LABEL_20:
	if (dword_5d4594_2650652) {
		if (sub_41E2F0() == 9) {
			sub_41F4B0();
			sub_41EC30();
			sub_446490(0);
			nox_xxx____setargv_4_44B000();
		}
	}
}
