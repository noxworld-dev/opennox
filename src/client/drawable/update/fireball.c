#include "fireball.h"

#include "../../../proto.h"

//----- (004CCEA0) --------------------------------------------------------
void __cdecl sub_4CCEA0(_DWORD* a1, int a2) {
	_DWORD* v2; // ebp
	int v3;     // ebx
	int v4;     // esi
	int v5;     // eax
	int v6;     // ecx
	int v8;     // eax
	int v9;     // edi
	int v11;    // ebx
	int v12;    // esi
	int v13;    // ebx
	int v14;    // ebx
	int v15;    // [esp+0h] [ebp-14h]
	int v16;    // [esp+4h] [ebp-10h]
	float2 v17; // [esp+Ch] [ebp-8h]
	int v18;    // [esp+18h] [ebp+4h]

	if (!*getMemU32Ptr(0x5D4594, 1522964))
		*getMemU32Ptr(0x5D4594, 1522964) = nox_xxx_getTTByNameSpriteMB_44CFC0((CHAR*)getMemAt(0x587000, 188304));
	v2 = a1;
	v3 = a1[4] - a1[9];
	v4 = a1[3] - a1[8];
	v5 = a1[4] - a1[9];
	v18 = v4;
	v15 = v3;
	v6 = abs32(v4) + abs32(v5);
	if (v6 / 7 > 0) {
		v16 = v6 / 7;
		while (1) {
			v8 = nox_common_randomIntMinMax_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c", 46);
			v9 = v2[8] + v4 * v8 / 100;
			v11 = v2[9] + (v3 * v8) / 100;
			v12 = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1522964), v9, v11);
			if (v12) {
				*(_DWORD*)(v12 + 432) = v9 << 12;
				*(_DWORD*)(v12 + 436) = v11 << 12;
				v17.field_0 = (double)-v18;
				v17.field_4 = (double)-v15;
				v13 = nox_common_randomIntMinMax_415FF0(-25, 25, "C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c", 63);
				v14 = nox_xxx_math_509ED0(&v17) + v13;
				if (v14 < 0)
					v14 += (unsigned int)(255 - v14) >> 8 << 8;
				*(_BYTE*)(v12 + 299) = v14;
				*(_DWORD*)(v12 + 440) =
					a2 * nox_common_randomIntMinMax_415FF0(100, 300, "C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c", 74);
				*(_DWORD*)(v12 + 448) =
					*getMemU32Ptr(0x5D4594, 2598000) +
					nox_common_randomIntMinMax_415FF0(30, 45, "C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c", 77);
				*(_DWORD*)(v12 + 444) = *getMemU32Ptr(0x5D4594, 2598000);
				*(_WORD*)(v12 + 104) = 28;
				*(_WORD*)(v12 + 106) = 0;
				*(_BYTE*)(v12 + 296) = nox_common_randomIntMinMax_415FF0(-2, 4, "C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c", 84);
				nox_xxx_sprite_45A110_drawable((_DWORD*)v12);
			}
			--v16;
			if (!v16)
				break;
			v3 = v15;
			v4 = v18;
		}
	}
}
