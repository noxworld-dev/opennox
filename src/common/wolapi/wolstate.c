#include "wolstate.h"

#include "../../client/shell/wolapi/wolreg.h"
#include "../../proto.h"

//----- (0041DAC0) --------------------------------------------------------
wchar_t* __cdecl sub_41DAC0(int a1) {
	wchar_t* result; // eax

	switch (a1 + 2147221402) {
	case 0:
		result = loadString_sub_40F1D0((char*)&byte_587000[58600], 0,
					       "C:\\NoxPost\\src\\common\\WolAPI\\wolstate.c", 196);
		break;
	case 8:
		result = loadString_sub_40F1D0((char*)&byte_587000[58496], 0,
					       "C:\\NoxPost\\src\\common\\WolAPI\\wolstate.c", 188);
		break;
	case 10:
		result = loadString_sub_40F1D0((char*)&byte_587000[58376], 0,
					       "C:\\NoxPost\\src\\common\\WolAPI\\wolstate.c", 180);
		break;
	case 11:
		result = loadString_sub_40F1D0((char*)&byte_587000[58548], 0,
					       "C:\\NoxPost\\src\\common\\WolAPI\\wolstate.c", 192);
		break;
	case 12:
		result = loadString_sub_40F1D0((char*)&byte_587000[58436], 0,
					       "C:\\NoxPost\\src\\common\\WolAPI\\wolstate.c", 184);
		break;
	default:
		result = loadString_sub_40F1D0((char*)&byte_587000[58652], 0,
					       "C:\\NoxPost\\src\\common\\WolAPI\\wolstate.c", 200);
		break;
	}
	if (result)
		result = (wchar_t*)sub_447310(0, (int)result);
	return result;
}

//----- (0041DDB0) --------------------------------------------------------
int sub_41DDB0() {
	int v0;      // esi
	int v1;      // eax
	wchar_t* v2; // eax
	wchar_t* v3; // eax

	if (*(_DWORD*)&byte_587000[58232]) {
		v0 = *(_DWORD*)&byte_587000[58232];
		do {
			v1 = sub_41E2F0();
			switch (sub_41DCC0(v1)) {
			case 5:
				if (*(_DWORD*)&byte_5D4594[2660652]) {
					if (!*(_WORD*)&byte_5D4594[2660140]) {
						switch (*(_DWORD*)&byte_5D4594[2660652] + 2147221403) {
						case 0:
							v2 = loadString_sub_40F1D0(
							    (char*)&byte_587000[58748], 0,
							    "C:\\NoxPost\\src\\common\\WolAPI\\wolstate.c", 414);
							nox_wcscpy((wchar_t*)&byte_5D4594[2660140], v2);
							break;
						case 1:
							v3 = loadString_sub_40F1D0(
							    (char*)&byte_587000[58800], 0,
							    "C:\\NoxPost\\src\\common\\WolAPI\\wolstate.c", 418);
							goto LABEL_14;
						case 155:
							v3 = loadString_sub_40F1D0(
							    (char*)&byte_587000[58848], 0,
							    "C:\\NoxPost\\src\\common\\WolAPI\\wolstate.c", 422);
							goto LABEL_14;
						case 156:
							v3 = loadString_sub_40F1D0(
							    (char*)&byte_587000[58904], 0,
							    "C:\\NoxPost\\src\\common\\WolAPI\\wolstate.c", 426);
							goto LABEL_14;
						default:
							v3 = loadString_sub_40F1D0(
							    (char*)&byte_587000[58956], 0,
							    "C:\\NoxPost\\src\\common\\WolAPI\\wolstate.c", 430);
						LABEL_14:
							nox_swprintf((wchar_t*)&byte_5D4594[2660140], v3);
							break;
						}
					}
					sub_468DF0((wchar_t*)&byte_5D4594[2660140]);
				} else {
					sub_468F30_wol_reg();
				}
				break;
			case 20:
				sub_468E60(0);
				break;
			case 21:
			case 22:
				sub_468E60(1);
				break;
			default:
				break;
			}
			--v0;
		} while (v0);
	}
	sub_40D250();
	return 1;
}
