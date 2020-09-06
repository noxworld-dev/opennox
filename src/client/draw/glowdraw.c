#include "glowdraw.h"

#include "../../proto.h"
#include "fx.h"
extern _DWORD dword_5d4594_1313564;
extern _DWORD dword_5d4594_1313692;
extern _DWORD dword_5d4594_1313532;
extern _DWORD dword_5d4594_1313536;
extern _DWORD dword_5d4594_1313540;

//----- (004B6770) --------------------------------------------------------
int __cdecl sub_4B6770(int* a1, nox_drawable* dr, int a3, int a4) {
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
	v5 = *(_DWORD*)(a2 + 444);
	v6 = *(_DWORD*)(a2 + 448) - v5;
	v7 = *(_DWORD*)(a2 + 448) - *getMemU32Ptr(0x5D4594, 2598000);
	v16 = *(_DWORD*)(a2 + 448) - v5;
	v18 = v7;
	if (v7 == v6)
		v18 = --v7;
	if (v7 > 0) {
		v9 = *a1;
		v10 = a1[1];
		v11 = *a1 + *(_DWORD*)(v4 + 12) - a1[4];
		v12 = *(_DWORD*)(v4 + 16) - *(__int16*)(v4 + 106) - *(__int16*)(v4 + 104) - a1[5];
		xLeft.field_0 = v11;
		v13 = v10 + v12;
		xLeft.field_4 = v13;
		if (v11 - 10 >= v9 && v13 - 10 >= v10 && v11 + 10 < a1[2] && v13 + 10 < a1[3]) {
			v14 = v18 * sub_415FF0(0, 4, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 213) / v16;
			v15 = v14;
			if (v14) {
				sub_4B6720(&xLeft, a4, 2 * v14 + 1, v14 + 1);
				nox_client_drawSetColor_434460(a3);
				sub_499B70(xLeft.field_0, xLeft.field_4, v15);
			}
		}
		result = 1;
	} else {
		sub_45A4E0_drawable(dr);
		result = 0;
	}
	return result;
}

//----- (004B6B00) --------------------------------------------------------
int __cdecl nox_thing_magic_sparkle_draw(int* a1, nox_drawable* dr) {
	int result; // eax

	if (sub_415FF0(0, 10, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 317) >= 5)
		result = sub_4B6770(a1, dr, *(int*)getMemAt(0x5D4594, 2523948), *(int*)&dword_5d4594_1313540);
	else
		result = sub_4B6770(a1, dr, *(int*)&dword_5d4594_1313540, *(int*)&dword_5d4594_1313536);
	return result;
}

//----- (004B6E80) --------------------------------------------------------
int __cdecl nox_thing_pixie_draw(int* a1, nox_drawable* dr) {
	bool v2;     // cc
	__int16 v3;  // ax
	__int16 v4;  // ax
	int v5;      // edx
	int v6;      // edi
	int v7;      // ecx
	int v8;      // eax
	int v9;      // edi
	int v10;     // esi
	int v11;     // ebx
	int v12;     // ebp
	__int64 v13; // rax
	int2 v15;    // [esp+10h] [ebp-8h]

	int a2 = dr;

	v2 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 503) < 50;
	v3 = *(_WORD*)(a2 + 104);
	if (v2) {
		if (v3 > 0) {
			v4 = v3 - 1;
		LABEL_6:
			*(_WORD*)(a2 + 104) = v4;
			goto LABEL_7;
		}
	} else if (v3 < 35) {
		v4 = v3 + 1;
		goto LABEL_6;
	}
LABEL_7:
	v5 = *a1;
	v6 = a1[1];
	v7 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
	v8 = v6 + *(_DWORD*)(a2 + 16) - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
	v15.field_0 = v7;
	v15.field_4 = v8;
	if (v7 - 10 >= v5 && v8 - 10 >= v6 && v7 + 10 < a1[2] && v8 + 10 < a1[3]) {
		sub_4B6720(&v15, *(int*)getMemAt(0x5D4594, 1313560), 10, 4);
		v9 = *a1 + *(_DWORD*)(a2 + 32) - a1[4];
		v10 = a1[1] + *(_DWORD*)(a2 + 36) - *(__int16*)(a2 + 104) - a1[5];
		v11 = v15.field_0 - v9;
		v12 = v15.field_4 - v10;
		if (v11 * v11 + v12 * v12 > 400) {
			v13 = (__int64)sqrt((double)(v11 * v11 + v12 * v12));
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
int __cdecl nox_thing_pixie_dust_draw(int* a1, nox_drawable* dr) {
	int result; // eax

	if (sub_415FF0(0, 10, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 554) >= 5)
		result = sub_4B6770(a1, dr, *(int*)getMemAt(0x5D4594, 2523948), *(int*)&dword_5d4594_1313564);
	else
		result = sub_4B6770(a1, dr, *(int*)&dword_5d4594_1313564, *(int*)getMemAt(0x5D4594, 1313560));
	return result;
}

//----- (004B7060) --------------------------------------------------------
int __cdecl nox_thing_blue_rain_spark_draw(_DWORD* a1, nox_drawable* dr) {
	int result; // eax
	int v3;     // eax
	int v4;     // eax
	int v5;     // edi

	int a2 = dr;

	result = sub_4B6970(a1, dr, *(int*)getMemAt(0x5D4594, 2523948), *(int*)&dword_5d4594_1313540);
	if (result == 1 && *(_BYTE*)(a2 + 296) >= 5) {
		v3 = *getMemU32Ptr(0x5D4594, 1313688);
		if (!*getMemU32Ptr(0x5D4594, 1313688)) {
			v3 = sub_44CFC0((CHAR*)getMemAt(0x587000, 176184));
			*getMemU32Ptr(0x5D4594, 1313688) = v3;
		}
		v4 = sub_45A360_drawable(v3, *(_DWORD*)(a2 + 12), *(_DWORD*)(a2 + 16));
		v5 = v4;
		if (v4) {
			if (v4 != -432) {
				*(_DWORD*)(v4 + 432) = *(_DWORD*)(a2 + 12) << 12;
				*(_DWORD*)(v4 + 436) = *(_DWORD*)(a2 + 16) << 12;
				*(_BYTE*)(v4 + 299) = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 605);
				*(_DWORD*)(v5 + 440) = sub_415FF0(1, 1611, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 608);
				*(_DWORD*)(v5 + 448) = *getMemU32Ptr(0x5D4594, 2598000) +
									   sub_415FF0(10, 96, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 611);
				*(_DWORD*)(v5 + 444) = *getMemU32Ptr(0x5D4594, 2598000);
			}
			*(_WORD*)(v5 + 104) = sub_415FF0(5, 15, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 618);
			*(_WORD*)(v5 + 106) = 0;
			*(_BYTE*)(v5 + 296) = sub_415FF0(0, 8, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 620);
			sub_45A110_drawable((_DWORD*)v5);
		}
		sub_45A4E0_drawable(dr);
		result = 0;
	}
	return result;
}

//----- (004B7310) --------------------------------------------------------
int __cdecl nox_thing_rain_orb_draw(_DWORD* a1, nox_drawable* dr) {
	int* v2;        // esi
	__int16 v3;     // cx
	int v4;         // edi
	int v5;         // eax
	__int16 v6;     // bp
	int v7;         // ebx
	__int16 v8;     // ax
	double v9;      // st7
	__int16 v10;    // ax
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
	__int16 v23[4]; // [esp+1Ch] [ebp-10h]
	float2 v24;     // [esp+24h] [ebp-8h]
	int v25;        // [esp+34h] [ebp+8h]

	int a2 = dr;

	v2 = (_DWORD*)a2;
	if (!dword_5d4594_1313692) {
		dword_5d4594_1313692 = sub_44CFC0((CHAR*)getMemAt(0x587000, 176396));
		*getMemU32Ptr(0x5D4594, 1313696) = sub_44CFC0((CHAR*)getMemAt(0x587000, 176412));
	}
	v3 = *(_WORD*)(a2 + 104);
	if (v3 > 0) {
		v14 = a1[5];
		v15 = *(_DWORD*)(a2 + 16);
		xLeft.field_0 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
		v16 = a1[1] - v14;
		v17 = *getMemU32Ptr(0x5D4594, 1313588);
		v18 = *(_DWORD*)(a2 + 108);
		xLeft.field_4 = v15 + v16 - v3;
		if (v18 != dword_5d4594_1313692)
			v17 = dword_5d4594_1313536;
		sub_4B6720(&xLeft, v17, *(unsigned __int8*)(a2 + 442), 5);
		v19 = *(__int16*)(a2 + 104) - *(__int16*)(a2 + 440);
		nox_client_drawSetColor_434460(v17);
		nox_client_drawAddPoint_49F500(xLeft.field_0, xLeft.field_4);
		sub_49F570(0, v19);
		nox_client_drawLineFromPoints_49E4B0();
		*(_WORD*)(a2 + 440) = *(_WORD*)(a2 + 104);
		*(_WORD*)(a2 + 104) += *(char*)(a2 + 296);
		nox_client_drawSetColor_434460(*(int*)getMemAt(0x5D4594, 1313592));
		sub_499B70(xLeft.field_0, xLeft.field_4, *(unsigned __int8*)(a2 + 442) / 3);
		result = 1;
	} else {
		if (!*getMemU32Ptr(0x5D4594, 1313700)) {
			*getMemU32Ptr(0x5D4594, 1313700) = sub_44CFC0((CHAR*)getMemAt(0x587000, 176424));
			*getMemU32Ptr(0x5D4594, 1313704) = sub_44CFC0((CHAR*)getMemAt(0x587000, 176440));
		}
		v4 = *(_DWORD*)(a2 + 12);
		v5 = *(_DWORD*)(a2 + 16);
		v6 = v5 + 20;
		v25 = v5 - *(_DWORD*)(a2 + 436);
		v24.field_0 = (double)(v2[3] - v2[108]);
		v24.field_4 = (double)v25;
		v7 = sub_509ED0(&v24);
		v23[2] = v4;
		v23[3] = v6;
		v20 = *getMemFloatPtr(0x587000, 8 * v7 + 194136) * 150.0 + (double)(int)v2[108];
		v8 = nox_float2int(v20);
		v9 = *getMemFloatPtr(0x587000, 8 * v7 + 194140) * 150.0;
		v23[0] = v8;
		v21 = v9 + (double)(int)v2[109];
		v10 = nox_float2int(v21);
		v11 = *getMemU32Ptr(0x5D4594, 1313700);
		v23[1] = v10;
		if (v2[27] != dword_5d4594_1313692)
			v11 = *getMemU32Ptr(0x5D4594, 1313704);
		v12 = sub_415FF0(6, 8, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 793);
		sub_499490(v11, v23, 0, 0, v12, 1);
		sub_45A4E0_drawable(dr);
		result = 0;
	}
	return result;
}

//----- (004B6A60) --------------------------------------------------------
int __cdecl nox_thing_red_spark_draw(_DWORD* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *(int*)&dword_5d4594_1313532, *(int*)getMemAt(0x5D4594, 1313528));
}

//----- (004B6A80) --------------------------------------------------------
int __cdecl nox_thing_blue_spark_draw(_DWORD* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *(int*)&dword_5d4594_1313540, *(int*)&dword_5d4594_1313536);
}

//----- (004B6AA0) --------------------------------------------------------
int __cdecl nox_thing_cyan_spark_draw(_DWORD* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *(int*)getMemAt(0x5D4594, 1313548), *(int*)getMemAt(0x5D4594, 1313544));
}

//----- (004B6AC0) --------------------------------------------------------
int __cdecl nox_thing_green_spark_draw(_DWORD* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *(int*)getMemAt(0x5D4594, 1313584), *(int*)getMemAt(0x5D4594, 1313580));
}

//----- (004B6AE0) --------------------------------------------------------
int __cdecl nox_thing_yellow_spark_draw(_DWORD* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *(int*)&dword_5d4594_1313532, *(int*)getMemAt(0x5D4594, 1313576));
}

//----- (004B6E40) --------------------------------------------------------
int __cdecl nox_thing_violet_spark_draw(_DWORD* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *(int*)getMemAt(0x5D4594, 1313556), *(int*)getMemAt(0x5D4594, 1313552));
}

//----- (004B6E60) --------------------------------------------------------
int __cdecl nox_thing_death_ball_spark_draw(_DWORD* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *(int*)getMemAt(0x5D4594, 1313572), *(int*)getMemAt(0x5D4594, 1313568));
}

//----- (004B7040) --------------------------------------------------------
int __cdecl nox_thing_white_spark_draw(_DWORD* a1, nox_drawable* dr) {
	return sub_4B6970(a1, dr, *(int*)getMemAt(0x5D4594, 2523948), *(int*)&dword_5d4594_1313540);
}

//----- (004AFE80) --------------------------------------------------------
int __cdecl nox_thing_particle_draw(int a1, nox_drawable* dr) {
	_DWORD* v2;                  // eax
	void(__cdecl * v3)(_DWORD*); // ecx

	_DWORD* a2 = dr;

	v2 = (_DWORD*)a2[108];
	a2[3] = v2[20] >> 16;
	a2[4] = v2[21] >> 16;
	v3 = (void(__cdecl*)(_DWORD*))v2[31];
	if (v3)
		v3(v2);
	return 1;
}

//----- (004B6B60) --------------------------------------------------------
int __cdecl nox_thing_glow_orb_draw(int* a1, nox_drawable* dr) { return sub_4B6B80(a1, dr, 0); }

//----- (004B6E20) --------------------------------------------------------
int __cdecl nox_thing_glow_orb_move_draw(int* a1, nox_drawable* dr) { return sub_4B6B80(a1, dr, 1); }
