#include "guimsg.h"
#include "../../proto.h"
extern _DWORD dword_5d4594_825736;

extern unsigned int nox_gameFPS;
//----- (00445490) --------------------------------------------------------
void __cdecl nox_xxx_printCentered_445490(wchar_t* a1) {
	int v1;             // eax
	int v2;             // eax
	unsigned short* v3; // eax

	if (a1) {
		v1 = ++*(unsigned int*)&dword_5d4594_825736;
		if (*(unsigned int*)&dword_5d4594_825736 == 3) {
			v1 = 0;
			*(unsigned int*)&dword_5d4594_825736 = 0;
		}
		nox_wcscpy(getMemU16Ptr(0x5D4594, 644 * v1 + 823804), a1);
		v2 = 644 * *(unsigned int*)&dword_5d4594_825736;
		*getMemUintPtr(0x5D4594, v2 + 824440) = *getMemUintPtr(0x5D4594, 2598000) +
													4 * nox_gameFPS +
													nox_gameFPS;
		*getMemU8Ptr( 0x5D4594, v2 + 824444) = 0;
		v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107916), 0, "C:\\NoxPost\\src\\Client\\Gui\\guimsg.c", 69);
		nox_xxx_consoleVPrint_450C00(6u, v3, a1);
	}
}
