#include "common__object__weaplook.h"
#include "common__strman.h"

//----- (004158C0) --------------------------------------------------------
char** nox_xxx_loadModifyers_4158C0() {
	char** result;       // eax
	unsigned char* v1; // esi
	int v2;              // ecx

	result = *(char***)getMemAt(0x5D4594, 371248);
	if (!*getMemU32Ptr(0x5D4594, 371248)) {
		result = *(char***)getMemAt(0x587000, 33396);
		if (*getMemU32Ptr(0x587000, 33396)) {
			result = (char**)getMemAt(0x587000, 33396);
			v1 = getMemAt(0x587000, 33396);
			do {
				*((uint32_t*)v1 - 1) =
					nox_strman_loadString_40F1D0(*result, 0, "C:\\NoxPost\\src\\common\\Object\\WeapLook.c", 200);
				v2 = *((uint32_t*)v1 + 3);
				v1 += 12;
				result = (char**)v1;
			} while (v2);
		}
		*getMemU32Ptr(0x5D4594, 371248) = 1;
	}
	return result;
}
