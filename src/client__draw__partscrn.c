#include "client__draw__partscrn.h"
#include "common__random.h"

#include "GAME1_2.h"
#include "GAME2_3.h"
#include "GAME3.h"

//----- (00489700) --------------------------------------------------------
int nox_client_screenParticleDraw_489700(void* a1p, nox_screenParticle* p) {
	int a1 = a1p;
	int v7;     // eax
	int v10;    // [esp-20h] [ebp-30h]
	char v11;   // [esp-10h] [ebp-20h]
	char v12;   // [esp-Ch] [ebp-1Ch]
	int2 xLeft; // [esp+8h] [ebp-8h]

	xLeft.field_0 = p->field_24 >> 16;
	xLeft.field_4 = p->field_28 >> 16;
	if (xLeft.field_0 <= 0 || xLeft.field_4 <= 0 || xLeft.field_0 >= *(int*)(a1 + 32) ||
		xLeft.field_4 >= *(int*)(a1 + 36)) {
		sub_431700(p);
		return 0;
	}
	sub_4B6720(&xLeft, p->field_8, p->field_40[0], p->field_40[0]);
	nox_client_drawSetColor_434460(p->field_12);
	nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, p->field_40[0] >> 1);
	char v3 = p->field_40[1];
	p->field_20 += p->field_36;
	if (v3) {
		char v4 = v3 - 1;
		p->field_40[1] = v4;
		if (!v4) {
			if (p->field_40[2] == 1) {
				uint8_t v5 = p->field_40[0] + 1;
				p->field_40[0] = v5;
				if (v5 >= 4u) {
					p->field_40[2] = 2;
				}
			} else {
				char v6 = p->field_40[0] - 1;
				p->field_40[0] = v6;
				if (!v6) {
					sub_431700(p);
					return 0;
				}
			}
			p->field_40[1] = p->field_40[3];
		}
	}
	if (*(uint8_t*)(&p->field_32) == 1 &&
		nox_common_randomIntMinMax_415FF0(0, 10, "C:\\NoxPost\\src\\client\\Draw\\PartScrn.c", 105) >= 8) {
		v12 = nox_common_randomIntMinMax_415FF0(3, 5, "C:\\NoxPost\\src\\client\\Draw\\PartScrn.c", 115);
		v11 = nox_common_randomIntMinMax_415FF0(2, 3, "C:\\NoxPost\\src\\client\\Draw\\PartScrn.c", 114);
		v10 = xLeft.field_4;
		v7 = nox_common_randomIntMinMax_415FF0(-2, 2, "C:\\NoxPost\\src\\client\\Draw\\PartScrn.c", 109);
		nox_client_newScreenParticle_431540(p->field_4, xLeft.field_0 + v7, v10, 0, 0, 1, v11, v12, 2, 2);
	}
	p->field_24 += p->field_16;
	p->field_28 += p->field_20;
	return 1;
}
