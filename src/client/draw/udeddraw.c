#include "udeddraw.h"

#include "../../proto.h"
#include "fx.h"

//----- (004B7A80) --------------------------------------------------------
int __cdecl nox_thing_undead_killer_draw(int* a1, int a2) {
	int result;     // eax
	__int16 v3;     // dx
	int v4;         // eax
	int v5;         // ecx
	int v6;         // ebx
	int v7;         // edi
	int v8;         // eax
	int v9;         // eax
	int v10;        // eax
	int v11;        // [esp-18h] [ebp-28h]
	int v12;        // [esp-14h] [ebp-24h]
	char v13;       // [esp-Ch] [ebp-1Ch]
	__int16 v14[4]; // [esp+0h] [ebp-10h]
	int2 v15;       // [esp+8h] [ebp-8h]

	if (!*(_DWORD*)&byte_5D4594[1313728]) {
		*(_DWORD*)&byte_5D4594[1313736] = sub_44CFC0((CHAR*)&byte_587000[176812]);
		*(_DWORD*)&byte_5D4594[1313732] = sub_4344A0(100, 100, 255);
		*(_DWORD*)&byte_5D4594[1313728] = 1;
	}
	if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a2 + 316)) <= 0x46) {
		if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Draw\\UDedDraw.c", 54) > 85) {
			v3 = *(_WORD*)(a2 + 328);
			v14[0] = *(_WORD*)(a2 + 324);
			v14[1] = v3;
			v14[2] = *(_WORD*)(a2 + 12) + sub_415FF0(-5, 5, "C:\\NoxPost\\src\\client\\Draw\\UDedDraw.c", 60);
			v14[3] = *(_WORD*)(a2 + 16) + sub_415FF0(-5, 5, "C:\\NoxPost\\src\\client\\Draw\\UDedDraw.c", 61);
			v13 = sub_415FF0(6, 10, "C:\\NoxPost\\src\\client\\Draw\\UDedDraw.c", 66);
			v4 = sub_415FF0(-5, 5, "C:\\NoxPost\\src\\client\\Draw\\UDedDraw.c", 65);
			sub_499490(*(int*)&byte_5D4594[1313736], v14, 0, v4, v13, 0);
		}
		v5 = *(_DWORD*)(a2 + 12);
		v6 = a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104);
		v7 = a1[5];
		v8 = *(_DWORD*)(a2 + 328);
		v15.field_0 = v5 + *a1 - a1[4];
		v12 = *(_DWORD*)(a2 + 324);
		v11 = *(_DWORD*)(a2 + 16);
		v15.field_4 = *(_DWORD*)(a2 + 16) + v6 - v7;
		v9 = sub_48C690(v5, v11, v12, v8);
		v10 = 8 - v9 / 40;
		if (v10 < 0)
			v10 = 1;
		sub_4B6720(&v15, *(int*)&byte_5D4594[1313732], v10, 12);
		result = 1;
	} else {
		sub_45A4E0_drawable(a2);
		result = 0;
	}
	return result;
}
