#include "client__gui__woldisc.h"

#include "proto.h"
#include "client__gui__guimsg.h"
#include "common__log.h"

extern _DWORD dword_5d4594_830292;
extern int nox_win_width;
extern int nox_win_height;

//----- (0044B010) --------------------------------------------------------
void sub_44B010() {
	wchar_t* v0; // eax
	wchar_t* v1; // eax

	nox_game_checkStateWol_43C260();
	sub_41E300(9);
	sub_44E040();
	if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
		v0 = nox_strman_loadString_40F1D0("LostConnection", 0, "C:\\NoxPost\\src\\client\\Gui\\woldisc.c", 75);
		nox_xxx_networkLog_printf_413D30("%S", v0);
		if (sub_43C710())
			nox_xxx_reconStart_41E400();
		else
			nox_xxx_quit_4460C0();
	} else if (nox_common_gameFlags_check_40A5C0(1)) {
		dword_5d4594_830292 = nox_new_window_from_file("woldisc.wnd", sub_44B0F0);
		nox_wnd_nox_xxx_wndDraw_46A9B0(*(_DWORD**)&dword_5d4594_830292, nox_win_width / 2 - *(int*)(dword_5d4594_830292 + 24) / 2,
						   nox_win_height / 2 - *(int*)(dword_5d4594_830292 + 28) / 2);
	} else {
		v1 = nox_strman_loadString_40F1D0("LostConnection", 0, "C:\\NoxPost\\src\\client\\Gui\\woldisc.c", 100);
		nox_xxx_printCentered_445490(v1);
	}
}
