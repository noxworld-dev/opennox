#include "../../proto.h"

//----- (004E39F0) --------------------------------------------------------
wchar_t* __cdecl sub_4E39F0_obj_db(const char** a1) {
	const char* v1;      // esi
	char* v2;            // eax
	const char* v3;      // eax
	const char* v4;      // edx
	unsigned __int8 v5;  // al
	unsigned __int8* v6; // ecx
	unsigned __int8* i;  // edx

	v1 = *a1;
	if (!*a1)
		v1 = (const char*)nox_xxx_getUnitName_4E39D0((int)a1);
	v2 = strrchr(v1, 58);
	if (v2)
		v3 = v2 + 1;
	else
		v3 = v1;
	v4 = v3;
	strcpy((char*)getMemAt(0x5D4594, 1563460), "NPC:");
	v5 = *v3;
	v6 = getMemAt(0x5D4594, strlen((const char*)getMemAt(0x5D4594, 1563460)) + 1563460);
	for (i = (unsigned __int8*)(v4 + 1); v5; ++i) {
		if (v5 != 95)
			*v6++ = v5;
		v5 = *i;
	}
	*v6 = 0;
	return nox_strman_loadString_40F1D0((char*)getMemAt(0x5D4594, 1563460), 0, "C:\\NoxPost\\src\\Server\\DBase\\objdb.c", 1577);
}