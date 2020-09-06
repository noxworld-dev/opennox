#include "guibook.h"

#include "../../proto.h"
#include "guimsg.h"

extern _DWORD dword_5d4594_1046852;
extern _DWORD dword_5d4594_1046652;
extern _DWORD dword_5d4594_1047524;
extern _DWORD dword_5d4594_1046944;
extern _DWORD dword_5d4594_1046648;
extern _DWORD dword_5d4594_1046640;
extern _DWORD dword_5d4594_1046624;
extern _DWORD dword_5d4594_1046932;
extern _DWORD dword_5d4594_1046948;
extern _DWORD dword_5d4594_1046636;
extern _DWORD dword_5d4594_1046928;
extern _DWORD dword_5d4594_1047512;
extern _DWORD dword_5d4594_1046656;
extern _DWORD dword_5d4594_1046924;
extern _DWORD dword_5d4594_1047520;
extern _DWORD dword_587000_132132;
extern _DWORD dword_5d4594_1046936;
extern _DWORD dword_5d4594_1046872;
extern _DWORD dword_5d4594_1047516;
extern _DWORD dword_5d4594_1046868;
extern int nox_win_width;
extern int nox_win_height;

//----- (0045AD70) --------------------------------------------------------
unsigned int __cdecl sub_45AD70(int a1) {
	unsigned int result; // eax
	wchar_t* v2;         // eax

	result = sub_477600();
	if (!result) {
		if (!sub_4372B0() || (result = nox_common_gameFlags_check_40A5C0(2048)) == 0) {
			if (!*getMemU32Ptr(0x5D4594, 2618908) ||
				sub_45ADF0(*(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 2618908) + 2251))) {
				result = sub_45B010(a1);
			} else {
				v2 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 132176), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c",
										   377);
				sub_445490(v2);
				result = (unsigned int)sub_452D80(925, 100);
			}
		}
	}
	return result;
}

//----- (0045BD40) --------------------------------------------------------
int __cdecl sub_45BD40(int a1) {
	int v1;                // esi
	int v2;                // ebp
	int v3;                // edi
	int v4;                // esi
	int v5;                // ebx
	int v6;                // ebp
	int v7;                // edi
	int v8;                // esi
	char v9;               // cl
	unsigned __int16* v10; // eax
	__int16* v11;          // eax
	unsigned __int16* v12; // eax
	unsigned __int16* v13; // eax
	int v14;               // esi
	wchar_t* v15;          // eax
	int v16;               // eax
	int v17;               // eax
	int v18;               // ebp
	wchar_t* v19;          // eax
	int v20;               // ebx
	wchar_t* v21;          // eax
	wchar_t* v22;          // eax
	int v23;               // esi
	unsigned __int16* v24; // eax
	int v25;               // eax
	_WORD* v26;            // eax
	int v27;               // eax
	unsigned __int16* v28; // eax
	unsigned __int16* v29; // esi
	int v30;               // edi
	int v31;               // edx
	int v32;               // ecx
	unsigned __int16* v33; // eax
	int v34;               // ecx
	_WORD* v35;            // eax
	unsigned __int16* v36; // eax
	int v37;               // eax
	__int16 v38;           // bx
	unsigned __int16* v39; // eax
	int v40;               // eax
	int v41;               // esi
	_WORD* v42;            // eax
	int v43;               // esi
	int v44;               // ebp
	wchar_t* v45;          // eax
	int v46;               // esi
	int v47;               // esi
	unsigned __int16* v48; // ebp
	unsigned __int16* v49; // ebp
	unsigned __int16* v50; // ebp
	unsigned __int16* v51; // ebp
	wchar_t* v52;          // eax
	unsigned __int16* v53; // eax
	int v55;               // [esp-10h] [ebp-23Ch]
	int v56;               // [esp-10h] [ebp-23Ch]
	int v57;               // [esp-10h] [ebp-23Ch]
	int v58;               // [esp-Ch] [ebp-238h]
	int v59;               // [esp-Ch] [ebp-238h]
	int v60;               // [esp-8h] [ebp-234h]
	int v61;               // [esp-8h] [ebp-234h]
	int v62;               // [esp-4h] [ebp-230h]
	int v63;               // [esp-4h] [ebp-230h]
	int v64;               // [esp-4h] [ebp-230h]
	int v65;               // [esp+10h] [ebp-21Ch]
	int v66;               // [esp+14h] [ebp-218h]
	int v67;               // [esp+18h] [ebp-214h]
	int v68;               // [esp+1Ch] [ebp-210h]
	WCHAR WideCharStr[4];  // [esp+20h] [ebp-20Ch]
	int v70;               // [esp+28h] [ebp-204h]
	wchar_t v71[256];      // [esp+2Ch] [ebp-200h]

	sub_46AA20(a1, &v66, &v67);
	v1 = v66 - 24;
	v2 = v67 - 76;
	v3 = sub_43F320(0);
	dword_5d4594_1046656 = v3 + 2;
	sub_434390(*(int*)getMemAt(0x5D4594, 1046880));
	nox_client_drawImageAt_47D2C0(*(int*)getMemAt(0x5D4594, 1046856), v1, v2);
	if (dword_5d4594_1046872)
		nox_client_drawImageAt_47D2C0(*(int*)getMemAt(0x5D4594, 1046660), v1, v2);
	else
		nox_client_drawImageAt_47D2C0(*(int*)getMemAt(0x5D4594, 1046644), v1, v2);
	if (dword_5d4594_1046868 == 3) {
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*(int*)&dword_5d4594_1046928, v1, v2);
		goto LABEL_75;
	}
	if (dword_5d4594_1046868 == 2) {
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*(int*)&dword_5d4594_1046924, v1, v2);
		goto LABEL_75;
	}
	if (dword_587000_132132) {
		v4 = dword_5d4594_1046936;
		*(_DWORD*)WideCharStr = 141 / dword_5d4594_1046656 - 1;
		if (!dword_5d4594_1046936) {
			nox_window_set_hidden(*(int*)&dword_5d4594_1046944, 1);
			v4 = dword_5d4594_1046936;
		}
		v5 = 0;
		v6 = v66 + 78;
		v7 = v67 + 19;
		if (2 * *(_DWORD*)WideCharStr > 0) {
			while (1) {
				v8 = v5 + 2 * *(_DWORD*)WideCharStr * v4;
				if (v8 >= *(int*)getMemAt(0x5D4594, 1047508) - dword_5d4594_1047512)
					break;
				if (v5 == *(_DWORD*)WideCharStr) {
					v6 = v66 + 199;
					v7 = v67 + 19;
				}
				sub_434390(*(int*)getMemAt(0x5D4594, 1046880));
				v9 = *(_BYTE*)(dword_5d4594_1047516 + 2251);
				if (dword_5d4594_1046868 == 1) {
					if (v9 == 2 && !sub_424B70(*getMemU32Ptr(0x5D4594, 4 * v8 + 1046960) + 74))
						sub_434390(*(int*)getMemAt(0x5D4594, 1046884));
					v10 = (unsigned __int16*)sub_427240(*getMemU32Ptr(0x5D4594, 4 * v8 + 1046960));
					sub_43F840(0, v10, &v65, 0, 128);
					v62 = v7;
					v60 = v6 - v65 / 2;
					v11 = (__int16*)sub_427240(*getMemU32Ptr(0x5D4594, 4 * v8 + 1046960));
				} else if (v9) {
					if (!sub_424B70(*getMemU32Ptr(0x5D4594, 4 * v8 + 1046960)))
						sub_434390(*(int*)getMemAt(0x5D4594, 1046884));
					v13 = (unsigned __int16*)sub_424930(*getMemU32Ptr(0x5D4594, 4 * v8 + 1046960));
					sub_43F840(0, v13, &v65, 0, 128);
					v62 = v7;
					v60 = v6 - v65 / 2;
					v11 = (__int16*)sub_424930(*getMemU32Ptr(0x5D4594, 4 * v8 + 1046960));
				} else {
					v12 = (unsigned __int16*)sub_425260(*getMemU32Ptr(0x5D4594, 4 * v8 + 1046960));
					sub_43F840(0, v12, &v65, 0, 128);
					v62 = v7;
					v60 = v6 - v65 / 2;
					v11 = (__int16*)sub_425260(*getMemU32Ptr(0x5D4594, 4 * v8 + 1046960));
				}
				sub_43F6E0(0, v11, v60, v62);
				v7 += dword_5d4594_1046656;
				if (++v5 >= 2 * *(_DWORD*)WideCharStr)
					break;
				v4 = dword_5d4594_1046936;
			}
		}
		goto LABEL_75;
	}
	if (dword_5d4594_1046868 == 1) {
		v14 = v67 + 51;
		v15 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 132380), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 978);
		nox_swprintf(v71, L"%s ", v15);
		v16 = sub_427460(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960)) - 1;
		if (v16) {
			v17 = v16 - 1;
			if (v17) {
				if (v17 == 2) {
					v18 = 76;
					v19 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 132520), 0,
												"C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 995);
					nox_wcscat(v71, v19);
					v20 = 0;
				} else {
					v18 = *(_DWORD*)WideCharStr;
					v20 = *(_DWORD*)WideCharStr;
				}
			} else {
				v18 = 38;
				v21 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 132476), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c",
											989);
				nox_wcscat(v71, v21);
				v20 = 0;
			}
		} else {
			v18 = 38;
			v22 =
				loadString_sub_40F1D0((char*)getMemAt(0x587000, 132432), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 983);
			nox_wcscat(v71, v22);
			v20 = 19;
		}
		if (*(_BYTE*)(dword_5d4594_1047516 + 2251) == 2 &&
			(*(_DWORD*)(dword_5d4594_1047516 + 4232) ||
			 nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096))) {
			sub_43F840(0, v71, &v70, 0, 0);
			sub_43FAF0(0, v71, (108 - v70) / 2 + v66 + 24, v14, 128, 0);
		}
		v23 = v14 + v3 + 2;
		v24 = (unsigned __int16*)sub_427240(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
		sub_43FA80(0, v24, &v70, &v68, 108);
		if (v68 <= v3)
			v25 = (108 - v70) / 2 + v66 + 24;
		else
			v25 = v66 + 24;
		v55 = v25;
		v26 = (_WORD*)sub_427240(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
		sub_43FD80(0, v26, v55, v23, 128, 0);
		v63 = v23 + v20 + v68 + 2;
		v61 = (108 - v18) / 2 + v66 + 24;
		v27 = sub_427400(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
		nox_client_drawImageAt_47D2C0(v27, v61, v63);
		v28 = (unsigned __int16*)sub_4272E0(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
		v29 = v28;
		v30 = v67 + 52;
		if (v28) {
			sub_43F840(0, v28, 0, WideCharStr, 92);
			v31 = *(_DWORD*)WideCharStr;
			v32 = v66 + 153;
			goto LABEL_53;
		}
	} else {
		if (!*(_BYTE*)(dword_5d4594_1047516 + 2251)) {
			sub_425450(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
			v33 = (unsigned __int16*)sub_425260(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
			sub_43FA80(0, v33, &v70, &v68, 108);
			if (v68 <= v3)
				v34 = (108 - v70) / 2 + v66 + 24;
			else
				v34 = v66 + 24;
			v58 = v67 + 53;
			v56 = v34;
			v35 = (_WORD*)sub_425260(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
			sub_43FD80(0, v35, v56, v58, 128, 0);
			v36 = (unsigned __int16*)sub_4252F0(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
			v29 = v36;
			v30 = v67 + 52;
			if (!v36)
				goto LABEL_75;
			sub_43F840(0, v36, 0, WideCharStr, 92);
			v31 = *(_DWORD*)WideCharStr;
			v32 = v66 + 153;
		LABEL_53:
			v37 = (141 - v31) / 2 + v67 + 17;
			if (v37 > v30)
				goto LABEL_73;
			goto LABEL_74;
		}
		v38 = sub_424A70(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
		v39 = (unsigned __int16*)sub_424930(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
		sub_43FA80(0, v39, &v65, &v68, 108);
		if (v68 <= v3)
			v40 = (108 - v65) / 2 + v66 + 24;
		else
			v40 = v66 + 24;
		v41 = v67 + 53;
		v59 = v67 + 53;
		v57 = v40;
		v42 = (_WORD*)sub_424930(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
		sub_43FD80(0, v42, v57, v59, 128, 0);
		v43 = v41 + v68 + 2;
		v44 = sub_4249A0(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960), 1);
		v45 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 132564), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1115);
		nox_swprintf(v71, L"%s ", v45);
		if (v44) {
			_itow(v44, WideCharStr, 10);
			nox_wcscat(v71, WideCharStr);
		} else if (sub_424A50(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960), 0x800000)) {
			nox_wcscat(v71, L"0");
		} else {
			nox_wcscat(v71, L"*");
		}
		sub_43F840(0, v71, &v65, 0, 0);
		v46 = v43 + 2;
		sub_43FAF0(0, v71, (108 - v65) / 2 + v66 + 24, v46, 128, 0);
		v47 = v46 + v3 + 2;
		if (v38 & 0x100) {
			v48 =
				loadString_sub_40F1D0((char*)getMemAt(0x587000, 132628), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1173);
			sub_43F840(0, v48, &v65, 0, 0);
			sub_43FAF0(0, v48, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
			v47 += v3;
		}
		if (v38 & 4) {
			v49 =
				loadString_sub_40F1D0((char*)getMemAt(0x587000, 132680), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1181);
			sub_43F840(0, v49, &v65, 0, 0);
			sub_43FAF0(0, v49, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
			v47 += v3;
		}
		if (v38 & 8) {
			v50 =
				loadString_sub_40F1D0((char*)getMemAt(0x587000, 132732), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1189);
			sub_43F840(0, v50, &v65, 0, 0);
			sub_43FAF0(0, v50, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
			v47 += v3;
		}
		if (v38 & 0x20) {
			v51 =
				loadString_sub_40F1D0((char*)getMemAt(0x587000, 132784), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1197);
			sub_43F840(0, v51, &v65, 0, 0);
			sub_43FAF0(0, v51, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
			v47 += v3;
		}
		v64 = *(_DWORD*)(dword_5d4594_1047516 + 4 * *getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960) + 3696);
		v52 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 132836), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1206);
		nox_swprintf(v71, v52, v64);
		sub_43F840(0, v71, &v65, 0, 0);
		sub_43FAF0(0, v71, (108 - v65) / 2 + v66 + 24, v3 + v47, 128, 0);
		v53 = (unsigned __int16*)sub_424A30(*getMemU32Ptr(0x5D4594, 4 * dword_5d4594_1046932 + 1046960));
		v29 = v53;
		v30 = v67 + 52;
		if (v53) {
			sub_43F840(0, v53, 0, WideCharStr, 92);
			v32 = v66 + 153;
			v37 = (141 - *(_DWORD*)WideCharStr) / 2 + v67 + 17;
			if (v37 > v30)
			LABEL_73:
				v37 = v30;
		LABEL_74:
			sub_43FAF0(0, v29, v32, v37, 92, 0);
			goto LABEL_75;
		}
	}
LABEL_75:
	if (!dword_587000_132132 &&
		*(int*)&dword_5d4594_1046932 >= *(int*)getMemAt(0x5D4594, 1047508) - *(int*)&dword_5d4594_1047512 - 1) {
		nox_window_set_hidden(*(int*)&dword_5d4594_1046948, 1);
	}
	return 1;
}

//----- (0045CF00) --------------------------------------------------------
int __cdecl sub_45CF00(_DWORD* a1) {
	wchar_t* v1; // eax
	wchar_t* v3; // eax
	wchar_t* v4; // eax

	if (*a1 == 1310) {
		if (!*(_BYTE*)(dword_5d4594_1047516 + 2251)) {
			v3 =
				loadString_sub_40F1D0((char*)getMemAt(0x587000, 133244), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1640);
			sub_4776B0(v3);
			return 1;
		}
		v4 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 133300), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1644);
		sub_4776B0(v4);
	} else if (*a1 == 1320) {
		v1 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 133352), 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1649);
		sub_4776B0(v1);
		return 1;
	}
	return 1;
}

//----- (0045C7D0) --------------------------------------------------------
int __cdecl sub_45C7D0(_DWORD* a1) {
	int v1;     // esi
	int v3;     // edi
	int v4;     // eax
	int v5;     // eax
	int v6;     // edi
	int v7;     // eax
	int v8;     // eax
	int v9;     // eax
	int v10;    // ecx
	double v11; // st7
	int v12;    // eax
	int v13;    // [esp-28h] [ebp-34h]
	int v14;    // [esp-28h] [ebp-34h]
	int v15;    // [esp-24h] [ebp-30h]
	int v16;    // [esp-20h] [ebp-2Ch]
	char v17;   // [esp-18h] [ebp-24h]
	char v18;   // [esp-18h] [ebp-24h]
	char v19;   // [esp-14h] [ebp-20h]
	char v20;   // [esp-14h] [ebp-20h]
	int v21;    // [esp-10h] [ebp-1Ch]
	int v22;    // [esp-Ch] [ebp-18h]
	int v23;    // [esp-Ch] [ebp-18h]
	int v24;    // [esp+4h] [ebp-8h]
	int v25;    // [esp+8h] [ebp-4h]

	v1 = dword_5d4594_1046652 != 0 ? 3 : 0;
	if (!dword_5d4594_1047520)
		return 1;
	if (dword_5d4594_1046648 &&
		sub_430B40_get_mouse_prev_seq() - dword_5d4594_1046648 < (unsigned int)(2 * *getMemU32Ptr(0x5D4594, 2649704))) {
		return 1;
	}
	nox_client_wndGetPosition_46AA60(a1, &v25, &v24);
	if (dword_5d4594_1046648) {
		v3 = 50;
		do {
			v19 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1287);
			v17 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1286);
			v16 = sub_415FF0(-10, -1, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1284);
			v15 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1283);
			v4 = sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1282);
			v13 = v24 + v4;
			v5 = sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1281);
			nox_client_newScreenParticle_431540(v1, v25 + v5, v13, v15, v16, 1, v17, v19, 2, 1);
			--v3;
		} while (v3);
		sub_452D80(795, 100);
		dword_5d4594_1046648 = 0;
	}
	v6 = 2;
	do {
		v20 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1331);
		v18 = sub_415FF0(1, 2, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1330);
		v7 = sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1326);
		v14 = v24 + v7;
		v8 = sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1325);
		nox_client_newScreenParticle_431540(v1, v25 + v8, v14, 0, 0, 0, v18, v20, 1, 1);
		--v6;
	} while (v6);
	v22 = v24;
	v21 = v25;
	if (dword_5d4594_1046652 == 1)
		v9 = sub_425310(*(int*)&dword_5d4594_1047524, 0);
	else
		v9 = sub_424A90(*(int*)&dword_5d4594_1047524);
	nox_client_drawImageAt_47D2C0(v9, v21, v22);
	*(float*)&dword_5d4594_1046636 = *(float*)&dword_5d4594_1046636 + *getMemFloatPtr(0x5D4594, 1046620);
	*(float*)&dword_5d4594_1046640 = *(float*)&dword_5d4594_1046640 + *(float*)&dword_5d4594_1046624;
	if ((double)*(int*)getMemAt(0x5D4594, 1046668) <= *(float*)&dword_5d4594_1046636 &&
		(double)*(int*)getMemAt(0x5D4594, 1046672) <= *(float*)&dword_5d4594_1046640) {
	LABEL_26:
		sub_45DBE0(*(void**)getMemAt(0x5D4594, 1046676), *(int*)&dword_5d4594_1047524, *(int*)&dword_5d4594_1046852);
		sub_45D810();
		goto LABEL_27;
	}
	if (*(float*)&dword_5d4594_1046636 > (double)*getMemFloatPtr(0x5D4594, 8 * *getMemU32Ptr(0x5D4594, 1046628) + 1046692)) {
		v10 = *getMemU32Ptr(0x5D4594, 1046628) + 1;
		*getMemU32Ptr(0x5D4594, 1046628) = v10;
		if (v10 < *(int*)getMemAt(0x5D4594, 1046680)) {
			if (v10 <= *(int*)getMemAt(0x5D4594, 1046680) - 1) {
				*getMemFloatPtr(0x5D4594, 1046620) =
					*getMemFloatPtr(0x5D4594, 8 * v10 + 1046692) - *getMemFloatPtr(0x5D4594, 8 * v10 + 1046684);
				*(float*)&dword_5d4594_1046624 =
					*getMemFloatPtr(0x5D4594, 8 * v10 + 1046696) - *getMemFloatPtr(0x5D4594, 8 * v10 + 1046688);
				sub_509F20((float2*)getMemAt(0x5D4594, 1046620));
				if (nox_win_width < 1000) {
					if (nox_win_width < 750)
						v11 = 6.0;
					else
						v11 = 8.0;
				} else {
					v11 = 10.0;
				}
				*getMemFloatPtr(0x5D4594, 1046620) = *getMemFloatPtr(0x5D4594, 1046620) * v11;
				*(float*)&dword_5d4594_1046624 = *(float*)&dword_5d4594_1046624 * v11;
			}
			goto LABEL_27;
		}
		goto LABEL_26;
	}
LABEL_27:
	v23 = nox_float2int(*(float*)&dword_5d4594_1046640);
	v12 = nox_float2int(*(float*)&dword_5d4594_1046636);
	nox_wnd_sub_46A9B0(a1, v12, v23);
	return 1;
}

//----- (0045D870) --------------------------------------------------------
void sub_45D870() {
	int v1;     // esi
	int v3;     // edi
	int v4;     // ebx
	int v5;     // ebp
	int v6;     // eax
	int v7;     // [esp-30h] [ebp-38h]
	char v8;    // [esp-20h] [ebp-28h]
	int v9;     // [esp+0h] [ebp-8h]
	int v10;    // [esp+4h] [ebp-4h]

	if (dword_5d4594_1047520) {
		v1 = dword_5d4594_1046652 != 1 ? 0 : 3;
		v9 = ((int)*getMemU32Ptr(0x5D4594, 1046668) - nox_float2int(*(float*)&dword_5d4594_1046636)) / 50;
		v10 = ((int)*getMemU32Ptr(0x5D4594, 1046672) - nox_float2int(*(float*)&dword_5d4594_1046640)) / 50;
		v3 = nox_float2int(*(float*)&dword_5d4594_1046636);
		v4 = nox_float2int(*(float*)&dword_5d4594_1046640);
		v5 = 50;
		do {
			v8 = sub_415FF0(3, 4, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 2483);
			v7 = v4 - sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 2479);
			v6 = sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 2478);
			nox_client_newScreenParticle_431540(v1, v3 + v6, v7, 0, 0, 1, v8, 0, 0, 1);
			v3 += v9;
			v4 += v10;
			--v5;
		} while (v5);
		sub_45DBE0(*(void**)getMemAt(0x5D4594, 1046676), *(int*)&dword_5d4594_1047524, *(int*)&dword_5d4594_1046852);
		sub_45D810();
	}
}
