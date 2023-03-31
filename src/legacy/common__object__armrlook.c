#include "memmap.h"
#include "client__gui__window.h"
#include "common__strman.h"
#include "operators.h"

//----- (00415B60) --------------------------------------------------------
wchar2_t* sub_415B60(int a1) {
	int v1;           // ecx
	int v2;           // edx
	unsigned char* i; // eax
	int v4;           // esi

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 34848)) {
		return nox_strman_loadString_40F1D0("result:ERROR", 0, "C:\\NoxPost\\src\\common\\Object\\ArmrLook.c", 263);
	}
	HIWORD(v2) = 0;
	for (i = getMemAt(0x587000, 34848);; i += 24) {
		LOWORD(v2) = *(uint16_t*)(a1 + 4);
		if (v2 == *((uint32_t*)i + 2)) {
			break;
		}
		v4 = *((uint32_t*)i + 6);
		++v1;
		if (!v4) {
			return nox_strman_loadString_40F1D0("result:ERROR", 0, "C:\\NoxPost\\src\\common\\Object\\ArmrLook.c", 263);
		}
	}
	return nox_strman_loadString_40F1D0(*(char**)getMemAt(0x587000, 34852 + 24 * v1), 0,
										"C:\\NoxPost\\src\\common\\Object\\ArmrLook.c", 261);
}

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
