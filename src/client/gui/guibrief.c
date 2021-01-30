#include "guibrief.h"

#include "../../proto.h"

extern _DWORD dword_587000_122956;
extern _DWORD nox_xxx_aSpellphoneme_3_587000_123008;
extern _DWORD dword_5d4594_832480;
extern _DWORD dword_5d4594_832520;
extern _DWORD dword_5d4594_832500;
extern _DWORD dword_5d4594_832528;
extern _DWORD dword_5d4594_832524;
extern _DWORD dword_5d4594_832512;
extern _DWORD dword_5d4594_832496;
extern _DWORD dword_5d4594_832516;
extern _DWORD dword_5d4594_832508;
extern _DWORD dword_5d4594_832504;
extern _DWORD dword_5d4594_832492;
extern _DWORD dword_5d4594_832532;
extern _DWORD dword_5d4594_832536;
extern _DWORD dword_5d4594_831232;
extern _DWORD dword_5d4594_832476;
extern _DWORD dword_5d4594_832484;
extern int nox_win_width;
extern int nox_win_height;

//----- (0044E410) --------------------------------------------------------
wchar_t* sub_44E410() {
	int v0;          // esi
	int v1;          // edi
	int i;           // ebp
	int v3;          // ebx
	int v4;          // esi
	wchar_t* result; // eax
	int v6;          // [esp-2Ch] [ebp-80h]
	int v7;          // [esp+10h] [ebp-44h]
	char v8[64];     // [esp+14h] [ebp-40h]

	v0 = 0;
	v7 = 0;
	v1 = 0;
	for (i = 1;; ++i) {
		while (1) {
			if (v0) {
				if (v0 == 1)
					v3 = v1 ? (v1 != 1) + 2 : 4;
				else
					v3 = v0 + 3;
			} else {
				v3 = 1;
			}
			nox_sprintf(v8, "Briefing:%sChapterBegin%d", *getMemU32Ptr(0x587000, 4 * v1 + 122944), i);
			v4 = 32 * (v1 + v0 + 10 * v1);
			*getMemU32Ptr(0x5D4594, v4 + 831300) = nox_xxx_gLoadImg_42F970(&v8[9]);
			*getMemU32Ptr(0x5D4594, v4 + 831304) =
				nox_strman_loadString_40F1D0(v8, getMemAt(0x5D4594, v4 + 831308), "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1221);
			v6 = *getMemU32Ptr(0x587000, 4 * v1 + 122944);
			*getMemU32Ptr(0x5D4594, v4 + 831312) = v3;
			nox_sprintf(v8, "Briefing:%sChapterLoss%d", v6, i);
			*getMemU32Ptr(0x5D4594, v4 + 831316) = nox_xxx_gLoadImg_42F970(&v8[9]);
			++v1;
			*getMemU32Ptr(0x5D4594, v4 + 831320) =
				nox_strman_loadString_40F1D0(v8, getMemAt(0x5D4594, v4 + 831324), "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1227);
			*getMemU32Ptr(0x5D4594, v4 + 831328) = v3;
			if (v1 >= 3)
				break;
			v0 = v7;
		}
		v7 = i;
		if (i >= 11)
			break;
		v0 = i;
		v1 = 0;
	}
	*getMemU32Ptr(0x5D4594, 831264) = nox_xxx_gLoadImg_42F970("CreditsImage");
	result = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 123412), getMemAt(0x5D4594, 831272),
								   "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1233);
	*getMemU32Ptr(0x5D4594, 831268) = result;
	return result;
}

//----- (0044E8E0) --------------------------------------------------------
int __cdecl sub_44E8E0(int a1, int a2) {
	int v2;                // ebx
	int v3;                // esi
	wchar_t* v4;           // eax
	wchar_t* v5;           // eax
	unsigned __int8* v6;   // eax
	unsigned __int8* v7;   // ebp
	int v8;                // esi
	int v9;                // ecx
	int v10;               // ebx
	int v11;               // eax
	signed int v12;        // eax
	int v13;               // esi
	wchar_t* v14;          // eax
	int v15;               // esi
	wchar_t* v16;          // eax
	int v17;               // esi
	wchar_t* v18;          // eax
	int v19;               // esi
	wchar_t* v20;          // eax
	wchar_t* v21;          // eax
	int v22;               // ebx
	int v23;               // esi
	int v24;               // ebp
	wchar_t* v25;          // eax
	wchar_t* v26;          // eax
	int v27;               // esi
	wchar_t* v28;          // eax
	wchar_t* v29;          // eax
	int v30;               // esi
	int v31;               // ebp
	int result;            // eax
	int v33;               // ebp
	unsigned __int16* v34; // esi
	int v35;               // ebx
	float v36;             // [esp+0h] [ebp-674h]
	int v37;               // [esp+0h] [ebp-674h]
	int v38;               // [esp+14h] [ebp-660h]
	int v39;               // [esp+18h] [ebp-65Ch]
	int v40;               // [esp+1Ch] [ebp-658h]
	int v41;               // [esp+20h] [ebp-654h]
	int v42;               // [esp+24h] [ebp-650h]
	int v43;               // [esp+28h] [ebp-64Ch]
	int v44;               // [esp+2Ch] [ebp-648h]
	int v45;               // [esp+30h] [ebp-644h]
	int v46;               // [esp+34h] [ebp-640h]
	int v47;               // [esp+38h] [ebp-63Ch]
	unsigned __int8* v48;  // [esp+3Ch] [ebp-638h]
	int v49;               // [esp+40h] [ebp-634h]
	int v50;               // [esp+44h] [ebp-630h]
	int v51;               // [esp+48h] [ebp-62Ch]
	int v52;               // [esp+4Ch] [ebp-628h]
	int v53;               // [esp+50h] [ebp-624h]
	WCHAR WideCharStr[11]; // [esp+54h] [ebp-620h]
	wchar_t v55[257];      // [esp+72h] [ebp-602h]
	wchar_t v56[256];      // [esp+274h] [ebp-400h]
	wchar_t v57[256];      // [esp+474h] [ebp-200h]

	v49 = (nox_win_width - NOX_DEFAULT_WIDTH) / 2;
	v47 = 0;
	v45 = 0;
	v50 = (nox_win_height - NOX_DEFAULT_HEIGHT) / 2;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v2 = nox_win_width / 2;
	v3 = nox_win_height / 2;
	v51 = nox_win_width / 2;
	v52 = nox_win_height / 2;
	v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 123480), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 449);
	nox_wcscpy(&v55[1], v4);
	v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 123552), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 451);
	nox_wcscpy(v56, v5);
	nox_wcscat(v56, L" ");
	_itow(*getMemIntPtr(0x5D4594, 831228), WideCharStr, 10);
	nox_wcscat(v56, WideCharStr);
	nox_swprintf(v57, L"%s - %s", &v55[1], v56);
	nox_xxx_drawGetStringSize_43F840(*(_DWORD*)(a2 + 200), v57, &v39, &v38, 0);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v57, v2 - v39 / 2, v38 + v3 - 240);
	v40 = *getMemU32Ptr(0x587000, 122968) - *getMemU32Ptr(0x587000, 122964);
	v36 = (double)v38 * 1.5;
	v41 = nox_float2int(v36);
	v6 = getMemAt(0x587000, 122964);
	v43 = 0;
	v42 = 0;
	v7 = getMemAt(0x5D4594, 832364);
	v48 = getMemAt(0x587000, 122964);
	while (1) {
		v8 = *(_DWORD*)v6 + v3 - 240;
		v9 = *(_DWORD*)v7;
		v10 = *((_DWORD*)v6 - 1) + v2 - 320;
		if (*(_DWORD*)v7) {
			++v43;
			if (v9 == *getMemU32Ptr(0x5D4594, 2618908))
				v47 = *((unsigned __int16*)v7 + 5);
			else
				v45 += *((unsigned __int16*)v7 + 5);
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
			nox_swprintf(&v55[1], L"%d) %s", v42 + 1, *(_DWORD*)v7 + 4704);
			v11 = *(_DWORD*)(a2 + 200);
			v46 = *getMemU32Ptr(0x587000, 122968) - *getMemU32Ptr(0x587000, 122960) + v10 - 16;
			nox_xxx_drawGetStringSize_43F840(v11, &v55[1], &v44, &v53, 0);
			while (v10 + v44 >= v46) {
				v12 = nox_wcslen(&v55[1]);
				if (v12 <= 5)
					break;
				v55[v12] = 0;
				nox_xxx_drawGetStringSize_43F840(*(_DWORD*)(a2 + 200), &v55[1], &v44, &v53, 0);
			}
			nox_xxx_drawString_43FAF0(*(_DWORD*)(a2 + 200), &v55[1], v10, v8, v40 - 8, v38);
			v13 = v41 + v41 / 2 + v8;
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
			v14 =
				nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 123648), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 529);
			nox_xxx_drawString_43FAF0(*(_DWORD*)(a2 + 200), v14, v10, v13, *(int*)&dword_5d4594_832476, v38);
			nox_swprintf(&v55[1], L" %d", *((unsigned __int16*)v7 + 3));
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614268));
			nox_xxx_drawString_43FAF0(*(_DWORD*)(a2 + 200), &v55[1], v10 + dword_5d4594_832476, v13, v40 - dword_5d4594_832476 - 8,
					   v38);
			v15 = v41 + v13;
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
			v16 =
				nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 123728), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 541);
			nox_xxx_drawString_43FAF0(*(_DWORD*)(a2 + 200), v16, v10, v15, *(int*)&dword_5d4594_832476, v38);
			nox_swprintf(&v55[1], L" %d", *((unsigned __int16*)v7 + 4));
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614268));
			nox_xxx_drawString_43FAF0(*(_DWORD*)(a2 + 200), &v55[1], v10 + dword_5d4594_832476, v15, v40 - dword_5d4594_832476 - 8,
					   v38);
			v17 = v41 + v15;
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
			v18 =
				nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 123804), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 553);
			nox_xxx_drawString_43FAF0(*(_DWORD*)(a2 + 200), v18, v10, v17, *(int*)&dword_5d4594_832476, v38);
			nox_swprintf(&v55[1], L" %d", *((unsigned __int16*)v7 + 2));
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614268));
			nox_xxx_drawString_43FAF0(*(_DWORD*)(a2 + 200), &v55[1], v10 + dword_5d4594_832476, v17, v40 - dword_5d4594_832476 - 8,
					   v38);
			v19 = v41 + v17;
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
			v20 =
				nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 123872), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 565);
			nox_xxx_drawString_43FAF0(*(_DWORD*)(a2 + 200), v20, v10, v19, *(int*)&dword_5d4594_832476, v38);
			nox_swprintf(&v55[1], L" %d", *((_DWORD*)v7 + 3));
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2650684));
			nox_xxx_drawString_43FAF0(*(_DWORD*)(a2 + 200), &v55[1], v10 + dword_5d4594_832476, v19, v40 - dword_5d4594_832476 - 8,
					   v38);
			v6 = v48;
		}
		v6 += 8;
		v7 += 16;
		++v42;
		v48 = v6;
		if ((int)v6 >= (int)getMemAt(0x587000, 123012))
			break;
		v2 = v51;
		v3 = v52;
	}
	v21 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 123944), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 583);
	nox_swprintf(&v55[1], v21, *getMemU32Ptr(0x5D4594, 832356));
	nox_xxx_drawGetStringSize_43F840(*(_DWORD*)(a2 + 200), &v55[1], &v39, &v38, 0);
	v22 = v49;
	v23 = v49 - v39 / 2 + 320;
	v24 = v50 + 2 * (150 - v38) + 150 - v38;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
	nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)&v55[1], v23, v24);
	if (v47) {
		v37 = v47;
		v25 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124012), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 593);
		nox_swprintf(&v55[1], v25, v37);
	} else {
		v26 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124080), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 596);
		nox_swprintf(&v55[1], v26);
	}
	if (v43 <= 1) {
		nox_wcscpy(v57, &v55[1]);
	} else {
		v27 = v45;
		if (v45) {
			v28 =
				nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124152), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 606);
			if (v28)
				nox_swprintf(v56, v28, v27);
		} else {
			v29 =
				nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124228), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 612);
			nox_wcscpy(v56, v29);
		}
		nox_swprintf(v57, L"%s - %s", &v55[1], v56);
	}
	nox_xxx_drawGetStringSize_43F840(*(_DWORD*)(a2 + 200), v57, &v39, &v38, 0);
	v30 = v22 - v39 / 2 + 320;
	v31 = v50 + 2 * (225 - v38);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
	nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v57, v30, v31);
	result = *getMemU32Ptr(0x5D4594, 2598000) / 0x1Eu;
	if (*getMemU32Ptr(0x5D4594, 2598000) % 0x1Eu) {
		if (dword_587000_122956 != 1)
			return result;
	} else {
		result = 1;
		if (dword_587000_122956 == 1) {
			dword_587000_122956 = *getMemU32Ptr(0x5D4594, 2598000) % 0x1Eu;
			return result;
		}
		dword_587000_122956 = 1;
	}
	v33 = *getMemU32Ptr(0x5D4594, 2523948);
	v34 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124324), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 642);
	nox_xxx_drawGetStringSize_43F840(*(_DWORD*)(a2 + 200), v34, &v39, 0, 0);
	v35 = v22 - v39 / 2 + 320;
	nox_xxx_drawSetTextColor_434390(v33);
	return nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v34, v35, v50 + 450);
}

//----- (0044F0F0) --------------------------------------------------------
int __cdecl sub_44F0F0(int a1, int a2) {
	int v2;               // esi
	int v3;               // ebx
	wchar_t* v4;          // eax
	int result;           // eax
	int v6;               // esi
	int v7;               // ebx
	unsigned __int16* v8; // ebp
	int v9;               // esi
	int v10;              // [esp+10h] [ebp-40Ch]
	int v11;              // [esp+14h] [ebp-408h]
	int v12;              // [esp+18h] [ebp-404h]
	wchar_t v13[256];     // [esp+1Ch] [ebp-400h]
	wchar_t v14[256];     // [esp+21Ch] [ebp-200h]

	v2 = nox_win_width / 2;
	v3 = nox_win_height / 2;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124392), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 668);
	nox_wcscpy(v13, v4);
	nox_wcscat(v13, L" %d");
	nox_swprintf(v14, v13, *getMemU32Ptr(0x5D4594, 832468));
	nox_xxx_drawGetStringSize_43F840(*(_DWORD*)(a2 + 200), v14, &v10, &v11, 0);
	nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v14, v2 - v10 / 2, v3 + 2 * (v11 - 80) + v11 - 80);
	if (*getMemU32Ptr(0x5D4594, 832464)) {
		nox_xxx_drawGetStringSize_43F840(*(_DWORD*)(a2 + 200), *(unsigned __int16**)getMemAt(0x5D4594, 832464), &v10, &v11, 0);
		nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), *(__int16**)getMemAt(0x5D4594, 832464), v2 - v10 / 2,
				   v3 + 2 * (80 - v11) + 80 - v11);
	}
	result = *getMemU32Ptr(0x5D4594, 2598000) / 0x1Eu;
	if (*getMemU32Ptr(0x5D4594, 2598000) % 0x1Eu) {
		if (nox_xxx_aSpellphoneme_3_587000_123008 != 1)
			return result;
	} else {
		result = 1;
		if (nox_xxx_aSpellphoneme_3_587000_123008 == 1) {
			nox_xxx_aSpellphoneme_3_587000_123008 = *getMemU32Ptr(0x5D4594, 2598000) % 0x1Eu;
			return result;
		}
		nox_xxx_aSpellphoneme_3_587000_123008 = 1;
	}
	v12 = *getMemU32Ptr(0x5D4594, 2523948);
	v6 = (nox_win_width - NOX_DEFAULT_WIDTH) / 2;
	v7 = (nox_win_height - NOX_DEFAULT_HEIGHT) / 2;
	v8 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124460), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 714);
	nox_xxx_drawGetStringSize_43F840(*(_DWORD*)(a2 + 200), v8, &v10, 0, 0);
	v9 = v6 - v10 / 2 + 320;
	nox_xxx_drawSetTextColor_434390(v12);
	return nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v8, v9, v7 + 462);
}

//----- (0044F300) --------------------------------------------------------
int __cdecl sub_44F300(int a1, int a2) {
	char* v2;              // ebx
	int v3;                // esi
	int v4;                // edi
	unsigned __int16* v5;  // ebp
	__int16* v6;           // ebp
	wchar_t* v7;           // eax
	int v8;                // ebp
	__int16* v9;           // ebp
	wchar_t* v10;          // eax
	int v11;               // ebp
	__int16* v12;          // ebp
	wchar_t* v13;          // eax
	int v14;               // ebp
	__int16* v15;          // ebx
	wchar_t* v16;          // eax
	unsigned __int16* v17; // ebx
	unsigned __int16* v18; // ebp
	unsigned __int16* v19; // ebx
	unsigned __int16* v20; // ebp
	unsigned __int16* v21; // ebx
	unsigned __int16* v22; // ebp
	int result;            // eax
	int v24;               // ebp
	unsigned __int16* v25; // ebx
	int v26;               // [esp-3Ch] [ebp-70h]
	int v27;               // [esp+10h] [ebp-24h]
	int v28;               // [esp+14h] [ebp-20h]
	unsigned __int16* v29; // [esp+18h] [ebp-1Ch]
	unsigned __int16* v30; // [esp+1Ch] [ebp-18h]
	int v31;               // [esp+20h] [ebp-14h]
	unsigned __int16* v32; // [esp+24h] [ebp-10h]
	unsigned __int16* v33; // [esp+28h] [ebp-Ch]
	int2 v34;              // [esp+2Ch] [ebp-8h]

	v2 = sub_437250();
	sub_44E110();
	sub_431510();
	nox_xxx_bookHideMB_45ACA0(1);
	sub_446780();
	v3 = (nox_win_width - NOX_DEFAULT_WIDTH) / 2;
	v4 = (nox_win_height - NOX_DEFAULT_HEIGHT) / 2;
	v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124528), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 765);
	nox_xxx_drawGetStringSize_43F840(*(_DWORD*)(a2 + 200), v5, &v31, 0, 0);
	v29 = (unsigned __int16*)(v3 - v31 / 2 + 320);
	v30 = (unsigned __int16*)(v4 + 20);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2650656));
	v26 = *(_DWORD*)(a2 + 200);
	v32 = (unsigned __int16*)((char*)v29 - 1);
	nox_xxx_drawString_43F6E0(v26, (__int16*)v5, (int)v29 - 1, v4 + 19);
	v33 = (unsigned __int16*)((char*)v29 + 1);
	nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v5, (int)v29 + 1, v4 + 19);
	nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v5, (int)v32, v4 + 21);
	nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v5, (int)v33, v4 + 21);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
	nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v5, (int)v29, v4 + 20);
	v34.field_0 = v3 + 73;
	v34.field_4 = v4 + 123;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832492 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832492 + 300))(v2, dword_5d4594_832492);
	v34.field_0 = v3 + 109;
	v34.field_4 = v4 + 76;
	v6 = (__int16*)nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124596), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c",
										 792);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, v6, v34.field_0, v34.field_4);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, (unsigned __int16*)v6, &v27, 0, 0);
	v34.field_0 += v27 + 4;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v7 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124664), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 799);
	nox_xxx_drawString_43FAF0(*(int*)&dword_5d4594_832484, v7, v34.field_0, v34.field_4, v3 - v34.field_0 + 520, 0);
	v34.field_0 = v3 + 565;
	v34.field_4 = v4 + 117;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832496 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832496 + 300))(v2, dword_5d4594_832496);
	v29 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124732), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 809);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v29, &v27, 0, 0);
	v30 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124800), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 811);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v30, &v28, 0, 0);
	v8 = v3 + 520;
	if (v28 + v27 <= 390) {
		v34.field_4 = v4 + 115;
		v34.field_0 = v8 - v28 - v27 - 4;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v29, v34.field_0, v34.field_4);
		v34.field_0 = v8 - v28;
		v34.field_4 = v4 + 115;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v30, v34.field_0, v34.field_4);
	} else {
		v34.field_0 = v3 + 199;
		v34.field_4 = v4 + 115;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v29, v34.field_0, v34.field_4);
		v34.field_0 += v27 + 4;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
		nox_xxx_drawString_43FAF0(*(int*)&dword_5d4594_832484, v30, v34.field_0, v34.field_4, v8 - v34.field_0, 0);
	}
	v34.field_0 = v3 + 133;
	v34.field_4 = v4 + 192;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832504 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832504 + 300))(v2, dword_5d4594_832504);
	v34.field_0 = v3 + 157;
	v34.field_4 = v4 + 156;
	v9 = (__int16*)nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124868), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c",
										 862);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, v9, v34.field_0, v34.field_4);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, (unsigned __int16*)v9, &v27, 0, 0);
	v34.field_0 += v27 + 4;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v10 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 124936), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 869);
	nox_xxx_drawString_43FAF0(*(int*)&dword_5d4594_832484, v10, v34.field_0, v34.field_4, v4 - v34.field_0 + 630, 0);
	v34.field_0 = v3 + 525;
	v34.field_4 = v4 + 222;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832500 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832500 + 300))(v2, dword_5d4594_832500);
	v29 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125004), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 879);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v29, &v27, 0, 0);
	v30 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125072), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 881);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v30, &v28, 0, 0);
	v11 = v3 + 500;
	if (v28 + v27 <= 215) {
		v34.field_4 = v4 + 198;
		v34.field_0 = v11 - v28 - v27 - 4;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v29, v34.field_0, v34.field_4);
		v34.field_0 = v11 - v28;
		v34.field_4 = v4 + 198;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v30, v34.field_0, v34.field_4);
	} else {
		v34.field_0 = v3 + 250;
		v34.field_4 = v4 + 198;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v29, v34.field_0, v34.field_4);
		v34.field_0 += v27 + 4;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
		nox_xxx_drawString_43FAF0(*(int*)&dword_5d4594_832484, v30, v34.field_0, v34.field_4, v11 - v34.field_0, 0);
	}
	v34.field_0 = v3 + 182;
	v34.field_4 = v4 + 262;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832528 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832528 + 300))(v2, dword_5d4594_832528);
	v34.field_0 = v3 + 201;
	v34.field_4 = v4 + 251;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832536 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832536 + 300))(v2, dword_5d4594_832536);
	v34.field_0 = v3 + 185;
	v34.field_4 = v4 + 234;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832532 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832532 + 300))(v2, dword_5d4594_832532);
	v34.field_0 = v3 + 221;
	v34.field_4 = v4 + 240;
	v12 = (__int16*)nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125140), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c",
										  942);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, v12, v34.field_0, v34.field_4);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, (unsigned __int16*)v12, &v27, 0, 0);
	v34.field_0 += v27 + 4;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v13 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125208), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 949);
	nox_xxx_drawString_43FAF0(*(int*)&dword_5d4594_832484, v13, v34.field_0, v34.field_4, v3 - v34.field_0 + 470, 0);
	v34.field_0 = v3 + 484;
	v34.field_4 = v4 + 278;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832516 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832516 + 300))(v2, dword_5d4594_832516);
	v34.field_0 = v3 + 503;
	v34.field_4 = v4 + 303;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832520 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832520 + 300))(v2, dword_5d4594_832520);
	v29 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125276), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 964);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v29, &v27, 0, 0);
	v30 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125344), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 966);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v30, &v28, 0, 0);
	v14 = v3 + 462;
	if (v28 + v27 <= 350) {
		v34.field_4 = v4 + 286;
		v34.field_0 = v14 - v28 - v27 - 4;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v29, v34.field_0, v34.field_4);
		v34.field_0 = v14 - v28;
		v34.field_4 = v4 + 286;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v30, v34.field_0, v34.field_4);
	} else {
		v34.field_0 = v3 + 113;
		v34.field_4 = v4 + 286;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v29, v34.field_0, v34.field_4);
		v34.field_0 += v27 + 4;
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
		nox_xxx_drawString_43FAF0(*(int*)&dword_5d4594_832484, v30, v34.field_0, v34.field_4, v14 - v34.field_0, 0);
	}
	v34.field_0 = v3 + 186;
	v34.field_4 = v4 + 333;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832512 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832512 + 300))(v2, dword_5d4594_832512);
	v34.field_0 = v3 + 219;
	v34.field_4 = v4 + 345;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832508 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832508 + 300))(v2, dword_5d4594_832508);
	v34.field_0 = v3 + 220;
	v34.field_4 = v4 + 322;
	sub_473A10(v2, &v34, (_DWORD*)(dword_5d4594_832524 + 12));
	(*(void(__cdecl**)(char*, _DWORD))(dword_5d4594_832524 + 300))(v2, dword_5d4594_832524);
	v34.field_0 = v3 + 241;
	v34.field_4 = v4 + 330;
	v15 = (__int16*)nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125412), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c",
										  1027);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, v15, v34.field_0, v34.field_4);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, (unsigned __int16*)v15, &v27, 0, 0);
	v34.field_0 += v27 + 4;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v16 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125480), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1034);
	nox_xxx_drawString_43FAF0(*(int*)&dword_5d4594_832484, v16, v34.field_0, v34.field_4, v3 - v34.field_0 + 550, 0);
	v17 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125548), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1040);
	v18 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125616), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1041);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v17, &v27, 0, 0);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v18, &v28, 0, 0);
	v34.field_0 = v3 - (v27 + v28) / 2 + 320;
	v34.field_4 = v4 + 370;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v17, v34.field_0, v34.field_4);
	v34.field_0 += v27 + 4;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v18, v34.field_0, v34.field_4);
	v19 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125684), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1055);
	v20 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125752), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1056);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v19, &v27, 0, 0);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v20, &v28, 0, 0);
	v34.field_0 = v3 - (v28 + v27) / 2 + 320;
	v34.field_4 = v4 + 395;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v19, v34.field_0, v34.field_4);
	v34.field_0 += v27 + 4;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v20, v34.field_0, v34.field_4);
	v21 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125820), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1070);
	v22 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125888), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1071);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v21, &v27, 0, 0);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v22, &v28, 0, 0);
	v34.field_0 = v3 - (v28 + v27) / 2 + 320;
	v34.field_4 = v4 + 420;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2614256));
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v21, v34.field_0, v34.field_4);
	v34.field_0 += v27 + 4;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_832484, (__int16*)v22, v34.field_0, v34.field_4);
	result = *getMemU32Ptr(0x5D4594, 2598000) / 0x1Eu;
	if (*getMemU32Ptr(0x5D4594, 2598000) % 0x1Eu) {
		if (*getMemU32Ptr(0x587000, 123012) != 1)
			return result;
	} else {
		result = 1;
		if (*getMemU32Ptr(0x587000, 123012) == 1) {
			*getMemU32Ptr(0x587000, 123012) = *getMemU32Ptr(0x5D4594, 2598000) % 0x1Eu;
			return result;
		}
		*getMemU32Ptr(0x587000, 123012) = 1;
	}
	v24 = *getMemU32Ptr(0x5D4594, 2523948);
	v25 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 125956), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1097);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_832484, v25, &v27, 0, 0);
	v34.field_4 = v4 + 450;
	v34.field_0 = v3 - v27 / 2 + 320;
	nox_xxx_drawSetTextColor_434390(v24);
	return nox_xxx_drawString_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v25, v34.field_0, v34.field_4);
}

//----- (00450770) --------------------------------------------------------
int __cdecl nox_xxx_clientQuestWinScreen_450770(int a1) {
	size_t v1;            // ebx
	unsigned __int8* v2;  // esi
	unsigned __int16* v3; // edi
	_DWORD* v4;           // esi
	unsigned __int16* v5; // eax
	unsigned __int16* v6; // eax
	unsigned __int16* v7; // eax
	unsigned __int16* v8; // eax
	int v9;               // eax

	memset(getMemAt(0x5D4594, 832364), 0, 0x60u);
	*getMemU32Ptr(0x5D4594, 832356) = 0;
	v1 = 0;
	*getMemU32Ptr(0x5D4594, 832356) = *(unsigned __int16*)(a1 + 2);
	*getMemU32Ptr(0x5D4594, 831228) = *(unsigned __int16*)(a1 + 4);
	v2 = getMemAt(0x5D4594, 832364 + 4);
	v3 = (unsigned __int16*)(a1 + 6);
	do {
		if (*v3) {
			*((_DWORD*)v2 - 1) = nox_common_playerInfoGetByID_417040(*v3);
			*(_WORD*)v2 = v3[4];
			*((_WORD*)v2 + 1) = v3[1];
			*((_WORD*)v2 + 2) = v3[2];
			*((_WORD*)v2 + 3) = v3[3];
			*((_DWORD*)v2 + 2) = *(_DWORD*)(v3 + 5);
			++v1;
		}
		v2 += 16;
		v3 += 7;
	} while ((int)v2 < (int)getMemAt(0x5D4594, 832464));
	qsort(getMemAt(0x5D4594, 832364), v1, 0x10u, sub_450960);
	if (!dword_5d4594_832476) {
		v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_831232, 1010);
		v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 126092), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1656);
		nox_xxx_drawGetStringSize_43F840(v4[59], v5, &a1, 0, 0);
		if (a1 > *(int*)&dword_5d4594_832476)
			dword_5d4594_832476 = a1;
		v6 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 126164), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1660);
		nox_xxx_drawGetStringSize_43F840(v4[59], v6, &a1, 0, 0);
		if (a1 > *(int*)&dword_5d4594_832476)
			dword_5d4594_832476 = a1;
		v7 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 126224), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1664);
		nox_xxx_drawGetStringSize_43F840(v4[59], v7, &a1, 0, 0);
		if (a1 > *(int*)&dword_5d4594_832476)
			dword_5d4594_832476 = a1;
		v8 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 126292), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1668);
		nox_xxx_drawGetStringSize_43F840(v4[59], v8, &a1, 0, 0);
		v9 = dword_5d4594_832476;
		if (a1 > *(int*)&dword_5d4594_832476) {
			v9 = a1;
			dword_5d4594_832476 = a1;
		}
		if (v9 > 85)
			dword_5d4594_832476 = 85;
	}
	return nox_client_lockScreenBriefing_450160(254, 1, 1);
}

//----- (00450980) --------------------------------------------------------
int __cdecl sub_450980(int a1, int a2) {
	char* v2;    // eax
	wchar_t* v3; // eax
	int result;  // eax

	dword_5d4594_832480 = 0;
	sub_431510();
	nox_xxx_bookHideMB_45ACA0(1);
	sub_446780();
	v2 = nox_xxx_gLoadImg_42F970((const char*)(a1 + 5));
	sub_450AD0(v2);
	if (strlen((const char*)(a1 + 37))) {
		v3 = nox_strman_loadString_40F1D0((char*)(a1 + 37), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1714);
		sub_450AF0((int)v3);
	} else {
		sub_450AF0((int)getMemAt(0x5D4594, 832544));
	}
	sub_450B00(*(unsigned __int16*)(a1 + 2));
	if (*(_BYTE*)(a1 + 4) & 2)
		dword_5d4594_832480 = 1;
	result = a2;
	if (a2)
		result = nox_client_lockScreenBriefing_450160(254, 1, 2);
	return result;
}

//----- (00450A30) --------------------------------------------------------
int __cdecl nox_client_showQuestBriefing_450A30(int a1, int a2) {
	char* v2;    // eax
	wchar_t* v3; // eax
	int result;  // eax

	dword_5d4594_832480 = 0;
	sub_431510();
	nox_xxx_bookHideMB_45ACA0(1);
	sub_446780();
	v2 = nox_xxx_gLoadImg_42F970((const char*)(a1 + 5));
	sub_450AD0(v2);
	if (strlen((const char*)(a1 + 37))) {
		v3 = nox_strman_loadString_40F1D0((char*)(a1 + 37), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1756);
		sub_450AF0((int)v3);
	} else {
		sub_450AF0((int)getMemAt(0x5D4594, 832548));
	}
	sub_450B00(*(unsigned __int16*)(a1 + 2));
	result = a2;
	if (a2)
		result = nox_client_lockScreenBriefing_450160(254, 1, 4);
	return result;
}
