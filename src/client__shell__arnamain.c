#include "client__shell__arnamain.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME3.h"
#include "GAME3_2.h"
#include "client__gui__window.h"
#include "client__shell__noxworld.h"
#include "client__shell__wolapi__wollogin.h"
#include "common__strman.h"
extern uint32_t dword_5d4594_1309708;
extern uint32_t nox_win_onlineOrLAN_1309716;

//----- (004AA4D0) --------------------------------------------------------
int nox_xxx_windowArenaSub_4AA4D0(int a1, unsigned int a2, int* a3, int a4) {
	if (a2 == 16389) {
		nox_xxx_clientPlaySoundSpecial_452D80(920, 100);
		return 1;
	}
	if (a2 != 16391) {
		return 0;
	}
	if (*(uint8_t*)(dword_5d4594_1309708 + 64) && !nox_common_gameFlags_check_40A5C0(0x2000000) && !sub_4D6F30()) {
		nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
		return 1;
	}
	int sid = nox_xxx_wndGetID_46B0A0(a3);
	if (sid != 411) {
		if (sid != 421) {
			nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
			return 1;
		}
		// LAN selected
		sub_4AA450();
		*(uint32_t*)(dword_5d4594_1309708 + 52) = nox_game_showGameSel_4379F0;
		sub_43AF50(0);
		nox_common_gameFlags_unset_40A540(0x1000000);
		nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
		return 1;
	}
	// WOL selected
	if (!sub_41D440()) {
		wchar_t* v7 =
			nox_strman_loadString_40F1D0("WOLAPIINIT_Failed", 0, "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 100);
		wchar_t* v5 = nox_strman_loadString_40F1D0("Error", 0, "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 100);
		nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&nox_win_onlineOrLAN_1309716, (int)v5, (int)v7, 33, 0, 0);
		return 0;
	}
	if (sub_40D5B0((int)&a2) && a2 < 0x10009) {
		sub_41D4C0();
		wchar_t* v8 =
			nox_strman_loadString_40F1D0("Wol.c:RegistryHosed", 0, "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 111);
		wchar_t* v6 = nox_strman_loadString_40F1D0("Error", 0, "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 111);
		nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&nox_win_onlineOrLAN_1309716, (int)v6, (int)v8, 33, 0, 0);
		return 0;
	}
	sub_4A1A40(0);
	sub_4AA450();
	*(uint32_t*)(dword_5d4594_1309708 + 52) = nox_game_showWolLogin_44A560;
	nox_common_gameFlags_unset_40A540(0x1000000);
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
	return 1;
}
