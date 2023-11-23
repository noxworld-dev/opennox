#include "client__draw__flagdraw.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME3_1.h"
#include "client__draw__weapondraw.h"

extern uint32_t dword_8531A0_2572;

//----- (004B9500) --------------------------------------------------------
int nox_thing_flag_draw(int* a1, nox_drawable* dr) {
	int v2;             // ebx
	int v3;             // edi
	int v4;             // esi
	int v5;             // eax
	unsigned short* v6; // ebx

	int a2 = dr;

	v2 = a2;
	nox_thing_weapon_animate_draw(a1, dr);
	if (nox_common_gameFlags_check_40A5C0(128)) {
		if (*(uint32_t*)(v2 + 120) & 0x1000000) {
			v3 = *a1 + *(uint32_t*)(v2 + 12) - a1[4];
			v4 = *(uint32_t*)(v2 + 16) + a1[1] - *(short*)(v2 + 104) -
				 (unsigned long long)(long long)*(float*)(v2 + 100) - a1[5];
			v5 = sub_4B94E0(dr);
			v6 = (unsigned short*)sub_418A80(v5);
			if (v6) {
				nox_xxx_drawSetTextColor_434390(dword_8531A0_2572);
				nox_xxx_drawGetStringSize_43F840(0, v6, &a2, 0, 0);
				nox_xxx_drawString_43F6E0(0, (short*)v6, a2 / -2 + v3, v4);
			}
		}
	}
	return 1;
}
