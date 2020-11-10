#include "wol.h"

#include "../../proto.h"
extern _DWORD dword_5d4594_2660652;

//----- (0041D1D0) --------------------------------------------------------
_DWORD* __cdecl nox_xxx_wolApiError_41D1D0(int a1) {
	wchar_t* v1;         // edi
	wchar_t* v2;         // eax
	int v3;              // eax
	int v4;              // esi
	size_t v5;           // eax
	unsigned __int8* v6; // esi
	_DWORD* result;      // eax

	v1 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 57204), 0, "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 41);
	if (*(int*)&dword_5d4594_2660652 > -2147221247) {
		if (dword_5d4594_2660652)
			v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 58048), 0, "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 123);
		else
			v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 57996), 0, "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 117);
		v6 = (unsigned __int8*)v2;
	} else if (*(int*)&dword_5d4594_2660652 >= -2147221248) {
		v6 = getMemAt(0x5D4594, 2660140);
	} else {
		switch (*(int *) &dword_5d4594_2660652 + 2147221404) {
			case 0:
				v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57516), 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 64);
				break;
			case 1:
				v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57564), 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 68);
				break;
			case 3:
				v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57416), 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 56);
				break;
			case 4:
				v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57356), 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 52);
				break;
			case 5:
				v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57304), 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 48);
				break;
			case 6:
				v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57472), 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 60);
				break;
			case 8:
				v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57612), 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 72);
				break;
			case 14:
				v3 = sub_4207E0();
				v4 = v3;
				if (v3) {
					v5 = strcspn((const char *) (v3 + 24), ":");
					if (!strncmp("Official Nox Games for New Players", (const char *) (v5 + v4 + 25), 0x22u)) {
						v1 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57804), 0,
												   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c",
												   96);
						v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57860), 0,
												   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c",
												   97);
					} else {
						v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57908), 0,
												   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c",
												   101);
					}
				} else {
					v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57952), 0,
											   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c",
											   106);
				}
				break;
			case 16:
				v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57252), 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 44);
				break;
			case 17:
				v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57664), 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 76);
				break;
			case 18:
				v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 57716), 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 80);
				break;
			default:
				v2 = nox_xxx_loadString_40F1D0((char *) getMemAt(0x587000, 58048), 0,
										   "C:\\NoxPost\\src\\common\\WolAPI\\wol.c", 123);
				break;
		}
		v6 = (unsigned __int8 *) v2;
	}
	sub_44A400();
	if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
		nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 58064), v1, v6);
		nox_xxx_setContinueMenuOrHost_43DDD0(0);
		nox_game_exit_xxx_43DE60();
	}
	if (a1)
		result = sub_44AFB0((int)v1, (int)v6, *(int*)&dword_5d4594_2660652);
	else
		result = nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v1, (int)v6, 33, 0, 0);
	return result;
}
