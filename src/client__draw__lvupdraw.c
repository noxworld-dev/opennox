#include "client__draw__lvupdraw.h"
#include "common__random.h"

#include "client__draw__fx.h"

//----- (004B7740) --------------------------------------------------------
uint32_t* nox_thing_falling_sparks_draw_4B7740(int a1, int a2, nox_drawable* dr) {
	int a3 = dr;
	int2* v3;         // edi
	int v4;           // ebp
	int v5;           // eax
	int v6;           // esi
	char v7;          // al
	uint32_t* result; // eax
	int2 a2a;         // [esp+10h] [ebp-8h]

	v3 = (int2*)(a3 + 12);
	v4 = 2;
	do {
		a2a.field_0 =
			v3->field_0 + nox_common_randomIntMinMax_415FF0(-15, 15, "C:\\NoxPost\\src\\client\\Draw\\LvUpDraw.c", 35);
		v5 = *(uint32_t*)(a3 + 16) +
			 nox_common_randomIntMinMax_415FF0(-15, 15, "C:\\NoxPost\\src\\client\\Draw\\LvUpDraw.c", 36);
		a2a.field_4 = v5;
		v6 = v5 - *(uint32_t*)(a2 + 20);
		v7 = nox_common_randomIntMinMax_415FF0(8, 12, "C:\\NoxPost\\src\\client\\Draw\\LvUpDraw.c", 40);
		result = (uint32_t*)sub_499950(a1, &a2a, v3, v6, -v7);
		--v4;
	} while (v4);
	return result;
}
