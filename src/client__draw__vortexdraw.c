#include "client__draw__vortexdraw.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "client__gui__window.h"
#include "client__video__draw_common.h"

extern uint32_t dword_5d4594_1313816;

//----- (004B9F50) --------------------------------------------------------
int  nox_thing_vortex_draw(int* a1, nox_drawable* dr) {
	int v2;     // ecx
	int v3;     // edi
	int v4;     // eax
	bool v5;    // cc
	char v6;    // al
	int v7;     // ecx
	int v8;     // edi
	int v9;     // eax
	int result; // eax
	float v11;  // [esp+0h] [ebp-28h]
	int2 xLeft; // [esp+10h] [ebp-18h]
	int2 a2a;   // [esp+18h] [ebp-10h]
	int2 a3;    // [esp+20h] [ebp-8h]

	int a2 = dr;

	if (!*getMemU32Ptr(0x5D4594, 1313820)) {
		dword_5d4594_1313816 = nox_color_rgb_4344A0(170, 170, 170);
		*getMemU32Ptr(0x5D4594, 1313820) = 1;
	}
	v2 = 8 * *(unsigned char*)(a2 + 448);
	v3 = *(unsigned char*)(a2 + 450);
	a2a.field_0 = *(uint32_t*)(a2 + 440) + v3 * *getMemIntPtr(0x587000, 192088 + v2) / 16;
	a2a.field_4 = *(uint32_t*)(a2 + 444) + v3 * *getMemIntPtr(0x587000, 192092 + v2) / 16;
	sub_4739E0(a1, &a2a, &xLeft);
	v4 = xLeft.field_4 - *(short*)(a2 + 104);
	v5 = xLeft.field_0 <= *a1;
	xLeft.field_4 -= *(short*)(a2 + 104);
	if (v5 || xLeft.field_0 >= a1[2] || v4 <= a1[1] || v4 >= a1[3]) {
		goto LABEL_22;
}
	if (a2a.field_4 >= *(int*)(a2 + 444)) {
		sub_4B6720(&xLeft, *(uint32_t*)(a2 + 432), 3, 5);
		nox_client_drawSetColor_434460(*(uint32_t*)(a2 + 436));
		nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, 3);
	} else {
		sub_4B6720(&xLeft, *(int*)&dword_5d4594_1313816, 2, 4);
		nox_client_drawSetColor_434460(*(int*)&dword_5d4594_1313816);
		nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, 2);
	}
	nox_client_drawAddPoint_49F500(xLeft.field_0, xLeft.field_4);
	v6 = *(uint8_t*)(a2 + 449);
	v7 = *(unsigned char*)(a2 + 448) - 2 * v6;
	if (v6 > 0) {
		v7 += v7 < 0 ? 0x100 : 0;
	} else if (v7 >= 256) {
		v7 -= 256;
	}
	v8 = *(unsigned char*)(a2 + 450);
	a2a.field_0 = *(uint32_t*)(a2 + 440) + v8 * *getMemU32Ptr(0x587000, 192088 + 8 * v7) / 16;
	a2a.field_4 = *(uint32_t*)(a2 + 444) + v8 * *getMemU32Ptr(0x587000, 192092 + 8 * v7) / 16;
	sub_4739E0(a1, &a2a, &xLeft);
	xLeft.field_4 -= *(short*)(a2 + 104);
	nox_client_drawAddPoint_49F500(xLeft.field_0, xLeft.field_4);
	if (a2a.field_4 >= *(int*)(a2 + 444)) {
		nox_client_drawSetColor_434460(*(uint32_t*)(a2 + 436));
	} else {
		nox_client_drawSetColor_434460(*(int*)&dword_5d4594_1313816);
}
	nox_client_drawLineFromPoints_49E4B0();
	*(uint8_t*)(a2 + 448) += *(uint8_t*)(a2 + 449);
	*(uint16_t*)(a2 + 104) += *(unsigned char*)(a2 + 451);
	sub_4739E0(a1, (int2*)(a2 + 12), &a3);
	v11 = (double)*(short*)(a2 + 104) * 0.0024999999 * 50.0;
	v9 = nox_float2int(v11);
	if (50 - v9 <= 0) {
		LABEL_22:
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
		result = 0;
	} else {
		*(uint8_t*)(a2 + 450) = 50 - v9;
		result = 1;
	}
	return result;
}
