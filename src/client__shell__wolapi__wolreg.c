#include "GAME1_2.h"
#include "GAME2_1.h"
#include "common__strman.h"
extern uint32_t dword_5d4594_1064300;
extern uint32_t dword_5d4594_1064820;
extern uint32_t dword_5d4594_1064296;
extern uint32_t dword_5d4594_1064816;

//----- (00468890) --------------------------------------------------------
int sub_468890_wol_reg(char* a1, char* a2, char* a3, uint8_t* a4, uint8_t* a5, wchar_t* a6) {
	uint32_t* v6;  // eax
	int v7;        // eax
	uint32_t* v8;  // eax
	int v9;        // eax
	uint32_t* v10; // eax
	int v11;       // eax
	uint32_t* v12; // eax
	int v13;       // eax
	char v14;      // al
	wchar_t* v15;  // eax
	int result;    // eax
	wchar_t* v17;  // eax
	wchar_t* v18;  // eax
	wchar_t* v19;  // eax
	wchar_t* v20;  // eax
	wchar_t* v21;  // [esp-4h] [ebp-60h]
	wchar_t* v22;  // [esp-4h] [ebp-60h]
	wchar_t* v23;  // [esp-4h] [ebp-60h]
	wchar_t* v24;  // [esp-4h] [ebp-60h]
	wchar_t* v25;  // [esp-4h] [ebp-60h]
	char v26[80];  // [esp+Ch] [ebp-50h]

	*a4 = (nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1064816, 1766)->draw_data.field_0 >> 2) & 1;
	*a5 = (nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1064816, 1767)->draw_data.field_0 >> 2) & 1;
	v6 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1064816, 1762);
	v7 = nox_window_call_field_94((int)v6, 16413, 0, 0);
	nox_sprintf(a1, "%S", v7);
	v8 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1064816, 1763);
	v9 = nox_window_call_field_94((int)v8, 16413, 0, 0);
	nox_sprintf(a2, "%S", v9);
	v10 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1064816, 1764);
	v11 = nox_window_call_field_94((int)v10, 16413, 0, 0);
	nox_sprintf(v26, "%S", v11);
	v12 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1064816, 1765);
	v13 = nox_window_call_field_94((int)v12, 16413, 0, 0);
	nox_sprintf(a3, "%S", v13);
	v14 = *a1;
	if (*a1) {
		if ((unsigned char)v14 < 0x31u || (unsigned char)v14 > 0x39u) {
			if (strlen(a2) == 8) {
				if (!strcmp(a2, v26)) {
					if (!dword_5d4594_1064300 || *a3) {
						result = 1;
					} else {
						v25 = nox_strman_loadString_40F1D0("TryAgain", 0,
														   "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 176);
						v20 = nox_strman_loadString_40F1D0("ErrNeedParentsEmail", 0,
														   "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 175);
						nox_swprintf(a6, L"%s %s", v20, v25);
						result = 0;
					}
				} else {
					v24 = nox_strman_loadString_40F1D0("TryAgain", 0,
													   "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 166);
					v19 = nox_strman_loadString_40F1D0("ErrPassDontMatch", 0,
													   "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 165);
					nox_swprintf(a6, L"%s %s", v19, v24);
					result = 0;
				}
			} else {
				v23 = nox_strman_loadString_40F1D0("TryAgain", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c",
												   158);
				v18 = nox_strman_loadString_40F1D0("ErrPasswordLength", 0,
												   "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 157);
				nox_swprintf(a6, L"%s %s", v18, v23);
				result = 0;
			}
		} else {
			v22 = nox_strman_loadString_40F1D0("TryAgain", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 150);
			v17 = nox_strman_loadString_40F1D0("ErrNickFirstLetter", 0,
											   "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 149);
			nox_swprintf(a6, L"%s %s", v17, v22);
			result = 0;
		}
	} else {
		v21 = nox_strman_loadString_40F1D0("TryAgain", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 142);
		v15 = nox_strman_loadString_40F1D0("ErrNoNick", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 141);
		nox_swprintf(a6, L"%s %s", v15, v21);
		result = 0;
	}
	return result;
}

//----- (00468BB0) --------------------------------------------------------
int sub_468BB0_wol_reg(int* a1, int* a2, int* a3, wchar_t* a4) {
	uint32_t* v4;      // eax
	const wchar_t* v5; // esi
	uint32_t* v6;      // eax
	const wchar_t* v7; // edi
	uint32_t* v8;      // eax
	const wchar_t* v9; // ebx
	uint32_t* v10;     // eax
	int v11;           // eax
	wchar_t* v12;      // eax
	int result;        // eax
	wchar_t* v14;      // eax
	wchar_t* v15;      // eax
	wchar_t* v16;      // [esp-4h] [ebp-14h]
	wchar_t* v17;      // [esp-4h] [ebp-14h]
	wchar_t* v18;      // [esp-4h] [ebp-14h]

	*a4 = 0;
	v4 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1064816, 1758);
	v5 = (const wchar_t*)nox_window_call_field_94((int)v4, 16413, 0, 0);
	v6 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1064816, 1759);
	v7 = (const wchar_t*)nox_window_call_field_94((int)v6, 16413, 0, 0);
	v8 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1064816, 1760);
	v9 = (const wchar_t*)nox_window_call_field_94((int)v8, 16413, 0, 0);
	v10 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1064816, 1761);
	v11 = nox_window_call_field_94((int)v10, 16413, 0, 0);
	nox_sprintf((char*)getMemAt(0x5D4594, 1064196), "%S", v11);
	if (v5 && v7 && nox_wcslen(v9) == 4) {
		if (getMemByte(0x5D4594, 1064196)) {
			*a1 = nox_wcstol(v5, 0, 10);
			*a2 = nox_wcstol(v7, 0, 10);
			*a3 = nox_wcstol(v9, 0, 10);
			if ((int)*a1 < 1 || (int)*a1 > 12 || (int)*a2 < 1 || (int)*a2 > 31) {
				v17 = nox_strman_loadString_40F1D0("TryAgain", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c",
												   228);
				v14 =
					nox_strman_loadString_40F1D0("ErrAge", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 227);
				nox_swprintf(a4, L"%s %s", v14, v17);
				result = 0;
			} else {
				result = 1;
			}
		} else {
			v16 = nox_strman_loadString_40F1D0("TryAgain", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 216);
			v12 = nox_strman_loadString_40F1D0("ErrEmail", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 215);
			nox_swprintf(a4, L"%s %s", v12, v16);
			result = 0;
		}
	} else {
		v18 = nox_strman_loadString_40F1D0("TryAgain", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 209);
		v15 = nox_strman_loadString_40F1D0("ErrAge", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 208);
		nox_swprintf(a4, L"%s %s", v15, v18);
		result = 0;
	}
	return result;
}

//----- (00468F30) --------------------------------------------------------
int sub_468F30_wol_reg() {
	wchar_t* v0; // eax

	v0 = nox_strman_loadString_40F1D0("Wolreg.c:ErrNoConsent", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c",
									  472);
	sub_468840(v0);
	dword_5d4594_1064296 = 4;
	nox_window_set_hidden(dword_5d4594_1064820, 1);
	return nox_xxx_wnd_46ABB0(dword_5d4594_1064816, 1);
}
