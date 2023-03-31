#include "memmap.h"
#include "defs.h"
#include "client__gui__window.h"
#include "common__strman.h"

void nullsub_22() {}
void nullsub_36() {}
void nullsub_38() {}
void nullsub_39() {}
void nullsub_40() {}
void nullsub_41() {}
void nullsub_42() {}
void nullsub_43() {}
void nullsub_44() {}

//----- (00413480) --------------------------------------------------------
wchar2_t* sub_413480(char a1) {
	int v1;            // ecx
	unsigned char* v2; // eax

	v1 = 0;
	v2 = getMemAt(0x587000, 27332);
	while (a1 != *v2) {
		v2 += 20;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 27452)) {
			return 0;
		}
	}
	return nox_strman_loadString_40F1D0(*(char**)getMemAt(0x587000, 27344 + 20 * v1), 0,
										"C:\\NoxPost\\src\\common\\Object\\Modifier.c", 2087);
}
