#include "gamewin.h"

#include "../guimsg.h"

#include "../../../proto.h"

//----- (0046B000) --------------------------------------------------------
wchar_t* __cdecl nox_xxx_wndWddSetTooltip_46B000(wchar_t* a1, wchar_t* a2) {
	wchar_t* result; // eax
	wchar_t* v3;     // eax

	if (a2) {
		if (nox_wcslen(a2) < 0x40) {
			result = nox_wcscpy(a1 + 102, a2);
		} else {
			v3 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 143168), 0,
									   "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\gamewin.c", 1004);
			result = nox_wcscpy(a1 + 102, v3);
		}
	} else {
		result = a1;
		a1[102] = 0;
	}
	return result;
}

//----- (0046C140) --------------------------------------------------------
void __cdecl nox_xxx_clientPickup_46C140(int a1) {
	int v2;      // eax
	wchar_t* v3; // eax
	int v4;      // [esp+0h] [ebp-4h]

	if (!*getMemU32Ptr(0x5D4594, 1064928)) {
		*getMemU32Ptr(0x5D4594, 1064928) = nox_xxx_getTTByNameSpriteMB_44CFC0((CHAR*)getMemAt(0x587000, 143192));
		*getMemU32Ptr(0x5D4594, 1064932) = nox_xxx_getTTByNameSpriteMB_44CFC0((CHAR*)getMemAt(0x587000, 143200));
		*getMemU32Ptr(0x5D4594, 1064936) = nox_xxx_getTTByNameSpriteMB_44CFC0((CHAR*)getMemAt(0x587000, 143216));
	}
	if (a1) {
		v2 = *(_DWORD*)(a1 + 108);
		if (v2 == *getMemU32Ptr(0x5D4594, 1064928) || v2 == *getMemU32Ptr(0x5D4594, 1064932) ||
			v2 == *getMemU32Ptr(0x5D4594, 1064936) || sub_467B00(v2, 1)) {
			LOBYTE(v4) = 115;
			*(_WORD*)((char*)&v4 + 1) = nox_xxx_netGetUnitCodeCli_578B00(a1);
			nox_xxx_netAddToMsgListCli_40EBC0(31, 0, &v4, 3);
		} else {
			nox_xxx_clientPlaySoundSpecial_452D80(925, 100);
			v3 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 143276), 0,
									   "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\gamewin.c", 83);
			nox_xxx_printCentered_445490(v3);
		}
	}
}
