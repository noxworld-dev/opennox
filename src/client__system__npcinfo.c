#include "client__system__npcinfo.h"

#include "common__random.h"
#include "GAME4.h"

//----- (0049A4B0) --------------------------------------------------------
int  nox_xxx_spriteNPCInfo_49A4B0(uint32_t* a1, int a2, int a3) {
	int result; // eax
	int v4;     // ecx

	result = a1[108];
	v4 = a1[69] - 1;
	a1[108] = 0;
	switch (v4) {
	case 0:
	case 1:
	case 2:
	case 3:
		if (!(a2 & 0xFFFFFFFC)) {
			if (!result || !a1[77])
				result = nox_common_randomIntMinMax_415FF0(23, 24, "C:\\NoxPost\\src\\client\\System\\NPCInfo.c", 286);
			goto LABEL_12;
		}
		result = sub_4FA280(a2 & 0xFFFFFFFC);
		break;
	case 4:
	case 5:
		if (a2 & 0x400) {
			if (result && a1[77]) {
			LABEL_12:
				a1[108] = result;
			} else {
				result = nox_common_randomIntMinMax_415FF0(47, 49, "C:\\NoxPost\\src\\client\\System\\NPCInfo.c", 314);
				a1[108] = result;
			}
		} else if (a2 & 0x7FF8000) {
			result = 30;
		} else {
			if (!(a3 & 0x3000000))
				goto LABEL_22;
			result = 40;
		}
		break;
	case 6:
		result = 21;
		break;
	case 7:
	LABEL_22:
		result = (a2 & 0x400) != 0 ? 0x26 : 0;
		break;
	case 8:
		result = 1;
		break;
	case 9:
		result = 2;
		break;
	case 11:
		result = 4;
		break;
	case 12:
		result = 6;
		break;
	case 13:
		result = 50;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}
