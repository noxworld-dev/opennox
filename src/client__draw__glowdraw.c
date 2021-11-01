#include <math.h>

#include "client__draw__glowdraw.h"
#include "common__random.h"

#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME4_1.h"
#include "client__draw__fx.h"
extern uint32_t dword_5d4594_1313564;
extern uint32_t dword_5d4594_1313692;
extern uint32_t dword_5d4594_1313532;
extern uint32_t dword_5d4594_1313536;
extern uint32_t dword_5d4594_1313540;
extern unsigned int nox_frame_xxx_2598000;

//----- (004B6770) --------------------------------------------------------
int  sub_4B6770(int* a1, nox_drawable* dr, int a3, int a4) {
	int a2 = dr;

	int v4;     // edx
	int v5;     // ebx
	int v6;     // ecx
	int v7;     // eax
	int result; // eax
	int v9;     // edi
	int v10;    // ebx
	int v11;    // ecx
	int v12;    // eax
	int v13;    // eax
	int v14;    // eax
	int v15;    // esi
	int v16;    // [esp+Ch] [ebp-Ch]
	int2 xLeft; // [esp+10h] [ebp-8h]
	int v18;    // [esp+20h] [ebp+8h]

	v4 = a2;
	v5 = *(uint32_t*)(a2 + 444);
	v6 = *(uint32_t*)(a2 + 448) - v5;
	v7 = *(uint32_t*)(a2 + 448) - nox_frame_xxx_2598000;
	v16 = *(uint32_t*)(a2 + 448) - v5;
	v18 = v7;
	if (v7 == v6)
		v18 = --v7;
	if (v7 > 0) {
		v9 = *a1;
		v10 = a1[1];
		v11 = *a1 + *(uint32_t*)(v4 + 12) - a1[4];
		v12 = *(uint32_t*)(v4 + 16) - *(short*)(v4 + 106) - *(short*)(v4 + 104) - a1[5];
		xLeft.field_0 = v11;
		v13 = v10 + v12;
		xLeft.field_4 = v13;
		if (v11 - 10 >= v9 && v13 - 10 >= v10 && v11 + 10 < a1[2] && v13 + 10 < a1[3]) {
			v14 = v18 * nox_common_randomIntMinMax_415FF0(0, 4, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 213) / v16;
			v15 = v14;
			if (v14) {
				sub_4B6720(&xLeft, a4, 2 * v14 + 1, v14 + 1);
				nox_client_drawSetColor_434460(a3);
				nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, v15);
			}
		}
		result = 1;
	} else {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
		result = 0;
	}
	return result;
}

//----- (004B6B00) --------------------------------------------------------
int  nox_thing_magic_sparkle_draw(int* a1, nox_drawable* dr) {
	int result; // eax

	if (nox_common_randomIntMinMax_415FF0(0, 10, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 317) >= 5)
		result = sub_4B6770(a1, dr, *getMemIntPtr(0x5D4594, 2523948), *(int*)&dword_5d4594_1313540);
	else
		result = sub_4B6770(a1, dr, *(int*)&dword_5d4594_1313540, *(int*)&dword_5d4594_1313536);
	return result;
}

//----- (004B6E80) --------------------------------------------------------
int  nox_thing_pixie_draw(int* a1, nox_drawable* dr) {
	bool v2;     // cc
	short v3;  // ax
	short v4;  // ax
	int v5;      // edx
	int v6;      // edi
	int v7;      // ecx
	int v8;      // eax
	int v9;      // edi
	int v10;     // esi
	int v11;     // ebx
	int v12;     // ebp
	long long v13; // rax
	int2 v15;    // [esp+10h] [ebp-8h]

	int a2 = dr;

	v2 = nox_common_randomIntMinMax_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 503) < 50;
	v3 = *(uint16_t*)(a2 + 104);
	if (v2) {
		if (v3 > 0) {
			v4 = v3 - 1;
		LABEL_6:
			*(uint16_t*)(a2 + 104) = v4;
			goto LABEL_7;
		}
	} else if (v3 < 35) {
		v4 = v3 + 1;
		goto LABEL_6;
	}
LABEL_7:
	v5 = *a1;
	v6 = a1[1];
	v7 = *a1 + *(uint32_t*)(a2 + 12) - a1[4];
	v8 = v6 + *(uint32_t*)(a2 + 16) - *(short*)(a2 + 106) - *(short*)(a2 + 104) - a1[5];
	v15.field_0 = v7;
	v15.field_4 = v8;
	if (v7 - 10 >= v5 && v8 - 10 >= v6 && v7 + 10 < a1[2] && v8 + 10 < a1[3]) {
		sub_4B6720(&v15, *getMemIntPtr(0x5D4594, 1313560), 10, 4);
		v9 = *a1 + *(uint32_t*)(a2 + 32) - a1[4];
		v10 = a1[1] + *(uint32_t*)(a2 + 36) - *(short*)(a2 + 104) - a1[5];
		v11 = v15.field_0 - v9;
		v12 = v15.field_4 - v10;
		if (v11 * v11 + v12 * v12 > 400) {
			v13 = (long long)sqrt((double)(v11 * v11 + v12 * v12));
			v9 = v15.field_0 - 20 * v11 / (int)v13;
			v10 = v15.field_4 - 20 * v12 / (int)v13;
		}
		nox_client_drawSetColor_434460(*(int*)&dword_5d4594_1313564);
		nox_client_drawAddPoint_49F500(v15.field_0, v15.field_4);
		nox_client_drawAddPoint_49F500(v9, v10);
		nox_client_drawLineFromPoints_49E4B0();
	}
	return 1;
}

//----- (004B6FE0) --------------------------------------------------------
int  nox_thing_pixie_dust_draw(int* a1, nox_drawable* dr) {
	int result; // eax

	if (nox_common_randomIntMinMax_415FF0(0, 10, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 554) >= 5)
		result = sub_4B6770(a1, dr, *getMemIntPtr(0x5D4594, 2523948), *(int*)&dword_5d4594_1313564);
	else
		result = sub_4B6770(a1, dr, *(int*)&dword_5d4594_1313564, *getMemIntPtr(0x5D4594, 1313560));
	return result;
}

//----- (004B7060) --------------------------------------------------------
int  nox_thing_blue_rain_spark_draw(uint32_t* a1, nox_drawable* dr) {
	int result; // eax
	int v3;     // eax
	int v4;     // eax
	int v5;     // edi

	int a2 = dr;

	result = sub_4B6970(a1, dr, *getMemIntPtr(0x5D4594, 2523948), *(int*)&dword_5d4594_1313540);
	if (result == 1 && *(uint8_t*)(a2 + 296) >= 5) {
		v3 = *getMemU32Ptr(0x5D4594, 1313688);
		if (!*getMemU32Ptr(0x5D4594, 1313688)) {
			v3 = nox_xxx_getTTByNameSpriteMB_44CFC0("WhiteSpark");
			*getMemU32Ptr(0x5D4594, 1313688) = v3;
		}
		v4 = nox_xxx_spriteLoadAdd_45A360_drawable(v3, *(uint32_t*)(a2 + 12), *(uint32_t*)(a2 + 16));
		v5 = v4;
		if (v4) {
			if (v4 != -432) {
				*(uint32_t*)(v4 + 432) = *(uint32_t*)(a2 + 12) << 12;
				*(uint32_t*)(v4 + 436) = *(uint32_t*)(a2 + 16) << 12;
				*(uint8_t*)(v4 + 299) = nox_common_randomIntMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 605);
				*(uint32_t*)(v5 + 440) = nox_common_randomIntMinMax_415FF0(1, 1611, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 608);
				*(uint32_t*)(v5 + 448) = nox_frame_xxx_2598000 +
									   nox_common_randomIntMinMax_415FF0(10, 96, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 611);
				*(uint32_t*)(v5 + 444) = nox_frame_xxx_2598000;
			}
			*(uint16_t*)(v5 + 104) = nox_common_randomIntMinMax_415FF0(5, 15, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 618);
			*(uint16_t*)(v5 + 106) = 0;
			*(uint8_t*)(v5 + 296) = nox_common_randomIntMinMax_415FF0(0, 8, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 620);
			nox_xxx_sprite_45A110_drawable((uint32_t*)v5);
		}
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
		result = 0;
	}
	return result;
}

//----- (004B7310) --------------------------------------------------------
int  nox_thing_rain_orb_draw(uint32_t* a1, nox_drawable* dr) {
	int* v2;        // esi
	short v3;     // cx
	int v4;         // edi
	int v5;         // eax
	short v6;     // bp
	int v7;         // ebx
	short v8;     // ax
	double v9;      // st7
	short v10;    // ax
	int v11;        // edi
	char v12;       // al
	int result;     // eax
	int v14;        // ebx
	int v15;        // edi
	int v16;        // edx
	int v17;        // ebx
	int v18;        // eax
	int v19;        // edi
	float v20;      // [esp+0h] [ebp-2Ch]
	float v21;      // [esp+0h] [ebp-2Ch]
	int2 xLeft;     // [esp+14h] [ebp-18h]
	short v23[4]; // [esp+1Ch] [ebp-10h]
	float2 v24;     // [esp+24h] [ebp-8h]
	int v25;        // [esp+34h] [ebp+8h]

	int a2 = dr;

	v2 = (uint32_t*)a2;
	if (!dword_5d4594_1313692) {
		dword_5d4594_1313692 = nox_xxx_getTTByNameSpriteMB_44CFC0("RainOrbWhite");
		*getMemU32Ptr(0x5D4594, 1313696) = nox_xxx_getTTByNameSpriteMB_44CFC0("RainOrbBlue");
	}
	v3 = *(uint16_t*)(a2 + 104);
	if (v3 > 0) {
		v14 = a1[5];
		v15 = *(uint32_t*)(a2 + 16);
		xLeft.field_0 = *a1 + *(uint32_t*)(a2 + 12) - a1[4];
		v16 = a1[1] - v14;
		v17 = *getMemU32Ptr(0x5D4594, 1313588);
		v18 = *(uint32_t*)(a2 + 108);
		xLeft.field_4 = v15 + v16 - v3;
		if (v18 != dword_5d4594_1313692)
			v17 = dword_5d4594_1313536;
		sub_4B6720(&xLeft, v17, *(unsigned char*)(a2 + 442), 5);
		v19 = *(short*)(a2 + 104) - *(short*)(a2 + 440);
		nox_client_drawSetColor_434460(v17);
		nox_client_drawAddPoint_49F500(xLeft.field_0, xLeft.field_4);
		nox_xxx_rasterPointRel_49F570(0, v19);
		nox_client_drawLineFromPoints_49E4B0();
		*(uint16_t*)(a2 + 440) = *(uint16_t*)(a2 + 104);
		*(uint16_t*)(a2 + 104) += *(char*)(a2 + 296);
		nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 1313592));
		nox_xxx_drawPointMB_499B70(xLeft.field_0, xLeft.field_4, *(unsigned char*)(a2 + 442) / 3);
		result = 1;
	} else {
		if (!*getMemU32Ptr(0x5D4594, 1313700)) {
			*getMemU32Ptr(0x5D4594, 1313700) = nox_xxx_getTTByNameSpriteMB_44CFC0("WhiteMoveOrb");
			*getMemU32Ptr(0x5D4594, 1313704) = nox_xxx_getTTByNameSpriteMB_44CFC0("BlueMoveOrb");
		}
		v4 = *(uint32_t*)(a2 + 12);
		v5 = *(uint32_t*)(a2 + 16);
		v6 = v5 + 20;
		v25 = v5 - *(uint32_t*)(a2 + 436);
		v24.field_0 = (double)(v2[3] - v2[108]);
		v24.field_4 = (double)v25;
		v7 = nox_xxx_math_509ED0(&v24);
		v23[2] = v4;
		v23[3] = v6;
		v20 = *getMemFloatPtr(0x587000, 194136 + 8 * v7) * 150.0 + (double)(int)v2[108];
		v8 = nox_float2int(v20);
		v9 = *getMemFloatPtr(0x587000, 194140 + 8 * v7) * 150.0;
		v23[0] = v8;
		v21 = v9 + (double)(int)v2[109];
		v10 = nox_float2int(v21);
		v11 = *getMemU32Ptr(0x5D4594, 1313700);
		v23[1] = v10;
		if (v2[27] != dword_5d4594_1313692)
			v11 = *getMemU32Ptr(0x5D4594, 1313704);
		v12 = nox_common_randomIntMinMax_415FF0(6, 8, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 793);
		sub_499490(v11, v23, 0, 0, v12, 1);
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
		result = 0;
	}
	return result;
}

//----- (004B6A60) --------------------------------------------------------
int  nox_thing_red_spark_draw(uint32_t* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *(int*)&dword_5d4594_1313532, *getMemIntPtr(0x5D4594, 1313528));
}

//----- (004B6A80) --------------------------------------------------------
int  nox_thing_blue_spark_draw(uint32_t* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *(int*)&dword_5d4594_1313540, *(int*)&dword_5d4594_1313536);
}

//----- (004B6AA0) --------------------------------------------------------
int  nox_thing_cyan_spark_draw(uint32_t* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *getMemIntPtr(0x5D4594, 1313548), *getMemIntPtr(0x5D4594, 1313544));
}

//----- (004B6AC0) --------------------------------------------------------
int  nox_thing_green_spark_draw(uint32_t* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *getMemIntPtr(0x5D4594, 1313584), *getMemIntPtr(0x5D4594, 1313580));
}

//----- (004B6AE0) --------------------------------------------------------
int  nox_thing_yellow_spark_draw(uint32_t* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *(int*)&dword_5d4594_1313532, *getMemIntPtr(0x5D4594, 1313576));
}

//----- (004B6E40) --------------------------------------------------------
int  nox_thing_violet_spark_draw(uint32_t* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *getMemIntPtr(0x5D4594, 1313556), *getMemIntPtr(0x5D4594, 1313552));
}

//----- (004B6E60) --------------------------------------------------------
int  nox_thing_death_ball_spark_draw(uint32_t* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *getMemIntPtr(0x5D4594, 1313572), *getMemIntPtr(0x5D4594, 1313568));
}

//----- (004B7040) --------------------------------------------------------
int  nox_thing_white_spark_draw(uint32_t* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *getMemIntPtr(0x5D4594, 2523948), *(int*)&dword_5d4594_1313540);
}

//----- (004AFE80) --------------------------------------------------------
int  nox_thing_particle_draw(int a1, nox_drawable* dr) {
	uint32_t* v2;                  // eax
	void( * v3)(uint32_t*); // ecx

	uint32_t* a2 = dr;

	v2 = (uint32_t*)a2[108];
	a2[3] = v2[20] >> 16;
	a2[4] = v2[21] >> 16;
	v3 = (void(*)(uint32_t*))v2[31];
	if (v3)
		v3(v2);
	return 1;
}

//----- (004B6B60) --------------------------------------------------------
int  nox_thing_glow_orb_draw(int* a1, nox_drawable* dr) { return sub_4B6B80(a1, dr, 0); }

//----- (004B6E20) --------------------------------------------------------
int  nox_thing_glow_orb_move_draw(int* a1, nox_drawable* dr) { return sub_4B6B80(a1, dr, 1); }
