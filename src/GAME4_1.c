#include "server/gamemech/explevel.h"
#include "server/magic/plyrspel.h"
#include "server/network/mapsend.h"
#include "server/system/trade.h"

#include "proto.h"

extern _DWORD dword_5d4594_2386840;
extern _DWORD dword_5d4594_1599696;
extern _DWORD dword_587000_237036;
extern _DWORD dword_5d4594_2386916;
extern _DWORD dword_5d4594_2386228;
extern _DWORD dword_5d4594_2386216;
extern _DWORD dword_587000_230092;
extern _DWORD dword_5d4594_2386156;
extern _DWORD dword_5d4594_3835348;
extern _DWORD dword_5d4594_2386492;
extern _DWORD dword_5d4594_2386564;
extern _DWORD dword_5d4594_2386920;
extern _DWORD dword_5d4594_2386568;
extern _DWORD dword_5d4594_2386220;
extern _DWORD dword_5d4594_2386192;
extern _DWORD dword_5d4594_2388640;
extern _DWORD dword_5d4594_2487240;
extern _DWORD dword_5d4594_2386188;
extern _DWORD dword_5d4594_2386160;
extern _DWORD dword_5d4594_1599712;
extern _DWORD dword_5d4594_2386924;
extern _DWORD dword_5d4594_1599692;
extern _DWORD dword_5d4594_1569664;
extern _DWORD dword_5d4594_3821968;
extern _DWORD dword_5d4594_2386572;
extern _DWORD dword_5d4594_2386500;
extern _DWORD dword_5d4594_1599632;
extern _DWORD dword_5d4594_2386576;
extern _DWORD dword_5d4594_2386212;
extern _DWORD dword_5d4594_3843628;
extern _DWORD dword_5d4594_2386180;
extern _DWORD dword_5d4594_2386496;
extern _DWORD dword_5d4594_2386184;
extern _DWORD dword_5d4594_3821964;
extern _DWORD dword_5d4594_2388648;
extern _DWORD dword_5d4594_3821636;
extern _DWORD dword_5d4594_3821640;
extern _DWORD dword_5d4594_2386152;
extern _DWORD dword_5d4594_2386224;
extern _DWORD dword_5d4594_2650672;
extern _DWORD dword_5d4594_2386940;
extern _DWORD dword_5d4594_2487236;
extern _DWORD dword_5d4594_2386176;
extern _DWORD dword_5d4594_2386944;
extern _DWORD dword_5d4594_2650652;
extern obj_5D4594_2650668_t** ptr_5D4594_2650668;

//----- (005098A0) --------------------------------------------------------
int sub_5098A0() {
	int v0;        // ebp
	BOOL v1;       // ebx
	signed int v2; // esi
	char* i;       // eax
	signed int v4; // ecx
	int v5;        // edi
	int v6;        // ebp
	int v7;        // eax
	signed int v8; // eax
	int result;    // eax
	char* v10;     // [esp+10h] [ebp-8h]
	int v11;       // [esp+14h] [ebp-4h]

	v0 = 0;
	v11 = 0;
	v10 = 0;
	v1 = 0;
	v2 = 2147483648;
	for (i = sub_418B10(); i; i = sub_418B60((int)i)) {
		v4 = *((_DWORD*)i + 13);
		if (v4 >= v2) {
			v1 = v4 == v2 && v0;
			v2 = *((_DWORD*)i + 13);
			v10 = i;
			v0 = (int)i;
		}
	}
	v5 = sub_4DA7C0();
	if (v5) {
		do {
			v6 = *(_DWORD*)(v5 + 748);
			if (!sub_419130(v5 + 48)) {
				v7 = *(_DWORD*)(v6 + 276);
				if (!(*(_BYTE*)(v7 + 3680) & 1)) {
					v8 = *(_DWORD*)(v7 + 2136);
					if (v8 >= v2) {
						v1 = v8 == v2 && v11;
						v2 = v8;
						v11 = v5;
					}
				}
			}
			v5 = sub_4DA7F0(v5);
		} while (v5);
		v0 = (int)v10;
	}
	sub_40A4D0(8);
	if (v1)
		return sub_4D8BF0(0, 1);
	result = v11;
	if (v11)
		return sub_4D8B90(v11, 1);
	if (v0)
		result = sub_4D8BF0(v0, 1);
	return result;
}

//----- (005099B0) --------------------------------------------------------
int sub_5099B0() {
	int v0;     // edi
	BOOL v1;    // ebx
	int v2;     // esi
	char* i;    // eax
	int v4;     // ecx
	int result; // eax

	v0 = 0;
	v1 = 0;
	v2 = -1;
	for (i = sub_418B10(); i; i = sub_418B60((int)i)) {
		v4 = *((_DWORD*)i + 13);
		if (v4 >= v2) {
			v1 = v4 == v2 && v0;
			v2 = *((_DWORD*)i + 13);
			v0 = (int)i;
		}
	}
	sub_40A4D0(8);
	if (!v0 || v1) {
		if (nox_common_gameFlags_check_40A5C0(64))
			result = sub_4D8C40(0);
		else
			result = sub_4D8C80(0, 1);
	} else if (nox_common_gameFlags_check_40A5C0(64)) {
		result = sub_4D8C40(v0);
	} else {
		result = sub_4D8C80(v0, 1);
	}
	return result;
}

//----- (00509A60) --------------------------------------------------------
char sub_509A60() {
	char* v0;   // eax
	__int16 v1; // ax
	int v2;     // edi
	char* v3;   // esi
	int v4;     // esi
	int v5;     // eax
	char* v6;   // edi
	__int16 v7; // ax
	int v8;     // ebp
	int v9;     // ebx
	int i;      // esi
	int v11;    // eax

	if (nox_common_gameFlags_check_40A5C0(1024)) {
		v6 = 0;
		v7 = nox_common_gameFlags_getVal_40A5B0();
		LOWORD(v0) = sub_40A020(v7);
		v8 = (unsigned __int16)v0;
		if ((int)(unsigned __int16)v0 >= 1) {
			v9 = 0;
			for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
				v11 = *(_DWORD*)(*(_DWORD*)(i + 748) + 276);
				if (!(*(_BYTE*)(v11 + 3680) & 1) && *(_DWORD*)(v11 + 2140) < v8) {
					v0 = (char*)sub_419130(i + 48);
					if (v0) {
						if (v6) {
							v0 = sub_418AB0(*(unsigned __int8*)(i + 52));
							if (v6 != v0)
								return (char)v0;
						} else {
							v6 = sub_418AB0(*(unsigned __int8*)(i + 52));
						}
					} else {
						if (v9 || v6)
							return (char)v0;
						v9 = i;
					}
				}
			}
			v0 = sub_40A8A0();
			if (v0) {
				sub_40A4D0(8);
				if (v6) {
					LOBYTE(v0) = sub_4D8BF0((int)v6, 0);
				} else if (v9) {
					LOBYTE(v0) = sub_4D8B90(v9, 0);
				} else {
					LOBYTE(v0) = sub_4D8B90(0, 0);
				}
			}
		}
	} else {
		v0 = (char*)nox_common_gameFlags_check_40A5C0(512);
		if (!v0) {
			v1 = nox_common_gameFlags_getVal_40A5B0();
			LOWORD(v0) = sub_40A020(v1);
			v2 = (unsigned __int16)v0;
			if ((_WORD)v0) {
				v3 = sub_418B10();
				if (v3) {
					while (*((_DWORD*)v3 + 13) < v2) {
						v3 = sub_418B60((int)v3);
						if (!v3)
							goto LABEL_7;
					}
					sub_40A4D0(8);
					LOBYTE(v0) = sub_4D8BF0((int)v3, 0);
				} else {
				LABEL_7:
					v0 = (char*)sub_4DA7C0();
					v4 = (int)v0;
					if (v0) {
						while (1) {
							v5 = *(_DWORD*)(*(_DWORD*)(v4 + 748) + 276);
							if (!(*(_BYTE*)(v5 + 3680) & 1) && *(_DWORD*)(v5 + 2136) >= v2)
								break;
							v0 = (char*)sub_4DA7F0(v4);
							v4 = (int)v0;
							if (!v0)
								return (char)v0;
						}
						sub_40A4D0(8);
						LOBYTE(v0) = sub_4D8B90(v4, 0);
					}
				}
			}
		}
	}
	return (char)v0;
}
// 509BEA: variable 'v0' is possibly undefined

//----- (00509C30) --------------------------------------------------------
_DWORD* __cdecl sub_509C30(int a1) {
	char* v1; // edx

	if (!*(_DWORD*)&byte_5D4594[1599688]) {
		sub_425760(&byte_5D4594[1599676]);
		*(_DWORD*)&byte_5D4594[1599688] = 1;
	}
	v1 = (char*)nox_malloc(0x20u);
	*((_DWORD*)v1 + 6) = *(_DWORD*)(a1 + 2068);
	strcpy(v1 + 12, (const char*)(a1 + 2096));
	v1[28] = *(_BYTE*)(a1 + 2251);
	return sub_4257F0((int*)&byte_5D4594[1599676], v1);
}

//----- (00509CB0) --------------------------------------------------------
int* sub_509CB0() {
	int* result; // eax
	int* v1;     // esi
	int* v2;     // edi

	result = *(int**)&byte_5D4594[1599688];
	if (*(_DWORD*)&byte_5D4594[1599688]) {
		result = sub_425890((int*)&byte_5D4594[1599676]);
		v1 = result;
		if (result) {
			do {
				v2 = sub_4258A0(v1);
				sub_425920((_DWORD**)v1);
				free(v1);
				v1 = v2;
			} while (v2);
		}
	}
	return result;
}

//----- (00509CF0) --------------------------------------------------------
int __cdecl sub_509CF0(const char* a1, char a2, int a3) {
	int* v3; // edi

	v3 = sub_425890((int*)&byte_5D4594[1599676]);
	if (!v3)
		return 1;
	while (strcmp((const char*)v3 + 12, a1) || a2 == *((_BYTE*)v3 + 28) && a3 == v3[6]) {
		v3 = sub_4258A0(v3);
		if (!v3)
			return 1;
	}
	return 0;
}

//----- (00509D80) --------------------------------------------------------
int __cdecl sub_509D80(int a1) {
	int* v1; // edi

	v1 = sub_425890((int*)&byte_5D4594[1599676]);
	if (!v1)
		return 0;
	while (strcmp((const char*)v1 + 12, (const char*)(a1 + 2096))) {
		v1 = sub_4258A0(v1);
		if (!v1)
			return 0;
	}
	return 1;
}

//----- (00509E00) --------------------------------------------------------
int __cdecl sub_509E00(_DWORD* a1) { return *(_DWORD*)&byte_587000[4 * (*a1 + 3 * a1[1]) + 230072]; }

//----- (00509E20) --------------------------------------------------------
int __cdecl sub_509E20(int a1, int2* a2) {
	int v2;     // ecx
	int v3;     // ecx
	int result; // eax

	v2 = *(int*)&byte_587000[8 * a1 + 192088];
	if (v2 <= *(int*)&dword_587000_230092)
		a2->field_0 = (v2 >= -*(int*)&dword_587000_230092) - 1;
	else
		a2->field_0 = 1;
	v3 = *(int*)&byte_587000[8 * a1 + 192092];
	result = dword_587000_230092;
	if (v3 <= *(int*)&dword_587000_230092) {
		result = -*(int*)&dword_587000_230092;
		if (v3 >= -*(int*)&dword_587000_230092)
			a2->field_4 = 0;
		else
			a2->field_4 = -1;
	} else {
		a2->field_4 = 1;
	}
	return result;
}

//----- (00509E90) --------------------------------------------------------
int __cdecl sub_509E90(int a1) { return *(_DWORD*)&byte_587000[4 * a1 + 230056]; }

//----- (00509EA0) --------------------------------------------------------
int __cdecl sub_509EA0(int a1) {
	int2 a2; // [esp+0h] [ebp-8h]

	sub_509E20(a1, &a2);
	return a2.field_4 + a2.field_0 + 2 * a2.field_4 + 4;
}

//----- (00509ED0) --------------------------------------------------------
int __cdecl sub_509ED0(float2* a1) {
	int result; // eax
	float v2;   // [esp+0h] [ebp-4h]

	v2 = (atan2(a1->field_4, a1->field_0) + 6.2831855) * 40.743664 + 0.5;
	result = nox_float2int(v2);
	if (result < 0)
		result += (unsigned int)(255 - result) >> 8 << 8;
	if (result >= 256)
		result += -256 * ((unsigned int)result >> 8);
	return result;
}

//----- (00509F20) --------------------------------------------------------
void __cdecl sub_509F20(float2* a1) {
	double v1; // st7

	v1 = nox_double2float(sqrt(a1->field_0 * a1->field_0 + a1->field_4 * a1->field_4));
	a1->field_0 = a1->field_0 / v1;
	a1->field_4 = a1->field_4 / v1;
}

//----- (00509F60) --------------------------------------------------------
void __cdecl sub_509F60(int a1, int a2) {
	int v2;     // esi
	char v3;    // al
	int v5;     // edi
	_DWORD* v6; // esi

	v2 = *(_DWORD*)(a1 + 748);
	sub_5341A0((char*)&byte_587000[233784], *(_DWORD*)&byte_5D4594[2598000], a2);
	v3 = *(_BYTE*)(v2 + 544);
	if (v3 == -1) {
		sub_5341A0((char*)&byte_587000[233804]);
		sub_5341A0((char*)&byte_587000[233832]);
	} else {
		if (v3 >= 0) {
			v5 = v3 + 1;
			v6 = (_DWORD*)(v2 + 8 * (3 * v3 + 69));
			do {
				sub_5341A0((char*)&byte_587000[233824], *(_DWORD*)&byte_587000[4 * *v6 + 230096]);
				v6 -= 6;
				--v5;
			} while (v5);
		}
		sub_5341A0((char*)&byte_587000[233832]);
	}
}

//----- (00509FF0) --------------------------------------------------------
int __cdecl sub_509FF0(int a1) {
	int result; // eax

	result = a1;
	if (*(_BYTE*)(*(_DWORD*)a1 + 16) & 0x20)
		*(_DWORD*)a1 = 0;
	return result;
}

//----- (0050A010) --------------------------------------------------------
int __cdecl sub_50A010(int a1) {
	int result; // eax

	result = a1 < 39;
	LOBYTE(result) = a1 > 39;
	return result;
}

//----- (0050A020) --------------------------------------------------------
int __cdecl sub_50A020(int a1) {
	return *(_DWORD*)(*(_DWORD*)(a1 + 748) + 24 * (*(char*)(*(_DWORD*)(a1 + 748) + 544) + 23));
}

//----- (0050A040) --------------------------------------------------------
int __cdecl sub_50A040(int a1) {
	int v1; // ebx
	int v2; // esi
	int* i; // edi
	int v4; // eax

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(char*)(v1 + 544) - 1;
	if (v2 < 0)
		return 38;
	for (i = (int*)(v1 + 8 * (3 * v2 + 69));; i -= 6) {
		v4 = sub_50A010(*i);
		if (!v4)
			break;
		if (--v2 < 0)
			return 38;
	}
	return *(_DWORD*)(v1 + 8 * (3 * v2 + 69));
}
// 50A06B: variable 'v4' is possibly undefined

//----- (0050A090) --------------------------------------------------------
int __cdecl sub_50A090(int a1, int a2) {
	int v2;    // ecx
	int v3;    // eax
	_DWORD* i; // ecx

	v2 = *(_DWORD*)(a1 + 748);
	v3 = *(char*)(v2 + 544) - 1;
	if (v3 < 0)
		return 0;
	for (i = (_DWORD*)(v2 + 8 * (3 * v3 + 69)); *i != a2; i -= 6) {
		if (--v3 < 0)
			return 0;
	}
	return 1;
}

//----- (0050A0D0) --------------------------------------------------------
int __cdecl sub_50A0D0(int a1, int a2) {
	int v2;    // ecx
	int v3;    // eax
	_DWORD* i; // ecx

	v2 = *(_DWORD*)(a1 + 748);
	v3 = *(char*)(v2 + 544);
	if (v3 < 0)
		return 0;
	for (i = (_DWORD*)(v2 + 8 * (3 * v3 + 69)); *i != a2; i -= 6) {
		if (--v3 < 0)
			return 0;
	}
	return 1;
}

//----- (0050A110) --------------------------------------------------------
int __cdecl sub_50A110(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 748);
	*(_BYTE*)(result + 481) = 0;
	*(_BYTE*)(result + 482) = 0;
	*(_BYTE*)(result + 483) = 0;
	*(_DWORD*)(result + 8) = 0;
	*(_DWORD*)(result + 268) = 0;
	*(_DWORD*)(result + 296) = 0;
	*(_DWORD*)(result + 364) = 0;
	*(_DWORD*)(result + 548) = *(_DWORD*)&byte_5D4594[2598000];
	*(_DWORD*)(result + 496) = *(_DWORD*)&byte_5D4594[2598000];
	return result;
}

//----- (0050A160) --------------------------------------------------------
char __cdecl sub_50A160(int a1) {
	int v1;                  // esi
	int v2;                  // eax
	int v3;                  // eax
	char v4;                 // al
	_DWORD* v5;              // edi
	int v6;                  // eax
	void(__cdecl * v7)(int); // eax
	char v8;                 // cl
	int v9;                  // edi
	int* v10;                // ebp
	int v11;                 // eax
	char result;             // al
	int v13;                 // [esp-Ch] [ebp-1Ch]
	int v14;                 // [esp-8h] [ebp-18h]
	int v15;                 // [esp-4h] [ebp-14h]

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(char*)(v1 + 544);
	v15 = v2;
	v14 = *(_DWORD*)&byte_587000[4 * *(_DWORD*)(v1 + 8 * (3 * v2 + 69)) + 230096];
	v13 = *(_DWORD*)(a1 + 36);
	v3 = sub_4E39D0(a1);
	sub_5341A0((char*)&byte_587000[233876], *(_DWORD*)&byte_5D4594[2598000], v3, v13, v14, v15);
	v4 = *(_BYTE*)(v1 + 544);
	if (v4 >= 0) {
		v5 = (_DWORD*)(v1 + 24 * (v4 + 23));
		v6 = sub_50A010(*(_DWORD*)(v1 + 24 * (v4 + 23)));
		if (!v6) {
			if (v5[5]) {
				v7 = *(void(__cdecl**)(int)) & byte_587000[16 * *v5 + 233168];
				if (v7)
					v7(a1);
			}
		}
	}
	dword_5d4594_1599692 = 1;
	v8 = *(_BYTE*)(v1 + 544) - 1;
	v9 = v8;
	*(_BYTE*)(v1 + 544) = v8;
	if (v8 >= 0) {
		v10 = (int*)(v1 + 8 * (3 * v8 + 69));
		do {
			v11 = sub_50A010(*v10);
			if (!v11)
				break;
			v10 -= 6;
			--v9;
			--*(_BYTE*)(v1 + 544);
		} while (v9 >= 0);
	}
	sub_50A110(a1);
	result = *(_BYTE*)(v1 + 544);
	if (result < 0) {
		*(_BYTE*)(v1 + 544) = 0;
		*(_DWORD*)(v1 + 552) = 0;
	}
	return result;
}
// 50A1CB: variable 'v6' is possibly undefined
// 50A21D: variable 'v11' is possibly undefined

//----- (0050A260) --------------------------------------------------------
int* __cdecl sub_50A260(int a1, int a2) {
	int v2;                  // esi
	int* result;             // eax
	char v4;                 // cl
	_DWORD* v5;              // edi
	int v6;                  // eax
	void(__cdecl * v7)(int); // eax
	char v8;                 // al
	int* v9;                 // esi
	int v10;                 // eax
	int v11;                 // [esp-8h] [ebp-18h]
	int v12;                 // [esp-4h] [ebp-14h]

	v2 = *(_DWORD*)(a1 + 748);
	if (!(*(_BYTE*)(a1 + 8) & 2))
		return 0;
	v4 = *(_BYTE*)(v2 + 544);
	if (v4 == 23)
		return 0;
	if (v4 < 0)
		goto LABEL_19;
	if (*(_DWORD*)(v2 + 552) == 31 && a2 != 30)
		return 0;
	v5 = (_DWORD*)(v2 + 24 * (v4 + 23));
	if (*(_DWORD*)(v2 + 24 * (v4 + 23)) || v4) {
		v6 = sub_50A010(*(_DWORD*)(v2 + 24 * (v4 + 23)));
		if (!v6 && v5[5]) {
			v7 = *(void(__cdecl**)(int)) & byte_587000[16 * *v5 + 233172];
			if (v7)
				v7(a1);
		}
	} else {
	LABEL_19:
		*(_BYTE*)(v2 + 544) = -1;
	}
	v8 = *(_BYTE*)(v2 + 544) + 1;
	*(_BYTE*)(v2 + 544) = v8;
	v9 = (int*)(v2 + 24 * (v8 + 23));
	*v9 = a2;
	v9[5] = 0;
	sub_50A110(a1);
	v12 = *(_DWORD*)&byte_587000[4 * a2 + 230096];
	v11 = *(_DWORD*)(a1 + 36);
	v10 = sub_4E39D0(a1);
	sub_5341A0((char*)&byte_587000[233916], *(_DWORD*)&byte_5D4594[2598000], v10, v11, v12);
	result = v9;
	dword_5d4594_1599692 = 1;
	return result;
}
// 50A2CD: variable 'v6' is possibly undefined

//----- (0050A360) --------------------------------------------------------
int* __cdecl sub_50A360(int a1, int a2) {
	int* result; // eax

	if (*(_BYTE*)(a1 + 8) & 2 &&
	    *(_DWORD*)(*(_DWORD*)(a1 + 748) + 24 * (*(char*)(*(_DWORD*)(a1 + 748) + 544) + 23)) != a2) {
		result = sub_50A260(a1, a2);
	} else {
		result = 0;
	}
	return result;
}

//----- (0050A3A0) --------------------------------------------------------
void __cdecl sub_50A3A0(int a1) {
	if (*(_BYTE*)(a1 + 8) & 2 && !sub_5341F0(a1)) {
		do
			sub_50A160(a1);
		while (!sub_5341F0(a1));
	}
}

//----- (0050A3D0) --------------------------------------------------------
int __cdecl sub_50A3D0(_DWORD* a1) {
	int v1;     // ebx
	int i;      // edi
	int result; // eax
	int v4;     // ecx
	int v5;     // eax
	int v6;     // eax
	int v7;     // ecx
	int v8;     // edi
	int v9;     // ecx
	int v10;    // eax
	int v11;    // eax
	int v12;    // esi

	v1 = a1[187];
	if (nox_common_gameFlags_check_40A5C0(4096))
		sub_50E1E0((int)a1);
	for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
		if ((_DWORD*)sub_4DDF30(i) == a1)
			sub_4DDEF0(i);
	}
	sub_50A3A0((int)a1);
	sub_50A260((int)a1, 31);
	sub_50A260((int)a1, 30);
	result = sub_534A40((int)a1);
	if (!result) {
		v4 = a1[4];
		LOBYTE(v4) = v4 & 0x7F;
		a1[4] = v4;
		sub_4DA9F0(a1);
		sub_4FF580((int)a1);
		if ((signed char)*(_BYTE*)(v1 + 1440) >= 0) {
			if (!nox_common_gameFlags_check_40A5C0(4096))
				goto LABEL_13;
			v5 = nox_common_randomInt_415FA0(5, 8);
		} else {
			v5 = nox_common_randomInt_415FA0(10, 20);
		}
		sub_511660(a1, *(_DWORD*)&byte_5D4594[2649704] * v5);
	LABEL_13:
		v6 = a1[127];
		if (v6 && *(_BYTE*)(v6 + 8) & 4) {
			v7 = a1[3];
			v8 = *(_DWORD*)(v6 + 748);
			LOBYTE(v7) = v7 & 0x7F;
			a1[3] = v7;
			sub_4D9200(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (int)a1);
			sub_417300(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (int)a1, 1);
		}
		v9 = a1[3];
		BYTE1(v9) &= 0xFEu;
		a1[3] = v9;
		sub_4EC4B0((int)a1);
		sub_4EC300((int)a1);
		v10 = a1[3];
		if (!(v10 & 0x2000))
			sub_4EDA40(a1);
		if (!nox_common_gameFlags_check_40A5C0(2048) && *(_DWORD*)(v1 + 2188) == 2 &&
		    *(_DWORD*)(v1 + 2184) == 2) {
			if (a1[130]) {
				v11 = sub_4EC580(a1[130]);
				if (*(_BYTE*)(v11 + 8) & 4)
					sub_4FC0B0(v11, 1);
			}
		}
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (result) {
			v12 = a1[130];
			if (v12) {
				result = sub_4EC580(v12);
				if (*(_BYTE*)(result + 8) & 4)
					result = sub_4D6170(result);
			}
		}
	}
	return result;
}

//----- (0050A5C0) --------------------------------------------------------
int __cdecl sub_50A5C0(float a1) {
	int v1;                   // esi
	int v2;                   // edi
	char v3;                  // al
	int v4;                   // eax
	int result;               // eax
	int v6;                   // eax
	int v7;                   // eax
	int v8;                   // eax
	unsigned __int16* v9;     // eax
	int v10;                  // ecx
	unsigned __int16 v11;     // cx
	int v12;                  // ecx
	int v13;                  // eax
	int v14;                  // edx
	int v15;                  // ebp
	int v16;                  // edx
	_DWORD* v17;              // eax
	void(__cdecl * v18)(int); // eax
	int v19;                  // ebx
	unsigned __int8 v20;      // cl
	int v21;                  // [esp+14h] [ebp+4h]

	v1 = LODWORD(a1);
	v2 = *(_DWORD*)(LODWORD(a1) + 748);
	v3 = *(_BYTE*)(v2 + 2094);
	if (v3)
		*(_BYTE*)(v2 + 2094) = v3 - 1;
	v4 = *(_DWORD*)(v2 + 2192);
	if (v4 && *(_DWORD*)(v4 + 16) & 0x8020)
		*(_DWORD*)(v2 + 2192) = 0;
	sub_50A910(SLODWORD(a1));
	sub_50CDD0(SLODWORD(a1));
	result = *(_DWORD*)(LODWORD(a1) + 16);
	if (result & 0x1000000) {
		dword_5d4594_1599692 = 0;
		result = *(_DWORD*)(v2 + 484);
		if (result) {
			if (!(*(_DWORD*)(LODWORD(a1) + 16) & 0x8020)) {
				v6 = *(_DWORD*)(v2 + 1440);
				if (v6 & 0x200) {
					v7 = sub_424300(SLODWORD(a1));
					if (v7)
						sub_501960(*(_DWORD*)(v7 + 64), SLODWORD(a1), 0, 0);
					sub_502490((int*)(v2 + 1248), *(_DWORD*)(LODWORD(a1) + 520), SLODWORD(a1));
					sub_5341A0((char*)&byte_587000[234068], *(_DWORD*)&byte_5D4594[2598000],
						   **(unsigned __int16**)(LODWORD(a1) + 556),
						   *(unsigned __int16*)(*(_DWORD*)(LODWORD(a1) + 556) + 4));
				}
				v8 = *(_DWORD*)(v2 + 520);
				if (v8 && (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - v8) >=
					      *(int*)&byte_5D4594[2649704]) {
					sub_532800(SLODWORD(a1));
					*(_DWORD*)(v2 + 520) = 0;
				}
				sub_5469B0(SLODWORD(a1));
			}
			v9 = *(unsigned __int16**)(LODWORD(a1) + 556);
			if (v9) {
				v10 = *(_DWORD*)(LODWORD(a1) + 16);
				if ((v10 & 0x8000) == 0 &&
				    (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(LODWORD(a1) + 536)) >
					*(int*)&byte_5D4594[2649704]) {
					v11 = v9[2];
					if (*v9 < v11 && v11 &&
					    !(*(_DWORD*)&byte_5D4594[2598000] %
					      (180 * *(_DWORD*)&byte_5D4594[2649704] / (unsigned int)v9[2]))) {
						sub_4EE460(SLODWORD(a1), 1);
					}
				}
			}
			sub_5281F0(a1);
			sub_547210(SLODWORD(a1));
			sub_546A70(SLODWORD(a1));
			sub_50A850(SLODWORD(a1));
			v12 = dword_5d4594_1599692;
			v21 = dword_5d4594_1599692;
			while (1) {
				v13 = *(char*)(v2 + 544);
				v14 = 3 * v13 + 69;
				v13 *= 3;
				v15 = *(_DWORD*)(v2 + 8 * v14);
				v16 = *(_DWORD*)(v2 + 8 * v13 + 572);
				v17 = (_DWORD*)(v2 + 8 * v13 + 572);
				if (v16)
					break;
				*v17 = 1;
				dword_5d4594_1599692 = 0;
				v18 = *(void(__cdecl**)(int)) & byte_587000[16 * v15 + 233160];
				if (v18) {
					v18(v1);
					v12 = dword_5d4594_1599692;
					if (dword_5d4594_1599692)
						continue;
				}
				goto LABEL_30;
			}
			if (v12)
				goto LABEL_31;
		LABEL_30:
			dword_5d4594_1599692 = v21;
		LABEL_31:
			(*(void(__cdecl**)(int)) & byte_587000[16 * v15 + 233164])(v1);
			if (dword_5d4594_1599692)
				sub_509F60(v1, (int)&byte_587000[234084]);
			v19 = *(_DWORD*)(v2 + 1440);
			BYTE1(v19) &= 0xFDu;
			*(_DWORD*)(v2 + 1440) = v19;
			sub_421FF0(v1);
			v20 = *(_BYTE*)(v2 + 1128);
			if (v20 < 0x64u)
				*(_BYTE*)(v2 + 1128) = v20 + 0x64u / *(_DWORD*)&byte_5D4594[2649704];
			if (sub_534840(v1))
				sub_534950(v1);
			result = *(_DWORD*)&byte_5D4594[2649704];
			if (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v1 + 536) >
			    (unsigned int)(3 * *(_DWORD*)&byte_5D4594[2649704]))
				*(_DWORD*)(v2 + 1440) &= 0xFFF7FFFF;
		}
	}
	return result;
}

//----- (0050A850) --------------------------------------------------------
char __cdecl sub_50A850(int a1) {
	_BYTE* v1;           // esi
	unsigned __int8* v2; // eax
	unsigned __int8 v3;  // cl
	unsigned __int8 v4;  // cl
	unsigned __int8 v5;  // dl
	unsigned __int8 v6;  // cl

	v1 = *(_BYTE**)(a1 + 748);
	if (*(_BYTE*)(a1 + 12) & 0x10) {
		v2 = *(unsigned __int8**)&v1[24 * (char)v1[544] + 552];
		if (v2 == (unsigned __int8*)16 || v2 == (unsigned __int8*)17) {
			v1[483] = 0;
			return (char)v2;
		}
	}
	LOBYTE(v2) = v1[483];
	if (!(_BYTE)v2) {
		v2 = sub_533D00(a1);
		if (v2) {
			v1[480] = v2[9];
			if (!v2[9])
				goto LABEL_13;
			v3 = v1[482] + 1;
			v1[482] = v3;
			if (v3 >= v2[10] + 1) {
				v4 = v1[481];
				v1[482] = 0;
				v1[481] = ++v4;
				v5 = v4;
				v6 = v2[9];
				if (v5 >= v6) {
					if (*((_DWORD*)v2 + 3)) {
						v1[481] = 0;
						return (char)v2;
					}
					v1[481] = v6 - 1;
				LABEL_13:
					v1[483] = 1;
					return (char)v2;
				}
			}
		}
	}
	return (char)v2;
}

//----- (0050A910) --------------------------------------------------------
int __cdecl sub_50A910(int a1) {
	int v1;     // ecx
	int v2;     // eax
	int result; // eax
	_DWORD* v4; // esi
	int v5;     // edi
	_DWORD* v6; // ebx
	int v7;     // eax
	int v8;     // eax
	int v9;     // ecx
	int v10;    // eax
	int v11;    // ecx
	int v12;    // [esp+0h] [ebp-8h]
	int v13;    // [esp+4h] [ebp-4h]

	v1 = *(_DWORD*)(a1 + 748);
	v12 = v1;
	v2 = *(_DWORD*)(v1 + 1216);
	if (v2 && *(_DWORD*)(v2 + 16) & 0x8020)
		*(_DWORD*)(v1 + 1216) = 0;
	result = *(char*)(v1 + 544);
	if (result >= 0) {
		v4 = (_DWORD*)(v1 + 8 * (3 * result + 69));
		v13 = result + 1;
		while (1) {
			v5 = 0;
			if (*(_DWORD*)&byte_587000[16 * *v4 + 230388] > 0) {
				v6 = v4 + 1;
				do {
					if (*(_DWORD*)&byte_587000[4 * (v5 + 4 * *v4) + 230392] == 1 && *v6)
						sub_509FF0((int)v6);
					++v5;
					v6 += 2;
				} while (v5 < *(int*)&byte_587000[16 * *v4 + 230388]);
				v1 = v12;
			}
			switch (*v4) {
			case 3:
				v7 = v4[3];
				if (v7)
					goto LABEL_26;
				break;
			case 7:
			case 8:
				v10 = v4[3];
				if (v10) {
					if (sub_5370E0(a1, v10, 0) || sub_50A0D0(a1, 3)) {
						v7 = v4[3];
						v11 = *(_DWORD*)(v7 + 56);
						goto LABEL_27;
					}
					v4[3] = 0;
				}
				break;
			case 0xF:
				v7 = *(_DWORD*)(v1 + 1196);
				if (v7) {
				LABEL_26:
					v11 = *(_DWORD*)(v7 + 56);
				LABEL_27:
					v4[1] = v11;
					v4[2] = *(_DWORD*)(v7 + 60);
				}
				break;
			case 0x11:
				v8 = v4[3];
				if (v8 && sub_5370E0(a1, v8, 0)) {
					v9 = v4[3];
					v4[1] = *(_DWORD*)(v9 + 56);
					v4[2] = *(_DWORD*)(v9 + 60);
				}
				break;
			default:
				break;
			}
			v4 -= 6;
			result = --v13;
			if (!v13)
				break;
			v1 = v12;
		}
	}
	return result;
}

//----- (0050AA90) --------------------------------------------------------
int __cdecl sub_50AA90(int a1) {
	int v1;    // edx
	int v2;    // eax
	_DWORD* i; // ecx
	int v5;    // esi

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(char*)(v1 + 544);
	if (v2 < 0)
		return 0;
	for (i = (_DWORD*)(v1 + 8 * (3 * v2 + 69)); *i != 3; i -= 6) {
		if (--v2 < 0)
			return 0;
	}
	v5 = v1 + 24 * v2 + 564;
	if (*(_DWORD*)v5)
		sub_509FF0(v5);
	return *(_DWORD*)v5;
}

//----- (0050AAE0) --------------------------------------------------------
int sub_50AAE0() {
	int v0; // eax

	v0 = sub_4DA790();
	dword_5d4594_1599696 = v0;
	if (!v0)
		return 0;
	while (!(*(_BYTE*)(v0 + 8) & 2)) {
		v0 = sub_4DA7A0(v0);
		dword_5d4594_1599696 = v0;
		if (!v0)
			return 0;
	}
	return v0 + 56;
}

//----- (0050AB10) --------------------------------------------------------
int sub_50AB10() {
	int v0; // eax

	v0 = sub_4DA7A0(*(int*)&dword_5d4594_1599696);
	dword_5d4594_1599696 = v0;
	if (!v0)
		return 0;
	while (!(*(_BYTE*)(v0 + 8) & 2)) {
		v0 = sub_4DA7A0(v0);
		dword_5d4594_1599696 = v0;
		if (!v0)
			return 0;
	}
	return v0 + 56;
}

//----- (0050AB50) --------------------------------------------------------
__int16 __cdecl sub_50AB50(int a1, int a2) {
	__int16 result; // ax

	if (a1 < 0 || a1 >= 256 || a2 < 0 || a2 >= 256)
		result = 0;
	else
		result = *(_WORD*)&byte_5D4594[12 * (a2 + (a1 << 8)) + 1599724];
	return result;
}

//----- (0050AB90) --------------------------------------------------------
int sub_50AB90() {
	int result; // eax

	result = nox_new_alloc_class("VisitNodes", 16, 1024);
	dword_5d4594_2386184 = result;
	if (result) {
		dword_5d4594_2386176 = nox_malloc(0x2000u);
		if (dword_5d4594_2386176) {
			*(_DWORD*)&byte_5D4594[2386172] = 0;
			result = 1;
		} else {
			nox_free_alloc_class(*(LPVOID*)&dword_5d4594_2386184);
			result = 0;
		}
	}
	return result;
}

//----- (0050ABF0) --------------------------------------------------------
void sub_50ABF0() {
	free(*(LPVOID*)&dword_5d4594_2386176);
	nox_free_alloc_class(*(LPVOID*)&dword_5d4594_2386184);
	dword_5d4594_2386184 = 0;
}

//----- (0050AC20) --------------------------------------------------------
int __cdecl sub_50AC20(int a3, _WORD* a2) {
	unsigned __int16* v2; // ecx
	unsigned __int16 v3;  // dx
	unsigned __int16 v4;  // ax
	unsigned __int16 v5;  // dx
	__int16 v6;           // ax
	_DWORD* v7;           // esi
	_WORD* v8;            // edi
	int result;           // eax
	int v10;              // eax
	int v11;              // esi
	int v12;              // esi
	__int16 v13;          // ax
	_WORD* v14;           // edi
	__int16 v15;          // ax
	_WORD* v16;           // edi
	float v17;            // [esp+0h] [ebp-18h]
	float v18;            // [esp+0h] [ebp-18h]
	float v19;            // [esp+0h] [ebp-18h]
	float v20;            // [esp+0h] [ebp-18h]
	int v21;              // [esp+Ch] [ebp-Ch]
	float2 a1;            // [esp+10h] [ebp-8h]

	v2 = (unsigned __int16*)a3;
	v3 = *(_WORD*)(a3 + 2);
	a3 = *(unsigned __int16*)a3;
	v21 = v3;
	if (!(byte_5D4594[12 * (v3 + (a3 << 8)) + 1599724] & 0x3C))
		return 0;
	dword_5d4594_2386152 = 0;
	v4 = *v2;
	v5 = v2[1];
	a1.field_0 = (double)a3 * 23.0;
	v6 = *(_WORD*)&byte_5D4594[12 * (v5 + (v4 << 8)) + 1599724];
	a1.field_4 = (double)v21 * 23.0;
	if (v6 & 0x10) {
		a3 = 2048;
		sub_517B70(&a1, sub_50AE80, (int)&a3);
		if (dword_5d4594_2386152) {
			v7 = (_DWORD*)(*(_DWORD*)(dword_5d4594_2386152 + 700) + 8);
			if (*(int*)(dword_5d4594_2386152 + 700) != -8) {
				if (*(_DWORD*)(dword_5d4594_2386152 + 16) & 0x1000000) {
					v8 = a2;
					*a2 = (__int16)*(int*)v7 / 23;
					result = 1;
					v8[1] = (int)v7[1] / 23;
					return result;
				}
			}
		}
		return 0;
	}
	if (v6 & 0x20) {
		a3 = 1024;
		sub_517B70(&a1, sub_50AE80, (int)&a3);
		v10 = dword_5d4594_2386152;
		if (!dword_5d4594_2386152)
			return 0;
		v11 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386152 + 748) + 12);
		goto LABEL_18;
	}
	if (v6 & 4) {
		a3 = 0x4000;
		sub_517B70(&a1, sub_50AE80, (int)&a3);
		if (dword_5d4594_2386152) {
			v12 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386152 + 748) + 4);
			if (v12) {
				if (*(_DWORD*)(dword_5d4594_2386152 + 16) & 0x1000000) {
					v17 = *(float*)(v12 + 56) * 0.043478262;
					v13 = nox_float2int(v17);
					v14 = a2;
					*a2 = v13;
					v18 = *(float*)(v12 + 60) * 0.043478262;
					v14[1] = nox_float2int(v18);
					return 1;
				}
			}
		}
		return 0;
	}
	if (v6 & 8) {
		a3 = 0x8000;
		sub_517B70(&a1, sub_50AE80, (int)&a3);
		v10 = dword_5d4594_2386152;
		if (dword_5d4594_2386152) {
			v11 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386152 + 748) + 4);
		LABEL_18:
			if (v11 && *(_DWORD*)(v10 + 16) & 0x1000000) {
				v19 = *(float*)(v11 + 56) * 0.043478262;
				v15 = nox_float2int(v19);
				v16 = a2;
				*a2 = v15;
				v20 = *(float*)(v11 + 60) * 0.043478262;
				v16[1] = nox_float2int(v20);
				return 1;
			}
			return 0;
		}
	}
	return 0;
}

//----- (0050AE80) --------------------------------------------------------
void __cdecl sub_50AE80(int a1, int a2) {
	if (*(_DWORD*)(a1 + 8) & *(_DWORD*)a2)
		dword_5d4594_2386152 = a1;
}

//----- (0050AEA0) --------------------------------------------------------
int __cdecl sub_50AEA0(int a1, float2* a2, _DWORD* a3) {
	unsigned __int16* v3; // ecx
	unsigned __int16 v4;  // dx
	unsigned __int16 v5;  // ax
	unsigned __int16 v6;  // dx
	__int16 v7;           // ax
	int v9;               // [esp+0h] [ebp-Ch]
	float2 a1a;           // [esp+4h] [ebp-8h]

	v3 = (unsigned __int16*)a1;
	v4 = *(_WORD*)(a1 + 2);
	a1 = *(unsigned __int16*)a1;
	v9 = v4;
	if (!(byte_5D4594[12 * (v4 + (a1 << 8)) + 1599724] & 0x3C))
		return 0;
	dword_5d4594_2386152 = 0;
	v5 = *v3;
	v6 = v3[1];
	a1a.field_0 = (double)a1 * 23.0;
	v7 = *(_WORD*)&byte_5D4594[12 * (v6 + (v5 << 8)) + 1599724];
	a1a.field_4 = (double)v9 * 23.0;
	if (v7 & 0x10) {
		a1 = 2048;
	} else if (v7 & 0x20) {
		a1 = 1024;
	} else if (v7 & 4) {
		a1 = 0x4000;
	} else if (v7 & 8) {
		a1 = 0x8000;
	}
	sub_517B70(&a1a, sub_50AE80, (int)&a1);
	if (!dword_5d4594_2386152 || !(*(_DWORD*)(dword_5d4594_2386152 + 16) & 0x1000000))
		return 0;
	*a2 = *(float2*)(dword_5d4594_2386152 + 56);
	*a3 = *(_DWORD*)(dword_5d4594_2386152 + 36);
	return 1;
}

//----- (0050B2C0) --------------------------------------------------------
int __cdecl sub_50B2C0(int a1) {
	int v1;               // ebp
	int result;           // eax
	double v3;            // st7
	int v4;               // eax
	double v5;            // st7
	int v6;               // ebx
	int v7;               // esi
	int v8;               // eax
	int v9;               // ecx
	unsigned __int8* v10; // edi
	float* v11;           // esi
	int v12;              // eax
	__int16 v13;          // ax
	float v14;            // [esp+0h] [ebp-74h]
	float v15;            // [esp+0h] [ebp-74h]
	float v16;            // [esp+0h] [ebp-74h]
	float v17;            // [esp+0h] [ebp-74h]
	int v18;              // [esp+14h] [ebp-60h]
	int v19;              // [esp+18h] [ebp-5Ch]
	int v20;              // [esp+1Ch] [ebp-58h]
	float v21;            // [esp+20h] [ebp-54h]
	float v22;            // [esp+24h] [ebp-50h]
	float2 a2;            // [esp+28h] [ebp-4Ch]
	int v24;              // [esp+30h] [ebp-44h]
	char v25[60];         // [esp+38h] [ebp-3Ch]
	int a1a;              // [esp+78h] [ebp+4h]

	v1 = a1;
	result = *(_DWORD*)(a1 + 8);
	if (!(result & 0xC080) && (result & 0x2000 || !(*(_BYTE*)(a1 + 16) & 0x49)) &&
	    (result & 0x2008 || *(_BYTE*)(a1 + 16) & 2)) {
		if (result & 0x10000) {
			qmemcpy(v25, (const void*)(a1 + 172), sizeof(v25));
			if (*(_DWORD*)(a1 + 172) == 2) {
				v3 = *(float*)&byte_587000[234176] + *(float*)(a1 + 176);
				*(float*)(a1 + 176) = v3;
				*(float*)(a1 + 180) = v3 * v3;
			} else if (*(_DWORD*)(a1 + 172) == 3) {
				*(float*)(a1 + 184) =
				    *(float*)&byte_587000[234176] + *(float*)&byte_587000[234176] + *(float*)(a1 + 184);
				*(float*)(a1 + 188) =
				    *(float*)&byte_587000[234176] + *(float*)&byte_587000[234176] + *(float*)(a1 + 188);
				nox_shape_box_calc((nox_shape*)(a1 + 172));
			}
			sub_4E7290(a1);
		}
		v14 = *(float*)(a1 + 232) * 0.043478262;
		v4 = nox_float2int(v14);
		v5 = *(float*)(a1 + 236) * 0.043478262;
		v6 = v4;
		v24 = v4;
		v15 = v5;
		v7 = nox_float2int(v15);
		v16 = *(float*)(a1 + 240) * 0.043478262;
		v19 = nox_float2int(v16);
		v17 = *(float*)(a1 + 244) * 0.043478262;
		v8 = nox_float2int(v17);
		v9 = v7;
		v20 = v8;
		for (a1a = v7; v9 <= v8; a1a = v9) {
			v18 = v6;
			if (v6 <= v19) {
				v10 = &byte_5D4594[12 * (v9 + (v6 << 8)) + 1599724];
				do {
					v11 = (float*)&byte_587000[234108];
					while (1) {
						v21 = (double)v18 * 23.0;
						a2.field_0 = v21 + *(v11 - 1);
						v22 = (double)a1a * 23.0;
						a2.field_4 = v22 + *v11;
						if (sub_547DB0(v1, &a2))
							break;
						v11 += 2;
						if ((int)v11 >= (int)&byte_587000[234180])
							goto LABEL_25;
					}
					*((_DWORD*)v10 - 1) = *(_DWORD*)&byte_5D4594[2386164];
					v12 = *(_DWORD*)(v1 + 8);
					if (v12 & 8 || *(_BYTE*)(v1 + 16) & 2) {
						v13 = *(_WORD*)v10 | 0x100;
						*(_WORD*)v10 = v13;
						if (!(*(_BYTE*)(v1 + 16) & 0x10)) {
							HIBYTE(v13) |= 2u;
							*(_WORD*)v10 = v13;
						}
					} else if (v12 & 0x2000) {
						v10[1] |= 4u;
					}
				LABEL_25:
					++v6;
					v10 += 3072;
					v18 = v6;
				} while (v6 <= v19);
				v9 = a1a;
				v8 = v20;
				v6 = v24;
			}
			++v9;
		}
		result = *(_DWORD*)(v1 + 8);
		if (result & 0x10000) {
			qmemcpy((void*)(v1 + 172), v25, 0x3Cu);
			result = sub_4E7290(v1);
		}
	}
	return result;
}

//----- (0050B500) --------------------------------------------------------
void sub_50B500() { *(_DWORD*)&byte_5D4594[2386168] = 0; }

//----- (0050B510) --------------------------------------------------------
int sub_50B510() {
	int result; // eax

	result = 0;
	*(_DWORD*)&byte_5D4594[2386168] = 0;
	*(_DWORD*)&byte_5D4594[2386172] = 0;
	return result;
}

//----- (0050B520) --------------------------------------------------------
int sub_50B520() {
	int result; // eax
	int i;      // esi

	result = *(_DWORD*)&byte_5D4594[2598000];
	if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)&byte_5D4594[2386172]) >= 0xF) {
		*(_DWORD*)&byte_5D4594[2386172] = *(_DWORD*)&byte_5D4594[2598000];
		++*(_DWORD*)&byte_5D4594[2386164];
		result = sub_4DA790();
		for (i = result; result; i = result) {
			sub_50B2C0(i);
			result = sub_4DA7A0(i);
		}
		*(_DWORD*)&byte_5D4594[2386168] = 1;
	}
	return result;
}

//----- (0050B580) --------------------------------------------------------
int __cdecl sub_50B580(int a1, float4* a3) {
	float v2;   // edx
	bool v3;    // c0
	float v4;   // edx
	float4 a1a; // [esp+0h] [ebp-10h]

	if (a3->field_0 >= (double)a3->field_8) {
		v2 = a3->field_0;
		a1a.field_0 = a3->field_8;
	} else {
		v2 = a3->field_8;
		a1a.field_0 = a3->field_0;
	}
	v3 = a3->field_4 < (double)a3->field_C;
	a1a.field_8 = v2;
	if (v3) {
		v4 = a3->field_C;
		a1a.field_4 = a3->field_4;
	} else {
		v4 = a3->field_4;
		a1a.field_4 = a3->field_C;
	}
	a1a.field_C = v4;
	dword_5d4594_2386156 = 1;
	*(_DWORD*)&byte_5D4594[2386148] = a1;
	sub_517C10(&a1a, (void(__cdecl*)(float*, int))sub_50B600, (int)a3);
	return dword_5d4594_2386156;
}

//----- (0050B600) --------------------------------------------------------
void __cdecl sub_50B600(float* arg0, float4* a1) {
	int v2;    // eax
	int v3;    // eax
	double v4; // st6
	double v5; // st7
	double v6; // st7
	double v7; // st7
	double v8; // st7
	float v9;  // [esp+10h] [ebp-30h]
	float v10; // [esp+14h] [ebp-2Ch]
	float v11; // [esp+1Ch] [ebp-24h]
	float v12; // [esp+20h] [ebp-20h]
	float v13; // [esp+24h] [ebp-1Ch]
	float2 a3; // [esp+28h] [ebp-18h]
	float4 a2; // [esp+30h] [ebp-10h]

	if (dword_5d4594_2386156 && *(float**)&byte_5D4594[2386148] != arg0) {
		v2 = *((_DWORD*)arg0 + 2);
		if (v2 & 6) {
			if (sub_5330C0(*(int*)&byte_5D4594[2386148], (int)arg0))
				return;
		} else if (!(v2 & 0x400008)) {
			return;
		}
		if (!((_BYTE)arg0[4] & 0x48) && (signed char)*((_BYTE*)arg0 + 8) >= 0) {
			v3 = *((_DWORD*)arg0 + 43);
			if (v3 == 2) {
				if (sub_57C8A0(a1, (float2*)arg0 + 7, &a3)) {
					v4 = a3.field_4 - arg0[15];
					if (v4 * v4 + (a3.field_0 - arg0[14]) * (a3.field_0 - arg0[14]) <= arg0[45])
						dword_5d4594_2386156 = 0;
				}
			} else if (v3 == 3) {
				v12 = arg0[48] + arg0[14];
				v5 = arg0[49] + arg0[15];
				a2.field_0 = v12;
				v13 = v5;
				v6 = arg0[50] + arg0[14];
				a2.field_4 = v13;
				v9 = v6;
				v7 = arg0[51] + arg0[15];
				a2.field_8 = v9;
				v10 = v7;
				v8 = arg0[52] + arg0[14];
				a2.field_C = v10;
				v11 = arg0[53] + arg0[15];
				a3.field_0 = arg0[54] + arg0[14];
				a3.field_4 = arg0[55] + arg0[15];
				if (sub_427980(a1, &a2)) {
					dword_5d4594_2386156 = 0;
				} else {
					a2.field_0 = v12;
					a2.field_4 = v13;
					a2.field_8 = v8;
					a2.field_C = v11;
					if (sub_427980(a1, &a2))
						goto LABEL_22;
					a2.field_0 = a3.field_0;
					a2.field_4 = a3.field_4;
					a2.field_8 = v8;
					a2.field_C = v11;
					if (sub_427980(a1, &a2) ||
					    (a2.field_0 = a3.field_0, a2.field_4 = a3.field_4, a2.field_8 = v9,
					     a2.field_C = v10, sub_427980(a1, &a2))) {
					LABEL_22:
						dword_5d4594_2386156 = 0;
					}
				}
			}
		}
	}
}

//----- (0050B810) --------------------------------------------------------
BOOL __cdecl sub_50B810(int a1, float* a2) {
	int v2;      // esi
	int v3;      // edi
	BOOL result; // eax
	float v5;    // [esp+0h] [ebp-10h]
	float v6;    // [esp+0h] [ebp-10h]

	v5 = *a2 * 0.043478262;
	v2 = nox_float2int(v5);
	v6 = a2[1] * 0.043478262;
	v3 = nox_float2int(v6);
	if (sub_50B870(a1, v2, v3))
		result = 0;
	else
		result = sub_50B8A0(a1, v2, v3);
	return result;
}

//----- (0050B870) --------------------------------------------------------
BOOL __cdecl sub_50B870(int a1, int a2, int a3) { return sub_57B630(a1, a2, a3) != -1; }

//----- (0050B8A0) --------------------------------------------------------
BOOL __cdecl sub_50B8A0(int a1, int a2, int a3) {
	BOOL result; // eax

	if (sub_50B950(a1, a2, a3))
		result = 0;
	else
		result = sub_50B8E0(a1, a2, a3) == 0;
	return result;
}

//----- (0050B8E0) --------------------------------------------------------
unsigned int __cdecl sub_50B8E0(int a1, int a2, int a3) {
	int v3;              // esi
	unsigned int v4;     // eax
	int v5;              // ecx
	unsigned int result; // eax

	v3 = 12 * (a3 + (a2 << 8));
	if (*(_DWORD*)&byte_5D4594[v3 + 1599720] != *(_DWORD*)&byte_5D4594[2386164])
		goto LABEL_12;
	HIWORD(v4) = HIWORD(a1);
	v5 = *(_DWORD*)(a1 + 16);
	if (v5 & 0x4000) {
		LOWORD(v4) = *(_WORD*)&byte_5D4594[v3 + 1599724];
		return (v4 >> 9) & 1;
	}
	if (byte_5D4594[v3 + 1599725] & 1)
		return 1;
	if (sub_534020(a1) || !(byte_5D4594[v3 + 1599725] & 4))
	LABEL_12:
		result = 0;
	else
		result = 1;
	return result;
}

//----- (0050B950) --------------------------------------------------------
int __cdecl sub_50B950(int a1, int a2, int a3) {
	int v3;     // ecx
	int result; // eax

	v3 = *(_DWORD*)(a1 + 16);
	if (v3 & 0x4000)
		result = (byte_5D4594[12 * (a3 + (a2 << 8)) + 1599724] >> 1) & 1;
	else
		result = byte_5D4594[12 * (a3 + (a2 << 8)) + 1599724] & 1;
	return result;
}

//----- (0050B9A0) --------------------------------------------------------
int __cdecl sub_50B9A0(int a1, int a2, int a3, float* a4) {
	*(_BYTE*)(*(_DWORD*)(a3 + 748) + 2172) = 0;
	sub_50BA00(0, a3, (float*)(a3 + 56), a4, 0, 0);
	if (dword_5d4594_2386180 > a2 && !dword_5d4594_1599712)
		dword_5d4594_1599712 = 1;
	return sub_50C990(a1, 0, a2);
}

//----- (0050BA00) --------------------------------------------------------
LPVOID __cdecl sub_50BA00(int a1, int a2, float* a3, float* a4, int(__cdecl* a5)(int, int, int), int a6) {
	int v6;                // eax
	double v7;             // st7
	int v8;                // eax
	double v9;             // st7
	LPVOID result;         // eax
	unsigned __int16* v11; // eax
	unsigned __int16 v12;  // cx
	unsigned __int16 v13;  // dx
	unsigned __int16* v14; // ebx
	unsigned __int16* v15; // esi
	int v16;               // edx
	int v17;               // edi
	int v18;               // eax
	int v19;               // edi
	int v20;               // edx
	int v21;               // ecx
	unsigned __int16 v22;  // bp
	int v23;               // ebp
	int v24;               // ebx
	unsigned __int16 v25;  // ax
	int v26;               // ecx
	float v27;             // edx
	float v28;             // eax
	int v29;               // ecx
	int v30;               // edi
	_WORD* v31;            // eax
	unsigned __int16* v32; // eax
	unsigned __int16* v33; // ebp
	unsigned __int16* v34; // esi
	unsigned __int16* v35; // edi
	int v36;               // eax
	int v37;               // eax
	bool v38;              // zf
	int v39;               // eax
	int v40;               // eax
	int v41;               // eax
	int v42;               // eax
	BOOL v43;              // eax
	int v44;               // eax
	unsigned __int16* v45; // esi
	unsigned __int16* v46; // edi
	int v47;               // [esp-4h] [ebp-70h]
	int v48;               // [esp-4h] [ebp-70h]
	int v49;               // [esp-4h] [ebp-70h]
	int v50;               // [esp-4h] [ebp-70h]
	float v51;             // [esp+0h] [ebp-6Ch]
	float v52;             // [esp+0h] [ebp-6Ch]
	float v53;             // [esp+0h] [ebp-6Ch]
	float v54;             // [esp+0h] [ebp-6Ch]
	int v55;               // [esp+0h] [ebp-6Ch]
	int v56;               // [esp+0h] [ebp-6Ch]
	int v57;               // [esp+0h] [ebp-6Ch]
	int v58;               // [esp+0h] [ebp-6Ch]
	int v59;               // [esp+14h] [ebp-58h]
	char v60;              // [esp+18h] [ebp-54h]
	int v61;               // [esp+1Ch] [ebp-50h]
	int i;                 // [esp+20h] [ebp-4Ch]
	BOOL v63;              // [esp+24h] [ebp-48h]
	int v64;               // [esp+28h] [ebp-44h]
	int v65;               // [esp+2Ch] [ebp-40h]
	int v66;               // [esp+30h] [ebp-3Ch]
	int v67;               // [esp+34h] [ebp-38h]
	__int16 v68[2];        // [esp+38h] [ebp-34h]
	int v69;               // [esp+3Ch] [ebp-30h]
	int v70;               // [esp+40h] [ebp-2Ch]
	unsigned __int8* v71;  // [esp+44h] [ebp-28h]
	unsigned __int8* v72;  // [esp+48h] [ebp-24h]
	int v73;               // [esp+4Ch] [ebp-20h]
	int v74;               // [esp+50h] [ebp-1Ch]
	int2 a2a;              // [esp+54h] [ebp-18h]
	float4 v76;            // [esp+5Ch] [ebp-10h]
	unsigned __int16* v77; // [esp+78h] [ebp+Ch]

	v67 = 0;
	v64 = 0;
	v65 = 0;
	v59 = a1 != 0 ? 0 : 999999;
	dword_5d4594_1599712 = 0;
	++dword_5d4594_2386160;
	if (!*(_DWORD*)&byte_5D4594[2386168])
		sub_50B520();
	v51 = *a3 * 0.043478262;
	v6 = nox_float2int(v51);
	v7 = a3[1] * 0.043478262;
	a2a.field_0 = v6;
	v52 = v7;
	a2a.field_4 = nox_float2int(v52);
	sub_50C8D0(a2, &a2a);
	v61 = 0;
	v63 = !sub_50B8A0(a2, a2a.field_0, a2a.field_4);
	if (a5 && !a5(a2, a2a.field_0, a2a.field_4))
		v61 = 1;
	v53 = *a4 * 0.043478262;
	v8 = nox_float2int(v53);
	v9 = a4[1] * 0.043478262;
	v73 = v8;
	v54 = v9;
	v74 = nox_float2int(v54);
	result = *(LPVOID*)&dword_5d4594_2386184;
	if (!dword_5d4594_2386184) {
		dword_5d4594_2386180 = 0;
		dword_5d4594_1599712 = 2;
		return result;
	}
	sub_4144D0(*(_DWORD**)&dword_5d4594_2386184);
	v11 = (unsigned __int16*)nox_alloc_class_new_obj_zero(*(_DWORD**)&dword_5d4594_2386184);
	*v11 = a2a.field_0;
	v11[1] = a2a.field_4;
	v12 = *v11;
	v13 = v11[1];
	*((_DWORD*)v11 + 1) = 0;
	*((_DWORD*)v11 + 2) = 0;
	v14 = v11;
	v66 = 0;
	*(_DWORD*)&byte_5D4594[12 * (v13 + (v12 << 8)) + 1599716] = dword_5d4594_2386160;
	while (2) {
		v15 = v14;
		v14 = 0;
		v77 = 0;
		if (!v15)
			goto LABEL_40;
		while (2) {
			v16 = *v15;
			v17 = v15[1];
			v18 = ((unsigned __int16)v16 - v73) * ((unsigned __int16)v16 - v73) +
			      ((unsigned __int16)v17 - v74) * ((unsigned __int16)v17 - v74);
			if (a1) {
				if (v18 > v59) {
					v67 = (int)v15;
					v59 = ((unsigned __int16)v16 - v73) * ((unsigned __int16)v16 - v73) +
					      ((unsigned __int16)v17 - v74) * ((unsigned __int16)v17 - v74);
				}
			} else {
				if (v18 < v59) {
					v67 = (int)v15;
					v59 = ((unsigned __int16)v16 - v73) * ((unsigned __int16)v16 - v73) +
					      ((unsigned __int16)v17 - v74) * ((unsigned __int16)v17 - v74);
				}
				if (!v63 && !v61 && v16 == v73 && v17 == v74) {
					dword_5d4594_1599712 = 0;
					return (LPVOID)sub_50C320(a2, (int)v15, a4);
				}
			}
			v69 = nox_common_randomInt_415FA0(0, 7);
			for (i = 0; i < 8; ++i) {
				v19 = (i + v69) % 8;
				v20 = *(_DWORD*)&byte_587000[8 * v19 + 234216];
				v21 = *(_DWORD*)&byte_587000[8 * v19 + 234220];
				v22 = *v15;
				v72 = &byte_587000[8 * v19 + 234216];
				v23 = v20 + v22;
				v24 = v21 + v15[1];
				v71 = &byte_587000[8 * v19 + 234220];
				if (v23 < 0 || v23 >= 256 || v24 < 0 || v24 >= 256 ||
				    *(_DWORD*)&byte_5D4594[12 * (v24 + (v23 << 8)) + 1599716] ==
					dword_5d4594_2386160) {
					continue;
				}
				*(_DWORD*)&byte_5D4594[12 * (v24 + (v23 << 8)) + 1599716] =
				    dword_5d4594_2386160;
				if (v23 == v73 && v24 == v74) {
					v25 = v15[1];
					v70 = 23 * *v15 + 11;
					v76.field_0 = (double)v70;
					v26 = 23 * v25;
					v27 = *a4;
					v28 = a4[1];
					v70 = v26 + 11;
					v76.field_8 = v27;
					v76.field_4 = (double)(v26 + 11);
					v76.field_C = v28;
					if (sub_50B580(a2, &v76)) {
						v29 = *(_DWORD*)(a2 + 16);
						if (v29 & 0x4000) {
							if (sub_535250(&v76, 0, 0, 5))
								goto LABEL_31;
						} else if (sub_535250(&v76, 0, 0, 1)) {
						LABEL_31:
							v30 = a2;
							goto LABEL_32;
						}
					}
				}
				if (v19 < 4) {
					v30 = a2;
				} else {
					v60 = ~(*(_WORD*)(a2 + 16) >> 8) & 0xD8 | 0x98;
					sub_57B4D0(a2);
					switch (v19) {
					case 4:
						v36 = (unsigned __int8)sub_57B500(*v15, v15[1] + 1, v60);
						if (v36 != 1 && v36 != 6 && v36 != 10 && v36 != 9 && v36 != 255)
							continue;
						LOBYTE(v37) = sub_57B500(*v15 + 1, v15[1], v60);
						goto LABEL_54;
					case 5:
						v39 = (unsigned __int8)sub_57B500(*v15 - 1, v15[1], v60);
						if (v39 != 1 && v39 != 6 && v39 != 10 && v39 != 9 && v39 != 255)
							continue;
						LOBYTE(v37) = sub_57B500(*v15, v15[1] - 1, v60);
					LABEL_54:
						v37 = (unsigned __int8)v37;
						if ((unsigned __int8)v37 == 1 || v37 == 4 || v37 == 7)
							goto LABEL_86;
						v38 = v37 == 8;
						break;
					case 6:
						v40 = (unsigned __int8)sub_57B500(*v15, v15[1] + 1, v60);
						if (v40 && v40 != 5 && v40 != 9 && v40 != 8 && v40 != 255)
							continue;
						v37 = (unsigned __int8)sub_57B500(*v15 - 1, v15[1], v60);
						if (!v37 || v37 == 3 || v37 == 10)
							goto LABEL_86;
						v38 = v37 == 7;
						break;
					case 7:
						v41 = (unsigned __int8)sub_57B500(*v15 + 1, v15[1], v60);
						if (v41 && v41 != 5 && v41 != 9 && v41 != 8 && v41 != 255)
							continue;
						v42 = (unsigned __int8)sub_57B500(*v15, v15[1] - 1, v60);
						if (v42) {
							if (v42 != 3 && v42 != 10 && v42 != 7 && v42 != 255)
								continue;
						}
						goto LABEL_86;
					default:
						goto LABEL_86;
					}
					if (!v38 && v37 != 255)
						continue;
				LABEL_86:
					v30 = a2;
					if (sub_50B950(a2, *v15, *(_DWORD*)v71 + v15[1]) ||
					    sub_50B950(a2, *(_DWORD*)v72 + *v15, v15[1]))
						continue;
				}
				if (sub_50B870(v30, v23, v24))
					continue;
				if (v73 != v23 || v74 != v24) {
					if (!sub_50C830(v30, v23, v24))
						continue;
				} else if (!sub_50C830(v30, v23, v24)) {
					continue;
				}
				v43 = sub_50B8A0(v30, v23, v24);
				if (v63) {
					if (v43) {
						v64 = 1;
					} else if (!sub_50B950(v30, *v15, v15[1]) && sub_50B950(v30, v23, v24)) {
						continue;
					}
				} else {
					if (!v43)
						continue;
					if (a5) {
						v44 = a5(v30, v23, v24);
						if (v61) {
							if (v44)
								v65 = 1;
						} else if (!v44) {
							continue;
						}
					}
				}
			LABEL_32:
				v31 = nox_alloc_class_new_obj_zero(*(_DWORD**)&dword_5d4594_2386184);
				if (!v31) {
					v55 = *(_DWORD*)(v30 + 36);
					v47 = sub_4E39D0(v30);
					sub_5341A0((char*)&byte_587000[234404], *(_DWORD*)&byte_5D4594[2598000], v47,
						   v55);
				LABEL_130:
					dword_5d4594_1599712 = 1;
					return (LPVOID)sub_50C320(v30, v67, 0);
				}
				*v31 = v23;
				v31[1] = v24;
				*((_DWORD*)v31 + 1) = v15;
				*((_DWORD*)v31 + 2) = v77;
				v77 = v31;
			}
			if (!sub_50AC20((int)v15, v68))
				goto LABEL_38;
			*((_BYTE*)v15 + 12) |= 2u;
			v32 = (unsigned __int16*)nox_alloc_class_new_obj_zero(*(_DWORD**)&dword_5d4594_2386184);
			if (!v32) {
				v30 = a2;
				v56 = *(_DWORD*)(a2 + 36);
				v48 = sub_4E39D0(a2);
				sub_5341A0((char*)&byte_587000[234456], *(_DWORD*)&byte_5D4594[2598000], v48, v56);
				goto LABEL_130;
			}
			*(_DWORD*)v32 = *(_DWORD*)v68;
			*((_DWORD*)v32 + 1) = v15;
			*((_DWORD*)v32 + 2) = v77;
			v77 = v32;
		LABEL_38:
			v15 = (unsigned __int16*)*((_DWORD*)v15 + 2);
			if (v15)
				continue;
			break;
		}
		v14 = v77;
	LABEL_40:
		v33 = 0;
		if (v64) {
			v34 = v14;
			if (v14) {
				do {
					v35 = (unsigned __int16*)*((_DWORD*)v34 + 2);
					if (sub_50B8A0(a2, *v34, v34[1])) {
						v33 = v34;
					} else if (v33) {
						*((_DWORD*)v33 + 2) = *((_DWORD*)v34 + 2);
					} else {
						v14 = (unsigned __int16*)*((_DWORD*)v34 + 2);
					}
					v34 = v35;
				} while (v35);
				v33 = 0;
			}
			v63 = 0;
			v64 = 0;
		}
		if (v65) {
			v45 = v14;
			if (v14) {
				do {
					v46 = (unsigned __int16*)*((_DWORD*)v45 + 2);
					if (a5(a2, *v45, v45[1])) {
						v33 = v45;
					} else if (v33) {
						*((_DWORD*)v33 + 2) = *((_DWORD*)v45 + 2);
					} else {
						v14 = (unsigned __int16*)*((_DWORD*)v45 + 2);
					}
					v45 = v46;
				} while (v46);
			}
			v61 = 0;
			v65 = 0;
		}
		if (v14) {
			if (a6 && v66 >= a6) {
				v58 = *(_DWORD*)(a2 + 36);
				v50 = sub_4E39D0(a2);
				sub_5341A0((char*)&byte_587000[234556], *(_DWORD*)&byte_5D4594[2598000], v50, v58);
				goto LABEL_134;
			}
			++v66;
			continue;
		}
		break;
	}
	v57 = *(_DWORD*)(a2 + 36);
	v49 = sub_4E39D0(a2);
	sub_5341A0((char*)&byte_587000[234508], *(_DWORD*)&byte_5D4594[2598000], v49, v57);
LABEL_134:
	v30 = a2;
	dword_5d4594_1599712 = 2;
	return (LPVOID)sub_50C320(v30, v67, 0);
}

//----- (0050C320) --------------------------------------------------------
int __cdecl sub_50C320(int a1, int a2, _DWORD* a3) {
	int result;           // eax
	unsigned __int16* v4; // edi
	int v5;               // esi
	_DWORD* v6;           // eax
	unsigned __int16* v7; // esi
	int v8;               // ebp
	int v9;               // eax
	char v10;             // cl
	int v11;              // ebx
	int v12;              // ecx
	unsigned __int16 v13; // ax
	int v14;              // edx
	unsigned __int16 v15; // ax
	int v16;              // ecx
	unsigned __int16 v17; // ax
	double v18;           // st7
	double v19;           // st7
	double v20;           // st7
	int v21;              // ecx
	_DWORD* v22;          // eax
	_DWORD* v23;          // edx
	int v24;              // eax
	int v25;              // [esp+Ch] [ebp-1Ch]
	float2 v26;           // [esp+10h] [ebp-18h]
	float4 v27;           // [esp+18h] [ebp-10h]

	result = a1;
	v4 = (unsigned __int16*)a2;
	v5 = *(_DWORD*)(a1 + 748);
	v25 = *(_DWORD*)(a1 + 748);
	if (!a2) {
		dword_5d4594_2386180 = 0;
		return result;
	}
	v6 = a3;
	if (a3) {
		**(_DWORD**)&dword_5d4594_2386176 = *a3;
		*(_DWORD*)(dword_5d4594_2386176 + 4) = v6[1];
	} else if (*(_BYTE*)(a2 + 12) & 2 && sub_50AEA0(a2, &v26, &a1)) {
		**(float**)&dword_5d4594_2386176 = v26.field_0;
		*(float*)(dword_5d4594_2386176 + 4) = v26.field_4;
		if (*(_BYTE*)(v5 + 2172) < 8u)
			*(_DWORD*)(v5 + 4 * (unsigned __int8)(*(_BYTE*)(v5 + 2172))++ + 2140) = a1;
	} else {
		a2 = *v4;
		**(float**)&dword_5d4594_2386176 = (double)a2 * 23.0 + 11.5;
		a2 = v4[1];
		*(float*)(dword_5d4594_2386176 + 4) = (double)a2 * 23.0 + 11.5;
	}
	v7 = (unsigned __int16*)*((_DWORD*)v4 + 1);
	v8 = 1;
	if (v7) {
		while (1) {
			v9 = *v7 - *v4;
			v10 = *((_BYTE*)v7 + 12);
			v11 = v7[1] - v4[1];
			a2 = *v7 - *v4;
			if (!(v10 & 2))
				goto LABEL_19;
			if (!sub_50AEA0((int)v7, &v26, &a1))
				break;
			v12 = v25;
			*(float*)(dword_5d4594_2386176 + 8 * v8) = v26.field_0;
			*(float*)(dword_5d4594_2386176 + 8 * v8 + 4) = v26.field_4;
			if (*(_BYTE*)(v25 + 2172) < 8u) {
				a2 = a2 * a2 + v11 * v11;
				if ((double)a2 > 4761.0)
					goto LABEL_17;
				v13 = v7[1];
				a2 = 23 * *v7 + 11;
				v14 = 23 * v13;
				v15 = *v4;
				v27.field_0 = (double)a2;
				a2 = v14 + 11;
				v16 = 23 * v15;
				v17 = v4[1];
				v27.field_4 = (double)(v14 + 11);
				v27.field_8 = (double)(v16 + 11);
				a2 = 23 * v17 + 11;
				v27.field_C = (double)a2;
				if (!sub_535250(&v27, 0, 0, 1)) {
					v12 = v25;
				LABEL_17:
					*(_DWORD*)(v12 + 4 * (unsigned __int8)(*(_BYTE*)(v12 + 2172))++ + 2140) = a1;
					goto LABEL_38;
				}
			}
		LABEL_38:
			v4 = v7;
			v7 = (unsigned __int16*)*((_DWORD*)v7 + 1);
			++v8;
			if (!v7)
				goto LABEL_39;
		}
		v9 = a2;
	LABEL_19:
		if (v9 <= 0) {
			if (v9 < 0) {
				if (v11 > 0) {
					a2 = *v7;
					*(float*)(dword_5d4594_2386176 + 8 * v8) =
					    (double)a2 * 23.0 + 23.0 - 2.3;
					a2 = v7[1];
					v20 = (double)a2;
				LABEL_29:
					*(float*)(dword_5d4594_2386176 + 8 * v8 + 4) = v20 * 23.0 + 2.3;
					goto LABEL_38;
				}
				if (v11 < 0) {
					a2 = *v7;
					*(float*)(dword_5d4594_2386176 + 8 * v8) =
					    (double)a2 * 23.0 + 23.0 - 2.3;
					a2 = v7[1];
					v18 = (double)a2;
					goto LABEL_37;
				}
				a2 = *v7;
				*(float*)(dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 23.0 - 2.3;
				a2 = v7[1];
				v19 = (double)a2;
				goto LABEL_25;
			}
			if (v11 > 0) {
				a2 = *v7;
				*(float*)(dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 11.5;
				a2 = v7[1];
				v20 = (double)a2;
				goto LABEL_29;
			}
			if (v11 < 0) {
				a2 = *v7;
				*(float*)(dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 11.5;
				a2 = v7[1];
				v18 = (double)a2;
				goto LABEL_37;
			}
		} else {
			if (v11 <= 0) {
				if (v11 < 0) {
					a2 = *v7;
					*(float*)(dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 2.3;
					a2 = v7[1];
					v18 = (double)a2;
				LABEL_37:
					*(float*)(dword_5d4594_2386176 + 8 * v8 + 4) =
					    v18 * 23.0 + 23.0 - 2.3;
					goto LABEL_38;
				}
				a2 = *v7;
				*(float*)(dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 2.3;
				a2 = v7[1];
				v19 = (double)a2;
			LABEL_25:
				*(float*)(dword_5d4594_2386176 + 8 * v8 + 4) = v19 * 23.0 + 11.5;
				goto LABEL_38;
			}
			a2 = *v7;
			*(float*)(dword_5d4594_2386176 + 8 * v8) = (double)a2 * 23.0 + 2.3;
			a2 = v7[1];
			*(float*)(dword_5d4594_2386176 + 8 * v8 + 4) = (double)a2 * 23.0 + 2.3;
		}
		goto LABEL_38;
	}
LABEL_39:
	v21 = 0;
	dword_5d4594_2386180 = v8;
	for (result = v8 / 2; v21 < *(int*)&dword_5d4594_2386180 / 2; result = dword_5d4594_2386180 / 2) {
		v22 = (_DWORD*)(dword_5d4594_2386176 + 8 * v21);
		v23 = (_DWORD*)(dword_5d4594_2386176 + 8 * (v8 - v21) - 8);
		v26 = *(float2*)(dword_5d4594_2386176 + 8 * v21);
		*v22 = *v23;
		v22[1] = v23[1];
		v24 = dword_5d4594_2386180 - v21++;
		*(float*)(dword_5d4594_2386176 + 8 * v24 - 8) = v26.field_0;
		*(float*)(dword_5d4594_2386176 + 8 * v24 - 4) = v26.field_4;
		v8 = dword_5d4594_2386180;
	}
	return result;
}

//----- (0050C830) --------------------------------------------------------
int __cdecl sub_50C830(int a1, int a2, int a3) {
	int v3;    // ecx
	float* v4; // esi
	float2 v6; // [esp+4h] [ebp-8h]
	float v7;  // [esp+10h] [ebp+4h]
	float v8;  // [esp+14h] [ebp+8h]

	v3 = *(_DWORD*)(a1 + 16);
	if (v3 & 0x4000 || sub_534020(a1))
		return 1;
	v4 = (float*)&byte_587000[234188];
	v8 = (double)(23 * a2);
	while (1) {
		v6.field_0 = v8 + *(v4 - 1);
		v7 = (double)(23 * a3);
		v6.field_4 = v7 + *v4;
		if (sub_411160(&v6) == 6)
			break;
		v4 += 2;
		if ((int)v4 >= (int)&byte_587000[234220])
			return 1;
	}
	return 0;
}

//----- (0050C8D0) --------------------------------------------------------
void __cdecl sub_50C8D0(int a1, int2* a2) {
	int v2;         // ecx
	int v3;         // edx
	long double v4; // st7
	float v5;       // [esp+Ch] [ebp-4h]
	float v6;       // [esp+Ch] [ebp-4h]

	if (sub_50B870(a1, a2->field_0, a2->field_4)) {
		v2 = a2->field_0;
		v3 = a2->field_4;
		v5 = (double)v3 * 23.0 + 11.5;
		v4 = *(float*)(a1 + 56) - ((double)a2->field_0 * 23.0 + 11.5);
		v6 = *(float*)(a1 + 60) - v5;
		if (fabs(v6) >= fabs(v4)) {
			if (v6 <= 0.0)
				a2->field_4 = v3 - 1;
			else
				a2->field_4 = v3 + 1;
		} else if (v4 <= 0.0) {
			a2->field_0 = v2 - 1;
		} else {
			a2->field_0 = v2 + 1;
		}
	}
}

//----- (0050C990) --------------------------------------------------------
int __cdecl sub_50C990(int a1, int a2, int a3) {
	int v3;     // ecx
	int v4;     // esi
	int v5;     // eax
	_DWORD* v6; // edi

	v3 = 0;
	if (*(int*)&dword_5d4594_2386180 <= 0)
		return a2;
	v4 = a2;
	v5 = a1 + 8 * a2;
	while (v4 != a3 - 1) {
		++v4;
		v5 += 8;
		v6 = (_DWORD*)(dword_5d4594_2386176 + 8 * v3++);
		*(_DWORD*)(v5 - 8) = *v6;
		*(_DWORD*)(v5 - 4) = v6[1];
		if (v3 >= *(int*)&dword_5d4594_2386180)
			return v4;
	}
	sub_5341A0((char*)&byte_587000[234608]);
	return v4;
}

//----- (0050CA00) --------------------------------------------------------
int __cdecl sub_50CA00(int a1, int a2, int a3, float* a4) {
	*(_BYTE*)(*(_DWORD*)(a3 + 748) + 2172) = 0;
	sub_50BA00(1, a3, (float*)(a3 + 56), a4, sub_50CA60, 6);
	if (dword_5d4594_2386180 > a2 && !dword_5d4594_1599712)
		dword_5d4594_1599712 = 1;
	return sub_50C990(a1, 0, a2);
}

//----- (0050CA60) --------------------------------------------------------
BOOL __cdecl sub_50CA60(int a4, int a2, int a3) {
	float2 a1; // [esp+0h] [ebp-8h]

	*(_DWORD*)&byte_5D4594[1599708] = 0;
	a1.field_0 = (double)a2 * 23.0 + 11.5;
	a1.field_4 = (double)a3 * 23.0 + 11.5;
	sub_517F90(&a1, 100.0, sub_50CAC0, a4);
	return *(_DWORD*)&byte_5D4594[1599708] == 0;
}

//----- (0050CAC0) --------------------------------------------------------
void __cdecl sub_50CAC0(int a1, int a2) {
	if (*(_DWORD*)&byte_5D4594[1599708] != 1) {
		if (sub_5330C0(a2, a1))
			*(_DWORD*)&byte_5D4594[1599708] = 1;
	}
}

//----- (0050CAF0) --------------------------------------------------------
int sub_50CAF0() { return dword_5d4594_1599712; }

//----- (0050CB00) --------------------------------------------------------
int sub_50CB00() { return dword_5d4594_2386180; }

//----- (0050CB10) --------------------------------------------------------
LPVOID sub_50CB10() { return *(LPVOID*)&dword_5d4594_2386176; }

//----- (0050CB20) --------------------------------------------------------
int __cdecl sub_50CB20(int a1, float* a2) {
	int v2;                // eax
	double v3;             // st7
	unsigned __int16* v4;  // eax
	int v5;                // ecx
	unsigned __int16* v6;  // ebp
	int v7;                // esi
	int v8;                // edi
	unsigned __int8* v9;   // ebx
	int v10;               // esi
	int v11;               // edi
	_WORD* v12;            // eax
	float v14;             // [esp+0h] [ebp-24h]
	float v15;             // [esp+0h] [ebp-24h]
	int v16;               // [esp+0h] [ebp-24h]
	int2 a2a;              // [esp+14h] [ebp-10h]
	float2 v18;            // [esp+1Ch] [ebp-8h]
	unsigned __int16* v19; // [esp+2Ch] [ebp+8h]

	++dword_5d4594_2386160;
	v14 = *a2 * 0.043478262;
	v2 = nox_float2int(v14);
	v3 = a2[1] * 0.043478262;
	a2a.field_0 = v2;
	v15 = v3;
	a2a.field_4 = nox_float2int(v15);
	sub_50C8D0(a1, &a2a);
	sub_4144D0(*(_DWORD**)&dword_5d4594_2386184);
	v4 = (unsigned __int16*)nox_alloc_class_new_obj_zero(*(_DWORD**)&dword_5d4594_2386184);
	*v4 = a2a.field_0;
	v4[1] = a2a.field_4;
	v5 = v4[1] + (*v4 << 8);
	*((_DWORD*)v4 + 1) = 0;
	*((_DWORD*)v4 + 2) = 0;
	*(_DWORD*)&byte_5D4594[12 * v5 + 1599716] = dword_5d4594_2386160;
	do {
		v6 = v4;
		v19 = 0;
		if (!v4)
			break;
		do {
			v7 = *v6;
			v8 = v6[1];
			if (byte_5D4594[12 * ((unsigned __int16)v8 + (v7 << 8)) + 1599724] & 0x40 &&
			    !sub_50B870(a1, v7, v8)) {
				v18.field_0 = (double)(23 * v7 + 11);
				v18.field_4 = (double)(23 * v8 + 11);
				return sub_518740(&v18, 0x80u);
			}
			v9 = &byte_587000[234284];
			do {
				v10 = *v6 + *((_DWORD*)v9 - 1);
				v11 = *(_DWORD*)v9 + v6[1];
				if (v10 >= 0 && v10 < 256 && v11 >= 0 && v11 < 256 &&
				    *(_DWORD*)&byte_5D4594[12 * (v11 + (v10 << 8)) + 1599716] !=
					dword_5d4594_2386160) {
					v16 = *(_DWORD*)v9 + v6[1];
					*(_DWORD*)&byte_5D4594[12 * (v11 + (v10 << 8)) + 1599716] =
					    dword_5d4594_2386160;
					if (!sub_50B870(a1, v10, v16)) {
						if (sub_50C830(a1, v10, v11)) {
							v12 = nox_alloc_class_new_obj_zero(
							    *(_DWORD**)&dword_5d4594_2386184);
							if (v12) {
								*v12 = v10;
								v12[1] = v11;
								*((_DWORD*)v12 + 1) = v6;
								*((_DWORD*)v12 + 2) = v19;
								v19 = v12;
							}
						}
					}
				}
				v9 += 8;
			} while ((int)v9 < (int)&byte_587000[234316]);
			v6 = (unsigned __int16*)*((_DWORD*)v6 + 2);
		} while (v6);
		v4 = v19;
	} while (v19);
	return 0;
}

//----- (0050CD30) --------------------------------------------------------
unsigned __int8* sub_50CD30() { return &byte_5D4594[2386196]; }

//----- (0050CD40) --------------------------------------------------------
char* __cdecl sub_50CD40(int a1, int a2, _DWORD* a3) {
	char* result; // eax

	result = (char*)sub_501900(a1);
	if (result) {
		if (dword_5d4594_2386188 || (result = nox_new_alloc_class("MonsterListen", 24, 128),
							(dword_5d4594_2386188 = result) != 0)) {
			result = (char*)sub_534160(a2);
			if (result) {
				result = (char*)nox_alloc_class_new_obj(*(_DWORD**)&dword_5d4594_2386188);
				if (result) {
					*(_DWORD*)result = a1;
					*((_DWORD*)result + 1) = a2;
					*((_DWORD*)result + 2) = *a3;
					*((_DWORD*)result + 3) = a3[1];
					*((_DWORD*)result + 4) = *(_DWORD*)&byte_5D4594[2598000];
					*((_DWORD*)result + 5) = dword_5d4594_2386192;
					dword_5d4594_2386192 = result;
				}
			}
		}
	}
	return result;
}

//----- (0050CDD0) --------------------------------------------------------
unsigned __int8* __cdecl sub_50CDD0(int a1) {
	int v1;                  // ebx
	int v2;                  // edi
	unsigned __int8* result; // eax
	int v4;                  // esi
	unsigned int v5;         // eax
	int v6;                  // ebp
	int v7;                  // eax
	int v8;                  // eax
	int v9;                  // [esp-4h] [ebp-18h]
	int* v10;                // [esp+Ch] [ebp-8h]
	int v11;                 // [esp+10h] [ebp-4h]
	int v12;                 // [esp+18h] [ebp+4h]

	v1 = a1;
	v2 = 0;
	v9 = a1;
	v11 = *(_DWORD*)(a1 + 748);
	v10 = 0;
	v12 = 0;
	result = (unsigned __int8*)sub_528190(v9);
	if (result) {
		result = (unsigned __int8*)sub_534B10(v1);
		if (!result) {
			result = (unsigned __int8*)sub_534B90(v1);
			if (!result) {
				result = (unsigned __int8*)sub_534B60(v1);
				if (!result) {
					v4 = dword_5d4594_2386192;
					if (dword_5d4594_2386192) {
						do {
							v5 = *(_DWORD*)(v4 + 16);
							v6 = *(_DWORD*)(v4 + 20);
							if (*(_DWORD*)&byte_5D4594[2598000] < v5 ||
							    *(_DWORD*)&byte_5D4594[2598000] - v5 > 2) {
								if (v2)
									*(_DWORD*)(v2 + 20) = v6;
								else
									dword_5d4594_2386192 =
									    *(_DWORD*)(v4 + 20);
								sub_414330(*(unsigned int**)&dword_5d4594_2386188,
									   (_QWORD*)v4);
							} else {
								v7 = *(_DWORD*)(v4 + 4);
								if (v7 && *(_BYTE*)(v7 + 16) & 0x20)
									*(_DWORD*)(v4 + 4) = 0;
								if (*(_DWORD*)(v11 + 404) <= *(int*)(v4 + 16)) {
									if (sub_50CF10(v1, v4)) {
										v8 = sub_50D000(v1, v4);
										if (v8 > 0 && v8 > v12) {
											v12 = v8;
											v10 = (int*)v4;
										}
									}
								}
								v2 = v4;
							}
							v4 = v6;
						} while (v6);
						result = (unsigned __int8*)v10;
						if (v10 && ((unsigned int)v10[4] > *(int*)(v11 + 404) ||
							    v12 > *(int*)(v11 + 408)))
							result = sub_50D110(v1, v10, v12);
					}
				}
			}
		}
	}
	return result;
}

//----- (0050CF10) --------------------------------------------------------
BOOL __cdecl sub_50CF10(int a1, int a2) {
	int v2;       // ebx
	int v3;       // edi
	int v4;       // ebp
	int v5;       // eax
	BOOL result;  // eax
	int v7;       // eax
	float v8;     // edx
	struc_19* v9; // eax
	int2 v10;     // [esp+10h] [ebp-8h]
	int v11;      // [esp+1Ch] [ebp+4h]
	char v12;     // [esp+1Ch] [ebp+4h]

	v2 = a1;
	v3 = *(_DWORD*)(a1 + 748);
	v4 = sub_4EC580(*(_DWORD*)(a2 + 4));
	v5 = sub_501900(*(_DWORD*)a2);
	v11 = v5;
	if (*(_DWORD*)(v3 + 404) > *(int*)&byte_5D4594[2598000])
		return 0;
	if (!v4) {
	LABEL_6:
		if (!v5)
			return 0;
		goto LABEL_10;
	}
	if (sub_5330C0(v2, v4)) {
		v5 = v11;
		goto LABEL_6;
	}
	if (!(v11 & 0x10))
		return 0;
LABEL_10:
	v12 = sub_501C00((float*)(a2 + 8), *(_DWORD*)(a2 + 4));
	result = 1;
	if (v12) {
		v7 = nox_float2int(*(float*)(v2 + 56));
		v8 = *(float*)(v2 + 60);
		v10.field_0 = v7;
		v10.field_4 = nox_float2int(v8);
		v9 = sub_4217B0(&v10, 0);
		if (v9) {
			if (v12 != BYTE2(v9->field_0[32]))
				result = 0;
		}
	}
	return result;
}

//----- (0050D000) --------------------------------------------------------
int __cdecl sub_50D000(int a1, int a2) {
	char v2;    // bp
	int v3;     // esi
	int result; // eax
	float v5;   // eax
	float v6;   // edx
	float v7;   // eax
	float v8;   // [esp+0h] [ebp-24h]
	float4 v9;  // [esp+14h] [ebp-10h]

	v2 = sub_501900(*(_DWORD*)a2);
	v3 = sub_501AF0(*(_DWORD*)a2, (float*)(a2 + 8), (float*)(a1 + 56));
	if (!sub_50D0C0(v2, v3))
		return -1;
	v5 = *(float*)(a1 + 56);
	v6 = *(float*)(a2 + 8);
	v9.field_4 = *(float*)(a1 + 60);
	v9.field_0 = v5;
	v7 = *(float*)(a2 + 12);
	v9.field_8 = v6;
	v9.field_C = v7;
	if (!sub_535250(&v9, 0, 0, 5)) {
		v8 = (double)v3 * 0.5;
		v3 = nox_float2int(v8);
	}
	if (sub_50D0C0(v2, v3))
		result = v3;
	else
		result = -1;
	return result;
}

//----- (0050D0C0) --------------------------------------------------------
int __cdecl sub_50D0C0(char a1, int a2) {
	if (a1 & 0x20) {
		if (a2 < *(int*)&byte_587000[234644])
			return 0;
	} else if (a1 & 0x40) {
		if (a2 < *(int*)&byte_587000[234652])
			return 0;
	} else if (a2 < *(int*)&byte_587000[234648]) {
		return 0;
	}
	return 1;
}

//----- (0050D110) --------------------------------------------------------
unsigned __int8* __cdecl sub_50D110(int a1, _DWORD* a2, int a3) {
	_DWORD* v3; // esi
	int v4;     // eax
	int v5;     // eax

	v3 = *(_DWORD**)(a1 + 748);
	v3[97] = *a2;
	v3[101] = *(_DWORD*)&byte_5D4594[2598000];
	v3[102] = a3;
	v4 = a2[1];
	if (v4)
		v3[98] = *(_DWORD*)(v4 + 36);
	else
		v3[98] = 0;
	sub_50D190(a1, a2 + 2, v3 + 99);
	v5 = sub_4EC580(a2[1]);
	return sub_502490(v3 + 320, v5, a1);
}

//----- (0050D190) --------------------------------------------------------
_DWORD* __cdecl sub_50D190(int a1, _DWORD* a2, _DWORD* a3) {
	_DWORD* result; // eax

	result = a2;
	*a3 = *a2;
	a3[1] = a2[1];
	*(_DWORD*)&byte_5D4594[2386196] = *a2;
	*(_DWORD*)&byte_5D4594[2386200] = a2[1];
	return result;
}

//----- (0050D1C0) --------------------------------------------------------
int sub_50D1C0() {
	int result; // eax

	sub_4144D0(*(_DWORD**)&dword_5d4594_2386188);
	result = 0;
	dword_5d4594_2386188 = 0;
	dword_5d4594_2386192 = 0;
	return result;
}

//----- (0050D1E0) --------------------------------------------------------
void sub_50D1E0() {
	if (dword_5d4594_2386188) {
		nox_free_alloc_class(*(LPVOID*)&dword_5d4594_2386188);
		dword_5d4594_2386188 = 0;
	}
	dword_5d4594_2386192 = 0;
}

//----- (0050D210) --------------------------------------------------------
int sub_50D210() { return *(_DWORD*)&byte_5D4594[2386204]; }

//----- (0050D220) --------------------------------------------------------
int __cdecl sub_50D220(int a1, int a2) {
	int result; // eax
	int v3;     // esi
	int v4;     // edi

	result = 0;
	v3 = *(_DWORD*)(a1 + 748);
	v4 = *(_DWORD*)(v3 + 280);
	*(_DWORD*)(v3 + 268) = 0;
	if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - v4) >= 0xA) {
		*(_DWORD*)(v3 + 272) = *(_DWORD*)a2;
		*(_DWORD*)(v3 + 276) = *(_DWORD*)(a2 + 4);
		*(_DWORD*)(v3 + 8) = sub_50B9A0(v3 + 12, 32, a1, (float*)a2);
		result = sub_50CAF0();
		*(_BYTE*)(v3 + 284) = result;
		*(_DWORD*)(v3 + 280) = *(_DWORD*)&byte_5D4594[2598000];
	} else {
		*(_DWORD*)(v3 + 8) = 0;
		*(_BYTE*)(v3 + 284) = 1;
	}
	return result;
}

//----- (0050D2A0) --------------------------------------------------------
int __cdecl sub_50D2A0(int a1, int a2) {
	_DWORD* v2; // esi
	int result; // eax

	v2 = *(_DWORD**)(a1 + 748);
	v2[92] = *(_DWORD*)a2;
	v2[93] = *(_DWORD*)(a2 + 4);
	result = sub_547F20(a1, (float*)a2);
	v2[74] = result;
	v2[91] = 0;
	return result;
}

//----- (0050D2E0) --------------------------------------------------------
BOOL __cdecl sub_50D2E0(int a1) {
	int v1;     // esi
	int v2;     // edi
	int v3;     // edx
	int v4;     // ecx
	double v5;  // st7
	double v6;  // st6
	_DWORD* v8; // edi
	int v9;     // eax

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(_DWORD*)(v1 + 296);
	if (v2 && !*(_DWORD*)(v1 + 8)) {
		v3 = *(_DWORD*)(v1 + 364);
		v4 = *(_DWORD*)(v1 + 4 * v3 + 300);
		v5 = *(float*)(v4 + 8) - *(float*)(a1 + 56);
		v6 = *(float*)(v4 + 12) - *(float*)(a1 + 60);
		if (v6 * v6 + v5 * v5 < 64.0) {
			if (v3 == v2 - 1) {
				*(_DWORD*)(v1 + 296) = 0;
				return 1;
			}
			*(_DWORD*)(v1 + 364) = v3 + 1;
			v4 = *(_DWORD*)(v1 + 4 * (v3 + 1) + 300);
		}
		v8 = (_DWORD*)(v4 + 8);
		sub_50D220(a1, v4 + 8);
		if (!*(_BYTE*)(v1 + 284)) {
			v9 = *(_DWORD*)(v1 + 8);
			*(_DWORD*)(v1 + 8 * v9 + 4) = *v8;
			*(_DWORD*)(v1 + 8 * v9 + 8) = v8[1];
		}
	}
	return sub_50D3B0((float*)a1) && *(_BYTE*)(v1 + 284) == 2;
}

//----- (0050D3B0) --------------------------------------------------------
int __cdecl sub_50D3B0(float* a1) {
	int v1;      // esi
	int v2;      // ebp
	float v3;    // edx
	int v4;      // edi
	float* v5;   // ebx
	double v6;   // st7
	double v7;   // st6
	double v8;   // st5
	float* v10;  // edi
	double v11;  // st7
	double v12;  // st7
	__int16 v13; // ax
	int v14;     // eax
	double v15;  // st7
	float* v16;  // [esp+10h] [ebp-2Ch]
	float v17;   // [esp+14h] [ebp-28h]
	float* v18;  // [esp+18h] [ebp-24h]
	int v19;     // [esp+1Ch] [ebp-20h]
	float v20;   // [esp+1Ch] [ebp-20h]
	float v21;   // [esp+20h] [ebp-1Ch]
	float2 v22;  // [esp+24h] [ebp-18h]
	float4 v23;  // [esp+2Ch] [ebp-10h]
	float v24;   // [esp+40h] [ebp+4h]

	v1 = *((_DWORD*)a1 + 187);
	v2 = 0;
	if (*(_DWORD*)(v1 + 8)) {
		v3 = a1[15];
		v23.field_0 = a1[14];
		v23.field_4 = v3;
		v4 = *(_DWORD*)(v1 + 268);
		v16 = 0;
		v18 = 0;
		v19 = 0;
		v17 = 10000000.0;
		if (v4 >= *(int*)(v1 + 8)) {
		LABEL_14:
			*(_DWORD*)(v1 + 8) = 0;
			return 0;
		}
		v5 = (float*)(v1 + 8 * v4 + 12);
		do {
			v23.field_8 = *v5;
			v23.field_C = v5[1];
			if (sub_535250(&v23, 0, 0, 132)) {
				v6 = v23.field_8 - a1[14];
				v7 = v23.field_C - a1[15];
				v8 = v7 * v7 + v6 * v6;
				if (v8 > 64.0) {
					if (!v16 || v17 > v8) {
						v17 = v8;
						v16 = v5;
						v2 = v4;
					}
				} else {
					if (v4 == *(_DWORD*)(v1 + 8) - 1) {
						*(_DWORD*)(v1 + 8) = 0;
						return 1;
					}
					v18 = v5;
					v19 = v4;
				}
			}
			++v4;
			v5 += 2;
		} while (v4 < *(int*)(v1 + 8));
		if (!v16) {
			if (!v18)
				goto LABEL_14;
			v2 = v19;
		}
		v10 = a1;
		*(_DWORD*)&byte_5D4594[2386204] = v2;
		*(_DWORD*)(v1 + 268) = v2;
		v20 = *(float*)(v1 + 8 * v2 + 12) - a1[14];
		v11 = *(float*)(v1 + 8 * v2 + 16) - a1[15];
		v21 = v11;
		v24 = sqrt(v11 * v21 + v20 * v20) + *(double*)&byte_581450[10288];
		if (v2 <= 0) {
			v22.field_0 = *(float*)(v1 + 20) - *(float*)(v1 + 12);
			v12 = *(float*)(v1 + 24) - *(float*)(v1 + 16);
		} else {
			v22.field_0 = *(float*)(v1 + 8 * v2 + 12) - *(float*)(v1 + 8 * v2 + 4);
			v12 = *(float*)(v1 + 8 * v2 + 16) - *(float*)(v1 + 8 * v2 + 8);
		}
		v22.field_4 = v12;
		v13 = sub_509ED0(&v22);
		*((_WORD*)v10 + 62) = v13;
		*((_WORD*)v10 + 63) = v13;
		v14 = *(_DWORD*)(v1 + 1440);
		if (v14 & 0x4000)
			v15 = *(float*)(*(_DWORD*)(v1 + 484) + 96) * v10[136];
		else
			v15 = v10[136];
		v10[22] = v15 * v20 / v24;
		v10[23] = v15 * v21 / v24;
	}
	return 0;
}

//----- (0050D5A0) --------------------------------------------------------
int __cdecl sub_50D5A0(int a1) {
	int v1;     // esi
	double v2;  // st7
	float* v3;  // edi
	double v4;  // st6
	float v6;   // edx
	char v7;    // al
	bool v8;    // zf
	int v9;     // eax
	double v10; // st7
	double v11; // st6
	double v12; // st7
	double v13; // st6
	float4 v14; // [esp+Ch] [ebp-10h]

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(float*)(v1 + 24 * *(char*)(v1 + 544) + 556) - *(float*)(a1 + 56);
	v3 = (float*)(v1 + 24 * *(char*)(v1 + 544) + 556);
	v4 = *(float*)(v1 + 24 * *(char*)(v1 + 544) + 560) - *(float*)(a1 + 60);
	if (sqrt(v4 * v4 + v2 * v2) + *(double*)&byte_581450[10288] <= 8.0)
		return 1;
	v6 = *(float*)(a1 + 60);
	v14.field_0 = *(float*)(a1 + 56);
	v14.field_4 = v6;
	v14.field_8 = *v3;
	v7 = (*(_DWORD*)(a1 + 16) >> 12) & 4;
	v14.field_C = v3[1];
	v8 = sub_535250(&v14, 0, 0, v7) == 0;
	v9 = *(_DWORD*)(v1 + 8);
	if (v8) {
		if (!v9) {
			if (!*(_DWORD*)(v1 + 296) ||
			    (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v1 + 280)) > 0xA &&
				(v12 = *(float*)(v1 + 368) - *v3, v13 = *(float*)(v1 + 372) - v3[1],
				 v13 * v13 + v12 * v12 > 10000.0)) {
				sub_50D2A0(a1, (int)v3);
			}
			if (*(_DWORD*)(v1 + 296)) {
			LABEL_16:
				if (sub_50D2E0(a1)) {
					*(_DWORD*)(v1 + 8) = 0;
					*(_DWORD*)(v1 + 296) = 0;
					return 1;
				}
				return 0;
			}
			sub_5341A0((char*)&byte_587000[234672]);
			sub_50D220(a1, (int)v3);
		}
	} else if (!v9 || (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v1 + 280)) > 0xA &&
			      (v10 = *(float*)(v1 + 272) - *v3, v11 = *(float*)(v1 + 276) - v3[1],
			       v11 * v11 + v10 * v10 > 2500.0)) {
		sub_50D220(a1, (int)v3);
	}
	if (*(_DWORD*)(v1 + 296))
		goto LABEL_16;
	if (*(_DWORD*)(v1 + 8) && sub_50D3B0((float*)a1)) {
		*(_DWORD*)(v1 + 8) = 0;
		return 1;
	}
	return 0;
}

//----- (0050D780) --------------------------------------------------------
int sub_50D780() {
	int result; // eax

	result = nox_new_alloc_class("SpawnClass", 12, 96);
	dword_5d4594_2386216 = result;
	if (result) {
		dword_5d4594_2386212 = 0;
		result = nox_new_alloc_class("MonsterListClass", 148, 96);
		dword_5d4594_2386220 = result;
		if (result) {
			dword_5d4594_2386224 = 0;
			dword_5d4594_2386228 = 0;
			result = 1;
		}
	}
	return result;
}

//----- (0050D7E0) --------------------------------------------------------
void sub_50D7E0() {
	sub_4144D0(*(_DWORD**)&dword_5d4594_2386216);
	dword_5d4594_2386212 = 0;
	sub_4144D0(*(_DWORD**)&dword_5d4594_2386220);
	dword_5d4594_2386224 = 0;
	dword_5d4594_2386228 = 0;
}

//----- (0050D820) --------------------------------------------------------
void sub_50D820() {
	nox_free_alloc_class(*(LPVOID*)&dword_5d4594_2386216);
	dword_5d4594_2386216 = 0;
	dword_5d4594_2386212 = 0;
	nox_free_alloc_class(*(LPVOID*)&dword_5d4594_2386220);
	dword_5d4594_2386220 = 0;
	dword_5d4594_2386224 = 0;
	dword_5d4594_2386228 = 0;
}

//----- (0050D860) --------------------------------------------------------
int __cdecl sub_50D860(int a1, int a2) {
	if (*(float*)(a1 + 4) == *(float*)(a2 + 4))
		return 0;
	if (*(float*)(a1 + 4) <= (double)*(float*)(a2 + 4))
		return -1;
	return 1;
}

//----- (0050D8D0) --------------------------------------------------------
void sub_50D8D0() {
	int* v0; // edi
	int* v1; // ebp
	int v2;  // ebx
	int v3;  // esi
	int v4;  // eax

	v0 = *(int**)&dword_5d4594_2386212;
	if (dword_5d4594_2386212) {
		do {
			v1 = (int*)v0[1];
			v2 = 1;
			v3 = sub_4DA7C0();
			if (!v3)
				goto LABEL_13;
			do {
				v4 = *(_DWORD*)(v3 + 748);
				if (*(_DWORD*)(*(_DWORD*)(v4 + 276) + 4792) == 1 && !*(_DWORD*)(v4 + 312) &&
				    sub_4E6C00(v3, *v0) < 700.0)
					v2 = 0;
				v3 = sub_4DA7F0(v3);
			} while (v3);
			if (v2 == 1)
			LABEL_13:
				sub_4E5CC0(*v0);
			v0 = v1;
		} while (v1);
	}
}

//----- (0050D960) --------------------------------------------------------
int sub_50D960() {
	int v0;               // ebx
	int v1;               // edi
	int v2;               // eax
	int* v3;              // ebp
	int v4;               // ecx
	_DWORD* v5;           // esi
	_DWORD* v6;           // eax
	int v7;               // eax
	int i;                // edx
	double v9;            // st7
	int v10;              // edi
	float* v11;           // ecx
	int v12;              // esi
	int j;                // edx
	int k;                // ecx
	int v15;              // ebx
	int v16;              // eax
	int v17;              // eax
	int v18;              // eax
	int v19;              // esi
	int v20;              // edi
	int v21;              // eax
	int v22;              // esi
	int v23;              // ebp
	int v24;              // edx
	unsigned __int8* v25; // eax
	int* v26;             // esi
	int* v27;             // ebx
	char v28;             // cl
	unsigned __int8* v29; // eax
	int v30;              // eax
	int v31;              // eax
	int v32;              // eax
	float v34;            // [esp+0h] [ebp-40h]
	int v35;              // [esp+14h] [ebp-2Ch]
	int v36;              // [esp+18h] [ebp-28h]
	int v37;              // [esp+18h] [ebp-28h]
	float4 a2;            // [esp+20h] [ebp-20h]
	float4 v39;           // [esp+30h] [ebp-10h]

	v34 = sub_419D40(&byte_587000[234752]);
	v35 = nox_float2int(v34);
	v36 = 0;
	memset(&byte_5D4594[2386232], 0, 0x80u);
	v0 = sub_4DA7C0();
	if (v0) {
		do {
			v1 = *(_DWORD*)(v0 + 748);
			*(_DWORD*)&byte_5D4594[4 * *(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + 2386232] = 0;
			v2 = *(_DWORD*)(v1 + 276);
			if (*(_DWORD*)(v2 + 4792)) {
				v3 = *(int**)&dword_5d4594_2386212;
				a2.field_0 = *(float*)(v0 + 56) - (double)*(unsigned __int16*)(v2 + 10) - 100.0;
				a2.field_4 = *(float*)(v0 + 60) -
					     (double)*(unsigned __int16*)(*(_DWORD*)(v1 + 276) + 12) - 100.0;
				a2.field_8 = (double)*(unsigned __int16*)(*(_DWORD*)(v1 + 276) + 10) +
					     *(float*)(v0 + 56) + 100.0;
				a2.field_C = (double)*(unsigned __int16*)(*(_DWORD*)(v1 + 276) + 12) +
					     *(float*)(v0 + 60) + 100.0;
				if (dword_5d4594_2386212) {
					do {
						if (sub_428220((float2*)(*v3 + 56), &a2)) {
							v39.field_0 = *(float*)(v0 + 56);
							v39.field_4 = *(float*)(v0 + 60);
							v4 = *v3;
							v39.field_8 = *(float*)(*v3 + 56);
							v39.field_C = *(float*)(v4 + 60);
							if (sub_535250(&v39, 0, 0, 69)) {
								v5 = sub_50DE60(*v3);
								if (!v5) {
									v6 = nox_alloc_class_new_obj_zero(
									    *(_DWORD**)&dword_5d4594_2386220);
									v5 = v6;
									if (!v6)
										break;
									v6[35] = dword_5d4594_2386224;
									if (dword_5d4594_2386224)
										*(_DWORD*)(dword_5d4594_2386224 +
											   144) = v6;
									dword_5d4594_2386224 = v6;
									++dword_5d4594_2386228;
									*v6 = *v3;
								}
								v5[2] |= 1 << *(_BYTE*)(*(_DWORD*)(v1 + 276) + 2064);
								v7 = *(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064);
								++*(_DWORD*)&byte_5D4594[4 * v7 + 2386232];
								if (*(_DWORD*)&byte_5D4594
									[4 * *(unsigned __int8*)(*(_DWORD*)(v1 + 276) +
												 2064) +
									 2386232] > v35)
									v36 = 1;
								*(float*)&v5[*(unsigned __int8*)(*(_DWORD*)(v1 + 276) +
												 2064) +
									     3] = sub_4E6C00(*v3, v0);
							}
						}
						v3 = (int*)v3[1];
					} while (v3);
				}
			}
			v0 = sub_4DA7F0(v0);
		} while (v0);
		if (v36) {
			for (i = dword_5d4594_2386224; i; i = *(_DWORD*)(i + 140)) {
				v9 = 0.0;
				v10 = 0;
				v11 = (float*)(i + 12);
				v12 = 32;
				do {
					if (*v11 != 0.0) {
						v9 = v9 + *v11;
						++v10;
					}
					++v11;
					--v12;
				} while (v12);
				*(float*)(i + 4) = v9 / (double)v10;
			}
			for (j = dword_5d4594_2386224; j; j = *(_DWORD*)(j + 140)) {
				for (k = *(_DWORD*)(j + 140); k; k = *(_DWORD*)(k + 140)) {
					if (*(float*)(k + 4) > (double)*(float*)(j + 4)) {
						v15 = *(_DWORD*)(j + 140);
						if (v15 == k) {
							v16 = *(_DWORD*)(j + 144);
							*(_DWORD*)(k + 144) = v16;
							if (v16)
								*(_DWORD*)(v16 + 140) = k;
							v17 = *(_DWORD*)(k + 140);
							*(_DWORD*)(j + 140) = v17;
							if (v17)
								*(_DWORD*)(v17 + 144) = j;
							*(_DWORD*)(j + 144) = k;
							*(_DWORD*)(k + 140) = j;
						} else {
							v18 = *(_DWORD*)(j + 144);
							v19 = *(_DWORD*)(k + 140);
							v20 = *(_DWORD*)(k + 144);
							if (v18)
								*(_DWORD*)(v18 + 140) = k;
							if (v20)
								*(_DWORD*)(v20 + 140) = j;
							if (v15)
								*(_DWORD*)(v15 + 144) = k;
							if (v19)
								*(_DWORD*)(v19 + 144) = j;
							*(_DWORD*)(j + 144) = v20;
							*(_DWORD*)(j + 140) = v19;
							*(_DWORD*)(k + 144) = v18;
							*(_DWORD*)(k + 140) = v15;
						}
						if (j == dword_5d4594_2386224)
							dword_5d4594_2386224 = k;
						v21 = k;
						k = j;
						j = v21;
					}
				}
			}
			while (1) {
				v22 = 0;
				v23 = 0;
				v24 = 0;
				v25 = &byte_5D4594[2386232];
				do {
					if (*(_DWORD*)v25 > v22) {
						v22 = *(_DWORD*)v25;
						v23 = v24;
					}
					v25 += 4;
					++v24;
				} while ((int)v25 < (int)&byte_5D4594[2386360]);
				if (v22 <= v35)
					break;
				v26 = *(int**)&dword_5d4594_2386224;
				v37 = 1;
				if (dword_5d4594_2386224) {
					do {
						if (v37 != 1)
							break;
						v27 = (int*)v26[35];
						if (v26[2] & (1 << v23)) {
							sub_4E5CC0(*v26);
							v28 = 0;
							v29 = &byte_5D4594[2386232];
							do {
								if ((1 << v28) & v26[2])
									--*(_DWORD*)v29;
								v29 += 4;
								++v28;
							} while ((int)v29 < (int)&byte_5D4594[2386360]);
							v30 = v26[35];
							if (v30)
								*(_DWORD*)(v30 + 144) = v26[36];
							v31 = v26[36];
							if (v31)
								*(_DWORD*)(v31 + 140) = v26[35];
							else
								dword_5d4594_2386224 = v26[35];
							sub_414330(*(unsigned int**)&dword_5d4594_2386220, v26);
							v32 = *(_DWORD*)&byte_5D4594[4 * v23 + 2386232];
							--dword_5d4594_2386228;
							if (v32 <= v35)
								v37 = 0;
						}
						v26 = v27;
					} while (v27);
				}
			}
		}
	}
	return sub_50DE10();
}

//----- (0050DE10) --------------------------------------------------------
int sub_50DE10() {
	int result; // eax
	int v1;     // esi

	result = dword_5d4594_2386224;
	if (dword_5d4594_2386224) {
		do {
			v1 = *(_DWORD*)(result + 140);
			sub_414330(*(unsigned int**)&dword_5d4594_2386220, (_QWORD*)result);
			result = v1;
			--dword_5d4594_2386228;
		} while (v1);
		dword_5d4594_2386224 = 0;
	} else {
		dword_5d4594_2386224 = 0;
	}
	return result;
}

//----- (0050DE60) --------------------------------------------------------
_DWORD* __cdecl sub_50DE60(int a1) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_2386224;
	if (!dword_5d4594_2386224)
		return 0;
	while (*result != a1) {
		result = (_DWORD*)result[35];
		if (!result)
			return 0;
	}
	return result;
}

//----- (0050DE80) --------------------------------------------------------
int __cdecl sub_50DE80(int a1, float* a2) {
	int v2;     // edi
	int v3;     // esi
	int v4;     // eax
	int v5;     // ecx
	float v7;   // [esp+0h] [ebp-20h]
	float4 a2a; // [esp+10h] [ebp-10h]

	v7 = sub_419D40(&byte_587000[234776]);
	v2 = nox_float2int(v7);
	v3 = sub_4DA7C0();
	if (!v3)
		return 1;
	while (1) {
		v4 = *(_DWORD*)(v3 + 748);
		v5 = *(_DWORD*)(v4 + 276);
		if (*(_DWORD*)(v5 + 4792)) {
			a2a.field_0 = *(float*)(v3 + 56) - (double)*(unsigned __int16*)(v5 + 10) - 100.0;
			a2a.field_4 =
			    *(float*)(v3 + 60) - (double)*(unsigned __int16*)(*(_DWORD*)(v4 + 276) + 12) - 100.0;
			a2a.field_8 =
			    (double)*(unsigned __int16*)(*(_DWORD*)(v4 + 276) + 10) + *(float*)(v3 + 56) + 100.0;
			a2a.field_C =
			    (double)*(unsigned __int16*)(*(_DWORD*)(v4 + 276) + 12) + *(float*)(v3 + 60) + 100.0;
			if (sub_428220((float2*)a2, &a2a)) {
				*(_DWORD*)&byte_5D4594[2386208] = 0;
				sub_517C10(&a2a, sub_50DFB0, v3);
				if (*(_DWORD*)&byte_5D4594[2386208] >= v2)
					break;
			}
		}
		v3 = sub_4DA7F0(v3);
		if (!v3)
			return 1;
	}
	return 0;
}

//----- (0050DFB0) --------------------------------------------------------
void __cdecl sub_50DFB0(float* a1, int a2) {
	float v2;  // ecx
	float v3;  // eax
	float v4;  // ecx
	float4 v5; // [esp+4h] [ebp-10h]

	if ((_BYTE)a1[2] & 2 && !((_DWORD)a1[4] & 0x20) &&
	    (((_DWORD)a1[4] & 0x8000) != 0x8000 || sub_534A40((int)a1))) {
		v2 = *(float*)(a2 + 56);
		v3 = a1[14];
		v5.field_4 = *(float*)(a2 + 60);
		v5.field_0 = v2;
		v4 = a1[15];
		v5.field_8 = v3;
		v5.field_C = v4;
		if (sub_535250(&v5, 0, 0, 69) == 1)
			++*(_DWORD*)&byte_5D4594[2386208];
	}
}

//----- (0050E030) --------------------------------------------------------
int __cdecl sub_50E030(int a1, _DWORD* a2) {
	int v2;      // ebp
	_DWORD* v3;  // esi
	int result;  // eax
	_DWORD* v5;  // edi
	int v6;      // eax
	_DWORD* v7;  // eax
	int v8;      // ecx
	int* v9;     // edx
	_DWORD* v10; // edi
	int v11;     // esi
	int v12;     // ebp
	_DWORD* v13; // edx
	int v14;     // esi

	v2 = *(_DWORD*)(a1 + 748);
	v3 = (_DWORD*)a2[187];
	if (!v3[549]) {
		result = nox_alloc_class_new_obj_zero(*(_DWORD**)&dword_5d4594_2386216);
		v5 = (_DWORD*)result;
		if (!result)
			return result;
		sub_50E110(result);
		*v5 = a2;
		++*(_BYTE*)(v2 + 86);
		v3[549] = v5;
		v3[548] = a1;
		v6 = a2[3];
		if (v6 & 0x2000) {
			v7 = sub_4E3810((CHAR*)&byte_587000[234800]);
			if (v7) {
				v8 = v7[173];
				v9 = v3 + 511;
				v10 = (_DWORD*)v7[173];
				v11 = 3;
				do {
					v12 = *v9;
					++v9;
					*v10 = v12;
					++v10;
					--v11;
				} while (v11);
				*(_DWORD*)(v8 + 24) = 0;
				*(_DWORD*)(v8 + 28) = a2[14];
				*(_DWORD*)(v8 + 32) = a2[15];
				*(_BYTE*)(v8 + 20) = 0;
				v13 = (_DWORD*)v8;
				v14 = 3;
				do {
					if (*v13)
						++*(_BYTE*)(v8 + 20);
					++v13;
					--v14;
				} while (v14);
			}
			sub_4F3070((int)a2, (int)v7, 1);
		}
	}
	return 1;
}

//----- (0050E110) --------------------------------------------------------
int __cdecl sub_50E110(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 8) = 0;
	*(_DWORD*)(a1 + 4) = dword_5d4594_2386212;
	if (dword_5d4594_2386212)
		*(_DWORD*)(dword_5d4594_2386212 + 8) = a1;
	dword_5d4594_2386212 = a1;
	return result;
}

//----- (0050E140) --------------------------------------------------------
void __cdecl sub_50E140(int a1) {
	int v1; // esi
	int v2; // eax

	if (a1) {
		v1 = *(_DWORD*)(a1 + 748);
		v2 = *(_DWORD*)(v1 + 2192);
		if (v2) {
			--*(_BYTE*)(*(_DWORD*)(v2 + 748) + 86);
			*(_DWORD*)(v1 + 2192) = 0;
		}
		if (*(_DWORD*)(v1 + 2196)) {
			sub_50E1B0(*(_DWORD*)(v1 + 2196));
			sub_414330(*(unsigned int**)&dword_5d4594_2386216, *(_QWORD**)(v1 + 2196));
			*(_DWORD*)(v1 + 2196) = 0;
		}
	}
}

//----- (0050E1B0) --------------------------------------------------------
int __cdecl sub_50E1B0(int a1) {
	int result; // eax
	int v2;     // ecx
	int v3;     // ecx

	result = a1;
	v2 = *(_DWORD*)(a1 + 4);
	if (v2)
		*(_DWORD*)(v2 + 8) = *(_DWORD*)(a1 + 8);
	v3 = *(_DWORD*)(a1 + 8);
	if (v3) {
		result = *(_DWORD*)(a1 + 4);
		*(_DWORD*)(v3 + 4) = result;
	} else {
		dword_5d4594_2386212 = *(_DWORD*)(a1 + 4);
	}
	return result;
}

//----- (0050E1E0) --------------------------------------------------------
void __cdecl sub_50E1E0(int a1) {
	if (a1) {
		if (!sub_534A40(a1))
			sub_50E140(a1);
	}
}

//----- (0050E210) --------------------------------------------------------
void __cdecl sub_50E210(int a1) {
	int v1; // esi
	int v2; // eax
	int v3; // esi
	int v4; // edi

	v1 = *(_DWORD*)(a1 + 748);
	if (!*(_DWORD*)&byte_5D4594[2386360])
		*(_DWORD*)&byte_5D4594[2386360] = sub_4E3AA0((CHAR*)&byte_587000[234808]);
	if (*(_BYTE*)(a1 + 8) & 2) {
		v2 = *(_DWORD*)(a1 + 12);
		if (v2 & 0x2000) {
			if (*(_DWORD*)(v1 + 2196)) {
				v3 = sub_4E7980(a1);
				if (v3) {
					do {
						v4 = sub_4E7990(v3);
						if (*(unsigned __int16*)(v3 + 4) == *(_DWORD*)&byte_5D4594[2386360])
							sub_4E5CC0(v3);
						v3 = v4;
					} while (v4);
				}
			}
		}
	}
	sub_50E140(a1);
}

//----- (0050E2A0) --------------------------------------------------------
int sub_50E2A0() {
	int result; // eax

	result = nox_new_alloc_class("TradeSessions", 64, 64);
	dword_5d4594_2386492 = result;
	if (result) {
		dword_5d4594_2386496 = nox_new_alloc_class("TradeItems", 16, 500);
		if (dword_5d4594_2386496) {
			memset(&byte_5D4594[2386364], 0, 0x80u);
			dword_5d4594_2386500 = 0;
			result = 1;
		} else {
			sub_50E300();
			result = 0;
		}
	}
	return result;
}

//----- (0050E300) --------------------------------------------------------
int sub_50E300() {
	int result; // eax

	if (dword_5d4594_2386492)
		nox_free_alloc_class(*(LPVOID*)&dword_5d4594_2386492);
	dword_5d4594_2386492 = 0;
	if (dword_5d4594_2386496)
		nox_free_alloc_class(*(LPVOID*)&dword_5d4594_2386496);
	result = 0;
	memset(&byte_5D4594[2386364], 0, 0x80u);
	dword_5d4594_2386496 = 0;
	dword_5d4594_2386500 = 0;
	return result;
}

//----- (0050E360) --------------------------------------------------------
int sub_50E360() {
	_DWORD* v0; // edi
	int* i;     // esi
	int result; // eax

	v0 = *(_DWORD**)&dword_5d4594_2386500;
	if (dword_5d4594_2386500) {
		do {
			if (v0[4]) {
				for (i = (int*)v0[5]; i; i = (int*)i[2])
					sub_4E38A0(*i);
				v0[5] = 0;
			}
			v0 = (_DWORD*)v0[14];
		} while (v0);
	}
	sub_4144D0(*(_DWORD**)&dword_5d4594_2386492);
	sub_4144D0(*(_DWORD**)&dword_5d4594_2386496);
	result = 0;
	memset(&byte_5D4594[2386364], 0, 0x80u);
	dword_5d4594_2386500 = 0;
	return result;
}

//----- (0050E3D0) --------------------------------------------------------
int __cdecl sub_50E3D0(int a1, int a2, float a3) {
	float v3;              // ebp
	int v4;                // edi
	int v5;                // ebx
	int v6;                // eax
	int v7;                // eax
	int v8;                // eax
	double v9;             // st7
	int v10;               // eax
	int v11;               // esi
	int v12;               // edi
	double v13;            // st7
	int v14;               // eax
	_BYTE* v15;            // esi
	double v16;            // st7
	int v17;               // eax
	double v18;            // st7
	int v19;               // ecx
	int v20;               // ecx
	unsigned __int16* v21; // ecx
	double v22;            // st7
	int v23;               // eax
	double v24;            // st7
	float v26;             // [esp+0h] [ebp-20h]
	int v27;               // [esp+14h] [ebp-Ch]
	float v28;             // [esp+18h] [ebp-8h]
	int v29;               // [esp+28h] [ebp+8h]
	float v30;             // [esp+28h] [ebp+8h]
	float v31;             // [esp+2Ch] [ebp+Ch]

	v3 = a3;
	v4 = 0;
	v27 = 0;
	v31 = (double)*(unsigned int*)(LODWORD(a3) + 32);
	if (!*(_DWORD*)&byte_5D4594[2386504]) {
		*(_DWORD*)&byte_5D4594[2386504] = sub_4E3AA0((CHAR*)&byte_587000[235608]);
		*(_DWORD*)&byte_5D4594[2386508] = sub_4E3AA0((CHAR*)&byte_587000[235616]);
		*(_DWORD*)&byte_5D4594[2386512] = sub_4E3AA0((CHAR*)&byte_587000[235624]);
	}
	v5 = a2;
	if (a2 && *(_DWORD*)(a2 + 16)) {
		v6 = *(_DWORD*)(a2 + 8);
		if (*(_BYTE*)(v6 + 8) & 4)
			v6 = *(_DWORD*)(a2 + 12);
		v27 = *(_DWORD*)(v6 + 692);
		v4 = *(_DWORD*)(v6 + 692);
	}
	v7 = *(_DWORD*)(LODWORD(v3) + 8);
	if (v7 & 0x100) {
		v8 = *(_DWORD*)(LODWORD(v3) + 12);
		if (v8 & 1) {
			v9 = (double)(unsigned __int16)sub_424C40(COERCE_FLOAT(**(_BYTE**)(LODWORD(v3) + 736)));
		LABEL_16:
			v31 = v9;
			goto LABEL_17;
		}
		if (v8 & 2) {
			v10 = sub_4E3B60(*(CHAR**)(LODWORD(v3) + 736));
			if (v10)
				v31 = (double)*(unsigned int*)(v10 + 48);
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				v9 = sub_419D40(&byte_587000[235632]) * v31;
				goto LABEL_16;
			}
		}
	}
LABEL_17:
	if (*(_DWORD*)(LODWORD(v3) + 8) & 0x13001000) {
		v11 = *(_DWORD*)(LODWORD(v3) + 692);
		v12 = 4;
		do {
			if (*(_DWORD*)v11) {
				*(float*)&v29 = (double)*(int*)(*(_DWORD*)v11 + 20);
				if (nox_common_gameFlags_check_40A5C0(4096))
					v13 = sub_419D40(&byte_587000[235660]) * *(float*)&v29;
				else
					v13 = *(float*)&v29;
				v31 = v13 + v31;
			}
			v11 += 4;
			--v12;
		} while (v12);
		v4 = v27;
	}
	v14 = *(_DWORD*)(LODWORD(v3) + 8);
	v30 = v31;
	if (v14 & 0x1000000 && *(_BYTE*)(LODWORD(v3) + 12) & 0x82) {
		v15 = *(_BYTE**)(LODWORD(v3) + 736);
		if (!v15[2] && *v15) {
			if (nox_common_gameFlags_check_40A5C0(4096))
				v16 = sub_419D40(&byte_587000[235692]);
			else
				v16 = sub_419D40(&byte_587000[235716]);
			v26 = v16;
			v17 = nox_float2int(v26);
			v18 = (double)v17;
			v19 = (unsigned __int8)v15[1];
			if (v19 > v17) {
				v28 = v31 / v18;
				v31 = (double)(v19 - v17) * v28 + v31;
			} else {
				v31 = (double)(unsigned __int8)v15[1] / v18 * v31;
			}
		}
	} else if (v14 & 0x1000) {
		if (*(_DWORD*)(LODWORD(v3) + 12) & 0x47F0000) {
			v20 = *(_DWORD*)(LODWORD(v3) + 736);
			if (*(_BYTE*)(v20 + 109)) {
				v4 = v27;
				v31 = (double)*(unsigned __int8*)(v20 + 108) / (double)*(unsigned __int8*)(v20 + 109) *
				      v31;
			}
		}
	}
	if (v4 && v5 && *(_DWORD*)(v5 + 16) && a1) {
		v31 = v31 * *(float*)(v4 + 1716);
		v30 = v30 * *(float*)(v4 + 1716);
	}
	v21 = *(unsigned __int16**)(LODWORD(v3) + 556);
	if (v21 && v21[2])
		v31 = (double)*v21 / (double)v21[2] * v31;
	if (v4 && !a1) {
		v22 = nox_common_gameFlags_check_40A5C0(4096) ? sub_419D40(&byte_587000[235736]) : *(float*)(v4 + 1720);
		v23 = *(unsigned __int16*)(LODWORD(v3) + 4);
		if ((unsigned __int16)v23 != *(_DWORD*)&byte_5D4594[2386504] &&
		    v23 != *(_DWORD*)&byte_5D4594[2386512] && v23 != *(_DWORD*)&byte_5D4594[2386508]) {
			v31 = v22 * v31;
			v30 = v22 * v30;
		}
	}
	if (nox_common_gameFlags_check_40A5C0(4096) && !a1 && *(_DWORD*)(LODWORD(v3) + 8) & 0x3001000 &&
	    *(_BYTE*)(*(_DWORD*)(LODWORD(v3) + 748) + 4) & 1) {
		v30 = 0.0;
	} else if (v31 >= 1.0) {
		goto LABEL_64;
	}
	v31 = 1.0;
LABEL_64:
	if (v30 < 1.0)
		v30 = 1.0;
	if (a1 == 2) {
		v24 = sub_419D40(&byte_587000[235756]) * (v30 - v31);
		v31 = v24;
		if (v24 < 1.0)
			v31 = 1.0;
	}
	return nox_float2int(v31);
}

//----- (0050E820) --------------------------------------------------------
int __cdecl sub_50E820(int a1, int a2) {
	int v3; // ecx
	int v5; // [esp+0h] [ebp-4h]

	HIWORD(v5) = *(_WORD*)(a2 + 36);
	v3 = *(_DWORD*)(a1 + 748);
	LOWORD(v5) = 2505;
	return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (int)&v5, 4, 0, 1);
}

//----- (0050E870) --------------------------------------------------------
_DWORD* sub_50E870() {
	_DWORD* v0; // eax
	_DWORD* v1; // esi

	v0 = nox_alloc_class_new_obj_zero(*(_DWORD**)&dword_5d4594_2386492);
	v1 = v0;
	if (!v0)
		return 0;
	v0[2] = 0;
	v0[3] = 0;
	v0[6] = 0;
	v0[7] = 0;
	v0[8] = 0;
	v0[9] = 0;
	v0[10] = 0;
	v0[11] = 0;
	v0[5] = 0;
	v0[12] = sub_4E3810((CHAR*)&byte_587000[235776]);
	v1[13] = sub_4E3810((CHAR*)&byte_587000[235784]);
	v1[15] = 0;
	v1[14] = dword_5d4594_2386500;
	if (dword_5d4594_2386500)
		*(_DWORD*)(dword_5d4594_2386500 + 60) = v1;
	dword_5d4594_2386500 = v1;
	return v1;
}

//----- (0050E970) --------------------------------------------------------
void __cdecl sub_50E970(int a1) {
	int v1;                  // edi
	int v2;                  // eax
	int v3;                  // esi
	unsigned int v4;         // esi
	_DWORD* v5;              // eax
	CHAR** v6;               // eax
	unsigned __int8* v7;     // esi
	_DWORD* v8;              // eax
	int v9;                  // ecx
	_DWORD* v10;             // eax
	int v11;                 // edi
	_DWORD* v12;             // ebx
	int v13;                 // eax
	unsigned int v14;        // esi
	_DWORD* v15;             // eax
	_DWORD* v16;             // eax
	_DWORD* v17;             // eax
	_DWORD* v18;             // eax
	_DWORD* v19;             // eax
	_DWORD* v20;             // eax
	_DWORD* v21;             // eax
	_DWORD* v22;             // eax
	_DWORD* v23;             // eax
	_DWORD* v24;             // eax
	_DWORD* v25;             // eax
	_DWORD* v26;             // eax
	_DWORD* v27;             // eax
	_DWORD* v28;             // eax
	_DWORD* v29;             // eax
	_DWORD* v30;             // eax
	_DWORD* v31;             // eax
	_DWORD* v32;             // eax
	_BYTE* v33;              // esi
	unsigned __int8* v34;    // ebp
	_DWORD* v35;             // eax
	int v36;                 // ebx
	int v37;                 // eax
	int v38;                 // edx
	int v39;                 // eax
	float v40;               // [esp+0h] [ebp-38h]
	int v41;                 // [esp+14h] [ebp-24h]
	int v42;                 // [esp+18h] [ebp-20h]
	_BYTE* v43;              // [esp+20h] [ebp-18h]
	unsigned __int8 v44[20]; // [esp+24h] [ebp-14h]

	v1 = a1;
	v2 = *(_DWORD*)(a1 + 8);
	if (v2 && *(_BYTE*)(v2 + 8) & 2 && *(_BYTE*)(v2 + 12) & 8 ||
	    (v2 = *(_DWORD*)(a1 + 12)) != 0 && *(_BYTE*)(v2 + 8) & 2 && *(_BYTE*)(v2 + 12) & 8) {
		v3 = v2;
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			v40 = sub_419D40(&byte_587000[235792]);
			v4 = nox_float2int(v40);
			if (sub_4E3CC0() < v4) {
				v5 = sub_4E3810((CHAR*)&byte_587000[235812]);
				if (v5)
					sub_50EE00(a1, *(float*)&v5);
			}
			if (*(_DWORD*)&byte_587000[234816]) {
				v6 = (CHAR**)&byte_587000[234816];
				v7 = &byte_587000[234816];
				do {
					v8 = sub_4E3810(*v6);
					if (v8)
						sub_50EE00(a1, *(float*)&v8);
					v9 = *((_DWORD*)v7 + 1);
					v7 += 4;
					v6 = (CHAR**)v7;
				} while (v9);
			}
			v10 = sub_4E3810((CHAR*)&byte_587000[235828]);
			v11 = (int)v10;
			if (v10) {
				v12 = (_DWORD*)v10[173];
				v13 = sub_4E3CC0();
				*v12 = 8;
				v14 = v13 + 2;
				v15 = nox_server_rewardgen_activateMarker_4F0720(v11, v13 + 2);
				if (v15)
					sub_50EE00(a1, *(float*)&v15);
				*v12 = 8;
				v16 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v16)
					sub_50EE00(a1, *(float*)&v16);
				*v12 = 8;
				v17 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v17)
					sub_50EE00(a1, *(float*)&v17);
				*v12 = 8;
				v18 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v18)
					sub_50EE00(a1, *(float*)&v18);
				*v12 = 16;
				v19 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v19)
					sub_50EE00(a1, *(float*)&v19);
				*v12 = 16;
				v20 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v20)
					sub_50EE00(a1, *(float*)&v20);
				*v12 = 16;
				v21 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v21)
					sub_50EE00(a1, *(float*)&v21);
				*v12 = 16;
				v22 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v22)
					sub_50EE00(a1, *(float*)&v22);
				*v12 = 1;
				v23 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v23)
					sub_50EE00(a1, *(float*)&v23);
				*v12 = 1;
				v24 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v24)
					sub_50EE00(a1, *(float*)&v24);
				*v12 = 1;
				v25 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v25)
					sub_50EE00(a1, *(float*)&v25);
				*v12 = 1;
				v26 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v26)
					sub_50EE00(a1, *(float*)&v26);
				*v12 = 1;
				v27 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v27)
					sub_50EE00(a1, *(float*)&v27);
				*v12 = 1;
				v28 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v28)
					sub_50EE00(a1, *(float*)&v28);
				*v12 = 4;
				v29 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v29)
					sub_50EE00(a1, *(float*)&v29);
				*v12 = 4;
				v30 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v30)
					sub_50EE00(a1, *(float*)&v30);
				*v12 = 4;
				v31 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
				if (v31)
					sub_50EE00(a1, *(float*)&v31);
				if (nox_common_randomInt_415FA0(0, 100) > 90) {
					*v12 = 2;
					v32 = nox_server_rewardgen_activateMarker_4F0720(v11, v14);
					if (v32)
						sub_50EE00(a1, *(float*)&v32);
				}
				sub_4E5CC0(v11);
			}
		} else {
			v33 = *(_BYTE**)(v3 + 692);
			v43 = v33;
			if (v33) {
				if (*v33) {
					v42 = 0;
					if (*v33) {
						v34 = v33 + 8;
						do {
							v41 = 0;
							if (*v34) {
								do {
									v35 = sub_4E3810(
									    *(CHAR**)(*((_DWORD*)v34 - 1) + 4));
									v36 = (int)v35;
									if (v35) {
										if (v35[2] & 0x13001000) {
											v37 = *((_DWORD*)v34 + 2);
											v38 = *((_DWORD*)v34 + 4);
											*(_DWORD*)&v44[4] =
											    *((_DWORD*)v34 + 3);
											*(_DWORD*)v44 = v37;
											v39 = *((_DWORD*)v34 + 5);
											*(_DWORD*)&v44[8] = v38;
											*(_DWORD*)&v44[12] = v39;
											sub_4E4990(v36, (int*)v44);
										}
										if (*(int(__cdecl**)(int*))(
											v36 + 704) == sub_4F5F30)
											**(_BYTE**)(v36 + 736) = v34[4];
										if (*(int(__cdecl**)(int*))(
											v36 + 704) == sub_4F6240)
											**(_BYTE**)(v36 + 736) = v34[4];
										if (*(int(__cdecl**)(int*))(
											v36 + 704) == sub_4F6390) {
											strcpy(
											    *(char**)(v36 + 736),
											    (const char*)sub_4E3A80(
												*((_DWORD*)v34 + 1)));
											v1 = a1;
											v33 = v43;
										}
										sub_50EE00(v1, *(float*)&v36);
									}
									++v41;
								} while (v41 < *v34);
							}
							v34 += 28;
							++v42;
						} while (v42 < (unsigned __int8)*v33);
					}
				}
			}
		}
	}
}

//----- (0050EE00) --------------------------------------------------------
float* __cdecl sub_50EE00(int a1, float a2) {
	float* result;   // eax
	float* v3;       // esi
	unsigned int v4; // ebx
	int v5;          // edi
	_DWORD* i;       // eax
	int v7;          // eax

	result = (float*)nox_alloc_class_new_obj_zero(*(_DWORD**)&dword_5d4594_2386496);
	v3 = result;
	if (result) {
		*result = a2;
		*((_DWORD*)result + 1) = sub_50E3D0(1, a1, a2);
		v4 = sub_50EEC0(v3);
		if (*(_DWORD*)(a1 + 20)) {
			if (v4 <= sub_50EEC0(*(_DWORD**)(a1 + 20))) {
				v3[3] = 0.0;
				v3[2] = *(float*)(a1 + 20);
				*(_DWORD*)(*(_DWORD*)(a1 + 20) + 12) = v3;
				*(_DWORD*)(a1 + 20) = v3;
				result = v3;
			} else {
				v5 = *(_DWORD*)(a1 + 20);
				for (i = *(_DWORD**)(v5 + 8); i; i = *(_DWORD**)(v5 + 8)) {
					if (v4 <= sub_50EEC0(i))
						break;
					v5 = *(_DWORD*)(v5 + 8);
				}
				v3[2] = *(float*)(v5 + 8);
				v7 = *(_DWORD*)(v5 + 8);
				if (v7)
					*(_DWORD*)(v7 + 12) = v3;
				*(_DWORD*)(v5 + 8) = v3;
				*((_DWORD*)v3 + 3) = v5;
				result = v3;
			}
		} else {
			v3[2] = 0.0;
			v3[3] = 0.0;
			*(_DWORD*)(a1 + 20) = v3;
			result = v3;
		}
	}
	return result;
}

//----- (0050EEC0) --------------------------------------------------------
int __cdecl sub_50EEC0(_DWORD* a1) {
	int v1;              // ecx
	int v2;              // eax
	unsigned __int8* v3; // edx

	v1 = 16781312;
	v2 = 255;
	v3 = &byte_581450[10308];
	do {
		if (*(_DWORD*)(*a1 + 8) & v1 && (!*(_DWORD*)v3 || *(_DWORD*)v3 & *(_DWORD*)(*a1 + 12)))
			break;
		v1 = *((_DWORD*)v3 + 1);
		v3 += 8;
		--v2;
	} while (v1);
	return a1[1] | (v2 << 24);
}

//----- (0050F2B0) --------------------------------------------------------
int __cdecl sub_50F2B0(int a1, _DWORD* a2) {
	int v2;               // eax
	int v3;               // ecx
	int v4;               // esi
	int v5;               // edx
	unsigned __int16* v6; // ecx
	int i;                // eax
	char v9[18];          // [esp+8h] [ebp-14h]

	v2 = *a2;
	v3 = a2[1];
	v4 = *(_DWORD*)(a1 + 748);
	v5 = *(_DWORD*)(*a2 + 692);
	v9[0] = -55;
	v9[1] = 8;
	*(_WORD*)&v9[4] = *(_WORD*)(v2 + 36);
	*(_WORD*)&v9[2] = *(_WORD*)(v2 + 4);
	*(_DWORD*)&v9[6] = v3;
	v6 = *(unsigned __int16**)(v2 + 556);
	if (v6)
		*(_DWORD*)&v9[10] = *v6;
	else
		*(_DWORD*)&v9[10] = 0;
	if (*(_DWORD*)(v2 + 8) & 0x13001000) {
		for (i = 0; i < 4; ++i) {
			if (*(_DWORD*)v5)
				v9[i + 14] = *(_BYTE*)(*(_DWORD*)v5 + 4);
			else
				v9[i + 14] = -1;
			v5 += 4;
		}
	} else {
		*(_DWORD*)&v9[14] = -1;
	}
	return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), (int)v9, 18, 0, 1);
}

//----- (0050F3A0) --------------------------------------------------------
void __cdecl sub_50F3A0(_DWORD* a1) {
	int* i; // edi
	int* j; // edi

	for (i = (int*)a1[8]; i; i = (int*)i[2])
		sub_4F3070(a1[2], *i, 1);
	sub_4FA590(a1[2], **(_DWORD**)(a1[12] + 692));
	sub_50F450(a1[2]);
	for (j = (int*)a1[9]; j; j = (int*)j[2])
		sub_4F3070(a1[3], *j, 1);
	sub_4FA590(a1[3], **(_DWORD**)(a1[13] + 692));
	sub_50F450(a1[3]);
	sub_50F490(a1, a1[2]);
	sub_50F490(a1, a1[3]);
	sub_510000((int)a1);
}

//----- (0050F450) --------------------------------------------------------
int __cdecl sub_50F450(int a1) {
	int v2;     // edx
	char v4[2]; // [esp+0h] [ebp-2h]

	v2 = *(_DWORD*)(a1 + 748);
	*(_WORD*)v4 = 457;
	return sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v4, 2, 0, 1);
}

//----- (0050F490) --------------------------------------------------------
int __cdecl sub_50F490(_DWORD* a1, int a2) {
	int result; // eax

	result = a2;
	*a1 = 0;
	if (*(_BYTE*)(a2 + 8) & 4) {
		result = *(_DWORD*)(a2 + 748);
		if (*(_DWORD**)(result + 280) == a1)
			*(_DWORD*)(result + 280) = 0;
	}
	return result;
}

//----- (0050F4C0) --------------------------------------------------------
void __cdecl sub_50F4C0(_DWORD* a1) {
	int v1; // eax
	int v2; // eax
	int v3; // edi

	sub_50F490(a1, a1[2]);
	sub_50F490(a1, a1[3]);
	v1 = a1[2];
	if (*(_BYTE*)(v1 + 8) & 4)
		sub_4E7A60(v1, 0);
	else
		sub_4E7A60(a1[3], 0);
	v2 = a1[2];
	if (*(_BYTE*)(v2 + 8) & 4) {
		sub_50F560(v2);
		v3 = a1[2];
	} else {
		sub_50F560(a1[3]);
		v3 = a1[3];
	}
	if (nox_common_gameFlags_check_40A5C0(4096))
		*(_DWORD*)&byte_5D4594[4 * *(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(v3 + 748) + 276) + 2064) +
				       2386364] = a1;
	else
		sub_510000((int)a1);
}

//----- (0050F560) --------------------------------------------------------
int __cdecl sub_50F560(int a1) {
	int v2;     // edx
	__int16 v4; // [esp+0h] [ebp-2h]

	v2 = *(_DWORD*)(a1 + 748);
	v4 = 713;
	return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), (int)&v4, 2, 0, 1);
}

//----- (0050F5A0) --------------------------------------------------------
void __cdecl sub_50F5A0(int a1, int a2) {
	int v2; // eax
	int v3; // eax
	int v4; // ecx
	int v5; // eax
	int v6; // eax
	int v7; // [esp-34h] [ebp-3Ch]

	v2 = *(_DWORD*)(a1 + 8);
	if (v2 == a2) {
		*(_DWORD*)(a1 + 24) = 1;
	} else if (*(_DWORD*)(a1 + 12) == a2) {
		*(_DWORD*)(a1 + 28) = 1;
	}
	if (*(_BYTE*)(v2 + 8) & 4)
		sub_50F720(v2, (_DWORD*)a1);
	v3 = *(_DWORD*)(a1 + 12);
	if (*(_BYTE*)(v3 + 8) & 4)
		sub_50F720(v3, (_DWORD*)a1);
	if (*(_DWORD*)(a1 + 24) == 1 && *(_DWORD*)(a1 + 28) == 1) {
		sub_50F790(a1, *(_DWORD*)(a1 + 12), *(int**)(a1 + 32));
		sub_50F790(a1, *(_DWORD*)(a1 + 8), *(int**)(a1 + 36));
		sub_50F7F0(*(_DWORD*)(a1 + 12), *(_DWORD*)(a1 + 48));
		sub_50F7F0(*(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 52));
		sub_50F6B0(*(_DWORD*)(a1 + 32));
		v7 = *(_DWORD*)(a1 + 36);
		*(_DWORD*)(a1 + 32) = 0;
		sub_50F6B0(v7);
		v4 = *(_DWORD*)(a1 + 48);
		*(_DWORD*)(a1 + 36) = 0;
		**(_DWORD**)(v4 + 692) = 0;
		**(_DWORD**)(*(_DWORD*)(a1 + 52) + 692) = 0;
		v5 = *(_DWORD*)(a1 + 16);
		*(_DWORD*)(a1 + 40) = 0;
		*(_DWORD*)(a1 + 44) = 0;
		if (v5 == 1) {
			v6 = *(_DWORD*)(a1 + 8);
			if (*(_BYTE*)(v6 + 8) & 4)
				sub_50F6E0(v6);
			else
				sub_50F6E0(*(_DWORD*)(a1 + 12));
		} else {
			sub_50F3A0((_DWORD*)a1);
		}
	}
}

//----- (0050F6B0) --------------------------------------------------------
int __cdecl sub_50F6B0(int a1) {
	int result; // eax
	int v2;     // esi

	result = a1;
	if (a1) {
		do {
			v2 = *(_DWORD*)(result + 8);
			sub_414330(*(unsigned int**)&dword_5d4594_2386496, (_QWORD*)result);
			result = v2;
		} while (v2);
	}
	return result;
}

//----- (0050F6E0) --------------------------------------------------------
int __cdecl sub_50F6E0(int a1) {
	int v2;     // edx
	__int16 v4; // [esp+0h] [ebp-2h]

	v2 = *(_DWORD*)(a1 + 748);
	v4 = 1993;
	return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), (int)&v4, 2, 0, 1);
}

//----- (0050F720) --------------------------------------------------------
int __cdecl sub_50F720(int a1, _DWORD* a2) {
	int v2;  // edx
	int v3;  // edi
	int v4;  // esi
	char v5; // al
	char v6; // al

	v2 = a1;
	v3 = a2[6];
	v4 = *(_DWORD*)(a1 + 748);
	v5 = 0;
	LOWORD(a1) = 969;
	BYTE2(a1) = 0;
	if (v3) {
		v5 = (a2[2] != v2) + 1;
		BYTE2(a1) = (a2[2] != v2) + 1;
	}
	if (a2[7]) {
		if (a2[3] == v2)
			v6 = v5 | 1;
		else
			v6 = v5 | 2;
		BYTE2(a1) = v6;
	}
	return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), (int)&a1, 3, 0, 1);
}

//----- (0050F790) --------------------------------------------------------
void __cdecl sub_50F790(int a1, int a2, int* a3) {
	int* i;    // esi
	float* v4; // eax
	int v5;    // ecx

	for (i = a3; i; i = (int*)i[2]) {
		if (*(_BYTE*)(a2 + 8) & 4) {
			sub_4F3070(a2, *i, 1);
		} else {
			v4 = sub_50EE00(a1, *(float*)i);
			if (v4) {
				v5 = *(_DWORD*)(a1 + 8);
				if (*(_BYTE*)(v5 + 8) & 4)
					sub_50F2B0(v5, v4);
				else
					sub_50F2B0(*(_DWORD*)(a1 + 12), v4);
			}
		}
	}
}

//----- (0050F7F0) --------------------------------------------------------
_DWORD* __cdecl sub_50F7F0(int a1, int a2) {
	_DWORD* result; // eax

	result = (_DWORD*)a1;
	if (*(_BYTE*)(a1 + 8) & 4)
		result = sub_4FA590(a1, **(_DWORD**)(a2 + 692));
	return result;
}

//----- (0050FA00) --------------------------------------------------------
int __cdecl sub_50FA00(int a1, _DWORD* a2) {
	int v2;      // edx
	int v3;      // esi
	int v4;      // edx
	int v5;      // edx
	char v7[14]; // [esp+4h] [ebp-10h]

	v7[0] = -55;
	v2 = a2[2];
	v3 = *(_DWORD*)(a1 + 748);
	v7[1] = 6;
	if (v2 == a1) {
		v4 = a2[3];
		*(_DWORD*)&v7[2] = **(_DWORD**)(a2[12] + 692);
		if (*(_BYTE*)(v4 + 8) & 4) {
			v5 = a2[13];
			*(_DWORD*)&v7[6] = 0;
		} else {
			v5 = a2[13];
			*(_DWORD*)&v7[6] = a2[11] - a2[10];
		}
		*(_DWORD*)&v7[10] = **(_DWORD**)(v5 + 692);
	} else if (a2[3] == a1) {
		*(_DWORD*)&v7[2] = **(_DWORD**)(a2[13] + 692);
		if (*(_BYTE*)(v2 + 8) & 4)
			*(_DWORD*)&v7[6] = 0;
		else
			*(_DWORD*)&v7[6] = a2[10] - a2[11];
		*(_DWORD*)&v7[10] = **(_DWORD**)(a2[12] + 692);
	}
	return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (int)v7, 14, 0, 1);
}

//----- (0050FB90) --------------------------------------------------------
_DWORD* __cdecl sub_50FB90(_DWORD* a1) {
	int v1;           // ecx
	_DWORD* result;   // eax
	int* v3;          // edi
	int v4;           // eax
	int* v5;          // edi
	int v6;           // eax
	int v7;           // ecx
	unsigned int v8;  // ecx
	unsigned int v9;  // edi
	unsigned int v10; // eax
	int v11;          // eax
	unsigned int v12; // edi
	unsigned int v13; // eax
	int v14;          // ecx

	v1 = a1[2];
	result = (_DWORD*)(*(_DWORD*)(v1 + 8) & 4);
	if (result != (_DWORD*)4 || (*(_BYTE*)(a1[3] + 8) & 4) != 4) {
		v3 = *(int**)(a1[12] + 692);
		if (result)
			sub_4FA590(v1, *v3);
		*v3 = 0;
		v4 = a1[3];
		v5 = *(int**)(a1[13] + 692);
		if (*(_BYTE*)(v4 + 8) & 4)
			sub_4FA590(v4, *v5);
		*v5 = 0;
		v6 = sub_50FD20(a1, a1[2]);
		v7 = a1[3];
		a1[10] = v6;
		result = (_DWORD*)sub_50FD20(a1, v7);
		v8 = a1[10];
		a1[11] = result;
		if ((unsigned int)result <= v8) {
			if ((unsigned int)result < v8) {
				v12 = v8 - (_DWORD)result;
				if (*(_BYTE*)(a1[3] + 8) & 4) {
					v13 = sub_4FA6B0(a1[3]);
					if (v13 < v12) {
						a1[11] += v13;
						**(_DWORD**)(a1[13] + 692) += v13;
						result = sub_4FA5D0(a1[3], v13);
					} else {
						v14 = a1[13];
						a1[11] += v12;
						**(_DWORD**)(v14 + 692) += v12;
						result = sub_4FA5D0(a1[3], v12);
					}
				} else {
					a1[11] = v8;
					result = *(_DWORD**)(a1[13] + 692);
					*result += v12;
				}
			}
		} else {
			v9 = (unsigned int)result - v8;
			if (*(_BYTE*)(a1[2] + 8) & 4) {
				v10 = sub_4FA6B0(a1[2]);
				if (v10 < v9) {
					a1[10] += v10;
					**(_DWORD**)(a1[12] + 692) += v10;
					result = sub_4FA5D0(a1[2], v10);
				} else {
					a1[10] += v9;
					**(_DWORD**)(a1[12] + 692) += v9;
					result = sub_4FA5D0(a1[2], v9);
				}
			} else {
				v11 = a1[12];
				a1[10] = v9 + v8;
				result = *(_DWORD**)(v11 + 692);
				*result += v9;
			}
		}
	}
	return result;
}

//----- (0050FD20) --------------------------------------------------------
int __cdecl sub_50FD20(_DWORD* a1, int a2) {
	int v2;     // edx
	int v3;     // ecx
	int result; // eax
	int v5;     // edx

	if (a1[2] == a2) {
		v2 = a1[12];
		v3 = a1[8];
	} else {
		v2 = a1[13];
		v3 = a1[9];
	}
	for (result = **(_DWORD**)(v2 + 692); v3; result += v5) {
		v5 = *(_DWORD*)(v3 + 4);
		v3 = *(_DWORD*)(v3 + 8);
	}
	return result;
}

//----- (0050FE20) --------------------------------------------------------
int __cdecl sub_50FE20(int a1, int a2) {
	int* v2;    // edi
	int v3;     // ebp
	int result; // eax
	float* v5;  // eax
	int v6;     // ecx
	int v7;     // eax
	int v8;     // eax
	int v9;     // eax
	int v10;    // eax

	v2 = sub_50FFE0(*(_DWORD**)(a1 + 32), a2);
	if (v2) {
		v3 = *(_DWORD*)(a1 + 8);
	} else {
		result = sub_50FFE0(*(_DWORD**)(a1 + 36), a2);
		v2 = (int*)result;
		if (!result)
			return result;
		v3 = *(_DWORD*)(a1 + 12);
	}
	if (*(_BYTE*)(v3 + 8) & 4) {
		sub_4F3070(v3, *v2, 1);
	} else {
		v5 = sub_50EE00(a1, *(float*)v2);
		if (v5) {
			v6 = *(_DWORD*)(a1 + 8);
			if (!(*(_BYTE*)(v6 + 8) & 4))
				v6 = *(_DWORD*)(a1 + 12);
			sub_50F2B0(v6, v5);
		}
	}
	v7 = v2[2];
	if (v7)
		*(_DWORD*)(v7 + 12) = v2[3];
	v8 = v2[3];
	if (v8)
		*(_DWORD*)(v8 + 8) = v2[2];
	if (*(_DWORD*)(a1 + 8) == v3) {
		if (*(int**)(a1 + 32) == v2)
			*(_DWORD*)(a1 + 32) = v2[2];
	} else if (*(int**)(a1 + 36) == v2) {
		*(_DWORD*)(a1 + 36) = v2[2];
	}
	sub_50FB90((_DWORD*)a1);
	*(_DWORD*)(a1 + 24) = 0;
	*(_DWORD*)(a1 + 28) = 0;
	v9 = *(_DWORD*)(a1 + 8);
	if (*(_BYTE*)(v9 + 8) & 4) {
		if (!(*(_BYTE*)(*(_DWORD*)(a1 + 12) + 8) & 4) && *(_DWORD*)(a1 + 44) <= *(int*)(a1 + 40))
			*(_DWORD*)(a1 + 28) = 1;
	} else if (*(_DWORD*)(a1 + 40) <= *(int*)(a1 + 44)) {
		*(_DWORD*)(a1 + 24) = 1;
	}
	if (*(_BYTE*)(v9 + 8) & 4) {
		sub_50FA00(v9, (_DWORD*)a1);
		sub_50FF90(*(_DWORD*)(a1 + 8), a1, *v2);
		sub_50F720(*(_DWORD*)(a1 + 8), (_DWORD*)a1);
	}
	v10 = *(_DWORD*)(a1 + 12);
	if (*(_BYTE*)(v10 + 8) & 4) {
		sub_50FA00(v10, (_DWORD*)a1);
		sub_50FF90(*(_DWORD*)(a1 + 12), a1, *v2);
		sub_50F720(*(_DWORD*)(a1 + 12), (_DWORD*)a1);
	}
	sub_414330(*(unsigned int**)&dword_5d4594_2386496, v2);
	return 1;
}

//----- (0050FF90) --------------------------------------------------------
int __cdecl sub_50FF90(int a1, int a2, int a3) {
	int v4; // ecx
	int v6; // [esp+0h] [ebp-4h]

	HIWORD(v6) = *(_WORD*)(a3 + 36);
	v4 = *(_DWORD*)(a1 + 748);
	LOWORD(v6) = 1481;
	return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), (int)&v6, 4, 0, 1);
}

//----- (0050FFE0) --------------------------------------------------------
_DWORD* __cdecl sub_50FFE0(_DWORD* a1, int a2) {
	_DWORD* result; // eax

	result = a1;
	if (!a1)
		return 0;
	while (*(_DWORD*)(*result + 36) != a2) {
		result = (_DWORD*)result[2];
		if (!result)
			return 0;
	}
	return result;
}

//----- (00510000) --------------------------------------------------------
void __cdecl sub_510000(int a1) {
	int* v1; // esi
	int* v2; // ebx
	int v3;  // eax
	int v4;  // eax

	v1 = *(int**)(a1 + 20);
	if (v1) {
		do {
			v2 = (int*)v1[2];
			sub_4E38A0(*v1);
			sub_414330(*(unsigned int**)&dword_5d4594_2386496, v1);
			v1 = v2;
		} while (v2);
	}
	sub_4E38A0(*(_DWORD*)(a1 + 48));
	sub_4E38A0(*(_DWORD*)(a1 + 52));
	sub_50F6B0(*(_DWORD*)(a1 + 32));
	sub_50F6B0(*(_DWORD*)(a1 + 36));
	v3 = *(_DWORD*)(a1 + 56);
	if (v3)
		*(_DWORD*)(v3 + 60) = *(_DWORD*)(a1 + 60);
	v4 = *(_DWORD*)(a1 + 60);
	if (v4)
		*(_DWORD*)(v4 + 56) = *(_DWORD*)(a1 + 56);
	if (a1 == dword_5d4594_2386500)
		dword_5d4594_2386500 = *(_DWORD*)(a1 + 56);
	sub_414330(*(unsigned int**)&dword_5d4594_2386492, (_QWORD*)a1);
}

//----- (005100A0) --------------------------------------------------------
int __cdecl sub_5100A0(int a1, int a2) {
	int* v2;    // eax
	int result; // eax

	v2 = sub_50FFE0(*(_DWORD**)(a1 + 20), a2);
	if (v2)
		result = *v2;
	else
		result = 0;
	return result;
}

//----- (005103A0) --------------------------------------------------------
int __cdecl sub_5103A0(int a1, int a2) {
	int v2;    // eax
	_BYTE* v3; // edi
	int v4;    // esi
	int i;     // ebx

	v2 = *(_DWORD*)(a1 + 8);
	if (*(_BYTE*)(v2 + 8) & 4)
		v2 = *(_DWORD*)(a1 + 12);
	v3 = *(_BYTE**)(v2 + 692);
	v4 = 0;
	if (!*v3)
		return -1;
	for (i = (int)(v3 + 4); !sub_5103F0(a2, i); i += 28) {
		if (++v4 >= (unsigned __int8)*v3)
			return -1;
	}
	return v4;
}

//----- (005103F0) --------------------------------------------------------
int __cdecl sub_5103F0(int a1, int a2) {
	int v2;     // ebp
	int v3;     // esi
	_DWORD* v4; // edx
	int v5;     // edx

	v2 = 0;
	if (!a1 || !a2)
		return 0;
	if (*(_WORD*)(a1 + 4) == **(_WORD**)a2) {
		v3 = *(_DWORD*)(a1 + 8);
		v2 = 1;
		if (v3 & 0x13001000) {
			v4 = *(_DWORD**)(a1 + 692);
			if (*(_DWORD*)(a2 + 12) != *v4)
				v2 = 0;
			if (*(_DWORD*)(a2 + 16) != v4[1])
				v2 = 0;
			if (*(_DWORD*)(a2 + 20) != v4[2])
				v2 = 0;
			if (*(_DWORD*)(a2 + 24) != v4[3])
				v2 = 0;
		}
		if (v3 & 0x100) {
			v5 = *(_DWORD*)(a1 + 12);
			if (v5 & 1 || v5 & 4) {
				if (**(unsigned __int8**)(a1 + 736) != *(_DWORD*)(a2 + 8))
					return 0;
			} else if (strcmp(*(const char**)(a1 + 736), (const char*)sub_4E3A80(*(_DWORD*)(a2 + 8)))) {
				v2 = 0;
			}
		}
	}
	return v2;
}

//----- (005108D0) --------------------------------------------------------
_DWORD* __cdecl sub_5108D0(int a1, int a2, int a3) {
	int v3;             // edi
	_DWORD* result;     // eax
	int v5;             // ebx
	int v6;             // ecx
	int v7;             // ecx
	unsigned __int8 v8; // dl
	_WORD* v9;          // ecx
	__int16 v10;        // dx
	char v11[8];        // [esp+Ch] [ebp-8h]

	v3 = 0;
	result = *(_DWORD**)(a1 + 504);
	v5 = *(_DWORD*)(a1 + 748);
	v11[0] = -55;
	v11[1] = 31;
	*(_WORD*)&v11[2] = a3;
	if (result) {
		while (result[9] != a3) {
			result = (_DWORD*)result[124];
			if (!result)
				return result;
		}
		v6 = result[2];
		if (v6 & 0x1000) {
			if (result[3] & 0x47F0000) {
				v7 = result[184];
				v8 = *(_BYTE*)(v7 + 109);
				if (*(_BYTE*)(v7 + 108) < v8) {
					if (v8)
						v3 = 1;
				}
			}
		}
		v9 = (_WORD*)result[139];
		if (v9 && (v10 = v9[2], *v9 != v10) && v10 || v3) {
			*(_DWORD*)&v11[4] = sub_50E3D0(2, a2, *(float*)&result);
			result = (_DWORD*)sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), v11, 8, 0, 1);
		} else {
			result = sub_501960(925, a1, 0, 0);
		}
	}
	return result;
}

//----- (00510AE0) --------------------------------------------------------
_DWORD* __cdecl sub_510AE0(int* a1, int a2, _DWORD* a3) {
	_DWORD* result;  // eax
	int v4;          // esi
	int v5;          // ebp
	unsigned int v6; // eax
	int v7;          // eax
	int v8;          // ebx

	result = (_DWORD*)sub_4FA6B0((int)a1);
	v4 = a1[126];
	v5 = a1[187];
	if (v4) {
		result = a3;
		while (*(_DWORD**)(v4 + 36) != a3) {
			v4 = *(_DWORD*)(v4 + 496);
			if (!v4)
				return result;
		}
		v6 = sub_50E3D0(2, a2, *(float*)&v4);
		sub_4FA5D0((int)a1, v6);
		sub_4E4560(v4, *(_WORD*)(*(_DWORD*)(v4 + 556) + 4));
		sub_4D87A0(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (_DWORD*)v4);
		v7 = *(_DWORD*)(v4 + 8);
		if (v7 & 0x1000 && *(_DWORD*)(v4 + 12) & 0x47F0000) {
			v8 = *(_DWORD*)(v4 + 736);
			if (sub_53C520(v4, 100))
				sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (_DWORD*)v4,
					   *(_BYTE*)(v8 + 108), *(_BYTE*)(v8 + 109));
		}
		sub_4D8870(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (int)a1);
		result = sub_501960(803, (int)a1, 2, a1[9]);
	}
	return result;
}

//----- (00510D10) --------------------------------------------------------
unsigned __int16 __cdecl sub_510D10(int* a1, int a2, int a3, unsigned int a4) {
	unsigned __int16 result; // ax
	int v5;                  // ebp
	int v6;                  // ebx
	int v7;                  // esi
	int v8;                  // eax

	sub_4FA6B0((int)a1);
	result = a4;
	v5 = a1[187];
	v6 = 0;
	if (a4) {
		while (1) {
			v7 = a1[126];
			if (!v7)
				break;
			while (1) {
				result = *(_WORD*)(v7 + 4);
				if (result == a3)
					break;
				v7 = *(_DWORD*)(v7 + 496);
				if (!v7)
					return result;
			}
			sub_4ED0C0((int)a1, (int*)v7);
			sub_4E5CC0(v7);
			v8 = sub_50E3D0(0, a2, *(float*)&v7);
			sub_4FA590((int)a1, v8);
			sub_4D8870(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (int)a1);
			result = a4;
			if (++v6 >= a4)
				return (unsigned int)sub_501960(307, (int)a1, 2, a1[9]);
		}
	}
	return result;
}

//----- (00510DC0) --------------------------------------------------------
void __cdecl sub_510DC0(_DWORD* a1) {
	if (a1[4])
		sub_50F4C0(a1);
	else
		sub_50F3A0(a1);
}

//----- (00510DE0) --------------------------------------------------------
int __cdecl sub_510DE0(int a1, int a2) {
	int v2;     // eax
	_DWORD* v3; // eax

	v2 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 280);
	if (!v2)
		return 0;
	v3 = *(_DWORD**)(v2 + 20);
	if (!v3)
		return 0;
	while (*(_DWORD*)(*v3 + 36) != a2) {
		v3 = (_DWORD*)v3[2];
		if (!v3)
			return 0;
	}
	return *v3;
}

//----- (00510E20) --------------------------------------------------------
void __cdecl sub_510E20(int a1) {
	if (*(_DWORD*)&byte_5D4594[4 * a1 + 2386364])
		sub_510000(*(_DWORD*)&byte_5D4594[4 * a1 + 2386364]);
	*(_DWORD*)&byte_5D4594[4 * a1 + 2386364] = 0;
}

//----- (00510E50) --------------------------------------------------------
void sub_510E50() { dword_5d4594_2386564 = 0; }

//----- (00510E60) --------------------------------------------------------
signed int __cdecl sub_510E60(int a1) {
	signed int result; // eax
	int v2;            // edi
	float v3;          // eax
	float v4;          // ecx
	float v5;          // eax
	float v6;          // ecx
	float2 a2;         // [esp+8h] [ebp-30h]
	int v8[2];         // [esp+10h] [ebp-28h]
	float4 a1a;        // [esp+18h] [ebp-20h]
	float4 v10;        // [esp+28h] [ebp-10h]

	result = *(_DWORD*)(a1 + 16);
	v2 = *(_DWORD*)(a1 + 748);
	if (result >= 0) {
		*(_DWORD*)(a1 + 500) = 0;
		*(_DWORD*)(a1 + 496) = dword_5d4594_2386564;
		if (dword_5d4594_2386564)
			*(_DWORD*)(dword_5d4594_2386564 + 500) = a1;
		dword_5d4594_2386564 = a1;
		result = *(_DWORD*)(a1 + 16) | 0x80000000;
		*(_DWORD*)(a1 + 16) = result;
	}
	if (*(_BYTE*)(a1 + 16) & 0x20)
		result = (signed int)sub_510FD0((_DWORD*)a1);
	if (*(_DWORD*)(a1 + 16) & 0x1000000) {
		v3 = *(float*)(a1 + 60);
		a1a.field_0 = *(float*)(a1 + 56);
		a1a.field_4 = v3;
		a1a.field_8 = cos(*(float*)v2) * 600.0 + *(float*)(a1 + 56);
		a1a.field_C = sin(*(float*)v2) * 600.0 + *(float*)(a1 + 60);
		if (sub_535250(&a1a, &a2, 0, 5)) {
			v4 = a1a.field_C;
			*(float*)(a1 + 156) = a1a.field_8;
			*(float*)(a1 + 160) = v4;
		} else {
			v5 = a2.field_0;
			v6 = a2.field_4;
			*(float*)(a1 + 156) = a2.field_0;
			*(float*)(a1 + 160) = v6;
			a1a.field_8 = v5;
			a1a.field_C = v6;
		}
		*(float*)v2 = *(float*)(v2 + 8) + *(float*)v2;
		if (a1a.field_0 >= (double)a1a.field_8) {
			v10.field_8 = a1a.field_0;
			v10.field_0 = a1a.field_8;
		} else {
			v10.field_0 = a1a.field_0;
			v10.field_8 = a1a.field_8;
		}
		if (a1a.field_4 >= (double)a1a.field_C) {
			v10.field_C = a1a.field_4;
			v10.field_4 = a1a.field_C;
		} else {
			v10.field_4 = a1a.field_4;
			v10.field_C = a1a.field_C;
		}
		v8[0] = a1;
		v8[1] = (int)&a1a;
		sub_517C10(&v10, sub_511020, (int)v8);
	} else {
		*(_DWORD*)v2 = *(_DWORD*)(v2 + 4);
	}
	return result;
}

//----- (00510FD0) --------------------------------------------------------
_DWORD* __cdecl sub_510FD0(_DWORD* a1) {
	_DWORD* result; // eax
	int v2;         // ecx
	int v3;         // ecx

	result = a1;
	if (a1[4] < 0) {
		v2 = a1[125];
		if (v2)
			*(_DWORD*)(v2 + 496) = a1[124];
		else
			dword_5d4594_2386564 = a1[124];
		v3 = a1[124];
		if (v3)
			*(_DWORD*)(v3 + 500) = a1[125];
	}
	a1[4] &= 0x7FFFFFFFu;
	return result;
}

//----- (00511020) --------------------------------------------------------
void __cdecl sub_511020(int a1, int a2) {
	int v2; // eax
	double v3;
	int v6;    // eax
	int v7;    // [esp-Ch] [ebp-20h]
	float2 a3; // [esp+Ch] [ebp-8h]

	v2 = *(_DWORD*)(a1 + 16);
	if (!(v2 & 0x41) &&
	    (!(v2 & 0x10) || nox_common_gameFlags_check_40A5C0(4096) && *(_BYTE*)(a1 + 8) & 2 &&
				 (*(_DWORD*)(a1 + 16) & 0x8000) != 0x8000) &&
	    *(_DWORD*)(a1 + 556) && sub_57C8A0(*(float4**)(a2 + 4), (float2*)(a1 + 56), &a3)) {
		v3 = *(float*)(a1 + 60) - a3.field_4;
		if (*(float*)(a1 + 176) * *(float*)(a1 + 176) >
		    v3 * v3 + (*(float*)(a1 + 56) - a3.field_0) * (*(float*)(a1 + 56) - a3.field_0)) {
			v7 = *(_DWORD*)a2;
			v6 = sub_4EC580(*(_DWORD*)a2);
			(*(void(__cdecl**)(int, int, int, int, int))(a1 + 716))(a1, v6, v7, 500, 16);
			sub_501960(298, a1, 0, 0);
		}
	}
}

//----- (00511100) --------------------------------------------------------
void __cdecl sub_511100(int a1) {
	int v1;    // edi
	char* v2;  // eax
	int v3;    // esi
	double v4; // st7
	double v5; // st7
	float v6;  // [esp+8h] [ebp-20h]
	float v7;  // [esp+Ch] [ebp-1Ch]
	float v8;  // [esp+14h] [ebp-14h]
	float v9;  // [esp+18h] [ebp-10h]
	float v10; // [esp+1Ch] [ebp-Ch]
	float v11; // [esp+20h] [ebp-8h]
	float i;   // [esp+24h] [ebp-4h]
	float v13; // [esp+2Ch] [ebp+4h]

	v1 = a1;
	v2 = sub_417090(a1);
	v3 = dword_5d4594_2386564;
	v4 = (double)*((unsigned __int16*)v2 + 5);
	v9 = *((float*)v2 + 908) - v4;
	v13 = (double)*((unsigned __int16*)v2 + 6);
	v10 = *((float*)v2 + 909) - v13;
	v11 = v4 + *((float*)v2 + 908);
	for (i = v13 + *((float*)v2 + 909); v3; v3 = *(_DWORD*)(v3 + 496)) {
		if (*(_DWORD*)(v3 + 16) & 0x1000000) {
			if (*(float*)(v3 + 56) >= (double)*(float*)(v3 + 156)) {
				v5 = *(float*)(v3 + 56);
				v6 = *(float*)(v3 + 156);
			} else {
				v5 = *(float*)(v3 + 156);
				v6 = *(float*)(v3 + 56);
			}
			if (*(float*)(v3 + 60) >= (double)*(float*)(v3 + 160)) {
				v8 = *(float*)(v3 + 60);
				v7 = *(float*)(v3 + 160);
			} else {
				v7 = *(float*)(v3 + 60);
				v8 = *(float*)(v3 + 160);
			}
			if (v9 < v5 && v11 > (double)v6 && v10 < (double)v8 && i > (double)v7)
				sub_511250(v1, (float*)v3);
		} else {
			**(_DWORD**)(v3 + 748) = *(_DWORD*)(*(_DWORD*)(v3 + 748) + 4);
		}
	}
}

//----- (00511250) --------------------------------------------------------
int __cdecl sub_511250(int a1, float* a2) {
	__int16 v2; // ax
	float v3;   // ecx
	__int16 v4; // ax
	float v5;   // edx
	char v7[9]; // [esp+4h] [ebp-Ch]

	v7[0] = -107;
	v2 = sub_419A30(a2[14]);
	v3 = a2[15];
	*(_WORD*)&v7[1] = v2;
	v4 = sub_419A30(v3);
	v5 = a2[39];
	*(_WORD*)&v7[3] = v4;
	*(_WORD*)&v7[5] = sub_419A30(v5);
	*(_WORD*)&v7[7] = sub_419A30(a2[40]);
	return sub_40EBC0(a1, 1, v7, 9);
}

//----- (005112C0) --------------------------------------------------------
BOOL sub_5112C0() {
	dword_5d4594_2386568 = nox_new_alloc_class("Springs", 52, 256);
	return dword_5d4594_2386568 != 0;
}

//----- (005112F0) --------------------------------------------------------
void sub_5112F0() {
	dword_5d4594_2386572 = 0;
	sub_4144D0(*(_DWORD**)&dword_5d4594_2386568);
}

//----- (00511310) --------------------------------------------------------
int sub_511310() {
	nox_free_alloc_class(*(LPVOID*)&dword_5d4594_2386568);
	dword_5d4594_2386572 = 0;
	return 1;
}

//----- (00511330) --------------------------------------------------------
void __cdecl sub_511330(int a1) {
	int v1; // eax

	v1 = dword_5d4594_2386572;
	if (dword_5d4594_2386572) {
		while (*(_DWORD*)(v1 + 8) != a1) {
			v1 = *(_DWORD*)(v1 + 44);
			if (!v1)
				return;
		}
		if (v1)
			sub_511360(v1);
	}
}

//----- (00511360) --------------------------------------------------------
void __cdecl sub_511360(int a1) {
	int v1; // ecx
	int v2; // ecx

	v1 = *(_DWORD*)(a1 + 48);
	if (v1)
		*(_DWORD*)(v1 + 44) = *(_DWORD*)(a1 + 44);
	else
		dword_5d4594_2386572 = *(_DWORD*)(a1 + 44);
	v2 = *(_DWORD*)(a1 + 44);
	if (v2)
		*(_DWORD*)(v2 + 48) = *(_DWORD*)(a1 + 48);
	sub_414330(*(unsigned int**)&dword_5d4594_2386568, (_QWORD*)a1);
}

//----- (005113A0) --------------------------------------------------------
void sub_5113A0() {
	int v0;         // esi
	int v1;         // eax
	int v2;         // edi
	int v3;         // ecx
	int v4;         // eax
	int v5;         // ecx
	double v6;      // st7
	long double v7; // st7
	double v8;      // st7
	double v9;      // st7
	float v10;      // [esp+0h] [ebp-1Ch]
	float v11;      // [esp+4h] [ebp-18h]
	float v12;      // [esp+14h] [ebp-8h]
	float v13;      // [esp+14h] [ebp-8h]
	float v14;      // [esp+18h] [ebp-4h]
	float v15;      // [esp+18h] [ebp-4h]

	v0 = dword_5d4594_2386572;
	if (dword_5d4594_2386572) {
		do {
			v1 = *(_DWORD*)(v0 + 8);
			v2 = *(_DWORD*)(v0 + 44);
			if (!v1)
				goto LABEL_16;
			v3 = *(_DWORD*)(v0 + 12);
			if (!v3)
				goto LABEL_16;
			if (!(*(_BYTE*)(v1 + 16) & 0x20) && !(*(_BYTE*)(v3 + 16) & 0x20) &&
			    (v4 = *(_DWORD*)(v0 + 12), v5 = *(_DWORD*)(v0 + 8),
			     v12 = *(float*)(v4 + 64) - *(float*)(v5 + 64),
			     v6 = *(float*)(v4 + 68) - *(float*)(v5 + 68), v14 = v6, v7 = sqrt(v6 * v14 + v12 * v12),
			     *(float*)(v0 + 32) = v7, v7 <= *(float*)(v0 + 28))) {
				v8 = *(float*)(v0 + 32) - *(float*)(v0 + 24);
				if (!(*(_BYTE*)(v0 + 40) & 1) || v8 >= 0.0) {
					if (v8 > *(float*)(v0 + 24))
						v8 = *(float*)(v0 + 24);
					v9 = -(v8 * *(float*)(v0 + 16));
					v15 = v9 * (v14 / *(float*)(v0 + 32));
					v13 = v9 * (v12 / *(float*)(v0 + 32));
					v11 = -v15;
					v10 = -v13;
					sub_548600(*(_DWORD*)(v0 + 8), v10, v11);
					sub_537610(*(_DWORD*)(v0 + 8));
					sub_548600(*(_DWORD*)(v0 + 12), v13, v15);
					sub_537610(*(_DWORD*)(v0 + 12));
					*(_DWORD*)(v0 + 36) = *(_DWORD*)(v0 + 32);
				}
			} else {
			LABEL_16:
				sub_511360(v0);
			}
			v0 = v2;
		} while (v2);
	}
}

//----- (005114D0) --------------------------------------------------------
void __cdecl sub_5114D0(int a1, int a2, int a3, int a4, int a5, int a6) {
	float* v6;      // eax
	double v7;      // st7
	double v8;      // st6
	long double v9; // st7

	if (a1 && a2 && !(*(_BYTE*)(a1 + 16) & 0x20) && !(*(_BYTE*)(a2 + 16) & 0x20)) {
		v6 = (float*)nox_alloc_class_new_obj_zero(*(_DWORD**)&dword_5d4594_2386568);
		if (v6) {
			*((_DWORD*)v6 + 4) = a3;
			*((_DWORD*)v6 + 5) = a4;
			*((_DWORD*)v6 + 2) = a1;
			*((_DWORD*)v6 + 3) = a2;
			*((_DWORD*)v6 + 6) = a5;
			*((_DWORD*)v6 + 7) = a6;
			v7 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
			v8 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
			v9 = sqrt(v8 * v8 + v7 * v7);
			v6[8] = v9;
			v6[9] = v9;
			sub_511560((int)v6);
		}
	}
}

//----- (00511560) --------------------------------------------------------
int __cdecl sub_511560(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 48) = 0;
	*(_DWORD*)(a1 + 44) = dword_5d4594_2386572;
	if (dword_5d4594_2386572)
		*(_DWORD*)(dword_5d4594_2386572 + 48) = a1;
	dword_5d4594_2386572 = a1;
	return result;
}

//----- (00511660) --------------------------------------------------------
int __cdecl sub_511660(_DWORD* a1, int a2) {
	int result;      // eax
	unsigned int v3; // edx
	int v4;          // ecx
	int v5;          // eax
	int v6;          // eax

	result = a1[4];
	if (!(result & 0x10000)) {
		if (result & 0x400000)
			sub_5116F0((int)a1);
		v3 = *(_DWORD*)&byte_5D4594[2598000] + a2;
		v4 = 0;
		a1[34] = *(_DWORD*)&byte_5D4594[2598000] + a2;
		v5 = dword_5d4594_2386576;
		if (!dword_5d4594_2386576)
			goto LABEL_14;
		do {
			if (v3 < *(int*)(v5 + 136))
				break;
			v4 = v5;
			v5 = *(_DWORD*)(v5 + 468);
		} while (v5);
		if (v4) {
			*(_DWORD*)(v4 + 468) = a1;
			if (!v5) {
				v6 = a1[4];
				a1[117] = 0;
				result = v6 | 0x400000;
				a1[4] = result;
				return result;
			}
		} else {
		LABEL_14:
			dword_5d4594_2386576 = a1;
		}
		a1[117] = v5;
		result = a1[4] | 0x400000;
		a1[4] = result;
	}
	return result;
}

//----- (005116F0) --------------------------------------------------------
int __cdecl sub_5116F0(int a1) {
	int result; // eax
	int v2;     // ecx

	result = *(_DWORD*)(a1 + 16);
	if (result & 0x400000) {
		v2 = 0;
		*(_DWORD*)(a1 + 16) = result & 0xFFBFFFFF;
		result = dword_5d4594_2386576;
		if (dword_5d4594_2386576) {
			while (result != a1) {
				v2 = result;
				result = *(_DWORD*)(result + 468);
				if (!result)
					return result;
			}
			if (result) {
				if (v2) {
					result = *(_DWORD*)(a1 + 468);
					*(_DWORD*)(v2 + 468) = result;
				} else {
					dword_5d4594_2386576 = *(_DWORD*)(a1 + 468);
				}
			}
		}
	}
	return result;
}

//----- (00511750) --------------------------------------------------------
void sub_511750() {
	_DWORD* v0; // esi
	_DWORD* v1; // edi
	int v2;     // edx

	v0 = *(_DWORD**)&dword_5d4594_2386576;
	if (dword_5d4594_2386576) {
		do {
			v1 = (_DWORD*)v0[117];
			if (v0[123]) {
				sub_5116F0((int)v0);
			} else {
				if (v0[34] > *(int*)&byte_5D4594[2598000])
					return;
				sub_5116F0((int)v0);
				v2 = v0[5];
				LOBYTE(v2) = v2 | 0x80;
				v0[5] = v2;
				sub_4E5CC0((int)v0);
			}
			v0 = v1;
		} while (v1);
	}
}

//----- (005117B0) --------------------------------------------------------
int sub_5117B0() {
	int result; // eax
	int v1;     // esi

	result = dword_5d4594_2386576;
	if (dword_5d4594_2386576) {
		do {
			v1 = *(_DWORD*)(result + 468);
			sub_5116F0(result);
			result = v1;
		} while (v1);
		dword_5d4594_2386576 = 0;
	} else {
		dword_5d4594_2386576 = 0;
	}
	return result;
}

//----- (005117F0) --------------------------------------------------------
char __cdecl sub_5117F0(int a1) {
	char result; // al

	result = a1;
	if (!(*(_BYTE*)(a1 + 8) & 1))
		result = sub_537610(a1);
	return result;
}

//----- (00511810) --------------------------------------------------------
void __cdecl sub_511810(int a1) {
	if (!(*(_BYTE*)(a1 + 8) & 1)) {
		if (sub_537580(a1))
			sub_5375A0(a1);
	}
}

//----- (00511850) --------------------------------------------------------
void sub_511850() {
	int v0; // esi
	int v1; // eax

	sub_5486D0();
	v0 = 5;
	do {
		sub_5118A0(0.2);
		sub_548B60();
		--v0;
	} while (v0);
	while (!sub_537590()) {
		v1 = sub_537700();
		if ((signed char)*(_BYTE*)(v1 + 8) >= 0)
			sub_4DA8D0(v1);
	}
	sub_548740();
}

//----- (005118A0) --------------------------------------------------------
int __cdecl sub_5118A0(float a1) {
	int i;               // esi
	int result;          // eax
	int j;               // esi
	double v4;           // st7
	float v5;            // ecx
	float* v6;           // edi
	unsigned __int8* v7; // edx
	char v8;             // al
	int v9;              // eax
	double v10;          // st7
	double v11;          // st6
	float v12;           // [esp+8h] [ebp-24h]
	float v13;           // [esp+10h] [ebp-1Ch]
	float v14;           // [esp+10h] [ebp-1Ch]
	float2 v15;          // [esp+14h] [ebp-18h]
	float4 v16;          // [esp+1Ch] [ebp-10h]

	if (!*(_DWORD*)&byte_5D4594[2386580]) {
		*(_DWORD*)&byte_5D4594[2386580] = sub_4E3AA0((CHAR*)&byte_587000[236824]);
		*(_DWORD*)&byte_5D4594[2386584] = sub_4E3AA0((CHAR*)&byte_587000[236844]);
		*(_DWORD*)&byte_5D4594[2386588] = sub_4E3AA0((CHAR*)&byte_587000[236864]);
		*(_DWORD*)&byte_5D4594[2386592] = sub_4E3AA0((CHAR*)&byte_587000[236884]);
		*(_DWORD*)&byte_5D4594[2386596] = sub_4E3AA0((CHAR*)&byte_587000[236900]);
		*(_DWORD*)&byte_5D4594[2386600] = sub_4E3AA0((CHAR*)&byte_587000[236920]);
		*(_DWORD*)&byte_5D4594[2386604] = sub_4E3AA0((CHAR*)&byte_587000[236944]);
		*(_DWORD*)&byte_5D4594[2386608] = sub_4E3AA0((CHAR*)&byte_587000[236968]);
		*(_DWORD*)&byte_5D4594[2386612] = sub_4E3AA0((CHAR*)&byte_587000[236992]);
		*(_DWORD*)&byte_5D4594[2386616] = sub_4E3AA0((CHAR*)&byte_587000[237012]);
	}
	for (i = sub_537740(); i; i = sub_537750(i))
		sub_5481C0(i);
	sub_5113A0();
	result = sub_537740();
	for (j = result; result; j = result) {
		if (*(_BYTE*)(j + 16) & 2 || *(_BYTE*)(j + 8) & 2 && sub_50A0D0(j, 67)) {
			*(_DWORD*)(j + 100) = 0;
			*(_DWORD*)(j + 96) = 0;
			*(_DWORD*)(j + 84) = 0;
			*(_DWORD*)(j + 80) = 0;
		} else {
			if (sub_4FF350(j, 5) || sub_4FF350(j, 25) || sub_4FF350(j, 28)) {
				v4 = *(float*)(j + 96);
				v13 = *(float*)(j + 100);
			} else {
				v4 = *(float*)(j + 96) + *(float*)(j + 88);
				v13 = *(float*)(j + 100) + *(float*)(j + 92);
			}
			v5 = *(float*)(j + 64);
			v6 = (float*)(j + 64);
			v14 = v13 - *(float*)(j + 84) * *(float*)(j + 112);
			*(float*)(j + 80) = (v4 - *(float*)(j + 112) * *(float*)(j + 80)) * a1 + *(float*)(j + 80);
			*(float*)(j + 84) = v14 * a1 + *(float*)(j + 84);
			v16.field_0 = v5;
			v16.field_4 = *(float*)(j + 68);
			v7 = &byte_5D4594[2386580];
			v16.field_8 = a1 * *(float*)(j + 80) + *(float*)(j + 64);
			v16.field_C = a1 * *(float*)(j + 84) + *(float*)(j + 68);
			v8 = (*(_DWORD*)(j + 16) >> 12) & 4 | 1;
			while (*(unsigned __int16*)(j + 4) != *(_DWORD*)v7) {
				v7 += 4;
				if ((int)v7 >= (int)&byte_5D4594[2386620])
					goto LABEL_20;
			}
			v8 = (*(_DWORD*)(j + 16) >> 12) & 4 | 0x41;
		LABEL_20:
			if (sub_535250(&v16, 0, 0, v8)) {
				*v6 = v16.field_8;
				*(float*)(j + 68) = v16.field_C;
			}
			v9 = *(_DWORD*)(j + 16);
			if (!(v9 & 0x4000) && *(_DWORD*)(j + 556) && sub_411160((float2*)(j + 64)) == 6) {
				v15.field_0 = 0.0;
				v15.field_4 = 0.0;
				sub_548630(j, 6u, &v15);
			}
			v10 = *v6 - *(float*)(j + 56);
			if (v10 < 0.0)
				v10 = -v10;
			v11 = *(float*)(j + 68) - *(float*)(j + 60);
			if (v11 < 0.0)
				v11 = -v11;
			if (v10 > 0.0099999998 || (v12 = v11, v12 > 0.0099999998)) {
				sub_4E44F0(j);
				sub_4E7290(j);
				sub_517970(j);
			}
		}
		result = sub_537750(j);
	}
	return result;
}

//----- (00511B60) --------------------------------------------------------
int __cdecl nox_server_scriptValToObjectPtr_511B60(int a1) {
	int result; // eax
	int v2;     // edi
	int v3;     // esi

	if (a1 == -1) {
		result = dword_5d4594_3821964;
		if (dword_5d4594_3821964 && !(*(_BYTE*)(dword_5d4594_3821964 + 16) & 0x20))
			return result;
		return 0;
	}
	if (a1 != -2) {
		result = sub_511C50(a1);
		if (result)
			return result;
		v2 = sub_4DA790();
		if (v2) {
			while (1) {
				if (!(*(_BYTE*)(v2 + 16) & 0x20) && *(_DWORD*)(v2 + 44) == a1) {
					sub_511D70(v2);
					return v2;
				}
				v3 = *(_DWORD*)(v2 + 504);
				if (v3)
					break;
			LABEL_17:
				v2 = sub_4DA7A0(v2);
				if (!v2)
					goto LABEL_18;
			}
			while (*(_BYTE*)(v3 + 16) & 0x20 || *(_DWORD*)(v3 + 44) != a1) {
				v3 = *(_DWORD*)(v3 + 496);
				if (!v3)
					goto LABEL_17;
			}
		} else {
		LABEL_18:
			v3 = sub_4DA870();
			if (!v3)
				return 0;
			while (*(_BYTE*)(v3 + 16) & 0x20 || *(_DWORD*)(v3 + 44) != a1) {
				result = sub_4DA880(v3);
				v3 = result;
				if (!result)
					return result;
			}
		}
		sub_511D70(v3);
		return v3;
	}
	result = dword_5d4594_3821968;
	if (!dword_5d4594_3821968 || *(_BYTE*)(dword_5d4594_3821968 + 16) & 0x20)
		return 0;
	return result;
}

//----- (00511C50) --------------------------------------------------------
int __cdecl sub_511C50(int a1) {
	_DWORD* v1; // esi

	if (dword_587000_237036)
		sub_511D20();
	v1 = *(_DWORD**)&byte_5D4594[2386820];
	if (!*(_DWORD*)&byte_5D4594[2386820])
		return 0;
	while (*(_BYTE*)(*v1 + 16) & 0x20 || *(_DWORD*)(*v1 + 44) != a1) {
		v1 = (_DWORD*)v1[2];
		if (!v1)
			return 0;
	}
	sub_511CE0(&byte_5D4594[2386820], (int)v1);
	sub_511CB0(&byte_5D4594[2386820], (int)v1);
	return *v1;
}

//----- (00511CB0) --------------------------------------------------------
int __cdecl sub_511CB0(_DWORD* a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a2 + 4) = 0;
	*(_DWORD*)(a2 + 8) = *a1;
	if (*a1)
		*(_DWORD*)(*a1 + 4) = a2;
	else
		a1[1] = a2;
	*a1 = a2;
	return result;
}

//----- (00511CE0) --------------------------------------------------------
int __cdecl sub_511CE0(_DWORD* a1, int a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // ecx

	result = a2;
	v3 = *(_DWORD*)(a2 + 8);
	if (v3)
		*(_DWORD*)(v3 + 4) = *(_DWORD*)(a2 + 4);
	else
		a1[1] = *(_DWORD*)(a2 + 4);
	v4 = *(_DWORD*)(a2 + 4);
	if (v4) {
		*(_DWORD*)(v4 + 8) = *(_DWORD*)(a2 + 8);
	} else {
		result = *(_DWORD*)(a2 + 8);
		*a1 = result;
	}
	return result;
}

//----- (00511D20) --------------------------------------------------------
int sub_511D20() {
	unsigned __int8* v0; // esi
	int result;          // eax

	v0 = &byte_5D4594[2386628];
	*(_DWORD*)&byte_5D4594[2386820] = 0;
	*(_DWORD*)&byte_5D4594[2386824] = 0;
	*(_DWORD*)&byte_5D4594[2386620] = 0;
	*(_DWORD*)&byte_5D4594[2386624] = 0;
	do {
		result = sub_511CB0(&byte_5D4594[2386620], (int)v0);
		v0 += 12;
	} while ((int)v0 < (int)&byte_5D4594[2386820]);
	dword_587000_237036 = 0;
	return result;
}

//----- (00511D70) --------------------------------------------------------
int __cdecl sub_511D70(int a1) {
	int* v1;    // eax
	int v2;     // esi
	int result; // eax
	int v4;     // [esp-8h] [ebp-8h]

	v1 = (int*)sub_511DC0();
	if (v1) {
		*v1 = a1;
		result = sub_511CB0(&byte_5D4594[2386820], (int)v1);
	} else {
		v2 = *(_DWORD*)&byte_5D4594[2386824];
		v4 = *(_DWORD*)&byte_5D4594[2386824];
		**(_DWORD**)&byte_5D4594[2386824] = a1;
		sub_511CE0(&byte_5D4594[2386820], v4);
		result = sub_511CB0(&byte_5D4594[2386820], v2);
	}
	return result;
}

//----- (00511DC0) --------------------------------------------------------
int sub_511DC0() {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[2386620];
	if (!*(_DWORD*)&byte_5D4594[2386620])
		return 0;
	*(_DWORD*)&byte_5D4594[2386620] = *(_DWORD*)(*(_DWORD*)&byte_5D4594[2386620] + 8);
	return result;
}

//----- (00511DE0) --------------------------------------------------------
int __cdecl sub_511DE0(int a1) {
	int result; // eax
	_DWORD* v2; // esi

	result = dword_587000_237036;
	if (!dword_587000_237036) {
		v2 = *(_DWORD**)&byte_5D4594[2386820];
		if (*(_DWORD*)&byte_5D4594[2386820]) {
			result = a1;
			while (*v2 != a1) {
				v2 = (_DWORD*)v2[2];
				if (!v2)
					return result;
			}
			sub_511CE0(&byte_5D4594[2386820], (int)v2);
			result = sub_511CB0(&byte_5D4594[2386620], (int)v2);
		}
	}
	return result;
}

//----- (00511E20) --------------------------------------------------------
int sub_511E20() {
	int result; // eax
	int v1;     // esi
	int v2;     // edi

	result = dword_587000_237036;
	if (!dword_587000_237036) {
		v1 = *(_DWORD*)&byte_5D4594[2386820];
		if (*(_DWORD*)&byte_5D4594[2386820]) {
			do {
				v2 = *(_DWORD*)(v1 + 8);
				sub_511CE0(&byte_5D4594[2386820], v1);
				result = sub_511CB0(&byte_5D4594[2386620], v1);
				v1 = v2;
			} while (v2);
		}
	}
	return result;
}

//----- (00511E60) --------------------------------------------------------
void sub_511E60() {
	if (!*(_DWORD*)&byte_5D4594[2386836])
		*(_DWORD*)&byte_5D4594[2386836] = sub_4E3AA0((CHAR*)&byte_587000[246804]);
	sub_5058F0();
	sub_51AC60();
	*(_DWORD*)&byte_5D4594[2386844] = 0;
	*(_DWORD*)&byte_5D4594[2386848] = 0;
	*(_DWORD*)&byte_5D4594[2386852] = 0;
}

//----- (00511EB0) --------------------------------------------------------
int sub_511EB0() {
	int v0; // edi
	int v1; // esi

	v0 = script_pop();
	v1 = script_pop();
	if (dword_5d4594_3821636 || dword_5d4594_3821640) {
		v1 = (*(int*)&dword_5d4594_3821636 + 23 * v1) / 23;
		v0 = (*(int*)&dword_5d4594_3821640 + 23 * v0) / 23;
	}
	if (nox_server_getWallAtPoint_410580(v1, v0))
		sub_507230(v0 | (v1 << 16));
	else
		sub_507230(0);
	return 0;
}

//----- (00511F50) --------------------------------------------------------
int sub_511F50() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_getWallAtPoint_410580(v0 >> 16, (unsigned __int16)v0);
	if (v1)
		sub_511F80(v1);
	return 0;
}

//----- (00511F80) --------------------------------------------------------
void __cdecl sub_511F80(int a1) {
	int v1;    // edx
	int v2;    // ecx
	char v3;   // al
	int v4;    // eax
	char* v5;  // eax
	int v6;    // eax
	float2 v7; // [esp+0h] [ebp-8h]
	int v8;    // [esp+Ch] [ebp+4h]

	v1 = a1;
	if (*(_BYTE*)(a1 + 4) & 4) {
		v2 = *(_DWORD*)(a1 + 28);
		v3 = *(_BYTE*)(v2 + 21);
		if (v3 != 3 && v3 != 4) {
			v4 = *(_DWORD*)(v2 + 4);
			*(_BYTE*)(v2 + 21) = 4;
			v8 = 23 * *(_DWORD*)(v2 + 8);
			v7.field_0 = (double)(23 * v4) + 11.5;
			v7.field_4 = (double)v8 + 11.5;
			if (!dword_5d4594_2386840) {
				v5 = sub_410EE0(*(unsigned __int8*)(v1 + 1));
				v6 = sub_40AF50(v5);
				sub_501A30(v6, &v7, 0, 0);
			}
		}
	}
}

//----- (00512010) --------------------------------------------------------
int sub_512010() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 2, (void(__cdecl*)(int, int))sub_511F80, 0);
	return 0;
}

//----- (00512040) --------------------------------------------------------
int sub_512040() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_getWallAtPoint_410580(v0 >> 16, (unsigned __int16)v0);
	if (v1)
		sub_512070(v1);
	return 0;
}

//----- (00512070) --------------------------------------------------------
void __cdecl sub_512070(int a1) {
	int v1;    // edx
	int v2;    // ecx
	char v3;   // al
	int v4;    // eax
	char* v5;  // eax
	int v6;    // eax
	float2 v7; // [esp+0h] [ebp-8h]
	int v8;    // [esp+Ch] [ebp+4h]

	v1 = a1;
	if (*(_BYTE*)(a1 + 4) & 4) {
		v2 = *(_DWORD*)(a1 + 28);
		v3 = *(_BYTE*)(v2 + 21);
		if (v3 != 1 && v3 != 2) {
			v4 = *(_DWORD*)(v2 + 4);
			*(_BYTE*)(v2 + 21) = 2;
			v8 = 23 * *(_DWORD*)(v2 + 8);
			v7.field_0 = (double)(23 * v4) + 11.5;
			v7.field_4 = (double)v8 + 11.5;
			if (!dword_5d4594_2386840) {
				v5 = sub_410F20(*(unsigned __int8*)(v1 + 1));
				v6 = sub_40AF50(v5);
				sub_501A30(v6, &v7, 0, 0);
			}
		}
	}
}

//----- (00512100) --------------------------------------------------------
int sub_512100() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 2, (void(__cdecl*)(int, int))sub_512070, 0);
	return 0;
}

//----- (00512130) --------------------------------------------------------
int sub_512130() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_getWallAtPoint_410580(v0 >> 16, (unsigned __int16)v0);
	if (v1)
		sub_512160(v1);
	return 0;
}

//----- (00512160) --------------------------------------------------------
void __cdecl sub_512160(int a1) {
	int v1;    // eax
	char v2;   // cl
	int v3;    // ecx
	char* v4;  // eax
	int v5;    // ecx
	int v6;    // eax
	float2 v7; // [esp+4h] [ebp-8h]

	if (*(_BYTE*)(a1 + 4) & 4) {
		v1 = *(_DWORD*)(a1 + 28);
		v2 = *(_BYTE*)(v1 + 21);
		if (v2 == 1 || v2 == 2) {
			v5 = *(_DWORD*)(v1 + 4);
			*(_BYTE*)(v1 + 21) = 4;
			v7.field_0 = (double)(23 * v5) + 11.5;
			v7.field_4 = (double)(int)(23 * *(_DWORD*)(v1 + 8)) + 11.5;
			if (dword_5d4594_2386840)
				return;
			v4 = sub_410EE0(*(unsigned __int8*)(a1 + 1));
		} else {
			v3 = *(_DWORD*)(v1 + 4);
			*(_BYTE*)(v1 + 21) = 2;
			v7.field_0 = (double)(23 * v3) + 11.5;
			v7.field_4 = (double)(int)(23 * *(_DWORD*)(v1 + 8)) + 11.5;
			if (dword_5d4594_2386840)
				return;
			v4 = sub_410F20(*(unsigned __int8*)(a1 + 1));
		}
		v6 = sub_40AF50(v4);
		sub_501A30(v6, &v7, 0, 0);
	}
}

//----- (00512260) --------------------------------------------------------
int sub_512260() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 2, (void(__cdecl*)(int, int))sub_512160, 0);
	return 0;
}

//----- (00512290) --------------------------------------------------------
int sub_512290() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_getWallAtPoint_410580(v0 >> 16, (unsigned __int16)v0);
	if (v1)
		sub_5122C0(v1);
	return 0;
}

//----- (005122C0) --------------------------------------------------------
int __cdecl sub_5122C0(int a1) {
	int v1;  // edx
	int2 v3; // [esp+0h] [ebp-8h]

	v1 = *(unsigned __int8*)(a1 + 6);
	v3.field_0 = *(unsigned __int8*)(a1 + 5);
	v3.field_4 = v1;
	return sub_534DA0(&v3);
}

//----- (005122F0) --------------------------------------------------------
int sub_5122F0() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 2, (void(__cdecl*)(int, int))sub_5122C0, 0);
	return 0;
}

//----- (00512320) --------------------------------------------------------
int sub_512320() {
	int v0; // esi
	int v1; // eax

	v0 = script_pop();
	v1 = script_pop();
	sub_51ACA0(v1 * *(_DWORD*)&byte_5D4594[2649704], v0, 0);
	return 0;
}

//----- (00512350) --------------------------------------------------------
int sub_512350() {
	int v0; // esi
	int v1; // eax

	v0 = script_pop();
	v1 = script_pop();
	sub_51ACA0(v1, v0, 0);
	return 0;
}

//----- (00512370) --------------------------------------------------------
int sub_512370() {
	int v0;     // edi
	int v1;     // eax
	int v2;     // eax
	int v3;     // esi
	int v4;     // eax
	_DWORD* v5; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = v2;
	if (v2) {
		v4 = *(_DWORD*)(v2 + 16);
		if ((v4 & 0x8000) == 0) {
			v5 = nox_server_getWaypointById_579C40(v0);
			if (v5)
				nox_server_scriptMoveTo_5123C0(v3, (int)v5);
		}
	}
	return 0;
}

//----- (005123C0) --------------------------------------------------------
int* __cdecl nox_server_scriptMoveTo_5123C0(int a1, int a2) {
	int* result; // eax
	int v3;      // ebx
	int* v4;     // eax
	int* v5;     // eax
	int* i;      // esi

	result = *(int**)(a1 + 16);
	if (SBYTE1(result) >= 0) {
		if (*(_BYTE*)(a1 + 8) & 2) {
			v3 = *(_DWORD*)(a1 + 748);
			sub_50A3A0(a1);
			v4 = sub_50A260(a1, 32);
			if (v4)
				v4[1] = 8;
			if (*(_BYTE*)(a2 + 476)) {
				v5 = sub_50A260(a1, 10);
				if (v5) {
					v5[1] = a2;
					*((_BYTE*)v5 + 12) = *(_BYTE*)(v3 + 1332);
				}
			}
			result = sub_50A260(a1, 8);
			if (result) {
				result[1] = *(_DWORD*)(a2 + 8);
				result[2] = *(_DWORD*)(a2 + 12);
				result[3] = 0;
			}
		} else if (*(unsigned __int16*)(a1 + 4) == *(_DWORD*)&byte_5D4594[2386836]) {
			result = (int*)sub_5124C0((_DWORD*)a1, (_DWORD*)a2);
		} else {
			result = (int*)sub_4DA790();
			for (i = result; result; i = result) {
				if (*((unsigned __int16*)i + 2) == *(_DWORD*)&byte_5D4594[2386836] &&
				    *(_DWORD*)(i[187] + 32) == *(_DWORD*)(a1 + 40)) {
					sub_5124C0(i, (_DWORD*)a2);
				}
				result = (int*)sub_4DA7A0((int)i);
			}
		}
	}
	return result;
}

//----- (005124C0) --------------------------------------------------------
int __cdecl sub_5124C0(_DWORD* a1, _DWORD* a2) {
	int v2; // edi

	v2 = a1[187];
	sub_4E75B0((int)a1);
	a1[20] = 0;
	a1[21] = 0;
	*(_BYTE*)v2 = 0;
	*(_DWORD*)(v2 + 8) = *a2;
	return sub_4DA8D0((int)a1);
}

//----- (00512500) --------------------------------------------------------
int nox_server_scriptGroupGoTo_512500() {
	int v0;     // esi
	int v1;     // eax
	int v2;     // edi
	_DWORD* v3; // ebx
	int* i;     // esi
	int v5;     // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptGetGroup_57C0A0(v1);
	v3 = nox_server_getWaypointById_579C40(v0);
	if (v3) {
		if (v2) {
			for (i = *(int**)(v2 + 84); i; i = (int*)i[2]) {
				v5 = sub_4ED020(*i);
				if (v5)
					nox_server_scriptMoveTo_5123C0(v5, (int)v3);
			}
		}
	}
	return 0;
}

//----- (00512560) --------------------------------------------------------
int sub_512560() {
	int v0; // esi
	int v1; // eax
	int v2; // eax
	int v3; // ecx

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		if (*(_BYTE*)(v2 + 8) & 2) {
			v3 = *(_DWORD*)(v2 + 16);
			if ((v3 & 0x8000) == 0)
				sub_5125A0(v2, v0);
		}
	}
	return 0;
}

//----- (005125A0) --------------------------------------------------------
float* __cdecl sub_5125A0(int a1, int a2) {
	float* result; // eax
	int v3;        // edx
	float v4;      // [esp+0h] [ebp-8h]
	float v5;      // [esp+4h] [ebp-4h]

	result = (float*)sub_509E90(a2);
	if (*(_BYTE*)(a1 + 8) & 2) {
		v3 = *(_DWORD*)(a1 + 16);
		if ((v3 & 0x8000) == 0) {
			v4 = *(float*)&byte_587000[8 * (_DWORD)result + 194136] * 10.0 + *(float*)(a1 + 56);
			v5 = *(float*)&byte_587000[8 * (_DWORD)result + 194140] * 10.0 + *(float*)(a1 + 60);
			result = (float*)sub_50A260(a1, 25);
			if (result) {
				result[1] = v4;
				result[2] = v5;
			}
		}
	}
	return result;
}

//----- (00512610) --------------------------------------------------------
int sub_512610() {
	int v0;     // edi
	int v1;     // eax
	int result; // eax
	int* i;     // esi
	int v4;     // eax
	int v5;     // ecx

	v0 = script_pop();
	v1 = script_pop();
	result = nox_server_scriptGetGroup_57C0A0(v1);
	if (result) {
		for (i = *(int**)(result + 84); i; i = (int*)i[2]) {
			v4 = sub_4ED020(*i);
			if (v4 && *(_BYTE*)(v4 + 8) & 2) {
				v5 = *(_DWORD*)(v4 + 16);
				if ((v5 & 0x8000) == 0)
					sub_5125A0(v4, v0);
			}
		}
		result = 0;
	}
	return result;
}

//----- (00512670) --------------------------------------------------------
int sub_512670() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_4E75B0(v1);
	return 0;
}

//----- (00512690) --------------------------------------------------------
int sub_512690() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_5126C0, 0);
	return 0;
}

//----- (005126C0) --------------------------------------------------------
char __cdecl sub_5126C0(int a1) { return sub_4E75B0(a1); }

//----- (005126D0) --------------------------------------------------------
int sub_5126D0() {
	int v0;     // eax
	_DWORD* v1; // eax

	v0 = script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1)
		v1[120] |= 1u;
	return 0;
}

//----- (005126F0) --------------------------------------------------------
int sub_5126F0() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 1, (void(__cdecl*)(int, int))sub_512720, 0);
	return 0;
}

//----- (00512720) --------------------------------------------------------
int __cdecl sub_512720(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 480) |= 1u;
	return result;
}

//----- (00512730) --------------------------------------------------------
int sub_512730() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_4E7600(v1);
	return 0;
}

//----- (00512750) --------------------------------------------------------
int sub_512750() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_512780, 0);
	return 0;
}

//----- (00512780) --------------------------------------------------------
int __cdecl sub_512780(int a1) { return sub_4E7600(a1); }

//----- (00512790) --------------------------------------------------------
int sub_512790() {
	int v0;     // eax
	_DWORD* v1; // eax

	v0 = script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1)
		v1[120] &= 0xFFFFFFFE;
	return 0;
}

//----- (005127B0) --------------------------------------------------------
int sub_5127B0() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 1, (void(__cdecl*)(int, int))sub_5127E0, 0);
	return 0;
}

//----- (005127E0) --------------------------------------------------------
int __cdecl sub_5127E0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 480) &= 0xFFFFFFFE;
	return result;
}

//----- (005127F0) --------------------------------------------------------
int sub_5127F0() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_4E7650(v1);
	return 0;
}

//----- (00512810) --------------------------------------------------------
int sub_512810() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_512840, 0);
	return 0;
}

//----- (00512840) --------------------------------------------------------
char __cdecl sub_512840(int a1) { return sub_4E7650(a1); }

//----- (00512850) --------------------------------------------------------
int sub_512850() {
	int v0;     // eax
	_DWORD* v1; // eax

	v0 = script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1)
		v1[120] ^= 1u;
	return 0;
}

//----- (00512870) --------------------------------------------------------
int sub_512870() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 1, (void(__cdecl*)(int, int))sub_5128A0, 0);
	return 0;
}

//----- (005128A0) --------------------------------------------------------
int __cdecl sub_5128A0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 480) ^= 1u;
	return result;
}

//----- (005128B0) --------------------------------------------------------
int sub_5128B0() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_4E5CC0(v1);
	return 0;
}

//----- (005128D0) --------------------------------------------------------
int sub_5128D0() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_512900, 0);
	return 0;
}

//----- (00512900) --------------------------------------------------------
void __cdecl sub_512900(int a1) { sub_4E5CC0(a1); }

//----- (00512910) --------------------------------------------------------
int sub_512910() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_512930(v1);
	return 0;
}

//----- (00512930) --------------------------------------------------------
void __cdecl sub_512930(int a1) {
	int v1;  // eax
	int v2;  // edi
	int* v3; // eax
	int* v4; // eax

	if (*(_BYTE*)(a1 + 8) & 2) {
		v1 = *(_DWORD*)(a1 + 16);
		if ((v1 & 0x8000) == 0) {
			v2 = *(_DWORD*)(a1 + 748);
			sub_50A3A0(a1);
			v3 = sub_50A260(a1, 32);
			if (v3)
				v3[1] = 10;
			v4 = sub_50A260(a1, 10);
			if (v4) {
				v4[1] = 0;
				*((_BYTE*)v4 + 12) = *(_BYTE*)(v2 + 1332);
			}
		}
	}
}

//----- (00512990) --------------------------------------------------------
int sub_512990() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_512930, 0);
	return 0;
}

//----- (005129C0) --------------------------------------------------------
int sub_5129C0() {
	int v0; // eax

	v0 = script_pop();
	nox_server_scriptValToObjectPtr_511B60(v0);
	return 0;
}

//----- (005129E0) --------------------------------------------------------
int sub_5129E0() {
	int v0; // eax

	v0 = script_pop();
	nox_server_scriptValToObjectPtr_511B60(v0);
	return 0;
}

//----- (00512A00) --------------------------------------------------------
int sub_512A00() {
	int v0;     // eax
	int result; // eax
	int v2;     // esi
	int v3;     // eax
	_DWORD* v4; // edi
	int* v5;    // eax
	int* v6;    // eax
	int* v7;    // eax

	v0 = script_pop();
	result = nox_server_scriptValToObjectPtr_511B60(v0);
	v2 = result;
	if (result) {
		if (*(_BYTE*)(result + 8) & 2) {
			v3 = *(_DWORD*)(result + 16);
			if ((v3 & 0x8000) == 0) {
				v4 = *(_DWORD**)(v2 + 748);
				sub_50A3A0(v2);
				v5 = sub_50A260(v2, 32);
				if (v5)
					v5[1] = 37;
				v6 = sub_50A260(v2, 25);
				if (v6) {
					*((float*)v6 + 1) =
					    *(float*)&byte_587000[8 * v4[94] + 194136] * 10.0 + *(float*)(v2 + 56);
					*((float*)v6 + 2) =
					    *(float*)&byte_587000[8 * v4[94] + 194140] * 10.0 + *(float*)(v2 + 60);
				}
				v7 = sub_50A260(v2, 37);
				if (v7) {
					v7[1] = v4[95];
					v7[2] = v4[96];
					v7[3] = 0;
				}
				result = 0;
			} else {
				result = 0;
			}
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (00512AC0) --------------------------------------------------------
int sub_512AC0() {
	int v0;     // esi
	int v1;     // edi
	float2* v2; // eax
	int v3;     // eax
	float2* v5; // [esp-Ch] [ebp-14h]

	v0 = script_pop();
	v1 = script_pop();
	v2 = (float2*)nox_server_getWaypointById_579C40(v0);
	if (v2) {
		v5 = v2 + 1;
		v3 = sub_40AF50(*(void**)&byte_5D4594[4 * v1 + 3831212]);
		sub_501A30(v3, v5, 0, 0);
	}
	return 0;
}

//----- (00512C10) --------------------------------------------------------
int sub_512C10() { return 1; }

//----- (00512C20) --------------------------------------------------------
int sub_512C20() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && (*(_BYTE*)(v1 + 8) & 0x80)) {
		*(_BYTE*)(*(_DWORD*)(v1 + 748) + 1) = 0;
		sub_501960(234, v1, 0, 0);
	}
	return 0;
}

//----- (00512C60) --------------------------------------------------------
int sub_512C60() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && (*(_BYTE*)(v1 + 8) & 0x80)) {
		*(_BYTE*)(*(_DWORD*)(v1 + 748) + 1) = 5;
		sub_501960(233, v1, 0, 0);
	}
	return 0;
}

//----- (00512CA0) --------------------------------------------------------
int sub_512CA0() {
	int v0;     // eax
	int v1;     // eax
	int result; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && *(_DWORD*)(v1 + 16) & 0x1000000) {
		sub_507230(1);
		result = 0;
	} else {
		sub_507230(0);
		result = 0;
	}
	return result;
}

//----- (00512CE0) --------------------------------------------------------
int sub_512CE0() {
	int v0;     // eax
	_DWORD* v1; // eax
	int result; // eax

	v0 = script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1 && v1[120] & 1) {
		sub_507230(1);
		result = 0;
	} else {
		sub_507230(0);
		result = 0;
	}
	return result;
}

//----- (00512D20) --------------------------------------------------------
int sub_512D20() {
	int v0;     // eax
	int v1;     // eax
	int result; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && (*(_BYTE*)(v1 + 8) & 0x80)) {
		sub_507230(*(_BYTE*)(*(_DWORD*)(v1 + 748) + 1) != 0);
		result = 0;
	} else {
		sub_507230(0);
		result = 0;
	}
	return result;
}

//----- (00512D70) --------------------------------------------------------
int sub_512D70() {
	int v0; // esi
	int v1; // eax
	int v3; // [esp+0h] [ebp-4h]

	v0 = script_pop();
	v1 = script_pop();
	*(float*)&v3 = sub_416030(*(float*)&v1, *(float*)&v0);
	sub_507230(v3);
	return 0;
}

//----- (00512DB0) --------------------------------------------------------
int sub_512DB0() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_common_randomInt_415FA0(v1, v0);
	sub_507230(v2);
	return 0;
}

//----- (00512DE0) --------------------------------------------------------
int sub_512DE0() {
	int v0; // esi
	int v1; // edi
	int v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	sub_51ACA0(v2 * *(_DWORD*)&byte_5D4594[2649704], v0, v1);
	return 0;
}

//----- (00512E10) --------------------------------------------------------
int sub_512E10() {
	int v0; // esi
	int v1; // edi
	int v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	sub_51ACA0(v2, v0, v1);
	return 0;
}

//----- (00512E40) --------------------------------------------------------
int __cdecl sub_512E40(char* a1) {
	char* v1; // eax
	int v2;   // ecx

	if (dword_5d4594_1599632 >= 1024)
		return dword_5d4594_1599632 - 1;
	v1 = _strdup(a1);
	v2 = dword_5d4594_1599632;
	*(_DWORD*)&byte_5D4594[4 * dword_5d4594_1599632 + 3831212] = v1;
	dword_5d4594_1599632 = v2 + 1;
	return v2;
}

//----- (00512EA0) --------------------------------------------------------
int sub_512EA0() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	_itoa(v0, (char*)&byte_5D4594[3821708], 10);
	v1 = sub_512E40((char*)&byte_5D4594[3821708]);
	sub_507230(v1);
	return 0;
}

//----- (00512ED0) --------------------------------------------------------
int sub_512ED0() {
	float v0; // eax
	int v1;   // eax

	v0 = COERCE_FLOAT(script_pop());
	nox_sprintf((char*)&byte_5D4594[3821708], "%f", v0, v0);
	v1 = sub_512E40((char*)&byte_5D4594[3821708]);
	sub_507230(v1);
	return 0;
}

//----- (00512F10) --------------------------------------------------------
int sub_512F10() {
	int v0;     // esi
	int v1;     // edi
	float* v2;  // esi
	_DWORD* v3; // eax
	_DWORD* v4; // edi

	v0 = script_pop();
	v1 = script_pop();
	v2 = (float*)nox_server_getWaypointById_579C40(v0);
	if (v2) {
		v3 = sub_4E3810(*(CHAR**)&byte_5D4594[4 * v1 + 3831212]);
		v4 = v3;
		if (!v3) {
			sub_507230(0);
			return 0;
		}
		sub_4DAA50((int)v3, 0, v2[2], v2[3]);
		sub_507230(v4[11]);
	}
	return 0;
}

//----- (00512F80) --------------------------------------------------------
int sub_512F80() {
	int v0;    // edi
	int v1;    // ebx
	int v2;    // ebp
	int v3;    // eax
	int v4;    // esi
	int v6[3]; // [esp+10h] [ebp-Ch]

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	v3 = script_pop();
	v4 = nox_server_scriptValToObjectPtr_511B60(v3);
	if (v4) {
		v6[0] = nox_server_scriptValToObjectPtr_511B60(v2);
		v6[1] = v1;
		v6[2] = v0;
		sub_512FE0(v4, v6);
	}
	return 0;
}

//----- (00512FE0) --------------------------------------------------------
void __cdecl sub_512FE0(int a1, int* a2) {
	int v2; // eax
	int v3; // [esp-Ch] [ebp-Ch]
	int v4; // [esp-8h] [ebp-8h]
	int v5; // [esp-4h] [ebp-4h]

	if (a2[1] > 0) {
		v5 = a2[2];
		v4 = a2[1];
		v3 = *a2;
		v2 = sub_4EC580(*a2);
		(*(void(__cdecl**)(int, int, int, int, int))(a1 + 716))(a1, v2, v3, v4, v5);
	}
}

//----- (00513010) --------------------------------------------------------
int sub_513010() {
	int v0;              // esi
	int v1;              // edi
	int v2;              // ebx
	int v3;              // ebp
	unsigned __int8* v4; // eax
	int v6[3];

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	v3 = script_pop();
	v6[0] = nox_server_scriptValToObjectPtr_511B60(v2);
	v6[1] = v1;
	v6[2] = v0;
	v4 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v3);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v4, 0, (void(__cdecl*)(int, int))sub_512FE0, (int)v6);
	return 0;
}

//----- (00513070) --------------------------------------------------------
int sub_513070() {
	int v0;    // edi
	int v1;    // eax
	int v2;    // esi
	float v4;  // [esp+8h] [ebp-10h]
	int v5[3]; // [esp+Ch] [ebp-Ch]

	v4 = COERCE_FLOAT(script_pop());
	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v5[1] = v0;
		v5[0] = (__int64)v4;
		sub_5130E0(v2, v5);
		sub_507230(v5[2]);
	} else {
		sub_507230(0);
	}
	return 0;
}

//----- (005130E0) --------------------------------------------------------
_DWORD* __cdecl sub_5130E0(int a1, _DWORD* a2) {
	_DWORD* v2;     // eax
	_DWORD* v3;     // esi
	_DWORD* result; // eax
	int v5;         // eax

	v2 = sub_4E3810((CHAR*)&byte_587000[247016]);
	v3 = v2;
	if (v2) {
		sub_4DAA50((int)v2, 0, *(float*)(a1 + 56), *(float*)(a1 + 60));
		v5 = v3[187];
		*(_DWORD*)(v5 + 28) = a1;
		*(_DWORD*)(v5 + 8) = a2[1];
		*(_DWORD*)(v5 + 4) = *a2;
		*(_BYTE*)v5 = 0;
		v3[20] = 0;
		v3[21] = 0;
		sub_4E75B0((int)v3);
		sub_4DA8D0((int)v3);
		result = (_DWORD*)v3[11];
		a2[2] = result;
	} else {
		result = a2;
		a2[2] = 0;
	}
	return result;
}

//----- (00513160) --------------------------------------------------------
int sub_513160() {
	int v0;              // esi
	int v1;              // edi
	unsigned __int8* v2; // eax
	float v4;            // [esp+8h] [ebp-10h]
	int v5[3];           // [esp+Ch] [ebp-Ch]

	v4 = COERCE_FLOAT(script_pop());
	v0 = script_pop();
	v1 = script_pop();
	v5[1] = v0;
	v5[0] = (__int64)v4;
	v2 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v1);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v2, 0, (void(__cdecl*)(int, int))sub_5130E0, (int)v5);
	return 0;
}

//----- (005131C0) --------------------------------------------------------
int sub_5131C0() {
	int v0;     // esi
	int v1;     // edi
	int v2;     // esi
	int result; // eax
	int v4;     // eax
	int v5;     // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = sub_4243F0(*(const char**)&byte_5D4594[4 * v0 + 3831212]);
	if (v2) {
		v4 = nox_server_scriptValToObjectPtr_511B60(v1);
		if (v4) {
			v5 = sub_4FB550_magic_plyrspel(v4, v2, 1, 0, 0);
			sub_507230(v5);
		} else {
			sub_507230(0);
		}
		result = 0;
	} else {
		sub_507230(0);
		result = 0;
	}
	return result;
}

//----- (00513230) --------------------------------------------------------
int sub_513230() {
	int v0;              // esi
	int v1;              // edi
	unsigned __int8* v2; // eax
	int v4;              // [esp+8h] [ebp-4h]

	v0 = script_pop();
	v1 = script_pop();
	v4 = sub_4243F0(*(const char**)&byte_5D4594[4 * v0 + 3831212]);
	if (v4) {
		v2 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v1);
		nox_server_scriptExecuteFnForEachGroupObj_502670(v2, 0, (void(__cdecl*)(int, int))sub_513280, (int)&v4);
	}
	return 0;
}

//----- (00513280) --------------------------------------------------------
int __cdecl sub_513280(int a1, int* a2) {
	int v2; // esi

	v2 = 0;
	if (nox_common_gameFlags_check_40A5C0(2048) && *(_BYTE*)(a1 + 8) & 4 &&
	    !*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 4 * *a2 + 3696)) {
		v2 = 1;
	}
	return sub_4FB550_magic_plyrspel(a1, *a2, 1, v2, 0);
}

//----- (005132E0) --------------------------------------------------------
int sub_5132E0() {
	int v0;      // esi
	int v1;      // ebx
	int v2;      // esi
	int v3;      // edi
	float v5;    // [esp+Ch] [ebp-54h]
	int v6[2];   // [esp+18h] [ebp-48h]
	char v8[64]; // [esp+20h] [ebp-40h]

	v5 = COERCE_FLOAT(script_pop());
	v0 = script_pop();
	v1 = script_pop();
	strcpy(v8, *(const char**)&byte_5D4594[4 * v0 + 3831212]);
	v2 = sub_424880(v8);
	if (v2 != -1) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v1);
		if (v3) {
			v6[0] = v2;
			v6[1] = (__int64)((double)*(unsigned int*)&byte_5D4594[2649704] * v5);
			sub_513390(v3, v6);
		}
	}
	return 0;
}

//----- (00513390) --------------------------------------------------------
__int16 __cdecl sub_513390(int a1, int* a2) { return sub_4FF380(a1, *a2, a2[1], 5); }

//----- (005133B0) --------------------------------------------------------
int sub_5133B0() {
	int v0;              // esi
	int v1;              // ebx
	int v2;              // eax
	unsigned __int8* v3; // eax
	float v5;            // [esp+Ch] [ebp-54h]
	int v6[2];           // [esp+18h] [ebp-48h]
	char v7[64];         // [esp+20h] [ebp-40h]

	v5 = COERCE_FLOAT(script_pop());
	v0 = script_pop();
	v1 = script_pop();
	strcpy(v7, *(const char**)&byte_5D4594[4 * v0 + 3831212]);
	v2 = sub_424880(v7);
	if (v2 != -1) {
		v6[0] = v2;
		v6[1] = (__int64)((double)*(unsigned int*)&byte_5D4594[2649704] * v5);
		v3 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v1);
		nox_server_scriptExecuteFnForEachGroupObj_502670(v3, 0, (void(__cdecl*)(int, int))sub_513390, (int)v6);
	}
	return 0;
}

//----- (00513460) --------------------------------------------------------
int sub_513460() {
	int v0; // eax

	v0 = *((_DWORD*)sub_417090(31) + 514);
	if (v0)
		sub_507230(*(_DWORD*)(v0 + 44));
	else
		sub_507230(0);
	return 0;
}

//----- (00513490) --------------------------------------------------------
int sub_513490() {
	int v0;      // eax
	char v2[76]; // [esp+4h] [ebp-4Ch]

	strcpy(v2, *(const char**)&byte_5D4594[4 * script_pop() + 3831212]);
	strcat(v2, (const char*)&byte_5D4594[3821644]);
	v0 = sub_4DA4F0(v2);
	if (v0)
		sub_507230(*(_DWORD*)(v0 + 44));
	else
		sub_507230(0);
	return 0;
}

//----- (00513530) --------------------------------------------------------
int sub_513530() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_507230(*(_DWORD*)(v1 + 56));
	else
		sub_507230(0);
	return 0;
}

//----- (00513570) --------------------------------------------------------
int sub_513570() {
	int v0;     // eax
	_DWORD* v1; // eax

	v0 = script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1)
		sub_507230(v1[2]);
	else
		sub_507230(0);
	return 0;
}

//----- (005135B0) --------------------------------------------------------
int sub_5135B0() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_507230(*(_DWORD*)(v1 + 60));
	else
		sub_507230(0);
	return 0;
}

//----- (005135F0) --------------------------------------------------------
int sub_5135F0() {
	int v0;     // eax
	_DWORD* v1; // eax

	v0 = script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1)
		sub_507230(v1[3]);
	else
		sub_507230(0);
	return 0;
}

//----- (00513630) --------------------------------------------------------
int sub_513630() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_507230(*(_DWORD*)(v1 + 104));
	else
		sub_507230(0);
	return 0;
}

//----- (00513670) --------------------------------------------------------
int sub_513670() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_507230(*(__int16*)(v1 + 124));
	else
		sub_507230(0);
	return 0;
}

//----- (005136A0) --------------------------------------------------------
int sub_5136A0() {
	int v0;    // eax
	int v1;    // eax
	float2 v3; // [esp+0h] [ebp-Ch]
	float v4;  // [esp+8h] [ebp-4h]

	v4 = COERCE_FLOAT(script_pop());
	LODWORD(v3.field_0) = script_pop();
	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v3.field_0 = (double)*(int*)&dword_5d4594_3821636 + v3.field_0;
		v3.field_4 = (double)*(int*)&dword_5d4594_3821640 + v4;
		sub_4E7010(v1, &v3);
	}
	return 0;
}

//----- (00513700) --------------------------------------------------------
int sub_513700() {
	int v0;    // eax
	float* v1; // eax
	float v3;  // [esp+0h] [ebp-8h]
	float v4;  // [esp+4h] [ebp-4h]

	v4 = COERCE_FLOAT(script_pop());
	v3 = COERCE_FLOAT(script_pop());
	v0 = script_pop();
	v1 = (float*)nox_server_getWaypointById_579C40(v0);
	if (v1) {
		v1[2] = (double)*(int*)&dword_5d4594_3821636 + v3;
		v1[3] = (double)*(int*)&dword_5d4594_3821640 + v4;
	}
	return 0;
}

//----- (00513750) --------------------------------------------------------
int sub_513750() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2)
		sub_4E46F0(v2, *(float*)&v0);
	return 0;
}

//----- (00513780) --------------------------------------------------------
int sub_513780() {
	int v0;          // esi
	int v1;          // eax
	int v2;          // eax
	unsigned int v3; // ecx

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = v0;
		if (v0 < 0)
			v3 = v0 + ((unsigned int)(255 - v0) >> 8 << 8);
		if ((int)v3 >= 256)
			LOWORD(v3) = -256 * (v3 >> 8) + v3;
		*(_WORD*)(v2 + 126) = v3;
		*(_WORD*)(v2 + 124) = v3;
	}
	return 0;
}

//----- (005137D0) --------------------------------------------------------
int sub_5137D0() {
	int v0;   // eax
	int v1;   // eax
	float v3; // [esp+0h] [ebp-8h]
	float v4; // [esp+4h] [ebp-4h]

	v4 = COERCE_FLOAT(script_pop());
	v3 = COERCE_FLOAT(script_pop());
	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		*(float*)(v1 + 88) = v3 + *(float*)(v1 + 88);
		*(float*)(v1 + 92) = v4 + *(float*)(v1 + 92);
	}
	return 0;
}

//----- (00513820) --------------------------------------------------------
int sub_513820() {
	int v0;    // eax
	float* v1; // eax
	double v2; // st7
	double v3; // st6
	float v5;  // [esp+0h] [ebp-Ch]
	float v6;  // [esp+0h] [ebp-Ch]
	float v7;  // [esp+4h] [ebp-8h]
	float v8;  // [esp+8h] [ebp-4h]
	float v9;  // [esp+8h] [ebp-4h]

	v5 = COERCE_FLOAT(script_pop());
	v8 = COERCE_FLOAT(script_pop());
	v7 = COERCE_FLOAT(script_pop());
	v0 = script_pop();
	v1 = (float*)nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = v1[14] - v8 + (double)*(int*)&dword_5d4594_3821636;
		v3 = v1[15] - v5 + (double)*(int*)&dword_5d4594_3821640;
		v6 = v3;
		v9 = sqrt(v3 * v6 + v2 * v2);
		v1[22] = v7 * v2 / v9 + v1[22];
		v1[23] = v7 * v6 / v9 + v1[23];
	}
	return 0;
}

//----- (005138B0) --------------------------------------------------------
int sub_5138B0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax
	int v3; // eax

	v0 = script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2) {
		v3 = *(_DWORD*)(v2 + 504);
		if (v3)
			v1 = *(_DWORD*)(v3 + 44);
	}
	sub_507230(v1);
	return 0;
}

//----- (005138E0) --------------------------------------------------------
int sub_5138E0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax
	int v3; // eax

	v0 = script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2) {
		v3 = *(_DWORD*)(v2 + 496);
		if (v3)
			v1 = *(_DWORD*)(v3 + 44);
	}
	sub_507230(v1);
	return 0;
}

//----- (00513910) --------------------------------------------------------
int sub_513910() {
	int v0; // edi
	int v1; // eax
	int v2; // esi
	int v3; // eax
	int v4; // edi

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptValToObjectPtr_511B60(v0);
	v4 = 0;
	if (v2 && v3 && sub_4F78E0(v2, v3))
		v4 = 1;
	sub_507230(v4);
	return 0;
}

//----- (00513960) --------------------------------------------------------
int sub_513960() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_507230(*(_DWORD*)(*(_DWORD*)(v1 + 492) + 44));
	else
		sub_507230(0);
	return 0;
}

//----- (005139A0) --------------------------------------------------------
int sub_5139A0() {
	int v0; // edi
	int v1; // eax
	int v2; // esi
	int v3; // eax
	int v4; // ebp
	int v5; // eax
	int v6; // edi

	if (!*(_DWORD*)&byte_5D4594[2386860]) {
		*(_DWORD*)&byte_5D4594[2386860] = sub_4E3AA0((CHAR*)&byte_587000[247024]);
		*(_DWORD*)&byte_5D4594[2386864] = sub_4E3AA0((CHAR*)&byte_587000[247032]);
		*(_DWORD*)&byte_5D4594[2386868] = sub_4E3AA0((CHAR*)&byte_587000[247048]);
	}
	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptValToObjectPtr_511B60(v0);
	v4 = v3;
	if (v2 && v3) {
		if (nox_common_gameFlags_check_40A5C0(2048) && (*(_BYTE*)(v2 + 8) & 4) == 4 &&
		    *(_DWORD*)&byte_5D4594[2386844] != *(_DWORD*)&byte_5D4594[2598000]) {
			*(_DWORD*)&byte_5D4594[2386844] = *(_DWORD*)&byte_5D4594[2598000];
			*(_DWORD*)&byte_5D4594[2386848] = 0;
			*(_DWORD*)&byte_5D4594[2386852] = 0;
		}
		if (*(_BYTE*)(v2 + 8) & 4) {
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				v5 = *(unsigned __int16*)(v2 + 4);
				if ((unsigned __int16)v5 != *(_DWORD*)&byte_5D4594[2386860] &&
				    v5 != *(_DWORD*)&byte_5D4594[2386864] && v5 != *(_DWORD*)&byte_5D4594[2386868]) {
					sub_513B00(v2, v4);
				}
			}
		}
		v6 = sub_4F36F0(v2, v4, 1, 1);
		if (v6 == 1 && *(_BYTE*)(v2 + 8) & 4 && nox_common_gameFlags_check_40A5C0(2048) &&
		    *(unsigned __int16*)(v4 + 4) != *(_DWORD*)&byte_5D4594[2386860]) {
			++*(_DWORD*)&byte_5D4594[2386848];
			sub_507230(1);
			return 0;
		}
	} else {
		v6 = 0;
	}
	sub_507230(v6);
	return 0;
}

//----- (00513B00) --------------------------------------------------------
void __cdecl sub_513B00(int a1, int a2) {
	_DWORD* v2; // ebp
	int v3;     // edi
	int v4;     // esi
	int v5;     // eax
	int v6;     // eax
	float2 v7;  // [esp+0h] [ebp-8h]

	if (!*(_DWORD*)&byte_5D4594[2386856])
		*(_DWORD*)&byte_5D4594[2386856] = sub_4E3AA0((CHAR*)&byte_587000[247064]);
	if (sub_467B00(*(unsigned __int16*)(a2 + 4), 1) - *(int*)&byte_5D4594[2386848] <= 0) {
		v2 = 0;
		v3 = 999999;
		v4 = sub_4E7980(a1);
		if (v4) {
			do {
				if (!(*(_BYTE*)(v4 + 8) & 0x10)) {
					v5 = *(_DWORD*)(v4 + 16);
					if (!(v5 & 0x100) &&
					    *(unsigned __int16*)(v4 + 4) != *(_DWORD*)&byte_5D4594[2386856] &&
					    !sub_53EBF0(v4)) {
						v6 = sub_50E3D0(1, 0, *(float*)&v4);
						if (v6 < v3) {
							v3 = v6;
							v2 = (_DWORD*)v4;
						}
					}
				}
				v4 = sub_4E7990(v4);
			} while (v4);
			if (v2) {
				sub_4ED970(50.0, (float2*)(a1 + 56), &v7);
				sub_4ED790(a1, v2, &v7);
				if (!*(_DWORD*)&byte_5D4594[2386852]) {
					sub_4DA2C0(a1, "pickup.c:CarryingTooMuch", 0);
					*(_DWORD*)&byte_5D4594[2386852] = 1;
				}
			}
		}
	}
}

//----- (00513C10) --------------------------------------------------------
int sub_513C10() {
	int v0;     // edi
	int v1;     // eax
	int v2;     // esi
	_DWORD* v3; // eax
	int v4;     // eax
	int result; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = (_DWORD*)nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && v3) {
		v4 = sub_4ED930(v2, v3);
		sub_507230(v4);
		result = 0;
	} else {
		sub_507230(0);
		result = 0;
	}
	return result;
}

//----- (00513C60) --------------------------------------------------------
int sub_513C60() { return 0; }

//----- (00513C70) --------------------------------------------------------
int sub_513C70() {
	int v0;      // esi
	int v1;      // ebx
	int v2;      // eax
	char v3;     // si
	int v4;      // eax
	int v5;      // eax
	int result;  // eax
	char v7[64]; // [esp+Ch] [ebp-40h]

	v0 = script_pop();
	v1 = script_pop();
	strcpy(v7, *(const char**)&byte_5D4594[4 * v0 + 3831212]);
	v2 = sub_424880(v7);
	v3 = v2;
	if (v2 != -1 && (v4 = nox_server_scriptValToObjectPtr_511B60(v1)) != 0) {
		v5 = sub_4FF350(v4, v3);
		sub_507230(v5);
		result = 0;
	} else {
		sub_507230(0);
		result = 0;
	}
	return result;
}

//----- (00513D00) --------------------------------------------------------
int sub_513D00() {
	int v0;      // esi
	int v1;      // ebx
	int v2;      // esi
	int v3;      // eax
	char v5[64]; // [esp+Ch] [ebp-40h]

	v0 = script_pop();
	v1 = script_pop();
	strcpy(v5, *(const char**)&byte_5D4594[4 * v0 + 3831212]);
	v2 = sub_424880(v5);
	if (v2 != -1) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v1);
		if (v3)
			sub_4FF5B0(v3, v2);
	}
	return 0;
}

//----- (00513D70) --------------------------------------------------------
int sub_513D70() {
	int v0;               // eax
	int v1;               // eax
	unsigned __int16* v2; // ecx
	int result;           // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && (v2 = *(unsigned __int16**)(v1 + 556)) != 0) {
		sub_507230(*v2);
		result = 0;
	} else {
		sub_507230(0);
		result = 0;
	}
	return result;
}

//----- (00513DB0) --------------------------------------------------------
int sub_513DB0() {
	int v0;     // eax
	int v1;     // eax
	int v2;     // ecx
	int result; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && (v2 = *(_DWORD*)(v1 + 556)) != 0) {
		sub_507230(*(unsigned __int16*)(v2 + 4));
		result = 0;
	} else {
		sub_507230(0);
		result = 0;
	}
	return result;
}

//----- (00513DF0) --------------------------------------------------------
int sub_513DF0() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2 && v0 > 0)
		sub_4EE460(v2, v0);
	return 0;
}

//----- (00513E20) --------------------------------------------------------
int sub_513E20() {
	float v0; // eax
	float v2; // [esp+4h] [ebp-Ch]
	float v3; // [esp+8h] [ebp-8h]
	float v4; // [esp+Ch] [ebp-4h]
	int v5;   // [esp+Ch] [ebp-4h]

	v4 = COERCE_FLOAT(script_pop());
	v2 = COERCE_FLOAT(script_pop());
	v3 = COERCE_FLOAT(script_pop());
	v0 = COERCE_FLOAT(script_pop());
	*(float*)&v5 = sqrt((v3 - v4) * (v3 - v4) + (v0 - v2) * (v0 - v2));
	sub_507230(v5);
	return 0;
}

//----- (00513E80) --------------------------------------------------------
int sub_513E80() {
	int v0;    // edi
	int v1;    // eax
	int v2;    // esi
	int v3;    // eax
	int v4;    // edx
	double v5; // st7
	double v6; // st7

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptValToObjectPtr_511B60(v0);
	v4 = 0;
	if (v2 && v3) {
		v5 = *(float*)(v2 + 56) - *(float*)(v3 + 56);
		if (v5 < 0.0)
			v5 = -v5;
		if (v5 <= 512.0) {
			v6 = *(float*)(v2 + 60) - *(float*)(v3 + 60);
			if (v6 < 0.0)
				v6 = -v6;
			if (v6 <= 512.0)
				v4 = sub_5370E0(v2, v3, 0);
		}
	}
	sub_507230(v4);
	return 0;
}

//----- (00513F10) --------------------------------------------------------
int sub_513F10() {
	script_pop();
	script_pop();
	return 0;
}

//----- (00513F20) --------------------------------------------------------
int sub_513F20() {
	script_pop();
	script_pop();
	return 0;
}

//----- (00513F30) --------------------------------------------------------
int sub_513F30() {
	script_pop();
	script_pop();
	return 0;
}

//----- (00513F40) --------------------------------------------------------
int sub_513F40() {
	script_pop();
	script_pop();
	return 0;
}

//----- (00513F50) --------------------------------------------------------
int sub_513F50() {
	script_pop();
	script_pop();
	return 0;
}

//----- (00513F60) --------------------------------------------------------
int sub_513F60() {
	script_pop();
	script_pop();
	return 0;
}

//----- (00513FA0) --------------------------------------------------------
int sub_513FA0() {
	int v0;     // esi
	char* v1;   // eax
	int result; // eax

	v0 = script_pop();
	v1 = sub_431770();
	switch (v0) {
	case 0:
		sub_507230(*(_DWORD*)(v1 + 50));
		result = 0;
		break;
	case 1:
		sub_507230(*(_DWORD*)(v1 + 54));
		result = 0;
		break;
	case 2:
		sub_507230(*(_DWORD*)(v1 + 58));
		result = 0;
		break;
	case 3:
		sub_507230(*(_DWORD*)(v1 + 62));
		result = 0;
		break;
	case 4:
		sub_507230((unsigned __int8)v1[66]);
		result = 0;
		break;
	case 5:
		sub_507230((unsigned __int8)v1[67]);
		result = 0;
		break;
	default:
		sub_507230(0);
		result = 0;
		break;
	}
	return result;
}

//----- (00514050) --------------------------------------------------------
int sub_514050() {
	int v0;     // edi
	int v1;     // eax
	int v2;     // esi
	int v3;     // eax
	__int16 v4; // ax
	float2 v6;  // [esp+8h] [ebp-8h]

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && v3) {
		v6.field_0 = *(float*)(v3 + 56) - *(float*)(v2 + 56);
		v6.field_4 = *(float*)(v3 + 60) - *(float*)(v2 + 60);
		v4 = sub_509ED0(&v6);
		*(_WORD*)(v2 + 126) = v4;
		*(_WORD*)(v2 + 124) = v4;
	}
	return 0;
}

//----- (005140B0) --------------------------------------------------------
int sub_5140B0() {
	int v0;   // eax
	int v1;   // eax
	int v3;   // [esp+0h] [ebp-10h]
	int v4;   // [esp+4h] [ebp-Ch]
	float v5; // [esp+8h] [ebp-8h]
	float v6; // [esp+Ch] [ebp-4h]

	v5 = COERCE_FLOAT(script_pop());
	v6 = COERCE_FLOAT(script_pop());
	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		*(float*)&v4 = (double)*(int*)&dword_5d4594_3821640 + v5;
		*(float*)&v3 = (double)*(int*)&dword_5d4594_3821636 + v6;
		sub_514110(v1, v3, v4);
	}
	return 0;
}

//----- (00514110) --------------------------------------------------------
int* __cdecl sub_514110(int a1, int a2, int a3) {
	int* result; // eax
	int* v4;     // eax

	result = *(int**)(a1 + 16);
	if (SBYTE1(result) >= 0 && *(_BYTE*)(a1 + 8) & 2) {
		sub_50A3A0(a1);
		v4 = sub_50A260(a1, 32);
		if (v4)
			v4[1] = 8;
		result = sub_50A260(a1, 8);
		if (result) {
			result[1] = a2;
			result[2] = a3;
			result[3] = 0;
		}
	}
	return result;
}

//----- (00514170) --------------------------------------------------------
int sub_514170() {
	int v0;     // eax
	int result; // eax
	int* i;     // esi
	int v3;     // eax
	int v4;     // [esp+0h] [ebp-14h]
	int v5;     // [esp+4h] [ebp-10h]
	float v6;   // [esp+Ch] [ebp-8h]
	float v7;   // [esp+10h] [ebp-4h]

	v6 = COERCE_FLOAT(script_pop());
	v7 = COERCE_FLOAT(script_pop());
	v0 = script_pop();
	result = nox_server_scriptGetGroup_57C0A0(v0);
	if (result) {
		for (i = *(int**)(result + 84); i; i = (int*)i[2]) {
			v3 = sub_4ED020(*i);
			if (v3) {
				*(float*)&v5 = (double)*(int*)&dword_5d4594_3821640 + v6;
				*(float*)&v4 = (double)*(int*)&dword_5d4594_3821636 + v7;
				sub_514110(v3, v4, v5);
			}
		}
		result = 0;
	}
	return result;
}

//----- (005141F0) --------------------------------------------------------
int sub_5141F0() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = sub_51AD60(v0);
	sub_507230(v1 != 0);
	return 0;
}

//----- (00514210) --------------------------------------------------------
int sub_514210() {
	int v0;              // ebp
	const char* v1;      // edi
	const char* v2;      // esi
	unsigned int v3;     // ebx
	char* v4;            // edi
	char* v5;            // edi
	const char* v6;      // esi
	char v7;             // cl
	char v8;             // bl
	char v9;             // si
	int result;          // eax
	int v11;             // eax
	char v12;            // al
	unsigned __int8 v13; // [esp+10h] [ebp-68h]
	float v14;           // [esp+14h] [ebp-64h]
	float v15;           // [esp+18h] [ebp-60h]
	int v16;             // [esp+1Ch] [ebp-5Ch]
	float2 v17;          // [esp+20h] [ebp-58h]
	int v19[4];          // [esp+28h] [ebp-50h]
	char v20[64];        // [esp+38h] [ebp-40h]

	v16 = script_pop();
	v0 = script_pop();
	v15 = COERCE_FLOAT(script_pop());
	v14 = COERCE_FLOAT(script_pop());
	v1 = *(const char**)&byte_5D4594[4 * script_pop() + 3831212];
	strcpy(v20, "MSG_FX_");
	v17.field_0 = (double)*(int*)&dword_5d4594_3821636 + v14;
	v17.field_4 = (double)*(int*)&dword_5d4594_3821640 + v15;
	v2 = v1;
	v3 = strlen(v1) + 1;
	v4 = &v20[strlen(v20)];
	qmemcpy(v4, v2, 4 * (v3 >> 2));
	v6 = &v2[4 * (v3 >> 2)];
	v5 = &v4[4 * (v3 >> 2)];
	v7 = v3;
	v8 = 87;
	v13 = 87;
	qmemcpy(v5, v6, v7 & 3);
	do {
		if (!_strcmpi(*(const char**)&byte_587000[4 * v13 + 238648], v20))
			break;
		v13 = ++v8;
	} while ((unsigned __int8)v8 <= 0x73u);
	v9 = v8 + 39;
	switch ((unsigned __int8)(v8 + 39)) {
	case 0x81u:
	case 0x82u:
	case 0x83u:
	case 0x84u:
	case 0x85u:
	case 0x86u:
	case 0x87u:
	case 0x88u:
	case 0x89u:
	case 0x8Au:
	case 0x8Bu:
	case 0x96u:
	case 0x9Au:
	case 0xA0u:
	case 0xA3u:
		sub_522FF0(v8 + 39, &v17);
		result = 0;
		break;
	case 0x8Cu:
	case 0x8Fu:
	case 0x90u:
	case 0x91u:
	case 0x94u:
	case 0x95u:
		v19[0] = dword_5d4594_3821636 + nox_float2int(v14);
		v19[1] = dword_5d4594_3821640 + nox_float2int(v15);
		v19[2] = dword_5d4594_3821636 + nox_float2int(*(float*)&v0);
		v19[3] = dword_5d4594_3821640 + nox_float2int(*(float*)&v16);
		sub_5232F0(v9, (int)v19);
		result = 0;
		break;
	case 0x93u:
		v12 = nox_float2int8(*(float*)&v0);
		sub_5231B0(&v17, v12);
		result = 0;
		break;
	case 0x97u:
		v11 = nox_float2int(*(float*)&v0);
		sub_4D9110(&v17, v11);
		result = 0;
		break;
	case 0x98u:
		sub_523790((int4*)v19, 30);
		result = 0;
		break;
	case 0xA2u:
		v19[0] = dword_5d4594_3821636 + nox_float2int(v14);
		v19[1] = dword_5d4594_3821640 + nox_float2int(v15);
		v19[2] = dword_5d4594_3821636 + nox_float2int(*(float*)&v0);
		v19[3] = dword_5d4594_3821640 + nox_float2int(*(float*)&v16);
		sub_523270(v9, (__int16*)v19, 100);
		result = 0;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (00514490) --------------------------------------------------------
int sub_514490() {
	int v0; // esi
	int v1; // eax
	int v2; // edi
	int v3; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptValToObjectPtr_511B60(v0);
	sub_4EC290(v2, v3);
	return 0;
}

//----- (005144C0) --------------------------------------------------------
int sub_5144C0() {
	int v0; // esi
	int v1; // eax
	int v2; // edi
	int v3; // eax
	int* i; // esi
	int v5; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptGetGroup_57C0A0(v0);
	if (v3) {
		for (i = *(int**)(v3 + 84); i; i = (int*)i[2]) {
			v5 = sub_4ED020(*i);
			if (v5)
				sub_4EC290(v2, v5);
		}
	}
	return 0;
}

//----- (00514510) --------------------------------------------------------
int sub_514510() {
	int v0;  // edi
	int v1;  // eax
	int v2;  // esi
	int v3;  // eax
	int* v4; // esi
	int i;   // edi
	int v6;  // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptGetGroup_57C0A0(v1);
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v0);
		v4 = *(int**)(v2 + 84);
		for (i = v3; v4; v4 = (int*)v4[2]) {
			v6 = sub_4ED020(*v4);
			if (v6)
				sub_4EC290(v6, i);
		}
	}
	return 0;
}

//----- (00514570) --------------------------------------------------------
int sub_514570() {
	int v0; // edi
	int v1; // eax
	int v2; // esi
	int v3; // eax
	int v4; // ebp
	int* i; // edi
	int v6; // ebx
	int* j; // esi
	int v8; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptGetGroup_57C0A0(v1);
	v3 = nox_server_scriptGetGroup_57C0A0(v0);
	v4 = v3;
	if (v2) {
		if (v3) {
			for (i = *(int**)(v2 + 84); i; i = (int*)i[2]) {
				v6 = sub_4ED020(*i);
				if (v6) {
					for (j = *(int**)(v4 + 84); j; j = (int*)j[2]) {
						v8 = sub_4ED020(*j);
						if (v8)
							sub_4EC290(v6, v8);
					}
				}
			}
		}
	}
	return 0;
}

//----- (005145F0) --------------------------------------------------------
int sub_5145F0() {
	int v0; // esi
	int v1; // edi
	int v2; // esi
	int v3; // eax
	int v4; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	v3 = nox_server_scriptValToObjectPtr_511B60(v1);
	v4 = sub_4EC4F0(v3, v2);
	sub_507230(v4);
	return 0;
}

//----- (00514630) --------------------------------------------------------
int sub_514630() {
	int v0;     // esi
	int v1;     // edi
	int result; // eax
	int v3;     // esi
	int v4;     // eax
	int* v5;    // esi
	int v6;     // edi
	int v7;     // ebx
	int v8;     // eax

	v0 = script_pop();
	v1 = script_pop();
	result = nox_server_scriptGetGroup_57C0A0(v0);
	v3 = result;
	if (result) {
		v4 = nox_server_scriptValToObjectPtr_511B60(v1);
		v5 = *(int**)(v3 + 84);
		v6 = v4;
		v7 = 1;
		if (v5) {
			while (1) {
				v8 = sub_4ED020(*v5);
				if (v8) {
					if (!sub_4EC4F0(v6, v8))
						break;
				}
				v5 = (int*)v5[2];
				if (!v5) {
					sub_507230(1);
					return 0;
				}
			}
			v7 = 0;
		}
		sub_507230(v7);
		result = 0;
	}
	return result;
}

//----- (005146B0) --------------------------------------------------------
int sub_5146B0() {
	int v0;     // edi
	int v1;     // eax
	int result; // eax
	int v3;     // esi
	int v4;     // eax
	int* v5;    // esi
	int v6;     // edi
	int v7;     // ebx
	int v8;     // eax

	v0 = script_pop();
	v1 = script_pop();
	result = nox_server_scriptGetGroup_57C0A0(v1);
	v3 = result;
	if (result) {
		v4 = nox_server_scriptValToObjectPtr_511B60(v0);
		v5 = *(int**)(v3 + 84);
		v6 = v4;
		v7 = 1;
		if (v5) {
			while (1) {
				v8 = sub_4ED020(*v5);
				if (v8) {
					if (!sub_4EC4F0(v8, v6))
						break;
				}
				v5 = (int*)v5[2];
				if (!v5) {
					sub_507230(1);
					return 0;
				}
			}
			v7 = 0;
		}
		sub_507230(v7);
		result = 0;
	}
	return result;
}

//----- (00514730) --------------------------------------------------------
int sub_514730() {
	int v0;  // esi
	int v1;  // edi
	int v2;  // esi
	int v3;  // eax
	int* v4; // ebx
	int i;   // ebp
	int v6;  // edi
	int* v7; // esi
	int v8;  // eax
	int v10; // [esp+8h] [ebp-4h]

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptGetGroup_57C0A0(v0);
	v3 = nox_server_scriptGetGroup_57C0A0(v1);
	v10 = v3;
	if (!v2 || !v3)
		return 0;
	v4 = *(int**)(v2 + 84);
	for (i = 1; v4; v4 = (int*)v4[2]) {
		if (!i)
			break;
		v6 = sub_4ED020(*v4);
		if (v6) {
			v7 = *(int**)(v10 + 84);
			if (v7) {
				while (1) {
					v8 = sub_4ED020(*v7);
					if (v8) {
						if (!sub_4EC4F0(v8, v6))
							break;
					}
					v7 = (int*)v7[2];
					if (!v7)
						goto LABEL_12;
				}
				i = 0;
			}
		}
	LABEL_12:;
	}
	sub_507230(i);
	return 0;
}

//----- (005147E0) --------------------------------------------------------
int sub_5147E0() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	sub_4EC300(v1);
	return 0;
}

//----- (00514800) --------------------------------------------------------
int sub_514800() {
	int* v0;     // eax
	char v2[76]; // [esp+4h] [ebp-4Ch]

	strcpy(v2, *(const char**)&byte_5D4594[4 * script_pop() + 3831212]);
	strcat(v2, (const char*)&byte_5D4594[3821644]);
	v0 = (int*)sub_579E30(v2);
	if (v0)
		sub_507230(*v0);
	else
		sub_507230(0);
	return 0;
}

//----- (005148A0) --------------------------------------------------------
int sub_5148A0() {
	int v0;      // eax
	char v2[76]; // [esp+4h] [ebp-4Ch]

	strcpy(v2, *(const char**)&byte_5D4594[4 * script_pop() + 3831212]);
	strcat(v2, (const char*)&byte_5D4594[3821644]);
	v0 = nox_server_scriptGetMapGroupByName_57C280(v2, 1);
	if (v0)
		sub_507230(*(_DWORD*)(v0 + 4));
	else
		sub_507230(0);
	return 0;
}

//----- (00514940) --------------------------------------------------------
int sub_514940() {
	int v0;      // eax
	char v2[76]; // [esp+4h] [ebp-4Ch]

	strcpy(v2, *(const char**)&byte_5D4594[4 * script_pop() + 3831212]);
	strcat(v2, (const char*)&byte_5D4594[3821644]);
	v0 = nox_server_scriptGetMapGroupByName_57C280(v2, 0);
	if (v0)
		sub_507230(*(_DWORD*)(v0 + 4));
	else
		sub_507230(0);
	return 0;
}

//----- (005149E0) --------------------------------------------------------
int sub_5149E0() {
	int v0; // eax
	char v2[76];

	strcpy(v2, *(const char**)&byte_5D4594[4 * script_pop() + 3831212]);
	strcat(v2, (const char*)&byte_5D4594[3821644]);
	v0 = nox_server_scriptGetMapGroupByName_57C280(v2, 2);
	if (v0)
		sub_507230(*(_DWORD*)(v0 + 4));
	else
		sub_507230(0);
	return 0;
}

//----- (00514BA0) --------------------------------------------------------
int sub_514BA0() {
	script_pop();
	script_pop();
	return 0;
}

//----- (00514BB0) --------------------------------------------------------
int sub_514BB0() {
	int v0;     // eax
	_DWORD* v1; // eax

	v0 = script_pop();
	v1 = (_DWORD*)nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_528D00(v1);
	return 0;
}

//----- (00514BD0) --------------------------------------------------------
int sub_514BD0() {
	sub_528D60();
	return 0;
}

//----- (00514BE0) --------------------------------------------------------
int sub_514BE0() {
	int v0; // esi
	int v1; // eax

	v0 = script_pop();
	v1 = script_pop();
	sub_500540(*(char**)&byte_5D4594[4 * v0 + 3831212], v1);
	return 0;
}

//----- (00514C10) --------------------------------------------------------
int sub_514C10() {
	int v0; // esi
	int v1; // eax

	v0 = script_pop();
	v1 = script_pop();
	sub_5006B0(*(char**)&byte_5D4594[4 * v0 + 3831212], v1);
	return 0;
}

//----- (00514C40) --------------------------------------------------------
int sub_514C40() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = sub_500750(*(char**)&byte_5D4594[4 * v0 + 3831212]);
	sub_507230(v1);
	return 0;
}

//----- (00514C60) --------------------------------------------------------
int sub_514C60() {
	int v0; // eax
	int v2; // [esp+0h] [ebp-4h]

	v0 = script_pop();
	*(float*)&v2 = sub_500770((char*)*(_DWORD*)&byte_5D4594[4 * v0 + 3831212]);
	sub_507230(v2);
	return 0;
}

//----- (00514C90) --------------------------------------------------------
int sub_514C90() {
	int v0; // eax

	v0 = script_pop();
	sub_5007E0(*(char**)&byte_5D4594[4 * v0 + 3831212]);
	return 0;
}

//----- (00514CB0) --------------------------------------------------------
int sub_514CB0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && dword_5d4594_3821968 &&
	    *(_DWORD*)(v2 + 44) == *(_DWORD*)(dword_5d4594_3821968 + 44)) {
		v1 = 1;
	}
	sub_507230(v1);
	return 0;
}

//----- (00514CF0) --------------------------------------------------------
int sub_514CF0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && dword_5d4594_3821964 &&
	    *(_DWORD*)(v2 + 44) == *(_DWORD*)(dword_5d4594_3821964 + 44)) {
		v1 = 1;
	}
	sub_507230(v1);
	return 0;
}

//----- (00514D30) --------------------------------------------------------
int sub_514D30() {
	if (dword_5d4594_3821968)
		sub_507230(*(_DWORD*)(dword_5d4594_3821968 + 44));
	else
		sub_507230(*(int*)&dword_5d4594_3821968);
	return 0;
}

//----- (00514D60) --------------------------------------------------------
int sub_514D60() {
	if (dword_5d4594_3821964)
		sub_507230(*(_DWORD*)(dword_5d4594_3821964 + 44));
	else
		sub_507230(*(int*)&dword_5d4594_3821964);
	return 0;
}

//----- (00514D90) --------------------------------------------------------
int sub_514D90() {
	int v0;  // ebx
	int v1;  // ebp
	int v2;  // esi
	int v3;  // edi
	int v4;  // eax
	char v6; // [esp+10h] [ebp-4h]

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	v3 = script_pop();
	v6 = sub_548F70(*(const char**)&byte_5D4594[4 * v2 + 3831212]);
	v4 = nox_server_scriptValToObjectPtr_511B60(v3);
	if (v4)
		sub_548C80(v4, v6, v1, v0);
	return 0;
}

//----- (00514DF0) --------------------------------------------------------
int sub_514DF0() {
	int v0; // eax
	int v1; // eax
	int v2; // ecx

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = *(_DWORD*)(v1 + 748);
		if (*(_BYTE*)(v1 + 8) & 2) {
			*(_DWORD*)(v2 + 2096) = -1;
			*(_DWORD*)(v2 + 2100) = -1;
			sub_4E4780(v1, 16);
		}
	}
	return 0;
}

//----- (00514E30) --------------------------------------------------------
int sub_514E30() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2 && *(_BYTE*)(v2 + 8) & 2)
		strcpy((char*)(*(_DWORD*)(v2 + 748) + 2106), *(const char**)&byte_5D4594[4 * v0 + 3831212]);
	return 0;
}

//----- (00514E90) --------------------------------------------------------
int sub_514E90() {
	int v0;         // esi
	int v1;         // eax
	int v2;         // eax
	const char* v4; // [esp-4h] [ebp-8h]

	v0 = script_pop();
	v1 = script_pop();
	v4 = *(const char**)&byte_5D4594[4 * v0 + 3831212];
	v2 = sub_40AF50(*(void**)&byte_5D4594[4 * v1 + 3831212]);
	sub_548DE0(*(int*)&dword_5d4594_3821964, *(int*)&dword_5d4594_3821968, v2, v4);
	return 0;
}

//----- (00514ED0) --------------------------------------------------------
int sub_514ED0() {
	int v0; // esi
	int v1; // edi
	int v2; // esi
	int v3; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	v3 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2 && v3)
		sub_548CD0(v2, v3);
	return 0;
}

//----- (00514F10) --------------------------------------------------------
int sub_514F10() {
	int v0;     // ebp
	int v1;     // esi
	int v2;     // eax
	int v3;     // ebx
	int v4;     // eax
	int v5;     // edi
	int v6;     // eax
	int v7;     // esi
	float2 v9;  // [esp+10h] [ebp-14h]
	int v10[3]; // [esp+18h] [ebp-Ch]

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	v3 = sub_4243F0(*(const char**)&byte_5D4594[4 * v2 + 3831212]);
	if (v3) {
		v4 = nox_server_scriptValToObjectPtr_511B60(v1);
		v5 = v4;
		if (v4) {
			if (!(*(_DWORD*)(v4 + 16) & 0x8020)) {
				v6 = nox_server_scriptValToObjectPtr_511B60(v0);
				v7 = v6;
				if (v6) {
					v9.field_0 = *(float*)(v6 + 56) - *(float*)(v5 + 56);
					v9.field_4 = *(float*)(v6 + 60) - *(float*)(v5 + 60);
					*(_WORD*)(v5 + 124) = sub_509ED0(&v9);
					v10[0] = v7;
					v10[1] = *(_DWORD*)(v7 + 56);
					v10[2] = *(_DWORD*)(v7 + 60);
					sub_4FDD20(v3, (_DWORD*)v5, v10);
				}
			}
		}
	}
	return 0;
}

//----- (00514FC0) --------------------------------------------------------
int sub_514FC0() {
	int v0;      // esi
	int v1;      // eax
	int v2;      // edi
	int v3;      // eax
	_DWORD* v4;  // esi
	float v6;    // [esp+8h] [ebp-1Ch]
	float v7;    // [esp+Ch] [ebp-18h]
	float2 v8;   // [esp+10h] [ebp-14h]
	float v9[3]; // [esp+18h] [ebp-Ch]

	v7 = COERCE_FLOAT(script_pop());
	v6 = COERCE_FLOAT(script_pop());
	v0 = script_pop();
	v1 = script_pop();
	v2 = sub_4243F0(*(const char**)&byte_5D4594[4 * v1 + 3831212]);
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v0);
		v4 = (_DWORD*)v3;
		if (v3) {
			v8.field_0 = v6 - *(float*)(v3 + 56);
			v8.field_4 = v7 - *(float*)(v3 + 60);
			*(_WORD*)(v3 + 124) = sub_509ED0(&v8);
			v9[0] = 0.0;
			v9[1] = v6;
			v9[2] = v7;
			sub_4FDD20(v2, v4, v9);
		}
	}
	return 0;
}

//----- (00515060) --------------------------------------------------------
int sub_515060() {
	int v0;    // esi
	int v1;    // eax
	int v2;    // edi
	int v3;    // esi
	float2 v5; // [esp+8h] [ebp-1Ch]
	float2 v6; // [esp+10h] [ebp-14h]
	int v7[3]; // [esp+18h] [ebp-Ch]

	v0 = script_pop();
	LODWORD(v5.field_4) = script_pop();
	LODWORD(v5.field_0) = script_pop();
	v1 = script_pop();
	v2 = sub_4243F0(*(const char**)&byte_5D4594[4 * v1 + 3831212]);
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v0);
		if (v3) {
			v6 = v5;
			sub_4E7010(*(int*)&dword_5d4594_1569664, &v6);
			v6.field_0 = *(float*)(v3 + 56) - v5.field_0;
			v6.field_4 = *(float*)(v3 + 60) - v5.field_4;
			*(_WORD*)(dword_5d4594_1569664 + 124) = sub_509ED0(&v6);
			v7[0] = v3;
			v7[1] = *(_DWORD*)(v3 + 56);
			v7[2] = *(_DWORD*)(v3 + 60);
			sub_4FDD20(v2, *(_DWORD**)&dword_5d4594_1569664, &v7);
		}
	}
	return 0;
}

//----- (00515130) --------------------------------------------------------
int sub_515130() {
	int v0;      // eax
	int v1;      // esi
	float2 v3;   // [esp+4h] [ebp-24h]
	float v4;    // [esp+Ch] [ebp-1Ch]
	float v5;    // [esp+10h] [ebp-18h]
	float2 v6;   // [esp+14h] [ebp-14h]
	float v7[3]; // [esp+1Ch] [ebp-Ch]

	v5 = COERCE_FLOAT(script_pop());
	v4 = COERCE_FLOAT(script_pop());
	LODWORD(v3.field_4) = script_pop();
	LODWORD(v3.field_0) = script_pop();
	v0 = script_pop();
	v1 = sub_4243F0(*(const char**)&byte_5D4594[4 * v0 + 3831212]);
	if (v1) {
		v6 = v3;
		sub_4E7010(*(int*)&dword_5d4594_1569664, &v6);
		v6.field_0 = v4 - v3.field_0;
		v6.field_4 = v5 - v3.field_4;
		*(_WORD*)(dword_5d4594_1569664 + 124) = sub_509ED0(&v6);
		v7[1] = v4;
		v7[0] = 0.0;
		v7[2] = v5;
		sub_4FDD20(v1, *(_DWORD**)&dword_5d4594_1569664, &v7);
	}
	return 0;
}

//----- (00515200) --------------------------------------------------------
int sub_515200() {
	dword_5d4594_2650672 = 0;
	sub_44DB30(25, 0, 0);
	return 0;
}

//----- (00515220) --------------------------------------------------------
int sub_515220() {
	nox_client_screenFadeTimeout_44DAB0(25, 0, sub_44E000);
	return 0;
}

//----- (00515240) --------------------------------------------------------
int sub_515240() {
	BOOL v0; // esi
	int v1;  // esi
	int v2;  // edi
	int v3;  // esi
	int v4;  // edi
	int v5;  // eax
	int v6;  // eax
	int i;   // eax
	int v9;  // ecx

	if (!*(_DWORD*)&byte_5D4594[2386872])
		*(_DWORD*)&byte_5D4594[2386872] = sub_4E3AA0((CHAR*)&byte_587000[247228]);
	if (script_pop() != 1) {
		if (sub_44DCA0(16, 30))
			sub_477530(0);
		for (i = sub_4DA790(); i; i = sub_4DA7A0(i)) {
			if (*(unsigned __int16*)(i + 4) == *(_DWORD*)&byte_5D4594[2386872]) {
				v9 = *(_DWORD*)(i + 16);
				if (v9 & 0x40)
					*(_DWORD*)(i + 16) = v9 & 0xFFFFFFBF;
			}
		}
		return 0;
	}
	v0 = sub_44DD00();
	if (sub_44DC40(16, 10))
		sub_477530(1);
	if (v0)
		return 0;
	if (!*(_DWORD*)&byte_5D4594[2386876]) {
		*(_DWORD*)&byte_5D4594[2386876] = sub_4E3AA0((CHAR*)&byte_587000[247244]);
		*(_DWORD*)&byte_5D4594[2386880] = sub_4E3AA0((CHAR*)&byte_587000[247256]);
		*(_DWORD*)&byte_5D4594[2386884] = sub_4E3AA0((CHAR*)&byte_587000[247272]);
		*(_DWORD*)&byte_5D4594[2386888] = sub_4E3AA0((CHAR*)&byte_587000[247280]);
		*(_DWORD*)&byte_5D4594[2386892] = sub_4E3AA0((CHAR*)&byte_587000[247292]);
		*(_DWORD*)&byte_5D4594[2386896] = sub_4E3AA0((CHAR*)&byte_587000[247304]);
		*(_DWORD*)&byte_5D4594[2386900] = sub_4E3AA0((CHAR*)&byte_587000[247316]);
	}
	v1 = sub_4DA840();
	if (v1) {
		do {
			v2 = sub_4DA850(v1);
			if (*(unsigned __int16*)(v1 + 4) != *(_DWORD*)&byte_5D4594[2386900])
				sub_4E5CC0(v1);
			v1 = v2;
		} while (v2);
	}
	v3 = sub_4DA790();
	if (!v3)
		return 0;
	do {
		v4 = sub_4DA7A0(v3);
		if (*(_DWORD*)(v3 + 508) &&
		    ((v5 = *(unsigned __int16*)(v3 + 4), (unsigned __int16)v5 == *(_DWORD*)&byte_5D4594[2386876]) ||
		     v5 == *(_DWORD*)&byte_5D4594[2386880] || v5 == *(_DWORD*)&byte_5D4594[2386884] ||
		     v5 == *(_DWORD*)&byte_5D4594[2386888] || v5 == *(_DWORD*)&byte_5D4594[2386892] ||
		     v5 == *(_DWORD*)&byte_5D4594[2386896])) {
			sub_4E5CC0(v3);
		} else {
			if (*(unsigned __int16*)(v3 + 4) == *(_DWORD*)&byte_5D4594[2386872]) {
				v6 = *(_DWORD*)(v3 + 16);
				if (!(v6 & 0x40)) {
					LOBYTE(v6) = v6 | 0x40;
					*(_DWORD*)(v3 + 16) = v6;
				}
			}
			sub_4FEB10(132, v3);
			sub_4FEB10(56, v3);
			sub_4FEB10(24, v3);
			sub_4FEB10(43, v3);
			sub_4FEB10(22, v3);
			sub_4FEB10(31, v3);
			sub_4FEB10(35, v3);
			sub_4FEB10(8, v3);
			sub_4FEB10(9, v3);
			sub_4FEB10(4, v3);
			sub_4FEB10(115, v3);
			sub_4FEB10(21, v3);
			sub_4FEB10(59, v3);
			sub_4FEB10(75, v3);
		}
		v3 = v4;
	} while (v4);
	return 0;
}

//----- (005154A0) --------------------------------------------------------
int sub_5154A0() {
	int v0; // esi
	int v1; // eax
	int v2; // eax
	int v3; // ecx

	v0 = -1;
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = *(_DWORD*)(v2 + 8);
		if (v3 & 0x4000)
			v0 = *(unsigned __int8*)(*(_DWORD*)(v2 + 748) + 12);
	}
	sub_507230(v0);
	return 0;
}

//----- (005154E0) --------------------------------------------------------
int sub_5154E0() {
	__int16 v0; // bx
	int v1;     // edi
	int v2;     // eax
	int v3;     // esi

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v2);
		if (v3) {
			sub_427500(v3, *(char**)&byte_5D4594[4 * v1 + 3831212], v0);
			if (v0 & 0xB) {
				sub_501960(903, v3, 0, 0);
				return 0;
			}
		}
	} else {
		sub_427550(*(char**)&byte_5D4594[4 * v1 + 3831212], v0);
	}
	return 0;
}

//----- (00515550) --------------------------------------------------------
int sub_515550() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	if (v1) {
		v2 = nox_server_scriptValToObjectPtr_511B60(v1);
		if (v2) {
			sub_427630(v2, *(const char**)&byte_5D4594[4 * v0 + 3831212]);
			return 0;
		}
	} else {
		sub_427680(*(const char**)&byte_5D4594[4 * v0 + 3831212]);
	}
	return 0;
}

//----- (005155A0) --------------------------------------------------------
int sub_5155A0() {
	__int16 v0; // si
	int v1;     // edi
	int v2;     // eax
	int v3;     // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v2);
		if (v3) {
			sub_427720(v3, *(const char**)&byte_5D4594[4 * v1 + 3831212], v0);
			return 0;
		}
	} else {
		sub_427770(*(const char**)&byte_5D4594[4 * v1 + 3831212], v0);
	}
	return 0;
}

//----- (00515600) --------------------------------------------------------
int sub_515600() {
	int v0;    // eax
	int v1;    // eax
	int v3;    // [esp+0h] [ebp-28h]
	int v4;    // [esp+4h] [ebp-24h]
	int v5;    // [esp+8h] [ebp-20h]
	int v6;    // [esp+Ch] [ebp-1Ch]
	int v7;    // [esp+10h] [ebp-18h]
	int v8[5]; // [esp+14h] [ebp-14h]

	v7 = script_pop();
	v6 = script_pop();
	v5 = script_pop();
	v4 = script_pop();
	v3 = script_pop();
	v0 = script_pop();
	v8[0] = v3;
	v8[1] = v4;
	v8[2] = v5;
	v8[3] = v6;
	v8[4] = v7;
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_515680(v1, v8);
	return 0;
}

//----- (00515680) --------------------------------------------------------
void __cdecl sub_515680(int a1, int a2) {
	int v2;    // ebx
	int v3;    // eax
	int* v4;   // edi
	float2 v5; // [esp+8h] [ebp-8h]

	v2 = *(_DWORD*)(a1 + 748);
	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 2) {
			v3 = *(_DWORD*)(a1 + 16);
			if ((v3 & 0x8000) == 0) {
				v5.field_0 = *(float*)(a2 + 8) - *(float*)a2;
				v5.field_4 = *(float*)(a2 + 12) - *(float*)(a2 + 4);
				sub_50A3A0(a1);
				v4 = sub_50A260(a1, 4);
				if (v4) {
					v4[1] = *(_DWORD*)a2;
					v4[2] = *(_DWORD*)(a2 + 4);
					v4[3] = sub_509ED0(&v5);
				}
				*(_DWORD*)(v2 + 1312) = *(_DWORD*)(a2 + 16);
			}
		}
	}
}

//----- (00515700) --------------------------------------------------------
int sub_515700() {
	int v0;              // eax
	unsigned __int8* v1; // eax
	int v3;              // [esp+0h] [ebp-28h]
	int v4;              // [esp+4h] [ebp-24h]
	int v5;              // [esp+8h] [ebp-20h]
	int v6;              // [esp+Ch] [ebp-1Ch]
	int v7;              // [esp+10h] [ebp-18h]
	int v8[5];           // [esp+14h] [ebp-14h]

	v7 = script_pop();
	v6 = script_pop();
	v5 = script_pop();
	v4 = script_pop();
	v3 = script_pop();
	v0 = script_pop();
	v8[1] = v4;
	v8[3] = v6;
	v8[0] = v3;
	v8[2] = v5;
	v8[4] = v7;
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, sub_515680, (int)v8);
	return 0;
}

//----- (00515780) --------------------------------------------------------
int sub_515780() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_5157A0(v1);
	return 0;
}

//----- (005157A0) --------------------------------------------------------
void __cdecl sub_5157A0(int a1) {
	int result; // eax

	if (a1 && *(_BYTE*)(a1 + 8) & 2) {
		result = *(int*)(a1 + 16);
		if (SBYTE1(result) >= 0) {
			sub_50A3A0(a1);
			sub_50A260(a1, 5);
		}
	}
}

//----- (005157D0) --------------------------------------------------------
int sub_5157D0() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_5157A0, 0);
	return 0;
}

//----- (00515800) --------------------------------------------------------
int sub_515800() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_515820(v1);
	return 0;
}

//----- (00515820) --------------------------------------------------------
void __cdecl sub_515820(int a1) {
	int result; // eax

	if (a1 && *(_BYTE*)(a1 + 8) & 2) {
		result = *(int*)(a1 + 16);
		if (SBYTE1(result) >= 0) {
			sub_50A3A0(a1);
			sub_50A260(a1, 0);
		}
	}
}

//----- (00515850) --------------------------------------------------------
int sub_515850() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_515820, 0);
	return 0;
}

//----- (00515880) --------------------------------------------------------
int sub_515880() {
	int v0; // edi
	int v1; // eax
	int v2; // esi
	int v3; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v0);
		if (v3)
			sub_5158C0(v2, v3);
	}
	return 0;
}

//----- (005158C0) --------------------------------------------------------
void __cdecl sub_5158C0(int a1, int a2) {
	int v2;  // eax
	int* v3; // eax

	if (a1) {
		if (a2) {
			if (*(_BYTE*)(a1 + 8) & 2) {
				if (a1 != a2) {
					v2 = *(_DWORD*)(a1 + 16);
					if ((v2 & 0x8000) == 0) {
						sub_50A3A0(a1);
						v3 = sub_50A260(a1, 3);
						if (v3) {
							v3[1] = *(_DWORD*)(a2 + 56);
							v3[2] = *(_DWORD*)(a2 + 60);
							v3[3] = a2;
						}
					}
				}
			}
		}
	}
}

//----- (00515910) --------------------------------------------------------
int sub_515910() {
	int v0;              // esi
	int v1;              // edi
	int v2;              // eax
	unsigned __int8* v3; // eax
	int v5;              // [esp-4h] [ebp-Ch]

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2) {
		v5 = v2;
		v3 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v1);
		nox_server_scriptExecuteFnForEachGroupObj_502670(v3, 0, sub_5158C0, v5);
	}
	return 0;
}

//----- (00515950) --------------------------------------------------------
int sub_515950() {
	int v0; // eax
	int v1; // eax
	int v3; // [esp+0h] [ebp-4h]

	v3 = script_pop();
	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_515980(v1, &v3);
	return 0;
}

//----- (00515980) --------------------------------------------------------
int __cdecl sub_515980(int a1, _DWORD* a2) {
	int result; // eax

	result = *(_DWORD*)(a1 + 748);
	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 2) {
			*(_DWORD*)(result + 1308) = *a2;
			*(_DWORD*)(result + 1304) = *a2;
		}
	}
	return result;
}

//----- (005159B0) --------------------------------------------------------
int sub_5159B0() {
	int v0;              // eax
	unsigned __int8* v1; // eax
	int v3;              // [esp+0h] [ebp-4h]

	v3 = script_pop();
	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_515980, (int)&v3);
	return 0;
}

//----- (005159E0) --------------------------------------------------------
int sub_5159E0() {
	int v0;   // eax
	int v1;   // eax
	float v3; // [esp+0h] [ebp-10h]
	float v4; // [esp+4h] [ebp-Ch]
	float2 v5;

	v4 = COERCE_FLOAT(script_pop());
	v3 = COERCE_FLOAT(script_pop());
	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v5.field_0 = v3;
		v5.field_4 = v4;
		sub_515A30(v1, (float2*)&v5);
	}
	return 0;
}

//----- (00515A30) --------------------------------------------------------
void __cdecl sub_515A30(int a1, float2* a2) {
	int v2;    // eax
	int* v3;   // eax
	float* v4; // edi
	float* v5; // eax

	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 2) {
			v2 = *(_DWORD*)(a1 + 16);
			if ((v2 & 0x8000) == 0) {
				if (sub_534220(a1)) {
					sub_50A3A0(a1);
					v3 = sub_50A260(a1, 32);
					if (v3)
						v3[1] = 16;
					sub_50A260(a1, 16);
					v4 = (float*)sub_50A260(a1, 51);
					if (v4) {
						v4[1] = sub_534470(a1) + *(float*)(a1 + 176);
						v4[3] = a2->field_0;
						v4[4] = a2->field_4;
					}
					v5 = (float*)sub_50A260(a1, 7);
					if (v5) {
						v5[1] = a2->field_0;
						v5[2] = a2->field_4;
						v5[3] = 0;
					}
				}
			}
		}
	}
}

//----- (00515AE0) --------------------------------------------------------
int sub_515AE0() {
	int v0;              // eax
	unsigned __int8* v1; // eax
	float2 v3;           // [esp+0h] [ebp-10h]
	float2 v4;           // [esp+8h] [ebp-8h]

	LODWORD(v3.field_4) = script_pop();
	LODWORD(v3.field_0) = script_pop();
	v0 = script_pop();
	v4 = v3;
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_515A30, (int)&v4);
	return 0;
}

//----- (00515B30) --------------------------------------------------------
int sub_515B30() {
	int v0;    // eax
	int v1;    // eax
	int v3[2]; // [esp+0h] [ebp-10h]
	int v4[2]; // [esp+8h] [ebp-8h]

	v3[1] = script_pop();
	v3[0] = script_pop();
	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		*(_QWORD*)v4 = *(_QWORD*)v3;
		sub_515B80(v1, v4);
	}
	return 0;
}

//----- (00515B80) --------------------------------------------------------
void __cdecl sub_515B80(int a1, _DWORD* a2) {
	int v2;  // eax
	int* v3; // eax
	int* v4; // eax

	if (a1) {
		if (a2) {
			if (*(_BYTE*)(a1 + 8) & 2) {
				v2 = *(_DWORD*)(a1 + 16);
				if ((v2 & 0x8000) == 0) {
					if (sub_534280(a1)) {
						sub_50A3A0(a1);
						v3 = sub_50A260(a1, 32);
						if (v3)
							v3[1] = 17;
						v4 = sub_50A260(a1, 17);
						if (v4) {
							v4[1] = *a2;
							v4[2] = a2[1];
							v4[3] = 0;
						}
					}
				}
			}
		}
	}
}

//----- (00515BF0) --------------------------------------------------------
int sub_515BF0() {
	int v0;              // eax
	unsigned __int8* v1; // eax
	int v3[2];           // [esp+0h] [ebp-10h]
	int v4[2];           // [esp+8h] [ebp-8h]

	v3[1] = script_pop();
	v3[0] = script_pop();
	v0 = script_pop();
	*(_QWORD*)v4 = *(_QWORD*)v3;
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_515B80, (int)v4);
	return 0;
}

//----- (00515C40) --------------------------------------------------------
int __fastcall sub_515C40(int a1) {
	char v1; // bl
	int v2;  // eax
	int v3;  // eax
	char v5; // [esp+1h] [ebp-1h]

	v5 = HIBYTE(a1);
	v1 = script_pop();
	v2 = script_pop();
	v3 = nox_server_scriptValToObjectPtr_511B60(v2);
	if (v3) {
		v5 = v1;
		sub_515C80(v3, &v5);
	}
	return 0;
}

//----- (00515C80) --------------------------------------------------------
int __cdecl sub_515C80(int a1, _BYTE* a2) {
	int result; // eax

	result = a1;
	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 2) {
			result = *(_DWORD*)(a1 + 748);
			*(_BYTE*)(result + 1332) = *a2;
		}
	}
	return result;
}

//----- (00515CB0) --------------------------------------------------------
int sub_515CB0() {
	char v0;             // bl
	int v1;              // eax
	unsigned __int8* v2; // eax
	char v4;             // [esp+1h] [ebp-1h]

	v0 = script_pop();
	v1 = script_pop();
	v4 = v0;
	v2 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v1);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v2, 0, (void(__cdecl*)(int, int))sub_515C80, (int)&v4);
	return 0;
}

//----- (00515CF0) --------------------------------------------------------
int sub_515CF0() {
	int v0; // edi
	int v1; // eax
	int v2; // esi
	int v3; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v0);
		sub_515D30(v2, v3);
	}
	return 0;
}

//----- (00515D30) --------------------------------------------------------
void __cdecl sub_515D30(int a1, int a2) {
	int v2;  // ebx
	int v3;  // eax
	int* v4; // eax
	int* v5; // eax

	v2 = *(_DWORD*)(a1 + 748);
	if (a1) {
		if (a2) {
			if (*(_BYTE*)(a1 + 8) & 2) {
				if (a1 != a2) {
					v3 = *(_DWORD*)(a1 + 16);
					if ((v3 & 0x8000) == 0) {
						sub_50A3A0(a1);
						*(_DWORD*)(v2 + 1216) = a2;
						sub_5281D0();
						v4 = sub_50A260(a1, 32);
						if (v4)
							v4[1] = 15;
						v5 = sub_50A260(a1, 15);
						if (v5) {
							v5[1] = *(_DWORD*)(a2 + 56);
							v5[2] = *(_DWORD*)(a2 + 60);
							v5[3] = *(_DWORD*)&byte_5D4594[2598000];
						}
					}
				}
			}
		}
	}
}

//----- (00515DB0) --------------------------------------------------------
int sub_515DB0() {
	int v0;              // esi
	int v1;              // edi
	unsigned __int8* v2; // eax
	int v4;              // [esp-4h] [ebp-Ch]

	v0 = script_pop();
	v1 = script_pop();
	v4 = nox_server_scriptValToObjectPtr_511B60(v0);
	v2 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v1);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v2, 0, sub_515D30, v4);
	return 0;
}

//----- (00515DF0) --------------------------------------------------------
int sub_515DF0() {
	int v0; // eax
	int v1; // eax
	int v3; // [esp+0h] [ebp-4h]

	v3 = script_pop();
	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_515E20(v1, &v3);
	return 0;
}

//----- (00515E20) --------------------------------------------------------
int __cdecl sub_515E20(int a1, _DWORD* a2) {
	int result; // eax

	result = a1;
	if (a1 && a2) {
		if (*(_BYTE*)(a1 + 8) & 2) {
			result = *(_DWORD*)(a1 + 748);
			*(_DWORD*)(result + 1336) = *a2;
		}
	}
	return result;
}

//----- (00515E50) --------------------------------------------------------
int sub_515E50() {
	int v0;              // eax
	unsigned __int8* v1; // eax
	int v3;              // [esp+0h] [ebp-4h]

	v3 = script_pop();
	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_515E20, (int)&v3);
	return 0;
}

//----- (00515E80) --------------------------------------------------------
int sub_515E80() {
	int v0; // eax
	int v1; // eax
	int v3; // [esp+0h] [ebp-4h]

	v3 = script_pop();
	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_515EB0(v1, &v3);
	return 0;
}

//----- (00515EB0) --------------------------------------------------------
int __cdecl sub_515EB0(int a1, _DWORD* a2) {
	int result; // eax

	result = a1;
	if (a1 && a2) {
		if (*(_BYTE*)(a1 + 8) & 2) {
			result = *(_DWORD*)(a1 + 748);
			*(_DWORD*)(result + 1344) = *a2;
		}
	}
	return result;
}

//----- (00515EE0) --------------------------------------------------------
int sub_515EE0() {
	int v0;              // eax
	unsigned __int8* v1; // eax
	int v3;              // [esp+0h] [ebp-4h]

	v3 = script_pop();
	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_515EB0, (int)&v3);
	return 0;
}

//----- (00515F10) --------------------------------------------------------
int sub_515F10() {
	int v0;    // ebx
	int v1;    // esi
	int v2;    // edi
	int v3;    // eax
	int v5[2]; // [esp+Ch] [ebp-8h]

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	v5[0] = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v5[0]) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v2);
		if (v3) {
			v5[1] = v0;
			nox_server_scriptFleeFrom_515F70(v3, v5);
		}
	}
	return 0;
}

//----- (00515F70) --------------------------------------------------------
void __cdecl nox_server_scriptFleeFrom_515F70(int a1, _DWORD* a2) {
	int v2;  // eax
	int* v3; // eax
	int* v4; // eax
	int* v5; // eax
	int v6;  // edx
	int v7;  // edx

	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 2) {
			v2 = *(_DWORD*)(a1 + 16);
			if ((v2 & 0x8000) == 0 && !sub_50A0D0(a1, 24)) {
				v3 = sub_50A260(a1, 32);
				if (v3)
					v3[1] = 24;
				v4 = sub_50A260(a1, 41);
				if (v4)
					v4[1] = *(_DWORD*)&byte_5D4594[2598000] + a2[1];
				v5 = sub_50A260(a1, 24);
				if (v5) {
					v6 = *a2;
					v5[1] = *(_DWORD*)(*a2 + 56);
					v7 = *(_DWORD*)(v6 + 60);
					v5[3] = 0;
					v5[2] = v7;
				}
			}
		}
	}
}

//----- (00516000) --------------------------------------------------------
int nox_server_scriptMonsterGroupFleeFrom_516000() {
	int v0;              // edi
	int v1;              // esi
	int v2;              // ebx
	unsigned __int8* v3; // eax
	int v5[2];           // [esp+Ch] [ebp-8h]

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	v5[0] = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v5[0]) {
		v5[1] = v0;
		v3 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v2);
		nox_server_scriptExecuteFnForEachGroupObj_502670(v3, 0, (void(__cdecl*)(int, int))nox_server_scriptFleeFrom_515F70, (int)v5);
	}
	return 0;
}

//----- (00516060) --------------------------------------------------------
int sub_516060() {
	int v0; // eax
	int v1; // eax
	int v3; // [esp+0h] [ebp-4h]

	v3 = script_pop();
	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_516090(v1, &v3);
	return 0;
}

//----- (00516090) --------------------------------------------------------
void __cdecl sub_516090(int a1, _DWORD* a2) {
	int v2;  // eax
	int* v3; // eax
	int* v4; // eax

	if (a1) {
		if (a2) {
			if (*(_BYTE*)(a1 + 8) & 2) {
				v2 = *(_DWORD*)(a1 + 16);
				if ((v2 & 0x8000) == 0) {
					v3 = sub_50A260(a1, 32);
					if (v3)
						v3[1] = 1;
					v4 = sub_50A260(a1, 1);
					if (v4)
						v4[1] = *(_DWORD*)&byte_5D4594[2598000] + *a2;
				}
			}
		}
	}
}

//----- (005160F0) --------------------------------------------------------
int sub_5160F0() {
	int v0;              // eax
	unsigned __int8* v1; // eax
	int v3;              // [esp+0h] [ebp-4h]

	v3 = script_pop();
	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_516090, (int)&v3);
	return 0;
}

//----- (00516120) --------------------------------------------------------
int sub_516120() {
	int v0; // eax
	int v1; // eax
	int v2; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = sub_4FA6D0(v1);
		sub_507230(v2);
	} else {
		sub_507230(0);
	}
	return 0;
}

//----- (00516160) --------------------------------------------------------
int sub_516160() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2)
		sub_4FA620(v2, v0);
	return 0;
}

//----- (00516190) --------------------------------------------------------
int sub_516190() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2)
		sub_4EF3A0_exp_level(v2, *(float*)&v0);
	return 0;
}

//----- (005161C0) --------------------------------------------------------
int sub_5161C0() {
	int v0; // edi
	int v1; // eax
	int v2; // esi
	int v3; // eax
	int v4; // edi

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptValToObjectPtr_511B60(v0);
	v4 = 0;
	if (v2 && v3 && sub_5330C0(v2, v3))
		v4 = 1;
	sub_507230(v4);
	return 0;
}

//----- (00516210) --------------------------------------------------------
int sub_516210() {
	int v0;              // esi
	int v1;              // eax
	int result;          // eax
	const char* v3;      // ecx
	int v4;              // ebp
	const char* v5;      // ebx
	unsigned __int8* v6; // edi
	int v7;              // [esp+10h] [ebp-4h]

	v0 = script_pop();
	v1 = script_pop();
	v7 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v7) {
		v3 = *(const char**)&byte_587000[237172];
		v4 = 1;
		if (*(_DWORD*)&byte_587000[237172]) {
			v5 = *(const char**)&byte_5D4594[4 * v0 + 3831212];
			v6 = &byte_587000[237172];
			while (strcmp(v3, v5)) {
				v3 = (const char*)*((_DWORD*)v6 + 1);
				v6 += 4;
				v4 *= 2;
				if (!v3)
					return 0;
			}
			sub_507230((v4 & *(_DWORD*)(v7 + 8)) != 0);
		}
		result = 0;
	} else {
		sub_507230(0);
		result = 0;
	}
	return result;
}

//----- (005162D0) --------------------------------------------------------
int sub_5162D0() {
	int v0;              // eax
	int result;          // eax
	unsigned __int8* v2; // edi
	int v3;              // ebp
	const char* v4;      // ecx
	bool v5;             // zf
	const char** i;      // [esp+10h] [ebp-10h]
	unsigned __int8* v7; // [esp+14h] [ebp-Ch]
	int v8;              // [esp+18h] [ebp-8h]
	int v9;              // [esp+1Ch] [ebp-4h]

	v8 = script_pop();
	v0 = script_pop();
	v9 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v9) {
		v2 = &byte_587000[237304];
		if (byte_587000 != (unsigned __int8*)-237304) {
			v7 = &byte_587000[237304];
			for (i = (const char**)&byte_587000[237304];; i += 32) {
				v3 = 1;
				v4 = *i;
				if (*i)
					break;
			LABEL_8:
				v5 = v7 + 128 == 0;
				v2 = v7 + 128;
				v7 += 128;
				if (v5)
					return 0;
			}
			while (strcmp(v4, *(const char**)&byte_5D4594[4 * v8 + 3831212])) {
				v4 = (const char*)*((_DWORD*)v2 + 1);
				v2 += 4;
				v3 *= 2;
				if (!v4)
					goto LABEL_8;
			}
			sub_507230((v3 & *(_DWORD*)(v9 + 12)) != 0);
		}
		result = 0;
	} else {
		sub_507230(0);
		result = 0;
	}
	return result;
}

//----- (005163C0) --------------------------------------------------------
int sub_5163C0() {
	int v0; // eax
	int v1; // eax
	int v2; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = sub_548F40(v1);
		sub_507230(v2);
	} else {
		sub_507230(0);
	}
	return 0;
}

//----- (00516400) --------------------------------------------------------
int sub_516400() {
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_4DB130("AUTOSAVE");
		sub_4DB170(1, 0, 0);
	}
	return 0;
}

//----- (00516430) --------------------------------------------------------
int sub_516430() {
	int v0;     // ebx
	char v2[3]; // [esp+4h] [ebp-8h]
	int v3;     // [esp+8h] [ebp-4h]

	v0 = script_pop();
	v3 = script_pop();
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_43D9B0(v3, v0);
	} else {
		v2[1] = v3;
		v2[2] = v0;
		v2[0] = -27;
		sub_4E5390(255, (int)v2, 3, 0, 1);
	}
	return 0;
}

//----- (005164A0) --------------------------------------------------------
int __thiscall sub_5164A0(void* this) {
	void* v2; // [esp+0h] [ebp-4h]

	v2 = this;
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_43DA80();
	} else {
		LOBYTE(v2) = -26;
		sub_4E5390(255, (int)&v2, 3, 0, 1);
	}
	return 0;
}

//----- (005164E0) --------------------------------------------------------
int __thiscall sub_5164E0(void* this) {
	void* v2; // [esp+0h] [ebp-4h]

	v2 = this;
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_43DAD0();
	} else {
		LOBYTE(v2) = -25;
		sub_4E5390(255, (int)&v2, 3, 0, 1);
	}
	return 0;
}

//----- (00516520) --------------------------------------------------------
int __thiscall sub_516520(void* this) {
	void* v2; // [esp+0h] [ebp-4h]

	v2 = this;
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_43D9B0(0, 0);
	} else {
		LOWORD(v2) = 229;
		sub_4E5390(255, (int)&v2, 3, 0, 1);
	}
	return 0;
}

//----- (00516570) --------------------------------------------------------
int __thiscall sub_516570(_BYTE* this) {
	int v1;    // eax
	_BYTE* v2; // esi
	_BYTE* v4; // [esp+0h] [ebp-4h]

	v4 = this;
	v1 = sub_4DA7C0();
	if (v1) {
		do {
			v2 = *(_BYTE**)(*(_DWORD*)(v1 + 748) + 276);
			if (v2[2064] == 31)
				break;
			v1 = sub_4DA7F0(v1);
		} while (v1);
	} else {
		v2 = v4;
	}
	dword_5d4594_2650672 = 1;
	return sub_4D9560((unsigned __int8)v2[2064], byte_5D4594[2386828], *(int*)&byte_5D4594[2386832]);
}

//----- (005165D0) --------------------------------------------------------
int sub_5165D0() {
	*(_DWORD*)&byte_5D4594[2386828] = script_pop() - 1;
	sub_413A00(1);
	return nox_client_screenFadeTimeout_44DAB0(25, 1, (void (*)(void))sub_516570);
}

//----- (00516600) --------------------------------------------------------
int sub_516600() {
	int i;  // esi
	int v1; // esi
	int v2; // edi

	for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
		if (*(_BYTE*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064) == 31)
			break;
	}
	sub_4277B0(i, 0xEu);
	v1 = sub_4E7980(i);
	if (v1) {
		do {
			v2 = sub_4E7990(v1);
			if (*(_BYTE*)(v1 + 8) & 0x40)
				sub_4E5CC0(v1);
			v1 = v2;
		} while (v2);
	}
	*(_DWORD*)&byte_5D4594[2386832] = 1;
	sub_5165D0();
	return 0;
}

//----- (00516680) --------------------------------------------------------
int sub_516680() {
	*(_DWORD*)&byte_5D4594[2386832] = 0;
	sub_5165D0();
	return 0;
}

//----- (005166A0) --------------------------------------------------------
int sub_5166A0() {
	char* v0; // eax
	int v1;   // ecx

	v0 = sub_417090(31);
	v1 = 0;
	if (v0 && *(_DWORD*)(*(_DWORD*)(*((_DWORD*)v0 + 514) + 748) + 284))
		v1 = 1;
	sub_507230(v1);
	return 0;
}

//----- (005166E0) --------------------------------------------------------
int sub_5166E0() {
	char* v0; // eax
	int v1;   // ecx

	v0 = sub_417090(31);
	v1 = 0;
	if (v0 && *(_DWORD*)(*(_DWORD*)(*((_DWORD*)v0 + 514) + 748) + 280))
		v1 = 1;
	sub_507230(v1);
	return 0;
}

//----- (00516720) --------------------------------------------------------
int sub_516720() {
	char* v0; // esi
	int v1;   // eax
	int v2;   // eax
	int v3;   // ecx
	int v4;   // ecx

	v0 = sub_417090(31);
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = *(_DWORD*)(v2 + 12);
		BYTE1(v3) |= 1u;
		*(_DWORD*)(v2 + 12) = v3;
		v4 = *((_DWORD*)v0 + 514);
		if (v4)
			sub_4EC290(v4, v2);
	}
	return 0;
}

//----- (00516760) --------------------------------------------------------
int sub_516760() {
	int v0; // eax
	int v1; // eax
	int v2; // edx

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = *(_DWORD*)(v1 + 12);
		BYTE1(v2) &= 0xFEu;
		*(_DWORD*)(v1 + 12) = v2;
		sub_4EC300(v1);
	}
	return 0;
}

//----- (00516790) --------------------------------------------------------
int __thiscall sub_516790(void* this) {
	int v1;   // eax
	int v2;   // eax
	void* v4; // [esp+0h] [ebp-4h]

	v4 = this;
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2)
		sub_507230((*(_DWORD*)(v2 + 12) >> 8) & 1);
	else
		sub_507230((int)v4);
	return 0;
}

//----- (005167D0) --------------------------------------------------------
int sub_5167D0() {
	char* v0; // esi
	int v1;   // eax
	int v2;   // eax
	int v3;   // ecx

	v0 = sub_417090(31);
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = *((_DWORD*)v0 + 514);
		if (v3)
			sub_4E7B00(v3, v2);
	}
	return 0;
}

//----- (00516810) --------------------------------------------------------
int sub_516810() {
	char* v0;   // esi
	int v1;     // eax
	_DWORD* v2; // eax
	int v3;     // ecx

	v0 = sub_417090(31);
	v1 = script_pop();
	v2 = (_DWORD*)nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = *((_DWORD*)v0 + 514);
		if (v3)
			sub_4E7B60(v3, v2);
	}
	return 0;
}

//----- (00516850) --------------------------------------------------------
int __thiscall sub_516850(void* this) {
	int v1;   // eax
	int v2;   // eax
	void* v4; // [esp+0h] [ebp-4h]

	v4 = this;
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2)
		sub_507230((*(_DWORD*)(v2 + 12) & 0xFFu) >> 7);
	else
		sub_507230((int)v4);
	return 0;
}

//----- (00516890) --------------------------------------------------------
int sub_516890() {
	_DWORD* v0; // edi
	int v1;     // esi
	int v2;     // ebx
	_DWORD* v3; // eax
	_DWORD* v4; // eax

	v0 = (_DWORD*)*((_DWORD*)sub_417090(31) + 514);
	v1 = 0;
	v2 = script_pop();
	v3 = (_DWORD*)v0[126];
	if (v3) {
		while (!(v3[2] & 0x1000000) || !(v3[3] & 0x7800000)) {
			v3 = (_DWORD*)v3[124];
			if (!v3)
				goto LABEL_7;
		}
		v1 = (v3[4] >> 8) & 1;
		sub_4E5CC0((int)v3);
	}
LABEL_7:
	v4 = sub_4EF750((int)v0, *(CHAR**)&byte_587000[4 * v2 + 247336], 0, 1, 1);
	if (v1)
		sub_4F2F70(v0, (int)v4);
	return 0;
}

//----- (00516920) --------------------------------------------------------
int sub_516920() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		if (v0 == 1) {
			sub_4E79C0(v2, 1);
			return 0;
		}
		sub_4E7A60(v2, 1);
	}
	return 0;
}

//----- (00516960) --------------------------------------------------------
int sub_516960() {
	dword_5d4594_2386840 = script_pop();
	return 0;
}

//----- (00516970) --------------------------------------------------------
int sub_516970() {
	int v0;     // esi
	int v1;     // edi
	int v2;     // eax
	int v3;     // eax
	_DWORD* v4; // eax
	int result; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	v3 = nox_server_scriptValToObjectPtr_511B60(v2);
	if (!v3 || !(*(_BYTE*)(v3 + 8) & 2))
		return 0;
	v4 = *(_DWORD**)(v3 + 748);
	switch (v1) {
	case 3:
		v4[309] = v0;
		result = 0;
		break;
	case 4:
		v4[307] = v0;
		result = 0;
		break;
	case 5:
		v4[317] = v0;
		result = 0;
		break;
	case 6:
		v4[311] = v0;
		result = 0;
		break;
	case 7:
		v4[313] = v0;
		result = 0;
		break;
	case 8:
		v4[315] = v0;
		result = 0;
		break;
	case 9:
		v4[319] = v0;
		result = 0;
		break;
	case 10:
		v4[321] = v0;
		result = 0;
		break;
	case 11:
		v4[323] = v0;
		result = 0;
		break;
	case 13:
		v4[325] = v0;
		return 0;
	default:
		return 0;
	}
	return result;
}

//----- (00516A50) --------------------------------------------------------
int sub_516A50() {
	int v0;     // esi
	int v1;     // eax
	_DWORD* v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = (_DWORD*)nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2)
		sub_511660(v2, v0);
	return 0;
}

//----- (00516A80) --------------------------------------------------------
void __cdecl sub_516A80(int a1, int a2, int a3, int a4) {
	int v4;     // eax
	_DWORD* v5; // eax
	int v6;     // ecx

	if (!*(_DWORD*)&byte_5D4594[2386904])
		*(_DWORD*)&byte_5D4594[2386904] = sub_4E3AA0((CHAR*)&byte_587000[247416]);
	v4 = sub_4E7980(a1);
	if (v4) {
		while (*(unsigned __int16*)(v4 + 4) != *(_DWORD*)&byte_5D4594[2386904]) {
			v4 = sub_4E7990(v4);
			if (!v4)
				goto LABEL_8;
		}
		sub_4E5CC0(v4);
	}
LABEL_8:
	v5 = sub_4E3810((CHAR*)&byte_587000[247424]);
	if (v5) {
		v6 = v5[173];
		*(_DWORD*)v6 = a2;
		*(_DWORD*)(v6 + 4) = a3;
		*(_DWORD*)(v6 + 8) = a4;
		*(_BYTE*)(v6 + 20) = 0;
		if (a2)
			*(_BYTE*)(v6 + 20) = 1;
		if (a3)
			++*(_BYTE*)(v6 + 20);
		if (a4)
			++*(_BYTE*)(v6 + 20);
		*(_DWORD*)(v6 + 24) = 0;
		*(_DWORD*)(v6 + 28) = *(_DWORD*)(a1 + 56);
		*(_DWORD*)(v6 + 32) = *(_DWORD*)(a1 + 60);
		sub_4F3070(a1, (int)v5, 1);
	}
}

//----- (00516B40) --------------------------------------------------------
int sub_516B40() {
	int v0; // ebp
	int v1; // ebx
	int v2; // edi
	int v3; // eax
	int v4; // eax
	int v5; // esi
	int v6; // eax
	int v7; // edi
	int v8; // ebx
	int v9; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	v3 = script_pop();
	v4 = nox_server_scriptValToObjectPtr_511B60(v3);
	v5 = v4;
	if (v4) {
		if (*(_BYTE*)(v4 + 8) & 2) {
			v6 = *(_DWORD*)(v4 + 12);
			if (v6 & 0x2000) {
				v7 = sub_4243F0(*(const char**)&byte_5D4594[4 * v2 + 3831212]);
				v8 = sub_4243F0(*(const char**)&byte_5D4594[4 * v1 + 3831212]);
				v9 = sub_4243F0(*(const char**)&byte_5D4594[4 * v0 + 3831212]);
				sub_516A80(v5, v7, v8, v9);
			}
		}
	}
	return 0;
}

//----- (00516BC0) --------------------------------------------------------
int sub_516BC0() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_4D9760(v1);
	return 0;
}

//----- (00516BE0) --------------------------------------------------------
int sub_516BE0() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2)
		sub_548FE0(v2, *(const char**)&byte_5D4594[4 * v0 + 3831212]);
	return 0;
}

//----- (00516C10) --------------------------------------------------------
int sub_516C10() {
	sub_44E040();
	return 0;
}

//----- (00516C20) --------------------------------------------------------
int sub_516C20() {
	sub_44E0B0(1);
	return 0;
}

//----- (00516C30) --------------------------------------------------------
int sub_516C30() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && *(_BYTE*)(v2 + 8) & 2)
		v1 = (*(_DWORD*)(*(_DWORD*)(v2 + 748) + 1440) >> 7) & 1;
	sub_507230(v1);
	return 0;
}

//----- (00516C70) --------------------------------------------------------
int sub_516C70() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_516C90(v1);
	return 0;
}

//----- (00516C90) --------------------------------------------------------
int __cdecl sub_516C90(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 2)
			*(_DWORD*)(*(_DWORD*)(a1 + 748) + 1440) |= 0x100000u;
	}
	return result;
}

//----- (00516CB0) --------------------------------------------------------
int sub_516CB0() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_516C90, 0);
	return 0;
}

//----- (00516CE0) --------------------------------------------------------
int sub_516CE0() {
	int v0; // eax
	int v1; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1)
		sub_516D00(v1);
	return 0;
}

//----- (00516D00) --------------------------------------------------------
unsigned int __cdecl sub_516D00(int a1) {
	unsigned int result; // eax
	int v2;              // edx

	result = a1;
	if (a1 && *(_BYTE*)(a1 + 8) & 2) {
		v2 = *(_DWORD*)(a1 + 16);
		if ((v2 & 0x8000) != 0) {
			*(_DWORD*)(*(_DWORD*)(a1 + 748) + 1440) &= 0xFFEFFFFF;
			result = sub_534AB0(a1);
		}
	}
	return result;
}

//----- (00516D40) --------------------------------------------------------
int sub_516D40() {
	int v0;              // eax
	unsigned __int8* v1; // eax

	v0 = script_pop();
	v1 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, (void(__cdecl*)(int, int))sub_516D00, 0);
	return 0;
}

//----- (00516D70) --------------------------------------------------------
int sub_516D70() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = *(_DWORD*)&byte_5D4594[2386908];
		if (!*(_DWORD*)&byte_5D4594[2386908]) {
			v2 = sub_4E3AA0((CHAR*)&byte_587000[247432]);
			*(_DWORD*)&byte_5D4594[2386908] = v2;
		}
		sub_507230(*(unsigned __int16*)(v1 + 4) == v2);
	}
	return 0;
}

//----- (00516DC0) --------------------------------------------------------
int sub_516DC0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = *(_DWORD*)&byte_5D4594[2386912];
		if (!*(_DWORD*)&byte_5D4594[2386912]) {
			v2 = sub_4E3AA0((CHAR*)&byte_587000[247444]);
			*(_DWORD*)&byte_5D4594[2386912] = v2;
		}
		sub_507230(*(unsigned __int16*)(v1 + 4) == v2);
	}
	return 0;
}

//----- (00516E10) --------------------------------------------------------
int sub_516E10() {
	int v0; // eax

	v0 = script_pop();
	sub_578C90(v0);
	return 0;
}

//----- (00516E30) --------------------------------------------------------
int sub_516E30() {
	int v0;   // edi
	int v1;   // eax
	int v2;   // eax
	int v3;   // esi
	char* v4; // eax

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = v2;
	if (v2 && *(_BYTE*)(v2 + 8) & 4) {
		if (v0 <= 0)
			sub_4D8EC0(v2, -v0);
		else
			sub_4D8E90(v2, v0);
		v4 = sub_418AB0(*(unsigned __int8*)(v3 + 52));
		if (v4)
			sub_419090((int)v4, v0 + *((_DWORD*)v4 + 13));
		sub_4D8EF0(v3);
	}
	return 0;
}

//----- (00516EA0) --------------------------------------------------------
int sub_516EA0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && *(_BYTE*)(v2 + 8) & 4)
		v1 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v2 + 748) + 276) + 2136);
	sub_507230(v1);
	return 0;
}

//----- (00516EE0) --------------------------------------------------------
BOOL sub_516EE0() {
	dword_5d4594_2386920 = 0;
	dword_5d4594_2386916 = nox_new_alloc_class("PendingOwn", 12, 512);
	return dword_5d4594_2386916 != 0;
}

//----- (00516F10) --------------------------------------------------------
int sub_516F10() {
	int result; // eax

	nox_free_alloc_class(*(LPVOID*)&dword_5d4594_2386916);
	result = 0;
	dword_5d4594_2386916 = 0;
	dword_5d4594_2386920 = 0;
	return result;
}

//----- (00516F30) --------------------------------------------------------
void sub_516F30() {
	sub_4144D0(*(_DWORD**)&dword_5d4594_2386916);
	dword_5d4594_2386920 = 0;
}

//----- (00516F50) --------------------------------------------------------
int __cdecl sub_516F50(int a1, int a2) {
	int v2; // eax

	v2 = sub_4DA870();
	if (!v2)
		return 0;
	while (*(_DWORD*)(v2 + 44) != a2) {
		v2 = sub_4DA880(v2);
		if (!v2)
			return 0;
	}
	sub_4EC290(a1, v2);
	return 1;
}

//----- (00516F90) --------------------------------------------------------
_DWORD* __cdecl sub_516F90(int a1, int a2) {
	_DWORD* result; // eax

	result = nox_alloc_class_new_obj_zero(*(_DWORD**)&dword_5d4594_2386916);
	if (result) {
		*result = a1;
		result[1] = a2;
		result[2] = dword_5d4594_2386920;
		dword_5d4594_2386920 = result;
	}
	return result;
}

//----- (00516FC0) --------------------------------------------------------
void sub_516FC0() {
	int* v0; // esi
	int v1;  // edi
	int v2;  // eax

	v0 = *(int**)&dword_5d4594_2386920;
	if (dword_5d4594_2386920) {
		do {
			v1 = sub_4ECF10(*v0);
			v2 = sub_4ECF10(v0[1]);
			if (v1 && v2)
				sub_4EC290(v1, v2);
			v0 = (int*)v0[2];
		} while (v0);
	}
	sub_516F30();
}

//----- (00517010) --------------------------------------------------------
int sub_517010() {
	int result;   // eax
	FILE* v1;     // esi
	char v2[256]; // [esp+4h] [ebp-100h]

	dword_5d4594_2386924 = 0;
	result = sub_408CC0_fopen((char*)&byte_587000[249116], 0);
	v1 = (FILE*)result;
	if (result) {
		result = sub_408D40(result, 23);
		if (result) {
			while (sub_517090(v1, v2) && sub_517170(v1, v2))
				;
			sub_408D90(v1);
			result = 1;
		}
	}
	return result;
}

//----- (00517090) --------------------------------------------------------
int __cdecl sub_517090(FILE* a1, _BYTE* a2) {
	_BYTE* v2;        // ebx
	int v3;           // ecx
	int v4;           // edi
	int v5;           // ebp
	int v6;           // eax
	WORD CharType[2]; // [esp+10h] [ebp-4h]

	v2 = a2;
	v3 = 0;
	*(_DWORD*)CharType = 0;
	v4 = 1;
	do {
		while (1) {
			v5 = v3;
			sub_408E40_fread((char*)CharType, 1, 1, a1);
			if (sub_409370() == -1)
				return 0;
			if (*(_DWORD*)&byte_587000[1668] <= 1) {
				v3 = *(_DWORD*)CharType;
				v6 = isspace(CharType[0]);
			} else {
				v6 = isspace(CharType[0]);
				v3 = *(_DWORD*)CharType;
			}
			if (v6)
				break;
			v4 = 0;
			if (v3 != 47 || v5 != 47) {
				*v2++ = v3;
			} else {
				sub_517140(a1);
				v2 = a2;
				v3 = *(_DWORD*)CharType;
				v4 = 1;
			}
		}
	} while (v4);
	*v2 = 0;
	return 1;
}

//----- (00517140) --------------------------------------------------------
int __cdecl sub_517140(FILE* a1) {
	FILE* v1;   // esi
	int result; // eax

	v1 = a1;
	do {
		LOBYTE(a1) = 0;
		sub_408E40_fread((char*)&a1, 1, 1, v1);
		result = sub_409370();
	} while (result != -1 && (_BYTE)a1 != 10);
	return result;
}

//----- (00517170) --------------------------------------------------------
int __cdecl sub_517170(FILE* a1, const char* a2) {
	int result;          // eax
	_DWORD* v3;          // ebx
	unsigned __int8* v4; // esi
	int v5;              // eax
	char* v6;            // edi
	int v7;              // edi
	unsigned __int8* v8; // esi
	int v9;              // [esp+10h] [ebp-104h]
	char v10[256];       // [esp+14h] [ebp-100h]

	result = (int)nox_calloc(1u, 0xF8u);
	v3 = (_DWORD*)result;
	if (result) {
		strcpy((char*)result, a2);
		while (1) {
			if (!sub_517090(a1, v10) || !_strcmpi("END", v10)) {
				v3[61] = dword_5d4594_2386924;
				dword_5d4594_2386924 = v3;
				return 1;
			}
			if (nox_common_gameFlags_check_40A5C0(2048) || nox_common_gameFlags_check_40A5C0(0x200000)) {
				if (_strcmpi("ARENA", v10)) {
					if (_strcmpi("SOLO", v10))
						goto LABEL_10;
				} else {
					sub_517140(a1);
				}
			} else {
			LABEL_10:
				if (!nox_common_gameFlags_check_40A5C0(0x2000))
					goto LABEL_14;
				if (_strcmpi("SOLO", v10)) {
					if (_strcmpi("ARENA", v10)) {
					LABEL_14:
						v4 = &byte_587000[248192];
						if (*(_DWORD*)&byte_587000[248192]) {
							do {
								if (!_strcmpi(*(const char**)v4, v10))
									break;
								v5 = *((_DWORD*)v4 + 3);
								v4 += 12;
							} while (v5);
						}
						if (!*(_DWORD*)v4) {
							free(v3);
							return 0;
						}
						v6 = (char*)v3 + *((_DWORD*)v4 + 2);
						switch (*((_DWORD*)v4 + 1)) {
						case 0:
							sub_517090(a1, v10);
							*(_DWORD*)v6 = atoi(v10);
							continue;
						case 1:
							sub_517090(a1, v10);
							*(float*)v6 = atof(v10);
							continue;
						case 2:
							sub_517090(a1, v10);
							*(_DWORD*)v6 = sub_40AF50(v10);
							continue;
						case 3:
							sub_517090(a1, v10);
							if (sub_549040((int)v3, v10))
								continue;
							return 0;
						case 4:
							sub_517090(a1, v10);
							if (sub_5490E0((int)v3, v10))
								continue;
							return 0;
						case 5:
							sub_517090(a1, v10);
							if (sub_549180((int)v3, v10))
								continue;
							return 0;
						case 6:
							v9 = 0;
							sub_517090(a1, v10);
							sub_423930(v10, &v9, (const char**)&byte_587000[247536]);
							*(_WORD*)v6 = v9;
							continue;
						case 7:
							sub_517090(a1, v6);
							if (!strcmp("NULL", v6))
								*v6 = 0;
							continue;
						case 8:
							sub_517090(a1, v10);
							v3[31] = 18;
							v7 = 0;
							v8 = &byte_587000[247464];
							break;
						default:
							continue;
						}
						while (_strcmpi(v10, (const char*)(*(_DWORD*)v8 + 7))) {
							v8 += 4;
							++v7;
							if ((int)v8 >= (int)&byte_587000[247536])
								goto LABEL_27;
						}
						v3[31] = v7;
					LABEL_27:
						if (v3[31] == 18)
							return 0;
					}
				} else {
					sub_517140(a1);
				}
			}
		}
	}
	return result;
}

//----- (005174F0) --------------------------------------------------------
_DWORD* sub_5174F0() {
	_DWORD* result; // eax
	_DWORD* v1;     // esi

	result = *(_DWORD**)&dword_5d4594_2386924;
	if (dword_5d4594_2386924) {
		do {
			v1 = (_DWORD*)result[61];
			free(result);
			result = v1;
		} while (v1);
		dword_5d4594_2386924 = 0;
	}
	return result;
}

//----- (00517520) --------------------------------------------------------
int sub_517520() {
	int v0; // esi
	int v1; // eax

	v0 = dword_5d4594_2386924;
	if (!dword_5d4594_2386924)
		return 1;
	while (1) {
		v1 = sub_4E3AA0((CHAR*)v0);
		*(_DWORD*)(v0 + 240) = v1;
		if (!v1)
			break;
		v0 = *(_DWORD*)(v0 + 244);
		if (!v0)
			return 1;
	}
	sub_5174F0();
	return 0;
}

//----- (00517560) --------------------------------------------------------
_DWORD* __cdecl sub_517560(int a1) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_2386924;
	if (!dword_5d4594_2386924)
		return 0;
	while (result[60] != a1) {
		result = (_DWORD*)result[61];
		if (!result)
			return 0;
	}
	return result;
}

//----- (00517590) --------------------------------------------------------
BOOL __cdecl sub_517590(float a1, float a2) {
	int v4; // [esp+0h] [ebp-4h]

	sub_5175E0(a1, (int)&a1);
	sub_5175E0(a2, (int)&v4);
	return a1 >= 0.0 && SLODWORD(a1) < *(int*)&dword_5d4594_2386944 && v4 >= 0 && v4 < *(int*)&dword_5d4594_2386944;
}

//----- (005175E0) --------------------------------------------------------
int __cdecl sub_5175E0(float a1, int a2) {
	int result; // eax

	if (a1 >= 0.0) {
		result = a2;
		*(_DWORD*)&byte_5D4594[2386932] = &byte_5D4594[2386952];
		*(float*)&byte_5D4594[2386952] = a1 * 0.011764706 + 8388608.0;
		*(_DWORD*)a2 = 0x7FFFFF & *(_DWORD*)&byte_5D4594[2386952];
	} else {
		result = nox_float2int(a1);
		*(_DWORD*)a2 = result;
	}
	return result;
}

//----- (00517640) --------------------------------------------------------
__int16 __cdecl sub_517640(signed int a1) {
	int v1;        // edi
	int v2;        // eax
	signed int v3; // esi
	int v4;        // ebx
	signed int v5; // eax
	int v6;        // ecx
	int v8;        // [esp+4h] [ebp-14h]
	int v9;        // [esp+8h] [ebp-10h]
	int v10;       // [esp+Ch] [ebp-Ch]
	int v11;       // [esp+10h] [ebp-8h]
	int v12;       // [esp+14h] [ebp-4h]

	v1 = a1;
	v2 = *(_DWORD*)(a1 + 16);
	if (!(v2 & 0x20) && !(v2 & 0x200) && v2 & 4) {
		if (!(*(_BYTE*)(a1 + 8) & 1)) {
			sub_4E7350(a1);
			sub_5175E0(*(float*)(v1 + 232), (int)&v8);
			sub_5175E0(*(float*)(v1 + 236), (int)&v10);
			sub_5175E0(*(float*)(v1 + 240), (int)&a1);
			sub_5175E0(*(float*)(v1 + 244), (int)&v9);
			v3 = v8;
			if (v8 < 0) {
				v3 = 0;
				v8 = 0;
			}
			v4 = v10;
			if (v10 < 0) {
				v4 = 0;
				v10 = 0;
			}
			v5 = a1;
			if (a1 >= *(int*)&dword_5d4594_2386944) {
				v5 = dword_5d4594_2386944 - 1;
				a1 = dword_5d4594_2386944 - 1;
			}
			v6 = v9;
			if (v9 >= *(int*)&dword_5d4594_2386944) {
				v6 = dword_5d4594_2386944 - 1;
				v9 = dword_5d4594_2386944 - 1;
			}
			for (*(_BYTE*)(v1 + 336) = 0; v4 <= v6; ++v4) {
				if (v3 <= v5) {
					do {
						sub_517780(1, v3, v4, v1);
						v5 = a1;
						++v3;
					} while (v3 <= a1);
					v3 = v8;
					v6 = v9;
				}
			}
		}
		sub_5175E0(*(float*)(v1 + 64), (int)&v12);
		sub_5175E0(*(float*)(v1 + 68), (int)&v11);
		sub_517780(0, v12, v11, v1);
		v2 = *(_DWORD*)(v1 + 16);
		BYTE1(v2) |= 2u;
		*(_DWORD*)(v1 + 16) = v2;
	}
	return v2;
}

//----- (00517780) --------------------------------------------------------
int __cdecl sub_517780(int a1, int a2, int a3, int a4) {
	int result;         // eax
	unsigned __int8 v5; // cl
	int v6;             // esi
	int v7;             // esi

	if (a1) {
		result = a1 - 1;
		if (a1 == 1) {
			v5 = *(_BYTE*)(a4 + 336);
			if (v5 < 4u) {
				result = a4 + 16 * (v5 + 17);
				*(_BYTE*)(a4 + 336) = v5 + 1;
				*(_WORD*)result = a2;
				*(_WORD*)(result + 2) = a3;
				*(_DWORD*)(result + 12) = a4;
				*(_DWORD*)(result + 8) = 0;
				*(_DWORD*)(result + 4) =
				    *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * a2) + 16 * a3 + 4);
				v6 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * a2) + 16 * a3 + 4);
				if (v6)
					*(_DWORD*)(v6 + 8) = result;
				*(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * a2) + 16 * a3 + 4) = result;
			}
		}
	} else {
		*(_DWORD*)(a4 + 268) = a4;
		result = a4 + 256;
		*(_WORD*)(a4 + 256) = a2;
		*(_WORD*)(a4 + 258) = a3;
		*(_DWORD*)(a4 + 264) = 0;
		*(_DWORD*)(a4 + 260) = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * a2) + 16 * a3);
		v7 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * a2) + 16 * a3);
		if (v7)
			*(_DWORD*)(v7 + 8) = result;
		*(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * a2) + 16 * a3) = result;
	}
	return result;
}

//----- (00517870) --------------------------------------------------------
__int16 __cdecl sub_517870(int a1) {
	int v1;               // eax
	int v2;               // edi
	unsigned __int16* v3; // ebx

	v1 = *(_DWORD*)(a1 + 16);
	if (v1 & 0x200) {
		sub_5178E0(0, (unsigned __int16*)(a1 + 256));
		if (!(*(_BYTE*)(a1 + 8) & 1)) {
			v2 = 0;
			if (*(_BYTE*)(a1 + 336)) {
				v3 = (unsigned __int16*)(a1 + 272);
				do {
					sub_5178E0(1, v3);
					++v2;
					v3 += 8;
				} while (v2 < *(unsigned __int8*)(a1 + 336));
			}
			*(_BYTE*)(a1 + 336) = 0;
		}
		v1 = *(_DWORD*)(a1 + 16);
		BYTE1(v1) &= 0xFDu;
		*(_DWORD*)(a1 + 16) = v1;
	}
	return v1;
}

//----- (005178E0) --------------------------------------------------------
unsigned __int16* __cdecl sub_5178E0(int a1, unsigned __int16* a2) {
	unsigned __int16* result; // eax
	int v3;                   // ecx
	int v4;                   // ecx
	int v5;                   // ecx
	int v6;                   // ecx

	if (a1) {
		result = (unsigned __int16*)(a1 - 1);
		if (a1 == 1) {
			result = a2;
			v3 = *((_DWORD*)a2 + 2);
			if (v3)
				*(_DWORD*)(v3 + 4) = *((_DWORD*)a2 + 1);
			else
				*(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * *a2) + 16 * a2[1] + 4) =
				    *((_DWORD*)a2 + 1);
			v4 = *((_DWORD*)a2 + 1);
			if (v4)
				*(_DWORD*)(v4 + 8) = *((_DWORD*)a2 + 2);
		}
	} else {
		result = a2;
		v5 = *((_DWORD*)a2 + 2);
		if (v5)
			*(_DWORD*)(v5 + 4) = *((_DWORD*)a2 + 1);
		else
			*(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * *a2) + 16 * a2[1]) =
			    *((_DWORD*)a2 + 1);
		v6 = *((_DWORD*)a2 + 1);
		if (v6)
			*(_DWORD*)(v6 + 8) = *((_DWORD*)a2 + 2);
	}
	return result;
}

//----- (00517970) --------------------------------------------------------
void __cdecl sub_517970(int a1) {
	sub_517870(a1);
	if (sub_517590(*(float*)(a1 + 64), *(float*)(a1 + 68)))
		sub_517640(a1);
	else
		sub_4E5CC0(a1);
}

//----- (005179B0) --------------------------------------------------------
void __cdecl sub_5179B0(int a1) {
	int v1;     // esi
	int v2;     // eax
	int v3;     // ecx
	int v4;     // edx
	int v5;     // eax
	__int16 v6; // dx
	int v7;     // eax
	int v8;     // [esp+4h] [ebp-4h]

	v1 = a1;
	if (!(*(_BYTE*)(a1 + 480) & 2)) {
		sub_5175E0(*(float*)(a1 + 8), (int)&a1);
		sub_5175E0(*(float*)(v1 + 12), (int)&v8);
		v2 = v8;
		v3 = a1;
		v4 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * a1) + 16 * v8 + 8);
		if (v4) {
			*(_DWORD*)(v4 + 500) = v1;
			v3 = a1;
			v2 = v8;
		}
		*(_DWORD*)(v1 + 500) = 0;
		v5 = 16 * v2;
		*(_DWORD*)(v1 + 496) = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * v3) + v5 + 8);
		*(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * v3) + v5 + 8) = v1;
		v6 = a1;
		*(_WORD*)(v1 + 494) = v8;
		v7 = *(_DWORD*)(v1 + 480);
		*(_WORD*)(v1 + 492) = v6;
		LOBYTE(v7) = v7 | 2;
		*(_DWORD*)(v1 + 480) = v7;
	}
}

//----- (00517A70) --------------------------------------------------------
int __cdecl sub_517A70(int a1) {
	int result; // eax
	int v2;     // ecx
	int v3;     // ecx

	result = a1;
	if (*(_BYTE*)(a1 + 480) & 2) {
		v2 = *(_DWORD*)(a1 + 500);
		if (v2)
			*(_DWORD*)(v2 + 496) = *(_DWORD*)(a1 + 496);
		else
			*(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * *(__int16*)(a1 + 492)) +
				   16 * *(__int16*)(a1 + 494) + 8) = *(_DWORD*)(a1 + 496);
		v3 = *(_DWORD*)(a1 + 496);
		if (v3)
			*(_DWORD*)(v3 + 500) = *(_DWORD*)(a1 + 500);
		*(_DWORD*)(a1 + 480) &= 0xFFFFFFFD;
	}
	return result;
}

//----- (00517AE0) --------------------------------------------------------
int sub_517AE0() {
	size_t v0; // eax
	int i;     // esi

	dword_5d4594_2386944 = 70;
	dword_5d4594_2386940 = nox_malloc(0x118u);
	v0 = dword_5d4594_2386944;
	for (i = 0; i < *(int*)&dword_5d4594_2386944; ++i) {
		*(_DWORD*)(dword_5d4594_2386940 + 4 * i) = nox_calloc(v0, 0x10u);
		v0 = dword_5d4594_2386944;
	}
	return 1;
}

//----- (00517B30) --------------------------------------------------------
void sub_517B30() {
	int i; // esi

	for (i = 0; i < *(int*)&dword_5d4594_2386944; ++i)
		free(*(LPVOID*)(dword_5d4594_2386940 + 4 * i));
	free(*(LPVOID*)&dword_5d4594_2386940);
}

//----- (00517B70) --------------------------------------------------------
void __cdecl sub_517B70(float2* a1, void(__cdecl* a2)(_DWORD, int), int a3) {
	int v3; // ecx
	int v4; // eax
	int i;  // esi
	int v6; // [esp+8h] [ebp-8h]
	int v7; // [esp+Ch] [ebp-4h]

	if (!a2)
		return;
	sub_5175E0(a1->field_0, (int)&v6);
	sub_5175E0(a1->field_4, (int)&v7);
	v3 = v6;
	if (v6 >= 0) {
		if (v6 < *(int*)&dword_5d4594_2386944)
			goto LABEL_7;
		v3 = dword_5d4594_2386944 - 1;
	} else {
		v3 = 0;
	}
	v6 = v3;
LABEL_7:
	v4 = v7;
	if (v7 >= 0) {
		if (v7 < *(int*)&dword_5d4594_2386944)
			goto LABEL_12;
		v4 = dword_5d4594_2386944 - 1;
	} else {
		v4 = 0;
	}
	v7 = v4;
LABEL_12:
	for (i = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * v3) + 16 * v4 + 4); i;
	     i = *(_DWORD*)(i + 4))
		a2(*(_DWORD*)(i + 12), a3);
}

//----- (00517C10) --------------------------------------------------------
void __cdecl sub_517C10(float4* a1, void(__cdecl* a2)(float*, int), int a3) {
	int v3;                          // eax
	int v4;                          // et1
	void(__cdecl * v5)(float*, int); // ebp
	int v6;                          // eax
	int v7;                          // edi
	float4* v8;                      // edi
	int v9;                          // esi
	int v10;                         // edx
	int v11;                         // eax
	int v12;                         // ecx
	int v13;                         // ebx
	int v14;                         // eax
	int v15;                         // ecx
	int v16;                         // esi
	int v17;                         // et1
	_DWORD* v18;                     // eax
	int v19;                         // ecx
	float* v20;                      // ecx
	int v21;                         // et1
	int v22;                         // [esp+4h] [ebp-10h]
	int v23;                         // [esp+8h] [ebp-Ch]
	int v24;                         // [esp+Ch] [ebp-8h]
	int v25;                         // [esp+10h] [ebp-4h]
	int v26;                         // [esp+18h] [ebp+4h]
	int v27;                         // [esp+1Ch] [ebp+8h]
	int v28;                         // [esp+20h] [ebp+Ch]

	v4 = *(_DWORD*)&byte_587000[249172];
	v3 = v4;
	if (v4 < 1) {
		v5 = a2;
		if (a2) {
			v6 = v3 + 1;
			v7 = *(_DWORD*)&byte_5D4594[4 * v6 + 2386964];
			*(_DWORD*)&byte_587000[249172] = v6;
			*(_DWORD*)&byte_5D4594[4 * v6 + 2386964] = v7 + 1;
			v8 = a1;
			sub_5175E0(a1->field_0, (int)&v24);
			sub_5175E0(a1->field_4, (int)&v25);
			sub_5175E0(a1->field_8, (int)&v22);
			sub_5175E0(a1->field_C, (int)&v23);
			v9 = v24;
			if (v24 < 0) {
				v24 = 0;
				v9 = 0;
			}
			v10 = v22;
			if (v22 >= *(int*)&dword_5d4594_2386944) {
				v10 = dword_5d4594_2386944 - 1;
				v22 = dword_5d4594_2386944 - 1;
			}
			v11 = v25;
			if (v25 < 0) {
				v11 = 0;
				v25 = 0;
			}
			if (v23 >= *(int*)&dword_5d4594_2386944)
				v23 = dword_5d4594_2386944 - 1;
			v12 = v11;
			v26 = v11;
			if (v11 <= v23) {
				v13 = a3;
				do {
					v14 = v9;
					v27 = v9;
					if (v9 <= v10) {
						v15 = 16 * v12;
						v28 = v15;
						do {
							v16 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 +
										    4 * v14) +
									 v15 + 4);
							if (v16) {
								do {
									v17 = *(_DWORD*)&byte_587000[249172];
									v18 = (_DWORD*)(*(_DWORD*)(v16 + 12) + 4 * v17 +
											248);
									v19 = *(_DWORD*)&byte_5D4594[4 * v17 + 2386964];
									if (*v18 != v19) {
										*v18 = v19;
										v20 = *(float**)(v16 + 12);
										if (v20[58] < (double)v8->field_8 &&
										    v20[60] > (double)v8->field_0 &&
										    v20[59] < (double)v8->field_C &&
										    v20[61] > (double)v8->field_4) {
											v5(v20, v13);
										}
									}
									v16 = *(_DWORD*)(v16 + 4);
								} while (v16);
								v15 = v28;
								v10 = v22;
								v14 = v27;
							}
							v27 = ++v14;
						} while (v14 <= v10);
						v12 = v26;
						v9 = v24;
					}
					v26 = ++v12;
				} while (v12 <= v23);
			}
			v21 = *(_DWORD*)&byte_587000[249172];
			*(_DWORD*)&byte_587000[249172] = v21 - 1;
		}
	}
}

//----- (00517DC0) --------------------------------------------------------
void __cdecl sub_517DC0(float4* a1, void(__cdecl* a2)(int, int), int a3) {
	void(__cdecl * v3)(int, int); // ebp
	int v4;                       // ebx
	int v5;                       // edx
	int v6;                       // eax
	int v7;                       // ecx
	int v8;                       // eax
	int v9;                       // esi
	int v10;                      // eax
	int v11;                      // [esp+Ch] [ebp-10h]
	int v12;                      // [esp+10h] [ebp-Ch]
	int v13;                      // [esp+14h] [ebp-8h]
	int v14;                      // [esp+18h] [ebp-4h]
	float4* v15;                  // [esp+20h] [ebp+4h]
	int i;                        // [esp+24h] [ebp+8h]

	v3 = a2;
	if (a2) {
		sub_5175E0(a1->field_0, (int)&v13);
		sub_5175E0(a1->field_4, (int)&v14);
		sub_5175E0(a1->field_8, (int)&v11);
		sub_5175E0(a1->field_C, (int)&v12);
		v4 = v13;
		if (v13 < 0) {
			v13 = 0;
			v4 = 0;
		}
		v5 = v11;
		if (v11 >= *(int*)&dword_5d4594_2386944) {
			v5 = dword_5d4594_2386944 - 1;
			v11 = dword_5d4594_2386944 - 1;
		}
		v6 = v14;
		if (v14 < 0) {
			v6 = 0;
			v14 = 0;
		}
		if (v12 >= *(int*)&dword_5d4594_2386944)
			v12 = dword_5d4594_2386944 - 1;
		v7 = v6;
		for (i = v6; v7 <= v12; i = v7) {
			if (v4 <= v5) {
				v8 = 16 * v7;
				v15 = (float4*)(16 * v7);
				do {
					v9 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * v4) + v8);
					if (v9) {
						do {
							v10 = *(_DWORD*)(v9 + 12);
							if (*(_BYTE*)(v10 + 8) & 1)
								v3(v10, a3);
							v9 = *(_DWORD*)(v9 + 4);
						} while (v9);
						v5 = v11;
						v8 = (int)v15;
					}
					++v4;
				} while (v4 <= v5);
				v4 = v13;
				v7 = i;
			}
			++v7;
		}
	}
}

//----- (00517ED0) --------------------------------------------------------
void __cdecl sub_517ED0(float4* a1, void(__cdecl* a2)(float*, int), int a3) {
	sub_517C10(a1, a2, a3);
	sub_517DC0(a1, (void(__cdecl*)(int, int))a2, a3);
}

//----- (00517F00) --------------------------------------------------------
int* __cdecl sub_517F00(float* a1, int(__cdecl* a2)(int*, int), int a3) {
	int* result; // eax
	int* i;      // esi
	double v5;   // st7
	double v6;   // st7

	result = (int*)sub_410780();
	for (i = result; result; i = result) {
		v5 = (double)(23 * i[1]);
		if (v5 > *a1 && v5 < a1[2]) {
			v6 = (double)(23 * i[2]);
			if (v6 > a1[1] && v6 < a1[3])
				a2(i, a3);
		}
		result = (int*)sub_410790(i);
	}
	return result;
}

//----- (00517F90) --------------------------------------------------------
void __cdecl sub_517F90(float2* a1, float a2, int a3, int a4) {
	double v4;  // st7
	int a3a[4]; // [esp+0h] [ebp-20h]
	float4 a1a; // [esp+10h] [ebp-10h]

	a3a[0] = (int)a1;
	a3a[2] = a3;
	*(float*)&a3a[1] = a2 * a2;
	v4 = a1->field_0 - a2;
	a3a[3] = a4;
	a1a.field_0 = v4;
	a1a.field_4 = a1->field_4 - a2;
	a1a.field_8 = a2 + a1->field_0;
	a1a.field_C = a2 + a1->field_4;
	sub_517C10(&a1a, sub_518000, (int)a3a);
}

//----- (00518000) --------------------------------------------------------
void __cdecl sub_518000(float* a1, int a2) {
	double v2; // st7
	double v3; // st6

	v2 = **(float**)a2 - a1[14];
	v3 = *(float*)(*(_DWORD*)a2 + 4) - a1[15];
	if (v3 * v3 + v2 * v2 < *(float*)(a2 + 4))
		(*(void(__cdecl**)(float*, _DWORD))(a2 + 8))(a1, *(_DWORD*)(a2 + 12));
}

//----- (00518040) --------------------------------------------------------
int __cdecl sub_518040(int arg0, float a2, int arg8, int a4) {
	int result; // eax
	double v5;  // st7
	double v6;  // st7
	int a3[4];  // [esp+0h] [ebp-20h]
	float4 a1;  // [esp+10h] [ebp-10h]

	result = arg0;
	if (arg0) {
		v5 = *(float*)arg0 - a2;
		a3[2] = arg8;
		a3[0] = arg0;
		*(float*)&a3[1] = a2;
		a1.field_0 = v5;
		v6 = *(float*)(arg0 + 4) - a2;
		a3[3] = a4;
		a1.field_4 = v6;
		a1.field_8 = a2 + *(float*)arg0;
		a1.field_C = a2 + *(float*)(arg0 + 4);
		sub_517C10(&a1, sub_5180B0, (int)a3);
	}
	return result;
}

//----- (005180B0) --------------------------------------------------------
void __cdecl sub_5180B0(int a1, int a2) {
	float2* v2;     // eax
	double v3;      // st7
	long double v4; // st7
	long double v5; // st7
	float2* v6;     // eax
	double v7;      // st7
	float2 v8;

	if (a1 && a2) {
		if (*(_DWORD*)(a1 + 172) == 2) {
			v6 = *(float2**)a2;
			*(float*)&v8 = **(float**)a2 - *(float*)(a1 + 56);
			v7 = v6->field_4 - *(float*)(a1 + 60);
			v8.field_4 = v7;
			v4 = sqrt(v7 * v8.field_4 + v8.field_0 * v8.field_0) - *(float*)(a1 + 176);
		} else {
			if (*(_DWORD*)(a1 + 172) == 3) {
				v5 = sub_54A990((float2*)*(_DWORD*)a2, *(float*)(a2 + 4), a1, &v8);
				goto LABEL_9;
			}
			v2 = *(float2**)a2;
			*(float*)&v8 = **(float**)a2 - *(float*)(a1 + 56);
			v3 = v2->field_4 - *(float*)(a1 + 60);
			v8.field_4 = v3;
			v4 = sqrt(v3 * v8.field_4 + v8.field_0 * v8.field_0);
		}
		v5 = *(float*)(a2 + 4) - v4;
	LABEL_9:
		if (v5 > 0.0)
			(*(void(__cdecl**)(int, _DWORD))(a2 + 8))(a1, *(_DWORD*)(a2 + 12));
	}
}

//----- (00518170) --------------------------------------------------------
void __cdecl sub_518170(int a1, float a2, int a3, int a4) {
	void(__cdecl * v4)(int, int); // ebp
	int v5;                       // ebx
	int v6;                       // edx
	int v7;                       // eax
	double v8;                    // st7
	int v9;                       // ecx
	int v10;                      // edi
	int v11;                      // eax
	int v12;                      // esi
	int v13;                      // ecx
	double v14;                   // st7
	double v15;                   // st6
	float v16;                    // [esp+0h] [ebp-24h]
	float v17;                    // [esp+0h] [ebp-24h]
	float v18;                    // [esp+0h] [ebp-24h]
	float v19;                    // [esp+0h] [ebp-24h]
	int v20;                      // [esp+14h] [ebp-10h]
	int v21;                      // [esp+18h] [ebp-Ch]
	int v22;                      // [esp+1Ch] [ebp-8h]
	int v23;                      // [esp+20h] [ebp-4h]
	int v24;                      // [esp+2Ch] [ebp+8h]
	int v25;                      // [esp+30h] [ebp+Ch]
	int v26;                      // [esp+34h] [ebp+10h]

	v4 = (void(__cdecl*)(int, int))a3;
	if (a3) {
		v16 = *(float*)a1 - a2;
		sub_5175E0(v16, (int)&v22);
		v17 = *(float*)(a1 + 4) - a2;
		sub_5175E0(v17, (int)&v23);
		v18 = a2 + *(float*)a1;
		sub_5175E0(v18, (int)&v20);
		v19 = a2 + *(float*)(a1 + 4);
		sub_5175E0(v19, (int)&v21);
		v5 = v22;
		if (v22 < 0) {
			v22 = 0;
			v5 = 0;
		}
		v6 = v20;
		if (v20 >= *(int*)&dword_5d4594_2386944) {
			v6 = dword_5d4594_2386944 - 1;
			v20 = dword_5d4594_2386944 - 1;
		}
		v7 = v23;
		if (v23 < 0) {
			v7 = 0;
			v23 = 0;
		}
		if (v21 >= *(int*)&dword_5d4594_2386944)
			v21 = dword_5d4594_2386944 - 1;
		v8 = a2 * a2;
		v9 = v7;
		v24 = v7;
		*(float*)&v25 = v8;
		if (v7 <= v21) {
			v10 = a4;
			do {
				if (v5 <= v6) {
					v11 = 16 * v9;
					v26 = 16 * v9;
					do {
						v12 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * v5) +
								 v11);
						if (v12) {
							do {
								v13 = *(_DWORD*)(v12 + 12);
								if (*(_BYTE*)(v13 + 8) & 1) {
									v14 = *(float*)a1 - *(float*)(v13 + 56);
									v15 = *(float*)(a1 + 4) - *(float*)(v13 + 60);
									if (v15 * v15 + v14 * v14 <= *(float*)&v25)
										v4(v13, v10);
								}
								v12 = *(_DWORD*)(v12 + 4);
							} while (v12);
							v11 = v26;
							v6 = v20;
						}
						++v5;
					} while (v5 <= v6);
					v5 = v22;
					v9 = v24;
				}
				v24 = ++v9;
			} while (v9 <= v21);
		}
	}
}

//----- (005182D0) --------------------------------------------------------
void __cdecl sub_5182D0(float* a1, float a2, void(__cdecl* a3)(int, int), int a4) {
	void(__cdecl * v4)(int, int); // ebp
	int v5;                       // ebx
	int v6;                       // edx
	int v7;                       // eax
	double v8;                    // st7
	int v9;                       // ecx
	int v10;                      // edi
	int v11;                      // eax
	int v12;                      // esi
	double v13;                   // st7
	double v14;                   // st6
	float v15;                    // [esp+0h] [ebp-24h]
	float v16;                    // [esp+0h] [ebp-24h]
	float v17;                    // [esp+0h] [ebp-24h]
	float v18;                    // [esp+0h] [ebp-24h]
	int v19;                      // [esp+14h] [ebp-10h]
	int v20;                      // [esp+18h] [ebp-Ch]
	int v21;                      // [esp+1Ch] [ebp-8h]
	int v22;                      // [esp+20h] [ebp-4h]
	int v23;                      // [esp+2Ch] [ebp+8h]
	float v24;                    // [esp+30h] [ebp+Ch]
	int v25;                      // [esp+34h] [ebp+10h]

	v4 = a3;
	if (a3) {
		v15 = *a1 - a2;
		sub_5175E0(v15, (int)&v21);
		v16 = a1[1] - a2;
		sub_5175E0(v16, (int)&v22);
		v17 = a2 + *a1;
		sub_5175E0(v17, (int)&v19);
		v18 = a2 + a1[1];
		sub_5175E0(v18, (int)&v20);
		v5 = v21;
		if (v21 < 0) {
			v21 = 0;
			v5 = 0;
		}
		v6 = v19;
		if (v19 >= *(int*)&dword_5d4594_2386944) {
			v6 = dword_5d4594_2386944 - 1;
			v19 = dword_5d4594_2386944 - 1;
		}
		v7 = v22;
		if (v22 < 0) {
			v7 = 0;
			v22 = 0;
		}
		if (v20 >= *(int*)&dword_5d4594_2386944)
			v20 = dword_5d4594_2386944 - 1;
		v8 = a2 * a2;
		v9 = v7;
		v23 = v7;
		v24 = v8;
		if (v7 <= v20) {
			v10 = a4;
			do {
				if (v5 <= v6) {
					v11 = 16 * v9;
					v25 = 16 * v9;
					do {
						v12 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * v5) +
								 v11 + 8);
						if (v12) {
							do {
								if (*(_BYTE*)(v12 + 480) & 1) {
									v13 = *a1 - *(float*)(v12 + 8);
									v14 = a1[1] - *(float*)(v12 + 12);
									if (v14 * v14 + v13 * v13 <= v24)
										v4(v12, v10);
								}
								v12 = *(_DWORD*)(v12 + 496);
							} while (v12);
							v11 = v25;
							v6 = v19;
						}
						++v5;
					} while (v5 <= v6);
					v5 = v21;
					v9 = v23;
				}
				v23 = ++v9;
			} while (v9 <= v20);
		}
	}
}

//----- (00518440) --------------------------------------------------------
int __cdecl sub_518440(int a1, unsigned __int8 a2) { return sub_518460((float2*)a1, a2, 0); }

//----- (00518460) --------------------------------------------------------
int __cdecl sub_518460(float2* a1, unsigned __int8 a2, int a3) {
	int v3;   // edi
	float v5; // [esp+0h] [ebp-2Ch]
	float v6; // [esp+0h] [ebp-2Ch]
	float v7; // [esp+0h] [ebp-2Ch]
	float v8; // [esp+0h] [ebp-2Ch]
	float v9; // [esp+18h] [ebp-14h]
	int4 v10; // [esp+1Ch] [ebp-10h]

	++*(_DWORD*)&byte_5D4594[2386960];
	*(_DWORD*)&byte_5D4594[2386928] = 1148846080;
	v9 = 0.0;
	v3 = 0;
	do {
		v5 = a1->field_0 - v9;
		sub_5175E0(v5, &v10.field_0);
		v6 = a1->field_4 - v9;
		sub_5175E0(v6, &v10.field_4);
		v7 = v9 + a1->field_0;
		sub_5175E0(v7, &v10.field_8);
		v8 = v9 + a1->field_4;
		sub_5175E0(v8, &v10.field_C);
		*(_DWORD*)&byte_5D4594[2386948] = 0;
		sub_518550(&v10, (int*)a1, a2, a3);
		if (*(_DWORD*)&byte_5D4594[2386948]) {
			v3 = *(_DWORD*)&byte_5D4594[2386948];
			v9 = *(float*)&byte_5D4594[2386928];
		} else {
			if (v3)
				return v3;
			v9 = v9 + 85.0;
		}
	} while (v9 < 1000.0);
	return v3;
}

//----- (00518550) --------------------------------------------------------
int __cdecl sub_518550(int* a1, int* a2, unsigned __int8 a3, int a4) {
	int* v4;         // ebp
	int v5;          // eax
	float v6;        // edx
	int result;      // eax
	int v8;          // ecx
	int v9;          // edx
	int v10;         // ecx
	int v11;         // eax
	int v12;         // esi
	int v13;         // ebx
	int v14;         // edi
	int* v15;        // ebp
	double v16;      // st7
	double v17;      // st6
	long double v18; // st5
	int v19;         // [esp+4h] [ebp-20h]
	int v20;         // [esp+8h] [ebp-1Ch]
	int v21;         // [esp+Ch] [ebp-18h]
	float v22;       // [esp+10h] [ebp-14h]
	float4 v23;      // [esp+14h] [ebp-10h]

	v4 = a1;
	if ((int)*a1 < 0)
		*a1 = 0;
	v5 = dword_5d4594_2386944;
	if (a1[2] >= *(int*)&dword_5d4594_2386944) {
		a1[2] = dword_5d4594_2386944 - 1;
		v5 = dword_5d4594_2386944;
	}
	if (a1[1] < 0) {
		a1[1] = 0;
		v5 = dword_5d4594_2386944;
	}
	if (a1[3] >= v5)
		a1[3] = v5 - 1;
	v6 = *((float*)a2 + 1);
	result = a1[1];
	LODWORD(v23.field_0) = *a2;
	v8 = a1[3];
	v23.field_4 = v6;
	v20 = result;
	if (result <= v8) {
		v9 = 16 * result;
		v21 = 16 * result;
		do {
			v10 = *v4;
			v19 = *v4;
			if (*v4 <= v4[2]) {
				do {
					v11 = v9 + *(_DWORD*)(dword_5d4594_2386940 + 4 * v10);
					if (*(_DWORD*)(v11 + 12) != *(_DWORD*)&byte_5D4594[2386960]) {
						v12 = *(_DWORD*)(v11 + 8);
						if (v12) {
							do {
								if (*(_BYTE*)(v12 + 480) & 1 && sub_579EE0(v12, a3)) {
									if (!a4)
										goto LABEL_35;
									v13 = 0;
									v14 = 0;
									if (*(_BYTE*)(v12 + 476)) {
										v15 = (int*)(v12 + 92);
										do {
											if (*(_BYTE*)(*v15 + 480) & 1 &&
											    sub_579EE0(*v15, a3))
												++v13;
											++v14;
											v15 += 2;
										} while (
										    v14 <
										    *(unsigned __int8*)(v12 + 476));
										v4 = a1;
										if (v13) {
										LABEL_35:
											v16 = *(float*)a2 -
											      *(float*)(v12 + 8);
											v17 = *((float*)a2 + 1) -
											      *(float*)(v12 + 12);
											v18 =
											    sqrt(v17 * v17 + v16 * v16);
											if (v18 < *(float*)&byte_5D4594
												      [2386928]) {
												v23.field_8 =
												    *(float*)(v12 + 8);
												v23.field_C =
												    *(float*)(v12 + 12);
												if (sub_535250(&v23, 0,
													       0, 1)) {
													*(_DWORD*)&byte_5D4594
													    [2386948] =
													    v12;
													v22 = v18;
													*(float*)&byte_5D4594
													    [2386928] =
													    v22;
												}
											}
										}
									}
								}
								v12 = *(_DWORD*)(v12 + 496);
							} while (v12);
							v9 = v21;
							v10 = v19;
						}
						*(_DWORD*)(*(_DWORD*)(dword_5d4594_2386940 + 4 * v10) + v9 +
							   12) = *(_DWORD*)&byte_5D4594[2386960];
					}
					v19 = ++v10;
				} while (v10 <= v4[2]);
				result = v20;
			}
			++result;
			v9 += 16;
			v20 = result;
			v21 = v9;
		} while (result <= v4[3]);
	}
	return result;
}

//----- (00518740) --------------------------------------------------------
int __cdecl sub_518740(float2* a1, unsigned __int8 a2) { return sub_518460(a1, a2, 1); }

//----- (00518760) --------------------------------------------------------
void sub_518760() { nox_srand(0x22F4u); }

//----- (00518770) --------------------------------------------------------
int sub_518770() {
	int result; // eax

	result = sub_4E3AA0((CHAR*)&byte_587000[249176]);
	*(_DWORD*)&byte_5D4594[2386972] = result;
	if (result) {
		result = sub_4E3AA0((CHAR*)&byte_587000[249196]);
		*(_DWORD*)&byte_5D4594[2386976] = result;
		if (result) {
			result = sub_4E3AA0((CHAR*)&byte_587000[249212]);
			*(_DWORD*)&byte_5D4594[2386980] = result;
			if (result) {
				*(_DWORD*)&byte_5D4594[2386984] = sub_4E3AA0((CHAR*)&byte_587000[249220]);
				result = *(_DWORD*)&byte_5D4594[2386984] != 0;
			}
		}
	}
	return result;
}

//----- (005187E0) --------------------------------------------------------
int __cdecl sub_5187E0(int a1, int a2) {
	__int16 v2;   // ax
	float v3;     // ecx
	__int16 v4;   // ax
	float v5;     // edx
	int v6;       // eax
	char v7;      // al
	int2 a2a;     // [esp+4h] [ebp-14h]
	char v10[11]; // [esp+Ch] [ebp-Ch]

	v10[0] = 48;
	*(_WORD*)&v10[3] = *(_WORD*)(a2 + 4);
	v2 = sub_578AC0((_DWORD*)a2);
	v3 = *(float*)(a2 + 56);
	*(_WORD*)&v10[1] = v2;
	v4 = nox_float2int(v3);
	v5 = *(float*)(a2 + 60);
	*(_WORD*)&v10[5] = v4;
	v6 = nox_float2int(v5);
	*(_WORD*)&v10[7] = v6;
	if (*(_BYTE*)(a2 + 8) & 1 && *(_BYTE*)(a2 + 12) & 0x30) {
		LOWORD(v6) = *(_WORD*)(a2 + 124);
		v10[10] = v6 >> 3;
	} else {
		v10[10] = -1;
	}
	sub_509E20(*(__int16*)(a2 + 124), &a2a);
	if ((unsigned __int8)(LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4) <= 3u)
		v7 = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4;
	else
		v7 = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 3;
	v10[9] = 16 * v7;
	return sub_40EF40(a1, v10, 11);
}

//----- (005188A0) --------------------------------------------------------
int __cdecl sub_5188A0(int a1, int a2) {
	__int16* v2; // eax
	int v3;      // ebx
	__int16 v4;  // ax
	__int16 v5;  // cx
	__int16 v6;  // dx
	__int16 v7;  // ax
	float v8;    // ecx
	char v10[9];

	if (*(_DWORD*)(a2 + 8) & 0x20000) {
		v2 = *(__int16**)(a2 + 556);
		if (v2) {
			v3 = *(_DWORD*)(a2 + 748);
			if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a2 + 536)) > 2) {
				v4 = *v2;
				v5 = *(_WORD*)(v3 + 2 * a1 + 96);
				if (v4 != v5) {
					sub_4D8760(a1, *(_DWORD*)(a2 + 36), v4 - v5);
					*(_WORD*)(v3 + 2 * a1 + 96) = **(_WORD**)(a2 + 556);
				}
			}
		}
	}
	v6 = *(_WORD*)(a2 + 4);
	v10[0] = 47;
	*(_WORD*)&v10[3] = v6;
	*(_WORD*)&v10[1] = sub_578AC0((_DWORD*)a2);
	v7 = nox_float2int(*(float*)(a2 + 56));
	v8 = *(float*)(a2 + 60);
	*(_WORD*)&v10[5] = v7;
	*(_WORD*)&v10[7] = nox_float2int(v8);
	return sub_40EF40(a1, v10, 9);
}

//----- (00518960) --------------------------------------------------------
int __cdecl sub_518960(int a1, _DWORD* a2, int a3) {
	int v3;       // ebx
	_DWORD* v4;   // esi
	__int16* v5;  // eax
	int v6;       // edi
	__int16 v7;   // ax
	__int16 v8;   // cx
	__int16 v9;   // dx
	__int16 v10;  // ax
	float v11;    // ecx
	__int16 v12;  // ax
	int v13;      // edi
	char v14;     // al
	char v15;     // al
	int2 a2a;     // [esp+Ch] [ebp-14h]
	char v18[11]; // [esp+14h] [ebp-Ch]

	v3 = a1;
	v4 = a2;
	if (a3) {
		v5 = (__int16*)a2[139];
		if (v5) {
			v6 = a2[187];
			if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - a2[134]) > 2) {
				v7 = *v5;
				v8 = *(_WORD*)(v6 + 2 * a1 + 412);
				if (v7 != v8) {
					sub_4D8760(a1, a2[9], v7 - v8);
					*(_WORD*)(v6 + 2 * v3 + 412) = *(_WORD*)v4[139];
				}
			}
		}
	}
	v9 = *((_WORD*)v4 + 2);
	v18[0] = 48;
	*(_WORD*)&v18[3] = v9;
	*(_WORD*)&v18[1] = sub_578AC0(v4);
	v10 = nox_float2int(*((float*)v4 + 14));
	v11 = *((float*)v4 + 15);
	*(_WORD*)&v18[5] = v10;
	v12 = nox_float2int(v11);
	v13 = v4[187];
	*(_WORD*)&v18[7] = v12;
	v18[9] = sub_533790((int)v4);
	v14 = *((_BYTE*)v4 + 12);
	v18[10] = *(_BYTE*)(v13 + 481);
	if (v14 & 0x10 && *(_BYTE*)(v13 + 2094) && nox_common_randomInt_415FA0(0, 10) >= 8) {
		v18[9] = 14;
		sub_4F9F90(50, &a3, &a1);
		v18[10] = nox_common_randomInt_415FA0(0, a3);
	}
	sub_509E20(*((__int16*)v4 + 62), &a2a);
	LOBYTE(a3) = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4;
	if ((unsigned __int8)a3 <= 3u)
		v15 = a3;
	else
		v15 = a3 - 1;
	v18[9] |= 16 * v15;
	return sub_40EF40(v3, v18, 11);
}

//----- (00518AE0) --------------------------------------------------------
int __cdecl sub_518AE0(int a1, int a2, _DWORD* a3) {
	_DWORD* v3;          // esi
	__int16 v4;          // ax
	int v5;              // ecx
	int v7;              // eax
	char v8;             // dl
	int v9;              // eax
	char v10;            // dl
	unsigned __int8 v11; // cl
	int v12;             // esi
	int v13;             // esi
	unsigned __int8 v14; // al
	char v15;            // dl

	v3 = a3;
	v4 = sub_578AC0(a3);
	v5 = v3[2];
	*(_WORD*)((char*)&a3 + 1) = v4;
	if (v5 & 0x400000 && v3[3] & 0x18) {
		HIBYTE(a3) = *(_BYTE*)v3[187];
		LOBYTE(a3) = -77;
		return sub_4E5390(a2, (int)&a3, 4, 0, 1);
	}
	v7 = *((unsigned __int16*)v3 + 2);
	if ((unsigned __int16)v7 == *(_DWORD*)&byte_5D4594[2386972]) {
		v8 = *(_BYTE*)(v3[187] + 20);
		LOBYTE(a3) = 57;
		HIBYTE(a3) = v8;
		return sub_40EBC0(a2, 1, &a3, 4);
	}
	if (v7 == *(_DWORD*)&byte_5D4594[2386980]) {
		v9 = v3[4];
		LOBYTE(a3) = 57;
		HIBYTE(a3) = ~HIBYTE(v9) & 1;
		return sub_40EBC0(a2, 1, &a3, 4);
	}
	if (v7 == *(_DWORD*)&byte_5D4594[2386976]) {
		v10 = *(_BYTE*)v3[187];
		LOBYTE(a3) = -76;
		HIBYTE(a3) = v10 & 1;
		return sub_40EBC0(a2, 1, &a3, 4);
	}
	if (v5 & 0x4000) {
		v11 = *(_BYTE*)(v3[187] + 16);
		LOBYTE(a3) = 57;
		HIBYTE(a3) = v11 >> 2;
		return sub_40EBC0(a2, 1, &a3, 4);
	}
	if ((v5 & 0x8000) != 0) {
		v12 = v3[187];
		if (v12 && (v13 = *(_DWORD*)(v12 + 4)) != 0) {
			v14 = *(_BYTE*)(*(_DWORD*)(v13 + 748) + 16);
			LOBYTE(a3) = 57;
			HIBYTE(a3) = v14 >> 2;
		} else {
			HIBYTE(a3) = 0;
			LOBYTE(a3) = 57;
		}
		return sub_40EBC0(a2, 1, &a3, 4);
	}
	if ((v5 & 0x80u) != 0) {
		v15 = *(_BYTE*)(v3[187] + 12);
		LOBYTE(a3) = -78;
		HIBYTE(a3) = v15;
		return sub_40EBC0(a2, 1, &a3, 4);
	}
	sub_527E50(a1, v3);
	return 0;
}

//----- (00518C30) --------------------------------------------------------
int __cdecl sub_518C30(int a1, _DWORD* a2, int a3, signed int a4) {
	int v4;         // ebx
	_DWORD* v5;     // esi
	int v6;         // edi
	int v7;         // ebp
	__int16* v8;    // eax
	__int16 v9;     // ax
	__int16 v10;    // cx
	__int16 v11;    // ax
	__int16 v12;    // ax
	float v13;      // ecx
	__int16 v14;    // ax
	float v15;      // edx
	char v16;       // al
	char v17;       // al
	signed int v18; // eax
	char v19;       // al
	int result;     // eax
	int2 a2a;       // [esp+10h] [ebp-14h]
	char v22[12];   // [esp+18h] [ebp-Ch]
	int v23;        // [esp+28h] [ebp+4h]

	v4 = a1;
	v5 = a2;
	v23 = *(_DWORD*)(a1 + 748);
	v6 = a2[187];
	v7 = *(unsigned __int8*)(*(_DWORD*)(v23 + 276) + 2064);
	if (a4) {
		v8 = (__int16*)a2[139];
		if (v8) {
			if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - a2[134]) > 2) {
				v9 = *v8;
				v10 = *(_WORD*)(v6 + 2 * v7 + 12);
				if (v9 != v10) {
					sub_4D8760(v7, a2[9], v9 - v10);
					*(_WORD*)(v6 + 2 * v7 + 12) = *(_WORD*)v5[139];
				}
			}
		}
	}
	if ((_DWORD*)v4 == v5)
		sub_4D9900(v4);
	*(_DWORD*)(*(_DWORD*)(v23 + 276) + 4 * *(unsigned __int8*)(*(_DWORD*)(v6 + 276) + 2064) + 4452) =
	    *(_DWORD*)&byte_5D4594[2598000];
	v11 = *((_WORD*)v5 + 2);
	v22[0] = -61;
	*(_WORD*)&v22[3] = v11;
	v12 = sub_578AC0(v5);
	v13 = *((float*)v5 + 14);
	*(_WORD*)&v22[1] = v12;
	v14 = nox_float2int(v13);
	v15 = *((float*)v5 + 15);
	*(_WORD*)&v22[5] = v14;
	*(_WORD*)&v22[7] = nox_float2int(v15);
	v22[9] = 0;
	v22[11] = nox_common_mapPlrActionToStateId_4FA2B0((int)v5);
	v16 = *(_BYTE*)(v6 + 88);
	if (v16 == 1 || v16 == 10 || v16 == 2 || v16 == 15 || v16 == 16 || v16 == 17 || v16 == 14 || v16 == 20 ||
	    v16 == 18 || v16 == 19 || v16 == 21 || v16 == 22 || v16 == 24 || v16 == 25 || v16 == 27 || v16 == 28 ||
	    v16 == 29 || v16 == 26 || v16 == 30 || v16 == 32) {
		v22[10] = *(_BYTE*)(v6 + 236);
	} else {
		v22[10] = -1;
	}
	if (*(_WORD*)(v6 + 160) && nox_common_randomInt_415FA0(0, 10) >= 8) {
		v22[11] = 50;
		v22[10] = -1;
	}
	v17 = *(_BYTE*)(v6 + 88);
	if ((v17 == 3 || v17 == 4) && v5[131] == 16) {
		v22[11] = 51;
		v22[10] = -1;
	}
	if (*(_BYTE*)(v6 + 88) != 30 && *(_DWORD*)(v6 + 164)) {
		sub_4F9F90(52, &a4, (int*)&a2);
		v18 = (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v6 + 164)) / ((unsigned int)a2 + 1);
		if (v18 >= a4 || (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v6 + 164)) >= 4) {
			*(_DWORD*)(v6 + 164) = 0;
		} else {
			v22[11] = 52;
			v22[10] = v18;
		}
	}
	sub_509E20(*((__int16*)v5 + 62), &a2a);
	LOBYTE(a2) = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4;
	if ((unsigned __int8)a2 <= 3u)
		v19 = (char)a2;
	else
		v19 = (_BYTE)a2 - 1;
	v22[9] |= 16 * v19;
	if (a3)
		result = sub_40EF40(*(unsigned __int8*)(*(_DWORD*)(v23 + 276) + 2064), v22, 12);
	else
		result = sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v23 + 276) + 2064), 1, v22, 12);
	return result;
}

//----- (00518EE0) --------------------------------------------------------
int __cdecl sub_518EE0(_DWORD* a3) {
	_DWORD* v1;  // ebx
	int v2;      // esi
	int v3;      // edi
	int result;  // eax
	int v5;      // eax
	int v6;      // eax
	int v7;      // eax
	int v8;      // eax
	int v9;      // eax
	int v10;     // eax
	int v11;     // eax
	int v12;     // eax
	int v13;     // ebp
	int v14;     // ebx
	int v15;     // eax
	int v16;     // edi
	char v17[3]; // [esp+Ch] [ebp-20h]
	int v18;     // [esp+10h] [ebp-1Ch]
	char v19[5]; // [esp+14h] [ebp-18h]
	float4 a1;   // [esp+1Ch] [ebp-10h]

	v1 = a3;
	v2 = a3[187];
	v3 = *(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064);
	sub_40F020(v3);
	if (v3 != 31 &&
	    !((*(_DWORD*)&byte_5D4594[2598000] + v3) % (unsigned int)(15 * *(_DWORD*)&byte_5D4594[2649704])))
		sub_4D9020(v3, (int)a3);
	if (!dword_5d4594_2650652 || !(*(_DWORD*)&byte_5D4594[2598000] % (unsigned int)sub_40A6C0()) ||
	    nox_common_gameFlags_check_40A5C0(8)) {
		if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 3680) & 0x40) {
			v19[0] = 40;
			*(_DWORD*)&v19[1] = *(_DWORD*)&byte_5D4594[2598000];
			sub_40EF40(v3, v19, 5);
			sub_417530(*(_DWORD*)(v2 + 276), 64);
		} else {
			v17[0] = 39;
			*(_WORD*)&v17[1] = *(_WORD*)&byte_5D4594[2598000];
			sub_40EF40(v3, v17, 3);
		}
	}
	if (!dword_5d4594_2650652 || a3 == *(_DWORD**)&dword_5d4594_3843628 ||
	    nox_common_gameFlags_check_40A5C0(8) || !(*(_DWORD*)&byte_5D4594[2598000] % (unsigned int)sub_40A6C0())) {
		if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 3680) & 3 || *(_DWORD*)&nox_common_engineFlags & 0x400000) {
			result = sub_519330((int)a3);
			if (!result)
				return result;
			if (*(_DWORD*)&nox_common_engineFlags & 0x400000)
				sub_518C30((int)a3, a3, 1, 1);
		} else {
			result = sub_518C30((int)a3, a3, 1, 1);
			if (!result)
				return result;
		}
		v5 = *(_DWORD*)(v2 + 276);
		v18 = *(unsigned __int16*)(v5 + 10);
		a1.field_0 = *(float*)(v5 + 3632) - (double)v18 - 100.0;
		v6 = *(_DWORD*)(v2 + 276);
		v18 = *(unsigned __int16*)(v6 + 12);
		a1.field_4 = *(float*)(v6 + 3636) - (double)v18 - 100.0;
		v7 = *(_DWORD*)(v2 + 276);
		v18 = *(unsigned __int16*)(v7 + 10);
		a1.field_8 = (double)v18 + *(float*)(v7 + 3632) + 100.0;
		v8 = *(_DWORD*)(v2 + 276);
		v18 = *(unsigned __int16*)(v8 + 12);
		a1.field_C = (double)v18 + *(float*)(v8 + 3636) + 100.0;
		sub_517ED0(&a1, sub_5193B0, (int)a3);
		v9 = *(_DWORD*)(v2 + 276);
		v18 = *(unsigned __int16*)(v9 + 10);
		a1.field_0 = *(float*)(v9 + 3632) - (double)v18 - 128.0;
		v10 = *(_DWORD*)(v2 + 276);
		v18 = *(unsigned __int16*)(v10 + 12);
		a1.field_4 = *(float*)(v10 + 3636) - (double)v18 - 128.0;
		v11 = *(_DWORD*)(v2 + 276);
		v18 = *(unsigned __int16*)(v11 + 10);
		a1.field_8 = (double)v18 + *(float*)(v11 + 3632) + 128.0;
		v12 = *(_DWORD*)(v2 + 276);
		v18 = *(unsigned __int16*)(v12 + 12);
		a1.field_C = (double)v18 + *(float*)(v12 + 3636) + 128.0;
		sub_517F00(&a1, sub_519660, (int)a3);
		if (sub_519710(v2))
			sub_519760((int)a3, &a1.field_0);
		if (byte_5D4594[2598000] & 8) {
			v13 = 0;
			v14 = 1 << *(_BYTE*)(*(_DWORD*)(v2 + 276) + 2064);
			v15 = sub_4DA790();
		LABEL_25:
			v16 = v15;
			while (1) {
				if (v16) {
					if (!(*(_DWORD*)(v16 + 8) & 0x20400000) &&
					    !sub_4173D0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v16) &&
					    (*(float*)(v16 + 232) > (double)a1.field_8 ||
					     *(float*)(v16 + 240) < (double)a1.field_0 ||
					     *(float*)(v16 + 236) > (double)a1.field_C ||
					     *(float*)(v16 + 244) < (double)a1.field_4)) {
						if (v14 & *(_DWORD*)(v16 + 148)) {
							sub_528A60(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064),
								   (_DWORD*)v16);
							*(_DWORD*)(v16 + 152) |= v14;
							*(_DWORD*)(v16 + 148) &= ~v14;
						}
					}
					if (v13)
						v15 = sub_4DA850(v16);
					else
						v15 = sub_4DA7A0(v16);
					goto LABEL_25;
				}
				if (v13 == 1)
					break;
				v16 = sub_4DA840();
				v13 = 1;
			}
			v1 = a3;
		}
	}
	if (!dword_5d4594_2650652 || !(*(_DWORD*)&byte_5D4594[2598000] % (unsigned int)sub_40A6C0()) ||
	    nox_common_gameFlags_check_40A5C0(8)) {
		sub_4FF7B0(*(_DWORD*)(v2 + 276));
		sub_511100(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064));
	}
	return sub_501CA0((int)v1);
}

//----- (00519330) --------------------------------------------------------
int __cdecl sub_519330(int a1) {
	int v1;      // esi
	char v3[12]; // [esp+8h] [ebp-Ch]

	v1 = *(_DWORD*)(a1 + 748);
	v3[0] = -61;
	*(_WORD*)&v3[3] = 0;
	*(_WORD*)&v3[1] = 0;
	*(_WORD*)&v3[5] = (__int64)*(float*)(*(_DWORD*)(v1 + 276) + 3632);
	*(_WORD*)&v3[7] = (__int64)*(float*)(*(_DWORD*)(v1 + 276) + 3636);
	v3[9] = 0;
	v3[10] = -1;
	v3[11] = 0;
	return sub_40EF40(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), v3, 12);
}

//----- (005193B0) --------------------------------------------------------
char __cdecl sub_5193B0(_DWORD* a1, int a2) {
	int v2; // ebx
	int v3; // eax

	v2 = *(_DWORD*)(a2 + 748);
	if ((_DWORD*)a2 != a1 || (sub_527E50(a2, a1), v3 = *(_DWORD*)(v2 + 276), *(_BYTE*)(v3 + 3680) & 1)) {
		if (!nox_common_gameFlags_check_40A5C0(0x2000) ||
		    (LOBYTE(v3) = byte_5D4594[2598000], *(_DWORD*)(v2 + 272) != *(_DWORD*)&byte_5D4594[2598000])) {
			LOBYTE(v3) = sub_519410(a2, (int)a1);
		}
	}
	return v3;
}

//----- (00519410) --------------------------------------------------------
char __cdecl sub_519410(int a1, int a2) {
	int v2;     // ebx
	int v3;     // ecx
	int v4;     // eax
	int v5;     // edi
	int v6;     // ebp
	int v7;     // eax
	int v8;     // eax
	float v9;   // ecx
	float v10;  // edx
	int v11;    // eax
	int v13;    // [esp+10h] [ebp-14h]
	float4 v14; // [esp+14h] [ebp-10h]

	v4 = *(_DWORD*)(a1 + 748);
	v13 = v4;
	v2 = 0;
	v3 = *(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064);
	LOBYTE(v4) = *(_BYTE*)(a2 + 16);
	v5 = v3;
	if (!(v4 & 0x20) && !(*(_DWORD*)(a2 + 8) & 0x40000000)) {
		v6 = 1 << v3;
		if (a2 != a1 && v6 & *(_DWORD*)(a2 + 140)) {
			sub_4D97A0(v3, (_DWORD*)a2, (v6 & *(_DWORD*)(a2 + 144)) != 0);
			LOBYTE(v4) = ~(_BYTE)v6;
			*(_DWORD*)(a2 + 140) &= ~v6;
		}
		if (v6 & *(_DWORD*)(a2 + 152) || *(_BYTE*)(a2 + 8) & 1) {
			v7 = *(_DWORD*)(a2 + 16);
			if (!(v7 & 0x800) || sub_4EC4F0(a2, a1) || (v4 = nox_common_gameFlags_check_40A5C0(512)) != 0) {
				v8 = *(_DWORD*)(v13 + 276);
				v14.field_0 = *(float*)(v8 + 3632);
				v9 = *(float*)(a2 + 60);
				v10 = *(float*)(v8 + 3636);
				v14.field_8 = *(float*)(a2 + 56);
				v4 = *(_DWORD*)(a2 + 8);
				v14.field_4 = v10;
				v14.field_C = v9;
				if (v4 & 0x20400000 || (v4 = sub_4173D0(v5, a2)) != 0 ||
				    (v4 = sub_535250(&v14, 0, 0, 69)) != 0) {
					if (v6 & *(_DWORD*)(a2 + 148)) {
						if (*(_BYTE*)(a2 + 20) & 0x20)
							return v4;
					} else if (*(_DWORD*)(a2 + 4 * v5 + 560) & 0xFFF) {
						*(_DWORD*)(a2 + 4 * v5 + 560) |= (*(_DWORD*)(a2 + 4 * v5 + 560) & 0xFFF)
										 << 16;
					}
					v11 = *(_DWORD*)(a2 + 8);
					if (v11 & 0x400000) {
						v2 = sub_518AE0(a1, v5, (_DWORD*)a2);
					} else if (v11 & 0x200000) {
						if (v11 & 2) {
							v2 = sub_518960(v5, (_DWORD*)a2, 1);
						} else if (v11 & 4) {
							v2 = sub_518C30(a1, (_DWORD*)a2, 1, 1);
						} else {
							v2 = sub_5187E0(v5, a2);
						}
					} else if (v11 & 0x100000) {
						v2 = sub_5188A0(v5, a2);
					} else {
						*(_DWORD*)(a2 + 152) = 0;
					}
					LOBYTE(v4) = sub_527E50(a1, (_DWORD*)a2);
					if (v2) {
						v4 = v6 | *(_DWORD*)(a2 + 148);
						*(_DWORD*)(a2 + 152) &= ~v6;
						*(_DWORD*)(a2 + 148) = v4;
					}
				} else if (v6 & *(_DWORD*)(a2 + 148)) {
					if (*(_BYTE*)(a2 + 8) & 6)
						sub_528A60(v5, (_DWORD*)a2);
					else
						sub_528A90(v5, (_DWORD*)a2);
					v4 = ~v6 & *(_DWORD*)(a2 + 148);
					*(_DWORD*)(a2 + 152) |= v6;
					*(_DWORD*)(a2 + 148) = v4;
				}
			}
		}
	}
	return v4;
}

//----- (00519660) --------------------------------------------------------
int __cdecl sub_519660(int a1, int a2) {
	int v2;     // esi
	int result; // eax
	int v4;     // ebx
	int v5;     // [esp-4h] [ebp-10h]

	v2 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) + 2064);
	result = (v2 & *(_DWORD*)(a1 + 28)) != 0;
	switch (*(unsigned __int8*)(a1 + 21)) {
	case 1u:
	case 4u:
		v4 = 0;
		break;
	case 2u:
	case 3u:
		v4 = 1;
		break;
	default:
		v4 = a2;
		break;
	}
	if (result != v4) {
		v5 = nox_server_getWallAtPoint_410580(*(_DWORD*)(a1 + 4), *(_DWORD*)(a1 + 8));
		if (v4) {
			sub_4DF120(v5);
			result = v2 | *(_DWORD*)(a1 + 28);
		} else {
			sub_4DF180(v5);
			result = ~v2 & *(_DWORD*)(a1 + 28);
		}
		*(_DWORD*)(a1 + 28) = result;
	}
	return result;
}

//----- (00519710) --------------------------------------------------------
int __cdecl sub_519710(int a1) {
	int result; // eax

	result = sub_417270(*(unsigned __int8*)(*(_DWORD*)(a1 + 276) + 2064));
	if (result)
		result =
		    result > 60 || *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 268) > (unsigned int)(60 / result);
	return result;
}

//----- (00519760) --------------------------------------------------------
void __cdecl sub_519760(int a1, float* a2) {
	int v2; // ebp
	int v3; // edi
	int v4; // eax
	int v5; // esi

	v2 = *(_DWORD*)(a1 + 748);
	v3 = *(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064);
	v4 = sub_4172C0(v3);
	v5 = v4;
	if (v4) {
		if (*(_BYTE*)(v4 + 16) & 0x20) {
			sub_417430(v4);
		} else if (*(float*)(v4 + 56) < (double)*a2 || *(float*)(v4 + 56) > (double)a2[2] ||
			   *(float*)(v4 + 60) < (double)a2[1] || *(float*)(v4 + 60) > (double)a2[3]) {
			*(_DWORD*)(v4 + 152) |= 1 << v3;
			sub_519410(a1, v4);
			sub_4D9020(v3, v5);
			*(_DWORD*)(v2 + 268) = *(_DWORD*)&byte_5D4594[2598000];
		}
	}
}

//----- (00519820) --------------------------------------------------------
void sub_519820() { nox_srand(0x22F5u); }

//----- (00519830) --------------------------------------------------------
int __cdecl sub_519830(int a1, char a2) {
	int result; // eax

	result = a1;
	if (a1) {
		*(_DWORD*)(a1 + 40) = 0;
		*(_BYTE*)a1 = a2;
		*(_WORD*)(a1 + 2) = 0;
		*(_WORD*)(a1 + 4) = 0;
		*(_DWORD*)(a1 + 8) = 0;
		*(_DWORD*)(a1 + 12) = 0;
		*(_DWORD*)(a1 + 16) = 1;
		*(_WORD*)(a1 + 20) = 512;
		*(_DWORD*)(a1 + 24) = 0;
		*(_BYTE*)(a1 + 28) = 2;
		*(_DWORD*)(a1 + 32) = 0;
		*(_DWORD*)(a1 + 44) = 0;
	}
	return result;
}

//----- (00519870) --------------------------------------------------------
int sub_519870() {
	char v0;             // di
	unsigned __int8* v1; // esi
	int result;          // eax

	v0 = 0;
	v1 = &byte_5D4594[2387148];
	*(_WORD*)&byte_5D4594[2388636] = 0;
	*(_WORD*)&byte_5D4594[2388638] = 0;
	dword_5d4594_2388640 = 0;
	dword_5d4594_2388648 = 0;
	do {
		result = sub_519830((int)v1, v0);
		v1 += 48;
		++v0;
	} while ((int)v1 < (int)&byte_5D4594[2388636]);
	return result;
}

//----- (005198B0) --------------------------------------------------------
void __cdecl sub_5198B0(unsigned __int8 a1) {
	char v1;             // bl
	unsigned __int8* v2; // esi

	v1 = 0;
	v2 = &byte_5D4594[2387150];
	do {
		if (*(_WORD*)v2 == 1) {
			*(_WORD*)v2 = 0;
			nullsub_27(v2 - 2);
			sub_519C80_net_mapsend(v2 - 2, a1);
			++*(_WORD*)&byte_5D4594[2388638];
			if (*((_WORD*)v2 + 1) == 1) {
				if (*(_DWORD*)(v2 + 6))
					free(*(LPVOID*)(v2 + 6));
			}
			sub_519830((int)(v2 - 2), v1);
		}
		v2 += 48;
		++v1;
	} while ((int)v2 < (int)&byte_5D4594[2388638]);
}
// 519920: using guessed type void __cdecl nullsub_27(_DWORD);

//----- (00519930) --------------------------------------------------------
int __cdecl sub_519930(int a1) {
	int v1;              // edi
	unsigned __int8* v2; // esi
	char* i;             // eax
	char v4;             // al
	int v6;              // [esp+8h] [ebp-4h]

	v1 = 0;
	v6 = 0;
	v2 = &byte_5D4594[48 * a1 + 2387148];
	if (v2) {
		if (a1 < 32) {
			for (i = (char*)sub_555250(*v2, &v6); i; i = (char*)sub_555290(*v2, &v6)) {
				v4 = *i;
				if (v4 == -72 || v4 == -71)
					++v1;
			}
		}
	}
	return v1;
}

//----- (00519E80) --------------------------------------------------------
_DWORD* __cdecl sub_519E80(int a1) {
	sub_417090(a1);
	return sub_4DE410(byte_5D4594[48 * a1 + 2387148]);
}

//----- (0051A100) --------------------------------------------------------
LPVOID sub_51A100() {
	LPVOID result; // eax

	if (dword_5d4594_2388648)
		sub_5198B0(0);
	result = *(LPVOID*)&dword_5d4594_2388640;
	if (dword_5d4594_2388640)
		free(*(LPVOID*)&dword_5d4594_2388640);
	*(_DWORD*)&byte_5D4594[2388644] = 0;
	return result;
}

//----- (0051A130) --------------------------------------------------------
int sub_51A130() { return dword_5d4594_2388648; }

//----- (0051A140) --------------------------------------------------------
BOOL __cdecl sub_51A140(int a1) {
	unsigned __int8* v1; // eax

	v1 = &byte_5D4594[48 * a1 + 2387148];
	return v1 && a1 < 32 && *((_WORD*)v1 + 1) == 1;
}

//----- (0051A170) --------------------------------------------------------
int __cdecl sub_51A170(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	if (!a1)
		return -1;
	v1 = 0;
	v2 = (const char**)&byte_587000[249880];
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)&byte_587000[249892])
			return -1;
	}
	return v1;
}

//----- (0051A1D0) --------------------------------------------------------
char* __cdecl sub_51A1D0(int a1) {
	char* result; // eax

	if (a1 <= -1 || a1 >= 3)
		result = 0;
	else
		result = *(char**)&byte_587000[4 * a1 + 249880];
	return result;
}

//----- (0051A500) --------------------------------------------------------
int __cdecl sub_51A500(int a1) {
	int v1;             // ecx
	int v2;             // edx
	unsigned __int8* i; // eax
	int v4;             // esi

	if (!*(_DWORD*)&byte_5D4594[2388664])
		sub_51A550();
	if (!a1)
		return 0;
	v1 = 0;
	if (!*(_DWORD*)&byte_587000[249904])
		return 0;
	HIWORD(v2) = 0;
	for (i = &byte_587000[249904];; i += 16) {
		LOWORD(v2) = *(_WORD*)(a1 + 4);
		if (*((_DWORD*)i - 1) == v2)
			break;
		v4 = *((_DWORD*)i + 4);
		++v1;
		if (!v4)
			return 0;
	}
	return *(_DWORD*)&byte_587000[16 * v1 + 249908];
}

//----- (0051A550) --------------------------------------------------------
CHAR* sub_51A550() {
	CHAR* result;        // eax
	unsigned __int8* v1; // esi

	result = *(CHAR**)&byte_587000[249904];
	if (*(_DWORD*)&byte_587000[249904]) {
		v1 = &byte_587000[249896];
		do {
			*((_DWORD*)v1 + 3) = sub_4E3AA0(result);
			*((_DWORD*)v1 + 1) = sub_4E3AA0(*(CHAR**)v1);
			result = (CHAR*)*((_DWORD*)v1 + 6);
			v1 += 16;
		} while (result);
		*(_DWORD*)&byte_5D4594[2388664] = 1;
	} else {
		*(_DWORD*)&byte_5D4594[2388664] = 1;
	}
	return result;
}

//----- (0051A5A0) --------------------------------------------------------
void __cdecl sub_51A5A0(int* a1) {
	_DWORD* v1;  // edi
	_DWORD* v2;  // esi
	int v3;      // eax
	int v4;      // eax
	double v5;   // st7
	int v6;      // eax
	_DWORD* v7;  // esi
	int v8;      // eax
	_DWORD* v9;  // eax
	int v10;     // eax
	_DWORD* v11; // eax
	int v12;     // eax
	_DWORD* v13; // eax
	int v14;     // eax
	_DWORD* v15; // eax
	float v16;   // [esp+8h] [ebp-8h]
	float v17;   // [esp+Ch] [ebp-4h]

	v1 = sub_4E3810((CHAR*)&byte_587000[252796]);
	v16 = sub_4E40F0();
	if (v1) {
		v2 = (_DWORD*)v1[187];
		v3 = v2[121];
		if (v3)
			v4 = *(_DWORD*)(v3 + 72);
		else
			v4 = *(unsigned __int16*)(*(_DWORD*)(sub_4E3B70(*((unsigned __int16*)v1 + 2)) + 136) + 4);
		if (v16 < 1.0)
			v16 = 1.0;
		v5 = (double)v4 * v16;
		v17 = v5;
		sub_4E4560((int)v1, (__int64)v5);
		*(_WORD*)(v1[139] + 4) = nox_float2int(v17);
		if (!*(_WORD*)v1[139])
			sub_4E4560((int)v1, 1u);
		v6 = v1[139];
		if (!*(_WORD*)(v6 + 4))
			*(_WORD*)(v6 + 4) = 1;
		v2[411] = 0x10000000;
		v2[423] = 0x10000000;
		v2[340] = 4;
		v2[326] = 1062501089;
		v2[510] = 3;
		v2[410] = 0x8000000;
		v2[444] = 0x20000000;
		v2[388] = 0x40000000;
		v2[415] = 0x40000000;
		sub_419D40(&byte_587000[252804]);
		v2[330] = 1062836634;
		sub_4DAA50((int)v1, 0, *(float*)a1, *((float*)a1 + 1));
		v7 = sub_4E3810((CHAR*)&byte_587000[252824]);
		if (v7) {
			v8 = sub_4E3CC0();
			v9 = nox_server_rewardgen_activateMarker_4F0720((int)v7, v8 + 2);
			if (v9)
				sub_4F3070((int)v1, (int)v9, 0);
			v10 = sub_4E3CC0();
			v11 = nox_server_rewardgen_activateMarker_4F0720((int)v7, v10 + 2);
			if (v11)
				sub_4F3070((int)v1, (int)v11, 0);
			v12 = sub_4E3CC0();
			v13 = nox_server_rewardgen_activateMarker_4F0720((int)v7, v12 + 2);
			if (v13)
				sub_4F3070((int)v1, (int)v13, 0);
			v14 = sub_4E3CC0();
			v15 = nox_server_rewardgen_activateMarker_4F0720((int)v7, v14 + 2);
			if (v15)
				sub_4F3070((int)v1, (int)v15, 0);
			sub_4E38A0((int)v7);
		}
	}
}

//----- (0051A7A0) --------------------------------------------------------
void __cdecl sub_51A7A0(int* a1) {
	_DWORD* v1; // edi
	_DWORD* v2; // esi
	int v3;     // eax
	int v4;     // eax
	double v5;  // st7
	int v6;     // eax
	_DWORD* v7; // esi
	int v8;     // eax
	_DWORD* v9; // eax
	float v10;  // [esp+8h] [ebp-8h]
	float v11;  // [esp+Ch] [ebp-4h]

	v1 = sub_4E3810((CHAR*)&byte_587000[252840]);
	v10 = sub_4E40F0();
	if (v1) {
		v2 = (_DWORD*)v1[187];
		v3 = v2[121];
		if (v3)
			v4 = *(_DWORD*)(v3 + 72);
		else
			v4 = *(unsigned __int16*)(*(_DWORD*)(sub_4E3B70(*((unsigned __int16*)v1 + 2)) + 136) + 4);
		if (v10 < 1.0)
			v10 = 1.0;
		v5 = (double)v4 * v10;
		v11 = v5;
		sub_4E4560((int)v1, (__int64)v5);
		*(_WORD*)(v1[139] + 4) = nox_float2int(v11);
		if (!*(_WORD*)v1[139])
			sub_4E4560((int)v1, 1u);
		v6 = v1[139];
		if (!*(_WORD*)(v6 + 4))
			*(_WORD*)(v6 + 4) = 1;
		v2[340] = 4;
		v2[411] = 0x10000000;
		v2[423] = 0x10000000;
		v2[326] = 1062501089;
		v2[510] = 1;
		v2[410] = 0x8000000;
		v2[444] = 0x20000000;
		v2[415] = 0x40000000;
		sub_4DAA50((int)v1, 0, *(float*)a1, *((float*)a1 + 1));
		v7 = sub_4E3810((CHAR*)&byte_587000[252852]);
		if (v7) {
			v8 = sub_4E3CC0();
			v9 = nox_server_rewardgen_activateMarker_4F0720((int)v7, v8 + 2);
			if (v9)
				sub_4F3070((int)v1, (int)v9, 0);
			sub_4E38A0((int)v7);
		}
	}
}

//----- (0051A930) --------------------------------------------------------
int sub_51A930() { return *(_DWORD*)&byte_5D4594[2388660]; }

//----- (0051A940) --------------------------------------------------------
int __cdecl sub_51A940(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[2388656] = a1;
	return result;
}

//----- (0051A950) --------------------------------------------------------
int sub_51A950() { return *(_DWORD*)&byte_5D4594[2388656]; }

//----- (0051A960) --------------------------------------------------------
int __cdecl sub_51A960(int a1, unsigned __int8* a2) {
	char* v2;      // eax
	int v3;        // esi
	int v5;        // eax
	int v6;        // edx
	int v7;        // [esp+Ch] [ebp-C04h]
	char v8[3072]; // [esp+10h] [ebp-C00h]

	v2 = sub_417090(a1);
	v3 = *a2;
	v7 = *a2;
	if (v2 && !(v2[3680] & 0x10))
		return v3 + 1;
	v5 = sub_51AAA0((int)(a2 + 1), v3, (int)v8);
	v6 = *(_DWORD*)&byte_5D4594[4 * a1 + 2388804];
	if (v6 + v5 < 128) {
		*(_DWORD*)&byte_5D4594[4 * a1 + 2388804] = v6 + v5;
		qmemcpy(&byte_5D4594[24 * (v6 + (a1 << 7)) + 2388932], v8, 24 * v5);
		v3 = v7;
	}
	sub_51AA20(a1);
	return v3 + 1;
}

//----- (0051AA20) --------------------------------------------------------
int __cdecl sub_51AA20(int a1) {
	int v1;              // esi
	int v2;              // edi
	int v3;              // edx
	int result;          // eax
	int v5;              // ebx
	unsigned __int8* v6; // ecx

	v1 = 0;
	v2 = 0;
	v3 = 0;
	result = *(_DWORD*)&byte_5D4594[4 * a1 + 2388804] - 1;
	if (result >= 0) {
		v5 = *(_DWORD*)&byte_5D4594[4 * a1 + 2388804];
		v6 = &byte_5D4594[24 * (result + (a1 << 7)) + 2388948];
		do {
			if (*(_DWORD*)v6) {
				result = *((_DWORD*)v6 - 2) - 2;
				if (*((_DWORD*)v6 - 2) == 2) {
					if (v3)
						*(_DWORD*)v6 = 0;
					else
						v3 = 1;
				} else {
					result = *((_DWORD*)v6 - 2) - 4;
					if (*((_DWORD*)v6 - 2) == 4) {
						if (v1)
							*(_DWORD*)v6 = 0;
						else
							v1 = 1;
					} else {
						result = *((_DWORD*)v6 - 2) - 5;
						if (*((_DWORD*)v6 - 2) == 5) {
							if (v2)
								*(_DWORD*)v6 = 0;
							else
								v2 = 1;
						}
					}
				}
			}
			v6 -= 24;
			--v5;
		} while (v5);
	}
	return result;
}

//----- (0051AAA0) --------------------------------------------------------
int __cdecl sub_51AAA0(int a1, int a2, int a3) {
	int v3;             // edi
	int v4;             // ebp
	_DWORD* v5;         // ebx
	int v6;             // ecx
	unsigned __int8 v7; // al
	int v9;             // [esp+8h] [ebp-4h]

	v3 = 0;
	v4 = 0;
	v9 = 0;
	if (a2 <= 0)
		return 0;
	v5 = (_DWORD*)(a3 + 12);
	do {
		v6 = *(unsigned __int8*)(a1 + v4);
		v4 += 4;
		*(v5 - 1) = v6;
		if (sub_42D440(v6)) {
			v7 = sub_42D450(*(v5 - 1));
			*v5 = 0;
			qmemcpy(v5, (const void*)(v4 + a1), v7);
			v4 += v7;
			v3 = v9;
		} else {
			*v5 = 0;
		}
		v5[1] = 1;
		++v3;
		v5 += 6;
		v9 = v3;
	} while (v4 < a2);
	return v3;
}

//----- (0051AB50) --------------------------------------------------------
unsigned __int8* __cdecl sub_51AB50(int a1) {
	int v1; // esi
	int v2; // edx

	*(_DWORD*)&byte_5D4594[4 * a1 + 2388676] = 0;
	if (*(int*)&byte_5D4594[4 * a1 + 2388804] <= 0)
		return 0;
	v1 = a1 << 7;
	while (1) {
		v2 = *(_DWORD*)&byte_5D4594[4 * a1 + 2388676];
		if (*(_DWORD*)&byte_5D4594[24 * (v1 + v2) + 2388948])
			break;
		*(_DWORD*)&byte_5D4594[4 * a1 + 2388676] = v2 + 1;
		if (v2 + 1 >= *(int*)&byte_5D4594[4 * a1 + 2388804])
			return 0;
	}
	return &byte_5D4594[24 * (v1 + *(_DWORD*)&byte_5D4594[4 * a1 + 2388676]) + 2388932];
}

//----- (0051ABC0) --------------------------------------------------------
unsigned __int8* __cdecl sub_51ABC0(int a1) {
	int v1; // esi
	int v2; // eax
	int v3; // esi

	v1 = *(_DWORD*)&byte_5D4594[4 * a1 + 2388676] + 1;
	*(_DWORD*)&byte_5D4594[4 * a1 + 2388676] = v1;
	v2 = v1;
	if (v1 >= *(int*)&byte_5D4594[4 * a1 + 2388804])
		return 0;
	v3 = a1 << 7;
	while (!*(_DWORD*)&byte_5D4594[24 * (v3 + v2) + 2388948]) {
		*(_DWORD*)&byte_5D4594[4 * a1 + 2388676] = ++v2;
		if (v2 >= *(int*)&byte_5D4594[4 * a1 + 2388804])
			return 0;
	}
	return &byte_5D4594[24 * (v3 + *(_DWORD*)&byte_5D4594[4 * a1 + 2388676]) + 2388932];
}

//----- (0051AC30) --------------------------------------------------------
int __cdecl sub_51AC30(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[4 * a1 + 2388804] = 0;
	return result;
}

//----- (0051AC40) --------------------------------------------------------
BOOL __cdecl sub_51AC40(int a1) { return *(_DWORD*)&byte_5D4594[4 * a1 + 2388804] == 0; }

//----- (0051AC60) --------------------------------------------------------
void sub_51AC60() {
	int v0; // ecx
	int i;  // eax

	v0 = dword_5d4594_2487236;
	if (dword_5d4594_2487236) {
		for (i = *(_DWORD*)(dword_5d4594_2487236 + 24); i; i = *(_DWORD*)(i + 24))
			v0 = i;
		*(_DWORD*)(v0 + 24) = dword_5d4594_2487240;
		dword_5d4594_2487240 = dword_5d4594_2487236;
		dword_5d4594_2487236 = 0;
	}
}

//----- (0051ACA0) --------------------------------------------------------
int __cdecl sub_51ACA0(int a1, int a2, int a3) {
	_DWORD* v3; // esi
	int result; // eax
	int v5;     // eax
	int i;      // ecx

	v3 = sub_51AD40();
	if (!v3)
		return sub_507230(0);
	*v3 = a1 + *(_DWORD*)&byte_5D4594[2598000];
	v3[1] = a2;
	v3[2] = a3;
	v5 = sub_51AD20();
	v3[3] = v5;
	v3[4] = 0;
	v3[5] = 0;
	v3[6] = 0;
	sub_507230(v5);
	result = dword_5d4594_2487236;
	if (dword_5d4594_2487236) {
		for (i = *(_DWORD*)(dword_5d4594_2487236 + 24); i; i = *(_DWORD*)(i + 24))
			result = i;
		*(_DWORD*)(result + 24) = v3;
		v3[7] = result;
	} else {
		dword_5d4594_2487236 = v3;
		v3[7] = 0;
	}
	return result;
}

//----- (0051AD20) --------------------------------------------------------
int sub_51AD20() {
	int result; // eax

	result = ++*(_DWORD*)&byte_587000[252868];
	if (*(_DWORD*)&byte_587000[252868] > 0x7D00u) {
		result = 1;
		*(_DWORD*)&byte_587000[252868] = 1;
	}
	return result;
}

//----- (0051AD40) --------------------------------------------------------
void* sub_51AD40() {
	void* result; // eax

	result = *(void**)&dword_5d4594_2487240;
	if (!dword_5d4594_2487240)
		return nox_malloc(0x20u);
	dword_5d4594_2487240 = *(_DWORD*)(dword_5d4594_2487240 + 24);
	return result;
}

//----- (0051AD60) --------------------------------------------------------
int __cdecl sub_51AD60(int a1) {
	int v1; // eax

	v1 = dword_5d4594_2487236;
	if (!dword_5d4594_2487236)
		return 0;
	while (*(_DWORD*)(v1 + 12) != a1) {
		v1 = *(_DWORD*)(v1 + 24);
		if (!v1)
			return 0;
	}
	sub_51AD90(v1);
	return 1;
}

//----- (0051AD90) --------------------------------------------------------
int __cdecl sub_51AD90(int a1) {
	int v1;     // edx
	_DWORD* v2; // ecx
	int v3;     // esi
	int result; // eax

	v1 = *(_DWORD*)(a1 + 24);
	v2 = (_DWORD*)(a1 + 24);
	if (v1)
		*(_DWORD*)(v1 + 28) = *(_DWORD*)(a1 + 28);
	v3 = *(_DWORD*)(a1 + 28);
	if (v3)
		*(_DWORD*)(v3 + 24) = *v2;
	if (a1 == dword_5d4594_2487236)
		dword_5d4594_2487236 = *v2;
	result = *v2;
	*v2 = dword_5d4594_2487240;
	dword_5d4594_2487240 = a1;
	*(_DWORD*)(a1 + 28) = 0;
	return result;
}

//----- (0051AE60) --------------------------------------------------------
_DWORD* __cdecl sub_51AE60(int a1) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_2487236;
	if (dword_5d4594_2487236) {
		do {
			if (result[4] == a1) {
				result = (_DWORD*)sub_51AD90((int)result);
			} else {
				if (result[5] == a1)
					result[5] = 0;
				result = (_DWORD*)result[6];
			}
		} while (result);
	}
	return result;
}

//----- (0051AEA0) --------------------------------------------------------
int sub_51AEA0() {
	int v0; // eax
	int j;  // esi
	int v2; // eax
	int v3; // eax
	int v5; // [esp+8h] [ebp-Ch]
	int i;  // [esp+Ch] [ebp-8h]
	int v7; // [esp+10h] [ebp-4h]

	v7 = 1;
	sub_426AC0_file3_fread(&v7, 2u);
	sub_426AC0_file3_fread(&byte_5D4594[2598000], 4u);
	v0 = dword_5d4594_2487236;
	for (i = 0; v0; v0 = *(_DWORD*)(v0 + 24))
		++i;
	sub_426AC0_file3_fread(&i, 4u);
	for (j = dword_5d4594_2487236; j; j = *(_DWORD*)(j + 24)) {
		sub_426AC0_file3_fread((_BYTE*)j, 4u);
		sub_426AC0_file3_fread((_BYTE*)(j + 4), 4u);
		sub_426AC0_file3_fread((_BYTE*)(j + 8), 4u);
		v2 = *(_DWORD*)(j + 16);
		if (v2)
			v5 = *(_DWORD*)(v2 + 44);
		else
			v5 = 0;
		sub_426AC0_file3_fread(&v5, 4u);
		v3 = *(_DWORD*)(j + 20);
		if (v3)
			v5 = *(_DWORD*)(v3 + 44);
		else
			v5 = 0;
		sub_426AC0_file3_fread(&v5, 4u);
	}
	return 1;
}

//----- (0051AF80) --------------------------------------------------------
int sub_51AF80() {
	int v0;          // ebx
	_DWORD* v1;      // eax
	_DWORD* v2;      // esi
	int v3;          // eax
	int i;           // ecx
	int v6;          // [esp+Ch] [ebp-20h]
	unsigned int v7; // [esp+10h] [ebp-1Ch]
	int v8;          // [esp+14h] [ebp-18h]
	int v9;          // [esp+18h] [ebp-14h]
	int v10;         // [esp+1Ch] [ebp-10h]
	int v11;         // [esp+20h] [ebp-Ch]
	int v12;         // [esp+24h] [ebp-8h]
	int v13;         // [esp+28h] [ebp-4h]

	v6 = 1;
	sub_426AC0_file3_fread(&v6, 2u);
	if ((__int16)v6 <= 1 && (__int16)v6 > 0) {
		sub_426AC0_file3_fread(&v8, 4u);
		sub_426AC0_file3_fread(&v7, 4u);
		v0 = 0;
		if (v7 <= 0)
			return 1;
		while (1) {
			sub_426AC0_file3_fread(&v9, 4u);
			sub_426AC0_file3_fread(&v10, 4u);
			sub_426AC0_file3_fread(&v11, 4u);
			sub_426AC0_file3_fread(&v12, 4u);
			sub_426AC0_file3_fread(&v13, 4u);
			v1 = sub_51AD40();
			v2 = v1;
			if (!v1)
				break;
			*v1 = v9 + *(_DWORD*)&byte_5D4594[2598000] - v8;
			v1[1] = v10;
			v1[2] = v11;
			v1[3] = sub_51AD20();
			v2[4] = 0;
			v2[5] = 0;
			v2[4] = v12;
			v2[5] = v13;
			v2[6] = 0;
			v3 = dword_5d4594_2487236;
			if (dword_5d4594_2487236) {
				for (i = *(_DWORD*)(dword_5d4594_2487236 + 24); i; i = *(_DWORD*)(i + 24))
					v3 = i;
				*(_DWORD*)(v3 + 24) = v2;
				v2[7] = v3;
			} else {
				dword_5d4594_2487236 = v2;
				v2[7] = 0;
			}
			if (++v0 >= v7)
				return 1;
		}
	}
	return 0;
}

//----- (0051B0C0) --------------------------------------------------------
void sub_51B0C0() {
	int* v0; // esi

	v0 = *(int**)&dword_5d4594_2487236;
	if (dword_5d4594_2487236) {
		do {
			if (v0[4])
				v0[4] = nox_server_scriptValToObjectPtr_511B60(v0[4]);
			if (v0[5])
				v0[5] = nox_server_scriptValToObjectPtr_511B60(v0[5]);
			v0 = (int*)v0[6];
		} while (v0);
	}
}

//----- (0051B810) --------------------------------------------------------
int __cdecl sub_51B810(int a1) {
	float* v1; // eax
	double v2; // st7
	int v3;    // edx
	double v4; // st7
	int v6;    // [esp-4h] [ebp-4h]
	float v7;  // [esp+4h] [ebp+4h]

	v1 = (float*)a1;
	v6 = a1;
	v2 = *(float*)(a1 + 88) + *(float*)(a1 + 80);
	v3 = *(_DWORD*)(a1 + 68);
	*(_DWORD*)(a1 + 56) = *(_DWORD*)(a1 + 64);
	*(_DWORD*)(a1 + 60) = v3;
	v4 = v2 * *(float*)(a1 + 112);
	*(float*)(a1 + 80) = v4;
	v7 = (v1[23] + v1[21]) * v1[28];
	v1[21] = v7;
	v1[16] = v4 + v1[16];
	v1[17] = v7 + v1[17];
	return sub_4E7290(v6);
}

//----- (0051B860) --------------------------------------------------------
char __cdecl sub_51B860(int a1) { return sub_537610(a1); }

//----- (0051B870) --------------------------------------------------------
void __cdecl sub_51B870(int a1) {
	int v1;         // esi
	int v2;         // ecx
	double v3;      // st7
	double v4;      // st7
	double v5;      // st7
	double v6;      // st6
	long double v7; // st6
	double v8;      // st7
	double v9;      // st7
	float v10;      // [esp+0h] [ebp-14h]
	float v11;      // [esp+0h] [ebp-14h]
	float v12;      // [esp+0h] [ebp-14h]
	float v13;      // [esp+10h] [ebp-4h]
	int v14;        // [esp+18h] [ebp+4h]

	v1 = a1;
	v2 = *(_DWORD*)(a1 + 16);
	v3 = *(float*)(a1 + 104);
	if (v2 & 0x40000) {
		v10 = v3 + *(float*)(a1 + 108);
		sub_4E46F0(a1, v10);
		v4 = *(float*)(a1 + 108) - 1.0;
		*(_DWORD*)(a1 + 88) = 0;
		*(_DWORD*)(a1 + 92) = 0;
		*(_DWORD*)(a1 + 80) = 0;
		*(_DWORD*)(a1 + 84) = 0;
		*(float*)(a1 + 108) = v4;
		v5 = *(float*)(a1 + 56) - *(float*)(a1 + 156);
		v6 = *(float*)(a1 + 60) - *(float*)(a1 + 160);
		v13 = v6;
		v7 = sqrt(v6 * v13 + v5 * v5);
		*(float*)&v14 = v7;
		if (v7 > 0.0) {
			*(float*)(v1 + 88) = v5 * -3.0 / *(float*)&v14;
			*(float*)(v1 + 92) = v13 * -3.0 / *(float*)&v14;
		}
		if (*(float*)(v1 + 104) < -50.0) {
			sub_4E46F0(v1, 90.0);
			*(_DWORD*)(v1 + 16) &= 0xFFFBFFFF;
			sub_4E7010(v1, (float2*)(v1 + 164));
		}
	} else if (v3 != 0.0 || *(float*)(a1 + 108) != 0.0) {
		if (0x800000 & v2) {
			v11 = *(float*)(a1 + 104) + *(float*)(a1 + 108);
			sub_4E46F0(a1, v11);
			if (*(float*)(a1 + 104) >= 0.0) {
				*(float*)(a1 + 108) = *(float*)(a1 + 108) - 0.5;
			} else {
				sub_4E46F0(a1, 0.0);
				v8 = -*(float*)(a1 + 108) * *(float*)(a1 + 116) * 0.1;
				*(float*)(a1 + 108) = v8;
				if (v8 < 2.0) {
					sub_4E46F0(a1, 0.0);
					*(_DWORD*)(a1 + 108) = 0;
				}
			}
		} else if (!(v2 & 0x100000)) {
			if (*(float*)(a1 + 104) > 0.0) {
				if (*(float*)(a1 + 108) <= 0.0)
					*(_DWORD*)(a1 + 16) = v2 | 0x20000;
				v12 = *(float*)(a1 + 104) + *(float*)(a1 + 108);
				sub_4E46F0(a1, v12);
				*(float*)(a1 + 108) = *(float*)(a1 + 108) - 1.0;
			}
			if (*(float*)(a1 + 104) <= 0.0) {
				v9 = *(float*)(a1 + 108);
				*(_DWORD*)(a1 + 16) &= 0xFFFDFFFF;
				if (v9 < 0.0 && !(*(_BYTE*)(a1 + 8) & 1)) {
					sub_537610(a1);
					if (*(float*)(a1 + 108) < -10.0) {
						if (*(_BYTE*)(a1 + 8) & 4)
							sub_501960(280, a1, 0, 0);
					}
				}
				sub_4E46F0(a1, 0.0);
				*(_DWORD*)(a1 + 108) = 0;
			}
		}
	}
}

//----- (0051BAC0) --------------------------------------------------------
void sub_51BAC0() { nox_srand(0x2308u); }

//----- (0051D0D0) --------------------------------------------------------
void sub_51D0D0() { nox_srand(0x2309u); }

//----- (0051D0E0) --------------------------------------------------------
void sub_51D0E0() { *(_DWORD*)&byte_5D4594[2487244] = 0; }

//----- (0051D0F0) --------------------------------------------------------
int __cdecl sub_51D0F0(char a1) {
	byte_5D4594[3835400] = a1;
	return 1;
}

//----- (0051D100) --------------------------------------------------------
int __cdecl sub_51D100(int a1) {
	if (a1 != 1 && a1)
		return 0;
	*(_DWORD*)&byte_5D4594[3835404] = a1;
	return 1;
}

//----- (0051D120) --------------------------------------------------------
_DWORD* __cdecl sub_51D120(float* a1) {
	_DWORD* result; // eax
	_DWORD* v2;     // esi
	float2 v3;      // [esp+4h] [ebp-8h]

	result = (float*)sub_4D3D90((float2*)a1, &v3);
	if (result) {
		result = sub_5798F0(v3.field_0, v3.field_4);
		v2 = result;
		if (result) {
			if (*(_DWORD*)&byte_5D4594[2487244]) {
				if (*(_DWORD*)&byte_5D4594[3835404] == 1) {
					sub_51D300(*(int*)&byte_5D4594[2487244], (int)result, byte_5D4594[3835400]);
					sub_51D300((int)v2, *(int*)&byte_5D4594[2487244], byte_5D4594[3835400]);
				}
			}
			*(_DWORD*)&byte_5D4594[2487244] = v2;
			result = v2;
		}
	}
	return result;
}

//----- (0051D1A0) --------------------------------------------------------
float* __cdecl sub_51D1A0(float2* a1) {
	float* result; // eax
	float2 a2;     // [esp+0h] [ebp-8h]

	result = (float*)sub_4D3D90(a1, &a2);
	if (result)
		result = sub_579AD0(a2.field_0, a2.field_4);
	return result;
}

//----- (0051D1E0) --------------------------------------------------------
int __cdecl sub_51D1E0(LPVOID lpMem) {
	LPVOID v1; // eax
	char* i;   // esi
	int v4;    // ebx
	char* v5;  // edi

	if (!lpMem)
		return 0;
	v1 = sub_579860();
	if (!v1)
		return 0;
	while (v1 != lpMem) {
		v1 = (LPVOID)sub_579870((int)v1);
		if (!v1)
			return 0;
	}
	for (i = (char*)sub_579860(); i; i = (char*)sub_579870((int)i)) {
		v4 = 0;
		if (i[476]) {
			v5 = i + 96;
			do {
				if (*((LPVOID*)v5 - 1) == lpMem)
					sub_51D370((int)i, (int)lpMem, *v5);
				++v4;
				v5 += 8;
			} while (v4 < (unsigned __int8)i[476]);
		}
	}
	sub_579B30(lpMem);
	return 1;
}

//----- (0051D270) --------------------------------------------------------
float* __cdecl sub_51D270(float* a1) {
	float* result; // eax
	float2 v2;     // [esp+0h] [ebp-8h]

	result = (float*)sub_4D3D90((float2*)a1, &v2);
	if (result) {
		result = sub_579AD0(v2.field_0, v2.field_0);
		if (result)
			result = (float*)sub_51D1E0(result);
	}
	return result;
}

//----- (0051D2C0) --------------------------------------------------------
int __cdecl sub_51D2C0(int a1, int a2) { return sub_51D300(a1, a2, byte_5D4594[3835400]); }

//----- (0051D2E0) --------------------------------------------------------
int __cdecl sub_51D2E0(int a1, int a2) { return sub_51D370(a1, a2, byte_5D4594[3835400]); }

//----- (0051D300) --------------------------------------------------------
int __cdecl sub_51D300(int a1, int a2, char a3) {
	unsigned __int8 v3; // al
	int v4;             // ecx
	int v5;             // esi
	_BYTE* v6;          // eax

	v3 = *(_BYTE*)(a1 + 476);
	if (v3 >= 0x1Fu || a1 == a2)
		return 0;
	v4 = 0;
	v5 = v3;
	if ((int)v3 > 0) {
		v6 = (_BYTE*)(a1 + 96);
		do {
			if (*((_DWORD*)v6 - 1) == a2 && *v6 == a3)
				break;
			++v4;
			v6 += 8;
		} while (v4 < v5);
	}
	if (v4 != v5)
		return 0;
	*(_DWORD*)(a1 + 8 * v5 + 92) = a2;
	*(_BYTE*)(a1 + 8 * (unsigned __int8)(*(_BYTE*)(a1 + 476))++ + 96) = a3;
	return 1;
}

//----- (0051D370) --------------------------------------------------------
int __cdecl sub_51D370(int a1, int a2, char a3) {
	int v3;     // eax
	int v4;     // esi
	_BYTE* i;   // ecx
	int v7;     // ecx
	_DWORD* v8; // eax

	if (a1 == a2)
		return 0;
	v3 = 0;
	v4 = *(unsigned __int8*)(a1 + 476);
	if (v4 <= 0)
		return 0;
	for (i = (_BYTE*)(a1 + 96); *((_DWORD*)i - 1) != a2 || *i != a3; i += 8) {
		if (++v3 >= v4)
			return 0;
	}
	v7 = v3;
	if (v3 < v4 - 1) {
		v8 = (_DWORD*)(a1 + 8 * v3 + 92);
		do {
			++v7;
			*v8 = v8[2];
			v8[1] = v8[3];
			v8 += 2;
		} while (v7 < *(unsigned __int8*)(a1 + 476) - 1);
	}
	--*(_BYTE*)(a1 + 476);
	return 1;
}

//----- (0051D3F0) --------------------------------------------------------
float2* __cdecl sub_51D3F0(float2* a1, float2* a2) {
	float2* result; // eax
	float2* v3;     // esi

	result = a1;
	if (a1) {
		if (a2) {
			result = (float2*)sub_51D1A0(a1);
			v3 = result;
			if (result) {
				result = (float2*)sub_51D1A0(a2);
				if (result)
					result = (float2*)sub_51D2C0((int)v3, (int)result);
			}
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (0051D440) --------------------------------------------------------
float* __cdecl sub_51D440(float* a1, float* a2) {
	float* result; // eax
	float* v3;     // esi

	result = a1;
	if (a1) {
		if (a2) {
			result = sub_51D1A0((float2*)a1);
			v3 = result;
			if (result) {
				result = sub_51D1A0((float2*)a2);
				if (result)
					result = (float*)sub_51D2E0((int)v3, (int)result);
			}
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (0051D490) --------------------------------------------------------
int __cdecl sub_51D490(char* a1) {
	int v1;         // edi
	const char* v2; // esi

	if (!a1)
		return -1;
	v1 = 0;
	v2 = (const char*)&byte_5D4594[2682188];
	while (_strcmpi(v2, a1)) {
		v2 += 60;
		++v1;
		if ((int)v2 >= (int)&byte_5D4594[2692748])
			return -1;
	}
	return v1;
}

//----- (0051D4D0) --------------------------------------------------------
int __cdecl sub_51D4D0(char* a1) {
	int v1;         // ebx
	int v2;         // edi
	const char* v3; // esi

	v1 = 0;
	v2 = 0;
	v3 = (const char*)&byte_5D4594[2682188];
	do {
		if (!_strcmpi(v3, a1)) {
			v1 = 1;
			*(_DWORD*)&byte_5D4594[3835340] = v2;
		}
		v3 += 60;
		++v2;
	} while ((int)v3 < (int)&byte_5D4594[2692748]);
	if (!_strcmpi(a1, "NONE")) {
		*(_DWORD*)&byte_5D4594[3835340] = 255;
		return 1;
	}
	if (v1)
		return 1;
	*(_DWORD*)&byte_5D4594[3835340] = 0;
	return 0;
}

//----- (0051D540) --------------------------------------------------------
int __cdecl sub_51D540(int a1) {
	int result; // eax

	if (a1 < 0 || a1 >= 176) {
		*(_DWORD*)&byte_5D4594[3835340] = 0;
		result = 0;
	} else {
		*(_DWORD*)&byte_5D4594[3835340] = a1;
		result = 1;
	}
	return result;
}

//----- (0051D570) --------------------------------------------------------
int __cdecl sub_51D570(int a1) {
	int result; // eax

	if (a1 <= byte_5D4594[60 * *(_DWORD*)&byte_5D4594[3835340] + 2682240] *
			  byte_5D4594[60 * *(_DWORD*)&byte_5D4594[3835340] + 2682241] -
		      1) {
		dword_5d4594_3835348 = a1;
		result = 1;
	} else {
		dword_5d4594_3835348 = 0;
		result = 0;
	}
	return result;
}

//----- (0051D5C0) --------------------------------------------------------
int __cdecl sub_51D5C0(int a1) {
	if (a1 != 1 && a1)
		return 0;
	*(_DWORD*)&byte_5D4594[3835344] = a1;
	return 1;
}

//----- (0051D5E0) --------------------------------------------------------
float* __cdecl sub_51D5E0(float* a1) {
	float* result; // eax
	float2 v2;     // [esp+0h] [ebp-8h]

	result = a1;
	if (a1) {
		if (*(_DWORD*)&byte_5D4594[3835340] == 255 ||
		    (sub_4D3D90((float2*)a1, &v2), (result = (float*)sub_51D8F0(&v2)) != 0) &&
			(*(_DWORD*)&byte_5D4594[3835364] != 1 || (result = (float*)sub_527380(&v2.field_0)) != 0)) {
			result = (float*)1;
		}
	}
	return result;
}

//----- (0051D650) --------------------------------------------------------
float* __cdecl sub_51D650(float* a1) {
	float* v1;     // esi
	char v3[0x48]; // [esp+8h] [ebp-48h]

	qmemcpy(v3, sub_4D3C70(), 0x48u);
	sub_51D4D0((char*)&byte_587000[253096]);
	v1 = sub_51D5E0(a1);
	sub_4D3C50(v3);
	return v1;
}

//----- (0051D6A0) --------------------------------------------------------
int __cdecl sub_51D6A0(int a1) {
	int result;    // eax
	char v2[0x48]; // [esp+8h] [ebp-48h]

	if (!a1)
		return 0;
	if (!*(_DWORD*)a1)
		return 0;
	qmemcpy(v2, sub_4D3C70(), 0x48u);
	sub_51D4D0((char*)&byte_587000[253104]);
	result = sub_51D8F0((float2*)(a1 + 4));
	if (result) {
		if (*(_DWORD*)&byte_5D4594[3835364] != 1 || (result = sub_527380((float*)(a1 + 4))) != 0) {
			sub_4D3C50(v2);
			*(_DWORD*)(a1 + 4) = 0;
			*(_DWORD*)a1 = 0;
			*(_DWORD*)(a1 + 8) = 0;
			result = 1;
		}
	}
	return result;
}

//----- (0051D740) --------------------------------------------------------
int __cdecl sub_51D740(float* a1, int a2) {
	double v2;  // st7
	double v3;  // st6
	int v4;     // ebx
	int v5;     // esi
	int v6;     // ebp
	int v7;     // edx
	int v8;     // edx
	float v9;   // ecx
	int result; // eax
	int v11;    // eax
	float v12;  // edx
	int v13;    // eax
	float v14;  // edx
	float2 v15; // [esp+10h] [ebp-8h]
	float v17;  // [esp+1Ch] [ebp+4h]

	if (!sub_4D3D90((float2*)a1, &v15))
		return 0;
	if (!a2)
		return 0;
	v2 = v15.field_0 + 11.5;
	v3 = v15.field_4 + 11.5;
	v4 = (__int64)(v2 * 0.021739131);
	v17 = v3;
	v5 = (__int64)(v3 * 0.021739131);
	v6 = (int)(__int64)v2 % 46;
	v7 = (__int64)v17 % 46;
	if (v4 - 1 <= 0 || v4 >= 127 || v5 - 1 <= 0 || v5 >= 127)
		return 0;
	if (v6 <= v7) {
		if (46 - v6 > v7) {
			v8 = (_DWORD)(ptr_5D4594_2650668[v4 - 1]) + 44 * v5 + 24;
			goto LABEL_10;
		}
		v13 = (_DWORD)(ptr_5D4594_2650668[v4]) + 44 * v5 + 24;
		v14 = v15.field_4;
		*(float*)(a2 + 4) = v15.field_0;
		*(_DWORD*)a2 = v13;
		*(float*)(a2 + 8) = v14;
		result = 1;
	} else {
		if (46 - v6 > v7) {
			v8 = (_DWORD)(ptr_5D4594_2650668[v4]) + 44 * v5 - 20;
		LABEL_10:
			v9 = v15.field_4;
			*(float*)(a2 + 4) = v15.field_0;
			*(_DWORD*)a2 = v8;
			*(float*)(a2 + 8) = v9;
			return 1;
		}
		v11 = (_DWORD)(ptr_5D4594_2650668[v4]) + 44 * v5 + 4;
		v12 = v15.field_4;
		*(float*)(a2 + 4) = v15.field_0;
		*(_DWORD*)a2 = v11;
		*(float*)(a2 + 8) = v12;
		result = 1;
	}
	return result;
}

//----- (0051D8B0) --------------------------------------------------------
int __cdecl sub_51D8B0(int a1) {
	if (!a1)
		return -1;
	if (*(_DWORD*)a1)
		return **(_DWORD**)a1;
	return -1;
}

//----- (0051D8D0) --------------------------------------------------------
int __cdecl sub_51D8D0(int a1) {
	if (!a1)
		return -1;
	if (*(_DWORD*)a1)
		return *(_DWORD*)(*(_DWORD*)a1 + 4);
	return -1;
}

//----- (0051D8F0) --------------------------------------------------------
int __cdecl sub_51D8F0(float2* a1) {
	double v1;  // st7
	double v2;  // st6
	int v3;     // esi
	int v4;     // edi
	int v5;     // ebp
	int v6;     // edx
	int result; // eax
	int v8;     // [esp+10h] [ebp-20h]
	int v9;     // [esp+14h] [ebp-1Ch]
	int v10;    // [esp+18h] [ebp-18h]
	int v11;    // [esp+1Ch] [ebp-14h]
	int v12;    // [esp+20h] [ebp-10h]
	char v13;   // [esp+24h] [ebp-Ch]
	int v14;    // [esp+28h] [ebp-8h]
	int v15;    // [esp+2Ch] [ebp-4h]
	float v16;  // [esp+34h] [ebp+4h]

	v9 = dword_5d4594_3835348;
	v1 = a1->field_0 + 11.5;
	v8 = *(_DWORD*)&byte_5D4594[3835340];
	v10 = 0;
	v13 = 0;
	v11 = -1;
	v12 = -1;
	v14 = 255;
	v15 = 0;
	v2 = a1->field_4 + 11.5;
	v3 = (__int64)(v1 * 0.021739131);
	v16 = v2;
	v4 = (__int64)(v2 * 0.021739131);
	v5 = (int)(__int64)v1 % 46;
	v6 = (__int64)v16 % 46;
	if (*(_DWORD*)&byte_5D4594[3835340] == 255)
		result = sub_51D9C0(v3, v4, v5, v6, 0);
	else
		result = sub_51D9C0(v3, v4, v5, v6, (int)&v8);
	return result;
}

//----- (0051D9C0) --------------------------------------------------------
int __cdecl sub_51D9C0(int a1, int a2, int a3, int a4, int a5) {
	int result; // eax

	if (a1 - 1 <= 0 || a1 >= 127 || a2 - 1 <= 0 || a2 >= 127)
		return 0;
	if (a3 <= a4) {
		if (46 - a3 <= a4)
			result = sub_51DA70(a1, a2, a5, 2, 0);
		else
			result = sub_51DA70(a1 - 1, a2, a5, 1, 0);
	} else if (46 - a3 <= a4) {
		result = sub_51DA70(a1, a2, a5, 1, 0);
	} else {
		result = sub_51DA70(a1, a2 - 1, a5, 2, 0);
	}
	return result;
}
