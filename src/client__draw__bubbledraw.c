#include "client__draw__bubbledraw.h"
#include "proto.h"

extern unsigned int nox_gameFPS;
//----- (004B7540) --------------------------------------------------------
int  nox_thing_bubble_draw(_DWORD* a1, nox_drawable* dr) {
	unsigned int v2;    // eax
	int v4;             // edx
	int v5;             // eax
	char v6;            // al
	char v7;            // al
	char v8;            // al
	unsigned __int8 v9; // al
	char v10;           // al
	char v11;           // al
	char v12;           // dl
	bool v13;           // zf
	char v14;           // al
	char v15;           // al
	char v16;           // al
	int2 xLeft;         // [esp+8h] [ebp-8h]

	int a2 = dr;

	if (*(_BYTE*)(a2 + 441) == 3)
		goto LABEL_29;
	v2 = *(_DWORD*)(a2 + 356);
	if (v2 && v2 <= *getMemIntPtr(0x5D4594, 2598000)) {
		*(_BYTE*)(a2 + 441) = 3;
		*(_BYTE*)(a2 + 442) = 4;
		*(_BYTE*)(a2 + 443) = 4;
		nox_xxx_spriteTransparentDecay_49B950((_DWORD*)a2, (int)nox_gameFPS);
	}
	if (*(_BYTE*)(a2 + 441) == 3) {
		LABEL_29:
		if (!*(_BYTE*)(a2 + 440)) {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
			return 0;
		}
	}
	v4 = a1[1];
	xLeft.field_0 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
	v5 = *(unsigned __int8*)(a2 + 440);
	xLeft.field_4 = *(_DWORD*)(a2 + 16) + v4 - a1[5] - *(__int16*)(a2 + 104);
	sub_4B6720(&xLeft, *(_DWORD*)(a2 + 432), v5, v5 + 3);
	nox_client_drawSetColor_434460(*(_DWORD*)(a2 + 436));
	nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, *(unsigned __int8*)(a2 + 440) >> 1);
	if (getMemByte(0x5D4594, 2598000) & 3)
		*(_WORD*)(a2 + 104) += *(char*)(a2 + 446);
	v6 = *(_BYTE*)(a2 + 442);
	if (v6) {
		v7 = v6 - 1;
		*(_BYTE*)(a2 + 442) = v7;
		if (!v7) {
			v8 = *(_BYTE*)(a2 + 441);
			if (v8 == 1) {
				v9 = *(_BYTE*)(a2 + 440) + 1;
				*(_BYTE*)(a2 + 440) = v9;
				if (v9 >= 5u)
					*(_BYTE*)(a2 + 441) = 2;
			} else {
				v13 = v8 == 2;
				v14 = *(_BYTE*)(a2 + 440);
				if (v13) {
					v15 = v14 - 1;
					*(_BYTE*)(a2 + 440) = v15;
					if (!v15)
						*(_BYTE*)(a2 + 441) = 1;
				} else {
					v16 = v14 - 1;
					*(_BYTE*)(a2 + 440) = v16;
					if (!v16) {
						nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
						return 0;
					}
				}
			}
			*(_BYTE*)(a2 + 442) = *(_BYTE*)(a2 + 443);
		}
	}
	v10 = *(_BYTE*)(a2 + 445);
	if (v10) {
		v11 = v10 - 1;
		*(_BYTE*)(a2 + 445) = v11;
		if (!v11) {
			v12 = *(_BYTE*)(a2 + 444);
			*(_BYTE*)(a2 + 446) = -*(_BYTE*)(a2 + 446);
			*(_BYTE*)(a2 + 445) = v12;
		}
	}
	if ((short)*(_WORD*)(a2 + 104) >= 0)
		return 1;
	nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
	return 0;
}
