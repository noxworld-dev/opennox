#include "client__drawable__update__telwake.h"

#include "GAME2.h"
#include "common__random.h"

extern unsigned int nox_frame_xxx_2598000;
//----- (004CD8D0) --------------------------------------------------------
int nox_xxx_updDrawTeleportWake_4CD8D0(int a1, int a2) {
	int v2; // esi
	int v3; // eax
	int v4; // eax
	int v5; // esi

	if (!*getMemU32Ptr(0x5D4594, 1522980)) {
		*getMemU32Ptr(0x5D4594, 1522980) = nox_xxx_getTTByNameSpriteMB_44CFC0("BlueSpark");
	}
	v2 = *(uint32_t*)(a2 + 12) +
		 nox_common_randomIntMinMax_415FF0(-5, 5, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 32);
	v3 = nox_common_randomIntMinMax_415FF0(-5, 5, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 33);
	v4 = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1522980), v2, *(uint32_t*)(a2 + 16) + v3);
	v5 = v4;
	if (v4) {
		*(uint32_t*)(v4 + 432) = *(uint32_t*)(v4 + 12) << 12;
		*(uint32_t*)(v4 + 436) = *(uint32_t*)(v4 + 16) << 12;
		*(uint8_t*)(v4 + 299) =
			nox_common_randomIntMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 43);
		*(uint32_t*)(v5 + 440) =
			nox_common_randomIntMinMax_415FF0(1, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 46);
		*(uint32_t*)(v5 + 448) =
			nox_frame_xxx_2598000 +
			nox_common_randomIntMinMax_415FF0(10, 32, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 49);
		*(uint32_t*)(v5 + 444) = nox_frame_xxx_2598000;
		*(uint16_t*)(v5 + 104) = 0;
		*(uint8_t*)(v5 + 296) =
			nox_common_randomIntMinMax_415FF0(3, 8, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 55);
		nox_xxx_sprite_45A110_drawable((uint32_t*)v5);
	}
	return 1;
}
