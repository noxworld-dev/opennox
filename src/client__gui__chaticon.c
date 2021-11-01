#include "client__gui__chaticon.h"
#include "client__gui__window.h"

#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2_1.h"
#include "client__gui__gamewin__gamewin.h"
#include "common__strman.h"

extern uint32_t dword_5d4594_825744;
extern int nox_win_width;
extern int nox_win_height;

//----- (00445650) --------------------------------------------------------
int nox_xxx_guiChatIconLoad_445650() {
	unsigned short* v0; // eax

	*getMemUintPtr(0x5D4594, 825748) = nox_xxx_gLoadImg_42F970("ChatIcon");
	*(unsigned int*)&dword_5d4594_825744 =
		nox_window_new(0, 136, nox_win_width - 50, nox_win_height / 2 - 50, 50, 50, 0);
	nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_825744, *getMemIntPtr(0x5D4594, 825748));
	nox_window_set_all_funcs(*(unsigned int**)&dword_5d4594_825744, 0, nox_xxx_guiChatMode_4456E0, 0);
	v0 = nox_strman_loadString_40F1D0("chatmode", 0, "C:\\NoxPost\\src\\client\\Gui\\chaticon.c", 73);
	nox_xxx_wndWddSetTooltip_46B000((unsigned short*)(*(unsigned int*)&dword_5d4594_825744 + 36), v0);
	return 1;
}
