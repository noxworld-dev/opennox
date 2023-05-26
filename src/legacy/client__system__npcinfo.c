#include "client__system__npcinfo.h"

#include "GAME4.h"
#include "common__random.h"

//----- (0049A4B0) --------------------------------------------------------
int nox_xxx_spriteNPCInfo_49A4B0(uint32_t* a1, int a2, int a3) {
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
			if (!result || !a1[77]) {
				result = nox_common_randomIntMinMax_415FF0(23, 24, "C:\\NoxPost\\src\\client\\System\\NPCInfo.c", 286);
			}
			a1[108] = result;
			return result;
		}
		return sub_4FA280(a2 & 0xFFFFFFFC);
	case 4:
	case 5:
		if (a2 & 0x400) {
			if (result && a1[77]) {
				a1[108] = result;
			} else {
				result = nox_common_randomIntMinMax_415FF0(47, 49, "C:\\NoxPost\\src\\client\\System\\NPCInfo.c", 314);
				a1[108] = result;
			}
			return result;
		} else if (a2 & 0x7FF8000) {
			return 30;
		} else {
			if (!(a3 & 0x3000000)) {
				return (a2 & 0x400) != 0 ? 0x26 : 0;
			}
			return 40;
		}
	case 6:
		return 21;
	case 7:
		return (a2 & 0x400) != 0 ? 0x26 : 0;
	case 8:
		return 1;
	case 9:
		return 2;
	case 11:
		return 4;
	case 12:
		return 6;
	case 13:
		return 50;
	default:
		return 0;
	}
}
