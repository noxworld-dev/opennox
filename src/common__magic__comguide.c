#include "common__magic__comguide.h"

#include "common__strman.h"
#include "GAME1_2.h"
#include "GAME2.h"

//----- (00427070) --------------------------------------------------------
int nox_xxx_loadGuides_427070() {
	char** v0;          // ebx
	unsigned char* i; // ebp
	int v2;             // esi
	wchar_t* v3;        // eax
	int v4;             // ecx
	int v5;             // edx
	const char* v6;     // edi
	char* v7;           // eax
	int v8;             // ecx
	int v9;             // edx
	const char* v10;    // edi
	int v11;            // eax
	char v13[256];      // [esp+14h] [ebp-100h]

	v0 = (char**)getMemAt(0x587000, 70504);
	for (i = getMemAt(0x5D4594, 740108);; i += 28) {
		v2 = sub_44D330(*v0);
		if (!v2) {
			break;
}
		nox_sprintf(v13, "creature:%s", *v0);
		*((uint32_t*)i - 1) = nox_strman_loadString_40F1D0(v13, 0, "C:\\NoxPost\\src\\common\\Magic\\ComGuide.c", 57);
		if (!strcmp(*(const char**)v2, "Bomber")) {
			*(uint32_t*)i = 0;
		} else {
			*(uint32_t*)i = nox_xxx_getTTByNameSpriteMB_44CFC0(*v0);
}
		nox_sprintf(v13, "creature_desc:%s", *v0);
		v3 = nox_strman_loadString_40F1D0(v13, 0, "C:\\NoxPost\\src\\common\\Magic\\ComGuide.c", 65);
		v4 = *getMemU32Ptr(0x587000, 71248);
		v5 = *getMemU32Ptr(0x587000, 71252);
		v6 = *v0;
		*((uint32_t*)i + 1) = v3;
		*(uint32_t*)v13 = v4;
		strcpy(&v13[8], "Cage");
		*(uint32_t*)&v13[4] = v5;
		strcat(v13, v6);
		v7 = nox_xxx_gLoadImg_42F970(v13);
		v8 = *getMemU32Ptr(0x587000, 71264);
		v9 = *getMemU32Ptr(0x587000, 71268);
		v10 = *v0;
		*((uint32_t*)i + 2) = v7;
		*(uint32_t*)v13 = v8;
		strcpy(&v13[8], "k");
		*(uint32_t*)&v13[4] = v9;
		strcat(v13, v10);
		*((uint32_t*)i + 3) = nox_xxx_gLoadImg_42F970(v13);
		*((uint32_t*)i + 4) = 0;
		v11 = *(uint32_t*)(v2 + 36);
		if (v11 & 1) {
			i[20] = 1;
		} else if (v11 & 2) {
			i[20] = 2;
		} else {
			i[20] = 4;
		}
		++v0;
		if ((int)v0 >= (int)getMemAt(0x587000, 70664)) {
			return 1;
}
	}
	return 0;
}
