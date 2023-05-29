#include "client__draw__bubbledraw.h"
#include "GAME1_2.h"
#include "GAME2.h"
#include "GAME2_3.h"
#include "GAME3.h"

//----- (004B7540) --------------------------------------------------------
int nox_thing_bubble_draw(uint32_t* a1, nox_drawable* dr) {
	unsigned int v2;  // eax
	int v4;           // edx
	int v5;           // eax
	char v6;          // al
	char v7;          // al
	char v8;          // al
	unsigned char v9; // al
	char v10;         // al
	char v11;         // al
	char v12;         // dl
	bool v13;         // zf
	char v14;         // al
	char v15;         // al
	char v16;         // al
	int2 xLeft;       // [esp+8h] [ebp-8h]

	int a2 = dr;

	if (*(uint8_t*)(a2 + 441) == 3) {
		if (!*(uint8_t*)(a2 + 440)) {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
			return 0;
		}
	} else {
		v2 = *(uint32_t*)(a2 + 356);
		if (v2 && v2 <= gameFrame()) {
			*(uint8_t*)(a2 + 441) = 3;
			*(uint8_t*)(a2 + 442) = 4;
			*(uint8_t*)(a2 + 443) = 4;
			nox_xxx_spriteTransparentDecay_49B950((uint32_t*)a2, (int)gameFPS());
		}
		if (*(uint8_t*)(a2 + 441) == 3) {
			if (!*(uint8_t*)(a2 + 440)) {
				nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
				return 0;
			}
		}
	}
	v4 = a1[1];
	xLeft.field_0 = *a1 + *(uint32_t*)(a2 + 12) - a1[4];
	v5 = *(unsigned char*)(a2 + 440);
	xLeft.field_4 = *(uint32_t*)(a2 + 16) + v4 - a1[5] - *(short*)(a2 + 104);
	sub_4B6720(&xLeft, *(uint32_t*)(a2 + 432), v5, v5 + 3);
	nox_client_drawSetColor_434460(*(uint32_t*)(a2 + 436));
	nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, *(unsigned char*)(a2 + 440) >> 1);
	if ((unsigned char)gameFrame() & 3) {
		*(uint16_t*)(a2 + 104) += *(char*)(a2 + 446);
	}
	v6 = *(uint8_t*)(a2 + 442);
	if (v6) {
		v7 = v6 - 1;
		*(uint8_t*)(a2 + 442) = v7;
		if (!v7) {
			v8 = *(uint8_t*)(a2 + 441);
			if (v8 == 1) {
				v9 = *(uint8_t*)(a2 + 440) + 1;
				*(uint8_t*)(a2 + 440) = v9;
				if (v9 >= 5u) {
					*(uint8_t*)(a2 + 441) = 2;
				}
			} else {
				v13 = v8 == 2;
				v14 = *(uint8_t*)(a2 + 440);
				if (v13) {
					v15 = v14 - 1;
					*(uint8_t*)(a2 + 440) = v15;
					if (!v15) {
						*(uint8_t*)(a2 + 441) = 1;
					}
				} else {
					v16 = v14 - 1;
					*(uint8_t*)(a2 + 440) = v16;
					if (!v16) {
						nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
						return 0;
					}
				}
			}
			*(uint8_t*)(a2 + 442) = *(uint8_t*)(a2 + 443);
		}
	}
	v10 = *(uint8_t*)(a2 + 445);
	if (v10) {
		v11 = v10 - 1;
		*(uint8_t*)(a2 + 445) = v11;
		if (!v11) {
			v12 = *(uint8_t*)(a2 + 444);
			*(uint8_t*)(a2 + 446) = -*(uint8_t*)(a2 + 446);
			*(uint8_t*)(a2 + 445) = v12;
		}
	}
	if ((short)*(uint16_t*)(a2 + 104) >= 0) {
		return 1;
	}
	nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
	return 0;
}
