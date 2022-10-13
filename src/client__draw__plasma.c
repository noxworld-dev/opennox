#include "client__draw__plasma.h"
#include "common__random.h"

#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME2.h"
#include "GAME3_1.h"
#include "GAME4_1.h"
#include "GAME5_2.h"
#include "client__draw__fx.h"
#include "client__video__draw_common.h"
#include "input_common.h"
#include "operators.h"

extern uint32_t dword_5d4594_1316412;
extern uint32_t dword_5d4594_1316408;

//----- (004BA230) --------------------------------------------------------
int sub_4BA230(int a1, int a2, int a3, int a4, int a5) {
	int v5;             // ebx
	unsigned char* v6;  // eax
	int v7;             // ecx
	int i;              // ebp
	int result;         // eax
	int v10;            // edi
	int v11;            // esi
	int v12;            // eax
	int v13;            // eax
	int v14;            // eax
	int v15;            // eax
	int j;              // edi
	unsigned char* v17; // esi
	int v18;            // eax
	int v19;            // edx
	int v20;            // eax
	int v21;            // ecx
	int v22;            // eax
	int v23;            // edx
	double v24;         // st7
	int v25;            // eax
	int v26;            // eax
	int v27;            // edx
	float v28;          // [esp+0h] [ebp-30h]
	float v29;          // [esp+0h] [ebp-30h]
	float v30;          // [esp+0h] [ebp-30h]
	float v31;          // [esp+0h] [ebp-30h]
	int2 a4a;           // [esp+10h] [ebp-20h]
	int2 a3a;           // [esp+18h] [ebp-18h]
	int2 a2a;           // [esp+20h] [ebp-10h]
	int2 a1a;           // [esp+28h] [ebp-8h]
	int v36;            // [esp+34h] [ebp+4h]
	float v37;          // [esp+34h] [ebp+4h]

	v5 = 0;
	if (!*getMemU32Ptr(0x5D4594, 1316404)) {
		*getMemU32Ptr(0x5D4594, 1313828) = nox_color_rgb_4344A0(40, 180, 255);
		*getMemU32Ptr(0x5D4594, 1313832) = nox_color_rgb_4344A0(255, 255, 255);
		*getMemU32Ptr(0x5D4594, 1313836) = nox_color_rgb_4344A0(40, 180, 255);
		*getMemU32Ptr(0x5D4594, 1313844) = 8;
		*getMemU32Ptr(0x5D4594, 1313852) = 8;
		*getMemU32Ptr(0x5D4594, 1313856) = 0;
		*getMemU32Ptr(0x5D4594, 1313860) = 0;
		*getMemU8Ptr(0x5D4594, 1313840) = 16;
		*getMemU8Ptr(0x5D4594, 1313842) = 16;
		*getMemU32Ptr(0x5D4594, 1313848) = 12;
		*getMemU8Ptr(0x5D4594, 1313841) = 24;
		v6 = getMemAt(0x5D4594, 1313900);
		*getMemU32Ptr(0x5D4594, 1313864) = 0;
		do {
			v7 = 30;
			do {
				*((uint32_t*)v6 - 1) = 0;
				*(uint32_t*)v6 = 0;
				*((uint32_t*)v6 + 1) = 0;
				*((uint32_t*)v6 + 2) = 0;
				*((uint32_t*)v6 - 2) = 0;
				v6 += 28;
				--v7;
			} while (v7);
		} while ((int)v6 < (int)getMemAt(0x5D4594, 1316420));
		*getMemU32Ptr(0x5D4594, 1316404) = 1;
	}
	sub_4BA670(a1, a2, a3, a4, a5);
	for (i = 0; i < 3; ++i) {
		result = dword_5d4594_1316408;
		v10 = 0;
		if (*(int*)&dword_5d4594_1316408 + 1 <= 0) {
			continue;
		}
		do {
			v11 = 28 * (30 * i + v10);
			v12 = *getMemU32Ptr(0x5D4594, 1313900 + v11) + *getMemU32Ptr(0x5D4594, 1313896 + v11);
			*getMemU32Ptr(0x5D4594, 1313896 + v11) = v12;
			if (v12 < 256) {
				if (v12 >= 0) {
					goto LABEL_14;
				}
				v13 = v12 + 255;
			} else {
				v13 = v12 - 256;
			}
			*getMemU32Ptr(0x5D4594, 1313896 + v11) = v13;
		LABEL_14:
			if (!v10) {
				*getMemU32Ptr(0x5D4594, 1313896 + 840 * i) = a1;
			}
			v14 = *getMemU32Ptr(0x5D4594, 1313904 + v11) + *getMemU32Ptr(0x5D4594, 1313900 + v11);
			*getMemU32Ptr(0x5D4594, 1313900 + v11) = v14;
			if (i == 1) {
				if (v14 <= 10) {
					if (v14 < -10) {
						*getMemU32Ptr(0x5D4594, 1314740 + 28 * v10) = -10;
					}
				} else {
					*getMemU32Ptr(0x5D4594, 1314740 + 28 * v10) = 10;
				}
			} else if (v14 <= 25) {
				if (v14 < -25) {
					*getMemU32Ptr(0x5D4594, 1313900 + v11) = -25;
				}
			} else {
				*getMemU32Ptr(0x5D4594, 1313900 + v11) = 25;
			}
			v15 = *getMemU32Ptr(0x5D4594, 1313908 + v11) - 1;
			*getMemU32Ptr(0x5D4594, 1313908 + v11) = v15;
			if (v15 <= 0) {
				*getMemU32Ptr(0x5D4594, 1313908 + v11) =
					nox_common_randomIntMinMax_415FF0(10, 90, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 378);
				*getMemU32Ptr(0x5D4594, 1313904 + v11) =
					nox_common_randomIntMinMax_415FF0(4, 8, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 382);
				if (nox_common_randomIntMinMax_415FF0(0, 1, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 385)) {
					*getMemU32Ptr(0x5D4594, 1313904 + v11) = -*getMemU32Ptr(0x5D4594, 1313904 + v11);
				}
				if (i == 1) {
					*getMemU32Ptr(0x5D4594, 1314732 + 28 * v10) =
						nox_common_randomIntMinMax_415FF0(40, 50, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 392);
				} else {
					*getMemU32Ptr(0x5D4594, 1313892 + v11) =
						nox_common_randomIntMinMax_415FF0(80, 110, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 395);
					if (v10 < 4 && nox_common_randomIntMinMax_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c",
																	 402) > 90) {
						*getMemU32Ptr(0x5D4594, 1313892 + v11) = nox_common_randomIntMinMax_415FF0(
							150, 200, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 407);
						*getMemU32Ptr(0x5D4594, 1313908 + v11) *= 2;
					}
				}
			}
			result = dword_5d4594_1316408;
			++v10;
		} while (v10 < *(int*)&dword_5d4594_1316408 + 1);
		v5 = 0;
	}
	for (j = 0; j < 3; ++j) {
		if (result > 0) {
			v17 = getMemAt(0x5D4594, 1313896 + 840 * j);
			do {
				v36 = *((uint32_t*)v17 - 1);
				v18 = *(uint32_t*)v17;
				v19 = *((uint32_t*)v17 - 2);
				a1a.field_0 = *((uint32_t*)v17 - 3);
				a1a.field_4 = v19;
				v37 = (double)v36;
				v28 = v37 * *getMemFloatPtr(0x587000, 194136 + 8 * v18);
				v20 = nox_float2int(v28);
				v21 = *(uint32_t*)v17;
				a3a.field_0 = v20;
				v29 = v37 * *getMemFloatPtr(0x587000, 194140 + 8 * v21);
				v22 = nox_float2int(v29);
				v23 = *((uint32_t*)v17 + 4);
				v24 = v37 * *getMemFloatPtr(0x587000, 194136 + 8 * *((uint32_t*)v17 + 7));
				a3a.field_4 = v22;
				v25 = *((uint32_t*)v17 + 5);
				a2a.field_0 = v23;
				a2a.field_4 = v25;
				v30 = v24;
				v26 = nox_float2int(v30);
				v27 = *((uint32_t*)v17 + 7);
				a4a.field_0 = v26;
				v31 = v37 * *getMemFloatPtr(0x587000, 194140 + 8 * v27);
				a4a.field_4 = nox_float2int(v31);
				sub_4BE800(*getMemU32Ptr(0x5D4594, 1313828 + 4 * j));
				sub_4BE810(1, *getMemU32Ptr(0x5D4594, 1313828 + 4 * j), *getMemU32Ptr(0x5D4594, 1313844 + 4 * j),
						   getMemByte(0x5D4594, 1313840 + j));
				if (j == 1) {
					sub_4BEAD0(&a1a, &a2a, &a3a, &a4a, 8, 1);
				} else {
					sub_4BEAD0(&a1a, &a2a, &a3a, &a4a, 8, 0);
				}
				result = dword_5d4594_1316408;
				++v5;
				v17 += 28;
			} while (v5 < *(int*)&dword_5d4594_1316408);
			v5 = 0;
		}
	}
	return result;
}

//----- (004BA8B0) --------------------------------------------------------
char sub_4BA8B0(int* a1, int* a2, int* a3) {
	int v3;   // esi
	char* v4; // edi
	int v5;   // edx
	int v6;   // eax

	v3 = *a3;
	v4 = nox_draw_getViewport_437250();
	if (!*getMemU32Ptr(0x5D4594, 1316416)) {
		*getMemU32Ptr(0x5D4594, 1316416) = nox_xxx_getTTByNameSpriteMB_44CFC0("CyanSpark");
	}
	v6 = 28 * (dword_5d4594_1316412 + 30 * v3);
	v5 = dword_5d4594_1316412 + 1;
	*getMemU32Ptr(0x5D4594, 1313884 + v6) = *a1;
	*getMemU32Ptr(0x5D4594, 1313888 + v6) = a1[1];
	*getMemU32Ptr(0x5D4594, 1313912 + v6) = *a2;
	*getMemU32Ptr(0x5D4594, 1313916 + v6) = a2[1];
	LOBYTE(v6) = (unsigned char)gameFrame();
	dword_5d4594_1316412 = v5;
	if ((unsigned char)gameFrame() & 4) {
		v6 = nox_common_randomIntMinMax_415FF0(0, 10, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 135);
		if (v6 > 5) {
			LOBYTE(v6) = nox_xxx_drawEnergyBolt_499710(*a2 + *((uint32_t*)v4 + 4) - *(uint32_t*)v4,
													   a2[1] + *((uint32_t*)v4 + 5) - *((uint32_t*)v4 + 1), 8,
													   *getMemIntPtr(0x5D4594, 1316416));
		}
	}
	return v6;
}

//----- (004BA980) --------------------------------------------------------
int nox_thing_plasma_draw(int* a1, nox_drawable* dr) {
	int v3;            // ebx
	unsigned short v4; // di
	int v5;            // ebp
	int v6;            // ecx
	int v7;            // edx
	int v8;            // eax
	int v9;            // esi
	int* v10;          // edi
	int* v11;          // ebx
	int v12;           // eax
	uint32_t* v13;     // eax
	int v14;           // eax
	uint32_t* v15;     // edi
	int v16;           // eax
	uint32_t* v17;     // eax
	int v18;           // eax
	uint32_t* v19;     // ebp
	int v20;           // eax
	int v21;           // edx
	int v22;           // ebx
	int v23;           // ecx
	float2 v25;        // [esp+4h] [ebp-8h]
	unsigned char v26; // [esp+14h] [ebp+8h]

	int a2 = dr;

	nox_point mpos = nox_client_getMousePos_4309F0();
	v3 = a2;
	if (*(uint8_t*)(a2 + 432)) {
		if (nox_xxx_netTestHighBit_578B70(*(uint32_t*)(a2 + 437))) {
			v12 = nox_xxx_netClearHighBit_578B30(*(uint32_t*)(a2 + 437));
			v13 = nox_xxx_netSpriteByCodeStatic_45A720(v12);
		} else {
			v14 = nox_xxx_netClearHighBit_578B30(*(uint32_t*)(a2 + 437));
			v13 = nox_xxx_netSpriteByCodeDynamic_45A6F0(v14);
		}
		v15 = v13;
		if (nox_xxx_netTestHighBit_578B70(*(uint32_t*)(a2 + 441))) {
			v16 = nox_xxx_netClearHighBit_578B30(*(uint32_t*)(a2 + 441));
			v17 = nox_xxx_netSpriteByCodeStatic_45A720(v16);
		} else {
			v18 = nox_xxx_netClearHighBit_578B30(*(uint32_t*)(a2 + 441));
			v17 = nox_xxx_netSpriteByCodeDynamic_45A6F0(v18);
		}
		v19 = v17;
		if (v15 && v17) {
			v20 = a1[5];
			v21 = a1[4];
			v22 = *a1;
			v23 = a1[1];
			v9 = *a1 + v15[3] - v21;
			a2 = *a1 + v15[3] - v21;
			a1 = (int*)(v15[4] - v20 + v23 - 20);
			v10 = (int*)(v22 + v19[3] - v21);
			v11 = (int*)(v19[4] - v20 + v23 - 20);
		} else {
			v9 = a2;
			v10 = a1;
			v11 = a1;
		}
		v25.field_0 = (double)mpos.x - (double)a2;
		v25.field_4 = (double)mpos.y - (double)(int)a1;
		v26 = nox_xxx_math_509ED0(&v25);
	} else {
		v4 = *(uint16_t*)(a2 + 439);
		v26 = *(uint8_t*)(a2 + 433);
		v5 = a1[5];
		v6 = a1[4];
		v7 = *a1;
		v8 = a1[1];
		v9 = *a1 + *(unsigned short*)(v3 + 437) - v6;
		a1 = (int*)(v4 - v5 + v8 - 20);
		v10 = (int*)(v7 + *(unsigned short*)(v3 + 441) - v6);
		v11 = (int*)(*(unsigned short*)(v3 + 443) - v5 + v8 - 20);
	}
	sub_4BA230(v26, v9, (int)a1, (int)v10, (int)v11);
	return 1;
}
