#include "partrain.h"

#include "../../proto.h"

//----- (004B7810) --------------------------------------------------------
int __cdecl nox_thing_blue_rain_draw(int a1, int a2) {
	int v3; // ebx
	int v4; // ebp
	int v5; // eax
	int v6; // edi
	int v7; // eax
	int v8; // esi
	int v9; // [esp+8h] [ebp+8h]

	if (nox_common_gameFlags_check_40A5C0(0x200000))
		return 1;
	if (!*(_DWORD*)&byte_5D4594[1313716])
		*(_DWORD*)&byte_5D4594[1313716] = sub_44CFC0((CHAR*)&byte_587000[176640]);
	v3 = a2;
	v9 = 2;
	do {
		v4 = *(_DWORD*)(v3 + 12) + sub_415FF0(-10, 10, "C:\\NoxPost\\src\\client\\Draw\\PartRain.c", 42);
		v5 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\client\\Draw\\PartRain.c", 43);
		v6 = *(_DWORD*)(v3 + 16) + v5;
		v7 = sub_45A360_drawable(*(int*)&byte_5D4594[1313716], v4, v6);
		v8 = v7;
		if (v7) {
			*(_DWORD*)(v7 + 432) = v4 << 12;
			*(_DWORD*)(v7 + 436) = v6 << 12;
			*(_BYTE*)(v7 + 299) = 0;
			*(_DWORD*)(v7 + 440) = 0;
			*(_DWORD*)(v7 + 448) = *(_DWORD*)&byte_5D4594[2598000] +
					       sub_415FF0(90, 120, "C:\\NoxPost\\src\\client\\Draw\\PartRain.c", 63);
			*(_DWORD*)(v8 + 444) = *(_DWORD*)&byte_5D4594[2598000];
			*(_WORD*)(v8 + 106) = 0;
			*(_BYTE*)(v8 + 296) = -5;
			*(_WORD*)(v8 + 104) = v6 - *(_WORD*)(a1 + 20);
			sub_45A110_drawable((_DWORD*)v8);
		}
		--v9;
	} while (v9);
	return 1;
}
