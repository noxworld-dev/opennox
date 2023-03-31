#include "client__gui__servopts__playrlst.h"
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
#include "common__system__team.h"
extern uint32_t dword_5d4594_1045692;
extern uint32_t dword_5d4594_1045688;
extern uint32_t dword_5d4594_1045684;

//----- (00456270) --------------------------------------------------------
int nox_xxx_guiServerPlayersLoad_456270(int a1) {
	int v1;        // esi
	uint32_t* v3;  // edi
	uint32_t* v4;  // ebx
	char* v5;      // ebp
	uint32_t* v6;  // esi
	uint32_t* v7;  // edi
	uint32_t* v8;  // esi
	uint32_t* v9;  // esi
	wchar2_t* v10;  // eax
	uint32_t* v11; // [esp+4h] [ebp-Ch]
	uint32_t* v12; // [esp+4h] [ebp-Ch]
	char* v13;     // [esp+8h] [ebp-8h]
	uint32_t* v14; // [esp+Ch] [ebp-4h]
	uint32_t* v15; // [esp+14h] [ebp+4h]
	uint32_t* v16; // [esp+14h] [ebp+4h]

	v1 = nox_strman_get_lang_code();
	if (nox_xxx_guiFontHeightMB_43F320(0) > 10) {
		v1 = 2;
	}
	if (dword_5d4594_1045684) {
		return 0;
	}
	dword_5d4594_1045684 = nox_new_window_from_file(*(const char**)getMemAt(0x587000, 129048 + 4 * v1), sub_4567C0);
	dword_5d4594_1045688 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10507);
	dword_5d4594_1045692 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10509);
	sub_46B120(*(uint32_t**)&dword_5d4594_1045684, a1);
	nox_xxx_wndSetDrawFn_46B340(*(int*)&dword_5d4594_1045684, sub_456640);
	nox_xxx_wndRetNULL_46A8A0();
	nox_common_list_clear_425760(getMemAt(0x5D4594, 1045652));
	nox_common_list_clear_425760(getMemAt(0x5D4594, 1045668));
	v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10501);
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10502);
	v14 = (uint32_t*)v3[8];
	v13 = nox_xxx_gLoadImg_42F970("UISlider");
	v5 = nox_xxx_gLoadImg_42F970("UISliderLit");
	v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10517);
	v15 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10515);
	v11 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10516);
	*(uint32_t*)(v6[100] + 8) = 16;
	*(uint32_t*)(v6[100] + 12) = 10;
	sub_4B5700((int)v6, 0, 0, (int)v13, (int)v5, (int)v5);
	nox_xxx_wnd_46B280((int)v6, (int)v3);
	nox_xxx_wnd_46B280((int)v15, (int)v3);
	nox_xxx_wnd_46B280((int)v11, (int)v3);
	v14[9] = v6;
	v14[7] = v15;
	v14[8] = v11;
	v7 = (uint32_t*)v4[8];
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10520);
	v16 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10518);
	v12 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10519);
	*(uint32_t*)(v8[100] + 8) = 16;
	*(uint32_t*)(v8[100] + 12) = 10;
	sub_4B5700((int)v8, 0, 0, (int)v13, (int)v5, (int)v5);
	nox_xxx_wnd_46B280((int)v8, (int)v4);
	nox_xxx_wnd_46B280((int)v16, (int)v4);
	nox_xxx_wnd_46B280((int)v12, (int)v4);
	v7[9] = v8;
	v7[7] = v16;
	v7[8] = v12;
	sub_456500();
	v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10504);
	if (nox_common_gameFlags_check_40A5C0(128)) {
		v10 = nox_strman_loadString_40F1D0("Title1", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 631);
		nox_window_call_field_94((int)v9, 16385, (int)v10, -1);
	}
	return dword_5d4594_1045684;
}

//----- (004567C0) --------------------------------------------------------
int sub_4567C0(int a1, int a2, int* a3, int a4) {
	char* v3;        // esi
	int v4;          // esi
	uint32_t* v5;    // eax
	int v6;          // eax
	uint32_t* v7;    // eax
	int v8;          // ebx
	int* v9;         // eax
	int* v10;        // ebp
	int i;           // eax
	wchar2_t* v12;    // eax
	char* v13;       // eax
	char* v14;       // esi
	uint32_t* v15;   // eax
	int v16;         // edi
	uint32_t* v17;   // eax
	uint32_t* v18;   // eax
	uint32_t* v20;   // eax
	int v21;         // eax
	char* v22;       // esi
	wchar2_t* v23;    // edi
	uint32_t* v24;   // eax
	int v25;         // eax
	char* v26;       // eax
	wchar2_t* v27;    // eax
	wchar2_t* v28;    // [esp-10h] [ebp-8Ch]
	char* v29;       // [esp+8h] [ebp-74h]
	wchar2_t v30[56]; // [esp+Ch] [ebp-70h]

	if (a2 != 16391) {
		if (a2 != 16400) {
			return 0;
		}
		if (nox_xxx_wndGetID_46B0A0(a3) == 10502) {
			v3 = sub_4165B0();
			if (nox_window_call_field_94((int)a3, 16404, 0, 0) < 0) {
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045688, 0);
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045692, 0);
			} else if (nox_common_gameFlags_check_40A5C0(0x8000) || v3[53] < 0) {
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045688, 0);
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045692, 0);
			} else {
				if (nox_common_gameFlags_check_40A5C0(1)) {
					nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045692, 1);
				}
				if (nox_common_gameFlags_check_40A5C0(128) || !*getMemU32Ptr(0x5D4594, 1045696)) {
					nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045688, 1);
				} else {
					nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045688, 0);
				}
			}
			if (nox_common_gameFlags_check_40A5C0(1) &&
				nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045688, 0);
			}
		}
	}
	v4 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	if (v4 > 10507) {
		if (v4 == 10509) {
			v28 =
				nox_strman_loadString_40F1D0("NewName", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 504);
			v27 = nox_strman_loadString_40F1D0("Rename", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 504);
			nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_1045684, (int)v27, (int)v28, 163, 0, 0);
		}
		return 0;
	}
	if (v4 == 10507) {
		v24 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10502);
		v25 = nox_window_call_field_94((int)v24, 16404, 0, 0);
		sub_456D00(v25, v30);
		v26 = sub_418A40(v30);
		if (v26) {
			sub_456BB0((int)v26);
			return 0;
		}
		return 0;
	}
	if (v4 == 4001) {
		v20 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10502);
		v21 = nox_window_call_field_94((int)v20, 16404, 0, 0);
		sub_456D00(v21, v30);
		v22 = sub_418A40(v30);
		if (v22) {
			v23 = (wchar2_t*)sub_449E60(168);
			if (!sub_4190F0(v23)) {
				nox_xxx_teamRenameMB_418CD0((wchar2_t*)v22, v23);
				return 0;
			}
		}
		return 0;
	}
	if (v4 != 10503) {
		return 0;
	}
	v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10502);
	v6 = nox_window_call_field_94((int)v5, 16404, 0, 0);
	if (v6 >= 0) {
		sub_456D00(v6, v30);
		v29 = sub_418A40(v30);
		if (v29) {
			v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10501);
			v8 = (int)v7;
			v9 = (int*)nox_window_call_field_94((int)v7, 16404, 0, 0);
			v10 = v9;
			for (i = *v9; i >= 0; ++v10) {
				v12 = (wchar2_t*)nox_window_call_field_94(v8, 16406, i, 0);
				v13 = nox_xxx_playerByName_4170D0(v12);
				v14 = v13;
				if (v13) {
					if (!(v13[3680] & 1) && !(v13[4] & 1)) {
						v15 = nox_xxx_objGetTeamByNetCode_418C80(*((uint32_t*)v13 + 515));
						v16 = (int)v15;
						if (v15) {
							if (nox_xxx_servObjectHasTeam_419130((int)v15)) {
								sub_4196D0(v16, (int)v29, *((uint32_t*)v14 + 515), 1);
							} else {
								nox_xxx_createAtImpl_4191D0(v29[57], v16, 1, *((uint32_t*)v14 + 515), 1);
							}
						}
					}
				}
				i = v10[1];
			}
		}
	}
	v17 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10502);
	nox_window_call_field_94((int)v17, 16403, -1, 0);
	v18 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10501);
	nox_window_call_field_94((int)v18, 16403, -1, 0);
	return 0;
}

//----- (00457010) --------------------------------------------------------
int sub_457010(int a1, wchar2_t* a2) {
	char* v2;         // ebp
	int result;       // eax
	uint32_t* v4;     // esi
	int v5;           // edi
	unsigned char v6; // al
	unsigned char v7; // al
	wchar2_t* v8;      // [esp-20h] [ebp-94h]
	wchar2_t v9[56];   // [esp+4h] [ebp-70h]

	v2 = sub_4165B0();
	result = dword_5d4594_1045684;
	if (dword_5d4594_1045684) {
		v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10502);
		v5 = nox_window_call_field_94((int)v4, 16404, 0, 0);
		nox_wcscpy(v9, a2);
		if (nox_common_gameFlags_check_40A5C0(96) || v2[52] & 0x60) {
			v6 = *(uint8_t*)(a1 + 57);
			if (v6 < 3u) {
				if (v6 == 1) {
					v8 = nox_strman_loadString_40F1D0("RedFlag", 0,
													  "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 778);
				} else {
					v8 = nox_strman_loadString_40F1D0("BlueFlag", 0,
													  "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 782);
				}
				nox_wcscat(v9, v8);
			}
		}
		nox_window_call_field_94((int)v4, 16398, v5, 0);
		nox_window_call_field_94((int)v4, 16402, v5, 0);
		v7 = sub_457120(a1);
		nox_window_call_field_94((int)v4, 16397, (int)v9, v7);
		result = nox_window_call_field_94((int)v4, 16403, v5, 0);
	}
	return result;
}

//----- (00457230) --------------------------------------------------------
char* sub_457230(wchar2_t* a1) {
	char* v1;       // ebp
	char* result;   // eax
	uint32_t* v3;   // esi
	char* v4;       // edi
	char v5;        // al
	uint32_t* v6;   // eax
	wchar2_t* v7;    // [esp-14h] [ebp-94h]
	wchar2_t v8[56]; // [esp+10h] [ebp-70h]

	v1 = sub_4165B0();
	result = *(char**)&dword_5d4594_1045684;
	if (dword_5d4594_1045684) {
		v3 = calloc(1, 0x48u);
		result = sub_418A40(a1);
		v4 = result;
		if (result) {
			v3[15] = (unsigned char)result[57];
			v3[17] = (unsigned char)result[56];
			*((uint8_t*)v3 + 64) = sub_457120((int)result);
			sub_425770(v3);
			nox_common_list_append_4258E0((int)getMemAt(0x5D4594, 1045668), v3);
			nox_wcscpy((wchar2_t*)v3 + 6, a1);
			nox_wcscpy(v8, a1);
			if (nox_common_gameFlags_check_40A5C0(96) || v1[52] & 0x60) {
				v5 = v4[57];
				if ((unsigned char)v5 < 3u) {
					if (v5 == 1) {
						v7 = nox_strman_loadString_40F1D0("RedFlag", 0,
														  "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 893);
					} else {
						v7 = nox_strman_loadString_40F1D0("BlueFlag", 0,
														  "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 897);
					}
					nox_wcscat(v8, v7);
				}
			}
			v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045684, 10502);
			result = (char*)nox_window_call_field_94((int)v6, 16397, (int)v8, *((unsigned char*)v3 + 64));
		}
	}
	return result;
}
