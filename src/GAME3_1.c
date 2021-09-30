#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "client__draw__animdraw.h"
#include "client__draw__vectdraw.h"
#include "client__drawable__drawable.h"
#include "client__gui__servopts__advserv.h"
#include "client__gui__guisumn.h"
#include "common__system__team.h"
#include "common__net_list.h"

#include "client__gui__guiinput.h"
#include "client__gui__servopts__objlst.h"
#include "client__gui__servopts__spelllst.h"
#include "client__gui__tooltip.h"
#include "client__gui__window.h"
#include "client__shell__inputcfg__inputcfg.h"
#include "client__shell__mainmenu.h"

#include "client__draw__mondraw.h"
#include "client__draw__plasma.h"
#include "client__drawable__update__charmup.h"
#include "client__drawable__update__fireball.h"
#include "client__system__npcinfo.h"
#include "client__system__ctrlevnt.h"

#include "common/fs/nox_fs.h"
#include "client__shell__optsback.h"
#include "client__video__draw_common.h"
#include "common__config.h"
#include "input_common.h"

extern _DWORD dword_587000_180476;
extern _DWORD dword_5d4594_1319260;
extern _DWORD dword_5d4594_1321196;
extern _DWORD dword_587000_185504;
extern _DWORD dword_5d4594_1313880;
extern _DWORD dword_5d4594_1320944;
extern _DWORD dword_5d4594_1313816;
extern _DWORD dword_5d4594_1320948;
extern _DWORD dword_587000_183460;
extern _DWORD dword_5d4594_1316412;
extern _DWORD dword_5d4594_1522968;
extern _DWORD dword_5d4594_3679312;
extern _DWORD dword_5d4594_1321520;
extern _DWORD dword_5d4594_1319268;
extern _DWORD dword_5d4594_1321024;
extern _DWORD dword_5d4594_1320936;
extern _DWORD nox_client_showTooltips_80840;
extern _DWORD dword_587000_183456;
extern _DWORD dword_5d4594_1320988;
extern _DWORD dword_5d4594_1522596;
extern _DWORD dword_5d4594_1319248;
extern _DWORD dword_5d4594_1193156;
extern _DWORD dword_587000_180480;
extern _DWORD dword_5d4594_3798728;
extern _DWORD dword_5d4594_1319236;
extern _DWORD dword_5d4594_1320972;
extern _DWORD dword_5d4594_1316704;
extern _DWORD dword_5d4594_1321208;
extern _DWORD nox_xxx_xxxRenderGUI_587000_80832;
extern _DWORD dword_5d4594_1321800;
extern unsigned int nox_client_texturedFloors2_154960;
extern _DWORD dword_5d4594_3799476;
extern _DWORD dword_5d4594_1321224;
extern _DWORD dword_5d4594_1319056;
extern _DWORD dword_5d4594_1320932;
extern _DWORD dword_5d4594_1321032;
extern _DWORD nox_client_renderBubbles_80844;
extern _DWORD dword_5d4594_1522932;
extern _DWORD dword_5d4594_1319264;
extern _DWORD dword_5d4594_1321044;
extern _DWORD nox_client_renderGlow_805852;
extern _DWORD dword_5d4594_1319232;
extern _DWORD dword_5d4594_1321216;
extern unsigned int nox_gui_console_translucent;
extern _DWORD nox_client_fadeObjects_80836;
extern nox_window* dword_5d4594_1321236;
extern nox_window* dword_5d4594_1321240;
extern nox_window* dword_5d4594_1321248;
extern nox_window* dword_5d4594_1321244;
nox_window* dword_5d4594_1522616 = 0;
nox_window* dword_5d4594_1522620 = 0;
nox_window* dword_5d4594_1522624 = 0;
nox_window* dword_5d4594_1522628 = 0;
extern _DWORD nox_client_lockHighResFloors_1193152;
extern _DWORD nox_win_legalBg_1522892;
extern _DWORD nox_client_drawFrontWalls_80812;
extern _DWORD dword_5d4594_1320992;
extern _DWORD dword_5d4594_1321204;
extern _DWORD nox_client_translucentFrontWalls_805844;
extern _DWORD dword_5d4594_1316408;
extern _QWORD qword_581450_9512;
extern _QWORD qword_581450_9544;
extern _DWORD dword_5d4594_1320968;
extern _DWORD dword_5d4594_1319060;
extern _DWORD dword_5d4594_3798720;
extern _DWORD dword_5d4594_1522632;
extern _DWORD dword_5d4594_1321252;
extern _DWORD dword_5d4594_3798156;
extern _DWORD dword_5d4594_1522612;
extern _DWORD dword_5d4594_1522604;
extern _DWORD nox_client_highResFloors_154952;
#ifndef NOX_CGO
extern void* (*nox_video_getImagePixdata_func)(nox_video_bag_image_t*);
#else // NOX_CGO
void* nox_video_getImagePixdata_func(nox_video_bag_image_t*);
#endif // NOX_CGO
extern _DWORD dword_5d4594_3807156;
extern int dword_5d4594_3799524;
extern _DWORD dword_5d4594_3679320;
extern _DWORD dword_5d4594_1313796;
extern _DWORD nox_client_texturedFloors_154956;
extern _DWORD nox_client_highResFrontWalls_80820;
extern _DWORD dword_5d4594_1321232;
extern _DWORD dword_5d4594_1313800;
extern _DWORD dword_5d4594_1316712;
extern _DWORD dword_5d4594_1320964;
extern _DWORD dword_5d4594_1316708;
extern _DWORD dword_5d4594_1321228;
extern _DWORD dword_5d4594_1321040;
extern _DWORD dword_5d4594_1316972;
extern _DWORD nox_client_renderGUI_80828;
extern _DWORD dword_5d4594_1320940;
extern int nox_win_width;
extern int nox_win_height;
extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;

extern int nox_backbuffer_depth;
extern unsigned int nox_video_dxUnlockSurface;

extern nox_render_data_t* ptr_5D4594_3799572;
extern nox_render_data_t obj_5D4594_3800716;

nox_gui_animation* nox_wnd_xxx_1522608 = 0;

void* nox_gui_itemAmount_item_1319256 = 0;
void* nox_gui_itemAmount_dialog_1319228 = 0;

_DWORD nox_arr_956A00[NOX_MAX_HEIGHT+150] = {0};
unsigned char nox_arr_957820[128*(NOX_MAX_HEIGHT+150)] = {0};

#ifndef NOX_CGO
void* nox_win_advVideoOpts_1522600 = 0;
extern nox_bindevent_t nox_bindevent_arr[NOX_BINDEVENT_MAX];
#endif // NOX_CGO

//----- (004B9470) --------------------------------------------------------
int  sub_4B9470(const char** a1) {
	const char* v1;      // esi
	int v2;              // edx
	unsigned __int8* v3; // edi

	if (!a1)
		return 0;
	v1 = *(const char**)getMemAt(0x587000, 177488);
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 177488))
		return 0;
	v3 = getMemAt(0x587000, 177488);
	while (strcmp(*a1, v1)) {
		v1 = (const char*)*((_DWORD*)v3 + 2);
		v3 += 8;
		++v2;
		if (!v1)
			return 0;
	}
	return *getMemU32Ptr(0x587000, 177492 + 8 * v2);
}

//----- (004B94E0) --------------------------------------------------------
int  sub_4B94E0(nox_drawable* dr) {
	int a1 = dr;
	int result; // eax

	if (*(_DWORD*)(a1 + 112) & 0x10000000)
		result = sub_4B9470(*(const char***)(a1 + 436));
	else
		result = 0;
	return result;
}

//----- (004B95D0) --------------------------------------------------------
_DWORD*  sub_4B95D0(nox_drawable* dr) {
	_DWORD* result; // eax
	int v2;         // edx
	int v3;         // ecx
	_DWORD* v4;     // ebx
	int v5;         // edi
	_BYTE* v6;      // esi
	int* v7;        // edi
	_DWORD** v8;    // esi
	int v9;         // ebx

	int a1 = dr;

	result = nox_xxx_getProjectileClassById_413250(*(_DWORD*)(a1 + 108));
	v4 = result;
	if (result) {
		v5 = 1;
		v6 = result + 4;
		do {
			LOBYTE(v3) = v6[1];
			LOBYTE(v2) = *v6;
			LOBYTE(result) = *(v6 - 1);
			sub_4340A0(v5++, (int)result, v2, v3);
			v6 += 3;
		} while (v5 < 7);
		v7 = v4 + 9;
		v8 = (_DWORD**)(a1 + 432);
		v9 = 4;
		do {
			result = *v8;
			if (*v8) {
				LOBYTE(v3) = *((_BYTE*)result + 26);
				LOBYTE(v2) = *((_BYTE*)result + 25);
				LOBYTE(result) = *((_BYTE*)result + 24);
				sub_4340A0(*v7, (int)result, v2, v3);
			}
			++v8;
			++v7;
			--v9;
		} while (v9);
	}
	return result;
}
// 4B9604: variable 'v2' is possibly undefined
// 4B9604: variable 'v3' is possibly undefined

//----- (004B9650) --------------------------------------------------------
_DWORD*  sub_4B9650(int a1) {
	_DWORD* result; // eax
	int v2;         // edx
	int v3;         // ecx
	int v4;         // edi
	_BYTE* v5;      // esi

	result = nox_xxx_getProjectileClassById_413250(a1);
	if (result) {
		v4 = 1;
		v5 = result + 4;
		do {
			LOBYTE(v3) = v5[1];
			LOBYTE(v2) = *v5;
			LOBYTE(result) = *(v5 - 1);
			sub_4340A0(v4++, (int)result, v2, v3);
			v5 += 3;
		} while (v4 < 7);
	}
	return result;
}
// 4B9677: variable 'v2' is possibly undefined
// 4B9677: variable 'v3' is possibly undefined

//----- (004B96F0) --------------------------------------------------------
_DWORD*  sub_4B96F0(nox_drawable* dr) {
	_DWORD* result; // eax
	int v2;         // edx
	int v3;         // ecx
	_DWORD* v4;     // ebx
	int v5;         // edi
	_BYTE* v6;      // esi
	int* v7;        // edi
	_DWORD** v8;    // esi
	int v9;         // ebx

	int a1 = dr;

	result = nox_xxx_equipClothFindDefByTT_413270(*(_DWORD*)(a1 + 108));
	v4 = result;
	if (result) {
		v5 = 1;
		v6 = result + 4;
		do {
			LOBYTE(v3) = v6[1];
			LOBYTE(v2) = *v6;
			LOBYTE(result) = *(v6 - 1);
			sub_4340A0(v5++, (int)result, v2, v3);
			v6 += 3;
		} while (v5 < 7);
		v7 = v4 + 9;
		v8 = (_DWORD**)(a1 + 432);
		v9 = 4;
		do {
			result = *v8;
			if (*v8) {
				LOBYTE(v3) = *((_BYTE*)result + 26);
				LOBYTE(v2) = *((_BYTE*)result + 25);
				LOBYTE(result) = *((_BYTE*)result + 24);
				sub_4340A0(*v7, (int)result, v2, v3);
			}
			++v8;
			++v7;
			--v9;
		} while (v9);
	}
	return result;
}
// 4B9724: variable 'v2' is possibly undefined
// 4B9724: variable 'v3' is possibly undefined

//----- (004BA670) --------------------------------------------------------
void  sub_4BA670(int a1, int a2, int a3, int a4, int a5) {
	int v5;               // ebx
	int v6;               // edi
	int v7;               // esi
	int v8;               // eax
	double v9;            // st7
	double v10;           // st6
	double v11;           // st5
	double v12;           // st4
	double v13;           // st5
	double v14;           // st5
	double v15;           // rt0
	int v16;              // eax
	int v17;              // ecx
	int v18;              // esi
	int v19;              // edx
	unsigned __int8* v20; // eax
	float v21;            // [esp-Ch] [ebp-44h]
	int2 a4a;             // [esp+18h] [ebp-20h]
	int2 a3a;             // [esp+20h] [ebp-18h]
	int2 a2a;             // [esp+28h] [ebp-10h]
	int2 a1a;             // [esp+30h] [ebp-8h]
	float v26;            // [esp+40h] [ebp+8h]

	v5 = a5;
	v6 = a4 - a2;
	v7 = a5 - a3;
	v8 = sub_48C6B0(a4 - a2, a5 - a3);
	dword_5d4594_1316408 = v8 / 40 + 1;
	if (v8 / 40 + 2 >= 30)
		dword_5d4594_1316408 = 28;
	a1a.field_0 = a2;
	v9 = *getMemFloatPtr(0x587000, 194136 + 8 * a1);
	v10 = *getMemFloatPtr(0x587000, 194140 + 8 * a1);
	v11 = (double)(a4 - a2);
	v12 = (double)v7;
	a1a.field_4 = a3;
	a2a.field_0 = a4;
	a2a.field_4 = v5;
	*(float*)&dword_5d4594_1313880 = v12;
	v26 = sqrt(v12 * *(float*)&dword_5d4594_1313880 + v11 * v11) + 0.0099999998;
	*getMemFloatPtr(0x5D4594, 1313876) = v11 / v26;
	v13 = *(float*)&dword_5d4594_1313880 / v26;
	*(float*)&dword_5d4594_1313880 = v13;
	v14 = v13 * v10 + *getMemFloatPtr(0x5D4594, 1313876) * v9;
	if (v14 < 0.0)
		v14 = v14 * 0.2;
	v15 = (1.0 - v14) * (double)v8 * 2.3;
	*getMemFloatPtr(0x5D4594, 1313868) = v9 * v15;
	*getMemFloatPtr(0x5D4594, 1313872) = v10 * v15;
	a3a.field_0 = nox_float2int(*getMemFloatPtr(0x5D4594, 1313868));
	v16 = nox_float2int(*getMemFloatPtr(0x5D4594, 1313872));
	a4a.field_0 = v6;
	v17 = 0;
	a3a.field_4 = v16;
	a4a.field_4 = v7;
	a5 = 0;
	do {
		if (v17)
			*getMemFloatPtr(0x5D4594, 1313856 + 4 * v17) = *getMemFloatPtr(0x5D4594, 1313856 + 4 * v17) + 0.25;
		else
			*getMemFloatPtr(0x5D4594, 1313856) = *getMemFloatPtr(0x5D4594, 1313856) + 0.2;
		v18 = dword_5d4594_1316408;
		if (*getMemFloatPtr(0x5D4594, 1313856 + 4 * v17) >= 1.0) {
			v19 = dword_5d4594_1316408 + 1;
			if (dword_5d4594_1316408 + 1 > 0) {
				v20 = getMemAt(0x5D4594, 1313872 + 28 * (v19 + 30 * v17));
				do {
					*((_DWORD*)v20 + 6) = *((_DWORD*)v20 - 1);
					*((_DWORD*)v20 + 7) = *(_DWORD*)v20;
					*((_DWORD*)v20 + 8) = *((_DWORD*)v20 + 1);
					*((_DWORD*)v20 + 9) = *((_DWORD*)v20 + 2);
					*((_DWORD*)v20 + 5) = *((_DWORD*)v20 - 2);
					v20 -= 28;
					--v19;
				} while (v19);
			}
			*getMemU32Ptr(0x5D4594, 1313856 + 4 * v17) = 0;
			*getMemU32Ptr(0x5D4594, 1313908 + 840 * v17) = 0;
		}
		v21 = *getMemFloatPtr(0x5D4594, 1313856 + 4 * v17);
		dword_5d4594_1316412 = 0;
		sub_4BEDE0(&a1a, &a2a, &a3a, &a4a, v18, v21, sub_4BA8B0, (int)&a5);
		v17 = ++a5;
	} while (a5 < 3);
}
// 4BA6B4: variable 'v8' is possibly undefined
// 4BAA32: variable 'v12' is possibly undefined
// 4BAA46: variable 'v14' is possibly undefined
// 4BAA70: variable 'v16' is possibly undefined
// 4BAA84: variable 'v18' is possibly undefined

//----- (004BAB30) --------------------------------------------------------
int nox_xxx_prepareLightningEffects_4BAB30() {
	int result; // eax

	*getMemU32Ptr(0x5D4594, 1316464) = nox_color_rgb_4344A0(255, 255, 255);
	*getMemU32Ptr(0x5D4594, 1316488) = nox_color_rgb_4344A0(128, 128, 255);
	*getMemU32Ptr(0x5D4594, 1316424) = nox_color_rgb_4344A0(128, 128, 255);
	*getMemU32Ptr(0x5D4594, 1316428) = nox_color_rgb_4344A0(64, 64, 255);
	*getMemU32Ptr(0x5D4594, 1316516) = nox_color_rgb_4344A0(200, 200, 255);
	*getMemU32Ptr(0x5D4594, 1316512) = nox_color_rgb_4344A0(128, 128, 255);
	*getMemU32Ptr(0x5D4594, 1316496) = nox_color_rgb_4344A0(255, 255, 255);
	*getMemU32Ptr(0x5D4594, 1316468) = nox_color_rgb_4344A0(255, 255, 0);
	*getMemU32Ptr(0x5D4594, 1316460) = nox_color_rgb_4344A0(30, 160, 30);
	*getMemU32Ptr(0x5D4594, 1316444) = nox_color_rgb_4344A0(60, 140, 60);
	*getMemU32Ptr(0x5D4594, 1316504) = nox_color_rgb_4344A0(40, 225, 40);
	*getMemU32Ptr(0x5D4594, 1316480) = nox_color_rgb_4344A0(150, 220, 150);
	*getMemU32Ptr(0x5D4594, 1316520) = nox_xxx_getTTByNameSpriteMB_44CFC0("BlueSpark");
	*getMemU32Ptr(0x5D4594, 1316524) = nox_xxx_getTTByNameSpriteMB_44CFC0("YellowSpark");
	result = nox_xxx_getTTByNameSpriteMB_44CFC0("GreenSpark");
	*getMemU32Ptr(0x5D4594, 1316528) = result;
	return result;
}
// 4BBC74: variable 'v10' is possibly undefined
// 4BBC74: variable 'v9' is possibly undefined
// 4BC002: variable 'v5' is possibly undefined
// 4BC002: variable 'v3' is possibly undefined

//----- (004BC080) --------------------------------------------------------
void  nox_xxx_spriteDrawMonsterHP_4BC080(_DWORD* a1, int a2, unsigned __int16 a3, unsigned __int16 a4, char a5) {
	int v5;    // edi
	int v6;    // edi
	int v7;    // ebp
	int v8;    // ebx
	int v9;    // esi
	float v10; // [esp+0h] [ebp-14h]
	float v11; // [esp+0h] [ebp-14h]
	float v12; // [esp+0h] [ebp-14h]

	if (a2) {
		v5 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
		v10 = *(float*)(a2 + 48) + *(float*)(a2 + 48);
		v6 = nox_float2int(v10) + v5;
		v7 = *(_DWORD*)(a2 + 16) + a1[1] - *(__int16*)(a2 + 104) - a1[5];
		v11 = *(float*)(a2 + 100) - *(float*)(a2 + 96);
		v8 = nox_float2int(v11);
		if (v8 < 30)
			v8 = 30;
		v12 = *(float*)(a2 + 96) + *(float*)(a2 + 100);
		v9 = v7 + nox_float2int(v12) / -2 - v8 / 2;
		if (a4) {
			nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 952));
			nox_client_drawRectFilledOpaque_49CE30(v6, v9, 2, v8);
			if (a5)
				nox_client_drawSetColor_434460(*getMemIntPtr(0x8531A0, 2572));
			else
				nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 940));
			nox_client_drawRectFilledOpaque_49CE30(v6, v8 + v9 - v8 * a3 / a4, 2, v8 * a3 / a4);
		}
	}
}

//----- (004BC6B0) --------------------------------------------------------
int  sub_4BC6B0(int* a1, nox_drawable* dr, int a3) {
	int a2 = dr;
	int v3; // eax

	v3 = sub_4BC5D0(dr, a3);
	if (v3 < 0)
		return 0;
	nox_xxx_drawObject_4C4770_draw(a1, dr, *(_DWORD*)(*(_DWORD*)(a3 + 4 * *(unsigned __int8*)(a2 + 297) + 4) + 4 * v3));
	return 1;
}

//----- (004BC720) --------------------------------------------------------
int  sub_4BC720(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 304);
	*(_DWORD*)(a1 + 432) = *(unsigned __int8*)(result + 27) * (*(unsigned __int8*)(result + 32) + 1);
	return result;
}

//----- (004BC920) --------------------------------------------------------
int nox_xxx_updDrawMonsterGen_4BC920() { return 1; }
// 4BCABD: variable 'v5' is possibly undefined
// 4BCABD: variable 'v4' is possibly undefined

//----- (004BD010) --------------------------------------------------------
int  sub_4BD010(nox_drawable* dr, int2* a2, int a3) {
	int v3;     // esi
	int result; // eax
	int2* v5;   // edi
	int v6;     // eax
	int v7;     // edx
	int v8;     // eax
	int v9;     // ebx
	int v10;    // ebp
	int v11;    // esi
	float v12;  // [esp+0h] [ebp-24h]
	float v13;  // [esp+0h] [ebp-24h]
	int v14;    // [esp+4h] [ebp-20h]
	float v15;  // [esp+4h] [ebp-20h]
	float v16;  // [esp+4h] [ebp-20h]
	int2 v17;   // [esp+14h] [ebp-10h]
	int2 v18;   // [esp+1Ch] [ebp-8h]
	int v19;    // [esp+28h] [ebp+4h]
	int2* a2a;  // [esp+2Ch] [ebp+8h]

	int a1 = dr;

	v3 = a1;
	if (*(_DWORD*)(a1 + 44) == 2) {
		v9 = (__int64)*(float*)(a1 + 48);
		v12 = *(float*)(a1 + 100) - (double)*(__int16*)(a1 + 104);
		v10 = a2->field_4 - nox_float2int(v12);
		v19 = a2->field_4;
		v13 = *(float*)(v3 + 96) - (double)*(__int16*)(v3 + 104);
		v11 = v19 - nox_float2int(v13);
		if (v11 > 0)
			nox_video_drawCircleColored_4C3270(a2->field_0, v19, v9, *getMemIntPtr(0x85B3FC, 940));
		nox_video_drawCircleColored_4C3270(a2->field_0, v11, v9, a3);
		nox_video_drawCircleColored_4C3270(a2->field_0, v10, v9, a3);
		nox_client_drawSetColor_434460(a3);
		nox_client_drawAddPoint_49F500(a2->field_0 - v9, v11);
		nox_client_drawAddPoint_49F500(a2->field_0 - v9, v10);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(v9 + a2->field_0, v11);
		nox_client_drawAddPoint_49F500(v9 + a2->field_0, v10);
		result = nox_client_drawLineFromPoints_49E4B0();
	} else {
		result = *(_DWORD*)(a1 + 44) - 3;
		if (*(_DWORD*)(a1 + 44) == 3) {
			v5 = a2;
			v14 = *(__int16*)(a1 + 104);
			v18.field_0 = a2->field_0;
			v15 = *(float*)(a1 + 100) - (double)v14;
			v6 = nox_float2int(v15);
			a2a = (int2*)*(__int16*)(a1 + 104);
			v7 = v5->field_4 - v6;
			v8 = v5->field_0;
			v18.field_4 = v7;
			v17.field_0 = v8;
			v16 = *(float*)(a1 + 96) - (double)(int)a2a;
			v17.field_4 = v5->field_4 - nox_float2int(v16);
			if (v17.field_4 > 0)
				sub_4CEA90((float*)(a1 + 64), v5, *getMemIntPtr(0x85B3FC, 940));
			sub_4CEA90((float*)(a1 + 64), &v17, a3);
			sub_4CEA90((float*)(a1 + 64), &v18, a3);
			nox_client_drawSetColor_434460(a3);
			nox_client_drawAddPoint_49F500(v17.field_0 + (unsigned __int64)(__int64)*(float*)(a1 + 72),
										   v17.field_4 + (unsigned __int64)(__int64)*(float*)(a1 + 76));
			nox_client_drawAddPoint_49F500(v18.field_0 + (unsigned __int64)(__int64)*(float*)(a1 + 72),
										   v18.field_4 + (unsigned __int64)(__int64)*(float*)(a1 + 76));
			nox_client_drawLineFromPoints_49E4B0();
			nox_client_drawAddPoint_49F500(v17.field_0 + (unsigned __int64)(__int64)*(float*)(a1 + 80),
										   v17.field_4 + (unsigned __int64)(__int64)*(float*)(a1 + 84));
			nox_client_drawAddPoint_49F500(v18.field_0 + (unsigned __int64)(__int64)*(float*)(a1 + 80),
										   v18.field_4 + (unsigned __int64)(__int64)*(float*)(a1 + 84));
			nox_client_drawLineFromPoints_49E4B0();
			nox_client_drawAddPoint_49F500(v17.field_0 + (unsigned __int64)(__int64)*(float*)(a1 + 88),
										   v17.field_4 + (unsigned __int64)(__int64)*(float*)(a1 + 92));
			nox_client_drawAddPoint_49F500(v18.field_0 + (unsigned __int64)(__int64)*(float*)(a1 + 88),
										   v18.field_4 + (unsigned __int64)(__int64)*(float*)(a1 + 92));
			result = nox_client_drawLineFromPoints_49E4B0();
		}
	}
	return result;
}

//----- (004BD280) --------------------------------------------------------
_DWORD*  sub_4BD280(int a1, int a2) {
	int v2;         // esi
	_DWORD* result; // eax
	_DWORD* v4;     // ecx
	int v5;         // edi

	v2 = a2 + 4;
	result = malloc(a1 * (a2 + 4) + 4);
	if (result) {
		v4 = result + 1;
		*result = result + 1;
		if (a1 != 1) {
			v5 = a1 - 1;
			do {
				--v5;
				*v4 = (char*)v4 + v2;
				v4 = (_DWORD*)((char*)v4 + v2);
			} while (v5);
		}
		*v4 = 0;
	}
	return result;
}

//----- (004BD2D0) --------------------------------------------------------
void  sub_4BD2D0(LPVOID lpMem) { free(lpMem); }

//----- (004BD2E0) --------------------------------------------------------
_DWORD*  sub_4BD2E0(_DWORD** a1) {
	_DWORD* result; // eax
	_DWORD* v2;     // edx

	result = *a1;
	if (*a1) {
		v2 = (_DWORD*)*result;
		++result;
		*a1 = v2;
	}
	return result;
}

//----- (004BD300) --------------------------------------------------------
int  sub_4BD300(_DWORD* a1, int a2) {
	int result; // eax

	result = a2 - 4;
	*(_DWORD*)(a2 - 4) = *a1;
	*a1 = a2 - 4;
	return result;
}

//----- (004BD320) --------------------------------------------------------
int  sub_4BD320(_DWORD** a1) {
	int result; // eax
	_DWORD* i;  // ecx

	result = 0;
	for (i = *a1; i; ++result)
		i = (_DWORD*)*i;
	return result;
}

//----- (004BD340) --------------------------------------------------------
_DWORD*  sub_4BD340(int a1, int a2, int a3, int a4) {
	_DWORD* v4; // esi

	v4 = malloc(0x1Cu);
	memset(v4, 0, 0x1Cu);
	*v4 = a1;
	v4[6] = a4;
	v4[1] = sub_4BD280(a2 / (a4 + 24), a4 + 24);
	v4[2] = sub_4BD280(a3, 84);
	nox_common_list_clear_425760(v4 + 3);
	if (v4[1] && v4[2])
		return v4;
	sub_4BD3C0(v4);
	return 0;
}

//----- (004BD3C0) --------------------------------------------------------
void  sub_4BD3C0(LPVOID lpMem) {
	int i; // eax

	for (i = nox_common_list_getNext_425940((int*)lpMem + 3); i; i = nox_common_list_getNext_425940((int*)lpMem + 3))
		sub_4BD690(i);
	if (*((_DWORD*)lpMem + 1))
		sub_4BD2D0(*((LPVOID*)lpMem + 1));
	if (*((_DWORD*)lpMem + 2))
		sub_4BD2D0(*((LPVOID*)lpMem + 2));
	free(lpMem);
}

//----- (004BD420) --------------------------------------------------------
_DWORD*  sub_4BD420(int a1, int a2) {
	_DWORD* result; // eax

	result = *(_DWORD**)(a1 + 12);
	if (result == (_DWORD*)(a1 + 12))
		return 0;
	while (result[4] != a2 || !result[5]) {
		result = (_DWORD*)*result;
		if (result == (_DWORD*)(a1 + 12))
			return 0;
	}
	return result;
}

//----- (004BD450) --------------------------------------------------------
_DWORD*  sub_4BD450(int a1) {
	_DWORD* result; // eax

	for (result = *(_DWORD**)(a1 + 12); result != (_DWORD*)(a1 + 12); result = (_DWORD*)*result)
		result[5] = 0;
	return result;
}

//----- (004BD470) --------------------------------------------------------
_DWORD*  sub_4BD470(_DWORD** a1, int a2) {
	_DWORD* v2;    // eax
	_DWORD* v3;    // edi
	_DWORD* v5;    // ebx
	_DWORD* v6;    // eax
	_DWORD* v7;    // ebp
	char* v8;      // edi
	signed int v9; // eax
	_DWORD* v10;   // [esp+18h] [ebp+8h]

	v2 = sub_4BD420((int)a1, a2);
	v3 = v2;
	if (v2) {
		sub_425920((_DWORD**)v2);
		sub_425900(a1 + 3, v3);
		return v3;
	}
	if (sub_486B60((int)*a1, a2)) {
		v5 = sub_4BD2E0((_DWORD**)a1[2]);
		if (!v5) {
			sub_4BD600((int)a1);
			v5 = sub_4BD2E0((_DWORD**)a1[2]);
			if (!v5) {
				sub_486E00((int)*a1);
				return 0;
			}
		}
		v5[4] = a2;
		v5[13] = a1;
		sub_425770(v5);
		v5[3] = 0;
		sub_487C30(v5 + 6);
		nullsub_10(v5 + 14);
		v5[11] = v5 + 14;
		v6 = (_DWORD*)(*a1)[71];
		v10 = (_DWORD*)(*a1)[71];
		if (!v6) {
		LABEL_19:
			sub_486AA0(*a1, v5[4], v5 + 14);
			sub_425900(a1 + 3, v5);
			v5[5] = 1;
			sub_486E00((int)*a1);
			return v5;
		}
		while (1) {
			v7 = a1[6];
			if ((int)v7 > (int)v6)
				v7 = v6;
			v8 = (char*)sub_4BD2E0((_DWORD**)a1[1]);
			if (!v8)
				break;
		LABEL_17:
			sub_487D30(v8, (int)(v8 + 24), (int)v7);
			sub_487C50((int)(v5 + 6), v8);
			v9 = sub_486DB0((int)*a1, v8 + 24, (signed int)v7);
			if ((_DWORD*)v9 != v7)
				goto LABEL_20;
			v10 = (_DWORD*)((char*)v10 - v9);
			if (!v10)
				goto LABEL_19;
			v6 = v10;
		}
		while (sub_4BD600((int)a1)) {
			v8 = (char*)sub_4BD2E0((_DWORD**)a1[1]);
			if (v8)
				goto LABEL_17;
		}
	LABEL_20:
		sub_4BD690((int)v5);
	}
	return 0;
}
// 487CF0: using guessed type void  nullsub_10(_DWORD);

//----- (004BD600) --------------------------------------------------------
int  sub_4BD600(int a1) {
	int v1; // esi

	v1 = sub_425960(a1 + 12);
	if (!v1)
		return 0;
	while (sub_4BD680(v1)) {
		v1 = sub_425960(v1);
		if (!v1)
			return 0;
	}
	sub_4BD690(v1);
	return 1;
}

//----- (004BD650) --------------------------------------------------------
int  sub_4BD650(int a1) {
	int result; // eax

	result = a1;
	++*(_DWORD*)(a1 + 12);
	return result;
}

//----- (004BD660) --------------------------------------------------------
int  sub_4BD660(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 12) - 1;
	*(_DWORD*)(a1 + 12) = result;
	if (result < 0)
		*(_DWORD*)(a1 + 12) = 0;
	return result;
}

//----- (004BD680) --------------------------------------------------------
int  sub_4BD680(int a1) { return *(_DWORD*)(a1 + 12); }

//----- (004BD690) --------------------------------------------------------
int  sub_4BD690(int a1) {
	_DWORD** i; // esi

	if (*(_DWORD*)(a1 + 4) != a1)
		sub_425920((_DWORD**)a1);
	for (i = (_DWORD**)nox_common_list_getNext_425940((int*)(a1 + 32)); i; i = (_DWORD**)nox_common_list_getNext_425940((int*)(a1 + 32))) {
		sub_425920(i);
		sub_487D60((int)i);
		sub_4BD300(*(_DWORD**)(*(_DWORD*)(a1 + 52) + 4), (int)i);
	}
	nullsub_9(a1 + 24);
	return sub_4BD300(*(_DWORD**)(*(_DWORD*)(a1 + 52) + 8), a1);
}
// 487CA0: using guessed type void  nullsub_9(_DWORD);

//----- (004BD700) --------------------------------------------------------
int  nox_xxx___fileno_0_4BD700(int a1) { return *(int*)(a1 + 16); }

//----- (004BD710) --------------------------------------------------------
int  sub_4BD710(int a1) { return a1 + 24; }

//----- (004BD720) --------------------------------------------------------
_DWORD*  sub_4BD720(int a1) {
	_DWORD* v1; // esi

	v1 = malloc(0x138u);
	memset(v1, 0, 0x138u);
	sub_425770(v1);
	sub_4BDC00((int)(v1 + 30));
	sub_4864A0(v1 + 44);
	sub_4BD7C0(v1);
	v1[33] = a1;
	v1[43] = *(_DWORD*)(a1 + 256);
	if (!(*(int(**)(_DWORD*))(*(_DWORD*)(a1 + 256) + 4))(v1))
		return v1;
	if (v1)
		sub_4BD7A0(v1);
	return 0;
}

//----- (004BD7A0) --------------------------------------------------------
void  sub_4BD7A0(LPVOID lpMem) {
	(*(void(**)(LPVOID))(*((_DWORD*)lpMem + 43) + 8))(lpMem);
	free(lpMem);
}

//----- (004BD7C0) --------------------------------------------------------
_DWORD*  sub_4BD7C0(_DWORD* a1) {
	_DWORD* result; // eax

	a1[69] = sub_4BD8C0;
	a1[70] = sub_4BD940;
	a1[71] = sub_4BD9B0;
	a1[34] = 0;
	a1[35] = 0;
	a1[36] = 0;
	a1[38] = 0;
	a1[3] = 1;
	sub_4BDC00((int)(a1 + 30));
	a1[30] = 0;
	a1[29] = *getMemU32Ptr(0x5D4594, 1193340);
	a1[28] = 0;
	result = sub_4864A0(a1 + 4);
	a1[72] = 0;
	return result;
}

//----- (004BD840) --------------------------------------------------------
int  sub_4BD840(int a3) {
	int v1;           // ebp
	unsigned int* v2; // edi
	_DWORD* v3;       // esi
	int result;       // eax

	v1 = *(_DWORD*)(a3 + 132);
	v2 = (unsigned int*)(a3 + 176);
	sub_4864A0((_DWORD*)(a3 + 176));
	sub_486570((unsigned int*)(a3 + 176), (_DWORD*)(a3 + 16));
	sub_486620((_DWORD*)(a3 + 16));
	if (*(_DWORD*)(a3 + 112)) {
		sub_486570(v2, *(_DWORD**)(a3 + 112));
		sub_486620(*(_DWORD**)(a3 + 112));
	}
	v3 = *(_DWORD**)(a3 + 116);
	if (v3)
		sub_486570(v2, v3);
	sub_486570(v2, (_DWORD*)(v1 + 88));
	result = *(_DWORD*)(v1 + 184);
	if (result)
		result = sub_486570(v2, *(_DWORD**)(v1 + 184));
	return result;
}

//----- (004BD8C0) --------------------------------------------------------
int  sub_4BD8C0(int a1) {
	int( * v1)(int); // eax
	int result;             // eax
	int v3;                 // eax
	int v4;                 // eax

	v1 = *(int(**)(int))(a1 + 136);
	if (v1) {
		result = v1(a1);
		if (result) {
			*(_DWORD*)(a1 + 300) = 0;
			*(_DWORD*)(a1 + 304) = 0;
			*(_DWORD*)(a1 + 296) = 0;
			return result;
		}
	} else {
		if (*(_DWORD*)(a1 + 292)) {
			v3 = nox_common_list_getNext_425940(*(int**)(a1 + 292));
			*(_DWORD*)(a1 + 292) = v3;
			if (v3) {
				*(_DWORD*)(a1 + 296) = *(_DWORD*)(v3 + 12);
				v4 = *(_DWORD*)(v3 + 16);
				*(_DWORD*)(a1 + 300) = v4;
				*(_DWORD*)(a1 + 304) = v4;
				return 0;
			}
		}
		*(_DWORD*)(a1 + 300) = 0;
	}
	return 0;
}

//----- (004BD940) --------------------------------------------------------
int  sub_4BD940(int a1) {
	void( * v1)(int); // eax

	if (*(_DWORD*)(a1 + 128)) {
		if (*(int*)(a1 + 128) != -1)
			--*(_DWORD*)(a1 + 128);
		sub_4BDB90((_DWORD*)a1, *(_DWORD**)(a1 + 288));
	} else {
		sub_4BDB90((_DWORD*)a1, 0);
	}
	v1 = *(void(**)(int))(a1 + 140);
	if (v1)
		v1(a1);
	if (*(_DWORD*)(a1 + 288))
		(*(void(**)(int))(*(_DWORD*)(a1 + 172) + 36))(a1);
	return 0;
}

//----- (004BD9B0) --------------------------------------------------------
int  sub_4BD9B0(_DWORD* a2) {
	int v1;                     // eax
	int( * v2)(_DWORD*); // eax
	int result;                 // eax

	a2[72] = 0;
	v1 = a2[31];
	LOBYTE(v1) = v1 & 0xFA;
	a2[31] = v1;
	a2[32] = 0;
	sub_4864A0(a2 + 4);
	v2 = (int(*)(_DWORD*))a2[36];
	if (v2)
		result = v2(a2);
	else
		result = 0;
	return result;
}

//----- (004BDA00) --------------------------------------------------------
int  sub_4BDA00(int a1) { return *(_DWORD*)(a1 + 124) & 8; }

//----- (004BDA10) --------------------------------------------------------
int  sub_4BDA10(int a1, int a2) {
	*(_DWORD*)(a1 + 12) = a2;
	*(_DWORD*)(a1 + 124) |= 8u;
	return sub_4BDA80(a1);
}

//----- (004BDA30) --------------------------------------------------------
_DWORD*  sub_4BDA30(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	if (a1[31] & 8) {
		a1[31] &= 0xFFFFFFF7;
		a1[3] = 1;
		result = sub_4BD7C0(a1);
	}
	return result;
}

//----- (004BDA60) --------------------------------------------------------
void  sub_4BDA60(LPVOID lpMem) {
	sub_4BDA80((int)lpMem);
	sub_486E90((int)lpMem);
	sub_4BD7A0(lpMem);
}

//----- (004BDA80) --------------------------------------------------------
int  sub_4BDA80(int a1) {
	int result = 0;              // eax
	int( * result2)(int); // eax

	if (*(_BYTE*)(a1 + 124) & 5)
		(*(void(**)(int))(*(_DWORD*)(a1 + 172) + 16))(a1);
	result2 = *(int(**)(int))(a1 + 148);
	if (result2)
		result = (int)result2(a1);
	*(_DWORD*)(a1 + 288) = 0;
	return result;
}

//----- (004BDAC0) --------------------------------------------------------
void  sub_4BDAC0(int a1) {
	int v1; // eax

	if (*(_BYTE*)(a1 + 124) & 1) {
		v1 = *(_DWORD*)(a1 + 124);
		LOBYTE(v1) = v1 & 0xFE;
		*(_DWORD*)(a1 + 124) = v1;
		(*(int(**)(int))(*(_DWORD*)(a1 + 172) + 20))(a1);
		*(_DWORD*)(a1 + 124) |= 4u;
	}
}

//----- (004BDAF0) --------------------------------------------------------
void  sub_4BDAF0(int a1) {
	if (*(_BYTE*)(a1 + 124) & 4) {
		(*(int(**)(int))(*(_DWORD*)(a1 + 172) + 24))(a1);
		*(_DWORD*)(a1 + 124) &= 0xFFFFFFFB;
		*(_DWORD*)(a1 + 124) |= 1u;
	}
}

//----- (004BDB20) --------------------------------------------------------
int  sub_4BDB20(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 124) |= 0x10u;
	return result;
}

//----- (004BDB30) --------------------------------------------------------
int  sub_4BDB30(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 124) &= 0xFFFFFFEF;
	return result;
}

//----- (004BDB40) --------------------------------------------------------
int  sub_4BDB40(int a2) {
	int result; // eax

	if (*(_BYTE*)(a2 + 124) & 5)
		return -2146500608;
	if (!*(_DWORD*)(a2 + 288))
		return -2147024896;
	sub_486520((unsigned int*)(a2 + 16));
	sub_4BD840(a2);
	result = (*(int(**)(int))(*(_DWORD*)(a2 + 172) + 12))(a2);
	if (!result)
		*(_DWORD*)(a2 + 124) |= 1u;
	return result;
}

//----- (004BDB90) --------------------------------------------------------
void  sub_4BDB90(_DWORD* a1, _DWORD* a2) {
	int v2;     // eax
	int v3;     // eax
	_DWORD* v4; // eax
	int v5;     // eax

	a1[72] = a2;
	if (a2) {
		v2 = sub_487C80((int)a2);
		a1[73] = v2;
		if (v2) {
			a1[74] = *(_DWORD*)(v2 + 12);
			v3 = *(_DWORD*)(v2 + 16);
			a1[75] = v3;
			a1[76] = v3;
			*a2 = 0;
		} else {
			v4 = (_DWORD*)a1[72];
			a1[74] = *v4;
			v5 = v4[1];
			a1[75] = v5;
			a1[76] = v5;
		}
	}
}

//----- (004BDC00) --------------------------------------------------------
int  sub_4BDC00(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 8) = 0;
	*(_DWORD*)(a1 + 4) = 0;
	return result;
}

//----- (004BDC10) --------------------------------------------------------
int  nox_xxx_loadAdvancedWnd_4BDC10(int* a1) {
	dword_5d4594_1316708 = nox_new_window_from_file("advanced.wnd", nox_xxx_windowAdvancedServProc_4BDDB0);
	sub_46B120(*(_DWORD**)&dword_5d4594_1316708, 0);
	sub_46C690(*(int*)&dword_5d4594_1316708);
	nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1316708);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1316708, sub_4BDDA0);
	nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_1316708);
	return sub_4BDC70(a1);
}

//----- (004BDC70) --------------------------------------------------------
int  sub_4BDC70(int* a1) {
	_DWORD* v1; // eax
	_DWORD* v2; // eax
	_DWORD* v3; // eax

	if (nox_common_gameFlags_check_40A5C0(1)) {
		v1 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316708, 10167);
		v1[9] |= 4u;
		dword_5d4594_1316704 = 0;
	} else {
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316708, 10164);
		v2[9] |= 4u;
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316708, 10167);
		nox_xxx_wnd_46ABB0((int)v3, 0);
		dword_5d4594_1316704 = 1;
	}
	sub_453F70(a1 + 6);
	sub_4535E0(a1 + 11);
	sub_4535F0(a1[12]);
	return sub_4BDD10();
}

//----- (004BDD10) --------------------------------------------------------
int sub_4BDD10() {
	int v1;   // eax
	char* v2; // eax

	switch (dword_5d4594_1316704) {
	case 0:
		v2 = sub_4165B0();
		v1 = sub_4CEBA0(*(int*)&dword_5d4594_1316708, v2);
		goto LABEL_6;
	case 1:
		dword_5d4594_1316712 = nox_xxx_guiSpelllistLoad_453850(*(int*)&dword_5d4594_1316708);
		return nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_1316712);
	case 2:
		v1 = nox_xxx_guiObjlistLoad_4530C0(*(int*)&dword_5d4594_1316708, 0x1000000);
		goto LABEL_6;
	case 3:
		v1 = nox_xxx_guiObjlistLoad_4530C0(*(int*)&dword_5d4594_1316708, 0x2000000);
	LABEL_6:
		dword_5d4594_1316712 = v1;
		break;
	default:
		return nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_1316712);
	}
	return nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_1316712);
}

//----- (004BDDA0) --------------------------------------------------------
int sub_4BDDA0() { return 1; }

//----- (004BDDB0) --------------------------------------------------------
int  nox_xxx_windowAdvancedServProc_4BDDB0(int a1, int a2, int* a3, int a4) {
	int v3;     // esi
	int result; // eax
	char* v5;   // ebx

	if (a2 == 23)
		return 1;
	if (a2 != 16391)
		return 1;
	v3 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	switch (v3) {
	case 10148:
		v5 = sub_4165B0();
		memcpy(v5 + 24, sub_453F90(), 0x14u);
		*((_DWORD*)v5 + 11) = *(_DWORD*)sub_453600();
		*((_DWORD*)v5 + 12) = sub_453610();
		sub_4BDF30();
		return 1;
	case 10164:
		if (dword_5d4594_1316712) {
			nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1316712);
			dword_5d4594_1316712 = 0;
		}
		dword_5d4594_1316704 = 1;
		sub_4BDD10();
		result = 1;
		break;
	case 10165:
		if (dword_5d4594_1316712) {
			nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1316712);
			dword_5d4594_1316712 = 0;
		}
		dword_5d4594_1316704 = 2;
		sub_4BDD10();
		result = 1;
		break;
	case 10166:
		if (dword_5d4594_1316712) {
			nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1316712);
			dword_5d4594_1316712 = 0;
		}
		dword_5d4594_1316704 = 3;
		sub_4BDD10();
		result = 1;
		break;
	case 10167:
		if (dword_5d4594_1316712) {
			nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1316712);
			dword_5d4594_1316712 = 0;
		}
		dword_5d4594_1316704 = 0;
		sub_4BDD10();
		result = 1;
		break;
	default:
		return 1;
	}
	return result;
}

//----- (004BDF30) --------------------------------------------------------
int sub_4BDF30() {
	int result; // eax

	result = dword_5d4594_1316708;
	if (dword_5d4594_1316708) {
		nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_1316708);
		nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1316708);
		dword_5d4594_1316708 = 0;
		dword_5d4594_1316712 = 0;
		result = nox_xxx_windowFocus_46B500(0);
	}
	return result;
}

//----- (004BDF70) --------------------------------------------------------
int  sub_4BDF70(int* a1) {
	int result; // eax

	result = *(int*)&dword_5d4594_1316708;
	if (dword_5d4594_1316708)
		result = sub_4BDF90(a1);
	return result;
}

//----- (004BDF90) --------------------------------------------------------
int  sub_4BDF90(int* a1) {
	int result = 0;       // eax
	int (*result2)(void); // eax

	sub_453F70(a1 + 6);
	sub_4535E0(a1 + 11);
	sub_4535F0(a1[12]);
	result2 = *(int (**)(void)) getMemAt(0x587000, 180016 + 4 * dword_5d4594_1316704);
	if (result2)
		result = result2();
	return result;
}

//----- (004BDFD0) --------------------------------------------------------
int sub_4BDFD0() {
	char* v0;   // eax
	int v1;     // esi
	int v2;     // edi
	_DWORD* v3; // eax
	_DWORD* v4; // eax
	int v5;     // eax
	_DWORD* v6; // esi
	_DWORD* v7; // eax
	int v9;     // [esp+8h] [ebp-8h]
	int v10;    // [esp+Ch] [ebp-4h]

	v0 = sub_416640();
	v1 = nox_strman_get_lang_code();
	v2 = (int)v0;
	if (nox_xxx_guiFontHeightMB_43F320(0) > 10)
		v1 = 2;
	if (nox_xxx_check_flag_aaa_43AF70() == 1)
		v3 = nox_new_window_from_file(*(const char**)getMemAt(0x587000, 180088 + 4 * v1), sub_4BE330);
	else
		v3 = nox_new_window_from_file(*(const char**)getMemAt(0x587000, 180048 + 4 * v1), sub_4BE330);
	dword_5d4594_1316972 = v3;
	sub_46B120(v3, 0);
	sub_46C690(*(int*)&dword_5d4594_1316972);
	nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1316972);
	nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_1316972);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1316972, sub_4BE320);
	v4 = nox_xxx_wndGetChildByID_46B0C0(0, 10100);
	nox_gui_getWindowOffs_46AA20((int)v4, &v10, &v9);
	if (nox_xxx_check_flag_aaa_43AF70() == 1)
		v5 = v9 + 55;
	else
		v5 = v9 + 80;
	nox_window_setPos_46A9B0(*(_DWORD**)&dword_5d4594_1316972, v10 + 15, v5);
	v6 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2104);
	nox_xxx_wnd_46B280((int)v6, *(int*)&dword_5d4594_1316972);
	nox_xxx_wndSetProc_46B2C0((int)v6, sub_4BE330);
	if (nox_xxx_check_flag_aaa_43AF70() == 1) {
		v7 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2119);
		nox_xxx_wnd_46B280((int)v7, *(int*)&dword_5d4594_1316972);
	}
	return sub_4BE120(v2);
}

//----- (004BE120) --------------------------------------------------------
int  sub_4BE120(int a1) {
	_DWORD* v1;      // eax
	int v2;          // ecx
	unsigned int v3; // ecx
	_DWORD* v4;      // eax
	int v5;          // ecx
	unsigned int v6; // ecx
	_DWORD* v7;      // esi
	_DWORD* v8;      // eax
	_DWORD* v9;      // eax
	_DWORD* v10;     // eax
	_DWORD* v11;     // eax
	_DWORD* v12;     // eax
	int result;      // eax
	_DWORD* v14;     // eax
	int v15;         // [esp-14h] [ebp-40h]
	wchar_t v16[16]; // [esp+Ch] [ebp-20h]

	v1 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2102);
	v2 = v1[9];
	if (*(_DWORD*)(a1 + 58))
		v3 = v2 | 4;
	else
		v3 = v2 & 0xFFFFFFFB;
	v1[9] = v3;
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2103);
	v5 = v4[9];
	if (*(_DWORD*)(a1 + 62))
		v6 = v5 | 4;
	else
		v6 = v5 & 0xFFFFFFFB;
	v4[9] = v6;
	v7 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2110);
	nox_swprintf(v16, L"%d", *(_DWORD*)(a1 + 70));
	nox_window_call_field_94((int)v7, 16414, (int)v16, -1);
	switch (*(_DWORD*)(a1 + 66)) {
	case 0:
		v8 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2110);
		nox_xxx_wnd_46ABB0((int)v8, 0);
		v15 = 2106;
		goto LABEL_12;
	case 1:
		v9 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2110);
		nox_xxx_wnd_46ABB0((int)v9, 0);
		v10 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2107);
		goto LABEL_13;
	case 2:
		v11 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2110);
		nox_xxx_wnd_46ABB0((int)v11, 0);
		v10 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2108);
		goto LABEL_13;
	case 3:
		v12 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2110);
		nox_xxx_wnd_46ABB0((int)v12, 1);
		v15 = 2109;
	LABEL_12:
		v10 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, v15);
	LABEL_13:
		v10[9] |= 4u;
		break;
	default:
		break;
	}
	result = nox_xxx_check_flag_aaa_43AF70();
	if (result == 1) {
		v14 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2119);
		nox_window_call_field_94((int)v14, 16394, *(_DWORD*)(a1 + 74), 0);
		result = sub_4BE2C0(*(_DWORD*)(a1 + 74));
	}
	return result;
}

//----- (004BE320) --------------------------------------------------------
int sub_4BE320() { return 1; }

//----- (004BE330) --------------------------------------------------------
int  sub_4BE330(int a1, unsigned int a2, int* a3, int a4) {
	_DWORD* v4;         // esi
	char* v5;           // edi
	int result;         // eax
	const wchar_t* v7;  // eax
	int v8;             // eax
	int v9;             // esi
	char* v10;          // eax
	char* v11;          // eax
	char* v12;          // esi
	_DWORD* v13;        // eax
	char* v14;          // esi
	_DWORD* v15;        // eax
	char* v16;          // esi
	_DWORD* v17;        // eax
	char* v18;          // esi
	_DWORD* v19;        // eax
	char* v20;          // edi
	const wchar_t* v21; // eax
	int v22;            // esi

	if (a2 > 0x4007) {
		if (a2 == 16393) {
			sub_4BE2C0(a4);
			nox_xxx_gameSetAudioFadeoutMb_501AC0(a4);
		} else if (a2 == 16415) {
			v20 = sub_416640();
			v21 = (const wchar_t*)nox_window_call_field_94((int)a3, 16413, 0, 0);
			if (v21) {
				if (*v21) {
					v22 = nox_wcstol(v21, 0, 10);
					if (v22 < 0)
						v22 = 0;
					if (nox_xxx_wndGetID_46B0A0(a3) == 2110) {
						*(_DWORD*)(v20 + 70) = v22;
						return 1;
					}
				}
			}
		}
		return 1;
	}
	if (a2 != 16391) {
		if (a2 != 23 && a2 == 16387) {
			v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, a4);
			v5 = sub_416640();
			if (!v4)
				return 0;
			if ((unsigned __int16)a3 == 1)
				return 0;
			v7 = (const wchar_t*)nox_window_call_field_94((int)v4, 16413, 0, 0);
			if (v7 && *v7) {
				v8 = nox_wcstol(v7, 0, 10);
				if (v8 < 0)
					v8 = 0;
				if (a4 == 2110) {
					*(_DWORD*)(v5 + 70) = v8;
					return 1;
				}
			}
		}
		return 1;
	}
	v9 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	switch (v9) {
	case 2102:
		v10 = sub_416640();
		*(_DWORD*)(v10 + 58) ^= 1u;
		result = 1;
		break;
	case 2103:
		v11 = sub_416640();
		*(_DWORD*)(v11 + 62) ^= 1u;
		result = 1;
		break;
	case 2106:
		v12 = sub_416640();
		v13 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2110);
		nox_xxx_wnd_46ABB0((int)v13, 0);
		*(_DWORD*)(v12 + 66) = 0;
		sub_40A6A0(1);
		result = 1;
		break;
	case 2107:
		v14 = sub_416640();
		v15 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2110);
		nox_xxx_wnd_46ABB0((int)v15, 0);
		*(_DWORD*)(v14 + 66) = 1;
		sub_40A6A0(1);
		result = 1;
		break;
	case 2108:
		v16 = sub_416640();
		v17 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2110);
		nox_xxx_wnd_46ABB0((int)v17, 0);
		*(_DWORD*)(v16 + 66) = 2;
		sub_40A6A0(1);
		result = 1;
		break;
	case 2109:
		v18 = sub_416640();
		v19 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1316972, 2110);
		nox_xxx_wnd_46ABB0((int)v19, 1);
		*(_DWORD*)(v18 + 66) = 3;
		sub_40A6A0(1);
		result = 1;
		break;
	case 2130:
		sub_4BE610();
		result = 1;
		break;
	default:
		return 1;
	}
	return result;
}

//----- (004BE610) --------------------------------------------------------
int sub_4BE610() {
	int result; // eax

	result = dword_5d4594_1316972;
	if (dword_5d4594_1316972) {
		nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_1316972);
		nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1316972);
		dword_5d4594_1316972 = 0;
		result = nox_xxx_windowFocus_46B500(0);
	}
	return result;
}

//----- (004BE640) --------------------------------------------------------
int  sub_4BE640(int a1, int a2) {
	unsigned int v2; // ecx
	int result;      // eax
	int v4;          // esi
	signed int v5;   // edi

	v2 = nox_xxx_bookGet_430B40_get_mouse_prev_seq() + a2;
	if (!a1)
		return 0;
	v4 = *(_DWORD*)(a1 + 96);
	if (*(_BYTE*)(v4 + 10)) {
		if (*(_BYTE*)(v4 + 10) == 2)
			result = *(_DWORD*)(*(_DWORD*)(v4 + 4) + 4 * ((int)(v2 / ((unsigned int)*(unsigned __int8*)(v4 + 9) + 1)) %
														  *(unsigned __int8*)(v4 + 8)));
		else
			result = 0;
	} else {
		v5 = (v2 - *(_DWORD*)(v4 + 12)) / ((unsigned int)*(unsigned __int8*)(v4 + 9) + 1);
		if (v5 >= *(unsigned __int8*)(v4 + 8) - 1) {
			v5 = *(unsigned __int8*)(v4 + 8) - 1;
			if (*(_DWORD*)v4)
				(*(void(**)(int))v4)(a1);
		}
		result = *(_DWORD*)(*(_DWORD*)(v4 + 4) + 4 * v5);
	}
	return result;
}

#ifndef NOX_CGO
//----- (004BE6D0) --------------------------------------------------------
void nox_video_drawAnimatedImageOrCursorAt_4BE6D0(int a1, int a2, int a3) {
	int v3 = sub_4BE640(a1, 0);
	if (v3) {
		if (dword_5d4594_3798728)
			sub_48B3F0(v3, a2, a3);
		else
			nox_client_drawImageAt_47D2C0(v3, a2, a3);
	}
}
#endif // NOX_CGO

//----- (004BE710) --------------------------------------------------------
__int16  sub_4BE710(int a1, int a2, int a3, int a4) {
	__int16 result = 0; // ax
	int v5;         // [esp-Ch] [ebp-Ch]

	v5 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 96) + 4) + 4 * a4);
	if (dword_5d4594_3798728)
		result = sub_48B3F0(v5, a2, a3);
	else
		nox_client_drawImageAt_47D2C0(v5, a2, a3);
	return result;
}

//----- (004BE750) --------------------------------------------------------
__int16  sub_4BE750(int a1, int a2, int a3) {
	int v3; // eax
	int v4; // esi
	int v6; // [esp+4h] [ebp-4h]

	v3 = sub_4BE640(a1, 0);
	v4 = v3;
	if (v3) {
		sub_47D5C0(v3, 0, 0, &v6, &a1);
		nox_client_drawImageAt_47D2C0(v4, a2 - v6 / 2, a3 - a1 / 2);
	}
	return v3;
}

//----- (004BE7B0) --------------------------------------------------------
int  sub_4BE7B0(int a1) {
	int result; // eax

	if (nox_client_getCursorType_477620() == 10) {
		++*getMemU32Ptr(0x5D4594, 1316976);
		result = sub_4BE640(a1, *getMemIntPtr(0x5D4594, 1316976));
	} else {
		*getMemU32Ptr(0x5D4594, 1316976) = 0;
		result = sub_4BE640(a1, 0);
	}
	return result;
}

//----- (004BE800) --------------------------------------------------------
int  sub_4BE800(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1316980) = a1;
	return result;
}

//----- (004BE810) --------------------------------------------------------
char  sub_4BE810(int a1, int a2, int a3, char a4) {
	char result; // al

	*getMemU32Ptr(0x5D4594, 1316988) = a1;
	result = a4;
	*getMemU32Ptr(0x5D4594, 1316984) = a2;
	*getMemU32Ptr(0x5D4594, 1316992) = a3;
	*getMemU8Ptr(0x5D4594, 1316996) = a4;
	return result;
}

//----- (004BE840) --------------------------------------------------------
int  sub_4BE840(int* a1, int* a2, int* a3, int* a4, int a5) {
	int v5;               // eax
	double v6;            // st7
	int* v7;              // edx
	unsigned __int8* v8;  // ecx
	int v9;               // esi
	int v10;              // ebx
	int v11;              // eax
	int v12;              // edx
	int v13;              // ebp
	unsigned __int8* v14; // eax
	int v15;              // ecx
	double v16;           // st7
	double v17;           // st7
	double v18;           // st6
	double v19;           // st5
	double v20;           // st4
	double v21;           // st3
	double v22;           // st2
	double v23;           // st1
	double v24;           // st0
	int result;           // eax
	int v26;              // esi
	int v27;              // edi
	int v28;              // ecx
	bool v29;             // zf
	int v30;              // [esp+4h] [ebp-38h]
	int v31;              // [esp+8h] [ebp-34h]
	int v32;              // [esp+Ch] [ebp-30h]
	int v33;              // [esp+14h] [ebp-28h]
	int v34;              // [esp+18h] [ebp-24h]
	int v35[4];
	int v39[4];
	int v43;   // [esp+40h] [ebp+4h]
	float v44; // [esp+40h] [ebp+4h]
	int v45;   // [esp+44h] [ebp+8h]
	int v46;   // [esp+48h] [ebp+Ch]
	float v47; // [esp+48h] [ebp+Ch]
	int v48;   // [esp+4Ch] [ebp+10h]

	v31 = *a1;
	v34 = a1[1];
	v5 = a3[1];
	v30 = *a3;
	v6 = 1.0 / (double)a5;
	v46 = *a4;
	v7 = a2;
	v45 = a4[1];
	v48 = *v7;
	v33 = v7[1];
	v32 = v5;
	v8 = getMemAt(0x581450, 9812);
	v43 = 0;
	do {
		v9 = *((_DWORD*)v8 - 1);
		v10 = v31;
		v11 = v32 * *((_DWORD*)v8 + 1) + v45 * *((_DWORD*)v8 + 2);
		v12 = v33 * *(_DWORD*)v8;
		v39[v43] = v31 * *((_DWORD*)v8 - 1) + v30 * *((_DWORD*)v8 + 1) + v48 * *(_DWORD*)v8 + v46 * *((_DWORD*)v8 + 2);
		v13 = v34;
		v8 += 16;
		v35[v43] = v34 * v9 + v12 + v11;
		v43++;
	} while ((int)v8 < (int)getMemAt(0x581450, 9876));
	*getMemFloatPtr(0x587000, 180484) = v6;
	v14 = getMemAt(0x587000, 180468);
	v15 = 0;
	*(float*)&dword_587000_180480 = v6 * v6;
	*(float*)&dword_587000_180476 = v6 * v6 * v6;
	*getMemFloatPtr(0x587000, 180496) = *(float*)&dword_587000_180480 + *(float*)&dword_587000_180480;
	v16 = *(float*)&dword_587000_180476 * 6.0;
	*getMemFloatPtr(0x587000, 180492) = v16;
	*getMemFloatPtr(0x587000, 180508) = v16;
	v17 = (double)v39[3];
	v18 = (double)v39[2];
	v19 = (double)v39[1];
	v20 = (double)v39[0];
	v21 = (double)v35[3];
	v22 = (double)v35[2];
	v47 = (double)v35[1];
	v44 = (double)v35[0];
	do {
		v23 = v20 * *((float*)v14 - 2);
		v24 = v19 * *((float*)v14 - 1);
		v14 += 16;
		*(float*)((char*)&v35 + v15) = v23 + v24 + v18 * *((float*)v14 - 4) + v17 * *((float*)v14 - 3);
		*(float*)((char*)&v39 + v15) =
			v44 * *((float*)v14 - 6) + v47 * *((float*)v14 - 5) + v22 * *((float*)v14 - 4) + v21 * *((float*)v14 - 3);
		v15 += 4;
	} while ((int)v14 < (int)getMemAt(0x587000, 180532));
	result = a5;
	if (a5 > 0) {
		do {
			*(float*)v35 = *(float*)v35 + *(float*)&v35[1];
			*(float*)&v35[1] = *(float*)&v35[2] + *(float*)&v35[1];
			*(float*)&v35[2] = *(float*)&v35[3] + *(float*)&v35[2];
			*(float*)v39 = *(float*)v39 + *(float*)&v39[1];
			*(float*)&v39[1] = *(float*)&v39[2] + *(float*)&v39[1];
			*(float*)&v39[2] = *(float*)&v39[3] + *(float*)&v39[2];
			v26 = nox_float2int(v35[0]);
			v27 = nox_float2int(v39[0]);
			nox_client_drawAddPoint_49F500(v10, v13);
			nox_client_drawAddPoint_49F500(v26, v27);
			nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 1316980));
			nox_client_drawLineFromPoints_49E4B0();
			if (*getMemU32Ptr(0x5D4594, 1316988)) {
				nox_client_drawAddPoint_49F500(v10, v13);
				nox_client_drawAddPoint_49F500(v26, v27);
				sub_434040(*getMemIntPtr(0x5D4594, 1316984));
				sub_434080(*getMemIntPtr(0x5D4594, 1316992));
				LOBYTE(v28) = getMemByte(0x5D4594, 1316996);
				sub_49E4F0(v28);
			}
			v10 = v26;
			result = a5 - 1;
			v29 = a5 == 1;
			v13 = v27;
			--a5;
		} while (!v29);
	}
	return result;
}
// 4BEAA0: variable 'v28' is possibly undefined

//----- (004BEAD0) --------------------------------------------------------
void  sub_4BEAD0(int2* a1, int2* a2, int2* a3, int2* a4, int a5, int a6) {
	int v6;               // eax
	double v7;            // st7
	unsigned __int8* v8;  // ecx
	int v9;               // edi
	int v10;              // eax
	int v11;              // esi
	int v12;              // ebx
	int v13;              // edi
	int v14;              // edx
	int v15;              // ebx
	unsigned __int8* v16; // eax
	int v17;              // ecx
	double v18;           // st7
	double v19;           // st7
	double v20;           // st6
	double v21;           // st5
	double v22;           // st4
	double v23;           // st3
	double v24;           // st2
	double v25;           // st1
	double v26;           // st0
	int v27;              // ebp
	int v28;              // ebx
	int i;                // eax
	int v30;              // esi
	int v31;              // ecx
	int v32;              // eax
	bool v33;             // zf
	int v34;              // [esp+4h] [ebp-38h]
	int v35;              // [esp+8h] [ebp-34h]
	int v36;              // [esp+Ch] [ebp-30h]
	int v37;              // [esp+10h] [ebp-2Ch]
	int v38;              // [esp+14h] [ebp-28h]
	int v39;              // [esp+18h] [ebp-24h]
	int v40[8];           // [esp+1Ch] [ebp-20h]
	int v41;              // [esp+40h] [ebp+4h]
	int v42;              // [esp+44h] [ebp+8h]
	float v43;            // [esp+44h] [ebp+8h]
	int v44;              // [esp+48h] [ebp+Ch]
	int v45;              // [esp+4Ch] [ebp+10h]
	float v46;            // [esp+4Ch] [ebp+10h]
	int v47;              // [esp+4Ch] [ebp+10h]
	int v48;              // [esp+50h] [ebp+14h]

	v36 = a1->field_0;
	v41 = a1->field_4;
	v6 = a4->field_4;
	v34 = a4->field_0;
	v7 = 1.0 / (double)a5;
	v35 = a2->field_0;
	v39 = a2->field_4;
	v42 = a3->field_0;
	v38 = a3->field_4;
	v44 = v6;
	v8 = getMemAt(0x581450, 9876);
	v45 = 0;
	do {
		v9 = *((_DWORD*)v8 + 1);
		v10 = *((_DWORD*)v8 + 2);
		v37 = v9;
		v11 = v39 * *(_DWORD*)v8;
		v12 = v35 * *(_DWORD*)v8 + v34 * v10 + v42 * v9;
		v13 = v36;
		v14 = v41 * *((_DWORD*)v8 - 1);
		v15 = v36 * *((_DWORD*)v8 - 1) + v12;
		v8 += 16;
		v40[v45 + 4] = v15;
		*(int*)((char*)&v40[0] + v45 * 4) = v14 + v11 + v38 * v37 + v44 * v10;
		++v45;
	} while ((int)v8 < (int)getMemAt(0x581450, 9940));
	*getMemFloatPtr(0x587000, 180484) = v7;
	v16 = getMemAt(0x587000, 180468);
	v17 = 0;
	*(float*)&dword_587000_180480 = v7 * v7;
	*(float*)&dword_587000_180476 = v7 * v7 * v7;
	*getMemFloatPtr(0x587000, 180496) = *(float*)&dword_587000_180480 + *(float*)&dword_587000_180480;
	v18 = *(float*)&dword_587000_180476 * 6.0;
	*getMemFloatPtr(0x587000, 180492) = v18;
	*getMemFloatPtr(0x587000, 180508) = v18;
	v19 = (double)v40[7];
	v20 = (double)v40[6];
	v21 = (double)v40[5];
	v22 = (double)v40[4];
	v23 = (double)v40[3];
	v24 = (double)v40[2];
	v43 = (double)v40[1];
	v46 = (double)v40[0];
	do {
		v25 = v22 * *((float*)v16 - 2);
		v26 = v21 * *((float*)v16 - 1);
		v16 += 16;
		*(float*)((char*)&v40[0] + v17 * 4) = v25 + v26 + v20 * *((float*)v16 - 4) + v19 * *((float*)v16 - 3);
		++v17;
		*(float*)&v40[v17 + 3] =
			v46 * *((float*)v16 - 6) + v43 * *((float*)v16 - 5) + v24 * *((float*)v16 - 4) + v23 * *((float*)v16 - 3);
	} while ((int)v16 < (int)getMemAt(0x587000, 180532));
	if (a5 > 0) {
		v47 = a5;
		do {
			*(float*)v40 = *(float*)v40 + *(float*)&v40[1];
			*(float*)&v40[1] = *(float*)&v40[2] + *(float*)&v40[1];
			*(float*)&v40[2] = *(float*)&v40[3] + *(float*)&v40[2];
			*(float*)&v40[4] = *(float*)&v40[4] + *(float*)&v40[5];
			*(float*)&v40[5] = *(float*)&v40[6] + *(float*)&v40[5];
			*(float*)&v40[6] = *(float*)&v40[7] + *(float*)&v40[6];
			v27 = nox_float2int(*(float*)v40);
			v28 = nox_float2int(*(float*)&v40[4]);
			nox_client_drawAddPoint_49F500(v13, v41);
			nox_client_drawAddPoint_49F500(v27, v28);
			nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 1316980));
			nox_client_drawLineFromPoints_49E4B0();
			if (a6) {
				v48 = 0;
				for (i = v13 - v28;; i = v13 - v28) {
					v30 = v48 != 0 ? 1 : -1;
					if (i >= 0)
						v31 = i;
					else
						v31 = v28 - v13;
					if (i < 0)
						i = v28 - v13;
					if (v31 <= i) {
						nox_client_drawAddPoint_49F500(v30 + v27, v28);
						nox_client_drawAddPoint_49F500(v13 + v30, v41);
					} else {
						nox_client_drawAddPoint_49F500(v27, v30 + v28);
						nox_client_drawAddPoint_49F500(v13, v41 + v30);
					}
					nox_client_drawLineFromPoints_49E4B0();
					if (++v48 >= 2)
						break;
				}
			}
			if (*getMemU32Ptr(0x5D4594, 1316988)) {
				nox_client_drawAddPoint_49F500(v13, v41);
				nox_client_drawAddPoint_49F500(v27, v28);
				sub_434040(*getMemIntPtr(0x5D4594, 1316984));
				v32 = sub_434080(*getMemIntPtr(0x5D4594, 1316992));
				LOBYTE(v32) = getMemByte(0x5D4594, 1316996);
				sub_49E4F0(v32);
			}
			v13 = v27;
			v33 = v47 == 1;
			v41 = v28;
			--v47;
		} while (!v33);
	}
}

//----- (004BEDE0) --------------------------------------------------------
void  sub_4BEDE0(int2* a1, int2* a2, int2* a3, int2* a4, int a5, float a6, int a7, int a8) {
	int v8;               // ecx
	double v9;            // st7
	unsigned __int8* v10; // ecx
	int v11;              // esi
	int v12;              // eax
	int v13;              // ebx
	int v14;              // eax
	int v15;              // esi
	double v16;           // st6
	double v17;           // st7
	double v18;           // st7
	float v19;            // [esp+0h] [ebp-54h]
	float v20;            // [esp+0h] [ebp-54h]
	float v21;            // [esp+10h] [ebp-44h]
	float v22;            // [esp+10h] [ebp-44h]
	int v23;              // [esp+14h] [ebp-40h]
	float v24;            // [esp+14h] [ebp-40h]
	int v25;              // [esp+18h] [ebp-3Ch]
	float v26;            // [esp+18h] [ebp-3Ch]
	int v27;              // [esp+1Ch] [ebp-38h]
	float v28;            // [esp+1Ch] [ebp-38h]
	int v29;              // [esp+20h] [ebp-34h]
	float v30;            // [esp+20h] [ebp-34h]
	int v31;              // [esp+24h] [ebp-30h]
	float v32;            // [esp+24h] [ebp-30h]
	int v33;              // [esp+28h] [ebp-2Ch]
	float v34;            // [esp+28h] [ebp-2Ch]
	int2 v35[5];          // [esp+2Ch] [ebp-28h]
	int2* v36;            // [esp+58h] [ebp+4h]
	float v37;            // [esp+58h] [ebp+4h]
	int2* v38;            // [esp+5Ch] [ebp+8h]
	float v39;            // [esp+5Ch] [ebp+8h]
	int v40;              // [esp+60h] [ebp+Ch]
	float v41;            // [esp+60h] [ebp+Ch]
	int v42;              // [esp+64h] [ebp+10h]
	float v43;            // [esp+64h] [ebp+10h]
	float v44;            // [esp+68h] [ebp+14h]
	float v45;            // [esp+6Ch] [ebp+18h]

	v8 = a1->field_0;
	v33 = a1->field_4;
	v35[2].field_4 = a1->field_4;
	v25 = v8;
	v35[2].field_0 = v8;
	v27 = a2->field_0;
	v9 = 1.0 / (double)a5;
	v23 = a3->field_0;
	v29 = a3->field_4;
	v21 = 0.0;
	v40 = a4->field_0;
	v31 = a2->field_4;
	v42 = a4->field_4;
	v10 = getMemAt(0x581450, 9876);
	v38 = 0;
	do {
		v11 = *((_DWORD*)v10 + 1);
		v12 = *((_DWORD*)v10 + 2);
		v36 = (int2*)*((_DWORD*)v10 - 1);
		v13 = v27 * *(_DWORD*)v10 + v25 * (_DWORD)v36 + v23 * v11 + v40 * v12;
		v14 = v33 * (_DWORD)v36 + v31 * *(_DWORD*)v10 + v29 * v11 + v42 * v12;
		v10 += 16;
		*(int*)((char*)&v35[0].field_0 + (_DWORD)v38) = v13;
		*(int*)((char*)&v35[3].field_0 + (_DWORD)v38) = v14;
		v38 = (int2*)((char*)v38 + 4);
	} while ((int)v10 < (int)getMemAt(0x581450, 9940));
	v15 = a5;
	if (a5 > 0) {
		v16 = v9 * a6;
		v41 = v16 + v9;
		v45 = (double)v35[0].field_0;
		v43 = (double)v35[0].field_4;
		v34 = (double)v35[1].field_0;
		v32 = (double)v35[1].field_4;
		v28 = (double)v35[3].field_0;
		v30 = (double)v35[3].field_4;
		v26 = (double)v35[4].field_0;
		v24 = (double)v35[4].field_4;
		do {
			v17 = v41 + v21;
			v22 = v17;
			if (v17 > 1.0)
				v22 = 1.0;
			v18 = v22 * v22;
			v44 = v18;
			v37 = v18 * v22;
			v19 = v43 * v44 + v45 * v37 + v34 * v22 + v32;
			v35[0].field_0 = nox_float2int(v19);
			v20 = v30 * v44 + v28 * v37 + v26 * v22 + v24;
			v35[0].field_4 = nox_float2int(v20);
			v39 = v16;
			v21 = v22 - v39;
			((void(*)(int2*, int2*, int))a7)(&v35[2], v35, a8);
			--v15;
			v35[2].field_0 = v35[0].field_0;
			v35[2].field_4 = v35[0].field_4;
		} while (v15);
	}
}

//----- (004BF010) --------------------------------------------------------
int  nox_xxx_clientReportSecondaryWeapon_4BF010(int a1) {
	int v1;     // ecx
	char v3[3]; // [esp+0h] [ebp-4h]
	char v4;    // [esp+3h] [ebp-1h]

	v4 = HIBYTE(v1);
	v3[0] = -32;
	*(_WORD*)&v3[1] = nox_xxx_netGetUnitCodeCli_578B00(a1);
	return nox_xxx_netClientSend2_4E53C0(31, v3, 3, 0, 1);
}

//----- (004BF7E0) --------------------------------------------------------
__int16  sub_4BF7E0(_DWORD* a1) {
	int v1;               // esi
	int v2;               // ebp
	int v3;               // eax
	int v4;               // edi
	int v5;               // ebx
	int v6;               // eax
	int v7;               // eax
	int v8;               // ebx
	int v9;               // eax
	int v10;              // ebx
	int v11;              // eax
	int v13;              // [esp+10h] [ebp-4h]
	unsigned __int8* v14; // [esp+18h] [ebp+4h]
	unsigned __int8* v15; // [esp+18h] [ebp+4h]

	v1 = a1[1] + 15;
	v2 = *a1 + 11;
	v13 = a1[1] + 15;
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 952));
	nox_client_drawRectFilledOpaque_49CE30(v2, v1, 200, 200);
	LOWORD(v3) = *getMemU16Ptr(0x852978, 8);
	if (*getMemU32Ptr(0x852978, 8)) {
		v4 = *getMemU32Ptr(0x8531A0, 2576);
		if (*getMemU32Ptr(0x8531A0, 2576)) {
			nox_xxx_drawPlayer_4341D0(1, *(_DWORD*)(*getMemU32Ptr(0x8531A0, 2576) + 2296));
			nox_xxx_drawPlayer_4341D0(2, *(_DWORD*)(v4 + 2304));
			nox_xxx_drawPlayer_4341D0(3, *(_DWORD*)(v4 + 2312));
			nox_xxx_drawPlayer_4341D0(4, *(_DWORD*)(v4 + 2308));
			nox_xxx_drawPlayer_4341D0(5, *(_DWORD*)(v4 + 2300));
			nox_xxx_drawPlayer_4341D0(6, *(_DWORD*)(v4 + 2292));
			if (*(_DWORD*)(v4 + 2292) == *(_DWORD*)(v4 + 2296))
				nox_client_drawImageAt_47D2C0(*getMemU32Ptr(0x973A20, 24 + 4 * *(unsigned __int8*)(v4 + 2252)), v2,
											  v1);
			else
				nox_client_drawImageAt_47D2C0(*getMemU32Ptr(0x973A20, 16 + 4 * *(unsigned __int8*)(v4 + 2252)), v2,
											  v1);
			v5 = 0;
			v14 = getMemAt(0x973A20, 32 + 104 * *(unsigned __int8*)(v4 + 2252));
			do {
				if (*(_DWORD*)v4 & (1 << v5) && !((1 << v5) & 0x3000000)) {
					v6 = sub_415CD0((char*)(1 << v5));
					sub_4BF9F0(1 << v5, v6, v2, v13, (int)v14, v5, 0);
				}
				++v5;
			} while (v5 < 26);
			if (*(_BYTE*)v4 & 2) {
				v7 = sub_415CD0((char*)2);
				sub_4BF9F0(2, v7, v2, v13, (int)v14, 0, 1);
			}
			v8 = 0;
			do {
				if (*(_DWORD*)v4 & (1 << v8) && (1 << v8) & 0x3000000) {
					v9 = sub_415CD0((char*)(1 << v8));
					sub_4BF9F0(1 << v8, v9, v2, v13, (int)v14, v8, 0);
				}
				++v8;
			} while (v8 < 26);
			v10 = 0;
			v15 = getMemAt(0x973A20, 256 + 108 * *(unsigned __int8*)(v4 + 2252));
			do {
				v3 = *(_DWORD*)(v4 + 4);
				if (v3 & (1 << v10)) {
					v11 = sub_415840((char*)(1 << v10));
					LOWORD(v3) = sub_4BF9F0(1 << v10, v11, v2, v13, (int)v15, v10, 0);
				}
				++v10;
			} while (v10 < 27);
		}
	}
	return v3;
}

//----- (004BF9F0) --------------------------------------------------------
__int16  sub_4BF9F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
	int v7;      // eax
	int v8;      // esi
	_DWORD* v9;  // eax
	int v10;     // edx
	int v11;     // ecx
	_DWORD* v12; // ebx
	int v13;     // ebp
	int v14;     // edi
	_BYTE* v15;  // esi
	int* v16;    // edi
	_BYTE** v17; // esi
	int v18;     // ebx
	_BYTE* v19;  // eax

	v7 = sub_461600(a2);
	v8 = v7;
	if (v7) {
		if (*(_DWORD*)(v7 + 112) & 0x2000000)
			v9 = nox_xxx_equipClothFindDefByTT_413270(*(_DWORD*)(v7 + 108));
		else
			v9 = nox_xxx_getProjectileClassById_413250(*(_DWORD*)(v7 + 108));
		v12 = v9;
		if (v9) {
			v13 = v8 + 432;
			v14 = 1;
			v15 = v9 + 4;
			do {
				LOBYTE(v9) = v15[1];
				LOBYTE(v11) = *v15;
				LOBYTE(v10) = *(v15 - 1);
				sub_4340A0(v14++, v10, v11, (int)v9);
				v15 += 3;
			} while (v14 < 7);
			v16 = v12 + 9;
			v17 = (_BYTE**)v13;
			v18 = 4;
			do {
				v19 = *v17;
				if (*v17) {
					LOBYTE(v11) = v19[26];
					LOBYTE(v10) = v19[25];
					LOBYTE(v19) = v19[24];
					sub_4340A0(*v16, (int)v19, v10, v11);
				}
				++v17;
				++v16;
				--v18;
			} while (v18);
		}
		if (a7)
			nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1319052), a3, a4);
		else
			nox_client_drawImageAt_47D2C0(*(_DWORD*)(a5 + 4 * a6), a3, a4);
	}
	return v7;
}
// 4BFA4C: variable 'v10' is possibly undefined
// 4BFA4C: variable 'v11' is possibly undefined

//----- (004BFAD0) --------------------------------------------------------
int sub_4BFAD0() {
	int v0;         // esi
	int v1;         // ebx
	int i;          // edi
	char* v3;       // eax
	const char* v4; // ecx
	int v5;         // ebp
	int v6;         // ebp

	v0 = 0;
	v1 = 0;
	for (i = 0; i < 8; i += 4) {
		v3 = nox_xxx_gLoadImg_42F970(*(const char**)getMemAt(0x587000, 180960 + i));
		v4 = *(const char**)getMemAt(0x587000, 180968 + i);
		*getMemU32Ptr(0x973A20, 16 + i) = v3;
		*getMemU32Ptr(0x973A20, 24 + i) = nox_xxx_gLoadImg_42F970(v4);
		v5 = 26;
		do {
			*getMemU32Ptr(0x973A20, 32 + v1) = nox_xxx_gLoadImg_42F970(*(const char**)getMemAt(0x587000, 180976 + v1));
			v1 += 4;
			--v5;
		} while (v5);
		v6 = 27;
		do {
			*getMemU32Ptr(0x973A20, 256 + v0) = nox_xxx_gLoadImg_42F970(*(const char**)getMemAt(0x587000, 181184 + v0));
			v0 += 4;
			--v6;
		} while (v6);
	}
	*getMemU32Ptr(0x5D4594, 1319052) = nox_xxx_gLoadImg_42F970("MaleMedievalCloakTop");
	return 1;
}

//----- (004BFB70) --------------------------------------------------------
void sub_4BFB70(int a1) {
	if (dword_5d4594_1319056) {
		dword_5d4594_1319056 = a1;
	} else {
		if (a1 == 1)
			nox_xxx_clientPlaySoundSpecial_452D80(1022, 100);
		dword_5d4594_1319056 = a1;
	}
}

//----- (004BFBB0) --------------------------------------------------------
void sub_4BFBB0(_DWORD* a1) {
	if (dword_5d4594_1319056) {
		if (dword_5d4594_1319056 == 1) {
			if (!a1) {
				sub_4BFC70();
				sub_4BFB70(0);
			}
		}
	} else if (a1 == (_DWORD*)1) {
		sub_4BFBF0();
		sub_4BFB70(1);
	}
}

//----- (004BFBF0) --------------------------------------------------------
int sub_4BFBF0() {
	int result; // eax
	int v1;     // [esp+0h] [ebp-8h]
	int v2;     // [esp+4h] [ebp-4h]

	result = dword_5d4594_1319060;
	if (dword_5d4594_1319060) {
		nox_window_set_hidden(*(int*)&dword_5d4594_1319060, 0);
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1319060, 1);
		nox_window_get_size(*(int*)&dword_5d4594_1319060, &v2, &v1);
		nox_window_setPos_46A9B0(*(_DWORD**)&dword_5d4594_1319060, nox_win_width / 2 - v2 / 2, nox_win_height / 2 - v1 / 2);
		result = nox_xxx_windowFocus_46B500(0);
	}
	return result;
}

//----- (004BFC70) --------------------------------------------------------
int sub_4BFC70() {
	int result; // eax

	result = dword_5d4594_1319060;
	if (dword_5d4594_1319060) {
		nox_window_set_hidden(*(int*)&dword_5d4594_1319060, 1);
		result = nox_xxx_windowFocus_46B500(0);
	}
	return result;
}

//----- (004BFC90) --------------------------------------------------------
int sub_4BFC90() {
	int result; // eax

	result = nox_new_window_from_file("SKey.wnd", sub_4BFCD0);
	dword_5d4594_1319060 = result;
	if (result) {
		sub_4BFB70(0);
		sub_4BFC70();
		result = 1;
	}
	return result;
}

//----- (004BFCD0) --------------------------------------------------------
int  sub_4BFCD0(int a1, int a2, int* a3, int a4) {
	int v3; // esi

	if (a2 == 16391) {
		v3 = nox_xxx_wndGetID_46B0A0(a3);
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
		if (v3 == 10803)
			sub_4BFC70();
	}
	return 0;
}

//----- (004BFD10) --------------------------------------------------------
void sub_4BFD10() {
	nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1319060);
	dword_5d4594_1319060 = 0;
	sub_4BFB70(0);
}

//----- (004BFD30) --------------------------------------------------------
int sub_4BFD30() { return dword_5d4594_1319056; }

//----- (004BFD40) --------------------------------------------------------
void sub_4BFD40() {
	if (dword_5d4594_1319268 == 1) {
		nox_window_set_hidden(nox_gui_itemAmount_dialog_1319228, 1);
		nox_xxx_wnd_46ABB0(nox_gui_itemAmount_dialog_1319228, 0);
		nox_xxx_wnd_46C6E0(nox_gui_itemAmount_dialog_1319228);
		if (nox_gui_itemAmount_item_1319256)
			nox_xxx_spriteDelete_45A4B0(nox_gui_itemAmount_item_1319256);
		nox_gui_itemAmount_item_1319256 = 0;
		dword_5d4594_1319268 = 0;
	} else {
		nox_xxx_wnd_46ABB0(nox_gui_itemAmount_dialog_1319228, 1);
		sub_46C690(nox_gui_itemAmount_dialog_1319228);
		nox_xxx_wndShowModalMB_46A8C0(nox_gui_itemAmount_dialog_1319228);
		dword_5d4594_1319268 = 1;
	}
}

//----- (004BFDD0) --------------------------------------------------------
int  sub_4BFDD0(_DWORD* a1, int a2, unsigned int a3) {
	int result; // eax

	switch (a2) {
	case 5:
	case 9:
	case 13:
		if (!nox_xxx_wndPointInWnd_46AAB0(a1, (unsigned __int16)a3, a3 >> 16))
			sub_4BFE40();
		goto LABEL_4;
	case 6:
	case 7:
	case 10:
	case 11:
	case 14:
	case 15:
	LABEL_4:
		result = 1;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (004BFE40) --------------------------------------------------------
int sub_4BFE40() {
	const wchar_t* v0; // eax
	unsigned int v1;   // esi
	int v3;            // [esp+0h] [ebp-10h]
	int v4;            // [esp+4h] [ebp-Ch]
	int2 v5;           // [esp+8h] [ebp-8h]

	if (dword_5d4594_1319268 != 1)
		return 0;
	v0 = (const wchar_t*)sub_46AF00(*(int*)&dword_5d4594_1319232);
	v1 = nox_wcstol(v0, 0, 10);
	if (v1 > *(int*)&dword_5d4594_1319248)
		v1 = dword_5d4594_1319248;
	nox_gui_getWindowOffs_46AA20(nox_gui_itemAmount_dialog_1319228, &v3, &v4);
	v5.field_0 = v3 + dword_587000_183456;
	v5.field_4 = v4 + dword_587000_183460;
	if (*getMemU32Ptr(0x5D4594, 1319100))
		(*(void(**)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD)) getMemAt(0x5D4594, 1319100))(
			&v5, *getMemU32Ptr(0x5D4594, 1319244), *getMemU32Ptr(0x5D4594, 1319240), v1, *getMemU32Ptr(0x5D4594, 1319252));
	sub_4BFD40();
	return 1;
}

//----- (004BFEF0) --------------------------------------------------------
int nox_gui_itemAmount_init_4BFEF0() {
	dword_5d4594_1319264 = 0;
	nox_gui_itemAmount_dialog_1319228 = nox_new_window_from_file("MultMove.wnd", sub_4C01C0);
	if (!nox_gui_itemAmount_dialog_1319228)
		return 0;
	nox_window_set_all_funcs(nox_gui_itemAmount_dialog_1319228, sub_4BFDD0, sub_4C0030, 0);
	dword_5d4594_1319232 = nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3601);
	dword_5d4594_1319236 = nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3607);
	nox_window_set_hidden(nox_gui_itemAmount_dialog_1319228, 1);
	nox_xxx_wnd_46ABB0(nox_gui_itemAmount_dialog_1319228, 0);
	*getMemU32Ptr(0x5D4594, 1319108) = 0;
	*getMemU32Ptr(0x5D4594, 1319112) = 0;
	*getMemU32Ptr(0x5D4594, 1319116) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1319120) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1319140) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1319144) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1319124) = 0;
	*getMemU32Ptr(0x5D4594, 1319128) = 0;
	*getMemU32Ptr(0x5D4594, 1319196) = nox_xxx_gLoadImg_42F970("MultiMoveBase");
	*getMemU32Ptr(0x5D4594, 1319200) = nox_xxx_gLoadImg_42F970("MultiMoveUpLit");
	*getMemU32Ptr(0x5D4594, 1319204) = nox_xxx_gLoadImg_42F970("MultiMoveDownLit");
	*getMemU32Ptr(0x5D4594, 1319208) = nox_xxx_gLoadImg_42F970("MultiMoveYesPressed");
	*getMemU32Ptr(0x5D4594, 1319212) = nox_xxx_gLoadImg_42F970("MultiMoveNoPressed");
	*getMemU32Ptr(0x5D4594, 1319216) = nox_xxx_gLoadImg_42F970("MultiMoveBaseNoTag");
	*getMemU32Ptr(0x5D4594, 1319220) = nox_xxx_gLoadImg_42F970("MultiMoveYesPressedNoTag");
	*getMemU32Ptr(0x5D4594, 1319224) = nox_xxx_gLoadImg_42F970("MultiMoveNoPressedNoTag");
	return 1;
}

//----- (004C0030) --------------------------------------------------------
int  sub_4C0030(int a1) {
	int v1; // ecx
	int v2; // ecx
	int v3; // edx
	int v5; // [esp+0h] [ebp-8h]
	int v6; // [esp+4h] [ebp-4h]

	nox_client_drawRectFilledAlpha_49CF10(0, 0, nox_win_width, nox_win_height);
	nox_gui_getWindowOffs_46AA20(a1, &v5, &v6);
	v1 = *getMemU32Ptr(0x5D4594, 1319196);
	if (!dword_5d4594_1319264)
		v1 = *getMemU32Ptr(0x5D4594, 1319216);
	nox_client_drawImageAt_47D2C0(v1, v5, v6);
	*(_DWORD*)((_DWORD)nox_gui_itemAmount_item_1319256 + 12) = v5 + dword_587000_183456;
	*(_DWORD*)((_DWORD)nox_gui_itemAmount_item_1319256 + 16) = v6 + dword_587000_183460;
	(*(void(**)(unsigned __int8*, _DWORD))((_DWORD)nox_gui_itemAmount_item_1319256 + 300))(getMemAt(0x5D4594, 1319108), nox_gui_itemAmount_item_1319256);
	if (nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3603)->draw_data.field_0 & 4)
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1319204), v5, v6);
	if (nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3602)->draw_data.field_0 & 4)
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1319200), v5, v6);
	if (nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3604)->draw_data.field_0 & 4) {
		v2 = *getMemU32Ptr(0x5D4594, 1319208);
		if (!dword_5d4594_1319264)
			v2 = *getMemU32Ptr(0x5D4594, 1319220);
		nox_client_drawImageAt_47D2C0(v2, v5, v6);
	}
	if (nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3605)->draw_data.field_0 & 4) {
		v3 = *getMemU32Ptr(0x5D4594, 1319212);
		if (!dword_5d4594_1319264)
			v3 = *getMemU32Ptr(0x5D4594, 1319224);
		nox_client_drawImageAt_47D2C0(v3, v5, v6);
	}
	return 1;
}

//----- (004C01C0) --------------------------------------------------------
int  sub_4C01C0(int a1, int a2, int* a3, int a4) {
	int v3;            // esi
	int result;        // eax
	const wchar_t* v5; // eax
	unsigned int v6;   // esi
	const wchar_t* v7; // eax
	unsigned int v8;   // esi
	const wchar_t* v9; // eax
	int v10;           // eax
	int v11;           // esi
	int v12;           // [esp+4h] [ebp-10h]
	int v13;           // [esp+8h] [ebp-Ch]
	int2 v14;          // [esp+Ch] [ebp-8h]

	if (a2 != 16391 || dword_5d4594_1319268 != 1)
		return 0;
	v3 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	switch (v3) {
	case 3602:
		v7 = (const wchar_t*)sub_46AF00(*(int*)&dword_5d4594_1319232);
		v8 = nox_wcstol(v7, 0, 10) + 1;
		if (v8 > *(int*)&dword_5d4594_1319248)
			return 0;
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1319164), L"%d", v8);
		sub_46AEE0(*(int*)&dword_5d4594_1319232, (int)getMemAt(0x5D4594, 1319164));
		if (!dword_5d4594_1319264)
			return 0;
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1319068), L"%d", dword_5d4594_1319260 * v8);
		sub_46AEE0(*(int*)&dword_5d4594_1319236, (int)getMemAt(0x5D4594, 1319068));
		result = 0;
		break;
	case 3603:
		v9 = (const wchar_t*)sub_46AF00(*(int*)&dword_5d4594_1319232);
		v10 = nox_wcstol(v9, 0, 10);
		v11 = v10;
		if (v10 > 1) {
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1319164), L"%d", v10 - 1);
			sub_46AEE0(*(int*)&dword_5d4594_1319232, (int)getMemAt(0x5D4594, 1319164));
			if (dword_5d4594_1319264) {
				nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1319068), L"%d", dword_5d4594_1319260 * (v11 - 1));
				sub_46AEE0(*(int*)&dword_5d4594_1319236, (int)getMemAt(0x5D4594, 1319068));
			}
		}
		return 0;
	case 3604:
	case 3606:
		v5 = (const wchar_t*)sub_46AF00(*(int*)&dword_5d4594_1319232);
		v6 = nox_wcstol(v5, 0, 10);
		if (v6 > *(int*)&dword_5d4594_1319248)
			v6 = dword_5d4594_1319248;
		nox_gui_getWindowOffs_46AA20(nox_gui_itemAmount_dialog_1319228, &v12, &v13);
		v14.field_0 = v12 + dword_587000_183456;
		v14.field_4 = v13 + dword_587000_183460;
		if (*getMemU32Ptr(0x5D4594, 1319160))
			(*(void(**)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD)) getMemAt(0x5D4594, 1319160))(&v14, *getMemU32Ptr(0x5D4594, 1319244), *getMemU32Ptr(0x5D4594, 1319240), v6,
								   *getMemU32Ptr(0x5D4594, 1319252));
		sub_4BFD40();
		result = 0;
		break;
	case 3605:
		sub_4BFE40();
		result = 0;
		break;
	default:
		return 0;
	}
	return result;
}

//----- (004C03E0) --------------------------------------------------------
void nox_gui_itemAmount_free_4C03E0() {
	if (nox_gui_itemAmount_item_1319256)
		nox_xxx_spriteDelete_45A4B0(nox_gui_itemAmount_item_1319256);
	nox_gui_itemAmount_item_1319256 = 0;
	nox_xxx_windowDestroyMB_46C4E0(nox_gui_itemAmount_dialog_1319228);
	nox_gui_itemAmount_dialog_1319228 = 0;
	dword_5d4594_1319232 = 0;
	dword_5d4594_1319236 = 0;
	dword_5d4594_1319264 = 0;
}

//----- (004C0430) --------------------------------------------------------
int  nox_gui_itemAmountDialog_4C0430(wchar_t* title, int x, int y, int a4, int a5, const void* a6, int a7, int a8, void* accept, void* cancel) {
	_DWORD* v10; // eax
	int result;  // eax

	v10 = nox_xxx_wndGetChildByID_46B0C0(nox_gui_itemAmount_dialog_1319228, 3606);
	sub_46AEE0(v10, title);
	nox_gui_itemAmount_item_1319256 = nox_new_drawable_for_thing(a5);
	*(_DWORD*)((_DWORD)nox_gui_itemAmount_item_1319256 + 120) |= 0x40000000u;
	if (a6)
		memcpy((void*)((_DWORD)nox_gui_itemAmount_item_1319256 + 432), a6, 0x14u);
	*getMemU32Ptr(0x5D4594, 1319160) = accept;
	*getMemU32Ptr(0x5D4594, 1319100) = cancel;
	*getMemU32Ptr(0x5D4594, 1319240) = a5;
	*getMemU32Ptr(0x5D4594, 1319244) = a4;
	dword_5d4594_1319248 = a7;
	*getMemU32Ptr(0x5D4594, 1319252) = a8;
	sub_4BFD40();
	sub_4C0560(x, y);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1319164), L"%d", 1);
	sub_46AEE0(*(int*)&dword_5d4594_1319232, (int)getMemAt(0x5D4594, 1319164));
	if (dword_5d4594_1319264) {
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1319068), L"%d", dword_5d4594_1319260);
		result = sub_46AEE0(*(int*)&dword_5d4594_1319236, (int)getMemAt(0x5D4594, 1319068));
	} else {
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1319068), (const wchar_t*)getMemAt(0x5D4594, 1319272));
		result = sub_46AEE0(*(int*)&dword_5d4594_1319236, (int)getMemAt(0x5D4594, 1319068));
	}
	return result;
}

//----- (004C0560) --------------------------------------------------------
int  sub_4C0560(int a1, int a2) {
	int v2; // ecx
	int v3; // eax
	int v5; // [esp+8h] [ebp-8h]
	int v6; // [esp+Ch] [ebp-4h]

	nox_window_get_size(nox_gui_itemAmount_dialog_1319228, &v5, &v6);
	v2 = a1 - dword_587000_183456;
	v3 = a2 - dword_587000_183460;
	if (a1 - *(int*)&dword_587000_183456 < 0)
		v2 = 0;
	if (v3 < 0)
		v3 = 0;
	if (v2 + v5 >= nox_win_width)
		v2 = nox_win_width - v5;
	if (v3 + v6 >= nox_win_height)
		v3 = nox_win_height - v6;
	return nox_window_setPos_46A9B0(nox_gui_itemAmount_dialog_1319228, v2, v3);
}

//----- (004C05F0) --------------------------------------------------------
int  sub_4C05F0(int a1, int a2) {
	int result; // eax

	result = a1;
	dword_5d4594_1319264 = a1;
	dword_5d4594_1319260 = a2;
	return result;
}

//----- (004C0610) --------------------------------------------------------
int nox_xxx_func_4C0610() {
	char v1[2]; // [esp+0h] [ebp-2h]

	v1[0] = -55;
	v1[1] = 14;
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, v1, 2);
}

//----- (004C0630) --------------------------------------------------------
int  sub_4C0630(int a1, unsigned int a2, unsigned int a3) {
	int v3;      // eax
	_DWORD* v4;  // ecx
	_DWORD* v5;  // eax
	int v6;      // esi
	int v7;      // edi
	_DWORD* v8;  // eax
	int v9;      // esi
	int v10;     // edi
	_DWORD* v12; // eax
	_DWORD* v13; // eax
	_DWORD* v14; // esi
	int v15;     // eax
	int2 a1a;    // [esp+4h] [ebp-8h]

	a1a.field_4 = a3 >> 16;
	a1a.field_0 = (unsigned __int16)a3;
	if (a2 == 5) {
		v12 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3704);
		if (nox_xxx_wndPointInWnd_46AAB0(v12, a1a.field_0, a1a.field_4)) {
			LOBYTE(v13) = sub_4C0910(&a1a);
			v14 = v13;
			if (v13[1]) {
				nox_xxx_wndSetCaptureMain_46ADC0(*(int*)&dword_5d4594_1320940);
				nox_xxx_setKeybTimeout_4160D0(2);
				*(int2*)getMemAt(0x5D4594, 1319276) = a1a;
				dword_5d4594_1320968 = *v14;
				*(_DWORD*)(dword_5d4594_1320968 + 128) = v14[v14[1] + 1];
				v14[v14[1] + 1] = 0;
				nox_xxx_cursorSetDraggedItem_477690(*(int*)&dword_5d4594_1320968);
				v15 = v14[1] - 1;
				v14[1] = v15;
				if (!v15)
					*v14 = 0;
				dword_5d4594_1320972 = v14;
				*getMemU32Ptr(0x5D4594, 1320304) = 0;
				nox_xxx_clientPlaySoundSpecial_452D80(791, 100);
			}
		}
		return 1;
	}
	if (a2 <= 5 || a2 > 7)
		return 0;
	v3 = nox_xxx_wndGetCaptureMain_46AE00();
	v4 = *(_DWORD**)&dword_5d4594_1320940;
	if (v3 == dword_5d4594_1320940) {
		nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_1320940);
		v4 = *(_DWORD**)&dword_5d4594_1320940;
	}
	if (!dword_5d4594_1320968)
		return 1;
	if (*getMemU32Ptr(0x5D4594, 1320304)) {
		if (*getMemU32Ptr(0x5D4594, 1320304) == 1) {
			v8 = nox_xxx_wndGetChildByID_46B0C0(v4, 3705);
			if (!nox_xxx_wndPointInWnd_46AAB0(v8, a1a.field_0, a1a.field_4) || (v9 = *getMemU32Ptr(0x5D4594, 1319276) - a1a.field_0,
															  v10 = *getMemU32Ptr(0x5D4594, 1319280) - a1a.field_4,
															  !nox_xxx_checkKeybTimeout_4160F0(3u, nox_gameFPS / 3u)) &&
																 v9 * v9 + v10 * v10 < 100) {
				nox_xxx_clientTrade_0_4C08E0(*(int*)&dword_5d4594_1320968);
			}
		}
	} else {
		v5 = nox_xxx_wndGetChildByID_46B0C0(v4, 3704);
		if (nox_xxx_wndPointInWnd_46AAB0(v5, a1a.field_0, a1a.field_4)) {
			v6 = *getMemU32Ptr(0x5D4594, 1319276) - a1a.field_0;
			v7 = *getMemU32Ptr(0x5D4594, 1319280) - a1a.field_4;
			if (!nox_xxx_checkKeybTimeout_4160F0(2u, nox_gameFPS / 3u) && v6 * v6 + v7 * v7 < 100)
				nox_xxx_clientTrade_0_4C08E0(*(int*)&dword_5d4594_1320968);
		} else {
			nox_xxx_clientTrade_0_4C08E0(*(int*)&dword_5d4594_1320968);
		}
	}
	*(_DWORD*)(dword_5d4594_1320972 + 4 * (*(_DWORD*)(dword_5d4594_1320972 + 4))++ + 8) =
		*(_DWORD*)(dword_5d4594_1320968 + 128);
	if (*(_DWORD*)(dword_5d4594_1320972 + 4) == 1)
		**(_DWORD**)&dword_5d4594_1320972 = dword_5d4594_1320968;
	nox_xxx_cursorResetDraggedItem_4776A0();
	dword_5d4594_1320968 = 0;
	dword_5d4594_1320972 = 0;
	return 1;
}
// 4C0836: variable 'v13' is possibly undefined

//----- (004C08E0) --------------------------------------------------------
int  nox_xxx_clientTrade_0_4C08E0(int a1) {
	char v2[4]; // [esp+0h] [ebp-4h]

	v2[0] = -55;
	v2[1] = 16;
	*(_WORD*)&v2[2] = nox_xxx_netGetUnitCodeCli_578B00(a1);
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, v2, 4);
}

//----- (004C0910) --------------------------------------------------------
char  sub_4C0910(int2* a1) {
	_DWORD* v1; // eax
	int v2;     // edi
	int v3;     // ebx
	int i;      // esi
	int v5;     // eax
	int v7;     // [esp+10h] [ebp-1Ch]
	int v8;     // [esp+14h] [ebp-18h]
	int v9;     // [esp+18h] [ebp-14h]
	int4 v10;   // [esp+1Ch] [ebp-10h]

	v1 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3704);
	nox_client_wndGetPosition_46AA60(v1, &v8, &v9);
	v2 = 0;
	v7 = 0;
	while (2) {
		v3 = 0;
		for (i = 0; i < 100; i += 50) {
			v10.field_0 = i + v8;
			v10.field_8 = i + v8 + 50;
			v10.field_4 = v2 + v9;
			v10.field_C = v2 + v9 + 50;
			v5 = sub_4281F0(a1, &v10);
			if (v5)
				return (char)getMemAt(0x5D4594, 1319284 + 140 * (v7 + 2 * v3));
			++v3;
		}
		v2 += 50;
		++v7;
		if (v2 < 100)
			continue;
		break;
	}
	return v5;
}
// 4C097E: variable 'v5' is possibly undefined

//----- (004C0C90) --------------------------------------------------------
int  sub_4C0C90(int a1, int a2, int* a3, int a4) {
	int v3; // esi

	if (a2 == 16391) {
		v3 = nox_xxx_wndGetID_46B0A0(a3);
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
		if (v3 == 3708) {
			nox_xxx_clientTrade_4C0CE0();
		} else if (v3 == 3710) {
			nox_xxx_func_4C0610();
			return 0;
		}
	}
	return 0;
}

//----- (004C0CE0) --------------------------------------------------------
int nox_xxx_clientTrade_4C0CE0() {
	char v1[2]; // [esp+0h] [ebp-2h]

	v1[0] = -55;
	v1[1] = 17;
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, v1, 2);
}

//----- (004C0D00) --------------------------------------------------------
int sub_4C0D00() {
	_DWORD* v0;           // eax
	_DWORD* v1;           // eax
	_DWORD* v2;           // eax
	_DWORD* v3;           // eax
	_DWORD* v4;           // eax
	_DWORD* v5;           // eax
	unsigned __int8* v6;  // esi
	int v7;               // ebp
	int v8;               // ebx
	int v9;               // edi
	_DWORD* v10;          // eax
	unsigned __int8* v11; // esi
	int v12;              // ebp
	int v13;              // ebx
	int v14;              // edi
	unsigned __int8* v16; // [esp+10h] [ebp-58h]
	unsigned __int8* v17; // [esp+10h] [ebp-58h]
	int v18;              // [esp+14h] [ebp-54h]
	int v19;              // [esp+18h] [ebp-50h]
	int v20;              // [esp+1Ch] [ebp-4Ch]
	int v21;              // [esp+20h] [ebp-48h]
	int v22;              // [esp+24h] [ebp-44h]
	wchar_t v23[32];      // [esp+28h] [ebp-40h]

	nox_gui_getWindowOffs_46AA20(*(int*)&dword_5d4594_1320940, &v21, &v22);
	nox_window_get_size(*(int*)&dword_5d4594_1320940, &v20, &v19);
	nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1320164), v21, v22);
	v0 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3711);
	nox_window_call_field_94((int)v0, 16385, (int)getMemAt(0x5D4594, 1320240), 0);
	v1 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3712);
	nox_window_call_field_94((int)v1, 16385, (int)getMemAt(0x5D4594, 1320868), 0);
	v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3713);
	nox_window_call_field_94((int)v2, 16385, (int)getMemAt(0x5D4594, 1320100), 0);
	nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1320184), v21 + *getMemU32Ptr(0x587000, 183696) - 64,
								  v22 + *getMemU32Ptr(0x587000, 183700) - 64);
	nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1320184), v21 + *getMemU32Ptr(0x587000, 183704) - 64,
								  v22 + *getMemU32Ptr(0x587000, 183708) - 64);
	v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3708);
	if (dword_5d4594_1320944) {
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1320172), v21, v22);
	} else if (v3[9] & 4) {
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1320168), v21, v22);
	}
	if (dword_5d4594_1320948)
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1320176), v21, v22);
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3710);
	if (*getMemU32Ptr(0x5D4594, 1320960) || v4[9] & 4)
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1320180), v21, v22);
	v5 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3704);
	nox_client_wndGetPosition_46AA60(v5, &v21, &v22);
	v6 = getMemAt(0x5D4594, 1319284);
	v18 = nox_xxx_guiFontHeightMB_43F320(0);
	v7 = 0;
	v16 = getMemAt(0x5D4594, 1319284);
	do {
		v8 = 0;
		do {
			if (*((_DWORD*)v6 + 1)) {
				*(_DWORD*)(*(_DWORD*)v6 + 12) = v8 + v21 + 25;
				*(_DWORD*)(*(_DWORD*)v6 + 16) = v22 + v7 + 25;
				(*(void(**)(unsigned __int8*, _DWORD))(*(_DWORD*)v6 + 300))(getMemAt(0x5D4594, 1320188), *(_DWORD*)v6);
				nox_swprintf(v23, L"%d", *((_DWORD*)v6 + 1));
				nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
				nox_xxx_drawString_43F6E0(0, (__int16*)v23, v8 + v21 + 5, v22 + v7 + 5);
				v9 = v22 + v7 + 50;
				nox_swprintf(v23, L"%d", *((_DWORD*)v6 + 34));
				nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2589772));
				nox_xxx_drawString_43F6E0(0, (__int16*)v23, v8 + v21 + 5, v9 - v18 - 5);
			}
			v8 += 50;
			v6 += 280;
		} while (v8 < 100);
		v7 += 50;
		v6 = v16 + 140;
		v16 += 140;
	} while ((int)v16 < (int)getMemAt(0x5D4594, 1319564));
	v10 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3705);
	nox_client_wndGetPosition_46AA60(v10, &v21, &v22);
	v11 = getMemAt(0x5D4594, 1320308);
	v12 = 0;
	v17 = getMemAt(0x5D4594, 1320308);
	do {
		v13 = 0;
		do {
			if (*((_DWORD*)v11 + 1)) {
				*(_DWORD*)(*(_DWORD*)v11 + 12) = v13 + v21 + 25;
				*(_DWORD*)(*(_DWORD*)v11 + 16) = v22 + v12 + 25;
				(*(void(**)(unsigned __int8*, _DWORD))(*(_DWORD*)v11 + 300))(getMemAt(0x5D4594, 1320188),
																					*(_DWORD*)v11);
				nox_swprintf(v23, L"%d", *((_DWORD*)v11 + 1));
				nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
				nox_xxx_drawString_43F6E0(0, (__int16*)v23, v13 + v21 + 5, v22 + v12 + 5);
				v14 = v22 + v12 + 50;
				nox_swprintf(v23, L"%d", *((_DWORD*)v11 + 34));
				nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2589772));
				nox_xxx_drawString_43F6E0(0, (__int16*)v23, v13 + v21 + 5, v14 - v18 - 5);
			}
			v13 += 50;
			v11 += 280;
		} while (v13 < 100);
		v12 += 50;
		v11 = v17 + 140;
		v17 += 140;
	} while ((int)v17 < (int)getMemAt(0x5D4594, 1320588));
	return 1;
}

//----- (004C1120) --------------------------------------------------------
int  sub_4C1120(int a1, int a2, wchar_t** a3) {
	_DWORD* v3;   // eax
	wchar_t** v4; // eax
	_DWORD* v5;   // eax
	wchar_t* v6;  // eax
	int2 a1a;     // [esp+0h] [ebp-8h]

	a1a.field_0 = (unsigned __int16)a3;
	a1a.field_4 = (unsigned int)a3 >> 16;
	v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3704);
	if (nox_xxx_wndPointInWnd_46AAB0(v3, (unsigned __int16)a3, (unsigned int)a3 >> 16)) {
		LOBYTE(v4) = sub_4C0910(&a1a);
	} else {
		v5 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3705);
		if (nox_xxx_wndPointInWnd_46AAB0(v5, a1a.field_0, a1a.field_4))
			LOBYTE(v4) = sub_4C11E0(&a1a);
		else
			v4 = a3;
	}
	if (*v4) {
		*((_DWORD*)*v4 + 32) = v4[2];
		v6 = nox_xxx_clientAskInfoMb_4BF050(*v4);
		nox_xxx_cursorSetTooltip_4776B0(v6);
	}
	return 1;
}
// 4C11AC: variable 'v4' is possibly undefined

//----- (004C11E0) --------------------------------------------------------
char  sub_4C11E0(_DWORD* a1) {
	_DWORD* v1; // eax
	int v2;     // edi
	int v3;     // ebx
	int i;      // esi
	int v5;     // eax
	int v7;     // [esp+10h] [ebp-1Ch]
	int v8;     // [esp+14h] [ebp-18h]
	int v9;     // [esp+18h] [ebp-14h]
	int4 v10;   // [esp+1Ch] [ebp-10h]

	v1 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3705);
	nox_client_wndGetPosition_46AA60(v1, &v8, &v9);
	v2 = 0;
	v7 = 0;
	while (2) {
		v3 = 0;
		for (i = 0; i < 100; i += 50) {
			v10.field_0 = i + v8;
			v10.field_8 = i + v8 + 50;
			v10.field_4 = v2 + v9;
			v10.field_C = v2 + v9 + 50;
			v5 = sub_4281F0((int2*)a1, &v10);
			if (v5)
				return (char)getMemAt(0x5D4594, 1320308 + 140 * (v7 + 2 * v3));
			++v3;
		}
		v2 += 50;
		++v7;
		if (v2 < 100)
			continue;
		break;
	}
	return v5;
}
// 4C124E: variable 'v5' is possibly undefined

//----- (004C12A0) --------------------------------------------------------
int nox_xxx_closeP2PTradeWnd_4C12A0() {
	int result; // eax

	nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1320940);
	result = 0;
	dword_5d4594_1320940 = 0;
	dword_5d4594_1320964 = 0;
	return result;
}

//----- (004C12C0) --------------------------------------------------------
int sub_4C12C0() { return dword_5d4594_1320964; }

//----- (004C12D0) --------------------------------------------------------
int nox_xxx_showP2PTradeWnd_4C12D0() {
	int result; // eax

	result = dword_5d4594_1320964;
	if (dword_5d4594_1320964)
		result = nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1320940);
	return result;
}

//----- (004C12F0) --------------------------------------------------------
BOOL  sub_4C12F0(int* a1) {
	_DWORD* v1; // eax

	v1 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3704);
	return nox_xxx_wndPointInWnd_46AAB0(v1, *a1, a1[1]);
}

//----- (004C1320) --------------------------------------------------------
int  nox_xxx_netP2PStartTrade_4C1320(int a1) {
	int v1;     // esi
	_DWORD* v3; // eax
	_DWORD* v4; // eax
	int v5;     // [esp+4h] [ebp-8h]
	int v6;     // [esp+8h] [ebp-4h]

	v1 = *getMemU32Ptr(0x8531A0, 2576);
	if (!*getMemU32Ptr(0x8531A0, 2576))
		return 0;
	if (dword_5d4594_1320964 == 1)
		return 0;
	dword_5d4594_1320964 = 1;
	sub_4C1410();
	nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1319844), (const wchar_t*)(a1 + 2));
	nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1320940, 1);
	nox_xxx_showP2PTradeWnd_4C12D0();
	nox_window_get_size(*(int*)&dword_5d4594_1320940, &v6, &v5);
	nox_window_setPos_46A9B0(*(_DWORD**)&dword_5d4594_1320940, 198, 193);
	v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3702);
	nox_window_call_field_94((int)v3, 16385, v1 + 4704, 0);
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3703);
	nox_window_call_field_94((int)v4, 16385, (int)getMemAt(0x5D4594, 1319844), 0);
	sub_467BB0();
	return 1;
}

//----- (004C1410) --------------------------------------------------------
int sub_4C1410() {
	_DWORD* v0;          // eax
	_DWORD* v1;          // eax
	unsigned __int8* v2; // ebp
	unsigned __int8* v3; // esi
	int v4;              // ebx
	unsigned __int8* v5; // ebp
	unsigned __int8* v6; // esi
	int v7;              // ebx
	_DWORD* v8;          // eax
	_DWORD* v9;          // eax
	_DWORD* v10;         // eax
	int result;          // eax
	wchar_t v12[64];     // [esp+10h] [ebp-80h]

	*getMemU16Ptr(0x5D4594, 1320240) = 0;
	*getMemU16Ptr(0x5D4594, 1320868) = 0;
	*getMemU16Ptr(0x5D4594, 1320100) = 0;
	v0 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3702);
	nox_window_call_field_94((int)v0, 16385, (int)getMemAt(0x5D4594, 1320976), 0);
	v1 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3703);
	nox_window_call_field_94((int)v1, 16385, (int)getMemAt(0x5D4594, 1320980), 0);
	v2 = getMemAt(0x5D4594, 1319284);
	do {
		v3 = v2;
		v4 = 2;
		do {
			if (*(_DWORD*)v3)
				nox_xxx_spriteDelete_45A4B0(*(_QWORD**)v3);
			*(_DWORD*)v3 = 0;
			*((_DWORD*)v3 + 1) = 0;
			v3 += 280;
			--v4;
		} while (v4);
		v2 += 140;
	} while ((int)v2 < (int)getMemAt(0x5D4594, 1319564));
	v5 = getMemAt(0x5D4594, 1320308);
	do {
		v6 = v5;
		v7 = 2;
		do {
			if (*(_DWORD*)v6)
				nox_xxx_spriteDelete_45A4B0(*(_QWORD**)v6);
			*(_DWORD*)v6 = 0;
			*((_DWORD*)v6 + 1) = 0;
			v6 += 280;
			--v7;
		} while (v7);
		v5 += 140;
	} while ((int)v5 < (int)getMemAt(0x5D4594, 1320588));
	nox_swprintf(v12, (const wchar_t*)getMemAt(0x5D4594, 1319972), 0);
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3711);
	nox_window_call_field_94((int)v8, 16385, (int)v12, 0);
	v9 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3712);
	nox_window_call_field_94((int)v9, 16385, (int)v12, 0);
	v10 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3713);
	result = nox_window_call_field_94((int)v10, 16385, (int)v12, 0);
	dword_5d4594_1320944 = 0;
	dword_5d4594_1320948 = 0;
	dword_5d4594_1320968 = 0;
	dword_5d4594_1320972 = 0;
	dword_5d4594_1320932 = 0;
	dword_5d4594_1320936 = 0;
	return result;
}

//----- (004C1590) --------------------------------------------------------
int sub_4C1590() {
	int result; // eax

	result = dword_5d4594_1320964;
	if (dword_5d4594_1320964) {
		sub_4C1410();
		nox_window_set_hidden(*(int*)&dword_5d4594_1320940, 1);
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1320940, 0);
		dword_5d4594_1320964 = 0;
		result = sub_467C10();
	}
	return result;
}

//----- (004C1710) --------------------------------------------------------
int  sub_4C1710(int a1, int a2) {
	int result; // eax
	_DWORD* i;  // ecx
	_DWORD* v4; // ecx
	int v5;     // edx

	result = 0;
	for (i = (_DWORD*)(a1 + 8); *i != a2; ++i) {
		if (++result >= 32)
			return result;
	}
	if (result < 31) {
		v4 = (_DWORD*)(a1 + 4 * result + 8);
		v5 = 31 - result;
		do {
			result = v4[1];
			*v4 = result;
			++v4;
			--v5;
		} while (v5);
	}
	*(_DWORD*)(a1 + 132) = 0;
	return result;
}

//----- (004C1760) --------------------------------------------------------
int  sub_4C1760(int a1, int a2) {
	int v2;    // eax
	_DWORD* i; // ecx

	if (!*(_DWORD*)(a1 + 4))
		return 0;
	v2 = 0;
	for (i = (_DWORD*)(a1 + 8); *i != a2; ++i) {
		if (++v2 >= 32)
			return 0;
	}
	return 1;
}

//----- (004C1790) --------------------------------------------------------
char*  nox_xxx_tradeClientAddItem_4C1790(int a1) {
	char* result; // eax
	int v2;       // ebp
	char* v3;     // esi
	_DWORD* v4;   // eax
	int v5;       // ecx
	int* v6;      // ebx
	_BYTE* v7;    // edi
	int v8;       // eax
	int v9;       // eax
	int v10;      // [esp+10h] [ebp+4h]

	result = *(char**)&dword_5d4594_1320964;
	if (!dword_5d4594_1320964)
		return result;
	v2 = a1;
	dword_5d4594_1320944 = 0;
	dword_5d4594_1320948 = 0;
	if (*(_BYTE*)(a1 + 2) == 1) {
		v3 = *(char**)&dword_5d4594_1320932;
		if (dword_5d4594_1320932) {
			result = (char*)sub_4C18E0(*(unsigned __int16*)(a1 + 3), *(_DWORD**)&dword_5d4594_1320932);
			if (result)
				goto LABEL_12;
			result = sub_4C1910(*(unsigned __int16*)(a1 + 3));
		} else {
			result = sub_4C1910(*(unsigned __int16*)(a1 + 3));
		}
	} else {
		v3 = *(char**)&dword_5d4594_1320936;
		if (dword_5d4594_1320936) {
			result = (char*)sub_4C18E0(*(unsigned __int16*)(a1 + 3), *(_DWORD**)&dword_5d4594_1320936);
			if (result)
				goto LABEL_12;
			result = sub_4C19C0(*(unsigned __int16*)(a1 + 3));
		} else {
			result = sub_4C19C0(*(unsigned __int16*)(a1 + 3));
		}
	}
	v3 = result;
LABEL_12:
	if (v3) {
		if (!*(_DWORD*)v3) {
			v4 = nox_new_drawable_for_thing(*(unsigned __int16*)(a1 + 3));
			*(_DWORD*)v3 = v4;
			if (v4[28] & 0x13001000) {
				v5 = -11 - a1;
				v6 = v4 + 108;
				v7 = (_BYTE*)(a1 + 11);
				v10 = -11 - a1;
				do {
					if (*v7 == -1) {
						*v6 = 0;
					} else {
						v8 = nox_xxx_modifGetDescById_413330((unsigned __int8)*v7);
						v5 = v10;
						*v6 = v8;
					}
					++v7;
					++v6;
				} while ((int)&v7[v5] < 4);
			}
			*((_DWORD*)v3 + 1) = 0;
			*((_DWORD*)v3 + 34) = 0;
		}
		*(_DWORD*)&v3[4 * *((_DWORD*)v3 + 1) + 8] = *(unsigned __int16*)(v2 + 5);
		v9 = *((_DWORD*)v3 + 34);
		++*((_DWORD*)v3 + 1);
		result = (char*)(*(_DWORD*)(v2 + 7) + v9);
		*((_DWORD*)v3 + 34) = result;
		dword_5d4594_1320932 = 0;
		dword_5d4594_1320936 = 0;
	}
	return result;
}

//----- (004C18E0) --------------------------------------------------------
int  sub_4C18E0(int a1, _DWORD* a2) {
	if (!a2[1])
		return 1;
	if (*(_DWORD*)(*a2 + 108) != a1 || *(_DWORD*)(*a2 + 112) & 0x13001000)
		return 0;
	return 1;
}

//----- (004C1910) --------------------------------------------------------
char*  sub_4C1910(int a1) {
	int v1;              // edi
	unsigned __int8* v2; // esi
	int v3;              // ecx
	unsigned __int8* v4; // edx
	int v5;              // eax
	int v6;              // esi
	unsigned __int8* v7; // edx
	int v8;              // eax
	unsigned __int8* v9; // ecx

	v1 = 0;
	v2 = getMemAt(0x5D4594, 1319284);
	while (2) {
		v3 = 0;
		v4 = v2;
		do {
			v5 = *(_DWORD*)v4;
			if (*(_DWORD*)v4 && *(_DWORD*)(v5 + 108) == a1 && !(*(_DWORD*)(v5 + 112) & 0x13001000))
				return (char*)getMemAt(0x5D4594, 1319284 + 140 * (v1 + 2 * v3));
			++v3;
			v4 += 280;
		} while (v3 < 2);
		v2 += 140;
		++v1;
		if ((int)v2 < (int)getMemAt(0x5D4594, 1319564))
			continue;
		break;
	}
	v6 = 0;
	v7 = getMemAt(0x5D4594, 1319284);
	while (2) {
		v8 = 0;
		v9 = v7;
		do {
			if (!*(_DWORD*)v9)
				return (char*)getMemAt(0x5D4594, 1319284 + 140 * (v6 + 2 * v8));
			++v8;
			v9 += 280;
		} while (v8 < 2);
		v7 += 140;
		++v6;
		if ((int)v7 < (int)getMemAt(0x5D4594, 1319564))
			continue;
		break;
	}
	return 0;
}

//----- (004C19C0) --------------------------------------------------------
char*  sub_4C19C0(int a1) {
	int v1;              // edi
	unsigned __int8* v2; // esi
	int v3;              // ecx
	unsigned __int8* v4; // edx
	int v5;              // eax
	int v6;              // esi
	unsigned __int8* v7; // edx
	int v8;              // eax
	unsigned __int8* v9; // ecx

	v1 = 0;
	v2 = getMemAt(0x5D4594, 1320308);
	while (2) {
		v3 = 0;
		v4 = v2;
		do {
			v5 = *(_DWORD*)v4;
			if (*(_DWORD*)v4 && *(_DWORD*)(v5 + 108) == a1 && !(*(_DWORD*)(v5 + 112) & 0x13001000))
				return (char*)getMemAt(0x5D4594, 1320308 + 140 * (v1 + 2 * v3));
			++v3;
			v4 += 280;
		} while (v3 < 2);
		v2 += 140;
		++v1;
		if ((int)v2 < (int)getMemAt(0x5D4594, 1320588))
			continue;
		break;
	}
	v6 = 0;
	v7 = getMemAt(0x5D4594, 1320308);
	while (2) {
		v8 = 0;
		v9 = v7;
		do {
			if (!*(_DWORD*)v9)
				return (char*)getMemAt(0x5D4594, 1320308 + 140 * (v6 + 2 * v8));
			++v8;
			v9 += 280;
		} while (v8 < 2);
		v7 += 140;
		++v6;
		if ((int)v7 < (int)getMemAt(0x5D4594, 1320588))
			continue;
		break;
	}
	return 0;
}

//----- (004C1A70) --------------------------------------------------------
char*  sub_4C1A70(int a1, int* a2) {
	_DWORD* v2;   // eax
	int v3;       // ecx
	_DWORD* v4;   // eax
	_DWORD* v5;   // edi
	char* v6;     // eax
	char* result; // eax
	char v8[4];   // [esp+0h] [ebp-14h]
	int2 a1a;     // [esp+4h] [ebp-10h]
	int v10;      // [esp+Ch] [ebp-8h]
	int v11;      // [esp+10h] [ebp-4h]

	v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3704);
	nox_client_wndGetPosition_46AA60(v2, &v10, &v11);
	v3 = v11 + 25;
	if (a2) {
		v3 = a2[1];
		a1a.field_0 = *a2;
	} else {
		a1a.field_0 = v10 + 25;
	}
	a1a.field_4 = v3;
	LOBYTE(v4) = sub_4C0910(&a1a);
	v5 = v4;
	if (sub_4C18E0(*(_DWORD*)(a1 + 108), v4)) {
		dword_5d4594_1320932 = v5;
		v6 = sub_4C1910(*(_DWORD*)(a1 + 108));
		if (v6) {
			if (*((_DWORD*)v6 + 1))
				dword_5d4594_1320932 = v6;
		}
	} else {
		result = sub_4C1910(*(_DWORD*)(a1 + 108));
		dword_5d4594_1320932 = result;
		if (!result)
			return result;
	}
	v8[0] = -55;
	v8[1] = 15;
	*(_WORD*)&v8[2] = nox_xxx_netGetUnitCodeCli_578B00(a1);
	return (char*)nox_netlist_addToMsgListCli_40EBC0(31, 0, v8, 4);
}
// 4C1ACF: variable 'v4' is possibly undefined

//----- (004C1B50) --------------------------------------------------------
int  sub_4C1B50(int a1) {
	int result; // eax

	result = dword_5d4594_1320964;
	if (dword_5d4594_1320964) {
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1320240), L"%d", *(_DWORD*)(a1 + 2));
		if (*(_DWORD*)(a1 + 6))
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1320868), L"(%d)", *(_DWORD*)(a1 + 6));
		else
			nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1320868), (const wchar_t*)getMemAt(0x5D4594, 1320984));
		result = nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1320100), L"%d", *(_DWORD*)(a1 + 10));
	}
	return result;
}

//----- (004C1BC0) --------------------------------------------------------
int  sub_4C1BC0(int a1) {
	unsigned int v1; // edx
	int result;      // eax

	result = dword_5d4594_1320964;
	if (dword_5d4594_1320964) {
		result = a1;
		dword_5d4594_1320944 = *(_BYTE*)(a1 + 2) & 1;
		LOBYTE(v1) = *(_BYTE*)(a1 + 2);
		dword_5d4594_1320948 = (v1 >> 1) & 1;
	}
	return result;
}
// 4C1BDC: variable 'v1' is possibly undefined

//----- (004C1BF0) --------------------------------------------------------
int nox_xxx_prepareP2PTrade_4C1BF0() {
	int result; // eax
	int v1;     // esi
	_DWORD* v2; // eax
	_DWORD* v3; // eax

	result = dword_5d4594_1320964;
	v1 = *getMemU32Ptr(0x8531A0, 2576);
	if (dword_5d4594_1320964) {
		if (*getMemU32Ptr(0x8531A0, 2576)) {
			sub_4C1410();
			v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3702);
			nox_window_call_field_94((int)v2, 16385, v1 + 4704, 0);
			v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3703);
			result = nox_window_call_field_94((int)v3, 16385, (int)getMemAt(0x5D4594, 1319844), 0);
		}
	}
	return result;
}

//----- (004C1C60) --------------------------------------------------------
int __fastcall sub_4C1C60(int a1, int a2) { return (unsigned __int64)(a2 * (__int64)a1) >> 16; }

//----- (004C1C80) --------------------------------------------------------
int  sub_4C1C80(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x587000, 184444) = a1;
	return result;
}

//----- (004C1C90) --------------------------------------------------------
int sub_4C1C90() { return *getMemU32Ptr(0x587000, 184444); }

//----- (004C1CA0) --------------------------------------------------------
int  sub_4C1CA0(int a1) {
	int result; // eax

	*getMemU32Ptr(0x587000, 184448) = a1;
	if (a1 == 3) {
		nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1321040, *getMemIntPtr(0x5D4594, 1321020));
		sub_46AEC0(*(int*)&dword_5d4594_1321040, *getMemIntPtr(0x5D4594, 1321016));
		result = nox_xxx_wndSetIconLit_46AEA0(*(int*)&dword_5d4594_1321040, *getMemIntPtr(0x5D4594, 1321016));
	} else if (a1 == 4) {
		nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1321040, *getMemIntPtr(0x5D4594, 1321028));
		sub_46AEC0(*(int*)&dword_5d4594_1321040, *(int*)&dword_5d4594_1321024);
		result = nox_xxx_wndSetIconLit_46AEA0(*(int*)&dword_5d4594_1321040, *(int*)&dword_5d4594_1321024);
	} else {
		result = a1 - 5;
		if (a1 == 5) {
			nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1321040, *getMemIntPtr(0x5D4594, 1321012));
			sub_46AEC0(*(int*)&dword_5d4594_1321040, *getMemIntPtr(0x5D4594, 1321008));
			result = nox_xxx_wndSetIconLit_46AEA0(*(int*)&dword_5d4594_1321040, *getMemIntPtr(0x5D4594, 1321008));
		}
	}
	return result;
}

//----- (004C1D70) --------------------------------------------------------
int sub_4C1D70() { return *getMemU32Ptr(0x587000, 184448); }

//----- (004C1FE0) --------------------------------------------------------
int  nox_xxx_guiDrawSummonBox_4C1FE0(_DWORD* a1) {
	unsigned __int8* v2; // ebx
	int v3;              // ebp
	int v4;              // eax
	int v5;              // esi
	int v6;              // eax
	int v7;              // edi
	int v8;              // ebp
	int v9;              // edi
	BOOL v10;            // edi
	int v11;             // ecx
	int v13;             // ebx
	int* v14;            // esi
	_DWORD* v15;         // eax
	int v17;             // [esp-18h] [ebp-4Ch]
	int v18;             // [esp-14h] [ebp-48h]
	char v19;            // [esp+7h] [ebp-2Dh]
	int v20;             // [esp+8h] [ebp-2Ch]
	int v21;             // [esp+Ch] [ebp-28h]
	int v22 = 0;             // [esp+10h] [ebp-24h]
	int v23 = 0;             // [esp+14h] [ebp-20h]
	int2 a1a;            // [esp+1Ch] [ebp-18h]
	int v26;             // [esp+24h] [ebp-10h]
	int v27;             // [esp+28h] [ebp-Ch]
	int v28;             // [esp+2Ch] [ebp-8h]
	int v29;             // [esp+30h] [ebp-4h]

	nox_point mpos = nox_client_getMousePos_4309F0();
	nox_point v24 = mpos;
	if (getMemByte(0x5D4594, 1321200) == 1) {
		dword_5d4594_1320992 += 20;
		if (dword_5d4594_1320992 >= *getMemIntPtr(0x5D4594, 1321004)) {
			dword_5d4594_1320992 = *getMemU32Ptr(0x5D4594, 1321004);
			*getMemU8Ptr(0x5D4594, 1321200) = 2;
		}
	} else if (getMemByte(0x5D4594, 1321200) == 3) {
		dword_5d4594_1320992 -= 20;
		if (dword_5d4594_1320992 <= *getMemIntPtr(0x5D4594, 1321000)) {
			dword_5d4594_1320992 = *getMemU32Ptr(0x5D4594, 1321000);
			*getMemU8Ptr(0x5D4594, 1321200) = 0;
			nox_window_set_hidden(*(int*)&dword_5d4594_1321032, 1);
			nox_window_set_hidden(*(int*)&dword_5d4594_1321040, 1);
		}
	}
	nox_window_setPos_46A9B0(*(_DWORD**)&dword_5d4594_1321032, *(int*)&dword_5d4594_1320988, *(int*)&dword_5d4594_1320992);
	nox_window_setPos_46A9B0(*(_DWORD**)&dword_5d4594_1321040, dword_5d4594_1320988 + 27, dword_5d4594_1320992 + 12);
	nox_client_wndGetPosition_46AA60(a1, &v28, &v29);
	nox_window_get_size((int)a1, &v21, &v20);
	nox_xxx_guiFontHeightMB_43F320(0);
	if (*getMemU32Ptr(0x5D4594, 1320996))
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1320996), *(int*)&dword_5d4594_1320988,
									  *(int*)&dword_5d4594_1320992);
	v2 = getMemAt(0x5D4594, 1321064);
	do {
		if (*((_DWORD*)v2 - 1)) {
			switch (v2[8]) {
			case 1u:
				v22 = 1;
				v23 = 1;
				break;
			case 2u:
				v22 = 1;
				v23 = 2;
				break;
			case 4u:
				v22 = 2;
				v23 = 2;
				break;
			}
			v3 = v28 + 38 * *(_DWORD*)v2 + 2;
			v4 = *((_DWORD*)v2 + 1);
			a1a.field_0 = v28 + 38 * *(_DWORD*)v2 + 2;
			v5 = v29 + 38 * v4 + 2;
			v21 = 38 * v22 - 4;
			v20 = 38 * v23 - 4;
			if (*((_DWORD*)v2 + 4)) {
				nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2589772));
				v18 = v20;
				v17 = v21;
				*((_DWORD*)v2 + 4) = 0;
				nox_client_drawRectFilledOpaque_49CE30(v3, v5, v17, v18);
			} else {
				v6 = nox_xxx_guiDrawSummon_4C2440(*((_DWORD*)v2 - 2));
				if (v6) {
					nox_client_drawImageAt_47D2C0(v6, v3, v5);
				} else {
					v7 = v3 + v21 / 2;
					v8 = v5 + v20 / 2;
					nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 956));
					sub_4B0BC0(v7, v8, 9);
					nox_video_drawCircleColored_4C3270(v7, v8, 9, *getMemIntPtr(0x852978, 4));
					v3 = a1a.field_0;
				}
			}
			if (sub_495180(*((_DWORD*)v2 - 3), &v27, &v26, &v19)) {
				if ((_WORD)v26)
					v9 = v20 * (unsigned __int16)v27 / (unsigned __int16)v26;
				else
					v9 = 0;
				if (v19)
					nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 984));
				else
					nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2598268));
				nox_client_drawRectFilledOpaque_49CE30(v21 + v3 - 2, v5, 2, v20);
				if (v19)
					nox_client_drawSetColor_434460(*getMemIntPtr(0x8531A0, 2572));
				else
					nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 940));
				nox_client_drawRectFilledOpaque_49CE30(v21 + v3 - 2, v20 + v5 - v9, 2, v9);
			}
			mpos = v24;
		}
		v2 += 32;
	} while ((int)v2 < (int)getMemAt(0x5D4594, 1321192));
	v10 = nox_xxx_wndPointInWnd_46AAB0(*(_DWORD**)&dword_5d4594_1321040, mpos.x, mpos.y);
	if (nox_xxx_wndPointInWnd_46AAB0(a1, mpos.x, mpos.y) || v10 || *getMemU32Ptr(0x5D4594, 1321212) == 1) {
		v11 = mpos.y;
		a1a.field_0 = (mpos.x - v28) / 38;
		a1a.field_4 = (v11 - v29) / 38;
		v13 = nox_xxx_wndSummonGet_4C2410(&a1a);
		*getMemU32Ptr(0x5D4594, 1321212) = 0;
		v14 = (int*)sub_4C2D60();
		if (v14) {
			do {
				v15 = nox_xxx_netSpriteByCodeDynamic_45A6F0(*v14);
				if (v15) {
					if (v14 == (int*)v13 || v10) {
						v15[30] |= 0x40000000u;
						*getMemU32Ptr(0x5D4594, 1321212) = 1;
					} else {
						v15[30] &= 0xBFFFFFFF;
					}
				}
				v14 = (int*)sub_4C2D90((int)v14);
			} while (v14);
			mpos = v24;
		}
	}
	if (dword_5d4594_1321044 && !nox_xxx_wndPointInWnd_46AAB0(*(_DWORD**)&dword_5d4594_1321044, mpos.x, mpos.y))
		nox_xxx_guiHideSummonWindow_4C2470();
	return 1;
}

//----- (004C2410) --------------------------------------------------------
int  nox_xxx_wndSummonGet_4C2410(int2* a1) {
	int result; // eax
	int v2;     // edx
	int v3;     // ecx

	result = 0;
	if (a1) {
		v2 = a1->field_0;
		if (a1->field_0 >= 0 && v2 < 2) {
			v3 = a1->field_4;
			if (v3 >= 0 && v3 < 2)
				result = *getMemU32Ptr(0x5D4594, 1321180 + 4 * (v3 + 2 * v2));
		}
	}
	return result;
}

//----- (004C2440) --------------------------------------------------------
int  nox_xxx_guiDrawSummon_4C2440(int a1) {
	const char* v1; // eax
	int v2;         // eax

	v1 = (const char*)nox_get_thing_name(a1);
	if (!v1)
		return 0;
	v2 = nox_xxx_guide_427010(v1);
	return sub_427430(v2);
}

//----- (004C2470) --------------------------------------------------------
int nox_xxx_guiHideSummonWindow_4C2470() {
	int result; // eax

	nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1321044);
	dword_5d4594_1321044 = 0;
	dword_5d4594_1321204 = 0;
	nox_xxx_clientPlaySoundSpecial_452D80(920, 100);
	result = dword_5d4594_1321040;
	*(_DWORD*)(dword_5d4594_1321040 + 36) &= 0xFFFFFFFD;
	return result;
}

//----- (004C24A0) --------------------------------------------------------
int sub_4C24A0() { return 1; }

//----- (004C24B0) --------------------------------------------------------
int  nox_xxx_wndSummonBigButtonProc_4C24B0(int a1, int a2, unsigned int a3) {
	int2 a1a; // [esp+0h] [ebp-8h]

	switch (a2) {
	case 5:
	case 6:
		return 1;
	case 7:
		dword_5d4594_1321204 = 0;
		a1a.field_4 = a3 >> 16;
		a1a.field_0 = (unsigned __int16)a3;
		nox_xxx_wndSummonCreateList_4C2560(&a1a);
		*(_DWORD*)(dword_5d4594_1321040 + 36) |= 2u;
		return 1;
	case 17:
		*(_DWORD*)(dword_5d4594_1321040 + 36) |= 2u;
		return 0;
	case 18:
		*(_DWORD*)(dword_5d4594_1321040 + 36) &= 0xFFFFFFFD;
		return 0;
	default:
		return 0;
	}
}

//----- (004C26F0) --------------------------------------------------------
int  sub_4C26F0(int yTop) {
	int v1;     // esi
	int result; // eax
	int xLeft;  // [esp+4h] [ebp-Ch]
	int v4;     // [esp+8h] [ebp-8h]
	int v5;     // [esp+Ch] [ebp-4h]

	v1 = yTop;
	nox_client_wndGetPosition_46AA60((_DWORD*)yTop, &xLeft, &yTop);
	nox_window_get_size(v1, &v4, &v5);
	nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, v4, v5);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 944));
	nox_client_drawAddPoint_49F500(xLeft + 1, yTop);
	nox_xxx_rasterPointRel_49F570(v4 - 2, 0);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(xLeft + 1, yTop + v5);
	nox_xxx_rasterPointRel_49F570(v4 - 2, 0);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(xLeft, yTop + 1);
	nox_xxx_rasterPointRel_49F570(0, v5 - 2);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(xLeft + v4, yTop + 1);
	nox_xxx_rasterPointRel_49F570(0, v5 - 2);
	nox_client_drawLineFromPoints_49E4B0();
	result = 1;
	dword_5d4594_3799524 = 1;
	return result;
}

//----- (004C2A00) --------------------------------------------------------
int  sub_4C2A00(int a1, int a2, int a3, int a4, __int16* a5) {
	unsigned __int8* v5; // esi

	nox_xxx_drawSetTextColor_434390(a4);
	v5 = getMemAt(0x587000, 184520);
	do {
		nox_xxx_drawString_43F6E0(0, a5, a1 + *(_DWORD*)v5, a2 + *((_DWORD*)v5 + 1));
		v5 += 8;
	} while ((int)v5 < (int)getMemAt(0x587000, 184552));
	nox_xxx_drawSetTextColor_434390(a3);
	return nox_xxx_drawString_43F6E0(0, a5, a1, a2);
}

void nox_client_orderCreature(int creature, int command) {
	unsigned char buf[4] = {0};
	buf[0] = 0x78;
	if (creature) {
		*(_WORD*)(&buf[1]) = *(_WORD*)creature;
	} else {
		if (command == 1)
			return;
		*(_WORD*)(&buf[1]) = 0;
	}
	buf[3] = command;
	nox_netlist_addToMsgListCli_40EBC0(31, 0, buf, 4);
	nox_xxx_guiHideSummonWindow_4C2470();
	if (!command) {
		nox_xxx_clientPlaySoundSpecial_452D80(777, 100);
	} else {
		nox_xxx_clientPlaySoundSpecial_452D80(898, 100);
	}
}

//----- (004C2A60) --------------------------------------------------------
int  nox_xxx_clientOrderCreature_4C2A60(int a1, unsigned int a2) {
	int result; // eax

	if (a2 >= 5) {
		if (a2 <= 6)
			return 1;
		if (a2 == 7) {
			LOBYTE(a2) = 120;
			result = *(_DWORD*)(a1 + 32);
			if (result == 2 || (!dword_5d4594_1321204 && result == 1))
				return 1;
			nox_client_orderCreature(dword_5d4594_1321204, *(_DWORD*)(a1 + 32));
			return 1;
		}
	}
	return 0;
}

//----- (004C2B10) --------------------------------------------------------
int  nox_xxx_wndSummonProc_4C2B10(_DWORD* a1, unsigned int a2, unsigned int a3) {
	int2 v5;  // [esp+0h] [ebp-10h]
	int2 a1a; // [esp+8h] [ebp-8h]

	if (a2 >= 5) {
		if (a2 <= 6)
			return 1;
		if (a2 == 7) {
			v5.field_4 = a3 >> 16;
			v5.field_0 = (unsigned __int16)a3;
			nox_client_wndGetPosition_46AA60(a1, &a2, &a3);
			a1a.field_0 = (v5.field_0 - (int)a2) / 38;
			a1a.field_4 = (v5.field_4 - (int)a3) / 38;
			dword_5d4594_1321204 = nox_xxx_wndSummonGet_4C2410(&a1a);
			if (dword_5d4594_1321204)
				nox_xxx_wndSummonCreateList_4C2560(&v5);
			return 1;
		}
	}
	return 0;
}

//----- (004C2BD0) --------------------------------------------------------
int sub_4C2BD0() { return 0; }

//----- (004C2BE0) --------------------------------------------------------
int sub_4C2BE0() { return 1; }

//----- (004C2BF0) --------------------------------------------------------
int* sub_4C2BF0() {
	int* v0;     // edx
	int* result; // eax
	int v2;      // ecx

	v0 = getMemIntPtr(0x5D4594, 1321180);
	do {
		result = v0;
		v2 = 2;
		do {
			*result = 0;
			result += 2;
			--v2;
		} while (v2);
		++v0;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 1321188));
	return result;
}

//----- (004C2C20) --------------------------------------------------------
int  sub_4C2C20(_DWORD* a1, int a2, unsigned int a3) {
	wchar_t* v3; // eax
	int2 a2a;    // [esp+0h] [ebp-8h]

	a2a.field_4 = a3 >> 16;
	a2a.field_0 = (unsigned __int16)a3;
	v3 = (wchar_t*)sub_4C2C60(a1, &a2a);
	nox_xxx_cursorSetTooltip_4776B0(v3);
	return 1;
}

//----- (004C2C60) --------------------------------------------------------
int  sub_4C2C60(_DWORD* a1, int2* a2) {
	int v4;     // eax
	int result; // eax
	int v6;     // [esp+4h] [ebp-Ch]
	int2 a1a;   // [esp+8h] [ebp-8h]

	nox_client_wndGetPosition_46AA60(a1, &a1, &v6);
	a1a.field_0 = (a2->field_0 - (int)a1) / 38;
	a1a.field_4 = (a2->field_4 - (int)v6) / 38;
	v4 = nox_xxx_wndSummonGet_4C2410(&a1a);
	if (v4)
		result = nox_get_thing_pretty_name(*(_DWORD*)(v4 + 4));
	else
		result = 0;
	return result;
}

//----- (004C2D60) --------------------------------------------------------
char* sub_4C2D60() {
	int v0;              // eax
	unsigned __int8* v1; // ecx

	v0 = 0;
	v1 = getMemAt(0x5D4594, 1321060);
	while (!*(_DWORD*)v1) {
		v1 += 32;
		++v0;
		if ((int)v1 >= (int)getMemAt(0x5D4594, 1321188))
			return 0;
	}
	return (char*)getMemAt(0x5D4594, 1321052 + 32 * v0);
}

//----- (004C2D90) --------------------------------------------------------
char*  sub_4C2D90(int a1) {
	int v1;              // eax
	unsigned __int8* v2; // ecx

	v1 = *(_DWORD*)(a1 + 24) + 1;
	if (v1 >= 4)
		return 0;
	v2 = getMemAt(0x5D4594, 1321060 + 32 * v1);
	while (!*(_DWORD*)v2) {
		v2 += 32;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 1321188))
			return 0;
	}
	return (char*)getMemAt(0x5D4594, 1321052 + 32 * v1);
}

//----- (004C2DD0) --------------------------------------------------------
BOOL  sub_4C2DD0(int a1) {
	int v1; // eax

	v1 = dword_5d4594_1321208;
	if (!dword_5d4594_1321208) {
		v1 = nox_xxx_getNameId_4E3AA0("CarnivorousPlant");
		dword_5d4594_1321208 = v1;
	}
	return *(_DWORD*)(a1 + 4) != v1;
}

//----- (004C2E00) --------------------------------------------------------
int sub_4C2E00() {
	char* v0; // esi

	if (!dword_5d4594_1321208)
		dword_5d4594_1321208 = nox_xxx_getNameId_4E3AA0("CarnivorousPlant");
	v0 = sub_4C2D60();
	if (!v0)
		return 0;
	while (!sub_4C2DD0((int)v0)) {
		v0 = sub_4C2D90((int)v0);
		if (!v0)
			return 0;
	}
	return 1;
}

//----- (004C2E50) --------------------------------------------------------
char  nox_xxx_cliSummonCreat_4C2E50(int a1, int a2, int a3) {
	char* v3; // eax

	v3 = sub_4C2D60();
	if (v3) {
		while (*(_DWORD*)v3 != a1 || *((_DWORD*)v3 + 1) != a2) {
			v3 = sub_4C2D90((int)v3);
			if (!v3)
				goto LABEL_5;
		}
	} else {
	LABEL_5:
		v3 = sub_4C2F20();
		if (v3) {
			*(_DWORD*)v3 = a1;
			*((_DWORD*)v3 + 1) = a2;
			v3[20] = sub_4C2EF0(a2);
			sub_4C2F70();
			LOBYTE(v3) = getMemByte(0x5D4594, 1321200);
			if (!getMemByte(0x5D4594, 1321200) || getMemByte(0x5D4594, 1321200) == 3) {
				if (!a3)
					nox_xxx_clientPlaySoundSpecial_452D80(801, 100);
				*getMemU8Ptr(0x5D4594, 1321200) = 1;
				nox_window_set_hidden(*(int*)&dword_5d4594_1321032, 0);
				LOBYTE(v3) = nox_window_set_hidden(*(int*)&dword_5d4594_1321040, 0);
			}
			++dword_5d4594_1321196;
		}
	}
	return (char)v3;
}

//----- (004C2EF0) --------------------------------------------------------
int  sub_4C2EF0(int a1) {
	int v1; // eax
	int v3; // eax

	v1 = nox_get_thing(a1)->sub_class;
	if (v1 & 1)
		return 1;
	v3 = -((v1 & 2) != 0);
	LOBYTE(v3) = v3 & 0xFE;
	return v3 + 4;
}

//----- (004C2F20) --------------------------------------------------------
char* sub_4C2F20() {
	int v0;              // esi
	unsigned __int8* v1; // eax
	char* result;        // eax

	v0 = 0;
	v1 = getMemAt(0x5D4594, 1321060);
	while (*(_DWORD*)v1) {
		v1 += 32;
		++v0;
		if ((int)v1 >= (int)getMemAt(0x5D4594, 1321188))
			return 0;
	}
	memset(getMemAt(0x5D4594, 1321052 + 32 * v0), 0, 0x20u);
	*getMemU32Ptr(0x5D4594, 1321060 + 32 * v0) = 1;
	result = (char*)getMemAt(0x5D4594, 1321052 + 32 * v0);
	*getMemU32Ptr(0x5D4594, 1321076 + 32 * v0) = v0;
	return result;
}

//----- (004C2F70) --------------------------------------------------------
char* sub_4C2F70() {
	int i;        // edi
	char* result; // eax
	char* j;      // esi

	sub_4C2BF0();
	for (i = 1;; i = 4) {
		while (1) {
			result = sub_4C2D60();
			for (j = result; result; j = result) {
				if ((unsigned __int8)j[20] == i)
					sub_4C2FD0((int)j);
				result = sub_4C2D90((int)j);
			}
			if (i != 1)
				break;
			i = 2;
		}
		if (i != 2)
			break;
	}
	return result;
}

//----- (004C2FD0) --------------------------------------------------------
int  sub_4C2FD0(int a1) {
	int v1;     // esi
	int* v2;    // edi
	int v3;     // edx
	int result; // eax

	v1 = 0;
	v2 = (int*)(a1 + 12);
	while (1) {
		v3 = *(unsigned __int8*)(a1 + 20);
		*v2 = *getMemU32Ptr(0x587000, 184456 + 8 * v1);
		*(_DWORD*)(a1 + 16) = *getMemU32Ptr(0x587000, 184460 + 8 * v1);
		if (sub_4C30C0(v2, v3))
			break;
		result = *(unsigned __int8*)(a1 + 20);
		v1 += result;
		if (v1 >= 4)
			return result;
	}
	return sub_4C3030((int*)(a1 + 12), *(unsigned __int8*)(a1 + 20), a1);
}

//----- (004C3030) --------------------------------------------------------
int  sub_4C3030(int* a1, int a2, int a3) {
	int v3;              // esi
	int result;          // eax
	int v5;              // ebx
	int v6;              // eax
	unsigned __int8* v7; // ecx

	if (a2 == 1) {
		v3 = 1;
		a2 = 1;
	} else if (a2 == 2) {
		v3 = 1;
		a2 = 2;
	} else {
		v3 = 2;
		if (a2 == 4)
			a2 = 2;
		else
			v3 = a2;
	}
	result = a2;
	v5 = a1[1];
	if (v5 < v5 + a2) {
		do {
			v6 = *a1;
			if (*a1 < *a1 + v3) {
				v7 = getMemAt(0x5D4594, 1321180 + 4 * (v5 + 2 * v6));
				do {
					*(_DWORD*)v7 = a3;
					++v6;
					v7 += 8;
				} while (v6 < v3 + *a1);
			}
			++v5;
			result = a1[1] + a2;
		} while (v5 < result);
	}
	return result;
}

//----- (004C30C0) --------------------------------------------------------
int  sub_4C30C0(int* a1, int a2) {
	int v2;              // ecx
	int v3;              // eax
	int v4;              // esi
	int v5;              // ebx
	int v6;              // edi
	int v7;              // edx
	int v8;              // eax
	unsigned __int8* v9; // ecx

	switch (a2) {
	case 1:
		v2 = 1;
		v3 = 1;
		break;
	case 2:
		v2 = 1;
		v3 = 2;
		break;
	case 4:
		v2 = 2;
		v3 = 2;
		break;
	default:
		v2 = a2;
		v3 = a2;
		break;
	}
	v4 = a1[1];
	v5 = v4 + v3;
	if (v4 >= v4 + v3)
		return 1;
	v6 = *a1;
	v7 = *a1 + v2;
	while (1) {
		v8 = *a1;
		if (v6 < v7)
			break;
	LABEL_14:
		if (++v4 >= v5)
			return 1;
	}
	v9 = getMemAt(0x5D4594, 1321180 + 4 * (v4 + 2 * v6));
	while (!*(_DWORD*)v9) {
		++v8;
		v9 += 8;
		if (v8 >= v7)
			goto LABEL_14;
	}
	return 0;
}

//----- (004C3140) --------------------------------------------------------
void nox_xxx_cliSummonOnDieOrBanish_4C3140(int a1, void* a2) {
	int* result; // eax
	int* v3;     // esi
	_DWORD* v4;  // eax

	result = (int*)sub_4C31D0(a1);
	v3 = result;
	if (!result) {
		return;
	}
	if (result == *(int**)&dword_5d4594_1321204)
		nox_xxx_guiHideSummonWindow_4C2470();
	v4 = nox_xxx_netSpriteByCodeDynamic_45A6F0(a1);
	if (v4)
		v4[30] &= 0xBFFFFFFF;
	sub_4C3030(v3 + 3, *((unsigned __int8*)v3 + 20), 0);
	sub_4C3210((int)v3);
	sub_4C2F70();
	--dword_5d4594_1321196;
	if (!dword_5d4594_1321196) {
		if (!a2)
			nox_xxx_clientPlaySoundSpecial_452D80(802, 100);
		*getMemU8Ptr(0x5D4594, 1321200) = 3;
	}
}

//----- (004C31D0) --------------------------------------------------------
char*  sub_4C31D0(int a1) {
	int v1;              // eax
	unsigned __int8* v2; // ecx

	v1 = 0;
	v2 = getMemAt(0x5D4594, 1321052);
	while (!*((_DWORD*)v2 + 2) || *(_DWORD*)v2 != a1) {
		v2 += 32;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 1321180))
			return 0;
	}
	return (char*)getMemAt(0x5D4594, 1321052 + 32 * v1);
}

//----- (004C3210) --------------------------------------------------------
int  sub_4C3210(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 8) = 0;
	return result;
}

//----- (004C3220) --------------------------------------------------------
BOOL  nox_xxx_sprite_4C3220(nox_drawable* a1) { return sub_4C31D0(*(_DWORD*)((_DWORD)a1 + 128)) != 0; }

//----- (004C3240) --------------------------------------------------------
BOOL  sub_4C3240(int a1) { return sub_4C31D0(a1) != 0; }

//----- (004C3260) --------------------------------------------------------
BOOL sub_4C3260() { return sub_4C2D60() != 0; }

#ifndef NOX_CGO
//----- (004C3270) --------------------------------------------------------
void nox_video_drawCircleColored_4C3270(int a1, int a2, int a3, int a4) {
	nox_client_drawSetColor_434460(a4);
	nox_video_drawCircle_4B0B90(a1, a2, a3);
}
#endif // NOX_CGO

//----- (004C32A0) --------------------------------------------------------
int  nox_xxx_spriteDrawCircleMB_4C32A0(int a1, int a2, int a3, int a4) {
	unsigned __int8* v4; // ebx
	int v5;              // esi
	int v6;              // edi
	int v8;              // [esp+10h] [ebp-8h]
	int v9;              // [esp+14h] [ebp-4h]

	v8 = (a3 * *getMemU32Ptr(0x587000, 192088)) >> 4;
	v9 = (a3 * *getMemU32Ptr(0x587000, 192092)) >> 4;
	nox_client_drawSetColor_434460(a4);
	nox_client_drawEnableAlpha_434560(1);
	v4 = getMemAt(0x587000, 192220);
	do {
		v5 = (a3 * *((_DWORD*)v4 - 1)) >> 4;
		v6 = (*(_DWORD*)v4 * a3) >> 4;
		nox_client_drawAddPoint_49F500(a1 + v8, a2 + v9);
		nox_client_drawAddPoint_49F500(v5 + a1, v6 + a2);
		nox_client_drawLineFromPoints_49E4B0();
		v4 += 128;
		v8 = v5;
		v9 = v6;
	} while ((int)v4 < (int)getMemAt(0x587000, 194140));
	nox_client_drawAddPoint_49F500(a1 + ((a3 * *getMemU32Ptr(0x587000, 192088)) >> 4),
								   a2 + ((a3 * *getMemU32Ptr(0x587000, 192092)) >> 4));
	nox_client_drawAddPoint_49F500(a1 + v5, a2 + v6);
	nox_client_drawLineFromPoints_49E4B0();
	return nox_client_drawEnableAlpha_434560(0);
}

//----- (004C3390) --------------------------------------------------------
int sub_4C3390() {
	*getMemU32Ptr(0x5D4594, 1321220) = nox_xxx_gLoadImg_42F970("VoteInProgress");
	dword_5d4594_1321216 = nox_window_new(0, 136, nox_win_width - 50, nox_win_height / 2 - 100, 50, 50, 0);
	nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1321216, *getMemIntPtr(0x5D4594, 1321220));
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1321216, 0, sub_4C3410, 0);
	nox_window_set_hidden(*(int*)&dword_5d4594_1321216, 1);
	return 1;
}

//----- (004C3410) --------------------------------------------------------
int  sub_4C3410(int* a1) {
	int* v1; // esi
	int v2;  // edx
	int v4;  // [esp+4h] [ebp-4h]

	v1 = a1;
	nox_client_wndGetPosition_46AA60(a1, &a1, &v4);
	v2 = v1[25];
	a1 = (int*)((char*)a1 + v1[24]);
	nox_client_drawImageAt_47D2C0(v1[15], (int)a1, v2 + v4);
	return 1;
}

//----- (004C3460) --------------------------------------------------------
int  sub_4C3460(int a1) { return nox_window_set_hidden(*(int*)&dword_5d4594_1321216, a1); }

//----- (004C3480) --------------------------------------------------------
BOOL sub_4C3480() { return dword_5d4594_1321216 && !wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1321216); }

//----- (004C34A0) --------------------------------------------------------
int sub_4C34A0() {
	int result; // eax

	result = nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1321216);
	dword_5d4594_1321216 = 0;
	return result;
}

//----- (004C34C0) --------------------------------------------------------
void  sub_4C34C0(int a1) {
	_DWORD* v1; // eax

	if (dword_5d4594_1321224) {
		if (a1) {
			v1 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1321224, 8901);
			nox_window_call_field_94((int)v1, 16385, a1, 0);
		}
	}
}

//----- (004C3500) --------------------------------------------------------
int sub_4C3500() {
	_DWORD* v0; // ecx

	v0 = nox_new_window_from_file("yesno.wnd", 0);
	dword_5d4594_1321224 = v0;
	if (v0) {
		nox_window_setPos_46A9B0(v0, (nox_win_width - 320) / 2, (nox_win_height - 240) / 2);
		v0 = *(_DWORD**)&dword_5d4594_1321224;
	}
	nox_window_set_hidden((int)v0, 1);
	return dword_5d4594_1321224;
}

//----- (004C3560) --------------------------------------------------------
int sub_4C3560() {
	nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1321224);
	return dword_5d4594_1321224;
}

//----- (004C3580) --------------------------------------------------------
int sub_4C3580() { return nox_window_set_hidden(*(int*)&dword_5d4594_1321224, 1); }

//----- (004C35B0) --------------------------------------------------------
int  sub_4C35B0(int a1) {
	if (wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1321228))
		return 0;
	sub_413A00(0);
	if (a1) {
		nox_window_set_hidden(*(int*)&dword_5d4594_1321228, 1);
	} else {
		sub_4C3620();
		nox_common_writecfgfile("nox.cfg");
		nox_window_set_hidden(*(int*)&dword_5d4594_1321228, 1);
		sub_472280();
		sub_4ADA40();
	}
	return 1;
}

//----- (004C3A60) --------------------------------------------------------
int  sub_4C3A60(_DWORD* a1, unsigned int a2, unsigned int a3, int a4) {
	int result; // eax

	if (a2 < 0x13 || a2 > 0x14)
		result = nox_xxx_wndListboxProcWithoutData10_4A28E0(a1, a2, a3, a4);
	else
		result = 0;
	return result;
}

//----- (004C3A90) --------------------------------------------------------
int  sub_4C3A90(int a1, int a2, int* a3, int a4) {
	int v3;     // esi
	int result; // eax

	if (a2 == 23)
		return 1;
	if (a2 != 16391)
		return 0;
	v3 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
	switch (v3) {
	case 931:
		sub_42CD90();
		nox_common_readcfgfile("nox.cfg", 1);
		sub_4C3B70();
		result = 0;
		break;
	case 932:
		sub_4C35B0(0);
		result = 0;
		break;
	case 933:
		sub_4C3CB0();
		result = 0;
		break;
	case 971:
	case 972:
	case 973:
		sub_430AA0(v3 - 971);
		return 0;
	default:
		return 0;
	}
	return result;
}

//----- (004C3B70) --------------------------------------------------------
#ifndef NOX_CGO
void sub_4C3B70() {
	nox_window_call_field_94(*(int*)&dword_5d4594_1321236, 16399, 0, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1321240, 16399, 0, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1321244, 16399, 0, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1321248, 16399, 0, 0);
	for (int i = 1; i < NOX_BINDEVENT_MAX; i++) {
		nox_bindevent_t* ev = &nox_bindevent_arr[i];
		if (ev->key == 44) {
			continue;
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_1321240, 16397, ev->title, -1);
		nox_window_call_field_94(*(int*)&dword_5d4594_1321236, 16397, (int)getMemAt(0x587000, 185340), -1);
		char* v2 = sub_42E8E0(ev->key, 1);
		char* v3 = sub_42E8E0(ev->key, 2);
		if (v2 && *(_WORD*)v2) {
			nox_window_call_field_94(*(int*)&dword_5d4594_1321244, 16397, (int)v2, -1);
		} else {
			nox_window_call_field_94(*(int*)&dword_5d4594_1321244, 16397, (int)getMemAt(0x587000, 185344), -1);
		}
		if (v3 && *(_WORD*)v3 && v2 != v3) {
			nox_window_call_field_94(*(int*)&dword_5d4594_1321248, 16397, (int)v3, -1);
		} else {
			nox_window_call_field_94(*(int*)&dword_5d4594_1321248, 16397, (int)getMemAt(0x587000, 185348), -1);
		}
	}
}

//----- (004C3CB0) --------------------------------------------------------
void sub_4C3CB0() {
	sub_42CD90();
	nox_common_readcfgfile("default.cfg", 1);
	sub_4C3B70();
}
#endif // NOX_CGO

//----- (004C3EB0) --------------------------------------------------------
int  sub_4C3EB0(int a1, int a2, unsigned int a3, int a4) {
	int result; // eax

	switch (a2) {
	case 6:
	case 7:
		goto LABEL_10;
	case 10:
	case 11:
		sub_4C4100(0x10002);
		goto LABEL_15;
	case 14:
	case 15:
		sub_4C4100(0x10001);
		goto LABEL_15;
	case 19:
		sub_4C4100(0x10003);
		goto LABEL_15;
	case 20:
		sub_4C4100(0x10004);
		goto LABEL_15;
	case 21:
		if (a3 == 1) {
			if (a4 == 2) {
				nox_xxx_windowFocus_46B500(0);
				nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_1321232);
				nox_window_set_hidden(*(int*)&dword_5d4594_1321232, 1);
				if (dword_5d4594_1321252)
					nox_window_call_field_94(*(int*)&dword_5d4594_1321252, 16403, -1, 0);
			}
			result = 1;
		} else if (a4 == 1 && sub_4C3FC0(a3)) {
		LABEL_10:
			sub_4C4100(0x10000);
		LABEL_15:
			nox_xxx_windowFocus_46B500(0);
			nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_1321232);
			nox_window_set_hidden(*(int*)&dword_5d4594_1321232, 1);
			result = 1;
		} else {
		LABEL_5:
			result = 0;
		}
		return result;
	default:
		goto LABEL_5;
	}
}

//----- (004C3FC0) --------------------------------------------------------
int  sub_4C3FC0(unsigned int a1) {
	const wchar_t* v6 = nox_xxx_keybind_titleByKeyZero_42EA00(a1);
	if (!v6) {
		return 0;
	}
	if (!dword_5d4594_1321252) {
		return 1;
	}
	int v7 = 0;
	int v8 = *(_DWORD*)((_DWORD)dword_5d4594_1321244 + 32);
	if (*(_WORD*)(v8 + 44) > 0) {
		do {
			const wchar_t* v9 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1321244, 16406, v7, 0);
			if (!nox_wcscmp(v9, v6))
				nox_window_call_field_94(*(int*)&dword_5d4594_1321244, 16407, (int)getMemAt(0x587000, 185444), v7);
			++v7;
		} while (v7 < *(__int16*)(v8 + 44));
	}
	int v10 = 0;
	int v11 = *(_DWORD*)((_DWORD)dword_5d4594_1321248 + 32);
	if (*(_WORD*)(v11 + 44) > 0) {
		do {
			const wchar_t*  v12 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1321248, 16406, v10, 0);
			if (!nox_wcscmp(v12, v6))
				nox_window_call_field_94(*(int*)&dword_5d4594_1321248, 16407, (int)getMemAt(0x587000, 185448), v10);
			++v10;
		} while (v10 < *(__int16*)(v11 + 44));
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_1321252, 16407, (int)v6, *(_DWORD*)(*(_DWORD*)(dword_5d4594_1321252 + 32) + 48));
	nox_window_call_field_94(*(int*)&dword_5d4594_1321252, 16403, -1, 0);
	dword_5d4594_1321252 = 0;
	return 1;
}

//----- (004C4100) --------------------------------------------------------
int  sub_4C4100(unsigned int a1) {
	char* v1;          // edi
	int v2;            // esi
	int v3;            // ebx
	const wchar_t* v4; // eax
	int v5;            // esi
	int v6;            // ebx
	const wchar_t* v7; // eax

	v1 = nox_xxx_keybind_titleByKey_42EA00(a1);
	if (!dword_5d4594_1321252)
		return 1;
	v2 = 0;
	v3 = *(_DWORD*)((_DWORD)dword_5d4594_1321244 + 32);
	if (*(_WORD*)(v3 + 44) > 0) {
		do {
			v4 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1321244, 16406, v2, 0);
			if (!nox_wcscmp(v4, (const wchar_t*)v1))
				nox_window_call_field_94(*(int*)&dword_5d4594_1321244, 16407, (int)getMemAt(0x587000, 185452), v2);
			++v2;
		} while (v2 < *(__int16*)(v3 + 44));
	}
	v5 = 0;
	v6 = *(_DWORD*)((_DWORD)dword_5d4594_1321248 + 32);
	if (*(_WORD*)(v6 + 44) > 0) {
		do {
			v7 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1321248, 16406, v5, 0);
			if (!nox_wcscmp(v7, (const wchar_t*)v1))
				nox_window_call_field_94(*(int*)&dword_5d4594_1321248, 16407, (int)getMemAt(0x587000, 185456), v5);
			++v5;
		} while (v5 < *(__int16*)(v6 + 44));
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_1321252, 16407, (int)v1,
							 *(_DWORD*)(*(_DWORD*)(dword_5d4594_1321252 + 32) + 48));
	nox_window_call_field_94(*(int*)&dword_5d4594_1321252, 16403, -1, 0);
	dword_5d4594_1321252 = 0;
	return 1;
}

//----- (004C4220) --------------------------------------------------------
int sub_4C4220() {
	int result; // eax

	nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1321228);
	nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1321232);
	result = 0;
	dword_5d4594_1321228 = 0;
	dword_5d4594_1321232 = 0;
	dword_5d4594_1321236 = 0;
	dword_5d4594_1321240 = 0;
	dword_5d4594_1321244 = 0;
	dword_5d4594_1321248 = 0;
	return result;
}

//----- (004C4260) --------------------------------------------------------
void sub_4C4260() {
	sub_4C3B70();
	nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1321228);
	sub_413A00(1);
}

//----- (004C4280) --------------------------------------------------------
BOOL sub_4C4280() { return wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1321228) == 0; }

//----- (004C42A0) --------------------------------------------------------
int  sub_4C42A0(int2* a1, int2* a2, int* a3, int* a4) {
	int v4;               // ecx
	int v5;               // eax
	int result;           // eax
	double v7;            // st7
	double v8;            // st7
	int v9;               // esi
	int v10;              // edx
	int* v11;             // ecx
	int v12;              // ebx
	int v13;              // edi
	double v14;           // st7
	int v15;              // esi
	int v16;              // edi
	double v17;           // st7
	int v18;              // ebp
	int v19;              // eax
	int v20;              // eax
	int v21;              // eax
	double v22;           // st7
	int v23;              // edi
	int v24;              // edx
	int v25;              // ebx
	unsigned __int8* v26; // ecx
	int v27;              // eax
	int v28;              // esi
	int v29;              // ebp
	bool v30;             // zf
	bool v31;             // cc
	unsigned __int8* v32; // edi
	int v33;              // ecx
	unsigned __int8* v34; // edx
	int v35;              // eax
	int v36;              // eax
	unsigned __int8* v37; // ebx
	unsigned __int8* v38; // esi
	int v39;              // ecx
	unsigned __int8* v40; // edx
	int v41;              // eax
	float v42;            // [esp+0h] [ebp-24h]
	float v43;            // [esp+14h] [ebp-10h]
	float v44;            // [esp+14h] [ebp-10h]
	unsigned __int8* v45; // [esp+14h] [ebp-10h]
	int v46;              // [esp+18h] [ebp-Ch]
	int v47;              // [esp+1Ch] [ebp-8h]
	int v48;              // [esp+1Ch] [ebp-8h]
	float v49;            // [esp+1Ch] [ebp-8h]
	int v50;              // [esp+20h] [ebp-4h]
	float v51;            // [esp+28h] [ebp+4h]
	float v52;            // [esp+28h] [ebp+4h]
	float v53;            // [esp+28h] [ebp+4h]
	int2* v54;            // [esp+2Ch] [ebp+8h]
	int2* v55;            // [esp+2Ch] [ebp+8h]
	int2* v56;            // [esp+2Ch] [ebp+8h]
	int2* v57;            // [esp+2Ch] [ebp+8h]
	int2* v58;            // [esp+2Ch] [ebp+8h]
	int2* v59;            // [esp+2Ch] [ebp+8h]
	int2* v60;            // [esp+2Ch] [ebp+8h]

	v4 = a1->field_4;
	v5 = a2->field_4;
	if (v4 == v5) {
		if (v4 < 0 || v4 >= sizeof(nox_arr_956A00)/4 || !nox_arr_956A00[v4])  // TODO: figure out why overflow happens on high-res
			return 0;
		v47 = a1->field_0;
		v54 = (int2*)a2->field_0;
		if (a1->field_0 > (int)v54) {
			v51 = (double)(int)v54;
			v7 = (double)v47;
		} else {
			v51 = (double)v47;
			v7 = (double)(int)v54;
		}
		v43 = v7;
		if (v4 < 0)
			return 0;
		if (v4 >= nox_win_height)
			v4 = nox_win_height - 1;
		if (v51 < 0.0)
			v51 = 0.0;
		v8 = (double)nox_win_width;
		if (v51 > v8)
			v51 = v8;
		v9 = nox_arr_956A00[v4];
		v10 = 0;
		if (v9 <= 0) {
		LABEL_22:
			*a4 = 0;
			result = 1;
		} else {
			v11 = ((void*)&nox_arr_957820[4 + 128 * v4]);
			while (1) {
				v12 = *(v11 - 1);
				v13 = *v11;
				v55 = (int2*)*v11;
				if ((double)*(v11 - 1) > v51) {
					if (*a3 < v12)
						*a3 = v12;
					if ((double)(int)v55<v43&& * a4> v13) {
						*a4 = v13;
						return 1;
					}
					return 1;
				}
				v14 = (double)(int)v55;
				if (v51 <= v14 && v43 > v14)
					break;
				if (v43 <= v14)
					return 1;
				v10 += 2;
				v11 += 2;
				if (v10 >= v9)
					goto LABEL_22;
			}
			if (*a4 <= v13)
				return 1;
			*a4 = v13;
			result = 1;
		}
		return result;
	}
	v48 = a1->field_0;
	v56 = (int2*)a2->field_0;
	if (a1->field_0 > (int)v56) {
		v15 = v5;
		v16 = a1->field_4;
		v50 = v5;
		v52 = (double)(int)v56;
		v17 = (double)v48;
	} else {
		v15 = a1->field_4;
		v16 = v5;
		v50 = a1->field_4;
		v52 = (double)v48;
		v17 = (double)(int)v56;
	}
	v44 = v17;
	v18 = v16 - v15;
	v57 = (int2*)(v16 - v15);
	if (v16 - v15 >= 0) {
		v46 = 1;
	} else {
		v18 = v15 - v16;
		v57 = (int2*)(v15 - v16);
		v46 = -1;
	}
	v49 = (v44 - v52) / (double)(int)v57;
	if (v15 >= 0) {
		v19 = nox_win_height;
		if (v15 < nox_win_height)
			goto LABEL_44;
		if (v16 >= nox_win_height)
			return 0;
		v58 = (int2*)(v15 - nox_win_height + 1);
		v15 = nox_win_height - 1;
		v52 = (double)(int)v58 * v49 + v52;
		v20 = nox_float2int(v52);
		if (*a3 < v20)
			*a3 = v20;
	} else {
		v15 = 0;
		v52 = v52 - (double)v50 * v49;
	}
	v19 = nox_win_height;
LABEL_44:
	if (v16 >= 0) {
		if (v16 >= v19) {
			v59 = (int2*)(v19 - v16 + v18 - 1);
			v44 = (double)(int)v59 * v49 + v52;
			v21 = nox_float2int(v44);
			if (*a4 > v21)
				*a4 = v21;
			v18 = (int)v59;
		}
	} else {
		v18 += v16;
	}
	if (v52 < 0.0) {
		v52 = 0.0;
		v15 -= nox_float2int(0.0);
	}
	v22 = (double)nox_win_width;
	if (v44 > v22) {
		v42 = v44 - v22;
		v18 -= nox_float2int(v42);
	}
	v23 = nox_arr_956A00[v15];
	v24 = 0;
	v25 = 1;
	if (v23 > 0) {
		v26 = ((void*)&nox_arr_957820[4 + 128 * v15]);
		while ((double)*((int*)v26 - 1) > v52 || (double)(int)(*(_DWORD*)v26 + 2) < v52) {
			v24 += 2;
			v26 += 8;
			if (v24 >= v23)
				goto LABEL_61;
		}
		v25 = 0;
	}
LABEL_61:
	v27 = v46;
	v28 = v46 + v15;
	v29 = v18 - 1;
	v60 = (int2*)v29;
	v53 = v49 + v52;
	if (v25) {
		v30 = v29 == 0;
		v31 = v29 <= 0;
		if (v29 <= 0) {
		LABEL_71:
			if (v30)
				return 0;
			goto LABEL_77;
		}
		v45 = &nox_arr_956A00[v28];
		v32 = ((void*)&nox_arr_957820[4 + 128 * v28]);
		while (1) {
			v33 = 0;
			if (*(_DWORD*)v45 > 0)
				break;
		LABEL_69:
			v28 += v46;
			v35 = (int)&v60[-1].field_4 + 3;
			v32 += 128 * v46;
			v53 = v49 + v53;
			v60 = (int2*)v35;
			v45 += 4 * v46;
			if (v35 <= 0) {
				v29 = v35;
				v27 = v46;
				v30 = v29 == 0;
				v31 = v29 <= 0;
				goto LABEL_71;
			}
		}
		v34 = v32;
		while ((double)*((int*)v34 - 1) > v53 || (double)(int)(*(_DWORD*)v34 + 2) < v53) {
			v33 += 2;
			v34 += 8;
			if (v33 >= *(int*)v45)
				goto LABEL_69;
		}
		v36 = nox_float2int(v53) - 1;
		if (*a3 < v36)
			*a3 = v36;
		v29 = (int)v60;
		v27 = v46;
	}
	v31 = v29 <= 0;
LABEL_77:
	if (!v31) {
		v37 = &nox_arr_956A00[v28];
		v38 = ((void*)&nox_arr_957820[4 + 128 * v28]);
		while (1) {
			v39 = 0;
			if (*(int*)v37 <= 0)
				break;
			v40 = v38;
			while ((double)*((int*)v40 - 1) > v53 || (double)(int)(*(_DWORD*)v40 + 2) < v53) {
				v39 += 2;
				v40 += 8;
				if (v39 >= *(int*)v37)
					goto LABEL_87;
			}
			--v29;
			v38 += 128 * v27;
			v37 += 4 * v27;
			v53 = v49 + v53;
			if (v29 <= 0)
				return 1;
		}
	LABEL_87:
		v41 = nox_float2int(v53);
		if (*a4 > v41)
			*a4 = v41;
	}
	return 1;
}

//----- (004C4770) --------------------------------------------------------
__int16  nox_xxx_drawObject_4C4770_draw(int* a1, nox_drawable* dr, int a3) {
	unsigned __int8* a2 = dr;
	unsigned __int8* v3;  // esi
	char* v4;             // eax
	_DWORD* v5;           // edi
	_DWORD* v6;           // eax
	int v7;               // ecx
	int v8;               // edi
	int v9;               // ecx
	int v10;              // ebp
	int v11;              // edx
	int v12;              // eax
	int v13;              // ebx
	int v14;              // edx
	int v15;              // ebx
	int v16;              // edi
	int v17;              // ebx
	unsigned __int8 v18;  // al
	unsigned __int8 v19;  // cl
	int v20;              // ecx
	int v21;              // edx
	int v22;              // ecx
	int v23;              // edi
	int v24;              // ebx
	int v25;              // ebx
	int v26;              // edi
	int v27;              // ecx
	unsigned __int8* v28; // edi
	__int16 v29;          // ax
	int v30;              // ebp
	int v31;              // edx
	int v32;              // eax
	int v33;              // eax
	int v34;              // edx
	int v35;              // ecx
	double v36;           // st7
	double v37;           // st7
	unsigned __int8 v38;  // bl
	unsigned __int8 v39;  // al
	int v40;              // edx
	int v41;              // ecx
	int v42;              // edi
	int v43;              // ebx
	int v44;              // eax
	int v45;              // eax
	int v46;              // eax
	int v47;              // ebp
	int v48;              // eax
	int v49;              // eax
	int v50;              // eax
	int v51;              // ebx
	int v53;              // [esp+18h] [ebp-30h]
	int v54;              // [esp+1Ch] [ebp-2Ch]
	int2 a1a;             // [esp+20h] [ebp-28h]
	int2 a2a;             // [esp+28h] [ebp-20h]
	int a4;               // [esp+30h] [ebp-18h]
	int a3a;              // [esp+34h] [ebp-14h]
	int v59a;          // [esp+38h] [ebp-10h]
	int v59b;          // [esp+38h] [ebp-10h]
	__int64 v60;          // [esp+40h] [ebp-8h]
	unsigned __int8 v61;  // [esp+4Ch] [ebp+4h]
	unsigned __int8 v62;  // [esp+4Ch] [ebp+4h]
	unsigned __int8 v63;  // [esp+50h] [ebp+8h]
	unsigned __int8 v64;  // [esp+50h] [ebp+8h]

	v53 = 0;
	v54 = 0;
	if (!dword_5d4594_1321520)
		dword_5d4594_1321520 = nox_xxx_getTTByNameSpriteMB_44CFC0("Ghost");
	v3 = a2;
	if (a2[112] & 4) {
		v4 = nox_common_playerInfoGetByID_417040(*((_DWORD*)a2 + 32));
		if (*getMemU32Ptr(0x85319C, 0) == *((_DWORD*)a2 + 32)) {
			if (v4 && v4[3680] & 1)
				v54 = 1;
		} else if (v4 && v4[3680] & 1) {
			return (__int16)v4;
		}
		v5 = nox_xxx_objGetTeamByNetCode_418C80(*getMemIntPtr(0x85319C, 0));
		if (v5) {
			v6 = nox_xxx_objGetTeamByNetCode_418C80(*((_DWORD*)a2 + 32));
			if (v6) {
				if (*getMemU32Ptr(0x85319C, 0) == *((_DWORD*)a2 + 32) || nox_xxx_servCompareTeams_419150((int)v5, (int)v6))
					v53 = 1;
			}
		}
	}
	v7 = *((_DWORD*)a2 + 3);
	a3a = 0;
	v8 = *a1;
	v9 = v7 - a1[4];
	v10 = a1[1];
	v11 = *((__int16*)a2 + 53);
	v59a = v9 + *a1 - *a2;
	v12 = *((_DWORD*)a2 + 4);
	v13 = *((_DWORD*)a2 + 4) - v11 - a2[1] - *((__int16*)a2 + 52);
	v14 = a1[5];
	v59b = v10 + v13 - v14;
	a4 = nox_win_width;
	if (*getMemU32Ptr(0x587000, 80808)) {
		v15 = *((_DWORD*)a2 + 30);
		if (!(v15 & 0x40000000) && !(v15 & 1) && (a2[112] & 0x80u) != 0) {
			v16 = v9 + v8;
			a1a.field_0 = v16;
			v17 = v10 + v12 - v14;
			v18 = a2[299];
			v19 = a2[299];
			a1a.field_4 = v17;
			v20 = 8 * v19;
			v21 = v16 + *getMemIntPtr(0x587000, 196184 + v20);
			v22 = v17 + *getMemIntPtr(0x587000, 196188 + v20);
			a2a.field_0 = v21;
			a2a.field_4 = v22;
			if (v18 < 0x18u && v18 && (v18 < 8u || v18 > 0x10u)) {
				v23 = (v21 + v16) >> 1;
				v24 = (v22 + v17) >> 1;
				if (sub_4C5630(v23 - 5, v23 - 5, v24)) {
					a1a.field_0 -= 2;
					a2a.field_0 -= 2;
				} else if (sub_4C5630(v23 + 5, v23 + 5, v24)) {
					a1a.field_0 += 2;
					a2a.field_0 += 2;
				}
			} else {
				v25 = (v22 + v17) >> 1;
				v26 = (v21 + v16) >> 1;
				if (sub_4C5630(v26, v26, v25 - 5)) {
					v27 = a2a.field_4 - 2;
					a1a.field_4 -= 2;
				} else {
					if (!sub_4C5630(v26, v26, v25 + 5))
						goto LABEL_32;
					v27 = a2a.field_4 + 2;
					a1a.field_4 += 2;
				}
				a2a.field_4 = v27;
			}
		LABEL_32:
			v4 = (char*)sub_4C42A0(&a1a, &a2a, &a3a, &a4);
			if (!v4)
				return (__int16)v4;
			goto LABEL_33;
		}
	}
LABEL_33:
	if (*((_DWORD*)a2 + 28) & 0x80000 && *((_DWORD*)a2 + 30) & 0x1000000 || *((_DWORD*)a2 + 30) & 0x40000000)
		v28 = getMemAt(0x587000, 185472);
	else
		v28 = (unsigned __int8*)(*(int(**)(int2*)) & dword_5d4594_3807156)((int2*)(a2 + 12));
	v29 = *((_WORD*)a2 + 52);
	a2a.field_0 = 0;
	if (v29 >= 0) {
		v30 = 0;
	} else {
		if (*getMemIntPtr(0x5D4594, 1321512) < 0 && a2 == *(unsigned __int8**)getMemAt(0x5D4594, 1321516))
			a2a.field_0 = 1;
		v30 = -v29;
	}
	*getMemU32Ptr(0x5D4594, 1321516) = a2;
	v31 = *((__int16*)a2 + 52);
	a1a.field_0 = v30;
	*getMemU32Ptr(0x5D4594, 1321512) = v31;
	if (nox_xxx_spriteCheckFlag31_4356C0((int)a2, 25)) {
		nox_xxx_draw_434600(1);
		sub_433E40(*getMemIntPtr(0x85B3FC, 980));
	} else if (a2[112] & 2 && (v32 = *((_DWORD*)a2 + 30), v32 & 0x40000000) && !(v32 & 0x8020)) {
		nox_xxx_draw_434600(1);
		sub_433E40(*getMemIntPtr(0x85B3FC, 980));
	} else {
		v33 = sub_4345F0(1);
		LOBYTE(v34) = v28[8];
		LOBYTE(v33) = v28[4];
		LOBYTE(v35) = *v28;
		sub_433CD0(v35, v33, v34);
	}
	if (*((_DWORD*)a2 + 120)) {
		v60 = (unsigned int)(nox_frame_xxx_2598000 - *((_DWORD*)a2 + 85));
		v36 = (double)v60;
		v60 = nox_gameFPS;
		v37 = 1.0 - v36 / (double)(int)nox_gameFPS;
		if (v37 < 0.0)
			v37 = 0.001;
		v38 = (__int64)(v37 * 255.0);
		v63 = (__int64)(v37 * 255.0);
		if (*((_DWORD*)v3 + 27) == dword_5d4594_1321520) {
			v39 = sub_4C4EC0(a1, (int)v3);
			if (v39 < v38) {
				v64 = v39;
				nox_client_drawEnableAlpha_434560(1);
				nox_client_drawSetAlpha_434580(v64);
				goto LABEL_64;
			}
		} else if (*((_DWORD*)v3 + 30) & 0x4000000) {
			v63 = v38 >> 1;
		}
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(v63);
		goto LABEL_64;
	}
	if (*((_DWORD*)a2 + 27) == dword_5d4594_1321520) {
		v61 = sub_4C4EC0(a1, (int)a2);
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(v61);
	} else if (*((_DWORD*)a2 + 30) & 0x4000000) {
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x80u);
	}
LABEL_64:
	if (!nox_xxx_spriteCheckFlag31_4356C0((int)v3, 0) && !v54 &&
		(*((_DWORD*)v3 + 27) != dword_5d4594_1321520 || !*getMemU32Ptr(0x852978, 8) ||
		 !nox_xxx_spriteCheckFlag31_4356C0(*getMemIntPtr(0x852978, 8), 21))) {
		goto LABEL_105;
	}
	if (*getMemU32Ptr(0x8531A0, 2576) && *(_BYTE*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 1) {
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x80u);
		goto LABEL_105;
	}
	v40 = *((_DWORD*)v3 + 8);
	v41 = *((_DWORD*)v3 + 9);
	v42 = *((_DWORD*)v3 + 3) - v40;
	v43 = *((_DWORD*)v3 + 4) - v41;
	v44 = *((_DWORD*)v3 + 3) - v40;
	if (v42 < 0)
		v44 = v40 - *((_DWORD*)v3 + 3);
	if (v44 < 4) {
		v45 = *((_DWORD*)v3 + 4) - v41;
		if (v43 < 0)
			v45 = v41 - *((_DWORD*)v3 + 4);
		if (v45 < 4) {
			v46 = *getMemU32Ptr(0x852978, 8);
			if (!*getMemU32Ptr(0x852978, 8))
				goto LABEL_82;
			if (!nox_xxx_spriteCheckFlag31_4356C0(*getMemIntPtr(0x852978, 8), 21)) {
				LOWORD(v4) = v53;
				if (!v53)
					return (__int16)v4;
			}
		}
	}
	v46 = *getMemU32Ptr(0x852978, 8);
LABEL_82:
	if (v42 || v43) {
		v47 = *((_DWORD*)v3 + 5) - *((_DWORD*)v3 + 10);
		if (!v47)
			v47 = 1;
		v48 = nox_double2int(sqrt((double)(v42 * v42 + v43 * v43))) / v47;
		v30 = a1a.field_0;
		v42 = v48;
		v46 = *getMemU32Ptr(0x852978, 8);
	}
	if (!v46)
		goto LABEL_123;
	if (v54)
		goto LABEL_95;
	if (v53 || !nox_xxx_spriteCheckFlag31_4356C0(v46, 21)) {
	LABEL_123:
		if (v42 < 8) {
			v49 = (v42 << 7) / 8;
			v62 = v49;
			if ((_BYTE)v49)
				goto LABEL_97;
			LOBYTE(v49) = 1;
		LABEL_96:
			v62 = v49;
		LABEL_97:
			if (v53 && (unsigned __int8)v49 <= 1u) {
				if ((v50 = *((_DWORD*)v3 + 28), v50 & 2) && *((_DWORD*)v3 + 69) == 8 ||
					v50 & 4 && !*((_DWORD*)v3 + 69)) {
					nox_xxx_draw_434600(1);
					sub_433E40(*getMemIntPtr(0x8531A0, 2572));
					v62 = -128;
				}
			}
			goto LABEL_104;
		}
	LABEL_95:
		LOBYTE(v49) = -128;
		goto LABEL_96;
	}
	nox_xxx_draw_434600(1);
	sub_433E40(*getMemIntPtr(0x8531A0, 2572));
#ifdef NOX_CGO
	v62 = -1;
#else // NOX_CGO
	v62 = nox_backbuffer_depth >= 16 ? -1 : -128;
#endif // NOX_CGO
LABEL_104:
	nox_client_drawEnableAlpha_434560(1);
	nox_client_drawSetAlpha_434580(v62);
LABEL_105:
	if (!(v3[112] & 4) && nox_xxx_spriteCheckFlag31_4356C0((int)v3, 23) && !nox_common_gameFlags_check_40A5C0(2048)) {
		nox_xxx_draw_434600(1);
		if ((unsigned char)nox_frame_xxx_2598000 & 1)
			sub_433E40(*getMemIntPtr(0x5D4594, 2523948));
		else
			sub_433E40(*getMemIntPtr(0x85B3FC, 980));
	}
	if (!nox_xxx_spriteCheckFlag31_4356C0((int)v3, 23) && nox_xxx_spriteCheckFlag31_4356C0((int)v3, 11)) {
		nox_xxx_draw_434600(1);
		sub_433E40(*getMemIntPtr(0x85B3FC, 956));
	}
	v51 = a2a.field_0;
	if (a2a.field_0) {
		nox_xxx_wndDraw_49F7F0();
		sub_49F7C0(dword_5d4594_3799476);
	} else {
		sub_47D370(v30);
	}
	nox_client_drawImageAt_47D2C0(a3, v59a, v59b);
	sub_4345F0(0);
	nox_client_drawEnableAlpha_434560(0);
	nox_xxx_draw_434600(0);
	if (v51)
		sub_49F860();
	*((_WORD*)v3 + 1) = 1;
	LOWORD(v4) = *getMemU16Ptr(0x973F18, 88);
	*((_WORD*)v3 + 2) = *getMemU16Ptr(0x973F18, 88);
	*((_WORD*)v3 + 3) = *getMemU16Ptr(0x973F18, 76);
	*((_DWORD*)v3 + 2) = a3;
	return (__int16)v4;
}
// 4C4AD0: variable 'v35' is possibly undefined
// 4C4AD0: variable 'v34' is possibly undefined

//----- (004C4EC0) --------------------------------------------------------
char  sub_4C4EC0(_DWORD* a1, int a2) {
	int v3; // ecx
	int v4; // eax
	int v5; // ecx

	if (*getMemU32Ptr(0x852978, 8) && nox_xxx_spriteCheckFlag31_4356C0(*getMemIntPtr(0x852978, 8), 21))
		return -1;
	v3 = *(_DWORD*)(a2 + 12) - a1[8] / 2 - a1[4];
	v4 = *(_DWORD*)(a2 + 16) - a1[9] / 2 - a1[5];
	v5 = 128 - ((v3 * v3 + v4 * v4) << 7) / *getMemU32Ptr(0x587000, 185464);
	if (v5 < 0)
		return 0;
	if (v5 > 128)
		LOBYTE(v5) = -128;
	return v5;
}

//----- (004C4F40) --------------------------------------------------------
__int16  nox_xxx_drawShinySpot_4C4F40(nox_draw_viewport_t* vp, nox_drawable* dr) {
	_DWORD* a1 = vp;
	int a2 = dr;
	char* v2;        // eax
	int v3;          // edi
	signed int v4;   // esi
	unsigned int v5; // eax
	signed int v6;   // edx

	v2 = *(char**)getMemAt(0x5D4594, 1321524);
	if (!*getMemU32Ptr(0x5D4594, 1321524)) {
		v2 = nox_xxx_gLoadAnim_42FA20("ShinySpot");
		*getMemU32Ptr(0x5D4594, 1321524) = v2;
	}
	v3 = *((_DWORD*)v2 + 24);
	v4 = *(unsigned __int8*)(v3 + 8);
	v5 = (nox_frame_xxx_2598000 + *(_DWORD*)(a2 + 128)) / (unsigned int)(8 * v4);
	v6 = ((nox_frame_xxx_2598000 + *(_DWORD*)(a2 + 128)) % (unsigned int)(8 * v4)) >> 1;
	if (v6 < v4)
		nox_client_drawImageAt_47D2C0(
			*(_DWORD*)(*(_DWORD*)(v3 + 4) + 4 * v6), *(_DWORD*)(a2 + 12) - a1[4] + *a1 - 64,
			a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5] + *(_DWORD*)(a2 + 16) - 64);
	return v5;
}

//----- (004C4FD0) --------------------------------------------------------
int nox_xxx_colorInit_4C4FD0() {
	int result; // eax

	*getMemU32Ptr(0x5D4594, 1321536) = nox_color_rgb_4344A0(255, 200, 255);
	*getMemU32Ptr(0x5D4594, 1321796) = nox_color_rgb_4344A0(255, 0, 255);
	result = nox_color_rgb_4344A0(100, 40, 100);
	*getMemU32Ptr(0x5D4594, 1321532) = result;
	return result;
}

//----- (004C5020) --------------------------------------------------------
int  sub_4C5020(int a1) {
	int result; // eax

	result = dword_5d4594_1321800;
	if (*(int*)&dword_5d4594_1321800 < 32) {
		result = dword_5d4594_1321800 + 1;
		*getMemU32Ptr(0x5D4594, 1321532 + 8 * result) = *(_DWORD*)(a1 + 1);
		*getMemU32Ptr(0x5D4594, 1321536 + 8 * result) = *(_DWORD*)(a1 + 5);
		dword_5d4594_1321800 = result;
	}
	return result;
}

//----- (004C5050) --------------------------------------------------------
void sub_4C5050() { dword_5d4594_1321800 = 0; }

//----- (004C5060) --------------------------------------------------------
int  sub_4C5060(nox_draw_viewport_t* a1p) {
	_DWORD* a1 = a1p;
	int result;           // eax
	unsigned __int16* v2; // ebp
	int v3;               // esi
	int v4;               // edi
	int v5;               // ebx
	int v6;               // ecx
	int v7;               // edi
	int v8;               // esi
	int v10;              // [esp+0h] [ebp-24h]
	int2 a1a;             // [esp+4h] [ebp-20h]
	int2 v12;             // [esp+Ch] [ebp-18h]
	int2 a2;              // [esp+14h] [ebp-10h]
	int2 v14;             // [esp+1Ch] [ebp-8h]

	result = *getMemU32Ptr(0x852978, 8);
	if (*getMemU32Ptr(0x852978, 8)) {
		result = dword_5d4594_1321800;
		v10 = 0;
		if (dword_5d4594_1321800 > 0) {
			v2 = getMemU16Ptr(0x5D4594, 1321540);
			do {
				v3 = *a1 + *v2 - a1[4];
				v4 = a1[1] + v2[1] - a1[5];
				v5 = sub_4992B0(v3, v4);
				v6 = v2[3] - v2[1];
				if (v3 <= 0 || v3 >= a1[8] - 1 || v4 <= 0 || v4 >= a1[9] - 1)
					v5 = 0;
				v14.field_0 = v3 + v2[2] - *v2;
				v14.field_4 = v4 + v6;
				v12.field_0 = v3;
				v12.field_4 = v4;
				v7 = sub_498C20(&v12, &v14, (int)a1);
				if (v7) {
					v8 = 0;
					for (a1a = v12; v8 < v7; v5 = 1 - v5) {
						*(_QWORD*)&a2 = sub_499290(v8);
						if (v5)
							sub_4C51D0(&a1a, &a2);
						a1a = a2;
						++v8;
					}
					if (v5)
						sub_4C51D0(&a1a, &v14);
				} else if (v5) {
					sub_4C51D0(&v12, &v14);
				}
				result = v10 + 1;
				v2 += 4;
				++v10;
			} while (v10 < *(int*)&dword_5d4594_1321800);
		}
	}
	return result;
}
// 4C5151: variable 'v9' is possibly undefined

//----- (004C51D0) --------------------------------------------------------
int  sub_4C51D0(int2* a1, int2* a2) {
	int v2;  // esi
	int v3;  // edi
	int v4;  // ebx
	int v5;  // ebp
	int v6;  // esi
	int v7;  // ecx
	int v8;  // eax
	int v9;  // ebx
	int v11; // ebp

	v2 = a1->field_4;
	v3 = a1->field_0;
	v4 = a2->field_0 - a1->field_0;
	v5 = a2->field_4 - v2;
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 1321532));
	nox_client_drawEnableAlpha_434560(1);
	nox_client_drawAddPoint_49F500(v3, v2);
	nox_xxx_rasterPointRel_49F570(v4, v5);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawEnableAlpha_434560(0);
	v6 = v2 - 22;
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 1321536));
	nox_client_drawAddPoint_49F500(v3, v6);
	nox_xxx_rasterPointRel_49F570(v4, v5);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 1321796));
	v7 = v4;
	if (v4 < 0)
		v7 = -v4;
	v8 = v5;
	if (v5 < 0)
		v8 = -v5;
	if (v7 <= v8) {
		nox_client_drawAddPoint_49F500(v3 - 1, v6);
		v11 = v6 + v5;
		nox_client_drawAddPoint_49F500(v4 + v3 - 1, v11);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(v3 + 1, v6);
		nox_client_drawAddPoint_49F500(v4 + v3 + 1, v11);
	} else {
		nox_client_drawAddPoint_49F500(v3, v6 - 1);
		v9 = v3 + v4;
		nox_client_drawAddPoint_49F500(v9, v6 + v5 - 1);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(v3, v6 + 1);
		nox_client_drawAddPoint_49F500(v9, v6 + v5 + 1);
	}
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (004C52E0) --------------------------------------------------------
int  sub_4C52E0(int* a1, int a2) {
	int v2;     // edx
	int result; // eax
	int v4;     // esi
	int* v5;    // edx
	int* v6;    // ecx
	int v7;     // ebx
	int v8;     // eax
	int v9;     // edi
	int v10;    // esi
	int v11;    // ebp
	int v12;    // edx
	int v13;    // ebx
	int v14;    // edi
	int v15;    // esi
	bool v16;   // cc
	int v17;    // [esp+8h] [ebp-14h]
	int v18;    // [esp+Ch] [ebp-10h]
	int* v19;   // [esp+10h] [ebp-Ch]
	int v20;    // [esp+14h] [ebp-8h]
	int v21;    // [esp+18h] [ebp-4h]

	v2 = nox_win_height;
	memset(nox_arr_956A00, 0, sizeof(nox_arr_956A00));
	result = a2;
	v4 = 0;
	dword_5d4594_3679320 = v2;
	dword_5d4594_3798156 = 0;
	v21 = 0;
	if (a2 > 0) {
		v5 = a1;
		v6 = a1 + 1;
		v19 = a1 + 1;
		while (1) {
			v7 = *(v6 - 1);
			if (v4 == result - 1) {
				v8 = *v5;
				v9 = *v6;
				v10 = v5[1];
			} else {
				v8 = v6[1];
				v9 = *v6;
				v10 = v6[2];
			}
			if (v9 != v10) {
				if (v7 == v8) {
					if (v10 <= v9) {
						if (v10 >= v9)
							goto LABEL_26;
						do
							sub_4C5430(v7, v10++);
						while (v10 < v9);
					} else {
						do
							sub_4C5430(v7, v9++);
						while (v9 < v10);
					}
					goto LABEL_25;
				}
				if (v9 <= v10) {
					v17 = *(v6 - 1);
					v11 = v9;
					v18 = v10;
					v12 = v8 <= v7 ? -1 : 1;
				} else {
					v17 = v8;
					v11 = v10;
					v18 = v9;
					v12 = v8 <= v7 ? 1 : -1;
				}
				v20 = v12;
				if (v8 - v7 >= 0)
					v13 = v8 - v7;
				else
					v13 = v7 - v8;
				v14 = v18 - v11;
				v15 = 0;
				if (v11 < v18) {
					do {
						sub_4C5430(v17, v11);
						v15 += v13;
						++v11;
						for (; v15 >= v14; v17 += v20)
							v15 -= v14;
					} while (v11 < v18);
				LABEL_25:
					v6 = v19;
					goto LABEL_26;
				}
			}
		LABEL_26:
			result = a2;
			v4 = v21 + 1;
			v6 += 2;
			v16 = ++v21 < a2;
			v19 = v6;
			if (!v16)
				return result;
			v5 = a1;
		}
	}
	return result;
}

//----- (004C5430) --------------------------------------------------------
void  sub_4C5430(int a1, int a2) {
	int v2;              // esi
	int v3;              // ecx
	unsigned __int8* v4; // eax
	int v5;              // eax
	unsigned __int8* v6; // edx

	v2 = nox_arr_956A00[a2];
	if (v2 < 32) {
		v3 = 0;
		if (v2 > 0) {
			v4 = ((void*)&nox_arr_957820[128 * a2]);
			do {
				if (a1 < *(int*)v4)
					break;
				++v3;
				v4 += 4;
			} while (v3 < v2);
		}
		if (v3 != v2 && v2 - 1 >= v3) {
			v5 = v2 - v3;
			v6 = ((void*)&nox_arr_957820[4 + 4 * (v2 - 1 + 32 * a2)]);
			do {
				*(_DWORD*)v6 = *((_DWORD*)v6 - 1);
				v6 -= 4;
				--v5;
			} while (v5);
		}
		nox_arr_956A00[a2] = v2 + 1;
		*((unsigned int*)&nox_arr_957820[4 * (v3 + 32 * a2)]) = a1;
		if (a2 < *(int*)&dword_5d4594_3679320)
			dword_5d4594_3679320 = a2;
		if (a2 > *(int*)&dword_5d4594_3798156)
			dword_5d4594_3798156 = a2;
	}
}

//----- (004C54D0) --------------------------------------------------------
void nox_xxx____inc_tmpoff_4C54D0() { ++dword_587000_185504; }

//----- (004C54E0) --------------------------------------------------------
int sub_4C54E0() {
	int result; // eax

	result = --dword_587000_185504;
	if (*(int*)&dword_587000_185504 <= 0)
		dword_587000_185504 = 1;
	return result;
}

//----- (004C5500) --------------------------------------------------------
void sub_4C5500(nox_draw_viewport_t* a1p) {
	int* a1 = a1p;
	int* v1;              // ebx
	int v2;               // ebp
	int v3;               // esi
	int v4;               // edi
	int v5;               // eax
	unsigned __int8* v6;  // ebx
	int* v7;              // esi
	int v8;               // eax
	int v9;               // ecx
	unsigned int v10;     // ebp
	int v11;              // ecx
	unsigned __int8* v13; // [esp+10h] [ebp-14h]
	int v14;              // [esp+18h] [ebp-Ch]
	int v15;              // [esp+1Ch] [ebp-8h]
	int v16;              // [esp+20h] [ebp-4h]

	v1 = a1;
	v2 = *a1;
	v3 = a1[1];
	v14 = *a1;
	v15 = a1[1];
	v16 = sub_49F6D0(0);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 952));
	v4 = dword_5d4594_3679320;
	if (dword_5d4594_3679320 > v3) {
		nox_client_drawRectFilledOpaque_49CE30(v2, v3, a1[8], dword_5d4594_3679320 - v3);
		v4 = dword_5d4594_3679320;
	}
	v5 = dword_5d4594_3798156;
	if (v4 < *(int*)&dword_5d4594_3798156) {
		v13 = &nox_arr_956A00[v4];
		v6 = ((void*)&nox_arr_957820[128 * v4]);
		do {
			v7 = (int*)(v6 + 4);
			v8 = v2;
			v9 = *(_DWORD*)v6;
			if (*(_DWORD*)v13 > 0) {
				v10 = (unsigned int)(*(_DWORD*)v13 + 1) >> 1;
				do {
					(*(void(**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798720)(v8, v4, v9);
					v8 = *v7;
					v9 = v7[1];
					v7 += 2;
					--v10;
				} while (v10);
				v2 = v14;
			}
			(*(void(**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798720)(v8, v4, v2 + a1[8]);
			v5 = dword_5d4594_3798156;
			++v4;
			v6 += 128;
			v13 += 4;
		} while (v4 < *(int*)&dword_5d4594_3798156);
		v3 = v15;
		v1 = a1;
	}
	v11 = v1[9];
	if (v5 < v11 + v3)
		nox_client_drawRectFilledOpaque_49CE30(v2, v5, v1[8], v3 + v11 - v5);
	sub_49F6D0(v16);

	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE))
		sub_498AE0();
}

//----- (004C5630) --------------------------------------------------------
int  sub_4C5630(int a1, int a2, int a3) {
	if (a3 < 0 || a3 > sizeof(nox_arr_956A00)/4) { // TODO: figure out why overflow happens on high-res
		return 0;
	}
	int v3;             // ecx
	int v4;             // edx
	unsigned __int8* i; // eax

	v3 = 0;
	v4 = nox_arr_956A00[a3];
	if (v4 <= 0)
		return 0;
	for (i = ((void*)&nox_arr_957820[128 * a3]); a1 > *((_DWORD*)i + 1) || a2 < *(int*)i; i += 8) {
		v3 += 2;
		if (v3 >= v4)
			return 0;
	}
	return 1;
}

//----- (004C5680) --------------------------------------------------------
int  sub_4C5680(int a1, int a2, int a3) {
	int v3;             // ecx
	int v4;             // edx
	unsigned __int8* i; // eax

	v3 = 0;
	v4 = nox_arr_956A00[a3];
	if (v4 <= 0)
		return 0;
	for (i = ((void*)&nox_arr_957820[4 + 128 * a3]); a1 < *((_DWORD*)i - 1) || a2 >= *(int*)i; i += 8) {
		v3 += 2;
		if (v3 >= v4)
			return 0;
	}
	return 1;
}

//----- (004C56D0) --------------------------------------------------------
int  sub_4C56D0(_DWORD* a1) {
	int v1;               // eax
	int v2;               // ebp
	int v3;               // ecx
	int v4;               // edx
	int result;           // eax
	int v6;               // ecx
	int v7;               // ebx
	int v8;               // edx
	int v9;               // esi
	bool v10;             // cc
	unsigned __int8* v11; // edx
	int v12;              // eax
	unsigned __int8* v13; // edi
	int v14;              // ebp
	unsigned int v15;     // ecx

	v1 = a1[5];
	if (v1 >= 0) {
		if (v1 >= 46)
			v2 = 0;
		else
			v2 = 46 - v1;
	} else {
		v2 = 46 - v1;
	}
	dword_5d4594_3679320 = v2;
	v3 = a1[9];
	v4 = a1[5];
	result = nox_win_height;
	if (v3 + v4 > 5865)
		result = nox_win_height - v3 - v4 + 5865;
	dword_5d4594_3798156 = result;
	if (result < 0) {
		result = 0;
		dword_5d4594_3798156 = 0;
	}
	v6 = a1[4];
	if (v6 >= 0) {
		if (v6 >= 46)
			v7 = 0;
		else
			v7 = 46 - v6;
	} else {
		v7 = 46 - v6;
	}
	v8 = a1[8];
	v9 = nox_win_width;
	if (v8 + v6 > 5865)
		v9 = nox_win_width - v8 - v6 + 5865;
	if (v9 < 0)
		v9 = 0;
	if (v7 > v9)
		v7 = v9;
	v10 = v2 < result;
	if (v2 > result) {
		v2 = result;
		dword_5d4594_3679320 = result;
		v10 = 0;
	}
	if (v10) {
		v11 = ((void*)&nox_arr_957820[4 + 128 * v2]);
		v12 = result - v2;
		v13 = &nox_arr_956A00[v2];
		v14 = v12;
		v15 = v12;
		result = 2;
		memset32(v13, 2, v15);
		do {
			*((_DWORD*)v11 - 1) = v7;
			*(_DWORD*)v11 = v9;
			v11 += 128;
			--v14;
		} while (v14);
	}
	return result;
}

//----- (004C57C0) --------------------------------------------------------
int  sub_4C57C0(FILE* a1, int a2, _DWORD* a3, _DWORD* a4) {
	int result; // eax

	if (!a1)
		return 0;
	result = sub_4C5850(a1);
	if (result) {
		if (*getMemU32Ptr(0x5D4594, 1322572)) {
			result = sub_4C5A60(a1, a2);
			if (!result)
				return result;
		} else if (!sub_4C5CB0(a1) || !sub_4C5D20(a1, a2)) {
			return 0;
		}
		nox_fs_close(a1);
		*a3 = dword_5d4594_3679312;
		*a4 = *getMemU32Ptr(0x85B3FC, 1029612);
		result = 1;
	}
	return result;
}

//----- (004C5850) --------------------------------------------------------
BOOL  sub_4C5850(FILE* a1) {
	FILE* v1; // esi
	int v3;   // [esp+4h] [ebp-4h]

	v1 = a1;
	if (nox_fs_fscan_char(a1, &a1) != 1)
		return 0;
	if ((_BYTE)a1 != 10)
		return 0;
	if (nox_fs_fscan_char(v1, &a1) != 1)
		return 0;
	if ((_BYTE)a1 != 5)
		return 0;
	if (nox_fs_fscan_char(v1, &a1) != 1)
		return 0;
	if ((_BYTE)a1 != 1)
		return 0;
	if (nox_fs_fscan_char(v1, &a1) != 1)
		return 0;
	if ((_BYTE)a1 != 8)
		return 0;
	if (nox_fs_fscan_char2(v1, &v3) != 1)
		return 0;
	if ((_WORD)v3)
		return 0;
	if (nox_fs_fscan_char2(v1, &v3) != 1)
		return 0;
	if ((_WORD)v3)
		return 0;
	if (nox_fs_fscan_char2(v1, &v3) != 1)
		return 0;
	dword_5d4594_3679312 = (unsigned __int16)v3;
	if (nox_fs_fscan_char2(v1, &v3) != 1)
		return 0;
	*getMemU32Ptr(0x85B3FC, 1029612) = (unsigned __int16)v3;
	if (dword_5d4594_3679312 > 639)
		return 0;
	if ((int)(unsigned __int16)v3 > 639)
		return 0;
	++dword_5d4594_3679312;
	*getMemU32Ptr(0x85B3FC, 1029612) = (unsigned __int16)v3 + 1;
	nox_fs_fseek_start(v1, 65);
	if (nox_fs_fscan_char(v1, &a1) != 1)
		return 0;
	if ((_BYTE)a1 == 1) {
		*getMemU32Ptr(0x5D4594, 1322572) = 0;
	} else {
		if ((_BYTE)a1 != 3)
			return 0;
		*getMemU32Ptr(0x5D4594, 1322572) = 1;
	}
	if (nox_fs_fscan_char2(v1, &v3) == 1) {
		*getMemU32Ptr(0x85B3FC, 1029604) = (unsigned __int16)v3;
		return nox_fs_fscan_char2(v1, &v3) == 1;
	}
	return 0;
}

//----- (004C5A60) --------------------------------------------------------
int  sub_4C5A60(FILE* a1, int a2) {
	int v2;  // ebx
	int v3;  // ebp
	int v4;  // eax
	int v5;  // esi
	char v6; // dl
	int v7;  // eax
	int v8;  // ecx
	bool v9; // cc
	int v11; // [esp+10h] [ebp-10h]
	int v12; // [esp+14h] [ebp-Ch]
	int v13; // [esp+18h] [ebp-8h]
	int v14; // [esp+1Ch] [ebp-4h]
	int i;   // [esp+28h] [ebp+8h]

	HIWORD(v2) = 0;
	LOBYTE(v12) = 0;
	LOBYTE(v11) = 0;
	nox_fs_fseek_start(a1, 128);
	v13 = 0;
	if (*getMemU32Ptr(0x85B3FC, 1029612) > 0) {
		v3 = a2;
		v4 = *getMemU32Ptr(0x85B3FC, 1029604);
		v14 = a2;
		while (2) {
			for (i = 0; i < 3; ++i) {
				v5 = 0;
				if (v4 > 0) {
					while (sub_4C5B80(a1, v5, &v11, &v12)) {
						LOBYTE(v2) = v12;
						v6 = v11;
						BYTE1(v2) = v12;
						v7 = v2 << 16;
						LOWORD(v7) = v2;
						v8 = (unsigned __int8)v11 >> 2;
						memset32((void*)(v5 + v3), v7, v8);
						memset((void*)(v5 + v3 + 4 * v8), v2, v6 & 3);
						v5 += (unsigned __int8)v11;
						v4 = *getMemU32Ptr(0x85B3FC, 1029604);
						if (v5 >= *getMemIntPtr(0x85B3FC, 1029604))
							goto LABEL_7;
					}
					return 0;
				}
			LABEL_7:
				v3 += 409600;
			}
			v3 = v14 + 640;
			v9 = ++v13 < *getMemIntPtr(0x85B3FC, 1029612);
			v14 += 640;
			if (v9)
				continue;
			break;
		}
	}
	sub_4C5B80(a1, 0, &v11, &v12);
	return 1;
}

//----- (004C5B80) --------------------------------------------------------
int  sub_4C5B80(FILE* a1, int a2, _BYTE* a3, _BYTE* a4) {
	int v4;              // eax
	int v5;              // ecx
	int result;          // eax
	_BYTE* v7;           // ecx
	FILE* v8;            // esi
	char v9;             // bl
	int v10;             // ebx
	unsigned __int8 v11; // al
	_BYTE* v12;          // eax
	char v13;            // cl
	_BYTE* v14;          // eax

	if (*getMemU32Ptr(0x5D4594, 1322576)) {
		v4 = a2;
		if (*getMemU32Ptr(0x5D4594, 1322576) + a2 <= *getMemIntPtr(0x85B3FC, 1029604)) {
			v7 = a4;
			*a3 = getMemByte(0x5D4594, 1322576);
			*getMemU32Ptr(0x5D4594, 1322576) = 0;
			*v7 = getMemByte(0x5D4594, 1322580);
			result = 1;
		} else {
			*a3 = getMemByte(0x85B3FC, 1029604) - a2;
			v5 = v4 - *getMemU32Ptr(0x85B3FC, 1029604) + *getMemU32Ptr(0x5D4594, 1322576);
			result = 1;
			*getMemU32Ptr(0x5D4594, 1322576) = v5;
		}
	} else {
		v8 = a1;
		if (nox_fs_fscan_char(a1, &a1) == 1) {
			v9 = (char)a1;
			if (((unsigned __int8)a1 & 0xC0) == 0xC0) {
				v10 = (unsigned __int8)a1 & 0x3F;
				if (nox_fs_fscan_char(v8, &a1) == 1) {
					if (v10 + a2 <= *getMemIntPtr(0x85B3FC, 1029604)) {
						v12 = a4;
						v13 = (char)a1;
						*a3 = v10;
						*v12 = v13;
					} else {
						v11 = getMemByte(0x85B3FC, 1029604) - a2;
						*a3 = getMemByte(0x85B3FC, 1029604) - a2;
						*getMemU32Ptr(0x5D4594, 1322576) = v10 - v11;
						*getMemU32Ptr(0x5D4594, 1322580) = (unsigned __int8)a1;
						*a4 = (_BYTE)a1;
					}
					result = 1;
				} else {
					result = 0;
				}
			} else {
				v14 = a4;
				*a3 = 1;
				*v14 = v9;
				result = 1;
			}
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (004C5CB0) --------------------------------------------------------
BOOL  sub_4C5CB0(FILE* a1) {
	FILE* v1; // esi

	v1 = a1;
	if (nox_fs_fseek_end(a1,  -769))
		return 0;
	if (nox_fs_fread(v1, &a1, 1) != 1)
		return 0;
	if ((_BYTE)a1 == 12)
		return nox_fs_fread(v1, getMemAt(0x5D4594, 1321804), 0x300) == 768;
	return 0;
}

//----- (004C5D20) --------------------------------------------------------
int  sub_4C5D20(FILE* a1, int a2) {
	int v2;     // ebx
	int v3;     // eax
	int v4;     // ebp
	int v5;     // esi
	char* v6;   // edi
	char v7;    // dl
	int v8;     // eax
	int v9;     // ecx
	char* v10;  // edi
	char v11;   // dl
	int v12;    // eax
	int v13;    // ecx
	char v14;   // dl
	int v15;    // eax
	int v16;    // ecx
	int result; // eax
	int v18;    // [esp+10h] [ebp-Ch]
	int v19;    // [esp+14h] [ebp-8h]
	int v20;    // [esp+18h] [ebp-4h]

	HIWORD(v2) = 0;
	LOBYTE(v19) = 0;
	LOBYTE(v18) = 0;
	nox_fs_fseek_start(a1, 128);
	v20 = 0;
	if (*getMemIntPtr(0x85B3FC, 1029612) <= 0) {
	LABEL_7:
		sub_4C5B80(a1, 0, &v18, &v19);
		result = 1;
	} else {
		v3 = *getMemU32Ptr(0x85B3FC, 1029604);
		v4 = a2 + 819200;
		while (1) {
			v5 = 0;
			if (v3 > 0)
				break;
		LABEL_6:
			v4 += 640;
			if (++v20 >= *getMemU32Ptr(0x85B3FC, 1029612))
				goto LABEL_7;
		}
		while (sub_4C5B80(a1, v5, &v18, &v19)) {
			v6 = (char*)(v5 + v4 - 819200);
			v7 = v18;
			LOBYTE(v2) = getMemByte(0x5D4594, 1321804 + 3 * (unsigned __int8)v19);
			BYTE1(v2) = getMemByte(0x5D4594, 1321804 + 3 * (unsigned __int8)v19);
			v8 = v2 << 16;
			LOWORD(v8) = v2;
			v9 = (unsigned __int8)v18 >> 2;
			memset32(v6, v8, v9);
			memset(&v6[4 * v9], v2, v7 & 3);
			v10 = (char*)(v5 + v4 - 409600);
			v11 = v18;
			LOBYTE(v2) = getMemByte(0x5D4594, 1321805 + 3 * (unsigned __int8)v19);
			BYTE1(v2) = getMemByte(0x5D4594, 1321805 + 3 * (unsigned __int8)v19);
			v12 = v2 << 16;
			LOWORD(v12) = v2;
			v13 = (unsigned __int8)v18 >> 2;
			memset32(v10, v12, v13);
			memset(&v10[4 * v13], v2, v11 & 3);
			v14 = v18;
			LOBYTE(v2) = getMemByte(0x5D4594, 1321806 + 3 * (unsigned __int8)v19);
			BYTE1(v2) = getMemByte(0x5D4594, 1321806 + 3 * (unsigned __int8)v19);
			v15 = v2 << 16;
			LOWORD(v15) = v2;
			v16 = (unsigned __int8)v18 >> 2;
			memset32((void*)(v5 + v4), v15, v16);
			memset((void*)(v5 + v4 + 4 * v16), v2, v14 & 3);
			v5 += (unsigned __int8)v18;
			v3 = *getMemU32Ptr(0x85B3FC, 1029604);
			if (v5 >= *getMemIntPtr(0x85B3FC, 1029604))
				goto LABEL_6;
		}
		result = 0;
	}
	return result;
}

//----- (004CA540) --------------------------------------------------------
int  nox_xxx_sprite_4CA540(_DWORD* a1, int a2) {
	_DWORD* v2; // esi
	double v3;  // st7
	double v4;  // st6
	double v5;  // st5
	double v6;  // st4
	int v7;     // eax
	int v8;     // edi
	int v9;     // eax
	float v11;  // [esp+0h] [ebp-14h]
	float v12;  // [esp+0h] [ebp-14h]
	float v13;  // [esp+10h] [ebp-4h]
	float v14;  // [esp+1Ch] [ebp+8h]

	v2 = (_DWORD*)a2;
	v3 = 0.0;
	v4 = *(float*)(a2 + 468);
	v5 = *(float*)(a2 + 472);
	v6 = 0.0;
	v7 = nox_frame_xxx_2598000 - *(_DWORD*)(a2 + 316) + 1;
	do {
		--v7;
		v13 = -(v5 * *(float*)(a2 + 476));
		v4 = v4 - v4 * *(float*)(a2 + 476);
		v5 = v5 + v13;
		v3 = v3 + v4;
		v6 = v6 + v5;
	} while (v7);
	v14 = v6;
	v11 = (double)(int)v2[81] + v3;
	v8 = nox_float2int(v11);
	v12 = (double)(int)v2[82] + v14;
	v9 = nox_float2int(v12);
	if (v8 > 0 && v9 > 0 && v8 < 5888 && v9 < 5888) {
		nox_xxx_updateSpritePosition_49AA90(v2, v8, v9);
		if (sub_4992B0(*a1 + v2[3] - a1[4], v2[4] + a1[1] - a1[5]))
			return 1;
	}
	nox_xxx_spriteDeleteStatic_45A4E0_drawable((int)v2);
	return 0;
}

//----- (004CA650) --------------------------------------------------------
int  sub_4CA650(int a1, int a2) {
	int v2;               // esi
	int v3;               // eax
	int v4;               // ebx
	int v5;               // edi
	int v6;               // eax
	int v7;               // ecx
	int v8;               // eax
	int v9;               // ebp
	int v10;              // eax
	int v11;              // edi
	unsigned __int16 v12; // dx
	int v13;              // ebp
	int v14;              // eax
	int result;           // eax
	int v16;              // [esp+10h] [ebp-10h]
	int v17;              // [esp+28h] [ebp+8h]

	v2 = a2;
	v3 = *(_DWORD*)(a2 + 16);
	v4 = *(unsigned __int16*)(a2 + 434) - v3;
	v5 = *(unsigned __int16*)(a2 + 432) - *(_DWORD*)(a2 + 12);
	v6 = sub_48C6B0(v5, v4);
	v7 = v6;
	v8 = *(unsigned __int8*)(a2 + 443);
	v17 = v8;
	++v7;
	v9 = *(_DWORD*)(v2 + 12);
	v10 = v5 * v8 / v7;
	v11 = *(_DWORD*)(v2 + 16);
	v16 = v9 + v10;
	v12 = *(_WORD*)(v2 + 432);
	v13 = v9 - v12;
	v14 = v11 + v4 * v17 / v7;
	if (v7 <= 10 ||
		v13 * (v16 - v12) + (v11 - *(unsigned __int16*)(v2 + 434)) * (v14 - *(unsigned __int16*)(v2 + 434)) < 0) {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(v2);
		result = 0;
	} else {
		nox_xxx_updateSpritePosition_49AA90((_DWORD*)v2, v16, v14);
		result = 1;
	}
	return result;
}
// 4CA67E: variable 'v6' is possibly undefined

//----- (004CA720) --------------------------------------------------------
int  sub_4CA720(int a1, int a2) {
	int v2;     // ebx
	int v3;     // ebp
	int v4;     // ecx
	int v5;     // edx
	int v6;     // ebx
	int v7;     // kr00_4
	int v8;     // ebx
	int result; // eax

	v2 = nox_frame_xxx_2598000 - *(_DWORD*)(a2 + 316);
	if (v2 >= 60 || (v3 = *(unsigned __int16*)(a2 + 432), abs32(*(_DWORD*)(a2 + 12) - (unsigned __int16)v3) < 10) &&
						abs32(*(_DWORD*)(a2 + 16) - *(unsigned __int16*)(a2 + 434)) < 10) {
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(a2);
		result = 0;
	} else {
		v4 = *(__int16*)(a2 + 440) - v2 * *(__int16*)(a2 + 440) / 60;
		v5 = (v2 << 8) / 120;
		if (*(_BYTE*)(a2 + 443))
			v6 = v5 + *(unsigned __int8*)(a2 + 442);
		else
			v6 = *(unsigned __int8*)(a2 + 442) - v5;
		if (v6 < 0)
			v6 += (unsigned int)(255 - v6) >> 8 << 8;
		if (v6 >= 256)
			v6 += -256 * ((unsigned int)v6 >> 8);
		v7 = v4 * *getMemIntPtr(0x587000, 192088 + 8 * v6);
		v8 = *(unsigned __int16*)(a2 + 434) + v4 * *getMemU32Ptr(0x587000, 192092 + 8 * v6) / 16;
		nox_xxx_updateSpritePosition_49AA90((_DWORD*)a2, v3 + v7 / 16, v8);
		*(_DWORD*)(a2 + 32) = v3 + v7 / 16;
		*(_DWORD*)(a2 + 36) = v8;
		result = 1;
	}
	return result;
}

//----- (004CA860) --------------------------------------------------------
int sub_4CA860() {
	unsigned __int8* v0; // esi
	__int64 v1;          // rax
	int v3;              // [esp+4h] [ebp-4h]

	v3 = 0;
	v0 = getMemAt(0x5D4594, 1322584);
	do {
		v1 = (__int64)(atan2((double)v3 * *getMemDoublePtr(0x581450, 9960), 1.0) * *getMemDoublePtr(0x581450, 9952) +
					   *(double*)&qword_581450_9544);
		*(_WORD*)v0 = v1;
		v0 += 2;
		++v3;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 1522584));
	return v1;
}

//----- (004CA8B0) --------------------------------------------------------
int  sub_4CA8B0(int a1, int a2) {
	int v2;     // ecx
	int result; // eax
	int v4;     // eax
	int v5;     // eax
	char v6;    // [esp+4h] [ebp+4h]

	v2 = a2;
	if (!a2)
		return a1 <= 0 ? 56250 : 18750;
	v4 = a1;
	if (a2 >= 0) {
		if (a1 >= 0) {
			v6 = 1;
		} else {
			v6 = 4;
			v4 = -v4;
		}
	} else {
		if (a1 >= 0) {
			v6 = 2;
		} else {
			v4 = -a1;
			v6 = 3;
		}
		v2 = -a2;
	}
	v5 = 1000 * v4 / v2;
	if (v5 >= 100000)
		v5 = 99999;
	result = *getMemI16Ptr(0x5D4594, 1322584 + 2 * v5);
	switch (v6) {
	case 2:
		return 37500 - result;
	case 3:
		result += 37500;
		break;
	case 4:
		result = 75000 - result;
		break;
	}
	return result;
}

//----- (004CA960) --------------------------------------------------------
void  sub_4CA960(_DWORD* a1, char a2, float4* a3, float2* a4) {
	int v4;   // eax
	int v5;   // eax
	int v6;   // eax
	int v7;   // eax
	int v8;   // [esp-8h] [ebp-10h]
	int2 a1a; // [esp+0h] [ebp-8h]

	v4 = a1[1];
	a1a.field_0 = 23 * *a1;
	a1a.field_4 = 23 * v4;
	switch (a2) {
	case 1:
		v6 = nox_float2int(11.5);
		sub_4CAA90(&a1a, a3, a4, v6, 23);
		break;
	case 2:
		v5 = nox_float2int(11.5);
		sub_4CAC30(&a1a, a3, a4, 0, v5);
		break;
	case 4:
		v8 = nox_float2int(11.5);
		sub_4CAC30(&a1a, a3, a4, v8, 23);
		break;
	case 6:
		sub_4CAC30(&a1a, a3, a4, 0, 23);
		break;
	case 8:
		v7 = nox_float2int(11.5);
		sub_4CAA90(&a1a, a3, a4, 0, v7);
		break;
	case 9:
		sub_4CAA90(&a1a, a3, a4, 0, 23);
		break;
	default:
		return;
	}
}

//----- (004CAA90) --------------------------------------------------------
void  sub_4CAA90(int2* a1, float4* a2, float2* a3, int a4, int a5) {
	int v5;     // eax
	int v6;     // edx
	double v7;  // st6
	int v8;     // eax
	double v9;  // st7
	double v11; // st7
	double v13; // st7
	double v14; // st5
	double v15; // st7
	double v16; // st7
	double v17; // st7
	float v18;  // [esp+8h] [ebp-24h]
	float v19;  // [esp+Ch] [ebp-20h]
	float v20;  // [esp+10h] [ebp-1Ch]
	double v21; // [esp+14h] [ebp-18h]
	float v22;  // [esp+1Ch] [ebp-10h]
	float v23;  // [esp+24h] [ebp-8h]

	v5 = a5 + a1->field_0;
	v6 = a1->field_4 - a5 + 22;
	v22 = (double)(a1->field_0 + a4);
	v7 = (double)v5;
	v23 = v7;
	v18 = v7 + (double)v6;
	v8 = nox_float2int(v18);
	if (a2->field_8 == a2->field_0) {
		v9 = a2->field_8;
		a3->field_0 = a2->field_8;
		a3->field_4 = (double)v8 - v9;
	} else {
		v11 = a2->field_C;
		if (v11 == a2->field_4) {
			a3->field_4 = a2->field_C;
			a3->field_0 = (double)v8 - v11;
		} else {
			v13 = (v11 - a2->field_4) / (a2->field_8 - a2->field_0);
			if (v13 == -1.0)
				v13 = -0.99000001;
			v14 = (double)v8;
			v20 = v14;
			v15 = nox_double2float((v14 - (a2->field_4 - v13 * a2->field_0)) / (v13 + *(double*)&qword_581450_9512));
			v16 = modf(v15, &v21);
			v19 = nox_double2float(v16);
			v17 = nox_double2float(v21);
			a3->field_0 = v17;
			if (v19 <= *(double*)&qword_581450_9544) {
				if (v19 < *getMemDoublePtr(0x581450, 9968))
					a3->field_0 = v17 - 1.0;
			} else {
				a3->field_0 = v17 + 1.0;
			}
			if (a3->field_0 >= (double)v22) {
				if (a3->field_0 > (double)v23)
					a3->field_0 = v23;
				a3->field_4 = v20 - a3->field_0;
			} else {
				a3->field_0 = v22;
				a3->field_4 = v20 - a3->field_0;
			}
		}
	}
}

//----- (004CAC30) --------------------------------------------------------
void  sub_4CAC30(int2* a1, float4* a2, float2* a3, int a4, int a5) {
	int v5;     // ecx
	int v6;     // eax
	int v7;     // eax
	double v8;  // st7
	double v9;  // st5
	double v10; // st7
	double v11; // st7
	double v12; // st7
	float v13;  // [esp+8h] [ebp-2Ch]
	float v14;  // [esp+14h] [ebp-20h]
	float v15;  // [esp+18h] [ebp-1Ch]
	double v16; // [esp+1Ch] [ebp-18h]
	float v17;  // [esp+24h] [ebp-10h]
	float v18;  // [esp+2Ch] [ebp-8h]

	v5 = a4 + a1->field_4;
	v6 = a5 + a1->field_0;
	v17 = (double)(a1->field_0 + a4);
	v18 = (double)v6;
	v13 = (double)v5 - v17;
	v7 = nox_float2int(v13);
	if (a2->field_8 == a2->field_0) {
		a3->field_0 = a2->field_8;
		a3->field_4 = (double)v7 + a2->field_8;
	} else if (a2->field_C == a2->field_4) {
		a3->field_0 = a2->field_C - (double)v7;
		a3->field_4 = a2->field_C;
	} else {
		v8 = (a2->field_C - a2->field_4) / (a2->field_8 - a2->field_0);
		if (v8 == 1.0)
			v8 = 0.99000001;
		v9 = (double)v7;
		v15 = v9;
		v10 = nox_double2float((v9 - (a2->field_4 - v8 * a2->field_0)) / (v8 - *(double*)&qword_581450_9512));
		v11 = modf(v10, &v16);
		v14 = nox_double2float(v11);
		v12 = nox_double2float(v16);
		a3->field_0 = v12;
		if (v14 <= *(double*)&qword_581450_9544) {
			if (v14 < *getMemDoublePtr(0x581450, 9968))
				a3->field_0 = v12 - 1.0;
		} else {
			a3->field_0 = v12 + 1.0;
		}
		if (a3->field_0 >= (double)v17) {
			if (a3->field_0 > (double)v18)
				a3->field_0 = v18;
			a3->field_4 = v15 + a3->field_0;
		} else {
			a3->field_0 = v17;
			a3->field_4 = v15 + a3->field_0;
		}
	}
}

//----- (004CADD0) --------------------------------------------------------
int sub_4CADD0() {
	int result; // eax
	int v1;     // esi
	_DWORD* v2; // eax

	result = *getMemU32Ptr(0x5D4594, 1522584);
	if (!*getMemU32Ptr(0x5D4594, 1522584)) {
		v1 = 0;
		do {
			v2 = calloc(1u, 0x3Cu);
			if (!v2)
				nox_exit(-1);
			++v1;
			v2[4] = *getMemU32Ptr(0x5D4594, 1522584);
			*getMemU32Ptr(0x5D4594, 1522584) = v2;
			v2[2] = *getMemU32Ptr(0x5D4594, 1522592);
			*getMemU32Ptr(0x5D4594, 1522592) = v2;
		} while (v1 < 10);
		*getMemU32Ptr(0x5D4594, 1522588) += 10;
		result = *getMemU32Ptr(0x5D4594, 1522584);
	}
	*getMemU32Ptr(0x5D4594, 1522584) = *(_DWORD*)(result + 16);
	return result;
}

//----- (004CAE40) --------------------------------------------------------
int  sub_4CAE40(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 16) = *getMemU32Ptr(0x5D4594, 1522584);
	*getMemU32Ptr(0x5D4594, 1522584) = a1;
	return result;
}

//----- (004CAE60) --------------------------------------------------------
int sub_4CAE60() {
	int result; // eax
	int v1;     // ecx

	result = *getMemU32Ptr(0x5D4594, 1522592);
	v1 = 0;
	for (*getMemU32Ptr(0x5D4594, 1522584) = 0; result; result = *(_DWORD*)(result + 8)) {
		*(_DWORD*)(result + 16) = v1;
		v1 = result;
		*getMemU32Ptr(0x5D4594, 1522584) = result;
	}
	return result;
}

//----- (004CAE90) --------------------------------------------------------
int  sub_4CAE90(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 12) = dword_5d4594_1522596;
	dword_5d4594_1522596 = a1;
	return result;
}

//----- (004CAEB0) --------------------------------------------------------
int sub_4CAEB0() {
	int result; // eax

	result = dword_5d4594_1522596;
	if (dword_5d4594_1522596)
		dword_5d4594_1522596 = *(_DWORD*)(dword_5d4594_1522596 + 12);
	return result;
}

//----- (004CAED0) --------------------------------------------------------
int  sub_4CAED0(int a1) {
	int result; // eax

	result = sub_4CADD0();
	*(_DWORD*)(result + 24) = *(_DWORD*)(a1 + 24);
	*(_DWORD*)(result + 28) = *(_DWORD*)(a1 + 28);
	*(_DWORD*)(result + 32) = *(_DWORD*)(a1 + 32);
	*(_BYTE*)(result + 36) = *(_BYTE*)(a1 + 36);
	*(_DWORD*)(result + 40) = *(_DWORD*)(a1 + 40);
	*(_DWORD*)(result + 44) = *(_DWORD*)(a1 + 44);
	*(_BYTE*)(result + 48) = *(_BYTE*)(a1 + 48);
	*(_BYTE*)(result + 56) = *(_BYTE*)(a1 + 56);
	*(_DWORD*)(result + 20) = *(_DWORD*)(a1 + 20);
	return result;
}

//----- (004CAF10) --------------------------------------------------------
nox_window*  nox_gui_newProgressBar_4CAF10(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD* a7) {
	int v7;     // eax
	_DWORD* v8; // esi

	v7 = a7[2];
	if (!(v7 & 0x1000))
		return 0;
	v8 = nox_window_new(a1, a2 & 0xFFFFFFF7, a3, a4, a5, a6, sub_4CAF80);
	sub_4CAFB0((int)v8);
	if (v8) {
		if (!a7[4])
			a7[4] = v8;
		nox_gui_windowCopyDrawData_46AF80((int)v8, a7);
	}
	return v8;
}

//----- (004CAF80) --------------------------------------------------------
int  sub_4CAF80(int a1, int a2, int a3, int a4) {
	if (a2 == 16416 && a3 >= 0 && a3 <= 100)
		*(_DWORD*)(a1 + 32) = a3;
	return 0;
}

//----- (004CAFB0) --------------------------------------------------------
int  sub_4CAFB0(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		if ((signed char)*(_BYTE*)(a1 + 4) >= 0)
			result = nox_window_set_all_funcs((_DWORD*)a1, 0, sub_4CAFF0, 0);
		else
			result = nox_window_set_all_funcs((_DWORD*)a1, 0, sub_4CB1A0, 0);
	}
	return result;
}

//----- (004CAFF0) --------------------------------------------------------
int  sub_4CAFF0(_DWORD* a1, _DWORD* a2) {
	int v2;          // ecx
	int v3;          // ebp
	int v4;          // edi
	int v5;          // edi
	int v6;          // edi
	int v7;          // ebp
	int xLeft;       // [esp+10h] [ebp-98h]
	int yTop;        // [esp+14h] [ebp-94h]
	int v11;         // [esp+18h] [ebp-90h]
	int v12;         // [esp+1Ch] [ebp-8Ch]
	int v13;         // [esp+20h] [ebp-88h]
	int v14;         // [esp+24h] [ebp-84h]
	wchar_t v15[64]; // [esp+28h] [ebp-80h]

	v2 = a2[17];
	v3 = a2[9];
	v14 = a2[7];
	v4 = a2[5];
	v11 = v2;
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop);
	if (v4 != 0x80000000) {
		nox_client_drawSetColor_434460(v4);
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, a1[2], a1[3]);
	}
	if (v3 != 0x80000000) {
		v5 = a1[2] * a1[8] / 100;
		nox_client_drawSetColor_434460(v3);
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, v5, a1[3]);
	}
	if (v11 != 0x80000000) {
		if ((a1[1] & 0x2000) == 0x2000)
			sub_43F670(1);
		nox_swprintf(v15, L"%i%%", a1[8]);
		nox_xxx_drawGetStringSize_43F840(a2[50], v15, &v13, &v12, 64);
		v6 = xLeft + a1[2] / 2 - v13 / 2;
		v7 = a1[3] / 2 - v12 / 2 + yTop + 1;
		nox_xxx_drawSetTextColor_434390(v11);
		nox_xxx_drawString_43FAF0(a2[50], v15, v6, v7, a1[2], 0);
		sub_43F670(0);
	}
	if (v14 != 0x80000000) {
		nox_client_drawSetColor_434460(v14);
		nox_client_drawBorderLines_49CC70(xLeft, yTop, a1[2], a1[3]);
	}
	return 1;
}

//----- (004CB1A0) --------------------------------------------------------
int  sub_4CB1A0(_DWORD* a1, int a2) {
	int v2;     // ebx
	_DWORD* v3; // esi
	int v4;     // edi
	int xLeft;  // [esp+Ch] [ebp-8h]
	int yTop;   // [esp+10h] [ebp-4h]

	v2 = *(_DWORD*)(a2 + 24);
	v3 = a1;
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop);
	nox_xxx_wndDraw_49F7F0();
	v4 = v3[2] * v3[8] / 100;
	nox_client_copyRect_49F6F0(xLeft, yTop, v4, v3[3]);
	if (v2 && v4 > 0)
		nox_client_drawImageAt_47D2C0(v2, xLeft, yTop);
	sub_49F860();
	return 1;
}

//----- (004CB230) --------------------------------------------------------
BOOL  nox_game_setMovieFile_4CB230(const char* a1, char* lpFileName) // setmoviefile
{
	char* v3;        // eax
	struct _stat v4; // [esp+10h] [ebp-24h]

	strcpy(lpFileName, "movies\\");
	strcat(lpFileName, a1);
	if (!_stat(lpFileName, (int)&v4))
		return 1;
	v3 = sub_413890();
	if (!v3)
		return 0;
	strcpy(lpFileName, v3);
	strcat(lpFileName, "movies\\");
	strcat(lpFileName, a1);
	return _stat(lpFileName, (int)&v4) == 0;
}

#ifndef NOX_CGO
//----- (004CB330) --------------------------------------------------------
void nox_client_advVideoOptsLoad_4CB330() {
	_DWORD* v0;       // eax
	int v1;           // ecx
	unsigned int v2;  // ecx
	_DWORD* v3;       // eax
	int v4;           // ecx
	unsigned int v5;  // ecx
	_DWORD* v6;       // eax
	int v7;           // ecx
	unsigned int v8;  // ecx
	_DWORD* v9;       // eax
	int v10;          // ecx
	unsigned int v11; // ecx
	_DWORD* v12;      // eax
	int v13;          // ecx
	unsigned int v14; // ecx
	_DWORD* v15;      // eax
	int v16;          // ecx
	unsigned int v17; // ecx
	_DWORD* v18;      // eax
	int v19;          // ecx
	unsigned int v20; // ecx
	_DWORD* v21;      // eax
	int v22;          // ecx
	unsigned int v23; // ecx
	_DWORD* v24;      // eax
	int v25;          // ecx
	unsigned int v26; // ecx
	_DWORD* v27;      // eax
	int v28;          // ecx
	unsigned int v29; // ecx
	_DWORD* v30;      // eax
	int v31;          // ecx
	unsigned int v32; // ecx
	_DWORD* v33;      // eax
	int v34;          // ecx
	unsigned int v35; // ecx
	_DWORD* v36;      // eax
	int v37;          // ecx
	unsigned int v38; // ecx
	_DWORD* result;   // eax
	int v40;          // ecx

	v0 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2010);
	v1 = v0[9];
	if (nox_video_dxUnlockSurface)
		v2 = v1 | 4;
	else
		v2 = v1 & 0xFFFFFFFB;
	v0[9] = v2;
	v3 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2012);
	v4 = v3[9];
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE))
		v5 = v4 | 4;
	else
		v5 = v4 & 0xFFFFFFFB;
	v3[9] = v5;
	v6 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2020);
	v7 = v6[9];
	if (nox_client_drawFrontWalls_80812)
		v8 = v7 | 4;
	else
		v8 = v7 & 0xFFFFFFFB;
	v6[9] = v8;
	v9 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2021);
	v10 = v9[9];
	if (nox_client_translucentFrontWalls_805844)
		v11 = v10 | 4;
	else
		v11 = v10 & 0xFFFFFFFB;
	v9[9] = v11;
	v12 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2022);
	v13 = v12[9];
	if (nox_client_highResFrontWalls_80820)
		v14 = v13 | 4;
	else
		v14 = v13 & 0xFFFFFFFB;
	v12[9] = v14;
	v15 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2031);
	v16 = v15[9];
	if (nox_client_highResFloors_154952)
		v17 = v16 | 4;
	else
		v17 = v16 & 0xFFFFFFFB;
	v15[9] = v17;
	v18 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2032);
	v19 = v18[9];
	if (nox_client_lockHighResFloors_1193152)
		v20 = v19 | 4;
	else
		v20 = v19 & 0xFFFFFFFB;
	v18[9] = v20;
	v21 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2014);
	v22 = v21[9];
	if (nox_gui_console_translucent)
		v23 = v22 | 4;
	else
		v23 = v22 & 0xFFFFFFFB;
	v21[9] = v23;
	v24 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2015);
	v25 = v24[9];
	if (nox_client_renderGlow_805852)
		v26 = v25 | 4;
	else
		v26 = v25 & 0xFFFFFFFB;
	v24[9] = v26;
	v27 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2040);
	v28 = v27[9];
	if (nox_client_renderGUI_80828)
		v29 = v28 | 4;
	else
		v29 = v28 & 0xFFFFFFFB;
	v27[9] = v29;
	v30 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2016);
	v31 = v30[9];
	if (nox_client_fadeObjects_80836)
		v32 = v31 | 4;
	else
		v32 = v31 & 0xFFFFFFFB;
	v30[9] = v32;
	v33 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2017);
	v34 = v33[9];
	if (nox_client_showTooltips_80840)
		v35 = v34 | 4;
	else
		v35 = v34 & 0xFFFFFFFB;
	v33[9] = v35;
	v36 = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2041);
	v37 = v36[9];
	if (nox_client_renderBubbles_80844)
		v38 = v37 | 4;
	else
		v38 = v37 & 0xFFFFFFFB;
	v36[9] = v38;
	result = nox_xxx_wndGetChildByID_46B0C0(nox_win_advVideoOpts_1522600, 2033);
	v40 = result[9];
	if (nox_client_texturedFloors2_154960)
		result[9] = v40 | 4;
	else
		result[9] = v40 & 0xFFFFFFFB;
}

//----- (004CB590) --------------------------------------------------------
int  nox_client_advVideoOpts_New_4CB590(nox_window* a1) {
	nox_win_advVideoOpts_1522600 = nox_new_window_from_file("advidopt.wnd", nox_client_advVideoOptsProc_4CB5D0);
	sub_46B120(nox_win_advVideoOpts_1522600, a1);
	nox_xxx_wndRetNULL_46A8A0();
	nox_client_advVideoOptsLoad_4CB330();
	return 1;
}

//----- (004CB5D0) --------------------------------------------------------
int  nox_client_advVideoOptsProc_4CB5D0(void* a1p, int a2, void* a3p, int a4) {
	int a1 = a1p;
	int* a3 = a3p;
	int v3;          // esi
	int v4;          // eax
	int result;      // eax
	int v6;          // ecx
	unsigned int v7; // ecx
	int v8;          // eax

	if (a2 == 16389) {
		nox_xxx_clientPlaySoundSpecial_452D80(920, 100);
		result = 1;
	} else if (a2 == 16391) {
		v3 = nox_xxx_wndGetID_46B0A0(a3);
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
		switch (v3) {
		case 2010:
			nox_video_dxUnlockSurface = nox_video_checkIsWinNT_48A1D0(1 - nox_video_dxUnlockSurface);
			v6 = *(_DWORD*)(a1 + 36);
			if (nox_video_dxUnlockSurface)
				v7 = v6 | 4;
			else
				v7 = v6 & 0xFFFFFFFB;
			*(_DWORD*)(a1 + 36) = v7;
			result = 0;
			break;
		case 2012:
			nox_common_toggleEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
			result = 0;
			break;
		case 2014:
			nox_gui_console_translucent = 1 - nox_gui_console_translucent;
			result = 0;
			break;
		case 2015:
			result = 0;
			nox_client_renderGlow_805852 = 1 - nox_client_renderGlow_805852;
			break;
		case 2016:
			result = 0;
			nox_client_fadeObjects_80836 = 1 - nox_client_fadeObjects_80836;
			break;
		case 2017:
			nox_client_showTooltips_80840 = 1 - nox_client_showTooltips_80840;
			result = 0;
			break;
		case 2020:
			nox_client_drawFrontWalls_80812 = 1 - nox_client_drawFrontWalls_80812;
			sub_49B3C0();
			result = 0;
			break;
		case 2021:
			result = 0;
			nox_client_translucentFrontWalls_805844 = 1 - nox_client_translucentFrontWalls_805844;
			break;
		case 2022:
			nox_client_highResFrontWalls_80820 = 1 - nox_client_highResFrontWalls_80820;
			result = 0;
			break;
		case 2031:
			result = 0;
			nox_client_highResFloors_154952 = 1 - nox_client_highResFloors_154952;
			break;
		case 2032:
			result = 0;
			nox_client_lockHighResFloors_1193152 = 1 - nox_client_lockHighResFloors_1193152;
			break;
		case 2033:
			nox_client_texturedFloors2_154960 = 1 - nox_client_texturedFloors2_154960;
			nox_client_texturedFloors_154956 = nox_client_texturedFloors2_154960;
			nox_xxx_tileSetDrawFn_481420();
			dword_5d4594_1193156 = 0;
			result = 0;
			break;
		case 2040:
			v8 = 1 - nox_client_renderGUI_80828;
			nox_client_renderGUI_80828 = v8;
			nox_xxx_xxxRenderGUI_587000_80832 = v8;
			result = 0;
			break;
		case 2041:
			nox_client_renderBubbles_80844 = 1 - nox_client_renderBubbles_80844;
			goto LABEL_23;
		case 2099:
			nox_setProfiledMode_4445C0();
			nox_client_advVideoOptsLoad_4CB330();
			v4 = *(_DWORD*)(a1 + 396);
			if (!v4)
				goto LABEL_23;
			nox_window_call_field_94(v4, 16391, (int)a3, 0);
			result = 0;
			break;
		default:
			goto LABEL_23;
		}
	} else {
	LABEL_23:
		result = 0;
	}
	return result;
}
#endif // NOX_CGO

//----- (004CB880) --------------------------------------------------------
int sub_4CB880() {
	int result;  // eax
	_DWORD** v1; // eax
	_DWORD* v2;  // esi
	_DWORD* v3;  // esi
	int v4;      // esi
	int v5;      // edi
	_DWORD* v6;  // eax
	int v7;      // eax
	_DWORD* v8;  // eax
	_DWORD* v9;  // eax

	nox_game_addStateCode_43BDD0(900);
	result = nox_new_window_from_file("InputCfg.wnd", sub_4CBE70);
	dword_5d4594_1522604 = result;
	if (result) {
		nox_xxx_wndSetWindowProc_46B300(result, sub_4A18E0);
		result = nox_gui_makeAnimation_43C5B0(*(_DWORD**)&dword_5d4594_1522604, 0, 0, 0, -480, 0, 20, 0, -40);
		nox_wnd_xxx_1522608 = result;
		if (result) {
			nox_wnd_xxx_1522608->field_0 = 900;
			nox_wnd_xxx_1522608->field_12 = sub_4CBB70;
			nox_wnd_xxx_1522608->fnc_done_out = sub_4CBBB0;
			dword_5d4594_1522616 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1522604, 910);
			dword_5d4594_1522620 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1522604, 911);
			dword_5d4594_1522624 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1522604, 912);
			dword_5d4594_1522628 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1522604, 913);
			result = dword_5d4594_1522616;
			if (dword_5d4594_1522616) {
				v1 = *(_DWORD***)((_DWORD)dword_5d4594_1522616 + 32);
				*v1[7] = 921;
				*v1[8] = 922;
				*v1[9] = 920;
				nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1522616, sub_4CBF60);
				sub_46B120(*(_DWORD**)&dword_5d4594_1522620, *(int*)&dword_5d4594_1522616);
				sub_46B120(*(_DWORD**)&dword_5d4594_1522624, *(int*)&dword_5d4594_1522616);
				sub_46B120(*(_DWORD**)&dword_5d4594_1522628, *(int*)&dword_5d4594_1522616);
				nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1522624, sub_4CC140);
				nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1522628, sub_4CC140);
				v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1522604, 921);
				nox_window_call_field_94(*(int*)&dword_5d4594_1522620, 16408, (int)v2, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16408, (int)v2, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16408, (int)v2, 0);
				v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1522604, 922);
				nox_window_call_field_94(*(int*)&dword_5d4594_1522620, 16409, (int)v3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16409, (int)v3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16409, (int)v3, 0);
				sub_4CBBF0();
				v4 = 971;
				v5 = sub_47DBC0() + 971;
				if (v5 > 971) {
					do {
						v6 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1522604, v4);
						nox_xxx_wnd_46ABB0((int)v6, 1);
						++v4;
					} while (v4 < v5);
				}
				v7 = nox_client_mousePriKey_430AF0();
				v8 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1522604, v7 + 971);
				nox_window_call_field_94((int)v8, 16392, 1, 0);
				dword_5d4594_1522612 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1522604, 980);
				sub_46B120(*(_DWORD**)&dword_5d4594_1522612, 0);
				nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1522612, sub_4CBE70);
				nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1522612, sub_4CC170);
				nox_window_set_hidden(*(int*)&dword_5d4594_1522612, 1);
				v9 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1522612, 981);
				sub_46AEE0((int)v9, (int)getMemAt(0x5D4594, 1522636));
				result = 1;
			}
		}
	}
	return result;
}
// 4A18E0: using guessed type int  sub_4A18E0(int, int, int, int);

//----- (004CBB70) --------------------------------------------------------
int sub_4CBB70() {
	sub_4CBD30();
	nox_common_writecfgfile("nox.cfg");
	nox_wnd_xxx_1522608->state = NOX_GUI_ANIM_OUT;
	sub_43BE40(2);
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100);
	return 1;
}

//----- (004CBBB0) --------------------------------------------------------
int sub_4CBBB0() {
	int (*v0)(void); // esi

	v0 = nox_wnd_xxx_1522608->field_13;
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_1522608);
	nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1522604);
	nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1522612);
	v0();
	return 1;
}

//----- (004CBBF0) --------------------------------------------------------
#ifndef NOX_CGO
void sub_4CBBF0() {
	nox_window_call_field_94(*(int*)&dword_5d4594_1522616, 16399, 0, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1522620, 16399, 0, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16399, 0, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16399, 0, 0);
	for (int i = 1; i < NOX_BINDEVENT_MAX; i++) {
		nox_bindevent_t* ev = &nox_bindevent_arr[i];
		if (ev->key == 44) {
			continue;
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_1522620, 16397, ev->title, -1);
		nox_window_call_field_94(*(int*)&dword_5d4594_1522616, 16397, (int)getMemAt(0x587000, 187544), -1);
		char* v2 = sub_42E8E0(ev->key, 1);
		char* v3 = sub_42E8E0(ev->key, 2);
		if (v2 && *(_WORD*)v2) {
			nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16397, (int)v2, -1);
		} else {
			nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16397, (int)getMemAt(0x587000, 187548), -1);
		}
		if (v3 && *(_WORD*)v3 && v2 != v3) {
			nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16397, (int)v3, -1);
		} else {
			nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16397, (int)getMemAt(0x587000, 187552), -1);
		}
	}
}
#endif // NOX_CGO

//----- (004CBE70) --------------------------------------------------------
int  sub_4CBE70(int a1, int a2, int* a3, int a4) {
	int v3;     // esi
	int result; // eax

	if (a2 == 23)
		return 1;
	if (a2 != 16391)
		return 0;
	v3 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
	switch (v3) {
	case 931:
		sub_42CD90();
		nox_common_readcfgfile("nox.cfg", 1);
		sub_4CBBF0();
		result = 0;
		break;
	case 932:
		sub_4CBD30();
		result = 0;
		break;
	case 933:
		sub_4CBF40();
		result = 0;
		break;
	case 971:
	case 972:
	case 973:
		sub_430AA0(v3 - 971);
		return 0;
	default:
		return 0;
	}
	return result;
}

//----- (004CBF40) --------------------------------------------------------
#ifndef NOX_CGO
void sub_4CBF40() {
	sub_42CD90();
	nox_common_readcfgfile("default.cfg", 1);
	sub_4CBBF0();
}
#endif // NOX_CGO

//----- (004CC140) --------------------------------------------------------
int  sub_4CC140(_DWORD* a1, unsigned int a2, unsigned int a3, int a4) {
	int result; // eax

	if (a2 < 0x13 || a2 > 0x14)
		result = nox_xxx_wndListboxProcWithoutData10_4A28E0(a1, a2, a3, a4);
	else
		result = 0;
	return result;
}

//----- (004CC170) --------------------------------------------------------
int  sub_4CC170(int a1, int a2, char* a3, int a4) {
	int result; // eax

	switch (a2) {
	case 6:
	case 7:
		goto LABEL_10;
	case 10:
	case 11:
		sub_4CC3C0(0x10002);
		goto LABEL_15;
	case 14:
	case 15:
		sub_4CC3C0(0x10001);
		goto LABEL_15;
	case 19:
		sub_4CC3C0(0x10003);
		goto LABEL_15;
	case 20:
		sub_4CC3C0(0x10004);
		goto LABEL_15;
	case 21:
		if (a3 == (char*)1) {
			if (a4 == 2) {
				nox_xxx_windowFocus_46B500(0);
				nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_1522612);
				nox_window_set_hidden(*(int*)&dword_5d4594_1522612, 1);
				if (dword_5d4594_1522632)
					nox_window_call_field_94(*(int*)&dword_5d4594_1522632, 16403, -1, 0);
			}
			result = 1;
		} else if (a4 == 1 && sub_4CC280(a3)) {
		LABEL_10:
			sub_4CC3C0(0x10000);
		LABEL_15:
			nox_xxx_windowFocus_46B500(0);
			nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_1522612);
			nox_window_set_hidden(*(int*)&dword_5d4594_1522612, 1);
			result = 1;
		} else {
		LABEL_5:
			result = 0;
		}
		return result;
	default:
		goto LABEL_5;
	}
}

//----- (004CC280) --------------------------------------------------------
int  sub_4CC280(unsigned int a1) {
	const wchar_t* v6 = nox_xxx_keybind_titleByKeyZero_42EA00(a1);
	if (!v6) {
		return 0;
	}
	if (!dword_5d4594_1522632) {
		return 1;
	}
	int v7 = 0;
	int v8 = *(_DWORD*)((_DWORD)dword_5d4594_1522624 + 32);
	if (*(_WORD*)(v8 + 44) > 0) {
		do {
			const wchar_t* v9 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16406, v7, 0);
			if (!nox_wcscmp(v9, v6))
				nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16407, (int)getMemAt(0x587000, 187824), v7);
			++v7;
		} while (v7 < *(__int16*)(v8 + 44));
	}
	int v10 = 0;
	int v11 = *(_DWORD*)((_DWORD)dword_5d4594_1522628 + 32);
	if (*(_WORD*)(v11 + 44) > 0) {
		do {
			const wchar_t* v12 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16406, v10, 0);
			if (!nox_wcscmp(v12, v6))
				nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16407, (int)getMemAt(0x587000, 187828), v10);
			++v10;
		} while (v10 < *(__int16*)(v11 + 44));
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_1522632, 16407, (int)v6, *(_DWORD*)(*(_DWORD*)(dword_5d4594_1522632 + 32) + 48));
	nox_window_call_field_94(*(int*)&dword_5d4594_1522632, 16403, -1, 0);
	dword_5d4594_1522632 = 0;
	return 1;
}

//----- (004CC3C0) --------------------------------------------------------
int  sub_4CC3C0(unsigned int a1) {
	char* v1;          // edi
	int v2;            // esi
	int v3;            // ebx
	const wchar_t* v4; // eax
	int v5;            // esi
	int v6;            // ebx
	const wchar_t* v7; // eax

	v1 = nox_xxx_keybind_titleByKey_42EA00(a1);
	if (!dword_5d4594_1522632)
		return 1;
	v2 = 0;
	v3 = *(_DWORD*)((_DWORD)dword_5d4594_1522624 + 32);
	if (*(_WORD*)(v3 + 44) > 0) {
		do {
			v4 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16406, v2, 0);
			if (!nox_wcscmp(v4, (const wchar_t*)v1))
				nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16407, (int)getMemAt(0x587000, 187832), v2);
			++v2;
		} while (v2 < *(__int16*)(v3 + 44));
	}
	v5 = 0;
	v6 = *(_DWORD*)((_DWORD)dword_5d4594_1522628 + 32);
	if (*(_WORD*)(v6 + 44) > 0) {
		do {
			v7 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16406, v5, 0);
			if (!nox_wcscmp(v7, (const wchar_t*)v1))
				nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16407, (int)getMemAt(0x587000, 187836), v5);
			++v5;
		} while (v5 < *(__int16*)(v6 + 44));
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_1522632, 16407, (int)v1,
							 *(_DWORD*)(*(_DWORD*)(dword_5d4594_1522632 + 32) + 48));
	nox_window_call_field_94(*(int*)&dword_5d4594_1522632, 16403, -1, 0);
	dword_5d4594_1522632 = 0;
	return 1;
}

//----- (004CC4E0) --------------------------------------------------------
#ifdef NOX_CGO
void nox_client_onShowLegal(nox_window* win);
#endif // NOX_CGO
int nox_game_showLegal_4CC4E0() // display legal window
{
	_DWORD* v0;           // esi
	int v1;               // eax
	_DWORD* v2;           // esi
	wchar_t* v3;          // eax
	_DWORD* v4;           // esi
	_DWORD* v5;           // eax
	_DWORD* v6;           // eax
	unsigned __int16* v8; // [esp-10h] [ebp-28h]
	int v9;               // [esp+4h] [ebp-14h]
	char v10[16];         // [esp+8h] [ebp-10h]

	nox_win_legalBg_1522892 = nox_new_window_from_file("legal.wnd", nox_xxx_windowMainBGProc_4CC6A0);
	nox_window_set_all_funcs(nox_win_legalBg_1522892, sub_4CC660, 0, 0);
	nox_xxx_wndShowModalMB_46A8C0(nox_win_legalBg_1522892);
	v0 = nox_xxx_wndGetChildByID_46B0C0(nox_win_legalBg_1522892, 9980);
	v8 = (unsigned __int16*)sub_46AF00((int)v0);
	v1 = sub_46AF40((int)v0);
	nox_xxx_drawGetStringSize_43F840(v1, v8, 0, &v9, 640);
	nox_window_setPos_46A9B0(v0, 0, 477 - v9);
	v2 = nox_xxx_wndGetChildByID_46B0C0(nox_win_legalBg_1522892, 9999);
	v3 = nox_xxx_getNoxVer_401020();
	nox_window_call_field_94((int)v2, 16385, (int)v3, 0);
	v4 = nox_xxx_wndGetChildByID_46B0C0(nox_win_legalBg_1522892, 9998);
	if (!nox_readHiddenCode_4145F0(v10))
		v10[0] = 0;
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1522896), L"%S", v10);
	nox_window_call_field_94((int)v4, 16385, (int)getMemAt(0x5D4594, 1522896), 0);
	v5 = nox_xxx_wndGetChildByID_46B0C0(nox_win_legalBg_1522892, 9970);
	nox_xxx_wndSetDrawFn_46B340((int)v5, sub_4CC6F0);
	*getMemU16Ptr(0x5D4594, 1522928) = 300;
	nox_xxx_wndRetNULL_46A8A0();
	if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
		v6 = nox_xxx_wndGetChildByID_46B0C0(nox_win_legalBg_1522892, 9901);
		nox_window_call_field_94(nox_win_legalBg_1522892, 16391, (int)v6, 0);
	}
	sub_43D9B0(14, 100);
#ifdef NOX_CGO
	nox_client_onShowLegal(nox_win_legalBg_1522892);
#endif // NOX_CGO
	return 1;
}

//----- (004CC660) --------------------------------------------------------
int  sub_4CC660(_DWORD* a1, int a2, int a3, int a4) {
	if (*getMemU16Ptr(0x5D4594, 1522928) <= 270) {
		if (a2 != 21)
			return 0;
		if (a4 == 2) {
			nox_xxx_windowDestroyMB_46C4E0(a1);
			nox_game_showMainMenu_4A1C00();
		}
	}
	return 1;
}

//----- (004CC6A0) --------------------------------------------------------
int  nox_xxx_windowMainBGProc_4CC6A0(_DWORD* a1, int a2, int* a3, int a4) {
	if (*getMemU16Ptr(0x5D4594, 1522928) <= 270) {
		if (a2 != 16391)
			return 0;
		if (nox_xxx_wndGetID_46B0A0(a3) == 9901) {
			nox_xxx_windowDestroyMB_46C4E0(a1);
			nox_game_showMainMenu_4A1C00();
		}
	}
	return 1;
}

//----- (004CC6F0) --------------------------------------------------------
int sub_4CC6F0(int a1, int a2) {
	_DWORD* v0; // eax

	if (--*getMemI16Ptr(0x5D4594, 1522928) < 0) {
		nox_xxx_windowDestroyMB_46C4E0(nox_win_legalBg_1522892);
		nox_game_showMainMenu_4A1C00();
	}
	if (*getMemI16Ptr(0x5D4594, 1522928) < 270) {
		v0 = nox_xxx_wndGetChildByID_46B0C0(nox_win_legalBg_1522892, 9910);
		nox_window_set_hidden((int)v0, 0);
	}
	nox_set_color_rgb_4343B0(150, 150, 150);
	nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x587000, 187860), 500, 150);
	return 1;
}

//----- (004CC770) --------------------------------------------------------
int nox_xxx_gameDownloadShowDialog_4CC770() {
	int v0; // ecx
	int v1; // eax
	int v3; // [esp+0h] [ebp-14h]
	int v4; // [esp+4h] [ebp-10h]
	int v5; // [esp+8h] [ebp-Ch]
	int v6; // [esp+Ch] [ebp-8h]
	int v7; // [esp+10h] [ebp-4h]

	dword_5d4594_1522932 = nox_new_window_from_file("mapdnld.wnd", nox_xxx_guiDownloadProc_4CC890);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1522932, nox_xxx_guiDownloadAbort_4CC830, 0, 0);
	nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(&v3, &v4, &v7);
	nox_xxx_screenGetSize_430C50_get_video_max(&v5, &v6);
	v0 = v3;
	if (v3 > v5) {
		v0 = v5;
		v3 = v5;
	}
	v1 = v4;
	if (v4 > v6) {
		v1 = v6;
		v4 = v6;
	}
	nox_window_setPos_46A9B0(*(_DWORD**)&dword_5d4594_1522932, (v0 - 1024) / 2, (v1 - 768) / 2);
	nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1522932);
	nox_xxx_wndRetNULL_46A8A0();
	return 1;
}

//----- (004CC830) --------------------------------------------------------
int  nox_xxx_guiDownloadAbort_4CC830(int a1, int a2, int a3, int a4) {
	if (a2 != 21)
		return 0;
	if (a3 != 1)
		return 0;
	if (a4 == 2) {
		nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
		nox_xxx_guiDownloadClose_4CC930();
		nox_xxx_gameSetMapPath_409D70((char*)getMemAt(0x5D4594, 1522936));
		nox_xxx_cliCancelMapDownload_4ABA90();
		nox_xxx_mapSetDownloadInProgress_4AB560(0);
		nox_xxx_mapSetDownloadOK_4AB570(0);
		nox_common_gameFlags_unset_40A540(9437184);
	}
	return 1;
}

//----- (004CC890) --------------------------------------------------------
int  nox_xxx_guiDownloadProc_4CC890(int a1, int a2, int* a3, int a4) {
	int v3; // esi

	if (a2 != 16391)
		return 0;
	v3 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	if (v3 != 1601)
		return 0;
	nox_xxx_guiDownloadClose_4CC930();
	nox_xxx_cliCancelMapDownload_4ABA90();
	nox_xxx_gameSetMapPath_409D70((char*)getMemAt(0x5D4594, 1522940));
	nox_xxx_mapSetDownloadInProgress_4AB560(0);
	nox_xxx_mapSetDownloadOK_4AB570(0);
	nox_common_gameFlags_unset_40A540(9437184);
	return 1;
}

//----- (004CC900) --------------------------------------------------------
int  nox_xxx_guiDownloadSetPercent_4CC900(unsigned __int8 a1) {
	_DWORD* v1; // eax

	v1 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1522932, 1603);
	return nox_window_call_field_94((int)v1, 16416, a1, 0);
}

//----- (004CC930) --------------------------------------------------------
int nox_xxx_guiDownloadClose_4CC930() {
	int result; // eax

	result = dword_5d4594_1522932;
	if (dword_5d4594_1522932)
		result = nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_1522932);
	dword_5d4594_1522932 = 0;
	return result;
}

//----- (004CCCF0) --------------------------------------------------------
int nox_xxx_updDrawUndeadKiller_4CCCF0() { return 1; }

//----- (004CCD00) --------------------------------------------------------
int  sub_4CCD00(int a1, int a2) {
	unsigned int i; // ecx

	for (i = *(_DWORD*)(a2 + 432); i < nox_frame_xxx_2598000; ++i) {
		if (*(float*)(a2 + 436) > 0.0) {
			*(float*)(a2 + 436) = *(float*)(a2 + 440) + *(float*)(a2 + 436);
			*(float*)(a2 + 440) = *(float*)(a2 + 440) - 1.0;
		}
		if (*(float*)(a2 + 436) <= 0.0) {
			*(_DWORD*)(a2 + 436) = 0;
			*(_DWORD*)(a2 + 440) = 0;
		}
	}
	*(_WORD*)(a2 + 104) = (__int64)*(float*)(a2 + 436);
	*(_BYTE*)(a2 + 296) = (__int64)*(float*)(a2 + 440);
	*(_DWORD*)(a2 + 432) = nox_frame_xxx_2598000;
	return 1;
}

//----- (004CCDB0) --------------------------------------------------------
int  nox_xxx_updDrawFist_4CCDB0(int a1, int a2) {
	unsigned int i; // edx
	double v3;      // st7
	double v4;      // st7
	double v5;      // st7

	for (i = *(_DWORD*)(a2 + 432); i < nox_frame_xxx_2598000; ++i) {
		v3 = *(float*)(a2 + 436) + *(float*)(a2 + 440);
		*(float*)(a2 + 436) = v3;
		if (v3 >= 0.0) {
			*(float*)(a2 + 440) = *(float*)(a2 + 440) - 0.5;
		} else {
			v4 = -*(float*)(a2 + 440) * *(float*)(a2 + 444);
			*(_DWORD*)(a2 + 436) = 0;
			v5 = v4 * 0.1;
			*(float*)(a2 + 440) = v5;
			if (v5 < 2.0) {
				*(_DWORD*)(a2 + 436) = 0;
				*(_DWORD*)(a2 + 440) = 0;
			}
		}
	}
	*(_WORD*)(a2 + 104) = (__int64)*(float*)(a2 + 436);
	*(_BYTE*)(a2 + 296) = (__int64)*(float*)(a2 + 440);
	*(_DWORD*)(a2 + 432) = nox_frame_xxx_2598000;
	return 1;
}

//----- (004CCE70) --------------------------------------------------------
int  sub_4CCE70(int a1, _DWORD* a2) {
	if (!a2[120] && !nox_xxx_checkGameFlagPause_413A50())
		sub_4CCEA0(a2, 5);
	return 1;
}

//----- (004CD090) --------------------------------------------------------
int  sub_4CD090(int a1, _DWORD* a2) {
	if (!a2[120] && !nox_xxx_checkGameFlagPause_413A50())
		sub_4CCEA0(a2, 4);
	return 1;
}

//----- (004CD0C0) --------------------------------------------------------
int  sub_4CD0C0(int a1, _DWORD* a2) {
	if (!a2[120] && !nox_xxx_checkGameFlagPause_413A50())
		sub_4CCEA0(a2, 3);
	return 1;
}

//----- (004CD0F0) --------------------------------------------------------
int  sub_4CD0F0(int a1, _DWORD* a2) {
	if (!a2[120] && !nox_xxx_checkGameFlagPause_413A50())
		sub_4CCEA0(a2, 2);
	return 1;
}

//----- (004CD120) --------------------------------------------------------
int  sub_4CD120(int a1, _DWORD* a2) {
	if (!a2[120] && !nox_xxx_checkGameFlagPause_413A50())
		sub_4CCEA0(a2, 1);
	return 1;
}

// 4CD249: variable 'v11' is possibly undefined
// 4CD25A: variable 'v13' is possibly undefined
// 4CD27E: variable 'v15' is possibly undefined
// 4CD28F: variable 'v16' is possibly undefined

//----- (004CD400) --------------------------------------------------------
int  sub_4CD400(_DWORD* a1, int a2) {
	int v2; // eax

	v2 = dword_5d4594_1522968;
	if (!dword_5d4594_1522968) {
		v2 = nox_xxx_getTTByNameSpriteMB_44CFC0("CharmOrb");
		dword_5d4594_1522968 = v2;
	}
	sub_4CD150(v2, a1, a2, 1);
	sub_4CD150(*(int*)&dword_5d4594_1522968, a1, a2, 0);
	return 1;
}

// 4CD516: variable 'v5' is possibly undefined
// 4CD527: variable 'v7' is possibly undefined
// 4CD54B: variable 'v9' is possibly undefined
// 4CD55C: variable 'v11' is possibly undefined
