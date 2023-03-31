#include "client__gui__window.h"
#include "common__strman.h"

#include "GAME1_2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "client__gui__gamewin__gamewin.h"

extern uint32_t dword_5d4594_1193712;
extern int nox_win_width;
extern int nox_win_height;

//----- (0048C9F0) --------------------------------------------------------
int sub_48C9F0(int* a1) {
	int* v1;     // esi
	wchar2_t* v2; // eax
	int v4;      // [esp+4h] [ebp-4h]

	v1 = a1;
	nox_client_wndGetPosition_46AA60(a1, &v4, &a1);
	v4 += v1[24];
	a1 = (int*)((char*)a1 + v1[25]);
	if (*getMemU32Ptr(0x8531A0, 2576)) {
		v2 = nox_strman_loadString_40F1D0("observermode", 0, "C:\\NoxPost\\src\\client\\Gui\\guiobs.c", 41);
		nox_xxx_wndWddSetTooltip_46B000((wchar2_t*)(dword_5d4594_1193712 + 36), v2);
		nox_client_drawImageAt_47D2C0(v1[15], v4, (int)a1);
	}
	return 1;
}

//----- (0048C980) --------------------------------------------------------
int sub_48C980() {
	*getMemU32Ptr(0x5D4594, 1193716) = nox_xxx_gLoadImg_42F970("ObserverIcon");
	dword_5d4594_1193712 = nox_window_new(0, 136, nox_win_width - 50, nox_win_height / 2 - 100, 50, 50, 0);
	nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1193712, *getMemIntPtr(0x5D4594, 1193716));
	nox_window_set_all_funcs(*(uint32_t**)&dword_5d4594_1193712, 0, sub_48C9F0, 0);
	return 1;
}
