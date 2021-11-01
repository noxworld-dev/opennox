#include "client__draw__boulderdraw.h"
#include "GAME3_1.h"

//----- (004B9B50) --------------------------------------------------------
int nox_thing_boulder_draw(int* a1, nox_drawable* dr) {
	int v2;          // edi
	int v3;          // ecx
	int v4;          // edx
	unsigned int v5; // ecx
	int v6;          // ecx

	int a2 = dr;

	v2 = *(uint32_t*)(a2 + 304);
	if (!*(uint32_t*)(a2 + 432) && !*(uint32_t*)(a2 + 436)) {
		*(uint32_t*)(a2 + 432) = *(uint32_t*)(a2 + 12);
		*(uint32_t*)(a2 + 436) = *(uint32_t*)(a2 + 16);
	}
	v3 = *(uint32_t*)(a2 + 12) - *(uint32_t*)(a2 + 432);
	v4 = *(uint32_t*)(a2 + 16) - *(uint32_t*)(a2 + 436);
	if (v3 * v3 + v4 * v4 >= 100) {
		if (v3 <= 0) {
			if (v4 > 0) {
				*(uint32_t*)(a2 + 444) = 0;
			LABEL_8:
				v5 = *(uint32_t*)(a2 + 440) + 1;
				*(uint32_t*)(a2 + 440) = v5;
				if (v5 >= 0x10) {
					*(uint32_t*)(a2 + 440) = 0;
				}
				goto LABEL_17;
			}
			*(uint32_t*)(a2 + 444) = 16;
		} else {
			if (v4 > 0) {
				*(uint32_t*)(a2 + 444) = 16;
				goto LABEL_8;
			}
			*(uint32_t*)(a2 + 444) = 0;
		}
		v6 = *(uint32_t*)(a2 + 440);
		if (v6) {
			*(uint32_t*)(a2 + 440) = v6 - 1;
		} else {
			*(uint32_t*)(a2 + 440) = 15;
		}
	LABEL_17:
		*(uint32_t*)(a2 + 432) = *(uint32_t*)(a2 + 12);
		*(uint32_t*)(a2 + 436) = *(uint32_t*)(a2 + 16);
	}
	nox_xxx_drawObject_4C4770_draw(
		a1, dr, *(uint32_t*)(*(uint32_t*)(v2 + 4) + 4 * (*(uint32_t*)(a2 + 440) + *(uint32_t*)(a2 + 444))));
	return 1;
}
