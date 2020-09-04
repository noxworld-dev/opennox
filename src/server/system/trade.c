#include "../dbase/objdb.h"

#include "../../proto.h"
extern _DWORD dword_5d4594_2386552;
extern _DWORD dword_5d4594_2386548;
extern _DWORD dword_5d4594_2386560;
extern void* nox_alloc_tradeItems_2386496;

//----- (0050E7A0) --------------------------------------------------------
int __cdecl sub_50E7A0(_DWORD* a1, int a2) {
	int* v2; // esi
	int v4;  // eax
	int v5;  // eax
	int v6;  // eax

	v2 = (int*)a1[5];
	if (!v2)
		return 0;
	while (*v2 != a2) {
		v2 = (int*)v2[2];
		if (!v2)
			return 0;
	}
	v4 = v2[2];
	if (v4)
		*(_DWORD*)(v4 + 12) = v2[3];
	v5 = v2[3];
	if (v5)
		*(_DWORD*)(v5 + 8) = v2[2];
	if (v2 == (int*)a1[5])
		a1[5] = v2[2];
	v6 = a1[2];
	if (!(*(_BYTE*)(v6 + 8) & 4))
		v6 = a1[3];
	sub_50E820(v6, *v2);
	sub_414330(*(unsigned int**)&nox_alloc_tradeItems_2386496, v2);
	return 1;
}

//----- (0050E8F0) --------------------------------------------------------
_DWORD* __cdecl sub_50E8F0(int a1, int a2) {
	int v2;         // ebx
	int v3;         // eax
	_DWORD* v4;     // esi
	_DWORD* result; // eax

	v2 = 0;
	if (nox_common_gameFlags_check_40A5C0(4096) &&
		(v3 = *(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064),
		 v4 = *(_DWORD**)getMemAt(0x5D4594, 4 * v3 + 2386364), *(_DWORD*)getMemAt(0x5D4594, 4 * v3 + 2386364) = 0, v4)) {
		v2 = 1;
	} else {
		result = sub_50E870();
		v4 = result;
		if (!result)
			return result;
	}
	v4[2] = a1;
	v4[3] = a2;
	v4[4] = 1;
	if (!v2)
		sub_50E970((int)v4);
	return v4;
}

//----- (0050F0F0) --------------------------------------------------------
int __cdecl sub_50F0F0(int a1, int a2) {
	int v2;      // ebx
	int v3;      // ebp
	wchar_t* v4; // eax
	char v6[86]; // [esp+10h] [ebp-58h]

	*(_WORD*)v6 = 3529;
	v2 = *(_DWORD*)(a2 + 8);
	if (*(_BYTE*)(v2 + 8) & 4) {
		v3 = *(_DWORD*)(a2 + 8);
		v2 = *(_DWORD*)(a2 + 12);
	} else {
		v3 = *(_DWORD*)(a2 + 12);
	}
	v4 = sub_4E39F0_obj_db((const char**)v2);
	nox_wcsncpy((wchar_t*)&v6[4], v4, 0x18u);
	*(_WORD*)&v6[52] = 0;
	strcpy(&v6[54], (const char*)(*(_DWORD*)(v2 + 692) + 1684));
	*(_WORD*)&v6[2] = *(_WORD*)(v2 + 4);
	return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(v3 + 748) + 276) + 2064), (int)v6, 86, 0, 1);
}

//----- (0050F1A0) --------------------------------------------------------
int __cdecl sub_50F1A0(int a1, int a2) {
	int v2;      // eax
	int v3;      // esi
	int v4;      // edx
	wchar_t* v6; // [esp-8h] [ebp-40h]
	char v8[52]; // [esp+4h] [ebp-34h]

	*(_WORD*)v8 = 3273;
	v2 = *(_DWORD*)(a2 + 8);
	v3 = *(_DWORD*)(a1 + 748);
	if (a1 != v2) {
		if (*(_BYTE*)(v2 + 8) & 4) {
			nox_wcscpy((wchar_t*)&v8[2], (const wchar_t*)(*(_DWORD*)(*(_DWORD*)(v2 + 748) + 276) + 4704));
			return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (int)v8, 52, 0, 1);
		}
		v6 = sub_4E39F0_obj_db(*(const char***)(a2 + 12));
	} else {
		v4 = *(_DWORD *) (a2 + 12);
		if (*(_BYTE *) (v4 + 8) & 4) {
			nox_wcscpy((wchar_t *) &v8[2], (const wchar_t *) (*(_DWORD *) (*(_DWORD *) (v4 + 748) + 276) + 4704));
			return sub_4E5390(*(unsigned __int8 *) (*(_DWORD *) (v3 + 276) + 2064), (int) v8, 52, 0, 1);
		}
		v6 = sub_4E39F0_obj_db((const char **) v4);
	}
	nox_wcsncpy((wchar_t *) &v8[2], v6, 0x18u);
	*(_WORD*)&v8[50] = 0;
	return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (int)v8, 52, 0, 1);
}

//----- (0050F280) --------------------------------------------------------
int __cdecl sub_50F280(int a1, int a2) {
	int result; // eax
	_DWORD* i;  // esi

	result = a2;
	for (i = *(_DWORD**)(a2 + 20); i; i = (_DWORD*)i[2])
		result = sub_50F2B0(a1, i);
	return result;
}

//----- (0050F370) --------------------------------------------------------
_DWORD* __cdecl sub_50F370(_DWORD* a1, int a2) {
	_DWORD* result; // eax

	result = a1;
	*a1 = 1;
	if (*(_BYTE*)(a2 + 8) & 4)
		*(_DWORD*)(*(_DWORD*)(a2 + 748) + 280) = a1;
	return result;
}

//----- (0050FAE0) --------------------------------------------------------
int __cdecl sub_50FAE0(int a1, int a2, int a3, int a4, int a5) {
	int v5;       // esi
	__int16 v6;   // dx
	int v7;       // ecx
	int v8;       // edx
	int i;        // eax
	char v11[15]; // [esp+4h] [ebp-10h]

	v5 = *(_DWORD*)(a1 + 748);
	v11[0] = -55;
	v11[2] = a1 == a2;
	v11[1] = 4;
	v6 = *(_WORD*)(a4 + 36);
	*(_WORD*)&v11[3] = *(_WORD*)(a4 + 4);
	*(_DWORD*)&v11[7] = a5;
	v7 = *(_DWORD*)(a4 + 8);
	*(_WORD*)&v11[5] = v6;
	if (v7 & 0x13001000) {
		v8 = *(_DWORD*)(a4 + 692);
		for (i = 0; i < 4; ++i) {
			if (*(_DWORD*)v8)
				v11[i + 11] = *(_BYTE*)(*(_DWORD*)v8 + 4);
			else
				v11[i + 11] = -1;
			v8 += 4;
		}
	} else {
		*(_DWORD*)&v11[11] = -1;
	}
	return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (int)v11, 15, 0, 1);
}

//----- (0050FD60) --------------------------------------------------------
BOOL __cdecl sub_50FD60(_DWORD* a1, int a2) {
	_DWORD* v2;      // esi
	unsigned int v3; // edi
	unsigned int v4; // ecx
	int v5;          // eax
	int* v6;         // edx
	int v7;          // ecx
	int v8;          // eax
	int v9;          // edx
	int* i;          // ecx
	int v12[4];      // [esp+8h] [ebp-20h]
	int v13[4];      // [esp+18h] [ebp-10h]

	v13[0] = 0;
	v12[0] = 0;
	v2 = a1;
	v13[1] = 0;
	v12[1] = 0;
	v3 = 0;
	v13[2] = 0;
	v12[2] = 0;
	v13[3] = 0;
	for (v12[3] = 0; v2; v2 = (_DWORD*)v2[2]) {
		v4 = 0;
		v5 = *(unsigned __int16*)(*v2 + 4);
		v6 = v13;
		while (*v6 != v5) {
			++v4;
			++v6;
			if (v4 >= 4) {
				v7 = v12[v3];
				v13[v3] = v5;
				v12[v3++] = v7 + 1;
				goto LABEL_6;
			}
		}
		++v12[v4];
	LABEL_6:;
	}
	v8 = 0;
	if (!v3)
		return 1;
	HIWORD(v9) = 0;
	for (i = v13;; ++i) {
		LOWORD(v9) = *(_WORD*)(a2 + 4);
		if (*i == v9 && !(*(_DWORD*)(a2 + 8) & 0x13001000))
			break;
		if (++v8 >= v3)
			return v3 < 4;
	}
	return 1;
}

//----- (00510320) --------------------------------------------------------
void __cdecl sub_510320(int a1, int a2) {
	int v2;    // ecx
	_BYTE* v3; // ebp
	int v4;    // eax
	int v5;    // esi
	char v6;   // cl
	int v7;    // edx
	int v8;    // eax

	if (a1 && a2) {
		v2 = *(_DWORD*)(a2 + 8);
		if (*(_BYTE*)(v2 + 8) & 4)
			v2 = *(_DWORD*)(a2 + 12);
		v3 = *(_BYTE**)(v2 + 692);
		v4 = sub_5103A0(a2, a1);
		if (v4 != -1) {
			v5 = (int)&v3[28 * v4];
			v6 = v3[28 * v4 + 8] - 1;
			*(_BYTE*)(v5 + 8) = v6;
			if (!v6) {
				v7 = v4;
				if (v4 < (unsigned __int8)*v3 - 1) {
					v8 = v5 + 4;
					do {
						++v7;
						memcpy((void*)v8, (const void*)(v8 + 28), 0x1Cu);
						v8 += 28;
					} while (v7 < (unsigned __int8)*v3 - 1);
				}
				--*v3;
			}
		}
	}
}

//----- (005104F0) --------------------------------------------------------
int __cdecl sub_5104F0(int a1, __int16 a2) {
	int v2;     // eax
	char v4[4]; // [esp+0h] [ebp-4h]

	*(_WORD*)&v4[2] = a2;
	v2 = *(_DWORD*)(a1 + 748);
	v4[0] = -55;
	v4[1] = 27;
	return sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v4, 4, 0, 1);
}

//----- (00510540) --------------------------------------------------------
int __cdecl sub_510540(int a1) {
	if (!nox_common_gameFlags_check_40A5C0(4096))
		return 1;
	if (!*(_DWORD*)getMemAt(0x5D4594, 2386520)) {
		*(_DWORD*)getMemAt(0x5D4594, 2386520) = sub_4E3AA0((CHAR*)getMemAt(0x587000, 236324));
		*(_DWORD*)getMemAt(0x5D4594, 2386528) = sub_4E3AA0((CHAR*)getMemAt(0x587000, 236332));
		*(_DWORD*)getMemAt(0x5D4594, 2386524) = sub_4E3AA0((CHAR*)getMemAt(0x587000, 236340));
		*(_DWORD*)getMemAt(0x5D4594, 2386532) = sub_4E3AA0((CHAR*)getMemAt(0x587000, 236348));
	}
	int v1 = *(unsigned __int16*)(a1 + 4);
	if ((unsigned __int16)v1 == *(_DWORD*)getMemAt(0x5D4594, 2386520) || v1 == *(_DWORD*)getMemAt(0x5D4594, 2386524) ||
		v1 == *(_DWORD*)getMemAt(0x5D4594, 2386528) || v1 == *(_DWORD*)getMemAt(0x5D4594, 2386532)) {
		return 0;
	}
	return 1;
}

//----- (005105D0) --------------------------------------------------------
BOOL __cdecl sub_5105D0(int a1) {
	int v1; // eax

	if (!*(_DWORD*)getMemAt(0x5D4594, 2386536)) {
		*(_DWORD*)getMemAt(0x5D4594, 2386536) = sub_4E3AA0((CHAR*)getMemAt(0x587000, 236364));
		*(_DWORD*)getMemAt(0x5D4594, 2386544) = sub_4E3AA0((CHAR*)getMemAt(0x587000, 236372));
		*(_DWORD*)getMemAt(0x5D4594, 2386540) = sub_4E3AA0((CHAR*)getMemAt(0x587000, 236380));
	}
	v1 = *(unsigned __int16*)(a1 + 4);
	return (unsigned __int16)v1 == *(_DWORD*)getMemAt(0x5D4594, 2386536) || v1 == *(_DWORD*)getMemAt(0x5D4594, 2386540) ||
		   v1 == *(_DWORD*)getMemAt(0x5D4594, 2386544);
}

//----- (0050EF10) --------------------------------------------------------
_DWORD* __cdecl sub_50EF10_trade(int a1, int a2) {
	int v2;           // edx
	int v3;           // eax
	wchar_t* v4;      // eax
	int v6;           // ecx
	int v7;           // eax
	wchar_t* v8;      // eax
	_DWORD* v9;       // esi
	char v10;         // al
	int v11;          // eax
	int v12;          // eax
	int v13;          // [esp-4h] [ebp-114h]
	wchar_t v14[128]; // [esp+10h] [ebp-100h]

	v2 = *(_DWORD*)(a1 + 8) & 4;
	if (v2) {
		v3 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 280);
		if (v3) {
			if (*(_DWORD*)(v3 + 12) != a2) {
				v4 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 235924), 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c",
										   1836);
				sub_4D9EB0(a1, v4);
			}
			return 0;
		}
	}
	v6 = *(_DWORD*)(a2 + 8) & 4;
	if (v6) {
		v7 = *(_DWORD*)(a2 + 748);
		if (*(_DWORD*)(v7 + 280)) {
			if (v2) {
				v13 = *(_DWORD*)(v7 + 276) + 4704;
				v8 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 235988), 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c",
										   1878);
				nox_swprintf(v14, v8, v13);
				sub_4D9EB0(a1, v14);
			}
			return 0;
		}
	}
	if (v2) {
		if (!v6) {
			v9 = sub_50E8F0(a1, a2);
			goto LABEL_18;
		}
	} else if (!v6) {
		goto LABEL_17;
	}
	if (!v2) {
		v9 = sub_50E8F0(a2, a1);
		goto LABEL_18;
	}
LABEL_17:
	v9 = sub_50E870();
	v9[2] = a1;
	v9[3] = a2;
LABEL_18:
	if (!v9)
		return 0;
	v9[1] = *(_DWORD*)getMemAt(0x5D4594, 2598000);
	sub_50F370(v9, a1);
	sub_50F370(v9, a2);
	v10 = *(_BYTE*)(a1 + 8);
	if (v9[4]) {
		if (v10 & 4)
			sub_50F0F0(a1, (int)v9);
		if (*(_BYTE*)(a2 + 8) & 4)
			sub_50F0F0(a2, (int)v9);
	} else {
		if (v10 & 4)
			sub_50F1A0(a1, (int)v9);
		if (*(_BYTE*)(a2 + 8) & 4)
			sub_50F1A0(a2, (int)v9);
	}
	if (v9[4]) {
		v11 = v9[2];
		if (*(_BYTE*)(v11 + 8) & 4)
			sub_50F280(v11, (int)v9);
		else
			sub_50F280(v9[3], (int)v9);
		if (v9[4] && nox_common_gameFlags_check_40A5C0(2048)) {
			v12 = v9[2];
			if (!(*(_BYTE*)(v12 + 8) & 4))
				v12 = v9[3];
			sub_4E79C0(v12, 0);
		}
	}
	return v9;
}

//----- (0050F820) --------------------------------------------------------
int __cdecl sub_50F820_trade(int a1, int a2, float a3) {
	float v3;    // ebx
	int result;  // eax
	int* v5;     // eax
	int* v6;     // edi
	wchar_t* v7; // eax
	wchar_t* v8; // eax
	int v9;      // eax
	int v10;     // eax
	int v11;     // eax
	int v12;     // eax

	if (!*(_DWORD*)getMemAt(0x5D4594, 2386516))
		*(_DWORD*)getMemAt(0x5D4594, 2386516) = sub_4E3AA0((CHAR*)getMemAt(0x587000, 236008));
	if (*(_DWORD*)(a1 + 8) == a2) {
		v3 = a3;
		if (!sub_50FD60(*(_DWORD**)(a1 + 32), SLODWORD(a3)))
			return 0;
	} else {
		if (*(_DWORD*)(a1 + 12) != a2)
			return 0;
		v3 = a3;
		if (!sub_50FD60(*(_DWORD**)(a1 + 36), SLODWORD(a3)))
			return 0;
	}
	v5 = (int*)nox_alloc_class_new_obj_zero(*(_DWORD**)&nox_alloc_tradeItems_2386496);
	v6 = v5;
	if (v5) {
		*(float*)v5 = v3;
		v5[2] = 0;
		v5[3] = 0;
		v5[1] = sub_50E3D0(1, a1, v3);
		if (*(_DWORD*)(a1 + 8) == a2) {
			v6[2] = *(_DWORD*)(a1 + 32);
			v9 = *(_DWORD*)(a1 + 32);
			if (v9)
				*(_DWORD*)(v9 + 12) = v6;
			*(_DWORD*)(a1 + 32) = v6;
		} else {
			v6[2] = *(_DWORD*)(a1 + 36);
			v10 = *(_DWORD*)(a1 + 36);
			if (v10)
				*(_DWORD*)(v10 + 12) = v6;
			*(_DWORD*)(a1 + 36) = v6;
		}
		sub_50FB90((_DWORD*)a1);
		v11 = *(_DWORD*)(a1 + 8);
		*(_DWORD*)(a1 + 24) = 0;
		*(_DWORD*)(a1 + 28) = 0;
		if (*(_BYTE*)(v11 + 8) & 4) {
			if (!(*(_BYTE*)(*(_DWORD*)(a1 + 12) + 8) & 4) && *(_DWORD*)(a1 + 44) <= *(int*)(a1 + 40))
				*(_DWORD*)(a1 + 28) = 1;
		} else if (*(_DWORD*)(a1 + 40) <= *(int*)(a1 + 44)) {
			*(_DWORD*)(a1 + 24) = 1;
		}
		if (*(_BYTE*)(v11 + 8) & 4) {
			sub_50FA00(v11, (_DWORD*)a1);
			sub_50FAE0(*(_DWORD*)(a1 + 8), a2, a1, *v6, v6[1]);
			sub_50F720(*(_DWORD*)(a1 + 8), (_DWORD*)a1);
		}
		v12 = *(_DWORD*)(a1 + 12);
		if (*(_BYTE*)(v12 + 8) & 4) {
			sub_50FA00(v12, (_DWORD*)a1);
			sub_50FAE0(*(_DWORD*)(a1 + 12), a2, a1, *v6, v6[1]);
			sub_50F720(*(_DWORD*)(a1 + 12), (_DWORD*)a1);
		}
		result = 1;
	} else {
		if (*(_BYTE*)(*(_DWORD*)(a1 + 8) + 8) & 4) {
			v7 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 236056), 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c",
									   2487);
			sub_4D9EB0(*(_DWORD*)(a1 + 8), v7);
		}
		if (!(*(_BYTE*)(*(_DWORD*)(a1 + 12) + 8) & 4))
			return 0;
		v8 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 236120), 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 2490);
		sub_4D9EB0(*(_DWORD*)(a1 + 12), v8);
		result = 0;
	}
	return result;
}

//----- (005100C0) --------------------------------------------------------
float* __cdecl sub_5100C0_trade(int a1, _DWORD* a2, int a3) {
	int v3;                                      // edi
	unsigned int v4;                             // ebx
	float* result;                               // eax
	int v6;                                      // esi
	unsigned int v7;                             // eax
	unsigned int v8;                             // ebp
	int v9;                                      // ebx
	wchar_t* v10;                                // eax
	int v11;                                     // eax
	int v12;                                     // ebx
	_DWORD* v13;                                 // eax
	void(__cdecl * v14)(int, _DWORD*, int, int); // ecx
	int v15;                                     // [esp+0h] [ebp-14h]
	float v16;                                   // [esp+0h] [ebp-14h]
	float v17;                                   // [esp+0h] [ebp-14h]
	int v18;                                     // [esp+18h] [ebp+4h]

	v3 = a1;
	v15 = a1;
	v18 = *(_DWORD*)(a1 + 748);
	v4 = sub_4FA6B0(v15);
	if (!dword_5d4594_2386548)
		dword_5d4594_2386548 = sub_4E3AA0((CHAR*)getMemAt(0x587000, 236144));
	result = (float*)a2[5];
	if (result) {
		while (!*(_DWORD*)result || *(_DWORD*)(*(_DWORD*)result + 36) != a3) {
			result = (float*)*((_DWORD*)result + 2);
			if (!result)
				return result;
		}
		v6 = *(_DWORD*)result;
		if (*(_DWORD*)result) {
			v7 = sub_50E3D0(1, (int)a2, *result);
			v8 = v7;
			if (v7 > v4)
				return (float*)sub_5104F0(v3, v7 - v4);
			if (*(_BYTE*)(v6 + 8) & 0x10) {
				v9 = sub_4E7D30(v3, *(unsigned __int16*)(v6 + 4));
				if (v9 >= (nox_common_gameFlags_check_40A5C0(6144) ? 9 : 3)) {
					v10 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 236200), 0,
												"C:\\NoxPost\\src\\Server\\System\\Trade.c", 2943);
					return (float*)sub_4D9EB0(v3, v10);
				}
			}
			if (*(unsigned __int16*)(v6 + 4) == dword_5d4594_2386548) {
				v16 = sub_419D40(getMemAt(0x587000, 236224));
				if (*(_DWORD*)(v18 + 320) >= nox_float2int(v16)) {
					sub_4DA2C0(v3, "pickup.c:MaxTradableAnkhsReached", 0);
					return (float*)sub_501960(925, v3, 0, 0);
				}
			}
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				v11 = *(_DWORD*)(v6 + 8);
				if (v11 & 0x1000) {
					if (*(_DWORD*)(v6 + 12) & 0x200000) {
						v17 = sub_419D40(getMemAt(0x587000, 236276));
						v12 = nox_float2int(v17);
						if (sub_4E7D30(v3, *(unsigned __int16*)(v6 + 4)) >= v12) {
							sub_4DA2C0(v3, "pickup.c:MaxSameItem", 0);
							return (float*)sub_501960(925, v3, 0, 0);
						}
					}
				}
			}
			if (nox_common_gameFlags_check_40A5C0(4096) &&
				(sub_5105D0(v6) || *(unsigned __int16*)(v6 + 4) == dword_5d4594_2386548))
				v13 = nox_new_objMem_2_4E3450(*(unsigned __int16*)(v6 + 4));
			else
				v13 = (_DWORD*)v6;
			if (v13[2] & 0x110 || (v14 = (void(__cdecl*)(int, _DWORD*, int, int))v13[177]) == 0) {
				sub_4F3070(v3, (int)v13, 1);
				sub_501960(307, v3, 2, *(_DWORD*)(v3 + 36));
			} else {
				v14(v3, v13, 1, 1);
			}
			sub_510320(v6, (int)a2);
			if (sub_510540(v6))
				sub_50E7A0(a2, v6);
			sub_4FA5D0(v3, v8);
			result = (float*)sub_4D8870(*(unsigned __int8*)(*(_DWORD*)(v18 + 276) + 2064), v3);
		}
	}
	return result;
}

//----- (00510640) --------------------------------------------------------
float* __cdecl sub_510640_trade(int a1, int a2, int a3, float* a4) {
	int v4;                                      // ebp
	float* result;                               // eax
	_DWORD* v6;                                  // edi
	int v7;                                      // esi
	unsigned int v8;                             // ebx
	int v9;                                      // edi
	int v10;                                     // eax
	int v11;                                     // edi
	_DWORD* v12;                                 // eax
	void(__cdecl * v13)(int, _DWORD*, int, int); // ecx
	wchar_t* v14;                                // eax
	int v15;                                     // [esp+0h] [ebp-1Ch]
	float v16;                                   // [esp+0h] [ebp-1Ch]
	float v17;                                   // [esp+0h] [ebp-1Ch]
	unsigned int v18;                            // [esp+14h] [ebp-8h]
	unsigned int v19;                            // [esp+18h] [ebp-4h]
	int v20;                                     // [esp+20h] [ebp+4h]

	v4 = a1;
	v15 = a1;
	v20 = *(_DWORD*)(a1 + 748);
	v19 = sub_4FA6B0(v15);
	if (!dword_5d4594_2386552)
		dword_5d4594_2386552 = sub_4E3AA0((CHAR*)getMemAt(0x587000, 236388));
	result = a4;
	v18 = 0;
	if (a4) {
		while (1) {
			v6 = (_DWORD*)a2;
			result = *(float**)(a2 + 20);
			if (!result)
				return result;
			while (*(unsigned __int16*)(*(_DWORD*)result + 4) != a3) {
				result = (float*)*((_DWORD*)result + 2);
				if (!result)
					return result;
			}
			v7 = *(_DWORD*)result;
			if (!*(_DWORD*)result)
				return result;
			v8 = sub_50E3D0(1, a2, *result);
			if (v8 > v19)
				return (float*)sub_5104F0(v4, v8 - v19);
			if (*(_BYTE*)(v7 + 8) & 0x10) {
				v9 = sub_4E7D30(v4, *(unsigned __int16*)(v7 + 4));
				if (v9 >= (nox_common_gameFlags_check_40A5C0(6144) ? 9 : 3)) {
					v14 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 236444), 0,
												"C:\\NoxPost\\src\\Server\\System\\Trade.c", 3108);
					return (float*)sub_4D9EB0(v4, v14);
				}
				v6 = (_DWORD*)a2;
			}
			if (*(unsigned __int16*)(v7 + 4) == dword_5d4594_2386552) {
				v16 = sub_419D40(getMemAt(0x587000, 236468));
				if (*(_DWORD*)(v20 + 320) >= nox_float2int(v16))
					break;
			}
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				v10 = *(_DWORD*)(v7 + 8);
				if (v10 & 0x1000) {
					if (*(_DWORD*)(v7 + 12) & 0x200000) {
						v17 = sub_419D40(getMemAt(0x587000, 236520));
						v11 = nox_float2int(v17);
						if (sub_4E7D30(v4, *(unsigned __int16*)(v7 + 4)) >= v11) {
							sub_4DA2C0(v4, "pickup.c:MaxSameItem", 0);
							goto LABEL_36;
						}
						v6 = (_DWORD*)a2;
					}
				}
			}
			if (nox_common_gameFlags_check_40A5C0(4096) &&
				(sub_5105D0(v7) || *(unsigned __int16*)(v7 + 4) == dword_5d4594_2386552))
				v12 = nox_new_objMem_2_4E3450(*(unsigned __int16*)(v7 + 4));
			else
				v12 = (_DWORD*)v7;
			v13 = (void(__cdecl*)(int, _DWORD*, int, int))v12[177];
			if (v13)
				v13(v4, v12, 1, 1);
			else
				sub_4F3070(v4, (int)v12, 1);
			sub_510320(v7, (int)v6);
			if (sub_510540(v7))
				sub_50E7A0(v6, v7);
			sub_4FA5D0(v4, v8);
			sub_4D8870(*(unsigned __int8*)(*(_DWORD*)(v20 + 276) + 2064), v4);
			result = (float*)++v18;
			if (v18 >= (unsigned int)a4)
				return result;
		}
		sub_4DA2C0(v4, "pickup.c:MaxTradableAnkhsReached", 0);
	LABEL_36:
		result = (float*)sub_501960(925, v4, 0, 0);
	}
	return result;
}

//----- (005109C0) --------------------------------------------------------
_DWORD* __cdecl sub_5109C0_trade(int* a1, int a2, _DWORD* a3) {
	int v3;         // ebx
	int v4;         // esi
	_DWORD* result; // eax
	wchar_t* v6;    // eax
	wchar_t* v7;    // eax
	char v8[8];     // [esp+Ch] [ebp-8h]

	v3 = a1[187];
	if (!*(_DWORD*)getMemAt(0x5D4594, 2386556))
		*(_DWORD*)getMemAt(0x5D4594, 2386556) = sub_4E3AA0((CHAR*)getMemAt(0x587000, 236568));
	v4 = a1[126];
	result = a3;
	v8[0] = -55;
	v8[1] = 29;
	*(_WORD*)&v8[2] = (_WORD)a3;
	if (v4) {
		while (*(_DWORD**)(v4 + 36) != a3) {
			v4 = *(_DWORD*)(v4 + 496);
			if (!v4)
				return result;
		}
		if (sub_53EBF0(v4) == 1) {
			v6 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 236616), 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c",
									   3298);
			sub_4D9EB0((int)a1, v6);
			result = sub_501960(925, (int)a1, 2, a1[9]);
		} else if (*(unsigned __int16*)(v4 + 4) == *(_DWORD*)getMemAt(0x5D4594, 2386556)) {
			v7 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 236676), 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c",
									   3308);
			sub_4D9EB0((int)a1, v7);
			result = sub_501960(925, (int)a1, 2, a1[9]);
		} else {
			*(_DWORD*)&v8[4] = sub_50E3D0(0, a2, *(float*)&v4);
			result = (_DWORD*)sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), v8, 8, 0, 1);
		}
	}
	return result;
}

//----- (00510BE0) --------------------------------------------------------
_DWORD* __cdecl sub_510BE0_trade(int* a1, int a2, _DWORD* a3) {
	_DWORD* result; // eax
	int v4;         // ebx
	int v5;         // esi
	wchar_t* v6;    // eax
	wchar_t* v7;    // eax
	int v8;         // eax

	sub_4FA6B0((int)a1);
	result = *(_DWORD**)&dword_5d4594_2386560;
	v4 = a1[187];
	if (!dword_5d4594_2386560) {
		result = (_DWORD*)sub_4E3AA0((CHAR*)getMemAt(0x587000, 236692));
		dword_5d4594_2386560 = result;
	}
	v5 = a1[126];
	if (v5) {
		result = a3;
		while (*(_DWORD**)(v5 + 36) != a3) {
			v5 = *(_DWORD*)(v5 + 496);
			if (!v5)
				return result;
		}
		if (sub_53EBF0(v5) == 1) {
			v6 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 236740), 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c",
									   3413);
			sub_4D9EB0((int)a1, v6);
			result = sub_501960(925, (int)a1, 2, a1[9]);
		} else if (*(unsigned __int16*)(v5 + 4) == dword_5d4594_2386560) {
			v7 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 236800), 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c",
									   3423);
			sub_4D9EB0((int)a1, v7);
			result = sub_501960(925, (int)a1, 2, a1[9]);
		} else {
			sub_4ED0C0((int)a1, (int*)v5);
			sub_4E5CC0(v5);
			v8 = sub_50E3D0(0, a2, *(float*)&v5);
			sub_4FA590((int)a1, v8);
			sub_4D8870(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), (int)a1);
			result = sub_501960(307, (int)a1, 2, a1[9]);
		}
	}
	return result;
}