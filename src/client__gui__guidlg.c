#include "client__gui__guidlg.h"
#include "client__gui__window.h"
#include "common__strman.h"

#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"

extern uint32_t dword_5d4594_1123520;
extern uint32_t dword_5d4594_1123524;
extern uint32_t nox_client_renderGUI_80828;
extern int nox_win_width;
extern int nox_win_height;

//----- (00479D30) --------------------------------------------------------
int sub_479D30(wchar_t* a1, int a2, char* a3, const char* a4, char a5) {
	uint32_t* v5;  // esi
	uint32_t* v6;  // edi
	uint32_t* v7;  // eax
	uint32_t* v8;  // esi
	uint32_t* v9;  // esi
	uint32_t* v10; // esi
	wchar_t* v11;  // eax
	uint32_t* v12; // esi
	uint32_t* v13; // esi
	uint32_t* v14; // esi
	wchar_t* v15;  // eax
	int result;    // eax
	char* v17;     // [esp-4h] [ebp-18h]
	int v18;       // [esp+Ch] [ebp-8h]
	int v19;       // [esp+10h] [ebp-4h]

	v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3901);
	v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3910);
	sub_445C20();
	nox_window_call_field_94((int)v5, 16399, 0, 0);
	nox_window_get_size(*(int*)&dword_5d4594_1123524, &v19, &v18);
	nox_window_setPos_46A9B0(*(uint32_t**)&dword_5d4594_1123524, nox_win_width - v19, nox_win_height - v18);
	sub_47A020(a3);
	nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1107056), a1);
	v17 = nox_xxx_gLoadImg_42F970(a4);
	v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3905);
	nox_xxx_wndSetIcon_46AE60((int)v7, (int)v17);
	nox_window_call_field_94((int)v6, 16385, (int)getMemAt(0x5D4594, 1107056), 0);
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3908);
	if (a5 & 1) {
		nox_xxx_wnd_46ABB0((int)v8, 1);
		nox_window_set_hidden((int)v8, 0);
		v8[5] = 5;
		v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3909);
		nox_xxx_wnd_46ABB0((int)v9, 1);
		nox_window_set_hidden((int)v9, 0);
		v9[5] = 35;
		v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3906);
		v11 = nox_strman_loadString_40F1D0("Dialog.wnd:Done", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIDlg.c", 460);
	} else {
		nox_xxx_wnd_46ABB0((int)v8, 0);
		nox_window_set_hidden((int)v8, 1);
		v12 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3909);
		nox_xxx_wnd_46ABB0((int)v12, 0);
		nox_window_set_hidden((int)v12, 1);
		v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3906);
		v11 = nox_strman_loadString_40F1D0("Dialog.wnd:Done", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIDlg.c", 483);
	}
	sub_46AEE0((int)v10, (int)v11);
	nox_xxx_wnd_46ABB0((int)v10, 1);
	nox_window_set_hidden((int)v10, 0);
	v10[5] = 95;
	v13 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3907);
	nox_xxx_wnd_46ABB0((int)v13, 1);
	nox_window_set_hidden((int)v13, 0);
	v13[5] = 65;
	if (a5 & 2) {
		v14 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3906);
		v15 = nox_strman_loadString_40F1D0("Dialog.wnd:Next", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIDlg.c", 503);
		sub_46AEE0((int)v14, (int)v15);
	}
	sub_467C10();
	nox_xxx_bookHideMB_45ACA0(0);
	*getMemU32Ptr(0x587000, 153436) = nox_client_renderGUI_80828;
	nox_client_renderGUI_80828 = 0;
	nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1123524, 1);
	nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1123524);
	*getMemU32Ptr(0x5D4594, 1123528) = a2;
	result = nox_xxx_playDialogFile_44D900(*getMemIntPtr(0x5D4594, 1115312), 100);
	dword_5d4594_1123520 = 1;
	return result;
}

//----- (0047A020) --------------------------------------------------------
wchar_t* sub_47A020(char* a1) {
	uint32_t* v1;    // eax
	int v2;          // ebp
	wchar_t* v3;     // edi
	wchar_t* v4;     // eax
	wchar_t* result; // eax
	size_t v6;       // esi
	int v7;          // ebx
	wchar_t* v8;     // eax
	int v9;          // [esp+10h] [ebp-18h]
	wchar_t* v10;    // [esp+14h] [ebp-14h]
	int v11;         // [esp+18h] [ebp-10h]
	short* v12;      // [esp+1Ch] [ebp-Ch]
	wchar_t v13[4];  // [esp+20h] [ebp-8h]

	*(uint32_t*)v13 = *getMemU32Ptr(0x587000, 153644);
	v13[2] = *getMemU16Ptr(0x587000, 153648);
	v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3901);
	v2 = (int)v1;
	v3 = 0;
	v12 = (short*)v1[8];
	v11 = 0;
	v9 = v1[2] - 10;
	v4 = nox_strman_loadString_40F1D0(a1, getMemAt(0x5D4594, 1115312), "C:\\NoxPost\\src\\client\\Gui\\GUIDlg.c", 338);
	nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1107120), v4);
	result = nox_wcstok((wchar_t*)getMemAt(0x5D4594, 1107120), v13);
	v10 = result;
	if (result) {
		while (1) {
			if (!v3) {
				v3 = result;
			}
			v6 = nox_wcslen(v3);
			nox_xxx_drawGetStringSize_43F840(*(uint32_t*)(v2 + 236), v3, (int*)&a1, 0, 0);
			v7 = v6;
			if ((int)a1 > v9) {
				while (1) {
					v6 = v7;
					if (!v7) {
						break;
					}
					v8 = &v3[v7];
					while (*v8 != 32) {
						--v6;
						--v8;
						if (!v6) {
							goto LABEL_15;
						}
					}
					if (!v6) {
						break;
					}
					v7 = v6 - 1;
					nox_wcsncpy((wchar_t*)getMemAt(0x5D4594, 1115324), v3, v6);
					*getMemU16Ptr(0x5D4594, 1115324 + 2 * v6) = 0;
					nox_xxx_drawGetStringSize_43F840(*(uint32_t*)(v2 + 236), getMemU16Ptr(0x5D4594, 1115324), (int*)&a1,
													 0, 0);
					if ((int)a1 <= v9) {
						goto LABEL_16;
					}
				}
			LABEL_15:
				v6 = sub_43F9E0(*(uint32_t*)(v2 + 236), v3, v9);
			}
		LABEL_16:
			nox_wcsncpy((wchar_t*)getMemAt(0x5D4594, 1115324), v3, v6);
			v3 += v6;
			*getMemU16Ptr(0x5D4594, 1115324 + 2 * v6) = 0;
			if (*v3 == 32) {
				++v3;
			}
			result = (wchar_t*)*v12;
			if (v11 >= (int)result) {
				break;
			}
			nox_window_call_field_94(v2, 16397, (int)getMemAt(0x5D4594, 1115324), -1);
			if (nox_wcslen(v3)) {
				result = v10;
			} else {
				result = nox_wcstok(0, v13);
				v10 = result;
				v3 = result;
			}
			++v11;
			if (!result) {
				break;
			}
			result = v10;
		}
	}
	return result;
}
