#include "client__audio__audevent.h"
#include "common__random.h"

#include "GAME2.h"
#include "GAME2_2.h"
#include "GAME3_1.h"

//----- (00451CF0) --------------------------------------------------------
int  sub_451CF0(uint32_t* a1) {
	int v1;     // ecx
	int result; // eax
	int v3;     // edx
	int v4;     // edi
	int v5;     // eax
	int v6;     // edi
	int v7;     // ecx
	uint32_t* v8; // eax
	int v9;     // eax

	v1 = a1[9];
	result = a1[108];
	v3 = *(uint32_t*)(v1 + 4);
	if (result) {
		if (v3 & 2) {
			v5 = nox_common_randomIntMinMax_415FF0(0, result - 1, "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c", 376);
			v6 = a1[108] - 1;
			a1[43] = a1[v5 + 76];
			v7 = v5;
			if (v5 < v6) {
				v8 = &a1[v5 + 76];
				do {
					++v7;
					*v8 = v8[1];
					++v8;
				} while (v7 < a1[108] - 1);
			}
		} else {
			++a1[43];
		}
		v9 = a1[43];
		--a1[108];
		result = sub_4BD710(a1[v9 + 10]);
	} else if (v3 & 1) {
		if (*(uint32_t*)(v1 + 60) && (v4 = a1[109] + 1, a1[109] = v4, v4 >= *(int*)(v1 + 60)))
			result = 0;
		else
			result = sub_451CA0(a1);
	}
	return result;
}

//----- (00451DC0) --------------------------------------------------------
int  sub_451DC0(int a1) {
	uint32_t* v1; // esi
	int result; // eax
	int v3;     // ebx
	int i;      // edi
	int v5;     // eax
	int v6;     // eax

	v1 = *(uint32_t**)(a1 + 36);
	result = *(uint32_t*)(a1 + 168);
	v3 = v1[1];
	if (result) {
		if (v1[17] < 0x21u)
			return result;
		sub_451F90(a1);
	}
	if (v3 & 4) {
		if (v1[17] >= 0x21u) {
			v5 = sub_451E80(a1);
			result = sub_451F30(a1, v5);
		} else {
			result = v1[48];
			for (i = 0; i < result; ++i) {
				sub_451F30(a1, i);
				result = v1[48];
			}
		}
	} else if (v3 & 2) {
		v6 = nox_common_randomIntMinMax_415FF0(0, v1[48] - 1, "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c", 536);
		result = sub_451F30(a1, v6);
	} else {
		result = sub_451F30(a1, 0);
	}
	return result;
}

//----- (00451E80) --------------------------------------------------------
int  sub_451E80(int a1) {
	int v1;      // eax
	int v2;      // ebx
	int v3;      // eax
	int v4;      // ecx
	int v5;      // edx
	int v6;      // eax
	int v7;      // edx
	int v8;      // eax
	int v9;      // edi
	int v10;     // ecx
	uint32_t* v11; // eax

	v1 = *(uint32_t*)(a1 + 36);
	v2 = *(uint32_t*)(v1 + 4);
	if (*(int*)(a1 + 568) <= 0) {
		v3 = *(uint32_t*)(v1 + 192);
		v4 = 0;
		*(uint32_t*)(a1 + 568) = v3;
		if (v3 > 0) {
			v5 = a1 + 440;
			do {
				v5 += 4;
				v6 = v3 - v4++ - 1;
				*(uint32_t*)(v5 - 4) = v6;
				v3 = *(uint32_t*)(a1 + 568);
			} while (v4 < v3);
		}
	}
	v7 = *(uint32_t*)(a1 + 568) - 1;
	*(uint32_t*)(a1 + 568) = v7;
	if (!(v2 & 2))
		return *(uint32_t*)(a1 + 4 * v7 + 440);
	v8 = nox_common_randomIntMinMax_415FF0(0, v7, "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c", 431);
	v9 = *(uint32_t*)(a1 + 4 * v8 + 440);
	v10 = v8;
	if (v8 < *(int*)(a1 + 568)) {
		v11 = (uint32_t*)(a1 + 4 * v8 + 440);
		do {
			++v10;
			*v11 = v11[1];
			++v11;
		} while (v10 < *(int*)(a1 + 568));
	}
	return v9;
}

//----- (00452580) --------------------------------------------------------
int  sub_452580(uint32_t* a1) {
	int v1;     // edi
	int result; // eax
	int v3;     // eax
	int v4;     // eax
	int v5;     // eax

	v1 = a1[9];
	if (!*(uint32_t*)(v1 + 192))
		return 0;
	v3 = a1[75];
	a1[109] = 0;
	result = sub_452810(*(uint32_t*)(v1 + 48) + v3, 0);
	a1[44] = result;
	if (result) {
		v4 = nox_common_randomIntMinMax_415FF0(*(uint32_t*)(v1 + 76), *(uint32_t*)(v1 + 80), "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c", 1482);
		sub_486320((uint32_t*)(a1[44] + 48), v4 + 100);
		sub_4BDB20(a1[44]);
		*(uint32_t*)(a1[44] + 152) = a1;
		*(uint32_t*)(a1[44] + 140) = sub_452770;
		*(uint32_t*)(a1[44] + 144) = sub_4526F0;
		*(uint32_t*)(a1[44] + 148) = sub_4526D0;
		a1[7] = 1;
		*(uint32_t*)(a1[44] + 112) = a1 + 46;
		if (*(uint8_t*)(v1 + 4) & 8) {
			v5 = nox_common_randomIntMinMax_415FF0(*(uint32_t*)(v1 + 68), *(uint32_t*)(v1 + 72), "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c",
							1497);
			if (v5 > 33)
				sub_452690((int)a1, v5, 1);
		}
		result = 1;
	}
	return result;
}

//----- (00452770) --------------------------------------------------------
int  sub_452770(uint32_t* a1) {
	uint32_t* v1;      // esi
	uint32_t* v2;      // ebx
	int v4;          // eax
	unsigned int v5; // eax

	v1 = (uint32_t*)a1[38];
	v2 = (uint32_t*)sub_451CF0((uint32_t*)a1[38]);
	if (*(uint32_t*)(v1[9] + 72) < 0x21u) {
		sub_4BDB90(a1, v2);
		return 0;
	}
	sub_4BDB90(a1, 0);
	v4 = v1[9];
	if (!(*(uint8_t*)(v4 + 4) & 8) || v2 || v1[142]) {
		v5 = nox_common_randomIntMinMax_415FF0(*(uint32_t*)(v4 + 68), *(uint32_t*)(v4 + 72), "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c", 706);
		if (v5 < 0x21) {
			sub_4BDB90(a1, v2);
			return 0;
		}
		v1[71] = v5;
		v1[74] = v2;
	}
	return 0;
}
