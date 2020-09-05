#include "spelllst.h"

#include "../../../proto.h"
extern _DWORD dword_5d4594_1045508;
extern _DWORD dword_5d4594_1045480;
extern _DWORD dword_5d4594_1045484;
extern _DWORD dword_5d4594_2650652;

//----- (00453850) --------------------------------------------------------
int __cdecl sub_453850(int a1) {
	int v1;            // ebx
	int v2;            // eax
	int v3;            // esi
	int v4;            // edi
	wchar_t* v5;       // eax
	wchar_t* v6;       // eax
	wchar_t* v7;       // eax
	const wchar_t* v8; // eax
	_DWORD* v9;        // esi
	_DWORD* v10;       // esi
	wchar_t v12[64];   // [esp+Ch] [ebp-80h]

	dword_5d4594_1045484 = nox_new_window_from_file("spelllst.wnd", sub_453C00);
	sub_46B340(*(int*)&dword_5d4594_1045484, sub_453B80);
	sub_46B120(*(_DWORD**)&dword_5d4594_1045484, a1);
	sub_46B280(*(int*)&dword_5d4594_1045484, a1);
	dword_5d4594_1045480 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045484, 1110);
	dword_5d4594_1045508 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045484, 1112);
	sub_453B00();
	nox_window_call_field_94(*(int*)&dword_5d4594_1045480, 16399, 0, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045508, 16399, 0, 0);
	v1 = 1;
	do {
		if (sub_424B50(v1)) {
			v2 = sub_424A70(v1);
			v3 = v2;
			if (!(v2 & 0x15000)) {
				if (v2 & 0x1000000 || (v4 = v2 & 0x2000000) != 0 && v2 & 0x4000000) {
					v7 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 127452), 0,
											   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 307);
					nox_wcscpy(v12, v7);
				} else {
					if (!(v2 & 0x6000000))
						goto LABEL_14;
					nox_wcscpy(v12, (const wchar_t*)getMemAt(0x5D4594, 1045512));
					if (v4) {
						v5 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 127508), 0,
												   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 314);
						nox_wcscat(v12, v5);
					}
					if (v3 & 0x4000000) {
						v6 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 127568), 0,
												   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 318);
						nox_wcscat(v12, v6);
					}
				}
				nox_window_call_field_94(*(int*)&dword_5d4594_1045508, 16397, (int)v12, -1);
				v8 = (const wchar_t*)sub_424930(v1);
				nox_wcsncpy(v12, v8, 0x3Fu);
				nox_window_call_field_94(*(int*)&dword_5d4594_1045480, 16397, (int)v12, -1);
			}
		}
	LABEL_14:
		++v1;
	} while (v1 < 137);
	v9 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045484, 1113);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045480, 16408, (int)v9, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045508, 16408, (int)v9, 0);
	v10 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045484, 1114);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045480, 16409, (int)v10, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045508, 16409, (int)v10, 0);
	sub_454040(getMemAt(0x5D4594, 1045488));
	sub_454120();
	if (!nox_common_gameFlags_check_40A5C0(1) || nox_common_gameFlags_check_40A5C0(49152))
		sub_46AD20(*(_DWORD**)&dword_5d4594_1045484, 1115, 1133, 0);
	return dword_5d4594_1045484;
}

//----- (00453C00) --------------------------------------------------------
int __cdecl sub_453C00(int a1, int a2, int* a3, int a4) {
	int* v3;      // edi
	int v4;       // ebx
	__int16* v5;  // edi
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
		if (a3 == sub_46B0C0(*(_DWORD**)&dword_5d4594_1045484, 1113) ||
			a3 == sub_46B0C0(*(_DWORD**)&dword_5d4594_1045484, 1114)) {
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
	v4 = sub_46B0A0(a3);
	v21 = v4;
	switch (v4) {
	case 1113:
	case 1114:
		nox_window_call_field_94(*(int*)&dword_5d4594_1045480, 0x4000, (int)v3, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1045508, 0x4000, (int)v3, 0);
		goto LABEL_37;
	case 1115:
	case 1116:
		v5 = *(__int16**)(dword_5d4594_1045480 + 32);
		v6 = 0;
		v20 = sub_4165B0();
		if (*v5 > 0) {
			v7 = 0;
			do {
				if (*((_DWORD*)v5 + 6) + v7 != -4) {
					v8 = sub_424960((wchar_t*)(*((_DWORD*)v5 + 6) + v7 + 4));
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
				*getMemU32Ptr(0x5D4594, i * 4 + 1045488) &= v19[i + 6];
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
		v11 = *(_DWORD*)(dword_5d4594_1045480 + 32);
		v12 = (wchar_t*)(*(_DWORD*)(v11 + 24) + 524 * (sub_4A4800(*(_DWORD*)(dword_5d4594_1045480 + 32)) + v4 - 1120) +
						 4);
		if (!v12)
			goto LABEL_19;
		v13 = sub_424960(v12);
		if (!v13)
			goto LABEL_19;
		if (!dword_5d4594_2650652 || (sub_57A1E0(v19, 0, 0, 4, 6128), sub_454000((int)&v19[6], v13))) {
			v15 = sub_4165B0();
			if ((nox_common_gameFlags_check_40A5C0(64) || v15[52] & 0x40) && v13 == 132) {
				v3[9] ^= 4u;
				v18 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 127748), 0,
											"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 226);
				v16 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 127816), 0,
											"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 225);
				sub_449A10(*(int*)&dword_5d4594_1045484, (int)v16, (int)v18, 33, 0, 0);
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
			v17 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 127632), 0,
										"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 211);
			v14 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 127692), 0,
										"C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 210);
			sub_449A10(*(int*)&dword_5d4594_1045484, (int)v14, (int)v17, 33, 0, 0);
			sub_44A360(1);
		}
	LABEL_20:
		sub_452D80(766, 100);
		result = 0;
		break;
	default:
		goto LABEL_20;
	}
	return result;
}
