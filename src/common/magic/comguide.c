#include "comguide.h"

#include "../../proto.h"

//----- (00427070) --------------------------------------------------------
int sub_427070() {
	CHAR** v0;          // ebx
	unsigned __int8* i; // ebp
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

	v0 = (CHAR**)&byte_587000[70504];
	for (i = &byte_5D4594[740108];; i += 28) {
		v2 = sub_44D330(*v0);
		if (!v2)
			break;
		nox_sprintf(v13, "creature:%s", *v0);
		*((_DWORD*)i - 1) = loadString_sub_40F1D0(v13, 0, "C:\\NoxPost\\src\\common\\Magic\\ComGuide.c", 57);
		if (!strcmp(*(const char**)v2, "Bomber"))
			*(_DWORD*)i = 0;
		else
			*(_DWORD*)i = sub_44CFC0(*v0);
		nox_sprintf(v13, "creature_desc:%s", *v0);
		v3 = loadString_sub_40F1D0(v13, 0, "C:\\NoxPost\\src\\common\\Magic\\ComGuide.c", 65);
		v4 = *(_DWORD*)&byte_587000[71248];
		v5 = *(_DWORD*)&byte_587000[71252];
		v6 = *v0;
		*((_DWORD*)i + 1) = v3;
		*(_DWORD*)v13 = v4;
		strcpy(&v13[8], "Cage");
		*(_DWORD*)&v13[4] = v5;
		strcat(v13, v6);
		v7 = sub_42F970(v13);
		v8 = *(_DWORD*)&byte_587000[71264];
		v9 = *(_DWORD*)&byte_587000[71268];
		v10 = *v0;
		*((_DWORD*)i + 2) = v7;
		*(_DWORD*)v13 = v8;
		strcpy(&v13[8], "k");
		*(_DWORD*)&v13[4] = v9;
		strcat(v13, v10);
		*((_DWORD*)i + 3) = sub_42F970(v13);
		*((_DWORD*)i + 4) = 0;
		v11 = *(_DWORD*)(v2 + 36);
		if (v11 & 1) {
			i[20] = 1;
		} else if (v11 & 2) {
			i[20] = 2;
		} else {
			i[20] = 4;
		}
		++v0;
		if ((int)v0 >= (int)&byte_587000[70664])
			return 1;
	}
	return 0;
}
