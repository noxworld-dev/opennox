#include "gamewin.h"

#include "../guimsg.h"

#include "../../../proto.h"

//----- (0046B000) --------------------------------------------------------
wchar_t* __cdecl sub_46B000(wchar_t* a1, wchar_t* a2) {
	wchar_t* result; // eax
	wchar_t* v3;     // eax

	if (a2) {
		if (nox_wcslen(a2) < 0x40) {
			result = nox_wcscpy(a1 + 102, a2);
		} else {
			v3 = loadString_sub_40F1D0((char*)&byte_587000[143168], 0,
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
void __cdecl sub_46C140(int a1) {
	int v2;      // eax
	wchar_t* v3; // eax
	int v4;      // [esp+0h] [ebp-4h]

	if (!*(_DWORD*)&byte_5D4594[1064928]) {
		*(_DWORD*)&byte_5D4594[1064928] = sub_44CFC0((CHAR*)&byte_587000[143192]);
		*(_DWORD*)&byte_5D4594[1064932] = sub_44CFC0((CHAR*)&byte_587000[143200]);
		*(_DWORD*)&byte_5D4594[1064936] = sub_44CFC0((CHAR*)&byte_587000[143216]);
	}
	if (a1) {
		v2 = *(_DWORD*)(a1 + 108);
		if (v2 == *(_DWORD*)&byte_5D4594[1064928] || v2 == *(_DWORD*)&byte_5D4594[1064932] ||
			v2 == *(_DWORD*)&byte_5D4594[1064936] || sub_467B00(v2, 1)) {
			LOBYTE(v4) = 115;
			*(_WORD*)((char*)&v4 + 1) = sub_578B00(a1);
			sub_40EBC0(31, 0, &v4, 3);
		} else {
			sub_452D80(925, 100);
			v3 = loadString_sub_40F1D0((char*)&byte_587000[143276], 0,
									   "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\gamewin.c", 83);
			sub_445490(v3);
		}
	}
}
