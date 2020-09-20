#include "vortexup.h"

#include "../../../proto.h"

//----- (004CC950) --------------------------------------------------------
int __cdecl sub_4CC950(int a1, int a2) {
	int v2;  // ebp
	int v3;  // esi
	int v4;  // eax
	char v5; // bl
	int v6;  // eax
	int v7;  // esi
	int v9;  // [esp+0h] [ebp-4h]

	if (!*getMemU32Ptr(0x5D4594, 1522952)) {
		*getMemU32Ptr(0x5D4594, 1522952) = sub_44CFC0((CHAR*)getMemAt(0x587000, 187880));
		*getMemU32Ptr(0x5D4594, 1522944) = nox_color_rgb_4344A0(200, 200, 200);
		*getMemU32Ptr(0x5D4594, 1522948) = nox_color_rgb_4344A0(255, 255, 255);
	}
	v2 = *getMemU32Ptr(0x5D4594, 1522944);
	v3 = *getMemU32Ptr(0x5D4594, 1522952);
	v9 = *getMemU32Ptr(0x5D4594, 1522948);
	v4 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c", 54);
	v5 = v4;
	v6 = sub_45A360_drawable(v3, *(_DWORD*)(a2 + 12) + 50 * *getMemIntPtr(0x587000, 8 * v4 + 192088) / 16,
							 *(_DWORD*)(a2 + 16) + 50 * *getMemIntPtr(0x587000, 8 * v4 + 192092) / 16);
	v7 = v6;
	if (v6) {
		*(_BYTE*)(v6 + 448) = v5;
		*(_WORD*)(a2 + 104) = 0;
		*(_BYTE*)(v6 + 449) = sub_415FF0(2, 3, "C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c", 74);
		if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c", 75) > 50)
			*(_BYTE*)(v7 + 449) = -*(_BYTE*)(v7 + 449);
		*(_BYTE*)(v7 + 451) = 1;
		*(_BYTE*)(v7 + 450) = 50;
		*(_DWORD*)(v7 + 440) = *(_DWORD*)(a2 + 12);
		*(_DWORD*)(v7 + 444) = *(_DWORD*)(a2 + 16);
		*(_DWORD*)(v7 + 432) = v2;
		*(_DWORD*)(v7 + 436) = v9;
		sub_45A110_drawable((_DWORD*)v7);
		sub_49BAB0_drawable((_DWORD*)v7);
	}
	return 1;
}
