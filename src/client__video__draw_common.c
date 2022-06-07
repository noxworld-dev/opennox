#define IGNORE_EXTERNS
#include "client__video__draw_common.h"
#undef IGNORE_EXTERNS
#include "GAME1_2.h"

//----- (004347F0) --------------------------------------------------------
int sub_4347F0(char* a1, int a2) {
	if (a2 <= 256) {
		sub_435120(getMemAt(0x973F18, 3880), a1);
		sub_435040();
	}
	return nox_xxx_makeFillerColor_48BDE0();
}

//----- (004B0300) --------------------------------------------------------
int sub_4B0300(char* a1) {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 1311928);
	if (*getMemIntPtr(0x5D4594, 1311928) < 2) {
		strncpy((char*)getMemAt(0x5D4594, 1311940 + 260 * *getMemU32Ptr(0x5D4594, 1311928)), a1, 0x104u);
		result = ++*getMemU32Ptr(0x5D4594, 1311928);
	}
	return result;
}
