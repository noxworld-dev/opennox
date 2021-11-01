#include "client__draw__arrowdraw.h"
#include "client__draw__slavedraw.h"
#include "GAME1_2.h"
#include "GAME2.h"
#include "GAME2_3.h"

extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;
//----- (004B7920) --------------------------------------------------------
int  nox_thing_arrow_draw(int* a1, nox_drawable* dr) {
	int v2;     // eax
	int v3;     // edi
	uint32_t* v4; // edi
	int v5;     // eax

	uint32_t* a2 = dr;

	v2 = *getMemU32Ptr(0x5D4594, 1313720);
	if (!*getMemU32Ptr(0x5D4594, 1313720)) {
		v2 = nox_xxx_getTTByNameSpriteMB_44CFC0("ArrowTailLink");
		*getMemU32Ptr(0x5D4594, 1313720) = v2;
	}
	v3 = a2[81];
	if ((a2[3] - v3) * (a2[3] - v3) + (a2[4] - a2[82]) * (a2[4] - a2[82]) > 200) {
		v4 = (uint32_t*)nox_xxx_spriteLoadAdd_45A360_drawable(v2, v3, a2[82]);
		v4[108] = a2[3];
		v4[109] = a2[4];
		nox_xxx_sprite_45A110_drawable(v4);
		v5 = a2[4];
		a2[81] = a2[3];
		a2[82] = v5;
		nox_xxx_spriteTransparentDecay_49B950(v4, nox_gameFPS / 3u);
	}
	return nox_thing_slave_draw(a1, dr);
}

//----- (004B79D0) --------------------------------------------------------
int  nox_thing_weak_arrow_draw(int* a1, nox_drawable* dr) {
	int v2;     // eax
	int v3;     // edi
	uint32_t* v4; // edi
	int v5;     // eax

	uint32_t* a2 = dr;

	v2 = *getMemU32Ptr(0x5D4594, 1313724);
	if (!*getMemU32Ptr(0x5D4594, 1313724)) {
		v2 = nox_xxx_getTTByNameSpriteMB_44CFC0("WeakArrowTailLink");
		*getMemU32Ptr(0x5D4594, 1313724) = v2;
	}
	v3 = a2[81];
	if ((a2[3] - v3) * (a2[3] - v3) + (a2[4] - a2[82]) * (a2[4] - a2[82]) > 200) {
		v4 = (uint32_t*)nox_xxx_spriteLoadAdd_45A360_drawable(v2, v3, a2[82]);
		v4[108] = a2[3];
		v4[109] = a2[4];
		nox_xxx_sprite_45A110_drawable(v4);
		v5 = a2[4];
		a2[81] = a2[3];
		a2[82] = v5;
		nox_xxx_spriteTransparentDecay_49B950(v4, nox_gameFPS / 3u);
	}
	return nox_thing_slave_draw(a1, dr);
}

//----- (004B6050) --------------------------------------------------------
int  nox_thing_arrow_tail_link_draw(uint32_t* a1, nox_drawable* dr) {
	int v2; // ebp
	int v3; // edi
	int v4; // esi
	int v5; // ebx
	int v6; // ebp
	int v7; // eax

	int a2 = dr;

	v2 = *(uint32_t*)(a2 + 16);
	v3 = *(uint32_t*)(a2 + 12) + *a1 - a1[4];
	v4 = v2 + a1[1] - *(short*)(a2 + 106) - *(short*)(a2 + 104) - a1[5];
	v5 = *(uint32_t*)(a2 + 436) - v2;
	v6 = *(uint32_t*)(a2 + 432) + *a1 - a1[4];
	if (*(uint32_t*)(a2 + 356) - nox_frame_xxx_2598000 > 0) {
		v7 = ((*(uint32_t*)(a2 + 356) - nox_frame_xxx_2598000) << 6) /
		     (int)(nox_gameFPS / 3u);
		if (v7 >= 64)
			v7 = 63;
		nox_client_drawSetColor_434460(*getMemU32Ptr(0x5D4594, 1313012 + 4 * v7));
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
int  nox_thing_weak_arrow_tail_link_draw(uint32_t* a1, nox_drawable* dr) {
	int v2; // ebp
	int v3; // edi
	int v4; // esi
	int v5; // ebx
	int v6; // ebp
	int v7; // eax

	int a2 = dr;

	v2 = *(uint32_t*)(a2 + 16);
	v3 = *(uint32_t*)(a2 + 12) + *a1 - a1[4];
	v4 = v2 + a1[1] - *(short*)(a2 + 106) - *(short*)(a2 + 104) - a1[5];
	v5 = *(uint32_t*)(a2 + 436) - v2;
	v6 = *(uint32_t*)(a2 + 432) + *a1 - a1[4];
	if (*(uint32_t*)(a2 + 356) - nox_frame_xxx_2598000 > 0) {
		v7 = ((*(uint32_t*)(a2 + 356) - nox_frame_xxx_2598000) << 6) /
		     (int)(nox_gameFPS / 3u);
		if (v7 >= 64)
			v7 = 63;
		nox_client_drawSetColor_434460(*getMemU32Ptr(0x5D4594, 1313268 + 4 * v7));
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x80u);
		nox_client_drawAddPoint_49F500(v3, v4 - 4);
		nox_client_drawAddPoint_49F500(v6, v5 + v4 - 4);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawEnableAlpha_434560(0);
	}
	return 1;
}
