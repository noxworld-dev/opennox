#include "client__gui__guifb.h"
#include "common__strman.h"

#include "GAME1_2.h"
#include "client__gui__gamewin__gamewin.h"
extern uint32_t dword_5d4594_1045636;

//----- (00456140) --------------------------------------------------------
void sub_456140(unsigned char a1) {
	int v2;      // esi
	wchar_t* v3; // eax
	wchar_t* v4; // eax
	wchar_t* v5; // eax
	wchar_t* v6; // eax

	*getMemU8Ptr(0x5D4594, 1045644) = a1;
	v2 = dword_5d4594_1045636 + 36;
	switch (a1) {
	case 0:
		*(uint32_t*)(v2 + 24) = nox_xxx_gLoadImg_42F970("BallAtHome");
		v3 = nox_strman_loadString_40F1D0("BallHomeTT", 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 165);
		nox_xxx_wndWddSetTooltip_46B000((wchar_t*)v2, v3);
		break;
	case 1:
		*(uint32_t*)(v2 + 24) = nox_xxx_gLoadImg_42F970("BallAway");
		v4 = nox_strman_loadString_40F1D0("BallAwayTT", 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 170);
		nox_xxx_wndWddSetTooltip_46B000((wchar_t*)v2, v4);
		break;
	case 2:
		*(uint32_t*)(v2 + 24) = nox_xxx_gLoadImg_42F970("BallRed");
		v5 = nox_strman_loadString_40F1D0("BallRedTT", 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 175);
		nox_xxx_wndWddSetTooltip_46B000((wchar_t*)v2, v5);
		break;
	case 4:
		*(uint32_t*)(v2 + 24) = nox_xxx_gLoadImg_42F970("BallBlue");
		v6 = nox_strman_loadString_40F1D0("BallBlueTT", 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 180);
		nox_xxx_wndWddSetTooltip_46B000((wchar_t*)v2, v6);
		break;
	}
}
