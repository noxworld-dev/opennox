#include "GAME1.h"
#include "GAME1_3.h"
#include "client__gui__guimsg.h"
#include "client__gui__window.h"
#include "client__system__parsecmd.h"
#include "common__strman.h"
#include "defs.h"
#include "operators.h"

//----- (00409FB0) --------------------------------------------------------
void sub_409FB0_settings(short a1, unsigned short a2) {
	int v2;            // eax
	unsigned short v3; // si
	wchar2_t* v4;       // eax

	v2 = sub_409A70(a1);
	v3 = a2;
	if (*getMemU16Ptr(0x5D4594, 3488 + 2 * v2) != a2) {
		if (a2 > 0x3E7u) {
			v3 = 999;
		}
		*getMemU16Ptr(0x5D4594, 3488 + 2 * v2) = v3;
		nox_server_gameSettingsUpdated = 1;
		if (nox_client_isConnected_43C700()) {
			v4 = nox_strman_loadString_40F1D0("parsecmd.c:lessonsset", 0,
											  "C:\\NoxPost\\src\\Common\\System\\settings.c", 389);
			sub_440A20(v4, v3);
		}
	}
}
