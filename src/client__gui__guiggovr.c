#include "client__gui__guiggovr.h"

#include "proto.h"

extern _DWORD dword_5d4594_1303452;
extern int nox_win_width;
extern int nox_win_height;
extern unsigned int nox_gameFPS;

//----- (0049B4B0) --------------------------------------------------------
int __cdecl sub_49B4B0(unsigned __int16* a1) {
	wchar_t* v1; // eax
	wchar_t* v2; // eax
	wchar_t* v3; // eax
	_DWORD* v4;  // eax
	_DWORD* v5;  // eax
	_DWORD* v6;  // eax
	_DWORD* v7;  // eax
	_DWORD* v8;  // eax
	_DWORD* v9;  // eax
	int result;  // eax
	int v11;     // [esp-4h] [ebp-10h]
	int v12;     // [esp-4h] [ebp-10h]
	int v13;     // [esp-4h] [ebp-10h]
	int v14;     // [esp+4h] [ebp-8h]
	int v15;     // [esp+8h] [ebp-4h]

	nox_window_set_hidden(*(int*)&dword_5d4594_1303452, 0);
	nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1303452, 1);
	nox_xxx_clientPlaySoundSpecial_452D80(1007, 100);
	nox_window_get_size(*(int*)&dword_5d4594_1303452, &v15, &v14);
	nox_wnd_nox_xxx_wndDraw_46A9B0(*(_DWORD**)&dword_5d4594_1303452, nox_win_width / 2 - v15 / 2, nox_win_height / 2 - v14 / 2);
	v11 = a1[1];
	v1 = nox_strman_loadString_40F1D0("GGOver.wnd:GeneratorsDestroyed", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c", 178);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1302172), v1, v11);
	v12 = a1[2];
	v2 = nox_strman_loadString_40F1D0("GGOver.wnd:NumSecretsFound", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c", 181);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1301916), v2, v12);
	v13 = a1[3];
	v3 = nox_strman_loadString_40F1D0("GGOver.wnd:Kills", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c", 183);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1302428), v3, v13);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1303196), (const wchar_t*)getMemAt(0x5D4594, 1303460));
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1303452, 10710);
	sub_46AEE0((int)v4, (int)getMemAt(0x5D4594, 1302172));
	v5 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1303452, 10705);
	sub_46AEE0((int)v5, (int)getMemAt(0x5D4594, 1302940));
	v6 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1303452, 10706);
	sub_46AEE0((int)v6, (int)getMemAt(0x5D4594, 1302684));
	v7 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1303452, 10707);
	sub_46AEE0((int)v7, (int)getMemAt(0x5D4594, 1301916));
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1303452, 10708);
	sub_46AEE0((int)v8, (int)getMemAt(0x5D4594, 1302428));
	v9 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1303452, 10711);
	sub_46AEE0((int)v9, (int)getMemAt(0x5D4594, 1303196));
	result = *getMemU32Ptr(0x5D4594, 2598000);
	*getMemU32Ptr(0x5D4594, 1303456) = *getMemU32Ptr(0x5D4594, 2598000);
	return result;
}

//----- (0049B6E0) --------------------------------------------------------
int sub_49B6E0() {
	int result;  // eax
	int v1;      // eax
	wchar_t* v2; // eax
	_DWORD* v3;  // eax
	int v4;      // [esp-4h] [ebp-4h]

	result = dword_5d4594_1303452;
	if (dword_5d4594_1303452) {
		result = wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1303452);
		if (!result) {
			v1 = *getMemU32Ptr(0x5D4594, 1303456) + 30 * nox_gameFPS -
				 *getMemU32Ptr(0x5D4594, 2598000);
			if (v1 < 0)
				v1 = 0;
			if (*getMemU32Ptr(0x5D4594, 2618908) && *(_BYTE*)(*getMemU32Ptr(0x5D4594, 2618908) + 2064) == 31) {
				nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1301852), (const wchar_t*)getMemAt(0x5D4594, 1303464));
			} else {
				v4 = (unsigned int)v1 / nox_gameFPS;
				v2 = nox_strman_loadString_40F1D0("Rules.c:Time", 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c",
										   265);
				nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1301852), L"%s - %d", v2, v4);
			}
			v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1303452, 10712);
			result = sub_46AEE0((int)v3, (int)getMemAt(0x5D4594, 1301852));
		}
	}
	return result;
}
