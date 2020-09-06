#include "../../client/gui/guimsg.h"
#include "../../client/system/parsecmd.h"
#include "../../proto.h"
extern _DWORD dword_5d4594_3592;

//----- (00409FB0) --------------------------------------------------------
void __cdecl sub_409FB0_settings(__int16 a1, unsigned __int16 a2) {
	int v2;              // eax
	unsigned __int16 v3; // si
	wchar_t* v4;         // eax

	v2 = sub_409A70(a1);
	v3 = a2;
	if (*getMemU16Ptr(0x5D4594, 2 * v2 + 3488) != a2) {
		if (a2 > 0x3E7u)
			v3 = 999;
		*getMemU16Ptr(0x5D4594, 2 * v2 + 3488) = v3;
		*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
		if (nox_client_isConnected_43C700()) {
			v4 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 4804), 0, "C:\\NoxPost\\src\\Common\\System\\settings.c",
									   389);
			sub_440A20(v4, v3);
		}
	}
}

//----- (0040A040) --------------------------------------------------------
void __cdecl sub_40A040_settings(__int16 a1, unsigned __int8 a2) {
	int v2;      // edi
	wchar_t* v3; // eax
	int v4;      // eax
	wchar_t* v5; // eax
	wchar_t* v6; // eax

	v2 = sub_409A70(a1);
	if (getMemByte(0x5D4594, v2 + 3500) == a2) {
		return;
	}
	if (!(!nox_common_gameFlags_check_40A5C0(0x4000000) && !dword_5d4594_3592)) {
		v6 = loadString_sub_40F1D0((char *) getMemAt(0x587000, 4868), 0, "C:\\NoxPost\\src\\Common\\System\\settings.c", 414);
		sub_445490(v6);
		return;
	}
	*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
	if (nox_client_isConnected_43C700()) {
		if (!a2) {
			v5 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 5048), 0,
									   "C:\\NoxPost\\src\\Common\\System\\settings.c", 431);
			sub_440A20(v5);
		} else {
			v3 = loadString_sub_40F1D0((char *) getMemAt(0x587000, 4928), 0, "C:\\NoxPost\\src\\Common\\System\\settings.c",
									   423);
			sub_440A20(v3, a2);
			LOBYTE(v4) = sub_40A8A0();
			if (!v4) {
				v5 = loadString_sub_40F1D0((char *) getMemAt(0x587000, 4988), 0,
										   "C:\\NoxPost\\src\\Common\\System\\settings.c", 426);
				sub_440A20(v5);
			}
		}
	}
	*getMemU8Ptr( 0x5D4594, v2 + 3500) = a2;
	*getMemU64Ptr(0x5D4594, 3468) = 60000 * a2 + sub_416BB0();
}
// 40A0D1: variable 'v4' is possibly undefined
