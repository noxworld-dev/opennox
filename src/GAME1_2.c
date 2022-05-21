#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
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
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__audio__auddiag.h"
#include "client__system__parsecmd.h"
#include "common__net_list.h"
#include "common__system__settings.h"
#include "common__system__team.h"
#include "common__crypt.h"

#include "client__drawable__drawdb.h"
#include "client__drawable__drawable.h"
#include "client__gui__gamewin__gamewin.h"
#include "client__gui__guiggovr.h"
#include "client__gui__guiquit.h"
#include "client__gui__window.h"
#include "client__shell__noxworld.h"
#include "client__shell__selchar.h"
#include "client__system__client.h"
#include "client__system__ctrlevnt.h"
#include "client__video__draw_common.h"
#include "common__magic__comguide.h"

#include "client__draw__partscrn.h"
#include "client__gui__guicon.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME5_2.h"
#include "client__draw__fx.h"
#include "client__drawable__drawdb.h"
#include "client__gui__guiinv.h"
#include "client__gui__guimeter.h"
#include "client__gui__guishop.h"
#include "client__gui__guispell.h"
#include "client__gui__servopts__guiserv.h"
#include "client__gui__window.h"
#include "client__io__win95__focus.h"
#include "client__network__netclint.h"
#include "client__shell__optsback.h"
#include "client__system__ctrlevnt.h"
#include "client__video__draw_common.h"
#include "client__video__sdl__draw_nogl.h"
#include "common/fs/nox_fs.h"
#include "common__binfile.h"
#include "common__log.h"
#include "common__magic__speltree.h"
#include "defs.h"
#include "input.h"
#include "input_common.h"
#include "operators.h"
#include "server__network__mapsend.h"
#include "server__script__builtin.h"
#include "server__script__script.h"
#include "server__xfer__savegame__savegame.h"
#include "server__network__playback.h"
#include "thing.h"
#include "win.h"

#include <time.h>

extern uint32_t nox_xxx_useAudio_587000_80772;
extern uint32_t dword_5d4594_811904;
extern uint32_t dword_5d4594_805988;
extern uint32_t dword_5d4594_805820;
extern uint32_t dword_5d4594_741648;
extern uint32_t dword_5d4594_815060;
extern uint32_t dword_5d4594_815052;
extern uint32_t dword_5d4594_805980;
extern uint32_t dword_5d4594_741652;
extern uint32_t dword_5d4594_3807116;
extern uint32_t dword_5d4594_810628;
extern uint32_t dword_5d4594_808564;
extern uint32_t dword_5d4594_741680;
extern uint32_t dword_5d4594_1193336;
extern uint32_t dword_5d4594_3807152;
extern uint32_t dword_5d4594_3807136;
extern uint32_t dword_5d4594_3805484;
extern uint32_t dword_5d4594_814548;
extern uint32_t dword_5d4594_3804684;
extern uint32_t nox_xxx_useMMX_587000_80800;
extern uint32_t dword_5d4594_3807140;
extern uint32_t nox_client_connError_814552;
extern uint32_t dword_5d4594_815056;
extern uint32_t dword_5d4594_808568;
extern uint32_t dword_5d4594_2660032;
extern uint32_t nox_client_gui_flag_1556112;
extern uint32_t dword_5d4594_741356;
extern uint32_t dword_5d4594_741332;
extern uint32_t dword_5d4594_741364;
extern int nox_video_16bit;
extern nox_gui_animation* nox_wnd_xxx_815040;
extern uint32_t dword_5d4594_805984;
extern uint32_t dword_5d4594_810636;
extern uint32_t dword_5d4594_805836;
extern uint32_t dword_587000_87408;
extern uint32_t dword_5d4594_3798812;
extern uint32_t dword_5d4594_3798800;
extern void* dword_587000_81128;
extern void* dword_587000_122852;
extern uint32_t dword_5d4594_528252;
extern void* nox_alloc_screenParticles_806044;
extern uint32_t dword_5d4594_3798828;
extern uint64_t qword_5d4594_814956;
extern void* dword_587000_93164;
extern uint32_t dword_5d4594_815044;
extern uint32_t nox_wol_server_result_cnt_815088;
extern void* dword_587000_127004;
extern uint32_t cpuid_5d4594_3801804;
extern uint32_t dword_5d4594_528256;
extern uint32_t dword_5d4594_3798816;
extern uint32_t dword_5d4594_3798808;
extern uint32_t dword_5d4594_3798832;
extern int dword_5d4594_3799524;
extern uint32_t dword_5d4594_815032;
extern void* dword_5d4594_810640;
extern uint32_t dword_5d4594_815020;
extern uint32_t dword_5d4594_815024;
extern uint32_t dword_5d4594_815028;
extern uint32_t dword_5d4594_3798836;
extern uint32_t dword_5d4594_814984;
extern uint32_t dword_5d4594_815016;
extern uint32_t nox_gameDisableMapDraw_5d4594_2650672;
extern uint32_t nox_game_createOrJoin_815048;
extern uint32_t dword_5d4594_3798804;
extern uint32_t dword_587000_87404;
extern uint32_t dword_587000_87412;
extern uint32_t dword_5d4594_3798820;
extern uint32_t dword_5d4594_3798824;
extern uint32_t dword_5d4594_815000;
extern uint32_t dword_5d4594_741676;
extern uint32_t dword_5d4594_3798840;
extern uint32_t nox_video_pixmode_3799624;
extern uint32_t nox_video_modeXxx_3801780;
extern uint32_t dword_5d4594_810632;
extern uint32_t nox_client_renderGUI_80828;
extern uint32_t dword_5d4594_3798796;
extern uint32_t nox_wol_wnd_gameList_815012;
extern nox_window* dword_5d4594_815004;
extern uint32_t dword_5d4594_2650652;
extern uint32_t dword_5d4594_3798844;
extern uint32_t nox_player_netCode_85319C;
extern nox_window* nox_wol_wnd_world_814980;
extern int nox_enable_audio;
extern unsigned int nox_frame_xxx_2598000;
extern uint32_t nox_color_white_2523948;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

extern float input_sensitivity;

int nox_win_width = 0;
int nox_win_height = 0;

extern nox_ctrlevent_xxx_t nox_ctrlevent_buf_747884[NOX_CTRLEVENT_XXX_MAX];
extern nox_ctrlevent_code_info_t nox_ctrlevent_code_infos[];

obj_5D4594_754088_t* ptr_5D4594_754088 = 0;
int ptr_5D4594_754088_cnt = 0;

obj_5D4594_754088_t* ptr_5D4594_754092 = 0;
int ptr_5D4594_754092_cnt = 0;

int obj_5D4594_754104_switch = 0;

nox_render_data_t* nox_draw_curDrawData_3799572 = 0;

nox_screenParticle* nox_screenParticles_head = 0;
nox_screenParticle* dword_5d4594_806052 = 0;

void* dword_5d4594_814624 = 0;

//----- (00427F30) --------------------------------------------------------
int nox_xxx_wallMath_427F30(int2* a1, int* a2) {
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
	if ((double)a1->field_0 < 57.5) {
		return 0;
	}
	v3 = a1->field_4;
	if ((double)v3 < 57.5) {
		return 0;
	}
	if (v2 > 5888) {
		return 0;
	}
	if (v3 > 5888) {
		return 0;
	}
	v4 = v2 / 23;
	v5 = v3 / 23;
	v6 = a2[1] / 23;
	v12 = a2[2] / 23;
	v13 = a2[3] / 23;
	v7 = a2[4] / 23;
	v9 = a2[5] / 23;
	if (v3 / 23 < v6 || v5 > a2[7] / 23 || v4 < v12 || v4 > v7) {
		return 0;
	}
	if (v5 > v13) {
		if (v4 < v5 + v12 - v13) {
			return 0;
		}
		v10 = *a2 / 23;
	} else {
		v10 = *a2 / 23;
		if (v4 < v10 + v6 - v5) {
			return 0;
		}
	}
	if (v5 > v9) {
		if (v4 > v7 + v9 - v5) {
			return 0;
		}
	} else if (v4 > v5 + v10 - v6) {
		return 0;
	}
	return 1;
}

//----- (00428170) --------------------------------------------------------
int sub_428170(void* a1p, int4* a2) {
	uint32_t* a1 = a1p;
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
	if (a2->field_0 < 0) {
		a2->field_0 = 0;
	}
	if (a2->field_4 < 0) {
		a2->field_4 = 0;
	}
	if (a2->field_8 >= 5888) {
		a2->field_8 = 5887;
	}
	if (a2->field_C >= 5888) {
		a2->field_C = 5887;
	}
	return 0;
}

//----- (004281F0) --------------------------------------------------------
int nox_xxx_pointInRect_4281F0(int2* a1, int4* a2) {
	int v2;      // ecx
	bool result; // al

	result = 0;
	if (a1->field_0 >= a2->field_0 && a1->field_0 <= a2->field_8) {
		v2 = a1->field_4;
		if (v2 >= a2->field_4 && v2 <= a2->field_C) {
			result = 1;
		}
	}
	return result;
}

//----- (00428220) --------------------------------------------------------
int sub_428220(float2* a1, float4* a2) {
	return a1->field_0 >= (double)a2->field_0 && a1->field_0 <= (double)a2->field_8 &&
		   a1->field_4 >= (double)a2->field_4 && a1->field_4 <= (double)a2->field_C;
}

//----- (00428270) --------------------------------------------------------
void nox_shape_box_calc(nox_shape* s) {
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
char* sub_4282D0(char* a1, int a2) {
	char* result; // eax

	result = strncpy((char*)getMemAt(0x5D4594, 741316), a1, 0x10u);
	*getMemU32Ptr(0x5D4594, 741304) = a2;
	return result;
}

//----- (004282F0) --------------------------------------------------------
void* sub_4282F0(int a1, int a2, size_t a3) {
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
	if (*(uint32_t*)(a1 + 608)) {
		for (i = 0; i < *(int*)&dword_5d4594_741332; ++i) {
			free(*(void**)(*(uint32_t*)(a1 + 608) + 4 * i));
			*(uint32_t*)(*(uint32_t*)(a1 + 608) + 4 * i) = 0;
		}
		free(*(void**)(a1 + 608));
		*(uint32_t*)(a1 + 608) = 0;
	}
	if (*(uint32_t*)(a1 + 612)) {
		free(*(void**)(a1 + 612));
		*(uint32_t*)(a1 + 612) = 0;
	}
	if (*(uint32_t*)(a1 + 616)) {
		free(*(void**)(a1 + 616));
		*(uint32_t*)(a1 + 616) = 0;
	}
	if (*(uint32_t*)(a1 + 620)) {
		free(*(void**)(a1 + 620));
		*(uint32_t*)(a1 + 620) = 0;
	}
	if (*(uint32_t*)(a1 + 624)) {
		free(*(void**)(a1 + 624));
		*(uint32_t*)(a1 + 624) = 0;
	}
	if (*(uint32_t*)(a1 + 628)) {
		free(*(void**)(a1 + 628));
		*(uint32_t*)(a1 + 628) = 0;
	}
	if (*(uint32_t*)(a1 + 632)) {
		free(*(void**)(a1 + 632));
		*(uint32_t*)(a1 + 632) = 0;
	}
	v6 = 4 * a3;
	*(uint32_t*)(a1 + 608) = calloc(a3, 4);
	if (a3) {
		do {
			*(uint32_t*)(*(uint32_t*)(a1 + 608) + 4 * v4++) = calloc(1, 0xAu);
		} while (v4 < a3);
	}
	*(uint32_t*)(a1 + 612) = calloc(1, v6);
	*(uint32_t*)(a1 + 616) = calloc(1, v6);
	*(uint32_t*)(a1 + 620) = calloc(1, a3);
	*(uint32_t*)(a1 + 624) = calloc(1, a3);
	*(uint32_t*)(a1 + 628) = calloc(1, v6);
	result = calloc(1, a3);
	v8 = 0;
	*(uint32_t*)(a1 + 632) = result;
	if (a3) {
		v9 = a2 + 16;
		for (j = a2 + 16;; v9 = j) {
			strcpy(*(char**)(*(uint32_t*)(v3 + 608) + 4 * v8), (const char*)(v9 - 16));
			*(uint32_t*)(*(uint32_t*)(v3 + 612) + 4 * v8) = *(uint32_t*)(v9 - 4);
			*(uint32_t*)(*(uint32_t*)(v3 + 616) + 4 * v8) = *(uint32_t*)v9;
			*(uint8_t*)(*(uint32_t*)(v3 + 620) + v8) = *(uint8_t*)(v9 + 4);
			*(uint8_t*)(*(uint32_t*)(v3 + 624) + v8) = *(uint8_t*)(v9 + 5);
			*(uint8_t*)(*(uint32_t*)(v3 + 632) + v8) = *(uint8_t*)(v9 + 12);
			v10 = *(uint32_t*)(v9 + 8);
			v11 = time(0) - v10;
			++v8;
			*(uint32_t*)(j + 8) = v11;
			*(uint32_t*)(*(uint32_t*)(v3 + 628) + 4 * v8 - 4) = v11;
			result = (void*)a3;
			j += 32;
			if (v8 >= a3) {
				break;
			}
		}
		*(uint16_t*)(v3 + 6) = a3;
		dword_5d4594_741332 = a3;
	} else {
		*(uint16_t*)(a1 + 6) = 0;
		dword_5d4594_741332 = 0;
	}
	return result;
}

//----- (00428540) --------------------------------------------------------
unsigned int sub_428540(int a1, char* a2, int a3) {
	unsigned int result; // eax
	char* v4;            // ecx
	char v5;             // bl

	if (*(uint32_t*)(a1 + 636)) {
		free(*(void**)(a1 + 636));
		*(uint32_t*)(a1 + 636) = 0;
	}
	*(uint32_t*)(a1 + 636) = calloc(a3, 2);
	result = 0;
	if (2 * a3) {
		v4 = a2;
		do {
			v5 = *v4;
			v4 += 2;
			*(uint8_t*)(result + *(uint32_t*)(a1 + 636)) = v5;
			*(uint8_t*)(result + *(uint32_t*)(a1 + 636) + 1) = *(v4 - 1);
			result += 2;
		} while (result < 2 * a3);
		*getMemU32Ptr(0x5D4594, 741308) = a3;
	} else {
		*getMemU32Ptr(0x5D4594, 741308) = a3;
	}
	return result;
}

//----- (004285C0) --------------------------------------------------------
char* sub_4285C0(short* a1) {
	char* result;    // eax
	short* v2;       // ebx
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
	*a1 = (short)result;
	if ((short)result <= 0) {
		dword_5d4594_741332 = *a1;
	} else {
		v3 = calloc((short)result, 4);
		v4 = 0;
		v5 = *a1 == 0;
		*((uint32_t*)a1 + 134) = v3;
		if (!v5) {
			do {
				*(uint32_t*)(*((uint32_t*)a1 + 134) + 4 * v4++) = calloc(1, 0xAu);
			} while (v4 < *a1);
		}
		v6 = calloc(*a1, 4);
		v19 = *a1;
		*((uint32_t*)a1 + 135) = v6;
		v7 = calloc(1, v19);
		v18 = 4 * *a1;
		*((uint32_t*)a1 + 144) = v7;
		*((uint32_t*)a1 + 136) = calloc(1, v18);
		v8 = calloc(*a1, 4);
		v17 = 4 * *a1;
		*((uint32_t*)a1 + 137) = v8;
		v9 = calloc(1, v17);
		v16 = 4 * *a1;
		*((uint32_t*)a1 + 138) = v9;
		*((uint32_t*)a1 + 139) = calloc(1, v16);
		v10 = calloc(*a1, 4);
		v15 = 4 * *a1;
		*((uint32_t*)a1 + 140) = v10;
		v11 = calloc(1, v15);
		v14 = 4 * *a1;
		*((uint32_t*)a1 + 141) = v11;
		*((uint32_t*)a1 + 142) = calloc(1, v14);
		*((uint32_t*)a1 + 143) = calloc(*a1, 4);
		v20 = 0;
		result = nox_common_playerInfoGetFirst_416EA0();
		v12 = result;
		if (result) {
			do {
				if (*((uint32_t*)v12 + 1198)) {
					strcpy(*(char**)(*((uint32_t*)v2 + 134) + 4 * v20), v12 + 2096);
					v13 = nox_xxx_net_getIP_554200((unsigned char)v12[2064] + 1);
					*(uint32_t*)(*((uint32_t*)v2 + 135) + 4 * v20) = htonl(v13);
					*(uint8_t*)(v20 + *((uint32_t*)v2 + 144)) = v12[2251];
					*(uint32_t*)(*((uint32_t*)v2 + 136) + 4 * v20) = *((uint32_t*)v12 + 1172);
					*(uint32_t*)(*((uint32_t*)v2 + 137) + 4 * v20) = *((uint32_t*)v12 + 1172);
					*(uint32_t*)(*((uint32_t*)v2 + 138) + 4 * v20) = *((uint32_t*)v12 + 1166);
					*(uint32_t*)(*((uint32_t*)v2 + 139) + 4 * v20) = *((uint32_t*)v12 + 1165);
					*(uint32_t*)(*((uint32_t*)v2 + 140) + 4 * v20) = *((uint32_t*)v12 + 1167);
					*(uint32_t*)(*((uint32_t*)v2 + 141) + 4 * v20) = *((uint32_t*)v12 + 1168);
					*(uint32_t*)(*((uint32_t*)v2 + 142) + 4 * v20) = *((uint32_t*)v12 + 1171);
					*(uint32_t*)(*((uint32_t*)v2 + 143) + 4 * v20++) = sub_4D6540((unsigned char)v12[2064]);
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
int sub_428810(int a1, int a2) {
	uint16_t* v2; // esi
	uint16_t* v3; // edi
	int v4;       // esi
	char v6[72];  // [esp+8h] [ebp-48h]

	v2 = sub_42ADA0(a1, a2, *getMemI16Ptr(0x5D4594, 741308), getMemUintPtr(0x5D4594, 741312));
	v3 = sub_42A8B0(v2, getMemIntPtr(0x5D4594, 741312));
	free(v2);
	v4 = 1;
	if (sub_420360(v6, &a2)) {
		v4 = sub_40DEA0((int)v6, (short)a2, (int)v3, *getMemIntPtr(0x5D4594, 741312));
	}
	free(v3);
	return v4;
}

//----- (00428890) --------------------------------------------------------
int sub_428890(short* a1) {
	uint16_t* v1; // esi
	uint16_t* v2; // edi
	int v3;       // esi
	char v5[72];  // [esp+8h] [ebp-48h]

	v1 = sub_42B810(a1, getMemUintPtr(0x5D4594, 741300));
	v2 = sub_42A8B0(v1, getMemIntPtr(0x5D4594, 741300));
	free(v1);
	v3 = 1;
	if (sub_420360(v5, &a1)) {
		v3 = sub_40DEA0((int)v5, (short)a1, (int)v2, *getMemIntPtr(0x5D4594, 741300));
	}
	free(v2);
	return v3;
}

//----- (004289D0) --------------------------------------------------------
void* sub_4289D0(void** a1) {
	unsigned int i; // edi
	void* result;   // eax

	if (a1[134]) {
		for (i = 0; i < *(int*)&dword_5d4594_741332; ++i) {
			free(*((void**)a1[134] + i));
			*((uint32_t*)a1[134] + i) = 0;
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
	int v1;            // eax
	unsigned short v2; // bp
	int v3;            // esi
	int v4;            // eax
	int v5;            // esi
	int i;             // esi
	unsigned short v7; // ax
	int v8;            // [esp+4h] [ebp-110h]
	int v9;            // [esp+8h] [ebp-10Ch]
	int v10;           // [esp+Ch] [ebp-108h]
	int v11;           // [esp+10h] [ebp-104h]
	char v12[256];     // [esp+14h] [ebp-100h]

	v11 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 2u);
	if ((short)v11 > 1) {
		return 0;
	}
	sub_42BFB0();
	if (nox_xxx_cryptGetXxx()) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 2u);
		for (i = 0; (unsigned short)i < (unsigned short)v9; ++i) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v10, 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v12, (unsigned char)v8);
			v12[(unsigned char)v8] = 0;
			if (!nox_common_gameFlags_check_40A5C0(2) || nox_common_gameFlags_check_40A5C0(1)) {
				v7 = nox_xxx_getNameId_4E3AA0(v12);
			} else {
				v7 = nox_xxx_getTTByNameSpriteMB_44CFC0(v12);
			}
			sub_42C310(v7, v10);
		}
		return 1;
	}
	sub_42BFE0();
	LOWORD(v1) = sub_42C300();
	v9 = v1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 2u);
	v2 = 0;
	if (!nox_xxx_unitDefGetCount_4E3AC0()) {
		return 1;
	}
	v3 = 0;
	do {
		LOWORD(v4) = sub_42C2E0(v3);
		v10 = v4;
		if ((uint16_t)v4) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v10, 2u);
			v5 = nox_xxx_objectTypeByInd_4E3B70(v3);
			LOBYTE(v8) = strlen(*(const char**)(v5 + 4));
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(*(uint8_t**)(v5 + 4), (unsigned char)v8);
		}
		v3 = ++v2;
	} while (v2 < (unsigned int)nox_xxx_unitDefGetCount_4E3AC0());
	return 1;
}
// 428B85: variable 'v1' is possibly undefined
// 428BAB: variable 'v4' is possibly undefined
// 428B30: using guessed type char var_100[256];

//----- (00428CD0) --------------------------------------------------------
int nox_server_mapRWPolygons_428CD0(int a1) {
	char* i;            // eax
	char* v3;           // esi
	unsigned int j;     // edi
	char* k;            // eax
	char* v6;           // esi
	char* v7;           // ebp
	char* v8;           // ebp
	unsigned int v9;    // esi
	unsigned char* v10; // esi
	uint16_t* v11;      // ebx
	uint8_t* v12;       // eax
	char* v13;          // edi
	int v14;            // eax
	unsigned int v15;   // ebp
	bool v16;           // cc
	char* v17;          // edi
	double v18;         // st7
	double v19;         // st7
	double v20;         // st7
	double v21;         // st7
	char* v22;          // edi
	char* v23;          // eax
	uint8_t* v24;       // esi
	unsigned int v25;   // [esp+10h] [ebp-2Ch]
	int v26;            // [esp+14h] [ebp-28h]
	int v27;            // [esp+18h] [ebp-24h]
	unsigned int v28;   // [esp+1Ch] [ebp-20h]
	float v29[2];       // [esp+20h] [ebp-1Ch]
	int v30;            // [esp+28h] [ebp-14h]
	int v31;            // [esp+2Ch] [ebp-10h]
	char v32[12];       // [esp+30h] [ebp-Ch]

	v30 = 0;
	if (a1) {
		return 1;
	}
	v26 = 4;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v26, 2u);
	if ((short)v26 > 4) {
		return 0;
	}
	if (nox_xxx_cryptGetXxx()) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v25, 4u);
		v9 = 1;
		if (v25 >= 1) {
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v29, 8u);
				if (!nox_xxx_polygonSetAngle_420D40(SLODWORD(v29[0]), SLODWORD(v29[1]), v9, a1)) {
					return 0;
				}
				if ((short)v26 < 3) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v31, 4u);
				}
			} while (++v9 <= v25);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v25, 4u);
		v28 = 1;
		if (v25 >= 1) {
			do {
				v10 = sub_421230();
				if (!v10) {
					return 0;
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v10 + 4, (unsigned char)v27);
				v10[(unsigned char)v27 + 4] = 0;
				if ((short)v26 >= 3 || (nox_xxx_fileReadWrite_426AC0_file3_fread(&v31, 4u),
										nox_xxx_fileReadWrite_426AC0_file3_fread(v32, 0xCu), v10[104] = v32[0],
										v10[105] = v32[4], v10[106] = v32[8], (short)v26 >= 3)) {
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
				v12 = calloc(*((unsigned short*)v10 + 64), 4u);
				*((uint32_t*)v10 + 27) = v12;
				if (!v12) {
					return 0;
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread(v12, 4 * (unsigned short)*v11);
				sub_421040((int)v10);
				v13 = nox_xxx_polygonGetAngle_421030(**((uint32_t**)v10 + 27));
				*((uint32_t*)v10 + 22) = nox_float2int(*((float*)v13 + 1));
				*((uint32_t*)v10 + 23) = nox_float2int(*((float*)v13 + 2));
				*((uint32_t*)v10 + 24) = nox_float2int(*((float*)v13 + 1));
				v14 = nox_float2int(*((float*)v13 + 2));
				v15 = 1;
				v16 = *v11 <= 1u;
				*((uint32_t*)v10 + 25) = v14;
				if (!v16) {
					do {
						v17 = nox_xxx_polygonGetAngle_421030(*(uint32_t*)(*((uint32_t*)v10 + 27) + 4 * v15));
						v18 = *((float*)v17 + 1);
						v29[0] = *((float*)v17 + 1);
						if (v18 >= (double)*((int*)v10 + 22)) {
							v19 = *((float*)v17 + 1);
							v29[0] = *((float*)v17 + 1);
							if (v19 > (double)*((int*)v10 + 24)) {
								*((uint32_t*)v10 + 24) = nox_float2int(v29[0]);
							}
						} else {
							*((uint32_t*)v10 + 22) = nox_float2int(v29[0]);
						}
						v20 = *((float*)v17 + 2);
						v29[0] = *((float*)v17 + 2);
						if (v20 >= (double)*((int*)v10 + 23)) {
							v21 = *((float*)v17 + 2);
							v29[0] = *((float*)v17 + 2);
							if (v21 > (double)*((int*)v10 + 25)) {
								*((uint32_t*)v10 + 25) = nox_float2int(v29[0]);
							}
						} else {
							*((uint32_t*)v10 + 23) = nox_float2int(v29[0]);
						}
						++v15;
					} while (v15 < (unsigned short)*v11);
				}
				if ((short)v26 >= 2) {
					v22 = *(char**)v10;
					nox_xxx_xferReadScriptHandler_4F5580((int)(v10 + 112), *(char**)v10);
					if (v22) {
						v23 = v22 + 128;
					} else {
						v23 = 0;
					}
					nox_xxx_xferReadScriptHandler_4F5580((int)(v10 + 120), v23);
				}
				if ((short)v26 >= 4) {
					v24 = v10 + 132;
					nox_xxx_fileReadWrite_426AC0_file3_fread(v24, 4u);
					if (*v24 & 1) {
						++v30;
					}
				}
			} while (++v28 <= v25);
		}
		sub_4D72D0(v30);
		return 1;
	}
	v25 = 0;
	for (i = nox_xxx_polygon_420CA0(); i; ++v25) {
		i = nox_xxx_polygon_420CD0(i);
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v25, 4u);
	v3 = nox_xxx_polygon_420CA0();
	for (j = 0; j < v25; ++j) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(v3, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v3 + 4, 8u);
		v3 = nox_xxx_polygon_420CD0(v3);
	}
	v25 = 0;
	for (k = nox_xxx_polygonGetNext_4210A0(); k; ++v25) {
		k = sub_4210E0((int)k);
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v25, 4u);
	v6 = nox_xxx_polygonGetNext_4210A0();
	v28 = 0;
	if (v25 <= 0) {
		return 1;
	}
	do {
		v7 = *(char**)v6;
		LOBYTE(v27) = strlen(v6 + 4);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v6 + 4, (unsigned char)v27);
		LOBYTE(a1) = v6[104];
		nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
		LOBYTE(a1) = v6[105];
		nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
		LOBYTE(a1) = v6[106];
		nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v6 + 130, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v6 + 128, 2u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(*((uint8_t**)v6 + 27), 4 * *((unsigned short*)v6 + 64));
		nox_xxx_xferReadScriptHandler_4F5580((int)(v6 + 112), v7);
		if (v7) {
			v8 = v7 + 128;
		} else {
			v8 = 0;
		}
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
	if ((short)v2 < 1) {
		return 0;
	}
	if (nox_xxx_cryptGetXxx()) {
		if (nox_xxx_cryptGetXxx() == 1) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v3[0], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v3[1], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v3[2], 4u);
			sub_469B90(v3);
			if (nox_common_gameFlags_check_40A5C0(2097154)) {
				sub_4349C0(v3);
			}
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
int nox_server_mapRWWindowWalls_4292C0(uint32_t* a1) {
	int result;   // eax
	uint32_t* v2; // edi
	char* v3;     // esi
	uint32_t* v4; // eax
	int v5;       // [esp+4h] [ebp-20h]
	int v6;       // [esp+8h] [ebp-1Ch]
	int2 v7;
	int4 v9; // [esp+14h] [ebp-10h]

	v5 = 2;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 2u);
	if ((short)v5 > 2) {
		return 0;
	}
	if (nox_xxx_cryptGetXxx()) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741336), 2u);
		v6 = 0;
		if (*getMemU16Ptr(0x5D4594, 741336) > 0) {
			v2 = a1;
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 8u);
				if (a1) {
					v3 = nox_xxx_mapGetWallSize_426A70();
					sub_428170(a1, &v9);
					v7.field_0 += v9.field_0 / 23 - *(uint32_t*)v3;
					v7.field_4 += v9.field_4 / 23 - *((uint32_t*)v3 + 1);
				}
				if (nox_common_gameFlags_check_40A5C0(0x400000)) {
					v4 = nox_xxx_cliWallGet_5042F0(v7.field_0, v7.field_4);
					if (v4) {
						v2 = (uint32_t*)*v4;
					}
				} else {
					v2 = (uint32_t*)nox_server_getWallAtGrid_410580(v7.field_0, v7.field_4);
				}
				if (v2) {
					*((uint8_t*)v2 + 4) |= 0x40u;
					if ((short)v5 < 2) {
						*((uint8_t*)v2 + 2) = 0;
					}
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
void sub_429450(uint8_t* a1, uint32_t* a2) {
	int v2;  // eax
	int2 v3; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned char)a1[6], v3.field_0 = 23 * (unsigned char)a1[5], v3.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v3, a2))) {
		if (a1[4] & 0x40) {
			++*getMemU16Ptr(0x5D4594, 741336);
		}
	}
}

//----- (004294B0) --------------------------------------------------------
void sub_4294B0(uint8_t* a1, uint32_t* a2) {
	int v2;  // eax
	int v3;  // edx
	int2 v4; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned char)a1[6], v4.field_0 = 23 * (unsigned char)a1[5], v4.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v4, a2))) {
		if (a1[4] & 0x40) {
			v3 = (unsigned char)a1[6];
			v4.field_0 = (unsigned char)a1[5];
			v4.field_4 = v3;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 8u);
		}
	}
}

//----- (00429520) --------------------------------------------------------
void nox_xxx_wallBreakableCounterClear_429520() { *getMemU32Ptr(0x5D4594, 741344) = 0; }

//----- (00429530) --------------------------------------------------------
int nox_server_mapRWDestructableWalls_429530(uint32_t* a1) {
	int result;   // eax
	uint32_t* v2; // edi
	char* v3;     // esi
	uint32_t* v4; // eax
	int v5;       // [esp+4h] [ebp-20h]
	int v6;       // [esp+8h] [ebp-1Ch]
	int2 v7;
	int4 v9; // [esp+14h] [ebp-10h]

	v5 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 2u);
	if ((short)v5 > 1) {
		return 0;
	}
	if (nox_xxx_cryptGetXxx()) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 741340), 2u);
		v6 = 0;
		if (*getMemU16Ptr(0x5D4594, 741340) > 0) {
			v2 = a1;
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 8u);
				if (a1) {
					v3 = nox_xxx_mapGetWallSize_426A70();
					sub_428170(a1, &v9);
					v7.field_0 += v9.field_0 / 23 - *(uint32_t*)v3;
					v7.field_4 += v9.field_4 / 23 - *((uint32_t*)v3 + 1);
				}
				if (nox_common_gameFlags_check_40A5C0(0x400000)) {
					v4 = nox_xxx_cliWallGet_5042F0(v7.field_0, v7.field_4);
					if (v4) {
						v2 = (uint32_t*)*v4;
					}
				} else {
					v2 = (uint32_t*)nox_server_getWallAtGrid_410580(v7.field_0, v7.field_4);
				}
				if (v2) {
					*((uint8_t*)v2 + 4) |= 8u;
					*((uint16_t*)v2 + 5) = *getMemU16Ptr(0x5D4594, 741344);
					++*getMemU32Ptr(0x5D4594, 741344);
					if (!nox_common_gameFlags_check_40A5C0(0x400000)) {
						nox_xxx_wallBreackableListAdd_410840((int)v2);
					}
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
void nox_xxx_wall_4296E0(uint8_t* a1, uint32_t* a2) {
	int v2;  // eax
	int2 v3; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned char)a1[6], v3.field_0 = 23 * (unsigned char)a1[5], v3.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v3, a2))) {
		if (a1[4] & 8) {
			++*getMemU16Ptr(0x5D4594, 741340);
		}
	}
}

//----- (00429740) --------------------------------------------------------
void sub_429740(uint8_t* a1, uint32_t* a2) {
	int v2;  // eax
	int v3;  // edx
	int2 v4; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned char)a1[6], v4.field_0 = 23 * (unsigned char)a1[5], v4.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v4, a2))) {
		if (a1[4] & 8) {
			v3 = (unsigned char)a1[6];
			v4.field_0 = (unsigned char)a1[5];
			v4.field_4 = v3;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 8u);
		}
	}
}

//----- (004297B0) --------------------------------------------------------
void nox_xxx_wallSecretCounterClear_4297B0() { *getMemU32Ptr(0x5D4594, 741352) = 0; }

//----- (004297C0) --------------------------------------------------------
int nox_server_mapRWSecretWalls_4297C0(uint32_t* a1) {
	char* v2;    // esi
	int* v3;     // edi
	uint8_t* v4; // ebx
	char* v5;    // ebp
	int* v6;     // eax
	int v7;      // eax
	char v8;     // dl
	int v9;      // [esp+4h] [ebp-1Ch]
	int v10 = 0; // [esp+8h] [ebp-18h]
	int v11;     // [esp+Ch] [ebp-14h]
	int4 v12;    // [esp+10h] [ebp-10h]

	v9 = 2;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 2u);
	if ((short)v9 > 2) {
		return 0;
	}
	if (!nox_xxx_cryptGetXxx()) {
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
			if ((short)v9 >= 2) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 21, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 22, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 24, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 28, 4u);
			}
			if (a1) {
				v5 = nox_xxx_mapGetWallSize_426A70();
				sub_428170(a1, &v12);
				*v3 += v12.field_0 / 23 - *(uint32_t*)v5;
				*((uint32_t*)v2 + 2) += v12.field_4 / 23 - *((uint32_t*)v5 + 1);
			}
			if (!nox_common_gameFlags_check_40A5C0(0x400000)) {
				break;
			}
			v6 = nox_xxx_cliWallGet_5042F0(*v3, *((uint32_t*)v2 + 2));
			if (!v6) {
				goto LABEL_14;
			}
			v7 = *v6;
			v10 = v7;
		LABEL_15:
			if (v7) {
				v8 = *(uint8_t*)(v7 + 4);
				*(uint32_t*)(v7 + 28) = v2;
				*(uint8_t*)(v7 + 4) = v8 | 4;
				*(uint16_t*)(v7 + 10) = *getMemU16Ptr(0x5D4594, 741352);
				++*getMemU32Ptr(0x5D4594, 741352);
				*((uint32_t*)v2 + 3) = v7;
				if (!*v4) {
					if (v2[20] & 8) {
						*((uint32_t*)v2 + 7) = -1;
						*v4 = 3;
						v2[22] = 23;
					} else {
						*((uint32_t*)v2 + 7) = 0;
						*v4 = 1;
						v2[22] = 0;
					}
				}
				if (!nox_common_gameFlags_check_40A5C0(0x400000)) {
					nox_xxx_wallSecretBlock_410760(v2);
				}
			}
			if (++v11 >= *getMemI16Ptr(0x5D4594, 741348)) {
				return 1;
			}
		}
		v10 = nox_server_getWallAtGrid_410580(*v3, *((uint32_t*)v2 + 2));
	LABEL_14:
		v7 = v10;
		goto LABEL_15;
	}
	return 1;
}

//----- (00429A00) --------------------------------------------------------
void sub_429A00(uint8_t* a1, uint32_t* a2) {
	int v2;  // eax
	int2 v3; // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = (unsigned char)a1[6], v3.field_0 = 23 * (unsigned char)a1[5], v3.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v3, a2))) {
		if (a1[4] & 4) {
			++*getMemU16Ptr(0x5D4594, 741348);
		}
	}
}

//----- (00429A60) --------------------------------------------------------
void sub_429A60(int a1, uint32_t* a2) {
	int v2;      // eax
	int v3;      // edx
	uint8_t* v4; // esi
	int2 v5;     // [esp+4h] [ebp-8h]

	if (!a2 || (v2 = *(unsigned char*)(a1 + 6), v5.field_0 = 23 * *(unsigned char*)(a1 + 5), v5.field_4 = 23 * v2,
				nox_xxx_wallMath_427F30(&v5, a2))) {
		if (*(uint8_t*)(a1 + 4) & 4) {
			v3 = *(unsigned char*)(a1 + 6);
			v4 = *(uint8_t**)(a1 + 28);
			v5.field_0 = *(unsigned char*)(a1 + 5);
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
int nox_server_mapRWWallMap_429B20(uint32_t* a1) {
	uint32_t* v2;                       // ebp
	int v3;                             // esi
	int v5;                             // edx
	int v6;                             // edx
	int v7;                             // ecx
	int v8;                             // eax
	int v9;                             // edi
	uint8_t* v10;                       // eax
	uint8_t* v11;                       // esi
	nox_player_polygon_check_data* v12; // eax
	int v13;                            // eax
	int v14;                            // eax
	char v15;                           // bl
	char v16;                           // bl
	unsigned char* v17;                 // esi
	int v18;                            // edi
	unsigned char* v19;                 // eax
	unsigned char* v20;                 // edi
	unsigned char* v21;                 // ebx
	char v22;                           // [esp+2h] [ebp-3Ah]
	char v23;                           // [esp+3h] [ebp-39h]
	int v24;                            // [esp+4h] [ebp-38h]
	int v25;                            // [esp+8h] [ebp-34h]
	int v26;                            // [esp+Ch] [ebp-30h]
	int v27;                            // [esp+10h] [ebp-2Ch]
	int v28;                            // [esp+14h] [ebp-28h]
	int v29;                            // [esp+18h] [ebp-24h]
	int v30;                            // [esp+1Ch] [ebp-20h]
	int v31;                            // [esp+20h] [ebp-1Ch]
	int2 v32;                           // [esp+24h] [ebp-18h]
	int4 v33;                           // [esp+2Ch] [ebp-10h]

	v31 = nox_xxx_wallGet_426A30();
	if (!getMemByte(0x5D4594, 741372)) {
		*getMemU8Ptr(0x5D4594, 741372) = nox_xxx_wallTileByName_410D60("MagicWallSystemUseOnly");
	}
	nox_xxx_wallSecretCounterClear_4297B0();
	nox_xxx_wallBreakableCounterClear_429520();
	v28 = 7;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v28, 2u);
	if ((short)v28 > 7) {
		return 0;
	}
	if ((short)v28 < 6) {
		return sub_42A150(v28, a1);
	}
	v2 = a1;
	if (!nox_xxx_cryptGetXxx()) {
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
	if (nox_xxx_cryptGetXxx()) {
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
		if (v22 == -1) {
			return 1;
		}
		while (1) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
			LOBYTE(v30) = v29 + v15;
			LOBYTE(a1) = v26 + (uint8_t)a1;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v24, 1u);
			v16 = (unsigned char)v24 >> 7;
			LOBYTE(v24) = v24 & 0x7F;
			if (nox_common_gameFlags_check_40A5C0(0x400000)) {
				v17 = (unsigned char*)*sub_504290(v30, (char)a1);
			} else {
				v18 = (unsigned char)v30;
				v19 = (unsigned char*)nox_server_getWallAtGrid_410580((unsigned char)v30, (unsigned char)a1);
				v17 = v19;
				if (v19) {
					if (v31 & 1) {
						*v19 = nox_xxx_wall_42A6C0(*v19, v24);
					} else {
						*v19 = v24;
					}
					goto LABEL_46;
				}
				v17 = (unsigned char*)nox_xxx_wallCreateAt_410250(v18, (unsigned char)a1);
				if (!v17) {
					return 0;
				}
			}
			*v17 = v24;
		LABEL_46:
			if (v16) {
				v17[4] |= 0x80u;
			}
			v20 = v17 + 1;
			nox_xxx_fileReadWrite_426AC0_file3_fread(v17 + 1, 1u);
			v21 = v17 + 2;
			nox_xxx_fileReadWrite_426AC0_file3_fread(v17 + 2, 1u);
			if (v31 & 1 && *v21 >= nox_xxx_mapWallMaxVariation_410DD0(*v20, *v17, 0)) {
				*v21 = 0;
			}
			v17[7] = nox_xxx_mapWallGetHpByTile_410E20(*v20);
			if ((uint16_t)v28 == 6) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v24, 1u);
				v17[8] = 1;
				*((uint32_t*)v17 + 3) = 0;
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread(v17 + 8, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v24, 1u);
				*((uint32_t*)v17 + 3) = (unsigned char)v24;
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 1u);
			v15 = v22;
			if (v22 == -1) {
				return 1;
			}
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
					v10 = (uint8_t*)nox_server_getWallAtGrid_410580(v9, v26);
					v11 = v10;
					if (v10) {
						if (v10[1] != getMemByte(0x5D4594, 741372)) {
							if (!v2 || (v32.field_0 = 23 * (unsigned char)v10[5],
										v32.field_4 = 23 * (unsigned char)v10[6], nox_xxx_wallMath_427F30(&v32, v2))) {
								nox_xxx_fileReadWrite_426AC0_file3_fread(v11 + 5, 1u);
								nox_xxx_fileReadWrite_426AC0_file3_fread(v11 + 6, 1u);
								if ((int)v11[4] >= 0) {
									LOBYTE(v24) = *v11;
								} else {
									LOBYTE(v24) = *v11 | 0x80;
								}
								nox_xxx_fileReadWrite_426AC0_file3_fread(&v24, 1u);
								nox_xxx_fileReadWrite_426AC0_file3_fread(v11 + 1, 1u);
								nox_xxx_fileReadWrite_426AC0_file3_fread(v11 + 2, 1u);
								v32.field_0 = 23 * (unsigned char)v11[5] + 11;
								v32.field_4 = 23 * (unsigned char)v11[6] + 11;
								v12 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v32, 0);
								if (v12 || (v12 = (nox_player_polygon_check_data*)sub_421990(&v32, 10.0, 0)) != 0) {
									v23 = BYTE2(v12->field_0[32]);
								} else {
									v23 = 100;
								}
								nox_xxx_fileReadWrite_426AC0_file3_fread(&v23, 1u);
								if (nox_common_gameFlags_check_40A5C0(0x200000)) {
									LOBYTE(v24) = 0;
								} else {
									LOBYTE(v24) = v11[12];
								}
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
int sub_42A0F0(int a1) {
	int result; // eax

	if ((int)*(unsigned char*)(a1 + 5) < *getMemIntPtr(0x5D4594, 741360)) {
		*getMemU32Ptr(0x5D4594, 741360) = *(unsigned char*)(a1 + 5);
	}
	if ((int)*(unsigned char*)(a1 + 5) > *(int*)&dword_5d4594_741356) {
		dword_5d4594_741356 = *(unsigned char*)(a1 + 5);
	}
	if ((int)*(unsigned char*)(a1 + 6) < *getMemIntPtr(0x5D4594, 741368)) {
		*getMemU32Ptr(0x5D4594, 741368) = *(unsigned char*)(a1 + 6);
	}
	result = *(unsigned char*)(a1 + 6);
	if (result > *(int*)&dword_5d4594_741364) {
		dword_5d4594_741364 = *(unsigned char*)(a1 + 6);
	}
	return result;
}

//----- (0042A150) --------------------------------------------------------
int sub_42A150(short a1, uint32_t* a2) {
	int v2;                             // eax
	uint32_t* v3;                       // ebx
	int v4;                             // edi
	int v5;                             // esi
	int v6;                             // edx
	int v7;                             // edx
	int v8;                             // ebp
	int v9;                             // ecx
	int v10;                            // eax
	int v11;                            // edi
	int v12;                            // eax
	uint8_t* v13;                       // esi
	nox_player_polygon_check_data* v14; // eax
	int v16;                            // eax
	int v17;                            // ebp
	unsigned char v18;                  // bl
	char v19;                           // bl
	unsigned char** v20;                // eax
	unsigned char* v21;                 // esi
	unsigned char* v22;                 // eax
	unsigned char v23;                  // al
	short v24;                          // bx
	unsigned char* v25;                 // edi
	char v26;                           // [esp+13h] [ebp-2Dh]
	int v27;                            // [esp+14h] [ebp-2Ch]
	int v28;                            // [esp+18h] [ebp-28h]
	int v29;                            // [esp+1Ch] [ebp-24h]
	int v30;                            // [esp+20h] [ebp-20h]
	int v31;                            // [esp+24h] [ebp-1Ch]
	int2 v32;                           // [esp+28h] [ebp-18h]
	int4 v33;                           // [esp+30h] [ebp-10h]

	v2 = nox_xxx_wallGet_426A30();
	v3 = a2;
	v30 = v2;
	v4 = 0;
	if (!nox_xxx_cryptGetXxx()) {
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
	if (!nox_xxx_cryptGetXxx()) {
		v7 = *getMemU32Ptr(0x5D4594, 741368);
		v8 = *getMemU32Ptr(0x5D4594, 741368);
		if (*getMemU32Ptr(0x5D4594, 741368) > *getMemIntPtr(0x5D4594, 741368) + v29) {
			return 1;
		}
		v9 = v28;
		v10 = *getMemU32Ptr(0x5D4594, 741360);
		while (1) {
			v11 = v10;
			if (v10 > v10 + v9) {
				goto LABEL_27;
			}
			do {
				v12 = nox_server_getWallAtGrid_410580(v11, v8);
				v13 = (uint8_t*)v12;
				if (v3) {
					if (!v12) {
						goto LABEL_15;
					}
					v32.field_0 = 23 * *(unsigned char*)(v12 + 5);
					v32.field_4 = 23 * *(unsigned char*)(v12 + 6);
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
				if ((int)v13[4] >= 0) {
					LOBYTE(v27) = *v13;
				} else {
					LOBYTE(v27) = *v13 | 0x80;
				}
			LABEL_19:
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 1u);
				if ((uint8_t)v27 != (uint8_t)-1) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(v13 + 1, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(v13 + 2, 1u);
					v32.field_0 = 23 * (unsigned char)v13[5] + 11;
					v32.field_4 = 23 * (unsigned char)v13[6] + 11;
					v14 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v32, 0);
					if (v14 || (v14 = (nox_player_polygon_check_data*)sub_421990(&v32, 10.0, 0)) != 0) {
						v26 = BYTE2(v14->field_0[32]);
					} else {
						v26 = 1;
					}
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
			if (++v8 > v7 + v29) {
				return 1;
			}
		}
	}
	if (v3) {
		sub_428170(v3, &v33);
		*getMemU32Ptr(0x5D4594, 741360) = v33.field_0 / 23;
		*getMemU32Ptr(0x5D4594, 741368) = v33.field_4 / 23;
	}
	v31 = 0;
	if (v29 < 0) {
		return 1;
	}
	v16 = v28;
	while (1) {
		v17 = 0;
		if (v16 >= 0) {
			break;
		}
	LABEL_60:
		v31 = ++v4;
		if (v4 > v29) {
			return 1;
		}
	}
	while (1) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 1u);
		if ((uint8_t)v27 != (uint8_t)-1) {
			break;
		}
	LABEL_59:
		v16 = v28;
		if (++v17 > v28) {
			goto LABEL_60;
		}
	}
	v18 = v27;
	LOBYTE(v27) = v27 & 0x7F;
	v19 = v18 >> 7;
	if (nox_common_gameFlags_check_40A5C0(0x400000)) {
		v20 = (unsigned char**)sub_504290(v17 + getMemByte(0x5D4594, 741360), v4 + getMemByte(0x5D4594, 741368));
		v21 = *v20;
		**v20 = v27;
	LABEL_43:
		if (v19) {
			v21[4] |= 0x80u;
		}
		v24 = a1;
		if (a1 < 2) {
			v21[1] = 0;
			v21[7] = nox_xxx_mapWallGetHpByTile_410E20(0);
			v21[8] = 1;
		} else {
			v25 = v21 + 1;
			nox_xxx_fileReadWrite_426AC0_file3_fread(v21 + 1, 1u);
			if (v24 >= 3) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(v21 + 2, 1u);
			} else {
				sub_42A650(v21);
			}
			if (v30 & 1 && v21[2] >= nox_xxx_mapWallMaxVariation_410DD0(*v25, *v21, 0)) {
				v21[2] = 0;
			}
			v21[7] = nox_xxx_mapWallGetHpByTile_410E20(*v25);
			if (v24 < 4) {
				v21[8] = 1;
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread(v21 + 8, 1u);
			}
			LOBYTE(a2) = 0;
			if (v24 >= 5) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
			}
			v4 = v31;
			*((uint32_t*)v21 + 3) = (unsigned char)a2;
		}
		goto LABEL_59;
	}
	v22 = (unsigned char*)nox_server_getWallAtGrid_410580(v17 + *getMemU32Ptr(0x5D4594, 741360),
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
	v21 = (unsigned char*)nox_xxx_wallCreateAt_410250(v17 + *getMemU32Ptr(0x5D4594, 741360),
													  v4 + *getMemU32Ptr(0x5D4594, 741368));
	if (v21) {
		goto LABEL_41;
	}
	return 0;
}

//----- (0042A650) --------------------------------------------------------
int sub_42A650(unsigned char* a1) {
	unsigned char v1; // cl
	int result;       // eax

	v1 = *a1;
	a1[2] = 0;
	if (!v1) {
		a1[2] = a1[5] % 3;
	}
	if (v1 == 1) {
		a1[2] = a1[5] % 3;
	}
	result = nox_xxx_getWallSprite_46A3B0(a1[1], v1, a1[2], (a1[4] >> 2) & 2);
	if (!result) {
		a1[2] = 0;
	}
	return result;
}

//----- (0042A6C0) --------------------------------------------------------
unsigned char nox_xxx_wall_42A6C0(unsigned char a1, unsigned char a2) {
	return getMemByte(0x587000, 71276 + 13 * a1 + a2);
}

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
		} else if (nox_xxx_cryptGetXxx() == 1) {
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
uint16_t* sub_42A8B0(uint8_t* a1, int* a2) {
	int v2;                // eax
	uint8_t* v3;           // esi
	uint8_t* v4;           // ebx
	uint16_t* result;      // eax
	int v6;                // esi
	void* v7;              // eax
	int v8;                // eax
	uint16_t* v9;          // esi
	unsigned char v10[12]; // [esp+Ch] [ebp-Ch]

	*(uint16_t*)v10 = 0;
	*(uint16_t*)&v10[2] = 0;
	v2 = *a2;
	*(uint32_t*)&v10[4] = 0;
	v3 = calloc(v2, 2);
	sub_42A970(a1, v3, a2);
	v4 = sub_42AC50(v3, (size_t*)a2);
	if (v3) {
		free(v3);
	}
	if (v4) {
		v6 = *a2;
		v7 = operator_new(0x10u);
		if (v7) {
			v8 = sub_42C910((int)v7, (char*)getMemAt(0x587000, 71480), v4, v6);
		} else {
			v8 = 0;
		}
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
int sub_42A970(uint8_t* a1, uint8_t* a2, int* a3) {
	int v3;            // eax
	char v4;           // bl
	int v5;            // edx
	int v6;            // ecx
	int v7;            // esi
	int v8;            // eax
	int* v9;           // edx
	uint8_t* v10;      // ebp
	int v11;           // edi
	char v12;          // cl
	int result;        // eax
	int v14;           // edx
	int v15;           // eax
	int v16;           // ebp
	char v17;          // [esp+13h] [ebp-405h]
	unsigned char v18; // [esp+14h] [ebp-404h]
	int v19[256];      // [esp+18h] [ebp-400h]

	v3 = 0;
	v4 = 1;
	memset(v19, 0, sizeof(v19));
	v18 = 1;
	v5 = *a3;
	if (*a3 > 0) {
		do {
			v6 = (unsigned char)a1[v3++];
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
		if (v8 >= 256) {
			goto LABEL_10;
		}
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
				if ((unsigned char)v4 <= 3u) {
					if ((int)v18 > 0) {
						v16 = v18;
						do {
							if (v12 == v17) {
								a2[result++] = v12;
							}
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
double sub_42AAA0(int* a1) {
	int v1;            // eax
	int v2;            // esi
	int v3;            // edi
	int v4;            // ecx
	int v5;            // edi
	int v6;            // esi
	unsigned char* v7; // ecx
	int v8;            // eax
	int v9;            // edx
	int v10;           // ecx
	int v11;           // eax
	int v13;           // [esp+Ch] [ebp+4h]

	if ((int)*a1 < 0 || !*getMemU32Ptr(0x5D4594, 741656)) {
		*getMemU32Ptr(0x5D4594, 741656) = 1;
		v1 = *a1;
		if ((int)*a1 < 0) {
			v1 = -v1;
		}
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
				v8 = *(uint32_t*)v7 - *getMemU32Ptr(0x5D4594, 741388 + 4 * ((v6 + 30) % 55));
				*(uint32_t*)v7 = v8;
				if (v8 < 0) {
					*(uint32_t*)v7 = v8 + 1000000000;
				}
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
void sub_42ABF0(int a1, int a2, int a3) {
	double v3; // st7
	int i;     // esi

	if (a3 > 0) {
		a3 = -a3;
	}
	v3 = sub_42AAA0(&a3);
	for (i = 0; i < a2; ++i) {
		int v5 = (int)(v3 * 255.0);
		if (v5 < 0) {
			v5 = -v5;
		}
		*(uint8_t*)(i + a1) = v5;
		v3 = sub_42AAA0(&a3);
	}
}

//----- (0042AC50) --------------------------------------------------------
uint8_t* sub_42AC50(uint8_t* a1, size_t* a2) {
	size_t* v2;        // esi
	void* v3;          // ebp
	size_t v4;         // ecx
	uint8_t* v5;       // edi
	uint8_t* result;   // eax
	time_t v7;         // eax
	int v8;            // ebx
	u_long v9;         // eax
	time_t v10;        // eax
	unsigned char v11; // al
	int v12;           // ebp
	int v13;           // ecx
	uint8_t* v14;      // edx
	int v15;           // ebx
	char v16;          // al
	int v17;           // [esp-Ch] [ebp-28h]
	void* v18;         // [esp-8h] [ebp-24h]
	time_t v19;        // [esp+Ch] [ebp-10h]
	void* lpMem;       // [esp+10h] [ebp-Ch]
	int v21;           // [esp+14h] [ebp-8h]
	u_long v22;        // [esp+18h] [ebp-4h]
	float v23;         // [esp+24h] [ebp+8h]
	unsigned char v24; // [esp+24h] [ebp+8h]

	v2 = a2;
	v19 = 0;
	v3 = calloc(1, *a2);
	v4 = *a2 + 5;
	lpMem = v3;
	v5 = calloc(1, v4);
	if ((int)*a2 >= 15) {
		v7 = time(0);
		v8 = v7;
		if (v7 > 0) {
			v8 = -v7;
		}
		v9 = htonl(v8);
		v17 = *a2;
		v22 = v9;
		sub_42ABF0((int)v3, v17, v8);
		v10 = time(0);
		v19 = v10;
		if (v10 > 0) {
			v19 = -v10;
		}
		if ((int)*a2 >= 241) {
			v23 = 241.0;
		} else {
			v23 = (double)(int)(*a2 - 14);
		}
		v11 = (unsigned long long)(long long)(sub_42AAA0(&v19) * v23) + 10;
		v12 = 0;
		v13 = 0;
		v24 = v11;
		if ((int)*v2 > 0) {
			v21 = v11;
			v14 = a1;
			v15 = (uint8_t*)lpMem - a1;
			while (1) {
				if (v13 == 5) {
					v5[5] = v11;
					v13 = 6;
				}
				if (v13 == v21) {
					*(uint32_t*)&v5[v13] = v22;
					v13 += 4;
				}
				v16 = *v14 ^ v14[v15];
				++v13;
				++v12;
				++v14;
				v5[v13 - 1] = v16;
				if (v12 >= (int)*v2) {
					break;
				}
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
uint16_t* sub_42ADA0(int a1, int a2, short a3, unsigned int* a4) {
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
	short v89;        // di
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
	uint16_t* v115;   // esi
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
	v5 = *(uint32_t*)(a1 + 8);
	*(uint16_t*)v118 = 0;
	*(uint16_t*)&v118[2] = 0;
	*(uint32_t*)&v118[4] = 0;
	v6 = operator_new(0x10u);
	if (v6) {
		v7 = sub_42C8B0((int)v6, "MXPL", v5);
	} else {
		v7 = 0;
	}
	sub_42C360(v118, v7);
	v8 = *(uint32_t*)(a1 + 12);
	v9 = operator_new(0x10u);
	if (v9) {
		v10 = sub_42C8B0((int)v9, "IDNO", v8);
	} else {
		v10 = 0;
	}
	sub_42C360(v118, v10);
	v11 = *(uint32_t*)(a1 + 16);
	v12 = operator_new(0x10u);
	if (v12) {
		v13 = sub_42C8B0((int)v12, "GSKU", v11);
	} else {
		v13 = 0;
	}
	sub_42C360(v118, v13);
	v14 = *(uint32_t*)(a1 + 20);
	v15 = operator_new(0x10u);
	if (v15) {
		v16 = sub_42C8B0((int)v15, "GSTY", v14);
	} else {
		v16 = 0;
	}
	sub_42C360(v118, v16);
	v119 = *(uint8_t*)(a1 + 24);
	v17 = operator_new(0x10u);
	if (v17) {
		v18 = sub_42C7F0((int)v17, "CLGM", v119);
	} else {
		v18 = 0;
	}
	sub_42C360(v118, v18);
	v19 = *(uint32_t*)(v4 + 32);
	v20 = operator_new(0x10u);
	if (v20) {
		v21 = sub_42C8B0((int)v20, "LIMT", v19);
	} else {
		v21 = 0;
	}
	sub_42C360(v118, v21);
	v22 = *(uint32_t*)(v4 + 36);
	v23 = operator_new(0x10u);
	if (v23) {
		v24 = sub_42C8B0((int)v23, "TLMT", v22);
	} else {
		v24 = 0;
	}
	sub_42C360(v118, v24);
	v120 = *(uint8_t*)(v4 + 40);
	v25 = operator_new(0x10u);
	if (v25) {
		v26 = sub_42C7F0((int)v25, "RSTC", v120);
	} else {
		v26 = 0;
	}
	sub_42C360(v118, v26);
	v27 = *(uint32_t*)(v4 + 44);
	v28 = operator_new(0x10u);
	if (v28) {
		v29 = sub_42C8B0((int)v28, "MINE", v27);
	} else {
		v29 = 0;
	}
	sub_42C360(v118, v29);
	v30 = *(uint32_t*)(v4 + 48);
	v31 = operator_new(0x10u);
	if (v31) {
		v32 = sub_42C8B0((int)v31, "MAXE", v30);
	} else {
		v32 = 0;
	}
	sub_42C360(v118, v32);
	v33 = *(uint32_t*)(v4 + 52);
	v34 = operator_new(0x10u);
	if (v34) {
		v35 = sub_42C8B0((int)v34, "MINP", v33);
	} else {
		v35 = 0;
	}
	sub_42C360(v118, v35);
	v36 = *(uint32_t*)(v4 + 56);
	v37 = operator_new(0x10u);
	if (v37) {
		v38 = sub_42C8B0((int)v37, "MAXP", v36);
	} else {
		v38 = 0;
	}
	sub_42C360(v118, v38);
	v121 = *(uint8_t*)(v4 + 60);
	v39 = operator_new(0x10u);
	if (v39) {
		v40 = sub_42C7F0((int)v39, "VIDM", v121);
	} else {
		v40 = 0;
	}
	sub_42C360(v118, v40);
	v122 = *(uint8_t*)(v4 + 61);
	v41 = operator_new(0x10u);
	if (v41) {
		v42 = sub_42C7F0((int)v41, "SVRS", v122);
	} else {
		v42 = 0;
	}
	sub_42C360(v118, v42);
	v123 = *(uint8_t*)(v4 + 25);
	v43 = operator_new(0x10u);
	if (v43) {
		v44 = sub_42C7F0((int)v43, "NTMS", v123);
	} else {
		v44 = 0;
	}
	sub_42C360(v118, v44);
	v45 = operator_new(0x10u);
	if (v45) {
		v46 = sub_42C8E0((int)v45, "SCEN", (const char*)(v4 + 96));
	} else {
		v46 = 0;
	}
	sub_42C360(v118, v46);
	v47 = operator_new(0x10u);
	if (v47) {
		v48 = sub_42C8E0((int)v47, "GNAM", (const char*)(v4 + 352));
	} else {
		v48 = 0;
	}
	sub_42C360(v118, v48);
	v49 = *(uint32_t*)(v4 + 64);
	v50 = operator_new(0x10u);
	if (v50) {
		v51 = sub_42C8B0((int)v50, "SPL1", v49);
	} else {
		v51 = 0;
	}
	sub_42C360(v118, v51);
	v52 = *(uint32_t*)(v4 + 68);
	v53 = operator_new(0x10u);
	if (v53) {
		v54 = sub_42C8B0((int)v53, "SPL2", v52);
	} else {
		v54 = 0;
	}
	sub_42C360(v118, v54);
	v55 = *(uint32_t*)(v4 + 72);
	v56 = operator_new(0x10u);
	if (v56) {
		v57 = sub_42C8B0((int)v56, "SPL3", v55);
	} else {
		v57 = 0;
	}
	sub_42C360(v118, v57);
	v58 = *(uint32_t*)(v4 + 88);
	v59 = operator_new(0x10u);
	if (v59) {
		v60 = sub_42C8B0((int)v59, "ARMR", v58);
	} else {
		v60 = 0;
	}
	sub_42C360(v118, v60);
	v124 = *(uint8_t*)(v4 + 84);
	v61 = operator_new(0x10u);
	if (v61) {
		v62 = sub_42C7F0((int)v61, "WPN1", v124);
	} else {
		v62 = 0;
	}
	sub_42C360(v118, v62);
	v125 = *(uint8_t*)(v4 + 85);
	v63 = operator_new(0x10u);
	if (v63) {
		v64 = sub_42C7F0((int)v63, "WPN2", v125);
	} else {
		v64 = 0;
	}
	sub_42C360(v118, v64);
	v126 = *(uint8_t*)(v4 + 86);
	v65 = operator_new(0x10u);
	if (v65) {
		v66 = sub_42C7F0((int)v65, "WPN3", v126);
	} else {
		v66 = 0;
	}
	sub_42C360(v118, v66);
	v67 = *(uint32_t*)(v4 + 92);
	v68 = operator_new(0x10u);
	if (v68) {
		v69 = sub_42C8B0((int)v68, "STAF", v67);
	} else {
		v69 = 0;
	}
	sub_42C360(v118, v69);
	v70 = *(uint32_t*)(v4 + 28);
	v71 = operator_new(0x10u);
	if (v71) {
		v72 = sub_42C8B0((int)v71, "DURA", v70);
	} else {
		v72 = 0;
	}
	sub_42C360(v118, v72);
	v73 = operator_new(0x10u);
	if (v73) {
		v74 = sub_42C7F0((int)v73, "FINI", 1);
	} else {
		v74 = 0;
	}
	sub_42C360(v118, v74);
	v127 = *(uint8_t*)(v4 + 26);
	v75 = operator_new(0x10u);
	if (v75) {
		v76 = sub_42C7F0((int)v75, "TRNY", v127);
	} else {
		v76 = 0;
	}
	sub_42C360(v118, v76);
	switch (a2) {
	case 0:
		*getMemU32Ptr(0x5D4594, 741668) = 0;
		v77 = operator_new(0x10u);
		if (v77) {
			v78 = sub_42C8B0((int)v77, "SEQU", 0);
		} else {
			v78 = 0;
		}
		sub_42C360(v118, v78);
		v79 = operator_new(0x10u);
		if (v79) {
			v80 = sub_42C7F0((int)v79, "ENDF", 0);
		} else {
			v80 = 0;
		}
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
		if (v85) {
			v86 = sub_42C8B0((int)v85, "SEQU", v84);
		} else {
			v86 = 0;
		}
		sub_42C360(v118, v86);
		v87 = operator_new(0x10u);
		if (v87) {
			v88 = sub_42C7F0((int)v87, "ENDF", 1);
		} else {
			v88 = 0;
		}
		sub_42C360(v118, v88);
		v89 = *(uint16_t*)(v4 + 6);
		v90 = operator_new(0x10u);
		if (v90) {
			v91 = sub_42C820((int)v90, (char*)getMemAt(0x587000, 71896), v89);
		} else {
			v91 = 0;
		}
		sub_42C360(v118, v91);
		v92 = 0;
		for (*getMemU32Ptr(0x5D4594, 741660) = 0; v92 < *(short*)(v4 + 6); *getMemU32Ptr(0x5D4594, 741660) = v92) {
			*getMemU8Ptr(0x587000, 71491) = v92 + 48;
			v93 = *(const char**)(*(uint32_t*)(v4 + 608) + 4 * v92);
			v94 = operator_new(0x10u);
			if (v94) {
				v95 = sub_42C8E0((int)v94, "LGL?", v93);
			} else {
				v95 = 0;
			}
			sub_42C360(v118, v95);
			*getMemU8Ptr(0x587000, 71499) = getMemByte(0x5D4594, 741660) + 48;
			v96 = *(uint32_t*)(*(uint32_t*)(v4 + 612) + 4 * *getMemU32Ptr(0x5D4594, 741660));
			v97 = operator_new(0x10u);
			if (v97) {
				v98 = sub_42C8B0((int)v97, "IPL?", v96);
			} else {
				v98 = 0;
			}
			sub_42C360(v118, v98);
			*getMemU8Ptr(0x587000, 71515) = getMemByte(0x5D4594, 741660) + 48;
			v99 = *(uint32_t*)(*(uint32_t*)(v4 + 616) + 4 * *getMemU32Ptr(0x5D4594, 741660));
			v100 = operator_new(0x10u);
			if (v100) {
				v101 = sub_42C8B0((int)v100, "CNL?", v99);
			} else {
				v101 = 0;
			}
			sub_42C360(v118, v101);
			*getMemU8Ptr(0x587000, 71507) = getMemByte(0x5D4594, 741660) + 48;
			v128 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 741660) + *(uint32_t*)(v4 + 620));
			v102 = operator_new(0x10u);
			if (v102) {
				v103 = sub_42C7F0((int)v102, "CLL?", v128);
			} else {
				v103 = 0;
			}
			sub_42C360(v118, v103);
			*getMemU8Ptr(0x587000, 71523) = getMemByte(0x5D4594, 741660) + 48;
			v129 = *(uint8_t*)(*(uint32_t*)(v4 + 624) + *getMemU32Ptr(0x5D4594, 741660));
			v104 = operator_new(0x10u);
			if (v104) {
				v105 = sub_42C7F0((int)v104, "CMP?", v129);
			} else {
				v105 = 0;
			}
			sub_42C360(v118, v105);
			*getMemU8Ptr(0x587000, 71531) = getMemByte(0x5D4594, 741660) + 48;
			v106 = *(uint32_t*)(*(uint32_t*)(v4 + 628) + 4 * *getMemU32Ptr(0x5D4594, 741660));
			v107 = operator_new(0x10u);
			if (v107) {
				v108 = sub_42C8B0((int)v107, "DUR?", v106);
			} else {
				v108 = 0;
			}
			sub_42C360(v118, v108);
			*getMemU8Ptr(0x587000, 71539) = getMemByte(0x5D4594, 741660) + 48;
			v117 = *(uint8_t*)(*(uint32_t*)(v4 + 632) + *getMemU32Ptr(0x5D4594, 741660));
			v109 = operator_new(0x10u);
			if (v109) {
				v110 = sub_42C7F0((int)v109, "PAR?", v117);
			} else {
				v110 = 0;
			}
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
		sub_42BD50(v118, (char*)getMemAt(0x587000, 71928), *(uint16_t*)(v4 + 6));
		v114 = 0;
		for (*getMemU32Ptr(0x5D4594, 741660) = 0; v114 < *(short*)(v4 + 6); *getMemU32Ptr(0x5D4594, 741660) = v114) {
			*getMemU8Ptr(0x587000, 71491) = v114 + 48;
			sub_42BE30(v118, (char*)getMemAt(0x587000, 71488), *(const char**)(*(uint32_t*)(v4 + 608) + 4 * v114));
			*getMemU8Ptr(0x587000, 71499) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BDC0(v118, "IPL?", *(uint32_t*)(*(uint32_t*)(v4 + 612) + 4 * *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71515) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BDC0(v118, "CNL?", *(uint32_t*)(*(uint32_t*)(v4 + 616) + 4 * *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71507) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BCE0(v118, "CLL?", *(uint8_t*)(*getMemU32Ptr(0x5D4594, 741660) + *(uint32_t*)(v4 + 620)));
			*getMemU8Ptr(0x587000, 71523) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BCE0(v118, "CMP?", *(uint8_t*)(*(uint32_t*)(v4 + 624) + *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71531) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BDC0(v118, "DUR?", *(uint32_t*)(*(uint32_t*)(v4 + 628) + 4 * *getMemU32Ptr(0x5D4594, 741660)));
			*getMemU8Ptr(0x587000, 71539) = getMemByte(0x5D4594, 741660) + 48;
			sub_42BCE0(v118, "PAR?", *(uint8_t*)(*(uint32_t*)(v4 + 632) + *getMemU32Ptr(0x5D4594, 741660)));
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
uint16_t* sub_42B810(short* a1, unsigned int* a2) {
	short* v2;       // esi
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
	short v21;       // di
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
	uint16_t* v57;   // esi
	char v59[12];    // [esp+8h] [ebp-Ch]
	char v60;        // [esp+18h] [ebp+4h]
	char v61;        // [esp+18h] [ebp+4h]

	v2 = a1;
	v3 = *((uint32_t*)a1 + 1);
	*(uint16_t*)v59 = 0;
	*(uint16_t*)&v59[2] = 0;
	*(uint32_t*)&v59[4] = 0;
	v4 = operator_new(0x10u);
	if (v4) {
		v5 = sub_42C8B0((int)v4, "IDNO", v3);
	} else {
		v5 = 0;
	}
	sub_42C360(v59, v5);
	v6 = *((uint32_t*)a1 + 2);
	v7 = operator_new(0x10u);
	if (v7) {
		v8 = sub_42C8B0((int)v7, "GSKU", v6);
	} else {
		v8 = 0;
	}
	sub_42C360(v59, v8);
	v9 = *((uint32_t*)a1 + 3);
	v10 = operator_new(0x10u);
	if (v10) {
		v11 = sub_42C8B0((int)v10, "GSTY", v9);
	} else {
		v11 = 0;
	}
	sub_42C360(v59, v11);
	v12 = operator_new(0x10u);
	if (v12) {
		v13 = sub_42C8E0((int)v12, "SCEN", (const char*)a1 + 24);
	} else {
		v13 = 0;
	}
	sub_42C360(v59, v13);
	v14 = operator_new(0x10u);
	if (v14) {
		v15 = sub_42C8E0((int)v14, "GNAM", (const char*)a1 + 280);
	} else {
		v15 = 0;
	}
	sub_42C360(v59, v15);
	v16 = *((uint32_t*)a1 + 5);
	v17 = operator_new(0x10u);
	if (v17) {
		v18 = sub_42C8B0((int)v17, "DURA", v16);
	} else {
		v18 = 0;
	}
	sub_42C360(v59, v18);
	v60 = *((uint8_t*)a1 + 16);
	v19 = operator_new(0x10u);
	if (v19) {
		v20 = sub_42C7F0((int)v19, "TRNY", v60);
	} else {
		v20 = 0;
	}
	sub_42C360(v59, v20);
	v21 = *v2;
	v22 = operator_new(0x10u);
	if (v22) {
		v23 = sub_42C820((int)v22, (char*)getMemAt(0x587000, 72000), v21);
	} else {
		v23 = 0;
	}
	sub_42C360(v59, v23);
	v24 = getMemByte(0x5D4594, 741672);
	v25 = operator_new(0x10u);
	if (v25) {
		v26 = sub_42C8B0((int)v25, "SEQU", v24);
	} else {
		v26 = 0;
	}
	sub_42C360(v59, v26);
	v27 = 0;
	for (*getMemU32Ptr(0x5D4594, 741664) = 0; v27 < *v2; *getMemU32Ptr(0x5D4594, 741664) = v27) {
		*getMemU8Ptr(0x587000, 71547) = v27 + 48;
		v28 = *(const char**)(*((uint32_t*)v2 + 134) + 4 * v27);
		v29 = operator_new(0x10u);
		if (v29) {
			v30 = sub_42C8E0((int)v29, "LGLS", v28);
		} else {
			v30 = 0;
		}
		sub_42C360(v59, v30);
		*getMemU8Ptr(0x587000, 71555) = getMemByte(0x5D4594, 741664) + 48;
		v31 = *(uint32_t*)(*((uint32_t*)v2 + 135) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v32 = operator_new(0x10u);
		if (v32) {
			v33 = sub_42C8B0((int)v32, "IPLS", v31);
		} else {
			v33 = 0;
		}
		sub_42C360(v59, v33);
		*getMemU8Ptr(0x587000, 71563) = getMemByte(0x5D4594, 741664) + 48;
		v61 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 741664) + *((uint32_t*)v2 + 144));
		v34 = operator_new(0x10u);
		if (v34) {
			v35 = sub_42C7F0((int)v34, "CLLS", v61);
		} else {
			v35 = 0;
		}
		sub_42C360(v59, v35);
		*getMemU8Ptr(0x587000, 71571) = getMemByte(0x5D4594, 741664) + 48;
		v36 = *(uint32_t*)(*((uint32_t*)v2 + 136) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v37 = operator_new(0x10u);
		if (v37) {
			v38 = sub_42C8B0((int)v37, "CSTS", v36);
		} else {
			v38 = 0;
		}
		sub_42C360(v59, v38);
		*getMemU8Ptr(0x587000, 71579) = getMemByte(0x5D4594, 741664) + 48;
		v39 = *(uint32_t*)(*((uint32_t*)v2 + 137) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v40 = operator_new(0x10u);
		if (v40) {
			v41 = sub_42C8B0((int)v40, "HSTS", v39);
		} else {
			v41 = 0;
		}
		sub_42C360(v59, v41);
		*getMemU8Ptr(0x587000, 71587) = getMemByte(0x5D4594, 741664) + 48;
		v42 = *(uint32_t*)(*((uint32_t*)v2 + 138) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v43 = operator_new(0x10u);
		if (v43) {
			v44 = sub_42C8B0((int)v43, "MKLS", v42);
		} else {
			v44 = 0;
		}
		sub_42C360(v59, v44);
		*getMemU8Ptr(0x587000, 71595) = getMemByte(0x5D4594, 741664) + 48;
		v45 = *(uint32_t*)(*((uint32_t*)v2 + 139) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v46 = operator_new(0x10u);
		if (v46) {
			v47 = sub_42C8B0((int)v46, "ANKS", v45);
		} else {
			v47 = 0;
		}
		sub_42C360(v59, v47);
		*getMemU8Ptr(0x587000, 71603) = getMemByte(0x5D4594, 741664) + 48;
		v48 = *(uint32_t*)(*((uint32_t*)v2 + 140) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v49 = operator_new(0x10u);
		if (v49) {
			v50 = sub_42C8B0((int)v49, "GNDS", v48);
		} else {
			v50 = 0;
		}
		sub_42C360(v59, v50);
		*getMemU8Ptr(0x587000, 71611) = getMemByte(0x5D4594, 741664) + 48;
		v51 = *(uint32_t*)(*((uint32_t*)v2 + 141) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v52 = operator_new(0x10u);
		if (v52) {
			v53 = sub_42C8B0((int)v52, "SECS", v51);
		} else {
			v53 = 0;
		}
		sub_42C360(v59, v53);
		*getMemU8Ptr(0x587000, 71619) = getMemByte(0x5D4594, 741664) + 48;
		v54 = *(uint32_t*)(*((uint32_t*)v2 + 142) + 4 * *getMemU32Ptr(0x5D4594, 741664));
		v55 = operator_new(0x10u);
		if (v55) {
			v56 = sub_42C8B0((int)v55, "BPTS", v54);
		} else {
			v56 = 0;
		}
		sub_42C360(v59, v56);
		*getMemU8Ptr(0x587000, 71627) = getMemByte(0x5D4594, 741664) + 48;
		sub_42BDC0(v59, "SCRS", *(uint32_t*)(*((uint32_t*)v2 + 143) + 4 * *getMemU32Ptr(0x5D4594, 741664)));
		v27 = *getMemU32Ptr(0x5D4594, 741664) + 1;
	}
	v57 = sub_42C480(v59, a2);
	++*getMemU32Ptr(0x5D4594, 741672);
	sub_42C330(v59);
	return v57;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042BCE0) --------------------------------------------------------
int sub_42BCE0(uint32_t* this, char* a2, char a3) {
	uint32_t* v3; // esi
	void* v4;     // eax
	int v5;       // eax

	v3 = this;
	v4 = operator_new(0x10u);
	if (v4) {
		v5 = sub_42C7F0((int)v4, a2, a3);
	} else {
		v5 = 0;
	}
	return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042BD50) --------------------------------------------------------
int sub_42BD50(uint32_t* this, char* a2, char a3) {
	uint32_t* v3; // esi
	void* v4;     // eax
	int v5;       // eax

	v3 = this;
	v4 = operator_new(0x10u);
	if (v4) {
		v5 = sub_42C820((int)v4, a2, a3);
	} else {
		v5 = 0;
	}
	return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042BDC0) --------------------------------------------------------
int sub_42BDC0(uint32_t* this, char* a2, char a3) {
	uint32_t* v3; // esi
	void* v4;     // eax
	int v5;       // eax

	v3 = this;
	v4 = operator_new(0x10u);
	if (v4) {
		v5 = sub_42C8B0((int)v4, a2, a3);
	} else {
		v5 = 0;
	}
	return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042BE30) --------------------------------------------------------
int sub_42BE30(uint32_t* this, char* a2, const char* a3) {
	uint32_t* v3; // esi
	void* v4;     // eax
	int v5;       // eax

	v3 = this;
	v4 = operator_new(0x10u);
	if (v4) {
		v5 = sub_42C8E0((int)v4, a2, a3);
	} else {
		v5 = 0;
	}
	return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042BEA0) --------------------------------------------------------
int sub_42BEA0(uint32_t* this, char* a2, const void* a3, unsigned short a4) {
	uint32_t* v4; // esi
	void* v5;     // eax
	int v6;       // eax

	v4 = this;
	v5 = operator_new(0x10u);
	if (v5) {
		v6 = sub_42C910((int)v5, a2, a3, a4);
	} else {
		v6 = 0;
	}
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
	int result;         // eax
	int i;              // esi
	unsigned short v2;  // ax
	bool v3;            // zf
	uint16_t* v4;       // eax
	int j;              // ecx
	unsigned short v6;  // ax
	uint16_t* v7;       // eax
	int k;              // esi
	uint16_t* v9;       // eax
	unsigned short v11; // cx
	uint16_t* v12;      // ecx
	int m;              // esi
	uint16_t* v14;      // eax
	int v15;            // [esp+4h] [ebp-4h]

	result = nox_common_gameFlags_check_40A5C0(2097153);
	if (result) {
		sub_42BFB0();
		v15 = 1;
		for (i = nox_server_getFirstObject_4DA790(); i; i = nox_server_getNextObject_4DA7A0(i)) {
			v2 = *(uint16_t*)(i + 4);
			v3 = *(uint16_t*)(dword_5d4594_741676 + 2 * v2) == 0;
			v4 = (uint16_t*)(dword_5d4594_741676 + 2 * v2);
			if (v3) {
				*v4 = v15;
				++*getMemU16Ptr(0x5D4594, 741684);
				++v15;
			}
			for (j = *(uint32_t*)(i + 504); j; j = *(uint32_t*)(j + 496)) {
				v6 = *(uint16_t*)(j + 4);
				v3 = *(uint16_t*)(dword_5d4594_741676 + 2 * v6) == 0;
				v7 = (uint16_t*)(dword_5d4594_741676 + 2 * v6);
				if (v3) {
					*v7 = v15;
					++*getMemU16Ptr(0x5D4594, 741684);
					++v15;
				}
			}
			if (*(uint32_t*)(i + 8) & 0x20000) {
				sub_42C210(i, &v15, getMemAt(0x5D4594, 741684));
			}
		}
		for (k = nox_server_getFirstObjectUninited_4DA870(); k; k = nox_server_getNextObjectUninited_4DA880(k)) {
			v9 = (uint16_t*)(dword_5d4594_741676 + 2 * *(unsigned short*)(k + 4));
			if (!*v9) {
				*v9 = v15;
				++*getMemU16Ptr(0x5D4594, 741684);
				++v15;
			}
			if (*(uint32_t*)(k + 8) & 0x20000) {
				sub_42C210(k, &v15, getMemAt(0x5D4594, 741684));
			}
		}
		for (nox_object_t* obj = nox_xxx_getFirstUpdatable2Object_4DA840(); obj;
			 obj = nox_xxx_getNextUpdatable2Object_4DA850(obj)) {
			v11 = *(uint16_t*)&obj->typ_ind;
			v3 = *(uint16_t*)(dword_5d4594_741676 + 2 * v11) == 0;
			v12 = (uint16_t*)(dword_5d4594_741676 + 2 * v11);
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
							if (!sub_4E3AD0(*(uint32_t*)(m + 108)) && sub_4E3B80(*(uint32_t*)(m + 108))) {
								v14 = (uint16_t*)(dword_5d4594_741676 + 2 * *(uint32_t*)(m + 108));
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
int sub_42C210(int a1, uint16_t* a2, uint16_t* a3) {
	int result;        // eax
	int v4;            // edi
	int v5;            // ebx
	uint16_t* v6;      // eax
	int i;             // ecx
	unsigned short v8; // ax
	bool v9;           // zf
	uint16_t* v10;     // eax
	int v11;           // [esp+14h] [ebp+4h]

	result = *(uint32_t*)(a1 + 748);
	v11 = 3;
	do {
		v4 = result;
		v5 = 4;
		do {
			if (*(uint32_t*)v4) {
				v6 = (uint16_t*)(dword_5d4594_741676 + 2 * *(unsigned short*)(*(uint32_t*)v4 + 4));
				if (!*v6) {
					*v6 = (*a2)++;
					++*a3;
				}
				for (i = *(uint32_t*)(*(uint32_t*)v4 + 504); i; i = *(uint32_t*)(i + 496)) {
					v8 = *(uint16_t*)(i + 4);
					v9 = *(uint16_t*)(dword_5d4594_741676 + 2 * v8) == 0;
					v10 = (uint16_t*)(dword_5d4594_741676 + 2 * v8);
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
short nox_xxx_objectTOCgetTT_42C2B0(short a1) {
	uint16_t* v1;    // ecx
	unsigned int v2; // eax

	v1 = *(uint16_t**)&dword_5d4594_741676;
	if (dword_5d4594_741676 && (v2 = 0, dword_5d4594_741680)) {
		while (*v1 != a1) {
			++v2;
			++v1;
			if (v2 >= *(int*)&dword_5d4594_741680) {
				goto LABEL_5;
			}
		}
	} else {
	LABEL_5:
		LOWORD(v2) = 0;
	}
	return v2;
}

//----- (0042C2E0) --------------------------------------------------------
short sub_42C2E0(int a1) {
	short result; // ax

	if (dword_5d4594_741676) {
		result = *(uint16_t*)(dword_5d4594_741676 + 2 * a1);
	} else {
		result = 0;
	}
	return result;
}

//----- (0042C300) --------------------------------------------------------
short sub_42C300() { return *getMemU16Ptr(0x5D4594, 741684); }

//----- (0042C310) --------------------------------------------------------
void* sub_42C310(unsigned short a1, short a2) {
	void* result; // eax

	result = *(void**)&dword_5d4594_741676;
	if (dword_5d4594_741676) {
		*(uint16_t*)(dword_5d4594_741676 + 2 * a1) = a2;
	}
	return result;
}

//----- (0042C330) --------------------------------------------------------
void sub_42C330(uint32_t* this) {
	uint32_t* v1; // esi
	uint32_t* v2; // edi

	v1 = (uint32_t*)this[1];
	if (v1) {
		do {
			v2 = (uint32_t*)v1[3];
			if (v1) {
				sub_42CC50(v1);
				operator_delete(v1);
			}
			v1 = v2;
		} while (v2);
	}
}
// 42CC50: using guessed type int sub_42CC50(uint32_t);

//----- (0042C360) --------------------------------------------------------
int sub_42C360(uint32_t* this, int a2) {
	int result; // eax

	result = a2;
	*(uint32_t*)(a2 + 12) = this[1];
	this[1] = a2;
	return result;
}

//----- (0042C480) --------------------------------------------------------
uint16_t* sub_42C480(uint32_t* this, unsigned int* a2) {
	uint32_t* v2;    // ebx
	int i;           // eax
	unsigned int v4; // ecx
	uint16_t* v5;    // edi
	int v6;          // ebx
	uint32_t* v7;    // ebp
	char* v8;        // ebp
	int v9;          // ebp

	v2 = this;
	*a2 = 4;
	for (i = this[1]; i; i = *(uint32_t*)(i + 12)) {
		v4 = *a2 + 8;
		*a2 = v4;
		*a2 = *(unsigned short*)(i + 6) + v4 + (-(((unsigned char)*(uint16_t*)(i + 6) + (uint8_t)v4) & 3) & 3);
	}
	v5 = (uint16_t*)operator_new(*a2);
	*v5 = htons(*(uint16_t*)a2);
	v5[1] = htons(*((uint16_t*)v2 + 1));
	v6 = v2[1];
	v7 = v5 + 2;
	if (!v6) {
		return v5;
	}
	do {
		sub_42CC70(v6);
		*v7 = *(uint32_t*)v6;
		v7[1] = *(uint32_t*)(v6 + 4);
		v8 = (char*)(v7 + 2);
		memcpy(v8, *(const void**)(v6 + 8), ntohs(*(uint16_t*)(v6 + 6)));
		v9 = (int)&v8[ntohs(*(uint16_t*)(v6 + 6))];
		v7 = (uint32_t*)((-(ntohs(*(uint16_t*)(v6 + 6)) & 3) & 3) + v9);
		sub_42CCE0((uint16_t*)v6);
		v6 = *(uint32_t*)(v6 + 12);
	} while (v6);
	return v5;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042C770) --------------------------------------------------------
int sub_42C770(void** this) {
	void** v1;  // ebx
	int result; // eax

	v1 = this;
	operator_delete(this[2]);
	result = 0;
	strcpy((char*)v1, (const char*)getMemAt(0x5D4594, 741688));
	*((uint16_t*)v1 + 2) = 0;
	*((uint16_t*)v1 + 3) = 0;
	v1[2] = 0;
	v1[3] = 0;
	return result;
}

//----- (0042C7F0) --------------------------------------------------------
int sub_42C7F0(int this, char* a2, char a3) {
	int v3; // esi

	v3 = this;
	*(uint32_t*)(this + 8) = 0;
	sub_42C9A0((void**)this, a2, a3);
	return v3;
}

//----- (0042C820) --------------------------------------------------------
int sub_42C820(int this, char* a2, char a3) {
	int v3; // esi

	v3 = this;
	*(uint32_t*)(this + 8) = 0;
	sub_42CA00((void**)this, a2, a3);
	return v3;
}

//----- (0042C8B0) --------------------------------------------------------
int sub_42C8B0(int this, char* a2, char a3) {
	int v3; // esi

	v3 = this;
	*(uint32_t*)(this + 8) = 0;
	sub_42CB20((void**)this, a2, a3);
	return v3;
}

//----- (0042C8E0) --------------------------------------------------------
int sub_42C8E0(int this, char* a2, const char* a3) {
	int v3; // esi

	v3 = this;
	*(uint32_t*)(this + 8) = 0;
	sub_42CB80((void**)this, a2, a3);
	return v3;
}

//----- (0042C910) --------------------------------------------------------
int sub_42C910(int this, char* a2, const void* a3, unsigned short a4) {
	int v4; // esi

	v4 = this;
	*(uint32_t*)(this + 8) = 0;
	sub_42CBF0((void**)this, a2, a3, a4);
	return v4;
}

//----- (0042C9A0) --------------------------------------------------------
char* sub_42C9A0(void** this, char* a2, char a3) {
	void** v3;       // ebx
	char* result;    // eax
	unsigned int v5; // edx

	v3 = this;
	sub_42C770(this);
	strncpy((char*)v3, a2, 4u);
	*((uint16_t*)v3 + 2) = 2;
	*((uint16_t*)v3 + 3) = 1;
	result = (char*)operator_new(1u);
	v5 = *((unsigned short*)v3 + 3);
	v3[2] = result;
	memcpy(result, &a3, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042CA00) --------------------------------------------------------
char* sub_42CA00(void** this, char* a2, char a3) {
	void** v3;       // ebx
	char* result;    // eax
	unsigned int v5; // edx

	v3 = this;
	sub_42C770(this);
	strncpy((char*)v3, a2, 4u);
	*((uint16_t*)v3 + 2) = 3;
	*((uint16_t*)v3 + 3) = 2;
	result = (char*)operator_new(2u);
	v5 = *((unsigned short*)v3 + 3);
	v3[2] = result;
	int a3i = a3;
	memcpy(result, &a3i, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042CB20) --------------------------------------------------------
char* sub_42CB20(void** this, char* a2, char a3) {
	void** v3;       // ebx
	char* result;    // eax
	unsigned int v5; // edx

	v3 = this;
	sub_42C770(this);
	strncpy((char*)v3, a2, 4u);
	*((uint16_t*)v3 + 2) = 6;
	*((uint16_t*)v3 + 3) = 4;
	result = (char*)operator_new(4u);
	v5 = *((unsigned short*)v3 + 3);
	v3[2] = result;
	int a3i = a3;
	memcpy(result, &a3i, v5);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042CB80) --------------------------------------------------------
char* sub_42CB80(void** this, char* a2, const char* a3) {
	void** v3;         // ebx
	unsigned int v4;   // kr08_4
	char* result;      // eax
	unsigned short v6; // cx

	v3 = this;
	sub_42C770(this);
	strncpy((char*)v3, a2, 4u);
	*((uint16_t*)v3 + 2) = 7;
	v4 = strlen(a3) + 1;
	*((uint16_t*)v3 + 3) = v4;
	result = (char*)operator_new((unsigned short)v4);
	v6 = *((uint16_t*)v3 + 3);
	v3[2] = result;
	memcpy(result, a3, v6);
	v3[3] = 0;
	return result;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042CBF0) --------------------------------------------------------
void* sub_42CBF0(void** this, char* a2, const void* a3, unsigned short a4) {
	void** v4;       // ebx
	void* result;    // eax
	unsigned int v6; // edx

	v4 = this;
	sub_42C770(this);
	strncpy((char*)v4, a2, 4u);
	*((uint16_t*)v4 + 2) = 20;
	*((uint16_t*)v4 + 3) = a4;
	result = operator_new(a4);
	v6 = *((unsigned short*)v4 + 3);
	v4[2] = result;
	memcpy(result, a3, v6);
	v4[3] = 0;
	return result;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0042CC70) --------------------------------------------------------
uint16_t sub_42CC70(int this) {
	int v1;          // esi
	uint16_t v2;     // ax
	uint16_t v3;     // cx
	uint16_t result; // ax

	v1 = this;
	switch (*(unsigned short*)(this + 4)) {
	case 3u:
	case 4u:
		**(uint16_t**)(this + 8) = htons(**(uint16_t**)(this + 8));
		break;
	case 5u:
	case 6u:
		**(uint32_t**)(this + 8) = htonl(**(uint32_t**)(this + 8));
		break;
	default:
		break;
	}
	v2 = htons(*(uint16_t*)(v1 + 4));
	v3 = *(uint16_t*)(v1 + 6);
	*(uint16_t*)(v1 + 4) = v2;
	result = htons(v3);
	*(uint16_t*)(v1 + 6) = result;
	return result;
}

//----- (0042CCE0) --------------------------------------------------------
short sub_42CCE0(uint16_t* this) {
	uint16_t* v1; // esi
	uint16_t v2;  // ax
	uint16_t v3;  // cx
	u_long v4;    // eax

	v1 = this;
	v2 = ntohs(this[2]);
	v3 = v1[3];
	v1[2] = v2;
	v1[3] = ntohs(v3);
	LOWORD(v4) = v1[2] - 3;
	switch (v1[2]) {
	case 3u:
	case 4u:
		LOWORD(v4) = ntohs(**((uint16_t**)v1 + 2));
		**((uint16_t**)v1 + 2) = v4;
		break;
	case 5u:
	case 6u:
		v4 = ntohl(**((uint32_t**)v1 + 2));
		**((uint32_t**)v1 + 2) = v4;
		break;
	default:
		return v4;
	}
	return v4;
}

//----- (0042E7B0) --------------------------------------------------------
void nox_xxx_clientTalk_42E7B0(nox_drawable* a1p) {
	int a1 = a1p;
	int v1;   // esi
	short v2; // ax

	v1 = a1;
	if (a1 && (!*getMemU32Ptr(0x8531A0, 2576) || !(*(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 3)) &&
		sub_478030() != 1 && nox_gui_xxx_check_446360() != 1) {
		v2 = *(uint16_t*)(v1 + 128);
		LOWORD(a1) = 464;
		HIWORD(a1) = v2;
		nox_netlist_addToMsgListCli_40EBC0(31, 0, &a1, 4);
	}
}

//----- (0042E810) --------------------------------------------------------
void nox_xxx_clientCollideOrUse_42E810(nox_drawable* a1p) {
	int a1 = a1p;
	int v1; // [esp-4h] [ebp-4h]

	if (a1 && (!*getMemU32Ptr(0x8531A0, 2576) || !(*(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 3))) {
		v1 = a1;
		LOBYTE(a1) = 123;
		*(uint16_t*)((char*)&a1 + 1) = nox_xxx_netGetUnitCodeCli_578B00(v1);
		nox_netlist_addToMsgListCli_40EBC0(31, 0, &a1, 3);
	}
}

//----- (0042E850) --------------------------------------------------------
void nox_xxx_clientTrade_42E850(nox_drawable* a1p) {
	int a1 = a1p;
	int v1; // esi

	v1 = a1;
	if (a1 && (!*getMemU32Ptr(0x8531A0, 2576) || !(*(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 3)) &&
		sub_47A260() != 1 && nox_gui_xxx_check_446360() != 1) {
		LOWORD(a1) = 5577;
		HIWORD(a1) = nox_xxx_netGetUnitCodeCli_578B00(v1);
		nox_netlist_addToMsgListCli_40EBC0(31, 0, &a1, 4);
	}
}

//----- (0042EB90) --------------------------------------------------------
int sub_42EB90(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 754052) = a1;
	return result;
}

//----- (0042EBA0) --------------------------------------------------------
int sub_42EBA0() { return *getMemU32Ptr(0x5D4594, 754052); }

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

//----- (0042FFF0) --------------------------------------------------------
int sub_42FFF0(FILE* a1) {
	signed int v1; // edx
	int result;    // eax
	char v3[12];   // [esp+8h] [ebp-2Ch]
	char v4[32];   // [esp+14h] [ebp-20h]

	strcpy(v3, "LOOKUPTABLE");
	v1 = nox_binfile_fread_raw_40ADD0(v4, 1u, strlen(v3), a1);
	result = 0;
	if (v1 == strlen(v3)) {
		v4[strlen(v3)] = 0;
		if (!strcmp(v4, v3)) {
			result = nox_binfile_fread_raw_40ADD0((char*)getMemAt(0x5D4594, 754340), 1u, 0x8000u, a1) == 0x8000;
		} else {
			result = 0;
		}
	}
	return result;
}
// 42FFF0: using guessed type char var_20[32];

//----- (00430880) --------------------------------------------------------
int sub_430880(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 805808) = a1;
	return result;
}

//----- (00430890) --------------------------------------------------------
int nox_xxx_get_430890() { return *getMemU32Ptr(0x5D4594, 805808); }

//----- (00430AA0) --------------------------------------------------------
int sub_430AA0(int a1) {
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
void nox_client_setMousePos_430B10(int x, int y) { nox_client_changeMousePos_430A00(x, y, true); }

//----- (00430B50) --------------------------------------------------------
int sub_430B50(int a1, int a2, int a3, int a4) {
	int result; // eax

	dword_5d4594_3807140 = a1;
	result = a4;
	dword_5d4594_3807136 = a2;
	dword_5d4594_3807116 = a3;
	dword_5d4594_3807152 = a4;
	return result;
}

//----- (00430DB0) --------------------------------------------------------
int nox_xxx_tileInitBuf_430DB0(int a1, int a2) {
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
	v3 = (char*)calloc(1, v2);
	dword_5d4594_3798796 = v3;
	if (!v3) {
		return 0;
	}
	dword_5d4594_3798844 = &v3[v2];
	return 1;
}

//----- (00430EC0) --------------------------------------------------------
int nox_video_freeFloorBuffer_430EC0() {
	if (dword_5d4594_3798796) {
		free(*(void**)&dword_5d4594_3798796);
		dword_5d4594_3798796 = 0;
	}
	sub_444C50();
	return 1;
}

//----- (00430EF0) --------------------------------------------------------
void nox_xxx_freeFloorBuffer_430EF0() { nox_video_freeFloorBuffer_430EC0(); }

//----- (004310B0) --------------------------------------------------------
int nox_audio_initall(int a3) {
	if (!nox_enable_audio) {
		return 1;
	}
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
	sub_4864A0(*(uint32_t**)&dword_587000_93164);
	sub_4864A0(*(uint32_t**)&dword_587000_122852);
	sub_4864A0(*(uint32_t**)&dword_587000_127004);
	nox_xxx_WorkerHurt_44D810();
	sub_43D8E0();
	sub_451850(*(int*)&dword_5d4594_805984, *(int*)&dword_5d4594_805980);
	v1 = sub_4866A0(2);
	if (!v1) {
		sub_43DC00();
	}
	sub_486320(*(uint32_t**)&dword_587000_93164, v1);
	v2 = sub_4866A0(1);
	if (!v2) {
		sub_44D960();
	}
	sub_486320(*(uint32_t**)&dword_587000_122852, v2);
	v3 = sub_4866A0(0);
	if (!v3) {
		sub_453050();
	}
	sub_486320(*(uint32_t**)&dword_587000_127004, v3);
	return 1;
}

//----- (004311F0) --------------------------------------------------------
int sub_4311F0() {
	uint32_t* v0; // eax
	int v2[7];    // [esp+0h] [ebp-1Ch]

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
// 487CF0: using guessed type void  nullsub_10(uint32_t);

//----- (00431270) --------------------------------------------------------
void sub_431270() {
	if (dword_5d4594_805984) {
		sub_487680(*(void**)&dword_5d4594_805984);
		dword_5d4594_805984 = 0;
	}
}

//----- (00431290) --------------------------------------------------------
int* sub_431290() {
	int* result; // eax

	result = *(int**)&dword_5d4594_805984;
	if (dword_5d4594_805984) {
		result = sub_487970(*(int*)&dword_5d4594_805984, -1);
	}
	return result;
}

//----- (00431370) --------------------------------------------------------
int sub_431370() { return sub_488B60() != 0; }

//----- (00431380) --------------------------------------------------------
void sub_431380() {
	sub_488BA0();
	sub_4896E0();
}

//----- (00431540) --------------------------------------------------------
nox_screenParticle* nox_client_newScreenParticle_431540(int a1, int a2, int a3, int a4, int a5, int a6, char a7,
														char a8, char a9, char a10) {
	int v10; // edi
	int v11; // ebx

	if (!nox_alloc_screenParticles_806044) {
		return 0;
	}
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
		if (!p) {
			return 0;
		}
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
	*(uint8_t*)(&p->field_32) = a10;
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
	if (nox_screenParticles_head) {
		nox_screenParticles_head->field_48 = p;
	} else {
		dword_5d4594_806052 = p;
	}
	nox_screenParticles_head = p;
}

//----- (004316C0) --------------------------------------------------------
void sub_4316C0(nox_screenParticle* p) {
	if (p == dword_5d4594_806052) {
		dword_5d4594_806052 = p->field_48;
	}

	nox_screenParticle* v2 = p->field_44;
	if (v2) {
		v2->field_48 = p->field_48;
	}

	nox_screenParticle* v3 = p->field_48;
	if (v3) {
		v3->field_44 = p->field_44;
	} else {
		nox_screenParticles_head = p->field_44;
	}
}

//----- (00431700) --------------------------------------------------------
void sub_431700(uint64_t* a1) {
	sub_4316C0((int)a1);
	nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_screenParticles_806044, a1);
}

//----- (00431720) --------------------------------------------------------
void nox_client_screenParticlesDraw_431720(nox_draw_viewport_t* rdr) {
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

//----- (00431790) --------------------------------------------------------
char* nox_xxx_copyServerIPAndPort_431790(char* a1) {
	char* result; // eax

	result = a1;
	if (a1) {
		result = strncpy((char*)getMemAt(0x5D4594, 806060), a1, 0x17u);
	}
	return result;
}
// 4335F8: variable 'v12' is possibly undefined

//----- (00434610) --------------------------------------------------------
int sub_434610(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_810636 = a1;
	return result;
}

//----- (00434620) --------------------------------------------------------
int sub_434620(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_810632 = a1;
	return result;
}

//----- (00434F00) --------------------------------------------------------
int sub_434F00() {
	return 1;
}

//----- (00435040) --------------------------------------------------------
void sub_435040() {
	pixel8888 buf[256]; // [esp+4h] [ebp-400h]
	unsigned char* data;

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

//----- (00435120) --------------------------------------------------------
void sub_435120(uint8_t* a1, char* a2) {
	char* result; // eax
	uint8_t* v3;  // ecx
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
void sub_435150(uint8_t* a1, char* a2) {
	char* v2;        // ecx
	uint8_t* result; // eax
	int v4;          // esi
	char v5;         // dl
	uint8_t* v6;     // eax

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

//----- (00435570) --------------------------------------------------------
long long nox_xxx_initTime_435570() {
	long long result; // rax

	result = nox_platform_get_ticks();
	*getMemU64Ptr(0x5D4594, 811908) = result;
	return result;
}

//----- (00435590) --------------------------------------------------------
int sub_435590() { return *getMemU32Ptr(0x5D4594, 811916); }

//----- (00435690) --------------------------------------------------------
uint32_t* sub_435690(uint32_t* a1) {
	uint32_t* result; // eax

	result = a1;
	*a1 = *getMemU32Ptr(0x5D4594, 811364);
	a1[1] = *getMemU32Ptr(0x5D4594, 811368);
	return result;
}

//----- (004356C0) --------------------------------------------------------
bool nox_xxx_spriteCheckFlag31_4356C0(nox_drawable* dr, char a2) {
	int a1 = dr;
	int result; // eax

	result = a1;
	if (a1) {
		result = ((1 << a2) & *(uint32_t*)(a1 + 124)) != 0;
	}
	return result;
}

//----- (004356E0) --------------------------------------------------------
void nox_xxx_spriteLoadError_4356E0() { *getMemU32Ptr(0x587000, 85720) = 0; }

//----- (00435700) --------------------------------------------------------
wchar_t* sub_435700(wchar_t* a1, int a2) {
	wchar_t* result; // eax

	result = nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 811376), a1);
	*getMemU32Ptr(0x5D4594, 811060) = a2;
	return result;
}

//----- (00435740) --------------------------------------------------------
uint32_t sub_435740() {
	uint32_t result; // eax

	result = nox_platform_get_ticks();
	*getMemU32Ptr(0x5D4594, 811924) = result;
	return result;
}

//----- (00435750) --------------------------------------------------------
uint32_t sub_435750() {
	uint32_t result; // eax

	result = nox_platform_get_ticks() - *getMemU32Ptr(0x5D4594, 811924);
	*getMemU32Ptr(0x5D4594, 811928) = result;
	return result;
}

//----- (00435770) --------------------------------------------------------
uint32_t nox_xxx_time_startProfile_435770() {
	uint32_t result; // eax

	result = nox_platform_get_ticks();
	*getMemU32Ptr(0x5D4594, 811932) = result;
	return result;
}

//----- (00435780) --------------------------------------------------------
uint32_t nox_xxx_time_endProfile_435780() {
	uint32_t result; // eax

	result = nox_platform_get_ticks() - *getMemU32Ptr(0x5D4594, 811932);
	*getMemU32Ptr(0x5D4594, 811936) = result;
	return result;
}

//----- (004357A0) --------------------------------------------------------
int nox_xxx_cliToggleObsWindow_4357A0() {
	int result; // eax

	if (*getMemU32Ptr(0x8531A0, 2576) && *(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 1) {
		result = nox_xxx_showObserverWindow_48CA70(0);
	} else {
		result = nox_xxx_showObserverWindow_48CA70(1);
	}
	return result;
}

//----- (00435F60) --------------------------------------------------------
int sub_435F60() {
	int result; // eax

	result = 1 - dword_5d4594_811904;
	dword_5d4594_811904 = 1 - dword_5d4594_811904;
	return result;
}

//----- (00436550) --------------------------------------------------------
int sub_436550() {
	int v0; // eax

	if (sub_459DA0() || nox_gui_xxx_check_446360() || sub_49CB40() || sub_49C810() || sub_446950() || sub_4706A0() ||
		nox_gui_console_flagXxx_451410()) {
		v0 = nox_frame_xxx_2598000;
	} else {
		v0 = nox_frame_xxx_2598000;
		if (nox_frame_xxx_2598000 != 2) {
			return nox_frame_xxx_2598000 - *getMemU32Ptr(0x5D4594, 811920) == 1;
		}
	}
	*getMemU32Ptr(0x5D4594, 811920) = v0;
	return 1;
}

//----- (00437100) --------------------------------------------------------
int sub_437100() {
	int result; // eax

	result = nox_client_renderGUI_80828;
	if (*getMemU32Ptr(0x5D4594, 811064) != nox_client_renderGUI_80828 &&
		!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		*getMemU32Ptr(0x5D4594, 811064) = nox_client_renderGUI_80828;
		sub_4721A0(*(int*)&nox_client_renderGUI_80828);
		sub_460EA0(*(int*)&nox_client_renderGUI_80828);
		nox_window_set_visible_unk5(*(int*)&nox_client_renderGUI_80828);
		sub_45D500(*(int*)&nox_client_renderGUI_80828);
		sub_455A00(*(int*)&nox_client_renderGUI_80828);
		sub_455F10(*(int*)&nox_client_renderGUI_80828);
		sub_4706C0(*(int*)&nox_client_renderGUI_80828);
		result = nox_client_renderGUI_80828;
		if (!nox_client_renderGUI_80828) {
			result = sub_478000();
		}
	}
	return result;
}

//----- (004372B0) --------------------------------------------------------
int nox_xxx_playerAnimCheck_4372B0() {
	int v0;     // eax
	int result; // eax

	result = 1;
	if (*getMemU32Ptr(0x852978, 8)) {
		v0 = *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 276);
		if (v0 != 1 && v0 != 2 && v0 != 51) {
			result = 0;
		}
	}
	return result;
}

//----- (004372E0) --------------------------------------------------------
int nox_xxx_clientIsObserver_4372E0() {
	int result; // eax

	if (*getMemU32Ptr(0x8531A0, 2576) && *(uint32_t*)(*getMemU32Ptr(0x8531A0, 2576) + 2092) == 1) {
		result = (*(uint32_t*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 3) != 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (00437320) --------------------------------------------------------
int sub_437320(int a1) {
	int v1;            // eax
	unsigned char* v2; // ecx
	int v3;            // ecx
	int v4;            // eax
	int result;        // eax

	v1 = 0;
	v2 = getMemAt(0x587000, 87484);
	do {
		if (*(uint32_t*)(a1 + 96) <= *(int*)v2) {
			break;
		}
		v2 += 4;
		++v1;
	} while ((int)v2 < (int)getMemAt(0x587000, 87496));
	if (v1 > 2) {
		v1 = 2;
	}
	v3 = *(uint32_t*)(a1 + 28) + 36;
	v4 = 16 * v1;
	if (*(int*)&dword_587000_87412 == -1) {
		*(uint32_t*)(*(uint32_t*)(a1 + 28) + 76) = *getMemU32Ptr(0x5D4594, 814568 + v4);
		*(uint32_t*)(v3 + 24) = *getMemU32Ptr(0x5D4594, 814564 + v4);
		result = *getMemU32Ptr(0x5D4594, 814564 + v4);
	} else {
		*(uint32_t*)(*(uint32_t*)(a1 + 28) + 76) = *getMemU32Ptr(0x5D4594, 814560 + v4);
		*(uint32_t*)(v3 + 24) = *getMemU32Ptr(0x5D4594, 814556 + v4);
		result = *getMemU32Ptr(0x5D4594, 814556 + v4);
	}
	*(uint32_t*)(v3 + 48) = result;
	return result;
}

//----- (004375C0) --------------------------------------------------------
void sub_4375C0(int a1) {
	if (nox_wol_server_result_cnt_815088) {
		sub_46AD20(*(uint32_t**)&nox_wol_wnd_world_814980, 10070, nox_wol_server_result_cnt_815088 + 10069, a1);
	}
}

//----- (00437860) --------------------------------------------------------
int sub_437860(int a1, int a2) {
	int result;        // eax
	unsigned char* v3; // ecx

	result = 0;
	v3 = getMemAt(0x587000, 87532);
	while (a1 <= *((short*)v3 - 2) || a1 >= *(short*)v3 || a2 <= *((short*)v3 - 1) || a2 >= *((short*)v3 + 1)) {
		v3 += 8;
		++result;
		if ((int)v3 >= (int)getMemAt(0x587000, 87564)) {
			return 0;
		}
	}
	return result;
}

//----- (004379C0) --------------------------------------------------------
void sub_4379C0() {
	if (dword_587000_87408 == 1) {
		nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16399, 0, 0);
	}
}

//----- (00438330) --------------------------------------------------------
int sub_438330() {
	int (*v0)(void); // esi

	v0 = nox_wnd_xxx_815040->field_13;
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_815040);
	if (!nox_common_gameFlags_check_40A5C0(0x10000000)) {
		nox_client_guiXxx_43A9D0();
	}
	if (v0) {
		v0();
	}
	return 1;
}

//----- (00438370) --------------------------------------------------------
int sub_438370() {
	if (nox_wnd_xxx_815040->state == NOX_GUI_ANIM_OUT_DONE) {
		return sub_438330();
	}
	nox_wnd_xxx_815040->state = NOX_GUI_ANIM_OUT;
	sub_43BE40(2);
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100);
	return 1;
}

//----- (00438480) --------------------------------------------------------
int sub_438480() {
	nox_xxx_wndSetProc_46B2C0(*(int*)&nox_wol_wnd_gameList_815012, sub_439050);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&nox_wol_wnd_gameList_815012, sub_438EF0);
	sub_46B120(*(uint32_t**)&dword_5d4594_815016, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_815016, sub_438EF0);
	sub_46B120(*(uint32_t**)&dword_5d4594_815020, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_815020, sub_438EF0);
	sub_46B120(*(uint32_t**)&dword_5d4594_815024, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_815024, sub_438EF0);
	sub_46B120(*(uint32_t**)&dword_5d4594_815028, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_815028, sub_438EF0);
	sub_46B120(*(uint32_t**)&dword_5d4594_815032, *(int*)&nox_wol_wnd_gameList_815012);
	nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_815032, sub_438EF0);
	**(uint32_t**)(*(uint32_t*)((uint32_t)dword_5d4594_815004 + 32) + 28) = 10035;
	**(uint32_t**)(*(uint32_t*)((uint32_t)dword_5d4594_815004 + 32) + 32) = 10036;
	**(uint32_t**)(*(uint32_t*)((uint32_t)dword_5d4594_815004 + 32) + 36) = 10032;
	nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16408,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 28), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16408,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 28), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16408,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 28), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16408,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 28), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16408,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 28), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16409,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 32), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16409,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 32), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16409,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 32), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16409,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 32), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16409,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 32), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16410,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 36), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16410,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 36), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16410,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 36), 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16410,
							 *(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 36), 0);
	return nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16410,
									*(uint32_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 36), 0);
}

//----- (00438C80) --------------------------------------------------------
int sub_438C80(int a1, int a2) {
	char v2[404]; // [esp+4h] [ebp-194h]

	nox_point mpos = nox_client_getMousePos_4309F0();
	if (!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_815000)) {
		memcpy(v2, *(const void**)&dword_5d4594_815000, sizeof(v2));
		*(uint32_t*)&v2[16] -= 32;
		*(uint32_t*)&v2[20] -= 32;
		*(uint32_t*)&v2[8] += 64;
		*(uint32_t*)&v2[12] += 64;
		if (!dword_5d4594_815044 && !nox_xxx_wndPointInWnd_46AAB0(v2, mpos.x, mpos.y)) {
			nox_window_set_hidden(*(int*)&dword_5d4594_815000, 1);
			nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16403, -1, 0);
			dword_5d4594_815056 = 0;
			nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_815000);
			nox_xxx_windowFocus_46B500(*(int*)&nox_wol_wnd_world_814980);
		}
	}
	if (sub_4A28B0() && !nox_xxx_wndPointInWnd_46AAB0(*(uint32_t**)getMemAt(0x5D4594, 815036), mpos.x, mpos.y)) {
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
int sub_438DD0(unsigned int a1, unsigned int a2) {
	if (*(int*)&dword_587000_87412 == -1) {
		if (a1 > 0xD8 && a1 < 0x258 && a2 > 0x1B && a2 < 0x1C3) {
			return 1;
		}
	} else if (a1 > 0xE2 && a1 < 0x24E && a2 > 0x25 && a2 < 0x1B9) {
		return 1;
	}
	return 0;
}

//----- (00438E30) --------------------------------------------------------
int sub_438E30(uint32_t* a1, int a2) {
	uint32_t* v1; // esi
	int v2;       // edx
	int v3;       // esi
	short** v4;   // edi
	int v6;       // [esp+4h] [ebp-4h]

	v1 = a1;
	nox_client_wndGetPosition_46AA60(a1, &v6, &a1);
	v2 = v1[25];
	if (v1[9] & 6) {
		nox_client_drawImageAt_47D2C0(v1[19], v6 + v1[24], (int)a1 + v2);
	} else {
		nox_client_drawImageAt_47D2C0(v1[15], v6 + v1[24], (int)a1 + v2);
	}
	v3 = v1[100];
	if (!v3) {
		return 1;
	}
	do {
		if (!(*(uint8_t*)(v3 + 4) & 0x10) && *(uint32_t*)(v3 + 44) == 2048) {
			v4 = *(short***)(v3 + 32);
			nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
			nox_xxx_drawStringStyle_43F7B0(*(uint32_t*)(v3 + 236), *v4, v6 + *(uint32_t*)(v3 + 16), (int)a1 + *(uint32_t*)(v3 + 20));
		}
		v3 = *(uint32_t*)(v3 + 388);
	} while (v3);
	return 1;
}

//----- (00438EF0) --------------------------------------------------------
int sub_438EF0(uint32_t* a1, int a2, unsigned int a3, int a4) {
	int result; // eax
	int v5;     // esi
	int v6;     // esi

	if (a2 == 19) {
		v6 = a1[8];
		nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16391, *(uint32_t*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16391, *(uint32_t*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16391, *(uint32_t*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16391, *(uint32_t*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16391, *(uint32_t*)(v6 + 28), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16391, *(uint32_t*)(v6 + 28), 0);
		result = 0;
	} else if (a2 == 20) {
		v5 = a1[8];
		nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16391, *(uint32_t*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815016, 16391, *(uint32_t*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815020, 16391, *(uint32_t*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815024, 16391, *(uint32_t*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16391, *(uint32_t*)(v5 + 32), 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_815032, 16391, *(uint32_t*)(v5 + 32), 0);
		result = 0;
	} else {
		result = nox_xxx_wndListboxProcWithoutData10_4A28E0(a1, a2, a3, a4);
	}
	return result;
}

//----- (00439050) --------------------------------------------------------
int sub_439050(int a1, unsigned int a2, int* a3, unsigned int a4) {
	int v4; // edi
	int v5; // edi
	int v7; // eax

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
					sub_439370(&pos, dword_5d4594_814624);
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
			if (a3 == nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_gameList_815012, 10043) ||
				a3 == nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_gameList_815012, 10044)) {
				nox_window_call_field_94(*(int*)&dword_5d4594_815016, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815020, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815024, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815028, 0x4000, (int)a3, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_815032, 0x4000, (int)a3, 0);
			}
			break;
		case 0x4009u:
			v4 = *(uint32_t*)(a1 + 32);
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
uint32_t* sub_439450(int a1, int a2, uint32_t* a3) {
	uint32_t* result; // eax
	int v4;           // ecx

	result = a3;
	*a3 = a1 - 65;
	a3[1] = a2 - 20;
	if (a1 - 65 + 130 > 600) {
		*a3 = 470;
	}
	if (a2 - 20 + 120 > 451) {
		a3[1] = 331;
	}
	if (dword_587000_87408 == 1) {
		v4 = 55;
		if (a3[1] >= 55) {
			goto LABEL_10;
		}
	} else {
		v4 = 27;
		if (a3[1] >= 27) {
			goto LABEL_10;
		}
	}
	a3[1] = v4;
LABEL_10:
	if ((int)*a3 < 216) {
		*a3 = 216;
	}
	return result;
}

//----- (00439CC0) --------------------------------------------------------
char* sub_439CC0(int a1, char* a2) {
	size_t v2;    // esi
	char* result; // eax

	v2 = (size_t)&strstr((const char*)(a1 + 52), "'s_game")[-52 - a1];
	result = strncpy(a2, (const char*)(a1 + 52), v2);
	a2[v2] = 0;
	return result;
}

//----- (00439D00) --------------------------------------------------------
int sub_439D00(int* a1, int a2, unsigned int a3, int a4) {
	if (a2 == 5) {
		if (nox_xxx_wndGetID_46B0A0(a1) == 10020 && nox_game_createOrJoin_815048 == 1) {
			sub_439D90((unsigned short)a3, a3 >> 16);
			return 1;
		}
		return 0;
	}
	if (a2 != 21) {
		return 0;
	}
	if (a3 != 1) {
		if (a3 != 28 && a3 == 57) {
			nox_point mpos = nox_client_getMousePos_4309F0();
			nox_window_call_field_93(a1, 5, mpos.x | (mpos.y << 16), 0);
		}
		return 0;
	}
	if (a4 == 2) {
		sub_4373A0();
	}
	return 1;
}

//----- (00439D90) --------------------------------------------------------
int sub_439D90(unsigned int a1, unsigned int a2) {
	int result; // eax
	short v3;   // dx

	result = sub_438DD0(a1, a2);
	if (result) {
		v3 = a2 + *getMemU16Ptr(0x587000, 87530 + 8 * dword_587000_87412) - 27;
		*getMemU16Ptr(0x5D4594, 814916) = a1 + *getMemU16Ptr(0x587000, 87528 + 8 * dword_587000_87412) - 216;
		*getMemU16Ptr(0x5D4594, 814918) = v3;
		sub_43B460();
		if (sub_43BDB0() & 2) {
			nox_xxx_setQuest_4D6F60(1);
		}
		if (nox_xxx_isQuest_4D6F50()) {
			if (nox_client_countPlayerFiles04_4DC7D0()) {
				sub_4A7A70(1);
				nox_game_showSelChar_4A4DB0();
				return nox_client_setCursorType_477610(0);
			}
		} else if (nox_client_countPlayerFiles02_4DC630()) {
			sub_4A7A70(1);
			nox_game_showSelChar_4A4DB0();
			return nox_client_setCursorType_477610(0);
		}
		sub_4A7A70(0);
		nox_game_showSelClass_4A4840();
		nox_client_setCursorType_477610(0);
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
	if (!sub_43BE30() || !*getMemU32Ptr(0x5D4594, 815084)) {
		sub_44A400();
	}
	result = sub_43AF90(0);
	dword_5d4594_815044 = 0;
	return result;
}

//----- (0043A9D0) --------------------------------------------------------
int nox_client_guiXxx_43A9D0() {
	nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_814984);
	sub_489FB0();
	sub_4A2890();
	if (dword_5d4594_815000 && !*(uint32_t*)(dword_5d4594_815000 + 396)) {
		nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_815000);
		nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_815000);
		dword_5d4594_815000 = 0;
	}
	if (nox_wol_wnd_world_814980) {
		nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&nox_wol_wnd_world_814980);
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
	short v8;      // cx
	char v9[32];   // [esp+0h] [ebp-12Ch]
	char v10[268]; // [esp+20h] [ebp-10Ch]

	if (dword_5d4594_528252 && dword_5d4594_528256) {
		nox_xxx_networkLog_printf_413D30("RECON: Posting server to WOL");
	}
	nox_game_createOrJoin_815048 = 0;
	dword_5d4594_815052 = 1;
	v0 = nox_xxx_cliGamedataGet_416590(0);
	v1 = sub_416640();
	memcpy(v1 + 111, v0, 0x3Au);
	*(uint16_t*)(v1 + 163) = nox_common_gameFlags_getVal_40A5B0();
	*(uint32_t*)(v1 + 135) = -1;
	*(uint32_t*)(v1 + 139) = -1;
	*(uint32_t*)(v1 + 143) = -1;
	*(uint32_t*)(v1 + 147) = -1;
	*(uint32_t*)(v1 + 151) = -1;
	*(uint32_t*)(v1 + 155) = -1;
	*(uint32_t*)(v1 + 159) = -1;
	v2 = nox_xxx_serverOptionsGetServername_40A4C0();
	strncpy(v1 + 120, v2, 0xFu);
	strcpy(v1 + 111, nox_xxx_mapGetMapName_409B40());
	if (nox_xxx_isQuest_4D6F50()) {
		if (dword_5d4594_528256) {
			*(uint16_t*)(v1 + 165) = nox_game_getQuestStage_4E3CC0();
		} else {
			*(uint16_t*)(v1 + 165) = 1;
		}
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
	*((uint32_t*)v1 + 12) = NOX_CLIENT_VERS_CODE;
	v1[102] = v5 & 0x80 | v4;
	*((uint32_t*)v1 + 11) = *getMemU32Ptr(0x5D4594, 814916);
	*(uint16_t*)(v1 + 109) = nox_xxx_servGetPort_40A430();
	nox_client_setServerConnectAddr_435720("localhost");
	if (dword_587000_87404 == 1) {
		memset(v10, 0, sizeof(v10));
		v6 = sub_41FA40();
		nox_sprintf(v9, "%s%s", v6, getMemAt(0x587000, 90752));
		strcpy(&v10[52], v9);
		*(uint32_t*)v10 = sub_420100();
		*(uint32_t*)&v10[4] = 1;
		*(uint32_t*)&v10[8] = 32;
		*(uint32_t*)&v10[12] = 0;
		*(uint32_t*)&v10[16] = 0;
		*(uint32_t*)&v10[20] = 1;
		*(uint32_t*)&v10[24] = 1;
		*(uint32_t*)&v10[44] = 0;
		*(uint32_t*)&v10[28] = 0;
		*(uint32_t*)&v10[224] = NOX_CLIENT_VERS_CODE;
		*(uint32_t*)&v10[32] = *getMemU32Ptr(0x5D4594, 814916);
		v10[sub_425550(v1 + 100, &v10[69], 552) + 69] = 0;
		sub_40D320((int)v10);
	}
	result = nox_xxx_cliGamedataGet_416590(1);
	v8 = *((uint16_t*)result + 26) & 0xE90F;
	HIBYTE(v8) |= 1u;
	*((uint16_t*)result + 26) = v8;
	return result;
}

//----- (0043ACC0) --------------------------------------------------------
void sub_43ACC0() {
	char* v0;     // eax
	int i;        // ebp
	int v2;       // eax
	char* v4;     // eax
	int v5;       // eax
	int v6;       // esi
	uint32_t* v7; // eax
	uint32_t* v8; // eax
	char v9[172]; // [esp+0h] [ebp-ECh]
	char v10[32]; // [esp+ACh] [ebp-40h]
	char v11[32]; // [esp+CCh] [ebp-20h]

	if (!nox_wol_server_result_cnt_815088 && !dword_5d4594_815044) {
		v0 = sub_41FA40();
		nox_sprintf(v11, "%s%s", v0, getMemAt(0x587000, 90768));
		for (i = sub_41F0E0(); i; i = sub_41F0C0()) {
			if (strcmp(v11, (const char*)(i + 52))) {
				memset(v9, 0, 0xA8u);
				v9[168] = 0;
				sub_4255F0((uint8_t*)(i + 69), &v9[100], 552);
				*(uint32_t*)&v9[96] = 9999;
				if ((int)*(uint32_t*)(i + 40) >= 0) {
					*(uint32_t*)&v9[96] = *(uint32_t*)(i + 40);
				}
				v2 = *(uint32_t*)(i + 32);
				*(uint32_t*)&v9[44] = *(uint32_t*)(i + 32);
				*(uint32_t*)&v9[48] = *(uint32_t*)(i + 224);
				if (*(int*)&dword_587000_87412 == -1 ||
					sub_437860((short)v2, *(short*)&v9[46]) == *(int*)&dword_587000_87412) {
					if (nox_xxx_checkSomeFlagsOnJoin_4899C0((int)v9)) {
						v4 = nox_net_ip2str(htonl(*(uint32_t*)(i + 36)));
						*(uint32_t*)&v9[12] = *(uint32_t*)v4;
						*(uint32_t*)&v9[16] = *((uint32_t*)v4 + 1);
						*(uint32_t*)&v9[20] = *((uint32_t*)v4 + 2);
						v5 = *((uint32_t*)v4 + 3);
						*(uint32_t*)&v9[32] = i;
						*(uint32_t*)&v9[24] = v5;
						*(uint32_t*)&v9[36] = nox_wol_server_result_cnt_815088;
						*(uint32_t*)&v9[44] = *(uint32_t*)(i + 32);
						nox_wol_servers_addResult_4A0030(v9);
						if (v9[120]) {
							strncpy(v10, &v9[120], 0xFu);
							v10[15] = 0;
						} else {
							nox_sprintAddrPort_43BC80((int)&v9[12], *(unsigned short*)&v9[109], v10);
						}
						if (++nox_wol_server_result_cnt_815088 >= 0x9C4u) {
							break;
						}
					}
				}
			}
		}
		if (nox_wol_server_result_cnt_815088) {
			sub_4A0360();
		}
		sub_44A400();
		if (nox_common_gameFlags_check_40A5C0(0x2000000) && *(int*)&dword_587000_87412 == -1) {
			v6 = sub_4A7F20() + 10053;
			v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, 10002);
			nox_window_call_field_94(*(int*)&nox_wol_wnd_world_814980, 16391, (int)v7, 0);
			v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&nox_wol_wnd_world_814980, v6);
			nox_window_call_field_94(*(int*)&nox_wol_wnd_world_814980, 16391, (int)v8, 0);
		}
		if (nox_game_createOrJoin_815048) {
			sub_4375C0(0);
		}
	}
}

//----- (0043AF30) --------------------------------------------------------
int sub_43AF30() { return dword_5d4594_815052; }

//----- (0043AF40) --------------------------------------------------------
int sub_43AF40() { return nox_game_createOrJoin_815048; }

//----- (0043AF50) --------------------------------------------------------
int sub_43AF50(int a1) {
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
int sub_43AF90(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_814548 = a1;
	return result;
}

//----- (0043AFA0) --------------------------------------------------------
void nox_client_setConnError_43AFA0(int a1) {
	nox_client_connError_814552 = a1;
	sub_43AF90(2);
}

//----- (0043AFC0) --------------------------------------------------------
void sub_43AFC0(int a1) {
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
		nox_client_setConnError_43AFA0(9);
		return;
	}
	if (!dword_587000_87408) {
		sub_43A920();
		v10.field_0 = *((short*)v1 + 22) + 216;
		v10.field_4 = *((short*)v1 + 23) + 27;
		dword_5d4594_814624 = v1;
		sub_439370(&v10, (int)v1);
		nox_client_setMousePos_430B10(v10.field_0, v10.field_4);
		return;
	}
	sub_43A920();
	v3 = sub_4A0330(v1);
	nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16403, v3, 0);
	nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16412, v3, 0);
	v4 = *(uint32_t*)(dword_5d4594_815016 + 32);
	v10.field_0 = *(uint32_t*)(dword_5d4594_815016 + 16) + 216;
	v5 = *(uint32_t*)(dword_5d4594_815016 + 20);
	v6 = 131 * *(uint32_t*)(v4 + 48);
	v7 = *(uint32_t*)(v4 + 24);
	v8 = *(short*)(v4 + 54);
	v9 = *(uint32_t*)(v7 + 4 * v6);
	dword_5d4594_814624 = v1;
	v10.field_4 = v9 - v8 + v5 + 27;
	sub_439370(&v10, (int)v1);
	nox_client_setMousePos_430B10(v10.field_0, v10.field_4);
}

//----- (0043B0E0) --------------------------------------------------------
void nox_xxx_failconn_43B0E0(int a1) {
	int i;   // ebx
	int* v2; // eax
	int v3;  // esi
	int v4;  // eax
	int v5;  // edi
	int v6;  // ebp

	for (i = a1; i; i = *(uint32_t*)(i + 48)) {
		v2 = sub_4A04F0((char*)(i + 52));
		v3 = (int)v2;
		if (v2) {
			if (v2[24] == 9999) {
				v4 = *(uint32_t*)(i + 40);
				if (v4 >= 0) {
					*(uint32_t*)(v3 + 96) = v4;
					v5 = sub_4A0330((int*)v3);
					if (dword_587000_87408 == 1) {
						if (nox_xxx_checkSomeFlagsOnJoin_4899C0(v3)) {
							nox_swprintf((wchar_t*)getMemAt(0x5D4594, 814756), L"%d", *(uint32_t*)(v3 + 96));
							nox_window_call_field_94(*(int*)&dword_5d4594_815028, 16407,
													 (int)getMemAt(0x5D4594, 814756), v5);
							if (nox_xxx_getConnResult_4A0560() == 6 || nox_xxx_getConnResult_4A0560() == 7) {
								sub_425920((uint32_t**)v3);
								v6 = nox_wol_servers_addResult_4A0030((const void*)v3);
								nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16398, v5, 0);
								sub_43B2A0(v6);
								nox_gui_wol_newServerLine_43B7C0(v3);
							}
						} else {
							nox_window_call_field_94(*(int*)&nox_wol_wnd_gameList_815012, 16398, v5, 0);
							sub_4A0540((void*)v3);
						}
					} else if (nox_xxx_checkSomeFlagsOnJoin_4899C0(v3)) {
						if (*(uint8_t*)(v3 + 120)) {
							strncpy((char*)getMemAt(0x5D4594, 814920), (const char*)(v3 + 120), 0xFu);
							*getMemU8Ptr(0x5D4594, 814935) = 0;
						} else {
							nox_sprintAddrPort_43BC80(v3 + 12, *(uint16_t*)(v3 + 109),
													  (char*)getMemAt(0x5D4594, 814920));
						}
						if (*(uint32_t*)(v3 + 96) == 9999) {
							nox_swprintf((wchar_t*)getMemAt(0x5D4594, 814628), L"%S -- ms", getMemAt(0x5D4594, 814920));
						} else {
							nox_swprintf((wchar_t*)getMemAt(0x5D4594, 814628), L"%S %dms", getMemAt(0x5D4594, 814920),
										 *(uint32_t*)(v3 + 96));
						}
						nox_xxx_wndWddSetTooltip_46B000((wchar_t*)(*(uint32_t*)(v3 + 28) + 36),
														(wchar_t*)getMemAt(0x5D4594, 814628));
						sub_437320(v3);
					} else {
						sub_4A0540((void*)v3);
					}
				}
			}
		}
	}
}

//----- (0043B2A0) --------------------------------------------------------
int sub_43B2A0(int a1) {
	int result; // eax

	result = a1;
	*(uint16_t*)(*(uint32_t*)(nox_wol_wnd_gameList_815012 + 32) + 46) = a1;
	*(uint16_t*)(*(uint32_t*)(dword_5d4594_815016 + 32) + 46) = a1;
	*(uint16_t*)(*(uint32_t*)(dword_5d4594_815020 + 32) + 46) = a1;
	*(uint16_t*)(*(uint32_t*)(dword_5d4594_815024 + 32) + 46) = a1;
	*(uint16_t*)(*(uint32_t*)(dword_5d4594_815028 + 32) + 46) = a1;
	*(uint16_t*)(*(uint32_t*)(dword_5d4594_815032 + 32) + 46) = a1;
	return result;
}

//----- (0043B300) --------------------------------------------------------
unsigned int nox_client_getServerAddr_43B300() {
	unsigned int result; // eax

	if (dword_5d4594_815056) {
		result = inet_addr((const char*)((uint32_t)dword_5d4594_814624 + 12));
	} else {
		result = 0;
	}
	return result;
}

//----- (0043B320) --------------------------------------------------------
int nox_client_getServerPort_43B320() { return dword_5d4594_815056 != 0 ? *getMemU32Ptr(0x5D4594, 814604) : 0; }

//----- (0043B340) --------------------------------------------------------
int sub_43B340() {
	int result; // eax

	if (dword_5d4594_815056) {
		result = *(unsigned short*)((uint32_t)dword_5d4594_814624 + 163);
	} else {
		result = 0;
	}
	return result;
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
	if (nox_game_getStateCode_43BE10() == 1700) {
		return sub_438330();
	}
	nox_window_set_hidden(*(int*)&nox_wol_wnd_world_814980, 1);
	nox_window_set_hidden(*(int*)&dword_5d4594_815000, 1);
	nox_client_setCursorType_477610(0);
	return 1;
}
