#include "guisave.h"

#include "../../proto.h"

extern _DWORD dword_5d4594_1082868;
extern _DWORD dword_5d4594_1082860;
extern _DWORD dword_5d4594_1082864;
extern _DWORD dword_5d4594_1082856;
extern int nox_win_width;
extern int nox_win_height;

//----- (0046C730) --------------------------------------------------------
int sub_46C730() {
	int result;  // eax
	_DWORD* v1;  // eax
	_DWORD* v2;  // eax
	int i;       // esi
	_DWORD* v4;  // eax
	wchar_t* v5; // eax
	wchar_t* v6; // eax

	result = nox_new_window_from_file("SelChar.wnd", sub_46C920);
	dword_5d4594_1082856 = result;
	if (result) {
		*(_DWORD*)(result + 4) |= 0x20u;
		sub_46B300(*(int*)&dword_5d4594_1082856, sub_46CCA0);
		dword_5d4594_1082860 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 510);
		dword_5d4594_1082864 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 511);
		dword_5d4594_1082868 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 512);
		sub_46B2C0(*(int*)&dword_5d4594_1082860, sub_46C920);
		sub_46B120(*(_DWORD**)&dword_5d4594_1082864, *(int*)&dword_5d4594_1082860);
		sub_46B120(*(_DWORD**)&dword_5d4594_1082868, *(int*)&dword_5d4594_1082860);
		*(_DWORD*)&byte_5D4594[1082872] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 501);
		*(_DWORD*)&byte_5D4594[1082876] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 502);
		*(_DWORD*)&byte_5D4594[1082880] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 503);
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 504);
		nox_window_set_hidden((int)v1, 1);
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 505);
		nox_window_set_hidden((int)v2, 1);
		for (i = 500; i <= 512; ++i) {
			v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, i);
			if (v4)
				sub_46AD60((int)v4, 1024);
		}
		v5 = loadString_sub_40F1D0((char*)&byte_587000[143360], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 341);
		sub_46AEE0(*(int*)&byte_5D4594[1082872], (int)v5);
		v6 = loadString_sub_40F1D0((char*)&byte_587000[143408], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 342);
		sub_46AEE0(*(int*)&byte_5D4594[1082876], (int)v6);
		sub_46A9B0(*(_DWORD**)&dword_5d4594_1082856, (nox_win_width - *(int*)(dword_5d4594_1082856 + 8)) / 2, 0);
		nox_window_set_hidden(*(int*)&dword_5d4594_1082856, 1);
		sub_46ABB0(*(int*)&dword_5d4594_1082856, 0);
		result = 1;
	}
	return result;
}

//----- (0046C920) --------------------------------------------------------
int __cdecl sub_46C920(_DWORD* a1, int a2, int* a3, int a4) {
	int v5;       // esi
	int v6;       // eax
	wchar_t* v7;  // eax
	int v8;       // edx
	int v9;       // eax
	_DWORD* v10;  // eax
	wchar_t* v11; // eax
	wchar_t* v12; // [esp-10h] [ebp-24h]
	wchar_t* v13; // [esp-10h] [ebp-24h]
	char v14[12]; // [esp+8h] [ebp-Ch]

	if (a2 != 16391) {
		if (a2 != 16400) {
			return 0;
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_1082860, 16403, a4, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1082864, 16403, a4, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1082868, 16403, a4, 0);
		return 0;
	}
	v5 = sub_46B0A0(a3);
	sub_452D80(766, 100);
	if (v5 == 501) {
		v8 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_1082864 + 32) + 48);
		if (v8 < 0) {
			return 0;
		}
		v9 = *(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 120);
		if ((v9 & 0x8000) != 0) {
			v10 = sub_46B0C0(a1, 501);
			sub_46ABB0((int)v10, 0);
			return 0;
		}
		if (strlen((const char*)&byte_5D4594[1278 * v8 + 1064952])) {
			sub_4DC970((char*)&byte_5D4594[1278 * v8 + 1064952], (char*)&byte_5D4594[1082840]);
			sub_46ADE0(*(int*)&dword_5d4594_1082856);
			v13 = loadString_sub_40F1D0((char*)&byte_587000[143456], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c",
										184);
			v11 = loadString_sub_40F1D0((char*)&byte_587000[143524], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c",
										183);
			sub_449A10(*(int*)&dword_5d4594_1082856, (int)v11, (int)v13, 56, sub_46CC70, sub_46CC90);
			return 0;
		}
		if (v8)
			nox_sprintf(v14, "SAVE%04d", v8);
		else
			strcpy(v14, "AUTOSAVE");
		sub_4DB130(v14);
		sub_4DB170(1, 0, 0);
		sub_46D6F0();
		return 0;
	} else if (v5 == 502) {
		v6 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_1082864 + 32) + 48);
		if (v6 >= 0 && strlen((const char*)&byte_5D4594[1278 * v6 + 1064952])) {
			if (sub_4372B0()) {
				sub_46CBD0();
				return 0;
			}
			v12 =
					loadString_sub_40F1D0((char*)&byte_587000[143616], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 233);
			v7 = loadString_sub_40F1D0((char*)&byte_587000[143680], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 232);
			sub_449A10(0, (int)v7, (int)v12, 24, sub_46CBD0, sub_44A400);
			return 0;
		}
		sub_452D80(925, 100);
		return 0;
	} else if (v5 == 503) {
		if (sub_450560()) {
			sub_450580();
			sub_43DDA0();
			sub_43DDD0(0);
			sub_43DE60();
			sub_446060();
			sub_46D6F0();
			return 0;
		}
		sub_46D6F0();
		return 0;
	}
	return 0;
}

//----- (0046CBD0) --------------------------------------------------------
int sub_46CBD0() {
	int result;  // eax
	wchar_t* v1; // eax
	wchar_t* v2; // [esp-Ch] [ebp-1Ch]
	char v3[12]; // [esp+4h] [ebp-Ch]

	result = 0;
	if (strlen((const char*)&byte_5D4594[1278 * *(_DWORD*)(*(_DWORD*)(dword_5d4594_1082864 + 32) + 48) + 1064952])) {
		sub_4DC970((char*)&byte_5D4594[1278 * *(_DWORD*)(*(_DWORD*)(dword_5d4594_1082864 + 32) + 48) + 1064952], v3);
		if (!sub_4DB790(v3)) {
			v2 = loadString_sub_40F1D0((char*)&byte_587000[143736], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 75);
			v1 = loadString_sub_40F1D0((char*)&byte_587000[143788], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 74);
			sub_449A10(0, (int)v1, (int)v2, 33, 0, 0);
		}
		if (sub_450560())
			sub_4505B0();
		sub_44A400();
		result = sub_46D6F0();
	}
	return result;
}

//----- (0046CE40) --------------------------------------------------------
int __cdecl sub_46CE40(int a1, int a2, int a3, _BYTE* a4) {
	int v4;              // ebp
	char* v5;            // eax
	_BYTE* v6;           // ebx
	int v7;              // esi
	_BYTE* v8;           // edi
	int v9;              // esi
	int v10;             // ebx
	int v21;             // esi
	_DWORD* v22;         // eax
	_DWORD* v23;         // eax
	_DWORD* v24;         // eax
	int result;          // eax
	int v26;             // esi
	int v40;             // [esp+14h] [ebp-1210h]
	char v41[12];        // [esp+18h] [ebp-120Ch]
	wchar_t v42[512];    // [esp+24h] [ebp-1200h]
	CHAR DateStr[256];   // [esp+424h] [ebp-E00h]
	CHAR TimeStr[256];   // [esp+524h] [ebp-D00h]
	char v45[1024];      // [esp+624h] [ebp-C00h]
	CHAR PathName[1024]; // [esp+A24h] [ebp-800h]
	CHAR Buffer[1024];   // [esp+E24h] [ebp-400h]

	v4 = 0;
	GetCurrentDirectoryA(0x400u, &Buffer);
	v5 = sub_409E10();
	nox_sprintf(&PathName, "%s\\Save\\", v5);
	CreateDirectoryA(&PathName, 0);
	nox_window_call_field_94(a1, 16399, 0, 0);
	nox_window_call_field_94(a2, 16399, 0, 0);
	nox_window_call_field_94(a3, 16399, 0, 0);
	nox_sprintf(&v45, "%sAUTOSAVE\\Player.plr", &PathName);
	v6 = a4;
	if (sub_41A000(&v45, a4))
		v4 = 1;
	v7 = 1;
	v8 = a4 + 1278;
	do {
		nox_sprintf(&v45, "%sSAVE%04d\\Player.plr", &PathName, v7);
		if (sub_41A000(&v45, v8))
			++v4;
		++v7;
		v8 += 1278;
	} while (v7 < 14);
	v9 = 0;
	v40 = 0;
	while (1) {
		v10 = (int)&v6[1278 * v9];
		if (strlen((const char*)(v10 + 4))) {
			sub_4DC970((char*)(v10 + 4), &v41);
			nox_sprintf(&DateStr, "nox.str:%s", *(_DWORD*)&byte_587000[4 * *(unsigned __int8*)(v10 + 1274) + 29456]);
			wchar_t* v39 = loadString_sub_40F1D0(&DateStr, 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 667);
			wchar_t* v13 =
				loadString_sub_40F1D0((char*)&byte_587000[144092], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 666);
			nox_swprintf(&v42, v13, v10 + 1224, v39);
			if (!strcmp(&v41, "AUTOSAVE")) {
				nox_wcscat(&v42, L" ");
				wchar_t* v14 = loadString_sub_40F1D0((char*)&byte_587000[144148], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c",
											674);
				nox_wcscat(&v42, v14);
			} else {
				nox_wcscat(&v42, L" - ");
				wchar_t* v17;
				switch (*(_BYTE *) (v10 + 1277)) {
				case 1:;
					char v16 = *(_BYTE *) (v10 + 1274);
					if (!v16) {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[144208], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 688);
					} else if (v16 != 1) {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[144316], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 692);
					} else {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[144268], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 690);
					}
					break;
				case 2:;
					char v18 = *(_BYTE *) (v10 + 1274);
					if (!v18) {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[144376], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 699);
					} else if (v18 != 1) {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[144488], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 703);
					} else {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[144432], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 701);
					}
					break;
				case 3:;
					char v19 = *(_BYTE *) (v10 + 1274);
					if (!v19) {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[144536], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 710);
					} else if (v19 != 1) {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[144656], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 714);
					} else {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[144596], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 712);
					}
					break;
				case 4:
					v17 = loadString_sub_40F1D0((char *) &byte_587000[144712], 0,
												"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 718);
					break;
				case 5:
					v17 = loadString_sub_40F1D0((char *) &byte_587000[144772], 0,
												"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 720);
					break;
				case 6:
					v17 = loadString_sub_40F1D0((char *) &byte_587000[144832], 0,
												"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 722);
					break;
				case 7:
					v17 = loadString_sub_40F1D0((char *) &byte_587000[144884], 0,
												"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 724);
					break;
				case 8:
					v17 = loadString_sub_40F1D0((char *) &byte_587000[144940], 0,
												"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 726);
					break;
				case 9:
					v17 = loadString_sub_40F1D0((char *) &byte_587000[145000], 0,
												"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 728);
					break;
				case 10:;
					v17 = loadString_sub_40F1D0((char *) &byte_587000[145064], 0,
												"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 730);
					break;
				case 11:;
					char v20 = *(_BYTE *) (v10 + 1274);
					if (!v20) {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[145124], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 735);
					} else if (v20 == 1) {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[145184], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 737);
					} else {
						v17 = loadString_sub_40F1D0((char *) &byte_587000[145232], 0,
													"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 739);
					}
					break;
				default:
					v17 = loadString_sub_40F1D0((char *) &byte_587000[145292], 0,
												"C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 743);
					break;
				}
				nox_wcscat(&v42, v17);
			}
			v21 = sub_46CD70((_BYTE*)v10);
			nox_window_call_field_94(a1, 16397, (int)&byte_587000[145320], v21);
			nox_window_call_field_94(a3, 16397, (int)&v42, v21);
			GetDateFormatA(0x800u, 1u, (const SYSTEMTIME*)(v10 + 1188), 0, &DateStr, 256);
			GetTimeFormatA(0x800u, 0xEu, (const SYSTEMTIME*)(v10 + 1188), 0, &TimeStr, 256);
			nox_swprintf(&v42, L"%S, %S ", &DateStr, &TimeStr);
			nox_window_call_field_94(a2, 16397, (int)&v42, v21);
			v9 = v40;
		} else {
			nox_window_call_field_94(a1, 16397, (int) &byte_587000[143900], 3);
			if (v9) {
				wchar_t* v11 =
						loadString_sub_40F1D0((char *) &byte_587000[143948], 0,
											  "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 645);
				nox_window_call_field_94(a2, 16397, (int) v11, 3);
				wchar_t* v12 =
						loadString_sub_40F1D0((char *) &byte_587000[143996], 0,
											  "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 650);
				nox_window_call_field_94(a3, 16397, (int) v12, 3);
			} else {
				nox_window_call_field_94(a2, 16397, (int) &byte_587000[143904], 3);
				nox_window_call_field_94(a3, 16397, (int) &byte_587000[143908], 3);
			}
		}
		v40 = ++v9;
		if (v9 >= 14)
			break;
		v6 = a4;
	}
	v22 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 503);
	if (v4 <= 0) {
		sub_46ABB0((int)v22, 0);
		v24 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 502);
		sub_46ABB0((int)v24, 0);
		sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 501);
	} else {
		sub_46ABB0((int)v22, 1);
		v23 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 502);
		sub_46ABB0((int)v23, 1);
	}
	result = sub_46CDC0((int)a4);
	v26 = result;
	if (result != -1) {
		nox_window_call_field_94(a1, 16403, result, 0);
		nox_window_call_field_94(a2, 16403, v26, 0);
		result = nox_window_call_field_94(a3, 16403, v26, 0);
	}
	return result;
}

//----- (0046D580) --------------------------------------------------------
int sub_46D580() {
	int result;  // eax
	_DWORD* v1;  // esi
	int v2;      // eax
	wchar_t* v3; // eax
	_DWORD* v4;  // esi
	wchar_t* v5; // eax
	wchar_t* v6; // eax

	result = nox_common_gameFlags_check_40A5C0(4096);
	if (!result) {
		memset(&byte_5D4594[1064948], 0, 0x45E4u);
		sub_46CE40(*(int*)&dword_5d4594_1082860, *(int*)&dword_5d4594_1082864, *(int*)&dword_5d4594_1082868,
				   &byte_5D4594[1064948]);
		sub_46A8C0(*(int*)&dword_5d4594_1082856);
		sub_46ABB0(*(int*)&dword_5d4594_1082856, 1);
		sub_46ADC0(*(int*)&dword_5d4594_1082856);
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 501);
		if (sub_450560() && !sub_450570() || (v2 = *(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 276), v2 == 2) ||
			v2 == 1 || v2 == 51) {
			sub_46ABB0((int)v1, 0);
		} else {
			sub_46ABB0((int)v1, 1);
		}
		if (sub_450560()) {
			v3 = loadString_sub_40F1D0((char*)&byte_587000[145376], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 860);
			sub_46AEE0(*(int*)&byte_5D4594[1082880], (int)v3);
			v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 509);
			v5 = loadString_sub_40F1D0((char*)&byte_587000[145424], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 862);
		} else {
			v6 = loadString_sub_40F1D0((char*)&byte_587000[145472], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 866);
			sub_46AEE0(*(int*)&byte_5D4594[1082880], (int)v6);
			v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1082856, 509);
			v5 = loadString_sub_40F1D0((char*)&byte_587000[145524], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 868);
		}
		sub_46AEE0((int)v4, (int)v5);
		result = sub_413A00(1);
	}
	return result;
}
