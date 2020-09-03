#include "../../proto.h"

//----- (004158C0) --------------------------------------------------------
char** sub_4158C0() {
	char** result;       // eax
	unsigned __int8* v1; // esi
	int v2;              // ecx

	result = *(char***)getMemAt(0x5D4594, 371248);
	if (!*(_DWORD*)getMemAt(0x5D4594, 371248)) {
		result = *(char***)getMemAt(0x587000, 33396);
		if (*(_DWORD*)getMemAt(0x587000, 33396)) {
			result = (char**)getMemAt(0x587000, 33396);
			v1 = getMemAt(0x587000, 33396);
			do {
				*((_DWORD*)v1 - 1) =
					loadString_sub_40F1D0(*result, 0, "C:\\NoxPost\\src\\common\\Object\\WeapLook.c", 200);
				v2 = *((_DWORD*)v1 + 3);
				v1 += 12;
				result = (char**)v1;
			} while (v2);
		}
		*(_DWORD*)getMemAt(0x5D4594, 371248) = 1;
	}
	return result;
}