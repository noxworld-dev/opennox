#include "harpoondraw.h"
#include "slavedraw.h"
#include "../../proto.h"


//----- (004B64A0) --------------------------------------------------------
int __cdecl nox_thing_harpoon_draw(int* a1, nox_drawable* dr) { return nox_thing_slave_draw(a1, dr); }

//----- (004B61F0) --------------------------------------------------------
int __cdecl nox_thing_harpoon_rope_draw(int* a1, nox_drawable* dr) {
	int v2;              // ecx
	int v3;              // edx
	unsigned __int16 v4; // bx
	int v5;              // edi
	int v6;              // eax
	int v7;              // ebx
	int v8;              // ecx
	_DWORD* v9;          // eax
	_DWORD* v10;         // edi
	_DWORD* v11;         // eax
	int v12;             // ebx
	int v13;             // ebp
	int v14;             // ecx
	int2 a1a;            // [esp+Ch] [ebp-10h]
	int2 a2a;            // [esp+14h] [ebp-8h]
	int v18;             // [esp+20h] [ebp+4h]

	int a2 = dr;

	if (!*(_BYTE*)(a2 + 432)) {
		v2 = a1[4];
		v3 = *a1;
		v4 = *(_WORD*)(a2 + 439);
		a1a.field_0 = *a1 + *(unsigned __int16*)(a2 + 437) - v2;
		v5 = a1[5];
		v6 = a1[1];
		a1a.field_4 = v4 - v5 + v6 - 20;
		v7 = *(unsigned __int16*)(a2 + 441) - v2;
		v8 = *(unsigned __int16*)(a2 + 443) - v5;
		a2a.field_0 = v3 + v7;
		a2a.field_4 = v8 + v6 - 20;
		LABEL_12:
		*getMemU32Ptr(0x5D4594, 1312492) = nox_color_rgb_4344A0(144, 104, 64);
		*getMemU32Ptr(0x5D4594, 1312496) = nox_color_rgb_4344A0(24, 16, 0);
		sub_4B63B0(&a1a, &a2a);
		return 1;
	}
	if (sub_578B70(*(_DWORD*)(a2 + 437)))
		v9 = sub_45A720(*(_DWORD*)(a2 + 437));
	else
		v9 = sub_45A6F0(*(_DWORD*)(a2 + 437));
	v10 = v9;
	if (sub_578B70(*(_DWORD*)(a2 + 441)))
		v11 = sub_45A720(*(_DWORD*)(a2 + 441));
	else
		v11 = sub_45A6F0(*(_DWORD*)(a2 + 441));
	if (v10 && v11) {
		v12 = a1[4];
		v13 = *a1;
		v14 = a1[1];
		v18 = a1[5];
		a1a.field_0 = v13 + v10[3] - v12;
		a1a.field_4 = v14 + v10[4] - v18;
		a2a.field_0 = v13 + v11[3] - v12;
		a2a.field_4 = v14 + v11[4] - *((__int16*)v11 + 53) - *((__int16*)v11 + 52) - v18;
		a1a.field_0 += *getMemU32Ptr(0x587000, 8 * *((unsigned __int8*)v10 + 297) + 175864);
		a1a.field_4 += *getMemU32Ptr(0x587000, 8 * *((unsigned __int8*)v10 + 297) + 175868);
		a2a.field_4 -= 8;
		goto LABEL_12;
	}
	return 1;
}
