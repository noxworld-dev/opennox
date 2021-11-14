#include "client__draw__summondraw.h"
#include "GAME1_2.h"
#include "GAME2.h"
#include "client__draw__animdraw.h"
#include "client__draw__fx.h"
#include "operators.h"
#include "client__drawable__drawable.h"

extern uint32_t dword_5d4594_1313740;
extern unsigned int nox_frame_xxx_2598000;

//----- (004B7D00) --------------------------------------------------------
int nox_thing_summon_effect_draw(int* a1, nox_drawable* dr) {
	uint32_t* v2;       // esi
	int v3;             // ecx
	int v4;             // edx
	int v5;             // ebx
	int v6;             // eax
	int v7;             // ecx
	int v8;             // edx
	int result;         // eax
	unsigned int v10;   // ebp
	unsigned char* v11; // edi
	unsigned int v12;   // eax
	int v13;            // ecx
	int v14;            // eax
	int v15;            // [esp+Ch] [ebp-8h]
	long long v16;      // [esp+Ch] [ebp-8h]
	int v17;            // [esp+10h] [ebp-4h]
	int v18;            // [esp+1Ch] [ebp+8h]

	uint32_t* a2 = dr;

	v2 = a2;
	v3 = a2[3];
	v4 = a2[4];
	v5 = a2[76];
	v18 = a2[77];
	v6 = dword_5d4594_1313740;
	v15 = v3;
	v17 = v4;
	if (!dword_5d4594_1313740) {
		v6 = nox_xxx_getTTByNameSpriteMB_44CFC0("BlueSpark");
		dword_5d4594_1313740 = v6;
	}
	v7 = nox_frame_xxx_2598000 - v2[79];
	v8 = *((unsigned short*)v2 + 218);
	if (v7 < (unsigned int)(unsigned short)v8) {
		if (v7 >= v8 - 1) {
			nox_xxx_makePointFxCli_499610(v6, 50, 1000, 30, v2[3], v2[4]);
		}
		nox_thing_animate_draw(a1, dr);
		v10 = 0;
		v11 = getMemAt(0x587000, 192092);
		do {
			if (v10 >= *(unsigned char*)(v5 + 8)) {
				v10 = 0;
			}
			v12 = (v10 + nox_frame_xxx_2598000 + v2[32]) / ((unsigned int)*(unsigned char*)(v5 + 9) + 1);
			v2[77] = v12;
			if (v12 >= *(unsigned char*)(v5 + 8)) {
				v2[77] = v12 % *(unsigned char*)(v5 + 8);
			}
			*(uint32_t*)(v5 + 12) = 5;
			v13 = v15 + 2 * *((uint32_t*)v11 - 1);
			v2[3] = v13;
			v14 = v17 + 2 * *(uint32_t*)v11;
			v2[4] = v14;
			if (v13 >= 0 && v13 < 5888 && v14 >= 0 && v14 < 5888) {
				nox_thing_animate_draw(a1, dr);
			}
			v11 += 80;
			++v10;
		} while ((int)v11 < (int)getMemAt(0x587000, 194140));
		v2[3] = v15;
		v2[4] = v17;
		v2[77] = v18;
		*(uint32_t*)(v5 + 12) = 2;
		nox_client_drawEnableAlpha_434560(1);
		v16 = nox_frame_xxx_2598000;
		LODWORD(v16) = v2[79];
		nox_client_drawSetAlpha_434580(
			(long long)(((double)nox_frame_xxx_2598000 - (double)v16) / (double)*((unsigned short*)v2 + 218) * 255.0));
		(*(void (**)(int*, uint32_t))(v2[108] + 300))(a1, v2[108]);
		nox_client_drawEnableAlpha_434560(0);
		result = 1;
	} else {
		nox_xxx_spriteDelete_45A4B0((uint64_t*)v2[108]);
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
		result = 0;
	}
	return result;
}
