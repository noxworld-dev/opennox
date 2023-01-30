#include "client__drawable__update__manabomb.h"

#include "GAME1_1.h"
#include "GAME2.h"
#include "client__draw__fx.h"
#include "common__random.h"
#include "operators.h"

extern uint32_t dword_5d4594_1522956;

//----- (004CCAC0) --------------------------------------------------------
int nox_xxx_updDrawManabombCharge_4CCAC0(int a1, uint32_t* a2) {
	int rad = (int)nox_xxx_gamedataGetFloat_419D40("ManaBombOutRadius");
	if (!dword_5d4594_1522956) {
		dword_5d4594_1522956 = nox_xxx_getTTByNameSpriteMB_44CFC0("ManaBombOrb");
		*getMemU32Ptr(0x5D4594, 1522960) = nox_xxx_getTTByNameSpriteMB_44CFC0("VioletSpark");
	}

	for (int v19 = 20; v19 != 0; v19--) {
		int v5 = (rad / 4) + nox_common_randomIntMinMax_415FF0(0, rad, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 63);
		if (v5 > rad) {
			v5 = rad;
		}
		int v6 = nox_common_randomIntMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 68);
		int v7 = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1522960),
												   a2[3] + v5 * *getMemIntPtr(0x587000, 192088 + 8 * v6) / 16,
												   a2[4] + v5 * *getMemIntPtr(0x587000, 192092 + 8 * v6) / 16);
		if (v7) {
			*(uint32_t*)(v7 + 432) = *(uint32_t*)(v7 + 12) << 12;
			*(uint32_t*)(v7 + 436) = *(uint32_t*)(v7 + 16) << 12;
			*(uint8_t*)(v7 + 299) = 0;
			*(uint32_t*)(v7 + 440) = 0;
			*(uint32_t*)(v7 + 448) = gameFrame() + nox_common_randomIntMinMax_415FF0(10, 30, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 88);
			*(uint32_t*)(v7 + 444) = gameFrame();
			*(uint16_t*)(v7 + 104) = 0;
			*(uint8_t*)(v7 + 296) = nox_common_randomIntMinMax_415FF0(2, 8, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 94);
			nox_xxx_sprite_45A110_drawable(v7);
		}
	}
	if (gameFrame() & 1) {
		if ((unsigned int)(gameFrame() - a2[80]) < 10) {
			short vv1[4];
			vv1[0] = *((int16_t*)a2 + 6);
			vv1[1] = *((int16_t*)a2 + 8);
			for (int v10 = gameFrame() % 51; v10 < 256; v10 += 51) {
				int16_t* tbl = getMemAt(0x587000, 192088 + 8 * v10);
				vv1[2] = vv1[0] + (rad / 16) * tbl[0];
				vv1[3] = vv1[1] + (rad / 16) * tbl[2];
				sub_499520(dword_5d4594_1522956, &vv1[0], v10, 0, 0);
				sub_499520(dword_5d4594_1522956, &vv1[0], v10, 1, 0);
			}
		}
	}
	return 1;
}
