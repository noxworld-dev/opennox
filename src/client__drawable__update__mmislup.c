#include "client__drawable__update__mmislup.h"

#include "GAME2.h"
#include "GAME2_3.h"
#include "common__random.h"

extern unsigned int nox_gameFPS;
//----- (004CD9E0) --------------------------------------------------------
int nox_xxx_updDrawMagicMissile_4CD9E0(int a1, uint32_t* a2) {
	uint32_t* v2;  // ebp
	int v3;        // esi
	int v4;        // edi
	int v5;        // ebx
	int v6;        // edi
	int v8;        // ebx
	int v9;        // eax
	int v10;       // esi
	int v11;       // edx
	uint32_t* v12; // esi
	int v14;       // [esp+8h] [ebp-8h]
	int v15;       // [esp+Ch] [ebp-4h]
	int v16;       // [esp+18h] [ebp+8h]

	v2 = a2;
	if (!*getMemU32Ptr(0x5D4594, 1522984)) {
		*getMemU32Ptr(0x5D4594, 1522984) = nox_xxx_getTTByNameSpriteMB_44CFC0("Spark");
		*getMemU32Ptr(0x5D4594, 1522988) = nox_xxx_getTTByNameSpriteMB_44CFC0("Puff");
		*getMemU32Ptr(0x5D4594, 1522992) = nox_xxx_getTTByNameSpriteMB_44CFC0("MagicMissileTailLink");
	}
	v3 = a2[3] - a2[8];
	v15 = a2[4] - a2[9];
	v14 = a2[3] - a2[8];
	v16 = 0;
	if (*getMemU32Ptr(0x587000, 190108) > 0) {
		while (1) {
			v4 = v2[8];
			v5 = v2[9];
			v6 = v3 *
					 nox_common_randomIntMinMax_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c",
													   40) /
					 100 +
				 v4;
			v8 = (v15 * nox_common_randomIntMinMax_415FF0(
							0, 100, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 41)) /
					 100 +
				 v5;
			v9 = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1522984), v6, v8);
			v10 = v9;
			if (v9) {
				*(uint32_t*)(v9 + 432) = v6 << 12;
				*(uint32_t*)(v9 + 436) = v8 << 12;
				*(uint8_t*)(v9 + 299) = nox_common_randomIntMinMax_415FF0(
					0, 255, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 52);
				*(uint32_t*)(v10 + 440) = 0;
				*(uint32_t*)(v10 + 448) =
					gameFrame() + nox_common_randomIntMinMax_415FF0(
												3, 10, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 59);
				*(uint32_t*)(v10 + 444) = gameFrame();
				*(uint16_t*)(v10 + 104) = 20;
				*(uint8_t*)(v10 + 296) = nox_common_randomIntMinMax_415FF0(
					0, 6, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 65);
				nox_xxx_sprite_45A110_drawable((uint32_t*)v10);
			}
			if (++v16 >= *getMemIntPtr(0x587000, 190108)) {
				break;
			}
			v3 = v14;
		}
	}
	v11 = v2[108];
	if ((v2[3] - v11) * (v2[3] - v11) + (v2[4] - v2[109]) * (v2[4] - v2[109]) > 200) {
		v12 = (uint32_t*)nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1522992), v11, v2[109]);
		v12[108] = v2[3];
		v12[109] = v2[4];
		nox_xxx_sprite_45A110_drawable(v12);
		v2[108] = v2[3];
		v2[109] = v2[4];
		nox_xxx_spriteTransparentDecay_49B950(v12, nox_gameFPS / 3u);
	}
	return 1;
}
