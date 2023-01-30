#include "client__network__deathmsg.h"
#include "client__gui__guicon.h"
#include "common__strman.h"

#include "GAME1.h"

//----- (004952E0) --------------------------------------------------------
int sub_4952E0(uint16_t* a1) {
	char* v1;        // eax
	wchar_t* v2;     // eax
	char* v3;        // eax
	wchar_t* v4;     // eax
	char* v5;        // eax
	wchar_t* v6;     // eax
	int v8;          // [esp-4h] [ebp-108h]
	wchar_t* v9;     // [esp-4h] [ebp-108h]
	int v10;         // [esp+0h] [ebp-104h]
	wchar_t v11[32]; // [esp+4h] [ebp-100h]
	wchar_t v12[32]; // [esp+44h] [ebp-C0h]
	wchar_t v13[64]; // [esp+84h] [ebp-80h]

	if (a1[1] && (v1 = nox_common_playerInfoGetByID_417040((unsigned short)a1[1])) != 0) {
		v8 = (int)(v1 + 4704);
		v2 = nox_strman_loadString_40F1D0("die.c:LocalizeAttacker", 0, "C:\\NoxPost\\src\\client\\Network\\deathmsg.c",
										  48);
		nox_swprintf(v13, v2, v8);
		if (a1[2]) {
			v3 = nox_common_playerInfoGetByID_417040((unsigned short)a1[2]);
			if (v3) {
				nox_swprintf(v12, L" + %s", v3 + 4704);
				nox_wcscat(v13, v12);
			}
		}
	} else {
		v9 =
			nox_strman_loadString_40F1D0("die.c:AttackerNasty", 0, "C:\\NoxPost\\src\\client\\Network\\deathmsg.c", 65);
		v4 = nox_strman_loadString_40F1D0("die.c:LocalizeAttacker", 0, "C:\\NoxPost\\src\\client\\Network\\deathmsg.c",
										  64);
		nox_swprintf(v13, v4, v9);
	}
	if (a1[3]) {
		v5 = nox_common_playerInfoGetByID_417040((unsigned short)a1[3]);
		if (v5) {
			v10 = (int)(v5 + 4704);
			v6 = nox_strman_loadString_40F1D0("die.c:LocalizeVictim", 0,
											  "C:\\NoxPost\\src\\client\\Network\\deathmsg.c", 72);
			nox_swprintf(v11, v6, v10);
		}
	}
	return nox_gui_console_Printf_450C00(NOX_CONSOLE_WHITE, (wchar_t*)getMemAt(0x587000, 161668), v11, v13);
}
