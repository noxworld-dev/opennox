#include "../../../proto.h"
extern _DWORD dword_5d4594_830272;
extern _DWORD dword_5d4594_830268;
extern _DWORD dword_5d4594_830252;
extern _DWORD dword_5d4594_830260;
extern _DWORD dword_5d4594_830256;
extern nox_wnd_xxx* nox_wnd_xxx_830244;
extern _DWORD dword_5d4594_830276;
extern _DWORD dword_5d4594_830264;
extern _DWORD dword_5d4594_830248;

//----- (0044A560) --------------------------------------------------------
int sub_44A560_wol_login() {
	int result;       // eax
	int i;            // esi
	int v2;           // esi
	_DWORD* v3;       // eax
	_DWORD* v4;       // eax
	_DWORD* v5;       // esi
	_DWORD* v6;       // ebp
	_DWORD* v7;       // ebx
	_DWORD* v8;       // edi
	char* v9;         // eax
	wchar_t* v10;     // eax
	wchar_t* v11;     // eax
	_DWORD* v12;      // esi
	int v13;          // eax
	_DWORD* v14;      // eax
	wchar_t* v15;     // [esp-10h] [ebp-ECh]
	_BYTE* v16;       // [esp+8h] [ebp-D4h]
	_BYTE* v17;       // [esp+Ch] [ebp-D0h]
	char* v18;        // [esp+10h] [ebp-CCh]
	wchar_t v19[100]; // [esp+14h] [ebp-C8h]

	nox_xxx_setGameFlags_40A4D0(4);
	sub_43AF50(1);
	sub_41E300(1);
	sub_4A1BE0(1);
	sub_4A1A40(0);
	sub_41D4C0();
	sub_41D440();
	if (dword_5d4594_830248) {
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_830248, 1);
	} else {
		sub_43BDD0(1700);
		result = nox_new_window_from_file("wolapi.wnd", sub_44AB30);
		dword_5d4594_830248 = result;
		if (!result)
			return result;
		result = nox_wnd_sub_43C5B0((_DWORD*)result, 0, 0, 0, -480, 0, 20, 0, -40);
		nox_wnd_xxx_830244 = result;
		if (!result)
			return result;
		nox_wnd_xxx_830244->field_0 = 1700;
		nox_wnd_xxx_830244->field_12 = sub_44AA40;
		nox_wnd_xxx_830244->field_14 = sub_44AA70;
		nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_830248, sub_44AAC0, 0, 0);
	}
	sub_41FCF0();
	dword_5d4594_830264 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_830248, 1708);
	nox_window_call_field_94(*(int*)&dword_5d4594_830264, 16399, 0, 0);
	for (i = 0; i < 128; ++i) {
		sub_41FB90(i, &v16, &v17);
		nox_swprintf(v19, L"%S", v16);
		if (!v19[0])
			nox_swprintf(v19, L" ");
		nox_window_call_field_94(*(int*)&dword_5d4594_830264, 16397, (int)v19, -1);
	}
	v2 = sub_41FC40();
	if (v2 == -1) {
		sub_41FC20(0);
		v2 = 0;
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_830264, 16403, v2, 0);
	sub_41FB90(v2, &v16, &v17);
	dword_5d4594_830256 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_830248, 1701);
	if (v16 && *v16) {
		nox_swprintf(v19, L"%S", v16);
		nox_window_call_field_94(*(int*)&dword_5d4594_830256, 16414, (int)v19, 0);
	}
	dword_5d4594_830260 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_830248, 1702);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_830260, sub_44AAD0);
	v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_830248, 1703);
	dword_5d4594_830252 = v3;
	if (v17 && *v17) {
		nox_swprintf(v19, L"%S", v17);
		nox_window_call_field_94(*(int*)&dword_5d4594_830260, 16414, (int)v19, 0);
		v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_830248, 1703);
		v4[9] |= 4u;
		dword_5d4594_830276 = 1;
	} else {
		v3[9] &= 0xFFFFFFFB;
		dword_5d4594_830276 = 0;
	}
	v5 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_830248, 1709);
	v6 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_830248, 1710);
	v7 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_830248, 1711);
	v8 = *(_DWORD**)(dword_5d4594_830264 + 32);
	v18 = nox_xxx_gLoadImg_42F970("UISlider");
	v9 = nox_xxx_gLoadImg_42F970("UISliderLit");
	sub_4B5700((int)v5, 0, 0, (int)v18, (int)v9, (int)v9);
	nox_xxx_wnd_46B280((int)v5, *(int*)&dword_5d4594_830264);
	nox_xxx_wnd_46B280((int)v6, *(int*)&dword_5d4594_830264);
	nox_xxx_wnd_46B280((int)v7, *(int*)&dword_5d4594_830264);
	v8[9] = v5;
	v8[7] = v6;
	v8[8] = v7;
	*(_DWORD*)(v5[100] + 8) = 16;
	*(_DWORD*)(v5[100] + 12) = 10;
	if (dword_5d4594_830272 == 1 || sub_4D3320() == 1) {
		if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
			if (dword_5d4594_830272 == 1) {
				v10 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 113496), 0,
											"C:\\NoxPost\\src\\client\\shell\\WolApi\\wollogin.c", 485);
				nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 113524), v10);
			} else {
				nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 113528));
			}
			nox_xxx_setExitMenuOrHost_43DDD0(0);
			nox_game_exit_xxx_43DE60();
			return 0;
		}
		v15 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 113628), 0,
									"C:\\NoxPost\\src\\client\\shell\\WolApi\\wollogin.c", 495);
		v11 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 113684), 0,
									"C:\\NoxPost\\src\\client\\shell\\WolApi\\wollogin.c", 495);
		nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_830248, (int)v11, (int)v15, 33, 0, 0);
		sub_44A4B0();
		dword_5d4594_830272 = 0;
	}
	if (!sub_44A4A0()) {
		nox_xxx_wndRetNULL_46A8A0();
		nox_xxx_windowDestroyChildsMB_46B500(*(int*)&dword_5d4594_830256);
	}
	dword_5d4594_830268 = 0;
	if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
		v12 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_830248, 1708);
		v13 = sub_4A7F00();
		nox_window_call_field_94(*(int*)&dword_5d4594_830248, 16400, (int)v12, v13 - 1);
		v14 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_830248, 1706);
		nox_window_call_field_94(*(int*)&dword_5d4594_830248, 16391, (int)v14, 0);
	}
	return 1;
}
