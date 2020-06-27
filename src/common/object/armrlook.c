#include "../../proto.h"

//----- (00415B60) --------------------------------------------------------
wchar_t* __cdecl sub_415B60(int a1) {
	int v1;             // ecx
	int v2;             // edx
	unsigned __int8* i; // eax
	int v4;             // esi

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[34848])
		return loadString_sub_40F1D0((char*)&byte_587000[37836], 0, "C:\\NoxPost\\src\\common\\Object\\ArmrLook.c",
									 263);
	HIWORD(v2) = 0;
	for (i = &byte_587000[34848];; i += 24) {
		LOWORD(v2) = *(_WORD*)(a1 + 4);
		if (v2 == *((_DWORD*)i + 2))
			break;
		v4 = *((_DWORD*)i + 6);
		++v1;
		if (!v4)
			return loadString_sub_40F1D0((char*)&byte_587000[37836], 0, "C:\\NoxPost\\src\\common\\Object\\ArmrLook.c",
										 263);
	}
	return loadString_sub_40F1D0(*(char**)&byte_587000[24 * v1 + 34852], 0,
								 "C:\\NoxPost\\src\\common\\Object\\ArmrLook.c", 261);
}

//----- (00415D50) --------------------------------------------------------
char** sub_415D50() {
	char** result;       // eax
	unsigned __int8* v1; // esi
	int v2;              // ecx

	result = *(char***)&byte_5D4594[371256];
	if (!*(_DWORD*)&byte_5D4594[371256]) {
		result = *(char***)&byte_587000[35500];
		if (*(_DWORD*)&byte_587000[35500]) {
			result = (char**)&byte_587000[35500];
			v1 = &byte_587000[35500];
			do {
				*((_DWORD*)v1 - 1) =
					loadString_sub_40F1D0(*result, 0, "C:\\NoxPost\\src\\common\\Object\\ArmrLook.c", 380);
				v2 = *((_DWORD*)v1 + 3);
				v1 += 12;
				result = (char**)v1;
			} while (v2);
		}
		*(_DWORD*)&byte_5D4594[371256] = 1;
	}
	return result;
}