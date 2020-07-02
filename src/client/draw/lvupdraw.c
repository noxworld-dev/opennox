#include "lvupdraw.h"

#include "../../proto.h"
#include "fx.h"

//----- (004B7740) --------------------------------------------------------
_DWORD* __cdecl nox_thing_falling_sparks_draw_4B7740(int a1, int a2, int a3) {
	int2* v3;       // edi
	int v4;         // ebp
	int v5;         // eax
	int v6;         // esi
	char v7;        // al
	_DWORD* result; // eax
	int2 a2a;       // [esp+10h] [ebp-8h]

	v3 = (int2*)(a3 + 12);
	v4 = 2;
	do {
		a2a.field_0 = v3->field_0 + sub_415FF0(-15, 15, "C:\\NoxPost\\src\\client\\Draw\\LvUpDraw.c", 35);
		v5 = *(_DWORD*)(a3 + 16) + sub_415FF0(-15, 15, "C:\\NoxPost\\src\\client\\Draw\\LvUpDraw.c", 36);
		a2a.field_4 = v5;
		v6 = v5 - *(_DWORD*)(a2 + 20);
		v7 = sub_415FF0(8, 12, "C:\\NoxPost\\src\\client\\Draw\\LvUpDraw.c", 40);
		result = (_DWORD*)sub_499950(a1, &a2a, v3, v6, -v7);
		--v4;
	} while (v4);
	return result;
}
