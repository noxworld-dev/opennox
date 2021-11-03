#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__light__light16.h"
#include "client__shell__wolapi__locale.h"
#include "client__shell__wolapi__wolchat.h"
#include "client__shell__wolapi__woldlgs.h"
#include "client__shell__wolapi__wollogin.h"
#include "client__system__parsecmd.h"
#include "client/audio/ail/compat_mss.h"

#include "client__gui__guicon.h"
#include "client__gui__guiquit.h"
#include "client__gui__window.h"
#include "client__network__cdecode.h"
#include "client__shell__mainmenu.h"
#include "client__shell__noxworld.h"
#include "client__shell__selchar.h"
#include "client__shell__selcolor.h"
#include "client__system__gameloop.h"

#include "MixPatch.h"
#include "client__io__win95__focus.h"
#include "client__system__ctrlevnt.h"
#include "client__video__draw_common.h"
#include "common/fs/nox_fs.h"
#include "common__binfile.h"
#include "common__net_list.h"
#include "common__strman.h"
#include "input_common.h"
#include "mutexes.h"
#include "operators.h"

extern uint32_t dword_587000_122856;
extern uint32_t dword_5d4594_830272;
extern uint32_t dword_5d4594_829532;
extern uint32_t dword_5d4594_830232;
extern uint32_t dword_5d4594_825764;
extern uint32_t dword_5d4594_830200;
extern uint32_t dword_5d4594_830268;
extern uint32_t nox_profiled_805856;
extern uint32_t dword_5d4594_815748;
extern uint32_t dword_5d4594_830196;
extern uint32_t dword_5d4594_830252;
extern uint32_t dword_5d4594_830236;
extern uint32_t dword_587000_109280;
extern uint32_t nox_game_loop_xxx_805872;
extern uint32_t dword_5d4594_830112;
extern uint32_t dword_5d4594_830192;
extern uint32_t dword_5d4594_816444;
extern uint32_t dword_5d4594_830228;
extern uint32_t dword_5d4594_830260;
extern uint32_t dword_5d4594_829544;
extern uint32_t dword_5d4594_816412;
extern uint32_t dword_5d4594_829500;
extern uint32_t nox_client_showTooltips_80840;
extern uint32_t dword_5d4594_830120;
extern uint32_t dword_5d4594_830256;
extern uint32_t dword_5d4594_830204;
extern uint32_t dword_5d4594_825752;
extern uint32_t dword_5d4594_830208;
extern uint32_t dword_587000_111668;
extern uint32_t dword_5d4594_825768;
extern uint32_t dword_5d4594_825736;
extern uint32_t dword_5d4594_2614264;
extern uint32_t dword_5d4594_830292;
extern uint32_t dword_5d4594_816448;
extern uint32_t dword_5d4594_815704;
extern uint32_t nox_xxx_xxxRenderGUI_587000_80832;
extern uint32_t dword_5d4594_826036;
extern uint32_t dword_5d4594_816356;
extern uint32_t dword_5d4594_826032;
extern uint32_t nox_xxx_gameDownloadInProgress_587000_173328;
extern uint32_t nox_client_renderBubbles_80844;
extern uint32_t dword_5d4594_830276;
extern int nox_video_16bit;
extern uint32_t dword_5d4594_830264;
extern uint32_t dword_5d4594_829504;
extern uint32_t dword_5d4594_825744;
extern uint32_t dword_5d4594_816372;
extern uint32_t nox_client_renderGlow_805852;
extern unsigned int nox_gui_console_translucent;
extern uint32_t nox_client_fadeObjects_80836;
extern uint32_t nox_client_lockHighResFloors_1193152;
extern uint32_t dword_5d4594_815708;
extern uint32_t dword_5d4594_816460;
extern uint32_t nox_client_drawFrontWalls_80812;
extern void* dword_587000_81128;
extern uint32_t dword_5d4594_2649712;
extern uint32_t nox_client_translucentFrontWalls_805844;
extern uint64_t qword_5d4594_815724;
extern uint64_t qword_581450_9552;
extern uint64_t qword_581450_9544;
extern uint32_t dword_5d4594_830148;
extern uint32_t dword_5d4594_830116;
extern uint32_t dword_5d4594_816368;
extern uint32_t dword_5d4594_816340;
extern uint32_t dword_5d4594_816488;
extern uint32_t dword_5d4594_815044;
extern uint32_t dword_587000_93156;
extern void* dword_587000_127004;
extern uint32_t dword_5d4594_829484;
extern uint32_t dword_5d4594_814624;
extern uint32_t dword_5d4594_826028;
extern uint32_t nox_client_highResFloors_154952;
extern uint32_t dword_5d4594_2618912;
extern uint32_t dword_5d4594_816452;
extern uint32_t dword_5d4594_816440;
extern uint32_t nox_client_texturedFloors_154956;
extern uint32_t nox_client_highResFrontWalls_80820;
extern uint32_t dword_5d4594_830104;
extern uint32_t dword_5d4594_816456;
extern uint32_t dword_5d4594_830108;
extern uint32_t dword_5d4594_816348;
extern uint32_t dword_5d4594_829488;
extern uint32_t nox_game_createOrJoin_815048;
extern uint32_t nox_client_gui_flag_815132;
extern uint32_t dword_587000_87404;
extern uint32_t dword_587000_87412;
extern uint32_t dword_5d4594_829492;
extern uint32_t dword_5d4594_830248;
extern uint32_t dword_5d4594_829480;
extern uint32_t dword_5d4594_3801780;
extern uint32_t nox_client_renderGUI_80828;
extern nox_window* nox_wnd_quitMenu_825760;
extern uint32_t dword_5d4594_2650652;
extern uint32_t dword_5d4594_830224;
extern uint8_t** nox_pixbuffer_rows_3798784;
extern nox_memfile* nox_loaded_thing_bin;
extern unsigned int nox_frame_xxx_2598000;

extern int nox_win_width;
extern int nox_win_height;

int nox_win_width_game = NOX_DEFAULT_WIDTH;
int nox_win_height_game = NOX_DEFAULT_HEIGHT;
int nox_win_depth_game = NOX_DEFAULT_DEPTH;

#ifndef NOX_CGO
int nox_win_width_menu = NOX_DEFAULT_WIDTH;
int nox_win_height_menu = NOX_DEFAULT_HEIGHT;
int nox_win_depth_menu = NOX_DEFAULT_DEPTH;
#endif // NOX_CGO

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;
extern int nox_backbuffer_depth;
extern int nox_backbuffer_width32;

extern unsigned int nox_gameFPS;

extern nox_video_mode nox_video_modes[];
extern int nox_video_modes_cnt;

extern nox_parse_thing_draw_funcs_t nox_parse_thing_draw_funcs[];
extern int nox_parse_thing_draw_funcs_cnt;

uint32_t dword_5d4594_816364 = 0;
uint32_t dword_5d4594_816376 = 0;
uint32_t dword_5d4594_816092 = 0;
#ifndef NOX_CGO
uint32_t dword_5d4594_816432 = 0;
uint32_t dword_5d4594_816436 = 0;
uint32_t dword_587000_93944 = 0xffffffff;
extern uint32_t nox_game_continueMenuOrHost_93200;
extern uint32_t nox_continue_mainloop_93196;
int (*func_5D4594_816388)(void) = 0;

int (*nox_draw_unk1)(void) = 0;
int (*func_5D4594_816392)(void) = 0;

int nox_game_state_arr[16] = {0};
int nox_game_state_ind = 0;
#endif // NOX_CGO

void (*mainloop_enter)(void*);
void* mainloop_enter_args;
int mainloop_exit_path = 0;

nox_thing* nox_things_head = 0;
nox_thing** nox_things_array = 0;
int nox_things_count = 0;

extern nox_render_data_t* ptr_5D4594_3799572;
nox_render_data_t obj_5D4594_3799660 = {0};
nox_render_data_t obj_5D4594_3800716 = {0};

void (*func_5D4594_830220)(void) = 0;
void (*func_5d4594_830216)(void) = 0;

nox_gui_animation* nox_wnd_xxx_829520 = 0;
nox_gui_animation* nox_wnd_xxx_830244 = 0;

void* nox_draw_defaultFont_816492 = 0;

//----- (0043B510) --------------------------------------------------------
void nox_client_xxx_switchChatMap_43B510() {
	short v0;     // ax
	char* result; // eax
	char* v2;     // edi
	short v5;     // cx
	int v6;       // [esp+0h] [ebp-54h]
	char v7[80];  // [esp+4h] [ebp-50h]

	nox_client_gui_flag_815132 = 0;
	nox_xxx_setGameFlags_40A4D0(5);
	nox_xxx_setMouseBounds_430A70(0, nox_win_width - 1, 0, nox_win_height - 1);
	v6 = *getMemU32Ptr(0x5D4594, 814916);
	if (dword_587000_87404 == 1) {
		v0 = *getMemU16Ptr(0x5D4594, 814916) - *getMemU16Ptr(0x587000, 87528 + 8 * dword_587000_87412);
		HIWORD(v6) -= *getMemU16Ptr(0x587000, 87530 + 8 * dword_587000_87412);
		LOWORD(v6) = v0;
	}
	strcpy(v7, nox_client_getChatMap_49FF40(&v6));
	if (!strchr(v7, '.')) {
		sub_409B50(v7);
		v2 = &v7[strlen(v7) + 1];
		*(uint32_t*)--v2 = *getMemU32Ptr(0x587000, 90856);
		v2[4] = 0;
		if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_WRITE | NOX_ENGINE_FLAG_REPLAY_READ)) {
			nox_xxx_gameSetMapPath_409D70(v7);
		}
		nox_common_gameFlags_unset_40A540(55280);
		nox_xxx_setGameFlags_40A4D0(128);
		result = sub_4165D0(0);
		v5 = *((uint16_t*)result + 26) & 0x280F;
		LOBYTE(v5) = result[52] & 0xF | 0x80;
		*((uint16_t*)result + 26) = v5;
	}
}
// 43B510: using guessed type char var_50[80];

//----- (0043B670) --------------------------------------------------------
uint32_t* sub_43B670() {
	char* v0; // esi

	v0 = sub_416640();
	if (nox_game_createOrJoin_815048) {
		sub_44A400();
		nox_client_xxx_switchChatMap_43B510();
		nox_client_guiXxx_43A9D0();
		nox_client_guiXxxDestroy_4A24A0();
		nox_xxx_gameSetAudioFadeoutMb_501AC0(*(uint32_t*)(v0 + 74));
	} else {
		sub_43B630();
		sub_40D350(*(uint32_t*)(dword_5d4594_814624 + 32));
	}
	return sub_49FF20();
}

//----- (0043B6D0) --------------------------------------------------------
int sub_43B6D0() { return dword_5d4594_815044; }

//----- (0043BC10) --------------------------------------------------------
unsigned short* sub_43BC10(wchar_t* a1, unsigned char a2) {
	const size_t a1_len = nox_wcslen(a1);
	wchar_t* a1_last_char = &a1[a1_len];

	int a1v = 0;
	do {
		nox_xxx_drawGetStringSize_43F840(0, a1, &a1v, 0, 0);
		*a1_last_char = 0;
		--a1_last_char;
	} while (a1v + 5 > a2);

	return a1;
}

//----- (0043BC80) --------------------------------------------------------
int nox_sprintAddrPort_43BC80(const char* addr, unsigned short port, char* dst) {
	return nox_sprintf(dst, "%s:%d", addr, port);
}

//----- (0043BD90) --------------------------------------------------------
int sub_43BD90(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 815092) |= a1;
	return result;
}

//----- (0043BDB0) --------------------------------------------------------
int sub_43BDB0() { return *getMemU32Ptr(0x5D4594, 815092); }

#ifndef NOX_CGO
//----- (0043BDC0) --------------------------------------------------------
void nox_game_decStateInd_43BDC0() { --nox_game_state_ind; }

//----- (0043BDD0) --------------------------------------------------------
void nox_game_addStateCode_43BDD0(int a1) {
	if (nox_game_getStateCode_43BE10() != a1) {
		++nox_game_state_ind;
		nox_game_state_arr[nox_game_state_ind] = a1;
	}
}

//----- (0043BE10) --------------------------------------------------------
int nox_game_getStateCode_43BE10() { return nox_game_state_arr[nox_game_state_ind]; }
#endif // NOX_CGO

//----- (0043BE30) --------------------------------------------------------
int sub_43BE30() { return *getMemU32Ptr(0x5D4594, 815204); }

//----- (0043BE40) --------------------------------------------------------
int sub_43BE40(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 815204) = a1;
	return result;
}

#ifndef NOX_CGO
//----- (0043BE50) --------------------------------------------------------
int sub_43BE50_get_video_mode_id() {
	for (int i = 0; i < nox_video_modes_cnt; i++) {
		nox_video_mode* m = &nox_video_modes[i];
		if (m->width == nox_win_width_game) {
			return m->id;
		}
	}
	return nox_video_modes_cnt;
}
wchar_t* get_video_mode_string(int v1) {
	return ((v1 >= 0 && v1 < nox_video_modes_cnt) ? nox_video_modes[v1].title : L"custom");
}

//----- (0043BE80) --------------------------------------------------------
nox_video_mode* sub_43BE80_video_mode_by_id(int a1) {
	for (int i = 0; i < nox_video_modes_cnt; i++) {
		nox_video_mode* m = &nox_video_modes[i];
		if (m->id == a1) {
			return m;
		}
	}
	return 0;
}

//----- (0043BEB0) --------------------------------------------------------
void nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(int* w, int* h, int* d) {
	if (w) {
		*w = nox_win_width_game;
	}
	if (h) {
		*h = nox_win_height_game;
	}
	if (d) {
		*d = nox_win_depth_game;
	}
}

//----- (0043BEF0) --------------------------------------------------------
void nox_xxx_gameResizeScreen_43BEF0_set_video_mode(int w, int h, int d) {
	d = 16; // 8 bit not supported
	nox_win_width_game = w;
	nox_win_height_game = h;
	nox_win_depth_game = d;

	change_windowed_fullscreen();
}

//----- (0043BF10) --------------------------------------------------------
int nox_xxx_video_43BF10_upd_video_mode(int defaults) {
	int v1;     // esi
	int v2;     // edi
	int v3;     // ebx
	int result; // eax

	// If true, set to 640x480
	if (defaults == 1) {
		v1 = nox_win_width_menu;
		v2 = nox_win_height_menu;
		v3 = nox_win_depth_menu;
	} else {
		v1 = nox_win_width_game;
		v2 = nox_win_height_game;
		v3 = nox_win_depth_game;
	}
	nox_video_resizewnd(v1, v2, v3);
	nox_game_loop_xxx_805872 = 0;
	if (v1 == nox_backbuffer_width && v2 == nox_backbuffer_height && v3 == nox_backbuffer_depth) {
		return 1;
	}
	nox_video_mouseThreadXxx_48BE50(1);
	if (v3 == nox_backbuffer_depth || (result = nox_video_bagMaybeReload(nox_video_16bit)) != 0) {
		result = nox_video_recreateBuffersAndTarget_430BA0();
		if (result) {
			nox_xxx_loadPal_4A96C0_video_read_palette("default.pal");
			sub_461520();
			nox_xxx_setMouseBounds_430A70(0, v1 - 1, 0, v2 - 1);
			nox_video_mouseThreadXxx_48BE50(0);
			return 1;
		}
	}
	return result;
}

//----- (0043BFE0) --------------------------------------------------------
int nox_xxx_cliWaitForJoinData_43BFE0() {
	int result; // eax

	nox_xxx_setGameState_43DDF0(nox_xxx_gameStateWait_43C020);
	nox_game_SetCliDrawFunc(0);
	if (*getMemU32Ptr(0x587000, 91840)) {
		*getMemU32Ptr(0x587000, 91840) = 0;
		nox_client_gui_flag_815132 = 1;
		return 1;
	}
	result = nox_game_switchStates_43C0A0();
	if (!result) {
		return 0;
	}

	nox_client_gui_flag_815132 = 1;
	return 1;
}

//----- (0043C020) --------------------------------------------------------
int nox_xxx_gameStateWait_43C020() {
	++nox_frame_xxx_2598000;
	if (nox_client_gui_flag_815132) {
		return 1;
	}
	nox_xxx_drawSelectColor_434350(*getMemIntPtr(0x85B3FC, 952));
	sub_440900();
	return 0;
}
#endif // NOX_CGO

//----- (0043C060) --------------------------------------------------------
int sub_43C060() {
	nox_xxx_loadPal_4A96C0_video_read_palette("default.pal");
	nox_xxx_wndLoadBorder_4AA1F0();
	nox_xxx_wndLoadMainBG_4A2210();
	nox_client_setCursorType_477610(0);
	sub_48B3E0(1);
	sub_44E040();
	sub_43E8C0(0);
	return nox_xxx_compassGenStrings_4A9C80() != 0;
}

#ifndef NOX_CGO
//----- (0043C0A0) --------------------------------------------------------
int nox_game_switchStates_43C0A0() { // switch game states
	unsigned char si = nox_game_state_ind;
	if (si == 0) {
		return 1;
	}

	unsigned int st = nox_game_state_arr[si];
	switch (st) {
	case 10:
		if (!nox_game_rollLogoAndStart_4AB1F0()) {
			return 0;
		}
		return 1;
	case 100:
		if (!nox_game_showMainMenu_4A1C00()) {
			return 0;
		}
		return 1;
	case 300:
		if (!nox_game_showOptions_4AA6B0()) {
			return 0;
		}
		return 1;
	case 400:
		if (!nox_game_showOnlineOrLAN_413800()) {
			return 0;
		}
		return 1;
	case 500:
		sub_4A7A70(1);
		if (!nox_game_showSelChar_4A4DB0()) {
			return 0;
		}
		return 1;
	case 600:
		if (!nox_game_showSelClass_4A4840()) {
			return 0;
		}
		return 1;
	case 700:
		if (!nox_game_showSelColor_4A5D00()) {
			return 0;
		}
		return 1;
	case 1700:
		if (!nox_game_showWolLogin_44A560()) {
			return 0;
		}
		return 1;
	case 1900:
		if (!nox_game_showWolChat_447620()) {
			return 0;
		}
		return 1;
	case 1915:
		if (!nox_game_showGameSel_4379F0()) {
			return 0;
		}
		return 1;
	case 10000:
		if (nox_xxx_check_flag_aaa_43AF70() == 1 && !sub_40E0B0()) {
			sub_41E300(9);
			sub_41F4B0();
			sub_41EC30();
			sub_446490(0);
			nox_xxx____setargv_4_44B000();
			sub_44A400();
			return 1;
		}
		if (!nox_game_showGameSel_4379F0()) {
			return 0;
		}
		return 1;
	}
	return 1;
}

//----- (0043C1E0) --------------------------------------------------------
void nox_game_checkStateSwitch_43C1E0() {
	if (nox_game_state_ind) {
		uint32_t* v0 = nox_gui_findAnimationForDest_43C520(nox_game_getStateCode_43BE10());
		uint32_t* v1 = v0;
		if (v0) {
			((int (*)(void))v0[12])();
			v1[13] = nox_game_switchStates_43C0A0;
			nox_game_decStateInd_43BDC0();
		}
	}
}

//----- (0043C220) --------------------------------------------------------
void nox_game_checkStateOptions_43C220() {
	if (nox_game_state_ind) {
		uint32_t* result = nox_gui_findAnimationForDest_43C520(nox_game_getStateCode_43BE10());
		uint32_t* v1 = result;
		if (result) {
			result = (uint32_t*)((int (*)(void))result[12])();
			v1[13] = nox_game_showOptions_4AA6B0;
		}
	}
}

//----- (0043C260) --------------------------------------------------------
void nox_game_checkStateWol_43C260() {
	if (nox_game_state_ind) {
		int result = nox_gui_findAnimationForDest_43C520(nox_game_getStateCode_43BE10());
		int v1 = result;
		if (result) {
			if (nox_game_getStateCode_43BE10() == 1700) {
				result = nox_game_showWolLogin_44A560();
			} else {
				result = (*(int (**)(void))(result + 48))();
				*(uint32_t*)(v1 + 52) = nox_game_showWolLogin_44A560;
			}
		}
		while (nox_game_getStateCode_43BE10() != 1700) {
			nox_game_decStateInd_43BDC0();
		}
	}
}

//----- (0043C2F0) --------------------------------------------------------
void nox_game_checkStateMenu_43C2F0() {
	if (nox_game_state_ind) {
		int result = nox_gui_findAnimationForDest_43C520(nox_game_getStateCode_43BE10());
		int v1 = result;
		if (result) {
			if (nox_game_getStateCode_43BE10() == 100) {
				result = nox_game_showMainMenu_4A1C00();
			} else {
				result = (*(int (**)(void))(result + 48))();
				*(uint32_t*)(v1 + 52) = nox_game_showMainMenu_4A1C00;
			}
		}
		while (nox_game_getStateCode_43BE10() != 100) {
			nox_game_decStateInd_43BDC0();
		}
	}
}

//----- (0043C380) --------------------------------------------------------
nox_gui_animation* nox_gui_animationHead_815212 = 0;
void nox_gui_doAnimation_out(nox_gui_animation* a) {
	int x = 0;
	int y = 0;
	nox_gui_getWindowOffs_46AA20(a->win, &x, &y);
	x += a->out_dx;
	y += a->out_dy;

	char maxed = 0;

	int mx = a->x2;
	if (a->out_dx >= 0) {
		if (x >= mx) {
			x = a->x2;
			++maxed;
		}
	} else {
		if (x <= mx) {
			x = a->x2;
			++maxed;
		}
	}

	int my = a->y2;
	if (a->out_dy >= 0) {
		if (y >= my) {
			y = a->y2;
			++maxed;
		}
	} else {
		if (y <= my) {
			y = a->y2;
			++maxed;
		}
	}

	nox_window_setPos_46A9B0(a->win, x, y);
	if (maxed == 2) {
		a->state = NOX_GUI_ANIM_OUT_DONE;
		sub_43BE40(1);
		if (a->fnc_done_out) {
			a->fnc_done_out();
		}
	}
}
void nox_gui_doAnimation_in(nox_gui_animation* a) {
	int x = 0;
	int y = 0;
	nox_gui_getWindowOffs_46AA20(a->win, &x, &y);
	x += a->in_dx;
	y += a->in_dy;

	char maxed = 0;

	int mx = a->x1;
	if (a->in_dx >= 0) {
		if (x >= mx) {
			x = a->x1;
			++maxed;
		}
	} else {
		if (x <= mx) {
			x = a->x1;
			++maxed;
		}
	}

	int my = a->y1;
	if (a->in_dy >= 0) {
		if (y >= my) {
			y = a->y1;
			++maxed;
		}
	} else {
		if (y <= my) {
			y = a->y1;
			++maxed;
		}
	}

	nox_window_setPos_46A9B0(a->win, x, y);
	if (maxed == 2) {
		a->state = NOX_GUI_ANIM_IN_DONE;
		sub_43BE40(0);
		if (a->fnc_done_in) {
			a->fnc_done_in();
		}
		sub_4A24F0();
	}
}
void nox_gui_doAnimation_43C380() {
	if (!nox_gui_animationHead_815212) {
		return;
	}
	nox_gui_animation* next = 0;
	for (nox_gui_animation* a = nox_gui_animationHead_815212; a; a = next) {
		next = a->next;
		if (a->state == NOX_GUI_ANIM_OUT) {
			nox_gui_doAnimation_out(a);
		} else if (a->state == NOX_GUI_ANIM_IN) {
			nox_gui_doAnimation_in(a);
		}
	}
}

//----- (0043C500) --------------------------------------------------------
nox_gui_animation* nox_gui_getAnimationHead_43C500() { return nox_gui_animationHead_815212; }

//----- (0043C510) --------------------------------------------------------
int sub_43C510(int a1) {
	int result; // eax

	if (a1) {
		result = *(uint32_t*)(a1 + 40);
	} else {
		result = 0;
	}
	return result;
}

//----- (0043C520) --------------------------------------------------------
nox_gui_animation* nox_gui_findAnimationForDest_43C520(int a1) {
	nox_gui_animation* p = nox_gui_animationHead_815212;
	if (!p) {
		return 0;
	}
	while (p->field_0 != a1) {
		p = p->next;
		if (!p) {
			return 0;
		}
	}
	return p;
}

//----- (0043C540) --------------------------------------------------------
nox_gui_animation* nox_gui_newAnimation_43C540() {
	nox_gui_animation* p = calloc(1, sizeof(nox_gui_animation));
	if (!p) {
		return 0;
	}
	p->next = nox_gui_animationHead_815212;
	if (nox_gui_animationHead_815212) {
		nox_gui_animationHead_815212->prev = p;
	}
	nox_gui_animationHead_815212 = p;
	return p;
}

//----- (0043C570) --------------------------------------------------------
void nox_gui_freeAnimation_43C570(nox_gui_animation* p) {
	nox_gui_animation* next = p->next;
	if (next) {
		next->prev = p->prev;
	}

	nox_gui_animation* prev = p->prev;
	if (prev) {
		prev->next = p->next;
	} else {
		nox_gui_animationHead_815212 = p->next;
	}
	free(p);
}

//----- (0043C5B0) --------------------------------------------------------
nox_gui_animation* nox_gui_makeAnimation_43C5B0(nox_window* win, int x1, int y1, int x2, int y2, int in_dx, int in_dy,
												int out_dx, int out_dy) {
	nox_gui_animation* p = nox_gui_newAnimation_43C540();
	if (!p) {
		return 0;
	}
	nox_window_setPos_46A9B0(win, x2, y2);
	p->win = win;
	p->x1 = x1;
	p->y1 = y1;
	p->x2 = x2;
	p->y2 = y2;
	p->in_dx = in_dx;
	p->in_dy = in_dy;
	p->out_dx = out_dx;
	p->out_dy = out_dy;
	p->state = NOX_GUI_ANIM_IN;
	sub_43BE40(3);
	nox_xxx_clientPlaySoundSpecial_452D80(922, 100);
	p->field_12 = 0;
	p->fnc_done_out = 0;
	p->fnc_done_in = 0;
	return p;
}
#endif // NOX_CGO

//----- (0043C650) --------------------------------------------------------
int sub_43C650() {
	long long v0;    // kr00_8
	unsigned int v1; // eax
	int v2;          // ett
	int result;      // eax

	v0 = nox_platform_get_ticks();
	v1 = *getMemU32Ptr(0x5D4594, 815756);
	if (*getMemU64Ptr(0x5D4594, 815740)) {
		v2 = ((unsigned int)v0 < *getMemIntPtr(0x5D4594, 815740)) + *getMemU32Ptr(0x5D4594, 815744);
		*getMemU32Ptr(0x5D4594, 815220 + 8 * *getMemU32Ptr(0x5D4594, 815756)) = v0 - *getMemU32Ptr(0x5D4594, 815740);
		*getMemU32Ptr(0x5D4594, 815224 + 8 * v1) = HIDWORD(v0) - v2;
	} else {
		*getMemU32Ptr(0x5D4594, 815220 + 8 * *getMemU32Ptr(0x5D4594, 815756)) = v0;
		*getMemU32Ptr(0x5D4594, 815224 + 8 * v1) = HIDWORD(v0);
	}
	*getMemU64Ptr(0x5D4594, 815756) = (__PAIR64__(*getMemUintPtr(0x5D4594, 815760), v1) + 1) % 0x3C;
	result = dword_5d4594_815748 + 1;
	*getMemU64Ptr(0x5D4594, 815740) = v0;
	++dword_5d4594_815748;
	return result;
}

//----- (0043C6E0) --------------------------------------------------------
int sub_43C6E0() { return !dword_5d4594_815704 && !dword_5d4594_815708; }

//----- (0043C700) --------------------------------------------------------
int nox_client_isConnected_43C700() { return *getMemU32Ptr(0x5D4594, 815764); }

//----- (0043C710) --------------------------------------------------------
int sub_43C710() { return nox_common_gameFlags_check_40A5C0(0x10000000); }

//----- (0043C720) --------------------------------------------------------
int nox_xxx_gameSetCliConnected_43C720(int a1) {
	int result; // eax
	bool v2;    // zf

	result = a1;
	v2 = *getMemU32Ptr(0x5D4594, 815764) == a1;
	*getMemU32Ptr(0x5D4594, 815764) = a1;
	if (!v2 && !a1) {
		nox_xxx_guiServerOptionsHide_4597E0(0);
		result = nox_xxx_cliSetSettingsAcquired_4169D0(0);
	}
	return result;
}

//----- (0043C750) --------------------------------------------------------
int nox_xxx_netGet_43C750() { return *(uint32_t*)getMemAt(0x5D4594, 815700); }

//----- (0043C760) --------------------------------------------------------
int sub_43C760() {
	int v0; // esi

	if (!nox_common_gameFlags_check_40A5C0(1)) {
		return *getMemU32Ptr(0x5D4594, 815712);
	}
	v0 = nox_netlist_sizeByInd_40E9F0(31, 1);
	return v0 + nox_netlist_sizeByInd2_40F0D0(31);
}

//----- (0043C790) --------------------------------------------------------
int sub_43C790() { return *getMemU32Ptr(0x587000, 91876); }

//----- (0043C7A0) --------------------------------------------------------
int sub_43C7A0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x587000, 91876) = a1;
	return result;
}

#ifndef NOX_CGO
//----- (0043C7B0) --------------------------------------------------------
int nox_xxx_netAddNetStruct4Host_43C7B0(char* cp, int hostshort, int a3, signed int* a4) {
	int v5; // eax

	dword_5d4594_815704 = 0;
	dword_5d4594_815708 = 0;

	nox_net_struct_arg_t narg;
	memset(&narg, 0, sizeof(nox_net_struct_arg_t));
	narg.data_size = 2048;
	narg.port = hostshort;
	nox_xxx_allocNetGQueue_5520B0(200, 1024);
	narg.func_yyy = nox_xxx_netHandleCliPacket_43C860;
	unsigned int id = nox_xxx_netPreStructToFull_5546F0(&narg);
	*(uint32_t*)getMemAt(0x5D4594, 815700) = id;
	v5 = sub_554760(id, cp, hostshort, a3, 153);
	OnLibraryNotice_258();
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		dword_5d4594_2649712 |= 0x80000000;
	}
	return 1;
}
#endif // NOX_CGO

//----- (0043C860) --------------------------------------------------------
int nox_xxx_netHandleCliPacket_43C860(int a1, unsigned char* a2, int a3, void* a4) {
	unsigned char v3; // cl
	int v4;           // ecx

	v3 = *a2;
	*getMemU32Ptr(0x5D4594, 815712) = a3;
	if (v3 < 0x27u) {
		v4 = *a2;
		if (v4 == 33) {
			sub_446380();
		} else if (v4 == 36) {
			dword_5d4594_2614264 = *(uint32_t*)(a2 + 1);
		}
	} else {
		nox_xxx_netOnPacketRecvCli_48EA70(31, (unsigned int)a2, a3);
		if (nox_client_isConnected_43C700()) {
			sub_48D660();
		}
	}
	*getMemU64Ptr(0x5D4594, 815716) = nox_platform_get_ticks();
	if (dword_5d4594_815704 == 1) {
		sub_4AB4A0(0);
		dword_5d4594_815704 = 0;
	}
	if (dword_5d4594_815708 == 1) {
		sub_43CF40();
	}
	return 1;
}

#ifndef NOX_CGO
//----- (0043C8F0) --------------------------------------------------------
int nox_xxx_clientSendInput_43C8F0(int a1, int a2, int a3) {
	int v3;     // ebx
	char* v4;   // edi
	int result; // eax
	int v6;     // eax
	char v7;    // [esp+Fh] [ebp-Dh]
	int v8;     // [esp+10h] [ebp-Ch]
	char v9[5]; // [esp+14h] [ebp-8h]

	v3 = nox_xxx_spriteGetMB_476F80();
	v4 = nox_xxx_netGetBuffSize_42CD50(&v8);
	if (!(uint8_t)v8) {
		return 1;
	}
	v7 = 63;
	result = nox_netlist_addToMsgListCli_40EBC0(a1, 0, &v7, 1);
	if (result) {
		result = nox_netlist_addToMsgListCli_40EBC0(a1, 0, &v8, 1);
		if (result) {
			result = nox_netlist_addToMsgListCli_40EBC0(a1, 0, v4, (unsigned char)v8);
			if (result) {
				v6 = v3 ? *(uint32_t*)(v3 + 16) : a3;
				if (a2 == *getMemU16Ptr(0x5D4594, 815768) && v6 == *getMemU16Ptr(0x5D4594, 815770)) {
					return 1;
				}
				*getMemU16Ptr(0x5D4594, 815770) = v6;
				*(uint16_t*)&v9[3] = v6;
				*getMemU16Ptr(0x5D4594, 815768) = a2;
				v9[0] = -84;
				*(uint16_t*)&v9[1] = a2;
				result = nox_netlist_addToMsgListCli_40EBC0(a1, 0, v9, 5);
				if (result) {
					return 1;
				}
			}
		}
	}
	return result;
}

//----- (0043C9F0) --------------------------------------------------------
int nox_xxx_netSendClientReady_43C9F0() {
	char v1; // [esp+1h] [ebp-1h]

	v1 = -64;
	nox_xxx_netSendSock_552640(*(unsigned int*)getMemAt(0x5D4594, 815700), &v1, 1,
							   NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
	return 1;
}

//----- (0043CA20) --------------------------------------------------------
int nox_xxx_netKeepAliveSocket_43CA20() {
	char v1; // [esp+1h] [ebp-1h]

	v1 = -66;
	nox_xxx_netSendSock_552640(*(unsigned int*)getMemAt(0x5D4594, 815700), &v1, 1, NOX_NET_SEND_FLAG2);
	return 1;
}

//----- (0043CA50) --------------------------------------------------------
int nox_xxx_netRequestMap_43CA50() {
	char v1; // [esp+1h] [ebp-1h]

	v1 = -74;
	nox_xxx_netSendSock_552640(*(unsigned int*)getMemAt(0x5D4594, 815700), &v1, 1,
							   NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
	return 1;
}

//----- (0043CA80) --------------------------------------------------------
int nox_xxx_netMapReceived_43CA80() {
	char v1; // [esp+1h] [ebp-1h]

	v1 = -65;
	nox_xxx_netSendSock_552640(*(unsigned int*)getMemAt(0x5D4594, 815700), &v1, 1,
							   NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
	return 1;
}

//----- (0043CAB0) --------------------------------------------------------
int nox_xxx_cliSendCancelMap_43CAB0() {
	char v0; // al
	char v2; // [esp+1h] [ebp-1h]

	v2 = -73;
	v0 = nox_xxx_netSendSock_552640(*(unsigned int*)getMemAt(0x5D4594, 815700), &v2, 1,
									NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
	if (nox_xxx_cliWaitServerResponse_5525B0(*(unsigned int*)getMemAt(0x5D4594, 815700), v0, 20, 6)) {
		return 0;
	}
	nox_netlist_resetByInd_40ED10(31, 0);
	return 1;
}

//----- (0043CB00) --------------------------------------------------------
int nox_xxx_netSendIncomingClient_43CB00() {
	char v0; // al
	char v2; // [esp+1h] [ebp-1h]

	v2 = -83;
	v0 = nox_xxx_netSendSock_552640(*(unsigned int*)getMemAt(0x5D4594, 815700), &v2, 1,
									NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
	if (nox_xxx_cliWaitServerResponse_5525B0(*(unsigned int*)getMemAt(0x5D4594, 815700), v0, 20, 6)) {
		return 0;
	}
	nox_netlist_resetByInd_40ED10(31, 0);
	return 1;
}

//----- (0043CB50) --------------------------------------------------------
int nox_xxx_cliSendOutgoingClient_43CB50() {
	char v0; // al
	char v2; // [esp+1h] [ebp-1h]

	v2 = -82;
	v0 = nox_xxx_netSendSock_552640(*(unsigned int*)getMemAt(0x5D4594, 815700), &v2, 1,
									NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
	if (nox_xxx_cliWaitServerResponse_5525B0(*(unsigned int*)getMemAt(0x5D4594, 815700), v0, 20, 6)) {
		return 0;
	}
	nox_xxx_servNetInitialPackets_552A80(*(unsigned int*)getMemAt(0x5D4594, 815700), 3);
	nox_netlist_resetByInd_40ED10(31, 0);
	return 1;
}

//----- (0043CBB0) --------------------------------------------------------
int sub_43CBB0() {
	nox_xxx_servNetInitialPackets_552A80(*(unsigned int*)getMemAt(0x5D4594, 815700), 1);
	if ((unsigned long long)(nox_platform_get_ticks() - *(uint64_t*)&qword_5d4594_815724) >= 2000) {
		*(uint64_t*)&qword_5d4594_815724 = nox_platform_get_ticks();
		sub_552E70(*(unsigned int*)getMemAt(0x5D4594, 815700));
	}
	nox_xxx_netMaybeSendAll_552460();
	if (!*getMemU32Ptr(0x5D4594, 815720) && !*getMemU32Ptr(0x5D4594, 815716) ||
		(unsigned long long)(nox_platform_get_ticks() - *getMemU64Ptr(0x5D4594, 815716)) <= 20000) {
		return 1;
	}
	sub_43B750();
	return 0;
}

//----- (0043CC60) --------------------------------------------------------
int sub_43CC60(int a1) {
	int result; // eax

	result = a1 == 0;
	*getMemU32Ptr(0x587000, 91872) = a1 == 0;
	return result;
}
#endif // NOX_CGO

//----- (0043CC80) --------------------------------------------------------
int sub_43CC80() {
	int result; // eax

	result = sub_5549F0(*(unsigned int*)getMemAt(0x5D4594, 815700));
	dword_5d4594_2649712 = 0;
	return result;
}

//----- (0043CCA0) --------------------------------------------------------
void sub_43CCA0() {
	int v0;                // esi
	int v1;                // esi
	unsigned long long v2; // rdi
	unsigned long long v3; // rax
	unsigned long long v4; // rax
	unsigned long long v5; // rax

	nox_xxx_spriteDeleteSomeList_49C4B0();
	v0 = nox_frame_xxx_2598000;
	nox_xxx_servNetInitialPackets_552A80(*(unsigned int*)getMemAt(0x5D4594, 815700), 1);
	if (v0 != nox_frame_xxx_2598000 && dword_5d4594_2650652 == 1 && !nox_common_gameFlags_check_40A5C0(1)) {
		v1 = sub_40A710(1);
		if (sub_43C790() > v1) {
			sub_43CEB0();
			v2 = *getMemU64Ptr(0x5D4594, 815740) + *getMemU64Ptr(0x587000, 91880) / (unsigned long long)sub_43C790();
			if (nox_platform_get_ticks() >= v2) {
				char v7[8];
				v7[0] = 40;
				*(uint32_t*)&v7[1] = nox_frame_xxx_2598000 + 1;
				nox_xxx_netOnPacketRecvCli_48EA70(31, (unsigned int)v7, 5);
			}
		}
	}
	v3 = nox_platform_get_ticks() - *(uint64_t*)&qword_5d4594_815724;
	if (v3 >= 2000) {
		*(uint64_t*)&qword_5d4594_815724 = nox_platform_get_ticks();
		sub_552E70(*(unsigned int*)getMemAt(0x5D4594, 815700));
	}
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_netImportant_4E5770(0x1Fu, 0);
	}
	nox_xxx_netSendBySock_40EE10(*(unsigned int*)getMemAt(0x5D4594, 815700), 31, 0);
	nox_netlist_resetByInd_40ED10(31, 0);
	nox_xxx_netMaybeSendAll_552460();
	if (!(*getMemU32Ptr(0x5D4594, 815720) || (*getMemU32Ptr(0x5D4594, 815716) != 0))) {
		return;
	}
	v5 = nox_platform_get_ticks() - *getMemU64Ptr(0x5D4594, 815716);
	if (v5 > 2000 && !dword_5d4594_815704) {
		dword_5d4594_815704 = 1;
		sub_4AB4A0(1);
		*getMemU64Ptr(0x5D4594, 815732) = nox_platform_get_ticks();
	}
	if (!(*getMemU32Ptr(0x5D4594, 815720) || (*getMemU32Ptr(0x5D4594, 815716) != 0))) {
		return;
	}
	v4 = nox_platform_get_ticks() - *getMemU64Ptr(0x5D4594, 815716);
	if (v4 <= 20000) {
		return;
	}
	if (dword_5d4594_815708) {
		return;
	}
	v4 = nox_platform_get_ticks() - *getMemU64Ptr(0x5D4594, 815732);
	if (v4 > 20000) {
		sub_43CF70();
	}
}

//----- (0043CEB0) --------------------------------------------------------
void sub_43CEB0() {
	unsigned int v1;           // esi
	unsigned int v2;           // edi
	unsigned int v3;           // ebx
	unsigned long long v4 = 0; // rax
	unsigned int v5;           // ecx
	int v6;                    // kr00_4
	unsigned int v7;           // kr08_4
	unsigned int v9;           // [esp+0h] [ebp-8h]

	int v0 = dword_5d4594_815748;
	if (*(int*)&dword_5d4594_815748 >= 60) {
		v0 = 60;
	}
	v1 = 0;
	v2 = 0;
	v3 = 0;
	if (!(v0 && v0 > 10)) {
		*getMemU32Ptr(0x587000, 91884) = 0;
		*getMemU32Ptr(0x587000, 91880) = 33;
		return;
	}
	v5 = 0;
	v9 = v0;
	do {
		do {
			v6 = *getMemU32Ptr(0x5D4594, 815220 + 8 * v5) + v2;
			v3 = (__PAIR64__(*getMemU32Ptr(0x5D4594, 815224 + 8 * v5), *getMemU32Ptr(0x5D4594, 815220 + 8 * v5)) +
				  __PAIR64__(v3, v2)) >>
				 32;
			v2 += *getMemU32Ptr(0x5D4594, 815220 + 8 * v5);
			v7 = v5 + 1;
			v1 = (__PAIR64__(v1, v5++) + 1) >> 32;
		} while (v1 < HIDWORD(v4));
		LODWORD(v4) = v9;
	} while (v1 <= HIDWORD(v4) && v7 < v9);
	long long v0a = __PAIR64__(v3, v6) / v4;
	*getMemU64Ptr(0x587000, 91880) = v0a;
}

//----- (0043CF40) --------------------------------------------------------
int sub_43CF40() {
	*getMemU64Ptr(0x5D4594, 815732) = nox_platform_get_ticks();
	dword_5d4594_815708 = 0;
	return sub_4AB4D0(0);
}

//----- (0043CF70) --------------------------------------------------------
int sub_43CF70() {
	int result; // eax
	char v2;    // [esp+1h] [ebp-1h]

	result = dword_5d4594_815708;
	if (!dword_5d4594_815708) {
		sub_4AB4D0(1);
		dword_5d4594_815708 = 1;
		result = *getMemU32Ptr(0x8531A0, 2576);
		if (*getMemU32Ptr(0x8531A0, 2576)) {
			nox_xxx_netNeedTimestampStatus_4174F0(*getMemIntPtr(0x8531A0, 2576), 64);
			v2 = 41;
			result = nox_xxx_netClientSend2_4E53C0(31, &v2, 1, 0, 1);
		}
	}
	return result;
}
// 43CFA0: variable 'v1' is possibly undefined

//----- (0043CFD0) --------------------------------------------------------
int nox_xxx_servNetInitialPacketsCheck_43CFD0() {
	return nox_xxx_servNetInitialPackets_552A80(*(unsigned int*)getMemAt(0x5D4594, 815700), 1) != -1;
}

//----- (0043CFF0) --------------------------------------------------------
int nox_xxx_servNetInitialPacketsUntilCRC_43CFF0() {
	long long start = nox_platform_get_ticks();
	while ((unsigned long long)(nox_platform_get_ticks() - start) < 10000) {
		nox_xxx_servNetInitialPackets_552A80(*(unsigned int*)getMemAt(0x5D4594, 815700), 1);
		nox_xxx_netSendBySock_40EE10(*(unsigned int*)getMemAt(0x5D4594, 815700), 31, 0);
		nox_netlist_resetByInd_40ED10(31, 0);
		nox_xxx_netMaybeSendAll_552460();
		if (nox_xxx_getMapCRC_40A370()) {
			return 1;
		}
	}
	return 0;
}

//----- (0043D2D0) --------------------------------------------------------
void sub_43D2D0() {
	int v1; // esi

	if (dword_5d4594_816340) {
		if (dword_5d4594_816364) {
			sub_486520(getMemUintPtr(0x5D4594, 816244));
			sub_486520(getMemUintPtr(0x5D4594, 816148));
			v1 = *(uint32_t*)((uint32_t)dword_587000_81128 + 4) >> 16;
			if (v1 == *getMemU32Ptr(0x587000, 93168)) {
				if ((unsigned long long)(nox_platform_get_ticks() - *getMemU64Ptr(0x5D4594, 816380)) > 0x32) {
					**(uint32_t**)&dword_587000_81128 &= 0xFFFFFFFD;
					*(uint32_t*)((uint32_t)dword_587000_81128 + 32) &= 0xFFFFFFFD;
					*(uint32_t*)((uint32_t)dword_587000_81128 + 64) &= 0xFFFFFFFD;
				}
			} else {
				*getMemU64Ptr(0x5D4594, 816380) = nox_platform_get_ticks();
				*getMemU32Ptr(0x587000, 93168) = v1;
			}
			if (dword_5d4594_816364) {
				if (**(uint8_t**)&dword_587000_81128 & 2 || getMemByte(0x5D4594, 816148) & 2 ||
					getMemByte(0x5D4594, 816244) & 2) {
					sub_43D3C0(*(int*)&dword_5d4594_816364, *getMemIntPtr(0x5D4594, 816096));
				}
			}
		}
	}
}

//----- (0043D3C0) --------------------------------------------------------
void sub_43D3C0(int a1, int a2) {
	unsigned int v2; // eax

	if (a1) {
		v2 = (*(uint32_t*)((uint32_t)dword_587000_81128 + 4) >> 16) *
			 ((*getMemU16Ptr(0x5D4594, 816154) * ((a2 * (unsigned int)*getMemU16Ptr(0x5D4594, 816250)) >> 14)) >> 14);
		*getMemU32Ptr(0x5D4594, 816148) &= 0xFFFFFFFD;
		*getMemU32Ptr(0x5D4594, 816244) &= 0xFFFFFFFD;
		AIL_set_stream_volume(a1, (int)(127 * (v2 >> 14)) / 100);
	}
}
// 581430: using guessed type int AIL_set_stream_volume(uint32_t, uint32_t);

//----- (0043D440) --------------------------------------------------------
void sub_43D440() {
	int* v0 = getMemIntPtr(0x5D4594, 816108 + 20 * *getMemU32Ptr(0x5D4594, 816352));
	if (!dword_5d4594_816340) {
		return;
	}
	switch (dword_5d4594_816348) {
	case 0:
		if (dword_5d4594_816356 && (dword_587000_93156 != 0)) {
			dword_5d4594_816348 = 3;
		} else {
			if (*v0) {
				if (dword_587000_93156) {
					sub_486320(getMemAt(0x5D4594, 816148), 0x4000);
					if (nox_xxx_musicStartPlay_43D6C0(v0)) {
						dword_5d4594_816348 = 1;
						v0[4] = 1;
					} else {
						*v0 = 0;
					}
				}
			}
		}
		break;
	case 1:
		if (dword_587000_93156 && *v0 == dword_5d4594_816092 && dword_5d4594_816364 &&
			AIL_stream_status(dword_5d4594_816364) != 2) {
			if (dword_5d4594_816356) {
				dword_5d4594_816348 = 4;
				sub_486350((int)getMemAt(0x5D4594, 816148), 0);
			}
		} else {
			dword_5d4594_816348 = 2;
			sub_486350((int)getMemAt(0x5D4594, 816148), 0);
		}
		break;
	case 2:
		if (!dword_5d4594_816364) {
			sub_43D650();
			dword_5d4594_816348 = 0;
		} else {
			if (AIL_stream_status(dword_5d4594_816364) == 2 || !(*getMemU32Ptr(0x5D4594, 816152) & 0xFFFF0000)) {
				sub_43D650();
				dword_5d4594_816348 = 0;
			}
		}
		break;
	case 3:
		if (!dword_5d4594_816356 || (dword_587000_93156 == 0)) {
			if (!dword_587000_93156 || *v0 != dword_5d4594_816092 || !dword_5d4594_816364 ||
				AIL_stream_status(dword_5d4594_816364) == 2) {
				sub_43D650();
				dword_5d4594_816348 = 0;
			} else {
				sub_486350((int)getMemAt(0x5D4594, 816148), 0x4000);
				sub_43D6A0();
				dword_5d4594_816348 = 1;
			}
		}
		break;
	case 4:
		if (dword_5d4594_816364 && (AIL_stream_status(dword_5d4594_816364) != 2)) {
			if (!(*getMemU32Ptr(0x5D4594, 816152) & 0xFFFF0000)) {
				sub_43D680();
				dword_5d4594_816348 = 3;
			}
		} else {
			sub_43D650();
			dword_5d4594_816348 = 0;
		}
		break;
	default:
		break;
	}
}
// 58141C: using guessed type int AIL_stream_status(uint32_t);

#ifndef NOX_CGO
//----- (0043D650) --------------------------------------------------------
void sub_43D650() {
	if (dword_5d4594_816364) {
		AIL_close_stream(dword_5d4594_816364);
		dword_5d4594_816364 = 0;
	}
	dword_5d4594_816092 = 0;
}
// 581418: using guessed type int AIL_close_stream(uint32_t);

//----- (0043D680) --------------------------------------------------------
void sub_43D680() {
	if (dword_5d4594_816364) {
		AIL_pause_stream(dword_5d4594_816364, 1);
	}
}
// 581414: using guessed type int AIL_pause_stream(uint32_t, uint32_t);

//----- (0043D6A0) --------------------------------------------------------
void sub_43D6A0() {
	if (dword_5d4594_816364) {
		AIL_pause_stream(dword_5d4594_816364, 0);
	}
}
// 581414: using guessed type int AIL_pause_stream(uint32_t, uint32_t);

//----- (0043D6C0) --------------------------------------------------------
int nox_xxx_musicStartPlay_43D6C0(int* a1) {
	const char* v1;   // edi
	unsigned char v2; // dl
	char* v3;         // edi
	int v4;           // esi
	char* v5;         // eax
	unsigned int v6;  // kr08_4
	char v8[540];     // [esp+10h] [ebp-21Ch]

	v1 = *(const char**)getMemAt(0x587000, 92792 + 4 * *a1);
	sub_43D650();
	*getMemU32Ptr(0x587000, 93160) = 0;
	if (!dword_5d4594_816376) {
		return 0;
	}
	strcpy(v8, "music\\");
	strcat(v8, v1);
	if (!strchr(v8, 46)) {
		v2 = getMemByte(0x587000, 93184);
		v3 = &v8[strlen(v8)];
		*(uint32_t*)v3 = *getMemU32Ptr(0x587000, 93180);
		v3[4] = v2;
	}
	v4 = AIL_open_stream(dword_5d4594_816376, v8, 204800);
	if (!v4) {
		if (dword_587000_122856 && sub_44D930()) {
			return 0;
		}
		v5 = sub_413890();
		if (!v5) {
			return 0;
		}
		*getMemU32Ptr(0x587000, 93160) = 1;
		strncpy(&v8[40], v5, 0x1F4u);
		v8[539] = 0;
		v6 = strlen(&v8[40]) + 1;
		if (v6 != 1 && v8[v6 + 38] != 92) {
			*(uint16_t*)&v8[strlen(&v8[40]) + 40] = *getMemU16Ptr(0x587000, 93188);
		}
		strcat(&v8[40], v8);
		v4 = AIL_open_stream(dword_5d4594_816376, &v8[40], 204800);
		if (!v4) {
			return 0;
		}
	}
	AIL_set_stream_position(v4, a1[2]);
	sub_486320(getMemAt(0x5D4594, 816148), 0);
	sub_486350((int)getMemAt(0x5D4594, 816148), 0x4000);
	sub_43D3C0(v4, a1[1]);
	AIL_start_stream(v4);
	dword_5d4594_816092 = *a1;
	*getMemU32Ptr(0x5D4594, 816096) = a1[1];
	*getMemU32Ptr(0x5D4594, 816100) = a1[2];
	*getMemU32Ptr(0x5D4594, 816104) = a1[3];
	a1[2] = 0;
	dword_5d4594_816364 = v4;
	return 1;
}
#endif // NOX_CGO
// 581408: using guessed type int AIL_open_stream(uint32_t, uint32_t, uint32_t);
// 58140C: using guessed type int AIL_set_stream_position(uint32_t, uint32_t);
// 581410: using guessed type int AIL_start_stream(uint32_t);

//----- (0043D8E0) --------------------------------------------------------
int sub_43D8E0() {
	int result; // eax
	int v1;     // eax

	if (dword_5d4594_816340) {
		return 1;
	}
	v1 = sub_43F130();
	dword_5d4594_816376 = v1;
	dword_587000_93156 = v1 != 0;
	sub_4864A0(getMemAt(0x5D4594, 816148));
	sub_486380(getMemAt(0x5D4594, 816148), 0x3E8u, 0, 0x4000);
	dword_5d4594_816348 = 0;
	dword_5d4594_816092 = 0;
	*getMemU32Ptr(0x5D4594, 816352) = 0;
	*getMemU32Ptr(0x5D4594, 816108) = 0;
	dword_5d4594_816356 = 0;
	dword_5d4594_816372 = 0;
	dword_5d4594_816368 = 0;
	dword_5d4594_816364 = 0;
	result = 1;
	dword_5d4594_816340 = 1;
	return result;
}

//----- (0043D970) --------------------------------------------------------
#ifndef NOX_CGO
void sub_43D970() {
	if (dword_5d4594_816340) {
		sub_43DCC0();
		dword_5d4594_816340 = 0;
	}
}
#endif // NOX_CGO

//----- (0043D990) --------------------------------------------------------
void sub_43D990() {
	int4 v1; // [esp+0h] [ebp-10h]

	v1.field_0 = 0;
	sub_43D9E0(&v1);
}

//----- (0043D9B0) --------------------------------------------------------
void sub_43D9B0(int a1, int a2) {
	int4 v3; // [esp+0h] [ebp-10h]

	v3.field_0 = a1;
	v3.field_C = 0;
	v3.field_8 = 0;
	v3.field_4 = a2;
	sub_43D9E0(&v3);
}

//----- (0043D9E0) --------------------------------------------------------
void sub_43D9E0(int4* a1) {
	int4* v1; // edx
	int v2;   // ecx

	v1 = (int4*)getMemAt(0x5D4594, 816108 + 20 * (*getMemU32Ptr(0x5D4594, 816352) ^ 1));
	v2 = a1->field_4;
	if (v2 <= 100) {
		if (v2 < 0) {
			a1->field_4 = 0;
		}
	} else {
		a1->field_4 = 100;
	}
	if (*getMemU32Ptr(0x5D4594, 816344)) {
		*(int4*)getMemAt(0x5D4594, 816060) = *a1;
	} else {
		*v1 = *a1;
		v1[1].field_0 = 0;
		*getMemU32Ptr(0x5D4594, 816352) ^= 1u;
	}
}

//----- (0043DA80) --------------------------------------------------------
int sub_43DA80() {
	int result; // eax

	if (*(int*)&dword_5d4594_816368 < 6) {
		sub_43DD10(getMemIntPtr(0x5D4594, 815772 + 16 * (dword_5d4594_816368 + 6 * dword_5d4594_816372)));
		++dword_5d4594_816368;
		result = 1;
	} else {
		dword_5d4594_816368 = 6;
		result = 0;
	}
	return result;
}

//----- (0043DAD0) --------------------------------------------------------
void sub_43DAD0() {
	if (dword_5d4594_816368 > 0) {
		sub_43D9E0((int4*)getMemAt(0x5D4594, 815772 + 16 * (--dword_5d4594_816368 + 6 * dword_5d4594_816372)));
	}
	dword_5d4594_816368 = 0;
}

//----- (0043DB10) --------------------------------------------------------
void sub_43DB10() {
	sub_43D990();
	dword_5d4594_816368 = 0;
}

//----- (0043DB20) --------------------------------------------------------
int sub_43DB20() { return dword_5d4594_816368; }

//----- (0043DB30) --------------------------------------------------------
int sub_43DB30(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_816368 = a1;
	return result;
}

//----- (0043DB40) --------------------------------------------------------
char* sub_43DB40(int a1) { return (char*)getMemAt(0x5D4594, 815772 + 16 * (a1 + 6 * dword_5d4594_816372)); }

//----- (0043DB60) --------------------------------------------------------
int sub_43DB60() {
	int result; // eax
	int v1;     // eax
	int v2;     // ecx

	result = 3;
	if (*(int*)&dword_5d4594_816372 < 3) {
		sub_43DA80();
		v1 = dword_5d4594_816372;
		v2 = dword_5d4594_816368;
		dword_5d4594_816368 = 0;
		*getMemU32Ptr(0x5D4594, 816076 + 4 * dword_5d4594_816372) = v2;
		result = v1 + 1;
		dword_5d4594_816372 = result;
	} else {
		dword_5d4594_816372 = 3;
	}
	return result;
}

//----- (0043DBA0) --------------------------------------------------------
void sub_43DBA0() {
	int v1; // eax
	if (dword_5d4594_816372 > 0) {
		v1 = dword_5d4594_816372 - 1;
		dword_5d4594_816372 = v1;
		dword_5d4594_816368 = *getMemU32Ptr(0x5D4594, 816076 + 4 * v1);
		sub_43DAD0();
	} else {
		dword_5d4594_816372 = 0;
	}
}

//----- (0043DBD0) --------------------------------------------------------
int sub_43DBD0() {
	++dword_5d4594_816356;
	sub_43D440();
	return 0;
}

//----- (0043DBE0) --------------------------------------------------------
int sub_43DBE0() {
	if (--*(int*)&dword_5d4594_816356 < 0) {
		dword_5d4594_816356 = 0;
	}
	sub_43D440();
	return 0;
}

//----- (0043DC00) --------------------------------------------------------
void sub_43DC00() { dword_587000_93156 = 0; }

//----- (0043DC10) --------------------------------------------------------
int sub_43DC10() {
	int result; // eax

	result = dword_5d4594_816376;
	if (dword_5d4594_816376) {
		dword_587000_93156 = 1;
	}
	return result;
}

//----- (0043DC30) --------------------------------------------------------
int sub_43DC30() { return dword_587000_93156; }

//----- (0043DC40) --------------------------------------------------------
int sub_43DC40() {
	int result; // eax

	if (!dword_5d4594_816340 ||
		(result = 1, dword_5d4594_816348 != 1) && dword_5d4594_816348 != 4 && dword_5d4594_816348 != 2) {
		result = 0;
	}
	return result;
}

//----- (0043DC80) --------------------------------------------------------
int sub_43DC80() {
	unsigned char* v0; // eax

	if (dword_587000_93156 && dword_5d4594_816340) {
		while (1) {
			v0 = getMemAt(0x5D4594, 816108 + 20 * *getMemU32Ptr(0x5D4594, 816352));
			if (*(uint32_t*)v0) {
				if (*((uint32_t*)v0 + 4)) {
					break;
				}
			}
			sub_4312C0();
		}
	}
	return 1;
}

//----- (0043DCC0) --------------------------------------------------------
#ifndef NOX_CGO
void sub_43DCC0() {
	if (!dword_587000_93156) {
		return;
	}
	if (!dword_5d4594_816340) {
		return;
	}
	sub_43D990();
	while (dword_5d4594_816348) {
		if (dword_5d4594_816348 == 3) {
			sub_43D650();
			dword_5d4594_816348 = 0;
		}
		sub_4312C0();
#ifdef __EMSCRIPTEN__
		nox_platform_sleep(0x32u);
#endif // __EMSCRIPTEN__
	}
}
#endif // NOX_CGO

//----- (0043DD10) --------------------------------------------------------
int sub_43DD10(int* a1) {
	unsigned char* v1; // ecx
	int result;        // eax

	v1 = getMemAt(0x5D4594, 816108 + 20 * *getMemU32Ptr(0x5D4594, 816352));
	*a1 = *getMemU32Ptr(0x5D4594, 816108 + 20 * *getMemU32Ptr(0x5D4594, 816352));
	a1[1] = *((uint32_t*)v1 + 1);
	a1[2] = *((uint32_t*)v1 + 2);
	a1[3] = *((uint32_t*)v1 + 3);
	result = dword_5d4594_816364;
	if (dword_5d4594_816364) {
		result = *a1;
		if (dword_5d4594_816092 == *a1) {
			result = AIL_stream_position(dword_5d4594_816364);
			a1[2] = result;
		}
	}
	return result;
}
// 581404: using guessed type int AIL_stream_position(uint32_t);

//----- (0043DD70) --------------------------------------------------------
void sub_43DD70(int a1, int a2) {
	sub_43DD10(getMemIntPtr(0x5D4594, 816060));
	sub_43D9B0(a1, a2);
	*getMemU32Ptr(0x5D4594, 816344) = 1;
}

//----- (0043DDA0) --------------------------------------------------------
void sub_43DDA0() {
	*getMemU32Ptr(0x5D4594, 816344) = 0;
	sub_43D9E0((int4*)getMemAt(0x5D4594, 816060));
}

//----- (0043DDD0) --------------------------------------------------------
#ifndef NOX_CGO
void nox_xxx_setContinueMenuOrHost_43DDD0(int v) { nox_game_continueMenuOrHost_93200 = v; }

//----- (0043DDE0) --------------------------------------------------------
void nox_xxx_setFrameLimit_43DDE0(int a1) { *getMemU32Ptr(0x587000, 93192) = a1; }

//----- (0043DDF0) --------------------------------------------------------
int nox_xxx_setGameState_43DDF0(int (*a1)(void)) {
	func_5D4594_816388 = a1;
	if (!a1) {
		func_5D4594_816388 = nox_return_1_43DE10;
	}
	return 1;
}

//----- (0043DE10) --------------------------------------------------------
int nox_return_1_43DE10() { return 1; }

//----- (0043DE20) --------------------------------------------------------
void nox_game_SetCliDrawFunc(int (*fnc)(void)) {
	nox_draw_unk1 = fnc;
	if (!fnc) {
		nox_draw_unk1 = nox_return_1_43DE10;
	}
}

//----- (0043DE40) --------------------------------------------------------
int sub_43DE40(int (*a1)(void)) {
	func_5D4594_816392 = a1;
	if (!a1) {
		func_5D4594_816392 = nox_return_1_43DE10;
	}
	return 1;
}

//----- (0043DE60) --------------------------------------------------------
void nox_game_exit_xxx_43DE60() {
	nox_continue_mainloop_93196 = 0;
	nox_xxx_gameSetCliConnected_43C720(0);
	if (nox_xxx_check_flag_aaa_43AF70() != 1) {
		return;
	}
	if (!nox_common_gameFlags_check_40A5C0(0x2000000)) {
		sub_40D380();
	}
}

int map_download_loop(int first) {
	unsigned char* v1; // eax

	nox_framerate_limit_416C70(30);
	nox_input_pollEvents_4453A0();
	nox_client_processMouseInput_4308A0(1);
	nox_xxx_cursorUpdate_46B740();
	if (nox_xxx_check_flag_aaa_43AF70() == 1) {
		sub_40D250();
		sub_40DF90();
	}
	v1 = nox_xxx_wndKeyGet_430940();
	for (dword_5d4594_2618912 = v1; *v1; dword_5d4594_2618912 = v1) {
		nox_xxx_windowUpdateKeysMB_46B6B0(v1);
		v1 = (dword_5d4594_2618912 + 8);
	}
	sub_43CCA0();
	if (first) {
		nox_xxx_netRequestMap_43CA50();
	}
	if (nox_frame_xxx_2598000 % 0x1Eu) {
		nox_xxx_netKeepAliveSocket_43CA20();
	}

	if (!nox_xxx_gameDownloadInProgress_587000_173328) {
		return map_download_finish();
	}

	nox_gui_draw();
	nox_client_drawCursorAndTooltips_477830();
	nox_xxx_directDrawBlitMB_48A220();
	nox_video_callCopyBackBuffer_4AD170();
	sub_48A290_call_present();

	if (!nox_xxx_gameDownloadInProgress_587000_173328) {
		return map_download_finish();
	}
	return -1;
}
#endif // NOX_CGO

//----- (0043E1A0) --------------------------------------------------------
uint32_t* nox_xxx_gui_43E1A0(int a1) {
	uint32_t* result; // eax

	if (a1) {
		result = nox_window_new(0, 552, 0, 0, nox_win_width, nox_win_height, 0);
		dword_5d4594_816412 = result;
		result[14] = *getMemU32Ptr(0x85B3FC, 952);
	} else {
		result = *(uint32_t**)&dword_5d4594_816412;
		if (dword_5d4594_816412) {
			result = (uint32_t*)nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_816412);
			dword_5d4594_816412 = 0;
		}
	}
	return result;
}

//----- (0043E200) --------------------------------------------------------
int sub_43E200() {
	sub_477530(0);
	nox_xxx_gui_43E1A0(0);
	nox_xxx_setContinueMenuOrHost_43DDD0(0);
	nox_game_exit_xxx_43DE60();
	return sub_44A400();
}

//----- (0043E230) --------------------------------------------------------
int sub_43E230() {
	sub_477530(0);

#ifndef NOX_CGO
	char* map_path_1 = nox_server_get_current_map_path_409B90();
	if (_chmod(map_path_1, 128) == -1) {
		return sub_43E200();
	}

	char* map_path_2 = sub_409C70();
	if (_chmod(map_path_2, 128) == -1) {
		return sub_43E200();
	}
#endif // NOX_CGO

	nox_xxx_setGameFlags_40A4D0(0x100000);
	return sub_44A400();
}

//-------------------------------------------------------------------------
#ifndef NOX_CGO
void mainloop_43E290() {
	nox_continue_mainloop_93196 = 1;
	nox_game_continueMenuOrHost_93200 = 1;
	*getMemU32Ptr(0x5D4594, 816400) = 60 * nox_gameFPS;

	// XXX
	nox_xxx_mapSetDownloadInProgress_4AB560(0);

	mainloop_enter = NULL;
#ifdef __EMSCRIPTEN__
	emscripten_cancel_main_loop();
	emscripten_set_main_loop(mainloop, 0, 0);
	// emscripten_set_main_loop_timing(EM_TIMING_RAF, 2);
	return;
	// never get here
#else  // !__EMSCRIPTEN__
	while (nox_continue_mainloop_93196) {
		mainloop();
	}
#endif // __EMSCRIPTEN__
}
#endif // NOX_CGO
// 43E815: variable 'v18' is possibly undefined
// 4AD170: using guessed type int nox_video_callCopyBackBuffer_4AD170(void);

//----- (0043E8B0) --------------------------------------------------------
int nox_xxx_debugSub_43E8B0() { return *getMemU32Ptr(0x5D4594, 816404); }

//----- (0043E8C0) --------------------------------------------------------
int sub_43E8C0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 816408) = a1;
	return result;
}

#ifndef NOX_CGO
//----- (0043E8E0) --------------------------------------------------------
void sub_43E8E0(int a1) {
	if (dword_5d4594_816432) {
		if (!dword_5d4594_816436) {
			dword_5d4594_816436 = 1;
			AIL_digital_handle_release(dword_5d4594_816432);
		}
	}
}
// 581400: using guessed type int AIL_digital_handle_release(uint32_t);

//----- (0043E910) --------------------------------------------------------
void sub_43E910(int a1) {
	if (dword_5d4594_816432) {
		if (dword_5d4594_816436) {
			AIL_digital_handle_reacquire(dword_5d4594_816432);
			dword_5d4594_816436 = 0;
		}
	}
}
// 5813FC: using guessed type int AIL_digital_handle_reacquire(uint32_t);

//----- (0043E940) --------------------------------------------------------
int sub_43E940(void* a1p) {
	int a1 = a1p;
	nox_on_exit(sub_43E9C0);
	AIL_startup();
	int v1 = AIL_register_timer(sub_43E9D0);
	dword_587000_93944 = v1;
	if (v1 == -1) {
		return 0x80040000;
	}
	AIL_set_timer_frequency(v1, 30);
	AIL_start_timer(dword_587000_93944);
	sub_42EBB0(1u, sub_43E910, 0, "Audio");
	sub_42EBB0(2u, sub_43E8E0, 0, "Audio");
	*(uint32_t*)(a1 + 20) = 1;
	return 0;
}
#endif // NOX_CGO
// 581398: using guessed type int AIL_set_timer_frequency(uint32_t, uint32_t);
// 5813F8: using guessed type int AIL_start_timer(uint32_t);
// 581420: using guessed type uint32_t AIL_startup();
// 581424: using guessed type int AIL_register_timer(uint32_t);

//----- (0043E9C0) --------------------------------------------------------
int sub_43E9C0() {
	sub_43E9F0();
	return 0;
}

//----- (0043E9D0) --------------------------------------------------------
#ifndef NOX_CGO
void sub_43E9D0(unsigned int a1) {
	sub_486EF0();
	sub_43D2D0();
	sub_486620(*(uint32_t**)&dword_587000_127004);
}

//----- (0043E9F0) --------------------------------------------------------
void sub_43E9F0() {
	if (*(int*)&dword_587000_93944 != -1) {
		AIL_stop_timer(dword_587000_93944);
		AIL_release_timer_handle(dword_587000_93944);
		dword_587000_93944 = -1;
	}
	AIL_shutdown();
}
// 5813D0: using guessed type int AIL_release_timer_handle(uint32_t);
// 5813D4: using guessed type int AIL_stop_timer(uint32_t);
// 5813F4: using guessed type uint32_t AIL_shutdown();

//----- (0043EA20) --------------------------------------------------------
int sub_43EA20(void* a1p) {
	int a1 = a1p;
	char v2[16]; // [esp+4h] [ebp-10h]

	sub_43EA90((int)v2, a1 + 60);
	AIL_set_preference(35, 125);
	dword_5d4594_816432 = sub_43EAD0((int)v2);
	if (!dword_5d4594_816432) {
		return -2147221504;
	}
	*getMemU32Ptr(0x587000, 93948) = AIL_get_preference(42);
	*(uint32_t*)(a1 + 196) = 24;
	return 0;
}
// 5813BC: using guessed type int AIL_get_preference(uint32_t);
// 5813C0: using guessed type int AIL_set_preference(uint32_t, uint32_t);

//----- (0043EA90) --------------------------------------------------------
int sub_43EA90(int a1, int a2) {
	int result; // eax

	result = a1;
	*(uint16_t*)a1 = 1;
	*(uint16_t*)(a1 + 2) = *(uint16_t*)(a2 + 12);
	*(uint32_t*)(a1 + 4) = *(uint32_t*)(a2 + 8);
	*(uint32_t*)(a1 + 8) = *(uint32_t*)(a2 + 20);
	*(uint16_t*)(a1 + 12) = *(uint16_t*)(a2 + 16) * *(uint16_t*)(a2 + 12);
	*(uint16_t*)(a1 + 14) = 8 * *(uint16_t*)(a2 + 16);
	return result;
}

//----- (0043EAD0) --------------------------------------------------------
int sub_43EAD0(int a1) {
	int v1;          // eax
	unsigned int v2; // eax
	int v3;          // ecx
	int v5;          // [esp+10h] [ebp-88h]
	int v6;          // [esp+14h] [ebp-84h]
	char v7[128];    // [esp+18h] [ebp-80h]

	v6 = *(uint32_t*)(a1 + 4);
	AIL_set_preference(15, 0);
	AIL_set_preference(33, 1);
	if (*(uint32_t*)(a1 + 4) < 0x2B11u) {
		return 0;
	}
	while (1) {
		while (1) {
			v1 = AIL_get_preference(15);
			if (!AIL_waveOutOpen(&v5, -(v1 != 0), a1)) {
				break;
			}
			AIL_last_error();
			if (!AIL_get_preference(15)) {
				AIL_set_preference(15, 1);
				goto LABEL_11;
			}
			v2 = *(uint32_t*)(a1 + 4) >> 1;
			*(uint32_t*)(a1 + 4) = v2;
			if (v2 < 0x2B11) {
				if (*(uint16_t*)(a1 + 14) == 8) {
					v3 = v6;
					*(uint16_t*)(a1 + 14) = 8;
					*(uint32_t*)(a1 + 4) = v3;
				}
				goto LABEL_11;
			}
		}
		strcpy(v7, "Device: ");
		AIL_digital_configuration(v5, 0, 0, &v7[strlen(v7)]);
		if (AIL_get_preference(15) || !strstr(v7, "Emulated")) {
			return v5;
		}
		AIL_waveOutClose(v5);
		AIL_set_preference(15, 1);
		AIL_set_preference(15, 1);
	LABEL_11:
		if (*(uint32_t*)(a1 + 4) < 0x2B11u) {
			return 0;
		}
	}
}
// 581390: using guessed type int AIL_waveOutClose(uint32_t);
// 581394: using guessed type int AIL_digital_configuration(uint32_t, uint32_t, uint32_t, uint32_t);
// 5813A4: using guessed type uint32_t AIL_last_error();
// 5813BC: using guessed type int AIL_get_preference(uint32_t);
// 5813C0: using guessed type int AIL_set_preference(uint32_t, uint32_t);
// 581434: using guessed type int AIL_waveOutOpen(uint32_t, uint32_t, uint32_t, uint32_t);

//----- (0043EC10) --------------------------------------------------------
int sub_43EC10() {
	int result; // eax

	result = dword_5d4594_816432;
	if (dword_5d4594_816432) {
		AIL_waveOutClose(dword_5d4594_816432);
		dword_5d4594_816432 = 0;
	}
	return result;
}
// 581390: using guessed type int AIL_waveOutClose(uint32_t);

//----- (0043EC30) --------------------------------------------------------
int sub_43EC30(void* a1p) {
	int a1 = a1p;
	uint32_t* v1; // esi
	int v2;       // eax

	v1 = calloc(1, 0x20u);
	memset(v1, 0, 0x20u);
	*(uint32_t*)(a1 + 272) = v1;
	v1[1] = a1;
	*v1 = dword_5d4594_816432;
	v1[5] = calloc(1, 0x4000u);
	v1[6] = calloc(1, 0x4000u);
	v2 = AIL_allocate_sample_handle(dword_5d4594_816432);
	v1[2] = v2;
	if (!v2 || !v1[5] || !v1[6]) {
		return -2147221504;
	}
	AIL_set_sample_user_data(v2, 0, v1);
	return 0;
}
// 58139C: using guessed type int AIL_set_sample_user_data(uint32_t, uint32_t, uint32_t);
// 5813A0: using guessed type int AIL_allocate_sample_handle(uint32_t);

//----- (0043ECB0) --------------------------------------------------------
int sub_43ECB0(void* a1p) {
	int a1 = a1p;
	int v1; // esi

	v1 = *(uint32_t*)(a1 + 272);
	if (*(uint32_t*)(v1 + 8)) {
		AIL_release_sample_handle(*(uint32_t*)(v1 + 8));
	}
	if (*(uint32_t*)(v1 + 20)) {
		free(*(void**)(v1 + 20));
	}
	if (*(uint32_t*)(v1 + 24)) {
		free(*(void**)(v1 + 24));
	}
	free((void*)v1);
	return 0;
}
#endif // NOX_CGO
// 581438: using guessed type int AIL_release_sample_handle(uint32_t);

//----- (0043EDB0) --------------------------------------------------------
void sub_43EDB0(HSAMPLE a1) {
	int v1;     // eax
	int v2;     // esi
	int result; // eax

	v1 = AIL_sample_user_data(a1, 0);
	v2 = v1;
	result = *(uint32_t*)(v1 + 28);
	if (!result) {
		result = (*(int (**)(uint32_t))(*(uint32_t*)(v2 + 4) + 284))(*(uint32_t*)(v2 + 4));
		*(uint32_t*)(v2 + 28) = 1;
	}
}
// 5813A8: using guessed type int AIL_sample_user_data(uint32_t, uint32_t);

#ifndef NOX_CGO
//----- (0043EDE0) --------------------------------------------------------
void sub_43EDE0(HSAMPLE a1) {
	int v1; // eax

	v1 = AIL_sample_user_data(a1, 0);
	sub_43EE00(v1);
}
// 5813A8: using guessed type int AIL_sample_user_data(uint32_t, uint32_t);

//----- (0043ED00) --------------------------------------------------------
int sub_43ED00(uint32_t* a1) {
	uint32_t* v1; // esi
	int v2;       // eax
	int v3;       // eax
	int v4;       // eax
	int v5;       // ecx

	v1 = (uint32_t*)a1[68];
	AIL_init_sample(v1[2]);
	v2 = *(uint32_t*)(a1[72] + 20);
	v1[4] = v2;
	if (!v2) {
		v1[4] = a1[33] + 60;
	}
	v3 = sub_43F0E0((uint32_t*)v1[4]);
	AIL_set_sample_type(v1[2], v3, 0);
	v4 = v1[4];
	if (*(uint32_t*)(v4 + 4) == 2) {
		AIL_set_sample_adpcm_block_size(v1[2], *(uint32_t*)(v4 + 24));
	}
	sub_43F060(a1);
	v5 = v1[2];
	v1[7] = 0;
	v1[3] = 0;
	AIL_register_EOB_callback(v5, sub_43EDE0);
	AIL_register_EOS_callback(v1[2], sub_43EDB0);
	sub_43EE00((int)v1);
	return 0;
}
#endif // NOX_CGO
// 5813AC: using guessed type int AIL_register_EOS_callback(uint32_t, uint32_t);
// 5813B0: using guessed type int AIL_register_EOB_callback(uint32_t, uint32_t);
// 5813B4: using guessed type int AIL_set_sample_adpcm_block_size(uint32_t, uint32_t);
// 5813B8: using guessed type int AIL_set_sample_type(uint32_t, uint32_t, uint32_t);
// 5813F0: using guessed type int AIL_init_sample(uint32_t);

//----- (0043EE00) --------------------------------------------------------
int sub_43EE00(int a1) {
	int v1;           // esi
	int result;       // eax
	int v3;           // ebx
	int v4;           // edi
	char* v5;         // ebp
	unsigned int v6;  // ecx
	signed int v7;    // esi
	signed int v8;    // eax
	char* v9;         // esi
	char v10;         // bp
	unsigned int v11; // ecx
	char* v12;        // edi
	char* v13;        // esi
	int v14;          // ecx
	int v15;          // edx
	int v16;          // eax
	char* v17;        // [esp+4h] [ebp-18h]
	signed int v18;   // [esp+8h] [ebp-14h]
	char* v19;        // [esp+Ch] [ebp-10h]
	int v20;          // [esp+10h] [ebp-Ch]
	int v21;          // [esp+14h] [ebp-8h]
	char* v22;        // [esp+18h] [ebp-4h]

	v1 = a1;
	result = AIL_sample_buffer_ready(*(uint32_t*)(a1 + 8));
	v20 = result;
	if (result != -1) {
		while (1) {
			v3 = *(uint32_t*)(v1 + 4);
			v4 = 0;
			v5 = 0;
			v17 = *(char**)(v1 + 4 * v20 + 20);
			v6 = 0;
			v7 = 0;
			v21 = 0;
			v19 = 0;
			v18 = 0;
			if (!*(uint32_t*)(a1 + 12)) {
				break;
			}
		LABEL_27:
			AIL_load_sample_buffer(*(uint32_t*)(a1 + 8), v20, v19, v4);
			result = AIL_sample_buffer_ready(*(uint32_t*)(a1 + 8));
			v20 = result;
			if (result == -1) {
				return result;
			}
			v1 = a1;
		}
		while (1) {
			if (v4 >= 0x4000) {
				goto LABEL_27;
			}
			v8 = *(uint32_t*)(v3 + 300);
			if (!v8) {
				(*(void (**)(int))(v3 + 276))(v3);
				v8 = *(uint32_t*)(v3 + 300);
				if (!v8) {
					(*(void (**)(int))(v3 + 280))(v3);
					v8 = *(uint32_t*)(v3 + 300);
					if (!v8) {
						*(uint32_t*)(a1 + 12) = 1;
						goto LABEL_27;
					}
				}
				v6 = v18;
			}
			if (v4) {
				break;
			}
			v19 = *(char**)(v3 + 296);
			if (v8 < 0x4000 || v5) {
				break;
			}
			v7 = v8;
		LABEL_24:
			v15 = *(uint32_t*)(v3 + 304) - v7;
			*(uint32_t*)(v3 + 300) -= v7;
			v16 = v7 + *(uint32_t*)(v3 + 296);
			*(uint32_t*)(v3 + 304) = v15;
			*(uint32_t*)(v3 + 296) = v16;
			v4 += v7;
			v21 = v4;
			if (*(uint32_t*)(a1 + 12)) {
				goto LABEL_27;
			}
		}
		if (v8 + v4 > 0x4000) {
			v8 = 0x4000 - v4;
		}
		if (!v8) {
			goto LABEL_24;
		}
		if (v5) {
			if (v6) {
				v9 = v5;
				v10 = v6;
				v11 = v6 >> 2;
				memcpy(v22, v9, 4 * v11);
				v13 = &v9[4 * v11];
				v12 = &v22[4 * v11];
				v19 = v22;
				v14 = v10 & 3;
				v5 = 0;
				memcpy(v12, v13, v14);
			}
		} else if (!v6) {
			v5 = *(char**)(v3 + 296);
			v22 = v17;
			v18 = v8;
		LABEL_23:
			v7 = v8;
			v17 += v8;
			v6 = v18;
			goto LABEL_24;
		}
		memcpy(v17, *(const void**)(v3 + 296), v8);
		v4 = v21;
		goto LABEL_23;
	}
	return result;
}
// 43EF03: variable 'v22' is possibly undefined
// 5813C4: using guessed type int AIL_load_sample_buffer(uint32_t, uint32_t, uint32_t, uint32_t);
// 5813C8: using guessed type int AIL_sample_buffer_ready(uint32_t);

//----- (0043EFD0) --------------------------------------------------------
int sub_43EFD0(int a1) {
	uint32_t* v1; // esi

	v1 = *(uint32_t**)(a1 + 272);
	AIL_end_sample(v1[2]);
	if (!v1[7]) {
		(*(void (**)(uint32_t))(v1[1] + 284))(v1[1]);
		v1[7] = 1;
	}
	return 0;
}
// 5813CC: using guessed type int AIL_end_sample(uint32_t);

#ifndef NOX_CGO
//----- (0043F010) --------------------------------------------------------
int sub_43F010(void* a1p) {
	int a1 = a1p;
	AIL_stop_sample(*(uint32_t*)(*(uint32_t*)(a1 + 272) + 8));
	return 0;
}
// 581428: using guessed type int AIL_stop_sample(uint32_t);

//----- (0043F030) --------------------------------------------------------
int sub_43F030(int a1) {
	AIL_resume_sample(*(uint32_t*)(*(uint32_t*)(a1 + 272) + 8));
	return 0;
}
// 58142C: using guessed type int AIL_resume_sample(uint32_t);

//----- (0043F050) --------------------------------------------------------
int sub_43F050() { return 0; }

//----- (0043F060) --------------------------------------------------------
int sub_43F060(uint32_t* a1) {
	int v1; // esi
	int v2; // eax

	v1 = a1[68];
	AIL_set_sample_volume(*(uint32_t*)(v1 + 8), (unsigned int)(127 * (a1[45] >> 16)) >> 14);
	AIL_set_sample_pan(*(uint32_t*)(v1 + 8), (unsigned int)(127 * (a1[61] >> 16)) >> 14);
	v2 = sub_486640((int)(a1 + 44), *(uint32_t*)(*(uint32_t*)(v1 + 16) + 8));
	AIL_set_sample_playback_rate(*(uint32_t*)(v1 + 8), v2);
	return 0;
}
// 5813D8: using guessed type int AIL_set_sample_playback_rate(uint32_t, uint32_t);
// 5813DC: using guessed type int AIL_set_sample_pan(uint32_t, uint32_t);
// 5813E0: using guessed type int AIL_set_sample_volume(uint32_t, uint32_t);

//----- (0043F0D0) --------------------------------------------------------
int sub_43F0D0() { return 0; }
#endif // NOX_CGO

//----- (0043F0E0) --------------------------------------------------------
int sub_43F0E0(uint32_t* a1) {
	int v1;     // ecx
	int result; // eax
	int v3;     // eax

	v1 = a1[1];
	if (v1) {
		if (v1 == 2) {
			v3 = -(a1[3] != 2);
			LOBYTE(v3) = v3 & 0xFE;
			result = v3 + 7;
		} else {
			result = 0;
		}
	} else if (a1[3] == 2) {
		result = (a1[4] == 2) + 2;
	} else {
		result = a1[4] == 2;
	}
	return result;
}

#ifndef NOX_CGO
//----- (0043F130) --------------------------------------------------------
int sub_43F130() { return dword_5d4594_816432; }

//----- (0043F140) --------------------------------------------------------
void sub_43F140(int a1) {
	int result; // eax
	int v2;     // esi

	if (dword_5d4594_816432) {
		result = AIL_get_preference(34);
		if (result) {
			v2 = a1 / result;
			if (a1 / result > 0) {
				if (v2 > AIL_get_preference(35)) {
					v2 = AIL_get_preference(35);
				}
				AIL_set_preference(42, v2);
				AIL_serve();
			} else {
				AIL_set_preference(42, *getMemU32Ptr(0x587000, 93948));
				AIL_serve();
			}
		}
	}
}
// 5813BC: using guessed type int AIL_get_preference(uint32_t);
// 5813C0: using guessed type int AIL_set_preference(uint32_t, uint32_t);
// 5813E4: using guessed type uint32_t AIL_serve();

//----- (0043F1A0) --------------------------------------------------------
int sub_43F1A0() {
	int result; // eax

	result = dword_5d4594_816432;
	if (dword_5d4594_816432) {
		AIL_set_preference(42, *getMemU32Ptr(0x587000, 93948));
		AIL_serve();
	}
	return result;
}
#endif // NOX_CGO
// 5813C0: using guessed type int AIL_set_preference(uint32_t, uint32_t);
// 5813E4: using guessed type uint32_t AIL_serve();

//----- (0043F1C0) --------------------------------------------------------
int nox_xxx_fontLoadMB_43F1C0() {
	int v0;            // esi
	unsigned char* v1; // eax
	unsigned char* v2; // eax
	int v3;            // ebp
	int v4;            // edi
	int v5;            // ebx

	v0 = 0;
	if (dword_5d4594_3801780) {
		if (dword_5d4594_3801780 == 1) {
			dword_5d4594_816448 = nox_xxx_StringDraw_43FE90;
		}
	} else {
		dword_5d4594_816448 = sub_440360;
	}
	dword_5d4594_816456 = 64;
	*getMemU32Ptr(0x5D4594, 816484) = 1;
	dword_5d4594_816440 = 1;
	dword_5d4594_816460 = 0;
	dword_5d4594_816452 = 0;
	v1 = getMemAt(0x5D4594, 816484);
	dword_5d4594_816444 = 0;
	do {
		v1 -= 4;
		*(uint32_t*)v1 = 0;
	} while (v1 != getMemAt(0x5D4594, 816464));
	if (nox_strman_get_lang_code() == 6 || (v2 = getMemAt(0x587000, 94112), nox_strman_get_lang_code() == 8)) {
		v2 = getMemAt(0x587000, 94176);
	}
	dword_5d4594_816488 = v2;
	v3 = 0;
	do {
		if (*(uint32_t*)&v2[v0 + 4]) {
			v4 = 0;
			if (v0 > 0) {
				v5 = 0;
				while (_strcmpi(*(const char**)&v2[v0 + 4], *(const char**)&v2[v5 + 4])) {
					v2 = *(unsigned char**)&dword_5d4594_816488;
					++v4;
					v5 += 12;
					if (v4 >= v3) {
						goto LABEL_18;
					}
				}
				*(uint32_t*)(v0 + dword_5d4594_816488 + 8) = *(uint32_t*)(dword_5d4594_816488 + 12 * v4 + 8);
				v2 = *(unsigned char**)&dword_5d4594_816488;
			}
		LABEL_18:
			if (*(uint32_t*)&v2[v0 + 4] && !*(uint32_t*)&v2[v0 + 8]) {
				*(uint32_t*)(v0 + dword_5d4594_816488 + 8) = nox_xxx_FontLoadFile_43F3B0(*(char**)&v2[v0 + 4]);
				v2 = *(unsigned char**)&dword_5d4594_816488;
			}
		}
		v0 += 12;
		++v3;
	} while (v0 < 60);
	nox_draw_defaultFont_816492 = *((uint32_t*)v2 + 2);
	return 1;
}

//----- (0043F2E0) --------------------------------------------------------
void nox_xxx_FontDestroy_43F2E0() {
	int v0;       // edi
	void** v1;    // esi
	void* result; // eax
	bool v3;      // zf

	v0 = 0;
	v1 = (void**)getMemAt(0x5D4594, 816464);
	do {
		result = *v1;
		v3 = *v1 == 0;
		*(uint32_t*)(v0 + dword_5d4594_816488 + 8) = 0;
		if (!v3) {
			*v1 = 0;
			nox_xxx_Font_440840(result);
		}
		++v1;
		v0 += 12;
	} while ((int)v1 < (int)getMemAt(0x5D4594, 816484));
}

//----- (0043F320) --------------------------------------------------------
int nox_xxx_guiFontHeightMB_43F320(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = a1;
	result = 0;
	if (a1 || (v1 = nox_draw_defaultFont_816492) != 0) {
		result = *(uint32_t*)(v1 + 28);
	}
	return result;
}

//----- (0043F340) --------------------------------------------------------
int nox_xxx_Font_43F340(int* a1) {
	int* v1;    // ecx
	int result; // eax

	v1 = a1;
	result = 0;
	if (a1 || (v1 = *(int**)&nox_draw_defaultFont_816492) != 0) {
		result = *v1;
	}
	return result;
}

//----- (0043F360) --------------------------------------------------------
int nox_xxx_guiFontPtrByName_43F360(char* a1) {
	int v1;         // edi
	int v2;         // esi
	const char* v3; // eax

	if (!dword_5d4594_816488) {
		return 0;
	}
	v1 = 0;
	v2 = 0;
	while (1) {
		v3 = *(const char**)(v2 + dword_5d4594_816488);
		if (v3) {
			if (!_strcmpi(v3, a1)) {
				break;
			}
		}
		v2 += 12;
		++v1;
		if (v2 >= 60) {
			return 0;
		}
	}
	return *(uint32_t*)(dword_5d4594_816488 + 12 * v1 + 8);
}

//----- (0043F3B0) --------------------------------------------------------
uint32_t* nox_xxx_FontLoadFile_43F3B0(char* a1) {
	uint32_t* v1;          // ebx
	FILE* v3;              // ebp
	char* v4;              // eax
	unsigned short v5;     // cx
	unsigned short v6;     // dx
	int v7;                // eax
	unsigned char* v8;     // eax
	size_t v9;             // esi
	char* v10;             // eax
	int v11;               // ecx
	unsigned char* v12;    // eax
	int v13;               // eax
	uint8_t* v14;          // eax
	uint8_t* v15;          // esi
	uint8_t* v16;          // eax
	int v17[7];            // [esp+4h] [ebp-68h]
	unsigned char v18[76]; // [esp+20h] [ebp-4Ch]

	v1 = 0;
	if (*(int*)&dword_5d4594_816444 >= 5) {
		return 0;
	}
	v3 = nox_fs_open(a1);
	if (v3) {
		v1 = calloc(1, 0x20u);
		if (v1) {
			memset(v1, 0, 0x20u);
			if (nox_binfile_fread_raw_40ADD0((char*)v17, 0x1Cu, 1u, v3) != 1) {
				goto LABEL_15;
			}
			if (v17[0] == 1181699700) {
				v1[2] = v17[4];
				v1[1] = v17[3];
				*v1 = v17[2];
				v1[5] = v17[6];
				v1[3] = v17[5];
				v4 = (char*)calloc(v17[5], 8);
				v1[4] = v4;
				if (!v4 || nox_binfile_fread_raw_40ADD0(v4, 8 * v1[3], 1u, v3) != 1) {
					goto LABEL_15;
				}
			} else {
				nox_fs_fseek_start(v3, 0);
				if (nox_binfile_fread_raw_40ADD0((char*)v18, 0x4Cu, 1u, v3) != 1) {
					goto LABEL_15;
				}
				v5 = *(uint16_t*)&v18[2];
				v6 = *(uint16_t*)v18;
				v1[2] = *(unsigned short*)&v18[4];
				v1[5] = *(uint32_t*)&v18[72];
				v7 = *(unsigned short*)&v18[6];
				v1[1] = v5;
				*v1 = v6;
				v1[3] = v7;
				v8 = (unsigned char*)calloc(v7, 8);
				v1[4] = v8;
				if (!v8) {
					goto LABEL_15;
				}
				memcpy(v8, &v18[8], 8 * v1[3]);
			}
			v1[7] = v1[2];
			v9 = v1[5] * nox_xxx_fontLoad_440870((int)v1);
			v10 = (char*)calloc(1, v9);
			v1[6] = v10;
			if (!v10 || nox_binfile_fread_raw_40ADD0(v10, v9, 1u, v3) != 1) {
			LABEL_15:
				nox_xxx_Font_440840(v1);
				nox_fs_close(v3);
				return 0;
			}
			v11 = 0;
			v12 = getMemAt(0x5D4594, 816464);
			while (*(uint32_t*)v12) {
				v12 += 4;
				++v11;
				if ((int)v12 >= (int)getMemAt(0x5D4594, 816484)) {
					goto LABEL_21;
				}
			}
			v13 = dword_5d4594_816444;
			*getMemU32Ptr(0x5D4594, 816464 + 4 * v11) = v1;
			dword_5d4594_816444 = v13 + 1;
		LABEL_21:
			if (*(unsigned char**)&dword_5d4594_816488 == getMemAt(0x587000, 94176)) {
				++v1[7];
				v14 = (uint8_t*)nox_xxx_FontGetChar_43FE30((int)v1, 0x20u);
				v15 = v14;
				if (v14 && nox_strman_get_lang_code() == 8) {
					++*v14;
				}
				if (nox_strman_get_lang_code() == 6) {
					v16 = (uint8_t*)nox_xxx_FontGetChar_43FE30((int)v1, 0x3000u);
					if (v16) {
						if (v15) {
							*v16 = 2 * *v15;
							nox_fs_close(v3);
							return v1;
						}
						*v16 = *(uint8_t*)v1;
					}
				}
			}
		}
		nox_fs_close(v3);
	}
	return v1;
}

//----- (0043F620) --------------------------------------------------------
int sub_43F620(void* lpMem) {
	int v1;    // ecx
	void** v2; // eax

	if (!lpMem) {
		return 0;
	}
	v1 = 0;
	v2 = (void**)getMemAt(0x5D4594, 816464);
	while (*v2 != lpMem) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 816484)) {
			return 0;
		}
	}
	*getMemU32Ptr(0x5D4594, 816464 + 4 * v1) = 0;
	nox_xxx_Font_440840(lpMem);
	--dword_5d4594_816444;
	return 1;
}

//----- (0043F670) --------------------------------------------------------
int sub_43F670(int a1) {
	int result; // eax

	result = dword_5d4594_816452;
	dword_5d4594_816452 = a1;
	return result;
}

//----- (0043F680) --------------------------------------------------------
int sub_43F680(int a1) {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 816484);
	*getMemU32Ptr(0x5D4594, 816484) = a1;
	return result;
}

//----- (0043F690) --------------------------------------------------------
int sub_43F690(int a1, int a2, int a3, int a4) {
	int result; // eax

	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING)) {
		return a3;
	}
	result = a1;
	if (a1 || (result = nox_draw_defaultFont_816492) != 0) {
		dword_5d4594_816460 = a3;
		result = (*(int (**)(uint32_t, uint32_t, uint32_t, uint32_t)) & dword_5d4594_816448)(result, a2, a3, a4);
	}
	return result;
}

//----- (0043F6E0) --------------------------------------------------------
int nox_xxx_drawString_43F6E0(int a1, wchar_t* a2, int a3, int a4) {
	int result; // eax

	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING)) {
		return a3;
	}
	result = a1;
	if (a1 || (result = nox_draw_defaultFont_816492) != 0) {
		dword_5d4594_816460 = a3;
		result = nox_xxx_guiDrawString_4407F0(result, a2, a3, a4);
	}
	return result;
}

//----- (0043F730) --------------------------------------------------------
int sub_43F730(int a1, short* a2, int a3, int a4) {
	int v5; // edi
	int v6; // ebx

	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING)) {
		return a3;
	}
	v5 = a1;
	if (!a1) {
		v5 = nox_draw_defaultFont_816492;
		if (!nox_draw_defaultFont_816492) {
			return 0;
		}
	}
	dword_5d4594_816460 = a3;
	v6 = ptr_5D4594_3799572->field_59;
	nox_xxx_drawSetTextColor_434390(ptr_5D4594_3799572->field_60);
	nox_xxx_guiDrawString_4407F0(v5, a2, a3 + 1, a4 + 1);
	nox_xxx_drawSetTextColor_434390(v6);
	return nox_xxx_guiDrawString_4407F0(v5, a2, a3, a4);
}

//----- (0043F7B0) --------------------------------------------------------
int sub_43F7B0(int a1, short* a2, int a3, int a4) {
	int result; // eax
	int v5;     // esi

	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING)) {
		return a3;
	}
	v5 = a1;
	if (!a1) {
		v5 = nox_draw_defaultFont_816492;
		if (!nox_draw_defaultFont_816492) {
			return 0;
		}
	}
	dword_5d4594_816460 = a3;
	if (!*getMemU32Ptr(0x5D4594, 816484)) {
		return nox_xxx_guiDrawString_4407F0(v5, a2, a3, a4);
	}
	dword_5d4594_816440 = 2;
	nox_xxx_guiDrawString_4407F0(v5, a2, a3, a4);
	result = nox_xxx_guiDrawString_4407F0(v5, a2, a3 + 1, a4);
	dword_5d4594_816440 = 1;
	return result;
}

//----- (0043F840) --------------------------------------------------------
int nox_xxx_drawGetStringSize_43F840(int a1, unsigned short* a2, int* a3, int* a4, int a5) {
	unsigned short v5;  // cx
	unsigned short v6;  // bp
	int v7;             // ebx
	int v8;             // esi
	unsigned short* v9; // edi
	unsigned char* v10; // eax
	int v11;            // eax
	int v12;            // esi
	int result;         // eax
	unsigned short* i;  // [esp+4h] [ebp-8h]
	int v15;            // [esp+8h] [ebp-4h]
	int v16;            // [esp+14h] [ebp+8h]

	v5 = 0;
	if ((a1 || (a1 = nox_draw_defaultFont_816492) != 0) && a2) {
		v6 = *a2;
		v7 = 0;
		v8 = 0;
		v9 = a2 + 1;
		v16 = *(uint32_t*)(a1 + 28);
		for (i = 0; v6; ++v9) {
			switch (v6) {
			case 9u:
				v8 = dword_5d4594_816456 + v8 - (dword_5d4594_816456 + v8) % dword_5d4594_816456;
				break;
			case 0xAu:
			case 0xDu:
				if (v5 != 13) {
					goto LABEL_7;
				}
				break;
			case 0x20u:
				v15 = v7;
				i = v9;
				goto LABEL_10;
			default:
			LABEL_10:
				v10 = (unsigned char*)nox_xxx_FontGetChar_43FE30(a1, v6);
				if (v10 || (v10 = (unsigned char*)nox_xxx_FontGetChar_43FE30(a1, 0x3Fu)) != 0) {
					v11 = *v10;
					v8 += v11 + dword_5d4594_816440;
					if (a5 && v8 > a5) {
						if (i) {
							v7 = v15;
							v9 = i;
							i = 0;
						} else {
							--v9;
							v12 = v8 - (dword_5d4594_816440 + v11);
							if (v12 > v7) {
								v7 = v12;
							}
						}
					LABEL_7:
						v8 = 0;
						v16 += *(uint32_t*)(a1 + 28);
					} else if (v8 > v7) {
						v7 = v8;
					}
				}
				break;
			}
			v5 = v6;
			v6 = *v9;
		}
		if (a3) {
			*a3 = v7;
		}
		if (a4) {
			*a4 = v16;
		}
		result = 1;
	} else {
		if (a4) {
			*a4 = 0;
		}
		if (a3) {
			*a3 = 0;
		}
		result = 0;
	}
	return result;
}
// 43F936: variable 'v15' is possibly undefined

//----- (0043F9E0) --------------------------------------------------------
int sub_43F9E0(int a1, unsigned short* a2, int a3) {
	int v3;            // ebx
	int v4;            // ebp
	int v5;            // edi
	unsigned short v6; // cx
	unsigned short* i; // esi
	unsigned char* v8; // eax

	v3 = a1;
	v4 = 0;
	v5 = 0;
	if (!a1) {
		v3 = nox_draw_defaultFont_816492;
		if (!nox_draw_defaultFont_816492) {
			return 0;
		}
	}
	if (!a2) {
		return 0;
	}
	v6 = *a2;
	for (i = a2 + 1; v6; ++i) {
		if (v6 == 9) {
			v5 = dword_5d4594_816456 + v5 - (dword_5d4594_816456 + v5) % dword_5d4594_816456;
		} else if (v6 != 10 && v6 != 13) {
			v8 = (unsigned char*)nox_xxx_FontGetChar_43FE30(v3, v6);
			if (v8 || (v8 = (unsigned char*)nox_xxx_FontGetChar_43FE30(v3, 0x3Fu)) != 0) {
				v5 += dword_5d4594_816440 + *v8;
			}
		}
		if (v5 > a3) {
			break;
		}
		v6 = *i;
		++v4;
	}
	return v4;
}

//----- (0043FA80) --------------------------------------------------------
int nox_xxx_bookGetStringSize_43FA80(int a1, unsigned short* a2, int* a3, uint32_t* a4, int a5) {
	int result; // eax

	if (!*getMemU32Ptr(0x5D4594, 816484)) {
		return nox_xxx_drawGetStringSize_43F840(a1, a2, a3, a4, a5);
	}
	dword_5d4594_816440 = 2;
	result = nox_xxx_drawGetStringSize_43F840(a1, a2, a3, a4, a5);
	dword_5d4594_816440 = 1;
	return result;
}

#ifndef NOX_CGO
//----- (0043FAF0) --------------------------------------------------------
int nox_xxx_drawString_43FAF0(void* a1, wchar_t* str, int a3, int a4, int a5, int a6) {
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING)) {
		return a3;
	}
	if (!a1) {
		a1 = nox_draw_defaultFont_816492;
		if (!a1) {
			return 0;
		}
	}
	if (!str) {
		return 0;
	}
	dword_5d4594_816460 = a3;
	wchar_t c = str[0];
	if (!c) {
		return 1;
	}
	int v11 = 0;
	int v21 = 0;
	wchar_t c2 = 0;
	wchar_t* str2 = str;
	wchar_t* str3 = str;
	wchar_t* str4 = 0;
	while (1) {
		switch (c) {
		case '\t':;
			int v16 = dword_5d4594_816456 + v11;
			v11 = v16 - v16 % dword_5d4594_816456;
			break;
		case '\n':
		case '\r':
			if (c2 == 13) {
				++str3;
				break;
			}
			for (int i = a3; str3 < str2;
				 i = (*(int (**)(uint32_t, uint32_t, uint32_t, uint32_t)) & dword_5d4594_816448)(a1, c2, i, a4)) {
				c2 = *str3;
				++str3;
			}
			int v14j = *(uint32_t*)((unsigned int)a1 + 28);
			v11 = 0;
			v21 += v14j;
			if (a6 && v21 >= a6) {
				return 1;
			}
			a4 += v14j;
			++str3;
			break;
		case ' ':
			str4 = str2;
		default:;
			int v14p = nox_xxx_FontGetChar_43FE30(a1, c);
			if (!v14p) {
				v14p = nox_xxx_FontGetChar_43FE30(a1, '?');
				if (!v14p) {
					break;
				}
			}
			v11 += dword_5d4594_816440 + *(unsigned char*)v14p;
			if (!a5 || v11 <= a5) {
				break;
			}
			if (str4) {
				str2 = str4;
			} else {
				--str2;
			}
			wchar_t v17c = 0;
			for (int j = a3; str3 < str2;
				 j = (*(int (**)(uint32_t, uint32_t, uint32_t, uint32_t)) & dword_5d4594_816448)(a1, v17c, j, a4)) {
				v17c = *str3;
				++str3;
			}
			if (str4) {
				str4 = 0;
				++str3;
			}
			int v14i = *(uint32_t*)((unsigned int)a1 + 28);
			v11 = 0;
			v21 += v14i;
			if (a6 && v21 >= a6) {
				return 1;
			}
			a4 += v14i;
			break;
		}
		c2 = c;
		++str2;
		c = str2[0];
		if (!c) {
			break;
		}
	}
	for (int v19 = a3; str3 < str2;
		 v19 = (*(int (**)(uint32_t, uint32_t, uint32_t, uint32_t)) & dword_5d4594_816448)(a1, c2, v19, a4)) {
		c2 = *str3;
		++str3;
	}
	return 1;
}
#endif // NOX_CGO

//----- (0043FD00) --------------------------------------------------------
int sub_43FD00(int a1, uint16_t* a2, int a3, int a4, int a5, int a6) {
	int v7; // edi

	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING)) {
		return a3;
	}
	dword_5d4594_816460 = a3;
	v7 = ptr_5D4594_3799572->field_59;
	nox_xxx_drawSetTextColor_434390(ptr_5D4594_3799572->field_60);
	nox_xxx_drawString_43FAF0(a1, a2, a3 + 1, a4 + 1, a5, a6);
	nox_xxx_drawSetTextColor_434390(v7);
	return nox_xxx_drawString_43FAF0(a1, a2, a3, a4, a5, a6);
}

//----- (0043FD80) --------------------------------------------------------
int nox_xxx_bookDrawString_43FA80_43FD80(int a1, uint16_t* a2, int a3, int a4, int a5, int a6) {
	int result; // eax

	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING)) {
		return a3;
	}
	dword_5d4594_816460 = a3;
	if (!*getMemU32Ptr(0x5D4594, 816484)) {
		return nox_xxx_drawString_43FAF0(a1, a2, a3, a4, a5, a6);
	}
	dword_5d4594_816440 = 2;
	nox_xxx_drawString_43FAF0(a1, a2, a3, a4, a5, a6);
	result = nox_xxx_drawString_43FAF0(a1, a2, a3 + 1, a4, a5, a6);
	dword_5d4594_816440 = 1;
	return result;
}

//----- (0043FE20) --------------------------------------------------------
int sub_43FE20(int a1) {
	int result; // eax

	result = dword_5d4594_816456;
	dword_5d4594_816456 = a1;
	return result;
}

//----- (0043FE30) --------------------------------------------------------
void* nox_xxx_FontGetChar_43FE30(void* font, unsigned short a2) {
	int a1 = font;
	int v2;     // edx
	int result; // eax
	int v4;     // esi

	v2 = *(uint32_t*)(a1 + 16);
	result = 0;
	v4 = 0;
	if ((int)*(unsigned short*)(a1 + 12) > 0) {
		while (a2 < *(uint16_t*)(v2 + 4) || a2 > *(uint16_t*)(v2 + 6)) {
			v2 += 8;
			if (++v4 >= *(unsigned short*)(a1 + 12)) {
				return result;
			}
		}
		result = *(uint32_t*)(a1 + 24) + *(uint32_t*)(a1 + 20) * (*(uint32_t*)v2 + a2 - *(unsigned short*)(v2 + 4));
	}
	return result;
}

//----- (0043FE90) --------------------------------------------------------
int nox_xxx_StringDraw_43FE90(void* font, short a2, int xLeft, int yTop) {
	int a1 = font;
	int v4;            // edx
	int v5;            // ebp
	int v7;            // edi
	unsigned char* v8; // eax
	short v9;          // ax
	int v10;           // esi
	int v11;           // ebx
	int v12;           // ebp
	int v13;           // edi
	int v14;           // ebx
	int v15;           // edx
	int v16;           // ebp
	int v17;           // esi
	uint16_t* v18;     // eax
	char* v19;         // ebp
	int v20;           // ecx
	char v21;          // dl
	uint16_t* v22;     // eax
	int v23;           // ecx
	int v24;           // esi
	uint16_t* v25;     // eax
	int v26;           // ecx
	int v27;           // esi
	uint16_t* v28;     // eax
	int v29;           // ecx
	int v30;           // esi
	uint16_t* v31;     // eax
	int v32;           // ecx
	int v33;           // esi
	uint16_t* v34;     // eax
	int v35;           // ecx
	int v36;           // esi
	uint16_t* v37;     // eax
	int v38;           // ecx
	int v39;           // esi
	uint16_t* v40;     // eax
	int v41;           // ecx
	int v42;           // esi
	bool v43;          // zf
	int v44;           // eax
	int v45;           // esi
	int v46;           // edi
	char* v47;         // esi
	uint16_t* v48;     // eax
	int v49;           // ecx
	char v50;          // dl
	uint16_t* v51;     // eax
	int v52;           // ecx
	uint16_t* v53;     // eax
	int v54;           // ecx
	uint16_t* v55;     // eax
	int v56;           // ecx
	uint16_t* v57;     // eax
	int v58;           // ecx
	uint16_t* v59;     // eax
	int v60;           // ecx
	uint16_t* v61;     // eax
	int v62;           // ecx
	uint16_t* v63;     // eax
	int v64;           // ecx
	int v65;           // [esp+10h] [ebp-38h]
	int v66;           // [esp+10h] [ebp-38h]
	int v67;           // [esp+14h] [ebp-34h]
	int v68;           // [esp+18h] [ebp-30h]
	int v69;           // [esp+18h] [ebp-30h]
	int v70;           // [esp+1Ch] [ebp-2Ch]
	int v71;           // [esp+24h] [ebp-24h]
	int4 v72;          // [esp+28h] [ebp-20h]
	RECT rc;           // [esp+38h] [ebp-10h]

	v5 = yTop;
	v71 = yTop;
	if (a2 == 9) {
		return dword_5d4594_816456 + xLeft - (dword_5d4594_816456 + xLeft - dword_5d4594_816460) % dword_5d4594_816456;
	}
	v7 = a1;
	LOWORD(v4) = *(uint16_t*)(&ptr_5D4594_3799572->field_59);
	yTop = v4;
	v8 = (unsigned char*)nox_xxx_FontGetChar_43FE30(a1, a2);
	if (!v8) {
		v9 = sub_4408A0(&yTop);
		a2 = v9;
		v8 = (unsigned char*)nox_xxx_FontGetChar_43FE30(a1, v9);
		if (!v8) {
			return xLeft;
		}
	}
	v10 = *(uint32_t*)(a1 + 8);
	v11 = xLeft;
	v65 = (int)(v8 + 1);
	v67 = *v8;
	if (!ptr_5D4594_3799572->flag_0) {
		goto LABEL_102;
	}
	SetRect(&rc, xLeft, v5, xLeft + *v8, v10 + v5);
	if (!nox_xxx_utilRect_49F930(&v72, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->clip))) {
		return v11 + dword_5d4594_816440 + v67;
	}
	if (rc.left == v72.field_0 && rc.right == v72.field_8 && rc.top == v72.field_4 && rc.bottom == v72.field_C) {
	LABEL_102:
		v44 = v10;
		v45 = v10 - 1;
		if (v44) {
			v46 = 4 * v5;
			v69 = v45 + 1;
			while (1) {
				v47 = (char*)v65;
				v48 = (uint16_t*)(2 * v11 + (uint32_t)nox_pixbuffer_rows_3798784[v46 / 4]);
				v49 = v67;
				v46 += 4;
				while (1) {
					v50 = *v47++;
					if (v50) {
						break;
					}
					v48 += 8;
					v49 -= 8;
				LABEL_92:
					if (v49 <= 0) {
						goto LABEL_95;
					}
				}
				if (v50 < 0) {
					*v48 = yTop;
				}
				v51 = v48 + 1;
				v52 = v49 - 1;
				if (v52 > 0) {
					if (v50 & 0x40) {
						*v51 = yTop;
					}
					v53 = v51 + 1;
					v54 = v52 - 1;
					if (v54 > 0) {
						if (v50 & 0x20) {
							*v53 = yTop;
						}
						v55 = v53 + 1;
						v56 = v54 - 1;
						if (v56 > 0) {
							if (v50 & 0x10) {
								*v55 = yTop;
							}
							v57 = v55 + 1;
							v58 = v56 - 1;
							if (v58 > 0) {
								if (v50 & 8) {
									*v57 = yTop;
								}
								v59 = v57 + 1;
								v60 = v58 - 1;
								if (v60 > 0) {
									if (v50 & 4) {
										*v59 = yTop;
									}
									v61 = v59 + 1;
									v62 = v60 - 1;
									if (v62 > 0) {
										if (v50 & 2) {
											*v61 = yTop;
										}
										v63 = v61 + 1;
										v64 = v62 - 1;
										if (v64 > 0) {
											break;
										}
									}
								}
							}
						}
					}
				}
				v11 = xLeft;
			LABEL_95:
				v43 = v69 == 1;
				v65 += *(uint32_t*)(a1 + 4);
				--v69;
				if (v43) {
					v7 = a1;
					goto LABEL_97;
				}
			}
			if (v50 & 1) {
				*v63 = yTop;
			}
			v11 = xLeft;
			v48 = v63 + 1;
			v49 = v64 - 1;
			goto LABEL_92;
		}
	LABEL_97:
		if (dword_5d4594_816452) {
			nox_client_drawRectStringSize_49D190(ptr_5D4594_3799572->field_59, v11, v5, v67, *(uint32_t*)(v7 + 8));
			dword_5d4594_816452 = 0;
			nox_xxx_StringDraw_43FE90(v7, a2, v11, v5);
			dword_5d4594_816452 = 1;
		}
		return v11 + dword_5d4594_816440 + v67;
	}
	v12 = v72.field_4 - rc.top + v5;
	v66 = *(uint32_t*)(a1 + 4) * (v72.field_4 - rc.top) + v65;
	v13 = ptr_5D4594_3799572->clip.left;
	v14 = ptr_5D4594_3799572->clip.right;
	if (v72.field_C == v72.field_4) {
		goto LABEL_60;
	}
	v15 = xLeft;
	v16 = 4 * v12;
	v68 = v72.field_C - v72.field_4;
	while (2) {
		v17 = v67;
		v18 = (uint16_t*)(2 * v15 + (uint32_t)nox_pixbuffer_rows_3798784[v16 / 4]);
		v70 = v16 + 4;
		v19 = (char*)v66;
		v20 = v15;
		while (1) {
			v21 = *v19++;
			if (v21) {
				break;
			}
			v18 += 8;
			v17 -= 8;
			v20 += 8;
		LABEL_58:
			if (v17 <= 0) {
				goto LABEL_59;
			}
		}
		if (v20 >= v13 && v20 < v14 && v21 < 0) {
			*v18 = yTop;
		}
		v22 = v18 + 1;
		v23 = v20 + 1;
		v24 = v17 - 1;
		if (v24 > 0) {
			if (v23 >= v13 && v23 < v14 && v21 & 0x40) {
				*v22 = yTop;
			}
			v25 = v22 + 1;
			v26 = v23 + 1;
			v27 = v24 - 1;
			if (v27 > 0) {
				if (v26 >= v13 && v26 < v14 && v21 & 0x20) {
					*v25 = yTop;
				}
				v28 = v25 + 1;
				v29 = v26 + 1;
				v30 = v27 - 1;
				if (v30 > 0) {
					if (v29 >= v13 && v29 < v14 && v21 & 0x10) {
						*v28 = yTop;
					}
					v31 = v28 + 1;
					v32 = v29 + 1;
					v33 = v30 - 1;
					if (v33 > 0) {
						if (v32 >= v13 && v32 < v14 && v21 & 8) {
							*v31 = yTop;
						}
						v34 = v31 + 1;
						v35 = v32 + 1;
						v36 = v33 - 1;
						if (v36 > 0) {
							if (v35 >= v13 && v35 < v14 && v21 & 4) {
								*v34 = yTop;
							}
							v37 = v34 + 1;
							v38 = v35 + 1;
							v39 = v36 - 1;
							if (v39 > 0) {
								if (v38 >= v13 && v38 < v14 && v21 & 2) {
									*v37 = yTop;
								}
								v40 = v37 + 1;
								v41 = v38 + 1;
								v42 = v39 - 1;
								if (v42 > 0) {
									if (v41 >= v13 && v41 < v14 && v21 & 1) {
										*v40 = yTop;
									}
									v18 = v40 + 1;
									v20 = v41 + 1;
									v17 = v42 - 1;
									goto LABEL_58;
								}
							}
						}
					}
				}
			}
		}
	LABEL_59:
		v43 = v68 == 1;
		v66 += *(uint32_t*)(a1 + 4);
		--v68;
		if (!v43) {
			v15 = xLeft;
			v16 = v70;
			continue;
		}
		break;
	}
LABEL_60:
	if (dword_5d4594_816452) {
		nox_client_drawRectStringSize_49D190(ptr_5D4594_3799572->field_59, xLeft, v71, v67, v72.field_C - v72.field_4);
		dword_5d4594_816452 = 0;
		nox_xxx_StringDraw_43FE90(a1, a2, xLeft, v71);
		dword_5d4594_816452 = 1;
	}
	return xLeft + dword_5d4594_816440 + v67;
}
// 43FEE1: variable 'v4' is possibly undefined

//----- (00440360) --------------------------------------------------------
int sub_440360(int a1, int a2, int xLeft, int yTop) {
	unsigned char* v5; // eax
	int v6;            // eax
	int v7;            // esi
	int v8;            // ebx
	int v9;            // ecx
	int v10;           // eax
	int v11;           // edi
	int v12;           // ebp
	int v13;           // ebx
	int v14;           // edi
	int v15;           // esi
	int v16;           // ecx
	uint8_t* v17;      // eax
	char* v18;         // edi
	char v19;          // dl
	uint8_t* v20;      // eax
	int v21;           // ecx
	int v22;           // esi
	uint8_t* v23;      // eax
	int v24;           // ecx
	int v25;           // esi
	uint8_t* v26;      // eax
	int v27;           // ecx
	int v28;           // esi
	uint8_t* v29;      // eax
	int v30;           // ecx
	int v31;           // esi
	uint8_t* v32;      // eax
	int v33;           // ecx
	int v34;           // esi
	uint8_t* v35;      // eax
	int v36;           // ecx
	int v37;           // esi
	uint8_t* v38;      // eax
	int v39;           // ecx
	int v40;           // esi
	bool v41;          // zf
	int v42;           // edi
	int v43;           // eax
	int v44;           // esi
	int v45;           // ebp
	int v46;           // esi
	char* v47;         // edi
	int v48;           // ecx
	uint8_t* v49;      // eax
	char v50;          // dl
	uint8_t* v51;      // eax
	int v52;           // ecx
	uint8_t* v53;      // eax
	int v54;           // ecx
	uint8_t* v55;      // eax
	int v56;           // ecx
	uint8_t* v57;      // eax
	int v58;           // ecx
	uint8_t* v59;      // eax
	int v60;           // ecx
	uint8_t* v61;      // eax
	int v62;           // ecx
	uint8_t* v63;      // eax
	int v64;           // ecx
	char v65;          // [esp+13h] [ebp-35h]
	char* v66;         // [esp+14h] [ebp-34h]
	int v67;           // [esp+18h] [ebp-30h]
	int v68;           // [esp+1Ch] [ebp-2Ch]
	int v69;           // [esp+20h] [ebp-28h]
	int v70;           // [esp+24h] [ebp-24h]
	int4 v71;          // [esp+28h] [ebp-20h]
	RECT rc;           // [esp+38h] [ebp-10h]
	int yTopa;         // [esp+58h] [ebp+10h]

	v70 = yTop;
	if ((uint16_t)a2 == 9) {
		return dword_5d4594_816456 + xLeft - (dword_5d4594_816456 + xLeft - dword_5d4594_816460) % dword_5d4594_816456;
	}
	v65 = *(uint8_t*)(&ptr_5D4594_3799572->field_59);
	v5 = (unsigned char*)nox_xxx_FontGetChar_43FE30(a1, a2);
	if (!v5) {
		LOWORD(v6) = sub_4408C0(&v65);
		a2 = v6;
		v5 = (unsigned char*)nox_xxx_FontGetChar_43FE30(a1, v6);
		if (!v5) {
			return xLeft;
		}
	}
	v7 = *(uint32_t*)(a1 + 8);
	v8 = *v5;
	v9 = (int)(v5 + 1);
	v10 = ptr_5D4594_3799572->flag_0;
	v66 = (char*)v9;
	v67 = v8;
	if (!v10) {
		goto LABEL_100;
	}
	SetRect(&rc, xLeft, yTop, v8 + xLeft, v7 + yTop);
	if (!nox_xxx_utilRect_49F930(&v71, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->clip))) {
		return xLeft + v8 + dword_5d4594_816440;
	}
	if (rc.left == v71.field_0 && rc.right == v71.field_8 && rc.top == v71.field_4 && rc.bottom == v71.field_C) {
	LABEL_100:
		v43 = v7;
		v44 = v7 - 1;
		if (!v43) {
		LABEL_95:
			if (dword_5d4594_816452) {
				nox_client_drawRectStringSize_49D190(ptr_5D4594_3799572->field_59, xLeft, yTop, v67,
													 *(uint32_t*)(a1 + 8));
				dword_5d4594_816452 = 0;
				sub_440360(a1, a2, xLeft, yTop);
				dword_5d4594_816452 = 1;
			}
			return xLeft + dword_5d4594_816440 + v67;
		}
		v45 = 4 * yTop;
		v46 = v44 + 1;
	LABEL_66:
		v47 = v66;
		v48 = v67;
		v49 = (uint8_t*)(xLeft + (uint32_t)nox_pixbuffer_rows_3798784[v45 / 4]);
		v45 += 4;
		while (1) {
			v50 = *v47++;
			if (v50) {
				if (v50 < 0) {
					*v49 = v65;
				}
				v51 = v49 + 1;
				v52 = v48 - 1;
				if (v52 <= 0) {
					goto LABEL_94;
				}
				if (v50 & 0x40) {
					*v51 = v65;
				}
				v53 = v51 + 1;
				v54 = v52 - 1;
				if (v54 <= 0) {
					goto LABEL_94;
				}
				if (v50 & 0x20) {
					*v53 = v65;
				}
				v55 = v53 + 1;
				v56 = v54 - 1;
				if (v56 <= 0) {
					goto LABEL_94;
				}
				if (v50 & 0x10) {
					*v55 = v65;
				}
				v57 = v55 + 1;
				v58 = v56 - 1;
				if (v58 <= 0) {
					goto LABEL_94;
				}
				if (v50 & 8) {
					*v57 = v65;
				}
				v59 = v57 + 1;
				v60 = v58 - 1;
				if (v60 <= 0) {
					goto LABEL_94;
				}
				if (v50 & 4) {
					*v59 = v65;
				}
				v61 = v59 + 1;
				v62 = v60 - 1;
				if (v62 <= 0) {
					goto LABEL_94;
				}
				if (v50 & 2) {
					*v61 = v65;
				}
				v63 = v61 + 1;
				v64 = v62 - 1;
				if (v64 <= 0) {
				LABEL_94:
					--v46;
					v66 += *(uint32_t*)(a1 + 4);
					if (!v46) {
						goto LABEL_95;
					}
					goto LABEL_66;
				}
				if (v50 & 1) {
					*v63 = v65;
				}
				v49 = v63 + 1;
				v48 = v64 - 1;
			} else {
				v49 += 8;
				v48 -= 8;
			}
			if (v48 <= 0) {
				goto LABEL_94;
			}
		}
	}
	v11 = v71.field_4 - rc.top + yTop;
	v66 += *(uint32_t*)(a1 + 4) * (v71.field_4 - rc.top);
	v12 = ptr_5D4594_3799572->clip.left;
	v13 = ptr_5D4594_3799572->clip.right;
	yTopa = ptr_5D4594_3799572->clip.right;
	if (v71.field_C == v71.field_4) {
		goto LABEL_61;
	}
	v14 = 4 * v11;
	v68 = v71.field_C - v71.field_4;
	while (2) {
		v15 = v67;
		v16 = xLeft;
		v17 = (uint8_t*)(xLeft + (uint32_t)nox_pixbuffer_rows_3798784[v14 / 4]);
		v69 = v14 + 4;
		v18 = v66;
		while (1) {
			v19 = *v18++;
			if (v19) {
				break;
			}
			v17 += 8;
			v15 -= 8;
			v16 += 8;
		LABEL_59:
			if (v15 <= 0) {
				goto LABEL_60;
			}
		}
		if (v16 >= v12 && v16 < v13 && v19 < 0) {
			*v17 = v65;
			v13 = yTopa;
		}
		v20 = v17 + 1;
		v21 = v16 + 1;
		v22 = v15 - 1;
		if (v22 > 0) {
			if (v21 >= v12 && v21 < v13 && v19 & 0x40) {
				*v20 = v65;
				v13 = yTopa;
			}
			v23 = v20 + 1;
			v24 = v21 + 1;
			v25 = v22 - 1;
			if (v25 > 0) {
				if (v24 >= v12 && v24 < v13 && v19 & 0x20) {
					*v23 = v65;
					v13 = yTopa;
				}
				v26 = v23 + 1;
				v27 = v24 + 1;
				v28 = v25 - 1;
				if (v28 > 0) {
					if (v27 >= v12 && v27 < v13 && v19 & 0x10) {
						*v26 = v65;
						v13 = yTopa;
					}
					v29 = v26 + 1;
					v30 = v27 + 1;
					v31 = v28 - 1;
					if (v31 > 0) {
						if (v30 >= v12 && v30 < v13 && v19 & 8) {
							*v29 = v65;
							v13 = yTopa;
						}
						v32 = v29 + 1;
						v33 = v30 + 1;
						v34 = v31 - 1;
						if (v34 > 0) {
							if (v33 >= v12 && v33 < v13 && v19 & 4) {
								*v32 = v65;
								v13 = yTopa;
							}
							v35 = v32 + 1;
							v36 = v33 + 1;
							v37 = v34 - 1;
							if (v37 > 0) {
								if (v36 >= v12 && v36 < v13 && v19 & 2) {
									*v35 = v65;
									v13 = yTopa;
								}
								v38 = v35 + 1;
								v39 = v36 + 1;
								v40 = v37 - 1;
								if (v40 > 0) {
									if (v39 >= v12 && v39 < v13 && v19 & 1) {
										*v38 = v65;
									}
									v17 = v38 + 1;
									v16 = v39 + 1;
									v15 = v40 - 1;
									goto LABEL_59;
								}
							}
						}
					}
				}
			}
		}
	LABEL_60:
		v41 = v68 == 1;
		v66 += *(uint32_t*)(a1 + 4);
		--v68;
		if (!v41) {
			v14 = v69;
			continue;
		}
		break;
	}
LABEL_61:
	if (dword_5d4594_816452) {
		v42 = v70;
		nox_client_drawRectStringSize_49D190(ptr_5D4594_3799572->field_59, xLeft, v70, v67, v71.field_C - v71.field_4);
		dword_5d4594_816452 = 0;
		sub_440360(a1, a2, xLeft, v42);
		dword_5d4594_816452 = 1;
	}
	return xLeft + dword_5d4594_816440 + v67;
}
// 4403CC: variable 'v6' is possibly undefined

//----- (004407F0) --------------------------------------------------------
int nox_xxx_guiDrawString_4407F0(int a1, short* a2, int a3, int a4) {
	short v4;   // cx
	short* v5;  // esi
	int result; // eax

	v4 = *a2;
	v5 = a2 + 1;
	if (!*a2) {
		return a3;
	}
	result = a3;
	do {
		if (v4 != 13 && v4 != 10) {
			result = (*(int (**)(uint32_t, uint16_t, uint32_t, uint32_t)) & dword_5d4594_816448)(a1, v4, result, a4);
		}
		v4 = *v5;
		++v5;
	} while (v4);
	return result;
}

//----- (00440840) --------------------------------------------------------
void nox_xxx_Font_440840(void* lpMem) {
	if (*((uint32_t*)lpMem + 4)) {
		free(*((void**)lpMem + 4));
	}
	if (*((uint32_t*)lpMem + 6)) {
		free(*((void**)lpMem + 6));
	}
	free(lpMem);
}

//----- (00440870) --------------------------------------------------------
int nox_xxx_fontLoad_440870(int a1) {
	int result;         // eax
	int v2;             // edx
	unsigned short* v3; // ecx
	int v4;             // esi

	result = 0;
	v2 = *(uint32_t*)(a1 + 12);
	if (v2 > 0) {
		v3 = (unsigned short*)(*(uint32_t*)(a1 + 16) + 4);
		do {
			v4 = v3[1] - *v3;
			v3 += 4;
			--v2;
			result += v4 + 1;
		} while (v2);
	}
	return result;
}

//----- (004408A0) --------------------------------------------------------
short sub_4408A0(uint16_t* a1) {
	if (getMemByte(0x973A20, 496) & 8) {
		*a1 ^= 0x5555u;
	}
	return 63;
}

//----- (004408C0) --------------------------------------------------------
short sub_4408C0(uint8_t* a1) {
	if (getMemByte(0x973A20, 496) & 8) {
		*a1 ^= 0x55u;
	}
	return 63;
}

#ifndef NOX_CGO
//----- (004408E0) --------------------------------------------------------
int sub_4408E0() { return 1; }

//----- (00440900) --------------------------------------------------------
void sub_440900() {
	uint32_t** dst = nox_pixbuffer_rows_3798784;
	int val = ptr_5D4594_3799572->field_58;
	for (int y = 0; y < nox_backbuffer_height; y++) {
		uint32_t* row = *dst;
		for (int x = 0; x < nox_backbuffer_width32; x++) {
			for (int i = 0; i < 8; i++) {
				row[i] = val;
			}
			row += 8;
		}
		++dst;
	}
}
#endif // NOX_CGO

//----- (00440950) --------------------------------------------------------
int nox_xxx_netServerCmd_440950(char a1, wchar_t* a2) {
	char v3[516]; // [esp+4h] [ebp-204h]

	v3[0] = -69;
	v3[1] = a1;
	*(uint16_t*)&v3[2] = *getMemU16Ptr(0x85319C, 0);
	v3[4] = 0;
	*(uint16_t*)&v3[5] = 0;
	if (a2) {
		v3[4] = nox_wcslen(a2) + 1;
		nox_wcscpy((wchar_t*)&v3[5], a2);
	}
	return nox_xxx_netClientSend2_4E53C0(31, v3, 2 * (unsigned char)v3[4] + 7, 0, 1);
}

//----- (00440AC0) --------------------------------------------------------
int sub_440AC0(wchar_t* a1) {
	int v1;             // edi
	const wchar_t** v2; // esi

	v1 = 0;
	v2 = (const wchar_t**)getMemAt(0x587000, 94504);
	while (_nox_wcsicmp(a1, *v2)) {
		v2 += 19;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 95416)) {
			return -1;
		}
	}
	return v1;
}

//----- (004417E0) --------------------------------------------------------
void sub_4417E0(wchar_t* a1, const char* a2) {
	unsigned char v2; // dl
	char* v3;         // edi
	char v4[64];      // [esp+4h] [ebp-C0h]
	wchar_t v5[64];   // [esp+44h] [ebp-80h]

	if (a2) {
		strcpy(v4, a2);
		v2 = getMemByte(0x587000, 103296);
		v3 = &v4[strlen(v4)];
		*(uint32_t*)v3 = *getMemU32Ptr(0x587000, 103292);
		v3[4] = v2;
		nox_swprintf(v5, L"%-20.20S\t\t", v4);
		nox_wcscat(a1, v5);
	}
}
// 4417E0: using guessed type char var_C0[64];

//----- (004438A0) --------------------------------------------------------
int nox_xxx_doExecrul_4438A0(int a1) {
	FILE* v1;        // eax
	FILE* v2;        // esi
	char* v3;        // eax
	char v5[256];    // [esp+8h] [ebp-400h]
	char v6[256];    // [esp+108h] [ebp-300h]
	wchar_t v7[128]; // [esp+208h] [ebp-200h]

	if (!a1) {
		return 0;
	}
	v6[0] = 0;
	nox_sprintf(v6, "%S", a1);
	v1 = nox_fs_open_text(v6);
	v2 = v1;
	if (!v1) {
		return 0;
	}
	if (!nox_fs_feof(v1)) {
		do {
			memset(v5, 0, 0xFCu);
			*(uint16_t*)&v5[252] = 0;
			v5[254] = 0;
			nox_fs_fgets(v2, v5, 255);
			v3 = strchr(v5, 10);
			if (v3) {
				*v3 = 0;
			}
			if (v5[0]) {
				nox_swprintf(v7, L"%S", v5);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_WHITE, (wchar_t*)getMemAt(0x587000, 106956), v7);
				nox_server_parseCmdText_443C80(v7, 1);
			}
		} while (!nox_fs_feof(v2));
	}
	nox_fs_close(v2);
	return 1;
}

//----- (004443B0) --------------------------------------------------------
#ifndef NOX_CGO
void sub_4443B0(unsigned char a1) {
	char* v1;    // eax
	wchar_t* v2; // esi

	if (a1 >= 0x3Bu && a1 <= 0x58u) {
		if (*getMemU32Ptr(0x587000, 95416)) {
			v1 = sub_444410(a1);
			v2 = (wchar_t*)v1;
			if (v1) {
				if (*(uint16_t*)v1) {
					nox_gui_console_Printf_450C00(NOX_CONSOLE_WHITE, (wchar_t*)getMemAt(0x587000, 107640), v1);
					nox_server_parseCmdText_443C80(v2, 0);
					sub_4309B0(a1, 1);
				}
			}
		}
	}
}
#endif // NOX_CGO

//----- (00444410) --------------------------------------------------------
wchar_t* sub_444410(int a1) {
	char* result;      // eax
	int v2;            // edx
	unsigned char* v3; // ecx

	result = 0;
	v2 = 0;
	v3 = getMemAt(0x587000, 94512);
	while (a1 != *(uint32_t*)v3) {
		v3 += 76;
		++v2;
		if ((int)v3 - (int)getMemAt(0x587000, 94512) >= 912) {
			return result;
		}
	}
	return (char*)getMemAt(0x587000, 94516 + 76 * v2);
}

#ifndef NOX_CGO
//----- (004445C0) --------------------------------------------------------
void nox_setProfiledMode_4445C0() {
	int v0 = 0;
	int v4 = 0;
	int v5 = 0;
	*getMemU32Ptr(0x587000, 80808) = 1;
	*getMemU32Ptr(0x587000, 80816) = 1;
	nox_client_showTooltips_80840 = 1;
	nox_client_renderGUI_80828 = 1;
	nox_xxx_xxxRenderGUI_587000_80832 = 1;
	if (v0 == 0) {
		v4 = 8;
		v5 = 75;
		nox_client_drawFrontWalls_80812 = 0;
		nox_client_translucentFrontWalls_805844 = 0;
		nox_client_highResFrontWalls_80820 = 0;
		nox_client_highResFloors_154952 = 0;
		nox_client_lockHighResFloors_1193152 = 0;
		nox_client_texturedFloors_154956 = 1;
		nox_gui_console_translucent = 0;
		nox_client_renderGlow_805852 = 0;
		nox_client_fadeObjects_80836 = 0;
		nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
		nox_client_renderBubbles_80844 = 0;
	} else if (v0 == 200) {
		v4 = 8;
		v5 = 85;
		nox_client_drawFrontWalls_80812 = 1;
		nox_client_translucentFrontWalls_805844 = 0;
		nox_client_highResFrontWalls_80820 = 0;
		nox_client_highResFloors_154952 = 0;
		nox_client_lockHighResFloors_1193152 = 0;
		nox_client_texturedFloors_154956 = 1;
		nox_gui_console_translucent = 0;
		nox_client_renderGlow_805852 = 0;
		nox_client_fadeObjects_80836 = 0;
		nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
		nox_client_renderBubbles_80844 = 0;
	} else if (v0 == 266) {
		v4 = 8;
		v5 = 100;
		nox_client_drawFrontWalls_80812 = 1;
		nox_client_translucentFrontWalls_805844 = 1;
		nox_client_highResFrontWalls_80820 = 1;
		nox_client_highResFloors_154952 = 1;
		nox_client_lockHighResFloors_1193152 = 0;
		nox_client_texturedFloors_154956 = 1;
		nox_gui_console_translucent = 0;
		nox_client_renderGlow_805852 = 1;
		nox_client_fadeObjects_80836 = 1;
		nox_common_setEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
		nox_client_renderBubbles_80844 = 1;
	} else if (v0 == 300) {
		v4 = 16;
		v5 = 100;
		nox_client_drawFrontWalls_80812 = 1;
		nox_client_translucentFrontWalls_805844 = 1;
		nox_client_highResFrontWalls_80820 = 1;
		nox_client_highResFloors_154952 = 1;
		nox_client_lockHighResFloors_1193152 = 0;
		nox_client_texturedFloors_154956 = 1;
		nox_gui_console_translucent = 0;
		nox_client_renderGlow_805852 = 1;
		nox_client_fadeObjects_80836 = 1;
		nox_common_setEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
		nox_client_renderBubbles_80844 = 1;
	} else if (v0 == 450) {
		v4 = 16;
		v5 = 100;
		nox_client_drawFrontWalls_80812 = 1;
		nox_client_translucentFrontWalls_805844 = 1;
		nox_client_highResFrontWalls_80820 = 1;
		nox_client_highResFloors_154952 = 1;
		nox_client_lockHighResFloors_1193152 = 1;
		nox_client_texturedFloors_154956 = 1;
		nox_gui_console_translucent = 1;
		nox_client_renderGlow_805852 = 1;
		nox_client_fadeObjects_80836 = 1;
		nox_common_setEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
		nox_client_renderBubbles_80844 = 1;
	}
	int v11;
	int v10;
	int v9 = 0;
	nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(&v11, &v10, &v9);
	v4 = 16; // 8 bit not supported
	nox_xxx_tileSetDrawFn_481420();
	if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE)) {
		nox_xxx_gameResizeScreen_43BEF0_set_video_mode(NOX_DEFAULT_WIDTH, NOX_DEFAULT_HEIGHT, v4);
	}
	nox_video_setCutSize_4766A0(v5);
	if (nox_common_gameFlags_check_40A5C0(0x10000000)) {
		nox_draw_setCutSize_476700(v5, 0);
	}
	nox_profiled_805856 = 1;
}
int nox_xxx____crtGetStringTypeA_0_444830() {
	abort();
	return 0;
}

//----- (004449D0) --------------------------------------------------------
int nox_client_drawInitAll_4449D0(int w, int h, int depth, int flags) {
	int result; // eax

	result = nox_client_drawXxx_444AC0(w, h, depth, flags);
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = sub_47D200();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = nox_video_initPixbuffer_486090();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = nox_video_assignCircleDrawFuncs_4B0B30();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = sub_4408E0();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = sub_49F610();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = sub_4338D0();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = nox_video_setBackBufferCopyFunc_4AD100();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = nox_video_initCursorDrawVars_48B1F0();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = nox_client_initFade2_44D9A0();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = sub_4B0650();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = nox_video_initLineDrawingFuncs_49E3F0();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = sub_48C560();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = sub_4B02D0();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = sub_4AF8D0();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = sub_4AEE80();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = sub_4AE520();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = nox_video_initRectDrawingFuncs_49CB50();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = nox_xxx_fontLoadMB_43F1C0();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return result;
	}

	result = sub_4AE400();
	printf("%s: %d\n", __FUNCTION__, result);
	if (result) {
		result = sub_49F4A0();
	}
	printf("%s: %d\n", __FUNCTION__, result);
	return result;
}
#endif // NOX_CGO

// 4408F0: using guessed type void nullsub_3(void);
// 47D2B0: using guessed type void nullsub_6(void);
// 48C570: using guessed type void nullsub_11(void);
// 49CC60: using guessed type void nullsub_12(void);
// 49E4A0: using guessed type void nullsub_13(void);
// 49F6C0: using guessed type void nullsub_14(void);
// 4AD140: using guessed type void nullsub_15(void);
// 4AE410: using guessed type void nullsub_16(void);
// 4AEE90: using guessed type void nullsub_17(void);
// 4B02F0: using guessed type void nullsub_18(void);
// 4B0B80: using guessed type void nullsub_19(void);

#ifndef NOX_CGO
//----- (00444D00) --------------------------------------------------------
void sub_444D00() {
	nox_mutex_lock(getMemAt(0x973F18, 168));
	nox_video_setBackBufferPtrs_48A190();
	nox_video_setBackBufferCopyFunc2_4AD150();
	nox_mutex_unlock(getMemAt(0x973F18, 168));
}
#endif // NOX_CGO

//----- (00444D30) --------------------------------------------------------
void sub_444D30() { memcpy(ptr_5D4594_3799572, &obj_5D4594_3799660, sizeof(nox_render_data_t)); }

//----- (00444D50) --------------------------------------------------------
void sub_444D50(nox_render_data_t* a1) { memcpy(a1, ptr_5D4594_3799572, sizeof(nox_render_data_t)); }

//----- (00444D70) --------------------------------------------------------
void sub_444D70(nox_render_data_t* a1) { memcpy(ptr_5D4594_3799572, a1, sizeof(nox_render_data_t)); }

//----- (00445440) --------------------------------------------------------
int sub_445440() { return 1; }

//----- (00445450) --------------------------------------------------------
wchar_t* sub_445450() {
	unsigned char* v0; // esi
	wchar_t* result;   // eax

	v0 = getMemAt(0x5D4594, 824440);
	do {
		result = nox_wcscpy((wchar_t*)v0 - 318, (const wchar_t*)getMemAt(0x5D4594, 825740));
		*(uint32_t*)v0 = 0;
		v0[4] = 0;
		v0 += 644;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 826372));
	dword_5d4594_825736 = 0;
	return result;
}

//----- (00445530) --------------------------------------------------------
int nox_xxx_drawMessageLines_445530() {
	int v1;             // ebp
	int v2;             // eax
	int v3;             // ebx
	int result;         // eax
	int v5;             // ebx
	unsigned short* v6; // ebx
	int v7;             // kr00_4
	unsigned char* v8;  // esi
	int v9;             // edi
	int v10;            // esi
	int v11;            // ecx
	int i;              // [esp+10h] [ebp-Ch]
	int v13;            // [esp+14h] [ebp-8h]
	int v14;            // [esp+18h] [ebp-4h]

	v13 = 0;
	nox_draw_viewport_t* rdr = nox_draw_getViewport_437250();
	v1 = 3 * rdr->height / 4 + rdr->y1 - 15;
	v2 = dword_5d4594_825736;
	for (i = dword_5d4594_825736;; v2 = i) {
		v3 = 161 * v2;
		result = nox_frame_xxx_2598000;
		v5 = 4 * v3;
		if (*getMemU32Ptr(0x5D4594, 824440 + v5) < nox_frame_xxx_2598000) {
			break;
		}
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x85B3FC, 952));
		v6 = getMemU16Ptr(0x5D4594, 823804 + v5);
		nox_xxx_drawGetStringSize_43F840(0, v6, &v14, 0, 0);
		v7 = nox_win_width - v14;
		v8 = getMemAt(0x587000, 107848);
		v9 = (nox_win_width - v14) / 2;
		do {
			nox_xxx_drawString_43F6E0(0, (short*)v6, v9 + *(uint32_t*)v8, v1 + *((uint32_t*)v8 + 1));
			v8 += 8;
		} while ((int)v8 < (int)getMemAt(0x587000, 107880));
		v10 = v13;
		if (v13) {
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2597996));
		} else {
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
		}
		nox_xxx_drawString_43F6E0(0, (short*)v6, v7 / 2, v1);
		v11 = -4 - nox_xxx_guiFontHeightMB_43F320(0);
		result = i;
		v1 += v11;
		if (i) {
			--i;
		} else {
			i = 2;
		}
		++v13;
		if (v10 + 1 >= 3) {
			break;
		}
	}
	return result;
}

//----- (004456E0) --------------------------------------------------------
int nox_xxx_guiChatMode_4456E0(int* a1) {
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

//----- (00445730) --------------------------------------------------------
int nox_xxx_guiChatShowHide_445730(int a1) { return nox_window_set_hidden(*(int*)&dword_5d4594_825744, a1); }

//----- (00445750) --------------------------------------------------------
int sub_445750() { return dword_5d4594_825744 && !wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_825744); }

//----- (00445770) --------------------------------------------------------
int sub_445770() {
	int result; // eax

	result = nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_825744);
	dword_5d4594_825744 = 0;
	return result;
}

// 445B20: using guessed type int nox_xxx_quitDialogYes_445B20();

//----- (00445B20) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void nox_xxx_quitDialogYes_445B20() {
	nox_client_quit_4460C0();
	sub_445C40();
}
// 445B20: using guessed type int nox_xxx_quitDialogYes_445B20();

//----- (00445B30) --------------------------------------------------------
int nox_xxx_quitDialogNo_445B30() { return nox_xxx_wndSetCaptureMain_46ADC0(nox_wnd_quitMenu_825760); }

//----- (00445BA0) --------------------------------------------------------
void sub_445BA0() { sub_413A00(0); }

//----- (00445BB0) --------------------------------------------------------
int sub_445BB0() { return 1; }

//----- (00445BC0) --------------------------------------------------------
int nox_xxx_wndDrawQuitMenu_445BC0(uint32_t* a1) {
	int xLeft; // [esp+4h] [ebp-8h]
	int yTop;  // [esp+8h] [ebp-4h]

	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop);
	nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, a1[2], a1[3]);
	return 1;
}

//----- (00445C00) --------------------------------------------------------
void sub_445C00() {
	int v = nox_xxx_wndGetFlags_46ADA0(nox_wnd_quitMenu_825760);
	if (v & 0x10) {
		sub_445C40();
	}
}

//----- (00445C20) --------------------------------------------------------
void sub_445C20() {
	int v = nox_xxx_wndGetFlags_46ADA0(nox_wnd_quitMenu_825760);
	if (!(v & 0x10)) {
		sub_445C40();
	}
}

//----- (00445FF0) --------------------------------------------------------
uint32_t* sub_445FF0() {
	int i;            // esi
	uint32_t* result; // eax

	if (nox_wnd_quitMenu_825760) {
		nox_wnd_quitMenu_825760->draw_data.bg_color = *getMemU32Ptr(0x85B3FC, 952);
	}
	for (i = 9001; i <= 9006; ++i) {
		result = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, i);
		if (result) {
			result[26] = *getMemU32Ptr(0x852978, 12);
		}
	}
	return result;
}

//----- (00446030) --------------------------------------------------------
int sub_446030() { return dword_5d4594_825768 != 0; }

//----- (00446050) --------------------------------------------------------
int sub_446050() {
	int result; // eax

	result = nox_frame_xxx_2598000;
	dword_5d4594_825768 = nox_frame_xxx_2598000;
	return result;
}

//----- (00446060) --------------------------------------------------------
void sub_446060() { dword_5d4594_825768 = 0; }

//----- (00446070) --------------------------------------------------------
void sub_446070() {
	if (!--dword_5d4594_825752) {
		sub_446380();
	}
}

//----- (00446090) --------------------------------------------------------
int sub_446090() { return dword_5d4594_825752 == 0; }

//----- (004460A0) --------------------------------------------------------
int sub_4460A0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 825756) = a1;
	return result;
}

//----- (004460B0) --------------------------------------------------------
int sub_4460B0() { return *getMemU32Ptr(0x5D4594, 825756); }

//----- (004460C0) --------------------------------------------------------
int nox_client_quit_4460C0() {
	int result; // eax

	if (nox_common_gameFlags_check_40A5C0(4096)) {
		if (nox_common_gameFlags_check_40A5C0(1)) {
			result = sub_4DCD40();
		} else if (sub_4460B0()) {
			sub_4460A0(0);
			result = sub_446140();
		} else {
			nox_xxx_netSavePlayer_41CE00();
			result = sub_4460A0(1);
		}
	} else {
		dword_5d4594_825764 = 1;
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (result) {
			result = nox_common_gameFlags_check_40A5C0(1);
			if (result) {
				result = sub_4D6B10(0);
			}
		}
	}
	return result;
}

//----- (00446140) --------------------------------------------------------
int sub_446140() {
	int result; // eax

	dword_5d4594_825764 = 1;
	result = nox_common_gameFlags_check_40A5C0(4096);
	if (result) {
		result = nox_common_gameFlags_check_40A5C0(1);
		if (result) {
			result = sub_4D6B10(0);
		}
	}
	return result;
}

//----- (00446180) --------------------------------------------------------
int nox_xxx_serverIsClosing_446180() { return dword_5d4594_825764; }

//----- (00446360) --------------------------------------------------------
unsigned int nox_gui_xxx_check_446360() {
	unsigned int result; // eax

	if (nox_wnd_quitMenu_825760) {
		result = ((unsigned int)~nox_xxx_wndGetFlags_46ADA0(nox_wnd_quitMenu_825760) >> 4) & 1;
	} else {
		result = 0;
	}
	return result;
}

//----- (00446380) --------------------------------------------------------
void sub_446380() {
	sub_44A400();
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) && !sub_4D6F30()) {
		sub_41CEE0((int)getMemAt(0x85B3FC, 10980), 1);
	}
	nox_xxx_guiServerOptionsHide_4597E0(1);
	nox_xxx_setContinueMenuOrHost_43DDD0(0);
	nox_game_exit_xxx_43DE60();
	sub_446060();
}

//----- (004463E0) --------------------------------------------------------
int nox_motd_4463E0(int a1) {
	FILE* result; // eax
	FILE* v2;     // edi
	char* v3;     // eax

	dword_5d4594_826036 = 0;
	*getMemU32Ptr(0x5D4594, 826040 + 4 * a1) = 0;
	result = nox_fs_open("motd.txt");
	v2 = result;
	if (result) {
		*getMemU32Ptr(0x5D4594, 826040 + 4 * a1) = nox_fs_fsize(v2);
		v3 = (char*)calloc(*getMemU32Ptr(0x5D4594, 826040 + 4 * a1) + 1, 1u);
		dword_5d4594_826036 = v3;
		if (v3) {
			nox_binfile_fread_raw_40ADD0(v3, *getMemU32Ptr(0x5D4594, 826040 + 4 * a1), 1u, v2);
			v3 = *(char**)&dword_5d4594_826036;
		}
		v3[(*getMemU32Ptr(0x5D4594, 826040 + 4 * a1))++] = 0;
		nox_fs_close(v2);
	}
	return 0;
}

//----- (00446490) --------------------------------------------------------
void* sub_446490(int a1) {
	void* result; // eax

	result = *(void**)&dword_5d4594_826036;
	if (dword_5d4594_826036) {
		free(*(void**)&dword_5d4594_826036);
		result = a1;
	}
	dword_5d4594_826036 = 0;
	*getMemU32Ptr(0x5D4594, 826040 + 4 * (uint32_t)a1) = 0;
	return result;
}

//----- (004464D0) --------------------------------------------------------
void* sub_4464D0(int a1, uint32_t* a2) {
	*a2 = *getMemU32Ptr(0x5D4594, 826040 + 4 * a1);
	return *(void**)&dword_5d4594_826036;
}

//----- (004464F0) --------------------------------------------------------
int sub_4464F0(int a1, uint32_t* a2) {
	if (!*getMemU32Ptr(0x5D4594, 826056 + 4 * a1)) {
		return 0;
	}
	*a2 = *getMemU32Ptr(0x5D4594, 826048 + 4 * a1);
	return *getMemU32Ptr(0x5D4594, 826056 + 4 * a1);
}

//----- (00446520) --------------------------------------------------------
void sub_446520(int a1, const void* a2, int a3) {
	void* v3; // edi

	if (a2) {
		if (a3 > 0) {
			v3 = calloc(a3, 1u);
			*getMemU32Ptr(0x5D4594, 826056 + 4 * a1) = v3;
			memcpy(v3, a2, a3);
			*getMemU32Ptr(0x5D4594, 826048 + 4 * a1) = a3;
			*getMemU32Ptr(0x5D4594, 826064 + 4 * a1) = 1;
		}
	}
}

//----- (00446580) --------------------------------------------------------
int sub_446580(int a1) {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 826056 + 4 * a1);
	if (result) {
		free(*(void**)getMemAt(0x5D4594, 826056 + 4 * a1));
		*getMemU32Ptr(0x5D4594, 826056 + 4 * a1) = 0;
		*getMemU32Ptr(0x5D4594, 826048 + 4 * a1) = 0;
		*getMemU32Ptr(0x5D4594, 826064 + 4 * a1) = 0;
	}
	return result;
}

//----- (004465C0) --------------------------------------------------------
int nox_xxx_guiMotdLoad_4465C0() {
	uint32_t* v0; // eax
	uint32_t* v1; // eax
	uint32_t* v2; // edi
	char* v3;     // ebx
	uint32_t* v4; // esi
	uint32_t* v5; // ebp
	char* v7;     // [esp+10h] [ebp-8h]
	uint32_t* v8; // [esp+14h] [ebp-4h]

	v0 = nox_new_window_from_file("motd.wnd", sub_4466C0);
	dword_5d4594_826028 = v0;
	v1 = nox_xxx_wndGetChildByID_46B0C0(v0, 4203);
	dword_5d4594_826032 = v1;
	v2 = (uint32_t*)v1[8];
	v7 = nox_xxx_gLoadImg_42F970("UISlider");
	v3 = nox_xxx_gLoadImg_42F970("UISliderLit");
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_826028, 4204);
	v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_826028, 4205);
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_826028, 4206);
	*(uint32_t*)(v4[100] + 8) = 16;
	*(uint32_t*)(v4[100] + 12) = 10;
	sub_4B5700((int)v4, 0, 0, (int)v7, (int)v3, (int)v3);
	nox_xxx_wnd_46B280((int)v4, *(int*)&dword_5d4594_826032);
	nox_xxx_wnd_46B280((int)v5, *(int*)&dword_5d4594_826032);
	nox_xxx_wnd_46B280((int)v8, *(int*)&dword_5d4594_826032);
	v2[9] = v4;
	v2[7] = v5;
	v2[8] = v8;
	return dword_5d4594_826028;
}

//----- (004466C0) --------------------------------------------------------
int sub_4466C0(int a1, int a2, int a3, int a4) {
	if (a2 == 16391) {
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
		sub_446780();
	}
	return 0;
}

//----- (004466F0) --------------------------------------------------------
char* sub_4466F0(char* a1, uint8_t* a2) {
	char* v2;     // edx
	char* v3;     // eax
	char v4;      // cl
	char* result; // eax

	v2 = a2;
	v3 = a1;
	*a2 = 0;
	if (!*a1) {
		return 0;
	}
	while (1) {
		v4 = *v3;
		if (!*v3) {
			*v2 = 0;
			return 0;
		}
		if (v4 == 10) {
			*v2 = 0;
			return v3 + 1;
		}
		if (v4 == 13) {
			break;
		}
		*v2++ = v4;
		++v3;
	}
	result = v3 + 1;
	*v2 = 0;
	if (*result == 10) {
		++result;
	}
	return result;
}

//----- (00446730) --------------------------------------------------------
uint8_t* nox_xxx_motdAddSomeTextMB_446730(uint8_t* a1) {
	uint8_t* result; // eax
	wchar_t v2[256]; // [esp+0h] [ebp-200h]

	result = a1;
	if (*a1) {
		nox_swprintf(v2, L"%S", a1);
		result = (uint8_t*)nox_window_call_field_94(*(int*)&dword_5d4594_826032, 16397, (int)v2, -1);
	}
	return result;
}

//----- (00446780) --------------------------------------------------------
int sub_446780() {
	if (wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_826028)) {
		return 0;
	}
	nox_xxx_windowFocus_46B500(0);
	nox_window_set_hidden(*(int*)&dword_5d4594_826028, 1);
	*(uint32_t*)(dword_5d4594_826028 + 4) &= 0xFFFFFFF7;
	*(uint32_t*)(dword_5d4594_826032 + 4) &= 0xFFFFFFF7;
	nox_window_call_field_94(*(int*)&dword_5d4594_826032, 16399, 0, 0);
	return 1;
}

//----- (004467F0) --------------------------------------------------------
void nox_xxx_motd_4467F0() {
	unsigned int result; // eax
	uint32_t* v1;        // eax
	char* v2;            // esi
	uint32_t* v3;        // eax
	char v4[256];        // [esp+0h] [ebp-100h]

	result = nox_gui_xxx_check_446360();
	if (!result) {
		result = nox_xxx_isQuest_4D6F50();
		if (!result || (result = nox_common_gameFlags_check_40A5C0(128)) == 0) {
			if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				result = nox_xxx_wndGetFlags_46ADA0(*(int*)&dword_5d4594_826028);
				if (result & 0x10) {
					result = sub_44A4A0();
					if (!result) {
						result = sub_49C810();
						if (!result) {
							result = sub_49CB40();
							if (!result) {
								nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_826028);
								v1 = nox_xxx_wndGetChildByID_46B0C0(0, 4100);
								if (v1) {
									nox_xxx_wndShowModalMB_46A8C0((int)v1);
								}
								*(uint32_t*)(dword_5d4594_826028 + 4) |= 8u;
								*(uint32_t*)(dword_5d4594_826032 + 4) |= 8u;
								v2 = *(char**)getMemAt(0x5D4594, 826060);
								if (*getMemU32Ptr(0x5D4594, 826060)) {
									while (1) {
										v2 = sub_4466F0(v2, v4);
										if (!v2) {
											break;
										}
										if (!v4[0]) {
											strcpy(v4, " ");
										}
										nox_xxx_motdAddSomeTextMB_446730(v4);
									}
									if (v4[0]) {
										nox_xxx_motdAddSomeTextMB_446730(v4);
									}
								}
								v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_826028, 4202);
								nox_xxx_windowFocus_46B500((int)v3);
							}
						}
					}
				}
			}
			*getMemU32Ptr(0x5D4594, 826068) = 0;
		}
	}
}

//----- (00446940) --------------------------------------------------------
int sub_446940(int a1) { return *getMemU32Ptr(0x5D4594, 826064 + 4 * a1); }

//----- (00446950) --------------------------------------------------------
int sub_446950() { return dword_5d4594_826028 && !(nox_xxx_wndGetFlags_46ADA0(*(int*)&dword_5d4594_826028) & 0x10); }

//----- (004469D0) --------------------------------------------------------
wchar_t* sub_4469D0(int a1) {
	if (a1 / *getMemU32Ptr(0x5D4594, 826092) + 1 <= 1) {
		return *(wchar_t**)getMemAt(0x587000, 108848 + 8 * a1);
	}
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827140), L"%s %d",
				 *getMemU32Ptr(0x587000, 108848 + 8 * (a1 % *getMemU32Ptr(0x5D4594, 826092))),
				 a1 / *getMemU32Ptr(0x5D4594, 826092) + 1);
	return (wchar_t*)getMemAt(0x5D4594, 827140);
}

//----- (00446A90) --------------------------------------------------------
int sub_446A90() {
	int result; // eax

	nox_wnd_xxx_829520->state = NOX_GUI_ANIM_OUT;
	sub_43BE40(2);
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100);
	result = 1;
	nox_wnd_xxx_829520->field_13 = nox_game_showGameSel_4379F0;
	return result;
}

//----- (00446AD0) --------------------------------------------------------
void sub_446AD0(int (*fnc)(void)) { nox_wnd_xxx_829520->field_13 = fnc; }

//----- (00446BC0) --------------------------------------------------------
char* sub_446BC0(int a1) {
	int v1;       // eax
	char* result; // eax

	v1 = nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16406, a1, 0);
	nox_sprintf((char*)getMemAt(0x5D4594, 826072), "%S", v1);
	result = (char*)getMemAt(0x5D4594, 826072);
	if (getMemByte(0x5D4594, 826072) == 64 ||
		getMemByte(0x5D4594, 826072) == 32) { // TODO: byte_5D4594 != (unsigned char*)-826072 && ...
		result = (char*)getMemAt(0x5D4594, 826073);
	}
	return result;
}

//----- (00446C10) --------------------------------------------------------
int sub_446C10(int a1, int a2) {
	int v2;     // ecx
	int result; // eax

	v2 = *(uint32_t*)(dword_5d4594_829488 + 32);
	result = a1;
	if (a1 < *(short*)(v2 + 44)) {
		result = 131 * a1;
		if (a2) {
			*(uint32_t*)(*(uint32_t*)(v2 + 24) + 524 * a1 + 516) = **(uint32_t**)getMemAt(0x85B3FC, 140);
		} else {
			*(uint32_t*)(*(uint32_t*)(v2 + 24) + 524 * a1 + 516) = **(uint32_t**)getMemAt(0x85B3FC, 188);
		}
	}
	return result;
}

//----- (00446C70) --------------------------------------------------------
int sub_446C70() { return nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16404, 0, 0); }

//----- (00446C90) --------------------------------------------------------
int sub_446C90() { return *(int*)nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16404, 0, 0) != -1; }

//----- (00446CC0) --------------------------------------------------------
wchar_t* sub_446CC0(int a1) {
	wchar_t* result; // eax
	char* v2;        // eax
	char* v3;        // eax

	result = (wchar_t*)sub_41E2F0();
	if (result == (wchar_t*)7) {
		if (a1) {
			v2 = sub_41FA40();
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 829224), *(const wchar_t**)getMemAt(0x5D4594, 829528), v2, a1);
		} else {
			result = *(wchar_t**)&dword_5d4594_829532;
			if (!dword_5d4594_829532) {
				return result;
			}
			v3 = sub_41FA40();
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 829224), *(const wchar_t**)&dword_5d4594_829532, v3);
			nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16403, -1, 0);
		}
		result = (wchar_t*)nox_window_call_field_94(*getMemIntPtr(0x5D4594, 829496), 16385,
													(int)getMemAt(0x5D4594, 829224), 0);
	}
	return result;
}

//----- (00446D50) --------------------------------------------------------
void sub_446D50() {
	char* v0; // eax
	int v1;   // [esp+0h] [ebp-4h]

	v1 = 0;
	v0 = (char*)sub_4464F0(0, &v1);
	sub_446D80(v0);
}

//----- (00446D80) --------------------------------------------------------
void sub_446D80(char* a1) {
	char* v1;        // esi
	char v2[256];    // [esp+4h] [ebp-300h]
	wchar_t v3[256]; // [esp+104h] [ebp-200h]

	v1 = a1;
	if (a1) {
		while (1) {
			v1 = sub_446E20(v1, v2);
			if (!v1) {
				break;
			}
			if (!v2[0]) {
				strcpy(v2, " ");
			}
			nox_swprintf(v3, L"%S", v2);
			sub_447310(0, (int)v3);
		}
		if (v2[0]) {
			nox_swprintf(v3, L"%S", v2);
			sub_447310(0, (int)v3);
		}
	}
}

//----- (00446E20) --------------------------------------------------------
char* sub_446E20(char* a1, uint8_t* a2) {
	char* v2;     // edx
	char* v3;     // eax
	char v4;      // cl
	char* result; // eax

	v2 = a2;
	v3 = a1;
	*a2 = 0;
	if (!*a1) {
		return 0;
	}
	while (1) {
		v4 = *v3;
		if (!*v3) {
			*v2 = 0;
			return 0;
		}
		if (v4 == 10) {
			*v2 = 0;
			return v3 + 1;
		}
		if (v4 == 13) {
			break;
		}
		*v2++ = v4;
		++v3;
	}
	result = v3 + 1;
	*v2 = 0;
	if (*result == 10) {
		++result;
	}
	return result;
}

//----- (00446E60) --------------------------------------------------------
wchar_t* sub_446E60() {
	wchar_t* result; // eax

	nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16399, 0, 0);
	for (result = sub_41F0A0(); result; result = sub_41F070()) {
		nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16397, (int)result, 14);
	}
	return result;
}

//----- (00446EB0) --------------------------------------------------------
char* sub_446EB0() {
	char* result;    // eax
	const char* i;   // esi
	wchar_t v2[256]; // [esp+4h] [ebp-200h]

	nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16399, 0, 0);
	result = sub_41F780();
	for (i = result; result; i = result) {
		nox_swprintf(v2, L"%S", i);
		if (sub_427880(i)) {
			nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16397, (int)v2, 2);
		} else {
			nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16397, (int)v2, 14);
		}
		result = sub_41F710();
	}
	return result;
}

//----- (00446F40) --------------------------------------------------------
char* sub_446F40(int a1) {
	int v1; // eax

	if (a1 == -1) {
		return 0;
	}
	v1 = nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16406, a1, 0);
	nox_sprintf((char*)getMemAt(0x5D4594, 827120), "%S", v1);
	return (char*)getMemAt(0x5D4594, 827120);
}

//----- (004471A0) --------------------------------------------------------
const wchar_t* sub_4471A0(const char* a1, int a2, int a3, int a4) {
	const wchar_t* result; // eax

	result = (const wchar_t*)sub_427880(a1);
	if (!result) {
		result = *(const wchar_t**)&dword_5d4594_829492;
		if (dword_5d4594_829492) {
			result = *(const wchar_t**)&dword_5d4594_829544;
			if (dword_5d4594_829544) {
				if (a2) {
					if (a3) {
						if (a4 == 1) {
							nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176),
										 *(const wchar_t**)getMemAt(0x5D4594, 829552), a1, a2);
							return (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397,
																			(int)getMemAt(0x5D4594, 827176), 7);
						}
						result = *(const wchar_t**)getMemAt(0x5D4594, 829548);
					}
					nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), result, a1, a2);
					result = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397,
																	  (int)getMemAt(0x5D4594, 827176), (a3 != 0) + 6);
				}
			}
		}
	}
	return result;
}

//----- (00447250) --------------------------------------------------------
const wchar_t* sub_447250(const char* a1, int a2, int a3, int a4) {
	const wchar_t* result; // eax
	const wchar_t* v5;     // esi
	char* v6;              // eax

	result = (const wchar_t*)sub_427880(a1);
	if (!result) {
		result = *(const wchar_t**)&dword_5d4594_829492;
		if (dword_5d4594_829492) {
			if (*getMemU32Ptr(0x5D4594, 829556)) {
				result = *(const wchar_t**)getMemAt(0x5D4594, 829560);
				if (*getMemU32Ptr(0x5D4594, 829560)) {
					if (a2) {
						if (a3) {
							if (a4 == 1) {
								v5 = *(const wchar_t**)getMemAt(0x5D4594, 829564);
								v6 = sub_41FA40();
								nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), v5, a1, v6, a2);
								return (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397,
																				(int)getMemAt(0x5D4594, 827176), 13);
							}
						} else {
							result = *(const wchar_t**)getMemAt(0x5D4594, 829556);
						}
						nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), result, a1, a2);
						result = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397,
																		  (int)getMemAt(0x5D4594, 827176), 13);
					}
				}
			}
		}
	}
	return result;
}

//----- (00447310) --------------------------------------------------------
int sub_447310(int a1, int a2) {
	int result; // eax

	result = dword_5d4594_829492;
	if (dword_5d4594_829492) {
		if (*getMemU32Ptr(0x5D4594, 829536)) {
			result = a2;
			if (a2) {
				if (a1) {
					nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), *(const wchar_t**)getMemAt(0x5D4594, 829536), a1,
								 a2);
				} else {
					nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), L"%s", a2);
				}
				result =
					nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)getMemAt(0x5D4594, 827176), 9);
			}
		}
	}
	return result;
}

//----- (00447380) --------------------------------------------------------
void sub_447380(const char* a1, char* a2) {
	const wchar_t* v3; // edi

	if (sub_427880(a1)) {
		return;
	}
	if (!dword_5d4594_829492) {
		return;
	}
	if (!dword_5d4594_829544) {
		return;
	}
	if (!a2) {
		return;
	}
	v3 = *(const wchar_t**)getMemAt(0x5D4594, 829540);
	sub_447410(a2);
	if (a1) {
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), v3, a1, a2);
	} else {
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), L"%S", a2);
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)getMemAt(0x5D4594, 827176), 4);
	nox_xxx_clientPlaySoundSpecial_452D80(226, 100);
}

//----- (00447410) --------------------------------------------------------
unsigned int sub_447410(char* a1) {
	int v1;              // edx
	char* v2;            // ecx
	char v3;             // al
	unsigned int result; // eax

	v1 = 0;
	v2 = a1;
	if (*a1) {
		do {
			if ((unsigned char)*v2 < 0x80u) {
				*getMemU8Ptr(0x5D4594, 826096 + v1++) = *v2;
			}
			v3 = *++v2;
		} while (v3);
	}
	*getMemU8Ptr(0x5D4594, 826096 + v1) = 0;
	result = strlen((const char*)getMemAt(0x5D4594, 826096)) + 1;
	memcpy(a1, getMemAt(0x5D4594, 826096), result);
	return result;
}

//----- (004475E0) --------------------------------------------------------
int sub_4475E0() { return nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16399, 0, 0); }

//----- (00447600) --------------------------------------------------------
void sub_447600() {
	if (!sub_44A4A0()) {
		nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_829500);
	}
}

//----- (00447BD0) --------------------------------------------------------
int sub_447BD0() {
	int (*v0)(void); // esi

	v0 = nox_wnd_xxx_829520->field_13;
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_829520);
	sub_448490();
	v0();
	return 1;
}

//----- (00447BF0) --------------------------------------------------------
int sub_447BF0(uint32_t* a1, int a2, unsigned int a3, int a4) {
	int result; // eax

	if (a2 == 19) {
		nox_window_call_field_94((int)a1, 16391, *(uint32_t*)(a1[8] + 28), 0);
		result = 0;
	} else if (a2 == 20) {
		nox_window_call_field_94((int)a1, 16391, *(uint32_t*)(a1[8] + 32), 0);
		result = 0;
	} else if (*(uint32_t*)(a1[8] + 16)) {
		result = nox_xxx_wndListboxProcWithData10_4A2DE0((int)a1, a2, a3, a4);
	} else {
		result = nox_xxx_wndListboxProcWithoutData10_4A28E0(a1, a2, a3, a4);
	}
	return result;
}

//----- (00447C70) --------------------------------------------------------
int sub_447C70(int a1, int a2, int a3, int a4) {
	int v5; // eax

	if (a2 != 21) {
		return 0;
	}
	if (a3 != 1) {
		return 0;
	}
	if (a4 == 2 && sub_41E2F0() == 7) {
		sub_41E300(9);
		v5 = sub_41E2F0();
		sub_41DA70(v5, 8);
		sub_44A400();
		nox_game_checkStateWol_43C260();
	}
	return 1;
}

//----- (00447CC0) --------------------------------------------------------
int sub_447CC0(int a1, unsigned int a2, int* a3, int a4) {
	int result;        // eax
	const wchar_t* v5; // edi
	const wchar_t* v6; // eax
	wchar_t* v7;       // esi
	int v9;            // ebx
	int v10;           // esi
	int v11;           // edi
	uint32_t* v12;     // esi
	int* v13;          // esi
	wchar_t* v14;      // eax
	int v15;           // eax
	int v16;           // eax
	int v17;           // eax
	int v18;           // eax
	int v19;           // eax
	wchar_t* v20;      // eax
	int* v21 = 0;      // [esp+8h] [ebp-104h]
	char File[256];    // [esp+Ch] [ebp-100h]

	if (a2 > 0x4006) {
		switch (a2) {
		case 0x4007u:
			switch (nox_xxx_wndGetID_46B0A0(a3)) {
			case 1902:
				sub_448730_wol_dialogs();
				break;
			case 1903:
				v16 = sub_41E2F0();
				sub_41DA70(v16, 12);
				v17 = sub_41E2F0();
				sub_41DA70(v17, 13);
				break;
			case 1904:
				sub_449280();
				break;
			case 1905:
				sub_40D380();
				sub_41E300(8);
				sub_4207F0(5);
				break;
			case 1906:
				sub_41E300(9);
				v15 = sub_41E2F0();
				sub_41DA70(v15, 8);
				nox_game_checkStateWol_43C260();
				break;
			case 1913:
				v20 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_829500, 16413, 0, 0);
				sub_447090_wol_chat(v20);
				nox_window_call_field_94(*(int*)&dword_5d4594_829500, 16414, (int)getMemAt(0x5D4594, 829580), 0);
				break;
			case 1914:
				nox_xxx_guiServerListLoad_449530();
				break;
			case 1926:
				v18 = sub_4200F0();
				nox_sprintf(File, "http://battleclans.westwood.com/nox/index_%d.html", v18);
				ShellExecuteA(0, 0, File, 0, (const char*)getMemAt(0x587000, 111564), 3);
				break;
			case 1927:
				v19 = sub_4200F0();
				nox_sprintf(File, "http://www.westwood.com/westwoodonline/tournaments/nox/rankindex_%d.html", v19);
				ShellExecuteA(0, 0, File, 0, (const char*)getMemAt(0x587000, 111644), 3);
				break;
			default:
				break;
			}
			nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
			return 1;
		case 0x4010u:
			if (nox_xxx_wndGetID_46B0A0(a3) != 1908) {
				return 0;
			}
			if (!*(uint16_t*)nox_window_call_field_94((int)a3, 16406, a4, 0)) {
				goto LABEL_23;
			}
			v5 = (const wchar_t*)sub_41EC00();
			v6 = (const wchar_t*)sub_41F1E0(a4);
			v7 = (wchar_t*)v6;
			if (!v6) {
				goto LABEL_23;
			}
			if (v5) {
				if (nox_wcscmp(v6, v5)) {
					sub_40D380();
					sub_446A20_wol_chat(v7);
				}
			LABEL_23:
				sub_447600();
				result = 0;
			} else {
				sub_446A20_wol_chat(0);
				sub_447600();
				result = 0;
			}
			break;
		case 0x4011u:
			if (nox_xxx_wndGetID_46B0A0(a3) != 1909) {
				return 0;
			}
			if (a4 == -1 || dword_5d4594_829504) {
				dword_587000_109280 = -1;
				result = 0;
			} else {
				nox_point mpos = nox_client_getMousePos_4309F0();
				dword_587000_109280 = a4;
				v9 = mpos.x;
				v10 = mpos.y;
				v11 = nox_xxx_guiFontHeightMB_43F320(0);
				dword_5d4594_829504 = nox_window_new(0, 40, v9 - 40, v10 - (v11 + 4) / 2, 80, v11 + 4, 0);
				nox_window_set_all_funcs(*(uint32_t**)&dword_5d4594_829504, 0, sub_448140, 0);
				nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_829504);
				v12 = nox_window_new(*(int*)&dword_5d4594_829504, 8, 0, v11 / 2, 80, v11 + 2, 0);
				nox_window_set_all_funcs(v12, sub_448340, sub_448240, 0);
				v12[8] = 0;
				result = 0;
			}
			return result;
		case 0x401Fu:
			v13 = a3;
			nox_xxx_wndGetID_46B0A0(a3);
			goto LABEL_31;
		default:
			return 0;
		}
		return result;
	}
	if (a2 == 16390) {
		if (dword_5d4594_830112) {
			return 0;
		}
		sub_41E2F0();
		return 0;
	}
	if (a2 > 0x4003) {
		if (a2 != 16389) {
			return 0;
		}
		nox_xxx_clientPlaySoundSpecial_452D80(920, 100);
		return 1;
	}
	if (a2 == 16387) {
		if (!nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, a4)) {
			return 0;
		}
		return 0;
	}
	if (a2 == 23) {
		return 1;
	}
	if (a2 != 1910) {
		return 0;
	}
	v13 = v21;
LABEL_31:
	v14 = (wchar_t*)nox_window_call_field_94((int)v13, 16413, 0, 0);
	sub_446F80_wol_chat(v14);
	nox_window_call_field_94((int)v13, 16414, (int)getMemAt(0x5D4594, 829576), 0);
	return 0;
}
// 447F24: variable 'v21' is possibly undefined

//----- (00448140) --------------------------------------------------------
int sub_448140(int yTop) {
	int v1;    // esi
	int xLeft; // [esp+4h] [ebp-Ch]
	int v4;    // [esp+8h] [ebp-8h]
	int v5;    // [esp+Ch] [ebp-4h]

	v1 = yTop;
	nox_client_wndGetPosition_46AA60((uint32_t*)yTop, &xLeft, &yTop);
	nox_window_get_size(v1, &v4, &v5);
	nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, v4, v5);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2523948));
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
	return 1;
}

//----- (00448240) --------------------------------------------------------
int sub_448240(uint32_t* a1, uint8_t* a2) {
	unsigned short* v2; // esi
	int v3;             // ecx
	int v5;             // [esp+4h] [ebp-8h]
	int v6;             // [esp+8h] [ebp-4h]

	v2 = *(unsigned short**)getMemAt(0x587000, 108824 + 12 * a1[8]);
	nox_client_wndGetPosition_46AA60(a1, &v6, &a1);
	nox_xxx_drawGetStringSize_43F840(0, v2, &v5, 0, 0);
	v3 = *getMemU32Ptr(0x5D4594, 2589772);
	if (!(*a2 & 2)) {
		v3 = *getMemU32Ptr(0x5D4594, 2523948);
	}
	sub_4482D0((80 - v5) / 2 + v6 + 1, (int)a1, v3, *getMemIntPtr(0x85B3FC, 952), v2);
	return 1;
}

//----- (004482D0) --------------------------------------------------------
int sub_4482D0(int a1, int a2, int a3, int a4, uint16_t* a5) {
	unsigned char* v5; // esi

	nox_xxx_drawSetTextColor_434390(a4);
	v5 = getMemAt(0x587000, 109288);
	do {
		nox_xxx_drawString_43FAF0(0, a5, a1 + *(uint32_t*)v5, a2 + *((uint32_t*)v5 + 1), 320, 0);
		v5 += 8;
	} while ((int)v5 < (int)getMemAt(0x587000, 109320));
	nox_xxx_drawSetTextColor_434390(a3);
	return nox_xxx_drawString_43FAF0(0, a5, a1, a2, 320, 0);
}

//----- (00448340) --------------------------------------------------------
int sub_448340(int a1, unsigned int a2) {
	if (a2 == 5) {
		return 1;
	}
	if (a2 > 5 && a2 <= 7) {
		sub_448380();
		(*(void (**)(int))getMemAt(0x587000, 108832 + 12 * *(uint32_t*)(a1 + 32)))(*(int*)&dword_587000_109280);
		return 1;
	}
	return 0;
}

//----- (00448380) --------------------------------------------------------
void sub_448380() {
	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_829504);
	dword_5d4594_829504 = 0;
	sub_447600();
}

//----- (004483A0) --------------------------------------------------------
int sub_4483A0(int a1, int a2) {
	int result; // eax
	int xLeft;  // [esp+0h] [ebp-8h]
	int yTop;   // [esp+4h] [ebp-4h]

	if (dword_5d4594_829504) {
		nox_point mpos = nox_client_getMousePos_4309F0();
		if (!nox_xxx_wndPointInWnd_46AAB0(*(uint32_t**)&dword_5d4594_829504, mpos.x, mpos.y)) {
			sub_448380();
		}
	}
	nox_client_wndGetPosition_46AA60((uint32_t*)a1, &xLeft, &yTop);
	if ((signed char)*(uint8_t*)(a1 + 4) >= 0) {
		if (*(uint32_t*)(a2 + 20) != 0x80000000) {
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, *(uint32_t*)(a1 + 8), *(uint32_t*)(a1 + 12));
		}
		result = 1;
	} else {
		nox_client_drawImageAt_47D2C0(*(uint32_t*)(a2 + 24), xLeft, yTop);
		result = 1;
	}
	return result;
}

//----- (00448450) --------------------------------------------------------
int sub_448450() {
	int result;   // eax
	uint32_t* v1; // eax

	result = nox_common_gameFlags_check_40A5C0(0x2000000);
	if (result) {
		sub_446970_wol_chat();
		v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1905);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_829480, 16391, (int)v1, 0);
	}
	return result;
}

//----- (00448490) --------------------------------------------------------
int sub_448490() {
	int result; // eax

	result = dword_5d4594_829480;
	if (dword_5d4594_829480) {
		result = nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_829480);
		dword_5d4594_829480 = 0;
		dword_5d4594_829484 = 0;
		dword_5d4594_829488 = 0;
		dword_5d4594_829492 = 0;
		dword_5d4594_829500 = 0;
	}
	return result;
}

//----- (004484D0) --------------------------------------------------------
void sub_4484D0(wchar_t* a1, int a2, int a3) {
	wchar_t* v3;       // eax
	const wchar_t* v4; // eax

	if (a1) {
		nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16402, a3, 0);
		v3 = sub_41F330((int)a1, a2);
		nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16397, (int)v3, 14);
		v4 = (const wchar_t*)sub_41EC00();
		if (v4) {
			if (!nox_wcscmp(v4, a1)) {
				nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16403, a3, 0);
			}
		}
	}
}

//----- (00448550) --------------------------------------------------------
int sub_448550(int a1) { return nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16398, a1, 0); }

//----- (00448570) --------------------------------------------------------
void sub_448570(const char* a1, char a2, int a3) {
	char* v3;        // eax
	wchar_t v4[256]; // [esp+4h] [ebp-200h]

	if (a1) {
		nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16402, a3, 0);
		v3 = sub_41F740((int)a1, a2);
		nox_swprintf(v4, L"%S", v3);
		if (sub_427880(a1)) {
			nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16397, (int)v4, 2);
		} else {
			nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16397, (int)v4, 14);
		}
	}
}

//----- (00448620) --------------------------------------------------------
int sub_448620(int a1) {
	int result; // eax

	result = a1;
	if (a1 >= 0) {
		result = nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16398, a1, 0);
	}
	return result;
}

//----- (00448650) --------------------------------------------------------
int sub_448650(uint8_t* a1, wchar_t* a2) {
	int result; // eax

	if (*a1 == -16) {
		result = sub_425680(a1 + 1, a2);
	} else {
		result = nox_swprintf(a2, L"%S", a1);
	}
	return result;
}

//----- (00448680) --------------------------------------------------------
int sub_448680(wchar_t* a1, char* a2) {
	int result;    // eax
	size_t v3;     // eax
	char v4[2048]; // [esp+4h] [ebp-800h]

	if (nox_xxx_cliCanTalkMB_4100F0((short*)a1)) {
		return nox_sprintf(a2, "%S", a1);
	}
	memset(v4, 0, sizeof(v4));
	memset(a2, 0, 0x800u);
	v3 = nox_wcslen(a1);
	sub_425550(a1, v4, 16 * (v3 + 1));
	result = 0;
	*a2 = -16;
	memcpy(a2 + 1, v4, strlen(v4));
	return result;
}

//----- (00448F00) --------------------------------------------------------
int sub_448F00(uint32_t* a1, int a2, int a3, int a4) {
	if (a2 != 21 || a3 != 28) {
		return nox_xxx_wndEditProc_487D70(a1, a2, a3, a4);
	}
	if (a4 == 2) {
		if (dword_587000_111668 == 1) {
			if (dword_5d4594_830204 != 1) {
				sub_448CF0_wol_dialogs();
				return 1;
			}
		} else if (dword_5d4594_830208 != 1) {
			sub_448CF0_wol_dialogs();
		}
	}
	return 1;
}

//----- (00448F60) --------------------------------------------------------
int sub_448F60(uint32_t* a1, int a2, int a3, int a4) {
	if (a2 != 21 || a3 != 28) {
		return nox_xxx_wndEditProc_487D70(a1, a2, a3, a4);
	}
	if (a4 == 2) {
		if (dword_587000_111668 == 1) {
			if (dword_5d4594_830204 != 1) {
				sub_448CF0_wol_dialogs();
				return 1;
			}
		} else if (dword_5d4594_830208 != 1) {
			sub_448CF0_wol_dialogs();
		}
	}
	return 1;
}

//----- (00448FC0) --------------------------------------------------------
int sub_448FC0(int a1, int a2) {
	int xLeft; // [esp+4h] [ebp-8h]
	int yTop;  // [esp+8h] [ebp-4h]

	nox_client_wndGetPosition_46AA60((uint32_t*)a1, &xLeft, &yTop);
	if ((signed char)*(uint8_t*)(a1 + 4) >= 0) {
		if (*(uint32_t*)(a2 + 20) != 0x80000000) {
			nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 952));
			nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, *(uint32_t*)(a1 + 8), *(uint32_t*)(a1 + 12));
		}
	} else {
		nox_client_drawImageAt_47D2C0(*(uint32_t*)(a2 + 24), xLeft, yTop);
	}
	if (dword_587000_111668) {
		if (dword_5d4594_830204 && nox_xxx_checkKeybTimeout_4160F0(0x12u, 10 * nox_gameFPS)) {
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_830148, 1);
			dword_5d4594_830204 = 0;
			return 1;
		}
	} else if (dword_5d4594_830208 && nox_xxx_checkKeybTimeout_4160F0(0x13u, 10 * nox_gameFPS)) {
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_830148, 1);
		dword_5d4594_830208 = 0;
	}
	return 1;
}

//----- (00449280) --------------------------------------------------------
int sub_449280() {
	int result;      // eax
	int v1;          // eax
	int v2;          // ecx
	unsigned int v3; // ecx
	int v4;          // eax
	int v5;          // ecx
	unsigned int v6; // ecx
	int v7;          // eax
	int v8;          // ecx
	unsigned int v9; // ecx

	if (dword_5d4594_830112) {
		return 0;
	}
	if (dword_5d4594_830116) {
		return 0;
	}
	if (dword_5d4594_830120) {
		return 0;
	}
	result = nox_new_window_from_file("wolopt.wnd", sub_4493D0);
	dword_5d4594_830104 = result;
	if (result) {
		*(uint32_t*)(result + 56) = *getMemU32Ptr(0x85B3FC, 952);
		*(uint32_t*)(dword_5d4594_830104 + 16) = (nox_win_width - *(uint32_t*)(dword_5d4594_830104 + 8)) / 2;
		*(uint32_t*)(dword_5d4594_830104 + 24) =
			*(uint32_t*)(dword_5d4594_830104 + 8) + *(uint32_t*)(dword_5d4594_830104 + 16);
		dword_5d4594_830192 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830104, 1991);
		dword_5d4594_830196 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830104, 1992);
		dword_5d4594_830200 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830104, 1993);
		v1 = sub_41FF60();
		v2 = *(uint32_t*)(dword_5d4594_830192 + 36);
		if (v1) {
			v3 = v2 | 4;
		} else {
			v3 = v2 & 0xFFFFFFFB;
		}
		*(uint32_t*)(dword_5d4594_830192 + 36) = v3;
		v4 = sub_41FF90();
		v5 = *(uint32_t*)(dword_5d4594_830196 + 36);
		if (v4) {
			v6 = v5 | 4;
		} else {
			v6 = v5 & 0xFFFFFFFB;
		}
		*(uint32_t*)(dword_5d4594_830196 + 36) = v6;
		v7 = sub_41FFC0();
		v8 = *(uint32_t*)(dword_5d4594_830200 + 36);
		if (v7) {
			v9 = v8 | 4;
		} else {
			v9 = v8 & 0xFFFFFFFB;
		}
		*(uint32_t*)(dword_5d4594_830200 + 36) = v9;
		dword_5d4594_830120 = 1;
		sub_46B120(*(uint32_t**)&dword_5d4594_830104, 0);
		nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_830104);
		sub_46C690(*(int*)&dword_5d4594_830104);
		nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_830104);
		result = 1;
	}
	return result;
}

//----- (004493D0) --------------------------------------------------------
int sub_4493D0(int a1, int a2, int* a3, int a4) {
	int v3;     // esi
	int result; // eax
	int v5;     // eax

	if (a2 != 16391) {
		return 0;
	}
	v3 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	switch (v3) {
	case 1985:
		v5 = sub_41FC40();
		sub_40DB50(v5 + 1, (int)&a2);
		sub_40D670(a2);
		return 0;
	case 1994:
		sub_4494A0();
		result = 0;
		break;
	case 1995:
		nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_830104);
		nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_830104);
		sub_447600();
		dword_5d4594_830120 = 0;
		result = 0;
		break;
	case 1996:
		sub_4B5770_wol_locale(*(int*)&dword_5d4594_830104);
		result = 0;
		break;
	default:
		return 0;
	}
	return result;
}

//----- (004494A0) --------------------------------------------------------
void sub_4494A0() {
	sub_41FF70((*(uint8_t*)(dword_5d4594_830192 + 36) & 4) == 4);
	sub_41FFA0((*(uint8_t*)(dword_5d4594_830196 + 36) & 4) == 4);
	sub_41FFD0((*(uint8_t*)(dword_5d4594_830200 + 36) & 4) == 4);
	nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_830104);
	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_830104);
	dword_5d4594_830120 = 0;
	sub_447600();
}

//----- (00449530) --------------------------------------------------------
int nox_xxx_guiServerListLoad_449530() {
	const char* v0;  // edi
	int v1;          // ebp
	int result;      // eax
	uint32_t* v3;    // ebx
	int v4;          // eax
	const char* i;   // esi
	char* v6;        // eax
	wchar_t* v7;     // eax
	int v8;          // eax
	uint32_t* v9;    // eax
	uint32_t* v10;   // esi
	uint32_t* v11;   // ebp
	uint32_t* v12;   // eax
	uint32_t* v13;   // edi
	char* v14;       // eax
	uint32_t* v15;   // eax
	char* v16;       // [esp+8h] [ebp-94h]
	int v17;         // [esp+Ch] [ebp-90h]
	char* v18;       // [esp+10h] [ebp-8Ch]
	int v19;         // [esp+14h] [ebp-88h]
	wchar_t v20[66]; // [esp+18h] [ebp-84h]

	v0 = 0;
	v16 = 0;
	v17 = -1;
	v1 = 0;
	result = nox_new_window_from_file("servlist.wnd", sub_4497D0_wol_dialogs);
	dword_5d4594_830108 = result;
	if (result) {
		*(uint32_t*)(result + 56) = *getMemU32Ptr(0x85B3FC, 952);
		sub_46B120(*(uint32_t**)&dword_5d4594_830108, 0);
		nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_830108);
		sub_46C690(*(int*)&dword_5d4594_830108);
		nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_830108);
		if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
			v16 = sub_4A7F10();
			v0 = v16;
		}
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830108, 1961);
		v4 = sub_4200F0();
		for (i = sub_4205B0(v4); i; i = (const char*)sub_4206B0((int)i)) {
			if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
				v6 = strchr(i + 24, 58);
				if (v6) {
					if (v0 && !_strcmpi(v0, v6 + 1)) {
						v17 = v1;
					}
				}
			}
			nox_swprintf(v20, L"%S", i + 24);
			v7 = nox_wcschr(v20, 0x3Au);
			if (v7) {
				nox_window_call_field_94((int)v3, 16397, (int)(v7 + 1), -1);
			}
			++v1;
		}
		v8 = sub_4200F0();
		if (sub_4207A0(v8) <= 0) {
			v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830108, 1962);
			nox_xxx_wnd_46ABB0((int)v9, 0);
		} else {
			nox_window_call_field_94((int)v3, 16403, 0, 0);
		}
		v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830108, 1964);
		v11 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830108, 1965);
		v12 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830108, 1966);
		v13 = (uint32_t*)v3[8];
		v19 = (int)v12;
		v18 = nox_xxx_gLoadImg_42F970("UISlider");
		v14 = nox_xxx_gLoadImg_42F970("UISliderLit");
		sub_4B5700((int)v10, 0, 0, (int)v18, (int)v14, (int)v14);
		nox_xxx_wnd_46B280((int)v10, (int)v3);
		nox_xxx_wnd_46B280((int)v11, (int)v3);
		nox_xxx_wnd_46B280(v19, (int)v3);
		v13[9] = v10;
		v13[7] = v11;
		v13[8] = v19;
		*(uint32_t*)(v10[100] + 8) = 16;
		*(uint32_t*)(v10[100] + 12) = 10;
		if (nox_common_gameFlags_check_40A5C0(0x2000000) && v16 && v17 != -1) {
			*(uint32_t*)(nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830108, 1961)->field_8 + 48) = v17;
			v15 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830108, 1962);
			nox_window_call_field_94(*(int*)&dword_5d4594_830108, 16391, (int)v15, 0);
		}
		result = 1;
	}
	return result;
}

//----- (00449A10) --------------------------------------------------------
uint32_t* nox_xxx_dialogMsgBoxCreate_449A10(nox_window* win, wchar_t* a2, wchar_t* text, int a4, void (*a5)(void),
											void (*a6)(void)) {
	int a1 = win;
	int v6;           // esi
	uint32_t* result; // eax
	uint32_t* v8;     // eax
	uint32_t* v9;     // eax
	uint32_t* v10;    // eax
	uint32_t* v11;    // eax

	v6 = nox_strman_get_lang_code();
	if (dword_5d4594_830224 && func_5d4594_830216) {
		func_5d4594_830216();
	}
	dword_5d4594_830228 = a1;
	dword_5d4594_830232 = 0;
	func_5D4594_830220 = a5;
	func_5d4594_830216 = a6;
	if (dword_5d4594_830224) {
		sub_449EA0(a4);
		if (a2) {
			sub_449E00(a2);
		}
		result = (uint32_t*)text;
		if (text) {
			result = (uint32_t*)sub_449E30(text);
		}
	} else {
		*getMemU32Ptr(0x5D4594, 830240) = 0;
		if (nox_xxx_guiFontHeightMB_43F320(0) > 10) {
			v6 = 2;
		}
		result =
			nox_new_window_from_file(*(const char**)getMemAt(0x587000, 112976 + 4 * v6), nox_xxx_windowDlgProc_449CA0);
		dword_5d4594_830224 = result;
		if (result) {
			nox_xxx_wndSetWindowProc_46B300((int)result, sub_449BE0);
			v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4003);
			nox_xxx_wndSetWindowProc_46B300((int)v8, sub_449C30);
			v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4008);
			nox_xxx_wndSetWindowProc_46B300((int)v9, sub_449C30);
			if (a2) {
				v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4005);
				nox_window_call_field_94((int)v10, 16385, a2, -1);
			}
			if (text) {
				v11 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4004);
				nox_window_call_field_94((int)v11, 16385, text, -1);
			}
			sub_46B120(*(uint32_t**)&dword_5d4594_830224, 0);
			nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_830224);
			sub_46C690(*(int*)&dword_5d4594_830224);
			nox_window_setPos_46A9B0(*(uint32_t**)&dword_5d4594_830224,
									 (nox_win_width - *(int*)(dword_5d4594_830224 + 8)) / 2,
									 (nox_win_height - *(int*)(dword_5d4594_830224 + 12)) / 2);
			sub_449EA0(a4);
			result = (uint32_t*)nox_xxx_wndGetCaptureMain_46AE00();
			dword_5d4594_830236 = result;
			if (result) {
				result = (uint32_t*)nox_xxx_wndClearCaptureMain_46ADE0((int)result);
			}
		}
	}
	return result;
}

//----- (00449BE0) --------------------------------------------------------
int sub_449BE0(int a1, int a2, int a3, int a4) {
	if (a2 != 21) {
		return 0;
	}
	if (a3 == 1) {
		return 1;
	}
	if (a3 == 57) {
		nox_point mpos = nox_client_getMousePos_4309F0();
		nox_window_call_field_93(a1, 5, mpos.x | (mpos.y << 16), 0);
	}
	return 0;
}

//----- (00449C30) --------------------------------------------------------
int sub_449C30(uint32_t* a1, int a2, int a3, int a4) {
	uint32_t* v4; // eax
	int v5;       // esi

	if (a2 == 21 && a3 == 28) {
		v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4001);
		v5 = (int)v4;
		if (v4[1] & 8) {
			if (!wndIsShown_nox_xxx_wndIsShown_46ACC0((int)v4)) {
				nox_window_call_field_94(*(int*)&dword_5d4594_830224, 16391, v5, 0);
			}
		}
	}
	return nox_xxx_wndEditProc_487D70(a1, a2, a3, a4);
}

//----- (00449CA0) --------------------------------------------------------
int nox_xxx_windowDlgProc_449CA0(int a1, int a2, int* a3, int a4) {
	int result; // eax
	int v5;     // eax

	if (a2 == 23) {
		return 1;
	}
	if (a2 != 16391) {
		return 0;
	}
	switch (nox_xxx_wndGetID_46B0A0(a3)) {
	case 4001:
	case 4007:
		if (getMemByte(0x5D4594, 830240) & 0x20) {
			nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_830224);
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_830228, 16391, (int)a3, a4);
		if (func_5D4594_830220) {
			func_5D4594_830220();
		}
		if (!(getMemByte(0x5D4594, 830240) & 0x20)) {
			return 0;
		}
		sub_44A400();
		result = 0;
		break;
	case 4002:
	case 4006:
		if (getMemByte(0x5D4594, 830240) & 0x20) {
			nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_830224);
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_830228, 16391, (int)a3, a4);
		if (func_5d4594_830216) {
			func_5d4594_830216();
		}
		if (!(getMemByte(0x5D4594, 830240) & 0x20)) {
			return 0;
		}
		sub_44A400();
		result = 0;
		break;
	case 4009:
		sub_41E300(9);
		v5 = sub_41E2F0();
		sub_41DA70(v5, 8);
		nox_game_checkStateWol_43C260();
		sub_44A200(256);
		sub_44A400();
		return 0;
	case 4010:
		nox_window_call_field_94(*(int*)&dword_5d4594_830228, 16391, (int)a3, a4);
		result = 0;
		break;
	default:
		return 0;
	}
	return result;
}

//----- (00449E00) --------------------------------------------------------
int sub_449E00(int a1) {
	uint32_t* v1; // eax

	v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4005);
	return nox_window_call_field_94((int)v1, 16385, a1, -1);
}

//----- (00449E30) --------------------------------------------------------
int sub_449E30(int a1) {
	uint32_t* v1; // eax

	v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4004);
	return nox_window_call_field_94((int)v1, 16385, a1, -1);
}

//----- (00449E60) --------------------------------------------------------
int sub_449E60(char a1) {
	uint32_t* v1; // eax

	if (a1 >= 0) {
		v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4003);
	} else {
		v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4008);
	}
	return nox_window_call_field_94((int)v1, 16413, 0, 0);
}

//----- (00449EA0) --------------------------------------------------------
void sub_449EA0(int a1) {
	short v1;     // bx
	uint32_t* v2; // esi
	uint32_t* v3; // esi
	uint32_t* v4; // esi
	uint32_t* v5; // esi
	uint32_t* v6; // esi
	uint32_t* v7; // esi
	uint32_t* v8; // esi
	uint32_t* v9; // esi
	int v11;      // [esp-4h] [ebp-Ch]
	int v12;      // [esp-4h] [ebp-Ch]
	int v13;      // [esp-4h] [ebp-Ch]
	int v14;      // [esp-4h] [ebp-Ch]
	int v15;      // [esp-4h] [ebp-Ch]
	int v16;      // [esp-4h] [ebp-Ch]
	int v17;      // [esp-4h] [ebp-Ch]
	int v18;      // [esp-4h] [ebp-Ch]

	v1 = a1 ^ *getMemU16Ptr(0x5D4594, 830240);
	if (((unsigned char)a1 ^ getMemByte(0x5D4594, 830240)) & 1) {
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4001);
		v11 = wndIsShown_nox_xxx_wndIsShown_46ACC0((int)v2) == 0;
		nox_window_set_hidden((int)v2, v11);
	}
	if (v1 & 2) {
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4002);
		v12 = wndIsShown_nox_xxx_wndIsShown_46ACC0((int)v3) == 0;
		nox_window_set_hidden((int)v3, v12);
	}
	if (v1 & 0x100) {
		v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4009);
		v13 = wndIsShown_nox_xxx_wndIsShown_46ACC0((int)v4) == 0;
		nox_window_set_hidden((int)v4, v13);
	}
	if (v1 & 0x200) {
		v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4010);
		v14 = wndIsShown_nox_xxx_wndIsShown_46ACC0((int)v5) == 0;
		nox_window_set_hidden((int)v5, v14);
	}
	if (v1 & 8) {
		v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4007);
		v15 = wndIsShown_nox_xxx_wndIsShown_46ACC0((int)v6) == 0;
		nox_window_set_hidden((int)v6, v15);
	}
	if (v1 & 0x10) {
		v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4006);
		v16 = wndIsShown_nox_xxx_wndIsShown_46ACC0((int)v7) == 0;
		nox_window_set_hidden((int)v7, v16);
	}
	if (v1 & 4) {
		v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4003);
		v17 = wndIsShown_nox_xxx_wndIsShown_46ACC0((int)v8) == 0;
		nox_window_set_hidden((int)v8, v17);
	}
	if ((v1 & 0x80u) != 0) {
		v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4008);
		v18 = wndIsShown_nox_xxx_wndIsShown_46ACC0((int)v9) == 0;
		nox_window_set_hidden((int)v9, v18);
	}
	if (a1 & 0x40) {
		nox_xxx_setMouseBounds_430A70(*(uint32_t*)(dword_5d4594_830224 + 16), *(uint32_t*)(dword_5d4594_830224 + 24),
									  *(uint32_t*)(dword_5d4594_830224 + 20), *(uint32_t*)(dword_5d4594_830224 + 28));
	} else {
		nox_xxx_setMouseBounds_430A70(0, nox_win_width - 1, 0, nox_win_height - 1);
	}
	*getMemU32Ptr(0x5D4594, 830240) = a1;
}

//----- (0044A0B0) --------------------------------------------------------
int sub_44A0B0(int a1) {
	uint32_t* v1; // eax
	uint32_t* v2; // eax
	uint32_t* v3; // eax
	uint32_t* v4; // eax
	uint32_t* v5; // eax
	uint32_t* v6; // eax
	uint32_t* v7; // eax
	uint32_t* v8; // eax
	int result;   // eax

	if (a1 & 1) {
		v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4001);
		nox_window_set_hidden((int)v1, 0);
	}
	if (a1 & 2) {
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4002);
		nox_window_set_hidden((int)v2, 0);
	}
	if (a1 & 0x100) {
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4009);
		nox_window_set_hidden((int)v3, 0);
	}
	if (a1 & 0x200) {
		v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4010);
		nox_window_set_hidden((int)v4, 0);
	}
	if (a1 & 8) {
		v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4007);
		nox_window_set_hidden((int)v5, 0);
	}
	if (a1 & 0x10) {
		v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4006);
		nox_window_set_hidden((int)v6, 0);
	}
	if (a1 & 4) {
		v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4003);
		nox_window_set_hidden((int)v7, 0);
	}
	if ((a1 & 0x80u) != 0) {
		v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4008);
		nox_window_set_hidden((int)v8, 0);
	}
	if (a1 & 0x40) {
		nox_xxx_setMouseBounds_430A70(*(uint32_t*)(dword_5d4594_830224 + 16), *(uint32_t*)(dword_5d4594_830224 + 20),
									  *(uint32_t*)(dword_5d4594_830224 + 24), *(uint32_t*)(dword_5d4594_830224 + 28));
	} else {
		nox_xxx_setMouseBounds_430A70(0, nox_win_width - 1, 0, nox_win_height - 1);
	}
	result = a1 | *getMemU32Ptr(0x5D4594, 830240);
	*getMemU32Ptr(0x5D4594, 830240) |= a1;
	return result;
}

//----- (0044A200) --------------------------------------------------------
int sub_44A200(int a1) {
	uint32_t* v1; // eax
	uint32_t* v2; // eax
	uint32_t* v3; // eax
	uint32_t* v4; // eax
	uint32_t* v5; // eax
	uint32_t* v6; // eax
	uint32_t* v7; // eax
	uint32_t* v8; // eax
	int result;   // eax

	if (a1 & 1) {
		v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4001);
		nox_window_set_hidden((int)v1, 1);
	}
	if (a1 & 2) {
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4002);
		nox_window_set_hidden((int)v2, 1);
	}
	if (a1 & 0x100) {
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4009);
		nox_window_set_hidden((int)v3, 1);
	}
	if (a1 & 0x200) {
		v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4010);
		nox_window_set_hidden((int)v4, 1);
	}
	if (a1 & 8) {
		v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4007);
		nox_window_set_hidden((int)v5, 1);
	}
	if (a1 & 0x10) {
		v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4006);
		nox_window_set_hidden((int)v6, 1);
	}
	if (a1 & 4) {
		v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4003);
		nox_window_set_hidden((int)v7, 1);
	}
	if ((a1 & 0x80u) != 0) {
		v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4008);
		nox_window_set_hidden((int)v8, 1);
	}
	if (a1 & 0x40) {
		nox_xxx_setMouseBounds_430A70(0, nox_win_width - 1, 0, nox_win_height - 1);
	}
	result = ~a1 & *getMemU32Ptr(0x5D4594, 830240);
	*getMemU32Ptr(0x5D4594, 830240) &= ~a1;
	return result;
}

//----- (0044A340) --------------------------------------------------------
int sub_44A340(int a1, int a2) { return nox_window_setPos_46A9B0(*(uint32_t**)&dword_5d4594_830224, a1, a2); }

//----- (0044A360) --------------------------------------------------------
void sub_44A360(int a1) {
	uint32_t* v1; // esi
	uint32_t* v2; // esi
	int result;   // eax

	v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4005);
	if (a1 == 1) {
		v1[59] = nox_xxx_guiFontPtrByName_43F360("large");
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4004);
		result = nox_xxx_guiFontPtrByName_43F360("large");
	} else {
		v1[59] = nox_xxx_guiFontPtrByName_43F360("default");
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4004);
		result = nox_xxx_guiFontPtrByName_43F360("default");
	}
	v2[59] = result;
}

//----- (0044A400) --------------------------------------------------------
int sub_44A400() {
	int result; // eax

	result = dword_5d4594_830224;
	if (dword_5d4594_830224) {
		if (dword_5d4594_830236) {
			nox_xxx_wndSetCaptureMain_46ADC0(*(int*)&dword_5d4594_830236);
			dword_5d4594_830236 = 0;
		}
		nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_830224);
		nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_830224);
		nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_830224);
		if (dword_5d4594_830232) {
			nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_830232);
		}
		dword_5d4594_830224 = 0;
		dword_5d4594_830228 = 0;
		nox_client_setCursorType_477610(0);
		nox_xxx_setMouseBounds_430A70(0, nox_win_width - 1, 0, nox_win_height - 1);
	}
	return result;
}

//----- (0044A4A0) --------------------------------------------------------
int sub_44A4A0() { return dword_5d4594_830224 != 0; }

//----- (0044A4B0) --------------------------------------------------------
int sub_44A4B0() {
	int result; // eax

	result = dword_5d4594_830224;
	if (dword_5d4594_830224) {
		result = nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_830224);
	}
	return result;
}

//----- (0044A4D0) --------------------------------------------------------
int sub_44A4D0(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_830232 = a1;
	return result;
}

//----- (0044A4E0) --------------------------------------------------------
int sub_44A4E0() {
	uint32_t* v0; // eax

	if (!sub_44A4A0()) {
		return 0;
	}
	v0 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830224, 4002);
	nox_window_call_field_94(*(int*)&dword_5d4594_830224, 16391, (int)v0, 0);
	return 1;
}

//----- (0044A520) --------------------------------------------------------
char* sub_44A520(int a1) {
	int v1;            // eax
	int v2;            // edx
	unsigned char* v3; // ecx

	v1 = *getMemU32Ptr(0x587000, 113136);
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 113136)) {
		return *(char**)getMemAt(0x587000, 113140);
	}
	v3 = getMemAt(0x587000, 113136);
	while (v1 != a1) {
		v1 = *((uint32_t*)v3 + 2);
		v3 += 8;
		++v2;
		if (!v1) {
			return *(char**)getMemAt(0x587000, 113140);
		}
	}
	return *(char**)getMemAt(0x587000, 113140 + 8 * v2);
}

//----- (0044AA40) --------------------------------------------------------
int sub_44AA40() {
	nox_wnd_xxx_830244->state = NOX_GUI_ANIM_OUT;
	sub_43BE40(2);
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100);
	sub_4207F0(1);
	return 1;
}

//----- (0044AA70) --------------------------------------------------------
int sub_44AA70() {
	int (*v0)(void); // esi

	v0 = nox_wnd_xxx_830244->field_13;
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_830244);
	if (dword_5d4594_830248) {
		nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_830248);
		dword_5d4594_830248 = 0;
	}
	sub_43BE40(1);
	v0();
	return 1;
}

//----- (0044AAC0) --------------------------------------------------------
int sub_44AAC0() { return 0; }

//----- (0044AAD0) --------------------------------------------------------
int sub_44AAD0(uint32_t* a1, int a2, int a3, int a4) {
	if (a2 == 21) {
		if (dword_5d4594_830268) {
			nox_window_call_field_94((int)a1, 16414, (int)getMemAt(0x5D4594, 830284), 0);
			sub_41FAE0((const char*)getMemAt(0x5D4594, 830288));
		}
		dword_5d4594_830268 = 0;
	}
	return nox_xxx_wndEditProc_487D70(a1, a2, a3, a4);
}

//----- (0044AB30) --------------------------------------------------------
int sub_44AB30(int a1, unsigned int a2, int* a3, int a4) {
	int result;        // eax
	int v5;            // eax
	int v6;            // esi
	int v7;            // eax
	int v8;            // eax
	int v9;            // esi
	int v10;           // esi
	int v11;           // eax
	int v12;           // eax
	int v13;           // eax
	char* v14;         // eax
	int v15;           // eax
	int v16;           // [esp-4h] [ebp-210h]
	uint8_t* v17;      // [esp+4h] [ebp-208h]
	int v18;           // [esp+8h] [ebp-204h]
	wchar_t File[128]; // [esp+Ch] [ebp-200h]
	char v20[256];     // [esp+10Ch] [ebp-100h]

	if (a2 > 0x4005) {
		if (a2 != 16391) {
			if (a2 == 16400) {
				v6 = nox_xxx_wndGetID_46B0A0(a3);
				nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
				if (v6 == 1708 && a4 >= 0 && a4 < 128) {
					sub_41FC20(a4);
					sub_41FB90(a4, &v18, &v17);
					if (v18) {
						nox_swprintf(File, L"%S", v18);
						nox_window_call_field_94(*(int*)&dword_5d4594_830256, 16414, (int)File, 0);
					}
					if (v17) {
						nox_swprintf(File, L"%S", v17);
						nox_window_call_field_94(*(int*)&dword_5d4594_830260, 16414, (int)File, 0);
						if (v17) {
							if (*v17) {
								*(uint32_t*)(dword_5d4594_830252 + 36) |= 4u;
								dword_5d4594_830276 = 1;
								return 0;
							}
						}
					}
					*(uint32_t*)(dword_5d4594_830252 + 36) &= 0xFFFFFFFB;
					dword_5d4594_830276 = 0;
				}
			}
			return 0;
		}
		v7 = nox_xxx_wndGetID_46B0A0(a3);
		if (v7 > 1706) {
			if (v7 != 1985) {
				if (v7 == 4010) {
					v16 = sub_4200F0();
					v14 = sub_44A520(*getMemIntPtr(0x5D4594, 830280));
					nox_sprintf((char*)File, "%s%d.html", v14, v16);
					ShellExecuteA(0, 0, (const char*)File, 0, (const char*)getMemAt(0x587000, 113732), 3);
				}
				goto LABEL_42;
			}
		} else {
			if (v7 != 1706) {
				v8 = v7 - 1703;
				if (v8) {
					if (v8 == 2) {
						sub_41E300(6);
						sub_4207F0(6);
						nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_830248, 0);
						sub_40E090();
						sub_4A1BE0(0);
					}
				} else {
					dword_5d4594_830276 ^= 1u;
					if (dword_5d4594_830276) {
						v10 = sub_41F9A0();
						nox_window_call_field_94(*(int*)&dword_5d4594_830264, 16403, v10, 0);
						sub_41FC20(v10);
					} else {
						v9 = sub_41FB60();
						sub_41FC20(128);
						sub_41FB70(v9);
					}
				}
				goto LABEL_42;
			}
			v17 = 0;
			if (!dword_5d4594_830276) {
				sub_41FC20(128);
			}
			v11 = nox_window_call_field_94(*(int*)&dword_5d4594_830256, 16413, 0, 0);
			nox_sprintf(v20, "%S", v11);
			sub_41FA80(v20);
			v12 = nox_window_call_field_94(*(int*)&dword_5d4594_830260, 16413, 0, 0);
			nox_sprintf(v20, "%S", v12);
			sub_41FAE0(v20);
			sub_41FC50();
			v13 = sub_41FC40();
			sub_40DB50(v13 + 1, (int)&v17);
			if (!v17) {
				sub_4B5770_wol_locale(*(int*)&dword_5d4594_830248);
			LABEL_42:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				return 1;
			}
		}
		dword_5d4594_830276 = (unsigned char)(*(uint8_t*)(dword_5d4594_830252 + 36) & 4) >> 2;
		sub_41E300(2);
		v15 = sub_41E2F0();
		sub_41DA70(v15, 0);
		sub_4207F0(2);
		sub_40E090();
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_830248, 0);
		sub_4A1BE0(0);
		goto LABEL_42;
	}
	if (a2 == 16389) {
		nox_xxx_clientPlaySoundSpecial_452D80(920, 100);
		return 1;
	}
	if (a2 == 2) {
		dword_5d4594_830248 = 0;
		return 0;
	}
	if (a2 != 16387) {
		return 0;
	}
	result = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_830248, a4);
	if (!result) {
		return result;
	}
	if ((unsigned short)a3 != 1) {
		return 0;
	}
	if (a4 == 1702) {
		v5 = nox_window_call_field_94(result, 16413, 0, 0);
		nox_sprintf(v20, "%S", v5);
		if (v20[0]) {
			dword_5d4594_830268 = 1;
		}
	}
	return 0;
}

//----- (0044AF70) --------------------------------------------------------
int sub_44AF70() {
	int result; // eax

	nox_wnd_xxx_830244->state = NOX_GUI_ANIM_OUT;
	sub_43BE40(2);
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100);
	result = 1;
	nox_wnd_xxx_830244->field_13 = nox_game_showWolChat_447620;
	dword_5d4594_830248 = 0;
	return result;
}

//----- (0044AFB0) --------------------------------------------------------
uint32_t* sub_44AFB0(int a1, int a2, int a3) {
	uint32_t* result; // eax

	if (a3 < -2147221388 || a3 > -2147221386) {
		result = nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_830248, a1, a2, 33, 0, 0);
	} else {
		result = nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_830248, a1, a2, 545, 0, 0);
	}
	*getMemU32Ptr(0x5D4594, 830280) = a3;
	return result;
}

//----- (0044B000) --------------------------------------------------------
void nox_xxx____setargv_4_44B000() { dword_5d4594_830272 = 1; }

//----- (0044B0F0) --------------------------------------------------------
int sub_44B0F0(int a1, int a2, int* a3, int a4) {
	int v3; // eax

	if (a2 != 23) {
		if (a2 == 16391) {
			v3 = nox_xxx_wndGetID_46B0A0(a3) - 581;
			if (!v3) {
				nox_xxx____setargv_4_44B000();
				nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_830292);
				goto LABEL_7;
			}
			if (v3 == 1) {
				nox_client_quit_4460C0();
				sub_44A400();
				nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_830292);
			LABEL_7:
				dword_5d4594_830292 = 0;
				return 0;
			}
		}
		return 0;
	}
	return 1;
}

// 44B47F: variable 'v19' is possibly undefined

// 44B68C: variable 'v21' is possibly undefined
// 44B8B0: using guessed type char var_100[256];

//----- (0044B940) --------------------------------------------------------
int sub_44B940(uint32_t* a1, int a2, nox_memfile* f) {
	int v3;            // esi
	int v4;            // ebx
	void* v5;          // eax
	int v6;            // ebp
	int v8;            // ebx
	char v10;          // cl
	int v13;           // [esp+10h] [ebp-90h]
	int v14;           // [esp+14h] [ebp-8Ch]
	unsigned char v15; // [esp+18h] [ebp-88h]
	const char* v16;   // [esp+1Ch] [ebp-84h]
	char v17[128];     // [esp+20h] [ebp-80h]

	v3 = a2;
	v4 = 0;
	*a1 = 40;
	v14 = 0;
	while (1) {
		v13 = v4 >= 16 ? v4 + 4 : v4;
		v5 = calloc(v3, 4);
		*(uint32_t*)((char*)a1 + v13 + 4) = v5;
		if (!v5) {
			break;
		}
		v6 = 0;
		if (v3 > 0) {
			do {
				v8 = nox_memfile_read_i32(f);
				v17[0] = getMemByte(0x5D4594, 830840);
				if (v8 == -1) {
					v10 = nox_memfile_read_i8(f);
					v15 = nox_memfile_read_u8(f);
					LOBYTE(v16) = v10;
					nox_memfile_read(v17, 1, v15, f);
					v17[v15] = 0;
					v3 = a2;
				}
				*(uint32_t*)(*(uint32_t*)((char*)a1 + v13 + 4) + 4 * ++v6 - 4) = nox_xxx_readImgMB_42FAA0(v8, v16, v17);
			} while (v6 < v3);
			v4 = v14;
		}
		v4 += 4;
		v14 = v4;
		if (v4 >= 32) {
			return 1;
		}
	}
	return 0;
}
// 44BA0E: variable 'v16' is possibly undefined
// 44B940: using guessed type char var_80[128];

//----- (0044BA60) --------------------------------------------------------
int nox_xxx_parse_Armor_44BA60(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 113856);
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 113960)) {
			return -1;
		}
	}
	return v1;
}

//----- (0044BAC0) --------------------------------------------------------
int sub_44BAC0(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 113964);
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 114072)) {
			return -1;
		}
	}
	return v1;
}

//----- (0044BB20) --------------------------------------------------------
int sub_44BB20(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 115688);
	while (strcmp(a1, *v2)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 115908)) {
			return -1;
		}
	}
	return v1;
}
// 44BD0C: variable 'v15' is possibly undefined
// 44BC50: using guessed type char var_80[128];
// 44BE2F: variable 'v11' is possibly undefined
// 44BF33: variable 'v11' is possibly undefined
// 44BE90: using guessed type char var_80[128];
// 44C0BD: variable 'v13' is possibly undefined
