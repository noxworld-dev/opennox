#include "client__drawable__update__cloud.h"
#include "common__random.h"

#include "proto.h"

//----- (004CE200) --------------------------------------------------------
int  sub_4CE200(int a1, int a2, int a3, int a4) {
	int result; // eax
	int v5;     // edi
	int v6;     // eax
	int v7;     // esi
	int v8;     // edi
	bool v9;    // cc
	int v10;    // eax
	int v11;    // eax
	int v12;    // esi
	int v13;    // eax

	if (!*getMemU32Ptr(0x5D4594, 1523016)) {
		*getMemU32Ptr(0x5D4594, 1523016) = nox_xxx_getTTByNameSpriteMB_44CFC0((CHAR*)getMemAt(0x587000, 191240));
		*getMemU32Ptr(0x5D4594, 1523020) = nox_xxx_getTTByNameSpriteMB_44CFC0((CHAR*)getMemAt(0x587000, 191252));
	}
	result = a3;
	if (a3 > 0) {
		do {
			v5 = nox_common_randomIntMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\cloud.c", 40);
			v6 = nox_common_randomIntMinMax_415FF0(0, a4, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\cloud.c", 41);
			v7 = *(_DWORD*)(a2 + 12) + v6 * *getMemIntPtr(0x587000, 8 * v5 + 192088) / 16;
			v8 = *(_DWORD*)(a2 + 16) + v6 * *getMemIntPtr(0x587000, 8 * v5 + 192092) / 16;
			v9 = nox_common_randomIntMinMax_415FF0(0, 10, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\cloud.c", 46) < 3;
			v10 = *getMemU32Ptr(0x5D4594, 1523020);
			if (!v9)
				v10 = *getMemU32Ptr(0x5D4594, 1523016);
			v11 = nox_xxx_spriteLoadAdd_45A360_drawable(v10, v7, v8);
			v12 = v11;
			if (v11) {
				*(_WORD*)(v11 + 104) = 0;
				nox_xxx_sprite_45A110_drawable((_DWORD*)v11);
				*(_BYTE*)(v12 + 432) = nox_common_randomIntMinMax_415FF0(1, 3, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\cloud.c", 57);
				*(_DWORD*)(v12 + 460) = sub_4CE340;
				v13 = nox_common_randomIntMinMax_415FF0(10, 32, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\cloud.c", 61);
				nox_xxx_spriteTransparentDecay_49B950((_DWORD*)v12, v13);
				nox_xxx_spriteToList_49BC80_drawable((_DWORD*)v12);
				nox_xxx_spriteToSightDestroyList_49BAB0_drawable((_DWORD*)v12);
			}
			result = --a3;
		} while (a3);
	}
	return result;
}
