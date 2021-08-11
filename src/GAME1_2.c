#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "client__audio__auddiag.h"
#include "client__system__parsecmd.h"
#include "common__system__settings.h"
#include "common__system__team.h"
#include "common__net_list.h"

#include "client__drawable__drawdb.h"
#include "client__gui__gamewin__gamewin.h"
#include "client__gui__guiggovr.h"
#include "client__gui__guiquit.h"
#include "client__gui__window.h"
#include "client__video__draw_common.h"
#include "client__shell__noxworld.h"
#include "client__shell__selchar.h"
#include "client__system__client.h"
#include "client__system__ctrlevnt.h"
#include "common__magic__comguide.h"

#include "client__draw__partscrn.h"
#include "client__gui__guicon.h"

#include "common/fs/nox_fs.h"
#include "common__log.h"
#include "input.h"
#include "proto.h"

#include <time.h>

extern unsigned char byte_5D4594_3804364[160];

extern _DWORD dword_5d4594_787188;
extern _DWORD nox_xxx_useAudio_587000_80772;
extern _DWORD dword_5d4594_811904;
extern _DWORD dword_5d4594_805988;
extern _DWORD dword_5d4594_3805492;
extern _DWORD dword_5d4594_811896;
extern _DWORD dword_5d4594_805820;
extern _DWORD dword_5d4594_741648;
extern _DWORD dword_5d4594_815060;
extern _DWORD dword_5d4594_815052;
extern _DWORD dword_5d4594_805980;
extern _DWORD dword_5d4594_741652;
extern _DWORD dword_5d4594_787192;
extern _DWORD dword_5d4594_3807116;
extern _DWORD dword_5d4594_787224;
extern _DWORD nox_video_bag_flag_754144;
extern _DWORD dword_5d4594_810628;
extern _DWORD dword_5d4594_808564;
extern _DWORD dword_5d4594_741680;
extern _DWORD dword_5d4594_1193336;
extern _DWORD dword_5d4594_3807152;
extern _DWORD dword_5d4594_3807136;
extern _DWORD dword_5d4594_3805484;
extern _DWORD dword_5d4594_814548;
extern _DWORD dword_5d4594_3804684;
extern _DWORD nox_xxx_useMMX_587000_80800;
extern _DWORD dword_5d4594_3807140;
extern _DWORD dword_5d4594_814552;
extern _DWORD dword_5d4594_815056;
extern _DWORD dword_5d4594_808568;
extern _DWORD nox_video_bag_tmpBufSize_787184;
extern _DWORD dword_5d4594_2660032;
extern _DWORD nox_client_gui_flag_1556112;
extern _DWORD dword_5d4594_787180;
extern _DWORD nox_video_bag_ready;
extern _DWORD dword_5d4594_741356;
extern _DWORD dword_5d4594_741332;
extern _DWORD dword_5d4594_741364;
extern _DWORD dword_5d4594_787212;
extern int nox_video_16bit;
extern nox_gui_animation* nox_wnd_xxx_815040;
extern _DWORD dword_5d4594_805984;
extern _DWORD dword_5d4594_3804668;
extern _DWORD dword_5d4594_810636;
extern _DWORD dword_5d4594_805836;
extern _DWORD dword_587000_87408;
extern _DWORD dword_5d4594_3798812;
extern _DWORD dword_5d4594_3798800;
extern void* dword_587000_81128;
extern void* dword_587000_122852;
extern _DWORD dword_5d4594_528252;
extern void* nox_alloc_screenParticles_806044;
extern _DWORD dword_5d4594_3798828;
extern _QWORD qword_5d4594_814956;
extern void* dword_587000_93164;
extern _DWORD dword_5d4594_815044;
extern _DWORD nox_wol_server_result_cnt_815088;
extern void* dword_587000_127004;
extern _DWORD dword_5d4594_814624;
extern _DWORD cpuid_5d4594_3801804;
extern _DWORD dword_5d4594_528256;
extern _DWORD dword_5d4594_3798816;
extern _DWORD dword_5d4594_3798808;
extern _DWORD dword_5d4594_3798832;
#ifndef NOX_CGO
_DWORD dword_5d4594_2618912 = 0;
_DWORD nox_game_playState_811372 = 0;
#endif // NOX_CGO
extern int dword_5d4594_3799524;
extern _DWORD dword_5d4594_815032;
extern _DWORD dword_5d4594_810640;
extern _DWORD dword_5d4594_815020;
extern _DWORD dword_5d4594_815024;
extern _DWORD dword_5d4594_815028;
extern _DWORD dword_5d4594_3798836;
extern _DWORD dword_5d4594_814984;
extern _DWORD dword_5d4594_815016;
extern _DWORD nox_gameDisableMapDraw_5d4594_2650672;
extern _DWORD nox_game_createOrJoin_815048;
extern _DWORD dword_5d4594_3798804;
extern _DWORD dword_587000_87404;
extern _DWORD dword_587000_87412;
extern _DWORD dword_5d4594_3798820;
extern _DWORD dword_5d4594_3798824;
extern _DWORD dword_5d4594_815000;
extern _DWORD dword_5d4594_741676;
extern _DWORD dword_5d4594_3798840;
extern _DWORD dword_5d4594_3799624;
extern _DWORD dword_5d4594_3801780;
extern _DWORD dword_5d4594_810632;
extern _DWORD nox_client_renderGUI_80828;
extern _DWORD dword_5d4594_3798796;
extern _DWORD nox_wol_wnd_gameList_815012;
extern nox_window* dword_5d4594_815004;
extern _DWORD dword_5d4594_2650652;
extern _DWORD dword_5d4594_3798844;
extern nox_window* nox_wol_wnd_world_814980;
extern int nox_enable_audio;
extern unsigned int nox_frame_xxx_2598000;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

extern float input_sensitivity;

#ifndef NOX_CGO
int nox_max_width = NOX_MAX_WIDTH;
int nox_max_height = NOX_MAX_HEIGHT;
#endif // NOX_CGO
int nox_win_width = 0;
int nox_win_height = 0;

FILE* nox_video_bag_fileptr = 0;

extern nox_ctrlevent_xxx_t nox_ctrlevent_buf_747884[NOX_CTRLEVENT_XXX_MAX];
extern nox_ctrlevent_code_info_t nox_ctrlevent_code_infos[];

obj_5D4594_754088_t* ptr_5D4594_754088 = 0;
int ptr_5D4594_754088_cnt = 0;

obj_5D4594_754088_t* ptr_5D4594_754092 = 0;
int ptr_5D4594_754092_cnt = 0;

int obj_5D4594_754104_switch = 0;

obj_5D4594_3799572_t* ptr_5D4594_3799572 = 0;

nox_screenParticle* nox_screenParticles_head = 0;
nox_screenParticle* dword_5d4594_806052 = 0;

nox_draw_viewport_t nox_draw_viewport = {0};

int nox_video_bag_var_2650640 = 0;
int nox_video_bag_var_787176 = 0;

int nox_video_bag_sections_cnt = 0;
int nox_video_bag_images_cnt = 0;

nox_things_imageRef_t* nox_images_arr1_787156 = 0;
int nox_images_cnt1_787160 = 0;
int nox_images_ind1_787164 = 0;

void* nox_video_bag_ptr_787200 = 0;
nox_video_bag_section_t* nox_video_bag_sections_arr = 0;
nox_video_bag_image_t* nox_video_bag_images_arr = 0;
void* nox_video_bag_tmpBuf_787208 = 0;

#ifndef NOX_CGO
char nox_clientServerAddr[32] = "localhost";
#endif // NOX_CGO

//----- (00427F30) --------------------------------------------------------
int  nox_xxx_wallMath_427F30(int2* a1, int* a2) {
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
int  sub_4280E0(int2* a1, _DWORD* a2) {
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
int  sub_428170(_DWORD* a1, int4* a2) {
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
int  sub_4281F0(int2* a1, int4* a2) {
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
BOOL  sub_428220(float2* a1, float4* a2) {
	return a1->field_0 >= (double)a2->field_0 && a1->field_0 <= (double)a2->field_8 &&
		   a1->field_4 >= (double)a2->field_4 && a1->field_4 <= (double)a2->field_C;
}

//----- (00428270) --------------------------------------------------------
void  nox_shape_box_calc(nox_shape* s) {
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
char*  sub_4282D0(char* a1, int a2) {
	char* result; // eax

	result = strncpy((char*)getMemAt(0x5D4594, 741316), a1, 0x10u);
	*getMemU32Ptr(0x5D4594, 741304) = a2;
	return result;
}

//----- (004282F0) --------------------------------------------------------
void*  sub_4282F0(int a1, int a2, size_t a3) {
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
unsigned int  sub_428540(int a1, char* a2, int a3) {
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
char*  sub_4285C0(__int16* a1) {
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

	result = (char*)nox_xxx_player_4E3CE0();
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
					v13 = nox_xxx_net_getIP_554200((unsigned __int8)v12[2064] + 1);
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
BOOL  sub_428810(int a1, int a2) {
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
BOOL  sub_428890(__int16* a1) {
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
LPVOID  sub_428910(LPVOID* a1) {
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
LPVOID  sub_4289D0(LPVOID* a1) {
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
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 2u);
	if ((__int16)v11 > 1)
		return 0;
	sub_42BFB0();
	if (*getMemU32Ptr(0x973F18, 3872)) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 2u);
		for (i = 0; (unsigned __int16)i < (unsigned __int16)v9; ++i) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v10, 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v12, (unsigned __int8)v8);
			v12[(unsigned __int8)v8] = 0;
			if (!nox_common_gameFlags_check_40A5C0(2) || nox_common_gameFlags_check_40A5C0(1))
				v7 = nox_xxx_getNameId_4E3AA0(v12);
			else
				v7 = nox_xxx_getTTByNameSpriteMB_44CFC0(v12);
			sub_42C310(v7, v10);
		}
		return 1;
	}
	sub_42BFE0();
	LOWORD(v1) = sub_42C300();
	v9 = v1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 2u);
	v2 = 0;
	if (!nox_xxx_unitDefGetCount_4E3AC0())
		return 1;
	v3 = 0;
	do {
		LOWORD(v4) = sub_42C2E0(v3);
		v10 = v4;
		if ((_WORD)v4) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v10, 2u);
			v5 = nox_xxx_objectTypeByInd_4E3B70(v3);
			LOBYTE(v8) = strlen(*(const char**)(v5 + 4));
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(*(_BYTE**)(v5 + 4), (unsigned __int8)v8);
		}
		v3 = ++v2;
	} while (v2 < (unsigned int)nox_xxx_unitDefGetCount_4E3AC0());
	return 1;
}
// 428B85: variable 'v1' is possibly undefined
// 428BAB: variable 'v4' is possibly undefined
// 428B30: using guessed type char var_100[256];

//----- (00428CD0) --------------------------------------------------------
int  nox_server_mapRWPolygons_428CD0(int a1) {
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
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v26, 2u);
	if ((__int16)v26 > 4)
		return 0;
	if (*getMemU32Ptr(0x973F18, 3872)) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v25, 4u);
		v9 = 1;
		if (v25 >= 1) {
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v29, 8u);
				if (!nox_xxx_polygonSetAngle_420D40(SLODWORD(v29[0]), SLODWORD(v29[1]), v9, a1))
					return 0;
				if ((__int16)v26 < 3)
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v31, 4u);
			} while (++v9 <= v25);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v25, 4u);
		v28 = 1;
		if (v25 >= 1) {
			do {
				v10 = sub_421230();
				if (!v10)
					return 0;
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v10 + 4, (unsigned __int8)v27);
				v10[(unsigned __int8)v27 + 4] = 0;
				if ((__int16)v26 >= 3 || (nox_xxx_fileReadWrite_426AC0_file3_fread(&v31, 4u), nox_xxx_fileReadWrite_426AC0_file3_fread(v32, 0xCu),
										  v10[104] = v32[0], v10[105] = v32[4], v10[106] = v32[8], (__int16)v26 >= 3)) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
					v10[104] = a1;
					nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
					v10[105] = a1;
					nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
					v10[106] = a1;
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread(v10 + 130, 1u);
				v11 = v10 + 128;
				nox_xxx_fileReadWrite_426AC0_file3_fread(v10 + 128, 2u);
				v12 = calloc(*((unsigned __int16*)v10 + 64), 4u);
				*((_DWORD*)v10 + 27) = v12;
				if (!v12)
					return 0;
				nox_xxx_fileReadWrite_426AC0_file3_fread(v12, 4 * (unsigned __int16)*v11);
				sub_421040((int)v10);
				v13 = nox_xxx_polygonGetAngle_421030(**((_DWORD**)v10 + 27));
				*((_DWORD*)v10 + 22) = nox_float2int(*((float*)v13 + 1));
				*((_DWORD*)v10 + 23) = nox_float2int(*((float*)v13 + 2));
				*((_DWORD*)v10 + 24) = nox_float2int(*((float*)v13 + 1));
				v14 = nox_float2int(*((float*)v13 + 2));
				v15 = 1;
				v16 = *v11 <= 1u;
				*((_DWORD*)v10 + 25) = v14;
				if (!v16) {
					do {
						v17 = nox_xxx_polygonGetAngle_421030(*(_DWORD*)(*((_DWORD*)v10 + 27) + 4 * v15));
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
					nox_xxx_xferReadScriptHandler_4F5580((int)(v10 + 112), *(char**)v10);
					if (v22)
						v23 = v22 + 128;
					else
						v23 = 0;
					nox_xxx_xferReadScriptHandler_4F5580((int)(v10 + 120), v23);
				}
				if ((__int16)v26 >= 4) {
					v24 = v10 + 132;
					nox_xxx_fileReadWrite_426AC0_file3_fread(v24, 4u);
					if (*v24 & 1)
						++v30;
				}
			} while (++v28 <= v25);
		}
		sub_4D72D0(v30);
		return 1;
	}
	v25 = 0;
	for (i = nox_xxx_polygon_420CA0(); i; ++v25)
		i = nox_xxx_polygon_420CD0(i);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v25, 4u);
	v3 = nox_xxx_polygon_420CA0();
	for (j = 0; j < v25; ++j) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(v3, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v3 + 4, 8u);
		v3 = nox_xxx_polygon_420CD0(v3);
	}
	v25 = 0;
	for (k = nox_xxx_polygonGetNext_4210A0(); k; ++v25)
		k = sub_4210E0((int)k);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v25, 4u);
	v6 = nox_xxx_polygonGetNext_4210A0();
	v28 = 0;
	if (v25 <= 0)
		return 1;
	do {
		v7 = *(char**)v6;
		LOBYTE(v27) = strlen(v6 + 4);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v6 + 4, (unsigned __int8)v27);
		LOBYTE(a1) = v6[104];
		nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
		LOBYTE(a1) = v6[105];
		nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
		LOBYTE(a1) = v6[106];
		nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v6 + 130, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v6 + 128, 2u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(*((_BYTE**)v6 + 27), 4 * *((unsigned __int16*)v6 + 64));
		nox_xxx_xferReadScriptHandler_4F5580((int)(v6 + 112), v7);
		if (v7)
			v8 = v7 + 128;
		else
			v8 = 0;
		nox_xxx_xferReadScriptHandler_4F5580((int)(v6 + 120), v8);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v6 + 132, 4u);
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
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v2, 2u);
	if ((__int16)v2 < 1)
		return 0;
	if (*getMemU32Ptr(0x973F18, 3872)) {
		if (*getMemU32Ptr(0x973F18, 3872) == 1) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v3[0], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v3[1], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v3[2], 4u);
			sub_469B90(v3);
			if (nox_common_gameFlags_check_40A5C0(2097154))
				sub_4349C0(v3);
		}
		result = 1;
	} else {
		v1 = nox_xxx_getAmbientColor_469BB0();
		nox_xxx_fileReadWrite_426AC0_file3_fread(v1, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 4, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 8, 4u);
		result = 1;
	}
	return result;
}

//----- (004292C0) --------------------------------------------------------
int  nox_server_mapRWWindowWalls_4292C0(_DWORD* a1) {
	int result; // eax
	_DWORD* v2; // edi
	char* v3;   // esi
	_DWORD* v4; // eax
	int v5;     // [esp+4h] [ebp-20h]
	int v6;     // [esp+8h] [ebp-1Ch]
	int2 v7;
	int4 v9; // [esp+14h] [ebp-10h]

	v5 = 2;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 2u);
	if ((__int16)v5 > 2)
		return 0;
	if (*getMemU32Ptr(0x973F18, 3872)) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741336), 2u);
		v6 = 0;
		if (*getMemU16Ptr(0x5D4594, 741336) > 0) {
			v2 = a1;
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 8u);
				if (a1) {
					v3 = nox_xxx_mapGetWallSize_426A70();
					sub_428170(a1, &v9);
					v7.field_0 += v9.field_0 / 23 - *(_DWORD*)v3;
					v7.field_4 += v9.field_4 / 23 - *((_DWORD*)v3 + 1);
				}
				if (nox_common_gameFlags_check_40A5C0(0x400000)) {
					v4 = nox_xxx_cliWallGet_5042F0(v7.field_0, v7.field_4);
					if (v4)
						v2 = (_DWORD*)*v4;
				} else {
					v2 = (_DWORD*)nox_server_getWallAtGrid_410580(v7.field_0, v7.field_4);
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
		nox_xxx_wallForeachFn_410640(sub_429450, (int)a1);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741336), 2u);
		nox_xxx_wallForeachFn_410640(sub_4294B0, (int)a1);
		result = 1;
	}
	return result;
}

//----- (00429450) --------------------------------------------------------
void  sub_429450(_BYTE* a1, _DWORD* a2) {
	int v2;  // eax
	int2 v3; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned __int8)a1[6], v3.field_0 = 23 * (unsigned __int8)a1[5], v3.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v3, a2))) {
		if (a1[4] & 0x40)
			++*getMemU16Ptr(0x5D4594, 741336);
	}
}

//----- (004294B0) --------------------------------------------------------
void  sub_4294B0(_BYTE* a1, _DWORD* a2) {
	int v2;  // eax
	int v3;  // edx
	int2 v4; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned __int8)a1[6], v4.field_0 = 23 * (unsigned __int8)a1[5], v4.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v4, a2))) {
		if (a1[4] & 0x40) {
			v3 = (unsigned __int8)a1[6];
			v4.field_0 = (unsigned __int8)a1[5];
			v4.field_4 = v3;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 8u);
		}
	}
}

//----- (00429520) --------------------------------------------------------
void nox_xxx_wallBreakableCounterClear_429520() { *getMemU32Ptr(0x5D4594, 741344) = 0; }

//----- (00429530) --------------------------------------------------------
int  nox_server_mapRWDestructableWalls_429530(_DWORD* a1) {
	int result; // eax
	_DWORD* v2; // edi
	char* v3;   // esi
	_DWORD* v4; // eax
	int v5;     // [esp+4h] [ebp-20h]
	int v6;     // [esp+8h] [ebp-1Ch]
	int2 v7;
	int4 v9; // [esp+14h] [ebp-10h]

	v5 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 2u);
	if ((__int16)v5 > 1)
		return 0;
	if (*getMemU32Ptr(0x973F18, 3872)) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741340), 2u);
		v6 = 0;
		if (*getMemU16Ptr(0x5D4594, 741340) > 0) {
			v2 = a1;
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 8u);
				if (a1) {
					v3 = nox_xxx_mapGetWallSize_426A70();
					sub_428170(a1, &v9);
					v7.field_0 += v9.field_0 / 23 - *(_DWORD*)v3;
					v7.field_4 += v9.field_4 / 23 - *((_DWORD*)v3 + 1);
				}
				if (nox_common_gameFlags_check_40A5C0(0x400000)) {
					v4 = nox_xxx_cliWallGet_5042F0(v7.field_0, v7.field_4);
					if (v4)
						v2 = (_DWORD*)*v4;
				} else {
					v2 = (_DWORD*)nox_server_getWallAtGrid_410580(v7.field_0, v7.field_4);
				}
				if (v2) {
					*((_BYTE*)v2 + 4) |= 8u;
					*((_WORD*)v2 + 5) = *getMemU16Ptr(0x5D4594, 741344);
					++*getMemU32Ptr(0x5D4594, 741344);
					if (!nox_common_gameFlags_check_40A5C0(0x400000))
						nox_xxx_wallBreackableListAdd_410840((int)v2);
				}
				++v6;
			} while (v6 < *getMemI16Ptr(0x5D4594, 741340));
		}
		result = 1;
	} else {
		*getMemU16Ptr(0x5D4594, 741340) = 0;
		nox_xxx_wallForeachFn_410640(nox_xxx_wall_4296E0, (int)a1);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741340), 2u);
		nox_xxx_wallForeachFn_410640(sub_429740, (int)a1);
		result = 1;
	}
	return result;
}

//----- (004296E0) --------------------------------------------------------
void  nox_xxx_wall_4296E0(_BYTE* a1, _DWORD* a2) {
	int v2;  // eax
	int2 v3; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned __int8)a1[6], v3.field_0 = 23 * (unsigned __int8)a1[5], v3.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v3, a2))) {
		if (a1[4] & 8)
			++*getMemU16Ptr(0x5D4594, 741340);
	}
}

//----- (00429740) --------------------------------------------------------
void  sub_429740(_BYTE* a1, _DWORD* a2) {
	int v2;  // eax
	int v3;  // edx
	int2 v4; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned __int8)a1[6], v4.field_0 = 23 * (unsigned __int8)a1[5], v4.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v4, a2))) {
		if (a1[4] & 8) {
			v3 = (unsigned __int8)a1[6];
			v4.field_0 = (unsigned __int8)a1[5];
			v4.field_4 = v3;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 8u);
		}
	}
}

//----- (004297B0) --------------------------------------------------------
void nox_xxx_wallSecretCounterClear_4297B0() { *getMemU32Ptr(0x5D4594, 741352) = 0; }

//----- (004297C0) --------------------------------------------------------
int  nox_server_mapRWSecretWalls_4297C0(_DWORD* a1) {
	char* v2;  // esi
	int* v3;   // edi
	_BYTE* v4; // ebx
	char* v5;  // ebp
	int* v6;   // eax
	int v7;    // eax
	char v8;   // dl
	int v9;    // [esp+4h] [ebp-1Ch]
	int v10 = 0;   // [esp+8h] [ebp-18h]
	int v11;   // [esp+Ch] [ebp-14h]
	int4 v12;  // [esp+10h] [ebp-10h]

	v9 = 2;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 2u);
	if ((__int16)v9 > 2)
		return 0;
	if (!*getMemU32Ptr(0x973F18, 3872)) {
		*getMemU16Ptr(0x5D4594, 741348) = 0;
		nox_xxx_wallForeachFn_410640(sub_429A00, (int)a1);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741348), 2u);
		nox_xxx_wallForeachFn_410640(sub_429A60, (int)a1);
		return 1;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741348), 2u);
	v11 = 0;
	if (*getMemU16Ptr(0x5D4594, 741348) > 0) {
		while (1) {
			v2 = (char*)calloc(1u, 0x20u);
			v3 = (int*)(v2 + 4);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 4, 8u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 16, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 20, 1u);
			v4 = v2 + 21;
			v2[21] = 0;
			if ((__int16)v9 >= 2) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 21, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 22, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 24, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 28, 4u);
			}
			if (a1) {
				v5 = nox_xxx_mapGetWallSize_426A70();
				sub_428170(a1, &v12);
				*v3 += v12.field_0 / 23 - *(_DWORD*)v5;
				*((_DWORD*)v2 + 2) += v12.field_4 / 23 - *((_DWORD*)v5 + 1);
			}
			if (!nox_common_gameFlags_check_40A5C0(0x400000))
				break;
			v6 = nox_xxx_cliWallGet_5042F0(*v3, *((_DWORD*)v2 + 2));
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
					nox_xxx_wallSecretBlock_410760(v2);
			}
			if (++v11 >= *getMemI16Ptr(0x5D4594, 741348))
				return 1;
		}
		v10 = nox_server_getWallAtGrid_410580(*v3, *((_DWORD*)v2 + 2));
	LABEL_14:
		v7 = v10;
		goto LABEL_15;
	}
	return 1;
}

//----- (00429A00) --------------------------------------------------------
void  sub_429A00(_BYTE* a1, _DWORD* a2) {
	int v2;  // eax
	int2 v3; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned __int8)a1[6], v3.field_0 = 23 * (unsigned __int8)a1[5], v3.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v3, a2))) {
		if (a1[4] & 4)
			++*getMemU16Ptr(0x5D4594, 741348);
	}
}

//----- (00429A60) --------------------------------------------------------
void  sub_429A60(int a1, _DWORD* a2) {
	int v2;    // eax
	int v3;    // edx
	_BYTE* v4; // esi
	int2 v5;   // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = *(unsigned __int8*)(a1 + 6), v5.field_0 = 23 * *(unsigned __int8*)(a1 + 5), v5.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v5, a2))) {
		if (*(_BYTE*)(a1 + 4) & 4) {
			v3 = *(unsigned __int8*)(a1 + 6);
			v4 = *(_BYTE**)(a1 + 28);
			v5.field_0 = *(unsigned __int8*)(a1 + 5);
			v5.field_4 = v3;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 8u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v4 + 16, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v4 + 20, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v4 + 21, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v4 + 22, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v4 + 24, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v4 + 28, 4u);
		}
	}
}

//----- (00429B20) --------------------------------------------------------
int  nox_server_mapRWWallMap_429B20(_DWORD* a1) {
	_DWORD* v2;           // ebp
	int v3;               // esi
	int v5;               // edx
	int v6;               // edx
	int v7;               // ecx
	int v8;               // eax
	int v9;               // edi
	_BYTE* v10;           // eax
	_BYTE* v11;           // esi
	nox_player_polygon_check_data* v12;        // eax
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

	v31 = nox_xxx_wallGet_426A30();
	if (!getMemByte(0x5D4594, 741372))
		*getMemU8Ptr(0x5D4594, 741372) = nox_xxx_wallTileByName_410D60("MagicWallSystemUseOnly");
	nox_xxx_wallSecretCounterClear_4297B0();
	nox_xxx_wallBreakableCounterClear_429520();
	v28 = 7;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v28, 2u);
	if ((__int16)v28 > 7)
		return 0;
	if ((__int16)v28 < 6)
		return sub_42A150(v28, a1);
	v2 = a1;
	if (!*getMemU32Ptr(0x973F18, 3872)) {
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
			nox_xxx_wallForeachFn_410640(sub_42A0F0, 0);
			v3 = dword_5d4594_741356;
			v5 = dword_5d4594_741364;
		}
		v25 = v3 - *getMemU32Ptr(0x5D4594, 741360) + 1;
		v27 = v5 - *getMemU32Ptr(0x5D4594, 741368) + 1;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741360), 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741368), 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v25, 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 4u);
	v26 = 0;
	v29 = 0;
	if (*getMemU32Ptr(0x973F18, 3872)) {
		if (v2) {
			sub_428170(v2, &v33);
			v13 = v33.field_0 / 23 - *getMemU32Ptr(0x5D4594, 741360);
			*getMemU32Ptr(0x5D4594, 741360) = v33.field_0 / 23;
			v29 = v13;
			v14 = v33.field_4 / 23 - *getMemU32Ptr(0x5D4594, 741368);
			*getMemU32Ptr(0x5D4594, 741368) = v33.field_4 / 23;
			v26 = v14;
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 1u);
		v15 = v22;
		if (v22 == -1)
			return 1;
		while (1) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
			LOBYTE(v30) = v29 + v15;
			LOBYTE(a1) = v26 + (_BYTE)a1;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v24, 1u);
			v16 = (unsigned __int8)v24 >> 7;
			LOBYTE(v24) = v24 & 0x7F;
			if (nox_common_gameFlags_check_40A5C0(0x400000)) {
				v17 = (unsigned __int8*)*sub_504290(v30, (char)a1);
			} else {
				v18 = (unsigned __int8)v30;
				v19 = (unsigned __int8*)nox_server_getWallAtGrid_410580((unsigned __int8)v30, (unsigned __int8)a1);
				v17 = v19;
				if (v19) {
					if (v31 & 1)
						*v19 = nox_xxx_wall_42A6C0(*v19, v24);
					else
						*v19 = v24;
					goto LABEL_46;
				}
				v17 = (unsigned __int8*)nox_xxx_wallCreateAt_410250(v18, (unsigned __int8)a1);
				if (!v17)
					return 0;
			}
			*v17 = v24;
		LABEL_46:
			if (v16)
				v17[4] |= 0x80u;
			v20 = v17 + 1;
			nox_xxx_fileReadWrite_426AC0_file3_fread(v17 + 1, 1u);
			v21 = v17 + 2;
			nox_xxx_fileReadWrite_426AC0_file3_fread(v17 + 2, 1u);
			if (v31 & 1 && *v21 >= nox_xxx_mapWallMaxVariation_410DD0(*v20, *v17, 0))
				*v21 = 0;
			v17[7] = nox_xxx_mapWallGetHpByTile_410E20(*v20);
			if ((_WORD)v28 == 6) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v24, 1u);
				v17[8] = 1;
				*((_DWORD*)v17 + 3) = 0;
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread(v17 + 8, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v24, 1u);
				*((_DWORD*)v17 + 3) = (unsigned __int8)v24;
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 1u);
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
					v10 = (_BYTE*)nox_server_getWallAtGrid_410580(v9, v26);
					v11 = v10;
					if (v10) {
						if (v10[1] != getMemByte(0x5D4594, 741372)) {
							if (!v2 || (v32.field_0 = 23 * (unsigned __int8)v10[5],
										v32.field_4 = 23 * (unsigned __int8)v10[6], nox_xxx_wallMath_427F30(&v32, v2))) {
								nox_xxx_fileReadWrite_426AC0_file3_fread(v11 + 5, 1u);
								nox_xxx_fileReadWrite_426AC0_file3_fread(v11 + 6, 1u);
								if ((int)v11[4] >= 0)
									LOBYTE(v24) = *v11;
								else
									LOBYTE(v24) = *v11 | 0x80;
								nox_xxx_fileReadWrite_426AC0_file3_fread(&v24, 1u);
								nox_xxx_fileReadWrite_426AC0_file3_fread(v11 + 1, 1u);
								nox_xxx_fileReadWrite_426AC0_file3_fread(v11 + 2, 1u);
								v32.field_0 = 23 * (unsigned __int8)v11[5] + 11;
								v32.field_4 = 23 * (unsigned __int8)v11[6] + 11;
								v12 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v32, 0);
								if (v12 || (v12 = (nox_player_polygon_check_data*)sub_421990(&v32, 10.0, 0)) != 0)
									v23 = BYTE2(v12->field_0[32]);
								else
									v23 = 100;
								nox_xxx_fileReadWrite_426AC0_file3_fread(&v23, 1u);
								if (nox_common_gameFlags_check_40A5C0(0x200000))
									LOBYTE(v24) = 0;
								else
									LOBYTE(v24) = v11[12];
								nox_xxx_fileReadWrite_426AC0_file3_fread(&v24, 1u);
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
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 1u);
	return 1;
}

//----- (0042A0F0) --------------------------------------------------------
int  sub_42A0F0(int a1) {
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
int  sub_42A150(__int16 a1, _DWORD* a2) {
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
	nox_player_polygon_check_data* v14;         // eax
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

	v2 = nox_xxx_wallGet_426A30();
	v3 = a2;
	v30 = v2;
	v4 = 0;
	if (!*getMemU32Ptr(0x973F18, 3872)) {
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
			nox_xxx_wallForeachFn_410640(sub_42A0F0, 0);
			v5 = dword_5d4594_741356;
			v6 = dword_5d4594_741364;
		}
		v28 = v5 - *getMemU32Ptr(0x5D4594, 741360) + 1;
		v29 = v6 - *getMemU32Ptr(0x5D4594, 741368) + 1;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741360), 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741368), 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v28, 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v29, 4u);
	if (!*getMemU32Ptr(0x973F18, 3872)) {
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
				v12 = nox_server_getWallAtGrid_410580(v11, v8);
				v13 = (_BYTE*)v12;
				if (v3) {
					if (!v12)
						goto LABEL_15;
					v32.field_0 = 23 * *(unsigned __int8*)(v12 + 5);
					v32.field_4 = 23 * *(unsigned __int8*)(v12 + 6);
					if (!nox_xxx_wallMath_427F30(&v32, v3)) {
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
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 1u);
				if ((_BYTE)v27 != (_BYTE)-1) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(v13 + 1, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(v13 + 2, 1u);
					v32.field_0 = 23 * (unsigned __int8)v13[5] + 11;
					v32.field_4 = 23 * (unsigned __int8)v13[6] + 11;
					v14 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v32, 0);
					if (v14 || (v14 = (nox_player_polygon_check_data*)sub_421990(&v32, 10.0, 0)) != 0)
						v26 = BYTE2(v14->field_0[32]);
					else
						v26 = 1;
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v26, 1u);
					LOBYTE(a1) = v13[12];
					nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
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
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 1u);
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
			v21[7] = nox_xxx_mapWallGetHpByTile_410E20(0);
			v21[8] = 1;
		} else {
			v25 = v21 + 1;
			nox_xxx_fileReadWrite_426AC0_file3_fread(v21 + 1, 1u);
			if (v24 >= 3)
				nox_xxx_fileReadWrite_426AC0_file3_fread(v21 + 2, 1u);
			else
				sub_42A650(v21);
			if (v30 & 1 && v21[2] >= nox_xxx_mapWallMaxVariation_410DD0(*v25, *v21, 0))
				v21[2] = 0;
			v21[7] = nox_xxx_mapWallGetHpByTile_410E20(*v25);
			if (v24 < 4)
				v21[8] = 1;
			else
				nox_xxx_fileReadWrite_426AC0_file3_fread(v21 + 8, 1u);
			LOBYTE(a2) = 0;
			if (v24 >= 5)
				nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
			v4 = v31;
			*((_DWORD*)v21 + 3) = (unsigned __int8)a2;
		}
		goto LABEL_59;
	}
	v22 = (unsigned __int8*)nox_server_getWallAtGrid_410580(v17 + *getMemU32Ptr(0x5D4594, 741360),
															 v4 + *getMemU32Ptr(0x5D4594, 741368));
	v21 = v22;
	if (v22) {
		if (v30 & 1) {
			v23 = nox_xxx_wall_42A6C0(*v22, v27);
		LABEL_42:
			*v21 = v23;
			goto LABEL_43;
		}
	LABEL_41:
		v23 = v27;
		goto LABEL_42;
	}
	v21 = (unsigned __int8*)nox_xxx_wallCreateAt_410250(v17 + *getMemU32Ptr(0x5D4594, 741360), v4 + *getMemU32Ptr(0x5D4594, 741368));
	if (v21)
		goto LABEL_41;
	return 0;
}

//----- (0042A650) --------------------------------------------------------
int  sub_42A650(unsigned __int8* a1) {
	unsigned __int8 v1; // cl
	int result;         // eax

	v1 = *a1;
	a1[2] = 0;
	if (!v1)
		a1[2] = a1[5] % 3;
	if (v1 == 1)
		a1[2] = a1[5] % 3;
	result = nox_xxx_getWallSprite_46A3B0(a1[1], v1, a1[2], (a1[4] >> 2) & 2);
	if (!result)
		a1[2] = 0;
	return result;
}

//----- (0042A6C0) --------------------------------------------------------
unsigned __int8  nox_xxx_wall_42A6C0(unsigned __int8 a1, unsigned __int8 a2) { return getMemByte(0x587000, 71276 + 13 * a1 + a2); }

//----- (0042A6E0) --------------------------------------------------------
int nox_server_mapRWMapInfo_42A6E0() {
	int vers = 3;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&vers, 2);
	if (vers > 3) {
		return 0;
	}
	if (vers >= 1) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 2408), 64);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 2472), 512);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 2984), 16);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3000), 64);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3064), 64);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3128), 128);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3256), 128);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3384), 256);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3640), 128);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3768), 32);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3800), 4);
		if (vers == 2) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3804), 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3805), 1u);
		} else if (*getMemU32Ptr(0x973F18, 3872) == 1) {
			*getMemU8Ptr(0x973F18, 3804) = 2;
			*getMemU8Ptr(0x973F18, 3805) = 16;
		}
	}
	if (vers < 3) {
		*getMemU8Ptr(0x973F18, 3806) = getMemByte(0x5D4594, 741376);
		*getMemU8Ptr(0x973F18, 3838) = getMemByte(0x5D4594, 741380);
	} else {
		int v2 = strlen(getMemAt(0x973F18, 3806));
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v2, 1);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3806), v2);
		*getMemU8Ptr(0x973F18, 3806 + v2) = 0;

		v2 = strlen(getMemAt(0x973F18, 3838));
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v2, 1);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x973F18, 3838), v2);
		*getMemU8Ptr(0x973F18, 3838 + v2) = 0;
	}
	return 1;
}

//----- (0042A8B0) --------------------------------------------------------
uint16_t*  sub_42A8B0(_BYTE* a1, int* a2) {
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
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042A970) --------------------------------------------------------
int  sub_42A970(_BYTE* a1, _BYTE* a2, int* a3) {
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
double  sub_42AAA0(int* a1) {
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
			*getMemU32Ptr(0x5D4594, 741384 + 4 * (v3 % 55)) = v2;
			v2 = v4 - v2 + (v4 - v2 < 0 ? 0x3B9ACA00 : 0);
			v4 = *getMemU32Ptr(0x5D4594, 741384 + 4 * (v3 % 55));
			v3 += 21;
		} while (v3 <= 1134);
		v5 = 4;
		do {
			v6 = 1;
			v7 = getMemAt(0x5D4594, 741388);
			do {
				v8 = *(_DWORD*)v7 - *getMemU32Ptr(0x5D4594, 741388 + 4 * ((v6 + 30) % 55));
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
	v11 = *getMemU32Ptr(0x5D4594, 741384 + 4 * v9) - *getMemU32Ptr(0x5D4594, 741384 + 4 * v10);
	v13 = v11;
	if (v11 < 0) {
		v11 += 1000000000;
		v13 = v11;
	}
	*getMemU32Ptr(0x5D4594, 741384 + 4 * v9) = v11;
	return (double)v13 * *getMemDoublePtr(0x581450, 8368);
}

//----- (0042ABF0) --------------------------------------------------------
void  sub_42ABF0(int a1, int a2, int a3) {
	double v3;  // st7
	int i;      // esi

	if (a3 > 0)
		a3 = -a3;
	v3 = sub_42AAA0(&a3);
	for (i = 0; i < a2; ++i) {
		int v5 = (int)(v3 * 255.0);
		if (v5 < 0)
			v5 = -v5;
		*(_BYTE*)(i + a1) = v5;
		v3 = sub_42AAA0(&a3);
	}
}

//----- (0042AC50) --------------------------------------------------------
_BYTE*  sub_42AC50(_BYTE* a1, size_t* a2) {
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
uint16_t*  sub_42ADA0(int a1, int a2, __int16 a3, unsigned int* a4) {
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
		v7 = sub_42C8B0((int)v6, "MXPL", v5);
	else
		v7 = 0;
	sub_42C360(v118, v7);
	v8 = *(_DWORD*)(a1 + 12);
	v9 = operator_new(0x10u);
	if (v9)
		v10 = sub_42C8B0((int)v9, "IDNO", v8);
	else
		v10 = 0;
	sub_42C360(v118, v10);
	v11 = *(_DWORD*)(a1 + 16);
	v12 = operator_new(0x10u);
	if (v12)
		v13 = sub_42C8B0((int)v12, "GSKU", v11);
	else
		v13 = 0;
	sub_42C360(v118, v13);
	v14 = *(_DWORD*)(a1 + 20);
	v15 = operator_new(0x10u);
	if (v15)
		v16 = sub_42C8B0((int)v15, "GSTY", v14);
	else
		v16 = 0;
	sub_42C360(v118, v16);
	v119 = *(_BYTE*)(a1 + 24);
	v17 = operator_new(0x10u);
	if (v17)
		v18 = sub_42C7F0((int)v17, "CLGM", v119);
	else
		v18 = 0;
	sub_42C360(v118, v18);
	v19 = *(_DWORD*)(v4 + 32);
	v20 = operator_new(0x10u);
	if (v20)
		v21 = sub_42C8B0((int)v20, "LIMT", v19);
	else
		v21 = 0;
	sub_42C360(v118, v21);
	v22 = *(_DWORD*)(v4 + 36);
	v23 = operator_new(0x10u);
	if (v23)
		v24 = sub_42C8B0((int)v23, "TLMT", v22);
	else
		v24 = 0;
	sub_42C360(v118, v24);
	v120 = *(_BYTE*)(v4 + 40);
	v25 = operator_new(0x10u);
	if (v25)
		v26 = sub_42C7F0((int)v25, "RSTC", v120);
	else
		v26 = 0;
	sub_42C360(v118, v26);
	v27 = *(_DWORD*)(v4 + 44);
	v28 = operator_new(0x10u);
	if (v28)
		v29 = sub_42C8B0((int)v28, "MINE", v27);
	else
		v29 = 0;
	sub_42C360(v118, v29);
	v30 = *(_DWORD*)(v4 + 48);
	v31 = operator_new(0x10u);
	if (v31)
		v32 = sub_42C8B0((int)v31, "MAXE", v30);
	else
		v32 = 0;
	sub_42C360(v118, v32);
	v33 = *(_DWORD*)(v4 + 52);
	v34 = operator_new(0x10u);
	if (v34)
		v35 = sub_42C8B0((int)v34, "MINP", v33);
	else
		v35 = 0;
	sub_42C360(v118, v35);
	v36 = *(_DWORD*)(v4 + 56);
	v37 = operator_new(0x10u);
	if (v37)
		v38 = sub_42C8B0((int)v37, "MAXP", v36);
	else
		v38 = 0;
	sub_42C360(v118, v38);
	v121 = *(_BYTE*)(v4 + 60);
	v39 = operator_new(0x10u);
	if (v39)
		v40 = sub_42C7F0((int)v39, "VIDM", v121);
	else
		v40 = 0;
	sub_42C360(v118, v40);
	v122 = *(_BYTE*)(v4 + 61);
	v41 = operator_new(0x10u);
	if (v41)
		v42 = sub_42C7F0((int)v41, "SVRS", v122);
	else
		v42 = 0;
	sub_42C360(v118, v42);
	v123 = *(_BYTE*)(v4 + 25);
	v43 = operator_new(0x10u);
	if (v43)
		v44 = sub_42C7F0((int)v43, "NTMS", v123);
	else
		v44 = 0;
	sub_42C360(v118, v44);
	v45 = operator_new(0x10u);
	if (v45)
		v46 = sub_42C8E0((int)v45, "SCEN", (const char*)(v4 + 96));
	else
		v46 = 0;
	sub_42C360(v118, v46);
	v47 = operator_new(0x10u);
	if (v47)
		v48 = sub_42C8E0((int)v47, "GNAM", (const char*)(v4 + 352));
	else
		v48 = 0;
	sub_42C360(v118, v48);
	v49 = *(_DWORD*)(v4 + 64);
	v50 = operator_new(0x10u);
	if (v50)
		v51 = sub_42C8B0((int)v50, "SPL1", v49);
	else
		v51 = 0;
	sub_42C360(v118, v51);
	v52 = *(_DWORD*)(v4 + 68);
	v53 = operator_new(0x10u);
	if (v53)
		v54 = sub_42C8B0((int)v53, "SPL2", v52);
	else
		v54 = 0;
	sub_42C360(v118, v54);
	v55 = *(_DWORD*)(v4 + 72);
	v56 = operator_new(0x10u);
	if (v56)
		v57 = sub_42C8B0((int)v56, "SPL3", v55);
	else
		v57 = 0;
	sub_42C360(v118, v57);
	v58 = *(_DWORD*)(v4 + 88);
	v59 = operator_new(0x10u);
	if (v59)
		v60 = sub_42C8B0((int)v59, "ARMR", v58);
	else
		v60 = 0;
	sub_42C360(v118, v60);
	v124 = *(_BYTE*)(v4 + 84);
	v61 = operator_new(0x10u);
	if (v61)
		v62 = sub_42C7F0((int)v61, "WPN1", v124);
	else
		v62 = 0;
	sub_42C360(v118, v62);
	v125 = *(_BYTE*)(v4 + 85);
	v63 = operator_new(0x10u);
	if (v63)
		v64 = sub_42C7F0((int)v63, "WPN2", v125);
	else
		v64 = 0;
	sub_42C360(v118, v64);
	v126 = *(_BYTE*)(v4 + 86);
	v65 = operator_new(0x10u);
	if (v65)
		v66 = sub_42C7F0((int)v65, "WPN3", v126);
	else
		v66 = 0;
	sub_42C360(v118, v66);
	v67 = *(_DWORD*)(v4 + 92);
	v68 = operator_new(0x10u);
	if (v68)
		v69 = sub_42C8B0((int)v68, "STAF", v67);
	else
		v69 = 0;
	sub_42C360(v118, v69);
	v70 = *(_DWORD*)(v4 + 28);
	v71 = operator_new(0x10u);
	if (v71)
		v72 = sub_42C8B0((int)v71, "DURA", v70);
	else
		v72 = 0;
	sub_42C360(v118, v72);
	v73 = operator_new(0x10u);
	if (v73)
		v74 = sub_42C7F0((int)v73, "FINI", 1);
	else
		v74 = 0;
	sub_42C360(v118, v74);
	v127 = *(_BYTE*)(v4 + 26);
	v75 = operator_new(0x10u);
	if (v75)
		v76 = sub_42C7F0((int)v75, "TRNY", v127);
	else
		v76 = 0;
	sub_42C360(v118, v76);
	switch (a2) {
	case 0:
		*getMemU32Ptr(0x5D4594, 741668) = 0;
		v77 = operator_new(0x10u);
		if (v77)
			v78 = sub_42C8B0((int)v77, "SEQU", 0);
		else
			v78 = 0;
		sub_42C360(v118, v78);
		v79 = operator_new(0x10u);
		if (v79)
			v80 = sub_42C7F0((int)v79, "ENDF", 0);
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
			v86 = sub_42C8B0((int)v85, "SEQU", v84);
		else
			v86 = 0;
		sub_42C360(v118, v86);
		v87 = operator_new(0x10u);
		if (v87)
			v88 = sub_42C7F0((int)v87, "ENDF", 1);
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
				v95 = sub_42C8E0((int)v94, "LGL?", v93);
			else
				v95 = 0;
			sub_42C360(v118, v95);
			*getMemU8Ptr(0x587000, 71499) = getMemByte(0x5D4594, 741660) + 48;
			v96 = *(_DWORD*)(*(_DWORD*)(v4 + 612) + 4 * *getMemU32Ptr(0x5D4594, 741660));
			v97 = operator_new(0x10u);
			if (v97)
				v98 = sub_42C8B0((int)v97, "IPL?", v96);
			else
				v98 = 0;
			sub_42C360(v118, v98);
			*getMemU8Ptr(0x587000, 71515) = getMemByte(0x5D4594, 741660) + 48;
			v99 = *(_DWORD*)(*(_DWORD*)(v4 + 616) + 4 * *getMemU32Ptr(0x5D4594, 741660));
			v100 = operator_new(0x10u);
			if (v100)
				v101 = sub_42C8B0((int)v100, "CNL?", v99);
			else
				v101 = 0;
			sub_42C360(v118, v101);
			*getMemU8Ptr(0x587000, 71507) = getMemByte(0x5D4594, 741660) + 48;
			v128 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 741660) + *(_DWORD*)(v4 + 620));
			v102 = operator_new(0x10u);
			if (v102)
				v103 = sub_42C7F0((int)v102, "CLL?", v128);
			else
				v103 = 0;
			sub_42C360(v118, v103);
			*getMemU8Ptr(0x587000, 71523) = getMemByte(0x5D4594, 741660) + 48;
			v129 = *(_BYTE*)(*(_DWORD*)(v4 + 624) + *getMemU32Ptr(0x5D4594, 741660));
			v104 = operator_new(0x10u);
			if (v104)
				v105 = sub_42C7F0((int)v104, "CMP?", v129);
			else
				v105 = 0;
			sub_42C360(v118, v105);
			*getMemU8Ptr(0x587000, 71531) = getMemByte(0x5D4594, 741660) + 48;
			v106 = *(_DWORD*)(*(_DWORD*)(v4 + 628) + 4 * *getMemU32Ptr(0x5D4594, 741660));
			v107 = operator_new(0x10u);
			if (v107)
				v108 = sub_42C8B0((int)v107, "DUR?", v106);
			else
				v108 = 0;
			sub_42C360(v118, v108);
			*getMemU8Ptr(0x587000, 71539) = getMemByte(0x5D4594, 741660) + 48;
			v117 = *(_BYTE*)(*(_DWORD*)(v4 + 632) + *getMemU32Ptr(0x5D4594, 741660));
			v109 = operator_new(0x10u);
			if (v109)
				v110 = sub_42C7F0((int)v109, "PAR?", v117);
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
		sub_42BDC0(v118, "SEQU", getMemByte(0x5D4594, 741668));
		sub_42BCE0(v118, "ENDF", 0);
		sub_42BD50(v118, (char*)getMemAt(0x587000, 71928), *(_WORD*)(v4 + 6));
		v114 = 0;
		for (*getMemU32Ptr(0x5D4594, 741660) = 0; v114 < *(__int16*)(v4 + 6); *getMemU32Ptr(0x5D4594, 741660) = v114) {
			*getMemU8Ptr(0x587000, 71491) = v114 + 48;
			sub_42BE30(v118, (char*)getMemAt(0x587000, 71488), *(const char**)(*(_DWORD*)(v4 + 608) + 4 * v114));
			*getMemU8Ptr(0x587000, 71499) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BDC0(v118, "IPL?",
					   *(_DWORD*)(*(_DWORD*)(v4 + 612) + 4 * *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71515) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BDC0(v118, "CNL?",
					   *(_DWORD*)(*(_DWORD*)(v4 + 616) + 4 * *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71507) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BCE0(v118, "CLL?",
					   *(_BYTE*)(*getMemU32Ptr(0x5D4594, 741660) + *(_DWORD*)(v4 + 620)));
			*getMemU8Ptr(0x587000, 71523) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BCE0(v118, "CMP?",
					   *(_BYTE*)(*(_DWORD*)(v4 + 624) + *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71531) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BDC0(v118, "DUR?",
					   *(_DWORD*)(*(_DWORD*)(v4 + 628) + 4 * *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71539) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BCE0(v118, "PAR?",
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
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042B810) --------------------------------------------------------
uint16_t*  sub_42B810(__int16* a1, unsigned int* a2) {
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
		v5 = sub_42C8B0((int)v4, "IDNO", v3);
	else
		v5 = 0;
	sub_42C360(v59, v5);
	v6 = *((_DWORD*)a1 + 2);
	v7 = operator_new(0x10u);
	if (v7)
		v8 = sub_42C8B0((int)v7, "GSKU", v6);
	else
		v8 = 0;
	sub_42C360(v59, v8);
	v9 = *((_DWORD*)a1 + 3);
	v10 = operator_new(0x10u);
	if (v10)
		v11 = sub_42C8B0((int)v10, "GSTY", v9);
	else
		v11 = 0;
	sub_42C360(v59, v11);
	v12 = operator_new(0x10u);
	if (v12)
		v13 = sub_42C8E0((int)v12, "SCEN", (const char*)a1 + 24);
	else
		v13 = 0;
	sub_42C360(v59, v13);
	v14 = operator_new(0x10u);
	if (v14)
		v15 = sub_42C8E0((int)v14, "GNAM", (const char*)a1 + 280);
	else
		v15 = 0;
	sub_42C360(v59, v15);
	v16 = *((_DWORD*)a1 + 5);
	v17 = operator_new(0x10u);
	if (v17)
		v18 = sub_42C8B0((int)v17, "DURA", v16);
	else
		v18 = 0;
	sub_42C360(v59, v18);
	v60 = *((_BYTE*)a1 + 16);
	v19 = operator_new(0x10u);
	if (v19)
		v20 = sub_42C7F0((int)v19, "TRNY", v60);
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
		v26 = sub_42C8B0((int)v25, "SEQU", v24);
	else
		v26 = 0;
	sub_42C360(v59, v26);
	v27 = 0;
	for (*getMemU32Ptr(0x5D4594, 741664) = 0; v27 < *v2; *getMemU32Ptr(0x5D4594, 741664) = v27) {
		*getMemU8Ptr(0x587000, 71547) = v27 + 48;
		v28 = *(const char**)(*((_DWORD*)v2 + 134) + 4 * v27);
		v29 = operator_new(0x10u);
		if (v29)
			v30 = sub_42C8E0((int)v29, "LGLS", v28);
		else
			v30 = 0;
		sub_42C360(v59, v30);
		*getMemU8Ptr(0x587000, 71555) = getMemByte(0x5D4594, 741664) + 48;
		v31 = *(_DWORD*)(*((_DWORD*)v2 + 135) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v32 = operator_new(0x10u);
		if (v32)
			v33 = sub_42C8B0((int)v32, "IPLS", v31);
		else
			v33 = 0;
		sub_42C360(v59, v33);
		*getMemU8Ptr(0x587000, 71563) = getMemByte(0x5D4594, 741664) + 48;
		v61 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 741664) + *((_DWORD*)v2 + 144));
		v34 = operator_new(0x10u);
		if (v34)
			v35 = sub_42C7F0((int)v34, "CLLS", v61);
		else
			v35 = 0;
		sub_42C360(v59, v35);
		*getMemU8Ptr(0x587000, 71571) = getMemByte(0x5D4594, 741664) + 48;
		v36 = *(_DWORD*)(*((_DWORD*)v2 + 136) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v37 = operator_new(0x10u);
		if (v37)
			v38 = sub_42C8B0((int)v37, "CSTS", v36);
		else
			v38 = 0;
		sub_42C360(v59, v38);
		*getMemU8Ptr(0x587000, 71579) = getMemByte(0x5D4594, 741664) + 48;
		v39 = *(_DWORD*)(*((_DWORD*)v2 + 137) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v40 = operator_new(0x10u);
		if (v40)
			v41 = sub_42C8B0((int)v40, "HSTS", v39);
		else
			v41 = 0;
		sub_42C360(v59, v41);
		*getMemU8Ptr(0x587000, 71587) = getMemByte(0x5D4594, 741664) + 48;
		v42 = *(_DWORD*)(*((_DWORD*)v2 + 138) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v43 = operator_new(0x10u);
		if (v43)
			v44 = sub_42C8B0((int)v43, "MKLS", v42);
		else
			v44 = 0;
		sub_42C360(v59, v44);
		*getMemU8Ptr(0x587000, 71595) = getMemByte(0x5D4594, 741664) + 48;
		v45 = *(_DWORD*)(*((_DWORD*)v2 + 139) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v46 = operator_new(0x10u);
		if (v46)
			v47 = sub_42C8B0((int)v46, "ANKS", v45);
		else
			v47 = 0;
		sub_42C360(v59, v47);
		*getMemU8Ptr(0x587000, 71603) = getMemByte(0x5D4594, 741664) + 48;
		v48 = *(_DWORD*)(*((_DWORD*)v2 + 140) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v49 = operator_new(0x10u);
		if (v49)
			v50 = sub_42C8B0((int)v49, "GNDS", v48);
		else
			v50 = 0;
		sub_42C360(v59, v50);
		*getMemU8Ptr(0x587000, 71611) = getMemByte(0x5D4594, 741664) + 48;
		v51 = *(_DWORD*)(*((_DWORD*)v2 + 141) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v52 = operator_new(0x10u);
		if (v52)
			v53 = sub_42C8B0((int)v52, "SECS", v51);
		else
			v53 = 0;
		sub_42C360(v59, v53);
		*getMemU8Ptr(0x587000, 71619) = getMemByte(0x5D4594, 741664) + 48;
		v54 = *(_DWORD*)(*((_DWORD*)v2 + 142) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v55 = operator_new(0x10u);
		if (v55)
			v56 = sub_42C8B0((int)v55, "BPTS", v54);
		else
			v56 = 0;
		sub_42C360(v59, v56);
		*getMemU8Ptr(0x587000, 71627) = getMemByte(0x5D4594, 741664) + 48;
		sub_42BDC0(v59, "SCRS",
				   *(_DWORD*)(*((_DWORD*)v2 + 143) + 4 * *getMemU32Ptr(0x5D4594, 741664)));
		v27 = *getMemU32Ptr(0x5D4594, 741664) + 1;
	}
	v57 = sub_42C480(v59, a2);
	++*getMemU32Ptr(0x5D4594, 741672);
	sub_42C330(v59);
	return v57;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

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
// 5667CB: using guessed type void * operator_new(unsigned int);

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
// 5667CB: using guessed type void * operator_new(unsigned int);

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
// 5667CB: using guessed type void * operator_new(unsigned int);

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
// 5667CB: using guessed type void * operator_new(unsigned int);

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
// 5667CB: using guessed type void * operator_new(unsigned int);

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
		for (l = nox_xxx_getFirstUpdatable2Object_4DA840(); l; l = nox_xxx_getNextUpdatable2Object_4DA850(l)) {
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
int  sub_42C210(int a1, _WORD* a2, _WORD* a3) {
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
__int16  nox_xxx_objectTOCgetTT_42C2B0(__int16 a1) {
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
__int16  sub_42C2E0(int a1) {
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
LPVOID  sub_42C310(unsigned __int16 a1, __int16 a2) {
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
// 5667CB: using guessed type void * operator_new(unsigned int);

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
// 5667CB: using guessed type void * operator_new(unsigned int);

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
// 5667CB: using guessed type void * operator_new(unsigned int);

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
// 5667CB: using guessed type void * operator_new(unsigned int);

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
	int a3i = a3;
	memcpy(result, &a3i, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

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
	int a3i = a3;
	memcpy(result, &a3i, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

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
	int a3i = a3;
	memcpy(result, &a3i, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

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
	int a3i = a3;
	memcpy(result, &a3i, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

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
// 5667CB: using guessed type void * operator_new(unsigned int);

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
// 5667CB: using guessed type void * operator_new(unsigned int);

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

//----- (0042E600) --------------------------------------------------------
char* sub_42E600() {
	sub_413A00(0);
	return sub_4DB790("AUTOSAVE");
}

//----- (0042E620) --------------------------------------------------------
void sub_42E620() { sub_413A00(0); }

//----- (0042E7B0) --------------------------------------------------------
void  nox_xxx_clientTalk_42E7B0(nox_drawable* a1p) {
	int a1 = a1p;
	int v1;     // esi
	__int16 v2; // ax

	v1 = a1;
	if (a1 && (!*getMemU32Ptr(0x8531A0, 2576) || !(*(_BYTE*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 3)) &&
		sub_478030() != 1 && nox_gui_xxx_check_446360() != 1) {
		v2 = *(_WORD*)(v1 + 128);
		LOWORD(a1) = 464;
		HIWORD(a1) = v2;
		nox_netlist_addToMsgListCli_40EBC0(31, 0, &a1, 4);
	}
}

//----- (0042E810) --------------------------------------------------------
void  nox_xxx_clientCollideOrUse_42E810(nox_drawable* a1p) {
	int a1 = a1p;
	int v1; // [esp-4h] [ebp-4h]

	if (a1 && (!*getMemU32Ptr(0x8531A0, 2576) || !(*(_BYTE*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 3))) {
		v1 = a1;
		LOBYTE(a1) = 123;
		*(_WORD*)((char*)&a1 + 1) = nox_xxx_netGetUnitCodeCli_578B00(v1);
		nox_netlist_addToMsgListCli_40EBC0(31, 0, &a1, 3);
	}
}

//----- (0042E850) --------------------------------------------------------
void  nox_xxx_clientTrade_42E850(nox_drawable* a1p) {
	int a1 = a1p;
	int v1; // esi

	v1 = a1;
	if (a1 && (!*getMemU32Ptr(0x8531A0, 2576) || !(*(_BYTE*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 3)) &&
		sub_47A260() != 1 && nox_gui_xxx_check_446360() != 1) {
		LOWORD(a1) = 5577;
		HIWORD(a1) = nox_xxx_netGetUnitCodeCli_578B00(v1);
		nox_netlist_addToMsgListCli_40EBC0(31, 0, &a1, 4);
	}
}

//----- (0042EB90) --------------------------------------------------------
int  sub_42EB90(int a1) {
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

	v0 = *(unsigned __int8**)&nox_video_bag_ptr_787200;
	result = 0;
	if (nox_video_bag_ptr_787200 && *getMemU32Ptr(0x5D4594, 787216)) {
		v2 = *getMemU32Ptr(0x5D4594, 787216);
		do {
			result += *v0++;
			--v2;
		} while (v2);
	}
	return result;
}

//----- (0042F1B0) --------------------------------------------------------
int  nox_video_bagReadIdxHeader_42F1B0(int* data, int* hdr) {
	hdr[0] = data[0];
	if (data[0] != -85082902 && data[0] != -85082901)
		return 0;
	hdr[3] = data[2];
	hdr[1] = data[3];
	hdr[2] = data[4];
	hdr[4] = data[5];
	return 24;
}

//----- (0042F200) --------------------------------------------------------
void nox_video_bagReadIdx_42F200(unsigned char* data, int is16bit) {
	dword_5d4594_787180 = 0;
	if (nox_video_bag_sections_cnt > 0) {
		int v16 = 0;
		int v17 = 0;
		for (int i = 0; i < nox_video_bag_sections_cnt; i++) {
			int v5 = *((_DWORD*)data + 1);
			_DWORD* v6 = ((_DWORD*)data + 2);
			int v7 = 0;
			if (nox_video_bag_flag_754144) {
				v7 = *v6;
				++v6;
			} else {
				v7 = v5;
			}
			int v8 = *v6;
			data = (unsigned __int8*)(v6 + 1);
			nox_video_bag_sections_arr[i].data = 0;
			nox_video_bag_sections_arr[i].field_1 = 0;
			nox_video_bag_sections_arr[i].bag_offs = v16;
			nox_video_bag_sections_arr[i].size = v5;
			nox_video_bag_sections_arr[i].size_comp = v7;
			nox_video_bag_sections_arr[i].field_5 = v17;
			nox_video_bag_sections_arr[i].field_6 = v8;
			v16 += v7;
			if (v8 == -1) {
				v8 = 1;
			} else if (v5 > dword_5d4594_787180) {
				dword_5d4594_787180 = v5;
			}
			if (v8 > 0) {
				int v9 = 0;
				int v11 = v17;
				v17 += v8;
				for (int j = v8; j > 0; j--) {
					nox_video_bag_images_arr[v11].sect_ind = i;
					unsigned __int8* v12 = &data[*data + 1];
					unsigned __int8 v13 = *v12;
					_DWORD* v14 = v12 + 1;
					nox_video_bag_images_arr[v11].typ = v13;
					int size = 0;
					if (is16bit == 1) {
						size = v14[0];
					} else {
						size = v14[1];
					}
					data = (unsigned __int8*)(v14 + 2);
					nox_video_bag_images_arr[v11].offset = v9;
					v11++;
					v9 += size;
				}
			}
		}
	}
	if (dword_5d4594_787180 > (int)nox_video_bag_tmpBufSize_787184) {
		dword_5d4594_787180 = nox_video_bag_tmpBufSize_787184;
	}
}

//----- (0042F030) --------------------------------------------------------
void nox_video_bag_free_42F030() {
	for (int i = 0; i < nox_video_bag_sections_cnt; i++) {
		nox_video_bag_section_t* ent = &nox_video_bag_sections_arr[i];
		if (ent->data) {
			if (ent->field_6 == -1) {
				free(ent->data);
			}
			ent->data = 0;
		}
	}
	*getMemU32Ptr(0x5D4594, 787136) = 0;
	*getMemU32Ptr(0x5D4594, 787140) = getMemAt(0x5D4594, 754108);
	*getMemU32Ptr(0x5D4594, 754136) = getMemAt(0x5D4594, 787108);
	*getMemU32Ptr(0x5D4594, 754140) = 0;
}

//----- (0042EFF0) --------------------------------------------------------
void nox_video_bag_sub_42EFF0() {
	nox_video_bag_free_42F030();
	if (nox_video_16bit) {
		nox_video_bag_var_787176 = nox_video_bag_tmpBufSize_787184;
	} else {
		nox_video_bag_var_787176 = dword_5d4594_787180;
	}
	dword_5d4594_787188 = dword_5d4594_787192;
}

//----- (0042EE30) --------------------------------------------------------
int  nox_video_read_videobag(int is16bit) {
	nox_video_bag_ready = 0;
	nox_video_bag_fileptr = nox_fs_open(nox_video_getbagfilename(is16bit));
	if (!nox_video_bag_fileptr) {
		return 0;
	}
	void* indData = nox_video_readBagIdxBytes_42F0B0(is16bit);
	if (!indData) {
		nox_fs_close(nox_video_bag_fileptr);
		return 0;
	}
	unsigned int hdr[5];
	int offs = nox_video_bagReadIdxHeader_42F1B0(indData, hdr);
	if (!offs) {
		free(indData);
		nox_fs_close(nox_video_bag_fileptr);
		return 0;
	}
	nox_video_bag_images_cnt = hdr[4];
	nox_video_bag_sections_cnt = hdr[3];
	nox_video_bag_tmpBufSize_787184 = hdr[1];
	if (nox_video_bag_tmpBuf_787208) {
		free(nox_video_bag_tmpBuf_787208);
		nox_video_bag_tmpBuf_787208 = 0;
	}
	if (nox_video_bag_flag_754144) {
		nox_video_bag_tmpBuf_787208 = malloc(nox_video_bag_tmpBufSize_787184);
	}
	if (!dword_5d4594_787212) {
		dword_5d4594_787212 = sub_578BF0();
	}
	if (nox_video_bag_var_2650640 == 1) {
		nox_video_bagAlloc_47A270();
	}
	nox_video_bag_sections_arr = malloc(sizeof(nox_video_bag_section_t) * nox_video_bag_sections_cnt);
	nox_video_bag_images_arr = malloc(sizeof(nox_video_bag_image_t) * nox_video_bag_images_cnt);
	nox_video_bagReadIdx_42F200((unsigned char*)indData + offs, is16bit);
	free(indData);
	int v7 = 0x800000;
	if (nox_video_bag_tmpBufSize_787184 * nox_video_bag_sections_cnt < 0x800000) {
		v7 = nox_video_bag_tmpBufSize_787184 * nox_video_bag_sections_cnt;
	}
	int v8 = nox_video_bag_tmpBufSize_787184 * (v7 / nox_video_bag_tmpBufSize_787184);
	dword_5d4594_787192 = v8 / nox_video_bag_tmpBufSize_787184;
	nox_video_bag_ptr_787200 = (int)malloc(v8);
	if (!nox_video_bag_ptr_787200) {
		return 0;
	}
	*getMemU32Ptr(0x973F18, 7736) = getMemAt(0x5D4594, 754148);
	nox_video_bag_ready = 1;
	nox_video_bag_sub_42EFF0();
	return 1;
}

//----- (0042F0B0) --------------------------------------------------------
void* nox_video_readBagIdxBytes_42F0B0(int is16bit) {
	FILE* f = nox_fs_open(nox_video_getBagIdxName_430120(is16bit));
	if (!f) {
		return 0;
	}
	int magic = 0;
	nox_binfile_fread2_40ADD0(&magic, 4, 1, f);
	nox_video_bag_flag_754144 = 0;
	if (magic == -85082901) {
		nox_video_bag_flag_754144 = 1;
	} else if (magic != -85082902) {
		nox_fs_close(f);
		return 0;
	}
	unsigned int sz = 0;
	nox_binfile_fread2_40ADD0(&sz, 4, 1, f);
	void* data = malloc(sz);
	if (!data) {
		nox_fs_close(f);
		return 0;
	}
	nox_fs_fseek_start(f, 0);
	int n = nox_binfile_fread2_40ADD0(data, 1, sz, f);
	if (n != sz) {
		nox_fs_close(f);
		return 0;
	}
	nox_fs_close(f);
	return data;
}

//----- (0042F490) --------------------------------------------------------
bool nox_video_reopen_videobag(const char* path) {
	if (nox_video_bag_fileptr) {
		nox_fs_close(nox_video_bag_fileptr);
	}
	nox_video_bag_fileptr = nox_fs_open(path);
	return nox_video_bag_fileptr != 0;
}

//----- (0042F370) --------------------------------------------------------
int  nox_video_bagMaybeReload(int is16bit) {
	if (!nox_video_bag_fileptr)
		return 1;
	nox_video_bag_ready = 0;
	const char* name = nox_video_getbagfilename(is16bit);
	if (is16bit != *getMemU32Ptr(0x587000, 80720)) {
		*getMemU32Ptr(0x587000, 80720) = is16bit;
		nox_video_reopen_videobag(name);
	}
	nox_video_bag_free_42F030();
	void* data = nox_video_readBagIdxBytes_42F0B0(is16bit);
	if (!data) {
		nox_fs_close(nox_video_bag_fileptr);
		return 0;
	}
	int hdr[5];
	int offs = nox_video_bagReadIdxHeader_42F1B0(data, hdr);
	if (!offs) {
		free(data);
		nox_fs_close(nox_video_bag_fileptr);
		return 0;
	}
	if (nox_video_bag_var_2650640 == 1)
		nox_video_bagAlloc_47A270();
	nox_video_bagReadIdx_42F200((unsigned char*)data + offs, is16bit);
	free(data);
	if (nox_video_bag_tmpBuf_787208) {
		free(nox_video_bag_tmpBuf_787208);
		nox_video_bag_tmpBuf_787208 = 0;
	}
	if (nox_video_bag_flag_754144) {
		nox_video_bag_tmpBuf_787208 = malloc(nox_video_bag_tmpBufSize_787184);
	}
	nox_video_bag_sub_42EFF0();
	nox_video_bag_ready = 1;
	return 1;
}

//----- (0042F4D0) --------------------------------------------------------
void nox_video_bagFree_42F4D0() {
	nox_video_bag_ready = 0;
	nox_video_bag_free_42F030();
	if (nox_video_bag_ptr_787200) {
		free(nox_video_bag_ptr_787200);
		nox_video_bag_ptr_787200 = 0;
	}
	if (nox_video_bag_sections_arr) {
		free(nox_video_bag_sections_arr);
		nox_video_bag_sections_arr = 0;
	}
	if (nox_video_bag_images_arr) {
		free(nox_video_bag_images_arr);
		nox_video_bag_images_arr = 0;
	}
	if (nox_images_arr1_787156) {
		if (nox_images_ind1_787164 > 0) {
			for (int i = 0; i < nox_images_ind1_787164; i++) {
				if (nox_images_arr1_787156[i].field_25_1 == 2) {
					free(*(LPVOID*)((int)nox_images_arr1_787156[i].field_24 + 4));
					free(nox_images_arr1_787156[i].field_24);
				}
			}
		}
		free(nox_images_arr1_787156);
		nox_images_arr1_787156 = 0;
		nox_images_cnt1_787160 = 0;
		nox_images_ind1_787164 = 0;
	}
	dword_5d4594_787192 = 0;
	dword_5d4594_787188 = 0;
	*getMemU32Ptr(0x5D4594, 787136) = 0;
	*getMemU32Ptr(0x5D4594, 787140) = getMemAt(0x5D4594, 754108);
	*getMemU32Ptr(0x5D4594, 754136) = getMemAt(0x5D4594, 787108);
	*getMemU32Ptr(0x5D4594, 754140) = 0;
	sub_47D150();
	nox_fs_close(nox_video_bag_fileptr);
	nox_video_bag_fileptr = 0;
	if (dword_5d4594_787212) {
		sub_578C40(*(LPVOID*)&dword_5d4594_787212);
		dword_5d4594_787212 = 0;
	}
	if (nox_video_bag_tmpBuf_787208) {
		free(nox_video_bag_tmpBuf_787208);
		nox_video_bag_tmpBuf_787208 = 0;
	}
}

//----- (0042F610) --------------------------------------------------------
int nox_xxx_imgLoadAlloc_42F610(int cnt) {
	if (cnt < 0)
		return 0;
	nox_images_arr1_787156 = malloc(sizeof(nox_things_imageRef_t) * cnt);
	if (!nox_images_arr1_787156) {
		return 0;
	}
	nox_images_cnt1_787160 = cnt;
	nox_images_ind1_787164 = 0;
	return 1;
}

//----- (0042F660) --------------------------------------------------------
int  nox_thing_read_IMAG_one_42F660(nox_memfile* f, char* buf) {
	if (nox_images_ind1_787164 >= nox_images_cnt1_787160) {
		return 0;
	}
	unsigned __int8 v29 = nox_memfile_read_u8(f);
	nox_memfile_read(buf, 1, v29, f);
	buf[v29] = 0;
	strcpy(nox_images_arr1_787156[nox_images_ind1_787164].name, buf);

	char v6 = nox_memfile_read_i8(f);
	nox_images_arr1_787156[nox_images_ind1_787164].field_25_1 = v6;
	if (v6 == 1) {
		int v8 = nox_memfile_read_i32(f);
		if (v8 == -1) {
			unsigned __int8 a2b = nox_memfile_read_u8(f);
			unsigned __int8 v30 = nox_memfile_read_u8(f);
			nox_memfile_read(buf, 1, v30, f);
			buf[v30] = 0;
			if (nox_xxx_loadImage_47A8C0(a2b, buf)) {
				strcpy(nox_images_arr1_787156[nox_images_ind1_787164].name2, buf);
				v8 = -1;
				nox_images_arr1_787156[nox_images_ind1_787164].field_25_0 = a2b;
			} else {
				nox_images_arr1_787156[nox_images_ind1_787164].field_25_0 = -1;
			}
		}
		nox_images_arr1_787156[nox_images_ind1_787164].field_24 = v8;
		nox_images_ind1_787164++;
		return 1;
	} else if (v6 == 2) {
		_DWORD* v13 = malloc(16);
		if (!v13) {
			return 0;
		}
		v13[0] = 0;
		unsigned __int8 v33 = nox_memfile_read_u8(f);
		*((_BYTE*)v13 + 8) = v33;
		int v27 = v33;
		void* v15 = malloc(4 * v33);
		if (!v15) {
			return 0;
		}
		v13[1] = v15;
		char v17 = nox_memfile_read_i8(f);
		*((_BYTE*)v13 + 9) = v17;
		unsigned __int8 v31 = nox_memfile_read_u8(f);
		char v28[16];
		nox_memfile_read(v28, 1, v31, f);
		v28[v31] = 0;
		if (!strcmp(v28, "Loop")) {
			*((_BYTE*)v13 + 10) = 2;
		} else if (!strcmp(v28, "OneShot")) {
			*((_BYTE*)v13 + 10) = 0;
		} else {
			return 0;
		}
		if (v33) {
			int v19 = 0;
			do {
				int v21 = nox_memfile_read_i32(f);
				if (v21 == -1) {
					char v23 = nox_memfile_read_i8(f);
					unsigned __int8 v32 = nox_memfile_read_u8(f);
					_BYTE a2b = v23;
					nox_memfile_read(v28, 1, v32, f);
					v28[v32] = 0;
					*(_DWORD*)(v13[1] + v19) = nox_xxx_loadImage_47A8C0(a2b, v28);
				} else {
					*(_DWORD*)(v13[1] + v19) = &nox_video_bag_images_arr[v21];
				}
				v19 += 4;
				--v27;
			} while (v27);
		}
		nox_images_arr1_787156[nox_images_ind1_787164].field_24 = v13;
		nox_images_ind1_787164++;
		return 1;
	}
	return 0;
}
// 42F660: using guessed type char var_10[16];

//----- (0042F970) --------------------------------------------------------
nox_video_bag_image_t* nox_xxx_gLoadImg_42F970(const char* name) {
	if (!name)
		return 0;
	if (nox_images_ind1_787164 <= 0)
		return 0;
	for (int i = 0; i < nox_images_ind1_787164; i++) {
		nox_things_imageRef_t* p = &nox_images_arr1_787156[i];
		if (strcmp(name, p->name) == 0) {
			if (p->field_24 == -1) {
				if (p->field_25_0 == -1) {
					return 0;
				}
				return nox_xxx_loadImage_47A8C0(p->field_25_0, p->name2);
			}
			return &nox_video_bag_images_arr[p->field_24];
		}
	}
	return 0;
}

//----- (0042FA20) --------------------------------------------------------
nox_things_imageRef_t* nox_xxx_gLoadAnim_42FA20(const char* name) {
	if (!name)
		return 0;
	if (nox_images_ind1_787164 <= 0)
		return 0;
	for (int i = 0; i < nox_images_ind1_787164; i++) {
		if (strcmp(name, nox_images_arr1_787156[i].name) == 0) {
			return &nox_images_arr1_787156[i];
		}
	}
	return 0;
}

//----- (0042FAA0) --------------------------------------------------------
nox_video_bag_image_t* nox_xxx_readImgMB_42FAA0(int known_idx, const char* a2, char* a3) {
	if (known_idx != -1) {
		return &nox_video_bag_images_arr[known_idx];
	}
	return nox_xxx_loadImage_47A8C0(a2, a3);
}

//----- (0042FAD0) --------------------------------------------------------
int sub_42FAD0() { return 0; }

//----- (0042FB30) --------------------------------------------------------
#ifdef NOX_CGO
void* nox_video_getImagePixdata_new(nox_video_bag_image_t* img);
#endif // NOX_CGO
void* nox_video_getImagePixdata_42FB30(nox_video_bag_image_t* img) {
	_DWORD* v5; // ecx
	_DWORD* v6; // eax

	if (dword_5d4594_787224)
		return 0;
	if (!img)
		return 0;
#ifdef NOX_CGO
	// hook for overriding images
	void* nimg = nox_video_getImagePixdata_new(img);
	if (nimg)
		return nimg;
#endif // NOX_CGO
	if ((img->typ & 0x3F) == 7)
		return sub_42FAD0();
	if (img->typ & 0x80)
		return img->offset; // TODO: reuses field for something else?
	dword_5d4594_787224 = 1;
	nox_video_bag_section_t* ent = &nox_video_bag_sections_arr[img->sect_ind];
	if (ent->field_6 == -1) {
		if (!ent->data) {
			ent->data = malloc(ent->size);
			nox_video_bagReadImage_42FE30(ent);
			ent->field_1 = nox_frame_xxx_2598000;
		}
		dword_5d4594_787224 = 0;
		return ent->data;
	}
	if (ent->data) {
		if (ent->field_1 == nox_frame_xxx_2598000) {
			dword_5d4594_787224 = 0;
			return &ent->data[img->offset];
		}
		ent->field_1 = nox_frame_xxx_2598000;
		*(_DWORD*)((char*)ent->field_7 + 32) = ent->field_8;
		*(_DWORD*)((char*)ent->field_8 + 28) = ent->field_7;
	} else {
		if (dword_5d4594_787188 == 0) {
			v5 = *(_DWORD**)getMemAt(0x5D4594, 754136);
			++*getMemU32Ptr(0x5D4594, 787220);
			v6 = (_DWORD*)(*getMemU32Ptr(0x5D4594, 754136) + 28);
			*(_DWORD*)(*(_DWORD*)(*getMemU32Ptr(0x5D4594, 754136) + 28) + 32) = getMemAt(0x5D4594, 754108);
			*getMemU32Ptr(0x5D4594, 754136) = *v6;
			*v6 = 0;
			v5[8] = 0;
			*(_DWORD*)(*getMemU32Ptr(0x5D4594, 787140) + 28) = ent;
			ent->field_7 = getMemAt(0x5D4594, 787108);
			ent->field_8 = *getMemU32Ptr(0x5D4594, 787140);
			*getMemU32Ptr(0x5D4594, 787140) = ent;
			ent->data = *v5;
			*v5 = 0;
			nox_video_bagReadImage_42FE30(ent);
			ent->field_1 = nox_frame_xxx_2598000;
			dword_5d4594_787224 = 0;
			return &ent->data[img->offset];
		}
		--dword_5d4594_787188;
		ent->data = &((char*)nox_video_bag_ptr_787200)[dword_5d4594_787188 * nox_video_bag_var_787176];
		nox_video_bagReadImage_42FE30(ent);
		ent->field_1 = nox_frame_xxx_2598000;
	}
	*(_DWORD*)(*getMemU32Ptr(0x5D4594, 787140) + 28) = ent;
	ent->field_7 = getMemAt(0x5D4594, 787108);
	ent->field_8 = *getMemU32Ptr(0x5D4594, 787140);
	*getMemU32Ptr(0x5D4594, 787140) = ent;
	dword_5d4594_787224 = 0;
	return &ent->data[img->offset];
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

static FILE* nox_video_bag_seek(unsigned int offset) {
	FILE* fp;
#ifdef __EMSCRIPTEN__0
	int i;
	for (i = 0; bag_files[i].path; i++) {
		if (bag_files[i].offset <= offset && offset - bag_files[i].offset < bag_files[i].size) {
			fp = bag_fp[i];
			if (fp == NULL)
				fp = bag_fp[i] = nox_fs_open(bag_files[i].path);
			nox_fs_fseek_start(fp, offset - bag_files[i].offset);
		}
	}
#else
	fp = nox_video_bag_fileptr;
	nox_fs_fseek_start(fp, offset);
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

void  nox_video_bagReadImage_42FE30(nox_video_bag_section_t* ent) {
	// check_preload((a1 - *(_DWORD *)&nox_video_bag_sections_arr) / 36);
	FILE* fp = nox_video_bag_seek(ent->bag_offs);
	int rn = 0;
	if (ent->size == ent->size_comp) {
		rn = nox_binfile_fread2_40ADD0(ent->data, 1, ent->size_comp, fp);
	} else {
		char* buf = 0;
		char* in;
		if (ent->size_comp > nox_video_bag_tmpBufSize_787184) {
			buf = malloc(ent->size_comp);
			in = buf;
			rn = nox_binfile_fread2_40ADD0(buf, 1, ent->size_comp, fp);
		} else {
			in = nox_video_bag_tmpBuf_787208;
			rn = nox_binfile_fread2_40ADD0(nox_video_bag_tmpBuf_787208, 1, ent->size_comp, fp);
		}
		sub_578C30(dword_5d4594_787212);
		int inLeft = ent->size_comp;
		int outLeft = ent->size;
		char* out = ent->data;
		if (nox_xxx_nxzDecompress_578C10(dword_5d4594_787212, &out[ent->size - outLeft], &outLeft, &in[ent->size_comp - inLeft], &inLeft)) {
			while (inLeft > 0 && nox_xxx_nxzDecompress_578C10(dword_5d4594_787212, &out[ent->size - outLeft], &outLeft, &in[ent->size_comp - inLeft], &inLeft)) {}
		}
		if (buf) {
			free(buf);
		}
	}
	if (rn == ent->size_comp && dword_5d4594_3799624 == 2) {
		nox_video_bag_decodeImagesInSection_42FF90(ent);
	}
}

//----- (0042FF90) --------------------------------------------------------
void  nox_video_bag_decodeImagesInSection_42FF90(nox_video_bag_section_t* ent) {
	int v1;     // edx
	int v3;     // ecx
	int v5;     // ebx

	v1 = ent->field_6;
	int result = ent->field_5;
	if (v1 >= 0)
		v3 = result + v1;
	else
		v3 = result - v1;
	if (result < v3) {
		int v4 = result;
		v5 = v3 - result;
		do {
			char typ = nox_video_bag_images_arr[v4].typ;
			if (typ != 0 && typ != 1) {
				nox_video_bag_image_t* img = &nox_video_bag_images_arr[v4];
				nox_video_bag_decodeImageSwitch_47D480(&ent->data[img->offset], img);
			}
			v4++;
			--v5;
		} while (v5);
	}
}

//----- (0042FFF0) --------------------------------------------------------
BOOL  sub_42FFF0(FILE* a1) {
	signed int v1; // edx
	BOOL result;   // eax
	char v3[12];   // [esp+8h] [ebp-2Ch]
	char v4[32];   // [esp+14h] [ebp-20h]

	strcpy(v3, "LOOKUPTABLE");
	v1 = nox_binfile_fread2_40ADD0(v4, 1u, strlen(v3), a1);
	result = 0;
	if (v1 == strlen(v3)) {
		v4[strlen(v3)] = 0;
		if (!strcmp(v4, v3))
			result = nox_binfile_fread2_40ADD0((char*)getMemAt(0x5D4594, 754340), 1u, 0x8000u, a1) == 0x8000;
		else
			result = 0;
	}
	return result;
}
// 42FFF0: using guessed type char var_20[32];

//----- (004300D0) --------------------------------------------------------
bool nox_video_bagexists_4300D0(int a1) {
	char* v1; // eax

	v1 = nox_video_getbagfilename(a1);
	return _access(v1, 0) != -1;
}

//----- (00430100) --------------------------------------------------------
const char* nox_video_getbagfilename(int is16bit) {
#ifdef __EMSCRIPTEN__
	return "video.bag";
#else
    const char* name = "video.bag";
	if (is16bit != 1)
		name = "video8.bag";
	return name;
#endif
}

//----- (00430120) --------------------------------------------------------
char*  nox_video_getBagIdxName_430120(int a1) {
	char* result; // eax

	result = "video.idx";
	if (a1 != 1)
		result = "video8.idx";
	return result;
}

//----- (00430880) --------------------------------------------------------
int  sub_430880(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 805808) = a1;
	return result;
}

//----- (00430890) --------------------------------------------------------
int nox_xxx_get_430890() { return *getMemU32Ptr(0x5D4594, 805808); }

//----- (00430AA0) --------------------------------------------------------
int  sub_430AA0(int a1) {
	int result; // eax

	result = a1 - 1;
	if (a1 == 1) {
		dword_5d4594_805820 = 1;
		nox_xxx_useAudio_587000_80772 = 9;
	} else {
		result = a1 - 2;
		if (a1 == 2) {
			dword_5d4594_805820 = 2;
			nox_xxx_useAudio_587000_80772 = 13;
		} else {
			dword_5d4594_805820 = 0;
			nox_xxx_useAudio_587000_80772 = 5;
		}
	}
	return result;
}

//----- (00430AF0) --------------------------------------------------------
int nox_client_mousePriKey_430AF0() { return dword_5d4594_805820; }

//----- (00430B00) --------------------------------------------------------
int nox_xxx_cursor_430B00() { return nox_xxx_useAudio_587000_80772; }

//----- (00430B10) --------------------------------------------------------
void  nox_client_setMousePos_430B10(int x, int y) { nox_client_changeMousePos_430A00(x, y, true); }

#ifndef NOX_CGO
//----- (00430B30) --------------------------------------------------------
int sub_430B30() { return *getMemU32Ptr(0x5D4594, 805804); }
#endif // NOX_CGO

//----- (00430B50) --------------------------------------------------------
int  sub_430B50(int a1, int a2, int a3, int a4) {
	int result; // eax

	dword_5d4594_3807140 = a1;
	result = a4;
	dword_5d4594_3807136 = a2;
	dword_5d4594_3807116 = a3;
	dword_5d4594_3807152 = a4;
	return result;
}

//----- (00430B80) --------------------------------------------------------
char*  sub_430B80(_DWORD* a1) {
	*a1 = dword_5d4594_3804684;
	return (char*)getMemAt(0x973F18, 6088);
}

#ifndef NOX_CGO
//----- (00430BB0) --------------------------------------------------------
void  sub_430BB0(_DWORD* a1, _DWORD* a2, _DWORD* a3) {
	*a1 = nox_backbuffer_width;
	*a2 = nox_backbuffer_height;
	*a3 = dword_5d4594_3801780 != 0 ? 16 : 8;
}

//----- (00430BE0) --------------------------------------------------------
void input_set_draw_win_size(int w, int h);
void nox_video_resizewnd(int w, int h, int d) {
	printf("New size: %d, %d\n", w, h);

	nox_win_width = w;
	if (w > nox_max_width)
		nox_win_width = nox_max_width;
	nox_win_height = h;
	if (h > nox_max_height)
		nox_win_height = nox_max_height;
	d = 16;
	nox_video_16bit = d != 8;
	input_set_draw_win_size(nox_win_width, nox_win_height);
}

//----- (00430C30) --------------------------------------------------------
void  sub_430C30_set_video_max(int w, int h) {
	nox_max_width = w;
	nox_max_height = h;
}

//----- (00430C50) --------------------------------------------------------
void  nox_xxx_screenGetSize_430C50_get_video_max(int* w, int* h) {
	*w = nox_max_width;
	*h = nox_max_height;
}

//----- (00430D40) --------------------------------------------------------
BOOL nox_xxx_testMMXSupport_430D40() {
	BOOL result; // eax

	if (*getMemU32Ptr(0x5D4594, 805840))
		result = 0;
	else
		result = nox_xxx_testCPUID2_444D90();
	return result;
}
#endif // NOX_CGO

//----- (00430DB0) --------------------------------------------------------
int  nox_xxx_tileInitBuf_430DB0(int a1, int a2) {
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
	v2 = ((46 * dword_5d4594_3798812) << getMemByte(0x973F18, 7696)) * 46 * dword_5d4594_3798816;
	dword_5d4594_3798804 = (46 * dword_5d4594_3798812) << getMemByte(0x973F18, 7696);
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

	result = nox_xxx_useMMX_587000_80800;
	if (nox_xxx_useMMX_587000_80800) {
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
void nox_xxx_freeFloorBuffer_430EF0() { nox_video_freeFloorBuffer_430EC0(); }

//----- (00430F00) --------------------------------------------------------
int screenshot_num = 0;

//----- (004310B0) --------------------------------------------------------
int  nox_audio_initall(int a3) {
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
	nox_xxx_WorkerHurt_44D810();
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
#ifndef NOX_CGO
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
#endif // NOX_CGO

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
// 487CF0: using guessed type void  nullsub_10(_DWORD);

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
#ifndef NOX_CGO
void sub_4312B0() {
	sub_431290();
	sub_44D8F0();
	sub_43D990();
}

//----- (004312C0) --------------------------------------------------------
void sub_4312C0() {
	if (dword_5d4594_805988) {
		return;
	}
	dword_5d4594_805988 = 1;
	__int64 v1 = nox_platform_get_ticks();
	__int64 v3 = v1 - *getMemU64Ptr(0x5D4594, 805996);
	if (v3 > 33) {
		sub_44D3A0();
		sub_43D440();
		*getMemU64Ptr(0x5D4594, 805996) = v1;
	}
	dword_5d4594_805988 = 0;
}
#endif // NOX_CGO

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
	nox_alloc_class_yyy_4144D0(nox_alloc_screenParticles_806044);
	nox_screenParticles_head = 0;
	dword_5d4594_806052 = 0;
	nox_xxx_particlesLoadColor_4313E0();
	return 1;
}

//----- (004313E0) --------------------------------------------------------
int nox_xxx_particlesLoadColor_4313E0() {
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
void nox_xxx_freeScreenParticles_4314D0() {
	if (nox_alloc_screenParticles_806044)
		nox_free_alloc_class(*(LPVOID*)&nox_alloc_screenParticles_806044);
	nox_alloc_screenParticles_806044 = 0;
	nox_screenParticles_head = 0;
	dword_5d4594_806052 = 0;
}

//----- (00431510) --------------------------------------------------------
int sub_431510() {
	if (nox_alloc_screenParticles_806044)
		nox_alloc_class_yyy_4144D0(*(_DWORD**)&nox_alloc_screenParticles_806044);
	nox_screenParticles_head = 0;
	dword_5d4594_806052 = 0;
	return nox_xxx_particlesLoadColor_4313E0();
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
void  sub_431700(_QWORD* a1) {
	sub_4316C0((int)a1);
	nox_alloc_class_free_obj(*(unsigned int**)&nox_alloc_screenParticles_806044, a1);
}

//----- (00431720) --------------------------------------------------------
void  nox_client_screenParticlesDraw_431720(nox_draw_viewport_t* rdr) {
	if (!rdr) {
		return;
	}
	sub_430B50(rdr->x1, rdr->y1, rdr->x2, rdr->y2);
	nox_screenParticle* p2 = 0;
	for (nox_screenParticle* p = nox_screenParticles_head; p; p = p2) {
		dword_5d4594_3799524 = 1;
		p2 = p->field_44; // getting it after the callback may fail
		p->draw_fnc(rdr, p);
	}
}

//----- (00431770) --------------------------------------------------------
char* nox_xxx_getHostInfoPtr_431770() { return (char*)getMemAt(0x5D4594, 807172); }

//----- (00431780) --------------------------------------------------------
char* nox_xxx_unused_431780() { return (char*)getMemAt(0x5D4594, 806060); }

//----- (00431790) --------------------------------------------------------
char*  nox_xxx_copyServerIPAndPort_431790(char* a1) {
	char* result; // eax

	result = a1;
	if (a1)
		result = strncpy((char*)getMemAt(0x5D4594, 806060), a1, 0x17u);
	return result;
}
// 4335F8: variable 'v12' is possibly undefined


//----- (00433E80) --------------------------------------------------------
void  sub_433E80(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3) {
	ptr_5D4594_3799572->data[44] = a1;
	ptr_5D4594_3799572->data[45] = a2;
	ptr_5D4594_3799572->data[46] = a3;
}

//----- (00433F10) --------------------------------------------------------
int  nox_xxx_drawMakeRGB_433F10(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3) {
	int result;          // eax
	__int64 v4;          // rax
	unsigned __int64 v5; // rax
	unsigned __int64 v6; // rax

	result = a1;
	ptr_5D4594_3799572->data[54] = a1;
	ptr_5D4594_3799572->data[55] = a2;
	ptr_5D4594_3799572->data[56] = a3;
#ifndef NOX_CGO
	if (cpuid_5d4594_3801804) {
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
#endif // NOX_CGO
	return result;
}

//----- (00434080) --------------------------------------------------------
int  sub_434080(int a1) {
	int result; // eax

	result = a1;
	ptr_5D4594_3799572->data[262] = a1;
	return result;
}

//----- (00434350) --------------------------------------------------------
int  nox_xxx_drawSelectColor_434350(int a1) {
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
int  nox_xxx_drawSetTextColor_434390(int a1) {
	ptr_5D4594_3799572->data[59] = a1;
	return a1;
}

//----- (004343E0) --------------------------------------------------------
int  nox_xxx_drawSetColor_4343E0(int a1) {
	ptr_5D4594_3799572->data[60] = a1;
	return a1;
}

//----- (00434460) --------------------------------------------------------
int  nox_client_drawSetColor_434460(int a1) {
	ptr_5D4594_3799572->data[61] = a1;
	return a1;
}

//----- (004344D0) --------------------------------------------------------
int  nox_xxx_unused_4344D0(_BYTE* a1) {
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
char*  sub_434510(char* a1, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 a4) {
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
int  nox_client_drawEnableAlpha_434560(int a1) {
	if (ptr_5D4594_3799572->data[13] != a1)
		ptr_5D4594_3799572->data[13] = a1;
	return ptr_5D4594_3799572;
}

//----- (00434580) --------------------------------------------------------
int  nox_client_drawSetAlpha_434580(unsigned __int8 a1) {
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
int  sub_4345F0(int a1) {
	ptr_5D4594_3799572->data[14] = a1;
	return a1;
}

//----- (00434600) --------------------------------------------------------
int  nox_xxx_draw_434600(int a1) {
	ptr_5D4594_3799572->data[17] = a1;
	return a1;
}

//----- (00434610) --------------------------------------------------------
int  sub_434610(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_810636 = a1;
	return result;
}

//----- (00434620) --------------------------------------------------------
int  sub_434620(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_810632 = a1;
	return result;
}

//----- (00434630) --------------------------------------------------------
unsigned __int8  sub_434630(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3) {
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
	v4 = getMemAt(0x973F18, 5096);
	if (*(int*)&dword_5d4594_808568 <= 0) {
	LABEL_6:
		v5 = a1;
		v6 = a1 | ((a2 | (a3 << 8)) << 8);
		v7 = 0;
		v15 = 255;
		do {
			v8 = (v7 + v15) / 2;
			if (v6 >= *getMemIntPtr(0x5D4594, 809604 + 4 * v8)) {
				if (!v6)
					return getMemByte(0x5D4594, 808304 + v8);
				v7 = v8 + 1;
			} else {
				v15 = v8 - 1;
			}
		} while (v7 <= v15);
		v17 = 195075;
		v18 = 0;
		v16 = 0;
		v10 = getMemAt(0x973F18, 3882);
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
		*getMemU8Ptr(0x973F18, 5096 + 4 * dword_5d4594_810628) = a1;
		v14 = getMemAt(0x973F18, 5096 + 4 * v13);
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
char  sub_4347C0(char a1) {
	char result; // al
	int v2;      // ecx

	result = a1;
	v2 = 256;
	do {
		--v2;
		*getMemU8Ptr(0x973F18, 3882) = a1;
		*getMemU8Ptr(0x973F18, 3881) = a1;
		*getMemU8Ptr(0x973F18, 3880) = a1;
		*getMemU8Ptr(0x973F18, 3883) = 0;
	} while (v2);
	return result;
}

//----- (00434820) --------------------------------------------------------
int  sub_434820(int a1, char a2, char a3, char a4) {
	if (a1 < 0 || a1 >= 256)
		return 0;
	*getMemU8Ptr(0x973F18, 3880 + 4 * a1) = a2;
	*getMemU8Ptr(0x973F18, 3881 + 4 * a1) = a3;
	*getMemU8Ptr(0x973F18, 3882 + 4 * a1) = a4;
	*getMemU8Ptr(0x973F18, 3883 + 4 * a1) = 4;
	sub_435040();
	sub_434F00();
	nox_xxx_makeFillerColor_48BDE0();
	return 1;
}

//----- (00434870) --------------------------------------------------------
int  sub_434870(int a1, _BYTE* a2, _BYTE* a3, _BYTE* a4) {
	if (a1 < 0 || a1 >= 256)
		return 0;
	if (a2)
		*a2 = getMemByte(0x973F18, 3880 + 4 * a1);
	if (a3)
		*a3 = getMemByte(0x973F18, 3881 + 4 * a1);
	if (a4)
		*a4 = getMemByte(0x973F18, 3882 + 4 * a1);
	return 1;
}

//----- (00434920) --------------------------------------------------------
int sub_434920() {
	int result; // eax

	if (dword_5d4594_808564)
		return 0;
	result = 1;
	memcpy(getMemAt(0x5D4594, 808572), getMemAt(0x973F18, 3880), 0x400u);
	dword_5d4594_808564 = 1;
	return result;
}

//----- (00434950) --------------------------------------------------------
int sub_434950() {
	if (!dword_5d4594_808564)
		return 0;
	dword_5d4594_808564 = 0;
	memcpy(getMemAt(0x973F18, 3880), getMemAt(0x5D4594, 808572), 0x400u);
	sub_435040();
	sub_434F00();
	return 1;
}

//----- (00434990) --------------------------------------------------------
int  sub_434990(int a1, int a2, int a3) {
	ptr_5D4594_3799572->data[62] = a1;
	ptr_5D4594_3799572->data[63] = a2;
	ptr_5D4594_3799572->data[64] = a3;
	return a2;
}

//----- (004349C0) --------------------------------------------------------
int  sub_4349C0(_DWORD* a1) {
	ptr_5D4594_3799572->data[62] = *a1;
	ptr_5D4594_3799572->data[63] = a1[1];
	ptr_5D4594_3799572->data[64] = a1[2];
	return a1[2];
}

//----- (00434A00) --------------------------------------------------------
int sub_434A00() { return (_DWORD)(&ptr_5D4594_3799572->data[62]); }

//----- (00434A10) --------------------------------------------------------
_DWORD*  sub_434A10(_DWORD* a1, _DWORD* a2, _DWORD* a3) {
	if (a1)
		*a1 = ptr_5D4594_3799572->data[62];
	if (a2)
		*a2 = ptr_5D4594_3799572->data[63];
	if (a3)
		*a3 = ptr_5D4594_3799572->data[64];
	return a3;
}

//----- (00434A60) --------------------------------------------------------
char  sub_434A60(int a1) {
	return *(_BYTE*)(dword_5d4594_3804668 + (((unsigned __int8)(getMemByte(0x973F18, 3882 + 4 * a1) & 0xF8) >> 3) |
											 (4 * (getMemByte(0x973F18, 3881 + 4 * a1) & 0xF8)) |
											 ((getMemByte(0x973F18, 3880 + 4 * a1) & 0xF8) << 7)));
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
char  sub_434E80(char a1, char a2, char a3) {
	return *(_BYTE*)(dword_5d4594_3804668 +
					 (((unsigned __int8)(a3 & 0xF8) >> 3) | (4 * (a2 & 0xF8)) | ((a1 & 0xF8) << 7)));
}

//----- (00434EC0) --------------------------------------------------------
char  sub_434EC0(char a1, char a2, char a3) {
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

	data = getMemAt(0x973F18, 3880);
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
		*getMemU8Ptr(0x5D4594, 808304 + i) = buf[i].field_0;
	}
	dword_5d4594_808568 = 0;
	dword_5d4594_810628 = 0;
}

//----- (004350E0) --------------------------------------------------------
_BYTE*  sub_4350E0(_BYTE* a1, _BYTE* a2) {
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
void  sub_435120(_BYTE* a1, char* a2) {
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
void  sub_435150(_BYTE* a1, char* a2) {
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

#ifndef NOX_CGO
//----- (00435180) --------------------------------------------------------
void nox_color_func_435180(uint8_t r, uint8_t g, uint8_t b, uint32_t* color) {
	uint8_t c = sub_434630(r, g, b);
	uint32_t val = c | (c << 8);
	*color = val | (val << 16);
}

//----- (004351C0) --------------------------------------------------------
void nox_color_rgba5551ext_4351C0(uint8_t r, uint8_t g, uint8_t b, uint32_t* color) {
	uint32_t val = (b >> 3) | (4 * (g & 0xF8 | (32 * (r & 0xF8))));
	*color = val | (val << 16);
}

//----- (00435200) --------------------------------------------------------
void nox_color_rgb565ext_435200(uint8_t r, uint8_t g, uint8_t b, uint32_t* color) {
	uint32_t val = (b >> 3) | (8 * (g & 0xFC | (32 * (r & 0xF8))));
	*color = val | (val << 16);
}
#endif // NOX_CGO

//----- (00435240) --------------------------------------------------------
void  sub_435240(unsigned __int8 a1, _BYTE* a2, _BYTE* a3, char* a4) {
	int v4;      // eax
	char result; // al

	v4 = 4 * a1;
	*a2 = getMemByte(0x973F18, 3880 + v4);
	*a3 = getMemByte(0x973F18, 3881 + v4);
	result = getMemByte(0x973F18, 3882 + v4);
	*a4 = result;
}

//----- (00435280) --------------------------------------------------------
void  sub_435280(__int16 a1, _BYTE* a2, _BYTE* a3, _BYTE* a4) {
	char result; // al

	*a2 = (unsigned __int16)(*((_WORD*)((_BYTE*)byte_5D4594_3804364 + 0)) & a1) >> *((_BYTE*)byte_5D4594_3804364 + 12);
	*a3 = (unsigned __int16)(*((_WORD*)((_BYTE*)byte_5D4594_3804364 + 4)) & a1) >> *((_BYTE*)byte_5D4594_3804364 + 16);
	result = ((unsigned __int8)a1 & *((_BYTE*)byte_5D4594_3804364 + 8)) << *((_BYTE*)byte_5D4594_3804364 + 20);
	*a4 = result;
}

//----- (00435570) --------------------------------------------------------
__int64 nox_xxx_initTime_435570() {
	__int64 result; // rax

	result = nox_platform_get_ticks();
	*getMemU64Ptr(0x5D4594, 811908) = result;
	return result;
}

//----- (00435590) --------------------------------------------------------
int sub_435590() { return *getMemU32Ptr(0x5D4594, 811916); }

//----- (004355B0) --------------------------------------------------------
int  sub_4355B0(int a1) {
	int result; // eax

	result = a1;
	nox_draw_viewport.field_12 = a1;
	return result;
}

//----- (004355C0) --------------------------------------------------------
BOOL sub_4355C0() {
	int v0;    // eax
	float2 v2; // [esp+0h] [ebp-8h]

	v2.field_0 = (double)nox_draw_viewport.field_6;
	v2.field_4 = (double)nox_draw_viewport.field_7;
	v0 = nox_xxx_tileNFromPoint_411160(&v2);
	return v0 == 255 || v0 == -1;
}

//----- (00435600) --------------------------------------------------------
void nox_xxx_cliUpdateCameraPos_435600(int a1, int a2) {
	int v2 = a2 + nox_draw_viewport.field_12 - nox_draw_viewport.height / 2;
	*getMemU32Ptr(0x5D4594, 811364) = nox_draw_viewport.field_6;
	*getMemU32Ptr(0x5D4594, 811368) = nox_draw_viewport.field_7;
	nox_draw_viewport.field_6 = a1;
	nox_draw_viewport.field_7 = v2 + nox_draw_viewport.height / 2;
	nox_draw_viewport.field_4 = a1 - nox_draw_viewport.width / 2;
	nox_draw_viewport.field_5 = a2 + nox_draw_viewport.field_12 - nox_draw_viewport.height / 2;
}

//----- (00435670) --------------------------------------------------------
void  nox_xxx_getSomeCoods_435670(int2* a1) { *a1 = *(int2*)(&nox_draw_viewport.field_6); }

//----- (00435690) --------------------------------------------------------
_DWORD*  sub_435690(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	*a1 = *getMemU32Ptr(0x5D4594, 811364);
	a1[1] = *getMemU32Ptr(0x5D4594, 811368);
	return result;
}

#ifndef NOX_CGO
//----- (004356B0) --------------------------------------------------------
int nox_xxx_gameGetPlayState_4356B0() { return nox_game_playState_811372; }
void nox_xxx_gameSetPlayState_4356B0(int v) { nox_game_playState_811372 = v; }
#endif // NOX_CGO

//----- (004356C0) --------------------------------------------------------
BOOL  nox_xxx_spriteTestBuf_4356C0(nox_drawable* dr, char a2) {
	int a1 = dr;
	BOOL result; // eax

	result = a1;
	if (a1)
		result = ((1 << a2) & *(_DWORD*)(a1 + 124)) != 0;
	return result;
}

//----- (004356E0) --------------------------------------------------------
void nox_xxx_spriteLoadError_4356E0() { *getMemU32Ptr(0x587000, 85720) = 0; }

//----- (004356F0) --------------------------------------------------------
char* nox_xxx_unused_4356F0() { return (char*)getMemAt(0x5D4594, 811280); }

//----- (00435700) --------------------------------------------------------
wchar_t*  sub_435700(wchar_t* a1, int a2) {
	wchar_t* result; // eax

	result = nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 811376), a1);
	*getMemU32Ptr(0x5D4594, 811060) = a2;
	return result;
}

//----- (00435720) --------------------------------------------------------
#ifndef NOX_CGO
void nox_client_setServerConnectAddr_435720(char* addr) {
	strncpy(nox_clientServerAddr, addr, 32);
}
char* nox_client_getServerConnectAddr() {
	return nox_clientServerAddr;
}
#endif // NOX_CGO

//----- (00435740) --------------------------------------------------------
DWORD sub_435740() {
	DWORD result; // eax

	result = nox_platform_get_ticks();
	*getMemU32Ptr(0x5D4594, 811924) = result;
	return result;
}

//----- (00435750) --------------------------------------------------------
DWORD sub_435750() {
	DWORD result; // eax

	result = nox_platform_get_ticks() - *getMemU32Ptr(0x5D4594, 811924);
	*getMemU32Ptr(0x5D4594, 811928) = result;
	return result;
}

//----- (00435770) --------------------------------------------------------
DWORD nox_xxx_time_startProfile_435770() {
	DWORD result; // eax

	result = nox_platform_get_ticks();
	*getMemU32Ptr(0x5D4594, 811932) = result;
	return result;
}

//----- (00435780) --------------------------------------------------------
DWORD nox_xxx_time_endProfile_435780() {
	DWORD result; // eax

	result = nox_platform_get_ticks() - *getMemU32Ptr(0x5D4594, 811932);
	*getMemU32Ptr(0x5D4594, 811936) = result;
	return result;
}

//----- (004357A0) --------------------------------------------------------
int nox_xxx_cliToggleObsWindow_4357A0() {
	int result; // eax

	if (*getMemU32Ptr(0x8531A0, 2576) && *(_BYTE*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 1)
		result = nox_xxx_showObserverWindow_48CA70(0);
	else
		result = nox_xxx_showObserverWindow_48CA70(1);
	return result;
}

//----- (004357D0) --------------------------------------------------------
BOOL  nox_xxx_clientResetSpriteAndGui_4357D0(int argc, const char** argv) {
	*getMemU32Ptr(0x85319C, 0) = 0;
	*getMemU32Ptr(0x852978, 8) = 0;
	*getMemU32Ptr(0x8531A0, 2576) = 0;
	strcpy((char*)getMemAt(0x5D4594, 811280), nox_xxx_getRandomName_4358A0());
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
	nox_netlist_resetAll_40EE60();
	if (!nox_common_gameFlags_check_40A5C0(1))
		nox_xxx_cliResetAllPlayers_416E30();
	BOOL result = nox_xxx_chatInit_48D7D0();
	if (!result) {
		return 0;
	}
	sub_4E4EF0();
	sub_48D740();
	nox_xxx_gameSetCliConnected_43C720(0);
	nox_gameDisableMapDraw_5d4594_2650672 = 0;
	sub_473930();
	sub_48D4B0(0);
	return 1;
}

//----- (00435A10) --------------------------------------------------------
int  nox_xxx_whenServerHostServer_435A10(signed int* a1) {
	char* v1;            // ebx
	int result;          // eax
	unsigned __int16 v3; // ax
	int v4;              // [esp+Ch] [ebp-A8h]
	int v5;              // [esp+10h] [ebp-A4h]
	int v6;              // [esp+14h] [ebp-A0h]
	BYTE Data[153];      // [esp+18h] [ebp-9Ch]

	nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(&v5, &v4, &v6);
	v1 = nox_xxx_getHostInfoPtr_431770();
	nox_wcscpy((wchar_t*)v1, (const wchar_t*)getMemAt(0x85B3FC, 12204));
	v1[66] = getMemByte(0x85B3FC, 12254);
	*(_WORD*)(v1 + 71) = *getMemU16Ptr(0x85B3FC, 12184);
	v1[73] = getMemByte(0x85B3FC, 12186);
	*((_WORD*)v1 + 34) = *getMemU16Ptr(0x85B3FC, 12187);
	v1[70] = getMemByte(0x85B3FC, 12189);
	*((_WORD*)v1 + 37) = *getMemU16Ptr(0x85B3FC, 12190);
	v1[76] = getMemByte(0x85B3FC, 12192);
	*(_WORD*)(v1 + 77) = *getMemU16Ptr(0x85B3FC, 12193);
	v1[79] = getMemByte(0x85B3FC, 12195);
	*((_WORD*)v1 + 40) = *getMemU16Ptr(0x85B3FC, 12196);
	v1[82] = getMemByte(0x85B3FC, 12198);
	v1[83] = getMemByte(0x85B3FC, 12199);
	v1[84] = getMemByte(0x85B3FC, 12200);
	v1[85] = getMemByte(0x85B3FC, 12201);
	v1[86] = getMemByte(0x85B3FC, 12202);
	v1[87] = getMemByte(0x85B3FC, 12203);
	v1[67] = getMemByte(0x85B3FC, 12255);
	sub_48D740();
	*(_DWORD*)&Data[97] = v5;
	*(_DWORD*)&Data[101] = v4;
	nox_xxx_regGetSerial_420120(&Data[105]);
	if (!nox_xxx_check_flag_aaa_43AF70())
		nox_common_getInstallPath_40E0D0((int)&Data[105], "SOFTWARE\\Westwood\\Nox", 0);
	Data[152] = !nox_xxx_checkHasSoloMaps_40ABD0();
	if (getMemByte(0x85B3FC, 10980) & 4)
		Data[152] |= 0x80u;
	strcpy((char*)&Data[142], (const char*)getMemAt(0x85B3FC, 10395));
	strcpy((char*)&Data[128], sub_41FA40());
	*(_DWORD*)&Data[138] = dword_5d4594_2660032;
	memcpy(Data, v1, 0x61u);
	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_replay_4D3860(Data);
		*getMemU32Ptr(0x85319C, 0) = nox_xxx_playerNew_4DD320(31, (int)Data);
		nox_client_setVersion_409AE0(NOX_CLIENT_VERS_CODE);
		nox_netlist_receiveCli_494E90(31);
	} else {
		v3 = nox_client_getServerPort_43B320();
		result = nox_xxx_netAddNetStruct4Host_43C7B0(nox_client_getServerConnectAddr(), v3, (int)Data, a1);
		if (!result)
			return result;
		nox_netlist_resetByInd_40ED10(31, 0);
		nox_xxx_set3512_40A340(0);
		nox_xxx_setMapCRC_40A360(0);
		result = nox_xxx_servNetInitialPacketsUntilCRC_43CFF0();
		if (!result) {
			*a1 = -19;
			return result;
		}
		if (nox_client_getVersionCode_409AD0() != NOX_CLIENT_VERS_CODE) {
			*a1 = -20;
			return 0;
		}
		printf("foo 7\n");
	}
	nox_xxx_gameSetPlayState_4356B0(2);
	if (!nox_common_gameFlags_check_40A5C0(1))
		sub_417C60();
	return 1;
}

//----- (00435CC0) --------------------------------------------------------
#ifndef NOX_CGO
int nox_xxx_initGameSession_435CC0() {
	sub_445450();
	sub_45DB90();
	sub_41D1A0(0);
	nox_xxx_initTime_435570();
	nox_client_gui_flag_1556112 = 0;

	if (!nox_alloc_drawable_init(5000))
		return 0;

	if (!sub_49A8E0_init())
		return 0;

	if (!nox_xxx_allocArrayHealthChanges_49A5F0())
		return 0;

	if (!nox_xxx_parseThingBinClient_44C840_read_things())
		return 0;

	if (!nox_xxx_loadGuides_427070())
		return 0;

	if (!sub_494F00())
		return 0;

	if (!nox_game_guiInit_473680())
		return 0;

	nox_alloc_npcs();
	if (!nox_xxx_loadReflSheild_499360())
		return 0;

	nox_xxx_initSight_485F80();
	if (!sub_4960B0())
		return 0;

	if (!sub_473A40())
		return 0;

	if (!nox_xxx_allocArrayDrawableFX_495AB0())
		return 0;

	if (!nox_xxx_allocClassListFriends_495980())
		return 0;

	sub_4958F0();
	nox_xxx_gameSetCliConnected_43C720(0);
	nox_xxx_setGameFlags_40A4D0(0x800000);
	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_netPlayerIncomingServ_4DDF60(31);
	} else {
		nox_xxx_netSendIncomingClient_43CB00();
	}
	nox_game_SetCliDrawFunc(nox_xxx_client_435F80_draw);
	nox_xxx_gameSetPlayState_4356B0(3);
	*getMemU32Ptr(0x587000, 85720) = 1;
	nox_draw_viewport.x1 = 0;
	nox_draw_viewport.y1 = 0;
	nox_draw_viewport.x2 = nox_win_width - 1;
	nox_draw_viewport.y2 = nox_win_height - 1;
	nox_draw_viewport.width = nox_win_width;
	nox_draw_viewport.height = nox_win_height;
	nox_draw_viewport.field_10 = 0;
	nox_draw_viewport.field_11 = 0;
	nox_draw_viewport.field_12 = 0;
	int v1 = nox_video_getCutSize_4766D0();
	nox_draw_setCutSize_476700(v1, 0);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_41CC00((char*)getMemAt(0x85B3FC, 10984));
	} else if (sub_4D6F50() || sub_4D6F70()) {
		if (sub_4D6F50() || sub_4D6F70()) {
			sub_460380();
			nox_xxx_cliPrepareGameplay1_460E60();
			nox_xxx_cliPrepareGameplay2_4721D0();
		}
		if (!nox_common_gameFlags_check_40A5C0(1)) {
			sub_41CC00((char*)getMemAt(0x85B3FC, 10984));
		}
	}
	nox_xxx_plrLoad_41A480((char*)getMemAt(0x85B3FC, 10984));
	nox_server_parseCmdText_443C80(L"execrul autoexec.rul", 1);
	sub_4951C0();
	sub_465DE0(0);
	return 1;
}

//----- (00435EB0) --------------------------------------------------------
int sub_435EB0() {
	nox_common_writecfgfile("nox.cfg");
	if (nox_common_gameFlags_check_40A5C0(1))
		nox_xxx_playerDisconnFinish_4DE530(31, 2);
	else
		nox_xxx_cliSendOutgoingClient_43CB50();
	sub_499450();
	nox_xxx_gameClearAll_467DF0(0);
	sub_495AE0();
	sub_4959D0();
	sub_473B30_free();
	sub_496120();
	sub_473840();
	nox_things_free_44C580();
	sub_49A950_free();
	nox_drawable_free();
	sub_49AEA0();
	nox_xxx_j_resetNPCRenderData_49A2E0();
	sub_4951C0();
	nox_xxx_gameSetPlayState_4356B0(2);
	return 1;
}
#endif // NOX_CGO
// 49A2E0: using guessed type int nox_xxx_j_resetNPCRenderData_49A2E0(void);

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
#ifndef NOX_CGO
int nox_xxx_client_435F80_draw() {
	nox_point mpos = nox_client_getMousePos_4309F0();
	if (nox_xxx_serverIsClosing_446180())
		sub_446190();
	if (!sub_437060() && !nox_common_gameFlags_check_40A5C0(8)) {
		nox_xxx_setContinueMenuOrHost_43DDD0(0);
		return 0;
	}
	sub_437100();
	if (!sub_478030() && !nox_xxx_guiCursor_477600())
		sub_470DE0();
	nox_xxx_input_42D220();
	if (nox_xxx_get_430890() == 1)
		sub_430880(0);
	nox_xxx_clientEnumHover_476FA0();
	if (!nox_xxx_clientSendInput_43C8F0(31, nox_draw_viewport.field_4 + mpos.x - nox_draw_viewport.x1,
					nox_draw_viewport.field_5 + mpos.y - nox_draw_viewport.y1))
		return 1;
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		sub_40B970();
		sub_40B790();
	}
	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_spriteDeleteSomeList_49C4B0();
		if (!nox_netlist_receiveCli_494E90(31))
			return 1;
	} else {
		sub_43CCA0();
	}
	sub_49BD70(&nox_draw_viewport);
	sub_49BBC0();
	nox_xxx_polygonDrawColor_421B80();
	if (nox_client_isConnected_43C700())
		nox_xxx_cliToggleObsWindow_4357A0();
	nox_xxx_clientDrawAll_436100_draw();
	sub_49BB40();
	sub_49BA70();
	if (sub_409F40(4096))
		nox_xxx_screenshot_46D830();
	if (*getMemU32Ptr(0x5D4594, 826068))
		nox_xxx_motd_4467F0();
	if (sub_42EBA0() == 1) {
		sub_42EB90(0);
		nox_xxx_consoleEsc_49B7A0();
	}
	sub_49B6E0();
	return *getMemU32Ptr(0x587000, 85720);
}
#endif // NOX_CGO
// 435F91: variable 'v1' is possibly undefined

//----- (00436550) --------------------------------------------------------
BOOL sub_436550() {
	int v0; // eax

	if (sub_459DA0() || nox_gui_xxx_check_446360() || sub_49CB40() || sub_49C810() || sub_446950() || sub_4706A0() || nox_gui_console_flagXxx_451410()) {
		v0 = nox_frame_xxx_2598000;
	} else {
		v0 = nox_frame_xxx_2598000;
		if (nox_frame_xxx_2598000 != 2)
			return nox_frame_xxx_2598000 - *getMemU32Ptr(0x5D4594, 811920) == 1;
	}
	*getMemU32Ptr(0x5D4594, 811920) = v0;
	return 1;
}

//----- (00437060) --------------------------------------------------------
#ifndef NOX_CGO
int sub_437060() {
	char* v0; // eax
	char i;   // cl
	bool v2;  // zf

	if (!sub_46A4A0()) {
		v0 = nox_xxx_wndKeyGet_430940();
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
					v2 = nox_xxx_guiCursor_477600() == 0;
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
#endif // NOX_CGO

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
void sub_437180() {
	sub_48D990(&nox_draw_viewport);
}

//----- (00437190) --------------------------------------------------------
#ifndef NOX_CGO
int nox_xxx_cliSetupSession_437190() {
	int result; // eax

	if (nox_xxx_check_flag_aaa_43AF70() == 1)
		sub_40D380();
	sub_473960();
	nox_xxx_cliResetAllPlayers_416E30();
	sub_455EE0();
	sub_456240();
	sub_48D800();
	sub_49A8C0();
	sub_470550();
	sub_46C5D0();
	sub_44DF70();
	if (!nox_common_gameFlags_check_40A5C0(1))
		sub_43CC80();
	nox_xxx_gameSetPlayState_4356B0(0);
	if (!nox_common_gameFlags_check_40A5C0(1))
		sub_4E4DE0();
	nox_xxx_mapLoad_40A380();
	nox_client_setServerConnectAddr_435720("");
	sub_446580(1);
	sub_48D760();
	if (!nox_common_gameFlags_check_40A5C0(1))
		nox_netlist_resetAll_40EE60();
	result = sub_417CF0();
	*getMemU32Ptr(0x85319C, 0) = 0;
	*getMemU32Ptr(0x852978, 8) = 0;
	*getMemU32Ptr(0x8531A0, 2576) = 0;
	return result;
}
#endif // NOX_CGO

//----- (00437250) --------------------------------------------------------
nox_draw_viewport_t* nox_draw_getViewport_437250() { return &nox_draw_viewport; }

//----- (00437260) --------------------------------------------------------
void sub_437260() {
	nox_client_copyRect_49F6F0(nox_draw_viewport.x1, nox_draw_viewport.y1, nox_draw_viewport.width, nox_draw_viewport.height);
}

//----- (00437290) --------------------------------------------------------
int4* sub_437290() { return nox_client_copyRect_49F6F0(0, 0, nox_getBackbufWidth(), nox_getBackbufHeight()); }

//----- (004372B0) --------------------------------------------------------
BOOL nox_xxx_playerAnimCheck_4372B0() {
	int v0;      // eax
	BOOL result; // eax

	result = 1;
	if (*getMemU32Ptr(0x852978, 8)) {
		v0 = *(_DWORD*)(*getMemU32Ptr(0x852978, 8) + 276);
		if (v0 != 1 && v0 != 2 && v0 != 51)
			result = 0;
	}
	return result;
}

//----- (004372E0) --------------------------------------------------------
BOOL nox_xxx_clientIsObserver_4372E0() {
	BOOL result; // eax

	if (*getMemU32Ptr(0x8531A0, 2576) && *(_DWORD*)(*getMemU32Ptr(0x8531A0, 2576) + 2092) == 1)
		result = (*(_DWORD*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 3) != 0;
	else
		result = 0;
	return result;
}

//----- (00437320) --------------------------------------------------------
int  sub_437320(int a1) {
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
		*(_DWORD*)(*(_DWORD*)(a1 + 28) + 76) = *getMemU32Ptr(0x5D4594, 814568 + v4);
		*(_DWORD*)(v3 + 24) = *getMemU32Ptr(0x5D4594, 814564 + v4);
		result = *getMemU32Ptr(0x5D4594, 814564 + v4);
	} else {
		*(_DWORD*)(*(_DWORD*)(a1 + 28) + 76) = *getMemU32Ptr(0x5D4594, 814560 + v4);
		*(_DWORD*)(v3 + 24) = *getMemU32Ptr(0x5D4594, 814556 + v4);
		result = *getMemU32Ptr(0x5D4594, 814556 + v4);
	}
	*(_DWORD*)(v3 + 48) = result;
	return result;
}

//----- (004375C0) --------------------------------------------------------
void  sub_4375C0(int a1) {
	if (nox_wol_server_result_cnt_815088)
		sub_46AD20(*(_DWORD**)&nox_wol_wnd_world_814980, 10070, nox_wol_server_result_cnt_815088 + 10069, a1);
}

//----- (004375F0) --------------------------------------------------------
#ifndef NOX_CGO
int  nox_client_OnLobbyServer_4375F0(const char* addr, uint16_t port, const char* name, const char* packet) {
	char v14[32];  // [esp+C0h] [ebp-20h]

	if (nox_wol_server_result_cnt_815088 >= 2500 || dword_5d4594_815044 || dword_5d4594_815060) {
		printf("OnLobbyServer_4375F0: ignoring server '%s': don't need more results\n", addr);
		return 0;
	}
	if (!memcmp(addr, getMemAt(0x5D4594, 815108), 1u)) {
		printf("OnLobbyServer_4375F0: ignoring server '%s': invalid address\n", addr);
		return 0;
	}
	if (*(_DWORD*)(packet + 44) != *getMemU32Ptr(0x5D4594, 814964)) {
		printf("OnLobbyServer_4375F0: ignoring server '%s': invalid ts: 0x%x vs 0x%x\n", addr, *(_DWORD*)(packet + 44), *getMemU32Ptr(0x5D4594, 814964));
		return 0;
	}
	if (!sub_4A0410(addr, port)) {
		printf("OnLobbyServer_4375F0: ignoring server '%s': duplicate?\n", addr);
		return 0;
	}
	unsigned int curTicks = nox_platform_get_ticks();
	unsigned int ticks = *(_DWORD*)(packet + 44);

	nox_gui_server_ent_t srv;
	memset(&srv, 0, sizeof(nox_gui_server_ent_t));
	srv.field_11_0 = *(short*)(packet + 40);
	srv.field_11_2 = *(short*)(packet + 42);
	srv.field_12 = *(_DWORD*)(packet + 24);
	srv.ping = curTicks - ticks; // ping
	srv.status = *(_BYTE*)(packet + 20) | *(_BYTE*)(packet + 21);
	srv.field_25_1 = *(_BYTE*)(packet + 5) | (16 * *(_BYTE*)(packet + 6));
	srv.field_25_2 = *(_BYTE*)(packet + 19);
	srv.players = *(_BYTE*)(packet + 3);
	srv.max_players = *(_BYTE*)(packet + 4);
	srv.field_26_1 = *(_WORD*)(packet + 36);
	srv.field_26_3 = *(_WORD*)(packet + 38);
	strcpy(srv.map_name, (const char*)(packet + 10));
	memcpy(srv.field_33_3, (const void*)(packet + 48), 20);
	srv.field_38_3 = *(_DWORD*)(packet + 7);
	srv.field_39_3 = *(_DWORD*)(packet + 32);
	srv.flags = *(_WORD*)(packet + 28);
	srv.quest_level = *(_WORD*)(packet + 68);
	srv.field_42 = 0;
	if (*(int*)&dword_587000_87412 == -1 || sub_437860(srv.field_11_0, srv.field_11_2) == dword_587000_87412) {
		if (nox_xxx_checkSomeFlagsOnJoin_4899C0(&srv)) {
			strcpy(srv.addr, addr);
			srv.field_9 = nox_wol_server_result_cnt_815088;
			srv.field_7 = 0;
			srv.port = port;
			strncpy(srv.server_name, name, 15);
			srv.flags = *(_WORD*)(packet + 28);
			nox_wol_servers_addResult_4A0030(&srv);
			v14[0] = 0;
			if (name)
				strcpy(v14, name);
			else
				nox_sprintAddrPort_43BC80(addr, port, v14);
			// TODO: v14 unused after the copy?
			++nox_wol_server_result_cnt_815088;
		}
	}
	return 0;
}
#endif // NOX_CGO

//----- (00437860) --------------------------------------------------------
int  sub_437860(int a1, int a2) {
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
		nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16399, 0, 0);
}

//----- (00438330) --------------------------------------------------------
int sub_438330() {
	int (*v0)(void); // esi

	v0 = nox_wnd_xxx_815040->field_13;
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_815040);
	if (!nox_common_gameFlags_check_40A5C0(0x10000000))
		sub_43A9D0();
	if (v0)
		v0();
	return 1;
}

//----- (00438370) --------------------------------------------------------
int sub_438370() {
	if (nox_wnd_xxx_815040->state == NOX_GUI_ANIM_OUT_DONE)
		return sub_438330();
	nox_wnd_xxx_815040->state = NOX_GUI_ANIM_OUT;
	sub_43BE40(2);
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100);
	return 1;
}

//----- (00438480) --------------------------------------------------------
int sub_438480() {
	nox_xxx_wndSetProc_46B2C0(*(int*)&nox_wol_wnd_gameList_815012, sub_439050);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&nox_wol_wnd_gameList_815012, sub_438EF0);
	sub_46B120(*(_DWORD**)&dword_5d4594_815016, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_815016, sub_438EF0);
	sub_46B120(*(_DWORD**)&dword_5d4594_815020, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_815020, sub_438EF0);
	sub_46B120(*(_DWORD**)&dword_5d4594_815024, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_815024, sub_438EF0);
	sub_46B120(*(_DWORD**)&dword_5d4594_815028, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_815028, sub_438EF0);
	sub_46B120(*(_DWORD**)&dword_5d4594_815032, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_815032, sub_438EF0);
	**(_DWORD**)(*(_DWORD*)((_DWORD)dword_5d4594_815004 + 32) + 28) = 10035;
	**(_DWORD**)(*(_DWORD*)((_DWORD)dword_5d4594_815004 + 32) + 32) = 10036;
	**(_DWORD**)(*(_DWORD*)((_DWORD)dword_5d4594_815004 + 32) + 36) = 10032;
	nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16408, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 28),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16408, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 28),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16408, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 28),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16408, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 28),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16408, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 28),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16409, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 32),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16409, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 32),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16409, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 32),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16409, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 32),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16409, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 32),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16410, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 36),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16410, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 36),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16410, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 36),
							 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16410, *(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 36),
							 0);
	return nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16410,
									*(_DWORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 36), 0);
}

//----- (00438A90) --------------------------------------------------------
int nox_client_joinGame_438A90() {
	int result = 0;    // eax
	char buf[100]; // [esp+0h] [ebp-64h]

	memset(&buf[0], 0, 100);
	// write 22 chars for serial number
	/*if (*/ nox_xxx_regGetSerial_420120((LPBYTE)&buf[56]); //)
	{
		/*if ( !*(_DWORD *)&dword_587000_87404 )
		  nox_common_getInstallPath_40E0D0((int)&buf[56], (LPCSTR)getMemAt(0x587000, 89088), 0);*/
		nox_wcscpy((wchar_t*)&buf[4], (const wchar_t*)getMemAt(0x85B3FC, 12204));
		buf[54] = getMemByte(0x85B3FC, 12254);
		buf[55] = getMemByte(0x85B3FC, 12256);
		*(_DWORD*)&buf[80] = NOX_CLIENT_VERS_CODE;
		*(_DWORD*)&buf[84] = dword_5d4594_2660032;
		strcpy(&buf[88], (const char*)getMemAt(0x85B3FC, 10344));
		buf[98] = !nox_xxx_checkHasSoloMaps_40ABD0();

		sub_43AF90(3);
		*(_QWORD*)&qword_5d4594_814956 = nox_platform_get_ticks() + 20000;

		uint16_t port = nox_client_getServerPort_43B320();
		unsigned int addr = nox_client_getServerAddr_43B300();
		return nox_client_sendJoinGame_5550A0(addr, port, buf);
	}
	/*else
	{
	  v0 = nox_strman_loadString_40F1D0("Error", 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c",
	541); sub_449E00((int)v0); v1 = nox_strman_loadString_40F1D0("ErrRegistry", 0,
	"C:\\NoxPost\\src\\client\\shell\\noxworld.c", 542); sub_449E30((int)v1); sub_449EA0(1); sub_43AF90(1); result =
	*(_DWORD *)&dword_587000_87404; if ( *(_DWORD *)&dword_587000_87404 == 1 ) result = sub_40D380();
	}*/
	return result;
}

//----- (00438C80) --------------------------------------------------------
int sub_438C80(int a1, int a2) {
	char v2[404]; // [esp+4h] [ebp-194h]

	nox_point mpos = nox_client_getMousePos_4309F0();
	if (!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_815000)) {
		memcpy(v2, *(const void**)&dword_5d4594_815000, sizeof(v2));
		*(_DWORD*)&v2[16] -= 32;
		*(_DWORD*)&v2[20] -= 32;
		*(_DWORD*)&v2[8] += 64;
		*(_DWORD*)&v2[12] += 64;
		if (!dword_5d4594_815044 && !nox_xxx_wndPointInWnd_46AAB0(v2, mpos.x, mpos.y)) {
			nox_window_set_hidden(*(int*)&dword_5d4594_815000, 1);
			nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16403, -1, 0);
			dword_5d4594_815056 = 0;
			nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_815000);
			nox_xxx_windowFocus_46B500(*(int*)&nox_wol_wnd_world_814980);
		}
	}
	if (sub_4A28B0() && !nox_xxx_wndPointInWnd_46AAB0(*(_DWORD**)getMemAt(0x5D4594, 815036), mpos.x, mpos.y)) {
		sub_4A2890();
		nox_xxx_windowFocus_46B500(*(int*)&nox_wol_wnd_world_814980);
	}
	if (nox_game_createOrJoin_815048 && sub_438DD0(mpos.x, mpos.y)) {
		nox_client_setCursorType_477610(9);
	} else if (!sub_44A4A0()) {
		nox_client_setCursorType_477610(0);
	}
	return 1;
}

//----- (00438DD0) --------------------------------------------------------
int  sub_438DD0(unsigned int a1, unsigned int a2) {
	if (*(int*)&dword_587000_87412 == -1) {
		if (a1 > 0xD8 && a1 < 0x258 && a2 > 0x1B && a2 < 0x1C3)
			return 1;
	} else if (a1 > 0xE2 && a1 < 0x24E && a2 > 0x25 && a2 < 0x1B9) {
		return 1;
	}
	return 0;
}

//----- (00438E30) --------------------------------------------------------
int  sub_438E30(_DWORD* a1, int a2) {
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
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
			sub_43F7B0(*(_DWORD*)(v3 + 236), *v4, v6 + *(_DWORD*)(v3 + 16), (int)a1 + *(_DWORD*)(v3 + 20));
		}
		v3 = *(_DWORD*)(v3 + 388);
	} while (v3);
	return 1;
}

//----- (00438EF0) --------------------------------------------------------
int  sub_438EF0(_DWORD* a1, int a2, unsigned int a3, int a4) {
	int result; // eax
	int v5;     // esi
	int v6;     // esi

	if (a2 == 19) {
		v6 = a1[8];
		nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16391, *(_DWORD*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16391, *(_DWORD*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16391, *(_DWORD*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16391, *(_DWORD*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16391, *(_DWORD*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16391, *(_DWORD*)(v6 + 28), 0);
		result = 0;
	} else if (a2 == 20) {
		v5 = a1[8];
		nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16391, *(_DWORD*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16391, *(_DWORD*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16391, *(_DWORD*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16391, *(_DWORD*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16391, *(_DWORD*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16391, *(_DWORD*)(v5 + 32), 0);
		result = 0;
	} else {
		result = nox_xxx_wndListboxProcWithoutData10_4A28E0(a1, a2, a3, a4);
	}
	return result;
}

//----- (00439050) --------------------------------------------------------
int  sub_439050(int a1, unsigned int a2, int* a3, unsigned int a4) {
	int v4;  // edi
	int v5;  // edi
	int v7;  // eax

	if (a2 > 0x400F) {
		if (a2 == 16400) {
			v7 = nox_xxx_wndGetID_46B0A0(a3);
			if (v7 >= 10038 && v7 <= 10042) {
				nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16403, a4, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16403, a4, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16403, a4, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16403, a4, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16403, a4, 0);
				if (a4 < *(int*)&nox_wol_server_result_cnt_815088) {
					nox_point pos = nox_client_getMousePos_4309F0();
					dword_5d4594_814624 = sub_4A04C0(a4);
					sub_439370(&pos, *(int*)&dword_5d4594_814624);
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
			if (a3 == nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&nox_wol_wnd_gameList_815012, 10043) ||
				a3 == nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&nox_wol_wnd_gameList_815012, 10044)) {
				nox_window_call_field_94(*(int*)&dword_5d4594_815016, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815020, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815024, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815028, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815032, 0x4000, (int)a3, 0);
			}
			break;
		case 0x4009u:
			v4 = *(_DWORD*)(a1 + 32);
			nox_xxx_wndListboxProcPre_4A30D0(a1, 0x4009u, (wchar_t*)a3, a4);
			v5 = sub_4A4800(v4);
			nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16412, v5, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16412, v5, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16412, v5, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16412, v5, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16412, v5, 0);
			break;
		}
	}
	return nox_xxx_wndListboxProcPre_4A30D0(a1, a2, (wchar_t*)a3, a4);
}

// 439385: variable 'v2' is possibly undefined

//----- (00439450) --------------------------------------------------------
_DWORD*  sub_439450(int a1, int a2, _DWORD* a3) {
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
char*  sub_439CC0(int a1, char* a2) {
	size_t v2;    // esi
	char* result; // eax

	v2 = (size_t)&strstr((const char*)(a1 + 52), "'s_game")[-52 - a1];
	result = strncpy(a2, (const char*)(a1 + 52), v2);
	a2[v2] = 0;
	return result;
}

//----- (00439D00) --------------------------------------------------------
int  sub_439D00(int* a1, int a2, unsigned int a3, int a4) {
	if (a2 == 5) {
		if (nox_xxx_wndGetID_46B0A0(a1) == 10020 && nox_game_createOrJoin_815048 == 1) {
			sub_439D90((unsigned __int16)a3, a3 >> 16);
			return 1;
		}
		return 0;
	}
	if (a2 != 21)
		return 0;
	if (a3 != 1) {
		if (a3 != 28 && a3 == 57) {
			nox_point mpos = nox_client_getMousePos_4309F0();
			nox_window_call_field_93(a1, 5, mpos.x | (mpos.y << 16), 0);
		}
		return 0;
	}
	if (a4 == 2)
		sub_4373A0();
	return 1;
}

//----- (00439D90) --------------------------------------------------------
int  sub_439D90(unsigned int a1, unsigned int a2) {
	int result; // eax
	__int16 v3; // dx

	result = sub_438DD0(a1, a2);
	if (result) {
		v3 = a2 + *getMemU16Ptr(0x587000, 87530 + 8 * dword_587000_87412) - 27;
		*getMemU16Ptr(0x5D4594, 814916) = a1 + *getMemU16Ptr(0x587000, 87528 + 8 * dword_587000_87412) - 216;
		*getMemU16Ptr(0x5D4594, 814918) = v3;
		sub_43B460();
		if (sub_43BDB0() & 2)
			sub_4D6F60(1);
		if (sub_4D6F50()) {
			if (sub_4DC7D0()) {
				sub_4A7A70(1);
				nox_game_showSelChar_4A4DB0();
				return nox_client_setCursorType_477610(0);
			}
		} else if (sub_4DC630()) {
			sub_4A7A70(1);
			nox_game_showSelChar_4A4DB0();
			return nox_client_setCursorType_477610(0);
		}
		sub_4A7A70(0);
		nox_game_showSelClass_4A4840();
		result = nox_client_setCursorType_477610(0);
	}
	return result;
}

// 43A3CE: variable 'v22' is possibly undefined

//----- (0043A920) --------------------------------------------------------
int sub_43A920() {
	int result; // eax

	nox_xxx_windowFocus_46B500(*(int*)&nox_wol_wnd_world_814980);
	if (dword_587000_87404 == 1) {
		sub_554D10();
		nox_game_SetCliDrawFunc(sub_41E210);
	}
	if (!sub_43BE30() || !*getMemU32Ptr(0x5D4594, 815084))
		sub_44A400();
	result = sub_43AF90(0);
	dword_5d4594_815044 = 0;
	return result;
}

//----- (0043A9D0) --------------------------------------------------------
int sub_43A9D0() {
	nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_814984);
	sub_489FB0();
	sub_4A2890();
	if (dword_5d4594_815000 && !*(_DWORD*)(dword_5d4594_815000 + 396)) {
		nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_815000);
		nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&dword_5d4594_815000);
		dword_5d4594_815000 = 0;
	}
	if (nox_wol_wnd_world_814980) {
		nox_xxx_windowDestroyMB_46C4E0(*(_DWORD**)&nox_wol_wnd_world_814980);
		nox_wol_wnd_world_814980 = 0;
	}
	sub_43A920();
	nox_xxx_windowFocus_46B500(0);
	nox_wol_server_result_cnt_815088 = 0;
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
		nox_xxx_networkLog_printf_413D30("RECON: Posting server to WOL");
	nox_game_createOrJoin_815048 = 0;
	dword_5d4594_815052 = 1;
	v0 = nox_xxx_cliGamedataGet_416590(0);
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
	v2 = nox_xxx_serverOptionsGetServername_40A4C0();
	strncpy(v1 + 120, v2, 0xFu);
	strcpy(v1 + 111, nox_xxx_mapGetMapName_409B40());
	if (sub_4D6F50()) {
		if (dword_5d4594_528256)
			*(_WORD*)(v1 + 165) = nox_game_getQuestStage_4E3CC0();
		else
			*(_WORD*)(v1 + 165) = 1;
	}
	v1[104] = nox_xxx_servGetPlrLimit_409FA0();
	v3 = nox_common_playerInfoCount_416F40();
	v1[103] = v3;
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		v1[103] = v3 - 1;
		--v1[104];
	}
	v4 = sub_43BE50_get_video_mode_id();
	v5 = v1[102];
	*((_DWORD*)v1 + 12) = NOX_CLIENT_VERS_CODE;
	v1[102] = v5 & 0x80 | v4;
	*((_DWORD*)v1 + 11) = *getMemU32Ptr(0x5D4594, 814916);
	*(_WORD*)(v1 + 109) = nox_xxx_servGetPort_40A430();
	nox_client_setServerConnectAddr_435720("localhost");
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
		*(_DWORD*)&v10[224] = NOX_CLIENT_VERS_CODE;
		*(_DWORD*)&v10[32] = *getMemU32Ptr(0x5D4594, 814916);
		v10[sub_425550(v1 + 100, &v10[69], 552) + 69] = 0;
		sub_40D320((int)v10);
	}
	result = nox_xxx_cliGamedataGet_416590(1);
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
	char* v4;          // eax
	int v5;            // eax
	int v6;            // esi
	_DWORD* v7;        // eax
	_DWORD* v8;        // eax
	char v9[172];      // [esp+0h] [ebp-ECh]
	char v10[32];      // [esp+ACh] [ebp-40h]
	char v11[32];      // [esp+CCh] [ebp-20h]

	if (!nox_wol_server_result_cnt_815088 && !dword_5d4594_815044) {
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
					if (nox_xxx_checkSomeFlagsOnJoin_4899C0((int)v9)) {
						v4 = nox_net_ip2str(htonl(*(_DWORD*)(i + 36)));
						*(_DWORD*)&v9[12] = *(_DWORD*)v4;
						*(_DWORD*)&v9[16] = *((_DWORD*)v4 + 1);
						*(_DWORD*)&v9[20] = *((_DWORD*)v4 + 2);
						v5 = *((_DWORD*)v4 + 3);
						*(_DWORD*)&v9[32] = i;
						*(_DWORD*)&v9[24] = v5;
						*(_DWORD*)&v9[36] = nox_wol_server_result_cnt_815088;
						*(_DWORD*)&v9[44] = *(_DWORD*)(i + 32);
						nox_wol_servers_addResult_4A0030(v9);
						if (v9[120]) {
							strncpy(v10, &v9[120], 0xFu);
							v10[15] = 0;
						} else {
							nox_sprintAddrPort_43BC80((int)&v9[12], *(unsigned __int16*)&v9[109], v10);
						}
						if (++nox_wol_server_result_cnt_815088 >= 0x9C4u)
							break;
					}
				}
			}
		}
		if (nox_wol_server_result_cnt_815088)
			sub_4A0360();
		sub_44A400();
		if (nox_common_gameFlags_check_40A5C0(0x2000000) && *(int*)&dword_587000_87412 == -1) {
			v6 = sub_4A7F20() + 10053;
			v7 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&nox_wol_wnd_world_814980, 10002);
			nox_window_call_field_94(*(int*)&nox_wol_wnd_world_814980, 16391, (int)v7, 0);
			v8 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&nox_wol_wnd_world_814980, v6);
			nox_window_call_field_94(*(int*)&nox_wol_wnd_world_814980, 16391, (int)v8, 0);
		}
		if (nox_game_createOrJoin_815048)
			sub_4375C0(0);
	}
}

//----- (0043AF30) --------------------------------------------------------
int sub_43AF30() { return dword_5d4594_815052; }

//----- (0043AF40) --------------------------------------------------------
int sub_43AF40() { return nox_game_createOrJoin_815048; }

//----- (0043AF50) --------------------------------------------------------
int  sub_43AF50(int a1) {
	int result; // eax

	result = a1;
	dword_587000_87404 = a1;
	dword_5d4594_2650652 = a1 == 1;
	return result;
}

//----- (0043AF70) --------------------------------------------------------
int nox_xxx_check_flag_aaa_43AF70() { return dword_587000_87404; }

//----- (0043AF80) --------------------------------------------------------
int sub_43AF80() { return dword_5d4594_814548; }

//----- (0043AF90) --------------------------------------------------------
int  sub_43AF90(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_814548 = a1;
	return result;
}

//----- (0043AFA0) --------------------------------------------------------
int  sub_43AFA0(int a1) {
	dword_5d4594_814552 = a1;
	return sub_43AF90(2);
}

//----- (0043AFC0) --------------------------------------------------------
void  sub_43AFC0(int a1) {
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
		nox_client_setMousePos_430B10(v10.field_0, v10.field_4);
		return;
	}
	sub_43A920();
	v3 = sub_4A0330(v1);
	nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16403, v3, 0);
	nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16412, v3, 0);
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
	nox_client_setMousePos_430B10(v10.field_0, v10.field_4);
}

//----- (0043B0E0) --------------------------------------------------------
void  nox_xxx_failconn_43B0E0(int a1) {
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
						if (nox_xxx_checkSomeFlagsOnJoin_4899C0(v3)) {
							nox_swprintf((wchar_t*)getMemAt(0x5D4594, 814756), L"%d", *(_DWORD*)(v3 + 96));
							nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16407, (int)getMemAt(0x5D4594, 814756), v5);
							if (nox_xxx_getConnResult_4A0560() == 6 || nox_xxx_getConnResult_4A0560() == 7) {
								sub_425920((_DWORD**)v3);
								v6 = nox_wol_servers_addResult_4A0030((const void*)v3);
								nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16398, v5, 0);
								sub_43B2A0(v6);
								nox_gui_wol_newServerLine_43B7C0(v3);
							}
						} else {
							nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16398, v5, 0);
							sub_4A0540((LPVOID)v3);
						}
					} else if (nox_xxx_checkSomeFlagsOnJoin_4899C0(v3)) {
						if (*(_BYTE*)(v3 + 120)) {
							strncpy((char*)getMemAt(0x5D4594, 814920), (const char*)(v3 + 120), 0xFu);
							*getMemU8Ptr(0x5D4594, 814935) = 0;
						} else {
							nox_sprintAddrPort_43BC80(v3 + 12, *(_WORD*)(v3 + 109), (char*)getMemAt(0x5D4594, 814920));
						}
						if (*(_DWORD*)(v3 + 96) == 9999)
							nox_swprintf((wchar_t*)getMemAt(0x5D4594, 814628), L"%S -- ms", getMemAt(0x5D4594, 814920));
						else
							nox_swprintf((wchar_t*)getMemAt(0x5D4594, 814628), L"%S %dms", getMemAt(0x5D4594, 814920),
										 *(_DWORD*)(v3 + 96));
						nox_xxx_wndWddSetTooltip_46B000((wchar_t*)(*(_DWORD*)(v3 + 28) + 36), (wchar_t*)getMemAt(0x5D4594, 814628));
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
int  sub_43B2A0(int a1) {
	int result; // eax

	result = a1;
	*(_WORD*)(*(_DWORD*)(nox_wol_wnd_gameList_815012 + 32) + 46) = a1;
	*(_WORD*)(*(_DWORD*)(dword_5d4594_815016 + 32) + 46) = a1;
	*(_WORD*)(*(_DWORD*)(dword_5d4594_815020 + 32) + 46) = a1;
	*(_WORD*)(*(_DWORD*)(dword_5d4594_815024 + 32) + 46) = a1;
	*(_WORD*)(*(_DWORD*)(dword_5d4594_815028 + 32) + 46) = a1;
	*(_WORD*)(*(_DWORD*)(dword_5d4594_815032 + 32) + 46) = a1;
	return result;
}

//----- (0043B300) --------------------------------------------------------
unsigned int nox_client_getServerAddr_43B300() {
	unsigned int result; // eax

	if (dword_5d4594_815056)
		result = inet_addr((const char*)(dword_5d4594_814624 + 12));
	else
		result = 0;
	return result;
}

//----- (0043B320) --------------------------------------------------------
int nox_client_getServerPort_43B320() { return dword_5d4594_815056 != 0 ? *getMemU32Ptr(0x5D4594, 814604) : 0; }

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
int nox_xxx_cliDrawConnectedLoop_43B360() { // client connecting draw handler
	char* v0;            // ebx
	unsigned __int16 v1; // ax
	char v2;             // al
	char v5[32];         // [esp+0h] [ebp-20h]

	nox_xxx_setGameFlags_40A4D0(4);
	nox_common_gameFlags_unset_40A540(1);
	v0 = (char*)(dword_5d4594_814624 + 12);
	if (!memcmp((const void*)(dword_5d4594_814624 + 12), getMemAt(0x5D4594, 815116), 1u)) {
		nox_client_setServerConnectAddr_435720("localhost");
	} else {
		v1 = nox_client_getServerPort_43B320();
		nox_sprintf(v5, "%s:%d", v0, v1);
		nox_xxx_copyServerIPAndPort_431790(v5);
		nox_client_setServerConnectAddr_435720(v0);
	}
	nox_common_writecfgfile("nox.cfg");
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
		nox_xxx_createSocketLocal_554B40(0);
	nox_client_joinGame_438A90();
	return 1;
}

//----- (0043B460) --------------------------------------------------------
int sub_43B460() {
	sub_438370();
	nox_wnd_xxx_815040->fnc_done_out = sub_43B490;
	nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_815000);
	return nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_814984, 0);
}

//----- (0043B490) --------------------------------------------------------
int sub_43B490() {
	if (nox_game_getStateCode_43BE10() == 1700)
		return sub_438330();
	nox_window_set_hidden(*(int*)&nox_wol_wnd_world_814980, 1);
	nox_window_set_hidden(*(int*)&dword_5d4594_815000, 1);
	nox_client_setCursorType_477610(0);
	return 1;
}

//----- (0043B4D0) --------------------------------------------------------
#ifndef NOX_CGO
void nox_xxx_serverHost_43B4D0() {
	if (nox_game_createOrJoin_815048) {
		sub_43B510();
		sub_43A9D0();
		sub_4A24A0();
		nox_xxx_gameSetAudioFadeoutMb_501AC0(0);
	} else {
		sub_43B630();
		sub_43B440();
	}
	sub_49FF20();
}
#endif // NOX_CGO
