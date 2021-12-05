#include <stdbool.h>
#include <string.h>

#include "defs.h"
#include "memmap.h"

int4* nox_xxx_utilRect_49F930(int4* a1, int4* a2, int4* a3);

extern unsigned char** nox_pixbuffer_rows_3798784;
extern nox_render_data_t obj_5D4594_3800716;
extern nox_render_data_t* ptr_5D4594_3799572;
extern unsigned char byte_5D4594_3804364[160];
extern void* nox_draw_colorTablesRev_3804668;
extern unsigned int dword_5d4594_810632;
extern unsigned int dword_5d4594_810636;
extern void* dword_5d4594_810640;

unsigned int dword_5d4594_3799508 = 0; // TODO: remove externs to it
void* nox_draw_sprite_dstPtr_3799540 = 0;
unsigned int dword_5d4594_3799552 = 0; // TODO: remove externs to it
unsigned int dword_5d4594_3799484 = 0;
unsigned int dword_5d4594_3799476 = 0;
unsigned char* nox_video_cur_pixdata_3799444 = 0;
unsigned char* nox_draw_colors_r_3804672 = 0;
unsigned char* nox_draw_colors_g_3804656 = 0;
unsigned char* nox_draw_colors_b_3804664 = 0;

#ifndef NOX_CGO

#ifdef _WIN32
#include <windows.h>
#else
#include "windows_compat.h"
#endif
#include "operators.h"

int nox_draw_sprite_offsY_3799556 = 0;
int nox_draw_sprite_offsX_3799560 = 0;
void (*func_type27_3799536)(void) = 0;
void (*func_type4_3799432)(void) = 0;
void (*func_type5_3799544)(void) = 0;
void (*func_type6_3799488)(void) = 0;
extern void* (*nox_video_getImagePixdata_func)(nox_video_bag_image_t*);
#else  // NOX_CGO
void* nox_video_getImagePixdata_func(nox_video_bag_image_t*);
#include "operators.h"
#endif // NOX_CGO

#ifndef NOX_CGO
//----- (004C60D0) --------------------------------------------------------
void sub_4C60D0(nox_video_bag_image_t* img, int x, int y) {
	int v8;   // edx
	int v9;   // edi
	int v10;  // ebp
	int v11;  // eax
	int v12;  // edx
	int v13;  // esi
	int v14;  // ecx
	int v15;  // ebx
	int v16;  // ebp
	int4 a1a; // [esp+10h] [ebp-20h]
	RECT rc;  // [esp+20h] [ebp-10h]
	int v19;  // [esp+3Ch] [ebp+Ch]

	nox_video_cur_pixdata_3799444 = nox_video_getImagePixdata_func(img);
	if (!nox_video_cur_pixdata_3799444) {
		return;
	}
	int4* result = nox_video_cur_pixdata_3799444;
	int width = result->field_0;
	int* v5 = &result->field_4;
	int4* v6 = (int4*)*v5;
	nox_video_cur_pixdata_3799444 = v5;
	++v5;
	nox_video_cur_pixdata_3799444 = v5;
	v8 = *v5;
	++v5;
	nox_draw_sprite_offsX_3799560 = v8;
	v9 = v8 + x;
	nox_video_cur_pixdata_3799444 = v5;
	nox_draw_sprite_offsY_3799556 = *v5;
	v10 = nox_draw_sprite_offsY_3799556 + y;
	result = (int4*)(v5 + 1);
	v19 = nox_draw_sprite_offsY_3799556 + y;
	nox_video_cur_pixdata_3799444 = result;
	if (dword_5d4594_3799484) {
		v6 = (int4*)((char*)v6 - dword_5d4594_3799484);
		if ((int)v6 <= 0) {
			return;
		}
		dword_5d4594_3799476 = (char*)v6 + v10;
	}
	*getMemU32Ptr(0x973F18, 92) = v8 + x;
	nox_video_cur_pixdata_3799444 = (char*)result + 1;
	*getMemU32Ptr(0x973F18, 84) = v10;
	*getMemU32Ptr(0x973F18, 88) = width;
	*getMemU32Ptr(0x973F18, 76) = v6;
	int v7 = width;
	if (ptr_5D4594_3799572->flag_0) {
		SetRect(&rc, v9, v10, width + v9, (int)v6 + v10);
		result = nox_xxx_utilRect_49F930(&a1a, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->clip));
		if (!result) {
			return;
		}
		v11 = a1a.field_0 - rc.left;
		v12 = a1a.field_4 - rc.top;
		v7 = a1a.field_8 - a1a.field_0;
		v6 = (int4*)(a1a.field_C - a1a.field_4);
		if (a1a.field_0 != rc.left || v12) {
			v9 += v11;
			v7 = a1a.field_8 - a1a.field_0;
			nox_video_cur_pixdata_3799444 += v11 + width * v12;
			v10 = v12 + v19;
		} else {
			v10 = v19;
		}
	}
	v13 = width - v7;
	result = v6;
	v14 = (int)&v6[-1].field_C + 3;
	*getMemU32Ptr(0x973F18, 28) = v7;
	if (result) {
		v15 = 4 * v10;
		v16 = v14 + 1;
		do {
			v15 += 4;
			nox_draw_sprite_dstPtr_3799540 = v9 + *(unsigned int*)(v15 + (unsigned int)nox_pixbuffer_rows_3798784 - 4);
			func_type27_3799536();
			--v16;
			nox_video_cur_pixdata_3799444 += v13;
		} while (v16);
	}
}
#endif // NOX_CGO

//----- (004C73A0) --------------------------------------------------------
unsigned char sub_4C73A0() {
	short* v0;            // esi
	unsigned char* v1;    // edi
	unsigned char* v2;    // edx
	short v3;             // cx
	int v4;               // eax
	unsigned char result; // al
	int v7;               // [esp+Ch] [ebp-4h]

	v0 = (unsigned short*)nox_video_cur_pixdata_3799444;
	v1 = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
	v7 = *getMemU32Ptr(0x973F18, 28);
	do {
		v2 = getMemAt(0x973F18, 3880 + 4 * *v1);
		v3 = *v0;
		v4 = (unsigned short)(*v0 & 0x7C00) >> 7;
		++v0;
		// result = *(unsigned char *)(*(unsigned int *)&dword_5d4594_810640
		//                  + (((unsigned char)(__CFADD__(v2[2], 8 * (v3 & 0x1F)) ? -1 : (unsigned
		//                  char)(getMemByte(0x973F18, 3882 + 4 * *v1) + 8 * (v3 & 0x1F))) >> 3) | (4 * (((unsigned
		//                  char)-__CFADD__(v2[1], (unsigned short)(v3 & 0x3E0) >> 2) | (unsigned
		//                  char)(v2[1] + ((unsigned short)(v3 & 0x3E0) >> 2))) & 0xF8)) | ((((unsigned
		//                  char)-__CFADD__(*v2, (unsigned char)v4) | (unsigned char)(*v2 + v4)) & 0xF8) << 7)));
		result = *(unsigned char*)((unsigned int)dword_5d4594_810640 + (SADD8(v2[2], 8 * (v3 & 0x1F)) >> 3) |
								   (4 * (SADD8(v2[1], (unsigned short)(v3 & 0x3E0) >> 2) & 0xF8) |
									(SADD8(*v2, (unsigned char)v4) & 0xF8) << 7));
		*v1++ = result;
	} while (v7-- > 1);
	nox_video_cur_pixdata_3799444 = v0;
	nox_draw_sprite_dstPtr_3799540 = v1;
	return result;
}

//----- (004C6A00) --------------------------------------------------------
void sub_4C6A00() {
	int result;        // eax
	short v1;          // si
	unsigned char* v2; // edi
	int v3;            // eax
	unsigned char v4;  // cl
	int v5;            // eax
	bool v6;           // zf
	unsigned char v7;  // [esp+0h] [ebp-20h]
	int v8;            // [esp+4h] [ebp-1Ch]
	unsigned char v9;  // [esp+14h] [ebp-Ch]
	unsigned char v10; // [esp+1Ch] [ebp-4h]

	result = *getMemU32Ptr(0x973F18, 28) - 1;
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = *(unsigned char*)(&ptr_5D4594_3799572->field_259);
		v2 = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
		v8 = *getMemU32Ptr(0x973F18, 28);
		do {
			v7 = nox_video_cur_pixdata_3799444[0];
			++nox_video_cur_pixdata_3799444;
			v3 = 4 * v7;
			v4 = getMemByte(0x973F18, 3880 + v3);
			v10 = getMemByte(0x973F18, 3882 + v3);
			v9 = getMemByte(0x973F18, 3881 + v3);
			v5 = 4 * (unsigned char)*v2;
			*v2 =
				*(unsigned char*)((((unsigned char)(getMemByte(0x973F18, 3882 + v5) +
													((unsigned short)(v1 * (v10 - getMemByte(0x973F18, 3882 + v5))) >>
													 8)) >>
									3) |
								   (4 * ((getMemByte(0x973F18, 3881 + v5) +
										  ((unsigned short)(v1 * (v9 - getMemByte(0x973F18, 3881 + v5))) >> 8)) &
											 0xF8 |
										 (32 * ((getMemByte(0x973F18, 3880 + v5) +
												 ((unsigned short)(v1 * (v4 - getMemByte(0x973F18, 3880 + v5))) >> 8)) &
												0xF8))))) +
								  (unsigned int)dword_5d4594_810640);
			v2 = (unsigned char*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 1);
			result = v8 - 1;
			v6 = v8 == 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 1;
			--v8;
		} while (!v6);
	}
}
//----- (004C6B50) --------------------------------------------------------
void sub_4C6B50() {
	int v0;            // ecx
	unsigned char* v1; // esi
	unsigned char* v2; // edi
	int v3;            // ebx
	int v4;            // eax
	int v5;            // eax
	bool v7;           // cc

	v0 = *getMemU32Ptr(0x973F18, 28);
	v1 = nox_video_cur_pixdata_3799444;
	v2 = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
	v3 = dword_5d4594_810632;
	if (dword_5d4594_810632) {
		do {
			v4 = *v1++ << 8;
			v5 = *v2++ + v4;
			*(v2 - 1) = *(unsigned char*)(v3 + v5);
			v7 = v0-- <= 1;
		} while (!v7);
		nox_video_cur_pixdata_3799444 = v1;
		nox_draw_sprite_dstPtr_3799540 = v2;
	}
}

//----- (004C6BA0) --------------------------------------------------------
void sub_4C6BA0() {
	int v0;            // ecx
	unsigned char* v1; // esi
	unsigned char* v2; // edi
	int v3;            // ebx
	int v4;            // eax
	int result;        // eax

	v0 = *getMemU32Ptr(0x973F18, 28);
	v1 = nox_video_cur_pixdata_3799444;
	v2 = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
	v3 = (obj_5D4594_3800716.field_258 >> 3) + dword_5d4594_810636;
	do {
		v4 = *v1++;
		result = 32 * v4;
		*v2++ = *(unsigned char*)(v3 + result);
	} while (v0-- > 1);
	nox_video_cur_pixdata_3799444 = v1;
	nox_draw_sprite_dstPtr_3799540 = v2;
}

//----- (004C6BF0) --------------------------------------------------------
void sub_4C6BF0() {
	unsigned char* v0;    // esi
	unsigned char* v1;    // edi
	int v2;               // ebx
	int v3;               // ecx
	int v4;               // eax
	unsigned char result; // al
	int v7;               // [esp+Ch] [ebp-4h]

	v0 = nox_video_cur_pixdata_3799444;
	v1 = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
	v7 = *getMemU32Ptr(0x973F18, 28);
	v2 = (obj_5D4594_3800716.field_258 >> 3) + dword_5d4594_810636;
	v3 = dword_5d4594_810632;
	do {
		v4 = (*(unsigned char*)(v2 + 32 * *v0++) << 8) + *v1;
		result = *(unsigned char*)(v3 + v4);
		*v1++ = result;
	} while (v7-- > 1);
	nox_video_cur_pixdata_3799444 = v0;
	nox_draw_sprite_dstPtr_3799540 = v1;
}

//----- (004C6C60) --------------------------------------------------------
void sub_4C6C60() {
	int result;        // eax
	int v1;            // ecx
	unsigned char* v2; // edi
	unsigned char v3;  // dl
	int v4;            // eax
	unsigned char v5;  // cl
	int v6;            // eax
	bool v7;           // zf
	unsigned char v8;  // [esp+0h] [ebp-24h]
	unsigned char v9;  // [esp+4h] [ebp-20h]
	int v10;           // [esp+4h] [ebp-20h]
	int v11;           // [esp+8h] [ebp-1Ch]
	unsigned char v12; // [esp+18h] [ebp-Ch]
	unsigned char v13; // [esp+20h] [ebp-4h]

	result = *getMemU32Ptr(0x973F18, 28) - 1;
	v9 = obj_5D4594_3800716.field_258 >> 3;
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = v9;
		v8 = *(unsigned char*)(&ptr_5D4594_3799572->field_259);
		v2 = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
		v11 = v9;
		v10 = *getMemU32Ptr(0x973F18, 28);
		while (1) {
			v3 = *(unsigned char*)(v1 + 32 * nox_video_cur_pixdata_3799444[0] + dword_5d4594_810636);
			++nox_video_cur_pixdata_3799444;
			v4 = 4 * v3;
			v5 = getMemByte(0x973F18, 3880 + v4);
			v13 = getMemByte(0x973F18, 3882 + v4);
			v12 = getMemByte(0x973F18, 3881 + v4);
			v6 = 4 * (unsigned char)*v2;
			*v2 =
				*(unsigned char*)((((unsigned char)(getMemByte(0x973F18, 3882 + v6) +
													((unsigned short)(v8 * (v13 - getMemByte(0x973F18, 3882 + v6))) >>
													 8)) >>
									3) |
								   (4 * ((getMemByte(0x973F18, 3881 + v6) +
										  ((unsigned short)(v8 * (v12 - getMemByte(0x973F18, 3881 + v6))) >> 8)) &
											 0xF8 |
										 (32 * ((getMemByte(0x973F18, 3880 + v6) +
												 ((unsigned short)(v8 * (v5 - getMemByte(0x973F18, 3880 + v6))) >> 8)) &
												0xF8))))) +
								  (unsigned int)dword_5d4594_810640);
			v2 = (unsigned char*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 1);
			result = v10 - 1;
			v7 = v10 == 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 1;
			--v10;
			if (v7) {
				break;
			}
			v1 = v11;
		}
	}
}

//----- (004C6DE0) --------------------------------------------------------
void sub_4C6DE0() {
	int v0;            // ecx
	unsigned char* v1; // esi
	unsigned char* v2; // edi
	int v3;            // ebx
	int v4;            // eax

	v0 = *getMemU32Ptr(0x973F18, 28);
	v1 = nox_video_cur_pixdata_3799444;
	v2 = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
	v3 = 32 * (*((unsigned char*)&obj_5D4594_3800716.field_76 + 12 * (*getMemU32Ptr(0x973F18, 0) >> 4))) +
		 dword_5d4594_810636;
	v4 = 0;
	do {
		LOBYTE(v4) = *v1++;
		*v2++ = *(unsigned char*)(v3 + v4);
	} while (v0-- > 1);
	nox_video_cur_pixdata_3799444 = v1;
	nox_draw_sprite_dstPtr_3799540 = v2;
}

//----- (004C6E40) --------------------------------------------------------
void sub_4C6E40() {
	int result;        // eax
	int v1;            // ecx
	unsigned char* v2; // edi
	unsigned char v3;  // dl
	int v4;            // eax
	unsigned char v5;  // cl
	int v6;            // eax
	bool v7;           // zf
	unsigned char v8;  // [esp+0h] [ebp-24h]
	unsigned char v9;  // [esp+4h] [ebp-20h]
	int v10;           // [esp+4h] [ebp-20h]
	int v11;           // [esp+8h] [ebp-1Ch]
	unsigned char v12; // [esp+18h] [ebp-Ch]
	unsigned char v13; // [esp+20h] [ebp-4h]

	result = ptr_5D4594_3799572;
	LOBYTE(result) = *(unsigned char*)(&ptr_5D4594_3799572->field_259);
	v9 = *(unsigned char*)(48 * (*getMemU32Ptr(0x973F18, 0) >> 4) + (unsigned int)(&ptr_5D4594_3799572->field_76));
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = 32 * v9;
		v8 = *(unsigned char*)(&ptr_5D4594_3799572->field_259);
		v2 = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
		v11 = 32 * v9;
		v10 = *getMemU32Ptr(0x973F18, 28);
		while (1) {
			v3 = *(unsigned char*)(v1 + nox_video_cur_pixdata_3799444[0] + dword_5d4594_810636);
			++nox_video_cur_pixdata_3799444;
			v4 = 4 * v3;
			v5 = getMemByte(0x973F18, 3880 + v4);
			v13 = getMemByte(0x973F18, 3882 + v4);
			v12 = getMemByte(0x973F18, 3881 + v4);
			v6 = 4 * (unsigned char)*v2;
			*v2 =
				*(unsigned char*)((((unsigned char)(getMemByte(0x973F18, 3882 + v6) +
													((unsigned short)(v8 * (v13 - getMemByte(0x973F18, 3882 + v6))) >>
													 8)) >>
									3) |
								   (4 * ((getMemByte(0x973F18, 3881 + v6) +
										  ((unsigned short)(v8 * (v12 - getMemByte(0x973F18, 3881 + v6))) >> 8)) &
											 0xF8 |
										 (32 * ((getMemByte(0x973F18, 3880 + v6) +
												 ((unsigned short)(v8 * (v5 - getMemByte(0x973F18, 3880 + v6))) >> 8)) &
												0xF8))))) +
								  (unsigned int)dword_5d4594_810640);
			v2 = (unsigned char*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 1);
			result = v10 - 1;
			v7 = v10 == 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 1;
			--v10;
			if (v7) {
				break;
			}
			v1 = v11;
		}
	}
}

//----- (004C6FD0) --------------------------------------------------------
void sub_4C6FD0() {
	unsigned char* result; // eax
	int v1;                // esi
	unsigned char v2;      // [esp+0h] [ebp-4h]

	result = (unsigned char*)(*getMemU32Ptr(0x973F18, 28) - 1);
	v2 = *(unsigned char*)(48 * (*getMemU32Ptr(0x973F18, 0) >> 4) + (unsigned int)(&ptr_5D4594_3799572->field_76));
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = *getMemU32Ptr(0x973F18, 28);
		result = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
		do {
			*result =
				*(unsigned char*)(((unsigned char)*result << 8) +
								  *(unsigned char*)(32 * v2 + nox_video_cur_pixdata_3799444[0] + dword_5d4594_810636) +
								  dword_5d4594_810632);
			result = (unsigned char*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 1);
			--v1;
			++nox_video_cur_pixdata_3799444;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 1;
		} while (v1);
	}
}

//----- (004C7060) --------------------------------------------------------
void sub_4C7060() {
	int result;       // eax
	int v1;           // edi
	int v2;           // ebp
	unsigned char v3; // dl

	result = *getMemU32Ptr(0x973F18, 0) >> 4;
	LOBYTE(result) =
		*(unsigned char*)(48 * (*getMemU32Ptr(0x973F18, 0) >> 4) + (unsigned int)(&ptr_5D4594_3799572->field_76));
	if (*getMemU32Ptr(0x973F18, 28)) {
		result = 32 * *(unsigned char*)(48 * (*getMemU32Ptr(0x973F18, 0) >> 4) +
										(unsigned int)(&ptr_5D4594_3799572->field_76));
		v1 = (unsigned char)(obj_5D4594_3800716.field_258 >> 3);
		v2 = *getMemU32Ptr(0x973F18, 28);
		do {
			v3 = *(unsigned char*)(result + nox_video_cur_pixdata_3799444[0] + dword_5d4594_810636);
			++nox_video_cur_pixdata_3799444;
			**(unsigned char**)&nox_draw_sprite_dstPtr_3799540 = *(unsigned char*)(v1 + 32 * v3 + dword_5d4594_810636);
			--v2;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 1;
		} while (v2);
	}
}

//----- (004C7110) --------------------------------------------------------
unsigned int sub_4C7110() {
	unsigned int result; // eax
	unsigned char* v1;   // edi
	int v2;              // ecx
	unsigned char v3;    // bl
	unsigned char v4;    // [esp+0h] [ebp-18h]
	unsigned int v5;     // [esp+4h] [ebp-14h]
	unsigned char v6;    // [esp+Ch] [ebp-Ch]
	unsigned char v7;    // [esp+10h] [ebp-8h]

	result = *getMemU32Ptr(0x973F18, 28) - 1;
	if (*getMemU32Ptr(0x973F18, 28)) {
		HIWORD(result) = *getMemU16Ptr(0x973F18, 30);
		v1 = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
		v5 = *getMemU32Ptr(0x973F18, 28);
		do {
			LOWORD(result) = *(unsigned short*)(&nox_video_cur_pixdata_3799444[0]);
			v2 = 4 * (unsigned char)*v1;
			v6 = 16 * *(unsigned short*)(&nox_video_cur_pixdata_3799444[0]);
			v3 = getMemByte(0x973F18, 3881 + v2);
			v7 = getMemByte(0x973F18, 3880 + v2);
			v4 = getMemByte(0x973F18, 3882 + v2);
			nox_video_cur_pixdata_3799444 += 2;
			*v1 = *(
				unsigned char*)((((unsigned char)(v4 + ((unsigned short)(v6 * ((result & 0xF0) - v4)) >> 8)) >> 3) |
								 (unsigned short)(4 *
												  ((v3 + ((unsigned short)(v6 * (((result >> 4) & 0xF0) - v3)) >> 8)) &
													   0xF8 |
												   (32 * ((v7 + ((unsigned short)(v6 * ((BYTE1(result) & 0xF0) - v7)) >>
																 8)) &
														  0xF8))))) +
								(unsigned int)dword_5d4594_810640);
			v1 = (unsigned char*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 1);
			result = v5 - 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 1;
			v5 = result;
		} while (result);
	}
	return result;
}

//----- (004C7240) --------------------------------------------------------
unsigned int sub_4C7240() {
	unsigned int result; // eax
	int v1;              // ecx
	unsigned char* v2;   // edi
	int v3;              // edx
	unsigned char v4;    // cl
	int v5;              // ecx
	unsigned char v6;    // [esp+4h] [ebp-18h]
	unsigned int v7;     // [esp+4h] [ebp-18h]
	int v8;              // [esp+8h] [ebp-14h]

	result = *getMemU32Ptr(0x973F18, 28) - 1;
	v6 = *(unsigned char*)(&ptr_5D4594_3799572->field_259);
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = v6;
		HIWORD(result) = *getMemU16Ptr(0x973F18, 30);
		v2 = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
		v8 = v6;
		v7 = *getMemU32Ptr(0x973F18, 28);
		while (1) {
			LOWORD(result) = *(unsigned short*)(&nox_video_cur_pixdata_3799444[0]);
			v3 = v1 * 16 * (*(unsigned short*)(&nox_video_cur_pixdata_3799444[0]) & 0xF);
			v4 = *v2;
			nox_video_cur_pixdata_3799444 += 2;
			v5 = 4 * v4;
			*v2 = *(
				unsigned char*)((((unsigned char)(getMemByte(0x973F18, 3882 + v5) +
												  ((unsigned short)(BYTE1(v3) * ((result & 0xF0) -
																				 getMemByte(0x973F18, 3882 + v5))) >>
												   8)) >>
								  3) |
								 (unsigned short)(4 *
												  ((getMemByte(0x973F18, 3881 + v5) +
													((unsigned short)(BYTE1(v3) * (((result >> 4) & 0xF0) -
																				   getMemByte(0x973F18, 3881 + v5))) >>
													 8)) &
													   0xF8 |
												   (32 * ((getMemByte(0x973F18, 3880 + v5) +
														   ((unsigned short)(BYTE1(v3) *
																			 ((BYTE1(result) & 0xF0) -
																			  getMemByte(0x973F18, 3880 + v5))) >>
															8)) &
														  0xF8))))) +
								(unsigned int)dword_5d4594_810640);
			v2 = (unsigned char*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 1);
			result = v7 - 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 1;
			v7 = result;
			if (!result) {
				break;
			}
			v1 = v8;
		}
	}
	return result;
}

//----- (004C6900) --------------------------------------------------------
char* sub_4C6900(int a1, int a2) {
	char* result;     // eax
	int v3;           // ebp
	int i;            // esi
	char v5;          // cl
	char* v6;         // eax
	unsigned char v7; // dl

	result = (char*)(a2 - 1);
	if (a2) {
		v3 = a2;
		result = nox_video_cur_pixdata_3799444;
		do {
			for (i = a1; i > 0; i -= v7) {
				v5 = *result;
				v6 = result + 1;
				nox_video_cur_pixdata_3799444 = v6;
				v7 = *v6;
				result = v6 + 1;
				nox_video_cur_pixdata_3799444 = result;
				switch (v5 & 0xF) {
				case 2:
				case 4:
					result += v7;
					goto LABEL_7;
				case 5:
				case 6:
				case 7:
					result += 2 * v7;
				LABEL_7:
					nox_video_cur_pixdata_3799444 = result;
					break;
				default:
					continue;
				}
			}
			--v3;
		} while (v3);
	}
	return result;
}

#ifndef NOX_CGO
//----- (004C64E0) --------------------------------------------------------
unsigned char* sub_4C64E0(int a1, int a2, int a3, int* a4) {
	int v4;                // ebp
	int v5;                // ebx
	unsigned char* result; // eax
	int v7;                // edi
	int v8;                // ecx
	unsigned char* v9;     // esi
	int v10;               // esi
	int v11;               // edi
	int v12;               // edx
	int v13;               // esi
	unsigned int v14;      // ecx
	char* v15;             // esi
	char* v16;             // eax
	char v17;              // dl
	unsigned int v18;      // ecx
	char* v19;             // edi
	char* v20;             // esi
	int v21;               // edx
	int v22;               // ecx
	unsigned char* v23;    // eax
	int v24;               // ecx
	int v25;               // edi
	int v26;               // ecx
	int v27;               // edx
	int v28;               // edi
	int v29;               // ecx
	int v30;               // edi
	int v31;               // ecx
	int v32;               // edi
	int v33;               // ecx
	int v34;               // edi
	int v35;               // ecx
	bool v36;              // zf
	unsigned char* v37;    // [esp+10h] [ebp-18h]
	int v38;               // [esp+14h] [ebp-14h]
	int v39;               // [esp+18h] [ebp-10h]
	int v40;               // [esp+1Ch] [ebp-Ch]
	int v41;               // [esp+20h] [ebp-8h]
	int v42;               // [esp+24h] [ebp-4h]
	int v43;               // [esp+30h] [ebp+8h]
	int v44;               // [esp+38h] [ebp+10h]

	v4 = *a4;
	v5 = a4[2];
	result = *(unsigned char**)&dword_5d4594_3799484;
	v7 = a2;
	v8 = a4[1] - a2;
	v9 = (unsigned char*)(a4[3] - a4[1]);
	v44 = a4[2];
	if (dword_5d4594_3799484) {
		v9 -= dword_5d4594_3799484;
		if ((int)v9 <= 0) {
			return result;
		}
		dword_5d4594_3799476 = &v9[a2];
	}
	if (v8) {
		v7 = v8 + a2;
		sub_4C6900(a3, v8);
	}
	v39 = 0;
	dword_5d4594_3799508 ^= v7 & 1;
	result = v9;
	v10 = (int)(v9 - 1);
	if (result) {
		result = nox_video_cur_pixdata_3799444;
		v11 = 4 * v7;
		v40 = v11;
		v42 = v10 + 1;
		do {
			v12 = a3;
			v13 = a1;
			v41 = a3;
			if (!dword_5d4594_3799552 || (dword_5d4594_3799508 ^= 1u) == 0) {
				v21 = a1 + (unsigned int)nox_pixbuffer_rows_3798784[v11 / 4];
				nox_draw_sprite_dstPtr_3799540 = a1 + (unsigned int)nox_pixbuffer_rows_3798784[v11 / 4];
				if (a3 <= 0) {
					goto LABEL_85;
				}
				while (1) {
					v38 = v21;
					v22 = *result;
					v23 = result + 1;
					*getMemU32Ptr(0x973F18, 0) = v22;
					nox_video_cur_pixdata_3799444 = v23;
					v24 = *v23;
					result = v23 + 1;
					*getMemU32Ptr(0x973F18, 28) = v24;
					nox_video_cur_pixdata_3799444 = result;
					v37 = result;
					v43 = v24;
					switch (getMemByte(0x973F18, 0) & 0xF) {
					case 1:
						v21 += v24;
						nox_draw_sprite_dstPtr_3799540 = v21;
						goto LABEL_82;
					case 2:
						v25 = v24 + v13;
						if (v13 < v4) {
							v5 = v44;
							if (v25 > v4) {
								if (v25 <= v44) {
									v26 = v13 - v4 + v24;
								} else {
									v26 = v44 - v4;
								}
								*getMemU32Ptr(0x973F18, 28) = v26;
								nox_video_cur_pixdata_3799444 = &result[v4 - v13];
								nox_draw_sprite_dstPtr_3799540 = v4 - v13 + v21;
								goto LABEL_28;
							}
						} else {
							v5 = v44;
							if (v25 <= v44) {
								goto LABEL_28;
							}
						}
						if (v13 < v5 && v25 > v5) {
							*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						LABEL_28:
							func_type27_3799536();
						}
						v27 = v43;
						result = &v37[v43];
					LABEL_80:
						nox_video_cur_pixdata_3799444 = result;
						v21 = v38 + v27;
						nox_draw_sprite_dstPtr_3799540 = v21;
					LABEL_83:
						v13 += v43;
						v41 -= v43;
						if (v41 <= 0) {
							v11 = v40;
							goto LABEL_85;
						}
						break;
					case 4:
						v30 = v24 + v13;
						if (v13 < v4) {
							v5 = v44;
							if (v30 > v4) {
								if (v30 <= v44) {
									v31 = v13 - v4 + v24;
								} else {
									v31 = v44 - v4;
								}
								*getMemU32Ptr(0x973F18, 28) = v31;
								nox_video_cur_pixdata_3799444 = &result[v4 - v13];
								nox_draw_sprite_dstPtr_3799540 = v4 - v13 + v21;
								goto LABEL_52;
							}
						} else {
							v5 = v44;
							if (v30 <= v44) {
								goto LABEL_52;
							}
						}
						if (v13 < v5 && v30 > v5) {
							*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						LABEL_52:
							func_type4_3799432();
						}
						v27 = v43;
						result = &v37[v43];
						goto LABEL_80;
					case 5:
						v32 = v24 + v13;
						if (v13 < v4) {
							v5 = v44;
							if (v32 > v4) {
								if (v32 <= v44) {
									v33 = v13 - v4 + v24;
								} else {
									v33 = v44 - v4;
								}
								*getMemU32Ptr(0x973F18, 28) = v33;
								nox_draw_sprite_dstPtr_3799540 = v4 - v13 + v21;
								nox_video_cur_pixdata_3799444 = &result[2 * (v4 - v13)];
								goto LABEL_65;
							}
						} else {
							v5 = v44;
							if (v32 <= v44) {
								goto LABEL_65;
							}
						}
						if (v13 < v5 && v32 > v5) {
							*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						LABEL_65:
							func_type5_3799544();
						}
						result = &v37[2 * v43];
						v21 = v38 + v43;
						nox_video_cur_pixdata_3799444 = &v37[2 * v43];
						nox_draw_sprite_dstPtr_3799540 = v38 + v43;
						goto LABEL_83;
					case 6:
						v34 = v24 + v13;
						if (v13 < v4) {
							v5 = v44;
							if (v34 > v4) {
								if (v34 <= v44) {
									v35 = v13 - v4 + v24;
								} else {
									v35 = v44 - v4;
								}
								*getMemU32Ptr(0x973F18, 28) = v35;
								nox_draw_sprite_dstPtr_3799540 = v4 - v13 + v21;
								nox_video_cur_pixdata_3799444 = &result[2 * (v4 - v13)];
								goto LABEL_78;
							}
						} else {
							v5 = v44;
							if (v34 <= v44) {
								goto LABEL_78;
							}
						}
						if (v13 < v5 && v34 > v5) {
							*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						LABEL_78:
							func_type6_3799488();
						}
					LABEL_79:
						v27 = v43;
						result = &v37[2 * v43];
						goto LABEL_80;
					case 7:
						v28 = v24 + v13;
						if (v13 < v4) {
							v5 = v44;
							if (v28 > v4) {
								if (v28 <= v44) {
									v29 = v13 - v4 + v24;
								} else {
									v29 = v44 - v4;
								}
								*getMemU32Ptr(0x973F18, 28) = v29;
								nox_draw_sprite_dstPtr_3799540 = v4 - v13 + v21;
								nox_video_cur_pixdata_3799444 = &result[2 * (v4 - v13)];
								func_type27_3799536();
								goto LABEL_79;
							}
						} else {
							v5 = v44;
							if (v28 <= v44) {
								func_type27_3799536();
								goto LABEL_79;
							}
						}
						if (v13 < v5 && v28 > v5) {
							*getMemU32Ptr(0x973F18, 28) = v5 - v13;
							func_type27_3799536();
						}
						goto LABEL_79;
					default:
					LABEL_82:
						v5 = v44;
						goto LABEL_83;
					}
				}
			}
			if (v39) {
				v14 = v5 - v4;
				v15 = (char*)(v4 + *(unsigned int*)(v11 + (unsigned int)nox_pixbuffer_rows_3798784 - 4));
				v16 = (char*)(v4 + (unsigned int)nox_pixbuffer_rows_3798784[v11 / 4]);
				if (v5 - v4 > a3) {
					v14 = a3;
				}
				v17 = v14;
				v18 = v14 >> 2;
				memcpy(v16, v15, 4 * v18);
				v20 = &v15[4 * v18];
				v19 = &v16[4 * v18];
				LOBYTE(v18) = v17;
				v12 = a3;
				memcpy(v19, v20, v18 & 3);
				v11 = v40;
			}
			sub_4C6900(v12, 1);
			result = nox_video_cur_pixdata_3799444;
		LABEL_85:
			v11 += 4;
			v36 = v42 == 1;
			++v39;
			v40 = v11;
			--v42;
		} while (!v36);
	}
	return result;
}

//----- (004C6260) --------------------------------------------------------
int sub_4C6260(int a1, int a2, int a3) {
	int result;     // eax
	signed int v4;  // ebx
	int v5;         // edi
	int* v6;        // ecx
	int v7;         // eax
	int v8;         // ebp
	int v9;         // eax
	int v10;        // esi
	int v11;        // ecx
	int v12;        // ecx
	int4* v13;      // edi
	int v14;        // edx
	signed int v15; // esi
	void* v16;      // eax
	int v17;        // edx
	RECT rc;        // [esp+10h] [ebp-20h]
	int4 a1a;       // [esp+20h] [ebp-10h]
	int v20;        // [esp+34h] [ebp+4h]
	int v21;        // [esp+38h] [ebp+8h]
	int4* v22;      // [esp+3Ch] [ebp+Ch]

	result = nox_video_getImagePixdata_func(a1);
	nox_video_cur_pixdata_3799444 = result;
	if (result) {
		v4 = *(unsigned int*)result;
		nox_video_cur_pixdata_3799444 = result + 4;
		v5 = *(unsigned int*)(result + 4);
		v6 = (int*)(result + 8);
		nox_video_cur_pixdata_3799444 = v6;
		v7 = *(unsigned int*)(result + 8);
		++v6;
		nox_draw_sprite_offsX_3799560 = v7;
		v8 = v7 + a2;
		nox_video_cur_pixdata_3799444 = v6;
		v9 = *v6;
		nox_draw_sprite_offsY_3799556 = v9;
		v10 = v9 + a3;
		result = dword_5d4594_3799484;
		v11 = (int)(v6 + 1);
		nox_video_cur_pixdata_3799444 = v11;
		if (dword_5d4594_3799484) {
			v5 -= dword_5d4594_3799484;
			if (v5 <= 0) {
				return result;
			}
			dword_5d4594_3799476 = v5 + v10;
		}
		nox_video_cur_pixdata_3799444 = v11 + 1;
		*getMemU32Ptr(0x973F18, 92) = v8;
		*getMemU32Ptr(0x973F18, 84) = v10;
		*getMemU32Ptr(0x973F18, 88) = v4;
		*getMemU32Ptr(0x973F18, 76) = v5;
		if (!ptr_5D4594_3799572->flag_0) {
			goto LABEL_30;
		}
		SetRect(&rc, v8, v10, v4 + v8, v5 + v10);
		result = nox_xxx_utilRect_49F930(&a1a, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->clip));
		if (!result) {
			return result;
		}
		if (rc.left != a1a.field_0 || rc.right != a1a.field_8 || rc.top != a1a.field_4 || rc.bottom != a1a.field_C) {
			result = sub_4C64E0(v8, v10, v4, &a1a.field_0);
		} else {
		LABEL_30:
			result = v10 & 1;
			v20 = 0;
			dword_5d4594_3799508 ^= result;
			v12 = v5;
			v13 = (int4*)(v5 - 1);
			v22 = v13;
			if (v12) {
				v14 = 4 * v10;
				v21 = 4 * v10;
				do {
					v15 = v4;
					v16 = (void*)((unsigned int)nox_pixbuffer_rows_3798784[v14 / 4] + v8);
					nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_pixbuffer_rows_3798784[v14 / 4] + v8;
					if (dword_5d4594_3799552 && (dword_5d4594_3799508 ^= 1u) != 0) {
						if (v20) {
							memcpy(v16,
								   (const void*)(v8 +
												 *(unsigned int*)(v14 + (unsigned int)nox_pixbuffer_rows_3798784 - 4)),
								   v4);
							v13 = v22;
						}
						sub_4C6900(v4, 1);
					} else if (v4 > 0) {
						while (2) {
							*getMemU32Ptr(0x973F18, 0) = nox_video_cur_pixdata_3799444[0];
							++nox_video_cur_pixdata_3799444;
							v17 = nox_video_cur_pixdata_3799444[0];
							result = (getMemByte(0x973F18, 0) & 0xF) - 1;
							*getMemU32Ptr(0x973F18, 28) = nox_video_cur_pixdata_3799444[0];
							++nox_video_cur_pixdata_3799444;
							switch (getMemByte(0x973F18, 0) & 0xF) {
							case 1:
								nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + v17;
								goto LABEL_26;
							case 2:
							case 7:
								func_type27_3799536();
								goto LABEL_26;
							case 4:
								func_type4_3799432();
								goto LABEL_26;
							case 5:
								func_type5_3799544();
								goto LABEL_26;
							case 6:
								func_type6_3799488();
							LABEL_26:
								v15 -= *getMemU32Ptr(0x973F18, 28);
								if (v15 <= 0) {
									break;
								}
								continue;
							default:
								return result;
							}
						}
					}
					v14 = v21 + 4;
					result = (int)v13;
					v13 = (int4*)((char*)v13 - 1);
					++v20;
					v21 += 4;
					v22 = v13;
				} while (result);
			}
		}
	}
	return result;
}
#endif // NOX_CGO

//----- (004C69A0) --------------------------------------------------------
void sub_4C69A0() {
	unsigned char* v0; // esi
	unsigned char* v1; // edi
	unsigned char v2;  // dl
	int v3;            // ecx
	int v4;            // eax
	int v6;            // edx
	int v7;            // edx

	v0 = nox_video_cur_pixdata_3799444;
	v1 = *(unsigned char**)&nox_draw_sprite_dstPtr_3799540;
	v2 = getMemByte(0x973F18, 28);
	v3 = *getMemU32Ptr(0x973F18, 28) >> 2;
	if (*getMemU32Ptr(0x973F18, 28) >> 2) {
		do {
			v4 = *(unsigned int*)v0;
			v0 += 4;
			*(unsigned int*)v1 = v4;
			v1 += 4;
		} while (v3-- > 1);
	}
	v6 = v2 & 3;
	if (v6) {
		LOBYTE(v4) = *v0++;
		*v1++ = v4;
		v7 = v6 - 1;
		if (v7) {
			LOBYTE(v4) = *v0++;
			*v1++ = v4;
			if (v7 != 1) {
				LOBYTE(v4) = *v0++;
				*v1++ = v4;
			}
		}
	}
	nox_video_cur_pixdata_3799444 = v0;
	nox_draw_sprite_dstPtr_3799540 = v1;
}

#ifndef NOX_CGO
//----- (004C5EB0) --------------------------------------------------------
void sub_4C5EB0(nox_video_bag_image_t* img, int x, int y) {
	int a1 = img;
	int a2 = x;
	int a3 = y;
	int v3; // ecx
	int v4; // eax

	if (a1) {
		switch (*(uint8_t*)(a1 + 10) & 0x3F) {
		case 2:
		case 7:
			func_type27_3799536 = sub_4C69A0;
			sub_4C60D0(img, a2, a3);
			return;
		case 3:
		case 4:
		case 5:
		case 6:
			func_type5_3799544 = sub_4C7110;
			func_type6_3799488 = sub_4C6E40;
			if (!ptr_5D4594_3799572->field_13) {
				if (ptr_5D4594_3799572->field_14) {
					func_type27_3799536 = sub_4C6BA0;
					func_type4_3799432 = sub_4C7060;
					sub_4C6260(a1, a2, a3);
					return;
				}
				goto LABEL_21;
			}
			func_type5_3799544 = sub_4C7240;
			if (ptr_5D4594_3799572->field_14) {
				v3 = ptr_5D4594_3799572->field_259;
				if (v3 == 255) {
					if (!ptr_5D4594_3799572->field_16) {
						func_type27_3799536 = sub_4C6BA0;
						func_type4_3799432 = sub_4C7060;
						sub_4C6260(a1, a2, a3);
						return;
					}
					goto LABEL_21;
				}
				if (v3 == 128) {
					func_type27_3799536 = sub_4C6BF0;
					func_type4_3799432 = sub_4C6FD0;
				} else {
					func_type4_3799432 = sub_4C6E40;
					func_type27_3799536 = sub_4C6C60;
				}
				sub_4C6260(a1, a2, a3);
			} else {
				v4 = ptr_5D4594_3799572->field_259;
				if (v4 == 255) {
				LABEL_21:
					func_type27_3799536 = sub_4C69A0;
					func_type4_3799432 = sub_4C6DE0;
					sub_4C6260(a1, a2, a3);
					return;
				}
				if (v4 == 128) {
					func_type27_3799536 = sub_4C6B50;
					func_type4_3799432 = sub_4C6FD0;
				} else {
					func_type4_3799432 = sub_4C6E40;
					func_type27_3799536 = sub_4C6A00;
				}
				sub_4C6260(a1, a2, a3);
			}
			break;
		case 8:
			func_type27_3799536 = sub_4C73A0;
			sub_4C6260(a1, a2, a3);
			return;
		default:
			return;
		}
	}
}

//----- (004C9B20) --------------------------------------------------------
void sub_4C9B20() {
	unsigned short* v0; // esi
	unsigned short* v1; // edi
	unsigned int v2;    // edx
	int v3;             // eax
	unsigned int v4;    // ebx
	int v5;             // edx
	unsigned short v6;  // cx
	int result;         // eax
	int v9;             // [esp-4h] [ebp-10h]

	v0 = nox_video_cur_pixdata_3799444;
	v1 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
	v9 = *getMemU32Ptr(0x973F18, 28);
	do {
		v2 = (unsigned short)*v1;
		v3 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 0)) & *v1) >>
			 *((unsigned char*)byte_5D4594_3804364 + 12);
		v4 = (*((unsigned int*)((unsigned char*)byte_5D4594_3804364 + 4)) & v2) >>
			 *((unsigned char*)byte_5D4594_3804364 + 16);
		v5 = (*((unsigned int*)((unsigned char*)byte_5D4594_3804364 + 8)) & v2)
			 << *((unsigned char*)byte_5D4594_3804364 + 20);
		v6 = *v0;
		++v0;
		LOBYTE(v3) = SADD8(HIBYTE(v6) & 0xF8 | 7, (unsigned char)v3);
		LOBYTE(v5) = SADD8((8 * v6) & 0xF8 | 7, (unsigned char)v5);
		LOBYTE(v4) = SADD8((v6 >> 3) & 0xFC | 3, (unsigned char)v4);
		result = *(unsigned int*)(nox_draw_colors_b_3804664 + 2 * v5) |
				 *(unsigned int*)(nox_draw_colors_g_3804656 + 2 * v4) |
				 *(unsigned int*)(nox_draw_colors_r_3804672 + 2 * v3);
		*v1 = result;
		++v1;
	} while ((*getMemU32Ptr(0x973F18, 28))-- > 1);
	*getMemU32Ptr(0x973F18, 28) = v9;
	nox_video_cur_pixdata_3799444 = v0;
	nox_draw_sprite_dstPtr_3799540 = v1;
}
#endif // NOX_CGO

//----- (004C8EC0) --------------------------------------------------------
void sub_4C8EC0() {
	int result;         // eax
	unsigned short* v1; // esi
	short v2;           // di
	unsigned char v3;   // [esp+8h] [ebp-3Ch]
	int v4;             // [esp+8h] [ebp-3Ch]
	unsigned char v5;   // [esp+Ch] [ebp-38h]
	unsigned char v6;   // [esp+14h] [ebp-30h]
	char v7[40];        // [esp+1Ch] [ebp-28h]

	v3 = *(unsigned char*)(&ptr_5D4594_3799572->field_259);
	memcpy(v7, (const void*)(48 * (*getMemU32Ptr(0x973F18, 0) >> 4) + (unsigned int)(&ptr_5D4594_3799572->field_66)),
		   sizeof(v7));
	result = *getMemU32Ptr(0x973F18, 28) - 1;
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
		v2 = v3;
		v4 = *getMemU32Ptr(0x973F18, 28);
		do {
			v5 = nox_video_cur_pixdata_3799444[0];
			++nox_video_cur_pixdata_3799444;
			v6 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 4)) & *v1) >>
				 *((unsigned char*)byte_5D4594_3804364 + 16);
			**(unsigned short**)&nox_draw_sprite_dstPtr_3799540 =
				*(unsigned short*)(nox_draw_colors_r_3804672 +
								   2 * (unsigned char)(((unsigned short)(*((unsigned short*)((unsigned char*)
																								 byte_5D4594_3804364 +
																							 0)) &
																		 *v1) >>
														*((unsigned char*)byte_5D4594_3804364 + 12)) +
													   ((unsigned short)(v2 *
																		 ((unsigned char)((unsigned short)(*(unsigned short*)&v7
																											   [24] *
																										   v5) >>
																						  8) -
																		  (unsigned char)((unsigned short)(*((unsigned short*)((unsigned char*)
																																   byte_5D4594_3804364 +
																															   0)) &
																										   *v1) >>
																						  *((unsigned char*)
																								byte_5D4594_3804364 +
																							12)))) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_g_3804656 +
								   2 * (unsigned char)(v6 +
													   ((unsigned short)(v2 *
																		 ((unsigned char)((unsigned short)(*(unsigned short*)&v7
																											   [28] *
																										   v5) >>
																						  8) -
																		  v6)) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_b_3804664 +
								   2 * (unsigned char)(((*(unsigned char*)v1 &
														 *((unsigned char*)byte_5D4594_3804364 + 8))
														<< *((unsigned char*)byte_5D4594_3804364 + 20)) +
													   ((unsigned short)(v2 *
																		 ((unsigned char)((unsigned short)(*(unsigned short*)&v7
																											   [32] *
																										   v5) >>
																						  8) -
																		  (unsigned char)((*(unsigned char*)v1 &
																						   *((unsigned char*)
																								 byte_5D4594_3804364 +
																							 8))
																						  << *((unsigned char*)
																								   byte_5D4594_3804364 +
																							   20)))) >>
														8)));
			v1 = (unsigned short*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 2);
			result = v4 - 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			v4 = result;
		} while (result);
	}
}

//----- (004C9050) --------------------------------------------------------
void sub_4C9050() {
	int result;         // eax
	unsigned short* v1; // edi
	unsigned char v2;   // cl
	unsigned int v3;    // edx
	int v4;             // [esp+8h] [ebp-3Ch]
	char v5[40];        // [esp+1Ch] [ebp-28h]

	result = *getMemU32Ptr(0x973F18, 28) - 1;
	memcpy(v5, (const void*)(48 * (*getMemU32Ptr(0x973F18, 0) >> 4) + (unsigned int)(&ptr_5D4594_3799572->field_66)),
		   sizeof(v5));
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
		v4 = *getMemU32Ptr(0x973F18, 28);
		do {
			v2 = nox_video_cur_pixdata_3799444[0];
			++nox_video_cur_pixdata_3799444;
			v3 = (unsigned short)*v1;
			*v1 =
				*(unsigned short*)(nox_draw_colors_r_3804672 +
								   2 * (unsigned char)(((*((unsigned int*)((unsigned char*)byte_5D4594_3804364 + 0)) &
														 v3) >>
														*((unsigned char*)byte_5D4594_3804364 + 12)) +
													   ((int)((((*(unsigned int*)&v5[24] * (unsigned int)v2) >> 8) &
															   0xFF) -
															  (unsigned char)((*((unsigned int*)((unsigned char*)
																									 byte_5D4594_3804364 +
																								 0)) &
																			   v3) >>
																			  *((unsigned char*)byte_5D4594_3804364 +
																				12))) >>
														1))) |
				*(unsigned short*)(nox_draw_colors_g_3804656 +
								   2 * (unsigned char)(((*((unsigned int*)((unsigned char*)byte_5D4594_3804364 + 4)) &
														 v3) >>
														*((unsigned char*)byte_5D4594_3804364 + 16)) +
													   ((int)((((*(unsigned int*)&v5[28] * (unsigned int)v2) >> 8) &
															   0xFF) -
															  (unsigned char)((*((unsigned int*)((unsigned char*)
																									 byte_5D4594_3804364 +
																								 4)) &
																			   v3) >>
																			  *((unsigned char*)byte_5D4594_3804364 +
																				16))) >>
														1))) |
				*(unsigned short*)(nox_draw_colors_b_3804664 +
								   2 * (unsigned char)(((*(unsigned char*)v1 &
														 *((unsigned char*)byte_5D4594_3804364 + 8))
														<< *((unsigned char*)byte_5D4594_3804364 + 20)) +
													   ((int)((((*(unsigned int*)&v5[32] * (unsigned int)v2) >> 8) &
															   0xFF) -
															  (unsigned char)((*(unsigned char*)v1 &
																			   *((unsigned char*)byte_5D4594_3804364 +
																				 8))
																			  << *((unsigned char*)byte_5D4594_3804364 +
																				   20))) >>
														1)));
			v1 = (unsigned short*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 2);
			result = v4 - 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			v4 = result;
		} while (result);
	}
}

//----- (004C92F0) --------------------------------------------------------
void sub_4C92F0() {
	int result;         // eax
	unsigned short* v1; // esi
	unsigned char v2;   // dl
	int v3;             // eax
	bool v4;            // zf
	unsigned char v5;   // [esp+8h] [ebp-48h]
	int v6;             // [esp+8h] [ebp-48h]
	unsigned char v7;   // [esp+Ch] [ebp-44h]
	unsigned char v8;   // [esp+10h] [ebp-40h]
	unsigned char v9;   // [esp+14h] [ebp-3Ch]
	unsigned char v10;  // [esp+1Ch] [ebp-34h]
	int v11;            // [esp+20h] [ebp-30h]
	char v12[40];       // [esp+28h] [ebp-28h]

	v9 = *(unsigned char*)(&ptr_5D4594_3799572->field_259);
	v8 = *(unsigned char*)(&ptr_5D4594_3799572->field_24);
	v7 = *(unsigned char*)(&ptr_5D4594_3799572->field_25);
	v5 = *(unsigned char*)(&ptr_5D4594_3799572->field_26);
	memcpy(v12, (const void*)(48 * (*getMemU32Ptr(0x973F18, 0) >> 4) + (unsigned int)(&ptr_5D4594_3799572->field_66)),
		   sizeof(v12));
	result = *getMemU32Ptr(0x973F18, 28) - 1;
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
		v11 = v5;
		v6 = *getMemU32Ptr(0x973F18, 28);
		do {
			v2 = nox_video_cur_pixdata_3799444[0];
			++nox_video_cur_pixdata_3799444;
			v3 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 0)) & *v1) >>
				 *((unsigned char*)byte_5D4594_3804364 + 12);
			v10 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 4)) & *v1) >>
				  *((unsigned char*)byte_5D4594_3804364 + 16);
			**(unsigned short**)&nox_draw_sprite_dstPtr_3799540 =
				*(unsigned short*)(nox_draw_colors_b_3804664 +
								   2 * (unsigned char)(((*(unsigned char*)v1 &
														 *((unsigned char*)byte_5D4594_3804364 + 8))
														<< *((unsigned char*)byte_5D4594_3804364 + 20)) +
													   ((unsigned short)(v9 *
																		 (((int)(v11 * (((*(unsigned int*)&v12[32] *
																						  (unsigned int)v2) >>
																						 8) &
																						0xFF)) >>
																		   8) -
																		  (unsigned char)((*(unsigned char*)v1 &
																						   *((unsigned char*)
																								 byte_5D4594_3804364 +
																							 8))
																						  << *((unsigned char*)
																								   byte_5D4594_3804364 +
																							   20)))) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_g_3804656 +
								   2 * (unsigned char)(v10 +
													   ((unsigned short)(v9 * (((int)(v7 * (((*(unsigned int*)&v12[28] *
																							  (unsigned int)v2) >>
																							 8) &
																							0xFF)) >>
																				8) -
																			   v10)) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_r_3804672 +
								   2 * (unsigned char)(v3 +
													   ((unsigned short)(v9 * (((int)(v8 * (((*(unsigned int*)&v12[24] *
																							  (unsigned int)v2) >>
																							 8) &
																							0xFF)) >>
																				8) -
																			   (unsigned char)v3)) >>
														8)));
			v1 = (unsigned short*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 2);
			result = v6 - 1;
			v4 = v6 == 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			--v6;
		} while (!v4);
	}
}

//----- (004C8850) --------------------------------------------------------
void sub_4C8850() {
	int result;         // eax
	unsigned short* v1; // edi
	unsigned char v2;   // al
	bool v3;            // zf
	int v4;             // [esp+0h] [ebp-28h]
	unsigned char v5;   // [esp+4h] [ebp-24h]
	unsigned char v6;   // [esp+8h] [ebp-20h]
	unsigned char v7;   // [esp+Ch] [ebp-1Ch]
	int v8;             // [esp+14h] [ebp-14h]
	unsigned char v9;   // [esp+18h] [ebp-10h]
	int v10;            // [esp+20h] [ebp-8h]

	v7 = *(unsigned char*)(&ptr_5D4594_3799572->field_259);
	v6 = *(unsigned char*)(&ptr_5D4594_3799572->field_24);
	result = *getMemU32Ptr(0x973F18, 28) - 1;
	if (*getMemU32Ptr(0x973F18, 28)) {
		v10 = *(unsigned char*)(&ptr_5D4594_3799572->field_26);
		v8 = *(unsigned char*)(&ptr_5D4594_3799572->field_25);
		v1 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
		v4 = *getMemU32Ptr(0x973F18, 28);
		do {
			v5 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 0)) & *v1) >>
				 *((unsigned char*)byte_5D4594_3804364 + 12);
			v2 = (*(unsigned char*)v1 & *((unsigned char*)byte_5D4594_3804364 + 8))
				 << *((unsigned char*)byte_5D4594_3804364 + 20);
			v9 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 4)) & *v1) >>
				 *((unsigned char*)byte_5D4594_3804364 + 16);
			*v1 =
				*(unsigned short*)(nox_draw_colors_b_3804664 +
								   2 * (unsigned char)(v2 +
													   ((unsigned short)(v7 *
																		 (((v10 *
																			(unsigned char)(((unsigned char)*(
																								 unsigned short*)(&nox_video_cur_pixdata_3799444
																													  [0]) &
																							 *((unsigned char*)
																								   byte_5D4594_3804364 +
																							   8))
																							<< *((unsigned char*)
																									 byte_5D4594_3804364 +
																								 20))) >>
																		   8) -
																		  v2)) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_g_3804656 +
								   2 * (unsigned char)(v9 +
													   ((unsigned short)(v7 *
																		 (((v8 *
																			(unsigned char)((unsigned short)(*((unsigned short*)((unsigned char*)
																																	 byte_5D4594_3804364 +
																																 4)) &
																											 *(unsigned short*)(&nox_video_cur_pixdata_3799444
																																	[0])) >>
																							*((unsigned char*)
																								  byte_5D4594_3804364 +
																							  16))) >>
																		   8) -
																		  v9)) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_r_3804672 +
								   2 * (unsigned char)(v5 +
													   ((unsigned short)(v7 *
																		 (((v6 *
																			(unsigned char)((unsigned short)(*((unsigned short*)((unsigned char*)
																																	 byte_5D4594_3804364 +
																																 0)) &
																											 *(unsigned short*)(&nox_video_cur_pixdata_3799444
																																	[0])) >>
																							*((unsigned char*)
																								  byte_5D4594_3804364 +
																							  12))) >>
																		   8) -
																		  v5)) >>
														8)));
			nox_video_cur_pixdata_3799444 += 2;
			v1 = (unsigned short*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 2);
			result = v4 - 1;
			v3 = v4 == 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			--v4;
		} while (!v3);
	}
}

//----- (004C94D0) --------------------------------------------------------
void sub_4C94D0() {
	unsigned char v0;   // dl
	int result;         // eax
	unsigned short* v2; // edi
	int v3;             // eax
	int v4;             // [esp+8h] [ebp-48h]
	unsigned char v5;   // [esp+Ch] [ebp-44h]
	unsigned char v6;   // [esp+10h] [ebp-40h]
	int v7;             // [esp+14h] [ebp-3Ch]
	int v8;             // [esp+1Ch] [ebp-34h]
	char v9[40];        // [esp+28h] [ebp-28h]

	v0 = *(unsigned char*)(&ptr_5D4594_3799572->field_24);
	memcpy(v9, (const void*)(48 * (*getMemU32Ptr(0x973F18, 0) >> 4) + (unsigned int)(&ptr_5D4594_3799572->field_66)),
		   sizeof(v9));
	result = *getMemU32Ptr(0x973F18, 28) - 1;
	if (*getMemU32Ptr(0x973F18, 28)) {
		v2 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
		v8 = *(unsigned char*)(&ptr_5D4594_3799572->field_26);
		v7 = *(unsigned char*)(&ptr_5D4594_3799572->field_25);
		v4 = *getMemU32Ptr(0x973F18, 28);
		do {
			v6 = nox_video_cur_pixdata_3799444[0];
			++nox_video_cur_pixdata_3799444;
			v3 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 0)) & *v2) >>
				 *((unsigned char*)byte_5D4594_3804364 + 12);
			v5 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 4)) & *v2) >>
				 *((unsigned char*)byte_5D4594_3804364 + 16);
			*v2 =
				*(unsigned short*)(nox_draw_colors_r_3804672 +
								   2 * (((v0 *
										  (unsigned char)(v3 +
														  ((int)((((*(unsigned int*)&v9[24] * (unsigned int)v6) >> 8) &
																  0xFF) -
																 (unsigned char)v3) >>
														   1))) >>
										 8) &
										0xFF)) |
				*(unsigned short*)(nox_draw_colors_b_3804664 +
								   2 * (((v8 *
										  (unsigned char)(((*(unsigned char*)v2 &
															*((unsigned char*)byte_5D4594_3804364 + 8))
														   << *((unsigned char*)byte_5D4594_3804364 + 20)) +
														  ((int)((((*(unsigned int*)&v9[32] * (unsigned int)v6) >> 8) &
																  0xFF) -
																 (unsigned char)((*(unsigned char*)v2 &
																				  *((unsigned char*)
																						byte_5D4594_3804364 +
																					8))
																				 << *((unsigned char*)
																						  byte_5D4594_3804364 +
																					  20))) >>
														   1))) >>
										 8) &
										0xFF)) |
				*(unsigned short*)(nox_draw_colors_g_3804656 +
								   2 * (((v7 *
										  (unsigned char)(v5 +
														  ((int)((((*(unsigned int*)&v9[28] * (unsigned int)v6) >> 8) &
																  0xFF) -
																 v5) >>
														   1))) >>
										 8) &
										0xFF));
			v2 = (unsigned short*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 2);
			result = v4 - 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			v4 = result;
		} while (result);
	}
}

//----- (004C97F0) --------------------------------------------------------
void sub_4C97F0() {
	int result;         // eax
	int v1;             // ecx
	unsigned short* v2; // edi
	unsigned int v3;    // eax
	unsigned int v4;    // ebx
	int v5;             // edx
	unsigned char v6;   // [esp+8h] [ebp-10h]
	int v7;             // [esp+8h] [ebp-10h]
	int v8;             // [esp+Ch] [ebp-Ch]

	result = *getMemU32Ptr(0x973F18, 28) - 1;
	v6 = *(unsigned char*)(&ptr_5D4594_3799572->field_259);
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = v6;
		v2 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
		v8 = v6;
		v7 = *getMemU32Ptr(0x973F18, 28);
		while (1) {
			v4 = (unsigned short)*v2;
			unsigned short v3 = *(unsigned short*)(&nox_video_cur_pixdata_3799444[0]);
			v5 = v1 * 16 * (*(unsigned short*)(&nox_video_cur_pixdata_3799444[0]) & 0xF);
			*v2 =
				*(unsigned short*)(nox_draw_colors_b_3804664 +
								   2 * (unsigned char)(((*(unsigned char*)v2 &
														 *((unsigned char*)byte_5D4594_3804364 + 8))
														<< *((unsigned char*)byte_5D4594_3804364 + 20)) +
													   ((unsigned short)(BYTE1(v5) *
																		 ((*(unsigned short*)(&nox_video_cur_pixdata_3799444
																								  [0]) &
																		   0xF0) -
																		  (unsigned char)((*(unsigned char*)v2 &
																						   *((unsigned char*)
																								 byte_5D4594_3804364 +
																							 8))
																						  << *((unsigned char*)
																								   byte_5D4594_3804364 +
																							   20)))) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_r_3804672 +
								   2 * (unsigned char)(((*((unsigned int*)((unsigned char*)byte_5D4594_3804364 + 0)) &
														 v4) >>
														*((unsigned char*)byte_5D4594_3804364 + 12)) +
													   ((unsigned short)(BYTE1(v5) *
																		 (((*(unsigned short*)(&nox_video_cur_pixdata_3799444
																								   [0]) >>
																			8) &
																		   0xF0) -
																		  (unsigned char)((*((unsigned int*)((unsigned char*)
																												 byte_5D4594_3804364 +
																											 0)) &
																						   v4) >>
																						  *((unsigned char*)
																								byte_5D4594_3804364 +
																							12)))) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_g_3804656 +
								   2 * (unsigned char)(((*((unsigned int*)((unsigned char*)byte_5D4594_3804364 + 4)) &
														 v4) >>
														*((unsigned char*)byte_5D4594_3804364 + 16)) +
													   ((unsigned short)(BYTE1(v5) *
																		 (((v3 >> 4) & 0xF0) -
																		  (unsigned char)((*((unsigned int*)((unsigned char*)
																												 byte_5D4594_3804364 +
																											 4)) &
																						   v4) >>
																						  *((unsigned char*)
																								byte_5D4594_3804364 +
																							16)))) >>
														8)));
			v2 = (unsigned short*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 2);
			result = v7 - 1;
			nox_video_cur_pixdata_3799444 += 2;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			v7 = result;
			if (!result) {
				break;
			}
			v1 = v8;
		}
	}
}

#ifndef NOX_CGO
//----- (004C8DF0) --------------------------------------------------------
void sub_4C8DF0() {
	int result;       // eax
	int v1;           // ecx
	int v2;           // esi
	int v3;           // edi
	bool v4;          // zf
	int v5;           // [esp+8h] [ebp-30h]
	unsigned char v6; // [esp+Ch] [ebp-2Ch]
	char v7[40];      // [esp+10h] [ebp-28h]

	result = *getMemU32Ptr(0x973F18, 28) - 1;
	memcpy(v7, (const void*)(48 * (*getMemU32Ptr(0x973F18, 0) >> 4) + (unsigned int)(&ptr_5D4594_3799572->field_66)),
		   sizeof(v7));
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = *(unsigned int*)&v7[32];
		v2 = *(unsigned int*)&v7[28];
		v3 = *(unsigned int*)&v7[24];
		v5 = *getMemU32Ptr(0x973F18, 28);
		do {
			v6 = nox_video_cur_pixdata_3799444[0];
			++nox_video_cur_pixdata_3799444;
			**(unsigned short**)&nox_draw_sprite_dstPtr_3799540 =
				*(unsigned short*)(nox_draw_colors_r_3804672 + 2 * ((v3 * (unsigned int)v6) >> 8)) |
				*(unsigned short*)(nox_draw_colors_g_3804656 + 2 * ((v2 * (unsigned int)v6) >> 8)) |
				*(unsigned short*)(nox_draw_colors_b_3804664 + 2 * ((v1 * (unsigned int)v6) >> 8));
			result = v5 - 1;
			v4 = v5 == 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			--v5;
		} while (!v4);
	}
}

//----- (004C8D60) --------------------------------------------------------
void sub_4C8D60() {
	unsigned short* v0; // esi
	unsigned short* v1; // edi
	unsigned short v2;  // ax
	int v3;             // eax
	int result;         // eax
	int v6;             // [esp-4h] [ebp-10h]

	v0 = nox_video_cur_pixdata_3799444;
	v1 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
	v6 = *getMemU32Ptr(0x973F18, 28);
	do {
		v2 = *v0;
		++v0;
		v3 = (unsigned char)*(unsigned int*)((unsigned int)nox_draw_colorTablesRev_3804668 + v2);
		result = *(unsigned int*)(nox_draw_colors_r_3804672 +
								  2 * ((unsigned int)(*(unsigned int*)(&obj_5D4594_3800716.field_24) * v3) >> 8)) |
				 *(unsigned int*)(nox_draw_colors_g_3804656 +
								  2 * ((unsigned int)(*(unsigned int*)(&obj_5D4594_3800716.field_25) * v3) >> 8)) |
				 *(unsigned int*)(nox_draw_colors_b_3804664 +
								  2 * ((unsigned int)(*(unsigned int*)(&obj_5D4594_3800716.field_26) * v3) >> 8));
		*v1 = result;
		++v1;
	} while ((*getMemU32Ptr(0x973F18, 28))-- > 1);
	*getMemU32Ptr(0x973F18, 28) = v6;
	nox_video_cur_pixdata_3799444 = v0;
	nox_draw_sprite_dstPtr_3799540 = v1;
}

//----- (004C91C0) --------------------------------------------------------
void sub_4C91C0() {
	int result;       // eax
	int v1;           // ecx
	int v2;           // edi
	bool v3;          // zf
	unsigned char v4; // [esp+8h] [ebp-34h]
	int v5;           // [esp+8h] [ebp-34h]
	unsigned char v6; // [esp+Ch] [ebp-30h]
	unsigned char v7; // [esp+10h] [ebp-2Ch]
	unsigned char v8; // [esp+10h] [ebp-2Ch]
	char v9[40];      // [esp+14h] [ebp-28h]

	v7 = *(unsigned char*)(&ptr_5D4594_3799572->field_24);
	v6 = *(unsigned char*)(&ptr_5D4594_3799572->field_25);
	v4 = *(unsigned char*)(&ptr_5D4594_3799572->field_26);
	result = *getMemU32Ptr(0x973F18, 28) - 1;
	memcpy(v9, (const void*)(48 * (*getMemU32Ptr(0x973F18, 0) >> 4) + (unsigned int)(&ptr_5D4594_3799572->field_66)),
		   sizeof(v9));
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = v4;
		v2 = v7;
		v5 = *getMemU32Ptr(0x973F18, 28);
		do {
			v8 = nox_video_cur_pixdata_3799444[0];
			++nox_video_cur_pixdata_3799444;
			**(unsigned short**)&nox_draw_sprite_dstPtr_3799540 =
				*(unsigned short*)(nox_draw_colors_b_3804664 +
								   2 * (((int)(v1 * (((*(unsigned int*)&v9[32] * (unsigned int)v8) >> 8) & 0xFF)) >>
										 8) &
										0xFF)) |
				*(unsigned short*)(nox_draw_colors_g_3804656 +
								   2 * (((int)(v6 * (((*(unsigned int*)&v9[28] * (unsigned int)v8) >> 8) & 0xFF)) >>
										 8) &
										0xFF)) |
				*(unsigned short*)(nox_draw_colors_r_3804672 +
								   2 * (((int)(v2 * (((*(unsigned int*)&v9[24] * (unsigned int)v8) >> 8) & 0xFF)) >>
										 8) &
										0xFF));
			result = v5 - 1;
			v3 = v5 == 1;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			--v5;
		} while (!v3);
	}
}

//----- (004C9970) --------------------------------------------------------
void sub_4C9970() {
	unsigned int result; // eax
	int v1;              // ebp
	unsigned short* v2;  // edi
	short v3;            // si
	unsigned char v4;    // [esp+0h] [ebp-1Ch]
	unsigned char v5;    // [esp+4h] [ebp-18h]
	unsigned int v6;     // [esp+8h] [ebp-14h]
	unsigned char v7;    // [esp+14h] [ebp-8h]
	int v8;              // [esp+18h] [ebp-4h]

	v5 = *(unsigned char*)(&ptr_5D4594_3799572->field_24);
	result = *getMemU32Ptr(0x973F18, 28) - 1;
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = *(unsigned char*)(&ptr_5D4594_3799572->field_25);
		HIWORD(result) = *getMemU16Ptr(0x973F18, 30);
		v2 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
		v8 = *(unsigned char*)(&ptr_5D4594_3799572->field_26);
		v6 = *getMemU32Ptr(0x973F18, 28);
		do {
			LOWORD(result) = *(unsigned short*)(&nox_video_cur_pixdata_3799444[0]);
			v7 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 0)) & *v2) >>
				 *((unsigned char*)byte_5D4594_3804364 + 12);
			v3 = (unsigned char)(16 * *(unsigned short*)(&nox_video_cur_pixdata_3799444[0]));
			v4 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 4)) & *v2) >>
				 *((unsigned char*)byte_5D4594_3804364 + 16);
			*v2 =
				*(unsigned short*)(nox_draw_colors_b_3804664 +
								   2 * (unsigned char)(((*(unsigned char*)v2 &
														 *((unsigned char*)byte_5D4594_3804364 + 8))
														<< *((unsigned char*)byte_5D4594_3804364 + 20)) +
													   ((unsigned short)(v3 *
																		 (((v8 *
																			(*(unsigned short*)(&nox_video_cur_pixdata_3799444
																									[0]) &
																			 0xF0)) >>
																		   8) -
																		  (unsigned char)((*(unsigned char*)v2 &
																						   *((unsigned char*)
																								 byte_5D4594_3804364 +
																							 8))
																						  << *((unsigned char*)
																								   byte_5D4594_3804364 +
																							   20)))) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_g_3804656 +
								   2 * (unsigned char)(v4 +
													   ((unsigned short)(v3 *
																		 (((int)(v1 * ((result >> 4) & 0xF0)) >> 8) -
																		  v4)) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_r_3804672 +
								   2 * (unsigned char)(v7 +
													   ((unsigned short)(v3 *
																		 (((v5 *
																			((*(unsigned short*)(&nox_video_cur_pixdata_3799444
																									 [0]) >>
																			  8) &
																			 0xF0)) >>
																		   8) -
																		  v7)) >>
														8)));
			v2 = (unsigned short*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 2);
			result = v6 - 1;
			nox_video_cur_pixdata_3799444 += 2;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			v6 = result;
		} while (result);
	}
}

//----- (004C96A0) --------------------------------------------------------
void sub_4C96A0() {
	unsigned int result; // eax
	unsigned short* v1;  // edi
	short v2;            // si
	unsigned char v3;    // [esp+0h] [ebp-14h]
	unsigned int v4;     // [esp+8h] [ebp-Ch]
	unsigned char v5;    // [esp+10h] [ebp-4h]

	result = *getMemU32Ptr(0x973F18, 28) - 1;
	if (*getMemU32Ptr(0x973F18, 28)) {
		HIWORD(result) = *getMemU16Ptr(0x973F18, 30);
		v1 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
		v4 = *getMemU32Ptr(0x973F18, 28);
		do {
			LOWORD(result) = *(unsigned short*)(&nox_video_cur_pixdata_3799444[0]);
			v2 = (unsigned char)(16 * *(unsigned short*)(&nox_video_cur_pixdata_3799444[0]));
			v5 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 0)) & *v1) >>
				 *((unsigned char*)byte_5D4594_3804364 + 12);
			v3 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 4)) & *v1) >>
				 *((unsigned char*)byte_5D4594_3804364 + 16);
			*v1 =
				*(unsigned short*)(nox_draw_colors_b_3804664 +
								   2 * (unsigned char)(((*(unsigned char*)v1 &
														 *((unsigned char*)byte_5D4594_3804364 + 8))
														<< *((unsigned char*)byte_5D4594_3804364 + 20)) +
													   ((unsigned short)(v2 *
																		 ((*(unsigned short*)(&nox_video_cur_pixdata_3799444
																								  [0]) &
																		   0xF0) -
																		  (unsigned char)((*(unsigned char*)v1 &
																						   *((unsigned char*)
																								 byte_5D4594_3804364 +
																							 8))
																						  << *((unsigned char*)
																								   byte_5D4594_3804364 +
																							   20)))) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_r_3804672 +
								   2 * (unsigned char)(v5 +
													   ((unsigned short)(v2 *
																		 (((*(unsigned short*)(&nox_video_cur_pixdata_3799444
																								   [0]) >>
																			8) &
																		   0xF0) -
																		  v5)) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_g_3804656 +
								   2 * (unsigned char)(v3 +
													   ((unsigned short)(v2 * (((result >> 4) & 0xF0) - v3)) >> 8)));
			v1 = (unsigned short*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 2);
			result = v4 - 1;
			nox_video_cur_pixdata_3799444 += 2;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			v4 = result;
		} while (result);
	}
}

//----- (004C80E0) --------------------------------------------------------
void sub_4C80E0() {
	const uint32_t size = *getMemU32Ptr(0x973F18, 28) << 1;
	memcpy(nox_draw_sprite_dstPtr_3799540, nox_video_cur_pixdata_3799444, size);
	nox_video_cur_pixdata_3799444 += size;
	nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + size;
}
#endif // NOX_CGO

void nullsub_7(void) {}

short sub_4C82C0() {
	abort();
	return 0;
}

short sub_4C8570() {
	abort();
	return 0;
}

int sub_4C8760() {
	abort();
	return 0;
}

short sub_4C8C00() {
	abort();
	return 0;
}

#ifndef NOX_CGO
//----- (004C7860) --------------------------------------------------------
void nox_client_drawImg_bbb_4C7860(int a1, int a2, int a3) {
	unsigned char* result = nox_video_getImagePixdata_func(a1);
	nox_video_cur_pixdata_3799444 = result;
	if (!result) {
		return;
	}
	int v4 = *(int*)(&result[0]);
	int* v5 = &result[4];
	nox_video_cur_pixdata_3799444 = v5;
	int v6 = v5[0];
	++v5;
	int v7 = v4;
	nox_video_cur_pixdata_3799444 = v5;
	int v8 = *v5;
	++v5;
	nox_draw_sprite_offsX_3799560 = v8;
	int v9 = v8 + a2;
	nox_video_cur_pixdata_3799444 = v5;
	nox_draw_sprite_offsY_3799556 = *v5;
	int v10 = nox_draw_sprite_offsY_3799556 + a3;
	result = v5 + 1;
	int v20 = nox_draw_sprite_offsY_3799556 + a3;
	nox_video_cur_pixdata_3799444 = result;
	if (dword_5d4594_3799484) {
		v6 = v6 - dword_5d4594_3799484;
		if (v6 <= 0) {
			return;
		}
		dword_5d4594_3799476 = v6 + v10;
	}
	*getMemU32Ptr(0x973F18, 92) = v8 + a2;
	nox_video_cur_pixdata_3799444 = (char*)result + 1;
	*getMemU32Ptr(0x973F18, 84) = v10;
	*getMemU32Ptr(0x973F18, 88) = v4;
	*getMemU32Ptr(0x973F18, 76) = v6;
	if (ptr_5D4594_3799572->flag_0) {
		RECT rc;
		SetRect(&rc, v9, v10, v4 + v9, v6 + v10);
		int4 a1a;
		if (!nox_xxx_utilRect_49F930(&a1a, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->clip))) {
			return;
		}
		int v11 = a1a.field_0 - rc.left;
		int v12 = a1a.field_4 - rc.top;
		v7 = a1a.field_8 - a1a.field_0;
		v6 = a1a.field_C - a1a.field_4;
		if (a1a.field_0 != rc.left || v12) {
			v9 += v11;
			nox_video_cur_pixdata_3799444 += v4 * v12 + 2 * v11;
			v10 = v12 + v20;
		} else {
			v10 = v20;
		}
	}
	int v13 = 2 * v9;
	int v14 = 2 * (v4 - v7);
	int v15 = v6 - 1;
	*getMemU32Ptr(0x973F18, 28) = v7;
	if (v6) {
		int v16 = 4 * v10;
		int v17 = v15 + 1;
		do {
			v16 += 4;
			nox_draw_sprite_dstPtr_3799540 = v13 + *(unsigned int*)((unsigned int)nox_pixbuffer_rows_3798784 + v16 - 4);
			func_type27_3799536();
			--v17;
			nox_video_cur_pixdata_3799444 += v14;
		} while (v17);
	}
}

//----- (004C8040) --------------------------------------------------------
void nox_client_draw_skip_4C8040(int width, int skip) {
	char* pix = nox_video_cur_pixdata_3799444;
	for (int i = 0; i < skip; i++) {
		unsigned char val = 0;
		for (int j = 0; j < width; j += val) {
			char op = pix[0];
			val = pix[1];
			pix = pix + 2;
			nox_video_cur_pixdata_3799444 = pix;
			switch (op & 0xF) {
			case 2:
			case 5:
			case 6:
			case 7:
				pix += 2 * val;
				nox_video_cur_pixdata_3799444 = pix;
				break;
			case 4:
				pix += val;
				nox_video_cur_pixdata_3799444 = pix;
				break;
			}
		}
	}
}

//----- (004C7C80) --------------------------------------------------------
void nox_client_drawXxx_4C7C80(int x, int y, int width, int4* a4) {
	int v4 = a4->field_0;
	int v5 = a4->field_8;
	int v8 = a4->field_4 - y;
	int v9 = a4->field_C - a4->field_4;
	int v45 = a4->field_8;
	if (dword_5d4594_3799484) {
		v9 -= dword_5d4594_3799484;
		if (v9 <= 0) {
			return;
		}
		dword_5d4594_3799476 = v9 + y;
	}
	int v7 = y;
	if (v8) {
		v7 = v8 + y;
		nox_client_draw_skip_4C8040(width, v8);
	}
	dword_5d4594_3799508 ^= v7 & 1;
	if (!v9) {
		return;
	}
	unsigned char* pix = nox_video_cur_pixdata_3799444;
	for (int i = 0; i < v9; i++) {
		int v11 = v7 + i;
		int v13 = x;
		int v42 = width;
		if (dword_5d4594_3799552 && (dword_5d4594_3799508 ^= 1u) != 0) {
			if (i != 0) {
				char* v14 = &nox_pixbuffer_rows_3798784[v11 - 1][2 * v4];
				char* v15 = &nox_pixbuffer_rows_3798784[v11][2 * v4];
				int v16 = v5 - v4;
				if (v5 - v4 > width) {
					v16 = width;
				}
				unsigned int v17 = 2 * v16;
				char v18 = v17;
				v17 >>= 2;
				memcpy(v15, v14, 4 * v17);
				char* v20 = &v14[4 * v17];
				char* v19 = &v15[4 * v17];
				memcpy(v19, v20, v18 & 3);
			}
			nox_client_draw_skip_4C8040(width, 1);
			pix = nox_video_cur_pixdata_3799444;
			continue;
		}
		int v21 = &nox_pixbuffer_rows_3798784[v11][2 * x];
		nox_draw_sprite_dstPtr_3799540 = v21;
		if (width <= 0) {
			continue;
		}
		int v30;
		while (1) {
			int v39 = v21;
			int v22 = *pix;
			unsigned char* v23 = pix + 1;
			*getMemU32Ptr(0x973F18, 0) = v22;
			nox_video_cur_pixdata_3799444 = v23;
			int v24 = *v23; // TODO: custom bag images fail here
			pix = v23 + 1;
			*getMemU32Ptr(0x973F18, 28) = v24;
			nox_video_cur_pixdata_3799444 = pix;
			unsigned char* v38 = pix;
			int v44 = v24;
			switch (getMemByte(0x973F18, 0) & 0xF) {
			case 1:
				v21 += 2 * v24;
				nox_draw_sprite_dstPtr_3799540 = v21;
				v5 = v45;
				break;
			case 2:
			case 7:;
				int v25 = v24 + v13;
				if (v13 < v4) {
					v5 = v45;
					if (v25 > v4) {
						int v26 = 0;
						if (v25 <= v45) {
							v26 = v13 - v4 + v24;
						} else {
							v26 = v45 - v4;
						}
						*getMemU32Ptr(0x973F18, 28) = v26;
						int v27 = 2 * (v4 - v13);
						nox_video_cur_pixdata_3799444 = &pix[v27];
						nox_draw_sprite_dstPtr_3799540 = v27 + v21;
						func_type27_3799536();
					} else if (v13 < v5 && v25 > v5) {
						*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						func_type27_3799536();
					}
				} else {
					v5 = v45;
					if (v25 <= v45) {
						func_type27_3799536();
					} else if (v13 < v5 && v25 > v5) {
						*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						func_type27_3799536();
					}
				}
				v30 = v44;
				pix = &v38[2 * v44];
				nox_video_cur_pixdata_3799444 = pix;
				v21 = v39 + 2 * v30;
				nox_draw_sprite_dstPtr_3799540 = v39 + 2 * v30;
				break;
			case 4:;
				int v28 = v24 + v13;
				if (v13 < v4) {
					v5 = v45;
					if (v28 > v4) {
						int v29 = 0;
						if (v28 <= v45) {
							v29 = v13 - v4 + v24;
						} else {
							v29 = v45 - v4;
						}
						*getMemU32Ptr(0x973F18, 28) = v29;
						nox_video_cur_pixdata_3799444 = &pix[v4 - v13];
						nox_draw_sprite_dstPtr_3799540 = v21 + 2 * (v4 - v13);
						func_type4_3799432();
					} else if (v13 < v5 && v28 > v5) {
						*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						func_type4_3799432();
					}
				} else {
					v5 = v45;
					if (v28 <= v45) {
						func_type4_3799432();
					} else if (v13 < v5 && v28 > v5) {
						*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						func_type4_3799432();
					}
				}
				v30 = v44;
				pix = &v38[v44];
				nox_video_cur_pixdata_3799444 = pix;
				v21 = v39 + 2 * v30;
				nox_draw_sprite_dstPtr_3799540 = v39 + 2 * v30;
				break;
			case 5:;
				int v31 = v24 + v13;
				if (v13 < v4) {
					v5 = v45;
					if (v31 > v4) {
						int v32 = 0;
						if (v31 <= v45) {
							v32 = v13 - v4 + v24;
						} else {
							v32 = v45 - v4;
						}
						*getMemU32Ptr(0x973F18, 28) = v32;
						int v33 = 2 * (v4 - v13);
						nox_video_cur_pixdata_3799444 = &pix[v33];
						nox_draw_sprite_dstPtr_3799540 = v33 + v21;
						func_type5_3799544();
					} else if (v13 < v5 && v31 > v5) {
						*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						func_type5_3799544();
					}
				} else {
					v5 = v45;
					if (v31 <= v45) {
						func_type5_3799544();
					} else if (v13 < v5 && v31 > v5) {
						*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						func_type5_3799544();
					}
				}
				pix = &v38[2 * v44];
				v21 = v39 + 2 * v44;
				nox_video_cur_pixdata_3799444 = &v38[2 * v44];
				nox_draw_sprite_dstPtr_3799540 = v39 + 2 * v44;
				break;
			case 6:;
				int v34 = v24 + v13;
				if (v13 < v4) {
					v5 = v45;
					if (v34 > v4) {
						int v35 = 0;
						if (v34 <= v45) {
							v35 = v13 - v4 + v24;
						} else {
							v35 = v45 - v4;
						}
						*getMemU32Ptr(0x973F18, 28) = v35;
						int v36 = 2 * (v4 - v13);
						nox_video_cur_pixdata_3799444 = &pix[v36];
						nox_draw_sprite_dstPtr_3799540 = v36 + v21;
						func_type6_3799488();
					} else if (v13 < v5 && v34 > v5) {
						*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						func_type6_3799488();
					}
				} else {
					v5 = v45;
					if (v34 <= v45) {
						func_type6_3799488();
					} else if (v13 < v5 && v34 > v5) {
						*getMemU32Ptr(0x973F18, 28) = v5 - v13;
						func_type6_3799488();
					}
				}
				v30 = v44;
				pix = &v38[2 * v44];
				nox_video_cur_pixdata_3799444 = pix;
				v21 = v39 + 2 * v30;
				nox_draw_sprite_dstPtr_3799540 = v39 + 2 * v30;
				break;
			default:
				v5 = v45;
				break;
			}
			v13 += v44;
			v42 -= v44;
			if (v42 <= 0) {
				break;
			}
		}
	}
}

//----- (004C79F0) --------------------------------------------------------
void nox_client_drawImg_aaa_4C79F0(nox_video_bag_image_t* img, int x, int y) {
	nox_video_cur_pixdata_3799444 = nox_video_getImagePixdata_func(img);
	if (!nox_video_cur_pixdata_3799444) {
		return;
	}
	int width = *(unsigned int*)nox_video_cur_pixdata_3799444;
	nox_video_cur_pixdata_3799444 += 4;

	int height = *(unsigned int*)nox_video_cur_pixdata_3799444;
	nox_video_cur_pixdata_3799444 += 4;

	int offX = *(int*)nox_video_cur_pixdata_3799444;
	nox_video_cur_pixdata_3799444 += 4;
	nox_draw_sprite_offsX_3799560 = offX;
	x += offX;

	int offY = *(int*)nox_video_cur_pixdata_3799444;
	nox_video_cur_pixdata_3799444 += 4;
	nox_draw_sprite_offsY_3799556 = offY;
	y += offY;

	nox_video_cur_pixdata_3799444++; // unused

	if (dword_5d4594_3799484) {
		height -= dword_5d4594_3799484;
		if (height <= 0) {
			return;
		}
		dword_5d4594_3799476 = height + y;
	}
	*getMemU32Ptr(0x973F18, 92) = x;
	*getMemU32Ptr(0x973F18, 84) = y;
	*getMemU32Ptr(0x973F18, 88) = width;
	*getMemU32Ptr(0x973F18, 76) = height;
	if (ptr_5D4594_3799572->flag_0) {
		RECT rc;
		int4 a1a;
		SetRect(&rc, x, y, x + width, y + height);
		if (!nox_xxx_utilRect_49F930(&a1a, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->clip))) {
			return;
		}
		if (rc.left != a1a.field_0 || rc.right != a1a.field_8 || rc.top != a1a.field_4 || rc.bottom != a1a.field_C) {
			nox_client_drawXxx_4C7C80(x, y, width, &a1a);
			return;
		}
	}
	dword_5d4594_3799508 ^= y & 1;
	for (int i = 0; i < height; i++) {
		unsigned char* row = &nox_pixbuffer_rows_3798784[y + i][2 * x];
		nox_draw_sprite_dstPtr_3799540 = row;
		if (dword_5d4594_3799552 && (dword_5d4594_3799508 ^= 1u) != 0) {
			if (i != 0) {
				memcpy(row, &nox_pixbuffer_rows_3798784[y + i - 1][2 * x], 2 * width);
			}
			nox_client_draw_skip_4C8040(width, 1);
		} else {
			for (int j = width; j > 0; j -= *getMemU32Ptr(0x973F18, 28)) {
				int a = nox_video_cur_pixdata_3799444[0];
				nox_video_cur_pixdata_3799444++;
				*getMemU32Ptr(0x973F18, 0) = a;

				int b = nox_video_cur_pixdata_3799444[0];
				nox_video_cur_pixdata_3799444++;
				*getMemU32Ptr(0x973F18, 28) = b;

				switch (a & 0xF) {
				case 1:
					nox_draw_sprite_dstPtr_3799540 = &row[2 * b];
					break;
				case 2:
				case 7:
					func_type27_3799536();
					break;
				case 4:
					func_type4_3799432();
					break;
				case 5:
					func_type5_3799544();
					break;
				case 6:
					func_type6_3799488();
					break;
				default:
					break;
				}
				row = nox_draw_sprite_dstPtr_3799540;
			}
		}
	}
}

//----- (004C7670) --------------------------------------------------------
void nox_xxx_smthPlayerAnim_4C7670(nox_video_bag_image_t* img, int x, int y) {
	int a1 = img;
	int a2 = x;
	int a3 = y;
	int v3; // esi
	int v4; // ecx
	int v5; // eax
	int v6; // ecx

	v3 = 0;
	if (a1) {
		switch (*(uint8_t*)(a1 + 10) & 0x3F) {
		case 2:
		case 7:
			func_type27_3799536 = sub_4C80E0;
			nox_client_drawImg_bbb_4C7860(a1, a2, a3);
			return;
		case 3:
		case 4:
		case 5:
		case 6:
			func_type5_3799544 = sub_4C96A0;
			func_type6_3799488 = nullsub_7;
			if (!ptr_5D4594_3799572->field_13) {
				if (ptr_5D4594_3799572->field_14) {
					func_type5_3799544 = sub_4C9970;
					func_type27_3799536 = sub_4C8760;
					func_type4_3799432 = sub_4C91C0;
					v3 = 1;
					goto LABEL_23;
				}
				v6 = ptr_5D4594_3799572->field_17;
				func_type27_3799536 = sub_4C8D60;
				if (v6) {
					goto LABEL_22;
				}
				goto LABEL_21;
			}
			func_type5_3799544 = sub_4C97F0;
			if (ptr_5D4594_3799572->field_14) {
				v4 = ptr_5D4594_3799572->field_259;
				if (v4 == 255) {
					if (!ptr_5D4594_3799572->field_16) {
						func_type27_3799536 = sub_4C8760;
						func_type4_3799432 = sub_4C91C0;
						v3 = 1;
						goto LABEL_23;
					}
					goto LABEL_21;
				}
				if (v4 == 128) {
					func_type27_3799536 = sub_4C8C00;
					func_type4_3799432 = sub_4C94D0;
					v3 = 1;
				} else {
					func_type27_3799536 = sub_4C8850;
					func_type4_3799432 = sub_4C92F0;
				}
			} else {
				v5 = ptr_5D4594_3799572->field_259;
				if (v5 == 255) {
				LABEL_21:
					func_type27_3799536 = sub_4C80E0;
				LABEL_22:
					func_type4_3799432 = sub_4C8DF0;
					goto LABEL_23;
				}
				if (v5 == 128) {
					func_type27_3799536 = sub_4C8570;
					func_type4_3799432 = sub_4C9050;
				} else {
					func_type27_3799536 = sub_4C82C0;
					func_type4_3799432 = sub_4C8EC0;
				}
				v3 = 1;
			}
		LABEL_23:
			nox_client_drawImg_aaa_4C79F0(a1, a2, a3);
#if 0
                if (v3)
                _m_femms();
#endif
			break;
		case 8:
			func_type27_3799536 = sub_4C9B20;
			nox_client_drawImg_aaa_4C79F0(a1, a2, a3);
			return;
		default:
			return;
		}
	}
}
#endif // NOX_CGO

//----- (004C8130) --------------------------------------------------------
void sub_4C8130() {
	int result;         // eax
	short v1;           // si
	unsigned short* v2; // edi
	int v3;             // [esp+0h] [ebp-1Ch]
	unsigned char v4;   // [esp+Ch] [ebp-10h]
	unsigned char v5;   // [esp+14h] [ebp-8h]

	result = *getMemU32Ptr(0x973F18, 28) - 1;
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = *(unsigned char*)(&ptr_5D4594_3799572->field_259);
		v2 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
		v3 = *getMemU32Ptr(0x973F18, 28);
		do {
			v5 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 0)) & *v2) >>
				 *((unsigned char*)byte_5D4594_3804364 + 12);
			v4 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 4)) & *v2) >>
				 *((unsigned char*)byte_5D4594_3804364 + 16);
			*v2 =
				*(unsigned short*)(nox_draw_colors_r_3804672 +
								   2 * (unsigned char)(v5 +
													   ((unsigned short)(v1 *
																		 ((unsigned char)((unsigned short)(*((unsigned short*)((unsigned char*)
																																   byte_5D4594_3804364 +
																															   0)) &
																										   *(unsigned short*)(&nox_video_cur_pixdata_3799444
																																  [0])) >>
																						  *((unsigned char*)
																								byte_5D4594_3804364 +
																							12)) -
																		  v5)) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_g_3804656 +
								   2 * (unsigned char)(v4 +
													   ((unsigned short)(v1 *
																		 ((unsigned char)((unsigned short)(*((unsigned short*)((unsigned char*)
																																   byte_5D4594_3804364 +
																															   4)) &
																										   *(unsigned short*)(&nox_video_cur_pixdata_3799444
																																  [0])) >>
																						  *((unsigned char*)
																								byte_5D4594_3804364 +
																							16)) -
																		  v4)) >>
														8))) |
				*(unsigned short*)(nox_draw_colors_b_3804664 +
								   2 * (unsigned char)(((*(unsigned char*)v2 &
														 *((unsigned char*)byte_5D4594_3804364 + 8))
														<< *((unsigned char*)byte_5D4594_3804364 + 20)) +
													   ((unsigned short)(v1 *
																		 ((unsigned char)(((unsigned char)*(
																							   unsigned short*)(&nox_video_cur_pixdata_3799444
																													[0]) &
																						   *((unsigned char*)
																								 byte_5D4594_3804364 +
																							 8))
																						  << *((unsigned char*)
																								   byte_5D4594_3804364 +
																							   20)) -
																		  (unsigned char)((*(unsigned char*)v2 &
																						   *((unsigned char*)
																								 byte_5D4594_3804364 +
																							 8))
																						  << *((unsigned char*)
																								   byte_5D4594_3804364 +
																							   20)))) >>
														8)));
			v2 = (unsigned short*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 2);
			result = v3 - 1;
			nox_video_cur_pixdata_3799444 += 2;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			v3 = result;
		} while (result);
	}
}

//----- (004C8410) --------------------------------------------------------
void sub_4C8410() {
	int result;         // eax
	unsigned short* v1; // esi
	int v2;             // [esp+0h] [ebp-1Ch]
	unsigned char v3;   // [esp+Ch] [ebp-10h]
	unsigned char v4;   // [esp+14h] [ebp-8h]

	result = *getMemU32Ptr(0x973F18, 28) - 1;
	if (*getMemU32Ptr(0x973F18, 28)) {
		v1 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
		v2 = *getMemU32Ptr(0x973F18, 28);
		do {
			v3 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 4)) & *v1) >>
				 *((unsigned char*)byte_5D4594_3804364 + 16);
			v4 = (unsigned short)(*((unsigned short*)((unsigned char*)byte_5D4594_3804364 + 0)) & *v1) >>
				 *((unsigned char*)byte_5D4594_3804364 + 12);
			*v1 =
				*(unsigned short*)(nox_draw_colors_r_3804672 +
								   2 * (unsigned char)(v4 +
													   (((unsigned char)((unsigned short)(*((unsigned short*)((unsigned char*)
																												  byte_5D4594_3804364 +
																											  0)) &
																						  *(unsigned short*)(&nox_video_cur_pixdata_3799444
																												 [0])) >>
																		 *((unsigned char*)byte_5D4594_3804364 + 12)) -
														 v4) >>
														1))) |
				*(unsigned short*)(nox_draw_colors_g_3804656 +
								   2 * (unsigned char)(v3 +
													   (((unsigned char)((unsigned short)(*((unsigned short*)((unsigned char*)
																												  byte_5D4594_3804364 +
																											  4)) &
																						  *(unsigned short*)(&nox_video_cur_pixdata_3799444
																												 [0])) >>
																		 *((unsigned char*)byte_5D4594_3804364 + 16)) -
														 v3) >>
														1))) |
				*(unsigned short*)(nox_draw_colors_b_3804664 +
								   2 * (unsigned char)(((*(unsigned char*)v1 &
														 *((unsigned char*)byte_5D4594_3804364 + 8))
														<< *((unsigned char*)byte_5D4594_3804364 + 20)) +
													   (((unsigned char)(((unsigned char)*(
																			  unsigned short*)(&nox_video_cur_pixdata_3799444
																								   [0]) &
																		  *((unsigned char*)byte_5D4594_3804364 + 8))
																		 << *((unsigned char*)byte_5D4594_3804364 +
																			  20)) -
														 (unsigned char)((*(unsigned char*)v1 &
																		  *((unsigned char*)byte_5D4594_3804364 + 8))
																		 << *((unsigned char*)byte_5D4594_3804364 +
																			  20))) >>
														1)));
			v1 = (unsigned short*)((unsigned int)nox_draw_sprite_dstPtr_3799540 + 2);
			result = v2 - 1;
			nox_video_cur_pixdata_3799444 += 2;
			nox_draw_sprite_dstPtr_3799540 = (unsigned int)nox_draw_sprite_dstPtr_3799540 + 2;
			v2 = result;
		} while (result);
	}
}

#ifndef NOX_CGO
//----- (004C8A30) --------------------------------------------------------
void sub_4C8A30() {
	unsigned short* v1; // esi
	int v5;             // [esp+0h] [ebp-28h]
	unsigned char v6;   // [esp+4h] [ebp-24h]
	unsigned char v7;   // [esp+8h] [ebp-20h]
	short v8;           // [esp+Ch] [ebp-1Ch]

	unsigned int rshift = *(unsigned int*)((unsigned char*)byte_5D4594_3804364 + 20);
	unsigned int gshift = *(unsigned int*)((unsigned char*)byte_5D4594_3804364 + 16);
	unsigned int bshift = *(unsigned int*)((unsigned char*)byte_5D4594_3804364 + 12);

	unsigned int rmask = *(unsigned int*)((unsigned char*)byte_5D4594_3804364 + 8);
	unsigned int gmask = *(unsigned int*)((unsigned char*)byte_5D4594_3804364 + 4);
	unsigned int bmask = *(unsigned int*)((unsigned char*)byte_5D4594_3804364 + 0);

	unsigned short* add1 = nox_draw_colors_r_3804672;
	unsigned short* add2 = nox_draw_colors_b_3804664;
	unsigned short* add3 = nox_draw_colors_g_3804656;

	unsigned short* px = nox_video_cur_pixdata_3799444;

	v7 = *(unsigned char*)(&ptr_5D4594_3799572->field_26);
	v6 = *(unsigned char*)(&ptr_5D4594_3799572->field_25);
	v8 = *(unsigned char*)(&ptr_5D4594_3799572->field_24);
	v1 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
	for (v5 = *getMemU32Ptr(0x973F18, 28); v5 > 0; --v5) {
		unsigned char v3;        // eax
		unsigned char v9;        // [esp+18h] [ebp-10h]
		unsigned char v10;       // [esp+20h] [ebp-8h]
		unsigned short v2 = *v1; // old color
		unsigned short x = *px;  // color to draw

		// XXX This code is incorrect in the original Nox binary, but is correct
		//     in the MMX version of this function. The color multiply (v8,v6,v7)
		//     is supposed to be applied to the new color, not to the old color.
		//     The old color already had it applied earlier.
		v3 = (v7 * ((rmask & x) << rshift)) >> 8;
		v9 = (v6 * ((gmask & x) >> gshift)) >> 8;
		v10 = (v8 * ((bmask & x) >> bshift)) >> 8;
		*v1 = add1[v10 + (((bmask & v2) >> bshift) - v10) / 2] | add3[v9 + (((gmask & v2) >> gshift) - v9) / 2] |
			  add2[v3 + (((rmask & v2) << rshift) - v3) / 2];
		v1++;
		px++;
	}
	nox_video_cur_pixdata_3799444 = px;
	*(unsigned short**)&nox_draw_sprite_dstPtr_3799540 = v1;
}

//----- (004C86B0) --------------------------------------------------------
void sub_4C86B0() {
	short* v0;          // esi
	unsigned short* v1; // edi
	short v2;           // ax
	int result;         // eax
	int v5;             // [esp-4h] [ebp-10h]

	v0 = (unsigned short*)nox_video_cur_pixdata_3799444;
	v1 = *(unsigned short**)&nox_draw_sprite_dstPtr_3799540;
	v5 = *getMemU32Ptr(0x973F18, 28);
	do {
		v2 = *v0;
		++v0;
		result = *(unsigned int*)(nox_draw_colors_r_3804672 +
								  2 * ((unsigned int)(*(unsigned int*)(&obj_5D4594_3800716.field_24) *
													  ((unsigned short)(*((unsigned short*)((unsigned char*)
																								byte_5D4594_3804364 +
																							0)) &
																		v2) >>
													   *((unsigned char*)byte_5D4594_3804364 + 12))) >>
									   8)) |
				 *(unsigned int*)(nox_draw_colors_g_3804656 +
								  2 * ((unsigned int)(*(unsigned int*)(&obj_5D4594_3800716.field_25) *
													  ((unsigned short)(*((unsigned short*)((unsigned char*)
																								byte_5D4594_3804364 +
																							4)) &
																		v2) >>
													   *((unsigned char*)byte_5D4594_3804364 + 16))) >>
									   8)) |
				 *(unsigned int*)(nox_draw_colors_b_3804664 +
								  2 * ((unsigned int)(*(unsigned int*)(&obj_5D4594_3800716.field_26) *
													  ((unsigned short)(*((unsigned short*)((unsigned char*)
																								byte_5D4594_3804364 +
																							8)) &
																		v2)
													   << *((unsigned char*)byte_5D4594_3804364 + 20))) >>
									   8));
		*v1 = result;
		++v1;
	} while ((*getMemU32Ptr(0x973F18, 28))-- > 1);
	*getMemU32Ptr(0x973F18, 28) = v5;
	nox_video_cur_pixdata_3799444 = v0;
	nox_draw_sprite_dstPtr_3799540 = v1;
}

//----- (004C7440) --------------------------------------------------------
void nox_client_xxxDraw16_4C7440(nox_video_bag_image_t* img, int x, int y) {
	int v3; // ecx
	int v4; // eax
	int v5; // ecx
#if 0
    if ((img->typ & 0xff) != 8)
    {
        _dprintf("%x %x %x", img, x, y);
        _dprintf("\t%d", img->typ & 0xff);
    }
#endif
	if (!img) {
		return;
	}
	switch (img->typ & 0x3F) {
	case 2:
	case 7:
		func_type27_3799536 = sub_4C80E0;
		nox_client_drawImg_bbb_4C7860(img, x, y);
		return;
	case 3:
	case 4:
	case 5:
	case 6:
		func_type5_3799544 = sub_4C96A0;
		func_type6_3799488 = nullsub_7;
		if (!ptr_5D4594_3799572->field_13) {
			if (ptr_5D4594_3799572->field_14) {
				func_type5_3799544 = sub_4C9970;
				func_type27_3799536 = sub_4C86B0;
				func_type4_3799432 = sub_4C91C0;
				nox_client_drawImg_aaa_4C79F0(img, x, y);
				return;
			}
			v5 = ptr_5D4594_3799572->field_17;
			func_type27_3799536 = sub_4C8D60;
			if (!v5) {
				func_type27_3799536 = sub_4C80E0;
			}
			func_type4_3799432 = sub_4C8DF0;
			nox_client_drawImg_aaa_4C79F0(img, x, y);
			return;
		}
		func_type5_3799544 = sub_4C97F0;
		if (ptr_5D4594_3799572->field_14) {
			v3 = ptr_5D4594_3799572->field_259;
			if (v3 == 255) {
				if (!ptr_5D4594_3799572->field_16) {
					func_type27_3799536 = sub_4C86B0;
					func_type4_3799432 = sub_4C91C0;
				} else {
					func_type27_3799536 = sub_4C80E0;
					func_type4_3799432 = sub_4C8DF0;
				}
				nox_client_drawImg_aaa_4C79F0(img, x, y);
				return;
			}
			if (v3 == 128) {
				func_type27_3799536 = sub_4C8A30;
				func_type4_3799432 = sub_4C94D0;
			} else {
				func_type27_3799536 = sub_4C8850;
				func_type4_3799432 = sub_4C92F0;
			}
			nox_client_drawImg_aaa_4C79F0(img, x, y);
		} else {
			v4 = ptr_5D4594_3799572->field_259;
			if (v4 == 255) {
				func_type27_3799536 = sub_4C80E0;
				func_type4_3799432 = sub_4C8DF0;
				nox_client_drawImg_aaa_4C79F0(img, x, y);
				return;
			}
			if (v4 == 128) {
				func_type27_3799536 = sub_4C8410;
				func_type4_3799432 = sub_4C9050;
			} else {
				func_type27_3799536 = sub_4C8130;
				func_type4_3799432 = sub_4C8EC0;
			}
			nox_client_drawImg_aaa_4C79F0(img, x, y);
		}
		break;
	case 8:
		func_type27_3799536 = sub_4C9B20;
		nox_client_drawImg_aaa_4C79F0(img, x, y);
		return;
	default:
		return;
	}
}
#endif // NOX_CGO
