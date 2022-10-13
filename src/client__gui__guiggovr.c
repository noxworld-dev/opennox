#include "client__gui__guiggovr.h"
#include "client__gui__window.h"
#include "common__strman.h"

#include "GAME2.h"
#include "GAME2_1.h"

extern uint32_t dword_5d4594_1303452;
extern int nox_win_width;
extern int nox_win_height;

//----- (0049B4B0) --------------------------------------------------------
int sub_49B4B0(unsigned short* a1) {
	wchar_t* v1;  // eax
	wchar_t* v2;  // eax
	wchar_t* v3;  // eax
	uint32_t* v4; // eax
	uint32_t* v5; // eax
	uint32_t* v6; // eax
	uint32_t* v7; // eax
	uint32_t* v8; // eax
	uint32_t* v9; // eax
	int result;   // eax
	int v11;      // [esp-4h] [ebp-10h]
	int v12;      // [esp-4h] [ebp-10h]
	int v13;      // [esp-4h] [ebp-10h]
	int v14;      // [esp+4h] [ebp-8h]
	int v15;      // [esp+8h] [ebp-4h]

	nox_window_set_hidden(*(int*)&dword_5d4594_1303452, 0);
	nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1303452, 1);
	nox_xxx_clientPlaySoundSpecial_452D80(1007, 100);
	nox_window_get_size(*(int*)&dword_5d4594_1303452, &v15, &v14);
	nox_window_setPos_46A9B0(*(uint32_t**)&dword_5d4594_1303452, nox_win_width / 2 - v15 / 2,
							 nox_win_height / 2 - v14 / 2);
	v11 = a1[1];
	v1 = nox_strman_loadString_40F1D0("GGOver.wnd:GeneratorsDestroyed", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c",
									  178);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1302172), v1, v11);
	v12 = a1[2];
	v2 =
		nox_strman_loadString_40F1D0("GGOver.wnd:NumSecretsFound", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c", 181);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1301916), v2, v12);
	v13 = a1[3];
	v3 = nox_strman_loadString_40F1D0("GGOver.wnd:Kills", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c", 183);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1302428), v3, v13);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1303196), (const wchar_t*)getMemAt(0x5D4594, 1303460));
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1303452, 10710);
	sub_46AEE0((int)v4, (int)getMemAt(0x5D4594, 1302172));
	v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1303452, 10705);
	sub_46AEE0((int)v5, (int)getMemAt(0x5D4594, 1302940));
	v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1303452, 10706);
	sub_46AEE0((int)v6, (int)getMemAt(0x5D4594, 1302684));
	v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1303452, 10707);
	sub_46AEE0((int)v7, (int)getMemAt(0x5D4594, 1301916));
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1303452, 10708);
	sub_46AEE0((int)v8, (int)getMemAt(0x5D4594, 1302428));
	v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1303452, 10711);
	sub_46AEE0((int)v9, (int)getMemAt(0x5D4594, 1303196));
	result = gameFrame();
	*getMemU32Ptr(0x5D4594, 1303456) = gameFrame();
	return result;
}

//----- (0049B6E0) --------------------------------------------------------
int sub_49B6E0() {
	int result;   // eax
	int v1;       // eax
	wchar_t* v2;  // eax
	uint32_t* v3; // eax
	int v4;       // [esp-4h] [ebp-4h]

	result = dword_5d4594_1303452;
	if (dword_5d4594_1303452) {
		result = wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1303452);
		if (!result) {
			v1 = *getMemU32Ptr(0x5D4594, 1303456) + 30 * gameFPS() - gameFrame();
			if (v1 < 0) {
				v1 = 0;
			}
			if (*getMemU32Ptr(0x8531A0, 2576) && *(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 2064) == 31) {
				nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1301852), (const wchar_t*)getMemAt(0x5D4594, 1303464));
			} else {
				v4 = (unsigned int)v1 / gameFPS();
				v2 = nox_strman_loadString_40F1D0("Rules.c:Time", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c", 265);
				nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1301852), L"%s - %d", v2, v4);
			}
			v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1303452, 10712);
			result = sub_46AEE0((int)v3, (int)getMemAt(0x5D4594, 1301852));
		}
	}
	return result;
}
