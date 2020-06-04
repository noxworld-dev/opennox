#include "tooltip.h"

#include "../../proto.h"
extern _DWORD dword_587000_26048;

//----- (004BF050) --------------------------------------------------------
wchar_t* __cdecl sub_4BF050(wchar_t* a1) {
	int* v1;            // esi
	int v2;             // eax
	const wchar_t* v3;  // ebx
	_DWORD* v4;         // eax
	wchar_t* v5;        // eax
	wchar_t* result;    // eax
	int v7;             // edx
	int v8;             // ecx
	const wchar_t* v9;  // ecx
	int v10;            // ecx
	wchar_t* v11;       // ecx
	const wchar_t* v12; // edi
	int v13;            // eax
	wchar_t* v14;       // eax
	int v15;            // esi
	wchar_t* v16;       // esi
	wchar_t* v17;       // esi
	int v18;            // eax
	int v19;            // eax
	const wchar_t* v20; // eax
	wchar_t* v21;       // eax
	wchar_t* v22;       // eax
	const wchar_t* v23; // eax
	int v24;            // eax
	int v25;            // eax
	wchar_t* v26;       // eax
	wchar_t* v27;       // eax
	const wchar_t* v28; // eax
	int v29;            // eax
	const wchar_t* v30; // eax
	wchar_t* v31;       // eax
	const wchar_t* v32; // eax
	int v33;            // [esp-4h] [ebp-18h]
	wchar_t* v34;       // [esp+Ch] [ebp-8h]
	wchar_t* v35;       // [esp+10h] [ebp-4h]

	*(_WORD*)&byte_5D4594[1317000] = 0;
	nox_wcscpy((wchar_t*)&byte_5D4594[1317000], (const wchar_t*)&byte_5D4594[1319048]);
	v1 = (int*)a1;
	if (!a1)
		return (wchar_t*)&byte_5D4594[1317000];
	v2 = *((_DWORD*)a1 + 28);
	if (!(v2 & 0x13001000)) {
		if (!(v2 & 0x100)) {
			result = (wchar_t*)nox_get_thing_pretty_name(*((_DWORD*)a1 + 27));
			if (result)
				return result;
			return (wchar_t*)&byte_5D4594[1317000];
		}
		v18 = *((_DWORD*)a1 + 29);
		LOBYTE(a1) = -13;
		if (v18 & 1) {
			v19 = v1[108];
			if (!v19) {
				LOBYTE(a1) = -30;
				*(_WORD*)((char*)&a1 + 1) = sub_578B00((int)v1);
				HIBYTE(a1) = 1;
				v1[108] = 137;
				goto LABEL_93;
			}
			if (v19 != 137) {
				if (dword_587000_26048 != 6) {
					v22 = loadString_sub_40F1D0((char*)&byte_587000[180736], 0,
								    "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 292);
					nox_swprintf((wchar_t*)&byte_5D4594[1317000], L"%s ", v22);
					v23 = (const wchar_t*)sub_424930(v1[108]);
					nox_wcscat((wchar_t*)&byte_5D4594[1317000], v23);
					goto LABEL_93;
				}
				v20 = (const wchar_t*)sub_424930(v1[108]);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v20);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				v21 = loadString_sub_40F1D0((char*)&byte_587000[180692], 0,
							    "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 288);
				goto LABEL_90;
			}
			return (wchar_t*)&byte_5D4594[1317000];
		}
		if (v18 & 2) {
			v24 = v1[108];
			if (!v24) {
				LOBYTE(a1) = -30;
				*(_WORD*)((char*)&a1 + 1) = sub_578B00((int)v1);
				HIBYTE(a1) = 2;
				v1[108] = 41;
				goto LABEL_93;
			}
			if (v24 == 41)
				return (wchar_t*)&byte_5D4594[1317000];
			if (dword_587000_26048 == 3 || dword_587000_26048 == 5) {
				v27 = loadString_sub_40F1D0((char*)&byte_587000[180788], 0,
							    "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 313);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v27);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				v28 = (const wchar_t*)sub_427240(v1[108]);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v28);
			} else {
				v25 = sub_427240(v1[108]);
				nox_swprintf((wchar_t*)&byte_5D4594[1317000], L"%s ", v25);
				v26 = loadString_sub_40F1D0((char*)&byte_587000[180848], 0,
							    "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 320);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v26);
			}
		} else if (v18 & 4) {
			v29 = v1[108];
			if (!v29) {
				LOBYTE(a1) = -30;
				*(_WORD*)((char*)&a1 + 1) = sub_578B00((int)v1);
				HIBYTE(a1) = 4;
				v1[108] = 6;
				goto LABEL_93;
			}
			if (v29 == 6)
				return (wchar_t*)&byte_5D4594[1317000];
			if (dword_587000_26048 == 6) {
				v30 = (const wchar_t*)sub_425260(v1[108]);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v30);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				v21 = loadString_sub_40F1D0((char*)&byte_587000[180900], 0,
							    "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 342);
			LABEL_90:
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v21);
				goto LABEL_93;
			}
			v31 = loadString_sub_40F1D0((char*)&byte_587000[180944], 0,
						    "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 346);
			nox_swprintf((wchar_t*)&byte_5D4594[1317000], L"%s ", v31);
			v32 = (const wchar_t*)sub_425260(v1[108]);
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], v32);
		} else {
			result = (wchar_t*)nox_get_thing_pretty_name(v1[27]);
			if (result)
				return result;
		}
	LABEL_93:
		if ((_BYTE)a1 != (_BYTE)-13) {
			sub_4E53C0(31, &a1, 4, 0, 1);
			return (wchar_t*)&byte_5D4594[1317000];
		}
		return (wchar_t*)&byte_5D4594[1317000];
	}
	v3 = 0;
	v34 = 0;
	v35 = 0;
	a1 = 0;
	if (v2 & 0x11001000)
		v4 = sub_413250(v1[27]);
	else
		v4 = sub_413270(v1[27]);
	if (v4) {
		v7 = v1[28] & 0x1000000;
		if (!v7 || v7 == 0x1000000 && !(v1[29] & 0x7800000)) {
			v8 = v1[108];
			if (v8) {
				v9 = *(const wchar_t**)(v8 + 8);
				if (v9)
					v3 = v9;
			}
			v10 = v1[109];
			if (v10) {
				v11 = *(wchar_t**)(v10 + 8);
				if (v11)
					v34 = v11;
			}
		}
		v12 = (const wchar_t*)v4[2];
		if (!v7 || !(v1[29] & 0x7800000)) {
			v13 = v1[110];
			if (v13) {
				v14 = *(wchar_t**)(v13 + 8);
				if (v14)
					v35 = v14;
			}
			v15 = v1[111];
			if (v15) {
				v16 = *(wchar_t**)(v15 + 12);
				if (v16)
					a1 = v16;
			}
		}
		switch (dword_587000_26048) {
		case 2:
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], v12);
			if (v35) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v35);
			}
			v17 = a1;
			if (a1) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v17);
			}
			if (v34) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v34);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
			}
			if (!v3)
				return (wchar_t*)&byte_5D4594[1317000];
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], v3);
			result = (wchar_t*)&byte_5D4594[1317000];
			break;
		case 3:
			if (v3) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v3);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
			}
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], v12);
			if (v34) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v34);
			}
			if (v35) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v35);
			}
			if (!a1)
				return (wchar_t*)&byte_5D4594[1317000];
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
			goto LABEL_67;
		case 5:
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], v12);
			if (v34) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v34);
			}
			if (v3) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v3);
			}
			if (v35) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v35);
			}
			if (!a1)
				return (wchar_t*)&byte_5D4594[1317000];
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], a1);
			result = (wchar_t*)&byte_5D4594[1317000];
			break;
		case 6:
			if (v3) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v3);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
			}
			if (v35) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v35);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
			}
			if (a1) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], a1);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
			}
			if (v34) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v34);
			}
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], v12);
			result = (wchar_t*)&byte_5D4594[1317000];
			break;
		default:
			if (v3) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v3);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
			}
			if (v34) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v34);
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
			}
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], v12);
			if (v35) {
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
				nox_wcscat((wchar_t*)&byte_5D4594[1317000], v35);
			}
			if (!a1)
				return (wchar_t*)&byte_5D4594[1317000];
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], L" ");
		LABEL_67:
			nox_wcscat((wchar_t*)&byte_5D4594[1317000], a1);
			result = (wchar_t*)&byte_5D4594[1317000];
			break;
		}
	} else {
		v33 = nox_get_thing_name(v1[27]);
		v5 = loadString_sub_40F1D0((char*)&byte_587000[180560], 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c",
					   53);
		nox_swprintf((wchar_t*)&byte_5D4594[1317000], v5, v33);
		result = (wchar_t*)&byte_5D4594[1317000];
	}
	return result;
}
