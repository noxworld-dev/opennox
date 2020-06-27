#include "sparklup.h"

#include "../../../proto.h"
#include "../../draw/glowdraw.h"

//----- (004CDBF0) --------------------------------------------------------
int __cdecl sub_4CDBF0(int a1, _DWORD* a2) {
	_DWORD* v2; // ebx
	int v3;     // edi
	int v4;     // ebp
	int v5;     // esi
	bool v6;    // zf
	int v8;     // [esp+10h] [ebp-10h]
	int v9;     // [esp+14h] [ebp-Ch]
	int v10;    // [esp+18h] [ebp-8h]
	int v11;    // [esp+1Ch] [ebp-4h]
	int v12;    // [esp+28h] [ebp+8h]

	v2 = a2;
	v10 = a2[3] - a2[8];
	v11 = a2[4] - a2[9];
	if (!*(_DWORD*)&byte_5D4594[1522996])
		*(_DWORD*)&byte_5D4594[1522996] = sub_44CFC0((CHAR*)&byte_587000[190392]);
	v8 = 0;
	v12 = 0;
	v9 = 5;
	do {
		v3 = v2[8] + v12 / 5 + sub_415FF0(-3, 3, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c", 28);
		v4 = v2[9] + sub_415FF0(-3, 3, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c", 29) + v8 / 5;
		v5 = sub_45A360_drawable(*(int*)&byte_5D4594[1522996], v3, v4);
		if (v5) {
			*(_DWORD*)(v5 + 300) = nox_thing_pixie_dust_draw;
			sub_484BE0((_DWORD*)(v5 + 136), 255, 200, 75);
			*(_DWORD*)(v5 + 432) = v3 << 12;
			*(_DWORD*)(v5 + 436) = v4 << 12;
			*(_BYTE*)(v5 + 299) = 0;
			*(_DWORD*)(v5 + 440) = 0;
			*(_DWORD*)(v5 + 448) = *(_DWORD*)&byte_5D4594[2598000] +
								   sub_415FF0(2, 10, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c", 51);
			*(_DWORD*)(v5 + 444) = *(_DWORD*)&byte_5D4594[2598000];
			*(_WORD*)(v5 + 104) = *((_WORD*)v2 + 52);
			*(_WORD*)(v5 + 106) = *((_WORD*)v2 + 53);
			*(_BYTE*)(v5 + 296) = 0;
			sub_45A110_drawable((_DWORD*)v5);
		}
		v12 += v10;
		v6 = v9 == 1;
		v8 += v11;
		--v9;
	} while (!v6);
	return 1;
}
