#include "guispell.h"

#include "../../proto.h"
#include "gamewin/gamewin.h"
#include "guimsg.h"

extern _DWORD dword_5d4594_1049516;
extern _DWORD dword_5d4594_1049524;
extern _DWORD dword_5d4594_1049536;
extern _DWORD dword_5d4594_1048144;
extern _DWORD dword_5d4594_1049484;
extern _DWORD dword_5d4594_1047552;
extern _DWORD dword_5d4594_1049512;
extern _DWORD dword_5d4594_1047548;
extern _DWORD dword_5d4594_1049520;
extern _DWORD dword_5d4594_1049508;
extern _DWORD dword_5d4594_1049500;
extern _DWORD dword_5d4594_1049504;
extern _DWORD dword_587000_133480;
extern int nox_win_width;
extern int nox_win_height;

//----- (0045DEB0) --------------------------------------------------------
int __cdecl sub_45DEB0(int* a1, int a2, int a3, int a4) {
	int v4;      // ebx
	wchar_t* v5; // eax
	_DWORD* v6;  // ecx
	int v7;      // eax

	v4 = sub_45DE60((int)a1, a3, a4);
	if (v4 >= 0) {
		if (a1 != (int*)getMemAt(0x5D4594, 1047940)) {
		LABEL_8:
			sub_45DC40((int)a1, a2, v4);
			return 1;
		}
		if (sub_424BF0(a2)) {
			v6 = (_DWORD*)a1[51];
			v7 = 0;
			while (*v6 != a2) {
				++v7;
				v6 += 2;
				if (v7 >= 3)
					goto LABEL_8;
			}
			v5 =
				loadString_sub_40F1D0((char*)getMemAt(0x587000, 133772), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 504);
		} else {
			v5 =
				loadString_sub_40F1D0((char*)getMemAt(0x587000, 133712), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 496);
		}
		sub_445490(v5);
		sub_452D80(925, 100);
	}
	return 0;
}

//----- (0045E040) --------------------------------------------------------
_DWORD* sub_45E040() {
	_DWORD** v0;    // edx
	_DWORD* v1;     // ecx
	int v2;         // edi
	int i;          // eax
	_DWORD* result; // eax
	wchar_t* v5;    // eax
	int* v6;        // ecx
	int v7;         // esi
	char v8;        // al
	int v9[5];      // [esp+8h] [ebp-14h]

	v0 = *(_DWORD***)&dword_5d4594_1048144;
	v1 = *(_DWORD**)&dword_5d4594_1048144;
	v2 = 0;
	for (i = 0; i < 3; ++i) {
		if (*v1)
			break;
		v1 += 2;
	}
	if (i == 3) {
		result = *(_DWORD**)getMemAt(0x5D4594, 2618908);
		if (*(_DWORD*)getMemAt(0x5D4594, 2618908)) {
			if (*(_DWORD*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 3832)) {
				v5 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 133828), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c",
										   1145);
				sub_445490(v5);
				result = sub_452D80(925, 100);
			}
		}
	} else {
		*getMemAt( 0x5D4594, 1049488) = 0;
		v6 = v9;
		v7 = 3;
		do {
			result = *v0;
			if (*v0) {
				*v6 = (int)result;
				++v2;
				++v6;
			}
			v0 += 2;
			--v7;
		} while (v7);
		if (v2 < 5) {
			v8 = getMemByte(0x5D4594, 1047924);
			v9[v2] = 34;
			result = (_DWORD*)sub_45DB20((char*)v9, v2 + 1, v8);
			*(_DWORD*)getMemAt(0x5D4594, 1047916) = 0;
			*(_DWORD*)getMemAt(0x5D4594, 1049480) = 0;
		}
	}
	return result;
}
//----- (0045E190) --------------------------------------------------------
int sub_45E190() {
	int v0;               // ebp
	int v1;               // ebx
	int v2;               // edi
	unsigned __int8* v4;  // esi
	char* v5;             // eax
	char* v6;             // eax
	char* v7;             // eax
	char* v8;             // eax
	wchar_t* v9;          // eax
	wchar_t* v10;         // eax
	char* v11;            // eax
	char* v12;            // eax
	char* v13;            // eax
	char* v14;            // eax
	wchar_t* v15;         // eax
	wchar_t* v16;         // eax
	char* v17;            // eax
	char* v18;            // eax
	char* v19;            // eax
	char* v20;            // eax
	char* v21;            // eax
	int v22;              // eax
	_DWORD* v23;          // eax
	wchar_t* v24;         // esi
	char* v25;            // eax
	wchar_t* v26;         // eax
	wchar_t* v27;         // esi
	char* v28;            // eax
	wchar_t* v29;         // eax
	char* v30;            // eax
	char* v31;            // eax
	char* v32;            // eax
	char* v33;            // eax
	char* v34;            // eax
	char* v35;            // eax
	wchar_t* v36;         // eax
	wchar_t* v37;         // esi
	char* v38;            // eax
	wchar_t* v39;         // eax
	wchar_t* v40;         // esi
	char* v41;            // eax
	wchar_t* v42;         // eax
	wchar_t* v43;         // esi
	char* v44;            // eax
	wchar_t* v45;         // eax
	char* v46;            // eax
	_DWORD* v47;          // eax
	int v48;              // eax
	int v49;              // ecx
	int* v50;             // ebx
	int v51;              // edi
	int v52;              // ecx
	_DWORD* v53;          // esi
	char* v54;            // eax
	char* v55;            // eax
	char* v56;            // eax
	char* v57;            // eax
	_DWORD* v58;          // esi
	_DWORD* v59;          // esi
	int v60;              // eax
	bool v61;             // zf
	int j;                // eax
	int v63;              // [esp-8h] [ebp-58h]
	unsigned __int16 v64; // [esp+Ch] [ebp-44h]
	int v65;              // [esp+10h] [ebp-40h]
	int v66;              // [esp+14h] [ebp-3Ch]
	int v67;              // [esp+18h] [ebp-38h]
	int v68;              // [esp+20h] [ebp-30h]
	int v69;              // [esp+20h] [ebp-30h]
	int i;                // [esp+24h] [ebp-2Ch]
	unsigned __int8* v71; // [esp+28h] [ebp-28h]
	char v72[32];         // [esp+30h] [ebp-20h]

	v0 = 0;
	*(_DWORD*)getMemAt(0x5D4594, 1047916) = 0;
	*getMemAt( 0x5D4594, 1047920) = 0;
	sub_416170(5);
	*(_DWORD*)getMemAt(0x5D4594, 1047924) = 0;
	*(_DWORD*)getMemAt(0x5D4594, 1047928) = 0;
	*(_DWORD*)getMemAt(0x5D4594, 1049480) = 0;
	*getMemAt( 0x5D4594, 1049488) = 0;
	v68 = sub_43F320(0);
	dword_5d4594_1047548 = (nox_win_width - 320) / 2;
	dword_5d4594_1047552 = nox_win_height - 74;
	*(_DWORD*)getMemAt(0x5D4594, 1049684) = sub_43F360((char*)getMemAt(0x587000, 133840));
	*(_DWORD*)getMemAt(0x587000, 133656) = dword_5d4594_1047548;
	v1 = dword_5d4594_1047548 + 69;
	*(_DWORD*)getMemAt(0x587000, 133660) = dword_5d4594_1047552 - 17;
	v2 = dword_5d4594_1047552 + 32;
	*(_DWORD*)getMemAt(0x587000, 133664) = dword_5d4594_1047548 + 320;
	*(_DWORD*)getMemAt(0x587000, 133668) = nox_win_height;
	if (!*(_DWORD*)getMemAt(0x5D4594, 2618908))
		return 0;
	if (*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251))
		sub_4601F0(*(int*)&dword_587000_133480, dword_5d4594_1047548 + 69, dword_5d4594_1047552 + 32, 5, 0, sub_45EF50,
				   sub_45FDE0);
	else
		sub_4601F0(*(int*)&dword_587000_133480, dword_5d4594_1047548 + 69, dword_5d4594_1047552 + 32, 5, 0, sub_45EF50,
				   sub_45FBD0);
	v4 = getMemAt(0x5D4594, 1048964);
	do {
		v2 -= 60;
		sub_4601F0((int)v4, v1, v2, 5, 0, sub_45EF50, sub_45FDE0);
		nox_window_set_hidden(*((_DWORD*)v4 + 52), 1);
		v4[200] = 0;
		*((_DWORD*)v4 + 51) = v4;
		v4 -= 256;
	} while ((int)v4 >= (int)getMemAt(0x5D4594, 1048196));
	if (*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251)) {
		dword_5d4594_1049504 =
			nox_window_new(0, 1160, dword_5d4594_1047548 + 260, *(int*)&dword_5d4594_1047552, 45, 66, 0);
		sub_46AE40(*(int*)&dword_5d4594_1049504, -263, 0);
		dword_5d4594_1049536 = nox_win_height - 74;
		sub_46B300(*(int*)&dword_5d4594_1049504, sub_45F8D0);
		dword_5d4594_1049520 = nox_window_new(*(int*)&dword_5d4594_1049504, 1032, 9, 33, 32, 32, 0);
		nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1049520, sub_45F7A0, sub_460000, 0);
		dword_5d4594_1049500 = nox_window_new(*(int*)&dword_5d4594_1049504, 1160, 0, 19, 12, 12, 0);
		sub_46B300(*(int*)&dword_5d4594_1049500, sub_45FB90);
		sub_46AE40(*(int*)&dword_5d4594_1049500, -265, -23);
		v5 = sub_42F970("QuickBarTrapButton");
		sub_46AE60(*(int*)&dword_5d4594_1049500, (int)v5);
		v6 = sub_42F970("QuickBarTrapButtonLit");
		sub_46AEA0(*(int*)&dword_5d4594_1049500, (int)v6);
	} else {
		dword_5d4594_1049504 =
			nox_window_new(0, 1672, dword_5d4594_1047548 + 260, *(int*)&dword_5d4594_1047552, 45, 66, 0);
		sub_46AE40(*(int*)&dword_5d4594_1049504, -263, 0);
		dword_5d4594_1049536 = nox_win_height - 74;
		sub_46B300(*(int*)&dword_5d4594_1049504, sub_45F8D0);
	}
	if (*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251)) {
		if (*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251) == 1) {
			if ((!*(_DWORD*)getMemAt(0x5D4594, 2618908) || !*(_DWORD*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 3832)) &&
				(!nox_common_gameFlags_check_40A5C0(0x2000) || nox_common_gameFlags_check_40A5C0(4096) ||
				 sub_4D6F50() || sub_4D6F70())) {
				v17 = sub_42F970("QuickBarWarriorRight");
				sub_46AE60(*(int*)&dword_5d4594_1049504, (int)v17);
				v18 = sub_42F970("QuickBarWarriorRight");
				sub_46AEA0(*(int*)&dword_5d4594_1049504, (int)v18);
				sub_46AD80(*(int*)&dword_5d4594_1049520, 8);
				sub_46AD80(*(int*)&dword_5d4594_1049500, 8);
				sub_46B340(*(int*)&dword_5d4594_1049500, sub_45EF30);
			} else {
				v13 = sub_42F970("QuickBarTrap");
				sub_46AE60(*(int*)&dword_5d4594_1049504, (int)v13);
				v14 = sub_42F970("QuickBarTrapHit");
				sub_46AEA0(*(int*)&dword_5d4594_1049504, (int)v14);
				v15 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 134012), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c",
											1805);
				sub_46B000((wchar_t*)(dword_5d4594_1049520 + 36), v15);
				sub_46AD60(*(int*)&dword_5d4594_1049520, 8);
				v16 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 134068), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c",
											1808);
				sub_46B000((wchar_t*)(dword_5d4594_1049500 + 36), v16);
				sub_46AD60(*(int*)&dword_5d4594_1049500, 8);
			}
		} else if (*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251) == 2) {
			if ((!*(_DWORD*)getMemAt(0x5D4594, 2618908) || !*(_DWORD*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 3832)) &&
				(!nox_common_gameFlags_check_40A5C0(0x2000) || nox_common_gameFlags_check_40A5C0(4096) ||
				 sub_4D6F50() || sub_4D6F70())) {
				v11 = sub_42F970("QuickBarWarriorRight");
				sub_46AE60(*(int*)&dword_5d4594_1049504, (int)v11);
				v12 = sub_42F970("QuickBarWarriorRight");
				sub_46AEA0(*(int*)&dword_5d4594_1049504, (int)v12);
				sub_46AD80(*(int*)&dword_5d4594_1049520, 8);
				sub_46AD80(*(int*)&dword_5d4594_1049500, 8);
				sub_46B340(*(int*)&dword_5d4594_1049500, sub_45EF30);
			} else {
				v7 = sub_42F970("QuickBarBomber");
				sub_46AE60(*(int*)&dword_5d4594_1049504, (int)v7);
				v8 = sub_42F970("QuickBarBomberHit");
				sub_46AEA0(*(int*)&dword_5d4594_1049504, (int)v8);
				v9 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 134216), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c",
										   1838);
				sub_46B000((wchar_t*)(dword_5d4594_1049520 + 36), v9);
				sub_46AD60(*(int*)&dword_5d4594_1049520, 8);
				v10 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 134276), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c",
											1841);
				sub_46B000((wchar_t*)(dword_5d4594_1049500 + 36), v10);
				sub_46AD60(*(int*)&dword_5d4594_1049500, 8);
			}
		}
	} else {
		v19 = sub_42F970("QuickBarWarriorRight");
		sub_46AE60(*(int*)&dword_5d4594_1049504, (int)v19);
		v20 = sub_42F970("QuickBarWarriorRight");
		sub_46AEA0(*(int*)&dword_5d4594_1049504, (int)v20);
	}
	if (*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251)) {
		sub_4601F0((int)getMemAt(0x5D4594, 1047940), dword_5d4594_1047548 + 122, dword_5d4594_1047552 - 17, 3, 21, sub_45EF50,
				   sub_45FDE0);
		v21 = sub_42F970("QuickBarTrapTray");
		sub_46AE60(*(int*)getMemAt(0x5D4594, 1048148), (int)v21);
		sub_46AE40(*(int*)getMemAt(0x5D4594, 1048148), -40, -20);
		v22 = *(_DWORD*)getMemAt(0x5D4594, 1048192);
		LOBYTE(v22) = getMemByte(0x5D4594, 1048192) | 1;
		*(_DWORD*)getMemAt(0x5D4594, 1048192) = v22;
		nox_window_set_hidden(*(int*)getMemAt(0x5D4594, 1048148), 1);
		dword_5d4594_1049484 = 0;
		v23 = nox_window_new(*(int*)getMemAt(0x5D4594, 1048148), 1032, 20, -7, 110, v68, 0);
		nox_window_set_all_funcs(v23, 0, sub_45FAC0, 0);
		v24 = (wchar_t*)nox_window_new(*(int*)getMemAt(0x5D4594, 1048148), 1032, 15, 12, 10, 14, 0);
		sub_46AE60((int)v24, 0);
		v25 = sub_42F970("QuickBarTrapTrayUpLit");
		sub_46AEA0((int)v24, (int)v25);
		nox_window_set_all_funcs(v24, sub_45F630, sub_45F6F0, 0);
		sub_46AE40((int)v24, -55, -32);
		v26 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 134432), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1883);
		sub_46B000(v24 + 18, v26);
		*((_DWORD*)v24 + 92) = 3;
		v27 = (wchar_t*)nox_window_new(*(int*)getMemAt(0x5D4594, 1048148), 1032, 15, 32, 10, 14, 0);
		sub_46AE60((int)v27, 0);
		v28 = sub_42F970("QuickBarTrapTrayDownLit");
		sub_46AEA0((int)v27, (int)v28);
		nox_window_set_all_funcs(v27, sub_45F630, sub_45F6F0, 0);
		sub_46AE40((int)v27, -55, -52);
		v29 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 134512), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1892);
		sub_46B000(v27 + 18, v29);
		*((_DWORD*)v27 + 92) = 4;
		dword_5d4594_1049508 = nox_window_new(0, 1032, dword_5d4594_1047548 - 1, dword_5d4594_1047552 + 26, 61, 48, 0);
		sub_46AE40(*(int*)&dword_5d4594_1049508, 1, -26);
		v30 = sub_42F970("QuickBarSpellSetBase");
		sub_46AE60(*(int*)&dword_5d4594_1049508, (int)v30);
		v31 = sub_42F970("QuickBarSpellSetBase");
		sub_46AEA0(*(int*)&dword_5d4594_1049508, (int)v31);
		*(_DWORD*)(dword_5d4594_1049508 + 368) = 5;
		nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1049508, sub_45F8D0, sub_45F6F0, 0);
	} else {
		dword_5d4594_1049508 = nox_window_new(0, 1032, dword_5d4594_1047548 - 1, dword_5d4594_1047552 + 26, 61, 48, 0);
		sub_46AE40(*(int*)&dword_5d4594_1049508, 1, -26);
		v32 = sub_42F970("QuickBarWarriorLeft");
		sub_46AE60(*(int*)&dword_5d4594_1049508, (int)v32);
		v33 = sub_42F970("QuickBarWarriorLeft");
		sub_46AEA0(*(int*)&dword_5d4594_1049508, (int)v33);
		nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1049508, sub_45F8D0, sub_45F6F0, 0);
	}
	dword_5d4594_1049524 = nox_window_new(*(int*)&dword_5d4594_1049508, 1160, 0, 9, 29, 30, 0);
	v34 = sub_42F970("SpellbookButton");
	sub_46AE60(*(int*)&dword_5d4594_1049524, (int)v34);
	v35 = sub_42F970("SpellbookButtonLit");
	sub_46AEA0(*(int*)&dword_5d4594_1049524, (int)v35);
	*(_DWORD*)getMemAt(0x5D4594, 1049528) = nox_window_new(*(int*)&dword_5d4594_1049524, 1064, 1, 2, 28, 28, 0);
	nox_window_set_all_funcs(*(_DWORD**)getMemAt(0x5D4594, 1049528), sub_45F450, sub_45EF30, sub_45F3F0);
	v36 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 134692), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1931);
	sub_46B000((wchar_t*)(*(_DWORD*)getMemAt(0x5D4594, 1049528) + 36), v36);
	if (*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251)) {
		v37 = (wchar_t*)nox_window_new(*(int*)&dword_5d4594_1049508, 1032, 30, 0, 15, 19, 0);
		sub_46AE40((int)v37, -29, -26);
		sub_46AE60((int)v37, 0);
		v38 = sub_42F970("QuickBarSpellSetUpLit");
		sub_46AEA0((int)v37, (int)v38);
		nox_window_set_all_funcs(v37, sub_45F630, sub_45F6F0, 0);
		*((_DWORD*)v37 + 92) = 0;
		v39 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 134772), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1943);
		sub_46B000(v37 + 18, v39);
		v40 = (wchar_t*)nox_window_new(*(int*)&dword_5d4594_1049508, 1032, 30, 29, 15, 19, 0);
		sub_46AE40((int)v40, -29, -55);
		sub_46AE60((int)v40, 0);
		v41 = sub_42F970("QuickBarSpellSetDownLit");
		sub_46AEA0((int)v40, (int)v41);
		nox_window_set_all_funcs(v40, sub_45F630, sub_45F6F0, 0);
		*((_DWORD*)v40 + 92) = 1;
		v42 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 134856), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1953);
		sub_46B000(v40 + 18, v42);
		v43 = (wchar_t*)nox_window_new(*(int*)&dword_5d4594_1049508, 1032, 48, 16, 13, 17, 0);
		sub_46AE40((int)v43, -47, -42);
		sub_46AE60((int)v43, 0);
		v44 = sub_42F970("QuickBarSpellSetMaxLit");
		sub_46AEA0((int)v43, (int)v44);
		nox_window_set_all_funcs(v43, sub_45F630, sub_45F6F0, 0);
		*((_DWORD*)v43 + 92) = 2;
		v45 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 134940), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1963);
		sub_46B000(v43 + 18, v45);
		dword_5d4594_1049516 = nox_window_new(0, 1032, 0, 0, 1, 1, 0);
		nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1049516, sub_45EF40, sub_45F8F0, 0);
		dword_5d4594_1049512 =
			nox_window_new(0, 1152, *(int*)&dword_5d4594_1047548, *(int*)&dword_5d4594_1047552, 2, 2, 0);
		v46 = sub_42F970("QuickBarTitle");
		sub_46AE60(*(int*)&dword_5d4594_1049512, (int)v46);
		v47 = nox_window_new(*(int*)&dword_5d4594_1049512, 8, 115, 6, 101, 14, 0);
		nox_window_set_all_funcs(v47, 0, sub_45F9B0, 0);
	}
	v64 = 0;
	while (1) {
		v65 = 0;
		v66 = 0;
		v69 = 5;
		v48 = v64 << 8;
		v49 = *(_DWORD*)getMemAt(0x5D4594, v48 + 1048404);
		v71 = getMemAt(0x5D4594, v48 + 1048196);
		v50 = (int*)getMemAt(0x5D4594, v48 + 1048428);
		v51 = *(_DWORD*)(v49 + 16) + 10;
		v52 = *(_DWORD*)(v49 + 20) + 5;
		v67 = v51;
		for (i = v52;; v52 = i) {
			v53 = nox_window_new(0, 1160, v51, v52, 30, 10, 0);
			v63 = v0 + 1;
			if (*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251)) {
				nox_sprintf(v72, "QuickBarNugget%d", v63);
				v54 = sub_42F970(v72);
				sub_46AE60((int)v53, (int)v54);
				*(_DWORD*)&v72[strlen(v72)] = *(_DWORD*)getMemAt(0x587000, 134996);
				v55 = sub_42F970(v72);
				sub_46AEA0((int)v53, (int)v55);
				v51 = v67;
			} else {
				nox_sprintf(v72, "QuickBarWarriorNugget%d", v63);
				v56 = sub_42F970(v72);
				sub_46AE60((int)v53, (int)v56);
				v57 = sub_42F970(v72);
				sub_46AEA0((int)v53, (int)v57);
			}
			sub_46AE40((int)v53, -70 - v65, -23);
			nox_window_set_all_funcs(v53, sub_45F8D0, 0, 0);
			*v50 = (int)v53;
			sub_45DE10(v0, (int)v71);
			if (*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251)) {
				v58 = nox_window_new(*v50, 1032, 12, 0, 10, 10, 0);
				nox_window_set_all_funcs(v58, sub_45F520, sub_45EF30, sub_45F480);
				v58[92] = v0 | (v64 << 16);
			}
			if (v64 == 4) {
				v59 = nox_window_new(*(_DWORD*)getMemAt(0x5D4594, v66 + 1049452), 1032, 13, 39, 10, 10, 0);
				nox_window_set_all_funcs(v59, 0, sub_45F5D0, 0);
				v59[92] = v0++;
			} else {
				nox_window_set_hidden(*v50, 1);
			}
			++v50;
			v60 = *(_DWORD*)getMemAt(0x587000, v66 + 133488);
			v51 += v60;
			v67 = v51;
			v61 = v69 == 1;
			v65 += v60;
			v66 += 4;
			--v69;
			if (v61)
				break;
		}
		if (++v64 >= 5u)
			break;
		v0 = 0;
	}
	if (!*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251)) {
		for (j = 0; j < 120; j += 24) {
			*(_DWORD*)getMemAt(0x5D4594, j + 1047788) = *(_DWORD*)getMemAt(0x587000, j + 133536);
			*(_DWORD*)getMemAt(0x5D4594, j + 1047792) = *(_DWORD*)getMemAt(0x587000, j + 133540);
			*(_DWORD*)getMemAt(0x5D4594, j + 1047796) = *(_DWORD*)getMemAt(0x587000, j + 133544);
			*(_DWORD*)getMemAt(0x5D4594, j + 1047800) = *(_DWORD*)getMemAt(0x587000, j + 133548);
			*(_DWORD*)getMemAt(0x5D4594, j + 1047804) = *(_DWORD*)getMemAt(0x587000, j + 133552);
			*(_DWORD*)getMemAt(0x5D4594, j + 1047808) = 0;
		}
	}
	sub_45E110(0);
	return 1;
}

//----- (0045F3F0) --------------------------------------------------------
int sub_45F3F0() {
	wchar_t* v0; // eax

	if (sub_45CFC0())
		v0 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 135064), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 901);
	else
		v0 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 135124), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 905);
	sub_4776B0(v0);
	return 1;
}

//----- (0045F480) --------------------------------------------------------
int __cdecl sub_45F480(int a1) {
	wchar_t* v1; // eax

	if (sub_45F500(*(unsigned __int16*)(a1 + 368),
				   (int)getMemAt(0x5D4594, 256 * ((unsigned __int16)(*(_DWORD*)(a1 + 368) >> 16)) + 1048196))) {
		v1 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 135180), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 941);
	} else {
		v1 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 135236), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 945);
	}
	sub_4776B0(v1);
	return 1;
}

//----- (0045F9B0) --------------------------------------------------------
int __cdecl sub_45F9B0(_DWORD* a1) {
	_DWORD* v1;      // esi
	wchar_t* v2;     // eax
	char* v3;        // esi
	int v5;          // [esp-8h] [ebp-5Ch]
	int v6;          // [esp+0h] [ebp-54h]
	int v7;          // [esp+4h] [ebp-50h]
	int v8;          // [esp+8h] [ebp-4Ch]
	int v9;          // [esp+Ch] [ebp-48h]
	int v10;         // [esp+10h] [ebp-44h]
	wchar_t v11[32]; // [esp+14h] [ebp-40h]

	if (!*(_DWORD*)getMemAt(0x5D4594, 1049476)) {
		v1 = a1;
		nox_client_wndGetPosition_46AA60(a1, &v6, &a1);
		nox_window_get_size((int)v1, &v7, &v9);
		v5 = *(unsigned __int8*)(dword_587000_133480 + 200) + 1;
		v2 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 135296), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1276);
		nox_swprintf(v11, v2, v5);
		sub_43F840(0, v11, &v8, &v10, 0);
		v3 = (char*)a1 - sub_43F320(0);
		a1 = &v3[sub_43F320(*(int*)getMemAt(0x5D4594, 1049684)) + 1];
		v6 += (v7 - v8) / 2;
		sub_434390(*(int*)getMemAt(0x5D4594, 2523948));
		sub_4343E0(*(int*)getMemAt(0x5D4594, 2614248));
		sub_43F730(0, (__int16*)v11, v6, (int)a1);
	}
	return 1;
}

//----- (0045FAC0) --------------------------------------------------------
int __cdecl sub_45FAC0(_DWORD* a1) {
	_DWORD* v1;     // esi
	wchar_t* v2;    // eax
	int v4;         // [esp-4h] [ebp-58h]
	int v5;         // [esp+4h] [ebp-50h]
	int v6;         // [esp+8h] [ebp-4Ch]
	int v7;         // [esp+Ch] [ebp-48h]
	int v8;         // [esp+10h] [ebp-44h]
	wchar_t v9[32]; // [esp+14h] [ebp-40h]

	v1 = a1;
	nox_client_wndGetPosition_46AA60(a1, &a1, &v7);
	nox_window_get_size((int)v1, &v5, &v8);
	v4 = getMemByte(0x5D4594, 1048140) + 1;
	v2 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 135348), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1299);
	nox_swprintf(v9, v2, v4);
	sub_43F840(0, v9, &v6, 0, 0);
	a1 = (_DWORD*)((char*)a1 + (v5 - v6) / 2);
	sub_434390(*(int*)getMemAt(0x5D4594, 2523948));
	sub_4343E0(*(int*)getMemAt(0x5D4594, 2614248));
	sub_43F730(0, (__int16*)v9, (int)a1, v7);
	return 1;
}

//----- (0045FBD0) --------------------------------------------------------
int __cdecl sub_45FBD0(int yTop) {
	int v1;           // ebx
	int v2;           // esi
	_DWORD* v3;       // eax
	int v5;           // ebp
	int v6;           // eax
	int* v7;          // edi
	int v8;           // eax
	int v9;           // esi
	wchar_t* v10;     // eax
	__int16* v11;     // eax
	wchar_t* v12;     // eax
	int v13;          // eax
	unsigned int v14; // eax
	int v15;          // [esp-10h] [ebp-20h]
	int v16;          // [esp-Ch] [ebp-1Ch]
	int v17;          // [esp-Ch] [ebp-1Ch]
	int xLeft;        // [esp+8h] [ebp-8h]
	int v19;          // [esp+Ch] [ebp-4h]

	v1 = yTop;
	v2 = 0;
	v3 = (_DWORD*)(*(_DWORD*)(yTop + 368) + 212);
	do {
		if (yTop == *v3)
			break;
		++v2;
		++v3;
	} while (v2 < 5);
	if (v2 == 5)
		return 0;
	nox_client_wndGetPosition_46AA60((_DWORD*)yTop, &xLeft, &yTop);
	v5 = sub_43F320(0);
	v6 = *(_DWORD*)(dword_587000_133480 + 204);
	v7 = (int*)(v6 + 8 * v2);
	v8 = *(_DWORD*)(v6 + 8 * v2);
	if (v8) {
		if (*(_DWORD*)getMemAt(0x5D4594, 2598000) <= 0xAu || v2 != *(_DWORD*)getMemAt(0x587000, 133484) ||
			(unsigned int)(*(_DWORD*)getMemAt(0x5D4594, 2598000) - *(_DWORD*)getMemAt(0x5D4594, 1049540)) >= 0xA) {
			v9 = sub_425310(v8, 0);
			v19 = 0;
		} else {
			v9 = sub_425310(v8, 1);
			v19 = 1;
		}
		v16 = *v7;
		if (*(_DWORD*)getMemAt(0x5D4594, 24 * *v7 + 1047776)) {
			v10 = (wchar_t*)sub_425260(v16);
			sub_46B000((wchar_t*)(v1 + 36), v10);
			if (v9) {
			LABEL_14:
				nox_client_drawImageAt_47D2C0(v9, xLeft, yTop);
			LABEL_19:
				v13 = 24 * *v7;
				if (*(_DWORD*)getMemAt(0x5D4594, v13 + 1047776) || !*(_DWORD*)getMemAt(0x5D4594, v13 + 1047772) || sub_4372B0()) {
					v14 = sub_4252D0(*v7);
					if (v14 / *(_DWORD*)getMemAt(0x5D4594, 2649704)) {
						if (!v19)
							nox_client_drawRectFilledAlpha_49CF10(
								xLeft, yTop, 34,
								34 - (*(_DWORD*)getMemAt(0x5D4594, 2598000) - *(_DWORD*)getMemAt(0x5D4594, 24 * *v7 + 1047784)) /
										 (v14 / *(_DWORD*)getMemAt(0x5D4594, 2649704)));
					}
				}
				return 1;
			}
			sub_434390(*(int*)getMemAt(0x5D4594, 2523948));
			v17 = yTop + v5 + 2;
			v15 = xLeft + 6;
			v11 = (__int16*)loadString_sub_40F1D0((char*)getMemAt(0x587000, 135396), 0,
												  "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1388);
		} else {
			v12 = (wchar_t*)sub_425260(v16);
			sub_46B000((wchar_t*)(v1 + 36), v12);
			if (v9)
				goto LABEL_14;
			sub_434390(*(int*)getMemAt(0x5D4594, 2523948));
			v17 = yTop + v5 + 2;
			v15 = xLeft + 6;
			v11 = (__int16*)loadString_sub_40F1D0((char*)getMemAt(0x587000, 135444), 0,
												  "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1401);
		}
		sub_43F6E0(0, v11, v15, v17);
		goto LABEL_19;
	}
	return 1;
}

//----- (0045FDE0) --------------------------------------------------------
int __cdecl sub_45FDE0(int yTop) {
	int v1;               // edi
	int v2;               // esi
	unsigned __int8* v3;  // eax
	int* v4;              // ebx
	_DWORD* v5;           // eax
	int v7;               // eax
	int v8;               // ecx
	int v9;               // ebp
	unsigned __int8 v10;  // al
	wchar_t* v11;         // eax
	__int16* v12;         // eax
	int v13;              // ebp
	int v14;              // edi
	int* v15;             // edi
	int v16;              // [esp-Ch] [ebp-24h]
	int v17;              // [esp-8h] [ebp-20h]
	int xLeft;            // [esp+Ch] [ebp-Ch]
	unsigned __int8* v19; // [esp+10h] [ebp-8h]
	int v20;              // [esp+14h] [ebp-4h]

	v1 = yTop;
	v2 = 0;
	v3 = *(unsigned __int8**)(yTop + 368);
	v19 = v3;
	v4 = (int*)*((_DWORD*)v3 + 51);
	v5 = v3 + 212;
	do {
		if (yTop == *v5)
			break;
		++v2;
		++v5;
	} while (v2 < 5);
	if (v2 == 5)
		return 0;
	nox_client_wndGetPosition_46AA60((_DWORD*)yTop, &xLeft, &yTop);
	if (v4[2 * v2]) {
		if (*(_DWORD*)getMemAt(0x5D4594, 2598000) <= 0xAu || v2 != *(_DWORD*)getMemAt(0x587000, 133484) ||
			(unsigned int)(*(_DWORD*)getMemAt(0x5D4594, 2598000) - *(_DWORD*)getMemAt(0x5D4594, 1049540)) >= 0xA) {
			v7 = sub_424A90(v4[2 * v2]);
		} else {
			v7 = sub_424AB0(v4[2 * v2]);
		}
		v8 = v4[2 * v2];
		v9 = v7;
		v10 = getMemByte(0x5D4594, v8 + 1049544);
		if ((char)v10 > 0)
			*getMemAt( 0x5D4594, v8 + 1049544) = v10 - 1;
		v11 = (wchar_t*)sub_424930(v4[2 * v2]);
		sub_46B000((wchar_t*)(v1 + 36), v11);
		if (v9) {
			nox_client_drawImageAt_47D2C0(v9, xLeft, yTop);
		} else {
			sub_434390(*(int*)getMemAt(0x5D4594, 2523948));
			v17 = sub_43F320(0) + yTop + 2;
			v16 = xLeft + 6;
			v12 = (__int16*)loadString_sub_40F1D0((char*)getMemAt(0x587000, 135492), 0,
												  "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1491);
			sub_43F6E0(0, v12, v16, v17);
		}
		v13 = sub_470DD0();
		v14 = sub_4249A0(v4[2 * v2], 1);
		v20 = v14;
		if (v19 == getMemAt(0x5D4594, 1047940) && v2 > 0) {
			v15 = v4;
			v19 = (unsigned __int8*)v2;
			do {
				if (*v15)
					v13 -= sub_4249A0(*v15, 2);
				v15 += 2;
				--v19;
			} while (v19);
			v14 = v20;
		}
		if (!sub_424B70(v4[2 * v2]) || sub_4372B0() || sub_4356C0(*(int*)getMemAt(0x5D4594, 2614252), 29)) {
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, 30, 30);
			return 1;
		}
		if (v13 < v14 && v14) {
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, 30, 30 * (v14 - v13) / v14);
			return 1;
		}
	} else {
		sub_46B000((wchar_t*)(v1 + 36), (wchar_t*)getMemAt(0x5D4594, 1049716));
	}
	return 1;
}

//----- (00460070) --------------------------------------------------------
int sub_460070() {
	int result;  // eax
	char* v1;    // eax
	char* v2;    // eax
	wchar_t* v3; // eax
	wchar_t* v4; // eax
	char* v5;    // eax
	char* v6;    // eax
	wchar_t* v7; // eax
	wchar_t* v8; // eax

	result = *(_DWORD*)getMemAt(0x5D4594, 2618908);
	if (*(_DWORD*)getMemAt(0x5D4594, 2618908)) {
		if (*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251) == 1) {
			v5 = sub_42F970("QuickBarTrap");
			sub_46AE60(*(int*)&dword_5d4594_1049504, (int)v5);
			v6 = sub_42F970("QuickBarTrapHit");
			sub_46AEA0(*(int*)&dword_5d4594_1049504, (int)v6);
			v7 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 135572), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c",
									   1544);
			sub_46B000((wchar_t*)(dword_5d4594_1049520 + 36), v7);
			sub_46AD60(*(int*)&dword_5d4594_1049520, 8);
			v8 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 135628), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c",
									   1547);
			sub_46B000((wchar_t*)(dword_5d4594_1049500 + 36), v8);
			sub_46AD60(*(int*)&dword_5d4594_1049500, 8);
			result = sub_46B340(*(int*)&dword_5d4594_1049500, 0);
		} else {
			result = *(unsigned __int8*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251) - 2;
			if (*(_BYTE*)(*(_DWORD*)getMemAt(0x5D4594, 2618908) + 2251) == 2) {
				v1 = sub_42F970("QuickBarBomber");
				sub_46AE60(*(int*)&dword_5d4594_1049504, (int)v1);
				v2 = sub_42F970("QuickBarBomberHit");
				sub_46AEA0(*(int*)&dword_5d4594_1049504, (int)v2);
				v3 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 135728), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c",
										   1559);
				sub_46B000((wchar_t*)(dword_5d4594_1049520 + 36), v3);
				sub_46AD60(*(int*)&dword_5d4594_1049520, 8);
				v4 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 135788), 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c",
										   1562);
				sub_46B000((wchar_t*)(dword_5d4594_1049500 + 36), v4);
				sub_46AD60(*(int*)&dword_5d4594_1049500, 8);
				result = sub_46B340(*(int*)&dword_5d4594_1049500, 0);
			}
		}
	}
	return result;
}

//----- (00460EC0) --------------------------------------------------------
_DWORD* __cdecl sub_460EC0(int a1) {
	_DWORD* result; // eax
	int v2;         // esi
	int v3;         // eax
	int v4;         // [esp-24h] [ebp-24h]
	int v5;         // [esp-20h] [ebp-20h]
	int v6;         // [esp-1Ch] [ebp-1Ch]
	char v7;        // [esp-14h] [ebp-14h]
	char v8;        // [esp-10h] [ebp-10h]

	if (!a1)
		return (_DWORD*)sub_460070();
	result = *(_DWORD**)&dword_5d4594_1049500;
	if (!(*(_BYTE*)(dword_5d4594_1049500 + 4) & 8)) {
		v2 = 50;
		dword_5d4594_1049536 = nox_win_height + 1;
		do {
			v8 = sub_415FF0(4, 6, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2732);
			v7 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2731);
			v6 = sub_415FF0(-20, -5, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2729);
			v5 = sub_415FF0(-5, 5, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2728);
			v4 = sub_415FF0(0, 20, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2727) +
				 *(_DWORD*)(dword_5d4594_1049504 + 20) + 10;
			v3 = sub_415FF0(0, 20, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2726);
			result = nox_client_newScreenParticle_431540(0, v3 + *(_DWORD*)(dword_5d4594_1049504 + 16) + 10, v4, v5, v6, 1, v7, v8, 2, 1);
			--v2;
		} while (v2);
	}
	return result;
}
