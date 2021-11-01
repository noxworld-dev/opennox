#include "client__draw__spiderspitdraw.h"
#include "GAME1_2.h"
#include "GAME2_3.h"

//----- (004B9D70) --------------------------------------------------------
int nox_thing_spider_spit_draw(uint32_t* a1, nox_drawable* dr) {
	uint32_t* v2; // eax
	int v3;       // edi
	int v4;       // ebp
	int v5;       // edx
	int v6;       // ecx
	int v7;       // esi
	int v8;       // ebp
	int v9;       // ebx
	int v10;      // edi
	int v12;      // [esp+14h] [ebp-Ch]
	int v13;      // [esp+18h] [ebp-8h]
	int v14;      // [esp+1Ch] [ebp-4h]
	int v15;      // [esp+24h] [ebp+4h]
	int v16;      // [esp+28h] [ebp+8h]
	int v17;      // [esp+28h] [ebp+8h]

	int a2 = dr;

	v2 = (uint32_t*)a2;
	v3 = a1[4];
	v4 = *(short*)(a2 + 104);
	v16 = a1[1];
	v13 = v2[4];
	v5 = v2[3];
	v12 = v4;
	v6 = v2[8];
	v7 = v16 + v13 - a1[5] - v4;
	v14 = v2[9];
	v8 = *a1 + v6 - v3;
	v9 = v5 + *a1 - v3;
	v10 = v16 + v14 - a1[5] - v12;
	if (v5 - v6 >= 0) {
		v15 = v5 - v6;
	} else {
		v15 = v6 - v5;
	}
	if (v13 - v14 >= 0) {
		v17 = v13 - v14;
	} else {
		v17 = v14 - v13;
	}
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 956));
	if (v15 <= v17) {
		nox_client_drawAddPoint_49F500(v9 + 1, v7);
		nox_client_drawAddPoint_49F500(v8 - 1, v10);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(v9 - 1, v7);
		nox_client_drawAddPoint_49F500(v8 - 1, v10);
	} else {
		nox_client_drawAddPoint_49F500(v9, v7 + 1);
		nox_client_drawAddPoint_49F500(v8, v10 + 1);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(v9, v7 + 1);
		nox_client_drawAddPoint_49F500(v8, v10 - 1);
	}
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawRectFilledOpaque_49CE30(v9 - 1, v7 - 1, 4, 4);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2523948));
	nox_client_drawAddPoint_49F500(v9, v7);
	nox_client_drawAddPoint_49F500(v8, v10);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawRectFilledOpaque_49CE30(v9, v7, 2, 2);
	return 1;
}
