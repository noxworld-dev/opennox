#include "client__draw__mgendraw.h"
#include "GAME3_1.h"
#include "common__random.h"
#include "operators.h"

//----- (004BC750) --------------------------------------------------------
int nox_thing_monster_gen_draw(int* a1, nox_drawable* dr) {
	int v2;             // esi
	int v3;             // eax
	int v4;             // edi
	int v5;             // eax
	int v6;             // ebx
	int v7;             // eax
	int v8;             // ecx
	unsigned int v9;    // ecx
	int v10;            // ebp
	int v11;            // ebp
	int v12;            // ecx
	int v13;            // eax
	signed int v14;     // ecx
	signed int v15;     // eax
	int v16;            // eax
	int v17;            // eax
	int result;         // eax
	unsigned char* v19; // [esp+10h] [ebp-8h]
	int v20;            // [esp+14h] [ebp-4h]
	unsigned char* v21; // [esp+20h] [ebp+8h]

	v2 = dr;
	v3 = dr->flags70;
	v4 = *(unsigned int*)&dr->field_76;
	if (v3 & 0x100) {
		v5 = 1;
	} else if (v3 & 0x200) {
		v5 = 2;
	} else {
		v5 = (dr->flags70 & 0xC00) != 0 ? 3 : 0;
	}
	v6 = *(unsigned char*)(v5 + v4 + 24);
	v19 = (unsigned char*)(v5 + v4 + 24);
	v21 = (unsigned char*)(v5 + v4 + 29);
	v20 = *(unsigned int*)(v4 + 4 * v5 + 4);
	switch (*(unsigned int*)(v4 + 4 * v5 + 36)) {
	case 0:
		v7 = v5 + v4 + 29;
		break;
	case 2:
		v7 = (gameFrame() + *(unsigned int*)(v2 + 128)) / ((unsigned int)*(unsigned char*)(v5 + v4 + 29) + 1);
		if (v7 >= v6) {
			v7 %= v6;
		}
		break;
	case 4:
		v7 = nox_common_randomIntMinMax_415FF0(0, v6, "C:\\NoxPost\\src\\client\\Draw\\MGenDraw.c", 86);
		break;
	case 5:
		v7 = *(unsigned int*)(v2 + 308);
		break;
	default:
		return 0;
	}
	v8 = *(unsigned int*)(v2 + 280);
	if (v8 & 0x800) {
		v9 = *(unsigned int*)(v2 + 120) & 0xDFFFFFFF;
		v7 = v6 - 1;
		*(unsigned int*)(v2 + 112) &= 0xFFF7FFFF;
		*(unsigned int*)(v2 + 120) = v9;
	}
	v10 = *(unsigned int*)(v2 + 432);
	if (v10) {
		v7 = ((*v21 + 1) * (unsigned int)*v19 - v10) / ((unsigned int)*v21 + 1);
		if (v7 >= v6) {
			v7 = v6 - 1;
		}
		if (v7 < 0) {
			v7 = 0;
		}
		v11 = v10 - 1;
		*(unsigned int*)(v2 + 432) = v11;
		if (!v11) {
			v12 = *(unsigned int*)(v2 + 280);
			BYTE1(v12) = BYTE1(v12) & 0xFB | 8;
			*(unsigned int*)(v2 + 280) = v12;
		}
	}
	nox_xxx_drawObject_4C4770_draw(a1, (unsigned char*)v2, *(unsigned int*)(v20 + 4 * v7));
	v13 = *(unsigned int*)(v2 + 280);
	if (!(v13 & 0xC00)) {
		v14 = *(unsigned char*)(v4 + 28);
		v15 = (gameFrame() + *(unsigned int*)(v2 + 128)) / ((unsigned int)*(unsigned char*)(v4 + 33) + 1);
		if (v15 >= v14) {
			v15 %= v14;
		}
		nox_xxx_drawObject_4C4770_draw(a1, (unsigned char*)v2,
									   *(unsigned int*)(*(unsigned int*)(v4 + 20) + 4 * v15));
	}
	v16 = *(unsigned int*)(v2 + 280);
	if (v16 & 0x800) {
		v17 = *(unsigned int*)(v2 + 120);
		LOBYTE(v17) = v17 | 1;
		*(unsigned int*)(v2 + 120) = v17;
	}
	return 1;
}
