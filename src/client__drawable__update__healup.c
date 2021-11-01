#include "client__drawable__update__healup.h"

#include "GAME2.h"
#include "GAME5_2.h"
#include "common__random.h"
#include "operators.h"

//----- (004CD450) --------------------------------------------------------
int sub_4CD450(uint32_t* a1, int a2) {
	int v2;        // esi
	int v3;        // eax
	int v4;        // ecx
	int v5;        // eax
	uint32_t* v6;  // eax
	int v7;        // eax
	uint32_t* v8;  // ebx
	int v9;        // eax
	uint32_t* v10; // eax
	int v11;       // eax
	uint32_t* v12; // edi
	uint32_t* v13; // edi
	int v14;       // ebx
	int v15;       // edx
	int v16;       // ebp
	int v17;       // edx
	int v18;       // ecx
	int v19;       // esi
	char v20;      // al
	int v22;       // [esp+0h] [ebp-8h]
	short v23;     // [esp+4h] [ebp-4h]
	int v24;       // [esp+Ch] [ebp+4h]

	if (!*getMemU32Ptr(0x5D4594, 1522972)) {
		*getMemU32Ptr(0x5D4594, 1522972) = nox_xxx_getTTByNameSpriteMB_44CFC0("HealOrb");
	}
	if (nox_common_randomIntMinMax_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 20) < 50) {
		if (*(uint8_t*)(a2 + 432)) {
			if (a2 == -432) {
				return 1;
			}
			if (nox_xxx_netTestHighBit_578B70(*(uint32_t*)(a2 + 437))) {
				v5 = nox_xxx_netClearHighBit_578B30(*(uint32_t*)(a2 + 437));
				v6 = nox_xxx_netSpriteByCodeStatic_45A720(v5);
			} else {
				v7 = nox_xxx_netClearHighBit_578B30(*(uint32_t*)(a2 + 437));
				v6 = nox_xxx_netSpriteByCodeDynamic_45A6F0(v7);
			}
			v8 = v6;
			if (nox_xxx_netTestHighBit_578B70(*(uint32_t*)(a2 + 441))) {
				v9 = nox_xxx_netClearHighBit_578B30(*(uint32_t*)(a2 + 441));
				v10 = nox_xxx_netSpriteByCodeStatic_45A720(v9);
			} else {
				v11 = nox_xxx_netClearHighBit_578B30(*(uint32_t*)(a2 + 441));
				v10 = nox_xxx_netSpriteByCodeDynamic_45A6F0(v11);
			}
			v12 = v10;
			if (!v8 || !v10) {
				return 1;
			}
			v2 = v10[3] +
				 nox_common_randomIntMinMax_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 61);
			v3 = v12[4] +
				 nox_common_randomIntMinMax_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 62);
			v4 = v8[4];
			v22 = v8[3];
		} else {
			if (a2 == -432) {
				return 1;
			}
			v2 = *(unsigned short*)(a2 + 441) +
				 nox_common_randomIntMinMax_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 31);
			v3 = *(unsigned short*)(a2 + 443) +
				 nox_common_randomIntMinMax_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 32);
			LOWORD(v22) = *(uint16_t*)(a2 + 437);
			LOWORD(v4) = *(uint16_t*)(a2 + 439);
		}
		v13 = a1;
		v23 = v4;
		v14 = *a1;
		v15 = *a1 - a1[4];
		v16 = a1[5];
		v24 = *(short*)(a2 + 104);
		v17 = v2 + v15;
		v18 = v3 + v13[1] - v16 - v24;
		if (v17 < 0) {
			v2 = v13[4] + v14 + 1;
		}
		if (v18 < 0) {
			v3 = v16 - v24 + v13[1] + 1;
		}
		if (v17 >= v13[8]) {
			v2 = v13[2] + v13[4] - 1;
		}
		if (v18 >= v13[9]) {
			v3 = v13[3] - v24 + v16 - 1;
		}
		v19 = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1522972), v2, v3);
		if (v19) {
			v20 = nox_common_randomIntMinMax_415FF0(6, 12, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 92);
			*(uint16_t*)(v19 + 432) = v22;
			*(uint16_t*)(v19 + 434) = v23;
			*(uint8_t*)(v19 + 443) = v20;
			*(uint8_t*)(v19 + 444) =
				nox_common_randomIntMinMax_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 99);
		}
	}
	return 1;
}
