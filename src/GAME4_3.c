#include "server/ability/ability.h"
#include "server/magic/plyrgide.h"
#include "server/magic/plyrspel.h"
#include "server/object/health.h"

#include "common/gamemech/pausefx.h"

#include "proto.h"

extern _DWORD dword_5d4594_2487912;
extern _DWORD dword_5d4594_2487980;
extern _DWORD dword_5d4594_3835356;
extern _DWORD dword_5d4594_2487852;
extern _DWORD dword_5d4594_2487848;
extern _DWORD dword_587000_312788;
extern _DWORD dword_587000_312784;
extern _DWORD dword_5d4594_2487984;
extern _DWORD dword_5d4594_2487248;
extern _DWORD dword_587000_312800;
extern _DWORD dword_587000_312816;
extern _DWORD dword_587000_312804;
extern _DWORD dword_587000_312820;
extern _DWORD dword_5d4594_2488660;
extern _QWORD qword_581450_10176;
extern _QWORD qword_581450_9512;
extern _QWORD qword_581450_9568;
extern _QWORD qword_581450_9544;
extern _DWORD dword_5d4594_2488604;
extern _DWORD dword_587000_264364;
extern _DWORD dword_5d4594_2487904;
extern _DWORD dword_5d4594_2487908;
extern _DWORD dword_5d4594_251572;
extern _DWORD dword_5d4594_2650652;
extern obj_5D4594_2650668_t** ptr_5D4594_2650668;

//----- (0052F8A0) --------------------------------------------------------
int __cdecl sub_52F8A0(float a1) {
	int v1;              // esi
	int v2;              // eax
	int v4;              // eax
	int v5;              // eax
	int v6;              // edi
	int v7;              // ecx
	int v8;              // edx
	int v9;              // ebx
	int v10;             // eax
	int v11;             // ecx
	int v12;             // edi
	int v13;             // eax
	int v14;             // ecx
	int v15;             // ecx
	int v16;             // ecx
	int v17;             // ecx
	int v18;             // ecx
	int v19;             // eax
	int v20;             // ebx
	_DWORD* v21;         // edi
	_DWORD* j;           // ebp
	int v23;             // eax
	int v24;             // eax
	int v25;             // ecx
	int v26;             // eax
	int v27;             // edi
	char v28;            // al
	unsigned __int8 v29; // al
	int v30;             // eax
	int v31;             // ebp
	int i;               // edi
	int v33;             // eax
	int v34;             // edi
	float v35;           // [esp+0h] [ebp-20h]
	float v36;           // [esp+0h] [ebp-20h]
	float v37;           // [esp+0h] [ebp-20h]
	float v38;           // [esp+0h] [ebp-20h]
	float v39;           // [esp+8h] [ebp-18h]
	float v40;           // [esp+1Ch] [ebp-4h]
	float v41;           // [esp+24h] [ebp+4h]
	float v42;           // [esp+24h] [ebp+4h]

	v1 = LODWORD(a1);
	v2 = *(_DWORD*)(LODWORD(a1) + 16);
	if (v2) {
		if (sub_4FF350(v2, 8))
			return 1;
	} else if (!*(_DWORD*)(LODWORD(a1) + 20)) {
		return 1;
	}
	v41 = sub_419D40(&byte_587000[260712]);
	if (*(_DWORD*)(v1 + 20)) {
		*(_DWORD*)&byte_5D4594[2487820] = *(_DWORD*)(v1 + 28);
		*(_DWORD*)&byte_5D4594[2487824] = *(_DWORD*)(v1 + 32);
		sub_517F90((float2*)(v1 + 28), v41, sub_530020, *(_DWORD*)(v1 + 16));
		return 1;
	}
	if (*(_BYTE*)(*(_DWORD*)(v1 + 16) + 8) & 4 && !sub_4EEC80(*(_DWORD*)(v1 + 16)))
		return 1;
	if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v1 + 60)) > 2 &&
	    sub_4E6BD0(*(_DWORD*)(v1 + 16)))
		return 1;
	v4 = *(_DWORD*)(v1 + 16);
	if (*(_BYTE*)(v4 + 8) & 2 && sub_4FEA70(v4, (float2*)(v1 + 28)))
		return 1;
	v5 = *(_DWORD*)(v1 + 104);
	if (v5) {
		do {
			v6 = *(_DWORD*)(v5 + 116);
			sub_4FE980(v5);
			v5 = v6;
		} while (v6);
	}
	v7 = *(_DWORD*)(v1 + 8);
	*(_DWORD*)(v1 + 104) = *(_DWORD*)(v1 + 108);
	*(_DWORD*)(v1 + 108) = 0;
	dword_5d4594_2487908 = 0;
	dword_5d4594_2487904 = 0;
	v8 = *(_DWORD*)(v1 + 16);
	*(_DWORD*)&byte_5D4594[2487844] = 0;
	v9 = *(_DWORD*)&byte_587000[4 * v7 + 260380];
	dword_5d4594_2487848 = 0;
	*(_DWORD*)&byte_5D4594[2487900] = v8;
	dword_5d4594_2487852 = 0;
	*(_DWORD*)&byte_5D4594[2487856] = 0;
	*(_DWORD*)&byte_5D4594[2487860] = 0;
	v10 = *(_DWORD*)(v1 + 16);
	if (!(*(_BYTE*)(v10 + 8) & 4) || (v11 = *(_DWORD*)(v10 + 748), (v12 = *(_DWORD*)(v11 + 288)) == 0) ||
	    (!sub_5330C0(v10, *(_DWORD*)(v11 + 288)) || sub_4E6C00(*(_DWORD*)(v1 + 16), v12) > v41
		 ? (v13 = dword_5d4594_2487908)
		 : (v13 = v12, dword_5d4594_2487908 = v12),
	     !v13)) {
		*(float*)&dword_5d4594_2487912 = v41 * v41;
		sub_517F90((float2*)(v1 + 28), v41, sub_52FF10, *(_DWORD*)(v1 + 16));
		v13 = dword_5d4594_2487908;
		if (!dword_5d4594_2487908) {
			for (i = *(_DWORD*)(v1 + 104); i; i = *(_DWORD*)(i + 116)) {
				if (*(_DWORD*)(i + 48))
					sub_4FEF90(i, *(_DWORD**)(i + 48));
			}
			v33 = *(_DWORD*)(v1 + 104);
			if (v33) {
				do {
					v34 = *(_DWORD*)(v33 + 116);
					sub_4FE980(v33);
					v33 = v34;
				} while (v34);
			}
			*(_DWORD*)(v1 + 104) = 0;
			return 0;
		}
	}
	v14 = dword_5d4594_2487904;
	*(_DWORD*)&byte_5D4594[4 * dword_5d4594_2487904 + 2487844] = v13;
	dword_5d4594_2487904 = v14 + 1;
	if (v9 > 1) {
		dword_5d4594_2487908 = 0;
		*(float*)&dword_5d4594_2487912 = v41 * v41;
		v35 = v41 * 0.94999999;
		sub_517F90((float2*)(*(_DWORD*)&byte_5D4594[2487844] + 56), v35, sub_52FF10,
			   *(int*)&byte_5D4594[2487844]);
		if (dword_5d4594_2487908) {
			v15 = dword_5d4594_2487904;
			*(_DWORD*)&byte_5D4594[4 * dword_5d4594_2487904 + 2487844] =
			    dword_5d4594_2487908;
			dword_5d4594_2487904 = v15 + 1;
		}
	}
	if (v9 > 2) {
		dword_5d4594_2487908 = 0;
		*(float*)&dword_5d4594_2487912 = v41 * v41;
		v36 = v41 * 0.89999998;
		sub_517F90((float2*)(*(_DWORD*)&byte_5D4594[2487844] + 56), v36, sub_52FF10,
			   *(int*)&byte_5D4594[2487844]);
		if (dword_5d4594_2487908) {
			v16 = dword_5d4594_2487904;
			*(_DWORD*)&byte_5D4594[4 * dword_5d4594_2487904 + 2487844] =
			    dword_5d4594_2487908;
			dword_5d4594_2487904 = v16 + 1;
		}
	}
	if (dword_5d4594_2487848) {
		if (v9 > 3) {
			dword_5d4594_2487908 = 0;
			*(float*)&dword_5d4594_2487912 = v41 * v41;
			v37 = v41 * 0.85000002;
			sub_517F90((float2*)(dword_5d4594_2487848 + 56), v37, sub_52FF10,
				   *(int*)&dword_5d4594_2487848);
			if (dword_5d4594_2487908) {
				v17 = dword_5d4594_2487904;
				*(_DWORD*)&byte_5D4594[4 * dword_5d4594_2487904 + 2487844] =
				    dword_5d4594_2487908;
				dword_5d4594_2487904 = v17 + 1;
			}
		}
	}
	if (dword_5d4594_2487852) {
		if (v9 > 4) {
			dword_5d4594_2487908 = 0;
			v40 = v41 * v41;
			*(float*)&dword_5d4594_2487912 = v40 * v40;
			v38 = v41 * 0.80000001;
			sub_517F90((float2*)(dword_5d4594_2487852 + 56), v38, sub_52FF10,
				   *(int*)&dword_5d4594_2487852);
			if (dword_5d4594_2487908) {
				v18 = dword_5d4594_2487904;
				*(_DWORD*)&byte_5D4594[4 * dword_5d4594_2487904 + 2487844] =
				    dword_5d4594_2487908;
				dword_5d4594_2487904 = v18 + 1;
			}
		}
	}
	sub_52FFD0(v1, *(_DWORD*)(v1 + 16), *(int*)&byte_5D4594[2487844]);
	if (v9 > 1 && dword_5d4594_2487848)
		sub_52FFD0(v1, *(int*)&byte_5D4594[2487844], *(int*)&dword_5d4594_2487848);
	v19 = dword_5d4594_2487852;
	if (v9 > 2 && dword_5d4594_2487852) {
		sub_52FFD0(v1, *(int*)&byte_5D4594[2487844], *(int*)&dword_5d4594_2487852);
		v19 = dword_5d4594_2487852;
	}
	if (v9 > 3 && *(_DWORD*)&byte_5D4594[2487856]) {
		if (dword_5d4594_2487848) {
			sub_52FFD0(v1, *(int*)&dword_5d4594_2487848, *(int*)&byte_5D4594[2487856]);
		LABEL_54:
			v19 = dword_5d4594_2487852;
			goto LABEL_55;
		}
		if (v19) {
			sub_52FFD0(v1, v19, *(int*)&byte_5D4594[2487856]);
			goto LABEL_54;
		}
	}
LABEL_55:
	if (v9 > 4) {
		if (*(_DWORD*)&byte_5D4594[2487860]) {
			if (v19 || (v19 = dword_5d4594_2487848) != 0)
				sub_52FFD0(v1, v19, *(int*)&byte_5D4594[2487860]);
		}
	}
	if (!*(_DWORD*)&byte_5D4594[2487844])
		return 0;
	v42 = sub_419D40(&byte_587000[260728]) + *(float*)(v1 + 76);
	v20 = nox_float2int(v42);
	*(float*)(v1 + 76) = v42 - (double)v20;
	v21 = *(_DWORD**)(v1 + 108);
	for (j = *(_DWORD**)(v1 + 104); v21; v21 = (_DWORD*)v21[29]) {
		if (j) {
			v23 = j[12];
			if (v21[12] != v23 || v21[4] != j[4]) {
				if (v23)
					sub_4FEF90((int)j, (_DWORD*)j[12]);
				sub_4FF130((int)v21);
			}
			j = (_DWORD*)j[29];
		} else {
			sub_4FF130((int)v21);
		}
		if (v20 > 0)
			(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD, int, int))(v21[12] + 716))(
			    v21[12], *(_DWORD*)(v1 + 16), 0, v20, 17);
		v24 = v21[12];
		if (*(_DWORD*)(v24 + 16) & 0x8020)
			sub_522FF0(129, (float2*)(v24 + 56));
	}
	for (; j; j = (_DWORD*)j[29]) {
		if (j[12])
			sub_4FEF90((int)j, (_DWORD*)j[12]);
	}
	v25 = *(_DWORD*)(v1 + 16);
	if (*(_BYTE*)(v25 + 8) & 4) {
		v26 = *(_DWORD*)(v1 + 72);
		if (v26) {
			v27 = *(_DWORD*)(v26 + 736);
			v28 = *(_BYTE*)(v27 + 108);
			if (!v28)
				return 1;
			v29 = v28 - 1;
			*(_BYTE*)(v27 + 108) = v29;
			*(_DWORD*)(v27 + 112) = 100 * v29 / *(unsigned __int8*)(v27 + 109);
			v30 = *(_DWORD*)(v1 + 16);
			if (v30 && *(_BYTE*)(v30 + 8) & 4) {
				v31 = *(_DWORD*)(v30 + 748);
				sub_4FA020((_DWORD*)v30, 22);
				sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(v31 + 276) + 2064), *(_DWORD**)(v1 + 72),
					   *(_BYTE*)(v27 + 108), *(_BYTE*)(v27 + 109));
			}
			if (!*(_BYTE*)(v27 + 108))
				return 1;
		} else {
			sub_4FA020((_DWORD*)v25, 10);
			sub_4EEBF0(*(_DWORD*)(v1 + 16), 1);
			if (!sub_4EEC80(*(_DWORD*)(v1 + 16)))
				return 1;
		}
	}
	if (!(*(_DWORD*)&byte_5D4594[2598000] % (*(_DWORD*)&byte_5D4594[2649704] / 3u))) {
		sub_501960(78, *(_DWORD*)(v1 + 16), 0, 0);
		sub_501960(78, *(int*)&byte_5D4594[2487844], 0, 0);
	}
	v39 = sub_419D40(&byte_587000[260744]);
	*(_DWORD*)(v1 + 68) = *(_DWORD*)&byte_5D4594[2598000] + nox_float2int(v39);
	return 0;
}

//----- (0052FF10) --------------------------------------------------------
void __cdecl sub_52FF10(int a1, int a2) {
	int v2;              // eax
	int v3;              // ecx
	int v4;              // eax
	unsigned __int8* v5; // ecx
	double v6;           // st7
	double v7;           // st6
	double v8;           // st5

	if (*(_DWORD*)(a1 + 8) & 0x20006) {
		v2 = *(_DWORD*)&byte_5D4594[2487900];
		if (*(_DWORD*)&byte_5D4594[2487900]) {
			if (!sub_5330C0(*(int*)&byte_5D4594[2487900], a1))
				return;
			v2 = *(_DWORD*)&byte_5D4594[2487900];
		}
		if (!(*(_BYTE*)(a1 + 8) & 2) || (v3 = *(_DWORD*)(a1 + 12), (v3 & 0x8000) == 0)) {
			if (!(*(_DWORD*)(a1 + 16) & 0x8020) && a1 != a2 && a1 != v2) {
				v4 = 0;
				if (*(int*)&dword_5d4594_2487904 <= 0) {
				LABEL_14:
					if (sub_5370E0(a2, a1, 0)) {
						v6 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
						v7 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
						v8 = v7 * v7 + v6 * v6;
						if (v8 < *(float*)&dword_5d4594_2487912) {
							*(float*)&dword_5d4594_2487912 = v8;
							dword_5d4594_2487908 = a1;
						}
					}
				} else {
					v5 = &byte_5D4594[2487844];
					while (*(_DWORD*)v5 != a1) {
						++v4;
						v5 += 4;
						if (v4 >= *(int*)&dword_5d4594_2487904)
							goto LABEL_14;
					}
				}
			}
		}
	}
}

//----- (0052FFD0) --------------------------------------------------------
_DWORD* __cdecl sub_52FFD0(int a1, int a2, int a3) {
	_DWORD* result; // eax
	int v4;         // ecx
	int v5;         // ecx

	result = sub_4FE950();
	if (result) {
		result[12] = a3;
		result[4] = a2;
		result[1] = 7;
		result[27] = 0;
		result[26] = 0;
		v4 = *(_DWORD*)(a1 + 108);
		result[28] = 0;
		result[29] = v4;
		v5 = *(_DWORD*)(a1 + 108);
		if (v5)
			*(_DWORD*)(v5 + 112) = result;
		*(_DWORD*)(a1 + 108) = result;
	}
	return result;
}

//----- (00530020) --------------------------------------------------------
void __cdecl sub_530020(int a1, int a2) {
	int v2;    // eax
	int v3;    // eax
	float v4;  // edx
	float v5;  // eax
	int v6;    // eax
	int v7;    // eax
	float v8;  // [esp+0h] [ebp-20h]
	float4 v9; // [esp+10h] [ebp-10h]

	if (a1 != a2) {
		v2 = *(_DWORD*)(a1 + 8);
		if (v2 & 6) {
			if (!(*(_DWORD*)(a1 + 16) & 0x8020)) {
				if (!(v2 & 2) || (v3 = *(_DWORD*)(a1 + 12), (v3 & 0x8000) == 0)) {
					if (!a2 || sub_5330C0(a2, a1)) {
						v4 = *(float*)(a1 + 56);
						v9.field_4 = *(float*)&byte_5D4594[2487824];
						v9.field_0 = *(float*)&byte_5D4594[2487820];
						v5 = *(float*)(a1 + 60);
						v9.field_8 = v4;
						v9.field_C = v5;
						if (sub_535250(&v9, 0, 0, 9)) {
							v8 = sub_419D40(&byte_587000[260764]);
							v6 = nox_float2int(v8);
							(*(void(__cdecl**)(int, _DWORD, _DWORD, int, int))(a1 + 716))(
							    a1, 0, 0, v6, 17);
							sub_522FF0(129, (float2*)(a1 + 56));
							v7 = sub_424800(43, 0);
							sub_501960(v7, a1, 0, 0);
						}
					}
				}
			}
		}
	}
}

//----- (00530100) --------------------------------------------------------
char __cdecl sub_530100(_DWORD* a1) {
	int v1; // eax
	int v2; // esi
	int v3; // eax
	int v4; // esi
	int v5; // edi
	int v6; // edi

	v1 = a1[27];
	if (v1) {
		do {
			v2 = *(_DWORD*)(v1 + 116);
			sub_4FE980(v1);
			v1 = v2;
		} while (v2);
	}
	v3 = a1[26];
	a1[27] = 0;
	if (v3) {
		do {
			v4 = *(_DWORD*)(v3 + 116);
			sub_4FE980(v3);
			v3 = v4;
		} while (v4);
	}
	a1[26] = 0;
	v5 = a1[18];
	if (v5) {
		v6 = *(_DWORD*)(v5 + 736);
		v3 = *(_DWORD*)(v6 + 96);
		LOBYTE(v3) = v3 & 0xFB;
		*(_DWORD*)(v6 + 96) = v3;
	}
	return v3;
}

//----- (00530160) --------------------------------------------------------
int __cdecl sub_530160(_DWORD* a1) {
	int v1;      // eax
	int v2;      // edi
	int v3;      // eax
	_DWORD* v4;  // eax
	__int16 v5;  // ax
	int v6;      // ecx
	__int16 v7;  // dx
	float v9;    // [esp+0h] [ebp-14h]
	char v10[7]; // [esp+Ch] [ebp-8h]

	v1 = a1[4];
	v2 = *(_DWORD*)(v1 + 748);
	if (!v1)
		return 1;
	if (*(_DWORD*)(v1 + 16) & 0x8020)
		return 1;
	if (!(*(_BYTE*)(v1 + 8) & 4))
		return 1;
	v3 = a1[12];
	if (!v3 || *(_DWORD*)(v3 + 16) & 0x8020)
		return 1;
	v9 = sub_419D40(&byte_587000[260788]);
	a1[17] = *(_DWORD*)&byte_5D4594[2598000] + a1[2] * nox_float2int(v9);
	sub_417190(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), a1[12], 1);
	v4 = (_DWORD*)a1[12];
	v10[0] = -46;
	v5 = sub_578AC0(v4);
	v6 = a1[12];
	*(_WORD*)&v10[1] = v5;
	v7 = *(_WORD*)(v6 + 4);
	v10[5] = 1;
	*(_WORD*)&v10[3] = v7;
	v10[6] = 1;
	sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v10, 7, 0, 1);
	return 0;
}

//----- (00530250) --------------------------------------------------------
unsigned int __cdecl sub_530250(int a1) {
	int v1;              // eax
	unsigned int result; // eax

	v1 = *(_DWORD*)(a1 + 48);
	if (v1)
		result = ((*(_DWORD*)(v1 + 16) & 0xFFu) >> 5) & 1;
	else
		result = 1;
	return result;
}

//----- (00530270) --------------------------------------------------------
int __cdecl sub_530270(int a1) {
	int result; // eax
	int v2;     // edi
	_DWORD* v3; // edx
	__int16 v4; // cx
	char v5[7]; // [esp+8h] [ebp-8h]

	result = *(_DWORD*)(a1 + 16);
	if (result) {
		if (*(_BYTE*)(result + 8) & 4) {
			v2 = *(_DWORD*)(result + 748);
			result = *(_DWORD*)(a1 + 48);
			if (result) {
				if (!(*(_BYTE*)(result + 8) & 4))
					sub_417300(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), result, 1);
				v3 = *(_DWORD**)(a1 + 48);
				v5[0] = -46;
				*(_WORD*)&v5[1] = sub_578AC0(v3);
				v4 = *(_WORD*)(*(_DWORD*)(a1 + 48) + 4);
				v5[5] = 2;
				*(_WORD*)&v5[3] = v4;
				v5[6] = 1;
				result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v5, 7, 0, 1);
			}
		}
	}
	return result;
}

//----- (00530310) --------------------------------------------------------
int __cdecl sub_530310(_DWORD* a1) {
	int result; // eax
	float v2;   // [esp+0h] [ebp-8h]

	if (!nox_common_gameFlags_check_40A5C0(4096) || (result = 1, a1[5] != 1)) {
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			v2 = sub_419D70(&byte_587000[260808], a1[2] - 1);
			a1[17] = *(_DWORD*)&byte_5D4594[2598000] + nox_float2int(v2);
			result = 0;
		} else {
			result = 0;
			a1[17] = *(_DWORD*)&byte_5D4594[2598000] + 1;
		}
	}
	return result;
}

//----- (00530380) --------------------------------------------------------
int __cdecl sub_530380(int* a1) {
	int v1;     // eax
	int v3;     // eax
	float2* v4; // ecx
	int v5;     // eax
	bool v6;    // zf
	int v7;     // eax
	int v8;     // eax
	int v9;     // [esp-Ch] [ebp-18h]
	int v10;    // [esp-Ch] [ebp-18h]
	int v11;    // [esp-8h] [ebp-14h]
	int v12;    // [esp-4h] [ebp-10h]
	float2 v13; // [esp+4h] [ebp-8h]

	v1 = a1[12];
	if (!v1)
		return 1;
	if (*(_DWORD*)(v1 + 16) & 0x8020)
		return 1;
	if (a1[17] - 1 == *(_DWORD*)&byte_5D4594[2598000]) {
		if (sub_4FF350(v1, 14)) {
			sub_501960(231, a1[12], 0, 0);
			return 1;
		}
		if (nox_common_gameFlags_check_40A5C0(4096) && (v3 = a1[12], *(_BYTE*)(v3 + 8) & 4)) {
			v4 = *(float2**)(*(_DWORD*)(v3 + 748) + 308);
			if (v4)
				sub_4ED970(60.0, v4 + 7, &v13);
			else
				sub_4F7AB0(&v13, a1[12]);
		} else if (!sub_579F00(&v13, a1[12])) {
			sub_4F7AB0(&v13, a1[12]);
		}
		sub_530560(a1[12], (int*)(a1[12] + 56), &v13);
		sub_522FF0(137, (float2*)(a1[12] + 56));
		v9 = a1[12];
		v5 = sub_424800(a1[1], 0);
		sub_501960(v5, v9, 0, 0);
		if (!sub_4FF350(a1[12], 0)) {
			sub_522FF0(137, (float2*)(a1[12] + 56));
			sub_522FF0(137, &v13);
		}
		sub_4E7190((_BYTE*)a1[12], &v13.field_0);
		v6 = !sub_4FF350(a1[12], 0);
		v7 = a1[12];
		if (v6) {
			sub_522FF0(137, (float2*)(v7 + 56));
			v12 = 0;
			v11 = 0;
			v10 = a1[12];
		} else {
			if (!(*(_BYTE*)(v7 + 8) & 4)) {
			LABEL_22:
				sub_4E7540(a1[4], a1[12]);
				return 1;
			}
			v12 = *(_DWORD*)(v7 + 36);
			v11 = 2;
			v10 = a1[12];
		}
		v8 = sub_424800(a1[1], 0);
		sub_501960(v8, v10, v11, v12);
		goto LABEL_22;
	}
	return 0;
}

//----- (00530560) --------------------------------------------------------
_DWORD* __cdecl sub_530560(int a1, int* a2, _DWORD* a3) {
	int v3;         // eax
	_DWORD* result; // eax
	_DWORD* v5;     // esi
	_DWORD* v6;     // eax

	v3 = *(_DWORD*)&byte_5D4594[2487916];
	if (!*(_DWORD*)&byte_5D4594[2487916]) {
		v3 = sub_4E3AA0((CHAR*)&byte_587000[260824]);
		*(_DWORD*)&byte_5D4594[2487916] = v3;
	}
	result = sub_4E3450(v3);
	v5 = result;
	if (result) {
		v6 = (_DWORD*)result[175];
		*v6 = *a3;
		v6[1] = a3[1];
		sub_4DAA50((int)v5, a1, *(float*)a2, *((float*)a2 + 1));
		result = (_DWORD*)(*(_DWORD*)&byte_5D4594[2598000] + *(_DWORD*)&byte_5D4594[2649704]);
		v5[34] = *(_DWORD*)&byte_5D4594[2598000] + *(_DWORD*)&byte_5D4594[2649704];
	}
	return result;
}

//----- (005305D0) --------------------------------------------------------
int __cdecl sub_5305D0(_DWORD* a1) {
	int v1;   // eax
	int v2;   // eax
	float v4; // [esp+0h] [ebp-8h]

	v1 = a1[3];
	if (*(_BYTE*)(v1 + 8) & 4) {
		v2 = *(_DWORD*)(v1 + 748);
		if (!v2 || !*(_DWORD*)(v2 + 4 * a1[1] - 372))
			return 1;
	}
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v4 = sub_419D70(&byte_587000[260840], a1[2] - 1);
		a1[17] = *(_DWORD*)&byte_5D4594[2598000] + nox_float2int(v4);
	} else {
		a1[17] = *(_DWORD*)&byte_5D4594[2598000] + 1;
	}
	return 0;
}

//----- (00530650) --------------------------------------------------------
int __cdecl sub_530650(int* a1) {
	int v1;     // ecx
	int v2;     // eax
	int v4;     // eax
	int v5;     // ebp
	int v6;     // edi
	int v7;     // edx
	int v8;     // ecx
	int v9;     // eax
	int v10;    // eax
	int v11;    // eax
	char v12;   // al
	int v13;    // eax
	int v14;    // [esp-10h] [ebp-24h]
	int v15;    // [esp-Ch] [ebp-20h]
	int v16;    // [esp-8h] [ebp-1Ch]
	int v17;    // [esp-4h] [ebp-18h]
	float2 v18; // [esp+Ch] [ebp-8h]

	v1 = a1[3];
	if (!v1)
		return 1;
	if (*(_BYTE*)(v1 + 16) & 0x20)
		return 1;
	v2 = a1[12];
	if (!v2 || *(_DWORD*)(v2 + 16) & 0x8020 || v2 != v1 && !a1[5])
		return 1;
	if (a1[17] - 1 != *(_DWORD*)&byte_5D4594[2598000])
		return 0;
	if (sub_4FF350(v2, 14)) {
		sub_501960(231, a1[12], 0, 0);
		return 1;
	}
	v4 = a1[3];
	if (*(_BYTE*)(v4 + 8) & 4) {
		v5 = *(_DWORD*)(v4 + 748);
		v6 = a1[1] - 122;
		v7 = *(_DWORD*)(v5 + 4 * v6 + 116);
		if (!v7)
			return 1;
		v8 = a1[12];
		v18 = *(float2*)(v8 + 56);
		sub_530560(v8, (int*)(v8 + 56), (_DWORD*)(v7 + 56));
		v14 = a1[12];
		v9 = sub_424800(a1[1], 1);
		sub_501960(v9, v14, 0, 0);
		sub_4E7190((_BYTE*)a1[12], (float*)(*(_DWORD*)(v5 + 4 * v6 + 116) + 56));
		if (sub_4FF350(a1[12], 0)) {
			v10 = a1[12];
			if (!(*(_BYTE*)(v10 + 8) & 4))
				goto LABEL_18;
			v17 = *(_DWORD*)(v10 + 36);
			v16 = 2;
			v15 = a1[12];
		} else {
			sub_522FF0(137, &v18);
			sub_522FF0(137, (float2*)(a1[12] + 56));
			v17 = 0;
			v16 = 0;
			v15 = a1[12];
		}
		v11 = sub_424800(a1[1], 1);
		sub_501960(v11, v15, v16, v17);
	LABEL_18:
		*(_DWORD*)(*(_DWORD*)(v5 + 4 * v6 + 116) + 136) = *(_DWORD*)&byte_5D4594[2598000];
		v12 = *(_BYTE*)(v6 + v5 + 156) - 1;
		*(_BYTE*)(v6 + v5 + 156) = v12;
		if (!v12) {
			sub_522FF0(129, (float2*)(*(_DWORD*)(v5 + 4 * v6 + 116) + 56));
			sub_4E5CC0(*(_DWORD*)(v5 + 4 * v6 + 116));
			*(_DWORD*)(v5 + 4 * v6 + 116) = 0;
		}
	}
	v13 = a1[4];
	if (!v13 || *(_BYTE*)(v13 + 16) & 0x20)
		return 1;
	sub_4E7540(v13, a1[12]);
	return 1;
}

//----- (00530820) --------------------------------------------------------
int __cdecl sub_530820(int a1) {
	int result; // eax
	float v2;   // [esp+0h] [ebp-8h]

	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v2 = sub_419D70(&byte_587000[260856], *(_DWORD*)(a1 + 8) - 1);
		*(_DWORD*)(a1 + 68) = *(_DWORD*)&byte_5D4594[2598000] + nox_float2int(v2);
		result = 0;
	} else {
		result = 0;
		*(_DWORD*)(a1 + 68) = *(_DWORD*)&byte_5D4594[2598000] + 1;
	}
	return result;
}

//----- (00530880) --------------------------------------------------------
int __cdecl sub_530880(int* a1) {
	int v1;     // eax
	int v2;     // eax
	int v4;     // eax
	int v5;     // edi
	int v6;     // edx
	int v7;     // ecx
	_DWORD* v8; // eax
	int v9;     // eax
	int v10;    // esi
	int v11;    // eax
	char v12;   // al
	int v13;    // [esp-Ch] [ebp-20h]
	float2 v14; // [esp+Ch] [ebp-8h]

	v1 = a1[4];
	if (!v1)
		return 1;
	if (*(_DWORD*)(v1 + 16) & 0x8020)
		return 1;
	v2 = a1[12];
	if (!v2 || *(_DWORD*)(v2 + 16) & 0x8020)
		return 1;
	if (a1[17] - 1 != *(_DWORD*)&byte_5D4594[2598000])
		return 0;
	if (sub_4FF350(v2, 14)) {
		sub_501960(231, a1[12], 0, 0);
		return 1;
	}
	v4 = a1[4];
	if (*(_BYTE*)(v4 + 8) & 4) {
		v5 = *(_DWORD*)(v4 + 748);
		v6 = 0;
		v7 = 4;
		v8 = (_DWORD*)(v5 + 116);
		do {
			if (*v8)
				++v6;
			++v8;
			--v7;
		} while (v7);
		if (!v6)
			return 1;
		v9 = a1[12];
		v14 = *(float2*)(a1[12] + 56);
		do
			v10 = nox_common_randomInt_415FA0(0, 3);
		while (!*(_DWORD*)(v5 + 4 * v10 + 116));
		sub_530560(a1[12], (int*)(a1[12] + 56), (_DWORD*)(*(_DWORD*)(v5 + 4 * v10 + 116) + 56));
		sub_4E7190((_BYTE*)a1[12], (float*)(*(_DWORD*)(v5 + 4 * v10 + 116) + 56));
		if (!sub_4FF350(a1[12], 0)) {
			sub_522FF0(137, &v14);
			sub_522FF0(137, (float2*)(a1[12] + 56));
		}
		v13 = a1[12];
		v11 = sub_424800(a1[1], 0);
		sub_501960(v11, v13, 0, 0);
		v12 = *(_BYTE*)(v10 + v5 + 156) - 1;
		*(_BYTE*)(v10 + v5 + 156) = v12;
		if (!v12) {
			sub_522FF0(129, (float2*)(*(_DWORD*)(v5 + 4 * v10 + 116) + 56));
			sub_4E5CC0(*(_DWORD*)(v5 + 4 * v10 + 116));
			*(_DWORD*)(v5 + 4 * v10 + 116) = 0;
		}
	}
	sub_4E7540(a1[4], a1[12]);
	return 1;
}

//----- (00530B70) --------------------------------------------------------
int __cdecl sub_530B70(int* a1) {
	int v1;  // ecx
	int v2;  // eax
	int v4;  // eax
	int v5;  // eax
	int v6;  // eax
	int v7;  // [esp-Ch] [ebp-14h]
	int v8;  // [esp-Ch] [ebp-14h]
	int v9;  // [esp-8h] [ebp-10h]
	int v10; // [esp-4h] [ebp-Ch]

	v1 = a1[12];
	if (!v1)
		return 1;
	v2 = a1[4];
	if (!v2 || *(_DWORD*)(v1 + 16) & 0x8020 || *(_DWORD*)(v2 + 16) & 0x8020)
		return 1;
	if (a1[17] - 1 == *(_DWORD*)&byte_5D4594[2598000]) {
		if (sub_4FF350(v1, 14)) {
			sub_501960(231, a1[12], 0, 0);
			return 1;
		}
		sub_522FF0(137, (float2*)(a1[12] + 56));
		v7 = a1[12];
		v4 = sub_424800(a1[1], 0);
		sub_501960(v4, v7, 0, 0);
		sub_530560(a1[12], (int*)(a1[12] + 56), a1 + 13);
		sub_4E7190((_BYTE*)a1[12], (float*)a1 + 13);
		if (sub_4FF350(a1[12], 0)) {
			v6 = a1[12];
			if (!(*(_BYTE*)(v6 + 8) & 4)) {
			LABEL_14:
				sub_4E7540(a1[4], a1[12]);
				return 1;
			}
			v10 = *(_DWORD*)(v6 + 36);
			v9 = 2;
			v8 = a1[12];
			v5 = sub_424800(a1[1], 0);
		} else {
			sub_522FF0(137, (float2*)(a1[12] + 56));
			v10 = 0;
			v9 = 0;
			v8 = a1[12];
			v5 = sub_424800(a1[1], 0);
		}
		sub_501960(v5, v8, v9, v10);
		goto LABEL_14;
	}
	return 0;
}

//----- (00530CA0) --------------------------------------------------------
int __cdecl sub_530CA0(int a1) {
	int v1;     // ecx
	int v2;     // eax
	int v3;     // ecx
	int result; // eax
	float v5;   // [esp+0h] [ebp-8h]

	v1 = *(_DWORD*)(a1 + 16);
	if (!v1)
		return 1;
	if (*(_BYTE*)(a1 + 88) & 0x20)
		return 1;
	v2 = *(_DWORD*)(a1 + 48);
	if (!v2)
		return 1;
	if (*(_DWORD*)(v2 + 16) & 0x8020)
		return 1;
	if (v1 == v2)
		return 1;
	if (*(_BYTE*)(v2 + 8) & 2) {
		v3 = *(_DWORD*)(v2 + 12);
		if (v3 & 0x4000)
			return 1;
	}
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v5 = sub_419D70(&byte_587000[260992], *(_DWORD*)(a1 + 8) - 1);
		*(_DWORD*)(a1 + 68) = *(_DWORD*)&byte_5D4594[2598000] + nox_float2int(v5);
		result = 0;
	} else {
		result = 0;
		*(_DWORD*)(a1 + 68) = *(_DWORD*)&byte_5D4594[2598000] + 1;
	}
	return result;
}

//----- (00530D30) --------------------------------------------------------
int __cdecl sub_530D30(int* a1) {
	int* v1;    // esi
	int v2;     // ecx
	int v3;     // eax
	int result; // eax
	int v5;     // eax
	int v6;     // ecx
	float2* v7; // ecx
	int v8;     // eax
	int v9;     // eax
	int v10;    // eax
	int v11;    // [esp-Ch] [ebp-24h]
	int v12;    // [esp-Ch] [ebp-24h]
	float* v13; // [esp-4h] [ebp-1Ch]
	float4 v14; // [esp+8h] [ebp-10h]
	int v18;    // [esp+1Ch] [ebp+4h]

	v1 = a1;
	v2 = a1[12];
	if (!v2)
		return 1;
	v3 = a1[4];
	if (!v3 || *(_DWORD*)(v2 + 16) & 0x8020 || *(_DWORD*)(v3 + 16) & 0x8020)
		return 1;
	if (a1[17] - 1 != *(_DWORD*)&byte_5D4594[2598000])
		return 0;
	if (sub_4FF350(v2, 14) || sub_4FF350(a1[4], 14)) {
		sub_501960(231, a1[12], 0, 0);
		sub_501960(231, a1[4], 0, 0);
		result = 1;
	} else {
		if (a1[5])
			goto LABEL_23;
		if (!sub_5370E0(a1[4], a1[12], 0)) {
			sub_4DA2C0(a1[4], "ExecDur.c:NeedClearLOSForSwap", 0);
			return 1;
		}
		v5 = a1[4];
		if (!(*(_BYTE*)(v5 + 8) & 4) ||
		    (v6 = *(_DWORD*)(v5 + 748),
		     v14.field_0 = *(float*)(v5 + 56) - (double)*(unsigned __int16*)(*(_DWORD*)(v6 + 276) + 10),
		     v14.field_4 = *(float*)(v5 + 60) - (double)*(unsigned __int16*)(*(_DWORD*)(v6 + 276) + 12),
		     v14.field_8 = (double)*(unsigned __int16*)(*(_DWORD*)(v6 + 276) + 10) + *(float*)(v5 + 56),
		     v18 = *(unsigned __int16*)(*(_DWORD*)(v6 + 276) + 12), v7 = (float2*)(v1[12] + 56),
		     v14.field_C = (double)v18 + *(float*)(v5 + 60), sub_428220(v7, &v14))) {
		LABEL_23:
			v8 = v1[12];
			v14.field_0 = *(float*)(v8 + 56);
			v13 = (float*)(v1[4] + 56);
			v14.field_4 = *(float*)(v8 + 60);
			sub_4E7190((_BYTE*)v8, v13);
			sub_4E7190((_BYTE*)v1[4], &v14);
			if (!sub_4FF350(v1[12], 0) && !sub_4FF350(v1[4], 0)) {
				sub_522FF0(137, (float2*)(v1[4] + 56));
				sub_522FF0(137, (float2*)(v1[12] + 56));
			}
			v11 = v1[12];
			v9 = sub_424800(v1[1], 0);
			sub_501960(v9, v11, 0, 0);
			v12 = v1[4];
			v10 = sub_424800(v1[1], 0);
			sub_501960(v10, v12, 0, 0);
			sub_4E7540(v1[4], v1[12]);
			result = 1;
		} else {
			sub_4DA2C0(v1[4], "ExecDur.c:NeedClearLOSForSwap", 0);
			result = 1;
		}
	}
	return result;
}

//----- (00530F90) --------------------------------------------------------
int __cdecl sub_530F90(_DWORD* a1) {
	int v1;     // ecx
	_DWORD* v2; // ebx
	float v4;   // [esp+0h] [ebp-10h]
	float v5;   // [esp+0h] [ebp-10h]

	if (!*(_DWORD*)&byte_5D4594[2487920])
		*(_DWORD*)&byte_5D4594[2487920] = sub_4E3AA0((CHAR*)&byte_587000[261072]);
	v4 = sub_419D70(&byte_587000[261088], a1[2] - 1);
	a1[18] = nox_float2int(v4);
	a1[19] = 0;
	a1[21] = 0;
	v1 = a1[4];
	if (v1 && !(*(_BYTE*)(v1 + 8) & 4) || a1[5]) {
		v5 = sub_419D40(&byte_587000[261108]);
		a1[17] = *(_DWORD*)&byte_5D4594[2598000] + nox_float2int(v5);
	} else {
		sub_4FF380(v1, 5, 10 * *(_WORD*)&byte_5D4594[2649704], 5);
		sub_4FF380(a1[4], 14, 10 * *(_WORD*)&byte_5D4594[2649704], 5);
		sub_4FF380(a1[4], 29, 10 * *(_WORD*)&byte_5D4594[2649704], 5);
		a1[20] = *(_DWORD*)(a1[4] + 120);
		*(_DWORD*)(a1[4] + 120) = 1203982323;
		*(_DWORD*)(a1[4] + 84) = 0;
		*(_DWORD*)(a1[4] + 80) = 0;
		*(_DWORD*)(a1[4] + 92) = 0;
		*(_DWORD*)(a1[4] + 88) = 0;
		*(_DWORD*)(a1[4] + 100) = 0;
		*(_DWORD*)(a1[4] + 96) = 0;
	}
	v2 = sub_4E3450(*(int*)&byte_5D4594[2487920]);
	if (v2) {
		sub_4DAA50((int)v2, 0, *((float*)a1 + 7), *((float*)a1 + 8));
		a1[19] = v2;
	}
	return 0;
}

//----- (005310C0) --------------------------------------------------------
int __cdecl sub_5310C0(int* a1) {
	int v1;     // edi
	int v2;     // eax
	int v4;     // eax
	bool v5;    // zf
	int v6;     // edi
	float v7;   // edx
	int v8;     // eax
	int v9;     // eax
	float v10;  // [esp+0h] [ebp-28h]
	float v11;  // [esp+4h] [ebp-24h]
	int v12;    // [esp+10h] [ebp-18h]
	float v13;  // [esp+14h] [ebp-14h]
	float v14;  // [esp+14h] [ebp-14h]
	float2 v15; // [esp+20h] [ebp-8h]

	v1 = 0;
	v2 = a1[4];
	if (!v2 && !a1[5])
		return 1;
	if (a1[17] - 1 == *(_DWORD*)&byte_5D4594[2598000])
		v1 = 1;
	if (v2 && *(_BYTE*)(v2 + 8) & 4 && !sub_4EEC80(a1[4]))
		v1 = 1;
	if (a1[19]) {
		if (!a1[5] && (v4 = a1[4]) != 0 && *(_BYTE*)(v4 + 8) & 4) {
			if ((unsigned __int16)sub_4EEC80(a1[4]) >= 0xFu)
				goto LABEL_18;
		} else if ((unsigned int)(a1[17] - *(_DWORD*)&byte_5D4594[2598000]) >= 0xA) {
			goto LABEL_18;
		}
		sub_4E5CC0(a1[19]);
		a1[19] = 0;
	}
LABEL_18:
	v5 = v1 == 0;
	v6 = a1[18];
	if (!v5) {
		if (a1[5]) {
			v7 = *((float*)a1 + 8);
			v15.field_0 = *((float*)a1 + 7);
		} else {
			v8 = a1[4];
			if (!v8)
				return 1;
			v15.field_0 = *(float*)(v8 + 56);
			v7 = *(float*)(v8 + 60);
		}
		v15.field_4 = v7;
		sub_4E25A0(1);
		v12 = a1[4];
		v11 = sub_419D40(&byte_587000[261132]);
		v10 = sub_419D40(&byte_587000[261152]);
		sub_4E25B0(&v15, v10, v11, v6, 15, v12, 0);
		v13 = sub_419D40(&byte_587000[261172]);
		v9 = nox_float2int(v13);
		sub_4D9110(&v15, v9);
		sub_522FF0(129, &v15);
		sub_522FF0(154, &v15);
		sub_501960(81, a1[4], 0, 0);
		a1[21] = 1;
		return 1;
	}
	v14 = sub_419D70(&byte_587000[261192], a1[2] - 1);
	a1[18] = v6 + nox_float2int(v14);
	if (!a1[5]) {
		if (sub_4E7BC0(a1[4]))
			sub_4EEBF0(a1[4], a1[2]);
	}
	return 0;
}

//----- (00531290) --------------------------------------------------------
int __cdecl sub_531290(int a1) {
	int v1;     // eax
	int result; // eax

	if (*(_DWORD*)(a1 + 76)) {
		sub_4E5CC0(*(_DWORD*)(a1 + 76));
		*(_DWORD*)(a1 + 76) = 0;
	}
	if (!*(_DWORD*)(a1 + 20)) {
		v1 = *(_DWORD*)(a1 + 16);
		if (v1) {
			if (*(_BYTE*)(v1 + 8) & 4) {
				sub_4FF5B0(v1, 5);
				sub_4FF5B0(*(_DWORD*)(a1 + 16), 14);
				sub_4FF5B0(*(_DWORD*)(a1 + 16), 29);
				*(_DWORD*)(*(_DWORD*)(a1 + 16) + 120) = *(_DWORD*)(a1 + 80);
			}
		}
	}
	result = *(_DWORD*)(a1 + 84);
	if (!result)
		result = sub_522FF0(163, (float2*)(a1 + 28));
	return result;
}

//----- (00531310) --------------------------------------------------------
int __cdecl sub_531310(_DWORD* a1) {
	int v1;     // ecx
	int v2;     // edi
	_DWORD* v3; // eax
	_DWORD* v4; // esi
	int v5;     // eax
	double v6;  // st7
	float v8;   // [esp+0h] [ebp-18h]
	float2 v9;  // [esp+10h] [ebp-8h]

	v8 = sub_419D70(&byte_587000[261212], a1[2] - 1);
	a1[18] = nox_float2int(v8);
	if (!*(_DWORD*)&byte_5D4594[2487924])
		*(_DWORD*)&byte_5D4594[2487924] = sub_4E3AA0((CHAR*)&byte_587000[261236]);
	if (a1[5])
		v1 = a1[6];
	else
		v1 = a1[4];
	v2 = 0;
	v9 = *(float2*)(v1 + 56);
	do {
		v3 = sub_4E3450(*(int*)&byte_5D4594[2487924]);
		v4 = v3;
		if (v3) {
			*(_DWORD*)v3[175] = a1;
			sub_4DAA50((int)v3, a1[4], v9.field_0, v9.field_4);
			*((_WORD*)v4 + 63) = v2;
			v5 = 8 * (__int16)v2;
			*((_WORD*)v4 + 62) = v2;
			*((float*)v4 + 20) = *(float*)&byte_587000[v5 + 194136] * 4.0;
			v6 = *(float*)&byte_587000[v5 + 194140] * 4.0;
			v4[28] = 0;
			*((float*)v4 + 21) = v6;
		}
		v2 += 6;
	} while (v2 < 256);
	sub_522FF0(160, &v9);
	return 0;
}

//----- (00531410) --------------------------------------------------------
int sub_531410() { return 0; }

//----- (00531420) --------------------------------------------------------
int __cdecl sub_531420(int a1) {
	int result; // eax
	int i;      // esi

	if (!*(_DWORD*)&byte_5D4594[2487928])
		*(_DWORD*)&byte_5D4594[2487928] = sub_4E3AA0((CHAR*)&byte_587000[261252]);
	result = sub_4DA790();
	for (i = result; result; i = result) {
		if (*(unsigned __int16*)(i + 4) == *(_DWORD*)&byte_5D4594[2487928] && **(_DWORD**)(i + 700) == a1)
			sub_4E5CC0(i);
		result = sub_4DA7A0(i);
	}
	return result;
}

//----- (00531490) --------------------------------------------------------
int __cdecl sub_531490(_DWORD* a1) {
	int v1;     // eax
	int v2;     // edi
	int result; // eax

	v1 = a1[12];
	v2 = 20 * a1[2] * *(_DWORD*)&byte_5D4594[2649704];
	if (!v1)
		return 1;
	if (!(*(_BYTE*)(v1 + 8) & 4))
		return 1;
	sub_4FF310(a1[12]);
	sub_4FF380(a1[12], 27, v2, a1[2]);
	result = 0;
	a1[17] = v2 + *(_DWORD*)&byte_5D4594[2598000];
	return result;
}

//----- (005314F0) --------------------------------------------------------
BOOL __cdecl sub_5314F0(int a1) {
	int v1;      // eax
	BOOL result; // eax
	int v3;      // eax

	v1 = *(_DWORD*)(a1 + 48);
	if (!v1)
		return 1;
	if (sub_4FF350(v1, 8))
		return 1;
	v3 = *(_DWORD*)(a1 + 48);
	if (v3 && *(_BYTE*)(v3 + 8) & 2 && sub_4FEA70(v3, (float2*)(a1 + 28)))
		result = 1;
	else
		result = (*(_DWORD*)(*(_DWORD*)(a1 + 48) + 16) & 0x8020) != 0;
	return result;
}

//----- (00531560) --------------------------------------------------------
int __cdecl sub_531560(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 48);
	if (result)
		result = sub_4FF5B0(result, 27);
	return result;
}

//----- (00531580) --------------------------------------------------------
int __cdecl sub_531580(int a1) {
	int v1; // eax
	int v2; // eax

	*(_DWORD*)(a1 + 72) = 0;
	*(_DWORD*)(a1 + 76) = 0;
	*(_DWORD*)(a1 + 48) = 0;
	sub_522FF0(131, (float2*)(a1 + 28));
	v1 = *(_DWORD*)(a1 + 16);
	if (!v1 || !(*(_BYTE*)(v1 + 8) & 4))
		return 0;
	v2 = *(_DWORD*)(*(_DWORD*)(v1 + 748) + 104);
	if (v2 && *(_DWORD*)(v2 + 12) & 0x4000000) {
		if (*(_BYTE*)(*(_DWORD*)(v2 + 736) + 96) & 4) {
			*(_DWORD*)(a1 + 72) = v2;
			*(_BYTE*)(a1 + 88) |= 2u;
		}
		return 0;
	}
	return 1;
}

//----- (00531600) --------------------------------------------------------
int __cdecl sub_531600(int a1) {
	int v1;              // eax
	int v2;              // eax
	int v3;              // edi
	int v4;              // eax
	int v5;              // eax
	int v6;              // ecx
	int v7;              // eax
	int v8;              // eax
	double v9;           // st7
	int v10;             // eax
	int v11;             // eax
	int v12;             // eax
	int v13;             // edi
	unsigned __int8 v14; // al
	unsigned __int8 v15; // al
	int v16;             // eax
	int v17;             // ebp
	_DWORD* v19;         // [esp-4h] [ebp-18h]
	float v20;           // [esp+0h] [ebp-14h]
	float v21;           // [esp+0h] [ebp-14h]

	if (!*(_DWORD*)&byte_5D4594[2487936]) {
		*(_DWORD*)&byte_5D4594[2487936] = sub_4E3AA0((CHAR*)&byte_587000[261268]);
		*(_DWORD*)&byte_5D4594[2487940] = sub_4E3AA0((CHAR*)&byte_587000[261276]);
	}
	v1 = *(_DWORD*)(a1 + 16);
	if (!v1 || *(_BYTE*)(a1 + 88) & 0x20 || *(_BYTE*)(v1 + 8) & 2 && sub_4FEA70(v1, (float2*)(a1 + 28)))
		return 1;
	v2 = *(_DWORD*)(a1 + 48);
	if (!v2)
		goto LABEL_16;
	if (*(_DWORD*)(v2 + 16) & 0x8020)
		goto LABEL_53;
	if (nox_server_testTwoPointsAndDirection_4E6E50((float2*)(*(_DWORD*)(a1 + 16) + 56),
							*(__int16*)(*(_DWORD*)(a1 + 16) + 124), (float2*)(v2 + 56)) &
	    2) {
		if (!*(_DWORD*)(a1 + 76))
			*(_DWORD*)(a1 + 76) = 3 * *(_DWORD*)&byte_5D4594[2649704];
	} else {
		*(_DWORD*)(a1 + 76) = 0;
	}
	if (sub_4E6C00(*(_DWORD*)(a1 + 48), *(_DWORD*)(a1 + 16)) > 400.0 ||
	    !sub_5370E0(*(_DWORD*)(a1 + 16), *(_DWORD*)(a1 + 48), 0)) {
	LABEL_53:
		*(_DWORD*)(a1 + 48) = 0;
	LABEL_16:
		v3 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 16) + 748) + 288);
		*(_DWORD*)&byte_5D4594[2487932] = 0;
		if (!v3)
			goto LABEL_54;
		if (sub_5330C0(*(_DWORD*)(a1 + 16), v3) && sub_4E6C00(*(_DWORD*)(a1 + 16), v3) <= 400.0)
			*(_DWORD*)&byte_5D4594[2487932] = v3;
		if (!*(_DWORD*)&byte_5D4594[2487932]) {
		LABEL_54:
			*(_DWORD*)&byte_587000[260404] = 1209810944;
			sub_517F90((float2*)(*(_DWORD*)(a1 + 16) + 56), 400.0, sub_531920, *(_DWORD*)(a1 + 16));
		}
		*(_DWORD*)(a1 + 48) = *(_DWORD*)&byte_5D4594[2487932];
		*(_DWORD*)(a1 + 76) = 0;
	}
	v4 = *(_DWORD*)(a1 + 76);
	if (v4) {
		v5 = v4 - 1;
		*(_DWORD*)(a1 + 76) = v5;
		if (!v5)
			*(_DWORD*)(a1 + 48) = 0;
	}
	v6 = *(_DWORD*)(a1 + 48);
	v7 = *(_DWORD*)(a1 + 36);
	if (v6) {
		if (v6 != v7) {
			if (v7)
				sub_4FEF90(a1, *(_DWORD**)(a1 + 36));
			sub_4FF130(a1);
		}
		v8 = *(unsigned __int16*)(*(_DWORD*)(a1 + 48) + 4);
		if ((unsigned __int16)v8 == *(_DWORD*)&byte_5D4594[2487936] || v8 == *(_DWORD*)&byte_5D4594[2487940])
			v9 = sub_419D40(&byte_587000[261292]);
		else
			v9 = sub_419D40(&byte_587000[261312]);
		v20 = v9;
		v10 = nox_float2int(v20);
		(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD, int, int))(*(_DWORD*)(a1 + 48) + 716))(
		    *(_DWORD*)(a1 + 48), *(_DWORD*)(a1 + 16), 0, v10, 14);
		v11 = *(_DWORD*)(a1 + 48);
		if (*(_DWORD*)(v11 + 16) & 0x8020)
			sub_522FF0(131, (float2*)(v11 + 56));
		v19 = *(_DWORD**)(a1 + 16);
		*(_DWORD*)(a1 + 36) = *(_DWORD*)(a1 + 48);
		sub_4FA020(v19, 22);
		if (!(*(_DWORD*)&byte_5D4594[2598000] % (*(_DWORD*)&byte_5D4594[2649704] / 3u))) {
			sub_501960(98, *(_DWORD*)(a1 + 16), 0, 0);
			sub_501960(98, *(_DWORD*)(a1 + 48), 0, 0);
		}
		if (!*(_DWORD*)(a1 + 76)) {
			v21 = sub_419D40(&byte_587000[261328]);
			*(_DWORD*)(a1 + 68) = *(_DWORD*)&byte_5D4594[2598000] + nox_float2int(v21);
		}
		v12 = *(_DWORD*)(a1 + 72);
		if (v12) {
			v13 = *(_DWORD*)(v12 + 736);
			v14 = *(_BYTE*)(v13 + 108);
			if (v14 <= 0u)
				return 1;
			v15 = v14 - 1;
			*(_BYTE*)(v13 + 108) = v15;
			*(_DWORD*)(v13 + 112) = 100 * v15 / *(unsigned __int8*)(v13 + 109);
			v16 = *(_DWORD*)(a1 + 16);
			if (v16) {
				if (*(_BYTE*)(v16 + 8) & 4) {
					v17 = *(_DWORD*)(v16 + 748);
					sub_4FA020((_DWORD*)v16, 22);
					sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(v17 + 276) + 2064),
						   *(_DWORD**)(a1 + 72), *(_BYTE*)(v13 + 108), *(_BYTE*)(v13 + 109));
				}
			}
			if (*(_BYTE*)(v13 + 108) <= 0u)
				return 1;
		}
	} else if (v7) {
		sub_4FEF90(a1, *(_DWORD**)(a1 + 36));
		*(_DWORD*)(a1 + 36) = 0;
	}
	return 0;
}

//----- (00531920) --------------------------------------------------------
void __cdecl sub_531920(int a1, int a2) {
	int v2;    // eax
	int v3;    // eax
	double v4; // st7
	double v5; // st6
	double v6; // st5

	v2 = *(_DWORD*)(a1 + 8);
	if (v2 & 0x20006) {
		if (!(*(_DWORD*)(a1 + 16) & 0x8020) && a1 != a2) {
			if (!(v2 & 2) || (v3 = *(_DWORD*)(a1 + 12), (v3 & 0x8000) == 0)) {
				if (sub_5330C0(a2, a1) &&
				    nox_server_testTwoPointsAndDirection_4E6E50(
					(float2*)(a2 + 56), *(__int16*)(a2 + 124), (float2*)(a1 + 56)) &
					    1 |
					0xC &&
				    sub_5370E0(a2, a1, 0)) {
					v4 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
					v5 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
					v6 = v5 * v5 + v4 * v4;
					if (v6 < *(float*)&byte_587000[260404]) {
						*(float*)&byte_587000[260404] = v6;
						*(_DWORD*)&byte_5D4594[2487932] = a1;
					}
				}
			}
		}
	}
}

//----- (005319E0) --------------------------------------------------------
int __cdecl sub_5319E0(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 72);
	if (result) {
		result = *(_DWORD*)(result + 736);
		*(_DWORD*)(result + 96) &= 0xFFFFFFFB;
	}
	return result;
}

//----- (00531A00) --------------------------------------------------------
int __cdecl sub_531A00(_DWORD* a1) {
	__int16 v1; // di
	int v2;     // eax
	_DWORD* v3; // eax
	int v4;     // ecx
	int v5;     // edx
	float v7;   // [esp+0h] [ebp-14h]
	float v8;   // [esp+Ch] [ebp-8h]
	float v9;   // [esp+10h] [ebp-4h]

	v7 = sub_419D40(&byte_587000[261348]);
	v1 = nox_float2int(v7);
	v2 = a1[12];
	if (!v2 || *(_DWORD*)(v2 + 16) & 0x8020)
		return 1;
	if ((*(_BYTE*)(v2 + 8) & 4) != 4) {
		sub_4FF380(v2, 15, v1, a1[2]);
		return 1;
	}
	v3 = sub_4E3810((CHAR*)&byte_587000[261376]);
	a1[18] = v3;
	if (!v3)
		return 1;
	v4 = a1[12];
	v5 = *(_DWORD*)(*(_DWORD*)(v4 + 748) + 276);
	if (*(_BYTE*)(v5 + 3680) & 0x10) {
		v8 = (double)*(int*)(v5 + 2284);
		v9 = (double)*(int*)(v5 + 2288);
	} else {
		v8 = 2944.0;
		v9 = 2944.0;
	}
	sub_4DAA50((int)v3, v4, v8, v9);
	sub_4FF380(a1[12], 1, v1, a1[2]);
	return 0;
}

//----- (00531AF0) --------------------------------------------------------
int __cdecl sub_531AF0(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 48);
	if (result) {
		if ((*(_BYTE*)(result + 8) & 4) == 4) {
			if (*(_DWORD*)(a1 + 72))
				sub_4E5CC0(*(_DWORD*)(a1 + 72));
			*(_DWORD*)(a1 + 72) = 0;
			result = sub_4FF5B0(*(_DWORD*)(a1 + 48), 1);
		} else {
			result = sub_4FF5B0(result, 15);
		}
	}
	return result;
}

//----- (00531B40) --------------------------------------------------------
int* __cdecl sub_531B40(int a1, int a2) {
	int v2;         // ebx
	int* result;    // eax
	BOOL v4;        // eax
	long double v5; // st7
	int v6;         // [esp-8h] [ebp-14h]
	int v7;         // [esp-4h] [ebp-10h]

	v2 = *(_DWORD*)(a1 + 748);
	if (sub_4FF350(a1, 29) || (result = (int*)sub_540D90(a1, a2)) == 0) {
		if (sub_534280(a1)) {
			v4 = sub_534220(a1);
			v7 = a2;
			v6 = a1;
			if (v4 && (v5 = sub_4E6C00(a1, a2), v7 = a2, v6 = a1,
				   v5 < *(float*)(*(_DWORD*)(v2 + 484) + 212) * 0.5))
				result = sub_531C60(a1, a2);
			else
				result = sub_531D50(v6, v7);
		} else if (sub_534220(a1)) {
			result = sub_531C60(a1, a2);
		} else {
			result = (int*)sub_534300(a1);
			if (!result)
				result = sub_531C10(a1, a2);
		}
	}
	return result;
}

//----- (00531C10) --------------------------------------------------------
int* __cdecl sub_531C10(int a1, int a2) {
	int* v2;     // eax
	int* v3;     // eax
	int* result; // eax

	v2 = sub_50A260(a1, 60);
	if (v2)
		v2[1] = a2;
	v3 = sub_50A260(a1, 42);
	if (v3)
		v3[1] = a2;
	result = sub_50A260(a1, 7);
	if (result) {
		result[1] = *(_DWORD*)(a2 + 56);
		result[2] = *(_DWORD*)(a2 + 60);
		result[3] = a2;
	}
	return result;
}

//----- (00531C60) --------------------------------------------------------
int* __cdecl sub_531C60(int a1, int a2) {
	int v2;      // ebx
	int* v3;     // eax
	int* v4;     // eax
	int* v5;     // eax
	double v6;   // st7
	int* v7;     // eax
	int* v8;     // eax
	int* v9;     // eax
	int v10;     // ecx
	int* result; // eax

	v2 = *(_DWORD*)(a1 + 748);
	v3 = sub_50A260(a1, 60);
	if (v3)
		v3[1] = a2;
	v4 = sub_50A260(a1, 42);
	if (v4)
		v4[1] = a2;
	if (sub_534280(a1)) {
		v5 = sub_50A260(a1, 50);
		if (v5) {
			v6 = *(float*)(*(_DWORD*)(v2 + 484) + 212) * 0.60000002;
			v5[3] = a2;
			*((float*)v5 + 1) = v6;
		}
	}
	v7 = sub_50A260(a1, 45);
	if (v7)
		v7[1] = a2;
	sub_50A260(a1, 16);
	v8 = sub_50A260(a1, 26);
	if (v8)
		v8[1] = a2;
	v9 = sub_50A260(a1, 49);
	if (v9) {
		v10 = *(_DWORD*)(*(_DWORD*)(v2 + 484) + 112);
		v9[3] = a2;
		v9[1] = v10;
	}
	if (*(_BYTE*)(a1 + 12) & 0x10) {
		sub_50A260(a1, 65);
		sub_50A260(a1, 40);
	}
	result = sub_50A260(a1, 7);
	if (result) {
		result[1] = *(_DWORD*)(a2 + 56);
		result[2] = *(_DWORD*)(a2 + 60);
		result[3] = a2;
	}
	return result;
}

//----- (00531D50) --------------------------------------------------------
int* __cdecl sub_531D50(int a1, int a2) {
	int v2;      // ebx
	int* v3;     // eax
	int* v4;     // eax
	int* v5;     // eax
	int* v6;     // eax
	int* result; // eax
	int* v8;     // eax
	int* v9;     // eax
	int v10;     // edx

	v2 = *(_DWORD*)(a1 + 748);
	v3 = sub_50A260(a1, 60);
	if (v3)
		v3[1] = a2;
	v4 = sub_50A260(a1, 45);
	if (v4)
		v4[1] = a2;
	v5 = sub_50A260(a1, 17);
	if (v5) {
		v5[1] = *(_DWORD*)(a2 + 56);
		v5[2] = *(_DWORD*)(a2 + 60);
		v5[3] = a2;
	}
	v6 = sub_50A260(a1, 26);
	if (v6)
		v6[1] = a2;
	result = (int*)sub_534710(a1);
	if (!result) {
		v8 = sub_50A260(a1, 47);
		if (v8)
			v8[1] = a2;
		v9 = sub_50A260(a1, 49);
		if (v9) {
			v10 = *(_DWORD*)(*(_DWORD*)(v2 + 484) + 212);
			v9[3] = a2;
			v9[1] = v10;
		}
		sub_50A260(a1, 40);
		result = sub_50A260(a1, 7);
		if (result) {
			result[1] = *(_DWORD*)(a2 + 56);
			result[2] = *(_DWORD*)(a2 + 60);
			result[3] = a2;
		}
	}
	return result;
}

//----- (00531E20) --------------------------------------------------------
int __cdecl sub_531E20(float a1) {
	int* v1; // edi
	int v2;  // eax
	int v3;  // eax

	v1 = *(int**)(LODWORD(a1) + 748);
	v2 = sub_424300(SLODWORD(a1));
	if (v2)
		sub_501960(*(_DWORD*)(v2 + 20), SLODWORD(a1), 0, 0);
	sub_502490(v1 + 310, v1[299], SLODWORD(a1));
	v3 = v1[360];
	BYTE1(v3) |= 1u;
	v1[360] = v3;
	sub_5281E0();
	sub_5281F0(a1);
	return sub_534750(SLODWORD(a1));
}

//----- (00531E90) --------------------------------------------------------
int __cdecl sub_531E90(int a1) {
	int v1; // eax
	int v2; // edx

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(_DWORD*)(v1 + 1440);
	BYTE1(v2) &= 0xFEu;
	*(_DWORD*)(v1 + 1440) = v2;
	return sub_534780(a1);
}

//----- (00531EC0) --------------------------------------------------------
char __cdecl sub_531EC0(int a1) {
	int v1;    // esi
	int v2;    // ebx
	int* v3;   // eax
	float* v4; // ebp
	double v5; // st7
	double v6; // st6

	v1 = *(_DWORD*)(a1 + 748);
	v2 = v1 + 24 * (*(char*)(v1 + 544) + 23);
	if (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v1 + 24 * (*(char*)(v1 + 544) + 23) + 12) >
	    (unsigned int)(10 * *(_DWORD*)&byte_5D4594[2649704]))
		goto LABEL_15;
	if (*(_DWORD*)(v1 + 1196)) {
		*(_DWORD*)(v2 + 12) = *(_DWORD*)&byte_5D4594[2598000];
		if (sub_528190(*(_DWORD*)(v1 + 1196))) {
			if (sub_4FF350(a1, 29) || (v3 = (int*)sub_540B90(a1)) == 0 &&
						      (v3 = (int*)sub_540F20(a1, *(_DWORD*)(v1 + 1196))) == 0) {
				LOBYTE(v3) = (unsigned int)sub_531B40(a1, *(_DWORD*)(v1 + 1196));
			}
			return (char)v3;
		}
	LABEL_15:
		LOBYTE(v3) = sub_50A160(a1);
		return (char)v3;
	}
	if (sub_534710(a1))
		goto LABEL_15;
	v4 = (float*)(v2 + 4);
	*(_DWORD*)&byte_5D4594[2487944] = 0;
	sub_517F90((float2*)(v2 + 4), 30.0, sub_532040, v1);
	if (*(_DWORD*)&byte_5D4594[2487944]) {
		sub_50A160(a1);
		v3 = *(int**)(v1 + 1200);
		if (*(int**)(v1 + 392) == v3)
			*(_DWORD*)(v1 + 388) = 0;
	} else {
		v5 = *v4 - *(float*)(a1 + 56);
		v6 = *(float*)(v2 + 8) - *(float*)(a1 + 60);
		if (v6 * v6 + v5 * v5 < 64.0)
			goto LABEL_15;
		sub_50A260(a1, 56);
		v3 = sub_50A260(a1, 7);
		if (v3) {
			v3[1] = *(_DWORD*)v4;
			v3[2] = *(_DWORD*)(v2 + 8);
			v3[3] = 0;
		}
	}
	return (char)v3;
}

//----- (00532040) --------------------------------------------------------
int __cdecl sub_532040(int a1, int a2) {
	int result; // eax
	int v3;     // ecx

	result = a1;
	if (*(_DWORD*)(a1 + 36) == *(_DWORD*)(a2 + 1200)) {
		v3 = *(_DWORD*)(a1 + 16);
		if ((v3 & 0x8000) != 0)
			*(_DWORD*)&byte_5D4594[2487944] = 1;
	}
	return result;
}

//----- (00532070) --------------------------------------------------------
char __cdecl sub_532070(int a1) {
	int v1;          // edi
	unsigned int v2; // eax

	v1 = *(_DWORD*)(a1 + 748) + 24 * (*(char*)(*(_DWORD*)(a1 + 748) + 544) + 23);
	if (sub_533E70(a1))
		*(_DWORD*)(v1 + 4) = *(_DWORD*)&byte_5D4594[2598000] + (*(_DWORD*)&byte_5D4594[2649704] >> 1);
	v2 = *(_DWORD*)(v1 + 4);
	if (*(_DWORD*)&byte_5D4594[2598000] > v2) {
		sub_50A160(a1);
		LOBYTE(v2) = *(_BYTE*)(a1 + 12);
		if (!(v2 & 0x10))
			LOBYTE(v2) = (unsigned int)sub_50A260(a1, 22);
	}
	return v2;
}

//----- (005320E0) --------------------------------------------------------
char __cdecl sub_5320E0(int a1) {
	char result; // al

	result = a1;
	if (*(_BYTE*)(*(_DWORD*)(a1 + 748) + 483))
		result = sub_50A160(a1);
	return result;
}

//----- (00532100) --------------------------------------------------------
char __cdecl sub_532100(int a1) { return sub_50A160(a1); }

//----- (00532110) --------------------------------------------------------
char __cdecl sub_532110(int a1) {
	char result; // al

	result = a1;
	if (*(_BYTE*)(*(_DWORD*)(a1 + 748) + 483))
		result = sub_50A160(a1);
	return result;
}

//----- (00532130) --------------------------------------------------------
int* __cdecl sub_532130(int a1) {
	int v1;      // edi
	int* v2;     // eax
	int* result; // eax
	int v4;      // eax
	double v5;   // st7
	int v6;      // eax
	int v7;      // ecx
	int v8;      // eax
	int* v9;     // eax
	int* v10;    // edi
	int v11;     // ecx
	int v12;     // ecx
	int v13;     // [esp-4h] [ebp-1Ch]
	float4 v14;  // [esp+8h] [ebp-10h]

	v1 = *(_DWORD*)(a1 + 748);
	if (*(_DWORD*)&byte_5D4594[2598000] >= *(int*)(v1 + 512)) {
		if (*(_BYTE*)(a1 + 12) & 0x10) {
			v4 = sub_4F7E80(*(_DWORD*)(v1 + 2056));
			if (v4 > *(unsigned __int8*)(v1 + 1128))
				*(_BYTE*)(v1 + 1128) -= v4;
			else
				*(_BYTE*)(v1 + 1128) = 0;
		}
		v14.field_0 = *(float*)(a1 + 56) - *(float*)&byte_587000[261388];
		v14.field_4 = *(float*)(a1 + 60) - *(float*)&byte_587000[261388];
		v14.field_8 = *(float*)&byte_587000[261388] + *(float*)(a1 + 56);
		v5 = *(float*)&byte_587000[261388] + *(float*)(a1 + 60);
		*(_DWORD*)&byte_5D4594[2487948] = 0;
		v14.field_C = v5;
		*(float*)&byte_5D4594[2487952] = *(float*)&byte_587000[261388] + 1.0;
		sub_517C10(&v14, (void(__cdecl*)(float*, int))sub_532390, a1);
		if (*(_DWORD*)&byte_5D4594[2487948] && !sub_5330C0(a1, *(int*)&byte_5D4594[2487948]) &&
		    *(_BYTE*)(a1 + 12) & 0x10 && (v6 = *(_DWORD*)(v1 + 2064)) != 0 &&
		    (v7 = *(_DWORD*)(v6 + 12), BYTE1(v7) & 0x40)) {
			v13 = *(_DWORD*)(a1 + 36);
			v8 = sub_4E39D0(a1);
			sub_5341A0((char*)&byte_587000[261392], *(_DWORD*)&byte_5D4594[2598000], v8, v13);
			sub_50A160(a1);
			v9 = sub_50A260(a1, 27);
			if (v9)
				v9[1] = *(__int16*)(a1 + 124);
			v10 = sub_50A260(a1, 41);
			if (v10)
				v10[1] = *(_DWORD*)&byte_5D4594[2598000] +
					 nox_common_randomInt_415FA0(*(_DWORD*)&byte_5D4594[2649704] >> 2,
								     *(_DWORD*)&byte_5D4594[2649704] >> 1);
			result = sub_50A260(a1, 24);
			if (result) {
				v11 = *(_DWORD*)&byte_5D4594[2487948] + 56;
				result[1] = *(_DWORD*)(*(_DWORD*)&byte_5D4594[2487948] + 56);
				v12 = *(_DWORD*)(v11 + 4);
				result[3] = 0;
				result[2] = v12;
			}
		} else {
			sub_5341D0(a1);
			*(_DWORD*)(a1 + 136) = *(_DWORD*)&byte_5D4594[2598000];
			*(_DWORD*)(v1 + 512) = *(_DWORD*)&byte_5D4594[2598000] +
					       nox_common_randomInt_415FA0(*(_DWORD*)(*(_DWORD*)(v1 + 484) + 128),
									   *(_DWORD*)(*(_DWORD*)(v1 + 484) + 132));
			result = (int*)sub_424300(a1);
			if (result)
				result = sub_501960(result[6], a1, 0, 0);
		}
	} else {
		v2 = sub_50A260(a1, 50);
		if (v2) {
			*((float*)v2 + 1) = *(float*)(*(_DWORD*)(v1 + 484) + 112) * 1.2;
			v2[3] = *(_DWORD*)(v1 + 1196);
		}
		result = sub_50A260(a1, 1);
		if (result)
			result[1] = *(_DWORD*)(v1 + 512);
	}
	return result;
}

//----- (00532390) --------------------------------------------------------
void __cdecl sub_532390(int a1, int a2) {
	int v2;    // ecx
	int v3;    // eax
	double v4; // st7
	double v5; // st6
	float* v6; // edx
	double v7; // st7
	float v8;  // [esp+4h] [ebp-4h]
	float v9;  // [esp+Ch] [ebp+4h]

	v2 = a1;
	if (*(_BYTE*)(a1 + 8) & 6) {
		v3 = *(_DWORD*)(a1 + 16);
		if ((v3 & 0x8000) == 0) {
			v4 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
			v5 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
			v8 = v5;
			v9 = sqrt(v5 * v8 + v4 * v4) + 0.000099999997;
			v7 = v4 / v9;
			if (v9 < (double)*(float*)&byte_5D4594[2487952]) {
				v6 = (float*)&byte_587000[8 * *(__int16*)(a2 + 124) + 194136];
				if (v8 / v9 * v6[1] + v7 * *v6 > 0.5) {
					*(_DWORD*)&byte_5D4594[2487948] = v2;
					*(float*)&byte_5D4594[2487952] = v9;
				}
			}
		}
	}
}

//----- (00532440) --------------------------------------------------------
char __cdecl sub_532440(int a1) {
	int v1;                 // edi
	BOOL v2;                // ebx
	int v3;                 // eax
	int v4;                 // ecx
	int(__cdecl * v5)(int); // eax
	int v6;                 // eax
	int v7;                 // ebx
	int v8;                 // eax
	int v10;                // [esp-4h] [ebp-10h]

	v1 = *(_DWORD*)(a1 + 748);
	if (*(_BYTE*)(a1 + 12) & 0x10) {
		if (*(_DWORD*)(v1 + 1440) & 0x20000)
			sub_4FAAF0((_DWORD*)a1);
		v2 = sub_538960(a1);
		v3 = *(_DWORD*)(v1 + 1440);
		if (v3 & 0x20000)
			LOBYTE(v3) = sub_4FAAC0((_DWORD*)a1);
		if (!v2)
			LOBYTE(v3) = sub_50A160(a1);
	} else {
		v4 = *(_DWORD*)(v1 + 484);
		v5 = *(int(__cdecl**)(int))(v4 + 236);
		if (v5) {
			if (*(unsigned __int8*)(v1 + 481) == *(_DWORD*)(v4 + 108) && !*(_BYTE*)(v1 + 482)) {
				v7 = v5(a1);
				v8 = sub_424300(a1);
				if (v8) {
					if (v7)
						sub_501960(*(_DWORD*)(v8 + 32), a1, 0, 0);
					else
						sub_501960(*(_DWORD*)(v8 + 36), a1, 0, 0);
				}
			}
			LOBYTE(v3) = *(_BYTE*)(v1 + 483);
			if ((_BYTE)v3)
				LOBYTE(v3) = sub_50A160(a1);
		} else {
			v10 = *(_DWORD*)(a1 + 36);
			v6 = sub_4E39D0(a1);
			sub_5341A0((char*)&byte_587000[261556], *(_DWORD*)&byte_5D4594[2598000], v6, v10);
			LOBYTE(v3) = sub_50A160(a1);
		}
	}
	return v3;
}

//----- (00532540) --------------------------------------------------------
_DWORD* __cdecl sub_532540(int a1) {
	_DWORD* v1;     // edi
	int* v2;        // eax
	_DWORD* result; // eax

	v1 = *(_DWORD**)(a1 + 748);
	if (*(_DWORD*)&byte_5D4594[2598000] >= v1[128]) {
		sub_5341D0(a1);
		*(_DWORD*)(a1 + 136) = *(_DWORD*)&byte_5D4594[2598000];
		v1[128] = *(_DWORD*)&byte_5D4594[2598000] +
			  nox_common_randomInt_415FA0(*(_DWORD*)(v1[121] + 220), *(_DWORD*)(v1[121] + 224));
		result = (_DWORD*)sub_424300(a1);
		if (result)
			result = sub_501960(result[10], a1, 0, 0);
	} else {
		v2 = sub_50A260(a1, 50);
		if (v2) {
			*((float*)v2 + 1) = *(float*)(v1[121] + 212) * 1.2;
			v2[3] = v1[299];
		}
		result = sub_50A260(a1, 1);
		if (result)
			result[1] = v1[128];
	}
	return result;
}

//----- (00532610) --------------------------------------------------------
char __cdecl sub_532610(int a1) {
	int v1;      // esi
	int v2;      // ebx
	int v3;      // eax
	int* v4;     // ebp
	int v5;      // eax
	float* v6;   // edi
	int v7;      // eax
	float v8;    // eax
	double v9;   // st7
	double v10;  // st6
	int v11;     // eax
	float v12;   // edx
	__int16 v13; // ax
	int v14;     // eax
	float v16;   // [esp+8h] [ebp-2Ch]
	float v17;   // [esp+Ch] [ebp-28h]
	float v18;   // [esp+10h] [ebp-24h]
	float v19;   // [esp+10h] [ebp-24h]
	float v20;   // [esp+14h] [ebp-20h]
	float v21;   // [esp+18h] [ebp-1Ch]
	float2 v22;  // [esp+1Ch] [ebp-18h]
	float4 v24;  // [esp+24h] [ebp-10h]
	float v25;   // [esp+38h] [ebp+4h]

	v1 = a1;
	v2 = *(_DWORD*)(a1 + 748);
	if (*(_BYTE*)(a1 + 12) & 0x10) {
		v3 = sub_538960(a1);
		if (!v3)
			LOBYTE(v3) = sub_50A160(a1);
	} else {
		v4 = (int*)(v2 + 24 * (*(char*)(v2 + 544) + 23));
		v5 = *(_DWORD*)(v2 + 484);
		if (*(unsigned __int8*)(v2 + 481) == *(_DWORD*)(v5 + 216) && !*(_BYTE*)(v2 + 482)) {
			v6 = (float*)sub_4E3810((CHAR*)(v5 + 148));
			if (v6) {
				v7 = v4[3];
				if (v7) {
					sub_533080(a1, v7, v6[136], (int)&v22);
				} else {
					v8 = *(float*)(&v4[2]);
					v22.field_0 = *(float*)(&v4[1]);
					v22.field_4 = v8;
				}
				v9 = v22.field_0 - *(float*)(a1 + 56);
				v10 = v22.field_4 - *(float*)(a1 + 60);
				v18 = v10;
				v11 = 8 * *(__int16*)(a1 + 124);
				v12 = *(float*)(a1 + 60);
				v24.field_0 = *(float*)(a1 + 56);
				v24.field_4 = v12;
				v25 = sqrt(v10 * v18 + v9 * v9) + 0.1;
				v16 = *(float*)(v1 + 176) + 4.0;
				v20 = v9 * v6[136] / v25;
				v21 = v18 * v6[136] / v25;
				v17 = v16 * *(float*)&byte_587000[v11 + 194136] + *(float*)(v1 + 56);
				v19 = v16 * *(float*)&byte_587000[v11 + 194140] + *(float*)(v1 + 60);
				v24.field_8 = v17 + v20;
				v24.field_C = v19 + v21;
				if (sub_535250(&v24, 0, 0, 5)) {
					sub_4DAA50((int)v6, v1, v17, v19);
					v6[20] = v20;
					v6[21] = v21;
					v13 = *(_WORD*)(v1 + 124);
					*((_WORD*)v6 + 62) = v13;
					*((_WORD*)v6 + 63) = v13;
				} else {
					sub_4E5CC0((int)v6);
				}
			}
			v14 = sub_424300(v1);
			if (v14)
				sub_501960(*(_DWORD*)(v14 + 44), v1, 0, 0);
		}
		LOBYTE(v3) = *(_BYTE*)(v2 + 483);
		if ((_BYTE)v3)
			LOBYTE(v3) = sub_50A160(v1);
	}
	return v3;
}

//----- (00532800) --------------------------------------------------------
char __cdecl sub_532800(int a1) {
	int v1; // eax
	int v2; // edi

	LOBYTE(v1) = *(_BYTE*)(a1 + 8);
	v2 = *(_DWORD*)(a1 + 748);
	if (v1 & 2) {
		LOBYTE(v1) = byte_5D4594[2598000];
		if (*(_DWORD*)&byte_5D4594[2598000] >= *(int*)(v2 + 532)) {
			*(_DWORD*)(v2 + 532) = *(_DWORD*)&byte_5D4594[2598000] +
					       nox_common_randomInt_415FA0(2 * *(_DWORD*)&byte_5D4594[2649704],
									   4 * *(_DWORD*)&byte_5D4594[2649704]);
			v1 = sub_424300(a1);
			if (v1)
				LOBYTE(v1) = (unsigned int)sub_501960(*(_DWORD*)(v1 + 8), a1, 0, 0);
		}
	}
	return v1;
}

//----- (00532880) --------------------------------------------------------
int __cdecl sub_532880(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 748);
	if (!*(_DWORD*)(result + 520))
		*(_DWORD*)(result + 520) = *(_DWORD*)&byte_5D4594[2598000];
	return result;
}

//----- (005328B0) --------------------------------------------------------
int __cdecl sub_5328B0(int a1, int a2) {
	unsigned __int16 v2; // di
	int i;               // esi

	v2 = 1;
	if (!a2)
		return 1;
	for (i = *(_DWORD*)(a1 + 504); i; i = *(_DWORD*)(i + 496)) {
		if (*(_DWORD*)(i + 8) & 0x2000000 && *(_BYTE*)(i + 12) & 4) {
			if (sub_4133D0(i)) {
				v2 = 0x2000;
			} else if (*(_WORD*)(i + 24) > v2) {
				v2 = *(_WORD*)(i + 24);
			}
		}
	}
	sub_532930(a1, v2, *(_WORD*)(a2 + 24));
	return 1;
}

//----- (00532930) --------------------------------------------------------
int __cdecl sub_532930(int a1, unsigned __int16 a2, unsigned __int16 a3) {
	int result; // eax

	result = a2;
	if ((int)a2 <= 32) {
		if (a2 == 32) {
			result = a3;
			if ((int)a3 > 16) {
				if (a3 == 32) {
					result = sub_501960(848, a1, 0, 0);
				} else if (a3 == 0x2000) {
					result = sub_501960(868, a1, 0, 0);
				}
			} else if (a3 == 16) {
				result = sub_501960(858, a1, 0, 0);
			} else {
				result = a3 - 1;
				switch (a3) {
				case 1u:
				case 2u:
				case 4u:
					result = sub_501960(863, a1, 0, 0);
					break;
				case 8u:
					result = sub_501960(853, a1, 0, 0);
					break;
				default:
					return result;
				}
			}
		} else {
			result = a2 - 1;
			switch (a2) {
			case 1u:
			case 2u:
			case 4u:
				result = a3;
				if ((int)a3 > 16) {
					if (a3 == 32) {
						result = sub_501960(852, a1, 0, 0);
					} else if (a3 == 0x2000) {
						result = sub_501960(872, a1, 0, 0);
					}
				} else if (a3 == 16) {
					result = sub_501960(862, a1, 0, 0);
				} else {
					result = a3 - 1;
					switch (a3) {
					case 1u:
					case 2u:
					case 4u:
						result = sub_501960(867, a1, 0, 0);
						break;
					case 8u:
						result = sub_501960(857, a1, 0, 0);
						break;
					default:
						return result;
					}
				}
				break;
			case 8u:
				result = a3;
				if ((int)a3 > 16) {
					if (a3 == 32) {
						result = sub_501960(850, a1, 0, 0);
					} else if (a3 == 0x2000) {
						result = sub_501960(870, a1, 0, 0);
					}
				} else if (a3 == 16) {
					result = sub_501960(860, a1, 0, 0);
				} else {
					result = a3 - 1;
					switch (a3) {
					case 1u:
					case 2u:
					case 4u:
						result = sub_501960(865, a1, 0, 0);
						break;
					case 8u:
						result = sub_501960(855, a1, 0, 0);
						break;
					default:
						return result;
					}
				}
				break;
			case 0x10u:
				result = a3;
				if ((int)a3 > 16) {
					if (a3 == 32) {
						result = sub_501960(851, a1, 0, 0);
					} else if (a3 == 0x2000) {
						result = sub_501960(871, a1, 0, 0);
					}
				} else if (a3 == 16) {
					result = sub_501960(861, a1, 0, 0);
				} else {
					result = a3 - 1;
					switch (a3) {
					case 1u:
					case 2u:
					case 4u:
						result = sub_501960(866, a1, 0, 0);
						break;
					case 8u:
						result = sub_501960(856, a1, 0, 0);
						break;
					default:
						return result;
					}
				}
				break;
			default:
				return result;
			}
		}
		return result;
	}
	if (a2 != 64 && a2 != 1024) {
		if (a2 != 0x2000)
			return result;
		result = a3;
		if ((int)a3 > 16) {
			if (a3 == 32)
				return sub_501960(868, a1, 0, 0);
			if (a3 != 0x2000)
				return result;
		} else if (a3 != 16) {
			result = a3 - 1;
			switch (a3) {
			case 1u:
			case 2u:
			case 4u:
				result = sub_501960(872, a1, 0, 0);
				break;
			case 8u:
				result = sub_501960(870, a1, 0, 0);
				break;
			default:
				return result;
			}
			return result;
		}
		return sub_501960(871, a1, 0, 0);
	}
	result = a3;
	if ((int)a3 > 16) {
		if (a3 == 32) {
			result = sub_501960(849, a1, 0, 0);
		} else if (a3 == 0x2000) {
			result = sub_501960(869, a1, 0, 0);
		}
	} else if (a3 == 16) {
		result = sub_501960(859, a1, 0, 0);
	} else {
		result = a3 - 1;
		switch (a3) {
		case 1u:
		case 2u:
		case 4u:
			result = sub_501960(864, a1, 0, 0);
			break;
		case 8u:
			result = sub_501960(854, a1, 0, 0);
			break;
		default:
			return result;
		}
	}
	return result;
}

//----- (00532E20) --------------------------------------------------------
int __cdecl sub_532E20(int a1, int a2) {
	int v3; // eax

	if (a1 && *(_DWORD*)(a1 + 8) & 0x1001000 && *(_DWORD*)(a1 + 492))
		return 1;
	if (a2 && *(_WORD*)(a2 + 24) != 0x4000 && sub_532F70(*(_DWORD*)(a1 + 524))) {
		v3 = *(_DWORD*)(a1 + 556);
		if (v3 && *(_WORD*)(v3 + 4) && sub_532FB0(*(_WORD*)(a1 + 24))) {
			sub_532EC0(a1, *(_WORD*)(a1 + 24));
			return 1;
		}
		sub_532930(a1, *(_WORD*)(a1 + 24), *(_WORD*)(a2 + 24));
	}
	return 1;
}

//----- (00532EC0) --------------------------------------------------------
_DWORD* __cdecl sub_532EC0(int a1, unsigned __int16 a2) {
	_DWORD* result; // eax

	result = (_DWORD*)a2;
	if ((int)a2 <= 64) {
		if (a2 != 64) {
			switch (a2) {
			case 8u:
				return sub_501960(875, a1, 0, 0);
			case 0x10u:
				return sub_501960(876, a1, 0, 0);
			case 0x20u:
				result = sub_501960(873, a1, 0, 0);
				break;
			}
			return result;
		}
		return sub_501960(874, a1, 0, 0);
	}
	if (a2 == 1024)
		return sub_501960(874, a1, 0, 0);
	if (a2 == 4096)
		result = sub_501960(877, a1, 0, 0);
	return result;
}

//----- (00532F70) --------------------------------------------------------
int __cdecl sub_532F70(int a1) {
	int result; // eax

	switch (a1) {
	case 0:
	case 2:
	case 3:
	case 10:
	case 11:
		result = 1;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (00532FB0) --------------------------------------------------------
BOOL __cdecl sub_532FB0(__int16 a1) { return a1 == 8 || a1 == 32 || a1 == 64; }

//----- (00532FE0) --------------------------------------------------------
int __cdecl sub_532FE0(unsigned __int16 a1, int a2) {
	if (a2)
		sub_532930(a2, a1, *(_WORD*)(a2 + 24));
	return 1;
}

//----- (00533010) --------------------------------------------------------
int __cdecl sub_533010(unsigned __int16 a1, int a2) {
	if (a2)
		sub_532EC0(a2, a1);
	return 1;
}

//----- (00533030) --------------------------------------------------------
unsigned __int8* __cdecl sub_533030(int a1, int a2) {
	int v2; // edi
	int v3; // eax

	v2 = *(_DWORD*)(a1 + 748);
	v3 = sub_424300(a1);
	if (v3)
		sub_501960(*(_DWORD*)(v3 + 68), a1, 0, 0);
	return sub_502490((int*)(v2 + 1232), a2, a1);
}

//----- (00533080) --------------------------------------------------------
int __cdecl sub_533080(int a1, int a2, float a3, int a4) {
	int result;     // eax
	double v5;      // st7
	double v6;      // st6
	long double v7; // st7

	result = a2;
	v5 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
	v6 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
	v7 = sqrt(v6 * v6 + v5 * v5) / a3;
	*(float*)a4 = v7 * *(float*)(a2 + 80) + *(float*)(a2 + 56);
	*(float*)(a4 + 4) = v7 * *(float*)(a2 + 84) + *(float*)(a2 + 60);
	return result;
}

//----- (005330C0) --------------------------------------------------------
BOOL __cdecl sub_5330C0(int a1, int a2) {
	int v2; // edx
	int v3; // eax
	int v5; // ecx
	int v6; // edi
	int v7; // esi
	int v8; // eax

	if (!*(_DWORD*)&byte_5D4594[2488512]) {
		*(_DWORD*)&byte_5D4594[2488512] = sub_4E3AA0((CHAR*)&byte_587000[263780]);
		*(_DWORD*)&byte_5D4594[2488516] = sub_4E3AA0((CHAR*)&byte_587000[263800]);
		*(_DWORD*)&byte_5D4594[2488520] = sub_4E3AA0((CHAR*)&byte_587000[263808]);
	}
	if (a1) {
		if (a2) {
			if (a1 != a2) {
				v2 = *(_DWORD*)(a2 + 8);
				if (!(*(_DWORD*)(a2 + 8) & 2) || !(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 1440) & 0x40000)) {
					v3 = *(_DWORD*)(a1 + 8) & 4;
					if (v3 && *(unsigned __int16*)(a2 + 4) == *(_DWORD*)&byte_5D4594[2488516])
						return 1;
					if (v3 && v2 & 0x20000)
						return 1;
					v5 = *(_DWORD*)(a1 + 8) & 2;
					if ((!v5 || !(v2 & 0x20000)) &&
					    (!v3 || !(*(_DWORD*)(a2 + 8) & 2) || !(*(_BYTE*)(a2 + 12) & 0x20)) &&
					    (!v5 || !(*(_BYTE*)(a1 + 12) & 0x20) || !(v2 & 4))) {
						if (sub_534B10(a1) || sub_534B90(a1)) {
							if (!sub_534B10(a2) && !sub_534B90(a2))
								return 1;
						} else {
							if (sub_534B60(a1))
								return !sub_534B60(a2);
							if (!sub_534B10(a2) &&
							    (!(*(_BYTE*)(a2 + 8) & 2) || !(*(_BYTE*)(a2 + 12) & 8)) &&
							    (!(*(_BYTE*)(a1 + 8) & 2) || !(*(_BYTE*)(a1 + 12) & 8)) &&
							    !sub_4FF350(a1, 28) && !sub_4FF350(a2, 28) &&
							    (!(*(_BYTE*)(a2 + 8) & 4) ||
							     !(*(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) +
									 3680) &
							       1))) {
								v6 = sub_4EC580(a1);
								v7 = sub_4EC580(a2);
								if (v6 != v7 && !sub_419150(v6 + 48, v7 + 48)) {
									v8 = *(_DWORD*)(v6 + 8);
									if (v8 & 4 && *(_DWORD*)(v7 + 8) & 0x20000)
										return 1;
									if (!(v8 & 2) ||
									    !(*(_DWORD*)(v7 + 8) & 0x20000)) {
										if (!nox_common_gameFlags_check_40A5C0(
											4096) &&
										    *(_BYTE*)(a1 + 8) & 2 &&
										    *(unsigned __int16*)(a2 + 4) ==
											*(_DWORD*)&byte_5D4594
											    [2488520]) {
											return sub_50A0D0(a2, 15) != 0;
										}
										if (sub_419130(v6 + 48) ||
										    sub_419130(v7 + 48) ||
										    !(*(_BYTE*)(v6 + 8) & 2) ||
										    !(*(_BYTE*)(v7 + 8) & 2)) {
											return 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

//----- (00533360) --------------------------------------------------------
BOOL __cdecl sub_533360(int a1, int a2) {
	double v2;   // st7
	double v3;   // st6
	float* v4;   // eax
	BOOL result; // eax
	float v6;    // [esp+Ch] [ebp-4h]
	float v7;    // [esp+18h] [ebp+8h]

	result = 0;
	if (sub_5370E0(a1, a2, 0)) {
		v2 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
		v3 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
		v6 = v3;
		v4 = (float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194136];
		v7 = sqrt(v3 * v6 + v2 * v2) + 0.001;
		if (v6 / v7 * v4[1] + v2 / v7 * *v4 > 0.5)
			result = 1;
	}
	return result;
}

//----- (005333F0) --------------------------------------------------------
int __cdecl sub_5333F0(int a1) {
	int v2; // [esp+0h] [ebp-4h]

	v2 = 1142947840;
	if (!nox_common_gameFlags_check_40A5C0(4096))
		v2 = 1132068864;
	dword_5d4594_2487984 = 0;
	dword_5d4594_2487980 = 1259902592;
	*(_DWORD*)&byte_5D4594[2487992] = 1;
	sub_517F90((float2*)(a1 + 56), *(float*)&v2, sub_533460, a1);
	return dword_5d4594_2487984;
}

//----- (00533460) --------------------------------------------------------
void __cdecl sub_533460(int a1, int a2) {
	int v2;    // edi
	int v3;    // eax
	double v4; // st7
	float* v5; // eax
	double v6; // st7
	float v7;  // [esp+10h] [ebp-8h]
	float v8;  // [esp+14h] [ebp-4h]
	float v9;  // [esp+20h] [ebp+8h]

	v2 = a2;
	if (a2 != a1) {
		if (*(_DWORD*)(a1 + 8) & 0x20006) {
			if (sub_5330C0(a2, a1)) {
				v3 = *(_DWORD*)(a1 + 16);
				if ((v3 & 0x8000) == 0) {
					if (sub_5370E0(a2, a1, 0)) {
						v7 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
						v4 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
						v8 = v4;
						v9 = nox_double2float(sqrt(v4 * v8 + v7 * v7)) + 0.001;
						if (!*(_DWORD*)&byte_5D4594[2487992] ||
						    (v5 = (float*)&byte_587000[8 * *(__int16*)(v2 + 124) + 194136],
						     v8 / v9 * v5[1] + v7 / v9 * *v5 > 0.5)) {
							v6 = v9;
							if (sub_4FF350(a1, 10))
								v6 = v6 * 0.33333334;
							if (v6 < *(float*)&dword_5d4594_2487980) {
								*(float*)&dword_5d4594_2487980 = v6;
								dword_5d4594_2487984 = a1;
							}
						}
					}
				}
			}
		}
	}
}

//----- (00533570) --------------------------------------------------------
int __cdecl sub_533570(int a1) {
	int v2; // [esp+0h] [ebp-4h]

	v2 = 1142947840;
	if (!nox_common_gameFlags_check_40A5C0(4096))
		v2 = 1132068864;
	dword_5d4594_2487984 = 0;
	*(_DWORD*)&byte_5D4594[2487992] = 0;
	dword_5d4594_2487980 = 1259902592;
	sub_517F90((float2*)(a1 + 56), *(float*)&v2, sub_533460, a1);
	return dword_5d4594_2487984;
}

//----- (005335D0) --------------------------------------------------------
int __cdecl sub_5335D0(int a1, float a2) {
	dword_5d4594_2487984 = 0;
	*(_DWORD*)&byte_5D4594[2487992] = 0;
	*(float*)&dword_5d4594_2487980 = a2;
	sub_517F90((float2*)(a1 + 56), a2, sub_533460, a1);
	return dword_5d4594_2487984;
}

//----- (00533610) --------------------------------------------------------
BOOL __cdecl sub_533610(int a1, int a2) {
	char* v2;    // esi
	char* v3;    // eax
	BOOL result; // eax

	v2 = sub_533660(a1);
	v3 = sub_533660(a2);
	if (v2 && v3)
		result = v2[130] == v3[130];
	else
		result = 1;
	return result;
}

//----- (00533660) --------------------------------------------------------
char* __cdecl sub_533660(int a1) {
	int v1;  // eax
	int2 v3; // [esp+4h] [ebp-8h]

	v1 = *(_DWORD*)(a1 + 8);
	if (v1 & 4)
		return sub_4214A0(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 3664));
	if (!(v1 & 2))
		return 0;
	v3.field_0 = nox_float2int(*(float*)(a1 + 56));
	v3.field_4 = nox_float2int(*(float*)(a1 + 60));
	return (char*)sub_4217B0(&v3, 0);
}

//----- (005336D0) --------------------------------------------------------
long double __cdecl sub_5336D0(int a1) {
	long double result; // st7

	dword_5d4594_2487984 = 0;
	dword_5d4594_2487980 = 1287568416;
	sub_517F90((float2*)(a1 + 56), 1000.0, sub_533720, a1);
	if (dword_5d4594_2487984)
		result = sqrt(*(float*)&dword_5d4594_2487980);
	else
		result = -1.0;
	return result;
}

//----- (00533720) --------------------------------------------------------
void __cdecl sub_533720(int a1, int a2) {
	double v2; // st7
	double v3; // st6
	double v4; // st5

	if (*(_BYTE*)(a1 + 8) & 6 && sub_5330C0(a2, a1) && !(*(_DWORD*)(a1 + 16) & 0x8020)) {
		v2 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
		v3 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
		v4 = v3 * v3 + v2 * v2;
		if (v4 < *(float*)&dword_5d4594_2487980) {
			*(float*)&dword_5d4594_2487980 = v4;
			dword_5d4594_2487984 = a1;
		}
	}
}

//----- (00533790) --------------------------------------------------------
int __cdecl sub_533790(int a1) {
	int v1;          // edi
	char v2;         // al
	unsigned int v3; // esi
	int result;      // eax

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(_BYTE*)(v1 + 544);
	if (v2 == -1) {
	LABEL_15:
		v3 = 8;
	} else {
		switch (*(_DWORD*)(v1 + 24 * (v2 + 23))) {
		case 7:
		case 8:
		case 0xA:
		case 0xD:
		case 0x1D:
		case 0x24:
		case 0x25:
			v3 = (*(_DWORD*)(v1 + 1440) & 0x4000 | 0x30000u) >> 14;
			break;
		case 9:
			v3 = 12;
			break;
		case 0x10:
			v3 = 1;
			break;
		case 0x11:
			v3 = 3;
			break;
		case 0x12:
		case 0x13:
		case 0x14:
			v3 = 7;
			break;
		case 0x15:
		case 0x17:
			v3 = 5;
			break;
		case 0x16:
			v3 = 6;
			break;
		case 0x18:
			v3 = 13;
			break;
		case 0x1E:
			v3 = 9;
			break;
		case 0x1F:
			v3 = 10;
			break;
		case 0x21:
		case 0x23:
			v3 = 14;
			break;
		case 0x22:
			v3 = 15;
			break;
		default:
			goto LABEL_15;
		}
	}
	if (sub_534840(a1) && v3 == 8) {
		if (*(_DWORD*)(v1 + 1440) & 0x40000)
			return 0;
		return v3;
	}
	if (sub_534A10(a1) && v3 == 8) {
		if (!*(_DWORD*)(v1 + 1196))
			return 14;
		return v3;
	}
	if (!sub_534A40(a1))
		return v3;
	if (v3 != 9)
		return v3;
	result = 15;
	if (!(*(_DWORD*)(v1 + 1440) & 0x80000))
		return v3;
	return result;
}

//----- (00533900) --------------------------------------------------------
void __cdecl sub_533900(int a1, int a2, int a3) {
	int i; // esi

	if (a1) {
		if (a2) {
			sub_5339A0(a1, a2, a3);
		} else {
			if (*(_BYTE*)(a1 + 8) & 4 && (a3 == 4 || a3 == 3 || a3 == 5))
				sub_500C70(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064), a3);
			for (i = *(_DWORD*)(a1 + 516); i; i = *(_DWORD*)(i + 512)) {
				if (*(_BYTE*)(i + 8) & 2) {
					if (*(_BYTE*)(*(_DWORD*)(i + 748) + 1440) & 0x80)
						sub_5339A0(a1, i, a3);
				}
			}
		}
	}
}

//----- (005339A0) --------------------------------------------------------
void __cdecl sub_5339A0(int a1, int a2, int a3) {
	_DWORD* v3;       // edi
	int v4;           // eax
	_DWORD* v5;       // eax
	int v6;           // eax
	unsigned int v7;  // ebp
	int v8;           // eax
	int v9;           // eax
	int* v10;         // eax
	int v11;          // edi
	int v12;          // eax
	unsigned int v13; // edx
	int* v14;         // eax
	int v15;          // edx
	int v16;          // eax
	unsigned int v17; // ebp

	v3 = *(_DWORD**)(a2 + 748);
	if (a1 && *(_BYTE*)(a2 + 8) & 2) {
		if (sub_534A40(a2) && !a3 || (v4 = *(_DWORD*)(a2 + 16), (v4 & 0x8000) == 0)) {
			if (v3[121] || (v5 = sub_517560(*(unsigned __int16*)(a2 + 4)), (v3[121] = v5) != 0)) {
				switch (a3) {
				case 0:
					if (*(_DWORD*)(a2 + 508) == a1)
						sub_5017F0(a2);
					break;
				case 1:
					if (*(_BYTE*)(a1 + 8) & 4)
						sub_4DDE80(a1, a2);
					break;
				case 2:
					if (*(_BYTE*)(a1 + 8) & 4)
						sub_528BD0(a2, a1, "MonUtil.c:idle", 0);
					v6 = sub_424300(a2);
					if (v6)
						sub_501960(*(_DWORD*)(v6 + 68), a2, 0, 0);
					v7 = v3[360] & 0xFFFFFFBF;
					v3[326] = 1056964608;
					v3[360] = v7;
					sub_50A3A0(a2);
					sub_50A260(a2, 0);
					break;
				case 3:
					if (sub_534320(a2)) {
						if (*(_BYTE*)(a1 + 8) & 4)
							sub_528BD0(a2, a1, "MonUtil.c:guarding", 0);
						v8 = sub_424300(a2);
						if (v8)
							sub_501960(*(_DWORD*)(v8 + 68), a2, 0, 0);
						v3[326] = 1056964608;
						if (sub_534280(a2)) {
							v9 = v3[360];
							LOBYTE(v9) = v9 | 0x40;
							v3[360] = v9;
						}
						v3[328] = 1132068864;
						sub_50A3A0(a2);
						v10 = sub_50A260(a2, 4);
						if (v10) {
							v10[1] = *(_DWORD*)(a2 + 56);
							v10[2] = *(_DWORD*)(a2 + 60);
							v10[3] = *(__int16*)(a2 + 124);
						}
					}
					break;
				case 4:
					v11 = *(_DWORD*)(a2 + 748);
					if (sub_534320(a2)) {
						if (*(_BYTE*)(a1 + 8) & 4)
							sub_528BD0(a2, a1, "MonUtil.c:escorting", 0);
						v12 = sub_424300(a2);
						if (v12)
							sub_501960(*(_DWORD*)(v12 + 68), a2, 0, 0);
						v13 = *(_DWORD*)(v11 + 1440) & 0xFFFFFFBF;
						*(_DWORD*)(v11 + 1304) = 1062501089;
						*(_DWORD*)(v11 + 1440) = v13;
						sub_50A3A0(a2);
						v14 = sub_50A260(a2, 3);
						if (v14) {
							v14[1] = *(_DWORD*)(a1 + 56);
							v15 = *(_DWORD*)(a1 + 60);
							v14[3] = a1;
							v14[2] = v15;
						}
					}
					break;
				case 5:
					if (sub_534320(a2)) {
						v16 = sub_424300(a2);
						if (v16)
							sub_501960(*(_DWORD*)(v16 + 68), a2, 0, 0);
						if (*(_BYTE*)(a1 + 8) & 4)
							sub_528BD0(a2, a1, "MonUtil.c:Hunting", 0);
						v17 = v3[360] & 0xFFFFFFBF;
						v3[326] = 1062501089;
						v3[360] = v17;
						sub_50A3A0(a2);
						sub_50A260(a2, 5);
					}
					break;
				default:
					return;
				}
			}
		}
	}
}

//----- (00533C80) --------------------------------------------------------
BOOL __cdecl sub_533C80(int a1, int a2) {
	float* v2; // ecx

	v2 = (float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194136];
	return (*(float*)(a2 + 60) - *(float*)(a1 + 60)) * v2[1] + (*(float*)(a2 + 56) - *(float*)(a1 + 56)) * *v2 >
	       0.0;
}

//----- (00533CC0) --------------------------------------------------------
void __cdecl sub_533CC0(int a1, float* a2) {
	float2 v2; // [esp+4h] [ebp-8h]

	if (a1) {
		v2.field_0 = *a2 - *(float*)(a1 + 56);
		v2.field_4 = a2[1] - *(float*)(a1 + 60);
		*(_WORD*)(a1 + 126) = sub_509ED0(&v2);
	}
}

//----- (00533D00) --------------------------------------------------------
unsigned __int8* __cdecl sub_533D00(int a1) {
	int v1;                  // esi
	int v2;                  // eax
	int v3;                  // eax
	int v4;                  // eax
	unsigned __int8* result; // eax
	int v6;                  // [esp+4h] [ebp-4h]

	v1 = *(_DWORD*)(a1 + 748);
	if (*(_BYTE*)(a1 + 12) & 0x10) {
		v2 = *(char*)(v1 + 544) + 23;
		a1 = 0;
		v6 = 0;
		v3 = *(_DWORD*)(v1 + 24 * v2);
		switch (v3) {
		case 16:
		case 17:
			if (*(_DWORD*)(v1 + 2056) & 0xFFFFFFFC)
				v4 = sub_4FA280(*(_DWORD*)(v1 + 2056) & 0xFFFFFFFC);
			else
				v4 = *(unsigned __int8*)(v1 + 2068);
			sub_4F9F90(v4, &a1, &v6);
			break;
		case 18:
		case 19:
		case 20:
			sub_4F9F90(21, &a1, &v6);
			break;
		case 30:
			sub_4F9F90(1, &a1, &v6);
			break;
		case 31:
			sub_4F9F90(2, &a1, &v6);
			break;
		case 21:
			sub_4F9F90(40, &a1, &v6);
			break;
		case 23:
			if (*(_DWORD*)(v1 + 2056) & 0x7FF8000)
				sub_4F9F90(30, &a1, &v6);
			else
				sub_4F9F90(47, &a1, &v6);
			break;
		}
		*(_DWORD*)&byte_5D4594[2487968] = 0;
		*(_DWORD*)&byte_5D4594[2487964] = 0;
		*(_DWORD*)&byte_5D4594[2487972] = 0;
		*(_DWORD*)&byte_5D4594[2487976] = 0;
		byte_5D4594[2487973] = a1;
		byte_5D4594[2487974] = v6;
		result = &byte_5D4594[2487964];
	} else if (*(_DWORD*)(v1 + 476)) {
		result = (unsigned __int8*)(*(_DWORD*)(v1 + 476) + 16 * sub_533790(a1));
	} else {
		result = 0;
	}
	return result;
}

//----- (00533E70) --------------------------------------------------------
int __cdecl sub_533E70(int a1) {
	*(_DWORD*)&byte_5D4594[2487956] = 0;
	*(_DWORD*)&byte_5D4594[2487988] = 1315859240; // fp32 100
	sub_518170(a1 + 56, 100.0, sub_533EB0, a1);
	return *(_DWORD*)&byte_5D4594[2487956];
}

//----- (00533EB0) --------------------------------------------------------
void __cdecl sub_533EB0(int a1, int a2) {
	int v2;         // esi
	float v3;       // ecx
	int v4;         // ecx
	double v5;      // st7
	double v6;      // st6
	float* v7;      // ecx
	double v8;      // st7
	long double v9; // st5
	float v10;      // [esp+Ch] [ebp-18h]
	float v11;      // [esp+10h] [ebp-14h]
	float2 a3;      // [esp+14h] [ebp-10h]
	float v13;      // [esp+1Ch] [ebp-8h]
	float v14;      // [esp+28h] [ebp+4h]

	v2 = a1;
	v3 = *(float*)(a1 + 76);
	a3.field_0 = *(float*)(a1 + 72);
	a3.field_4 = v3;
	if (sub_54E6F0(a2, a1)) {
		if (nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a2 + 56), *(__int16*)(a2 + 124), &a3) & 1) {
			v4 = *(__int16*)(a2 + 124);
			v5 = *(float*)(a1 + 80) * *(float*)&byte_587000[8 * v4 + 194136];
			v6 = *(float*)(a1 + 84) * *(float*)&byte_587000[8 * v4 + 194140];
			v7 = (float*)&byte_587000[8 * v4 + 194136];
			if (v5 + v6 < 0.0) {
				v10 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
				v11 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
				v8 = *v7 * v11 + -v7[1] * v10;
				if (v8 < 0.0)
					v8 = -v8;
				if (v8 < 20.0) {
					v9 = sqrt(*(float*)(a1 + 80) * *(float*)(a1 + 80) +
						  *(float*)(a1 + 84) * *(float*)(a1 + 84));
					v13 = *(float*)(a1 + 80) / v9;
					v14 = sqrt(v11 * v11 + v10 * v10);
					if (*(float*)(v2 + 84) / v9 * -(v11 / v14) + v13 * -(v10 / v14) > 0.69999999) {
						if (sub_5370E0(a2, v2, 0)) {
							if (v14 < (double)*(float*)&byte_5D4594[2487988]) {
								*(_DWORD*)&byte_5D4594[2487956] = v2;
								*(float*)&byte_5D4594[2487988] = v14;
							}
						}
					}
				}
			}
		}
	}
}

//----- (00534020) --------------------------------------------------------
int __cdecl sub_534020(int a1) { return (*(_DWORD*)(a1 + 12) >> 10) & 1; }

//----- (00534030) --------------------------------------------------------
char __cdecl sub_534030(int a1) {
	int v1;          // ebx
	char v2;         // al
	int v3;          // esi
	unsigned int v4; // ecx
	unsigned int v5; // edi
	unsigned int v6; // eax
	int v7;          // ecx
	unsigned int v9; // [esp+Ch] [ebp-8h]
	int v10;         // [esp+10h] [ebp-4h]

	v1 = a1;
	v2 = *(_BYTE*)(a1 + 12);
	v3 = *(_DWORD*)(a1 + 748);
	v10 = *(_DWORD*)(a1 + 748);
	if (v2 & 0x30) {
		sub_4F9F90(4, &v9, &a1);
		v4 = *(_DWORD*)(v1 + 36) + *(_DWORD*)&byte_5D4594[2598000];
		v5 = v4 / (a1 + 1) % v9;
		v6 = (v4 - 1) / (a1 + 1) / v9;
		if (v5 != (v4 - 1) / (a1 + 1) % v9) {
			v6 = *(_DWORD*)(v10 + 484);
			if (v5 == *(_DWORD*)(v6 + 100) || v5 == *(_DWORD*)(v6 + 104)) {
				v6 = sub_424300(v1);
				if (v6)
					LOBYTE(v6) = (unsigned int)sub_501960(*(_DWORD*)(v6 + 72), v1, 0, 0);
			}
		}
	} else {
		v6 = *(_DWORD*)(v3 + 484);
		v7 = *(unsigned __int8*)(v3 + 481);
		if (v7 == *(_DWORD*)(v6 + 100) || v7 == *(_DWORD*)(v6 + 104)) {
			LOBYTE(v6) = *(_BYTE*)(v3 + 482);
			if (!(_BYTE)v6) {
				v6 = sub_424300(a1);
				if (v6)
					LOBYTE(v6) = (unsigned int)sub_501960(*(_DWORD*)(v6 + 72), v1, 0, 0);
			}
		}
	}
	return v6;
}

//----- (00534120) --------------------------------------------------------
BOOL __cdecl sub_534120(int a1, float2* a2) {
	return *(float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194140] * a2->field_4 +
		   *(float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194136] * a2->field_0 >
	       0.89999998;
}

//----- (00534160) --------------------------------------------------------
int __cdecl sub_534160(int a1) {
	int result; // eax
	int i;      // ecx

	result = a1;
	if (a1) {
		for (i = *(_DWORD*)(a1 + 508); i; i = *(_DWORD*)(i + 508)) {
			if (*(_BYTE*)(result + 8) & 6)
				break;
			result = i;
		}
		if (result) {
			if (!(*(_BYTE*)(result + 8) & 6))
				result = 0;
		}
	}
	return result;
}

//----- (005341A0) --------------------------------------------------------
void sub_5341A0(char* a1, ...) {
	// char debug[1024];
	va_list va; // [esp+8h] [ebp+8h]

	va_start(va, a1);
	// nox_vsprintf(debug, a1, va);
	// OutputDebugStringA(debug);
	if (nox_common_engineFlags & 8)
		nox_vsprintf((char*)&byte_5D4594[2487996], a1, va);
}

//----- (005341D0) --------------------------------------------------------
int __cdecl sub_5341D0(int a1) {
	sub_4FF5B0(a1, 0);
	return sub_4FF5B0(a1, 23);
}

//----- (005341F0) --------------------------------------------------------
BOOL __cdecl sub_5341F0(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)(a1 + 748);
	return !*(_BYTE*)(v1 + 544) && !*(_DWORD*)(v1 + 552);
}

//----- (00534220) --------------------------------------------------------
BOOL __cdecl sub_534220(int a1) {
	int v1;      // edi
	BOOL result; // eax

	v1 = *(_DWORD*)(a1 + 748);
	if (sub_534300(a1))
		goto LABEL_9;
	if (*(_BYTE*)(a1 + 12) & 0x10)
		return !sub_534280(a1);
	if (*(float*)(*(_DWORD*)(v1 + 484) + 112) <= 0.0)
	LABEL_9:
		result = 0;
	else
		result = 1;
	return result;
}

//----- (00534280) --------------------------------------------------------
BOOL __cdecl sub_534280(int a1) {
	int v1;      // ecx
	BOOL result; // eax

	v1 = *(_DWORD*)(a1 + 748);
	if (*(_BYTE*)(a1 + 12) & 0x10)
		result = (*(_DWORD*)(v1 + 2056) & 0x47F00FE) != 0;
	else
		result = *(_BYTE*)(*(_DWORD*)(v1 + 484) + 148) != 0;
	return result;
}

//----- (005342C0) --------------------------------------------------------
int __cdecl sub_5342C0(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = *(_DWORD*)(a1 + 748);
	if (*(_BYTE*)(a1 + 12) & 0x10)
		result = (*(_DWORD*)(v1 + 2060) & 0x3000000) != 0;
	else
		result = (*(_DWORD*)(v1 + 1440) >> 2) & 1;
	return result;
}

//----- (00534300) --------------------------------------------------------
int __cdecl sub_534300(int a1) { return (*(_DWORD*)(*(_DWORD*)(a1 + 748) + 1440) >> 5) & 1; }

//----- (00534320) --------------------------------------------------------
BOOL __cdecl sub_534320(int a1) { return *(float*)(a1 + 548) >= 0.0099999998; }

//----- (00534340) --------------------------------------------------------
BOOL __cdecl sub_534340(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 24 * (*(char*)(*(_DWORD*)(a1 + 748) + 544) + 23));
	return !v1 || v1 == 1 || v1 == 4 || v1 == 25 || v1 == 26 || v1 == 27 || v1 == 23;
}

//----- (00534390) --------------------------------------------------------
BOOL __cdecl sub_534390(int a1) { return *(float*)(*(_DWORD*)(a1 + 748) + 1304) > 0.66000003; }

//----- (005343C0) --------------------------------------------------------
BOOL __cdecl sub_5343C0(int a1) {
	int v1; // ecx

	v1 = *(_DWORD*)(a1 + 748);
	return *(float*)(v1 + 1304) < 0.66000003 && *(float*)(v1 + 1304) > 0.33000001;
}

//----- (00534400) --------------------------------------------------------
BOOL __cdecl sub_534400(int a1) {
	int v1; // ecx

	v1 = *(_DWORD*)(a1 + 748);
	return *(float*)(v1 + 1304) < 0.33000001 && *(float*)(v1 + 1304) > 0.079999998;
}

//----- (00534440) --------------------------------------------------------
BOOL __cdecl sub_534440(int a1) { return *(float*)(*(_DWORD*)(a1 + 748) + 1304) < 0.079999998; }

//----- (00534470) --------------------------------------------------------
double __cdecl sub_534470(int a1) { return *(float*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 484) + 112); }

//----- (00534490) --------------------------------------------------------
char* __cdecl sub_534490(float a1) {
	int v1;    // edx
	float* v2; // ecx

	v1 = 0;
	v2 = (float*)&byte_587000[261712];
	while (a1 != *v2) {
		v2 += 2;
		++v1;
		if ((int)v2 >= (int)&byte_587000[261744])
			return *(char**)&byte_587000[261716];
	}
	return *(char**)&byte_587000[8 * v1 + 261716];
}

//----- (005344C0) --------------------------------------------------------
double __cdecl sub_5344C0(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)&byte_587000[261716];
	while (strcmp(*v2, a1)) {
		v2 += 2;
		++v1;
		if ((int)v2 >= (int)&byte_587000[261748])
			return 0.5;
	}
	return *(float*)&byte_587000[8 * v1 + 261712];
}

//----- (00534530) --------------------------------------------------------
char* __cdecl sub_534530(int a1) {
	char* result; // eax

	if (a1 < 0 || a1 >= 5)
		result = *(char**)&byte_587000[261744];
	else
		result = *(char**)&byte_587000[4 * a1 + 261744];
	return result;
}

//----- (00534550) --------------------------------------------------------
int __cdecl sub_534550(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)&byte_587000[261744];
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)&byte_587000[261764])
			return 3;
	}
	return v1;
}

//----- (005345B0) --------------------------------------------------------
char* __cdecl sub_5345B0(int a1) {
	unsigned __int8* v1; // ecx
	int v2;              // eax

	v1 = &byte_587000[262056];
	while (*(_DWORD*)v1 != a1) {
	LABEL_6:
		v1 += 4;
		if ((int)v1 >= (int)&byte_587000[262072])
			return *(char**)&byte_587000[261920];
	}
	v2 = 0;
	while (v2 != a1) {
		if (++v2 >= 39)
			goto LABEL_6;
	}
	return *(char**)&byte_587000[4 * v2 + 261768];
}

//----- (005345F0) --------------------------------------------------------
int __cdecl sub_5345F0(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)&byte_587000[261768];
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)&byte_587000[261924])
			return 38;
	}
	return v1;
}

//----- (00534650) --------------------------------------------------------
char* __cdecl sub_534650(int a1) {
	int v1; // eax

	v1 = 0;
	while (v1 != a1) {
		if (++v1 >= 72)
			return 0;
	}
	return *(char**)&byte_587000[4 * v1 + 261768];
}

//----- (00534670) --------------------------------------------------------
int __cdecl sub_534670(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)&byte_587000[261768];
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)&byte_587000[262056])
			return 0;
	}
	return v1;
}

//----- (005346D0) --------------------------------------------------------
int __cdecl sub_5346D0(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 748);
	*(_DWORD*)(result + 8) = 0;
	*(_DWORD*)(result + 296) = 0;
	return result;
}

//----- (005346F0) --------------------------------------------------------
int __cdecl sub_5346F0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(*(_DWORD*)(a1 + 748) + 1196) = 0;
	return result;
}

//----- (00534710) --------------------------------------------------------
BOOL __cdecl sub_534710(int a1) {
	int v1;      // ecx
	BOOL result; // eax

	v1 = *(_DWORD*)(a1 + 748);
	if (*(_BYTE*)(v1 + 1440) & 0x40)
		result = 1;
	else
		result = *(_DWORD*)(v1 + 24 * (*(char*)(v1 + 544) + 23)) == 4;
	return result;
}

//----- (00534750) --------------------------------------------------------
int __cdecl sub_534750(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = *(_DWORD*)(a1 + 748);
	result = *(_DWORD*)(v1 + 1440);
	if (!(result & 0x10000)) {
		BYTE1(result) |= 0x40u;
		*(_DWORD*)(v1 + 1440) = result;
	}
	return result;
}

//----- (00534780) --------------------------------------------------------
int __cdecl sub_534780(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = *(_DWORD*)(a1 + 748);
	result = *(_DWORD*)(v1 + 1440);
	if ((result & 0x8000) == 0) {
		BYTE1(result) &= 0xBFu;
		*(_DWORD*)(v1 + 1440) = result;
	}
	return result;
}

//----- (005347A0) --------------------------------------------------------
int __cdecl sub_5347A0(int a1) { return (*(_DWORD*)(*(_DWORD*)(a1 + 748) + 1440) >> 9) & 1; }

//----- (005347C0) --------------------------------------------------------
BOOL __cdecl sub_5347C0(int a1) {
	unsigned __int16* v1; // eax
	unsigned __int16 v2;  // cx
	BOOL result;          // eax

	v1 = *(unsigned __int16**)(a1 + 556);
	result = 0;
	if (v1) {
		v2 = v1[2];
		if (*v1 < v2) {
			if (v2)
				result = 1;
		}
	}
	return result;
}

//----- (005347F0) --------------------------------------------------------
BOOL __cdecl sub_5347F0(int a1) { return *(_BYTE*)(a1 + 540) != 0; }

//----- (00534810) --------------------------------------------------------
BOOL __cdecl sub_534810(int a1) {
	return *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(*(_DWORD*)(a1 + 748) + 508) <
	       (unsigned int)(3 * *(_DWORD*)&byte_5D4594[2649704]);
}

//----- (00534840) --------------------------------------------------------
BOOL __cdecl sub_534840(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)&byte_5D4594[2488524];
	if (!*(_DWORD*)&byte_5D4594[2488524]) {
		v1 = sub_4E3AA0((CHAR*)&byte_587000[263896]);
		*(_DWORD*)&byte_5D4594[2488524] = v1;
	}
	return *(unsigned __int16*)(a1 + 4) == v1;
}

//----- (00534870) --------------------------------------------------------
int* __cdecl sub_534870(int a1) {
	int* result; // eax

	result = (int*)sub_534840(a1);
	if (result) {
		sub_50A260(a1, 61);
		result = sub_50A260(a1, 33);
	}
	return result;
}

//----- (005348A0) --------------------------------------------------------
int* __cdecl sub_5348A0(int a1) {
	int* result; // eax

	result = (int*)sub_534840(a1);
	if (result) {
		sub_50A260(a1, 61);
		result = sub_50A260(a1, 34);
	}
	return result;
}

//----- (005348D0) --------------------------------------------------------
char __cdecl sub_5348D0(int a1) {
	int v1;      // esi
	char result; // al

	v1 = *(_DWORD*)(a1 + 748);
	result = *(_BYTE*)(v1 + 483);
	if (result) {
		sub_50A160(a1);
		*(_DWORD*)(v1 + 1440) |= 0x40000u;
		result = (unsigned int)sub_4E8020(a1);
	}
	return result;
}

//----- (00534910) --------------------------------------------------------
char __cdecl sub_534910(int a1) {
	int v1;      // esi
	char result; // al

	v1 = *(_DWORD*)(a1 + 748);
	result = *(_BYTE*)(v1 + 483);
	if (result) {
		sub_50A160(a1);
		*(_DWORD*)(v1 + 1440) &= 0xFFFBFFFF;
		result = (unsigned int)sub_4E8020(a1);
	}
	return result;
}

//----- (00534950) --------------------------------------------------------
void __cdecl sub_534950(int a1) {
	int v1;    // ecx
	int v2;    // edx
	int v3;    // eax
	double v4; // st7
	double v5; // st6

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(_DWORD*)(v1 + 24 * (*(char*)(v1 + 544) + 23));
	v3 = v1 + 24 * (*(char*)(v1 + 544) + 23);
	if (v2 && (v2 != 4 || (v4 = *(float*)(v3 + 4) - *(float*)(a1 + 56), v5 = *(float*)(v3 + 8) - *(float*)(a1 + 60),
			       v5 * v5 + v4 * v4 > 64.0))) {
		if (v2 != 34 && *(_DWORD*)(v1 + 1440) & 0x40000) {
			sub_50A260(a1, 61);
			sub_50A260(a1, 34);
			goto LABEL_10;
		}
	} else if (!(*(_DWORD*)(v1 + 1440) & 0x40000) &&
		   (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v1 + 548)) >
		       *(int*)&byte_5D4594[2649704]) {
		sub_50A260(a1, 61);
		sub_50A260(a1, 33);
	LABEL_10:
		sub_501960(460, a1, 0, 0);
		return;
	}
}

//----- (00534A10) --------------------------------------------------------
BOOL __cdecl sub_534A10(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)&byte_5D4594[2488528];
	if (!*(_DWORD*)&byte_5D4594[2488528]) {
		v1 = sub_4E3AA0((CHAR*)&byte_587000[263904]);
		*(_DWORD*)&byte_5D4594[2488528] = v1;
	}
	return *(unsigned __int16*)(a1 + 4) == v1;
}

//----- (00534A40) --------------------------------------------------------
BOOL __cdecl sub_534A40(int a1) {
	int v1; // eax

	if (!*(_DWORD*)&byte_5D4594[2488532]) {
		*(_DWORD*)&byte_5D4594[2488532] = sub_4E3AA0((CHAR*)&byte_587000[263924]);
		*(_DWORD*)&byte_5D4594[2488536] = sub_4E3AA0((CHAR*)&byte_587000[263932]);
	}
	v1 = *(unsigned __int16*)(a1 + 4);
	return (unsigned __int16)v1 == *(_DWORD*)&byte_5D4594[2488532] || v1 == *(_DWORD*)&byte_5D4594[2488536];
}

//----- (00534A90) --------------------------------------------------------
char __cdecl sub_534A90(int a1) {
	char result; // al

	result = a1;
	if (*(_BYTE*)(*(_DWORD*)(a1 + 748) + 483))
		result = sub_50A160(a1);
	return result;
}

//----- (00534AB0) --------------------------------------------------------
unsigned int __cdecl sub_534AB0(int a1) {
	unsigned int result; // eax

	result = sub_534A40(a1);
	if (result) {
		result = sub_50A020(a1);
		if (result == 31) {
			sub_50A160(a1);
			sub_50A260(a1, 61);
			sub_50A260(a1, 35);
			sub_501960(469, a1, 0, 0);
			sub_4EE6F0(a1);
			result = *(_DWORD*)(a1 + 16) & 0xFFFF7FA7;
			*(_DWORD*)(a1 + 16) = result;
		}
	}
	return result;
}

//----- (00534B10) --------------------------------------------------------
BOOL __cdecl sub_534B10(int a1) {
	int v1; // eax
	int v2; // ecx

	v1 = *(_DWORD*)&byte_5D4594[2488544];
	if (!*(_DWORD*)&byte_5D4594[2488544]) {
		*(_DWORD*)&byte_5D4594[2488540] = sub_4E3AA0((CHAR*)&byte_587000[263944]);
		v1 = sub_4E3AA0((CHAR*)&byte_587000[263952]);
		*(_DWORD*)&byte_5D4594[2488544] = v1;
	}
	v2 = *(unsigned __int16*)(a1 + 4);
	return (unsigned __int16)v2 == v1 || v2 == *(_DWORD*)&byte_5D4594[2488540];
}

//----- (00534B60) --------------------------------------------------------
BOOL __cdecl sub_534B60(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)&byte_5D4594[2488548];
	if (!*(_DWORD*)&byte_5D4594[2488548]) {
		v1 = sub_4E3AA0((CHAR*)&byte_587000[263964]);
		*(_DWORD*)&byte_5D4594[2488548] = v1;
	}
	return *(unsigned __int16*)(a1 + 4) == v1;
}

//----- (00534B90) --------------------------------------------------------
BOOL __cdecl sub_534B90(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)&byte_5D4594[2488552];
	if (!*(_DWORD*)&byte_5D4594[2488552]) {
		v1 = sub_4E3AA0((CHAR*)&byte_587000[263968]);
		*(_DWORD*)&byte_5D4594[2488552] = v1;
	}
	return *(unsigned __int16*)(a1 + 4) == v1;
}

//----- (00534BC0) --------------------------------------------------------
int __cdecl sub_534BC0(int a1, int a2, int a3, int a4, int a5) {
	unsigned __int8* v5; // esi
	unsigned __int8 v6;  // al
	int v7;              // eax
	int v8;              // ecx
	int result;          // eax
	unsigned __int8 v10; // al
	int v11;             // ecx
	int v12;             // eax
	int v13;             // eax
	char* v14;           // eax
	_DWORD* v15;         // edi
	float v16;           // [esp+0h] [ebp-1Ch]
	int2 v17;

	v5 = (unsigned __int8*)nox_server_getWallAtPoint_410580(a1, a2);
	if (!*(_DWORD*)&byte_5D4594[2488556])
		*(_DWORD*)&byte_5D4594[2488556] = sub_410D60("MagicWallSystemUseOnly");
	if (!v5)
		return 0;
	v6 = v5[4];
	if (v6 & 0x20)
		return 0;
	if (!(v6 & 8)) {
		sub_532FE0(*(_WORD*)&byte_5D4594[12332 * v5[1] + 2692784], a5);
		return 0;
	}
	if (!nox_common_gameFlags_check_40A5C0(4096) || !a5 || v5[1] != *(_DWORD*)&byte_5D4594[2488556] ||
	    (v7 = sub_4EC580(a5)) == 0 || (v8 = 99999999, !(*(_BYTE*)(v7 + 8) & 4))) {
		v8 = a3;
	}
	if (v5[7] - v8 > 0) {
		v10 = v5[7] - v8;
		v11 = v5[1];
		v5[7] = v10;
		*(float*)&v17.field_0 = (double)a1 * 23.0 + 11.5;
		*(float*)&v17.field_4 = (double)a2 * 23.0 + 11.5;
		v12 = sub_410E40(v11);
		if (v12) {
			v13 = nox_common_randomInt_415FA0(0, v12 - 1);
			v14 = sub_410E60(v5[1], v13);
			v15 = sub_4E3810(v14);
			if (v15) {
				sub_4DAA50((int)v15, 0, *(float*)&v17.field_0, *(float*)&v17.field_4);
				v16 = sub_416030(10.0, 20.0);
				sub_52DF80((int)&v17, (int)v15, v16);
			}
		}
		sub_533010(*(_WORD*)&byte_5D4594[12332 * v5[1] + 2692784], a5);
		result = 0;
	} else {
		v17.field_0 = a1;
		v17.field_4 = a2;
		result = sub_534DA0(&v17);
	}
	return result;
}

//----- (00534DA0) --------------------------------------------------------
int __cdecl sub_534DA0(int* a1) {
	int v1;      // edi
	char v2;     // al
	double v3;   // st7
	char* v4;    // eax
	int v5;      // eax
	int v6;      // eax
	int v7;      // ebx
	int v8;      // eax
	int v9;      // ebp
	char* v10;   // eax
	_DWORD* v11; // esi
	int v13;     // [esp+0h] [ebp-24h]
	float v14;   // [esp+0h] [ebp-24h]
	float v15;   // [esp+4h] [ebp-20h]
	float v16;   // [esp+8h] [ebp-1Ch]
	float2 v17;  // [esp+1Ch] [ebp-8h]

	v1 = nox_server_getWallAtPoint_410580(*a1, a1[1]);
	if (!*(_DWORD*)&byte_5D4594[2488560])
		*(_DWORD*)&byte_5D4594[2488560] = sub_410D60("MagicWallSystemUseOnly");
	if (!v1)
		return 0;
	v2 = *(_BYTE*)(v1 + 4);
	if (!(v2 & 8) || v2 & 0x20)
		return 0;
	v13 = *(unsigned __int8*)(v1 + 1);
	v17.field_0 = (double)*a1 * 23.0 + 11.5;
	v3 = (double)a1[1];
	*(_BYTE*)(v1 + 7) = 0;
	v17.field_4 = v3 * 23.0 + 11.5;
	v4 = sub_410EA0(v13);
	v5 = sub_40AF50(v4);
	sub_501A30(v5, &v17, 0, 0);
	sub_522FF0(138, &v17);
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		v6 = sub_410E40(*(unsigned __int8*)(v1 + 1));
		if (v6) {
			v7 = nox_common_randomInt_415FA0(0, v6 - 1);
			v8 = nox_common_randomInt_415FA0(3, 6);
			if (v8 > 0) {
				v9 = v8;
				do {
					v10 = sub_410E60(*(unsigned __int8*)(v1 + 1), v7);
					v11 = sub_4E3810(v10);
					if (v11) {
						v15 = sub_416030(-2.0, 2.0) + v17.field_4;
						v14 = sub_416030(-2.0, 2.0) + v17.field_0;
						sub_4DAA50((int)v11, 0, v14, v15);
						v16 = sub_416030(4.0, 10.0);
						sub_52DF80((int)&v17, (int)v11, v16);
					}
					if (++v7 >= sub_410E40(*(unsigned __int8*)(v1 + 1)))
						v7 = 0;
					--v9;
				} while (v9);
			}
		}
	}
	if (*(unsigned __int8*)(v1 + 1) == *(_DWORD*)&byte_5D4594[2488560]) {
		sub_4FF840(v1);
	} else {
		sub_410520(*(_WORD*)(v1 + 10));
		sub_4DF0A0(v1, 32);
	}
	return 1;
}

//----- (00534FC0) --------------------------------------------------------
bool __cdecl sub_534FC0(int4* a1, int a2, float a3, int a4, int a5, int a6) {
	int4* v6;        // edx
	int v7;          // edi
	int v8;          // eax
	int v9;          // ecx
	int v10;         // ecx
	int v11;         // ecx
	int v12;         // ecx
	int v13;         // ebx
	int v14;         // esi
	char* v15;       // edi
	float* v16;      // eax
	double v17;      // st7
	double v18;      // st7
	double v19;      // st7
	double v20;      // st7
	long double v21; // st7
	float v22;       // eax
	int* v23;        // esi
	int v25;         // [esp+8h] [ebp-144h]
	float v26;       // [esp+Ch] [ebp-140h]
	float v27;       // [esp+Ch] [ebp-140h]
	float v28;       // [esp+10h] [ebp-13Ch]
	int v29;         // [esp+14h] [ebp-138h]
	float v30;       // [esp+18h] [ebp-134h]
	float v31;       // [esp+1Ch] [ebp-130h]
	int v32;         // [esp+20h] [ebp-12Ch]
	int v33;         // [esp+24h] [ebp-128h]
	float* v34;      // [esp+28h] [ebp-124h]
	float v35;       // [esp+2Ch] [ebp-120h]
	int v36[2];      // [esp+30h] [ebp-11Ch]
	float v37;       // [esp+38h] [ebp-114h]
	float4 v38;
	char v41[256]; // [esp+4Ch] [ebp-100h]

	v6 = a1;
	v7 = 0;
	v25 = 0;
	if (!a1 || !a2)
		return 0;
	v8 = a6;
	v29 = 0;
	if (a6) {
		v9 = *(_DWORD*)(a6 + 8);
		if (v9 & 6) {
			v10 = *(__int16*)(a6 + 124);
			v29 = 1;
		} else {
			if (!(v9 & 0x1001000))
				goto LABEL_10;
			v11 = *(_DWORD*)(a6 + 492);
			if (!v11)
				goto LABEL_10;
			v10 = *(__int16*)(v11 + 124);
			v29 = 1;
		}
		v34 = (float*)&byte_587000[8 * v10 + 194136];
	}
LABEL_10:
	v12 = a1->field_C;
	v13 = a1->field_4;
	v33 = a1->field_4;
	v37 = a3 * a3;
	if (v13 <= v12) {
		do {
			v14 = v6->field_0;
			v32 = v6->field_0;
			if (v6->field_0 <= v6->field_8) {
				v15 = &v41[8 * v7 + 4];
				do {
					if (nox_server_getWallAtPoint_410580(v14, v13)) {
						v16 = (float*)(v29 ? a6 + 56 : a2);
						v17 = (double)v32;
						v35 = v17;
						v26 = v17 * 23.0 + 11.5 - *v16;
						v18 = (double)v33;
						v31 = v18;
						v19 = v18 * 23.0 + 11.5 - v16[1];
						v28 = v19;
						v20 = v19 * v28 + v26 * v26;
						v30 = v20;
						if (v20 < v37) {
							if (!v29 || v30 <= 0.0 ||
							    (v21 = sqrt(v30) + 0.5, v27 = v26 / v21,
							     v28 / v21 * v34[1] + v27 * *v34 >
								 *(double*)&qword_581450_9544)) {
								v22 = *(float*)(a2 + 4);
								v38.field_0 = *(float*)a2;
								v38.field_4 = v22;
								v38.field_8 = v35 * 23.0 + 11.5;
								v36[1] = 0;
								v36[0] = 0;
								v38.field_C = v31 * 23.0 + 11.5;
								if ((sub_535250(&v38, 0, (int2*)v36, 1) == 1 ||
								     v36[0] == v14 && v36[1] == v13) &&
								    v25 < 32) {
									*((_DWORD*)v15 - 1) = v14;
									*(_DWORD*)v15 = v13;
									++v25;
									v15 += 8;
								}
							}
						}
					}
					v32 = ++v14;
				} while (v14 <= a1->field_8);
				v7 = v25;
				v8 = a6;
				v6 = a1;
			}
			v33 = ++v13;
		} while (v13 <= v6->field_C);
	}
	if (v7 > 0) {
		v23 = (int*)v41;
		while (1) {
			sub_534BC0(*v23, v23[1], a4, a5, v8);
			v23 += 2;
			if (!--v7)
				break;
			v8 = a6;
		}
		v7 = v25;
	}
	return v7 > 0;
}
// 535128: variable 'v34' is possibly undefined

//----- (00535250) --------------------------------------------------------
int __cdecl sub_535250(float4* a1, float2* a2, int2* a3, char a4) {
	int v4;     // edi
	int v5;     // ebx
	float v6;   // eax
	double v7;  // st7
	int v8;     // eax
	float v10;  // edx
	double v11; // st7
	int v12;    // eax
	float v13;  // ecx
	double v14; // st7
	double v15; // st7
	float v16;  // et1
	float v17;  // et1
	double v18; // st7
	float v19;  // et1
	double v20; // st7
	float v21;  // et1
	double v22; // st7
	float v23;  // et1
	int v24;    // eax
	float v25;  // et1
	int v26;    // edi
	int v27;    // eax
	int v28;    // ebx
	float v29;  // ecx
	double v30; // st7
	float v31;  // et1
	float v32;  // et1
	double v33; // st7
	float v34;  // et1
	float v35;  // et1
	double v36; // st7
	float v37;  // et1
	int v38;    // eax
	float v39;  // et1
	int v40;    // edi
	int v41;    // eax
	int v42;    // ebx
	float v43;  // edx
	float v44;  // [esp+8h] [ebp-5Ch]
	float v45;  // [esp+8h] [ebp-5Ch]
	float v46;  // [esp+8h] [ebp-5Ch]
	float v47;  // [esp+8h] [ebp-5Ch]
	float v48;  // [esp+1Ch] [ebp-48h]
	float v49;  // [esp+1Ch] [ebp-48h]
	float v50;  // [esp+20h] [ebp-44h]
	float v51;  // [esp+20h] [ebp-44h]
	int v52;    // [esp+24h] [ebp-40h]
	int v53;    // [esp+24h] [ebp-40h]
	float v54;  // [esp+24h] [ebp-40h]
	float v55;  // [esp+24h] [ebp-40h]
	float v56;  // [esp+28h] [ebp-3Ch]
	float v57;  // [esp+28h] [ebp-3Ch]
	float v58;  // [esp+28h] [ebp-3Ch]
	float a1c;  // [esp+2Ch] [ebp-38h]
	int a1a;    // [esp+2Ch] [ebp-38h]
	int a1b;    // [esp+2Ch] [ebp-38h]
	float v62;  // [esp+30h] [ebp-34h]
	float v63;  // [esp+34h] [ebp-30h]
	int v64;    // [esp+38h] [ebp-2Ch]
	int v65;    // [esp+38h] [ebp-2Ch]
	float v66;  // [esp+38h] [ebp-2Ch]
	int v67;    // [esp+38h] [ebp-2Ch]
	int v68;    // [esp+38h] [ebp-2Ch]
	float v69;  // [esp+3Ch] [ebp-28h]
	float v70;  // [esp+3Ch] [ebp-28h]
	float v71;  // [esp+40h] [ebp-24h]
	float v72;  // [esp+40h] [ebp-24h]
	double v73; // [esp+44h] [ebp-20h]
	float v74;  // [esp+4Ch] [ebp-18h]
	float v75;  // [esp+50h] [ebp-14h]
	float4 a4a; // [esp+54h] [ebp-10h]

	v44 = a1->field_0 * 0.043478262;
	v4 = nox_float2int(v44);
	v45 = a1->field_4 * 0.043478262;
	v5 = nox_float2int(v45);
	v46 = a1->field_8 * 0.043478262;
	v6 = COERCE_FLOAT(nox_float2int(v46));
	v7 = a1->field_C * 0.043478262;
	v74 = v6;
	v47 = v7;
	v8 = nox_float2int(v47);
	if (v4 < 0 || v4 >= 256 || v5 < 0 || v5 >= 256)
		return 0;
	if (v4 == LODWORD(v74)) {
		v52 = -1;
		if (a1->field_C >= (double)a1->field_4)
			v52 = 1;
		v64 = v8 + v52;
		if (v5 != v8 + v52) {
			while (!sub_57C9A0(v4, v5, a1, &a4a, a4)) {
				v5 += v52;
				if (v5 == v64)
					return 1;
			}
			if (a2) {
				v10 = a4a.field_4;
				a2->field_0 = a4a.field_0;
				a2->field_4 = v10;
			}
		LABEL_14:
			if (a3) {
				a3->field_0 = v4;
				a3->field_4 = v5;
			}
			return 0;
		}
	} else {
		v11 = a1->field_8;
		if (v5 == v8) {
			if (v11 >= a1->field_0)
				v12 = 1;
			else
				v12 = -1;
			v53 = v12;
			v65 = LODWORD(v74) + v12;
			if (v4 != LODWORD(v74) + v12) {
				while (!sub_57C9A0(v4, v5, a1, &a4a, a4)) {
					v4 += v53;
					if (v4 == v65)
						return 1;
				}
				if (a2) {
					v13 = a4a.field_4;
					a2->field_0 = a4a.field_0;
					a2->field_4 = v13;
				}
				goto LABEL_14;
			}
		} else {
			a1c = v11 - a1->field_0;
			v14 = a1->field_C - a1->field_4;
			v56 = v14;
			v62 = v14 / a1c;
			v63 = a1->field_4 - v56 * a1->field_0 / a1c;
			v66 = sub_419A10(a1c);
			if (sub_419A10(v56) >= v66) {
				if (a1->field_0 >= (double)a1->field_8) {
					v58 = a1->field_8;
					v55 = a1->field_0;
					v51 = -1.0;
				} else {
					v58 = a1->field_0;
					v55 = a1->field_8;
					v51 = 1.0;
				}
				v49 = 1.0;
				if (a1->field_4 >= (double)a1->field_C)
					v49 = -1.0;
				v30 = a1->field_0;
				if (v30 <= v55) {
					while (v30 >= v58) {
						v31 = *(float*)&dword_587000_264364;
						modf(v30 / v31, &v73);
						v32 = *(float*)&dword_587000_264364;
						v33 = nox_double2float(v32 * v73);
						if (v51 <= *(double*)&qword_581450_9568) {
							v70 = v33;
							v35 = *(float*)&dword_587000_264364;
							v74 = v33 + v35;
						} else {
							v74 = v33;
							v34 = *(float*)&dword_587000_264364;
							v70 = v33 + v34;
						}
						a1b = nox_double2int(v73);
						v36 = v74 * v62 + v63;
						if (v49 > *(double*)&qword_581450_9568 && v36 < a1->field_4 ||
						    v49 < *(double*)&qword_581450_9568 && v36 > a1->field_4) {
							v36 = a1->field_4;
						}
						v72 = v70 * v62 + v63;
						if (v49 > *(double*)&qword_581450_9568 && v72 > (double)a1->field_C ||
						    v49 < *(double*)&qword_581450_9568 && v72 < (double)a1->field_C) {
							v72 = a1->field_C;
						}
						v37 = *(float*)&dword_587000_264364;
						modf(v36 / v37, &v73);
						v38 = nox_double2int(v73 - v49);
						v39 = *(float*)&dword_587000_264364;
						v40 = v38;
						modf(v72 / v39, &v73);
						v41 = nox_double2int(v49 + v73);
						v42 = v40 >= v41 ? -1 : 1;
						v68 = v42 + v41;
						if (v40 != v42 + v41) {
							while (!sub_57C9A0(a1b, v40, a1, &a4a, a4)) {
								v40 += v42;
								if (v40 == v68)
									goto LABEL_80;
							}
							if (a2) {
								v43 = a4a.field_4;
								a2->field_0 = a4a.field_0;
								a2->field_4 = v43;
							}
							if (a3) {
								a3->field_4 = v40;
								a3->field_0 = a1b;
								return 0;
							}
							return 0;
						}
					LABEL_80:
						v30 = v51 * 0.1 + v70;
						if (v30 > v55)
							return 1;
					}
				}
			} else {
				if (a1->field_4 >= (double)a1->field_C) {
					v57 = a1->field_C;
					v54 = a1->field_4;
					v50 = -1.0;
				} else {
					v57 = a1->field_4;
					v54 = a1->field_C;
					v50 = 1.0;
				}
				v48 = 1.0;
				if (a1->field_0 >= (double)a1->field_8)
					v48 = -1.0;
				v15 = a1->field_4;
				if (v15 <= v54) {
					while (v15 >= v57) {
						v16 = *(float*)&dword_587000_264364;
						modf(v15 / v16, &v73);
						v17 = *(float*)&dword_587000_264364;
						v18 = v17 * v73;
						if (v50 <= *(double*)&qword_581450_9568) {
							v20 = nox_double2float(v18);
							v71 = v20;
							v21 = *(float*)&dword_587000_264364;
							v75 = v20 + v21;
						} else {
							v75 = nox_double2float(v18);
							v19 = *(float*)&dword_587000_264364;
							v71 = v19 + v75;
						}
						a1a = nox_double2int(v73);
						v22 = (v75 - v63) / v62;
						if (v48 > *(double*)&qword_581450_9568 && v22 < a1->field_0 ||
						    v48 < *(double*)&qword_581450_9568 && v22 > a1->field_0) {
							v22 = a1->field_0;
						}
						v69 = (v71 - v63) / v62;
						if (v48 > *(double*)&qword_581450_9568 && v69 > (double)a1->field_8 ||
						    v48 < *(double*)&qword_581450_9568 && v69 < (double)a1->field_8) {
							v69 = a1->field_8;
						}
						v23 = *(float*)&dword_587000_264364;
						modf(v22 / v23, &v73);
						v24 = nox_double2int(v73 - v48);
						v25 = *(float*)&dword_587000_264364;
						v26 = v24;
						modf(v69 / v25, &v73);
						v27 = nox_double2int(v48 + v73);
						v28 = v26 >= v27 ? -1 : 1;
						v67 = v28 + v27;
						if (v26 != v28 + v27) {
							while (!sub_57C9A0(v26, a1a, a1, &a4a, a4)) {
								v26 += v28;
								if (v26 == v67)
									goto LABEL_51;
							}
							if (a2) {
								v29 = a4a.field_4;
								a2->field_0 = a4a.field_0;
								a2->field_4 = v29;
							}
							if (a3) {
								a3->field_0 = v26;
								a3->field_4 = a1a;
								return 0;
							}
							return 0;
						}
					LABEL_51:
						v15 = v50 * 0.1 + v71;
						if (v15 > v54)
							return 1;
					}
				}
			}
		}
	}
	return 1;
}

//----- (00535960) --------------------------------------------------------
void sub_535960() { nox_srand(0x8A2u); }

//----- (00535970) --------------------------------------------------------
int __cdecl sub_535970(int a1, int a2, char* a3) {
	sscanf(a3, "%f", a1 + 44);
	return 1;
}

//----- (00535990) --------------------------------------------------------
int __cdecl sub_535990(int a1, int a2, char* a3) { return nox_parse_shape((nox_shape*)(a1 + 60), a3); }

//----- (005359B0) --------------------------------------------------------
int __cdecl sub_5359B0(int a1, int a2, char* a3) {
	int v5; // [esp+0h] [ebp-4h]

	sscanf(a3, "%d %d", &v5, &a3);
	if ((int)a3 < (int)v5)
		a3 = v5;
	*(float*)(a1 + 112) = (double)(int)v5;
	*(float*)(a1 + 116) = (double)(int)a3;
	return 1;
}

//----- (00535A00) --------------------------------------------------------
int __cdecl sub_535A00(int a1, int a2, char* a3) {
	sscanf(a3, "%d", a1 + 48);
	return 1;
}

//----- (00535A20) --------------------------------------------------------
int __cdecl sub_535A20(int a1, int a2, char* a3) {
	double v3; // st7

	sscanf(a3, "%d", &a3);
	v3 = (double)(int)a3 * 0.03125;
	*(_DWORD*)(a1 + 132) = 0;
	*(float*)(a1 + 124) = v3;
	*(float*)(a1 + 128) = v3;
	return 1;
}

//----- (00535A60) --------------------------------------------------------
int __cdecl sub_535A60(int a1, int a2, char* a3) {
	int result; // eax

	sscanf(a3, "%d", &a3);
	if (*(_DWORD*)(a1 + 136))
		free(*(LPVOID*)(a1 + 136));
	result = (int)nox_calloc(1u, 0x14u);
	*(_DWORD*)(a1 + 136) = result;
	if (result) {
		*(_WORD*)(result + 4) = (_WORD)a3;
		**(_WORD**)(a1 + 136) = (_WORD)a3;
		result = 1;
	}
	return result;
}

//----- (00535AD0) --------------------------------------------------------
int __cdecl sub_535AD0(int a1, int a2, const char* a3) {
	*(_DWORD*)(a1 + 32) = 0;
	sub_423930(a3, (_DWORD*)(a1 + 32), (const char**)&byte_587000[264368]);
	return 1;
}

//----- (00535B00) --------------------------------------------------------
int __cdecl sub_535B00(int a1, int a2, const char* a3) {
	*(_DWORD*)(a1 + 24) = 0;
	sub_423930(a3, (_DWORD*)(a1 + 24), (const char**)&byte_587000[264500]);
	return 1;
}

//----- (00535B30) --------------------------------------------------------
int __cdecl sub_535B30(int a1, int a2, const char* a3) {
	*(_DWORD*)(a1 + 28) = 0;
	sub_423A10(a3, (_DWORD*)(a1 + 28));
	return 1;
}

//----- (00535B60) --------------------------------------------------------
int __cdecl sub_535B60(int a1, int a2, char* a3) {
	sscanf(a3, "%f", a1 + 56);
	return 1;
}

//----- (00535B80) --------------------------------------------------------
int __cdecl sub_535B80(int a1, int a2, char* a3) {
	sscanf(a3, "%d", &a3);
	*(_WORD*)(a1 + 122) = (_WORD)a3;
	return 1;
}

//----- (00535BB0) --------------------------------------------------------
int __cdecl sub_535BB0(int a1, int a2, char* a3) {
	sscanf(a3, "%d", &a3);
	*(_BYTE*)(a1 + 120) = (_BYTE)a3;
	return 1;
}

//----- (00535BE0) --------------------------------------------------------
int __cdecl sub_535BE0(int a1, int a2, const char* a3) {
	int v4; // [esp+0h] [ebp-4h]

	v4 = 0;
	sub_423930(a3, &v4, (const char**)&byte_587000[265912]);
	*(_WORD*)(a1 + 40) = v4;
	return 1;
}

//----- (00535C20) --------------------------------------------------------
int sub_535C20(int a1, int a2, char* a3) { return 1; }

//----- (00535C30) --------------------------------------------------------
int __cdecl sub_535C30(int a1, int a2, char* a3) {
	int v2; // edx

	*(_DWORD*)(a1 + 12) = **(_DWORD**)(a2 + 8);
	v2 = *(_DWORD*)(a2 + 8) + 4;
	*(_DWORD*)(a2 + 8) = v2;
	if (*(int*)(a1 + 12) == -1) {
		*(_DWORD*)(a2 + 8) = v2 + 1;
		*(_DWORD*)(a2 + 8) = *(unsigned __int8*)(v2 + 1) + v2 + 1 + 1;
	}
	return 1;
}

//----- (00535C80) --------------------------------------------------------
int __cdecl sub_535C80(int a1, int a2) {
	int* v2;             // ecx
	int v3;              // edx
	int v4;              // ecx
	unsigned __int8* v5; // ecx

	v2 = *(int**)(a2 + 8);
	v3 = *v2;
	v4 = (int)(v2 + 1);
	*(_DWORD*)(a2 + 8) = v4;
	if (v3 == -1) {
		v5 = (unsigned __int8*)(v4 + 1);
		*(_DWORD*)(a2 + 8) = v5;
		*(_DWORD*)(a2 + 8) = &v5[*v5 + 1];
	}
	return 1;
}

//----- (00535CC0) --------------------------------------------------------
void sub_535CC0() { nox_srand(0x8A3u); }

//----- (00535CD0) --------------------------------------------------------
int __cdecl sub_535CD0(int a1, _DWORD* a2, void* a3) {
	_DWORD* v3;           // ebp
	void* v4;             // ebx
	unsigned __int8* v5;  // eax
	int result;           // eax
	int v7;               // esi
	char* v8;             // eax
	_DWORD* v9;           // eax
	int v10;              // ecx
	char* v11;            // eax
	int v12;              // edi
	unsigned __int8* v13; // eax
	int v14;              // edi
	char* v15;            // esi
	unsigned __int8* v16; // eax
	int i;                // eax
	char* v18;            // ecx
	char v19;             // dl
	char* v20;            // eax
	char v21;             // cl
	char* v22;            // eax
	char v23;             // cl
	unsigned __int8* v24; // eax
	int v25;              // esi
	int* v26;             // eax
	int v27;              // ecx
	int v28;              // eax
	unsigned __int8* v29; // eax
	unsigned __int8 v30;  // di
	_DWORD* v31;          // eax
	int v32;              // ecx
	unsigned __int8* v33; // eax
	const char** v34;     // ecx
	unsigned __int8* v35; // eax
	unsigned __int8 v36;  // cl
	char v37;             // cl
	int v38;              // esi
	int* v39;             // ecx
	int v40;              // edx
	int v41;              // ecx
	unsigned __int8* v42; // ecx
	int v43;              // [esp-14h] [ebp-2Ch]
	_DWORD* v44;          // [esp-4h] [ebp-1Ch]
	int v45;              // [esp+10h] [ebp-8h]
	int v46;              // [esp+14h] [ebp-4h]
	char* v47;            // [esp+1Ch] [ebp+4h]
	unsigned __int8 v48;  // [esp+1Ch] [ebp+4h]
	unsigned __int8 v49;  // [esp+20h] [ebp+8h]
	unsigned __int8 v50;  // [esp+20h] [ebp+8h]
	unsigned __int8 v51;  // [esp+20h] [ebp+8h]
	unsigned __int8 v52;  // [esp+20h] [ebp+8h]
	unsigned __int8 v53;  // [esp+20h] [ebp+8h]
	unsigned __int8 v54;  // [esp+20h] [ebp+8h]
	unsigned __int8 v55;  // [esp+20h] [ebp+8h]
	int v56;              // [esp+24h] [ebp+Ch]
	int v57;              // [esp+24h] [ebp+Ch]

	v3 = a2;
	v4 = a3;
	v5 = (unsigned __int8*)a2[2];
	v44 = a2;
	v49 = *v5;
	v44[2] = v5 + 1;
	nox_memfile_read(a3, 1u, v49, (int)v44);
	*((_BYTE*)a3 + v49) = 0;
	sub_40AD60((char*)&v45, 4, 1, v3);
	result = 0;
	if (!strcmp((const char*)a3, "MonsterDraw")) {
		v7 = *(_DWORD*)(a1 + 192);
		if (!v7)
			return result;
		v8 = (char*)nox_calloc(1u, 0x100u);
		v47 = v8;
		if (!v8)
			return 0;
		*(_DWORD*)(v7 + 476) = v8;
		while (1) {
			v9 = (_DWORD*)v3[2];
			v10 = *v9;
			v11 = (char*)(v9 + 1);
			v3[2] = v11;
			if (v10 != 1398030676)
				break;
			v12 = *v11;
			v13 = (unsigned __int8*)(v11 + 1);
			v3[2] = v13;
			if (v12 >= 16)
				return 0;
			v50 = *v13;
			v3[2] = v13 + 1;
			nox_memfile_read(v4, 1u, v50, (int)v3);
			*((_BYTE*)v4 + v50) = 0;
			v14 = 16 * v12;
			v15 = &v47[v14];
			v56 = (int)&v47[v14];
			*(_DWORD*)&v47[v14] = sub_40AF50(v4);
			v16 = (unsigned __int8*)v3[2];
			v51 = *v16;
			v3[2] = v16 + 1;
			for (i = 0; i < v51; ++i) {
				v18 = (char*)v3[2];
				v19 = *v18;
				v3[2] = v18 + 1;
				v15[i + 4] = v19;
			}
			v15[8] = i;
			v20 = (char*)v3[2];
			v21 = *v20;
			v3[2] = v20 + 1;
			v15[9] = v21;
			v22 = (char*)v3[2];
			v23 = *v22;
			v3[2] = v22 + 1;
			v15[10] = v23;
			v24 = (unsigned __int8*)v3[2];
			v52 = *v24;
			v3[2] = v24 + 1;
			nox_memfile_read(v4, 1u, v52, (int)v3);
			*((_BYTE*)v4 + v52) = 0;
			*(_DWORD*)(v56 + 12) =
			    !strcmp((const char*)v4, "Loop") || !strcmp((const char*)v4, "LoopAndFade");
			v45 = 8 * *(unsigned __int8*)(v56 + 9);
			if (v45 > 0) {
				v25 = v45;
				do {
					v26 = (int*)v3[2];
					v27 = *v26;
					v28 = (int)(v26 + 1);
					v3[2] = v28;
					if (v27 == -1) {
						v29 = (unsigned __int8*)(v28 + 1);
						v3[2] = v29;
						v3[2] = &v29[*v29 + 1];
					}
					--v25;
				} while (v25);
			}
		}
	} else {
		if (!strcmp((const char*)a3, "AnimateStateDraw")) {
			v3[2] += v45;
			return 1;
		}
		if (!strcmp((const char*)a3, "PlayerDraw")) {
			v30 = a1;
			while (1) {
				v31 = (_DWORD*)v3[2];
				v32 = *v31;
				v33 = (unsigned __int8*)(v31 + 1);
				v3[2] = v33;
				if (v32 == 1162757152)
					break;
				if (v32 == 1398030676) {
					v53 = *v33;
					v3[2] = v33 + 1;
					nox_memfile_read(v4, 1u, v53, (int)v3);
					*((_BYTE*)v4 + v53) = 0;
					v57 = 0;
					v34 = (const char**)&byte_587000[268120];
					do {
						if (!strcmp(*v34, (const char*)v4))
							break;
						++v34;
						++v57;
					} while ((int)v34 < (int)&byte_587000[268340]);
					if (v57 == 55)
						return 0;
					v35 = (unsigned __int8*)v3[2];
					v36 = *v35++;
					v3[2] = v35;
					v48 = v36;
					v37 = *v35++;
					v3[2] = v35;
					LOBYTE(v46) = v37;
					v54 = *v35;
					v3[2] = v35 + 1;
					nox_memfile_read(v4, 1u, v54, (int)v3);
					v30 = v48;
					v43 = (unsigned __int8)v46;
					*((_BYTE*)v4 + v54) = 0;
					sub_4F9FB0(v57, v48, v43);
				} else if (v32 == 1397051733) {
					v55 = *v33;
					v3[2] = v33 + 1;
					nox_memfile_read(v4, 1u, v55, (int)v3);
					*((_BYTE*)v4 + v55) = 0;
					v45 = 8 * v30;
					if (8 * v30 > 0) {
						v38 = 8 * v30;
						do {
							v39 = (int*)v3[2];
							v40 = *v39;
							v41 = (int)(v39 + 1);
							v3[2] = v41;
							if (v40 == -1) {
								v42 = (unsigned __int8*)(v41 + 1);
								v3[2] = v42;
								v3[2] = &v42[*v42 + 1];
							}
							--v38;
						} while (v38);
					}
				}
			}
		} else {
			v3[2] += v45;
		}
	}
	return 1;
}

//----- (005360A0) --------------------------------------------------------
int __cdecl sub_5360A0(int a1, int a2, char* a3) {
	char* v3;            // eax
	const char* v4;      // ecx
	int v5;              // ebp
	unsigned __int8* v6; // edi

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)&byte_587000[269128];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[269128]) {
		v6 = &byte_587000[269128];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 2);
			v6 += 8;
			++v5;
		} while (v4);
	}
	if (!*(_DWORD*)&byte_587000[8 * v5 + 269128])
		return 0;
	*(_DWORD*)(a1 + 212) = *(_DWORD*)&byte_587000[8 * v5 + 269132];
	return 1;
}

//----- (00536130) --------------------------------------------------------
char* __cdecl sub_536130(char* a1, int* a2) {
	char* result; // eax
	int v3;       // eax
	char* v4;     // eax

	result = strtok(a1, " ");
	if (result) {
		v3 = sub_424880(result);
		*a2 = v3;
		if (v3 == -1) {
			result = 0;
		} else {
			v4 = strtok(0, " ");
			a2[1] = atoi(v4);
			result = (char*)1;
		}
	}
	return result;
}

//----- (00536180) --------------------------------------------------------
char* __cdecl sub_536180(char* a1, int* a2) {
	char* result; // eax

	result = strtok(a1, " ");
	if (result) {
		*a2 = sub_4243F0(result);
		result = (char*)1;
	}
	return result;
}

//----- (005361B0) --------------------------------------------------------
char* __cdecl sub_5361B0(char* a1, int a2) {
	char* result; // eax
	char v3;      // al
	double v4;    // [esp+4h] [ebp-8h]

	*(_DWORD*)a2 = 1;
	result = strtok(a1, " ");
	if (result) {
		v3 = atoi(result);
		*(_BYTE*)(a2 + 109) = v3;
		*(_BYTE*)(a2 + 108) = v3;
		*(_DWORD*)(a2 + 112) = 100;
		result = strtok(0, " ");
		if (result) {
			v4 = (double)*(unsigned int*)&byte_5D4594[2649704];
			*(_DWORD*)(a2 + 100) = (__int64)(v4 / atof(result));
			result = strtok(0, " ");
			if (result) {
				*(_DWORD*)(a2 + 92) = sub_4243F0(result);
				result = (char*)1;
			}
		}
	}
	return result;
}

//----- (00536260) --------------------------------------------------------
char* __cdecl sub_536260(char* a1, int a2) {
	char* result; // eax
	char v3;      // al
	char* v4;     // eax
	int v5;       // eax
	char* v6;     // eax
	double v7;    // [esp+Ch] [ebp-8h]
	double v8;

	*(_DWORD*)a2 = 0;
	result = strtok(a1, " ");
	if (result) {
		v3 = atoi(result);
		*(_BYTE*)(a2 + 109) = v3;
		*(_BYTE*)(a2 + 108) = v3;
		*(_DWORD*)(a2 + 112) = 100;
		result = strtok(0, " ");
		if (result) {
			strcpy((char*)(a2 + 4), result);
			*(_DWORD*)(a2 + 84) = 0;
			result = strtok(0, " ");
			if (result) {
				v7 = (double)*(unsigned int*)&byte_5D4594[2649704];
				v8 = atof(result);
				if (v8 == 0.0) {
					*(_DWORD*)(a2 + 100) = 0;
				} else {
					*(_DWORD*)(a2 + 100) = (__int64)(v7 / v8);
				}
				v4 = strtok(0, " ");
				if (v4 && !strcmp(v4, "MULTI_SHOT")) {
					v5 = *(_DWORD*)(a2 + 96);
					LOBYTE(v5) = v5 | 1;
					*(_DWORD*)(a2 + 96) = v5;
				}
				v6 = strtok(0, " ");
				if (v6)
					*(_DWORD*)(a2 + 88) = sub_40AF50(v6);
				result = (char*)1;
			}
		}
	}
	return result;
}

//----- (00536390) --------------------------------------------------------
char* __cdecl sub_536390(char* a1, int* a2) {
	char* result; // eax

	result = strtok(a1, " ");
	if (result) {
		*a2 = atoi(result);
		result = (char*)1;
	}
	return result;
}

//----- (005363C0) --------------------------------------------------------
char* __cdecl sub_5363C0(char* a1, int* a2) {
	char* result; // eax

	result = strtok(a1, " ");
	if (result) {
		*a2 = atoi(result);
		result = (char*)1;
	}
	return result;
}

//----- (005363F0) --------------------------------------------------------
int __cdecl sub_5363F0(_DWORD* a1, int a2, char* a3) {
	char* v3;                      // ebx
	const char* v4;                // eax
	int v5;                        // ebp
	unsigned __int8* v6;           // edi
	int v7;                        // ebp
	int result;                    // eax
	int(__cdecl * v9)(char*, int); // esi
	char* v10;                     // [esp+1Ch] [ebp+Ch]

	v3 = strtok(a3, " \t\n\r");
	v10 = strtok(0, (const char*)&byte_5D4594[2488564]);
	v4 = *(const char**)&byte_587000[269784];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[269784]) {
		v6 = &byte_587000[269784];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 4);
			v6 += 16;
			++v5;
		} while (v4);
	}
	v7 = 16 * v5;
	if (!*(_DWORD*)&byte_587000[v7 + 269784])
		goto LABEL_13;
	a1[50] = *(_DWORD*)&byte_587000[v7 + 269788];
	a1[52] = *(_DWORD*)&byte_587000[v7 + 269792];
	if (!*(_DWORD*)&byte_587000[v7 + 269792])
		goto LABEL_13;
	result = (int)nox_calloc(1u, *(_DWORD*)&byte_587000[v7 + 269792]);
	a1[51] = result;
	if (!result)
		return result;
	v9 = *(int(__cdecl**)(char*, int)) & byte_587000[v7 + 269796];
	if (v9)
		result = v9(v10, result);
	else
	LABEL_13:
		result = 1;
	return result;
}

//----- (005364E0) --------------------------------------------------------
int __cdecl sub_5364E0(char* a1, int a2) {
	unsigned int v2; // ecx
	char v3;         // al
	char* v4;        // edi
	char* v5;        // esi
	int result;      // eax
	char v7[256];    // [esp+Ch] [ebp-100h]

	sscanf(a1, "%s", v7);
	v2 = strlen(v7) + 1;
	v3 = v2;
	v2 >>= 2;
	qmemcpy((void*)(a2 + 16), v7, 4 * v2);
	v5 = &v7[4 * v2];
	v4 = (char*)(a2 + 16 + 4 * v2);
	LOBYTE(v2) = v3;
	result = 1;
	qmemcpy(v4, v5, v2 & 3);
	*(_DWORD*)(a2 + 12) = 0;
	return result;
}
// 5364E0: using guessed type char var_100[256];

//----- (00536550) --------------------------------------------------------
int __cdecl sub_536550(char* a1, _DWORD* a2) {
	sscanf(a1, "%f %f", a2, a2 + 2);
	a2[1] = *a2;
	return 1;
}

//----- (00536580) --------------------------------------------------------
int __cdecl sub_536580(char* a1, int a2) {
	sscanf(a1, "%d %d %d", a2, a2 + 4, a2 + 8);
	return 1;
}

//----- (005365B0) --------------------------------------------------------
int __cdecl sub_5365B0(char* a1, int a2) {
	char* v2; // eax
	char* v3; // eax

	v2 = strtok(a1, " ");
	if (v2)
		*(_DWORD*)(a2 + 36) = sub_40AF50(v2);
	v3 = strtok(0, " ");
	if (v3)
		*(_DWORD*)(a2 + 40) = sub_40AF50(v3);
	return 1;
}

//----- (00536600) --------------------------------------------------------
int __cdecl sub_536600(char* a1, int a2) {
	sscanf(a1, "%d", a2);
	return 1;
}

//----- (00536620) --------------------------------------------------------
int __cdecl sub_536620(_DWORD* a1, int a2, char* a3) {
	char* v3;                      // ebx
	const char* v4;                // eax
	int v5;                        // ebp
	unsigned __int8* v6;           // edi
	int v7;                        // ebp
	int result;                    // eax
	int(__cdecl * v9)(char*, int); // esi
	char* v10;                     // [esp+1Ch] [ebp+Ch]

	v3 = strtok(a3, " \t\n\r");
	v10 = strtok(0, (const char*)&byte_5D4594[2488568]);
	v4 = *(const char**)&byte_587000[270328];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[270328]) {
		v6 = &byte_587000[270328];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 4);
			v6 += 16;
			++v5;
		} while (v4);
	}
	v7 = 16 * v5;
	if (!*(_DWORD*)&byte_587000[v7 + 270328])
		goto LABEL_13;
	a1[47] = *(_DWORD*)&byte_587000[v7 + 270332];
	a1[49] = *(_DWORD*)&byte_587000[v7 + 270336];
	if (!*(_DWORD*)&byte_587000[v7 + 270336])
		goto LABEL_13;
	result = (int)nox_calloc(1u, *(_DWORD*)&byte_587000[v7 + 270336]);
	a1[48] = result;
	if (!result)
		return result;
	v9 = *(int(__cdecl**)(char*, int)) & byte_587000[v7 + 270340];
	if (v9)
		result = v9(v10, result);
	else
	LABEL_13:
		result = 1;
	return result;
}

//----- (00536710) --------------------------------------------------------
int __cdecl sub_536710(int a1, int a2, char* a3) {
	char* v3;                // eax
	const char* v4;          // ecx
	int v5;                  // ebp
	unsigned __int8* v6;     // edi
	void(__cdecl * v7)(int); // eax

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)&byte_587000[272352];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[272352]) {
		v6 = &byte_587000[272352];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 3);
			v6 += 12;
			++v5;
		} while (v4);
	}
	if (*(_DWORD*)&byte_587000[12 * v5 + 272352]) {
		*(_DWORD*)(a1 + 184) = *(_DWORD*)&byte_587000[12 * v5 + 272356];
		v7 = *(void(__cdecl**)(int)) & byte_587000[12 * v5 + 272360];
		if (v7)
			v7(a1);
	}
	return 1;
}

//----- (005367B0) --------------------------------------------------------
char* __cdecl sub_5367B0(__int16* a1) {
	unsigned __int8* v1; // eax
	int v2;              // ecx
	char* result;        // eax
	unsigned __int8* i;  // esi
	__int16 v5;          // dx

	if (!*(_DWORD*)&byte_5D4594[2488572]) {
		v1 = &byte_5D4594[3815404];
		v2 = 51;
		do {
			*(_WORD*)v1 = -1;
			*((_WORD*)v1 + 1) = 0;
			v1 += 4;
			--v2;
		} while (v2);
		*(_DWORD*)&byte_5D4594[2488572] = 1;
	}
	result = 0;
	for (i = &byte_5D4594[3815404]; *(short*)i != -1; i += 4) {
		if ((int)++result >= 50)
			return result;
	}
	result = strtok(0, " \t\n\r");
	if (result && *result) {
		result = (char*)sub_40AF50(result);
		if ((_WORD)result) {
			v5 = *a1;
			*((_WORD*)i + 1) = (_WORD)result;
			*(_WORD*)i = v5;
		}
	}
	return result;
}

//----- (00536830) --------------------------------------------------------
int __cdecl sub_536830(int a1, int a2, char* a3) {
	char* v3;            // eax
	const char* v4;      // ecx
	int v5;              // ebp
	unsigned __int8* v6; // edi

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)&byte_587000[272808];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[272808]) {
		v6 = &byte_587000[272808];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 3);
			v6 += 12;
			++v5;
		} while (v4);
	}
	if (*(_DWORD*)&byte_587000[12 * v5 + 272808])
		*(_DWORD*)(a1 + 216) = *(_DWORD*)&byte_587000[12 * v5 + 272812];
	return 1;
}

//----- (005368C0) --------------------------------------------------------
int __cdecl sub_5368C0(char* a1, int a2) {
	int* v2;  // esi
	char* v3; // eax
	char* v4; // eax

	v2 = *(int**)(a2 + 176);
	v3 = strtok(a1, " ");
	*v2 = atoi(v3);
	v4 = strtok(0, " ");
	v2[1] = atoi(v4);
	return 1;
}

//----- (00536910) --------------------------------------------------------
int __cdecl sub_536910(int a1, int a2) {
	*(_DWORD*)(a2 + 36) = 2;
	return 1;
}

//----- (00536930) --------------------------------------------------------
int __cdecl sub_536930(_DWORD* a1, int a2, char* a3) {
	char* v3;                          // ebx
	const char* v4;                    // eax
	int v5;                            // ebp
	unsigned __int8* v6;               // edi
	int v7;                            // ebp
	int result;                        // eax
	int(__cdecl * v9)(char*, _DWORD*); // esi
	char* v10;                         // [esp+1Ch] [ebp+Ch]

	v3 = strtok(a3, " \t\n\r");
	v10 = strtok(0, (const char*)&byte_5D4594[2488576]);
	v4 = *(const char**)&byte_587000[273112];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[273112]) {
		v6 = &byte_587000[273112];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 4);
			v6 += 16;
			++v5;
		} while (v4);
	}
	v7 = 16 * v5;
	if (!*(_DWORD*)&byte_587000[v7 + 273112])
		goto LABEL_13;
	a1[43] = *(_DWORD*)&byte_587000[v7 + 273116];
	a1[45] = *(_DWORD*)&byte_587000[v7 + 273120];
	if (!*(_DWORD*)&byte_587000[v7 + 273120])
		goto LABEL_13;
	result = (int)nox_calloc(1u, *(_DWORD*)&byte_587000[v7 + 273120]);
	a1[44] = result;
	if (!result)
		return result;
	v9 = *(int(__cdecl**)(char*, _DWORD*)) & byte_587000[v7 + 273124];
	if (v9)
		result = v9(v10, a1);
	else
	LABEL_13:
		result = 1;
	return result;
}

//----- (00536A20) --------------------------------------------------------
int __cdecl sub_536A20(int a1, int a2, char* a3) {
	char* v3;                // eax
	const char* v4;          // ecx
	int v5;                  // ebp
	unsigned __int8* v6;     // edi
	void(__cdecl * v7)(int); // eax

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)&byte_587000[273768];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[273768]) {
		v6 = &byte_587000[273768];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 3);
			v6 += 12;
			++v5;
		} while (v4);
	}
	if (*(_DWORD*)&byte_587000[12 * v5 + 273768]) {
		*(_DWORD*)(a1 + 168) = *(_DWORD*)&byte_587000[12 * v5 + 273772];
		v7 = *(void(__cdecl**)(int)) & byte_587000[12 * v5 + 273776];
		if (v7)
			v7(a1);
	}
	return 1;
}

//----- (00536AC0) --------------------------------------------------------
char* __cdecl sub_536AC0(__int16* a1) {
	unsigned __int8* v1; // eax
	int v2;              // ecx
	char* result;        // eax
	unsigned __int8* i;  // esi
	__int16 v5;          // dx

	if (!*(_DWORD*)&byte_5D4594[2488580]) {
		v1 = &byte_5D4594[3815180];
		v2 = 51;
		do {
			*(_WORD*)v1 = -1;
			*((_WORD*)v1 + 1) = 0;
			v1 += 4;
			--v2;
		} while (v2);
		*(_DWORD*)&byte_5D4594[2488580] = 1;
	}
	result = 0;
	for (i = &byte_5D4594[3815180]; *(short*)i != -1; i += 4) {
		if ((int)++result >= 50)
			return result;
	}
	result = strtok(0, " \t\n\r");
	if (result && *result) {
		result = (char*)sub_40AF50(result);
		if ((_WORD)result) {
			v5 = *a1;
			*((_WORD*)i + 1) = (_WORD)result;
			*(_WORD*)i = v5;
		}
	}
	return result;
}

//----- (00536B40) --------------------------------------------------------
int __cdecl sub_536B40(char* a1, int a2) {
	char v3[64]; // [esp+4h] [ebp-40h]

	sscanf(a1, "%s %s", a2, v3);
	*(_DWORD*)(a2 + 128) = sub_40AF50(v3);
	return 1;
}

//----- (00536B80) --------------------------------------------------------
int __cdecl sub_536B80(int a1, int a2, char* a3) {
	char* v3;                      // ebx
	const char* v4;                // eax
	int v5;                        // ebp
	unsigned __int8* v6;           // edi
	int v7;                        // ebp
	int result;                    // eax
	int(__cdecl * v9)(char*, int); // esi
	char* v10;                     // [esp+1Ch] [ebp+Ch]

	v3 = strtok(a3, " \t\n\r");
	v10 = strtok(0, (const char*)&byte_5D4594[2488584]);
	v4 = *(const char**)&byte_587000[274080];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[274080]) {
		v6 = &byte_587000[274080];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 4);
			v6 += 16;
			++v5;
		} while (v4);
	}
	v7 = 16 * v5;
	if (!*(_DWORD*)&byte_587000[v7 + 274080])
		return 0;
	*(_DWORD*)(a1 + 160) = *(_DWORD*)&byte_587000[v7 + 274084];
	if (!*(_DWORD*)&byte_587000[v7 + 274088])
		goto LABEL_14;
	result = (int)nox_calloc(1u, *(_DWORD*)&byte_587000[v7 + 274088]);
	*(_DWORD*)(a1 + 164) = result;
	if (!result)
		return result;
	v9 = *(int(__cdecl**)(char*, int)) & byte_587000[v7 + 274092];
	if (v9)
		result = v9(v10, result);
	else
	LABEL_14:
		result = 1;
	return result;
}

//----- (00536C60) --------------------------------------------------------
int __cdecl sub_536C60(int a1, int a2, char* a3) {
	char* v3;            // eax
	const char* v4;      // ecx
	int v5;              // ebp
	unsigned __int8* v6; // edi

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)&byte_587000[274520];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[274520]) {
		v6 = &byte_587000[274520];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 2);
			v6 += 8;
			++v5;
		} while (v4);
	}
	if (!*(_DWORD*)&byte_587000[8 * v5 + 274520])
		return 0;
	*(_DWORD*)(a1 + 152) = *(_DWORD*)&byte_587000[8 * v5 + 274524];
	return 1;
}

//----- (00536CF0) --------------------------------------------------------
int __cdecl sub_536CF0(int a1, int a2, char* a3) {
	char* v3;            // eax
	const char* v4;      // ecx
	int v5;              // ebp
	unsigned __int8* v6; // edi

	v3 = strtok(a3, " \t\n\r");
	v4 = *(const char**)&byte_587000[274616];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[274616]) {
		v6 = &byte_587000[274616];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 2);
			v6 += 8;
			++v5;
		} while (v4);
	}
	if (!*(_DWORD*)&byte_587000[8 * v5 + 274616])
		return 0;
	*(_DWORD*)(a1 + 156) = *(_DWORD*)&byte_587000[8 * v5 + 274620];
	return 1;
}

//----- (00536D80) --------------------------------------------------------
int __cdecl sub_536D80(char* a1, int a2) {
	sscanf(a1, "%d", a2);
	return 1;
}

//----- (00536DA0) --------------------------------------------------------
BOOL __cdecl sub_536DA0(char* a1, int* a2) {
	int v2;       // eax
	char v4[256]; // [esp+0h] [ebp-100h]

	sscanf(a1, "%s", v4);
	v2 = sub_40AF50(v4);
	*a2 = v2;
	return v2 != 0;
}

//----- (00536DE0) --------------------------------------------------------
int __cdecl sub_536DE0(char* a1, _BYTE* a2) {
	sscanf(a1, "%d", &a1);
	*a2 = (_BYTE)a1;
	return 1;
}

//----- (00536E10) --------------------------------------------------------
BOOL __cdecl sub_536E10(char* a1, int a2) {
	char* v2; // eax
	char* v3; // eax
	int v4;   // eax

	v2 = strtok(a1, " ");
	*(_BYTE*)a2 = atoi(v2);
	v3 = strtok(0, " ");
	v4 = sub_4E0A00(v3);
	*(_DWORD*)(a2 + 4) = v4;
	return v4 != 18;
}

//----- (00536E50) --------------------------------------------------------
int __cdecl sub_536E50(char* a1, _BYTE* a2) {
	char* v2; // eax

	v2 = strtok(a1, " ");
	*a2 = atoi(v2);
	return 1;
}

//----- (00536E80) --------------------------------------------------------
int __cdecl sub_536E80(char* a1, int* a2) {
	char* v2; // eax
	char* v3; // eax

	v2 = strtok(a1, " ");
	*a2 = atoi(v2);
	v3 = strtok(a1, " ");
	a2[1] = atoi(v3);
	return 1;
}

//----- (00536EC0) --------------------------------------------------------
int __cdecl sub_536EC0(_DWORD* a1, int a2, char* a3) {
	char* v3;                      // ebx
	const char* v4;                // eax
	int v5;                        // ebp
	unsigned __int8* v6;           // edi
	int v7;                        // ebp
	int result;                    // eax
	int(__cdecl * v9)(char*, int); // esi
	char* v10;                     // [esp+1Ch] [ebp+Ch]

	v3 = strtok(a3, " \t\n\r");
	v10 = strtok(0, (const char*)&byte_5D4594[2488588]);
	v4 = *(const char**)&byte_587000[274872];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[274872]) {
		v6 = &byte_587000[274872];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 4);
			v6 += 16;
			++v5;
		} while (v4);
	}
	v7 = 16 * v5;
	if (!*(_DWORD*)&byte_587000[v7 + 274872])
		return 0;
	a1[35] = *(_DWORD*)&byte_587000[v7 + 274876];
	a1[37] = *(_DWORD*)&byte_587000[v7 + 274880];
	if (!*(_DWORD*)&byte_587000[v7 + 274880])
		goto LABEL_14;
	result = (int)nox_calloc(1u, *(_DWORD*)&byte_587000[v7 + 274880]);
	a1[36] = result;
	if (!result)
		return result;
	v9 = *(int(__cdecl**)(char*, int)) & byte_587000[v7 + 274884];
	if (v9)
		result = v9(v10, result);
	else
	LABEL_14:
		result = 1;
	return result;
}

//----- (00536FB0) --------------------------------------------------------
BOOL __cdecl sub_536FB0(int a1, int a2, char a3) {
	BOOL result; // eax
	int v4;      // eax
	int v5;      // eax
	int v6;      // eax

	if (!*(_DWORD*)&byte_5D4594[2488592]) {
		*(_DWORD*)&byte_5D4594[2488592] = sub_4E3AA0((CHAR*)&byte_587000[276736]);
		*(_DWORD*)&byte_5D4594[2488596] = sub_4E3AA0((CHAR*)&byte_587000[276744]);
		*(_DWORD*)&byte_5D4594[2488600] = sub_4E3AA0((CHAR*)&byte_587000[276752]);
	}
	if (sub_4FF350(a1, 2))
		return 0;
	if (a3 & 1 || !sub_4FF350(a2, 0))
		goto LABEL_10;
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		v4 = *(unsigned __int16*)(a1 + 4);
		if ((unsigned __int16)v4 == *(_DWORD*)&byte_5D4594[2488596] || v4 == *(_DWORD*)&byte_5D4594[2488600])
			goto LABEL_10;
	} else if (sub_4FF350(a1, 21)) {
		goto LABEL_10;
	}
	if (*(unsigned __int16*)(a1 + 4) != *(_DWORD*)&byte_5D4594[2488592] || (v6 = *(_DWORD*)(a1 + 508)) == 0 ||
	    !sub_4FF350(v6, 21)) {
		if (*(float*)&byte_587000[276732] >= fabs(*(float*)(a2 + 80)) &&
		    *(float*)&byte_587000[276732] >= fabs(*(float*)(a2 + 84))) {
			return 0;
		}
	}
LABEL_10:
	result = 1;
	if (*(_BYTE*)(a1 + 8) & 2) {
		v5 = *(_DWORD*)(a1 + 12);
		if (v5 & 0x2000) {
			if (nox_common_playerIsAbilityActive_4FC250(a2, 4))
				result = 0;
		}
	}
	return result;
}

//----- (005370E0) --------------------------------------------------------
int __cdecl sub_5370E0(int a1, int a2, char a3) {
	int result; // eax

	result = sub_536FB0(a1, a2, a3);
	if (result)
		result = sub_537110(a1, a2);
	return result;
}

//----- (00537110) --------------------------------------------------------
int __cdecl sub_537110(int a1, int a2) {
	int v2;     // eax
	int v3;     // esi
	int v4;     // eax
	int result; // eax
	float4 a1a; // [esp+4h] [ebp-2Ch]
	int a3[7];  // [esp+14h] [ebp-1Ch]

	v2 = *(_DWORD*)(a1 + 56);
	a3[4] = *(_DWORD*)(a1 + 60);
	a3[3] = v2;
	if (*(_BYTE*)(a2 + 8) < 0 && *(_BYTE*)(a2 + 12) & 4) {
		v3 = *(_DWORD*)(a2 + 748);
		*(float*)&a3[5] =
		    (double)(*(int*)&byte_587000[8 * *(_DWORD*)(v3 + 12) + 196184] / 2) + *(float*)(a2 + 56);
		*(float*)&a3[6] =
		    (double)(*(int*)&byte_587000[8 * *(_DWORD*)(v3 + 12) + 196188] / 2) + *(float*)(a2 + 60);
	} else {
		v4 = *(_DWORD*)(a2 + 60);
		a3[5] = *(_DWORD*)(a2 + 56);
		a3[6] = v4;
	}
	if (*(float*)&a3[3] >= (double)*(float*)&a3[5]) {
		a1a.field_8 = *(float*)&a3[3];
		LODWORD(a1a.field_0) = a3[5];
	} else {
		a1a.field_0 = *(float*)&a3[3];
		LODWORD(a1a.field_8) = a3[5];
	}
	if (*(float*)&a3[4] >= (double)*(float*)&a3[6]) {
		a1a.field_C = *(float*)&a3[4];
		LODWORD(a1a.field_4) = a3[6];
	} else {
		a1a.field_4 = *(float*)&a3[4];
		LODWORD(a1a.field_C) = a3[6];
	}
	a3[2] = a2;
	a3[0] = 1;
	a3[1] = a1;
	sub_517C10(&a1a, sub_537230, (int)a3);
	if (a3[0])
		result = sub_535250((float4*)&a3[3], 0, 0, 9);
	else
		result = 0;
	return result;
}

//----- (00537230) --------------------------------------------------------
void __cdecl sub_537230(float* a1, int arg4) {
	int v2;     // ecx
	int v3;     // eax
	double v4;  // st7
	int v5;     // eax
	double v6;  // st6
	double v7;  // st7
	double v8;  // st7
	double v9;  // st7
	double v10; // st7
	float v11;  // [esp+14h] [ebp-2Ch]
	float v12;  // [esp+18h] [ebp-28h]
	float v13;  // [esp+1Ch] [ebp-24h]
	float v14;  // [esp+20h] [ebp-20h]
	float v15;  // [esp+24h] [ebp-1Ch]
	float2 a3;  // [esp+28h] [ebp-18h]
	float4 a2;  // [esp+30h] [ebp-10h]

	if (a1 != *(float**)(arg4 + 4) && a1 != *(float**)(arg4 + 8) && (_DWORD)a1[4] & 0x10000) {
		if ((signed char)*((_BYTE*)a1 + 8) >= 0) {
			v5 = *((_DWORD*)a1 + 43);
			if (v5 == 2) {
				if (sub_57C8A0((float4*)(arg4 + 12), (float2*)a1 + 7, &a3)) {
					v6 = a3.field_4 - a1[15];
					if (v6 * v6 + (a3.field_0 - a1[14]) * (a3.field_0 - a1[14]) <= a1[45])
						*(_DWORD*)arg4 = 0;
				}
			} else if (v5 == 3) {
				v14 = a1[48] + a1[14];
				v7 = a1[49] + a1[15];
				a2.field_0 = v14;
				v15 = v7;
				v8 = a1[50] + a1[14];
				a2.field_4 = v15;
				v12 = v8;
				v9 = a1[51] + a1[15];
				a2.field_8 = v12;
				v13 = v9;
				v10 = a1[52] + a1[14];
				a2.field_C = v13;
				v11 = a1[53] + a1[15];
				a3.field_0 = a1[54] + a1[14];
				a3.field_4 = a1[55] + a1[15];
				if (sub_427980((float4*)(arg4 + 12), &a2))
					goto LABEL_20;
				a2.field_0 = v14;
				a2.field_4 = v15;
				a2.field_8 = v10;
				a2.field_C = v11;
				if (sub_427980((float4*)(arg4 + 12), &a2))
					goto LABEL_20;
				a2.field_0 = a3.field_0;
				a2.field_4 = a3.field_4;
				a2.field_8 = v10;
				a2.field_C = v11;
				if (sub_427980((float4*)(arg4 + 12), &a2) ||
				    (a2.field_0 = a3.field_0, a2.field_4 = a3.field_4, a2.field_8 = v12,
				     a2.field_C = v13, sub_427980((float4*)(arg4 + 12), &a2))) {
				LABEL_20:
					*(_DWORD*)arg4 = 0;
				}
			}
		} else {
			v2 = *((_DWORD*)a1 + 187);
			if (!((_BYTE)a1[3] & 4)) {
				v3 = 8 * *(_DWORD*)(v2 + 12);
				v4 = (double)*(int*)&byte_587000[v3 + 196184] * 0.125;
				a3.field_4 = (double)*(int*)&byte_587000[v3 + 196188] * 0.125;
				a2.field_0 = a1[14] - v4;
				a2.field_4 = a1[15] - a3.field_4;
				a2.field_8 =
				    (double)*(int*)&byte_587000[8 * *(_DWORD*)(v2 + 12) + 196184] + a2.field_0 + v4;
				a2.field_C = (double)*(int*)&byte_587000[8 * *(_DWORD*)(v2 + 12) + 196188] +
					     a2.field_4 + a3.field_4;
				if (sub_427980((float4*)(arg4 + 12), &a2))
					*(_DWORD*)arg4 = 0;
			}
		}
	}
}

//----- (005374B0) --------------------------------------------------------
int __cdecl sub_5374B0(float4* a1) { return sub_535250(a1, 0, 0, 9); }

//----- (005374D0) --------------------------------------------------------
void __cdecl sub_5374D0(_DWORD* a1) {
	int v1; // esi

	if (a1) {
		v1 = a1[187];
		if (v1) {
			if (*(_DWORD*)(v1 + 136)) {
				*(_DWORD*)(v1 + 132) = 0;
				sub_4FC300(a1, 3);
				sub_4E5CC0(*(_DWORD*)(v1 + 136));
				*(_DWORD*)(v1 + 136) = 0;
			}
		}
	}
}

//----- (00537520) --------------------------------------------------------
_DWORD* __cdecl sub_537520(_DWORD* a1) {
	sub_5374D0(a1);
	return sub_501960(998, (int)a1, 0, 0);
}

//----- (00537540) --------------------------------------------------------
void __cdecl sub_537540(int a1) {
	_DWORD* i; // esi

	if (a1) {
		for (i = (_DWORD*)sub_4DA7C0(); i; i = (_DWORD*)sub_4DA7F0((int)i)) {
			if (*(_DWORD*)(i[187] + 132) == a1)
				sub_537520(i);
		}
	}
}

//----- (00537580) --------------------------------------------------------
int __cdecl sub_537580(int a1) { return *(_BYTE*)(a1 + 464) & 1; }

//----- (00537590) --------------------------------------------------------
BOOL sub_537590() { return dword_5d4594_2488604 == 0; }

//----- (005375A0) --------------------------------------------------------
void __cdecl sub_5375A0(int a1) {
	int v1;  // eax
	int v2;  // ecx
	char v3; // al

	if (*(_BYTE*)(a1 + 464) & 1) {
		v1 = dword_5d4594_2488604;
		v2 = 0;
		if (dword_5d4594_2488604) {
			while (v1 != a1) {
				v2 = v1;
				v1 = *(_DWORD*)(v1 + 460);
				if (!v1)
					return;
			}
			if (v1) {
				if (v2)
					*(_DWORD*)(v2 + 460) = *(_DWORD*)(a1 + 460);
				else
					dword_5d4594_2488604 = *(_DWORD*)(a1 + 460);
				if (a1 == *(_DWORD*)&byte_5D4594[2488608])
					*(_DWORD*)&byte_5D4594[2488608] = v2;
				v3 = *(_BYTE*)(a1 + 464);
				*(_DWORD*)(a1 + 460) = -1;
				*(_BYTE*)(a1 + 464) = v3 & 0xFE;
			}
		}
	}
}

//----- (00537610) --------------------------------------------------------
char __cdecl sub_537610(int a1) {
	int v1;                       // eax
	int v2;                       // edx
	int v3;                       // edi
	void(__cdecl * v4)(int, int); // ecx
	int v5;                       // ecx

	v1 = *(_DWORD*)(a1 + 744);
	if (v1 || (v1 = *(_DWORD*)(a1 + 696)) != 0 && !(*(_BYTE*)(a1 + 16) & 0x40)) {
		if ((v2 = *(_DWORD*)(a1 + 8), !(v2 & 0x400000)) && !(*(_BYTE*)(a1 + 16) & 8) ||
		    (v3 = sub_4E3AA0((CHAR*)&byte_587000[276764]), v1 = sub_4E3AA0((CHAR*)&byte_587000[276772]),
		     v2 = *(_DWORD*)(a1 + 8), v2 & 0xE080) ||
		    (v4 = *(void(__cdecl**)(int, int))(a1 + 696), v4 == sub_4EADF0) || v4 == sub_4EBD40 ||
		    (v5 = *(unsigned __int16*)(a1 + 4), (unsigned __int16)v5 == v3) || v5 == v1) {
			if (*(_BYTE*)(a1 + 16) & 4) {
				if (v2 & 0x2008)
					sub_50B500();
				nullsub_30(a1);
				LOBYTE(v1) = *(_BYTE*)(a1 + 464);
				if (!(v1 & 1)) {
					if (*(_DWORD*)&byte_5D4594[2488608])
						*(_DWORD*)(*(_DWORD*)&byte_5D4594[2488608] + 460) = a1;
					else
						dword_5d4594_2488604 = a1;
					*(_DWORD*)&byte_5D4594[2488608] = a1;
					LOBYTE(v1) = *(_BYTE*)(a1 + 464) | 1;
					*(_DWORD*)(a1 + 460) = 0;
					*(_BYTE*)(a1 + 464) = v1;
				}
			}
		}
	}
	return v1;
}
// 5485F0: using guessed type void __cdecl nullsub_30(_DWORD);

//----- (00537700) --------------------------------------------------------
int sub_537700() {
	int result; // eax
	_DWORD* v1; // ecx

	result = dword_5d4594_2488604;
	v1 = (_DWORD*)(dword_5d4594_2488604 + 460);
	dword_5d4594_2488604 = *(_DWORD*)(dword_5d4594_2488604 + 460);
	if (!dword_5d4594_2488604)
		*(_DWORD*)&byte_5D4594[2488608] = 0;
	*v1 = -1;
	*(_BYTE*)(result + 464) &= 0xFEu;
	return result;
}

//----- (00537740) --------------------------------------------------------
int sub_537740() { return dword_5d4594_2488604; }

//----- (00537750) --------------------------------------------------------
int __cdecl sub_537750(int a1) {
	int result; // eax

	result = a1;
	if (a1)
		result = *(_DWORD*)(a1 + 460);
	return result;
}

//----- (00537760) --------------------------------------------------------
unsigned int sub_537760() { return *(_DWORD*)&byte_5D4594[2488620] != 0 ? (unsigned int)&byte_5D4594[2488612] : 0; }

//----- (00537770) --------------------------------------------------------
char __cdecl sub_537770(int a1) {
	int v1;    // eax
	int v3;    // [esp+0h] [ebp-Ch]
	float2 v4; // [esp+4h] [ebp-8h]

	LOBYTE(v1) = byte_5D4594[2488624];
	if (!*(_DWORD*)&byte_5D4594[2488624]) {
		*(_DWORD*)&byte_5D4594[2488624] = sub_4E3AA0((CHAR*)&byte_587000[276788]);
		*(_DWORD*)&byte_5D4594[2488628] = sub_4E3AA0((CHAR*)&byte_587000[276800]);
		v1 = sub_4E3AA0((CHAR*)&byte_587000[276812]);
		*(_DWORD*)&byte_5D4594[2488632] = v1;
	}
	if (!(*(_BYTE*)(a1 + 16) & 0x60)) {
		*(_DWORD*)&byte_5D4594[2488620] = 0;
		LOBYTE(v1) = sub_537850(a1, &v3, &v4);
		if ((_BYTE)v1) {
			if (!v3 || (v1 = *(unsigned __int16*)(v3 + 4),
				    (unsigned __int16)v1 != *(_DWORD*)&byte_5D4594[2488624]) &&
				       v1 != *(_DWORD*)&byte_5D4594[2488628] && v1 != *(_DWORD*)&byte_5D4594[2488632]) {
				(*(void(__cdecl**)(int, int, float2*))(a1 + 696))(a1, v3, &v4);
				LOBYTE(v1) = v3;
				*(_DWORD*)&byte_5D4594[2488620] = 0;
				if (v3) {
					v4.field_0 = -v4.field_0;
					v4.field_4 = -v4.field_4;
					LOBYTE(v1) = (*(int(__cdecl**)(int, int, float2*))(v3 + 696))(v3, a1, &v4);
				}
			}
		}
	}
	return v1;
}

//----- (00537850) --------------------------------------------------------
char __cdecl sub_537850(int a1, int* a2, float2* a3) {
	int v3;     // esi
	int v4;     // ebx
	double v5;  // st7
	double v6;  // st7
	int v7;     // edx
	float v8;   // eax
	int v9;     // eax
	float v10;  // eax
	float v11;  // ecx
	float v12;  // edx
	bool v13;   // al
	int v14;    // edx
	int v15;    // edi
	float v16;  // ecx
	double v17; // st7
	int v18;    // ebp
	double v19; // st7
	double v20; // st6
	double v21; // st7
	double v22; // st6
	double v23; // st5
	float v25;  // edx
	float v26;  // [esp+1Ch] [ebp-44h]
	float2 v27; // [esp+20h] [ebp-40h]
	float2 v28; // [esp+28h] [ebp-38h]
	int v29[2]; // [esp+30h] [ebp-30h]
	float2 a2a; // [esp+38h] [ebp-28h]
	float2 v31; // [esp+40h] [ebp-20h]
	int2 a3a;   // [esp+48h] [ebp-18h]
	float4 a1a; // [esp+50h] [ebp-10h]
	int v34;    // [esp+64h] [ebp+4h]
	int v35;    // [esp+64h] [ebp+4h]

	v3 = a1;
	v4 = 0;
	*(float*)&v34 = *(float*)(a1 + 64) - *(float*)(a1 + 56);
	v5 = *(float*)(v3 + 68) - *(float*)(v3 + 60);
	v26 = v5;
	v6 = v5 * v26 + *(float*)&v34 * *(float*)&v34;
	if (v6 <= 36.0) {
		v7 = *(_DWORD*)(v3 + 56);
		v8 = *(float*)(v3 + 64);
		v28.field_4 = *(float*)(v3 + 68);
		v29[0] = v7;
		v28.field_0 = v8;
		v29[1] = *(_DWORD*)(v3 + 60);
		v9 = sub_54E810(v3, &v28, (int)v29);
		if (!v9)
			goto LABEL_4;
		goto LABEL_3;
	}
	v15 = nox_double2int(sqrt(v6 * 0.027777778)) + 1;
	v16 = *(float*)(v3 + 60);
	v17 = (double)v15;
	v29[0] = *(_DWORD*)(v3 + 56);
	v18 = 0;
	*(float*)&v29[1] = v16;
	LODWORD(v28.field_0) = v29[0];
	v28.field_4 = v16;
	*(float*)&v35 = *(float*)&v34 / v17;
	v27.field_0 = v26 / v17;
	if (v15 > 0) {
		while (1) {
			v28.field_0 = v28.field_0 + *(float*)&v35;
			v28.field_4 = v28.field_4 + v27.field_0;
			v9 = sub_54E810(v3, &v28, (int)v29);
			if (v9)
				break;
			++v18;
			*(float2*)v29 = v28;
			if (v18 >= v15)
				goto LABEL_4;
		}
	LABEL_3:
		v4 = v9;
		v27.field_0 = *(float*)v29 - *(float*)(v9 + 56);
		v27.field_4 = *(float*)&v29[1] - *(float*)(v9 + 60);
	}
LABEL_4:
	v10 = *(float*)(v3 + 60);
	v11 = *(float*)(v3 + 64);
	a1a.field_0 = *(float*)(v3 + 56);
	v12 = *(float*)(v3 + 68);
	a1a.field_4 = v10;
	a1a.field_8 = v11;
	a1a.field_C = v12;
	if (sub_535250(&a1a, &a2a, &a3a, 5)) {
		v13 = 0;
	} else {
		*(int2*)&byte_5D4594[2488612] = a3a;
		*(float2*)&a1a.field_8 = a2a;
		*(_DWORD*)&byte_5D4594[2488620] = 1;
		v13 = sub_57CDB0(&a3a, &a1a.field_0, &v31) != 0;
		v14 = *(_DWORD*)(v3 + 60);
		*(_DWORD*)(v3 + 64) = *(_DWORD*)(v3 + 56);
		*(_DWORD*)(v3 + 68) = v14;
	}
	if (v4) {
		if (!v13) {
			*a3 = v27;
			*a2 = v4;
			return 1;
		}
		v19 = *(float*)(v3 + 56) - *(float*)(v4 + 56);
		v20 = *(float*)(v3 + 60) - *(float*)(v4 + 60);
		v21 = v20 * v20 + v19 * v19;
		v22 = *(float*)(v3 + 56) - a2a.field_0;
		v23 = *(float*)(v3 + 60) - a2a.field_4;
		if (v21 < v23 * v23 + v22 * v22) {
			*a3 = v27;
			*a2 = v4;
			return 1;
		}
		goto LABEL_17;
	}
	if (v13) {
	LABEL_17:
		v25 = v31.field_4;
		a3->field_0 = v31.field_0;
		a3->field_4 = v25;
		*a2 = 0;
		return 1;
	}
	return 0;
}
// 537A87: variable 'v24' is possibly undefined

//----- (00537AF0) --------------------------------------------------------
_DWORD* __cdecl sub_537AF0(int* a1, int a2) {
	_DWORD* result; // eax
	_DWORD* v3;     // esi
	int v4;         // eax
	int v5;         // [esp-18h] [ebp-18h]
	int v6;         // [esp-18h] [ebp-18h]
	int v7;         // [esp-18h] [ebp-18h]

	if (!*(_DWORD*)&byte_5D4594[2488636])
		sub_537BD0();
	if (a2) {
		if (a2 == 1) {
			v6 = *(_DWORD*)&byte_587000[8 * nox_common_randomInt_415FA0(0, 0) + 276836];
			result = sub_4E3450(v6);
		} else {
			result = (_DWORD*)(a2 - 2);
			if (a2 != 2)
				return result;
			v5 = *(_DWORD*)&byte_587000[8 * nox_common_randomInt_415FA0(0, 0) + 276844];
			result = sub_4E3450(v5);
		}
	} else {
		v7 = *(_DWORD*)&byte_587000[8 * nox_common_randomInt_415FA0(0, 0) + 276828];
		result = sub_4E3450(v7);
	}
	v3 = result;
	if (result) {
		sub_4DAA50((int)result, 0, *(float*)a1, *((float*)a1 + 1));
		if (nox_common_gameFlags_check_40A5C0(4096))
			v4 = nox_common_randomInt_415FA0(5, 8);
		else
			v4 = nox_common_randomInt_415FA0(10, 20);
		result = (_DWORD*)sub_511660(v3, *(_DWORD*)&byte_5D4594[2649704] * v4);
	}
	return result;
}

//----- (00537BD0) --------------------------------------------------------
int sub_537BD0() {
	int result; // eax

	*(_DWORD*)&byte_587000[276828] = sub_4E3AA0(*(CHAR**)&byte_587000[276824]);
	*(_DWORD*)&byte_587000[276836] = sub_4E3AA0(*(CHAR**)&byte_587000[276832]);
	result = sub_4E3AA0(*(CHAR**)&byte_587000[276840]);
	*(_DWORD*)&byte_587000[276844] = result;
	*(_DWORD*)&byte_5D4594[2488636] = 1;
	return result;
}

//----- (00537C10) --------------------------------------------------------
char __cdecl sub_537C10(int a1, int a2) {
	float2* v2;  // ebp
	char result; // al
	int v4;      // edi
	int v5;      // esi
	int v6;      // ecx
	char v7;     // al
	int* v8;     // ebx
	int v9;      // eax
	float v10;   // [esp+0h] [ebp-54h]
	int v11;     // [esp+18h] [ebp-3Ch]
	float4 a1a;  // [esp+1Ch] [ebp-38h]
	int v13[10]; // [esp+2Ch] [ebp-28h]
	int a3;      // [esp+58h] [ebp+4h]

	v2 = (float2*)a1;
	result = *(_BYTE*)(a1 + 16);
	v4 = *(_DWORD*)(a1 + 692);
	v11 = *(_DWORD*)(a1 + 692);
	if (!(result & 0x20)) {
		v5 = sub_4EC580(a1);
		sub_4E5CC0(a1);
		if (v5) {
			if (*(_BYTE*)(v5 + 8) & 4) {
				v6 = *(_DWORD*)(v5 + 748);
				if (*(_BYTE*)(*(_DWORD*)(v6 + 276) + 2251) == 1) {
					v7 = *(_BYTE*)(v6 + 244);
					if (v7)
						*(_BYTE*)(v6 + 244) = v7 - 1;
				}
			}
		}
		if (a2) {
			v8 = (int*)(v4 + 24);
			*(_DWORD*)(v4 + 24) = a2;
		} else {
			v13[0] = 15;
			v13[1] = 1;
			v13[2] = 0;
			v13[3] = 6;
			v13[4] = 0;
			v13[5] = -1;
			v13[6] = 0;
			v13[7] = -1;
			v13[8] = 0x8000;
			v8 = (int*)(v4 + 24);
			v10 = sub_419D40(&byte_587000[277100]);
			*(_DWORD*)(v4 + 24) = sub_4E6EA0(a1, v10, (int)v13);
		}
		a3 = 0;
		if (*(_BYTE*)(v4 + 20)) {
			do {
				if ((!sub_424A50(*(_DWORD*)v4, 1) || a2) && !sub_4FD0E0(v5, *(_DWORD*)v4)) {
					if (*(_BYTE*)(v5 + 8) & 4) {
						v9 = sub_4FE7B0(*(_DWORD*)v4, v5);
						sub_4FD400(*(_DWORD*)v4, v5, (_DWORD*)v5, (int)v2, v8, v9);
					} else {
						sub_4FD400(*(_DWORD*)v4, v5, (_DWORD*)v5, (int)v2, v8, 2);
					}
				}
				v4 += 4;
				++a3;
			} while (a3 < *(unsigned __int8*)(v11 + 20));
		}
		sub_522FF0(129, v2 + 7);
		sub_501A30(40, v2 + 7, 0, 0);
		a1a.field_0 = v2[7].field_0 - 100.0;
		a1a.field_4 = v2[7].field_4 - 100.0;
		a1a.field_8 = v2[7].field_0 + 100.0;
		a1a.field_C = v2[7].field_4 + 100.0;
		sub_517C10(&a1a, sub_537DD0, (int)v2);
	}
	return result;
}

//----- (00537DD0) --------------------------------------------------------
void __cdecl sub_537DD0(float* a1, int a2) {
	int v2;    // eax
	float v3;  // edx
	float v4;  // ecx
	float v5;  // edx
	float4 v6; // [esp+8h] [ebp-10h]

	if (a1 != (float*)a2 && !((_BYTE)a1[4] & 0x20)) {
		v2 = *(_DWORD*)&byte_5D4594[2488640];
		if (!*(_DWORD*)&byte_5D4594[2488640]) {
			v2 = sub_4E3AA0((CHAR*)&byte_587000[277112]);
			*(_DWORD*)&byte_5D4594[2488640] = v2;
		}
		if (*((unsigned __int16*)a1 + 2) == v2) {
			v3 = *(float*)(a2 + 56);
			v4 = a1[14];
			v6.field_4 = *(float*)(a2 + 60);
			v6.field_0 = v3;
			v5 = a1[15];
			v6.field_8 = v4;
			v6.field_C = v5;
			if (sub_535250(&v6, 0, 0, 5) == 1) {
				*((_DWORD*)a1 + 186) = sub_538280;
				sub_4DA8D0((int)a1);
			}
		}
	}
}

//----- (00537E60) --------------------------------------------------------
int __cdecl sub_537E60(int a1, int a2, int a3, int a4) {
	int v4;     // eax
	float4 a1a; // [esp+4h] [ebp-10h]

	a1a.field_0 = *(float*)(a4 + 56) - 300.0;
	a1a.field_4 = *(float*)(a4 + 60) - 300.0;
	a1a.field_8 = *(float*)(a4 + 56) + 300.0;
	a1a.field_C = *(float*)(a4 + 60) + 300.0;
	v4 = sub_424800(a1, 0);
	sub_501960(v4, a3, 0, 0);
	while (1) {
		*(_DWORD*)&byte_5D4594[2488644] = 0;
		sub_517C10(&a1a, sub_537F00, a4);
		if (!*(_DWORD*)&byte_5D4594[2488644])
			break;
		sub_537C10(*(int*)&byte_5D4594[2488644], 0);
	}
	return 1;
}

//----- (00537F00) --------------------------------------------------------
void __cdecl sub_537F00(float* a1, int a2) {
	int v2;    // eax
	int v3;    // ebx
	float v4;  // edx
	float v5;  // ecx
	float v6;  // edx
	float4 v7; // [esp+0h] [ebp-10h]

	v2 = *(_DWORD*)&byte_5D4594[2488640];
	if (!*(_DWORD*)&byte_5D4594[2488640]) {
		v2 = sub_4E3AA0((CHAR*)&byte_587000[277120]);
		*(_DWORD*)&byte_5D4594[2488640] = v2;
	}
	if (*((unsigned __int16*)a1 + 2) == v2 && !((_BYTE)a1[4] & 0x20)) {
		v3 = sub_4EC580(a2);
		if (sub_4EC4F0((int)a1, v3) || !*((_DWORD*)a1 + 127) && !(*(_BYTE*)(v3 + 8) & 4)) {
			v4 = *(float*)(a2 + 56);
			v5 = a1[14];
			v7.field_4 = *(float*)(a2 + 60);
			v7.field_0 = v4;
			v6 = a1[15];
			v7.field_8 = v5;
			v7.field_C = v6;
			if (sub_535250(&v7, 0, 0, 5) == 1)
				*(_DWORD*)&byte_5D4594[2488644] = a1;
		}
	}
}

//----- (00537FA0) --------------------------------------------------------
int __cdecl sub_537FA0(int a1, int a2, int a3, int a4, int a5) {
	int v5;      // edi
	int v6;      // esi
	_DWORD* v8;  // eax
	int v9;      // ebx
	int v10;     // ebp
	int v11;     // ecx
	BYTE v12;    // eax
	int v13;     // ebx
	_DWORD* v14; // eax
	int* v15;    // edi
	int v16;     // edx
	int v17;     // edx
	int v18;     // eax
	int v19;     // [esp-Ch] [ebp-2Ch]
	float v20;   // [esp+0h] [ebp-20h]
	int v21;     // [esp+14h] [ebp-Ch]
	float2 v22;  // [esp+18h] [ebp-8h]
	float v23;   // [esp+24h] [ebp+4h]
	int* v24;    // [esp+24h] [ebp+4h]

	v5 = a3;
	if (*(_BYTE*)(a3 + 8) & 4) {
		v6 = *(_DWORD*)(a3 + 748);
		v20 = sub_419D40(&byte_587000[277128]);
		if (*(unsigned __int8*)(v6 + 244) >= nox_float2int(v20)) {
			a3 = 5;
		LABEL_6:
			sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v6 + 276) + 2064), 0, &a3);
			return 0;
		}
		if (!*(_BYTE*)(v6 + 212)) {
			a3 = 7;
			goto LABEL_6;
		}
		v8 = sub_4E3810((CHAR*)&byte_587000[277144]);
		v9 = (int)v8;
		v21 = (int)v8;
		if (v8) {
			v10 = v8[173];
			if (*(_BYTE*)(*(_DWORD*)(v6 + 276) + 2251) != 2) {
				v13 = a4;
				sub_4DAA50((int)v8, v5, *(float*)(a4 + 56), *(float*)(a4 + 60));
				v19 = sub_424800(a1, 0);
				sub_501960(v19, v13, 0, 0);
			LABEL_23:
				a4 = 0;
				v22.field_0 = 0.0;
				if (*(_BYTE*)(v6 + 212)) {
					v24 = (int*)v10;
					v15 = (int*)(v6 + 192);
					do {
						if (sub_424B70(*v15)) {
							v16 = a4;
							*v24 = *v15;
							a4 = v16 + 1;
							++v24;
						}
						v17 = *(unsigned __int8*)(v6 + 212);
						++v15;
						++LODWORD(v22.field_0);
					} while (SLODWORD(v22.field_0) < v17);
				}
				*(_BYTE*)(v10 + 20) = a4;
				v18 = a5;
				*(_DWORD*)(v10 + 28) = *(_DWORD*)(a5 + 4);
				*(_DWORD*)(v10 + 32) = *(_DWORD*)(v18 + 8);
				*(_DWORD*)(v10 + 24) = 0;
				*(_BYTE*)(v6 + 212) = 0;
				*(_WORD*)(v21 + 126) = *(_WORD*)(v13 + 124);
				*(_WORD*)(v21 + 124) = *(_WORD*)(v13 + 124);
				if (*(_BYTE*)(*(_DWORD*)(v6 + 276) + 2251) == 1)
					++*(_BYTE*)(v6 + 244);
				return 1;
			}
			v23 = (double)sub_538250(v5);
			if (sub_419D40(&byte_587000[277152]) <= v23) {
				v11 = *(_DWORD*)(v6 + 276);
				a4 = 5;
				sub_4DA0F0(*(unsigned __int8*)(v11 + 2064), 0, &a4);
				sub_4E5CC0(v9);
				return 0;
			}
			v12 = sub_500D70(v5, 5);
			if (v12) {
				if (!*(_DWORD*)&byte_5D4594[2488648])
					*(_DWORD*)&byte_5D4594[2488648] = sub_4E3AA0((CHAR*)&byte_587000[277168]);
				v13 = a4;
				sub_4ED970(50.0, (float2*)(a4 + 56), &v22);
				if (v5)
					v14 = sub_5016C0(*(int*)&byte_5D4594[2488648], (int*)&v22, v5,
							 *(_BYTE*)(v5 + 124));
				else
					v14 = sub_5016C0(*(int*)&byte_5D4594[2488648], (int*)&v22, 0, 0);
				if (v14)
					sub_4F3070((int)v14, v21, 1);
				sub_501960(367, v13, 0, 0);
				goto LABEL_23;
			}
			sub_4E5CC0(v9);
		}
		return 0;
	}
	return 1;
}
// 5380C1: variable 'v12' is possibly undefined

//----- (00538250) --------------------------------------------------------
int __cdecl sub_538250(int a1) {
	int result; // eax
	int i;      // ecx

	result = 0;
	for (i = *(_DWORD*)(a1 + 516); i; i = *(_DWORD*)(i + 512)) {
		if (*(_BYTE*)(i + 8) & 2) {
			if (*(_DWORD*)(i + 12) & 0x2000)
				++result;
		}
	}
	return result;
}

//----- (00538280) --------------------------------------------------------
char __cdecl sub_538280(int a1) { return sub_537C10(a1, 0); }

//----- (00538290) --------------------------------------------------------
int __cdecl sub_538290(int a1, int a2, int a3, int a4) {
	int result;                                  // eax
	int v5;                                      // esi
	int v6;                                      // ebp
	int* v7;                                     // esi
	int v8;                                      // eax
	void(__cdecl * v9)(int, int, int, int, int); // ecx
	int v10;                                     // [esp+10h] [ebp+4h]

	result = a3;
	if (a3) {
		v5 = *(_DWORD*)(a3 + 692);
		v6 = a1;
		if (sub_417DA0(1) || !a2 || !(*(_BYTE*)(a2 + 8) & 6) || (result = sub_5330C0(a2, a1)) != 0) {
			result = sub_4FF350(a1, 23);
			if (!result) {
				result = sub_4FF350(a1, 27);
				if (!result) {
					v7 = (int*)(v5 + 8);
					v10 = 2;
					do {
						v8 = *v7;
						if (*v7) {
							v9 = *(void(__cdecl**)(int, int, int, int, int))(v8 + 52);
							if (v9)
								v9(v8, a3, a2, v6, a4);
						}
						++v7;
						result = --v10;
					} while (v10);
				}
			}
		}
	}
	return result;
}

//----- (00538330) --------------------------------------------------------
int __cdecl sub_538330(int a1, int a2) {
	int v2;    // ebp
	int v3;    // eax
	int v4;    // ecx
	int v5;    // eax
	int v6;    // eax
	int v8;    // eax
	int v9;    // eax
	int v12;   // eax
	float a3;  // [esp+0h] [ebp-34h]
	float v15; // [esp+Ch] [ebp-28h]
	float v16; // [esp+Ch] [ebp-28h]
	float v17; // [esp+Ch] [ebp-28h]
	float v18; // [esp+Ch] [ebp-28h]
	float v19; // [esp+Ch] [ebp-28h]
	int v20;   // [esp+10h] [ebp-24h]
	int v21;   // [esp+20h] [ebp-14h]
	int4 a1a;  // [esp+24h] [ebp-10h]
	float v23; // [esp+38h] [ebp+4h]

	v2 = a1;
	v21 = 0;
	if (!a1 || !a2)
		return 0;
	*(_DWORD*)&byte_5D4594[2488656] = 0;
	dword_5d4594_2488660 = 0;
	v3 = *(_DWORD*)(a2 + 28);
	if (v3 && (v4 = *(_DWORD*)(v3 + 12), BYTE1(v4) & 0x40)) {
		sub_518040(a2 + 16, *(float*)(a2 + 8), sub_538510, a2);
		v21 = 25;
	} else {
		dword_5d4594_2488660 = 0;
		*(_DWORD*)&byte_5D4594[2488652] = *(_DWORD*)(a2 + 8);
		sub_518040(a1 + 56, *(float*)(a2 + 8), sub_5386A0, a1);
		if (dword_5d4594_2488660)
			sub_538510(*(int*)&dword_5d4594_2488660, a2);
	}
	v23 = (double)v21;
	v15 = *(float*)(a2 + 16) - *(float*)(a2 + 8) - v23;
	v5 = nox_float2int(v15);
	v16 = *(float*)(a2 + 20) - *(float*)(a2 + 8) - v23;
	a1a.field_0 = v5 / 23;
	v6 = nox_float2int(v16);
	v17 = *(float*)(a2 + 8) + *(float*)(a2 + 16) + v23;
	a1a.field_4 = v6 / 23;
	v8 = nox_float2int(v17);
	v18 = *(float*)(a2 + 20) + *(float*)(a2 + 8) + v23;
	a1a.field_8 = v8 / 23;
	v9 = nox_float2int(v18);
	v12 = *(_DWORD*)(a2 + 28);
	a1a.field_C = v9 / 23;
	if (!v12)
		v12 = v2;
	a3 = v23 + *(float*)(a2 + 8);
	sub_534FC0(&a1a, a2 + 16, a3, (__int64)(*(float*)a2 + 0.5), *(unsigned __int8*)(a2 + 4), v12);
	if (*(_DWORD*)(a2 + 28)) {
		if (*(_DWORD*)&byte_5D4594[2488656]) {
			v20 = *(unsigned __int8*)(a2 + 4);
			v19 = sub_419D40(&byte_587000[277176]) * *(float*)a2;
			sub_4E1560(*(_DWORD*)(a2 + 28), *(_DWORD*)(a2 + 12), *(int*)&dword_5d4594_2488660,
				   *(int*)&dword_5d4594_2488660, v19, v20);
		}
	}
	return *(_DWORD*)&byte_5D4594[2488656];
}

//----- (00538510) --------------------------------------------------------
void __cdecl sub_538510(int a1, int a2) {
	int v2;     // eax
	int v3;     // eax
	int v4;     // eax
	float v5;   // ecx
	float v6;   // edx
	float v7;   // eax
	int v8;     // eax
	int v9;     // eax
	int v10;    // esi
	char v11;   // al
	float4 v12; // [esp+Ch] [ebp-10h]

	if (a1) {
		if (a2) {
			v2 = *(_DWORD*)(a2 + 12);
			if (v2) {
				if (a1 != v2) {
					if ((unsigned __int8)nox_server_testTwoPointsAndDirection_4E6E50(
						(float2*)(v2 + 56), *(__int16*)(v2 + 124), (float2*)(a1 + 56)) &
					    *(_BYTE*)(a2 + 32)) {
						v3 = *(_DWORD*)(a1 + 16);
						if (!(v3 & 0x8040) && (*(_DWORD*)(a2 + 24) || !(v3 & 8))) {
							if (*(_WORD*)(a1 + 24) != 0x4000)
								*(_DWORD*)&byte_5D4594[2488656] = 1;
							v4 = *(_DWORD*)(a2 + 12);
							v12.field_0 = *(float*)(v4 + 56);
							v5 = *(float*)(a1 + 60);
							v6 = *(float*)(v4 + 60);
							v7 = *(float*)(a1 + 56);
							v12.field_4 = v6;
							v12.field_8 = v7;
							v12.field_C = v5;
							if (sub_535250(&v12, 0, 0, 5)) {
								sub_538290(a1, *(_DWORD*)(a2 + 12), *(_DWORD*)(a2 + 28),
									   a2);
								(*(void(__cdecl**)(int, _DWORD, _DWORD, _DWORD,
										   _DWORD))(a1 + 716))(
								    a1, *(_DWORD*)(a2 + 12), *(_DWORD*)(a2 + 28),
								    (__int64)(*(float*)a2 + 0.5),
								    *(unsigned __int8*)(a2 + 4));
								if (nox_common_gameFlags_check_40A5C0(2048)) {
									if (*(_BYTE*)(*(_DWORD*)(a2 + 12) + 8) & 4) {
										if (!(*(_BYTE*)(a1 + 8) & 2)) {
											v8 = *(_DWORD*)(a1 + 556);
											if (v8) {
												if (*(_WORD*)(v8 + 4)) {
													v9 = *(
													    _DWORD*)(a1 +
														     16);
													if ((v9 &
													     0x8000) ==
														0 &&
													    !(v9 &
													      0x20))
														sub_522FF0(
														    139,
														    (float2*)(a1 +
															      56));
												}
											}
										}
									}
								}
								if (!*(_DWORD*)(a2 + 28)) {
									v10 = *(_DWORD*)(a2 + 12);
									if (*(_BYTE*)(v10 + 8) & 4)
										v11 = *(
										    _BYTE*)(*(_DWORD*)(*(_DWORD*)(v10 +
														  748) +
												       276) +
											    8);
									else
										v11 = *(_BYTE*)(*(_DWORD*)(v10 + 748) +
												2068);
									if (v11 == 25)
										sub_52DF80(v10 + 56, a1, 20.0);
								}
							}
						}
					}
				}
			}
		}
	}
}

//----- (005386A0) --------------------------------------------------------
void __cdecl sub_5386A0(int a3, int a2) {
	int v2;    // eax
	int v3;    // eax
	double v4; // st7
	double v5; // st7
	float* v6; // eax
	double v7; // st7
	float2 a4; // [esp+8h] [ebp-8h]

	if (a2 != a3) {
		if (a2) {
			if (a3) {
				v2 = *(_DWORD*)(a3 + 16);
				if (!(v2 & 0x8049) && (*(_BYTE*)(a3 + 8) & 6 || !(v2 & 0x10) || (v2 & 0x80u) != 0) &&
				    (sub_5330C0(a2, a3) || !(*(_BYTE*)(a3 + 8) & 6))) {
					v3 = *(_DWORD*)(a3 + 16);
					if ((v3 & 0x8000) == 0) {
						if (sub_5370E0(a2, a3, 1)) {
							if (*(float*)&byte_5D4594[2488652] > 0.0) {
								a4.field_0 = *(float*)(a3 + 56) - *(float*)(a2 + 56);
								v4 = *(float*)(a3 + 60) - *(float*)(a2 + 60);
								a4.field_4 = v4;
								v5 = sqrt(v4 * a4.field_4 + a4.field_0 * a4.field_0);
								if (v5 != 0.0) {
									v6 = (float*)&byte_587000[8 * *(__int16*)(a2 +
														  124) +
												  194136];
									if (a4.field_4 / v5 * v6[1] +
										a4.field_0 / v5 * *v6 >
									    0.5) {
										if (*(_DWORD*)(a3 + 172) == 2) {
											v5 = v5 - *(float*)(a3 + 176);
										} else if (*(_DWORD*)(a3 + 172) == 3) {
											v7 = sub_54A990(
											    (float2*)(a2 + 56),
											    *(float*)&byte_5D4594
												[2488652],
											    a3, &a4);
											if (v7 < 0.0)
												return;
											v5 = *(float*)&byte_5D4594
												 [2488652] -
											     v7;
										}
										if (v5 < 0.0)
											v5 = 0.0;
										if ((v5 < *(float*)&byte_5D4594
											      [2488652] ||
										     dword_5d4594_2488660 &&
											 !(*(_BYTE*)(dword_5d4594_2488660 +
												     8) &
											   2) &&
											 (*(_BYTE*)(a3 + 8) & 2) ==
											     2) &&
										    (!dword_5d4594_2488660 ||
										     !(*(_BYTE*)(dword_5d4594_2488660 +
												 8) &
										       2))) {
											*(float*)&byte_5D4594[2488652] =
											    v5;
											dword_5d4594_2488660 = a3;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

//----- (00538840) --------------------------------------------------------
int __cdecl sub_538840(int a1, int a2, int a3) {
	int v3;                                         // edi
	int* v4;                                        // esi
	int v5;                                         // eax
	void(__cdecl * v6)(int, int, int, _DWORD, int); // ecx
	int result;                                     // eax
	int v8;                                         // [esp+14h] [ebp+4h]

	v3 = a1;
	v8 = 4;
	v4 = *(int**)(v3 + 692);
	do {
		v5 = *v4;
		if (*v4) {
			v6 = *(void(__cdecl**)(int, int, int, _DWORD, int))(v5 + 40);
			if (v6)
				v6(v5, v3, a2, 0, a3);
		}
		++v4;
		result = --v8;
	} while (v8);
	return result;
}

//----- (00538890) --------------------------------------------------------
int __cdecl sub_538890(int a1) {
	_DWORD* v1; // eax
	int v2;     // edi
	int v3;     // ebx
	double v4;  // st7
	int v5;     // eax
	int result; // eax
	__int16 v7; // si
	float v8;   // [esp+0h] [ebp-18h]
	float v9;   // [esp+4h] [ebp-14h]

	if (!a1)
		return 0;
	v1 = sub_4E3810((CHAR*)&byte_587000[277200]);
	v2 = (int)v1;
	if (!v1)
		return 0;
	v3 = *(_DWORD*)(a1 + 748);
	v4 = *(float*)(a1 + 176) + 1.0;
	*(_DWORD*)(v1[175] + 4) = a1;
	v5 = 8 * *(__int16*)(a1 + 124);
	v9 = v4 * *(float*)&byte_587000[v5 + 194140] + *(float*)(a1 + 60);
	v8 = v4 * *(float*)&byte_587000[v5 + 194136] + *(float*)(a1 + 56);
	sub_4DAA50(v2, a1, v8, v9);
	result = 1;
	*(float*)(v2 + 80) = *(float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194136] * *(float*)(v2 + 544);
	*(float*)(v2 + 84) = *(float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194140] * *(float*)(v2 + 544);
	v7 = *(_WORD*)(a1 + 124);
	*(_WORD*)(v2 + 124) = v7;
	*(_WORD*)(v2 + 126) = v7;
	*(_DWORD*)(v3 + 136) = v2;
	*(_DWORD*)(v3 + 140) = 0;
	return result;
}

//----- (00538960) --------------------------------------------------------
BOOL __cdecl sub_538960(int a1) {
	float* v1;           // edi
	int v2;              // eax
	int v3;              // eax
	int v4;              // ebp
	int v5;              // ebx
	char v6;             // dl
	float v7;            // edx
	float v8;            // eax
	char v9;             // al
	double v10;          // st7
	int v11;             // eax
	int v12;             // edx
	double v13;          // st7
	__int16 v14;         // ax
	int v15;             // ecx
	int v16;             // edx
	double v17;          // st7
	int v18;             // eax
	int v19;             // eax
	char v20;            // cl
	int v21;             // ecx
	double v22;          // st7
	double v23;          // st7
	int v24;             // edi
	int v25;             // ebx
	int v26;             // edx
	double v27;          // st7
	double v28;          // st7
	double v29;          // st7
	int v30;             // eax
	float v31;           // edx
	double v32;          // st6
	_DWORD* v33;         // eax
	int v34;             // edi
	int v35;             // ebx
	__int16 v36;         // ax
	double v37;          // st7
	int v38;             // eax
	float v39;           // edx
	char* v40;           // ebx
	double v41;          // st6
	_DWORD* v42;         // eax
	int v43;             // edi
	__int16 v44;         // ax
	char v45;            // al
	int v46;             // edx
	double v47;          // st7
	double v48;          // st7
	int v49;             // edx
	double v50;          // st7
	double v51;          // st7
	int v52;             // edx
	double v53;          // st7
	double v54;          // st7
	int v55;             // eax
	int v56;             // eax
	int v57;             // edx
	double v58;          // st7
	double v59;          // st7
	int v60;             // edx
	double v61;          // st7
	double v62;          // st7
	_DWORD* v63;         // edi
	int v64;             // eax
	char v65;            // bl
	unsigned __int8 v66; // bl
	_DWORD* v67;         // edi
	int v68;             // eax
	bool v69;            // cc
	int v70;             // eax
	int v71;             // ecx
	unsigned __int8 v72; // al
	int v73;             // ecx
	float v75;           // [esp+0h] [ebp-C0h]
	__int16 v76;         // [esp+17h] [ebp-A9h]
	int v77;             // [esp+1Ch] [ebp-A4h]
	int v78;             // [esp+20h] [ebp-A0h]
	int v79;             // [esp+24h] [ebp-9Ch]
	int v80;             // [esp+28h] [ebp-98h]
	int v81;             // [esp+2Ch] [ebp-94h]
	char v82[36];        // [esp+30h] [ebp-90h]
	float4 v83;
	int v86;      // [esp+64h] [ebp-5Ch]
	char v87[88]; // [esp+68h] [ebp-58h]

	v1 = 0;
	v2 = *(_DWORD*)(a1 + 8);
	if (v2 & 4) {
		v79 = *(_DWORD*)(a1 + 748);
		v3 = *(_DWORD*)(v79 + 276);
		v4 = *(_DWORD*)(v79 + 104);
		v5 = *(_DWORD*)(v3 + 4);
		v6 = *(_BYTE*)(v3 + 8);
		LOBYTE(v76) = *(_BYTE*)(v79 + 236);
	} else {
		if (!(v2 & 2) || !(*(_BYTE*)(a1 + 12) & 0x10))
			return 0;
		v79 = *(_DWORD*)(a1 + 748);
		v5 = *(_DWORD*)(v79 + 2056);
		v4 = *(_DWORD*)(v79 + 2064);
		v6 = *(_BYTE*)(v79 + 2068);
		LOBYTE(v76) = *(_BYTE*)(v79 + 481);
	}
	LOBYTE(v80) = v6;
	if (v4) {
		v1 = (float*)sub_413250(*(unsigned __int16*)(v4 + 4));
		if (!v1)
			return 0;
		*(_DWORD*)(v4 + 56) = *(_DWORD*)(a1 + 56);
		*(_DWORD*)(v4 + 60) = *(_DWORD*)(a1 + 60);
		*(_DWORD*)(v4 + 72) = *(_DWORD*)(a1 + 56);
		*(_DWORD*)(v4 + 76) = *(_DWORD*)(a1 + 60);
	} else if (!v6) {
		LOBYTE(v80) = nox_common_randomInt_415FA0(23, 24);
		if (!(*(_BYTE*)(a1 + 8) & 4))
			goto LABEL_171;
		if (!*(_BYTE*)(*(_DWORD*)(v79 + 276) + 2251) && nox_common_randomInt_415FA0(0, 100) >= 75)
			LOBYTE(v80) = 25;
		if (*(_BYTE*)(a1 + 8) & 4)
			*(_BYTE*)(*(_DWORD*)(v79 + 276) + 8) = v80;
		else
		LABEL_171:
			*(_BYTE*)(v79 + 2068) = v80;
	}
	*(_DWORD*)&v82[28] = v4;
	v81 = sub_4F9FD0(a1);
	if (nox_common_playerIsAbilityActive_4FC250(a1, 2) && sub_4FC3E0(a1, 2)) {
		sub_4F9F90(46, &v77, &v78);
		HIBYTE(v76) = (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
		if (v76 == 770) {
			v7 = *(float*)(a1 + 56);
			v8 = *(float*)(a1 + 60);
			LODWORD(v83.field_0) = a1;
			v83.field_4 = v7;
			v83.field_8 = v8;
			sub_4D9110((float*)(a1 + 56), 15);
			sub_517F90((float2*)(a1 + 56), 300.0, sub_539B90, a1);
			sub_52BBB0(13, a1, a1, a1);
		}
		if (HIBYTE(v76) >= v77)
			sub_4FC440(a1, 2);
		goto LABEL_159;
	}
	if (nox_common_playerIsAbilityActive_4FC250(a1, 1)) {
		if (!sub_4FF350(a1, 25) && !sub_4FF350(a1, 5)) {
			sub_4F9F90(45, &v77, &v78);
			v9 = (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
			v10 = *(float*)(a1 + 548) * 6.0;
			*(float*)(a1 + 544) = v10;
			HIBYTE(v76) = v9;
			v11 = 8 * *(__int16*)(a1 + 124);
			v12 = v77 - 1;
			*(float*)(a1 + 88) = v10 * *(float*)&byte_587000[v11 + 194136] + *(float*)(a1 + 88);
			*(float*)(a1 + 92) = v10 * *(float*)&byte_587000[v11 + 194140] + *(float*)(a1 + 92);
			if (HIBYTE(v76) >= v12)
				HIBYTE(v76) = 0;
			goto LABEL_159;
		}
		return 0;
	}
	if (!v4) {
		sub_4F9F90((unsigned __int8)v80, &v77, &v78);
		if (*(_BYTE*)(a1 + 8) & 4 && !*(_DWORD*)v79)
			*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1);
		HIBYTE(v76) = (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
		if (HIBYTE(v76) < v77)
			goto LABEL_159;
		if ((unsigned __int8)v80 >= 0x17u) {
			if ((unsigned __int8)v80 <= 0x18u) {
				v13 = 0.039999999;
				v14 = 5;
				goto LABEL_39;
			}
			if ((_BYTE)v80 == 25) {
				v13 = 0.039999999;
				v14 = 10;
			LABEL_39:
				v15 = *(_DWORD*)(a1 + 56);
				v16 = *(_DWORD*)(a1 + 60);
				*(float*)&v87[64] = v13;
				*(_WORD*)&v87[72] = v14;
				*(_DWORD*)&v82[16] = v15;
				*(_DWORD*)&v82[20] = v16;
				*(_WORD*)&v87[60] = 0;
				*(float*)v82 = sub_4EF1E0(v81, (int)v87);
				v17 = *(float*)(a1 + 176) + 20.0;
				v82[4] = 10;
				*(_DWORD*)&v82[12] = a1;
				*(_DWORD*)&v82[24] = 0;
				*(float*)&v82[8] = v17;
				v82[32] = 1;
				*(_DWORD*)&v82[28] = 0;
				v18 = sub_538330(a1, (int)v82);
			LABEL_56:
				if (!v18)
					sub_501960(879, a1, 0, 0);
				goto LABEL_159;
			}
		}
		v13 = 0.0;
		v14 = 0;
		goto LABEL_39;
	}
	if (v5 & 0x47F8000) {
		v19 = *(_DWORD*)(v4 + 736);
		v86 = *(_DWORD*)(v4 + 736);
		if ((v5 & 0x8000) != 0 || (v20 = *(_BYTE*)(v19 + 96), v80 = 31, v20 & 2))
			v80 = 29;
		sub_4F9F90(v80, &v77, &v78);
		if (*(_BYTE*)(a1 + 8) & 4 && !*(_DWORD*)v79) {
			if (v80 == 29)
				*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1);
			else
				*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000];
		}
		HIBYTE(v76) = (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
		if (HIBYTE(v76) >= v77) {
			if (v5 & 0x47F0000)
				*(_DWORD*)(v86 + 96) &= 0xFFFFFFFD;
			goto LABEL_159;
		}
		if (v80 != 29 || HIBYTE(v76) != v77 / 2 || HIBYTE(v76) <= (unsigned __int8)v76) {
			if (*(_BYTE*)(a1 + 8) & 2) {
				if (v80 != 29 && v76 == 256) {
					v24 = *(_DWORD*)(v4 + 736);
					sub_53F8E0(a1, v4);
					if (!*(_BYTE*)(v24 + 108)) {
						if (*(_BYTE*)(v24 + 109))
							sub_53A030(a1, v4);
					}
				}
			}
			goto LABEL_159;
		}
		v21 = *(_DWORD*)(a1 + 60);
		*(_DWORD*)&v82[16] = *(_DWORD*)(a1 + 56);
		*(_DWORD*)&v82[20] = v21;
		*(float*)v82 = sub_4EF1E0(v81, (int)v1);
		v22 = *(float*)(a1 + 176);
		v82[4] = 0;
		*(_DWORD*)&v82[12] = a1;
		v23 = v22 + v1[17];
		*(_DWORD*)&v82[24] = 0;
		v82[32] = 1;
		*(float*)&v82[8] = v23;
		sub_538840(v4, a1, (int)v82);
		v18 = sub_538330(a1, (int)v82);
		goto LABEL_56;
	}
	if (v5 & 0x7800000) {
		v25 = ((v5 & 0x3800000) != 0) + 31;
		sub_4F9F90(v25, &v77, &v78);
		if (*(_BYTE*)(a1 + 8) & 4 && !*(_DWORD*)v79)
			*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1);
		HIBYTE(v76) = (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
		if (v25 != 32 || HIBYTE(v76) != v77 / 2 || HIBYTE(v76) <= (unsigned __int8)v76)
			goto LABEL_159;
		v26 = *(_DWORD*)(a1 + 60);
		*(_DWORD*)&v82[16] = *(_DWORD*)(a1 + 56);
		*(_DWORD*)&v82[20] = v26;
		*(float*)v82 = sub_4EF1E0(v81, (int)v1);
		v27 = *(float*)(a1 + 176);
		v82[4] = 0;
		*(_DWORD*)&v82[12] = a1;
		v28 = v27 + v1[17];
		*(_DWORD*)&v82[24] = 0;
		v82[32] = 1;
		*(float*)&v82[8] = v28;
		sub_538840(v4, a1, (int)v82);
		v18 = sub_538330(a1, (int)v82);
		goto LABEL_56;
	}
	if (!(v5 & 0x40)) {
		if ((v5 & 0x80u) == 0) {
			if (v5 & 0x200) {
				sub_4F9F90(28, &v77, &v78);
				if (*(_BYTE*)(a1 + 8) & 4 && !*(_DWORD*)v79)
					*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1);
				HIBYTE(v76) =
				    (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned __int8)v76) {
					v46 = *(_DWORD*)(a1 + 60);
					*(_DWORD*)&v82[16] = *(_DWORD*)(a1 + 56);
					*(_DWORD*)&v82[20] = v46;
					*(float*)v82 = sub_4EF1E0(v81, (int)v1);
					v47 = *(float*)(a1 + 176);
					v82[4] = 0;
					*(_DWORD*)&v82[12] = a1;
					v48 = v47 + v1[17];
					*(_DWORD*)&v82[24] = 0;
					v82[32] = 1;
					*(float*)&v82[8] = v48;
					sub_538840(v4, a1, (int)v82);
					if (!sub_538330(a1, (int)v82))
						sub_501960(880, a1, 0, 0);
				}
			} else if (v5 & 0x100) {
				sub_4F9F90(27, &v77, &v78);
				if (*(_BYTE*)(a1 + 8) & 4 && !*(_DWORD*)v79)
					*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1);
				HIBYTE(v76) =
				    (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned __int8)v76) {
					v49 = *(_DWORD*)(a1 + 60);
					*(_DWORD*)&v82[16] = *(_DWORD*)(a1 + 56);
					*(_DWORD*)&v82[20] = v49;
					*(float*)v82 = sub_4EF1E0(v81, (int)v1);
					v50 = *(float*)(a1 + 176);
					v82[4] = 0;
					*(_DWORD*)&v82[12] = a1;
					v51 = v50 + v1[17];
					*(_DWORD*)&v82[24] = 0;
					v82[32] = 1;
					*(float*)&v82[8] = v51;
					sub_538840(v4, a1, (int)v82);
					if (!sub_538330(a1, (int)v82))
						sub_501960(881, a1, 0, 0);
				}
			} else if (v5 & 0x400) {
				sub_4F9F90(37, &v77, &v78);
				if (*(_BYTE*)(a1 + 8) & 4 && !*(_DWORD*)v79)
					*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1);
				HIBYTE(v76) =
				    (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned __int8)v76) {
					v52 = *(_DWORD*)(a1 + 60);
					*(_DWORD*)&v82[16] = *(_DWORD*)(a1 + 56);
					*(_DWORD*)&v82[20] = v52;
					*(float*)v82 = sub_4EF1E0(v81, (int)v1);
					v53 = *(float*)(a1 + 176);
					v82[4] = 0;
					*(_DWORD*)&v82[12] = a1;
					v54 = v53 + v1[17];
					*(_DWORD*)&v82[24] = 0;
					v82[32] = 1;
					*(float*)&v82[8] = v54;
					sub_538840(v4, a1, (int)v82);
					if (!sub_538330(a1, (int)v82))
						sub_501960(881, a1, 0, 0);
				}
			} else if (v5 & 0x4000) {
				sub_4F9F90(39, &v77, &v78);
				if (*(_BYTE*)(a1 + 8) & 4 && !*(_DWORD*)v79)
					*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1);
				HIBYTE(v76) =
				    (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned __int8)v76) {
					v55 = 8 * *(__int16*)(a1 + 124);
					*(float*)&v82[16] =
					    *(float*)&byte_587000[v55 + 194136] * 35.0 + *(float*)(a1 + 56);
					*(float*)&v82[20] =
					    *(float*)&byte_587000[v55 + 194140] * 35.0 + *(float*)(a1 + 60);
					*(float*)v82 = sub_4EF1E0(v81, (int)v1);
					v82[4] = 2;
					*(_DWORD*)&v82[12] = a1;
					*(float*)&v82[8] = v1[17];
					*(_DWORD*)&v82[24] = 1;
					v82[32] = 1;
					sub_538840(v4, a1, (int)v82);
					sub_538330(a1, (int)v82);
					v75 = (double)v81 * 0.1;
					v56 = nox_float2int(v75);
					sub_4D9110((float*)(a1 + 56), v56);
					sub_501960(882, a1, 0, 0);
				}
			} else if (v5 & 0x800) {
				sub_4F9F90(26, &v77, &v78);
				if (*(_BYTE*)(a1 + 8) & 4 && !*(_DWORD*)v79)
					*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1);
				HIBYTE(v76) =
				    (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned __int8)v76) {
					v57 = *(_DWORD*)(a1 + 60);
					*(_DWORD*)&v82[16] = *(_DWORD*)(a1 + 56);
					*(_DWORD*)&v82[20] = v57;
					*(float*)v82 = sub_4EF1E0(v81, (int)v1);
					v58 = *(float*)(a1 + 176);
					v82[4] = 2;
					*(_DWORD*)&v82[12] = a1;
					v59 = v58 + v1[17];
					*(_DWORD*)&v82[24] = 1;
					v82[32] = 1;
					*(float*)&v82[8] = v59;
					sub_538840(v4, a1, (int)v82);
					if (!sub_538330(a1, (int)v82))
						sub_501960(884, a1, 0, 0);
				}
			} else if (v5 & 0x3000) {
				sub_4F9F90(35, &v77, &v78);
				if (*(_BYTE*)(a1 + 8) & 4 && !*(_DWORD*)v79)
					*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1);
				HIBYTE(v76) =
				    (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
				if (HIBYTE(v76) == v77 / 2 && HIBYTE(v76) > (unsigned __int8)v76) {
					v60 = *(_DWORD*)(a1 + 60);
					*(_DWORD*)&v82[16] = *(_DWORD*)(a1 + 56);
					*(_DWORD*)&v82[20] = v60;
					*(float*)v82 = sub_4EF1E0(v81, (int)v1);
					v61 = *(float*)(a1 + 176);
					v82[4] = 0;
					*(_DWORD*)&v82[12] = a1;
					v62 = v61 + v1[17];
					*(_DWORD*)&v82[24] = 1;
					v82[32] = 1;
					*(float*)&v82[8] = v62;
					sub_538840(v4, a1, (int)v82);
					if (!sub_538330(a1, (int)v82))
						sub_501960(883, a1, 0, 0);
				}
			} else if (v5 & 4) {
				sub_4F9F90(33, &v77, &v78);
				if (*(_BYTE*)(a1 + 8) & 4) {
					v63 = (_DWORD*)v79;
					if (!*(_DWORD*)v79) {
						v64 = sub_4E0960(v4);
						*v63 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1) - v64;
					}
				}
				v65 =
				    (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
				v66 = sub_4E0960(v4) + v65;
				HIBYTE(v76) = v66;
				if (v66 >= v77 - 1 && v66 > (unsigned __int8)v76) {
					sub_539BD0(a1, v4);
					HIBYTE(v76) = v77;
				}
			} else if (v5 & 8) {
				sub_4F9F90(34, &v77, &v78);
				if (*(_BYTE*)(a1 + 8) & 4) {
					v67 = (_DWORD*)v79;
					if (!*(_DWORD*)v79) {
						v68 = sub_4E0960(v4);
						*v67 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1) - v68;
					}
				}
				HIBYTE(v76) =
				    (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
				v69 = (int)HIBYTE(v76) < 1;
				if (HIBYTE(v76) == 1) {
					if (!(_BYTE)v76)
						sub_539BD0(a1, v4);
					v69 = 0;
				}
				if (!v69)
					HIBYTE(v76) += sub_4E0960(v4);
			}
			goto LABEL_159;
		}
		sub_4F9F90(44, &v77, &v78);
		if (*(_BYTE*)(a1 + 8) & 4 && !*(_DWORD*)v79)
			*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1);
		HIBYTE(v76) = (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
		if (HIBYTE(v76) != v77 / 2 || HIBYTE(v76) <= (unsigned __int8)v76)
			goto LABEL_159;
		v37 = *(float*)(a1 + 176) + 4.0;
		v38 = 8 * *(__int16*)(a1 + 124);
		v39 = *(float*)(a1 + 60);
		v40 = *(char**)(v4 + 736);
		v41 = v37 * *(float*)&byte_587000[v38 + 194136] + *(float*)(a1 + 56);
		v83.field_0 = *(float*)(a1 + 56);
		v83.field_4 = v39;
		v83.field_8 = v41;
		v83.field_C = v37 * *(float*)&byte_587000[v38 + 194140] + *(float*)(a1 + 60);
		if (sub_535250(&v83, 0, 0, 4)) {
			v42 = sub_4E3810((CHAR*)&byte_587000[277332]);
			v43 = (int)v42;
			if (v42) {
				*(_DWORD*)(v42[175] + 4) = a1;
				sub_4DAA50((int)v42, a1, v83.field_8, v83.field_C);
				sub_4E4990(v43, *(int**)(v4 + 692));
				*(float*)(v43 + 80) =
				    *(float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194136] * *(float*)(v43 + 544);
				*(float*)(v43 + 84) =
				    *(float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194140] * *(float*)(v43 + 544);
				v44 = *(_WORD*)(a1 + 124);
				*(_WORD*)(v43 + 124) = v44;
				*(_WORD*)(v43 + 126) = v44;
				sub_501960(891, a1, 0, 0);
				if (!v40[2]) {
					v45 = v40[1] - 1;
					v40[1] = v45;
					if (v45) {
						if (*(_BYTE*)(a1 + 8) & 4)
							sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(v79 + 276) + 2064),
								   (_DWORD*)v4, v45, *v40);
					} else {
						sub_4ED0C0(a1, (int*)v4);
						sub_4E5CC0(v4);
						sub_539FB0((_DWORD*)a1);
					}
				}
				goto LABEL_159;
			}
			return 0;
		}
	LABEL_94:
		sub_501960(323, a1, 0, 0);
		goto LABEL_159;
	}
	sub_4F9F90(44, &v77, &v78);
	if (*(_BYTE*)(a1 + 8) & 4 && !*(_DWORD*)v79)
		*(_DWORD*)v79 = *(_DWORD*)&byte_5D4594[2598000] + v77 * (v78 + 1);
	HIBYTE(v76) = (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) / (unsigned int)(v78 + 1);
	if (HIBYTE(v76) != v77 / 2 || HIBYTE(v76) <= (unsigned __int8)v76)
		goto LABEL_159;
	v29 = *(float*)(a1 + 176) + 4.0;
	v30 = 8 * *(__int16*)(a1 + 124);
	v31 = *(float*)(a1 + 60);
	v32 = v29 * *(float*)&byte_587000[v30 + 194136] + *(float*)(a1 + 56);
	v83.field_0 = *(float*)(a1 + 56);
	v83.field_4 = v31;
	v83.field_8 = v32;
	v83.field_C = v29 * *(float*)&byte_587000[v30 + 194140] + *(float*)(a1 + 60);
	if (!sub_535250(&v83, 0, 0, 5))
		goto LABEL_94;
	v33 = sub_4E3810((CHAR*)&byte_587000[277308]);
	v34 = (int)v33;
	if (!v33)
		return 0;
	v35 = v33[187];
	sub_4ED0C0(a1, (int*)v4);
	sub_4DAA50(v34, a1, v83.field_8, v83.field_C);
	sub_4F3070(v34, v4, 1);
	sub_4E4990(v34, *(int**)(v4 + 692));
	*(float*)(v34 + 80) = *(float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194136] * *(float*)(v34 + 544);
	*(float*)(v34 + 84) = *(float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194140] * *(float*)(v34 + 544);
	v36 = *(_WORD*)(a1 + 124);
	*(_WORD*)(v34 + 124) = v36;
	*(_WORD*)(v34 + 126) = v36;
	*(_BYTE*)(v35 + 4) = 4;
	*(_DWORD*)(v35 + 16) = *(_DWORD*)(a1 + 56);
	*(_DWORD*)(v35 + 20) = *(_DWORD*)(a1 + 60);
	*(_BYTE*)(v35 + 24) = 2;
	sub_501960(891, a1, 0, 0);
LABEL_159:
	v70 = *(_DWORD*)(a1 + 8);
	if (v70 & 4) {
		v71 = v79;
		v72 = HIBYTE(v76);
		*(_BYTE*)(v79 + 236) = HIBYTE(v76);
		if (HIBYTE(v76) >= v77)
			*(_BYTE*)(v71 + 236) = v77 - 1;
	} else if (v70 & 2 && *(_BYTE*)(a1 + 12) & 0x10) {
		v73 = v79;
		*(_BYTE*)(v79 + 481) = HIBYTE(v76);
		v72 = HIBYTE(v76);
		if (HIBYTE(v76) >= v77)
			*(_BYTE*)(v73 + 481) = v77 - 1;
	} else {
		v72 = HIBYTE(v76);
	}
	return v72 < v77;
}
// 539AF2: variable 'v76' is possibly undefined

//----- (00539B90) --------------------------------------------------------
__int16 __cdecl sub_539B90(int a1, int a2) {
	__int16 result; // ax

	result = a2;
	if (a2) {
		result = a1;
		if (a1) {
			if (*(_BYTE*)(a1 + 8) & 2 && *(_DWORD*)(a1 + 12) & 0x20000 && !(*(_DWORD*)(a1 + 16) & 0x8020))
				result = sub_4FF380(a1, 5, 90, 3);
		}
	}
	return result;
}

//----- (00539BD0) --------------------------------------------------------
int __cdecl sub_539BD0(int a1, int a2) {
	int v2;     // eax
	_BYTE* v3;  // edi
	char* v4;   // ebx
	_DWORD* v6; // esi
	int v7;     // eax
	int v8;     // eax

	v2 = sub_415820(a2);
	v3 = *(_BYTE**)(a2 + 736);
	v4 = (char*)v2;
	if (!*v3) {
		v6 = *(_DWORD**)(a1 + 504);
		if (v6) {
			while (1) {
				v7 = v6[4];
				if (v7 & 0x100) {
					if (sub_415820((int)v6) == 2) {
						v8 = v6[184];
						if (*(_BYTE*)(v8 + 1) || *(_BYTE*)(v8 + 2) == 1)
							break;
					}
				}
				v6 = (_DWORD*)v6[124];
				if (!v6)
					goto LABEL_14;
			}
			sub_539D80(a1, (int)v6, a2, v4);
			return 1;
		}
	LABEL_14:
		if (nox_common_gameFlags_check_40A5C0(4096) && v4 == (char*)4)
			sub_539D80(a1, 0, a2, (char*)4);
		if (!(*(_BYTE*)(a1 + 8) & 4))
			return 0;
		if (sub_539FF0((_DWORD*)a1) == 1) {
			sub_4DA2C0(a1, "pattack.c:ReloadQuiver", 0);
			*v3 = 0;
		} else {
			if (nox_common_gameFlags_check_40A5C0(4096) && v4 == (char*)4)
				goto LABEL_25;
			sub_4DA2C0(a1, "pattack.c:NoQuiver", 0);
		}
		if (v4 != (char*)4) {
			if (v4 == (char*)8)
				sub_501960(888, a1, 0, 0);
			goto LABEL_29;
		}
	LABEL_25:
		if (!nox_common_gameFlags_check_40A5C0(4096))
			sub_501960(887, a1, 0, 0);
	LABEL_29:
		sub_4FA020((_DWORD*)a1, 13);
		return 0;
	}
	sub_4DA2C0(a1, "pattack.c:ReloadingQuiver", 0);
	if (v4 == (char*)4) {
		if (!nox_common_gameFlags_check_40A5C0(4096)) {
			sub_501960(887, a1, 0, 0);
			--*v3;
			return 0;
		}
	} else if (v4 == (char*)8) {
		sub_501960(888, a1, 0, 0);
	}
	--*v3;
	return 0;
}

//----- (00539D80) --------------------------------------------------------
_DWORD* __cdecl sub_539D80(int a1, int a2, int a3, char* a4) {
	double v4;      // st7
	char* v5;       // ebx
	int v6;         // eax
	double v7;      // st6
	double v8;      // st7
	float v9;       // eax
	_DWORD* result; // eax
	_DWORD* v11;    // eax
	int v12;        // edi
	__int16 v13;    // ax
	int v14;        // edi
	char v15;       // al
	char v16;       // cl
	float v17;      // [esp+Ch] [ebp-18h]
	float v18;      // [esp+10h] [ebp-14h]
	float4 v19;     // [esp+14h] [ebp-10h]

	v4 = *(float*)(a1 + 176) + 4.0;
	if (a2)
		v5 = *(char**)(a2 + 736);
	else
		v5 = a4;
	v6 = 8 * *(__int16*)(a1 + 124);
	v7 = v4 * *(float*)&byte_587000[v6 + 194136];
	v19.field_4 = *(float*)(a1 + 60);
	v17 = v7 + *(float*)(a1 + 56);
	v8 = v4 * *(float*)&byte_587000[v6 + 194140];
	v9 = *(float*)(a1 + 56);
	v19.field_8 = v17;
	v19.field_0 = v9;
	v18 = v8 + *(float*)(a1 + 60);
	v19.field_C = v18;
	result = (_DWORD*)sub_535250(&v19, 0, 0, 5);
	if (result) {
		if (a2) {
			if (a4 == (char*)4)
				v11 = sub_4E3810((CHAR*)&byte_587000[277440]);
			else
				v11 = sub_4E3810((CHAR*)&byte_587000[277452]);
		} else {
			v11 = sub_4E3810((CHAR*)&byte_587000[277424]);
		}
		v12 = (int)v11;
		if (v11) {
			*(_DWORD*)(v11[175] + 4) = a1;
			sub_4DAA50((int)v11, a1, v17, v18);
			if (a2)
				sub_4E4990(v12, *(int**)(a2 + 692));
			sub_539F40(a1, a3, v12);
			*(float*)(v12 + 80) =
			    *(float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194136] * *(float*)(v12 + 544);
			*(float*)(v12 + 84) =
			    *(float*)&byte_587000[8 * *(__int16*)(a1 + 124) + 194140] * *(float*)(v12 + 544);
			v13 = *(_WORD*)(a1 + 124);
			*(_WORD*)(v12 + 124) = v13;
			*(_WORD*)(v12 + 126) = v13;
		}
		if (a2) {
			if (!v5[2]) {
				if (*(_BYTE*)(a1 + 8) & 4) {
					v14 = *(_DWORD*)(a1 + 748);
					v15 = v5[1] - 1;
					v16 = *v5;
					v5[1] = v15;
					sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(v14 + 276) + 2064), (_DWORD*)a2, v15,
						   v16);
					if (!v5[1])
						sub_4E5CC0(a2);
				}
			}
		}
		if (a4 == (char*)4)
			result = sub_501960(885, a1, 0, 0);
		else
			result = sub_501960(886, a1, 0, 0);
	}
	return result;
}

//----- (00539F40) --------------------------------------------------------
int __cdecl sub_539F40(int a1, int a2, int a3) {
	int v3;                                     // ebx
	int v4;                                     // edi
	int* v5;                                    // esi
	int v6;                                     // eax
	int(__cdecl * v7)(int, int, int, int, int); // ecx
	int result;                                 // eax
	int v9;                                     // [esp+18h] [ebp+8h]
	int v10;                                    // [esp+1Ch] [ebp+Ch]

	v3 = a3;
	v4 = a2;
	v10 = *(_DWORD*)(a3 + 692);
	v9 = 2;
	v5 = (int*)(*(_DWORD*)(v4 + 692) + 8);
	do {
		v6 = *v5;
		if (*v5) {
			if (*(char(__cdecl**)(int, int, int, int))(v6 + 52) == sub_4E0640) {
				*(_DWORD*)(v10 + 12) = v6;
			} else {
				v7 = *(int(__cdecl**)(int, int, int, int, int))(v6 + 40);
				if (v7 == sub_4E09B0)
					v7(v6, v4, a1, 0, v3);
			}
		}
		++v5;
		result = --v9;
	} while (v9);
	return result;
}

//----- (00539FB0) --------------------------------------------------------
int __cdecl sub_539FB0(_DWORD* a1) {
	int v1; // esi

	v1 = a1[126];
	if (!v1)
		return 0;
	while (sub_415820(v1) != 128) {
		v1 = *(_DWORD*)(v1 + 496);
		if (!v1)
			return 0;
	}
	return sub_53A420(a1, v1, 1, 1);
}

//----- (00539FF0) --------------------------------------------------------
int __cdecl sub_539FF0(_DWORD* a1) {
	int v1; // esi

	v1 = a1[126];
	if (!v1)
		return 0;
	while (sub_415820(v1) != 2) {
		v1 = *(_DWORD*)(v1 + 496);
		if (!v1)
			return 0;
	}
	return sub_53A420(a1, v1, 1, 1);
}

//----- (0053A030) --------------------------------------------------------
int __cdecl sub_53A030(int a1, int a2) {
	int v2;     // ebp
	int result; // eax
	int v4;     // eax
	int v5;     // ecx

	v2 = *(_DWORD*)(a1 + 748);
	if (!(*(_DWORD*)(a2 + 8) & 0x1001000))
		return 0;
	v4 = *(_DWORD*)(a2 + 16);
	if (!(v4 & 0x100))
		return 0;
	result = *(_DWORD*)(a1 + 504);
	if (!result)
		return 0;
	while (result != a2) {
		result = *(_DWORD*)(result + 496);
		if (!result)
			return result;
	}
	*(_BYTE*)(v2 + 2068) = 0;
	v5 = *(_DWORD*)(a2 + 16);
	BYTE1(v5) &= 0xFEu;
	*(_DWORD*)(a2 + 16) = v5;
	if (*(_BYTE*)(a1 + 12) & 0x10)
		sub_4E4B20(a1, a2, 0);
	if (*(_BYTE*)(a2 + 12) & 0xC)
		sub_53A0F0(a1, 1, 1);
	if (!(*(_BYTE*)(a2 + 12) & 2))
		*(_DWORD*)(v2 + 2064) = 0;
	sub_4F3030(a2, a1);
	sub_4FEB60(a1, a2);
	return 1;
}

//----- (0053A0F0) --------------------------------------------------------
void __cdecl sub_53A0F0(int a1, int a2, int a3) {
	int v3; // esi
	int v4; // eax

	v3 = *(_DWORD*)(a1 + 504);
	if (v3) {
		while (1) {
			v4 = *(_DWORD*)(v3 + 16);
			if (v4 & 0x100) {
				if (sub_415820(v3) == 2)
					break;
			}
			v3 = *(_DWORD*)(v3 + 496);
			if (!v3)
				return;
		}
		sub_53A140((_DWORD*)a1, v3, a2, a3);
	}
}

//----- (0053A140) --------------------------------------------------------
int __cdecl sub_53A140(_DWORD* a1, int a2, int a3, int a4) {
	_DWORD* v4;  // edi
	int v5;      // eax
	_DWORD* v6;  // ebx
	int v7;      // ecx
	int v8;      // eax
	int v10;     // esi
	_DWORD* v11; // eax
	int v12;     // edx
	int v13;     // eax
	int v14;     // ebx
	int v15;     // ebx
	int v16;     // ebp
	int v17;     // ebp
	_DWORD* v18; // eax
	int v19;     // [esp+14h] [ebp+8h]

	v4 = (_DWORD*)a2;
	v5 = sub_415820(a2);
	v6 = a1;
	v7 = v5;
	v19 = v5;
	v8 = a1[2];
	if (v8 & 2)
		return sub_53A030((int)a1, (int)v4);
	if (!(v8 & 4) || !(v4[2] & 0x1001000))
		return 0;
	v10 = a1[187];
	if (*(_BYTE*)(v10 + 88) == 1) {
		sub_4FA020(a1, 13);
		v7 = v19;
	}
	v11 = *(_DWORD**)(v10 + 104);
	if (!v11 || v11 != v4 && v7 != 2)
		return 0;
	if (v7 & 0xC)
		sub_53A0F0((int)a1, a3, a4);
	sub_4FEB60((int)a1, (int)v4);
	if (v19 == 2) {
		v12 = v4[4];
		BYTE1(v12) &= 0xFEu;
		v4[4] = v12;
		*(_DWORD*)(*(_DWORD*)(v10 + 276) + 4) &= 0xFFFFFFFD;
		if (a3)
			sub_4D8590(*(unsigned __int8*)(*(_DWORD*)(v10 + 276) + 2064), v4);
		if (a4)
			sub_4D84C0(255, (int)v4);
	} else {
		v13 = *(_DWORD*)(v10 + 104);
		v14 = *(_DWORD*)(v13 + 16);
		BYTE1(v14) &= 0xFEu;
		*(_DWORD*)(v13 + 16) = v14;
		v15 = *(_DWORD*)(v10 + 276);
		*(_DWORD*)(v15 + 4) &= ~sub_415820(*(_DWORD*)(v10 + 104));
		if (a3)
			sub_4D8590(*(unsigned __int8*)(*(_DWORD*)(v10 + 276) + 2064), *(_DWORD**)(v10 + 104));
		if (a4)
			sub_4D84C0(255, (int)v4);
		v6 = a1;
		*(_DWORD*)(v10 + 104) = 0;
	}
	sub_4F3030((int)v4, (int)v6);
	sub_980523(v6);
	v16 = v6[187];
	if (!*(_DWORD*)(v16 + 108) || !(sub_415820(*(_DWORD*)(v16 + 108)) & 0x7FFE40C)) {
		v17 = *(_DWORD*)(*(_DWORD*)(v16 + 276) + 2500);
		if (v17 && (unsigned __int8)*(_DWORD*)(v17 + 16) == 16) {
			sub_4F2F70((int)v6, v17);
		} else {
			v18 = sub_9805EB(v6);
			if (v18)
				sub_4F2F70((int)v6, (int)v18);
		}
	}
	return 1;
}

//----- (0053A2C0) --------------------------------------------------------
int __cdecl sub_53A2C0(int a1, int a2) {
	int v2;     // ebp
	int result; // eax
	int v4;     // eax
	int v5;     // ecx
	int v6;     // eax
	int v7;     // edx
	int v8;     // ecx

	v2 = *(_DWORD*)(a1 + 748);
	if (!(*(_DWORD*)(a2 + 8) & 0x1001000))
		return 0;
	v4 = *(_DWORD*)(a2 + 16);
	if (v4 & 0x100)
		return 0;
	result = *(_DWORD*)(a1 + 504);
	if (!result)
		return 0;
	while (result != a2) {
		result = *(_DWORD*)(result + 496);
		if (!result)
			return result;
	}
	*(_BYTE*)(v2 + 2068) = 0;
	if (!(*(_BYTE*)(a2 + 12) & 0xC))
		sub_53A0F0(a1, 1, 1);
	v5 = *(_DWORD*)(a2 + 12);
	if (!(v5 & 2)) {
		v6 = *(_DWORD*)(a1 + 504);
		if (v6) {
			while (1) {
				v7 = *(_DWORD*)(v6 + 16);
				if (v7 & 0x100) {
					if (*(_DWORD*)(v6 + 8) & 0x1001000 &&
					    (!(v5 & 0xC) || !(*(_BYTE*)(v6 + 12) & 2)))
						break;
				}
				v6 = *(_DWORD*)(v6 + 496);
				if (!v6)
					goto LABEL_22;
			}
			sub_53A030(a1, v6);
		}
	}
LABEL_22:
	v8 = *(_DWORD*)(a2 + 16);
	BYTE1(v8) |= 1u;
	*(_DWORD*)(a2 + 16) = v8;
	if (*(_BYTE*)(a1 + 12) & 0x10)
		sub_4E4B20(a1, a2, 1);
	if (!(*(_BYTE*)(a2 + 12) & 2))
		*(_DWORD*)(v2 + 2064) = a2;
	sub_4F2FF0(a2, a1);
	if (sub_415820(a2) & 0x7FFE40C)
		sub_53A3D0((_DWORD*)a1);
	return 1;
}

//----- (0053A3D0) --------------------------------------------------------
void __cdecl sub_53A3D0(_DWORD* a1) {
	_DWORD* i; // esi
	int v2;    // eax

	if (a1) {
		for (i = (_DWORD*)a1[126]; i; i = (_DWORD*)i[124]) {
			if (i[2] & 0x2000000) {
				v2 = i[4];
				if (v2 & 0x100) {
					if (sub_415C70((int)i) & 0x3000000)
						sub_53E430(a1, (int)i, 1, 1);
				}
			}
		}
	}
}

//----- (0053A420) --------------------------------------------------------
int __cdecl sub_53A420(_DWORD* a1, int a2, int a3, int a4) {
	int v4;     // ebx
	int v5;     // eax
	int v6;     // eax
	int result; // eax
	int v8;     // ebp
	int v9;     // eax
	int v10;    // eax
	int v11;    // edx
	int v12;    // eax

	v4 = sub_415820(a2);
	if (!(*(_DWORD*)(a2 + 8) & 0x1001000))
		return 0;
	v5 = *(_DWORD*)(a2 + 16);
	if (v5 & 0x100)
		return 0;
	v6 = a1[2];
	if (v6 & 2)
		return sub_53A2C0((int)a1, a2);
	if (!(v6 & 4))
		return 0;
	v8 = a1[187];
	if (sub_4FC3E0((int)a1, 2) || sub_4FC3E0((int)a1, 1))
		return 0;
	if (!sub_57B3D0(a2, *(_BYTE*)(*(_DWORD*)(v8 + 276) + 2251))) {
		sub_4DA2C0((int)a1, "weapon.c:WeaponEquipClassFail", 0);
		goto LABEL_10;
	}
	LOBYTE(v9) = sub_4F3180((int)a1, a2);
	if (!v9) {
		sub_4DA2C0((int)a1, "weapon.c:WeaponEquipStrengthFail", 0);
		if (a4)
			sub_501960(925, (int)a1, 2, a1[9]);
		return 0;
	}
	result = a1[126];
	if (!result)
		return 0;
	while (result != a2) {
		result = *(_DWORD*)(result + 496);
		if (!result)
			return result;
	}
	if (*(_BYTE*)(v8 + 88) == 1)
		sub_4FA020(a1, 13);
	if (v4 == 2) {
		if (!(*(_BYTE*)(*(_DWORD*)(v8 + 276) + 4) & 0xC) && !sub_53A680((int)a1)) {
			sub_4DA2C0((int)a1, "weapon.c:BowNotFound", 0);
		LABEL_10:
			if (a4)
				sub_501960(925, (int)a1, 2, a1[9]);
			return 0;
		}
		sub_53A0F0((int)a1, 1, 1);
	}
	v10 = *(_DWORD*)(v8 + 104);
	if (v10 && v4 != 2 && !sub_53A140(a1, v10, 1, 1))
		return 0;
	v11 = *(_DWORD*)(a2 + 16);
	BYTE1(v11) |= 1u;
	*(_DWORD*)(a2 + 16) = v11;
	*(_DWORD*)(*(_DWORD*)(v8 + 276) + 4) |= v4;
	sub_4D8540(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (_DWORD*)a2, a3);
	if (v4 != 2)
		*(_DWORD*)(v8 + 104) = a2;
	v12 = *(_DWORD*)(a2 + 8);
	if (v12 & 0x1000 && *(_DWORD*)(a2 + 12) & 0x47F0000) {
		sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (_DWORD*)a2,
			   *(_BYTE*)(*(_DWORD*)(a2 + 736) + 108), *(_BYTE*)(*(_DWORD*)(a2 + 736) + 109));
	} else if (v12 & 0x1000000) {
		if (v4 & 0x82) {
			sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (_DWORD*)a2,
				   *(_BYTE*)(*(_DWORD*)(a2 + 736) + 1), **(_BYTE**)(a2 + 736));
		} else if (v4 & 0xC) {
			**(_BYTE**)(a2 + 736) = 0;
		}
	}
	sub_4F2FF0(a2, (int)a1);
	if (v4 & 0x7FFE40C)
		sub_53A3D0(a1);
	return 1;
}
// 53A4E9: variable 'v9' is possibly undefined

//----- (0053A680) --------------------------------------------------------
int __cdecl sub_53A680(int a1) {
	int v1; // esi

	v1 = *(_DWORD*)(a1 + 504);
	if (!v1)
		return 0;
	while (!(sub_415820(v1) & 0xC)) {
		v1 = *(_DWORD*)(v1 + 496);
		if (!v1)
			return 0;
	}
	return sub_53A420((_DWORD*)a1, v1, 1, 1);
}

//----- (0053A6C0) --------------------------------------------------------
void __cdecl sub_53A6C0(int a1, int a2) {
	int v2;     // edx
	__int16 v3; // ax

	if (a1 && a2) {
		v2 = *(_DWORD*)(a2 + 8);
		if (v2 & 0x1000) {
			sub_501960(830, a1, 0, 0);
		} else {
			v3 = *(_WORD*)(a2 + 24);
			if (v3 & 0x10) {
				sub_501960(842, a1, 0, 0);
			} else if (v3 & 8) {
				sub_501960(844, a1, 0, 0);
			}
		}
	}
}

//----- (0053A720) --------------------------------------------------------
int __cdecl sub_53A720(int a1, int a2, int a3, int a4) {
	_DWORD* v4; // esi
	int v5;     // ebp
	int v6;     // ebx
	int v8;     // eax
	int v9;     // ebp
	int v10;    // eax
	int v11;    // eax
	float v12;  // [esp+0h] [ebp-14h]
	int v13;    // [esp+18h] [ebp+4h]

	v4 = (_DWORD*)a1;
	v5 = 0;
	if (*(_BYTE*)(a1 + 8) & 4) {
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			if (*(_DWORD*)(a2 + 12) & 0x200000) {
				v12 = sub_419D40(&byte_587000[277556]);
				v6 = nox_float2int(v12);
				if (sub_4E7D30(a1, *(unsigned __int16*)(a2 + 4)) >= v6) {
					sub_4DA2C0(a1, "pickup.c:MaxSameItem", 0);
					sub_501960(925, a1, 0, 0);
					return 0;
				}
			}
		}
	}
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096) && sub_409F40(2)) {
		if (!(*(_BYTE*)(a2 + 12) & 0x82) && sub_4E7EC0(a1, a2))
			v5 = 1;
		if (*(_BYTE*)(a2 + 12) & 0x40) {
			v8 = *(_DWORD*)(a1 + 516);
			if (v8) {
				while (!(*(_DWORD*)(v8 + 8) & 0x1000000) || !(*(_BYTE*)(v8 + 12) & 0x40)) {
					v8 = *(_DWORD*)(v8 + 512);
					if (!v8)
						goto LABEL_18;
				}
				goto LABEL_19;
			}
		}
	LABEL_18:
		if (v5 == 1) {
		LABEL_19:
			if (*(_BYTE*)(a1 + 8) & 4) {
				sub_4DA2C0(a1, "weapon.c:CannotPickupDuplicateWeapon", 0);
				sub_501960(925, a1, 2, *(_DWORD*)(a1 + 36));
			}
			return 0;
		}
	}
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096) &&
	    *(_BYTE*)(a1 + 8) & 4 && !sub_57B3D0(a2, *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2251))) {
		sub_4DA2C0(a1, "weapon.c:WeaponEquipClassFail", 0);
		sub_501960(925, a1, 2, *(_DWORD*)(a1 + 36));
		return 0;
	}
	if (sub_4F31E0(a1, a2, a3) != 1)
		return 0;
	if (*(_BYTE*)(a1 + 8) & 4) {
		v9 = 0;
		v13 = *(_DWORD*)(a1 + 748);
		if (!*(_DWORD*)(v13 + 104) && !sub_419E60((int)v4) && sub_415820(a2) != 2)
			v9 = sub_53A420(v4, a2, a4, 0);
		if (!sub_419E60((int)v4) && sub_415820(a2) == 2) {
			v10 = *(_DWORD*)(*(_DWORD*)(v13 + 276) + 4);
			if (v10 & 0xC) {
				if (!(v10 & 2))
					v9 = sub_53A420(v4, a2, a4, 0);
			}
		}
		if (!v9) {
			v11 = *(_DWORD*)(a2 + 8);
			if (v11 & 0x1000 && *(_DWORD*)(a2 + 12) & 0x47F0000) {
				sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(v13 + 276) + 2064), (_DWORD*)a2,
					   *(_BYTE*)(*(_DWORD*)(a2 + 736) + 108),
					   *(_BYTE*)(*(_DWORD*)(a2 + 736) + 109));
			} else if (v11 & 0x1000000 && *(_BYTE*)(a2 + 12) & 0x82) {
				sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(v13 + 276) + 2064), (_DWORD*)a2,
					   *(_BYTE*)(*(_DWORD*)(a2 + 736) + 1), **(_BYTE**)(a2 + 736));
			}
		}
	}
	sub_53A6C0((int)v4, a2);
	sub_5116F0(a2);
	return 1;
}

//----- (0053A9C0) --------------------------------------------------------
int __cdecl sub_53A9C0(int a1, int a2, int a3, int a4) {
	int v4; // edi
	int v5; // eax

	v4 = sub_53A720(a1, a2, a3, a4);
	if (v4 == 1 && *(_BYTE*)(a1 + 8) & 4 && !sub_419E60(a1)) {
		v5 = *(_DWORD*)(a2 + 12);
		if (0x800000 & v5) {
			sub_4DA2C0(a1, "weapon.c:PickupHalberdOblivion", 0);
			sub_501960(914, a1, 0, 0);
		} else if (v5 & 0x1000000) {
			sub_4DA2C0(a1, "weapon.c:PickupHeartOblivion", 0);
			sub_501960(915, a1, 0, 0);
		} else if (v5 & 0x2000000) {
			sub_4DA2C0(a1, "weapon.c:PickupWierdlingOblivion", 0);
			sub_501960(916, a1, 0, 0);
		} else if (v5 & 0x4000000) {
			sub_4DA2C0(a1, "weapon.c:PickupOrbOblivion", 0);
			sub_501960(917, a1, 0, 0);
		}
		sub_57AF30(a1, 1);
		sub_4F2F70((_DWORD*)a1, a2);
	}
	return v4;
}

//----- (0053AAB0) --------------------------------------------------------
void __cdecl sub_53AAB0(int a1) {
	int v2;     // ecx
	__int16 v3; // cx

	if (a1) {
		v2 = *(_DWORD*)(a1 + 8);
		if (v2 & 0x1000) {
			sub_501960(831, a1, 0, 0);
		} else {
			v3 = *(_WORD*)(a1 + 24);
			if (v3 & 0x10) {
				sub_501960(843, a1, 0, 0);
			} else if (v3 & 8) {
				sub_501960(845, a1, 0, 0);
			}
		}
	}
}

//----- (0053AB10) --------------------------------------------------------
int __cdecl sub_53AB10(int a1, _DWORD* a2, int* a3) {
	if (sub_4ED290(a1, (int)a2, (float2*)a3) != 1)
		return 0;
	sub_53AAB0((int)a2);
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096)) {
		if (sub_409F40(2))
			sub_511660(a2, 25 * *(_DWORD*)&byte_5D4594[2649704]);
	}
	return 1;
}

//----- (0053AB90) --------------------------------------------------------
void __cdecl sub_53AB90(int a1, int a2) {
	int v2; // esi
	int v3; // eax

	if (a1) {
		v2 = *(_DWORD*)(a1 + 748);
		if (a2) {
			if (!sub_57B3D0(a2, *(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251)) ||
			    (LOBYTE(v3) = sub_4F3180(a1, a2), !v3))
				sub_4D9670(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), 0, 1);
		}
		*(_DWORD*)(v2 + 108) = a2;
	}
}
// 53ABD1: variable 'v3' is possibly undefined

//----- (0053AC10) --------------------------------------------------------
void __cdecl sub_53AC10(int a1) {
	void(__cdecl * v1)(int, _DWORD, _DWORD); // eax

	if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128)) > 0x28) {
		v1 = *(void(__cdecl**)(int, _DWORD, _DWORD))(a1 + 696);
		if (v1)
			v1(a1, 0, 0);
		sub_4E5CC0(a1);
	}
}

//----- (0053AC50) --------------------------------------------------------
char __cdecl sub_53AC50(int a1) {
	_DWORD* v1; // edi
	int v2;     // ecx
	int v3;     // eax
	int v4;     // eax
	int v5;     // eax
	int v6;     // eax
	int v7;     // edi

	v1 = *(_DWORD**)(a1 + 748);
	v2 = v1[2];
	v3 = v1[1];
	if (v2 == v3) {
		if (v1[3] != v3) {
			v4 = *(_DWORD*)(a1 + 12);
			if (v4 & 4) {
				if (*(_BYTE*)(a1 + 24) & 8)
					sub_501960(245, a1, 0, 0);
				else
					sub_501960(241, a1, 0, 0);
			} else if (v4 & 1) {
				sub_501960(247, a1, 0, 0);
			} else if (v4 & 0x1000) {
				sub_501960(1014, a1, 0, 0);
			} else {
				sub_501960(237, a1, 0, 0);
			}
			goto LABEL_24;
		}
		if (v2 == v3)
			goto LABEL_24;
	}
	if (v1[3] == v3) {
		v5 = *(_DWORD*)(a1 + 12);
		if (v5 & 4) {
			if (*(_BYTE*)(a1 + 24) & 8)
				sub_501960(246, a1, 0, 0);
			else
				sub_501960(243, a1, 0, 0);
		} else if (v5 & 1) {
			sub_501960(248, a1, 0, 0);
		} else if (v5 & 0x1000) {
			sub_501960(1015, a1, 0, 0);
		} else {
			sub_501960(239, a1, 0, 0);
		}
		sub_4DA920((_DWORD*)a1);
	}
LABEL_24:
	v6 = v1[3];
	if (v1[2] != v6) {
		sub_4E44F0(a1);
		v6 = v1[3];
		v1[2] = v6;
	}
	if (*(_DWORD*)(a1 + 16) & 0x1000000) {
		if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - v1[11]) > *(int*)&byte_5D4594[2649704] >> 1) {
			v7 = v1[1];
			if (v6 != v7) {
				if (v6 - v7 + (v6 - v7 < 0 ? 0x20 : 0) >= 16)
					sub_548860(a1, 2);
				else
					sub_548860(a1, -2);
				LOBYTE(v6) = sub_537610(a1);
			}
		}
	}
	return v6;
}

//----- (0053ADC0) --------------------------------------------------------
void __cdecl sub_53ADC0(int a1) {
	int v1; // eax
	int v2; // ecx

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(_DWORD*)(v1 + 4);
	if (v2 <= 0) {
		sub_4E5CC0(a1);
	} else {
		*(_DWORD*)(v1 + 4) = v2 - 1;
		if (*(_DWORD*)(v1 + 12) == 4)
			*(_DWORD*)(a1 + 112) = 1065353216;
		else
			*(_DWORD*)(a1 + 112) = 1064514355;
	}
}

//----- (0053AE00) --------------------------------------------------------
char __cdecl sub_53AE00(int a1) {
	_BYTE* v1; // esi
	int v2;    // eax
	bool v3;   // zf

	v1 = *(_BYTE**)(a1 + 748);
	if (v1[1]) {
		LOBYTE(v2) = v1[1] - 1;
		if (v1[1] == 1) {
			LOBYTE(v2) = *v1 - 1;
			v3 = *v1 == 1;
			*v1 = v2;
			if (v3) {
				LOWORD(v2) = nox_common_randomInt_415FA0(0, 255);
				*(_WORD*)(a1 + 126) = v2;
				v1[1] = 0;
				*v1 = 2;
				v1[2] = 0;
			}
		}
	} else {
		v2 = 8 * *(__int16*)(a1 + 124);
		*(float*)(a1 + 88) = *(float*)&byte_587000[v2 + 194136] * 4.0;
		*(float*)(a1 + 92) = *(float*)&byte_587000[v2 + 194140] * 4.0;
		LOBYTE(v2) = *v1 - 1;
		v3 = *v1 == 1;
		*v1 = v2;
		if (v3) {
			LOBYTE(v2) = v1[2] + 1;
			v1[2] = v2;
			if ((_BYTE)v2 == 4) {
				v1[2] = 0;
				v1[1] = 1;
				LOBYTE(v2) = nox_common_randomInt_415FA0(5, 60);
				*v1 = v2;
			} else {
				*v1 = 2;
			}
		}
	}
	return v2;
}

//----- (0053AEC0) --------------------------------------------------------
float* __cdecl sub_53AEC0(int a1) {
	float* v1;     // esi
	int v2;        // eax
	int v3;        // ebx
	double v4;     // st7
	double v5;     // st7
	int v6;        // edi
	float* result; // eax
	float v8;      // [esp+0h] [ebp-38h]
	float v9;      // [esp+4h] [ebp-34h]
	float v10;     // [esp+10h] [ebp-28h]
	float v11;     // [esp+14h] [ebp-24h]
	float v12;     // [esp+1Ch] [ebp-1Ch]
	float v13;     // [esp+1Ch] [ebp-1Ch]
	float v14;     // [esp+2Ch] [ebp-Ch]
	float v15;     // [esp+30h] [ebp-8h]
	int v16;       // [esp+34h] [ebp-4h]
	float v17;     // [esp+34h] [ebp-4h]
	int v18;       // [esp+3Ch] [ebp+4h]
	float v19;     // [esp+3Ch] [ebp+4h]
	float v20;     // [esp+3Ch] [ebp+4h]

	v1 = (float*)a1;
	v2 = 8 * *(__int16*)(a1 + 124);
	v3 = 0;
	v4 = *(float*)&byte_587000[v2 + 194136] * *(float*)(a1 + 544);
	v18 = 0;
	v1[22] = v4 * 0.25 + v1[22];
	v1[23] = *(float*)&byte_587000[v2 + 194140] * v1[136] * 0.25 + v1[23];
	v14 = (v1[14] - v1[18]) * 0.25;
	v15 = (v1[15] - v1[19]) * 0.25;
	do {
		v5 = (double)v18;
		v19 = v5;
		v12 = v5 * v14 + v1[18];
		v16 = nox_float2int(v12);
		v13 = v19 * v15 + v1[19];
		v6 = 2;
		v20 = (double)nox_float2int(v13);
		v17 = (double)v16;
		do {
			v11 = sub_416030(-2.0, 2.0);
			v10 = sub_416030(-2.0, 2.0);
			v9 = sub_416030(-4.0, 4.0) + v20;
			v8 = sub_416030(-4.0, 4.0) + v17;
			result = sub_54FD80(v8, v9, 1, 6, v10, v11, 0.0, (int)v1);
			--v6;
		} while (v6);
		v18 = ++v3;
	} while (v3 < 4);
	return result;
}

//----- (0053B030) --------------------------------------------------------
void __cdecl sub_53B030(int a1) {
	sub_52E040(a1 + 56, **(float**)(a1 + 748), 0, *(float*)(*(_DWORD*)(a1 + 748) + 8), 0, 0, 0);
}

//----- (0053B060) --------------------------------------------------------
char __cdecl sub_53B060(_DWORD* a1) {
	unsigned int* v1; // esi
	unsigned int v2;  // eax

	v1 = (unsigned int*)a1[187];
	if (!(a1[4] & 0x1000000)) {
		v2 = *v1;
		LOBYTE(v2) = *v1 & 0xF6;
		*v1 = v2;
		return v2;
	}
	if (!(*(_BYTE*)v1 & 8)) {
		*((_BYTE*)v1 + 8) = 0;
		a1[34] = *(_DWORD*)&byte_5D4594[2598000];
		sub_4E4880((int)a1, 0);
	}
	if (*((_BYTE*)v1 + 8)) {
		if (*((_BYTE*)v1 + 8) != 1) {
			if (*((_BYTE*)v1 + 8) == 3 && *(_DWORD*)&byte_5D4594[2598000] > a1[34] && !(*(_BYTE*)v1 & 1))
				*((_BYTE*)v1 + 8) = 1;
			goto LABEL_18;
		}
		if (*(_DWORD*)&byte_5D4594[2598000] > a1[34] && *(_BYTE*)v1 & 1) {
			sub_501960(v1[10], (int)a1, 0, 0);
			sub_4E4880((int)a1, 0);
			sub_502490((int*)v1 + 7, 0, (int)a1);
			*((_BYTE*)v1 + 8) = (*v1 & 2) != 0 ? 5 : 0;
		LABEL_17:
			a1[34] = *(_DWORD*)&byte_5D4594[2598000] + *(_DWORD*)&byte_5D4594[2649704];
			goto LABEL_18;
		}
	} else if (*(_DWORD*)&byte_5D4594[2598000] > a1[34] && *(_BYTE*)v1 & 1) {
		sub_501960(v1[9], (int)a1, 0, 0);
		sub_4E4880((int)a1, 1);
		sub_502490((int*)v1 + 5, v1[1], (int)a1);
		*((_BYTE*)v1 + 8) = 3;
		goto LABEL_17;
	}
LABEL_18:
	v2 = *v1;
	if (*v1 & 1)
		LOBYTE(v2) = v2 | 4;
	else
		LOBYTE(v2) = v2 & 0xFB;
	*v1 = v2;
	*v1 = v2 & 0xFFFFFFFE | 8;
	return v2;
}

//----- (0053B1B0) --------------------------------------------------------
char __cdecl sub_53B1B0(int a1) {
	int* v1; // esi
	int v2;  // eax
	int v3;  // ebx
	int v4;  // eax

	v1 = *(int**)(a1 + 748);
	if (!*(_DWORD*)&byte_5D4594[2488680]) {
		*(_DWORD*)&byte_5D4594[2488680] = sub_4E3AA0((CHAR*)&byte_587000[278100]);
		*(_DWORD*)&byte_5D4594[2488676] = sub_4E3AA0((CHAR*)&byte_587000[278108]);
	}
	v2 = *(unsigned __int16*)(a1 + 4);
	if ((unsigned __int16)v2 == *(_DWORD*)&byte_5D4594[2488680] || v2 == *(_DWORD*)&byte_5D4594[2488676])
		v3 = 0;
	else
		v3 = *(_DWORD*)&byte_5D4594[2649704];
	if (*(_DWORD*)(a1 + 16) & 0x1000000) {
		if (!(*(_BYTE*)v1 & 8)) {
			*((_BYTE*)v1 + 8) = 0;
			*(_DWORD*)(a1 + 136) = *(_DWORD*)&byte_5D4594[2598000];
			sub_4E4880(a1, 0);
		}
		if (*((_BYTE*)v1 + 8)) {
			if (*((_BYTE*)v1 + 8) == 1 && *(_DWORD*)&byte_5D4594[2598000] > *(int*)(a1 + 136) &&
			    !(*(_BYTE*)v1 & 1)) {
				sub_501960(v1[10], a1, 0, 0);
				sub_4E4880(a1, 0);
				sub_502490(v1 + 7, 0, a1);
				*((_BYTE*)v1 + 8) = (*v1 & 2) != 0 ? 5 : 0;
			}
		} else if (*(_BYTE*)v1 & 1) {
			sub_501960(v1[9], a1, 0, 0);
			sub_4E4880(a1, 1);
			sub_502490(v1 + 5, v1[1], a1);
			*((_BYTE*)v1 + 8) = 1;
			*(_DWORD*)(a1 + 136) = v3 + *(_DWORD*)&byte_5D4594[2598000];
		}
		v4 = *v1;
		if (*v1 & 1)
			LOBYTE(v4) = v4 | 4;
		else
			LOBYTE(v4) = v4 & 0xFB;
		*v1 = v4;
		LOBYTE(v4) = v4 & 0xFE | 8;
		*v1 = v4;
	} else {
		v4 = *v1;
		LOBYTE(v4) = *v1 & 0xF6;
		*v1 = v4;
	}
	return v4;
}

//----- (0053B300) --------------------------------------------------------
char __cdecl sub_53B300(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)(a1 + 16);
	if (v1 & 0x1000000)
		LOBYTE(v1) = v1 & 0xBF;
	else
		LOBYTE(v1) = v1 | 0x40;
	*(_DWORD*)(a1 + 16) = v1;
	return v1;
}

//----- (0053B320) --------------------------------------------------------
char __cdecl sub_53B320(_DWORD* a1) {
	int v1; // eax

	v1 = a1[4];
	if (v1 & 0x1000000) {
		if (a1[174] && v1 & 0x40) {
			LOBYTE(v1) = v1 & 0xBF;
			a1[4] = v1;
			LOBYTE(v1) = sub_537610((int)a1);
		} else {
			LOBYTE(v1) = v1 & 0xBF;
			a1[4] = v1;
		}
	} else {
		if (!a1[33]) {
			sub_4E44F0((int)a1);
			a1[33] = 1;
		}
		v1 = a1[4];
		LOBYTE(v1) = v1 | 0x40;
		a1[4] = v1;
	}
	return v1;
}

//----- (0053B380) --------------------------------------------------------
char __cdecl sub_53B380(int a1) {
	int v1; // esi
	int v2; // eax
	int v3; // edi

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(_DWORD*)(v1 + 4);
	if (v2) {
		sub_537610(a1);
		v3 = *(_DWORD*)(*(_DWORD*)(v1 + 4) + 748);
		if (*(_BYTE*)(v3 + 12) == 1) {
			if (*(_DWORD*)(v3 + 16) <= 32)
				sub_517F90((float2*)(a1 + 56), 64.0, sub_53B410, a1);
			if (*(_BYTE*)(v1 + 12) != *(_BYTE*)(v3 + 12))
				sub_53B490(a1, 0);
		} else if (*(_BYTE*)(v3 + 12) == 3 && *(_BYTE*)(v1 + 12) != *(_BYTE*)(v3 + 12)) {
			sub_53B490(a1, 1);
			LOBYTE(v2) = *(_BYTE*)(v3 + 12);
			*(_BYTE*)(v1 + 12) = v2;
			return v2;
		}
		LOBYTE(v2) = *(_BYTE*)(v3 + 12);
		*(_BYTE*)(v1 + 12) = v2;
	}
	return v2;
}

//----- (0053B410) --------------------------------------------------------
void __cdecl sub_53B410(int a1, int a2) {
	int v2;   // edi
	int v3;   // ebx
	float v4; // [esp+0h] [ebp-10h]
	float v5; // [esp+0h] [ebp-10h]

	if (sub_57B850((float2*)(a2 + 56), (float*)(a2 + 172), (float2*)(a1 + 56))) {
		v2 = *(_DWORD*)(a2 + 748);
		v3 = *(_DWORD*)(*(_DWORD*)(v2 + 4) + 748);
		v4 = *(float*)(a1 + 104) + 64.0 - (double)*(int*)(v3 + 16);
		if (sub_419A10(v4) < 10.0) {
			sub_4E7010(a1, (float2*)(*(_DWORD*)(v2 + 4) + 56));
			v5 = (double)*(int*)(v3 + 16);
			sub_4E46F0(a1, v5);
		}
	}
}

//----- (0053B490) --------------------------------------------------------
_DWORD* __cdecl sub_53B490(int a1, int a2) {
	_DWORD* result; // eax
	int v3;         // ecx
	int v4;         // ecx
	int v5;         // ecx
	int v6;         // ecx

	if (a2) {
		result = (_DWORD*)a1;
		v3 = *(unsigned __int16*)(a1 + 24);
		if ((unsigned __int16)v3 == 8) {
			result = sub_501960(257, a1, 0, 0);
		} else if (v3 == 16) {
			v4 = *(_DWORD*)(a1 + 12);
			if (v4 & 0x20) {
				result = sub_501960(253, a1, 0, 0);
			} else if (v4 & 0x40) {
				result = sub_501960(259, a1, 0, 0);
			} else {
				result = sub_501960(251, a1, 0, 0);
			}
		} else if (v3 == 32) {
			if (*(_BYTE*)(a1 + 12) & 2)
				result = sub_501960(255, a1, 0, 0);
			else
				result = sub_501960(249, a1, 0, 0);
		}
	} else {
		result = (_DWORD*)a1;
		v5 = *(unsigned __int16*)(a1 + 24);
		if ((unsigned __int16)v5 == 8) {
			result = sub_501960(258, a1, 0, 0);
		} else if (v5 == 16) {
			v6 = *(_DWORD*)(a1 + 12);
			if (v6 & 0x20) {
				result = sub_501960(254, a1, 0, 0);
			} else if (v6 & 0x40) {
				result = sub_501960(260, a1, 0, 0);
			} else {
				result = sub_501960(252, a1, 0, 0);
			}
		} else if (v5 == 32) {
			if (*(_BYTE*)(a1 + 12) & 2)
				result = sub_501960(256, a1, 0, 0);
			else
				result = sub_501960(250, a1, 0, 0);
		}
	}
	return result;
}

//----- (0053B5D0) --------------------------------------------------------
void __cdecl sub_53B5D0(_DWORD* a1) {
	int v1; // esi
	int v2; // eax
	int v3; // eax
	int v4; // eax

	v1 = a1[187];
	switch (*(unsigned __int8*)(v1 + 12)) {
	case 0u:
		if (a1[4] & 0x1000000) {
			if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - a1[34]) > *(int*)&byte_5D4594[2649704]) {
				*(_BYTE*)(v1 + 12) = 3;
				sub_53B490((int)a1, 1);
			}
		}
		break;
	case 1u:
		v2 = *(_DWORD*)(v1 + 16);
		if (v2 > 0) {
			*(_DWORD*)(v1 + 16) = v2 - 2;
		} else {
			*(_BYTE*)(v1 + 12) = 0;
			a1[34] = *(_DWORD*)&byte_5D4594[2598000];
		}
		sub_4E44F0((int)a1);
		if (*(_DWORD*)(v1 + 4))
			sub_4E44F0(*(_DWORD*)(v1 + 4));
		if ((double)*(int*)(v1 + 16) <= 20.0) {
			v3 = a1[4];
			LOBYTE(v3) = v3 | 0x10;
			a1[4] = v3;
		}
		break;
	case 2u:
		if (a1[4] & 0x1000000 &&
		    (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - a1[34]) > *(int*)&byte_5D4594[2649704]) {
			*(_BYTE*)(v1 + 12) = 1;
			sub_53B490((int)a1, 0);
		}
		break;
	case 3u:
		*(_DWORD*)(v1 + 16) += 2;
		sub_4E44F0((int)a1);
		if (*(_DWORD*)(v1 + 4))
			sub_4E44F0(*(_DWORD*)(v1 + 4));
		if ((double)*(int*)(v1 + 16) >= 20.0) {
			v4 = a1[4];
			LOBYTE(v4) = v4 & 0xEF;
			a1[4] = v4;
		}
		if ((double)*(int*)(v1 + 16) >= 32.0)
			sub_517F90((float2*)a1 + 7, 64.0, sub_53B750, (int)a1);
		if (*(_DWORD*)(v1 + 16) >= 64) {
			*(_DWORD*)(v1 + 16) = 64;
			*(_BYTE*)(v1 + 12) = 2;
			a1[34] = *(_DWORD*)&byte_5D4594[2598000];
		}
		break;
	default:
		return;
	}
}

//----- (0053B750) --------------------------------------------------------
void __cdecl sub_53B750(int a1, int a2) {
	int v2;    // ebx
	int v3;    // edi
	int v4;    // eax
	double v5; // st7
	float v6;  // [esp+0h] [ebp-10h]
	float v7;  // [esp+0h] [ebp-10h]

	if (sub_57B850((float2*)(a2 + 56), (float*)(a2 + 172), (float2*)(a1 + 56))) {
		v2 = *(_DWORD*)(a2 + 748);
		v3 = *(_DWORD*)(v2 + 4);
		if (v3) {
			v6 = *(float*)(a1 + 104) - (double)*(int*)(v2 + 16);
			if (sub_419A10(v6) < 10.0) {
				v4 = *(_DWORD*)(a1 + 172);
				if (v4 == 3) {
					if (*(float*)(v3 + 184) < (double)*(float*)(a1 + 184) ||
					    *(float*)(v3 + 188) < (double)*(float*)(a1 + 188)) {
					LABEL_12:
						*(_DWORD*)(a1 + 16) &= 0xFFEFFFFF;
						sub_4E46F0(a1, 0.0);
						return;
					}
				} else if (v4 == 2) {
					v5 = *(float*)(a1 + 176) + *(float*)(a1 + 176);
					if (v5 > *(float*)(v3 + 184) || v5 > *(float*)(v3 + 188))
						goto LABEL_12;
				}
				sub_4E7010(a1, (float2*)(*(_DWORD*)(v2 + 4) + 56));
				v7 = (double)(int)(*(_DWORD*)(v2 + 16) - 64);
				sub_4E46F0(a1, v7);
				return;
			}
		}
	}
}

//----- (0053B860) --------------------------------------------------------
void __cdecl sub_53B860(int a1) {
	float* v1;  // edx
	double v2;  // st7
	double v3;  // st6
	int v4;     // edx
	__int16 v5; // ax
	bool v6;    // sf
	float v7;   // [esp+8h] [ebp-4h]

	v1 = *(float**)(a1 + 748);
	v2 = *(float*)(*(_DWORD*)v1 + 56) - v1[1];
	v3 = *(float*)(*(_DWORD*)v1 + 60) - v1[2];
	v7 = v3;
	if (v3 * v7 + v2 * v2 <= 160000.0) {
		*(float*)(a1 + 64) = *(float*)(*(_DWORD*)v1 + 56) - v2;
		*(float*)(a1 + 68) = *(float*)(*(_DWORD*)v1 + 60) - v7;
		v4 = *(_DWORD*)v1;
		v5 = *(_WORD*)(v4 + 124) + 128;
		v6 = (__int16)(*(_WORD*)(v4 + 124) - 128) < 0;
		*(_WORD*)(a1 + 126) = v5;
		while (*(_WORD*)(a1 + 126) >= 256)
			*(_WORD*)(a1 + 126) -= 256;
	} else {
		sub_4E5CC0(a1);
	}
}

//----- (0053B8F0) --------------------------------------------------------
void __cdecl sub_53B8F0(int a1) {
	void(__cdecl * v1)(int); // ecx

	if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128)) > **(_DWORD**)(a1 + 748)) {
		v1 = *(void(__cdecl**)(int))(a1 + 724);
		*(_DWORD*)(a1 + 16) |= 0x8000u;
		if (v1)
			v1(a1);
		else
			sub_4E5CC0(a1);
	}
}

//----- (0053B940) --------------------------------------------------------
void __cdecl sub_53B940(int a1) {
	int v1;     // edi
	int* v2;    // esi
	double v3;  // st7
	int v4;     // eax
	int v5;     // eax
	int v6;     // eax
	int v7;     // eax
	int v8;     // eax
	int v9;     // esi
	double v10; // st7
	double v11; // st7
	double v12; // st6
	double v13; // st7
	double v14; // st6
	float v15;  // [esp+4h] [ebp-10h]
	int v16;    // [esp+4h] [ebp-10h]
	float v17;  // [esp+10h] [ebp-4h]
	float v18;  // [esp+18h] [ebp+4h]

	v1 = a1;
	v2 = *(int**)(a1 + 748);
	if (v2[1])
		v3 = sub_419D40(&byte_587000[278124]);
	else
		v3 = sub_419D40(&byte_587000[278148]);
	v15 = v3;
	if (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128) <= (unsigned int)nox_float2int(v15)) {
		if (*v2 && *(_BYTE*)(*v2 + 16) & 0x20)
			*v2 = 0;
		v4 = v2[2];
		if (v4 && *(_BYTE*)(v4 + 16) & 0x20)
			v2[2] = 0;
		v5 = v2[1];
		if (v5) {
			v6 = *(_DWORD*)(v5 + 16);
			if (v6 & 0x20 || (v6 & 0x8000) != 0)
				v2[1] = 0;
		}
		if (!v2[1]) {
			v7 = *(_DWORD*)(a1 + 136);
			if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - v7) > *(int*)&byte_5D4594[2649704] >> 2 ||
			    v7 == *(_DWORD*)(a1 + 128)) {
				v16 = *v2;
				v8 = sub_424A70(v2[3]);
				v2[1] = sub_540610(0, a1, v8, 600.0, 0, v16);
				*(_DWORD*)(a1 + 136) = *(_DWORD*)&byte_5D4594[2598000];
			}
		}
		v9 = v2[1];
		if (v9) {
			v18 = *(float*)(v9 + 56) - *(float*)(a1 + 56);
			v10 = *(float*)(v9 + 60) - *(float*)(v1 + 60);
			v17 = v10;
			v11 = nox_double2float(sqrt(v10 * v17 + v18 * v18) + *(double*)&qword_581450_10176);
			v12 = v18 * *(float*)(v1 + 544);
			*(_DWORD*)(v1 + 112) = 1063675494;
			*(float*)(v1 + 88) = v12 / v11;
			*(float*)(v1 + 92) = v17 * *(float*)(v1 + 544) / v11;
		} else {
			v13 = nox_double2float(
			    sqrt(*(float*)(a1 + 80) * *(float*)(a1 + 80) + *(float*)(a1 + 84) * *(float*)(a1 + 84)) +
			    *(double*)&qword_581450_10176);
			v14 = *(float*)(a1 + 544) * *(float*)(a1 + 80);
			*(_DWORD*)(a1 + 112) = 1063675494;
			*(float*)(a1 + 88) = v14 / v13;
			*(float*)(a1 + 92) = *(float*)(a1 + 544) * *(float*)(a1 + 84) / v13;
		}
	} else {
		sub_522FF0(150, (float2*)(a1 + 56));
		sub_4E71F0(a1);
	}
}

//----- (0053BB00) --------------------------------------------------------
void __cdecl sub_53BB00(int a1) {
	int v1;          // ecx
	int v2;          // esi
	int v3;          // edi
	unsigned int v4; // eax
	int v5;          // edx
	int v6;          // eax
	double v7;       // st7
	double v8;       // st6
	double v9;       // st5
	long double v10; // st7
	long double v11; // st7
	float v12;       // [esp+0h] [ebp-30h]
	float v13;       // [esp+4h] [ebp-2Ch]
	int v14;         // [esp+Ch] [ebp-24h]
	float v15;       // [esp+10h] [ebp-20h]
	float v16;       // [esp+14h] [ebp-1Ch]
	float v17;       // [esp+2Ch] [ebp-4h]
	int v18;         // [esp+34h] [ebp+4h]

	v1 = *(_DWORD*)&byte_5D4594[2598000];
	v2 = a1;
	v3 = *(_DWORD*)(a1 + 748);
	v4 = *(_DWORD*)&byte_5D4594[2649704];
	if (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128) <=
	    (unsigned int)(5 * *(_DWORD*)&byte_5D4594[2649704])) {
		v5 = *(_DWORD*)(v3 + 4);
		if (v5 && *(_BYTE*)(v5 + 16) & 0x20) {
			*(_DWORD*)(v3 + 4) = 0;
			v1 = *(_DWORD*)&byte_5D4594[2598000];
			v4 = *(_DWORD*)&byte_5D4594[2649704];
		}
		if (!*(_DWORD*)(v3 + 4) && v1 - *(_DWORD*)(a1 + 136) > v4 >> 2) {
			*(_DWORD*)&byte_5D4594[2488668] = 0;
			*(_DWORD*)&byte_5D4594[2488672] = 1287568416;
			sub_518170(a1 + 56, 600.0, sub_53BD10, a1);
			*(_DWORD*)(v3 + 4) = *(_DWORD*)&byte_5D4594[2488668];
			*(_DWORD*)(a1 + 136) = *(_DWORD*)&byte_5D4594[2598000];
		}
		v6 = *(_DWORD*)(v3 + 4);
		if (v6) {
			v7 = *(float*)(v6 + 56) - *(float*)(a1 + 56);
			v8 = *(float*)(v6 + 60) - *(float*)(a1 + 60);
			v9 = v7;
			v10 = sqrt(v8 * v8 + v7 * v7) + 0.1;
			*(float*)(a1 + 88) = v9 * *(float*)(a1 + 544) / v10;
			*(float*)(a1 + 92) = v8 * *(float*)(a1 + 544) / v10;
			if (v10 < 10.0) {
				sub_501960(20, a1, 0, 0);
				sub_4E5CC0(a1);
				sub_4E5CC0(*(_DWORD*)(v3 + 4));
			}
		} else {
			v11 = sqrt(*(float*)(a1 + 80) * *(float*)(a1 + 80) + *(float*)(a1 + 84) * *(float*)(a1 + 84)) +
			      0.1;
			*(float*)(a1 + 88) = *(float*)(a1 + 544) * *(float*)(a1 + 80) / v11;
			*(float*)(a1 + 92) = *(float*)(a1 + 544) * *(float*)(a1 + 84) / v11;
		}
		v17 = *(float*)(a1 + 56);
		v18 = *(int*)(a1 + 60);
		v16 = sub_416030(-2.0, 2.0);
		v15 = sub_416030(-2.0, 2.0);
		v14 = nox_common_randomInt_415FA0(15, 30);
		v13 = sub_416030(-4.0, 4.0) + *(float*)&v18;
		v12 = sub_416030(-4.0, 4.0) + v17;
		sub_54FD80(v12, v13, 3, v14, v15, v16, 0.0, v2);
	} else {
		sub_4E5CC0(a1);
	}
}

//----- (0053BD10) --------------------------------------------------------
void __cdecl sub_53BD10(int a1, int a2) {
	double v2; // st7
	double v3; // st6
	double v4; // st5

	if (!(*(_BYTE*)(a1 + 16) & 0x20) && (!(*(_BYTE*)(a1 + 8) & 1) || *(_BYTE*)(a1 + 12) & 2) && a2 != a1 &&
	    (!*(_DWORD*)(a2 + 508) || !sub_4EC4F0(a1, *(_DWORD*)(a2 + 508)))) {
		if (sub_5370E0(a2, a1, 0)) {
			v2 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
			v3 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
			v4 = v3 * v3 + v2 * v2;
			if (v4 < *(float*)&byte_5D4594[2488672]) {
				*(float*)&byte_5D4594[2488672] = v4;
				*(_DWORD*)&byte_5D4594[2488668] = a1;
			}
		}
	}
}

//----- (0053BDA0) --------------------------------------------------------
int __cdecl sub_53BDA0(int a1) {
	int* v1;    // edi
	int v2;     // ecx
	int v3;     // eax
	int v4;     // eax
	int v5;     // eax
	int v6;     // edi
	__int16 v7; // cx
	__int16 v8; // ax
	int result; // eax
	double v10; // st7

	v1 = *(int**)(a1 + 748);
	v2 = *v1;
	if (*(_BYTE*)(*v1 + 16) & 0x20 || *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128) >
					      (unsigned int)(3 * *(_DWORD*)&byte_5D4594[2649704])) {
		return (*(int(__cdecl**)(int, _DWORD, _DWORD))(a1 + 696))(a1, 0, 0);
	}
	v3 = v1[1];
	if (v3) {
		v4 = *(_DWORD*)(v3 + 16);
		if (v4 & 0x20 || (v4 & 0x8000) != 0)
			v1[1] = 0;
	}
	if (!v1[1] && !(byte_5D4594[2598000] & 7)) {
		v5 = sub_540610(0, a1, 32, 600.0, 0, v2);
		v1[1] = v5;
		if (v5 == *(_DWORD*)(a1 + 508))
			v1[1] = 0;
	}
	v6 = v1[1];
	if (v6) {
		v7 = *(_WORD*)(a1 + 126);
		if ((*(float*)(v6 + 60) - *(float*)(a1 + 60)) * *(float*)&byte_587000[8 * v7 + 194136] -
			(*(float*)(v6 + 56) - *(float*)(a1 + 56)) * *(float*)&byte_587000[8 * v7 + 194140] >=
		    0.0) {
			*(_WORD*)(a1 + 126) = v7 + 42;
			if ((__int16)(v7 + 42) >= 256) {
				do
					*(_WORD*)(a1 + 126) -= 256;
				while (*(_WORD*)(a1 + 126) >= 256);
			}
		} else {
			v8 = v7 - 42;
			*(_WORD*)(a1 + 126) = v7 - 42;
			if ((__int16)(v7 - 42) < 0) {
				do
					v8 += 256;
				while (v8 < 0);
				*(_WORD*)(a1 + 126) = v8;
			}
		}
	}
	result = 8 * *(__int16*)(a1 + 126);
	*(float*)(a1 + 88) = *(float*)&byte_587000[result + 194136] * *(float*)(a1 + 544);
	v10 = *(float*)&byte_587000[result + 194140] * *(float*)(a1 + 544);
	*(_DWORD*)(a1 + 112) = 1061997773;
	*(float*)(a1 + 92) = v10;
	return result;
}

//----- (0053BEF0) --------------------------------------------------------
int __cdecl sub_53BEF0(int a1) {
	unsigned __int8* v1; // esi
	unsigned __int8 v2;  // al
	unsigned __int8 v3;  // al
	int result;          // eax
	int v5;              // eax
	_BYTE* v6;           // eax
	float4 a1a;          // [esp+Ch] [ebp-10h]

	v1 = *(unsigned __int8**)(a1 + 748);
	if (*v1) {
		if (*v1 <= 2u) {
			v2 = v1[9];
			if (v2 == v1[8]) {
				++v1[20];
				sub_4E44F0(a1);
				if (v1[20] == 9) {
					v3 = v1[8];
					v1[20] = 1;
					v1[8] = v3 + 1;
				}
				v1[9] = 0;
			} else {
				v1[9] = v2 + 1;
			}
		}
	} else {
		if (v1[20])
			sub_4E44F0(a1);
		v1[20] = 0;
	}
	result = *v1;
	if (*v1) {
		v5 = result - 1;
		if (v5) {
			result = v5 - 1;
			if (!result && v1[8] >= 4u) {
				v1[20] = 0;
				*v1 = 0;
				*((_DWORD*)v1 + 1) = 0;
				return result;
			}
		} else {
			result = v1[8];
			if ((_BYTE)result) {
				if ((_BYTE)result == 4) {
					*v1 = 0;
					*((_DWORD*)v1 + 1) = 0;
					return result;
				}
			} else if (v1[20] == 8) {
				result = *((_DWORD*)v1 + 3);
				if (result) {
					a1a.field_0 = *(float*)(a1 + 56) - *(float*)(a1 + 176);
					a1a.field_4 = *(float*)(a1 + 60) - *(float*)(a1 + 176);
					a1a.field_8 = *(float*)(a1 + 56) + *(float*)(a1 + 176);
					a1a.field_C = *(float*)(a1 + 60) + *(float*)(a1 + 176);
					sub_517C10(&a1a, sub_53C060, result + 56);
					*((_DWORD*)v1 + 1) = 0;
					return result;
				}
			}
		}
	} else if (*((_DWORD*)v1 + 1)) {
		result = *((_DWORD*)v1 + 3);
		if (result) {
			if (*(_DWORD*)(a1 + 16) & 0x1000000) {
				v6 = *(_BYTE**)(result + 748);
				*v1 = 1;
				v1[8] = 0;
				v1[9] = 0;
				*(_DWORD*)(a1 + 136) = *(_DWORD*)&byte_5D4594[2598000];
				*v6 = 2;
				v6[8] = 0;
				v6[9] = 0;
				result = *(_DWORD*)&byte_5D4594[2598000];
				*(_DWORD*)(*((_DWORD*)v1 + 3) + 136) = *(_DWORD*)&byte_5D4594[2598000];
			}
		}
	}
	*((_DWORD*)v1 + 1) = 0;
	return result;
}

//----- (0053C060) --------------------------------------------------------
void __cdecl sub_53C060(float* a1, int a2) {
	if (!((_DWORD)a1[2] & 0x420000)) {
		sub_522FF0(137, (float2*)a1 + 7);
		sub_501960(147, (int)a1, 0, 0);
		sub_4E7190(a1, (float*)a2);
		sub_522FF0(137, (float2*)a1 + 7);
		sub_501960(147, (int)a1, 0, 0);
	}
}

//----- (0053C0C0) --------------------------------------------------------
int __cdecl sub_53C0C0(int a1) {
	int result; // eax
	int v2;     // esi
	int v3;     // ecx
	float4 a1a; // [esp+8h] [ebp-10h]

	result = a1;
	v2 = *(_DWORD*)(a1 + 748);
	if (*(_DWORD*)(v2 + 4)) {
		v3 = *(_DWORD*)(v2 + 12);
		if (v3) {
			if (*(_DWORD*)(a1 + 16) & 0x1000000) {
				a1a.field_0 = *(float*)(a1 + 56) - *(float*)(a1 + 176);
				a1a.field_4 = *(float*)(a1 + 60) - *(float*)(a1 + 176);
				a1a.field_8 = *(float*)(a1 + 176) + *(float*)(a1 + 56);
				a1a.field_C = *(float*)(a1 + 60) + *(float*)(a1 + 176);
				sub_517C10(&a1a, sub_53C140, v3 + 56);
			}
		}
	}
	*(_DWORD*)(v2 + 4) = 0;
	return result;
}

//----- (0053C140) --------------------------------------------------------
void __cdecl sub_53C140(float* a1, int a2) {
	if (!((_DWORD)a1[2] & 0x420000))
		sub_4E7190(a1, (float*)a2);
}

//----- (0053C160) --------------------------------------------------------
void __cdecl sub_53C160(int a3) {
	double v1; // st7
	float v2;  // eax
	float v3;  // edx
	double v4; // st7
	float v5;  // ecx
	double v6; // st7
	float v7;  // eax
	int2 a2;   // [esp+4h] [ebp-18h]
	float4 a1; // [esp+Ch] [ebp-10h]

	if (*(_DWORD*)(a3 + 16) & 0x1000000) {
		sub_509E20(*(__int16*)(a3 + 124), &a2);
		if (a2.field_0 >= 0) {
			if (a2.field_4 < 0) {
				v4 = *(float*)(a3 + 60) - 400.0;
				v5 = *(float*)(a3 + 60);
				a1.field_0 = *(float*)(a3 + 56);
				a1.field_C = v5;
				a1.field_4 = v4;
				a1.field_8 = *(float*)(a3 + 56) + 400.0;
				goto LABEL_10;
			}
			v6 = *(float*)(a3 + 56) + 400.0;
			v7 = *(float*)(a3 + 60);
			a1.field_0 = *(float*)(a3 + 56);
			a1.field_4 = v7;
			a1.field_8 = v6;
		} else {
			a1.field_0 = *(float*)(a3 + 56) - 400.0;
			if (a2.field_4 < 0) {
				v1 = *(float*)(a3 + 60) - 400.0;
				v2 = *(float*)(a3 + 60);
				a1.field_8 = *(float*)(a3 + 56);
				a1.field_C = v2;
				a1.field_4 = v1;
			LABEL_10:
				sub_517ED0(&a1, sub_53C240, a3);
				return;
			}
			v3 = *(float*)(a3 + 56);
			a1.field_4 = *(float*)(a3 + 60);
			a1.field_8 = v3;
		}
		a1.field_C = *(float*)(a3 + 60) + 400.0;
		goto LABEL_10;
	}
}

//----- (0053C240) --------------------------------------------------------
void __cdecl sub_53C240(float* a1, int arg4) {
	float* v2;      // esi
	int v3;         // edi
	double v4;      // st7
	long double v5; // st7
	double v6;      // st7
	double v7;      // st7
	double v8;      // st7
	double v9;      // st7
	float v10;      // [esp+8h] [ebp-10h]
	float v11;      // [esp+Ch] [ebp-Ch]
	int2 a2;        // [esp+10h] [ebp-8h]
	float v13;      // [esp+1Ch] [ebp+4h]
	float v14;      // [esp+1Ch] [ebp+4h]
	float v15;      // [esp+20h] [ebp+8h]
	float v16;      // [esp+20h] [ebp+8h]

	v2 = a1;
	if (!((_BYTE)a1[4] & 0x20) && !((_DWORD)a1[2] & 0x400000)) {
		v3 = arg4;
		v15 = a1[14] - *(float*)(arg4 + 56);
		v4 = a1[15] - *(float*)(v3 + 60);
		v13 = v4;
		v5 = sqrt(v4 * v13 + v15 * v15) + 0.1;
		v11 = v5;
		if (v5 < 400.0) {
			sub_509E20(*(__int16*)(v3 + 124), &a2);
			v6 = v15;
			if (v15 >= 0.0)
				v10 = v15;
			else
				v10 = -v6;
			if (v13 >= 0.0)
				v16 = v13;
			else
				v16 = -v13;
			switch (a2.field_4 + a2.field_0 + 2 * a2.field_4 + 4) {
			case 0:
				if (v6 < 0.0)
					goto LABEL_12;
				break;
			case 1:
				if (v13 < 0.0)
					goto LABEL_29;
				break;
			case 2:
				if (v6 > 0.0) {
				LABEL_12:
					if (v13 < 0.0)
						goto LABEL_25;
				}
				break;
			case 3:
				if (v6 < 0.0)
					goto LABEL_21;
				break;
			case 5:
				if (v6 > 0.0) {
				LABEL_21:
					if (v16 / v10 <= 0.26789999)
						goto LABEL_35;
				}
				break;
			case 6:
				if (v6 < 0.0 && v13 > 0.0) {
				LABEL_25:
					v7 = v16 / v10;
					if (v7 >= 0.57730001 && v7 <= 0.1732)
						goto LABEL_35;
				}
				break;
			case 7:
				if (v13 > 0.0) {
				LABEL_29:
					if (v16 / v10 <= 0.3732)
						goto LABEL_35;
				}
				break;
			case 8:
				if (v6 > 0.0 && v13 > 0.0) {
					v8 = v16 / v10;
					if (v8 >= 0.57730001 && v8 <= 0.1732)
						goto LABEL_35;
				}
				break;
			default:
			LABEL_35:
				if (sub_5370E0(v3, (int)v2, 0)) {
					v14 = (400.0 - v11) * (400.0 - v11) * (400.0 - v11) * 0.0000005;
					v9 = v14 / sub_4E4A70((int)v2);
					v2[22] =
					    v9 * *(float*)&byte_587000[8 * *(__int16*)(v3 + 124) + 194136] + v2[22];
					v2[23] =
					    v9 * *(float*)&byte_587000[8 * *(__int16*)(v3 + 124) + 194140] + v2[23];
				}
				break;
			}
		}
	}
}

//----- (0053C520) --------------------------------------------------------
int __cdecl sub_53C520(int a1, int a2) {
	int v2; // ecx
	int v3; // eax
	int v4; // eax
	int v5; // edx

	v2 = *(_DWORD*)(a1 + 736);
	if (!v2)
		return 0;
	v3 = *(_DWORD*)(v2 + 112);
	if (v3 >= 100)
		return 0;
	v4 = a2 + v3;
	*(_DWORD*)(v2 + 112) = v4 < 100 ? v4 : 100;
	v5 = *(_DWORD*)(v2 + 112) * *(unsigned __int8*)(v2 + 109) / 100;
	if (v5 == *(unsigned __int8*)(v2 + 108))
		return 0;
	*(_BYTE*)(v2 + 108) = v5;
	return 1;
}

//----- (0053C580) --------------------------------------------------------
signed int __cdecl sub_53C580(int a1) {
	int v1;               // edi
	signed int* v2;       // esi
	int v3;               // ebp
	int v4;               // eax
	int v5;               // esi
	double v6;            // st7
	double v7;            // st6
	int v8;               // ebp
	_DWORD* v9;           // eax
	int v10;              // ecx
	int v11;              // ebx
	__int16 v12;          // bx
	char v13;             // al
	__int16 v14;          // ax
	int v15;              // eax
	unsigned __int16 v16; // ax
	int v17;              // edx
	signed int result;    // eax
	float v19;            // [esp+0h] [ebp-20h]
	float v20;            // [esp+4h] [ebp-1Ch]
	int v21;              // [esp+14h] [ebp-Ch]
	int v22;              // [esp+18h] [ebp-8h]
	signed int v23;       // [esp+1Ch] [ebp-4h]
	signed int* v24;      // [esp+24h] [ebp+4h]

	v1 = a1;
	v23 = 1;
	v2 = *(signed int**)(a1 + 748);
	v24 = *(signed int**)(a1 + 748);
	v3 = sub_4DA7C0();
	v21 = v3;
	if (!v3)
		goto LABEL_50;
	while (1) {
		v4 = *(_DWORD*)(v3 + 16);
		if ((v4 & 0x8000) != 0)
			goto LABEL_47;
		v5 = *(_DWORD*)(v3 + 748);
		if (sub_419130(v1 + 48)) {
			if (!sub_419150(v1 + 48, v3 + 48))
				goto LABEL_47;
		}
		v6 = *(float*)(v1 + 56) - *(float*)(v3 + 56);
		v7 = *(float*)(v1 + 60) - *(float*)(v3 + 60);
		v22 = 0;
		if (v7 * v7 + v6 * v6 >= 2500.0 || !sub_537110(v1, v3))
			goto LABEL_47;
		v23 = 0;
		if (*v24 >= 1) {
			v8 = sub_53C940(*(_DWORD**)(v5 + 104));
			if (!nox_common_gameFlags_check_40A5C0(0x2000) || nox_common_gameFlags_check_40A5C0(4096)) {
				if (!v8) {
				LABEL_24:
					v3 = v21;
					goto LABEL_25;
				}
			} else {
				v8 = 1;
			}
			v9 = *(_DWORD**)(v5 + 104);
			if (v9) {
				v10 = v9[2];
				if (v10 & 0x1000) {
					if (v9[3] & 0x47F0000) {
						v11 = v9[184];
						if (*(int*)(v11 + 112) < 100) {
							if (nox_common_gameFlags_check_40A5C0(4096)) {
								if (!(*(_DWORD*)&byte_5D4594[2598000] %
								      (*(_DWORD*)&byte_5D4594[2649704] >> 1)))
									sub_501960(230, v1, 0, 0);
							} else {
								v22 = 1;
								--*v24;
							}
							if (sub_53C520(*(_DWORD*)(v5 + 104), v8))
								sub_4D82B0(
								    *(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064),
								    *(_DWORD**)(v5 + 104), *(_BYTE*)(v11 + 108),
								    *(_BYTE*)(v11 + 109));
						}
					}
				}
			}
			goto LABEL_24;
		}
	LABEL_25:
		if ((int)*v24 < 1 || *(_WORD*)(v5 + 4) >= *(_WORD*)(v5 + 8) || (int)*v24 <= 0)
			goto LABEL_42;
		v12 = 1;
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			v13 = *(_BYTE*)(*(_DWORD*)(v5 + 276) + 2251);
			if (v13) {
				if (v13 == 1) {
					v14 = nox_float2int(*(float*)&dword_587000_312820);
				} else {
					if (v13 != 2)
						goto LABEL_36;
					v14 = nox_float2int(*(float*)&dword_587000_312804);
				}
			} else {
				v14 = nox_float2int(*(float*)&dword_587000_312788);
			}
			v12 = v14;
		}
	LABEL_36:
		v15 = *(_DWORD*)(v5 + 276);
		*(_WORD*)(v5 + 4) += v12;
		sub_56F9E0(*(_DWORD*)(v15 + 4596), v12);
		v16 = *(_WORD*)(v5 + 8);
		if (*(_WORD*)(v5 + 4) > v16) {
			v17 = *(_DWORD*)(v5 + 276);
			*(_WORD*)(v5 + 4) = v16;
			sub_56F870(*(_DWORD*)(v17 + 4596), v16);
		}
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			if (!(*(_DWORD*)&byte_5D4594[2598000] % (*(_DWORD*)&byte_5D4594[2649704] >> 1)))
				sub_501960(230, v1, 0, 0);
		LABEL_42:
			if (!v22)
				goto LABEL_47;
			goto LABEL_43;
		}
		--*v24;
	LABEL_43:
		if (!(*v24 % 8)) {
			v19 = (double)(80 * *v24 / 50);
			nullsub_35(v1, LODWORD(v19));
			sub_4E44F0(v1);
		}
		if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) >
		    *(int*)&byte_5D4594[2649704] >> 1) {
			sub_501960(230, v1, 0, 0);
			*(_DWORD*)(v1 + 136) = *(_DWORD*)&byte_5D4594[2598000];
		}
	LABEL_47:
		v21 = sub_4DA7F0(v3);
		if (!v21)
			break;
		v3 = v21;
	}
	result = v23;
	if (v23) {
		v2 = v24;
	LABEL_50:
		result = *(_DWORD*)&byte_5D4594[2598000] / (*(_DWORD*)&byte_5D4594[2649704] >> 1);
		if (!(*(_DWORD*)&byte_5D4594[2598000] % (*(_DWORD*)&byte_5D4594[2649704] >> 1))) {
			result = *v2;
			if ((int)*v2 < 50) {
				if (!(result % 8)) {
					v20 = (double)(80 * result / 50);
					nullsub_35(v1, LODWORD(v20));
					result = sub_4E44F0(v1);
				}
				++*v2;
			}
		}
	}
	return result;
}
// 4E4770: using guessed type void __cdecl nullsub_35(_DWORD, _DWORD);

//----- (0053C940) --------------------------------------------------------
int __cdecl sub_53C940(_DWORD* a1) {
	int v1;     // ecx
	int result; // eax
	int v3;     // edx
	int* i;     // ecx
	int v5;     // eax
	float v6;   // [esp+0h] [ebp-4h]

	if (!a1)
		return 0;
	v1 = a1[2];
	if (v1 & 0x1000 && a1[3] & 0x4000000) {
		v6 = sub_419D40(&byte_587000[278412]);
		result = nox_float2int(v6);
	} else {
		v3 = 2;
		for (i = (int*)(a1[173] + 8);; ++i) {
			v5 = *i;
			if (*i) {
				if (*(int (**)())(v5 + 40) == nullsub_36)
					break;
			}
			if (++v3 >= 4)
				return 0;
		}
		result = *(_DWORD*)(v5 + 48);
	}
	return result;
}
// 4E09D0: using guessed type void nullsub_36();

//----- (0053C9A0) --------------------------------------------------------
void __cdecl sub_53C9A0(float* a1) {
	float* v1;   // ebx
	int v2;      // ecx
	int v3;      // edx
	float* v4;   // esi
	float v5;    // ecx
	int v6;      // ebp
	int v7;      // edi
	int v8;      // eax
	_DWORD* v9;  // eax
	_DWORD* v10; // edi
	int v11;     // eax
	float4 v12;  // [esp+4h] [ebp-10h]
	float v13;   // [esp+18h] [ebp+4h]

	v1 = a1;
	v2 = *((_DWORD*)a1 + 34);
	v3 = *((_DWORD*)a1 + 32);
	if (v2 == v3) {
		*((_DWORD*)a1 + 34) = *(_DWORD*)&byte_5D4594[2598000] + nox_common_randomInt_415FA0(1, 5);
	} else if (v2 == *(_DWORD*)&byte_5D4594[2598000]) {
		if (!*(_DWORD*)&byte_5D4594[2488684]) {
			*(_DWORD*)&byte_5D4594[2488684] = sub_4E3AA0((CHAR*)&byte_587000[278488]);
			*(_DWORD*)&byte_5D4594[2488688] = sub_4E3AA0((CHAR*)&byte_587000[278500]);
		}
		v4 = a1 + 14;
		sub_4E25B0((int)(a1 + 14), 100.0, 30.0, 30, 7, (int)a1, 0);
		sub_52E040((int)(a1 + 14), 100.0, 1106247680, 60.0, (int)a1, 0, 0);
		v5 = a1[15];
		v12.field_0 = a1[14];
		v12.field_4 = v5;
		v6 = 4;
		do {
			v7 = nox_common_randomInt_415FA0(0, 1);
			v13 = sub_416030(0.0, 15.0) + 10.0;
			v8 = nox_common_randomInt_415FA0(0, 255);
			v12.field_8 = v13 * *(float*)&byte_587000[8 * v8 + 194136] + *v4;
			v12.field_C = v13 * *(float*)&byte_587000[8 * v8 + 194140] + v1[15];
			if (sub_535250(&v12, 0, 0, 1)) {
				v9 = sub_4E3450(*(_DWORD*)&byte_5D4594[4 * v7 + 2488684]);
				v10 = v9;
				if (v9) {
					sub_4DAA50((int)v9, 0, v12.field_8, v12.field_C);
					v11 = nox_common_randomInt_415FA0(5, 20);
					sub_511660(v10, *(_DWORD*)&byte_5D4594[2649704] * v11);
				}
			}
			--v6;
		} while (v6);
	} else if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - v3) >= *(int*)&byte_5D4594[2649704]) {
		sub_4E5CC0((int)a1);
	}
}

//----- (0053CB60) --------------------------------------------------------
void __cdecl sub_53CB60(int a1) {
	if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128)) >= *(int*)&byte_5D4594[2649704])
		sub_4E5CC0(a1);
}

//----- (0053CB90) --------------------------------------------------------
void __cdecl sub_53CB90(int a1) {
	unsigned int v1; // eax
	float4 a1a;      // [esp+4h] [ebp-10h]

	v1 = *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128);
	if (v1 == 8) {
		*(_DWORD*)&byte_5D4594[2488664] = 0;
		a1a.field_0 = *(float*)(a1 + 56) - 40.0;
		a1a.field_4 = *(float*)(a1 + 60) - 40.0;
		a1a.field_8 = *(float*)(a1 + 56) + 40.0;
		a1a.field_C = *(float*)(a1 + 60) + 40.0;
		sub_517C10(&a1a, sub_53CC30, a1 + 56);
		if (*(_DWORD*)&byte_5D4594[2488664])
			sub_501960(283, a1, 0, 0);
	} else if (v1 >= 0x1E) {
		sub_4E5CC0(a1);
	}
}

//----- (0053CC30) --------------------------------------------------------
void __cdecl sub_53CC30(float* a1, int a2) {
	int v2;    // eax
	double v3; // st7
	double v4; // st6

	v2 = *((_DWORD*)a1 + 2);
	if (v2 & 0x2000) {
		v3 = *(float*)a2 - a1[14];
		v4 = *(float*)(a2 + 4) - a1[15];
		if (sqrt(v4 * v4 + v3 * v3) - a1[44] <= 40.0) {
			sub_4E5CC0((int)a1);
			*(_DWORD*)&byte_5D4594[2488664] = 1;
		}
	}
}

//----- (0053CC90) --------------------------------------------------------
void __cdecl sub_53CC90(int a1) {
	if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128)) > 2)
		sub_4E5CC0(a1);
}

//----- (0053CCB0) --------------------------------------------------------
void __cdecl sub_53CCB0(int a1) {
	int v1; // edx
	int v2; // esi

	v1 = *(_DWORD*)(a1 + 136);
	v2 = *(_DWORD*)(a1 + 128);
	if (v1 == v2) {
		*(_DWORD*)(a1 + 136) = *(_DWORD*)&byte_5D4594[2598000] + 3;
	} else if (v1 == *(_DWORD*)&byte_5D4594[2598000]) {
		sub_4E25B0(a1 + 56, 15.0, 15.0, 1, 1, a1, 0);
	} else if (*(_DWORD*)&byte_5D4594[2598000] - v2 >= (unsigned int)(2 * *(_DWORD*)&byte_5D4594[2649704])) {
		sub_4E5CC0(a1);
	}
}

//----- (0053CD20) --------------------------------------------------------
void __cdecl sub_53CD20(int a1) {
	_DWORD* v1;      // ebx
	int v2;          // eax
	unsigned int v3; // edx
	unsigned int v4; // eax
	int v5;          // ecx
	int v6;          // eax
	int v7;          // eax
	int v8;          // eax
	int v9;          // eax
	int v10;         // eax
	float* v11;      // edi
	int v12;         // eax
	float v13;       // edx
	int v14;         // eax
	double v15;      // st7
	float v16;       // edx
	float v17;       // ecx
	float v18;       // edx
	int v19;         // eax
	double v20;      // st7
	float v21;       // [esp+0h] [ebp-28h]
	float2 a2;       // [esp+10h] [ebp-18h]
	float4 a1a;      // [esp+18h] [ebp-10h]

	v1 = *(_DWORD**)(a1 + 748);
	if (*(_DWORD*)&byte_5D4594[2488696]) {
		v3 = *(_DWORD*)&byte_5D4594[2649704];
	} else {
		v21 = sub_419D40(&byte_587000[278704]);
		v2 = nox_float2int(v21);
		v3 = *(_DWORD*)&byte_5D4594[2649704];
		*(_DWORD*)&byte_5D4594[2488696] = *(_DWORD*)&byte_5D4594[2649704] * v2;
	}
	v4 = v1[5];
	v5 = *(_DWORD*)&byte_5D4594[2598000];
	if (*(_DWORD*)&byte_5D4594[2598000] > v4 && v4) {
		sub_4E5CC0(a1);
		return;
	}
	v6 = v1[1];
	if (v6) {
		v7 = *(_DWORD*)(v6 + 16);
		if (v7 & 0x20 || (v7 & 0x8000) != 0) {
			v1[1] = 0;
			v3 = *(_DWORD*)&byte_5D4594[2649704];
			v5 = *(_DWORD*)&byte_5D4594[2598000];
		}
	}
	if (*(_DWORD*)(a1 + 16) & 0x1000000) {
		if (v5 - *(_DWORD*)(a1 + 136) > v3 >> 2) {
			v8 = sub_533570(a1);
			v1[1] = v8;
			if (v8 == *(_DWORD*)(a1 + 508))
				v1[1] = 0;
			*(_DWORD*)(a1 + 136) = *(_DWORD*)&byte_5D4594[2598000];
		}
	} else {
		v1[1] = 0;
	}
	v9 = *(_DWORD*)(a1 + 508);
	if (v9 && (*(_BYTE*)(v9 + 8) & 4) == 4 && (*(_BYTE*)(v9 + 16) & 2) == 2)
		v1[1] = 0;
	v10 = v1[1];
	if (!v10) {
		v11 = (float*)(a1 + 56);
		sub_518170(a1 + 56, *(float*)&byte_587000[277804], sub_53D010, a1);
		v12 = *(_DWORD*)(a1 + 508);
		if (v12) {
			v13 = *(float*)(a1 + 60);
			a1a.field_0 = *v11;
			a1a.field_4 = v13;
			a1a.field_8 = *(float*)(v12 + 56);
			a1a.field_C = *(float*)(v12 + 60);
			if (!sub_535250(&a1a, 0, 0, 9))
				goto LABEL_29;
			v14 = *(_DWORD*)(a1 + 508);
			a2.field_0 = *(float*)(v14 + 56) - *v11;
			v15 = *(float*)(v14 + 60);
		} else {
			v16 = *v11;
			v17 = *(float*)(a1 + 156);
			a1a.field_4 = *(float*)(a1 + 60);
			a1a.field_0 = v16;
			v18 = *(float*)(a1 + 160);
			a1a.field_8 = v17;
			a1a.field_C = v18;
			if (!sub_535250(&a1a, 0, 0, 9))
				goto LABEL_29;
			a2.field_0 = *(float*)(a1 + 156) - *v11;
			v15 = *(float*)(a1 + 160);
		}
		a2.field_4 = v15 - *(float*)(a1 + 60);
		sub_53CF90(a1, &a2, 25);
		goto LABEL_29;
	}
	a2.field_0 = *(float*)(v10 + 56) - *(float*)(a1 + 56);
	a2.field_4 = *(float*)(v1[1] + 60) - *(float*)(a1 + 60);
	sub_53CF90(a1, &a2, 32);
LABEL_29:
	v19 = 8 * *(__int16*)(a1 + 126);
	*(float*)(a1 + 88) = *(float*)&byte_587000[v19 + 194136] * *(float*)(a1 + 544);
	v20 = *(float*)&byte_587000[v19 + 194140] * *(float*)(a1 + 544);
	*(_DWORD*)(a1 + 112) = 1063675494;
	*(float*)(a1 + 92) = v20;
	if (byte_5D4594[2598000] & 8 && *(_DWORD*)(a1 + 508)) {
		if (sub_537110(a1, *(_DWORD*)(a1 + 508)) == 1)
			v1[6] = *(_DWORD*)&byte_5D4594[2598000];
		if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - v1[6]) > *(int*)&byte_5D4594[2488696]) {
			sub_4FD050((_DWORD*)a1, *(_DWORD*)(a1 + 508));
			v1[6] = *(_DWORD*)&byte_5D4594[2598000];
		}
	}
}

//----- (0053CF90) --------------------------------------------------------
__int16 __cdecl sub_53CF90(int a1, float2* a2, __int16 a3) {
	__int16 v3;     // dx
	__int16 result; // ax

	v3 = *(_WORD*)(a1 + 126);
	if (*(float*)&byte_587000[8 * v3 + 194136] * a2->field_4 -
		*(float*)&byte_587000[8 * v3 + 194140] * a2->field_0 >=
	    0.0) {
		result = v3 + a3;
		*(_WORD*)(a1 + 126) = v3 + a3;
		if ((__int16)(v3 + a3) >= 256) {
			result = -256;
			do
				*(_WORD*)(a1 + 126) -= 256;
			while (*(_WORD*)(a1 + 126) >= 256);
		}
	} else {
		result = v3 - a3;
		*(_WORD*)(a1 + 126) = v3 - a3;
		if ((__int16)(v3 - a3) < 0) {
			do
				result += 256;
			while (result < 0);
			*(_WORD*)(a1 + 126) = result;
		}
	}
	return result;
}

//----- (0053D010) --------------------------------------------------------
__int16 __cdecl sub_53D010(int a1, int a2) {
	int v2;     // eax
	float2 a2a; // [esp+0h] [ebp-8h]

	v2 = *(_DWORD*)&byte_5D4594[2488692];
	if (!*(_DWORD*)&byte_5D4594[2488692]) {
		v2 = sub_4E3AA0((CHAR*)&byte_587000[278724]);
		*(_DWORD*)&byte_5D4594[2488692] = v2;
	}
	if (*(unsigned __int16*)(a1 + 4) == v2) {
		LOWORD(v2) = a2;
		if (a1 != a2 && *(_DWORD*)(a2 + 508) == *(_DWORD*)(a1 + 508)) {
			a2a.field_0 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
			a2a.field_4 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
			LOWORD(v2) = sub_53CF90(a2, &a2a, 16);
		}
	}
	return v2;
}

//----- (0053D080) --------------------------------------------------------
void __cdecl sub_53D080(int a1) {
	int v1;   // esi
	int v2;   // ebx
	int v3;   // eax
	float v4; // [esp+0h] [ebp-1Ch]
	float v5; // [esp+8h] [ebp-14h]
	float v6; // [esp+18h] [ebp-4h]
	float v7; // [esp+20h] [ebp+4h]

	v1 = a1;
	v2 = *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128);
	if (*(_DWORD*)&byte_5D4594[2598000] % (*(_DWORD*)&byte_5D4594[2649704] / 3u)) {
		*(_DWORD*)&byte_5D4594[2488700] = 0;
		v4 = sub_419D40(&byte_587000[278732]);
		sub_518170(a1 + 56, v4, sub_53D170, a1);
		if (*(_DWORD*)&byte_5D4594[2488700] == 1) {
			sub_537AF0((int*)(a1 + 56), 1);
			sub_4E5CC0(a1);
		}
	}
	if (v2 > 10) {
		v6 = sub_419D40(&byte_587000[278756]);
		v7 = sub_419D40(&byte_587000[278776]);
		v5 = sub_419D40(&byte_587000[278796]);
		v3 = nox_float2int(v5);
		sub_4E25B0(v1 + 56, v6, v7, v3, 2, v1, 0);
	}
	if (v2 > 4 * *(_DWORD*)&byte_5D4594[2649704])
		sub_4E5CC0(v1);
}

//----- (0053D170) --------------------------------------------------------
void __cdecl sub_53D170(int a1, int a2) {
	int v2;   // eax
	int v3;   // eax
	int v4;   // eax
	float v5; // edx
	float v6; // [esp-14h] [ebp-24h]
	int4 a1a; // [esp+0h] [ebp-10h]

	v2 = *(_DWORD*)&byte_5D4594[2488704];
	if (!*(_DWORD*)&byte_5D4594[2488704]) {
		v2 = sub_4E3AA0((CHAR*)&byte_587000[278820]);
		*(_DWORD*)&byte_5D4594[2488704] = v2;
	}
	if (a1 != a2 && *(unsigned __int16*)(a1 + 4) == v2 && sub_537110(a2, a1)) {
		*(_DWORD*)&byte_5D4594[2488700] = 1;
		if (!(*(_BYTE*)(a1 + 16) & 0x20)) {
			a1a.field_0 = nox_float2int(*(float*)(a2 + 56));
			v3 = nox_float2int(*(float*)(a2 + 60));
			v6 = *(float*)(a1 + 56);
			a1a.field_4 = v3;
			v4 = nox_float2int(v6);
			v5 = *(float*)(a1 + 60);
			a1a.field_8 = v4;
			a1a.field_C = nox_float2int(v5);
			sub_523790(&a1a, 10);
			sub_537AF0((int*)(a1 + 56), 1);
			sub_4E5CC0(a1);
		}
	}
}

//----- (0053D220) --------------------------------------------------------
void __cdecl sub_53D220(int a1) {
	int v1; // esi

	v1 = *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128);
	if (v1 > 10)
		sub_4E25B0(a1 + 56, 25.0, 0.0, 20, 2, a1, 0);
	if (v1 > 2 * *(_DWORD*)&byte_5D4594[2649704])
		sub_4E5CC0(a1);
}

//----- (0053D270) --------------------------------------------------------
void __cdecl sub_53D270(int a1) {
	int v1;    // eax
	int v2;    // ecx
	float2 v3; // [esp+4h] [ebp-8h]

	v1 = *(_DWORD*)(a1 + 508);
	if (v1) {
		if (*(_BYTE*)(v1 + 8) & 4) {
			v2 = *(_DWORD*)(v1 + 748);
			if (*(_BYTE*)(v1 + 16) & 0x20 || *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128) >
							     (unsigned int)(300 * *(_DWORD*)&byte_5D4594[2649704])) {
				sub_4E5CC0(a1);
				sub_4FF5B0(*(_DWORD*)(a1 + 508), 1);
			} else {
				v3.field_0 = (double)*(int*)(*(_DWORD*)(v2 + 276) + 2284);
				v3.field_4 = (double)*(int*)(*(_DWORD*)(v2 + 276) + 2288);
				if (sub_517590(v3.field_0, v3.field_4))
					sub_4E7010(a1, &v3);
			}
		}
	} else {
		sub_4E5CC0(a1);
	}
}

//----- (0053D330) --------------------------------------------------------
void __cdecl sub_53D330(int a1) {
	int v1;    // eax
	int v2;    // ecx
	int v3;    // eax
	int v4;    // [esp-Ch] [ebp-20h]
	float4 v5; // [esp+4h] [ebp-10h]

	v1 = *(_DWORD*)(a1 + 508);
	v2 = *(_DWORD*)(v1 + 748);
	if (*(_DWORD*)(v1 + 16) & 0x8020 || *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128) >
						(unsigned int)(20 * *(_DWORD*)&byte_5D4594[2649704])) {
		v4 = *(_DWORD*)(a1 + 508);
		v3 = sub_424800(127, 2);
		sub_501960(v3, v4, 0, 0);
		sub_4E5CC0(a1);
		sub_4FF5B0(*(_DWORD*)(a1 + 508), 24);
	} else {
		v5.field_8 = (double)*(int*)(*(_DWORD*)(v2 + 276) + 2284);
		v5.field_C = (double)*(int*)(*(_DWORD*)(v2 + 276) + 2288);
		v5.field_0 = *(float*)(v1 + 56);
		v5.field_4 = *(float*)(v1 + 60);
		if (sub_535250(&v5, 0, 0, 5))
			sub_4E7010(a1, (float2*)&v5.field_8);
	}
}

//----- (0053D400) --------------------------------------------------------
void __cdecl sub_53D400(int a1) {
	double v1; // st7
	double v2; // st7
	double v3; // st7
	float2 a2; // [esp+4h] [ebp-8h]

	if (*(float*)(a1 + 104) <= 0.0 && (int)*(_DWORD*)(a1 + 16) >= 0) {
		sub_501960(48, a1, 0, 0);
		sub_537AF0((int*)(a1 + 56), 2);
		v1 = *(float*)(a1 + 176) + *(float*)(a1 + 56);
		*(_DWORD*)(a1 + 16) |= 0x80000000;
		a2.field_4 = *(float*)(a1 + 60);
		a2.field_0 = v1;
		sub_522FF0(138, &a2);
		v2 = *(float*)(a1 + 56) - *(float*)(a1 + 176);
		a2.field_4 = *(float*)(a1 + 60);
		a2.field_0 = v2;
		sub_522FF0(138, &a2);
		v3 = *(float*)(a1 + 176) + *(float*)(a1 + 60);
		a2.field_0 = *(float*)(a1 + 56);
		a2.field_4 = v3;
		sub_522FF0(138, &a2);
		sub_4D9110((float*)(a1 + 56), 30);
	}
	if (*(float*)(a1 + 104) >= 200.0 && *(int*)(a1 + 16) < 0)
		sub_4E5CC0(a1);
	if (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128) >
	    (unsigned int)(3 * *(_DWORD*)&byte_5D4594[2649704]))
		sub_4E5CC0(a1);
}

//----- (0053D510) --------------------------------------------------------
void __cdecl sub_53D510(int a1) {
	float v1;  // ecx
	float v2;  // eax
	float v3;  // ecx
	float4 v4; // [esp+4h] [ebp-10h]

	if (*(_DWORD*)&byte_5D4594[2598000] >= *(int*)(a1 + 136) ||
	    (v1 = *(float*)(a1 + 156), v2 = *(float*)(a1 + 56), v4.field_4 = *(float*)(a1 + 160), v4.field_0 = v1,
	     v3 = *(float*)(a1 + 60), v4.field_8 = v2, v4.field_C = v3, !sub_535250(&v4, 0, 0, 65)) ||
	    (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 128)) > 3 &&
		*(float*)(a1 + 72) == *(float*)(a1 + 56) && *(float*)(a1 + 76) == *(float*)(a1 + 60)) {
		sub_4E5CC0(a1);
	}
}

//----- (0053D5A0) --------------------------------------------------------
void __cdecl sub_53D5A0(float* a2) {
	_DWORD* v1; // ebx
	int v2;     // edi
	double v3;  // st7
	double v4;  // st7
	float v5;   // edx
	double v6;  // st6
	double v7;  // st7
	_DWORD* v8; // eax
	int v9;     // edi
	float a3;   // [esp+8h] [ebp-18h]
	float a4;   // [esp+Ch] [ebp-14h]
	float4 a1;  // [esp+10h] [ebp-10h]

	if (*(_DWORD*)&byte_5D4594[2598000] - *((_DWORD*)a2 + 32) <
	    (unsigned int)(5 * *(_DWORD*)&byte_5D4594[2649704])) {
		if (*((_DWORD*)a2 + 34) <= *(int*)&byte_5D4594[2598000]) {
			v1 = (_DWORD*)*((_DWORD*)a2 + 187);
			v2 = nox_common_randomInt_415FA0(0, 255);
			v3 = sub_416030(4.0, 12.0);
			v4 = v3 * v3;
			v5 = a2[15];
			a1.field_0 = a2[14];
			v6 = v4 * *(float*)&byte_587000[8 * v2 + 194136];
			a1.field_4 = v5;
			a3 = v6 + a2[14];
			v7 = v4 * *(float*)&byte_587000[8 * v2 + 194140];
			a1.field_8 = a3;
			a4 = v7 + a2[15];
			a1.field_C = a4;
			if ((unsigned __int8)sub_5374B0(&a1)) {
				v8 = sub_4E3810((CHAR*)&byte_587000[278928]);
				v9 = (int)v8;
				if (v8) {
					*(_DWORD*)v8[187] = *v1;
					sub_4DAA50((int)v8, (int)a2, a3, a4);
					*(_DWORD*)(v9 + 20) |= 0x20u;
					sub_4E46F0(v9, 255.0);
					*(_DWORD*)(v9 + 108) = -1056964608;
				}
			}
			*((_DWORD*)a2 + 34) = *(_DWORD*)&byte_5D4594[2598000] + nox_common_randomInt_415FA0(4, 8);
		}
	} else {
		sub_4E5CC0((int)a2);
	}
}

//----- (0053D6E0) --------------------------------------------------------
void __cdecl sub_53D6E0(int a6) {
	int* v1;    // ebx
	float* v2;  // edi
	_DWORD* v3; // eax
	int v4;     // eax
	float v5;   // [esp+4h] [ebp-20h]
	float v6;   // [esp+8h] [ebp-1Ch]
	float v7;   // [esp+Ch] [ebp-18h]
	float v8;   // [esp+10h] [ebp-14h]
	int4 a1;    // [esp+14h] [ebp-10h]

	if (*(float*)(a6 + 104) <= 0.0) {
		v1 = *(int**)(a6 + 748);
		sub_501960(87, a6, 0, 0);
		v2 = (float*)(a6 + 56);
		sub_537AF0((int*)(a6 + 56), 2);
		sub_4D9110((float*)(a6 + 56), 10);
		v3 = sub_4E3810((CHAR*)&byte_587000[278984]);
		if (v3)
			sub_4DAA50((int)v3, 0, *v2, *(float*)(a6 + 60));
		v4 = sub_4EC580(a6);
		sub_4E25B0(a6 + 56, 80.0, 30.0, *v1, 7, v4, 0);
		v5 = *v2 - 80.0;
		v6 = *(float*)(a6 + 60) - 80.0;
		v7 = *v2 + 80.0;
		v8 = *(float*)(a6 + 60) + 80.0;
		a1.field_0 = nox_float2int(v5) / 23;
		a1.field_4 = nox_float2int(v6) / 23;
		a1.field_8 = nox_float2int(v7) / 23;
		a1.field_C = nox_float2int(v8) / 23;
		sub_534FC0(&a1, a6 + 56, 80.0, *v1, 7, a6);
		sub_4E5CC0(a6);
	}
}

//----- (0053D850) --------------------------------------------------------
void __cdecl sub_53D850(int a1) {
	_DWORD* v1; // esi

	v1 = *(_DWORD**)(a1 + 748);
	if (*(_DWORD*)(a1 + 136) < *(int*)&byte_5D4594[2598000]) {
		sub_517F90((float2*)(a1 + 56), 75.0, sub_53D8C0, a1);
		*(_DWORD*)(a1 + 136) = *(_DWORD*)&byte_5D4594[2598000] + nox_common_randomInt_415FA0(5, 10);
	}
	if (*v1)
		--*v1;
	if (!*v1)
		sub_4E5CC0(a1);
}

//----- (0053D8C0) --------------------------------------------------------
void __cdecl sub_53D8C0(int a1, int a2) {
	float v2;  // edx
	float v3;  // eax
	float v4;  // eax
	int v5;    // eax
	int v6;    // eax
	int v7;    // [esp-8h] [ebp-20h]
	float4 v8; // [esp+8h] [ebp-10h]

	if (*(_BYTE*)(a1 + 8) & 6) {
		v2 = *(float*)(a1 + 56);
		v3 = *(float*)(a2 + 56);
		v8.field_4 = *(float*)(a2 + 60);
		v8.field_0 = v3;
		v4 = *(float*)(a1 + 60);
		v8.field_8 = v2;
		v8.field_C = v4;
		if (sub_535250(&v8, 0, 0, 5)) {
			v7 = nox_common_randomInt_415FA0(3, 10);
			v5 = sub_4EC580(a2);
			(*(void(__cdecl**)(int, int, int, int, int))(a1 + 716))(a1, v5, a2, v7, 5);
			v6 = sub_4EC580(a2);
			if (sub_5330C0(v6, a1))
				sub_4EE7E0(a1, 1, 1);
		}
	}
}

//----- (0053D960) --------------------------------------------------------
void __cdecl sub_53D960(int a1) {
	_DWORD* v1; // esi

	v1 = *(_DWORD**)(a1 + 748);
	if (*(_DWORD*)(a1 + 136) < *(int*)&byte_5D4594[2598000]) {
		sub_517F90((float2*)(a1 + 56), 35.0, sub_53D9D0, a1);
		*(_DWORD*)(a1 + 136) = *(_DWORD*)&byte_5D4594[2598000] + nox_common_randomInt_415FA0(5, 10);
	}
	if (*v1)
		--*v1;
	if (!*v1)
		sub_4E5CC0(a1);
}

//----- (0053D9D0) --------------------------------------------------------
void __cdecl sub_53D9D0(int a1, int a2) {
	float v2;  // edx
	float v3;  // eax
	float v4;  // eax
	int v5;    // eax
	int v6;    // eax
	float4 v7; // [esp+8h] [ebp-10h]

	if (*(_BYTE*)(a1 + 8) & 6) {
		v2 = *(float*)(a1 + 56);
		v3 = *(float*)(a2 + 56);
		v7.field_4 = *(float*)(a2 + 60);
		v7.field_0 = v3;
		v4 = *(float*)(a1 + 60);
		v7.field_8 = v2;
		v7.field_C = v4;
		if (sub_535250(&v7, 0, 0, 5)) {
			v5 = sub_4EC580(a2);
			(*(void(__cdecl**)(int, int, int, _DWORD, int))(a1 + 716))(a1, v5, a2, 0, 5);
			v6 = sub_4EC580(a2);
			if (sub_5330C0(v6, a1))
				sub_4EE7E0(a1, 1, 1);
		}
	}
}

//----- (0053DA60) --------------------------------------------------------
void __cdecl sub_53DA60(int* a1) {
	int v1;     // eax
	int v2;     // eax
	_DWORD* v3; // eax

	v1 = *(_DWORD*)&byte_5D4594[2598000];
	if ((unsigned int)a1[34] < *(int*)&byte_5D4594[2598000]) {
		v2 = *(_DWORD*)&byte_5D4594[2488708];
		if (!*(_DWORD*)&byte_5D4594[2488708]) {
			v2 = sub_4E3AA0((CHAR*)&byte_587000[279144]);
			*(_DWORD*)&byte_5D4594[2488708] = v2;
		}
		v3 = sub_4E3450(v2);
		if (v3)
			sub_4DAA50((int)v3, a1[127], *((float*)a1 + 14), *((float*)a1 + 15));
		a1[34] = *(_DWORD*)&byte_5D4594[2598000] + nox_common_randomInt_415FA0(1, 5);
		v1 = *(_DWORD*)&byte_5D4594[2598000];
	}
	if (v1 - a1[32] > (unsigned int)(3 * *(_DWORD*)&byte_5D4594[2649704]))
		sub_4E5CC0((int)a1);
}

//----- (0053DB00) --------------------------------------------------------
void __cdecl sub_53DB00(int a1) {
	if (*(_DWORD*)(a1 + 128) > *(int*)&byte_5D4594[2598000] ||
	    *(_DWORD*)(a1 + 136) < *(int*)&byte_5D4594[2598000]) {
		sub_4E5CC0(a1);
	}
}

//----- (0053DB30) --------------------------------------------------------
int* __cdecl sub_53DB30(_DWORD* a1) {
	int* result; // eax

	result = (int*)a1[5];
	if ((unsigned __int8)result & 2) {
		result = (int*)a1[4];
		if (SBYTE1(result) < 0) {
			sub_4E4780((int)a1, 2);
			sub_4E4800((int)a1, (int*)4);
			result = (int*)a1[4];
			LOBYTE(result) = (unsigned __int8)result | 0x40;
			a1[34] = *(_DWORD*)&byte_5D4594[2598000] + 2 * *(_DWORD*)&byte_5D4594[2649704];
			a1[4] = result;
		}
	} else if ((unsigned __int8)result & 4) {
		result = *(int**)&byte_5D4594[2598000];
		if (*(_DWORD*)&byte_5D4594[2598000] > a1[34]) {
			sub_4E4780((int)a1, 4);
			result = sub_4E4800((int)a1, (int*)8);
		}
	} else if ((unsigned __int8)result & 8) {
		result = sub_4DA920(a1);
	}
	return result;
}

//----- (0053DBB0) --------------------------------------------------------
int* __cdecl sub_53DBB0(_DWORD* a1) {
	int* result; // eax

	result = (int*)a1[5];
	if ((unsigned __int8)result & 2) {
		result = (int*)a1[4];
		if (SBYTE1(result) < 0) {
			sub_4E4780((int)a1, 2);
			sub_4E4800((int)a1, (int*)4);
			result = *(int**)&byte_5D4594[2598000];
			a1[34] = *(_DWORD*)&byte_5D4594[2598000] + 2 * *(_DWORD*)&byte_5D4594[2649704];
		}
	} else if ((unsigned __int8)result & 4) {
		result = *(int**)&byte_5D4594[2598000];
		if (*(_DWORD*)&byte_5D4594[2598000] > a1[34]) {
			sub_4E4780((int)a1, 4);
			result = sub_4E4800((int)a1, (int*)8);
		}
	} else if ((unsigned __int8)result & 8) {
		result = sub_4DA920(a1);
	}
	return result;
}

//----- (0053DC30) --------------------------------------------------------
void __cdecl sub_53DC30(_DWORD* a1) {
	int v1; // eax
	int v2; // eax

	switch (a1[5]) {
	case 2:
		v1 = a1[4];
		if ((v1 & 0x8000) != 0) {
			sub_4E4780((int)a1, 2);
			sub_4E4800((int)a1, (int*)4);
			a1[34] = *(_DWORD*)&byte_5D4594[2598000] + 2 * *(_DWORD*)&byte_5D4594[2649704];
			v2 = a1[4];
			LOBYTE(v2) = v2 | 0x40;
			a1[4] = v2;
		}
		break;
	case 4:
		if (*(_DWORD*)&byte_5D4594[2598000] > a1[34]) {
			sub_4E4780((int)a1, 4);
			sub_4E4800((int)a1, (int*)8);
		}
		break;
	case 8:
		sub_4DA920(a1);
		sub_4E5CC0((int)a1);
		break;
	}
}

//----- (0053DCC0) --------------------------------------------------------
void __cdecl sub_53DCC0(int a1) {
	int v1;    // edi
	int v2;    // esi
	int v3;    // eax
	int v4;    // eax
	int v5;    // eax
	int v6;    // eax
	int v7;    // eax
	double v8; // st7
	double v9; // st6
	float v10; // [esp+Ch] [ebp-4h]
	float v11; // [esp+14h] [ebp+4h]

	v1 = a1;
	v2 = *(_DWORD*)(a1 + 748);
	v3 = sub_4E7980(a1);
	if (!v3 || *(_BYTE*)(v3 + 16) & 0x20) {
		sub_4E5CC0(a1);
		return;
	}
	v4 = *(_DWORD*)(v2 + 12);
	if (v4 && *(_BYTE*)(v4 + 16) & 0x20)
		*(_DWORD*)(v2 + 12) = 0;
	v5 = *(_DWORD*)(a1 + 508);
	if (!v5 || *(_BYTE*)(v5 + 16) & 0x20) {
		*(_BYTE*)(v2 + 24) = 1;
		*(_DWORD*)(v2 + 8) = 0;
	} else {
		*(_DWORD*)(v2 + 16) = *(_DWORD*)(v5 + 56);
		*(_DWORD*)(v2 + 20) = *(_DWORD*)(v5 + 60);
		if (!sub_537110(a1, *(_DWORD*)(a1 + 508))) {
			*(_DWORD*)(v2 + 8) = 0;
		LABEL_12:
			if (!*(_BYTE*)(v2 + 24)) {
				v6 = *(_DWORD*)(v2 + 8);
				if (v6 && ((v7 = *(_DWORD*)(v6 + 16), v7 & 0x20) || (v7 & 0x8000) != 0)) {
					*(_DWORD*)(v2 + 8) = 0;
					*(_BYTE*)(v2 + 24) = 1;
				} else {
					v8 = *(float*)(v2 + 16) - *(float*)(a1 + 56);
					v9 = *(float*)(v2 + 20) - *(float*)(a1 + 60);
					v11 = v9;
					v10 = sqrt(v9 * v11 + v8 * v8) + *(double*)&qword_581450_10176;
					*(float*)(v1 + 80) = v8 * *(float*)(v1 + 544) / v10;
					*(float*)(v1 + 84) = v11 * *(float*)(v1 + 544) / v10;
				}
			}
			goto LABEL_19;
		}
		if (!*(_BYTE*)(v2 + 24)) {
			*(_DWORD*)(v2 + 8) = *(_DWORD*)(a1 + 508);
			goto LABEL_12;
		}
	}
LABEL_19:
	if (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v1 + 128) >
	    (unsigned int)(5 * *(_DWORD*)&byte_5D4594[2649704])) {
		*(_BYTE*)(v2 + 24) = 1;
		*(_DWORD*)(v2 + 8) = 0;
	}
}

//----- (0053DDF0) --------------------------------------------------------
int __cdecl sub_53DDF0(int a1) {
	int v1;             // esi
	int v2;             // edi
	int result;         // eax
	int v4;             // eax
	int v5;             // edx
	char v6;            // [esp-18h] [ebp-24h]
	unsigned __int8 v7; // [esp+8h] [ebp-4h]

	v1 = a1;
	v2 = *(_DWORD*)(a1 + 748);
	result = *(_DWORD*)(v2 + 8);
	if (result) {
		v4 = sub_4ECBD0(a1);
		v5 = *(_DWORD*)(v2 + 8);
		a1 = v4;
		v7 = *(_BYTE*)(v1 + 52);
		result = 3 * *(_DWORD*)&byte_5D4594[2649704];
		if (*(_DWORD*)&byte_5D4594[2598000] - v5 > (unsigned int)(30 * *(_DWORD*)&byte_5D4594[2649704])) {
			sub_501960(305, v1, 0, 0);
			v6 = a1;
			*(_DWORD*)(v2 + 8) = 0;
			sub_4E82C0(v7, 0, v6, 0);
			sub_4E7010(v1, (float2*)v2);
			result = sub_4DA180(8, &a1);
		}
	}
	return result;
}

//----- (0053DE80) --------------------------------------------------------
int* __cdecl sub_53DE80(_DWORD* a1) {
	int v1;      // edi
	int* result; // eax

	v1 = a1[175];
	if (a1[4] & 0x1000000) {
		result = (int*)a1[5];
		if ((unsigned __int8)result & 2) {
			sub_4E4780((int)a1, 2);
			result = sub_4E4800((int)a1, (int*)8);
		} else if ((unsigned __int8)result & 4) {
			result = *(int**)(v1 + 16);
			if (*(_DWORD*)&byte_5D4594[2598000] >= (unsigned int)result) {
				sub_4E4780((int)a1, 4);
				result = sub_4E4800((int)a1, (int*)8);
			}
		} else {
			*(_DWORD*)(v1 + 24) = 0;
		}
	} else {
		result = *(int**)(v1 + 16);
		if (result) {
			if (*(_DWORD*)&byte_5D4594[2598000] >= (unsigned int)result) {
				sub_4E4670((int)a1, 1);
				sub_4E4780((int)a1, 2);
				sub_4E4800((int)a1, (int*)4);
				*(_DWORD*)(v1 + 16) += 5 * *(_DWORD*)&byte_5D4594[2649704];
				result = sub_501960(874, (int)a1, 0, 0);
			}
		}
	}
	return result;
}

//----- (0053DF40) --------------------------------------------------------
void __cdecl sub_53DF40(int a3) {
	int v1;              // edi
	unsigned __int64 v2; // rax
	int v3;              // eax
	int v4;              // eax
	int v5;              // eax
	double v6;           // st7
	double v7;           // st7
	double v8;           // st7
	double v9;           // st6
	int v10;             // eax
	float4 v11;          // [esp+8h] [ebp-10h]

	v1 = *(_DWORD*)(a3 + 748);
	*(_DWORD*)(a3 + 112) = 1008981770;
	if (*(_DWORD*)v1 && *(_BYTE*)(*(_DWORD*)v1 + 16) & 0x20) {
		sub_4EB9B0(a3, 0);
		sub_419570(a3 + 48, *(_DWORD*)(a3 + 36));
		sub_4E8290(1, 0);
	}
	v2 = sub_416BB0() - *(_QWORD*)(v1 + 8);
	v11.field_4 = *((float*)&v2 + 1);
	if (v2 <= 0x4E20) {
		v3 = *(_DWORD*)(a3 + 508);
		if (v3) {
			if (v3 != *(_DWORD*)v1 ||
			    (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v1 + 16)) <= *(int*)(v1 + 20)) {
				*(_DWORD*)(a3 + 16) |= 0x40u;
				*(_QWORD*)(v1 + 8) = sub_416BB0();
				v5 = *(_DWORD*)(a3 + 508);
				if (*(_DWORD*)(v5 + 16) & 0x8020) {
					sub_4EC300(a3);
					sub_4EB9B0(a3, 0);
					sub_419570(a3 + 48, *(_DWORD*)(a3 + 36));
					sub_4E8290(1, 0);
				} else {
					v6 = *(float*)(v5 + 176) + *(float*)(a3 + 176);
					v11.field_0 = *(float*)(v5 + 56);
					v11.field_4 = *(float*)(v5 + 60);
					v7 = v6 + 10.0;
					v11.field_8 = v7 * *(float*)&byte_587000[8 * *(__int16*)(v5 + 124) + 194136] +
						      *(float*)(v5 + 56);
					v11.field_C = v7 * *(float*)&byte_587000[8 * *(__int16*)(v5 + 124) + 194140] +
						      *(float*)(v5 + 60);
					if (sub_535250(&v11, 0, 0, 5))
						sub_4E7010(a3, (float2*)&v11.field_8);
				}
			} else {
				*(_DWORD*)(a3 + 16) &= 0xFFFFFFBF;
				*(_DWORD*)(a3 + 520) = 0;
				v4 = *(__int16*)(*(_DWORD*)(a3 + 508) + 124) + nox_common_randomInt_415FA0(-32, 32);
				if (v4 < 0)
					v4 += (unsigned int)(255 - v4) >> 8 << 8;
				if (v4 >= 256)
					v4 += -256 * ((unsigned int)v4 >> 8);
				v11.field_0 = *(float*)(a3 + 56) - *(float*)&byte_587000[8 * v4 + 194136] * 20.0;
				v11.field_4 = *(float*)(a3 + 60) - *(float*)&byte_587000[8 * v4 + 194140] * 20.0;
				sub_52DF80((int)&v11, a3, 30.0);
				sub_4EC300(a3);
				sub_4E8290(1, 0);
				sub_501960(926, a3, 0, 0);
			}
		} else {
			v8 = *(float*)(a3 + 84);
			v9 = *(float*)(a3 + 80);
			v10 = *(_DWORD*)(a3 + 16);
			LOBYTE(v10) = v10 & 0xBF;
			*(_DWORD*)(a3 + 16) = v10;
			if (*(float*)(v1 + 24) > sqrt(v9 * v9 + v8 * v8))
				*(_DWORD*)v1 = 0;
		}
	} else {
		sub_417F50(a3);
	}
}

//----- (0053E190) --------------------------------------------------------
void __cdecl sub_53E190(int a1) {
	int v1; // eax

	v1 = **(_DWORD**)(a1 + 700);
	if (v1 && *(_BYTE*)(v1 + 88) & 1) {
		sub_4E5CC0(a1);
	} else if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a1 + 136)) > 0x46) {
		sub_4E5CC0(a1);
	}
}

//----- (0053E1D0) --------------------------------------------------------
void __cdecl sub_53E1D0(int a1) {
	_DWORD* v1; // ecx
	int v2;     // eax
	int v3;     // eax
	double v4;  // st7
	double v5;  // st7
	float4 v6;  // [esp+4h] [ebp-10h]

	v1 = *(_DWORD**)(a1 + 748);
	v2 = v1[1];
	if (!v2 || *(_DWORD*)(v2 + 16) & 0x8020) {
		if (*v1 && *(_BYTE*)(*v1 + 16) & 0x20)
			*v1 = 0;
		v3 = *(_DWORD*)(a1 + 508);
		if (v3) {
			if (*(_DWORD*)(v3 + 16) & 0x8020) {
				sub_4EC300(a1);
			} else {
				v4 = *(float*)(v3 + 176) + *(float*)(a1 + 176);
				v6.field_0 = *(float*)(v3 + 56);
				v6.field_4 = *(float*)(v3 + 60);
				v5 = v4 + 10.0;
				v6.field_8 =
				    v5 * *(float*)&byte_587000[8 * *(__int16*)(v3 + 124) + 194136] + *(float*)(v3 + 56);
				v6.field_C =
				    v5 * *(float*)&byte_587000[8 * *(__int16*)(v3 + 124) + 194140] + *(float*)(v3 + 60);
				if (sub_535250(&v6, 0, 0, 5))
					sub_4E7010(a1, (float2*)&v6.field_8);
			}
		}
	} else {
		sub_4F3400(v2, a1, 1);
	}
}

//----- (0053E2B0) --------------------------------------------------------
char __cdecl sub_53E2B0(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)(a1 + 16);
	if (!(v1 & 0x1000000)) {
		LOBYTE(v1) = v1 | 0x40;
		*(_DWORD*)(a1 + 744) = 0;
		*(_DWORD*)(a1 + 16) = v1;
	}
	return v1;
}

//----- (0053E2D0) --------------------------------------------------------
BOOL __cdecl sub_53E2D0(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)(a1 + 8) & 0x2000000)
		result = (sub_415C70(a1) & 0xC0D) == 0;
	else
		result = 1;
	return result;
}

//----- (0053E300) --------------------------------------------------------
int __cdecl sub_53E300(_DWORD* a1) {
	_DWORD* i;  // esi
	int v2;     // eax
	int result; // eax
	float v4;   // [esp+8h] [ebp-4h]

	v4 = 0.0;
	for (i = (_DWORD*)a1[126]; i; i = (_DWORD*)i[124]) {
		if (i[2] & 0x2000000) {
			v2 = i[4];
			if (v2 & 0x100)
				v4 = sub_415C00((int)i) + v4;
		}
	}
	if (v4 > *(double*)&qword_581450_9512)
		v4 = 1.0;
	result = a1[2];
	if (result & 4) {
		result = a1[187];
		*(float*)(result + 228) = v4;
	} else if (result & 2) {
		result = LODWORD(v4);
		*(float*)(a1[187] + 2072) = v4;
	}
	return result;
}

//----- (0053E3A0) --------------------------------------------------------
int __cdecl sub_53E3A0(int a1, int a2) {
	int result; // eax
	int v3;     // ecx

	if (!(*(_DWORD*)(a2 + 8) & 0x2000000))
		return 0;
	v3 = *(_DWORD*)(a2 + 16);
	if (!(v3 & 0x100))
		return 0;
	result = *(_DWORD*)(a1 + 504);
	if (!result)
		return 0;
	while (result != a2) {
		result = *(_DWORD*)(result + 496);
		if (!result)
			return result;
	}
	BYTE1(v3) &= 0xFEu;
	*(_DWORD*)(a2 + 16) = v3;
	if (*(_BYTE*)(a1 + 12) & 0x10)
		sub_4E4B20(a1, a2, 0);
	*(_DWORD*)(a2 + 16) &= 0xEFFFFFFF;
	sub_53E300((_DWORD*)a1);
	sub_4F3030(a2, a1);
	return 1;
}

//----- (0053E430) --------------------------------------------------------
int __cdecl sub_53E430(_DWORD* a1, int a2, int a3, int a4) {
	int v4;     // ecx
	int v5;     // eax
	int v7;     // eax
	int v8;     // ebp
	_DWORD* v9; // edi
	char v10;   // al

	if (!(*(_DWORD*)(a2 + 8) & 0x2000000))
		return 0;
	v4 = *(_DWORD*)(a2 + 16);
	if (!(v4 & 0x100))
		return 0;
	v5 = a1[2];
	if (v5 & 2)
		return sub_53E3A0((int)a1, a2);
	if (!(v5 & 4))
		return 0;
	v7 = a1[126];
	v8 = a1[187];
	if (!v7)
		return 0;
	while (v7 != a2) {
		v7 = *(_DWORD*)(v7 + 496);
		if (!v7)
			return 0;
	}
	*(_DWORD*)(a2 + 16) = v4 & 0xEFFFFEFF;
	v9 = *(_DWORD**)(v8 + 276);
	*v9 &= ~sub_415C70(a2);
	if (a3)
		sub_4D8590(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (_DWORD*)a2);
	if (a4)
		sub_4D84C0(255, a2);
	sub_53E300(a1);
	sub_4F3030(a2, (int)a1);
	if (*(_BYTE*)(a2 + 12) & 2) {
		v10 = *(_BYTE*)(v8 + 88);
		if (v10 == 15 || v10 == 16 || v10 == 17)
			sub_4FA020(a1, 13);
	}
	return 1;
}

//----- (0053E520) --------------------------------------------------------
int __cdecl sub_53E520(int a1, _DWORD* a2) {
	_DWORD* v3; // eax
	_DWORD* v4; // ecx

	if (!(a2[2] & 0x2000000))
		return 0;
	if (a2[4] & 0x100)
		return 0;
	v3 = *(_DWORD**)(a1 + 504);
	v4 = *(_DWORD**)(a1 + 504);
	if (!v4)
		return 0;
	while (v4 != a2) {
		v4 = (_DWORD*)v4[124];
		if (!v4)
			return 0;
	}
	if (v3) {
		while (!(v3[2] & 0x2000000) || !(v3[4] & 0x100) || v3[3] != a2[3]) {
			v3 = (_DWORD*)v3[124];
			if (!v3)
				goto LABEL_18;
		}
		sub_53E3A0(a1, (int)v3);
	}
LABEL_18:
	a2[4] |= 0x100u;
	if (*(_BYTE*)(a1 + 12) & 0x10)
		sub_4E4B20(a1, (int)a2, 1);
	if (!sub_53E2D0((int)a2))
		a2[4] |= 0x10000000u;
	sub_53E300((_DWORD*)a1);
	sub_4F2FF0((int)a2, a1);
	if (a2[3] & 2)
		sub_53E600((_DWORD*)a1);
	return 1;
}

//----- (0053E600) --------------------------------------------------------
void __cdecl sub_53E600(_DWORD* a1) {
	_DWORD* i; // esi
	int v2;    // eax

	if (a1) {
		for (i = (_DWORD*)a1[126]; i; i = (_DWORD*)i[124]) {
			v2 = i[4];
			if (v2 & 0x100 && i[2] & 0x1001000) {
				if (sub_415820((int)i) & 0x7FFE40C)
					sub_53A140(a1, (int)i, 1, 1);
			}
		}
	}
}

//----- (0053E650) --------------------------------------------------------
int __cdecl sub_53E650(_DWORD* a1, int a2, int a3, int a4) {
	int v4;      // eax
	int v5;      // eax
	int v7;      // ebx
	_DWORD* v8;  // ebp
	int v9;      // eax
	int v10;     // ecx
	_DWORD* v11; // ebp

	if (!(*(_DWORD*)(a2 + 8) & 0x2000000))
		return 0;
	v4 = *(_DWORD*)(a2 + 16);
	if (v4 & 0x100)
		return 0;
	v5 = a1[2];
	if (v5 & 2)
		return sub_53E520((int)a1, (_DWORD*)a2);
	if (!(v5 & 4))
		return 0;
	v7 = a1[187];
	v8 = sub_53E7B0((int)a1, a2);
	if (!sub_57B3D0(a2, *(_BYTE*)(*(_DWORD*)(v7 + 276) + 2251))) {
		sub_4DA2C0((int)a1, "armor.c:ArmorEquipClassFail", 0);
		if (a4)
			sub_501960(925, (int)a1, 2, a1[9]);
		return 0;
	}
	LOBYTE(v9) = sub_4F3180((int)a1, a2);
	if (!v9) {
		sub_4DA2C0((int)a1, "armor.c:ArmorEquipStrengthFail", 0);
		if (a4)
			sub_501960(925, (int)a1, 2, a1[9]);
		return 0;
	}
	if (v8)
		sub_53E430(a1, (int)v8, 1, 1);
	v10 = *(_DWORD*)(a2 + 16);
	BYTE1(v10) |= 1u;
	*(_DWORD*)(a2 + 16) = v10;
	v11 = *(_DWORD**)(v7 + 276);
	*v11 |= sub_415C70(a2);
	sub_4D8540(*(unsigned __int8*)(*(_DWORD*)(v7 + 276) + 2064), (_DWORD*)a2, a3);
	if (!sub_53E2D0(a2))
		*(_DWORD*)(a2 + 16) |= 0x10000000u;
	sub_53E300(a1);
	sub_4F2FF0(a2, (int)a1);
	if (*(_BYTE*)(a2 + 12) & 2)
		sub_53E600(a1);
	return 1;
}
// 53E6E7: variable 'v9' is possibly undefined

//----- (0053E7B0) --------------------------------------------------------
_DWORD* __cdecl sub_53E7B0(int a1, int a2) {
	_DWORD* result; // eax

	result = *(_DWORD**)(a1 + 504);
	if (!result)
		return 0;
	while (!(result[4] & 0x100) || !(result[2] & 0x2000000) || result[3] != *(_DWORD*)(a2 + 12)) {
		result = (_DWORD*)result[124];
		if (!result)
			return 0;
	}
	return result;
}

//----- (0053E7F0) --------------------------------------------------------
int __cdecl sub_53E7F0(int a1, int a2, int a3, int a4) {
	_DWORD* v5;  // eax
	int v6;      // ebp
	_DWORD* v7;  // esi
	int v8;      // eax
	_DWORD* v9;  // ecx
	int i;       // eax
	int v11;     // eax
	_DWORD* v12; // ecx
	int v13;     // eax
	int m;       // eax
	__int16 v15; // ax
	int v16;     // eax
	int j;       // eax
	_DWORD* v18; // ecx
	int k;       // eax
	int l;       // eax

	if (!*(_DWORD*)&byte_5D4594[2488712]) {
		*(_DWORD*)&byte_5D4594[2488712] = sub_4E3AA0((CHAR*)&byte_587000[279312]);
		*(_DWORD*)&byte_5D4594[2488716] = sub_4E3AA0((CHAR*)&byte_587000[279328]);
		*(_DWORD*)&byte_5D4594[2488720] = sub_4E3AA0((CHAR*)&byte_587000[279340]);
		*(_DWORD*)&byte_5D4594[2488724] = sub_4E3AA0((CHAR*)&byte_587000[279356]);
	}
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096) && sub_409F40(2) &&
	    sub_4E7EC0(a1, a2)) {
		sub_4DA2C0(a1, "armor.c:CannotPickupDuplicateArmor", 0);
	LABEL_13:
		sub_501960(925, a1, 2, *(_DWORD*)(a1 + 36));
		return 0;
	}
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096) &&
	    *(_BYTE*)(a1 + 8) & 4 && !sub_57B3D0(a2, *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2251))) {
		sub_4DA2C0(a1, "armor.c:ArmorEquipClassFail", 0);
		goto LABEL_13;
	}
	if (sub_4F31E0(a1, a2, a3) != 1)
		return 0;
	if (*(_BYTE*)(a1 + 8) & 4) {
		v5 = sub_53E7B0(a1, a2);
		v6 = *(_DWORD*)(a1 + 748);
		v7 = v5;
		v8 = sub_419E60(a1);
		if (!v8) {
			if (v7) {
				LOWORD(v8) = *((_WORD*)v7 + 2);
				if (v8 != *(_DWORD*)&byte_5D4594[2488720] && v8 != *(_DWORD*)&byte_5D4594[2488724] &&
				    v8 != *(_DWORD*)&byte_5D4594[2488712] && v8 != *(_DWORD*)&byte_5D4594[2488716]) {
					goto LABEL_40;
				}
				if (v8 == *(_DWORD*)&byte_5D4594[2488716]) {
					v9 = (_DWORD*)v7[173];
					for (i = 0; i < 4; ++i) {
						if (*v9)
							break;
						++v9;
					}
					if (i == 4)
						sub_53E650((_DWORD*)a1, a2, a4, 0);
					goto LABEL_40;
				}
			}
			if (!(*(_BYTE*)(a2 + 12) & 2))
				goto LABEL_70;
			if (!v7) {
				v11 = *(_DWORD*)(v6 + 104);
				if (!v11 || !(*(_DWORD*)(v11 + 12) & 0x7FFE40C))
					sub_53E650((_DWORD*)a1, a2, a4, 0);
				goto LABEL_40;
			}
			v12 = (_DWORD*)v7[173];
			v13 = *((unsigned __int16*)v7 + 2);
			if ((unsigned __int16)v13 != *(_DWORD*)&byte_5D4594[2488720]) {
				if (v13 == *(_DWORD*)&byte_5D4594[2488724]) {
					v16 = *(unsigned __int16*)(a2 + 4);
					if ((unsigned __int16)v16 == *(_DWORD*)&byte_5D4594[2488720]) {
						for (j = 0; j < 4; ++j) {
							if (*v12)
								break;
							++v12;
						}
						if (j == 4) {
							v18 = *(_DWORD**)(a2 + 692);
							for (k = 0; k < 4; ++k) {
								if (*v18)
									break;
								++v18;
							}
							if (k != 4)
								sub_53E650((_DWORD*)a1, a2, a4, 0);
						}
					} else if (v16 == *(_DWORD*)&byte_5D4594[2488724]) {
						for (l = 0; l < 4; ++l) {
							if (*v12)
								break;
							++v12;
						}
						if (l == 4)
							sub_53E650((_DWORD*)a1, a2, a4, 0);
					}
				}
				goto LABEL_40;
			}
			for (m = 0; m < 4; ++m) {
				if (*v12)
					break;
				++v12;
			}
			if (m == 4)
			LABEL_70:
				sub_53E650((_DWORD*)a1, a2, a4, 0);
		}
	}
LABEL_40:
	v15 = *(_WORD*)(a2 + 24);
	if (v15 & 0x10) {
		sub_501960(804, a1, 0, 0);
	} else if (v15 & 8) {
		sub_501960(810, a1, 0, 0);
	} else if (v15 & 4) {
		sub_501960(807, a1, 0, 0);
	} else if (v15 & 2) {
		if (*(_BYTE*)(a2 + 12) & 0x20)
			sub_501960(816, a1, 0, 0);
		else
			sub_501960(813, a1, 0, 0);
	}
	sub_5116F0(a2);
	return 1;
}

//----- (0053EAE0) --------------------------------------------------------
void __cdecl sub_53EAE0(int a1) {
	__int16 v2; // cx

	if (a1) {
		v2 = *(_WORD*)(a1 + 24);
		if (v2 & 0x10) {
			sub_501960(805, a1, 0, 0);
		} else if (v2 & 8) {
			sub_501960(811, a1, 0, 0);
		} else if (v2 & 4) {
			sub_501960(808, a1, 0, 0);
		} else if (v2 & 2) {
			if (*(_BYTE*)(a1 + 12) & 0x20)
				sub_501960(817, a1, 0, 0);
			else
				sub_501960(814, a1, 0, 0);
		}
	}
}

//----- (0053EB70) --------------------------------------------------------
int __cdecl sub_53EB70(int a1, _DWORD* a2, int* a3) {
	if (sub_4ED290(a1, (int)a2, (float2*)a3) != 1)
		return 0;
	sub_53EAE0((int)a2);
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096)) {
		if (sub_409F40(2))
			sub_511660(a2, 25 * *(_DWORD*)&byte_5D4594[2649704]);
	}
	return 1;
}

//----- (0053EBF0) --------------------------------------------------------
int __cdecl sub_53EBF0(int a1) {
	unsigned __int8* i; // eax
	int v2;             // edx

	if (!a1)
		return 0;
	if (!*(_DWORD*)&byte_5D4594[2488728])
		sub_53EC40();
	if (!*(_DWORD*)&byte_587000[279432])
		return 0;
	for (i = &byte_587000[279432]; *((_DWORD*)i + 1) != *(unsigned __int16*)(a1 + 4); i += 12) {
		v2 = *((_DWORD*)i + 3);
		if (!v2)
			return 0;
	}
	return 1;
}

//----- (0053EC40) --------------------------------------------------------
CHAR* sub_53EC40() {
	CHAR* result;        // eax
	unsigned __int8* v1; // esi

	result = *(CHAR**)&byte_587000[279432];
	if (*(_DWORD*)&byte_587000[279432]) {
		v1 = &byte_587000[279432];
		do {
			*((_DWORD*)v1 + 1) = sub_4E3AA0(result);
			result = (CHAR*)*((_DWORD*)v1 + 3);
			v1 += 12;
		} while (result);
		*(_DWORD*)&byte_5D4594[2488728] = 1;
	} else {
		*(_DWORD*)&byte_5D4594[2488728] = 1;
	}
	return result;
}

//----- (0053EC80) --------------------------------------------------------
BOOL __cdecl sub_53EC80(int a1, int a2) {
	int v2;             // edx
	unsigned __int8* i; // eax
	int v4;             // esi

	if (!a1)
		return 0;
	if (!*(_DWORD*)&byte_5D4594[2488728])
		sub_53EC40();
	v2 = 0;
	if (!*(_DWORD*)&byte_587000[279432])
		return 0;
	for (i = &byte_587000[279432]; *((_DWORD*)i + 1) != *(unsigned __int16*)(a1 + 4); i += 12) {
		v4 = *((_DWORD*)i + 3);
		++v2;
		if (!v4)
			return 0;
	}
	return (a2 & *(_DWORD*)&byte_587000[12 * v2 + 279440]) != 0;
}

//----- (0053ECE0) --------------------------------------------------------
int __cdecl sub_53ECE0(int a1, int a2) {
	int v2; // eax

	if (*(_BYTE*)(a1 + 540)) {
		sub_4EE9D0(a1);
		sub_4DA2C0(a1, "Use.c:MushroomClean", 0);
		v2 = sub_424800(14, 1);
		sub_501960(v2, a1, 0, 0);
	} else {
		sub_4DA2C0(a1, "Use.c:MushroomConfuse", 0);
	}
	sub_4FF380(a1, 3, 300, 5);
	sub_4E5CC0(a2);
	return 1;
}

//----- (0053ED60) --------------------------------------------------------
int __cdecl sub_53ED60(int a1, int a2) {
	sub_4FF380(a1, **(_DWORD**)(a2 + 736), *(_DWORD*)(*(_DWORD*)(a2 + 736) + 4), 5);
	sub_4E5CC0(a2);
	return 1;
}

//----- (0053ED90) --------------------------------------------------------
int __cdecl sub_53ED90(int a1, _DWORD* a2) {
	int* v2;   // ecx
	int v3;    // eax
	int v4;    // eax
	int v6[3]; // [esp+4h] [ebp-Ch]

	v6[0] = a1;
	v2 = (int*)a2[184];
	if (*(_BYTE*)(a1 + 8) & 4) {
		v3 = *(_DWORD*)(a1 + 748);
		*(float*)&v6[1] = (double)*(int*)(*(_DWORD*)(v3 + 276) + 2284);
		*(float*)&v6[2] = (double)*(int*)(*(_DWORD*)(v3 + 276) + 2288);
	} else {
		v4 = *(_DWORD*)(a1 + 60);
		v6[1] = *(_DWORD*)(a1 + 56);
		v6[2] = v4;
	}
	sub_4FD400(*v2, (int)a2, a2, (int)a2, v6, 4);
	sub_4E5CC0((int)a2);
	return 1;
}

//----- (0053EE10) --------------------------------------------------------
int __cdecl sub_53EE10(int a1, int a2) {
	_WORD* v2; // eax
	int v3;    // eax

	if (*(_BYTE*)(a2 + 8) & 0x10) {
		if (!(*(_BYTE*)(a2 + 12) & 8)) {
			v2 = *(_WORD**)(a1 + 556);
			if (v2) {
				if (*v2 < v2[2]) {
					sub_4EE460(a1, **(_DWORD**)(a2 + 736));
					if (*(_BYTE*)(a1 + 8) & 4) {
						v3 = *(_DWORD*)(a2 + 12);
						if (*(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2252)) {
							if (v3 & 1) {
								sub_501960(324, a1, 0, 0);
							} else if (v3 & 2) {
								sub_501960(325, a1, 0, 0);
							} else if (v3 & 4) {
								sub_501960(326, a1, 0, 0);
							}
						} else if (v3 & 1) {
							sub_501960(314, a1, 0, 0);
						} else if (v3 & 2) {
							sub_501960(315, a1, 0, 0);
						} else if (v3 & 4) {
							sub_501960(316, a1, 0, 0);
						}
					} else {
						sub_501960(334, a1, 0, 0);
					}
					sub_4E5CC0(a2);
				}
			}
		}
	}
	return 1;
}

//----- (0053EF00) --------------------------------------------------------
int __cdecl sub_53EF00(int a1, int a2) {
	int v2; // esi

	if (!a1 || !a2 || !*(_DWORD*)(a1 + 556))
		return 1;
	sub_4FF380(a1, 3, 5 * *(_WORD*)&byte_5D4594[2649704], 4);
	sub_4DA2C0(a1, "Use.c:CiderConfuse", 0);
	v2 = sub_53EE10(a1, a2);
	if (v2)
		sub_4E5CC0(a2);
	return v2;
}

//----- (0053EF70) --------------------------------------------------------
int __cdecl sub_53EF70(int a1, int a2) {
	int v2;     // ebp
	int v3;     // edi
	int result; // eax
	int v5;     // edx
	_WORD* v6;  // edx
	char v7;    // al
	double v8;  // st7
	int v9;     // ecx
	char v10;   // al
	double v11; // st7
	int v12;    // eax
	int v13;    // ecx
	int v14;    // ecx
	int v15;    // ecx
	int v16;    // eax
	int v17;    // ecx
	int v18;    // ecx
	int v19;    // ecx
	int v20;    // ecx
	int v21;    // ecx
	int v22;    // ecx
	float v23;  // [esp+0h] [ebp-20h]
	float v24;  // [esp+0h] [ebp-20h]
	int v25;    // [esp+10h] [ebp-10h]
	int v26[3]; // [esp+14h] [ebp-Ch]

	v2 = a2;
	v3 = **(_DWORD**)(a2 + 736);
	result = 0;
	v25 = **(_DWORD**)(a2 + 736);
	if (!(*(_DWORD*)(a1 + 8) & 4) || (v5 = *(_DWORD*)(a1 + 16), (v5 & 0x8000) == 0)) {
		if (!(*(_BYTE*)(a2 + 12) & 0x10) || (v6 = *(_WORD**)(a1 + 556)) == 0) {
		LABEL_16:
			if (!(*(_BYTE*)(v2 + 12) & 0x20) || !(*(_BYTE*)(a1 + 8) & 4) ||
			    (v9 = *(_DWORD*)(a1 + 748), *(_WORD*)(v9 + 4) >= *(_WORD*)(v9 + 8))) {
			LABEL_27:
				if (*(_BYTE*)(v2 + 12) & 0x40 && *(_BYTE*)(a1 + 8) & 4 && *(_BYTE*)(a1 + 540)) {
					sub_4EE9D0(a1);
					v12 = sub_424800(14, 1);
					sub_501960(v12, a1, 0, 0);
					result = 1;
				}
				v13 = *(_DWORD*)(v2 + 12);
				if (v13 & 0x100) {
					sub_4FF380(a1, 9, 120 * *(_WORD*)&byte_5D4594[2649704], 3);
					result = 1;
				}
				v14 = *(_DWORD*)(v2 + 12);
				if (v14 & 0x200) {
					sub_4FF380(a1, 0, 120 * *(_WORD*)&byte_5D4594[2649704], 3);
					result = 1;
				}
				v15 = *(_DWORD*)(v2 + 12);
				if (v15 & 0x400) {
					v16 = *(_DWORD*)(a1 + 56);
					v17 = *(_DWORD*)(a1 + 60);
					v26[0] = a1;
					v26[1] = v16;
					v26[2] = v17;
					sub_4FD400(51, a1, (_DWORD*)a1, a1, v26, v3);
					result = 1;
				}
				v18 = *(_DWORD*)(v2 + 12);
				if (v18 & 0x800) {
					sub_4FF380(a1, 17, 120 * *(_WORD*)&byte_5D4594[2649704], 3);
					result = 1;
				}
				v19 = *(_DWORD*)(v2 + 12);
				if (v19 & 0x1000) {
					sub_4FF380(a1, 20, 120 * *(_WORD*)&byte_5D4594[2649704], 3);
					result = 1;
				}
				v20 = *(_DWORD*)(v2 + 12);
				if (v20 & 0x2000) {
					sub_4FF380(a1, 18, 120 * *(_WORD*)&byte_5D4594[2649704], 3);
					result = 1;
				}
				v21 = *(_DWORD*)(v2 + 12);
				if (v21 & 0x4000) {
					sub_4FF380(a1, 23, 120 * *(_WORD*)&byte_5D4594[2649704], 3);
					result = 1;
				}
				v22 = *(_DWORD*)(v2 + 12);
				if ((v22 & 0x8000) != 0) {
					sub_4FF380(a1, 21, 120 * *(_WORD*)&byte_5D4594[2649704], 3);
					result = 1;
				}
				if (*(_DWORD*)(v2 + 12) & 0x10000) {
					sub_4FF380(a1, 13, 120 * *(_WORD*)&byte_5D4594[2649704], 3);
				} else if (!result) {
					return 1;
				}
				sub_4E5CC0(v2);
				return 1;
			}
			v10 = *(_BYTE*)(*(_DWORD*)(v9 + 276) + 2251);
			if (v10) {
				if (v10 == 1) {
					v11 = (double)v25 * *(float*)&dword_587000_312820;
				} else {
					if (v10 != 2) {
					LABEL_26:
						sub_4EEB80(a1, v3);
						sub_501960(755, a1, 0, 0);
						result = 1;
						goto LABEL_27;
					}
					v11 = (double)v25 * *(float*)&dword_587000_312804;
				}
			} else {
				v11 = (double)v25 * *(float*)&dword_587000_312788;
			}
			v24 = v11;
			v3 = nox_float2int(v24);
			goto LABEL_26;
		}
		if (*v6 >= v6[2]) {
		LABEL_15:
			v2 = a2;
			goto LABEL_16;
		}
		if (*(_DWORD*)(a1 + 8) & 4) {
			v7 = *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2251);
			switch (v7) {
			case 0:
				v8 = (double)v25 * *(float*)&dword_587000_312784;
			LABEL_13:
				v23 = v8;
				v3 = nox_float2int(v23);
				v25 = v3;
				break;
			case 1:
				v8 = (double)v25 * *(float*)&dword_587000_312816;
				goto LABEL_13;
			case 2:
				v8 = (double)v25 * *(float*)&dword_587000_312800;
				goto LABEL_13;
			}
		}
		sub_4EE460(a1, v3);
		sub_501960(754, a1, 0, 0);
		result = 1;
		goto LABEL_15;
	}
	return result;
}

//----- (0053F290) --------------------------------------------------------
int __cdecl sub_53F290(int a1, _DWORD* a2) {
	int v2;              // esi
	int result;          // eax
	double v4;           // st7
	int v5;              // eax
	double v6;           // st6
	float v7;            // edx
	double v8;           // st7
	int v9;              // eax
	_DWORD* v10;         // eax
	int v11;             // ebx
	unsigned __int8 v12; // al
	float4 v13;          // [esp+Ch] [ebp-10h]

	v2 = a2[184];
	if (!v2)
		return 1;
	if (!*(_DWORD*)(v2 + 84))
		*(_DWORD*)(v2 + 84) = sub_4E3AA0((CHAR*)(v2 + 4));
	if (!*(_BYTE*)(v2 + 109) || *(_BYTE*)(v2 + 108)) {
		if (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v2 + 104) >=
		    (unsigned int)(*(_DWORD*)(v2 + 100) - sub_4E0960((int)a2))) {
			v4 = *(float*)(a1 + 176) + 4.0;
			v5 = 8 * *(__int16*)(a1 + 124);
			v6 = v4 * *(float*)&byte_587000[v5 + 194136];
			v7 = *(float*)(a1 + 60);
			v13.field_0 = *(float*)(a1 + 56);
			v13.field_4 = v7;
			v13.field_8 = v6 + *(float*)(a1 + 56);
			v8 = v4 * *(float*)&byte_587000[v5 + 194140] + *(float*)(a1 + 60);
			v13.field_8 = v13.field_8 + *(float*)(a1 + 80);
			v13.field_C = v8 + *(float*)(a1 + 84);
			if (!sub_535250(&v13, 0, 0, 5)) {
				v13.field_8 = v13.field_0;
				v13.field_C = v13.field_4;
			}
			sub_53F480(a1, *(_DWORD*)(v2 + 84), (int*)&v13.field_8, (_DWORD*)*(__int16*)(a1 + 124));
			if (*(_BYTE*)(v2 + 96) & 1) {
				v9 = *(__int16*)(a1 + 124) + 8;
				if (v9 >= 256)
					v9 += -256 * ((unsigned int)v9 >> 8);
				sub_53F480(a1, *(_DWORD*)(v2 + 84), (int*)&v13.field_8, (_DWORD*)v9);
				v10 = (_DWORD*)(*(__int16*)(a1 + 124) - 8);
				if ((int)v10 < 0)
					v10 += 64 * ((unsigned int)(255 - (_DWORD)v10) >> 8);
				sub_53F480(a1, *(_DWORD*)(v2 + 84), (int*)&v13.field_8, v10);
			}
			sub_501960(*(_DWORD*)(v2 + 88), a1, 0, 0);
			if (*(_BYTE*)(v2 + 109)) {
				v11 = *(unsigned __int8*)(v2 + 109);
				v12 = *(_BYTE*)(v2 + 108) - 1;
				*(_BYTE*)(v2 + 108) = v12;
				*(_DWORD*)(v2 + 112) = 100 * v12 / v11;
				if (*(_BYTE*)(a1 + 8) & 4)
					sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064),
						   a2, v12, v11);
			}
			*(_DWORD*)(v2 + 104) = *(_DWORD*)&byte_5D4594[2598000];
			result = 1;
		} else {
			result = 0;
		}
	} else {
		sub_501960(222, a1, 0, 0);
		result = 0;
	}
	return result;
}

//----- (0053F480) --------------------------------------------------------
_DWORD* __cdecl sub_53F480(int a1, int a2, int* a3, _DWORD* a4) {
	_DWORD* result; // eax
	_DWORD* v5;     // esi

	result = sub_4E3450(a2);
	v5 = result;
	if (result) {
		sub_4DAA50((int)result, a1, *(float*)a3, *((float*)a3 + 1));
		result = a4;
		*((_WORD*)v5 + 62) = (_WORD)a4;
		*((_WORD*)v5 + 63) = (_WORD)a4;
		*((float*)v5 + 20) = *(float*)&byte_587000[8 * (_DWORD)a4 + 194136] * *((float*)v5 + 136);
		*((float*)v5 + 21) = *(float*)&byte_587000[8 * (_DWORD)a4 + 194140] * *((float*)v5 + 136);
		*((float*)v5 + 20) = *(float*)(a1 + 80) + *((float*)v5 + 20);
		*((float*)v5 + 21) = *(float*)(a1 + 84) + *((float*)v5 + 21);
	}
	return result;
}

//----- (0053F4F0) --------------------------------------------------------
int __cdecl sub_53F4F0(int a1, _DWORD* a2) {
	int v2;              // esi
	int v4;              // eax
	int v5;              // eax
	int v6;              // ecx
	int v7;              // eax
	int v8;              // eax
	unsigned __int8 v9;  // al
	unsigned __int8 v10; // cl
	int v11[3];          // [esp+Ch] [ebp-Ch]

	v2 = a2[184];
	if (!*(_DWORD*)&byte_5D4594[2488732])
		*(_DWORD*)&byte_5D4594[2488732] = sub_4E3AA0((CHAR*)&byte_587000[280072]);
	if (*(_BYTE*)(v2 + 109) && !*(_BYTE*)(v2 + 108)) {
		sub_501960(222, a1, 0, 0);
		return 0;
	}
	if (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v2 + 104) <
	    (unsigned int)(*(_DWORD*)(v2 + 100) - 2 * sub_4E0960((int)a2)))
		return 0;
	if (*(_BYTE*)(a1 + 8) & 4) {
		v4 = *(_DWORD*)(a1 + 748);
		*(float*)&v11[1] = (double)*(int*)(*(_DWORD*)(v4 + 276) + 2284);
		*(float*)&v11[2] = (double)*(int*)(*(_DWORD*)(v4 + 276) + 2288);
		v5 = *(_DWORD*)(v4 + 288);
		if (v5) {
			v11[0] = v5;
			goto LABEL_13;
		}
	} else {
		v6 = *(_DWORD*)(a1 + 60);
		v11[1] = *(_DWORD*)(a1 + 56);
		v11[2] = v6;
	}
	v11[0] = a1;
LABEL_13:
	v7 = *(_DWORD*)(v2 + 92);
	*(_DWORD*)(v2 + 96) |= 4u;
	if (sub_4FD400(v7, a1, (_DWORD*)a1, a1, v11, 4)) {
		*(_DWORD*)(v2 + 104) = *(_DWORD*)&byte_5D4594[2598000];
		v8 = a2[2];
		if (!(v8 & 0x1000) || !(a2[3] & 0x4040000)) {
			v9 = *(_BYTE*)(v2 + 109);
			if (v9) {
				v10 = *(_BYTE*)(v2 + 108) - 1;
				*(_BYTE*)(v2 + 108) = v10;
				*(_DWORD*)(v2 + 112) = 100 * v10 / v9;
				if (*(_BYTE*)(a1 + 8) & 4)
					sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064),
						   a2, v10, v9);
			}
		}
	}
	return 1;
}

//----- (0053F670) --------------------------------------------------------
int __cdecl sub_53F670(int a1, int a2) {
	int v2;    // esi
	int v3;    // eax
	double v4; // st7
	float v6;  // [esp+0h] [ebp-38h]
	float v7;  // [esp+4h] [ebp-34h]
	float v8;  // [esp+28h] [ebp-10h]
	float v9;  // [esp+2Ch] [ebp-Ch]
	float v10; // [esp+30h] [ebp-8h]
	float v11; // [esp+34h] [ebp-4h]
	float v12; // [esp+3Ch] [ebp+4h]
	float v13; // [esp+3Ch] [ebp+4h]

	v2 = a1;
	v8 = 0.0;
	v3 = 8 * *(__int16*)(a1 + 124);
	v11 = *(float*)&byte_587000[v3 + 194136] * *(float*)(a1 + 176) * 1.5;
	v10 = *(float*)&byte_587000[v3 + 194140] * *(float*)(a1 + 176) * 1.5;
	do {
		v12 = sub_416030(12.0, 25.0);
		v9 = sub_416030(-2.0, 2.0) + v12 * *(float*)&byte_587000[8 * *(__int16*)(v2 + 124) + 194136];
		v13 = sub_416030(-2.0, 2.0) + v12 * *(float*)&byte_587000[8 * *(__int16*)(v2 + 124) + 194140];
		v7 = v10 + *(float*)(v2 + 60);
		v6 = v11 + *(float*)(v2 + 56);
		sub_54FD80(v6, v7, 1, 20, v9, v13, 0.0, 0);
		v4 = v8 + 1.0;
		v8 = v4;
	} while (v4 < 1.0);
	if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(a2 + 136)) > *(int*)&byte_5D4594[2649704]) {
		sub_501960(9, v2, 0, 0);
		*(_DWORD*)(a2 + 136) = *(_DWORD*)&byte_5D4594[2598000];
	}
	return 0;
}

//----- (0053F7C0) --------------------------------------------------------
int __cdecl sub_53F7C0(int a1, int a2) {
	int v2; // esi
	int v3; // ecx

	if (*(_BYTE*)(a1 + 8) & 4) {
		v2 = *(_DWORD*)(a2 + 736);
		v3 = *(_DWORD*)(v2 + 256);
		if ((*(_DWORD*)&byte_5D4594[2598000] - v3 > (unsigned int)(3 * *(_DWORD*)&byte_5D4594[2649704]) ||
		     !v3) &&
		    sub_537110(a1, a2) == 1) {
			sub_4DA2C0(a1, (const char*)v2, 1);
			*(_DWORD*)(v2 + 256) = *(_DWORD*)&byte_5D4594[2598000];
		}
	}
	return 1;
}

//----- (0053F830) --------------------------------------------------------
int __cdecl sub_53F830(int a1, int a2) {
	int v2; // esi
	int v3; // ebx
	int v4; // edi
	int v5; // ecx
	int v6; // eax
	int v7; // eax
	int v8; // edx

	v2 = a1;
	if (*(_BYTE*)(a1 + 8) & 4) {
		v3 = *(_DWORD*)(a1 + 748);
		v4 = *(_DWORD*)(a2 + 736);
		v5 = *(_DWORD*)(v4 + 256);
		if ((*(_DWORD*)&byte_5D4594[2598000] - v5 > (unsigned int)(3 * *(_DWORD*)&byte_5D4594[2649704]) ||
		     !v5) &&
		    sub_537110(a1, a2) == 1) {
			if (sub_4D75E0()) {
				v6 = sub_4E3CC0();
				v7 = sub_4D74F0(v6);
				v8 = *(_DWORD*)(v3 + 276);
				a1 = v7;
				sub_4DA0F0(*(unsigned __int8*)(v8 + 2064), 21, &a1);
			} else {
				sub_4DA2C0(v2, "GeneralPrint:WarpClosed", 1);
			}
			*(_DWORD*)(v4 + 256) = *(_DWORD*)&byte_5D4594[2598000];
		}
	}
	return 1;
}

//----- (0053F8E0) --------------------------------------------------------
int __cdecl sub_53F8E0(int a1, int a2) {
	int result; // eax

	if (!a2)
		return 1;
	if (!*(_DWORD*)(a2 + 732))
		return 1;
	result = sub_419E60(a1);
	if (result != 1)
		result = (*(int(__cdecl**)(int, int))(a2 + 732))(a1, a2);
	return result;
}

//----- (0053F930) --------------------------------------------------------
int __cdecl sub_53F930(int a1, int a2) {
	int v2;     // ebx
	int v3;     // esi
	int result; // eax

	if (!(*(_BYTE*)(a1 + 8) & 4))
		return 0;
	v2 = *(_DWORD*)(a1 + 748);
	v3 = sub_427010(*(const char**)(a2 + 736));
	if (nox_common_gameFlags_check_40A5C0(4096) && *(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251) != 2) {
		sub_4DA2C0(a1, "pickup.c:ObjectEquipClassFail", 0);
		return 0;
	}
	if (*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4 * v3 + 4244)) {
		sub_4DA2C0(a1, "objcoll.c:AlreadyHaveGuide", 0);
		result = 0;
	} else {
		sub_4FAE80_magic_plyrgide(a1, v3, 1);
		sub_4E5CC0(a2);
		result = 1;
	}
	return result;
}

//----- (0053F9E0) --------------------------------------------------------
int __cdecl sub_53F9E0(int a1, int a2) {
	unsigned __int8* v2; // ebx
	int v3;              // ebp
	int v4;              // edi
	int v5;              // ecx
	char v6;             // al

	v2 = *(unsigned __int8**)(a2 + 736);
	v3 = 0;
	v4 = *(_DWORD*)(a1 + 748);
	if (!(*(_BYTE*)(a1 + 8) & 4))
		return 0;
	v5 = *(_DWORD*)(v4 + 276);
	v6 = *(_BYTE*)(v5 + 2251);
	if (v6 != 1 && v6 != 2) {
		sub_4DA2C0(a1, "use.c:SpellRewardClassFail", 0);
	LABEL_7:
		sub_501960(925, a1, 2, *(_DWORD*)(a1 + 36));
		return 0;
	}
	if (sub_57AEA0(*(unsigned __int8*)(v5 + 2251), *v2)) {
		sub_4DA2C0(a1, "use.c:SpellRewardClassFail", 0);
		goto LABEL_7;
	}
	if (nox_common_gameFlags_check_40A5C0(6144) && !*(_DWORD*)(*(_DWORD*)(v4 + 276) + 4 * *v2 + 3696))
		v3 = 1;
	if (sub_4FB550_magic_plyrspel(a1, *v2, 1, v3, 0))
		sub_4E5CC0(a2);
	else
		sub_501960(925, a1, 2, *(_DWORD*)(a1 + 36));
	return 1;
}

//----- (0053FAE0) --------------------------------------------------------
int __cdecl sub_53FAE0(int a1, int a2) {
	unsigned __int8* v2; // ebx
	int v3;              // ebp
	int v4;              // edi
	int result;          // eax

	v2 = *(unsigned __int8**)(a2 + 736);
	v3 = 0;
	v4 = *(_DWORD*)(a1 + 748);
	if (!(*(_BYTE*)(a1 + 8) & 4))
		return 0;
	if (*(_BYTE*)(*(_DWORD*)(v4 + 276) + 2251)) {
		sub_4DA2C0(a1, "pickup.c:ObjectEquipClassFail", 0);
		sub_501960(925, a1, 2, *(_DWORD*)(a1 + 36));
		result = 0;
	} else {
		if (nox_common_gameFlags_check_40A5C0(6144) && !*(_DWORD*)(*(_DWORD*)(v4 + 276) + 4 * *v2 + 3696))
			v3 = 1;
		if (sub_4FB9C0_ability(a1, *v2, v3))
			sub_4E5CC0(a2);
		else
			sub_501960(925, a1, 2, *(_DWORD*)(a1 + 36));
		result = 1;
	}
	return result;
}

//----- (0053FBC0) --------------------------------------------------------
_DWORD* __cdecl sub_53FBC0(float* a1, int a2) {
	int v2;         // eax
	int v3;         // ebx
	float* v4;      // esi
	_DWORD* result; // eax
	_DWORD* v6;     // edi
	int v7;         // eax
	int v8;         // eax
	float v9;       // [esp+0h] [ebp-1Ch]
	float v10;      // [esp+4h] [ebp-18h]
	int* v11;       // [esp+24h] [ebp+8h]

	if (!*(_DWORD*)&byte_5D4594[2488736])
		sub_53FCA0();
	v2 = sub_509EA0(a2);
	v3 = 0;
	v4 = (float*)&byte_587000[88 * v2 + 280376];
	v11 = (int*)&byte_5D4594[44 * v2 + 2488740];
	do {
		result = sub_4E3450(*v11);
		v6 = result;
		if (!result)
			break;
		if (dword_5d4594_2650652) {
			if (nox_common_gameFlags_check_40A5C0(0x2000)) {
				v7 = v6[4];
				LOBYTE(v7) = v7 | 0x40;
				v6[4] = v7;
			}
		}
		v10 = v4[1] + a1[1];
		v9 = *v4 + *a1;
		sub_4DAA50((int)v6, 0, v9, v10);
		v8 = nox_common_randomInt_415FA0(10, 20);
		result = (_DWORD*)sub_511660(v6, *(_DWORD*)&byte_5D4594[2649704] * v8);
		++v3;
		v4 += 2;
		++v11;
	} while (v3 < 11);
	return result;
}

//----- (0053FCA0) --------------------------------------------------------
void sub_53FCA0() {
	int i;               // ebx
	unsigned __int8* v1; // edi
	char v2[32];         // [esp+Ch] [ebp-20h]

	for (i = 0; i < 9; ++i) {
		switch (i) {
		case 0:
			v1 = &byte_587000[281216];
			goto LABEL_11;
		case 1:
			v1 = &byte_587000[281220];
			goto LABEL_11;
		case 2:
			v1 = &byte_587000[281224];
			goto LABEL_11;
		case 3:
			v1 = &byte_587000[281228];
			goto LABEL_11;
		case 5:
			v1 = &byte_587000[281232];
			goto LABEL_11;
		case 6:
			v1 = &byte_587000[281236];
			goto LABEL_11;
		case 7:
			v1 = &byte_587000[281240];
			goto LABEL_11;
		case 8:
			v1 = &byte_587000[281244];
		LABEL_11:
			nox_sprintf(v2, "CorpseSkull%s", v1);
			*(_DWORD*)&byte_5D4594[44 * i + 2488740] = sub_4E3AA0(v2);
			nox_sprintf(v2, "CorpseRibCage%s", v1);
			*(_DWORD*)&byte_5D4594[44 * i + 2488744] = sub_4E3AA0(v2);
			nox_sprintf(v2, "CorpsePelvis%s", v1);
			*(_DWORD*)&byte_5D4594[44 * i + 2488748] = sub_4E3AA0(v2);
			nox_sprintf(v2, "CorpseLeftLowerLeg%s", v1);
			*(_DWORD*)&byte_5D4594[44 * i + 2488752] = sub_4E3AA0(v2);
			nox_sprintf(v2, "CorpseLeftUpperLeg%s", v1);
			*(_DWORD*)&byte_5D4594[44 * i + 2488756] = sub_4E3AA0(v2);
			nox_sprintf(v2, "CorpseLeftLowerArm%s", v1);
			*(_DWORD*)&byte_5D4594[44 * i + 2488760] = sub_4E3AA0(v2);
			nox_sprintf(v2, "CorpseLeftUpperArm%s", v1);
			*(_DWORD*)&byte_5D4594[44 * i + 2488764] = sub_4E3AA0(v2);
			nox_sprintf(v2, "CorpseRightLowerLeg%s", v1);
			*(_DWORD*)&byte_5D4594[44 * i + 2488768] = sub_4E3AA0(v2);
			nox_sprintf(v2, "CorpseRightUpperLeg%s", v1);
			*(_DWORD*)&byte_5D4594[44 * i + 2488772] = sub_4E3AA0(v2);
			nox_sprintf(v2, "CorpseRightLowerArm%s", v1);
			*(_DWORD*)&byte_5D4594[44 * i + 2488776] = sub_4E3AA0(v2);
			nox_sprintf(v2, "CorpseRightUpperArm%s", v1);
			*(_DWORD*)&byte_5D4594[44 * i + 2488780] = sub_4E3AA0(v2);
			break;
		default:
			continue;
		}
	}
	*(_DWORD*)&byte_5D4594[2488736] = 1;
}

//----- (0053FEA0) --------------------------------------------------------
void sub_53FEA0() { nox_srand(0x22E0u); }

//----- (0053FEB0) --------------------------------------------------------
void __cdecl sub_53FEB0(int a1) {
	int v1; // edi

	v1 = 0;
	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 4)
			v1 = *(_DWORD*)(a1 + 748);
		sub_4FEE90(a1);
		if (sub_4FF350(a1, 3))
			*(_WORD*)(a1 + 126) =
			    (unsigned __int8)(*(_BYTE*)(a1 + 124) + 4 * nox_common_randomInt_415FA0(-8, 8));
		if (v1)
			*(_BYTE*)(v1 + 236) = 0;
		sub_4FA020((_DWORD*)a1, 1);
		sub_4FF5B0(a1, 0);
		sub_4FF5B0(a1, 23);
		sub_4FEB10(67, a1);
		sub_4FC3C0(a1, 1, 1);
	}
}

//----- (0053FF40) --------------------------------------------------------
void __cdecl sub_53FF40(int a1) {
	int v1; // eax

	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 4) {
			v1 = *(_DWORD*)(a1 + 748);
			if (v1)
				*(_BYTE*)(v1 + 236) = 0;
		}
		sub_4FA020((_DWORD*)a1, 1);
		sub_4FE680(a1, 300.0);
		sub_517F90((float2*)(a1 + 56), 300.0, sub_53FFB0, a1);
		sub_4FF5B0(a1, 0);
		sub_4FF5B0(a1, 23);
		sub_4FEB10(67, a1);
		sub_4FC3C0(a1, 2, 1);
	}
}

//----- (0053FFB0) --------------------------------------------------------
int __cdecl sub_53FFB0(_DWORD* a1, _DWORD* a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // edx
	int v5[3];  // [esp+8h] [ebp-Ch]

	result = a1[2];
	if (result & 6 && !(a1[4] & 0x8020)) {
		if (result & 4) {
			result = a1[187];
			if (!result)
				return result;
			result = *(_DWORD*)(result + 276);
			if (!result)
				return result;
			if (!*(_BYTE*)(result + 2251))
				return result;
			result = *(_DWORD*)(result + 3680) & 1;
			if ((_BYTE)result == 1)
				return result;
		} else if (result & 2 && !(*(_BYTE*)(a1[187] + 1440) & 0x20)) {
			return result;
		}
		result = sub_419150((int)(a2 + 12), (int)(a1 + 12));
		if (!result) {
			result = sub_537110((int)a1, (int)a2);
			if (result) {
				v3 = a1[14];
				v4 = a1[15];
				v5[0] = (int)a1;
				v5[1] = v3;
				v5[2] = v4;
				result = sub_4FD400(55, (int)a2, a2, (int)a2, v5, 5);
			}
		}
	}
	return result;
}

//----- (00540070) --------------------------------------------------------
int __cdecl sub_540070(_DWORD* a1) {
	int result; // eax
	int v2;     // edi

	result = sub_4FA020(a1, 32);
	if (a1) {
		v2 = a1[187];
		result = sub_538890((int)a1);
		if (v2)
			*(_DWORD*)(v2 + 140) = 0;
	}
	return result;
}

//----- (005400B0) --------------------------------------------------------
void __cdecl sub_5400B0(_DWORD* a1, __int16 a2) {
	int v2; // edi

	if (a1) {
		v2 = a1[187];
		if (v2) {
			if (*(_BYTE*)(v2 + 88) == 5)
				sub_4FA020(a1, 13);
			sub_4FF380((int)a1, 31, a2, *(_DWORD*)(*(_DWORD*)(v2 + 276) + 3712));
			sub_4FC3C0((int)a1, 4, 1);
			sub_5281D0();
		}
	}
}

//----- (00540110) --------------------------------------------------------
void __cdecl sub_540110(int a1, __int16 a2) {
	if (a1) {
		sub_4FF380(a1, 21, a2, *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 3716));
		sub_4FC3C0(a1, 5, 1);
	}
}

//----- (00540150) --------------------------------------------------------
void sub_540150() { nox_srand(0x22E1u); }

//----- (00540160) --------------------------------------------------------
int __cdecl sub_540160(int a1, int a2, int a3, int a4, int a5, int a6) {
	int v6;     // ebp
	int v7;     // edi
	int v8;     // eax
	int result; // eax
	int v10;    // ebx
	int v11;    // edi
	float v12;  // edx
	double v13; // st7
	double v14; // st6
	double v15; // st6
	float* v16; // esi
	int* v17;   // ebx
	double v18; // st7
	int v19;    // eax
	int v20;    // eax
	int v21;    // eax
	int v22;    // eax
	float v23;  // [esp+0h] [ebp-30h]
	float v24;  // [esp+0h] [ebp-30h]
	float v25;  // [esp+14h] [ebp-1Ch]
	float2 v26; // [esp+18h] [ebp-18h]
	float4 a1a; // [esp+20h] [ebp-10h]
	int v28;    // [esp+40h] [ebp+10h]
	int v29;    // [esp+48h] [ebp+18h]

	v6 = a4;
	v25 = *(float*)(a4 + 176) + 4.0;
	if (!*(_DWORD*)&byte_5D4594[2489136])
		*(_DWORD*)&byte_5D4594[2489136] = sub_4E3AA0((CHAR*)&byte_587000[281532]);
	v23 = sub_419D70(&byte_587000[281548], a6 - 1);
	v28 = nox_float2int(v23);
	v7 = sub_4E7C80(a3, *(int*)&byte_5D4594[2489136]);
	v24 = sub_419D70(&byte_587000[281568], a6 - 1);
	v8 = nox_float2int(v24);
	if (v7 + v28 > v8)
		v28 = v8 - v7;
	if (v28) {
		v10 = 0;
		v29 = 0;
		if (v28 > 0) {
			v11 = a3;
			do {
				switch (v10) {
				case 0:
					v11 = *(__int16*)(v6 + 124);
					break;
				case 1:
					v11 = *(__int16*)(v6 + 124) - 16;
					break;
				case 2:
					v11 = *(__int16*)(v6 + 124) + 16;
					break;
				case 3:
					v11 = *(__int16*)(v6 + 124) - 32;
					break;
				case 4:
					v11 = *(__int16*)(v6 + 124) + 32;
					break;
				default:
					break;
				}
				if (v11 < 0)
					v11 += (unsigned int)(255 - v11) >> 8 << 8;
				if (v11 >= 256)
					v11 += -256 * ((unsigned int)v11 >> 8);
				v12 = *(float*)(v6 + 60);
				v13 = v25 * *(float*)&byte_587000[8 * v11 + 194136] + *(float*)(v6 + 56);
				v14 = v25 * *(float*)&byte_587000[8 * v11 + 194140];
				a1a.field_0 = *(float*)(v6 + 56);
				v15 = v14 + *(float*)(v6 + 60);
				a1a.field_4 = v12;
				a1a.field_C = v15;
				a1a.field_8 = v13 + *(float*)(v6 + 80);
				a1a.field_C = a1a.field_C + *(float*)(v6 + 84);
				if (sub_535250(&a1a, 0, 0, 5)) {
					v16 = (float*)sub_4E3810((CHAR*)&byte_587000[281616]);
					if (v16) {
						v17 = (int*)*((_DWORD*)v16 + 187);
						sub_4DAA50((int)v16, a3, a1a.field_8, a1a.field_C);
						v18 = sub_416030(0.80000001, 1.2) * v16[136];
						v16[136] = v18;
						v19 = 8 * (__int16)v11;
						*((_WORD*)v16 + 63) = v11;
						*((_WORD*)v16 + 62) = v11;
						v16[20] = v18 * *(float*)&byte_587000[v19 + 194136] * 0.1;
						v16[21] = v18 * *(float*)&byte_587000[v19 + 194140] * 0.1;
						v16[20] = v16[20] + *(float*)(v6 + 80);
						v16[21] = v16[21] + *(float*)(v6 + 84);
						if (*(_BYTE*)(v6 + 8) & 4) {
							v20 = *(_DWORD*)(v6 + 748);
							v26.field_0 = (double)*(int*)(*(_DWORD*)(v20 + 276) + 2284);
							v26.field_4 = (double)*(int*)(*(_DWORD*)(v20 + 276) + 2288);
							v21 = sub_540610(&v26, (int)v16, 32, 600.0, 0, a3);
						} else {
							v21 = sub_540610(0, (int)v16, 32, 600.0, 0, a3);
						}
						v17[1] = v21;
						v17[3] = a1;
						*v17 = a3;
						v10 = v29;
					}
				}
				v29 = ++v10;
			} while (v10 < v28);
		}
		v22 = sub_424800(a1, 0);
		sub_501960(v22, v6, 0, 0);
		result = 1;
	} else {
		sub_4DA2C0(a3, "mmissile.c:TooManyMissiles", 0);
		result = 0;
	}
	return result;
}

//----- (00540440) --------------------------------------------------------
int __cdecl sub_540440(int a1, int a2, int a3, int a4, int a5, int a6) {
	int v6;      // ebx
	int v7;      // eax
	int v8;      // esi
	int v9;      // eax
	int v10;     // ebp
	float v11;   // eax
	double v12;  // st7
	_DWORD* v13; // esi
	int* v14;    // edi
	int v15;     // eax
	float4 v17;  // [esp+Ch] [ebp-10h]
	float v18;   // [esp+2Ch] [ebp+10h]
	int v19;     // [esp+34h] [ebp+18h]

	v6 = a4;
	v7 = *(_DWORD*)&byte_5D4594[2489140];
	v18 = *(float*)(a4 + 176) + 4.0;
	if (!*(_DWORD*)&byte_5D4594[2489140]) {
		v7 = sub_4E3AA0((CHAR*)&byte_587000[281680]);
		*(_DWORD*)&byte_5D4594[2489140] = v7;
	}
	v8 = sub_4E7C80(a3, v7);
	if (v8 < (int)(__int64)sub_419D70(&byte_587000[281688], a6 - 1)) {
		v9 = (unsigned __int64)(__int64)sub_419D70(&byte_587000[281700], a6 - 1) - v8;
		if (v9 > 0) {
			v19 = v9;
			do {
				v10 = nox_common_randomInt_415FA0(0, 255);
				v11 = *(float*)(v6 + 60);
				v12 = v18 * *(float*)&byte_587000[8 * v10 + 194136] + *(float*)(v6 + 56);
				v17.field_0 = *(float*)(v6 + 56);
				v17.field_4 = v11;
				v17.field_8 = v12;
				v17.field_C = v18 * *(float*)&byte_587000[8 * v10 + 194140] + *(float*)(v6 + 60);
				if (sub_535250(&v17, 0, 0, 5)) {
					v13 = sub_4E3810((CHAR*)&byte_587000[281760]);
					if (v13) {
						v14 = (int*)v13[187];
						sub_4DAA50((int)v13, a3, v17.field_8, v17.field_C);
						*((_WORD*)v13 + 63) = v10;
						*((_WORD*)v13 + 62) = v10;
						v13[20] = 0;
						v13[21] = 0;
						v14[1] = sub_540610(0, (int)v13, 32, 600.0, 0, a3);
						*v14 = a3;
						v14[3] = a1;
						v13[39] = *(_DWORD*)(v6 + 56);
						v13[40] = *(_DWORD*)(v6 + 60);
						v14[5] = *(_DWORD*)&byte_5D4594[2598000] +
							 *(_DWORD*)&byte_5D4594[2649704] *
							     nox_common_randomInt_415FA0(30, 90);
						v14[6] = *(_DWORD*)&byte_5D4594[2598000];
					}
				}
				--v19;
			} while (v19);
		}
		v15 = sub_424800(a1, 0);
		sub_501960(v15, v6, 0, 0);
	}
	return 1;
}

//----- (00540610) --------------------------------------------------------
int __cdecl sub_540610(float2* a1, int a2, int a3, float a4, int a5, int a6) {
	int v6;     // ecx
	int v7;     // esi
	float v9;   // edx
	float v10;  // ecx
	float v11;  // edx
	float v12;  // edx
	int v13;    // ecx
	float v14;  // eax
	float4 v15; // [esp+10h] [ebp-38h]
	float4 a1a; // [esp+20h] [ebp-28h]
	int a3a[6]; // [esp+30h] [ebp-18h]

	if (a6) {
		if (*(_BYTE*)(a6 + 8) & 4) {
			if (a3 & 0x20) {
				v6 = *(_DWORD*)(a6 + 748);
				v7 = *(_DWORD*)(v6 + 288);
				if (v7) {
					if (sub_5330C0(a6, *(_DWORD*)(v6 + 288)) && (a5 == 1 || !a5 && a2 != v7))
						return v7;
				}
			}
		}
	}
	*(_DWORD*)&byte_5D4594[2489144] = a5;
	*(_DWORD*)&byte_5D4594[2489152] = 0;
	*(_DWORD*)&byte_5D4594[2489148] = 1287568416;
	if (a1) {
		if (a2) {
			v9 = *(float*)(a2 + 56);
			v10 = a1->field_0;
			v15.field_4 = *(float*)(a2 + 60);
			v15.field_0 = v9;
			v11 = a1->field_4;
			v15.field_8 = v10;
			v15.field_C = v11;
			if (sub_535250(&v15, 0, 0, 5)) {
				v12 = a1->field_4;
				a3a[3] = LODWORD(a1->field_0);
			LABEL_18:
				*(float*)&a3a[4] = v12;
				goto LABEL_19;
			}
			v13 = *(_DWORD*)(a2 + 60);
			a3a[3] = *(_DWORD*)(a2 + 56);
			a3a[4] = v13;
		} else {
			v14 = a1->field_4;
			a3a[3] = LODWORD(a1->field_0);
			*(float*)&a3a[4] = v14;
		}
	LABEL_19:
		a3a[1] = a2;
		a3a[0] = a3;
		*(float*)&a3a[2] = a4 * a4;
		a3a[5] = sub_4EC580(a2);
		a1a.field_0 = *(float*)&a3a[3] - a4;
		a1a.field_4 = *(float*)&a3a[4] - a4;
		a1a.field_8 = *(float*)&a3a[3] + a4;
		a1a.field_C = *(float*)&a3a[4] + a4;
		sub_517C10(&a1a, sub_540780, (int)a3a);
		return *(_DWORD*)&byte_5D4594[2489152];
	}
	if (a2) {
		v12 = *(float*)(a2 + 60);
		a3a[3] = *(_DWORD*)(a2 + 56);
		goto LABEL_18;
	}
	return 0;
}

//----- (00540780) --------------------------------------------------------
void __cdecl sub_540780(float* a1, int a2) {
	float* v2; // esi
	int v3;    // eax
	int v4;    // ebx
	int v5;    // eax
	double v6; // st7
	double v7; // st6
	int v8;    // eax
	int v9;    // edi
	float v10; // [esp+Ch] [ebp+4h]

	v2 = a1;
	if (*(_DWORD*)&byte_5D4594[2489144] || *(float**)(a2 + 4) != a1) {
		v3 = *((_DWORD*)a1 + 2);
		if (v3 & 0x20006) {
			if (!(v3 & 2) || (v4 = *((_DWORD*)a1 + 3), (v4 & 0x8000) == 0)) {
				if ((!(v3 & 4) || !(*(_BYTE*)(*(_DWORD*)(*((_DWORD*)a1 + 187) + 276) + 3680) & 1)) &&
				    !((_DWORD)a1[4] & 0x8020)) {
					if (!(v3 & 2) || (v5 = *((_DWORD*)a1 + 3), !(v5 & 0x4000))) {
						sub_4EC580((int)a1);
						if (!(*(_BYTE*)a2 & 0x20) || sub_5330C0(*(_DWORD*)(a2 + 4), (int)a1)) {
							v6 = *(float*)(a2 + 12) - a1[14];
							v7 = *(float*)(a2 + 16) - a1[15];
							v10 = v7 * v7 + v6 * v6;
							if (v10 <= (double)*(float*)(a2 + 8)) {
								v8 = *(_DWORD*)(a2 + 4);
								if (!v8 || sub_5370E0(v8, (int)v2, 0)) {
									v9 = *(_DWORD*)(a2 + 20);
									if ((!v9 || sub_5370E0(v9, (int)v2, 0)) &&
									    v10 < (double)*(
										      float*)&byte_5D4594[2489148]) {
										*(_DWORD*)&byte_5D4594[2489152] = v2;
										*(float*)&byte_5D4594[2489148] =
										    v7 * v7 + v6 * v6;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

//----- (005408A0) --------------------------------------------------------
BOOL __cdecl sub_5408A0(int a1) {
	int v1; // ecx

	v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 24 * (*(char*)(*(_DWORD*)(a1 + 748) + 544) + 23));
	return v1 >= 18 && v1 <= 20;
}

//----- (005408D0) --------------------------------------------------------
int __cdecl sub_5408D0(int a1) {
	int v1;      // ebx
	int v2;      // esi
	int* v3;     // edi
	_DWORD* v4;  // ebp
	int v5;      // eax
	float v7;    // [esp+0h] [ebp-240h]
	int v8;      // [esp+18h] [ebp-228h]
	int v9[137]; // [esp+1Ch] [ebp-224h]

	v1 = *(_DWORD*)(a1 + 748);
	v8 = 0;
	if (!(*(_DWORD*)(a1 + 16) & 0x1000000))
		return 0;
	if (!sub_534300(a1))
		return 0;
	if (*(_DWORD*)&byte_5D4594[2598000] < *(int*)(v1 + 1452))
		return 0;
	if (sub_5408A0(a1))
		return 0;
	*(_DWORD*)&byte_5D4594[2489156] = 0;
	v7 = sub_419D40(&byte_587000[281816]) * 0.5;
	sub_518170(a1 + 56, v7, sub_540B60, a1);
	if (!*(_DWORD*)&byte_5D4594[2489156])
		return 0;
	v2 = 1;
	v3 = v9;
	v4 = (_DWORD*)(v1 + 1492);
	do {
		if (*v4 & 0x8000000) {
			if (sub_424A50(v2, 16)) {
				*v3 = v2;
				++v3;
				++v8;
			}
		}
		++v2;
		++v4;
	} while (v2 < 137);
	if (!v8)
		return 0;
	v5 = nox_common_randomInt_415FA0(0, v8 - 1);
	sub_540A30(a1, v9[v5], a1);
	*(_DWORD*)(v1 + 1452) =
	    *(_DWORD*)&byte_5D4594[2598000] +
	    nox_common_randomInt_415FA0(*(unsigned __int16*)(v1 + 1448), *(unsigned __int16*)(v1 + 1450));
	return 1;
}
// 5408D0: using guessed type int var_224[137];

//----- (00540A30) --------------------------------------------------------
int* __cdecl sub_540A30(int a1, int a2, int a3) {
	int v3;      // esi
	int* v4;     // ebx
	int* result; // eax
	int* v6;     // eax
	int* v7;     // eax
	int* v8;     // eax
	int v9;      // edx
	int v10;     // [esp-8h] [ebp-14h]
	int v11;     // [esp+10h] [ebp+4h]

	v3 = a1;
	v10 = a1;
	v11 = *(_DWORD*)(a1 + 748);
	sub_50A260(v10, 61);
	if (sub_424A50(a2, 2)) {
		v4 = sub_50A260(v3, 41);
		if (v4)
			v4[1] = *(_DWORD*)&byte_5D4594[2598000] +
				nox_common_randomInt_415FA0(*(_DWORD*)&byte_5D4594[2649704] >> 1,
							    2 * *(_DWORD*)&byte_5D4594[2649704]);
		result = sub_50A260(v3, 20);
		if (result)
			goto LABEL_7;
	} else {
		result = sub_50A260(v3, 18);
		if (result) {
		LABEL_7:
			result[1] = a2;
			result[3] = a3;
			goto LABEL_8;
		}
	}
LABEL_8:
	if (a3 != v3) {
		result = (int*)sub_50A090(v3, 24);
		if (!result) {
			if (!sub_424A50(a2, 4)) {
				v6 = sub_50A260(v3, 26);
				if (v6)
					v6[1] = a3;
				v7 = sub_50A260(v3, 47);
				if (v7)
					v7[1] = a3;
			}
			v8 = sub_50A260(v3, 49);
			if (v8) {
				v9 = *(_DWORD*)(*(_DWORD*)(v11 + 484) + 212);
				v8[3] = a3;
				v8[1] = v9;
			}
			sub_50A260(v3, 40);
			result = sub_50A260(v3, 7);
			if (result) {
				result[1] = *(_DWORD*)(a3 + 56);
				result[2] = *(_DWORD*)(a3 + 60);
				result[3] = a3;
			}
		}
	}
	return result;
}

//----- (00540B60) --------------------------------------------------------
int __cdecl sub_540B60(int a1, int a2) {
	int result; // eax

	result = a1;
	if (*(_BYTE*)(a1 + 8) & 1 && *(_BYTE*)(a1 + 12) & 2) {
		result = a2;
		if (*(_DWORD*)(*(_DWORD*)(a1 + 748) + 4) == a2)
			*(_DWORD*)&byte_5D4594[2489156] = 1;
	}
	return result;
}

//----- (00540B90) --------------------------------------------------------
int __cdecl sub_540B90(int a1) {
	int v1;       // edi
	int v2;       // ebp
	int v3;       // esi
	int* v4;      // ebx
	_DWORD* v5;   // ebp
	int v6;       // esi
	int* v7;      // ebx
	int v8;       // ebp
	int v9;       // eax
	int v11;      // [esp+10h] [ebp-228h]
	int v12[137]; // [esp+14h] [ebp-224h]

	v1 = 0;
	v2 = *(_DWORD*)(a1 + 748);
	v11 = *(_DWORD*)(a1 + 748);
	if (!(*(_DWORD*)(a1 + 16) & 0x1000000) || !sub_534300(a1) ||
	    *(_DWORD*)&byte_5D4594[2598000] < *(int*)(v2 + 1460) || sub_5408A0(a1)) {
		return 0;
	}
	v3 = 1;
	v4 = v12;
	v5 = (_DWORD*)(v2 + 1492);
	do {
		if (*v5 & 0x10000000) {
			if (sub_424A50(v3, 16)) {
				*v4 = v3;
				++v1;
				++v4;
			}
		}
		++v3;
		++v5;
	} while (v3 < 137);
	if (!v1)
		return 0;
	v6 = 0;
	if (v1 > 0) {
		v7 = v12;
		while (1) {
			v8 = a1;
			if (sub_540CE0(a1, *v7))
				return 0;
			++v6;
			++v7;
			if (v6 >= v1)
				goto LABEL_17;
		}
	}
	v8 = a1;
LABEL_17:
	v9 = nox_common_randomInt_415FA0(0, v1 - 1);
	sub_540A30(v8, v12[v9], v8);
	*(_DWORD*)(v11 + 1460) =
	    *(_DWORD*)&byte_5D4594[2598000] +
	    nox_common_randomInt_415FA0(*(unsigned __int16*)(v11 + 1456), *(unsigned __int16*)(v11 + 1458));
	return 1;
}
// 540B90: using guessed type int var_224[137];

//----- (00540CE0) --------------------------------------------------------
BOOL __cdecl sub_540CE0(int a1, int a2) {
	int i;       // esi
	BOOL result; // eax

	for (i = 0; i < 32; ++i) {
		if (sub_424920(i) == a2)
			break;
	}
	if (i == 32)
		result = 0;
	else
		result = sub_4FF350(a1, i);
	return result;
}

//----- (00540D20) --------------------------------------------------------
BOOL __cdecl sub_540D20(int a1) { return a1 >= 75 && a1 <= 114; }

//----- (00540D40) --------------------------------------------------------
int __cdecl sub_540D40(int a1) {
	int v1; // esi

	v1 = sub_4FE930();
	if (!v1)
		return 0;
	while (!sub_540D20(*(_DWORD*)(v1 + 4)) || *(_DWORD*)(v1 + 16) != a1) {
		v1 = sub_4FE940(v1);
		if (!v1)
			return 0;
	}
	return 1;
}

//----- (00540D90) --------------------------------------------------------
int __cdecl sub_540D90(int a1, int a2) {
	int v2;       // ebp
	int v3;       // ebx
	int v4;       // esi
	int* v5;      // edi
	_DWORD* v6;   // ebx
	int v7;       // esi
	int v8;       // edi
	BYTE v9;      // eax
	int v11;      // [esp+10h] [ebp-22Ch]
	int v12;      // [esp+14h] [ebp-228h]
	int v13[137]; // [esp+18h] [ebp-224h]

	v2 = 0;
	v3 = *(_DWORD*)(a1 + 748);
	v12 = *(_DWORD*)(a1 + 748);
	if (*(_DWORD*)(a1 + 16) & 0x1000000 && sub_534300(a1) &&
	    *(_DWORD*)&byte_5D4594[2598000] >= *(int*)(v3 + 1476) && !sub_5408A0(a1)) {
		v4 = 1;
		v5 = v13;
		v11 = 1;
		v6 = (_DWORD*)(v3 + 1492);
		do {
			if (*v6 & 0x40000000 && sub_424A50(v4, 16)) {
				*v5 = v4;
				++v2;
				++v5;
				if (!sub_540D20(v4))
					v11 = 0;
			}
			++v4;
			++v6;
		} while (v4 < 137);
		if (v2) {
			while (1) {
				while (1) {
					v7 = nox_common_randomInt_415FA0(0, v2 - 1);
					v8 = v13[v7];
					if (sub_540D20(v13[v7]))
						break;
				LABEL_19:
					if (v7 >= 0) {
						sub_540A30(a1, v13[v7], a2);
						*(_DWORD*)(v12 + 1476) =
						    *(_DWORD*)&byte_5D4594[2598000] +
						    nox_common_randomInt_415FA0(*(unsigned __int16*)(v12 + 1472),
										*(unsigned __int16*)(v12 + 1474));
						return 1;
					}
				}
				if (sub_540D40(a1)) {
					if (v11)
						return 0;
				} else {
					v9 = sub_500D70(a1, v8 - 74);
					if (v9)
						goto LABEL_19;
					if (v11)
						return 0;
				}
			}
		}
	}
	return 0;
}
// 540E9A: variable 'v9' is possibly undefined
// 540D90: using guessed type int var_224[137];

//----- (00540F20) --------------------------------------------------------
int __cdecl sub_540F20(int a1, int a2) {
	int v2;      // edi
	int v3;      // esi
	int* v4;     // ebx
	_DWORD* v5;  // ebp
	int v6;      // eax
	int v8;      // [esp+8h] [ebp-228h]
	int v9[137]; // [esp+Ch] [ebp-224h]

	v8 = 0;
	v2 = *(_DWORD*)(a1 + 748);
	if (!(*(_DWORD*)(a1 + 16) & 0x1000000) || !sub_534300(a1) ||
	    *(_DWORD*)&byte_5D4594[2598000] < *(int*)(v2 + 1468) || sub_5408A0(a1)) {
		return 0;
	}
	v3 = 1;
	v4 = v9;
	v5 = (_DWORD*)(v2 + 1492);
	do {
		if (*v5 & 0x20000000) {
			if (sub_424A50(v3, 16)) {
				*v4 = v3;
				++v4;
				++v8;
			}
		}
		++v3;
		++v5;
	} while (v3 < 137);
	if (!v8)
		return 0;
	v6 = nox_common_randomInt_415FA0(0, v8 - 1);
	sub_540A30(a1, v9[v6], a2);
	*(_DWORD*)(v2 + 1468) =
	    *(_DWORD*)&byte_5D4594[2598000] +
	    nox_common_randomInt_415FA0(*(unsigned __int16*)(v2 + 1464), *(unsigned __int16*)(v2 + 1466));
	return 1;
}
// 540F20: using guessed type int var_224[137];

//----- (00541050) --------------------------------------------------------
int __cdecl sub_541050(int a1) {
	int v1;       // edi
	int v2;       // ebp
	int v3;       // esi
	int* v4;      // ebx
	_DWORD* v5;   // ebp
	int v6;       // esi
	int* v7;      // ebx
	int v8;       // ebp
	int v9;       // eax
	int v11;      // [esp+10h] [ebp-228h]
	int v12[137]; // [esp+14h] [ebp-224h]

	v1 = 0;
	v2 = *(_DWORD*)(a1 + 748);
	v11 = *(_DWORD*)(a1 + 748);
	if (!(*(_DWORD*)(a1 + 16) & 0x1000000) || !sub_534300(a1) ||
	    *(_DWORD*)&byte_5D4594[2598000] < *(int*)(v2 + 1484) || sub_5408A0(a1)) {
		return 0;
	}
	v3 = 1;
	v4 = v12;
	v5 = (_DWORD*)(v2 + 1492);
	do {
		if ((int)*v5 < 0) {
			if (sub_424A50(v3, 16)) {
				*v4 = v3;
				++v1;
				++v4;
			}
		}
		++v3;
		++v5;
	} while (v3 < 137);
	if (!v1)
		return 0;
	v6 = 0;
	if (v1 > 0) {
		v7 = v12;
		while (1) {
			v8 = a1;
			if (sub_540CE0(a1, *v7))
				return 0;
			++v6;
			++v7;
			if (v6 >= v1)
				goto LABEL_17;
		}
	}
	v8 = a1;
LABEL_17:
	v9 = nox_common_randomInt_415FA0(0, v1 - 1);
	sub_540A30(v8, v12[v9], v8);
	*(_DWORD*)(v11 + 1484) =
	    *(_DWORD*)&byte_5D4594[2598000] +
	    nox_common_randomInt_415FA0(*(unsigned __int16*)(v11 + 1480), *(unsigned __int16*)(v11 + 1482));
	return 1;
}
// 541050: using guessed type int var_224[137];

//----- (005411A0) --------------------------------------------------------
int __cdecl sub_5411A0(int a3) {
	int v1;              // edi
	int v2;              // edx
	_WORD* v3;           // ecx
	unsigned __int16 v4; // ax
	BOOL v6;             // eax
	double v7;           // st7
	float4 a1;           // [esp+8h] [ebp-10h]

	v1 = *(_DWORD*)(a3 + 748);
	if (!(*(_DWORD*)(a3 + 16) & 0x1000000) || !sub_534300(a3) || byte_5D4594[2598000] & 0x1F || sub_5408A0(a3))
		return 0;
	v2 = *(_DWORD*)(v1 + 1440);
	if (v2 & 0x800) {
		v3 = *(_WORD**)(a3 + 556);
		v4 = v3[2];
		if (v4) {
			if (*v3 < (unsigned int)(v4 >> 1)) {
				sub_540A30(a3, 41, a3);
				return 0;
			}
		}
	}
	if (!(v2 & 0x1000))
		return 0;
	v6 = nox_common_gameFlags_check_40A5C0(4096);
	*(_DWORD*)&byte_5D4594[2489160] = 0;
	v7 = (double)(v6 ? 640 : 250);
	a1.field_0 = *(float*)(a3 + 56) - v7;
	a1.field_4 = *(float*)(a3 + 60) - v7;
	a1.field_8 = v7 + *(float*)(a3 + 56);
	a1.field_C = v7 + *(float*)(a3 + 60);
	sub_517C10(&a1, sub_5412A0, a3);
	if (!*(_DWORD*)&byte_5D4594[2489160])
		return 0;
	sub_540A30(a3, 41, *(int*)&byte_5D4594[2489160]);
	return 1;
}

//----- (005412A0) --------------------------------------------------------
void __cdecl sub_5412A0(float* a1, int a2) {
	int v2; // eax

	if ((float*)a2 != a1 && !sub_5330C0(a2, (int)a1)) {
		if (*((_DWORD*)a1 + 139)) {
			v2 = *((_DWORD*)a1 + 4);
			if ((v2 & 0x8000) == 0) {
				if (sub_5370E0(a2, (int)a1, 0)) {
					if (**((_WORD**)a1 + 139) <
					    (unsigned int)(*(_WORD*)(*((_DWORD*)a1 + 139) + 4) >> 1))
						*(_DWORD*)&byte_5D4594[2489160] = a1;
				}
			}
		}
	}
}

//----- (00541300) --------------------------------------------------------
char __cdecl sub_541300(int a1, _DWORD* a2, int a3) {
	int v3; // edi
	int v4; // eax

	v3 = a2[187];
	if (*(_DWORD*)(v3 + 1440) & 0x20000)
		sub_4FAAF0(a2);
	sub_533CC0((int)a2, (float*)(a3 + 4));
	sub_4FDD20(a1, a2, (int*)a3);
	v4 = *(_DWORD*)(v3 + 1440);
	if (v4 & 0x20000)
		LOBYTE(v4) = sub_4FAAC0(a2);
	return v4;
}

//----- (00541360) --------------------------------------------------------
char __cdecl sub_541360(_DWORD* a1) {
	int v1;      // esi
	char result; // al

	v1 = a1[187];
	if (!*(_DWORD*)(v1 + 24 * *(char*)(v1 + 544) + 564) || (sub_5413B0(a1, 0), (result = *(_BYTE*)(v1 + 483)) != 0))
		result = sub_50A160((int)a1);
	return result;
}

//----- (005413B0) --------------------------------------------------------
char __cdecl sub_5413B0(_DWORD* a1, int a2) {
	int v2;    // ecx
	int* v3;   // edi
	int v4;    // eax
	int v5;    // eax
	int v6;    // ecx
	int v8[3]; // [esp+8h] [ebp-Ch]

	v2 = a1[187];
	v3 = (int*)(v2 + 24 * (*(char*)(v2 + 544) + 23));
	LOBYTE(v4) = *(_BYTE*)(v2 + 482);
	if (!(_BYTE)v4) {
		LOBYTE(v4) = *(_BYTE*)(v2 + 481);
		if ((unsigned __int8)v4 == *(_DWORD*)(*(_DWORD*)(v2 + 484) + 216)) {
			if (a2) {
				LOBYTE(v4) = a2 - 1;
				if (a2 != 1)
					return v4;
				v5 = v3[3];
				v6 = v3[4];
				v8[0] = 0;
				v8[1] = v5;
				v8[2] = v6;
			} else {
				v8[0] = v3[3];
				sub_541490((int)a1, (float*)v8[0], (float2*)&v8[1]);
			}
			v4 = sub_4FF350((int)a1, 29);
			if (!v4)
				LOBYTE(v4) = sub_541300(v3[1], a1, (int)v8);
		} else if ((_BYTE)v4 == 1) {
			v4 = sub_424300((int)a1);
			if (v4)
				LOBYTE(v4) = (unsigned int)sub_501960(*(_DWORD*)(v4 + 56), (int)a1, 0, 0);
		}
	}
	return v4;
}

//----- (00541490) --------------------------------------------------------
void __cdecl sub_541490(int a1, float* a2, float2* a3) {
	double v3; // st7
	float v4;  // [esp+4h] [ebp-14h]
	float v5;  // [esp+1Ch] [ebp+4h]
	float v6;  // [esp+1Ch] [ebp+4h]

	v5 = 1.0 - *(float*)(*(_DWORD*)(a1 + 748) + 1320);
	*a3 = *((float2*)a2 + 7);
	v4 = v5 + 1.0;
	v3 = sub_416030(v5, v4);
	a3->field_0 = a3->field_0 - v3 * a2[20] * 6.0;
	a3->field_4 = a3->field_4 - v3 * a2[21] * 6.0;
	v6 = v5 * 0.80000001 + 0.2;
	a3->field_0 = sub_416030(-60.0, 60.0) * v6 + a3->field_0;
	a3->field_4 = sub_416030(-60.0, 60.0) * v6 + a3->field_4;
}

//----- (00541560) --------------------------------------------------------
char __cdecl sub_541560(_DWORD* a1) {
	int v1;      // edi
	char result; // al

	v1 = a1[187];
	sub_5413B0(a1, 1);
	result = *(_BYTE*)(v1 + 483);
	if (result)
		result = sub_50A160((int)a1);
	return result;
}

//----- (00541590) --------------------------------------------------------
_DWORD* __cdecl sub_541590(int a1) {
	return sub_4FEB10(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 24 * *(char*)(*(_DWORD*)(a1 + 748) + 544) + 556), a1);
}

//----- (005415C0) --------------------------------------------------------
char __cdecl sub_5415C0(int a1) {
	sub_4FEB10(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 24 * *(char*)(*(_DWORD*)(a1 + 748) + 544) + 556), a1);
	return sub_50A160(a1);
}

//----- (005415F0) --------------------------------------------------------
char __cdecl sub_5415F0(_DWORD* a1) {
	char result; // al

	if (*(_DWORD*)(a1[187] + 24 * *(char*)(a1[187] + 544) + 564))
		result = sub_5413B0(a1, 0);
	else
		result = sub_50A160((int)a1);
	return result;
}

//----- (00541630) --------------------------------------------------------
char __cdecl sub_541630(int a1, int a2) {
	_DWORD* v2; // eax
	int v3;     // ecx

	v2 = (_DWORD*)(*(_DWORD*)(a1 + 748) + 24 * (*(char*)(*(_DWORD*)(a1 + 748) + 544) + 23));
	if (*v2 == 20) {
		v3 = v2[1];
		LOBYTE(v2) = a2;
		if (v3 == a2)
			LOBYTE(v2) = sub_50A160(a1);
	}
	return (char)v2;
}

//----- (00541670) --------------------------------------------------------
int __cdecl sub_541670(LPCSTR a1, LPCSTR lpExistingFileName, LPCSTR lpFileName) {
	FILE* v3;   // edi
	FILE* v4;   // esi
	int result; // eax
	int v6;     // ebp
	int v7;     // ebp
	FILE* v8;   // eax
	FILE* v9;   // ebx

	if (!a1)
		return 0;
	if (!lpExistingFileName)
		return 0;
	if (!lpFileName)
		return 0;
	v3 = fopen(a1, "rb");
	if (!v3)
		return 0;
	v4 = fopen(lpExistingFileName, "rb");
	if (!v4) {
		fclose(v3);
		return 0;
	}
	fseek(v3, 0, 2);
	v6 = ftell(v3);
	fseek(v3, 0, 0);
	if (v6) {
		fseek(v4, 0, 2);
		v7 = ftell(v4);
		fseek(v4, 0, 0);
		if (v7) {
			v8 = fopen(lpFileName, "w+b");
			v9 = v8;
			if (v8) {
				sub_5417C0(v3, v4, v8);
				fclose(v3);
				fclose(v4);
				fclose(v9);
				result = 1;
			} else {
				fclose(v3);
				fclose(v4);
				result = 0;
			}
		} else {
			fclose(v3);
			fclose(v4);
			DeleteFileA(lpFileName);
			MoveFileA(a1, lpFileName);
			result = 1;
		}
	} else {
		fclose(v3);
		fclose(v4);
		DeleteFileA(lpFileName);
		MoveFileA(lpExistingFileName, lpFileName);
		result = 1;
	}
	return result;
}

//----- (005417C0) --------------------------------------------------------
size_t __cdecl sub_5417C0(FILE* a1, FILE* a2, FILE* a3) {
	unsigned int v3; // kr04_4
	unsigned int v4; // kr08_4
	char v6[1024];   // [esp+10h] [ebp-400h]

	*(_DWORD*)&byte_5D4594[2489420] = 0;
	*(_DWORD*)&byte_5D4594[2489424] = 0;
	*(_DWORD*)&byte_5D4594[2489428] = 0;
	strcpy(v6, "SCRIPT03");
	v3 = strlen(v6) + 1;
	fread(v6, v3 - 1, 1u, a1);
	fread(v6, v3 - 1, 1u, a2);
	fwrite(v6, v3 - 1, 1u, a3);
	sub_5418C0(a1, a2, a3);
	sub_541A50(a1, a2, a3);
	strcpy(v6, "DONE");
	v4 = strlen(v6) + 1;
	fread(v6, v4 - 1, 1u, a1);
	fread(v6, v4 - 1, 1u, a2);
	return fwrite(v6, v4 - 1, 1u, a3);
}

//----- (005418C0) --------------------------------------------------------
int __cdecl sub_5418C0(FILE* a1, FILE* a2, FILE* a3) {
	int i;          // ebx
	int result;     // eax
	int j;          // edi
	size_t v6;      // [esp+10h] [ebp-1010h]
	int v7;         // [esp+14h] [ebp-100Ch]
	int v8;         // [esp+18h] [ebp-1008h]
	int v9;         // [esp+1Ch] [ebp-1004h]
	char v10[4096]; // [esp+20h] [ebp-1000h]

	strcpy((char*)v10, "STRG");
	v6 = strlen((const char*)v10);
	fread(v10, v6, 1u, a1);
	fread(v10, v6, 1u, a2);
	fwrite(v10, v6, 1u, a3);
	fread(&v8, 4u, 1u, a1);
	fread(&v7, 4u, 1u, a2);
	*(_DWORD*)&byte_5D4594[2489424] = v8;
	v9 = v8 + v7;
	fwrite(&v9, 4u, 1u, a3);
	for (i = 0; i < v8; ++i) {
		fread(&v6, 4u, 1u, a1);
		fread(v10, v6, 1u, a1);
		v10[v6] = 0;
		fwrite(&v6, 4u, 1u, a3);
		fwrite(v10, v6, 1u, a3);
	}
	result = v7;
	for (j = 0; j < v7; ++j) {
		fread(&v6, 4u, 1u, a2);
		fread(v10, v6, 1u, a2);
		v10[v6] = 0;
		fwrite(&v6, 4u, 1u, a3);
		fwrite(v10, v6, 1u, a3);
		result = v7;
	}
	return result;
}

//----- (00541A50) --------------------------------------------------------
FILE* __cdecl sub_541A50(FILE* a1, FILE* a2, FILE* a3) {
	unsigned int v3; // kr04_4
	FILE* result;    // eax
	int i;           // ebx
	int j;           // edi
	size_t v7;       // [esp+10h] [ebp-101Ch]
	char v8;         // [esp+14h] [ebp-1018h]
	char v9;         // [esp+18h] [ebp-1014h]
	int v10;         // [esp+1Ch] [ebp-1010h]
	int v11;         // [esp+20h] [ebp-100Ch]
	char v12;        // [esp+24h] [ebp-1008h]
	int v13;         // [esp+28h] [ebp-1004h]
	char v14[4096];  // [esp+2Ch] [ebp-1000h]

	strcpy((char*)v14, "CODE");
	v3 = strlen((const char*)v14) + 1;
	fread(v14, v3 - 1, 1u, a1);
	fread(v14, v3 - 1, 1u, a2);
	fwrite(v14, v3 - 1, 1u, a3);
	fread(&v11, 4u, 1u, a1);
	fread(&v10, 4u, 1u, a2);
	*(_DWORD*)&byte_5D4594[2489428] = v11;
	v13 = v10 + v11 - 2;
	fwrite(&v13, 4u, 1u, a3);
	result = sub_541E40(a1, a2, a3);
	for (i = 0; i < v11 - 2; result = (FILE*)(v11 - 2)) {
		v7 = 4;
		fread(&v14, 4u, 1u, a1);
		fwrite(v14, v7, 1u, a3);
		fread(&v7, 4u, 1u, a1);
		fread(v14, v7, 1u, a1);
		v14[v7] = 0;
		fwrite(&v7, 4u, 1u, a3);
		fwrite(v14, v7, 1u, a3);
		fread(&v12, 4u, 1u, a1);
		fwrite(&v12, 4u, 1u, a3);
		fread(&v8, 4u, 1u, a1);
		fwrite(&v8, 4u, 1u, a3);
		sub_541D80(a1, a3);
		v7 = 4;
		fread(v14, 4u, 1u, a1);
		fwrite(v14, v7, 1u, a3);
		fread(&v9, 4u, 1u, a1);
		fwrite(&v9, 4u, 1u, a3);
		sub_542380(a1, a3, 0);
		++i;
	}
	for (j = 0; j < v10 - 2; result = (FILE*)(v10 - 2)) {
		v7 = 4;
		fread(v14, 4u, 1u, a2);
		fwrite(v14, v7, 1u, a3);
		fread(&v7, 4u, 1u, a2);
		fread(v14, v7, 1u, a2);
		v14[v7] = 0;
		fwrite(&v7, 4u, 1u, a3);
		fwrite(v14, v7, 1u, a3);
		fread(&v12, 4u, 1u, a2);
		fwrite(&v12, 4u, 1u, a3);
		fread(&v8, 4u, 1u, a2);
		fwrite(&v8, 4u, 1u, a3);
		sub_541D80(a2, a3);
		v7 = 4;
		fread(v14, 4u, 1u, a2);
		fwrite(v14, v7, 1u, a3);
		fread(&v9, 4u, 1u, a2);
		fwrite(&v9, 4u, 1u, a3);
		sub_542380(a2, a3, 1);
		++j;
	}
	return result;
}

//----- (00541D80) --------------------------------------------------------
int __cdecl sub_541D80(FILE* a1, FILE* a2) {
	int v2;     // ebx
	int result; // eax
	int v4;     // [esp+Ch] [ebp-100Ch]
	char v5;    // [esp+10h] [ebp-1008h]
	char v6;    // [esp+14h] [ebp-1004h]
	char v7;    // [esp+18h] [ebp-1000h]

	fread(&v7, 4u, 1u, a1);
	v2 = 0;
	fwrite(&v7, 4u, 1u, a2);
	fread(&v4, 4u, 1u, a1);
	fwrite(&v4, 4u, 1u, a2);
	fread(&v5, 4u, 1u, a1);
	fwrite(&v5, 4u, 1u, a2);
	result = v4;
	if (v4 && v4 > 0) {
		do {
			fread(&v6, 4u, 1u, a1);
			fwrite(&v6, 4u, 1u, a2);
			result = v4;
			++v2;
		} while (v2 < v4);
	}
	return result;
}

//----- (00541E40) --------------------------------------------------------
FILE* __cdecl sub_541E40(FILE* a1, FILE* a2, FILE* a3) {
	size_t v4; // [esp+10h] [ebp-1034h]
	char v5;   // [esp+14h] [ebp-1030h]
	int i;     // [esp+18h] [ebp-102Ch]
	int v7;    // [esp+1Ch] [ebp-1028h]
	char v8;   // [esp+20h] [ebp-1024h]
	char v9;   // [esp+24h] [ebp-1020h]
	char v10;  // [esp+28h] [ebp-101Ch]
	int v11;   // [esp+2Ch] [ebp-1018h]
	int v12;   // [esp+30h] [ebp-1014h]
	int v13;   // [esp+34h] [ebp-1010h]
	int v14;   // [esp+38h] [ebp-100Ch]
	char v15;  // [esp+3Ch] [ebp-1008h]
	int v16;   // [esp+40h] [ebp-1004h]
	char v17;  // [esp+44h] [ebp-1000h]

	v4 = 4;
	fread(&v17, 4u, 1u, a1);
	fread(&v17, 4u, 1u, a2);
	fwrite(&v17, 4u, 1u, a3);
	fread(&v4, 4u, 1u, a1);
	fread(&v17, v4, 1u, a1);
	fread(&v4, 4u, 1u, a2);
	fread(&v17, v4, 1u, a2);
	fwrite(&v4, 4u, 1u, a3);
	fwrite(&v17, v4, 1u, a3);
	fread(&v9, 4u, 1u, a1);
	fread(&v9, 4u, 1u, a2);
	fwrite(&v9, 4u, 1u, a3);
	fread(&v8, 4u, 1u, a1);
	fread(&v8, 4u, 1u, a2);
	fwrite(&v8, 4u, 1u, a3);
	v4 = 4;
	fread(&v17, 4u, 1u, a1);
	fread(&v17, v4, 1u, a2);
	fwrite(&v17, v4, 1u, a3);
	fread(&v7, 4u, 1u, a1);
	fread(&v11, 4u, 1u, a2);
	v12 = v7 + v11;
	fwrite(&v12, 4u, 1u, a3);
	fread(&v10, 4u, 1u, a1);
	fread(&v10, 4u, 1u, a2);
	fwrite(&v10, 4u, 1u, a3);
	v4 = 4;
	fread(&v17, 4u, 1u, a1);
	fread(&v17, v4, 1u, a2);
	fwrite(&v17, v4, 1u, a3);
	fread(&v13, 4u, 1u, a1);
	fread(&v14, 4u, 1u, a2);
	fwrite(&v13, 4u, 1u, a3);
	fread(&v15, 4u, 1u, a1);
	fread(&v15, 4u, 1u, a2);
	fwrite(&v15, 4u, 1u, a3);
	v4 = 4;
	fread(&v17, 4u, 1u, a1);
	fread(&v17, v4, 1u, a2);
	fwrite(&v17, v4, 1u, a3);
	fread(&v4, 4u, 1u, a1);
	fread(&v17, v4, 1u, a1);
	fread(&v4, 4u, 1u, a2);
	fread(&v17, v4, 1u, a2);
	fwrite(&v4, 4u, 1u, a3);
	fwrite(&v17, v4, 1u, a3);
	fread(&v9, 4u, 1u, a1);
	fread(&v9, 4u, 1u, a2);
	fwrite(&v9, 4u, 1u, a3);
	fread(&v8, 4u, 1u, a1);
	fread(&v8, 4u, 1u, a2);
	fwrite(&v8, 4u, 1u, a3);
	v4 = 4;
	fread(&v17, 4u, 1u, a1);
	fread(&v17, v4, 1u, a2);
	fwrite(&v17, v4, 1u, a3);
	fread(&v7, 4u, 1u, a1);
	fread(&v11, 4u, 1u, a2);
	*(_DWORD*)&byte_5D4594[2489420] = v7;
	v12 = v11 + v7 - 4;
	fwrite(&v12, 4u, 1u, a3);
	fread(&v10, 4u, 1u, a1);
	fread(&v10, 4u, 1u, a2);
	fwrite(&v10, 4u, 1u, a3);
	for (i = 0; i < v7; ++i) {
		fread(&v5, 4u, 1u, a1);
		fwrite(&v5, 4u, 1u, a3);
	}
	fread(&v5, 4u, 1u, a2);
	fread(&v5, 4u, 1u, a2);
	fread(&v5, 4u, 1u, a2);
	fread(&v5, 4u, 1u, a2);
	for (i = 4; i < v11; ++i) {
		fread(&v5, 4u, 1u, a2);
		fwrite(&v5, 4u, 1u, a3);
	}
	v4 = 4;
	fread(&v17, 4u, 1u, a1);
	fread(&v17, v4, 1u, a2);
	fwrite(&v17, v4, 1u, a3);
	fread(&v13, 4u, 1u, a1);
	fread(&v14, 4u, 1u, a2);
	v16 = v14 + v13 - 4;
	fwrite(&v16, 4u, 1u, a3);
	sub_542380(a1, a3, 0);
	fseek(a3, -4, 1);
	return sub_542380(a2, a3, 1);
}

//----- (00542380) --------------------------------------------------------
FILE* __cdecl sub_542380(FILE* a1, FILE* a2, int a3) {
	FILE* v3;     // ebp
	FILE* v4;     // esi
	FILE* result; // eax
	FILE* v6;     // ebx
	int v7;       // edi
	FILE* v8;     // edi
	char v9;      // bl
	char v10;     // di
	char v11;     // di
	char v12;     // al
	FILE* v13;    // edi
	int (*v14)(); // eax
	FILE* v15;    // edi
	float v16;    // [esp+14h] [ebp+4h]

	v3 = a1;
	v4 = a2;
	while (2) {
		result = sub_542B70(v3);
		switch ((unsigned int)result) {
		case 0u:
			v6 = sub_542B70(v3);
			v7 = sub_542B70(v3);
			if (v6 && a3 && v7 >= 4)
				v7 = v7 + *(_DWORD*)&byte_5D4594[2489420] - 4;
			sub_542BB0(0, v4);
			goto LABEL_8;
		case 1u:
			v6 = sub_542B70(v3);
			v7 = sub_542B70(v3);
			if (v6 && a3 && v7 >= 4)
				v7 = v7 + *(_DWORD*)&byte_5D4594[2489420] - 4;
			sub_542BB0(1, v4);
			goto LABEL_8;
		case 2u:
			v6 = sub_542B70(v3);
			v7 = sub_542B70(v3);
			if (v6 && a3 && v7 >= 4)
				v7 = v7 + *(_DWORD*)&byte_5D4594[2489420] - 4;
			sub_542BB0(2, v4);
		LABEL_8:
			sub_542BB0((char)v6, v4);
			sub_542BB0(v7, v4);
			continue;
		case 3u:
			v8 = sub_542B70(v3);
			v9 = (unsigned int)sub_542B70(v3);
			if (v8 && a3)
				v9 += byte_5D4594[2489424];
			sub_542BB0(3, v4);
			sub_542BB0((char)v8, v4);
			sub_542BB0(v9, v4);
			continue;
		case 4u:
			v10 = (unsigned int)sub_542B70(v3);
			sub_542BB0(4, v4);
			sub_542BB0(v10, v4);
			continue;
		case 5u:
			v16 = sub_542B90(v3);
			sub_542BB0(5, v4);
			sub_542BD0(SLOBYTE(v16), v4);
			continue;
		case 6u:
			v11 = (unsigned int)sub_542B70(v3);
			if (a3)
				v11 += byte_5D4594[2489424];
			sub_542BB0(6, v4);
			sub_542BB0(v11, v4);
			continue;
		case 7u:
			sub_542BB0(7, v4);
			continue;
		case 8u:
			sub_542BB0(8, v4);
			continue;
		case 9u:
			sub_542BB0(9, v4);
			continue;
		case 0xAu:
			sub_542BB0(10, v4);
			continue;
		case 0xBu:
			sub_542BB0(11, v4);
			continue;
		case 0xCu:
			sub_542BB0(12, v4);
			continue;
		case 0xDu:
			sub_542BB0(13, v4);
			continue;
		case 0xEu:
			sub_542BB0(14, v4);
			continue;
		case 0xFu:
			sub_542BB0(15, v4);
			continue;
		case 0x10u:
			sub_542BB0(16, v4);
			continue;
		case 0x11u:
			sub_542BB0(17, v4);
			continue;
		case 0x12u:
			sub_542BB0(18, v4);
			continue;
		case 0x13u:
			sub_542BB0(19, v4);
			goto LABEL_44;
		case 0x14u:
			sub_542BB0(20, v4);
			goto LABEL_44;
		case 0x15u:
			sub_542BB0(21, v4);
		LABEL_44:
			v12 = (unsigned int)sub_542B70(v3);
			sub_542BB0(v12, v4);
			continue;
		case 0x16u:
		case 0x18u:
			sub_542BB0((char)result, v4);
			continue;
		case 0x17u:
			sub_542BB0(23, v4);
			continue;
		case 0x19u:
			sub_542BB0(25, v4);
			continue;
		case 0x1Au:
			sub_542BB0(26, v4);
			continue;
		case 0x1Bu:
			sub_542BB0(27, v4);
			continue;
		case 0x1Cu:
			sub_542BB0(28, v4);
			continue;
		case 0x1Du:
			sub_542BB0(29, v4);
			continue;
		case 0x1Eu:
			sub_542BB0(30, v4);
			continue;
		case 0x1Fu:
			sub_542BB0(31, v4);
			continue;
		case 0x20u:
			sub_542BB0(32, v4);
			continue;
		case 0x21u:
			sub_542BB0(33, v4);
			continue;
		case 0x22u:
			sub_542BB0(34, v4);
			continue;
		case 0x23u:
			sub_542BB0(35, v4);
			continue;
		case 0x24u:
			sub_542BB0(36, v4);
			continue;
		case 0x25u:
			sub_542BB0(37, v4);
			continue;
		case 0x26u:
			sub_542BB0(38, v4);
			continue;
		case 0x27u:
			sub_542BB0(39, v4);
			continue;
		case 0x28u:
			sub_542BB0(40, v4);
			continue;
		case 0x29u:
			sub_542BB0(41, v4);
			continue;
		case 0x2Au:
			sub_542BB0(42, v4);
			continue;
		case 0x2Bu:
			sub_542BB0(43, v4);
			continue;
		case 0x2Cu:
			sub_542BB0(44, v4);
			continue;
		case 0x2Du:
			sub_542BB0(45, v4);
			continue;
		case 0x2Eu:
			sub_542BB0(46, v4);
			continue;
		case 0x2Fu:
			sub_542BB0(47, v4);
			continue;
		case 0x30u:
			sub_542BB0(48, v4);
			continue;
		case 0x31u:
			sub_542BB0(49, v4);
			continue;
		case 0x32u:
			sub_542BB0(50, v4);
			continue;
		case 0x33u:
			sub_542BB0(51, v4);
			continue;
		case 0x34u:
			sub_542BB0(52, v4);
			continue;
		case 0x35u:
			sub_542BB0(53, v4);
			continue;
		case 0x36u:
			sub_542BB0(54, v4);
			continue;
		case 0x37u:
			sub_542BB0(55, v4);
			continue;
		case 0x38u:
			sub_542BB0(56, v4);
			continue;
		case 0x39u:
			sub_542BB0(57, v4);
			continue;
		case 0x3Au:
			sub_542BB0(58, v4);
			continue;
		case 0x3Bu:
			sub_542BB0(59, v4);
			continue;
		case 0x3Cu:
			sub_542BB0(60, v4);
			continue;
		case 0x3Du:
			sub_542BB0(61, v4);
			continue;
		case 0x3Eu:
			sub_542BB0(62, v4);
			continue;
		case 0x3Fu:
			sub_542BB0(63, v4);
			continue;
		case 0x40u:
			sub_542BB0(64, v4);
			continue;
		case 0x41u:
			sub_542BB0(65, v4);
			continue;
		case 0x42u:
			sub_542BB0(66, v4);
			continue;
		case 0x43u:
			sub_542BB0(67, v4);
			continue;
		case 0x44u:
			sub_542BB0(68, v4);
			continue;
		case 0x45u:
			v13 = sub_542B70(v3);
			if (a3) {
				v14 = *(int (**)()) & byte_587000[4 * (_DWORD)v13 + 245900];
				if (v14 == sub_512320 || v14 == sub_512350 || v14 == sub_512DE0 || v14 == sub_512E10 ||
				    v14 == sub_516970 || v14 == sub_514D90) {
					fseek(v4, -4, 1);
					fread(&a2, 4u, 1u, v4);
					fseek(v4, -4, 1);
					a2 = (FILE*)((char*)a2 + *(_DWORD*)&byte_5D4594[2489428] - 2);
					fwrite(&a2, 4u, 1u, v4);
					if (*(int (**)()) & byte_587000[4 * (_DWORD)v13 + 245900] == sub_514D90) {
						fseek(v4, -12, 1);
						fread(&a2, 4u, 1u, v4);
						fseek(v4, -4, 1);
						a2 = (FILE*)((char*)a2 + *(_DWORD*)&byte_5D4594[2489428] - 2);
						fwrite(&a2, 4u, 1u, v4);
						fseek(v4, 8, 1);
					}
				}
			}
			sub_542BB0(69, v4);
			sub_542BB0((char)v13, v4);
			continue;
		case 0x46u:
			v15 = sub_542B70(v3);
			if (a3)
				v15 = (FILE*)((char*)v15 + *(_DWORD*)&byte_5D4594[2489428] - 2);
			sub_542BB0(70, v4);
			sub_542BB0((char)v15, v4);
			continue;
		case 0x47u:
			sub_542BB0(71, v4);
			continue;
		case 0x48u:
			return (FILE*)sub_542BB0(72, v4);
		case 0x49u:
			sub_542BB0(73, v4);
			continue;
		default:
			return result;
		}
	}
}

//----- (00542B70) --------------------------------------------------------
FILE* __cdecl sub_542B70(FILE* a1) {
	fread(&a1, 4u, 1u, a1);
	return a1;
}

//----- (00542B90) --------------------------------------------------------
double __cdecl sub_542B90(FILE* a1) {
	fread(&a1, 4u, 1u, a1);
	return *(float*)&a1;
}

//----- (00542BB0) --------------------------------------------------------
size_t __cdecl sub_542BB0(char a1, FILE* a2) { return fwrite(&a1, 4u, 1u, a2); }

//----- (00542BD0) --------------------------------------------------------
size_t __cdecl sub_542BD0(char a1, FILE* a2) { return fwrite(&a1, 4u, 1u, a2); }

//----- (00542BF0) --------------------------------------------------------
char* __cdecl sub_542BF0(int a1, int a2, int a3) {
	int** v3;                 // eax
	int* v4;                  // ebx
	char* v5;                 // esi
	char* v6;                 // edx
	const char* v7;           // eax
	int v8;                   // esi
	char* v9;                 // eax
	CHAR* v10;                // eax
	int(__cdecl * v11)(int*); // eax
	const char* v12;          // edx
	char* v13;                // eax
	const char* v14;          // edx
	char* v15;                // eax
	const char* v16;          // edx
	const char* v17;          // edx
	char* v18;                // eax
	const char* v19;          // edx
	char* v20;                // eax
	const char* v21;          // edx
	char* v22;                // eax
	const char* v23;          // edx
	char* v24;                // eax
	const char* v25;          // edx
	char* v26;                // eax
	const char* v27;          // edx
	char* v28;                // eax
	const char* v29;          // edx
	char* v30;                // eax
	const char* v31;          // edx
	char* v32;                // eax
	const char* v33;          // edx
	const char* v34;          // edx
	const char* v35;          // eax
	char* v36;                // eax
	const char* v37;          // eax
	char* v38;                // eax
	const char* v39;          // eax
	char* v40;                // eax
	const char* v41;          // eax
	char* result;             // eax
	char* i;                  // ebx
	char* v44;                // [esp-14h] [ebp-28h]
	char* v45;                // [esp-14h] [ebp-28h]
	char* v46;                // [esp-14h] [ebp-28h]
	char* v47;                // [esp-14h] [ebp-28h]
	int v48;                  // [esp+10h] [ebp-4h]

	v3 = (int**)sub_5049D0();
	v48 = (int)v3;
	if (v3) {
		while (1) {
			v4 = *v3;
			if (((*v3)[4] & 0x80000000) == 0x80000000) {
				if (*v4) {
					v5 = sub_543620(*v4, a1);
					v6 = (char*)realloc((LPVOID)*v4, strlen(v5) + 1);
					*v4 = (int)v6;
					strcpy(v6, v5);
				}
				v7 = (const char*)sub_508CB0(v4, 14);
				if (v7) {
					v8 = a3;
					if (strlen(v7)) {
						v9 = sub_5435C0((int)v7, a1, a2, a3);
						sub_509120(v4, 14, v9);
					}
				} else {
					v8 = a3;
				}
				v10 = (CHAR*)sub_4E39D0((int)v4);
				v11 = *(int(__cdecl**)(int*))(sub_4E3B60(v10) + 212);
				if (v11 == sub_4F4E50) {
					v12 = (const char*)sub_508CB0(v4, 1);
					if (strlen(v12)) {
						v13 = sub_5435C0((int)v12, a1, a2, v8);
						sub_509120(v4, 1, v13);
					}
					v14 = (const char*)sub_508CB0(v4, 2);
					if (strlen(v14)) {
						v15 = sub_5435C0((int)v14, a1, a2, v8);
						sub_509120(v4, 2, v15);
					}
					v16 = (const char*)sub_508CB0(v4, 0);
					if (strlen(v16)) {
						v44 = sub_5435C0((int)v16, a1, a2, v8);
						sub_509120(v4, 0, v44);
					}
				} else if (v11 == sub_528DB0) {
					v17 = (const char*)sub_508CB0(v4, 3);
					if (strlen(v17)) {
						v18 = sub_5435C0((int)v17, a1, a2, v8);
						sub_509120(v4, 3, v18);
					}
					v19 = (const char*)sub_508CB0(v4, 5);
					if (strlen(v19)) {
						v20 = sub_5435C0((int)v19, a1, a2, v8);
						sub_509120(v4, 5, v20);
					}
					v21 = (const char*)sub_508CB0(v4, 4);
					if (strlen(v21)) {
						v22 = sub_5435C0((int)v21, a1, a2, v8);
						sub_509120(v4, 4, v22);
					}
					v23 = (const char*)sub_508CB0(v4, 6);
					if (strlen(v23)) {
						v24 = sub_5435C0((int)v23, a1, a2, v8);
						sub_509120(v4, 6, v24);
					}
					v25 = (const char*)sub_508CB0(v4, 7);
					if (strlen(v25)) {
						v26 = sub_5435C0((int)v25, a1, a2, v8);
						sub_509120(v4, 7, v26);
					}
					v27 = (const char*)sub_508CB0(v4, 8);
					if (strlen(v27)) {
						v28 = sub_5435C0((int)v27, a1, a2, v8);
						sub_509120(v4, 8, v28);
					}
					v29 = (const char*)sub_508CB0(v4, 9);
					if (strlen(v29)) {
						v30 = sub_5435C0((int)v29, a1, a2, v8);
						sub_509120(v4, 9, v30);
					}
					v31 = (const char*)sub_508CB0(v4, 10);
					if (strlen(v31)) {
						v32 = sub_5435C0((int)v31, a1, a2, v8);
						sub_509120(v4, 10, v32);
					}
					v33 = (const char*)sub_508CB0(v4, 11);
					if (strlen(v33)) {
						v45 = sub_5435C0((int)v33, a1, a2, v8);
						sub_509120(v4, 11, v45);
					}
				} else if (v11 == sub_4F51D0) {
					v34 = (const char*)sub_508CB0(v4, 12);
					if (strlen(v34)) {
						v46 = sub_5435C0((int)v34, a1, a2, v8);
						sub_509120(v4, 12, v46);
					}
				} else if (v11 == sub_4F7130) {
					v35 = (const char*)sub_508CB0(v4, 15);
					if (v35 && strlen(v35)) {
						v36 = sub_5435C0((int)v35, a1, a2, v8);
						sub_509120(v4, 15, v36);
					}
					v37 = (const char*)sub_508CB0(v4, 16);
					if (v37 && strlen(v37)) {
						v38 = sub_5435C0((int)v37, a1, a2, v8);
						sub_509120(v4, 16, v38);
					}
					v39 = (const char*)sub_508CB0(v4, 18);
					if (v39 && strlen(v39)) {
						v40 = sub_5435C0((int)v39, a1, a2, v8);
						sub_509120(v4, 18, v40);
					}
					v41 = (const char*)sub_508CB0(v4, 17);
					if (v41 && strlen(v41)) {
						v47 = sub_5435C0((int)v41, a1, a2, v8);
						sub_509120(v4, 17, v47);
					}
				}
				v4[4] &= 0x7FFFFFFFu;
				v3 = (int**)v48;
			}
			v48 = sub_5049E0((int)v3);
			if (!v48)
				break;
			v3 = (int**)v48;
		}
	}
	result = (char*)sub_579860();
	for (i = result; result; i = result) {
		if (*((int*)i + 120) < 0) {
			if ((int)strlen(i + 16) > 0)
				strcpy(i + 16, sub_543620((int)(i + 16), a1));
			*((_DWORD*)i + 120) &= 0x7FFFFFFFu;
		}
		result = (char*)sub_579870((int)i);
	}
	return result;
}

//----- (00543110) --------------------------------------------------------
FILE* __cdecl sub_543110(LPCSTR lpExistingFileName, int2* a2) {
	int v2;                 // edx
	int v3;                 // eax
	char* v4;               // edi
	FILE* result;           // eax
	FILE* v6;               // ebx
	FILE* v7;               // ebp
	unsigned int v8;        // kr08_4
	int i;                  // esi
	int v10;                // esi
	int v11;                // edi
	size_t v12;             // [esp+10h] [ebp-101Ch]
	int v13;                // [esp+14h] [ebp-1018h]
	int v14;                // [esp+18h] [ebp-1014h]
	int v15;                // [esp+1Ch] [ebp-1010h]
	int j;                  // [esp+20h] [ebp-100Ch]
	char v17;               // [esp+24h] [ebp-1008h]
	char v18;               // [esp+28h] [ebp-1004h]
	char v19[2048];         // [esp+2Ch] [ebp-1000h]
	char NewFileName[2048]; // [esp+82Ch] [ebp-800h]

	sub_542BF0(*(int*)&byte_5D4594[3835312], a2->field_0, a2->field_4);
	v2 = *(_DWORD*)&byte_587000[282612];
	strcpy(NewFileName, (const char*)&byte_5D4594[3841580]);
	v3 = *(_DWORD*)&byte_587000[282616];
	v4 = &NewFileName[strlen(NewFileName)];
	*(_DWORD*)v4 = *(_DWORD*)&byte_587000[282608];
	*((_DWORD*)v4 + 1) = v2;
	*((_DWORD*)v4 + 2) = v3;
	CopyFileA(lpExistingFileName, NewFileName, 0);
	result = fopen(NewFileName, "rb");
	v6 = result;
	if (result) {
		v7 = fopen(lpExistingFileName, "w+b");
		if (v7) {
			strcpy((char*)v19, "SCRIPT03");
			v8 = strlen((const char*)v19) + 1;
			fread(v19, v8 - 1, 1u, v6);
			fwrite(v19, v8 - 1, 1u, v7);
			strcpy((char*)v19, "STRG");
			v12 = strlen((const char*)v19);
			fread(v19, v12, 1u, v6);
			fwrite(v19, v12, 1u, v7);
			fread(&v14, 4u, 1u, v6);
			fwrite(&v14, 4u, 1u, v7);
			for (i = 0; i < v14; ++i) {
				fread(&v12, 4u, 1u, v6);
				fread(v19, v12, 1u, v6);
				v19[v12] = 0;
				fwrite(&v12, 4u, 1u, v7);
				fwrite(v19, v12, 1u, v7);
			}
			strcpy((char*)v19, "CODE");
			v12 = strlen((const char*)v19);
			fread(v19, v12, 1u, v6);
			fwrite(v19, v12, 1u, v7);
			fread(&v15, 4u, 1u, v6);
			fwrite(&v15, 4u, 1u, v7);
			v10 = 0;
			for (j = 0; v10 < v15; j = v10) {
				v12 = 4;
				fread(v19, 4u, 1u, v6);
				fwrite(v19, v12, 1u, v7);
				fread(&v12, 4u, 1u, v6);
				fread(v19, v12, 1u, v6);
				v19[v12] = 0;
				if (v10 > 1) {
					sub_5435C0((int)&v19, *(int*)&byte_5D4594[3835312], a2->field_0, a2->field_4);
					strcpy((char*)&v19, (const char*)&byte_5D4594[2489164]);
					v10 = j;
					v12 = strlen((const char*)&v19);
				}
				fwrite(&v12, 4u, 1u, v7);
				fwrite(v19, v12, 1u, v7);
				fread(&v18, 4u, 1u, v6);
				fwrite(&v18, 4u, 1u, v7);
				fread(&v17, 4u, 1u, v6);
				fwrite(&v17, 4u, 1u, v7);
				sub_541D80(v6, v7);
				v12 = 4;
				fread(v19, 4u, 1u, v6);
				fwrite(v19, v12, 1u, v7);
				v11 = ftell(v7);
				fread(&v13, 4u, 1u, v6);
				fwrite(&v13, 4u, 1u, v7);
				sub_542380(v6, v7, 0);
				v13 = -4 - v11 + ftell(v7);
				fseek(v7, v11, 0);
				fwrite(&v13, 4u, 1u, v7);
				fseek(v7, v13, 1);
				++v10;
			}
			strcpy((char*)&v19, "DONE");
			v12 = strlen((const char*)&v19);
			fread(v19, v12, 1u, v6);
			fwrite(v19, v12, 1u, v7);
			fclose(v6);
			fclose(v7);
			result = (FILE*)DeleteFileA(NewFileName);
		} else {
			result = (FILE*)fclose(v6);
		}
	}
	return result;
}
// 543110: using guessed type CHAR NewFileName[2048];

//----- (005435C0) --------------------------------------------------------
char* __cdecl sub_5435C0(int a1, int a2, int a3, int a4) {
	nox_sprintf((char*)&byte_5D4594[2489164], "%s%%%d%%%d%%%d", a1, a2, a3, a4);
	strlen((const char*)&byte_5D4594[2489164]);
	strcpy((char*)&byte_5D4594[2489164], "ERROR_NAME_TOO_LONG!");
	return (char*)&byte_5D4594[2489164];
}

//----- (00543620) --------------------------------------------------------
char* __cdecl sub_543620(int a1, int a2) {
	nox_sprintf((char*)&byte_5D4594[2489164], "%s%%%d", a1, a2);
	strlen((const char*)&byte_5D4594[2489164]);
	strcpy((char*)&byte_5D4594[2489164], "ERROR_NAME_TOO_LONG!");
	return (char*)&byte_5D4594[2489164];
}

//----- (00543680) --------------------------------------------------------
int __cdecl sub_543680(float* a1) {
	int result; // eax
	float2 a2;  // [esp+0h] [ebp-30h]
	int2 v3;    // [esp+8h] [ebp-28h]
	int v4[8];  // [esp+10h] [ebp-20h]

	if (dword_5d4594_3835356 == 255)
		return 1;
	result = sub_4D3D90((float2*)a1, &a2);
	if (result) {
		v4[0] = *(_DWORD*)&byte_5D4594[3835340];
		*(_DWORD*)&byte_5D4594[3835352] = 1;
		v4[1] = *(_DWORD*)&byte_5D4594[3835348];
		v4[6] = dword_5d4594_3835356;
		v4[7] = *(_DWORD*)&byte_5D4594[3835360];
		v3.field_0 = (__int64)a2.field_0;
		v3.field_4 = (__int64)a2.field_4;
		result = sub_5437E0(&v3.field_0, (int)v4, 46);
		*(_DWORD*)&byte_5D4594[3835352] = 0;
	}
	return result;
}

//----- (00543720) --------------------------------------------------------
void __cdecl sub_543720(int a1, int a2, int a3, int a4) {
	int result; // eax
	int v5;     // ecx

	if (*(_DWORD*)&byte_5D4594[2489432] >= 500) {
		*(_DWORD*)&byte_5D4594[3807168] = 1;
	} else {
		result = 16 * *(_DWORD*)&byte_5D4594[2489432];
		v5 = *(_DWORD*)&byte_5D4594[2489432] + 1;
		*(_DWORD*)&byte_5D4594[result + 3807180] = a1;
		*(_DWORD*)&byte_5D4594[result + 3807184] = a2;
		*(_DWORD*)&byte_5D4594[result + 3807188] = a3;
		*(_DWORD*)&byte_5D4594[result + 3807192] = a4;
		*(_DWORD*)&byte_5D4594[2489432] = v5;
	}
}

//----- (00543770) --------------------------------------------------------
int __cdecl sub_543770(_DWORD* a1, _DWORD* a2, _DWORD* a3, _DWORD* a4) {
	int v4; // eax

	if (*(int*)&byte_5D4594[2489432] <= 0)
		return 0;
	v4 = *(_DWORD*)&byte_5D4594[2489432] - 1;
	*(_DWORD*)&byte_5D4594[2489432] = v4;
	*a1 = *(_DWORD*)&byte_5D4594[16 * v4 + 3807180];
	*a2 = *(_DWORD*)&byte_5D4594[16 * *(_DWORD*)&byte_5D4594[2489432] + 3807184];
	*a3 = *(_DWORD*)&byte_5D4594[16 * *(_DWORD*)&byte_5D4594[2489432] + 3807188];
	*a4 = *(_DWORD*)&byte_5D4594[16 * *(_DWORD*)&byte_5D4594[2489432] + 3807192];
	return 1;
}

//----- (005437E0) --------------------------------------------------------
BOOL __cdecl sub_5437E0(int* a1, int a2, int a3) {
	double v3;            // st7
	double v4;            // st6
	int v5;               // ebx
	double v6;            // st6
	int v7;               // edi
	int v8;               // esi
	int v9;               // edx
	int v10;              // ecx
	int v11;              // esi
	int v12;              // edx
	int v13;              // ebx
	int v14;              // ecx
	int v15;              // edx
	int v16;              // ebx
	unsigned __int8* v17; // edi
	int v18;              // edx
	int v19;              // eax
	int* v20;             // ecx
	int v21;              // edi
	int v23;              // [esp+Ch] [ebp-8h]
	float v24;            // [esp+10h] [ebp-4h]

	v3 = (double)*a1 + 11.5;
	v4 = (double)a1[1];
	v5 = (__int64)(v3 * 0.021739131);
	v23 = (__int64)(v3 * 0.021739131);
	v6 = v4 + 11.5;
	v24 = v6;
	v7 = (__int64)(v6 * 0.021739131);
	a1 = (int*)(__int64)(v6 * 0.021739131);
	v8 = (int)(__int64)v3 % 46;
	*(_DWORD*)&byte_5D4594[3821628] = 0;
	v9 = (__int64)v24 % 46;
	dword_5d4594_2487248 = 0;
	if (v5 <= 0 || v5 >= 127 || v7 <= 0 || v7 >= 127) {
		v11 = a3;
	} else if (v8 <= v9) {
		if (a3 - v8 <= v9) {
			v15 = ptr_5D4594_2650668[v5];
			v11 = *(_DWORD*)(v15 + 44 * v7 + 24);
			sub_51DD50(v5, v7, 2, *(_DWORD*)(v15 + 44 * v7 + 24));
		} else {
			v13 = v5 - 1;
			v14 = ptr_5D4594_2650668[v13];
			v11 = *(_DWORD*)(v14 + 44 * v7 + 4);
			sub_51DD50(v13, v7, 1, *(_DWORD*)(v14 + 44 * v7 + 4));
		}
	} else if (a3 - v8 <= v9) {
		v12 = ptr_5D4594_2650668[v5];
		v11 = *(_DWORD*)(v12 + 44 * v7 + 4);
		sub_51DD50(v5, v7, 1, *(_DWORD*)(v12 + 44 * v7 + 4));
	} else {
		v10 = ptr_5D4594_2650668[v5];
		v11 = *(_DWORD*)(v10 + 44 * v7 - 20);
		sub_51DD50(v5, v7 - 1, 2, *(_DWORD*)(v10 + 44 * v7 - 20));
	}
	v16 = 0;
	if (dword_5d4594_2487248 > 0) {
		v17 = &byte_5D4594[3815632];
		do {
			v18 = *((_DWORD*)v17 + 1);
			v19 = *((_DWORD*)v17 - 1);
			v20 = *(int**)v17;
			v23 = *((_DWORD*)v17 - 1);
			a1 = v20;
			a3 = v18;
			if (v18 & 2) {
				sub_51DD50(v19, (int)v20, 1, v11);
				sub_51DD50(v23, (int)a1 + 1, 1, v11);
				sub_51DD50(v23 - 1, (int)a1, 1, v11);
				sub_51DD50(v23 - 1, (int)a1 + 1, 1, v11);
			} else if (v18 & 1) {
				sub_51DD50(v19 + 1, (int)v20, 2, v11);
				sub_51DD50(v23 + 1, (int)a1 - 1, 2, v11);
				sub_51DD50(v23, (int)a1, 2, v11);
				sub_51DD50(v23, (int)a1 - 1, 2, v11);
			}
			++v16;
			v17 += 12;
		} while (v16 < *(int*)&dword_5d4594_2487248);
	}
	if (sub_51DE30(&v23, &a1, &a3)) {
		v21 = a2;
		do {
			if (a3 & 2) {
				sub_543BC0(v23, (int)a1, 1, v11, v21, 1);
				sub_543BC0(v23, (int)a1 + 1, 1, v11, v21, 4);
				sub_543BC0(v23 - 1, (int)a1, 1, v11, v21, 3);
				sub_543BC0(v23 - 1, (int)a1 + 1, 1, v11, v21, 6);
				sub_543BC0(v23, (int)a1 - 1, 2, v11, v21, 0);
				sub_543BC0(v23 + 1, (int)a1, 2, v11, v21, 2);
				sub_543BC0(v23 - 1, (int)a1, 2, v11, v21, 5);
				sub_543BC0(v23, (int)a1 + 1, 2, v11, v21, 7);
			} else if (a3 & 1) {
				sub_543BC0(v23 + 1, (int)a1, 2, v11, v21, 4);
				sub_543BC0(v23 + 1, (int)a1 - 1, 2, v11, v21, 1);
				sub_543BC0(v23, (int)a1, 2, v11, v21, 6);
				sub_543BC0(v23, (int)a1 - 1, 2, v11, v21, 3);
				sub_543BC0(v23, (int)a1 - 1, 1, v11, v21, 0);
				sub_543BC0(v23 + 1, (int)a1, 1, v11, v21, 2);
				sub_543BC0(v23 - 1, (int)a1, 1, v11, v21, 5);
				sub_543BC0(v23, (int)a1 + 1, 1, v11, v21, 7);
			}
		} while (sub_51DE30(&v23, &a1, &a3));
	}
	return *(_DWORD*)&byte_5D4594[3821628] == 0;
}

//----- (00543BC0) --------------------------------------------------------
void __cdecl sub_543BC0(int a1, int a2, int a3, int a4, int a5, int a6) {
	int v7; // ebx

	if (a1 > 0 && a1 < 127) {
		if (a2 > 0 && a2 < 127) {
			v7 = a3;
			if ((!(a3 & 1) || a2 != 1) && (!(a3 & 2) || a1 != 1)) {
				if (a3 & 2) {
					if (a4 == *(_DWORD*)((_DWORD)(ptr_5D4594_2650668[a1]) + 44 * a2 + 24))
						return;
					v7 = a3;
				}
				if (!(a3 & 1) || a4 != *(_DWORD*)((_DWORD)(ptr_5D4594_2650668[a1]) + 44 * a2 + 4)) {
					if (a5) {
						*(_DWORD*)(a5 + 28) = a6;
						sub_51DA70(a1, a2, a5, v7, 1);
					}
				}
			}
		}
	}
}

//----- (00543C50) --------------------------------------------------------
int __cdecl sub_543C50(_DWORD* a1, int a2, int a3, int a4, int a5, int a6) {
	_DWORD* v6;   // edi
	_DWORD* v7;   // esi
	_DWORD** v8;  // eax
	int result;   // eax
	_DWORD** v10; // eax
	int v11;      // ebx
	int v12;      // eax
	_DWORD* v13;  // ebx
	_DWORD** v14; // edi
	_DWORD* j;    // ebp
	_DWORD* v16;  // esi
	int v17;      // eax
	int v18;      // eax
	_DWORD* v19;  // esi
	int v20;      // eax
	int i;        // ecx
	int v22;      // [esp+24h] [ebp+14h]

	if (a2 == 255 || a4 == 255) {
		v19 = a1;
		v20 = a1[4];
		if (v20) {
			for (i = *(_DWORD*)(v20 + 16); i; i = *(_DWORD*)(i + 16)) {
				v19 = (_DWORD*)v20;
				v20 = i;
			}
			sub_4221E0(v20);
			v19[4] = 0;
		}
		return 1;
	}
	v6 = a1;
	if (*a1 == 255)
		return 1;
	v7 = a1;
	if (a6) {
		v10 = (_DWORD**)(a1 + 4);
		v11 = 0;
		if (!a1[4])
			goto LABEL_45;
		do {
			v7 = *v10;
			if (**v10 == a2 && v7[1] == a3 && v7[2] == a4 && sub_543E60((int)v7, a5))
				v11 = 1;
			v10 = (_DWORD**)(v7 + 4);
		} while (v7[4]);
		if (!v11) {
		LABEL_45:
			v12 = sub_543EB0(a4, a5);
			v7[4] = sub_422160(a2, a3, a4, v12);
			return 1;
		}
		while (1) {
			v13 = v6;
			v22 = 0;
			if (!v6[4])
				break;
			do {
				v13 = (_DWORD*)v13[4];
				if (*v13 == a2 && v13[1] == a3 && v13[2] == a4) {
					v14 = (_DWORD**)(v13 + 4);
					for (j = v13; j[4]; v14 = (_DWORD**)(j + 4)) {
						v16 = *v14;
						if (**v14 == a2 && v16[1] == a3 && (v17 = v16[2], v17 == a4) &&
						    (v18 = sub_411490(v17, v16[3]), sub_543E60((int)v13, v18))) {
							v22 = 1;
							*v14 = (_DWORD*)v16[4];
							sub_4221E0((int)v16);
						} else {
							j = v16;
						}
					}
					v6 = a1;
				}
			} while (v13[4]);
			if (!v22)
				return 1;
		}
		return 1;
	}
	v8 = (_DWORD**)(a1 + 4);
	if (a1[4]) {
		while (1) {
			v7 = *v8;
			if (**v8 == a2 && v7[1] == a3 && v7[2] == a4 && v7[3] == a5)
				break;
			v8 = (_DWORD**)(v7 + 4);
			if (!v7[4])
				goto LABEL_11;
		}
		result = 0;
	} else {
	LABEL_11:
		v7[4] = sub_422160(a2, a3, a4, a5);
		result = 1;
	}
	return result;
}

//----- (00543E60) --------------------------------------------------------
int __cdecl sub_543E60(int a1, int a2) {
	int v2; // ecx
	int v4; // eax

	v2 = a2 + 12 * sub_411490(*(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
	if (*(_DWORD*)&byte_587000[4 * v2 + 282736] == 255)
		return 0;
	v4 = sub_543EB0(*(_DWORD*)(a1 + 8), *(_DWORD*)&byte_587000[4 * v2 + 282736]);
	if (v4 != *(_DWORD*)(a1 + 12))
		*(_DWORD*)(a1 + 12) = v4;
	return 1;
}

//----- (00543EB0) --------------------------------------------------------
int __cdecl sub_543EB0(int a1, int a2) {
	int v2;     // esi
	int v3;     // edi
	int result; // eax

	v2 = byte_5D4594[60 * a1 + 2678400];
	v3 = byte_5D4594[60 * a1 + 2678401];
	if (v2 == 3 && v3 == byte_5D4594[60 * a1 + 2678400])
		return a2;
	result = a2;
	if (a2) {
		switch (a2) {
		case 1:
			result = nox_common_randomInt_415FA0(1, v2 - 2);
			break;
		case 2:
			result = v2 - 1;
			break;
		case 3:
			result = v2 + 2 * nox_common_randomInt_415FA0(0, v3 - 3);
			break;
		case 4:
			result = v2 + 2 * nox_common_randomInt_415FA0(0, v3 - 3) + 1;
			break;
		case 5:
			result = v2 + 2 * v3 - 4;
			break;
		case 6:
			result = nox_common_randomInt_415FA0(1, v2 - 2) + v2 + 2 * v3 - 4;
			break;
		case 7:
			result = 2 * (v2 + v3) - 5;
			break;
		default:
			result = a2 + 2 * (v2 + v3) - 12;
			break;
		}
	}
	return result;
}

//----- (00543FB0) --------------------------------------------------------
int __cdecl sub_543FB0(const char* a1) {
	int v1;        // ebp
	const char* i; // edi

	if (!a1)
		return -1;
	v1 = 0;
	if (*(int*)&dword_5d4594_251572 <= 0)
		return -1;
	for (i = (const char*)&byte_5D4594[2678348]; strcmp(i, a1); i += 60) {
		if (++v1 >= *(int*)&dword_5d4594_251572)
			return -1;
	}
	return v1;
}

//----- (00544020) --------------------------------------------------------
int __cdecl sub_544020(char* a1) {
	int v1;     // eax
	int result; // eax

	*(_DWORD*)&byte_5D4594[2489436] = 0;
	if (_strcmpi("NONE", a1)) {
		v1 = sub_543FB0(a1);
		result = sub_544070(v1);
	} else {
		dword_5d4594_3835356 = 255;
		result = 1;
	}
	return result;
}

//----- (00544070) --------------------------------------------------------
int __cdecl sub_544070(int a1) {
	if (a1 < 0 || a1 >= *(int*)&dword_5d4594_251572)
		return 0;
	dword_5d4594_3835356 = a1;
	*(_DWORD*)&byte_5D4594[2489436] = 1;
	return 1;
}

//----- (005440A0) --------------------------------------------------------
int __cdecl sub_5440A0(int a1) {
	if (!*(_DWORD*)&byte_5D4594[2489436])
		return 1;
	if (*(int*)&dword_5d4594_3835356 == -1 || a1 < 0 || a1 >= *(unsigned __int16*)&byte_5D4594[60 * a1 + 2678392])
		return 0;
	*(_DWORD*)&byte_5D4594[3835360] = a1;
	return 1;
}

//----- (005440F0) --------------------------------------------------------
int __cdecl sub_5440F0(int a1, signed int a2) {
	int v2;        // ebp
	int v3;        // ebx
	int v4;        // edi
	signed int v5; // eax
	int v6;        // eax
	int result;    // eax

	if (a1 < 0 || a1 >= 12 || *(int*)&dword_5d4594_3835356 == -1)
		return 0;
	v2 = *(_DWORD*)&byte_587000[4 * a1 + 283312];
	v3 = byte_5D4594[60 * dword_5d4594_3835356 + 2678401];
	v4 = byte_5D4594[60 * dword_5d4594_3835356 + 2678400];
	if (v4 != 3 || v3 != byte_5D4594[60 * dword_5d4594_3835356 + 2678400]) {
		switch (a1) {
		case 0:
		case 3:
		case 4:
			v2 = v4 + v2 - 3;
			break;
		case 5:
		case 8:
		case 9:
		case 10:
		case 11:
			v2 = v2 + 2 * (v3 + v4 - 4) - 4;
			break;
		case 6:
		case 7:
			v2 = v4 + 2 * v3 - 6 + v2 - 3;
			break;
		default:
			break;
		}
	}
	v5 = a2;
	if (a2 == -1) {
		v6 = sub_544240(*(int*)&dword_5d4594_3835356);
		if (a1 && a1 != 2 && a1 != 4 && a1 != 6)
			return sub_5440A0(v2);
		v5 = sub_526AC0(0, v6 - 1);
	}
	if (!v5)
		return sub_5440A0(v2);
	if (a1 != 6 && a1 != 2) {
		if ((!a1 || a1 == 4) && v5 <= v3 - 3)
			goto LABEL_24;
		return 0;
	}
	if (v5 > v4 - 3)
		return 0;
LABEL_24:
	switch (a1) {
	case 0:
	case 4:
		v2 += 2 * v5;
		return sub_5440A0(v2);
	case 2:
	case 6:
		result = sub_5440A0(v5 + v2);
		break;
	default:
		return sub_5440A0(v2);
	}
	return result;
}

//----- (00544240) --------------------------------------------------------
int __cdecl sub_544240(int a1) {
	int result; // eax

	if (a1 < 0 || a1 >= *(int*)&dword_5d4594_251572)
		result = 0;
	else
		result = byte_5D4594[60 * a1 + 2678400] - 2;
	return result;
}

//----- (00544270) --------------------------------------------------------
int __cdecl sub_544270(const char* a1) {
	int v1;        // ebp
	const char* i; // edi

	v1 = 0;
	if (*(int*)&dword_5d4594_251572 <= 0)
		return -1;
	for (i = (const char*)&byte_5D4594[2678348]; strcmp(i, a1); i += 60) {
		if (++v1 >= *(int*)&dword_5d4594_251572)
			return -1;
	}
	return v1;
}

//----- (005442D0) --------------------------------------------------------
int __cdecl sub_5442D0(float* a1) {
	int result; // eax
	float2 a2;  // [esp+0h] [ebp-8h]

	if (!*(_DWORD*)&byte_5D4594[2489436])
		return 1;
	result = sub_4D3D90((float2*)a1, &a2);
	if (result)
		result = sub_544310(&a2);
	return result;
}

//----- (00544310) --------------------------------------------------------
int __cdecl sub_544310(float2* a1) {
	double v1;  // st7
	double v2;  // st6
	int v3;     // esi
	int v4;     // edi
	int v5;     // ebp
	int v6;     // edx
	int result; // eax
	int v8[8];  // [esp+10h] [ebp-20h]
	float v9;   // [esp+34h] [ebp+4h]

	*(_DWORD*)&byte_5D4594[3835352] = 1;
	v1 = a1->field_0 + 11.5;
	v8[1] = *(_DWORD*)&byte_5D4594[3835348];
	v8[0] = *(_DWORD*)&byte_5D4594[3835340];
	v8[2] = 0;
	LOBYTE(v8[5]) = 0;
	v8[3] = -1;
	v8[4] = -1;
	v8[6] = dword_5d4594_3835356;
	v8[7] = *(_DWORD*)&byte_5D4594[3835360];
	v2 = a1->field_4 + 11.5;
	v3 = (__int64)(v1 * 0.021739131);
	v9 = v2;
	v4 = (__int64)(v2 * 0.021739131);
	v5 = (int)(__int64)v1 % 46;
	v6 = (__int64)v9 % 46;
	if (*(_DWORD*)&byte_5D4594[3835340] == 255)
		result = sub_51D9C0(v3, v4, v5, v6, 0);
	else
		result = sub_51D9C0(v3, v4, v5, v6, (int)v8);
	*(_DWORD*)&byte_5D4594[3835352] = 0;
	return result;
}

//----- (005443F0) --------------------------------------------------------
char __cdecl sub_5443F0(int a1) {
	int v1;    // esi
	int v2;    // edi
	int v4;    // ebx
	double v5; // st7
	double v6; // st7
	double v7; // st6
	double v8; // st5
	double v9; // st6
	char v10;  // al
	BOOL v11;  // ebp
	int* v12;  // ebx
	int* v13;  // edi
	float v14; // [esp+Ch] [ebp+4h]

	v1 = a1;
	v2 = *(_DWORD*)(a1 + 748);
	if (!sub_534320(a1))
		return sub_50A160(a1);
	v4 = v2 + 24 * (*(char*)(v2 + 544) + 23);
	if (sub_50A040(a1) == 3) {
		v5 = *(float*)(v2 + 1316) * 3.0;
		v14 = v5;
		v6 = v5 + 30.0;
		v7 = *(float*)(v4 + 4) - *(float*)(v1 + 56);
		v8 = *(float*)(v4 + 8) - *(float*)(v1 + 60);
		v9 = v8 * v8 + v7 * v7;
		if (v9 >= v14 * v14) {
			if (v9 > v6 * v6)
				sub_534750(v1);
		} else {
			sub_534780(v1);
		}
	}
	if (sub_50D5A0(v1) == 1) {
		v10 = *(_BYTE*)(v2 + 284);
		v11 = v10 == 2 || v10 == 1 && *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v2 + 540) <
						  (unsigned int)(5 * *(_DWORD*)&byte_5D4594[2649704]);
		if (v10 == 1)
			*(_DWORD*)(v2 + 540) = *(_DWORD*)&byte_5D4594[2598000];
		if (!v10 && !sub_547F10() && !*(_DWORD*)(v4 + 12)) {
			sub_533CC0(v1, (float*)(v4 + 4));
			sub_50A160(v1);
		}
		if (v11) {
			v12 = sub_50A260(v1, 41);
			if (v12)
				v12[1] = *(_DWORD*)&byte_5D4594[2598000] +
					 nox_common_randomInt_415FA0(2 * *(_DWORD*)&byte_5D4594[2649704],
								     4 * *(_DWORD*)&byte_5D4594[2649704]);
			sub_50A260(v1, 29);
			*(_DWORD*)(v2 + 1440) |= 0x200000u;
		}
		if (*(_BYTE*)(v2 + 284)) {
			v13 = sub_50A260(v1, 1);
			if (v13)
				v13[1] = *(_DWORD*)&byte_5D4594[2598000] +
					 nox_common_randomInt_415FA0(*(_DWORD*)&byte_5D4594[2649704] >> 1,
								     *(int*)&byte_5D4594[2649704]);
		}
	}
	return sub_534030(v1);
}

//----- (005445C0) --------------------------------------------------------
char __cdecl sub_5445C0(int* a1) {
	int v1;  // edi
	int v2;  // eax
	int* v3; // eax
	int v4;  // ecx

	v1 = a1[187];
	if (!sub_5343C0((int)a1) && !sub_534390((int)a1) || (v2 = sub_545E60(a1)) == 0) {
		if (sub_534390((int)a1)) {
			if (*(_DWORD*)(v1 + 1196)) {
				v3 = sub_50A260((int)a1, 15);
				if (v3) {
					v4 = *(_DWORD*)(v1 + 1196);
					v3[1] = *(_DWORD*)(v4 + 56);
					v3[2] = *(_DWORD*)(v4 + 60);
					v3[3] = *(_DWORD*)&byte_5D4594[2598000];
				}
			}
		}
		LOBYTE(v2) = sub_5443F0((int)a1);
	}
	return v2;
}

//----- (00544640) --------------------------------------------------------
void __cdecl sub_544640(int a1) {
	float* v1;      // esi
	int v2;         // edi
	double v3;      // st7
	double v4;      // st6
	long double v5; // st6
	double v6;      // st6
	float v7;       // [esp+Ch] [ebp-4h]
	float v8;       // [esp+14h] [ebp+4h]

	v1 = (float*)a1;
	v2 = *(_DWORD*)(a1 + 748);
	if (sub_534320(a1)) {
		if (!sub_4FF350(a1, 3) && !sub_4FF350(a1, 5) && !sub_4FF350(a1, 28)) {
			v3 = *(float*)(v2 + 24 * (*(char*)(v2 + 544) + 23) + 4) - *(float*)(a1 + 56);
			v4 = *(float*)(v2 + 24 * (*(char*)(v2 + 544) + 23) + 8) - *(float*)(a1 + 60);
			v7 = v4;
			v5 = sqrt(v4 * v7 + v3 * v3) + 0.000099999997;
			v8 = v5;
			if (v5 >= 8.0) {
				v6 = *(float*)(*(_DWORD*)(v2 + 484) + 96) * v1[136];
				v1[136] = v6;
				v1[22] = v6 * v3 / v8;
				v1[23] = v7 * v1[136] / v8;
			} else {
				sub_50A160((int)v1);
			}
		}
	} else {
		sub_50A160(a1);
	}
}

//----- (00544740) --------------------------------------------------------
int __cdecl sub_544740(int a1) { return sub_534750(a1); }

//----- (00544750) --------------------------------------------------------
int __cdecl sub_544750(int a1) { return sub_534780(a1); }

//----- (00544760) --------------------------------------------------------
char __cdecl sub_544760(int a1) {
	int v1;    // esi
	int v2;    // eax
	int v3;    // ebx
	int v4;    // eax
	int v5;    // eax
	double v6; // st7
	double v7; // st6
	int v8;    // eax
	int v9;    // eax
	int v10;   // ebx
	int v11;   // eax

	v1 = *(_DWORD*)(a1 + 748);
	if (sub_534320(a1)) {
		v3 = v1 + 24 * (*(char*)(v1 + 544) + 23);
		v4 = *(_DWORD*)(v1 + 1196);
		if (v4) {
			*(_DWORD*)(v3 + 4) = *(_DWORD*)(v4 + 56);
			*(_DWORD*)(v3 + 8) = *(_DWORD*)(v4 + 60);
			v5 = *(_DWORD*)(v1 + 1196);
			v6 = *(float*)(v5 + 56) - *(float*)(a1 + 56);
			v7 = *(float*)(v5 + 60) - *(float*)(a1 + 60);
			if (*(float*)(v1 + 1356) * *(float*)(v1 + 1356) > v7 * v7 + v6 * v6 &&
			    (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v1 + 280)) >
				*(_DWORD*)&byte_5D4594[2649704] >> 1) {
				*(_DWORD*)(v1 + 8) = 0;
			}
			if (sub_534300(a1) && !sub_4FF350(a1, 29) && !sub_534400(a1) && !sub_534440(a1)) {
				v8 = sub_50A0D0(a1, 6) ? sub_541050(a1) : sub_540B90(a1);
				if (!v8 && sub_5370E0(a1, *(_DWORD*)(v1 + 1196), 0))
					sub_540F20(a1, *(_DWORD*)(v1 + 1196));
			}
		}
		v9 = *(_DWORD*)&byte_5D4594[2598000];
		if (*(_DWORD*)(v1 + 8) && *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v1 + 280) >
					      (unsigned int)(2 * *(_DWORD*)&byte_5D4594[2649704])) {
			*(_DWORD*)(v1 + 8) = 0;
			v9 = *(_DWORD*)&byte_5D4594[2598000];
		}
		if (*(_DWORD*)(v1 + 8) || (unsigned int)(v9 - *(_DWORD*)(v1 + 280)) <= 0xA ||
		    (v10 = v3 + 4, v11 = sub_50CA00(v1 + 12, 32, a1, (float*)v10), *(_DWORD*)(v1 + 8) = v11,
		     *(_DWORD*)(v1 + 280) = *(_DWORD*)&byte_5D4594[2598000], *(_DWORD*)(v1 + 268) = 0, v11 > 1)) {
			if (sub_50D3B0((float*)a1))
				*(_DWORD*)(v1 + 8) = 0;
			LOBYTE(v2) = sub_534030(a1);
		} else {
			*(_DWORD*)v10 = *(_DWORD*)(a1 + 56);
			v2 = *(_DWORD*)(a1 + 60);
			*(_DWORD*)(v10 + 4) = v2;
		}
	} else {
		LOBYTE(v2) = sub_50A160(a1);
	}
	return v2;
}

//----- (00544920) --------------------------------------------------------
int __cdecl sub_544920(int a1) { return sub_534750(a1); }

//----- (00544930) --------------------------------------------------------
int __cdecl sub_544930(int a1) { return sub_534780(a1); }

//----- (00544940) --------------------------------------------------------
int __cdecl sub_544940(int a1) { return sub_534780(a1); }

//----- (00544950) --------------------------------------------------------
char __cdecl sub_544950(int a1) { return sub_5443F0(a1); }

//----- (00544960) --------------------------------------------------------
char __cdecl sub_544960(int a1) {
	unsigned int v1; // eax

	v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 24 * *(char*)(*(_DWORD*)(a1 + 748) + 544) + 556);
	if (v1 <= *(int*)&byte_5D4594[2598000])
		LOBYTE(v1) = sub_50A160(a1);
	return v1;
}

//----- (00544990) --------------------------------------------------------
char __cdecl sub_544990(int a1) {
	int v1;      // eax
	int v2;      // esi
	int v3;      // ecx
	char result; // al

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(_DWORD*)(v1 + 548);
	v3 = *(_DWORD*)(v1 + 24 * *(char*)(v1 + 544) + 556);
	result = byte_5D4594[2598000];
	if (*(_DWORD*)&byte_5D4594[2598000] > (unsigned int)(v2 + v3))
		result = sub_50A160(a1);
	return result;
}

//----- (005449D0) --------------------------------------------------------
int* __cdecl sub_5449D0(int a1) {
	int* result; // eax

	*(_DWORD*)(*(_DWORD*)(a1 + 748) + 1304) = 1062501089;
	result = sub_50A260(a1, 10);
	if (result) {
		result[1] = 0;
		*((_BYTE*)result + 12) = -128;
	}
	return result;
}

//----- (00544A00) --------------------------------------------------------
int __cdecl sub_544A00(int a1, float a2) {
	*(_DWORD*)&byte_5D4594[2489452] = 0;
	*(_DWORD*)&byte_5D4594[2489444] = 1259902592;
	sub_517F90((float2*)(a1 + 56), a2, sub_544A40, a1);
	return *(_DWORD*)&byte_5D4594[2489452];
}

//----- (00544A40) --------------------------------------------------------
void __cdecl sub_544A40(int a1, int a2) {
	int v2;    // eax
	int v3;    // eax
	double v4; // st7
	double v5; // st6
	double v6; // st5

	if (*(_BYTE*)(a1 + 8) & 0x10) {
		v2 = *(_DWORD*)(a1 + 12);
		if (!(v2 & 4) && ((v2 & 0x80u) == 0 || sub_5347F0(a2))) {
			v3 = *(_DWORD*)(a1 + 12);
			if (!(v3 & 8) ||
			    v3 & 0x10 && nox_common_gameFlags_check_40A5C0(0x2000) && *(_BYTE*)(a2 + 12) & 0x10) {
				if (sub_5370E0(a2, a1, 0)) {
					v4 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
					v5 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
					v6 = v5 * v5 + v4 * v4;
					if (v6 < *(float*)&byte_5D4594[2489444]) {
						*(float*)&byte_5D4594[2489444] = v6;
						*(_DWORD*)&byte_5D4594[2489452] = a1;
					}
				}
			}
		}
	}
}

//----- (00544AE0) --------------------------------------------------------
int __cdecl sub_544AE0(int a1, float a2) {
	*(_DWORD*)&byte_5D4594[2489440] = 0;
	*(_DWORD*)&byte_5D4594[2489448] = 1259902592;
	sub_517F90((float2*)(a1 + 56), a2, sub_544B20, a1);
	return *(_DWORD*)&byte_5D4594[2489440];
}

//----- (00544B20) --------------------------------------------------------
void __cdecl sub_544B20(int a1, int a2) {
	double v2; // st7
	double v3; // st6
	double v4; // st5

	if (*(_DWORD*)(a1 + 8) & 0x1000000 && sub_57B3D0(a1, 0) && sub_5370E0(a2, a1, 0)) {
		v2 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
		v3 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
		v4 = v3 * v3 + v2 * v2;
		if (v4 < *(float*)&byte_5D4594[2489448]) {
			*(float*)&byte_5D4594[2489448] = v4;
			*(_DWORD*)&byte_5D4594[2489440] = a1;
		}
	}
}

//----- (00544B90) --------------------------------------------------------
char __cdecl sub_544B90(int a1) {
	int v1;    // ecx
	int v2;    // edi
	int v3;    // ecx
	double v4; // st7
	double v5; // st6
	int v6;    // edi

	v1 = *(_DWORD*)(a1 + 748);
	v2 = v1 + 24 * (*(char*)(v1 + 544) + 23);
	v3 = *(_DWORD*)(v1 + 24 * (*(char*)(v1 + 544) + 23) + 4);
	if (v3) {
		v4 = *(float*)(v3 + 56) - *(float*)(a1 + 56);
		v5 = *(float*)(v3 + 60) - *(float*)(a1 + 60);
		if (v5 * v5 + v4 * v4 < 5625.0) {
			if (sub_5370E0(a1, v3, 0)) {
				sub_4F36F0(a1, *(_DWORD*)(v2 + 4), 1, 1);
				v6 = *(_DWORD*)(v2 + 4);
				if (*(_BYTE*)(v6 + 12) & 0x10)
					sub_53F8E0(a1, v6);
			}
		}
	}
	return sub_50A160(a1);
}

//----- (00544C40) --------------------------------------------------------
int __cdecl sub_544C40(int a1) {
	int v1;                      // edi
	int v2;                      // eax
	int result = 0;              // eax
	int(__cdecl * result2)(int); // eax

	v1 = *(_DWORD*)(a1 + 748);
	v2 = sub_424300(a1);
	if (v2)
		sub_501960(*(_DWORD*)(v2 + 60), a1, 0, 0);
	sub_502490((int*)(v1 + 1264), 0, a1);
	result2 = *(int(__cdecl**)(int))(*(_DWORD*)(v1 + 484) + 228);
	if (result2)
		result = result2(a1);
	return result;
}

//----- (00544CA0) --------------------------------------------------------
void __cdecl sub_544CA0(_DWORD* a1) {
	int v1; // edi

	v1 = a1[187];
	if (sub_534A40((int)a1)) {
		if (*(_DWORD*)(v1 + 1440) & 0x80000)
			sub_544CE0(a1);
	}
}

//----- (00544CE0) --------------------------------------------------------
void __cdecl sub_544CE0(_DWORD* a1) {
	int v1; // eax
	int v2; // ecx
	int v3; // edi

	v1 = a1[127];
	if (v1 && *(_BYTE*)(v1 + 8) & 4) {
		v2 = a1[3];
		v3 = *(_DWORD*)(v1 + 748);
		LOBYTE(v2) = v2 & 0x7F;
		a1[3] = v2;
		sub_4D9200(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (int)a1);
		sub_417300(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (int)a1, 1);
	}
	sub_4EE500_obj_health((int)a1);
	sub_537AF0(a1 + 14, 1);
	sub_4E5CC0((int)a1);
}

//----- (00544D60) --------------------------------------------------------
char __cdecl sub_544D60(int a1) {
	char result; // al

	result = a1;
	if (*(_BYTE*)(*(_DWORD*)(a1 + 748) + 483))
		result = sub_50A160(a1);
	return result;
}

//----- (00544D80) --------------------------------------------------------
char __cdecl sub_544D80(_DWORD* a1) {
	int v1;                      // ebx
	void(__cdecl * v2)(_DWORD*); // eax
	int v3;                      // edi
	int v4;                      // eax
	int v5;                      // eax
	bool v6;                     // zf
	float v8;                    // [esp+0h] [ebp-10h]
	float v9;                    // [esp+0h] [ebp-10h]

	v1 = a1[187];
	if (a1[131] == 14 && a1[3] & 0x10000)
		sub_544E60((int)a1);
	a1[21] = 0;
	a1[20] = 0;
	a1[23] = 0;
	a1[22] = 0;
	a1[25] = 0;
	a1[24] = 0;
	v2 = *(void(__cdecl**)(_DWORD*))(*(_DWORD*)(v1 + 484) + 232);
	if (v2)
		v2(a1);
	if (sub_534A40((int)a1)) {
		v8 = sub_419D70(&byte_587000[283656], 0);
		v3 = nox_float2int(v8);
		v9 = sub_419D70(&byte_587000[283676], 1);
		v4 = nox_float2int(v9);
		*(_DWORD*)(v1 + 492) = nox_common_randomInt_415FA0(v3, v4);
		v5 = a1[4];
		LOBYTE(v5) = v5 | 0x10;
		a1[4] = v5;
	} else {
		v6 = !sub_534A40((int)a1);
		v5 = a1[4];
		if (v6)
			LOBYTE(v5) = v5 | 0x18;
		else
			LOBYTE(v5) = v5 | 0x10;
		a1[4] = v5;
	}
	return v5;
}

//----- (00544E60) --------------------------------------------------------
char __cdecl sub_544E60(int a1) {
	int v1;     // eax
	_DWORD* v2; // eax
	_DWORD* v3; // esi
	__int16 v4; // di

	v1 = *(_DWORD*)&byte_5D4594[2489456];
	if (!*(_DWORD*)&byte_5D4594[2489456]) {
		v1 = sub_4E3AA0((CHAR*)&byte_587000[283744]);
		*(_DWORD*)&byte_5D4594[2489456] = v1;
	}
	v2 = sub_4E3450(v1);
	v3 = v2;
	if (v2) {
		LOBYTE(v2) = sub_4DAA50((int)v2, 0, *(float*)(a1 + 56), *(float*)(a1 + 60));
		v4 = *(_WORD*)(a1 + 124);
		*((_WORD*)v3 + 63) = v4;
		*((_WORD*)v3 + 62) = v4;
	}
	return (char)v2;
}

//----- (00544EC0) --------------------------------------------------------
void __cdecl sub_544EC0(int a1) {
	_DWORD* v1; // edi
	int v2;     // eax

	v1 = *(_DWORD**)(a1 + 748);
	if (sub_534A40(a1)) {
		v2 = v1[360];
		if (v2 & 0x80000) {
			sub_5231B0((float*)(a1 + 56), 100);
			sub_544CE0((_DWORD*)a1);
		} else if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - v1[137]) > v1[123] && !(v2 & 0x100000)) {
			if (v1[299])
				sub_534AB0(a1);
		}
	} else {
		sub_4DA920((_DWORD*)a1);
		*(_DWORD*)(a1 + 744) = 0;
		sub_544F70(a1);
		if (*(_BYTE*)(v1[121] + 92) & 1)
			sub_4E5CC0(a1);
	}
}

//----- (00544F70) --------------------------------------------------------
int __cdecl sub_544F70(int a1) {
	int v1;             // ecx
	int result;         // eax
	int v3;             // edx
	_DWORD* v4;         // edx
	unsigned __int8 v5; // dl
	int v6;             // ecx
	_DWORD* v7;         // esi

	v1 = 0;
	result = *(_DWORD*)(a1 + 748);
	v3 = *(_DWORD*)(result + 296);
	*(_BYTE*)(result + 2094) = 0;
	if (v3 > 0) {
		v4 = (_DWORD*)(result + 300);
		do {
			*v4 = 0;
			++v1;
			++v4;
		} while (v1 < *(int*)(result + 296));
	}
	v5 = *(_BYTE*)(result + 1129);
	v6 = 0;
	*(_DWORD*)(result + 296) = 0;
	*(_DWORD*)(result + 364) = 0;
	if (v5 > 0u) {
		v7 = (_DWORD*)(result + 1132);
		do {
			*v7 = 0;
			++v6;
			++v7;
		} while (v6 < *(unsigned __int8*)(result + 1129));
	}
	*(_BYTE*)(result + 1129) = 0;
	*(_DWORD*)(result + 1196) = 0;
	return result;
}

//----- (00544FF0) --------------------------------------------------------
unsigned __int8* __cdecl sub_544FF0(int a1) {
	int v1; // edi

	v1 = *(_DWORD*)(a1 + 748);
	sub_50A160(a1);
	return sub_502490((int*)(v1 + 1288), 0, a1);
}
