#include "client__draw__doordraw.h"
#include "client__draw__parse__parse.h"
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3_1.h"
#include "client__gui__window.h"
#include "client__video__draw_common.h"
#include "operators.h"

extern uint32_t dword_5d4594_3807156;

//----- (004BC9E0) --------------------------------------------------------
int  nox_thing_door_draw(uint32_t* a1, nox_drawable* dr) {
	uint8_t* v2; // edi
	int v3;    // eax
	int v4;    // edx
	int v5;    // ecx
	char v6;   // al
	char v7;   // dl
	char v9;   // dl
	char v10;  // dl
	char v11;  // dl
	int v12;   // [esp-4h] [ebp-18h]
	int v13;   // [esp-4h] [ebp-18h]
	int v14;   // [esp-4h] [ebp-18h]
	int v15;   // [esp-4h] [ebp-18h]
	int2 a3;   // [esp+Ch] [ebp-8h]

	nox_xxx_drawObject_4C4770_draw(a1, dr, *(uint32_t*)(*(uint32_t*)((char*)dr->field_76 + 4) + 4 * dr->field_74_4));
	if (!nox_common_gameFlags_check_40A5C0(4096) || dr->field_108_1 != 1)
		return 1;
	if (!dr->field_109) {
		dr->field_110 = nox_xxx_gLoadImg_42F970("DoorLockSilverSW");
		dr->field_109 = nox_xxx_gLoadImg_42F970("DoorLockSilverSE");
		dr->field_111 = nox_xxx_gLoadImg_42F970("DoorLockGoldSW");
		dr->field_112 = nox_xxx_gLoadImg_42F970("DoorLockGoldSE");
	}
	sub_4739E0(a1, &dr->pos, &a3);
	a3.field_0 -= 64;
	a3.field_4 -= 79;
	v2 = (uint8_t*)(*(int(**)(int2*)) & dword_5d4594_3807156)(&dr->pos);
	v3 = sub_4345F0(1);
	LOBYTE(v4) = v2[8];
	LOBYTE(v3) = v2[4];
	LOBYTE(v5) = *v2;
	sub_433CD0(v5, v3, v4);
	v6 = dr->field_74_4;
	if (v6 == 0) {
		v7 = dr->field_108_2;
		v12 = a3.field_4 - 20;
		a3.field_0 -= 15;
		a3.field_4 -= 20;
		if (v7 == 1)
			nox_client_drawImageAt_47D2C0(dr->field_110, a3.field_0, v12);
		else
			nox_client_drawImageAt_47D2C0(dr->field_111, a3.field_0, v12);
		return 1;
	} else if (v6 == 8) {
		v9 = dr->field_108_2;
		v13 = a3.field_4 - 20;
		a3.field_0 += 15;
		a3.field_4 -= 20;
		if (v9 == 1)
			nox_client_drawImageAt_47D2C0(dr->field_109, a3.field_0, v13);
		else
			nox_client_drawImageAt_47D2C0(dr->field_112, a3.field_0, v13);
		return 1;
	} else if (v6 == 16) {
		v10 = dr->field_108_2;
		v14 = a3.field_4 + 2;
		a3.field_0 += 8;
		a3.field_4 += 2;
		if (v10 == 1)
			nox_client_drawImageAt_47D2C0(dr->field_110, a3.field_0, v14);
		else
			nox_client_drawImageAt_47D2C0(dr->field_111, a3.field_0, v14);
		return 1;
	} else {
		v11 = dr->field_108_2;
		v15 = a3.field_4 + 2;
		a3.field_0 -= 8;
		a3.field_4 += 2;
		if (v11 == 1)
			nox_client_drawImageAt_47D2C0(dr->field_109, a3.field_0, v15);
		else
			nox_client_drawImageAt_47D2C0(dr->field_112, a3.field_0, v15);
		return 1;
	}
}

//----- (0044C0F0) --------------------------------------------------------
bool  nox_things_door_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->draw_func = &nox_thing_door_draw;
	void* v3 = nox_xxx_spriteLoadStaticRandomData_44C000(attr_value, f);
	obj->field_5c = v3;
	return v3 != 0;
}
