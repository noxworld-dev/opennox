#include "client__draw__glowdraw.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"
#include "GAME5_2.h"
#include "client__video__draw_common.h"
#include "common__random.h"
#include "operators.h"

extern uint32_t dword_587000_142316;
extern uint32_t dword_587000_142328;
extern uint32_t dword_587000_154968;
extern uint32_t dword_5d4594_3805484;
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
extern uint32_t nox_video_modeXxx_3801780;
extern uint32_t dword_5d4594_3798796;
extern uint32_t dword_5d4594_3798844;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_video_dxFullScreen;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

//----- (00484BD0) --------------------------------------------------------
double sub_484BD0() { return *(float*)&dword_587000_154968; }

//----- (004C1C70) --------------------------------------------------------
int sub_4C1C70(int a1, int a2) { return ((long long)a1 << 16) / a2; }

void sub_4695E0(int a1, int a2, int* a3, int a4, int a5);
//----- (004697C0) --------------------------------------------------------
int sub_4697C0(int* a1, int* a2, int2* a3, signed int a4, int* a5) {
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
	if (*a1 < *a2) {
		result = *a2;
	}
	if (v7 > a2[1] + *a2) {
		v18 = a2[1] + *a2;
		v7 = a2[1] + *a2;
	}
	if (v7 - result > 1) {
		v23 = *getMemU32Ptr(0x587000, 142308);
		if ((unsigned int)a4 <= *getMemIntPtr(0x587000, 142308)) {
			v23 = a4;
		}
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
						if (++v15 >= *v22) {
							break;
						}
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
				if (v9 >= v18) {
					break;
				}
			}
		}
	}
	return result;
}

//----- (004696B0) --------------------------------------------------------
int sub_4696B0(int2* a1, int2* a2, int2* a3, int2* a4, signed int a5, int* a6) {
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
void nox_xxx_cliLight16_469140(nox_drawable* dr, nox_draw_viewport_t* vp) {
	int arg0 = dr;
	int v1;           // esi
	int v2;           // eax
	signed int v3;    // ebp
	int v4;           // edi
	int v5;           // ecx
	int v6;           // eax
	int v7;           // ebx
	unsigned int v16; // eax
	short v17;        // cx
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
	if (!(sub_45A840(arg0) || *(uint32_t*)(arg0 + 112) & 0x80000 && (v2 = *(uint32_t*)(arg0 + 120), v2 & 0x1000000) &&
								  *(uint32_t*)(arg0 + 144) > 0 && v2 & 4)) {
		return;
	}
	if (!(!nox_xxx_get_57AF20() || arg0 == *getMemU32Ptr(0x852978, 8) ||
		  *(int (**)(int*, int))(arg0 + 300) == nox_thing_glow_orb_draw)) {
		return;
	}
	v3 = *(uint32_t*)(arg0 + 148);
	v4 = *(uint32_t*)(arg0 + 144);
	if (*(uint32_t*)(arg0 + 120) & 0x20000000) {
		v3 += nox_common_randomIntMinMax_415FF0(0, *(uint32_t*)(arg0 + 148) >> 18,
												"C:\\NoxPost\\src\\Client\\Light\\Light16.c", 267)
			  << 16;
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

//----- (00430CC0) --------------------------------------------------------
int nox_xxx___cfltcvt_init_430CC0() {
	*getMemU32Ptr(0x973F18, 7696) = 1;
	*getMemU32Ptr(0x973F18, 7700) = nox_xxx_someEdgeProcessing_480EF0;
	*getMemU32Ptr(0x973F18, 7720) = sub_4814F0;
	dword_5d4594_3807156 = sub_469920;
	dword_5d4594_805836 = 0;
	dword_5d4594_3805484 = sub_480BE0;
	return 0;
}
