#include "GAME1.h"
#include "GAME3_3.h"
#include "common__strman.h"

//----- (004E77E0) --------------------------------------------------------
wchar_t*  nox_xxx_itemGetName_4E77E0_obj_util(int a1) {
	int v1;            // eax
	uint32_t* v2;        // edi
	uint32_t* v3;        // eax
	uint32_t* v4;        // ebx
	wchar_t* v5;       // eax
	int v7;            // eax
	const wchar_t* v8; // eax
	int v9;            // eax
	int v10;           // eax
	wchar_t* v11;      // eax
	int v12;           // [esp-4h] [ebp-10h]

	v1 = *(uint32_t*)(a1 + 8);
	if (v1 & 0x13001000) {
		v2 = *(uint32_t**)(a1 + 692);
		if (v1 & 0x11001000) {
			v3 = nox_xxx_getProjectileClassById_413250(*(unsigned short*)(a1 + 4));
		} else {
			v3 = nox_xxx_equipClothFindDefByTT_413270(*(unsigned short*)(a1 + 4));
}
		v4 = v3;
		if (!v3) {
			v12 = nox_xxx_getUnitName_4E39D0(a1);
			v5 = nox_strman_loadString_40F1D0("NoInfo", 0, "C:\\NoxPost\\src\\Server\\Object\\objutil.c",
									   983);
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1565660), v5, v12);
			return (wchar_t*)getMemAt(0x5D4594, 1565660);
		}
		nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1565660), (const wchar_t*)getMemAt(0x5D4594, 1567732));
		if (*v2 && *(uint32_t*)(*v2 + 8)) {
			nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1565660), *(const wchar_t**)(*v2 + 8));
			nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1565660), L" ");
		}
		v7 = v2[1];
		if (v7) {
			v8 = *(const wchar_t**)(v7 + 8);
			if (v8) {
				nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1565660), v8);
				nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1565660), L" ");
			}
		}
		if (v4[2]) {
			nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1565660), (const wchar_t*)v4[2]);
}
		v9 = v2[2];
		if (v9 && *(uint32_t*)(v9 + 8)) {
			nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1565660), L" ");
			nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1565660), *(const wchar_t**)(v2[2] + 8));
		}
		v10 = v2[3];
		if (v10 && *(uint32_t*)(v10 + 12)) {
			nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1565660), L" ");
			nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1565660), *(const wchar_t**)(v2[3] + 12));
			return (wchar_t*)getMemAt(0x5D4594, 1565660);
		}
	} else {
		v11 =
			nox_strman_loadString_40F1D0("NoDescription", 0, "C:\\NoxPost\\src\\Server\\Object\\objutil.c", 1032);
		nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1565660), v11);
	}
	return (wchar_t*)getMemAt(0x5D4594, 1565660);
}
