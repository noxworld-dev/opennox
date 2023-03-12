#include "client__gui__guidlg.h"
#include "client__gui__window.h"
#include "common__strman.h"

#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"

extern void* dword_5d4594_1123524;
extern int nox_win_width;
extern int nox_win_height;

//----- (0047A020) --------------------------------------------------------
void sub_47A020(char* a1) {
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
				v6 = nox_draw_getFontAdvance_43F9E0(*(uint32_t*)(v2 + 236), v3, v9);
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
}
