#include "selchar.h"

#include "../../proto.h"
#include "../gui/guisave.h"
#include "optsback.h"
extern _DWORD dword_5d4594_1307748;
extern _DWORD dword_5d4594_1307768;
extern _DWORD dword_5d4594_1307744;
extern _DWORD dword_5d4594_1307776;
extern _DWORD dword_5d4594_1307764;
extern _DWORD dword_5d4594_1307780;

//----- (004A4DB0) --------------------------------------------------------
int sub_4A4DB0() {
	int result;  // eax
	_DWORD* v1;  // esi
	_DWORD* v2;  // esi
	_DWORD* v3;  // esi
	wchar_t* v4; // eax
	_DWORD* v5;  // eax
	_DWORD* v6;  // eax
	_DWORD* v7;  // esi
	wchar_t* v8; // eax
	_DWORD* v9;  // eax

	nox_client_setCursorType_477610(0);
	if (sub_4D6F30())
		sub_4D6F90(1);
	sub_43BDD0(500);
	sub_4A1BE0(1);
	result = nox_new_window_from_file("SelChar.wnd", sub_4A5710);
	dword_5d4594_1307764 = result;
	if (result) {
		sub_46B300(result, sub_4A18E0);
		result = nox_wnd_sub_43C5B0(*(_DWORD**)&dword_5d4594_1307764, 0, 0, 0, -440, 0, 20, 0, -40);
		dword_5d4594_1307748 = result;
		if (result) {
			*(_DWORD*)result = 500;
			*(_DWORD*)(dword_5d4594_1307748 + 48) = sub_4A50A0;
			*(_DWORD*)(dword_5d4594_1307748 + 56) = sub_4A50D0;
			dword_5d4594_1307744 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 510);
			dword_5d4594_1307776 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 511);
			dword_5d4594_1307768 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 512);
			sub_46B2C0(*(int*)&dword_5d4594_1307744, sub_4A5710);
			sub_46B120(*(_DWORD**)&dword_5d4594_1307776, *(int*)&dword_5d4594_1307744);
			sub_46B120(*(_DWORD**)&dword_5d4594_1307768, *(int*)&dword_5d4594_1307744);
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				v5 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 504);
				nox_window_set_hidden((int)v5, 1);
				v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 505);
				nox_window_set_hidden((int)v6, 1);
				v7 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 509);
				v8 = loadString_sub_40F1D0((char*)&byte_587000[170436], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c",
										   746);
				sub_46AEE0((int)v7, (int)v8);
			} else {
				v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 504);
				nox_window_call_field_94(*(int*)&dword_5d4594_1307744, 16408, (int)v1, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_1307776, 16408, (int)v1, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_1307768, 16408, (int)v1, 0);
				v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 505);
				nox_window_call_field_94(*(int*)&dword_5d4594_1307744, 16409, (int)v2, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_1307776, 16409, (int)v2, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_1307768, 16409, (int)v2, 0);
				v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 509);
				v4 = loadString_sub_40F1D0((char*)&byte_587000[170380], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c",
										   735);
				sub_46AEE0((int)v3, (int)v4);
			}
			sub_4A5150();
			sub_4A19F0((char*)&byte_587000[170448]);
			sub_46A8A0();
			if (nox_common_gameFlags_check_40A5C0(0x2000))
				sub_4A5700();
			else
				sub_4A56E0();
			if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
				v9 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 502);
				nox_window_call_field_94(*(int*)&dword_5d4594_1307764, 16391, (int)v9, 0);
			}
			result = 1;
		}
	}
	return result;
}
//----- (004A5150) --------------------------------------------------------
int sub_4A5150() {
	size_t v0;                             // ebp
	_DWORD* v1;                            // eax
	char* v2;                              // edi
	int result;                            // eax
	HANDLE v7;                             // eax
	void* v8;                              // esi
	size_t v9;                             // ebp
	HANDLE v10;                            // edi
	int v11;                               // esi
	int v12;                               // esi
	size_t v13;                            // ebx
	wchar_t* v14;                          // eax
	unsigned int v15;                      // edi
	wchar_t* v16;                          // eax
	char* v17;                             // eax
	_DWORD* v18;                           // eax
	_DWORD* v19;                           // eax
	_DWORD* v20;                           // esi
	_DWORD* v21;                           // eax
	_DWORD* v22;                           // eax
	_DWORD* v23;                           // eax
	int v24;                               // [esp-Ch] [ebp-C18h]
	wchar_t* v25;                          // [esp-Ch] [ebp-C18h]
	wchar_t* v26;                          // [esp-8h] [ebp-C14h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+Ch] [ebp-C00h]
	char v28[64];                          // [esp+14Ch] [ebp-AC0h]
	wchar_t v29[64];                       // [esp+18Ch] [ebp-A80h]
	wchar_t v30[256];                      // [esp+20Ch] [ebp-A00h]
	char PathName[1024];                   // [esp+40Ch] [ebp-800h]
	char v32[1024];                        // [esp+80Ch] [ebp-400h]

	v0 = 0;
	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 501);
	sub_46ABB0((int)v1, 1);
	v2 = nox_common_get_data_path_409E10();
	strcpy(PathName, v2);
	strcat(PathName, "\\Save\\");
	CreateDirectoryA(PathName, 0);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		dword_5d4594_1307780 = nox_calloc(0xEu, 0x4FEu);
		result = sub_46CE40(*(int*)&dword_5d4594_1307744, *(int*)&dword_5d4594_1307776, *(int*)&dword_5d4594_1307768,
							*(_BYTE**)&dword_5d4594_1307780);
	} else {
		SetCurrentDirectoryA(PathName);
		strcpy(v32, PathName);
		v7 = FindFirstFileA("*.plr", &FindFileData);
		v8 = v7;
		if (v7 != (HANDLE)-1) {
			if (!(FindFileData.dwFileAttributes & 0x10))
				v0 = 1;
			if (FindNextFileA(v7, &FindFileData)) {
				do {
					if (!(FindFileData.dwFileAttributes & 0x10))
						++v0;
				} while (FindNextFileA(v8, &FindFileData));
			}
			FindClose(v8);
		}
		dword_5d4594_1307780 = nox_calloc(v0, 0x4FEu);
		v9 = 0;
		v10 = FindFirstFileA("*.plr", &FindFileData);
		if (v10 != (HANDLE)-1) {
			if (!(FindFileData.dwFileAttributes & 0x10)) {
				nox_sprintf(PathName, "%s%s", v32, FindFileData.cFileName);
				sub_41A000(PathName, *(_BYTE**)&dword_5d4594_1307780);
				if (sub_4A5690(*(_BYTE**)&dword_5d4594_1307780) == 1)
					v9 = 1;
			}
			if (FindNextFileA(v10, &FindFileData)) {
				v11 = 1278 * v9;
				do {
					if (!(FindFileData.dwFileAttributes & 0x10)) {
						nox_sprintf(PathName, "%s%s", v32, FindFileData.cFileName);
						sub_41A000(PathName, (_BYTE*)(v11 + dword_5d4594_1307780));
						if (sub_4A5690((_BYTE*)(v11 + dword_5d4594_1307780)) == 1) {
							++v9;
							v11 += 1278;
						}
					}
				} while (FindNextFileA(v10, &FindFileData));
			}
			FindClose(v10);
		}
		qsort(*(void**)&dword_5d4594_1307780, v9, 0x4FEu, sub_4A4CB0);
		if (v9) {
			v12 = 0;
			v13 = v9;
			do {
				nox_sprintf(v28, "nox.str:%s",
							*(_DWORD*)&byte_587000[4 * *(unsigned __int8*)(v12 + dword_5d4594_1307780 + 1274) + 29456]);
				v26 = loadString_sub_40F1D0(v28, 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 285);
				v24 = v12 + dword_5d4594_1307780 + 1224;
				v14 = loadString_sub_40F1D0((char*)&byte_587000[170600], 0,
											"C:\\NoxPost\\src\\client\\shell\\selchar.c", 283);
				nox_swprintf(v30, v14, v24, v26);
				if (*(_BYTE*)(v12 + dword_5d4594_1307780) & 4) {
					v15 = *(unsigned __int8*)(v12 + dword_5d4594_1307780 + 1277);
					if (v15 < 1)
						v15 = 1;
					nox_wcscat(v30, L" - ");
					v16 = loadString_sub_40F1D0((char*)&byte_587000[170680], 0,
												"C:\\NoxPost\\src\\client\\shell\\selchar.c", 298);
					nox_wcscat(v30, v16);
					nox_swprintf(v29, L" %d", v15);
					nox_wcscat(v30, v29);
				}
				nox_window_call_field_94(*(int*)&dword_5d4594_1307744, 16397, (int)&byte_587000[170708], 14);
				nox_window_call_field_94(*(int*)&dword_5d4594_1307768, 16397, (int)v30, 14);
				if (*(_BYTE*)(v12 + dword_5d4594_1307780) & 4)
					v25 = loadString_sub_40F1D0((char*)&byte_587000[170752], 0,
												"C:\\NoxPost\\src\\client\\shell\\selchar.c", 316);
				else
					v25 = loadString_sub_40F1D0((char*)&byte_587000[170812], 0,
												"C:\\NoxPost\\src\\client\\shell\\selchar.c", 325);
				nox_window_call_field_94(*(int*)&dword_5d4594_1307776, 16397, (int)v25, 14);
				v12 += 1278;
				--v13;
			} while (v13);
		}
		v17 = nox_common_get_data_path_409E10();
		SetCurrentDirectoryA(v17);
		if (v9) {
			v18 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 503);
			sub_46ABB0((int)v18, 1);
			v19 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 502);
			sub_46ABB0((int)v19, 1);
			v20 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 501);
			if ((sub_4D6F50() || sub_4D6F70()) && sub_4DC7D0() >= 14)
				sub_46ABB0((int)v20, 0);
			else
				sub_46ABB0((int)v20, 1);
		} else {
			v21 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 503);
			sub_46ABB0((int)v21, 0);
			v22 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 502);
			sub_46ABB0((int)v22, 0);
			v23 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307764, 501);
			sub_46ABB0((int)v23, 1);
		}
		result = dword_5d4594_1307776;
		if (*(_WORD*)(*(_DWORD*)(dword_5d4594_1307776 + 32) + 46)) {
			nox_window_call_field_94(*(int*)&dword_5d4594_1307776, 16403, 0, 0);
			result = nox_window_call_field_94(*(int*)&dword_5d4594_1307768, 16403, 0, 0);
		}
	}
	return result;
}
//----- (004A5710) --------------------------------------------------------
int __cdecl sub_4A5710(int a1, unsigned int a2, int* a3, int a4) {
	int v5;         // eax
	wchar_t* v6;    // eax
	int v7;         // ebx
	int v8;         // eax
	bool v9;        // zf
	int v10;        // eax
	char* v11;      // eax
	char* v12;      // eax
	int v13;        // eax
	int v14;        // eax
	wchar_t* v15;   // [esp-18h] [ebp-938h]
	int v16;        // [esp-14h] [ebp-934h]
	int (*v17)();   // [esp-10h] [ebp-930h]
	int v18;        // [esp-10h] [ebp-930h]
	int v19;        // [esp-Ch] [ebp-92Ch]
	char v20[12];   // [esp+4h] [ebp-91Ch]
	char v21[16];   // [esp+10h] [ebp-910h]
	char v22[1024]; // [esp+20h] [ebp-900h]
	char v23[1278]; // [esp+420h] [ebp-500h]

	if (a2 <= 0x4007) {
		if (a2 != 16391) {
			if (a2 == 2) {
				if (sub_46B0A0(a3) == 500) {
					free(*(LPVOID*)&dword_5d4594_1307780);
					return 0;
				}
			} else if (a2 == 16389) {
				sub_452D80(920, 100);
				return 1;
			}
			return 0;
		}
		switch (sub_46B0A0(a3)) {
		case 501:
			sub_4E3C60(1000000000);
			sub_4A50A0();
			*(_DWORD*)(dword_5d4594_1307748 + 52) = sub_4A4840;
			goto LABEL_40;
		case 502:
			v7 = *(_DWORD*)(dword_5d4594_1307776 + 32);
			v8 = *(_DWORD*)(v7 + 48);
			if (v8 != -1) {
				if (!strlen((const char*)(dword_5d4594_1307780 + 1278 * v8 + 4)))
					goto LABEL_38;
				sub_4DC970((char*)(dword_5d4594_1307780 + 1278 * v8 + 4), v20);
				if ((!nox_common_gameFlags_check_40A5C0(2048) || sub_4DC100((int)v20, (int)&byte_587000[171268])) &&
					sub_41A000((char*)(dword_5d4594_1307780 + 1278 * *(_DWORD*)(v7 + 48) + 4), v23)) {
					qmemcpy(&byte_5D4594[2660684], v23, 0x4FCu);
					*(_WORD*)&byte_5D4594[2661960] = *(_WORD*)&v23[1276];
					sub_43BDC0();
					if (byte_5D4594[2661958]) {
						if (byte_5D4594[2661958] == 1) {
							sub_409D70((char*)&byte_587000[171288]);
						} else if (byte_5D4594[2661958] == 2) {
							sub_409D70((char*)&byte_587000[171300]);
						}
					} else {
						sub_409D70((char*)&byte_587000[171276]);
					}
					if (nox_common_gameFlags_check_40A5C0(2048)) {
						sub_4DB220(1);
						sub_4DB230(1);
						nox_sprintf(v21, "%s.map", dword_5d4594_1307780 + 1278 * *(_DWORD*)(v7 + 48) + 1156);
						v9 = sub_4DB2A0(v21) == 0;
						v10 = *(_DWORD*)(v7 + 48);
						v19 = dword_5d4594_1307780 + 1278 * v10 + 1156;
						v18 = dword_5d4594_1307780 + 1278 * v10 + 1156;
						if (v9) {
							v12 = nox_common_get_data_path_409E10();
							nox_sprintf(v22, "%s\\Maps\\%s\\%s.map", v12, v18, v19);
						} else {
							v11 = nox_common_get_data_path_409E10();
							nox_sprintf(v22, "%s\\Save\\%s\\%s\\%s.map", v11, &byte_587000[171320], v18, v19);
						}
						sub_4DB270(v22);
						sub_409D70(v21);
						sub_4DCC70(1);
						v13 = sub_41D090((char*)(dword_5d4594_1307780 + 1278 * *(_DWORD*)(v7 + 48) + 4));
						sub_4E3C60(v13);
					} else if (sub_4D6F30()) {
						sub_4DCE60(*(unsigned __int8*)(dword_5d4594_1307780 + 1278 * *(_DWORD*)(v7 + 48) + 1277));
						sub_4DCE80((const char*)(dword_5d4594_1307780 + 1278 * *(_DWORD*)(v7 + 48) + 1156));
						v14 = sub_41D090((char*)(dword_5d4594_1307780 + 1278 * *(_DWORD*)(v7 + 48) + 4));
						sub_4E3C60(v14);
					}
					sub_4A24C0(0);
					sub_4A50A0();
					*(_DWORD*)(dword_5d4594_1307748 + 52) = 0;
				}
			}
			goto LABEL_40;
		case 503:
			v5 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_1307776 + 32) + 48);
			if (v5 == -1)
				goto LABEL_40;
			*(_DWORD*)&byte_5D4594[1307772] = *(_DWORD*)(*(_DWORD*)(dword_5d4594_1307776 + 32) + 48);
			sub_4DC970((char*)(dword_5d4594_1307780 + 1278 * v5 + 4), (char*)&byte_5D4594[1307752]);
			if (nox_common_gameFlags_check_40A5C0(2048) && !strcmp((const char*)&byte_5D4594[1307752], "AUTOSAVE")) {
				sub_452D80(925, 100);
				v17 = 0;
				v16 = 33;
				v15 = loadString_sub_40F1D0((char*)&byte_587000[170876], 0,
											"C:\\NoxPost\\src\\client\\shell\\selchar.c", 466);
				v6 = loadString_sub_40F1D0((char*)&byte_587000[170952], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c",
										   465);
			} else {
				if (!strlen((const char*)(dword_5d4594_1307780 + 1278 * *(_DWORD*)&byte_5D4594[1307772] + 4))) {
				LABEL_38:
					sub_452D80(925, 100);
					goto LABEL_40;
				}
				v17 = sub_4A5C70;
				v16 = 56;
				if (nox_common_gameFlags_check_40A5C0(2048)) {
					v15 = loadString_sub_40F1D0((char*)&byte_587000[171024], 0,
												"C:\\NoxPost\\src\\client\\shell\\selchar.c", 480);
					v6 = loadString_sub_40F1D0((char*)&byte_587000[171092], 0,
											   "C:\\NoxPost\\src\\client\\shell\\selchar.c", 479);
				} else {
					v15 = loadString_sub_40F1D0((char*)&byte_587000[171160], 0,
												"C:\\NoxPost\\src\\client\\shell\\selchar.c", 488);
					v6 = loadString_sub_40F1D0((char*)&byte_587000[171236], 0,
											   "C:\\NoxPost\\src\\client\\shell\\selchar.c", 487);
				}
			}
			sub_449A10(0, (int)v6, (int)v15, v16, v17, 0);
		LABEL_40:
			sub_452D80(921, 100);
			return 1;
		case 504:
		case 505:
			nox_window_call_field_94(*(int*)&dword_5d4594_1307744, 0x4000, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1307776, 0x4000, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1307768, 0x4000, (int)a3, 0);
			goto LABEL_40;
		default:
			goto LABEL_40;
		}
	}
	if (a2 == 16400) {
		nox_window_call_field_94(*(int*)&dword_5d4594_1307744, 16403, a4, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1307776, 16403, a4, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1307768, 16403, a4, 0);
	}
	return 0;
}
