#include "magicdrw.h"

#include "../../proto.h"
extern _DWORD dword_5d4594_1313804;

//----- (004B98A0) --------------------------------------------------------
int __cdecl nox_thing_magic_draw(int* a1, nox_drawable* dr) {
	int v2;   // esi
	int v3;   // edi
	int v4;   // ecx
	int v5;   // eax
	int v6;   // eax
	int v7;   // edi
	float v9; // [esp+0h] [ebp-1Ch]
	int2 v10; // [esp+14h] [ebp-8h]

	int a2 = dr;

	if (!dword_5d4594_1313804) {
		*getMemU32Ptr(0x5D4594, 1313808) = nox_color_rgb_4344A0(0, 200, 255);
		*getMemU32Ptr(0x5D4594, 1313812) = nox_color_rgb_4344A0(255, 255, 50);
		dword_5d4594_1313804 = 1;
	}
	v2 = *a1;
	v3 = a1[1];
	v4 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
	v5 = *(_DWORD*)(a2 + 16) - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
	v10.field_0 = v4;
	v6 = v3 + v5;
	v10.field_4 = v6;
	if (v4 - 10 >= v2 && v6 - 10 >= v3 && v4 + 10 < a1[2] && v6 + 10 < a1[3]) {
		v7 = sub_415FF0(1, 4, "C:\\NoxPost\\src\\Client\\Draw\\magicdrw.c", 48);
		sub_4B6720(&v10, *getMemIntPtr(0x5D4594, 1313808), 2 * v7 + 1, (v7 >> 1) + 3);
		nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2523948));
		nox_client_drawRectFilledOpaque_49CE30(v10.field_0 - (v7 >> 1), v10.field_4 - (v7 >> 1), v7, v7);
		sub_484BE0((_DWORD*)(a2 + 136), 200, 200, 255);
		v9 = sub_416090(0.0, 100.0);
		sub_484D70_light_intensity(a2 + 136, v9);
	}
	return 1;
}

//----- (004B99F0) --------------------------------------------------------
int __cdecl nox_thing_magic_missle_draw(int* a1, nox_drawable* dr) {
	int v2;   // esi
	int v3;   // edi
	int v4;   // ecx
	int v5;   // eax
	int v6;   // eax
	int v7;   // edi
	float v9; // [esp+0h] [ebp-1Ch]
	int2 v10; // [esp+14h] [ebp-8h]

	int a2 = dr;

	if (!dword_5d4594_1313804) {
		*getMemU32Ptr(0x5D4594, 1313808) = nox_color_rgb_4344A0(0, 200, 255);
		*getMemU32Ptr(0x5D4594, 1313812) = nox_color_rgb_4344A0(255, 255, 50);
		dword_5d4594_1313804 = 1;
	}
	v2 = *a1;
	v3 = a1[1];
	v4 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
	v5 = *(_DWORD*)(a2 + 16) - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
	v10.field_0 = v4;
	v6 = v3 + v5;
	v10.field_4 = v6;
	if (v4 - 10 >= v2 && v6 - 10 >= v3 && v4 + 10 < a1[2] && v6 + 10 < a1[3]) {
		v7 = sub_415FF0(1, 4, "C:\\NoxPost\\src\\Client\\Draw\\magicdrw.c", 91);
		sub_4B6720(&v10, *getMemIntPtr(0x5D4594, 1313812), 2 * v7 + 1, (v7 >> 1) + 3);
		nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2523948));
		nox_client_drawRectFilledOpaque_49CE30(v10.field_0 - (v7 >> 1), v10.field_4 - (v7 >> 1), v7, v7);
		sub_484BE0((_DWORD*)(a2 + 136), 255, 180, 50);
		v9 = sub_416090(0.0, 100.0);
		sub_484D70_light_intensity(a2 + 136, v9);
	}
	return 1;
}

//----- (004B5F30) --------------------------------------------------------
int __cdecl nox_thing_magic_missle_tail_link_draw(_DWORD* a1, nox_drawable* dr) {
	int v2;         // ecx
	int v3;         // edi
	int v4;         // esi
	int v5;         // ebx
	int v6;         // eax
	int v7;         // ebp
	int v8;         // ebx
	float v10;      // [esp+0h] [ebp-1Ch]
	int v11;        // [esp+14h] [ebp-8h]
	int v12;        // [esp+18h] [ebp-4h]
	signed int v13; // [esp+20h] [ebp+4h]
	int v14;        // [esp+24h] [ebp+8h]

	int a2 = dr;

	v2 = a2;
	v3 = *(_DWORD*)(a2 + 12) + *a1 - a1[4];
	v4 = *(_DWORD*)(a2 + 16) + a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
	v12 = a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5] + *(_DWORD*)(a2 + 436);
	v5 = *(_DWORD*)(a2 + 356) - *getMemU32Ptr(0x5D4594, 2598000);
	v11 = *a1 - a1[4] + *(_DWORD*)(a2 + 432);
	v14 = v5;
	if (v5 > 0) {
		v6 = (v5 << 6) / (int)(*getMemU32Ptr(0x5D4594, 2649704) / 3u);
		v13 = *getMemU32Ptr(0x5D4594, 2649704) / 3u;
		if (v6 >= 64)
			v6 = 63;
		v7 = *getMemU32Ptr(0x5D4594, 4 * v6 + 1312756);
		v8 = v2 + 136;
		sub_484BE0((_DWORD*)(v2 + 136), 255, 128, 50);
		v10 = (double)v14 * 20.0 / (double)v13;
		sub_484D70_light_intensity(v8, v10);
		nox_client_drawSetColor_434460(v7);
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x80u);
		nox_client_drawAddPoint_49F500(v3, v4);
		nox_client_drawAddPoint_49F500(v11, v12);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawEnableAlpha_434560(0);
	}
	return 1;
}

//----- (004B5E10) --------------------------------------------------------
int __cdecl nox_thing_magic_tail_link_draw(_DWORD* a1, nox_drawable* dr) {
	int v2;          // ecx
	int v3;          // edi
	int v4;          // esi
	int v5;          // eax
	bool v6;         // zf
	int v7;          // eax
	unsigned int v8; // ett
	int v9;          // ebp
	int v10;         // ebx
	float v12;       // [esp+0h] [ebp-24h]
	int v13;         // [esp+14h] [ebp-10h]
	int v14;         // [esp+18h] [ebp-Ch]
	int v15;         // [esp+2Ch] [ebp+8h]

	int a2 = dr;

	v2 = a2;
	v3 = *(_DWORD*)(a2 + 12) + *a1 - a1[4];
	v4 = *(_DWORD*)(a2 + 16) + a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
	v13 = *a1 - a1[4] + *(_DWORD*)(a2 + 432);
	v5 = *(_DWORD*)(a2 + 356) - *getMemU32Ptr(0x5D4594, 2598000);
	v6 = *(_DWORD*)(a2 + 356) == *getMemU32Ptr(0x5D4594, 2598000);
	v14 = a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5] + *(_DWORD*)(a2 + 436);
	v15 = v5;
	if (v5 >= 0 && !v6) {
		v8 = v5 << 6;
		v7 = (unsigned int)(v5 << 6) / *getMemU32Ptr(0x5D4594, 2649704);
		if ((int)(v8 / *getMemU32Ptr(0x5D4594, 2649704)) >= 64)
			v7 = 63;
		v9 = *getMemU32Ptr(0x5D4594, 4 * v7 + 1312500);
		v10 = v2 + 136;
		sub_484BE0((_DWORD*)(v2 + 136), 128, 128, 255);
		v12 = (double)v15 * 20.0 / (double)*getMemIntPtr(0x5D4594, 2649704);
		sub_484D70_light_intensity(v10, v12);
		nox_client_drawSetColor_434460(v9);
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x80u);
		nox_client_drawAddPoint_49F500(v3, v4);
		nox_client_drawAddPoint_49F500(v13, v14);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawEnableAlpha_434560(0);
	}
	return 1;
}

//----- (004B9B40) --------------------------------------------------------
int nox_thing_drain_mana_draw() { return 1; }
