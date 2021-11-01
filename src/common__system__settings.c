#include "client__gui__guimsg.h"
#include "client__system__parsecmd.h"
#include "GAME1.h"
#include "GAME1_3.h"
#include "client__gui__window.h"
#include "defs.h"
#include "common__strman.h"
#include "operators.h"

extern uint32_t dword_5d4594_3592;

//----- (00409FB0) --------------------------------------------------------
void  sub_409FB0_settings(short a1, unsigned short a2) {
	int v2;              // eax
	unsigned short v3; // si
	wchar_t* v4;         // eax

	v2 = sub_409A70(a1);
	v3 = a2;
	if (*getMemU16Ptr(0x5D4594, 3488 + 2 * v2) != a2) {
		if (a2 > 0x3E7u)
			v3 = 999;
		*getMemU16Ptr(0x5D4594, 3488 + 2 * v2) = v3;
		nox_server_gameSettingsUpdated = 1;
		if (nox_client_isConnected_43C700()) {
			v4 = nox_strman_loadString_40F1D0("parsecmd.c:lessonsset", 0, "C:\\NoxPost\\src\\Common\\System\\settings.c",
									   389);
			sub_440A20(v4, v3);
		}
	}
}

//----- (0040A040) --------------------------------------------------------
void  sub_40A040_settings(short a1, unsigned char a2) {
	int v2;      // edi
	wchar_t* v3; // eax
	int v4;      // eax
	wchar_t* v5; // eax
	wchar_t* v6; // eax

	v2 = sub_409A70(a1);
	if (getMemByte(0x5D4594, 3500 + v2) == a2) {
		return;
	}
	if (!(!nox_common_gameFlags_check_40A5C0(0x4000000) && !dword_5d4594_3592)) {
		v6 = nox_strman_loadString_40F1D0("NotInSuddenDeath", 0, "C:\\NoxPost\\src\\Common\\System\\settings.c", 414);
		nox_xxx_printCentered_445490(v6);
		return;
	}
	nox_server_gameSettingsUpdated = 1;
	if (nox_client_isConnected_43C700()) {
		if (!a2) {
			v5 = nox_strman_loadString_40F1D0("parsecmd.c:timedisabled", 0,
									   "C:\\NoxPost\\src\\Common\\System\\settings.c", 431);
			sub_440A20(v5);
		} else {
			v3 = nox_strman_loadString_40F1D0("parsecmd.c:timeset", 0, "C:\\NoxPost\\src\\Common\\System\\settings.c",
									   423);
			sub_440A20(v3, a2);
			LOBYTE(v4) = nox_xxx_gamePlayIsAnyPlayers_40A8A0();
			if (!v4) {
				v5 = nox_strman_loadString_40F1D0("TimeLimitDeferred", 0,
										   "C:\\NoxPost\\src\\Common\\System\\settings.c", 426);
				sub_440A20(v5);
			}
		}
	}
	*getMemU8Ptr(0x5D4594, 3500 + v2) = a2;
	*getMemU64Ptr(0x5D4594, 3468) = 60000 * a2 + nox_platform_get_ticks();
}
// 40A0D1: variable 'v4' is possibly undefined
