#include "client__shell__options.h"

#include "GAME2.h"
#include "common__strman.h"

//----- (004AA650) --------------------------------------------------------
void sub_4AA650() {
	char* v2; // ecx
	void* v3; // [esp+0h] [ebp-4h]

	if (!sub_44D930()) {
		v2 = *(char**)getMemAt(0x587000, 172892 + 4 * (*getMemU32Ptr(0x5D4594, 1309744))++);
		nox_strman_loadString_40F1D0(v2, &v3, "C:\\NoxPost\\src\\client\\shell\\Options.c", 131);
		*getMemU32Ptr(0x5D4594, 1309744) %= 3;
		if (v3) {
			/*(void*)*/ nox_xxx_playDialogFile_44D900((int)v3, 100);
		}
	}
}
