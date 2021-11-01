#include "client__gui__servopts__spelllst.h"
#include "client__gui__window.h"
#include "common__strman.h"

#include "GAME1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME5_2.h"
#include "common__magic__speltree.h"
extern uint32_t dword_5d4594_1045508;
extern uint32_t dword_5d4594_1045480;
extern uint32_t dword_5d4594_1045484;
extern uint32_t dword_5d4594_2650652;

//----- (00453850) --------------------------------------------------------
int  nox_xxx_guiSpelllistLoad_453850(int a1) {
	uint32_t* v9;        // esi
	uint32_t* v10;       // esi

	dword_5d4594_1045484 = nox_new_window_from_file("spelllst.wnd", sub_453C00);
	nox_xxx_wndSetDrawFn_46B340(*(int*)&dword_5d4594_1045484, sub_453B80);
	sub_46B120(*(uint32_t**)&dword_5d4594_1045484, a1);
	nox_xxx_wnd_46B280(*(int*)&dword_5d4594_1045484, a1);
	dword_5d4594_1045480 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045484, 1110);
	dword_5d4594_1045508 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045484, 1112);
	sub_453B00();
	nox_window_call_field_94(*(int*)&dword_5d4594_1045480, 16399, 0, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045508, 16399, 0, 0);
	wchar_t wbuf[64] = {0};
	for (int i = 1; i < NOX_SPELLS_MAX; i++) {
		if (!nox_xxx_spellIsValid_424B50(i)) {
			continue;
		}
		int flags = nox_xxx_spellFlags_424A70(i);
		if ((flags & 0x15000) != 0) {
			continue;
		}
		if (flags & 0x1000000 || flags & 0x2000000 && flags & 0x4000000) {
			wchar_t* v7 = nox_strman_loadString_40F1D0("Common", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 307);
			nox_wcscpy(wbuf, v7);
		} else {
			if ((flags & 0x6000000) == 0) {
				continue;
			}
			wbuf[0] = 0;
			if (flags & 0x2000000) {
				wchar_t* v5 = nox_strman_loadString_40F1D0("SpellWizard", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 314);
				nox_wcscat(wbuf, v5);
			}
			if (flags & 0x4000000) {
				wchar_t* v6 = nox_strman_loadString_40F1D0("SpellConjurer", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 318);
				nox_wcscat(wbuf, v6);
			}
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_1045508, 16397, wbuf, -1);
		wchar_t* title = nox_xxx_spellTitle_424930(i);
		nox_wcsncpy(wbuf, title, sizeof(wbuf)/2-1);
		nox_window_call_field_94(*(int*)&dword_5d4594_1045480, 16397, wbuf, -1);
	}
	v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045484, 1113);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045480, 16408, (int)v9, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045508, 16408, (int)v9, 0);
	v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045484, 1114);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045480, 16409, (int)v10, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045508, 16409, (int)v10, 0);
	sub_454040(getMemAt(0x5D4594, 1045488));
	sub_454120();
	if (!nox_common_gameFlags_check_40A5C0(1) || nox_common_gameFlags_check_40A5C0(49152))
		sub_46AD20(*(uint32_t**)&dword_5d4594_1045484, 1115, 1133, 0);
	return dword_5d4594_1045484;
}

//----- (00453C00) --------------------------------------------------------
int  sub_453C00(int a1, int a2, int* a3, int a4) {
	int* v3;      // edi
	int v4;       // ebx
	short* v5;  // edi
	int v6;       // ebp
	int v7;       // ebx
	int v8;       // esi
	int i;        // eax
	int result;   // eax
	int v11;      // esi
	wchar_t* v12; // eax
	int v13;      // esi
	wchar_t* v14; // eax
	char* v15;    // ebp
	wchar_t* v16; // eax
	wchar_t* v17; // [esp-10h] [ebp-5Ch]
	wchar_t* v18; // [esp-10h] [ebp-5Ch]
	int v19[15];  // [esp+10h] [ebp-3Ch]
	char* v20;    // [esp+54h] [ebp+8h]
	int v21;      // [esp+58h] [ebp+Ch]

	if (a2 == 0x4000) {
		if (a3 == nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045484, 1113) ||
			a3 == nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045484, 1114)) {
			nox_window_call_field_94(*(int*)&dword_5d4594_1045480, 0x4000, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1045508, 0x4000, (int)a3, 0);
		LABEL_37:
			sub_454120();
		}
		return 0;
	}
	if (a2 != 16391)
		return 0;
	v3 = a3;
	v4 = nox_xxx_wndGetID_46B0A0(a3);
	v21 = v4;
	switch (v4) {
	case 1113:
	case 1114:
		nox_window_call_field_94(*(int*)&dword_5d4594_1045480, 0x4000, (int)v3, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1045508, 0x4000, (int)v3, 0);
		goto LABEL_37;
	case 1115:
	case 1116:
		v5 = *(short**)(dword_5d4594_1045480 + 32);
		v6 = 0;
		v20 = sub_4165B0();
		if (*v5 > 0) {
			v7 = 0;
			do {
				if (*((uint32_t*)v5 + 6) + v7 != -4) {
					v8 = nox_xxx_spellByTitle_424960((wchar_t*)(*((uint32_t*)v5 + 6) + v7 + 4));
					if (v8) {
						if (v21 == 1115) {
							if (!nox_common_gameFlags_check_40A5C0(64) && !(v20[52] & 0x40) || v8 != 132)
								sub_453FA0((int)getMemAt(0x5D4594, 1045488), v8, 1);
						} else {
							sub_453FA0((int)getMemAt(0x5D4594, 1045488), v8, 0);
						}
					}
				}
				++v6;
				v7 += 524;
			} while (v6 < *v5);
		}
		if (dword_5d4594_2650652) {
			sub_57A1E0(v19, 0, 0, 4, 6128);
			for (i = 0; i < 5; ++i)
				*getMemU32Ptr(0x5D4594, 1045488 + i * 4) &= v19[i + 6];
		}
		sub_454120();
		goto LABEL_19;
	case 1120:
	case 1121:
	case 1122:
	case 1123:
	case 1124:
	case 1125:
	case 1126:
	case 1127:
	case 1128:
	case 1129:
	case 1130:
	case 1131:
	case 1132:
	case 1133:
		v11 = *(uint32_t*)(dword_5d4594_1045480 + 32);
		v12 = (wchar_t*)(*(uint32_t*)(v11 + 24) + 524 * (sub_4A4800(*(uint32_t*)(dword_5d4594_1045480 + 32)) + v4 - 1120) +
						 4);
		if (!v12)
			goto LABEL_19;
		v13 = nox_xxx_spellByTitle_424960(v12);
		if (!v13)
			goto LABEL_19;
		if (!dword_5d4594_2650652 || (sub_57A1E0(v19, 0, 0, 4, 6128), sub_454000((int)&v19[6], v13))) {
			v15 = sub_4165B0();
			if ((nox_common_gameFlags_check_40A5C0(64) || v15[52] & 0x40) && v13 == 132) {
				v3[9] ^= 4u;
				v18 = nox_strman_loadString_40F1D0("plyrspel.c:Illegal", 0,
											"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 226);
				v16 = nox_strman_loadString_40F1D0("Notice", 0,
											"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 225);
				nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_1045484, (int)v16, (int)v18, 33, 0, 0);
				sub_44A360(1);
			} else {
				if (v3[9] & 4)
					sub_453FA0((int)getMemAt(0x5D4594, 1045488), v13, 0);
				else
					sub_453FA0((int)getMemAt(0x5D4594, 1045488), v13, 1);
			LABEL_19:
				sub_459D50(1);
			}
		} else {
			v3[9] ^= 4u;
			v17 = nox_strman_loadString_40F1D0("NotInternet", 0,
										"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 211);
			v14 = nox_strman_loadString_40F1D0("Notice", 0,
										"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 210);
			nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_1045484, (int)v14, (int)v17, 33, 0, 0);
			sub_44A360(1);
		}
	LABEL_20:
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
		result = 0;
		break;
	default:
		goto LABEL_20;
	}
	return result;
}
