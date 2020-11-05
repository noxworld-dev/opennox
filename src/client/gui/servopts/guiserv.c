#include "guiserv.h"

#include "../../../proto.h"
#include "../../system/parsecmd.h"
#include "../gamewin/gamewin.h"
#include "playrlst.h"

extern _DWORD dword_5d4594_1046548;
extern _DWORD dword_5d4594_1046512;
extern _DWORD dword_587000_129656;
extern _DWORD dword_5d4594_1046360;
extern _DWORD dword_5d4594_1046524;
extern _DWORD dword_5d4594_1046356;
extern _DWORD dword_5d4594_1046540;
extern _DWORD dword_5d4594_1046536;
extern _DWORD dword_5d4594_1046528;
extern _DWORD dword_5d4594_1046500;
extern _DWORD dword_5d4594_1046520;
extern _DWORD dword_5d4594_1046504;
extern _DWORD dword_5d4594_1046516;
extern _DWORD dword_5d4594_1046532;
extern _DWORD dword_5d4594_1046508;
extern _DWORD dword_5d4594_1046496;
extern _DWORD dword_587000_26048;
extern _DWORD dword_5d4594_1046492;
extern int nox_win_width;
extern int nox_win_height;

//----- (00457410) --------------------------------------------------------
char* sub_457410() {
	char* result;        // eax
	unsigned __int8* v1; // esi

	result = *(char**)&dword_5d4594_1046548;
	if (!dword_5d4594_1046548) {
		result = *(char**)getMemAt(0x587000, 129664);
		if (*getMemU32Ptr(0x587000, 129664)) {
			v1 = getMemAt(0x587000, 129664);
			do {
				*((_DWORD*)v1 + 1) =
					nox_xxx_loadString_40F1D0(result, 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 212);
				result = (char*)*((_DWORD*)v1 + 3);
				v1 += 12;
			} while (result);
		}
		dword_5d4594_1046548 = 1;
	}
	return result;
}

//----- (00457500) --------------------------------------------------------
int nox_xxx_guiServerOptsLoad_457500() {
	int v1;       // esi
	_DWORD* v2;   // eax
	_DWORD* v3;   // eax
	_DWORD* v4;   // edi
	char* v5;     // ebx
	_DWORD* v6;   // esi
	_DWORD* v7;   // ebp
	_DWORD* v8;   // eax
	char* v9;     // esi
	wchar_t* v10; // esi
	wchar_t* v11; // eax
	wchar_t* v12; // eax
	_DWORD* v13;  // eax
	char* v14;    // [esp+0h] [ebp-8h]
	_DWORD* v15;  // [esp+4h] [ebp-4h]

	if (!sub_446360()) {
		if (dword_5d4594_1046492) {
			nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
			nox_xxx_guiServerOptionsTryHide_4574D0();
			return 1;
		}
		if (nox_common_gameFlags_check_40A5C0(1)) {
			sub_459D50(1);
			if (dword_587000_129656)
				sub_425760(getMemAt(0x5D4594, 1045956));
		}
		v1 = dword_587000_26048;
		if (nox_xxx_guiFontHeightMB_43F320(0) > 10)
			v1 = 2;
		dword_5d4594_1046492 = nox_new_window_from_file(*(const char**)getMemAt(0x587000, 4 * v1 + 129760), nox_xxx_guiServerOptionsProcPre_4585D0);
		sub_43FE20(100);
		nox_wnd_nox_xxx_wndDraw_46A9B0(*(_DWORD**)&dword_5d4594_1046492, nox_win_width - *(_DWORD*)(dword_5d4594_1046492 + 8) - 10,
						   0);
		nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1046492, nox_xxx_guiServerOptionsProc_458590);
		nox_xxx_wndSetDrawFn_46B340(*(int*)&dword_5d4594_1046492, nox_xxx_windowServerOptionsDrawProc_458500);
		dword_5d4594_1046512 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10101);
		dword_5d4594_1046496 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10114);
		dword_5d4594_1046500 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10183);
		dword_5d4594_1046504 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10197);
		dword_5d4594_1046508 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10199);
		dword_5d4594_1046524 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10150);
		dword_5d4594_1046516 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10134);
		dword_5d4594_1046520 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10135);
		dword_5d4594_1046536 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10153);
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10331);
		sub_46B070((int)v2, nox_xxx_options_457AA0);
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10333);
		sub_46B070((int)v3, nox_xxx_options_457B00);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046524, *(int*)&dword_5d4594_1046492);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046532, *(int*)&dword_5d4594_1046492);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046536, *(int*)&dword_5d4594_1046492);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046500, *(int*)&dword_5d4594_1046492);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046504, *(int*)&dword_5d4594_1046492);
		nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1046508, *(int*)&dword_5d4594_1046492);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046524, nox_xxx_guiServerOptionsProcPre_4585D0);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046532, nox_xxx_guiServerOptionsProcPre_4585D0);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046536, nox_xxx_guiServerOptionsProcPre_4585D0);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046500, nox_xxx_guiServerOptionsProcPre_4585D0);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046504, nox_xxx_guiServerOptionsProcPre_4585D0);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1046508, nox_xxx_guiServerOptionsProcPre_4585D0);
		*getMemU32Ptr(0x5D4594, 1046352) = nox_xxx_gLoadImg_42F970("UITabs1");
		dword_5d4594_1046356 = nox_xxx_gLoadImg_42F970("UITabs2");
		dword_5d4594_1046360 = nox_xxx_gLoadImg_42F970("UITabs3");
		v4 = *(_DWORD**)(dword_5d4594_1046496 + 32);
		v14 = nox_xxx_gLoadImg_42F970("UISlider");
		v5 = nox_xxx_gLoadImg_42F970("UISliderLit");
		v6 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046500, 10182);
		v7 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046500, 10180);
		v15 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046500, 10181);
		*(_DWORD*)(v6[100] + 8) = 16;
		*(_DWORD*)(v6[100] + 12) = 10;
		sub_4B5700((int)v6, 0, 0, (int)v14, (int)v5, (int)v5);
		nox_xxx_wnd_46B280((int)v6, *(int*)&dword_5d4594_1046496);
		nox_xxx_wnd_46B280((int)v7, *(int*)&dword_5d4594_1046496);
		nox_xxx_wnd_46B280((int)v15, *(int*)&dword_5d4594_1046496);
		v4[9] = v6;
		v4[7] = v7;
		v4[8] = v15;
		v8 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10160);
		v8[9] |= 4u;
		v9 = sub_4165D0(0);
		if (nox_common_gameFlags_check_40A5C0(1))
			sub_4161E0();
		sub_457410();
		sub_457B60((int)v9);
		sub_457A10();
		if (nox_common_gameFlags_check_40A5C0(1)) {
			sub_4165F0(0, 1);
			sub_4165D0(1);
		} else {
			v10 = (wchar_t*)nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10159);
			v11 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 130156), 0,
										"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1811);
			nox_window_call_field_94((int)v10, 16385, (int)v11, -1);
			v12 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 130224), 0,
										"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1812);
			nox_xxx_wndWddSetTooltip_46B000(v10 + 18, v12);
			v13 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10149);
			nox_window_set_hidden((int)v13, 0);
			nox_window_set_hidden(*(int*)&dword_5d4594_1046508, 1);
			sub_46ACE0(*(_DWORD**)&dword_5d4594_1046492, 10145, 10146, 1);
		}
		if (dword_587000_129656) {
			if (sub_4D6F30() || sub_4D6F50()) {
				nox_server_parseCmdText_443C80((wchar_t*)getMemAt(0x587000, 130244), 1);
			} else if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				nox_server_parseCmdText_443C80((wchar_t*)getMemAt(0x587000, 130284), 1);
			}
		}
		dword_587000_129656 = 0;
	}
	return 1;
}

//----- (00457AA0) --------------------------------------------------------
int __cdecl nox_xxx_options_457AA0(int a1, _BYTE* a2) {
	wchar_t* v2; // eax

	if (*a2 & 4)
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 130372), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   446);
	else
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 130436), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   450);
	nox_xxx_cursorSetTooltip_4776B0(v2);
	return 1;
}

//----- (00457B00) --------------------------------------------------------
int __cdecl nox_xxx_options_457B00(int a1, _BYTE* a2) {
	wchar_t* v2; // eax

	if (*a2 & 4)
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 130500), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   465);
	else
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 130564), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   469);
	nox_xxx_cursorSetTooltip_4776B0(v2);
	return 1;
}

//----- (00457FE0) --------------------------------------------------------
int sub_457FE0() {
	_DWORD* v0;  // esi
	wchar_t* v1; // eax
	wchar_t* v2; // eax
	wchar_t* v3; // eax
	wchar_t* v5; // [esp-4h] [ebp-8h]
	wchar_t* v6; // [esp-4h] [ebp-8h]

	v0 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10210);
	if (nox_common_gameFlags_check_40A5C0(0x4000)) {
		v5 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 130636), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   380);
		v1 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 130708), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   379);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1045700), L"%s %s", v1, v5);
	} else if (nox_common_gameFlags_check_40A5C0(0x8000)) {
		v6 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 130788), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   385);
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 130856), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   384);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1045700), L"%s %s", v2, v6);
	} else {
		v3 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 130936), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   389);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1045700), v3);
	}
	return nox_window_call_field_94((int)v0, 16385, (int)getMemAt(0x5D4594, 1045700), -1);
}

//----- (004580E0) --------------------------------------------------------
int __cdecl sub_4580E0(int a1) {
	wchar_t* v1; // eax
	wchar_t* v2; // eax
	__int16 v3;  // ax
	wchar_t* v4; // eax
	wchar_t* v5; // eax
	_DWORD* v6;  // eax
	_DWORD* v7;  // eax
	_DWORD* v8;  // eax
	int v10;     // [esp-4h] [ebp-4h]

	v1 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131000), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
							   736);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1045968), v1, a1);
	if (nox_common_gameFlags_check_40A5C0(128)) {
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131060), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   739);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1046096), v2);
	} else {
		v3 = nox_common_gameFlags_getVal_40A5B0();
		v10 = nox_xxx_guiServerOptionsGetGametypeName_4573C0(v3);
		v4 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131120), 0, (const char*)getMemAt(0x587000, 0x20000), 743);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1046096), v4, v10);
	}
	if (nox_common_gameFlags_check_40A5C0(1))
		v5 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131180), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   748);
	else
		v5 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131240), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   752);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1046224), v5);
	v6 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10121);
	nox_window_call_field_94((int)v6, 16385, (int)getMemAt(0x5D4594, 1045968), -1);
	v7 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10118);
	nox_window_call_field_94((int)v7, 16385, (int)getMemAt(0x5D4594, 1046096), -1);
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10117);
	return nox_window_call_field_94((int)v8, 16385, (int)getMemAt(0x5D4594, 1046224), -1);
}

//----- (00458230) --------------------------------------------------------
int __cdecl sub_458230(int a1, char* a2, int a3) {
	int v3;           // ebp
	int* v4;          // ebx
	int v5;           // eax
	int v6;           // esi
	int i;            // eax
	int j;            // eax
	wchar_t* v9;      // eax
	int result;       // eax
	char* v11;        // ebx
	int v12;          // eax
	int v13;          // eax
	char* v14;        // eax
	int v15;          // [esp-8h] [ebp-160h]
	int v16;          // [esp-4h] [ebp-15Ch]
	int v17;          // [esp+10h] [ebp-148h]
	int v18;          // [esp+14h] [ebp-144h]
	char v19[58];     // [esp+18h] [ebp-140h]
	char v20[58];     // [esp+54h] [ebp-104h]
	wchar_t v21[100]; // [esp+90h] [ebp-C8h]

	nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16399, 0, 0);
	v3 = a1;
	v18 = -1;
	*getMemU32Ptr(0x5D4594, 1046552) = a1;
	v4 = nox_xxx_validateMapList_4D09B0();
	v17 = 0;
	if (!v4)
		goto LABEL_30;
	do {
		if (v4[6]) {
			v5 = sub_4CFFC0((int)v4);
			if (v5 & v3) {
				strcpy(v19, (const char*)v4 + 12);
				memcpy(v20, v19, 0x38u);
				*(_WORD*)&v20[56] = *(_WORD*)&v19[56];
				sub_57A1E0((int*)v19, 0, 0, 1, a1);
				sub_57A1E0((int*)v20, "user.rul", 0, 3, a1);
				v6 = -1;
				for (i = 0; i < 20; i += 4) {
					if (*(_DWORD*)&v19[i + 24] != *(_DWORD*)&v20[i + 24])
						v6 = 6;
				}
				if (v6 == -1) {
					for (j = 0; j < 4; ++j) {
						if (v19[j + 44] != v20[j + 44])
							v6 = 6;
					}
					if (v6 == -1 && *(_DWORD*)&v19[48] != *(_DWORD*)&v20[48])
						v6 = 6;
				}
				v16 = *((unsigned __int8*)v4 + 33);
				v15 = *((unsigned __int8*)v4 + 32);
				v9 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131312), 0,
										   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 823);
				nox_swprintf(v21, v9, v4 + 3, v15, v16);
				nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16397, (int)v21, v6);
				if (!_strcmpi(a2, (const char*)v4 + 12)) {
					v18 = v17;
					nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16403, v17, 0);
					nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16412, v17, 0);
				}
				v3 = a1;
				++v17;
			}
		}
		v4 = sub_4D09C0(v4);
	} while (v4);
	if (v18 < 0) {
	LABEL_30:
		nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16403, 0, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16412, 0, 0);
	}
	result = a3;
	if (a3) {
		v11 = sub_4165B0();
		v12 = nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16404, 0, 0);
		if (v12 >= 0 && (v13 = nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16406, v12, 0),
						 nox_sprintf((char*)v21, "%S", v13), (v14 = strtok((char*)v21, "\t")) != 0)) {
			strcpy(v11, v14);
		} else {
			*v11 = 0;
		}
		sub_57A1E0((int*)v11, "user.rul", 0, 7, v3);
		result = sub_459880((int)v11);
	}
	return result;
}
//----- (004585D0) --------------------------------------------------------
int __cdecl nox_xxx_guiServerOptionsProcPre_4585D0(int a1, unsigned int a2, int a3, int a4) {
	_DWORD* v4;           // esi
	char* v5;             // ebp
	int result;           // eax
	int v7;               // eax
	int v8;               // ebx
	int v9;               // edi
	int* v10;             // eax
	int v11;              // edi
	_DWORD* v12;          // esi
	_DWORD* v13;          // eax
	_DWORD* v14;          // eax
	_DWORD* v15;          // eax
	int v16;              // edi
	_DWORD* v17;          // eax
	char* v18;            // esi
	int v19;              // edi
	__int16 v20;          // ax
	bool v21;             // cc
	wchar_t* v22;         // eax
	wchar_t* v23;         // eax
	wchar_t* v24;         // eax
	char* v25;            // esi
	_DWORD* v26;          // esi
	int v27;              // edi
	int v28;              // eax
	char* v29;            // esi
	_DWORD* v30;          // edi
	int v31;              // eax
	wchar_t* v32;         // ebp
	int v33;              // edi
	unsigned int v34;     // ecx
	int v35;              // eax
	char* v36;            // edi
	char* v37;            // ebx
	wchar_t* v38;         // [esp-10h] [ebp-F0h]
	wchar_t* v39;         // [esp-10h] [ebp-F0h]
	WCHAR WideCharStr[4]; // [esp+10h] [ebp-D0h]
	char v41[100];        // [esp+18h] [ebp-C8h]
	char v42[100];        // [esp+7Ch] [ebp-64h]

	if (a2 > 0x4007) {
		if (a2 == 16400) {
			v28 = nox_xxx_wndGetID_46B0A0((int*)a3) - 10114;
			if (v28) {
				if (v28 == 6) {
					v29 = sub_4165B0();
					v30 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10119);
					v31 = nox_window_call_field_94(a3, 16404, 0, 0);
					if (v31 >= 0 && v31 < *(__int16*)(*(_DWORD*)(a3 + 32) + 44)) {
						v32 = (wchar_t*)nox_window_call_field_94(a3, 16406, a4, 0);
						nox_window_call_field_94((int)v30, 16385, (int)v32, -1);
						v33 = *((_WORD*)v29 + 26) & 0x17F0;
						*((_WORD*)v29 + 26) &= 0xE80Fu;
						*((_WORD*)v29 + 26) |= sub_459650(v32);
						if (v33 != (*((_WORD*)v29 + 26) & 0x17F0))
							sub_458230(*((unsigned __int16*)v29 + 26), (char*)getMemAt(0x5D4594, 1046556), 1);
						nox_window_set_hidden(a3, 1);
						nox_xxx_wndClearCaptureMain_46ADE0(a3);
						*((_WORD*)v29 + 27) = nox_xxx_servGamedataGet_40A020(*((_WORD*)v29 + 26));
						v29[56] = sub_40A180(*((_WORD*)v29 + 26));
						sub_457460((int)v29);
						sub_459D50(1);
						if (v29[53] & 0x10) {
							sub_424BD0();
							sub_4537F0();
							sub_459700();
						}
						LOWORD(v34) = *((_WORD*)v29 + 26);
						sub_457F30((v34 >> 12) & 1);
						return 1;
					}
				}
			} else if (nox_window_call_field_94(a3, 16404, 0, 0) >= 0) {
				v35 = nox_window_call_field_94(a3, 16406, a4, 0);
				nox_sprintf(v42, "%S", v35);
				v36 = strtok(v42, "\t");
				v37 = sub_4165B0();
				strcpy(v37, v36);
				sub_57A1E0((int*)v37, "user.rul", 0, 7, *((_WORD*)v37 + 26));
				sub_459880((int)v37);
				sub_459D50(1);
			}
		}
		return 1;
	}
	if (a2 == 16391) {
		v9 = nox_xxx_wndGetID_46B0A0((int*)a3);
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
		switch (v9) {
		case 10119:
			v26 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10120);
			nox_window_set_hidden((int)v26, 0);
			nox_xxx_wndSetCaptureMain_46ADC0((int)v26);
			nox_xxx_wndShowModalMB_46A8C0((int)v26);
			nox_xxx_windowServerOptionsFillGametypeList_4596A0();
			return 1;
		case 10122:
			v27 = (*(_BYTE*)(a3 + 36) & 4) != 0;
			if (!nox_common_gameFlags_check_40A5C0(49152)) {
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046500, v27);
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046504, v27);
			}
			sub_459D50(1);
			return 1;
		case 10141:
			sub_459700();
			return 1;
		case 10145:
			v18 = nox_xxx_cliGamedataGet_416590(1);
			sub_459AA0((int)v18);
			sub_4165F0(1, 0);
			v19 = nox_xxx_getTeamCounter_417DD0();
			if (nox_common_gameFlags_check_40A5C0(128) && (v20 = *((_WORD*)v18 + 26), v20 & 0x60)) {
				if (v20 < 0) {
					v21 = v19 <= 2;
				} else {
					v21 = v19 <= 2;
					if (v19 < 2) {
						v22 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131412), 0,
													"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1363);
						nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_1046492, (int)getMemAt(0x5D4594, 1046560), (int)v22, 56, sub_459150,
								   0);
						sub_44A360(1);
						return 1;
					}
				}
				if (!v21) {
					v38 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131472), 0,
												"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1371);
					v23 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131536), 0,
												"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1370);
					nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_1046492, (int)v23, (int)v38, 33, 0, 0);
					sub_44A360(1);
					return 1;
				}
			} else if (nox_common_gameFlags_check_40A5C0(128) && nox_common_gameFlags_check_40A5C0(16) &&
					   nox_xxx_CheckGameplayFlags_417DA0(4) && v19 > 2) {
				v39 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131592), 0,
											"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1384);
				v24 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131656), 0,
											"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1383);
				nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_1046492, (int)v24, (int)v39, 33, 0, 0);
				sub_44A360(1);
				return 1;
			}
			sub_459150();
			OnLibraryNotice(261, 0);
			result = 1;
			break;
		case 10146:
			v25 = sub_4165B0();
			if (nox_common_gameFlags_check_40A5C0(128)) {
				if ((int)v25[53] < 0)
					sub_419030(1);
				*((_WORD*)v25 + 26) &= 0x3FFFu;
			}
			goto LABEL_58;
		case 10149:
		LABEL_58:
			nox_xxx_guiServerOptionsHide_4597E0(0);
			return 1;
		case 10152:
			v10 = (int*)nox_xxx_cliGamedataGet_416590(1);
			nox_xxx_loadAdvancedWnd_4BDC10(v10);
			return 1;
		case 10159:
			v11 = *(_DWORD*)(a3 + 396);
			sub_46B120((_DWORD*)a3, 0);
			sub_46B120((_DWORD*)a3, v11);
			v12 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10196);
			if (nox_common_gameFlags_check_40A5C0(1)) {
				nox_window_set_hidden((int)v12, 0);
				sub_46ACE0(*(_DWORD**)&dword_5d4594_1046492, 10161, 10163, 0);
				sub_46AD20(*(_DWORD**)&dword_5d4594_1046492, 10161, 10163, 1);
				sub_4593B0(0);
				v13 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10163);
				v13[9] |= 4u;
				v14 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10161);
				v14[9] &= 0xFFFFFFFB;
				v15 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10162);
				v15[9] &= 0xFFFFFFFB;
				sub_46ACE0(*(_DWORD**)&dword_5d4594_1046492, 10141, 10141, 1);
			} else {
				nox_window_set_hidden((int)v12, 1);
				dword_5d4594_1046532 = nox_xxx_guiServerPlayersLoad_456270(*(int*)&dword_5d4594_1046492);
				sub_46ACE0(*(_DWORD**)&dword_5d4594_1046492, 10141, 10141, 1);
			}
			nox_window_set_hidden(*(int*)&dword_5d4594_1046524, 1);
			return 1;
		case 10160:
			v16 = *(_DWORD*)(a3 + 396);
			sub_46B120((_DWORD*)a3, 0);
			sub_46B120((_DWORD*)a3, v16);
			if (dword_5d4594_1046532) {
				sub_456D60(1);
				dword_5d4594_1046532 = 0;
			}
			if (dword_5d4594_1046528) {
				sub_4557D0(1);
				dword_5d4594_1046528 = 0;
			}
			if (dword_5d4594_1046536) {
				sub_4AD820();
				dword_5d4594_1046540 = 0;
			}
			sub_46ACE0(*(_DWORD**)&dword_5d4594_1046492, 10161, 10163, 1);
			if (nox_common_gameFlags_check_40A5C0(1))
				sub_46ACE0(*(_DWORD**)&dword_5d4594_1046492, 10141, 10141, 0);
			v17 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10196);
			nox_window_set_hidden((int)v17, 1);
			nox_window_set_hidden(*(int*)&dword_5d4594_1046524, 0);
			return 1;
		case 10161:
			sub_4593B0(1);
			return 1;
		case 10162:
			sub_4593B0(2);
			return 1;
		case 10163:
			sub_4593B0(0);
			return 1;
		case 10330:
			if (nox_xxx_CheckGameplayFlags_417DA0(4)) {
				nox_xxx_toggleAllTeamFlags_418690(0);
				sub_419030(1);
				sub_46AD20(*(_DWORD**)&dword_5d4594_1046508, 10331, 10333, 0);
				result = 1;
			} else {
				nox_xxx_wndGuiTeamCreate_4185B0();
				if (nox_xxx_CheckGameplayFlags_417DA0(2))
					sub_4181F0(0);
				else
					nox_xxx_toggleAllTeamFlags_418690(1);
				sub_46AD20(*(_DWORD**)&dword_5d4594_1046508, 10331, 10333, 1);
				result = 1;
			}
			return result;
		case 10331:
			if (nox_xxx_CheckGameplayFlags_417DA0(2)) {
				nox_xxx_UnsetGameplayFlags_417D70(2);
				nox_xxx_toggleAllTeamFlags_418690(1);
			} else {
				nox_xxx_toggleAllTeamFlags_418690(0);
				sub_418390();
			}
			return 1;
		case 10332:
			sub_4181F0(1);
			return 1;
		case 10333:
			if (nox_xxx_CheckGameplayFlags_417DA0(1))
				nox_xxx_UnsetGameplayFlags_417D70(1);
			else
				nox_xxx_SetGameplayFlag_417D50(1);
			return 1;
		default:
			return 1;
		}
		return result;
	}
	if (a2 == 23)
		return 0;
	if (a2 != 16387)
		return 1;
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, a4);
	sub_416630();
	v5 = sub_4165B0();
	if (!v4)
		return 0;
	if ((unsigned __int16)a3 == 1) {
		if (a4 == 10101) {
			v4[26] = *getMemU32Ptr(0x5D4594, 2523948);
			return 1;
		}
		return 1;
	}
	v7 = nox_window_call_field_94((int)v4, 16413, 0, 0);
	nox_sprintf(v41, "%S", v7);
	if (!v41[0]) // TODO: was if (!v41 || ...
		return 1;
	v8 = atoi(v41);
	if (v8 < 0)
		v8 = 0;
	if (a4 == 10101) {
		v4[26] = nox_color_rgb_4344A0(230, 165, 65);
		strcpy(v5 + 9, v41);
		nox_xxx_gameSetServername_40A440(v41);
		return 1;
	}
	if (a4 == 10134) {
		*((_WORD*)v5 + 27) = v8;
		sub_459D50(1);
		return 1;
	}
	if (a4 != 10135)
		return 1;
	if (v8 > 255) {
		LOBYTE(v8) = -1;
		_itow(255, WideCharStr, 10);
		nox_window_call_field_94((int)v4, 16414, (int)WideCharStr, -1);
	}
	v5[56] = v8;
	sub_459D50(1);
	return 1;
}
//----- (00459880) --------------------------------------------------------
int __cdecl sub_459880(int a1) {
	__int16 v1;      // ax
	wchar_t* v2;     // eax
	_DWORD* v4;      // eax
	int v5;          // ecx
	unsigned int v6; // ecx

	sub_416630();
	v1 = *(_WORD*)(a1 + 52);
	if (v1 & 0x20) {
		if (!*(_BYTE*)(a1 + 57) && nox_common_gameFlags_check_40A5C0(1)) {
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046516, 1);
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046520, 1);
		}
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131772), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   1900);
	} else {
		LOBYTE(v1) = *(_BYTE*)(a1 + 57);
		if (v1 & 0x400) {
			if (!LOBYTE(v1) && nox_common_gameFlags_check_40A5C0(1)) {
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046516, 1);
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046520, 1);
			}
			v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131848), 0,
									   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1912);
		} else {
			if (!LOBYTE(v1) && nox_common_gameFlags_check_40A5C0(1) && !nox_common_gameFlags_check_40A5C0(49152)) {
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046516, 1);
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046520, 1);
			}
			v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 131920), 0,
									   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1926);
		}
	}
	nox_wcscpy((wchar_t*)(dword_5d4594_1046516 + 108), v2);
	sub_4580E0(a1);
	sub_459A40((char*)(a1 + 9));
	if (nox_common_gameFlags_check_40A5C0(1) && !nox_common_gameFlags_check_40A5C0(49152)) {
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046500, *(_BYTE*)(a1 + 57) == 0);
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1046504, *(_BYTE*)(a1 + 57) == 0);
	}
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10122);
	v5 = v4[9];
	if (*(_BYTE*)(a1 + 57))
		v6 = v5 | 4;
	else
		v6 = v5 & 0xFFFFFFFB;
	v4[9] = v6;
	sub_453F70((const void*)(a1 + 24));
	sub_4535E0((int*)(a1 + 44));
	return sub_4535F0(*(_DWORD*)(a1 + 48));
}

//----- (00459CD0) --------------------------------------------------------
int sub_459CD0() {
	int result;         // eax
	unsigned __int8 v1; // al
	wchar_t* v2;        // eax
	_DWORD* v3;         // eax
	int v4;             // [esp-4h] [ebp-4h]

	result = dword_5d4594_1046492;
	if (dword_5d4594_1046492) {
		if (sub_40A740() || nox_common_gameFlags_check_40A5C0(0x8000))
			v1 = sub_417DE0();
		else
			v1 = nox_xxx_getTeamCounter_417DD0();
		v4 = v1;
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 132012), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c",
								   2071);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1046364), v2, v4);
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10110);
		result = nox_window_call_field_94((int)v3, 16385, (int)getMemAt(0x5D4594, 1046364), -1);
	}
	return result;
}
