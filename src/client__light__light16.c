#include "client__light__light16.h"
#include "client__draw__glowdraw.h"

#include "common__random.h"
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"
#include "GAME5_2.h"
#include "client__video__draw_common.h"
#include "client__io__win95__dxvideo.h"
#include "operators.h"

extern uint32_t dword_5d4594_3805492;
extern uint32_t dword_5d4594_1193180;
extern uint32_t dword_587000_142316;
extern uint32_t dword_5d4594_1193176;
extern uint32_t dword_587000_142328;
extern uint32_t dword_587000_154968;
extern uint32_t dword_5d4594_3805484;
extern uint32_t dword_5d4594_1193184;
extern uint32_t dword_5d4594_2650680;
extern uint32_t dword_5d4594_805836;
extern uint32_t dword_5d4594_3798800;
extern uint32_t dword_5d4594_2650676;
extern uint32_t dword_5d4594_3798808;
extern uint32_t dword_5d4594_3807156;
extern uint32_t dword_5d4594_3798836;
extern uint32_t dword_5d4594_3798804;
extern uint32_t dword_5d4594_3798820;
extern uint32_t dword_5d4594_3798824;
extern uint32_t dword_5d4594_3798840;
extern uint32_t dword_5d4594_3801780;
extern uint32_t dword_5d4594_3798796;
extern uint32_t dword_5d4594_3798844;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_video_dxFullScreen;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

extern unsigned char nox_arr_84EB20[280*57*4]; // TODO: the 4x factor is for high-res; figure out what 57 is
#ifndef NOX_CGO
nox_light_3 nox_arr2_853BC0[57*4][45*4] = {0}; // TODO: the 4x factor is for high-res; figure out what those values are

uint32_t nox_xxx_useMMX_587000_80800 = 1;

//----- (00485880) --------------------------------------------------------
signed int  sub_485880(uint32_t* a1, int* a2, int a3, signed int a4, char* a5) {
	signed int result; // eax
	int v6;            // esi
	int v7;            // edi
	const void* v8;    // edx
	char* v9;          // esi
	int v10;           // eax
	void* v11;         // edi
	int v12;           // ecx
	int v13;           // ebx
	int v14;           // edx
	int v15;           // ebp
	int v16;           // eax
	int v17;           // esi
	int v18;           // esi
	int v19;           // ecx
	unsigned int v20;  // [esp+10h] [ebp-Ch]
	int v21;           // [esp+14h] [ebp-8h]
	int v22;           // [esp+18h] [ebp-4h]
	signed int v23;    // [esp+20h] [ebp+4h]

	result = dword_5d4594_3798820;
	v6 = a1[1] - dword_5d4594_3798824;
	v7 = *a1 - dword_5d4594_3798820;
	if (v7 >= 0 && v6 >= 0 && v7 < *(int*)&dword_5d4594_3798800 && v6 < *(int*)&dword_5d4594_3798808) {
		v8 = *(const void**)&dword_5d4594_3798796;
		result = dword_5d4594_3798844;
		v9 = (char*)(v7 + dword_5d4594_3798796 + dword_5d4594_3798836 +
					 dword_5d4594_3798804 * (dword_5d4594_3798840 + v6));
		v21 = dword_5d4594_3798796;
		v20 = dword_5d4594_3798844;
		v22 = dword_5d4594_3798844 - dword_5d4594_3798796;
		dword_5d4594_1193184 = v9;
		dword_5d4594_1193180 = a5;
		if ((unsigned int)v9 >= *(int*)&dword_5d4594_3798844) {
			v9 -= dword_5d4594_3798844 - dword_5d4594_3798796;
			dword_5d4594_1193184 = v9;
		}
		if (nox_common_getEngineFlag(NOX_ENGINE_DISABLE_SOFT_LIGHTS)) {
			if ((unsigned int)&v9[a4] < *(int*)&dword_5d4594_3798844) {
				memcpy(a5, v9, a4);
			} else {
				v10 = dword_5d4594_3798844 - (uint32_t)v9;
				memcpy(a5, v9, dword_5d4594_3798844 - (uint32_t)v9);
				v11 = (void*)(dword_5d4594_1193180 + v10);
				result = a4 - v10;
				memcpy(v11, v8, result);
			}
		} else {
			v12 = *a1 - 23 * *a2 - dword_5d4594_2650676;
			v13 = 12 * a3;
			v14 = *((unsigned int*)&nox_arr_84EB20[4 + 280 * *a2 + 12 * a3]);
			dword_5d4594_1193176 = v14;
			v15 = *getMemU32Ptr(0x8529A0, 1020 + 4 * ((*((int*)&nox_arr_84EB20[284 + 280 * *a2 + 12 * a3]) - v14) >> 8));
			if (v12 <= 0) {
				v23 = 23;
				v16 = 23;
			} else {
				v16 = 23 - v12;
				dword_5d4594_1193176 = v12 * v15 + v14;
				v23 = 23 - v12;
			}
			if (v16 <= a4)
				goto LABEL_18;
			v23 = a4;
			while (1) {
				v16 = v23;
			LABEL_18:
				if ((unsigned int)&v9[v16] <= v20) {
					sub_485AE0(v16, v15);
				} else {
					v17 = (int)&v9[v16 - v20];
					sub_485AE0(v17, v15);
					dword_5d4594_1193184 = v21;
					sub_485AE0(v23 - v17, v15);
				}
				if (*(int*)&dword_5d4594_1193184 >= v20)
					dword_5d4594_1193184 -= v22;
				result = a4 - v23;
				a4 -= v23;
				if (a4 <= 0)
					break;
				v23 = 23;
				if (result < 23)
					v23 = result;
				v18 = *a2 + 1;
				v19 = v18;
				*a2 = v18;
				v9 = *(char**)&dword_5d4594_1193184;
				dword_5d4594_1193176 = *((unsigned int*)&nox_arr_84EB20[4 + 280 * v19 + v13]);
				v15 = *getMemU32Ptr(0x8529A0, 1020 + 4 * ((*((int*)&nox_arr_84EB20[284 + 280 * *a2 + v13]) - *(int*)&dword_5d4594_1193176) >> 8));
			}
		}
	}
	return result;
}

//----- (00481470) --------------------------------------------------------
int  sub_481470(int2* a1) {
	unsigned short v1; // dx
	int v2;              // eax
	int v3;              // esi
	int v4;              // ebx
	int v5;              // ecx
	int result;

	LOBYTE(v1) = 0;
	v2 = a1->field_4 + 45 * a1->field_0;
	HIBYTE(v1) = getMemByte(0x8531A0, + v2);
	v3 = v1;
	v4 = *getMemU32Ptr(0x8529A0, 1020 + 4 * (((getMemByte(0x8531A0, 1 + v2) << 8) - v1) >> 8));
	v5 = 0;
	do {
		v5 += 12;
		*getMemU32Ptr(0x5D4594, 2598276 + 280 * a1->field_0 + v5) = v3;
		v3 += v4;
	} while (v5 < 276);
	result = 35 * a1->field_0;
	*((unsigned int*)&nox_arr_84EB20[280 * a1->field_0]) = a1->field_4;
	return result;
}
#endif // NOX_CGO

//----- (00484F90) --------------------------------------------------------
void  sub_484F90(int a1) {
	int v1;               // ebx
	int v2;               // eax
	double v3;            // st7
	int v4;               // ecx
	int v5;               // edx
	int v6;               // eax
	int v7;               // ecx
	int v8;               // ebp
	int v9;               // edi
	int v10;              // esi
	int v11;              // eax
	int v12;              // ecx
	int v13;              // edx
	int v14;              // esi
	double v15;           // st7
	unsigned char* v16; // ebp
	int v17;              // edi
	double v18;           // st6
	double v19;           // st5
	double v20;           // st6
	double v21;           // st6
	int v22;              // edi
	int v23;              // esi
	int v24;              // eax
	int v25;              // ebp
	int v26;              // eax
	int v27;              // ebx
	float v28;            // [esp+0h] [ebp-50h]
	float v29;            // [esp+0h] [ebp-50h]
	float v30;            // [esp+0h] [ebp-50h]
	float v31;            // [esp+0h] [ebp-50h]
	float a5;             // [esp+14h] [ebp-3Ch]
	int a5a;              // [esp+14h] [ebp-3Ch]
	int v34;              // [esp+18h] [ebp-38h]
	int2 v35;             // [esp+1Ch] [ebp-34h]
	int2 a3;              // [esp+24h] [ebp-2Ch]
	float v37;            // [esp+2Ch] [ebp-24h]
	float v38;            // [esp+30h] [ebp-20h]
	float v39;            // [esp+34h] [ebp-1Ch]
	int2 a1a;             // [esp+38h] [ebp-18h]
	int a4;               // [esp+40h] [ebp-10h]
	int v42;              // [esp+44h] [ebp-Ch]
	int2 a2;              // [esp+48h] [ebp-8h]
	int v44;              // [esp+54h] [ebp+4h]
	int v45;              // [esp+54h] [ebp+4h]

	v1 = a1;
	if (sub_45A840((uint32_t*)a1) || *(uint32_t*)(a1 + 112) & 0x80000 && (v2 = *(uint32_t*)(a1 + 120), v2 & 0x1000000) &&
									   v2 & 4 && *(uint32_t*)(a1 + 144) > 0) {
		if (!nox_xxx_get_57AF20() || a1 == *getMemU32Ptr(0x852978, 8) ||
			*(int(**)(int*, int))(a1 + 300) == nox_thing_glow_orb_draw) {
			if (*(uint32_t*)(a1 + 120) & 0x20000000 && dword_5d4594_3801780 == 1) {
				a5 = nox_common_randomFloatXxx_416090(0.89999998, 1.1) * *(float*)(a1 + 140);
				v3 = (double)sub_484C60(a5);
			} else {
				v3 = (double)*(int*)(a1 + 144);
				a5 = *(float*)(a1 + 140);
			}
			*(float*)&v44 = v3;
			if (a5 > (double)*(float*)&dword_587000_154968) {
				if (a5 <= 31.0)
					v37 = a5;
				else
					v37 = 31.0;
				v4 = *(uint32_t*)(v1 + 16);
				v5 = *(uint32_t*)(v1 + 168);
				v6 = *(uint32_t*)(v1 + 12) - dword_5d4594_2650676;
				v39 = a5 * a5;
				v7 = v4 - dword_5d4594_2650680;
				a4 = v6;
				v42 = v7;
				if (v5 == 0xFFFF) {
					v38 = *(float*)&v44 * *(float*)&v44;
					v28 = ((double)a4 - *(float*)&v44) * 0.043478262 + 0.5;
					v8 = nox_float2int(v28);
					a5a = v8;
					if (v8 < 0) {
						a5a = 0;
						v8 = 0;
					}
					v29 = ((double)a4 + *(float*)&v44) * 0.043478262 + 0.5;
					v9 = nox_float2int(v29);
					v34 = v9;
					if (v9 > 56) {
						v34 = 56;
						v9 = 56;
					}
					v30 = ((double)v42 - *(float*)&v44) * 0.043478262 + 0.5;
					v10 = nox_float2int(v30);
					if (v10 < 0)
						v10 = 0;
					v31 = ((double)v42 + *(float*)&v44) * 0.043478262 + 0.5;
					v11 = nox_float2int(v31);
					v35.field_0 = v11;
					if (v11 > 44) {
						v35.field_0 = 44;
						v11 = 44;
					}
					a3.field_0 = v10;
					v12 = 23 * v10;
					a2.field_4 = 23 * v10;
					if (v10 <= v11) {
						v13 = 23 * v8;
						a1a.field_0 = 23 * v8;
						do {
							if (v8 <= v9) {
								v14 = a4 - v13;
								v45 = a4 - v13;
								v15 = (double)(v42 - v12) * (double)(v42 - v12);
								v16 = getMemAt(0x8531A0, + 40 * v8 + 5 * v8 + a3.field_0);
								v17 = v9 - a5a + 1;
								do {
									v18 = (double)v45 * (double)v45 + v15;
									if (v18 <= v38) {
										v19 =
											(*getMemFloatPtr(0x587000, 154996) + v37) /
											(*getMemFloatPtr(0x587000, 154992) * *getMemFloatPtr(0x587000, 154972) * v18 / v39 +
											 1.0);
										if (v19 > *getMemFloatPtr(0x587000, 154996)) {
											v20 = v19 - *getMemFloatPtr(0x587000, 154996);
											if (*(uint32_t*)(v1 + 172))
												v21 = (double)*v16 - v20;
											else
												v21 = v20 + (double)*v16;
											if (v21 >= 0.0) {
												if (v21 > 31.0)
													v21 = 31.0;
											} else {
												v21 = 0.0;
											}
											v12 = a2.field_4;
											v13 = a1a.field_0;
											v14 -= 23;
											*v16 = (long long)v21;
											v45 = v14;
										} else {
											v14 -= 23;
											v45 = v14;
										}
									} else {
										v14 -= 23;
										v45 = v14;
									}
									v16 += 45;
									--v17;
								} while (v17);
								v8 = a5a;
								v9 = v34;
								v11 = v35.field_0;
							}
							v12 += 23;
							a2.field_4 = v12;
							++a3.field_0;
						} while (a3.field_0 <= v11);
					}
				} else {
					a1a.field_0 = (v6 << 16) / 23;
					a1a.field_4 = (v7 << 16) / 23;
					v22 = (int)((long long)*(float*)&v44 << 16) / 23;
					v23 = sub_4C1C60(
						v22, 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * ((unsigned short)(*(uint16_t*)(v1 + 164) + 0x4000) >> 4)));
					v24 = sub_4C1C60(v22,
									 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * (*(unsigned short*)(v1 + 164) >> 4)));
					a3.field_0 = a1a.field_0 + v23;
					LOWORD(v23) = *(uint16_t*)(v1 + 164) + *(uint16_t*)(v1 + 166);
					a3.field_4 = a1a.field_4 + v24;
					v25 = sub_4C1C60(
						v22, 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * ((unsigned short)(v23 + 0x4000) >> 4)));
					v26 = sub_4C1C60(v22, 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * ((unsigned short)v23 >> 4)));
					LOWORD(v23) = *(uint16_t*)(v1 + 164) - *(uint16_t*)(v1 + 166);
					a2.field_4 = a1a.field_4 + v26;
					a2.field_0 = a1a.field_0 + v25;
					v27 = sub_4C1C60(
						v22, 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * ((unsigned short)(v23 + 0x4000) >> 4)));
					v35.field_4 =
						a1a.field_4 +
						sub_4C1C60(v22, 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * ((unsigned short)v23 >> 4)));
					v35.field_0 = a1a.field_0 + v27;
					sub_4854D0(&a1a, &a2, &a3, (int)&a4, a5);
					sub_4854D0(&a1a, &a3, &v35, (int)&a4, a5);
				}
			}
		}
	}
}

#ifndef NOX_CGO
//----- (00484E60) --------------------------------------------------------
void  sub_484E60(int a1) {
	uint32_t* v1;         // esi
	unsigned char v2; // al
	int v3;             // edx
	int v4;             // eax
	int v5;             // eax
	int v6;             // ecx
	int v7;             // edx
	int v8;             // [esp+8h] [ebp-18h]
	int v9;             // [esp+Ch] [ebp-14h]
	int4 v10;           // [esp+10h] [ebp-10h]

	v1 = (uint32_t*)a1;
	dword_5d4594_2650676 = 46 * ((*(uint32_t*)(a1 + 16) + 11) / 46 - 1) - 11;
	dword_5d4594_2650680 = 46 * ((*(uint32_t*)(a1 + 20) + 11) / 46) - 57;
	if (nox_common_getEngineFlag(NOX_ENGINE_DISABLE_SOFT_LIGHTS)) {
		memset(getMemAt(0x8531A0, 0), 0x1Fu, 0xA04u);
		*getMemU8Ptr(0x8531A0, 2564) = 31;
	} else {
		if (nox_xxx_get_57AF20()) {
			v8 = 50;
			a1 = 50;
			v9 = 50;
		} else {
			sub_434A10(&v9, &v8, &a1);
		}
		v2 = sub_434AA0(v9, v8, a1);
		LOBYTE(v3) = v2 >> 3;
		BYTE1(v3) = v2 >> 3;
		v4 = v3 << 16;
		LOWORD(v4) = v3;
		memset32(getMemAt(0x8531A0, 0), v4, 0x281u);
		*getMemU8Ptr(0x8531A0, 2564) = v3;
		v5 = v1[4];
		v10.field_0 = v5 - 100;
		v6 = v1[5];
		v10.field_4 = v6 - 100;
		v7 = v1[9];
		v10.field_8 = v1[8] + v5 + 100;
		v10.field_C = v7 + v6 + 100;
		nox_xxx_forEachSprite_49AB00(&v10, sub_484F90, (int)v1);
	}
}

//----- (00485740) --------------------------------------------------------
char*  sub_485740(uint32_t* a1) {
	int v1;       // ecx
	int v2;       // esi
	int v3;       // ebx
	int v4;       // ebp
	int v5;       // edi
	int v6;       // esi
	int v7;       // ebx
	int v8;       // ecx
	char* result; // eax
	int v10;      // [esp+10h] [ebp-4h]

	if (nox_common_getEngineFlag(NOX_ENGINE_DISABLE_SOFT_LIGHTS))
		return (char*)getMemAt(0x587000, 155000);
	v1 = *a1 - dword_5d4594_2650676;
	v2 = a1[1] - dword_5d4594_2650680;
	v3 = v1 / 23;
	v4 = v2 / 23;
	if (v1 / 23 < 0 || v4 < 0 || v3 > 56 || v4 > 44)
		return (char*)getMemAt(0x587000, 155000);
	v5 = v1 % 23;
	v10 = v2 % 23;
	v6 = 5 * v3 + v4 + 40 * v3;
	v7 = getMemByte(0x8531A0, + v6);
	v8 = v1 % 23 * (getMemByte(0x8531A0, 45 + v6) - v7);
	result = (char*)getMemAt(0x5D4594, 1193164);
	*getMemU32Ptr(0x5D4594, 1193172) =
		8 * (v7 + v8 / 23 +
			 v10 *
				 (getMemByte(0x8531A0, 1 + v6) + v5 * (getMemByte(0x8531A0, 46 + v6) - getMemByte(0x8531A0, 1 + v6)) / 23 -
				  (v7 + v8 / 23)) /
				 23);
	*getMemU32Ptr(0x5D4594, 1193168) = *getMemU32Ptr(0x5D4594, 1193172);
	*getMemU32Ptr(0x5D4594, 1193164) = *getMemU32Ptr(0x5D4594, 1193172);
	return result;
}

//----- (00484B70) --------------------------------------------------------
short  sub_484B70(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	int v8; // eax

	v8 = sub_47D380(a7, a8);
	if (v8)
		nox_client_drawImageAt_47D2C0(a1, a2, a3);
	return v8;
}

//----- (00430D60) --------------------------------------------------------
int sub_430D60() {
	int result; // eax

	result = 0;
	dword_5d4594_3805484 = sub_485880;
	nox_xxx_useMMX_587000_80800 = 0;
	dword_5d4594_805836 = 0;
	*getMemU32Ptr(0x973F18, 7696) = 0;
	*getMemU32Ptr(0x973F18, 7720) = sub_481470;
	*getMemU32Ptr(0x973F18, 7704) = sub_484E60;
	dword_5d4594_3807156 = sub_485740;
	*getMemU32Ptr(0x973F18, 7700) = sub_484B70;
	return result;
}
#endif // NOX_CGO

//----- (00484BD0) --------------------------------------------------------
double sub_484BD0() { return *(float*)&dword_587000_154968; }

//----- (004C1C70) --------------------------------------------------------
int sub_4C1C70(int a1, int a2) { return ((long long)a1 << 16) / a2; }

#ifdef NOX_CGO
void sub_4695E0(int a1, int a2, int* a3, int a4, int a5);
#else // NOX_CGO
//----- (004695E0) --------------------------------------------------------
void sub_4695E0(int a1, int a2, int* a3, int a4, int a5) {
	int v5 = a4;
	if (a5) {
		v5 = -a4;
	}
	int v6 = sub_4C1C60(v5, a3[0]) << 8;
	int v7 = sub_4C1C60(v5, a3[1]) << 8;
	int v8 = sub_4C1C60(v5, a3[2]) << 8;

	nox_light_3* ptr = &nox_arr2_853BC0[a1][a2];

	nox_light_3 res;
	res.r = v6 + ptr->r;
	res.g = v7 + ptr->g;
	res.b = v8 + ptr->b;

	if (res.r <= 0xFF0000) {
		if (res.r < 0) {
			res.r = 0;
		}
	} else {
		res.r = 0xFF0000;
	}
	if (res.g <= 0xFF0000) {
		if (res.g < 0) {
			res.g = 0;
		}
	} else {
		res.g = 0xFF0000;
	}
	if (res.b <= 0xFF0000) {
		if (res.b < 0) {
			res.b = 0;
		}
	} else {
		res.b = 0xFF0000;
	}
	*ptr = res;
}
#endif // NOX_CGO

//----- (004697C0) --------------------------------------------------------
int  sub_4697C0(int* a1, int* a2, int2* a3, signed int a4, int* a5) {
	int result;       // eax
	int* v6;          // edi
	int v7;           // esi
	int v8;           // edx
	int v9;           // ebp
	int* v10;         // ecx
	char* v11;        // eax
	int v12;          // edi
	int v13;          // eax
	int v14;          // esi
	int v15;          // ebx
	int v16;          // eax
	unsigned int v17; // eax
	int v18;          // [esp+10h] [ebp-10h]
	char* i;          // [esp+14h] [ebp-Ch]
	int j;            // [esp+18h] [ebp-8h]
	unsigned int v21; // [esp+1Ch] [ebp-4h]
	int* v22;         // [esp+24h] [ebp+4h]
	signed int v23;   // [esp+28h] [ebp+8h]
	int v24;          // [esp+30h] [ebp+10h]

	result = *a1;
	v6 = a2;
	v7 = *a1 + a1[1];
	v18 = *a1 + a1[1];
	if (*a1 < *a2)
		result = *a2;
	if (v7 > a2[1] + *a2) {
		v18 = a2[1] + *a2;
		v7 = a2[1] + *a2;
	}
	if (v7 - result > 1) {
		v23 = *getMemU32Ptr(0x587000, 142308);
		if ((unsigned int)a4 <= *getMemIntPtr(0x587000, 142308))
			v23 = a4;
		v21 = (a4 >> 16) * (a4 >> 16);
		v8 = 23 * result - a3->field_4;
		v24 = 23 * result - a3->field_4;
		v9 = result;
		if (result < v7) {
			v10 = &v6[result + 2];
			v11 = (char*)((char*)a1 - (char*)v6);
			v12 = dword_587000_142316;
			v22 = v10;
			for (i = v11;; v11 = i) {
				v13 = *(int*)((char*)v10 + (uint32_t)v11);
				v14 = 23 * v13 - a3->field_0;
				v15 = v13;
				if (v13 < *v10) {
					v16 = v8 * v8;
					for (j = v8 * v8;; v16 = j) {
						v17 = sub_4C1C70(v12 + v23,
										 66 * *getMemU32Ptr(0x587000, 142312) * (v16 + v14 * v14) / v21 + 0x10000);
						v12 = dword_587000_142316;
						if (v17 > *(int*)&dword_587000_142316) {
							sub_4695E0(v15, v9, a5, 8 * (v17 - dword_587000_142316), 0);
							v12 = dword_587000_142316;
						}
						v14 += 23;
						if (++v15 >= *v22)
							break;
					}
					v8 = v24;
					v10 = v22;
				}
				result = v18;
				v8 += 23;
				++v9;
				++v10;
				v24 = v8;
				v22 = v10;
				if (v9 >= v18)
					break;
			}
		}
	}
	return result;
}

//----- (004696B0) --------------------------------------------------------
int  sub_4696B0(int2* a1, int2* a2, int2* a3, int2* a4, signed int a5, int* a6) {
	int v6;        // edx
	int v7;        // edi
	int2* v8;      // edi
	int2* v9;      // ebx
	int2* v10;     // esi
	int result;    // eax
	int v12;       // ecx
	char v13[184]; // [esp+10h] [ebp-228h]
	char v14[184]; // [esp+C8h] [ebp-170h]
	char v15[184]; // [esp+180h] [ebp-B8h]

	v6 = a1->field_4;
	v7 = a2->field_4;
	if (v6 > v7) {
		v10 = a3;
		if (v7 <= a3->field_4) {
			v9 = a2;
			v8 = a1;
			goto LABEL_9;
		}
		v9 = a3;
	} else {
		v8 = a3;
		if (v6 <= a3->field_4) {
			v9 = a1;
			v10 = a2;
			goto LABEL_9;
		}
		v9 = a3;
	}
	v10 = a1;
	v8 = a2;
LABEL_9:
	sub_484DC0(v9, v10, (int*)v15);
	sub_484DC0(v9, v8, (int*)v14);
	sub_4697C0((int*)v15, (int*)v14, a4, a5, a6);
	result = v10->field_4;
	v12 = v8->field_4;
	if (result >= v12) {
		if (result > v12) {
			sub_484DC0(v8, v10, (int*)v13);
			result = sub_4697C0((int*)v15, (int*)v13, a4, a5, a6);
		}
	} else {
		sub_484DC0(v10, v8, (int*)v13);
		result = sub_4697C0((int*)v13, (int*)v14, a4, a5, a6);
	}
	return result;
}

//----- (00469140) --------------------------------------------------------
void  nox_xxx_cliLight16_469140(nox_drawable* dr, nox_draw_viewport_t* vp) {
	int arg0 = dr;
	int v1;           // esi
	int v2;           // eax
	signed int v3;    // ebp
	int v4;           // edi
	int v5;           // ecx
	int v6;           // eax
	int v7;           // ebx
	unsigned int v16; // eax
	short v17;      // cx
	int v18;          // edi
	int v19;          // ebx
	int v20;          // eax
	int v21;          // ecx
	int v22;          // edi
	int v23;          // eax
	int v24;          // eax
	int v25;          // eax
	int* v26;         // esi
	float v27;        // [esp+0h] [ebp-68h]
	signed int v33;   // [esp+24h] [ebp-44h]
	unsigned int v36; // [esp+34h] [ebp-34h]
	int2 a1;          // [esp+38h] [ebp-30h]
	int2 a4;          // [esp+40h] [ebp-28h]
	int2 a3;          // [esp+50h] [ebp-18h]
	int2 a2;          // [esp+58h] [ebp-10h]
	int2 v42;         // [esp+60h] [ebp-8h]
	int v44;          // [esp+6Ch] [ebp+4h]
	int v45;          // [esp+6Ch] [ebp+4h]

	v1 = arg0;
	if (!(sub_45A840(arg0) || *(uint32_t*)(arg0 + 112) & 0x80000 && (v2 = *(uint32_t*)(arg0 + 120), v2 & 0x1000000) && *(uint32_t*)(arg0 + 144) > 0 && v2 & 4)) {
		return;
	}
	if (!(!nox_xxx_get_57AF20() || arg0 == *getMemU32Ptr(0x852978, 8) || *(int(**)(int*, int))(arg0 + 300) == nox_thing_glow_orb_draw)) {
		return;
	}
	v3 = *(uint32_t*)(arg0 + 148);
	v4 = *(uint32_t*)(arg0 + 144);
	if (*(uint32_t*)(arg0 + 120) & 0x20000000) {
		v3 += nox_common_randomIntMinMax_415FF0(0, *(uint32_t*)(arg0 + 148) >> 18, "C:\\NoxPost\\src\\Client\\Light\\Light16.c", 267) << 16;
		v27 = (double)v3 * 0.000015258789;
		v4 = sub_484C60(v27);
	}
	if (v3 <= (int)(sub_484BD0() * 65536.0)) {
		return;
	}
	v33 = v3;
	if ((unsigned int)v3 > *getMemIntPtr(0x587000, 142320)) {
		v33 = *getMemU32Ptr(0x587000, 142320);
	}
	v5 = *(uint32_t*)(arg0 + 12) - dword_5d4594_2650676;
	v7 = *(uint32_t*)(arg0 + 16) - dword_5d4594_2650680;
	v36 = (v3 >> 16) * (v3 >> 16);
	v6 = *(uint32_t*)(arg0 + 168);
	a4.field_0 = v5;
	a4.field_4 = v7;
	if (v6 == 0xFFFF) {
		unsigned int dlimit = v4 * v4;

		int xmin = (v5 - v4) / 23;
		if (xmin < 0) {
			xmin = 0;
		}

		int xmax = (v5 + v4) / 23;
		if (xmax > 56) {
			xmax = 56;
		}

		int ymin = (v7 - v4) / 23;
		if (ymin < 0) {
			ymin = 0;
		}

		int ymax = (v7 + v4) / 23;
		if (ymax > 44) {
			ymax = 44;
		}

		int v11 = dword_587000_142328;
		for (int y = ymin; y <= ymax; y++) {
			int dy = v7 - 23 * y;
			int dy2 = dy * dy;
			for (int x = xmin; x <= xmax; x++) {
				int dx = v5 - 23 * x;
				int dx2 = dx * dx;
				unsigned int dist = dx2 + dy2;
				if (dist <= dlimit) {
					v16 = sub_4C1C70(v33 + v11, 66 * dist * *getMemU32Ptr(0x587000, 142324) / v36 + 0x10000);
					v11 = dword_587000_142328;
					if (v16 > v11) {
						sub_4695E0(x, y, (int*)(v1 + 152), 8 * (v16 - dword_587000_142328), *(uint32_t*)(v1 + 172));
					}
					v5 = a4.field_0;
					v7 = a4.field_4;
				}
			}
		}
	} else {
		a1.field_0 = (v5 << 16) / 23;
		v17 = *(uint16_t*)(arg0 + 164);
		v18 = v4 << 16;
		a1.field_4 = (v7 << 16) / 23;
		v19 = v18 / 23;
		v20 = sub_4C1C60(v18 / 23, 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * ((unsigned short)(v17 + 0x4000) >> 4)));
		v21 = v18 / 23;
		v22 = v20;
		v23 = sub_4C1C60(v21, 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * (*(unsigned short*)(arg0 + 164) >> 4)));
		a3.field_0 = a1.field_0 + v22;
		LOWORD(v22) = *(uint16_t*)(arg0 + 164) + *(uint16_t*)(arg0 + 166);
		a3.field_4 = a1.field_4 + v23;
		v44 = sub_4C1C60(v19, 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * ((unsigned short)(v22 + 0x4000) >> 4)));
		v24 = sub_4C1C60(v19, 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * ((unsigned short)v22 >> 4)));
		LOWORD(v22) = *(uint16_t*)(v1 + 164) - *(uint16_t*)(v1 + 166);
		a2.field_0 = a1.field_0 + v44;
		a2.field_4 = a1.field_4 + v24;
		v45 = sub_4C1C60(v19, 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * ((unsigned short)(v22 + 0x4000) >> 4)));
		v25 = sub_4C1C60(v19, 16 * *getMemU32Ptr(0x85B3FC, 12260 + 4 * ((unsigned short)v22 >> 4)));
		v26 = (int*)(v1 + 152);
		v42.field_0 = a1.field_0 + v45;
		v42.field_4 = a1.field_4 + v25;
		sub_4696B0(&a1, &a2, &a3, &a4, v3, v26);
		sub_4696B0(&a1, &a3, &v42, &a4, v3, v26);
	}
}

#ifndef NOX_CGO
//----- (00468F80) --------------------------------------------------------
void  sub_468F80(nox_draw_viewport_t* vp) {
	int a1 = vp;
	uint32_t* v1;           // esi
	int v5;               // ecx
	int v6;               // eax
	int v7;               // edx
	int v8;               // edx
	int v11;              // eax
	int v12;              // ebx
	int v13;              // edx
	int v14;              // eax
	int v15;              // ecx
	int v16;              // edx
	int4 v17;             // [esp+Ch] [ebp-24h]
	int v18;              // [esp+1Ch] [ebp-14h]
	int v19;              // [esp+20h] [ebp-10h]
	int v20;              // [esp+24h] [ebp-Ch]
	int v21;              // [esp+28h] [ebp-8h]
	int v22;              // [esp+2Ch] [ebp-4h]

	v1 = (uint32_t*)a1;
	dword_5d4594_2650676 = 46 * ((*(uint32_t*)(a1 + 16) + 11) / 46 - 1) - 11;
	dword_5d4594_2650680 = 46 * ((*(uint32_t*)(a1 + 20) + 11) / 46) - 57;
	if (nox_common_getEngineFlag(NOX_ENGINE_DISABLE_SOFT_LIGHTS)) {
		for (int i = 0; i < 57*4; i++) {
			for (int j = 0; j < 45*4; j++) {
				nox_arr2_853BC0[i][j].r = 0xFF0000;
				nox_arr2_853BC0[i][j].g = 0xFF0000;
				nox_arr2_853BC0[i][j].b = 0xFF0000;
			}
		}
	} else {
		int a1b = 0;
		sub_434A10(&a1b, &v22, &v21);
		if (nox_xxx_get_57AF20()) {
			v5 = 50;
			v6 = 50;
			v7 = 50;
			v22 = 50;
			v21 = 50;
			a1b = 50;
		} else {
			v6 = v21;
			v5 = v22;
			v7 = a1b;
		}
		v8 = v7 << 16;
		v20 = v6 << 16;
		v19 = v5 << 16;
		v18 = v8;
		v11 = v8;
		v12 = v19;
		v13 = v20;
		for (int i = 0; i < 57*4; i++) {
			for (int j = 0; j < 45*4; j++) {
				nox_arr2_853BC0[i][j].r = v11;
				nox_arr2_853BC0[i][j].g = v12;
				nox_arr2_853BC0[i][j].b = v13;
			}
		}
		v14 = v1[4];
		v17.field_0 = v14 - 100;
		v15 = v1[5];
		v17.field_4 = v15 - 100;
		v16 = v1[9];
		v17.field_8 = v1[8] + v14 + 100;
		v17.field_C = v16 + v15 + 100;
		nox_xxx_forEachSprite_49AB00(&v17, nox_xxx_cliLight16_469140, (int)v1);
	}
}
#endif // NOX_CGO

//----- (00430CC0) --------------------------------------------------------
int nox_xxx___cfltcvt_init_430CC0() {
	*getMemU32Ptr(0x973F18, 7696) = 1;
	*getMemU32Ptr(0x973F18, 7700) = nox_xxx_someEdgeProcessing_480EF0;
	*getMemU32Ptr(0x973F18, 7720) = sub_4814F0;
	dword_5d4594_3807156 = sub_469920;
#ifdef NOX_CGO
	dword_5d4594_805836 = 0;
	dword_5d4594_3805484 = sub_480BE0;
	dword_5d4594_3805492 = sub_480860;
	return 0;
#else // NOX_CGO
	*getMemU32Ptr(0x973F18, 7704) = sub_468F80;
	int result; // eax
	result = nox_xxx_testMMXSupport_430D40();
	nox_xxx_useMMX_587000_80800 = result;
	if (result) {
		dword_5d4594_805836 = 1;
		dword_5d4594_3805484 = sub_480950;
		dword_5d4594_3805492 = sub_4805A0;
	} else {
		dword_5d4594_805836 = 0;
		dword_5d4594_3805484 = sub_480BE0;
		dword_5d4594_3805492 = sub_480860;
	}
	return result;
#endif // NOX_CGO
}

#ifndef NOX_CGO
//----- (00430BA0) --------------------------------------------------------
int nox_video_initFloorBuffer_430BA0() {
	if (dword_5d4594_3801780 == 1)
		nox_xxx___cfltcvt_init_430CC0();
	else
		sub_430D60();
	if (!nox_xxx_tileInitBuf_430DB0(nox_backbuffer_width, nox_backbuffer_height)) {
		printf("VideoInit: error initializing floor buffer\n");
		return 0;
	}
	return 1;
}

//----- (00431040) --------------------------------------------------------
int  nox_xxx_unused_431040(int a1, int a2, int a3) {
	nox_win_width = a2;
	nox_win_height = a3;
	*(uint32_t*)&nox_video_dxFullScreen = 0;
	int result = nox_xxx_unused_4800F0();
	if (!result) {
		return 0;
	}
	return nox_video_initFloorBuffer_430BA0();
}

int nox_video_recreateBuffersAndTarget_430BA0() {
	nox_video_freeFloorBuffer_430EC0();
	int result = nox_video_recreateRenderTarget_47FD70();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return 0;
	}
	return nox_video_initFloorBuffer_430BA0();
}
#endif // NOX_CGO
