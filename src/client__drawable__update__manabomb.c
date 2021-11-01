#include "client__drawable__update__manabomb.h"

#include "GAME1_1.h"
#include "GAME2.h"
#include "client__draw__fx.h"
#include "common__random.h"
#include "operators.h"

extern uint32_t dword_5d4594_1522956;
extern unsigned int nox_frame_xxx_2598000;

//----- (004CCAC0) --------------------------------------------------------
int nox_xxx_updDrawManabombCharge_4CCAC0(int a1, uint32_t* a2) {
	unsigned int v2;    // ebx
	uint32_t* v3;       // ebp
	int v4;             // edi
	int v5;             // esi
	int v6;             // eax
	int v7;             // eax
	int v8;             // esi
	short v9;           // cx
	unsigned int v10;   // edi
	unsigned char* v11; // esi
	short v12;          // cx
	float v14;          // [esp+0h] [ebp-20h]
	int i;              // [esp+14h] [ebp-Ch]
	short v16;          // [esp+18h] [ebp-8h]
	short v17;          // [esp+1Ah] [ebp-6h]
	unsigned int v18;   // [esp+1Ch] [ebp-4h]
	int v19;            // [esp+28h] [ebp+8h]

	v14 = nox_xxx_gamedataGetFloat_419D40("ManaBombOutRadius");
	v2 = nox_float2int(v14);
	if (!dword_5d4594_1522956) {
		dword_5d4594_1522956 = nox_xxx_getTTByNameSpriteMB_44CFC0("ManaBombOrb");
		*getMemU32Ptr(0x5D4594, 1522960) = nox_xxx_getTTByNameSpriteMB_44CFC0("VioletSpark");
	}
	v3 = a2;
	v19 = 20;
	v4 = v2 >> 2;
	v18 = v2 >> 4;
	for (i = v2 >> 2;; v4 = i) {
		v5 =
			v4 + nox_common_randomIntMinMax_415FF0(0, v2, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 63);
		if (v5 > (int)v2) {
			v5 = v2;
		}
		v6 = nox_common_randomIntMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 68);
		v7 = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1522960),
												   v3[3] + v5 * *getMemIntPtr(0x587000, 192088 + 8 * v6) / 16,
												   v3[4] + v5 * *getMemIntPtr(0x587000, 192092 + 8 * v6) / 16);
		v8 = v7;
		if (v7) {
			*(uint32_t*)(v7 + 432) = *(uint32_t*)(v7 + 12) << 12;
			*(uint32_t*)(v7 + 436) = *(uint32_t*)(v7 + 16) << 12;
			*(uint8_t*)(v7 + 299) = 0;
			*(uint32_t*)(v7 + 440) = 0;
			*(uint32_t*)(v7 + 448) =
				nox_frame_xxx_2598000 +
				nox_common_randomIntMinMax_415FF0(10, 30, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 88);
			*(uint32_t*)(v8 + 444) = nox_frame_xxx_2598000;
			*(uint16_t*)(v8 + 104) = 0;
			*(uint8_t*)(v8 + 296) =
				nox_common_randomIntMinMax_415FF0(2, 8, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 94);
			nox_xxx_sprite_45A110_drawable((uint32_t*)v8);
		}
		if (!--v19) {
			break;
		}
	}
	if ((unsigned char)nox_frame_xxx_2598000 & 1) {
		if ((unsigned int)(nox_frame_xxx_2598000 - v3[80]) < 0xA) {
			v9 = *((uint16_t*)v3 + 8);
			LOWORD(i) = *((uint16_t*)v3 + 6);
			HIWORD(i) = v9;
			v10 = nox_frame_xxx_2598000 % 0x33u;
			if ((int)(nox_frame_xxx_2598000 % 0x33u) < 256) {
				v11 = getMemAt(0x587000, 192092 + 8 * v10);
				do {
					v12 = v18 * *(uint16_t*)v11;
					v16 = i + v18 * *((uint16_t*)v11 - 2);
					v17 = HIWORD(i) + v12;
					sub_499520(*(int*)&dword_5d4594_1522956, (unsigned short*)&i, v10, 0, 0);
					sub_499520(*(int*)&dword_5d4594_1522956, (unsigned short*)&i, v10, 1, 0);
					v11 += 408;
					LOWORD(v10) = v10 + 51;
				} while ((int)v11 < (int)getMemAt(0x587000, 194140));
			}
		}
	}
	return 1;
}
