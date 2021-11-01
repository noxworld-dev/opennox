#include "client__draw__partrain.h"
#include "client__draw__lvupdraw.h"
#include "common__random.h"

#include "GAME1.h"
#include "GAME2.h"

extern unsigned int nox_frame_xxx_2598000;
//----- (004B7810) --------------------------------------------------------
int  nox_thing_blue_rain_draw(int a1, nox_drawable* dr) {
	int v3; // ebx
	int v4; // ebp
	int v5; // eax
	int v6; // edi
	int v7; // eax
	int v8; // esi
	int v9; // [esp+8h] [ebp+8h]

	int a2 = dr;

	if (nox_common_gameFlags_check_40A5C0(0x200000)) {
		return 1;
}
	if (!*getMemU32Ptr(0x5D4594, 1313716)) {
		*getMemU32Ptr(0x5D4594, 1313716) = nox_xxx_getTTByNameSpriteMB_44CFC0("BlueRainSpark");
}
	v3 = a2;
	v9 = 2;
	do {
		v4 = *(uint32_t*)(v3 + 12) + nox_common_randomIntMinMax_415FF0(-10, 10, "C:\\NoxPost\\src\\client\\Draw\\PartRain.c", 42);
		v5 = nox_common_randomIntMinMax_415FF0(-10, 10, "C:\\NoxPost\\src\\client\\Draw\\PartRain.c", 43);
		v6 = *(uint32_t*)(v3 + 16) + v5;
		v7 = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1313716), v4, v6);
		v8 = v7;
		if (v7) {
			*(uint32_t*)(v7 + 432) = v4 << 12;
			*(uint32_t*)(v7 + 436) = v6 << 12;
			*(uint8_t*)(v7 + 299) = 0;
			*(uint32_t*)(v7 + 440) = 0;
			*(uint32_t*)(v7 + 448) =
				nox_frame_xxx_2598000 + nox_common_randomIntMinMax_415FF0(90, 120, "C:\\NoxPost\\src\\client\\Draw\\PartRain.c", 63);
			*(uint32_t*)(v8 + 444) = nox_frame_xxx_2598000;
			*(uint16_t*)(v8 + 106) = 0;
			*(uint8_t*)(v8 + 296) = -5;
			*(uint16_t*)(v8 + 104) = v6 - *(uint16_t*)(a1 + 20);
			nox_xxx_sprite_45A110_drawable((uint32_t*)v8);
		}
		--v9;
	} while (v9);
	return 1;
}

//----- (004B7700) --------------------------------------------------------
int  nox_thing_levelup_draw(int a1, nox_drawable* dr) {
	int v2; // eax

	v2 = *getMemU32Ptr(0x5D4594, 1313708);
	if (!*getMemU32Ptr(0x5D4594, 1313708)) {
		v2 = nox_xxx_getTTByNameSpriteMB_44CFC0("RainOrbWhite");
		*getMemU32Ptr(0x5D4594, 1313708) = v2;
	}
	nox_thing_falling_sparks_draw_4B7740(v2, a1, dr);
	return 1;
}

//----- (004B77D0) --------------------------------------------------------
int  nox_thing_oblivion_up_draw(int a1, nox_drawable* dr) {
	int v2; // eax

	v2 = *getMemU32Ptr(0x5D4594, 1313712);
	if (!*getMemU32Ptr(0x5D4594, 1313712)) {
		v2 = nox_xxx_getTTByNameSpriteMB_44CFC0("RainOrbBlue");
		*getMemU32Ptr(0x5D4594, 1313712) = v2;
	}
	nox_thing_falling_sparks_draw_4B7740(v2, a1, dr);
	return 1;
}
