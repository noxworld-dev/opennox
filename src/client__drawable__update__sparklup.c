#include "client__drawable__update__sparklup.h"

#include "common__random.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "client__draw__glowdraw.h"

extern unsigned int nox_frame_xxx_2598000;
//----- (004CDBF0) --------------------------------------------------------
int  nox_xxx_updDrawSparkleTrail_4CDBF0(int a1, uint32_t* a2) {
	uint32_t* v2; // ebx
	int v3;     // edi
	int v4;     // ebp
	int v5;     // esi
	bool v6;    // zf
	int v8;     // [esp+10h] [ebp-10h]
	int v9;     // [esp+14h] [ebp-Ch]
	int v10;    // [esp+18h] [ebp-8h]
	int v11;    // [esp+1Ch] [ebp-4h]
	int v12;    // [esp+28h] [ebp+8h]

	v2 = a2;
	v10 = a2[3] - a2[8];
	v11 = a2[4] - a2[9];
	if (!*getMemU32Ptr(0x5D4594, 1522996)) {
		*getMemU32Ptr(0x5D4594, 1522996) = nox_xxx_getTTByNameSpriteMB_44CFC0("BlueSpark");
}
	v8 = 0;
	v12 = 0;
	v9 = 5;
	do {
		v3 = v2[8] + v12 / 5 + nox_common_randomIntMinMax_415FF0(-3, 3, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c", 28);
		v4 = v2[9] + nox_common_randomIntMinMax_415FF0(-3, 3, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c", 29) + v8 / 5;
		v5 = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1522996), v3, v4);
		if (v5) {
			*(uint32_t*)(v5 + 300) = nox_thing_pixie_dust_draw;
			nox_xxx_spriteChangeLightColor_484BE0((uint32_t*)(v5 + 136), 255, 200, 75);
			*(uint32_t*)(v5 + 432) = v3 << 12;
			*(uint32_t*)(v5 + 436) = v4 << 12;
			*(uint8_t*)(v5 + 299) = 0;
			*(uint32_t*)(v5 + 440) = 0;
			*(uint32_t*)(v5 + 448) = nox_frame_xxx_2598000 +
								   nox_common_randomIntMinMax_415FF0(2, 10, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c", 51);
			*(uint32_t*)(v5 + 444) = nox_frame_xxx_2598000;
			*(uint16_t*)(v5 + 104) = *((uint16_t*)v2 + 52);
			*(uint16_t*)(v5 + 106) = *((uint16_t*)v2 + 53);
			*(uint8_t*)(v5 + 296) = 0;
			nox_xxx_sprite_45A110_drawable((uint32_t*)v5);
		}
		v12 += v10;
		v6 = v9 == 1;
		v8 += v11;
		--v9;
	} while (!v6);
	return 1;
}
