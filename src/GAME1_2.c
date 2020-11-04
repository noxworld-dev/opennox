#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "client/audio/auddiag.h"
#include "client/system/parsecmd.h"
#include "common/system/settings.h"
#include "common/system/team.h"

#include "client/drawable/drawdb.h"
#include "client/gui/gamewin/gamewin.h"
#include "client/gui/guiggovr.h"
#include "client/gui/guiquit.h"
#include "client/shell/noxworld.h"
#include "client/shell/selchar.h"
#include "client/system/client.h"
#include "client/system/ctrlevnt.h"
#include "common/magic/comguide.h"

#include "client/draw/partscrn.h"

#include "proto.h"

extern unsigned char byte_5D4594_3804364[160];

extern _DWORD dword_5d4594_787188;
extern _DWORD dword_587000_80772;
extern _DWORD dword_5d4594_811904;
extern _DWORD dword_5d4594_805988;
extern _DWORD dword_5d4594_3805492;
extern _DWORD nox_profiled_805856;
extern _DWORD dword_5d4594_754048;
extern _DWORD dword_5d4594_811896;
extern _DWORD dword_5d4594_805820;
extern _DWORD dword_5d4594_741648;
extern _DWORD dword_5d4594_815060;
extern _DWORD dword_5d4594_815052;
extern _DWORD dword_5d4594_805980;
extern _DWORD dword_5d4594_741652;
extern _DWORD dword_5d4594_787192;
extern _DWORD nox_server_kickQuestPlayerMinVotes_229992;
extern _DWORD dword_5d4594_3807116;
extern _DWORD nox_server_resetQuestMinVotes_229988;
extern _DWORD nox_server_sendMotd_108752;
extern _DWORD dword_5d4594_787224;
extern _DWORD dword_5d4594_754144;
extern _DWORD dword_5d4594_810628;
extern _DWORD dword_5d4594_808564;
extern _DWORD dword_5d4594_741680;
extern _DWORD dword_5d4594_1193336;
extern _DWORD dword_5d4594_811072;
extern _DWORD dword_5d4594_3807152;
extern _DWORD dword_5d4594_3807136;
extern _DWORD dword_5d4594_3805484;
extern _DWORD nox_server_sanctuaryHelp_54276;
extern _DWORD dword_5d4594_814548;
extern _DWORD dword_5d4594_3804684;
extern _DWORD dword_5d4594_1193156;
extern _DWORD dword_587000_80800;
extern _DWORD dword_5d4594_3807140;
extern _DWORD dword_5d4594_814552;
extern _DWORD dword_5d4594_815056;
extern _DWORD dword_5d4594_811100;
extern _DWORD dword_5d4594_808568;
extern _DWORD dword_5d4594_787184;
extern _DWORD dword_5d4594_2660032;
extern _DWORD dword_5d4594_1556112;
extern _DWORD dword_5d4594_754044;
extern _DWORD dword_5d4594_811372;
extern _DWORD dword_5d4594_787200;
extern _DWORD dword_5d4594_787180;
extern _DWORD dword_5d4594_787144;
extern _DWORD dword_5d4594_741356;
extern _DWORD dword_587000_154960;
extern _DWORD dword_5d4594_741332;
extern _DWORD dword_5d4594_741364;
extern _DWORD dword_5d4594_787212;
extern _DWORD dword_5d4594_811104;
extern _DWORD nox_client_renderBubbles_80844;
extern _DWORD dword_5d4594_3804680;
extern _DWORD nox_client_renderGlow_805852;
extern _DWORD dword_5d4594_787172;
extern _DWORD nox_client_translucentConsole_80824;
extern _DWORD nox_client_fadeObjects_80836;
extern _DWORD nox_server_connectionType_3596;
extern nox_wnd_xxx* nox_wnd_xxx_815040;
extern _DWORD dword_5d4594_805984;
extern _DWORD nox_client_lockHighResFloors_1193152;
extern _DWORD dword_5d4594_3804668;
extern _DWORD dword_5d4594_810636;
extern _DWORD dword_5d4594_805836;
extern _DWORD dword_587000_87408;
extern _DWORD dword_5d4594_3798812;
extern _DWORD dword_5d4594_3798800;
extern _DWORD nox_client_drawFrontWalls_80812;
extern void* dword_587000_81128;
extern void* dword_587000_122852;
extern _DWORD dword_5d4594_754040;
extern _DWORD dword_5d4594_528252;
extern void* nox_alloc_screenParticles_806044;
extern _DWORD dword_5d4594_3798828;
extern _DWORD nox_client_translucentFrontWalls_805844;
extern _QWORD qword_5d4594_814956;
extern void* dword_587000_93164;
extern _DWORD dword_5d4594_787152;
extern _DWORD dword_5d4594_815044;
extern _DWORD dword_5d4594_787208;
extern _DWORD dword_5d4594_815088;
extern void* dword_587000_127004;
extern _DWORD dword_5d4594_814624;
extern _DWORD dword_5d4594_3801804;
extern _DWORD dword_5d4594_528256;
extern _DWORD dword_5d4594_3798816;
extern _DWORD nox_client_highResFloors_154952;
extern _DWORD dword_5d4594_3798808;
extern _DWORD dword_5d4594_3798832;
extern _DWORD dword_5d4594_2618912;
extern _DWORD dword_5d4594_754056;
extern _DWORD dword_5d4594_3799524;
extern _DWORD dword_5d4594_787164;
extern _DWORD dword_5d4594_815032;
extern _DWORD dword_5d4594_810640;
extern _DWORD dword_5d4594_815020;
extern _DWORD nox_client_texturedFloors_154956;
extern _DWORD dword_5d4594_787156;
extern _DWORD nox_client_highResFrontWalls_80820;
extern _DWORD dword_5d4594_815024;
extern _DWORD dword_5d4594_815028;
extern _DWORD dword_5d4594_3798836;
extern _DWORD dword_5d4594_814984;
extern _DWORD dword_5d4594_815016;
extern _DWORD dword_5d4594_2650672;
extern _DWORD dword_5d4594_815048;
extern _DWORD dword_5d4594_3798804;
extern _DWORD dword_587000_87404;
extern _DWORD dword_587000_87412;
extern _DWORD dword_5d4594_3798820;
extern _DWORD dword_5d4594_3798824;
extern _DWORD dword_5d4594_815000;
extern _DWORD dword_5d4594_741676;
extern _DWORD dword_5d4594_754036;
extern _DWORD dword_5d4594_3798840;
extern _DWORD dword_5d4594_3799624;
extern _DWORD dword_5d4594_3801780;
extern _DWORD dword_5d4594_787148;
extern _DWORD dword_5d4594_810632;
extern _DWORD nox_client_renderGUI_80828;
extern _DWORD dword_5d4594_3798796;
extern _DWORD dword_5d4594_815012;
extern _DWORD dword_5d4594_815004;
extern _DWORD dword_5d4594_2650652;
extern _DWORD dword_5d4594_3798844;
extern _DWORD dword_5d4594_814980;
extern int nox_enable_audio;
extern int nox_video_dxUnlockSurface;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

extern float input_sensitivity;

int nox_win_width = 0;
int nox_win_height = 0;

int nox_win_width_1 = NOX_DEFAULT_WIDTH;
int nox_win_height_1 = NOX_DEFAULT_HEIGHT;
int nox_win_depth_1 = NOX_DEFAULT_DEPTH;

int nox_win_width_2 = NOX_DEFAULT_WIDTH;
int nox_win_height_2 = NOX_DEFAULT_HEIGHT;
int nox_win_depth_2 = NOX_DEFAULT_DEPTH;

int nox_max_width = NOX_MAX_WIDTH;
int nox_max_height = NOX_MAX_HEIGHT;

extern int g_fullscreen;
int g_scaled = 0;
int g_fullscreen_cfg = 0;
int g_scaled_cfg = 0;
extern float draw_gamma;

FILE* nox_video_bag_fileptr = 0;

nox_mouse_state_t nox_input_buffer[256] = {0};
int nox_input_buffer_cap = sizeof(nox_input_buffer) / sizeof(nox_mouse_state_t);
int nox_processing_input = 0;

nox_mouse_state_t nox_mouse = {0};
nox_mouse_state_t nox_mouse_prev = {0};
_DWORD nox_mouse_prev_seq = 0;
_DWORD nox_mouse_prev_seq_2 = 0;
mouse_pos_t nox_mouse_min = {0, 0};
#ifdef __GNUC__
mouse_pos_t nox_mouse_max = {NOX_DEFAULT_WIDTH - 1, NOX_DEFAULT_HEIGHT - 1};
#else
mouse_pos_t nox_mouse_max = {639, 478}; // ugly hack for MSVC
#endif
mouse_pos_t nox_mouse_prev_left = {0};
mouse_pos_t nox_mouse_prev_right = {0};
mouse_pos_t nox_mouse_prev_middle = {0};

obj_5D4594_754088_t* ptr_5D4594_754088 = 0;
int ptr_5D4594_754088_cnt = 0;

obj_5D4594_754088_t* ptr_5D4594_754092 = 0;
int ptr_5D4594_754092_cnt = 0;

int obj_5D4594_754104_switch = 0;

obj_5D4594_3799572_t* ptr_5D4594_3799572 = 0;

nox_screenParticle* nox_screenParticles_head = 0;
nox_screenParticle* dword_5d4594_806052 = 0;

//----- (00427F30) --------------------------------------------------------
int __cdecl sub_427F30(int2* a1, int* a2) {
	int v2;  // esi
	int v3;  // ecx
	int v4;  // ebp
	int v5;  // edi
	int v6;  // ebx
	int v7;  // esi
	int v9;  // edx
	int v10; // eax
	int v12; // [esp+18h] [ebp-18h]
	int v13; // [esp+1Ch] [ebp-14h]

	v2 = a1->field_0;
	if ((double)a1->field_0 < 57.5)
		return 0;
	v3 = a1->field_4;
	if ((double)v3 < 57.5)
		return 0;
	if (v2 > 5888)
		return 0;
	if (v3 > 5888)
		return 0;
	v4 = v2 / 23;
	v5 = v3 / 23;
	v6 = a2[1] / 23;
	v12 = a2[2] / 23;
	v13 = a2[3] / 23;
	v7 = a2[4] / 23;
	v9 = a2[5] / 23;
	if (v3 / 23 < v6 || v5 > a2[7] / 23 || v4 < v12 || v4 > v7)
		return 0;
	if (v5 > v13) {
		if (v4 < v5 + v12 - v13)
			return 0;
		v10 = *a2 / 23;
	} else {
		v10 = *a2 / 23;
		if (v4 < v10 + v6 - v5)
			return 0;
	}
	if (v5 > v9) {
		if (v4 > v7 + v9 - v5)
			return 0;
	} else if (v4 > v5 + v10 - v6) {
		return 0;
	}
	return 1;
}

//----- (004280E0) --------------------------------------------------------
int __cdecl sub_4280E0(int2* a1, _DWORD* a2) {
	int v2; // ebx
	int v3; // esi
	int v4; // ebp
	int v5; // eax
	int v6; // edi
	int v7; // edx
	int v9; // edx

	v2 = a2[2];
	v3 = a1->field_0;
	if (a1->field_0 < v2)
		return 0;
	v4 = a2[4];
	if (v3 > v4)
		return 0;
	v5 = a1->field_4;
	v6 = a2[1];
	if (v5 < v6 || v5 > a2[7])
		return 0;
	v7 = a2[3];
	if (v5 > v7) {
		if (v3 < v2 + v5 - v7)
			return 0;
		v4 = a2[4];
	} else if (v3 < *a2 + v6 - v5) {
		return 0;
	}
	v9 = a2[5];
	if (v5 > v9) {
		if (v3 > v4 + v9 - v5)
			return 0;
	} else if (v3 > *a2 + v5 - v6) {
		return 0;
	}
	return 1;
}

//----- (00428170) --------------------------------------------------------
int __cdecl sub_428170(_DWORD* a1, int4* a2) {
	int v2; // edx
	int v3; // edx

	v2 = a1[1];
	if (v2 >= a1[7]) {
		a2->field_C = v2;
		a2->field_4 = a1[7];
	} else {
		a2->field_4 = v2;
		a2->field_C = a1[7];
	}
	v3 = a1[2];
	if (v3 >= a1[4]) {
		a2->field_8 = v3;
		a2->field_0 = a1[4];
	} else {
		a2->field_0 = v3;
		a2->field_8 = a1[4];
	}
	if (a2->field_0 < 0)
		a2->field_0 = 0;
	if (a2->field_4 < 0)
		a2->field_4 = 0;
	if (a2->field_8 >= 5888)
		a2->field_8 = 5887;
	if (a2->field_C >= 5888)
		a2->field_C = 5887;
	return 0;
}

//----- (004281F0) --------------------------------------------------------
int __cdecl sub_4281F0(int2* a1, int4* a2) {
	int v2;      // ecx
	bool result; // al

	result = 0;
	if (a1->field_0 >= a2->field_0 && a1->field_0 <= a2->field_8) {
		v2 = a1->field_4;
		if (v2 >= a2->field_4 && v2 <= a2->field_C)
			result = 1;
	}
	return result;
}

//----- (00428220) --------------------------------------------------------
BOOL __cdecl sub_428220(float2* a1, float4* a2) {
	return a1->field_0 >= (double)a2->field_0 && a1->field_0 <= (double)a2->field_8 &&
		   a1->field_4 >= (double)a2->field_4 && a1->field_4 <= (double)a2->field_C;
}

//----- (00428270) --------------------------------------------------------
void __cdecl nox_shape_box_calc(nox_shape* s) {
	const float mul = 0.35354999; // cos(Pi/4) / 2
	float px = s->box_w * mul;
	float py = s->box_h * mul;

	double v = 0.0;

	v = -px + py;
	s->box_left_top = v;
	s->box_left_top_2 = v;

	v = -px - py;
	s->box_left_bottom = v;
	s->box_left_bottom_2 = v;

	v = +px + py;
	s->box_right_top = v;
	s->box_right_top_2 = v;

	v = +px - py;
	s->box_right_bottom = v;
	s->box_right_bottom_2 = v;
}

//----- (004282D0) --------------------------------------------------------
char* __cdecl sub_4282D0(char* a1, int a2) {
	char* result; // eax

	result = strncpy((char*)getMemAt(0x5D4594, 741316), a1, 0x10u);
	*getMemU32Ptr(0x5D4594, 741304) = a2;
	return result;
}

//----- (004282F0) --------------------------------------------------------
void* __cdecl sub_4282F0(int a1, int a2, size_t a3) {
	int v3;         // ebx
	size_t v4;      // edi
	unsigned int i; // esi
	size_t v6;      // ebp
	void* result;   // eax
	size_t v8;      // ebp
	int v9;         // edx
	int v10;        // esi
	int v11;        // eax
	int j;          // [esp+14h] [ebp+4h]

	v3 = a1;
	v4 = 0;
	if (*(_DWORD*)(a1 + 608)) {
		for (i = 0; i < *(int*)&dword_5d4594_741332; ++i) {
			free(*(LPVOID*)(*(_DWORD*)(a1 + 608) + 4 * i));
			*(_DWORD*)(*(_DWORD*)(a1 + 608) + 4 * i) = 0;
		}
		free(*(LPVOID*)(a1 + 608));
		*(_DWORD*)(a1 + 608) = 0;
	}
	if (*(_DWORD*)(a1 + 612)) {
		free(*(LPVOID*)(a1 + 612));
		*(_DWORD*)(a1 + 612) = 0;
	}
	if (*(_DWORD*)(a1 + 616)) {
		free(*(LPVOID*)(a1 + 616));
		*(_DWORD*)(a1 + 616) = 0;
	}
	if (*(_DWORD*)(a1 + 620)) {
		free(*(LPVOID*)(a1 + 620));
		*(_DWORD*)(a1 + 620) = 0;
	}
	if (*(_DWORD*)(a1 + 624)) {
		free(*(LPVOID*)(a1 + 624));
		*(_DWORD*)(a1 + 624) = 0;
	}
	if (*(_DWORD*)(a1 + 628)) {
		free(*(LPVOID*)(a1 + 628));
		*(_DWORD*)(a1 + 628) = 0;
	}
	if (*(_DWORD*)(a1 + 632)) {
		free(*(LPVOID*)(a1 + 632));
		*(_DWORD*)(a1 + 632) = 0;
	}
	v6 = 4 * a3;
	*(_DWORD*)(a1 + 608) = malloc(4 * a3);
	if (a3) {
		do
			*(_DWORD*)(*(_DWORD*)(a1 + 608) + 4 * v4++) = malloc(0xAu);
		while (v4 < a3);
	}
	*(_DWORD*)(a1 + 612) = malloc(v6);
	*(_DWORD*)(a1 + 616) = malloc(v6);
	*(_DWORD*)(a1 + 620) = malloc(a3);
	*(_DWORD*)(a1 + 624) = malloc(a3);
	*(_DWORD*)(a1 + 628) = malloc(v6);
	result = malloc(a3);
	v8 = 0;
	*(_DWORD*)(a1 + 632) = result;
	if (a3) {
		v9 = a2 + 16;
		for (j = a2 + 16;; v9 = j) {
			strcpy(*(char**)(*(_DWORD*)(v3 + 608) + 4 * v8), (const char*)(v9 - 16));
			*(_DWORD*)(*(_DWORD*)(v3 + 612) + 4 * v8) = *(_DWORD*)(v9 - 4);
			*(_DWORD*)(*(_DWORD*)(v3 + 616) + 4 * v8) = *(_DWORD*)v9;
			*(_BYTE*)(*(_DWORD*)(v3 + 620) + v8) = *(_BYTE*)(v9 + 4);
			*(_BYTE*)(*(_DWORD*)(v3 + 624) + v8) = *(_BYTE*)(v9 + 5);
			*(_BYTE*)(*(_DWORD*)(v3 + 632) + v8) = *(_BYTE*)(v9 + 12);
			v10 = *(_DWORD*)(v9 + 8);
			v11 = time(0) - v10;
			++v8;
			*(_DWORD*)(j + 8) = v11;
			*(_DWORD*)(*(_DWORD*)(v3 + 628) + 4 * v8 - 4) = v11;
			result = (void*)a3;
			j += 32;
			if (v8 >= a3)
				break;
		}
		*(_WORD*)(v3 + 6) = a3;
		dword_5d4594_741332 = a3;
	} else {
		*(_WORD*)(a1 + 6) = 0;
		dword_5d4594_741332 = 0;
	}
	return result;
}

//----- (00428540) --------------------------------------------------------
unsigned int __cdecl sub_428540(int a1, char* a2, int a3) {
	unsigned int result; // eax
	char* v4;            // ecx
	char v5;             // bl

	if (*(_DWORD*)(a1 + 636)) {
		free(*(LPVOID*)(a1 + 636));
		*(_DWORD*)(a1 + 636) = 0;
	}
	*(_DWORD*)(a1 + 636) = malloc(2 * a3);
	result = 0;
	if (2 * a3) {
		v4 = a2;
		do {
			v5 = *v4;
			v4 += 2;
			*(_BYTE*)(result + *(_DWORD*)(a1 + 636)) = v5;
			*(_BYTE*)(result + *(_DWORD*)(a1 + 636) + 1) = *(v4 - 1);
			result += 2;
		} while (result < 2 * a3);
		*getMemU32Ptr(0x5D4594, 741308) = a3;
	} else {
		*getMemU32Ptr(0x5D4594, 741308) = a3;
	}
	return result;
}

//----- (004285C0) --------------------------------------------------------
char* __cdecl sub_4285C0(__int16* a1) {
	char* result;    // eax
	__int16* v2;     // ebx
	void* v3;        // eax
	unsigned int v4; // esi
	bool v5;         // zf
	void* v6;        // eax
	void* v7;        // eax
	void* v8;        // eax
	void* v9;        // eax
	void* v10;       // eax
	void* v11;       // eax
	char* v12;       // ebp
	int v13;         // eax
	size_t v14;      // [esp-24h] [ebp-30h]
	size_t v15;      // [esp-20h] [ebp-2Ch]
	size_t v16;      // [esp-18h] [ebp-24h]
	size_t v17;      // [esp-14h] [ebp-20h]
	size_t v18;      // [esp-Ch] [ebp-18h]
	size_t v19;      // [esp-8h] [ebp-14h]
	int v20;         // [esp+10h] [ebp+4h]

	result = (char*)sub_4E3CE0();
	v2 = a1;
	*a1 = (__int16)result;
	if ((__int16)result <= 0) {
		dword_5d4594_741332 = *a1;
	} else {
		v3 = malloc(4 * (__int16)result);
		v4 = 0;
		v5 = *a1 == 0;
		*((_DWORD*)a1 + 134) = v3;
		if (!v5) {
			do
				*(_DWORD*)(*((_DWORD*)a1 + 134) + 4 * v4++) = malloc(0xAu);
			while (v4 < *a1);
		}
		v6 = malloc(4 * *a1);
		v19 = *a1;
		*((_DWORD*)a1 + 135) = v6;
		v7 = malloc(v19);
		v18 = 4 * *a1;
		*((_DWORD*)a1 + 144) = v7;
		*((_DWORD*)a1 + 136) = malloc(v18);
		v8 = malloc(4 * *a1);
		v17 = 4 * *a1;
		*((_DWORD*)a1 + 137) = v8;
		v9 = malloc(v17);
		v16 = 4 * *a1;
		*((_DWORD*)a1 + 138) = v9;
		*((_DWORD*)a1 + 139) = malloc(v16);
		v10 = malloc(4 * *a1);
		v15 = 4 * *a1;
		*((_DWORD*)a1 + 140) = v10;
		v11 = malloc(v15);
		v14 = 4 * *a1;
		*((_DWORD*)a1 + 141) = v11;
		*((_DWORD*)a1 + 142) = malloc(v14);
		*((_DWORD*)a1 + 143) = malloc(4 * *a1);
		v20 = 0;
		result = nox_common_playerInfoGetFirst_416EA0();
		v12 = result;
		if (result) {
			do {
				if (*((_DWORD*)v12 + 1198)) {
					strcpy(*(char**)(*((_DWORD*)v2 + 134) + 4 * v20), v12 + 2096);
					v13 = sub_554200((unsigned __int8)v12[2064] + 1);
					*(_DWORD*)(*((_DWORD*)v2 + 135) + 4 * v20) = htonl(v13);
					*(_BYTE*)(v20 + *((_DWORD*)v2 + 144)) = v12[2251];
					*(_DWORD*)(*((_DWORD*)v2 + 136) + 4 * v20) = *((_DWORD*)v12 + 1172);
					*(_DWORD*)(*((_DWORD*)v2 + 137) + 4 * v20) = *((_DWORD*)v12 + 1172);
					*(_DWORD*)(*((_DWORD*)v2 + 138) + 4 * v20) = *((_DWORD*)v12 + 1166);
					*(_DWORD*)(*((_DWORD*)v2 + 139) + 4 * v20) = *((_DWORD*)v12 + 1165);
					*(_DWORD*)(*((_DWORD*)v2 + 140) + 4 * v20) = *((_DWORD*)v12 + 1167);
					*(_DWORD*)(*((_DWORD*)v2 + 141) + 4 * v20) = *((_DWORD*)v12 + 1168);
					*(_DWORD*)(*((_DWORD*)v2 + 142) + 4 * v20) = *((_DWORD*)v12 + 1171);
					*(_DWORD*)(*((_DWORD*)v2 + 143) + 4 * v20++) = sub_4D6540((unsigned __int8)v12[2064]);
				}
				v12 = nox_common_playerInfoGetNext_416EE0((int)v12);
			} while (v12);
			result = (char*)*v2;
			dword_5d4594_741332 = *v2;
		} else {
			dword_5d4594_741332 = *v2;
		}
	}
	return result;
}

//----- (00428810) --------------------------------------------------------
BOOL __cdecl sub_428810(int a1, int a2) {
	uint16_t* v2; // esi
	uint16_t* v3; // edi
	BOOL v4;     // esi
	char v6[72]; // [esp+8h] [ebp-48h]

	v2 = sub_42ADA0(a1, a2, *getMemI16Ptr(0x5D4594, 741308), getMemUintPtr(0x5D4594, 741312));
	v3 = sub_42A8B0(v2, getMemIntPtr(0x5D4594, 741312));
	free(v2);
	v4 = 1;
	if (sub_420360(v6, &a2))
		v4 = sub_40DEA0((int)v6, (__int16)a2, (int)v3, *getMemIntPtr(0x5D4594, 741312));
	free(v3);
	return v4;
}

//----- (00428890) --------------------------------------------------------
BOOL __cdecl sub_428890(__int16* a1) {
	uint16_t* v1; // esi
	uint16_t* v2; // edi
	BOOL v3;     // esi
	char v5[72]; // [esp+8h] [ebp-48h]

	v1 = sub_42B810(a1, getMemUintPtr(0x5D4594, 741300));
	v2 = sub_42A8B0(v1, getMemIntPtr(0x5D4594, 741300));
	free(v1);
	v3 = 1;
	if (sub_420360(v5, &a1))
		v3 = sub_40DEA0((int)v5, (__int16)a1, (int)v2, *getMemIntPtr(0x5D4594, 741300));
	free(v2);
	return v3;
}

//----- (00428910) --------------------------------------------------------
LPVOID __cdecl sub_428910(LPVOID* a1) {
	unsigned int i; // edi
	LPVOID result;  // eax

	if (a1[152]) {
		for (i = 0; i < *(int*)&dword_5d4594_741332; ++i) {
			free(*((LPVOID*)a1[152] + i));
			*((_DWORD*)a1[152] + i) = 0;
		}
		free(a1[152]);
		a1[152] = 0;
	}
	if (a1[153]) {
		free(a1[153]);
		a1[153] = 0;
	}
	if (a1[154]) {
		free(a1[154]);
		a1[154] = 0;
	}
	if (a1[155]) {
		free(a1[155]);
		a1[155] = 0;
	}
	result = a1[159];
	if (result) {
		free(a1[159]);
		a1[159] = 0;
	}
	return result;
}

//----- (004289D0) --------------------------------------------------------
LPVOID __cdecl sub_4289D0(LPVOID* a1) {
	unsigned int i; // edi
	LPVOID result;  // eax

	if (a1[134]) {
		for (i = 0; i < *(int*)&dword_5d4594_741332; ++i) {
			free(*((LPVOID*)a1[134] + i));
			*((_DWORD*)a1[134] + i) = 0;
		}
		free(a1[134]);
		a1[134] = 0;
	}
	if (a1[135]) {
		free(a1[135]);
		a1[135] = 0;
	}
	if (a1[144]) {
		free(a1[144]);
		a1[144] = 0;
	}
	if (a1[136]) {
		free(a1[136]);
		a1[136] = 0;
	}
	if (a1[137]) {
		free(a1[137]);
		a1[137] = 0;
	}
	if (a1[138]) {
		free(a1[138]);
		a1[138] = 0;
	}
	if (a1[139]) {
		free(a1[139]);
		a1[139] = 0;
	}
	if (a1[140]) {
		free(a1[140]);
		a1[140] = 0;
	}
	if (a1[141]) {
		free(a1[141]);
		a1[141] = 0;
	}
	if (a1[142]) {
		free(a1[142]);
		a1[142] = 0;
	}
	result = a1[143];
	if (result) {
		free(a1[143]);
		a1[143] = 0;
	}
	return result;
}

//----- (00428B30) --------------------------------------------------------
int nox_server_mapRWObjectTOC_428B30() {
	int v1;              // eax
	unsigned __int16 v2; // bp
	int v3;              // esi
	int v4;              // eax
	int v5;              // esi
	int i;               // esi
	unsigned __int16 v7; // ax
	int v8;              // [esp+4h] [ebp-110h]
	int v9;              // [esp+8h] [ebp-10Ch]
	int v10;             // [esp+Ch] [ebp-108h]
	int v11;             // [esp+10h] [ebp-104h]
	char v12[256];       // [esp+14h] [ebp-100h]

	v11 = 1;
	sub_426AC0_file3_fread(&v11, 2u);
	if ((__int16)v11 > 1)
		return 0;
	sub_42BFB0();
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		sub_426AC0_file3_fread(&v9, 2u);
		for (i = 0; (unsigned __int16)i < (unsigned __int16)v9; ++i) {
			sub_426AC0_file3_fread(&v10, 2u);
			sub_426AC0_file3_fread(&v8, 1u);
			sub_426AC0_file3_fread(v12, (unsigned __int8)v8);
			v12[(unsigned __int8)v8] = 0;
			if (!nox_common_gameFlags_check_40A5C0(2) || nox_common_gameFlags_check_40A5C0(1))
				v7 = sub_4E3AA0(v12);
			else
				v7 = sub_44CFC0(v12);
			sub_42C310(v7, v10);
		}
		return 1;
	}
	sub_42BFE0();
	LOWORD(v1) = sub_42C300();
	v9 = v1;
	sub_426AC0_file3_fread(&v9, 2u);
	v2 = 0;
	if (!sub_4E3AC0())
		return 1;
	v3 = 0;
	do {
		LOWORD(v4) = sub_42C2E0(v3);
		v10 = v4;
		if ((_WORD)v4) {
			sub_426AC0_file3_fread(&v10, 2u);
			v5 = sub_4E3B70(v3);
			LOBYTE(v8) = strlen(*(const char**)(v5 + 4));
			sub_426AC0_file3_fread(&v8, 1u);
			sub_426AC0_file3_fread(*(_BYTE**)(v5 + 4), (unsigned __int8)v8);
		}
		v3 = ++v2;
	} while (v2 < (unsigned int)sub_4E3AC0());
	return 1;
}
// 428B85: variable 'v1' is possibly undefined
// 428BAB: variable 'v4' is possibly undefined
// 428B30: using guessed type char var_100[256];

//----- (00428CD0) --------------------------------------------------------
int __cdecl nox_server_mapRWPolygons_428CD0(int a1) {
	char* i;              // eax
	char* v3;             // esi
	unsigned int j;       // edi
	char* k;              // eax
	char* v6;             // esi
	char* v7;             // ebp
	char* v8;             // ebp
	unsigned int v9;      // esi
	unsigned __int8* v10; // esi
	_WORD* v11;           // ebx
	_BYTE* v12;           // eax
	char* v13;            // edi
	int v14;              // eax
	unsigned int v15;     // ebp
	bool v16;             // cc
	char* v17;            // edi
	double v18;           // st7
	double v19;           // st7
	double v20;           // st7
	double v21;           // st7
	char* v22;            // edi
	char* v23;            // eax
	_BYTE* v24;           // esi
	unsigned int v25;     // [esp+10h] [ebp-2Ch]
	int v26;              // [esp+14h] [ebp-28h]
	int v27;              // [esp+18h] [ebp-24h]
	unsigned int v28;     // [esp+1Ch] [ebp-20h]
	float v29[2];         // [esp+20h] [ebp-1Ch]
	int v30;              // [esp+28h] [ebp-14h]
	int v31;              // [esp+2Ch] [ebp-10h]
	char v32[12];         // [esp+30h] [ebp-Ch]

	v30 = 0;
	if (a1)
		return 1;
	v26 = 4;
	sub_426AC0_file3_fread(&v26, 2u);
	if ((__int16)v26 > 4)
		return 0;
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		sub_426AC0_file3_fread(&v25, 4u);
		v9 = 1;
		if (v25 >= 1) {
			do {
				sub_426AC0_file3_fread(&a1, 4u);
				sub_426AC0_file3_fread(v29, 8u);
				if (!sub_420D40(SLODWORD(v29[0]), SLODWORD(v29[1]), v9, a1))
					return 0;
				if ((__int16)v26 < 3)
					sub_426AC0_file3_fread(&v31, 4u);
			} while (++v9 <= v25);
		}
		sub_426AC0_file3_fread(&v25, 4u);
		v28 = 1;
		if (v25 >= 1) {
			do {
				v10 = sub_421230();
				if (!v10)
					return 0;
				sub_426AC0_file3_fread(&v27, 1u);
				sub_426AC0_file3_fread(v10 + 4, (unsigned __int8)v27);
				v10[(unsigned __int8)v27 + 4] = 0;
				if ((__int16)v26 >= 3 || (sub_426AC0_file3_fread(&v31, 4u), sub_426AC0_file3_fread(v32, 0xCu),
										  v10[104] = v32[0], v10[105] = v32[4], v10[106] = v32[8], (__int16)v26 >= 3)) {
					sub_426AC0_file3_fread(&a1, 1u);
					v10[104] = a1;
					sub_426AC0_file3_fread(&a1, 1u);
					v10[105] = a1;
					sub_426AC0_file3_fread(&a1, 1u);
					v10[106] = a1;
				}
				sub_426AC0_file3_fread(v10 + 130, 1u);
				v11 = v10 + 128;
				sub_426AC0_file3_fread(v10 + 128, 2u);
				v12 = calloc(*((unsigned __int16*)v10 + 64), 4u);
				*((_DWORD*)v10 + 27) = v12;
				if (!v12)
					return 0;
				sub_426AC0_file3_fread(v12, 4 * (unsigned __int16)*v11);
				sub_421040((int)v10);
				v13 = sub_421030(**((_DWORD**)v10 + 27));
				*((_DWORD*)v10 + 22) = nox_float2int(*((float*)v13 + 1));
				*((_DWORD*)v10 + 23) = nox_float2int(*((float*)v13 + 2));
				*((_DWORD*)v10 + 24) = nox_float2int(*((float*)v13 + 1));
				v14 = nox_float2int(*((float*)v13 + 2));
				v15 = 1;
				v16 = *v11 <= 1u;
				*((_DWORD*)v10 + 25) = v14;
				if (!v16) {
					do {
						v17 = sub_421030(*(_DWORD*)(*((_DWORD*)v10 + 27) + 4 * v15));
						v18 = *((float*)v17 + 1);
						v29[0] = *((float*)v17 + 1);
						if (v18 >= (double)*((int*)v10 + 22)) {
							v19 = *((float*)v17 + 1);
							v29[0] = *((float*)v17 + 1);
							if (v19 > (double)*((int*)v10 + 24))
								*((_DWORD*)v10 + 24) = nox_float2int(v29[0]);
						} else {
							*((_DWORD*)v10 + 22) = nox_float2int(v29[0]);
						}
						v20 = *((float*)v17 + 2);
						v29[0] = *((float*)v17 + 2);
						if (v20 >= (double)*((int*)v10 + 23)) {
							v21 = *((float*)v17 + 2);
							v29[0] = *((float*)v17 + 2);
							if (v21 > (double)*((int*)v10 + 25))
								*((_DWORD*)v10 + 25) = nox_float2int(v29[0]);
						} else {
							*((_DWORD*)v10 + 23) = nox_float2int(v29[0]);
						}
						++v15;
					} while (v15 < (unsigned __int16)*v11);
				}
				if ((__int16)v26 >= 2) {
					v22 = *(char**)v10;
					sub_4F5580((int)(v10 + 112), *(char**)v10);
					if (v22)
						v23 = v22 + 128;
					else
						v23 = 0;
					sub_4F5580((int)(v10 + 120), v23);
				}
				if ((__int16)v26 >= 4) {
					v24 = v10 + 132;
					sub_426AC0_file3_fread(v24, 4u);
					if (*v24 & 1)
						++v30;
				}
			} while (++v28 <= v25);
		}
		sub_4D72D0(v30);
		return 1;
	}
	v25 = 0;
	for (i = sub_420CA0(); i; ++v25)
		i = sub_420CD0(i);
	sub_426AC0_file3_fread(&v25, 4u);
	v3 = sub_420CA0();
	for (j = 0; j < v25; ++j) {
		sub_426AC0_file3_fread(v3, 4u);
		sub_426AC0_file3_fread(v3 + 4, 8u);
		v3 = sub_420CD0(v3);
	}
	v25 = 0;
	for (k = sub_4210A0(); k; ++v25)
		k = sub_4210E0((int)k);
	sub_426AC0_file3_fread(&v25, 4u);
	v6 = sub_4210A0();
	v28 = 0;
	if (v25 <= 0)
		return 1;
	do {
		v7 = *(char**)v6;
		LOBYTE(v27) = strlen(v6 + 4);
		sub_426AC0_file3_fread(&v27, 1u);
		sub_426AC0_file3_fread(v6 + 4, (unsigned __int8)v27);
		LOBYTE(a1) = v6[104];
		sub_426AC0_file3_fread(&a1, 1u);
		LOBYTE(a1) = v6[105];
		sub_426AC0_file3_fread(&a1, 1u);
		LOBYTE(a1) = v6[106];
		sub_426AC0_file3_fread(&a1, 1u);
		sub_426AC0_file3_fread(v6 + 130, 1u);
		sub_426AC0_file3_fread(v6 + 128, 2u);
		sub_426AC0_file3_fread(*((_BYTE**)v6 + 27), 4 * *((unsigned __int16*)v6 + 64));
		sub_4F5580((int)(v6 + 112), v7);
		if (v7)
			v8 = v7 + 128;
		else
			v8 = 0;
		sub_4F5580((int)(v6 + 120), v8);
		sub_426AC0_file3_fread(v6 + 132, 4u);
		v6 = sub_4210E0((int)v6);
		++v28;
	} while (v28 < v25);
	return 1;
}

//----- (00429200) --------------------------------------------------------
int nox_server_mapRWAmbientData_429200() {
	int result; // eax
	char* v1;   // esi
	int v2;     // [esp+0h] [ebp-10h]
	int v3[3];  // [esp+4h] [ebp-Ch]

	v2 = 1;
	sub_426AC0_file3_fread(&v2, 2u);
	if ((__int16)v2 < 1)
		return 0;
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
			sub_426AC0_file3_fread(&v3[0], 4u);
			sub_426AC0_file3_fread(&v3[1], 4u);
			sub_426AC0_file3_fread(&v3[2], 4u);
			sub_469B90(v3);
			if (nox_common_gameFlags_check_40A5C0(2097154))
				sub_4349C0(v3);
		}
		result = 1;
	} else {
		v1 = sub_469BB0();
		sub_426AC0_file3_fread(v1, 4u);
		sub_426AC0_file3_fread(v1 + 4, 4u);
		sub_426AC0_file3_fread(v1 + 8, 4u);
		result = 1;
	}
	return result;
}

//----- (004292C0) --------------------------------------------------------
int __cdecl nox_server_mapRWWindowWalls_4292C0(_DWORD* a1) {
	int result; // eax
	_DWORD* v2; // edi
	char* v3;   // esi
	_DWORD* v4; // eax
	int v5;     // [esp+4h] [ebp-20h]
	int v6;     // [esp+8h] [ebp-1Ch]
	int2 v7;
	int4 v9; // [esp+14h] [ebp-10h]

	v5 = 2;
	sub_426AC0_file3_fread(&v5, 2u);
	if ((__int16)v5 > 2)
		return 0;
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 741336), 2u);
		v6 = 0;
		if (*getMemU16Ptr(0x5D4594, 741336) > 0) {
			v2 = a1;
			do {
				sub_426AC0_file3_fread(&v7, 8u);
				if (a1) {
					v3 = sub_426A70();
					sub_428170(a1, &v9);
					v7.field_0 += v9.field_0 / 23 - *(_DWORD*)v3;
					v7.field_4 += v9.field_4 / 23 - *((_DWORD*)v3 + 1);
				}
				if (nox_common_gameFlags_check_40A5C0(0x400000)) {
					v4 = sub_5042F0(v7.field_0, v7.field_4);
					if (v4)
						v2 = (_DWORD*)*v4;
				} else {
					v2 = (_DWORD*)nox_server_getWallAtPoint_410580(v7.field_0, v7.field_4);
				}
				if (v2) {
					*((_BYTE*)v2 + 4) |= 0x40u;
					if ((__int16)v5 < 2)
						*((_BYTE*)v2 + 2) = 0;
				}
				++v6;
			} while (v6 < *getMemI16Ptr(0x5D4594, 741336));
		}
		result = 1;
	} else {
		*getMemU16Ptr(0x5D4594, 741336) = 0;
		sub_410640(sub_429450, (int)a1);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 741336), 2u);
		sub_410640(sub_4294B0, (int)a1);
		result = 1;
	}
	return result;
}

//----- (00429450) --------------------------------------------------------
void __cdecl sub_429450(_BYTE* a1, _DWORD* a2) {
	int v2;  // eax
	int2 v3; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned __int8)a1[6], v3.field_0 = 23 * (unsigned __int8)a1[5], v3.field_4 = 23 * v2,
				sub_427F30(&v3, a2))) {
		if (a1[4] & 0x40)
			++*getMemU16Ptr(0x5D4594, 741336);
	}
}

//----- (004294B0) --------------------------------------------------------
void __cdecl sub_4294B0(_BYTE* a1, _DWORD* a2) {
	int v2;  // eax
	int v3;  // edx
	int2 v4; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned __int8)a1[6], v4.field_0 = 23 * (unsigned __int8)a1[5], v4.field_4 = 23 * v2,
				sub_427F30(&v4, a2))) {
		if (a1[4] & 0x40) {
			v3 = (unsigned __int8)a1[6];
			v4.field_0 = (unsigned __int8)a1[5];
			v4.field_4 = v3;
			sub_426AC0_file3_fread(&v4, 8u);
		}
	}
}

//----- (00429520) --------------------------------------------------------
void sub_429520() { *getMemU32Ptr(0x5D4594, 741344) = 0; }

//----- (00429530) --------------------------------------------------------
int __cdecl nox_server_mapRWDestructableWalls_429530(_DWORD* a1) {
	int result; // eax
	_DWORD* v2; // edi
	char* v3;   // esi
	_DWORD* v4; // eax
	int v5;     // [esp+4h] [ebp-20h]
	int v6;     // [esp+8h] [ebp-1Ch]
	int2 v7;
	int4 v9; // [esp+14h] [ebp-10h]

	v5 = 1;
	sub_426AC0_file3_fread(&v5, 2u);
	if ((__int16)v5 > 1)
		return 0;
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 741340), 2u);
		v6 = 0;
		if (*getMemU16Ptr(0x5D4594, 741340) > 0) {
			v2 = a1;
			do {
				sub_426AC0_file3_fread(&v7, 8u);
				if (a1) {
					v3 = sub_426A70();
					sub_428170(a1, &v9);
					v7.field_0 += v9.field_0 / 23 - *(_DWORD*)v3;
					v7.field_4 += v9.field_4 / 23 - *((_DWORD*)v3 + 1);
				}
				if (nox_common_gameFlags_check_40A5C0(0x400000)) {
					v4 = sub_5042F0(v7.field_0, v7.field_4);
					if (v4)
						v2 = (_DWORD*)*v4;
				} else {
					v2 = (_DWORD*)nox_server_getWallAtPoint_410580(v7.field_0, v7.field_4);
				}
				if (v2) {
					*((_BYTE*)v2 + 4) |= 8u;
					*((_WORD*)v2 + 5) = *getMemU16Ptr(0x5D4594, 741344);
					++*getMemU32Ptr(0x5D4594, 741344);
					if (!nox_common_gameFlags_check_40A5C0(0x400000))
						sub_410840((int)v2);
				}
				++v6;
			} while (v6 < *getMemI16Ptr(0x5D4594, 741340));
		}
		result = 1;
	} else {
		*getMemU16Ptr(0x5D4594, 741340) = 0;
		sub_410640(sub_4296E0, (int)a1);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 741340), 2u);
		sub_410640(sub_429740, (int)a1);
		result = 1;
	}
	return result;
}

//----- (004296E0) --------------------------------------------------------
void __cdecl sub_4296E0(_BYTE* a1, _DWORD* a2) {
	int v2;  // eax
	int2 v3; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned __int8)a1[6], v3.field_0 = 23 * (unsigned __int8)a1[5], v3.field_4 = 23 * v2,
				sub_427F30(&v3, a2))) {
		if (a1[4] & 8)
			++*getMemU16Ptr(0x5D4594, 741340);
	}
}

//----- (00429740) --------------------------------------------------------
void __cdecl sub_429740(_BYTE* a1, _DWORD* a2) {
	int v2;  // eax
	int v3;  // edx
	int2 v4; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned __int8)a1[6], v4.field_0 = 23 * (unsigned __int8)a1[5], v4.field_4 = 23 * v2,
				sub_427F30(&v4, a2))) {
		if (a1[4] & 8) {
			v3 = (unsigned __int8)a1[6];
			v4.field_0 = (unsigned __int8)a1[5];
			v4.field_4 = v3;
			sub_426AC0_file3_fread(&v4, 8u);
		}
	}
}

//----- (004297B0) --------------------------------------------------------
void sub_4297B0() { *getMemU32Ptr(0x5D4594, 741352) = 0; }

//----- (004297C0) --------------------------------------------------------
int __cdecl nox_server_mapRWSecretWalls_4297C0(_DWORD* a1) {
	char* v2;  // esi
	int* v3;   // edi
	_BYTE* v4; // ebx
	char* v5;  // ebp
	int* v6;   // eax
	int v7;    // eax
	char v8;   // dl
	int v9;    // [esp+4h] [ebp-1Ch]
	int v10;   // [esp+8h] [ebp-18h]
	int v11;   // [esp+Ch] [ebp-14h]
	int4 v12;  // [esp+10h] [ebp-10h]

	v9 = 2;
	sub_426AC0_file3_fread(&v9, 2u);
	if ((__int16)v9 > 2)
		return 0;
	if (!*getMemU32Ptr(0x5D4594, 3803300)) {
		*getMemU16Ptr(0x5D4594, 741348) = 0;
		sub_410640(sub_429A00, (int)a1);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 741348), 2u);
		sub_410640(sub_429A60, (int)a1);
		return 1;
	}
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 741348), 2u);
	v11 = 0;
	if (*getMemU16Ptr(0x5D4594, 741348) > 0) {
		while (1) {
			v2 = (char*)calloc(1u, 0x20u);
			v3 = (int*)(v2 + 4);
			sub_426AC0_file3_fread(v2 + 4, 8u);
			sub_426AC0_file3_fread(v2 + 16, 4u);
			sub_426AC0_file3_fread(v2 + 20, 1u);
			v4 = v2 + 21;
			v2[21] = 0;
			if ((__int16)v9 >= 2) {
				sub_426AC0_file3_fread(v2 + 21, 1u);
				sub_426AC0_file3_fread(v2 + 22, 1u);
				sub_426AC0_file3_fread(v2 + 24, 4u);
				sub_426AC0_file3_fread(v2 + 28, 4u);
			}
			if (a1) {
				v5 = sub_426A70();
				sub_428170(a1, &v12);
				*v3 += v12.field_0 / 23 - *(_DWORD*)v5;
				*((_DWORD*)v2 + 2) += v12.field_4 / 23 - *((_DWORD*)v5 + 1);
			}
			if (!nox_common_gameFlags_check_40A5C0(0x400000))
				break;
			v6 = sub_5042F0(*v3, *((_DWORD*)v2 + 2));
			if (!v6)
				goto LABEL_14;
			v7 = *v6;
			v10 = v7;
		LABEL_15:
			if (v7) {
				v8 = *(_BYTE*)(v7 + 4);
				*(_DWORD*)(v7 + 28) = v2;
				*(_BYTE*)(v7 + 4) = v8 | 4;
				*(_WORD*)(v7 + 10) = *getMemU16Ptr(0x5D4594, 741352);
				++*getMemU32Ptr(0x5D4594, 741352);
				*((_DWORD*)v2 + 3) = v7;
				if (!*v4) {
					if (v2[20] & 8) {
						*((_DWORD*)v2 + 7) = -1;
						*v4 = 3;
						v2[22] = 23;
					} else {
						*((_DWORD*)v2 + 7) = 0;
						*v4 = 1;
						v2[22] = 0;
					}
				}
				if (!nox_common_gameFlags_check_40A5C0(0x400000))
					sub_410760(v2);
			}
			if (++v11 >= *getMemI16Ptr(0x5D4594, 741348))
				return 1;
		}
		v10 = nox_server_getWallAtPoint_410580(*v3, *((_DWORD*)v2 + 2));
	LABEL_14:
		v7 = v10;
		goto LABEL_15;
	}
	return 1;
}

//----- (00429A00) --------------------------------------------------------
void __cdecl sub_429A00(_BYTE* a1, _DWORD* a2) {
	int v2;  // eax
	int2 v3; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned __int8)a1[6], v3.field_0 = 23 * (unsigned __int8)a1[5], v3.field_4 = 23 * v2,
				sub_427F30(&v3, a2))) {
		if (a1[4] & 4)
			++*getMemU16Ptr(0x5D4594, 741348);
	}
}

//----- (00429A60) --------------------------------------------------------
void __cdecl sub_429A60(int a1, _DWORD* a2) {
	int v2;    // eax
	int v3;    // edx
	_BYTE* v4; // esi
	int2 v5;   // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = *(unsigned __int8*)(a1 + 6), v5.field_0 = 23 * *(unsigned __int8*)(a1 + 5), v5.field_4 = 23 * v2,
				sub_427F30(&v5, a2))) {
		if (*(_BYTE*)(a1 + 4) & 4) {
			v3 = *(unsigned __int8*)(a1 + 6);
			v4 = *(_BYTE**)(a1 + 28);
			v5.field_0 = *(unsigned __int8*)(a1 + 5);
			v5.field_4 = v3;
			sub_426AC0_file3_fread(&v5, 8u);
			sub_426AC0_file3_fread(v4 + 16, 4u);
			sub_426AC0_file3_fread(v4 + 20, 1u);
			sub_426AC0_file3_fread(v4 + 21, 1u);
			sub_426AC0_file3_fread(v4 + 22, 1u);
			sub_426AC0_file3_fread(v4 + 24, 4u);
			sub_426AC0_file3_fread(v4 + 28, 4u);
		}
	}
}

//----- (00429B20) --------------------------------------------------------
int __cdecl nox_server_mapRWWallMap_429B20(_DWORD* a1) {
	_DWORD* v2;           // ebp
	int v3;               // esi
	int v5;               // edx
	int v6;               // edx
	int v7;               // ecx
	int v8;               // eax
	int v9;               // edi
	_BYTE* v10;           // eax
	_BYTE* v11;           // esi
	struc_19* v12;        // eax
	int v13;              // eax
	int v14;              // eax
	char v15;             // bl
	char v16;             // bl
	unsigned __int8* v17; // esi
	int v18;              // edi
	unsigned __int8* v19; // eax
	unsigned __int8* v20; // edi
	unsigned __int8* v21; // ebx
	char v22;             // [esp+2h] [ebp-3Ah]
	char v23;             // [esp+3h] [ebp-39h]
	int v24;              // [esp+4h] [ebp-38h]
	int v25;              // [esp+8h] [ebp-34h]
	int v26;              // [esp+Ch] [ebp-30h]
	int v27;              // [esp+10h] [ebp-2Ch]
	int v28;              // [esp+14h] [ebp-28h]
	int v29;              // [esp+18h] [ebp-24h]
	int v30;              // [esp+1Ch] [ebp-20h]
	int v31;              // [esp+20h] [ebp-1Ch]
	int2 v32;             // [esp+24h] [ebp-18h]
	int4 v33;             // [esp+2Ch] [ebp-10h]

	v31 = sub_426A30();
	if (!getMemByte(0x5D4594, 741372))
		*getMemU8Ptr(0x5D4594, 741372) = sub_410D60("MagicWallSystemUseOnly");
	sub_4297B0();
	sub_429520();
	v28 = 7;
	sub_426AC0_file3_fread(&v28, 2u);
	if ((__int16)v28 > 7)
		return 0;
	if ((__int16)v28 < 6)
		return sub_42A150(v28, a1);
	v2 = a1;
	if (!*getMemU32Ptr(0x5D4594, 3803300)) {
		if (a1) {
			sub_428170(a1, &v33);
			*getMemU32Ptr(0x5D4594, 741360) = v33.field_0 / 23;
			v3 = v33.field_8 / 23;
			dword_5d4594_741356 = v33.field_8 / 23;
			*getMemU32Ptr(0x5D4594, 741368) = v33.field_4 / 23;
			v5 = v33.field_C / 23;
			dword_5d4594_741364 = v5;
		} else {
			*getMemU32Ptr(0x5D4594, 741368) = 256;
			*getMemU32Ptr(0x5D4594, 741360) = 256;
			dword_5d4594_741364 = 0;
			dword_5d4594_741356 = 0;
			sub_410640(sub_42A0F0, 0);
			v3 = dword_5d4594_741356;
			v5 = dword_5d4594_741364;
		}
		v25 = v3 - *getMemU32Ptr(0x5D4594, 741360) + 1;
		v27 = v5 - *getMemU32Ptr(0x5D4594, 741368) + 1;
	}
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 741360), 4u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 741368), 4u);
	sub_426AC0_file3_fread(&v25, 4u);
	sub_426AC0_file3_fread(&v27, 4u);
	v26 = 0;
	v29 = 0;
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		if (v2) {
			sub_428170(v2, &v33);
			v13 = v33.field_0 / 23 - *getMemU32Ptr(0x5D4594, 741360);
			*getMemU32Ptr(0x5D4594, 741360) = v33.field_0 / 23;
			v29 = v13;
			v14 = v33.field_4 / 23 - *getMemU32Ptr(0x5D4594, 741368);
			*getMemU32Ptr(0x5D4594, 741368) = v33.field_4 / 23;
			v26 = v14;
		}
		sub_426AC0_file3_fread(&v22, 1u);
		v15 = v22;
		if (v22 == -1)
			return 1;
		while (1) {
			sub_426AC0_file3_fread(&a1, 1u);
			LOBYTE(v30) = v29 + v15;
			LOBYTE(a1) = v26 + (_BYTE)a1;
			sub_426AC0_file3_fread(&v24, 1u);
			v16 = (unsigned __int8)v24 >> 7;
			LOBYTE(v24) = v24 & 0x7F;
			if (nox_common_gameFlags_check_40A5C0(0x400000)) {
				v17 = (unsigned __int8*)*sub_504290(v30, (char)a1);
			} else {
				v18 = (unsigned __int8)v30;
				v19 = (unsigned __int8*)nox_server_getWallAtPoint_410580((unsigned __int8)v30, (unsigned __int8)a1);
				v17 = v19;
				if (v19) {
					if (v31 & 1)
						*v19 = sub_42A6C0(*v19, v24);
					else
						*v19 = v24;
					goto LABEL_46;
				}
				v17 = (unsigned __int8*)sub_410250(v18, (unsigned __int8)a1);
				if (!v17)
					return 0;
			}
			*v17 = v24;
		LABEL_46:
			if (v16)
				v17[4] |= 0x80u;
			v20 = v17 + 1;
			sub_426AC0_file3_fread(v17 + 1, 1u);
			v21 = v17 + 2;
			sub_426AC0_file3_fread(v17 + 2, 1u);
			if (v31 & 1 && *v21 >= sub_410DD0(*v20, *v17, 0))
				*v21 = 0;
			v17[7] = sub_410E20(*v20);
			if ((_WORD)v28 == 6) {
				sub_426AC0_file3_fread(&v24, 1u);
				v17[8] = 1;
				*((_DWORD*)v17 + 3) = 0;
			} else {
				sub_426AC0_file3_fread(v17 + 8, 1u);
				sub_426AC0_file3_fread(&v24, 1u);
				*((_DWORD*)v17 + 3) = (unsigned __int8)v24;
			}
			sub_426AC0_file3_fread(&v22, 1u);
			v15 = v22;
			if (v22 == -1)
				return 1;
		}
	}
	v6 = *getMemU32Ptr(0x5D4594, 741368);
	v26 = *getMemU32Ptr(0x5D4594, 741368);
	if (*getMemU32Ptr(0x5D4594, 741368) <= *getMemIntPtr(0x5D4594, 741368) + v27) {
		v7 = v25;
		v8 = *getMemU32Ptr(0x5D4594, 741360);
		do {
			v9 = v8;
			v29 = v8;
			if (v8 <= v8 + v7) {
				do {
					v10 = (_BYTE*)nox_server_getWallAtPoint_410580(v9, v26);
					v11 = v10;
					if (v10) {
						if (v10[1] != getMemByte(0x5D4594, 741372)) {
							if (!v2 || (v32.field_0 = 23 * (unsigned __int8)v10[5],
										v32.field_4 = 23 * (unsigned __int8)v10[6], sub_427F30(&v32, v2))) {
								sub_426AC0_file3_fread(v11 + 5, 1u);
								sub_426AC0_file3_fread(v11 + 6, 1u);
								if ((int)v11[4] >= 0)
									LOBYTE(v24) = *v11;
								else
									LOBYTE(v24) = *v11 | 0x80;
								sub_426AC0_file3_fread(&v24, 1u);
								sub_426AC0_file3_fread(v11 + 1, 1u);
								sub_426AC0_file3_fread(v11 + 2, 1u);
								v32.field_0 = 23 * (unsigned __int8)v11[5] + 11;
								v32.field_4 = 23 * (unsigned __int8)v11[6] + 11;
								v12 = sub_4217B0(&v32, 0);
								if (v12 || (v12 = (struc_19*)sub_421990(&v32, 10.0, 0)) != 0)
									v23 = BYTE2(v12->field_0[32]);
								else
									v23 = 100;
								sub_426AC0_file3_fread(&v23, 1u);
								if (nox_common_gameFlags_check_40A5C0(0x200000))
									LOBYTE(v24) = 0;
								else
									LOBYTE(v24) = v11[12];
								sub_426AC0_file3_fread(&v24, 1u);
								v2 = a1;
								v9 = v29;
							}
						}
					}
					v8 = *getMemU32Ptr(0x5D4594, 741360);
					v7 = v25;
					v29 = ++v9;
				} while (v9 <= *getMemIntPtr(0x5D4594, 741360) + v25);
				v6 = *getMemU32Ptr(0x5D4594, 741368);
			}
			++v26;
		} while (v26 <= v6 + v27);
	}
	v22 = -1;
	sub_426AC0_file3_fread(&v22, 1u);
	return 1;
}

//----- (0042A0F0) --------------------------------------------------------
int __cdecl sub_42A0F0(int a1) {
	int result; // eax

	if ((int)*(unsigned __int8*)(a1 + 5) < *getMemIntPtr(0x5D4594, 741360))
		*getMemU32Ptr(0x5D4594, 741360) = *(unsigned __int8*)(a1 + 5);
	if ((int)*(unsigned __int8*)(a1 + 5) > *(int*)&dword_5d4594_741356)
		dword_5d4594_741356 = *(unsigned __int8*)(a1 + 5);
	if ((int)*(unsigned __int8*)(a1 + 6) < *getMemIntPtr(0x5D4594, 741368))
		*getMemU32Ptr(0x5D4594, 741368) = *(unsigned __int8*)(a1 + 6);
	result = *(unsigned __int8*)(a1 + 6);
	if (result > *(int*)&dword_5d4594_741364)
		dword_5d4594_741364 = *(unsigned __int8*)(a1 + 6);
	return result;
}

//----- (0042A150) --------------------------------------------------------
int __cdecl sub_42A150(__int16 a1, _DWORD* a2) {
	int v2;                // eax
	_DWORD* v3;            // ebx
	int v4;                // edi
	int v5;                // esi
	int v6;                // edx
	int v7;                // edx
	int v8;                // ebp
	int v9;                // ecx
	int v10;               // eax
	int v11;               // edi
	int v12;               // eax
	_BYTE* v13;            // esi
	struc_19* v14;         // eax
	int v16;               // eax
	int v17;               // ebp
	unsigned __int8 v18;   // bl
	char v19;              // bl
	unsigned __int8** v20; // eax
	unsigned __int8* v21;  // esi
	unsigned __int8* v22;  // eax
	unsigned __int8 v23;   // al
	__int16 v24;           // bx
	unsigned __int8* v25;  // edi
	char v26;              // [esp+13h] [ebp-2Dh]
	int v27;               // [esp+14h] [ebp-2Ch]
	int v28;               // [esp+18h] [ebp-28h]
	int v29;               // [esp+1Ch] [ebp-24h]
	int v30;               // [esp+20h] [ebp-20h]
	int v31;               // [esp+24h] [ebp-1Ch]
	int2 v32;              // [esp+28h] [ebp-18h]
	int4 v33;              // [esp+30h] [ebp-10h]

	v2 = sub_426A30();
	v3 = a2;
	v30 = v2;
	v4 = 0;
	if (!*getMemU32Ptr(0x5D4594, 3803300)) {
		if (a2) {
			sub_428170(a2, &v33);
			*getMemU32Ptr(0x5D4594, 741360) = v33.field_0 / 23;
			v5 = v33.field_8 / 23;
			dword_5d4594_741356 = v33.field_8 / 23;
			*getMemU32Ptr(0x5D4594, 741368) = v33.field_4 / 23;
			v6 = v33.field_C / 23;
			dword_5d4594_741364 = v33.field_C / 23;
		} else {
			*getMemU32Ptr(0x5D4594, 741368) = 256;
			*getMemU32Ptr(0x5D4594, 741360) = 256;
			dword_5d4594_741364 = 0;
			dword_5d4594_741356 = 0;
			sub_410640(sub_42A0F0, 0);
			v5 = dword_5d4594_741356;
			v6 = dword_5d4594_741364;
		}
		v28 = v5 - *getMemU32Ptr(0x5D4594, 741360) + 1;
		v29 = v6 - *getMemU32Ptr(0x5D4594, 741368) + 1;
	}
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 741360), 4u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 741368), 4u);
	sub_426AC0_file3_fread(&v28, 4u);
	sub_426AC0_file3_fread(&v29, 4u);
	if (!*getMemU32Ptr(0x5D4594, 3803300)) {
		v7 = *getMemU32Ptr(0x5D4594, 741368);
		v8 = *getMemU32Ptr(0x5D4594, 741368);
		if (*getMemU32Ptr(0x5D4594, 741368) > *getMemIntPtr(0x5D4594, 741368) + v29)
			return 1;
		v9 = v28;
		v10 = *getMemU32Ptr(0x5D4594, 741360);
		while (1) {
			v11 = v10;
			if (v10 > v10 + v9)
				goto LABEL_27;
			do {
				v12 = nox_server_getWallAtPoint_410580(v11, v8);
				v13 = (_BYTE*)v12;
				if (v3) {
					if (!v12)
						goto LABEL_15;
					v32.field_0 = 23 * *(unsigned __int8*)(v12 + 5);
					v32.field_4 = 23 * *(unsigned __int8*)(v12 + 6);
					if (!sub_427F30(&v32, v3)) {
						v13 = 0;
						LOBYTE(v27) = -1;
						goto LABEL_19;
					}
				}
				if (!v13) {
				LABEL_15:
					LOBYTE(v27) = -1;
					goto LABEL_19;
				}
				if ((int)v13[4] >= 0)
					LOBYTE(v27) = *v13;
				else
					LOBYTE(v27) = *v13 | 0x80;
			LABEL_19:
				sub_426AC0_file3_fread(&v27, 1u);
				if ((_BYTE)v27 != (_BYTE)-1) {
					sub_426AC0_file3_fread(v13 + 1, 1u);
					sub_426AC0_file3_fread(v13 + 2, 1u);
					v32.field_0 = 23 * (unsigned __int8)v13[5] + 11;
					v32.field_4 = 23 * (unsigned __int8)v13[6] + 11;
					v14 = sub_4217B0(&v32, 0);
					if (v14 || (v14 = (struc_19*)sub_421990(&v32, 10.0, 0)) != 0)
						v26 = BYTE2(v14->field_0[32]);
					else
						v26 = 1;
					sub_426AC0_file3_fread(&v26, 1u);
					LOBYTE(a1) = v13[12];
					sub_426AC0_file3_fread(&a1, 1u);
				}
				v10 = *getMemU32Ptr(0x5D4594, 741360);
				v9 = v28;
				++v11;
			} while (v11 <= *getMemIntPtr(0x5D4594, 741360) + v28);
			v7 = *getMemU32Ptr(0x5D4594, 741368);
		LABEL_27:
			if (++v8 > v7 + v29)
				return 1;
		}
	}
	if (v3) {
		sub_428170(v3, &v33);
		*getMemU32Ptr(0x5D4594, 741360) = v33.field_0 / 23;
		*getMemU32Ptr(0x5D4594, 741368) = v33.field_4 / 23;
	}
	v31 = 0;
	if (v29 < 0)
		return 1;
	v16 = v28;
	while (1) {
		v17 = 0;
		if (v16 >= 0)
			break;
	LABEL_60:
		v31 = ++v4;
		if (v4 > v29)
			return 1;
	}
	while (1) {
		sub_426AC0_file3_fread(&v27, 1u);
		if ((_BYTE)v27 != (_BYTE)-1)
			break;
	LABEL_59:
		v16 = v28;
		if (++v17 > v28)
			goto LABEL_60;
	}
	v18 = v27;
	LOBYTE(v27) = v27 & 0x7F;
	v19 = v18 >> 7;
	if (nox_common_gameFlags_check_40A5C0(0x400000)) {
		v20 = (unsigned __int8**)sub_504290(v17 + getMemByte(0x5D4594, 741360), v4 + getMemByte(0x5D4594, 741368));
		v21 = *v20;
		**v20 = v27;
	LABEL_43:
		if (v19)
			v21[4] |= 0x80u;
		v24 = a1;
		if (a1 < 2) {
			v21[1] = 0;
			v21[7] = sub_410E20(0);
			v21[8] = 1;
		} else {
			v25 = v21 + 1;
			sub_426AC0_file3_fread(v21 + 1, 1u);
			if (v24 >= 3)
				sub_426AC0_file3_fread(v21 + 2, 1u);
			else
				sub_42A650(v21);
			if (v30 & 1 && v21[2] >= sub_410DD0(*v25, *v21, 0))
				v21[2] = 0;
			v21[7] = sub_410E20(*v25);
			if (v24 < 4)
				v21[8] = 1;
			else
				sub_426AC0_file3_fread(v21 + 8, 1u);
			LOBYTE(a2) = 0;
			if (v24 >= 5)
				sub_426AC0_file3_fread(&a2, 1u);
			v4 = v31;
			*((_DWORD*)v21 + 3) = (unsigned __int8)a2;
		}
		goto LABEL_59;
	}
	v22 = (unsigned __int8*)nox_server_getWallAtPoint_410580(v17 + *getMemU32Ptr(0x5D4594, 741360),
															 v4 + *getMemU32Ptr(0x5D4594, 741368));
	v21 = v22;
	if (v22) {
		if (v30 & 1) {
			v23 = sub_42A6C0(*v22, v27);
		LABEL_42:
			*v21 = v23;
			goto LABEL_43;
		}
	LABEL_41:
		v23 = v27;
		goto LABEL_42;
	}
	v21 = (unsigned __int8*)sub_410250(v17 + *getMemU32Ptr(0x5D4594, 741360), v4 + *getMemU32Ptr(0x5D4594, 741368));
	if (v21)
		goto LABEL_41;
	return 0;
}

//----- (0042A650) --------------------------------------------------------
int __cdecl sub_42A650(unsigned __int8* a1) {
	unsigned __int8 v1; // cl
	int result;         // eax

	v1 = *a1;
	a1[2] = 0;
	if (!v1)
		a1[2] = a1[5] % 3;
	if (v1 == 1)
		a1[2] = a1[5] % 3;
	result = sub_46A3B0(a1[1], v1, a1[2], (a1[4] >> 2) & 2);
	if (!result)
		a1[2] = 0;
	return result;
}

//----- (0042A6C0) --------------------------------------------------------
unsigned __int8 __cdecl sub_42A6C0(unsigned __int8 a1, unsigned __int8 a2) { return getMemByte(0x587000, 13 * a1 + 71276 + a2); }

//----- (0042A6E0) --------------------------------------------------------
int nox_server_mapRWMapInfo_42A6E0() {
	__int16 v0; // ax
	int v2;     // [esp+0h] [ebp-8h]
	int v3;     // [esp+4h] [ebp-4h]

	v3 = 3;
	sub_426AC0_file3_fread(&v3, 2u);
	v0 = v3;
	if ((__int16)v3 > 3)
		return 0;
	if ((__int16)v3 >= 1) {
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836), 0x40u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 64), 0x200u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 576), 0x10u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 592), 0x40u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 656), 0x40u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 720), 0x80u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 848), 0x80u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 976), 0x100u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 1232), 0x80u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 1360), 0x20u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 1392), 4u);
		v0 = v3;
		if ((_WORD)v3 == 2) {
			sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 1396), 1u);
			sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 1397), 1u);
			v0 = v3;
		} else if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
			*getMemU8Ptr(0x5D4594, 3801836 + 1396) = 2;
			*getMemU8Ptr(0x5D4594, 3801836 + 1397) = 16;
		}
	}
	if (v0 < 3) {
		*getMemU8Ptr(0x5D4594, 3801836 + 1398) = getMemByte(0x5D4594, 741376);
		*getMemU8Ptr(0x5D4594, 3801836 + 1430) = getMemByte(0x5D4594, 741380);
	} else {
		LOBYTE(v2) = strlen((const char*)getMemAt(0x5D4594, 3801836 + 1398));
		sub_426AC0_file3_fread(&v2, 1u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 1398), (unsigned __int8)v2);
		*getMemU8Ptr(0x5D4594, 3801836 + 1398 + (unsigned __int8)v2) = 0;
		LOBYTE(v2) = strlen((const char*)getMemAt(0x5D4594, 3801836 + 1430));
		sub_426AC0_file3_fread(&v2, 1u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 3801836 + 1430), (unsigned __int8)v2);
		*getMemU8Ptr(0x5D4594, 3801836 + 1430 + (unsigned __int8)v2) = 0;
	}
	return 1;
}

//----- (0042A8B0) --------------------------------------------------------
uint16_t* __cdecl sub_42A8B0(_BYTE* a1, int* a2) {
	int v2;                  // eax
	_BYTE* v3;               // esi
	_BYTE* v4;               // ebx
	uint16_t* result;         // eax
	int v6;                  // esi
	void* v7;                // eax
	int v8;                  // eax
	uint16_t* v9;             // esi
	unsigned __int8 v10[12]; // [esp+Ch] [ebp-Ch]

	*(_WORD*)v10 = 0;
	*(_WORD*)&v10[2] = 0;
	v2 = *a2;
	*(_DWORD*)&v10[4] = 0;
	v3 = malloc(2 * v2);
	sub_42A970(a1, v3, a2);
	v4 = sub_42AC50(v3, (size_t*)a2);
	if (v3)
		free(v3);
	if (v4) {
		v6 = *a2;
		v7 = operator_new(0x10u);
		if (v7)
			v8 = sub_42C910((int)v7, (char*)getMemAt(0x587000, 71480), v4, v6);
		else
			v8 = 0;
		sub_42C360(v10, v8);
		free(v4);
		v9 = sub_42C480(v10, (unsigned int*)a2);
		sub_42C330(v10);
		result = v9;
	} else {
		sub_42C330(v10);
		result = 0;
	}
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042A970) --------------------------------------------------------
int __cdecl sub_42A970(_BYTE* a1, _BYTE* a2, int* a3) {
	int v3;              // eax
	char v4;             // bl
	int v5;              // edx
	int v6;              // ecx
	int v7;              // esi
	int v8;              // eax
	int* v9;             // edx
	_BYTE* v10;          // ebp
	int v11;             // edi
	char v12;            // cl
	int result;          // eax
	int v14;             // edx
	int v15;             // eax
	int v16;             // ebp
	char v17;            // [esp+13h] [ebp-405h]
	unsigned __int8 v18; // [esp+14h] [ebp-404h]
	int v19[256];        // [esp+18h] [ebp-400h]

	v3 = 0;
	v4 = 1;
	memset(v19, 0, sizeof(v19));
	v18 = 1;
	v5 = *a3;
	if (*a3 > 0) {
		do {
			v6 = (unsigned __int8)a1[v3++];
			++v19[v6];
		} while (v3 < v5);
	}
	v7 = v19[0];
	v17 = 0;
	v8 = 0;
	v9 = v19;
	while (*v9) {
		if (*v9 < v7) {
			v7 = *v9;
			v17 = v8;
		}
		++v8;
		++v9;
		if (v8 >= 256)
			goto LABEL_10;
	}
	v17 = v8;
LABEL_10:
	v10 = a1;
	v11 = 1;
	*a2 = v17;
	v12 = *a1;
	result = 1;
	v14 = *a3;
	if ((int)*a3 < 1) {
		*a3 = 1;
	} else {
		do {
			if (v10[v11] != v12 || v11 >= v14) {
				if ((unsigned __int8)v4 <= 3u) {
					if ((int)v18 > 0) {
						v16 = v18;
						do {
							if (v12 == v17)
								a2[result++] = v12;
							a2[result++] = v12;
							--v16;
						} while (v16);
					}
				} else {
					a2[result] = v17;
					v15 = result + 1;
					a2[v15++] = v4;
					a2[v15] = v12;
					result = v15 + 1;
				}
				v10 = a1;
				v4 = 1;
				v12 = a1[v11];
			} else {
				++v4;
			}
			++v11;
			v18 = v4;
			v14 = *a3;
		} while (v11 <= *a3);
		*a3 = result;
	}
	return result;
}
// 42A970: using guessed type int var_400[256];

//----- (0042AAA0) --------------------------------------------------------
double __cdecl sub_42AAA0(int* a1) {
	int v1;              // eax
	int v2;              // esi
	int v3;              // edi
	int v4;              // ecx
	int v5;              // edi
	int v6;              // esi
	unsigned __int8* v7; // ecx
	int v8;              // eax
	int v9;              // edx
	int v10;             // ecx
	int v11;             // eax
	int v13;             // [esp+Ch] [ebp+4h]

	if ((int)*a1 < 0 || !*getMemU32Ptr(0x5D4594, 741656)) {
		*getMemU32Ptr(0x5D4594, 741656) = 1;
		v1 = *a1;
		if ((int)*a1 < 0)
			v1 = -v1;
		v2 = 1;
		v3 = 21;
		v4 = (161803398 - v1) % 1000000000;
		*getMemU32Ptr(0x5D4594, 741604) = (161803398 - v1) % 1000000000;
		do {
			*getMemU32Ptr(0x5D4594, 4 * (v3 % 55) + 741384) = v2;
			v2 = v4 - v2 + (v4 - v2 < 0 ? 0x3B9ACA00 : 0);
			v4 = *getMemU32Ptr(0x5D4594, 4 * (v3 % 55) + 741384);
			v3 += 21;
		} while (v3 <= 1134);
		v5 = 4;
		do {
			v6 = 1;
			v7 = getMemAt(0x5D4594, 741388);
			do {
				v8 = *(_DWORD*)v7 - *getMemU32Ptr(0x5D4594, 4 * ((v6 + 30) % 55) + 741388);
				*(_DWORD*)v7 = v8;
				if (v8 < 0)
					*(_DWORD*)v7 = v8 + 1000000000;
				v7 += 4;
				++v6;
			} while ((int)v7 <= (int)getMemAt(0x5D4594, 741604));
			--v5;
		} while (v5);
		dword_5d4594_741648 = 0;
		dword_5d4594_741652 = 31;
		*a1 = 1;
	}
	v9 = ++dword_5d4594_741648;
	if (dword_5d4594_741648 == 56) {
		v9 = 1;
		dword_5d4594_741648 = 1;
	}
	v10 = ++dword_5d4594_741652;
	if (dword_5d4594_741652 == 56) {
		v10 = 1;
		dword_5d4594_741652 = 1;
	}
	v11 = *getMemU32Ptr(0x5D4594, 4 * v9 + 741384) - *getMemU32Ptr(0x5D4594, 4 * v10 + 741384);
	v13 = v11;
	if (v11 < 0) {
		v11 += 1000000000;
		v13 = v11;
	}
	*getMemU32Ptr(0x5D4594, 4 * v9 + 741384) = v11;
	return (double)v13 * *getMemDoublePtr(0x581450, 8368);
}

//----- (0042ABF0) --------------------------------------------------------
void __cdecl sub_42ABF0(int a1, int a2, int a3) {
	double v3;  // st7
	int i;      // esi
	__int64 v5; // rax

	if (a3 > 0)
		a3 = -a3;
	v3 = sub_42AAA0(&a3);
	for (i = 0; i < a2; ++i) {
		v5 = (__int64)(v3 * 255.0);
		if ((int)v5 < 0)
			LODWORD(v5) = -(int)v5;
		*(_BYTE*)(i + a1) = v5;
		v3 = sub_42AAA0(&a3);
	}
}

//----- (0042AC50) --------------------------------------------------------
_BYTE* __cdecl sub_42AC50(_BYTE* a1, size_t* a2) {
	size_t* v2;          // esi
	void* v3;            // ebp
	size_t v4;           // ecx
	_BYTE* v5;           // edi
	_BYTE* result;       // eax
	time_t v7;           // eax
	int v8;              // ebx
	u_long v9;           // eax
	time_t v10;          // eax
	unsigned __int8 v11; // al
	int v12;             // ebp
	int v13;             // ecx
	_BYTE* v14;          // edx
	int v15;             // ebx
	char v16;            // al
	int v17;             // [esp-Ch] [ebp-28h]
	void* v18;           // [esp-8h] [ebp-24h]
	time_t v19;          // [esp+Ch] [ebp-10h]
	LPVOID lpMem;        // [esp+10h] [ebp-Ch]
	int v21;             // [esp+14h] [ebp-8h]
	u_long v22;          // [esp+18h] [ebp-4h]
	float v23;           // [esp+24h] [ebp+8h]
	unsigned __int8 v24; // [esp+24h] [ebp+8h]

	v2 = a2;
	v19 = 0;
	v3 = malloc(*a2);
	v4 = *a2 + 5;
	lpMem = v3;
	v5 = malloc(v4);
	if ((int)*a2 >= 15) {
		v7 = time(0);
		v8 = v7;
		if (v7 > 0)
			v8 = -v7;
		v9 = htonl(v8);
		v17 = *a2;
		v22 = v9;
		sub_42ABF0((int)v3, v17, v8);
		v10 = time(0);
		v19 = v10;
		if (v10 > 0)
			v19 = -v10;
		if ((int)*a2 >= 241)
			v23 = 241.0;
		else
			v23 = (double)(int)(*a2 - 14);
		v11 = (unsigned __int64)(__int64)(sub_42AAA0(&v19) * v23) + 10;
		v12 = 0;
		v13 = 0;
		v24 = v11;
		if ((int)*v2 > 0) {
			v21 = v11;
			v14 = a1;
			v15 = (_BYTE*)lpMem - a1;
			while (1) {
				if (v13 == 5) {
					v5[5] = v11;
					v13 = 6;
				}
				if (v13 == v21) {
					*(_DWORD*)&v5[v13] = v22;
					v13 += 4;
				}
				v16 = *v14 ^ v14[v15];
				++v13;
				++v12;
				++v14;
				v5[v13 - 1] = v16;
				if (v12 >= (int)*v2)
					break;
				v11 = v24;
			}
		}
		v18 = lpMem;
		*v2 += 5;
		free(v18);
		result = v5;
	} else {
		*a2 = -2;
		free(v3);
		free(v5);
		result = 0;
	}
	return result;
}

//----- (0042ADA0) --------------------------------------------------------
uint16_t* __cdecl sub_42ADA0(int a1, int a2, __int16 a3, unsigned int* a4) {
	int v4;           // esi
	int v5;           // edi
	void* v6;         // eax
	int v7;           // eax
	int v8;           // edi
	void* v9;         // eax
	int v10;          // eax
	int v11;          // edi
	void* v12;        // eax
	int v13;          // eax
	int v14;          // edi
	void* v15;        // eax
	int v16;          // eax
	void* v17;        // eax
	int v18;          // eax
	int v19;          // edi
	void* v20;        // eax
	int v21;          // eax
	int v22;          // edi
	void* v23;        // eax
	int v24;          // eax
	void* v25;        // eax
	int v26;          // eax
	int v27;          // edi
	void* v28;        // eax
	int v29;          // eax
	int v30;          // edi
	void* v31;        // eax
	int v32;          // eax
	int v33;          // edi
	void* v34;        // eax
	int v35;          // eax
	int v36;          // edi
	void* v37;        // eax
	int v38;          // eax
	void* v39;        // eax
	int v40;          // eax
	void* v41;        // eax
	int v42;          // eax
	void* v43;        // eax
	int v44;          // eax
	void* v45;        // eax
	int v46;          // eax
	void* v47;        // eax
	int v48;          // eax
	int v49;          // edi
	void* v50;        // eax
	int v51;          // eax
	int v52;          // edi
	void* v53;        // eax
	int v54;          // eax
	int v55;          // edi
	void* v56;        // eax
	int v57;          // eax
	int v58;          // edi
	void* v59;        // eax
	int v60;          // eax
	void* v61;        // eax
	int v62;          // eax
	void* v63;        // eax
	int v64;          // eax
	void* v65;        // eax
	int v66;          // eax
	int v67;          // edi
	void* v68;        // eax
	int v69;          // eax
	int v70;          // edi
	void* v71;        // eax
	int v72;          // eax
	void* v73;        // eax
	int v74;          // eax
	void* v75;        // eax
	int v76;          // eax
	void* v77;        // eax
	int v78;          // eax
	void* v79;        // eax
	int v80;          // eax
	void* v81;        // eax
	int v82;          // eax
	int v83;          // eax
	char v84;         // di
	void* v85;        // eax
	int v86;          // eax
	void* v87;        // eax
	int v88;          // eax
	__int16 v89;      // di
	void* v90;        // eax
	int v91;          // eax
	int v92;          // eax
	const char* v93;  // edi
	void* v94;        // eax
	int v95;          // eax
	int v96;          // edi
	void* v97;        // eax
	int v98;          // eax
	int v99;          // edi
	void* v100;       // eax
	int v101;         // eax
	void* v102;       // eax
	int v103;         // eax
	void* v104;       // eax
	int v105;         // eax
	int v106;         // edi
	void* v107;       // eax
	int v108;         // eax
	void* v109;       // eax
	int v110;         // eax
	const void* v111; // esi
	void* v112;       // eax
	int v113;         // eax
	int v114;         // eax
	uint16_t* v115;    // esi
	char v117;        // [esp+Ch] [ebp-10h]
	char v118[12];    // [esp+10h] [ebp-Ch]
	char v119;        // [esp+20h] [ebp+4h]
	char v120;        // [esp+20h] [ebp+4h]
	char v121;        // [esp+20h] [ebp+4h]
	char v122;        // [esp+20h] [ebp+4h]
	char v123;        // [esp+20h] [ebp+4h]
	char v124;        // [esp+20h] [ebp+4h]
	char v125;        // [esp+20h] [ebp+4h]
	char v126;        // [esp+20h] [ebp+4h]
	char v127;        // [esp+20h] [ebp+4h]
	char v128;        // [esp+20h] [ebp+4h]
	char v129;        // [esp+24h] [ebp+8h]

	v4 = a1;
	v5 = *(_DWORD*)(a1 + 8);
	*(_WORD*)v118 = 0;
	*(_WORD*)&v118[2] = 0;
	*(_DWORD*)&v118[4] = 0;
	v6 = operator_new(0x10u);
	if (v6)
		v7 = sub_42C8B0((int)v6, (char*)getMemAt(0x587000, 71632), v5);
	else
		v7 = 0;
	sub_42C360(v118, v7);
	v8 = *(_DWORD*)(a1 + 12);
	v9 = operator_new(0x10u);
	if (v9)
		v10 = sub_42C8B0((int)v9, (char*)getMemAt(0x587000, 71640), v8);
	else
		v10 = 0;
	sub_42C360(v118, v10);
	v11 = *(_DWORD*)(a1 + 16);
	v12 = operator_new(0x10u);
	if (v12)
		v13 = sub_42C8B0((int)v12, (char*)getMemAt(0x587000, 71648), v11);
	else
		v13 = 0;
	sub_42C360(v118, v13);
	v14 = *(_DWORD*)(a1 + 20);
	v15 = operator_new(0x10u);
	if (v15)
		v16 = sub_42C8B0((int)v15, (char*)getMemAt(0x587000, 71656), v14);
	else
		v16 = 0;
	sub_42C360(v118, v16);
	v119 = *(_BYTE*)(a1 + 24);
	v17 = operator_new(0x10u);
	if (v17)
		v18 = sub_42C7F0((int)v17, (char*)getMemAt(0x587000, 71664), v119);
	else
		v18 = 0;
	sub_42C360(v118, v18);
	v19 = *(_DWORD*)(v4 + 32);
	v20 = operator_new(0x10u);
	if (v20)
		v21 = sub_42C8B0((int)v20, (char*)getMemAt(0x587000, 71672), v19);
	else
		v21 = 0;
	sub_42C360(v118, v21);
	v22 = *(_DWORD*)(v4 + 36);
	v23 = operator_new(0x10u);
	if (v23)
		v24 = sub_42C8B0((int)v23, (char*)getMemAt(0x587000, 71680), v22);
	else
		v24 = 0;
	sub_42C360(v118, v24);
	v120 = *(_BYTE*)(v4 + 40);
	v25 = operator_new(0x10u);
	if (v25)
		v26 = sub_42C7F0((int)v25, (char*)getMemAt(0x587000, 71688), v120);
	else
		v26 = 0;
	sub_42C360(v118, v26);
	v27 = *(_DWORD*)(v4 + 44);
	v28 = operator_new(0x10u);
	if (v28)
		v29 = sub_42C8B0((int)v28, (char*)getMemAt(0x587000, 71696), v27);
	else
		v29 = 0;
	sub_42C360(v118, v29);
	v30 = *(_DWORD*)(v4 + 48);
	v31 = operator_new(0x10u);
	if (v31)
		v32 = sub_42C8B0((int)v31, (char*)getMemAt(0x587000, 71704), v30);
	else
		v32 = 0;
	sub_42C360(v118, v32);
	v33 = *(_DWORD*)(v4 + 52);
	v34 = operator_new(0x10u);
	if (v34)
		v35 = sub_42C8B0((int)v34, (char*)getMemAt(0x587000, 71712), v33);
	else
		v35 = 0;
	sub_42C360(v118, v35);
	v36 = *(_DWORD*)(v4 + 56);
	v37 = operator_new(0x10u);
	if (v37)
		v38 = sub_42C8B0((int)v37, (char*)getMemAt(0x587000, 71720), v36);
	else
		v38 = 0;
	sub_42C360(v118, v38);
	v121 = *(_BYTE*)(v4 + 60);
	v39 = operator_new(0x10u);
	if (v39)
		v40 = sub_42C7F0((int)v39, (char*)getMemAt(0x587000, 71728), v121);
	else
		v40 = 0;
	sub_42C360(v118, v40);
	v122 = *(_BYTE*)(v4 + 61);
	v41 = operator_new(0x10u);
	if (v41)
		v42 = sub_42C7F0((int)v41, (char*)getMemAt(0x587000, 71736), v122);
	else
		v42 = 0;
	sub_42C360(v118, v42);
	v123 = *(_BYTE*)(v4 + 25);
	v43 = operator_new(0x10u);
	if (v43)
		v44 = sub_42C7F0((int)v43, (char*)getMemAt(0x587000, 71744), v123);
	else
		v44 = 0;
	sub_42C360(v118, v44);
	v45 = operator_new(0x10u);
	if (v45)
		v46 = sub_42C8E0((int)v45, (char*)getMemAt(0x587000, 71752), (const char*)(v4 + 96));
	else
		v46 = 0;
	sub_42C360(v118, v46);
	v47 = operator_new(0x10u);
	if (v47)
		v48 = sub_42C8E0((int)v47, (char*)getMemAt(0x587000, 71760), (const char*)(v4 + 352));
	else
		v48 = 0;
	sub_42C360(v118, v48);
	v49 = *(_DWORD*)(v4 + 64);
	v50 = operator_new(0x10u);
	if (v50)
		v51 = sub_42C8B0((int)v50, (char*)getMemAt(0x587000, 71768), v49);
	else
		v51 = 0;
	sub_42C360(v118, v51);
	v52 = *(_DWORD*)(v4 + 68);
	v53 = operator_new(0x10u);
	if (v53)
		v54 = sub_42C8B0((int)v53, (char*)getMemAt(0x587000, 71776), v52);
	else
		v54 = 0;
	sub_42C360(v118, v54);
	v55 = *(_DWORD*)(v4 + 72);
	v56 = operator_new(0x10u);
	if (v56)
		v57 = sub_42C8B0((int)v56, (char*)getMemAt(0x587000, 71784), v55);
	else
		v57 = 0;
	sub_42C360(v118, v57);
	v58 = *(_DWORD*)(v4 + 88);
	v59 = operator_new(0x10u);
	if (v59)
		v60 = sub_42C8B0((int)v59, (char*)getMemAt(0x587000, 71792), v58);
	else
		v60 = 0;
	sub_42C360(v118, v60);
	v124 = *(_BYTE*)(v4 + 84);
	v61 = operator_new(0x10u);
	if (v61)
		v62 = sub_42C7F0((int)v61, (char*)getMemAt(0x587000, 71800), v124);
	else
		v62 = 0;
	sub_42C360(v118, v62);
	v125 = *(_BYTE*)(v4 + 85);
	v63 = operator_new(0x10u);
	if (v63)
		v64 = sub_42C7F0((int)v63, (char*)getMemAt(0x587000, 71808), v125);
	else
		v64 = 0;
	sub_42C360(v118, v64);
	v126 = *(_BYTE*)(v4 + 86);
	v65 = operator_new(0x10u);
	if (v65)
		v66 = sub_42C7F0((int)v65, (char*)getMemAt(0x587000, 71816), v126);
	else
		v66 = 0;
	sub_42C360(v118, v66);
	v67 = *(_DWORD*)(v4 + 92);
	v68 = operator_new(0x10u);
	if (v68)
		v69 = sub_42C8B0((int)v68, (char*)getMemAt(0x587000, 71824), v67);
	else
		v69 = 0;
	sub_42C360(v118, v69);
	v70 = *(_DWORD*)(v4 + 28);
	v71 = operator_new(0x10u);
	if (v71)
		v72 = sub_42C8B0((int)v71, (char*)getMemAt(0x587000, 71832), v70);
	else
		v72 = 0;
	sub_42C360(v118, v72);
	v73 = operator_new(0x10u);
	if (v73)
		v74 = sub_42C7F0((int)v73, (char*)getMemAt(0x587000, 71840), 1);
	else
		v74 = 0;
	sub_42C360(v118, v74);
	v127 = *(_BYTE*)(v4 + 26);
	v75 = operator_new(0x10u);
	if (v75)
		v76 = sub_42C7F0((int)v75, (char*)getMemAt(0x587000, 71848), v127);
	else
		v76 = 0;
	sub_42C360(v118, v76);
	switch (a2) {
	case 0:
		*getMemU32Ptr(0x5D4594, 741668) = 0;
		v77 = operator_new(0x10u);
		if (v77)
			v78 = sub_42C8B0((int)v77, (char*)getMemAt(0x587000, 71856), 0);
		else
			v78 = 0;
		sub_42C360(v118, v78);
		v79 = operator_new(0x10u);
		if (v79)
			v80 = sub_42C7F0((int)v79, (char*)getMemAt(0x587000, 71864), 0);
		else
			v80 = 0;
		sub_42C360(v118, v80);
		v81 = operator_new(0x10u);
		if (v81) {
			v82 = sub_42C820((int)v81, (char*)getMemAt(0x587000, 71872), -1);
			sub_42C360(v118, v82);
			break;
		}
		sub_42C360(v118, 0);
		break;
	case 2:
		v83 = *getMemU32Ptr(0x5D4594, 741668) + 1;
		*getMemU32Ptr(0x5D4594, 741668) = v83;
		v84 = v83;
		v85 = operator_new(0x10u);
		if (v85)
			v86 = sub_42C8B0((int)v85, (char*)getMemAt(0x587000, 71880), v84);
		else
			v86 = 0;
		sub_42C360(v118, v86);
		v87 = operator_new(0x10u);
		if (v87)
			v88 = sub_42C7F0((int)v87, (char*)getMemAt(0x587000, 71888), 1);
		else
			v88 = 0;
		sub_42C360(v118, v88);
		v89 = *(_WORD*)(v4 + 6);
		v90 = operator_new(0x10u);
		if (v90)
			v91 = sub_42C820((int)v90, (char*)getMemAt(0x587000, 71896), v89);
		else
			v91 = 0;
		sub_42C360(v118, v91);
		v92 = 0;
		for (*getMemU32Ptr(0x5D4594, 741660) = 0; v92 < *(__int16*)(v4 + 6); *getMemU32Ptr(0x5D4594, 741660) = v92) {
			*getMemU8Ptr(0x587000, 71491) = v92 + 48;
			v93 = *(const char**)(*(_DWORD*)(v4 + 608) + 4 * v92);
			v94 = operator_new(0x10u);
			if (v94)
				v95 = sub_42C8E0((int)v94, (char*)getMemAt(0x587000, 71488), v93);
			else
				v95 = 0;
			sub_42C360(v118, v95);
			*getMemU8Ptr(0x587000, 71499) = getMemByte(0x5D4594, 741660) + 48;
			v96 = *(_DWORD*)(*(_DWORD*)(v4 + 612) + 4 * *getMemU32Ptr(0x5D4594, 741660));
			v97 = operator_new(0x10u);
			if (v97)
				v98 = sub_42C8B0((int)v97, (char*)getMemAt(0x587000, 71496), v96);
			else
				v98 = 0;
			sub_42C360(v118, v98);
			*getMemU8Ptr(0x587000, 71515) = getMemByte(0x5D4594, 741660) + 48;
			v99 = *(_DWORD*)(*(_DWORD*)(v4 + 616) + 4 * *getMemU32Ptr(0x5D4594, 741660));
			v100 = operator_new(0x10u);
			if (v100)
				v101 = sub_42C8B0((int)v100, (char*)getMemAt(0x587000, 71512), v99);
			else
				v101 = 0;
			sub_42C360(v118, v101);
			*getMemU8Ptr(0x587000, 71507) = getMemByte(0x5D4594, 741660) + 48;
			v128 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 741660) + *(_DWORD*)(v4 + 620));
			v102 = operator_new(0x10u);
			if (v102)
				v103 = sub_42C7F0((int)v102, (char*)getMemAt(0x587000, 71504), v128);
			else
				v103 = 0;
			sub_42C360(v118, v103);
			*getMemU8Ptr(0x587000, 71523) = getMemByte(0x5D4594, 741660) + 48;
			v129 = *(_BYTE*)(*(_DWORD*)(v4 + 624) + *getMemU32Ptr(0x5D4594, 741660));
			v104 = operator_new(0x10u);
			if (v104)
				v105 = sub_42C7F0((int)v104, (char*)getMemAt(0x587000, 71520), v129);
			else
				v105 = 0;
			sub_42C360(v118, v105);
			*getMemU8Ptr(0x587000, 71531) = getMemByte(0x5D4594, 741660) + 48;
			v106 = *(_DWORD*)(*(_DWORD*)(v4 + 628) + 4 * *getMemU32Ptr(0x5D4594, 741660));
			v107 = operator_new(0x10u);
			if (v107)
				v108 = sub_42C8B0((int)v107, (char*)getMemAt(0x587000, 71528), v106);
			else
				v108 = 0;
			sub_42C360(v118, v108);
			*getMemU8Ptr(0x587000, 71539) = getMemByte(0x5D4594, 741660) + 48;
			v117 = *(_BYTE*)(*(_DWORD*)(v4 + 632) + *getMemU32Ptr(0x5D4594, 741660));
			v109 = operator_new(0x10u);
			if (v109)
				v110 = sub_42C7F0((int)v109, (char*)getMemAt(0x587000, 71536), v117);
			else
				v110 = 0;
			sub_42C360(v118, v110);
			v92 = *getMemU32Ptr(0x5D4594, 741660) + 1;
		}
		v111 = *(const void**)(v4 + 636);
		v112 = operator_new(0x10u);
		if (v112) {
			v113 = sub_42C910((int)v112, (char*)getMemAt(0x587000, 71904), v111, 2 * a3);
			sub_42C360(v118, v113);
			break;
		}
		sub_42C360(v118, 0);
		break;
	case 1:
		++*getMemU32Ptr(0x5D4594, 741668);
		sub_42BDC0(v118, (char*)getMemAt(0x587000, 71912), getMemByte(0x5D4594, 741668));
		sub_42BCE0(v118, (char*)getMemAt(0x587000, 71920), 0);
		sub_42BD50(v118, (char*)getMemAt(0x587000, 71928), *(_WORD*)(v4 + 6));
		v114 = 0;
		for (*getMemU32Ptr(0x5D4594, 741660) = 0; v114 < *(__int16*)(v4 + 6); *getMemU32Ptr(0x5D4594, 741660) = v114) {
			*getMemU8Ptr(0x587000, 71491) = v114 + 48;
			sub_42BE30(v118, (char*)getMemAt(0x587000, 71488), *(const char**)(*(_DWORD*)(v4 + 608) + 4 * v114));
			*getMemU8Ptr(0x587000, 71499) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BDC0(v118, (char*)getMemAt(0x587000, 71496),
					   *(_DWORD*)(*(_DWORD*)(v4 + 612) + 4 * *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71515) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BDC0(v118, (char*)getMemAt(0x587000, 71512),
					   *(_DWORD*)(*(_DWORD*)(v4 + 616) + 4 * *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71507) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BCE0(v118, (char*)getMemAt(0x587000, 71504),
					   *(_BYTE*)(*getMemU32Ptr(0x5D4594, 741660) + *(_DWORD*)(v4 + 620)));
			*getMemU8Ptr(0x587000, 71523) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BCE0(v118, (char*)getMemAt(0x587000, 71520),
					   *(_BYTE*)(*(_DWORD*)(v4 + 624) + *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71531) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BDC0(v118, (char*)getMemAt(0x587000, 71528),
					   *(_DWORD*)(*(_DWORD*)(v4 + 628) + 4 * *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71539) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BCE0(v118, (char*)getMemAt(0x587000, 71536),
					   *(_BYTE*)(*(_DWORD*)(v4 + 632) + *getMemU32Ptr(0x5D4594, 741660)));
			v114 = *getMemU32Ptr(0x5D4594, 741660) + 1;
		}
		sub_42BEA0(v118, (char*)getMemAt(0x587000, 71936), *(const void**)(v4 + 636), 2 * a3);
		break;
	}
	v115 = sub_42C480(v118, a4);
	sub_42C330(v118);
	return v115;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042B810) --------------------------------------------------------
uint16_t* __cdecl sub_42B810(__int16* a1, unsigned int* a2) {
	__int16* v2;     // esi
	int v3;          // edi
	void* v4;        // eax
	int v5;          // eax
	int v6;          // edi
	void* v7;        // eax
	int v8;          // eax
	int v9;          // edi
	void* v10;       // eax
	int v11;         // eax
	void* v12;       // eax
	int v13;         // eax
	void* v14;       // eax
	int v15;         // eax
	int v16;         // edi
	void* v17;       // eax
	int v18;         // eax
	void* v19;       // eax
	int v20;         // eax
	__int16 v21;     // di
	void* v22;       // eax
	int v23;         // eax
	char v24;        // di
	void* v25;       // eax
	int v26;         // eax
	int v27;         // eax
	const char* v28; // edi
	void* v29;       // eax
	int v30;         // eax
	int v31;         // edi
	void* v32;       // eax
	int v33;         // eax
	void* v34;       // eax
	int v35;         // eax
	int v36;         // edi
	void* v37;       // eax
	int v38;         // eax
	int v39;         // edi
	void* v40;       // eax
	int v41;         // eax
	int v42;         // edi
	void* v43;       // eax
	int v44;         // eax
	int v45;         // edi
	void* v46;       // eax
	int v47;         // eax
	int v48;         // edi
	void* v49;       // eax
	int v50;         // eax
	int v51;         // edi
	void* v52;       // eax
	int v53;         // eax
	int v54;         // edi
	void* v55;       // eax
	int v56;         // eax
	uint16_t* v57;    // esi
	char v59[12];    // [esp+8h] [ebp-Ch]
	char v60;        // [esp+18h] [ebp+4h]
	char v61;        // [esp+18h] [ebp+4h]

	v2 = a1;
	v3 = *((_DWORD*)a1 + 1);
	*(_WORD*)v59 = 0;
	*(_WORD*)&v59[2] = 0;
	*(_DWORD*)&v59[4] = 0;
	v4 = operator_new(0x10u);
	if (v4)
		v5 = sub_42C8B0((int)v4, (char*)getMemAt(0x587000, 71944), v3);
	else
		v5 = 0;
	sub_42C360(v59, v5);
	v6 = *((_DWORD*)a1 + 2);
	v7 = operator_new(0x10u);
	if (v7)
		v8 = sub_42C8B0((int)v7, (char*)getMemAt(0x587000, 71952), v6);
	else
		v8 = 0;
	sub_42C360(v59, v8);
	v9 = *((_DWORD*)a1 + 3);
	v10 = operator_new(0x10u);
	if (v10)
		v11 = sub_42C8B0((int)v10, (char*)getMemAt(0x587000, 71960), v9);
	else
		v11 = 0;
	sub_42C360(v59, v11);
	v12 = operator_new(0x10u);
	if (v12)
		v13 = sub_42C8E0((int)v12, (char*)getMemAt(0x587000, 71968), (const char*)a1 + 24);
	else
		v13 = 0;
	sub_42C360(v59, v13);
	v14 = operator_new(0x10u);
	if (v14)
		v15 = sub_42C8E0((int)v14, (char*)getMemAt(0x587000, 71976), (const char*)a1 + 280);
	else
		v15 = 0;
	sub_42C360(v59, v15);
	v16 = *((_DWORD*)a1 + 5);
	v17 = operator_new(0x10u);
	if (v17)
		v18 = sub_42C8B0((int)v17, (char*)getMemAt(0x587000, 71984), v16);
	else
		v18 = 0;
	sub_42C360(v59, v18);
	v60 = *((_BYTE*)a1 + 16);
	v19 = operator_new(0x10u);
	if (v19)
		v20 = sub_42C7F0((int)v19, (char*)getMemAt(0x587000, 71992), v60);
	else
		v20 = 0;
	sub_42C360(v59, v20);
	v21 = *v2;
	v22 = operator_new(0x10u);
	if (v22)
		v23 = sub_42C820((int)v22, (char*)getMemAt(0x587000, 72000), v21);
	else
		v23 = 0;
	sub_42C360(v59, v23);
	v24 = getMemByte(0x5D4594, 741672);
	v25 = operator_new(0x10u);
	if (v25)
		v26 = sub_42C8B0((int)v25, (char*)getMemAt(0x587000, 72008), v24);
	else
		v26 = 0;
	sub_42C360(v59, v26);
	v27 = 0;
	for (*getMemU32Ptr(0x5D4594, 741664) = 0; v27 < *v2; *getMemU32Ptr(0x5D4594, 741664) = v27) {
		*getMemU8Ptr(0x587000, 71547) = v27 + 48;
		v28 = *(const char**)(*((_DWORD*)v2 + 134) + 4 * v27);
		v29 = operator_new(0x10u);
		if (v29)
			v30 = sub_42C8E0((int)v29, (char*)getMemAt(0x587000, 71544), v28);
		else
			v30 = 0;
		sub_42C360(v59, v30);
		*getMemU8Ptr(0x587000, 71555) = getMemByte(0x5D4594, 741664) + 48;
		v31 = *(_DWORD*)(*((_DWORD*)v2 + 135) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v32 = operator_new(0x10u);
		if (v32)
			v33 = sub_42C8B0((int)v32, (char*)getMemAt(0x587000, 71552), v31);
		else
			v33 = 0;
		sub_42C360(v59, v33);
		*getMemU8Ptr(0x587000, 71563) = getMemByte(0x5D4594, 741664) + 48;
		v61 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 741664) + *((_DWORD*)v2 + 144));
		v34 = operator_new(0x10u);
		if (v34)
			v35 = sub_42C7F0((int)v34, (char*)getMemAt(0x587000, 71560), v61);
		else
			v35 = 0;
		sub_42C360(v59, v35);
		*getMemU8Ptr(0x587000, 71571) = getMemByte(0x5D4594, 741664) + 48;
		v36 = *(_DWORD*)(*((_DWORD*)v2 + 136) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v37 = operator_new(0x10u);
		if (v37)
			v38 = sub_42C8B0((int)v37, (char*)getMemAt(0x587000, 71568), v36);
		else
			v38 = 0;
		sub_42C360(v59, v38);
		*getMemU8Ptr(0x587000, 71579) = getMemByte(0x5D4594, 741664) + 48;
		v39 = *(_DWORD*)(*((_DWORD*)v2 + 137) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v40 = operator_new(0x10u);
		if (v40)
			v41 = sub_42C8B0((int)v40, (char*)getMemAt(0x587000, 71576), v39);
		else
			v41 = 0;
		sub_42C360(v59, v41);
		*getMemU8Ptr(0x587000, 71587) = getMemByte(0x5D4594, 741664) + 48;
		v42 = *(_DWORD*)(*((_DWORD*)v2 + 138) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v43 = operator_new(0x10u);
		if (v43)
			v44 = sub_42C8B0((int)v43, (char*)getMemAt(0x587000, 71584), v42);
		else
			v44 = 0;
		sub_42C360(v59, v44);
		*getMemU8Ptr(0x587000, 71595) = getMemByte(0x5D4594, 741664) + 48;
		v45 = *(_DWORD*)(*((_DWORD*)v2 + 139) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v46 = operator_new(0x10u);
		if (v46)
			v47 = sub_42C8B0((int)v46, (char*)getMemAt(0x587000, 71592), v45);
		else
			v47 = 0;
		sub_42C360(v59, v47);
		*getMemU8Ptr(0x587000, 71603) = getMemByte(0x5D4594, 741664) + 48;
		v48 = *(_DWORD*)(*((_DWORD*)v2 + 140) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v49 = operator_new(0x10u);
		if (v49)
			v50 = sub_42C8B0((int)v49, (char*)getMemAt(0x587000, 71600), v48);
		else
			v50 = 0;
		sub_42C360(v59, v50);
		*getMemU8Ptr(0x587000, 71611) = getMemByte(0x5D4594, 741664) + 48;
		v51 = *(_DWORD*)(*((_DWORD*)v2 + 141) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v52 = operator_new(0x10u);
		if (v52)
			v53 = sub_42C8B0((int)v52, (char*)getMemAt(0x587000, 71608), v51);
		else
			v53 = 0;
		sub_42C360(v59, v53);
		*getMemU8Ptr(0x587000, 71619) = getMemByte(0x5D4594, 741664) + 48;
		v54 = *(_DWORD*)(*((_DWORD*)v2 + 142) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v55 = operator_new(0x10u);
		if (v55)
			v56 = sub_42C8B0((int)v55, (char*)getMemAt(0x587000, 71616), v54);
		else
			v56 = 0;
		sub_42C360(v59, v56);
		*getMemU8Ptr(0x587000, 71627) = getMemByte(0x5D4594, 741664) + 48;
		sub_42BDC0(v59, (char*)getMemAt(0x587000, 71624),
				   *(_DWORD*)(*((_DWORD*)v2 + 143) + 4 * *getMemU32Ptr(0x5D4594, 741664)));
		v27 = *getMemU32Ptr(0x5D4594, 741664) + 1;
	}
	v57 = sub_42C480(v59, a2);
	++*getMemU32Ptr(0x5D4594, 741672);
	sub_42C330(v59);
	return v57;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BCE0) --------------------------------------------------------
int __thiscall sub_42BCE0(_DWORD* this, char* a2, char a3) {
	_DWORD* v3; // esi
	void* v4;   // eax
	int v5;     // eax

	v3 = this;
	v4 = operator_new(0x10u);
	if (v4)
		v5 = sub_42C7F0((int)v4, a2, a3);
	else
		v5 = 0;
	return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BD50) --------------------------------------------------------
int __thiscall sub_42BD50(_DWORD* this, char* a2, char a3) {
	_DWORD* v3; // esi
	void* v4;   // eax
	int v5;     // eax

	v3 = this;
	v4 = operator_new(0x10u);
	if (v4)
		v5 = sub_42C820((int)v4, a2, a3);
	else
		v5 = 0;
	return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BDC0) --------------------------------------------------------
int __thiscall sub_42BDC0(_DWORD* this, char* a2, char a3) {
	_DWORD* v3; // esi
	void* v4;   // eax
	int v5;     // eax

	v3 = this;
	v4 = operator_new(0x10u);
	if (v4)
		v5 = sub_42C8B0((int)v4, a2, a3);
	else
		v5 = 0;
	return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BE30) --------------------------------------------------------
int __thiscall sub_42BE30(_DWORD* this, char* a2, const char* a3) {
	_DWORD* v3; // esi
	void* v4;   // eax
	int v5;     // eax

	v3 = this;
	v4 = operator_new(0x10u);
	if (v4)
		v5 = sub_42C8E0((int)v4, a2, a3);
	else
		v5 = 0;
	return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BEA0) --------------------------------------------------------
int __thiscall sub_42BEA0(_DWORD* this, char* a2, const void* a3, unsigned __int16 a4) {
	_DWORD* v4; // esi
	void* v5;   // eax
	int v6;     // eax

	v4 = this;
	v5 = operator_new(0x10u);
	if (v5)
		v6 = sub_42C910((int)v5, a2, a3, a4);
	else
		v6 = 0;
	return sub_42C360(v4, v6);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BFB0) --------------------------------------------------------
int sub_42BFB0() {
	int result; // eax

	result = 0;
	memset(*(void**)&dword_5d4594_741676, 0, 2 * dword_5d4594_741680);
	*getMemU16Ptr(0x5D4594, 741684) = 0;
	return result;
}

//----- (0042BFE0) --------------------------------------------------------
int sub_42BFE0() {
	int result;           // eax
	int i;                // esi
	unsigned __int16 v2;  // ax
	bool v3;              // zf
	_WORD* v4;            // eax
	int j;                // ecx
	unsigned __int16 v6;  // ax
	_WORD* v7;            // eax
	int k;                // esi
	_WORD* v9;            // eax
	int l;                // eax
	unsigned __int16 v11; // cx
	_WORD* v12;           // ecx
	int m;                // esi
	_WORD* v14;           // eax
	int v15;              // [esp+4h] [ebp-4h]

	result = nox_common_gameFlags_check_40A5C0(2097153);
	if (result) {
		sub_42BFB0();
		v15 = 1;
		for (i = nox_server_getFirstObject_4DA790(); i; i = nox_server_getNextObject_4DA7A0(i)) {
			v2 = *(_WORD*)(i + 4);
			v3 = *(_WORD*)(dword_5d4594_741676 + 2 * v2) == 0;
			v4 = (_WORD*)(dword_5d4594_741676 + 2 * v2);
			if (v3) {
				*v4 = v15;
				++*getMemU16Ptr(0x5D4594, 741684);
				++v15;
			}
			for (j = *(_DWORD*)(i + 504); j; j = *(_DWORD*)(j + 496)) {
				v6 = *(_WORD*)(j + 4);
				v3 = *(_WORD*)(dword_5d4594_741676 + 2 * v6) == 0;
				v7 = (_WORD*)(dword_5d4594_741676 + 2 * v6);
				if (v3) {
					*v7 = v15;
					++*getMemU16Ptr(0x5D4594, 741684);
					++v15;
				}
			}
			if (*(_DWORD*)(i + 8) & 0x20000)
				sub_42C210(i, &v15, getMemAt(0x5D4594, 741684));
		}
		for (k = nox_server_getFirstObjectUninited_4DA870(); k; k = nox_server_getNextObjectUninited_4DA880(k)) {
			v9 = (_WORD*)(dword_5d4594_741676 + 2 * *(unsigned __int16*)(k + 4));
			if (!*v9) {
				*v9 = v15;
				++*getMemU16Ptr(0x5D4594, 741684);
				++v15;
			}
			if (*(_DWORD*)(k + 8) & 0x20000)
				sub_42C210(k, &v15, getMemAt(0x5D4594, 741684));
		}
		for (l = sub_4DA840(); l; l = sub_4DA850(l)) {
			v11 = *(_WORD*)(l + 4);
			v3 = *(_WORD*)(dword_5d4594_741676 + 2 * v11) == 0;
			v12 = (_WORD*)(dword_5d4594_741676 + 2 * v11);
			if (v3) {
				*v12 = v15;
				++*getMemU16Ptr(0x5D4594, 741684);
				++v15;
			}
		}
		result = nox_common_gameFlags_check_40A5C0(0x200000);
		if (!result) {
			result = nox_common_gameFlags_check_40A5C0(1);
			if (result == 1) {
				result = nox_common_gameFlags_check_40A5C0(2);
				if (result == 1) {
					result = nox_common_gameFlags_check_40A5C0(0x400000);
					if (!result) {
						result = sub_45A060();
						for (m = result; result; m = result) {
							if (!sub_4E3AD0(*(_DWORD*)(m + 108)) && sub_4E3B80(*(_DWORD*)(m + 108))) {
								v14 = (_WORD*)(dword_5d4594_741676 + 2 * *(_DWORD*)(m + 108));
								if (!*v14) {
									*v14 = v15;
									++*getMemU16Ptr(0x5D4594, 741684);
									++v15;
								}
							}
							result = sub_45A070(m);
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (0042C210) --------------------------------------------------------
int __cdecl sub_42C210(int a1, _WORD* a2, _WORD* a3) {
	int result;          // eax
	int v4;              // edi
	int v5;              // ebx
	_WORD* v6;           // eax
	int i;               // ecx
	unsigned __int16 v8; // ax
	bool v9;             // zf
	_WORD* v10;          // eax
	int v11;             // [esp+14h] [ebp+4h]

	result = *(_DWORD*)(a1 + 748);
	v11 = 3;
	do {
		v4 = result;
		v5 = 4;
		do {
			if (*(_DWORD*)v4) {
				v6 = (_WORD*)(dword_5d4594_741676 + 2 * *(unsigned __int16*)(*(_DWORD*)v4 + 4));
				if (!*v6) {
					*v6 = (*a2)++;
					++*a3;
				}
				for (i = *(_DWORD*)(*(_DWORD*)v4 + 504); i; i = *(_DWORD*)(i + 496)) {
					v8 = *(_WORD*)(i + 4);
					v9 = *(_WORD*)(dword_5d4594_741676 + 2 * v8) == 0;
					v10 = (_WORD*)(dword_5d4594_741676 + 2 * v8);
					if (v9) {
						*v10 = (*a2)++;
						++*a3;
					}
				}
			}
			v4 += 4;
			--v5;
		} while (v5);
		result = v4;
		--v11;
	} while (v11);
	return result;
}

//----- (0042C2B0) --------------------------------------------------------
__int16 __cdecl sub_42C2B0(__int16 a1) {
	_WORD* v1;       // ecx
	unsigned int v2; // eax

	v1 = *(_WORD**)&dword_5d4594_741676;
	if (dword_5d4594_741676 && (v2 = 0, dword_5d4594_741680)) {
		while (*v1 != a1) {
			++v2;
			++v1;
			if (v2 >= *(int*)&dword_5d4594_741680)
				goto LABEL_5;
		}
	} else {
	LABEL_5:
		LOWORD(v2) = 0;
	}
	return v2;
}

//----- (0042C2E0) --------------------------------------------------------
__int16 __cdecl sub_42C2E0(int a1) {
	__int16 result; // ax

	if (dword_5d4594_741676)
		result = *(_WORD*)(dword_5d4594_741676 + 2 * a1);
	else
		result = 0;
	return result;
}

//----- (0042C300) --------------------------------------------------------
__int16 sub_42C300() { return *getMemU16Ptr(0x5D4594, 741684); }

//----- (0042C310) --------------------------------------------------------
LPVOID __cdecl sub_42C310(unsigned __int16 a1, __int16 a2) {
	LPVOID result; // eax

	result = *(LPVOID*)&dword_5d4594_741676;
	if (dword_5d4594_741676)
		*(_WORD*)(dword_5d4594_741676 + 2 * a1) = a2;
	return result;
}

//----- (0042C330) --------------------------------------------------------
void __thiscall sub_42C330(_DWORD* this) {
	_DWORD* v1; // esi
	_DWORD* v2; // edi

	v1 = (_DWORD*)this[1];
	if (v1) {
		do {
			v2 = (_DWORD*)v1[3];
			if (v1) {
				sub_42CC50(v1);
				operator_delete(v1);
			}
			v1 = v2;
		} while (v2);
	}
}
// 42CC50: using guessed type int __thiscall sub_42CC50(_DWORD);

//----- (0042C360) --------------------------------------------------------
int __thiscall sub_42C360(_DWORD* this, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a2 + 12) = this[1];
	this[1] = a2;
	return result;
}

//----- (0042C370) --------------------------------------------------------
uint16_t* __thiscall sub_42C370(uint16_t* this, uint16_t* a2) {
	uint16_t* v2;      // edi
	uint16_t v3;       // ax
	uint16_t v4;       // ax
	uint16_t* v5;      // esi
	uint16_t v6;       // ax
	void* v7;         // eax
	int v8;           // ecx
	int v9;           // ebx
	_DWORD* v10;      // esi
	uint16_t v11;      // ax
	unsigned int v12; // ebp
	void* v13;        // eax
	int v14;          // eax
	int v16;          // [esp+8h] [ebp-8h]
	uint16_t* v17;     // [esp+Ch] [ebp-4h]
	int v18;          // [esp+14h] [ebp+4h]

	v2 = this;
	v3 = *a2;
	v17 = this;
	*this = *a2;
	*this = ntohs(v3);
	v4 = a2[1];
	v2[1] = a2[1];
	v5 = a2 + 2;
	v2[1] = ntohs(v4);
	v6 = *v2;
	*((_DWORD*)v2 + 1) = 0;
	v16 = v6 - 4;
	if (v16 <= 0)
		return v2;
	while (1) {
		v7 = operator_new(0x10u);
		v8 = *(_DWORD*)v5;
		v9 = (int)v7;
		v10 = v5 + 4;
		*(_DWORD*)v7 = v8;
		*((_DWORD*)v7 + 1) = *(v10 - 1);
		v11 = ntohs(*((_WORD*)v7 + 3));
		v12 = v11;
		v13 = operator_new(v11);
		*(_DWORD*)(v9 + 8) = v13;
		memcpy(v13, v10, v12);
		v14 = -(ntohs(*(_WORD*)(v9 + 6)) & 3) & 3;
		v18 = (int)v10 + v14 + v12;
		v16 += -8 - v14 - v12;
		sub_42CCE0((uint16_t*)v9);
		sub_42C360(v17, v9);
		if (v16 <= 0)
			break;
		v5 = (uint16_t*)v18;
	}
	return v17;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042C480) --------------------------------------------------------
uint16_t* __thiscall sub_42C480(_DWORD* this, unsigned int* a2) {
	_DWORD* v2;      // ebx
	int i;           // eax
	unsigned int v4; // ecx
	uint16_t* v5;     // edi
	int v6;          // ebx
	_DWORD* v7;      // ebp
	char* v8;        // ebp
	int v9;          // ebp

	v2 = this;
	*a2 = 4;
	for (i = this[1]; i; i = *(_DWORD*)(i + 12)) {
		v4 = *a2 + 8;
		*a2 = v4;
		*a2 = *(unsigned __int16*)(i + 6) + v4 + (-(((unsigned __int8)*(_WORD*)(i + 6) + (_BYTE)v4) & 3) & 3);
	}
	v5 = (uint16_t*)operator_new(*a2);
	*v5 = htons(*(_WORD*)a2);
	v5[1] = htons(*((_WORD*)v2 + 1));
	v6 = v2[1];
	v7 = v5 + 2;
	if (!v6)
		return v5;
	do {
		sub_42CC70(v6);
		*v7 = *(_DWORD*)v6;
		v7[1] = *(_DWORD*)(v6 + 4);
		v8 = (char*)(v7 + 2);
		memcpy(v8, *(const void**)(v6 + 8), ntohs(*(_WORD*)(v6 + 6)));
		v9 = (int)&v8[ntohs(*(_WORD*)(v6 + 6))];
		v7 = (_DWORD*)((-(ntohs(*(_WORD*)(v6 + 6)) & 3) & 3) + v9);
		sub_42CCE0((uint16_t*)v6);
		v6 = *(_DWORD*)(v6 + 12);
	} while (v6);
	return v5;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042C580) --------------------------------------------------------
int __thiscall sub_42C580(_DWORD* this, char* a2) {
	int v2; // esi

	v2 = this[1];
	if (!v2)
		return 0;
	while (strncmp(a2, (const char*)v2, 4u)) {
		v2 = *(_DWORD*)(v2 + 12);
		if (!v2)
			return 0;
	}
	return v2;
}

//----- (0042C5C0) --------------------------------------------------------
bool __thiscall sub_42C5C0(_DWORD* this, char* a2, _BYTE* a3) {
	int v3; // eax

	v3 = sub_42C580(this, a2);
	if (v3)
		*a3 = **(_BYTE**)(v3 + 8);
	return v3 != 0;
}

//----- (0042C5E0) --------------------------------------------------------
bool __thiscall sub_42C5E0(_DWORD* this, char* a2, _BYTE* a3) {
	int v3; // eax

	v3 = sub_42C580(this, a2);
	if (v3)
		*a3 = **(_BYTE**)(v3 + 8);
	return v3 != 0;
}

//----- (0042C600) --------------------------------------------------------
bool __thiscall sub_42C600(_DWORD* this, char* a2, _WORD* a3) {
	int v3; // eax

	v3 = sub_42C580(this, a2);
	if (v3)
		*a3 = **(_WORD**)(v3 + 8);
	return v3 != 0;
}

//----- (0042C630) --------------------------------------------------------
bool __thiscall sub_42C630(_DWORD* this, char* a2, _WORD* a3) {
	int v3; // eax

	v3 = sub_42C580(this, a2);
	if (v3)
		*a3 = **(_WORD**)(v3 + 8);
	return v3 != 0;
}

//----- (0042C660) --------------------------------------------------------
bool __thiscall sub_42C660(_DWORD* this, char* a2, _DWORD* a3) {
	int v3; // eax

	v3 = sub_42C580(this, a2);
	if (v3)
		*a3 = **(_DWORD**)(v3 + 8);
	return v3 != 0;
}

//----- (0042C680) --------------------------------------------------------
bool __thiscall sub_42C680(_DWORD* this, char* a2, _DWORD* a3) {
	int v3; // eax

	v3 = sub_42C580(this, a2);
	if (v3)
		*a3 = **(_DWORD**)(v3 + 8);
	return v3 != 0;
}

//----- (0042C6A0) --------------------------------------------------------
bool __thiscall sub_42C6A0(_DWORD* this, char* a2, char* a3) {
	int v3;  // eax
	bool v4; // zf

	v3 = sub_42C580(this, a2);
	v4 = v3 == 0;
	if (v3) {
		strcpy(a3, *(const char**)(v3 + 8));
		v4 = v3 == 0;
	}
	return !v4;
}

//----- (0042C6E0) --------------------------------------------------------
bool __thiscall sub_42C6E0(_DWORD* this, char* a2, _DWORD* a3) {
	int v3; // eax

	v3 = sub_42C580(this, a2);
	if (v3)
		*a3 = **(_DWORD**)(v3 + 8);
	return v3 != 0;
}

//----- (0042C700) --------------------------------------------------------
bool __thiscall sub_42C700(_DWORD* this, char* a2, _DWORD* a3) {
	int v3; // eax

	v3 = sub_42C580(this, a2);
	if (v3)
		*a3 = **(_DWORD**)(v3 + 8);
	return v3 != 0;
}

//----- (0042C720) --------------------------------------------------------
bool __thiscall sub_42C720(_DWORD* this, char* a2, void* a3, unsigned int* a4) {
	int v4;          // eax
	bool v5;         // zf
	unsigned int v6; // ecx

	v4 = sub_42C580(this, a2);
	v5 = v4 == 0;
	if (v4) {
		v6 = *(unsigned __int16*)(v4 + 6);
		if ((unsigned __int16)v6 >= (int)*a4)
			v6 = *a4;
		memcpy(a3, *(const void**)(v4 + 8), v6);
		*a4 = *(unsigned __int16*)(v4 + 6);
		v5 = v4 == 0;
	}
	return !v5;
}

//----- (0042C770) --------------------------------------------------------
int __thiscall sub_42C770(LPVOID* this) {
	LPVOID* v1; // ebx
	int result; // eax

	v1 = this;
	operator_delete(this[2]);
	result = 0;
	strcpy((char*)v1, (const char*)getMemAt(0x5D4594, 741688));
	*((_WORD*)v1 + 2) = 0;
	*((_WORD*)v1 + 3) = 0;
	v1[2] = 0;
	v1[3] = 0;
	return result;
}

//----- (0042C7C0) --------------------------------------------------------
int __thiscall sub_42C7C0(int this, char* a2, char a3) {
	int v3; // esi

	v3 = this;
	*(_DWORD*)(this + 8) = 0;
	sub_42C940((LPVOID*)this, a2, a3);
	return v3;
}

//----- (0042C7F0) --------------------------------------------------------
int __thiscall sub_42C7F0(int this, char* a2, char a3) {
	int v3; // esi

	v3 = this;
	*(_DWORD*)(this + 8) = 0;
	sub_42C9A0((LPVOID*)this, a2, a3);
	return v3;
}

//----- (0042C820) --------------------------------------------------------
int __thiscall sub_42C820(int this, char* a2, char a3) {
	int v3; // esi

	v3 = this;
	*(_DWORD*)(this + 8) = 0;
	sub_42CA00((LPVOID*)this, a2, a3);
	return v3;
}

//----- (0042C850) --------------------------------------------------------
int __thiscall sub_42C850(int this, char* a2, char a3) {
	int v3; // esi

	v3 = this;
	*(_DWORD*)(this + 8) = 0;
	sub_42CA60((LPVOID*)this, a2, a3);
	return v3;
}

//----- (0042C880) --------------------------------------------------------
int __thiscall sub_42C880(int this, char* a2, char a3) {
	int v3; // esi

	v3 = this;
	*(_DWORD*)(this + 8) = 0;
	sub_42CAC0((LPVOID*)this, a2, a3);
	return v3;
}

//----- (0042C8B0) --------------------------------------------------------
int __thiscall sub_42C8B0(int this, char* a2, char a3) {
	int v3; // esi

	v3 = this;
	*(_DWORD*)(this + 8) = 0;
	sub_42CB20((LPVOID*)this, a2, a3);
	return v3;
}

//----- (0042C8E0) --------------------------------------------------------
int __thiscall sub_42C8E0(int this, char* a2, const char* a3) {
	int v3; // esi

	v3 = this;
	*(_DWORD*)(this + 8) = 0;
	sub_42CB80((LPVOID*)this, a2, a3);
	return v3;
}

//----- (0042C910) --------------------------------------------------------
int __thiscall sub_42C910(int this, char* a2, const void* a3, unsigned __int16 a4) {
	int v4; // esi

	v4 = this;
	*(_DWORD*)(this + 8) = 0;
	sub_42CBF0((LPVOID*)this, a2, a3, a4);
	return v4;
}

//----- (0042C940) --------------------------------------------------------
char* __thiscall sub_42C940(LPVOID* this, char* a2, char a3) {
	LPVOID* v3;      // ebx
	char* result;    // eax
	unsigned int v5; // edx

	v3 = this;
	sub_42C770(this);
	strncpy((char*)v3, a2, 4u);
	*((_WORD*)v3 + 2) = 1;
	*((_WORD*)v3 + 3) = 1;
	result = (char*)operator_new(1u);
	v5 = *((unsigned __int16*)v3 + 3);
	v3[2] = result;
	memcpy(result, &a3, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042C9A0) --------------------------------------------------------
char* __thiscall sub_42C9A0(LPVOID* this, char* a2, char a3) {
	LPVOID* v3;      // ebx
	char* result;    // eax
	unsigned int v5; // edx

	v3 = this;
	sub_42C770(this);
	strncpy((char*)v3, a2, 4u);
	*((_WORD*)v3 + 2) = 2;
	*((_WORD*)v3 + 3) = 1;
	result = (char*)operator_new(1u);
	v5 = *((unsigned __int16*)v3 + 3);
	v3[2] = result;
	memcpy(result, &a3, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CA00) --------------------------------------------------------
char* __thiscall sub_42CA00(LPVOID* this, char* a2, char a3) {
	LPVOID* v3;      // ebx
	char* result;    // eax
	unsigned int v5; // edx

	v3 = this;
	sub_42C770(this);
	strncpy((char*)v3, a2, 4u);
	*((_WORD*)v3 + 2) = 3;
	*((_WORD*)v3 + 3) = 2;
	result = (char*)operator_new(2u);
	v5 = *((unsigned __int16*)v3 + 3);
	v3[2] = result;
	memcpy(result, &a3, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CA60) --------------------------------------------------------
char* __thiscall sub_42CA60(LPVOID* this, char* a2, char a3) {
	LPVOID* v3;      // ebx
	char* result;    // eax
	unsigned int v5; // edx

	v3 = this;
	sub_42C770(this);
	strncpy((char*)v3, a2, 4u);
	*((_WORD*)v3 + 2) = 4;
	*((_WORD*)v3 + 3) = 2;
	result = (char*)operator_new(2u);
	v5 = *((unsigned __int16*)v3 + 3);
	v3[2] = result;
	memcpy(result, &a3, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CAC0) --------------------------------------------------------
char* __thiscall sub_42CAC0(LPVOID* this, char* a2, char a3) {
	LPVOID* v3;      // ebx
	char* result;    // eax
	unsigned int v5; // edx

	v3 = this;
	sub_42C770(this);
	strncpy((char*)v3, a2, 4u);
	*((_WORD*)v3 + 2) = 5;
	*((_WORD*)v3 + 3) = 4;
	result = (char*)operator_new(4u);
	v5 = *((unsigned __int16*)v3 + 3);
	v3[2] = result;
	memcpy(result, &a3, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CB20) --------------------------------------------------------
char* __thiscall sub_42CB20(LPVOID* this, char* a2, char a3) {
	LPVOID* v3;      // ebx
	char* result;    // eax
	unsigned int v5; // edx

	v3 = this;
	sub_42C770(this);
	strncpy((char*)v3, a2, 4u);
	*((_WORD*)v3 + 2) = 6;
	*((_WORD*)v3 + 3) = 4;
	result = (char*)operator_new(4u);
	v5 = *((unsigned __int16*)v3 + 3);
	v3[2] = result;
	memcpy(result, &a3, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CB80) --------------------------------------------------------
char* __thiscall sub_42CB80(LPVOID* this, char* a2, const char* a3) {
	LPVOID* v3;          // ebx
	unsigned int v4;     // kr08_4
	char* result;        // eax
	unsigned __int16 v6; // cx

	v3 = this;
	sub_42C770(this);
	strncpy((char*)v3, a2, 4u);
	*((_WORD*)v3 + 2) = 7;
	v4 = strlen(a3) + 1;
	*((_WORD*)v3 + 3) = v4;
	result = (char*)operator_new((unsigned __int16)v4);
	v6 = *((_WORD*)v3 + 3);
	v3[2] = result;
	memcpy(result, a3, v6);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CBF0) --------------------------------------------------------
void* __thiscall sub_42CBF0(LPVOID* this, char* a2, const void* a3, unsigned __int16 a4) {
	LPVOID* v4;      // ebx
	void* result;    // eax
	unsigned int v6; // edx

	v4 = this;
	sub_42C770(this);
	strncpy((char*)v4, a2, 4u);
	*((_WORD*)v4 + 2) = 20;
	*((_WORD*)v4 + 3) = a4;
	result = operator_new(a4);
	v6 = *((unsigned __int16*)v4 + 3);
	v4[2] = result;
	memcpy(result, a3, v6);
	v4[3] = 0;
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CC60) --------------------------------------------------------
int __thiscall sub_42CC60(unsigned __int16* this) { return this[2]; }

//----- (0042CC70) --------------------------------------------------------
uint16_t __thiscall sub_42CC70(int this) {
	int v1;         // esi
	uint16_t v2;     // ax
	uint16_t v3;     // cx
	uint16_t result; // ax

	v1 = this;
	switch (*(unsigned __int16*)(this + 4)) {
	case 3u:
	case 4u:
		**(_WORD**)(this + 8) = htons(**(_WORD**)(this + 8));
		break;
	case 5u:
	case 6u:
		**(_DWORD**)(this + 8) = htonl(**(_DWORD**)(this + 8));
		break;
	default:
		break;
	}
	v2 = htons(*(_WORD*)(v1 + 4));
	v3 = *(_WORD*)(v1 + 6);
	*(_WORD*)(v1 + 4) = v2;
	result = htons(v3);
	*(_WORD*)(v1 + 6) = result;
	return result;
}

//----- (0042CCE0) --------------------------------------------------------
__int16 __thiscall sub_42CCE0(uint16_t* this) {
	uint16_t* v1; // esi
	uint16_t v2;  // ax
	uint16_t v3;  // cx
	u_long v4;   // eax

	v1 = this;
	v2 = ntohs(this[2]);
	v3 = v1[3];
	v1[2] = v2;
	v1[3] = ntohs(v3);
	LOWORD(v4) = v1[2] - 3;
	switch (v1[2]) {
	case 3u:
	case 4u:
		LOWORD(v4) = ntohs(**((_WORD**)v1 + 2));
		**((_WORD**)v1 + 2) = v4;
		break;
	case 5u:
	case 6u:
		v4 = ntohl(**((_DWORD**)v1 + 2));
		**((_DWORD**)v1 + 2) = v4;
		break;
	default:
		return v4;
	}
	return v4;
}

//----- (0042CD50) --------------------------------------------------------
char* __cdecl sub_42CD50(_BYTE* a1) {
	*a1 = getMemByte(0x5D4594, 747864);
	return (char*)getMemAt(0x5D4594, 741692);
}

//----- (0042CD70) --------------------------------------------------------
LPVOID sub_42CD70() { return *(LPVOID*)&dword_5d4594_754056; }

//----- (0042CD80) --------------------------------------------------------
void* __cdecl sub_42CD80(void* a1) {
	void* result; // eax

	result = a1;
	dword_5d4594_754056 = a1;
	return result;
}

//----- (0042CD90) --------------------------------------------------------
void sub_42CD90() {
	_DWORD* result; // eax
	_DWORD* v1;     // esi

	result = *(_DWORD**)&dword_5d4594_754056;
	if (result) {
		do {
			v1 = (_DWORD*)result[19];
			free(result);
			result = v1;
		} while (v1);
	}
	dword_5d4594_754056 = 0;
	*getMemU8Ptr(0x5D4594, 747848) = 0;
	*getMemU8Ptr(0x5D4594, 750956) = 0;
	dword_5d4594_754036 = 0;
	dword_5d4594_754040 = 0;
	dword_5d4594_754044 = 0;
	dword_5d4594_754048 = 0;
	*getMemU32Ptr(0x5D4594, 747856) = 100;
	*getMemU32Ptr(0x5D4594, 747868) = 4;
}

//----- (0042CDF0) --------------------------------------------------------
_DWORD* __cdecl sub_42CDF0(FILE* a1) {
	int v1;              // eax
	FILE* v2;            // edi
	_DWORD* result;      // eax
	_DWORD* v4;          // ebx
	int v5;              // ebp
	unsigned __int8* v6; // esi
	int v7;              // eax
	int v8;              // ebp
	unsigned __int8* v9; // esi
	int v10;             // eax
	_DWORD* v11;         // [esp+Ch] [ebp+4h]
	_DWORD* v12;         // [esp+Ch] [ebp+4h]

	v1 = sub_430AF0();
	v2 = a1;
	fprintf(a1, "MousePickup = %s\n", *getMemU32Ptr(0x587000, 4 * v1 + 73652));
	result = *(_DWORD**)&dword_5d4594_754056;
	v4 = *(_DWORD**)&dword_5d4594_754056;
	if (dword_5d4594_754056) {
		for (result = *(_DWORD**)(dword_5d4594_754056 + 76); result; result = (_DWORD*)result[19])
			v4 = result;
		for (; v4; v4 = (_DWORD*)v4[18]) {
			v5 = 0;
			if (v4[8] > 0) {
				v11 = v4;
				do {
					if (*getMemU32Ptr(0x587000, 73672)) {
						v6 = getMemAt(0x587000, 73672);
						do {
							if (*v11 == (char*)*((_DWORD*)v6 + 1))
								fprintf(v2, "%s ", *(_DWORD*)v6);
							v7 = *((_DWORD*)v6 + 4);
							v6 += 16;
						} while (v7);
					}
					if (v5 != v4[8] - 1)
						fprintf(v2, "+ ");
					++v5;
					v11++;
				} while (v5 < v4[8]);
			}
			fprintf(v2, "= ");
			v8 = 0;
			if (v4[17] > 0) {
				v12 = v4 + 9;
				do {
					if (*getMemU32Ptr(0x587000, 75880)) {
						v9 = getMemAt(0x587000, 75880);
						do {
							if (*v12 == (char*)*((_DWORD*)v9 + 1))
								fprintf(v2, "%s ", *(_DWORD*)v9);
							v10 = *((_DWORD*)v9 + 3);
							v9 += 12;
						} while (v10);
					}
					if (v8 != v4[17] - 1)
						fprintf(v2, "+ ");
					++v8;
					v12++;
				} while (v8 < v4[17]);
			}
			result = (_DWORD*)fprintf(v2, "\n");
		}
	}
	return result;
}

//----- (0042CF50) --------------------------------------------------------
int __cdecl sub_42CF50(const char* a1) {
	int result;           // eax
	const char* v2;       // ebp
	_DWORD* v3;           // ebx
	char* v4;             // ebp
	int v5;               // edi
	const char** v6;      // esi
	const char* v7;       // eax
	int v8;               // ebp
	unsigned __int8* v9;  // edi
	int v10;              // eax
	char* v11;            // eax
	const char* v12;      // ecx
	int v13;              // ebp
	unsigned __int8* v14; // edi
	int v15;              // eax
	char* v16;            // [esp+10h] [ebp-408h]
	int v17;              // [esp+14h] [ebp-404h]
	char v18[1024];       // [esp+18h] [ebp-400h]

	*getMemU32Ptr(0x5D4594, 747868) = 4;
	*getMemU8Ptr(0x5D4594, 747848) = 0;
	strcpy(v18, a1);
	result = (int)strtok(v18, " \r\t\n");
	v2 = (const char*)result;
	v16 = (char*)result;
	if (result) {
		result = (int)calloc(1u, 0x60u);
		v3 = (_DWORD*)result;
		v17 = result;
		if (result) {
			if (!strcmp(v2, "MousePickup")) {
				strtok(0, " \r\t\n");
				v4 = strtok(0, " \r\t\n");
				v5 = 0;
				v6 = (const char**)getMemAt(0x587000, 73652);
				while (_strcmpi(v4, *v6)) {
					++v6;
					++v5;
					if ((int)v6 >= (int)getMemAt(0x587000, 73668))
						goto LABEL_9;
				}
				if (v5 < 4)
					goto LABEL_10;
			LABEL_9:
				v5 = 0;
			LABEL_10:
				sub_430AA0(v5);
				free(v3);
				result = 1;
			} else {
				while (*v2 != 61) {
					if (*v2 != 43) {
						v7 = *(const char**)getMemAt(0x587000, 73672);
						v8 = 0;
						if (*getMemU32Ptr(0x587000, 73672)) {
							v9 = getMemAt(0x587000, 73672);
							while (strcmp(v7, v16)) {
								v7 = (const char*)*((_DWORD*)v9 + 4);
								v9 += 16;
								++v8;
								if (!v7)
									goto LABEL_21;
							}
							v10 = v3[8];
							if (v10 == 8) {
							LABEL_38:
								free(v3);
								return 0;
							}
							v3[v10] = *getMemU32Ptr(0x587000, 16 * v8 + 73676);
							++v3[8];
						}
					LABEL_21:
						if (!*getMemU32Ptr(0x587000, 16 * v8 + 73672))
							return 0;
					}
					v16 = strtok(0, " \r\t\n");
					if (!v16)
						break;
					v2 = v16;
				}
				v3[17] = 0;
				v11 = strtok(0, " \r\t\n");
				if (v11) {
					while (*v11 != 61) {
						if (*v11 != 43) {
							v12 = *(const char**)getMemAt(0x587000, 75880);
							v13 = 0;
							if (*getMemU32Ptr(0x587000, 75880)) {
								v14 = getMemAt(0x587000, 75880);
								while (strcmp(v12, v11)) {
									v12 = (const char*)*((_DWORD*)v14 + 3);
									v14 += 12;
									++v13;
									if (!v12) {
										v3 = (_DWORD*)v17;
										goto LABEL_33;
									}
								}
								v3 = (_DWORD*)v17;
								v15 = *(_DWORD*)(v17 + 68);
								if (v15 == 8)
									goto LABEL_38;
								*(_DWORD*)(v17 + 4 * v15 + 36) = *getMemU32Ptr(0x587000, 12 * v13 + 75884);
								++*(_DWORD*)(v17 + 68);
							}
						LABEL_33:
							if (!*getMemU32Ptr(0x587000, 12 * v13 + 75880))
								return 0;
						}
						v11 = strtok(0, " \r\t\n");
						if (!v11)
							break;
					}
				}
				v3[18] = 0;
				v3[19] = dword_5d4594_754056;
				if (dword_5d4594_754056)
					*(_DWORD*)(dword_5d4594_754056 + 72) = v3;
				dword_5d4594_754056 = v3;
				result = 1;
			}
		}
	}
	return result;
}

//----- (0042D220) --------------------------------------------------------
unsigned int sub_42D220() {
	int v0;      // ebx
	int2* v1;    // ebp
	int v2;      // esi
	int* v3;     // edi
	int v4;      // ebx
	bool v5;     // zf
	int v6;      // eax
	bool v7;     // zf
	int v8;      // eax
	int v9;      // eax
	int v10;     // edx
	_DWORD* v11; // ebp
	int v12;     // esi
	int v13;     // edx
	int v14;     // eax
	_DWORD* v15; // ecx
	int v16;     // ecx
	int i;       // eax
	int v19;     // [esp+10h] [ebp-Ch]
	int v20;     // [esp+10h] [ebp-Ch]
	int v21;     // [esp+14h] [ebp-8h]
	int2* v22;   // [esp+18h] [ebp-4h]

	v0 = 0;
	v21 = 0;
	v1 = nox_client_getMousePos_4309F0();
	v22 = v1;
	v2 = dword_5d4594_754056;
	if (dword_5d4594_754056) {
		while (1) {
			v19 = 0;
			if (*(_DWORD*)(v2 + 32) > 0)
				break;
		LABEL_33:
			if (v19 == *(_DWORD*)(v2 + 32)) {
				v10 = v21;
				v21 = v2;
				*(_DWORD*)(v2 + 80) = v10;
				*(_BYTE*)(v2 + 88) = 1;
			}
			v2 = *(_DWORD*)(v2 + 76);
			if (!v2) {
				v0 = v21;
				goto LABEL_37;
			}
		}
		v3 = (int*)v2;
		while (1) {
			v4 = *v3;
			if (!(*v3 & 0xFFFF0000))
				break;
			if (v4 & 0x10000 && getMemByte(0x5D4594, 747848) != 2) {
				switch (v4) {
				case 65536:
					v6 = v1[3].field_0;
					if (v6 != 5 && v6 != 8)
						goto LABEL_33;
					v7 = v6 == 8;
					break;
				case 65537:
					v8 = v1[6].field_0;
					if (v8 != 13 && v8 != 16)
						goto LABEL_33;
					v7 = v8 == 16;
					break;
				case 65538:
					v9 = v1[4].field_4;
					if (v9 != 9 && v9 != 12)
						goto LABEL_33;
					v7 = v9 == 12;
					break;
				case 65539:
					if (v1[1].field_0 == 19)
						goto LABEL_32;
					goto LABEL_33;
				case 65540:
					if (v1[1].field_0 == 20)
						goto LABEL_32;
					goto LABEL_33;
				default:
					goto LABEL_32;
				}
				if (v7) {
					v5 = *(_DWORD*)(v2 + 36) == 1;
				LABEL_17:
					if (v5)
						goto LABEL_33;
					goto LABEL_32;
				}
			} else if (v4 & 0x20000 && (getMemByte(0x5D4594, 750956) || !((1 << v4) & *getMemU32Ptr(0x5D4594, 747844)))) {
				goto LABEL_33;
			}
		LABEL_32:
			++v3;
			if (++v19 >= *(int*)(v2 + 32))
				goto LABEL_33;
		}
		if (sub_46B4F0() || sub_46A4A0() || sub_430970(v4) == 1)
			goto LABEL_33;
		v5 = sub_430950(v4) == 1;
		goto LABEL_17;
	}
LABEL_37:
	if (v0) {
		do {
			if (*(_BYTE*)(v0 + 88)) {
				v20 = 0;
				if (*(_DWORD*)(v0 + 32) > 0) {
					v11 = (_DWORD*)v0;
					do {
						v12 = v21;
						do {
							if (*(_BYTE*)(v12 + 88)) {
								if (v12 != v0) {
									v13 = *(_DWORD*)(v12 + 32);
									v14 = 0;
									if (v13 > 0) {
										v15 = (_DWORD*)v12;
										while (*v11 != *v15) {
											++v14;
											++v15;
											if (v14 >= v13)
												goto LABEL_52;
										}
										if (*(int*)(v0 + 32) >= v13)
											*(_BYTE*)(v12 + 88) = 0;
										else
											*(_BYTE*)(v0 + 88) = 0;
									}
								}
							}
						LABEL_52:
							v12 = *(_DWORD*)(v12 + 80);
						} while (v12);
						++v11;
						++v20;
					} while (v20 < *(int*)(v0 + 32));
					v1 = v22;
				}
			}
			v0 = *(_DWORD*)(v0 + 80);
		} while (v0);
		v0 = v21;
	}
	v16 = 0;
	for (i = v0; i; i = *(_DWORD*)(i + 80)) {
		if (*(_BYTE*)(i + 88)) {
			*(_DWORD*)(i + 84) = v16;
			v16 = i;
			*(_DWORD*)(i + 92) = *getMemU32Ptr(0x5D4594, 2598000);
		}
	}
	sub_42D6B0(v1, v16);
	return sub_42D510();
}

//----- (0042D440) --------------------------------------------------------
int __cdecl sub_42D440(int a1) { return *getMemU32Ptr(0x587000, 12 * a1 + 72020); }

//----- (0042D450) --------------------------------------------------------
unsigned __int8 __cdecl sub_42D450(int a1) { return getMemByte(0x587000, 12 * a1 + 72024); }

//----- (0042D460) --------------------------------------------------------
int __cdecl sub_42D460(int a1) {
	int result; // eax

	switch (a1) {
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 42:
	case 43:
	case 44:
	case 45:
		result = 1;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (0042D4B0) --------------------------------------------------------
int __cdecl sub_42D4B0(int a1) {
	int result; // eax

	switch (a1) {
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 31:
	case 32:
	case 33:
	case 34:
	case 35:
	case 38:
	case 39:
	case 40:
	case 41:
	case 42:
	case 43:
	case 44:
	case 45:
	case 46:
	case 47:
	case 48:
	case 49:
	case 51:
	case 52:
	case 53:
	case 54:
	case 55:
	case 56:
		result = 1;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (0042D510) --------------------------------------------------------
unsigned int sub_42D510() {
	int v0;              // ebp
	__int64 v1;          // kr00_8
	unsigned int result; // eax
	int v3;              // ebx
	__int64 v4;          // kr08_8
	int v5;              // eax
	int v6;              // edx
	int* v7;             // ebx
	int v8;              // eax
	int v9;              // edx
	unsigned __int8 v10; // al

	v0 = 0;
	v1 = sub_416BB0();
	*getMemU32Ptr(0x5D4594, 747864) = 0;
	result = nox_common_gameFlags_check_40A5C0(1);
	if (result) {
		v3 = dword_5d4594_754040;
		result = dword_5d4594_754036;
		if (dword_5d4594_754040 != dword_5d4594_754036) {
			v4 = v1 + 50;
			do {
				if (HIDWORD(v4) < *getMemIntPtr(0x5D4594, 24 * v3 + 747888))
					break;
				if (HIDWORD(v4) <= *getMemIntPtr(0x5D4594, 24 * v3 + 747888)) {
					result = v1 + 50;
					if ((unsigned int)v4 < *getMemIntPtr(0x5D4594, 24 * v3 + 747884))
						break;
				}
				if (*getMemU32Ptr(0x5D4594, 24 * v3 + 747900) == 1) {
					v5 = *getMemU32Ptr(0x5D4594, 747864);
					v6 = *getMemU32Ptr(0x5D4594, 24 * v3 + 747892);
					*getMemU8Ptr( 0x5D4594, *getMemU32Ptr(0x5D4594, 747864) + 741692) = getMemByte(0x5D4594, 24 * v3 + 747892);
					*getMemU32Ptr(0x5D4594, 747864) = v5 + 4;
					result = sub_42D440(v6);
					if (result) {
						result = sub_42D450(*getMemU32Ptr(0x5D4594, 24 * v3 + 747892));
						memcpy(getMemAt(0x5D4594, *getMemU32Ptr(0x5D4594, 747864) + 741692), getMemAt(0x5D4594, 24 * v3 + 747896),
								result);
						*getMemU32Ptr(0x5D4594, 747864) += result;
					}
				}
				v3 = (v3 + 1) % 128;
			} while (v3 != dword_5d4594_754036);
		}
		dword_5d4594_754040 = v3;
	} else if (dword_5d4594_754036 > 0) {
		v7 = getMemIntPtr(0x5D4594, 747892);
		do {
			if (v7[2] == 1) {
				v8 = *getMemU32Ptr(0x5D4594, 747864);
				v9 = *v7;
				*getMemU8Ptr( 0x5D4594, *getMemU32Ptr(0x5D4594, 747864) + 741692) = *(_BYTE*)v7;
				*getMemU32Ptr(0x5D4594, 747864) = v8 + 4;
				if (sub_42D440(v9)) {
					v10 = sub_42D450(*v7);
					memcpy(getMemAt(0x5D4594, *getMemU32Ptr(0x5D4594, 747864) + 741692), v7 + 1, v10);
					*getMemU32Ptr(0x5D4594, 747864) += v10;
				}
			}
			result = dword_5d4594_754036;
			++v0;
			v7 += 6;
		} while (v0 < *(int*)&dword_5d4594_754036);
	}
	return result;
}

//----- (0042E600) --------------------------------------------------------
char* sub_42E600() {
	sub_413A00(0);
	return sub_4DB790("AUTOSAVE");
}

//----- (0042E620) --------------------------------------------------------
void sub_42E620() { sub_413A00(0); }

//----- (0042E630) --------------------------------------------------------
int sub_42E630() {
	char* v0;   // eax
	int result; // eax

	v0 = (char*)sub_416640();
	switch (*(_DWORD*)(v0 + 66)) {
	case 1:
		result = sub_554290();
		break;
	case 2:
		result = sub_554300();
		break;
	case 3:
		result = *(_DWORD*)(v0 + 70);
		break;
	default:
		result = 0;
		break;
	}
	return result;
}
// 42E644: control flows out of bounds to 554290
// 42E649: control flows out of bounds to 554300

//----- (0042E670) --------------------------------------------------------
void __cdecl sub_42E670(int a1, int a2) {
	bool v2;    // zf
	int result; // eax
	int v4;     // ecx
	int v5;     // eax

	v2 = !nox_common_gameFlags_check_40A5C0(1);
	result = dword_5d4594_754036;
	if (v2) {
		if (*(int*)&dword_5d4594_754036 >= 128)
			return;
	} else {
		result = dword_5d4594_754036 + 1;
		if (dword_5d4594_754036 + 1 == dword_5d4594_754040)
			return;
	}
	if (getMemByte(0x5D4594, 2661958) || (result = sub_42D460(a1)) == 0) {
		if (nox_common_gameFlags_check_40A5C0(1) && sub_42D4B0(a1)) {
			result = dword_5d4594_754040;
			v4 = dword_5d4594_754036;
			if (dword_5d4594_754040 != dword_5d4594_754036) {
				while (*getMemU32Ptr(0x5D4594, 24 * result + 747892) != a1) {
					result = (result + 1) % 128;
					if (result == dword_5d4594_754036)
						goto LABEL_14;
				}
				return;
			}
		} else {
			v4 = dword_5d4594_754036;
		}
	LABEL_14:
		v5 = 24 * v4;
		*getMemU32Ptr(0x5D4594, v5 + 747884) = *getMemU32Ptr(0x5D4594, 747876);
		*getMemU32Ptr(0x5D4594, v5 + 747888) = *getMemU32Ptr(0x5D4594, 747880);
		*getMemU32Ptr(0x5D4594, v5 + 747892) = a1;
		*getMemU32Ptr(0x5D4594, v5 + 747900) = 1;
		*getMemU32Ptr(0x5D4594, v5 + 747896) = a2;
		dword_5d4594_754036 = v4 + 1;
		if (nox_common_gameFlags_check_40A5C0(1)) {
			dword_5d4594_754036 %= 128;
		}
	}
}

//----- (0042E780) --------------------------------------------------------
void __cdecl sub_42E780(int a1, int a2) {
	if (*getMemU32Ptr(0x5D4594, 2614252) && !(*(_BYTE*)(*getMemU32Ptr(0x5D4594, 2614252) + 120) & 2)) {
		int result = sub_413A50();
		if (!result)
			sub_42E670(a1, a2);
	}
}

//----- (0042E7B0) --------------------------------------------------------
void __cdecl sub_42E7B0(int a1) {
	int v1;     // esi
	__int16 v2; // ax

	v1 = a1;
	if (a1 && (!*getMemU32Ptr(0x5D4594, 2618908) || !(*(_BYTE*)(*getMemU32Ptr(0x5D4594, 2618908) + 3680) & 3)) &&
		sub_478030() != 1 && sub_446360() != 1) {
		v2 = *(_WORD*)(v1 + 128);
		LOWORD(a1) = 464;
		HIWORD(a1) = v2;
		sub_40EBC0(31, 0, &a1, 4);
	}
}

//----- (0042E810) --------------------------------------------------------
void __cdecl sub_42E810(int a1) {
	int v1; // [esp-4h] [ebp-4h]

	if (a1 && (!*getMemU32Ptr(0x5D4594, 2618908) || !(*(_BYTE*)(*getMemU32Ptr(0x5D4594, 2618908) + 3680) & 3))) {
		v1 = a1;
		LOBYTE(a1) = 123;
		*(_WORD*)((char*)&a1 + 1) = sub_578B00(v1);
		sub_40EBC0(31, 0, &a1, 3);
	}
}

//----- (0042E850) --------------------------------------------------------
void __cdecl sub_42E850(int a1) {
	int v1; // esi

	v1 = a1;
	if (a1 && (!*getMemU32Ptr(0x5D4594, 2618908) || !(*(_BYTE*)(*getMemU32Ptr(0x5D4594, 2618908) + 3680) & 3)) &&
		sub_47A260() != 1 && sub_446360() != 1) {
		LOWORD(a1) = 5577;
		HIWORD(a1) = sub_578B00(v1);
		sub_40EBC0(31, 0, &a1, 4);
	}
}

//----- (0042E8C0) --------------------------------------------------------
void __cdecl sub_42E8C0(int a1) { nullsub_33(a1, getMemAt(0x5D4594, 747884), dword_5d4594_754036); }
// 42E8B0: using guessed type void __cdecl nullsub_33(_DWORD, _DWORD, _DWORD);

//----- (0042E8E0) --------------------------------------------------------
char* __cdecl sub_42E8E0(int a1, int a2) {
	_DWORD* v2;          // esi
	int v3;              // ebp
	int v4;              // edi
	_DWORD* v5;          // ebx
	int v6;              // ecx
	unsigned __int8* v7; // eax

	v2 = *(_DWORD**)&dword_5d4594_754056;
	if (!dword_5d4594_754056)
		return (char*)getMemAt(0x5D4594, 754072);
	while (1) {
		v3 = v2[17];
		v4 = 0;
		if (v3 > 0)
			break;
	LABEL_11:
		v2 = (_DWORD*)v2[19];
		if (!v2)
			return (char*)getMemAt(0x5D4594, 754072);
	}
	v5 = v2 + 9;
	while (1) {
		if (*v5 == a1 && --a2 <= 0) {
			v6 = 0;
			if (*getMemU32Ptr(0x587000, 73672))
				break;
		}
	LABEL_10:
		++v4;
		++v5;
		if (v4 >= v3)
			goto LABEL_11;
	}
	v7 = getMemAt(0x587000, 73672);
	while (*v2 != *((_DWORD*)v7 + 1)) {
		v7 += 16;
		++v6;
		if (!*(_DWORD*)v7)
			goto LABEL_10;
	}
	return *(char**)getMemAt(0x587000, 16 * v6 + 73684);
}

//----- (0042E960) --------------------------------------------------------
char* __cdecl sub_42E960(wchar_t* a1) {
	int v1;             // edi
	unsigned __int8* i; // esi
	int v3;             // eax

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 73672))
		return 0;
	for (i = getMemAt(0x587000, 73672); _nox_wcsicmp(*((const wchar_t**)i + 3), a1); i += 16) {
		v3 = *((_DWORD*)i + 4);
		++v1;
		if (!v3)
			return 0;
	}
	return *(char**)getMemAt(0x587000, 16 * v1 + 73672);
}

//----- (0042E9B0) --------------------------------------------------------
char* __cdecl sub_42E9B0(char* a1) {
	int v1;              // edi
	const char** v2;     // eax
	unsigned __int8* v3; // esi
	int v4;              // ecx

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 73672))
		return (char*)getMemAt(0x5D4594, 754076);
	v2 = (const char**)getMemAt(0x587000, 73672);
	v3 = getMemAt(0x587000, 73672);
	while (_strcmpi(*v2, a1)) {
		v4 = *((_DWORD*)v3 + 4);
		v3 += 16;
		++v1;
		v2 = (const char**)v3;
		if (!v4)
			return (char*)getMemAt(0x5D4594, 754076);
	}
	return *(char**)getMemAt(0x587000, 16 * v1 + 73684);
}

//----- (0042EA00) --------------------------------------------------------
char* __cdecl sub_42EA00(char* a1) {
	int v1;             // ecx
	unsigned __int8* i; // eax
	int v3;             // esi

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 73672))
		return (char*)getMemAt(0x5D4594, 754080);
	for (i = getMemAt(0x587000, 73672); *((char**)i + 1) != a1; i += 16) {
		v3 = *((_DWORD*)i + 4);
		++v1;
		if (!v3)
			return (char*)getMemAt(0x5D4594, 754080);
	}
	return *(char**)getMemAt(0x587000, 16 * v1 + 73684);
}

//----- (0042EA40) --------------------------------------------------------
int __cdecl sub_42EA40(wchar_t* a1) {
	int v1;             // edi
	unsigned __int8* i; // esi
	int v3;             // eax

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 75880))
		return 0;
	for (i = getMemAt(0x587000, 75880); _nox_wcsicmp(*((const wchar_t**)i + 2), a1); i += 12) {
		v3 = *((_DWORD*)i + 3);
		++v1;
		if (!v3)
			return 0;
	}
	return *getMemU32Ptr(0x587000, 12 * v1 + 75880);
}

//----- (0042EA90) --------------------------------------------------------
char* __cdecl sub_42EA90(char* a1) {
	int v1;              // edi
	const char** v2;     // eax
	unsigned __int8* v3; // esi
	int v4;              // ecx

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 75880))
		return (char*)getMemAt(0x5D4594, 754084);
	v2 = (const char**)getMemAt(0x587000, 75880);
	v3 = getMemAt(0x587000, 75880);
	while (_strcmpi(*v2, a1)) {
		v4 = *((_DWORD*)v3 + 3);
		v3 += 12;
		++v1;
		v2 = (const char**)v3;
		if (!v4)
			return (char*)getMemAt(0x5D4594, 754084);
	}
	return *(char**)getMemAt(0x587000, 12 * v1 + 75888);
}

//----- (0042EB90) --------------------------------------------------------
int __cdecl sub_42EB90(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 754052) = a1;
	return result;
}

//----- (0042EBA0) --------------------------------------------------------
int sub_42EBA0() { return *getMemU32Ptr(0x5D4594, 754052); }

//----- (0042ED20) --------------------------------------------------------
void sub_42ED20() {
	if (!obj_5D4594_754104_switch) {
		return;
	}
	obj_5D4594_754104_switch = 0;
	if (!ptr_5D4594_754088) {
		return;
	}
	for (int i = 0; i < ptr_5D4594_754088_cnt; i++) {
		obj_5D4594_754088_t* cur = &ptr_5D4594_754088[i];
		cur->fnc(cur->field_4);
	}
}

//----- (0042ED70) --------------------------------------------------------
void sub_42ED70() {
	if (obj_5D4594_754104_switch) {
		return;
	}
	obj_5D4594_754104_switch = 1;
	if (!ptr_5D4594_754092) {
		return;
	}
	for (int i = 0; i < ptr_5D4594_754092_cnt; i++) {
		obj_5D4594_754088_t* cur = &ptr_5D4594_754092[i];
		cur->fnc(cur->field_4);
	}
}

//----- (0042EDC0) --------------------------------------------------------
void sub_42EDC0() {
	if (ptr_5D4594_754088) {
		free(ptr_5D4594_754088);
		ptr_5D4594_754088 = 0;
	}
	if (ptr_5D4594_754092) {
		free(ptr_5D4594_754092);
		ptr_5D4594_754092 = 0;
	}
}

//----- (0042EE00) --------------------------------------------------------
int sub_42EE00() {
	unsigned __int8* v0; // ecx
	int result;          // eax
	int v2;              // esi

	v0 = *(unsigned __int8**)&dword_5d4594_787200;
	result = 0;
	if (dword_5d4594_787200 && *getMemU32Ptr(0x5D4594, 787216)) {
		v2 = *getMemU32Ptr(0x5D4594, 787216);
		do {
			result += *v0++;
			--v2;
		} while (v2);
	}
	return result;
}

//----- (0042EE30) --------------------------------------------------------
int __cdecl nox_video_read_videobag(int a1) {
	char* v1;            // eax
	int result;          // eax
	int* v3;             // eax
	int* v4;             // esi
	int v5;              // eax
	unsigned __int8* v6; // edi
	int v7;              // eax
	signed int v8;       // [esp-4h] [ebp-40h]
	char v9[20];         // [esp+8h] [ebp-34h]

	dword_5d4594_787144 = 0;
	v1 = nox_video_getbagfilename(a1);
	result = (int)fopen(v1, "rb");
	nox_video_bag_fileptr = result;
	if (result) {
		v3 = (int*)sub_42F0B0(a1);
		v4 = v3;
		if (v3) {
			v5 = sub_42F1B0(v3, (int*)v9);
			if (v5) {
				v6 = (unsigned __int8*)v4 + v5;
				*getMemU32Ptr(0x5D4594, 787168) = *(_DWORD*)&v9[16];
				dword_5d4594_787172 = *(_DWORD*)&v9[12];
				dword_5d4594_787184 = *(_DWORD*)&v9[4];
				if (dword_5d4594_787208) {
					free(*(LPVOID*)&dword_5d4594_787208);
					dword_5d4594_787208 = 0;
				}
				if (dword_5d4594_754144)
					dword_5d4594_787208 = malloc(*(size_t*)&dword_5d4594_787184);
				if (!dword_5d4594_787212)
					dword_5d4594_787212 = sub_578BF0();
				if (*getMemU32Ptr(0x5D4594, 2650640) == 1)
					sub_47A270();
				dword_5d4594_787148 = malloc(36 * dword_5d4594_787172);
				dword_5d4594_787152 = malloc(12 * *getMemU32Ptr(0x5D4594, 787168));
				sub_42F200(v6, a1);
				free(v4);
				v7 = 0x800000;
				if (*(_DWORD*)&v9[4] * dword_5d4594_787172 < 0x800000)
					v7 = *(_DWORD*)&v9[4] * dword_5d4594_787172;
				v8 = *(_DWORD*)&v9[4] * (v7 / *(_DWORD*)&v9[4]);
				dword_5d4594_787192 = v8 / *(_DWORD*)&v9[4];
				result = (int)malloc(v8);
				dword_5d4594_787200 = result;
				if (result) {
					*getMemU32Ptr(0x5D4594, 3807164) = getMemAt(0x5D4594, 754148);
					dword_5d4594_787144 = 1;
					sub_42EFF0();
					result = 1;
				}
			} else {
				free(v4);
				fclose(nox_video_bag_fileptr);
				result = 0;
			}
		} else {
			fclose(nox_video_bag_fileptr);
			result = 0;
		}
	}
	return result;
}

//----- (0042EFF0) --------------------------------------------------------
int sub_42EFF0() {
	int result; // eax

	sub_42F030();
	if (dword_5d4594_3804680) {
		result = dword_5d4594_787192;
		*getMemU32Ptr(0x5D4594, 787176) = dword_5d4594_787184;
	} else {
		result = dword_5d4594_787180;
		*getMemU32Ptr(0x5D4594, 787176) = dword_5d4594_787180;
	}
	dword_5d4594_787188 = dword_5d4594_787192;
	return result;
}

//----- (0042F030) --------------------------------------------------------
char* sub_42F030() {
	char* result; // eax
	int v1;       // edi
	int v2;       // esi

	result = *(char**)&dword_5d4594_787172;
	v1 = 0;
	if (dword_5d4594_787172 > 0) {
		result = *(char**)&dword_5d4594_787148;
		v2 = 0;
		do {
			if (*(_DWORD*)&result[v2]) {
				if (*(int*)&result[v2 + 24] == -1) {
					free(*(LPVOID*)&result[v2]);
					result = *(char**)&dword_5d4594_787148;
				}
				*(_DWORD*)&result[v2] = 0;
				result = *(char**)&dword_5d4594_787148;
			}
			++v1;
			v2 += 36;
		} while (v1 < *(int*)&dword_5d4594_787172);
	}
	*getMemU32Ptr(0x5D4594, 787136) = 0;
	*getMemU32Ptr(0x5D4594, 787140) = getMemAt(0x5D4594, 754108);
	*getMemU32Ptr(0x5D4594, 754136) = getMemAt(0x5D4594, 787108);
	*getMemU32Ptr(0x5D4594, 754140) = 0;
	return result;
}

//----- (0042F0B0) --------------------------------------------------------
FILE* __cdecl sub_42F0B0(int a1) {
	char* v1;      // eax
	FILE* result;  // eax
	FILE* v3;      // esi
	char* v4;      // edi
	signed int v5; // eax
	size_t v6;     // [esp+8h] [ebp-8h]
	int v7;        // [esp+Ch] [ebp-4h]

	v6 = 0;
	v7 = 0;
	v1 = sub_430120(a1);
	result = fopen(v1, "rb");
	v3 = result;
	if (result) {
		sub_40ADD0_fread((char*)&v7, 4u, 1u, result);
		dword_5d4594_754144 = 0;
		if (v7 == -85082901) {
			dword_5d4594_754144 = 1;
		} else if (v7 != -85082902) {
			fclose(v3);
			return 0;
		}
		sub_40ADD0_fread((char*)&v6, 4u, 1u, v3);
		v4 = (char*)malloc(v6);
		if (v4) {
			fseek(v3, 0, SEEK_SET);
			v5 = sub_40ADD0_fread(v4, 1u, v6, v3);
			if (v5 == v6) {
				fclose(v3);
				result = (FILE*)v4;
			} else {
				fclose(v3);
				result = 0;
			}
		} else {
			fclose(v3);
			result = 0;
		}
	}
	return result;
}

//----- (0042F1B0) --------------------------------------------------------
int __cdecl sub_42F1B0(int* a1, int* a2) {
	int v2;  // edx
	bool v3; // zf

	v2 = *a1;
	v3 = *a1 == -85082902;
	*a2 = *a1;
	if (!v3 && v2 != -85082901)
		return 0;
	a2[3] = a1[2];
	a2[1] = a1[3];
	a2[2] = a1[4];
	a2[4] = a1[5];
	return 24;
}

//----- (0042F200) --------------------------------------------------------
int __cdecl sub_42F200(unsigned __int8* a1, int a2) {
	unsigned __int8* v2;  // ecx
	int result;           // eax
	int v4;               // esi
	int v5;               // ebx
	_DWORD* v6;           // ecx
	int v7;               // edx
	int v8;               // edi
	int v9;               // ebp
	int v10;              // ebx
	int v11;              // edx
	unsigned __int8* v12; // ecx
	unsigned __int8 v13;  // al
	_DWORD* v14;          // ecx
	int v15;              // edi
	int v16;              // [esp+0h] [ebp-Ch]
	int v17;              // [esp+4h] [ebp-8h]
	int v18;              // [esp+8h] [ebp-4h]
	int v19;              // [esp+10h] [ebp+4h]

	v2 = a1;
	result = 0;
	v17 = 0;
	v16 = 0;
	dword_5d4594_787180 = 0;
	v19 = 0;
	if (dword_5d4594_787172 > 0) {
		v4 = 0;
		do {
			v5 = *((_DWORD*)v2 + 1);
			v6 = v2 + 8;
			if (dword_5d4594_754144) {
				v7 = *v6;
				++v6;
			} else {
				v7 = v5;
			}
			v8 = *v6;
			v2 = (unsigned __int8*)(v6 + 1);
			*(_DWORD*)(v4 + dword_5d4594_787148) = 0;
			*(_DWORD*)(v4 + dword_5d4594_787148 + 4) = 0;
			*(_DWORD*)(v4 + dword_5d4594_787148 + 8) = v16;
			*(_DWORD*)(v4 + dword_5d4594_787148 + 12) = v5;
			*(_DWORD*)(v4 + dword_5d4594_787148 + 16) = v7;
			result = v17;
			*(_DWORD*)(v4 + dword_5d4594_787148 + 20) = v17;
			*(_DWORD*)(v4 + dword_5d4594_787148 + 24) = v8;
			v16 += v7;
			if (v8 == -1) {
				v8 = 1;
			} else if (v5 > *(int*)&dword_5d4594_787180) {
				dword_5d4594_787180 = v5;
			}
			v9 = 0;
			if (v8 <= 0) {
				v10 = v19;
			} else {
				v10 = v19;
				v11 = 12 * v17;
				v18 = v8;
				v17 += v8;
				do {
					*(_WORD*)(v11 + dword_5d4594_787152 + 8) = v19;
					v12 = &v2[*v2 + 1];
					v13 = *v12;
					v14 = v12 + 1;
					*(_BYTE*)(v11 + dword_5d4594_787152 + 10) = v13;
					if (a2 == 1)
						v15 = *v14;
					else
						v15 = v14[1];
					v2 = (unsigned __int8*)(v14 + 2);
					v11 += 12;
					*(_DWORD*)(v11 + dword_5d4594_787152 - 12) = v9;
					v9 += v15;
					--v18;
				} while (v18);
				result = v17;
			}
			v4 += 36;
			v19 = v10 + 1;
		} while (v10 + 1 < *(int*)&dword_5d4594_787172);
	}
	if (dword_5d4594_787180 > *(int*)&dword_5d4594_787184)
		dword_5d4594_787180 = dword_5d4594_787184;
	return result;
}

//----- (0042F370) --------------------------------------------------------
int __cdecl nox_video_parse_videobag(int is8bit) {
	int result;          // eax
	char* v2;            // eax
	int* v3;             // eax
	int* v4;             // esi
	int v5;              // eax
	unsigned __int8* v6; // ebx
	char v7[20];         // [esp+8h] [ebp-14h]

	if (!nox_video_bag_fileptr)
		return 1;
	dword_5d4594_787144 = 0;
	v2 = nox_video_getbagfilename(is8bit);
	if (is8bit != *getMemU32Ptr(0x587000, 80720)) {
		*getMemU32Ptr(0x587000, 80720) = is8bit;
		nox_video_reopen_videobag(v2);
	}
	sub_42F030();
	v3 = (int*)sub_42F0B0(is8bit);
	v4 = v3;
	if (v3) {
		v5 = sub_42F1B0(v3, (int*)v7);
		if (v5) {
			v6 = (unsigned __int8*)v4 + v5;
			if (*getMemU32Ptr(0x5D4594, 2650640) == 1)
				sub_47A270();
			sub_42F200(v6, is8bit);
			free(v4);
			if (dword_5d4594_787208) {
				free(*(LPVOID*)&dword_5d4594_787208);
				dword_5d4594_787208 = 0;
			}
			if (dword_5d4594_754144)
				dword_5d4594_787208 = malloc(*(size_t*)&dword_5d4594_787184);
			sub_42EFF0();
			result = 1;
			dword_5d4594_787144 = 1;
		} else {
			free(v4);
			fclose(nox_video_bag_fileptr);
			result = 0;
		}
	} else {
		fclose(nox_video_bag_fileptr);
		result = 0;
	}
	return result;
}

//----- (0042F490) --------------------------------------------------------
BOOL __cdecl nox_video_reopen_videobag(char* a1) {
	if (nox_video_bag_fileptr)
		fclose(nox_video_bag_fileptr);
	nox_video_bag_fileptr = fopen(a1, "rb");
	return nox_video_bag_fileptr != 0;
}

//----- (0042F4D0) --------------------------------------------------------
void sub_42F4D0() {
	_BYTE* v0; // eax
	int v1;    // edi
	int v2;    // esi

	dword_5d4594_787144 = 0;
	sub_42F030();
	if (dword_5d4594_787200) {
		free(*(LPVOID*)&dword_5d4594_787200);
		dword_5d4594_787200 = 0;
	}
	if (dword_5d4594_787148) {
		free(*(LPVOID*)&dword_5d4594_787148);
		dword_5d4594_787148 = 0;
	}
	if (dword_5d4594_787152) {
		free(*(LPVOID*)&dword_5d4594_787152);
		dword_5d4594_787152 = 0;
	}
	v0 = *(_BYTE**)&dword_5d4594_787156;
	if (dword_5d4594_787156) {
		v1 = 0;
		if (dword_5d4594_787164 > 0) {
			v2 = 0;
			do {
				if (v0[v2 + 101] == 2) {
					free(*(LPVOID*)(*(_DWORD*)&v0[v2 + 96] + 4));
					free(*(LPVOID*)(v2 + dword_5d4594_787156 + 96));
					v0 = *(_BYTE**)&dword_5d4594_787156;
				}
				++v1;
				v2 += 104;
			} while (v1 < *(int*)&dword_5d4594_787164);
		}
		free(v0);
		dword_5d4594_787156 = 0;
		*getMemU32Ptr(0x5D4594, 787160) = 0;
		dword_5d4594_787164 = 0;
	}
	dword_5d4594_787192 = 0;
	dword_5d4594_787188 = 0;
	*getMemU32Ptr(0x5D4594, 787136) = 0;
	*getMemU32Ptr(0x5D4594, 787140) = getMemAt(0x5D4594, 754108);
	*getMemU32Ptr(0x5D4594, 754136) = getMemAt(0x5D4594, 787108);
	*getMemU32Ptr(0x5D4594, 754140) = 0;
	sub_47D150();
	fclose(nox_video_bag_fileptr);
	nox_video_bag_fileptr = 0;
	if (dword_5d4594_787212) {
		sub_578C40(*(LPVOID*)&dword_5d4594_787212);
		dword_5d4594_787212 = 0;
	}
	if (dword_5d4594_787208) {
		free(*(LPVOID*)&dword_5d4594_787208);
		dword_5d4594_787208 = 0;
	}
}

//----- (0042F610) --------------------------------------------------------
int __cdecl sub_42F610(int a1) {
	int result; // eax

	if (a1 < 0)
		return 0;
	result = (int)malloc(104 * a1);
	dword_5d4594_787156 = result;
	if (result) {
		*getMemU32Ptr(0x5D4594, 787160) = a1;
		dword_5d4594_787164 = 0;
		result = 1;
	}
	return result;
}

//----- (0042F660) --------------------------------------------------------
int __cdecl sub_42F660(int a1, void* a2) {
	int v2;               // ebp
	void* v3;             // ebx
	unsigned __int8* v4;  // eax
	char* v5;             // eax
	char v6;              // cl
	_DWORD* v7;           // eax
	int v8;               // edi
	char* v9;             // eax
	char v10;             // cl
	unsigned __int8* v11; // eax
	_DWORD* v12;          // eax
	_DWORD* v13;          // ebx
	unsigned __int8* v14; // eax
	void* v15;            // eax
	char* v16;            // eax
	char v17;             // cl
	unsigned __int8* v18; // eax
	int v19;              // edi
	_DWORD* v20;          // eax
	int v21;              // ecx
	char* v22;            // eax
	char v23;             // cl
	unsigned __int8* v24; // eax
	int v26;              // [esp-4h] [ebp-28h]
	int v27;              // [esp+10h] [ebp-14h]
	char v28[16];         // [esp+14h] [ebp-10h]
	unsigned __int8 v29;  // [esp+28h] [ebp+4h]
	unsigned __int8 v30;  // [esp+28h] [ebp+4h]
	unsigned __int8 v31;  // [esp+28h] [ebp+4h]
	unsigned __int8 v32;  // [esp+28h] [ebp+4h]
	unsigned __int8 v33;  // [esp+2Ch] [ebp+8h]

	if (dword_5d4594_787164 < *getMemIntPtr(0x5D4594, 787160)) {
		v2 = a1;
		v3 = a2;
		v26 = a1;
		v4 = *(unsigned __int8**)(a1 + 8);
		v29 = *v4;
		*(_DWORD*)(v26 + 8) = v4 + 1;
		nox_memfile_read(a2, 1u, v29, v26);
		*((_BYTE*)a2 + v29) = 0;
		strcpy((char*)(dword_5d4594_787156 + 104 * dword_5d4594_787164), (const char*)a2);
		v5 = *(char**)(v2 + 8);
		v6 = *v5;
		*(_DWORD*)(v2 + 8) = v5 + 1;
		*(_BYTE*)(dword_5d4594_787156 + 104 * dword_5d4594_787164 + 101) = v6;
		if (v6 == 1) {
			v7 = *(_DWORD**)(v2 + 8);
			v8 = *v7;
			v9 = (char*)(v7 + 1);
			*(_DWORD*)(v2 + 8) = v9;
			if (v8 == -1) {
				v10 = *v9;
				v11 = (unsigned __int8*)(v9 + 1);
				*(_DWORD*)(v2 + 8) = v11;
				v30 = *v11;
				LOBYTE(a2) = v10;
				*(_DWORD*)(v2 + 8) = v11 + 1;
				nox_memfile_read(v3, 1u, v30, v2);
				*((_BYTE*)v3 + v30) = 0;
				if (sub_47A8C0((const char*)a2, (char*)v3)) {
					strcpy((char*)(dword_5d4594_787156 + 104 * dword_5d4594_787164 + 32), (const char*)v3);
					v8 = -1;
					*(_BYTE*)(dword_5d4594_787156 + 104 * dword_5d4594_787164 + 100) = (_BYTE)a2;
				} else {
					*(_BYTE*)(dword_5d4594_787156 + 104 * dword_5d4594_787164 + 100) = -1;
				}
			}
			*(_DWORD*)(dword_5d4594_787156 + 104 * dword_5d4594_787164 + 96) = v8;
		LABEL_22:
			++dword_5d4594_787164;
			return 1;
		}
		if (v6 == 2) {
			v12 = malloc(0x10u);
			v13 = v12;
			if (v12) {
				*v12 = 0;
				v14 = *(unsigned __int8**)(v2 + 8);
				v33 = *v14;
				*(_DWORD*)(v2 + 8) = v14 + 1;
				*((_BYTE*)v13 + 8) = v33;
				v27 = v33;
				v15 = malloc(4 * v33);
				v13[1] = v15;
				if (v15) {
					v16 = *(char**)(v2 + 8);
					v17 = *v16;
					*(_DWORD*)(v2 + 8) = v16 + 1;
					*((_BYTE*)v13 + 9) = v17;
					v18 = *(unsigned __int8**)(v2 + 8);
					v31 = *v18;
					*(_DWORD*)(v2 + 8) = v18 + 1;
					nox_memfile_read(v28, 1u, v31, v2);
					v28[v31] = 0;
					if (!strcmp(v28, "OneShot")) {
						*((_BYTE*)v13 + 10) = 0;
					LABEL_15:
						if (v33) {
							v19 = 0;
							do {
								v20 = *(_DWORD**)(v2 + 8);
								v21 = *v20;
								v22 = (char*)(v20 + 1);
								*(_DWORD*)(v2 + 8) = v22;
								if (v21 == -1) {
									v23 = *v22;
									v24 = (unsigned __int8*)(v22 + 1);
									*(_DWORD*)(v2 + 8) = v24;
									v32 = *v24;
									*(_DWORD*)(v2 + 8) = v24 + 1;
									LOBYTE(a2) = v23;
									nox_memfile_read(v28, 1u, v32, v2);
									v28[v32] = 0;
									*(_DWORD*)(v13[1] + v19) = sub_47A8C0((const char*)a2, v28);
								} else {
									*(_DWORD*)(v13[1] + v19) = dword_5d4594_787152 + 12 * v21;
								}
								v19 += 4;
								--v27;
							} while (v27);
						}
						*(_DWORD*)(dword_5d4594_787156 + 104 * dword_5d4594_787164 + 96) = v13;
						goto LABEL_22;
					}
					if (!strcmp(v28, "Loop")) {
						*((_BYTE*)v13 + 10) = 2;
						goto LABEL_15;
					}
				}
			}
		}
	}
	return 0;
}
// 42F660: using guessed type char var_10[16];

//----- (0042F970) --------------------------------------------------------
char* __cdecl sub_42F970(const char* a1) {
	int v1;         // edi
	const char* i;  // ebp
	int v4;         // eax
	const char* v5; // ecx

	if (!a1)
		return 0;
	v1 = 0;
	if (*(int*)&dword_5d4594_787164 <= 0)
		return 0;
	for (i = *(const char**)&dword_5d4594_787156; strcmp(a1, i); i += 104) {
		if (++v1 >= *(int*)&dword_5d4594_787164)
			return 0;
	}
	v4 = dword_5d4594_787156 + 104 * v1;
	v5 = *(const char**)(v4 + 96);
	if ((int)v5 == -1) {
		LOBYTE(v5) = *(_BYTE*)(v4 + 100);
		if ((_BYTE)v5 != (_BYTE)-1)
			return sub_47A8C0(v5, (char*)(v4 + 32));
		return 0;
	}
	return (char*)(dword_5d4594_787152 + 12 * (_DWORD)v5);
}

//----- (0042FA20) --------------------------------------------------------
char* __cdecl sub_42FA20(const char* a1) {
	int v1;        // edi
	const char* i; // ebp

	if (!a1)
		return 0;
	v1 = 0;
	if (*(int*)&dword_5d4594_787164 <= 0)
		return 0;
	for (i = *(const char**)&dword_5d4594_787156; strcmp(a1, i); i += 104) {
		if (++v1 >= *(int*)&dword_5d4594_787164)
			return 0;
	}
	return (char*)(dword_5d4594_787156 + 104 * v1);
}

//----- (0042FAA0) --------------------------------------------------------
char* __cdecl sub_42FAA0(int known_idx, const char* a2, char* a3) {
	if (known_idx != -1) {
		return (char*)(dword_5d4594_787152 + 12 * known_idx);
	}

	return sub_47A8C0(a2, a3);
}

//----- (0042FAD0) --------------------------------------------------------
int sub_42FAD0() { return 0; }

//----- (0042FAE0) --------------------------------------------------------
_DWORD* __cdecl sub_42FAE0(int a1) {
	_DWORD* result; // eax

	result = (_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8));
	if (result[6] == -1) {
		result = (_DWORD*)*result;
		if (result) {
			free(result);
			result = *(_DWORD**)&dword_5d4594_787148;
			*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8)) = 0;
		}
	}
	return result;
}

//----- (0042FB30) --------------------------------------------------------
int __cdecl sub_42FB30(int a1) {
	int v2;     // ecx
	int* v3;    // eax
	int v4;     // edx
	_DWORD* v5; // ecx
	_DWORD* v6; // eax

	if (dword_5d4594_787224)
		return 0;
	if (!a1)
		return 0;
	if ((*(_BYTE*)(a1 + 10) & 0x3F) == 7)
		return sub_42FAD0();
	if (*(_BYTE*)(a1 + 10) & 0x80)
		return *(_DWORD*)a1;
	v2 = dword_5d4594_787148;
	dword_5d4594_787224 = 1;
	v3 = (int*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8));
	v4 = *v3;
	if (v3[6] != -1) {
		if (v4) {
			if (v3[1] == *getMemU32Ptr(0x5D4594, 2598000)) {
			LABEL_19:
				dword_5d4594_787224 = 0;
				return *(_DWORD*)a1 + *(_DWORD*)(v2 + 36 * *(unsigned __int16*)(a1 + 8));
			}
			v3[1] = *getMemU32Ptr(0x5D4594, 2598000);
			*(_DWORD*)(*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8) + 28) + 32) =
				*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8) + 32);
			*(_DWORD*)(*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8) + 32) + 28) =
				*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8) + 28);
		} else {
			if (!dword_5d4594_787188) {
				v5 = *(_DWORD**)getMemAt(0x5D4594, 754136);
				++*getMemU32Ptr(0x5D4594, 787220);
				v6 = (_DWORD*)(*getMemU32Ptr(0x5D4594, 754136) + 28);
				*(_DWORD*)(*(_DWORD*)(*getMemU32Ptr(0x5D4594, 754136) + 28) + 32) = getMemAt(0x5D4594, 754108);
				*getMemU32Ptr(0x5D4594, 754136) = *v6;
				*v6 = 0;
				v5[8] = 0;
				*(_DWORD*)(*getMemU32Ptr(0x5D4594, 787140) + 28) =
					dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8);
				*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8) + 28) = getMemAt(0x5D4594, 787108);
				*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8) + 32) =
					*getMemU32Ptr(0x5D4594, 787140);
				*getMemU32Ptr(0x5D4594, 787140) = dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8);
				*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8)) = *v5;
				*v5 = 0;
				sub_42FE30(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8));
				*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8) + 4) =
					*getMemU32Ptr(0x5D4594, 2598000);
				dword_5d4594_787224 = 0;
				return *(_DWORD*)a1 + *(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8));
			}
			*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8)) =
				dword_5d4594_787200 + --dword_5d4594_787188 * *getMemU32Ptr(0x5D4594, 787176);
			sub_42FE30(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8));
			*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8) + 4) = *getMemU32Ptr(0x5D4594, 2598000);
		}
		*(_DWORD*)(*getMemU32Ptr(0x5D4594, 787140) + 28) = dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8);
		*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8) + 28) = getMemAt(0x5D4594, 787108);
		*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8) + 32) = *getMemU32Ptr(0x5D4594, 787140);
		v2 = dword_5d4594_787148;
		*getMemU32Ptr(0x5D4594, 787140) = dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8);
		goto LABEL_19;
	}
	if (!v4) {
		*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8)) = malloc(v3[3]);
		sub_42FE30(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8));
		*(_DWORD*)(dword_5d4594_787148 + 36 * *(unsigned __int16*)(a1 + 8) + 4) = *getMemU32Ptr(0x5D4594, 2598000);
		v2 = dword_5d4594_787148;
	}
	dword_5d4594_787224 = 0;
	return *(_DWORD*)(v2 + 36 * *(unsigned __int16*)(a1 + 8));
}

//----- (0042FE30) --------------------------------------------------------
#ifdef __EMSCRIPTEN__0
const struct bag_file {
	unsigned int offset;
	unsigned int size;
	const char* path;
} bag_files[] = {
	{0, 16780329, "video.bag.0"},         {16780329, 16784856, "video.bag.1"}, {33565185, 16784032, "video.bag.2"},
	{50349217, 16785943, "video.bag.3"},  {67135160, 16780261, "video.bag.4"}, {83915421, 16787457, "video.bag.5"},
	{100702878, 16784419, "video.bag.6"}, {117487297, 4419642, "video.bag.7"}, {0, 0, 0},
};
FILE* bag_fp[8];
#endif

static FILE* get_bag(unsigned int offset) {
	FILE* fp;
#ifdef __EMSCRIPTEN__0
	int i;
	for (i = 0; bag_files[i].path; i++) {
		if (bag_files[i].offset <= offset && offset - bag_files[i].offset < bag_files[i].size) {
			fp = bag_fp[i];
			if (fp == NULL)
				fp = bag_fp[i] = fopen(bag_files[i].path, "rb");
			fseek(fp, offset - bag_files[i].offset, SEEK_SET);
		}
	}
#else
	fp = nox_video_bag_fileptr;
	fseek(fp, offset, SEEK_SET);
#endif
	return fp;
}

static int preloaded[] = {
	3,    4,    17,   18,   438,  439,  575,  584,  586,  587,  588,  589,  590,  592,  593,  596,  597,  628,  629,
	630,  631,  632,  708,  852,  853,  854,  856,  857,  858,  883,  884,  885,  886,  887,  888,  937,  938,  939,
	941,  942,  943,  944,  1016, 1020, 1021, 1022, 1023, 1025, 1026, 1028, 1029, 1030, 1085, 1086, 1087, 1088, 1094,
	1095, 1096, 1097, 1098, 1109, 1110, 1112, 1113, 1132, 1134, 1135, 1136, 1137, 1138, 1139, 1140, 1141, 1142, 1143,
	1144, 1145, 1146, 1147, 1148, 1149, 1150, 1151, 1152, 1153, 1154, 1155, 1156, 1157, 1158, 1159, 1160, 1161, 1162,
	1163, 1164, 1165, 1166, 1167, 1168, 1169, 1171, 1172, 1173, 1175, 1178, 1179, 1180, 1182, 1206, 1219, 1220, 1221,
	1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, 1232, 1233, 1234, 1235, 1236, 1237, 1239, 1240, 1241,
	1242, 1243, 1244, 1245, 1246, 1247, 1249, 1250, 1251, 1252, 1256, 1257, 1262, 1263, 1265, 1272, 1274, 1275, 1276,
	1277, 1349, 1351, 1352, 1358, 1359, 1360, 1361, 1377, 1378, 1429, 1433, 1434, 1445, 1478, 1524, 1525, 1526, 1527,
	1528, 1529, 1530, 1533, 1534, 1535, 1536, 1692, 1693, 1703, 1704, 1705, 1706, 1707, 1708, 1724, 1725, 1726, 1727,
	1743, 1744, 1745, 1746, 1748, 1749, 1750, 1751, 1752, 1753, 1754, 1755, 1756, 1757, 1758, 1759, 1760, 1763, 1764,
	1765, 1766, 1767, 1768, 1769, 1770, 1771, 1774, 1775, 1776, 1777, 1778, 1779, 1780, 1781, 1782, 1783, 1784, 1785,
	1786, 1787, 1790, 1791, 1792, 1793, 1794, 1795, 1796, 1797, 1798, 1799, 1800, 1801, 1802, 1803, 1804, 1805, 1806,
	1807, 1810, 1811, 1812, 1813, 1814, 1815, 1816, 1818, 1819, 1820, 1824, 1825, 1826, 1828, 1829, 1830, 1831, 1832,
	1834, 1835, 1837, 1838, 1839, 1840, 1841, 1842, 1843, 1844, 1845, 1846, 1847, 1848, 1849, 1850, 1851, 1852, 1853,
	1854, 1855, 1858, 1859, 1860, 1861, 1862, 1863, 1864, 1865, 1866, 1867, 1868, 1869, 1870, 1871, 1872, 1874, 1877,
	1878, 1879, 1880, 1881, 1882, 1883, 1884, 1885, 1886, 1887, 1888, 1889, 1901, 1902, 1903, 1904, 1906, 1907, 1908,
	1910, 1911, 1913, 1914, 1915, 1916, 1917, 1918, 1919, 1920, 1921, 1923, 1924, 1925, 1926, 1930, 1931, 1932, 1933,
	1934, 1935, 1936, 1937, 1938, 1939, 1940, 1941, 1942, 1943, 1944, 1945, 1946, 1947, 1948, 1952, 1953, 1958, 1959,
	1960, 1961, 1962, 1963, 1964, 1965, 1966, 1967, 1968, 1969, 1970, 1972, 1978, 1979, 1980, 1981, 1982, 1983, 1984,
	1985, 1988, 1989, 1990, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2006, 2007,
	2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2032, 2044, 2054, 2107, 2109, 2110, 2113, 2115,
	2125, 2143, 2161, 2163, 2170, 2271, 2278, 2287, 2288, 2289, 2290, 2291, 2292, 2293, 2294, 2295, 2297, 2298, 2299,
	2300, 2301, 2302, 2303, 2304, 2305, 2306, 2311, 2312, 2322, 2323, 2324, 2325, 2326, 2327, 2328, 2329, 2330, 2331,
	2332, 2371, 2380, 2381, 2382, 2383, 2384, 2385, 2386, 2388, 2389, 2390, 2395, 2396, 2401, 2402, 2403, 2404, 2405,
	2406, 2409, 2411, 2413, 2414, 2421, 2422, 2423, 2424, 2425, 2426, 2427, 2428, 2429, 2430, 2431, 2432, 2433, 2434,
	2435, 2436, 2437, 2439, 2441, 2442, 2443, 2446, 2447, 2449, 2450, 2451, 2452, 2453, 2454, 2455, 2456, 2457, 2458,
	2460, 2461, 2462, 2463, 2464, 2465, 2466, 2467, 2468, 2469, 2470, 2474, 2475, 2476, 2479, 2480, 2484, 2490, 2492,
	2530, 2534, 2547, 2550, 2554, 2555, 2556, 2557, 2558, 2563, 2564, 2565, 2566, 2578, 2579, 2580, 2585, 2609, 2619,
	2620, 2626, 2636, 2638, 2639, 2643, 2650, 2651, 2653, 2654, 2655, 2656, 2657, 2658, 2659, 2660, 2661, 2662, 2664,
	2667, 2668, 2669, 2670, 2677, 2678, 2684, 2687, 2688, 2689, 2690, 2691, 2692, 2693, 2694, 2695, 2696, 2697, 2698,
	2699, 2700, 2701, 2702, 2704, 2707, 2709, 2711, 2713, 2716, 2718, 2721, 2722, 2723, 2725, 2726, 2730, 2733, 2734,
	2735, 2749, 2750, 2751, 2752, 2753, 2754, 2756, 2757, 2758, 2759, 2760, 2761, 2767, 2768, 2771, 2772, 2776, 2780,
	2781, 2782, 2783, 2784, 2785, 2787, 2788, 2789, 2790, 2791, 2799, 2800, 2801, 2802, 2803, 2804, 2805, 2807, 2808,
	2811, 2812, 2813, 2814, 2815, 2816, 2818, 2819, 2820, 2821, 2822, 2823, 2827, 2828, 2831, 2832, 2833, 2835, 2836,
	2840, 2841, 2842, 2843, 2844, 2846, 2847, 2848, 2851, 2852, 2853, 2854, 2855, 2862, 2863, 2864, 2870, 2871, 2872,
	2873, 2877, 2878, 2879, 2885, 2901, 2909, 2912, 2916, 2919, 2923, 2929, 2942, 2944, 2945, 2946, 2947, 2948, 2949,
	2950, 2951, 2952, 2953, 2954, 2955, 2957, 2958, 2962, 2965, 2966, 2970, 2971, 2980, 2984, 2991, 2995, 2996, 2997,
	2998, 2999, 3000, 3001, 3002, 3007, 3008, 3009, 3010, 3011, 3012, 3013, 3014, 3015, 3016, 3017, 3033, 3034, 3035,
	3036, 3045, 3051, 3058, 3064, 3065, 3066, 3067, 3068, 3069, 3071, 3072, 3074, 3075, 3076, 3077, 3085, 3086, 3087,
	3096, 3097, 3098, 3114, 3116, 3118, 3122, 3130, 3133, 3134, 3135, 3136, 3137, 3138, 3139, 3140, 3141, 3142, 3143,
	3144, 3145, 3150, 3151, 3156, 3157, 3162, 3163, 3164, 3188, 3192, 3193, 3194, 3195, 3284, 3326, 3327, 3328, 3329,
	3330, 3331, 3332, 3334, 3335, 3339, 3340, 3341, 3355, 3356, 3458, 3505, 3516, 3517, 3518, 3519, 3520, 3521, 3522,
	3523, 3525, 3527, 3528, 3529, 3530, 3531, 3532, 3533, 3540, 3541, 3542, 3543, 3546, 3547, 3548, 3555, 3560, 3561,
	3562, 3563, 3564, 3565, 3570, 3571, 3572, 3577, 3578, 3579, 3584, 3585, 3586, 3587, 3588, 3589, 3590, 3591, 3683,
	3686, 3766, 3783, 3784, 3785, 3786, 3787, 3788, 3789, 3792, 3813, 3814, 3815, 3816, 3817, 3818, 3819, 3820, 3828,
	3829, 3830, 3831, 3832, 4115, 4116, 4117, 4118, 4119, 4120, 4121, 4122, 4123, 5751, 5756, 5757, 5758, 5759, 5760,
	5761, 5762, 5763, 5764, 5767, 5768, 5779, 5780, 5782, 5783, 5784, 5785, 5786, 5787, 5788, 5789, 5807, 5819, 5850,
	5858, 5869, 5970, 5971, 5972, 5979, 5980, 6019, 6030, 6031, 6050, 6051, 6052, 6053, 6054, 6055, 6056, 6057, 6058,
	6123, 6124, 6178, 6179, 6180, 6181, 6182, 6183, 6190, 6191, 6192, 6207, 6246, 6247, 6248, 6249, 6250, 6251, 6269,
	6270, 6271, 6272, 6273, 6274, 6275, 6276, 6277, 6278, 6279, 6280, 6281, 6282, 6283, 6284, 6285, 6408, -1};

void check_preload(unsigned int x) {
	int i;
	for (i = 0; preloaded[i] >= 0; i++)
		if (preloaded[i] == x)
			return;
	printf("bag: %d\n", x);
}

int __cdecl sub_42FE30(int a1) {
	int v1;        // esi
	signed int v2; // eax
	char* v3;      // ebx
	char* v4;      // ebp
	signed int v5; // eax
	char* v6;      // edi
	int v7;        // eax
	int result;    // eax
	int v9;        // [esp+8h] [ebp-8h]
	int v10;       // [esp+Ch] [ebp-4h]
	FILE* fp;

	v1 = a1;
	// check_preload((a1 - *(_DWORD *)&dword_5d4594_787148) / 36);
	fp = get_bag(*(_DWORD*)(a1 + 8));
	v2 = *(_DWORD*)(v1 + 16);
	if (*(_DWORD*)(v1 + 12) == v2) {
		v10 = sub_40ADD0_fread(*(char**)v1, 1u, v2, fp);
	} else {
		v3 = 0;
		v4 = *(char**)v1;
		if (v2 > *(int*)&dword_5d4594_787184) {
			v3 = (char*)malloc(v2);
			v10 = sub_40ADD0_fread(v3, 1u, *(_DWORD*)(v1 + 16), fp);
			v6 = v3;
		} else {
			v5 = sub_40ADD0_fread(*(char**)&dword_5d4594_787208, 1u, v2, fp);
			v6 = *(char**)&dword_5d4594_787208;
			v10 = v5;
		}
		v7 = *(_DWORD*)(v1 + 12);
		a1 = *(_DWORD*)(v1 + 16);
		v9 = v7;
		sub_578C30(*(int*)&dword_5d4594_787212);
		if (sub_578C10(*(_DWORD**)&dword_5d4594_787212, &v4[*(_DWORD*)(v1 + 12) - v9], &v9,
					   (unsigned int)&v6[*(_DWORD*)(v1 + 16) - a1], &a1)) {
			while (a1 > 0 && sub_578C10(*(_DWORD**)&dword_5d4594_787212, &v4[*(_DWORD*)(v1 + 12) - v9], &v9,
										(unsigned int)&v6[*(_DWORD*)(v1 + 16) - a1], &a1))
				;
		}
		if (v3)
			free(v3);
	}
	result = v10;
	if (v10 == *(_DWORD*)(v1 + 16) && dword_5d4594_3799624 == 2)
		result = sub_42FF90((_DWORD*)v1);
	return result;
}

//----- (0042FF90) --------------------------------------------------------
int __cdecl sub_42FF90(_DWORD* a1) {
	int v1;     // edx
	int result; // eax
	int v3;     // ecx
	int v4;     // esi
	int v5;     // ebx
	char v6;    // cl

	v1 = a1[6];
	result = a1[5];
	if (v1 >= 0)
		v3 = result + v1;
	else
		v3 = result - v1;
	if (result < v3) {
		v4 = 12 * result;
		v5 = v3 - result;
		do {
			result = v4 + dword_5d4594_787152;
			v6 = *(_BYTE*)(v4 + dword_5d4594_787152 + 10);
			if (v6) {
				if (v6 != 1)
					result = sub_47D480((int*)(*a1 + *(_DWORD*)result), v4 + dword_5d4594_787152);
			}
			v4 += 12;
			--v5;
		} while (v5);
	}
	return result;
}

//----- (0042FFF0) --------------------------------------------------------
BOOL __cdecl sub_42FFF0(FILE* a1) {
	signed int v1; // edx
	BOOL result;   // eax
	char v3[12];   // [esp+8h] [ebp-2Ch]
	char v4[32];   // [esp+14h] [ebp-20h]

	strcpy(v3, "LOOKUPTABLE");
	v1 = sub_40ADD0_fread(v4, 1u, strlen(v3), a1);
	result = 0;
	if (v1 == strlen(v3)) {
		v4[strlen(v3)] = 0;
		if (!strcmp(v4, v3))
			result = sub_40ADD0_fread((char*)getMemAt(0x5D4594, 754340), 1u, 0x8000u, a1) == 0x8000;
		else
			result = 0;
	}
	return result;
}
// 42FFF0: using guessed type char var_20[32];

//----- (004300D0) --------------------------------------------------------
BOOL __cdecl sub_4300D0(int a1) {
	char* v1; // eax

	v1 = nox_video_getbagfilename(a1);
	return _access(v1, 0) != -1;
}

//----- (00430100) --------------------------------------------------------
char* __cdecl nox_video_getbagfilename(int a1) {
#ifdef __EMSCRIPTEN__
	return "video.bag";
#else
    char* result = "video.bag";
	if (a1 != 1)
		result = "video8.bag";
	return result;
#endif
}

//----- (00430120) --------------------------------------------------------
char* __cdecl sub_430120(int a1) {
	char* result; // eax

	result = "video.idx";
	if (a1 != 1)
		result = "video8.idx";
	return result;
}

//----- (00430140) --------------------------------------------------------
void sub_430140(int a1) {
	unsigned __int8* v0; // eax

	v0 = getMemAt(0x5D4594, 789280);
	do {
		*(v0 - 2) = 0;
		*(_DWORD*)v0 = 0;
		*(v0 - 3) = 1;
		v0 += 8;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 791328));
	*getMemU32Ptr(0x5D4594, 791352) = 1;
	*getMemU32Ptr(0x5D4594, 791344) = 0;
	*getMemU32Ptr(0x5D4594, 791364) = 1;
	*getMemU32Ptr(0x5D4594, 791356) = 0;
	*getMemU32Ptr(0x5D4594, 791376) = 1;
	*getMemU32Ptr(0x5D4594, 791368) = 0;
	sub_4302A0_process_events(1, 1);
}

//----- (00430190) --------------------------------------------------------
int sub_430190() {
	int v1;              // ecx
	unsigned __int8* v2; // eax
	int v4;              // [esp+0h] [ebp-4h]

	sub_47FB10();
	v1 = 0;
	v2 = getMemAt(0x5D4594, 789278);
	do {
		*(v2 - 2) = v1;
		*v2 = 0;
		*(_DWORD*)(v2 + 2) = 0;
		*(v2 - 1) = 1;
		v2 += 8;
		++v1;
	} while (v1 < 256);
	initMouse_sub_47D8D0();
	sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
	sub_47D660(0, (int)&v4);
	sub_47D660(1u, (int)&v4);
	sub_42EBB0(2u, sub_430140, 0, "Input");
	return 1;
}

//----- (00430210) --------------------------------------------------------
void sub_430210() {
	sub_47FCC0();
	*getMemU32Ptr(0x5D4594, 805808) = 0;
}

//----- (00430230) --------------------------------------------------------
void sub_430230() {
	if (nox_mouse.left_state && (nox_mouse_prev.field_6 == 5 || nox_mouse_prev.field_6 == 8)) {
		nox_mouse.field_6 = 8;
	}
	if (nox_mouse.right_state && (nox_mouse_prev.field_9 == 9 || nox_mouse_prev.field_9 == 12)) {
		nox_mouse.field_9 = 12;
	}
	if (nox_mouse.middle_state && (nox_mouse_prev.field_12 == 13 || nox_mouse_prev.field_12 == 16)) {
		nox_mouse.field_12 = 16;
	}
}

//----- (004302A0) --------------------------------------------------------
void __cdecl sub_4302A0_process_events(int evNum, int a2) {
	if (nox_mouse_prev_seq_2 != nox_mouse_prev_seq) {
		nox_mouse.field_6 = 0;
		nox_mouse.field_9 = 0;
		nox_mouse.field_12 = 0;
		nox_mouse.z = 0;
		nox_mouse_prev_seq_2 = nox_mouse_prev_seq;
	}
	int num = 0;
	if (obj_5D4594_754104_switch != 1) {
		num = evNum;
		if (!evNum)
			sub_430230();
	}
	int x = 0;
	int y = 0;
	if (num <= 0) {
		y = nox_mouse.pos.y;
		x = nox_mouse.pos.x;
	} else {
		for (int i = 0; i < num; i++) {
			nox_mouse_state_t* ev = &nox_input_buffer[i];
			sub_430A00_change_mouse_pos(ev->pos.x, ev->pos.y, 0);

			x = nox_mouse.pos.x;
			y = nox_mouse.pos.y;
			nox_mouse.z += ev->z;

			int dx, dy;

			// left mouse button
			if (ev->left_seq == 0) {
				if (nox_mouse.left_state && (nox_mouse_prev.field_6 == 5 || nox_mouse_prev.field_6 == 8)) {
					nox_mouse.field_6 = 8;
				}
			} else if (nox_mouse.left_state != ev->left_state) {
				if (ev->left_state) {
					if (nox_mouse.field_6 != 7) {
						nox_mouse.field_6 = 5;
						nox_mouse.left_state = 1;
						nox_mouse.left_seq = nox_mouse_prev_seq;
					}
				} else if ((unsigned int)((int)(nox_mouse_prev_seq)-nox_mouse.left_seq) >= 15 ||
						   (dx = nox_mouse.pos.x - nox_mouse_prev_left.x, dy = nox_mouse.pos.y - nox_mouse_prev_left.y,
							dx * dx + dy * dy >= 100)) {
					nox_mouse.field_6 = 6;
					nox_mouse.left_state = 0;
					nox_mouse.left_seq = nox_mouse_prev_seq;
				} else {
					nox_mouse.field_6 = 7;
					nox_mouse.left_state = 0;
					nox_mouse.left_seq = nox_mouse_prev_seq;
				}
			}

			// right mouse button
			if (ev->right_seq == 0) {
				if (nox_mouse.right_state && (nox_mouse_prev.field_9 == 9 || nox_mouse_prev.field_9 == 12)) {
					nox_mouse.field_9 = 12;
				}
			} else if (nox_mouse.right_state != ev->right_state) {
				if (ev->right_state) {
					if (nox_mouse.field_9 != 11) {
						nox_mouse.field_9 = 9;
						nox_mouse.right_state = 1;
						nox_mouse.right_seq = nox_mouse_prev_seq;
					}
				} else if ((unsigned int)((int)(nox_mouse_prev_seq)-nox_mouse.right_seq) >= 15 ||
						   (dx = nox_mouse.pos.x - nox_mouse_prev_right.x,
							dy = nox_mouse.pos.y - nox_mouse_prev_right.y, dx * dx + dy * dy >= 100)) {
					nox_mouse.field_9 = 10;
					nox_mouse.right_state = 0;
					nox_mouse.right_seq = nox_mouse_prev_seq;
				} else {
					nox_mouse.field_9 = 11;
					nox_mouse.right_state = 0;
					nox_mouse.right_seq = nox_mouse_prev_seq;
				}
			}

			// middle mouse button
			if (ev->middle_seq == 0) {
				if (nox_mouse.middle_state && (nox_mouse_prev.field_12 == 13 || nox_mouse_prev.field_12 == 16)) {
					nox_mouse.field_12 = 16;
				}
			} else if (nox_mouse.middle_state != ev->middle_state) {
				if (ev->middle_state) {
					if (nox_mouse.field_12 != 15) {
						nox_mouse.field_12 = 13;
						nox_mouse.middle_state = 1;
						nox_mouse.middle_seq = nox_mouse_prev_seq;
					}
				} else if ((unsigned int)((int)(nox_mouse_prev_seq)-nox_mouse.middle_seq) >= 15 ||
						   (dx = nox_mouse.pos.x - nox_mouse_prev_middle.x,
							dy = nox_mouse.pos.y - nox_mouse_prev_middle.y, dx * dx + dy * dy >= 100)) {
					nox_mouse.field_12 = 14;
					nox_mouse.middle_state = 0;
					nox_mouse.middle_seq = nox_mouse_prev_seq;
				} else {
					nox_mouse.field_12 = 15;
					nox_mouse.middle_state = 0;
					nox_mouse.middle_seq = nox_mouse_prev_seq;
				}
			}
		}
	}
	if (nox_mouse.field_6 == 5) {
		nox_mouse_prev_left.x = x;
		nox_mouse_prev_left.y = y;
	}
	if (nox_mouse.field_9 == 9) {
		nox_mouse_prev_right.x = x;
		nox_mouse_prev_right.y = y;
	}
	if (nox_mouse.field_12 == 13) {
		nox_mouse_prev_middle.x = x;
		nox_mouse_prev_middle.y = y;
	}
	nox_mouse.field_3 = x - nox_mouse_prev.pos.x;
	nox_mouse.field_4 = y - nox_mouse_prev.pos.y;
	if (nox_mouse.field_3 * nox_mouse.field_3 + (y - nox_mouse_prev.pos.y) * (y - nox_mouse_prev.pos.y) >= 4) {
		*getMemU32Ptr(0x5D4594, 805824) = 0;
		*getMemU32Ptr(0x5D4594, 805804) = 0;
	} else {
		++*getMemU32Ptr(0x5D4594, 805824);
		if (*getMemU32Ptr(0x5D4594, 805824) >= 10)
			*getMemU32Ptr(0x5D4594, 805804) = 1;
	}
	if (a2) {
		if (nox_mouse.z <= 0)
			nox_mouse.z = nox_mouse.z >= 0 ? 0 : 20;
		else
			nox_mouse.z = 19;
		nox_mouse_prev = nox_mouse;
	}
}

//----- (004306A0) --------------------------------------------------------
void __cdecl nox_client_readMouseBuffer_4306A0(int a1) {
	if (nox_processing_input)
		return;
	nox_processing_input = 1;
	int v2 = 0;
	while (1) {
		char v4 = sub_47DB20_get_mouse_data(&nox_input_buffer[v2]);
		if (v4 == -1)
			continue;
		v2++;
		if (!v4 || v2 >= nox_input_buffer_cap)
			break;
	}
	int v5 = v2 - 1;
	sub_4302A0_process_events(v5, a1);
	nox_processing_input = 0;
	if (v5) {
		*getMemU32Ptr(0x5D4594, 805816) = nox_mouse_prev_seq;
	}
}

//----- (00430710) --------------------------------------------------------
int sub_430710() {
	unsigned __int8* v0; // esi
	unsigned __int8 v1;  // al
	int v2;              // ebp
	unsigned __int8* v3; // edi
	unsigned __int8* v4; // esi
	unsigned __int8 v5;  // cl
	unsigned __int8 v6;  // dl
	int v7;              // eax
	int v8;              // ecx
	int result;          // eax

	v0 = getMemAt(0x5D4594, 787228);
	do {
		do {
			sub_47FA80((int)v0);
			v1 = *v0;
		} while (*v0 == -1);
		v0 += 8;
	} while (v1);
	v2 = 0;
	if (getMemByte(0x5D4594, 787228)) {
		v3 = getMemAt(0x5D4594, 787228);
		v4 = getMemAt(0x5D4594, 787228);
		do {
			if (*v3 == 15) {
				if (getMemByte(0x5D4594, 789725) == 2 || getMemByte(0x5D4594, 790749) == 2)
					v4[2] = 1;
			} else {
				v3 = v4;
				if (*v4 == 58)
					sub_47F950(0x3Au);
			}
			if (obj_5D4594_754104_switch == 1)
				v4[2] = 1;
			v5 = v4[1];
			v6 = v4[2];
			v4 += 8;
			v7 = *v3;
			v3 = v4;
			v7 *= 8;
			++v2;
			*getMemU8Ptr( 0x5D4594, v7 + 789277) = v5;
			v8 = nox_mouse_prev_seq;
			*getMemU8Ptr( 0x5D4594, v7 + 789278) = v6;
			*getMemU32Ptr(0x5D4594, v7 + 789280) = v8;
		} while (*v4);
	}
	result = sub_4307D0();
	if (result == 1 || v2)
		*getMemU32Ptr(0x5D4594, 805816) = nox_mouse_prev_seq;
	return result;
}

//----- (004307D0) --------------------------------------------------------
int sub_4307D0() {
	int v0;              // edx
	unsigned __int8* v2; // ecx
	unsigned __int8 v3;  // al
	int v4;              // esi
	unsigned __int8* v6; // ecx
	unsigned __int8* v7; // eax

	v0 = 0;
	if (obj_5D4594_754104_switch == 1)
		return 0;
	if (getMemByte(0x5D4594, 787228)) {
		v2 = getMemAt(0x5D4594, 787228);
		do {
			v3 = v2[8];
			v2 += 8;
			++v0;
		} while (v3);
	}
	v4 = nox_mouse_prev_seq;
	int v5 = 0;
	v6 = getMemAt(0x5D4594, 789280);
	while (*(v6 - 3) != 2 || (unsigned int)(nox_mouse_prev_seq - *(_DWORD*)v6) <= 0xA) {
		v6 += 8;
		++v5;
		if (v5 >= 256)
			return 0;
	}
	*getMemU8Ptr( 0x5D4594, 8 * v0 + 787228) = v5;
	*getMemU8Ptr( 0x5D4594, 8 * v0 + 787229) = 2;
	*getMemU8Ptr( 0x5D4594, 8 * v0 + 787230) = 0;
	*getMemU8Ptr( 0x5D4594, 8 * v0 + 787236) = 0;
	int v8 = 0;
	v7 = getMemAt(0x5D4594, 789280);
	do {
		*(_DWORD*)v7 = v4;
		v7 += 8;
		++v8;
	} while (v8 < 256);
	*getMemU32Ptr(0x5D4594, 8 * v5 + 789280) = v4 - 12;
	return 1;
}

//----- (00430880) --------------------------------------------------------
int __cdecl sub_430880(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 805808) = a1;
	return result;
}

//----- (00430890) --------------------------------------------------------
int sub_430890() { return *getMemU32Ptr(0x5D4594, 805808); }

//----- (004308A0) --------------------------------------------------------
int __cdecl nox_client_processMouseInput_4308A0(int a1) {
	int v2; // ecx

	nox_client_readMouseBuffer_4306A0(a1);
	sub_430710();
	if (getMemByte(0x5D4594, 787228)) {
		v2 = *getMemU32Ptr(0x5D4594, 787228) >> 8;
		if (!BYTE1(v2))
			OnLibraryNotice(417, *getMemU32Ptr(0x5D4594, 787228));
	}
	++nox_mouse_prev_seq;
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) &&
		(unsigned int)(nox_mouse_prev_seq - *getMemU32Ptr(0x5D4594, 805816)) > 0xA8C) {
		if (!nox_common_gameFlags_check_40A5C0(1)) {
			sub_440950(0, (wchar_t*)getMemAt(0x587000, 80784));
			return 1;
		}
		if (*getMemU32Ptr(0x5D4594, 2618908))
			sub_443E90(*getMemIntPtr(0x5D4594, 2618908), 0, (wchar_t*)getMemAt(0x587000, 80792));
	}
	return 1;
}

//----- (00430940) --------------------------------------------------------
char* sub_430940() { return (char*)getMemAt(0x5D4594, 787228); }

//----- (00430950) --------------------------------------------------------
unsigned __int8 __cdecl sub_430950(unsigned __int8 a1) { return getMemByte(0x5D4594, 8 * a1 + 789278); }

//----- (00430970) --------------------------------------------------------
unsigned __int8 __cdecl sub_430970(unsigned __int8 a1) { return getMemByte(0x5D4594, 8 * a1 + 789277); }

//----- (00430990) --------------------------------------------------------
int __cdecl sub_430990(unsigned __int8 a1) { return *getMemU32Ptr(0x5D4594, 8 * a1 + 789280); }

//----- (004309B0) --------------------------------------------------------
int __cdecl sub_4309B0(unsigned __int8 a1, char a2) {
	int result; // eax

	result = a1;
	*getMemU8Ptr( 0x5D4594, 8 * a1 + 789278) = a2;
	return result;
}

//----- (004309D0) --------------------------------------------------------
int __cdecl sub_4309D0(unsigned __int8 a1, char a2) {
	int result; // eax

	result = a1;
	*getMemU8Ptr( 0x5D4594, 8 * a1 + 789277) = a2;
	return result;
}

//----- (004309F0) --------------------------------------------------------
int2* __cdecl nox_client_getMousePos_4309F0() { return &nox_mouse.pos; }

//----- (00430A00) --------------------------------------------------------
void __cdecl sub_430A00_change_mouse_pos(int x, int y, int isAbs) {
	mouse_pos_t p;
	p.x = x;
	p.y = y;

	if (!isAbs) {
		p.x += nox_mouse.pos.x;
		p.y += nox_mouse.pos.y;
	}

	if (p.x > nox_mouse_max.x)
		p.x = nox_mouse_max.x;

	if (p.x < nox_mouse_min.x)
		p.x = nox_mouse_min.x;

	if (p.y > nox_mouse_max.y)
		p.y = nox_mouse_max.y;

	if (p.y < nox_mouse_min.y)
		p.y = nox_mouse_min.y;

	nox_mouse.pos = p;
}

//----- (00430A70) --------------------------------------------------------
int __cdecl sub_430A70_set_mouse_bounds(int x_min, int x_max, int y_min, int y_max) {
	nox_mouse_min.x = x_min;
	nox_mouse_min.y = y_min;
	nox_mouse_max.x = x_max;
	nox_mouse_max.y = y_max;
	return y_max;
}

//----- (00430AA0) --------------------------------------------------------
int __cdecl sub_430AA0(int a1) {
	int result; // eax

	result = a1 - 1;
	if (a1 == 1) {
		dword_5d4594_805820 = 1;
		dword_587000_80772 = 9;
	} else {
		result = a1 - 2;
		if (a1 == 2) {
			dword_5d4594_805820 = 2;
			dword_587000_80772 = 13;
		} else {
			dword_5d4594_805820 = 0;
			dword_587000_80772 = 5;
		}
	}
	return result;
}

//----- (00430AF0) --------------------------------------------------------
int sub_430AF0() { return dword_5d4594_805820; }

//----- (00430B00) --------------------------------------------------------
int sub_430B00() { return dword_587000_80772; }

//----- (00430B10) --------------------------------------------------------
void __cdecl sub_430B10_set_mouse_pos(int x, int y) { sub_430A00_change_mouse_pos(x, y, 1); }

//----- (00430B30) --------------------------------------------------------
int sub_430B30() { return *getMemU32Ptr(0x5D4594, 805804); }

//----- (00430B40) --------------------------------------------------------
int sub_430B40_get_mouse_prev_seq() { return nox_mouse_prev_seq; }

//----- (00430B50) --------------------------------------------------------
int __cdecl sub_430B50(int a1, int a2, int a3, int a4) {
	int result; // eax

	dword_5d4594_3807140 = a1;
	result = a4;
	dword_5d4594_3807136 = a2;
	dword_5d4594_3807116 = a3;
	dword_5d4594_3807152 = a4;
	return result;
}

//----- (00430B80) --------------------------------------------------------
char* __cdecl sub_430B80(_DWORD* a1) {
	*a1 = dword_5d4594_3804684;
	return (char*)getMemAt(0x5D4594, 3805516);
}

//----- (00430BB0) --------------------------------------------------------
void __cdecl sub_430BB0(_DWORD* a1, _DWORD* a2, _DWORD* a3) {
	*a1 = nox_backbuffer_width;
	*a2 = nox_backbuffer_height;
	*a3 = dword_5d4594_3801780 != 0 ? 16 : 8;
}

//----- (00430BE0) --------------------------------------------------------
BOOL __cdecl nox_video_resizewnd(int a1, int a2, int a3) {
	BOOL result; // eax

	printf("New size: %d, %d\n", a1, a2);

	nox_win_width = a1;
	if (a1 > nox_max_width)
		nox_win_width = nox_max_width;
	nox_win_height = a2;
	if (a2 > nox_max_height)
		nox_win_height = nox_max_height;
	a3 = 16;
	result = a3 != 8;
	dword_5d4594_3804680 = a3 != 8;
	return result;
}

//----- (00430C30) --------------------------------------------------------
void __cdecl sub_430C30_set_video_max(int w, int h) {
	nox_max_width = w;
	nox_max_height = h;
}

//----- (00430C50) --------------------------------------------------------
void __cdecl sub_430C50_get_video_max(int* w, int* h) {
	*w = nox_max_width;
	*h = nox_max_height;
}

//----- (00430D40) --------------------------------------------------------
BOOL sub_430D40() {
	BOOL result; // eax

	if (*getMemU32Ptr(0x5D4594, 805840))
		result = 0;
	else
		result = sub_444D90();
	return result;
}

//----- (00430DB0) --------------------------------------------------------
int __cdecl sub_430DB0(int a1, int a2) {
	size_t v2; // edi
	char* v3;  // eax

	dword_5d4594_3798812 = a1 / 46 + 4;
	dword_5d4594_3798820 = 0;
	dword_5d4594_3798824 = 0;
	dword_5d4594_3798800 = 46 * dword_5d4594_3798812;
	dword_5d4594_3798816 = a2 / 46 + 3;
	dword_5d4594_3798828 = 0;
	dword_5d4594_3798832 = 0;
	dword_5d4594_3798808 = 46 * dword_5d4594_3798816;
	v2 = ((46 * dword_5d4594_3798812) << getMemByte(0x5D4594, 3807124)) * 46 * dword_5d4594_3798816;
	dword_5d4594_3798804 = (46 * dword_5d4594_3798812) << getMemByte(0x5D4594, 3807124);
	dword_5d4594_3798836 = 0;
	dword_5d4594_3798840 = 0;
	v3 = (char*)malloc(v2);
	dword_5d4594_3798796 = v3;
	if (!v3)
		return 0;
	dword_5d4594_3798844 = &v3[v2];
	return 1;
}

//----- (00430E70) --------------------------------------------------------
int sub_430E70() {
	int result; // eax

	result = dword_587000_80800;
	if (dword_587000_80800) {
		result = dword_5d4594_805836;
		if (dword_5d4594_805836) {
			dword_5d4594_805836 = 0;
			dword_5d4594_3805484 = sub_480BE0;
			dword_5d4594_3805492 = sub_480860;
		} else {
			dword_5d4594_805836 = 1;
			dword_5d4594_3805484 = sub_480950;
			dword_5d4594_3805492 = sub_4805A0;
		}
	}
	return result;
}

//----- (00430EC0) --------------------------------------------------------
int nox_video_freeFloorBuffer_430EC0() {
	if (dword_5d4594_3798796) {
		free(*(LPVOID*)&dword_5d4594_3798796);
		dword_5d4594_3798796 = 0;
	}
	sub_444C50();
	return 1;
}

//----- (00430EF0) --------------------------------------------------------
void sub_430EF0() { nox_video_freeFloorBuffer_430EC0(); }

//----- (00430F00) --------------------------------------------------------
int screenshot_num = 0;

//----- (004310B0) --------------------------------------------------------
int __cdecl nox_audio_initall(int a3) {
	if (!nox_enable_audio)
		return 1;
	int v1; // esi
	int v2; // esi
	int v3; // esi

	if (a3) {
		sub_486F30();
		if (sub_4311F0()) {
			dword_587000_81128 = dword_5d4594_805984 + 88;
			dword_5d4594_805980 = sub_4866F0("audio", "audio");
		}
	}
	sub_4864A0(getMemAt(0x5D4594, 805884));
	sub_4864A0(*(_DWORD**)&dword_587000_93164);
	sub_4864A0(*(_DWORD**)&dword_587000_122852);
	sub_4864A0(*(_DWORD**)&dword_587000_127004);
	sub_44D810();
	sub_43D8E0();
	sub_451850(*(int*)&dword_5d4594_805984, *(int*)&dword_5d4594_805980);
	v1 = sub_4866A0(2);
	if (!v1)
		sub_43DC00();
	sub_486320(*(_DWORD**)&dword_587000_93164, v1);
	v2 = sub_4866A0(1);
	if (!v2)
		sub_44D960();
	sub_486320(*(_DWORD**)&dword_587000_122852, v2);
	v3 = sub_4866A0(0);
	if (!v3)
		sub_453050();
	sub_486320(*(_DWORD**)&dword_587000_127004, v3);
	return 1;
}

//----- (004311B0) --------------------------------------------------------
void sub_4311B0() {
	sub_43DCC0();
	sub_4312B0();
	sub_43D970();
	sub_44D8C0();
	sub_451970();
	if (dword_5d4594_805980)
		sub_4869C0(*(LPVOID*)&dword_5d4594_805980);
	dword_587000_81128 = 0;
	sub_431270();
	if (dword_5d4594_1193336) {
		sub_4875F0();
		sub_4870A0();
		dword_5d4594_1193336 = 0;
	}
}

//----- (004311F0) --------------------------------------------------------
BOOL sub_4311F0() {
	_DWORD* v0; // eax
	int v2[7];  // [esp+0h] [ebp-1Ch]

	sub_486FA0(*getMemIntPtr(0x587000, 94032));
	nullsub_10(v2);
	v2[2] = 22050;
	v2[1] = 0;
	v2[3] = 2;
	v2[4] = 2;
	v2[0] = 4;
	sub_487D00(v2);
	v0 = sub_487150(-1, v2);
	dword_5d4594_805984 = v0;
	return v0 && sub_487790((int)v0, 16) == 16;
}
// 487CF0: using guessed type void __cdecl nullsub_10(_DWORD);

//----- (00431270) --------------------------------------------------------
void sub_431270() {
	if (dword_5d4594_805984) {
		sub_487680(*(LPVOID*)&dword_5d4594_805984);
		dword_5d4594_805984 = 0;
	}
}

//----- (00431290) --------------------------------------------------------
int* sub_431290() {
	int* result; // eax

	result = *(int**)&dword_5d4594_805984;
	if (dword_5d4594_805984)
		result = sub_487970(*(int*)&dword_5d4594_805984, -1);
	return result;
}

//----- (004312B0) --------------------------------------------------------
void sub_4312B0() {
	sub_431290();
	sub_44D8F0();
	sub_43D990();
}

//----- (004312C0) --------------------------------------------------------
int sub_4312C0() {
	int result;      // eax
	__int64 v1;      // rax
	__int64 v2;      // kr00_8
	unsigned int v3; // ecx

	result = dword_5d4594_805988;
	if (!dword_5d4594_805988) {
		dword_5d4594_805988 = 1;
		v1 = sub_416BB0();
		v2 = v1;
		v3 = (unsigned __int64)(v1 - *getMemU64Ptr(0x5D4594, 805996)) >> 32;
		result = v1 - *getMemU32Ptr(0x5D4594, 805996);
		if (__PAIR64__(v3, result) > 0x21) {
			sub_44D3A0();
			result = sub_43D440();
			*getMemU64Ptr(0x5D4594, 805996) = v2;
		}
		dword_5d4594_805988 = 0;
	}
	return result;
}

//----- (00431330) --------------------------------------------------------
BOOL sub_431330() { return dword_5d4594_805984 != 0; }

//----- (00431340) --------------------------------------------------------
int sub_431340() { return 1; }

//----- (00431370) --------------------------------------------------------
BOOL sub_431370() { return sub_488B60() != 0; }

//----- (00431380) --------------------------------------------------------
void sub_431380() {
	sub_488BA0();
	sub_4896E0();
}

//----- (00431390) --------------------------------------------------------
int nox_client_initScreenParticles_431390() {
	if (!nox_alloc_screenParticles_806044) {
		nox_alloc_screenParticles_806044 = nox_new_alloc_class("ScreenParticles", sizeof(nox_screenParticle), 2000);
		if (!nox_alloc_screenParticles_806044) {
			return 0;
		}
	}
	sub_4144D0(nox_alloc_screenParticles_806044);
	nox_screenParticles_head = 0;
	dword_5d4594_806052 = 0;
	sub_4313E0();
	return 1;
}

//----- (004313E0) --------------------------------------------------------
int sub_4313E0() {
	int result; // eax

	*getMemU32Ptr(0x5D4594, 806012) = nox_color_rgb_4344A0(255, 255, 200);
	*getMemU32Ptr(0x5D4594, 806004) = nox_color_rgb_4344A0(50, 150, 255);
	*getMemU32Ptr(0x5D4594, 806036) = nox_color_rgb_4344A0(200, 255, 255);
	*getMemU32Ptr(0x5D4594, 806024) = nox_color_rgb_4344A0(255, 200, 100);
	*getMemU32Ptr(0x5D4594, 806040) = nox_color_rgb_4344A0(200, 255, 200);
	*getMemU32Ptr(0x5D4594, 806020) = nox_color_rgb_4344A0(255, 255, 0);
	*getMemU32Ptr(0x5D4594, 806028) = nox_color_rgb_4344A0(0, 0, 255);
	*getMemU32Ptr(0x5D4594, 806016) = nox_color_rgb_4344A0(128, 128, 255);
	*getMemU32Ptr(0x5D4594, 806008) = nox_color_rgb_4344A0(255, 128, 64);
	result = nox_color_rgb_4344A0(0, 255, 0);
	*getMemU32Ptr(0x5D4594, 806032) = result;
	return result;
}

//----- (004314D0) --------------------------------------------------------
void sub_4314D0() {
	if (nox_alloc_screenParticles_806044)
		nox_free_alloc_class(*(LPVOID*)&nox_alloc_screenParticles_806044);
	nox_alloc_screenParticles_806044 = 0;
	nox_screenParticles_head = 0;
	dword_5d4594_806052 = 0;
}

//----- (00431510) --------------------------------------------------------
int sub_431510() {
	if (nox_alloc_screenParticles_806044)
		sub_4144D0(*(_DWORD**)&nox_alloc_screenParticles_806044);
	nox_screenParticles_head = 0;
	dword_5d4594_806052 = 0;
	return sub_4313E0();
}

//----- (00431540) --------------------------------------------------------
nox_screenParticle* nox_client_newScreenParticle_431540(int a1, int a2, int a3, int a4, int a5, int a6, char a7, char a8, char a9, char a10) {
	int v10;     // edi
	int v11;     // ebx

	if (!nox_alloc_screenParticles_806044)
		return 0;
	switch (a1) {
	case 0:
		v10 = *getMemU32Ptr(0x5D4594, 806016);
		v11 = *getMemU32Ptr(0x5D4594, 806036);
		break;
	case 1:
		v10 = *getMemU32Ptr(0x5D4594, 806028);
		v11 = *getMemU32Ptr(0x5D4594, 806004);
		break;
	case 2:
		v10 = *getMemU32Ptr(0x5D4594, 806032);
		v11 = *getMemU32Ptr(0x5D4594, 806040);
		break;
	case 3:
		v10 = *getMemU32Ptr(0x5D4594, 806020);
		v11 = *getMemU32Ptr(0x5D4594, 806012);
		break;
	case 4:
		v10 = *getMemU32Ptr(0x5D4594, 806008);
		v11 = *getMemU32Ptr(0x5D4594, 806024);
		break;
	default:
		return 0;
	}
	nox_screenParticle* p = nox_alloc_class_new_obj_zero(nox_alloc_screenParticles_806044);
	if (!p) {
		p = dword_5d4594_806052;
		if (!p)
			return 0;
		sub_4316C0(p);
	}
	p->field_24 = a2 << 16;
	p->field_28 = a3 << 16;
	p->field_40[0] = a7;
	p->field_40[1] = a8;
	p->field_40[2] = a9;
	p->field_40[3] = a8;
	p->draw_fnc = nox_client_screenParticleDraw_489700;
	p->field_16 = a4 << 16;
	p->field_20 = a5 << 16;
	p->field_36 = a6 << 16;
	*(_BYTE*)(&p->field_32) = a10;
	p->field_4 = a1;
	p->field_8 = v10;
	p->field_12 = v11;
	nox_client_addScreenParticle_431680(p);
	if (!p->field_36 && !p->field_40[1]) {
		p->field_40[1] = 3;
		p->field_40[2] = 2;
		p->field_40[3] = 3;
	}
	return p;
}

//----- (00431680) --------------------------------------------------------
void nox_client_addScreenParticle_431680(nox_screenParticle* p) {
	p->field_44 = nox_screenParticles_head;
	p->field_48 = 0;
	if (nox_screenParticles_head)
		nox_screenParticles_head->field_48 = p;
	else
		dword_5d4594_806052 = p;
	nox_screenParticles_head = p;
}

//----- (004316C0) --------------------------------------------------------
void sub_4316C0(nox_screenParticle* p) {
	if (p == dword_5d4594_806052)
		dword_5d4594_806052 = p->field_48;

	nox_screenParticle* v2 = p->field_44;
	if (v2)
		v2->field_48 = p->field_48;

	nox_screenParticle* v3 = p->field_48;
	if (v3) {
		v3->field_44 = p->field_44;
	} else {
		nox_screenParticles_head = p->field_44;
	}
}

//----- (00431700) --------------------------------------------------------
void __cdecl sub_431700(_QWORD* a1) {
	sub_4316C0((int)a1);
	sub_414330(*(unsigned int**)&nox_alloc_screenParticles_806044, a1);
}

//----- (00431720) --------------------------------------------------------
void __cdecl nox_client_screenParticlesDraw_431720(int* a1) {
	if (!a1) {
		return;
	}

	sub_430B50(a1[0], a1[1], a1[2], a1[3]);
	nox_screenParticle* p2 = 0;
	for (nox_screenParticle* p = nox_screenParticles_head; p; p = p2) {
		dword_5d4594_3799524 = 1;
		p2 = p->field_44; // getting it after the callback may fail
		p->draw_fnc(a1, p);
	}
}

//----- (00431770) --------------------------------------------------------
char* sub_431770() { return (char*)getMemAt(0x5D4594, 807172); }

//----- (00431780) --------------------------------------------------------
char* sub_431780() { return (char*)getMemAt(0x5D4594, 806060); }

//----- (00431790) --------------------------------------------------------
char* __cdecl sub_431790(char* a1) {
	char* result; // eax

	result = a1;
	if (a1)
		result = strncpy((char*)getMemAt(0x5D4594, 806060), a1, 0x17u);
	return result;
}

//----- (004317B0) --------------------------------------------------------
int nox_common_readcfgfile(const char* path, int a2) {
	sub_42CD90();
	FILE* file = fopen(path, "r");
	if (file) {
		if (a2 || nox_common_parsecfg_all(file)) {
			if (sub_4331E0(file, a2)) {
				fclose(file);
				return 1;
			}
		}
		fclose(file);
		file = 0;
	}
	sub_42CD90();
	file = fopen("default.cfg", "r");
	if (!file) {
		return 0;
	}
	if (!(a2 || nox_common_parsecfg_all(file))) {
		fclose(file);
		return 0;
	}
	if (!sub_4331E0(file, a2)) {
		fclose(file);
		return 0;
	}
	fclose(file);
	nox_common_writecfgfile("nox.cfg");
	return 1;
}

//----- (00431890) --------------------------------------------------------
int nox_common_parsecfg_all(FILE* a1) {
	char* v1;            // eax
	char* v2;            // eax
	const char* v3;      // edi
	int v4;              // edx
	unsigned __int8* v5; // ebp

	sub_486670(0x4000, 0);
	sub_486670(0x4000, 1);
	sub_486670(0x4000, 2);
LABEL_2:
	while (fgets((char*)getMemAt(0x5D4594, 806084), 1024, a1)) {
		if (getMemByte(0x5D4594, 806084) == '#') {
			continue;
		}
		v1 = strtok((char*)getMemAt(0x5D4594, 806084), " \r\t\n");
		if (!v1) {
			continue;
		}
		if (!strcmp(v1, "---"))
			return 1;
		if (!strcmp(v1, "Version")) {
			v2 = (char*)sub_432AD0(getMemIntPtr(0x587000, 81284));
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "VideoMode")) {
			v2 = (char*)nox_common_parsecfg_videomode();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "VideoSize")) {
			v2 = (char*)nox_common_parsecfg_videosize();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "Gamma")) {
			v2 = (char*)sub_432C00();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "FXVolume")) {
			v2 = (char*)sub_432CB0(0);
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "DialogVolume")) {
			v2 = (char*)sub_432CB0(1);
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "MusicVolume")) {
			v2 = (char*)sub_432CB0(2);
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "LastServer")) {
			v2 = (char*)sub_431FC0();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "ServerName")) {
			v2 = (char*)sub_432010();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "UnlockSurface")) {
			v2 = (char*)sub_4320B0();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "SoftShadowEdge")) {
			v2 = (char*)sub_432100();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "DrawFrontWalls")) {
			v2 = (char*)sub_432150();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "TranslucentFrontWalls")) {
			v2 = (char*)sub_4321A0();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "HighResFrontWalls")) {
			v2 = (char*)sub_4321F0();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "HighResFloors")) {
			v2 = (char*)sub_432240();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "LockHighResFloors")) {
			v2 = (char*)sub_432290();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "TexturedFloors")) {
			v2 = (char*)sub_4322E0();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "TranslucentConsole")) {
			v2 = (char*)sub_432340();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "RenderGlow")) {
			v2 = (char*)sub_432390();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "RenderGUI")) {
			v2 = (char*)sub_4323E0();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "FadeObjects")) {
			v2 = (char*)sub_432430();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "TrackData")) {
			v2 = (char*)sub_433190();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "RenderBubbles")) {
			v2 = (char*)sub_432480();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "SysopPassword")) {
			v2 = (char*)sub_4324D0();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "ServerPassword")) {
			v2 = (char*)sub_432520();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "Profiled")) {
			v2 = (char*)sub_432590();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "SanctuaryHelp")) {
			v2 = (char*)sub_432620();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "MaxPacketLossPct")) {
			v2 = (char*)sub_4325D0();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "SendMessageOfTheDay")) {
			v2 = (char*)sub_432A90();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "InternetUpdateRate")) {
			v2 = (char*)sub_432DF0();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "ConnectionType")) {
			v2 = (char*)sub_433050();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "MapCycle")) {
			v2 = (char*)sub_432C30();
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "LANFilters")) {
			v2 = sub_432E50(0);
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "INETFilters")) {
			v2 = sub_432E50(1);
			if (!v2)
				return 0;
		} else if (!strcmp(v1, "LessonLimit")) {
			if (!sub_432D10())
				return 0;
		} else if (!strcmp(v1, "TimeLimit")) {
			if (!sub_432D80())
				return 0;
		} else if (!strcmp(v1, "PlayerSkeletons")) {
			if (!sub_4327C0())
				return 0;
		} else if (!strcmp(v1, "BroadcastGestures")) {
			if (!sub_432810())
				return 0;
		} else if (!strcmp(v1, "LatencyCompensation")) {
			if (!sub_432970())
				return 0;
		} else if (!strcmp(v1, "Closed")) {
			if (!sub_432860())
				return 0;
		} else if (!strcmp(v1, "Private")) {
			if (!sub_4328C0())
				return 0;
		} else if (!strcmp(v1, "AudioThreshold")) {
			if (!sub_433130())
				return 0;
		} else if (!strcmp(v1, "MaxPlayers")) {
			if (!sub_4330C0())
				return 0;
		} else if (!strcmp(v1, "RestrictedClasses")) {
			if (!sub_432920())
				return 0;
		} else if (!strcmp(v1, "RestrictedPing")) {
			if (!sub_4329D0())
				return 0;
		} else if (!strcmp(v1, "LimitMaxRes")) {
			if (!sub_432A30())
				return 0;
		} else if (!strcmp(v1, "ItemRespawn")) {
			if (!sub_432660())
				return 0;
		} else if (!strcmp(v1, "CamperAlarm")) {
			if (!sub_4326B0())
				return 0;
		} else if (!strcmp(v1, "MinKickVotes")) {
			if (!sub_432700())
				return 0;
		} else if (!strcmp(v1, "ResetQuestMinVotes")) {
			if (!sub_432740())
				return 0;
		} else if (!strcmp(v1, "KickQuestPlayerMinVotes")) {
			if (!sub_432780())
				return 0;
		} else if (!strcmp(v1, "Fullscreen")) {
			const char* token;
			strtok(NULL, " \r\t\n");
			token = strtok(NULL, " \r\t\n");
			if (token) {
				g_fullscreen_cfg = atoi(token);
				if (g_fullscreen <= -4) {
					g_fullscreen = g_fullscreen_cfg;
				}
			}

			change_windowed_fullscreen();
		} else if (!strcmp(v1, "Gamma2")) {
			const char* token;
			strtok(NULL, " \r\t\n");
			token = strtok(NULL, " \r\t\n");
			if (token)
				draw_gamma = atof(token);
		} else if (!strcmp(v1, "Stretched")) {
			const char* token;
			strtok(NULL, " \r\t\n");
			token = strtok(NULL, " \r\t\n");
			if (token) {
				g_scaled_cfg = atoi(token);
				if (g_scaled >= 0) {
					g_scaled = g_scaled_cfg;
				}
			}
		} else if (!strcmp(v1, "InputSensitivity")) {
			const char* token;
			strtok(NULL, " \r\t\n");
			token = strtok(NULL, " \r\t\n");
			if (token)
				input_sensitivity = atof(token);
		} else {
			v3 = *(const char**)getMemAt(0x587000, 81168);
			v4 = 0;
			if (*getMemU32Ptr(0x587000, 81168)) {
				v5 = getMemAt(0x587000, 81168);
				while (strcmp(v1, v3)) {
					v3 = (const char*)*((_DWORD*)v5 + 2);
					v5 += 8;
					++v4;
					if (!v3)
						goto LABEL_2;
				}
				v2 = (char*)sub_432C70(*getMemU32Ptr(0x587000, 8 * v4 + 81172));
				if (!v2)
					return 0;
			}
		}
	}
	return 0;
}

//----- (00431FC0) --------------------------------------------------------
int sub_431FC0() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0)
		strncpy((char*)getMemAt(0x5D4594, 806060), v0, 0x16u);
	else
		*getMemU8Ptr(0x5D4594, 806060) = getMemByte(0x5D4594, 807272);
	return 1;
}

//----- (00432010) --------------------------------------------------------
int sub_432010() {
	char* v0;       // eax
	const char* v1; // esi
	int result;     // eax
	char* v3;       // eax
	char v4;        // cl
	char v5[64];    // [esp+4h] [ebp-40h]

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	v1 = v0;
	if (v0) {
		if (*getMemU32Ptr(0x587000, 81284) == 0x10000 && !_strcmpi(v0, "NoxWorld"))
			v1 = "User_Game";
		strncpy(v5, v1, 0x3Fu);
		v3 = v5;
		if (v5[0]) {
			do {
				if (*v3 == 95)
					*v3 = 32;
				v4 = *++v3;
			} while (v4);
		}
		sub_40A440(v5);
		result = 1;
	} else {
		sub_40A440(0);
		result = 1;
	}
	return result;
}

//----- (004320B0) --------------------------------------------------------
int sub_4320B0() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = atoi(v0);
	nox_video_dxUnlockSurface = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2)
		nox_video_dxUnlockSurface = 1;
	return result;
}

//----- (00432100) --------------------------------------------------------
int sub_432100() {
	char* v0; // eax
	bool v1;  // zf

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = atoi(v0) == 0;
		if (!v1) {
			nox_common_setEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
			return 1;
		}
		nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
	}
	return 1;
}

//----- (00432150) --------------------------------------------------------
int sub_432150() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = atoi(v0);
	nox_client_drawFrontWalls_80812 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2)
		nox_client_drawFrontWalls_80812 = 1;
	return result;
}

//----- (004321A0) --------------------------------------------------------
int sub_4321A0() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = atoi(v0);
	nox_client_translucentFrontWalls_805844 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2)
		nox_client_translucentFrontWalls_805844 = 1;
	return result;
}

//----- (004321F0) --------------------------------------------------------
int sub_4321F0() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = atoi(v0);
	nox_client_highResFrontWalls_80820 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2)
		nox_client_highResFrontWalls_80820 = 1;
	return result;
}

//----- (00432240) --------------------------------------------------------
int sub_432240() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = atoi(v0);
	nox_client_highResFloors_154952 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2)
		nox_client_highResFloors_154952 = 1;
	return result;
}

//----- (00432290) --------------------------------------------------------
int sub_432290() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = atoi(v0);
	nox_client_lockHighResFloors_1193152 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2)
		nox_client_lockHighResFloors_1193152 = 1;
	return result;
}

//----- (004322E0) --------------------------------------------------------
int sub_4322E0() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		nox_client_texturedFloors_154956 = atoi(v0);
		nox_client_texturedFloors_154956 = nox_client_texturedFloors_154956 != 0;
		sub_481420();
		dword_5d4594_1193156 = 0;
		dword_587000_154960 = nox_client_texturedFloors_154956;
	}
	return 1;
}

//----- (00432340) --------------------------------------------------------
int sub_432340() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = atoi(v0);
	nox_client_translucentConsole_80824 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2)
		nox_client_translucentConsole_80824 = 1;
	return result;
}

//----- (00432390) --------------------------------------------------------
int sub_432390() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = atoi(v0);
	nox_client_renderGlow_805852 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2)
		nox_client_renderGlow_805852 = 1;
	return result;
}

//----- (004323E0) --------------------------------------------------------
int sub_4323E0() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = atoi(v0);
	nox_client_renderGUI_80828 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2)
		nox_client_renderGUI_80828 = 1;
	return result;
}

//----- (00432430) --------------------------------------------------------
int sub_432430() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = atoi(v0);
	nox_client_fadeObjects_80836 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2)
		nox_client_fadeObjects_80836 = 1;
	return result;
}

//----- (00432480) --------------------------------------------------------
int sub_432480() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = atoi(v0);
	nox_client_renderBubbles_80844 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2)
		nox_client_renderBubbles_80844 = 1;
	return result;
}

//----- (004324D0) --------------------------------------------------------
int sub_4324D0() {
	char* v0;        // eax
	wchar_t v2[100]; // [esp+0h] [ebp-C8h]

	strtok(0, " \r\t\n");
	v0 = strtok(0, "\r\t\n");
	if (v0) {
		nox_swprintf(v2, L"%S", v0);
		sub_40A610(v2);
	}
	return 1;
}

//----- (00432520) --------------------------------------------------------
int sub_432520() {
	char* v0;        // esi
	char* v1;        // eax
	wchar_t v3[100]; // [esp+4h] [ebp-C8h]

	v0 = sub_416640();
	strtok(0, " \r\t\n");
	v1 = strtok(0, "\r\t\n");
	if (v1) {
		nox_swprintf(v3, L"%S", v1);
		nox_wcsncpy((wchar_t*)v0 + 39, v3, 8u);
		*((_WORD*)v0 + 47) = 0;
	}
	return 1;
}

//----- (00432590) --------------------------------------------------------
int sub_432590() {
#ifdef __EMSCRIPTEN__
	nox_profiled_805856 = 1;
	return 1;
#endif
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0)
		nox_profiled_805856 = atoi(v0) != 0;
	return 1;
}

//----- (004325D0) --------------------------------------------------------
int sub_4325D0() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		*getMemU32Ptr(0x587000, 81280) = atoi(v0);
		*getMemU32Ptr(0x587000, 292940) = (__int64)((double)*getMemIntPtr(0x587000, 81280) * 0.0099999998 * 10.0);
	}
	return 1;
}

//----- (00432620) --------------------------------------------------------
int sub_432620() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0)
		nox_server_sanctuaryHelp_54276 = atoi(v0) != 0;
	return 1;
}

//----- (00432660) --------------------------------------------------------
int sub_432660() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		if (atoi(v0)) {
			sub_409E70(2);
			return 1;
		}
		sub_409EC0(2);
	}
	return 1;
}

//----- (004326B0) --------------------------------------------------------
int sub_4326B0() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		if (atoi(v0)) {
			sub_409E70(0x2000);
			return 1;
		}
		sub_409EC0(0x2000);
	}
	return 1;
}

//----- (00432700) --------------------------------------------------------
int sub_432700() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0)
		*getMemU32Ptr(0x587000, 229980) = atoi(v0);
	return 1;
}

//----- (00432740) --------------------------------------------------------
int sub_432740() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0)
		nox_server_resetQuestMinVotes_229988 = atoi(v0);
	return 1;
}

//----- (00432780) --------------------------------------------------------
int sub_432780() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0)
		nox_server_kickQuestPlayerMinVotes_229992 = atoi(v0);
	return 1;
}

//----- (004327C0) --------------------------------------------------------
int sub_4327C0() {
	char* v0; // esi
	char* v1; // edi

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		*(_DWORD*)(v1 + 58) = atoi(v0) > 0;
	}
	return 1;
}

//----- (00432810) --------------------------------------------------------
int sub_432810() {
	char* v0; // esi
	char* v1; // edi

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		*(_DWORD*)(v1 + 62) = atoi(v0) > 0;
	}
	return 1;
}

//----- (00432860) --------------------------------------------------------
int sub_432860() {
	char* v0; // edi
	char* v1; // esi
	bool v2;  // cc
	char v3;  // al

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		v2 = atoi(v0) <= 0;
		v3 = v1[100];
		if (!v2) {
			v1[100] = v3 | 0x10;
			return 1;
		}
		v1[100] = v3 & 0xEF;
	}
	return 1;
}

//----- (004328C0) --------------------------------------------------------
int sub_4328C0() {
	char* v0; // edi
	char* v1; // esi
	bool v2;  // cc
	char v3;  // al

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		v2 = atoi(v0) <= 0;
		v3 = v1[100];
		if (!v2) {
			v1[100] = v3 | 0x20;
			return 1;
		}
		v1[100] = v3 & 0xDF;
	}
	return 1;
}

//----- (00432920) --------------------------------------------------------
int sub_432920() {
	char* v0; // edi
	char* v1; // esi

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		v1[100] |= atoi(v0) & 7;
	}
	return 1;
}

//----- (00432970) --------------------------------------------------------
int sub_432970() {
	char* v0; // edi
	char* v1; // esi
	char* v2; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		*(_DWORD*)(v1 + 66) = atoi(v0);
		v2 = strtok(0, " \r\t\n");
		if (v2)
			*(_DWORD*)(v1 + 70) = atoi(v2);
	}
	return 1;
}

//----- (004329D0) --------------------------------------------------------
int sub_4329D0() {
	char* v0; // edi
	char* v1; // esi
	char* v2; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		*(_WORD*)(v1 + 105) = atoi(v0);
		v2 = strtok(0, " \r\t\n");
		if (v2)
			*(_WORD*)(v1 + 107) = atoi(v2);
	}
	return 1;
}

//----- (00432A30) --------------------------------------------------------
int sub_432A30() {
	char* v0; // edi
	char* v1; // esi
	bool v2;  // cc
	char v3;  // al

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		v2 = atoi(v0) <= 0;
		v3 = v1[102];
		if (!v2) {
			v1[102] = v3 | 0x80;
			return 1;
		}
		v1[102] = v3 & 0x7F;
	}
	return 1;
}

//----- (00432A90) --------------------------------------------------------
int sub_432A90() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0)
		nox_server_sendMotd_108752 = atoi(v0) != 0;
	return 1;
}

//----- (00432AD0) --------------------------------------------------------
int __cdecl sub_432AD0(int* a1) {
	char* v1; // eax

	strtok(0, " \r\t\n");
	v1 = strtok(0, " \r\t\n");
	*a1 = atoi(v1);
	return 1;
}

//----- (00432B00) --------------------------------------------------------
int nox_common_parsecfg_videomode() {
	char* v0; // eax
	char* v2; // eax
	char* v4; // eax
	int v5;   // eax
	int v6;   // esi

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	int w = atoi(v0);
	v2 = strtok(0, " \r\t\n");
	int h = atoi(v2);
	v4 = strtok(0, " \r\t\n");
	v5 = atoi(v4);
	v6 = v5;
	if (v5 == 8) {
		if (!sub_4300D0(0))
			v6 = 16;
	} else if (v5 == 16) {
		if (!sub_4300D0(1))
			v6 = 8;
	} else {
		v6 = sub_4300D0(1) ? 16 : 8;
	}
#ifdef __EMSCRIPTEN__
	w = EM_ASM_INT(return Module['ingameWidth']());
	h = EM_ASM_INT(return Module['ingameHeight']());
#endif
	v6 = 16; // 8 bit not supported
	if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE)) {
		nox_win_width_1 = w;
		nox_win_height_1 = h;
		nox_win_depth_1 = v6;
		nox_win_depth_2 = v6;

		// FIXME: this will cause the game to change its window size to whatever set in nox.cfg right at the
		// start! this is different from original game where window is only resized after joining the game
		change_windowed_fullscreen();
	}
	return 1;
}

//----- (00432BD0) --------------------------------------------------------
int nox_common_parsecfg_videosize() {
	char* v0; // eax
	int v1;   // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	v1 = atoi(v0);
	sub_4766A0(v1);
	return 1;
}

//----- (00432C00) --------------------------------------------------------
int sub_432C00() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	*getMemU32Ptr(0x587000, 80852) = atoi(v0);
	return 1;
}

//----- (00432C30) --------------------------------------------------------
int sub_432C30() {
	char* v0; // eax
	int v1;   // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = atoi(v0);
		sub_4D0D90(v1 != 0);
	}
	return 1;
}

//----- (00432C70) --------------------------------------------------------
int __cdecl sub_432C70(int a1) {
	char* v1; // eax
	int v2;   // eax

	strtok(0, " \r\t\n");
	v1 = strtok(0, " \r\t\n");
	if (v1) {
		v2 = atoi(v1);
		sub_4D0DC0(a1, v2);
	}
	return 1;
}

//----- (00432CB0) --------------------------------------------------------
int __cdecl sub_432CB0(int a1) {
	char* v1;        // eax
	unsigned int v2; // eax
	int result;      // eax

	strtok(0, " \r\t\n");
	v1 = strtok(0, " \r\t\n");
	v2 = atoi(v1);
	if ((v2 & 0x80000000) == 0) {
		if (v2 > 0x4000)
			v2 = 0x4000;
		sub_486670(v2, a1);
		result = 1;
	} else {
		sub_486670(0, a1);
		result = 1;
	}
	return result;
}

//----- (00432D10) --------------------------------------------------------
int sub_432D10() {
	char* v0;            // eax
	char* v1;            // eax
	unsigned __int8* v2; // esi
	unsigned __int16 v3; // ax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = strtok(v0, ",\r\n");
	if (!v1)
		return 1;
	v2 = getMemAt(0x587000, 81224);
	do {
		v3 = atoi(v1);
		sub_409FB0_settings(*(_DWORD*)v2, v3);
		v2 += 4;
		v1 = strtok(0, ",\r\n");
	} while (v1);
	return 1;
}

//----- (00432D80) --------------------------------------------------------
int sub_432D80() {
	char* v0;            // eax
	char* v1;            // eax
	unsigned __int8* v2; // esi
	unsigned __int8 v3;  // al

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = strtok(v0, ",\r\n");
	if (!v1)
		return 1;
	v2 = getMemAt(0x587000, 81224);
	do {
		v3 = atoi(v1);
		sub_40A040_settings(*(_DWORD*)v2, v3);
		v2 += 4;
		v1 = strtok(0, ",\r\n");
	} while (v1);
	return 1;
}

//----- (00432DF0) --------------------------------------------------------
int sub_432DF0() {
	char* v0; // eax
	int v1;   // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = atoi(v0);
		sub_40A6D0(v1);
		if (sub_40A6C0() <= 0 || sub_40A6C0() > 3)
			sub_40A6D0(1);
	}
	return 1;
}

//----- (00432E50) --------------------------------------------------------
char* __cdecl sub_432E50(int a1) {
	char* v1;     // eax
	char* result; // eax
	int v3;       // esi
	char* v4;     // eax
	int v5[11];   // [esp+4h] [ebp-2Ch]

	strtok(0, " \r\t\n");
	v1 = strtok(0, " \r\t\n");
	if (!v1)
		return (char*)1;
	result = strtok(v1, ",\r\n");
	if (result) {
		v3 = atoi(result);
		result = strtok(0, ",\r\n");
		if (result) {
			v5[0] = atoi(result);
			result = strtok(0, ",\r\n");
			if (result) {
				v5[1] = *result == 49;
				result = strtok(0, ",\r\n");
				if (result) {
					v5[2] = *result == 49;
					result = strtok(0, ",\r\n");
					if (result) {
						v5[3] = atoi(result);
						result = strtok(0, ",\r\n");
						if (result) {
							v5[4] = atoi(result);
							result = strtok(0, ",\r\n");
							if (result) {
								v5[5] = *result == 49;
								result = strtok(0, ",\r\n");
								if (result) {
									v5[6] = *result == 49;
									result = strtok(0, ",\r\n");
									if (result) {
										v5[7] = *result == 49;
										result = strtok(0, ",\r\n");
										if (result) {
											v5[8] = *result == 49;
											result = strtok(0, ",\r\n");
											if (result) {
												v5[9] = *result == 49;
												v4 = strtok(0, ",\r\n");
												if (v4)
													v5[10] = *v4 == 49;
												else
													v5[10] = 0;
												sub_489FF0(a1, v3, v5);
												return (char*)1;
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
	return result;
}

//----- (00433050) --------------------------------------------------------
int sub_433050() {
	char* v0;           // eax
	int v1;             // eax
	unsigned __int8* i; // ecx
	int v3;             // edx

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = atoi(v0);
		if (*getMemU32Ptr(0x587000, 81248)) {
			for (i = getMemAt(0x587000, 81248); *((_DWORD*)i + 1) != v1; i += 8) {
				v3 = *((_DWORD*)i + 2);
				if (!v3)
					return 1;
			}
			if (v1 < 0 && v1 > 4)
				v1 = 4;
			nox_server_connectionType_3596 = v1;
		}
	}
	return 1;
}

//----- (004330C0) --------------------------------------------------------
int sub_4330C0() {
	char* v0; // edi
	char* v1; // esi
	char v2;  // al

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0)
		return 1;
	v1 = sub_416640();
	v2 = atoi(v0);
	v1[104] = v2;
	if ((unsigned __int8)v2 <= 0x20u) {
		if ((unsigned __int8)v2 < 1u)
			v1[104] = 1;
	} else {
		v1[104] = 32;
	}
	sub_409F80((unsigned __int8)v1[104]);
	return 1;
}

//----- (00433130) --------------------------------------------------------
int sub_433130() {
	char* v0; // edi
	char* v1; // esi
	int v2;   // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		v2 = atoi(v0);
		*(_DWORD*)(v1 + 74) = v2;
		if (v2 > 100) {
			*(_DWORD*)(v1 + 74) = 100;
			return 1;
		}
		if (v2 < 0)
			*(_DWORD*)(v1 + 74) = 0;
	}
	return 1;
}

//----- (00433190) --------------------------------------------------------
int sub_433190() {
	char* v0; // eax
	char v2;  // [esp+0h] [ebp-4h]

	v2 = 0;
	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0)
		v2 = atoi(v0);
	sub_578DE0(v2);
	return 1;
}

//----- (004331E0) --------------------------------------------------------
int __cdecl sub_4331E0(FILE* a1, int a2) {
	int v2;     // edi
	int result; // eax

	v2 = 0;
	if (a2) {
		while (fgets((char*)getMemAt(0x5D4594, 806084), 1024, a1)) {
			if (!strncmp("---", (const char*)getMemAt(0x5D4594, 806084), 3u))
				goto LABEL_6;
		}
		result = 1;
	} else {
	LABEL_6:
		do {
			do {
				if (!fgets((char*)getMemAt(0x5D4594, 806084), 1024, a1))
					return v2;
			} while (getMemByte(0x5D4594, 806084) == 35);
			if (!strncmp("---", (const char*)getMemAt(0x5D4594, 806084), 3u))
				return 1;
		} while (sub_42CF50((const char*)getMemAt(0x5D4594, 806084)));
		result = 0;
	}
	return result;
}

//----- (00433290) --------------------------------------------------------
void __cdecl nox_common_writecfgfile(char* a1) {
	FILE* f = fopen(a1, "w");
	if (!f) {
		return;
	}
	sub_4332E0(f);
	sub_42CDF0(f);
	fprintf(f, "---\n");
	fclose(f);
#ifdef __EMSCRIPTEN__
	EM_ASM(FS.syncfs(false, function(err){}));
#endif
}

//----- (004332E0) --------------------------------------------------------
int __cdecl sub_4332E0(FILE* a1) {
	char* v1;             // edi
	int v2;               // eax
	int v3;               // eax
	int v4;               // eax
	int v5;               // eax
	char* v6;             // eax
	unsigned __int8 v7;   // al
	wchar_t* v8;          // eax
	BOOL v9;              // eax
	int v10;              // eax
	unsigned int v11;     // eax
	unsigned int v12;     // ecx
	int v13;              // eax
	unsigned int v14;     // eax
	BOOL v15;             // eax
	int v16;              // eax
	int v17;              // eax
	unsigned __int8* v18; // ebx
	unsigned __int8* v19; // edi
	int v20;              // eax
	int v21;              // eax
	_DWORD* v23;          // [esp+8h] [ebp-4h]

	v1 = sub_416640();
	fprintf(a1, "Version = %d\n", 65540);
	fprintf(a1, "VideoMode = %d %d %d\n", nox_win_width_1, nox_win_height_1, nox_win_depth_1);
	fprintf(a1, "Stretched = %d\n", g_scaled_cfg);
	fprintf(a1, "Fullscreen = %d\n", g_fullscreen_cfg);
	v2 = sub_4766D0();
	fprintf(a1, "VideoSize = %d\n", v2);
	// fprintf(a1, "Gamma = %d\n", *(_DWORD *)getMemAt(0x587000, 80852));
	fprintf(a1, "Gamma2 = %f\n", draw_gamma);
	fprintf(a1, "InputSensitivity = %f\n", input_sensitivity);
	if (sub_453070() == 1)
		v3 = *(_DWORD*)((_DWORD)dword_587000_127004 + 4) >> 16;
	else
		v3 = 0;
	fprintf(a1, "FXVolume = %d\n", v3);
	if (sub_44D990() == 1)
		v4 = *(_DWORD*)((_DWORD)dword_587000_122852 + 4) >> 16;
	else
		v4 = 0;
	fprintf(a1, "DialogVolume = %d\n", v4);
	if (sub_43DC30() == 1)
		v5 = *(_DWORD*)((_DWORD)dword_587000_93164 + 4) >> 16;
	else
		v5 = 0;
	fprintf(a1, "MusicVolume = %d\n", v5);
	fprintf(a1, "LastServer = %s\n", getMemAt(0x5D4594, 806060));
	v6 = sub_433890();
	fprintf(a1, "ServerName = %s\n", v6);
	fprintf(a1, "UnlockSurface = %d\n", nox_video_dxUnlockSurface);
	fprintf(a1, "SoftShadowEdge = %d\n", nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE) ? 1 : 0);
	fprintf(a1, "DrawFrontWalls = %d\n", nox_client_drawFrontWalls_80812);
	fprintf(a1, "TranslucentFrontWalls = %d\n", nox_client_translucentFrontWalls_805844);
	fprintf(a1, "HighResFrontWalls = %d\n", nox_client_highResFrontWalls_80820);
	fprintf(a1, "HighResFloors = %d\n", nox_client_highResFloors_154952);
	fprintf(a1, "LockHighResFloors = %d\n", nox_client_lockHighResFloors_1193152);
	fprintf(a1, "TexturedFloors = %d\n", nox_client_texturedFloors_154956);
	fprintf(a1, "TranslucentConsole = %d\n", nox_client_translucentConsole_80824);
	fprintf(a1, "RenderGlow = %d\n", nox_client_renderGlow_805852);
	fprintf(a1, "RenderGUI = %d\n", nox_client_renderGUI_80828);
	fprintf(a1, "FadeObjects = %d\n", nox_client_fadeObjects_80836);
	fprintf(a1, "RenderBubbles = %d\n", nox_client_renderBubbles_80844);
	v7 = sub_578DF0();
	fprintf(a1, "TrackData = %d\n", v7);
	v8 = sub_40A630();
	fprintf(a1, "SysopPassword = %S\n", v8);
	fprintf(a1, "ServerPassword = %S\n", v1 + 78);
	fprintf(a1, "Profiled = %d\n", nox_profiled_805856 != 0);
	fprintf(a1, "SanctuaryHelp = %d\n", nox_server_sanctuaryHelp_54276);
	fprintf(a1, "MaxPacketLossPct = %d\n", *getMemU32Ptr(0x587000, 81280));
	fprintf(a1, "SendMessageOfTheDay = %d\n", nox_server_sendMotd_108752);
	v9 = sub_4D0D70();
	fprintf(a1, "MapCycle = %d\n", v9);
	fprintf(a1, "ConnectionType = %d\n", nox_server_connectionType_3596);
	v10 = sub_40A6C0();
	fprintf(a1, "InternetUpdateRate = %d\n", v10);
	fprintf(a1, "LessonLimit =");
	sub_4337B0(a1);
	fprintf(a1, "TimeLimit =");
	sub_433820(a1);
	fprintf(a1, "PlayerSkeletons = %d\n", *(_DWORD*)(v1 + 58));
	fprintf(a1, "BroadcastGestures = %d\n", *(_DWORD*)(v1 + 62));
	v11 = fprintf(a1, "LatencyCompensation = %d %d\n", *(_DWORD*)(v1 + 66), *(_DWORD*)(v1 + 70));
	LOBYTE(v11) = v1[100];
	fprintf(a1, "Closed = %d\n", (v11 >> 4) & 1);
	LOBYTE(v12) = v1[100];
	fprintf(a1, "Private = %d\n", (v12 >> 5) & 1);
	fprintf(a1, "AudioThreshold = %d\n", *(_DWORD*)(v1 + 74));
	v13 = sub_409FA0();
	fprintf(a1, "MaxPlayers = %d\n", v13);
	fprintf(a1, "RestrictedClasses = %d\n", v1[100] & 7);
	fprintf(a1, "RestrictedPing = %d %d\n", *(unsigned __int16*)(v1 + 105), *(unsigned __int16*)(v1 + 107));
	fprintf(a1, "LimitMaxRes = %d\n", (unsigned __int8)v1[102] >> 7);
	v14 = sub_409E60();
	fprintf(a1, "CamperAlarm = %d\n", (v14 >> 13) & 1);
	v15 = sub_409F40(2);
	fprintf(a1, "ItemRespawn = %d\n", v15);
	fprintf(a1, "MinKickVotes = %d\n", *getMemU32Ptr(0x587000, 229980));
	fprintf(a1, "ResetQuestMinVotes = %d\n", nox_server_resetQuestMinVotes_229988);
	fprintf(a1, "KickQuestPlayerMinVotes = %d\n", nox_server_kickQuestPlayerMinVotes_229992);
	v16 = sub_48A020(0, &v23);
	fprintf(a1, "LANFilters = %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", v16, *v23, v23[1], v23[2], v23[3], v23[4], v23[5],
			v23[6], v23[7], v23[8], v23[9], v23[10]);
	v17 = sub_48A020(1, &v23);
	fprintf(a1, "INETFilters = %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", v17, *v23, v23[1], v23[2], v23[3], v23[4],
			v23[5], v23[6], v23[7], v23[8], v23[9], v23[10]);
	if (*getMemU32Ptr(0x587000, 81168)) {
		v18 = getMemAt(0x587000, 81168);
		v19 = getMemAt(0x587000, 81168);
		do {
			v20 = sub_4D0DE0(*((_DWORD*)v19 + 1));
			fprintf(a1, "%s = %d\n", *(_DWORD*)v18, v20);
			v21 = *((_DWORD*)v19 + 2);
			v19 += 8;
			v18 = v19;
		} while (v21);
	}
	return fprintf(a1, "---\n");
}
// 4335F8: variable 'v12' is possibly undefined

//----- (004337B0) --------------------------------------------------------
int __cdecl sub_4337B0(FILE* a1) {
	unsigned __int16 v1; // ax
	int v2;              // eax
	unsigned __int8* v3; // esi
	unsigned __int16 v4; // ax

	v1 = sub_40A020(*getMemI16Ptr(0x587000, 81224));
	fprintf(a1, " %d", v1);
	LOWORD(v2) = *getMemU16Ptr(0x587000, 81228);
	if (*getMemU32Ptr(0x587000, 81228)) {
		v3 = getMemAt(0x587000, 81228);
		do {
			v4 = sub_40A020(v2);
			fprintf(a1, ",%d", v4);
			v2 = *((_DWORD*)v3 + 1);
			v3 += 4;
		} while (v2);
	}
	return fprintf(a1, "\n");
}

//----- (00433820) --------------------------------------------------------
int __cdecl sub_433820(FILE* a1) {
	unsigned __int8 v1;  // al
	int v2;              // eax
	unsigned __int8* v3; // esi
	unsigned __int8 v4;  // al

	v1 = sub_40A180(*getMemI16Ptr(0x587000, 81224));
	fprintf(a1, " %d", v1);
	LOWORD(v2) = *getMemU16Ptr(0x587000, 81228);
	if (*getMemU32Ptr(0x587000, 81228)) {
		v3 = getMemAt(0x587000, 81228);
		do {
			v4 = sub_40A180(v2);
			fprintf(a1, ",%d", v4);
			v2 = *((_DWORD*)v3 + 1);
			v3 += 4;
		} while (v2);
	}
	return fprintf(a1, "\n");
}

//----- (00433890) --------------------------------------------------------
char* sub_433890() {
	char* v0;            // eax
	unsigned __int8* v1; // eax
	char v2;             // cl

	v0 = sub_40A4C0();
	strncpy((char*)getMemAt(0x5D4594, 807108), v0, 0x3Fu);
	v1 = getMemAt(0x5D4594, 807108);
	if (getMemByte(0x5D4594, 807108)) {
		do {
			if (*v1 == 32)
				*v1 = 95;
			v2 = *++v1;
		} while (v2);
	}
	return (char*)getMemAt(0x5D4594, 807108);
}

//----- (00433E80) --------------------------------------------------------
void __cdecl sub_433E80(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3) {
	ptr_5D4594_3799572->data[44] = a1;
	ptr_5D4594_3799572->data[45] = a2;
	ptr_5D4594_3799572->data[46] = a3;
}

//----- (00433F10) --------------------------------------------------------
int __cdecl sub_433F10(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3) {
	int result;          // eax
	__int64 v4;          // rax
	unsigned __int64 v5; // rax
	unsigned __int64 v6; // rax

	result = a1;
	ptr_5D4594_3799572->data[54] = a1;
	ptr_5D4594_3799572->data[55] = a2;
	ptr_5D4594_3799572->data[56] = a3;
	if (dword_5d4594_3801804) {
		v4 = a1 | (a1 << 16);
		HIDWORD(v4) = 0;
		v4 <<= 16;
		LODWORD(v4) = a1 | (unsigned int)v4;
		v4 <<= 16;
		ptr_5D4594_3799572->data[48] = a1 | (unsigned int)v4;
		ptr_5D4594_3799572->data[49] = HIDWORD(v4);
		v5 = (a2 | ((a2 | ((unsigned __int64)a2 << 16)) << 16)) << 16;
		ptr_5D4594_3799572->data[50] = a2 | (unsigned int)v5;
		ptr_5D4594_3799572->data[51] = HIDWORD(v5);
		v6 = (a3 | ((a3 | ((unsigned __int64)a3 << 16)) << 16)) << 16;
		ptr_5D4594_3799572->data[52] = a3 | (unsigned int)v6;
		ptr_5D4594_3799572->data[53] = HIDWORD(v6);
		result = ptr_5D4594_3799572;
	}
	return result;
}

//----- (00434080) --------------------------------------------------------
int __cdecl sub_434080(int a1) {
	int result; // eax

	result = a1;
	ptr_5D4594_3799572->data[262] = a1;
	return result;
}

//----- (00434350) --------------------------------------------------------
int __cdecl sub_434350(int a1) {
	int result; // eax

	result = a1;
	ptr_5D4594_3799572->data[58] = a1;
	return result;
}

//----- (00434370) --------------------------------------------------------
int sub_434370() {
	ptr_5D4594_3799572->data[61] = ptr_5D4594_3799572->data[58];
	return ptr_5D4594_3799572;
}

//----- (00434390) --------------------------------------------------------
int __cdecl sub_434390(int a1) {
	ptr_5D4594_3799572->data[59] = a1;
	return a1;
}

//----- (004343E0) --------------------------------------------------------
int __cdecl sub_4343E0(int a1) {
	ptr_5D4594_3799572->data[60] = a1;
	return a1;
}

//----- (00434460) --------------------------------------------------------
int __cdecl nox_client_drawSetColor_434460(int a1) {
	ptr_5D4594_3799572->data[61] = a1;
	return a1;
}

//----- (004344D0) --------------------------------------------------------
int __cdecl sub_4344D0(_BYTE* a1) {
	int result; // eax
	__int16 v2; // cx

	result = 0;
	if (a1) {
		if (dword_5d4594_3799624) {
			result = *(unsigned __int16*)a1 | (*(unsigned __int16*)a1 << 16);
		} else {
			LOBYTE(v2) = 0;
			HIBYTE(v2) = *a1;
			result =
				(unsigned __int16)((unsigned __int8)*a1 | v2) | ((unsigned __int16)((unsigned __int8)*a1 | v2) << 16);
		}
	}
	return result;
}

//----- (00434510) --------------------------------------------------------
char* __cdecl sub_434510(char* a1, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 a4) {
	char* result; // eax
	int v5[10];   // [esp+8h] [ebp-28h]

	v5[6] = a2;
	result = a1;
	v5[7] = a3;
	v5[8] = a4;
	memcpy(a1, v5, 0x28u);
	return result;
}

//----- (00434560) --------------------------------------------------------
int __cdecl nox_client_drawEnableAlpha_434560(int a1) {
	if (ptr_5D4594_3799572->data[13] != a1)
		ptr_5D4594_3799572->data[13] = a1;
	return ptr_5D4594_3799572;
}

//----- (00434580) --------------------------------------------------------
int __cdecl nox_client_drawSetAlpha_434580(unsigned __int8 a1) {
	int result; // eax
	__int64 v2; // rax

	result = a1;
	if (ptr_5D4594_3799572->data[259] != a1) {
		ptr_5D4594_3799572->data[259] = a1;
		v2 = a1 | (a1 << 16);
		HIDWORD(v2) = 0;
		v2 <<= 16;
		LODWORD(v2) = a1 | (unsigned int)v2;
		v2 <<= 16;
		ptr_5D4594_3799572->data[260] = a1 | (unsigned int)v2;
		result = ptr_5D4594_3799572;
		ptr_5D4594_3799572->data[261] = HIDWORD(v2);
	}
	return result;
}

//----- (004345F0) --------------------------------------------------------
int __cdecl sub_4345F0(int a1) {
	ptr_5D4594_3799572->data[14] = a1;
	return a1;
}

//----- (00434600) --------------------------------------------------------
int __cdecl sub_434600(int a1) {
	ptr_5D4594_3799572->data[17] = a1;
	return a1;
}

//----- (00434610) --------------------------------------------------------
int __cdecl sub_434610(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_810636 = a1;
	return result;
}

//----- (00434620) --------------------------------------------------------
int __cdecl sub_434620(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_810632 = a1;
	return result;
}

//----- (00434630) --------------------------------------------------------
unsigned __int8 __cdecl sub_434630(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3) {
	int v3;                 // ecx
	unsigned __int8* v4;    // eax
	int v5;                 // esi
	unsigned int v6;        // ecx
	int v7;                 // edi
	int v8;                 // eax
	unsigned __int8 result; // al
	unsigned __int8* v10;   // edi
	int v11;                // edx
	int v12;                // esi
	int v13;                // edx
	unsigned __int8* v14;   // ecx
	int v15;                // [esp+10h] [ebp-10h]
	int v16;                // [esp+10h] [ebp-10h]
	unsigned int v17;       // [esp+14h] [ebp-Ch]
	unsigned __int8 v18;    // [esp+18h] [ebp-8h]

	v3 = 0;
	v4 = getMemAt(0x5D4594, 3804524);
	if (*(int*)&dword_5d4594_808568 <= 0) {
	LABEL_6:
		v5 = a1;
		v6 = a1 | ((a2 | (a3 << 8)) << 8);
		v7 = 0;
		v15 = 255;
		do {
			v8 = (v7 + v15) / 2;
			if (v6 >= *getMemIntPtr(0x5D4594, 4 * v8 + 809604)) {
				if (!v6)
					return getMemByte(0x5D4594, v8 + 808304);
				v7 = v8 + 1;
			} else {
				v15 = v8 - 1;
			}
		} while (v7 <= v15);
		v17 = 195075;
		v18 = 0;
		v16 = 0;
		v10 = getMemAt(0x5D4594, 3803310);
		while (1) {
			v11 = *(v10 - 2) - v5;
			v12 = *(v10 - 1) - a2;
			if (v11 * v11 + v12 * v12 + (*v10 - a3) * (*v10 - (unsigned int)a3) < v17) {
				v17 = v11 * v11 + v12 * v12 + (*v10 - a3) * (*v10 - a3);
				v18 = v16;
			}
			v10 += 4;
			if (++v16 >= 256)
				break;
			v5 = a1;
		}
		v13 = dword_5d4594_810628;
		*getMemU8Ptr( 0x5D4594, 4 * dword_5d4594_810628 + 3804524) = a1;
		v14 = getMemAt(0x5D4594, 4 * v13 + 3804524);
		v14[1] = a2;
		v14[2] = a3;
		v14[3] = v18;
		if (*(int*)&dword_5d4594_808568 < 32)
			++dword_5d4594_808568;
		if (++*(int*)&dword_5d4594_810628 >= 32)
			dword_5d4594_810628 = 0;
		result = v18;
	} else {
		while (a1 != *v4 || a2 != v4[1] || a3 != v4[2]) {
			v4 += 4;
			if (++v3 >= *(int*)&dword_5d4594_808568)
				goto LABEL_6;
		}
		result = v4[3];
	}
	return result;
}

//----- (004347C0) --------------------------------------------------------
char __cdecl sub_4347C0(char a1) {
	char result; // al
	int v2;      // ecx

	result = a1;
	v2 = 256;
	do {
		--v2;
		*getMemU8Ptr(0x5D4594, 3803310) = a1;
		*getMemU8Ptr(0x5D4594, 3803309) = a1;
		*getMemU8Ptr(0x5D4594, 3803308) = a1;
		*getMemU8Ptr(0x5D4594, 3803311) = 0;
	} while (v2);
	return result;
}

//----- (00434820) --------------------------------------------------------
int __cdecl sub_434820(int a1, char a2, char a3, char a4) {
	if (a1 < 0 || a1 >= 256)
		return 0;
	*getMemU8Ptr( 0x5D4594, 4 * a1 + 3803308) = a2;
	*getMemU8Ptr( 0x5D4594, 4 * a1 + 3803309) = a3;
	*getMemU8Ptr( 0x5D4594, 4 * a1 + 3803310) = a4;
	*getMemU8Ptr( 0x5D4594, 4 * a1 + 3803311) = 4;
	sub_435040();
	sub_434F00();
	sub_48BDE0();
	return 1;
}

//----- (00434870) --------------------------------------------------------
int __cdecl sub_434870(int a1, _BYTE* a2, _BYTE* a3, _BYTE* a4) {
	if (a1 < 0 || a1 >= 256)
		return 0;
	if (a2)
		*a2 = getMemByte(0x5D4594, 4 * a1 + 3803308);
	if (a3)
		*a3 = getMemByte(0x5D4594, 4 * a1 + 3803309);
	if (a4)
		*a4 = getMemByte(0x5D4594, 4 * a1 + 3803310);
	return 1;
}

//----- (00434920) --------------------------------------------------------
int sub_434920() {
	int result; // eax

	if (dword_5d4594_808564)
		return 0;
	result = 1;
	memcpy(getMemAt(0x5D4594, 808572), getMemAt(0x5D4594, 3803308), 0x400u);
	dword_5d4594_808564 = 1;
	return result;
}

//----- (00434950) --------------------------------------------------------
int sub_434950() {
	if (!dword_5d4594_808564)
		return 0;
	dword_5d4594_808564 = 0;
	memcpy(getMemAt(0x5D4594, 3803308), getMemAt(0x5D4594, 808572), 0x400u);
	sub_435040();
	sub_434F00();
	return 1;
}

//----- (00434990) --------------------------------------------------------
int __cdecl sub_434990(int a1, int a2, int a3) {
	ptr_5D4594_3799572->data[62] = a1;
	ptr_5D4594_3799572->data[63] = a2;
	ptr_5D4594_3799572->data[64] = a3;
	return a2;
}

//----- (004349C0) --------------------------------------------------------
int __cdecl sub_4349C0(_DWORD* a1) {
	ptr_5D4594_3799572->data[62] = *a1;
	ptr_5D4594_3799572->data[63] = a1[1];
	ptr_5D4594_3799572->data[64] = a1[2];
	return a1[2];
}

//----- (00434A00) --------------------------------------------------------
int sub_434A00() { return (_DWORD)(&ptr_5D4594_3799572->data[62]); }

//----- (00434A10) --------------------------------------------------------
_DWORD* __cdecl sub_434A10(_DWORD* a1, _DWORD* a2, _DWORD* a3) {
	if (a1)
		*a1 = ptr_5D4594_3799572->data[62];
	if (a2)
		*a2 = ptr_5D4594_3799572->data[63];
	if (a3)
		*a3 = ptr_5D4594_3799572->data[64];
	return a3;
}

//----- (00434A60) --------------------------------------------------------
char __cdecl sub_434A60(int a1) {
	return *(_BYTE*)(dword_5d4594_3804668 + (((unsigned __int8)(getMemByte(0x5D4594, 4 * a1 + 3803310) & 0xF8) >> 3) |
											 (4 * (getMemByte(0x5D4594, 4 * a1 + 3803309) & 0xF8)) |
											 ((getMemByte(0x5D4594, 4 * a1 + 3803308) & 0xF8) << 7)));
}

//----- (00434DA0) --------------------------------------------------------
int sub_434DA0() {
	__int16 v0;      // bx
	int v1;          // edi
	void* result;    // eax
	unsigned int v3; // esi

	if (*(int*)&dword_5d4594_3799624 < 0)
		return 1;
	if (dword_5d4594_3799624 > 1) {
		if (dword_5d4594_3799624 == 2) {
			v0 = 3;
			v1 = 0xFFFF;
			goto LABEL_6;
		}
		return 1;
	}
	v0 = 7;
	v1 = 0x7FFF;
LABEL_6:
	result = (int)calloc(v1 + 3, 1u);
	dword_5d4594_3804668 = result;
	if (result) {
		v3 = 0;
		while (1) {
			*(_BYTE*)((char*)result + v3) =
				(unsigned __int16)(28 * ((((unsigned __int16)v3 & *((_WORD*)((_BYTE*)byte_5D4594_3804364 + 8)))
										  << *((_BYTE*)byte_5D4594_3804364 + 20)) |
										 7) +
								   150 * (v0 | ((v3 & *((_DWORD*)((_BYTE*)byte_5D4594_3804364 + 4))) >> *((_BYTE*)byte_5D4594_3804364 + 16))) +
								   76 * (((v3 & *((_DWORD*)((_BYTE*)byte_5D4594_3804364 + 0))) >> *((_BYTE*)byte_5D4594_3804364 + 12)) | 7)) >>
				8;
			if ((int)++v3 > v1)
				break;
			result = dword_5d4594_3804668;
		}
		result = 1;
	}
	return 1;
}

//----- (00434E80) --------------------------------------------------------
char __cdecl sub_434E80(char a1, char a2, char a3) {
	return *(_BYTE*)(dword_5d4594_3804668 +
					 (((unsigned __int8)(a3 & 0xF8) >> 3) | (4 * (a2 & 0xF8)) | ((a1 & 0xF8) << 7)));
}

//----- (00434EC0) --------------------------------------------------------
char __cdecl sub_434EC0(char a1, char a2, char a3) {
	return *(_BYTE*)(dword_5d4594_3804668 +
					 (((unsigned __int8)(a3 & 0xF8) >> 3) | (8 * (a2 & 0xFC)) | ((a1 & 0xF8) << 8)));
}

//----- (00434F00) --------------------------------------------------------
int sub_434F00() {
	int result; // eax
	int i;      // ebx

	if (dword_5d4594_3799624)
		return 1;
	if (dword_5d4594_810640 || (result = (int)calloc(0x8000u, 1u), (dword_5d4594_810640 = result) != 0)) {
		for (i = 0; i <= 0x7FFF; ++i)
			*(_BYTE*)(dword_5d4594_810640 + i) =
				sub_434630((unsigned __int16)(i & 0x7C00) >> 7, (unsigned __int16)(i & 0x3E0) >> 2, 8 * (i & 0x1F));
		result = 1;
	}
	return result;
}

//----- (00435040) --------------------------------------------------------
void sub_435040() {
	pixel8888 buf[256]; // [esp+4h] [ebp-400h]
	unsigned __int8* data;

	data = getMemAt(0x5D4594, 3803308);
	for (int i = 0; i < 256; ++i) {
		buf[i].field_0 = i;
		buf[i].field_1 = data[4 * i + 0];
		buf[i].field_2 = data[4 * i + 1];
		buf[i].field_3 = data[4 * i + 2];
	}
	sub_48C580(buf, 256);

	data = getMemAt(0x5D4594, 809604);
	for (int i = 0; i < 256; ++i) {
		data[4 * i + 0] = buf[i].field_1;
		data[4 * i + 1] = buf[i].field_2;
		data[4 * i + 2] = buf[i].field_3;
		data[4 * i + 3] = 0;
		*getMemU8Ptr( 0x5D4594, i + 808304) = buf[i].field_0;
	}
	dword_5d4594_808568 = 0;
	dword_5d4594_810628 = 0;
}

//----- (004350E0) --------------------------------------------------------
_BYTE* __cdecl sub_4350E0(_BYTE* a1, _BYTE* a2) {
	_BYTE* v2;     // ecx
	_BYTE* result; // eax
	int v4;        // esi

	v2 = a2;
	result = a1;
	v4 = 256;
	do {
		*result = *v2;
		result[1] = v2[1];
		result[2] = v2[2];
		result[3] = 4;
		result += 4;
		v2 += 4;
		--v4;
	} while (v4);
	return result;
}

//----- (00435120) --------------------------------------------------------
void __cdecl sub_435120(_BYTE* a1, char* a2) {
	char* result; // eax
	_BYTE* v3;    // ecx
	int v4;       // esi
	char v5;      // bl
	char* v6;     // eax
	char v7;      // bl
	char v8;      // bl

	result = a2;
	v3 = a1;
	v4 = 256;
	do {
		v5 = *result;
		v6 = result + 1;
		*v3 = v5;
		v7 = *v6++;
		v3[1] = v7;
		v8 = *v6;
		v3[3] = 4;
		v3[2] = v8;
		result = v6 + 1;
		v3 += 4;
		--v4;
	} while (v4);
}

//----- (00435150) --------------------------------------------------------
void __cdecl sub_435150(_BYTE* a1, char* a2) {
	char* v2;      // ecx
	_BYTE* result; // eax
	int v4;        // esi
	char v5;       // dl
	_BYTE* v6;     // eax

	v2 = a2;
	result = a1;
	v4 = 256;
	do {
		v5 = *v2;
		v2 += 4;
		*result = v5;
		v6 = result + 1;
		*v6++ = *(v2 - 3);
		*v6 = *(v2 - 2);
		result = v6 + 1;
		--v4;
	} while (v4);
}

//----- (00435180) --------------------------------------------------------
void nox_color_func_435180(uint8_t r, uint8_t g, uint8_t b, uint32_t* color) {
	uint8_t c = sub_434630(r, g, b);
	uint32_t val = c | (c << 8);
	*color = val | (val << 16);
}

//----- (004351C0) --------------------------------------------------------
void nox_color_func_4351C0(uint8_t r, uint8_t g, uint8_t b, uint32_t* color) {
	uint32_t val = (b >> 3) | (4 * (g & 0xF8 | (32 * (r & 0xF8))));
	*color = val | (val << 16);
}

//----- (00435200) --------------------------------------------------------
void nox_color_func_435200(uint8_t r, uint8_t g, uint8_t b, uint32_t* color) {
	uint32_t val = (b >> 3) | (8 * (g & 0xFC | (32 * (r & 0xF8))));
	*color = val | (val << 16);
}

//----- (00435240) --------------------------------------------------------
void __cdecl sub_435240(unsigned __int8 a1, _BYTE* a2, _BYTE* a3, char* a4) {
	int v4;      // eax
	char result; // al

	v4 = 4 * a1;
	*a2 = getMemByte(0x5D4594, v4 + 3803308);
	*a3 = getMemByte(0x5D4594, v4 + 3803309);
	result = getMemByte(0x5D4594, v4 + 3803310);
	*a4 = result;
}

//----- (00435280) --------------------------------------------------------
void __cdecl sub_435280(__int16 a1, _BYTE* a2, _BYTE* a3, _BYTE* a4) {
	char result; // al

	*a2 = (unsigned __int16)(*((_WORD*)((_BYTE*)byte_5D4594_3804364 + 0)) & a1) >> *((_BYTE*)byte_5D4594_3804364 + 12);
	*a3 = (unsigned __int16)(*((_WORD*)((_BYTE*)byte_5D4594_3804364 + 4)) & a1) >> *((_BYTE*)byte_5D4594_3804364 + 16);
	result = ((unsigned __int8)a1 & *((_BYTE*)byte_5D4594_3804364 + 8)) << *((_BYTE*)byte_5D4594_3804364 + 20);
	*a4 = result;
}

//----- (00435570) --------------------------------------------------------
__int64 sub_435570() {
	__int64 result; // rax

	result = sub_416BB0();
	*getMemU64Ptr(0x5D4594, 811908) = result;
	return result;
}

//----- (00435590) --------------------------------------------------------
int sub_435590() { return *getMemU32Ptr(0x5D4594, 811916); }

//----- (004355A0) --------------------------------------------------------
void sub_4355A0() { nox_srand(0xA28u); }

//----- (004355B0) --------------------------------------------------------
int __cdecl sub_4355B0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 811116) = a1;
	return result;
}

//----- (004355C0) --------------------------------------------------------
BOOL sub_4355C0() {
	int v0;    // eax
	float2 v2; // [esp+0h] [ebp-8h]

	v2.field_0 = (double)*getMemIntPtr(0x5D4594, 811092);
	v2.field_4 = (double)*getMemIntPtr(0x5D4594, 811096);
	v0 = sub_411160(&v2);
	return v0 == 255 || v0 == -1;
}

//----- (00435600) --------------------------------------------------------
int __cdecl sub_435600(int a1, int a2) {
	int v2;     // ecx
	int result; // eax

	v2 = a2 + *getMemU32Ptr(0x5D4594, 811116) - dword_5d4594_811104 / 2;
	*getMemU32Ptr(0x5D4594, 811364) = *getMemU32Ptr(0x5D4594, 811092);
	*getMemU32Ptr(0x5D4594, 811368) = *getMemU32Ptr(0x5D4594, 811096);
	result = v2 + dword_5d4594_811104 / 2;
	*getMemU32Ptr(0x5D4594, 811092) = a1;
	*getMemU32Ptr(0x5D4594, 811096) = v2 + dword_5d4594_811104 / 2;
	*getMemU32Ptr(0x5D4594, 811084) = a1 - dword_5d4594_811100 / 2;
	*getMemU32Ptr(0x5D4594, 811088) = a2 + *getMemU32Ptr(0x5D4594, 811116) - dword_5d4594_811104 / 2;
	return result;
}

//----- (00435670) --------------------------------------------------------
void __cdecl sub_435670(int2* a1) { *a1 = *(int2*)getMemAt(0x5D4594, 811092); }

//----- (00435690) --------------------------------------------------------
_DWORD* __cdecl sub_435690(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	*a1 = *getMemU32Ptr(0x5D4594, 811364);
	a1[1] = *getMemU32Ptr(0x5D4594, 811368);
	return result;
}

//----- (004356B0) --------------------------------------------------------
int sub_4356B0() { return dword_5d4594_811372; }

//----- (004356C0) --------------------------------------------------------
BOOL __cdecl sub_4356C0(nox_drawable* dr, char a2) {
	int a1 = dr;
	BOOL result; // eax

	result = a1;
	if (a1)
		result = ((1 << a2) & *(_DWORD*)(a1 + 124)) != 0;
	return result;
}

//----- (004356E0) --------------------------------------------------------
void sub_4356E0() { *getMemU32Ptr(0x587000, 85720) = 0; }

//----- (004356F0) --------------------------------------------------------
char* sub_4356F0() { return (char*)getMemAt(0x5D4594, 811280); }

//----- (00435700) --------------------------------------------------------
wchar_t* __cdecl sub_435700(wchar_t* a1, int a2) {
	wchar_t* result; // eax

	result = nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 811376), a1);
	*getMemU32Ptr(0x5D4594, 811060) = a2;
	return result;
}

//----- (00435720) --------------------------------------------------------
char* __cdecl sub_435720(char* a1) { return strncpy((char*)getMemAt(0x587000, 85680), a1, 0x20u); }

//----- (00435740) --------------------------------------------------------
DWORD sub_435740() {
	DWORD result; // eax

	result = nox_get_ticks();
	*getMemU32Ptr(0x5D4594, 811924) = result;
	return result;
}

//----- (00435750) --------------------------------------------------------
DWORD sub_435750() {
	DWORD result; // eax

	result = nox_get_ticks() - *getMemU32Ptr(0x5D4594, 811924);
	*getMemU32Ptr(0x5D4594, 811928) = result;
	return result;
}

//----- (00435770) --------------------------------------------------------
DWORD sub_435770() {
	DWORD result; // eax

	result = nox_get_ticks();
	*getMemU32Ptr(0x5D4594, 811932) = result;
	return result;
}

//----- (00435780) --------------------------------------------------------
DWORD sub_435780() {
	DWORD result; // eax

	result = nox_get_ticks() - *getMemU32Ptr(0x5D4594, 811932);
	*getMemU32Ptr(0x5D4594, 811936) = result;
	return result;
}

//----- (004357A0) --------------------------------------------------------
int sub_4357A0() {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 2618908) && *(_BYTE*)(*getMemU32Ptr(0x5D4594, 2618908) + 3680) & 1)
		result = sub_48CA70(0);
	else
		result = sub_48CA70(1);
	return result;
}

//----- (004357D0) --------------------------------------------------------
BOOL __cdecl sub_4357D0(int argc, const char** argv) {
	*getMemU32Ptr(0x5D4594, 2616328) = 0;
	*getMemU32Ptr(0x5D4594, 2614252) = 0;
	*getMemU32Ptr(0x5D4594, 2618908) = 0;
	strcpy((char*)getMemAt(0x5D4594, 811280), sub_4358A0());
	if (argc > 1) {
		int v2 = argc - 1;
		const char** v3 = argv + 1;
		do {
			if (!_strcmpi("-noskip", *v3))
				*getMemU32Ptr(0x587000, 85724) = 0;
			++v3;
			--v2;
		} while (v2);
	}
#ifdef __EMSCRIPTEN__
	*getMemU32Ptr(0x587000, 85724) = 0;
#endif
	*getMemU32Ptr(0x5D4594, 811064) = nox_client_renderGUI_80828;
	sub_40EE60();
	if (!nox_common_gameFlags_check_40A5C0(1))
		sub_416E30();
	BOOL result = sub_48D7D0();
	if (!result) {
		return 0;
	}
	sub_4E4EF0();
	sub_48D740();
	sub_43C720(0);
	dword_5d4594_2650672 = 0;
	sub_473930();
	sub_48D4B0(0);
	return 1;
}

//----- (00435A10) --------------------------------------------------------
int __cdecl sub_435A10(signed int* a1) {
	char* v1;            // ebx
	int result;          // eax
	unsigned __int16 v3; // ax
	int v4;              // [esp+Ch] [ebp-A8h]
	int v5;              // [esp+10h] [ebp-A4h]
	int v6;              // [esp+14h] [ebp-A0h]
	BYTE Data[153];      // [esp+18h] [ebp-9Ch]

	sub_43BEB0_get_video_mode(&v5, &v4, &v6);
	v1 = sub_431770();
	nox_wcscpy((wchar_t*)v1, (const wchar_t*)getMemAt(0x5D4594, 2661908));
	v1[66] = getMemByte(0x5D4594, 2661958);
	*(_WORD*)(v1 + 71) = *getMemU16Ptr(0x5D4594, 2661888);
	v1[73] = getMemByte(0x5D4594, 2661890);
	*((_WORD*)v1 + 34) = *getMemU16Ptr(0x5D4594, 2661891);
	v1[70] = getMemByte(0x5D4594, 2661893);
	*((_WORD*)v1 + 37) = *getMemU16Ptr(0x5D4594, 2661894);
	v1[76] = getMemByte(0x5D4594, 2661896);
	*(_WORD*)(v1 + 77) = *getMemU16Ptr(0x5D4594, 2661897);
	v1[79] = getMemByte(0x5D4594, 2661899);
	*((_WORD*)v1 + 40) = *getMemU16Ptr(0x5D4594, 2661900);
	v1[82] = getMemByte(0x5D4594, 2661902);
	v1[83] = getMemByte(0x5D4594, 2661903);
	v1[84] = getMemByte(0x5D4594, 2661904);
	v1[85] = getMemByte(0x5D4594, 2661905);
	v1[86] = getMemByte(0x5D4594, 2661906);
	v1[87] = getMemByte(0x5D4594, 2661907);
	v1[67] = getMemByte(0x5D4594, 2661959);
	sub_48D740();
	*(_DWORD*)&Data[97] = v5;
	*(_DWORD*)&Data[101] = v4;
	sub_420120(&Data[105]);
	if (!sub_43AF70())
		sub_40E0D0((int)&Data[105], (LPCSTR)getMemAt(0x587000, 86344), 0);
	Data[152] = !sub_40ABD0();
	if (getMemByte(0x5D4594, 2660684) & 4)
		Data[152] |= 0x80u;
	strcpy((char*)&Data[142], (const char*)getMemAt(0x5D4594, 2660012 + 87));
	strcpy((char*)&Data[128], sub_41FA40());
	*(_DWORD*)&Data[138] = dword_5d4594_2660032;
	memcpy(Data, v1, 0x61u);
	if (nox_common_gameFlags_check_40A5C0(1)) {
		sub_4D3860(Data);
		*getMemU32Ptr(0x5D4594, 2616328) = sub_4DD320(31, (int)Data);
		sub_409AE0(66458);
		sub_494E90(31);
	} else {
		v3 = sub_43B320();
		result = sub_43C7B0((char*)getMemAt(0x587000, 85680), v3, (int)Data, a1);
		if (!result)
			return result;
		sub_40ED10(31, 0);
		sub_40A340(0);
		sub_40A360(0);
		result = sub_43CFF0();
		if (!result) {
			*a1 = -19;
			return result;
		}
		if (sub_409AD0() != 66458) {
			*a1 = -20;
			return 0;
		}
		printf("foo 7\n");
	}
	dword_5d4594_811372 = 2;
	if (!nox_common_gameFlags_check_40A5C0(1))
		sub_417C60();
	return 1;
}

//----- (00435CC0) --------------------------------------------------------
int sub_435CC0() {
	int result; // eax
	int v1;     // eax

	sub_445450();
	sub_45DB90();
	sub_41D1A0(0);
	sub_435570();
	dword_5d4594_1556112 = 0;

	if (!nox_alloc_drawable_init(5000))
		return 0;

	result = sub_49A8E0_init();
	if (!result)
		return 0;

	result = sub_49A5F0();
	if (!result)
		return 0;

	result = sub_44C840_read_things();
	if (!result)
		return 0;

	result = sub_427070();
	if (!result)
		return 0;

	result = sub_494F00();
	if (!result)
		return 0;

	result = sub_473680();
	if (!result)
		return 0;

	nox_alloc_npcs();
	result = sub_499360();
	if (!result)
		return 0;

	sub_485F80();
	result = sub_4960B0();
	if (!result)
		return 0;

	result = sub_473A40();
	if (!result)
		return 0;

	result = sub_495AB0();
	if (!result)
		return 0;

	result = sub_495980();
	if (!result)
		return 0;

	sub_4958F0();
	sub_43C720(0);
	sub_40A4D0(0x800000);
	if (nox_common_gameFlags_check_40A5C0(1))
		sub_4DDF60(31);
	else
		sub_43CB00();
	nox_set_draw_unk1(sub_435F80_draw);
	dword_5d4594_811372 = 3;
	*getMemU32Ptr(0x587000, 85720) = 1;
	*getMemU32Ptr(0x5D4594, 811076) = nox_win_width - 1;
	*getMemU32Ptr(0x5D4594, 811068) = 0;
	dword_5d4594_811072 = 0;
	dword_5d4594_811100 = nox_win_width;
	*getMemU32Ptr(0x5D4594, 811080) = nox_win_height - 1;
	dword_5d4594_811104 = nox_win_height;
	*getMemU8Ptr(0x5D4594, 811108) = 0;
	*getMemU32Ptr(0x5D4594, 811112) = 0;
	*getMemU32Ptr(0x5D4594, 811116) = 0;
	v1 = sub_4766D0();
	sub_476700(v1, 0);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_41CC00((char*)getMemAt(0x5D4594, 2660688));
	} else if (sub_4D6F50() || sub_4D6F70()) {
		if (sub_4D6F50() || sub_4D6F70()) {
			sub_460380();
			sub_460E60();
			sub_4721D0();
		}
		if (!nox_common_gameFlags_check_40A5C0(1))
			sub_41CC00((char*)getMemAt(0x5D4594, 2660688));
	}
	sub_41A480((char*)getMemAt(0x5D4594, 2660688));
	nox_server_parseCmdText_443C80((wchar_t*)getMemAt(0x587000, 86380), 1);
	sub_4951C0();
	sub_465DE0(0);
	return 1;
}

//----- (00435EB0) --------------------------------------------------------
int sub_435EB0() {
	nox_common_writecfgfile((char*)getMemAt(0x587000, 86424));
	if (nox_common_gameFlags_check_40A5C0(1))
		sub_4DE530(31, 2);
	else
		sub_43CB50();
	sub_499450();
	sub_467DF0(0);
	sub_495AE0();
	sub_4959D0();
	sub_473B30_free();
	sub_496120();
	sub_473840();
	nox_things_free_44C580();
	sub_49A950_free();
	nox_drawable_free();
	sub_49AEA0();
	sub_49A2E0();
	sub_4951C0();
	dword_5d4594_811372 = 2;
	return 1;
}
// 49A2E0: using guessed type int sub_49A2E0(void);

//----- (00435F40) --------------------------------------------------------
int sub_435F40() {
	int result; // eax

	result = 1 - dword_5d4594_811896;
	dword_5d4594_811896 = 1 - dword_5d4594_811896;
	return result;
}

//----- (00435F60) --------------------------------------------------------
int sub_435F60() {
	int result; // eax

	result = 1 - dword_5d4594_811904;
	dword_5d4594_811904 = 1 - dword_5d4594_811904;
	return result;
}

//----- (00435F80) --------------------------------------------------------
int sub_435F80_draw() {
	int2* v0; // esi

	v0 = nox_client_getMousePos_4309F0();
	if (sub_446180())
		sub_446190();
	if (!sub_437060() && !nox_common_gameFlags_check_40A5C0(8)) {
		sub_43DDD0(0);
		return 0;
	}
	sub_437100();
	if (!sub_478030() && !sub_477600())
		sub_470DE0();
	sub_42D220();
	if (sub_430890() == 1)
		sub_430880(0);
	sub_476FA0();
	if (!sub_43C8F0(31, *getMemU32Ptr(0x5D4594, 811084) + v0->field_0 - *getMemU32Ptr(0x5D4594, 811068),
					*getMemU32Ptr(0x5D4594, 811088) + v0->field_4 - dword_5d4594_811072))
		return 1;
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		sub_40B970();
		sub_40B790();
	}
	if (nox_common_gameFlags_check_40A5C0(1)) {
		sub_49C4B0();
		if (!sub_494E90(31))
			return 1;
	} else {
		sub_43CCA0();
	}
	sub_49BD70((int)getMemAt(0x5D4594, 811068));
	sub_49BBC0();
	sub_421B80();
	if (nox_client_isConnected_43C700())
		sub_4357A0();
	sub_436100_draw();
	sub_49BB40();
	sub_49BA70();
	if (sub_409F40(4096))
		sub_46D830();
	if (*getMemU32Ptr(0x5D4594, 826068))
		sub_4467F0();
	if (sub_42EBA0() == 1) {
		sub_42EB90(0);
		sub_49B7A0();
	}
	sub_49B6E0();
	return *getMemU32Ptr(0x587000, 85720);
}
// 435F91: variable 'v1' is possibly undefined

//----- (00436550) --------------------------------------------------------
BOOL sub_436550() {
	int v0; // eax

	if (sub_459DA0() || sub_446360() || sub_49CB40() || sub_49C810() || sub_446950() || sub_4706A0() || sub_451410()) {
		v0 = *getMemU32Ptr(0x5D4594, 2598000);
	} else {
		v0 = *getMemU32Ptr(0x5D4594, 2598000);
		if (*getMemU32Ptr(0x5D4594, 2598000) != 2)
			return *getMemU32Ptr(0x5D4594, 2598000) - *getMemU32Ptr(0x5D4594, 811920) == 1;
	}
	*getMemU32Ptr(0x5D4594, 811920) = v0;
	return 1;
}

//----- (00437060) --------------------------------------------------------
int sub_437060() {
	char* v0; // eax
	char i;   // cl
	bool v2;  // zf

	if (!sub_46A4A0()) {
		v0 = sub_430940();
		dword_5d4594_2618912 = v0;
		for (i = *v0; *v0; i = *v0) {
			if (v0[2] != 1 && v0[1] != 2) {
				switch (i) {
				case 0x3B:
				case 0x3C:
				case 0x3D:
				case 0x3E:
				case 0x3F:
				case 0x40:
				case 0x41:
				case 0x42:
				case 0x43:
				case 0x44:
				case 0x57:
				case 0x58:
					v2 = sub_477600() == 0;
					v0 = *(char**)&dword_5d4594_2618912;
					if (v2) {
						sub_4443B0(**(_BYTE**)&dword_5d4594_2618912);
						v0 = *(char**)&dword_5d4594_2618912;
					}
					break;
				default:
					break;
				}
			}
			v0 += 8;
			dword_5d4594_2618912 = v0;
		}
	}
	return 1;
}

//----- (00437100) --------------------------------------------------------
int sub_437100() {
	int result; // eax

	result = nox_client_renderGUI_80828;
	if (*getMemU32Ptr(0x5D4594, 811064) != nox_client_renderGUI_80828 && !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		*getMemU32Ptr(0x5D4594, 811064) = nox_client_renderGUI_80828;
		sub_4721A0(*(int*)&nox_client_renderGUI_80828);
		sub_460EA0(*(int*)&nox_client_renderGUI_80828);
		nox_window_set_visible_unk5(*(int*)&nox_client_renderGUI_80828);
		sub_45D500(*(int*)&nox_client_renderGUI_80828);
		sub_455A00(*(int*)&nox_client_renderGUI_80828);
		sub_455F10(*(int*)&nox_client_renderGUI_80828);
		sub_4706C0(*(int*)&nox_client_renderGUI_80828);
		result = nox_client_renderGUI_80828;
		if (!nox_client_renderGUI_80828)
			result = sub_478000();
	}
	return result;
}

//----- (00437180) --------------------------------------------------------
int4* sub_437180() { return sub_48D990(getMemAt(0x5D4594, 811068)); }

//----- (00437190) --------------------------------------------------------
int sub_437190() {
	int result; // eax

	if (sub_43AF70() == 1)
		sub_40D380();
	sub_473960();
	sub_416E30();
	sub_455EE0();
	sub_456240();
	sub_48D800();
	sub_49A8C0();
	sub_470550();
	sub_46C5D0();
	sub_44DF70();
	if (!nox_common_gameFlags_check_40A5C0(1))
		sub_43CC80();
	dword_5d4594_811372 = 0;
	if (!nox_common_gameFlags_check_40A5C0(1))
		sub_4E4DE0();
	sub_40A380();
	sub_435720((char*)getMemAt(0x5D4594, 814544));
	sub_446580(1);
	sub_48D760();
	if (!nox_common_gameFlags_check_40A5C0(1))
		sub_40EE60();
	result = sub_417CF0();
	*getMemU32Ptr(0x5D4594, 2616328) = 0;
	*getMemU32Ptr(0x5D4594, 2614252) = 0;
	*getMemU32Ptr(0x5D4594, 2618908) = 0;
	return result;
}

//----- (00437250) --------------------------------------------------------
char* sub_437250() { return (char*)getMemAt(0x5D4594, 811068); }

//----- (00437260) --------------------------------------------------------
int4* sub_437260() {
	return nox_client_copyRect_49F6F0(*getMemIntPtr(0x5D4594, 811068), *(int*)&dword_5d4594_811072,
									  *(int*)&dword_5d4594_811100, *(int*)&dword_5d4594_811104);
}

//----- (00437290) --------------------------------------------------------
int4* sub_437290() { return nox_client_copyRect_49F6F0(0, 0, nox_backbuffer_width, nox_backbuffer_height); }

//----- (004372B0) --------------------------------------------------------
BOOL sub_4372B0() {
	int v0;      // eax
	BOOL result; // eax

	result = 1;
	if (*getMemU32Ptr(0x5D4594, 2614252)) {
		v0 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 276);
		if (v0 != 1 && v0 != 2 && v0 != 51)
			result = 0;
	}
	return result;
}

//----- (004372E0) --------------------------------------------------------
BOOL sub_4372E0() {
	BOOL result; // eax

	if (*getMemU32Ptr(0x5D4594, 2618908) && *(_DWORD*)(*getMemU32Ptr(0x5D4594, 2618908) + 2092) == 1)
		result = (*(_DWORD*)(*getMemU32Ptr(0x5D4594, 2618908) + 3680) & 3) != 0;
	else
		result = 0;
	return result;
}

//----- (00437310) --------------------------------------------------------
void sub_437310() { nox_srand(0xA29u); }

//----- (00437320) --------------------------------------------------------
int __cdecl sub_437320(int a1) {
	int v1;              // eax
	unsigned __int8* v2; // ecx
	int v3;              // ecx
	int v4;              // eax
	int result;          // eax

	v1 = 0;
	v2 = getMemAt(0x587000, 87484);
	do {
		if (*(_DWORD*)(a1 + 96) <= *(int*)v2)
			break;
		v2 += 4;
		++v1;
	} while ((int)v2 < (int)getMemAt(0x587000, 87496));
	if (v1 > 2)
		v1 = 2;
	v3 = *(_DWORD*)(a1 + 28) + 36;
	v4 = 16 * v1;
	if (*(int*)&dword_587000_87412 == -1) {
		*(_DWORD*)(*(_DWORD*)(a1 + 28) + 76) = *getMemU32Ptr(0x5D4594, v4 + 814568);
		*(_DWORD*)(v3 + 24) = *getMemU32Ptr(0x5D4594, v4 + 814564);
		result = *getMemU32Ptr(0x5D4594, v4 + 814564);
	} else {
		*(_DWORD*)(*(_DWORD*)(a1 + 28) + 76) = *getMemU32Ptr(0x5D4594, v4 + 814560);
		*(_DWORD*)(v3 + 24) = *getMemU32Ptr(0x5D4594, v4 + 814556);
		result = *getMemU32Ptr(0x5D4594, v4 + 814556);
	}
	*(_DWORD*)(v3 + 48) = result;
	return result;
}

//----- (004375C0) --------------------------------------------------------
void __cdecl sub_4375C0(int a1) {
	if (dword_5d4594_815088)
		sub_46AD20(*(_DWORD**)&dword_5d4594_814980, 10070, dword_5d4594_815088 + 10069, a1);
}

//----- (004375F0) --------------------------------------------------------
int __cdecl sub_4375F0(const char* a1, __int16 a2, char* a3, int a4) {
	DWORD v4;      // edx
	int v5;        // edi
	__int16 v6;    // cx
	__int16 v7;    // ax
	int v8;        // ecx
	__int16 v9;    // ax
	int v10;       // ecx
	int v11;       // eax
	char v13[172]; // [esp+14h] [ebp-CCh]
	char v14[32];  // [esp+C0h] [ebp-20h]

	if (dword_5d4594_815088 < 0x9C4u && !dword_5d4594_815044 && !dword_5d4594_815060) {
		if (memcmp(a1, getMemAt(0x5D4594, 815108), 1u)) {
			if (*(_DWORD*)(a4 + 44) == *getMemU32Ptr(0x5D4594, 814964)) {
				if (sub_4A0410(a1, a2)) {
					memset(v13, 0, 0xA8u);
					v13[168] = 0;
					v4 = nox_get_ticks();
					v5 = *(_DWORD*)(a4 + 44);
					v6 = *(_WORD*)(a4 + 36);
					v13[101] = *(_BYTE*)(a4 + 5) | (16 * *(_BYTE*)(a4 + 6));
					v7 = *(_WORD*)(a4 + 38);
					*(_WORD*)&v13[105] = v6;
					LOBYTE(v6) = *(_BYTE*)(a4 + 21);
					*(_WORD*)&v13[107] = v7;
					LOBYTE(v7) = *(_BYTE*)(a4 + 4);
					v13[100] = *(_BYTE*)(a4 + 20) | v6;
					LOBYTE(v6) = *(_BYTE*)(a4 + 3);
					v13[104] = v7;
					LOBYTE(v7) = *(_BYTE*)(a4 + 19);
					v13[103] = v6;
					v8 = *(_DWORD*)(a4 + 32);
					v13[102] = v7;
					v9 = *(_WORD*)(a4 + 28);
					*(_DWORD*)&v13[159] = v8;
					v10 = *(_DWORD*)(a4 + 24);
					*(_WORD*)&v13[163] = v9;
					v11 = *(_DWORD*)(a4 + 40);
					*(_DWORD*)&v13[48] = v10;
					*(_DWORD*)&v13[44] = v11;
					memcpy(&v13[135], (const void*)(a4 + 48), 0x14u);
					*(_DWORD*)&v13[155] = *(_DWORD*)(a4 + 7);
					strcpy(&v13[111], (const char*)(a4 + 10));
					LOWORD(v10) = *(_WORD*)(a4 + 68);
					*(_DWORD*)&v13[96] = v4 - v5;
					*(_WORD*)&v13[165] = v10;
					if (*(int*)&dword_587000_87412 == -1 ||
						sub_437860(*(__int16*)&v13[44], *(__int16*)&v13[46]) == dword_587000_87412) {
						if (sub_4899C0((int)v13)) {
							*(_DWORD*)&v13[36] = dword_5d4594_815088;
							*(_DWORD*)&v13[28] = 0;
							strcpy(&v13[12], a1);
							*(_WORD*)&v13[109] = a2;
							strncpy(&v13[120], a3, 0xFu);
							*(_WORD*)&v13[163] = *(_WORD*)(a4 + 28);
							sub_4A0030(v13);
							v14[0] = 0;
							if (a3)
								strcpy(v14, a3);
							else
								sub_43BC80((int)a1, a2, v14);
							++dword_5d4594_815088;
						}
					}
				}
			}
		}
	}
	return 0;
}

//----- (00437860) --------------------------------------------------------
int __cdecl sub_437860(int a1, int a2) {
	int result;          // eax
	unsigned __int8* v3; // ecx

	result = 0;
	v3 = getMemAt(0x587000, 87532);
	while (a1 <= *((__int16*)v3 - 2) || a1 >= *(__int16*)v3 || a2 <= *((__int16*)v3 - 1) || a2 >= *((__int16*)v3 + 1)) {
		v3 += 8;
		++result;
		if ((int)v3 >= (int)getMemAt(0x587000, 87564))
			return 0;
	}
	return result;
}

//----- (004379C0) --------------------------------------------------------
void sub_4379C0() {
	if (dword_587000_87408 == 1)
		nox_window_call_field_94(*(int*)&dword_5d4594_815012, 16399, 0, 0);
}

//----- (00438330) --------------------------------------------------------
int sub_438330() {
	int (*v0)(void); // esi

	v0 = nox_wnd_xxx_815040->field_13;
	sub_43C570(nox_wnd_xxx_815040);
	if (!nox_common_gameFlags_check_40A5C0(0x10000000))
		sub_43A9D0();
	if (v0)
		v0();
	return 1;
}

//----- (00438370) --------------------------------------------------------
int sub_438370() {
	if (*(_BYTE*)(&nox_wnd_xxx_815040->field_16) == 1)
		return sub_438330();
	*(_BYTE*)(&nox_wnd_xxx_815040->field_16) = 2;
	sub_43BE40(2);
	sub_452D80(923, 100);
	return 1;
}

//----- (00438480) --------------------------------------------------------
int sub_438480() {
	sub_46B2C0(*(int*)&dword_5d4594_815012, sub_439050);
	sub_46B300(*(int*)&dword_5d4594_815012, sub_438EF0);
	sub_46B120(*(_DWORD**)&dword_5d4594_815016, *(int*)&dword_5d4594_815012);
	sub_46B300(*(int*)&dword_5d4594_815016, sub_438EF0);
	sub_46B120(*(_DWORD**)&dword_5d4594_815020, *(int*)&dword_5d4594_815012);
	sub_46B300(*(int*)&dword_5d4594_815020, sub_438EF0);
	sub_46B120(*(_DWORD**)&dword_5d4594_815024, *(int*)&dword_5d4594_815012);
	sub_46B300(*(int*)&dword_5d4594_815024, sub_438EF0);
	sub_46B120(*(_DWORD**)&dword_5d4594_815028, *(int*)&dword_5d4594_815012);
	sub_46B300(*(int*)&dword_5d4594_815028, sub_438EF0);
	sub_46B120(*(_DWORD**)&dword_5d4594_815032, *(int*)&dword_5d4594_815012);
	sub_46B300(*(int*)&dword_5d4594_815032, sub_438EF0);
	**(_DWORD**)(*(_DWORD*)(dword_5d4594_815004 + 32) + 28) = 10035;
	**(_DWORD**)(*(_DWORD*)(dword_5d4594_815004 + 32) + 32) = 10036;
	**(_DWORD**)(*(_DWORD*)(dword_5d4594_815004 + 32) + 36) = 10032;
	nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16408, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 28),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16408, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 28),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16408, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 28),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16408, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 28),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16408, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 28),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16409, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 32),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16409, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 32),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16409, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 32),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16409, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 32),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16409, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 32),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16410, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 36),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16410, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 36),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16410, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 36),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16410, *(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 36),
							 0);
	return nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16410,
									*(_DWORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 36), 0);
}

//----- (00438A90) --------------------------------------------------------
int sub_438A90() {
	int result;    // eax
	BOOL v3;       // eax
	int v4;        // eax
	uint16_t v5;    // [esp-10h] [ebp-74h]
	char buf[100]; // [esp+0h] [ebp-64h]

	memset(&buf[0], 0, 100);
	/*if (*/ sub_420120((LPBYTE)&buf[56]); //)
	{
		/*if ( !*(_DWORD *)&dword_587000_87404 )
		  sub_40E0D0((int)&buf[56], (LPCSTR)getMemAt(0x587000, 89088), 0);*/
		v3 = sub_40ABD0();
		buf[55] = getMemByte(0x5D4594, 2661960);
		buf[54] = getMemByte(0x5D4594, 2661958);
		buf[98] = !v3;
		*(_DWORD*)&buf[80] = 0x1039A;
		*(_DWORD*)&buf[84] = dword_5d4594_2660032;
		strcpy(&buf[88], (const char*)getMemAt(0x5D4594, 2660012 + 36));
		nox_wcscpy((wchar_t*)&buf[4], (const wchar_t*)getMemAt(0x5D4594, 2661908));
		sub_43AF90(3);
		*(_QWORD*)&qword_5d4594_814956 = sub_416BB0() + 20000;
		v5 = sub_43B320();
		v4 = sub_43B300();
		result = sub_5550A0(v4, v5, buf);
	}
	/*else
	{
	  v0 = loadString_sub_40F1D0((char *)getMemAt(0x587000, 89028), 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
	541); sub_449E00((int)v0); v1 = loadString_sub_40F1D0((char *)getMemAt(0x587000, 89076), 0,
	"C:\\NoxPost\\src\\client\\shell\\noxworld.c", 542); sub_449E30((int)v1); sub_449EA0(1); sub_43AF90(1); result =
	*(_DWORD *)&dword_587000_87404; if ( *(_DWORD *)&dword_587000_87404 == 1 ) result = sub_40D380();
	}*/
	return result;
}

//----- (00438C80) --------------------------------------------------------
int sub_438C80(int a1, int a2) {
	int2* v0;     // ebx
	char v2[404]; // [esp+4h] [ebp-194h]

	v0 = nox_client_getMousePos_4309F0();
	if (!wndIsShown_sub_46ACC0(*(int*)&dword_5d4594_815000)) {
		memcpy(v2, *(const void**)&dword_5d4594_815000, sizeof(v2));
		*(_DWORD*)&v2[16] -= 32;
		*(_DWORD*)&v2[20] -= 32;
		*(_DWORD*)&v2[8] += 64;
		*(_DWORD*)&v2[12] += 64;
		if (!dword_5d4594_815044 && !sub_46AAB0(v2, v0->field_0, v0->field_4)) {
			nox_window_set_hidden(*(int*)&dword_5d4594_815000, 1);
			nox_window_call_field_94(*(int*)&dword_5d4594_815012, 16403, -1, 0);
			dword_5d4594_815056 = 0;
			sub_46C6E0(*(int*)&dword_5d4594_815000);
			sub_46B500(*(int*)&dword_5d4594_814980);
		}
	}
	if (sub_4A28B0() && !sub_46AAB0(*(_DWORD**)getMemAt(0x5D4594, 815036), v0->field_0, v0->field_4)) {
		sub_4A2890();
		sub_46B500(*(int*)&dword_5d4594_814980);
	}
	if (dword_5d4594_815048 && sub_438DD0(v0->field_0, v0->field_4)) {
		nox_client_setCursorType_477610(9);
	} else if (!sub_44A4A0()) {
		nox_client_setCursorType_477610(0);
	}
	return 1;
}

//----- (00438DD0) --------------------------------------------------------
int __cdecl sub_438DD0(unsigned int a1, unsigned int a2) {
	if (*(int*)&dword_587000_87412 == -1) {
		if (a1 > 0xD8 && a1 < 0x258 && a2 > 0x1B && a2 < 0x1C3)
			return 1;
	} else if (a1 > 0xE2 && a1 < 0x24E && a2 > 0x25 && a2 < 0x1B9) {
		return 1;
	}
	return 0;
}

//----- (00438E30) --------------------------------------------------------
int __cdecl sub_438E30(_DWORD* a1, int a2) {
	_DWORD* v1;   // esi
	int v2;       // edx
	int v3;       // esi
	__int16** v4; // edi
	int v6;       // [esp+4h] [ebp-4h]

	v1 = a1;
	nox_client_wndGetPosition_46AA60(a1, &v6, &a1);
	v2 = v1[25];
	if (v1[9] & 6)
		nox_client_drawImageAt_47D2C0(v1[19], v6 + v1[24], (int)a1 + v2);
	else
		nox_client_drawImageAt_47D2C0(v1[15], v6 + v1[24], (int)a1 + v2);
	v3 = v1[100];
	if (!v3)
		return 1;
	do {
		if (!(*(_BYTE*)(v3 + 4) & 0x10) && *(_DWORD*)(v3 + 44) == 2048) {
			v4 = *(__int16***)(v3 + 32);
			sub_434390(*getMemIntPtr(0x5D4594, 2523948));
			sub_43F7B0(*(_DWORD*)(v3 + 236), *v4, v6 + *(_DWORD*)(v3 + 16), (int)a1 + *(_DWORD*)(v3 + 20));
		}
		v3 = *(_DWORD*)(v3 + 388);
	} while (v3);
	return 1;
}

//----- (00438EF0) --------------------------------------------------------
int __cdecl sub_438EF0(_DWORD* a1, int a2, unsigned int a3, int a4) {
	int result; // eax
	int v5;     // esi
	int v6;     // esi

	if (a2 == 19) {
		v6 = a1[8];
		nox_window_call_field_94(*(int*)&dword_5d4594_815012, 16391, *(_DWORD*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16391, *(_DWORD*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16391, *(_DWORD*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16391, *(_DWORD*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16391, *(_DWORD*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16391, *(_DWORD*)(v6 + 28), 0);
		result = 0;
	} else if (a2 == 20) {
		v5 = a1[8];
		nox_window_call_field_94(*(int*)&dword_5d4594_815012, 16391, *(_DWORD*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16391, *(_DWORD*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16391, *(_DWORD*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16391, *(_DWORD*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16391, *(_DWORD*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16391, *(_DWORD*)(v5 + 32), 0);
		result = 0;
	} else {
		result = sub_4A28E0(a1, a2, a3, a4);
	}
	return result;
}

//----- (00439050) --------------------------------------------------------
int __cdecl sub_439050(int a1, unsigned int a2, int* a3, unsigned int a4) {
	int v4;  // edi
	int v5;  // edi
	int v7;  // eax
	int2 v8; // [esp+Ch] [ebp-8h]

	if (a2 > 0x400F) {
		if (a2 == 16400) {
			v7 = sub_46B0A0(a3);
			if (v7 >= 10038 && v7 <= 10042) {
				nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16403, a4, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16403, a4, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16403, a4, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16403, a4, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16403, a4, 0);
				if (a4 < *(int*)&dword_5d4594_815088) {
					v8 = *nox_client_getMousePos_4309F0();
					dword_5d4594_814624 = sub_4A04C0(a4);
					sub_439370(&v8, *(int*)&dword_5d4594_814624);
				}
			}
		} else if (a2 == 16403 || a2 == 16412) {
			nox_window_call_field_94(*(int*)&dword_5d4594_815016, a2, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815020, a2, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815024, a2, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815028, a2, (int)a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815032, a2, (int)a3, 0);
		}
	} else if (a2 >= 0x400E) {
		nox_window_call_field_94(*(int*)&dword_5d4594_815016, a2, (int)a3, a4);
		nox_window_call_field_94(*(int*)&dword_5d4594_815020, a2, (int)a3, a4);
		nox_window_call_field_94(*(int*)&dword_5d4594_815024, a2, (int)a3, a4);
		nox_window_call_field_94(*(int*)&dword_5d4594_815028, a2, (int)a3, a4);
		nox_window_call_field_94(*(int*)&dword_5d4594_815032, a2, (int)a3, a4);
	} else {
		switch (a2) {
		case 0x17u:
			return 1;
		case 0x4000u:
			if (a3 == sub_46B0C0(*(_DWORD**)&dword_5d4594_815012, 10043) ||
				a3 == sub_46B0C0(*(_DWORD**)&dword_5d4594_815012, 10044)) {
				nox_window_call_field_94(*(int*)&dword_5d4594_815016, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815020, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815024, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815028, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815032, 0x4000, (int)a3, 0);
			}
			break;
		case 0x4009u:
			v4 = *(_DWORD*)(a1 + 32);
			sub_4A30D0(a1, 0x4009u, (wchar_t*)a3, a4);
			v5 = sub_4A4800(v4);
			nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16412, v5, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16412, v5, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16412, v5, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16412, v5, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16412, v5, 0);
			break;
		}
	}
	return sub_4A30D0(a1, a2, (wchar_t*)a3, a4);
}

// 439385: variable 'v2' is possibly undefined

//----- (00439450) --------------------------------------------------------
_DWORD* __cdecl sub_439450(int a1, int a2, _DWORD* a3) {
	_DWORD* result; // eax
	int v4;         // ecx

	result = a3;
	*a3 = a1 - 65;
	a3[1] = a2 - 20;
	if (a1 - 65 + 130 > 600)
		*a3 = 470;
	if (a2 - 20 + 120 > 451)
		a3[1] = 331;
	if (dword_587000_87408 == 1) {
		v4 = 55;
		if (a3[1] >= 55)
			goto LABEL_10;
	} else {
		v4 = 27;
		if (a3[1] >= 27)
			goto LABEL_10;
	}
	a3[1] = v4;
LABEL_10:
	if ((int)*a3 < 216)
		*a3 = 216;
	return result;
}

//----- (00439CC0) --------------------------------------------------------
char* __cdecl sub_439CC0(int a1, char* a2) {
	size_t v2;    // esi
	char* result; // eax

	v2 = (size_t)&strstr((const char*)(a1 + 52), "'s_game")[-52 - a1];
	result = strncpy(a2, (const char*)(a1 + 52), v2);
	a2[v2] = 0;
	return result;
}

//----- (00439D00) --------------------------------------------------------
int __cdecl sub_439D00(int* a1, int a2, unsigned int a3, int a4) {
	int2* v4; // eax

	if (a2 == 5) {
		if (sub_46B0A0(a1) == 10020 && dword_5d4594_815048 == 1) {
			sub_439D90((unsigned __int16)a3, a3 >> 16);
			return 1;
		}
		return 0;
	}
	if (a2 != 21)
		return 0;
	if (a3 != 1) {
		if (a3 != 28 && a3 == 57) {
			v4 = nox_client_getMousePos_4309F0();
			nox_window_call_field_93((int)a1, 5, v4->field_0 | (v4->field_4 << 16), 0);
		}
		return 0;
	}
	if (a4 == 2)
		sub_4373A0();
	return 1;
}

//----- (00439D90) --------------------------------------------------------
int __cdecl sub_439D90(unsigned int a1, unsigned int a2) {
	int result; // eax
	__int16 v3; // dx

	result = sub_438DD0(a1, a2);
	if (result) {
		v3 = a2 + *getMemU16Ptr(0x587000, 8 * dword_587000_87412 + 87530) - 27;
		*getMemU16Ptr(0x5D4594, 814916) = a1 + *getMemU16Ptr(0x587000, 8 * dword_587000_87412 + 87528) - 216;
		*getMemU16Ptr(0x5D4594, 814918) = v3;
		sub_43B460();
		if (sub_43BDB0() & 2)
			sub_4D6F60(1);
		if (sub_4D6F50()) {
			if (sub_4DC7D0()) {
				sub_4A7A70(1);
				sub_4A4DB0();
				return nox_client_setCursorType_477610(0);
			}
		} else if (sub_4DC630()) {
			sub_4A7A70(1);
			sub_4A4DB0();
			return nox_client_setCursorType_477610(0);
		}
		sub_4A7A70(0);
		sub_4A4840();
		result = nox_client_setCursorType_477610(0);
	}
	return result;
}

// 43A3CE: variable 'v22' is possibly undefined

//----- (0043A920) --------------------------------------------------------
int sub_43A920() {
	int result; // eax

	sub_46B500(*(int*)&dword_5d4594_814980);
	if (dword_587000_87404 == 1) {
		sub_554D10();
		nox_set_draw_unk1(sub_41E210);
	}
	if (!sub_43BE30() || !*getMemU32Ptr(0x5D4594, 815084))
		sub_44A400();
	result = sub_43AF90(0);
	dword_5d4594_815044 = 0;
	return result;
}

//----- (0043A9D0) --------------------------------------------------------
int sub_43A9D0() {
	sub_46ADE0(*(int*)&dword_5d4594_814984);
	sub_489FB0();
	sub_4A2890();
	if (dword_5d4594_815000 && !*(_DWORD*)(dword_5d4594_815000 + 396)) {
		sub_46C6E0(*(int*)&dword_5d4594_815000);
		sub_46C4E0(*(_DWORD**)&dword_5d4594_815000);
		dword_5d4594_815000 = 0;
	}
	if (dword_5d4594_814980) {
		sub_46C4E0(*(_DWORD**)&dword_5d4594_814980);
		dword_5d4594_814980 = 0;
	}
	sub_43A920();
	sub_46B500(0);
	dword_5d4594_815088 = 0;
	sub_49FFA0(0);
	sub_554D10();
	nox_client_setCursorType_477610(0);
	return sub_43DE40(0);
}

//----- (0043AA70) --------------------------------------------------------
char* sub_43AA70() {
	char* v0;      // esi
	char* v1;      // ebx
	char* v2;      // eax
	char v3;       // al
	char v4;       // al
	char v5;       // cl
	char* v6;      // eax
	char* result;  // eax
	__int16 v8;    // cx
	char v9[32];   // [esp+0h] [ebp-12Ch]
	char v10[268]; // [esp+20h] [ebp-10Ch]

	if (dword_5d4594_528252 && dword_5d4594_528256)
		sub_413D30((char*)getMemAt(0x587000, 90708));
	dword_5d4594_815048 = 0;
	dword_5d4594_815052 = 1;
	v0 = sub_416590(0);
	v1 = sub_416640();
	memcpy(v1 + 111, v0, 0x3Au);
	*(_WORD*)(v1 + 163) = nox_common_gameFlags_getVal_40A5B0();
	*(_DWORD*)(v1 + 135) = -1;
	*(_DWORD*)(v1 + 139) = -1;
	*(_DWORD*)(v1 + 143) = -1;
	*(_DWORD*)(v1 + 147) = -1;
	*(_DWORD*)(v1 + 151) = -1;
	*(_DWORD*)(v1 + 155) = -1;
	*(_DWORD*)(v1 + 159) = -1;
	v2 = sub_40A4C0();
	strncpy(v1 + 120, v2, 0xFu);
	strcpy(v1 + 111, sub_409B40());
	if (sub_4D6F50()) {
		if (dword_5d4594_528256)
			*(_WORD*)(v1 + 165) = sub_4E3CC0();
		else
			*(_WORD*)(v1 + 165) = 1;
	}
	v1[104] = sub_409FA0();
	v3 = nox_common_playerInfoCount_416F40();
	v1[103] = v3;
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		v1[103] = v3 - 1;
		--v1[104];
	}
	v4 = sub_43BE50_get_video_mode_id();
	v5 = v1[102];
	*((_DWORD*)v1 + 12) = 66458;
	v1[102] = v5 & 0x80 | v4;
	*((_DWORD*)v1 + 11) = *getMemU32Ptr(0x5D4594, 814916);
	*(_WORD*)(v1 + 109) = sub_40A430();
	sub_435720((char*)getMemAt(0x587000, 90740));
	if (dword_587000_87404 == 1) {
		memset(v10, 0, sizeof(v10));
		v6 = sub_41FA40();
		nox_sprintf(v9, "%s%s", v6, getMemAt(0x587000, 90752));
		strcpy(&v10[52], v9);
		*(_DWORD*)v10 = sub_420100();
		*(_DWORD*)&v10[4] = 1;
		*(_DWORD*)&v10[8] = 32;
		*(_DWORD*)&v10[12] = 0;
		*(_DWORD*)&v10[16] = 0;
		*(_DWORD*)&v10[20] = 1;
		*(_DWORD*)&v10[24] = 1;
		*(_DWORD*)&v10[44] = 0;
		*(_DWORD*)&v10[28] = 0;
		*(_DWORD*)&v10[224] = 66458;
		*(_DWORD*)&v10[32] = *getMemU32Ptr(0x5D4594, 814916);
		v10[sub_425550(v1 + 100, &v10[69], 552) + 69] = 0;
		sub_40D320((int)v10);
	}
	result = sub_416590(1);
	v8 = *((_WORD*)result + 26) & 0xE90F;
	HIBYTE(v8) |= 1u;
	*((_WORD*)result + 26) = v8;
	return result;
}

//----- (0043ACC0) --------------------------------------------------------
void sub_43ACC0() {
	char* v0;          // eax
	int i;             // ebp
	int v2;            // eax
	struct in_addr v3; // eax
	char* v4;          // eax
	int v5;            // eax
	int v6;            // esi
	_DWORD* v7;        // eax
	_DWORD* v8;        // eax
	char v9[172];      // [esp+0h] [ebp-ECh]
	char v10[32];      // [esp+ACh] [ebp-40h]
	char v11[32];      // [esp+CCh] [ebp-20h]

	if (!dword_5d4594_815088 && !dword_5d4594_815044) {
		v0 = sub_41FA40();
		nox_sprintf(v11, "%s%s", v0, getMemAt(0x587000, 90768));
		for (i = sub_41F0E0(); i; i = sub_41F0C0()) {
			if (strcmp(v11, (const char*)(i + 52))) {
				memset(v9, 0, 0xA8u);
				v9[168] = 0;
				sub_4255F0((_BYTE*)(i + 69), &v9[100], 552);
				*(_DWORD*)&v9[96] = 9999;
				if ((int)*(_DWORD*)(i + 40) >= 0)
					*(_DWORD*)&v9[96] = *(_DWORD*)(i + 40);
				v2 = *(_DWORD*)(i + 32);
				*(_DWORD*)&v9[44] = *(_DWORD*)(i + 32);
				*(_DWORD*)&v9[48] = *(_DWORD*)(i + 224);
				if (*(int*)&dword_587000_87412 == -1 ||
					sub_437860((__int16)v2, *(__int16*)&v9[46]) == *(int*)&dword_587000_87412) {
					if (sub_4899C0((int)v9)) {
						v3.S_un.S_addr = htonl(*(_DWORD*)(i + 36));
						v4 = inet_ntoa(v3);
						*(_DWORD*)&v9[12] = *(_DWORD*)v4;
						*(_DWORD*)&v9[16] = *((_DWORD*)v4 + 1);
						*(_DWORD*)&v9[20] = *((_DWORD*)v4 + 2);
						v5 = *((_DWORD*)v4 + 3);
						*(_DWORD*)&v9[32] = i;
						*(_DWORD*)&v9[24] = v5;
						*(_DWORD*)&v9[36] = dword_5d4594_815088;
						*(_DWORD*)&v9[44] = *(_DWORD*)(i + 32);
						sub_4A0030(v9);
						if (v9[120]) {
							strncpy(v10, &v9[120], 0xFu);
							v10[15] = 0;
						} else {
							sub_43BC80((int)&v9[12], *(unsigned __int16*)&v9[109], v10);
						}
						if (++dword_5d4594_815088 >= 0x9C4u)
							break;
					}
				}
			}
		}
		if (dword_5d4594_815088)
			sub_4A0360();
		sub_44A400();
		if (nox_common_gameFlags_check_40A5C0(0x2000000) && *(int*)&dword_587000_87412 == -1) {
			v6 = sub_4A7F20() + 10053;
			v7 = sub_46B0C0(*(_DWORD**)&dword_5d4594_814980, 10002);
			nox_window_call_field_94(*(int*)&dword_5d4594_814980, 16391, (int)v7, 0);
			v8 = sub_46B0C0(*(_DWORD**)&dword_5d4594_814980, v6);
			nox_window_call_field_94(*(int*)&dword_5d4594_814980, 16391, (int)v8, 0);
		}
		if (dword_5d4594_815048)
			sub_4375C0(0);
	}
}

//----- (0043AF30) --------------------------------------------------------
int sub_43AF30() { return dword_5d4594_815052; }

//----- (0043AF40) --------------------------------------------------------
int sub_43AF40() { return dword_5d4594_815048; }

//----- (0043AF50) --------------------------------------------------------
int __cdecl sub_43AF50(int a1) {
	int result; // eax

	result = a1;
	dword_587000_87404 = a1;
	dword_5d4594_2650652 = a1 == 1;
	return result;
}

//----- (0043AF70) --------------------------------------------------------
int sub_43AF70() { return dword_587000_87404; }

//----- (0043AF80) --------------------------------------------------------
int sub_43AF80() { return dword_5d4594_814548; }

//----- (0043AF90) --------------------------------------------------------
int __cdecl sub_43AF90(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_814548 = a1;
	return result;
}

//----- (0043AFA0) --------------------------------------------------------
int __cdecl sub_43AFA0(int a1) {
	dword_5d4594_814552 = a1;
	return sub_43AF90(2);
}

//----- (0043AFC0) --------------------------------------------------------
void __cdecl sub_43AFC0(int a1) {
	int* v1;  // esi
	int v3;   // edi
	int v4;   // eax
	int v5;   // edx
	int v6;   // ecx
	int v7;   // edi
	int v8;   // eax
	int v9;   // ecx
	int2 v10; // [esp+4h] [ebp-8h]

	v1 = sub_4A04F0((char*)(a1 + 52));
	if (!v1) {
		sub_43AFA0(9);
		return;
	}
	if (!dword_587000_87408) {
		sub_43A920();
		v10.field_0 = *((__int16*)v1 + 22) + 216;
		v10.field_4 = *((__int16*)v1 + 23) + 27;
		dword_5d4594_814624 = v1;
		sub_439370(&v10, (int)v1);
		sub_430B10_set_mouse_pos(v10.field_0, v10.field_4);
		return;
	}
	sub_43A920();
	v3 = sub_4A0330(v1);
	nox_window_call_field_94(*(int*)&dword_5d4594_815012, 16403, v3, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815012, 16412, v3, 0);
	v4 = *(_DWORD*)(dword_5d4594_815016 + 32);
	v10.field_0 = *(_DWORD*)(dword_5d4594_815016 + 16) + 216;
	v5 = *(_DWORD*)(dword_5d4594_815016 + 20);
	v6 = 131 * *(_DWORD*)(v4 + 48);
	v7 = *(_DWORD*)(v4 + 24);
	v8 = *(__int16*)(v4 + 54);
	v9 = *(_DWORD*)(v7 + 4 * v6);
	dword_5d4594_814624 = v1;
	v10.field_4 = v9 - v8 + v5 + 27;
	sub_439370(&v10, (int)v1);
	sub_430B10_set_mouse_pos(v10.field_0, v10.field_4);
}

//----- (0043B0E0) --------------------------------------------------------
void __cdecl sub_43B0E0(int a1) {
	int i;   // ebx
	int* v2; // eax
	int v3;  // esi
	int v4;  // eax
	int v5;  // edi
	int v6;  // ebp

	for (i = a1; i; i = *(_DWORD*)(i + 48)) {
		v2 = sub_4A04F0((char*)(i + 52));
		v3 = (int)v2;
		if (v2) {
			if (v2[24] == 9999) {
				v4 = *(_DWORD*)(i + 40);
				if (v4 >= 0) {
					*(_DWORD*)(v3 + 96) = v4;
					v5 = sub_4A0330((int*)v3);
					if (dword_587000_87408 == 1) {
						if (sub_4899C0(v3)) {
							nox_swprintf((wchar_t*)getMemAt(0x5D4594, 814756), L"%d", *(_DWORD*)(v3 + 96));
							nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16407, (int)getMemAt(0x5D4594, 814756), v5);
							if (sub_4A0560() == 6 || sub_4A0560() == 7) {
								sub_425920((_DWORD**)v3);
								v6 = sub_4A0030((const void*)v3);
								nox_window_call_field_94(*(int*)&dword_5d4594_815012, 16398, v5, 0);
								sub_43B2A0(v6);
								sub_43B7C0(v3);
							}
						} else {
							nox_window_call_field_94(*(int*)&dword_5d4594_815012, 16398, v5, 0);
							sub_4A0540((LPVOID)v3);
						}
					} else if (sub_4899C0(v3)) {
						if (*(_BYTE*)(v3 + 120)) {
							strncpy((char*)getMemAt(0x5D4594, 814920), (const char*)(v3 + 120), 0xFu);
							*getMemU8Ptr(0x5D4594, 814935) = 0;
						} else {
							sub_43BC80(v3 + 12, *(_WORD*)(v3 + 109), (char*)getMemAt(0x5D4594, 814920));
						}
						if (*(_DWORD*)(v3 + 96) == 9999)
							nox_swprintf((wchar_t*)getMemAt(0x5D4594, 814628), L"%S -- ms", getMemAt(0x5D4594, 814920));
						else
							nox_swprintf((wchar_t*)getMemAt(0x5D4594, 814628), L"%S %dms", getMemAt(0x5D4594, 814920),
										 *(_DWORD*)(v3 + 96));
						sub_46B000((wchar_t*)(*(_DWORD*)(v3 + 28) + 36), (wchar_t*)getMemAt(0x5D4594, 814628));
						sub_437320(v3);
					} else {
						sub_4A0540((LPVOID)v3);
					}
				}
			}
		}
	}
}

//----- (0043B2A0) --------------------------------------------------------
int __cdecl sub_43B2A0(int a1) {
	int result; // eax

	result = a1;
	*(_WORD*)(*(_DWORD*)(dword_5d4594_815012 + 32) + 46) = a1;
	*(_WORD*)(*(_DWORD*)(dword_5d4594_815016 + 32) + 46) = a1;
	*(_WORD*)(*(_DWORD*)(dword_5d4594_815020 + 32) + 46) = a1;
	*(_WORD*)(*(_DWORD*)(dword_5d4594_815024 + 32) + 46) = a1;
	*(_WORD*)(*(_DWORD*)(dword_5d4594_815028 + 32) + 46) = a1;
	*(_WORD*)(*(_DWORD*)(dword_5d4594_815032 + 32) + 46) = a1;
	return result;
}

//----- (0043B300) --------------------------------------------------------
unsigned int sub_43B300() {
	unsigned int result; // eax

	if (dword_5d4594_815056)
		result = inet_addr((const char*)(dword_5d4594_814624 + 12));
	else
		result = 0;
	return result;
}

//----- (0043B320) --------------------------------------------------------
int sub_43B320() { return dword_5d4594_815056 != 0 ? *getMemU32Ptr(0x5D4594, 814604) : 0; }

//----- (0043B340) --------------------------------------------------------
int sub_43B340() {
	int result; // eax

	if (dword_5d4594_815056)
		result = *(unsigned __int16*)(dword_5d4594_814624 + 163);
	else
		result = 0;
	return result;
}

//----- (0043B360) --------------------------------------------------------
int sub_43B360() // client connecting draw handler
{
	char* v0;            // ebx
	unsigned __int16 v1; // ax
	char v2;             // al
	char v5[32];         // [esp+0h] [ebp-20h]

	sub_40A4D0(4);
	nox_common_gameFlags_unset_40A540(1);
	v0 = (char*)(dword_5d4594_814624 + 12);
	if (!memcmp((const void*)(dword_5d4594_814624 + 12), getMemAt(0x5D4594, 815116), 1u)) {
		sub_435720((char*)getMemAt(0x587000, 90828));
	} else {
		v1 = sub_43B320();
		nox_sprintf(v5, "%s:%d", v0, v1);
		sub_431790(v5);
		sub_435720(v0);
	}
	nox_common_writecfgfile((char*)getMemAt(0x587000, 90848));
	v2 = *(_BYTE*)(dword_5d4594_814624 + 102);
	nox_video_mode* v3;
	if (v2 < 0 && (v3 = sub_43BE80_video_mode_by_id(v2 & 0x7F)) != 0)
		sub_430C30_set_video_max(v3->width, v3->height);
	else
		sub_430C30_set_video_max(NOX_MAX_WIDTH, NOX_MAX_HEIGHT);
	sub_44A400();
	sub_43A9D0();
	sub_4A24A0();
	return 1;
}

//----- (0043B440) --------------------------------------------------------
int sub_43B440() {
	if (dword_587000_87404 == 1)
		sub_554B40(0);
	sub_438A90();
	return 1;
}

//----- (0043B460) --------------------------------------------------------
int sub_43B460() {
	sub_438370();
	nox_wnd_xxx_815040->field_14 = sub_43B490;
	sub_46C6E0(*(int*)&dword_5d4594_815000);
	return sub_46ABB0(*(int*)&dword_5d4594_814984, 0);
}

//----- (0043B490) --------------------------------------------------------
int sub_43B490() {
	if (sub_43BE10() == 1700)
		return sub_438330();
	nox_window_set_hidden(*(int*)&dword_5d4594_814980, 1);
	nox_window_set_hidden(*(int*)&dword_5d4594_815000, 1);
	nox_client_setCursorType_477610(0);
	return 1;
}

//----- (0043B4D0) --------------------------------------------------------
_DWORD* sub_43B4D0() {
	if (dword_5d4594_815048) {
		sub_43B510();
		sub_43A9D0();
		sub_4A24A0();
		sub_501AC0(0);
	} else {
		sub_43B630();
		sub_43B440();
	}
	return sub_49FF20();
}
