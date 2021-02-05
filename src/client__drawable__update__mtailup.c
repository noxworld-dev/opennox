#include "client__drawable__update__mtailup.h"

#include "common__random.h"
#include "proto.h"
#include "client__draw__glowdraw.h"

extern unsigned int nox_gameFPS;
//----- (004CDD80) --------------------------------------------------------
void  nox_xxx_updDrawMagic_4CDD80(int a1, _DWORD* a2) {
	_DWORD* v2; // edi
	int v3;     // eax
	int v4;     // eax
	_DWORD* v5; // esi
	int v6;     // ebx
	int v7;     // ebp
	int v8;     // esi
	int v9;     // eax
	int v10;    // eax
	int v11;    // esi
	int v13;    // [esp+10h] [ebp-8h]
	int v14;    // [esp+14h] [ebp-4h]
	int v15;    // [esp+20h] [ebp+8h]

	v2 = a2;
	v3 = a2[3] - a2[108];
	if (v3 * v3 + (a2[4] - a2[109]) * (a2[4] - a2[109]) > 200) {
		v4 = *getMemU32Ptr(0x5D4594, 1523000);
		if (!*getMemU32Ptr(0x5D4594, 1523000)) {
			v4 = nox_xxx_getTTByNameSpriteMB_44CFC0((CHAR*)getMemAt(0x587000, 190560));
			*getMemU32Ptr(0x5D4594, 1523000) = v4;
		}
		v5 = (_DWORD*)nox_xxx_spriteLoadAdd_45A360_drawable(v4, a2[108], a2[109]);
		v5[108] = a2[3];
		v5[109] = a2[4];
		nox_xxx_sprite_45A110_drawable(v5);
		a2[108] = a2[3];
		a2[109] = a2[4];
		nox_xxx_spriteTransparentDecay_49B950(v5, (int)nox_gameFPS);
	}
	v13 = a2[3] - a2[8];
	v14 = a2[4] - a2[9];
	if (!*getMemU32Ptr(0x5D4594, 1523004))
		*getMemU32Ptr(0x5D4594, 1523004) = nox_xxx_getTTByNameSpriteMB_44CFC0((CHAR*)getMemAt(0x587000, 190576));
	v6 = 0;
	v7 = 0;
	v15 = 4;
	do {
		v8 = v2[8] + v7 / 4 + nox_common_randomIntMinMax_415FF0(-8, 8, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mtailup.c", 66);
		v9 = nox_common_randomIntMinMax_415FF0(-8, 8, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mtailup.c", 68);
		v10 = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1523004), v8, v2[9] + v6 / 4 + v9);
		v11 = v10;
		if (v10) {
			*(_DWORD*)(v10 + 300) = nox_thing_magic_sparkle_draw;
			nox_xxx_spriteChangeLightColor_484BE0((_DWORD*)(v10 + 136), 128, 128, 255);
			*(_DWORD*)(v11 + 432) = v2[3] << 12;
			*(_DWORD*)(v11 + 436) = v2[4] << 12;
			*(_BYTE*)(v11 + 299) = 0;
			*(_DWORD*)(v11 + 440) = 0;
			*(_DWORD*)(v11 + 448) = *getMemU32Ptr(0x5D4594, 2598000) +
									nox_common_randomIntMinMax_415FF0(10, 20, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mtailup.c", 90);
			*(_DWORD*)(v11 + 444) = *getMemU32Ptr(0x5D4594, 2598000);
			*(_WORD*)(v11 + 104) = *((_WORD*)v2 + 52);
			*(_WORD*)(v11 + 106) = *((_WORD*)v2 + 53);
			*(_BYTE*)(v11 + 296) = 0;
			nox_xxx_sprite_45A110_drawable((_DWORD*)v11);
		}
		v7 += v13;
		v6 += v14;
		v15--;
	} while (v15);
}
