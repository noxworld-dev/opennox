#include "client__draw__triggerdraw.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME2_3.h"

//----- (004BB9D0) --------------------------------------------------------
int nox_thing_trigger_draw(uint32_t* a1, nox_drawable* dr) {
	int v2 = *a1 - a1[4];
	int v3 = a1[1] - a1[5];

	int v4 = dr->pos.x + v2 + nox_float2int(dr->shape.box_left_top);
	int v12 = dr->pos.y + v3 + nox_float2int(dr->shape.box_left_bottom);
	int v7 = dr->pos.x + v2 + nox_float2int(dr->shape.box_right_bottom_2);
	int v8 = dr->pos.y + v3 + nox_float2int(dr->shape.box_right_top_2);
	int v9 = dr->pos.x + v2 + nox_float2int(dr->shape.box_left_bottom_2);
	int v10 = dr->pos.y + v3 + nox_float2int(dr->shape.box_left_top_2);
	int v11 = dr->pos.x + v2 + nox_float2int(dr->shape.box_right_top);
	int v5 = dr->pos.y + v3 + nox_float2int(dr->shape.box_right_bottom);

	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 952));
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
