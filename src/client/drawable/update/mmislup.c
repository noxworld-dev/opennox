#include "mmislup.h"

#include "../../../proto.h"

//----- (004CD9E0) --------------------------------------------------------
int __cdecl sub_4CD9E0(int a1, _DWORD* a2) {
	_DWORD* v2;  // ebp
	int v3;      // esi
	int v4;      // edi
	int v5;      // ebx
	int v6;      // edi
	int v8;      // ebx
	int v9;      // eax
	int v10;     // esi
	int v11;     // edx
	_DWORD* v12; // esi
	int v14;     // [esp+8h] [ebp-8h]
	int v15;     // [esp+Ch] [ebp-4h]
	int v16;     // [esp+18h] [ebp+8h]

	v2 = a2;
	if (!*getMemU32Ptr(0x5D4594, 1522984)) {
		*getMemU32Ptr(0x5D4594, 1522984) = sub_44CFC0((CHAR*)getMemAt(0x587000, 190112));
		*getMemU32Ptr(0x5D4594, 1522988) = sub_44CFC0((CHAR*)getMemAt(0x587000, 190120));
		*getMemU32Ptr(0x5D4594, 1522992) = sub_44CFC0((CHAR*)getMemAt(0x587000, 190128));
	}
	v3 = a2[3] - a2[8];
	v15 = a2[4] - a2[9];
	v14 = a2[3] - a2[8];
	v16 = 0;
	if (*getMemU32Ptr(0x587000, 190108) > 0) {
		while (1) {
			v4 = v2[8];
			v5 = v2[9];
			v6 = v3 * sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 40) / 100 + v4;
			v8 = (v15 * sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 41)) / 100 + v5;
			v9 = sub_45A360_drawable(*getMemIntPtr(0x5D4594, 1522984), v6, v8);
			v10 = v9;
			if (v9) {
				*(_DWORD*)(v9 + 432) = v6 << 12;
				*(_DWORD*)(v9 + 436) = v8 << 12;
				*(_BYTE*)(v9 + 299) = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 52);
				*(_DWORD*)(v10 + 440) = 0;
				*(_DWORD*)(v10 + 448) = *getMemU32Ptr(0x5D4594, 2598000) +
										sub_415FF0(3, 10, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 59);
				*(_DWORD*)(v10 + 444) = *getMemU32Ptr(0x5D4594, 2598000);
				*(_WORD*)(v10 + 104) = 20;
				*(_BYTE*)(v10 + 296) = sub_415FF0(0, 6, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 65);
				sub_45A110_drawable((_DWORD*)v10);
			}
			if (++v16 >= *getMemIntPtr(0x587000, 190108))
				break;
			v3 = v14;
		}
	}
	v11 = v2[108];
	if ((v2[3] - v11) * (v2[3] - v11) + (v2[4] - v2[109]) * (v2[4] - v2[109]) > 200) {
		v12 = (_DWORD*)sub_45A360_drawable(*getMemIntPtr(0x5D4594, 1522992), v11, v2[109]);
		v12[108] = v2[3];
		v12[109] = v2[4];
		sub_45A110_drawable(v12);
		v2[108] = v2[3];
		v2[109] = v2[4];
		sub_49B950(v12, *getMemU32Ptr(0x5D4594, 2649704) / 3u);
	}
	return 1;
}
