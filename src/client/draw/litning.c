#include "litning.h"

#include "../../proto.h"
extern _DWORD dword_5d4594_1316476;
extern _DWORD dword_5d4594_1316492;

//----- (0049F5A0) --------------------------------------------------------
void sub_49F5A0() { *(_DWORD*)&byte_5D4594[3798692] = 0; }

//----- (004BB070) --------------------------------------------------------
int __cdecl sub_4BB070(int a1, int a2) {
	int v2;             // eax
	bool v3;            // zf
	int v4;             // esi
	int v5;             // edi
	int v6;             // ebx
	int v7;             // ebp
	unsigned __int8 v8; // al
	int v9;             // ecx
	int v10;            // eax
	int v11;            // ecx
	int v12;            // eax
	int v14;            // edi
	int v15;            // esi
	int v16;            // eax
	int v17;            // [esp+10h] [ebp-14h]
	int v18;            // [esp+10h] [ebp-14h]
	int v19;            // [esp+14h] [ebp-10h]
	int v20;            // [esp+14h] [ebp-10h]
	int v21;            // [esp+18h] [ebp-Ch]
	int v22;            // [esp+18h] [ebp-Ch]
	int v23;            // [esp+20h] [ebp-4h]
	int v24;            // [esp+20h] [ebp-4h]
	int v25;            // [esp+28h] [ebp+4h]
	int v26;            // [esp+28h] [ebp+4h]
	int v27;            // [esp+2Ch] [ebp+8h]
	int v28;            // [esp+2Ch] [ebp+8h]

	v2 = dword_5d4594_1316492 + 1;
	v3 = dword_5d4594_1316492 + 1 == *(_DWORD*)&byte_5D4594[1316448];
	v23 = 0;
	++dword_5d4594_1316492;
	if (!v3) {
		v14 = 1;
		v15 = 1;
		if (v2 > 1) {
			v16 = v2 - 1;
			do {
				v14 *= *(_DWORD*)&byte_587000[178212] + 9;
				v15 *= 10;
				--v16;
			} while (v16);
		}
		LOWORD(v24) = v15 *
				  sub_415FF0(-dword_5d4594_1316476, *(int*)&dword_5d4594_1316476,
					     "C:\\NoxPost\\src\\Client\\Draw\\Litning.c", 193) /
				  v14 +
			      (((__int16)a1 + (__int16)a2) >> 1);
		HIWORD(v24) = v15 *
				  sub_415FF0(-dword_5d4594_1316476, *(int*)&dword_5d4594_1316476,
					     "C:\\NoxPost\\src\\Client\\Draw\\Litning.c", 196) /
				  v14 +
			      ((SHIWORD(a1) + SHIWORD(a2)) >> 1);
		sub_4BB070(a1, v24);
		sub_4BB070(v24, a2);
		return --dword_5d4594_1316492;
	}
	if (*(_DWORD*)&byte_5D4594[1316508]) {
		LOBYTE(v23) = byte_5D4594[1316420] + 48;
		sub_434040(*(int*)&byte_5D4594[1316440]);
		sub_434080(12);
		v4 = SHIWORD(a1);
		v5 = (__int16)a1;
		nox_client_drawAddPoint_49F500((__int16)a1, SHIWORD(a1));
		v6 = SHIWORD(a2);
		v7 = (__int16)a2;
		nox_client_drawAddPoint_49F500((__int16)a2, SHIWORD(a2));
		sub_49E4F0(v23);
		v23 = 1;
	} else {
		sub_434040(*(int*)&byte_5D4594[1316472]);
		sub_434080(3);
		v4 = SHIWORD(a1);
		v5 = (__int16)a1;
		nox_client_drawAddPoint_49F500((__int16)a1, SHIWORD(a1));
		v6 = SHIWORD(a2);
		v7 = (__int16)a2;
		nox_client_drawAddPoint_49F500((__int16)a2, SHIWORD(a2));
		sub_49E4F0(32);
	}
	nox_client_drawSetColor_434460(*(int*)&byte_5D4594[1316472]);
	nox_client_drawAddPoint_49F500(v5, v4);
	nox_client_drawAddPoint_49F500(v7, v6);
	nox_client_drawLineFromPoints_49E4B0();
	if (!v23)
		return --dword_5d4594_1316492;
	v8 = byte_5D4594[1316420];
	v25 = 1;
	if ((byte_5D4594[1316420] & 0xFEu) > 2) {
		v19 = v7 + 1;
		v21 = v5 + 1;
		v17 = v4 + 1;
		v27 = v6 + 1;
		do {
			sub_49F5A0();
			v9 = v5 - v7;
			if (v5 - v7 < 0)
				v9 = v7 - v5;
			v10 = v4 - v6;
			if (v4 - v6 < 0)
				v10 = v6 - v4;
			if (v9 <= v10) {
				nox_client_drawAddPoint_49F500(v19, v6);
				nox_client_drawAddPoint_49F500(v21, v4);
			} else {
				nox_client_drawAddPoint_49F500(v7, v27);
				nox_client_drawAddPoint_49F500(v5, v17);
			}
			nox_client_drawLineFromPoints_49E4B0();
			++v27;
			++v17;
			++v21;
			v8 = byte_5D4594[1316420];
			++v19;
			++v25;
		} while (v25 < (byte_5D4594[1316420] >> 1));
	}
	v26 = 1;
	if ((v8 & 0xFEu) <= 2)
		return --dword_5d4594_1316492;
	v20 = v7 - 1;
	v18 = v5 - 1;
	v22 = v4 - 1;
	v28 = v6 - 1;
	do {
		sub_49F5A0();
		v11 = v5 - v7;
		if (v5 - v7 < 0)
			v11 = v7 - v5;
		v12 = v4 - v6;
		if (v4 - v6 < 0)
			v12 = v6 - v4;
		if (v11 <= v12) {
			nox_client_drawAddPoint_49F500(v20, v6);
			nox_client_drawAddPoint_49F500(v18, v4);
		} else {
			nox_client_drawAddPoint_49F500(v7, v28);
			nox_client_drawAddPoint_49F500(v5, v22);
		}
		nox_client_drawLineFromPoints_49E4B0();
		--v28;
		--v22;
		--v18;
		++v26;
		--v20;
	} while (v26 < (byte_5D4594[1316420] >> 1));
	return --dword_5d4594_1316492;
}

//----- (004BAE60) --------------------------------------------------------
int __cdecl sub_4BAE60(int2* a1, int2* a2, int a3, __int16* a4, int a5, int a6, int a7) {
	int2* v7;    // ebx
	int2* v8;    // ebp
	int v9;      // esi
	int v10;     // eax
	int v11;     // eax
	__int64 v12; // rax
	int v13;     // eax
	int v14;     // edi
	int v15;     // ebx
	int v16;     // eax
	int v17;     // edx
	int v18;     // esi
	int v19;     // ecx
	int result;  // eax
	int2* v21;   // [esp+14h] [ebp+4h]
	int2* v22;   // [esp+18h] [ebp+8h]

	v7 = a2;
	v8 = a1;
	if (a1->field_0 - a2->field_0 >= 0)
		v9 = a1->field_0 - a2->field_0;
	else
		v9 = a2->field_0 - a1->field_0;
	v10 = a2->field_4;
	if (a1->field_4 - v10 >= 0)
		v11 = a1->field_4 - v10;
	else
		v11 = v10 - a1->field_4;
	v12 = (__int64)sqrt((double)(v9 * v9 + v11 * v11));
	if ((int)v12 >= 512) {
		dword_5d4594_1316476 = *(_DWORD*)&byte_587000[178204];
		*(_DWORD*)&byte_5D4594[1316448] = *(_DWORD*)&byte_587000[178216];
	} else {
        *(_DWORD *) &dword_5d4594_1316476 =
                *(_DWORD *) &byte_587000[178208] +
                (int) v12 * (*(_DWORD *) &byte_587000[178204] - *(_DWORD *) &byte_587000[178208]) / 512;
        bool v13p = 0;
        if ((int) v12 < 64) {
            v13 = *(_DWORD *) &byte_587000[178216] - 3;
        } else if ((int) v12 < 128) {
            v13 = *(_DWORD *) &byte_587000[178216] - 2;
        } else if ((int) v12 < 256) {
            v13 = *(_DWORD *) &byte_587000[178216] - 1;
        } else {
            v13 = *(_DWORD *) &byte_587000[178216];
            v13p = 1;
        }
        if (v13 >= 1 || v13p) {
            *(_DWORD *) &byte_5D4594[1316448] = v13;
        } else {
            *(_DWORD *) &byte_5D4594[1316448] = 1;
        }
    }
	*(_DWORD*)&byte_5D4594[1316532] = a3;
	if (a3 == 1 || a3 == 3) {
		*(_WORD*)&byte_5D4594[1316432] = *a4;
		*(_WORD*)&byte_5D4594[1316434] = a4[2];
		v14 = a1->field_0;
		v15 = a2->field_0;
		v16 = a1->field_0 - a2->field_0;
		if (v16 < 0)
			v16 = v15 - v14;
		v17 = a1->field_4;
		v18 = a2->field_4;
		v19 = a1->field_4 - v18;
		if (v19 < 0)
			v19 = v18 - v17;
		if (v16 <= v19)
			*(_DWORD*)&byte_5D4594[1316500] = (v17 >= v18) + 2;
		else
			*(_DWORD*)&byte_5D4594[1316500] = v14 >= v15;
		v7 = a2;
	}
	LOWORD(v22) = a1->field_0;
	LOWORD(v21) = v7->field_0;
	HIWORD(v22) = v8->field_4;
	HIWORD(v21) = v7->field_4;
	if (a6) {
		dword_5d4594_1316492 = 1;
		*(_DWORD*)&byte_5D4594[1316472] = *(_DWORD*)&byte_5D4594[1316456];
		*(_DWORD*)&byte_5D4594[1316508] = 0;
		sub_4BB070((int)v22, (int)v21);
		dword_5d4594_1316492 = 1;
		*(_DWORD*)&byte_5D4594[1316472] = *(_DWORD*)&byte_5D4594[1316452];
		sub_4BB070((int)v22, (int)v21);
	}
	result = a7;
	if (a7) {
		dword_5d4594_1316492 = 1;
		*(_DWORD*)&byte_5D4594[1316472] = *(_DWORD*)&byte_5D4594[1316436];
		*(_DWORD*)&byte_5D4594[1316440] = *(_DWORD*)&byte_5D4594[1316484];
		*(_DWORD*)&byte_5D4594[1316508] = 1;
		result = sub_4BB070((int)v22, (int)v21);
	}
	return result;
}

//----- (004BAC80) --------------------------------------------------------
int __cdecl nox_thing_lightning_draw(int* a1, int a2) {
	int v2;              // ebx
	int v3;              // edi
	int v4;              // ebp
	int v5;              // ecx
	unsigned __int16 v6; // ax
	_DWORD* v7;          // eax
	_DWORD* v8;          // edi
	_DWORD* v9;          // eax
	int v10;             // esi
	int v11;             // ecx
	int v12;             // ebx
	int v13;             // edx
	int2 a2a;            // [esp+10h] [ebp-20h]
	int2 a1a;            // [esp+18h] [ebp-18h]
	int2 a3;             // [esp+20h] [ebp-10h]
	int2 v18;            // [esp+28h] [ebp-8h]
	int v19;             // [esp+34h] [ebp+4h]

	if (!*(_BYTE*)(a2 + 432)) {
		v2 = *a1;
		v3 = a1[4];
		v4 = a1[5];
		v5 = *a1;
		v19 = a1[1];
		v18.field_0 = *(unsigned __int16*)(a2 + 437);
		a1a.field_0 = v18.field_0 + v5 - v3;
		v6 = *(_WORD*)(a2 + 441);
		v18.field_4 = *(unsigned __int16*)(a2 + 439);
		a1a.field_4 = v19 - v4 + v18.field_4 - 20;
		a3.field_0 = v6;
		a2a.field_0 = v2 + v6 - v3;
		a3.field_4 = *(unsigned __int16*)(a2 + 443);
		a2a.field_4 = a3.field_4 - v4 + v19 - 20;
	} else {
        if (sub_578B70(*(_DWORD *) (a2 + 437)))
            v7 = sub_45A720(*(_DWORD *) (a2 + 437));
        else
            v7 = sub_45A6F0(*(_DWORD *) (a2 + 437));
        v8 = v7;
        if (sub_578B70(*(_DWORD *) (a2 + 441)))
            v9 = sub_45A720(*(_DWORD *) (a2 + 441));
        else
            v9 = sub_45A6F0(*(_DWORD *) (a2 + 441));
        if (!(v8 && v9)) {
            return 1;
        }
        v10 = a1[4];
        v11 = *a1 - v10;
        a1a.field_0 = *a1 + v8[3] - v10;
        v12 = a1[5];
        v13 = a1[1];
        a1a.field_4 = v13 + v8[4] - v12 - 20;
        v18 = *(int2 *) (v8 + 3);
        a2a.field_0 = v9[3] + v11;
        a2a.field_4 = v9[4] - v12 + v13 - 20;
        a3 = *(int2 *) (v9 + 3);
    }
    *(_DWORD*)&byte_5D4594[1316452] = *(_DWORD*)&byte_5D4594[1316428];
    *(_DWORD*)&byte_5D4594[1316436] = *(_DWORD*)&byte_5D4594[1316464];
    *(_DWORD*)&byte_5D4594[1316456] = *(_DWORD*)&byte_5D4594[1316424];
    *(_DWORD*)&byte_5D4594[1316484] = *(_DWORD*)&byte_5D4594[1316488];
    byte_5D4594[1316420] = 1;
    sub_4BAE60(&a1a, &a2a, 2, 0, 1, 1, 1);
    if (!sub_413A50())
        sub_4999D0(*(int*)&byte_5D4594[1316520], &v18, &a3);
    return 1;
}

//----- (004BB3F0) --------------------------------------------------------
int __cdecl nox_thing_chain_lightning_bolt_draw(int* a1, int a2) {
	unsigned __int16 v2; // ax
	int v3;              // ebx
	int v4;              // edi
	int v5;              // ebp
	int v6;              // edx
	int v7;              // ecx
	unsigned __int16 v8; // ax
	_DWORD* v9;          // eax
	_DWORD* v10;         // edi
	_DWORD* v11;         // eax
	int v12;             // esi
	int v13;             // ecx
	int v14;             // ebx
	int v15;             // edx
	int2 a2a;            // [esp+10h] [ebp-20h]
	int2 a1a;            // [esp+18h] [ebp-18h]
	int2 v19;            // [esp+20h] [ebp-10h]
	int2 a3;             // [esp+28h] [ebp-8h]

	if (!*(_BYTE*)(a2 + 432)) {
		v2 = *(_WORD*)(a2 + 437);
		v3 = *a1;
		v4 = a1[4];
		v5 = a1[5];
		v6 = a1[1];
		v7 = v2 + *a1 - v4;
		v19.field_0 = v2;
		a1a.field_0 = v7;
		LOWORD(v7) = *(_WORD*)(a2 + 439);
		a2a.field_0 = v3 + *(unsigned __int16*)(a2 + 441) - v4;
		v19.field_4 = (unsigned __int16)v7;
		v8 = *(_WORD*)(a2 + 443);
		a1a.field_4 = v6 - v5 + (unsigned __int16)v7 - 20;
		a3.field_0 = v8;
		a2a.field_4 = v8 - v5 + v6 - 20;
	} else {
        if (sub_578B70(*(_DWORD *) (a2 + 437)))
            v9 = sub_45A720(*(_DWORD *) (a2 + 437));
        else
            v9 = sub_45A6F0(*(_DWORD *) (a2 + 437));
        v10 = v9;
        if (sub_578B70(*(_DWORD *) (a2 + 441)))
            v11 = sub_45A720(*(_DWORD *) (a2 + 441));
        else
            v11 = sub_45A6F0(*(_DWORD *) (a2 + 441));
        if (!(v10 && v11)) {
            return 1;
        }
        v12 = a1[4];
        v13 = *a1 - v12;
        a1a.field_0 = *a1 + v10[3] - v12;
        v14 = a1[5];
        v15 = a1[1];
        a1a.field_4 = v15 + v10[4] - v14 - 20;
        v19 = *(int2 *) (v10 + 3);
        a2a.field_0 = v11[3] + v13;
        a2a.field_4 = v11[4] - v14 + v15 - 20;
        a3 = *(int2 *) (v11 + 3);
    }
    *(_DWORD*)&byte_5D4594[1316452] = *(_DWORD*)&byte_5D4594[1316428];
    *(_DWORD*)&byte_5D4594[1316436] = *(_DWORD*)&byte_5D4594[1316464];
    *(_DWORD*)&byte_5D4594[1316456] = *(_DWORD*)&byte_5D4594[1316424];
    *(_DWORD*)&byte_5D4594[1316484] = *(_DWORD*)&byte_5D4594[1316488];
    byte_5D4594[1316420] = 1;
    sub_4BAE60(&a1a, &a2a, 2, 0, 1, 1, 1);
    if (!sub_413A50())
        sub_4999D0(*(int*)&byte_5D4594[1316520], &v19, &a3);
    return 1;
}

//----- (004BB5D0) --------------------------------------------------------
int __cdecl nox_thing_energy_bolt_draw(int* a1, int a2) {
	int v2;              // esi
	bool v3;             // zf
	int v4;              // ebp
	int v5;              // edi
	int v6;              // ebx
	int v7;              // ecx
	unsigned __int16 v8; // ax
	_DWORD* v9;          // eax
	_DWORD* v10;         // edi
	_DWORD* v11;         // eax
	int v12;             // esi
	int v13;             // edx
	int v14;             // ebp
	int v15;             // ecx
	int2 a2a;            // [esp+10h] [ebp-20h]
	int2 a1a;            // [esp+18h] [ebp-18h]
	int2 a3;             // [esp+20h] [ebp-10h]
	int2 v20;            // [esp+28h] [ebp-8h]
	int v21;             // [esp+34h] [ebp+4h]
	char v22;            // [esp+38h] [ebp+8h]

	v2 = a2;
	v3 = *(_BYTE*)(a2 + 432) == 0;
	v22 = *(_BYTE*)(a2 + 433);
	if (v3) {
		v4 = *a1;
		v5 = a1[4];
		v6 = a1[5];
		v7 = *a1;
		v21 = a1[1];
		v20.field_0 = *(unsigned __int16*)(v2 + 437);
		a1a.field_0 = v20.field_0 + v7 - v5;
		v8 = *(_WORD*)(v2 + 441);
		v20.field_4 = *(unsigned __int16*)(v2 + 439);
		a1a.field_4 = v21 - v6 + v20.field_4 - 20;
		a3.field_0 = v8;
		a2a.field_0 = v4 + v8 - v5;
		a3.field_4 = *(unsigned __int16*)(v2 + 443);
		a2a.field_4 = a3.field_4 - v6 + v21 - 20;
	} else {
        if (sub_578B70(*(_DWORD *) (v2 + 437)))
            v9 = sub_45A720(*(_DWORD *) (v2 + 437));
        else
            v9 = sub_45A6F0(*(_DWORD *) (v2 + 437));
        v10 = v9;
        if (sub_578B70(*(_DWORD *) (v2 + 441)))
            v11 = sub_45A720(*(_DWORD *) (v2 + 441));
        else
            v11 = sub_45A6F0(*(_DWORD *) (v2 + 441));
        if (!(v10 && v11)) {
            return 1;
        }
        v12 = *a1;
        v13 = a1[4];
        v14 = a1[5];
        v15 = a1[1];
        a1a.field_0 = v10[3] + *a1 - v13;
        a1a.field_4 = v10[4] - v14 + v15 - 20;
        v20 = *(int2 *) (v10 + 3);
        a2a.field_0 = v12 + v11[3] - v13;
        a2a.field_4 = v11[4] - v14 + v15 - 20;
        a3 = *(int2 *) (v11 + 3);
    }
    byte_5D4594[1316420] = 2 * (v22 + 127);
    *(_DWORD*)&byte_5D4594[1316436] = *(_DWORD*)&byte_5D4594[1316496];
    *(_DWORD*)&byte_5D4594[1316484] = *(_DWORD*)&byte_5D4594[1316468];
    sub_4BAE60(&a1a, &a2a, 2, 0, 0, 0, 1);
    if (!sub_413A50())
        sub_4999D0(*(int*)&byte_5D4594[1316524], &v20, &a3);
    return 1;
}

//----- (004BB7B0) --------------------------------------------------------
int __cdecl nox_thing_green_bolt_draw(int* a1, int a2) {
	int v2;              // eax
	int v3;              // eax
	int v5;              // ebx
	int v6;              // edi
	int v7;              // ebp
	int v8;              // ecx
	unsigned __int16 v9; // ax
	_DWORD* v10;         // eax
	_DWORD* v11;         // edi
	_DWORD* v12;         // eax
	int v13;             // esi
	int v14;             // edx
	int v15;             // ebx
	int v16;             // ecx
	int2 a2a;            // [esp+10h] [ebp-20h]
	int2 a1a;            // [esp+18h] [ebp-18h]
	int2 a3;             // [esp+20h] [ebp-10h]
	int2 v20;            // [esp+28h] [ebp-8h]
	int v21;             // [esp+34h] [ebp+4h]

	if (*(_BYTE*)(a2 + 432)) {
		if (sub_578B70(*(_DWORD*)(a2 + 437)))
			v10 = sub_45A720(*(_DWORD*)(a2 + 437));
		else
			v10 = sub_45A6F0(*(_DWORD*)(a2 + 437));
		v11 = v10;
		if (sub_578B70(*(_DWORD*)(a2 + 441)))
			v12 = sub_45A720(*(_DWORD*)(a2 + 441));
		else
			v12 = sub_45A6F0(*(_DWORD*)(a2 + 441));
		if (!v11 || !v12)
			return 1;
		v13 = *a1;
		v14 = a1[4];
		a1a.field_0 = v11[3] + *a1 - v14;
		v15 = a1[5];
		v16 = a1[1];
		a1a.field_4 = v16 + v11[4] - v15 - 20;
		v20 = *(int2*)(v11 + 3);
		a2a.field_0 = v13 + v12[3] - v14;
		a2a.field_4 = v12[4] - v15 + v16 - 20;
		a3 = *(int2*)(v12 + 3);
	} else {
		v2 = *(_DWORD*)(a2 + 433);
		if (v2) {
			v3 = v2 - 1;
			*(_DWORD*)(a2 + 433) = v3;
			if (!v3) {
				sub_45A4E0_drawable(a2);
				return 0;
			}
		}
		v5 = *a1;
		v6 = a1[4];
		v7 = a1[5];
		v8 = *a1;
		v21 = a1[1];
		v20.field_0 = *(unsigned __int16*)(a2 + 437);
		a1a.field_0 = v20.field_0 + v8 - v6;
		v9 = *(_WORD*)(a2 + 441);
		v20.field_4 = *(unsigned __int16*)(a2 + 439);
		a1a.field_4 = v21 - v7 + v20.field_4 - 20;
		a3.field_0 = v9;
		a2a.field_0 = v5 + v9 - v6;
		a3.field_4 = *(unsigned __int16*)(a2 + 443);
		a2a.field_4 = a3.field_4 - v7 + v21 - 20;
	}
	*(_DWORD*)&byte_5D4594[1316452] = *(_DWORD*)&byte_5D4594[1316444];
	*(_DWORD*)&byte_5D4594[1316436] = *(_DWORD*)&byte_5D4594[1316504];
	*(_DWORD*)&byte_5D4594[1316456] = *(_DWORD*)&byte_5D4594[1316460];
	*(_DWORD*)&byte_5D4594[1316484] = *(_DWORD*)&byte_5D4594[1316480];
	byte_5D4594[1316420] = 1;
	sub_4BAE60(&a1a, &a2a, 2, 0, 1, 1, 1);
	if (!sub_413A50())
		sub_4999D0(*(int*)&byte_5D4594[1316528], &v20, &a3);
	return 1;
}
