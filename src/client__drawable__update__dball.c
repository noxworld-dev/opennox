#include "client__drawable__update__dball.h"
#include "common__random.h"

#include "GAME2.h"
#include "client__draw__fx.h"

extern unsigned int nox_frame_xxx_2598000;
//----- (004CDFA0) --------------------------------------------------------
uint32_t* nox_xxx_updDrawAddRndSpark_4CDFA0(int a1, uint32_t* a2) {
	uint32_t* result; // eax
	uint32_t* v3;     // ebp
	uint32_t* v4;     // esi

	if (!*getMemU32Ptr(0x5D4594, 1523008)) {
		*getMemU32Ptr(0x5D4594, 1523008) = nox_xxx_getTTByNameSpriteMB_44CFC0("DeathBallSpark");
	}
	result = a2;
	if ((int)a2 > 0) {
		v3 = a2;
		do {
			result = (uint32_t*)nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1523008),
																	  *(uint32_t*)(a1 + 12), *(uint32_t*)(a1 + 16));
			v4 = result;
			if (result) {
				result[108] = *(uint32_t*)(a1 + 12) << 12;
				result[109] = *(uint32_t*)(a1 + 16) << 12;
				*((uint8_t*)result + 299) = nox_common_randomIntMinMax_415FF0(
					0, 255, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 37);
				v4[110] = nox_common_randomIntMinMax_415FF0(1000, 3000,
															"C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 40);
				v4[112] = nox_frame_xxx_2598000 +
						  nox_common_randomIntMinMax_415FF0(10, 40,
															"C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 43);
				v4[111] = nox_frame_xxx_2598000;
				*((uint16_t*)v4 + 52) = 22;
				*((uint8_t*)v4 + 296) =
					nox_common_randomIntMinMax_415FF0(0, 4, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 49);
				nox_xxx_sprite_45A110_drawable(v4);
			}
			v3 = (uint32_t*)((char*)v3 - 1);
		} while (v3);
	}
	return result;
}

//----- (004CE0C0) --------------------------------------------------------
int nox_xxx_updDrawDBallCharge_4CE0C0(int a1, int a2) {
	int v2;       // ebx
	short v3;     // cx
	int v4;       // esi
	short v5;     // ax
	short v6;     // cx
	int v7;       // eax
	int v9;       // [esp-18h] [ebp-20h]
	char v10;     // [esp-14h] [ebp-1Ch]
	short v11[4]; // [esp+0h] [ebp-8h]

	if (!*getMemU32Ptr(0x5D4594, 1523012)) {
		*getMemU32Ptr(0x5D4594, 1523012) = nox_xxx_getTTByNameSpriteMB_44CFC0("CharmOrb");
	}
	v2 = 10;
	v3 = *(uint16_t*)(a2 + 16);
	v11[0] = *(uint16_t*)(a2 + 12);
	v11[1] = v3;
	do {
		v4 = nox_common_randomIntMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 102);
		v5 = nox_common_randomIntMinMax_415FF0(2, 8, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 105);
		v6 = *(uint16_t*)(a2 + 16) + v5 * *getMemI16Ptr(0x587000, 192092 + 8 * v4);
		v11[2] = *(uint16_t*)(a2 + 12) + v5 * *getMemI16Ptr(0x587000, 192088 + 8 * v4);
		v11[3] = v6;
		if (nox_common_randomIntMinMax_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 112) <
			50) {
			v10 = nox_common_randomIntMinMax_415FF0(6, 10, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 116);
			v9 = nox_common_randomIntMinMax_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 115);
			v7 = nox_common_randomIntMinMax_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 114);
			sub_499490(*getMemIntPtr(0x5D4594, 1523012), v11, v7, v9, v10, 0);
		}
		--v2;
	} while (v2);
	return 1;
}
