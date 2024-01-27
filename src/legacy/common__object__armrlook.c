#include "memmap.h"
#include "client__gui__window.h"
#include "common__strman.h"
#include "operators.h"

//----- (00415D50) --------------------------------------------------------
char** nox_xxx_loadLook_415D50() {
	char** result;     // eax
	unsigned char* v1; // esi
	int v2;            // ecx

	result = *(char***)getMemAt(0x5D4594, 371256);
	if (!*getMemU32Ptr(0x5D4594, 371256)) {
		result = *(char***)getMemAt(0x587000, 35500);
		if (*getMemU32Ptr(0x587000, 35500)) {
			result = (char**)getMemAt(0x587000, 35500);
			v1 = getMemAt(0x587000, 35500);
			do {
				*((uint32_t*)v1 - 1) =
					nox_strman_loadString_40F1D0(*result, 0, "C:\\NoxPost\\src\\common\\Object\\ArmrLook.c", 380);
				v2 = *((uint32_t*)v1 + 3);
				v1 += 12;
				result = (char**)v1;
			} while (v2);
		}
		*getMemU32Ptr(0x5D4594, 371256) = 1;
	}
	return result;
}
