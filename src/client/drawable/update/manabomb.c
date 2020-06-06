#include "manabomb.h"

#include "../../../proto.h"
#include "../../draw/fx.h"
extern _DWORD dword_5d4594_1522956;

//----- (004CCAC0) --------------------------------------------------------
int __cdecl sub_4CCAC0(int a1, _DWORD* a2) {
	unsigned int v2;      // ebx
	_DWORD* v3;           // ebp
	int v4;               // edi
	int v5;               // esi
	int v6;               // eax
	int v7;               // eax
	int v8;               // esi
	__int16 v9;           // cx
	unsigned int v10;     // edi
	unsigned __int8* v11; // esi
	__int16 v12;          // cx
	float v14;            // [esp+0h] [ebp-20h]
	int i;                // [esp+14h] [ebp-Ch]
	__int16 v16;          // [esp+18h] [ebp-8h]
	__int16 v17;          // [esp+1Ah] [ebp-6h]
	unsigned int v18;     // [esp+1Ch] [ebp-4h]
	int v19;              // [esp+28h] [ebp+8h]

	v14 = sub_419D40(&byte_587000[188052]);
	v2 = nox_float2int(v14);
	if (!dword_5d4594_1522956) {
		dword_5d4594_1522956 = sub_44CFC0((CHAR*)&byte_587000[188072]);
		*(_DWORD*)&byte_5D4594[1522960] = sub_44CFC0((CHAR*)&byte_587000[188084]);
	}
	v3 = a2;
	v19 = 20;
	v4 = v2 >> 2;
	v18 = v2 >> 4;
	for (i = v2 >> 2;; v4 = i) {
		v5 = v4 + sub_415FF0(0, v2, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 63);
		if (v5 > (int)v2)
			v5 = v2;
		v6 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 68);
		v7 = sub_45A360_drawable(*(int*)&byte_5D4594[1522960],
					 v3[3] + v5 * *(int*)&byte_587000[8 * v6 + 192088] / 16,
					 v3[4] + v5 * *(int*)&byte_587000[8 * v6 + 192092] / 16);
		v8 = v7;
		if (v7) {
			*(_DWORD*)(v7 + 432) = *(_DWORD*)(v7 + 12) << 12;
			*(_DWORD*)(v7 + 436) = *(_DWORD*)(v7 + 16) << 12;
			*(_BYTE*)(v7 + 299) = 0;
			*(_DWORD*)(v7 + 440) = 0;
			*(_DWORD*)(v7 + 448) =
			    *(_DWORD*)&byte_5D4594[2598000] +
			    sub_415FF0(10, 30, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 88);
			*(_DWORD*)(v8 + 444) = *(_DWORD*)&byte_5D4594[2598000];
			*(_WORD*)(v8 + 104) = 0;
			*(_BYTE*)(v8 + 296) =
			    sub_415FF0(2, 8, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 94);
			sub_45A110_drawable((_DWORD*)v8);
		}
		if (!--v19)
			break;
	}
	if (byte_5D4594[2598000] & 1) {
		if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - v3[80]) < 0xA) {
			v9 = *((_WORD*)v3 + 8);
			LOWORD(i) = *((_WORD*)v3 + 6);
			HIWORD(i) = v9;
			v10 = *(_DWORD*)&byte_5D4594[2598000] % 0x33u;
			if ((int)(*(_DWORD*)&byte_5D4594[2598000] % 0x33u) < 256) {
				v11 = &byte_587000[8 * v10 + 192092];
				do {
					v12 = v18 * *(_WORD*)v11;
					v16 = i + v18 * *((_WORD*)v11 - 2);
					v17 = HIWORD(i) + v12;
					sub_499520(*(int*)&dword_5d4594_1522956, (unsigned __int16*)&i, v10, 0, 0);
					sub_499520(*(int*)&dword_5d4594_1522956, (unsigned __int16*)&i, v10, 1, 0);
					v11 += 408;
					LOWORD(v10) = v10 + 51;
				} while ((int)v11 < (int)&byte_587000[194140]);
			}
		}
	}
	return 1;
}
