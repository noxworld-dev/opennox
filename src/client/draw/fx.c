#include "fx.h"

#include "../../proto.h"

//----- (00499490) --------------------------------------------------------
_DWORD* __cdecl sub_499490(int a1, _WORD* a2, int a3, int a4, char a5, char a6) {
	_DWORD* result; // eax
	_DWORD* v7;     // esi

	result = (_DWORD*)nox_xxx_spriteLoadAdd_45A360_drawable(a1, a3 + (unsigned __int16)a2[2], a4 + (unsigned __int16)a2[3]);
	v7 = result;
	if (result) {
		*((_WORD*)result + 216) = *a2;
		*((_WORD*)result + 217) = a2[1];
		*((_BYTE*)result + 443) = a5;
		*((_BYTE*)result + 444) = nox_xxx_randGetMinMax_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 138);
		*((_BYTE*)v7 + 446) = a6;
		*((_BYTE*)v7 + 445) = a6;
		result = nox_xxx_sprite_45A110_drawable(v7);
	}
	return result;
}

//----- (00499520) --------------------------------------------------------
_DWORD* __cdecl sub_499520(int a1, unsigned __int16* a2, __int16 a3, char a4, char a5) {
	int v5;         // ebp
	int v6;         // edi
	_DWORD* result; // eax
	_DWORD* v8;     // esi

	v5 = a2[3];
	v6 = a2[2];
	result = (_DWORD*)nox_xxx_spriteLoadAdd_45A360_drawable(a1, v6, (unsigned __int16)v5);
	v8 = result;
	if (result) {
		*((_WORD*)result + 216) = *a2;
		*((_WORD*)result + 217) = a2[1];
		*((_WORD*)result + 218) = v6;
		*((_WORD*)result + 219) = v5;
		*((_BYTE*)result + 442) = a3;
		*((_WORD*)result + 220) = (__int64)sqrt((double)((v6 - *a2) * (v6 - *a2) + (v5 - a2[1]) * (v5 - a2[1])));
		*((_BYTE*)result + 443) = a4;
		*((_BYTE*)result + 444) = nox_xxx_randGetMinMax_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 182);
		*((_BYTE*)v8 + 446) = a5;
		*((_BYTE*)v8 + 445) = a5;
		v8[116] = sub_4CA720;
		*((_WORD*)v8 + 254) = a3;
		result = nox_xxx_sprite_45A110_drawable(v8);
	}
	return result;
}

//----- (00499610) --------------------------------------------------------
int __cdecl nox_xxx_makePointFxCli_499610(int a1, int a2, int a3, int a4, int a5, int a6) {
	int result; // eax
	int v7;     // eax
	int v8;     // esi

	result = a2;
	if (a2 > 0) {
		do {
			v7 = nox_xxx_spriteLoadAdd_45A360_drawable(a1, a5, a6);
			v8 = v7;
			if (v7) {
				*(_DWORD*)(v7 + 432) = *(_DWORD*)(v7 + 12) << 12;
				*(_DWORD*)(v7 + 436) = *(_DWORD*)(v7 + 16) << 12;
				*(_BYTE*)(v7 + 299) = nox_xxx_randGetMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 227);
				*(_DWORD*)(v8 + 440) = nox_xxx_randGetMinMax_415FF0(1, a3, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 230);
				*(_DWORD*)(v8 + 448) =
					*getMemU32Ptr(0x5D4594, 2598000) + nox_xxx_randGetMinMax_415FF0(a4, 64, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 233);
				*(_DWORD*)(v8 + 444) = *getMemU32Ptr(0x5D4594, 2598000);
				*(_WORD*)(v8 + 104) = 0;
				*(_BYTE*)(v8 + 296) = nox_xxx_randGetMinMax_415FF0(2, 10, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 239);
				nox_xxx_sprite_45A110_drawable((_DWORD*)v8);
			}
			result = --a2;
		} while (a2);
	}
	return result;
}

//----- (00499710) --------------------------------------------------------
int __cdecl sub_499710(int a1, int a2, __int16 a3, int a4) {
	int v4;     // eax
	int v5;     // esi
	int result; // eax
	int v7;     // [esp+10h] [ebp-4h]

	v7 = 2;
	do {
		v4 = nox_xxx_spriteLoadAdd_45A360_drawable(a4, a1, a2);
		v5 = v4;
		if (v4) {
			*(_DWORD*)(v4 + 432) = a1 << 12;
			*(_DWORD*)(v4 + 436) = a2 << 12;
			*(_BYTE*)(v4 + 299) = nox_xxx_randGetMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 268);
			*(_DWORD*)(v5 + 440) = nox_xxx_randGetMinMax_415FF0(1, 3000, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 271);
			*(_DWORD*)(v5 + 448) =
				*getMemU32Ptr(0x5D4594, 2598000) + nox_xxx_randGetMinMax_415FF0(5, 20, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 274);
			*(_DWORD*)(v5 + 444) = *getMemU32Ptr(0x5D4594, 2598000);
			*(_WORD*)(v5 + 104) = a3 + nox_xxx_randGetMinMax_415FF0(0, 20, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 279);
			*(_BYTE*)(v5 + 296) = nox_xxx_randGetMinMax_415FF0(0, 4, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 280);
			nox_xxx_sprite_45A110_drawable((_DWORD*)v5);
		}
		result = --v7;
	} while (v7);
	return result;
}

//----- (00499950) --------------------------------------------------------
int __cdecl sub_499950(int a1, int2* a2, int2* a3, unsigned __int16 a4, char a5) {
	int result; // eax
	int v6;     // esi

	result = nox_xxx_spriteLoadAdd_45A360_drawable(a1, a2->field_0, a2->field_4);
	v6 = result;
	if (result) {
		*(_DWORD*)(result + 104) = a4;
		*(_BYTE*)(result + 296) = a5;
		*(_WORD*)(result + 440) = a4;
		*(_BYTE*)(result + 442) = nox_xxx_randGetMinMax_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 406);
		*(int2*)(v6 + 432) = *a3;
		result = nox_xxx_sprite_45A110_drawable((_DWORD*)v6);
	}
	return result;
}

//----- (004999D0) --------------------------------------------------------
int __cdecl nox_xxx_makeLightningParticles_4999D0(int a1, int2* a2, int2* a3) {
	int2* v3;   // ebp
	int v4;     // esi
	int v5;     // edi
	__int64 v6; // rax
	int v7;     // ebx
	int v8;     // ecx
	int v9;     // esi
	int v10;    // edi
	int v11;    // eax
	int v12;    // ebp
	int v14;    // [esp+10h] [ebp-Ch]
	int v15;    // [esp+14h] [ebp-8h]
	int v16;    // [esp+18h] [ebp-4h]
	int2* v17;  // [esp+28h] [ebp+Ch]

	v3 = a2;
	v4 = a3->field_0 - a2->field_0;
	v5 = a3->field_4 - a2->field_4;
	v14 = a3->field_0 - a2->field_0;
	v15 = v5;
	v6 = (__int64)sqrt((double)(v4 * v4 + v5 * v5));
	v7 = v6;
	v16 = v6;
	if ((int)v6 > 0) {
		LODWORD(v6) = nox_xxx_randGetMinMax_415FF0(0, v6, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 437);
		v8 = v6;
		v17 = (int2*)v6;
		if ((int)v6 <= v7) {
			while (1) {
				v9 = v3->field_0 + v4 * v8 / v7;
				v10 = v3->field_4 + v5 * v8 / v7;
				v11 = nox_xxx_spriteLoadAdd_45A360_drawable(a1, v9, v10);
				v12 = v11;
				if (v11) {
					if (v11 != -432) {
						*(_DWORD*)(v11 + 432) = v9 << 12;
						*(_DWORD*)(v11 + 436) = v10 << 12;
						*(_BYTE*)(v11 + 299) = nox_xxx_randGetMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 458);
						*(_DWORD*)(v12 + 440) = nox_xxx_randGetMinMax_415FF0(1, 3000, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 461);
						*(_DWORD*)(v12 + 448) = *getMemU32Ptr(0x5D4594, 2598000) +
												nox_xxx_randGetMinMax_415FF0(5, 20, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 464);
						*(_DWORD*)(v12 + 444) = *getMemU32Ptr(0x5D4594, 2598000);
					}
					*(_WORD*)(v12 + 104) = nox_xxx_randGetMinMax_415FF0(15, 30, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 471);
					*(_BYTE*)(v12 + 296) = nox_xxx_randGetMinMax_415FF0(-4, 4, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 472);
					nox_xxx_sprite_45A110_drawable((_DWORD*)v12);
					v7 = v16;
				}
				LODWORD(v6) = nox_xxx_randGetMinMax_415FF0(8, 100, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 439);
				v17 = (int2*)((char*)v17 + v6);
				if ((int)v17 > v7)
					break;
				v3 = a2;
				v4 = v14;
				v5 = v15;
				v8 = (int)v17;
			}
		}
	}
	return v6;
}

//----- (00499E70) --------------------------------------------------------
int __cdecl nox_xxx_draw_499E70(int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
	int v7;     // edi
	int v8;     // esi
	char v9;    // bl
	int v10;    // ebp
	int v11;    // eax
	int result; // eax
	int v13;    // [esp+10h] [ebp-4h]

	v13 = 100;
	do {
		if (a6 == 2) {
			v7 = a3;
			v8 = a2 + nox_xxx_randGetMinMax_415FF0(0, a4, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 555);
		} else {
			v8 = a2;
			v7 = a3 + nox_xxx_randGetMinMax_415FF0(0, a5, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 563);
		}
		v9 = nox_xxx_randGetMinMax_415FF0(2, 5, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 568);
		v10 = nox_xxx_randGetMinMax_415FF0(-40, -20, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 571);
		if (a7 == 1)
			v11 = nox_xxx_randGetMinMax_415FF0(-20, 0, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 573);
		else
			v11 = nox_xxx_randGetMinMax_415FF0(0, 20, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 575);
		nox_client_newScreenParticle_431540(a1, v8, v7, v11, v10, 1, v9, 0, 0, 1);
		result = --v13;
	} while (v13);
	return result;
}

//----- (0049A150) --------------------------------------------------------
int __cdecl sub_49A150(int2* a1, int a2, unsigned __int8 a3) {
	int v3;     // ebx
	int result; // eax
	int v5;     // ebp
	int v6;     // eax
	int v7;     // esi
	int v8;     // [esp+1Ch] [ebp+Ch]

	v3 = 2400 * a3 / 255 + 200;
	result = 84215050 * a3;
	v5 = 10 * a3 / 255 + 5;
	if (180 * a3 / 255 + 10 > 0) {
		v8 = 180 * a3 / 255 + 10;
		do {
			v6 = nox_xxx_spriteLoadAdd_45A360_drawable(a2, a1->field_0, a1->field_4);
			v7 = v6;
			if (v6) {
				if (v6 != -432) {
					*(_DWORD*)(v6 + 432) = *(_DWORD*)(v6 + 12) << 12;
					*(_DWORD*)(v6 + 436) = *(_DWORD*)(v6 + 16) << 12;
					*(_BYTE*)(v6 + 299) = nox_xxx_randGetMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 822);
					*(_DWORD*)(v7 + 440) = nox_xxx_randGetMinMax_415FF0(1, v3, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 825);
					*(_DWORD*)(v7 + 448) = *getMemU32Ptr(0x5D4594, 2598000) +
										   nox_xxx_randGetMinMax_415FF0(v5, 96, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 828);
					*(_DWORD*)(v7 + 444) = *getMemU32Ptr(0x5D4594, 2598000);
				}
				*(_WORD*)(v7 + 104) = nox_xxx_randGetMinMax_415FF0(5, 15, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 834);
				*(_WORD*)(v7 + 106) = 0;
				*(_BYTE*)(v7 + 296) = nox_xxx_randGetMinMax_415FF0(0, 8, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 836);
				nox_xxx_sprite_45A110_drawable((_DWORD*)v7);
			}
			result = --v8;
		} while (v8);
	}
	return result;
}
