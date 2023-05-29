#include "client__gui__tooltip.h"
#include "common__strman.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME2.h"
#include "GAME3_3.h"
#include "GAME5_2.h"
#include "client__gui__window.h"
#include "common__magic__speltree.h"
#include "operators.h"

//----- (004BF050) --------------------------------------------------------
wchar2_t* nox_xxx_clientAskInfoMb_4BF050(nox_drawable* a1p) {
	wchar2_t* a1 = a1p;
	int* v1;            // esi
	int v2;             // eax
	const wchar2_t* v3;  // ebx
	uint32_t* v4;       // eax
	wchar2_t* v5;        // eax
	wchar2_t* result;    // eax
	int v7;             // edx
	int v8;             // ecx
	const wchar2_t* v9;  // ecx
	int v10;            // ecx
	wchar2_t* v11;       // ecx
	const wchar2_t* v12; // edi
	int v13;            // eax
	wchar2_t* v14;       // eax
	int v15;            // esi
	wchar2_t* v16;       // esi
	wchar2_t* v17;       // esi
	int v18;            // eax
	int v19;            // eax
	const wchar2_t* v20; // eax
	wchar2_t* v21;       // eax
	wchar2_t* v22;       // eax
	const wchar2_t* v23; // eax
	int v24;            // eax
	int v25;            // eax
	wchar2_t* v26;       // eax
	wchar2_t* v27;       // eax
	const wchar2_t* v28; // eax
	int v29;            // eax
	const wchar2_t* v30; // eax
	wchar2_t* v31;       // eax
	const wchar2_t* v32; // eax
	int v33;            // [esp-4h] [ebp-18h]
	wchar2_t* v34;       // [esp+Ch] [ebp-8h]
	wchar2_t* v35;       // [esp+10h] [ebp-4h]

	*getMemU16Ptr(0x5D4594, 1317000) = 0;
	nox_wcscpy((wchar2_t*)getMemAt(0x5D4594, 1317000), (const wchar2_t*)getMemAt(0x5D4594, 1319048));
	v1 = (int*)a1;
	if (!a1) {
		return (wchar2_t*)getMemAt(0x5D4594, 1317000);
	}
	v2 = *((uint32_t*)a1 + 28);
	if (!(v2 & 0x13001000)) {
		if (!(v2 & 0x100)) {
			result = (wchar2_t*)nox_get_thing_pretty_name(*((uint32_t*)a1 + 27));
			if (result) {
				return result;
			}
			return (wchar2_t*)getMemAt(0x5D4594, 1317000);
		}
		v18 = *((uint32_t*)a1 + 29);
		LOBYTE(a1) = -13;
		if (v18 & 1) {
			v19 = v1[108];
			if (!v19) {
				LOBYTE(a1) = -30;
				*(uint16_t*)((char*)&a1 + 1) = nox_xxx_netGetUnitCodeCli_578B00((int)v1);
				HIBYTE(a1) = 1;
				v1[108] = 137;
				goto LABEL_93;
			}
			if (v19 != 137) {
				if (nox_strman_get_lang_code() != 6) {
					v22 = nox_strman_loadString_40F1D0("BookOf", 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 292);
					nox_swprintf((wchar2_t*)getMemAt(0x5D4594, 1317000), L"%s ", v22);
					v23 = (const wchar2_t*)nox_xxx_spellTitle_424930(v1[108]);
					nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v23);
					goto LABEL_93;
				}
				v20 = (const wchar2_t*)nox_xxx_spellTitle_424930(v1[108]);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v20);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				v21 = nox_strman_loadString_40F1D0("BookOf", 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 288);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v21);
				goto LABEL_93;
			}
			return (wchar2_t*)getMemAt(0x5D4594, 1317000);
		}
		if (v18 & 2) {
			v24 = v1[108];
			if (!v24) {
				LOBYTE(a1) = -30;
				*(uint16_t*)((char*)&a1 + 1) = nox_xxx_netGetUnitCodeCli_578B00((int)v1);
				HIBYTE(a1) = 2;
				v1[108] = 41;
				goto LABEL_93;
			}
			if (v24 == 41) {
				return (wchar2_t*)getMemAt(0x5D4594, 1317000);
			}
			if (nox_strman_get_lang_code() == 3 || nox_strman_get_lang_code() == 5) {
				v27 = nox_strman_loadString_40F1D0("LoreScroll", 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 313);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v27);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				v28 = (const wchar2_t*)nox_xxx_guiCreatureGetName_427240(v1[108]);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v28);
			} else {
				v25 = nox_xxx_guiCreatureGetName_427240(v1[108]);
				nox_swprintf((wchar2_t*)getMemAt(0x5D4594, 1317000), L"%s ", v25);
				v26 = nox_strman_loadString_40F1D0("LoreScroll", 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 320);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v26);
			}
		} else if (v18 & 4) {
			v29 = v1[108];
			if (!v29) {
				LOBYTE(a1) = -30;
				*(uint16_t*)((char*)&a1 + 1) = nox_xxx_netGetUnitCodeCli_578B00((int)v1);
				HIBYTE(a1) = 4;
				v1[108] = 6;
				goto LABEL_93;
			}
			if (v29 == 6) {
				return (wchar2_t*)getMemAt(0x5D4594, 1317000);
			}
			if (nox_strman_get_lang_code() == 6) {
				v30 = (const wchar2_t*)nox_xxx_abilityGetName_0_425260(v1[108]);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v30);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				v21 = nox_strman_loadString_40F1D0("BookOf", 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 342);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v21);
				goto LABEL_93;
			}
			v31 = nox_strman_loadString_40F1D0("BookOf", 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 346);
			nox_swprintf((wchar2_t*)getMemAt(0x5D4594, 1317000), L"%s ", v31);
			v32 = (const wchar2_t*)nox_xxx_abilityGetName_0_425260(v1[108]);
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v32);
		} else {
			result = (wchar2_t*)nox_get_thing_pretty_name(v1[27]);
			if (result) {
				return result;
			}
		}
	LABEL_93:
		if ((uint8_t)a1 != (uint8_t)-13) {
			nox_xxx_netClientSend2_4E53C0(31, &a1, 4, 0, 1);
			return (wchar2_t*)getMemAt(0x5D4594, 1317000);
		}
		return (wchar2_t*)getMemAt(0x5D4594, 1317000);
	}
	v3 = 0;
	v34 = 0;
	v35 = 0;
	a1 = 0;
	if (v2 & 0x11001000) {
		v4 = nox_xxx_getProjectileClassById_413250(v1[27]);
	} else {
		v4 = nox_xxx_equipClothFindDefByTT_413270(v1[27]);
	}
	if (v4) {
		v7 = v1[28] & 0x1000000;
		if (!v7 || v7 == 0x1000000 && !(v1[29] & 0x7800000)) {
			v8 = v1[108];
			if (v8) {
				v9 = *(const wchar2_t**)(v8 + 8);
				if (v9) {
					v3 = v9;
				}
			}
			v10 = v1[109];
			if (v10) {
				v11 = *(wchar2_t**)(v10 + 8);
				if (v11) {
					v34 = v11;
				}
			}
		}
		v12 = (const wchar2_t*)v4[2];
		if (!v7 || !(v1[29] & 0x7800000)) {
			v13 = v1[110];
			if (v13) {
				v14 = *(wchar2_t**)(v13 + 8);
				if (v14) {
					v35 = v14;
				}
			}
			v15 = v1[111];
			if (v15) {
				v16 = *(wchar2_t**)(v15 + 12);
				if (v16) {
					a1 = v16;
				}
			}
		}
		switch (nox_strman_get_lang_code()) {
		case 2:
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v12);
			if (v35) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v35);
			}
			v17 = a1;
			if (a1) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v17);
			}
			if (v34) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v34);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
			}
			if (!v3) {
				return (wchar2_t*)getMemAt(0x5D4594, 1317000);
			}
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v3);
			result = (wchar2_t*)getMemAt(0x5D4594, 1317000);
			break;
		case 3:
			if (v3) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v3);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
			}
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v12);
			if (v34) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v34);
			}
			if (v35) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v35);
			}
			if (!a1) {
				return (wchar2_t*)getMemAt(0x5D4594, 1317000);
			}
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), a1);
			result = (wchar2_t*)getMemAt(0x5D4594, 1317000);
			break;
		case 5:
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v12);
			if (v34) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v34);
			}
			if (v3) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v3);
			}
			if (v35) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v35);
			}
			if (!a1) {
				return (wchar2_t*)getMemAt(0x5D4594, 1317000);
			}
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), a1);
			result = (wchar2_t*)getMemAt(0x5D4594, 1317000);
			break;
		case 6:
			if (v3) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v3);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
			}
			if (v35) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v35);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
			}
			if (a1) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), a1);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
			}
			if (v34) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v34);
			}
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v12);
			result = (wchar2_t*)getMemAt(0x5D4594, 1317000);
			break;
		default:
			if (v3) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v3);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
			}
			if (v34) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v34);
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
			}
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v12);
			if (v35) {
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
				nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), v35);
			}
			if (!a1) {
				return (wchar2_t*)getMemAt(0x5D4594, 1317000);
			}
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), L" ");
			nox_wcscat((wchar2_t*)getMemAt(0x5D4594, 1317000), a1);
			result = (wchar2_t*)getMemAt(0x5D4594, 1317000);
			break;
		}
	} else {
		v33 = nox_get_thing_name(v1[27]);
		v5 = nox_strman_loadString_40F1D0("NoArmsInfo", 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 53);
		nox_swprintf((wchar2_t*)getMemAt(0x5D4594, 1317000), v5, v33);
		result = (wchar2_t*)getMemAt(0x5D4594, 1317000);
	}
	return result;
}
