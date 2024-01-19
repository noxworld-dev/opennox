#include "client__draw__vectdraw.h"
#include "GAME2.h"
#include "GAME3_1.h"
#include "client__draw__parse__parse.h"
#include "common__random.h"

//----- (004BC5D0) --------------------------------------------------------
int sub_4BC5D0(nox_drawable* dr, int a2) {
	uint32_t* a1 = dr;
	int result; // eax
	int v3;     // ecx
	int v4;     // ecx

	switch (*(unsigned int*)(a2 + 44)) {
	case 0:
		result = (gameFrame() - a1[79]) / (unsigned int)(*(short*)(a2 + 42) + 1);
		v4 = *(short*)(a2 + 40);
		if (result >= v4) {
			result = v4 - 1;
		}
		break;
	case 1:
		result = (gameFrame() - a1[79]) / (unsigned int)(*(short*)(a2 + 42) + 1);
		if (result >= *(short*)(a2 + 40)) {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
			result = -1;
		}
		break;
	case 2:
		result = (gameFrame() + a1[32]) / (unsigned int)(*(short*)(a2 + 42) + 1);
		v3 = *(short*)(a2 + 40);
		if (result >= v3) {
			result %= v3;
		}
		break;
	case 4:
		result = nox_common_randomIntMinMax_415FF0(0, *(short*)(a2 + 40) - 1,
												   "C:\\NoxPost\\src\\Client\\Draw\\vectdraw.c", 19);
		break;
	case 5:
		result = a1[77];
		break;
	default:
		result = 0;
		break;
	}
	return result;
}
