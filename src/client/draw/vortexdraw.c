#include "vortexdraw.h"
#include "../../proto.h"

extern _DWORD dword_5d4594_1313816;

//----- (004B9F50) --------------------------------------------------------
int __cdecl nox_thing_vortex_draw(int* a1, int a2) {
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

	if (!*(_DWORD*)&byte_5D4594[1313820]) {
		dword_5d4594_1313816 = sub_4344A0(170, 170, 170);
		*(_DWORD*)&byte_5D4594[1313820] = 1;
	}
	v2 = 8 * *(unsigned __int8*)(a2 + 448);
	v3 = *(unsigned __int8*)(a2 + 450);
	a2a.field_0 = *(_DWORD*)(a2 + 440) + v3 * *(int*)&byte_587000[v2 + 192088] / 16;
	a2a.field_4 = *(_DWORD*)(a2 + 444) + v3 * *(int*)&byte_587000[v2 + 192092] / 16;
	sub_4739E0(a1, &a2a, &xLeft);
	v4 = xLeft.field_4 - *(__int16*)(a2 + 104);
	v5 = xLeft.field_0 <= *a1;
	xLeft.field_4 -= *(__int16*)(a2 + 104);
	if (v5 || xLeft.field_0 >= a1[2] || v4 <= a1[1] || v4 >= a1[3])
		goto LABEL_22;
	if (a2a.field_4 >= *(int*)(a2 + 444)) {
		sub_4B6720(&xLeft, *(_DWORD*)(a2 + 432), 3, 5);
		nox_client_drawSetColor_434460(*(_DWORD*)(a2 + 436));
		sub_499B70(xLeft.field_0, xLeft.field_4, 3);
	} else {
		sub_4B6720(&xLeft, *(int*)&dword_5d4594_1313816, 2, 4);
		nox_client_drawSetColor_434460(*(int*)&dword_5d4594_1313816);
		sub_499B70(xLeft.field_0, xLeft.field_4, 2);
	}
	nox_client_drawAddPoint_49F500(xLeft.field_0, xLeft.field_4);
	v6 = *(_BYTE*)(a2 + 449);
	v7 = *(unsigned __int8*)(a2 + 448) - 2 * v6;
	if (v6 > 0) {
		v7 += v7 < 0 ? 0x100 : 0;
	} else if (v7 >= 256) {
		v7 -= 256;
	}
	v8 = *(unsigned __int8*)(a2 + 450);
	a2a.field_0 = *(_DWORD*)(a2 + 440) + v8 * *(_DWORD*)&byte_587000[8 * v7 + 192088] / 16;
	a2a.field_4 = *(_DWORD*)(a2 + 444) + v8 * *(_DWORD*)&byte_587000[8 * v7 + 192092] / 16;
	sub_4739E0(a1, &a2a, &xLeft);
	xLeft.field_4 -= *(__int16*)(a2 + 104);
	nox_client_drawAddPoint_49F500(xLeft.field_0, xLeft.field_4);
	if (a2a.field_4 >= *(int*)(a2 + 444))
		nox_client_drawSetColor_434460(*(_DWORD*)(a2 + 436));
	else
		nox_client_drawSetColor_434460(*(int*)&dword_5d4594_1313816);
	nox_client_drawLineFromPoints_49E4B0();
	*(_BYTE*)(a2 + 448) += *(_BYTE*)(a2 + 449);
	*(_WORD*)(a2 + 104) += *(unsigned __int8*)(a2 + 451);
	sub_4739E0(a1, (int2*)(a2 + 12), &a3);
	v11 = (double)*(__int16*)(a2 + 104) * 0.0024999999 * 50.0;
	v9 = nox_float2int(v11);
	if (50 - v9 <= 0) {
		LABEL_22:
		sub_45A4E0_drawable(a2);
		result = 0;
	} else {
		*(_BYTE*)(a2 + 450) = 50 - v9;
		result = 1;
	}
	return result;
}
