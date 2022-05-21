// This must come before the SDL includes.
#ifndef NOX_PORT_CLIENT_VIDEO_DRAW_COMMON_H
#define NOX_PORT_CLIENT_VIDEO_DRAW_COMMON_H

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
#include "common__magic__speltree.h"
#include "defs.h"
#include "input.h"
#include "input_common.h"
#include "server__network__mapsend.h"
#include "server__script__builtin.h"
#include "server__script__script.h"
#include "server__xfer__savegame__savegame.h"
#include "thing.h"
#include "win.h"

int nox_getBackbufWidth();
int nox_getBackbufHeight();

#define __m64 void

extern unsigned char byte_581450_9176[160];
extern unsigned char byte_581450_9336[160];

extern uint32_t dword_5d4594_823772;
extern uint32_t dword_5d4594_810628;
extern uint32_t dword_5d4594_808564;
extern uint32_t dword_5d4594_1311936;
extern uint32_t dword_5d4594_1193672;
extern void* dword_5d4594_1193624;
extern uint32_t dword_5d4594_1193664;
extern uint32_t dword_5d4594_1193524;
extern uint32_t dword_5d4594_1193648;
extern uint32_t dword_5d4594_3798728;
extern uint32_t dword_5d4594_808568;
extern uint32_t dword_5d4594_1193668;
extern uint32_t nox_video_bag_ready;
extern uint32_t dword_5d4594_823776;
extern uint8_t* nox_pixbuffer_3798780;
extern void* dword_5d4594_1193704;
extern int nox_backbuffer_pitch_3801808;
extern uint32_t cpuid_5d4594_3801804;
void* nox_video_getImagePixdata_func(nox_video_bag_image_t*);
extern void* dword_5d4594_810640;
extern uint32_t nox_video_pixmode_3799624;
extern uint32_t nox_video_modeXxx_3801780;
extern unsigned char* nox_draw_colors_r_3804672;
extern unsigned char* nox_draw_colors_g_3804656;
extern unsigned char* nox_draw_colors_b_3804664;
extern uint8_t** nox_pixbuffer_rows_3798784;
extern int nox_enable_audio;

extern int nox_win_width;
extern int nox_win_height;

extern nox_render_data_t* nox_draw_curDrawData_3799572;
extern nox_render_data_t obj_5D4594_3799660;
extern nox_render_data_t obj_5D4594_3800716;

extern uint32_t dword_974854;

extern int g_scaled;

#ifndef IGNORE_EXTERNS

extern void* nox_backbuffer1_pix;
extern void* nox_backbuffer_pix;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;
extern int nox_backbuffer_depth;

extern int nox_video_renderTargetFlags;
extern int nox_video_windowsPlatformVersion;
extern int nox_video_cursorDrawIsThreaded;
extern int nox_video_gammaValue;
extern int (*func_5d4594_1311924)(void);

extern uint32_t dword_973C70;
extern uint32_t g_backbuffer_count;
extern uint32_t dword_5ACFAC;
extern uint32_t dword_6F7B9C;
extern uint32_t dword_6F7BB0;
extern uint32_t g_cursor_surf_pitch;
extern uint8_t* g_cursor_surf_pixels;
extern uint8_t* g_cursor_surf_pixels_6F7C78;
extern void (*dword_6F7C10)(uint32_t, uint32_t, uint32_t);

void nox_video_setGammaSlider(int v);

extern int nox_backbuffer_pitchDiff;
extern int nox_backbuffer_width32;

#endif // IGNORE_EXTERNS

int nox_video_getFullScreen();
void nox_video_setFullScreen(int v);

void updateGamma(int value);
int sub_433CD0(uint8_t a1, uint8_t a2, uint8_t a3);
int sub_433E40(int a1);
void sub_434040(int a1);
void sub_4340A0(int a1, int a2, int a3, int a4);
int nox_xxx_drawPlayer_4341D0(int a1, int a2);
void nox_set_color_rgb_434430(int r, int g, int b);
uint32_t nox_color_rgb_4344A0(int r, int g, int b);
int sub_4347F0(char* a1, int a2);
int sub_4348C0();
int sub_434FB0();
void sub_4352E0();
void sub_4353C0();
void sub_4353F0();
void sub_444C50();
bool nox_xxx_makeFillerColor_48BDE0();
void nox_video_callCopyBackBuffer_4AD170(void);
int sub_4B0300(char* a1);
void sub_4B0640(void* a1);

#endif // NOX_PORT_CLIENT_VIDEO_DRAW_COMMON_H
