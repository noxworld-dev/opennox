#include "common__wolapi__wol.h"
#include "common__log.h"
#include "common__strman.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "client__gui__window.h"
extern uint32_t dword_5d4594_2660652;

//----- (0041D1D0) --------------------------------------------------------
uint32_t*  nox_xxx_wolApiError_41D1D0(int a1) {
	wchar_t* v1;         // edi
	wchar_t* v2;         // eax
	int v3;              // eax
	int v4;              // esi
	size_t v5;           // eax
	unsigned char* v6; // esi
	uint32_t* result;      // eax

	v1 = nox_strman_loadString_40F1D0("WolApiError", 0, "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 41);
	if (*(int*)&dword_5d4594_2660652 > -2147221247) {
		if (dword_5d4594_2660652) {
			v2 = nox_strman_loadString_40F1D0("UnknownError", 0, "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 123);
		} else {
			v2 = nox_strman_loadString_40F1D0("Internalerror", 0, "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 117);
}
		v6 = (unsigned char*)v2;
	} else if (*(int*)&dword_5d4594_2660652 >= -2147221248) {
		v6 = getMemAt(0x85B3FC, 10436);
	} else {
		switch (*(int *) &dword_5d4594_2660652 + 2147221404) {
			case 0:
				v2 = nox_strman_loadString_40F1D0("NickInUse", 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 64);
				break;
			case 1:
				v2 = nox_strman_loadString_40F1D0("InvalidPass", 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 68);
				break;
			case 3:
				v2 = nox_strman_loadString_40F1D0("ConnectionNetDown", 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 56);
				break;
			case 4:
				v2 = nox_strman_loadString_40F1D0("ConnectionLookupError", 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 52);
				break;
			case 5:
				v2 = nox_strman_loadString_40F1D0("ConnectionError", 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 48);
				break;
			case 6:
				v2 = nox_strman_loadString_40F1D0("Timeout", 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 60);
				break;
			case 8:
				v2 = nox_strman_loadString_40F1D0("registryhosed", 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 72);
				break;
			case 14:
				v3 = sub_4207E0();
				v4 = v3;
				if (v3) {
					v5 = strcspn((const char *) (v3 + 24), ":");
					if (!strncmp("Official Nox Games for New Players", (const char *) (v5 + v4 + 25), 0x22u)) {
						v1 = nox_strman_loadString_40F1D0("Guiserv.c:Notice", 0,
												   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c",
												   96);
						v2 = nox_strman_loadString_40F1D0("TooSkilled", 0,
												   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c",
												   97);
					} else {
						v2 = nox_strman_loadString_40F1D0("banned", 0,
												   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c",
												   101);
					}
				} else {
					v2 = nox_strman_loadString_40F1D0("banned", 0,
											   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c",
											   106);
				}
				break;
			case 16:
				v2 = nox_strman_loadString_40F1D0("DisabledError", 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 44);
				break;
			case 17:
				v2 = nox_strman_loadString_40F1D0("serialbanned", 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 76);
				break;
			case 18:
				v2 = nox_strman_loadString_40F1D0("serialdupe", 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 80);
				break;
			default:
				v2 = nox_strman_loadString_40F1D0("UnknownError", 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 123);
				break;
		}
		v6 = (unsigned char *) v2;
	}
	sub_44A400();
	if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
		nox_xxx_networkLog_printf_413D30("%S %S", v1, v6);
		nox_xxx_setContinueMenuOrHost_43DDD0(0);
		nox_game_exit_xxx_43DE60();
	}
	if (a1) {
		result = sub_44AFB0((int)v1, (int)v6, *(int*)&dword_5d4594_2660652);
	} else {
		result = nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v1, (int)v6, 33, 0, 0);
}
	return result;
}
