#include "guijourn.h"

#include "../../proto.h"

//----- (00469BC0) --------------------------------------------------------
void sub_469BC0() {
	int v0;            // esi
	int v1;            // eax
	int v2;            // ebx
	int i;             // ebp
	int v4;            // eax
	int v5;            // eax
	int v6;            // eax
	wchar_t* v7;       // eax
	wchar_t* v8;       // [esp-20h] [ebp-1078h]
	wchar_t* v9;       // [esp-20h] [ebp-1078h]
	wchar_t* v10;      // [esp-20h] [ebp-1078h]
	int v11;           // [esp+4h] [ebp-1054h]
	int v12;           // [esp+8h] [ebp-1050h]
	char v13[76];      // [esp+Ch] [ebp-104Ch]
	wchar_t v14[2048]; // [esp+58h] [ebp-1000h]

	v0 = *(_DWORD*)&byte_5D4594[2618908];
	if (*(_DWORD*)&byte_5D4594[2618908]) {
		v1 = sub_43F320(0);
		v2 = *(_DWORD*)(v0 + 3644);
		v11 = v1;
		for (i = -v1; v2; i += v11 + v12) {
			strcpy(v13, "Journal:");
			HIWORD(v4) = 0;
			strcat(&v13, (const char*)v2);
			LOWORD(v4) = *(_WORD*)(v2 + 72);
			v5 = v4 - 2;
			if (v5) {
				v6 = v5 - 2;
				if (v6) {
					if (v6 == 4) {
						v8 = loadString_sub_40F1D0((char*)&byte_587000[142564], 0,
									   "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c",
									   64);
						nox_wcscpy(v14, v8);
					} else {
						v14[0] = 0;
					}
				} else {
					v9 = loadString_sub_40F1D0((char*)&byte_587000[142500], 0,
								   "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 60);
					nox_wcscpy(v14, v9);
				}
			} else {
				v10 = loadString_sub_40F1D0((char*)&byte_587000[142440], 0,
							    "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 56);
				nox_wcscpy(v14, v10);
			}
			nox_wcscat(v14, L" ");
			v7 = loadString_sub_40F1D0((char*)&v13, 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 74);
			nox_wcscat(v14, v7);
			sub_43F840(0, v14, 0, &v12, 240);
			v2 = *(_DWORD*)(v2 + 64);
		}
		*(_DWORD*)&byte_5D4594[1064848] = i <= 0 ? 0 : i;
	}
}

//----- (00469D40) --------------------------------------------------------
void __cdecl sub_469D40(int xLeft, int yTop, int a3) {
	int v3;            // esi
	int v4;            // ebp
	int v5;            // ebx
	int i;             // eax
	int v7;            // eax
	int v8;            // edi
	wchar_t* v9;       // eax
	wchar_t* v10;      // eax
	wchar_t* v11;      // eax
	wchar_t* v12;      // eax
	int v13;           // esi
	int v14;           // [esp+10h] [ebp-1054h]
	int v15;           // [esp+14h] [ebp-1050h]
	char v16[76];      // [esp+18h] [ebp-104Ch]
	wchar_t v17[2048]; // [esp+64h] [ebp-1000h]

	v3 = *(_DWORD*)&byte_5D4594[2618908];
	v4 = yTop - a3;
	if (*(_DWORD*)&byte_5D4594[2618908]) {
		nox_video_drawSetColor_434460(*(int*)&byte_5D4594[2650656]);
		sub_49CE30(xLeft, yTop, 260, 150);
		v5 = *(_DWORD*)(v3 + 3644);
		if (v5) {
			for (i = *(_DWORD*)(v5 + 64); i; i = *(_DWORD*)(i + 64))
				v5 = i;
			v14 = sub_43F320(0);
			do {
				HIWORD(v7) = 0;
				strcpy(v16, "Journal:");
				strcat(v16, (const char*)v5);
				LOWORD(v7) = *(_WORD*)(v5 + 72);
				switch (v7) {
				case 1:
					v8 = *(_DWORD*)&byte_5D4594[2523948];
					goto LABEL_12;
				case 2:
					v8 = *(_DWORD*)&byte_5D4594[2650644];
					v9 = loadString_sub_40F1D0((char*)&byte_587000[142680], 0,
								   "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 135);
					nox_wcscpy(v17, v9);
					break;
				case 4:
					v8 = *(_DWORD*)&byte_5D4594[2650660];
					v10 = loadString_sub_40F1D0((char*)&byte_587000[142740], 0,
								    "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 140);
					nox_wcscpy(v17, v10);
					break;
				case 8:
					v8 = *(_DWORD*)&byte_5D4594[2589772];
					v11 = loadString_sub_40F1D0((char*)&byte_587000[142804], 0,
								    "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 145);
					nox_wcscpy(v17, v11);
					break;
				default:
					v8 = *(_DWORD*)&byte_5D4594[2618904];
				LABEL_12:
					v17[0] = 0;
					break;
				}
				nox_wcscat(v17, L" ");
				v12 = loadString_sub_40F1D0((char*)&v16, 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c",
							    155);
				nox_wcscat(v17, v12);
				sub_43F840(0, &v17, 0, &v15, 240);
				v13 = v15 + v4;
				if (v15 + v4 > yTop) {
					sub_434390(v8);
					sub_43FAF0(0, &v17, xLeft + 10, v4, 240, 0);
				}
				v4 = v13 + v14;
				if (v13 + v14 > yTop + 150)
					break;
				v5 = *(_DWORD*)(v5 + 68);
			} while (v5);
		}
	}
}
