#include "noxworld.h"

#include "../../common/object/armrlook.h"
#include "../../common/object/weaplook.h"
#include "../../proto.h"
#include "../gui/gamewin/gamewin.h"
#include "selchar.h"

extern _DWORD dword_5d4594_815096;
extern _DWORD dword_5d4594_815060;
extern _DWORD dword_5d4594_815052;
extern _DWORD dword_5d4594_815100;
extern _DWORD dword_5d4594_814548;
extern _DWORD dword_5d4594_814992;
extern _DWORD dword_5d4594_814552;
extern _DWORD dword_5d4594_815056;
extern _DWORD dword_5d4594_814996;
extern _DWORD dword_5d4594_814988;
extern _DWORD dword_587000_87408;
extern _QWORD qword_5d4594_814956;
extern _QWORD qword_5d4594_815068;
extern _DWORD dword_5d4594_815044;
extern _DWORD dword_5d4594_815088;
extern _DWORD dword_5d4594_814624;
extern _DWORD dword_5d4594_815032;
extern _DWORD dword_5d4594_815020;
extern _DWORD dword_5d4594_815024;
extern _DWORD dword_5d4594_815028;
extern _DWORD dword_5d4594_814984;
extern _DWORD dword_5d4594_815016;
extern _DWORD dword_5d4594_815048;
extern _DWORD dword_587000_87404;
extern _DWORD dword_587000_87412;
extern _DWORD dword_5d4594_815000;
extern _DWORD dword_5d4594_815012;
extern _DWORD dword_5d4594_815004;
extern _DWORD dword_5d4594_814980;
extern int nox_win_width;
extern int nox_win_height;

nox_wnd_xxx* nox_wnd_xxx_815040 = 0;

//----- (004373A0) --------------------------------------------------------
void sub_4373A0() {
	wchar_t* v0; // eax
	wchar_t* v1; // eax
	wchar_t* v2; // eax

	if (!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_815000)) {
		nox_window_set_hidden(*(int*)&dword_5d4594_815000, 1);
		dword_5d4594_815056 = 0;
		nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_815000);
		nox_xxx_windowDestroyChildsMB_46B500(*(int*)&dword_5d4594_814980);
	}
	if (*(int*)&dword_587000_87408 == 1 || *(int*)&dword_587000_87412 == -1) {
		if (dword_5d4594_815048 == 1) {
			dword_5d4594_815048 = 0;
			sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
			v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 87876), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									   619);
			nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v2, 0);
			nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
		} else {
			sub_43C1E0();
			sub_49FF20();
			if (dword_587000_87404 == 1) {
				*getMemU32Ptr(0x5D4594, 815084) = 1;
				sub_41E300(7);
				sub_4207F0(4);
				sub_40D380();
			}
			nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
		}
	} else if (dword_5d4594_815048 == 1) {
		dword_5d4594_815048 = 0;
		sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
		nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_814984);
		sub_4375C0(1);
		v0 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 87928), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 643);
		nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v0, 0);
		nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
	} else {
		sub_49FF20();
		if (dword_587000_87404) {
			dword_587000_87412 = -1;
			nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_814984);
			nox_window_set_hidden(*(int*)&dword_5d4594_814984, 1);
			nox_window_set_hidden(*(int*)&dword_5d4594_814988, 0);
			v1 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 87980), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									   660);
			nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v1, 0);
			sub_4378B0();
			nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
		} else {
			sub_43C1E0();
		}
	}
}

//----- (004378B0) --------------------------------------------------------
int sub_4378B0() {
	int result;  // eax
	uint16_t v1;  // ax
	wchar_t* v2; // eax
	int v3;      // eax
	int v4;      // [esp-4h] [ebp-4h]

	result = sub_44A4A0();
	if (result) {
		*getMemU32Ptr(0x5D4594, 815104) = 1;
	} else {
		*getMemU64Ptr(0x5D4594, 815076) = nox_call_get_ticks();
		dword_5d4594_815060 = 0;
		sub_4379C0();
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16399, 0, 0);
		sub_49FFA0(1);
		dword_5d4594_815088 = 0;
		if (dword_587000_87404) {
			sub_41F370(1);
			v3 = sub_41E2F0();
			sub_41DA70(v3, 12);
		} else {
			sub_555000(sub_4375F0);
			v4 = nox_platform_get_ticks();
			*getMemU32Ptr(0x5D4594, 814964) = v4;
			v1 = nox_xxx_servGetPort_40A430();
			nox_xxx_lobbyMakePacket_554AA0(v1, 0, 0, v4);
			v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88032), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									   1097);
			nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_814980, 0, (int)v2, 0, 0, 0);
		}
		*getMemU32Ptr(0x5D4594, 815104) = 0;
		result = (unsigned __int64)(*getMemU64Ptr(0x5D4594, 815076) + (__int64)120000) >> 32;
		*(_QWORD*)&qword_5d4594_815068 = *getMemU64Ptr(0x5D4594, 815076) + (__int64)120000;
	}
	return result;
}

//----- (004379F0) --------------------------------------------------------
int sub_4379F0() {
	int result;   // eax
	_DWORD* v2;   // esi
	_DWORD* v3;   // eax
	_DWORD* v4;   // eax
	wchar_t* v5;  // eax
	_DWORD* v6;   // eax
	wchar_t* v7;  // eax
	_DWORD* v8;   // esi
	_DWORD* v9;   // ebx
	_DWORD* v10;  // ebp
	_DWORD* v11;  // edi
	_DWORD* v12;  // esi
	_DWORD* v13;  // ebx
	_DWORD* v14;  // ebp
	_DWORD* v15;  // edi
	int v16;      // eax
	wchar_t* v17; // eax
	wchar_t* v18; // eax
	_DWORD* v19;  // eax
	_DWORD* v20;  // eax
	_DWORD* v21;  // eax
	_DWORD* v22;  // eax
	_DWORD* v23;  // eax
	_DWORD* v24;  // eax
	_DWORD* v25;  // eax
	_DWORD* v26;  // eax
	wchar_t* v27; // [esp-14h] [ebp-1Ch]
	wchar_t* v28; // [esp-14h] [ebp-1Ch]

	sub_4D6F60(0);
	sub_4D6F80(0);
	if (!nox_common_gameFlags_check_40A5C0(0x2000000) && !sub_4D6F30()) {
		dword_5d4594_815048 = 0;
		dword_587000_87412 = -1;
	}
	*getMemU32Ptr(0x5D4594, 815076) = 0;
	*getMemU32Ptr(0x5D4594, 815080) = 0;
	*getMemU32Ptr(0x5D4594, 815084) = 0;
	sub_43BDD0(10000);
	sub_4A24C0(1);
	if (*(int*)&dword_587000_87404 != 1 || (sub_4A1BE0(0), *(int*)&dword_587000_87412 != -1))
		sub_49FDB0(0);
	if (dword_5d4594_814980) {
		dword_5d4594_815044 = 0;
		*(_BYTE*)(&nox_wnd_xxx_815040->field_16) = 3;
		nox_wnd_xxx_815040->field_14 = sub_438330;
		sub_43BE40(3);
		nox_xxx_clientPlaySoundSpecial_452D80(922, 100);
		nox_window_set_hidden(*(int*)&dword_5d4594_814980, 0);
		nox_window_set_hidden(*(int*)&dword_5d4594_815000, 0);
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_814984, 1);
		if (dword_5d4594_815048)
			sub_4375C0(0);
		sub_46ACE0(*(_DWORD**)&dword_5d4594_814980, 10047, 10051, dword_587000_87408 == 0);
		if (sub_4D6FA0() == 2) {
			v25 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10010);
			nox_window_call_field_94(*(int*)&dword_5d4594_814980, 16391, (int)v25, 0);
			v26 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10010);
			nox_window_call_field_94(*(int*)&dword_5d4594_814980, 16391, (int)v26, 0);
		}
		result = 1;
	} else {
		dword_5d4594_814980 = nox_new_window_from_file("noxworld.wnd", nox_xxx_windowMultiplayerSub_439E70);
		if (dword_5d4594_814980) {
			sub_49FF20();
			nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_814980);
			nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_814980, sub_439D00, 0, 0);
			nox_wnd_xxx_815040 = nox_wnd_sub_43C5B0(*(_DWORD**)&dword_5d4594_814980, 0, 0, 0, -480, 0, 20, 0, -40);
			if (nox_wnd_xxx_815040) {
				nox_wnd_xxx_815040->field_0 = 10000;
				nox_wnd_xxx_815040->field_12 = sub_438370;
				nox_wnd_xxx_815040->field_14 = sub_438330;
				dword_5d4594_814984 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10020);
				dword_5d4594_814988 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10021);
				nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_814984, sub_439D00);
				nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_814988, sub_439D00);
				nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_814988, nox_xxx_windowMultiplayerSub_439E70);
				dword_5d4594_814996 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10011);
				dword_5d4594_815012 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10037);
				dword_5d4594_815004 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10034);
				dword_5d4594_815000 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10033);
				dword_5d4594_814992 = sub_489B80(*(int*)&dword_5d4594_814980);
				*getMemU32Ptr(0x5D4594, 815008) = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10001);
				dword_5d4594_815016 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10038);
				dword_5d4594_815020 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10039);
				dword_5d4594_815024 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10040);
				dword_5d4594_815028 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10041);
				dword_5d4594_815032 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10042);
				v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10002);
				if (nox_common_gameFlags_check_40A5C0(0x1000000))
					nox_xxx_wnd_46ABB0((int)v2, 0);
				v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10003);
				v3[9] &= 0xFFFFFFFB;
				v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10046);
				nox_xxx_wndSetDrawFn_46B340((int)v4, sub_438C80);
				nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_815012, nox_xxx_windowMultiplayerSub_439E70);
				nox_window_set_hidden(*(int*)&dword_5d4594_815012, 1);
				nox_window_set_hidden(*(int*)&dword_5d4594_815000, 1);
				nox_xxx_wnd_46B280(*getMemIntPtr(0x5D4594, 815008), *(int*)&dword_5d4594_814980);
				if (dword_587000_87404) {
					nox_game_SetCliDrawFunc(sub_41E210);
					v6 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10007);
					nox_window_set_hidden((int)v6, 0);
					dword_587000_87412 = -1;
					nox_window_set_hidden(*(int*)&dword_5d4594_814984, 1);
					v7 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88164), 0,
											   "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2530);
					nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v7, 0);
				} else {
					dword_587000_87412 = 0;
					nox_window_set_hidden(*(int*)&dword_5d4594_814988, 1);
					v5 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88112), 0,
											   "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2517);
					nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v5, 0);
					sub_46ACE0(*(_DWORD**)&dword_5d4594_814984, 10620, 10631, 1);
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
				v8 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_815012, 10053);
				v9 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_815012, 10043);
				v10 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_815012, 10044);
				v11 = *(_DWORD**)(dword_5d4594_815012 + 32);
				nox_xxx_wnd_46B280((int)v8, *(int*)&dword_5d4594_815012);
				nox_xxx_wnd_46B280((int)v9, *(int*)&dword_5d4594_815012);
				nox_xxx_wnd_46B280((int)v10, *(int*)&dword_5d4594_815012);
				v11[9] = v8;
				v11[7] = v9;
				v11[8] = v10;
				*(_DWORD*)(v8[100] + 8) = 16;
				*(_DWORD*)(v8[100] + 12) = 12;
				nox_xxx_wndSetOffsetMB_46AE40(v8[100], 0, -15);
				v12 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_815000, 10032);
				v13 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_815000, 10035);
				v14 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_815000, 10036);
				v15 = *(_DWORD**)(dword_5d4594_815004 + 32);
				nox_xxx_wnd_46B280((int)v12, *(int*)&dword_5d4594_815004);
				nox_xxx_wnd_46B280((int)v13, *(int*)&dword_5d4594_815004);
				nox_xxx_wnd_46B280((int)v14, *(int*)&dword_5d4594_815004);
				v15[9] = v12;
				v15[7] = v13;
				v15[8] = v14;
				*(_DWORD*)(v12[100] + 8) = 16;
				*(_DWORD*)(v12[100] + 12) = 10;
				sub_438480();
				v16 = nox_xxx_servGetPort_40A430();
				sub_40A3C0(v16);
				dword_5d4594_815048 = 0;
				dword_5d4594_815044 = 0;
				dword_5d4594_815052 = 0;
				dword_5d4594_814548 = 0;
				*(_QWORD*)&qword_5d4594_815068 = nox_call_get_ticks() + 1000;
				if (dword_587000_87408 == 1)
					sub_4383A0();
				if (!dword_587000_87404)
					nox_xxx_createSocketLocal_554B40(0);
				dword_5d4594_815088 = 0;
				nox_xxx_loadModifyers_4158C0();
				nox_xxx_loadLook_415D50();
				sub_430C30_set_video_max(NOX_MAX_WIDTH, NOX_MAX_HEIGHT);
				nox_client_setCursorType_477610(0);
				if (dword_5d4594_815096) {
					v27 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88552), 0,
												"C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2616);
					v17 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88600), 0,
												"C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2616);
					nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v17, (int)v27, 33, 0, 0);
					sub_44A360(1);
					dword_5d4594_815096 = 0;
				} else if (dword_5d4594_815100) {
					v28 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88656), 0,
												"C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2623);
					v18 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88704), 0,
												"C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2623);
					nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v18, (int)v28, 33, 0, 0);
					sub_44A360(1);
					dword_5d4594_815100 = 0;
				}
				sub_43DE40(sub_438770);
				if (sub_44A4A0())
					sub_44A4B0();
				nox_xxx_wndSetDrawFn_46B340(*(int*)&dword_5d4594_814984, sub_438E30);
				v19 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10054);
				nox_xxx_wndSetDrawFn_46B340((int)v19, sub_438E30);
				v20 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10055);
				nox_xxx_wndSetDrawFn_46B340((int)v20, sub_438E30);
				v21 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10056);
				nox_xxx_wndSetDrawFn_46B340((int)v21, sub_438E30);
				v22 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10057);
				nox_xxx_wndSetDrawFn_46B340((int)v22, sub_438E30);
				if (!dword_587000_87408)
					sub_46ACE0(*(_DWORD**)&dword_5d4594_814980, 10047, 10051, 1);
				if (sub_4D6FA0() == 1) {
					v23 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10002);
					nox_window_call_field_94(*(int*)&dword_5d4594_814980, 16391, (int)v23, 0);
					sub_4D6F60(1);
					v24 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10020);
					nox_window_call_field_93((int)v24, 5, 15663512, 0);
				}
				result = 1;
			} else {
				result = 0;
			}
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (004383A0) --------------------------------------------------------
int sub_4383A0() {
	wchar_t* v0; // eax
	int result;  // eax

	if (!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_814992)) {
		nox_window_set_hidden(*(int*)&dword_5d4594_814992, 1);
		sub_489870();
	}
	nox_window_set_hidden(*(int*)&dword_5d4594_815012, 0);
	nox_window_set_hidden(*(int*)&dword_5d4594_814984, 1);
	nox_window_set_hidden(*(int*)&dword_5d4594_814988, 1);
	sub_46AD20(*(_DWORD**)&dword_5d4594_814980, 10006, 10007, 1);
	sub_46ACE0(*(_DWORD**)&dword_5d4594_814980, 10047, 10051, 0);
	v0 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88760), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 418);
	nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v0, 0);
	result = dword_587000_87404;
	dword_587000_87408 = 1;
	if (dword_587000_87404 == 1)
		dword_587000_87412 = -1;
	return result;
}

//----- (00438770) --------------------------------------------------------
int sub_438770() {
	int result;  // eax
	__int64 v1;  // rax
	wchar_t* v2; // eax
	wchar_t* v3; // eax
	wchar_t* v4; // eax
	wchar_t* v5; // eax
	_WORD* v6;   // esi
	_DWORD* v7;  // eax

	if (dword_5d4594_814548) {
		switch (dword_5d4594_814548) {
		case 2:
			sub_438BD0();
			sub_43AF90(1);
			result = 1;
			break;
		case 3:
			if ((unsigned __int64)nox_call_get_ticks() < *(_QWORD*)&qword_5d4594_814956)
				goto LABEL_29;
			sub_43AFA0(8);
			result = 1;
			break;
		case 4:
			sub_43AF90(3);
			v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88816), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									   1343);
			sub_449E30((int)v2);
			*(_QWORD*)&qword_5d4594_814956 = nox_call_get_ticks() + 20000;
			result = 1;
			break;
		case 5:
			v3 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88864), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									   1349);
			sub_449E00((int)v3);
			v4 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88916), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
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
			v5 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 88976), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									   1364);
			sub_449E30((int)v5);
			sub_449EA0(0);
			nox_game_SetCliDrawFunc(nox_xxx_cliDrawConnectedLoop_43B360);
			sub_43AF90(1);
			result = 1;
			break;
		case 8:
			v1 = nox_call_get_ticks();
			dword_5d4594_814548 = 9;
			*getMemU64Ptr(0x5D4594, 814972) = v1 + 1000;
			result = 1;
			break;
		case 9:
			if ((unsigned __int64)nox_call_get_ticks() <= *getMemU64Ptr(0x5D4594, 814972))
				goto LABEL_29;
			nox_xxx_initSomethingNetGame_438A90();
			result = 1;
			break;
		case 0xA:
			v6 = (_WORD*)sub_449E60(4);
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
			 !wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_815012)) &&
			!dword_5d4594_815048 && !dword_5d4594_815044 && !dword_5d4594_815052 &&
			wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_815000)) {
			if ((unsigned __int64)nox_call_get_ticks() > *(_QWORD*)&qword_5d4594_815068) {
				sub_4378B0();
				return 1;
			}
			if ((unsigned __int64)(nox_call_get_ticks() - *getMemU64Ptr(0x5D4594, 815076)) > 0x3E8 && !dword_5d4594_815060 &&
				!dword_587000_87404) {
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

	if (!sub_44A4A0())
		nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_814980, 0, 0, 0, 0, 0);
	v0 = dword_5d4594_814552;
	if (dword_5d4594_814552 != 8 && dword_5d4594_814552 != 9 && dword_5d4594_814552 != 10) {
		v1 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89152), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1262);
		sub_449E00((int)v1);
		v0 = dword_5d4594_814552;
	}
	v2 = nox_xxx_loadString_40F1D0(*(char**)getMemAt(0x587000, 4 * v0 + 87416), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
							   1265);
	sub_449E30((int)v2);
	dword_5d4594_815044 = 0;
	sub_449EA0(1);
	sub_44A360(1);
	if (dword_587000_87404 == 1)
		sub_40D380();
	return sub_4A24C0(1);
}

//----- (00439370) --------------------------------------------------------
void __cdecl sub_439370(int2* a1, int a2) {
	int v2;      // eax
	wchar_t* v3; // eax

	if (!(*(_BYTE*)(a2 + 164) & 0x10) || (LOBYTE(v2) = nox_client_checkQuestExp_SKU2_4D7700(), v2)) {
		sub_439450(a1->field_0, a1->field_4, a1);
		sub_46B120(*(_DWORD**)&dword_5d4594_815000, 0);
		nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_815000);
		sub_46C690(*(int*)&dword_5d4594_815000);
		nox_wnd_nox_xxx_wndDraw_46A9B0(*(_DWORD**)&dword_5d4594_815000, a1->field_0, a1->field_4);
		sub_4394D0(a2);
		dword_5d4594_815056 = 1;
		*getMemU16Ptr(0x5D4594, 814604) = *(_WORD*)(a2 + 109);
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING))
			nox_xxx_wnd_46ABB0(*getMemIntPtr(0x5D4594, 815008), 0);
	} else {
		v3 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89244), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 688);
		nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_814980, 0, (int)v3, 33, 0, 0);
		sub_44A360(0);
		sub_44A4B0();
	}
}
//----- (004394D0) --------------------------------------------------------
int __cdecl sub_4394D0(int a1) {
	int v1;              // ebp
	wchar_t* v2;         // eax
	wchar_t* v3;         // eax
	wchar_t* v4;         // eax
	wchar_t* v5;         // eax
	wchar_t* v6;         // eax
	wchar_t* v7;         // eax
	wchar_t* v8;         // eax
	__int16 v9;          // ax
	wchar_t* v10;        // eax
	wchar_t* v11;        // eax
	int result;          // eax
	wchar_t* v13;        // eax
	wchar_t* v14;        // eax
	int v15;             // ebx
	int v16;             // esi
	int v17;             // edi
	int v18;             // ebp
	int v19;             // eax
	wchar_t* v20;        // eax
	int v21;             // esi
	wchar_t* v22;        // eax
	int v23;             // ebx
	int v24;             // edi
	int v25;             // ebp
	int v26;             // eax
	wchar_t* v27;        // eax
	int v28;             // edi
	wchar_t* v29;        // eax
	int v30;             // esi
	int v31;             // ebx
	wchar_t* v32;        // eax
	wchar_t* v33;        // [esp-8h] [ebp-14Ch]
	unsigned __int8 v34; // [esp+10h] [ebp-134h]
	unsigned __int8 v35; // [esp+10h] [ebp-134h]
	int v36;             // [esp+14h] [ebp-130h]
	char v37[16];        // [esp+18h] [ebp-12Ch]
	wchar_t v38[100];    // [esp+7Ch] [ebp-C8h]

	v36 = a1 + 111;
	v1 = *(_BYTE*)(a1 + 102) & 0x7F;
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16399, 0, 0);
	v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89316), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 749);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v2, 14);
	if (*(_BYTE*)(a1 + 120)) {
		strncpy(v37, (const char*)(a1 + 120), 0xFu);
		v37[15] = 0;
	} else {
		sub_43BC80(a1 + 12, *(_WORD*)(a1 + 109), v37);
	}
	nox_swprintf(v38, L"%S", v37);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	if (dword_587000_87404 == 1) {
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89332), -1);
		v3 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89376), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 766);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v3, 14);
		sub_439CC0(*(_DWORD*)(a1 + 32), v37);
		nox_swprintf(v38, L"%S", v37);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89396), -1);
	v4 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89440), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 774);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v4, 14);
	if (*(_DWORD*)(a1 + 96) == 9999)
		nox_swprintf(v38, L"--");
	else
		nox_swprintf(v38, L"%d", *(_DWORD*)(a1 + 96));
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89464), -1);
	v5 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89508), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 787);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v5, 14);
	v6 = sub_43BCB0(*(_WORD*)(a1 + 163));
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v6, -1);
	if (*(_BYTE*)(a1 + 164) & 0x10) {
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89520), -1);
		v7 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89564), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 794);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v7, 14);
		nox_swprintf(v38, L"%d", *(unsigned __int16*)(a1 + 165));
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89580), -1);
	v8 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89624), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 801);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v8, 14);
	strcpy(v37, (const char*)(a1 + 111));
	nox_swprintf(v38, L"%S", v37);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89636), -1);
	v9 = *(_WORD*)(a1 + 163);
	if (v9 & 0xC000u) {
		if (v9 & 0x4000)
			v33 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89680), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
										811);
		else
			v33 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89732), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
										815);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v33, 6);
		v10 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89780), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 817);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v10, 6);
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89788), -1);
	v11 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89832), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 822);
	nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v11, 14);
	nox_swprintf(v38, L"%d/%d\n", *(unsigned __int8*)(a1 + 103), *(unsigned __int8*)(a1 + 104));
	result = nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v38, -1);
	if (*(_BYTE*)(a1 + 164) & 0x20) {
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89860), -1);
		v13 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89904), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 831);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v13, 14);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, *getMemU32Ptr(0x587000, 4 * v1 + 87472), -1);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 89916), -1);
		v14 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 89960), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 836);
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
			if (nox_xxx_spellGetValidMB_424B50(v17) && !(v16 & *(_DWORD*)(v36 + 4 * v34 + 24)) && nox_xxx_spellGetFlags_424A70(v17) & 0x7000000) {
				v15 = 1;
				v19 = nox_xxx_spellLoadName_424930(v17);
				nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, v19, 4);
			}
			++v17;
			--v18;
		} while (v18);
		if (!v15) {
			v20 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90016), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
										866);
			nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v20, 4);
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 90024), -1);
		v21 = 0;
		v22 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90068), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 872);
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v22, 14);
		v23 = 1;
		v35 = 0;
		v24 = 1;
		v25 = 27;
		do {
			if (!((unsigned __int8)v23 & *(_BYTE*)(v35 + v36 + 44))) {
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
			v27 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90124), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
										899);
			nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v27, 4);
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)getMemAt(0x587000, 90132), -1);
		v28 = 0;
		v29 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90176), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 905);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v29, 14);
		v30 = 1;
		v31 = 26;
		do {
			if (!(v30 & *(_DWORD*)(a1 + 159))) {
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
			v32 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90232), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
										920);
			result = nox_window_call_field_94(*(int*)&dword_5d4594_815004, 16397, (int)v32, 4);
		}
	}
	return result;
}

//----- (00439E70) --------------------------------------------------------
int __cdecl nox_xxx_windowMultiplayerSub_439E70(int a1, unsigned int a2, int* a3, int a4) {
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
	_DWORD* v17;        // eax
	_DWORD* v18;        // eax
	int v19;            // esi
	int v20;            // esi
	wchar_t* v21;       // eax
	int v22;            // eax
	wchar_t* v23;       // eax
	char* v24;          // eax
	char* v25;          // eax
	char* v26;          // eax
	int v27;            // eax
	uint16_t v28;        // [esp-8h] [ebp-A0h]
	int2 v29;           // [esp+4h] [ebp-94h]
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
			v29 = *nox_client_getMousePos_4309F0();
			dword_5d4594_814624 = sub_4A28C0(a4);
			sub_439370(&v29, *(int*)&dword_5d4594_814624);
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
	if (a2 != 16391)
		return 0;
	v4 = nox_xxx_wndGetID_46B0A0(a3);
	v5 = v4;
	if (v4 != 10043 && v4 != 10044 && v4 != 10035 && v4 != 10036)
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	if (v5 >= 10070) {
		v29 = *nox_client_getMousePos_4309F0();
		v30 = v29.field_0 - 216;
		v31 = v29.field_4 - 27;
		v6 = (int*)sub_4A0020();
		if (sub_4A25C0(&v30, v6) >= 2) {
			v7 = (int*)sub_4A0020();
			*getMemU32Ptr(0x5D4594, 815036) = sub_4A2610(*(int*)&dword_5d4594_814980, &v30, v7);
		} else {
			dword_5d4594_814624 = sub_4A0490(v5 - 10070);
			sub_439370(&v29, *(int*)&dword_5d4594_814624);
		}
		nox_xxx_cursorSetTooltip_4776B0((wchar_t*)getMemAt(0x5D4594, 815112));
	}
	if (v5 > 10006) {
		switch (v5) {
		case 10007:
			if (dword_5d4594_815048)
				sub_4373A0();
			if (dword_587000_87404)
				sub_43A980();
			else
				OnLibraryNotice(418, 0);
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
			sub_4A0290(v5);
			sub_4A0390();
			return 0;
		case 10054:
			dword_587000_87412 = 0;
			sub_43A810();
			sub_4378B0();
			if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
				v24 = sub_4A7EF0();
				sub_439D90(*(_DWORD*)v24 + 216, *((_DWORD*)v24 + 1) + 27);
			} else {
				sub_439D90(0x198u, 0xEFu);
			}
			result = 0;
			break;
		case 10055:
			dword_587000_87412 = 1;
			sub_43A810();
			sub_4378B0();
			if (!nox_common_gameFlags_check_40A5C0(0x2000000)) {
				sub_439D90(0x198u, 0xEFu);
				result = 0;
			} else {
				v25 = sub_4A7EF0();
				sub_439D90(*(_DWORD*)v25 + 216, *((_DWORD*)v25 + 1) + 27);
				return 0;
			}
			break;
		case 10056:
			dword_587000_87412 = 2;
			sub_43A810();
			sub_4378B0();
			if (!nox_common_gameFlags_check_40A5C0(0x2000000)) {
				sub_439D90(0x198u, 0xEFu);
			} else {
				v24 = sub_4A7EF0();
				sub_439D90(*(_DWORD*)v24 + 216, *((_DWORD*)v24 + 1) + 27);
			}
			result = 0;
			break;
		case 10057:
			dword_587000_87412 = 3;
			sub_43A810();
			sub_4378B0();
			if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
				v26 = sub_4A7EF0();
				sub_439D90(*(_DWORD*)v26 + 216, *((_DWORD*)v26 + 1) + 27);
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
		dword_5d4594_815048 = 0;
		sub_4378B0();
		return 0;
	}
	if (v5 > 10002) {
		v19 = v5 - 10003;
		if (v19) {
			v20 = v19 - 1;
			if (!v20) {
				dword_5d4594_815048 = 0;
				sub_4383A0();
				sub_4378B0();
				return 0;
			}
			if (v20 == 1) {
				dword_5d4594_815048 = 0;
				nox_window_set_hidden(*(int*)&dword_5d4594_815012, 1);
				nox_window_set_hidden(*(int*)&dword_5d4594_814984, 1);
				nox_window_set_hidden(*(int*)&dword_5d4594_814988, 1);
				nox_window_set_hidden(*(int*)&dword_5d4594_814992, 0);
				sub_46AD20(*(_DWORD**)&dword_5d4594_814980, 10006, 10007, 0);
				sub_46ACE0(*(_DWORD**)&dword_5d4594_814980, 10047, 10051, 1);
				v21 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90440), 0,
											"C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2186);
				nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v21, 0);
				return 0;
			}
			return 0;
		}
		LOBYTE(v22) = nox_client_checkQuestExp_SKU2_4D7700();
		if (!v22) {
			v23 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90328), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
										2013);
			nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_814980, 0, (int)v23, 33, 0, 0);
			sub_44A360(0);
			sub_44A4B0();
			return 0;
		}
		dword_5d4594_815048 = 1;
		nox_common_gameFlags_unset_40A540(0x10000);
		nox_client_setMousePos_430B10(408, 239);
		sub_4375C0(0);
		if (!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_814992))
			sub_489870();
		sub_4D6F60(1);
		nox_xxx_cliShowHideTubes_470AA0(1);
		if (dword_587000_87404 == 1) {
			if (*(int*)&dword_587000_87412 != -1)
				return 0;
			goto LABEL_52;
		}
	LABEL_53:
		dword_587000_87412 = 0;
		v18 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10020);
		nox_window_call_field_93((int)v18, 5, 15663512, 0);
		return 0;
	}
	if (v5 == 10002) {
		if (nox_common_gameFlags_check_40A5C0(0x1000000))
			return 0;
		dword_5d4594_815048 = 1;
		nox_xxx_setGameFlags_40A4D0(0x10000);
		nox_xxx_cliShowHideTubes_470AA0(0);
		nox_client_setMousePos_430B10(408, 239);
		sub_4375C0(0);
		if (!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_814992))
			sub_489870();
		if (nox_common_gameFlags_check_40A5C0(0x2000000) || sub_4D6F30())
			return 0;
		if (dword_587000_87404 == 1) {
			if (*(int*)&dword_587000_87412 != -1)
				return 0;
		LABEL_52:
			v16 = nox_common_randomInt_415FA0(10054, 10057);
			v17 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814980, v16);
			nox_window_call_field_94(*(int*)&dword_5d4594_814980, 16391, (int)v17, 0);
			return 0;
		}
		goto LABEL_53;
	}
	v8 = v5 - 4001;
	if (!v8) {
		if (sub_43AF80() == 6) {
			v12 = (const wchar_t*)sub_449E60(4);
			nox_wcsncpy(v33, v12, 9u);
			v33[8] = 0;
			v28 = sub_43B320();
			v13 = nox_xxx_inServerGetAddr_43B300();
			sub_5550D0(v13, v28, buf);
			sub_43AF90(3);
			*(_QWORD*)&qword_5d4594_814956 = nox_call_get_ticks() + 20000;
			sub_449EA0(0);
			return 0;
		}
		if (sub_43AF80() == 10) {
			v14 = sub_449E60(4);
			nox_sprintf(v35, "%S", v14);
			v15 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90496), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
										2209);
			sub_449E30((int)v15);
			sub_43AF90(11);
			sub_40D740((int)v34);
			sub_449EA0(0);
			return 0;
		}
		if (sub_43AF80() == 1) {
			if (dword_587000_87404 == 1)
				sub_40D380();
			sub_43A920();
			sub_4379F0();
			return 0;
		}
		if (*getMemU32Ptr(0x5D4594, 815104)) {
			*(_QWORD*)&qword_5d4594_815068 = nox_call_get_ticks() + 1000;
			return 0;
		}
		return 0;
	}
	v9 = v8 - 1;
	if (!v9) {
		if (dword_587000_87404 == 1)
			sub_40D380();
		sub_43A920();
		sub_4379F0();
		return 0;
	}
	if (v9 != 5999 || dword_5d4594_815044)
		return 0;
	v10 = sub_43B340();
	if (v10 & 0x1000) {
		sub_4D6F80(1);
		nox_xxx_cliShowHideTubes_470AA0(1);
	}
	sub_43B460();
	if (sub_4D6F70()) {
		if (sub_4DC7D0()) {
			sub_4A7A70(1);
			sub_4A4DB0();
			dword_5d4594_815044 = 1;
			sub_4A2890();
			return 0;
		}
	} else if (sub_4DC630()) {
		sub_4A7A70(1);
		sub_4A4DB0();
		dword_5d4594_815044 = 1;
		sub_4A2890();
		return 0;
	}
	sub_4A7A70(0);
	sub_4A4840();
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
	nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_814984, *getMemU32Ptr(0x5D4594, 4 * dword_587000_87412 + 814900));
	if (dword_5d4594_815048 == 1)
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90544), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 377);
	else
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90596), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 382);
	nox_window_call_field_94(*(int*)&dword_5d4594_814996, 16385, (int)v2, 0);
	if (dword_587000_87404 == 1) {
		sub_46ACE0(*(_DWORD**)&dword_5d4594_814984, 10600, 10611, 1);
		v0 = 0;
		v1 = getMemIntPtr(0x587000, 87560);
		do {
			sub_46ACE0(*(_DWORD**)&dword_5d4594_814984, *v1, v1[1], v0 != dword_587000_87412);
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

	v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90648), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1295);
	v0 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90700), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1295);
	nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_814980, (int)v0, (int)v2, 39, 0, 0);
	return sub_43AF90(10);
}

//----- (0043B630) --------------------------------------------------------
_DWORD* sub_43B630() {
	wchar_t* v0; // eax

	nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_815000);
	v0 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90904), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1284);
	return nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_814980, 0, (int)v0, 34, 0, 0);
}

//----- (0043B6E0) --------------------------------------------------------
void sub_43B6E0() {
	wchar_t* v1; // eax
	wchar_t* v2; // [esp-10h] [ebp-10h]
	if (dword_5d4594_814980) {
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 90960), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3331);
		v1 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91008), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3331);
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

	if (dword_5d4594_814980) {
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91064), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3351);
		v1 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91112), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3351);
		nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v1, (int)v2, 33, 0, 0);
		sub_44A360(1);
		dword_5d4594_815100 = 0;
	} else {
		dword_5d4594_815100 = 1;
	}
}

//----- (0043B7C0) --------------------------------------------------------
_DWORD* __cdecl nox_xxx_openfuckupwindow_43B7C0(int a1) {
	int v1;                // eax
	__int16 v2;            // cx
	_DWORD* v3;            // eax
	int v4;                // eax
	_DWORD* result;        // eax
	wchar_t* v6;           // eax
	int v7;                // eax
	char v8;               // al
	wchar_t* v9;           // eax
	wchar_t* v10;          // eax
	wchar_t* v11;          // [esp-14h] [ebp-208h]
	WCHAR WideCharStr[64]; // [esp+8h] [ebp-1ECh]
	char v13[32];          // [esp+88h] [ebp-16Ch]
	char v14[332];         // [esp+A8h] [ebp-14Ch]

	if (dword_587000_87408) {
		nox_window_call_field_94(*(int*)&dword_5d4594_815012, 16397, (int)getMemAt(0x587000, 91164), 4);
		strncpy(v14, (const char*)(a1 + 120), 0xFu);
		v14[15] = 0;
		if (!memcmp(v14, getMemAt(0x5D4594, 815120), 1u))
			sub_43BC80(a1 + 12, *(_WORD*)(a1 + 109), v14);
		nox_swprintf(WideCharStr, L"%S", v14);
		sub_43BC10(WideCharStr, 0x64u);
		nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16397, (int)WideCharStr, 4);
		nox_swprintf(WideCharStr, L"%d/%d", *(unsigned __int8*)(a1 + 103), *(unsigned __int8*)(a1 + 104));
		nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16397, (int)WideCharStr, 4);
		v6 = sub_43BCB0(*(_WORD*)(a1 + 163));
		if (*(_BYTE*)(a1 + 164) & 0x10) {
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 814772), L"%s %d", v6, *(unsigned __int16*)(a1 + 165));
			nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16397, (int)getMemAt(0x5D4594, 814772), 4);
		} else {
			nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16397, (int)v6, 4);
		}
		v7 = *(_DWORD*)(a1 + 96);
		if (v7 == 9999)
			nox_swprintf(WideCharStr, L"--");
		else
			_itow(v7, WideCharStr, 10);
		nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16397, (int)WideCharStr, 4);
		v8 = *(_BYTE*)(a1 + 100);
		WideCharStr[0] = 0;
		if (v8 & 0x20) {
			v9 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91248), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									   3486);
			nox_wcscat(WideCharStr, v9);
		}
		if (*(_BYTE*)(a1 + 100) & 0x10) {
			if (WideCharStr[0])
				nox_wcscat(WideCharStr, L"+");
			v10 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91316), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
										3494);
			nox_wcscat(WideCharStr, v10);
		}
		if (!WideCharStr[0]) {
			if (*(_BYTE*)(a1 + 103) < *(_BYTE*)(a1 + 104))
				v11 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91424), 0,
											"C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3505);
			else
				v11 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91376), 0,
											"C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3501);
			nox_wcscat(WideCharStr, v11);
		}
		result = (_DWORD*)nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16397, (int)WideCharStr, 4);
	} else {
		memset(v14, 0, sizeof(v14));
		*(_DWORD*)&v14[8] = 257;
		*(_DWORD*)&v14[16] = dword_5d4594_814980;
		if (*(int*)&dword_587000_87412 == -1) {
			v1 = sub_437860(*(__int16*)(a1 + 44), *(__int16*)(a1 + 46));
			v2 = *getMemU16Ptr(0x587000, 8 * v1 + 87528);
			v1 += 10054;
			*(_WORD*)(a1 + 44) -= v2;
			*(_WORD*)(a1 + 46) -= *getMemU16Ptr(0x587000, 8 * v1 + 7098);
			*(_WORD*)(a1 + 44) >>= 1;
			*(_WORD*)(a1 + 46) >>= 1;
			v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_814988, v1);
			v4 = nox_xxx_wndCreateButtonOrChekBox_4A91A0((int)v3, 1185, *(__int16*)(a1 + 44) - 5, *(__int16*)(a1 + 46) - 5, 10, 10, v14);
		} else {
			*(_WORD*)(a1 + 44) -= *getMemU16Ptr(0x587000, 8 * dword_587000_87412 + 87528);
			*(_WORD*)(a1 + 46) -= *getMemU16Ptr(0x587000, 8 * dword_587000_87412 + 87530);
			v4 = nox_xxx_wndCreateButtonOrChekBox_4A91A0(*(int*)&dword_5d4594_814984, 1192, *(__int16*)(a1 + 44) - 10, *(__int16*)(a1 + 46) - 10, 20,
							20, v14);
		}
		*(_DWORD*)(a1 + 28) = v4;
		sub_437320(a1);
		if (*(_BYTE*)(a1 + 120)) {
			strncpy(v13, (const char*)(a1 + 120), 0xFu);
			v13[15] = 0;
		} else {
			sub_43BC80(a1 + 12, *(_WORD*)(a1 + 109), v13);
		}
		if (*(_DWORD*)(a1 + 96) == 9999)
			nox_swprintf(WideCharStr, L"%S -- ms", v13);
		else
			nox_swprintf(WideCharStr, L"%S %dms", v13, *(_DWORD*)(a1 + 96));
		nox_xxx_wndWddSetTooltip_46B000((wchar_t*)(*(_DWORD*)(a1 + 28) + 36), WideCharStr);
		nox_xxx_wndSetProc_46B2C0(*(_DWORD*)(a1 + 28), nox_xxx_windowMultiplayerSub_439E70);
		result = *(_DWORD**)(a1 + 28);
		*result = *(_DWORD*)(a1 + 36) + 10070;
	}
	return result;
}

//----- (0043BCB0) --------------------------------------------------------
wchar_t* __cdecl sub_43BCB0(__int16 a1) {
	if (a1 & 0x1000)
		return nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91480), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									 3534);
	if (a1 & 0x20)
		return nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91528), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									 3541);
	if (a1 & 0x400)
		return nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91572), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									 3545);
	if (a1 & 0x10)
		return nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91624), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									 3550);
	if (a1 & 0x40)
		return nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91672), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									 3555);
	if ((a1 & 0x80u) == 0)
		return nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91772), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
									 3563);
	return nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 91724), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3559);
}
