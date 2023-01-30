#include "client__draw__pressureplatedraw.h"
#include "GAME1_1.h"
#include "GAME2_3.h"
#include "client__video__draw_common.h"
#include "operators.h"

//----- (004BBB30) --------------------------------------------------------
int nox_thing_pressure_plate_draw(uint32_t* a1, nox_drawable* dr) {
	int v2;    // esi
	int v4;    // ebp
	int v5;    // edi
	int v6;    // ebx
	int v7;    // ebp
	int v8;    // eax
	int v9;    // edx
	int v10;   // ecx
	int v11;   // eax
	int v12;   // edi
	float v13; // [esp-10h] [ebp-34h]
	int v14;   // [esp+4h] [ebp-20h]
	int v15;   // [esp+8h] [ebp-1Ch]
	int v16;   // [esp+Ch] [ebp-18h]
	int v17;   // [esp+10h] [ebp-14h]
	int v18;   // [esp+14h] [ebp-10h]
	int v19;   // [esp+1Ch] [ebp-8h]
	int v20;   // [esp+2Ch] [ebp+8h]

	v2 = dr;
	if (!*(uint8_t*)(v2 + 432) && !*(uint8_t*)(v2 + 433) && !*(uint8_t*)(v2 + 434) && !*(uint8_t*)(v2 + 435) &&
		!*(uint8_t*)(v2 + 436) && !*(uint8_t*)(v2 + 437)) {
		return 1;
	}
	v4 = a1[1] - a1[5];
	v13 = *(float*)(v2 + 64);
	v5 = *a1 - a1[4];
	v20 = a1[1] - a1[5];
	v18 = *(uint32_t*)(v2 + 12) + v5 + nox_float2int(v13);
	v6 = *(uint32_t*)(v2 + 16) + v4 + nox_float2int(*(float*)(v2 + 68));
	v19 = *(uint32_t*)(v2 + 12) + v5 + nox_float2int(*(float*)(v2 + 88));
	v7 = *(uint32_t*)(v2 + 16) + v20 + nox_float2int(*(float*)(v2 + 92));
	v16 = *(uint32_t*)(v2 + 12) + v5 + nox_float2int(*(float*)(v2 + 72));
	v17 = *(uint32_t*)(v2 + 16) + v20 + nox_float2int(*(float*)(v2 + 76));
	v14 = *(uint32_t*)(v2 + 12) + v5 + nox_float2int(*(float*)(v2 + 80));
	v8 = nox_float2int(*(float*)(v2 + 84));
	v9 = v20;
	v10 = *(uint32_t*)(v2 + 16);
	v11 = v10 + v20 + v8;
	v12 = 0;
	v15 = v11;
	do {
		if (v12) {
			LOBYTE(v9) = *(uint8_t*)(v2 + 437);
			LOBYTE(v11) = *(uint8_t*)(v2 + 436);
			LOBYTE(v10) = *(uint8_t*)(v2 + 435);
		} else {
			LOBYTE(v9) = *(uint8_t*)(v2 + 434);
			LOBYTE(v11) = *(uint8_t*)(v2 + 433);
			LOBYTE(v10) = *(uint8_t*)(v2 + 432);
		}
		nox_set_color_rgb_434430(v10, v11, v9);
		nox_client_drawAddPoint_49F500(v12 + v18, v6);
		nox_client_drawAddPoint_49F500(v12 + v14, v15);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(v12 + v19, v7);
		nox_client_drawAddPoint_49F500(v12 + v14, v15);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(v12 + v18, v6);
		nox_client_drawAddPoint_49F500(v12 + v16, v17);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(v12 + v19, v7);
		nox_client_drawAddPoint_49F500(v12 + v16, v17);
		v11 = nox_client_drawLineFromPoints_49E4B0();
		++v12;
	} while (v12 < 2);
	return 1;
}
