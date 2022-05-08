#include "client__network__netclint.h"

#include "GAME1_3.h"
#include "client__gui__guimsg.h"
#include "client__gui__window.h"
#include "common__strman.h"

//----- (0043D260) --------------------------------------------------------
void sub_43D260(int a1, int a2) {
	wchar_t* v2;     // eax
	wchar_t v3[256]; // [esp+8h] [ebp-200h]

	if (a1) {
		if (a2) {
			v2 = nox_strman_loadString_40F1D0("WolPage", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 784);
			nox_swprintf(v3, v2, a1, a2);
			nox_xxx_printCentered_445490(v3);
		}
	}
}
