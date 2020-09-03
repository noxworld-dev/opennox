#include "triggerdraw.h"
#include "../../proto.h"

//----- (004BB9D0) --------------------------------------------------------
int __cdecl nox_thing_trigger_draw(_DWORD* a1, nox_drawable* dr) {
	int v2 = *a1 - a1[4];
	int v3 = a1[1] - a1[5];

	int v4 = *(_DWORD*)&dr->field_3 + v2 + nox_float2int(dr->shape.box_left_top);
	int v12 = *(_DWORD*)&dr->field_4 + v3 + nox_float2int(dr->shape.box_left_bottom);
	int v7 = *(_DWORD*)&dr->field_3 + v2 + nox_float2int(dr->shape.box_right_bottom_2);
	int v8 = *(_DWORD*)&dr->field_4 + v3 + nox_float2int(dr->shape.box_right_top_2);
	int v9 = *(_DWORD*)&dr->field_3 + v2 + nox_float2int(dr->shape.box_left_bottom_2);
	int v10 = *(_DWORD*)&dr->field_4 + v3 + nox_float2int(dr->shape.box_left_top_2);
	int v11 = *(_DWORD*)&dr->field_3 + v2 + nox_float2int(dr->shape.box_right_top);
	int v5 = *(_DWORD*)&dr->field_4 + v3 + nox_float2int(dr->shape.box_right_bottom);

	nox_client_drawSetColor_434460(*(int*)getMemAt(0x5D4594, 2650656));
	nox_client_drawEnableAlpha_434560(1);
	nox_client_drawAddPoint_49F500(v4, v12);
	nox_client_drawAddPoint_49F500(v11, v5);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v7, v8);
	nox_client_drawAddPoint_49F500(v11, v5);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v4, v12);
	nox_client_drawAddPoint_49F500(v9, v10);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v7, v8);
	nox_client_drawAddPoint_49F500(v9, v10);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawEnableAlpha_434560(0);

	return 1;
}
