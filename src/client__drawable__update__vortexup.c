#include "client__drawable__update__vortexup.h"

#include "GAME2.h"
#include "GAME2_3.h"
#include "client__video__draw_common.h"
#include "common__random.h"

//----- (004CC950) --------------------------------------------------------
int nox_xxx_updDrawVortexSource_4CC950(int a1, int a2) {
	int v2;  // ebp
	int v3;  // esi
	int v4;  // eax
	char v5; // bl
	int v6;  // eax
	int v7;  // esi
	int v9;  // [esp+0h] [ebp-4h]

	if (!*getMemU32Ptr(0x5D4594, 1522952)) {
		*getMemU32Ptr(0x5D4594, 1522952) = nox_xxx_getTTByNameSpriteMB_44CFC0("WhiteVortexOrb");
		*getMemU32Ptr(0x5D4594, 1522944) = nox_color_rgb_4344A0(200, 200, 200);
		*getMemU32Ptr(0x5D4594, 1522948) = nox_color_rgb_4344A0(255, 255, 255);
	}
	v2 = *getMemU32Ptr(0x5D4594, 1522944);
	v3 = *getMemU32Ptr(0x5D4594, 1522952);
	v9 = *getMemU32Ptr(0x5D4594, 1522948);
	v4 = nox_common_randomIntMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c", 54);
	v5 = v4;
	v6 = nox_xxx_spriteLoadAdd_45A360_drawable(
		v3, *(uint32_t*)(a2 + 12) + 50 * *getMemIntPtr(0x587000, 192088 + 8 * v4) / 16,
		*(uint32_t*)(a2 + 16) + 50 * *getMemIntPtr(0x587000, 192092 + 8 * v4) / 16);
	v7 = v6;
	if (v6) {
		*(uint8_t*)(v6 + 448) = v5;
		*(uint16_t*)(a2 + 104) = 0;
		*(uint8_t*)(v6 + 449) =
			nox_common_randomIntMinMax_415FF0(2, 3, "C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c", 74);
		if (nox_common_randomIntMinMax_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c", 75) >
			50) {
			*(uint8_t*)(v7 + 449) = -*(uint8_t*)(v7 + 449);
		}
		*(uint8_t*)(v7 + 451) = 1;
		*(uint8_t*)(v7 + 450) = 50;
		*(uint32_t*)(v7 + 440) = *(uint32_t*)(a2 + 12);
		*(uint32_t*)(v7 + 444) = *(uint32_t*)(a2 + 16);
		*(uint32_t*)(v7 + 432) = v2;
		*(uint32_t*)(v7 + 436) = v9;
		nox_xxx_sprite_45A110_drawable((uint32_t*)v7);
		nox_xxx_spriteToSightDestroyList_49BAB0_drawable((uint32_t*)v7);
	}
	return 1;
}
