#include "client__draw__glyphdraw.h"
#include "GAME1.h"
#include "GAME1_2.h"
#include "client__draw__animdraw.h"
#include "client__video__draw_common.h"
#include "operators.h"

extern uint32_t dword_8531A0_2572;

//----- (004B9C70) --------------------------------------------------------
int nox_thing_glyph_draw(int* a1, nox_drawable* dr) {
	char v3; // cl
	int v4;  // ecx
	int v5;  // eax
	int v6;  // eax
	int v7;  // esi

	uint32_t* a2 = dr;

	if (!nox_common_gameFlags_check_40A5C0(2) || !*getMemU32Ptr(0x852978, 8)) {
		goto LABEL_10;
	}
	if (a2[30] & 0x40000000) {
		LOBYTE(a2) = -1;
		goto LABEL_10;
	}
	if (nox_client_drawable_testBuff_4356C0(*getMemIntPtr(0x852978, 8), 21)) {
		nox_xxx_draw_434600(1);
		nox_draw_setColorMultAndIntensity_433E40(dword_8531A0_2572);
		v3 = -1;
		LOBYTE(a2) = v3;
		goto LABEL_10;
	}
	v4 = a2[3] - *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 12);
	v5 = a2[4] - *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 16);
	v6 = v4 * v4 + v5 * v5;
	if (v6 >= 22500) {
		return 1;
	}
	v3 = -56 - 200 * v6 / 22500;
	LOBYTE(a2) = v3;
LABEL_10:
	nox_client_drawEnableAlpha_434560(1);
	nox_client_drawSetAlpha_434580((unsigned char)a2);
	v7 = nox_thing_animate_draw(a1, dr);
	nox_client_drawEnableAlpha_434560(0);
	nox_xxx_draw_434600(0);
	return v7;
}
