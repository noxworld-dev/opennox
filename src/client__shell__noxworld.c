#include "client__shell__noxworld.h"

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
#include "GAME5_2.h"
#include "MixPatch.h"
#include "client__gui__window.h"
#include "common__magic__speltree.h"
#include "common__object__armrlook.h"
#include "common__object__weaplook.h"
#include "common__random.h"
#include "common__strman.h"
#include "defs.h"
#include "input_common.h"
#include "operators.h"

#include "client__gui__gamewin__gamewin.h"
#include "client__shell__mainmenu.h"
#include "client__shell__selchar.h"

extern uint32_t dword_5d4594_815096;
extern uint32_t dword_5d4594_815060;
extern uint32_t dword_5d4594_815052;
extern uint32_t dword_5d4594_815100;
extern uint32_t dword_5d4594_814548;
extern uint32_t dword_5d4594_814992;
extern uint32_t nox_client_connError_814552;
extern uint32_t dword_5d4594_815056;
extern uint32_t dword_5d4594_814996;
extern uint32_t dword_5d4594_814988;
extern uint32_t dword_587000_87408;
extern uint64_t qword_5d4594_814956;
extern uint64_t qword_5d4594_815068;
extern uint32_t dword_5d4594_815044;
extern uint32_t nox_wol_server_result_cnt_815088;
extern uint32_t dword_5d4594_814624;
extern uint32_t dword_5d4594_815032;
extern uint32_t dword_5d4594_815020;
extern uint32_t dword_5d4594_815024;
extern uint32_t dword_5d4594_815028;
extern uint32_t dword_5d4594_814984;
extern uint32_t dword_5d4594_815016;
extern uint32_t nox_game_createOrJoin_815048;
extern uint32_t dword_587000_87404;
extern uint32_t dword_587000_87412;
extern uint32_t dword_5d4594_815000;
extern uint32_t nox_wol_wnd_gameList_815012;
extern nox_window* dword_5d4594_815004;
extern nox_window* nox_wol_wnd_world_814980;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_video_modes_cnt;
extern nox_video_mode nox_video_modes[7];

int dword_5d4594_815104 = 0;
nox_gui_animation* nox_wnd_xxx_815040 = 0;

//----- (004373A0) --------------------------------------------------------
void sub_4373A0() {
	wchar_t* v0; // eax
	wchar_t* v1; // eax
	wchar_t* v2; // eax

	if (!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_815000)) {
		nox_window_set_hidden(*(int*)&dword_5d4594_815000, 1);
		dword_5d4594_815056 = 0;
		nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_815000);
		nox_xxx_windowFocus_46B500(*(int*)&nox_wol_wnd_world_814980);
	}
	if (*(int*)&dword_587000_87408 == 1 || *(int*)&dword_587000_87412 == -1) {
		if (nox_game_createOrJoin_815048 == 1) {
			nox_game_createOrJoin_815048 = 0;
			nox_xxx_setMouseBounds_430A70(0, nox_win_width - 1, 0, nox_win_height - 1);
			v2 = nox_strman_loadString_40F1D0("ChooseArea", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 619);
			nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v2, 0);
			nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
		} else {
			nox_game_checkStateSwitch_43C1E0();
			sub_49FF20();
			if (dword_587000_87404 == 1) {
				*getMemU32Ptr(0x5D4594, 815084) = 1;
				sub_41E300(7);
				sub_4207F0(4);
				sub_40D380();
			}
			nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
		}
	} else if (nox_game_createOrJoin_815048 == 1) {
		nox_game_createOrJoin_815048 = 0;
		nox_xxx_setMouseBounds_430A70(0, nox_win_width - 1, 0, nox_win_height - 1);
		nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_814984);
		sub_4375C0(1);
		v0 = nox_strman_loadString_40F1D0("JoinServer", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 643);
		nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v0, 0);
		nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
	} else {
		sub_49FF20();
		if (dword_587000_87404) {
			dword_587000_87412 = -1;
			nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_814984);
			nox_window_set_hidden(*(int*)&dword_5d4594_814984, 1);
			nox_window_set_hidden(*(int*)&dword_5d4594_814988, 0);
			v1 = nox_strman_loadString_40F1D0("ChooseArea", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 660);
			nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v1, 0);
			nox_client_refreshServerList_4378B0();
			nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
		} else {
			nox_game_checkStateSwitch_43C1E0();
		}
	}
}

//----- (004378B0) --------------------------------------------------------
#ifndef NOX_CGO
void nox_client_refreshServerList_4378B0() {
	if (sub_44A4A0()) {
		dword_5d4594_815104 = 1;
		return;
	}

	*getMemU64Ptr(0x5D4594, 815076) = nox_platform_get_ticks();
	dword_5d4594_815060 = 0;
	sub_4379C0();
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16399, 0, 0);
	sub_49FFA0(1);
	nox_wol_server_result_cnt_815088 = 0;
	if (dword_587000_87404) {
		sub_41F370(1);
		int v3 = sub_41E2F0();
		sub_41DA70(v3, 12);
	} else {
		nox_client_setOnLobbyServer_555000(nox_client_OnLobbyServer_4375F0);
		unsigned int ticks = nox_platform_get_ticks();
		*getMemU32Ptr(0x5D4594, 814964) = ticks;
		uint16_t port = nox_xxx_servGetPort_40A430();
		nox_xxx_lobbyMakePacket_554AA0(port, 0, 0, ticks);
		wchar_t* str = nox_strman_loadString_40F1D0("Wolchat.c:PleaseWait", 0,
													"C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1097);
		nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&nox_wol_wnd_world_814980, 0, str, 0, 0, 0);
	}
	dword_5d4594_815104 = 0;
	*(uint64_t*)&qword_5d4594_815068 = *getMemU64Ptr(0x5D4594, 815076) + (long long)120000;
}
#endif // NOX_CGO

//----- (004379F0) --------------------------------------------------------
int nox_game_showGameSel_4379F0() {
	uint32_t* v2;  // esi
	uint32_t* v3;  // eax
	uint32_t* v4;  // eax
	wchar_t* v5;   // eax
	uint32_t* v6;  // eax
	wchar_t* v7;   // eax
	uint32_t* v8;  // esi
	uint32_t* v9;  // ebx
	uint32_t* v10; // ebp
	uint32_t* v11; // edi
	uint32_t* v12; // esi
	uint32_t* v13; // ebx
	uint32_t* v14; // ebp
	uint32_t* v15; // edi
	int v16;       // eax
	wchar_t* v17;  // eax
	wchar_t* v18;  // eax
	uint32_t* v19; // eax
	uint32_t* v20; // eax
	uint32_t* v21; // eax
	uint32_t* v22; // eax
	uint32_t* v23; // eax
	uint32_t* v24; // eax
	uint32_t* v25; // eax
	uint32_t* v26; // eax
	wchar_t* v27;  // [esp-14h] [ebp-1Ch]
	wchar_t* v28;  // [esp-14h] [ebp-1Ch]

	nox_xxx_setQuest_4D6F60(0);
	sub_4D6F80(0);
	if (!nox_common_gameFlags_check_40A5C0(0x2000000) && !sub_4D6F30()) {
		nox_game_createOrJoin_815048 = 0;
		dword_587000_87412 = -1;
	}
	*getMemU32Ptr(0x5D4594, 815076) = 0;
	*getMemU32Ptr(0x5D4594, 815080) = 0;
	*getMemU32Ptr(0x5D4594, 815084) = 0;
	nox_game_addStateCode_43BDD0(10000);
	sub_4A24C0(1);
	if (*(int*)&dword_587000_87404 != 1 || (sub_4A1BE0(0), *(int*)&dword_587000_87412 != -1)) {
		sub_49FDB0(0);
	}
	if (nox_wol_wnd_world_814980) {
		dword_5d4594_815044 = 0;
		nox_wnd_xxx_815040->state = NOX_GUI_ANIM_IN;
		nox_wnd_xxx_815040->fnc_done_out = sub_438330;
		sub_43BE40(3);
		nox_xxx_clientPlaySoundSpecial_452D80(922, 100);
		nox_window_set_hidden(*(int*)&nox_wol_wnd_world_814980, 0);
		nox_window_set_hidden(*(int*)&dword_5d4594_815000, 0);
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_814984, 1);
		if (nox_game_createOrJoin_815048) {
			sub_4375C0(0);
		}
		sub_46ACE0(*(uint32_t**)&nox_wol_wnd_world_814980, 10047, 10051, dword_587000_87408 == 0);
		if (sub_4D6FA0() == 2) {
			v25 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10010);
			nox_window_call_field_94(*(int*)&nox_wol_wnd_world_814980, 16391, (int)v25, 0);
			v26 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10010);
			nox_window_call_field_94(*(int*)&nox_wol_wnd_world_814980, 16391, (int)v26, 0);
		}
		return 1;
	}
	nox_wol_wnd_world_814980 = nox_new_window_from_file("noxworld.wnd", nox_xxx_windowMultiplayerSub_439E70);
	if (!nox_wol_wnd_world_814980) {
		return 0;
	}
	sub_49FF20();
	nox_xxx_wndShowModalMB_46A8C0(*(int*)&nox_wol_wnd_world_814980);
	nox_window_set_all_funcs(*(uint32_t**)&nox_wol_wnd_world_814980, sub_439D00, 0, 0);
	nox_wnd_xxx_815040 =
		nox_gui_makeAnimation_43C5B0(*(uint32_t**)&nox_wol_wnd_world_814980, 0, 0, 0, -480, 0, 20, 0, -40);
	if (!nox_wnd_xxx_815040) {
		return 0;
	}
	nox_wnd_xxx_815040->field_0 = 10000;
	nox_wnd_xxx_815040->field_12 = sub_438370;
	nox_wnd_xxx_815040->fnc_done_out = sub_438330;
	dword_5d4594_814984 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10020);
	dword_5d4594_814988 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10021);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_814984, sub_439D00);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_814988, sub_439D00);
	nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_814988, nox_xxx_windowMultiplayerSub_439E70);
	dword_5d4594_814996 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10011);
	nox_wol_wnd_gameList_815012 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10037);
	dword_5d4594_815004 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10034);
	dword_5d4594_815000 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10033);
	dword_5d4594_814992 = sub_489B80(*(int*)&nox_wol_wnd_world_814980);
	*getMemU32Ptr(0x5D4594, 815008) = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10001);
	dword_5d4594_815016 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10038);
	dword_5d4594_815020 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10039);
	dword_5d4594_815024 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10040);
	dword_5d4594_815028 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10041);
	dword_5d4594_815032 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10042);
	v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10002);
	if (nox_common_gameFlags_check_40A5C0(0x1000000)) {
		nox_xxx_wnd_46ABB0((int)v2, 0);
	}
	v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10003);
	v3[9] &= 0xFFFFFFFB;
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10046);
	nox_xxx_wndSetDrawFn_46B340((int)v4, sub_438C80);
	nox_xxx_wndSetProc_46B2C0(*(int*)&nox_wol_wnd_gameList_815012, nox_xxx_windowMultiplayerSub_439E70);
	nox_window_set_hidden(*(int*)&nox_wol_wnd_gameList_815012, 1);
	nox_window_set_hidden(*(int*)&dword_5d4594_815000, 1);
	nox_xxx_wnd_46B280(*getMemIntPtr(0x5D4594, 815008), *(int*)&nox_wol_wnd_world_814980);
	if (dword_587000_87404) {
		nox_game_SetCliDrawFunc(sub_41E210);
		v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10007);
		nox_window_set_hidden((int)v6, 0);
		dword_587000_87412 = -1;
		nox_window_set_hidden(*(int*)&dword_5d4594_814984, 1);
		v7 = nox_strman_loadString_40F1D0("ChooseArea", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2530);
		nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v7, 0);
	} else {
		dword_587000_87412 = 0;
		nox_window_set_hidden(*(int*)&dword_5d4594_814988, 1);
		v5 = nox_strman_loadString_40F1D0("JoinServer", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2517);
		nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v5, 0);
		sub_46ACE0(*(uint32_t**)&dword_5d4594_814984, 10620, 10631, 1);
		sub_49FDB0(0);
	}
	*getMemU32Ptr(0x5D4594, 814556) = nox_xxx_gLoadImg_42F970("NWGameIconLargeGreen");
	*getMemU32Ptr(0x5D4594, 814560) = nox_xxx_gLoadImg_42F970("NWGameIconLargeGreenLit");
	*getMemU32Ptr(0x5D4594, 814564) = nox_xxx_gLoadImg_42F970("NWGameIconSmallGreen");
	*getMemU32Ptr(0x5D4594, 814568) = nox_xxx_gLoadImg_42F970("NWGameIconSmallGreenLit");
	*getMemU32Ptr(0x5D4594, 814572) = nox_xxx_gLoadImg_42F970("NWGameIconLargeYellow");
	*getMemU32Ptr(0x5D4594, 814576) = nox_xxx_gLoadImg_42F970("NWGameIconLargeYellowLit");
	*getMemU32Ptr(0x5D4594, 814580) = nox_xxx_gLoadImg_42F970("NWGameIconSmallYellow");
	*getMemU32Ptr(0x5D4594, 814584) = nox_xxx_gLoadImg_42F970("NWGameIconSmallYellowLit");
	*getMemU32Ptr(0x5D4594, 814588) = nox_xxx_gLoadImg_42F970("NWGameIconLargeRed");
	*getMemU32Ptr(0x5D4594, 814592) = nox_xxx_gLoadImg_42F970("NWGameIconLargeRedLit");
	*getMemU32Ptr(0x5D4594, 814596) = nox_xxx_gLoadImg_42F970("NWGameIconSmallRed");
	*getMemU32Ptr(0x5D4594, 814600) = nox_xxx_gLoadImg_42F970("NWGameIconSmallRedLit");
	*getMemU32Ptr(0x5D4594, 814900) = nox_xxx_gLoadImg_42F970("NWMapULLg");
	*getMemU32Ptr(0x5D4594, 814904) = nox_xxx_gLoadImg_42F970("NWMapURLg");
	*getMemU32Ptr(0x5D4594, 814908) = nox_xxx_gLoadImg_42F970("NWMapLLLg");
	*getMemU32Ptr(0x5D4594, 814912) = nox_xxx_gLoadImg_42F970("NWMapLRLg");
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_gameList_815012, 10053);
	v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_gameList_815012, 10043);
	v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_gameList_815012, 10044);
	v11 = *(uint32_t**)(nox_wol_wnd_gameList_815012 + 32);
	nox_xxx_wnd_46B280((int)v8, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wnd_46B280((int)v9, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wnd_46B280((int)v10, *(int*)&nox_wol_wnd_gameList_815012);
	v11[9] = v8;
	v11[7] = v9;
	v11[8] = v10;
	*(uint32_t*)(v8[100] + 8) = 16;
	*(uint32_t*)(v8[100] + 12) = 12;
	nox_xxx_wndSetOffsetMB_46AE40(v8[100], 0, -15);
	v12 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_815000, 10032);
	v13 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_815000, 10035);
	v14 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_815000, 10036);
	v15 = *(uint32_t**)((uint32_t)dword_5d4594_815004 + 32);
	nox_xxx_wnd_46B280((int)v12, *(int*)&dword_5d4594_815004);
	nox_xxx_wnd_46B280((int)v13, *(int*)&dword_5d4594_815004);
	nox_xxx_wnd_46B280((int)v14, *(int*)&dword_5d4594_815004);
	v15[9] = v12;
	v15[7] = v13;
	v15[8] = v14;
	*(uint32_t*)(v12[100] + 8) = 16;
	*(uint32_t*)(v12[100] + 12) = 10;
	sub_438480();
	v16 = nox_xxx_servGetPort_40A430();
	sub_40A3C0(v16);
	nox_game_createOrJoin_815048 = 0;
	dword_5d4594_815044 = 0;
	dword_5d4594_815052 = 0;
	dword_5d4594_814548 = 0;
	*(uint64_t*)&qword_5d4594_815068 = nox_platform_get_ticks() + 1000;
	if (dword_587000_87408 == 1) {
		sub_4383A0();
	}
	if (!dword_587000_87404) {
		nox_xxx_createSocketLocal_554B40(0);
	}
	nox_wol_server_result_cnt_815088 = 0;
	nox_xxx_loadModifyers_4158C0();
	nox_xxx_loadLook_415D50();
	sub_430C30_set_video_max(NOX_MAX_WIDTH, NOX_MAX_HEIGHT);
	nox_client_setCursorType_477610(0);
	if (dword_5d4594_815096) {
		v27 = nox_strman_loadString_40F1D0("Kicked", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2616);
		v17 = nox_strman_loadString_40F1D0("Notification", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2616);
		nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v17, (int)v27, 33, 0, 0);
		sub_44A360(1);
		dword_5d4594_815096 = 0;
	} else if (dword_5d4594_815100) {
		v28 = nox_strman_loadString_40F1D0("Timeout", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2623);
		v18 = nox_strman_loadString_40F1D0("Notification", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2623);
		nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v18, (int)v28, 33, 0, 0);
		sub_44A360(1);
		dword_5d4594_815100 = 0;
	}
	sub_43DE40(sub_438770);
	if (sub_44A4A0()) {
		sub_44A4B0();
	}
	nox_xxx_wndSetDrawFn_46B340(*(int*)&dword_5d4594_814984, sub_438E30);
	v19 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10054);
	nox_xxx_wndSetDrawFn_46B340((int)v19, sub_438E30);
	v20 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10055);
	nox_xxx_wndSetDrawFn_46B340((int)v20, sub_438E30);
	v21 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10056);
	nox_xxx_wndSetDrawFn_46B340((int)v21, sub_438E30);
	v22 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10057);
	nox_xxx_wndSetDrawFn_46B340((int)v22, sub_438E30);
	if (!dword_587000_87408) {
		sub_46ACE0(*(uint32_t**)&nox_wol_wnd_world_814980, 10047, 10051, 1);
	}
	if (sub_4D6FA0() == 1) {
		v23 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10002);
		nox_window_call_field_94(*(int*)&nox_wol_wnd_world_814980, 16391, (int)v23, 0);
		nox_xxx_setQuest_4D6F60(1);
		v24 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10020);
		nox_window_call_field_93((int)v24, 5, 15663512, 0);
	}
	return 1;
}

//----- (004383A0) --------------------------------------------------------
int sub_4383A0() {
	wchar_t* v0; // eax
	int result;  // eax

	if (!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_814992)) {
		nox_window_set_hidden(*(int*)&dword_5d4594_814992, 1);
		sub_489870();
	}
	nox_window_set_hidden(*(int*)&nox_wol_wnd_gameList_815012, 0);
	nox_window_set_hidden(*(int*)&dword_5d4594_814984, 1);
	nox_window_set_hidden(*(int*)&dword_5d4594_814988, 1);
	sub_46AD20(*(uint32_t**)&nox_wol_wnd_world_814980, 10006, 10007, 1);
	sub_46ACE0(*(uint32_t**)&nox_wol_wnd_world_814980, 10047, 10051, 0);
	v0 = nox_strman_loadString_40F1D0("ListJoinServer", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 418);
	nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v0, 0);
	result = dword_587000_87404;
	dword_587000_87408 = 1;
	if (dword_587000_87404 == 1) {
		dword_587000_87412 = -1;
	}
	return result;
}

//----- (00438770) --------------------------------------------------------
int sub_438770() {
	int result;   // eax
	long long v1; // rax
	wchar_t* v2;  // eax
	wchar_t* v3;  // eax
	wchar_t* v4;  // eax
	wchar_t* v5;  // eax
	uint16_t* v6; // esi
	uint32_t* v7; // eax

	if (dword_5d4594_814548) {
		switch (dword_5d4594_814548) {
		case 2:
			sub_438BD0();
			sub_43AF90(1);
			result = 1;
			break;
		case 3:
			if ((unsigned long long)nox_platform_get_ticks() < *(uint64_t*)&qword_5d4594_814956) {
				goto LABEL_29;
			}
			nox_client_setConnError_43AFA0(8);
			result = 1;
			break;
		case 4:
			sub_43AF90(3);
			v2 = nox_strman_loadString_40F1D0("TestCon", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1343);
			sub_449E30((int)v2);
			*(uint64_t*)&qword_5d4594_814956 = nox_platform_get_ticks() + 20000;
			result = 1;
			break;
		case 5:
			v3 = nox_strman_loadString_40F1D0("Password", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1349);
			sub_449E00((int)v3);
			v4 = nox_strman_loadString_40F1D0("PasswordRequired", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
											  1350);
			sub_449E30((int)v4);
			sub_449EA0(7);
			sub_44A360(0);
			sub_43AF90(6);
			sub_4A24C0(1);
			result = 1;
			break;
		case 7:
			sub_44A360(1);
			v5 = nox_strman_loadString_40F1D0("Connected", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1364);
			sub_449E30((int)v5);
			sub_449EA0(0);
			nox_game_SetCliDrawFunc(nox_xxx_cliDrawConnectedLoop_43B360);
			sub_43AF90(1);
			result = 1;
			break;
		case 8:
			v1 = nox_platform_get_ticks();
			dword_5d4594_814548 = 9;
			*getMemU64Ptr(0x5D4594, 814972) = v1 + 1000;
			result = 1;
			break;
		case 9:
			if ((unsigned long long)nox_platform_get_ticks() <= *getMemU64Ptr(0x5D4594, 814972)) {
				goto LABEL_29;
			}
			nox_client_joinGame_438A90();
			result = 1;
			break;
		case 0xA:
			v6 = (uint16_t*)sub_449E60(4);
			v7 = nox_xxx_wndGetChildByID_46B0C0(0, 4001);
			if (v6 && *v6) {
				nox_xxx_wnd_46ABB0((int)v7, 1);
				result = 1;
			} else {
				nox_xxx_wnd_46ABB0((int)v7, 0);
				result = 1;
			}
			break;
		default:
			goto LABEL_29;
		}
	} else {
		if ((!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_814984) ||
			 !wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_814988) ||
			 !wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&nox_wol_wnd_gameList_815012)) &&
			!nox_game_createOrJoin_815048 && !dword_5d4594_815044 && !dword_5d4594_815052 &&
			wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_815000)) {
			if ((unsigned long long)nox_platform_get_ticks() > *(uint64_t*)&qword_5d4594_815068) {
				nox_client_refreshServerList_4378B0();
				return 1;
			}
			if ((unsigned long long)(nox_platform_get_ticks() - *getMemU64Ptr(0x5D4594, 815076)) > 0x3E8 &&
				!dword_5d4594_815060 && !dword_587000_87404) {
				sub_44A400();
				sub_4379C0();
				sub_4A0360();
				dword_5d4594_815060 = 1;
			}
		}
	LABEL_29:
		result = 1;
	}
	return result;
}

//----- (00438BD0) --------------------------------------------------------
int sub_438BD0() {
	int v0;      // eax
	wchar_t* v1; // eax
	wchar_t* v2; // eax

	if (!sub_44A4A0()) {
		nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&nox_wol_wnd_world_814980, 0, 0, 0, 0, 0);
	}
	v0 = nox_client_connError_814552;
	if (nox_client_connError_814552 != 8 && nox_client_connError_814552 != 9 && nox_client_connError_814552 != 10) {
		v1 = nox_strman_loadString_40F1D0("ConnError", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1262);
		sub_449E00((int)v1);
		v0 = nox_client_connError_814552;
	}
	v2 = nox_strman_loadString_40F1D0(*(char**)getMemAt(0x587000, 87416 + 4 * v0), 0,
									  "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1265);
	sub_449E30((int)v2);
	dword_5d4594_815044 = 0;
	sub_449EA0(1);
	sub_44A360(1);
	if (dword_587000_87404 == 1) {
		sub_40D380();
	}
	return sub_4A24C0(1);
}

//----- (00439370) --------------------------------------------------------
void sub_439370(int2* a1, int a2) {
	int v2;      // eax
	wchar_t* v3; // eax

	if (!(*(uint8_t*)(a2 + 164) & 0x10) || (LOBYTE(v2) = nox_client_checkQuestExp_SKU2_4D7700(), v2)) {
		sub_439450(a1->field_0, a1->field_4, a1);
		sub_46B120(*(uint32_t**)&dword_5d4594_815000, 0);
		nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_815000);
		sub_46C690(*(int*)&dword_5d4594_815000);
		nox_window_setPos_46A9B0(*(uint32_t**)&dword_5d4594_815000, a1->field_0, a1->field_4);
		sub_4394D0(a2);
		dword_5d4594_815056 = 1;
		*getMemU16Ptr(0x5D4594, 814604) = *(uint16_t*)(a2 + 109);
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
			nox_xxx_wnd_46ABB0(*getMemIntPtr(0x5D4594, 815008), 0);
		}
	} else {
		v3 = nox_strman_loadString_40F1D0("GeneralPrint:InformExpansion", 0,
										  "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 688);
		nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&nox_wol_wnd_world_814980, 0, (int)v3, 33, 0, 0);
		sub_44A360(0);
		sub_44A4B0();
	}
}
//----- (004394D0) --------------------------------------------------------
int sub_4394D0(int a1) {
	int v1;            // ebp
	wchar_t* v2;       // eax
	wchar_t* v3;       // eax
	wchar_t* v4;       // eax
	wchar_t* v5;       // eax
	wchar_t* v6;       // eax
	wchar_t* v7;       // eax
	wchar_t* v8;       // eax
	short v9;          // ax
	wchar_t* v10;      // eax
	wchar_t* v11;      // eax
	int result;        // eax
	wchar_t* v13;      // eax
	wchar_t* v14;      // eax
	int v15;           // ebx
	int v16;           // esi
	int v17;           // edi
	int v18;           // ebp
	int v19;           // eax
	wchar_t* v20;      // eax
	int v21;           // esi
	wchar_t* v22;      // eax
	int v23;           // ebx
	int v24;           // edi
	int v25;           // ebp
	int v26;           // eax
	wchar_t* v27;      // eax
	int v28;           // edi
	wchar_t* v29;      // eax
	int v30;           // esi
	int v31;           // ebx
	wchar_t* v32;      // eax
	wchar_t* v33;      // [esp-8h] [ebp-14Ch]
	unsigned char v34; // [esp+10h] [ebp-134h]
	unsigned char v35; // [esp+10h] [ebp-134h]
	int v36;           // [esp+14h] [ebp-130h]
	char v37[16];      // [esp+18h] [ebp-12Ch]
	wchar_t v38[100];  // [esp+7Ch] [ebp-C8h]

	v36 = a1 + 111;
	v1 = *(uint8_t*)(a1 + 102) & 0x7F;
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16399, 0, 0);
	v2 = nox_strman_loadString_40F1D0("Name", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 749);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v2, 14);
	if (*(uint8_t*)(a1 + 120)) {
		strncpy(v37, (const char*)(a1 + 120), 0xFu);
		v37[15] = 0;
	} else {
		nox_sprintAddrPort_43BC80(a1 + 12, *(uint16_t*)(a1 + 109), v37);
	}
	nox_swprintf(v38, L"%S", v37);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	if (dword_587000_87404 == 1) {
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89332), -1);
		v3 = nox_strman_loadString_40F1D0("GameHost", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 766);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v3, 14);
		sub_439CC0(*(uint32_t*)(a1 + 32), v37);
		nox_swprintf(v38, L"%S", v37);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89396), -1);
	v4 = nox_strman_loadString_40F1D0("Ping", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 774);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v4, 14);
	if (*(uint32_t*)(a1 + 96) == 9999) {
		nox_swprintf(v38, L"--");
	} else {
		nox_swprintf(v38, L"%d", *(uint32_t*)(a1 + 96));
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89464), -1);
	v5 = nox_strman_loadString_40F1D0("GameType", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 787);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v5, 14);
	v6 = nox_gui_wol_gameModeString_43BCB0(*(uint16_t*)(a1 + 163));
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v6, -1);
	if (*(uint8_t*)(a1 + 164) & 0x10) {
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89520), -1);
		v7 = nox_strman_loadString_40F1D0("Stage", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 794);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v7, 14);
		nox_swprintf(v38, L"%d", *(unsigned short*)(a1 + 165));
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89580), -1);
	v8 = nox_strman_loadString_40F1D0("Map", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 801);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v8, 14);
	strcpy(v37, (const char*)(a1 + 111));
	nox_swprintf(v38, L"%S", v37);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89636), -1);
	v9 = *(uint16_t*)(a1 + 163);
	if (v9 & 0xC000u) {
		if (v9 & 0x4000) {
			v33 = nox_strman_loadString_40F1D0("Individual", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 811);
		} else {
			v33 = nox_strman_loadString_40F1D0("Clan", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 815);
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v33, 6);
		v10 = nox_strman_loadString_40F1D0("Ladder", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 817);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v10, 6);
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89788), -1);
	v11 = nox_strman_loadString_40F1D0("Occupancy", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 822);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v11, 14);
	nox_swprintf(v38, L"%d/%d\n", *(unsigned char*)(a1 + 103), *(unsigned char*)(a1 + 104));
	result = nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	if (*(uint8_t*)(a1 + 164) & 0x20) {
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89860), -1);
		v13 = nox_strman_loadString_40F1D0("Resolution", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 831);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v13, 14);
		int rstr = get_video_mode_string(v1);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, rstr, -1);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89916), -1);
		v14 = nox_strman_loadString_40F1D0("DisabledSpells", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 836);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v14, 14);
		v15 = 0;
		v16 = 1;
		v34 = 0;
		v17 = 1;
		v18 = 136;
		do {
			if (v16 == 0x80000000) {
				v16 = 1;
				++v34;
			} else {
				v16 *= 2;
			}
			if (nox_xxx_spellIsValid_424B50(v17) && !(v16 & *(uint32_t*)(v36 + 4 * v34 + 24)) &&
				nox_xxx_spellFlags_424A70(v17) & 0x7000000) {
				v15 = 1;
				v19 = nox_xxx_spellTitle_424930(v17);
				nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, v19, 4);
			}
			++v17;
			--v18;
		} while (v18);
		if (!v15) {
			v20 = nox_strman_loadString_40F1D0("None", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 866);
			nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v20, 4);
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 90024), -1);
		v21 = 0;
		v22 = nox_strman_loadString_40F1D0("DisabledWeapons", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 872);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v22, 14);
		v23 = 1;
		v35 = 0;
		v24 = 1;
		v25 = 27;
		do {
			if (!((unsigned char)v23 & *(uint8_t*)(v35 + v36 + 44))) {
				v26 = sub_4159F0(v24);
				if (v26) {
					nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, v26, -1);
					v21 = 1;
				}
			}
			if (v23 == 128) {
				v23 = 1;
				++v35;
			} else {
				v23 *= 2;
			}
			v24 *= 2;
			--v25;
		} while (v25);
		if (!v21) {
			v27 = nox_strman_loadString_40F1D0("None", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 899);
			nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v27, 4);
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 90132), -1);
		v28 = 0;
		v29 = nox_strman_loadString_40F1D0("DisabledArmor", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 905);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v29, 14);
		v30 = 1;
		v31 = 26;
		do {
			if (!(v30 & *(uint32_t*)(a1 + 159))) {
				result = sub_415E80(v30);
				if (result) {
					v28 = 1;
					result = nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, result, -1);
				}
			}
			v30 *= 2;
			--v31;
		} while (v31);
		if (!v28) {
			v32 = nox_strman_loadString_40F1D0("None", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 920);
			result = nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v32, 4);
		}
	}
	return result;
}

//----- (00439E70) --------------------------------------------------------
int nox_xxx_windowMultiplayerSub_439E70(int a1, unsigned int a2, int* a3, int a4) {
	int v4;             // eax
	int v5;             // esi
	int* v6;            // eax
	int* v7;            // eax
	int v8;             // esi
	int v9;             // esi
	int v10;            // eax
	int result;         // eax
	const wchar_t* v12; // eax
	int v13;            // eax
	int v14;            // eax
	wchar_t* v15;       // eax
	int v16;            // eax
	uint32_t* v17;      // eax
	uint32_t* v18;      // eax
	int v19;            // esi
	int v20;            // esi
	wchar_t* v21;       // eax
	int v22;            // eax
	wchar_t* v23;       // eax
	char* v24;          // eax
	char* v25;          // eax
	char* v26;          // eax
	int v27;            // eax
	uint16_t v28;       // [esp-8h] [ebp-A0h]
	int v30;            // [esp+Ch] [ebp-8Ch]
	int v31;            // [esp+10h] [ebp-88h]
	char buf[4];        // [esp+14h] [ebp-84h]
	wchar_t v33[10];    // [esp+18h] [ebp-80h]
	char v34[36];       // [esp+2Ch] [ebp-6Ch]
	char v35[72];       // [esp+50h] [ebp-48h]

	if (a2 > 0x4010) {
		if (a2 == 16403 || a2 == 16412) {
			nox_window_call_field_94(*(int*)&dword_5d4594_815016, a2, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815020, a2, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815024, a2, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815028, a2, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815032, a2, (int)a3, 0);
		}
		return 0;
	}
	switch (a2) {
	case 0x4010u:
		if (nox_xxx_wndGetID_46B0A0(a3) == 10061) {
			nox_point mpos = nox_client_getMousePos_4309F0();
			dword_5d4594_814624 = sub_4A28C0(a4);
			sub_439370(&mpos, dword_5d4594_814624);
			return 0;
		}
		return 0;
	case 0x17u:
		return 1;
	case 0x4000u:
		v27 = nox_xxx_wndGetID_46B0A0(a3);
		if (v27 >= 10043 && v27 <= 10044) {
			nox_window_call_field_94(*(int*)&dword_5d4594_815016, 0x4000, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815020, 0x4000, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815024, 0x4000, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815028, 0x4000, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815032, 0x4000, (int)a3, 0);
			return 0;
		}
		return 0;
	}
	if (a2 != 16391) {
		return 0;
	}
	v4 = nox_xxx_wndGetID_46B0A0(a3);
	v5 = v4;
	if (v4 != 10043 && v4 != 10044 && v4 != 10035 && v4 != 10036) {
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	}
	if (v5 >= 10070) {
		nox_point mpos = nox_client_getMousePos_4309F0();
		v30 = mpos.x - 216;
		v31 = mpos.y - 27;
		v6 = (int*)sub_4A0020();
		if (sub_4A25C0(&v30, v6) >= 2) {
			v7 = (int*)sub_4A0020();
			*getMemU32Ptr(0x5D4594, 815036) = sub_4A2610(*(int*)&nox_wol_wnd_world_814980, &v30, v7);
		} else {
			dword_5d4594_814624 = sub_4A0490(v5 - 10070);
			sub_439370(&mpos, dword_5d4594_814624);
		}
		nox_xxx_cursorSetTooltip_4776B0((wchar_t*)getMemAt(0x5D4594, 815112));
	}
	if (v5 > 10006) {
		switch (v5) {
		case 10007:
			if (nox_game_createOrJoin_815048) {
				sub_4373A0();
			}
			if (dword_587000_87404) {
				sub_43A980();
			}
#ifndef NOX_CGO
			else {
				OnLibraryNotice_418();
			}
#endif // NOX_CGO
			return 0;
		case 10010:
			sub_4373A0();
			return 0;
		case 10047:
		case 10048:
		case 10049:
		case 10050:
		case 10051:
			sub_4379C0();
			nox_wol_servers_sortBtnHandler_4A0290(v5);
			sub_4A0390();
			return 0;
		case 10054:
			dword_587000_87412 = 0;
			sub_43A810();
			nox_client_refreshServerList_4378B0();
			if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
				v24 = sub_4A7EF0();
				sub_439D90(*(uint32_t*)v24 + 216, *((uint32_t*)v24 + 1) + 27);
			} else {
				sub_439D90(0x198u, 0xEFu);
			}
			result = 0;
			break;
		case 10055:
			dword_587000_87412 = 1;
			sub_43A810();
			nox_client_refreshServerList_4378B0();
			if (!nox_common_gameFlags_check_40A5C0(0x2000000)) {
				sub_439D90(0x198u, 0xEFu);
				result = 0;
			} else {
				v25 = sub_4A7EF0();
				sub_439D90(*(uint32_t*)v25 + 216, *((uint32_t*)v25 + 1) + 27);
				return 0;
			}
			break;
		case 10056:
			dword_587000_87412 = 2;
			sub_43A810();
			nox_client_refreshServerList_4378B0();
			if (!nox_common_gameFlags_check_40A5C0(0x2000000)) {
				sub_439D90(0x198u, 0xEFu);
			} else {
				v24 = sub_4A7EF0();
				sub_439D90(*(uint32_t*)v24 + 216, *((uint32_t*)v24 + 1) + 27);
			}
			result = 0;
			break;
		case 10057:
			dword_587000_87412 = 3;
			sub_43A810();
			nox_client_refreshServerList_4378B0();
			if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
				v26 = sub_4A7EF0();
				sub_439D90(*(uint32_t*)v26 + 216, *((uint32_t*)v26 + 1) + 27);
			} else {
				sub_439D90(0x198u, 0xEFu);
			}
			result = 0;
			break;
		default:
			return 0;
		}
		return result;
	}
	if (v5 == 10006) {
		nox_game_createOrJoin_815048 = 0;
		nox_client_refreshServerList_4378B0();
		return 0;
	}
	if (v5 > 10002) {
		v19 = v5 - 10003;
		if (v5 != 10003) {
			v20 = v19 - 1;
			if (!v20) {
				nox_game_createOrJoin_815048 = 0;
				sub_4383A0();
				nox_client_refreshServerList_4378B0();
				return 0;
			}
			if (v20 == 1) {
				nox_game_createOrJoin_815048 = 0;
				nox_window_set_hidden(*(int*)&nox_wol_wnd_gameList_815012, 1);
				nox_window_set_hidden(*(int*)&dword_5d4594_814984, 1);
				nox_window_set_hidden(*(int*)&dword_5d4594_814988, 1);
				nox_window_set_hidden(*(int*)&dword_5d4594_814992, 0);
				sub_46AD20(*(uint32_t**)&nox_wol_wnd_world_814980, 10006, 10007, 0);
				sub_46ACE0(*(uint32_t**)&nox_wol_wnd_world_814980, 10047, 10051, 1);
				v21 = nox_strman_loadString_40F1D0("FilterMsg", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2186);
				nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v21, 0);
				return 0;
			}
			return 0;
		}
		// host quest game
		LOBYTE(v22) = nox_client_checkQuestExp_SKU2_4D7700();
		if (!v22) {
			v23 = nox_strman_loadString_40F1D0("GeneralPrint:InformExpansion", 0,
											   "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2013);
			nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&nox_wol_wnd_world_814980, 0, (int)v23, 33, 0, 0);
			sub_44A360(0);
			sub_44A4B0();
			return 0;
		}
		nox_game_createOrJoin_815048 = 1;
		nox_common_gameFlags_unset_40A540(0x10000);
		nox_client_setMousePos_430B10(408, 239);
		sub_4375C0(0);
		if (!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_814992)) {
			sub_489870();
		}
		nox_xxx_setQuest_4D6F60(1);
		nox_xxx_cliShowHideTubes_470AA0(1);
		if (dword_587000_87404 == 1) {
			if (*(int*)&dword_587000_87412 != -1) {
				return 0;
			}
			v16 = nox_common_randomInt_415FA0(10054, 10057);
			v17 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, v16);
			nox_window_call_field_94(*(int*)&nox_wol_wnd_world_814980, 16391, (int)v17, 0);
			return 0;
		}
		dword_587000_87412 = 0;
		v18 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10020);
		nox_window_call_field_93((int)v18, 5, 15663512, 0);
		return 0;
	}
	if (v5 == 10002) {
		// host regular game
		if (nox_common_gameFlags_check_40A5C0(0x1000000)) {
			return 0;
		}
		nox_game_createOrJoin_815048 = 1;
		nox_xxx_setGameFlags_40A4D0(0x10000);
		nox_xxx_cliShowHideTubes_470AA0(0);
		nox_client_setMousePos_430B10(408, 239);
		sub_4375C0(0);
		if (!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_814992)) {
			sub_489870();
		}
		if (nox_common_gameFlags_check_40A5C0(0x2000000) || sub_4D6F30()) {
			return 0;
		}
		if (dword_587000_87404 == 1) {
			if (*(int*)&dword_587000_87412 != -1) {
				return 0;
			}
			v16 = nox_common_randomInt_415FA0(10054, 10057);
			v17 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, v16);
			nox_window_call_field_94(*(int*)&nox_wol_wnd_world_814980, 16391, (int)v17, 0);
			return 0;
		}
		dword_587000_87412 = 0;
		v18 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10020);
		nox_window_call_field_93((int)v18, 5, 15663512, 0);
		return 0;
	}
	v8 = v5 - 4001;
	if (!v8) {
		if (sub_43AF80() == 6) {
			v12 = (const wchar_t*)sub_449E60(4);
			nox_wcsncpy(v33, v12, 9u);
			v33[8] = 0;
			v28 = nox_client_getServerPort_43B320();
			v13 = nox_client_getServerAddr_43B300();
			sub_5550D0(v13, v28, buf);
			sub_43AF90(3);
			*(uint64_t*)&qword_5d4594_814956 = nox_platform_get_ticks() + 20000;
			sub_449EA0(0);
			return 0;
		}
		if (sub_43AF80() == 10) {
			v14 = sub_449E60(4);
			nox_sprintf(v35, "%S", v14);
			v15 = nox_strman_loadString_40F1D0("Finding", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2209);
			sub_449E30((int)v15);
			sub_43AF90(11);
			sub_40D740((int)v34);
			sub_449EA0(0);
			return 0;
		}
		if (sub_43AF80() == 1) {
			if (dword_587000_87404 == 1) {
				sub_40D380();
			}
			sub_43A920();
			nox_game_showGameSel_4379F0();
			return 0;
		}
		if (dword_5d4594_815104) {
			*(uint64_t*)&qword_5d4594_815068 = nox_platform_get_ticks() + 1000;
			return 0;
		}
		return 0;
	}
	v9 = v8 - 1;
	if (!v9) {
		if (dword_587000_87404 == 1) {
			sub_40D380();
		}
		sub_43A920();
		nox_game_showGameSel_4379F0();
		return 0;
	}
	if (v9 != 5999 || dword_5d4594_815044) {
		return 0;
	}
	v10 = sub_43B340();
	if (v10 & 0x1000) {
		sub_4D6F80(1);
		nox_xxx_cliShowHideTubes_470AA0(1);
	}
	sub_43B460();
	if (sub_4D6F70()) {
		if (nox_client_countPlayerFiles04_4DC7D0()) {
			sub_4A7A70(1);
			nox_game_showSelChar_4A4DB0();
			dword_5d4594_815044 = 1;
			sub_4A2890();
			return 0;
		}
	} else if (nox_client_countPlayerFiles02_4DC630()) {
		sub_4A7A70(1);
		nox_game_showSelChar_4A4DB0();
		dword_5d4594_815044 = 1;
		sub_4A2890();
		return 0;
	}
	sub_4A7A70(0);
	nox_game_showSelClass_4A4840();
	dword_5d4594_815044 = 1;
	sub_4A2890();
	return 0;
}
//----- (0043A810) --------------------------------------------------------
void sub_43A810() {
	int v0;      // edi
	int* v1;     // esi
	wchar_t* v2; // [esp-8h] [ebp-Ch]

	nox_window_set_hidden(*(int*)&dword_5d4594_814984, 0);
	nox_window_set_hidden(*(int*)&dword_5d4594_814988, 1);
	nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_814984, *getMemU32Ptr(0x5D4594, 814900 + 4 * dword_587000_87412));
	if (nox_game_createOrJoin_815048 == 1) {
		v2 = nox_strman_loadString_40F1D0("CreateMsg", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 377);
	} else {
		v2 = nox_strman_loadString_40F1D0("JoinServer", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 382);
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v2, 0);
	if (dword_587000_87404 == 1) {
		sub_46ACE0(*(uint32_t**)&dword_5d4594_814984, 10600, 10611, 1);
		v0 = 0;
		v1 = getMemIntPtr(0x587000, 87560);
		do {
			sub_46ACE0(*(uint32_t**)&dword_5d4594_814984, *v1, v1[1], v0 != dword_587000_87412);
			v1 += 2;
			++v0;
		} while ((int)v1 < (int)getMemAt(0x587000, 87592));
	}
	sub_49FDB0(*(int*)&dword_587000_87412);
}

//----- (0043A980) --------------------------------------------------------
int sub_43A980() {
	wchar_t* v0; // eax
	wchar_t* v2; // [esp-10h] [ebp-10h]

	v2 = nox_strman_loadString_40F1D0("FindText", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1295);
	v0 = nox_strman_loadString_40F1D0("Find", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1295);
	nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&nox_wol_wnd_world_814980, (int)v0, (int)v2, 39, 0, 0);
	return sub_43AF90(10);
}

//----- (0043B630) --------------------------------------------------------
uint32_t* sub_43B630() {
	wchar_t* v0; // eax

	nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_815000);
	v0 = nox_strman_loadString_40F1D0("AttemptingConn", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1284);
	return nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&nox_wol_wnd_world_814980, 0, (int)v0, 34, 0, 0);
}

//----- (0043B6E0) --------------------------------------------------------
void sub_43B6E0() {
	wchar_t* v1; // eax
	wchar_t* v2; // [esp-10h] [ebp-10h]
	if (nox_wol_wnd_world_814980) {
		v2 = nox_strman_loadString_40F1D0("Kicked", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3331);
		v1 = nox_strman_loadString_40F1D0("Notification", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3331);
		nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v1, (int)v2, 33, 0, 0);
		sub_44A360(1);
		dword_5d4594_815096 = 0;
	} else {
		dword_5d4594_815096 = 1;
	}
}

//----- (0043B750) --------------------------------------------------------
void sub_43B750() {
	wchar_t* v1; // eax
	wchar_t* v2; // [esp-10h] [ebp-10h]

	if (nox_wol_wnd_world_814980) {
		v2 = nox_strman_loadString_40F1D0("Timeout", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3351);
		v1 = nox_strman_loadString_40F1D0("Notification", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3351);
		nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v1, (int)v2, 33, 0, 0);
		sub_44A360(1);
		dword_5d4594_815100 = 0;
	} else {
		dword_5d4594_815100 = 1;
	}
}

//----- (0043B7C0) --------------------------------------------------------
void nox_gui_wol_newServerLine_43B7C0(nox_gui_server_ent_t* srv) {
	wchar_t wbuf[128];
	char buf[332];

	if (dword_587000_87408) { // LAN games
		nox_window_call_field_94(nox_wol_wnd_gameList_815012, 16397, (int)getMemAt(0x587000, 91164), 4);

		strncpy(buf, srv->server_name, 15);
		buf[15] = 0;
		if (!memcmp(buf, getMemAt(0x5D4594, 815120), 1u)) {
			nox_sprintAddrPort_43BC80(srv->addr, srv->port, buf);
		}
		nox_swprintf(wbuf, L"%S", buf);
		sub_43BC10(wbuf, 100);
		nox_window_call_field_94(dword_5d4594_815016, 16397, wbuf, 4);

		nox_swprintf(wbuf, L"%d/%d", srv->players, srv->max_players);
		nox_window_call_field_94(dword_5d4594_815020, 16397, wbuf, 4);

		wchar_t* v6 = nox_gui_wol_gameModeString_43BCB0(srv->flags);
		if (srv->flags & 0x1000) { // quest
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 814772), L"%s %d", v6, srv->quest_level);
			nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16397, (int)getMemAt(0x5D4594, 814772), 4);
		} else {
			nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16397, v6, 4);
		}

		if (srv->ping == 9999) {
			nox_swprintf(wbuf, L"--");
		} else {
			_itow(srv->ping, wbuf, 10);
		}
		nox_window_call_field_94(dword_5d4594_815028, 16397, wbuf, 4);

		wbuf[0] = 0;
		if (srv->status & 0x20) {
			wchar_t* v9 = nox_strman_loadString_40F1D0("Noxworld.wnd:private", 0,
													   "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3486);
			nox_wcscat(wbuf, v9);
		}
		if (srv->status & 0x10) {
			if (wbuf[0]) {
				nox_wcscat(wbuf, L"+");
			}
			wchar_t* v10 = nox_strman_loadString_40F1D0("Noxworld.wnd:closed", 0,
														"C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3494);
			nox_wcscat(wbuf, v10);
		}
		if (!wbuf[0]) {
			wchar_t* v11;
			if (srv->players < srv->max_players) {
				v11 = nox_strman_loadString_40F1D0("Open", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3505);
			} else {
				v11 = nox_strman_loadString_40F1D0("Full", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3501);
			}
			nox_wcscat(wbuf, v11);
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16397, wbuf, 4);
	} else { // WOL games
		int a1 = srv;
		memset(buf, 0, sizeof(buf));
		*(uint32_t*)&buf[8] = 257;
		*(uint32_t*)&buf[16] = nox_wol_wnd_world_814980;
		int v4;
		if (*(int*)&dword_587000_87412 == -1) {
			int v1 = sub_437860(*(short*)(a1 + 44), *(short*)(a1 + 46));
			short v2 = *getMemU16Ptr(0x587000, 87528 + 8 * v1);
			v1 += 10054;
			*(uint16_t*)(a1 + 44) -= v2;
			*(uint16_t*)(a1 + 46) -= *getMemU16Ptr(0x587000, 7098 + 8 * v1);
			*(uint16_t*)(a1 + 44) >>= 1;
			*(uint16_t*)(a1 + 46) >>= 1;
			uint32_t* v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_814988, v1);
			v4 = nox_gui_newButtonOrCheckbox_4A91A0((int)v3, 1185, *(short*)(a1 + 44) - 5, *(short*)(a1 + 46) - 5, 10,
													10, buf);
		} else {
			*(uint16_t*)(a1 + 44) -= *getMemU16Ptr(0x587000, 87528 + 8 * dword_587000_87412);
			*(uint16_t*)(a1 + 46) -= *getMemU16Ptr(0x587000, 87530 + 8 * dword_587000_87412);
			v4 = nox_gui_newButtonOrCheckbox_4A91A0(*(int*)&dword_5d4594_814984, 1192, *(short*)(a1 + 44) - 10,
													*(short*)(a1 + 46) - 10, 20, 20, buf);
		}
		*(uint32_t*)(a1 + 28) = v4;
		sub_437320(a1);
		char v13[32];
		if (*(uint8_t*)(a1 + 120)) {
			strncpy(v13, (const char*)(a1 + 120), 15);
			v13[15] = 0;
		} else {
			nox_sprintAddrPort_43BC80(a1 + 12, *(uint16_t*)(a1 + 109), v13);
		}
		if (*(uint32_t*)(a1 + 96) == 9999) {
			nox_swprintf(wbuf, L"%S -- ms", v13);
		} else {
			nox_swprintf(wbuf, L"%S %dms", v13, *(uint32_t*)(a1 + 96));
		}
		nox_xxx_wndWddSetTooltip_46B000((wchar_t*)(*(uint32_t*)(a1 + 28) + 36), wbuf);
		nox_xxx_wndSetProc_46B2C0(*(uint32_t*)(a1 + 28), nox_xxx_windowMultiplayerSub_439E70);
		uint32_t* result = *(uint32_t**)(a1 + 28);
		*result = *(uint32_t*)(a1 + 36) + 10070;
	}
}

//----- (0043BCB0) --------------------------------------------------------
wchar_t* nox_gui_wol_gameModeString_43BCB0(short a1) {
	if (a1 & 0x1000) {
		return nox_strman_loadString_40F1D0("Quest", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3534);
	}
	if (a1 & 0x20) {
		return nox_strman_loadString_40F1D0("CTF", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3541);
	}
	if (a1 & 0x400) {
		return nox_strman_loadString_40F1D0("Highlander", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3545);
	}
	if (a1 & 0x10) {
		return nox_strman_loadString_40F1D0("KotR", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3550);
	}
	if (a1 & 0x40) {
		return nox_strman_loadString_40F1D0("Flagball", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3555);
	}
	if ((a1 & 0x80u) == 0) {
		return nox_strman_loadString_40F1D0("Arena", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3563);
	}
	return nox_strman_loadString_40F1D0("Chat", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3559);
}
