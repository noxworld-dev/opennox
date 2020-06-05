#include "guimsg.h"
#include "../../proto.h"
extern _DWORD dword_5d4594_825736;

//----- (00445490) --------------------------------------------------------
void __cdecl sub_445490(wchar_t* a1) {
	int v1;             // eax
	int v2;             // eax
	unsigned short* v3; // eax

	if (a1) {
		v1 = ++*(unsigned int*)&dword_5d4594_825736;
		if (*(unsigned int*)&dword_5d4594_825736 == 3) {
			v1 = 0;
			*(unsigned int*)&dword_5d4594_825736 = 0;
		}
		nox_wcscpy((unsigned short*)&byte_5D4594[644 * v1 + 823804], a1);
		v2 = 644 * *(unsigned int*)&dword_5d4594_825736;
		*(unsigned int*)&byte_5D4594[v2 + 824440] = *(unsigned int*)&byte_5D4594[2598000] +
							    4 * *(unsigned int*)&byte_5D4594[2649704] +
							    *(unsigned int*)&byte_5D4594[2649704];
		byte_5D4594[v2 + 824444] = 0;
		v3 = loadString_sub_40F1D0((char*)&byte_587000[107916], 0, "C:\\NoxPost\\src\\Client\\Gui\\guimsg.c",
					   69);
		sub_450C00(6u, v3, a1);
	}
}
