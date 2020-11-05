#include "arrowdraw.h"
#include "slavedraw.h"
#include "../../proto.h"

//----- (004B7920) --------------------------------------------------------
int __cdecl nox_thing_arrow_draw(int* a1, nox_drawable* dr) {
	int v2;     // eax
	int v3;     // edi
	_DWORD* v4; // edi
	int v5;     // eax

	_DWORD* a2 = dr;

	v2 = *getMemU32Ptr(0x5D4594, 1313720);
	if (!*getMemU32Ptr(0x5D4594, 1313720)) {
		v2 = nox_xxx_getTTByNameSpriteMB_44CFC0((CHAR*)getMemAt(0x587000, 176776));
		*getMemU32Ptr(0x5D4594, 1313720) = v2;
	}
	v3 = a2[81];
	if ((a2[3] - v3) * (a2[3] - v3) + (a2[4] - a2[82]) * (a2[4] - a2[82]) > 200) {
		v4 = (_DWORD*)nox_xxx_spriteLoadAdd_45A360_drawable(v2, v3, a2[82]);
		v4[108] = a2[3];
		v4[109] = a2[4];
		nox_xxx_sprite_45A110_drawable(v4);
		v5 = a2[4];
		a2[81] = a2[3];
		a2[82] = v5;
		nox_xxx_spriteTransparentDecay_49B950(v4, *getMemU32Ptr(0x5D4594, 2649704) / 3u);
	}
	return nox_thing_slave_draw(a1, dr);
}

//----- (004B79D0) --------------------------------------------------------
int __cdecl nox_thing_weak_arrow_draw(int* a1, nox_drawable* dr) {
	int v2;     // eax
	int v3;     // edi
	_DWORD* v4; // edi
	int v5;     // eax

	_DWORD* a2 = dr;

	v2 = *getMemU32Ptr(0x5D4594, 1313724);
	if (!*getMemU32Ptr(0x5D4594, 1313724)) {
		v2 = nox_xxx_getTTByNameSpriteMB_44CFC0((CHAR*)getMemAt(0x587000, 176792));
		*getMemU32Ptr(0x5D4594, 1313724) = v2;
	}
	v3 = a2[81];
	if ((a2[3] - v3) * (a2[3] - v3) + (a2[4] - a2[82]) * (a2[4] - a2[82]) > 200) {
		v4 = (_DWORD*)nox_xxx_spriteLoadAdd_45A360_drawable(v2, v3, a2[82]);
		v4[108] = a2[3];
		v4[109] = a2[4];
		nox_xxx_sprite_45A110_drawable(v4);
		v5 = a2[4];
		a2[81] = a2[3];
		a2[82] = v5;
		nox_xxx_spriteTransparentDecay_49B950(v4, *getMemU32Ptr(0x5D4594, 2649704) / 3u);
	}
	return nox_thing_slave_draw(a1, dr);
}

//----- (004B6050) --------------------------------------------------------
int __cdecl nox_thing_arrow_tail_link_draw(_DWORD* a1, nox_drawable* dr) {
	int v2; // ebp
	int v3; // edi
	int v4; // esi
	int v5; // ebx
	int v6; // ebp
	int v7; // eax

	int a2 = dr;

	v2 = *(_DWORD*)(a2 + 16);
	v3 = *(_DWORD*)(a2 + 12) + *a1 - a1[4];
	v4 = v2 + a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
	v5 = *(_DWORD*)(a2 + 436) - v2;
	v6 = *(_DWORD*)(a2 + 432) + *a1 - a1[4];
	if (*(_DWORD*)(a2 + 356) - *getMemU32Ptr(0x5D4594, 2598000) > 0) {
		v7 = ((*(_DWORD*)(a2 + 356) - *getMemU32Ptr(0x5D4594, 2598000)) << 6) /
		     (int)(*getMemU32Ptr(0x5D4594, 2649704) / 3u);
		if (v7 >= 64)
			v7 = 63;
		nox_client_drawSetColor_434460(*getMemU32Ptr(0x5D4594, 4 * v7 + 1313012));
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x80u);
		nox_client_drawAddPoint_49F500(v3, v4 - 4);
		nox_client_drawAddPoint_49F500(v6, v5 + v4 - 4);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawEnableAlpha_434560(0);
	}
	return 1;
}

//----- (004B6120) --------------------------------------------------------
int __cdecl nox_thing_weak_arrow_tail_link_draw(_DWORD* a1, nox_drawable* dr) {
	int v2; // ebp
	int v3; // edi
	int v4; // esi
	int v5; // ebx
	int v6; // ebp
	int v7; // eax

	int a2 = dr;

	v2 = *(_DWORD*)(a2 + 16);
	v3 = *(_DWORD*)(a2 + 12) + *a1 - a1[4];
	v4 = v2 + a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
	v5 = *(_DWORD*)(a2 + 436) - v2;
	v6 = *(_DWORD*)(a2 + 432) + *a1 - a1[4];
	if (*(_DWORD*)(a2 + 356) - *getMemU32Ptr(0x5D4594, 2598000) > 0) {
		v7 = ((*(_DWORD*)(a2 + 356) - *getMemU32Ptr(0x5D4594, 2598000)) << 6) /
		     (int)(*getMemU32Ptr(0x5D4594, 2649704) / 3u);
		if (v7 >= 64)
			v7 = 63;
		nox_client_drawSetColor_434460(*getMemU32Ptr(0x5D4594, 4 * v7 + 1313268));
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x80u);
		nox_client_drawAddPoint_49F500(v3, v4 - 4);
		nox_client_drawAddPoint_49F500(v6, v5 + v4 - 4);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawEnableAlpha_434560(0);
	}
	return 1;
}
