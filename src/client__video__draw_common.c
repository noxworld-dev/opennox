#include <math.h>
#define IGNORE_EXTERNS
#include "client__video__draw_common.h"
#undef IGNORE_EXTERNS
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME5_2.h"
#include "mutexes.h"
#include "operators.h"

unsigned char byte_5D4594_3804364[160] = {0};

int nox_video_renderTargetFlags = 0;
int nox_video_windowsPlatformVersion = 0;

void (*dword_975240)(uint32_t, uint32_t*, uint32_t*, uint32_t*);
int (*dword_975380)(uint32_t, uint32_t, uint32_t);
void nox_color_rgb_func(uint8_t r, uint8_t g, uint8_t b, uint32_t* p);
void nox_color_rgb_func_set(int mode);

unsigned char* nox_draw_colors_r_3804672 = 0;
unsigned char* nox_draw_colors_g_3804656 = 0;
unsigned char* nox_draw_colors_b_3804664 = 0;

//----- (004340A0) --------------------------------------------------------
void sub_4340A0(int a1, int a2, int a3, int a4) {
	unsigned long long v4; // rax
	int v5;                // esi
	unsigned long long v6; // rax
	unsigned long long v7; // rax

	a2 = a2 & 0xFF;
	a3 = a3 & 0xFF;
	a4 = a4 & 0xFF;

	v4 = a1;
	if (a1 >= 0 && a1 < 16) {
		v5 = 48 * a1 + (uint32_t)(&nox_draw_curDrawData_3799572->field_66);
		*(uint32_t*)(v5 + 32) = (unsigned char)a4;
		*(uint32_t*)(v5 + 24) = (unsigned char)a2;
		*(uint32_t*)(v5 + 28) = (unsigned char)a3;
		nox_color_rgb_func(a2, a3, a4, (uint32_t*)(v5 + 40));
	}
}

//----- (004347F0) --------------------------------------------------------
int sub_4347F0(char* a1, int a2) {
	if (a2 <= 256) {
		sub_435120(getMemAt(0x973F18, 3880), a1);
		sub_4353F0();
		sub_435040();
		sub_434F00();
	}
	return nox_xxx_makeFillerColor_48BDE0();
}

//----- (004348C0) --------------------------------------------------------
int sub_4348C0() {
	// FIXME 8-bit support
	return 0;
}

//----- (00434FB0) --------------------------------------------------------
int sub_434FB0() {
	// FIXME 8-bit support
	return 1;
}

//----- (004352E0) --------------------------------------------------------
void sub_4352E0() {
	// FIXME gamma control
}

//----- (004353C0) --------------------------------------------------------
void sub_4353C0() {
	// FIXME 8-bit support
}

//----- (004353F0) --------------------------------------------------------
void sub_4353F0() {
	// FIXME 8-bit support
}

void nox_draw_freeColorTables_433C20_2();
//----- (00433CD0) --------------------------------------------------------
int sub_433CD0(uint8_t a1, uint8_t a2, uint8_t a3) {
	long long v5;          // rax
	unsigned long long v6; // rax
	unsigned long long v7; // rax
	int result;            // eax

	nox_draw_curDrawData_3799572->field_24 = a1;
	nox_draw_curDrawData_3799572->field_25 = a2;
	nox_draw_curDrawData_3799572->field_26 = a3;
	nox_draw_curDrawData_3799572->field_16 = a1 == 0xFF && a2 == 0xFF && a3 == 0xFF;
	result = dword_975380(a1, a2, a3);
	((uint16_t*)(&nox_draw_curDrawData_3799572->field_258))[1] = result;
	return result;
}

//----- (00433E40) --------------------------------------------------------
int sub_433E40(int a1) {
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	return sub_433CD0(v3, v2, a1);
}

//----- (00434040) --------------------------------------------------------
void sub_434040(int a1) {
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	nox_xxx_drawMakeRGB_433F10(v3, v2, a1);
}

//----- (004341D0) --------------------------------------------------------
int nox_xxx_drawPlayer_4341D0(int a1, int a2) {
	int result;            // eax
	int v3;                // edi
	int v4;                // esi
	int v5;                // ecx
	unsigned long long v6; // rax
	unsigned long long v7; // rax
	long long v8;          // kr10_8
	unsigned long long v9; // rax
	int v10;               // [esp+8h] [ebp-4h]

	result = a1;
	if (a1 >= 0 && a1 < 16) {
		v3 = a2;
		v4 = 48 * a1 + (uint32_t)(&nox_draw_curDrawData_3799572->field_66);
		result = *(uint32_t*)(48 * a1 + (uint32_t)(&nox_draw_curDrawData_3799572->field_76));
		if (a2 != result) {
			dword_975240(a2, &a1, &a2, &v10);
			*(uint32_t*)(v4 + 24) = (unsigned char)a1;
			*(uint32_t*)(v4 + 28) = (unsigned char)a2;
			v5 = (unsigned char)v10;
			*(uint32_t*)(v4 + 40) = v3;
			*(uint32_t*)(v4 + 32) = v5;
		}
	}
	return result;
}

//----- (00434480) --------------------------------------------------------
void sub_434480(int a1, int* a2, int* a3, int* a4) { dword_975240(a1, a2, a3, a4); }

//----- (00434B60) --------------------------------------------------------
int sub_434B60() {
	int v0;       // ebp
	pixel888* v1; // edi
	int v2;       // ebx
	char* v3;     // esi
	long long v4; // rax
	int v13;      // [esp+10h] [ebp-90Ch]
	char v14[1536];
	pixel888 v19[256]; // [esp+61Ch] [ebp-300h]

	v0 = nox_video_getGammaSetting_434B00();
	v1 = v19;
	v2 = 0;
	v3 = &v14[512];
	v13 = 0;
	do {
		if (v0 == 1) {
			LOWORD(v4) = (uint16_t)v2 << 8;
		} else {
			v4 = (long long)(pow((double)v13 * 0.00392156862745098,
								 1.0 / ((double)(v0 - 1) * 0.1666666666666667 + 1.0)) *
							 65535.0);
		}
		*((uint16_t*)v3 + 256) = v4;
		*(uint16_t*)v3 = v4;
		*((uint16_t*)v3 - 256) = v4;
		++v2;
		v3 += 2;
		v13 = v2;
	} while (v2 < 256);
	// FIXME gamma control
	return 0;
}
// 434B60: using guessed type char var_8FF[511];
// 434B60: using guessed type char var_6FF[512];
// 434B60: using guessed type char var_4FF[511];

//----- (004B0300) --------------------------------------------------------
int sub_4B0300(char* a1) {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 1311928);
	if (*getMemIntPtr(0x5D4594, 1311928) < 2) {
		strncpy((char*)getMemAt(0x5D4594, 1311940 + 260 * *getMemU32Ptr(0x5D4594, 1311928)), a1, 0x104u);
		result = ++*getMemU32Ptr(0x5D4594, 1311928);
	}
	return result;
}

// 4B0536: variable 'v8' is possibly undefined
// 4B0536: variable 'v7' is possibly undefined
