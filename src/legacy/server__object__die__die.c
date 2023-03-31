#include "common__object__armrlook.h"
#include "server__object__objutil.h"

#include "GAME1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "common__strman.h"

// TODO: convert table_274080

//----- (0054E170) --------------------------------------------------------
void nox_xxx_dieArmor_54E170_obj_die(int a1) {
	int v1;       // ebx
	int v2;       // edi
	uint32_t* v3; // eax
	short v4;     // ax
	int v5;       // ebp
	short v6;     // ax
	wchar2_t* v7;  // esi
	int v8;       // edi
	wchar2_t* v9;  // eax
	float2* v10;  // [esp+14h] [ebp+4h]

	v1 = a1;
	v2 = 0;
	if (!nox_strman_get_lang_code() || nox_strman_get_lang_code() == 1) {
		v3 = nox_xxx_equipClothFindDefByTT_413270(*(unsigned short*)(a1 + 4));
		if (v3) {
			v4 = *(uint16_t*)(v3[2] + 2 * nox_wcslen((const wchar2_t*)v3[2]) - 2);
			if (v4 == 83 || v4 == 115) {
				v2 = 1;
			}
		}
	}
	v5 = *(uint32_t*)(a1 + 492);
	if (v5) {
		v10 = (float2*)(v5 + 56);
	} else {
		v10 = (float2*)(a1 + 56);
	}
	v6 = *(uint16_t*)(v1 + 24);
	if (v6 & 0x10) {
		if (v2) {
			v7 = nox_strman_loadString_40F1D0("ArmorDieMetalPlural", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c",
											  1536);
		} else {
			v7 = nox_strman_loadString_40F1D0("ArmorDieMetal", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1538);
		}
		v8 = 806;
	} else if (v6 & 8) {
		if (v2) {
			v7 = nox_strman_loadString_40F1D0("ArmorDieWoodPlural", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c",
											  1547);
		} else {
			v7 = nox_strman_loadString_40F1D0("ArmorDieWood", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1549);
		}
		v8 = 812;
	} else if (v6 & 4) {
		if (v2) {
			v7 = nox_strman_loadString_40F1D0("ArmorDieHidePlural", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c",
											  1558);
		} else {
			v7 = nox_strman_loadString_40F1D0("ArmorDieHide", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1560);
		}
		v8 = 809;
	} else if (v6 & 2) {
		if (v2) {
			v7 = nox_strman_loadString_40F1D0("ArmorDieClothPlural", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c",
											  1569);
		} else {
			v7 = nox_strman_loadString_40F1D0("ArmorDieCloth", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1571);
		}
		v8 = 815;
	} else {
		v8 = (int)v10;
		v7 = nox_strman_loadString_40F1D0("ArmorDieGeneric", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1579);
	}
	v9 = nox_xxx_itemGetName_4E77E0_obj_util(v1);
	nox_xxx_netSendLineMessage_4D9EB0(v5, v7, v9);
	nox_xxx_audCreate_501A30(v8, v10, 0, 0);
	nox_xxx_delayedDeleteObject_4E5CC0(v1);
}

//----- (0054E370) --------------------------------------------------------
void nox_xxx_dieWeapon_54E370_obj_die(int a1) {
	int v1;      // edi
	float2* v2;  // ebx
	short v3;    // ax
	wchar2_t* v4; // eax
	wchar2_t* v5; // eax
	wchar2_t* v6; // eax
	wchar2_t* v7; // [esp-4h] [ebp-10h]
	wchar2_t* v8; // [esp-4h] [ebp-10h]
	wchar2_t* v9; // [esp-4h] [ebp-10h]

	v1 = *(uint32_t*)(a1 + 492);
	v2 = (float2*)(v1 + 56);
	if (!v1) {
		v2 = (float2*)(a1 + 56);
	}
	v3 = *(uint16_t*)(a1 + 24);
	if (v3 & 0x10) {
		v7 = nox_xxx_itemGetName_4E77E0_obj_util(a1);
		v4 = nox_strman_loadString_40F1D0("WeaponDieMetal", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1626);
		nox_xxx_netSendLineMessage_4D9EB0(v1, v4, v7);
		nox_xxx_audCreate_501A30(818, v2, 0, 0);
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	} else {
		if (v3 & 8) {
			v8 = nox_xxx_itemGetName_4E77E0_obj_util(a1);
			v5 = nox_strman_loadString_40F1D0("WeaponDieWood", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1633);
			nox_xxx_netSendLineMessage_4D9EB0(v1, v5, v8);
			nox_xxx_audCreate_501A30(819, v2, 0, 0);
		} else {
			v9 = sub_415B60(a1);
			v6 = nox_strman_loadString_40F1D0("WeaponDieGeneric", 0, "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c",
											  1640);
			nox_xxx_netSendLineMessage_4D9EB0(v1, v6, v9);
		}
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}
