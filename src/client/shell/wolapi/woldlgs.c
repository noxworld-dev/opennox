#include "woldlgs.h"
#include "../../../proto.h"
#include "wolchat.h"

extern _DWORD dword_5d4594_830204;
extern _DWORD dword_5d4594_830208;
extern _DWORD dword_5d4594_830132;
extern _DWORD dword_587000_111668;
extern _DWORD dword_5d4594_830148;
extern _DWORD dword_5d4594_830116;
extern _DWORD dword_5d4594_830140;
extern _DWORD dword_5d4594_830108;
extern _DWORD dword_5d4594_830124;
extern int nox_win_width;
extern int nox_win_height;

//----- (00448730) --------------------------------------------------------
int sub_448730_wol_dialogs() {
	int result; // eax

	if (*(_DWORD*)&byte_5D4594[830112])
		return 0;
	if (dword_5d4594_830116)
		return 0;
	if (*(_DWORD*)&byte_5D4594[830120])
		return 0;
	result = nox_new_window_from_file("wolfind.wnd", sub_4489C0_wol_dialogs);
	dword_5d4594_830124 = result;
	if (result) {
		*(_DWORD*)(result + 56) = *(_DWORD*)&byte_5D4594[2650656];
		*(_DWORD*)(dword_5d4594_830124 + 16) =
		    (nox_win_width - *(_DWORD*)(dword_5d4594_830124 + 8)) / 2;
		*(_DWORD*)(dword_5d4594_830124 + 24) =
		    *(_DWORD*)(dword_5d4594_830124 + 8) + *(_DWORD*)(dword_5d4594_830124 + 16);
		*(_DWORD*)&byte_5D4594[830128] = sub_46B0C0(*(_DWORD**)&dword_5d4594_830124, 1933);
		sub_46B300(*(int*)&byte_5D4594[830128], sub_448F00);
		*(_DWORD*)&byte_5D4594[830136] = sub_46B0C0(*(_DWORD**)&dword_5d4594_830124, 1934);
		dword_5d4594_830132 = sub_46B0C0(*(_DWORD**)&dword_5d4594_830124, 1935);
		sub_46B300(*(int*)&dword_5d4594_830132, sub_448F60);
		*(_DWORD*)&byte_5D4594[830152] = sub_46B0C0(*(_DWORD**)&dword_5d4594_830124, 1931);
		*(_DWORD*)&byte_5D4594[830156] = sub_46B0C0(*(_DWORD**)&dword_5d4594_830124, 1932);
		sub_46ABB0(*(int*)&byte_5D4594[830152], 0);
		dword_5d4594_830140 = sub_46B0C0(*(_DWORD**)&dword_5d4594_830124, 1938);
		*(_DWORD*)&byte_5D4594[830144] = sub_46B0C0(*(_DWORD**)&dword_5d4594_830124, 1939);
		dword_5d4594_830148 = sub_46B0C0(*(_DWORD**)&dword_5d4594_830124, 1936);
		sub_46B500(*(int*)&dword_5d4594_830132);
		*(_DWORD*)&byte_5D4594[830160] = loadString_sub_40F1D0(
		    (char*)&byte_587000[111732], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 579);
		*(_DWORD*)&byte_5D4594[830164] = loadString_sub_40F1D0(
		    (char*)&byte_587000[111800], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 580);
		*(_DWORD*)&byte_5D4594[830168] = loadString_sub_40F1D0(
		    (char*)&byte_587000[111872], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 581);
		*(_DWORD*)&byte_5D4594[830172] = loadString_sub_40F1D0(
		    (char*)&byte_587000[111936], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 582);
		*(_DWORD*)&byte_5D4594[830176] = loadString_sub_40F1D0(
		    (char*)&byte_587000[112000], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 583);
		*(_DWORD*)&byte_5D4594[830180] = loadString_sub_40F1D0(
		    (char*)&byte_587000[112068], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 584);
		*(_DWORD*)&byte_5D4594[830184] = loadString_sub_40F1D0(
		    (char*)&byte_587000[112136], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 585);
		*(_DWORD*)&byte_5D4594[830188] = loadString_sub_40F1D0(
		    (char*)&byte_587000[112196], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 586);
		dword_587000_111668 = 1;
		dword_5d4594_830116 = 1;
		sub_46B120(*(_DWORD**)&dword_5d4594_830124, 0);
		sub_46A8C0(*(int*)&dword_5d4594_830124);
		sub_46C690(*(int*)&dword_5d4594_830124);
		sub_46B500(*(int*)&dword_5d4594_830124);
		sub_46B340(*(int*)&dword_5d4594_830124, sub_448FC0);
		result = 1;
	}
	return result;
}

//----- (004489C0) --------------------------------------------------------
int __cdecl sub_4489C0_wol_dialogs(int a1, int a2, int* a3, int a4) {
	wchar_t* v4;       // esi
	const wchar_t* v5; // eax
	int result;        // eax
	wchar_t* v7;       // eax
	int v8;            // esi

	if (a2 == 16391) {
		v8 = sub_46B0A0(a3);
		sub_452D80(766, 100);
		switch (v8) {
		case 1931:
			nox_window_set_hidden(*(int*)&byte_5D4594[830136], 0);
			nox_window_set_hidden(*(int*)&dword_5d4594_830132, 1);
			nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, *(int*)&byte_5D4594[830160], 0);
			nox_window_call_field_94(*(int*)&byte_5D4594[830144], 16385, *(int*)&byte_5D4594[830168], 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_830148, 16385, *(int*)&byte_5D4594[830176], 0);
			sub_46ABB0(*(int*)&byte_5D4594[830152], 0);
			sub_46ABB0(*(int*)&byte_5D4594[830156], 1);
			if (dword_5d4594_830204)
				sub_46ABB0(*(int*)&dword_5d4594_830148, 0);
			else
				sub_46ABB0(*(int*)&dword_5d4594_830148, 1);
			dword_587000_111668 = 1;
			result = 0;
			break;
		case 1932:
			nox_window_set_hidden(*(int*)&byte_5D4594[830136], 1);
			nox_window_set_hidden(*(int*)&dword_5d4594_830132, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, *(int*)&byte_5D4594[830164], 0);
			nox_window_call_field_94(*(int*)&byte_5D4594[830144], 16385, *(int*)&byte_5D4594[830172], 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_830148, 16385, *(int*)&byte_5D4594[830180], 0);
			sub_46ABB0(*(int*)&byte_5D4594[830152], 1);
			sub_46ABB0(*(int*)&byte_5D4594[830156], 0);
			dword_587000_111668 = 0;
			if (dword_5d4594_830208)
				sub_46ABB0(*(int*)&dword_5d4594_830148, 0);
			else
				sub_46ABB0(*(int*)&dword_5d4594_830148, 1);
			result = 0;
			break;
		case 1936:
			sub_448CF0_wol_dialogs();
			goto LABEL_24;
		case 1937:
			sub_46C6E0(*(int*)&dword_5d4594_830124);
			sub_46C4E0(*(_DWORD**)&dword_5d4594_830124);
			sub_447600();
			dword_5d4594_830116 = 0;
			result = 0;
			break;
		default:
			goto LABEL_24;
		}
	} else if (a2 == 16400 && sub_46B0A0(a3) == 1934 && a4 != -1 &&
		   (v4 = (wchar_t*)nox_window_call_field_94((int)a3, 16406, a4, 0), *v4) &&
		   (v5 = (const wchar_t*)sub_41EC00(), v4)) {
		if (v5) {
			if (!nox_wcscmp(v4, v5)) {
				v7 = loadString_sub_40F1D0((char*)&byte_587000[112316], 0,
							   "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 327);
			} else {
				sub_46C6E0(*(int*)&dword_5d4594_830124);
				sub_46C4E0(*(_DWORD**)&dword_5d4594_830124);
				sub_447600();
				dword_5d4594_830116 = 0;
				dword_5d4594_830124 = 0;
				sub_40D380();
				sub_446A20_wol_chat(v4);
				v7 = loadString_sub_40F1D0((char*)&byte_587000[112252], 0,
							   "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 321);
			}
			nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, (int)v7, 0);
			result = 0;
		} else {
			sub_446A20_wol_chat(0);
			result = 0;
		}
	} else {
	LABEL_24:
		result = 0;
	}
	return result;
}

//----- (00448CF0) --------------------------------------------------------
int sub_448CF0_wol_dialogs() {
	_WORD* v0;    // esi
	int result;   // eax
	wchar_t* v2;  // eax
	int v3;       // eax
	wchar_t* v4;  // eax
	int v5;       // [esp+0h] [ebp-170h]
	char v6[36];  // [esp+4h] [ebp-16Ch]
	char v7[72];  // [esp+28h] [ebp-148h]
	char v8[256]; // [esp+70h] [ebp-100h]

	v0 = (_WORD*)nox_window_call_field_94(*(int*)&byte_5D4594[830128], 16413, 0, 0);
	if (dword_587000_111668) {
		if (v0 && *v0) {
			nox_sprintf(v7, "%S", v0);
			sub_40D740((int)v6);
			nox_swprintf((wchar_t*)&byte_5D4594[829840], *(const wchar_t**)&byte_5D4594[830184], v0);
			nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, (int)&byte_5D4594[829840], 0);
			dword_5d4594_830204 = 1;
			sub_4160D0(18);
			return sub_46ABB0(*(int*)&dword_5d4594_830148, 0);
		}
		v2 = loadString_sub_40F1D0((char*)&byte_587000[112388], 0,
					   "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 234);
		return nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, (int)v2, 0);
	}
	v3 = nox_window_call_field_94(*(int*)&dword_5d4594_830132, 16413, 0, 0);
	nox_sprintf(v8, "%S", v3);
	if (!v0 || !*v0) {
		v2 = loadString_sub_40F1D0((char*)&byte_587000[112520], 0,
					   "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 267);
		return nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, (int)v2, 0);
	}
	if (v8[0]) // TODO: &v5 != (int*)-112 && ...
	{
		nox_sprintf(v7, "%S", v0);
		sub_40D770((int)v6, (int)v8);
		nox_swprintf((wchar_t*)&byte_5D4594[829840], *(const wchar_t**)&byte_5D4594[830188], v0);
		nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, (int)&byte_5D4594[829840], 0);
		dword_5d4594_830208 = 1;
		sub_4160D0(19);
		sub_46ABB0(*(int*)&dword_5d4594_830148, 0);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_830132, 16414, (int)&byte_5D4594[830212], 0);
	} else {
		v4 = loadString_sub_40F1D0((char*)&byte_587000[112456], 0,
					   "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 264);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, (int)v4, 0);
	}
	return result;
}

//----- (004490C0) --------------------------------------------------------
void __cdecl sub_4490C0_wol_dialogs(int a1) {
	int v1;         // ebp
	char* v3;       // ebx
	const char* v4; // esi
	_DWORD* v5;     // eax
	wchar_t* v6;    // eax

	v1 = 0;
	if (sub_43AF80() == 11) {
		sub_43AFC0(a1);
		return;
	}
	if (!dword_5d4594_830116) {
		return;
	}
	v3 = sub_420110();
	if (!v3) {
		sub_4491B0_wol_dialogs();
		return;
	}
	nox_window_call_field_94(*(int*)&byte_5D4594[830136], 16399, 0, 0);
	if (a1) {
		v4 = (const char*)(a1 + 52);
		do {
			if (!strncmp(v4, v3, strlen(v3))) {
				v5 = sub_41E7A0(v4);
				nox_window_call_field_94(*(int*)&byte_5D4594[830136], 16397, (int)v5, 9);
				++v1;
			}
		} while (*(_DWORD*)(a1 + 48));
	}
	v6 = loadString_sub_40F1D0((char*)&byte_587000[112580], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c",
				   639);
	nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, (int)v6, 0);
	if (!v1)
		sub_4491B0_wol_dialogs();
}

//----- (004491B0) --------------------------------------------------------
int sub_4491B0_wol_dialogs() {
	int result;  // eax
	wchar_t* v1; // eax

	if (sub_43AF80() == 11)
		return sub_43AFA0(9);
	result = dword_5d4594_830116;
	if (dword_5d4594_830116) {
		v1 = loadString_sub_40F1D0((char*)&byte_587000[112640], 0,
					   "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 660);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, (int)v1, 0);
	}
	return result;
}

//----- (00449200) --------------------------------------------------------
int sub_449200_wol_dialogs() {
	int result;  // eax
	wchar_t* v1; // eax

	result = dword_5d4594_830116;
	if (dword_5d4594_830116) {
		v1 = loadString_sub_40F1D0((char*)&byte_587000[112700], 0,
					   "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 669);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, (int)v1, 0);
	}
	return result;
}

//----- (00449240) --------------------------------------------------------
int sub_449240_wol_dialogs() {
	int result;  // eax
	wchar_t* v1; // eax

	result = dword_5d4594_830116;
	if (dword_5d4594_830116) {
		v1 = loadString_sub_40F1D0((char*)&byte_587000[112760], 0,
					   "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 678);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_830140, 16385, (int)v1, 0);
	}
	return result;
}

//----- (004497D0) --------------------------------------------------------
int __cdecl sub_4497D0_wol_dialogs(int a1, int a2, int* a3, int a4) {
	_DWORD* v3;    // esi
	int v4;        // eax
	int result;    // eax
	int v6;        // eax
	int v7;        // eax
	int v8;        // edi
	_DWORD* v9;    // eax
	int v10;       // esi
	int v11;       // eax
	const char* i; // eax
	int v13;       // eax
	wchar_t* v14;  // eax
	wchar_t* v15;  // [esp-10h] [ebp-18h]

	if (a2 == 16389) {
		sub_452D80(920, 100);
		result = 1;
	} else if (a2 == 16391) {
		v6 = sub_46B0A0(a3) - 1952;
		if (v6) {
			v7 = v6 - 10;
			if (v7) {
				if (v7 == 1) {
					sub_46C6E0(*(int*)&dword_5d4594_830108);
					sub_46C4E0(*(_DWORD**)&dword_5d4594_830108);
					dword_5d4594_830108 = 0;
					if (sub_41E2F0() != 7) {
						sub_468020();
						sub_452D80(921, 100);
						return 1;
					}
				}
			} else {
				v8 = 0;
				v9 = sub_46B0C0(*(_DWORD**)&dword_5d4594_830108, 1961);
				v10 = nox_window_call_field_94((int)v9, 16404, 0, 0);
				if (v10 >= 0) {
					v11 = sub_4200F0();
					for (i = sub_4205B0(v11); i; i = (const char*)sub_4206B0((int)i)) {
						if (!v10)
							break;
						--v10;
					}
					sub_4207D0((int)i);
					if (sub_41E2F0() == 7) {
						v8 = 1;
						sub_41E300(3);
					}
					v13 = sub_41E2F0();
					sub_41DA70(v13, 3);
				}
				sub_46C6E0(*(int*)&dword_5d4594_830108);
				sub_46C4E0(*(_DWORD**)&dword_5d4594_830108);
				dword_5d4594_830108 = 0;
				if (v8) {
					v15 = loadString_sub_40F1D0(
					    (char*)&byte_587000[112880], 0,
					    "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 175);
					v14 = loadString_sub_40F1D0(
					    (char*)&byte_587000[112952], 0,
					    "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 174);
					sub_449A10(0, (int)v14, (int)v15, 288, 0, 0);
					sub_44A4B0();
					sub_452D80(921, 100);
					return 1;
				}
			}
		} else {
			sub_46C6E0(*(int*)&byte_5D4594[830096]);
			sub_46C4E0(*(_DWORD**)&byte_5D4594[830096]);
			*(_DWORD*)&byte_5D4594[830112] = 0;
			sub_447600();
		}
		sub_452D80(921, 100);
		result = 1;
	} else {
		if (a2 == 16400 && sub_46B0A0(a3) == 1961) {
			v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_830108, 1962);
			v4 = nox_window_call_field_94((int)a3, 16404, 0, 0);
			sub_46ABB0((int)v3, v4 >= 0);
		}
		result = 0;
	}
	return result;
}