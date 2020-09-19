#include "healup.h"

#include "../../../proto.h"

//----- (004CD450) --------------------------------------------------------
int __cdecl sub_4CD450(_DWORD* a1, int a2) {
	int v2;      // esi
	int v3;      // eax
	int v4;      // ecx
	int v5;      // eax
	_DWORD* v6;  // eax
	int v7;      // eax
	_DWORD* v8;  // ebx
	int v9;      // eax
	_DWORD* v10; // eax
	int v11;     // eax
	_DWORD* v12; // edi
	_DWORD* v13; // edi
	int v14;     // ebx
	int v15;     // edx
	int v16;     // ebp
	int v17;     // edx
	int v18;     // ecx
	int v19;     // esi
	char v20;    // al
	int v22;     // [esp+0h] [ebp-8h]
	__int16 v23; // [esp+4h] [ebp-4h]
	int v24;     // [esp+Ch] [ebp+4h]

	if (!*getMemU32Ptr(0x5D4594, 1522972))
		*getMemU32Ptr(0x5D4594, 1522972) = sub_44CFC0((CHAR*)getMemAt(0x587000, 189112));
	if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 20) < 50) {
		if (*(_BYTE*)(a2 + 432)) {
			if (a2 == -432)
				return 1;
			if (sub_578B70(*(_DWORD*)(a2 + 437))) {
				v5 = sub_578B30(*(_DWORD*)(a2 + 437));
				v6 = sub_45A720(v5);
			} else {
				v7 = sub_578B30(*(_DWORD*)(a2 + 437));
				v6 = sub_45A6F0(v7);
			}
			v8 = v6;
			if (sub_578B70(*(_DWORD*)(a2 + 441))) {
				v9 = sub_578B30(*(_DWORD*)(a2 + 441));
				v10 = sub_45A720(v9);
			} else {
				v11 = sub_578B30(*(_DWORD*)(a2 + 441));
				v10 = sub_45A6F0(v11);
			}
			v12 = v10;
			if (!v8 || !v10)
				return 1;
			v2 = v10[3] + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 61);
			v3 = v12[4] + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 62);
			v4 = v8[4];
			v22 = v8[3];
		} else {
			if (a2 == -432)
				return 1;
			v2 = *(unsigned __int16*)(a2 + 441) +
				 sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 31);
			v3 = *(unsigned __int16*)(a2 + 443) +
				 sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 32);
			LOWORD(v22) = *(_WORD*)(a2 + 437);
			LOWORD(v4) = *(_WORD*)(a2 + 439);
		}
		v13 = a1;
		v23 = v4;
		v14 = *a1;
		v15 = *a1 - a1[4];
		v16 = a1[5];
		v24 = *(__int16*)(a2 + 104);
		v17 = v2 + v15;
		v18 = v3 + v13[1] - v16 - v24;
		if (v17 < 0)
			v2 = v13[4] + v14 + 1;
		if (v18 < 0)
			v3 = v16 - v24 + v13[1] + 1;
		if (v17 >= v13[8])
			v2 = v13[2] + v13[4] - 1;
		if (v18 >= v13[9])
			v3 = v13[3] - v24 + v16 - 1;
		v19 = sub_45A360_drawable(*getMemIntPtr(0x5D4594, 1522972), v2, v3);
		if (v19) {
			v20 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 92);
			*(_WORD*)(v19 + 432) = v22;
			*(_WORD*)(v19 + 434) = v23;
			*(_BYTE*)(v19 + 443) = v20;
			*(_BYTE*)(v19 + 444) = sub_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 99);
		}
	}
	return 1;
}
