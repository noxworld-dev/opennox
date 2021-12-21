#include <math.h>

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
#include "GAME3_3.h"
#include "GAME4_1.h"
#include "GAME5_2.h"
#include "client__draw__debugdraw.h"
#include "client__draw__image.h"
#include "client__draw__staticdraw.h"
#include "client__drawable__drawable.h"

#include "client__gui__gadgets__listbox.h"
#include "client__gui__guibook.h"
#include "client__gui__guicon.h"
#include "client__gui__guicurs.h"
#include "client__gui__guishop.h"
#include "client__gui__servopts__guiserv.h"
#include "client__gui__tooltip.h"
#include "client__gui__window.h"

#include "client__draw__drawwin.h"
#include "client__light__light16.h"

#include "client__video__draw_common.h"

#include "common/fs/nox_fs.h"
#include "common__binfile.h"
#include "common__magic__speltree.h"
#include "common__net_list.h"
#include "common__strman.h"
#include "input.h"
#include "input_common.h"
#include "mutexes.h"
#include "operators.h"

extern unsigned char byte_5D4594_3804364[160];

extern uint32_t dword_5d4594_1098456;
extern uint32_t dword_5d4594_1193180;
extern int dword_5d4594_1097212;
extern uint32_t dword_5d4594_1193352;
extern uint32_t dword_5d4594_1096636;
extern int dword_5d4594_1097216;
extern uint32_t dword_5d4594_3807116;
extern uint32_t dword_5d4594_1098620;
extern uint32_t nox_xxx_cursorTypePrev_587000_151528;
extern uint32_t dword_5d4594_1123520;
extern uint32_t dword_5d4594_1193188;
extern uint32_t dword_5d4594_1193176;
extern uint32_t dword_5d4594_1098596;
extern uint32_t dword_5d4594_1193336;
extern uint32_t nox_client_showTooltips_80840;
extern uint32_t dword_5d4594_3799452;
extern uint32_t dword_5d4594_1098600;
extern uint32_t dword_5d4594_3807152;
extern uint32_t dword_5d4594_1098616;
extern uint32_t dword_5d4594_1193672;
extern uint32_t dword_5d4594_3807136;
extern uint32_t dword_5d4594_1098604;
extern uint32_t dword_587000_154968;
extern void* dword_5d4594_1193624;
extern uint32_t dword_5d4594_1193664;
extern uint32_t dword_5d4594_1193524;
extern uint32_t dword_5d4594_3805484;
extern uint32_t dword_5d4594_3804684;
extern uint32_t dword_5d4594_1193156;
extern uint32_t dword_5d4594_3807140;
extern uint32_t dword_5d4594_3799552;
extern uint32_t dword_5d4594_1193648;
extern uint32_t dword_5d4594_1193668;
extern uint32_t nox_video_bag_ready;
extern uint32_t nox_xxx_xxxRenderGUI_587000_80832;
extern unsigned int nox_client_texturedFloors2_154960;
extern uint32_t dword_5d4594_3799476;
extern uint32_t dword_5d4594_3799468;
extern uint32_t nox_xxx_waypointCounterMB_587000_154948;
extern uint32_t dword_5d4594_3807160;
extern uint32_t dword_5d4594_1098592;
extern uint32_t dword_5d4594_1193184;
extern uint32_t dword_5d4594_1189600;
extern uint32_t dword_5d4594_823776;
extern uint32_t dword_5d4594_1098580;
extern uint32_t dword_5d4594_2650680;
extern uint32_t nox_client_lockHighResFloors_1193152;
extern uint32_t dword_5d4594_805836;
extern uint32_t dword_5d4594_3799508;
extern uint32_t dword_5d4594_3798812;
extern uint32_t dword_5d4594_3798800;
extern uint32_t dword_5d4594_1193584;
extern uint32_t dword_5d4594_3798828;
extern uint64_t qword_581450_9552;
extern uint64_t qword_581450_9544;
extern uint32_t dword_5d4594_1098624;
extern uint32_t dword_5d4594_2650676;
extern uint32_t dword_5d4594_3798156;
extern uint32_t cpuid_5d4594_3801804;
extern uint32_t dword_5d4594_3798816;
extern uint32_t nox_client_highResFloors_154952;
extern uint32_t dword_5d4594_3798808;
extern uint32_t dword_5d4594_3798832;
extern uint32_t dword_5d4594_1193384;
extern uint32_t dword_5d4594_1123532;
extern uint32_t dword_5d4594_1193348;
extern int dword_5d4594_3799524;
extern uint32_t dword_5d4594_3679320;
extern uint32_t dword_5d4594_1193360;
extern uint32_t nox_client_texturedFloors_154956;
extern uint32_t nox_client_highResFrontWalls_80820;
extern uint32_t dword_5d4594_3798836;
extern uint32_t dword_5d4594_1107036;
extern uint32_t dword_5d4594_251568;
extern uint32_t dword_5d4594_3799484;
extern uint32_t dword_5d4594_251572;
extern uint32_t dword_5d4594_1098628;
extern uint32_t dword_5d4594_3798804;
extern uint32_t dword_5d4594_1098576;
extern uint32_t dword_5d4594_1193516;
extern uint32_t dword_5d4594_3798820;
extern uint32_t dword_5d4594_3798824;
extern void* dword_587000_155144;
extern uint32_t dword_5d4594_3798840;
extern uint32_t dword_5d4594_1123524;
extern uint32_t dword_5d4594_1193380;
extern uint32_t nox_video_modeXxx_3801780;
extern uint32_t nox_client_renderGUI_80828;
extern uint32_t dword_5d4594_3798796;
extern uint32_t dword_5d4594_3798844;
extern uint32_t nox_player_netCode_85319C;
extern unsigned char* nox_draw_colors_r_3804672;
extern unsigned char* nox_draw_colors_g_3804656;
extern unsigned char* nox_draw_colors_b_3804664;
extern uint8_t** nox_pixbuffer_rows_3798784;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_backbuffer_width;
extern int nox_backbuffer_height;
extern int nox_video_renderTargetFlags;
extern int nox_video_pauseThreadedDrawCursor;
extern int nox_video_drawCursorThreadOk;
extern int nox_video_allowCursorDrawThread;
extern int nox_video_windowsPlatformVersion;
extern int nox_video_cursorDrawIsThreaded;
int nox_client_mouseCursorType = 0;
extern unsigned int nox_frame_xxx_2598000;
extern HANDLE* nox_video_cursorDrawThreadHandle;

void* dword_5d4594_1189592 = 0;
void* dword_5d4594_1189596 = 0;

extern nox_drawable** nox_drawable_list_3;
extern int nox_drawable_list_3_size;

extern nox_drawable** nox_drawable_list_4;
extern int nox_drawable_list_4_size;

extern nox_render_data_t* nox_draw_curDrawData_3799572;

extern obj_5D4594_2650668_t** ptr_5D4594_2650668;

extern uint32_t nox_arr_956A00[NOX_MAX_HEIGHT + 150];
extern unsigned char nox_arr_957820[128 * (NOX_MAX_HEIGHT + 150)];
unsigned char nox_arr_84EB20[280 * 57 * 4] = {0}; // TODO: the 4x factor is for high-res; figure out what 57 is
extern nox_light_3 nox_arr2_853BC0[57 * 4]
								  [45 * 4]; // TODO: the 4x factor is for high-res; figure out what those values are

#ifndef NOX_CGO
int nox_video_16bit = 0;
uint32_t dword_5d4594_1097208 = 0;

uint32_t nox_client_spellDragnDrop_1097192 = 0;
uint32_t nox_client_spellDragnDrop_type_1097196 = 0;
void* nox_client_itemDragnDrop_1097188 = 0;

uint8_t* nox_pixbuffer_3798780 = 0;
int nox_backbuffer_pitch_3801808 = 0;
void* (*nox_video_getImagePixdata_func)(nox_video_bag_image_t*) = 0;
uint32_t nox_video_pixmode_3799624 = 0;
void* dword_5d4594_1189584 = 0;
#endif // NOX_CGO
uint8_t** nox_pixbuffer_rows_3798776 = 0;
uint8_t* nox_pixbuffer_3798788 = 0;

void* dword_5d4594_1096640 = 0;

void (*func_587000_154940)(int2*, uint32_t, uint32_t) = nox_xxx_tileDraw_4815E0;
int (*func_587000_154944)(int, int) = nox_xxx_drawTexEdgesProbably_481900;

void (*nox_client_drawAtFunc_3799500)(nox_video_bag_image_t*, int, int) = 0;

int nox_video_cutSize = 100;

void* nox_client_spriteUnderCursorXxx_1096644 = 0;

#ifndef NOX_CGO
//----- (00475F10) --------------------------------------------------------
int sub_475F10(nox_draw_viewport_t* a1p) {
	uint32_t* a1 = a1p;
	int* v1;    // ebp
	int result; // eax
	bool i;     // zf
	int v4;     // esi
	int v5;     // eax

	v1 = nox_drawable_list_3;
	result = nox_drawable_list_3_size - 1;
	for (i = nox_drawable_list_3_size-- == 0; !i; --nox_drawable_list_3_size) {
		v4 = *v1;
		++v1;
		nox_xxx_drawHasteAndRunParticles_4746C0(a1, v4);
		if (nox_xxx_client_4984B0_drawable(v4)) {
			*(uint32_t*)(v4 + 484) = 1;
			(*(void (**)(uint32_t*, int))(v4 + 300))(a1, v4);
			if (*(uint8_t*)(v4 + 280) & 0x40) {
				nox_xxx_drawShinySpot_4C4F40(a1, v4);
			}
			nox_xxx_drawEffectsMB_474E60(a1, v4);
			sub_495BB0((uint32_t*)v4, a1);
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_EXTENTS)) {
				nox_thing_debug_draw(a1, v4);
			}
			v5 = *(uint32_t*)(v4 + 480);
			*(uint32_t*)(v4 + 132) = 0;
			if (!v5 && !*(uint32_t*)(v4 + 488)) {
				*(uint32_t*)(v4 + 340) = nox_frame_xxx_2598000;
			}
		}
		result = nox_drawable_list_3_size - 1;
		i = nox_drawable_list_3_size == 0;
	}
	return result;
}

//----- (00475FE0) --------------------------------------------------------
int sub_475FE0(nox_draw_viewport_t* a1p) {
	uint32_t* a1 = a1p;
	int* v1;    // ebp
	int result; // eax
	bool i;     // zf
	int v4;     // esi
	int v5;     // eax

	v1 = nox_drawable_list_4;
	result = nox_drawable_list_4_size - 1;
	for (i = nox_drawable_list_4_size-- == 0; !i; --nox_drawable_list_4_size) {
		v4 = *v1;
		++v1;
		if (nox_xxx_client_4984B0_drawable(v4)) {
			*(uint32_t*)(v4 + 484) = 1;
			(*(void (**)(uint32_t*, int))(v4 + 300))(a1, v4);
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_EXTENTS)) {
				nox_thing_debug_draw(a1, v4);
			}
			v5 = *(uint32_t*)(v4 + 480);
			*(uint32_t*)(v4 + 132) = 0;
			if (!v5 && !*(uint32_t*)(v4 + 488)) {
				*(uint32_t*)(v4 + 340) = nox_frame_xxx_2598000;
			}
		}
		result = nox_drawable_list_4_size - 1;
		i = nox_drawable_list_4_size == 0;
	}
	return result;
}
#endif // NOX_CGO

//----- (00476080) --------------------------------------------------------
int sub_476080(unsigned char* a1) {
	int v1;     // esi
	int v2;     // ecx
	int result; // eax
	int v4;     // edx
	int v5;     // ecx

	if (!*getMemU32Ptr(0x852978, 8)) {
		return 23 * a1[6] + 11;
	}
	switch (*a1) {
	case 0u:
	case 3u:
	case 0xBu:
		v1 = -23;
		v2 = 23 * a1[5] + 22;
		result = 23 * a1[6];
		goto LABEL_5;
	case 1u:
	case 4u:
	case 0xCu:
		v1 = 23;
		v2 = 23 * a1[5];
		result = 23 * a1[6];
	LABEL_5:
		v4 = *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 12) - v2;
		v5 = v1 * (*(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 16) - result) - 23 * v4;
		if (v1 < 0) {
			v5 = 23 * v4 - v1 * (*(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 16) - result);
		}
		if (v5 < 0) {
			result += 22;
		}
		break;
	default:
		result = 23 * a1[6] + 11;
		break;
	}
	return result;
}

//----- (00476160) --------------------------------------------------------
int sub_476160(const void* a1, const void* a2) {
	int v2;     // esi
	int result; // eax

	if ((signed char)*(uint8_t*)(*(uint32_t*)a1 + 112) >= 0) {
		v2 = *(uint32_t*)(*(uint32_t*)a1 + 16) + *(short*)(*(uint32_t*)a1 + 104);
	} else {
		v2 = sub_4761B0(*(uint32_t*)a1);
	}
	if ((signed char)*(uint8_t*)(*(uint32_t*)a2 + 112) >= 0) {
		result = v2 - (*(uint32_t*)(*(uint32_t*)a2 + 16) + *(short*)(*(uint32_t*)a2 + 104));
	} else {
		result = v2 - sub_4761B0(*(uint32_t*)a2);
	}
	return result;
}

//----- (004761B0) --------------------------------------------------------
int sub_4761B0(nox_drawable* a1p) {
	int a1 = a1p;
	int result; // eax
	int v2;     // edx
	int v3;     // ecx
	int v4;     // edx

	if (!*getMemU32Ptr(0x852978, 8)) {
		return *(uint32_t*)(a1 + 16) + *getMemIntPtr(0x587000, 196188 + 8 * *(unsigned char*)(a1 + 299)) / 2;
	}
	result = *(uint32_t*)(a1 + 16);
	v2 = 8 * *(unsigned char*)(a1 + 299);
	v3 = (*(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 16) - result) * *getMemIntPtr(0x587000, 196184 + v2) -
		 (*(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 12) - *(uint32_t*)(a1 + 12)) * *getMemIntPtr(0x587000, 196188 + v2);
	if (*getMemIntPtr(0x587000, 196184 + v2) < 0) {
		v3 = (*(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 12) - *(uint32_t*)(a1 + 12)) *
				 *getMemIntPtr(0x587000, 196188 + 8 * *(unsigned char*)(a1 + 299)) -
			 (*(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 16) - result) *
				 *getMemIntPtr(0x587000, 196184 + 8 * *(unsigned char*)(a1 + 299));
	}
	v4 = result + *getMemIntPtr(0x587000, 196188 + 8 * *(unsigned char*)(a1 + 299));
	if (v3 >= 0) {
		if (v4 <= result) {
			result += *getMemIntPtr(0x587000, 196188 + 8 * *(unsigned char*)(a1 + 299));
		}
	} else if (v4 > result) {
		result += *getMemIntPtr(0x587000, 196188 + 8 * *(unsigned char*)(a1 + 299));
	}
	return result;
}

//----- (00476240) --------------------------------------------------------
int sub_476240(const void* a1, const void* a2) {
	int v2; // esi

	v2 = sub_476080(*(unsigned char**)a1);
	return v2 - sub_476080(*(unsigned char**)a2);
}

//----- (00476270) --------------------------------------------------------
void sub_476270(nox_draw_viewport_t* a1p) {
	uint32_t* a1 = a1p;
	uint32_t* v1; // esi
	int v2;       // ebp
	int v3;       // ebx
	int v4;       // edi
	int v5;       // ebx
	int v6;       // ebx
	int v7;       // edi
	float* v8;    // eax
	int v9;       // edi
	int v10;      // ebx
	int v11;      // edi
	int v12;      // ebx
	int v13;      // ebp
	int v15;      // ecx
	int v16;      // edx
	int v17;      // ebx
	int v18;      // edi
	short v19;    // ax
	int v21;      // [esp-8h] [ebp-30h]
	int v22;      // [esp-4h] [ebp-2Ch]
	float* v23;   // [esp+10h] [ebp-18h]
	int v24;      // [esp+14h] [ebp-14h]
	float* v25;   // [esp+18h] [ebp-10h]
	int v26;      // [esp+18h] [ebp-10h]
	int v27;      // [esp+20h] [ebp-8h]
	int v28;      // [esp+20h] [ebp-8h]
	int v29;      // [esp+24h] [ebp-4h]
	int i;        // [esp+2Ch] [ebp+4h]
	int v31;      // [esp+2Ch] [ebp+4h]

	v27 = sub_50CB00();
	v24 = sub_50D210();
	v1 = a1;
	v23 = (float*)sub_50CB10();
	if (v27 >= 2) {
		v2 = 1;
		v3 = 0;
		for (i = 0;; v3 = i) {
			v4 = *v1 + (unsigned long long)(long long)v23[2 * v3] - v1[4];
			v25 = &v23[2 * v3 + 1];
			v5 = v1[1] + (unsigned long long)(long long)*v25 - v1[5];
			if (i == v24) {
				nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 940));
			} else if (v23[2 * i] < 0.0 || *v25 < 0.0) {
				nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 980));
			} else {
				nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2589772));
			}
			nox_client_drawBorderLines_49CC70(v4 - 1, v5 - 1, 3, 3);
			nox_client_drawSetColor_434460(*getMemIntPtr(0x8531A0, 2572));
			nox_client_drawAddPoint_49F500(v4, v5);
			v6 = *v1 + (unsigned long long)(long long)v23[2 * v2] - v1[4];
			v7 = v1[1] + (unsigned long long)(long long)v23[2 * v2 + 1] - v1[5];
			nox_client_drawAddPoint_49F500(v6, v7);
			nox_client_drawLineFromPoints_49E4B0();
			i = v2++;
			if (v2 >= v27) {
				break;
			}
		}
		nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2589772));
		nox_client_drawBorderLines_49CC70(v6 - 1, v7 - 1, 3, 3);
	}
	v8 = (float*)sub_50CD30();
	v9 = *v1 + (unsigned long long)(long long)*v8 - v1[4];
	v10 = v1[1] + (unsigned long long)(long long)v8[1] - v1[5];
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2523948));
	nox_client_drawBorderLines_49CC70(v9 - 2, v10 - 2, 5, 5);
	v11 = v1[4];
	v12 = v1[5];
	v26 = (long long)((double)(v11 / 23) + 0.5);
	v13 = (long long)((double)(v12 / 23) + 0.5);
	v28 = (long long)((double)((nox_win_width + v11) / 23) + 0.5);
	int v14 = (long long)((double)((nox_win_height + v12) / 23) + 0.5);
	v15 = v14;
	v29 = v14;
	if (v13 > v14) {
		return;
	}
	v16 = 23 * v13;
	v31 = 23 * v13;
	do {
		v17 = v26;
		if (v26 > v28) {
			goto LABEL_37;
		}
		v18 = 23 * v26;
		do {
			if (sub_57B500(v17, v13, 64) == -1) {
				v19 = sub_50AB50(v17, v13);
				if (v19 & 0x40) {
					nox_set_color_rgb_434430(0, 255, 0);
				} else if (v19 & 2) {
					nox_set_color_rgb_434430(0, 255, 255);
				} else {
					if (v19 & 1) {
						nox_set_color_rgb_434430(0, 100, 100);
						goto LABEL_34;
					}
					if (v19 & 0x3C) {
						v22 = 255;
					LABEL_32:
						v21 = 0;
					LABEL_33:
						nox_set_color_rgb_434430(255, v21, v22);
						goto LABEL_34;
					}
					if (v19 & 0x400) {
						v22 = 0;
						goto LABEL_32;
					}
					if (v19 & 0x200) {
						v22 = 0;
						v21 = 255;
						goto LABEL_33;
					}
					if (!(v19 & 0x100)) {
						goto LABEL_35;
					}
					nox_set_color_rgb_434430(100, 100, 0);
				}
			} else {
				nox_set_color_rgb_434430(0, 0, 255);
			}
		LABEL_34:
			nox_client_drawBorderLines_49CC70(v18 - v1[4], v31 - v1[5], 23, 23);
		LABEL_35:
			++v17;
			v18 += 23;
		} while (v17 <= v28);
		v15 = v29;
		v16 = v31;
	LABEL_37:
		++v13;
		v16 += 23;
		v31 = v16;
	} while (v13 <= v15);
}

//----- (004765F0) --------------------------------------------------------
int sub_4765F0(nox_draw_viewport_t* a1p) {
	int a1 = a1p;
	int result; // eax
	int v2;     // eax

	*getMemU32Ptr(0x5D4594, 1096440) = nox_client_highResFloors_154952;
	result = *getMemU32Ptr(0x852978, 8);
	*getMemU32Ptr(0x5D4594, 1096444) = nox_client_highResFrontWalls_80820;
	if (*getMemU32Ptr(0x852978, 8) && !nox_client_lockHighResFloors_1193152) {
		v2 = *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 276);
		if ((v2 == 3 || v2 == 6 || v2 == 45) && (*(int*)(a1 + 16) - *getMemIntPtr(0x5D4594, 1096556) >= 4 ||
												 *(int*)(a1 + 20) - *getMemIntPtr(0x5D4594, 1096560) >= 4)) {
			nox_client_highResFloors_154952 = 0;
			nox_client_highResFrontWalls_80820 = 0;
		}
		result = *(uint32_t*)(a1 + 16);
		*getMemU32Ptr(0x5D4594, 1096556) = *(uint32_t*)(a1 + 16);
		*getMemU32Ptr(0x5D4594, 1096560) = *(uint32_t*)(a1 + 20);
	}
	return result;
}

//----- (00476680) --------------------------------------------------------
int sub_476680() {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 1096440);
	nox_client_highResFloors_154952 = *getMemU32Ptr(0x5D4594, 1096440);
	nox_client_highResFrontWalls_80820 = *getMemU32Ptr(0x5D4594, 1096444);
	return result;
}

//----- (004766A0) --------------------------------------------------------
void nox_video_setCutSize_4766A0(int a1) {
	if (a1 >= 65) {
		if (a1 > 100) {
			a1 = 100;
		}
		nox_video_cutSize = a1;
	} else {
		nox_video_cutSize = 65;
	}
}

//----- (004766D0) --------------------------------------------------------
int nox_video_getCutSize_4766D0() { return nox_video_cutSize; }

#ifndef NOX_CGO
//----- (004766E0) --------------------------------------------------------
void nox_client_increaseViewport_4766E0() { nox_draw_setCutSize_476700(0, 2); }

//----- (004766F0) --------------------------------------------------------
void nox_client_decreaseViewport_4766F0() { nox_draw_setCutSize_476700(0, -2); }

//----- (00476700) --------------------------------------------------------
void nox_draw_setCutSize_476700(int cutPerc, int a2) {
	nox_draw_viewport_t* rdr = nox_draw_getViewport_437250();
	int v2 = a2;
	int v4 = rdr->width;
	int perc = cutPerc;
	if (a2) {
		int v7 = 0;
		while (v7 < 4) {
			perc = v2 + 100 * (nox_backbuffer_width - 2 * rdr->x1) / nox_backbuffer_width;
			int v6 = perc * nox_backbuffer_width / 100;
			if (v2 >= 0) {
				++v2;
			} else {
				--v2;
			}
			if (v6 - v4 < 0) {
				v7 = v4 - v6;
			} else {
				v7 = v6 - v4;
			}
		}
	}
	if (perc >= 40) {
		if (perc > 100) {
			perc = 100;
		}
	} else {
		perc = 40;
	}
	nox_video_cutSize = perc;

	rdr->x1 = ((nox_backbuffer_width - perc * nox_backbuffer_width / 100) / 2) & 0xFFFFFFFC;
	if (rdr->x1 < 0) {
		rdr->x1 = 0;
	}

	rdr->y1 = ((nox_backbuffer_height - perc * nox_backbuffer_height / 100) / 2);
	if (rdr->y1 < 0) {
		rdr->y1 = 0;
	}

	rdr->x2 = (nox_backbuffer_width - rdr->x1 + 2) & 0xFFFFFFFC;
	if (rdr->x2 >= nox_backbuffer_width) {
		rdr->x2 = nox_backbuffer_width - 1;
	}

	rdr->y2 = (nox_backbuffer_height - rdr->y1 - 1);
	if (rdr->y2 >= nox_backbuffer_height) {
		rdr->y2 = nox_backbuffer_height - 1;
	}

	rdr->width = rdr->x2 - rdr->x1 + 1;
	rdr->height = rdr->y2 - rdr->y1 + 1;
	dword_5d4594_1193188 = 1;
	dword_5d4594_3799524 = 1;
}
#endif // NOX_CGO

//----- (00476850) --------------------------------------------------------
void sub_476850(nox_draw_viewport_t* vp, nox_drawable* dr) {
	unsigned char* a2 = dr;
	int v2;           // eax
	int* v3;          // eax
	int v4;           // edi
	int v5;           // ecx
	uint32_t* v6;     // eax
	int v7;           // ebx
	int v8;           // ebp
	int v9;           // eax
	int v10;          // ecx
	int v11;          // edx
	unsigned int v12; // edi
	uint8_t* v13;     // eax
	unsigned int v14; // esi
	char* v15;        // edx
	unsigned int v16; // ebx
	int v17;          // ecx
	int v18;          // ecx
	unsigned int v19; // ebp
	unsigned int v20; // ebx
	int v21;          // edx
	uint8_t* v22;     // esi
	char* v23;        // edi
	uint8_t* v24;     // esi
	int v25;          // [esp+10h] [ebp-18h]
	int v26;          // [esp+14h] [ebp-14h]
	int i;            // [esp+14h] [ebp-14h]
	unsigned int v28; // [esp+18h] [ebp-10h]
	int v29;          // [esp+1Ch] [ebp-Ch]
	int v30;          // [esp+20h] [ebp-8h]
	unsigned int v31; // [esp+30h] [ebp+8h]

	if (*((int (**)(int*, int))a2 + 75) == nox_thing_static_draw) {
		if (*((uint32_t*)a2 + 28) & 0x40000 && !(*((uint32_t*)a2 + 30) & 0x1000000)) {
			return;
		}
		v2 = *(uint32_t*)(*((uint32_t*)a2 + 76) + 4);
	} else {
		v2 = *(uint32_t*)(*(uint32_t*)(*((uint32_t*)a2 + 76) + 4) + 4 * *((uint32_t*)a2 + 77));
	}
	v3 = nox_video_getImagePixdata_func(v2);
	if (v3) {
		v4 = *v3;
		v5 = v3[1];
		v6 = v3 + 2;
		v26 = v5;
		v7 = dword_5d4594_3798820;
		v8 = *v6 + *((uint32_t*)a2 + 3) - *a2;
		v9 = (int)(v6 + 2);
		v30 = v4;
		v10 = *(uint32_t*)(v9 - 4) + *((uint32_t*)a2 + 4) - *((short*)a2 + 53) - *((short*)a2 + 52) - a2[1];
		if (v8 < *(int*)&dword_5d4594_3798820 || v8 + v4 >= *(int*)&dword_5d4594_3798820 + dword_5d4594_3798800 ||
			v10 < *(int*)&dword_5d4594_3798824 || v10 + v26 >= *(int*)&dword_5d4594_3798824 + dword_5d4594_3798808) {
			*((uint32_t*)a2 + 86) = 0;
		} else {
			v11 = nox_xxx_waypointCounterMB_587000_154948;
			if (*(int*)&nox_xxx_waypointCounterMB_587000_154948 <= 0) {
				*((uint32_t*)a2 + 86) = 0;
				v7 = dword_5d4594_3798820;
				v11 = nox_xxx_waypointCounterMB_587000_154948;
			}
			if (v11 - *((int*)a2 + 86) > 1 || v11 <= 0) {
				v12 = dword_5d4594_3798844;
				v13 = (uint8_t*)(v9 + 1);
				v28 = dword_5d4594_3798844;
				v25 = dword_5d4594_3798844 - dword_5d4594_3798796;
				v14 = v8 + dword_5d4594_3798796 + dword_5d4594_3798836 +
					  dword_5d4594_3798804 * (v10 + dword_5d4594_3798840 - dword_5d4594_3798824) - v7;
				v31 = v14;
				if (v14 >= *(int*)&dword_5d4594_3798844) {
					v14 -= v25;
					v31 = v14;
				}
				if (v26) {
					v29 = v26;
					do {
						v15 = (char*)v14;
						for (i = v30; i > 0; i -= v19) {
							v16 = (unsigned char)v13[1];
							v17 = *v13 & 0xF;
							v13 += 2;
							v18 = v17 - 1;
							v19 = v16;
							if (v18) {
								if (v18 == 1) {
									if ((unsigned int)v15 >= v12 || (unsigned int)&v15[v16] < v12) {
										memcpy(v15, v13, 4 * (v16 >> 2));
										v24 = &v13[4 * (v16 >> 2)];
										v23 = &v15[4 * (v16 >> 2)];
										v13 += v16;
										v15 += v16;
										memcpy(v23, v24, v16 & 3);
										v14 = v31;
										v12 = v28;
									} else {
										v20 = (unsigned int)&v15[v16 - v12];
										v19 -= v20;
										memcpy(v15, v13, v19);
										v21 = dword_5d4594_3798796;
										v22 = &v13[v19];
										v13 += v20 + v19;
										memcpy(*(void**)&dword_5d4594_3798796, v22, v20);
										v15 = (char*)(v20 + v21);
										v14 = v31;
										v12 = v28;
									}
								}
							} else {
								v15 += v16;
								if ((unsigned int)v15 >= v12) {
									v15 -= v25;
								}
							}
						}
						v14 += dword_5d4594_3798804;
						v31 = v14;
						if (v14 >= v12) {
							v14 -= v25;
							v31 = v14;
						}
						--v29;
					} while (v29);
				}
			} else {
				*((uint32_t*)a2 + 86) = v11;
			}
		}
	}
}

//----- (00476AE0) --------------------------------------------------------
void* sub_476AE0(nox_draw_viewport_t* vp, nox_drawable* dr) {
	unsigned char* a2 = dr;
	unsigned char* v2;                        // ebx
	int result;                               // eax
	int (*result2)(int*, int);                // eax
	int v4;                                   // eax
	int v5;                                   // edi
	int v6;                                   // ecx
	int v7;                                   // ebp
	char* v8;                                 // esi
	int v9;                                   // edx
	int v10;                                  // ecx
	unsigned int v11;                         // edi
	uint8_t* v12;                             // esi
	int v13;                                  // ebx
	int v14;                                  // edx
	unsigned int v15;                         // ecx
	unsigned int v16;                         // ebx
	int v17;                                  // ecx
	int v18;                                  // eax
	int v19;                                  // eax
	int v20;                                  // ebp
	int v21;                                  // edi
	int v22;                                  // ebp
	int v23;                                  // ebx
	int v24;                                  // esi
	int v25;                                  // [esp+10h] [ebp-1Ch]
	int v26;                                  // [esp+14h] [ebp-18h]
	int v27;                                  // [esp+18h] [ebp-14h]
	int v28;                                  // [esp+18h] [ebp-14h]
	unsigned int v29;                         // [esp+1Ch] [ebp-10h]
	int v30;                                  // [esp+20h] [ebp-Ch]
	int v31;                                  // [esp+24h] [ebp-8h]
	int v32;                                  // [esp+28h] [ebp-4h]
	void (*v33)(unsigned int, uint8_t*, int); // [esp+34h] [ebp+8h]

	v2 = a2;
	result2 = (int (*)(int*, int)) * ((uint32_t*)a2 + 75);
	if (result2 == nox_thing_static_draw) {
		if (*((uint32_t*)a2 + 28) & 0x40000 && !(*((uint32_t*)a2 + 30) & 0x1000000)) {
			return result2;
		}
		v4 = *(uint32_t*)(*((uint32_t*)a2 + 76) + 4);
	} else {
		v4 = *(uint32_t*)(*(uint32_t*)(*((uint32_t*)a2 + 76) + 4) + 4 * *((uint32_t*)a2 + 77));
	}
	result = nox_video_getImagePixdata_func(v4);
	if (result) {
#ifndef NOX_CGO
		if (nox_video_pixmode_3799624 == 1) {
			v33 = sub_476D70;
		} else {
			v33 = sub_476DA0;
			if (!nox_client_texturedFloors_154956) {
				v33 = sub_476D70;
			}
		}
#else  // NOX_CGO
		v33 = sub_476D70;
#endif // NOX_CGO
		v5 = *(uint32_t*)result;
		v6 = *((uint32_t*)result + 1);
		v27 = *((uint32_t*)result + 1);
		v7 = *((uint32_t*)result + 2) + *((uint32_t*)v2 + 3) - *v2;
		v8 = (char*)result + 16;
		result =
			(int)(*((uint32_t*)result + 3) + *((uint32_t*)v2 + 4) - *((short*)v2 + 53) - *((short*)v2 + 52) - v2[1]);
		v31 = v5;
		if (v7 < *(int*)&dword_5d4594_3798820 || v7 + v5 >= *(int*)&dword_5d4594_3798820 + dword_5d4594_3798800 ||
			(v9 = dword_5d4594_3798824, (int)result < *(int*)&dword_5d4594_3798824) ||
			(int)result + v6 >= *(int*)&dword_5d4594_3798824 + dword_5d4594_3798808) {
			*((uint32_t*)v2 + 86) = 0;
		} else {
			v10 = nox_xxx_waypointCounterMB_587000_154948;
			if (*(int*)&nox_xxx_waypointCounterMB_587000_154948 <= 0) {
				*((uint32_t*)v2 + 86) = 0;
				v9 = dword_5d4594_3798824;
				v10 = nox_xxx_waypointCounterMB_587000_154948;
			}
			if (v10 - *((int*)v2 + 86) > 1 || v10 <= 0) {
				v11 = dword_5d4594_3798844;
				v12 = v8 + 1;
				v29 = dword_5d4594_3798844;
				v26 = dword_5d4594_3798844 - dword_5d4594_3798796;
				v13 = dword_5d4594_3798804 * ((uint32_t)result + dword_5d4594_3798840 - v9);
				v14 = v7 + dword_5d4594_3798836 - dword_5d4594_3798820;
				v15 = v13 + dword_5d4594_3798796 + 2 * v14;
				v25 = v13 + dword_5d4594_3798796 + 2 * v14;
				if (v15 >= *(int*)&dword_5d4594_3798844) {
					v15 -= v26;
					v25 = v15;
				}
				result = (int)(v27 - 1);
				if (v27) {
					v30 = v27;
					do {
						v16 = v15;
						v28 = v31;
						if (v31 > 0) {
							do {
								v17 = (unsigned char)v12[1];
								v18 = *v12 & 0xF;
								v12 += 2;
								v19 = v18 - 1;
								v32 = v17;
								v20 = 2 * v17;
								if (v19) {
									if (v19 == 1) {
										if (v16 >= v11 || v16 + v20 < v11) {
											v33(v16, v12, 2 * v17);
											v12 += v20;
											v16 += v20;
										} else {
											v21 = v16 + v20 - v29;
											v22 = v29 - v16;
											v33(v16, v12, v29 - v16);
											v23 = dword_5d4594_3798796;
											v24 = (int)&v12[v22];
											v33(dword_5d4594_3798796, (uint8_t*)v24, v21);
											v12 = (uint8_t*)(v21 + v24);
											v16 = v21 + v23;
											v11 = v29;
										}
									}
								} else {
									v16 += v20;
									if (v16 >= v11) {
										v16 -= v26;
									}
								}
								v28 -= v32;
							} while (v28 > 0);
							v15 = v25;
						}
						v15 += dword_5d4594_3798804;
						v25 = v15;
						if (v15 >= v11) {
							v15 -= v26;
							v25 = v15;
						}
						result = (int)--v30;
					} while (v30);
				}
			} else {
				*((uint32_t*)v2 + 86) = v10;
			}
		}
	}
	return result;
}

//----- (00476D70) --------------------------------------------------------
short sub_476D70(uint32_t* a1, int* a2, unsigned int a3) {
	uint32_t* v3;  // edi
	signed int v4; // ecx
	int* v5;       // esi
	int v6;        // eax

	v3 = a1;
	v4 = a3 >> 2;
	v5 = a2;
	if (a3 >> 2) {
		do {
			v6 = *v5;
			++v5;
			*v3 = v6;
			++v3;
		} while (v4-- > 1);
	}
	if (a3 & 3) {
		LOWORD(v6) = *(uint16_t*)v5;
		*(uint16_t*)v3 = *(uint16_t*)v5;
	}
	return v6;
}

//----- (00476DA0) --------------------------------------------------------
void sub_476DA0(unsigned int* a1, uint32_t* a2, unsigned int a3) {
	unsigned int* v3; // edi
	signed int v4;    // ecx
	uint32_t* v5;     // esi

	v3 = a1;
	v4 = a3 >> 2;
	v5 = a2;
	if (a3 >> 2) {
		do {
			*v3 = ((*v5 & 0xFFC0FFC0) >> 1) | *v5 & 0x1F001F;
			++v5;
			++v3;
		} while (v4-- > 1);
	}
	if (a3 & 3) {
		*(uint16_t*)v3 = ((unsigned short)(*(uint16_t*)v5 & 0xFFC0) >> 1) | *(uint16_t*)v5 & 0x1F;
	}
}

//----- (00476E00) --------------------------------------------------------
int nox_client_setPhonemeFrame_476E00(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1096596 + 4 * a1) = nox_frame_xxx_2598000;
	return result;
}

//----- (00476E20) --------------------------------------------------------
uint32_t* sub_476E20() {
	int v0;       // esi
	char* v1;     // eax
	uint32_t* v2; // esi

	v0 = 0;
	while (1) {
		v1 = nox_xxx_gLoadImg_42F970(*(const char**)getMemAt(0x587000, 151272 + v0));
		*getMemU32Ptr(0x5D4594, 1096564 + v0) = v1;
		if (!v1) {
			break;
		}
		v0 += 4;
		if (v0 >= 32) {
			v2 = nox_window_new(0, 64, (nox_win_width - 100) / 2, (nox_win_height - 100) / 2, 1, 1, 0);
			nox_window_set_all_funcs(v2, 0, sub_476E90, 0);
			return v2;
		}
	}
	return 0;
}

//----- (00476E90) --------------------------------------------------------
int sub_476E90() {
	unsigned char* v0; // edi
	int v1;            // esi

	v0 = getMemAt(0x587000, 151208);
	v1 = 0;
	do {
		if (*getMemU32Ptr(0x5D4594, 1096596 + v1)) {
			nox_client_drawImageAt_47D2C0(*getMemU32Ptr(0x5D4594, 1096564 + v1),
										  nox_win_width / 2 + *(uint32_t*)v0 - 16,
										  *((uint32_t*)v0 + 1) + nox_win_height / 2 - 41);
			if ((unsigned int)(nox_frame_xxx_2598000 - *getMemU32Ptr(0x5D4594, 1096596 + v1)) > 3) {
				*getMemU32Ptr(0x5D4594, 1096596 + v1) = 0;
			}
		}
		v0 += 8;
		v1 += 4;
	} while ((int)v0 < (int)getMemAt(0x587000, 151272));
	return 1;
}

//----- (00476F10) --------------------------------------------------------
int nox_xxx_clientDeleteSprite_476F10_drawable(nox_drawable* dr) {
	int a1 = dr;
	int result; // eax

	result = a1;
	if (dword_5d4594_1096640 == a1) {
		dword_5d4594_1096640 = 0;
	}
	if (nox_client_spriteUnderCursorXxx_1096644 == a1) {
		nox_client_spriteUnderCursorXxx_1096644 = 0;
	}
	return result;
}

//----- (00476F40) --------------------------------------------------------
unsigned int nox_xxx_packetGetMarshall_476F40() {
	unsigned int result; // eax

	if (dword_5d4594_1096640) {
		result = nox_xxx_netGetUnitCodeCli_578B00(*(int*)&dword_5d4594_1096640);
	} else {
		result = 0;
	}
	return result;
}

//----- (00476F60) --------------------------------------------------------
int sub_476F60() {
	int result; // eax

	if (dword_5d4594_1096640) {
		result = *(uint32_t*)((uint32_t)dword_5d4594_1096640 + 128);
	} else {
		result = 0;
	}
	return result;
}

//----- (00476F80) --------------------------------------------------------
void* nox_xxx_spriteGetMB_476F80() { return dword_5d4594_1096640; }

//----- (00476F90) --------------------------------------------------------
void* nox_xxx_clientGetSpriteAtCursor_476F90() { return nox_client_spriteUnderCursorXxx_1096644; }

//----- (00476FA0) --------------------------------------------------------
void nox_xxx_clientEnumHover_476FA0() {
	int4 v2; // [esp+10h] [ebp-10h]

	if (!*getMemU32Ptr(0x5D4594, 1096632)) {
		*getMemU32Ptr(0x5D4594, 1096632) = nox_xxx_getNameId_4E3AA0("Glyph");
	}
	nox_point mpos = nox_client_getMousePos_4309F0();
	nox_draw_getViewport_437250();
	sub_473970(&mpos, &mpos);
	dword_5d4594_1096640 = 0;
	nox_client_spriteUnderCursorXxx_1096644 = 0;
	*getMemU32Ptr(0x5D4594, 1096628) = 0;
	v2.field_0 = mpos.x - 96;
	v2.field_8 = mpos.x + 96;
	v2.field_C = mpos.y + 96;
	v2.field_4 = mpos.y - 96;
	dword_5d4594_1096636 = 0;
	nox_xxx_forEachSprite_49AB00(&v2, nox_xxx_clientOnCursorHover_477050, &mpos);
}

//----- (00477050) --------------------------------------------------------
void nox_xxx_clientOnCursorHover_477050(int arg0, int a2) {
	int v2;    // esi
	int v3;    // eax
	int v4;    // eax
	int v5;    // ecx
	char* v6;  // eax
	int v7;    // eax
	float v8;  // ebp
	int v9;    // edi
	int v10;   // ebx
	int v11;   // eax
	int v12;   // edx
	int v13;   // edi
	int v14;   // ebx
	float v15; // eax
	int v16;   // edx
	int v17;   // eax
	int v18;   // edi
	int v19;   // ebx
	int v20;   // eax
	int v21;   // ecx
	int v22;   // edi
	float v23; // [esp+0h] [ebp-24h]
	float v24; // [esp+0h] [ebp-24h]
	float v25; // [esp+0h] [ebp-24h]
	float v26; // [esp+0h] [ebp-24h]
	float2 a3; // [esp+14h] [ebp-10h]
	float2 a1; // [esp+1Ch] [ebp-8h]
	int v29;   // [esp+28h] [ebp+4h]

	if (!*getMemU32Ptr(0x5D4594, 1096648)) {
		*getMemU32Ptr(0x5D4594, 1096648) = nox_xxx_getTTByNameSpriteMB_44CFC0("Polyp");
	}
	v2 = arg0;
	if (arg0 == *getMemU32Ptr(0x852978, 8)) {
		return;
	}
	v3 = *(uint32_t*)(arg0 + 120);
	if (!((v3 & 0x8000) == 0 && (!nox_xxx_spriteCheckFlag31_4356C0(arg0, 0) ||
								 nox_xxx_spriteCheckFlag31_4356C0(*getMemIntPtr(0x852978, 8), 21)))) {
		return;
	}
	v4 = *(uint32_t*)(arg0 + 112);
	if (!(!(v4 & 2) || (v5 = *(uint32_t*)(arg0 + 116), !(v5 & 0x4000)))) {
		return;
	}
	if (!(v4 & 0x80400206 || *(uint32_t*)(arg0 + 108) == *getMemU32Ptr(0x5D4594, 1096648))) {
		return;
	}
	if (!nox_xxx_client_4984B0_drawable(arg0)) {
		return;
	}
	if (!(!(*(uint8_t*)(arg0 + 112) & 4) ||
		  (v6 = nox_common_playerInfoGetByID_417040(*(uint32_t*)(arg0 + 128))) != 0 && !(v6[3680] & 1))) {
		return;
	}
	v7 = *(uint32_t*)(arg0 + 112);
	if (!((!(v7 & 0x400000) || (*(uint8_t*)(arg0 + 116) & 0x80)) && (!(v7 & 2) || *(uint32_t*)(arg0 + 276) != 10))) {
		return;
	}
	v23 = (double)*(int*)(arg0 + 16) - *(float*)(arg0 + 100) - (double)*(short*)(arg0 + 104);
	v29 = nox_float2int(v23);
	v24 = (double)*(int*)(v2 + 16) - *(float*)(v2 + 96) - (double)*(short*)(v2 + 104);
	v8 = COERCE_FLOAT(nox_float2int(v24));
	a3.field_0 = v8;
	if (*(uint32_t*)(v2 + 44) == 2) {
		v25 = *(float*)(v2 + 48) * *(float*)(v2 + 48);
		LODWORD(a3.field_0) = nox_float2int(v25);
		v17 = nox_float2int(*(float*)(v2 + 48));
		v18 = *(uint32_t*)(v2 + 12);
		v19 = *(uint32_t*)(v2 + 12) - v17;
		v20 = v18 + nox_float2int(*(float*)(v2 + 48));
		v21 = *(uint32_t*)(a2 + 4);
		if (v21 <= SLODWORD(v8)) {
			v8 = *(float*)&v29;
			if (v21 >= v29) {
				if (*(int*)a2 <= v19 || *(int*)a2 >= v20) {
					return;
				}
				goto LABEL_38;
			}
		}
		v15 = a3.field_0;
		v16 = (*(uint32_t*)a2 - v18) * (*(uint32_t*)a2 - v18) + (v21 - LODWORD(v8)) * (v21 - LODWORD(v8));
	} else {
		if (*(uint32_t*)(v2 + 44) != 3) {
			return;
		}
		a1.field_0 = (double)*(int*)(v2 + 12);
		a1.field_4 = (double)SLODWORD(a3.field_0);
		a3.field_0 = (double)*(int*)a2;
		a3.field_4 = (double)*(int*)(a2 + 4);
		if (nox_xxx_map_57B850(&a1, (float*)(v2 + 44), &a3) ||
			(a1.field_4 = (double)v29, nox_xxx_map_57B850(&a1, (float*)(v2 + 44), &a3)) ||
			(v9 = *(uint32_t*)(v2 + 12) + nox_float2int(*(float*)(v2 + 72)),
			 v10 = v29 + nox_float2int(*(float*)(v2 + 76)), v11 = LODWORD(v8) + nox_float2int(*(float*)(v2 + 76)),
			 *(uint32_t*)a2 > v9) &&
				*(uint32_t*)a2 < *(int*)(v2 + 12) && (v12 = *(uint32_t*)(a2 + 4), v12 > v10) && v12 < v11) {
			goto LABEL_38;
		}
		v13 = *(uint32_t*)(v2 + 12) + nox_float2int(*(float*)(v2 + 80));
		v14 = v29 + nox_float2int(*(float*)(v2 + 84));
		LODWORD(v15) = LODWORD(v8) + nox_float2int(*(float*)(v2 + 84));
		if (*(int*)a2 < *(int*)(v2 + 12)) {
			return;
		}
		if (*(int*)a2 >= v13) {
			return;
		}
		v16 = *(uint32_t*)(a2 + 4);
		if (v16 <= v14) {
			return;
		}
	}
	if (v16 >= SLODWORD(v15)) {
		return;
	}
LABEL_38:
	v26 = (double)*(short*)(v2 + 104) + (double)*(int*)(v2 + 16) + *(float*)(v2 + 96);
	v22 = nox_float2int(v26);
	if (v22 > *getMemIntPtr(0x5D4594, 1096628)) {
		*getMemU32Ptr(0x5D4594, 1096628) = v22;
		dword_5d4594_1096640 = v2;
	}
	if (v2 != *getMemU32Ptr(0x852978, 8) && v22 > *(int*)&dword_5d4594_1096636 && nox_xxx_client_57B400(v2)) {
		if (*getMemU32Ptr(0x8531A0, 2576) && *(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 2251) == 1 &&
			*(uint32_t*)(v2 + 108) == *getMemU32Ptr(0x5D4594, 1096632)) {
			if (!nox_client_spriteUnderCursorXxx_1096644) {
				nox_client_spriteUnderCursorXxx_1096644 = v2;
				dword_5d4594_1096636 = 0;
			}
		} else {
			dword_5d4594_1096636 = v22;
			nox_client_spriteUnderCursorXxx_1096644 = v2;
		}
	}
}

//----- (00477470) --------------------------------------------------------
void nox_video_drawCursorSelectCircle2_477470(uint32_t* a1, int a2, int a3) {
	int v3;   // ebx
	int v4;   // ebx
	int v5;   // esi
	int v6;   // edi
	float v7; // [esp+0h] [ebp-14h]

	if (a3) {
		if (*(uint32_t*)(a3 + 44) == 2) {
			v4 = nox_float2int(*(float*)(a3 + 48));
		} else {
			if (*(uint32_t*)(a3 + 44) != 3) {
				v3 = 6;
			LABEL_8:
				v5 = *a1 + *(uint32_t*)(a3 + 12) - a1[4];
				v6 = *(uint32_t*)(a3 + 16) + a1[1] - a1[5];
				nox_client_drawSetColor_434460(a2);
				nox_client_drawEnableAlpha_434560(1);
				nox_client_drawSetAlpha_434580(0x80u);
				nox_video_drawCircle_4B0B90(v5, v6, v3 - 1);
				nox_video_drawCircle_4B0B90(v5, v6, v3 + 1);
				nox_client_drawEnableAlpha_434560(0);
				nox_video_drawCircle_4B0B90(v5, v6, v3);
				return;
			}
			v7 = *(float*)(a3 + 60) + *(float*)(a3 + 56);
			v4 = nox_float2int(v7) / 2;
		}
		v3 = v4 + 6;
		goto LABEL_8;
	}
}

//----- (00477530) --------------------------------------------------------
unsigned char sub_477530(int a1) {
	unsigned char result; // al

	if (a1 == 1) {
		*getMemU32Ptr(0x5D4594, 1096652) = nox_xxx_bookHideMB_45ACA0(0);
		*getMemU32Ptr(0x5D4594, 1096664) = sub_467C10();
		*getMemU32Ptr(0x5D4594, 1096660) = nox_xxx_guiServerOptionsTryHide_4574D0();
		nox_client_renderGUI_80828 = 0;
		*getMemU32Ptr(0x5D4594, 1096656) = sub_473670();
		if (*getMemU32Ptr(0x5D4594, 1096656) == 1) {
			nox_client_toggleMap_473610();
		}
		nox_gui_console_Hide_4512B0();
		sub_446780();
		sub_4AD9B0(1);
		sub_4C35B0(1);
		sub_46D6F0();
		result = sub_460660();
		*getMemU32Ptr(0x5D4594, 1096672) = 1;
	} else {
		*getMemU32Ptr(0x5D4594, 1096672) = 0;
		if (*getMemU32Ptr(0x5D4594, 1096652)) {
			nox_xxx_bookShowMB_45AD70(0);
		}
		if (*getMemU32Ptr(0x5D4594, 1096664)) {
			sub_467BB0();
		}
		if (*getMemU32Ptr(0x5D4594, 1096660)) {
			nox_xxx_guiServerOptsLoad_457500();
		}
		result = getMemByte(0x5D4594, 1096656);
		if (*getMemU32Ptr(0x5D4594, 1096656)) {
			result = nox_client_toggleMap_473610();
		}
		if (nox_xxx_xxxRenderGUI_587000_80832 == 1) {
			nox_client_renderGUI_80828 = 1;
		}
	}
	return result;
}

//----- (00477600) --------------------------------------------------------
int nox_xxx_guiCursor_477600() { return *getMemU32Ptr(0x5D4594, 1096672); }

//----- (00477610) --------------------------------------------------------
int nox_client_setCursorType_477610(int a1) {
	int result; // eax

	result = a1;
	nox_client_mouseCursorType = a1;
	return result;
}

//----- (00477620) --------------------------------------------------------
int nox_client_getCursorType_477620() { return nox_client_mouseCursorType; }

//----- (00477630) --------------------------------------------------------
int nox_xxx_cursorGetTypePrev_477630() { return nox_xxx_cursorTypePrev_587000_151528; }

#ifndef NOX_CGO
//----- (00477640) --------------------------------------------------------
void nox_xxx_bookSaveSpellForDragDrop_477640(int a1, int a2) {
	nox_client_spellDragnDrop_1097192 = a1;
	nox_client_spellDragnDrop_type_1097196 = a2;
}

//----- (00477660) --------------------------------------------------------
void nox_xxx_bookSpellDnDclear_477660() {
	nox_client_spellDragnDrop_1097192 = 0;
	nox_client_spellDragnDrop_type_1097196 = 0;
}

//----- (00477670) --------------------------------------------------------
int nox_xxx_bookGetSpellDnDType_477670() { return nox_client_spellDragnDrop_type_1097196; }

//----- (00477680) --------------------------------------------------------
nox_drawable* nox_xxx_cursorGetDraggedItem_477680() { return nox_client_itemDragnDrop_1097188; }

//----- (00477690) --------------------------------------------------------
void nox_xxx_cursorSetDraggedItem_477690(nox_drawable* a1) { nox_client_itemDragnDrop_1097188 = a1; }

//----- (004776A0) --------------------------------------------------------
void nox_xxx_cursorResetDraggedItem_4776A0() { nox_client_itemDragnDrop_1097188 = 0; }
#endif // NOX_CGO

//----- (004776B0) --------------------------------------------------------
void nox_xxx_cursorSetTooltip_4776B0(wchar_t* a1) {
	if (a1) {
		if ((int)nox_wcslen(a1) >= 256) {
			nox_wcsncpy((wchar_t*)getMemAt(0x5D4594, 1096676), a1, 0xFFu);
			*getMemU16Ptr(0x5D4594, 1097186) = 0;
		} else {
			nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1096676), a1);
		}
	} else {
		*getMemU16Ptr(0x5D4594, 1096676) = 0;
	}
}

#ifndef NOX_CGO
//----- (00477710) --------------------------------------------------------
char* nox_xxx_cursorLoadAll_477710() {
	memset(getMemAt(0x5D4594, 1097220), 0, 68);
	*getMemU32Ptr(0x5D4594, 1097220) = nox_xxx_gLoadAnim_42FA20("CursorSelect");
	*getMemU32Ptr(0x5D4594, 1097224) = nox_xxx_gLoadAnim_42FA20("CursorGrab");
	*getMemU32Ptr(0x5D4594, 1097228) = nox_xxx_gLoadAnim_42FA20("CursorPickup");
	*getMemU32Ptr(0x5D4594, 1097232) = nox_xxx_gLoadAnim_42FA20("CursorTrade");
	*getMemU32Ptr(0x5D4594, 1097236) = nox_xxx_gLoadAnim_42FA20("CursorTalk");
	*getMemU32Ptr(0x5D4594, 1097240) = nox_xxx_gLoadAnim_42FA20("CursorTarget");
	*getMemU32Ptr(0x5D4594, 1097244) = nox_xxx_gLoadAnim_42FA20("CursorIdentify");
	*getMemU32Ptr(0x5D4594, 1097248) = nox_xxx_gLoadAnim_42FA20("CursorIdentifyNo");
	*getMemU32Ptr(0x5D4594, 1097252) = nox_xxx_gLoadAnim_42FA20("CursorRepair");
	*getMemU32Ptr(0x5D4594, 1097256) = nox_xxx_gLoadAnim_42FA20("CursorCreateGame");
	*getMemU32Ptr(0x5D4594, 1097260) = nox_xxx_gLoadAnim_42FA20("CursorBusy");
	*getMemU32Ptr(0x5D4594, 1097264) = nox_xxx_gLoadAnim_42FA20("CursorBuy");
	*getMemU32Ptr(0x5D4594, 1097268) = nox_xxx_gLoadAnim_42FA20("CursorSell");
	*getMemU32Ptr(0x5D4594, 1097272) = nox_xxx_gLoadAnim_42FA20("CursorUse");
	*getMemU32Ptr(0x5D4594, 1097276) = nox_xxx_gLoadAnim_42FA20("CursorMove");
	*getMemU32Ptr(0x5D4594, 1097280) = nox_xxx_gLoadAnim_42FA20("CursorPickupFar");
	*getMemU32Ptr(0x5D4594, 1097284) = nox_xxx_gLoadAnim_42FA20("CursorCaution");
	return 1;
}

//----- (00477830) --------------------------------------------------------
void nox_client_drawCursorAndTooltips_477830() {
	char* v1;   // eax
	int v2;     // eax
	int v4;     // esi
	int v5;     // edi
	int v6;     // eax
	int v7;     // [esp+Ch] [ebp-3Ch]
	int v8;     // [esp+10h] [ebp-38h]
	int v9[13]; // [esp+14h] [ebp-34h]

	if (!*getMemU32Ptr(0x5D4594, 1097220)) {
		nox_xxx_cursorLoadAll_477710();
	}
	nox_point mpos = nox_client_getMousePos_4309F0();
	v9[0] = 0;
	v9[1] = 0;
	v9[2] = nox_win_width;
	v9[3] = nox_win_height;
	v9[8] = nox_win_width;
	v9[9] = nox_win_height;
	v9[4] = 0;
	v9[5] = 0;
	*getMemU32Ptr(0x5D4594, 1097204) = 0;
	dword_5d4594_1097208 = nox_xxx_guiFontHeightMB_43F320(0) + 4;
	if (nox_client_itemDragnDrop_1097188) // Dragging item
	{
		*(uint32_t*)((uint32_t)nox_client_itemDragnDrop_1097188 + 12) = mpos.x;
		*(uint32_t*)((uint32_t)nox_client_itemDragnDrop_1097188 + 16) = mpos.y;
		(*(void (**)(int*, uint32_t))((uint32_t)nox_client_itemDragnDrop_1097188 + 300))(
			v9, nox_client_itemDragnDrop_1097188);
	}
	if (nox_client_spellDragnDrop_1097192) // Player is dragging spell or ability
	{
		v1 = nox_common_playerInfoGetByID_417040(nox_player_netCode_85319C);
		if (!v1 || v1[2251]) {
			v2 = nox_xxx_spellIcon_424A90(nox_client_spellDragnDrop_1097192); // Spell icon
			if (v2) {
				nox_client_drawImageAt_47D2C0(v2, mpos.x - 15, mpos.y - 15);
			}
		} else {
			v2 = nox_xxx_spellGetAbilityIcon_425310(nox_client_spellDragnDrop_1097192, 0); // Ability icon
			if (v2) {
				nox_client_drawImageAt_47D2C0(v2, mpos.x - 15, mpos.y - 15);
			}
		}
	}
	nox_video_cursorDrawImpl_477A30(*getMemIntPtr(0x5D4594, 2523948), mpos.x, mpos.y);
	if (*getMemU16Ptr(0x5D4594, 1096676) && nox_client_showTooltips_80840 == 1) {
		nox_xxx_drawGetStringSize_43F840(0, getMemU16Ptr(0x5D4594, 1096676), &v8, &v7, 0);
		v4 = mpos.x - *getMemU32Ptr(0x5D4594, 1097204);
		v5 = mpos.y - dword_5d4594_1097208;
		v6 = v7 + 4;
		v7 += 4;
		if (v4 + v8 + 4 >= nox_win_width) {
			v4 -= v8;
		}
		if (v4 < 0) {
			v4 = 0;
		}
		if (v5 + v6 < nox_win_height) {
			if (v5 < 0) {
				v5 = 0;
			}
		} else {
			v5 = nox_win_height - v6;
		}
		nox_client_drawRectFilledAlpha_49CF10(v4, v5, v8 + 4, v6);
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2589772));
		nox_xxx_drawStringWrap_43FAF0(0, getMemAt(0x5D4594, 1096676), v4 + 2, v5 + 2, 0, 0);
		if (dword_5d4594_3799468) {
			nox_draw_viewport_t* rdr = nox_draw_getViewport_437250();
			if (v4 < rdr->x1 || v4 + v8 + 4 > rdr->x2 || v5 < rdr->y1 || v7 + v5 > rdr->y2) {
				dword_5d4594_3799524 = 1;
			}
		}
	}
}

//----- (00477EA0) --------------------------------------------------------
int sub_477EA0() {
	nox_point mpos = nox_client_getMousePos_4309F0();
	int x = mpos.x;
	int y = mpos.y + 22;
	nox_video_cursorDrawImpl_477A30(*getMemIntPtr(0x85B3FC, 952), x, y);
	sub_477EF0(*getMemIntPtr(0x852978, 4), --x, y);
	return sub_477EF0(*getMemIntPtr(0x852978, 4), x + 2, y);
}

//----- (00477EF0) --------------------------------------------------------
int sub_477EF0(int a1, int a2, int a3) {
	if (nox_client_mouseCursorType == 2) {
		return nox_xxx_spriteDrawCircleMB_4C32A0(a2, a3, 5 - nox_frame_xxx_2598000 % 5u, a1);
	}
	nox_client_drawSetColor_434460(a1);
	nox_client_drawEnableAlpha_434560(1);
	nox_client_drawAddPoint_49F500(a2 - 4, a3 - 4);
	nox_xxx_rasterPointRel_49F570(8, 8);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(a2 + 4, a3 - 4);
	nox_xxx_rasterPointRel_49F570(-8, 8);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawEnableAlpha_434560(0);
	return 1;
}

//----- (00477F80) --------------------------------------------------------
void sub_477F80() {
	if (!nox_video_cursorDrawIsThreaded) {
		if (dword_5d4594_3799468) {
			nox_draw_viewport_t* rdr = nox_draw_getViewport_437250();
			if (dword_5d4594_1097212 < rdr->x1 || dword_5d4594_1097212 + 64 >= rdr->x2 ||
				dword_5d4594_1097216 < rdr->y1 || dword_5d4594_1097216 + 64 >= rdr->y2) {
				nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 952));
				nox_client_drawRectFilledOpaque_49CE30(dword_5d4594_1097212 + 32, dword_5d4594_1097216 + 32, 64, 64);
			}
		}
	}
}

//----- (00477FF0) --------------------------------------------------------
int sub_477FF0() { return sub_4BE7B0(*getMemIntPtr(0x5D4594, 1097260)); }

//----- (00478000) --------------------------------------------------------
int sub_478000() {
	int result; // eax
	int v1;     // eax

	sub_467CD0();
	result = nox_client_spellDragnDrop_type_1097196;
	if (nox_client_spellDragnDrop_type_1097196) {
		v1 = nox_xxx_wndGetCaptureMain_46AE00();
		nox_xxx_wndClearCaptureMain_46ADE0(v1);
		nox_xxx_bookSpellDnDclear_477660();
	}
	return result;
}
#endif // NOX_CGO

//----- (00478030) --------------------------------------------------------
int sub_478030() { return dword_5d4594_1098624; }

//----- (00478040) --------------------------------------------------------
int sub_478040() {
	short v2; // [esp+0h] [ebp-2h]

	if (!dword_5d4594_1098624) {
		return 0;
	}
	v2 = 4809;
	nox_netlist_addToMsgListCli_40EBC0(31, 0, &v2, 2);
	sub_467680();
	return 1;
}

//----- (00478080) --------------------------------------------------------
int sub_478080(int a1) {
	char* v1;   // eax
	int result; // eax

	if (dword_5d4594_1098624 && (v1 = sub_4780A0(a1)) != 0) {
		result = *(uint32_t*)v1;
	} else {
		result = 0;
	}
	return result;
}

//----- (004780A0) --------------------------------------------------------
char* sub_4780A0(int a1) {
	int v1;            // ebp
	unsigned char* v2; // edi
	int v3;            // esi
	unsigned char* v4; // edx
	int v5;            // eax
	unsigned char* v6; // ecx

	v1 = 0;
	v2 = getMemAt(0x5D4594, 1098644);
	while (1) {
		v3 = 0;
		v4 = v2;
		do {
			if (*((uint32_t*)v4 - 1)) {
				v5 = 0;
				v6 = v4;
				while (*(uint32_t*)v6 != a1) {
					++v5;
					v6 += 4;
					if (v5 >= 32) {
						goto LABEL_7;
					}
				}
				return (char*)getMemAt(0x5D4594, 1098636 + 140 * (v1 + 10 * v3));
			}
		LABEL_7:
			++v3;
			v4 += 1400;
		} while (v3 < 6);
		v2 += 140;
		++v1;
		if ((int)v2 < (int)getMemAt(0x5D4594, 1100044)) {
			continue;
		}
		return 0;
	}
}

//----- (00478110) --------------------------------------------------------
int sub_478110() {
	uint32_t* v0;      // eax
	int result;        // eax
	uint32_t* v2;      // eax
	unsigned char* v3; // edx
	unsigned char* v4; // eax
	int v5;            // ecx
	uint32_t* v6;      // esi
	int v7;            // [esp+4h] [ebp-8h]
	int v8;            // [esp+8h] [ebp-4h]

	*getMemU32Ptr(0x5D4594, 1098500) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1098504) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1098524) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1098492) = 0;
	*getMemU32Ptr(0x5D4594, 1098496) = 0;
	*getMemU32Ptr(0x5D4594, 1098528) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1098508) = 0;
	*getMemU32Ptr(0x5D4594, 1098512) = 0;
	v0 = nox_new_window_from_file("Shop.wnd", sub_478480);
	dword_5d4594_1098576 = v0;
	if (!v0) {
		return 0;
	}
	nox_window_set_all_funcs(v0, sub_478650, sub_478970, 0);
	v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1098576, 3806);
	nox_gui_winSetFunc96_46B070((int)v2, sub_478E50);
	v3 = getMemAt(0x5D4594, 1098636);
	do {
		v4 = v3;
		v5 = 6;
		do {
			*(uint32_t*)v4 = 0;
			v4 += 1400;
			--v5;
		} while (v5);
		v3 += 140;
	} while ((int)v3 < (int)getMemAt(0x5D4594, 1100036));
	sub_478F10();
	nox_window_get_size(*(int*)&dword_5d4594_1098576, &v8, &v7);
	nox_window_setPos_46A9B0(*(uint32_t**)&dword_5d4594_1098576, nox_win_width - v8, nox_win_height - v7);
	nox_window_set_hidden(*(int*)&dword_5d4594_1098576, 1);
	nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1098576, 0);
	*getMemU32Ptr(0x5D4594, 1098400) = nox_xxx_gLoadImg_42F970("ShopBase");
	*getMemU32Ptr(0x5D4594, 1098404) = nox_xxx_gLoadImg_42F970("ShopTradeMode");
	*getMemU32Ptr(0x5D4594, 1098408) = nox_xxx_gLoadImg_42F970("ShopIdentifyMode");
	*getMemU32Ptr(0x5D4594, 1098412) = nox_xxx_gLoadImg_42F970("ShopRepairMode");
	*getMemU32Ptr(0x5D4594, 1098416) = nox_xxx_gLoadImg_42F970("ShopRepairMode");
	*getMemU32Ptr(0x5D4594, 1098420) = nox_xxx_gLoadImg_42F970("ShopExitMode");
	*getMemU32Ptr(0x5D4594, 1098424) = nox_xxx_gLoadImg_42F970("ShopInventoryBar1");
	*getMemU32Ptr(0x5D4594, 1098428) = nox_xxx_gLoadImg_42F970("ShopInventoryBar2");
	*getMemU32Ptr(0x5D4594, 1098432) = nox_xxx_gLoadImg_42F970("ShopInventorySlider");
	*getMemU32Ptr(0x5D4594, 1098436) = nox_xxx_gLoadImg_42F970("ShopInventorySliderSelected");
	*getMemU32Ptr(0x5D4594, 1098448) = nox_xxx_gLoadImg_42F970("ShopInventoryUp");
	*getMemU32Ptr(0x5D4594, 1098452) = nox_xxx_gLoadImg_42F970("ShopInventoryUpSelected");
	*getMemU32Ptr(0x5D4594, 1098440) = nox_xxx_gLoadImg_42F970("ShopInventorydown");
	*getMemU32Ptr(0x5D4594, 1098444) = nox_xxx_gLoadImg_42F970("ShopInventorydownSelected");
	dword_5d4594_1098456 = nox_xxx_gLoadImg_42F970("ShopTextBorder");
	*getMemU32Ptr(0x5D4594, 1098460) = nox_xxx_gLoadImg_42F970("ShopkeeperPic");
	*getMemU32Ptr(0x5D4594, 1098464) = nox_xxx_gLoadImg_42F970("ShopkeeperWarriorPic");
	*getMemU32Ptr(0x5D4594, 1098468) = nox_xxx_gLoadImg_42F970("ShopkeeperConjurerPic");
	*getMemU32Ptr(0x5D4594, 1098472) = nox_xxx_gLoadImg_42F970("ShopkeeperWizardPic");
	*getMemU32Ptr(0x5D4594, 1098476) = nox_xxx_gLoadImg_42F970("ShopkeeperLandOfTheDeadPic");
	*getMemU32Ptr(0x5D4594, 1098480) = nox_xxx_gLoadImg_42F970("ShopkeeperMagicShopPic");
	dword_5d4594_1098580 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1098576, 3807);
	*getMemU32Ptr(0x5D4594, 1098584) = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1098576, 3808);
	*getMemU32Ptr(0x5D4594, 1098588) = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1098576, 3809);
	v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1098576, 3806);
	nox_client_wndGetPosition_46AA60(v6, getMemAt(0x5D4594, 1098380), getMemAt(0x5D4594, 1098384));
	nox_window_get_size((int)v6, getMemAt(0x5D4594, 1098388), getMemAt(0x5D4594, 1098392));
	*getMemU32Ptr(0x5D4594, 1098388) += *getMemU32Ptr(0x5D4594, 1098380);
	*getMemU32Ptr(0x5D4594, 1098392) += *getMemU32Ptr(0x5D4594, 1098384);
	*(uint32_t*)(*(uint32_t*)(dword_5d4594_1098580 + 400) + 8) = 16;
	*(uint32_t*)(*(uint32_t*)(dword_5d4594_1098580 + 400) + 12) = 12;
	nox_xxx_wndSetOffsetMB_46AE40(*(uint32_t*)(dword_5d4594_1098580 + 400), 0, -15);
	sub_4B5700(*(int*)&dword_5d4594_1098580, 0, 0, *getMemIntPtr(0x5D4594, 1098432), *getMemIntPtr(0x5D4594, 1098436),
			   *getMemIntPtr(0x5D4594, 1098436));
	result = 1;
	dword_5d4594_1098592 = *(uint32_t*)(*(uint32_t*)(dword_5d4594_1098580 + 32) + 4);
	return result;
}

//----- (00478480) --------------------------------------------------------
int sub_478480(int a1, int a2, int* a3, int a4) {
	int result; // eax
	int v5;     // esi
	int v7;     // ecx
	int v8;     // ecx

	if (a2 != 16391) {
		if (a2 == 16393) {
			dword_5d4594_1107036 = dword_5d4594_1098592 - a4;
			return 0;
		}
		return 0;
	}
	if (sub_45D9B0()) {
		return 0;
	}
	v5 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	switch (v5) {
	case 3801:
		if (!dword_5d4594_1098624) {
			return 0;
		}
		sub_478040();
		result = 0;
		break;
	case 3802:
		if (!dword_5d4594_1098624) {
			return 0;
		}
		if (dword_5d4594_1098628 == 4) {
			sub_467680();
		}
		nox_client_setCursorType_477610(12);
		dword_5d4594_1098628 = 3;
		if (sub_467C80()) {
			return 0;
		}
		sub_467BB0();
		result = 0;
		break;
	case 3803:
		if (!dword_5d4594_1098624) {
			return 0;
		}
		sub_467650();
		dword_5d4594_1098628 = 4;
		result = 0;
		break;
	case 3804:
		if (dword_5d4594_1098624) {
			if (dword_5d4594_1098628 == 4) {
				sub_467680();
			}
			nox_client_setCursorType_477610(11);
			dword_5d4594_1098628 = 2;
		}
		return 0;
	case 3808:
		if (*(int*)&dword_5d4594_1107036 - 50 >= 0) {
			v8 = dword_5d4594_1107036 - 50 - (dword_5d4594_1107036 - 50) % 50;
		} else {
			v8 = 0;
		}
		dword_5d4594_1107036 = v8;
		nox_window_call_field_94(*(int*)&dword_5d4594_1098580, 16394, dword_5d4594_1098592 - v8, 0);
		result = 0;
		break;
	case 3809:
		if (*(int*)&dword_5d4594_1107036 + 50 <= *(int*)&dword_5d4594_1098592) {
			v7 = dword_5d4594_1107036 + 50 - (dword_5d4594_1107036 + 50) % 50;
			dword_5d4594_1107036 = dword_5d4594_1107036 + 50 - (dword_5d4594_1107036 + 50) % 50;
		} else {
			v7 = dword_5d4594_1098592;
			dword_5d4594_1107036 = dword_5d4594_1098592;
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_1098580, 16394, dword_5d4594_1098592 - v7, 0);
		result = 0;
		break;
	default:
		return 0;
	}
	return result;
}
// 478585: variable 'v6' is possibly undefined

//----- (00478650) --------------------------------------------------------
int sub_478650(int a1, int a2, unsigned int a3) {
	int v4;  // eax
	int2 v5; // [esp+0h] [ebp-8h]

	v5.field_0 = (unsigned short)a3;
	v5.field_4 = a3 >> 16;
	if (!sub_45D9B0()) {
		switch (a2) {
		case 5:
			v4 = sub_4281F0(&v5, (int4*)getMemAt(0x5D4594, 1098380));
			if (v4) {
				if (dword_5d4594_1098628 == 2) {
					sub_478730(&v5.field_0);
				}
			}
			break;
		case 19:
			if (dword_5d4594_1098628 == 2) {
				nox_window_call_field_94(*(int*)&dword_5d4594_1098576, 16391, *getMemIntPtr(0x5D4594, 1098584), 0);
				return 1;
			}
			break;
		case 20:
			if (dword_5d4594_1098628 == 2) {
				nox_window_call_field_94(*(int*)&dword_5d4594_1098576, 16391, *getMemIntPtr(0x5D4594, 1098588), 0);
				return 1;
			}
			break;
		default:
			return 0;
		}
	}
	return 1;
}
// 478703: variable 'v4' is possibly undefined

//----- (00478850) --------------------------------------------------------
void sub_478850(int a1, short a2, int a3, int a4) {
	if (a4) {
		if (a4 == 1) {
			nox_client_tradeXxxBuyAccept_478880(a3, a2);
		} else {
			sub_4788F0(a3, a4);
		}
	}
}

//----- (00478970) --------------------------------------------------------
int sub_478970() {
	int result; // eax
	int2 a1;    // [esp+0h] [ebp-8h]

	a1.field_0 = nox_win_width - NOX_DEFAULT_WIDTH;
	a1.field_4 = nox_win_height - NOX_DEFAULT_HEIGHT;
	nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1098400), nox_win_width - NOX_DEFAULT_WIDTH,
								  nox_win_height - NOX_DEFAULT_HEIGHT);
	if (dword_5d4594_1098628 == 2) {
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1098404), a1.field_0, a1.field_4);
		sub_478C80();
		result = 1;
	} else if (dword_5d4594_1098628 == 3) {
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1098408), a1.field_0, a1.field_4);
		sub_478B10(&a1);
		result = 1;
	} else if (dword_5d4594_1098628 == 1) {
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1098412), a1.field_0, a1.field_4);
		sub_478A70(&a1);
		result = 1;
	} else {
		if (dword_5d4594_1098628 == 4) {
			nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1098416), a1.field_0, a1.field_4);
			sub_478BC0(&a1.field_0);
		}
		result = 1;
	}
	return result;
}

//----- (00478A70) --------------------------------------------------------
int sub_478A70(int2* a1) {
	uint32_t* v1; // esi
	int result;   // eax
	int v3;       // [esp+4h] [ebp-10h]
	int v4;       // [esp+8h] [ebp-Ch]
	int v5;       // [esp+Ch] [ebp-8h]
	int v6;       // [esp+10h] [ebp-4h]

	v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1098576, 3806);
	nox_client_wndGetPosition_46AA60(v1, &v5, &v6);
	nox_window_get_size((int)v1, &v4, &v3);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	nox_client_drawImageAt_47D2C0(dword_5d4594_1098456, a1->field_0, a1->field_4);
	result = dword_5d4594_1098604;
	if (dword_5d4594_1098604) {
		result = nox_xxx_drawStringWrap_43FAF0(0, *(uint16_t**)&dword_5d4594_1098604, v5 + 8, v6 + 8, v4 - 16, v3 - 16);
	}
	return result;
}

//----- (00478C80) --------------------------------------------------------
int sub_478C80() {
	int v0;            // edi
	int v1;            // ebx
	unsigned char* v2; // esi
	int v3;            // edi
	int v4;            // ebp
	int v6;            // [esp+10h] [ebp-58h]
	unsigned char* v7; // [esp+14h] [ebp-54h]
	unsigned int v8;   // [esp+18h] [ebp-50h]
	int v9;            // [esp+1Ch] [ebp-4Ch]
	int v10;           // [esp+20h] [ebp-48h]
	wchar_t v11[32];   // [esp+28h] [ebp-40h]

	v8 = sub_4674A0();
	nox_xxx_wndDraw_49F7F0();
	nox_client_copyRect_49F6F0(*getMemIntPtr(0x5D4594, 1098380), *getMemIntPtr(0x5D4594, 1098384),
							   *getMemU32Ptr(0x5D4594, 1098388) - *getMemU32Ptr(0x5D4594, 1098380),
							   *getMemU32Ptr(0x5D4594, 1098392) - *getMemU32Ptr(0x5D4594, 1098384));
	v0 = *getMemU32Ptr(0x5D4594, 1098380);
	v10 = *getMemU32Ptr(0x5D4594, 1098380);
	v1 = *getMemU32Ptr(0x5D4594, 1098384) - dword_5d4594_1107036;
	v2 = getMemAt(0x5D4594, 1098640);
	v9 = nox_xxx_guiFontHeightMB_43F320(0);
	v6 = 0;
	v7 = getMemAt(0x5D4594, 1098640);
	do {
		if (v1 > *getMemIntPtr(0x5D4594, 1098384) - 50) {
			nox_client_drawImageAt_47D2C0(*getMemU32Ptr(0x5D4594, 1098424 + 4 * (v6 % 2)), v0, v1);
			v3 = v0 + 5;
			v4 = 6;
			do {
				if (*(uint32_t*)v2) {
					*(uint32_t*)(*((uint32_t*)v2 - 1) + 12) = v3 + 20;
					*(uint32_t*)(*((uint32_t*)v2 - 1) + 16) = v1 + 25;
					(*(void (**)(unsigned char*, uint32_t))(*((uint32_t*)v2 - 1) + 300))(getMemAt(0x5D4594, 1098492),
																						 *((uint32_t*)v2 - 1));
					if (v8 < *((uint32_t*)v2 + 33)) {
						nox_client_drawRectFilledAlpha_49CF10(v3 - 5, v1, 50, 50);
					}
					if (*(uint32_t*)v2 > 1u) {
						nox_swprintf(v11, L"%d", *(uint32_t*)v2);
						nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
						nox_xxx_drawStringWrap_43FAF0(0, v11, v3, v1 + 5, 320, 0);
					}
					nox_swprintf(v11, L"%d", *((uint32_t*)v2 + 33));
					nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2589772));
					nox_xxx_drawStringWrap_43FAF0(0, v11, v3, v1 - v9 + 45, 320, 0);
				}
				v3 += 50;
				v2 += 1400;
				--v4;
			} while (v4);
			v2 = v7;
			v0 = v10;
		}
		v1 += 50;
		if (v1 >= *getMemIntPtr(0x5D4594, 1098392)) {
			break;
		}
		v2 += 140;
		++v6;
		v7 = v2;
	} while ((int)v2 < (int)getMemAt(0x5D4594, 1100040));
	return sub_49F860();
}

//----- (00478E50) --------------------------------------------------------
int sub_478E50(int a1, int a2, unsigned int a3) {
	int v3;       // ecx
	int v4;       // edx
	int v5;       // edx
	wchar_t** v6; // eax
	wchar_t* v7;  // eax

	if (dword_5d4594_1098628 == 2) {
		v3 = ((unsigned short)a3 - *getMemU32Ptr(0x5D4594, 1098380)) / 50;
		v4 = (int)((a3 >> 16) - *getMemU32Ptr(0x5D4594, 1098384) + dword_5d4594_1107036) / 50;
		if (v3 >= 6) {
			v3 = 5;
		}
		if (v4 >= 10) {
			v4 = 9;
		}
		v5 = 35 * (v4 + 10 * v3);
		v6 = (wchar_t**)getMemAt(0x5D4594, 1098636 + 4 * v5);
		if (*getMemU32Ptr(0x5D4594, 1098640 + 4 * v5)) {
			*((uint32_t*)*v6 + 32) = v6[2];
			v7 = nox_xxx_clientAskInfoMb_4BF050(*v6);
			nox_xxx_cursorSetTooltip_4776B0(v7);
		}
	}
	return 1;
}

//----- (00478F10) --------------------------------------------------------
uint32_t* sub_478F10() {
	unsigned char* v0; // esi
	int v1;            // ebx
	void* v2;          // edi
	uint32_t* result;  // eax
	unsigned char* v4; // [esp+10h] [ebp-4h]

	v4 = getMemAt(0x5D4594, 1098636);
	do {
		v0 = v4;
		v1 = 6;
		do {
			if (*(uint32_t*)v0) {
				nox_xxx_spriteDelete_45A4B0(*(uint64_t**)v0);
			}
			*(uint32_t*)v0 = 0;
			v2 = v0 + 8;
			*((uint32_t*)v0 + 1) = 0;
			v0 += 1400;
			memset(v2, 0, 0x80u);
			*((uint32_t*)v0 - 316) = 0;
			--v1;
		} while (v1);
		result = v4 + 140;
		v4 += 140;
	} while ((int)v4 < (int)getMemAt(0x5D4594, 1100036));
	dword_5d4594_1107036 = 0;
	return result;
}

//----- (00478F80) --------------------------------------------------------
int sub_478F80() {
	int result; // eax

	sub_478F10();
	sub_44D8F0();
	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1098576);
	result = 0;
	dword_5d4594_1098576 = 0;
	dword_5d4594_1098624 = 0;
	dword_5d4594_1098628 = 1;
	dword_5d4594_1098596 = 0;
	dword_5d4594_1098600 = 0;
	dword_5d4594_1098604 = 0;
	*getMemU32Ptr(0x5D4594, 1098608) = 0;
	dword_5d4594_1098616 = 0;
	return result;
}

//----- (004790F0) --------------------------------------------------------
char* nox_xxx_getShopPic_4790F0(int a1) {
	uint32_t* v1; // esi
	char* result; // eax

	v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1098576, 3805);
	if (!*getMemU32Ptr(0x5D4594, 1107040)) {
		*getMemU32Ptr(0x5D4594, 1098396) = nox_xxx_getTTByNameSpriteMB_44CFC0("Shopkeeper");
		*getMemU32Ptr(0x5D4594, 1098560) = nox_xxx_getTTByNameSpriteMB_44CFC0("ShopkeeperWarriorsRealm");
		*getMemU32Ptr(0x5D4594, 1098556) = nox_xxx_getTTByNameSpriteMB_44CFC0("ShopkeeperConjurerRealm");
		*getMemU32Ptr(0x5D4594, 1098564) = nox_xxx_getTTByNameSpriteMB_44CFC0("ShopkeeperWizardRealm");
		*getMemU32Ptr(0x5D4594, 1098572) = nox_xxx_getTTByNameSpriteMB_44CFC0("ShopkeeperLandOfTheDead");
		*getMemU32Ptr(0x5D4594, 1098568) = nox_xxx_getTTByNameSpriteMB_44CFC0("ShopkeeperMagicShop");
		*getMemU32Ptr(0x5D4594, 1098484) = nox_xxx_getTTByNameSpriteMB_44CFC0("ShopkeeperPurple");
		*getMemU32Ptr(0x5D4594, 1097292) = nox_xxx_getTTByNameSpriteMB_44CFC0("ShopkeeperYellow");
		*getMemU32Ptr(0x5D4594, 1107040) = 1;
	}
	if (a1 == *getMemU32Ptr(0x5D4594, 1098396)) {
		result = nox_xxx_gLoadImg_42F970("ShopKeeperPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098560)) {
		result = nox_xxx_gLoadImg_42F970("ShopKeeperWarriorPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098556)) {
		result = nox_xxx_gLoadImg_42F970("ShopKeeperConjurerPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098564)) {
		result = nox_xxx_gLoadImg_42F970("ShopKeeperWizardPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098572)) {
		result = nox_xxx_gLoadImg_42F970("ShopKeeperLandOfTheDeadPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098568)) {
		result = nox_xxx_gLoadImg_42F970("ShopKeeperMagicShopPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098484)) {
		result = nox_xxx_gLoadImg_42F970("ShopKeeperPurplePic");
		v1[15] = result;
	} else {
		if (a1 == *getMemU32Ptr(0x5D4594, 1097292)) {
			result = nox_xxx_gLoadImg_42F970("ShopKeeperBrownPic");
		} else {
			result = nox_xxx_gLoadImg_42F970("ShopKeeperPic");
		}
		v1[15] = result;
	}
	return result;
}

//----- (00479280) --------------------------------------------------------
int sub_479280() {
	int result; // eax

	result = dword_5d4594_1098624;
	if (dword_5d4594_1098624) {
		sub_467680();
		dword_5d4594_1098624 = 0;
		dword_5d4594_1098628 = 0;
		sub_478F10();
		sub_44D8F0();
		nox_window_set_hidden(*(int*)&dword_5d4594_1098576, 1);
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1098576, 0);
		sub_467C10();
		nox_client_setCursorType_477610(0);
		result = nox_client_renderGUI_80828;
		if (!nox_client_renderGUI_80828 && *getMemU32Ptr(0x5D4594, 1098612) == 1) {
			nox_client_renderGUI_80828 = 1;
		}
	}
	return result;
}

//----- (00479300) --------------------------------------------------------
uint32_t* sub_479300(int a1, int a2, int a3, short a4, int a5) {
	uint32_t* result; // eax
	uint32_t* v6;     // ebx
	int* v7;          // edi
	int i;            // esi

	result = sub_4793C0(a1);
	v6 = result;
	if (result) {
		if (!*result) {
			result = nox_new_drawable_for_thing(a1);
			*v6 = result;
			if (!result) {
				return result;
			}
			result[30] |= 0x40000000u;
			*(uint16_t*)(*v6 + 294) = a4;
			*(uint16_t*)(*v6 + 292) = a4;
			if (*(uint32_t*)(*v6 + 112) & 0x13001000) {
				v7 = (int*)(*v6 + 432);
				for (i = 0; i < 4; ++i) {
					if (*(char*)(i + a5) == -1) {
						*v7 = 0;
					} else {
						*v7 = nox_xxx_modifGetDescById_413330(*(unsigned char*)(i + a5));
					}
					++v7;
				}
			}
			v6[1] = 0;
		}
		v6[v6[1] + 2] = a2;
		result = (uint32_t*)(v6[1] + 1);
		v6[34] = a3;
		v6[1] = result;
	}
	return result;
}

//----- (004793C0) --------------------------------------------------------
char* sub_4793C0(int a1) {
	int v1;            // ebx
	unsigned char* v2; // esi
	int v3;            // ecx
	unsigned char* v4; // eax

	v1 = 0;
	v2 = getMemAt(0x5D4594, 1098636);
	while (1) {
		v3 = 0;
		v4 = v2;
		do {
			if (*((uint32_t*)v4 + 1) && *(uint32_t*)(*(uint32_t*)v4 + 108) == a1 &&
				!(*(uint32_t*)(*(uint32_t*)v4 + 112) & 0x4000000)) {
				return (char*)getMemAt(0x5D4594, 1098636 + 140 * (v1 + 10 * v3));
			}
			++v3;
			v4 += 1400;
		} while (v3 < 6);
		v2 += 140;
		++v1;
		if ((int)v2 < (int)getMemAt(0x5D4594, 1100036)) {
			continue;
		}
		break;
	}
	return sub_479430();
}

//----- (00479430) --------------------------------------------------------
char* sub_479430() {
	int v0;            // esi
	unsigned char* v1; // edx
	int v2;            // eax
	unsigned char* v3; // ecx

	v0 = 0;
	v1 = getMemAt(0x5D4594, 1098640);
	while (1) {
		v2 = 0;
		v3 = v1;
		do {
			if (!*(uint32_t*)v3) {
				return (char*)getMemAt(0x5D4594, 1098636 + 140 * (v0 + 10 * v2));
			}
			++v2;
			v3 += 1400;
		} while (v2 < 6);
		v1 += 140;
		++v0;
		if ((int)v1 < (int)getMemAt(0x5D4594, 1100040)) {
			continue;
		}
		break;
	}
	return 0;
}

//----- (00479480) --------------------------------------------------------
char* sub_479480(int a1) {
	char* result; // eax
	char* v2;     // esi

	result = sub_4780A0(a1);
	v2 = result;
	if (result) {
		sub_4794D0((int)result, a1);
		result = (char*)(*((uint32_t*)v2 + 1) - 1);
		*((uint32_t*)v2 + 1) = result;
		if (!result) {
			result = (char*)nox_xxx_spriteDelete_45A4B0(*(uint64_t**)v2);
			*(uint32_t*)v2 = 0;
			*((uint32_t*)v2 + 34) = 0;
		}
	}
	return result;
}

//----- (004794D0) --------------------------------------------------------
int sub_4794D0(int a1, int a2) {
	int result;   // eax
	uint32_t* i;  // ecx
	uint32_t* v4; // ecx
	int v5;       // edx

	result = 0;
	for (i = (uint32_t*)(a1 + 8); *i != a2; ++i) {
		if (++result >= 32) {
			return result;
		}
	}
	if (result < 31) {
		v4 = (uint32_t*)(a1 + 4 * result + 8);
		v5 = 31 - result;
		do {
			result = v4[1];
			*v4 = result;
			++v4;
			--v5;
		} while (v5);
	}
	*(uint32_t*)(a1 + 132) = 0;
	return result;
}

//----- (00479590) --------------------------------------------------------
int sub_479590() { return dword_5d4594_1098628; }

//----- (004795A0) --------------------------------------------------------
void sub_4795A0(int a1) {
	if (dword_5d4594_1098628 == 4) {
		if (a1 != 4) {
			sub_467680();
		}
		dword_5d4594_1098628 = a1;
	} else {
		dword_5d4594_1098628 = a1;
	}
}

//----- (00479690) --------------------------------------------------------
int sub_479690(int a1, short a2, short a3, int a4) {
	int result; // eax

	result = a4;
	dword_5d4594_1098616 = 0;
	if (a4) {
		if (a4 == 1) {
			result = nox_client_tradeXxxSellAccept_4796D0(a2);
		} else {
			result = sub_479700(a3, a4);
		}
	}
	return result;
}

//----- (004796D0) --------------------------------------------------------
int nox_client_tradeXxxSellAccept_4796D0(short a1) {
	char v2[4]; // [esp+0h] [ebp-4h]

	v2[0] = -55;
	v2[1] = 24;
	*(uint16_t*)&v2[2] = a1;
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, v2, 4);
}

//----- (00479700) --------------------------------------------------------
int sub_479700(short a1, char a2) {
	char v3[5]; // [esp+0h] [ebp-8h]

	v3[0] = -55;
	v3[1] = 25;
	*(uint16_t*)&v3[2] = a1;
	v3[4] = a2;
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, v3, 5);
}

//----- (00479810) --------------------------------------------------------
void sub_479810() { dword_5d4594_1098620 = 0; }

//----- (00479820) --------------------------------------------------------
int sub_479820(int a1, short a2) {
	int result; // eax

	result = sub_479840(a2);
	dword_5d4594_1098620 = 0;
	return result;
}

//----- (00479840) --------------------------------------------------------
int sub_479840(short a1) {
	char v2[4]; // [esp+0h] [ebp-4h]

	v2[0] = -55;
	v2[1] = 26;
	*(uint16_t*)&v2[2] = a1;
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, v2, 4);
}

//----- (00479870) --------------------------------------------------------
int sub_479870() { return dword_5d4594_1098628 == 2; }

//----- (00479880) --------------------------------------------------------
bool sub_479880(uint32_t* a1) { return sub_4281F0((int2*)a1, (int4*)getMemAt(0x5D4594, 1098380)); }

//----- (004798A0) --------------------------------------------------------
int sub_4798A0(uint32_t* a1) {
	int v1;            // eax
	int v2;            // ecx
	int v3;            // edx
	int v4;            // edx
	unsigned char* v5; // eax

	v1 = sub_4281F0((int2*)a1, (int4*)getMemAt(0x5D4594, 1098380));
	if (!v1) {
		return 0;
	}
	v2 = (*a1 - *getMemU32Ptr(0x5D4594, 1098380)) / 50;
	v3 = (a1[1] - *getMemU32Ptr(0x5D4594, 1098384) + dword_5d4594_1107036) / 50;
	if (v2 >= 6) {
		v2 = 5;
	}
	if (v3 >= 10) {
		v3 = 9;
	}
	v4 = 35 * (v3 + 10 * v2);
	v5 = getMemAt(0x5D4594, 1098636 + 4 * v4);
	if (!*getMemU32Ptr(0x5D4594, 1098640 + 4 * v4)) {
		return 0;
	}
	*(uint32_t*)(*(uint32_t*)v5 + 128) = *((uint32_t*)v5 + 2);
	return *(uint32_t*)v5;
}
// 4798B5: variable 'v1' is possibly undefined

//----- (00479950) --------------------------------------------------------
int sub_479950() {
	void* v2; // [esp+0h] [ebp-4h]

	if (wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1123524) == 1) {
		return 0;
	}
	*getMemU8Ptr(0x5D4594, 1123516) = 0;
	LOWORD(v2) = 720;
	BYTE2(v2) = 0;
	nox_netlist_addToMsgListCli_40EBC0(31, 0, &v2, 3);
	return 1;
}

//----- (004799A0) --------------------------------------------------------
int sub_4799A0() {
	int result;    // eax
	uint32_t* v1;  // edi
	uint32_t* v2;  // ebp
	uint32_t* v3;  // eax
	int v4;        // esi
	uint32_t* v5;  // ebx
	char* v6;      // eax
	uint32_t* v7;  // eax
	char* v8;      // [esp-18h] [ebp-1Ch]
	char* v9;      // [esp-14h] [ebp-18h]
	uint32_t* v10; // [esp+0h] [ebp-4h]

	*getMemU32Ptr(0x5D4594, 1107052) = nox_color_rgb_4344A0(240, 128, 64);
	result = nox_new_window_from_file("Dialog.wnd", nox_xxx_guiDialog_479B00);
	dword_5d4594_1123524 = result;
	if (result) {
		nox_xxx_wndSetWindowProc_46B300(result, sub_479BE0);
		nox_xxx_wndSetDrawFn_46B340(*(int*)&dword_5d4594_1123524, sub_479CB0);
		nox_gui_winSetFunc96_46B070(*(int*)&dword_5d4594_1123524, sub_479D00);
		v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3904);
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3903);
		v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3902);
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3901);
		v4 = (int)v3;
		v5 = (uint32_t*)v3[8];
		v9 = nox_xxx_gLoadImg_42F970("UISliderLit");
		v8 = nox_xxx_gLoadImg_42F970("UISliderLit");
		v6 = nox_xxx_gLoadImg_42F970("UISlider");
		sub_4B5700((int)v1, 0, 0, (int)v6, (int)v8, (int)v9);
		nox_xxx_wnd_46B280((int)v1, v4);
		nox_xxx_wnd_46B280((int)v2, v4);
		nox_xxx_wnd_46B280((int)v10, v4);
		v5[9] = v1;
		v5[7] = v2;
		v5[8] = v10;
		v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3906);
		nox_xxx_wndSetDrawFn_46B340((int)v7, sub_479C40);
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1123524, 0);
		nox_window_set_hidden(*(int*)&dword_5d4594_1123524, 1);
		dword_5d4594_1123520 = 0;
		result = 1;
	}
	return result;
}

//----- (00479B00) --------------------------------------------------------
int nox_xxx_guiDialog_479B00(int a1, int a2, int* a3, int a4) {
	int v3;     // esi
	int result; // eax

	if (a2 != 16391) {
		return 0;
	}
	v3 = nox_xxx_wndGetID_46B0A0(a3);
	if (sub_45D9B0()) {
		return 0;
	}
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	switch (v3) {
	case 3906:
		sub_479950();
		result = 0;
		break;
	case 3907:
		nox_xxx_playDialogFile_44D900(*getMemIntPtr(0x5D4594, 1115312), 100);
		result = 0;
		break;
	case 3908:
		*getMemU8Ptr(0x5D4594, 1123516) = 1;
		LOWORD(a2) = 720;
		BYTE2(a2) = 1;
		nox_netlist_addToMsgListCli_40EBC0(31, 0, &a2, 3);
		result = 0;
		break;
	case 3909:
		*getMemU8Ptr(0x5D4594, 1123516) = 2;
		BYTE2(a2) = 2;
		LOWORD(a2) = 720;
		nox_netlist_addToMsgListCli_40EBC0(31, 0, &a2, 3);
		return 0;
	default:
		return 0;
	}
	return result;
}
// 479B4D: variable 'v4' is possibly undefined

//----- (00479BE0) --------------------------------------------------------
int sub_479BE0(uint32_t* a1, int a2, unsigned int a3, int a4) {
	switch (a2) {
	case 5:
	case 6:
	case 7:
	case 9:
	case 10:
	case 11:
	case 13:
	case 14:
	case 15:
		nox_xxx_wndPointInWnd_46AAB0(a1, (unsigned short)a3, a3 >> 16);
		break;
	default:
		return 1;
	}
	return 1;
}

//----- (00479C40) --------------------------------------------------------
int sub_479C40(uint32_t* a1, int a2) {
	char v2;   // bl
	int yTop;  // [esp+8h] [ebp-8h]
	int xLeft; // [esp+Ch] [ebp-4h]

	v2 = nox_xxx_bookGet_430B40_get_mouse_prev_seq();
	if (!sub_44D930() && (v2 & 0x7Fu) < 0x1E && v2 & 8) {
		nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop);
		sub_49CD30(xLeft, yTop, a1[2], a1[3] - 2, *getMemIntPtr(0x5D4594, 1107052), 4);
	}
	return nox_xxx_wndButtonDrawNoImg_4A81D0((int)a1, a2);
}

//----- (00479CB0) --------------------------------------------------------
int sub_479CB0(int a1, int a2) {
	int v2; // esi
	int v4; // [esp+4h] [ebp-8h]
	int v5; // [esp+8h] [ebp-4h]

	v2 = *(uint32_t*)(a2 + 24);
	nox_client_wndGetPosition_46AA60(*(uint32_t**)&dword_5d4594_1123524, &v4, &v5);
	nox_client_drawImageAt_47D2C0(v2, nox_win_width - NOX_DEFAULT_WIDTH, nox_win_height - NOX_DEFAULT_HEIGHT);
	return 1;
}

//----- (00479D00) --------------------------------------------------------
int sub_479D00() { return 1; }

//----- (00479D10) --------------------------------------------------------
int sub_479D10() {
	int result; // eax

	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1123524);
	result = 0;
	dword_5d4594_1123524 = 0;
	dword_5d4594_1123520 = 0;
	return result;
}

//----- (0047A1F0) --------------------------------------------------------
int sub_47A1F0() {
	uint32_t* v0; // eax
	int result;   // eax

	v0 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1123524, 3901);
	nox_window_call_field_94((int)v0, 16399, 0, 0);
	nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1123524, 0);
	nox_window_set_hidden(*(int*)&dword_5d4594_1123524, 1);
	sub_44D8F0();
	result = nox_client_renderGUI_80828;
	dword_5d4594_1123520 = 0;
	if (!nox_client_renderGUI_80828 && *getMemU32Ptr(0x587000, 153436) == 1) {
		nox_client_renderGUI_80828 = 1;
	}
	return result;
}

//----- (0047A260) --------------------------------------------------------
int sub_47A260() { return dword_5d4594_1123520; }

#ifndef NOX_CGO
//----- (0047A270) --------------------------------------------------------
int nox_video_bagAlloc_47A270() {
	int result; // eax

	sub_47D150();
	if (!nox_video_modeXxx_3801780) {
		return 0;
	}
	sub_47A310((const char*)getMemAt(0x587000, 153712));
	sub_47A650();
#ifndef NOX_CGO
	dword_5d4594_1189584 = calloc(dword_5d4594_1123532, 336);
	if (!dword_5d4594_1189584) {
		return 0;
	}
#endif // NOX_CGO
	result = (int)calloc(1, 0x12C000u);
	*getMemU32Ptr(0x5D4594, 1189588) = result;
	if (!result) {
		return 0;
	}
	result = (int)calloc(1, 0x12C000u);
	dword_5d4594_1189592 = result;
	if (!result) {
		return 0;
	}
	result = (int)calloc(1, 0x12C000u);
	dword_5d4594_1189596 = result;
	if (!result) {
		return 0;
	}
#ifndef NOX_CGO
	sub_47A650();
#endif // NOX_CGO
	return 1;
}
#endif // NOX_CGO

//----- (0047A310) --------------------------------------------------------
uint32_t sub_47A310(const char* lpPathName) {
	uint32_t result;                       // eax
	char* v3;                              // edx
	const char* v4;                        // ebp
	HANDLE v5;                             // ebx
	char* v6;                              // edx
	char* v7;                              // edx
	int v8;                                // [esp+10h] [ebp-348h]
	HANDLE v9;                             // [esp+14h] [ebp-344h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+18h] [ebp-340h]
	char Buffer[512];                      // [esp+158h] [ebp-200h]

	dword_5d4594_1189600 = 0;
	v8 = 0;
	if (nox_fs_set_workdir(lpPathName) || (result = GetLastError()) == 0) {
		nox_fs_workdir(Buffer, 512);
		v3 = (char*)getMemAt(0x5D4594, 1124048 + 512 * (dword_5d4594_1189600)++);
		strcpy(v3, Buffer);
		if (*(int*)&dword_5d4594_1189600 <= 0) {
		LABEL_27:
			nox_fs_set_workdir(Buffer);
			result = nox_fs_set_workdir("..");
		} else {
			v4 = (const char*)getMemAt(0x5D4594, 1124048);
			while (nox_fs_set_workdir(v4) || !GetLastError()) {
				v5 = FindFirstFileA((const char*)getMemAt(0x587000, 153724), &FindFileData);
				v9 = v5;
				if (v5 != (HANDLE)-1) {
					if (FindFileData.dwFileAttributes & 0x10 && strcmp(FindFileData.cFileName, ".") &&
						strcmp(FindFileData.cFileName, "..")) {
						v6 = (char*)getMemAt(0x5D4594, 1124048 + 512 * dword_5d4594_1189600);
						strcpy(v6, v4);
						if (v4[strlen(v4) - 1] != 92) {
							*(uint16_t*)&v6[strlen(v6)] = *getMemU16Ptr(0x587000, 153736);
						}
						strcat(v6, FindFileData.cFileName);
						if (strlen(v6) >= 0x200) {
							nox_exit(1);
						}
						if (++*(int*)&dword_5d4594_1189600 >= 128) {
							nox_exit(1);
						}
					}
					while (FindNextFileA(v5, &FindFileData)) {
						if (FindFileData.dwFileAttributes & 0x10 && strcmp(FindFileData.cFileName, ".") &&
							strcmp(FindFileData.cFileName, "..")) {
							v7 = (char*)getMemAt(0x5D4594, 1124048 + 512 * dword_5d4594_1189600);
							strcpy(v7, v4);
							if (v4[strlen(v4) - 1] != 92) {
								*(uint16_t*)&v7[strlen(v7)] = *getMemU16Ptr(0x587000, 153748);
							}
							strcat(v7, FindFileData.cFileName);
							if (strlen(v7) >= 0x200) {
								nox_exit(1);
							}
							if (++*(int*)&dword_5d4594_1189600 >= 128) {
								nox_exit(1);
							}
							v5 = v9;
						}
					}
					FindClose(v5);
				}
				v4 += 512;
				if (++v8 >= *(int*)&dword_5d4594_1189600) {
					goto LABEL_27;
				}
			}
			nox_fs_set_workdir(Buffer);
			result = nox_fs_set_workdir("..");
		}
	}
	return result;
}

#ifndef NOX_CGO
//----- (0047A650) --------------------------------------------------------
int sub_47A650() {
	int result;                            // eax
	const char* v1;                        // ebx
	short v2;                              // dx
	char* v3;                              // edi
	unsigned char v4;                      // al
	HANDLE v5;                             // esi
	HANDLE v6;                             // [esp+8h] [ebp-24Ch]
	int v7;                                // [esp+Ch] [ebp-248h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-244h]
	char FileName[260];                    // [esp+150h] [ebp-104h]

	result = dword_5d4594_1189600;
	dword_5d4594_1123532 = 0;
	v7 = 0;
	if (dword_5d4594_1189600 > 0) {
		v1 = (const char*)getMemAt(0x5D4594, 1124048);
		do {
			v2 = *getMemU16Ptr(0x587000, 153760);
			strcpy(FileName, v1);
			v3 = &FileName[strlen(FileName)];
			v4 = getMemByte(0x587000, 153762);
			*(uint32_t*)v3 = *getMemU32Ptr(0x587000, 153756);
			*((uint16_t*)v3 + 2) = v2;
			v3[6] = v4;
			v5 = FindFirstFileA(FileName, &FindFileData);
			v6 = v5;
			if (v5 != (HANDLE)-1) {
				if (dword_5d4594_1189584) {
					strcpy((char*)((char*)dword_5d4594_1189584 + 336 * dword_5d4594_1123532), v1);
					strcpy((char*)(336 * dword_5d4594_1123532 + (char*)dword_5d4594_1189584 + 260),
						   FindFileData.cFileName);
					*(uint32_t*)(336 * dword_5d4594_1123532 + (char*)dword_5d4594_1189584 + 324) = 0;
				}
				++dword_5d4594_1123532;
				for (; FindNextFileA(v5, &FindFileData); ++dword_5d4594_1123532) {
					if (dword_5d4594_1189584) {
						strcpy((char*)((char*)dword_5d4594_1189584 + 336 * dword_5d4594_1123532), v1);
						strcpy((char*)(336 * dword_5d4594_1123532 + (char*)dword_5d4594_1189584 + 260),
							   FindFileData.cFileName);
						v5 = v6;
						*(uint32_t*)(336 * dword_5d4594_1123532 + (char*)dword_5d4594_1189584 + 324) = 0;
					}
				}
				FindClose(v5);
			}
			result = v7 + 1;
			v1 += 512;
			++v7;
		} while (v7 < *(int*)&dword_5d4594_1189600);
	}
	return result;
}
// 47A650: using guessed type char FileName[260];

//----- (0047A8C0) --------------------------------------------------------
char* nox_xxx_loadImage_47A8C0(char a1, char* a2) {
	int v2;       // edi
	int i;        // esi
	char* result; // eax

	if (!dword_5d4594_1189584) {
		return 0;
	}
	v2 = 0;
	if (*(int*)&dword_5d4594_1123532 <= 0) {
		return 0;
	}
	for (i = 0; _strcmpi((const char*)(i + (char*)dword_5d4594_1189584 + 260), a2); i += 336) {
		if (++v2 >= *(int*)&dword_5d4594_1123532) {
			return 0;
		}
	}
	result = (char*)(336 * v2 + (char*)dword_5d4594_1189584 + 324);
	if (!*(uint32_t*)result) {
		if (nox_video_bag_readImageData_47A960(a1, v2)) {
			return (char*)(336 * v2 + (char*)dword_5d4594_1189584 + 324);
		}
		return 0;
	}
	return result;
}

//----- (0047A960) --------------------------------------------------------
int nox_video_bag_readImageData_47A960(unsigned char typ, int ind) {
	FILE* v4;          // edi
	bool v5;           // zf
	int v6;            // eax
	char* v8;          // eax
	int v9;            // esi
	unsigned char v10; // dl
	char* v11;         // edi
	unsigned char v12; // dl
	char* v13;         // edi
	void* v14;         // eax
	char v15[160];     // [esp+0h] [ebp-348h]
	int v18;           // [esp+B8h] [ebp-290h]
	int v19;           // [esp+BCh] [ebp-28Ch]
	char v20[68];      // [esp+C0h] [ebp-288h]
	char v21[68];      // [esp+104h] [ebp-244h]
	char Buffer[512];  // [esp+148h] [ebp-200h]

	nox_fs_workdir(Buffer, 512);
	if (!nox_fs_set_workdir((const char*)((char*)dword_5d4594_1189584 + 336 * ind)) && GetLastError()) {
		return 0;
	}
	v4 = nox_fs_open((const char*)((char*)dword_5d4594_1189584 + 336 * ind + 260));
	if (sub_4C57C0(v4, *getMemIntPtr(0x5D4594, 1189588), &v19, &v18)) {
		nox_fs_close(v4);
		switch (typ & 0x3F) {
		case 0:
			*(uint32_t*)((char*)dword_5d4594_1189584 + 336 * ind + 324) = calloc(v18 * v19, 3);
			v5 = nox_xxx_videoBag_LoadTile_47AD60(v19, v18,
												  *(uint16_t**)((char*)dword_5d4594_1189584 + 336 * ind + 324)) == 0;
			v6 = dword_5d4594_1189584;
			if (v5) {
				goto LABEL_6;
			}
			*(uint16_t*)((char*)dword_5d4594_1189584 + 336 * ind + 332) = 0;
			*(uint8_t*)((char*)dword_5d4594_1189584 + 336 * ind + 334) = -128;
			break;
		case 1:
			*(uint32_t*)((char*)dword_5d4594_1189584 + 336 * ind + 324) = calloc(v18 * v19, 3);
			v5 = nox_xxx_videoBag_LoadEdge_47AF30(
					 v19, v18, *(unsigned char**)((char*)dword_5d4594_1189584 + 336 * ind + 324)) == 0;
			v6 = dword_5d4594_1189584;
			if (v5) {
			LABEL_6:
				free(*(void**)(v6 + 336 * ind + 324));
				nox_fs_set_workdir(Buffer);
				return 0;
			}
			*(uint16_t*)((char*)dword_5d4594_1189584 + 336 * ind + 332) = 0;
			*(uint8_t*)((char*)dword_5d4594_1189584 + 336 * ind + 334) = -127;
			break;
		case 3:
		case 4:
		case 5:
		case 6:
			v8 = strrchr((const char*)((char*)dword_5d4594_1189584 + 336 * ind + 260), '.');
			v9 = (int)&v8[-336 * ind];
			strncpy(v21, (const char*)((char*)dword_5d4594_1189584 + 336 * ind + 260),
					(size_t)&v8[-336 * ind - (int)dword_5d4594_1189584 - 260]);
			v15[v9 - (int)dword_5d4594_1189584] = 0;
			if (typ == 5 || typ == 6) {
				v10 = getMemByte(0x587000, 153772);
				strcpy(v20, v21);
				v11 = &v20[strlen(v20)];
				*(uint32_t*)v11 = *getMemU32Ptr(0x587000, 153768);
				v11[4] = v10;
				v4 = nox_fs_open(v20);
				if (v4) {
					if (!sub_4C57C0(v4, *(int*)&dword_5d4594_1189596, &v19, &v18)) {
						goto LABEL_26;
					}
				}
			}
			if (typ == 4 || typ == 6) {
				v12 = getMemByte(0x587000, 153784);
				strcpy(v20, v21);
				v13 = &v20[strlen(v20)];
				*(uint32_t*)v13 = *getMemU32Ptr(0x587000, 153780);
				v13[4] = v12;
				v4 = nox_fs_open(v20);
				if (v4) {
					if (!sub_4C57C0(v4, *(int*)&dword_5d4594_1189592, &v19, &v18)) {
					LABEL_26:
						nox_fs_close(v4);
						nox_fs_set_workdir(Buffer);
						return 0;
					}
				}
			}
			v14 = calloc(v18 * v19, 3);
			*(uint32_t*)((char*)dword_5d4594_1189584 + 336 * ind + 324) = v14;
			if (!nox_xxx_videoBag_LoadPXImg_47B7F0(v19, v18,
												   *(uint32_t*)((char*)dword_5d4594_1189584 + 336 * ind + 324), typ)) {
				free(*(void**)((char*)dword_5d4594_1189584 + 336 * ind + 324));
				nox_fs_set_workdir(Buffer);
				return 0;
			}
			*(uint16_t*)((char*)dword_5d4594_1189584 + 336 * ind + 332) = 0;
			*(uint8_t*)((char*)dword_5d4594_1189584 + 336 * ind + 334) = typ | 0x80;
			break;
		default:
			break;
		}
	}
	nox_fs_close(v4);
	nox_fs_set_workdir(Buffer);
	return 1;
}
// 47A960: using guessed type char var_348[160];
// 47A960: using guessed type char var_288[68];
#endif // NOX_CGO

//----- (0047AD60) --------------------------------------------------------
int nox_xxx_videoBag_LoadTile_47AD60(int a1, int a2, uint16_t* a3) {
	int v3;    // edi
	int v4;    // edx
	int i;     // esi
	int v6;    // ecx
	int v7;    // eax
	short v8;  // ax
	int v9;    // esi
	int v10;   // edi
	int v11;   // edx
	int v12;   // ecx
	int v13;   // eax
	short v14; // ax
	short v15; // bx
	int v17;   // [esp+0h] [ebp-4h]
	int v18;   // [esp+8h] [ebp+4h]

	v17 = 0;
	if (a1 != 46 || a2 != 46) {
		return 0;
	}
	v3 = 819200;
	v4 = 1;
	for (i = 23; i > 0; --i) {
		v6 = 0;
		if (v4 > 0) {
			v17 += v4;
			do {
				v7 = i + v3;
#ifndef NOX_CGO
				if (nox_video_pixmode_3799624 == 2) {
					v8 = 8 * (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + i + v3 + v6 - 409600) & 0xF8 |
							  (32 * (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v7 + v6 - 819200) & 0xF8)));
				} else
#endif // NOX_CGO
				{
					v8 = 4 * (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + i + v3 + v6 - 409600) & 0xF8 |
							  (32 * (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v7 + v6 - 819200) & 0xF8)));
				}
				*a3 = (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + i + v3 + v6++) >> 3) | v8;
				++a3;
			} while (v6 < v4);
		}
		v4 += 2;
		v3 += 640;
	}
	v9 = 1;
	v10 = 833920;
	v11 = 45;
	v18 = 23;
	do {
		v12 = 0;
		if (v11 > 0) {
			v17 += v11;
			do {
				v13 = v10 + v9;
#ifndef NOX_CGO
				if (nox_video_pixmode_3799624 == 2) {
					v14 = 8 * (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v10 + v9 + v12 - 409600) & 0xF8 |
							   (32 * (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v13 + v12 - 819200) & 0xF8)));
				} else
#endif // NOX_CGO
				{
					v14 = 4 * (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v10 + v9 + v12 - 409600) & 0xF8 |
							   (32 * (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v13 + v12 - 819200) & 0xF8)));
				}
				++a3;
				v15 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v10 + v9 + v12++) >> 3;
				*(a3 - 1) = v15 | v14;
			} while (v12 < v11);
		}
		++v9;
		v11 -= 2;
		v10 += 640;
		--v18;
	} while (v18);
	return 1;
}

//----- (0047AF30) --------------------------------------------------------
int nox_xxx_videoBag_LoadEdge_47AF30(int a1, int a2, unsigned char* a3) {
	int v3;             // edx
	int v4;             // eax
	int v5;             // ecx
	int v6;             // eax
	int v7;             // eax
	int v8;             // edi
	int v9;             // edx
	int v10;            // eax
	int v11;            // ebp
	int v12;            // eax
	int v13;            // edx
	int v14;            // ecx
	int v15;            // eax
	int i;              // esi
	int v17;            // esi
	int v18;            // edi
	int v19;            // eax
	int v20;            // ebp
	int v21;            // eax
	int v22;            // esi
	int v23;            // edi
	int v24;            // ecx
	int v25;            // esi
	int v26;            // ecx
	int j;              // edi
	int v28;            // esi
	int v29;            // edi
	unsigned char* v30; // eax
	int v31;            // ecx
	int v32;            // ebx
	int v33;            // ebp
	int v34;            // edx
	int v35;            // ecx
	int v36;            // ebx
	int v37;            // ecx
	int v38;            // edx
	int v39;            // ecx
	short v40;          // cx
	int v41;            // edx
	uint16_t* v42;      // eax
	int v43;            // ecx
	int v44;            // ebx
	char v45;           // cl
	int v46;            // ebx
	int v47;            // ecx
	short v48;          // cx
	uint8_t* v49;       // ebx
	int v50;            // eax
	uint8_t* v51;       // ebx
	int v52;            // eax
	uint8_t* v53;       // ebp
	uint16_t* v54;      // eax
	bool v55;           // zf
	int v56;            // ebp
	int v57;            // ecx
	int v58;            // edx
	int v59;            // ecx
	short v60;          // cx
	int v61;            // edx
	uint16_t* v62;      // eax
	int v63;            // ecx
	int v64;            // ebx
	int v65;            // ecx
	short v66;          // cx
	uint8_t* v67;       // ebx
	int v68;            // eax
	uint8_t* v69;       // ebx
	int v70;            // eax
	uint8_t* v71;       // ebp
	uint16_t* v72;      // eax
	bool v73;           // cc
	int v75;            // [esp+0h] [ebp-20h]
	int v76;            // [esp+0h] [ebp-20h]
	int v77;            // [esp+4h] [ebp-1Ch]
	unsigned char v78;  // [esp+8h] [ebp-18h]
	int v79;            // [esp+8h] [ebp-18h]
	unsigned char v80;  // [esp+Ch] [ebp-14h]
	short v81;          // [esp+10h] [ebp-10h]
	int v82;            // [esp+14h] [ebp-Ch]
	int v83;            // [esp+14h] [ebp-Ch]
	short v84;          // [esp+18h] [ebp-8h]
	int v85;            // [esp+1Ch] [ebp-4h]
	char v86;           // [esp+24h] [ebp+4h]
	uint8_t* v87;       // [esp+24h] [ebp+4h]
	uint8_t* v88;       // [esp+24h] [ebp+4h]
	char v89;           // [esp+25h] [ebp+5h]
	char v90;           // [esp+26h] [ebp+6h]
	int v91;            // [esp+28h] [ebp+8h]
	int v92;            // [esp+28h] [ebp+8h]
	int v93;            // [esp+28h] [ebp+8h]
	int v94;            // [esp+28h] [ebp+8h]
	int v95;            // [esp+28h] [ebp+8h]
	int v96;            // [esp+2Ch] [ebp+Ch]
	int v97;            // [esp+2Ch] [ebp+Ch]

	HIWORD(v4) = 0;
	if (a1 != 46 || a2 != 46) {
		return 0;
	}
	HIWORD(v5) = *getMemU16Ptr(0x5D4594, 1189590);
	v86 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 1);
	v89 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 409601);
	v90 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 819201);
	LOWORD(v4) = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 1) & 0xF8;
	LOWORD(v3) = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 409601) & 0xF8;
#ifndef NOX_CGO
	if (nox_video_pixmode_3799624 == 2) {
		v6 = 8 * (v3 | (32 * v4));
	} else
#endif // NOX_CGO
	{
		v6 = 4 * (v3 | (32 * v4));
	}

	LOWORD(v5) = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 819201) >> 3;
	v7 = v5 | v6;
	v81 = v7;
	v8 = *getMemU32Ptr(0x5D4594, 1189588) + 819200;
	LOWORD(v7) = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 409600) & 0xF8;
	v78 = -1;
	LOWORD(v3) = **(uint8_t**)getMemAt(0x5D4594, 1189588) & 0xF8;
	v9 = 32 * v3;
	v10 = v9 | v7;
	LOWORD(v9) = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 819200) >> 3;
	v11 = 1;
	v12 = v9 | (4 * v10);
	v13 = 0;
	v84 = v12;
	v91 = 0;
	v14 = 0;
	v15 = 23;
	while (v15 > 0) {
		for (i = 0; i < v11; ++i) {
			if (v86 != *(uint8_t*)(v8 + v15 + i - 819200) || v89 != *(uint8_t*)(v8 + v15 + i - 409600) ||
				v90 != *(uint8_t*)(v8 + v15 + i)) {
				v13 = 1;
				v78 = v14;
				v91 = 1;
				break;
			}
			v13 = v91;
		}
		++v14;
		--v15;
		v11 += 2;
		v8 += 640;
		if (v13) {
			goto LABEL_27;
		}
	}
	v17 = *getMemU32Ptr(0x5D4594, 1189588) + ((5 * v14 + 6400) << 7);
	v18 = 91 - 2 * v14;
	do {
		if (v14 >= 46) {
			break;
		}
		v19 = 0;
		if (v18 > 0) {
			while (v86 == *(uint8_t*)(v19 + v17 + v14 - 819222) && v89 == *(uint8_t*)(v14 + v17 + v19 - 409622) &&
				   v90 == *(uint8_t*)(v14 + v17 + v19 - 22)) {
				if (++v19 >= v18) {
					goto LABEL_26;
				}
			}
			v78 = v14;
			v13 = 1;
		}
	LABEL_26:
		++v14;
		v18 -= 2;
		v17 += 640;
	} while (!v13);
LABEL_27:
	v20 = 0;
	v80 = -1;
	v92 = 0;
	v21 = 45;
	v22 = *getMemU32Ptr(0x5D4594, 1189588) + 848000;
	v23 = 1;
	while (v23 <= 45) {
		v24 = 0;
		if (v23 > 0) {
			while (v86 == *(uint8_t*)(v24 + v22 + v21 - 819222) && v89 == *(uint8_t*)(v22 + v24 + v21 - 409622) &&
				   v90 == *(uint8_t*)(v22 + v24 + v21 - 22)) {
				if (++v24 >= v23) {
					v20 = v92;
					goto LABEL_36;
				}
			}
			v20 = 1;
			v80 = v21;
			v92 = 1;
		}
	LABEL_36:
		--v21;
		v23 += 2;
		v22 -= 640;
		if (v20) {
			goto LABEL_48;
		}
	}
	v93 = 2 * v21 + 1;
	v25 = 23 - v21;
	v26 = *getMemU32Ptr(0x5D4594, 1189588) + ((5 * v21 + 6400) << 7);
	do {
		if (v21 < 0) {
			break;
		}
		for (j = 0; j < v93; ++j) {
			if (v86 != *(uint8_t*)(v26 + v25 + j - 819200) || v89 != *(uint8_t*)(v26 + v25 + j - 409600) ||
				v90 != *(uint8_t*)(v26 + v25 + j)) {
				v80 = v21;
				v20 = 1;
				break;
			}
		}
		--v21;
		++v25;
		v26 -= 640;
		v93 -= 2;
	} while (!v20);
LABEL_48:
	v28 = 2;
	*a3 = v78;
	v29 = 2;
	a3[1] = v80;
	v30 = a3 + 2;
	if (v80 >= 0x17u) {
		v31 = 22;
	} else {
		v31 = v80;
	}
	v32 = v78;
	v77 = v78;
	if (v78 <= v31) {
		v82 = 2 * v78 + 1;
		v33 = 23 - v78;
		v34 = (5 * v78 + 6400) << 7;
		v35 = v31 - v78 + 1;
		v75 = (5 * v78 + 6400) << 7;
		v36 = v35 + v78;
		v79 = 23 - v78;
		v85 = v35;
		v77 = v36;
		while (1) {
			v37 = v34 + v33 - 819200;
			v38 = v34 + v33 - 409600;
			LOWORD(v37) = *(uint8_t*)(v37 + *getMemU32Ptr(0x5D4594, 1189588)) & 0xF8;
			LOWORD(v38) = *(uint8_t*)(v38 + *getMemU32Ptr(0x5D4594, 1189588)) & 0xF8;
#ifndef NOX_CGO
			if (nox_video_pixmode_3799624 == 2) {
				v39 = 8 * (v38 | (32 * v37));
			} else
#endif // NOX_CGO
			{
				v39 = 4 * (v38 | (32 * v37));
			}
			v40 = (*(uint8_t*)(v33 + v75 + *getMemU32Ptr(0x5D4594, 1189588)) >> 3) | v39;
			if (v40 == v81) {
				v41 = 1;
				v28 += 2;
				*v30 = 1;
				v87 = v30 + 1;
				v30 += 2;
				v94 = 1;
				v29 += 2;
			} else if (v40 == v84) {
				*v30 = 3;
				v87 = v30 + 1;
				v30 += 2;
				v28 += 2;
				v94 = 3;
				v41 = 1;
				v29 += 2;
			} else {
				*v30 = 2;
				v42 = v30 + 1;
				v87 = v42;
				v42 = (uint16_t*)((char*)v42 + 1);
				v28 += 4;
				v94 = 2;
				*v42 = v40;
				v30 = (unsigned char*)(v42 + 1);
				v41 = 1;
				v29 += 3;
			}
			v43 = 1;
			v96 = 1;
			if (v82 > 1) {
				v44 = v75;
				while (1) {
					v45 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v44 + v33 - 819200 + v43);
					v46 = *getMemU32Ptr(0x5D4594, 1189588) + v75 + v33 - 409600;
					LOWORD(v43) = v45 & 0xF8;
					LOWORD(v46) = *(uint8_t*)(v46 + v96) & 0xF8;
#ifndef NOX_CGO
					v47 = nox_video_pixmode_3799624 == 2 ? 8 * (v46 | (32 * v43)) : 4 * (v46 | (32 * v43));
#else  // NOX_CGO
					v47 = 4 * (v46 | (32 * v43));
#endif // NOX_CGO
					v48 = (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v75 + v79 + v96) >> 3) | v47;
					if (v48 == v81) {
						if (v94 == 1) {
							++v41;
						} else {
							v49 = v87;
							v50 = (int)(v30 + 1);
							v87 = (uint8_t*)v50;
							v30 = (unsigned char*)(v50 + 1);
							*v49 = v41;
							*(v30 - 2) = 1;
							v28 += 2;
							v94 = 1;
							v41 = 1;
							v29 += 2;
						}
					} else if (v48 == v84) {
						if (v94 == 3) {
							++v41;
						} else {
							v51 = v87;
							v52 = (int)(v30 + 1);
							v87 = (uint8_t*)v52;
							v30 = (unsigned char*)(v52 + 1);
							*v51 = v41;
							*(v30 - 2) = 3;
							v28 += 2;
							v94 = 3;
							v41 = 1;
							v29 += 2;
						}
					} else if (v94 == 2) {
						*(uint16_t*)v30 = v48;
						v30 += 2;
						++v41;
						v28 += 2;
						++v29;
					} else {
						v53 = v87;
						v54 = v30 + 1;
						v87 = v54;
						v54 = (uint16_t*)((char*)v54 + 1);
						*v53 = v41;
						*((uint8_t*)v54 - 2) = 2;
						*v54 = v48;
						v30 = (unsigned char*)(v54 + 1);
						v28 += 4;
						v94 = 2;
						v41 = 1;
						v29 += 3;
					}
					if (++v96 >= v82) {
						break;
					}
					v44 = v75;
					v33 = v79;
					v43 = v96;
				}
				v33 = v79;
			}
			v32 = v77;
			--v33;
			*v87 = v41;
			v82 += 2;
			v55 = v85 == 1;
			v79 = v33;
			v75 += 640;
			--v85;
			if (v55) {
				break;
			}
			v34 = v75;
		}
	}
	if (v32 <= v80) {
		v56 = (5 * v32 + 6400) << 7;
		v76 = (5 * v32 + 6400) << 7;
		v83 = 91 - 2 * v32;
		do {
			v57 = *getMemU32Ptr(0x5D4594, 1189588) + v56 - 819200;
			v58 = *getMemU32Ptr(0x5D4594, 1189588) + v56 - 409600;
			LOWORD(v57) = *(uint8_t*)(v57 + v32 - 22) & 0xF8;
			LOWORD(v58) = *(uint8_t*)(v58 + v32 - 22) & 0xF8;
#ifndef NOX_CGO
			if (nox_video_pixmode_3799624 == 2) {
				v59 = 8 * (v58 | (32 * v57));
			} else
#endif // NOX_CGO
			{
				v59 = 4 * (v58 | (32 * v57));
			}
			v60 = (*(uint8_t*)(v56 + *getMemU32Ptr(0x5D4594, 1189588) + v32 - 22) >> 3) | v59;
			if (v60 == v81) {
				*v30 = 1;
				v61 = 1;
				v88 = v30 + 1;
				v30 += 2;
				v28 += 2;
				v95 = 1;
				v29 += 2;
			} else if (v60 == v84) {
				*v30 = 3;
				v88 = v30 + 1;
				v30 += 2;
				v28 += 2;
				v95 = 3;
				v61 = 1;
				v29 += 2;
			} else {
				*v30 = 2;
				v62 = v30 + 1;
				v88 = v62;
				v62 = (uint16_t*)((char*)v62 + 1);
				v28 += 4;
				v95 = 2;
				*v62 = v60;
				v30 = (unsigned char*)(v62 + 1);
				v61 = 1;
				v29 += 3;
			}
			v97 = 1;
			if (v83 > 1) {
				do {
					v63 = v97 + *getMemU32Ptr(0x5D4594, 1189588) + v56 - 819200;
					LOBYTE(v63) = *(uint8_t*)(v63 + v32 - 22);
					v64 = v97 + *getMemU32Ptr(0x5D4594, 1189588) + v76 - 409600;
					LOWORD(v63) = v63 & 0xF8;
					LOWORD(v64) = *(uint8_t*)(v64 + v77 - 22) & 0xF8;
#ifndef NOX_CGO
					if (nox_video_pixmode_3799624 == 2) {
						v65 = 8 * (v64 | (32 * v63));
					} else
#endif // NOX_CGO
					{
						v65 = 4 * (v64 | (32 * v63));
					}
					v66 = (*(uint8_t*)(v97 + *getMemU32Ptr(0x5D4594, 1189588) + v76 + v77 - 22) >> 3) | v65;
					if (v66 == v81) {
						if (v95 == 1) {
							++v61;
						} else {
							v67 = v88;
							v68 = (int)(v30 + 1);
							v88 = (uint8_t*)v68;
							v30 = (unsigned char*)(v68 + 1);
							*v67 = v61;
							*(v30 - 2) = 1;
							v28 += 2;
							v95 = 1;
							v61 = 1;
							v29 += 2;
						}
					} else if (v66 == v84) {
						if (v95 == 3) {
							++v61;
						} else {
							v69 = v88;
							v70 = (int)(v30 + 1);
							v88 = (uint8_t*)v70;
							v30 = (unsigned char*)(v70 + 1);
							*v69 = v61;
							*(v30 - 2) = 3;
							v28 += 2;
							v95 = 3;
							v61 = 1;
							v29 += 2;
						}
					} else if (v95 == 2) {
						*(uint16_t*)v30 = v66;
						v30 += 2;
						++v61;
						v28 += 2;
						++v29;
					} else {
						v71 = v88;
						v72 = v30 + 1;
						v88 = v72;
						v72 = (uint16_t*)((char*)v72 + 1);
						*v71 = v61;
						*((uint8_t*)v72 - 2) = 2;
						*v72 = v66;
						v30 = (unsigned char*)(v72 + 1);
						v28 += 4;
						v95 = 2;
						v61 = 1;
						v29 += 3;
					}
					v56 = v76;
					v73 = v97 + 1 < v83;
					v32 = v77;
					++v97;
				} while (v73);
			}
			++v32;
			v56 += 640;
			v77 = v32;
			*v88 = v61;
			v76 = v56;
			v83 -= 2;
		} while (v32 <= v80);
	}
	return 1;
}
// 47AF8E: variable 'v3' is possibly undefined

//----- (0047B7F0) --------------------------------------------------------
int nox_xxx_videoBag_LoadPXImg_47B7F0(int a1, int a2, int a3, unsigned char a4) {
	int v4;             // esi
	int v5;             // ebp
	unsigned char v6;   // bl
	int i;              // edx
	int v8;             // edi
	int v9;             // edi
	int v10;            // edi
	int v11;            // ebp
	int v12;            // eax
	int v13;            // ecx
	int j;              // edi
	int v15;            // edx
	int v16;            // edx
	int v17;            // edx
	int v18;            // ebx
	int v19;            // ebp
	int v20;            // edi
	unsigned char* v21; // ecx
	int v22;            // edx
	int v23;            // edx
	int v24;            // edx
	int v25;            // eax
	int v26;            // ebp
	int v27;            // edi
	unsigned char* v28; // ecx
	int v29;            // edx
	int v30;            // edx
	int v31;            // edx
	int v32;            // eax
	unsigned char* v34; // esi
	int v35;            // edi
	int v36;            // ebp
	int v37;            // eax
	int v38;            // ecx
	uint8_t* v39;       // ecx
	short v40;          // dx
	short v41;          // dx
	uint16_t* v42;      // esi
	int v43;            // edx
	int v44;            // edx
	int v45;            // ecx
	bool v46;           // zf
	int v47;            // esi
	short v48;          // dx
	short v49;          // dx
	uint16_t* v50;      // esi
	uint8_t* v51;       // ecx
	char v52;           // cl
	uint8_t* v53;       // esi
	int v54;            // ecx
	short v55;          // cx
	short v56;          // dx
	short v57;          // dx
	uint16_t* v58;      // esi
	int v59;            // ecx
	int v60;            // esi
	char v61;           // dl
	uint8_t* v62;       // esi
	short v63;          // dx
	short v64;          // dx
	uint16_t* v65;      // esi
	int v66;            // ecx
	char v67;           // dl
	uint16_t* v68;      // esi
	int v69;            // ecx
	int v70;            // edx
	int v71;            // ebx
	uint8_t* v72;       // edx
	int v73;            // esi
	int v74;            // esi
	int v75;            // ecx
	int v76;            // ebx
	int v77;            // edx
	int v78;            // ecx
	uint16_t* v79;      // esi
	uint8_t* v80;       // edx
	int v81;            // esi
	int v82;            // ecx
	char v83;           // cl
	uint8_t* v84;       // esi
	int v85;            // ecx
	char v86;           // dl
	char v87;           // dl
	uint16_t* v88;      // esi
	int v89;            // esi
	char v90;           // dl
	uint8_t* v91;       // esi
	int v92;            // esi
	int v93;            // esi
	int v94;            // edx
	int v95;            // ecx
	int v96;            // ebx
	int v97;            // edx
	uint16_t* v98;      // esi
	uint8_t* v99;       // ecx
	int v100;           // esi
	int v101;           // [esp+10h] [ebp-74h]
	int v102;           // [esp+10h] [ebp-74h]
	int v103;           // [esp+10h] [ebp-74h]
	int v104;           // [esp+14h] [ebp-70h]
	int v105;           // [esp+14h] [ebp-70h]
	int v106;           // [esp+18h] [ebp-6Ch]
	int v107;           // [esp+1Ch] [ebp-68h]
	int v108;           // [esp+1Ch] [ebp-68h]
	int v109;           // [esp+20h] [ebp-64h]
	unsigned char v110; // [esp+24h] [ebp-60h]
	unsigned char v111; // [esp+24h] [ebp-60h]
	unsigned char v112; // [esp+24h] [ebp-60h]
	unsigned char v113; // [esp+24h] [ebp-60h]
	int v114;           // [esp+28h] [ebp-5Ch]
	unsigned char v115; // [esp+28h] [ebp-5Ch]
	unsigned char v116; // [esp+28h] [ebp-5Ch]
	unsigned char v117; // [esp+28h] [ebp-5Ch]
	unsigned char v118; // [esp+28h] [ebp-5Ch]
	int v119;           // [esp+30h] [ebp-54h]
	int v120;           // [esp+30h] [ebp-54h]
	unsigned char v121; // [esp+30h] [ebp-54h]
	unsigned char v122; // [esp+30h] [ebp-54h]
	int v123;           // [esp+34h] [ebp-50h]
	int v124;           // [esp+38h] [ebp-4Ch]
	int v125;           // [esp+3Ch] [ebp-48h]
	short v126;         // [esp+60h] [ebp-24h]
	short v127;         // [esp+64h] [ebp-20h]
	unsigned char v128; // [esp+68h] [ebp-1Ch]
	unsigned char v129; // [esp+69h] [ebp-1Bh]
	unsigned char v130; // [esp+6Ah] [ebp-1Ah]
	int v131;           // [esp+88h] [ebp+4h]
	int v132;           // [esp+88h] [ebp+4h]
	int v133;           // [esp+88h] [ebp+4h]
	int v134;           // [esp+88h] [ebp+4h]
	int v135;           // [esp+88h] [ebp+4h]
	int v136;           // [esp+88h] [ebp+4h]
	int v137;           // [esp+88h] [ebp+4h]
	int v138;           // [esp+88h] [ebp+4h]
	uint8_t* v139;      // [esp+8Ch] [ebp+8h]
	uint8_t* v140;      // [esp+8Ch] [ebp+8h]
	uint8_t* v141;      // [esp+8Ch] [ebp+8h]
	uint8_t* v142;      // [esp+8Ch] [ebp+8h]
	int v143;           // [esp+90h] [ebp+Ch]
	int v144;           // [esp+90h] [ebp+Ch]
	int v145;           // [esp+90h] [ebp+Ch]
	int v146;           // [esp+90h] [ebp+Ch]
	int v147;           // [esp+94h] [ebp+10h]
	int v148;           // [esp+94h] [ebp+10h]
	int v149;           // [esp+94h] [ebp+10h]
	int v150;           // [esp+94h] [ebp+10h]

	v114 = -1;
	v4 = *getMemU32Ptr(0x5D4594, 1189588) + 819200;
	v128 = **(uint8_t**)getMemAt(0x5D4594, 1189588);
	v129 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 409600);
	v130 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 819200);
	v5 = 0;
	v6 = **(uint8_t**)getMemAt(0x5D4594, 1189588);
	v124 = 0;
	do {
		if (v124 >= a2) {
			break;
		}
		for (i = 0; i < a1; ++i) {
			v8 = *(unsigned char*)(v4 + i - 819200);
			if (v128 <= v8 + 5 && v6 >= v8 - 5) {
				v9 = *(unsigned char*)(v4 + i - 409600);
				if (v129 <= v9 + 5 && v129 >= v9 - 5) {
					v10 = *(unsigned char*)(v4 + i);
					if (v130 <= v10 + 5 && v130 >= v10 - 5) {
						continue;
					}
				}
			}
			v5 = 1;
			v114 = v124;
			break;
		}
		v4 += 640;
		++v124;
	} while (!v5);
	v11 = 0;
	v123 = -1;
	v12 = a2 - 1;
	v13 = *getMemU32Ptr(0x5D4594, 1189588) + ((5 * (a2 - 1) + 6400) << 7);
	do {
		if (v12 < 0) {
			break;
		}
		for (j = 0; j < a1; ++j) {
			v15 = *(unsigned char*)(v13 + j - 819200);
			if (v6 > v15 + 5 || v6 < v15 - 5 || (v16 = *(unsigned char*)(v13 + j - 409600), v129 > v16 + 5) ||
				v129 < v16 - 5 || (v17 = *(unsigned char*)(v13 + j), v130 > v17 + 5) || v130 < v17 - 5) {
				v6 = **(uint8_t**)getMemAt(0x5D4594, 1189588);
				v123 = v12;
				v11 = 1;
				break;
			}
			v6 = **(uint8_t**)getMemAt(0x5D4594, 1189588);
		}
		--v12;
		v13 -= 640;
	} while (!v11);
	v18 = -1;
	v119 = 0;
	v19 = 0;
	do {
		if (v19 >= a1) {
			break;
		}
		v20 = v114;
		v21 = (unsigned char*)(v19 + *getMemU32Ptr(0x5D4594, 1189588) + ((5 * v114 + 6400) << 7));
		while (v20 <= v123) {
			v22 = *(v21 - 819200);
			if (v128 > v22 + 5 || v128 < v22 - 5 || (v23 = *(v21 - 409600), v129 > v23 + 5) || v129 < v23 - 5 ||
				(v24 = *v21, v130 > v24 + 5) || v130 < v24 - 5) {
				v25 = 1;
				v18 = v19;
				v119 = 1;
				goto LABEL_40;
			}
			++v20;
			v21 += 640;
		}
		v25 = v119;
	LABEL_40:
		++v19;
	} while (!v25);
	v106 = v18;
	v109 = -1;
	v120 = 0;
	v26 = a1 - 1;
	do {
		if (v26 < 0) {
			break;
		}
		v27 = v114;
		v28 = (unsigned char*)(v26 + *getMemU32Ptr(0x5D4594, 1189588) + ((5 * v114 + 6400) << 7));
		while (v27 <= v123) {
			v29 = *(v28 - 819200);
			if (v128 > v29 + 5 || v128 < v29 - 5 || (v30 = *(v28 - 409600), v129 > v30 + 5) || v129 < v30 - 5 ||
				(v31 = *v28, v130 > v31 + 5) || v130 < v31 - 5) {
				v32 = 1;
				v109 = v26;
				v120 = 1;
				goto LABEL_54;
			}
			++v27;
			v28 += 640;
		}
		v32 = v120;
	LABEL_54:
		--v26;
	} while (!v32);
	if (v114 == -1) {
		*(uint32_t*)a3 = 0;
		*(uint32_t*)(a3 + 4) = 0;
		*(uint32_t*)(a3 + 8) = 0;
		*(uint32_t*)(a3 + 12) = 0;
		*(uint8_t*)(a3 + 16) = 0;
		*(uint8_t*)(a3 + 17) = 0;
		*(uint8_t*)(a3 + 18) = 0;
		return 1;
	}
	*(uint32_t*)a3 = v109 - v18 + 1;
	v34 = (unsigned char*)(a3 + 17);
	*(uint32_t*)(a3 + 4) = v123 - v114 + 1;
	v35 = 17;
	*(uint32_t*)(a3 + 8) = v18;
	*(uint32_t*)(a3 + 12) = v114;
	*(uint8_t*)(a3 + 16) = a4 | 0x80;
	v36 = 17;
	if (a4 == 4 || a4 == 6) {
		sub_47D090(a1, a2);
	}
	v37 = v114;
	if (v114 > v123) {
		goto LABEL_208;
	}
	v38 = a4 - 3;
	v125 = a4 - 3;
	while (1) {
		switch (v38) {
		case 0:
			v110 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18);
			if (v128 > v110 + 5 || v128 < v110 - 5 ||
				(v107 = (5 * v37 + 3200) << 7, v131 = *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + v107 + v18),
				 v129 > v131 + 5) ||
				v129 < v131 - 5 ||
				(v104 = (5 * v37 + 6400) << 7, v132 = *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + v104 + v18),
				 v130 > v132 + 5) ||
				v130 < v132 - 5) {
				v104 = (5 * v37 + 6400) << 7;
				v107 = (5 * v37 + 3200) << 7;
#ifndef NOX_CGO
				if (nox_video_pixmode_3799624 == 2) {
					v40 = 8 * ((32 * (v110 & 0xF8)) |
							   *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) & 0xF8);
				} else
#endif // NOX_CGO
				{
					v40 = 4 * ((32 * (v110 & 0xF8)) |
							   *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) & 0xF8);
				}
				v41 = (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) >> 3) | v40;
				*v34 = 2;
				v42 = v34 + 1;
				v35 += 4;
				v39 = v42;
				v42 = (uint16_t*)((char*)v42 + 1);
				v147 = 2;
				v133 = 1;
				*v42 = v41;
				v34 = (unsigned char*)(v42 + 1);
				v139 = v39;
				v36 += 3;
			} else {
				v35 += 2;
				*v34 = 1;
				v147 = 1;
				v133 = 1;
				v39 = v34 + 1;
				v34 += 2;
				v139 = v39;
				v36 += 2;
			}
			v143 = v18 + 1;
			if (v18 + 1 > v109) {
				goto LABEL_97;
			}
			while (1) {
				v115 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v143);
				if (v128 > v115 + 5 || v128 < v115 - 5) {
					goto LABEL_88;
				}
				v43 = *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + v107 + v143);
				if (v129 > v43 + 5 || v129 < v43 - 5 ||
					(v44 = *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + v104 + v143), v130 > v44 + 5) ||
					v130 < v44 - 5) {
					v39 = v139;
				LABEL_88:
#ifndef NOX_CGO
					if (nox_video_pixmode_3799624 == 2) {
						v48 = 8 * ((32 * (v115 & 0xF8)) |
								   *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v107 + v143) & 0xF8);
					} else
#endif // NOX_CGO
					{
						v48 = 4 * ((32 * (v115 & 0xF8)) |
								   *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v107 + v143) & 0xF8);
					}
					v49 = (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v104 + v143) >> 3) | v48;
					if (v147 == 1) {
						v50 = v34 + 1;
						*v39 = v133;
						*((uint8_t*)v50 - 1) = 2;
						v39 = v50;
						v50 = (uint16_t*)((char*)v50 + 1);
						v35 += 4;
						v147 = 2;
						*v50 = v49;
						v34 = (unsigned char*)(v50 + 1);
						v139 = v39;
						v133 = 1;
						v36 += 3;
					} else {
						if (++v133 == 254) {
							*v39 = -3;
							*v34 = 2;
							v35 += 2;
							v39 = v34 + 1;
							v34 += 2;
							v133 = 1;
							v139 = v39;
							v36 += 2;
						}
						*(uint16_t*)v34 = v49;
						v34 += 2;
						v35 += 2;
						++v36;
					}
					goto LABEL_96;
				}
				if (v147 != 1) {
					break;
				}
				v45 = v133 + 1;
				v133 = v45;
				v46 = v45 == 254;
				v39 = v139;
				if (v46) {
					*v139 = -3;
					*v34 = 1;
					v47 = (int)(v34 + 1);
				LABEL_85:
					v39 = (uint8_t*)v47;
					v34 = (unsigned char*)(v47 + 1);
					v35 += 2;
					v133 = 1;
					v139 = v39;
					v36 += 2;
				}
			LABEL_96:
				if (++v143 > v109) {
				LABEL_97:
					*v39 = v133;
					goto LABEL_206;
				}
			}
			v47 = (int)(v34 + 1);
			v147 = 1;
			*v139 = v133;
			*(uint8_t*)(v47 - 1) = 1;
			goto LABEL_85;
		case 1:
			v101 = 640 * v37;
			v111 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18);
			if (v128 > v111 + 5 || v128 < v111 - 5 ||
				v129 > *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) + 5 ||
				v129 < *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) - 5 ||
				v130 > *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) + 5 ||
				v130 < *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) - 5) {
				v52 = *(uint8_t*)(v101 + (unsigned int)dword_5d4594_1189592 + v18);
				if (v52 == -1) {
					HIBYTE(v55) = 0;
#ifndef NOX_CGO
					if (nox_video_pixmode_3799624 == 2) {
						v56 =
							8 * ((32 * (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18) & 0xF8)) |
								 *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) & 0xF8);
					} else
#endif // NOX_CGO
					{
						v56 =
							4 * ((32 * (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18) & 0xF8)) |
								 *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) & 0xF8);
					}
					LOBYTE(v55) = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) >> 3;
					v57 = v55 | v56;
					*v34 = 2;
					v58 = v34 + 1;
					v148 = 2;
					v51 = v58;
					v58 = (uint16_t*)((char*)v58 + 1);
					v134 = 1;
					v140 = v51;
					*v58 = v57;
					v34 = (unsigned char*)(v58 + 1);
					v35 += 4;
				} else {
					v134 = 1;
					*v34 = (16 * v52) | 4;
					v53 = v34 + 1;
					v54 = *(unsigned char*)((unsigned int)dword_5d4594_1189592 + v101 + v18);
					v18 = v106;
					v148 = (16 * v54) | 4;
					v51 = v53++;
					v140 = v51;
					*v53 = *(uint8_t*)(v101 + *getMemU32Ptr(0x5D4594, 1189588) + v106);
					v34 = v53 + 1;
					v35 += 3;
				}
				v36 += 3;
			} else {
				v35 += 2;
				*v34 = 1;
				v148 = 1;
				v134 = 1;
				v51 = v34 + 1;
				v34 += 2;
				v140 = v51;
				v36 += 2;
			}
			v144 = v18 + 1;
			if (v18 + 1 > v109) {
				goto LABEL_141;
			}
			do {
				v116 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v101 + v144);
				if (v128 <= v116 + 5 && v128 >= v116 - 5) {
					if (v129 <=
							*(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v144) + 5 &&
						v129 >=
							*(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v144) - 5 &&
						v130 <=
							*(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v144) + 5 &&
						v130 >=
							*(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v144) - 5) {
						if (v148 == 1) {
							v59 = v134 + 1;
							v134 = v59;
							v46 = v59 == 254;
							v51 = v140;
							if (!v46) {
								goto LABEL_140;
							}
							*v140 = -3;
							*v34 = 1;
							v60 = (int)(v34 + 1);
						} else {
							v60 = (int)(v34 + 1);
							v148 = 1;
							*v140 = v134;
							*(uint8_t*)(v60 - 1) = 1;
						}
						v51 = (uint8_t*)v60;
						v34 = (unsigned char*)(v60 + 1);
						v35 += 2;
						v134 = 1;
						v140 = v51;
						v36 += 2;
						goto LABEL_140;
					}
					v51 = v140;
				}
				v61 = *(uint8_t*)(v101 + (unsigned int)dword_5d4594_1189592 + v144);
				if (v61 == -1) {
#ifndef NOX_CGO
					if (nox_video_pixmode_3799624 == 2) {
						v63 =
							8 * ((32 * (v116 & 0xF8)) |
								 *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v144) & 0xF8);
					} else
#endif // NOX_CGO
					{
						v63 =
							4 * ((32 * (v116 & 0xF8)) |
								 *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v144) & 0xF8);
					}
					v64 = (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v144) >> 3) | v63;
					if (v148 != 2) {
						v65 = v34 + 1;
						*v51 = v134;
						*((uint8_t*)v65 - 1) = 2;
						v51 = v65;
						v65 = (uint16_t*)((char*)v65 + 1);
						v35 += 4;
						v140 = v51;
						*v65 = v64;
						v34 = (unsigned char*)(v65 + 1);
						v148 = 2;
						v134 = 1;
						v36 += 3;
						goto LABEL_140;
					}
					if (++v134 == 254) {
						*v51 = -3;
						*v34 = 2;
						v35 += 2;
						v51 = v34 + 1;
						v34 += 2;
						v134 = 1;
						v140 = v51;
						v36 += 2;
					}
					*(uint16_t*)v34 = v64;
					v34 += 2;
					v35 += 2;
				} else {
					v121 = (16 * v61) | 4;
					if (v148 != v121) {
						v148 = v121;
						*v51 = v134;
						*v34 = v121;
						v62 = v34 + 1;
						v51 = v62++;
						v35 += 3;
						*v62 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v101 + v144);
						v34 = v62 + 1;
						v134 = 1;
						v140 = v51;
						v36 += 3;
						goto LABEL_140;
					}
					if (++v134 == 254) {
						*v51 = -3;
						*v34 = v121;
						v51 = v34 + 1;
						v34 += 2;
						v35 += 2;
						v134 = 1;
						v140 = v51;
						v36 += 2;
					}
					++v34;
					++v35;
					*(v34 - 1) = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v101 + v144);
				}
				++v36;
			LABEL_140:
				++v144;
			} while (v144 <= v109);
		LABEL_141:
			*v51 = v134;
		LABEL_206:
			v18 = v106;
		LABEL_207:
			if (++v37 <= v123) {
				v38 = v125;
				continue;
			}
		LABEL_208:
			*v34 = 0;
			v34[1] = 0;
			return 1;
		case 2:
			v102 = 640 * v37;
			v112 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18);
			if (v128 > v112 + 5 || v128 < v112 - 5 ||
				(v108 = (5 * v37 + 3200) << 7, v135 = *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + v108 + v18),
				 v129 > v135 + 5) ||
				v129 < v135 - 5 ||
				(v105 = (5 * v37 + 6400) << 7, v136 = *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + v105 + v18),
				 v130 > v136 + 5) ||
				v130 < v136 - 5) {
				v108 = (5 * v37 + 3200) << 7;
				v66 = (5 * v37 + 6400) << 7;
				v105 = v66;
				v35 += 4;
				LOBYTE(v66) = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v66 + v18);
				v18 = v106;
				v149 = 5;
				v137 = 1;
				v126 = (*(uint8_t*)(v102 + (unsigned int)dword_5d4594_1189596 + v106) >> 4) | v66 & 0xF0;
				v67 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v108 + v106);
				*v34 = 5;
				v68 = v34 + 1;
				v141 = v68;
				v68 = (uint16_t*)((char*)v68 + 1);
				*v68 = (16 * ((16 * (v112 & 0xF0)) | v67 & 0xF0)) | v126;
				v34 = (unsigned char*)(v68 + 1);
				v36 += 3;
			} else {
				v35 += 2;
				*v34 = 1;
				v141 = v34 + 1;
				v34 += 2;
				v149 = 1;
				v137 = 1;
				v36 += 2;
			}
			v69 = v18 + 1;
			v145 = v18 + 1;
			if (v18 + 1 <= v109) {
				do {
					v117 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v102 + v69);
					if (v128 > v117 + 5 || v128 < v117 - 5 ||
						(v70 = *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + v108 + v145), v129 > v70 + 5) ||
						v129 < v70 - 5 ||
						(v71 = *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + v105 + v145), v130 > v71 + 5) ||
						v130 < v71 - 5) {
						v75 = *getMemU32Ptr(0x5D4594, 1189588) + v105;
						v76 = *getMemU32Ptr(0x5D4594, 1189588) + v108;
						HIWORD(v77) = HIWORD(v145);
						LOWORD(v75) = (*(uint8_t*)((unsigned int)dword_5d4594_1189596 + v102 + v145) >> 4) |
									  *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v105 + v145) & 0xF0;
						LOWORD(v76) = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v108 + v145) & 0xF0;
						LOWORD(v77) = v117 & 0xF0;
						v78 = (16 * ((16 * v77) | v76)) | v75;
						if (v149 == 5) {
							if (++v137 == 254) {
								v80 = v141;
								v81 = (int)(v34 + 1);
								v141 = (uint8_t*)v81;
								v34 = (unsigned char*)(v81 + 1);
								*v80 = -3;
								*(v34 - 2) = 5;
								v35 += 2;
								v137 = 1;
								v36 += 2;
							}
							*(uint16_t*)v34 = v78;
							v34 += 2;
							v35 += 2;
							++v36;
						} else {
							v79 = v34 + 1;
							v35 += 4;
							*v141 = v137;
							*((uint8_t*)v79 - 1) = 5;
							v141 = v79;
							v79 = (uint16_t*)((char*)v79 + 1);
							v149 = 2;
							v137 = 1;
							*v79 = v78;
							v34 = (unsigned char*)(v79 + 1);
							v36 += 3;
						}
					} else if (v149 == 1) {
						if (++v137 == 254) {
							v72 = v141;
							v73 = (int)(v34 + 1);
							v141 = (uint8_t*)v73;
							v34 = (unsigned char*)(v73 + 1);
							*v72 = -3;
							*(v34 - 2) = 1;
							v35 += 2;
							v137 = 1;
							v36 += 2;
						}
					} else {
						v74 = (int)(v34 + 1);
						v35 += 2;
						*v141 = v137;
						*(uint8_t*)(v74 - 1) = 1;
						v141 = (uint8_t*)v74;
						v34 = (unsigned char*)(v74 + 1);
						v149 = 1;
						v137 = 1;
						v36 += 2;
					}
					v69 = ++v145;
				} while (v145 <= v109);
				v18 = v106;
			}
			*v141 = v137;
			goto LABEL_207;
		case 3:
			v103 = 640 * v37;
			v113 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18);
			if (v128 > v113 + 5 || v128 < v113 - 5 ||
				v129 > *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) + 5 ||
				v129 < *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) - 5 ||
				v130 > *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) + 5 ||
				v130 < *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) - 5) {
				v83 = *(uint8_t*)(v103 + (unsigned int)dword_5d4594_1189592 + v18);
				v35 += 4;
				if (v83 == -1) {
					v150 = 5;
					v86 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18);
					v18 = v106;
					v127 = (*(uint8_t*)(v103 + (unsigned int)dword_5d4594_1189596 + v106) >> 4) | v86 & 0xF0;
					v87 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v106);
					*v34 = 5;
					v88 = v34 + 1;
					v142 = v88;
					v88 = (uint16_t*)((char*)v88 + 1);
					v82 = 1;
					*v88 = (16 * ((16 * (v113 & 0xF0)) | v87 & 0xF0)) | v127;
					v34 = (unsigned char*)(v88 + 1);
					v138 = 1;
					v36 += 3;
				} else {
					*v34 = (16 * v83) | 6;
					v84 = v34 + 1;
					v85 = *(unsigned char*)((unsigned int)dword_5d4594_1189592 + v103 + v18);
					v142 = v84++;
					*v84 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v103 + v106);
					v18 = v106;
					++v84;
					v150 = (16 * v85) | 6;
					v82 = 1;
					*v84 = *(uint8_t*)(v103 + (unsigned int)dword_5d4594_1189596 + v106);
					v34 = v84 + 1;
					v138 = 1;
					v36 += 4;
				}
			} else {
				v82 = 1;
				v35 += 2;
				*v34 = 1;
				v142 = v34 + 1;
				v34 += 2;
				v150 = 1;
				v138 = 1;
				v36 += 2;
			}
			v146 = v18 + 1;
			if (v18 + 1 > v109) {
				goto LABEL_205;
			}
			while (1) {
				v118 = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v103 + v146);
				if (v128 > v118 + 5 || v128 < v118 - 5) {
					goto LABEL_192;
				}
				if (v129 > *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v146) + 5 ||
					v129 < *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v146) - 5 ||
					v130 > *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v146) + 5 ||
					v130 < *(unsigned char*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v146) - 5) {
					break;
				}
				if (v150 != 1) {
					v89 = (int)(v34 + 1);
					v150 = 1;
					*v142 = v138;
					*(uint8_t*)(v89 - 1) = 1;
					goto LABEL_189;
				}
				v82 = ++v138;
				if (v138 == 254) {
					v89 = (int)(v34 + 1);
					*v142 = -3;
					*(uint8_t*)(v89 - 1) = 1;
				LABEL_189:
					v82 = 1;
					v142 = (uint8_t*)v89;
					v34 = (unsigned char*)(v89 + 1);
					v35 += 2;
					v138 = 1;
					v36 += 2;
				}
			LABEL_204:
				if (++v146 > v109) {
				LABEL_205:
					*v142 = v82;
					goto LABEL_206;
				}
			}
			v82 = v138;
		LABEL_192:
			v90 = *(uint8_t*)(v103 + (unsigned int)dword_5d4594_1189592 + v146);
			if (v90 == -1) {
				HIWORD(v94) = *getMemU16Ptr(0x5D4594, 1189590);
				HIWORD(v95) = HIWORD(v146);
				v96 = *getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7);
				LOWORD(v94) = (*(uint8_t*)((unsigned int)dword_5d4594_1189596 + v103 + v146) >> 4) |
							  *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v146) & 0xF0;
				LOWORD(v96) = *(uint8_t*)(v96 + v146) & 0xF0;
				LOWORD(v95) = v118 & 0xF0;
				v97 = (16 * ((16 * v95) | v96)) | v94;
				if (v150 == 5) {
					v82 = ++v138;
					if (v138 == 254) {
						v99 = v142;
						v100 = (int)(v34 + 1);
						v142 = (uint8_t*)v100;
						v34 = (unsigned char*)(v100 + 1);
						*v99 = -3;
						*(v34 - 2) = 5;
						v82 = 1;
						v35 += 2;
						v138 = 1;
						v36 += 2;
					}
					*(uint16_t*)v34 = v97;
					v34 += 2;
					v35 += 2;
					goto LABEL_203;
				}
				v98 = v34 + 1;
				v35 += 4;
				*v142 = v138;
				*((uint8_t*)v98 - 1) = 5;
				v142 = v98;
				v98 = (uint16_t*)((char*)v98 + 1);
				v82 = 1;
				v150 = 5;
				*v98 = v97;
				v34 = (unsigned char*)(v98 + 1);
				v138 = 1;
				v36 += 3;
			} else {
				v122 = (16 * v90) | 6;
				if (v150 == v122) {
					v138 = ++v82;
					if (v82 == 254) {
						v92 = (int)(v34 + 1);
						v35 += 2;
						*v142 = -3;
						*(uint8_t*)(v92 - 1) = v122;
						v82 = 1;
						v142 = (uint8_t*)v92;
						v34 = (unsigned char*)(v92 + 1);
						v138 = 1;
						v36 += 2;
					}
					v93 = (int)(v34 + 1);
					*(uint8_t*)(v93 - 1) = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v103 + v146);
					v34 = (unsigned char*)(v93 + 1);
					++v35;
					*(v34 - 1) = *(uint8_t*)((unsigned int)dword_5d4594_1189596 + v103 + v146);
				LABEL_203:
					++v36;
					goto LABEL_204;
				}
				v150 = v122;
				v91 = v34 + 1;
				v35 += 4;
				*v142 = v82;
				*(v91 - 1) = v122;
				v142 = v91++;
				v82 = 1;
				*v91++ = *(uint8_t*)(*getMemU32Ptr(0x5D4594, 1189588) + v103 + v146);
				v138 = 1;
				*v91 = *(uint8_t*)((unsigned int)dword_5d4594_1189596 + v103 + v146);
				v34 = v91 + 1;
				v36 += 4;
			}
			goto LABEL_204;
		default:
			goto LABEL_207;
		}
	}
}

//----- (0047D090) --------------------------------------------------------
int sub_47D090(int a1, int a2) {
	int result;        // eax
	int v3;            // ecx
	int v4;            // edi
	int v5;            // esi
	int v6;            // ebp
	char v7;           // dl
	unsigned char* v8; // eax
	int v9;            // [esp+0h] [ebp-4h]
	int v10;           // [esp+Ch] [ebp+8h]

	result = a2;
	if (a2 > 0) {
		v3 = dword_5d4594_1189592;
		v4 = 0;
		v9 = a2;
		do {
			v5 = 0;
			if (a1 > 0) {
				v6 = v4;
				do {
					v7 = 0;
					v8 = getMemAt(0x587000, 153689);
					v10 = 0;
					do {
						if (*(uint8_t*)(v3 + v6) == *(v8 - 1) && *(uint8_t*)(v4 + v3 + 819200 + v5 - 409600) == *v8 &&
							*(uint8_t*)(v4 + v3 + 819200 + v5) == v8[1]) {
							*(uint8_t*)(v3 + v6) = v7;
							v3 = dword_5d4594_1189592;
							v10 = 1;
						}
						v8 += 3;
						++v7;
					} while ((int)v8 < (int)getMemAt(0x587000, 153710));
					if (!v10) {
						*(uint8_t*)(v4 + v3 + v5) = -1;
						v3 = dword_5d4594_1189592;
					}
					++v5;
					++v6;
				} while (v5 < a1);
			}
			v4 += 640;
			result = --v9;
		} while (v9);
	}
	return result;
}

#ifndef NOX_CGO
//----- (0047D150) --------------------------------------------------------
void sub_47D150() {
	char* v1; // ecx
	int v2;   // edi
	int v3;   // esi

	if (*getMemU32Ptr(0x5D4594, 1189588)) {
		free(*(void**)getMemAt(0x5D4594, 1189588));
		*getMemU32Ptr(0x5D4594, 1189588) = 0;
	}
	if (dword_5d4594_1189592) {
		free(*(void**)&dword_5d4594_1189592);
		dword_5d4594_1189592 = 0;
	}
	if (dword_5d4594_1189596) {
		free(*(void**)&dword_5d4594_1189596);
		dword_5d4594_1189596 = 0;
	}
#ifndef NOX_CGO
	v1 = *(char**)&dword_5d4594_1189584;
	if (dword_5d4594_1189584) {
		v2 = 0;
		if (dword_5d4594_1123532 > 0) {
			v3 = 0;
			do {
				if (*(uint32_t*)&v1[v3 + 324]) {
					free(*(void**)&v1[v3 + 324]);
					v1 = *(char**)&dword_5d4594_1189584;
				}
				++v2;
				v3 += 336;
			} while (v2 < *(int*)&dword_5d4594_1123532);
		}
		free(v1);
		dword_5d4594_1189584 = 0;
	}
#endif // NOX_CGO
}

//----- (0047D200) --------------------------------------------------------
int sub_47D200() {
	if (nox_video_modeXxx_3801780 == 0) {
		nox_client_drawAtFunc_3799500 = sub_4C5EB0;
	} else if (nox_video_modeXxx_3801780 == 1) {
		if (cpuid_5d4594_3801804) {
			nox_client_drawAtFunc_3799500 = nox_xxx_smthPlayerAnim_4C7670;
		} else {
			nox_client_drawAtFunc_3799500 = nox_client_xxxDraw16_4C7440;
		}
	}
	dword_5d4594_3799484 = 0;
	*getMemU32Ptr(0x973F18, 52) = 0;
	*getMemU32Ptr(0x973F18, 12) = 0;
	dword_5d4594_3799476 = 0;
	dword_5d4594_3799452 = 0;
	*getMemU32Ptr(0x973F18, 44) = 0;
	*getMemU32Ptr(0x973F18, 104) = 0;
	*getMemU32Ptr(0x973F18, 8) = 0;
	*getMemU32Ptr(0x973F18, 36) = 0;
	*getMemU32Ptr(0x973F18, 32) = 0;
	*getMemU32Ptr(0x973F18, 100) = 0;
	*getMemU32Ptr(0x973F18, 20) = 0;
	*getMemU32Ptr(0x973F18, 120) = 0;
	*getMemU32Ptr(0x973F18, 68) = 0;
	dword_5d4594_3799524 = 0;
	dword_5d4594_3799468 = 0;
	dword_5d4594_3799552 = 0;
	dword_5d4594_3799508 = 0;
	nox_video_getImagePixdata_func = nox_video_getImagePixdata_42FB30;
	return 1;
}

//----- (0047D2C0) --------------------------------------------------------
void nox_client_drawImageAt_47D2C0(nox_video_bag_image_t* img, int x, int y) {
	if (dword_5d4594_3799452) {
		nox_xxx_wndDraw_49F7F0();
		sub_49F780(*getMemIntPtr(0x973F18, 52), *getMemIntPtr(0x973F18, 12));
		sub_49F6D0(1);
	}
	nox_client_drawAtFunc_3799500(img, x, y);
	if (dword_5d4594_3799452) {
		sub_49F860();
		dword_5d4594_3799452 = 0;
	}
	dword_5d4594_3799484 = 0;
	*getMemU32Ptr(0x973F18, 120) = 0;
	if (*getMemU32Ptr(0x973F18, 68) && img) {
		if (*getMemU32Ptr(0x973F18, 92) != img->field_1_0 || *getMemU32Ptr(0x973F18, 84) != img->field_1_1) {
			dword_5d4594_3799524 = 1;
		}
		img->field_1_0 = *getMemU16Ptr(0x973F18, 92);
		img->field_1_1 = *getMemU16Ptr(0x973F18, 84);
	}
}
#endif // NOX_CGO

//----- (0047D370) --------------------------------------------------------
int sub_47D370(int a1) {
	int result; // eax

	result = a1;
	if (a1 < 0) {
		result = 0;
	}
	dword_5d4594_3799484 = result;
	return result;
}

//----- (0047D380) --------------------------------------------------------
int sub_47D380(int a1, int a2) {
	int v2; // eax
	int v3; // ecx
	int v4; // edx
	int v5; // esi

	v2 = a1;
	v3 = a2;
	if (a1 > a2) {
		v2 = a2;
		v3 = a1;
	}
	v4 = nox_draw_curDrawData_3799572->clip.left;
	if (v2 >= v4) {
		if (v2 >= nox_draw_curDrawData_3799572->clip.right) {
			return 0;
		}
	} else {
		v2 = nox_draw_curDrawData_3799572->clip.left;
	}
	v5 = nox_draw_curDrawData_3799572->clip.right;
	if (v3 < v5) {
		if (v3 < v4) {
			return 0;
		}
	} else {
		v3 = nox_draw_curDrawData_3799572->clip.right;
	}
	if (v2 == v3) {
		return 0;
	}
	if (v2 != v4 || v3 != v5) {
		*getMemU32Ptr(0x973F18, 52) = v2;
		*getMemU32Ptr(0x973F18, 12) = v3;
		dword_5d4594_3799452 = 1;
	}
	return 1;
}

//----- (0047D3F0) --------------------------------------------------------
int sub_47D3F0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x973F18, 44) = a1;
	return result;
}

//----- (0047D400) --------------------------------------------------------
int sub_47D400(int a1, char a2) {
	int result; // eax

	result = a1;
	dword_5d4594_3799552 = a1;
	dword_5d4594_3799508 = a2 & 1;
	return result;
}

//----- (0047D420) --------------------------------------------------------
int nox_xxx_unused_47D420(int a1, int a2, int a3, int a4, int a5, int a6) {
	int result; // eax

	*getMemU32Ptr(0x973F18, 120) = 1;
	*getMemU32Ptr(0x973F18, 104) = a1 << 16;
	*getMemU32Ptr(0x973F18, 8) = a2 << 16;
	*getMemU32Ptr(0x973F18, 36) = a3 << 16;
	result = a4 << 16;
	*getMemU32Ptr(0x973F18, 32) = a4 << 16;
	*getMemU32Ptr(0x973F18, 100) = a5 << 16;
	*getMemU32Ptr(0x973F18, 20) = a6 << 16;
	return result;
}

#ifndef NOX_CGO
//----- (0047D480) --------------------------------------------------------
int nox_video_bag_decodeImageSwitch_47D480(void* data, nox_video_bag_image_t* img) {
	switch (img->typ & 0x3F) {
	case 2:
	case 7:
		nox_xxx_video_ReadTile_Real_47D4E0(data);
		break;
	case 3:
	case 4:
	case 5:
	case 6:
		nox_xxx_video_ReadSprite_Real_47D530(data);
		break;
	default:
		break;
	}
	return 1;
}
#endif // NOX_CGO

//----- (0047D4E0) --------------------------------------------------------
short nox_xxx_video_ReadTile_Real_47D4E0(uint32_t* a1) {
	int v1;       // ecx
	uint16_t* v2; // edi
	short result; // ax

	v1 = *a1 * a1[1];
	v2 = (uint16_t*)((char*)a1 + 17);
	do {
		result = *v2 & 0x1F | (2 * *v2) & 0xFFC0;
		*v2 = result;
		++v2;
	} while (v1-- > 1);
	return result;
}

//----- (0047D530) --------------------------------------------------------
void nox_xxx_video_ReadSprite_Real_47D530(void* data) {
	int v2 = 0; // ecx
	bool v6;    // cc

	int width = *((int*)data + 0);
	int height = *((int*)data + 1);
	short* pix = (short*)((char*)data + 17);
	int h = height;
	while (1) {
		unsigned char op = *((unsigned char*)pix + 0);
		unsigned char b = *((unsigned char*)pix + 1);
		++pix;
		op &= 0xF;
		if (op == 2) {
			int n = b;
			do {
				*pix = *pix & 0x1F | (2 * (*pix & 0x7FE0));
				++pix;
				v6 = n-- <= 1;
			} while (!v6);
			v6 = v2 <= b;
			v2 -= b;
			if (v6) {
				v6 = h-- <= 1;
				if (v6) {
					return;
				}
				v2 = width;
			}
		} else if (op == 4) {
			pix = (short*)((char*)pix + b);
			v6 = v2 <= b;
			v2 -= b;
			if (v6) {
				v6 = h-- <= 1;
				if (v6) {
					return;
				}
				v2 = width;
			}
		} else if (op == 5 || op == 6) {
			pix = (short*)((char*)pix + b);
			pix = (short*)((char*)pix + b);
			v6 = v2 <= b;
			v2 -= b;
			if (v6) {
				v6 = h-- <= 1;
				if (v6) {
					return;
				}
				v2 = width;
			}
		}
	}
}

//----- (0047D5C0) --------------------------------------------------------
int sub_47D5C0(int a1, uint32_t* a2, uint32_t* a3, uint32_t* a4, uint32_t* a5) {
	uint32_t* v5; // eax
	uint32_t* v6; // eax
	uint32_t* v7; // eax

	if (a4) {
		*a4 = 0;
	}
	if (a5) {
		*a5 = 0;
	}
	if (!a1) {
		return 0;
	}
	v5 = nox_video_getImagePixdata_func(a1);
	if (!v5) {
		return 0;
	}
	if (a4) {
		*a4 = *v5;
	}
	v6 = v5 + 1;
	if (a5) {
		*a5 = *v6;
	}
	v7 = v6 + 1;
	if (a2) {
		*a2 += *v7;
	}
	if (a3) {
		*a3 += v7[1];
	}
	return 1;
}

//----- (0047DBC0) --------------------------------------------------------
unsigned char sub_47DBC0() { return getMemByte(0x5D4594, 1193128); }

#ifndef NOX_CGO
//----- (0047DBD0) --------------------------------------------------------
void nox_xxx_keyboard_47DBD0() {
	unsigned char* v0 = getMemAt(0x5D4594, 1191572);
	for (int i = 0; i < 256; i++) {
		*((uint16_t*)v0 + 0) = 0;
		*((uint16_t*)v0 + 1) = 0;
		*((uint16_t*)v0 + 2) = 0;
		v0 += 6;
	}
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 211), "\b");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 211 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 211);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 14) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 211);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 14 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 211);
	*getMemU8Ptr(0x5D4594, 1193144) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 200) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 200 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 200 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 208) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 208 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 208 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 203) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 203 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 203 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 205) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 205 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 205 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 199) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 199 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 199 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 207) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 207 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 207 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 201) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 201 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 201 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 209) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 209 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 209 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 210) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 210 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 210 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 211 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 14 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 1) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 1 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 1 + 4) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 15), "\t");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 15 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 15);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 15 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 58) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 58 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 58 + 4) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 28), "\n");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 28 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 28);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 28 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 184) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 184 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 184 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 157) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 157 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 157 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 54) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 54 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 54 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 56) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 56 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 56 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 29) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 29 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 29 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 42) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 42 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 42 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 69) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 69 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 69 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 70) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 70 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 70 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 183) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 183 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 183 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 59) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 79), "1");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 79 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 79);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 59 + 2) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 80), "2");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 80 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 80);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 59 + 4) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 81), "3");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 81 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 81);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 60) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 75), "4");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 75 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 75);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 60 + 2) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 76), "5");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 76 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 76);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 60 + 4) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 77), "6");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 77 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 77);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 61) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 71), "7");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 71 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 71);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 61 + 2) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 72), "8");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 72 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 72);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 61 + 4) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 73), "9");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 73 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 73);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 62) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 57), " ");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 57 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 57);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 62 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 62 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 63) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 63 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 63 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 64) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 64 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 64 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 65) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 65 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 65 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 66) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 66 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 66 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 67) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 67 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 67 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 68) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 68 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 68 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 87) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 87 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 87 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 88) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 88 + 2) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 88 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 79 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 80 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 81 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 75 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 76 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 77 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 71 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 72 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 73 + 4) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 82), "0");
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 82 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 82);
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 82 + 4) = 0;
	*getMemU16Ptr(0x5D4594, 1191572 + 6 * 57 + 4) = 0;
	switch (nox_strman_get_lang_code()) {
	case 0:
	case 4:
	case 6:
	case 7:
	case 8:
	case 9:
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 156), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 156 + 2), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 74), "-");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 74 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 74);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 74 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 78), "+");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 78 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 78);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 78 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 156 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 181), "/");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 181 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 181);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 181 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 83), ".");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 83 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 83);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 83 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 55), "*");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 55 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 55);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 55 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 30), "a");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 30 + 2), "A");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 30 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 48), "b");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 48 + 2), "B");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 48 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 46), "c");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 46 + 2), "C");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 46 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 32), "d");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 32 + 2), "D");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 32 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 18), "e");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 18 + 2), "E");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 18 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 33), "f");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 33 + 2), "F");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 33 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 34), "g");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 34 + 2), "G");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 34 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 35), "h");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 35 + 2), "H");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 35 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 23), "i");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 23 + 2), "I");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 23 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 36), "j");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 36 + 2), "J");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 36 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 37), "k");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 37 + 2), "K");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 37 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 38), "l");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 38 + 2), "L");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 38 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 50), "m");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 50 + 2), "M");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 50 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 49), "n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 49 + 2), "N");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 49 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 24), "o");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 24 + 2), "O");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 24 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 25), "p");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 25 + 2), "P");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 25 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 16), "q");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 16 + 2), "Q");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 16 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 19), "r");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 19 + 2), "R");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 19 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 31), "s");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 31 + 2), "S");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 31 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 20), "t");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 20 + 2), "T");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 20 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 22), "u");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 22 + 2), "U");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 22 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 47), "v");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 47 + 2), "V");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 47 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 17), "w");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 17 + 2), "W");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 17 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 45), "x");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 45 + 2), "X");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 45 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 21), "y");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 21 + 2), "Y");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 21 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 44), "z");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 44 + 2), "Z");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 44 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 2), "1");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 2 + 2), "!");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 2 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 3), "2");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 3 + 2), "@");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 3 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 4), "3");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 4 + 2), "#");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 4 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 5), "4");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 5 + 2), "$");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 5 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 6), "5");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 6 + 2), "%");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 6 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 7), "6");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 7 + 2), "^");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 7 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 8), "7");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 8 + 2), "&");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 8 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 9), "8");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 9 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 55);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 9 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 10), "9");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 10 + 2), "(");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 10 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11), "0");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11 + 2), ")");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 11 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 51), ",");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 51 + 2), "<");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 51 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 52) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 83);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 52 + 2), ">");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 52 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 53) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 181);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 53 + 2), "?");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 53 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 26), "[");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 26 + 2), "{");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 26 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 27), "]");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 27 + 2), "}");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 27 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 39), ";");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 39 + 2), ":");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 39 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 40), "'");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 40 + 2), "\"");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 40 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 41), "`");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 41 + 2), "~");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 41 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 43), "\\");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 43 + 2), "|");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 43 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 12) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 74);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 12 + 2), "_");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 12 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 13), "=");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 13 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 78);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 13 + 4) = 0;
		break;
	case 1:
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 156), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 156 + 2), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 74), "-");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 74 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 74);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 74 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 78), "+");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 78 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 78);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 78 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 156 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 181), "/");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 181 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 181);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 181 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 83), ".");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 83 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 83);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 83 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 55), "*");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 55 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 55);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 55 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 30), "a");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 30 + 2), "A");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 30 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 48), "b");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 48 + 2), "B");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 48 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 46), "c");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 46 + 2), "C");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 46 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 32), "d");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 32 + 2), "D");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 32 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 18), "e");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 18 + 2), "E");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 18 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 33), "f");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 33 + 2), "F");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 33 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 34), "g");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 34 + 2), "G");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 34 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 35), "h");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 35 + 2), "H");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 35 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 23), "i");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 23 + 2), "I");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 23 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 36), "j");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 36 + 2), "J");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 36 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 37), "k");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 37 + 2), "K");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 37 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 38), "l");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 38 + 2), "L");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 38 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 50), "m");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 50 + 2), "M");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 50 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 49), "n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 49 + 2), "N");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 49 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 24), "o");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 24 + 2), "O");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 24 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 25), "p");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 25 + 2), "P");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 25 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 16), "q");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 16 + 2), "Q");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 16 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 19), "r");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 19 + 2), "R");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 19 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 31), "s");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 31 + 2), "S");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 31 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 20), "t");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 20 + 2), "T");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 20 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 22), "u");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 22 + 2), "U");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 22 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 47), "v");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 47 + 2), "V");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 47 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 17), "w");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 17 + 2), "W");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 17 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 45), "x");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 45 + 2), "X");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 45 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 21), "y");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 21 + 2), "Y");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 21 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 44), "z");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 44 + 2), "Z");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 44 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 2), "1");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 2 + 2), "!");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 2 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 3), "2");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 3 + 2), "\"");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 3 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 4), "3");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 4 + 2) = 163;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 4 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 5), "4");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 5 + 2), "$");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 5 + 4) = 8364;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 6), "5");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 6 + 2), "%");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 6 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 7), "6");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 7 + 2), "^");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 7 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 8), "7");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 8 + 2), "&");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 8 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 9), "8");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 9 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 55);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 9 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 10), "9");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 10 + 2), "(");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 10 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11), "0");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11 + 2), ")");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 11 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 51), ",");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 51 + 2), "<");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 51 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 52) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 83);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 52 + 2), ">");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 52 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 53) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 181);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 53 + 2), "?");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 53 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 26), "[");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 26 + 2), "{");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 26 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 27), "]");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 27 + 2), "}");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 27 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 39), ";");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 39 + 2), ":");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 39 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 40), "'");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 40 + 2), "@");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 40 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 41), "`");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 41 + 2) = 172;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 41 + 4) = 166;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 43), "#");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 43 + 2), "~");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 43 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 12) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 74);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 12 + 2), "_");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 12 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 13), "=");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 13 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 78);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 13 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 86), "\\");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 86 + 2), "|");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 86 + 4) = 0;
		*getMemU8Ptr(0x5D4594, 1193144) = -72;
		break;
	case 2:
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 156), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 156 + 2), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 74), "-");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 74 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 74);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 74 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 78), "+");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 78 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 78);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 78 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 156 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 181), "/");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 181 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 181);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 181 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 83), ",");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 83 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 83);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 83 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 55), "*");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 55 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 55);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 55 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 30), "a");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 30 + 2), "A");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 30 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 48), "b");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 48 + 2), "B");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 48 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 46), "c");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 46 + 2), "C");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 46 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 32), "d");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 32 + 2), "D");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 32 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 18), "e");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 18 + 2), "E");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 18 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 33), "f");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 33 + 2), "F");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 33 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 34), "g");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 34 + 2), "G");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 34 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 35), "h");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 35 + 2), "H");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 35 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 23), "i");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 23 + 2), "I");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 23 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 36), "j");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 36 + 2), "J");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 36 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 37), "k");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 37 + 2), "K");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 37 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 38), "l");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 38 + 2), "L");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 38 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 50), "m");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 50 + 2), "M");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 50 + 4), "\xb5"); // µ
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 49), "n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 49 + 2), "N");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 49 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 24), "o");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 24 + 2), "O");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 24 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 25), "p");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 25 + 2), "P");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 25 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 16), "q");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 16 + 2), "Q");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 16 + 4), "@");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 19), "r");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 19 + 2), "R");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 19 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 31), "s");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 31 + 2), "S");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 31 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 20), "t");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 20 + 2), "T");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 20 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 22), "u");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 22 + 2), "U");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 22 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 47), "v");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 47 + 2), "V");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 47 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 17), "w");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 17 + 2), "W");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 17 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 45), "x");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 45 + 2), "X");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 45 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 21), "z");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 21 + 2), "Z");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 21 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 44), "y");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 44 + 2), "Y");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 44 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 2), "1");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 2 + 2), "!");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 2 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 3), "2");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 3 + 2), "\"");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 3 + 4) = 178;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 4), "3");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 4 + 2) = 167;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 4 + 4) = 179;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 5), "4");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 5 + 2), "$");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 5 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 6), "5");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 6 + 2), "%");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 6 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 7), "6");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 7 + 2), "&");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 7 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 8), "7");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 8 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 181);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 8 + 4), "{");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 9), "8");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 9 + 2), "(");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 9 + 4), "[");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 10), "9");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 10 + 2), ")");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 10 + 4), "]");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11), "0");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11 + 2), "=");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11 + 4), "}");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 51) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 83);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 51 + 2), ";");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 51 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 52), ".");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 52 + 2), ":");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 52 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 53) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 74);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 53 + 2), "_");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 53 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 26), "\xfc");     // ü
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 26 + 2), "\xdc"); // Ü
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 26 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 27) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 78);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 27 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 55);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 27 + 4), "~");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 39), "\xf6");     // ö
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 39 + 2), "\xd6"); // Ö
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 39 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 40), "\xe4");     // ä
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 40 + 2), "\xc4"); // Ä
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 40 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 41), "^");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 41 + 2), "\xb0"); // °
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 41 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 43), "#");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 43 + 2), "'");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 43 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 12), "\xdf"); // ß
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 12 + 2), "?");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 12 + 4), "\\");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 13) = 180;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 13 + 2), "`");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 13 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 86), "<");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 86 + 2), ">");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 86 + 4), "|");
		*getMemU8Ptr(0x5D4594, 1193144) = -72;
		break;
	case 3:
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 156), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 156 + 2), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 74), "-");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 74 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 74);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 74 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 78), "+");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 78 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 78);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 78 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 156 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 181), "/");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 181 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 181);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 181 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 83), ".");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 83 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 83);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 83 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 55), "*");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 55 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 55);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 55 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 30), "q");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 30 + 2), "Q");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 30 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 48), "b");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 48 + 2), "B");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 48 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 46), "c");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 46 + 2), "C");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 46 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 32), "d");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 32 + 2), "D");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 32 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 18), "e");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 18 + 2), "E");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 18 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 33), "f");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 33 + 2), "F");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 33 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 34), "g");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 34 + 2), "G");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 34 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 35), "h");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 35 + 2), "H");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 35 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 23), "i");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 23 + 2), "I");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 23 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 36), "j");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 36 + 2), "J");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 36 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 37), "k");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 37 + 2), "K");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 37 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 38), "l");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 38 + 2), "L");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 38 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 50), ",");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 50 + 2), "?");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 50 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 49), "n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 49 + 2), "N");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 49 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 24), "o");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 24 + 2), "O");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 24 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 25), "p");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 25 + 2), "P");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 25 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 16), "a");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 16 + 2), "A");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 16 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 19), "r");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 19 + 2), "R");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 19 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 31), "s");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 31 + 2), "S");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 31 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 20), "t");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 20 + 2), "T");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 20 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 22), "u");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 22 + 2), "U");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 22 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 47), "v");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 47 + 2), "V");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 47 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 17), "z");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 17 + 2), "Z");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 17 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 45), "x");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 45 + 2), "X");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 45 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 21), "y");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 21 + 2), "Y");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 21 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 44), "w");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 44 + 2), "W");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 44 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 2), "&");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 2 + 2), "1");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 2 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 3), "\xe9"); // é
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 3 + 2), "2");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 3 + 4), "~");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 4), "\"");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 4 + 2), "3");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 4 + 4), "#");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 5), "'");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 5 + 2), "4");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 5 + 4), "{");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 6), "(");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 6 + 2), "5");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 6 + 4), "[");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 7) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 74);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 7 + 2), "6");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 7 + 4), "|");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 8), "\xe8"); // è
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 8 + 2), "7");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 8 + 4), "`");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 9), "_");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 9 + 2), "8");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 9 + 4), "\\");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 10), "\xe7"); // ç
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 10 + 2), "9");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 10 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11), "\xe0"); // à
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11 + 2), "0");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11 + 4), "@");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 51), ";");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 51 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 83);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 51 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 52), ":");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 52 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 181);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 52 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 53), "!");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 53 + 2) = 167;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 53 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 26), "^");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 26 + 2) = 168;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 26 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 27), "$");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 27 + 2) = 163;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 27 + 4) = 164;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 39), "m");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 39 + 2), "M");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 39 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 40), "\xf9"); // ù
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 40 + 2), "%");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 40 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 41) = 178;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 41 + 2) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 41 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 43) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 55);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 43 + 2), "\xb5"); // µ
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 43 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 12), ")");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 12 + 2), "\xb0"); // °
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 12 + 4), "]");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 13), "=");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 13 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 78);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 13 + 4), "}");
		goto LABEL_9;
	case 5:
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 156), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 156 + 2), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 74), "-");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 74 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 74);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 74 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 78), "+");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 78 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 78);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 78 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 156 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 181), "/");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 181 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 181);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 181 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 83), ".");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 83 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 83);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 83 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 55), "*");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 55 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 55);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 55 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 30), "a");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 30 + 2), "A");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 30 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 48), "b");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 48 + 2), "B");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 48 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 46), "c");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 46 + 2), "C");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 46 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 32), "d");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 32 + 2), "D");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 32 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 18), "e");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 18 + 2), "E");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 18 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 33), "f");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 33 + 2), "F");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 33 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 34), "g");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 34 + 2), "G");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 34 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 35), "h");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 35 + 2), "H");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 35 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 23), "i");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 23 + 2), "I");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 23 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 36), "j");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 36 + 2), "J");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 36 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 37), "k");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 37 + 2), "K");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 37 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 38), "l");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 38 + 2), "L");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 38 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 50), "m");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 50 + 2), "M");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 50 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 49), "n");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 49 + 2), "N");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 49 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 24), "o");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 24 + 2), "O");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 24 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 25), "p");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 25 + 2), "P");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 25 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 16), "q");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 16 + 2), "Q");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 16 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 19), "r");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 19 + 2), "R");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 19 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 31), "s");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 31 + 2), "S");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 31 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 20), "t");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 20 + 2), "T");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 20 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 22), "u");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 22 + 2), "U");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 22 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 47), "v");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 47 + 2), "V");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 47 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 17), "w");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 17 + 2), "W");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 17 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 45), "x");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 45 + 2), "X");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 45 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 21), "y");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 21 + 2), "Y");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 21 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 44), "z");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 44 + 2), "Z");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 44 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 2), "1");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 2 + 2), "!");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 2 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 3), "2");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 3 + 2), "\"");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 3 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 4), "3");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 4 + 2) = 163;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 4 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 5), "4");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 5 + 2), "$");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 5 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 6), "5");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 6 + 2), "%");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 6 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 7), "6");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 7 + 2), "&");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 7 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 8), "7");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 8 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 181);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 8 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 9), "8");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 9 + 2), "(");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 9 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 10), "9");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 10 + 2), ")");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 10 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11), "0");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 11 + 2), "=");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 11 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 51), ",");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 51 + 2), ";");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 51 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 52) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 83);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 52 + 2), ":");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 52 + 4) = 0;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 53) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 74);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 53 + 2), "_");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 53 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 26), "\xe8");     // è
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 26 + 2), "\xe9"); // é
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 26 + 4), "[");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 27) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 78);
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 27 + 2) = *getMemU16Ptr(0x5D4594, 1191572 + 6 * 55);
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 27 + 4), "]");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 39), "\xf2");     // ò
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 39 + 2), "\xe7"); // ç
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 39 + 4), "@");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 40), "\xe0");     // à
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 40 + 2), "\xb0"); // °
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 40 + 4), "#");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 41), "\\");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 41 + 2), "|");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 41 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 43), "\xf9"); // ù
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 43 + 2) = 167;
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 43 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 12), "'");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 12 + 2), "?");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 12 + 4) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 13), "\xec"); // ì
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 13 + 2), "^");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 13 + 4) = 0;
	LABEL_9:
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 86), "<");
		strcpy((char*)getMemAt(0x5D4594, 1191572 + 6 * 86 + 2), ">");
		*getMemU16Ptr(0x5D4594, 1191572 + 6 * 86 + 4) = 0;
		*getMemU8Ptr(0x5D4594, 1193144) = -72;
		break;
	}
}
#endif NOX_CGO

//----- (0047FCE0) --------------------------------------------------------
int sub_47FCE0(uint32_t* a1, int a2) {
	int v2;            // edx
	unsigned char* v3; // eax
	int v4;            // eax
	int v5;            // esi

	v2 = 0;
	if (*(int*)&dword_5d4594_3804684 <= 0) {
	LABEL_8:
		v4 = 16 * dword_5d4594_3804684;
		v5 = dword_5d4594_3804684 + 1;
		*getMemU32Ptr(0x973F18, 6088 + v4) = a1[3];
		*getMemU32Ptr(0x973F18, 6092 + v4) = a1[2];
		*getMemU32Ptr(0x973F18, 6096 + v4) = a1[21];
		*getMemU32Ptr(0x973F18, 6100 + v4) = a1[26];
		dword_5d4594_3804684 = v5;
	} else {
		v3 = getMemAt(0x973F18, 6092);
		while (*((uint32_t*)v3 - 1) != a1[3] || *(uint32_t*)v3 != a1[2] || *((uint32_t*)v3 + 1) != a1[21] ||
			   *((uint32_t*)v3 + 2) != a1[26]) {
			++v2;
			v3 += 16;
			if (v2 >= *(int*)&dword_5d4594_3804684) {
				goto LABEL_8;
			}
		}
	}
	return 1;
}

// 4514E0: using guessed type void  nullsub_4(uint32_t, uint32_t, uint32_t, uint32_t);

//----- (0047FEF0) --------------------------------------------------------
int nox_xxx_setupSomeVideo_47FEF0() {
	unsigned char* v0; // eax
	int result;        // eax
	unsigned char* v2; // eax

#ifndef NOX_CGO
	if (nox_video_pixmode_3799624 == 2) {
#endif // NOX_CGO
		*getMemU32Ptr(0x973F18, 7716) = sub_480250;
		*getMemU32Ptr(0x973F18, 5248) = sub_480220;
		v0 = getMemAt(0x5D4594, 2598060);
		do {
			*((uint16_t*)v0 - 16) = 31744;
			*(uint16_t*)v0 = 992;
			*((uint16_t*)v0 + 16) = 31;
			*((uint16_t*)v0 - 12) = -2048;
			*((uint16_t*)v0 + 4) = -1024;
			*((uint16_t*)v0 + 20) = -2048;
			*((uint16_t*)v0 - 8) = -2048;
			*((uint16_t*)v0 + 8) = 2016;
			*((uint16_t*)v0 + 24) = 31;
			*((uint16_t*)v0 - 4) = 248;
			*((uint16_t*)v0 + 12) = 252;
			*((uint16_t*)v0 + 28) = 248;
			v0 += 2;
		} while ((int)v0 < (int)getMemAt(0x5D4594, 2598068));
		*getMemU32Ptr(0x5D4594, 2598128) = 0;
		*getMemU32Ptr(0x5D4594, 2598160) = 0;
		*getMemU32Ptr(0x5D4594, 2598132) = 0;
		*getMemU32Ptr(0x5D4594, 2598136) = 0;
		*getMemU32Ptr(0x5D4594, 2598168) = 0;
		*getMemU32Ptr(0x5D4594, 2598144) = 0;
		*getMemU32Ptr(0x5D4594, 2598176) = 0;
		*getMemU32Ptr(0x5D4594, 2598152) = 0;
		*getMemU32Ptr(0x5D4594, 2598184) = 0;
		*getMemU32Ptr(0x5D4594, 2598124) = 7;
		*getMemU32Ptr(0x5D4594, 2598156) = 2;
		*getMemU32Ptr(0x5D4594, 2598164) = 5;
		*getMemU32Ptr(0x5D4594, 2598140) = 8;
		*getMemU32Ptr(0x5D4594, 2598172) = 3;
		*getMemU32Ptr(0x5D4594, 2598148) = 8;
		*getMemU32Ptr(0x5D4594, 2598180) = 3;
		dword_5d4594_3807160 = sub_480EB0;
		result = 1;
#ifndef NOX_CGO
	} else if (nox_video_pixmode_3799624 == 1) {
		*getMemU32Ptr(0x973F18, 7716) = sub_4801E0;
		*getMemU32Ptr(0x973F18, 5248) = sub_4801B0;
		v2 = getMemAt(0x5D4594, 2598060);
		do {
			*((uint16_t*)v2 - 16) = 31744;
			*(uint16_t*)v2 = 992;
			*((uint16_t*)v2 + 16) = 31;
			*((uint16_t*)v2 - 12) = -2048;
			*((uint16_t*)v2 + 4) = -2048;
			*((uint16_t*)v2 + 20) = -2048;
			*((uint16_t*)v2 - 8) = 31744;
			*((uint16_t*)v2 + 8) = 992;
			*((uint16_t*)v2 + 24) = 31;
			*((uint16_t*)v2 - 4) = 248;
			*((uint16_t*)v2 + 12) = 248;
			*((uint16_t*)v2 + 28) = 248;
			v2 += 2;
		} while ((int)v2 < (int)getMemAt(0x5D4594, 2598068));
		*getMemU32Ptr(0x5D4594, 2598128) = 0;
		*getMemU32Ptr(0x5D4594, 2598156) = 2;
		*getMemU32Ptr(0x5D4594, 2598160) = 0;
		*getMemU32Ptr(0x5D4594, 2598136) = 0;
		*getMemU32Ptr(0x5D4594, 2598168) = 0;
		*getMemU32Ptr(0x5D4594, 2598144) = 0;
		*getMemU32Ptr(0x5D4594, 2598172) = 2;
		*getMemU32Ptr(0x5D4594, 2598176) = 0;
		*getMemU32Ptr(0x5D4594, 2598152) = 0;
		*getMemU32Ptr(0x5D4594, 2598180) = 2;
		*getMemU32Ptr(0x5D4594, 2598184) = 0;
		*getMemU32Ptr(0x5D4594, 2598124) = 7;
		*getMemU32Ptr(0x5D4594, 2598132) = 1;
		*getMemU32Ptr(0x5D4594, 2598164) = 6;
		*getMemU32Ptr(0x5D4594, 2598140) = 7;
		*getMemU32Ptr(0x5D4594, 2598148) = 7;
		dword_5d4594_3807160 = memcpy;
		result = 1;
	} else {
		result = 0;
	}
#endif // NOX_CGO
	return result;
}

//----- (004800F0) --------------------------------------------------------
#ifndef NOX_CGO
int nox_xxx_unused_4800F0() {
	int v2; // [esp-10h] [ebp-10h]
	int v3; // [esp-Ch] [ebp-Ch]
	int v4; // [esp-8h] [ebp-8h]
	int v5; // [esp-4h] [ebp-4h]

	nox_xxx_setSomeFunc_48A210(sub_47FCE0);
	v5 = (nox_video_16bit != 0) + 20;
	v4 = nox_video_16bit != 0 ? 16 : 8;
	v3 = nox_win_height;
	v2 = nox_win_width;
	if (!nox_xxx_GfxInit_444930(v2, v3, v4, v5)) {
		MessageBoxA(0, "GfxInit() failed", "StartupError", 0);
		return 0;
	}
	nox_client_clearScreen_440900();
	nox_xxx_setupSomeVideo_47FEF0();
	sub_49F6D0(1);
	sub_437290();
	nox_video_16bit = nox_video_modeXxx_3801780;
	*getMemU32Ptr(0x973F18, 6060) = nox_backbuffer_pitch_3801808 * nox_backbuffer_height;
	*getMemU32Ptr(0x973F18, 7696) = nox_video_modeXxx_3801780 == 1;
	sub_430B50(0, 0, 639, 479);
	nox_input_pollEvents_4453A0();
	return 1;
}
#endif // NOX_CGO

//----- (004801B0) --------------------------------------------------------
char sub_4801B0(uint8_t* a2, uint8_t* a3) {
	unsigned int v2; // edx
	unsigned int v3; // eax
	char result;     // al

	HIWORD(v3) = HIWORD(a3);
	*a2 = 8 * *a3;
	LOWORD(v2) = *(uint16_t*)a3;
	a2[1] = (v2 >> 2) & 0xF8;
	LOWORD(v3) = *(uint16_t*)a3;
	result = (v3 >> 7) & 0xF8;
	a2[2] = result;
	return result;
}
// 4801C2: variable 'v2' is possibly undefined

//----- (004801E0) --------------------------------------------------------
uint16_t* sub_4801E0(uint8_t* a1, uint16_t* a2) {
	uint16_t* result; // eax

	result = a2;
	*a2 = (*a1 >> 3) | (4 * (a1[1] & 0xF8 | (32 * (a1[2] & 0xF8))));
	return result;
}

//----- (00480220) --------------------------------------------------------
uint8_t* sub_480220(uint8_t* a1, uint8_t* a2) {
	unsigned int v2; // edx
	uint8_t* result; // eax

	result = a2;
	*a1 = 8 * *a2;
	LOWORD(v2) = *(uint16_t*)a2;
	a1[1] = (v2 >> 3) & 0xFC;
	a1[2] = a2[1] & 0xF8;
	return result;
}
// 480232: variable 'v2' is possibly undefined

//----- (00480250) --------------------------------------------------------
uint16_t* sub_480250(uint8_t* a1, uint16_t* a2) {
	uint16_t* result; // eax

	result = a2;
	*a2 = (*a1 >> 3) | (8 * (a1[1] & 0xFC | (32 * (a1[2] & 0xF8))));
	return result;
}

unsigned int sub_480290(void* a1, int a2, int a3, unsigned int* a4, unsigned int* a5) {
	abort();
	return 0;
}

short sub_4805A0(int a1, void* a2, int a3, unsigned int* a4, unsigned int* a5) {
	abort();
	return 0;
}

short sub_480700(int a1, void* a2, int a3, unsigned int* a4, unsigned int* a5) {
	abort();
	return 0;
}

//----- (00480860) --------------------------------------------------------
void sub_480860(uint16_t* a1, uint16_t* a2, int a3, int* a4, int* a5) {
	uint16_t* dword_975384 = nox_draw_colors_g_3804656;
	uint16_t* dword_97538C = nox_draw_colors_b_3804664;
	uint16_t* dword_975394 = nox_draw_colors_r_3804672;
	uint16_t dword_975260 = *((uint16_t*)((uint8_t*)byte_5D4594_3804364 + 0));
	uint16_t dword_975264 = *((uint16_t*)((uint8_t*)byte_5D4594_3804364 + 4));
	uint16_t dword_975268 = *((uint16_t*)((uint8_t*)byte_5D4594_3804364 + 8));
	uint16_t dword_97526C = *((uint16_t*)((uint8_t*)byte_5D4594_3804364 + 12));
	uint16_t dword_975270 = *((uint16_t*)((uint8_t*)byte_5D4594_3804364 + 16));
	uint16_t dword_975274 = *((uint16_t*)((uint8_t*)byte_5D4594_3804364 + 20));

	while (a3 > 0) {
		*a1 = (dword_97538C[((a4[2] * ((*a2 & dword_975268) << dword_975274)) >> 16) & 0xFF] |
			   dword_975384[((a4[1] * ((*a2 & dword_975264) >> dword_975270)) >> 16) & 0xFF] |
			   dword_975394[((a4[0] * ((*a2 & dword_975260) >> dword_97526C)) >> 16) & 0xFF]);
		a4[0] += a5[0];
		a4[1] += a5[1];
		a4[2] += a5[2];
		++a1;
		++a2;
		--a3;
	}
}

//----- (00480950) --------------------------------------------------------
int sub_480950(int* a1, int* a2, int a3, int a4, int a5) {
	int v5;          // ecx
	int result;      // eax
	int v7;          // edx
	unsigned int v8; // eax
	int v9;          // edi
	int v10;         // ecx
	int v11;         // edx
	int* v12;        // eax
	int v13;         // edi
	int v14;         // ebx
	int v15;         // edx
	int v16;         // ebp
	int v17;         // edi
	void* v18;       // ebx
	int v19;         // eax
	int v20;         // eax
	int v21[3];      // [esp+10h] [ebp-18h]
	int v22[3];      // [esp+1Ch] [ebp-Ch]
	void* v23;       // [esp+2Ch] [ebp+4h]

	v5 = *a1;
	result = a1[1] - dword_5d4594_3798824;
	v7 = *a1 - dword_5d4594_3798820;
	if (v7 >= 0 && result >= 0 && v7 < *(int*)&dword_5d4594_3798800 && result < *(int*)&dword_5d4594_3798808) {
		v8 = dword_5d4594_3798804 * (dword_5d4594_3798840 + result) + dword_5d4594_3798796 +
			 2 * (dword_5d4594_3798836 + v7);
		if (v8 >= *(int*)&dword_5d4594_3798844) {
			v8 += dword_5d4594_3798796 - dword_5d4594_3798844;
		}
		if (nox_common_getEngineFlag(NOX_ENGINE_DISABLE_SOFT_LIGHTS)) {
			if (2 * a4 + v8 < *(int*)&dword_5d4594_3798844) {
				result = (*(int (**)(uint32_t, uint32_t, uint32_t)) & dword_5d4594_3807160)(a5, v8, 2 * a4);
			} else {
				v9 = dword_5d4594_3798844 - v8;
				(*(void (**)(uint32_t, uint32_t, uint32_t)) & dword_5d4594_3807160)(a5, v8, dword_5d4594_3798844 - v8);
				result = (*(int (**)(uint32_t, uint32_t, uint32_t)) &
						  dword_5d4594_3807160)(a5 + v9, dword_5d4594_3798796, 2 * a4 - v9);
			}
		} else {
			v23 = (void*)v8;
			v10 = v5 - 23 * *a2 - dword_5d4594_2650676;
			v11 = 12 * a3 + 280 * *a2;
			v12 = ((void*)&nox_arr_84EB20[4 + v11]);
			v13 = *getMemU32Ptr(
				0x8529A0, 1020 + 4 * ((*((int*)&nox_arr_84EB20[284 + v11]) - *((int*)&nox_arr_84EB20[4 + v11])) >> 8));
			v22[0] = *getMemU32Ptr(
				0x8529A0, 1020 + 4 * ((*((int*)&nox_arr_84EB20[284 + v11]) - *((int*)&nox_arr_84EB20[4 + v11])) >> 8));
			v14 = *getMemU32Ptr(
				0x8529A0, 1020 + 4 * ((*((int*)&nox_arr_84EB20[288 + v11]) - *((int*)&nox_arr_84EB20[8 + v11])) >> 8));
			v22[1] = *getMemU32Ptr(
				0x8529A0, 1020 + 4 * ((*((int*)&nox_arr_84EB20[288 + v11]) - *((int*)&nox_arr_84EB20[8 + v11])) >> 8));
			v15 = *getMemU32Ptr(
				0x8529A0, 1020 + 4 * ((*((int*)&nox_arr_84EB20[292 + v11]) - *((int*)&nox_arr_84EB20[12 + v11])) >> 8));
			v22[2] = v15;
			v21[0] = *v12;
			v16 = v12[1];
			v21[1] = v12[1];
			v21[2] = v12[2];
			if (v10 <= 0) {
				v17 = 23;
			} else {
				v21[2] += v10 * v15;
				v21[0] += v10 * v13;
				v21[1] = v10 * v14 + v16;
				v17 = 23 - v10;
			}
			if (v17 > a4) {
				v17 = a4;
			}
			v18 = v23;
			while (1) {
				sub_480290(v18, a5, v17, (unsigned int*)v21, (unsigned int*)v22);
				v18 = (void*)((char*)v18 + 2 * v17);
				a5 += 2 * v17;
				if ((unsigned int)v18 >= *(int*)&dword_5d4594_3798844) {
					v18 =
						(void*)((char*)v18 - 2 * ((*(int*)&dword_5d4594_3798844 - *(int*)&dword_5d4594_3798796) >> 1));
				}
				result = a4 - v17;
				a4 -= v17;
				if (a4 <= 0) {
					break;
				}
				v17 = 23;
				if (result < 23) {
					v17 = result;
				}
				v19 = *a2 + 1;
				*a2 = v19;
				v20 = 12 * a3 + 280 * v19;
				v21[0] = *((unsigned int*)&nox_arr_84EB20[4 + v20]);
				v21[1] = *((unsigned int*)&nox_arr_84EB20[8 + v20]);
				v21[2] = *((unsigned int*)&nox_arr_84EB20[12 + v20]);
				v22[0] = *getMemU32Ptr(
					0x8529A0,
					1020 + 4 * ((*((int*)&nox_arr_84EB20[284 + v20]) - *((int*)&nox_arr_84EB20[4 + v20])) >> 8));
				v22[1] = *getMemU32Ptr(
					0x8529A0,
					1020 + 4 * ((*((int*)&nox_arr_84EB20[288 + v20]) - *((int*)&nox_arr_84EB20[8 + v20])) >> 8));
				v22[2] = *getMemU32Ptr(
					0x8529A0,
					1020 + 4 * ((*((int*)&nox_arr_84EB20[292 + v20]) - *((int*)&nox_arr_84EB20[12 + v20])) >> 8));
			}
		}
	}
	return result;
}

//----- (00480BE0) --------------------------------------------------------
void sub_480BE0(uint32_t* a1, int* a2, int a3, int a4, int a5) {
	uint8_t* v6; // ebp
	int v7;      // edi
	int v9;      // ecx
	int v10;     // eax
	int v16;     // ecx
	int v17;     // edi
	int v18;     // eax
	int v21;     // [esp+14h] [ebp-10h]
	int v22;     // [esp+18h] [ebp-Ch]
	int v23;     // [esp+1Ch] [ebp-8h]
	int v24;     // [esp+20h] [ebp-4h]
	int v25;     // [esp+28h] [ebp+4h]
	int v26;     // [esp+30h] [ebp+Ch]
	// void( * maprgb)(const uint8_t*, uint16_t*);
	uint8_t* x1 = *(uint8_t**)&dword_5d4594_3798844;
	uint8_t* x2 = *(uint8_t**)&dword_5d4594_3798796;

	v6 = (uint8_t*)(dword_5d4594_3798804 * (dword_5d4594_3798840 + a1[1] - dword_5d4594_3798824) +
					dword_5d4594_3798796 + 2 * (dword_5d4594_3798836 + *a1 - dword_5d4594_3798820));
	if (v6 >= x1) {
		v6 += x2 - x1;
	}
	if (nox_common_getEngineFlag(NOX_ENGINE_DISABLE_SOFT_LIGHTS)) {
		if ((unsigned int)&v6[2 * a4] < x1) {
			(*(int (**)(uint32_t, uint32_t, uint32_t)) & dword_5d4594_3807160)(a5, v6, 2 * a4);
		} else {
			v7 = x1 - v6;
			(*(void (**)(uint32_t, uint32_t, uint32_t)) & dword_5d4594_3807160)(a5, v6, x1 - v6);
			(*(int (**)(uint32_t, uint32_t, uint32_t)) & dword_5d4594_3807160)(a5 + v7, dword_5d4594_3798796,
																			   2 * a4 - v7);
		}
	} else {
		v9 = *a1 - 23 * *a2 - dword_5d4594_2650676;
		v21 = 12 * a3;
		v10 = 12 * a3 + 280 * *a2;
		int v11 = *((int*)&nox_arr_84EB20[4 + v10]);
		int v12 = *((int*)&nox_arr_84EB20[8 + v10]);
		int v13 = *((int*)&nox_arr_84EB20[12 + v10]);
		int v11b = *((int*)&nox_arr_84EB20[284 + v10]);
		int v12b = *((int*)&nox_arr_84EB20[288 + v10]);
		int v13b = *((int*)&nox_arr_84EB20[292 + v10]);
		v22 = *getMemU32Ptr(0x8529A0, 1020 + 4 * ((v11b - v11) >> 8));
		v23 = *getMemU32Ptr(0x8529A0, 1020 + 4 * ((v12b - v12) >> 8));
		v24 = *getMemU32Ptr(0x8529A0, 1020 + 4 * ((v13b - v13) >> 8));
		if (v9 <= 0) {
			v25 = 23;
		} else {
			v11 += v9 * v22;
			v12 += v9 * v23;
			v13 += v9 * v24;
			v25 = 23 - v9;
		}
		if (v25 > a4) {
			v25 = a4;
		}
		while (1) {
			for (v26 = v25; v26; --v26) {
				uint8_t r, g, b;
				uint16_t x = *(uint16_t*)v6;

#if 1
				r = (v13 * (x & 0x1Fu)) >> 13;
				g = (v12 * ((x >> 2) & 0xF8)) >> 16;
				b = (v11 * ((x >> 7) & 0xF8)) >> 16;
				*(uint16_t*)a5 = (r >> 3) | ((g & 0xF8) << 2) | ((b & 0xF8) << 7);
#else
				*(uint16_t*)a5 = x;
#endif
				// maprgb = *(void **)getMemAt(0x973F18, 7716);
				// maprgb(tmp, v20);

				v6 += 2;
				a5 += 2;
				if (v6 >= x1) {
					v6 = x2;
				}
				v11 += v22;
				v12 += v23;
				v13 += v24;
			}
			v16 = a4 - v25;
			a4 = v16;
			if (v16 <= 0) {
				break;
			}
			v25 = 23;
			if (v16 < 23) {
				v25 = v16;
			}
			v17 = *a2 + 1;
			*a2 = v17;
			v18 = v21 + 280 * v17;
			v11 = *((int*)&nox_arr_84EB20[4 + v18]);
			v12 = *((int*)&nox_arr_84EB20[8 + v18]);
			v13 = *((int*)&nox_arr_84EB20[12 + v18]);
			v11b = *((int*)&nox_arr_84EB20[284 + v18]);
			v12b = *((int*)&nox_arr_84EB20[288 + v18]);
			v13b = *((int*)&nox_arr_84EB20[292 + v18]);
			v22 = *getMemU32Ptr(0x8529A0, 1020 + 4 * ((v11b - v11) >> 8));
			v23 = *getMemU32Ptr(0x8529A0, 1020 + 4 * ((v12b - v12) >> 8));
			v24 = *getMemU32Ptr(0x8529A0, 1020 + 4 * ((v13b - v13) >> 8));
		}
	}
}

//----- (00480EB0) --------------------------------------------------------
uint16_t* sub_480EB0(uint16_t* a1, short* a2, int a3) {
	short* v3;    // esi
	uint16_t* v4; // edi
	int v5;       // ecx
	short v6;     // ax

	v3 = a2;
	v4 = a1;
	v5 = a3;
	do {
		v6 = *v3;
		++v3;
		*v4 = v6 & 0x1F | (2 * v6) & 0xFFC0;
		++v4;
	} while (v5-- > 1);
	return v4;
}

//----- (00480EF0) --------------------------------------------------------
int nox_getBackbufferPitch();
int* nox_xxx_someEdgeProcessing_480EF0(int a1, int a2, int a3, int* a4, int* a5, int a6, int a7, int a8, int a9,
									   int a10) {
	int* result;                                // eax
	int v10;                                    // ebx
	char v11;                                   // cl
	int v12;                                    // esi
	int v13;                                    // edx
	int* v14;                                   // ebp
	int v15;                                    // edi
	char* v16;                                  // ebp
	int v17;                                    // ecx
	int v18;                                    // esi
	int v19;                                    // esi
	int v20;                                    // edx
	int v21;                                    // edx
	int v22;                                    // ecx
	int v23;                                    // edx
	int v24;                                    // eax
	int v25;                                    // ecx
	int v26;                                    // esi
	int v27;                                    // ecx
	int i;                                      // esi
	char v29;                                   // al
	unsigned int v30;                           // ecx
	const void* v31;                            // esi
	int v32;                                    // edi
	int j;                                      // esi
	char v34;                                   // al
	char v35;                                   // dl
	int v36;                                    // ecx
	int v37;                                    // esi
	unsigned char v38;                          // dl
	char v39;                                   // al
	int v40;                                    // [esp+10h] [ebp-48h]
	int v41;                                    // [esp+14h] [ebp-44h]
	void (*v42)(char*, char*, int, int*, int*); // [esp+18h] [ebp-40h]
	int v43;                                    // [esp+1Ch] [ebp-3Ch]
	int v44;                                    // [esp+20h] [ebp-38h]
	int2 v45;                                   // [esp+24h] [ebp-34h]
	int2 v46;                                   // [esp+2Ch] [ebp-2Ch]
	int v47;                                    // [esp+34h] [ebp-24h]
	int v48;                                    // [esp+38h] [ebp-20h]
	int v49;                                    // [esp+3Ch] [ebp-1Ch]
	int v50[3];                                 // [esp+40h] [ebp-18h]
	int v51[3];                                 // [esp+4Ch] [ebp-Ch]
	char* v52;                                  // [esp+60h] [ebp+8h]
	int v53;                                    // [esp+64h] [ebp+Ch]
	int v54;                                    // [esp+64h] [ebp+Ch]
	int v55;                                    // [esp+70h] [ebp+18h]
	int v56;                                    // [esp+74h] [ebp+1Ch]
	unsigned char v57;                          // [esp+7Ch] [ebp+24h]
	unsigned char v58;                          // [esp+7Ch] [ebp+24h]
	unsigned char v59;                          // [esp+7Ch] [ebp+24h]
	unsigned char v60;                          // [esp+7Ch] [ebp+24h]
	unsigned char v61;                          // [esp+7Ch] [ebp+24h]

	result = (int*)a1;
	v10 = 0;
	v44 = 0;
	if (!result) {
		return 0;
	}
	v11 = nox_video_bag_image_type(a1);
	v45.field_4 = 0;
	v45.field_0 = 0;
	v46.field_4 = 0;
	v46.field_0 = 0;
	if ((v11 & 0x3F) != 3) {
		return result;
	}
#ifdef NOX_CGO
	v42 = sub_480860;
#else  // NOX_CGO
	v42 = sub_480700;
	if (!cpuid_5d4594_3801804) {
		v42 = sub_480860;
	}
#endif // NOX_CGO
	result = (int*)nox_video_getImagePixdata_42FB30(a1);
	if (!result) {
		return result;
	}
	v12 = *result;
	v13 = result[1] - a9;
	v43 = *result;
	v40 = *result;
	v41 = v13;
	if (v13 <= 0) {
		return result;
	}
	v14 = result + 3;
	result = (int*)(result[2] + a2);
	v15 = *v14;
	v16 = (char*)v14 + 5;
	v17 = v15 + a3;
	v53 = v15 + a3;
	if (!((int)result <= *(int*)&dword_5d4594_3807116 && v17 <= *(int*)&dword_5d4594_3807152)) {
		return result;
	}
	if ((int)result < *(int*)&dword_5d4594_3807140) {
		if ((int)result + v12 < *(int*)&dword_5d4594_3807140) {
			return result;
		}
		v10 = *(int*)&dword_5d4594_3807140 - (int)result;
		v40 = v12 - (*(int*)&dword_5d4594_3807140 - (int)result);
		result = *(int**)&dword_5d4594_3807140;
	}
	if ((int)result + v40 > *(int*)&dword_5d4594_3807116) {
		v40 = *(int*)&dword_5d4594_3807116 - (int)result;
	}
	if (v17 < *(int*)&dword_5d4594_3807136) {
		if (v13 + v17 < *(int*)&dword_5d4594_3807136) {
			return result;
		}
		v18 = *(int*)&dword_5d4594_3807136 - v17;
		v17 = *(int*)&dword_5d4594_3807136;
		v13 -= v18;
		v53 = *(int*)&dword_5d4594_3807136;
		v41 = v13;
		v44 = v18;
	}
	if (v13 + v17 > *(int*)&dword_5d4594_3807152) {
		v13 = *(int*)&dword_5d4594_3807152 - v17;
		v41 = *(int*)&dword_5d4594_3807152 - v17;
	}
	if (!(v40 > 0 && v13 > 0)) {
		return result;
	}
	v19 = a6;
	if (a6 < v17) {
		v19 = v17;
	}
	if (v13 + v17 > v19) {
		v41 = v19 - v17;
	}
	if (a7 <= (int)result + v10) {
		v20 = 0;
	} else {
		v20 = a7 - v10 - (int)result;
		v10 = a7 - (int)result;
		v40 -= v20;
	}
	if (a8 < (int)result + v40 + v10) {
		v40 = a8 - v10 - (int)result;
	}
	if (v40 <= 0) {
		return result;
	}
	v21 = (int)nox_pixbuffer_rows_3798784[v17] + 2 * ((int)result + v20);
	v22 = a4[1];
	v52 = (char*)v21;
	v23 = *a4;
	v49 = a4[2] << 8;
	v23 <<= 8;
	v24 = (*a5 << 8) - v23;
	v47 = v23;
	v48 = v22 << 8;
	v25 = a5[1] << 8;
	v26 = a5[2] << 8;
	v50[0] = v24 / v43;
	v50[1] = (v25 - v48) / v43;
	v50[2] = (v26 - v49) / v43;
	if (v44 > 0) {
		v27 = v44;
		do {
			for (i = v43; i > 0; i -= v57) {
				v29 = *v16;
				v57 = v16[1];
				v16 += 2;
				LOBYTE(a1) = v29;
				if (v29 == 2) {
					v16 += 2 * v57;
				}
			}
			--v27;
		} while (v27);
	}
	v46.field_4 = v53;
	sub_473970(&v46, &v45);
	v30 = 0;
	v31 = 0;
	result = (int*)(v41 - 1);
	if (!v41) {
		return result;
	}
	v56 = v41;
#ifdef NOX_CGO
	int bpitch = nox_getBackbufferPitch();
#else  // NOX_CGO
	int bpitch = nox_backbuffer_pitch_3801808;
#endif // NOX_CGO
	while (1) {
		v32 = 0;
		v54 = 0;
		v55 = 0;
		if (nox_client_highResFrontWalls_80820 || !(v45.field_4 & 1)) {
			if (v10 <= 0) {
				v35 = a1;
			} else {
				do {
					v35 = *v16;
					v59 = v16[1];
					v16 += 2;
					LOBYTE(a1) = v35;
					if (v35 == 2) {
						v16 += 2 * v59;
					}
					v32 += v59;
				} while (v32 < v10);
			}
			if (v32 <= v10) {
				v36 = v40;
			} else {
				v36 = v40;
				v37 = v40;
				if (v32 - v10 <= v40) {
					v37 = v32 - v10;
				}
				if (v35 == 2) {
					v51[0] = v47 + v10 * v50[0];
					v51[1] = v48 + v10 * v50[1];
					v51[2] = v49 + v10 * v50[2];
					v42(v52, &v16[-2 * (v32 - v10)], v37, v51, v50);
					v36 = v40;
					v54 = 2 * v37;
				}
				v55 = 0;
			}
			if (v32 < v36 + v10) {
				do {
					v38 = v16[1];
					LOBYTE(a1) = *v16;
					v16 += 2;
					v60 = v38;
					if ((uint8_t)a1 == 2) {
						if (v38 > v10 + v36 - v32) {
							v55 = v32 + v38 - v36 - v10;
							v60 = -(char)(v32 + -(char)v36 - v10);
						}
						v51[0] = v47 + v50[0] * v32;
						v51[2] = v49 + v50[2] * v32;
						v51[1] = v48 + v50[1] * v32;
						v42(&v52[2 * (v32 - v10)], v16, v60, v51, v50);
						v36 = v40;
						v16 += 2 * v60;
					}
					v32 += v60;
					v54 += 2 * v60;
				} while (v32 < v36 + v10);
				if (v55) {
					if ((uint8_t)a1 == 2) {
						v16 += 2 * v55;
					}
					v32 += v55;
				}
			}
			for (; v32 < v43; v32 += v61) {
				v39 = *v16;
				v61 = v16[1];
				v16 += 2;
				LOBYTE(a1) = v39;
				if (v39 == 2) {
					v16 += 2 * v61;
				}
			}
		} else {
			if (v31 && v30) {
				memcpy(v52, v31, v30);
			}
			for (j = v43; j > 0; j -= v58) {
				v34 = *v16;
				v58 = v16[1];
				v16 += 2;
				LOBYTE(a1) = v34;
				if (v34 == 2) {
					v16 += 2 * v58;
				}
			}
		}
		v31 = v52;
		v52 += bpitch;
		++v45.field_4;
		result = (int*)--v56;
		if (!v56) {
			break;
		}
		v30 = v54;
	}
	return result;
}

//----- (00481410) --------------------------------------------------------
void sub_481410() { nox_xxx_waypointCounterMB_587000_154948 = -1; }

//----- (00481420) --------------------------------------------------------
int nox_xxx_tileSetDrawFn_481420() {
	int result; // eax

	result = nox_client_texturedFloors_154956;
	if (nox_client_texturedFloors_154956) {
		func_587000_154940 = nox_xxx_tileDraw_4815E0;
		func_587000_154944 = nox_xxx_drawTexEdgesProbably_481900;
	} else {
		func_587000_154940 = sub_481770;
		func_587000_154944 = nullsub_8;
	}
	dword_5d4594_1193188 = 1;
	return result;
}
// 481BE0: using guessed type void nullsub_8();

#ifndef NOX_CGO
//----- (004814F0) --------------------------------------------------------
int sub_4814F0(nox_point* a1) {
	int v5;            // edi
	unsigned char* v6; // eax
	int result;        // eax

	nox_light_3 c1 = nox_arr2_853BC0[a1->x][a1->y + 0];
	int v2 = c1.r >> 8;
	int v3 = c1.g >> 8;
	int v4 = c1.b >> 8;

	nox_light_3 c2 = nox_arr2_853BC0[a1->x][a1->y + 1];
	int v2b = c2.r >> 8;
	int v3b = c2.g >> 8;
	int v4b = c2.b >> 8;

	int v8 = *getMemU32Ptr(0x8529A0, 1020 + 4 * ((v2b - v2) >> 8));
	int v9 = *getMemU32Ptr(0x8529A0, 1020 + 4 * ((v3b - v3) >> 8));
	int v10 = *getMemU32Ptr(0x8529A0, 1020 + 4 * ((v4b - v4) >> 8));
	v5 = 0;
	do {
		v6 = ((void*)&nox_arr_84EB20[4 + 280 * a1->x + v5]);
		v5 += 12;
		*((uint32_t*)v6 + 0) = v2;
		*((uint32_t*)v6 + 1) = v3;
		*((uint32_t*)v6 + 2) = v4;
		v2 += v8;
		v3 += v9;
		v4 += v10;
	} while (v5 < 12 * 23);
	result = 7 * a1->x;
	*((unsigned int*)&nox_arr_84EB20[280 * a1->x]) = a1->y;
	return result;
}
#endif // NOX_CGO

//----- (004815E0) --------------------------------------------------------
char nox_xxx_tileDraw_4815E0(uint32_t* a1, int a2) {
	unsigned int v2; // ebx
	int v3;          // eax
	char* v4;        // esi
	unsigned int v5; // edi
	int v6;          // eax
	int v7;          // edx
	unsigned int v8; // ebp
	signed int v9;   // eax
	char* v10;       // edi
	char* v11;       // esi
	char v12;        // cl
	char* v14;       // [esp+10h] [ebp+4h]
	int i;           // [esp+14h] [ebp+8h]

	v2 = dword_5d4594_3798804 * (dword_5d4594_3798840 + a1[1] - dword_5d4594_3798824) + dword_5d4594_3798796 +
		 ((dword_5d4594_3798836 + *a1 - dword_5d4594_3798820) << getMemByte(0x973F18, 7696));
	if (v2 >= *(int*)&dword_5d4594_3798844) {
		v2 += dword_5d4594_3798796 - dword_5d4594_3798844;
	}
	v3 = nox_video_getImagePixdata_42FB30(a2);
	v4 = (char*)v3;
	v14 = (char*)v3;
	if (v3) {
		v5 = dword_5d4594_3798844;
		if (v2 + *getMemIntPtr(0x973CE0, 376) >= *(int*)&dword_5d4594_3798844) {
			v6 = 0;
			for (i = 0;; v6 = i) {
				v7 = *getMemU32Ptr(0x973CE0, 192 + v6) << getMemByte(0x973F18, 7696);
				v8 = *getMemU32Ptr(0x973CE0, 384 + v6) << getMemByte(0x973F18, 7696);
				if (v2 + v7 + v8 < v5) {
					memcpy((void*)(v7 + v2), v4, 4 * (v8 >> 2));
					v11 = &v4[4 * (v8 >> 2)];
					v10 = (char*)(v7 + v2 + 4 * (v8 >> 2));
					v12 = v8;
				} else {
					v9 = v5 - v7 - v2;
					if (v9 > 0) {
						memcpy((void*)(v7 + v2), v4, v9);
						memcpy(*(void**)&dword_5d4594_3798796, &v14[v9], v8 - v9);
						v5 = dword_5d4594_3798844;
						v2 += dword_5d4594_3798796 - dword_5d4594_3798844;
						goto LABEL_13;
					}
					v2 += dword_5d4594_3798796 - v5;
					memcpy((void*)(v7 + v2), v4, 4 * (v8 >> 2));
					v11 = &v4[4 * (v8 >> 2)];
					v10 = (char*)(v7 + v2 + 4 * (v8 >> 2));
					v12 = v8;
				}
				memcpy(v10, v11, v12 & 3);
				v5 = dword_5d4594_3798844;
			LABEL_13:
				v2 += dword_5d4594_3798804;
				v14 += v8;
				LOBYTE(v3) = i + 4;
				i += 4;
				if (i >= 184) {
					return v3;
				}
				v4 = v14;
			}
		} else {
#ifndef NOX_CGO
			if (nox_video_pixmode_3799624) {
				LOBYTE(v3) = sub_4831C0(v3, v2);
			} else {
				LOBYTE(v3) = sub_482910(v3, v2);
			}
#else  // NOX_CGO
			LOBYTE(v3) = sub_4831C0(v3, v2);
#endif // NOX_CGO
		}
	}
	return v3;
}

//----- (00481770) --------------------------------------------------------
char* sub_481770(uint32_t* a1, int a2, unsigned short a3) {
	int v3;           // ebp
	unsigned char v4; // cl
	unsigned int v5;  // edx
	unsigned int v6;  // esi
	int v7;           // ebx
	int v8;           // eax
	int v9;           // edi
	int v10;          // ebx
	char* result;     // eax
	int v12;          // [esp+Ch] [ebp+Ch]

	if (!nox_client_texturedFloors_154956 && (getMemByte(0x85B3FC, 32542 + 60 * a3) & 1) == 1) {
		dword_5d4594_1193156 = 1;
	}
	v3 = *getMemU32Ptr(0x85B3FC, 32532 + 60 * a3);
	v4 = getMemByte(0x973F18, 7696);
	v5 = dword_5d4594_3798844;
	v6 = dword_5d4594_3798804 * (dword_5d4594_3798840 + a1[1] - dword_5d4594_3798824) + dword_5d4594_3798796 +
		 ((dword_5d4594_3798836 + *a1 - dword_5d4594_3798820) << getMemByte(0x973F18, 7696));
	if (v6 >= *(int*)&dword_5d4594_3798844) {
		v6 += dword_5d4594_3798796 - dword_5d4594_3798844;
	}
	if (v6 + *getMemU32Ptr(0x973CE0, 376) < *(int*)&dword_5d4594_3798844) {
#ifndef NOX_CGO
		if (nox_video_pixmode_3799624) {
			result = (char*)sub_484450(v3, v6);
		} else {
			result = (char*)sub_483FE0(v3, v6);
		}
#else  // NOX_CGO
		result = (char*)sub_484450(v3, v6);
#endif // NOX_CGO
	} else {
		v7 = 0;
		v12 = 0;
		while (1) {
			v8 = *getMemU32Ptr(0x973CE0, 192 + v7) << v4;
			v9 = *getMemU32Ptr(0x973CE0, 384 + v7) << v4;
			if (v6 + v9 + v8 < v5) {
				result = (char*)sub_49D1C0(v6 + v8, v3, v9);
				v5 = dword_5d4594_3798844;
			} else {
				v10 = v5 - v8 - v6;
				if (v10 <= 0) {
					v6 += dword_5d4594_3798796 - v5;
					result = (char*)sub_49D1C0(v6 + v8, v3, v9);
					v5 = dword_5d4594_3798844;
					v7 = v12;
				} else {
					sub_49D1C0(v6 + v8, v3, v5 - v8 - v6);
					sub_49D1C0(*(int*)&dword_5d4594_3798796, v3, v9 - v10);
					v5 = dword_5d4594_3798844;
					v7 = v12;
					result = (char*)(dword_5d4594_3798796 - dword_5d4594_3798844);
					v6 += dword_5d4594_3798796 - dword_5d4594_3798844;
				}
			}
			v7 += 4;
			v6 += dword_5d4594_3798804;
			v12 = v7;
			if (v7 >= 184) {
				break;
			}
			v4 = getMemByte(0x973F18, 7696);
		}
	}
	return result;
}

//----- (00481900) --------------------------------------------------------
char nox_xxx_drawTexEdgesProbably_481900(uint32_t* a1, uint32_t* a2) {
	int v2;            // ebx
	int v3;            // esi
	int v4;            // edx
	int v5;            // ebp
	int v6;            // eax
	int v7;            // edi
	int v8;            // edi
	int v9;            // eax
	uint8_t* v10;      // ebx
	int v11;           // ebp
	unsigned int v12;  // esi
	unsigned int v13;  // edi
	char* v14;         // ebp
	char* v15;         // edx
	int v16;           // ebx
	char* v17;         // edi
	unsigned int v18;  // ecx
	char* v19;         // esi
	unsigned int v20;  // eax
	int v22;           // eax
	int v24;           // [esp+10h] [ebp-1Ch]
	unsigned char v25; // [esp+14h] [ebp-18h]
	char* v26;         // [esp+14h] [ebp-18h]
	char* v27;         // [esp+18h] [ebp-14h]
	int v28;           // [esp+1Ch] [ebp-10h]
	unsigned char v29; // [esp+20h] [ebp-Ch]
	int v30;           // [esp+28h] [ebp-4h]
	unsigned int v31;  // [esp+30h] [ebp+4h]
	unsigned char v32; // [esp+34h] [ebp+8h]
	char* v33;         // [esp+34h] [ebp+8h]
	int* addr;

	v2 = dword_5d4594_3798824;
	v3 = *(uint32_t*)(*getMemU32Ptr(0x85B3FC, 32516 + 60 * *a2) +
					  4 * (a2[1] + *getMemU16Ptr(0x85B3FC, 32530 + 60 * *a2)));
	v4 = a2[2];
	v5 = dword_5d4594_3798836;
	addr = (*getMemU32Ptr(0x85B3FC, 28676 + 60 * v4) + 4 * (a2[3] + *getMemU16Ptr(0x85B3FC, 28690 + 60 * v4)));
	v6 = *(uint32_t*)addr;
	v7 = dword_5d4594_3798840;
	*getMemU32Ptr(0x5D4594, 2523980 + 4 * v4) = 1;
	v8 = dword_5d4594_3798804 * (v7 + a1[1] - v2) + dword_5d4594_3798796 +
		 ((v5 + *a1 - dword_5d4594_3798820) << getMemByte(0x973F18, 7696));
	v9 = nox_video_getImagePixdata_42FB30(v6);
	if (v9) {
		v32 = *(uint8_t*)v9;
		v25 = *(uint8_t*)(v9 + 1);
		v10 = (uint8_t*)(v9 + 2);
		v9 = nox_video_getImagePixdata_42FB30(v3);
		v11 = v9;
		if (v9) {
			v12 = dword_5d4594_3798844;
			v9 = v32;
			v13 = dword_5d4594_3798804 * v32 + v8;
			v31 = v13;
			v14 = (char*)((*getMemU32Ptr(0x973CE0, +4 * v32) << getMemByte(0x973F18, 7696)) + v11);
			v27 = v14;
			if (v13 >= *(int*)&dword_5d4594_3798844) {
				v13 += dword_5d4594_3798796 - dword_5d4594_3798844;
				v31 = v13;
			}
			v28 = v32;
			v30 = v25;
			if (v32 <= (int)v25) {
				do {
					v24 = *getMemU32Ptr(0x973CE0, 384 + 4 * v9);
					v26 = v14;
					v15 = (char*)(v13 + (*getMemU32Ptr(0x973CE0, 192 + 4 * v9) << getMemByte(0x973F18, 7696)));
					if (v24 > 0) {
						do {
							LOBYTE(v9) = *v10;
							v29 = v10[1];
							v33 = v10 + 2;
							v16 = v29 << getMemByte(0x973F18, 7696);
							switch ((uint8_t)v9) {
							case 2:
								if ((unsigned int)&v15[v16] < v12) {
									v19 = v33;
									v18 = v29 << getMemByte(0x973F18, 7696);
									v17 = v15;
								} else {
									memcpy(v15, v33, v12 - (uint32_t)v15);
									v17 = *(char**)&dword_5d4594_3798796;
									v18 = v16 - (v12 - (uint32_t)v15);
									v19 = &v33[v12 - (uint32_t)v15];
								}
								memcpy(v17, v19, v18);
								v12 = dword_5d4594_3798844;
								v13 = v31;
								v33 += v16;
								break;
							case 3:
								if ((unsigned int)&v15[v16] < v12) {
									memcpy(v15, v14, v16);
								} else {
									v20 = v12 - (uint32_t)v15;
									memcpy(v15, v14, v20);
									v14 = v26;
									memcpy(*(void**)&dword_5d4594_3798796, &v26[v20], v16 - v20);
								}
								v12 = dword_5d4594_3798844;
								v13 = v31;
								break;
							case 1:
								break;
							default:
								return v9;
							}
							v15 += v16;
							v22 = v24 - v29;
							v14 += v16;
							v24 -= v29;
							v26 = v14;
							if ((unsigned int)v15 >= v12) {
								v15 += dword_5d4594_3798796 - v12;
							}
							v10 = v33;
						} while (v22 > 0);
						v9 = v28;
					}
					v14 = &v27[*getMemU32Ptr(0x973CE0, 384 + 4 * v9) << getMemByte(0x973F18, 7696)];
					v13 += dword_5d4594_3798804;
					v27 += *getMemU32Ptr(0x973CE0, 384 + 4 * v9) << getMemByte(0x973F18, 7696);
					v31 = v13;
					if (v13 >= v12) {
						v13 += dword_5d4594_3798796 - v12;
						v31 = v13;
					}
					v28 = ++v9;
				} while (v9 <= v30);
			}
		}
	}
	return v9;
}

//----- (00481BF0) --------------------------------------------------------
void nox_xxx_tileCallDrawEdges_481BF0(int a1, int a2) {
	int i; // esi

	for (i = a2; i; i = *(uint32_t*)(i + 16)) {
		func_587000_154944(a1, i);
	}
}
// 5ACD40: invalid function type has been ignored

//----- (00481C20) --------------------------------------------------------
void nox_xxx_tileDrawMB_481C20_A(nox_draw_viewport_t* vp, int v3) {
	int v17; // esi
	int v63; // [esp-8h] [ebp-54h]
	int v16; // edi
	int v62; // [esp-8h] [ebp-54h]
	int v14; // esi
	int v15; // edi
	int v13; // ecx
	int v12; // eax
	int v11; // ebx
	int v4;  // eax
	int v6;  // ecx
	int v10; // esi
	int v9;  // edx
	int v7;  // edx
	int v8;  // eax
	int j;
	int2 v68; // [esp+1Ch] [ebp-30h]
	if (v3 >= *(int*)&dword_5d4594_3798820 + 23) {
		int v71 = nox_getBackbufWidth() + v3;
		if (v71 <= *(int*)&dword_5d4594_3798800 + dword_5d4594_3798820 - 46 ||
			*(int*)&dword_5d4594_3798812 + *(int*)&dword_5d4594_3798828 - 1 >= 128) {
			return;
		}
		if (v71 > *(int*)&dword_5d4594_3798800 + *(int*)&dword_5d4594_3798820) {
			nox_xxx_tileDrawImpl_4826A0(vp);
			return;
		}
		v7 = dword_5d4594_3798828 + 1;
		dword_5d4594_3798828 = v7;
		v8 = dword_5d4594_3798820 + 46;
		dword_5d4594_3798820 += 46;
		j = dword_5d4594_3798812 + v7 - 2;
		v9 = dword_5d4594_3798836 + 46;
		dword_5d4594_3798836 += 46;
		if (*(int*)&dword_5d4594_3798836 >= *(int*)&dword_5d4594_3798800) {
			dword_5d4594_3798836 = v9 - dword_5d4594_3798800;
			v10 = ++dword_5d4594_3798840;
			if (*(int*)&dword_5d4594_3798840 >= *(int*)&dword_5d4594_3798808) {
				dword_5d4594_3798840 = v10 - dword_5d4594_3798808;
			}
		}
		v4 = dword_5d4594_3798800 + v8 - 92;
	} else {
		if (*(int*)&dword_5d4594_3798828 <= 0) {
			return;
		}
		if (v3 < *(int*)&dword_5d4594_3798820 - 23) {
			nox_xxx_tileDrawImpl_4826A0(vp);
			return;
		}
		v4 = dword_5d4594_3798820 - 46;
		j = --dword_5d4594_3798828;
		dword_5d4594_3798820 -= 46;
		dword_5d4594_3798836 -= 46;
		if (*(int*)&dword_5d4594_3798836 < 0) {
			v6 = *(int*)&dword_5d4594_3798840 - 1;
			bool v5 = *(int*)&dword_5d4594_3798840 - 1 < 0;
			dword_5d4594_3798836 += dword_5d4594_3798800;
			--*(int*)&dword_5d4594_3798840;
			if (v5) {
				*(int*)&dword_5d4594_3798840 = *(int*)&dword_5d4594_3798808 + v6;
			}
		}
	}
	int v76 = v4;
	sub_481410();
	v11 = dword_5d4594_3798824;
	unsigned int v74 = dword_5d4594_3798832;
	if (*(int*)&dword_5d4594_3798832 < *(int*)&dword_5d4594_3798832 + *(int*)&dword_5d4594_3798816) {
		v12 = 44 * dword_5d4594_3798832;
		for (int i = 44 * dword_5d4594_3798832;; v12 = i) {
			HIWORD(v13) = HIWORD(ptr_5D4594_2650668); // TODO: why it's doing it?
			v14 = v12 + (uint32_t)(ptr_5D4594_2650668[j]);
			if (*(uint8_t*)v14 & 2) {
				LOWORD(v13) = *(uint16_t*)(v14 + 24);
				v15 = *(unsigned short*)(v14 + 24);
				v62 = *(uint32_t*)(*getMemU32Ptr(0x85B3FC, 32516 + 60 * v15) +
								   4 * (*(uint32_t*)(v14 + 28) + *getMemU16Ptr(0x85B3FC, 32530 + 60 * v15)));
				v68.field_0 = v76;
				v68.field_4 = v11 + 23;
				func_587000_154940(&v68, v62, v13);
				*getMemU32Ptr(0x85B3FC, 228 + 4 * v15) = 1;
				if (*(uint32_t*)(v14 + 40)) {
					nox_xxx_tileCallDrawEdges_481BF0((int)&v68, *(uint32_t*)(v14 + 40));
				}
			}
			if (*(uint8_t*)v14 & 1) {
				LOWORD(v13) = *(uint16_t*)(v14 + 4);
				v16 = *(unsigned short*)(v14 + 4);
				v63 = *(uint32_t*)(*getMemU32Ptr(0x85B3FC, 32516 + 60 * v16) +
								   4 * (*(uint32_t*)(v14 + 8) + *getMemU16Ptr(0x85B3FC, 32530 + 60 * v16)));
				v68.field_0 = v76 + 23;
				v68.field_4 = v11;
				func_587000_154940(&v68, v63, v13);
				*getMemU32Ptr(0x85B3FC, 228 + 4 * v16) = 1;
				v17 = *(uint32_t*)(v14 + 20);
				if (v17) {
					nox_xxx_tileCallDrawEdges_481BF0((int)&v68, v17);
				}
			}
			v11 += 46;
			bool v18 = (int)++v74 < *(int*)&dword_5d4594_3798832 + dword_5d4594_3798816;
			i += 44;
			if (!v18) {
				break;
			}
		}
	}
}

void nox_xxx_tileDrawMB_481C20_B(nox_draw_viewport_t* vp, int v78) {
	int v33;  // esi
	int v65;  // [esp-8h] [ebp-54h]
	int v32;  // edi
	int2 v68; // [esp+1Ch] [ebp-30h]
	int v64;  // [esp-8h] [ebp-54h]
	int v31;  // edi
	int v28;  // esi
	char v29; // al
	int v30;  // esi
	int v27;  // ecx
	int v25;  // eax
	int v26;  // ebx
	int v21;  // eax
	int v20;  // edi
	int v19;  // esi
	int v23;  // edi
	int v24;  // ecx
	int v22;  // esi
	int v76;
	if ((int)v78 >= *(int*)&dword_5d4594_3798824 + 23) {
		if ((int)v78 + nox_getBackbufHeight() <= *(int*)&dword_5d4594_3798824 + *(int*)&dword_5d4594_3798808) {
			return;
		}
		v22 = dword_5d4594_3798832;
		if (*(int*)&dword_5d4594_3798832 + *(int*)&dword_5d4594_3798816 >= 128) {
			return;
		}
		if ((int)v78 + nox_getBackbufHeight() > *(int*)&dword_5d4594_3798824 + *(int*)&dword_5d4594_3798808 + 46) {
			nox_xxx_tileDrawImpl_4826A0(vp);
			return;
		}
		++dword_5d4594_3798832;
		v23 = dword_5d4594_3798824 + 46;
		v19 = dword_5d4594_3798816 + v22;
		v24 = dword_5d4594_3798840 + 46;
		dword_5d4594_3798824 += 46;
		dword_5d4594_3798840 += 46;
		if (*(int*)&dword_5d4594_3798840 >= *(int*)&dword_5d4594_3798808) {
			dword_5d4594_3798840 = v24 - dword_5d4594_3798808;
		}
		v76 = v23 + dword_5d4594_3798808 - 46;
	} else {
		if (*(int*)&dword_5d4594_3798832 <= 0) {
			return;
		}
		if ((int)v78 < *(int*)&dword_5d4594_3798824 - 23) {
			nox_xxx_tileDrawImpl_4826A0(vp);
			return;
		}
		v19 = dword_5d4594_3798832 - 1;
		v20 = dword_5d4594_3798824 - 46;
		v21 = dword_5d4594_3798840 - 46;
		bool v5 = *(int*)&dword_5d4594_3798840 - 46 < 0;
		--dword_5d4594_3798832;
		dword_5d4594_3798824 -= 46;
		dword_5d4594_3798840 -= 46;
		if (v5) {
			dword_5d4594_3798840 = dword_5d4594_3798808 + v21;
		}
		v76 = v20;
	}
	sub_481410();
	v25 = dword_5d4594_3798828;
	v26 = dword_5d4594_3798820;
	int i = dword_5d4594_3798828;
	int j = dword_5d4594_3798812 + dword_5d4594_3798828 - 1;
	if (dword_5d4594_3798828 < j) {
		v27 = 44 * v19;
		int v71 = 44 * v19;
		while (1) {
			v28 = ptr_5D4594_2650668[v25];
			v29 = *(uint8_t*)(v28 + v27);
			v30 = v27 + v28;
			if (v29 & 2) {
				LOWORD(v27) = *(uint16_t*)(v30 + 24);
				v31 = *(unsigned short*)(v30 + 24);
				v64 = *(uint32_t*)(*getMemU32Ptr(0x85B3FC, 32516 + 60 * v31) +
								   4 * (*(uint32_t*)(v30 + 28) + *getMemU16Ptr(0x85B3FC, 32530 + 60 * v31)));
				v68.field_0 = v26;
				v68.field_4 = v76 + 23;
				func_587000_154940(&v68, v64, v27);
				*getMemU32Ptr(0x85B3FC, 228 + 4 * v31) = 1;
				if (*(uint32_t*)(v30 + 40)) {
					nox_xxx_tileCallDrawEdges_481BF0((int)&v68, *(uint32_t*)(v30 + 40));
				}
			}
			if (*(uint8_t*)v30 & 1) {
				LOWORD(v27) = *(uint16_t*)(v30 + 4);
				v32 = *(unsigned short*)(v30 + 4);
				v65 = *(uint32_t*)(*getMemU32Ptr(0x85B3FC, 32516 + 60 * v32) +
								   4 * (*(uint32_t*)(v30 + 8) + *getMemU16Ptr(0x85B3FC, 32530 + 60 * v32)));
				v68.field_0 = v26 + 23;
				v68.field_4 = v76;
				func_587000_154940(&v68, v65, v27);
				*getMemU32Ptr(0x85B3FC, 228 + 4 * v32) = 1;
				v33 = *(uint32_t*)(v30 + 20);
				if (v33) {
					nox_xxx_tileCallDrawEdges_481BF0((int)&v68, v33);
				}
			}
			v26 += 46;
			if (++i >= j) {
				break;
			}
			v27 = v71;
			v25 = i;
		}
	}
}
void nox_xxx_tileDrawMB_481C20_C_textured(nox_draw_viewport_t* vp, int v72, int v78) {
	unsigned char* v48; // eax
	int v49;            // ecx
	int v50;            // eax
	unsigned char* v51; // esi
	int v52;            // eax
	int* v53;           // ebx
	int v54;            // esi
	int v55;            // eax
	unsigned int v56;   // ecx
	unsigned int v57;   // eax
	int v58;            // eax
	int v59;            // edi
	int v60;            // edx
	int v61;            // esi
	int2 v66;           // [esp+Ch] [ebp-40h]
	int2 v67;           // [esp+14h] [ebp-38h]
	int v69;            // [esp+24h] [ebp-28h]
	int v70;            // [esp+28h] [ebp-24h]
	unsigned char* v75; // [esp+3Ch] [ebp-10h]
	int v80;            // [esp+54h] [ebp+8h]
	v67.field_4 = v78 + dword_5d4594_3679320;
	sub_4745F0(vp);
	v48 = nox_arr_84EB20;
	do {
		*(uint32_t*)v48 = -1;
		v48 += 280;
	} while ((int)(v48 - (unsigned char*)nox_arr_84EB20) < sizeof(nox_arr_84EB20));
	v66.field_4 = (v67.field_4 - *(int*)&dword_5d4594_2650680) / 23;
	v49 = dword_5d4594_3679320;
	v50 = v67.field_4 - 23 * v66.field_4 - dword_5d4594_2650680;
	v78 = v67.field_4 - 23 * v66.field_4 - dword_5d4594_2650680;
	v80 = dword_5d4594_3679320;
	if (*(int*)&dword_5d4594_3679320 < *(int*)&dword_5d4594_3798156) {
		v51 = ((void*)&nox_arr_957820[128 * dword_5d4594_3679320]);
		int v76 = 4 * dword_5d4594_3679320 - 4;
		unsigned char ishift = getMemByte(0x973F18, 7696);
		void* func1 = getMemAt(0x973F18, 7720);
		for (int j = ((void*)&nox_arr_957820[128 * dword_5d4594_3679320]);; v51 = (unsigned char*)j) {
			int i = (uint32_t)nox_pixbuffer_rows_3798784[v49];
			if (v50 == 23) {
				v78 = 0;
				++v66.field_4;
			}
			v52 = nox_arr_956A00[v76 / 4 + 1];
			v53 = (int*)v51;
			// low-res floors basically skip each second row (interlacing) and then duplicate result from the first row
			if (nox_client_highResFloors_154952 || !(v67.field_4 & 1) || v51 == nox_arr_957820) {
				if (v52 > 0) {
					int v71 = (unsigned int)(v52 + 1) >> 1;
					do {
						v58 = v53[1];
						v69 = *v53;
						v59 = v69 + v72;
						v53 += 2;
						v67.field_0 = v69 + v72;
						v60 = (v69 + v72 - *(int*)&dword_5d4594_2650676) / 23;
						v66.field_0 = v60;
						v70 = (v69 + v72 - *(int*)&dword_5d4594_2650676) / 23;
						v61 = dword_5d4594_2650676 + 23 * v60;
						unsigned int v74 = v58 - v69;
						v75 = ((void*)&nox_arr_84EB20[280 * v60]);
						if (v61 < v58 + v72 + 23) {
							do {
								if (*(uint32_t*)v75 != v66.field_4) {
									(*(int (**)(int2*))func1)(&v66);
									v59 = v67.field_0;
									v60 = v66.field_0;
								}
								v61 += 23;
								v75 += 280;
								v66.field_0 = ++v60;
							} while (v61 < (int)(v74 + v59 + 23));
						}
						v66.field_0 = v70;
						(*(void (**)(int2*, int*, uint32_t, uint32_t, uint32_t)) &
						 dword_5d4594_3805484)(&v67, &v66.field_0, v78, v74, i + (v69 << ishift));
						--v71;
					} while (v71);
				}
			} else if (v52 > 0) {
				// remove interlacing
				unsigned int v74 = (unsigned int)(v52 + 1) >> 1;
				do {
					v54 = *v53;
					v55 = v53[1];
					v53 += 2;
					v56 = (v55 - v54) << ishift;
					v57 = v74;
					memcpy((void*)(i + (v54 << ishift)),
						   (const void*)((v54 << ishift) + (uint32_t)nox_pixbuffer_rows_3798784[v76 / 4]), v56);
					v74 = v57 - 1;
				} while (v57 != 1);
			}
			++v78;
			bool v18 = ++v80 < *(int*)&dword_5d4594_3798156;
			j += 128;
			v76 += 4;
			++v67.field_4;
			if (!v18) {
				break;
			}
			v49 = v80;
			v50 = v78;
		}
	}
#if 0
	if (*(uint32_t*)& dword_5d4594_805836)
		_m_femms();
#endif
}
void nox_xxx_tileDrawMB_481C20_C_solid(nox_draw_viewport_t* vp, int v72, int v78) {
	unsigned char* v35; // ebx
	int v36;            // eax
	int v37;            // eax
	int v38;            // edx
	char* v39;          // esi
	unsigned int v40;   // eax
	int v41;            // eax
	char* v42;          // edi
	char* v43;          // edi
	char* v44;          // esi
	char v45;           // cl
	bool v46;           // zf
	int v47;            // eax
	int2 v67;           // [esp+14h] [ebp-38h]
	int v79;            // [esp+54h] [ebp+8h]
	v67.field_4 = v78 + dword_5d4594_3679320;
	sub_4745F0(vp);
	v79 = dword_5d4594_3679320;
	if (*(int*)&dword_5d4594_3679320 < *(int*)&dword_5d4594_3798156) {
		unsigned char* v78a = ((void*)&nox_arr_957820[128 * dword_5d4594_3679320]);
		bool v18;
		do {
			v35 = v78a;
			v36 = nox_arr_956A00[v79];
			int i = nox_pixbuffer_rows_3798784[v79];
			if (v36 > 0) {
				int j = (unsigned int)(v36 + 1) >> 1;
				do {
					v37 = *(uint32_t*)v35;
					v38 = *((uint32_t*)v35 + 1) - *(uint32_t*)v35;
					v67.field_0 = *(uint32_t*)v35 + v72;
					v35 += 8;
					v39 = (char*)(dword_5d4594_3798804 * (v67.field_4 + dword_5d4594_3798840 - dword_5d4594_3798824) +
								  dword_5d4594_3798796 +
								  ((v37 + v72 + dword_5d4594_3798836 - dword_5d4594_3798820)
								   << getMemByte(0x973F18, 7696)));
					if ((unsigned int)v39 >= *(int*)&dword_5d4594_3798844) {
						v39 += dword_5d4594_3798796 - dword_5d4594_3798844;
					}
					int v76 = i + (v37 << getMemByte(0x973F18, 7696));
					v40 = v38 << getMemByte(0x973F18, 7696);
					if ((unsigned int)&v39[v38 << getMemByte(0x973F18, 7696)] < *(int*)&dword_5d4594_3798844) {
						v42 = (char*)v76;
						memcpy((void*)v76, v39, 4 * (v40 >> 2));
					} else {
						v41 = dword_5d4594_3798844 - (uint32_t)v39;
						memcpy((void*)v76, v39, dword_5d4594_3798844 - (uint32_t)v39);
						v39 = *(char**)&dword_5d4594_3798796;
						v42 = (char*)(v41 + v76);
						v40 = (v38 << getMemByte(0x973F18, 7696)) - v41;
						memcpy(v42, *(const void**)&dword_5d4594_3798796, 4 * (v40 >> 2));
					}
					v44 = &v39[4 * (v40 >> 2)];
					v43 = &v42[4 * (v40 >> 2)];
					v45 = v40;
					v47 = j - 1;
					v46 = j == 1;
					memcpy(v43, v44, v45 & 3);
					j = v47;
				} while (!v46);
			}
			v18 = ++v79 < *(int*)&dword_5d4594_3798156;
			v78a += 128;
			++v67.field_4;
		} while (v18);
	}
}
#ifndef NOX_CGO
void nox_xxx_tileDrawMB_481C20(nox_draw_viewport_t* vp) {
	int v1;             // esi
	int v2;             // edx
	int v3;             // esi
	int v72;            // [esp+30h] [ebp-1Ch]
	unsigned char* v78; // [esp+48h] [ebp-4h]

	++nox_xxx_waypointCounterMB_587000_154948;
	int* a1 = vp;
	v1 = a1[4];
	v2 = *a1;
	v78 = (unsigned char*)(a1[5] - a1[1]);
	v3 = v1 - v2;
	v72 = v3;
	if (!nox_client_texturedFloors_154956 && dword_5d4594_1193156 == 1) {
		nox_client_texturedFloors2_154960 = 0;
		nox_client_texturedFloors_154956 = 1;
		nox_xxx_tileSetDrawFn_481420();
	}
	if (dword_5d4594_1193156 == 1 && !nox_client_texturedFloors2_154960 && !(nox_frame_xxx_2598000 % 0x1Eu) &&
		!nox_xxx_tileCheckRedrawMB_482570(vp)) {
		dword_5d4594_1193156 = 0;
		nox_client_texturedFloors_154956 = nox_client_texturedFloors2_154960;
		nox_xxx_tileSetDrawFn_481420();
	}
	if (dword_5d4594_1193188) {
		nox_xxx_tileDrawImpl_4826A0(vp);
		dword_5d4594_1193188 = 0;
	} else {
		nox_xxx_tileDrawMB_481C20_A(vp, v3);
		nox_xxx_tileDrawMB_481C20_B(vp, v78);
	}
	if (nox_client_texturedFloors_154956) {
		nox_xxx_tileDrawMB_481C20_C_textured(vp, v72, v78);
	} else {
		nox_xxx_tileDrawMB_481C20_C_solid(vp, v72, v78);
	}
}
#endif // NOX_CGO
// 481F0B: variable 'v13' is possibly undefined
// 482142: variable 'v27' is possibly undefined

//----- (00482570) --------------------------------------------------------
int nox_xxx_tileCheckRedrawMB_482570(nox_draw_viewport_t* vp) {
	uint32_t* a1 = vp;
	int v1;       // esi
	int v2;       // ebx
	int v3;       // eax
	int v4;       // edx
	int i;        // ebp
	int v6;       // edi
	uint32_t* v7; // esi
	int v8;       // eax
	int v10;      // [esp+10h] [ebp-8h]
	int v11;      // [esp+14h] [ebp-4h]
	int v12;      // [esp+1Ch] [ebp+4h]

	v1 = a1[5] - a1[1];
	v2 = (a1[4] - *a1 - 11) / 46;
	if (v2 < 0) {
		v2 = 0;
	}
	v12 = dword_5d4594_3798812 + v2 - 1;
	if (v12 >= 128) {
		v12 = 127;
		v2 = 127 - dword_5d4594_3798812;
	}
	v3 = (v1 - 11) / 46 - 1;
	if (v3 < 0) {
		v3 = 0;
	}
	v4 = dword_5d4594_3798816 + v3;
	v10 = dword_5d4594_3798816 + v3;
	if (*(int*)&dword_5d4594_3798816 + v3 >= 128) {
		v10 = 127;
		v3 = 127 - dword_5d4594_3798816;
		v4 = 127;
	}
	v11 = v3;
	if (v3 >= v4) {
		return 0;
	}
	for (i = 44 * v3;; i += 44) {
		v6 = v2;
		if (v2 < v12) {
			break;
		}
	LABEL_19:
		if (++v11 >= v4) {
			return 0;
		}
	}
	v7 = &ptr_5D4594_2650668[v2];
	while (1) {
		v8 = i + *v7;
		if (*(uint8_t*)v8 & 1) {
			if ((getMemByte(0x85B3FC, 32542 + 60 * *(uint32_t*)(v8 + 4)) & 1) == 1) {
				return 1;
			}
		}
		if (*(uint8_t*)v8 & 2 && (getMemByte(0x85B3FC, 32542 + 60 * *(uint32_t*)(v8 + 24)) & 1) == 1) {
			return 1;
		}
		++v6;
		++v7;
		if (v6 >= v12) {
			v4 = v10;
			goto LABEL_19;
		}
	}
}

//----- (004826A0) --------------------------------------------------------
int nox_xxx_tileDrawImpl_4826A0(nox_draw_viewport_t* vp) {
	uint32_t* a1 = vp;
	int v1;     // esi
	int v2;     // ebx
	int result; // eax
	int v4;     // ecx
	int v5;     // esi
	int v6;     // ebx
	int v7;     // ecx
	int v8;     // ebp
	int v9;     // eax
	int v10;    // ecx
	int v11;    // esi
	char v12;   // al
	int v13;    // esi
	int v14;    // edi
	int v15;    // edi
	int v16;    // esi
	bool v17;   // zf
	int v18;    // [esp-8h] [ebp-34h]
	int v19;    // [esp-8h] [ebp-34h]
	int v20;    // [esp+10h] [ebp-1Ch]
	int v21;    // [esp+14h] [ebp-18h]
	int v22;    // [esp+18h] [ebp-14h]
	int v23;    // [esp+1Ch] [ebp-10h]
	int2 v24;   // [esp+24h] [ebp-8h]
	int v25;    // [esp+30h] [ebp+4h]

	v1 = a1[4] - *a1;
	v2 = a1[5] - a1[1];
	dword_5d4594_3798836 = 0;
	dword_5d4594_3798840 = 0;
	sub_481410();
	memset(getMemAt(0x85B3FC, 228), 0, 0x2C0u);
	memset(getMemAt(0x5D4594, 2523980), 0, 0x100u);
	v25 = (v1 - 11) / 46;
	if (v25 < 0) {
		v25 = 0;
	}
	v20 = dword_5d4594_3798812 + v25 - 1;
	if (v20 >= 128) {
		v20 = 127;
		v25 = 127 - dword_5d4594_3798812;
	}
	result = (v2 - 11) / 46 - 1;
	if (result < 0) {
		result = 0;
	}
	v4 = dword_5d4594_3798816 + result;
	if (*(int*)&dword_5d4594_3798816 + result >= 128) {
		v4 = 127;
		result = 127 - dword_5d4594_3798816;
	}
	v5 = v25;
	dword_5d4594_3798824 = 46 * result - 11;
	v6 = 46 * result - 57;
	dword_5d4594_3798828 = v25;
	dword_5d4594_3798820 = 46 * v25 - 11;
	dword_5d4594_3798832 = result;
	if (result < v4) {
		v21 = 44 * result;
		v23 = v4 - result;
		v7 = v20;
		do {
			v8 = 46 * v25 - 57;
			v6 += 46;
			v9 = v5;
			v22 = v5;
			if (v5 < v7) {
				do {
					HIWORD(v10) = HIWORD(ptr_5D4594_2650668); // TODO: why it's doing it?
					v8 += 46;
					v11 = ptr_5D4594_2650668[v9];
					v12 = *(uint8_t*)(v11 + v21);
					v13 = v21 + v11;
					if (v12) {
						if (v12 & 2) {
							LOWORD(v10) = *(uint16_t*)(v13 + 24);
							v14 = *(unsigned short*)(v13 + 24);
							v18 =
								*(uint32_t*)(*getMemU32Ptr(0x85B3FC, 32516 + 60 * v14) +
											 4 * (*(uint32_t*)(v13 + 28) + *getMemU16Ptr(0x85B3FC, 32530 + 60 * v14)));
							v24.field_0 = v8;
							v24.field_4 = v6 + 23;
							func_587000_154940(&v24, v18, v10);
							*getMemU32Ptr(0x85B3FC, 228 + 4 * v14) = 1;
							if (*(uint32_t*)(v13 + 40)) {
								nox_xxx_tileCallDrawEdges_481BF0((int)&v24, *(uint32_t*)(v13 + 40));
							}
						}
						if (*(uint8_t*)v13 & 1) {
							LOWORD(v10) = *(uint16_t*)(v13 + 4);
							v15 = *(unsigned short*)(v13 + 4);
							v19 = *(uint32_t*)(*getMemU32Ptr(0x85B3FC, 32516 + 60 * v15) +
											   4 * (*(uint32_t*)(v13 + 8) + *getMemU16Ptr(0x85B3FC, 32530 + 60 * v15)));
							v24.field_0 = v8 + 23;
							v24.field_4 = v6;
							func_587000_154940(&v24, v19, v10);
							*getMemU32Ptr(0x85B3FC, 228 + 4 * v15) = 1;
							v16 = *(uint32_t*)(v13 + 20);
							if (v16) {
								nox_xxx_tileCallDrawEdges_481BF0((int)&v24, v16);
							}
						}
					}
					v7 = v20;
					v9 = ++v22;
				} while (v22 < v20);
				v5 = v25;
			}
			result = v23 - 1;
			v17 = v23 == 1;
			v21 += 44;
			--v23;
		} while (!v17);
	}
	return result;
}
// 4828A6: variable 'v10' is possibly undefined

//----- (00482910) --------------------------------------------------------
char sub_482910(int a1, int a2) {
	int v2;      // edx
	int v3;      // edi
	int v4;      // edi
	int v5;      // edi
	int v6;      // edi
	int v7;      // edi
	int v8;      // edi
	int v9;      // edi
	int v10;     // edi
	int v11;     // edi
	int v12;     // edi
	int v13;     // edi
	int v14;     // edi
	int v15;     // edi
	int v16;     // edi
	int v17;     // edi
	int v18;     // edi
	int v19;     // edi
	int v20;     // edi
	int v21;     // edi
	int v22;     // edi
	int v23;     // edi
	int v24;     // edi
	int v25;     // edi
	int v26;     // edi
	int v27;     // edi
	int v28;     // edi
	int v29;     // edi
	int v30;     // edi
	int v31;     // edi
	int v32;     // edi
	int v33;     // edi
	int v34;     // edi
	int v35;     // edi
	int v36;     // edi
	int v37;     // edi
	int v38;     // edi
	int v39;     // edi
	int v40;     // edi
	int v41;     // edi
	int v42;     // edi
	int v43;     // edi
	int v44;     // edi
	int v45;     // edi
	int v46;     // edi
	char result; // al

	v2 = dword_5d4594_3798804;
	*(uint8_t*)(a2 + 23) = *(uint8_t*)a1;
	v3 = v2 + a2;
	*(uint16_t*)(v3 + 22) = *(uint16_t*)(a1 + 1);
	*(uint8_t*)(v3 + 24) = *(uint8_t*)(a1 + 3);
	v4 = v2 + v2 + a2;
	*(uint8_t*)(v4 + 21) = *(uint8_t*)(a1 + 4);
	*(uint16_t*)(v4 + 22) = *(uint16_t*)(a1 + 5);
	*(uint16_t*)(v4 + 24) = *(uint16_t*)(a1 + 7);
	v5 = v2 + v4;
	*(uint32_t*)(v5 + 20) = *(uint32_t*)(a1 + 9);
	*(uint16_t*)(v5 + 24) = *(uint16_t*)(a1 + 13);
	*(uint8_t*)(v5 + 26) = *(uint8_t*)(a1 + 15);
	v6 = v2 + v5;
	*(uint8_t*)(v6 + 19) = *(uint8_t*)(a1 + 16);
	*(uint32_t*)(v6 + 20) = *(uint32_t*)(a1 + 17);
	*(uint32_t*)(v6 + 24) = *(uint32_t*)(a1 + 21);
	v7 = v2 + v6;
	*(uint16_t*)(v7 + 18) = *(uint16_t*)(a1 + 25);
	*(uint32_t*)(v7 + 20) = *(uint32_t*)(a1 + 27);
	*(uint32_t*)(v7 + 24) = *(uint32_t*)(a1 + 31);
	*(uint8_t*)(v7 + 28) = *(uint8_t*)(a1 + 35);
	v8 = v2 + v7;
	*(uint8_t*)(v8 + 17) = *(uint8_t*)(a1 + 36);
	*(uint16_t*)(v8 + 18) = *(uint16_t*)(a1 + 37);
	*(uint32_t*)(v8 + 20) = *(uint32_t*)(a1 + 39);
	*(uint32_t*)(v8 + 24) = *(uint32_t*)(a1 + 43);
	*(uint16_t*)(v8 + 28) = *(uint16_t*)(a1 + 47);
	v9 = v2 + v8;
	*(uint32_t*)(v9 + 16) = *(uint32_t*)(a1 + 49);
	*(uint32_t*)(v9 + 20) = *(uint32_t*)(a1 + 53);
	*(uint32_t*)(v9 + 24) = *(uint32_t*)(a1 + 57);
	*(uint16_t*)(v9 + 28) = *(uint16_t*)(a1 + 61);
	*(uint8_t*)(v9 + 30) = *(uint8_t*)(a1 + 63);
	v10 = v2 + v9;
	*(uint8_t*)(v10 + 15) = *(uint8_t*)(a1 + 64);
	*(uint32_t*)(v10 + 16) = *(uint32_t*)(a1 + 65);
	*(uint32_t*)(v10 + 20) = *(uint32_t*)(a1 + 69);
	*(uint32_t*)(v10 + 24) = *(uint32_t*)(a1 + 73);
	*(uint32_t*)(v10 + 28) = *(uint32_t*)(a1 + 77);
	v11 = v2 + v10;
	*(uint16_t*)(v11 + 14) = *(uint16_t*)(a1 + 81);
	*(uint32_t*)(v11 + 16) = *(uint32_t*)(a1 + 83);
	*(uint32_t*)(v11 + 20) = *(uint32_t*)(a1 + 87);
	*(uint32_t*)(v11 + 24) = *(uint32_t*)(a1 + 91);
	*(uint32_t*)(v11 + 28) = *(uint32_t*)(a1 + 95);
	*(uint8_t*)(v11 + 32) = *(uint8_t*)(a1 + 99);
	v12 = v2 + v11;
	*(uint8_t*)(v12 + 13) = *(uint8_t*)(a1 + 100);
	*(uint16_t*)(v12 + 14) = *(uint16_t*)(a1 + 101);
	*(uint32_t*)(v12 + 16) = *(uint32_t*)(a1 + 103);
	*(uint32_t*)(v12 + 20) = *(uint32_t*)(a1 + 107);
	*(uint32_t*)(v12 + 24) = *(uint32_t*)(a1 + 111);
	*(uint32_t*)(v12 + 28) = *(uint32_t*)(a1 + 115);
	*(uint16_t*)(v12 + 32) = *(uint16_t*)(a1 + 119);
	v13 = v2 + v12;
	*(uint32_t*)(v13 + 12) = *(uint32_t*)(a1 + 121);
	*(uint32_t*)(v13 + 16) = *(uint32_t*)(a1 + 125);
	*(uint32_t*)(v13 + 20) = *(uint32_t*)(a1 + 129);
	*(uint32_t*)(v13 + 24) = *(uint32_t*)(a1 + 133);
	*(uint32_t*)(v13 + 28) = *(uint32_t*)(a1 + 137);
	*(uint16_t*)(v13 + 32) = *(uint16_t*)(a1 + 141);
	*(uint8_t*)(v13 + 34) = *(uint8_t*)(a1 + 143);
	v14 = v2 + v13;
	*(uint8_t*)(v14 + 11) = *(uint8_t*)(a1 + 144);
	*(uint32_t*)(v14 + 12) = *(uint32_t*)(a1 + 145);
	*(uint32_t*)(v14 + 16) = *(uint32_t*)(a1 + 149);
	*(uint32_t*)(v14 + 20) = *(uint32_t*)(a1 + 153);
	*(uint32_t*)(v14 + 24) = *(uint32_t*)(a1 + 157);
	*(uint32_t*)(v14 + 28) = *(uint32_t*)(a1 + 161);
	*(uint32_t*)(v14 + 32) = *(uint32_t*)(a1 + 165);
	v15 = v2 + v14;
	*(uint16_t*)(v15 + 10) = *(uint16_t*)(a1 + 169);
	*(uint32_t*)(v15 + 12) = *(uint32_t*)(a1 + 171);
	*(uint32_t*)(v15 + 16) = *(uint32_t*)(a1 + 175);
	*(uint32_t*)(v15 + 20) = *(uint32_t*)(a1 + 179);
	*(uint32_t*)(v15 + 24) = *(uint32_t*)(a1 + 183);
	*(uint32_t*)(v15 + 28) = *(uint32_t*)(a1 + 187);
	*(uint32_t*)(v15 + 32) = *(uint32_t*)(a1 + 191);
	*(uint8_t*)(v15 + 36) = *(uint8_t*)(a1 + 195);
	v16 = v2 + v15;
	*(uint8_t*)(v16 + 9) = *(uint8_t*)(a1 + 196);
	*(uint16_t*)(v16 + 10) = *(uint16_t*)(a1 + 197);
	*(uint32_t*)(v16 + 12) = *(uint32_t*)(a1 + 199);
	*(uint32_t*)(v16 + 16) = *(uint32_t*)(a1 + 203);
	*(uint32_t*)(v16 + 20) = *(uint32_t*)(a1 + 207);
	*(uint32_t*)(v16 + 24) = *(uint32_t*)(a1 + 211);
	*(uint32_t*)(v16 + 28) = *(uint32_t*)(a1 + 215);
	*(uint32_t*)(v16 + 32) = *(uint32_t*)(a1 + 219);
	*(uint16_t*)(v16 + 36) = *(uint16_t*)(a1 + 223);
	v17 = v2 + v16;
	*(uint32_t*)(v17 + 8) = *(uint32_t*)(a1 + 225);
	*(uint32_t*)(v17 + 12) = *(uint32_t*)(a1 + 229);
	*(uint32_t*)(v17 + 16) = *(uint32_t*)(a1 + 233);
	*(uint32_t*)(v17 + 20) = *(uint32_t*)(a1 + 237);
	*(uint32_t*)(v17 + 24) = *(uint32_t*)(a1 + 241);
	*(uint32_t*)(v17 + 28) = *(uint32_t*)(a1 + 245);
	*(uint32_t*)(v17 + 32) = *(uint32_t*)(a1 + 249);
	*(uint16_t*)(v17 + 36) = *(uint16_t*)(a1 + 253);
	*(uint8_t*)(v17 + 38) = *(uint8_t*)(a1 + 255);
	v18 = v2 + v17;
	*(uint8_t*)(v18 + 7) = *(uint8_t*)(a1 + 256);
	*(uint32_t*)(v18 + 8) = *(uint32_t*)(a1 + 257);
	*(uint32_t*)(v18 + 12) = *(uint32_t*)(a1 + 261);
	*(uint32_t*)(v18 + 16) = *(uint32_t*)(a1 + 265);
	*(uint32_t*)(v18 + 20) = *(uint32_t*)(a1 + 269);
	*(uint32_t*)(v18 + 24) = *(uint32_t*)(a1 + 273);
	*(uint32_t*)(v18 + 28) = *(uint32_t*)(a1 + 277);
	*(uint32_t*)(v18 + 32) = *(uint32_t*)(a1 + 281);
	*(uint32_t*)(v18 + 36) = *(uint32_t*)(a1 + 285);
	v19 = v2 + v18;
	*(uint16_t*)(v19 + 6) = *(uint16_t*)(a1 + 289);
	*(uint32_t*)(v19 + 8) = *(uint32_t*)(a1 + 291);
	*(uint32_t*)(v19 + 12) = *(uint32_t*)(a1 + 295);
	*(uint32_t*)(v19 + 16) = *(uint32_t*)(a1 + 299);
	*(uint32_t*)(v19 + 20) = *(uint32_t*)(a1 + 303);
	*(uint32_t*)(v19 + 24) = *(uint32_t*)(a1 + 307);
	*(uint32_t*)(v19 + 28) = *(uint32_t*)(a1 + 311);
	*(uint32_t*)(v19 + 32) = *(uint32_t*)(a1 + 315);
	*(uint32_t*)(v19 + 36) = *(uint32_t*)(a1 + 319);
	*(uint8_t*)(v19 + 40) = *(uint8_t*)(a1 + 323);
	v20 = v2 + v19;
	*(uint8_t*)(v20 + 5) = *(uint8_t*)(a1 + 324);
	*(uint16_t*)(v20 + 6) = *(uint16_t*)(a1 + 325);
	*(uint32_t*)(v20 + 8) = *(uint32_t*)(a1 + 327);
	*(uint32_t*)(v20 + 12) = *(uint32_t*)(a1 + 331);
	*(uint32_t*)(v20 + 16) = *(uint32_t*)(a1 + 335);
	*(uint32_t*)(v20 + 20) = *(uint32_t*)(a1 + 339);
	*(uint32_t*)(v20 + 24) = *(uint32_t*)(a1 + 343);
	*(uint32_t*)(v20 + 28) = *(uint32_t*)(a1 + 347);
	*(uint32_t*)(v20 + 32) = *(uint32_t*)(a1 + 351);
	*(uint32_t*)(v20 + 36) = *(uint32_t*)(a1 + 355);
	*(uint16_t*)(v20 + 40) = *(uint16_t*)(a1 + 359);
	v21 = v2 + v20;
	*(uint32_t*)(v21 + 4) = *(uint32_t*)(a1 + 361);
	*(uint32_t*)(v21 + 8) = *(uint32_t*)(a1 + 365);
	*(uint32_t*)(v21 + 12) = *(uint32_t*)(a1 + 369);
	*(uint32_t*)(v21 + 16) = *(uint32_t*)(a1 + 373);
	*(uint32_t*)(v21 + 20) = *(uint32_t*)(a1 + 377);
	*(uint32_t*)(v21 + 24) = *(uint32_t*)(a1 + 381);
	*(uint32_t*)(v21 + 28) = *(uint32_t*)(a1 + 385);
	*(uint32_t*)(v21 + 32) = *(uint32_t*)(a1 + 389);
	*(uint32_t*)(v21 + 36) = *(uint32_t*)(a1 + 393);
	*(uint16_t*)(v21 + 40) = *(uint16_t*)(a1 + 397);
	*(uint8_t*)(v21 + 42) = *(uint8_t*)(a1 + 399);
	v22 = v2 + v21;
	*(uint8_t*)(v22 + 3) = *(uint8_t*)(a1 + 400);
	*(uint32_t*)(v22 + 4) = *(uint32_t*)(a1 + 401);
	*(uint32_t*)(v22 + 8) = *(uint32_t*)(a1 + 405);
	*(uint32_t*)(v22 + 12) = *(uint32_t*)(a1 + 409);
	*(uint32_t*)(v22 + 16) = *(uint32_t*)(a1 + 413);
	*(uint32_t*)(v22 + 20) = *(uint32_t*)(a1 + 417);
	*(uint32_t*)(v22 + 24) = *(uint32_t*)(a1 + 421);
	*(uint32_t*)(v22 + 28) = *(uint32_t*)(a1 + 425);
	*(uint32_t*)(v22 + 32) = *(uint32_t*)(a1 + 429);
	*(uint32_t*)(v22 + 36) = *(uint32_t*)(a1 + 433);
	*(uint32_t*)(v22 + 40) = *(uint32_t*)(a1 + 437);
	v23 = v2 + v22;
	*(uint16_t*)(v23 + 2) = *(uint16_t*)(a1 + 441);
	*(uint32_t*)(v23 + 4) = *(uint32_t*)(a1 + 443);
	*(uint32_t*)(v23 + 8) = *(uint32_t*)(a1 + 447);
	*(uint32_t*)(v23 + 12) = *(uint32_t*)(a1 + 451);
	*(uint32_t*)(v23 + 16) = *(uint32_t*)(a1 + 455);
	*(uint32_t*)(v23 + 20) = *(uint32_t*)(a1 + 459);
	*(uint32_t*)(v23 + 24) = *(uint32_t*)(a1 + 463);
	*(uint32_t*)(v23 + 28) = *(uint32_t*)(a1 + 467);
	*(uint32_t*)(v23 + 32) = *(uint32_t*)(a1 + 471);
	*(uint32_t*)(v23 + 36) = *(uint32_t*)(a1 + 475);
	*(uint32_t*)(v23 + 40) = *(uint32_t*)(a1 + 479);
	*(uint8_t*)(v23 + 44) = *(uint8_t*)(a1 + 483);
	v24 = v2 + v23;
	*(uint8_t*)(v24 + 1) = *(uint8_t*)(a1 + 484);
	*(uint16_t*)(v24 + 2) = *(uint16_t*)(a1 + 485);
	*(uint32_t*)(v24 + 4) = *(uint32_t*)(a1 + 487);
	*(uint32_t*)(v24 + 8) = *(uint32_t*)(a1 + 491);
	*(uint32_t*)(v24 + 12) = *(uint32_t*)(a1 + 495);
	*(uint32_t*)(v24 + 16) = *(uint32_t*)(a1 + 499);
	*(uint32_t*)(v24 + 20) = *(uint32_t*)(a1 + 503);
	*(uint32_t*)(v24 + 24) = *(uint32_t*)(a1 + 507);
	*(uint32_t*)(v24 + 28) = *(uint32_t*)(a1 + 511);
	*(uint32_t*)(v24 + 32) = *(uint32_t*)(a1 + 515);
	*(uint32_t*)(v24 + 36) = *(uint32_t*)(a1 + 519);
	*(uint32_t*)(v24 + 40) = *(uint32_t*)(a1 + 523);
	*(uint16_t*)(v24 + 44) = *(uint16_t*)(a1 + 527);
	v25 = v2 + v24;
	*(uint8_t*)(v25 + 1) = *(uint8_t*)(a1 + 529);
	*(uint16_t*)(v25 + 2) = *(uint16_t*)(a1 + 530);
	*(uint32_t*)(v25 + 4) = *(uint32_t*)(a1 + 532);
	*(uint32_t*)(v25 + 8) = *(uint32_t*)(a1 + 536);
	*(uint32_t*)(v25 + 12) = *(uint32_t*)(a1 + 540);
	*(uint32_t*)(v25 + 16) = *(uint32_t*)(a1 + 544);
	*(uint32_t*)(v25 + 20) = *(uint32_t*)(a1 + 548);
	*(uint32_t*)(v25 + 24) = *(uint32_t*)(a1 + 552);
	*(uint32_t*)(v25 + 28) = *(uint32_t*)(a1 + 556);
	*(uint32_t*)(v25 + 32) = *(uint32_t*)(a1 + 560);
	*(uint32_t*)(v25 + 36) = *(uint32_t*)(a1 + 564);
	*(uint32_t*)(v25 + 40) = *(uint32_t*)(a1 + 568);
	*(uint16_t*)(v25 + 44) = *(uint16_t*)(a1 + 572);
	v26 = v2 + v25;
	*(uint16_t*)(v26 + 2) = *(uint16_t*)(a1 + 574);
	*(uint32_t*)(v26 + 4) = *(uint32_t*)(a1 + 576);
	*(uint32_t*)(v26 + 8) = *(uint32_t*)(a1 + 580);
	*(uint32_t*)(v26 + 12) = *(uint32_t*)(a1 + 584);
	*(uint32_t*)(v26 + 16) = *(uint32_t*)(a1 + 588);
	*(uint32_t*)(v26 + 20) = *(uint32_t*)(a1 + 592);
	*(uint32_t*)(v26 + 24) = *(uint32_t*)(a1 + 596);
	*(uint32_t*)(v26 + 28) = *(uint32_t*)(a1 + 600);
	*(uint32_t*)(v26 + 32) = *(uint32_t*)(a1 + 604);
	*(uint32_t*)(v26 + 36) = *(uint32_t*)(a1 + 608);
	*(uint32_t*)(v26 + 40) = *(uint32_t*)(a1 + 612);
	*(uint8_t*)(v26 + 44) = *(uint8_t*)(a1 + 616);
	v27 = v2 + v26;
	*(uint8_t*)(v27 + 3) = *(uint8_t*)(a1 + 617);
	*(uint32_t*)(v27 + 4) = *(uint32_t*)(a1 + 618);
	*(uint32_t*)(v27 + 8) = *(uint32_t*)(a1 + 622);
	*(uint32_t*)(v27 + 12) = *(uint32_t*)(a1 + 626);
	*(uint32_t*)(v27 + 16) = *(uint32_t*)(a1 + 630);
	*(uint32_t*)(v27 + 20) = *(uint32_t*)(a1 + 634);
	*(uint32_t*)(v27 + 24) = *(uint32_t*)(a1 + 638);
	*(uint32_t*)(v27 + 28) = *(uint32_t*)(a1 + 642);
	*(uint32_t*)(v27 + 32) = *(uint32_t*)(a1 + 646);
	*(uint32_t*)(v27 + 36) = *(uint32_t*)(a1 + 650);
	*(uint32_t*)(v27 + 40) = *(uint32_t*)(a1 + 654);
	v28 = v2 + v27;
	*(uint32_t*)(v28 + 4) = *(uint32_t*)(a1 + 658);
	*(uint32_t*)(v28 + 8) = *(uint32_t*)(a1 + 662);
	*(uint32_t*)(v28 + 12) = *(uint32_t*)(a1 + 666);
	*(uint32_t*)(v28 + 16) = *(uint32_t*)(a1 + 670);
	*(uint32_t*)(v28 + 20) = *(uint32_t*)(a1 + 674);
	*(uint32_t*)(v28 + 24) = *(uint32_t*)(a1 + 678);
	*(uint32_t*)(v28 + 28) = *(uint32_t*)(a1 + 682);
	*(uint32_t*)(v28 + 32) = *(uint32_t*)(a1 + 686);
	*(uint32_t*)(v28 + 36) = *(uint32_t*)(a1 + 690);
	*(uint16_t*)(v28 + 40) = *(uint16_t*)(a1 + 694);
	*(uint8_t*)(v28 + 42) = *(uint8_t*)(a1 + 696);
	v29 = v2 + v28;
	*(uint8_t*)(v29 + 5) = *(uint8_t*)(a1 + 697);
	*(uint16_t*)(v29 + 6) = *(uint16_t*)(a1 + 698);
	*(uint32_t*)(v29 + 8) = *(uint32_t*)(a1 + 700);
	*(uint32_t*)(v29 + 12) = *(uint32_t*)(a1 + 704);
	*(uint32_t*)(v29 + 16) = *(uint32_t*)(a1 + 708);
	*(uint32_t*)(v29 + 20) = *(uint32_t*)(a1 + 712);
	*(uint32_t*)(v29 + 24) = *(uint32_t*)(a1 + 716);
	*(uint32_t*)(v29 + 28) = *(uint32_t*)(a1 + 720);
	*(uint32_t*)(v29 + 32) = *(uint32_t*)(a1 + 724);
	*(uint32_t*)(v29 + 36) = *(uint32_t*)(a1 + 728);
	*(uint16_t*)(v29 + 40) = *(uint16_t*)(a1 + 732);
	v30 = v2 + v29;
	*(uint16_t*)(v30 + 6) = *(uint16_t*)(a1 + 734);
	*(uint32_t*)(v30 + 8) = *(uint32_t*)(a1 + 736);
	*(uint32_t*)(v30 + 12) = *(uint32_t*)(a1 + 740);
	*(uint32_t*)(v30 + 16) = *(uint32_t*)(a1 + 744);
	*(uint32_t*)(v30 + 20) = *(uint32_t*)(a1 + 748);
	*(uint32_t*)(v30 + 24) = *(uint32_t*)(a1 + 752);
	*(uint32_t*)(v30 + 28) = *(uint32_t*)(a1 + 756);
	*(uint32_t*)(v30 + 32) = *(uint32_t*)(a1 + 760);
	*(uint32_t*)(v30 + 36) = *(uint32_t*)(a1 + 764);
	*(uint8_t*)(v30 + 40) = *(uint8_t*)(a1 + 768);
	v31 = v2 + v30;
	*(uint8_t*)(v31 + 7) = *(uint8_t*)(a1 + 769);
	*(uint32_t*)(v31 + 8) = *(uint32_t*)(a1 + 770);
	*(uint32_t*)(v31 + 12) = *(uint32_t*)(a1 + 774);
	*(uint32_t*)(v31 + 16) = *(uint32_t*)(a1 + 778);
	*(uint32_t*)(v31 + 20) = *(uint32_t*)(a1 + 782);
	*(uint32_t*)(v31 + 24) = *(uint32_t*)(a1 + 786);
	*(uint32_t*)(v31 + 28) = *(uint32_t*)(a1 + 790);
	*(uint32_t*)(v31 + 32) = *(uint32_t*)(a1 + 794);
	*(uint32_t*)(v31 + 36) = *(uint32_t*)(a1 + 798);
	v32 = v2 + v31;
	*(uint32_t*)(v32 + 8) = *(uint32_t*)(a1 + 802);
	*(uint32_t*)(v32 + 12) = *(uint32_t*)(a1 + 806);
	*(uint32_t*)(v32 + 16) = *(uint32_t*)(a1 + 810);
	*(uint32_t*)(v32 + 20) = *(uint32_t*)(a1 + 814);
	*(uint32_t*)(v32 + 24) = *(uint32_t*)(a1 + 818);
	*(uint32_t*)(v32 + 28) = *(uint32_t*)(a1 + 822);
	*(uint32_t*)(v32 + 32) = *(uint32_t*)(a1 + 826);
	*(uint16_t*)(v32 + 36) = *(uint16_t*)(a1 + 830);
	*(uint8_t*)(v32 + 38) = *(uint8_t*)(a1 + 832);
	v33 = v2 + v32;
	*(uint8_t*)(v33 + 9) = *(uint8_t*)(a1 + 833);
	*(uint16_t*)(v33 + 10) = *(uint16_t*)(a1 + 834);
	*(uint32_t*)(v33 + 12) = *(uint32_t*)(a1 + 836);
	*(uint32_t*)(v33 + 16) = *(uint32_t*)(a1 + 840);
	*(uint32_t*)(v33 + 20) = *(uint32_t*)(a1 + 844);
	*(uint32_t*)(v33 + 24) = *(uint32_t*)(a1 + 848);
	*(uint32_t*)(v33 + 28) = *(uint32_t*)(a1 + 852);
	*(uint32_t*)(v33 + 32) = *(uint32_t*)(a1 + 856);
	*(uint16_t*)(v33 + 36) = *(uint16_t*)(a1 + 860);
	v34 = v2 + v33;
	*(uint16_t*)(v34 + 10) = *(uint16_t*)(a1 + 862);
	*(uint32_t*)(v34 + 12) = *(uint32_t*)(a1 + 864);
	*(uint32_t*)(v34 + 16) = *(uint32_t*)(a1 + 868);
	*(uint32_t*)(v34 + 20) = *(uint32_t*)(a1 + 872);
	*(uint32_t*)(v34 + 24) = *(uint32_t*)(a1 + 876);
	*(uint32_t*)(v34 + 28) = *(uint32_t*)(a1 + 880);
	*(uint32_t*)(v34 + 32) = *(uint32_t*)(a1 + 884);
	*(uint8_t*)(v34 + 36) = *(uint8_t*)(a1 + 888);
	v35 = v2 + v34;
	*(uint8_t*)(v35 + 11) = *(uint8_t*)(a1 + 889);
	*(uint32_t*)(v35 + 12) = *(uint32_t*)(a1 + 890);
	*(uint32_t*)(v35 + 16) = *(uint32_t*)(a1 + 894);
	*(uint32_t*)(v35 + 20) = *(uint32_t*)(a1 + 898);
	*(uint32_t*)(v35 + 24) = *(uint32_t*)(a1 + 902);
	*(uint32_t*)(v35 + 28) = *(uint32_t*)(a1 + 906);
	*(uint32_t*)(v35 + 32) = *(uint32_t*)(a1 + 910);
	v36 = v2 + v35;
	*(uint32_t*)(v36 + 12) = *(uint32_t*)(a1 + 914);
	*(uint32_t*)(v36 + 16) = *(uint32_t*)(a1 + 918);
	*(uint32_t*)(v36 + 20) = *(uint32_t*)(a1 + 922);
	*(uint32_t*)(v36 + 24) = *(uint32_t*)(a1 + 926);
	*(uint32_t*)(v36 + 28) = *(uint32_t*)(a1 + 930);
	*(uint16_t*)(v36 + 32) = *(uint16_t*)(a1 + 934);
	*(uint8_t*)(v36 + 34) = *(uint8_t*)(a1 + 936);
	v37 = v2 + v36;
	*(uint8_t*)(v37 + 13) = *(uint8_t*)(a1 + 937);
	*(uint16_t*)(v37 + 14) = *(uint16_t*)(a1 + 938);
	*(uint32_t*)(v37 + 16) = *(uint32_t*)(a1 + 940);
	*(uint32_t*)(v37 + 20) = *(uint32_t*)(a1 + 944);
	*(uint32_t*)(v37 + 24) = *(uint32_t*)(a1 + 948);
	*(uint32_t*)(v37 + 28) = *(uint32_t*)(a1 + 952);
	*(uint16_t*)(v37 + 32) = *(uint16_t*)(a1 + 956);
	v38 = v2 + v37;
	*(uint16_t*)(v38 + 14) = *(uint16_t*)(a1 + 958);
	*(uint32_t*)(v38 + 16) = *(uint32_t*)(a1 + 960);
	*(uint32_t*)(v38 + 20) = *(uint32_t*)(a1 + 964);
	*(uint32_t*)(v38 + 24) = *(uint32_t*)(a1 + 968);
	*(uint32_t*)(v38 + 28) = *(uint32_t*)(a1 + 972);
	*(uint8_t*)(v38 + 32) = *(uint8_t*)(a1 + 976);
	v39 = v2 + v38;
	*(uint8_t*)(v39 + 15) = *(uint8_t*)(a1 + 977);
	*(uint32_t*)(v39 + 16) = *(uint32_t*)(a1 + 978);
	*(uint32_t*)(v39 + 20) = *(uint32_t*)(a1 + 982);
	*(uint32_t*)(v39 + 24) = *(uint32_t*)(a1 + 986);
	*(uint32_t*)(v39 + 28) = *(uint32_t*)(a1 + 990);
	v40 = v2 + v39;
	*(uint32_t*)(v40 + 16) = *(uint32_t*)(a1 + 994);
	*(uint32_t*)(v40 + 20) = *(uint32_t*)(a1 + 998);
	*(uint32_t*)(v40 + 24) = *(uint32_t*)(a1 + 1002);
	*(uint16_t*)(v40 + 28) = *(uint16_t*)(a1 + 1006);
	*(uint8_t*)(v40 + 30) = *(uint8_t*)(a1 + 1008);
	v41 = v2 + v40;
	*(uint8_t*)(v41 + 17) = *(uint8_t*)(a1 + 1009);
	*(uint16_t*)(v41 + 18) = *(uint16_t*)(a1 + 1010);
	*(uint32_t*)(v41 + 20) = *(uint32_t*)(a1 + 1012);
	*(uint32_t*)(v41 + 24) = *(uint32_t*)(a1 + 1016);
	*(uint16_t*)(v41 + 28) = *(uint16_t*)(a1 + 1020);
	v42 = v2 + v41;
	*(uint16_t*)(v42 + 18) = *(uint16_t*)(a1 + 1022);
	*(uint32_t*)(v42 + 20) = *(uint32_t*)(a1 + 1024);
	*(uint32_t*)(v42 + 24) = *(uint32_t*)(a1 + 1028);
	*(uint8_t*)(v42 + 28) = *(uint8_t*)(a1 + 1032);
	v43 = v2 + v42;
	*(uint8_t*)(v43 + 19) = *(uint8_t*)(a1 + 1033);
	*(uint32_t*)(v43 + 20) = *(uint32_t*)(a1 + 1034);
	*(uint32_t*)(v43 + 24) = *(uint32_t*)(a1 + 1038);
	v44 = v2 + v43;
	*(uint32_t*)(v44 + 20) = *(uint32_t*)(a1 + 1042);
	*(uint16_t*)(v44 + 24) = *(uint16_t*)(a1 + 1046);
	*(uint8_t*)(v44 + 26) = *(uint8_t*)(a1 + 1048);
	v45 = v2 + v44;
	*(uint8_t*)(v45 + 21) = *(uint8_t*)(a1 + 1049);
	*(uint16_t*)(v45 + 22) = *(uint16_t*)(a1 + 1050);
	*(uint16_t*)(v45 + 24) = *(uint16_t*)(a1 + 1052);
	v46 = v2 + v45;
	*(uint16_t*)(v46 + 22) = *(uint16_t*)(a1 + 1054);
	result = *(uint8_t*)(a1 + 1056);
	*(uint8_t*)(v46 + 24) = result;
	*(uint8_t*)(v2 + v46 + 23) = *(uint8_t*)(a1 + 1057);
	return result;
}

//----- (004831C0) --------------------------------------------------------
short sub_4831C0(int a1, int a2) {
	int v2;       // edx
	int v3;       // edi
	int v4;       // edi
	int v5;       // edi
	int v6;       // edi
	int v7;       // edi
	int v8;       // edi
	int v9;       // edi
	int v10;      // edi
	int v11;      // edi
	int v12;      // edi
	int v13;      // edi
	int v14;      // edi
	int v15;      // edi
	int v16;      // edi
	int v17;      // edi
	int v18;      // edi
	int v19;      // edi
	int v20;      // edi
	int v21;      // edi
	int v22;      // edi
	int v23;      // edi
	int v24;      // edi
	int v25;      // edi
	int v26;      // edi
	int v27;      // edi
	int v28;      // edi
	int v29;      // edi
	int v30;      // edi
	int v31;      // edi
	int v32;      // edi
	int v33;      // edi
	int v34;      // edi
	int v35;      // edi
	int v36;      // edi
	int v37;      // edi
	int v38;      // edi
	int v39;      // edi
	int v40;      // edi
	int v41;      // edi
	int v42;      // edi
	int v43;      // edi
	int v44;      // edi
	int v45;      // edi
	int v46;      // edi
	short result; // ax

	v2 = dword_5d4594_3798804;
	*(uint16_t*)(a2 + 46) = *(uint16_t*)a1;
	v3 = v2 + a2;
	*(uint32_t*)(v3 + 44) = *(uint32_t*)(a1 + 2);
	*(uint16_t*)(v3 + 48) = *(uint16_t*)(a1 + 6);
	v4 = v2 + v2 + a2;
	*(uint16_t*)(v4 + 42) = *(uint16_t*)(a1 + 8);
	*(uint32_t*)(v4 + 44) = *(uint32_t*)(a1 + 10);
	*(uint32_t*)(v4 + 48) = *(uint32_t*)(a1 + 14);
	v5 = v2 + v4;
	*(uint32_t*)(v5 + 40) = *(uint32_t*)(a1 + 18);
	*(uint32_t*)(v5 + 44) = *(uint32_t*)(a1 + 22);
	*(uint32_t*)(v5 + 48) = *(uint32_t*)(a1 + 26);
	*(uint16_t*)(v5 + 52) = *(uint16_t*)(a1 + 30);
	v6 = v2 + v5;
	*(uint16_t*)(v6 + 38) = *(uint16_t*)(a1 + 32);
	*(uint32_t*)(v6 + 40) = *(uint32_t*)(a1 + 34);
	*(uint32_t*)(v6 + 44) = *(uint32_t*)(a1 + 38);
	*(uint32_t*)(v6 + 48) = *(uint32_t*)(a1 + 42);
	*(uint32_t*)(v6 + 52) = *(uint32_t*)(a1 + 46);
	v7 = v2 + v6;
	*(uint32_t*)(v7 + 36) = *(uint32_t*)(a1 + 50);
	*(uint32_t*)(v7 + 40) = *(uint32_t*)(a1 + 54);
	*(uint32_t*)(v7 + 44) = *(uint32_t*)(a1 + 58);
	*(uint32_t*)(v7 + 48) = *(uint32_t*)(a1 + 62);
	*(uint32_t*)(v7 + 52) = *(uint32_t*)(a1 + 66);
	*(uint16_t*)(v7 + 56) = *(uint16_t*)(a1 + 70);
	v8 = v2 + v7;
	*(uint16_t*)(v8 + 34) = *(uint16_t*)(a1 + 72);
	*(uint32_t*)(v8 + 36) = *(uint32_t*)(a1 + 74);
	*(uint32_t*)(v8 + 40) = *(uint32_t*)(a1 + 78);
	*(uint32_t*)(v8 + 44) = *(uint32_t*)(a1 + 82);
	*(uint32_t*)(v8 + 48) = *(uint32_t*)(a1 + 86);
	*(uint32_t*)(v8 + 52) = *(uint32_t*)(a1 + 90);
	*(uint32_t*)(v8 + 56) = *(uint32_t*)(a1 + 94);
	v9 = v2 + v8;
	*(uint32_t*)(v9 + 32) = *(uint32_t*)(a1 + 98);
	*(uint32_t*)(v9 + 36) = *(uint32_t*)(a1 + 102);
	*(uint32_t*)(v9 + 40) = *(uint32_t*)(a1 + 106);
	*(uint32_t*)(v9 + 44) = *(uint32_t*)(a1 + 110);
	*(uint32_t*)(v9 + 48) = *(uint32_t*)(a1 + 114);
	*(uint32_t*)(v9 + 52) = *(uint32_t*)(a1 + 118);
	*(uint32_t*)(v9 + 56) = *(uint32_t*)(a1 + 122);
	*(uint16_t*)(v9 + 60) = *(uint16_t*)(a1 + 126);
	v10 = v2 + v9;
	*(uint16_t*)(v10 + 30) = *(uint16_t*)(a1 + 128);
	*(uint32_t*)(v10 + 32) = *(uint32_t*)(a1 + 130);
	*(uint32_t*)(v10 + 36) = *(uint32_t*)(a1 + 134);
	*(uint32_t*)(v10 + 40) = *(uint32_t*)(a1 + 138);
	*(uint32_t*)(v10 + 44) = *(uint32_t*)(a1 + 142);
	*(uint32_t*)(v10 + 48) = *(uint32_t*)(a1 + 146);
	*(uint32_t*)(v10 + 52) = *(uint32_t*)(a1 + 150);
	*(uint32_t*)(v10 + 56) = *(uint32_t*)(a1 + 154);
	*(uint32_t*)(v10 + 60) = *(uint32_t*)(a1 + 158);
	v11 = v2 + v10;
	*(uint32_t*)(v11 + 28) = *(uint32_t*)(a1 + 162);
	*(uint32_t*)(v11 + 32) = *(uint32_t*)(a1 + 166);
	*(uint32_t*)(v11 + 36) = *(uint32_t*)(a1 + 170);
	*(uint32_t*)(v11 + 40) = *(uint32_t*)(a1 + 174);
	*(uint32_t*)(v11 + 44) = *(uint32_t*)(a1 + 178);
	*(uint32_t*)(v11 + 48) = *(uint32_t*)(a1 + 182);
	*(uint32_t*)(v11 + 52) = *(uint32_t*)(a1 + 186);
	*(uint32_t*)(v11 + 56) = *(uint32_t*)(a1 + 190);
	*(uint32_t*)(v11 + 60) = *(uint32_t*)(a1 + 194);
	*(uint16_t*)(v11 + 64) = *(uint16_t*)(a1 + 198);
	v12 = v2 + v11;
	*(uint16_t*)(v12 + 26) = *(uint16_t*)(a1 + 200);
	*(uint32_t*)(v12 + 28) = *(uint32_t*)(a1 + 202);
	*(uint32_t*)(v12 + 32) = *(uint32_t*)(a1 + 206);
	*(uint32_t*)(v12 + 36) = *(uint32_t*)(a1 + 210);
	*(uint32_t*)(v12 + 40) = *(uint32_t*)(a1 + 214);
	*(uint32_t*)(v12 + 44) = *(uint32_t*)(a1 + 218);
	*(uint32_t*)(v12 + 48) = *(uint32_t*)(a1 + 222);
	*(uint32_t*)(v12 + 52) = *(uint32_t*)(a1 + 226);
	*(uint32_t*)(v12 + 56) = *(uint32_t*)(a1 + 230);
	*(uint32_t*)(v12 + 60) = *(uint32_t*)(a1 + 234);
	*(uint32_t*)(v12 + 64) = *(uint32_t*)(a1 + 238);
	v13 = v2 + v12;
	*(uint32_t*)(v13 + 24) = *(uint32_t*)(a1 + 242);
	*(uint32_t*)(v13 + 28) = *(uint32_t*)(a1 + 246);
	*(uint32_t*)(v13 + 32) = *(uint32_t*)(a1 + 250);
	*(uint32_t*)(v13 + 36) = *(uint32_t*)(a1 + 254);
	*(uint32_t*)(v13 + 40) = *(uint32_t*)(a1 + 258);
	*(uint32_t*)(v13 + 44) = *(uint32_t*)(a1 + 262);
	*(uint32_t*)(v13 + 48) = *(uint32_t*)(a1 + 266);
	*(uint32_t*)(v13 + 52) = *(uint32_t*)(a1 + 270);
	*(uint32_t*)(v13 + 56) = *(uint32_t*)(a1 + 274);
	*(uint32_t*)(v13 + 60) = *(uint32_t*)(a1 + 278);
	*(uint32_t*)(v13 + 64) = *(uint32_t*)(a1 + 282);
	*(uint16_t*)(v13 + 68) = *(uint16_t*)(a1 + 286);
	v14 = v2 + v13;
	*(uint16_t*)(v14 + 22) = *(uint16_t*)(a1 + 288);
	*(uint32_t*)(v14 + 24) = *(uint32_t*)(a1 + 290);
	*(uint32_t*)(v14 + 28) = *(uint32_t*)(a1 + 294);
	*(uint32_t*)(v14 + 32) = *(uint32_t*)(a1 + 298);
	*(uint32_t*)(v14 + 36) = *(uint32_t*)(a1 + 302);
	*(uint32_t*)(v14 + 40) = *(uint32_t*)(a1 + 306);
	*(uint32_t*)(v14 + 44) = *(uint32_t*)(a1 + 310);
	*(uint32_t*)(v14 + 48) = *(uint32_t*)(a1 + 314);
	*(uint32_t*)(v14 + 52) = *(uint32_t*)(a1 + 318);
	*(uint32_t*)(v14 + 56) = *(uint32_t*)(a1 + 322);
	*(uint32_t*)(v14 + 60) = *(uint32_t*)(a1 + 326);
	*(uint32_t*)(v14 + 64) = *(uint32_t*)(a1 + 330);
	*(uint32_t*)(v14 + 68) = *(uint32_t*)(a1 + 334);
	v15 = v2 + v14;
	*(uint32_t*)(v15 + 20) = *(uint32_t*)(a1 + 338);
	*(uint32_t*)(v15 + 24) = *(uint32_t*)(a1 + 342);
	*(uint32_t*)(v15 + 28) = *(uint32_t*)(a1 + 346);
	*(uint32_t*)(v15 + 32) = *(uint32_t*)(a1 + 350);
	*(uint32_t*)(v15 + 36) = *(uint32_t*)(a1 + 354);
	*(uint32_t*)(v15 + 40) = *(uint32_t*)(a1 + 358);
	*(uint32_t*)(v15 + 44) = *(uint32_t*)(a1 + 362);
	*(uint32_t*)(v15 + 48) = *(uint32_t*)(a1 + 366);
	*(uint32_t*)(v15 + 52) = *(uint32_t*)(a1 + 370);
	*(uint32_t*)(v15 + 56) = *(uint32_t*)(a1 + 374);
	*(uint32_t*)(v15 + 60) = *(uint32_t*)(a1 + 378);
	*(uint32_t*)(v15 + 64) = *(uint32_t*)(a1 + 382);
	*(uint32_t*)(v15 + 68) = *(uint32_t*)(a1 + 386);
	*(uint16_t*)(v15 + 72) = *(uint16_t*)(a1 + 390);
	v16 = v2 + v15;
	*(uint16_t*)(v16 + 18) = *(uint16_t*)(a1 + 392);
	*(uint32_t*)(v16 + 20) = *(uint32_t*)(a1 + 394);
	*(uint32_t*)(v16 + 24) = *(uint32_t*)(a1 + 398);
	*(uint32_t*)(v16 + 28) = *(uint32_t*)(a1 + 402);
	*(uint32_t*)(v16 + 32) = *(uint32_t*)(a1 + 406);
	*(uint32_t*)(v16 + 36) = *(uint32_t*)(a1 + 410);
	*(uint32_t*)(v16 + 40) = *(uint32_t*)(a1 + 414);
	*(uint32_t*)(v16 + 44) = *(uint32_t*)(a1 + 418);
	*(uint32_t*)(v16 + 48) = *(uint32_t*)(a1 + 422);
	*(uint32_t*)(v16 + 52) = *(uint32_t*)(a1 + 426);
	*(uint32_t*)(v16 + 56) = *(uint32_t*)(a1 + 430);
	*(uint32_t*)(v16 + 60) = *(uint32_t*)(a1 + 434);
	*(uint32_t*)(v16 + 64) = *(uint32_t*)(a1 + 438);
	*(uint32_t*)(v16 + 68) = *(uint32_t*)(a1 + 442);
	*(uint32_t*)(v16 + 72) = *(uint32_t*)(a1 + 446);
	v17 = v2 + v16;
	*(uint32_t*)(v17 + 16) = *(uint32_t*)(a1 + 450);
	*(uint32_t*)(v17 + 20) = *(uint32_t*)(a1 + 454);
	*(uint32_t*)(v17 + 24) = *(uint32_t*)(a1 + 458);
	*(uint32_t*)(v17 + 28) = *(uint32_t*)(a1 + 462);
	*(uint32_t*)(v17 + 32) = *(uint32_t*)(a1 + 466);
	*(uint32_t*)(v17 + 36) = *(uint32_t*)(a1 + 470);
	*(uint32_t*)(v17 + 40) = *(uint32_t*)(a1 + 474);
	*(uint32_t*)(v17 + 44) = *(uint32_t*)(a1 + 478);
	*(uint32_t*)(v17 + 48) = *(uint32_t*)(a1 + 482);
	*(uint32_t*)(v17 + 52) = *(uint32_t*)(a1 + 486);
	*(uint32_t*)(v17 + 56) = *(uint32_t*)(a1 + 490);
	*(uint32_t*)(v17 + 60) = *(uint32_t*)(a1 + 494);
	*(uint32_t*)(v17 + 64) = *(uint32_t*)(a1 + 498);
	*(uint32_t*)(v17 + 68) = *(uint32_t*)(a1 + 502);
	*(uint32_t*)(v17 + 72) = *(uint32_t*)(a1 + 506);
	*(uint16_t*)(v17 + 76) = *(uint16_t*)(a1 + 510);
	v18 = v2 + v17;
	*(uint16_t*)(v18 + 14) = *(uint16_t*)(a1 + 512);
	*(uint32_t*)(v18 + 16) = *(uint32_t*)(a1 + 514);
	*(uint32_t*)(v18 + 20) = *(uint32_t*)(a1 + 518);
	*(uint32_t*)(v18 + 24) = *(uint32_t*)(a1 + 522);
	*(uint32_t*)(v18 + 28) = *(uint32_t*)(a1 + 526);
	*(uint32_t*)(v18 + 32) = *(uint32_t*)(a1 + 530);
	*(uint32_t*)(v18 + 36) = *(uint32_t*)(a1 + 534);
	*(uint32_t*)(v18 + 40) = *(uint32_t*)(a1 + 538);
	*(uint32_t*)(v18 + 44) = *(uint32_t*)(a1 + 542);
	*(uint32_t*)(v18 + 48) = *(uint32_t*)(a1 + 546);
	*(uint32_t*)(v18 + 52) = *(uint32_t*)(a1 + 550);
	*(uint32_t*)(v18 + 56) = *(uint32_t*)(a1 + 554);
	*(uint32_t*)(v18 + 60) = *(uint32_t*)(a1 + 558);
	*(uint32_t*)(v18 + 64) = *(uint32_t*)(a1 + 562);
	*(uint32_t*)(v18 + 68) = *(uint32_t*)(a1 + 566);
	*(uint32_t*)(v18 + 72) = *(uint32_t*)(a1 + 570);
	*(uint32_t*)(v18 + 76) = *(uint32_t*)(a1 + 574);
	v19 = v2 + v18;
	*(uint32_t*)(v19 + 12) = *(uint32_t*)(a1 + 578);
	*(uint32_t*)(v19 + 16) = *(uint32_t*)(a1 + 582);
	*(uint32_t*)(v19 + 20) = *(uint32_t*)(a1 + 586);
	*(uint32_t*)(v19 + 24) = *(uint32_t*)(a1 + 590);
	*(uint32_t*)(v19 + 28) = *(uint32_t*)(a1 + 594);
	*(uint32_t*)(v19 + 32) = *(uint32_t*)(a1 + 598);
	*(uint32_t*)(v19 + 36) = *(uint32_t*)(a1 + 602);
	*(uint32_t*)(v19 + 40) = *(uint32_t*)(a1 + 606);
	*(uint32_t*)(v19 + 44) = *(uint32_t*)(a1 + 610);
	*(uint32_t*)(v19 + 48) = *(uint32_t*)(a1 + 614);
	*(uint32_t*)(v19 + 52) = *(uint32_t*)(a1 + 618);
	*(uint32_t*)(v19 + 56) = *(uint32_t*)(a1 + 622);
	*(uint32_t*)(v19 + 60) = *(uint32_t*)(a1 + 626);
	*(uint32_t*)(v19 + 64) = *(uint32_t*)(a1 + 630);
	*(uint32_t*)(v19 + 68) = *(uint32_t*)(a1 + 634);
	*(uint32_t*)(v19 + 72) = *(uint32_t*)(a1 + 638);
	*(uint32_t*)(v19 + 76) = *(uint32_t*)(a1 + 642);
	*(uint16_t*)(v19 + 80) = *(uint16_t*)(a1 + 646);
	v20 = v2 + v19;
	*(uint16_t*)(v20 + 10) = *(uint16_t*)(a1 + 648);
	*(uint32_t*)(v20 + 12) = *(uint32_t*)(a1 + 650);
	*(uint32_t*)(v20 + 16) = *(uint32_t*)(a1 + 654);
	*(uint32_t*)(v20 + 20) = *(uint32_t*)(a1 + 658);
	*(uint32_t*)(v20 + 24) = *(uint32_t*)(a1 + 662);
	*(uint32_t*)(v20 + 28) = *(uint32_t*)(a1 + 666);
	*(uint32_t*)(v20 + 32) = *(uint32_t*)(a1 + 670);
	*(uint32_t*)(v20 + 36) = *(uint32_t*)(a1 + 674);
	*(uint32_t*)(v20 + 40) = *(uint32_t*)(a1 + 678);
	*(uint32_t*)(v20 + 44) = *(uint32_t*)(a1 + 682);
	*(uint32_t*)(v20 + 48) = *(uint32_t*)(a1 + 686);
	*(uint32_t*)(v20 + 52) = *(uint32_t*)(a1 + 690);
	*(uint32_t*)(v20 + 56) = *(uint32_t*)(a1 + 694);
	*(uint32_t*)(v20 + 60) = *(uint32_t*)(a1 + 698);
	*(uint32_t*)(v20 + 64) = *(uint32_t*)(a1 + 702);
	*(uint32_t*)(v20 + 68) = *(uint32_t*)(a1 + 706);
	*(uint32_t*)(v20 + 72) = *(uint32_t*)(a1 + 710);
	*(uint32_t*)(v20 + 76) = *(uint32_t*)(a1 + 714);
	*(uint32_t*)(v20 + 80) = *(uint32_t*)(a1 + 718);
	v21 = v2 + v20;
	*(uint32_t*)(v21 + 8) = *(uint32_t*)(a1 + 722);
	*(uint32_t*)(v21 + 12) = *(uint32_t*)(a1 + 726);
	*(uint32_t*)(v21 + 16) = *(uint32_t*)(a1 + 730);
	*(uint32_t*)(v21 + 20) = *(uint32_t*)(a1 + 734);
	*(uint32_t*)(v21 + 24) = *(uint32_t*)(a1 + 738);
	*(uint32_t*)(v21 + 28) = *(uint32_t*)(a1 + 742);
	*(uint32_t*)(v21 + 32) = *(uint32_t*)(a1 + 746);
	*(uint32_t*)(v21 + 36) = *(uint32_t*)(a1 + 750);
	*(uint32_t*)(v21 + 40) = *(uint32_t*)(a1 + 754);
	*(uint32_t*)(v21 + 44) = *(uint32_t*)(a1 + 758);
	*(uint32_t*)(v21 + 48) = *(uint32_t*)(a1 + 762);
	*(uint32_t*)(v21 + 52) = *(uint32_t*)(a1 + 766);
	*(uint32_t*)(v21 + 56) = *(uint32_t*)(a1 + 770);
	*(uint32_t*)(v21 + 60) = *(uint32_t*)(a1 + 774);
	*(uint32_t*)(v21 + 64) = *(uint32_t*)(a1 + 778);
	*(uint32_t*)(v21 + 68) = *(uint32_t*)(a1 + 782);
	*(uint32_t*)(v21 + 72) = *(uint32_t*)(a1 + 786);
	*(uint32_t*)(v21 + 76) = *(uint32_t*)(a1 + 790);
	*(uint32_t*)(v21 + 80) = *(uint32_t*)(a1 + 794);
	*(uint16_t*)(v21 + 84) = *(uint16_t*)(a1 + 798);
	v22 = v2 + v21;
	*(uint16_t*)(v22 + 6) = *(uint16_t*)(a1 + 800);
	*(uint32_t*)(v22 + 8) = *(uint32_t*)(a1 + 802);
	*(uint32_t*)(v22 + 12) = *(uint32_t*)(a1 + 806);
	*(uint32_t*)(v22 + 16) = *(uint32_t*)(a1 + 810);
	*(uint32_t*)(v22 + 20) = *(uint32_t*)(a1 + 814);
	*(uint32_t*)(v22 + 24) = *(uint32_t*)(a1 + 818);
	*(uint32_t*)(v22 + 28) = *(uint32_t*)(a1 + 822);
	*(uint32_t*)(v22 + 32) = *(uint32_t*)(a1 + 826);
	*(uint32_t*)(v22 + 36) = *(uint32_t*)(a1 + 830);
	*(uint32_t*)(v22 + 40) = *(uint32_t*)(a1 + 834);
	*(uint32_t*)(v22 + 44) = *(uint32_t*)(a1 + 838);
	*(uint32_t*)(v22 + 48) = *(uint32_t*)(a1 + 842);
	*(uint32_t*)(v22 + 52) = *(uint32_t*)(a1 + 846);
	*(uint32_t*)(v22 + 56) = *(uint32_t*)(a1 + 850);
	*(uint32_t*)(v22 + 60) = *(uint32_t*)(a1 + 854);
	*(uint32_t*)(v22 + 64) = *(uint32_t*)(a1 + 858);
	*(uint32_t*)(v22 + 68) = *(uint32_t*)(a1 + 862);
	*(uint32_t*)(v22 + 72) = *(uint32_t*)(a1 + 866);
	*(uint32_t*)(v22 + 76) = *(uint32_t*)(a1 + 870);
	*(uint32_t*)(v22 + 80) = *(uint32_t*)(a1 + 874);
	*(uint32_t*)(v22 + 84) = *(uint32_t*)(a1 + 878);
	v23 = v2 + v22;
	*(uint32_t*)(v23 + 4) = *(uint32_t*)(a1 + 882);
	*(uint32_t*)(v23 + 8) = *(uint32_t*)(a1 + 886);
	*(uint32_t*)(v23 + 12) = *(uint32_t*)(a1 + 890);
	*(uint32_t*)(v23 + 16) = *(uint32_t*)(a1 + 894);
	*(uint32_t*)(v23 + 20) = *(uint32_t*)(a1 + 898);
	*(uint32_t*)(v23 + 24) = *(uint32_t*)(a1 + 902);
	*(uint32_t*)(v23 + 28) = *(uint32_t*)(a1 + 906);
	*(uint32_t*)(v23 + 32) = *(uint32_t*)(a1 + 910);
	*(uint32_t*)(v23 + 36) = *(uint32_t*)(a1 + 914);
	*(uint32_t*)(v23 + 40) = *(uint32_t*)(a1 + 918);
	*(uint32_t*)(v23 + 44) = *(uint32_t*)(a1 + 922);
	*(uint32_t*)(v23 + 48) = *(uint32_t*)(a1 + 926);
	*(uint32_t*)(v23 + 52) = *(uint32_t*)(a1 + 930);
	*(uint32_t*)(v23 + 56) = *(uint32_t*)(a1 + 934);
	*(uint32_t*)(v23 + 60) = *(uint32_t*)(a1 + 938);
	*(uint32_t*)(v23 + 64) = *(uint32_t*)(a1 + 942);
	*(uint32_t*)(v23 + 68) = *(uint32_t*)(a1 + 946);
	*(uint32_t*)(v23 + 72) = *(uint32_t*)(a1 + 950);
	*(uint32_t*)(v23 + 76) = *(uint32_t*)(a1 + 954);
	*(uint32_t*)(v23 + 80) = *(uint32_t*)(a1 + 958);
	*(uint32_t*)(v23 + 84) = *(uint32_t*)(a1 + 962);
	*(uint16_t*)(v23 + 88) = *(uint16_t*)(a1 + 966);
	v24 = v2 + v23;
	*(uint16_t*)(v24 + 2) = *(uint16_t*)(a1 + 968);
	*(uint32_t*)(v24 + 4) = *(uint32_t*)(a1 + 970);
	*(uint32_t*)(v24 + 8) = *(uint32_t*)(a1 + 974);
	*(uint32_t*)(v24 + 12) = *(uint32_t*)(a1 + 978);
	*(uint32_t*)(v24 + 16) = *(uint32_t*)(a1 + 982);
	*(uint32_t*)(v24 + 20) = *(uint32_t*)(a1 + 986);
	*(uint32_t*)(v24 + 24) = *(uint32_t*)(a1 + 990);
	*(uint32_t*)(v24 + 28) = *(uint32_t*)(a1 + 994);
	*(uint32_t*)(v24 + 32) = *(uint32_t*)(a1 + 998);
	*(uint32_t*)(v24 + 36) = *(uint32_t*)(a1 + 1002);
	*(uint32_t*)(v24 + 40) = *(uint32_t*)(a1 + 1006);
	*(uint32_t*)(v24 + 44) = *(uint32_t*)(a1 + 1010);
	*(uint32_t*)(v24 + 48) = *(uint32_t*)(a1 + 1014);
	*(uint32_t*)(v24 + 52) = *(uint32_t*)(a1 + 1018);
	*(uint32_t*)(v24 + 56) = *(uint32_t*)(a1 + 1022);
	*(uint32_t*)(v24 + 60) = *(uint32_t*)(a1 + 1026);
	*(uint32_t*)(v24 + 64) = *(uint32_t*)(a1 + 1030);
	*(uint32_t*)(v24 + 68) = *(uint32_t*)(a1 + 1034);
	*(uint32_t*)(v24 + 72) = *(uint32_t*)(a1 + 1038);
	*(uint32_t*)(v24 + 76) = *(uint32_t*)(a1 + 1042);
	*(uint32_t*)(v24 + 80) = *(uint32_t*)(a1 + 1046);
	*(uint32_t*)(v24 + 84) = *(uint32_t*)(a1 + 1050);
	*(uint32_t*)(v24 + 88) = *(uint32_t*)(a1 + 1054);
	v25 = v2 + v24;
	*(uint16_t*)(v25 + 2) = *(uint16_t*)(a1 + 1058);
	*(uint32_t*)(v25 + 4) = *(uint32_t*)(a1 + 1060);
	*(uint32_t*)(v25 + 8) = *(uint32_t*)(a1 + 1064);
	*(uint32_t*)(v25 + 12) = *(uint32_t*)(a1 + 1068);
	*(uint32_t*)(v25 + 16) = *(uint32_t*)(a1 + 1072);
	*(uint32_t*)(v25 + 20) = *(uint32_t*)(a1 + 1076);
	*(uint32_t*)(v25 + 24) = *(uint32_t*)(a1 + 1080);
	*(uint32_t*)(v25 + 28) = *(uint32_t*)(a1 + 1084);
	*(uint32_t*)(v25 + 32) = *(uint32_t*)(a1 + 1088);
	*(uint32_t*)(v25 + 36) = *(uint32_t*)(a1 + 1092);
	*(uint32_t*)(v25 + 40) = *(uint32_t*)(a1 + 1096);
	*(uint32_t*)(v25 + 44) = *(uint32_t*)(a1 + 1100);
	*(uint32_t*)(v25 + 48) = *(uint32_t*)(a1 + 1104);
	*(uint32_t*)(v25 + 52) = *(uint32_t*)(a1 + 1108);
	*(uint32_t*)(v25 + 56) = *(uint32_t*)(a1 + 1112);
	*(uint32_t*)(v25 + 60) = *(uint32_t*)(a1 + 1116);
	*(uint32_t*)(v25 + 64) = *(uint32_t*)(a1 + 1120);
	*(uint32_t*)(v25 + 68) = *(uint32_t*)(a1 + 1124);
	*(uint32_t*)(v25 + 72) = *(uint32_t*)(a1 + 1128);
	*(uint32_t*)(v25 + 76) = *(uint32_t*)(a1 + 1132);
	*(uint32_t*)(v25 + 80) = *(uint32_t*)(a1 + 1136);
	*(uint32_t*)(v25 + 84) = *(uint32_t*)(a1 + 1140);
	*(uint32_t*)(v25 + 88) = *(uint32_t*)(a1 + 1144);
	v26 = v2 + v25;
	*(uint32_t*)(v26 + 4) = *(uint32_t*)(a1 + 1148);
	*(uint32_t*)(v26 + 8) = *(uint32_t*)(a1 + 1152);
	*(uint32_t*)(v26 + 12) = *(uint32_t*)(a1 + 1156);
	*(uint32_t*)(v26 + 16) = *(uint32_t*)(a1 + 1160);
	*(uint32_t*)(v26 + 20) = *(uint32_t*)(a1 + 1164);
	*(uint32_t*)(v26 + 24) = *(uint32_t*)(a1 + 1168);
	*(uint32_t*)(v26 + 28) = *(uint32_t*)(a1 + 1172);
	*(uint32_t*)(v26 + 32) = *(uint32_t*)(a1 + 1176);
	*(uint32_t*)(v26 + 36) = *(uint32_t*)(a1 + 1180);
	*(uint32_t*)(v26 + 40) = *(uint32_t*)(a1 + 1184);
	*(uint32_t*)(v26 + 44) = *(uint32_t*)(a1 + 1188);
	*(uint32_t*)(v26 + 48) = *(uint32_t*)(a1 + 1192);
	*(uint32_t*)(v26 + 52) = *(uint32_t*)(a1 + 1196);
	*(uint32_t*)(v26 + 56) = *(uint32_t*)(a1 + 1200);
	*(uint32_t*)(v26 + 60) = *(uint32_t*)(a1 + 1204);
	*(uint32_t*)(v26 + 64) = *(uint32_t*)(a1 + 1208);
	*(uint32_t*)(v26 + 68) = *(uint32_t*)(a1 + 1212);
	*(uint32_t*)(v26 + 72) = *(uint32_t*)(a1 + 1216);
	*(uint32_t*)(v26 + 76) = *(uint32_t*)(a1 + 1220);
	*(uint32_t*)(v26 + 80) = *(uint32_t*)(a1 + 1224);
	*(uint32_t*)(v26 + 84) = *(uint32_t*)(a1 + 1228);
	*(uint16_t*)(v26 + 88) = *(uint16_t*)(a1 + 1232);
	v27 = v2 + v26;
	*(uint16_t*)(v27 + 6) = *(uint16_t*)(a1 + 1234);
	*(uint32_t*)(v27 + 8) = *(uint32_t*)(a1 + 1236);
	*(uint32_t*)(v27 + 12) = *(uint32_t*)(a1 + 1240);
	*(uint32_t*)(v27 + 16) = *(uint32_t*)(a1 + 1244);
	*(uint32_t*)(v27 + 20) = *(uint32_t*)(a1 + 1248);
	*(uint32_t*)(v27 + 24) = *(uint32_t*)(a1 + 1252);
	*(uint32_t*)(v27 + 28) = *(uint32_t*)(a1 + 1256);
	*(uint32_t*)(v27 + 32) = *(uint32_t*)(a1 + 1260);
	*(uint32_t*)(v27 + 36) = *(uint32_t*)(a1 + 1264);
	*(uint32_t*)(v27 + 40) = *(uint32_t*)(a1 + 1268);
	*(uint32_t*)(v27 + 44) = *(uint32_t*)(a1 + 1272);
	*(uint32_t*)(v27 + 48) = *(uint32_t*)(a1 + 1276);
	*(uint32_t*)(v27 + 52) = *(uint32_t*)(a1 + 1280);
	*(uint32_t*)(v27 + 56) = *(uint32_t*)(a1 + 1284);
	*(uint32_t*)(v27 + 60) = *(uint32_t*)(a1 + 1288);
	*(uint32_t*)(v27 + 64) = *(uint32_t*)(a1 + 1292);
	*(uint32_t*)(v27 + 68) = *(uint32_t*)(a1 + 1296);
	*(uint32_t*)(v27 + 72) = *(uint32_t*)(a1 + 1300);
	*(uint32_t*)(v27 + 76) = *(uint32_t*)(a1 + 1304);
	*(uint32_t*)(v27 + 80) = *(uint32_t*)(a1 + 1308);
	*(uint32_t*)(v27 + 84) = *(uint32_t*)(a1 + 1312);
	v28 = v2 + v27;
	*(uint32_t*)(v28 + 8) = *(uint32_t*)(a1 + 1316);
	*(uint32_t*)(v28 + 12) = *(uint32_t*)(a1 + 1320);
	*(uint32_t*)(v28 + 16) = *(uint32_t*)(a1 + 1324);
	*(uint32_t*)(v28 + 20) = *(uint32_t*)(a1 + 1328);
	*(uint32_t*)(v28 + 24) = *(uint32_t*)(a1 + 1332);
	*(uint32_t*)(v28 + 28) = *(uint32_t*)(a1 + 1336);
	*(uint32_t*)(v28 + 32) = *(uint32_t*)(a1 + 1340);
	*(uint32_t*)(v28 + 36) = *(uint32_t*)(a1 + 1344);
	*(uint32_t*)(v28 + 40) = *(uint32_t*)(a1 + 1348);
	*(uint32_t*)(v28 + 44) = *(uint32_t*)(a1 + 1352);
	*(uint32_t*)(v28 + 48) = *(uint32_t*)(a1 + 1356);
	*(uint32_t*)(v28 + 52) = *(uint32_t*)(a1 + 1360);
	*(uint32_t*)(v28 + 56) = *(uint32_t*)(a1 + 1364);
	*(uint32_t*)(v28 + 60) = *(uint32_t*)(a1 + 1368);
	*(uint32_t*)(v28 + 64) = *(uint32_t*)(a1 + 1372);
	*(uint32_t*)(v28 + 68) = *(uint32_t*)(a1 + 1376);
	*(uint32_t*)(v28 + 72) = *(uint32_t*)(a1 + 1380);
	*(uint32_t*)(v28 + 76) = *(uint32_t*)(a1 + 1384);
	*(uint32_t*)(v28 + 80) = *(uint32_t*)(a1 + 1388);
	*(uint16_t*)(v28 + 84) = *(uint16_t*)(a1 + 1392);
	v29 = v2 + v28;
	*(uint16_t*)(v29 + 10) = *(uint16_t*)(a1 + 1394);
	*(uint32_t*)(v29 + 12) = *(uint32_t*)(a1 + 1396);
	*(uint32_t*)(v29 + 16) = *(uint32_t*)(a1 + 1400);
	*(uint32_t*)(v29 + 20) = *(uint32_t*)(a1 + 1404);
	*(uint32_t*)(v29 + 24) = *(uint32_t*)(a1 + 1408);
	*(uint32_t*)(v29 + 28) = *(uint32_t*)(a1 + 1412);
	*(uint32_t*)(v29 + 32) = *(uint32_t*)(a1 + 1416);
	*(uint32_t*)(v29 + 36) = *(uint32_t*)(a1 + 1420);
	*(uint32_t*)(v29 + 40) = *(uint32_t*)(a1 + 1424);
	*(uint32_t*)(v29 + 44) = *(uint32_t*)(a1 + 1428);
	*(uint32_t*)(v29 + 48) = *(uint32_t*)(a1 + 1432);
	*(uint32_t*)(v29 + 52) = *(uint32_t*)(a1 + 1436);
	*(uint32_t*)(v29 + 56) = *(uint32_t*)(a1 + 1440);
	*(uint32_t*)(v29 + 60) = *(uint32_t*)(a1 + 1444);
	*(uint32_t*)(v29 + 64) = *(uint32_t*)(a1 + 1448);
	*(uint32_t*)(v29 + 68) = *(uint32_t*)(a1 + 1452);
	*(uint32_t*)(v29 + 72) = *(uint32_t*)(a1 + 1456);
	*(uint32_t*)(v29 + 76) = *(uint32_t*)(a1 + 1460);
	*(uint32_t*)(v29 + 80) = *(uint32_t*)(a1 + 1464);
	v30 = v2 + v29;
	*(uint32_t*)(v30 + 12) = *(uint32_t*)(a1 + 1468);
	*(uint32_t*)(v30 + 16) = *(uint32_t*)(a1 + 1472);
	*(uint32_t*)(v30 + 20) = *(uint32_t*)(a1 + 1476);
	*(uint32_t*)(v30 + 24) = *(uint32_t*)(a1 + 1480);
	*(uint32_t*)(v30 + 28) = *(uint32_t*)(a1 + 1484);
	*(uint32_t*)(v30 + 32) = *(uint32_t*)(a1 + 1488);
	*(uint32_t*)(v30 + 36) = *(uint32_t*)(a1 + 1492);
	*(uint32_t*)(v30 + 40) = *(uint32_t*)(a1 + 1496);
	*(uint32_t*)(v30 + 44) = *(uint32_t*)(a1 + 1500);
	*(uint32_t*)(v30 + 48) = *(uint32_t*)(a1 + 1504);
	*(uint32_t*)(v30 + 52) = *(uint32_t*)(a1 + 1508);
	*(uint32_t*)(v30 + 56) = *(uint32_t*)(a1 + 1512);
	*(uint32_t*)(v30 + 60) = *(uint32_t*)(a1 + 1516);
	*(uint32_t*)(v30 + 64) = *(uint32_t*)(a1 + 1520);
	*(uint32_t*)(v30 + 68) = *(uint32_t*)(a1 + 1524);
	*(uint32_t*)(v30 + 72) = *(uint32_t*)(a1 + 1528);
	*(uint32_t*)(v30 + 76) = *(uint32_t*)(a1 + 1532);
	*(uint16_t*)(v30 + 80) = *(uint16_t*)(a1 + 1536);
	v31 = v2 + v30;
	*(uint16_t*)(v31 + 14) = *(uint16_t*)(a1 + 1538);
	*(uint32_t*)(v31 + 16) = *(uint32_t*)(a1 + 1540);
	*(uint32_t*)(v31 + 20) = *(uint32_t*)(a1 + 1544);
	*(uint32_t*)(v31 + 24) = *(uint32_t*)(a1 + 1548);
	*(uint32_t*)(v31 + 28) = *(uint32_t*)(a1 + 1552);
	*(uint32_t*)(v31 + 32) = *(uint32_t*)(a1 + 1556);
	*(uint32_t*)(v31 + 36) = *(uint32_t*)(a1 + 1560);
	*(uint32_t*)(v31 + 40) = *(uint32_t*)(a1 + 1564);
	*(uint32_t*)(v31 + 44) = *(uint32_t*)(a1 + 1568);
	*(uint32_t*)(v31 + 48) = *(uint32_t*)(a1 + 1572);
	*(uint32_t*)(v31 + 52) = *(uint32_t*)(a1 + 1576);
	*(uint32_t*)(v31 + 56) = *(uint32_t*)(a1 + 1580);
	*(uint32_t*)(v31 + 60) = *(uint32_t*)(a1 + 1584);
	*(uint32_t*)(v31 + 64) = *(uint32_t*)(a1 + 1588);
	*(uint32_t*)(v31 + 68) = *(uint32_t*)(a1 + 1592);
	*(uint32_t*)(v31 + 72) = *(uint32_t*)(a1 + 1596);
	*(uint32_t*)(v31 + 76) = *(uint32_t*)(a1 + 1600);
	v32 = v2 + v31;
	*(uint32_t*)(v32 + 16) = *(uint32_t*)(a1 + 1604);
	*(uint32_t*)(v32 + 20) = *(uint32_t*)(a1 + 1608);
	*(uint32_t*)(v32 + 24) = *(uint32_t*)(a1 + 1612);
	*(uint32_t*)(v32 + 28) = *(uint32_t*)(a1 + 1616);
	*(uint32_t*)(v32 + 32) = *(uint32_t*)(a1 + 1620);
	*(uint32_t*)(v32 + 36) = *(uint32_t*)(a1 + 1624);
	*(uint32_t*)(v32 + 40) = *(uint32_t*)(a1 + 1628);
	*(uint32_t*)(v32 + 44) = *(uint32_t*)(a1 + 1632);
	*(uint32_t*)(v32 + 48) = *(uint32_t*)(a1 + 1636);
	*(uint32_t*)(v32 + 52) = *(uint32_t*)(a1 + 1640);
	*(uint32_t*)(v32 + 56) = *(uint32_t*)(a1 + 1644);
	*(uint32_t*)(v32 + 60) = *(uint32_t*)(a1 + 1648);
	*(uint32_t*)(v32 + 64) = *(uint32_t*)(a1 + 1652);
	*(uint32_t*)(v32 + 68) = *(uint32_t*)(a1 + 1656);
	*(uint32_t*)(v32 + 72) = *(uint32_t*)(a1 + 1660);
	*(uint16_t*)(v32 + 76) = *(uint16_t*)(a1 + 1664);
	v33 = v2 + v32;
	*(uint16_t*)(v33 + 18) = *(uint16_t*)(a1 + 1666);
	*(uint32_t*)(v33 + 20) = *(uint32_t*)(a1 + 1668);
	*(uint32_t*)(v33 + 24) = *(uint32_t*)(a1 + 1672);
	*(uint32_t*)(v33 + 28) = *(uint32_t*)(a1 + 1676);
	*(uint32_t*)(v33 + 32) = *(uint32_t*)(a1 + 1680);
	*(uint32_t*)(v33 + 36) = *(uint32_t*)(a1 + 1684);
	*(uint32_t*)(v33 + 40) = *(uint32_t*)(a1 + 1688);
	*(uint32_t*)(v33 + 44) = *(uint32_t*)(a1 + 1692);
	*(uint32_t*)(v33 + 48) = *(uint32_t*)(a1 + 1696);
	*(uint32_t*)(v33 + 52) = *(uint32_t*)(a1 + 1700);
	*(uint32_t*)(v33 + 56) = *(uint32_t*)(a1 + 1704);
	*(uint32_t*)(v33 + 60) = *(uint32_t*)(a1 + 1708);
	*(uint32_t*)(v33 + 64) = *(uint32_t*)(a1 + 1712);
	*(uint32_t*)(v33 + 68) = *(uint32_t*)(a1 + 1716);
	*(uint32_t*)(v33 + 72) = *(uint32_t*)(a1 + 1720);
	v34 = v2 + v33;
	*(uint32_t*)(v34 + 20) = *(uint32_t*)(a1 + 1724);
	*(uint32_t*)(v34 + 24) = *(uint32_t*)(a1 + 1728);
	*(uint32_t*)(v34 + 28) = *(uint32_t*)(a1 + 1732);
	*(uint32_t*)(v34 + 32) = *(uint32_t*)(a1 + 1736);
	*(uint32_t*)(v34 + 36) = *(uint32_t*)(a1 + 1740);
	*(uint32_t*)(v34 + 40) = *(uint32_t*)(a1 + 1744);
	*(uint32_t*)(v34 + 44) = *(uint32_t*)(a1 + 1748);
	*(uint32_t*)(v34 + 48) = *(uint32_t*)(a1 + 1752);
	*(uint32_t*)(v34 + 52) = *(uint32_t*)(a1 + 1756);
	*(uint32_t*)(v34 + 56) = *(uint32_t*)(a1 + 1760);
	*(uint32_t*)(v34 + 60) = *(uint32_t*)(a1 + 1764);
	*(uint32_t*)(v34 + 64) = *(uint32_t*)(a1 + 1768);
	*(uint32_t*)(v34 + 68) = *(uint32_t*)(a1 + 1772);
	*(uint16_t*)(v34 + 72) = *(uint16_t*)(a1 + 1776);
	v35 = v2 + v34;
	*(uint16_t*)(v35 + 22) = *(uint16_t*)(a1 + 1778);
	*(uint32_t*)(v35 + 24) = *(uint32_t*)(a1 + 1780);
	*(uint32_t*)(v35 + 28) = *(uint32_t*)(a1 + 1784);
	*(uint32_t*)(v35 + 32) = *(uint32_t*)(a1 + 1788);
	*(uint32_t*)(v35 + 36) = *(uint32_t*)(a1 + 1792);
	*(uint32_t*)(v35 + 40) = *(uint32_t*)(a1 + 1796);
	*(uint32_t*)(v35 + 44) = *(uint32_t*)(a1 + 1800);
	*(uint32_t*)(v35 + 48) = *(uint32_t*)(a1 + 1804);
	*(uint32_t*)(v35 + 52) = *(uint32_t*)(a1 + 1808);
	*(uint32_t*)(v35 + 56) = *(uint32_t*)(a1 + 1812);
	*(uint32_t*)(v35 + 60) = *(uint32_t*)(a1 + 1816);
	*(uint32_t*)(v35 + 64) = *(uint32_t*)(a1 + 1820);
	*(uint32_t*)(v35 + 68) = *(uint32_t*)(a1 + 1824);
	v36 = v2 + v35;
	*(uint32_t*)(v36 + 24) = *(uint32_t*)(a1 + 1828);
	*(uint32_t*)(v36 + 28) = *(uint32_t*)(a1 + 1832);
	*(uint32_t*)(v36 + 32) = *(uint32_t*)(a1 + 1836);
	*(uint32_t*)(v36 + 36) = *(uint32_t*)(a1 + 1840);
	*(uint32_t*)(v36 + 40) = *(uint32_t*)(a1 + 1844);
	*(uint32_t*)(v36 + 44) = *(uint32_t*)(a1 + 1848);
	*(uint32_t*)(v36 + 48) = *(uint32_t*)(a1 + 1852);
	*(uint32_t*)(v36 + 52) = *(uint32_t*)(a1 + 1856);
	*(uint32_t*)(v36 + 56) = *(uint32_t*)(a1 + 1860);
	*(uint32_t*)(v36 + 60) = *(uint32_t*)(a1 + 1864);
	*(uint32_t*)(v36 + 64) = *(uint32_t*)(a1 + 1868);
	*(uint16_t*)(v36 + 68) = *(uint16_t*)(a1 + 1872);
	v37 = v2 + v36;
	*(uint16_t*)(v37 + 26) = *(uint16_t*)(a1 + 1874);
	*(uint32_t*)(v37 + 28) = *(uint32_t*)(a1 + 1876);
	*(uint32_t*)(v37 + 32) = *(uint32_t*)(a1 + 1880);
	*(uint32_t*)(v37 + 36) = *(uint32_t*)(a1 + 1884);
	*(uint32_t*)(v37 + 40) = *(uint32_t*)(a1 + 1888);
	*(uint32_t*)(v37 + 44) = *(uint32_t*)(a1 + 1892);
	*(uint32_t*)(v37 + 48) = *(uint32_t*)(a1 + 1896);
	*(uint32_t*)(v37 + 52) = *(uint32_t*)(a1 + 1900);
	*(uint32_t*)(v37 + 56) = *(uint32_t*)(a1 + 1904);
	*(uint32_t*)(v37 + 60) = *(uint32_t*)(a1 + 1908);
	*(uint32_t*)(v37 + 64) = *(uint32_t*)(a1 + 1912);
	v38 = v2 + v37;
	*(uint32_t*)(v38 + 28) = *(uint32_t*)(a1 + 1916);
	*(uint32_t*)(v38 + 32) = *(uint32_t*)(a1 + 1920);
	*(uint32_t*)(v38 + 36) = *(uint32_t*)(a1 + 1924);
	*(uint32_t*)(v38 + 40) = *(uint32_t*)(a1 + 1928);
	*(uint32_t*)(v38 + 44) = *(uint32_t*)(a1 + 1932);
	*(uint32_t*)(v38 + 48) = *(uint32_t*)(a1 + 1936);
	*(uint32_t*)(v38 + 52) = *(uint32_t*)(a1 + 1940);
	*(uint32_t*)(v38 + 56) = *(uint32_t*)(a1 + 1944);
	*(uint32_t*)(v38 + 60) = *(uint32_t*)(a1 + 1948);
	*(uint16_t*)(v38 + 64) = *(uint16_t*)(a1 + 1952);
	v39 = v2 + v38;
	*(uint16_t*)(v39 + 30) = *(uint16_t*)(a1 + 1954);
	*(uint32_t*)(v39 + 32) = *(uint32_t*)(a1 + 1956);
	*(uint32_t*)(v39 + 36) = *(uint32_t*)(a1 + 1960);
	*(uint32_t*)(v39 + 40) = *(uint32_t*)(a1 + 1964);
	*(uint32_t*)(v39 + 44) = *(uint32_t*)(a1 + 1968);
	*(uint32_t*)(v39 + 48) = *(uint32_t*)(a1 + 1972);
	*(uint32_t*)(v39 + 52) = *(uint32_t*)(a1 + 1976);
	*(uint32_t*)(v39 + 56) = *(uint32_t*)(a1 + 1980);
	*(uint32_t*)(v39 + 60) = *(uint32_t*)(a1 + 1984);
	v40 = v2 + v39;
	*(uint32_t*)(v40 + 32) = *(uint32_t*)(a1 + 1988);
	*(uint32_t*)(v40 + 36) = *(uint32_t*)(a1 + 1992);
	*(uint32_t*)(v40 + 40) = *(uint32_t*)(a1 + 1996);
	*(uint32_t*)(v40 + 44) = *(uint32_t*)(a1 + 2000);
	*(uint32_t*)(v40 + 48) = *(uint32_t*)(a1 + 2004);
	*(uint32_t*)(v40 + 52) = *(uint32_t*)(a1 + 2008);
	*(uint32_t*)(v40 + 56) = *(uint32_t*)(a1 + 2012);
	*(uint16_t*)(v40 + 60) = *(uint16_t*)(a1 + 2016);
	v41 = v2 + v40;
	*(uint16_t*)(v41 + 34) = *(uint16_t*)(a1 + 2018);
	*(uint32_t*)(v41 + 36) = *(uint32_t*)(a1 + 2020);
	*(uint32_t*)(v41 + 40) = *(uint32_t*)(a1 + 2024);
	*(uint32_t*)(v41 + 44) = *(uint32_t*)(a1 + 2028);
	*(uint32_t*)(v41 + 48) = *(uint32_t*)(a1 + 2032);
	*(uint32_t*)(v41 + 52) = *(uint32_t*)(a1 + 2036);
	*(uint32_t*)(v41 + 56) = *(uint32_t*)(a1 + 2040);
	v42 = v2 + v41;
	*(uint32_t*)(v42 + 36) = *(uint32_t*)(a1 + 2044);
	*(uint32_t*)(v42 + 40) = *(uint32_t*)(a1 + 2048);
	*(uint32_t*)(v42 + 44) = *(uint32_t*)(a1 + 2052);
	*(uint32_t*)(v42 + 48) = *(uint32_t*)(a1 + 2056);
	*(uint32_t*)(v42 + 52) = *(uint32_t*)(a1 + 2060);
	*(uint16_t*)(v42 + 56) = *(uint16_t*)(a1 + 2064);
	v43 = v2 + v42;
	*(uint16_t*)(v43 + 38) = *(uint16_t*)(a1 + 2066);
	*(uint32_t*)(v43 + 40) = *(uint32_t*)(a1 + 2068);
	*(uint32_t*)(v43 + 44) = *(uint32_t*)(a1 + 2072);
	*(uint32_t*)(v43 + 48) = *(uint32_t*)(a1 + 2076);
	*(uint32_t*)(v43 + 52) = *(uint32_t*)(a1 + 2080);
	v44 = v2 + v43;
	*(uint32_t*)(v44 + 40) = *(uint32_t*)(a1 + 2084);
	*(uint32_t*)(v44 + 44) = *(uint32_t*)(a1 + 2088);
	*(uint32_t*)(v44 + 48) = *(uint32_t*)(a1 + 2092);
	*(uint16_t*)(v44 + 52) = *(uint16_t*)(a1 + 2096);
	v45 = v2 + v44;
	*(uint16_t*)(v45 + 42) = *(uint16_t*)(a1 + 2098);
	*(uint32_t*)(v45 + 44) = *(uint32_t*)(a1 + 2100);
	*(uint32_t*)(v45 + 48) = *(uint32_t*)(a1 + 2104);
	v46 = v2 + v45;
	*(uint32_t*)(v46 + 44) = *(uint32_t*)(a1 + 2108);
	result = *(uint16_t*)(a1 + 2112);
	*(uint16_t*)(v46 + 48) = result;
	*(uint16_t*)(v2 + v46 + 46) = *(uint16_t*)(a1 + 2114);
	return result;
}

//----- (00483FE0) --------------------------------------------------------
int sub_483FE0(int a1, int a2) {
	int result; // eax
	int v3;     // edx
	int v4;     // edi
	int v5;     // edi
	int v6;     // edi
	int v7;     // edi
	int v8;     // edi
	int v9;     // edi
	int v10;    // edi
	int v11;    // edi
	int v12;    // edi
	int v13;    // edi
	int v14;    // edi
	int v15;    // edi
	int v16;    // edi
	int v17;    // edi
	int v18;    // edi
	int v19;    // edi
	int v20;    // edi
	int v21;    // edi
	int v22;    // edi
	int v23;    // edi
	int v24;    // edi
	int v25;    // edi
	int v26;    // edi
	int v27;    // edi
	int v28;    // edi
	int v29;    // edi
	int v30;    // edi
	int v31;    // edi
	int v32;    // edi
	int v33;    // edi
	int v34;    // edi
	int v35;    // edi
	int v36;    // edi
	int v37;    // edi
	int v38;    // edi
	int v39;    // edi
	int v40;    // edi
	int v41;    // edi
	int v42;    // edi
	int v43;    // edi
	int v44;    // edi
	int v45;    // edi
	int v46;    // edi
	int v47;    // edi

	result = a1;
	v3 = dword_5d4594_3798804;
	*(uint8_t*)(a2 + 23) = a1;
	v4 = v3 + a2;
	*(uint16_t*)(v4 + 22) = a1;
	*(uint8_t*)(v4 + 24) = a1;
	v5 = v3 + v3 + a2;
	*(uint8_t*)(v5 + 21) = a1;
	*(uint16_t*)(v5 + 22) = a1;
	*(uint16_t*)(v5 + 24) = a1;
	v6 = v3 + v5;
	*(uint32_t*)(v6 + 20) = a1;
	*(uint16_t*)(v6 + 24) = a1;
	*(uint8_t*)(v6 + 26) = a1;
	v7 = v3 + v6;
	*(uint8_t*)(v7 + 19) = a1;
	*(uint32_t*)(v7 + 20) = a1;
	*(uint32_t*)(v7 + 24) = a1;
	v8 = v3 + v7;
	*(uint16_t*)(v8 + 18) = a1;
	*(uint32_t*)(v8 + 20) = a1;
	*(uint32_t*)(v8 + 24) = a1;
	*(uint8_t*)(v8 + 28) = a1;
	v9 = v3 + v8;
	*(uint8_t*)(v9 + 17) = a1;
	*(uint16_t*)(v9 + 18) = a1;
	*(uint32_t*)(v9 + 20) = a1;
	*(uint32_t*)(v9 + 24) = a1;
	*(uint16_t*)(v9 + 28) = a1;
	v10 = v3 + v9;
	*(uint32_t*)(v10 + 16) = a1;
	*(uint32_t*)(v10 + 20) = a1;
	*(uint32_t*)(v10 + 24) = a1;
	*(uint16_t*)(v10 + 28) = a1;
	*(uint8_t*)(v10 + 30) = a1;
	v11 = v3 + v10;
	*(uint8_t*)(v11 + 15) = a1;
	*(uint32_t*)(v11 + 16) = a1;
	*(uint32_t*)(v11 + 20) = a1;
	*(uint32_t*)(v11 + 24) = a1;
	*(uint32_t*)(v11 + 28) = a1;
	v12 = v3 + v11;
	*(uint16_t*)(v12 + 14) = a1;
	*(uint32_t*)(v12 + 16) = a1;
	*(uint32_t*)(v12 + 20) = a1;
	*(uint32_t*)(v12 + 24) = a1;
	*(uint32_t*)(v12 + 28) = a1;
	*(uint8_t*)(v12 + 32) = a1;
	v13 = v3 + v12;
	*(uint8_t*)(v13 + 13) = a1;
	*(uint16_t*)(v13 + 14) = a1;
	*(uint32_t*)(v13 + 16) = a1;
	*(uint32_t*)(v13 + 20) = a1;
	*(uint32_t*)(v13 + 24) = a1;
	*(uint32_t*)(v13 + 28) = a1;
	*(uint16_t*)(v13 + 32) = a1;
	v14 = v3 + v13;
	*(uint32_t*)(v14 + 12) = a1;
	*(uint32_t*)(v14 + 16) = a1;
	*(uint32_t*)(v14 + 20) = a1;
	*(uint32_t*)(v14 + 24) = a1;
	*(uint32_t*)(v14 + 28) = a1;
	*(uint16_t*)(v14 + 32) = a1;
	*(uint8_t*)(v14 + 34) = a1;
	v15 = v3 + v14;
	*(uint8_t*)(v15 + 11) = a1;
	*(uint32_t*)(v15 + 12) = a1;
	*(uint32_t*)(v15 + 16) = a1;
	*(uint32_t*)(v15 + 20) = a1;
	*(uint32_t*)(v15 + 24) = a1;
	*(uint32_t*)(v15 + 28) = a1;
	*(uint32_t*)(v15 + 32) = a1;
	v16 = v3 + v15;
	*(uint16_t*)(v16 + 10) = a1;
	*(uint32_t*)(v16 + 12) = a1;
	*(uint32_t*)(v16 + 16) = a1;
	*(uint32_t*)(v16 + 20) = a1;
	*(uint32_t*)(v16 + 24) = a1;
	*(uint32_t*)(v16 + 28) = a1;
	*(uint32_t*)(v16 + 32) = a1;
	*(uint8_t*)(v16 + 36) = a1;
	v17 = v3 + v16;
	*(uint8_t*)(v17 + 9) = a1;
	*(uint16_t*)(v17 + 10) = a1;
	*(uint32_t*)(v17 + 12) = a1;
	*(uint32_t*)(v17 + 16) = a1;
	*(uint32_t*)(v17 + 20) = a1;
	*(uint32_t*)(v17 + 24) = a1;
	*(uint32_t*)(v17 + 28) = a1;
	*(uint32_t*)(v17 + 32) = a1;
	*(uint16_t*)(v17 + 36) = a1;
	v18 = v3 + v17;
	*(uint32_t*)(v18 + 8) = a1;
	*(uint32_t*)(v18 + 12) = a1;
	*(uint32_t*)(v18 + 16) = a1;
	*(uint32_t*)(v18 + 20) = a1;
	*(uint32_t*)(v18 + 24) = a1;
	*(uint32_t*)(v18 + 28) = a1;
	*(uint32_t*)(v18 + 32) = a1;
	*(uint16_t*)(v18 + 36) = a1;
	*(uint8_t*)(v18 + 38) = a1;
	v19 = v3 + v18;
	*(uint8_t*)(v19 + 7) = a1;
	*(uint32_t*)(v19 + 8) = a1;
	*(uint32_t*)(v19 + 12) = a1;
	*(uint32_t*)(v19 + 16) = a1;
	*(uint32_t*)(v19 + 20) = a1;
	*(uint32_t*)(v19 + 24) = a1;
	*(uint32_t*)(v19 + 28) = a1;
	*(uint32_t*)(v19 + 32) = a1;
	*(uint32_t*)(v19 + 36) = a1;
	v20 = v3 + v19;
	*(uint16_t*)(v20 + 6) = a1;
	*(uint32_t*)(v20 + 8) = a1;
	*(uint32_t*)(v20 + 12) = a1;
	*(uint32_t*)(v20 + 16) = a1;
	*(uint32_t*)(v20 + 20) = a1;
	*(uint32_t*)(v20 + 24) = a1;
	*(uint32_t*)(v20 + 28) = a1;
	*(uint32_t*)(v20 + 32) = a1;
	*(uint32_t*)(v20 + 36) = a1;
	*(uint8_t*)(v20 + 40) = a1;
	v21 = v3 + v20;
	*(uint8_t*)(v21 + 5) = a1;
	*(uint16_t*)(v21 + 6) = a1;
	*(uint32_t*)(v21 + 8) = a1;
	*(uint32_t*)(v21 + 12) = a1;
	*(uint32_t*)(v21 + 16) = a1;
	*(uint32_t*)(v21 + 20) = a1;
	*(uint32_t*)(v21 + 24) = a1;
	*(uint32_t*)(v21 + 28) = a1;
	*(uint32_t*)(v21 + 32) = a1;
	*(uint32_t*)(v21 + 36) = a1;
	*(uint16_t*)(v21 + 40) = a1;
	v22 = v3 + v21;
	*(uint32_t*)(v22 + 4) = a1;
	*(uint32_t*)(v22 + 8) = a1;
	*(uint32_t*)(v22 + 12) = a1;
	*(uint32_t*)(v22 + 16) = a1;
	*(uint32_t*)(v22 + 20) = a1;
	*(uint32_t*)(v22 + 24) = a1;
	*(uint32_t*)(v22 + 28) = a1;
	*(uint32_t*)(v22 + 32) = a1;
	*(uint32_t*)(v22 + 36) = a1;
	*(uint16_t*)(v22 + 40) = a1;
	*(uint8_t*)(v22 + 42) = a1;
	v23 = v3 + v22;
	*(uint8_t*)(v23 + 3) = a1;
	*(uint32_t*)(v23 + 4) = a1;
	*(uint32_t*)(v23 + 8) = a1;
	*(uint32_t*)(v23 + 12) = a1;
	*(uint32_t*)(v23 + 16) = a1;
	*(uint32_t*)(v23 + 20) = a1;
	*(uint32_t*)(v23 + 24) = a1;
	*(uint32_t*)(v23 + 28) = a1;
	*(uint32_t*)(v23 + 32) = a1;
	*(uint32_t*)(v23 + 36) = a1;
	*(uint32_t*)(v23 + 40) = a1;
	v24 = v3 + v23;
	*(uint16_t*)(v24 + 2) = a1;
	*(uint32_t*)(v24 + 4) = a1;
	*(uint32_t*)(v24 + 8) = a1;
	*(uint32_t*)(v24 + 12) = a1;
	*(uint32_t*)(v24 + 16) = a1;
	*(uint32_t*)(v24 + 20) = a1;
	*(uint32_t*)(v24 + 24) = a1;
	*(uint32_t*)(v24 + 28) = a1;
	*(uint32_t*)(v24 + 32) = a1;
	*(uint32_t*)(v24 + 36) = a1;
	*(uint32_t*)(v24 + 40) = a1;
	*(uint8_t*)(v24 + 44) = a1;
	v25 = v3 + v24;
	*(uint8_t*)(v25 + 1) = a1;
	*(uint16_t*)(v25 + 2) = a1;
	*(uint32_t*)(v25 + 4) = a1;
	*(uint32_t*)(v25 + 8) = a1;
	*(uint32_t*)(v25 + 12) = a1;
	*(uint32_t*)(v25 + 16) = a1;
	*(uint32_t*)(v25 + 20) = a1;
	*(uint32_t*)(v25 + 24) = a1;
	*(uint32_t*)(v25 + 28) = a1;
	*(uint32_t*)(v25 + 32) = a1;
	*(uint32_t*)(v25 + 36) = a1;
	*(uint32_t*)(v25 + 40) = a1;
	*(uint16_t*)(v25 + 44) = a1;
	v26 = v3 + v25;
	*(uint8_t*)(v26 + 1) = a1;
	*(uint16_t*)(v26 + 2) = a1;
	*(uint32_t*)(v26 + 4) = a1;
	*(uint32_t*)(v26 + 8) = a1;
	*(uint32_t*)(v26 + 12) = a1;
	*(uint32_t*)(v26 + 16) = a1;
	*(uint32_t*)(v26 + 20) = a1;
	*(uint32_t*)(v26 + 24) = a1;
	*(uint32_t*)(v26 + 28) = a1;
	*(uint32_t*)(v26 + 32) = a1;
	*(uint32_t*)(v26 + 36) = a1;
	*(uint32_t*)(v26 + 40) = a1;
	*(uint16_t*)(v26 + 44) = a1;
	v27 = v3 + v26;
	*(uint16_t*)(v27 + 2) = a1;
	*(uint32_t*)(v27 + 4) = a1;
	*(uint32_t*)(v27 + 8) = a1;
	*(uint32_t*)(v27 + 12) = a1;
	*(uint32_t*)(v27 + 16) = a1;
	*(uint32_t*)(v27 + 20) = a1;
	*(uint32_t*)(v27 + 24) = a1;
	*(uint32_t*)(v27 + 28) = a1;
	*(uint32_t*)(v27 + 32) = a1;
	*(uint32_t*)(v27 + 36) = a1;
	*(uint32_t*)(v27 + 40) = a1;
	*(uint8_t*)(v27 + 44) = a1;
	v28 = v3 + v27;
	*(uint8_t*)(v28 + 3) = a1;
	*(uint32_t*)(v28 + 4) = a1;
	*(uint32_t*)(v28 + 8) = a1;
	*(uint32_t*)(v28 + 12) = a1;
	*(uint32_t*)(v28 + 16) = a1;
	*(uint32_t*)(v28 + 20) = a1;
	*(uint32_t*)(v28 + 24) = a1;
	*(uint32_t*)(v28 + 28) = a1;
	*(uint32_t*)(v28 + 32) = a1;
	*(uint32_t*)(v28 + 36) = a1;
	*(uint32_t*)(v28 + 40) = a1;
	v29 = v3 + v28;
	*(uint32_t*)(v29 + 4) = a1;
	*(uint32_t*)(v29 + 8) = a1;
	*(uint32_t*)(v29 + 12) = a1;
	*(uint32_t*)(v29 + 16) = a1;
	*(uint32_t*)(v29 + 20) = a1;
	*(uint32_t*)(v29 + 24) = a1;
	*(uint32_t*)(v29 + 28) = a1;
	*(uint32_t*)(v29 + 32) = a1;
	*(uint32_t*)(v29 + 36) = a1;
	*(uint16_t*)(v29 + 40) = a1;
	*(uint8_t*)(v29 + 42) = a1;
	v30 = v3 + v29;
	*(uint8_t*)(v30 + 5) = a1;
	*(uint16_t*)(v30 + 6) = a1;
	*(uint32_t*)(v30 + 8) = a1;
	*(uint32_t*)(v30 + 12) = a1;
	*(uint32_t*)(v30 + 16) = a1;
	*(uint32_t*)(v30 + 20) = a1;
	*(uint32_t*)(v30 + 24) = a1;
	*(uint32_t*)(v30 + 28) = a1;
	*(uint32_t*)(v30 + 32) = a1;
	*(uint32_t*)(v30 + 36) = a1;
	*(uint16_t*)(v30 + 40) = a1;
	v31 = v3 + v30;
	*(uint16_t*)(v31 + 6) = a1;
	*(uint32_t*)(v31 + 8) = a1;
	*(uint32_t*)(v31 + 12) = a1;
	*(uint32_t*)(v31 + 16) = a1;
	*(uint32_t*)(v31 + 20) = a1;
	*(uint32_t*)(v31 + 24) = a1;
	*(uint32_t*)(v31 + 28) = a1;
	*(uint32_t*)(v31 + 32) = a1;
	*(uint32_t*)(v31 + 36) = a1;
	*(uint8_t*)(v31 + 40) = a1;
	v32 = v3 + v31;
	*(uint8_t*)(v32 + 7) = a1;
	*(uint32_t*)(v32 + 8) = a1;
	*(uint32_t*)(v32 + 12) = a1;
	*(uint32_t*)(v32 + 16) = a1;
	*(uint32_t*)(v32 + 20) = a1;
	*(uint32_t*)(v32 + 24) = a1;
	*(uint32_t*)(v32 + 28) = a1;
	*(uint32_t*)(v32 + 32) = a1;
	*(uint32_t*)(v32 + 36) = a1;
	v33 = v3 + v32;
	*(uint32_t*)(v33 + 8) = a1;
	*(uint32_t*)(v33 + 12) = a1;
	*(uint32_t*)(v33 + 16) = a1;
	*(uint32_t*)(v33 + 20) = a1;
	*(uint32_t*)(v33 + 24) = a1;
	*(uint32_t*)(v33 + 28) = a1;
	*(uint32_t*)(v33 + 32) = a1;
	*(uint16_t*)(v33 + 36) = a1;
	*(uint8_t*)(v33 + 38) = a1;
	v34 = v3 + v33;
	*(uint8_t*)(v34 + 9) = a1;
	*(uint16_t*)(v34 + 10) = a1;
	*(uint32_t*)(v34 + 12) = a1;
	*(uint32_t*)(v34 + 16) = a1;
	*(uint32_t*)(v34 + 20) = a1;
	*(uint32_t*)(v34 + 24) = a1;
	*(uint32_t*)(v34 + 28) = a1;
	*(uint32_t*)(v34 + 32) = a1;
	*(uint16_t*)(v34 + 36) = a1;
	v35 = v3 + v34;
	*(uint16_t*)(v35 + 10) = a1;
	*(uint32_t*)(v35 + 12) = a1;
	*(uint32_t*)(v35 + 16) = a1;
	*(uint32_t*)(v35 + 20) = a1;
	*(uint32_t*)(v35 + 24) = a1;
	*(uint32_t*)(v35 + 28) = a1;
	*(uint32_t*)(v35 + 32) = a1;
	*(uint8_t*)(v35 + 36) = a1;
	v36 = v3 + v35;
	*(uint8_t*)(v36 + 11) = a1;
	*(uint32_t*)(v36 + 12) = a1;
	*(uint32_t*)(v36 + 16) = a1;
	*(uint32_t*)(v36 + 20) = a1;
	*(uint32_t*)(v36 + 24) = a1;
	*(uint32_t*)(v36 + 28) = a1;
	*(uint32_t*)(v36 + 32) = a1;
	v37 = v3 + v36;
	*(uint32_t*)(v37 + 12) = a1;
	*(uint32_t*)(v37 + 16) = a1;
	*(uint32_t*)(v37 + 20) = a1;
	*(uint32_t*)(v37 + 24) = a1;
	*(uint32_t*)(v37 + 28) = a1;
	*(uint16_t*)(v37 + 32) = a1;
	*(uint8_t*)(v37 + 34) = a1;
	v38 = v3 + v37;
	*(uint8_t*)(v38 + 13) = a1;
	*(uint16_t*)(v38 + 14) = a1;
	*(uint32_t*)(v38 + 16) = a1;
	*(uint32_t*)(v38 + 20) = a1;
	*(uint32_t*)(v38 + 24) = a1;
	*(uint32_t*)(v38 + 28) = a1;
	*(uint16_t*)(v38 + 32) = a1;
	v39 = v3 + v38;
	*(uint16_t*)(v39 + 14) = a1;
	*(uint32_t*)(v39 + 16) = a1;
	*(uint32_t*)(v39 + 20) = a1;
	*(uint32_t*)(v39 + 24) = a1;
	*(uint32_t*)(v39 + 28) = a1;
	*(uint8_t*)(v39 + 32) = a1;
	v40 = v3 + v39;
	*(uint8_t*)(v40 + 15) = a1;
	*(uint32_t*)(v40 + 16) = a1;
	*(uint32_t*)(v40 + 20) = a1;
	*(uint32_t*)(v40 + 24) = a1;
	*(uint32_t*)(v40 + 28) = a1;
	v41 = v3 + v40;
	*(uint32_t*)(v41 + 16) = a1;
	*(uint32_t*)(v41 + 20) = a1;
	*(uint32_t*)(v41 + 24) = a1;
	*(uint16_t*)(v41 + 28) = a1;
	*(uint8_t*)(v41 + 30) = a1;
	v42 = v3 + v41;
	*(uint8_t*)(v42 + 17) = a1;
	*(uint16_t*)(v42 + 18) = a1;
	*(uint32_t*)(v42 + 20) = a1;
	*(uint32_t*)(v42 + 24) = a1;
	*(uint16_t*)(v42 + 28) = a1;
	v43 = v3 + v42;
	*(uint16_t*)(v43 + 18) = a1;
	*(uint32_t*)(v43 + 20) = a1;
	*(uint32_t*)(v43 + 24) = a1;
	*(uint8_t*)(v43 + 28) = a1;
	v44 = v3 + v43;
	*(uint8_t*)(v44 + 19) = a1;
	*(uint32_t*)(v44 + 20) = a1;
	*(uint32_t*)(v44 + 24) = a1;
	v45 = v3 + v44;
	*(uint32_t*)(v45 + 20) = a1;
	*(uint16_t*)(v45 + 24) = a1;
	*(uint8_t*)(v45 + 26) = a1;
	v46 = v3 + v45;
	*(uint8_t*)(v46 + 21) = a1;
	*(uint16_t*)(v46 + 22) = a1;
	*(uint16_t*)(v46 + 24) = a1;
	v47 = v3 + v46;
	*(uint16_t*)(v47 + 22) = a1;
	*(uint8_t*)(v47 + 24) = a1;
	*(uint8_t*)(v3 + v47 + 23) = a1;
	return result;
}

//----- (00484450) --------------------------------------------------------
int sub_484450(int a1, int a2) {
	int result; // eax
	int v3;     // edx
	int v4;     // edi
	int v5;     // edi
	int v6;     // edi
	int v7;     // edi
	int v8;     // edi
	int v9;     // edi
	int v10;    // edi
	int v11;    // edi
	int v12;    // edi
	int v13;    // edi
	int v14;    // edi
	int v15;    // edi
	int v16;    // edi
	int v17;    // edi
	int v18;    // edi
	int v19;    // edi
	int v20;    // edi
	int v21;    // edi
	int v22;    // edi
	int v23;    // edi
	int v24;    // edi
	int v25;    // edi
	int v26;    // edi
	int v27;    // edi
	int v28;    // edi
	int v29;    // edi
	int v30;    // edi
	int v31;    // edi
	int v32;    // edi
	int v33;    // edi
	int v34;    // edi
	int v35;    // edi
	int v36;    // edi
	int v37;    // edi
	int v38;    // edi
	int v39;    // edi
	int v40;    // edi
	int v41;    // edi
	int v42;    // edi
	int v43;    // edi
	int v44;    // edi
	int v45;    // edi
	int v46;    // edi
	int v47;    // edi

	result = a1;
	v3 = dword_5d4594_3798804;
	*(uint16_t*)(a2 + 46) = a1;
	v4 = v3 + a2;
	*(uint32_t*)(v4 + 44) = a1;
	*(uint16_t*)(v4 + 48) = a1;
	v5 = v3 + v3 + a2;
	*(uint16_t*)(v5 + 42) = a1;
	*(uint32_t*)(v5 + 44) = a1;
	*(uint32_t*)(v5 + 48) = a1;
	v6 = v3 + v5;
	*(uint32_t*)(v6 + 40) = a1;
	*(uint32_t*)(v6 + 44) = a1;
	*(uint32_t*)(v6 + 48) = a1;
	*(uint16_t*)(v6 + 52) = a1;
	v7 = v3 + v6;
	*(uint16_t*)(v7 + 38) = a1;
	*(uint32_t*)(v7 + 40) = a1;
	*(uint32_t*)(v7 + 44) = a1;
	*(uint32_t*)(v7 + 48) = a1;
	*(uint32_t*)(v7 + 52) = a1;
	v8 = v3 + v7;
	*(uint32_t*)(v8 + 36) = a1;
	*(uint32_t*)(v8 + 40) = a1;
	*(uint32_t*)(v8 + 44) = a1;
	*(uint32_t*)(v8 + 48) = a1;
	*(uint32_t*)(v8 + 52) = a1;
	*(uint16_t*)(v8 + 56) = a1;
	v9 = v3 + v8;
	*(uint16_t*)(v9 + 34) = a1;
	*(uint32_t*)(v9 + 36) = a1;
	*(uint32_t*)(v9 + 40) = a1;
	*(uint32_t*)(v9 + 44) = a1;
	*(uint32_t*)(v9 + 48) = a1;
	*(uint32_t*)(v9 + 52) = a1;
	*(uint32_t*)(v9 + 56) = a1;
	v10 = v3 + v9;
	*(uint32_t*)(v10 + 32) = a1;
	*(uint32_t*)(v10 + 36) = a1;
	*(uint32_t*)(v10 + 40) = a1;
	*(uint32_t*)(v10 + 44) = a1;
	*(uint32_t*)(v10 + 48) = a1;
	*(uint32_t*)(v10 + 52) = a1;
	*(uint32_t*)(v10 + 56) = a1;
	*(uint16_t*)(v10 + 60) = a1;
	v11 = v3 + v10;
	*(uint16_t*)(v11 + 30) = a1;
	*(uint32_t*)(v11 + 32) = a1;
	*(uint32_t*)(v11 + 36) = a1;
	*(uint32_t*)(v11 + 40) = a1;
	*(uint32_t*)(v11 + 44) = a1;
	*(uint32_t*)(v11 + 48) = a1;
	*(uint32_t*)(v11 + 52) = a1;
	*(uint32_t*)(v11 + 56) = a1;
	*(uint32_t*)(v11 + 60) = a1;
	v12 = v3 + v11;
	*(uint32_t*)(v12 + 28) = a1;
	*(uint32_t*)(v12 + 32) = a1;
	*(uint32_t*)(v12 + 36) = a1;
	*(uint32_t*)(v12 + 40) = a1;
	*(uint32_t*)(v12 + 44) = a1;
	*(uint32_t*)(v12 + 48) = a1;
	*(uint32_t*)(v12 + 52) = a1;
	*(uint32_t*)(v12 + 56) = a1;
	*(uint32_t*)(v12 + 60) = a1;
	*(uint16_t*)(v12 + 64) = a1;
	v13 = v3 + v12;
	*(uint16_t*)(v13 + 26) = a1;
	*(uint32_t*)(v13 + 28) = a1;
	*(uint32_t*)(v13 + 32) = a1;
	*(uint32_t*)(v13 + 36) = a1;
	*(uint32_t*)(v13 + 40) = a1;
	*(uint32_t*)(v13 + 44) = a1;
	*(uint32_t*)(v13 + 48) = a1;
	*(uint32_t*)(v13 + 52) = a1;
	*(uint32_t*)(v13 + 56) = a1;
	*(uint32_t*)(v13 + 60) = a1;
	*(uint32_t*)(v13 + 64) = a1;
	v14 = v3 + v13;
	*(uint32_t*)(v14 + 24) = a1;
	*(uint32_t*)(v14 + 28) = a1;
	*(uint32_t*)(v14 + 32) = a1;
	*(uint32_t*)(v14 + 36) = a1;
	*(uint32_t*)(v14 + 40) = a1;
	*(uint32_t*)(v14 + 44) = a1;
	*(uint32_t*)(v14 + 48) = a1;
	*(uint32_t*)(v14 + 52) = a1;
	*(uint32_t*)(v14 + 56) = a1;
	*(uint32_t*)(v14 + 60) = a1;
	*(uint32_t*)(v14 + 64) = a1;
	*(uint16_t*)(v14 + 68) = a1;
	v15 = v3 + v14;
	*(uint16_t*)(v15 + 22) = a1;
	*(uint32_t*)(v15 + 24) = a1;
	*(uint32_t*)(v15 + 28) = a1;
	*(uint32_t*)(v15 + 32) = a1;
	*(uint32_t*)(v15 + 36) = a1;
	*(uint32_t*)(v15 + 40) = a1;
	*(uint32_t*)(v15 + 44) = a1;
	*(uint32_t*)(v15 + 48) = a1;
	*(uint32_t*)(v15 + 52) = a1;
	*(uint32_t*)(v15 + 56) = a1;
	*(uint32_t*)(v15 + 60) = a1;
	*(uint32_t*)(v15 + 64) = a1;
	*(uint32_t*)(v15 + 68) = a1;
	v16 = v3 + v15;
	*(uint32_t*)(v16 + 20) = a1;
	*(uint32_t*)(v16 + 24) = a1;
	*(uint32_t*)(v16 + 28) = a1;
	*(uint32_t*)(v16 + 32) = a1;
	*(uint32_t*)(v16 + 36) = a1;
	*(uint32_t*)(v16 + 40) = a1;
	*(uint32_t*)(v16 + 44) = a1;
	*(uint32_t*)(v16 + 48) = a1;
	*(uint32_t*)(v16 + 52) = a1;
	*(uint32_t*)(v16 + 56) = a1;
	*(uint32_t*)(v16 + 60) = a1;
	*(uint32_t*)(v16 + 64) = a1;
	*(uint32_t*)(v16 + 68) = a1;
	*(uint16_t*)(v16 + 72) = a1;
	v17 = v3 + v16;
	*(uint16_t*)(v17 + 18) = a1;
	*(uint32_t*)(v17 + 20) = a1;
	*(uint32_t*)(v17 + 24) = a1;
	*(uint32_t*)(v17 + 28) = a1;
	*(uint32_t*)(v17 + 32) = a1;
	*(uint32_t*)(v17 + 36) = a1;
	*(uint32_t*)(v17 + 40) = a1;
	*(uint32_t*)(v17 + 44) = a1;
	*(uint32_t*)(v17 + 48) = a1;
	*(uint32_t*)(v17 + 52) = a1;
	*(uint32_t*)(v17 + 56) = a1;
	*(uint32_t*)(v17 + 60) = a1;
	*(uint32_t*)(v17 + 64) = a1;
	*(uint32_t*)(v17 + 68) = a1;
	*(uint32_t*)(v17 + 72) = a1;
	v18 = v3 + v17;
	*(uint32_t*)(v18 + 16) = a1;
	*(uint32_t*)(v18 + 20) = a1;
	*(uint32_t*)(v18 + 24) = a1;
	*(uint32_t*)(v18 + 28) = a1;
	*(uint32_t*)(v18 + 32) = a1;
	*(uint32_t*)(v18 + 36) = a1;
	*(uint32_t*)(v18 + 40) = a1;
	*(uint32_t*)(v18 + 44) = a1;
	*(uint32_t*)(v18 + 48) = a1;
	*(uint32_t*)(v18 + 52) = a1;
	*(uint32_t*)(v18 + 56) = a1;
	*(uint32_t*)(v18 + 60) = a1;
	*(uint32_t*)(v18 + 64) = a1;
	*(uint32_t*)(v18 + 68) = a1;
	*(uint32_t*)(v18 + 72) = a1;
	*(uint16_t*)(v18 + 76) = a1;
	v19 = v3 + v18;
	*(uint16_t*)(v19 + 14) = a1;
	*(uint32_t*)(v19 + 16) = a1;
	*(uint32_t*)(v19 + 20) = a1;
	*(uint32_t*)(v19 + 24) = a1;
	*(uint32_t*)(v19 + 28) = a1;
	*(uint32_t*)(v19 + 32) = a1;
	*(uint32_t*)(v19 + 36) = a1;
	*(uint32_t*)(v19 + 40) = a1;
	*(uint32_t*)(v19 + 44) = a1;
	*(uint32_t*)(v19 + 48) = a1;
	*(uint32_t*)(v19 + 52) = a1;
	*(uint32_t*)(v19 + 56) = a1;
	*(uint32_t*)(v19 + 60) = a1;
	*(uint32_t*)(v19 + 64) = a1;
	*(uint32_t*)(v19 + 68) = a1;
	*(uint32_t*)(v19 + 72) = a1;
	*(uint32_t*)(v19 + 76) = a1;
	v20 = v3 + v19;
	*(uint32_t*)(v20 + 12) = a1;
	*(uint32_t*)(v20 + 16) = a1;
	*(uint32_t*)(v20 + 20) = a1;
	*(uint32_t*)(v20 + 24) = a1;
	*(uint32_t*)(v20 + 28) = a1;
	*(uint32_t*)(v20 + 32) = a1;
	*(uint32_t*)(v20 + 36) = a1;
	*(uint32_t*)(v20 + 40) = a1;
	*(uint32_t*)(v20 + 44) = a1;
	*(uint32_t*)(v20 + 48) = a1;
	*(uint32_t*)(v20 + 52) = a1;
	*(uint32_t*)(v20 + 56) = a1;
	*(uint32_t*)(v20 + 60) = a1;
	*(uint32_t*)(v20 + 64) = a1;
	*(uint32_t*)(v20 + 68) = a1;
	*(uint32_t*)(v20 + 72) = a1;
	*(uint32_t*)(v20 + 76) = a1;
	*(uint16_t*)(v20 + 80) = a1;
	v21 = v3 + v20;
	*(uint16_t*)(v21 + 10) = a1;
	*(uint32_t*)(v21 + 12) = a1;
	*(uint32_t*)(v21 + 16) = a1;
	*(uint32_t*)(v21 + 20) = a1;
	*(uint32_t*)(v21 + 24) = a1;
	*(uint32_t*)(v21 + 28) = a1;
	*(uint32_t*)(v21 + 32) = a1;
	*(uint32_t*)(v21 + 36) = a1;
	*(uint32_t*)(v21 + 40) = a1;
	*(uint32_t*)(v21 + 44) = a1;
	*(uint32_t*)(v21 + 48) = a1;
	*(uint32_t*)(v21 + 52) = a1;
	*(uint32_t*)(v21 + 56) = a1;
	*(uint32_t*)(v21 + 60) = a1;
	*(uint32_t*)(v21 + 64) = a1;
	*(uint32_t*)(v21 + 68) = a1;
	*(uint32_t*)(v21 + 72) = a1;
	*(uint32_t*)(v21 + 76) = a1;
	*(uint32_t*)(v21 + 80) = a1;
	v22 = v3 + v21;
	*(uint32_t*)(v22 + 8) = a1;
	*(uint32_t*)(v22 + 12) = a1;
	*(uint32_t*)(v22 + 16) = a1;
	*(uint32_t*)(v22 + 20) = a1;
	*(uint32_t*)(v22 + 24) = a1;
	*(uint32_t*)(v22 + 28) = a1;
	*(uint32_t*)(v22 + 32) = a1;
	*(uint32_t*)(v22 + 36) = a1;
	*(uint32_t*)(v22 + 40) = a1;
	*(uint32_t*)(v22 + 44) = a1;
	*(uint32_t*)(v22 + 48) = a1;
	*(uint32_t*)(v22 + 52) = a1;
	*(uint32_t*)(v22 + 56) = a1;
	*(uint32_t*)(v22 + 60) = a1;
	*(uint32_t*)(v22 + 64) = a1;
	*(uint32_t*)(v22 + 68) = a1;
	*(uint32_t*)(v22 + 72) = a1;
	*(uint32_t*)(v22 + 76) = a1;
	*(uint32_t*)(v22 + 80) = a1;
	*(uint16_t*)(v22 + 84) = a1;
	v23 = v3 + v22;
	*(uint16_t*)(v23 + 6) = a1;
	*(uint32_t*)(v23 + 8) = a1;
	*(uint32_t*)(v23 + 12) = a1;
	*(uint32_t*)(v23 + 16) = a1;
	*(uint32_t*)(v23 + 20) = a1;
	*(uint32_t*)(v23 + 24) = a1;
	*(uint32_t*)(v23 + 28) = a1;
	*(uint32_t*)(v23 + 32) = a1;
	*(uint32_t*)(v23 + 36) = a1;
	*(uint32_t*)(v23 + 40) = a1;
	*(uint32_t*)(v23 + 44) = a1;
	*(uint32_t*)(v23 + 48) = a1;
	*(uint32_t*)(v23 + 52) = a1;
	*(uint32_t*)(v23 + 56) = a1;
	*(uint32_t*)(v23 + 60) = a1;
	*(uint32_t*)(v23 + 64) = a1;
	*(uint32_t*)(v23 + 68) = a1;
	*(uint32_t*)(v23 + 72) = a1;
	*(uint32_t*)(v23 + 76) = a1;
	*(uint32_t*)(v23 + 80) = a1;
	*(uint32_t*)(v23 + 84) = a1;
	v24 = v3 + v23;
	*(uint32_t*)(v24 + 4) = a1;
	*(uint32_t*)(v24 + 8) = a1;
	*(uint32_t*)(v24 + 12) = a1;
	*(uint32_t*)(v24 + 16) = a1;
	*(uint32_t*)(v24 + 20) = a1;
	*(uint32_t*)(v24 + 24) = a1;
	*(uint32_t*)(v24 + 28) = a1;
	*(uint32_t*)(v24 + 32) = a1;
	*(uint32_t*)(v24 + 36) = a1;
	*(uint32_t*)(v24 + 40) = a1;
	*(uint32_t*)(v24 + 44) = a1;
	*(uint32_t*)(v24 + 48) = a1;
	*(uint32_t*)(v24 + 52) = a1;
	*(uint32_t*)(v24 + 56) = a1;
	*(uint32_t*)(v24 + 60) = a1;
	*(uint32_t*)(v24 + 64) = a1;
	*(uint32_t*)(v24 + 68) = a1;
	*(uint32_t*)(v24 + 72) = a1;
	*(uint32_t*)(v24 + 76) = a1;
	*(uint32_t*)(v24 + 80) = a1;
	*(uint32_t*)(v24 + 84) = a1;
	*(uint16_t*)(v24 + 88) = a1;
	v25 = v3 + v24;
	*(uint16_t*)(v25 + 2) = a1;
	*(uint32_t*)(v25 + 4) = a1;
	*(uint32_t*)(v25 + 8) = a1;
	*(uint32_t*)(v25 + 12) = a1;
	*(uint32_t*)(v25 + 16) = a1;
	*(uint32_t*)(v25 + 20) = a1;
	*(uint32_t*)(v25 + 24) = a1;
	*(uint32_t*)(v25 + 28) = a1;
	*(uint32_t*)(v25 + 32) = a1;
	*(uint32_t*)(v25 + 36) = a1;
	*(uint32_t*)(v25 + 40) = a1;
	*(uint32_t*)(v25 + 44) = a1;
	*(uint32_t*)(v25 + 48) = a1;
	*(uint32_t*)(v25 + 52) = a1;
	*(uint32_t*)(v25 + 56) = a1;
	*(uint32_t*)(v25 + 60) = a1;
	*(uint32_t*)(v25 + 64) = a1;
	*(uint32_t*)(v25 + 68) = a1;
	*(uint32_t*)(v25 + 72) = a1;
	*(uint32_t*)(v25 + 76) = a1;
	*(uint32_t*)(v25 + 80) = a1;
	*(uint32_t*)(v25 + 84) = a1;
	*(uint32_t*)(v25 + 88) = a1;
	v26 = v3 + v25;
	*(uint16_t*)(v26 + 2) = a1;
	*(uint32_t*)(v26 + 4) = a1;
	*(uint32_t*)(v26 + 8) = a1;
	*(uint32_t*)(v26 + 12) = a1;
	*(uint32_t*)(v26 + 16) = a1;
	*(uint32_t*)(v26 + 20) = a1;
	*(uint32_t*)(v26 + 24) = a1;
	*(uint32_t*)(v26 + 28) = a1;
	*(uint32_t*)(v26 + 32) = a1;
	*(uint32_t*)(v26 + 36) = a1;
	*(uint32_t*)(v26 + 40) = a1;
	*(uint32_t*)(v26 + 44) = a1;
	*(uint32_t*)(v26 + 48) = a1;
	*(uint32_t*)(v26 + 52) = a1;
	*(uint32_t*)(v26 + 56) = a1;
	*(uint32_t*)(v26 + 60) = a1;
	*(uint32_t*)(v26 + 64) = a1;
	*(uint32_t*)(v26 + 68) = a1;
	*(uint32_t*)(v26 + 72) = a1;
	*(uint32_t*)(v26 + 76) = a1;
	*(uint32_t*)(v26 + 80) = a1;
	*(uint32_t*)(v26 + 84) = a1;
	*(uint32_t*)(v26 + 88) = a1;
	v27 = v3 + v26;
	*(uint32_t*)(v27 + 4) = a1;
	*(uint32_t*)(v27 + 8) = a1;
	*(uint32_t*)(v27 + 12) = a1;
	*(uint32_t*)(v27 + 16) = a1;
	*(uint32_t*)(v27 + 20) = a1;
	*(uint32_t*)(v27 + 24) = a1;
	*(uint32_t*)(v27 + 28) = a1;
	*(uint32_t*)(v27 + 32) = a1;
	*(uint32_t*)(v27 + 36) = a1;
	*(uint32_t*)(v27 + 40) = a1;
	*(uint32_t*)(v27 + 44) = a1;
	*(uint32_t*)(v27 + 48) = a1;
	*(uint32_t*)(v27 + 52) = a1;
	*(uint32_t*)(v27 + 56) = a1;
	*(uint32_t*)(v27 + 60) = a1;
	*(uint32_t*)(v27 + 64) = a1;
	*(uint32_t*)(v27 + 68) = a1;
	*(uint32_t*)(v27 + 72) = a1;
	*(uint32_t*)(v27 + 76) = a1;
	*(uint32_t*)(v27 + 80) = a1;
	*(uint32_t*)(v27 + 84) = a1;
	*(uint16_t*)(v27 + 88) = a1;
	v28 = v3 + v27;
	*(uint16_t*)(v28 + 6) = a1;
	*(uint32_t*)(v28 + 8) = a1;
	*(uint32_t*)(v28 + 12) = a1;
	*(uint32_t*)(v28 + 16) = a1;
	*(uint32_t*)(v28 + 20) = a1;
	*(uint32_t*)(v28 + 24) = a1;
	*(uint32_t*)(v28 + 28) = a1;
	*(uint32_t*)(v28 + 32) = a1;
	*(uint32_t*)(v28 + 36) = a1;
	*(uint32_t*)(v28 + 40) = a1;
	*(uint32_t*)(v28 + 44) = a1;
	*(uint32_t*)(v28 + 48) = a1;
	*(uint32_t*)(v28 + 52) = a1;
	*(uint32_t*)(v28 + 56) = a1;
	*(uint32_t*)(v28 + 60) = a1;
	*(uint32_t*)(v28 + 64) = a1;
	*(uint32_t*)(v28 + 68) = a1;
	*(uint32_t*)(v28 + 72) = a1;
	*(uint32_t*)(v28 + 76) = a1;
	*(uint32_t*)(v28 + 80) = a1;
	*(uint32_t*)(v28 + 84) = a1;
	v29 = v3 + v28;
	*(uint32_t*)(v29 + 8) = a1;
	*(uint32_t*)(v29 + 12) = a1;
	*(uint32_t*)(v29 + 16) = a1;
	*(uint32_t*)(v29 + 20) = a1;
	*(uint32_t*)(v29 + 24) = a1;
	*(uint32_t*)(v29 + 28) = a1;
	*(uint32_t*)(v29 + 32) = a1;
	*(uint32_t*)(v29 + 36) = a1;
	*(uint32_t*)(v29 + 40) = a1;
	*(uint32_t*)(v29 + 44) = a1;
	*(uint32_t*)(v29 + 48) = a1;
	*(uint32_t*)(v29 + 52) = a1;
	*(uint32_t*)(v29 + 56) = a1;
	*(uint32_t*)(v29 + 60) = a1;
	*(uint32_t*)(v29 + 64) = a1;
	*(uint32_t*)(v29 + 68) = a1;
	*(uint32_t*)(v29 + 72) = a1;
	*(uint32_t*)(v29 + 76) = a1;
	*(uint32_t*)(v29 + 80) = a1;
	*(uint16_t*)(v29 + 84) = a1;
	v30 = v3 + v29;
	*(uint16_t*)(v30 + 10) = a1;
	*(uint32_t*)(v30 + 12) = a1;
	*(uint32_t*)(v30 + 16) = a1;
	*(uint32_t*)(v30 + 20) = a1;
	*(uint32_t*)(v30 + 24) = a1;
	*(uint32_t*)(v30 + 28) = a1;
	*(uint32_t*)(v30 + 32) = a1;
	*(uint32_t*)(v30 + 36) = a1;
	*(uint32_t*)(v30 + 40) = a1;
	*(uint32_t*)(v30 + 44) = a1;
	*(uint32_t*)(v30 + 48) = a1;
	*(uint32_t*)(v30 + 52) = a1;
	*(uint32_t*)(v30 + 56) = a1;
	*(uint32_t*)(v30 + 60) = a1;
	*(uint32_t*)(v30 + 64) = a1;
	*(uint32_t*)(v30 + 68) = a1;
	*(uint32_t*)(v30 + 72) = a1;
	*(uint32_t*)(v30 + 76) = a1;
	*(uint32_t*)(v30 + 80) = a1;
	v31 = v3 + v30;
	*(uint32_t*)(v31 + 12) = a1;
	*(uint32_t*)(v31 + 16) = a1;
	*(uint32_t*)(v31 + 20) = a1;
	*(uint32_t*)(v31 + 24) = a1;
	*(uint32_t*)(v31 + 28) = a1;
	*(uint32_t*)(v31 + 32) = a1;
	*(uint32_t*)(v31 + 36) = a1;
	*(uint32_t*)(v31 + 40) = a1;
	*(uint32_t*)(v31 + 44) = a1;
	*(uint32_t*)(v31 + 48) = a1;
	*(uint32_t*)(v31 + 52) = a1;
	*(uint32_t*)(v31 + 56) = a1;
	*(uint32_t*)(v31 + 60) = a1;
	*(uint32_t*)(v31 + 64) = a1;
	*(uint32_t*)(v31 + 68) = a1;
	*(uint32_t*)(v31 + 72) = a1;
	*(uint32_t*)(v31 + 76) = a1;
	*(uint16_t*)(v31 + 80) = a1;
	v32 = v3 + v31;
	*(uint16_t*)(v32 + 14) = a1;
	*(uint32_t*)(v32 + 16) = a1;
	*(uint32_t*)(v32 + 20) = a1;
	*(uint32_t*)(v32 + 24) = a1;
	*(uint32_t*)(v32 + 28) = a1;
	*(uint32_t*)(v32 + 32) = a1;
	*(uint32_t*)(v32 + 36) = a1;
	*(uint32_t*)(v32 + 40) = a1;
	*(uint32_t*)(v32 + 44) = a1;
	*(uint32_t*)(v32 + 48) = a1;
	*(uint32_t*)(v32 + 52) = a1;
	*(uint32_t*)(v32 + 56) = a1;
	*(uint32_t*)(v32 + 60) = a1;
	*(uint32_t*)(v32 + 64) = a1;
	*(uint32_t*)(v32 + 68) = a1;
	*(uint32_t*)(v32 + 72) = a1;
	*(uint32_t*)(v32 + 76) = a1;
	v33 = v3 + v32;
	*(uint32_t*)(v33 + 16) = a1;
	*(uint32_t*)(v33 + 20) = a1;
	*(uint32_t*)(v33 + 24) = a1;
	*(uint32_t*)(v33 + 28) = a1;
	*(uint32_t*)(v33 + 32) = a1;
	*(uint32_t*)(v33 + 36) = a1;
	*(uint32_t*)(v33 + 40) = a1;
	*(uint32_t*)(v33 + 44) = a1;
	*(uint32_t*)(v33 + 48) = a1;
	*(uint32_t*)(v33 + 52) = a1;
	*(uint32_t*)(v33 + 56) = a1;
	*(uint32_t*)(v33 + 60) = a1;
	*(uint32_t*)(v33 + 64) = a1;
	*(uint32_t*)(v33 + 68) = a1;
	*(uint32_t*)(v33 + 72) = a1;
	*(uint16_t*)(v33 + 76) = a1;
	v34 = v3 + v33;
	*(uint16_t*)(v34 + 18) = a1;
	*(uint32_t*)(v34 + 20) = a1;
	*(uint32_t*)(v34 + 24) = a1;
	*(uint32_t*)(v34 + 28) = a1;
	*(uint32_t*)(v34 + 32) = a1;
	*(uint32_t*)(v34 + 36) = a1;
	*(uint32_t*)(v34 + 40) = a1;
	*(uint32_t*)(v34 + 44) = a1;
	*(uint32_t*)(v34 + 48) = a1;
	*(uint32_t*)(v34 + 52) = a1;
	*(uint32_t*)(v34 + 56) = a1;
	*(uint32_t*)(v34 + 60) = a1;
	*(uint32_t*)(v34 + 64) = a1;
	*(uint32_t*)(v34 + 68) = a1;
	*(uint32_t*)(v34 + 72) = a1;
	v35 = v3 + v34;
	*(uint32_t*)(v35 + 20) = a1;
	*(uint32_t*)(v35 + 24) = a1;
	*(uint32_t*)(v35 + 28) = a1;
	*(uint32_t*)(v35 + 32) = a1;
	*(uint32_t*)(v35 + 36) = a1;
	*(uint32_t*)(v35 + 40) = a1;
	*(uint32_t*)(v35 + 44) = a1;
	*(uint32_t*)(v35 + 48) = a1;
	*(uint32_t*)(v35 + 52) = a1;
	*(uint32_t*)(v35 + 56) = a1;
	*(uint32_t*)(v35 + 60) = a1;
	*(uint32_t*)(v35 + 64) = a1;
	*(uint32_t*)(v35 + 68) = a1;
	*(uint16_t*)(v35 + 72) = a1;
	v36 = v3 + v35;
	*(uint16_t*)(v36 + 22) = a1;
	*(uint32_t*)(v36 + 24) = a1;
	*(uint32_t*)(v36 + 28) = a1;
	*(uint32_t*)(v36 + 32) = a1;
	*(uint32_t*)(v36 + 36) = a1;
	*(uint32_t*)(v36 + 40) = a1;
	*(uint32_t*)(v36 + 44) = a1;
	*(uint32_t*)(v36 + 48) = a1;
	*(uint32_t*)(v36 + 52) = a1;
	*(uint32_t*)(v36 + 56) = a1;
	*(uint32_t*)(v36 + 60) = a1;
	*(uint32_t*)(v36 + 64) = a1;
	*(uint32_t*)(v36 + 68) = a1;
	v37 = v3 + v36;
	*(uint32_t*)(v37 + 24) = a1;
	*(uint32_t*)(v37 + 28) = a1;
	*(uint32_t*)(v37 + 32) = a1;
	*(uint32_t*)(v37 + 36) = a1;
	*(uint32_t*)(v37 + 40) = a1;
	*(uint32_t*)(v37 + 44) = a1;
	*(uint32_t*)(v37 + 48) = a1;
	*(uint32_t*)(v37 + 52) = a1;
	*(uint32_t*)(v37 + 56) = a1;
	*(uint32_t*)(v37 + 60) = a1;
	*(uint32_t*)(v37 + 64) = a1;
	*(uint16_t*)(v37 + 68) = a1;
	v38 = v3 + v37;
	*(uint16_t*)(v38 + 26) = a1;
	*(uint32_t*)(v38 + 28) = a1;
	*(uint32_t*)(v38 + 32) = a1;
	*(uint32_t*)(v38 + 36) = a1;
	*(uint32_t*)(v38 + 40) = a1;
	*(uint32_t*)(v38 + 44) = a1;
	*(uint32_t*)(v38 + 48) = a1;
	*(uint32_t*)(v38 + 52) = a1;
	*(uint32_t*)(v38 + 56) = a1;
	*(uint32_t*)(v38 + 60) = a1;
	*(uint32_t*)(v38 + 64) = a1;
	v39 = v3 + v38;
	*(uint32_t*)(v39 + 28) = a1;
	*(uint32_t*)(v39 + 32) = a1;
	*(uint32_t*)(v39 + 36) = a1;
	*(uint32_t*)(v39 + 40) = a1;
	*(uint32_t*)(v39 + 44) = a1;
	*(uint32_t*)(v39 + 48) = a1;
	*(uint32_t*)(v39 + 52) = a1;
	*(uint32_t*)(v39 + 56) = a1;
	*(uint32_t*)(v39 + 60) = a1;
	*(uint16_t*)(v39 + 64) = a1;
	v40 = v3 + v39;
	*(uint16_t*)(v40 + 30) = a1;
	*(uint32_t*)(v40 + 32) = a1;
	*(uint32_t*)(v40 + 36) = a1;
	*(uint32_t*)(v40 + 40) = a1;
	*(uint32_t*)(v40 + 44) = a1;
	*(uint32_t*)(v40 + 48) = a1;
	*(uint32_t*)(v40 + 52) = a1;
	*(uint32_t*)(v40 + 56) = a1;
	*(uint32_t*)(v40 + 60) = a1;
	v41 = v3 + v40;
	*(uint32_t*)(v41 + 32) = a1;
	*(uint32_t*)(v41 + 36) = a1;
	*(uint32_t*)(v41 + 40) = a1;
	*(uint32_t*)(v41 + 44) = a1;
	*(uint32_t*)(v41 + 48) = a1;
	*(uint32_t*)(v41 + 52) = a1;
	*(uint32_t*)(v41 + 56) = a1;
	*(uint16_t*)(v41 + 60) = a1;
	v42 = v3 + v41;
	*(uint16_t*)(v42 + 34) = a1;
	*(uint32_t*)(v42 + 36) = a1;
	*(uint32_t*)(v42 + 40) = a1;
	*(uint32_t*)(v42 + 44) = a1;
	*(uint32_t*)(v42 + 48) = a1;
	*(uint32_t*)(v42 + 52) = a1;
	*(uint32_t*)(v42 + 56) = a1;
	v43 = v3 + v42;
	*(uint32_t*)(v43 + 36) = a1;
	*(uint32_t*)(v43 + 40) = a1;
	*(uint32_t*)(v43 + 44) = a1;
	*(uint32_t*)(v43 + 48) = a1;
	*(uint32_t*)(v43 + 52) = a1;
	*(uint16_t*)(v43 + 56) = a1;
	v44 = v3 + v43;
	*(uint16_t*)(v44 + 38) = a1;
	*(uint32_t*)(v44 + 40) = a1;
	*(uint32_t*)(v44 + 44) = a1;
	*(uint32_t*)(v44 + 48) = a1;
	*(uint32_t*)(v44 + 52) = a1;
	v45 = v3 + v44;
	*(uint32_t*)(v45 + 40) = a1;
	*(uint32_t*)(v45 + 44) = a1;
	*(uint32_t*)(v45 + 48) = a1;
	*(uint16_t*)(v45 + 52) = a1;
	v46 = v3 + v45;
	*(uint16_t*)(v46 + 42) = a1;
	*(uint32_t*)(v46 + 44) = a1;
	*(uint32_t*)(v46 + 48) = a1;
	v47 = v3 + v46;
	*(uint32_t*)(v47 + 44) = a1;
	*(uint16_t*)(v47 + 48) = a1;
	*(uint16_t*)(v3 + v47 + 46) = a1;
	return result;
}

//----- (00484BA0) --------------------------------------------------------
void sub_484BA0(float a1) {
	if (a1 >= 1.0) {
		*(float*)&dword_587000_154968 = a1;
	} else {
		dword_587000_154968 = 1065353216;
	}
}

//----- (00484BE0) --------------------------------------------------------
uint32_t* nox_xxx_spriteChangeLightColor_484BE0(uint32_t* a1, int a2, int a3, int a4) {
	uint32_t* result; // eax

	result = a1;
	a1[4] = a2;
	*a1 = 2;
	a1[5] = a3;
	a1[6] = a4;
	return result;
}

//----- (00484C00) --------------------------------------------------------
long long sub_484C00(int a1, int a2) {
	long long result; // rax

	result = (long long)((double)a2 * 0.0027777778 * *(double*)&qword_581450_9552 + *(double*)&qword_581450_9544);
	*(uint16_t*)(a1 + 28) = result;
	*(uint32_t*)(a1 + 32) = 0;
	return result;
}

//----- (00484C30) --------------------------------------------------------
long long nox_xxx_spriteChangeLightSize_484C30(int a1, int a2) {
	long long result; // rax

	result = (long long)((double)a2 * 0.0027777778 * *(double*)&qword_581450_9552 + *(double*)&qword_581450_9544);
	*(uint16_t*)(a1 + 30) = result;
	return result;
}

//----- (00484C60) --------------------------------------------------------
int sub_484C60(float a1) {
	double v2; // st7

	if (a1 <= (double)*(float*)&dword_587000_154968) {
		return 0;
	}
	if (a1 <= 31.0) {
		v2 = a1;
	} else {
		v2 = 31.0;
	}
	return nox_double2int(sqrt(((*getMemFloatPtr(0x587000, 154980) + v2) /
									(*getMemFloatPtr(0x587000, 154980) + *(float*)&dword_587000_154968) +
								1.0) *
							   (a1 * a1 / (*getMemFloatPtr(0x587000, 154976) * *getMemFloatPtr(0x587000, 154972)))));
}

//----- (00484CE0) --------------------------------------------------------
int sub_484CE0(int a1, float a2) {
	int result; // eax

	if (a2 > 63.0) {
		a2 = 63.0;
	}
	*(float*)(a1 + 4) = a2;
	result = sub_484C60(a2);
	*(uint32_t*)(a1 + 8) = result;
	return result;
}

//----- (00484D20) --------------------------------------------------------
int sub_484D20(int a1, float a2) {
	int result; // eax

	if (a2 > 63.0) {
		a2 = 63.0;
	}
	*(uint32_t*)(a1 + 12) = (long long)(a2 * *(double*)&qword_581450_9552 + *(double*)&qword_581450_9544);
	result = sub_484C60(a2);
	*(uint32_t*)(a1 + 8) = result;
	return result;
}

//----- (00484D70) --------------------------------------------------------
int nox_xxx_spriteChangeIntensity_484D70_light_intensity(int a1, float a2) {
	int result; // eax

	if (a2 > 63.0) {
		a2 = 63.0;
	}
	*(float*)(a1 + 4) = a2;
	*(uint32_t*)(a1 + 12) = (long long)(a2 * *(double*)&qword_581450_9552 + *(double*)&qword_581450_9544);
	result = sub_484C60(a2);
	*(uint32_t*)(a1 + 8) = result;
	return result;
}

//----- (00484DC0) --------------------------------------------------------
int sub_484DC0(int2* a1, int2* a2, int* a3) {
	int result; // eax
	int v4;     // ecx
	int v5;     // ebx
	int v6;     // ecx
	int v7;     // edi
	int v8;     // ebx
	int* v9;    // edx
	int v10;    // ecx

	result = (a1->field_4 + 0x8000) >> 16;
	*a3 = result;
	v4 = ((a2->field_4 + 0x8000) >> 16) - result + 1;
	a3[1] = v4;
	if (v4 > 0) {
		v5 = a1->field_0;
		result = (a2->field_0 - a1->field_0) / v4;
		v6 = *a3 + v4;
		if ((int)*a3 < 0) {
			a3[1] = v6;
			*a3 = 0;
		}
		if (v6 > 44) {
			a3[1] += 44 - v6;
			v6 = 44;
		}
		v7 = *a3;
		if ((int)*a3 < v6) {
			v8 = v5 + 0x8000;
			v9 = &a3[v7 + 2];
			v10 = v6 - v7;
			do {
				*v9 = v8 >> 16;
				if (v8 >> 16 < 0) {
					*v9 = 0;
				}
				if (*v9 >= 56) {
					*v9 = 55;
				}
				v8 += result;
				++v9;
				--v10;
			} while (v10);
		}
	}
	return result;
}
// 484F48: variable 'v3' is possibly undefined

//----- (004854D0) --------------------------------------------------------
int sub_4854D0(int2* a1, int2* a2, int2* a3, int a4, float a5) {
	int v5;      // edx
	int v6;      // edi
	int2* v7;    // edi
	int2* v8;    // ebx
	int2* v9;    // esi
	int result;  // eax
	int v11;     // ecx
	int v12[46]; // [esp+10h] [ebp-228h]
	int v13[46]; // [esp+C8h] [ebp-170h]
	int v14[46]; // [esp+180h] [ebp-B8h]

	v5 = a1->field_4;
	v6 = a2->field_4;
	if (v5 > v6) {
		v9 = a3;
		if (v6 <= a3->field_4) {
			v8 = a2;
			v7 = a1;
			goto LABEL_9;
		}
		v8 = a3;
	} else {
		v7 = a3;
		if (v5 <= a3->field_4) {
			v8 = a1;
			v9 = a2;
			goto LABEL_9;
		}
		v8 = a3;
	}
	v9 = a1;
	v7 = a2;
LABEL_9:
	sub_484DC0(v8, v9, v14);
	sub_484DC0(v8, v7, v13);
	sub_4855D0((int)v14, (int)v13, a4, a5);
	result = v9->field_4;
	v11 = v7->field_4;
	if (result >= v11) {
		if (result > v11) {
			sub_484DC0(v7, v9, v12);
			result = sub_4855D0((int)v14, (int)v12, a4, a5);
		}
	} else {
		sub_484DC0(v9, v7, v12);
		result = sub_4855D0((int)v12, (int)v13, a4, a5);
	}
	return result;
}

//----- (004855D0) --------------------------------------------------------
int sub_4855D0(int a1, int a2, int a3, float a4) {
	int v4;             // edx
	int v5;             // ecx
	int v6;             // ebp
	int result;         // eax
	double v8;          // st7
	int v9;             // ebx
	double v10;         // st6
	uint32_t* v11;      // edi
	int v12;            // esi
	double v13;         // st5
	double v14;         // st4
	unsigned char* v15; // ebx
	double v16;         // st2
	double v17;         // st2
	int v18;            // [esp+1Ch] [ebp+8h]
	int v19;            // [esp+24h] [ebp+10h]

	v4 = a2;
	v5 = *(uint32_t*)a1;
	v6 = *(uint32_t*)a1 + *(uint32_t*)(a1 + 4);
	if (*(uint32_t*)a1 < *(int*)a2) {
		v5 = *(uint32_t*)a2;
	}
	if (v6 > *(int*)(a2 + 4) + *(uint32_t*)a2) {
		v6 = *(uint32_t*)(a2 + 4) + *(uint32_t*)a2;
	}
	result = v6 - v5;
	if (v6 - v5 > 1) {
		v8 = a4 <= 31.0 ? a4 : 31.0;
		*(float*)&v18 = a4 * a4;
		result = 23 * v5 - *(uint32_t*)(a3 + 4);
		v9 = v5;
		v10 = (double)result;
		v19 = v5;
		if (v5 < v6) {
			v11 = (uint32_t*)(v4 + 4 * v5 + 8);
			result = a1 - v4;
			do {
				v12 = *(uint32_t*)((char*)v11 + result);
				v13 = (double)(int)(23 * v12 - *(uint32_t*)a3);
				if (v12 < *v11) {
					v14 = *getMemFloatPtr(0x587000, 154988) + v8;
					v15 = getMemAt(0x8531A0, +40 * v12 + 5 * v12 + v9);
					do {
						v16 = v14 / ((v13 * v13 + v10 * v10) * *getMemFloatPtr(0x587000, 154984) *
										 *getMemFloatPtr(0x587000, 154972) / *(float*)&v18 +
									 1.0);
						if (v16 > *getMemFloatPtr(0x587000, 154988)) {
							v17 = v16 - *getMemFloatPtr(0x587000, 154988) + (double)*v15;
							if (v17 > 31.0) {
								v17 = 31.0;
							}
							*v15 = (long long)v17;
						}
						++v12;
						v13 = v13 + 23.0;
						v15 += 45;
					} while (v12 < *v11);
					v9 = v19;
					result = a1 - v4;
				}
				v10 = v10 + 23.0;
				++v9;
				++v11;
				v19 = v9;
			} while (v9 < v6);
		}
	}
	return result;
}

//----- (00485AE0) --------------------------------------------------------
unsigned int sub_485AE0(int a1, int a2) {
	unsigned char* v2;   // esi
	int v3;              // ecx
	uint8_t* v4;         // edi
	int v5;              // edx
	int v6;              // eax
	unsigned int result; // eax
	bool v8;             // cc

	v2 = *(unsigned char**)&dword_5d4594_1193184;
	v3 = a1;
	v4 = (uint8_t*)(dword_5d4594_1193180 - 1);
	v5 = dword_5d4594_1193176;
	do {
		v6 = *v2++ << 13;
		++v4;
		result = (unsigned int)(v5 + v6) >> 8;
		v5 += a2;
		v8 = v3-- <= 1;
		*v4 = getMemByte(0x5D4594, 2589804 + result);
	} while (!v8);
	dword_5d4594_1193176 = v5;
	dword_5d4594_1193184 = v2;
	dword_5d4594_1193180 = v4 + 1;
	return result;
}

//----- (00485B30) --------------------------------------------------------
int nox_thing_read_floor_485B30(int a1, char* a2) {
	int v2;            // esi
	uint8_t* v3;       // edi
	int v4;            // eax
	int v5;            // ebp
	const char* v6;    // edx
	int v7;            // ecx
	uint8_t* v9;       // edx
	int v10;           // edi
	int v11;           // ebx
	int* v12;          // eax
	int v13;           // ecx
	char* v14;         // eax
	char v15;          // cl
	int v16;           // [esp-4h] [ebp-40h]
	unsigned char v17; // [esp+10h] [ebp-2Ch]
	int i;             // [esp+10h] [ebp-2Ch]
	unsigned char v19; // [esp+14h] [ebp-28h]
	int v20;           // [esp+14h] [ebp-28h]
	const char* v21;   // [esp+18h] [ebp-24h]
	char v22[32];      // [esp+1Ch] [ebp-20h]
	unsigned char v23; // [esp+40h] [ebp+4h]

	v2 = a1;
	v16 = a1;
	v3 = (uint8_t*)(*(uint32_t*)(a1 + 8) + 4);
	*(uint32_t*)(a1 + 8) = v3;
	LOBYTE(a1) = *v3;
	*(uint32_t*)(v2 + 8) = v3 + 1;
	nox_memfile_read(v22, 1u, (unsigned char)a1, v16);
	v4 = dword_5d4594_251568;
	v5 = 0;
	v22[(unsigned char)a1] = 0;
	if (v4 <= 0) {
	LABEL_5:
		v7 = a1;
	} else {
		v6 = (const char*)getMemAt(0x85B3FC, 32484);
		while (strcmp(v6, v22)) {
			++v5;
			v6 += 60;
			if (v5 >= *(int*)&dword_5d4594_251568) {
				goto LABEL_5;
			}
		}
		v7 = v5;
	}
	if (v5 == dword_5d4594_251568) {
		return 0;
	}
	v9 = (uint8_t*)(*(uint32_t*)(v2 + 8) + 12);
	*(uint32_t*)(v2 + 8) = v9;
	LOBYTE(v21) = *v9;
	*(uint32_t*)(v2 + 8) = v9 + 1;
	v19 = v9[1];
	*(uint32_t*)(v2 + 8) = v9 + 2;
	v17 = v9[2];
	*(uint32_t*)(v2 + 8) = v9 + 4;
	v10 = (unsigned char)v21 * v19 * v17;
	v20 = 15 * v7;
	*getMemU32Ptr(0x85B3FC, 32516 + 60 * v7) = calloc(v10, 4);
	v11 = 0;
	for (i = 0; v11 < v10; *(uint32_t*)(*getMemU32Ptr(0x85B3FC, 32516 + 4 * v20) + 4 * v11 - 4) =
							   nox_xxx_readImgMB_42FAA0(v13, v21, a2)) {
		v12 = *(int**)(v2 + 8);
		v13 = *v12;
		*(uint32_t*)(v2 + 8) = v12 + 1;
		*a2 = getMemByte(0x5D4594, 1193192);
		if (v13 == -1) {
			v14 = *(char**)(v2 + 8);
			v15 = *v14++;
			*(uint32_t*)(v2 + 8) = v14;
			LOBYTE(v21) = v15;
			v23 = *v14;
			*(uint32_t*)(v2 + 8) = v14 + 1;
			nox_memfile_read(a2, 1u, v23, v2);
			v13 = -1;
			a2[v23] = 0;
			v11 = i;
		}
		i = ++v11;
	}
	return 1;
}
// 485CB9: variable 'v21' is possibly undefined
// 485B30: using guessed type char var_20[32];

//----- (00485D40) --------------------------------------------------------
int nox_thing_read_edge_485D40(int a1, char* a2) {
	int v2;            // esi
	uint8_t* v3;       // edi
	int v4;            // eax
	int v5;            // ebp
	const char* v6;    // ebx
	int v7;            // ebx
	int result;        // eax
	uint8_t* v9;       // edi
	char v10;          // cl
	unsigned char v11; // dl
	int v12;           // eax
	unsigned char v13; // di
	int v14;           // edi
	int v15;           // ebx
	int* v16;          // eax
	int v17;           // ecx
	char* v18;         // eax
	char v19;          // cl
	int* v20;          // eax
	int v21;           // ecx
	int v22;           // [esp-4h] [ebp-40h]
	int i;             // [esp+10h] [ebp-2Ch]
	int v24;           // [esp+14h] [ebp-28h]
	unsigned int v25;  // [esp+18h] [ebp-24h]
	char v26[64];      // [esp+1Ch] [ebp-20h]
	unsigned char v27; // [esp+40h] [ebp+4h]

	v2 = a1;
	v22 = a1;
	v3 = (uint8_t*)(*(uint32_t*)(a1 + 8) + 4);
	*(uint32_t*)(a1 + 8) = v3;
	LOBYTE(a1) = *v3;
	*(uint32_t*)(v2 + 8) = v3 + 1;
	nox_memfile_read(v26, 1u, (unsigned char)a1, v22);
	v4 = dword_5d4594_251572;
	v5 = 0;
	v26[(unsigned char)a1] = 0;
	if (v4 <= 0) {
	LABEL_5:
		v7 = a1;
	} else {
		v6 = (const char*)getMemAt(0x85B3FC, 28644);
		while (strcmp(v6, v26)) {
			++v5;
			v6 += 60;
			if (v5 >= *(int*)&dword_5d4594_251572) {
				goto LABEL_5;
			}
		}
		v7 = v5;
	}
	if (v5 == dword_5d4594_251572) {
		return 0;
	}
	v9 = (uint8_t*)(*(uint32_t*)(v2 + 8) + 9);
	*(uint32_t*)(v2 + 8) = v9;
	v25 = *v9;
	*(uint32_t*)(v2 + 8) = v9 + 2;
	v10 = v9[2];
	*(uint32_t*)(v2 + 8) = v9 + 3;
	if (v10 == 1) {
		return 0;
	}
	v11 = v9[3];
	v12 = (int)(v9 + 4);
	*(uint32_t*)(v2 + 8) = v9 + 4;
	v13 = v9[4];
	*(uint32_t*)(v2 + 8) = v12 + 1;
	v14 = 2 * v25 * (v11 + v13);
	result = (int)calloc(v14, 5);
	memset((int*)result, 0, 5 * v14);
	v24 = 15 * v7;
	*getMemU32Ptr(0x85B3FC, 28676 + 60 * v7) = result;
	if (result) {
		v15 = 0;
		for (i = 0; v15 < v14; *(uint32_t*)(*getMemU32Ptr(0x85B3FC, 28676 + 4 * v24) + 4 * v15 - 4) =
								   nox_xxx_readImgMB_42FAA0(v17, v25, a2)) {
			v16 = *(int**)(v2 + 8);
			v17 = *v16;
			*(uint32_t*)(v2 + 8) = v16 + 1;
			*a2 = getMemByte(0x5D4594, 1193196);
			if (v17 == -1) {
				v18 = *(char**)(v2 + 8);
				v19 = *v18++;
				*(uint32_t*)(v2 + 8) = v18;
				LOBYTE(v25) = v19;
				v27 = *v18;
				*(uint32_t*)(v2 + 8) = v18 + 1;
				nox_memfile_read(a2, 1u, v27, v2);
				v17 = -1;
				a2[v27] = 0;
				v15 = i;
			}
			i = ++v15;
		}
		v20 = *(int**)(v2 + 8);
		v21 = *v20;
		*(uint32_t*)(v2 + 8) = v20 + 1;
		result = v21 == 1162757152;
	}
	return result;
}
// 485EEB: variable 'v25' is possibly undefined
// 485D40: using guessed type char var_20[32];

//----- (00485F80) --------------------------------------------------------
void nox_xxx_initSight_485F80() {
	int v0; // esi
	int v1; // eax
	int v2; // edx
	int i;  // ecx
	int v4; // edx
	int v5; // edi
	int v6; // ecx
	int v7; // ebx

	v0 = 0;
	v1 = 0;
	v2 = 1;
	for (i = 23; i > 0; --i) {
		*getMemU32Ptr(0x973CE0, +4 * v1) = v0;
		*getMemU32Ptr(0x973CE0, 192 + 4 * v1) = i;
		*getMemU32Ptr(0x973CE0, 384 + 4 * v1) = v2;
		v0 += v2;
		++v1;
		v2 += 2;
	}
	if (v1 < 46) {
		v4 = 91 - 2 * v1;
		v5 = v1 - 22;
		v6 = 4 * v1;
		v7 = 46 - v1;
		do {
			*getMemU32Ptr(0x973CE0, +v6) = v0;
			*getMemU32Ptr(0x973CE0, 192 + v6) = v5;
			*getMemU32Ptr(0x973CE0, 384 + v6) = v4;
			v0 += v4;
			++v5;
			v4 -= 2;
			v6 += 4;
			--v7;
		} while (v7);
	}

	unsigned int* v8 = getMemAt(0x8529A0, 0);
	for (int j = 0; j < 253; j++) {
		v8[j] = ((j - 253) * 256) / 22;
	}
	*getMemU32Ptr(0x8529A0, 1016) = 0;
	unsigned int* v12 = getMemAt(0x8529A0, 1020);
	for (int k = 0; k < 256; k++) {
		v12[k] = (k * 256) / 22;
	}
}

//----- (00486060) --------------------------------------------------------
int nox_xxx_tile_486060() {
	int result; // eax

	dword_5d4594_1193188 = 1;
	result = 45 * dword_5d4594_3798804;
	*getMemU32Ptr(0x973CE0, 376) = 45 * dword_5d4594_3798804 + (46 << getMemByte(0x973F18, 7696));
	return result;
}

#ifndef NOX_CGO
//----- (00486110) --------------------------------------------------------
void nox_free_pixbuffers_486110() {
	if (!*getMemU32Ptr(0x5D4594, 1193200)) {
		if (nox_pixbuffer_3798780) {
			free(nox_pixbuffer_3798780);
			nox_pixbuffer_3798780 = 0;
		}
		if (nox_pixbuffer_3798788) {
			free(nox_pixbuffer_3798788);
			nox_pixbuffer_3798788 = 0;
		}
	}
	if (nox_pixbuffer_rows_3798784) {
		free(nox_pixbuffer_rows_3798784);
		nox_pixbuffer_rows_3798784 = 0;
	}
	if (nox_pixbuffer_rows_3798776) {
		free(nox_pixbuffer_rows_3798776);
		nox_pixbuffer_rows_3798776 = 0;
	}
}

//----- (00486180) --------------------------------------------------------
int sub_486180(void* a1) {
	int result; // eax

	nox_free_pixbuffers_486110();
	nox_pixbuffer_3798780 = a1;
	result = nox_video_initPixbufferRows_486230();
	*getMemU32Ptr(0x5D4594, 1193200) = 1;
	return result;
}

//----- (004861A0) --------------------------------------------------------
void nox_pixbuffer_swap_4861A0() {
	uint8_t* tmp = nox_pixbuffer_3798788;
	nox_pixbuffer_3798788 = nox_pixbuffer_3798780;
	nox_pixbuffer_3798780 = tmp;

	uint8_t** tmp2 = nox_pixbuffer_rows_3798784;
	nox_pixbuffer_rows_3798784 = nox_pixbuffer_rows_3798776;
	nox_pixbuffer_rows_3798776 = tmp2;
}

//----- (004861D0) --------------------------------------------------------
int nox_video_initPixbufferData_4861D0() {
	if (*getMemU32Ptr(0x5D4594, 1193200)) {
		return 1;
	}

	nox_pixbuffer_3798780 = calloc(nox_backbuffer_pitch_3801808 * nox_backbuffer_height, 1u);
	if (!nox_pixbuffer_3798780) {
		return 0;
	}

	if (!(nox_video_renderTargetFlags & 0x40)) {
		return 1;
	}

	nox_pixbuffer_3798788 = calloc(nox_backbuffer_pitch_3801808 * nox_backbuffer_height, 1u);
	if (!nox_pixbuffer_3798788) {
		return 0;
	}
	return 1;
}

//----- (00486230) --------------------------------------------------------
int nox_video_initPixbufferRows_486230() {
	nox_pixbuffer_rows_3798784 = calloc(nox_backbuffer_height, sizeof(uint8_t*));
	if (!nox_pixbuffer_rows_3798784) {
		return 0;
	}

	if (nox_backbuffer_height > 0) {
		uint8_t** rows = nox_pixbuffer_rows_3798784;
		uint8_t* pix = nox_pixbuffer_3798780;
		for (int y = 0; y < nox_backbuffer_height; y++) {
			rows[y] = &pix[y * nox_backbuffer_pitch_3801808];
		}
	}

	if (!(nox_video_renderTargetFlags & 0x40)) {
		return 1;
	}

	nox_pixbuffer_rows_3798776 = calloc(nox_backbuffer_height, 4);
	if (!nox_pixbuffer_rows_3798776) {
		return 0;
	}

	if (nox_backbuffer_height > 0) {
		uint8_t** rows = nox_pixbuffer_rows_3798776;
		uint8_t* pix = nox_pixbuffer_3798788;
		for (int y = 0; y < nox_backbuffer_height; y++) {
			rows[y] = &pix[y * nox_backbuffer_pitch_3801808];
		}
	}
	return 1;
}
#endif // NOX_CGO

//----- (004862E0) --------------------------------------------------------
int sub_4862E0(int a3, int a4) {
	*(uint32_t*)a3 = 0;
	*(uint64_t*)(a3 + 24) = nox_platform_get_ticks();
	sub_486380((uint32_t*)a3, 0x3E8u, 0, 0x4000);
	sub_486320((uint32_t*)a3, a4);
	return sub_4863B0((unsigned int*)a3);
}

//----- (00486320) --------------------------------------------------------
uint32_t* sub_486320(uint32_t* a1, int a2) {
	uint32_t* result; // eax

	result = a1;
	*a1 |= 1u;
	a1[2] = a2 << 16;
	return result;
}

//----- (00486340) --------------------------------------------------------
uint32_t* sub_486340(uint32_t* a1) {
	uint32_t* result; // eax

	result = a1;
	*a1 |= 1u;
	return result;
}

//----- (00486350) --------------------------------------------------------
int sub_486350(void* a1p, int a2) {
	int a1 = a1p;
	long long v2; // rax
	int v3;       // ecx

	LODWORD(v2) = *(uint32_t*)(a1 + 8);
	v3 = *(uint32_t*)(a1 + 4);
	*(uint32_t*)a1 &= 0xFFFFFFFE;
	if ((uint32_t)v2 == v3) {
		v2 = nox_platform_get_ticks();
		*(uint64_t*)(a1 + 24) = v2;
	}
	*(uint32_t*)(a1 + 8) = a2 << 16;
	return v2;
}

//----- (00486380) --------------------------------------------------------
int sub_486380(uint32_t* a1, unsigned int a2, int a3, int a4) {
	int result; // eax

	a1[4] = a2;
	a1[3] = (a4 << 16) / a2;
	result = a3;
	a1[5] = a3;
	return result;
}

//----- (004863B0) --------------------------------------------------------
int sub_4863B0(unsigned int* a2) {
	signed int v1;          // ebx
	unsigned int v2;        // eax
	int result;             // eax
	long long v4;           // rax
	unsigned int v5;        // edi
	unsigned int v6;        // ebp
	unsigned int v7;        // ecx
	unsigned int v8;        // ecx
	unsigned int v9;        // edi
	unsigned long long v10; // kr00_8
	signed int v11;         // eax
	unsigned int v12;       // eax
	unsigned int v13;       // ecx
	unsigned int v14;       // eax
	unsigned int v15;       // ecx

	v1 = a2[2] - a2[1];
	if (!v1) {
		return 0;
	}
	if (*(uint8_t*)a2 & 1) {
		a2[1] = a2[2];
		v2 = *a2;
		LOBYTE(v2) = *a2 | 2;
		*a2 = v2;
		result = 1;
	} else {
		v4 = nox_platform_get_ticks();
		v5 = a2[6];
		v6 = a2[7];
		v7 = v4;
		a2[6] = v4;
		LODWORD(v4) = a2[5];
		a2[7] = HIDWORD(v4);
		v10 = __PAIR64__(HIDWORD(v4), v7) - __PAIR64__(v6, v5);
		v9 = (__PAIR64__(HIDWORD(v4), v7) - __PAIR64__(v6, v5)) >> 32;
		v8 = v10;
		if (__PAIR64__(v9, v10) > __PAIR64__(v4, a2[4])) {
			v8 = a2[4];
		}
		v11 = v8 * a2[3];
		if (v1 >= 0) {
			if (v11 <= v1) {
				v15 = v11 + a2[1];
				v14 = *a2;
				LOBYTE(v14) = *a2 | 2;
				a2[1] = v15;
			} else {
				a2[1] += v1;
				v14 = *a2;
				LOBYTE(v14) = *a2 | 2;
			}
			*a2 = v14;
			result = 1;
		} else {
			if (v11 <= -v1) {
				v13 = a2[1] - v11;
				v12 = *a2;
				LOBYTE(v12) = *a2 | 2;
				a2[1] = v13;
			} else {
				a2[1] += v1;
				v12 = *a2;
				LOBYTE(v12) = *a2 | 2;
			}
			*a2 = v12;
			result = 1;
		}
	}
	return result;
}

//----- (004864A0) --------------------------------------------------------
uint32_t* sub_4864A0(uint32_t* a3) {
	sub_4862E0((int)a3, 0x4000);
	sub_4862E0((int)(a3 + 8), 100);
	sub_4862E0((int)(a3 + 16), 0x2000);
	sub_486380(a3 + 8, 0x3E8u, 0, 10);
	sub_486380(a3, 0x3E8u, 0, 0x4000);
	sub_486380(a3 + 16, 0x3E8u, 0, 0x4000);
	return sub_486320(a3, 0x4000);
}

//----- (00486520) --------------------------------------------------------
int sub_486520(unsigned int* a2) {
	sub_4863B0(a2);
	sub_4863B0(a2 + 8);
	return sub_4863B0(a2 + 16);
}

//----- (00486550) --------------------------------------------------------
int sub_486550(uint8_t* a1) { return *a1 & 2 || a1[32] & 2 || a1[64] & 2; }

//----- (00486570) --------------------------------------------------------
int sub_486570(unsigned int* a1, uint32_t* a2) {
	int v2; // eax

	sub_486320(a1, ((a2[1] >> 16) * (a1[1] >> 16)) >> 14);
	sub_4863B0(a1);
	sub_486320(a1 + 8, (int)((a2[9] >> 16) * (a1[9] >> 16)) / 100);
	sub_4863B0(a1 + 8);
	if (a2[17] >> 16 != 0x2000) {
		v2 = (a1[17] >> 16) + (a2[17] >> 16) - 0x2000;
		if (v2 >= 0) {
			if ((unsigned int)v2 > 0x4000) {
				v2 = 0x4000;
			}
		} else {
			v2 = 0;
		}
		sub_486320(a1 + 16, v2);
	}
	return sub_4863B0(a1 + 16);
}

//----- (00486620) --------------------------------------------------------
uint32_t* sub_486620(uint32_t* a1) {
	uint32_t* result; // eax

	result = a1;
	*a1 &= 0xFFFFFFFD;
	a1[16] &= 0xFFFFFFFD;
	a1[8] &= 0xFFFFFFFD;
	return result;
}

//----- (00486640) --------------------------------------------------------
int sub_486640(void* a1p, int a2) {
	int a1 = a1p;
	return a2 * (*(uint32_t*)(a1 + 36) >> 16) / 100;
}

//----- (00486670) --------------------------------------------------------
int sub_486670(int a1, int a2) {
	int result; // eax

	result = a2;
	if (a2) {
		result = a2 - 1;
		if (a2 == 1) {
			*getMemU32Ptr(0x587000, 155052) = a1;
		} else {
			result = a2 - 2;
			if (a2 == 2) {
				result = a1;
				*getMemU32Ptr(0x587000, 155056) = a1;
			}
		}
	} else {
		*getMemU32Ptr(0x587000, 155048) = a1;
	}
	return result;
}

//----- (004866A0) --------------------------------------------------------
int sub_4866A0(int a1) {
	switch (a1) {
	case 0:
		return *getMemU32Ptr(0x587000, 155048);
	case 1:
		return *getMemU32Ptr(0x587000, 155052);
	case 2:
		return *getMemU32Ptr(0x587000, 155056);
	}
	return 0x4000;
}

//----- (004866D0) --------------------------------------------------------
int sub_4866D0(uint32_t* a1, int a2) { return *a1 + 36 * a2; }

//----- (004866F0) --------------------------------------------------------
char* sub_4866F0(const char* a1, const char* a2) {
	char* v2;         // ebp
	char* v3;         // eax
	unsigned char v4; // al
	char* v5;         // edi
	FILE* v6;         // ebx
	char* v7;         // eax
	char* v8;         // edi
	unsigned char v9; // cl
	FILE* v10;        // eax
	void* v11;        // edi
	int v12;          // eax
	int v13;          // edi
	int v14;          // esi
	HANDLE v15;       // esi
	char v17[12];
	char v20[260];                         // [esp+1Ch] [ebp-244h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+120h] [ebp-140h]

	v2 = (char*)calloc(1, 0x120u);
	memset(v2, 0, 0x120u);
	strcpy(v20, a1);
	v3 = strrchr(v20, 46);
	if (v3) {
		*v3 = 0;
	}
	v4 = getMemByte(0x587000, 155064);
	v5 = &v20[strlen(v20)];
	*(uint32_t*)v5 = *getMemU32Ptr(0x587000, 155060);
	v5[4] = v4;
	v6 = nox_fs_open(v20);
	if (!v6) {
		goto LABEL_27;
	}
	v7 = strrchr(v20, 46);
	if (v7) {
		*v7 = 0;
	}
	v8 = &v20[strlen(v20) + 1];
	v9 = getMemByte(0x587000, 155076);
	*(uint32_t*)--v8 = *getMemU32Ptr(0x587000, 155072);
	v8[4] = v9;
	v10 = nox_fs_open(v20);
	*((uint32_t*)v2 + 67) = v10;
	if (!v10 || nox_binfile_fread_raw_40ADD0(v17, 0xCu, 1u, v6) != 1) {
		goto LABEL_27;
	}
	*((uint32_t*)v2 + 1) = *(uint32_t*)&v17[8];
	if (*(int*)&v17[8] <= 0) {
		goto LABEL_14;
	}
	v11 = calloc(*(uint32_t*)&v17[8], 36);
	v12 = *((uint32_t*)v2 + 1);
	*(uint32_t*)v2 = v11;
	memset(v11, 0, 4 * ((unsigned int)(36 * v12) >> 2));
	if (*(uint32_t*)&v17[4] != 1) {
		if (nox_binfile_fread_raw_40ADD0(*(char**)v2, 36 * *((uint32_t*)v2 + 1), 1u, v6) == 1) {
			goto LABEL_14;
		}
	LABEL_27:
		if (v2) {
			sub_4869C0(v2);
		}
		if (v6) {
			nox_fs_close(v6);
		}
		return 0;
	}
	v13 = 0;
	if (*((uint32_t*)v2 + 1) > 0) {
		v14 = 0;
		while (nox_binfile_fread_raw_40ADD0((char*)(v14 + *(uint32_t*)v2), 0x20u, 1u, v6) == 1) {
			++v13;
			*(uint32_t*)(*(uint32_t*)v2 + v14 + 32) = 0;
			v14 += 36;
			if (v13 >= *((uint32_t*)v2 + 1)) {
				goto LABEL_14;
			}
		}
		goto LABEL_27;
	}
LABEL_14:
	nox_fs_close(v6);
	qsort(*(void**)v2, *((uint32_t*)v2 + 1), 0x24u, (int (*)(const void*, const void*))_strcmpi);
	*((uint32_t*)v2 + 69) = 0;
	if (a2) {
		strcpy(v2 + 8, a2);
		if (v2[strlen(v2 + 8) + 8] == 92) {
			v2[strlen(v2 + 8) + 8] = 0;
		}
		v15 = FindFirstFileA(v2 + 8, &FindFileData);
		if (v15 != (HANDLE)-1) {
			if (FindFileData.dwFileAttributes & 0x10) {
			LABEL_21:
				*((uint32_t*)v2 + 69) = 1;
			} else {
				while (FindNextFileA(v15, &FindFileData)) {
					if (FindFileData.dwFileAttributes & 0x10) {
						goto LABEL_21;
					}
				}
			}
			FindClose(v15);
		}
		if (v2[strlen(v2 + 8) + 8] != 92) {
			*(uint16_t*)&v2[strlen(v2 + 8) + 8] = *getMemU16Ptr(0x587000, 155084);
		}
	}
	return v2;
}
// 4866F0: using guessed type char var_244[260];

//----- (004869C0) --------------------------------------------------------
void sub_4869C0(void* lpMem) {
	if (*((uint32_t*)lpMem + 67)) {
		nox_fs_close(*((FILE**)lpMem + 67));
	}
	if (*((uint32_t*)lpMem + 68)) {
		nox_fs_close(*((FILE**)lpMem + 68));
	}
	if (*(uint32_t*)lpMem) {
		free(*(void**)lpMem);
	}
	free(lpMem);
}

//----- (00486A10) --------------------------------------------------------
unsigned int sub_486A10(int a1, void* a2) {
	void* v2;            // eax
	unsigned int result; // eax

	v2 = bsearch(a2, *(const void**)a1, *(uint32_t*)(a1 + 4), 0x24u, (int (*)(const void*, const void*))_strcmpi);
	if (v2) {
		result = ((unsigned int)v2 - *(uint32_t*)a1) / 0x24;
	} else {
		result = -1;
	}
	return result;
}

//----- (00486A50) --------------------------------------------------------
char* sub_486A50(uint32_t* a1, int a2) {
	char* result; // eax

	if (a2 < 0 || a2 >= a1[1]) {
		result = (char*)getMemAt(0x587000, 155088);
	} else {
		result = (char*)sub_4866D0(a1, a2);
	}
	return result;
}

//----- (00486A80) --------------------------------------------------------
int sub_486A80(uint32_t* a1, int a2) {
	int result; // eax

	if (a2 < 0 || a2 >= a1[1]) {
		result = 0;
	} else {
		result = *(uint32_t*)(*a1 + 36 * a2 + 20);
	}
	return result;
}

//----- (00486AA0) --------------------------------------------------------
int sub_486AA0(uint32_t* a1, int a2, uint32_t* a3) {
	uint32_t* v3; // eax
	int result;   // eax

	v3 = (uint32_t*)sub_4866D0(a1, a2);
	*a3 = 4;
	a3[2] = v3[6];
	a3[3] = ((v3[7] & 1) != 0) + 1;
	a3[6] = v3[8];
	if (v3[7] & 8) {
		result = 2;
		a3[1] = 2;
		a3[4] = 2;
	} else {
		a3[1] = 0;
		result = ((v3[7] & 4) != 0) + 1;
		a3[4] = result;
	}
	return result;
}

//----- (00486B10) --------------------------------------------------------
int sub_486B10(uint32_t* a1, int a2, uint32_t* a3) {
	int result; // eax
	int v4;     // edx

	result = sub_4866D0(a1, a2);
	v4 = a3[2];
	*(uint32_t*)(result + 28) = 0;
	*(uint32_t*)(result + 24) = v4;
	if (a3[3] == 2) {
		*(uint32_t*)(result + 28) = 1;
	}
	if (a3[4] == 2) {
		*(uint32_t*)(result + 28) |= 4u;
	}
	return result;
}

//----- (00486B60) --------------------------------------------------------
int sub_486B60(int a1, int a2) {
	int v2;       // ebp
	FILE* v3;     // eax
	FILE* v6;     // eax
	FILE* v7;     // esi
	int v8;       // edi
	int v9;       // eax
	int v10;      // ecx
	int v12;      // [esp+10h] [ebp-12Ch]
	char v13[8];  // [esp+14h] [ebp-128h]
	char v14[16]; // [esp+1Ch] [ebp-120h]
	int v15[12];  // [esp+2Ch] [ebp-110h]

	v12 = 1;
	v2 = sub_4866D0((uint32_t*)a1, a2);
	sub_486E00(a1);
	v3 = *(FILE**)(a1 + 268);
	*(uint32_t*)(a1 + 280) = v3;
	*(uint32_t*)(a1 + 284) = *(uint32_t*)(v2 + 20);
	if (nox_fs_fseek_start(v3, *(uint32_t*)(v2 + 16))) {
		v12 = 0;
	}
	if (!*(uint32_t*)(v2 + 20)) {
		v12 = 0;
	}
	if (!*(uint32_t*)(a1 + 276)) {
		return v12;
	}
	strcpy((char*)&v15[3], (const char*)(a1 + 8));
	strcat((char*)&v15[3], (const char*)v2);
	strcat((char*)&v15[3], ".wav");
	v6 = nox_fs_open((const char*)&v15[3]);
	v7 = v6;
	v8 = 0;
	*(uint32_t*)(a1 + 272) = v6;
	if (!v6) {
		return v12;
	}
	if (nox_binfile_fread_raw_40ADD0((char*)v15, 0xCu, 1u, v6) != 1 || v15[0] != 1179011410 || v15[2] != 1163280727) {
		printf("error: '%s' is bad - cannot read\n", &v15[3]);
		if (*(uint32_t*)(a1 + 272)) {
			nox_fs_close(*(FILE**)(a1 + 272));
			*(uint32_t*)(a1 + 272) = 0;
		}
		return v12;
	}
	if (nox_binfile_fread_raw_40ADD0(v13, 8u, 1u, v7) != 1) {
		goto LABEL_18;
	}
	while (1) {
		if (*(uint32_t*)v13 == 544501094) {
			nox_binfile_fread_raw_40ADD0(v14, 0x10u, 1u, v7);
			nox_fs_fseek_cur(v7, *(uint32_t*)&v13[4] - 16);
			goto LABEL_15;
		}
		if (*(uint32_t*)v13 == 1635017060) {
			break;
		}
		nox_fs_fseek_cur(v7, *(int*)&v13[4]);
	LABEL_15:
		if (nox_binfile_fread_raw_40ADD0(v13, 8u, 1u, v7) != 1) {
			goto LABEL_18;
		}
	}
	v8 = *(uint32_t*)&v13[4];
LABEL_18:
	*(uint32_t*)(v2 + 28) = 2;
	if (*(unsigned short*)&v14[12] / (int)*(unsigned short*)&v14[2] == 2) {
		*(uint32_t*)(v2 + 28) = 6;
	}
	if (*(uint16_t*)&v14[2] == 2) {
		v9 = *(uint32_t*)(v2 + 28);
		LOBYTE(v9) = v9 | 1;
		*(uint32_t*)(v2 + 28) = v9;
	}
	*(uint32_t*)(v2 + 24) = *(uint32_t*)&v14[4];
	v10 = *(uint32_t*)(a1 + 272);
	*(uint32_t*)(a1 + 284) = v8;
	*(uint32_t*)(a1 + 280) = v10;
	return 1;
}

//----- (00486DB0) --------------------------------------------------------
signed int sub_486DB0(int a1, char* a2, signed int a3) {
	signed int result; // eax
	signed int v4;     // eax

	if (!*(uint32_t*)(a1 + 280)) {
		return 0;
	}
	v4 = a3;
	if (a3 > *(int*)(a1 + 284)) {
		v4 = *(uint32_t*)(a1 + 284);
	}
	if (v4 <= 0 || (result = nox_binfile_fread_raw_40ADD0(a2, 1u, v4, *(FILE**)(a1 + 280)), result < 0)) {
		result = 0;
	}
	*(uint32_t*)(a1 + 284) -= result;
	return result;
}

//----- (00486E00) --------------------------------------------------------
FILE* sub_486E00(int a1) {
	FILE* result; // eax

	result = *(FILE**)(a1 + 272);
	*(uint32_t*)(a1 + 280) = 0;
	if (result) {
		nox_fs_close(result);
		result = 0;
		*(uint32_t*)(a1 + 272) = 0;
	}
	return result;
}

//----- (00486E30) --------------------------------------------------------
int sub_486E30(int a1, uint32_t* a2) {
	int result; // eax

	a2[33] = a1;
	++*(uint32_t*)(a1 + 192);
	++*(uint32_t*)(a1 + 212);
	nox_common_list_append_4258E0(a1 + 200, a2);
	result = *(uint32_t*)(a1 + 212) - 1;
	*(uint32_t*)(a1 + 212) = result;
	if (result < 0) {
		*(uint32_t*)(a1 + 212) = 0;
	}
	return result;
}

//----- (00486E90) --------------------------------------------------------
int sub_486E90(int a1) {
	int v1;     // esi
	int result; // eax

	v1 = *(uint32_t*)(a1 + 132);
	sub_425920((uint32_t**)a1);
	--*(uint32_t*)(v1 + 192);
	++*(uint32_t*)(v1 + 212);
	sub_425920((uint32_t**)a1);
	result = *(uint32_t*)(v1 + 212) - 1;
	*(uint32_t*)(v1 + 212) = result;
	if (result < 0) {
		*(uint32_t*)(v1 + 212) = 0;
	}
	return result;
}

//----- (00486EF0) --------------------------------------------------------
void* sub_486EF0() {
	void* result; // eax
	int* v1;      // esi
	int i;        // edi

	result = *(void**)&dword_5d4594_1193336;
	if (dword_5d4594_1193336) {
		result = *(void**)&dword_587000_155144;
		if (!*(uint32_t*)((uint32_t)dword_587000_155144 + 24)) {
			v1 = *(int**)((uint32_t)dword_587000_155144 + 12);
			for (i = (uint32_t)dword_587000_155144 + 12; v1 != (int*)i; v1 = (int*)*v1) {
				if (!(v1[3] & 2)) {
					result = (void*)((int (*)(int*))v1[54])(v1);
				}
			}
		}
	}
	return result;
}

//----- (00486F30) --------------------------------------------------------
int sub_486F30() {
	nox_common_list_clear_425760(*(uint32_t**)&dword_587000_155144);
	nox_common_list_clear_425760((uint32_t*)((uint32_t)dword_587000_155144 + 12));
	*(uint32_t*)((uint32_t)dword_587000_155144 + 24) = 0;
	*getMemU32Ptr(0x5D4594, 1193340) = (uint32_t)dword_587000_155144 + 32;
	sub_4864A0((uint32_t*)((uint32_t)dword_587000_155144 + 32));
	dword_5d4594_1193336 = 1;
	return 0;
}

//----- (00486FA0) --------------------------------------------------------
uint32_t* sub_486FA0(int a1) {
	uint32_t* result; // eax
	uint32_t* v2;     // edi
	int v3;           // eax

	result = sub_486FE0(a1);
	v2 = result;
	if (result) {
		v3 = *(uint32_t*)(a1 + 12);
		LOBYTE(v3) = v3 | 1;
		*(uint32_t*)(a1 + 12) = v3;
		sub_487050(v2);
		if (*(uint8_t*)(a1 + 8) & 2) {
			*getMemU32Ptr(0x5D4594, 1193332) = 1;
		}
		result = v2;
	}
	return result;
}

//----- (00486FE0) --------------------------------------------------------
uint32_t* sub_486FE0(int a1) {
	uint32_t* v1; // esi

	v1 = calloc(1, 0x58u);
	memset(v1, 0, 0x58u);
	sub_425770(v1);
	v1[4] = 0;
	v1[3] = a1;
	if (!(*(int (**)(uint32_t*))(a1 + 20))(v1)) {
		return v1;
	}
	if (v1) {
		sub_487030(v1);
	}
	return 0;
}

//----- (00487030) --------------------------------------------------------
void sub_487030(void* lpMem) {
	(*(void (**)(void*))(*((uint32_t*)lpMem + 3) + 24))(lpMem);
	*(uint32_t*)(*((uint32_t*)lpMem + 3) + 12) &= 0xFFFFFFFE;
	free(lpMem);
}

//----- (00487050) --------------------------------------------------------
void sub_487050(uint32_t* a1) { nox_common_list_append_4258E0(*(int*)&dword_587000_155144, a1); }

//----- (00487070) --------------------------------------------------------
void sub_487070(void* lpMem) {
	sub_487090((uint32_t**)lpMem);
	sub_487030(lpMem);
	*getMemU32Ptr(0x5D4594, 1193332) = 0;
}

//----- (00487090) --------------------------------------------------------
uint32_t** sub_487090(uint32_t** a1) { return sub_425920(a1); }

//----- (004870A0) --------------------------------------------------------
void sub_4870A0() {
	int* v1; // edi
	int* v2; // esi
	int* v3; // [esp+4h] [ebp-4h]

	v1 = sub_4870E0((int*)&v3);
	if (v1) {
		do {
			v2 = sub_487100(&v3);
			sub_487070(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (004870E0) --------------------------------------------------------
int* sub_4870E0(int* a1) {
	int* result; // eax

	result = nox_common_list_getFirstSafe_425890(*(int**)&dword_587000_155144);
	*a1 = (int)result;
	return result;
}

//----- (00487100) --------------------------------------------------------
int* sub_487100(int** a1) {
	if (*a1) {
		*a1 = nox_common_list_getNextSafe_4258A0(*a1);
	}
	return *a1;
}

//----- (00487120) --------------------------------------------------------
int sub_487120() {
	int v0;  // esi
	int* i;  // eax
	int* v3; // [esp+4h] [ebp-4h]

	v0 = 0;
	for (i = sub_4870E0((int*)&v3); i; i = sub_487100(&v3)) {
		v0 += i[5];
	}
	return v0;
}

//----- (00487150) --------------------------------------------------------
uint32_t* sub_487150(int a1, const void* a2) {
	int v2;       // edi
	uint32_t* v3; // esi
	uint32_t* v4; // eax
	int v6;       // [esp+8h] [ebp-4h]

	v2 = a1;
	if (a1 == -1) {
		v2 = 0;
	}
	sub_487360(v2, (int**)&a1, &v6);
	if (!a1) {
		return 0;
	}
	v3 = *(uint32_t**)(a1 + 4 * v6 + 24);
	if (!v3) {
		v4 = sub_4871C0(a1, v6, a2);
		v3 = v4;
		if (!v4) {
			return 0;
		}
		v4[47] = v2;
		sub_487310(v4);
	}
	++v3[4];
	return v3;
}

//----- (004871C0) --------------------------------------------------------
uint32_t* sub_4871C0(int a1, int a2, const void* a3) {
	int v3;       // ebp
	uint32_t* v4; // esi

	v3 = *(uint32_t*)(a1 + 12);
	v4 = calloc(1, 0x108u);
	memset(v4, 0, 0x108u);
	sub_425770(v4);
	v4[6] = a2;
	v4[5] = a1;
	v4[4] = 0;
	++*(uint32_t*)(a1 + 16);
	*(uint32_t*)(a1 + 4 * a2 + 24) = v4;
	v4[64] = *(uint32_t*)(v3 + 36);
	nox_common_list_clear_425760(v4 + 50);
	sub_4864A0(v4 + 22);
	v4[53] = 0;
	v4[56] = 33;
	v4[60] = 0;
	v4[58] = 0;
	v4[62] = 0;
	v4[54] = sub_4873C0;
	v4[57] = 0;
	v4[61] = 0;
	v4[59] = 0;
	v4[63] = 0;
	nullsub_10(v4 + 15);
	nullsub_10(v4 + 8);
	if (a3) {
		sub_487590((int)v4, a3);
	}
	if (!(*(int (**)(uint32_t*))(v3 + 28))(v4)) {
		return v4;
	}
	if (v4) {
		sub_4872C0(v4);
	}
	return 0;
}
// 487CF0: using guessed type void  nullsub_10(uint32_t);

//----- (004872C0) --------------------------------------------------------
void sub_4872C0(void* lpMem) {
	int v1; // eax
	int v2; // ecx

	sub_487910((int)lpMem, -1);
	(*(void (**)(void*))(*(uint32_t*)(*((uint32_t*)lpMem + 5) + 12) + 32))(lpMem);
	*(uint32_t*)(*((uint32_t*)lpMem + 5) + 4 * *((uint32_t*)lpMem + 6) + 24) = 0;
	v1 = *((uint32_t*)lpMem + 5);
	v2 = *(uint32_t*)(v1 + 16) - 1;
	*(uint32_t*)(v1 + 16) = v2;
	if (v2 < 0) {
		*(uint32_t*)(*((uint32_t*)lpMem + 5) + 16) = 0;
	}
	free(lpMem);
}

//----- (00487310) --------------------------------------------------------
int sub_487310(uint32_t* a1) {
	int result; // eax

	++*(uint32_t*)((uint32_t)dword_587000_155144 + 24);
	nox_common_list_append_4258E0((uint32_t)dword_587000_155144 + 12, a1);
	result = *(uint32_t*)((uint32_t)dword_587000_155144 + 24) - 1;
	*(uint32_t*)((uint32_t)dword_587000_155144 + 24) = result;
	if (result < 0) {
		*(uint32_t*)((uint32_t)dword_587000_155144 + 24) = 0;
	}
	return result;
}

//----- (00487360) --------------------------------------------------------
int* sub_487360(int a1, int** a2, int* a3) {
	int* result; // eax
	int i;       // esi
	int v5;      // ecx
	int* v6;     // [esp+4h] [ebp-4h]

	result = sub_4870E0((int*)&v6);
	for (i = a1; result; result = sub_487100(&v6)) {
		v5 = result[5];
		if (i < v5) {
			break;
		}
		i -= v5;
	}
	*a2 = result;
	if (result) {
		result = a3;
		*a3 = i;
	} else {
		*a3 = -1;
	}
	return result;
}

//----- (004873C0) --------------------------------------------------------
int sub_4873C0(int a3) {
	int v1;           // esi
	long long v3;     // rax
	unsigned int v4;  // ecx
	int v5;           // ebp
	bool v6;          // cf
	unsigned int v7;  // ebx
	unsigned int v8;  // ecx
	int v9;           // edi
	unsigned int v10; // eax
	uint32_t* v11;    // ebx
	int v12;          // edi
	int v13;          // ebp
	uint32_t* v14;    // esi
	int v15;          // [esp+10h] [ebp-Ch]
	int v16;          // [esp+18h] [ebp-4h]
	int v17;          // [esp+20h] [ebp+4h]

	v1 = a3;
	if (*(uint32_t*)(a3 + 212)) {
		return -2146304000;
	}
	v3 = nox_platform_get_ticks();
	v4 = *(uint32_t*)(a3 + 248);
	v5 = v3;
	v6 = (unsigned int)v3 < v4;
	v7 = v3 - v4;
	v8 = *(uint32_t*)(a3 + 224);
	v16 = HIDWORD(v3);
	v9 = HIDWORD(v3) - (v6 + *(uint32_t*)(a3 + 252));
	v10 = *(uint32_t*)(a3 + 228);
	if (__PAIR64__(v9, v7) >= __PAIR64__(v10, v8)) {
		*(uint32_t*)(a3 + 232) = v7;
		*(uint32_t*)(a3 + 236) = v9;
		if (*(uint64_t*)(a3 + 240) > 10 * __PAIR64__(v10, v8)) {
			*(uint32_t*)(a3 + 240) = 0;
			*(uint32_t*)(a3 + 244) = 0;
		}
		if (__PAIR64__(v9, v7) > *(uint64_t*)(a3 + 240)) {
			*(uint32_t*)(a3 + 240) = v7;
			*(uint32_t*)(a3 + 244) = v9;
		}
		v11 = (uint32_t*)(a3 + 88);
		v15 = a3 + 88;
		sub_486520((unsigned int*)(a3 + 88));
		if (*(uint32_t*)(a3 + 184)) {
			sub_486520(*(unsigned int**)(a3 + 184));
		}
		if (!*(uint32_t*)(a3 + 184) || !(v17 = sub_486550(*(uint8_t**)(a3 + 184)))) {
			v17 = sub_486550((uint8_t*)(v1 + 88));
		}
		*(uint32_t*)(v1 + 248) = v5;
		*(uint32_t*)(v1 + 252) = v16;
		v12 = *(uint32_t*)(v1 + 200);
		if (v12 != v1 + 200) {
			do {
				v13 = *(uint32_t*)v12;
				if (*(uint8_t*)(v12 + 124) & 1 && *(uint32_t*)(v12 + 288)) {
					if ((sub_486520((unsigned int*)(v12 + 16)), v17) || sub_486550((uint8_t*)(v12 + 16)) ||
						*(uint32_t*)(v12 + 116) && sub_486550(*(uint8_t**)(v12 + 116)) ||
						*(uint32_t*)(v12 + 112) && sub_486550(*(uint8_t**)(v12 + 112))) {
						sub_4BD840(v12);
						(*(void (**)(int))(*(uint32_t*)(v12 + 172) + 32))(v12);
					}
				}
				v12 = v13;
			} while (v13 != v1 + 200);
			v11 = (uint32_t*)v15;
		}
		v14 = *(uint32_t**)(v1 + 184);
		if (v14) {
			sub_486620(v14);
		}
		sub_486620(v11);
	}
	return 0;
}

//----- (00487590) --------------------------------------------------------
int sub_487590(int a1, const void* a2) {
	int result; // eax

	result = a1;
	memcpy((void*)(a1 + 60), a2, 0x1Cu);
	return result;
}

//----- (004875B0) --------------------------------------------------------
int* sub_4875B0(int* a1) {
	int* result; // eax

	result = nox_common_list_getFirstSafe_425890((int*)((uint32_t)dword_587000_155144 + 12));
	*a1 = (int)result;
	return result;
}

//----- (004875D0) --------------------------------------------------------
int* sub_4875D0(int** a1) {
	if (*a1) {
		*a1 = nox_common_list_getNextSafe_4258A0(*a1);
	}
	return *a1;
}

//----- (004875F0) --------------------------------------------------------
int sub_4875F0() {
	int* v0;    // edi
	int* v1;    // esi
	int result; // eax
	int* v3;    // [esp+4h] [ebp-4h]

	++*(uint32_t*)((uint32_t)dword_587000_155144 + 24);
	v0 = sub_4875B0((int*)&v3);
	if (v0) {
		do {
			v1 = sub_4875D0(&v3);
			sub_487680(v0);
			v0 = v1;
		} while (v1);
	}
	result = *(uint32_t*)((uint32_t)dword_587000_155144 + 24) - 1;
	*(uint32_t*)((uint32_t)dword_587000_155144 + 24) = result;
	if (result < 0) {
		*(uint32_t*)((uint32_t)dword_587000_155144 + 24) = 0;
	}
	return result;
}

//----- (00487650) --------------------------------------------------------
void sub_487650(uint32_t* lpMem) {
	int v2; // ecx

	v2 = lpMem[4] - 1;
	lpMem[4] = v2;
	if (v2 < 0) {
		lpMem[4] = 0;
	}
	sub_487680(lpMem);
}

//----- (00487680) --------------------------------------------------------
void sub_487680(void* lpMem) {
	sub_4876A0((uint32_t**)lpMem);
	sub_4872C0(lpMem);
}

//----- (004876A0) --------------------------------------------------------
void* sub_4876A0(uint32_t** a1) {
	void* result; // eax

	++*(uint32_t*)((uint32_t)dword_587000_155144 + 24);
	sub_425920(a1);
	result = (void*)(*(uint32_t*)((uint32_t)dword_587000_155144 + 24) - 1);
	*(uint32_t*)((uint32_t)dword_587000_155144 + 24) = result;
	if ((int)result < 0) {
		result = *(void**)&dword_587000_155144;
		*(uint32_t*)((uint32_t)dword_587000_155144 + 24) = 0;
	}
	return result;
}

//----- (004876E0) --------------------------------------------------------
int sub_4876E0() { return -2147221504; }

//----- (004876F0) --------------------------------------------------------
uint32_t* sub_4876F0(int a1, int a2) { return sub_486320((uint32_t*)(a1 + 88), a2); }

//----- (00487710) --------------------------------------------------------
int sub_487710(int a1, int a2) { return sub_486350(a1 + 88, a2); }

//----- (00487730) --------------------------------------------------------
int sub_487730(int a1) { return *(uint32_t*)(a1 + 196); }

//----- (00487740) --------------------------------------------------------
int sub_487740(int a1) { return *(uint32_t*)(a1 + 192); }

//----- (00487750) --------------------------------------------------------
uint32_t* sub_487750(int a1) {
	uint32_t* v1; // eax
	uint32_t* v2; // esi

	if (*(int*)(a1 + 192) >= *(int*)(a1 + 196)) {
		return 0;
	}
	v1 = sub_4BD720(a1);
	v2 = v1;
	if (!v1) {
		return 0;
	}
	sub_486E30(a1, v1);
	return v2;
}

//----- (00487790) --------------------------------------------------------
int sub_487790(int a1, int a2) {
	int v2; // esi
	int v3; // edi

	v2 = 0;
	if (sub_487750(a1)) {
		v3 = a2;
		do {
			++v2;
			--v3;
		} while (v3 && sub_487750(a1));
	}
	return v2;
}

//----- (004877D0) --------------------------------------------------------
int* sub_4877D0(int a1, int* a2) {
	int* result; // eax

	result = nox_common_list_getFirstSafe_425890((int*)(a1 + 200));
	*a2 = (int)result;
	return result;
}

//----- (004877F0) --------------------------------------------------------
int* sub_4877F0(int** a1) {
	if (*a1) {
		*a1 = nox_common_list_getNextSafe_4258A0(*a1);
	}
	return *a1;
}

//----- (00487810) --------------------------------------------------------
int* sub_487810(int a1, int a2) {
	unsigned int v2; // esi
	int v3;          // edi
	int* v4;         // ebp
	int* result;     // eax
	int v6;          // ecx
	unsigned int v7; // edx
	int v8;          // [esp+10h] [ebp-8h]
	int* v9;         // [esp+14h] [ebp-4h]

	v2 = -1;
	if (a2 == -1) {
		a2 = 1;
	}
	v3 = 127;
	v4 = 0;
	v8 = 127;
	v9 = 0;
	for (result = sub_4877D0(a1, &a1); result; result = sub_4877F0((int**)&a1)) {
		if (result[3] == a2) {
			if (!(result[31] & 0x15)) {
				return result;
			}
			v6 = result[30];
			if (result[31] & 1) {
				if (v6 >= v3) {
					if (v6 == v3) {
						v7 = result[45];
						if (v7 < v2 && v2 - v7 >= 0x666) {
							v3 = result[30];
							v4 = result;
							v2 = result[45];
						}
					}
				} else {
					v2 = result[45];
					v3 = result[30];
					v4 = result;
				}
			} else if (v6 < v8) {
				v8 = result[30];
				v9 = result;
			}
		}
	}
	result = v9;
	if (!v9 || v8 > v3) {
		result = v4;
	}
	return result;
}

//----- (004878E0) --------------------------------------------------------
int* sub_4878E0(int a1, int a2) {
	int* v2; // eax
	int* v3; // esi

	v2 = sub_487810(a1, 1);
	v3 = v2;
	if (v2) {
		sub_4BDA10((int)v2, a2);
	}
	return v3;
}

//----- (00487910) --------------------------------------------------------
int sub_487910(int a1, int a2) {
	int* v2; // edi
	int v3;  // ebx
	int* v4; // esi

	v2 = sub_4877D0(a1, &a1);
	if (!v2) {
		return 0;
	}
	v3 = a2;
	do {
		v4 = sub_4877F0((int**)&a1);
		if (v3 == -1 || v2[3] == v3) {
			sub_4BDA60(v2);
		}
		v2 = v4;
	} while (v4);
	return 0;
}

//----- (00487970) --------------------------------------------------------
int* sub_487970(int a1, int a2) {
	int* result; // eax
	int* v3;     // edi
	int v4;      // ebx
	int* v5;     // esi

	result = sub_4877D0(a1, &a1);
	v3 = result;
	if (result) {
		v4 = a2;
		do {
			result = sub_4877F0((int**)&a1);
			v5 = result;
			if (v4 == -1 || v3[3] == v4) {
				result = (int*)sub_4BDA80((int)v3);
			}
			v3 = v5;
		} while (v5);
	}
	return result;
}

//----- (004879C0) --------------------------------------------------------
int* sub_4879C0(int a1, int a2) {
	int* result; // eax
	int v3;      // esi

	result = sub_4877D0(a1, &a1);
	if (result) {
		v3 = a2;
		do {
			if (result[31] & 1 && (v3 == -1 || result[3] == v3)) {
				sub_4BDAC0((int)result);
			}
			result = sub_4877F0((int**)&a1);
		} while (result);
	}
	return result;
}

//----- (00487A10) --------------------------------------------------------
int* sub_487A10(int a1, int a2) {
	int* result; // eax
	int v3;      // esi

	result = sub_4877D0(a1, &a1);
	if (result) {
		v3 = a2;
		do {
			if (result[31] & 4 && (v3 == -1 || result[3] == v3)) {
				sub_4BDAF0((int)result);
			}
			result = sub_4877F0((int**)&a1);
		} while (result);
	}
	return result;
}

//----- (00487A60) --------------------------------------------------------
int sub_487A60(int a1) { return (*(int (**)(int))(a1 + 216))(a1); }

//----- (00487A70) --------------------------------------------------------
int nox_xxx_unused_487A70(uint32_t* a1, int (*a2)(char*)) {
	int* v2;           // eax
	int i;             // edi
	unsigned char* v4; // esi
	int v5;            // ecx
	unsigned char* v6; // edx
	int* v8;           // [esp+Ch] [ebp-CCh]
	char v9[200];      // [esp+10h] [ebp-C8h]

	a2((char*)getMemAt(0x587000, 155148));
	nox_sprintf(v9, "%s (%d)\n", **(uint32_t**)(a1[5] + 12), a1[47]);
	a2(v9);
	nox_sprintf(v9, "si: %05d ms (%05d,%d) \n", a1[56], a1[58], a1[60]);
	a2(v9);
	nox_sprintf(v9, "Chan:TYPE: STATE :  SAMPLE  :PRI :VOL:\n");
	a2(v9);
	v2 = sub_4877D0((int)a1, (int*)&v8);
	for (i = 0; v2; v2 = sub_4877F0(&v8)) {
		if (v2[31] & 1) {
			v4 = getMemAt(0x587000, 155264);
		} else {
			v4 = getMemAt(0x587000, 155272);
			if (!(v2[31] & 4)) {
				v4 = getMemAt(0x587000, 155280);
			}
		}
		v5 = v2[3];
		if (v5 < 4096) {
			v6 = getMemAt(0x587000, 155296);
			if (v5 != 1) {
				v6 = getMemAt(0x587000, 155304);
			}
		} else {
			v6 = getMemAt(0x587000, 155288);
		}
		nox_sprintf(v9, "#%2d :%s:%s:0x%08x:%4d:%3d:\n", i, v6, v4, v2[72], v2[30],
					(100 * ((unsigned int)v2[45] >> 16)) >> 14);
		a2(v9);
		++i;
	}
	return ((int (*)(unsigned char*))a2)(getMemAt(0x587000, 155344));
}

//----- (00487BC0) --------------------------------------------------------
uint32_t* sub_487BC0(size_t a1) {
	uint32_t* v1; // esi
	void* v2;     // eax

	v1 = calloc(1, 0x1Cu);
	memset(v1, 0, 0x1Cu);
	sub_487C30(v1);
	v1[1] = a1;
	v2 = calloc(1, a1);
	*v1 = v2;
	if (v2) {
		return v1;
	}
	if (v1) {
		sub_487C10(v1);
	}
	return 0;
}

//----- (00487C10) --------------------------------------------------------
void sub_487C10(void* lpMem) {
	if (*(uint32_t*)lpMem) {
		free(*(void**)lpMem);
	}
	free(lpMem);
}

//----- (00487C30) --------------------------------------------------------
void sub_487C30(uint32_t* a1) {
	*a1 = 0;
	a1[1] = 0;
	a1[5] = 0;
	a1[6] = 0;
	nox_common_list_clear_425760(a1 + 2);
}

//----- (00487C50) --------------------------------------------------------
int sub_487C50(int a1, uint32_t* a2) {
	int result; // eax

	nox_common_list_append_4258E0(a1 + 8, a2);
	result = a2[4] + *(uint32_t*)(a1 + 4);
	*(uint32_t*)(a1 + 4) = result;
	a2[5] = a1;
	return result;
}

//----- (00487C80) --------------------------------------------------------
int sub_487C80(int a1) { return nox_common_list_getNext_425940((int*)(a1 + 8)); }

//----- (00487CB0) --------------------------------------------------------
int sub_487CB0(int a1, int a2) { return a2 * *(uint32_t*)(a1 + 20) / 1000; }

//----- (00487CD0) --------------------------------------------------------
long long sub_487CD0(int a1, int a2) { return 1000 * a2 / *(uint32_t*)(a1 + 20); }

//----- (00487D00) --------------------------------------------------------
int sub_487D00(uint32_t* a1) {
	int v1;     // edx
	int result; // eax

	v1 = a1[1];
	result = a1[2] * a1[3] * a1[4];
	a1[5] = result;
	if (v1 == 1) {
		result >>= 2;
		a1[5] = result;
	}
	return result;
}

//----- (00487D30) --------------------------------------------------------
uint32_t* sub_487D30(uint32_t* a1, int a2, int a3) {
	uint32_t* result; // eax

	a1[4] = a3;
	a1[3] = a2;
	result = sub_425770(a1);
	a1[5] = 0;
	return result;
}

//----- (00487D60) --------------------------------------------------------
int sub_487D60(int a1) {
	int result; // eax

	result = a1;
	*(uint32_t*)(a1 + 20) = 0;
	return result;
}

//----- (00487D70) --------------------------------------------------------
int nox_xxx_wndEditProc_487D70_key(uint32_t* a1, int v4, int a3, int a4) {
	switch (a3) {
	case 1:
	case 58:
	case 59:
	case 60:
	case 61:
	case 62:
	case 63:
	case 64:
	case 65:
	case 66:
	case 67:
	case 68:
	case 87:
	case 88:
	case 199:
	case 201:
	case 207:
	case 209:
		return 0;
	case 14:
	case 211:
		if (a3 != 14 && (nox_strman_get_lang_code() == 6 || nox_strman_get_lang_code() == 8)) {
			break;
		}
		if (a4 != 2) {
			return 1;
		}
		if (!*(uint16_t*)(v4 + 1054)) {
			short v6 = *(uint16_t*)(v4 + 1052);
			if (!v6) {
				return 1;
			}
			unsigned short v7 = v6 - 1;
			*(uint16_t*)(v4 + 1052) = v7;
			*(uint16_t*)(v4 + 2 * v7) = 0;
			return 1;
		}
		break;
	case 15:
	case 205:
	case 208:
		if (a4 != 2) {
			return 1;
		}
		nox_xxx_wndRetNULL_46A8A0();
		return 1;
	case 28:
	case 156:
		if (a4 != 2 || *(uint32_t*)(v4 + 1044)) {
			return 1;
		}
		nox_window_call_field_94(a1[13], 16415, (int)a1, 0);
		return 1;
	case 200:
	case 203:
		if (a4 != 2) {
			return 1;
		}
		nox_xxx_wndRetNULL_0_46A8B0();
		return 1;
	default:
		break;
	}
	if (nox_strman_get_lang_code() == 6 || nox_strman_get_lang_code() == 8) {
		if (!*(uint32_t*)(v4 + 1036) && !*(uint32_t*)(v4 + 1032) && !*(uint32_t*)(v4 + 1028)) {
			wchar_t* v8 = nox_input_getStringBuffer_57011C();
			nox_wcscpy((wchar_t*)(v4 + 512), (const wchar_t*)v8);
			nox_input_freeStringBuffer_57011C(v8);
			*(uint16_t*)(v4 + 1054) = nox_wcslen((const wchar_t*)(v4 + 512));
			if (0) { // if (!nox_xxx_string_5702B4(*(uint32_t***)&dword_5d4594_1193348))
				return 1;
			}
			// nox_xxx_string_570392(*(uint32_t***)&dword_5d4594_1193348);
			nox_window_set_hidden(*(uint32_t*)(v4 + 1048), 1);
			return 1;
		}
	}
	unsigned short v9 = nox_input_scanCodeToAlpha_47F950(a3);
	if (!v9 || a4 != 2) {
		return 1;
	}
	int v10 = 0;
	if (*(uint32_t*)(v4 + 1028)) {
		v10 = iswdigit(v9);
		if (!v10) {
			return 1;
		}
	} else if (*(uint32_t*)(v4 + 1032)) {
		v10 = iswalnum(v9);
		if (!v10) {
			return 1;
		}
	}
	int v11 = *(unsigned short*)(v4 + 1052);
	if ((unsigned short)v11 >= *(short*)(v4 + 1040) - 1) {
		return 1;
	}
	*(uint16_t*)(v4 + 2 * v11) = v9;
	*(uint16_t*)(v4 + 2 * (unsigned short)++*(uint16_t*)(v4 + 1052)) = 0;
	return 1;
}
int nox_xxx_wndEditProc_487D70(uint32_t* a1, int a2, int a3, int a4) {
	int v4;  // esi
			 //	int result;          // eax
			 //	short v6;          // ax
			 //	unsigned short v7; // ax
			 //	unsigned short v9; // di
			 //	int v10;             // eax
			 //	int v11;             // eax
	int v12; // eax
	int v13; // eax
	int v14; // eax
	int v15; // eax
	int v16; // [esp-10h] [ebp-20h]
	int v17; // [esp-10h] [ebp-20h]

	v4 = a1[8];
	switch (a2) {
	case 7:
		a1[9] |= 2u;
		nox_xxx_windowFocus_46B500((int)a1);
		return 1;
	case 8:
		v15 = a1[11];
		if (v15 & 0x100) {
			nox_window_call_field_94(a1[13], 0x4000, (int)a1, 0);
		}
		return 1;
	case 17:
		v12 = a1[11];
		if (!(v12 & 0x100)) {
			return 1;
		}
		v16 = a1[13];
		a1[9] |= 2u;
		nox_window_call_field_94(v16, 16389, (int)a1, 0);
		nox_xxx_windowFocus_46B500((int)a1);
		return 1;
	case 18:
		v13 = a1[11];
		if (v13 & 0x100) {
			v14 = a1[9];
			LOBYTE(v14) = v14 & 0xFD;
			v17 = a1[13];
			a1[9] = v14;
			nox_window_call_field_94(v17, 16390, (int)a1, 0);
		}
		return 1;
	case 21:
		return nox_xxx_wndEditProc_487D70_key(a1, v4, a3, a4);
	default:
		return 0;
	}
}

//----- (00488160) --------------------------------------------------------
int nox_xxx_wndEditDrawNoImage_488160(int a1, int a2) {
	int v2;          // edi
	int v3;          // edx
	int v4;          // ebx
	int v5;          // ecx
	int v6;          // kr04_4
	int v7;          // ebp
	wchar_t* v8;     // ecx
	signed short v9; // ax
	size_t v10;      // edx
	size_t v11;      // eax
	short* v12;      // edi
	int i;           // ecx
	uint32_t* v14;   // eax
	int v15;         // eax
	int v16;         // ebx
	bool v17;        // zf
	int v19;         // [esp-28h] [ebp-260h]
	int v20;         // [esp-14h] [ebp-24Ch]
	int v21;         // [esp+10h] [ebp-228h]
	int v22;         // [esp+14h] [ebp-224h]
	wchar_t* v23;    // [esp+18h] [ebp-220h]
	int v24;         // [esp+1Ch] [ebp-21Ch]
	wchar_t* v25;    // [esp+20h] [ebp-218h]
	short* v26;      // [esp+24h] [ebp-214h]
	int yTop;        // [esp+28h] [ebp-210h]
	int xLeft;       // [esp+2Ch] [ebp-20Ch]
	int v29;         // [esp+30h] [ebp-208h]
	int v30;         // [esp+34h] [ebp-204h]
	short v31[256];  // [esp+38h] [ebp-200h]

	v2 = a1;
	v3 = *(uint32_t*)(a2 + 20);
	v25 = *(wchar_t**)(a2 + 28);
	v23 = *(wchar_t**)(a1 + 32);
	v22 = 0;
	v24 = 0;
	*((uint32_t*)v23 + 261) = 0;
	v30 = v3;
	v26 = v31;
	nox_client_wndGetPosition_46AA60((uint32_t*)a1, &xLeft, &yTop);
	v4 = xLeft;
	v21 = *(uint32_t*)(a1 + 8);
	v5 = nox_xxx_guiFontHeightMB_43F320(*(uint32_t*)(a2 + 200));
	v6 = *(uint32_t*)(a1 + 12);
	v29 = v5;
	v7 = yTop + v6 / 2 - v5 / 2;
	if (((*(uint32_t*)(a1 + 4) >> 13) & 1) == 1) {
		nox_draw_enableTextSmoothing_43F670(1);
	}
	if ((*(uint32_t*)(a1 + 4) >> 3) & 1) {
		if (*(uint8_t*)a2 & 2) {
			v25 = *(wchar_t**)(a2 + 36);
		}
	} else {
		v30 = *(uint32_t*)(a2 + 44);
	}
	if (*(uint16_t*)(a2 + 72)) {
		nox_xxx_drawGetStringSize_43F840(*(uint32_t*)(a2 + 200), (unsigned short*)(a2 + 72), &v22, 0, 0);
		nox_xxx_drawSetTextColor_434390(*(uint32_t*)(a2 + 68));
		nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(a2 + 200), (uint16_t*)(a2 + 72), v4 + 2, v7, v21, 0);
		v4 += v22 + 6;
		v21 += -6 - v22;
	}
	v8 = v23;
	v9 = v23[521];
	if (v9 > 0 && v21 > v9) {
		v21 = v9;
		v4 = xLeft + *(uint32_t*)(a1 + 8) - v9;
	}
	if (v30 != 0x80000000) {
		nox_client_drawSetColor_434460(v30);
		nox_client_drawRectFilledOpaque_49CE30(v4 + 1, yTop + 1, v21 - 2, *(uint32_t*)(a1 + 12) - 2);
		v8 = v23;
	}
	if (v25 != (wchar_t*)0x80000000) {
		nox_client_drawSetColor_434460((int)v25);
		nox_client_drawBorderLines_49CC70(v4, yTop, v21, *(uint32_t*)(a1 + 12));
		v8 = v23;
	}
	if (*(uint32_t*)(a2 + 68) != 0x80000000) {
		if (*((uint32_t*)v8 + 256)) {
			v10 = nox_wcslen(v8);
			v11 = 0;
			if ((int)v10 > 0) {
				memset32(v31, 2752554, v10 >> 1);
				v12 = &v31[2 * (v10 >> 1)];
				for (i = v10 & 1; i; --i) {
					*v12 = 42;
					++v12;
				}
				v2 = a1;
				v11 = v10;
			}
			v31[v11] = 0;
		} else {
			nox_wcscpy((wchar_t*)v31, v8);
		}
		nox_xxx_drawGetStringSize_43F840(*(uint32_t*)(a2 + 200), (unsigned short*)v31, &v22, 0, 0);
		v19 = *(uint32_t*)(a2 + 200);
		v25 = v23 + 256;
		nox_xxx_drawGetStringSize_43F840(v19, v23 + 256, &v24, 0, 0);
		if (((*(uint32_t*)(v2 + 4) >> 14) & 1) == 1 && v24 + v22 > 0 && v21 >= 10 && v24 + v22 + 10 > v21) {
			do {
				v20 = *(uint32_t*)(a2 + 200);
				++v26;
				nox_xxx_drawGetStringSize_43F840(v20, (unsigned short*)v26, &v22, 0, 0);
			} while (v24 + v22 + 10 > v21);
		}
		v14 = (uint32_t*)*((uint32_t*)v23 + 262);
		if (v14) {
			nox_window_setPos_46A9B0(v14, v4 + v22, v29 + v7);
		}
		nox_xxx_drawSetTextColor_434390(*(uint32_t*)(a2 + 68));
		nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(a2 + 200), v26, v4 + 5, v7, 0, 0);
		v15 = nox_color_rgb_4344A0(192, 0, 192);
		nox_xxx_drawSetTextColor_434390(v15);
		nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(a2 + 200), v25, v4 + v22 + 5, v7, 0, 0);
		v16 = v4 + v22 + v24 + 5;
		if (v2 == nox_xxx_wndGetFocus_46B4F0()) {
			v17 = ((*getMemU8Ptr(0x5D4594, 1193344))++ & 8) == 0;
			if (!v17) {
				nox_client_drawSetColor_434460(*(uint32_t*)(a2 + 68));
				nox_client_drawRectFilledOpaque_49CE30(v16, v7, 2, v29);
			}
		}
	}
	nox_draw_enableTextSmoothing_43F670(0);
	return 1;
}
// 488160: using guessed type wchar_t var_200[256];

//----- (00488500) --------------------------------------------------------
nox_window* nox_gui_newEntryField_488500(int a1, int a2, int a3, int a4, int a5, int a6, int a7, wchar_t* a8) {
	uint32_t* v8;     // esi
	bool v9;          // cc
	int* v10;         // ebx
	uint32_t* result; // eax
	uint32_t* v12;    // eax
	int v13;          // eax
	char v14[56];     // [esp+14h] [ebp-184h]
	char v15[332];    // [esp+4Ch] [ebp-14Ch]

	if (*(uint8_t*)(a7 + 8) & 0x80) {
		v8 = nox_window_new(a1, a2, a3, a4, a5, a6, nox_xxx_wndEditProcPre_488710);
		nox_xxx_wndEdit_488830((int)v8);
		if (!v8) {
			return v8;
		}
		if (!*(uint32_t*)(a7 + 16)) {
			*(uint32_t*)(a7 + 16) = v8;
		}
		nox_gui_windowCopyDrawData_46AF80((int)v8, (const void*)a7);
		memset(a8, 0, 0x100u);
		memset(a8 + 256, 0, 0x100u);
		a8[526] = nox_wcslen(a8);
		v9 = (short)a8[520] < 256;
		a8[527] = 0;
		*((uint32_t*)a8 + 261) = 0;
		if (!v9) {
			a8[520] = 256;
		}
		v10 = (int*)calloc(1, 0x420u);
		memcpy(v10, a8, 0x420u);
		v8[8] = v10;
		if (nox_strman_get_lang_code() != 8 && nox_strman_get_lang_code() != 6) {
			result = v8;
			v10[262] = 0;
			return result;
		}
		memset(v15, 0, sizeof(v15));
		*(uint32_t*)&v15[24] = 0;
		*(uint32_t*)&v15[28] = *(uint32_t*)(a7 + 68);
		*(uint32_t*)&v15[36] = 0x80000000;
		*(uint32_t*)&v15[52] = 0x80000000;
		*(uint32_t*)&v15[68] = *(uint32_t*)&v15[28];
		memset(v14, 0, sizeof(v14));
		*(uint32_t*)&v14[8] = 1;
		*(uint32_t*)&v14[12] = 1;
		*(uint32_t*)&v15[48] = 0;
		*(uint16_t*)&v14[2] = 0x0a;
		*(uint16_t*)&v14[0] = 0x80;
		*(uint32_t*)&v14[4] = 0;
		*(uint32_t*)&v14[16] = 0;
		*(uint16_t*)&v15[72] = 0;
		*(uint32_t*)&v15[8] = 288;
		v12 = nox_gui_newScrollListBox_4A4310(0, 17584, 0, a6, 110, 119, (int)v15, (short*)v14);
		v10[262] = (int)v12;
		if (v12) {
			nox_xxx_wndClearFlag_46AD80((int)v12, 128);
			nox_xxx_wndListboxInit_4A3C00(v10[262], *(uint32_t*)(v10[262] + 32));
			v13 = nox_color_rgb_4344A0(0, 0, 0);
			nox_xxx_wndSetRectColor2MB_46AFE0(v10[262], v13);
			return v8;
		}
	}
	return 0;
}

//----- (00488710) --------------------------------------------------------
int nox_xxx_wndEditProcPre_488710(int a1, unsigned int a2, wchar_t* a3, int a4) {
	int v3; // esi
	int v4; // eax
	int v6; // eax
	int v7; // eax

	v3 = *(uint32_t*)(a1 + 32);
	if (a2 > 0x401D) {
		if (a2 == 16414) {
			nox_wcsncpy((wchar_t*)v3, a3, 0xFFu);
			*(uint16_t*)(v3 + 510) = 0;
			*(uint16_t*)(v3 + 1052) = nox_wcslen((const wchar_t*)v3);
			*(uint16_t*)(v3 + 512) = 0;
			*(uint16_t*)(v3 + 1054) = 0;
		}
		return 0;
	}
	if (a2 == 16413) {
		return *(uint32_t*)(a1 + 32);
	}
	if (a2 == 2) {
		nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)(v3 + 1048));
		free(*(void**)(a1 + 32));
		return 0;
	}
	if (a2 != 23) {
		return 0;
	}
	if (a3) {
		dword_5d4594_1193352 = a1;
		nox_input_enableTextEdit_5700CA();
		v6 = *(uint32_t*)(a1 + 36);
		LOBYTE(v6) = v6 | 6;
		*(uint32_t*)(a1 + 36) = v6;
	} else {
		nox_input_disableTextEdit_5700F6();
		dword_5d4594_1193352 = 0;
		v4 = *(uint32_t*)(a1 + 36);
		LOBYTE(v4) = v4 & 0xF9;
		*(uint32_t*)(a1 + 36) = v4;
		nox_window_set_hidden(*(uint32_t*)(v3 + 1048), 1);
		*(uint16_t*)(v3 + 512) = 0;
		*(uint16_t*)(v3 + 1054) = 0;
	}
	v7 = nox_xxx_wndGetID_46B0A0((int*)a1);
	nox_window_call_field_94(*(uint32_t*)(a1 + 52), 16387, (int)a3, v7);
	return 1;
}

//----- (00488830) --------------------------------------------------------
int nox_xxx_wndEdit_488830(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		if ((signed char)*(uint8_t*)(a1 + 4) >= 0) {
			result = nox_window_set_all_funcs((uint32_t*)a1, nox_xxx_wndEditProc_487D70,
											  nox_xxx_wndEditDrawNoImage_488160, 0);
		} else {
			result = nox_window_set_all_funcs((uint32_t*)a1, nox_xxx_wndEditProc_487D70,
											  nox_xxx_wndEditDrawWithImage_488870, 0);
		}
	}
	return result;
}

//----- (00488870) --------------------------------------------------------
int nox_xxx_wndEditDrawWithImage_488870(int a1, int a2) {
	int v2;         // edi
	int v3;         // ebp
	int v4;         // ecx
	int v5;         // kr04_4
	int v6;         // ebx
	int v7;         // eax
	size_t v8;      // edx
	size_t v9;      // eax
	short* v10;     // edi
	int i;          // ecx
	int v12;        // eax
	bool v13;       // zf
	int v15;        // [esp-14h] [ebp-244h]
	int xLeft;      // [esp+10h] [ebp-220h]
	int v17;        // [esp+14h] [ebp-21Ch]
	short* v18;     // [esp+18h] [ebp-218h]
	int v19;        // [esp+1Ch] [ebp-214h]
	wchar_t* v20;   // [esp+20h] [ebp-210h]
	int v21;        // [esp+24h] [ebp-20Ch]
	wchar_t* v22;   // [esp+28h] [ebp-208h]
	int v23;        // [esp+2Ch] [ebp-204h]
	short v24[256]; // [esp+30h] [ebp-200h]

	v2 = a1;
	v20 = *(wchar_t**)(a2 + 24);
	v22 = *(wchar_t**)(a1 + 32);
	*((uint32_t*)v22 + 261) = 0;
	v18 = v24;
	nox_client_wndGetPosition_46AA60((uint32_t*)a1, &xLeft, &v21);
	v3 = *(uint32_t*)(a1 + 8);
	v4 = nox_xxx_guiFontHeightMB_43F320(*(uint32_t*)(a2 + 200));
	v5 = *(uint32_t*)(a1 + 12);
	v23 = v4;
	v6 = v21 + v5 / 2 - v4 / 2;
	if (((*(uint32_t*)(a1 + 4) >> 13) & 1) == 1) {
		nox_draw_enableTextSmoothing_43F670(1);
	}
	if ((*(uint32_t*)(a1 + 4) >> 3) & 1) {
		v7 = (int)v20;
	} else {
		v7 = *(uint32_t*)(a2 + 48);
	}
	if (v7) {
		nox_client_drawImageAt_47D2C0(v7, xLeft, v21);
	}
	nox_xxx_drawSetTextColor_434390(*(uint32_t*)(a2 + 68));
	if (*(uint16_t*)(a2 + 72)) {
		nox_xxx_drawGetStringSize_43F840(*(uint32_t*)(a2 + 200), (unsigned short*)(a2 + 72), &v17, 0, 0);
		nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(a2 + 200), (uint16_t*)(a2 + 72), xLeft + 2, v6, v3, 0);
		v3 += -6 - v17;
		xLeft += v17 + 6;
	}
	if (*(uint32_t*)(a2 + 68) != 0x80000000) {
		if (*((uint32_t*)v22 + 256)) {
			v8 = nox_wcslen(v22);
			v9 = 0;
			if ((int)v8 > 0) {
				memset32(v24, 2752554, v8 >> 1);
				v10 = &v24[2 * (v8 >> 1)];
				for (i = v8 & 1; i; --i) {
					*v10 = 42;
					++v10;
				}
				v2 = a1;
				v9 = v8;
			}
			v24[v9] = 0;
		} else {
			nox_wcscpy((wchar_t*)v24, v22);
		}
		nox_xxx_drawGetStringSize_43F840(*(uint32_t*)(a2 + 200), (unsigned short*)v24, &v17, 0, 0);
		v20 = v22 + 256;
		nox_xxx_drawGetStringSize_43F840(*(uint32_t*)(a2 + 200), v22 + 256, &v19, 0, 0);
		if (((*(uint32_t*)(v2 + 4) >> 14) & 1) == 1 && v17 + v19 > 0 && v17 + v19 + 10 > v3) {
			do {
				v15 = *(uint32_t*)(a2 + 200);
				++v18;
				nox_xxx_drawGetStringSize_43F840(v15, (unsigned short*)v18, &v17, 0, 0);
			} while (v19 + v17 + 10 > v3);
		}
		nox_xxx_drawSetTextColor_434390(*(uint32_t*)(a2 + 68));
		nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(a2 + 200), v18, xLeft + 5, v6, v3, 0);
		v12 = nox_color_rgb_4344A0(192, 0, 192);
		nox_xxx_drawSetTextColor_434390(v12);
		nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(a2 + 200), v20, v17 + xLeft + 5, v6, v3, 0);
		xLeft += v17 + v19 + 5;
		if (v2 == nox_xxx_wndGetFocus_46B4F0()) {
			v13 = ((*getMemU8Ptr(0x5D4594, 1193344))++ & 8) == 0;
			if (!v13) {
				nox_client_drawSetColor_434460(*(uint32_t*)(a2 + 68));
				nox_client_drawRectFilledOpaque_49CE30(xLeft, v6, 2, v23);
			}
		}
	}
	nox_draw_enableTextSmoothing_43F670(0);
	return 1;
}
// 488870: using guessed type wchar_t var_200[256];

//----- (00488B60) --------------------------------------------------------
int sub_488B60() {
	int** v0; // eax

	v0 = (int**)operator_new(4u);
	if (v0) {
		dword_5d4594_1193348 = v0;
		// sub_570142(*(uint32_t***)&dword_5d4594_1193348, 11);
	} else {
		dword_5d4594_1193348 = 0;
		// sub_570142(0, 11);
	}
	return 1;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (00488BA0) --------------------------------------------------------
int sub_488BA0() {
	void* v0; // esi

	v0 = *(void**)&dword_5d4594_1193348;
	if (dword_5d4594_1193348) {
		operator_delete(v0);
	}
	dword_5d4594_1193348 = 0;
	return 1;
}

//----- (00488BD0) --------------------------------------------------------
void nox_xxx_onChar_488BD0(unsigned short a1) {
	int v2; // esi
	int v3; // eax

	if (dword_5d4594_1193348) {
		if (dword_5d4594_1193352) {
			v2 = *(uint32_t*)(dword_5d4594_1193352 + 32);
			if (nox_strman_get_lang_code() == 6 || nox_strman_get_lang_code() == 8) {
				if (!*(uint32_t*)(v2 + 1036)) {
					if (!*(uint32_t*)(v2 + 1032)) {
						if (!*(uint32_t*)(v2 + 1028)) {
							*(uint32_t*)(v2 + 1044) = 1;
							switch (a1) {
							case 7u:
							case 8u:
							case 9u:
							case 0xBu:
							case 0xCu:
								break;
							case 0xAu:
							case 0xDu:
								*(uint32_t*)(v2 + 1044) = 0;
								break;
							default:
								v3 = *(unsigned short*)(v2 + 1052);
								if ((unsigned short)v3 < *(short*)(v2 + 1040) - 1) {
									*(uint16_t*)(v2 + 2 * v3) = a1;
									*(uint16_t*)(v2 + 2 * (unsigned short)++*(uint16_t*)(v2 + 1052)) = 0;
								}
								wchar_t* v4 = nox_input_getStringBuffer_57011C();
								nox_wcscpy((wchar_t*)(v2 + 512), (const wchar_t*)v4);
								nox_input_freeStringBuffer_57011C(v4);
								*(uint16_t*)(v2 + 1054) = nox_wcslen((const wchar_t*)(v2 + 512));
								// nox_xxx_string_570392(*(uint32_t***)&dword_5d4594_1193348);
								nox_window_set_hidden(*(uint32_t*)(v2 + 1048), 1);
								break;
							}
						}
					}
				}
			}
		}
	}
}

#ifndef NOX_CGO
//----- (00488D00) --------------------------------------------------------
int nox_xxx_wndStaticDrawNoImage_488D00(nox_window* a1p, nox_window_data* a2p) {
	int a1 = a1p;
	int xLeft = a2p;
	int v2;               // esi
	unsigned short** v3;  // ebx
	int v4;               // ecx
	int v5;               // edi
	int v6;               // ebp
	int v7;               // eax
	int v8;               // ebp
	unsigned short* v9;   // eax
	int v10;              // ecx
	size_t v11;           // eax
	const wchar_t* v12;   // ebp
	const wchar_t* v13;   // ebx
	wchar_t* v14;         // ebx
	wchar_t* v15;         // eax
	int v16;              // ebp
	wchar_t* v17;         // eax
	int v18;              // ebx
	int v19;              // ebp
	int v20;              // ebx
	const wchar_t* v22;   // [esp-4h] [ebp-40h]
	int v23;              // [esp+10h] [ebp-2Ch]
	wchar_t* v24;         // [esp+14h] [ebp-28h]
	int v25;              // [esp+18h] [ebp-24h]
	int v26;              // [esp+1Ch] [ebp-20h]
	int v27;              // [esp+20h] [ebp-1Ch]
	int yTop;             // [esp+24h] [ebp-18h]
	int v29;              // [esp+28h] [ebp-14h]
	size_t v30;           // [esp+2Ch] [ebp-10h]
	int v31;              // [esp+30h] [ebp-Ch]
	int v32;              // [esp+34h] [ebp-8h]
	unsigned short** v33; // [esp+38h] [ebp-4h]
	wchar_t* v34;         // [esp+40h] [ebp+4h]

	v2 = xLeft;
	v3 = *(unsigned short***)(a1 + 32);
	v4 = *(uint32_t*)(xLeft + 20);
	v25 = *(uint32_t*)(xLeft + 28);
	v27 = v25;
	v33 = v3;
	v26 = v4;
	nox_client_wndGetPosition_46AA60((uint32_t*)a1, &xLeft, &yTop);
	v5 = *(uint32_t*)(a1 + 8);
	v6 = yTop + *(int*)(a1 + 12) / 2;
	if ((*(uint32_t*)(a1 + 4) & 0x2000) == 0x2000) {
		nox_draw_enableTextSmoothing_43F670(1);
	}
	if (*(uint8_t*)(a1 + 4) & 8) {
		if (*(uint8_t*)v2 & 2) {
			v25 = *(uint32_t*)(v2 + 36);
		}
		v7 = v26;
	} else {
		v7 = *(uint32_t*)(v2 + 44);
	}
	if (*(uint8_t*)v2 & 4) {
		v27 = *(uint32_t*)(v2 + 52);
	}
	if (v7 != 0x80000000) {
		nox_client_drawSetColor_434460(v7);
		nox_client_drawRectFilledOpaque_49CE30(xLeft + 1, yTop + 1, v5 - 2, *(uint32_t*)(a1 + 12) - 2);
	}
	if (v25 != 0x80000000) {
		nox_client_drawSetColor_434460(v25);
		nox_client_drawBorderLines_49CC70(xLeft, yTop, v5, *(uint32_t*)(a1 + 12));
	}
	if (*v3 && *(uint32_t*)(v2 + 68) != 0x80000000) {
		nox_xxx_drawSetTextColor_434390(*(uint32_t*)(v2 + 68));
		nox_xxx_drawGetStringSize_43F840(*(uint32_t*)(v2 + 200), *v3, &v29, &v23, v5);
		v8 = v23 / -2 + v6;
		v9 = v3[1];
		v26 = v8;
		if (v9) {
			v10 = *(uint32_t*)(v2 + 200);
			if (v23 > nox_xxx_guiFontHeightMB_43F320(v10)) {
				v22 = *v3;
				v32 = xLeft;
				v11 = nox_wcslen(v22);
				sub_4892D0(2 * v11 + 2);
				if (dword_5d4594_1193360) {
					v12 = *v3;
					v24 = *v3;
					while (1) {
						v25 = 0;
						v31 = 0;
						v13 = v12;
						v34 = (wchar_t*)v12;
						v30 = nox_wcslen(v12);
						while (1) {
							v14 = nox_wcschr(v13, 0x20u);
							if (!v14) {
								v25 = 1;
								v14 = (wchar_t*)&v12[v30];
							}
							v15 = v34;
							if (v34 <= v14) {
								while (*v15 != 10) {
									++v15;
									if (v15 > v14) {
										goto LABEL_32;
									}
								}
								v31 = 1;
								v14 = v15;
								if (v15 < &v12[v30]) {
									v25 = 0;
								}
							}
						LABEL_32:
							v16 = v14 - v24;
							nox_wcsncpy(*(wchar_t**)&dword_5d4594_1193360, v24, v16);
							*(uint16_t*)(dword_5d4594_1193360 + 2 * v16) = 0;
							nox_xxx_drawGetStringSize_43F840(*(uint32_t*)(v2 + 200),
															 *(unsigned short**)&dword_5d4594_1193360, 0, &v23, v5);
							if (v23 > nox_xxx_guiFontHeightMB_43F320(*(uint32_t*)(v2 + 200) + 28)) {
								break;
							}
							v34 = v14;
							v13 = v14 + 1;
							if (v25 || v31) {
								v17 = v24;
								goto LABEL_40;
							}
							v12 = v24;
						}
						v17 = v24;
						if (v34 == v24) {
							v34 = v14;
						}
						v25 = 0;
					LABEL_40:
						v18 = v34 - v17;
						nox_wcsncpy(*(wchar_t**)&dword_5d4594_1193360, v17, v18);
						*(uint16_t*)(dword_5d4594_1193360 + 2 * v18) = 0;
						nox_xxx_drawGetStringSize_43F840(*(uint32_t*)(v2 + 200),
														 *(unsigned short**)&dword_5d4594_1193360, &v29, &v23, v5);
						xLeft = v32 + (v5 - v29) / 2;
						if (v33[2]) {
							nox_xxx_drawSetTextColor_434390(v27);
							v19 = v26;
							v20 = v26 - 1;
							nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *(uint16_t**)&dword_5d4594_1193360,
													  xLeft - 1, v26 - 1, v5, 0);
							nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *(uint16_t**)&dword_5d4594_1193360,
													  xLeft + 1, v20, v5, 0);
							nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *(uint16_t**)&dword_5d4594_1193360,
													  xLeft - 1, v19 + 1, v5, 0);
							nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *(uint16_t**)&dword_5d4594_1193360,
													  xLeft + 1, v19 + 1, v5, 0);
							nox_xxx_drawSetTextColor_434390(*(uint32_t*)(v2 + 68));
							nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *(uint16_t**)&dword_5d4594_1193360, xLeft,
													  v19, v5, 0);
						} else {
							nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *(uint16_t**)&dword_5d4594_1193360,
													  v32 + (v5 - v29) / 2, v26, v5, 0);
							v19 = v26;
						}
						v26 = v23 + v19 + 1;
						if (v25) {
							break;
						}
						v24 = v34 + 1;
						v12 = v34 + 1;
					}
				}
			} else {
				xLeft += (v5 - v29) / 2;
				if (v3[2]) {
					nox_xxx_drawSetTextColor_434390(v27);
					nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *v3, xLeft - 1, v8 - 1, v5, 0);
					nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *v3, xLeft + 1, v8 - 1, v5, 0);
					nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *v3, xLeft - 1, v8 + 1, v5, 0);
					nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *v3, xLeft + 1, v8 + 1, v5, 0);
					nox_xxx_drawSetTextColor_434390(*(uint32_t*)(v2 + 68));
					nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *v3, xLeft, v8, v5, 0);
				} else {
					nox_xxx_drawStringWrap_43FAF0(v10, *v3, xLeft, v8, v5, 0);
				}
			}
		} else if (v3[2]) {
			nox_xxx_drawSetTextColor_434390(v27);
			nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *v3, xLeft + 1, v8 - 1, v5, 0);
			nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *v3, xLeft + 3, v8 - 1, v5, 0);
			nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *v3, xLeft + 1, v8 + 1, v5, 0);
			nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *v3, xLeft + 3, v8 + 1, v5, 0);
			nox_xxx_drawSetTextColor_434390(*(uint32_t*)(v2 + 68));
			nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *v3, xLeft + 2, v8, v5, 0);
		} else {
			nox_xxx_drawStringWrap_43FAF0(*(uint32_t*)(v2 + 200), *v3, xLeft + 2, v8, v5, 0);
		}
	}
	nox_draw_enableTextSmoothing_43F670(0);
	return 1;
}

//----- (004892D0) --------------------------------------------------------
wchar_t* sub_4892D0(int a1) {
	wchar_t* result; // eax

	result = (wchar_t*)a1;
	if (a1 > *getMemIntPtr(0x5D4594, 1193364)) {
		*getMemU32Ptr(0x5D4594, 1193364) = a1;
		result = (wchar_t*)realloc(*(void**)&dword_5d4594_1193360, a1);
		dword_5d4594_1193360 = result;
	}
	return result;
}

//----- (00489300) --------------------------------------------------------
nox_window* nox_gui_newStaticText_489300(nox_window* a1, int a2, int a3, int a4, int a5, int a6, nox_window_data* a7p, nox_staticText_data* a8p) {
	uint32_t* a7 = a7p;
	uint32_t* a8 = a8p;
	int v8;        // ecx
	uint32_t* v9;  // esi
	uint32_t* v10; // edx

	v8 = a7[2];
	BYTE1(v8) &= 0xFBu;
	a7[2] = v8;
	if (!(v8 & 0x800)) {
		return 0;
	}
	v9 = nox_window_new(a1, a2, a3, a4, a5, a6, nox_xxx_wndStaticProcPre_489390);
	nox_xxx_wndStatic_4893E0((int)v9);
	if (v9) {
		if (!a7[4]) {
			a7[4] = v9;
		}
		nox_gui_windowCopyDrawData_46AF80((int)v9, a7);
		v10 = calloc(1, 0xCu);
		v10[0] = a8[0];
		v10[1] = a8[1];
		v10[2] = a8[2];
		v9[8] = v10;
	}
	return v9;
}

//----- (00489390) --------------------------------------------------------
int nox_xxx_wndStaticProcPre_489390(nox_window* a1p, int a2, int a3, int a4) {
	int a1 = a1p;
	switch (a2) {
	case 2:
		free(*(void**)(a1 + 32));
		break;
	case 16385:
		if (a3) {
			**(uint32_t**)(a1 + 32) = a3;
			return 0;
		}
		break;
	case 16386:
		return **(uint32_t**)(a1 + 32);
	}
	return 0;
}

//----- (004893E0) --------------------------------------------------------
int nox_xxx_wndStatic_4893E0(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		if ((signed char)*(uint8_t*)(a1 + 4) >= 0) {
			result = nox_window_set_all_funcs((uint32_t*)a1, nox_xxx_wndStaticProc_489420,
											  nox_xxx_wndStaticDrawNoImage_488D00, 0);
		} else {
			result = nox_window_set_all_funcs((uint32_t*)a1, nox_xxx_wndStaticProc_489420,
											  nox_xxx_wndStaticDrawWithImage_489550, 0);
		}
	}
	return result;
}

//----- (00489420) --------------------------------------------------------
int nox_xxx_wndStaticProc_489420(int a1, int a2, int a3, int a4) {
	int result; // eax

	if (a2 != 21) {
		return 0;
	}
	switch (a3) {
	case 15:
	case 205:
	case 208:
		if (a4 != 2) {
			goto LABEL_7;
		}
		nox_xxx_wndRetNULL_46A8A0();
		result = 1;
		break;
	case 200:
	case 203:
		if (a4 == 2) {
			nox_xxx_wndRetNULL_0_46A8B0();
		}
	LABEL_7:
		result = 1;
		break;
	default:
		return 0;
	}
	return result;
}

//----- (00489550) --------------------------------------------------------
int nox_xxx_wndStaticDrawWithImage_489550(nox_window* a1p, nox_window_data* a2p) {
	uint32_t* a1 = a1p;
	uint32_t* a2 = a2p;
	uint32_t* v2;        // esi
	unsigned short** v3; // ebp
	uint32_t* v4;        // ebx
	int v5;              // eax
	int v6;              // edi
	int v7;              // eax
	int v8;              // eax
	int v9;              // ecx
	int v11;             // [esp+10h] [ebp-Ch]
	int v12;             // [esp+14h] [ebp-8h]
	int v13;             // [esp+18h] [ebp-4h]

	v2 = a1;
	v3 = (unsigned short**)a1[8];
	nox_client_wndGetPosition_46AA60(a1, &a1, &v11);
	v4 = a2;
	v12 = v2[2];
	v5 = nox_xxx_guiFontHeightMB_43F320(a2[50]);
	v6 = v11 + v2[3] / 2 - v5 / 2;
	if ((v2[1] & 0x2000) == 0x2000) {
		nox_draw_enableTextSmoothing_43F670(1);
	}
	v7 = v4[6];
	if (v7) {
		nox_client_drawImageAt_47D2C0(v7, (int)a1 + v2[24], v11 + v2[25]);
	}
	if (v2[1] & 8) {
		v8 = v4[8];
	} else {
		v8 = v4[12];
	}
	if (v8) {
		nox_client_drawImageAt_47D2C0(v8, (int)a1 + v2[24], v11 + v2[25]);
	}
	if (*v3) {
		nox_xxx_drawSetTextColor_434390(v4[17]);
		if (v3[1]) {
			nox_xxx_drawGetStringSize_43F840(v4[50], *v3, &v13, 0, 0);
			v9 = v4[50];
			a1 = (uint32_t*)((char*)a1 + (v12 - v13) / 2);
			nox_xxx_drawStringWrap_43FAF0(v9, *v3, (int)a1, v6, v12, 0);
		} else {
			nox_xxx_drawStringWrap_43FAF0(v4[50], *v3, (int)a1 + 2, v6, v12, 0);
		}
	}
	nox_draw_enableTextSmoothing_43F670(0);
	return 1;
}
#endif // NOX_CGO

//----- (004896C0) --------------------------------------------------------
int sub_4896C0() { return *getMemU32Ptr(0x5D4594, 1193356); }

//----- (004896D0) --------------------------------------------------------
int sub_4896D0(int a1) {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 1193356);
	*getMemU32Ptr(0x5D4594, 1193356) = a1;
	return result;
}

//----- (004896E0) --------------------------------------------------------
int sub_4896E0() {
	if (dword_5d4594_1193360) {
		free(*(void**)&dword_5d4594_1193360);
	}
	return 1;
}

//----- (00489870) --------------------------------------------------------
int sub_489870() {
	int v0;            // eax
	unsigned char* v1; // esi
	uint32_t* v2;      // eax
	const wchar_t* v3; // eax
	unsigned int v4;   // eax
	int v5;            // edx
	char v6;           // cl
	int v7;            // eax

	v0 = nox_xxx_check_flag_aaa_43AF70();
	v1 = getMemAt(0x5D4594, 1193388 + 44 * v0);
	if (*getMemU32Ptr(0x5D4594, 1193372 + 4 * v0) == 2) {
		*(uint32_t*)v1 =
			(nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10028)->draw_data.field_0 >> 2) & 1;
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10031);
		v3 = (const wchar_t*)nox_window_call_field_94((int)v2, 16413, 0, 0);
		*((uint32_t*)v1 + 4) = nox_wcstol(v3, 0, 10);
		*((uint32_t*)v1 + 1) =
			(nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10029)->draw_data.field_0 >> 2) & 1;
		v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10030)->draw_data.field_0;
		*((uint32_t*)v1 + 3) = 0;
		*((uint32_t*)v1 + 2) = (v4 >> 2) & 1;
		if (nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10015)->draw_data.field_0 & 4) {
			v5 = *((uint32_t*)v1 + 3);
			LOBYTE(v5) = v5 | 0x80;
			*((uint32_t*)v1 + 3) = v5;
			v6 = *((uint8_t*)(&nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10016)
								   ->draw_data.field_0));
			v7 = *((uint32_t*)v1 + 3);
			if (v6 & 4) {
				LOBYTE(v7) = v7 | 1;
			} else {
				LOBYTE(v7) = v7 | 2;
			}
			*((uint32_t*)v1 + 3) = v7;
		}
		*((uint32_t*)v1 + 5) =
			(nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10014)->draw_data.field_0 >> 2) & 1;
		*((uint32_t*)v1 + 10) =
			(nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10018)->draw_data.field_0 >> 2) & 1;
	}
	return nox_window_set_hidden(*(int*)&dword_5d4594_1193380, 1);
}

//----- (004899C0) --------------------------------------------------------
int nox_xxx_checkSomeFlagsOnJoin_4899C0(nox_gui_server_ent_t* srv) {
	int a1 = srv;
	int v1;            // eax
	int v2;            // edx
	int v3;            // eax
	unsigned char* v4; // ebp
	int v5;            // eax
	int v6;            // ebx
	unsigned int v7;   // eax
	char v9;           // al
	unsigned char v10; // cl
	unsigned char v11; // cl
	char v12;          // al
	int v13[15];       // [esp+Ch] [ebp-3Ch]
	unsigned char v14; // [esp+4Ch] [ebp+4h]
	unsigned char v15; // [esp+4Ch] [ebp+4h]

	v1 = nox_xxx_check_flag_aaa_43AF70();
	v2 = 11 * v1;
	v3 = *getMemU32Ptr(0x5D4594, 1193372 + 4 * v1);
	v4 = getMemAt(0x5D4594, 1193388 + 4 * v2);
	if (!v3) {
		return 1;
	}
	v5 = v3 - 1;
	if (v5) {
		if (v5 == 1) {
			v6 = a1;
			if (*(uint32_t*)v4) {
				v7 = *(uint32_t*)(a1 + 96);
				if (v7 > *((uint32_t*)v4 + 4) && v7 != 9999) {
					return 0;
				}
			}
			if (*((uint32_t*)v4 + 1) && *(uint8_t*)(a1 + 100) & 0x10) {
				return 0;
			}
			if (*((uint32_t*)v4 + 2) && *(uint8_t*)(a1 + 100) & 0x20) {
				return 0;
			}
			v9 = *(uint8_t*)(a1 + 102);
			if (v9 < 0 && *((uint32_t*)v4 + 3) > (v9 & 0x7F)) {
				return 0;
			}
			if (*((uint32_t*)v4 + 5)) {
				strcpy((char*)v13, (const char*)(a1 + 111));
				sub_57A1E0(v13, 0, 0, 5, *(uint16_t*)(a1 + 163));
				v10 = 0;
				v14 = 0;
				while (v13[v14 + 6] == *(uint32_t*)(4 * v14 + v6 + 135)) {
					v14 = ++v10;
					if (v10 >= 5u) {
						v11 = 0;
						v15 = 0;
						while (*((uint8_t*)&v13[11] + v15) == *(uint8_t*)(v15 + v6 + 155)) {
							v15 = ++v11;
							if (v11 >= 4u) {
								if (v13[12] == *(uint32_t*)(v6 + 159)) {
									goto LABEL_26;
								}
								return 0;
							}
						}
						return 0;
					}
				}
				return 0;
			}
		LABEL_26:
			if (*((uint32_t*)v4 + 10) && *(uint32_t*)(v6 + 48) != NOX_CLIENT_VERS_CODE) {
				return 0;
			}
		}
		return 1;
	}
	v12 = *(uint8_t*)(a1 + 100);
	if (v12 & 0x10) {
		return 0;
	}
	if (v12 & 0x20) {
		return 0;
	}
	return *(uint32_t*)(a1 + 48) == NOX_CLIENT_VERS_CODE;
}

//----- (00489B80) --------------------------------------------------------
uint32_t* sub_489B80(int a1) {
	uint32_t* result;  // eax
	int v2;            // ebx
	unsigned char* v3; // edi
	uint32_t* v4;      // eax
	uint32_t* v5;      // eax
	uint32_t* v6;      // eax
	uint32_t* v7;      // eax
	uint32_t* v8;      // eax
	uint32_t* v9;      // eax
	uint32_t* v10;     // esi
	int v11;           // ebx
	int v12;           // ebx
	wchar_t v13[16];   // [esp+0h] [ebp-20h]

	result = nox_new_window_from_file("filter.wnd", nox_xxx_windowMplayFilterProc_489E70);
	dword_5d4594_1193380 = result;
	if (result) {
		dword_5d4594_1193384 = nox_xxx_wndGetChildByID_46B0C0(result, 10012);
		v2 = nox_xxx_check_flag_aaa_43AF70();
		v3 = getMemAt(0x5D4594, 1193388 + 44 * v2);
		sub_46B120(*(uint32_t**)&dword_5d4594_1193380, a1);
		sub_46B120(*(uint32_t**)&dword_5d4594_1193384, *(int*)&dword_5d4594_1193380);
		nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1193384, nox_xxx_windowMplayFilterProc_489E70);
		if (*(uint32_t*)v3) {
			v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10028);
			v4[9] |= 4u;
		}
		nox_swprintf(v13, L"%d", *((uint32_t*)v3 + 4));
		v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10031);
		nox_window_call_field_94((int)v5, 16414, (int)v13, -1);
		if (*((uint32_t*)v3 + 1)) {
			v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10029);
			v6[9] |= 4u;
		}
		if (*((uint32_t*)v3 + 2)) {
			v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10030);
			v7[9] |= 4u;
		}
		if (*((uint32_t*)v3 + 3)) {
			v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10015);
			v8[9] |= 4u;
		}
		if (v3[12] & 2) {
			v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10017);
		} else {
			v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10016);
		}
		v10 = v9;
		v9[9] |= 4u;
		if (*((uint32_t*)v3 + 5)) {
			v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10014);
			v10[9] |= 4u;
		}
		if (*((uint32_t*)v3 + 10)) {
			v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10018);
			v10[9] |= 4u;
		}
		v11 = *getMemU32Ptr(0x5D4594, 1193372 + 4 * v2);
		if (v11) {
			v12 = v11 - 1;
			if (v12) {
				if (v12 == 1) {
					v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10026);
					sub_489DC0();
				}
			} else {
				v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10025);
				nox_window_set_hidden(*(int*)&dword_5d4594_1193384, 1);
			}
		} else {
			v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10024);
			nox_window_set_hidden(*(int*)&dword_5d4594_1193384, 1);
		}
		v10[9] |= 4u;
		result = *(uint32_t**)&dword_5d4594_1193380;
	}
	return result;
}

//----- (00489DC0) --------------------------------------------------------
void sub_489DC0() {
	uint32_t* v0; // eax
	uint32_t* v1; // eax

	nox_window_set_hidden(*(int*)&dword_5d4594_1193384, 0);
	if (nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193384, 10028)->draw_data.field_0 & 4) {
		v0 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193384, 10031);
		nox_xxx_wnd_46ABB0((int)v0, 1);
	} else {
		v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193384, 10031);
		nox_xxx_wnd_46ABB0((int)v1, 0);
	}
	if (nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193384, 10015)->draw_data.field_0 & 4) {
		sub_46AD20(*(uint32_t**)&dword_5d4594_1193384, 10016, 10017, 1);
	} else {
		sub_46AD20(*(uint32_t**)&dword_5d4594_1193384, 10016, 10017, 0);
	}
}

//----- (00489E70) --------------------------------------------------------
int nox_xxx_windowMplayFilterProc_489E70(int a1, int a2, int* a3, int a4) {
	int v3;       // ebx
	int v4;       // esi
	int result;   // eax
	uint32_t* v6; // eax
	int v7;       // [esp-Ch] [ebp-10h]
	int v8;       // [esp-Ch] [ebp-10h]

	v3 = nox_xxx_check_flag_aaa_43AF70();
	if (a2 == 23) {
		return 1;
	}
	if (a2 != 16391) {
		return 0;
	}
	v4 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	switch (v4) {
	case 10015:
		sub_46AD20(*(uint32_t**)&dword_5d4594_1193380, 10016, 10017, ((unsigned int)~a3[9] >> 2) & 1);
		return 0;
	case 10024:
		v7 = dword_5d4594_1193384;
		*getMemU32Ptr(0x5D4594, 1193372 + 4 * v3) = 0;
		nox_window_set_hidden(v7, 1);
		result = 0;
		break;
	case 10025:
		v8 = dword_5d4594_1193384;
		*getMemU32Ptr(0x5D4594, 1193372 + 4 * v3) = 1;
		nox_window_set_hidden(v8, 1);
		result = 0;
		break;
	case 10026:
		*getMemU32Ptr(0x5D4594, 1193372 + 4 * v3) = 2;
		sub_489DC0();
		result = 0;
		break;
	case 10028:
		v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1193380, 10031);
		nox_xxx_wnd_46ABB0((int)v6, ((unsigned int)~a3[9] >> 2) & 1);
		result = 0;
		break;
	default:
		return 0;
	}
	return result;
}

//----- (00489FB0) --------------------------------------------------------
int sub_489FB0() {
	int result; // eax

	result = dword_5d4594_1193380;
	if (dword_5d4594_1193380) {
		sub_489870();
		nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_1193380);
		result = nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1193380);
		dword_5d4594_1193380 = 0;
	}
	return result;
}

//----- (00489FF0) --------------------------------------------------------
int sub_489FF0(int a1, int a2, const void* a3) {
	int result; // eax

	*getMemU32Ptr(0x5D4594, 1193372 + 4 * a1) = a2;
	result = 11 * a1;
	memcpy(getMemAt(0x5D4594, 1193388 + 44 * a1), a3, 0x2Cu);
	return result;
}

//----- (0048A020) --------------------------------------------------------
int sub_48A020(int a1, uint32_t* a2) {
	*a2 = getMemAt(0x5D4594, 1193388 + 44 * a1);
	return *getMemU32Ptr(0x5D4594, 1193372 + 4 * a1);
}

//----- (0048A1D0) --------------------------------------------------------
int nox_video_checkIsWinNT_48A1D0(int a1) {
	int v1; // eax

	if (nox_video_windowsPlatformVersion != 5) // Non-NT
	{
		v1 = *(uint32_t*)&nox_video_renderTargetFlags;
		if (a1) {
			LOBYTE(v1) = nox_video_renderTargetFlags | 0x20;
		} else {
			LOBYTE(v1) = nox_video_renderTargetFlags & 0xDF;
		}
		*(uint32_t*)&nox_video_renderTargetFlags = v1;
		sub_444D00();
	}
	return (*(uint32_t*)&nox_video_renderTargetFlags >> 5) & 1;
}

//----- (0048A210) --------------------------------------------------------
int nox_xxx_setSomeFunc_48A210(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1193504) = a1;
	return result;
}

//----- (0048A5D0) --------------------------------------------------------
int sub_48A5D0() { return 0; }

//----- (0048B3E0) --------------------------------------------------------
int sub_48B3E0(int a1) {
	int result; // eax

	result = dword_5d4594_1193672;
	dword_5d4594_1193672 = a1;
	return result;
}

#ifndef NOX_CGO
//----- (0048B590) --------------------------------------------------------
void sub_48B590(uint32_t* a1, uint32_t* a2, uint32_t* a3) {
	if (a1) {
		*a1 = dword_5d4594_1193624;
	}
	if (a2) {
		*a2 = dword_5d4594_1193648;
	}
	if (a3) {
		*a3 = dword_5d4594_1193524;
	}
}

//----- (0048B680) --------------------------------------------------------
void sub_48B680(int a1) {
	if (a1 != nox_draw_curDrawData_3799572->field_15) {
		if (nox_video_cursorDrawIsThreaded) {
			nox_draw_curDrawData_3799572->field_15 = a1;
		} else {
			nox_draw_curDrawData_3799572->field_14 = a1;
		}
		sub_48BD90(1);
	}
}

//----- (0048B6B0) --------------------------------------------------------
int sub_48B6B0(int a1, int a2, int a3) {
	int result;            // eax
	long long v4;          // rax
	unsigned long long v5; // rax
	unsigned long long v6; // rax

	if (!nox_video_cursorDrawIsThreaded) {
		return sub_433CD0(a1, a2, a3);
	}
	result = (unsigned char)a1;
	nox_draw_curDrawData_3799572->field_34 = (unsigned char)a1;
	nox_draw_curDrawData_3799572->field_35 = (unsigned char)a2;
	nox_draw_curDrawData_3799572->field_36 = (unsigned char)a3;
	if (cpuid_5d4594_3801804) {
		v4 = (unsigned char)a1 | ((unsigned char)a1 << 16);
		HIDWORD(v4) = 0;
		v4 <<= 16;
		LODWORD(v4) = (unsigned char)a1 | (unsigned int)v4;
		v4 <<= 16;
		nox_draw_curDrawData_3799572->field_28 = (unsigned char)a1 | (unsigned int)v4;
		nox_draw_curDrawData_3799572->field_29 = HIDWORD(v4);
		v5 = ((unsigned char)a2 | (((unsigned char)a2 | ((unsigned long long)(unsigned char)a2 << 16)) << 16)) << 16;
		nox_draw_curDrawData_3799572->field_30 = (unsigned char)a2 | (unsigned int)v5;
		nox_draw_curDrawData_3799572->field_31 = HIDWORD(v5);
		v6 = ((unsigned char)a3 | (((unsigned char)a3 | ((unsigned long long)(unsigned char)a3 << 16)) << 16)) << 16;
		nox_draw_curDrawData_3799572->field_32 = (unsigned char)a3 | (unsigned int)v6;
		result = nox_draw_curDrawData_3799572;
		nox_draw_curDrawData_3799572->field_33 = HIDWORD(v6);
	}
	return result;
}

//----- (0048B800) --------------------------------------------------------
int sub_48B800(int a1) {
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	sub_434480(a1, (int)&v3, (int)&v2, (int)&a1);
	return sub_48B6B0(v3, v2, a1);
}
#endif // NOX_CGO

//----- (0048BD90) --------------------------------------------------------
void sub_48BD90(int a1) {
	nox_mutex_lock(getMemAt(0x973F18, 168));
	if (!a1) {
		SetRect((LPRECT)getMemAt(0x5D4594, 1193532), 0, 0, 0, 0);
	}
	dword_5d4594_1193664 = 1;
	dword_5d4594_1193668 = 1;
	dword_5d4594_1193624 = 0;
	nox_mutex_unlock(getMemAt(0x973F18, 168));
}

#ifndef NOX_CGO
//----- (0048BE50) --------------------------------------------------------
int nox_video_mouseThreadXxx_48BE50(int a1) {
	int result; // eax

	result = nox_video_drawCursorThreadOk;
	if (nox_video_drawCursorThreadOk) {
		result = nox_video_cursorDrawIsThreaded;
		if (nox_video_cursorDrawIsThreaded) {
			result = a1;
			nox_video_pauseThreadedDrawCursor = a1;
		}
	}
	return result;
}

//----- (0048BE70) --------------------------------------------------------
int nox_video_createCursorDrawThread_48BE70() {
	nox_video_allowCursorDrawThread = 1;
	nox_video_cursorDrawThreadHandle = _beginthread(nox_video_cursorThreadWorker_48BEB0, 0, 0);
	if (nox_video_cursorDrawThreadHandle != -1) {
		return 1;
	}
	nox_video_cursorDrawThreadHandle = 0;
	return 0;
}

//----- (0048BEB0) --------------------------------------------------------
int nox_video_cursorThreadWorker_48BEB0() {
	int v2; // [esp-14h] [ebp-14h]
	int v3; // [esp-10h] [ebp-10h]
	int v4; // [esp-Ch] [ebp-Ch]

	while (nox_video_allowCursorDrawThread) {
		nox_platform_sleep(33);
		if (!nox_video_pauseThreadedDrawCursor && nox_video_drawCursorThreadOk && dword_5d4594_823776 &&
			dword_5d4594_1193672 && *getMemU32Ptr(0x5D4594, 1193108) && nox_video_bag_ready && !nox_xxx_get_430890()) {
			nox_client_readMouseBuffer_4306A0(0);
			nox_point mpos = nox_client_getMousePos_4309F0();
			if (nox_client_getCursorType_477620() == 10) {
				v3 = mpos.x - 64;
				v4 = mpos.y - 64;
				v2 = sub_477FF0();
				sub_48B3F0(v2, v3, v4);
			} else {
				sub_48B3F0(0, mpos.x - 64, mpos.y - 64);
			}
			nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(1, 1);
		}
	}
	return 0;
}
#endif // NOX_CGO

//----- (0048C0C0) --------------------------------------------------------
int sub_48C0C0(void* a1, uint32_t* a2, uint32_t* a3) {
	int result;   // eax
	uint32_t* v4; // eax
	uint32_t* v5; // eax

	result = nox_video_getImagePixdata_func(a1);
	dword_5d4594_1193516 = result;
	if (result) {
		v4 = (uint32_t*)(result + 8);
		dword_5d4594_1193516 = v4;
		*a2 -= *v4;
		v5 = (uint32_t*)(dword_5d4594_1193516 + 4);
		dword_5d4594_1193516 = v5;
		*a3 -= *v5;
		result = 1;
	}
	return result;
}

#ifndef NOX_CGO
//----- (0048C170) --------------------------------------------------------
void sub_48C170(int4* a1, int4* a2) {
	if (nox_video_renderTargetFlags & 0x10) {
		a1->field_0 = *getMemU32Ptr(0x5D4594, 1193684) * a2->field_0 / nox_backbuffer_width;
		a1->field_8 = *getMemU32Ptr(0x5D4594, 1193684) * a2->field_8 / nox_backbuffer_width;
		a1->field_4 = *getMemU32Ptr(0x5D4594, 1193688) * a2->field_4 / nox_backbuffer_height;
		a1->field_C = *getMemU32Ptr(0x5D4594, 1193688) * a2->field_C / nox_backbuffer_height;
	} else {
		a1->field_0 = a2->field_0;
		a1->field_8 = a2->field_8;
		a1->field_4 = a2->field_4;
		a1->field_C = a2->field_C;
	}
}
#endif // NOX_CGO

//----- (0048C420) --------------------------------------------------------
char sub_48C420() {
	uint8_t* v0;      // esi
	uint8_t* v1;      // edi
	unsigned char v2; // dl
	int v3;           // ecx
	int v4;           // eax
	int v6;           // edx
	int v7;           // edx

	v0 = *(uint8_t**)&dword_5d4594_1193516;
	v1 = *(uint8_t**)&dword_5d4594_1193584;
	v2 = getMemByte(0x5D4594, 1193520);
	v3 = *getMemU32Ptr(0x5D4594, 1193520) >> 2;
	if (*getMemU32Ptr(0x5D4594, 1193520) >> 2) {
		do {
			v4 = *(uint32_t*)v0;
			v0 += 4;
			*(uint32_t*)v1 = v4;
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
	dword_5d4594_1193516 = v0;
	dword_5d4594_1193584 = v1;
	return v4;
}

//----- (0048C480) --------------------------------------------------------
short sub_48C480() {
	int* v0;      // esi
	uint32_t* v1; // edi
	char v2;      // cf
	int v3;       // ecx
	int v4;       // eax

	v0 = *(int**)&dword_5d4594_1193516;
	v1 = *(uint32_t**)&dword_5d4594_1193584;
	v2 = getMemByte(0x5D4594, 1193520) & 1;
	v3 = *getMemU32Ptr(0x5D4594, 1193520) >> 1;
	if (*getMemU32Ptr(0x5D4594, 1193520) >> 1) {
		do {
			v4 = *v0;
			++v0;
			*v1 = v4;
			++v1;
		} while (v3-- > 1);
	}
	if (v2) {
		LOWORD(v4) = *(uint16_t*)v0;
		v0 = (int*)((char*)v0 + 2);
		*(uint16_t*)v1 = v4;
		v1 = (uint32_t*)((char*)v1 + 2);
	}
	dword_5d4594_1193516 = v0;
	dword_5d4594_1193584 = v1;
	return v4;
}
