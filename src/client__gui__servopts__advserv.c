#include "client__gui__servopts__advserv.h"
#include "proto.h"
extern _DWORD dword_5d4594_1316972;

//----- (004BE2C0) --------------------------------------------------------
int __cdecl sub_4BE2C0(int a1) {
	wchar_t* v1; // eax
	_DWORD* v2;  // eax

	*(_DWORD*)(sub_416640() + 74) = a1;
	v1 =
		nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 180448), 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\advserv.c", 71);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1316716), v1, a1);
	v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2120);
	return nox_window_call_field_94((int)v2, 16385, (int)getMemAt(0x5D4594, 1316716), -1);
}
