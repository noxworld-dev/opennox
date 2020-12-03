// This must come before the SDL includes.
#ifndef DRAW_COMMON_H
#define DRAW_COMMON_H

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#endif

#include "proto.h"

extern unsigned char byte_581450_9176[160];
extern unsigned char byte_581450_9336[160];

extern _DWORD dword_5d4594_823772;
extern _DWORD dword_5d4594_1193568;
extern _DWORD dword_5d4594_1193576;
extern _DWORD dword_5d4594_810628;
extern _DWORD dword_5d4594_808564;
extern _DWORD dword_5d4594_1311936;
extern _DWORD dword_5d4594_1193672;
extern _DWORD dword_5d4594_1193624;
extern _DWORD dword_5d4594_1193664;
extern _DWORD dword_5d4594_1193524;
extern _DWORD dword_5d4594_1193648;
extern _DWORD dword_5d4594_3798728;
extern _DWORD dword_5d4594_808568;
extern _DWORD dword_5d4594_1193668;
extern _DWORD dword_5d4594_787144;
extern _DWORD dword_5d4594_823776;
extern BYTE* nox_pixbuffer_3798780;
extern _DWORD dword_5d4594_1193704;
extern _DWORD dword_5d4594_3804668;
extern _DWORD dword_5d4594_1193584;
extern int nox_pitch_3801808;
extern _DWORD dword_5d4594_3801804;
extern _DWORD dword_5d4594_3799492;
extern _DWORD dword_5d4594_810640;
extern _DWORD dword_5d4594_1193516;
extern _DWORD dword_5d4594_3799624;
extern _DWORD dword_5d4594_3801780;
extern _DWORD dword_5d4594_3804672;
extern _DWORD dword_5d4594_3804656;
extern _DWORD dword_5d4594_3804664;
extern BYTE** nox_pixbuffer_rows_3798784;
extern int nox_enable_audio;

extern int nox_win_width;
extern int nox_win_height;

extern obj_5D4594_3799572_t* ptr_5D4594_3799572;
extern obj_5D4594_3799572_t obj_5D4594_3799660;
extern obj_5D4594_3799572_t obj_5D4594_3800716;

extern HANDLE* nox_video_cursorDrawThreadHandle;
extern DWORD dword_974854;

extern int g_fullscreen;
extern int g_scaled;

#ifndef IGNORE_EXTERNS
extern unsigned char byte_5D4594_3804364[160];

extern void* nox_backbuffer1_pix;
extern void* nox_backbuffer_pix;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;
extern int nox_backbuffer_depth;

extern int nox_video_renderTargetFlags;
extern int nox_video_pauseThreadedDrawCursor;
extern int nox_video_drawCursorThreadOk;
extern int nox_video_allowCursorDrawThread;
extern int nox_video_windowsPlatformVersion;
extern int nox_video_cursorDrawIsThreaded;
extern int nox_video_gammaValue;
extern int (*func_5d4594_1311924)(void);

extern DWORD dword_973C70;
extern DWORD g_present_ticks;
extern DWORD g_backbuffer_count;
extern DWORD dword_5ACFAC;
extern DWORD dword_6F7B9C;
extern void (*g_present_ptr)();
extern DWORD dword_6F7BB0;
extern DWORD dword_6F7BF8;
extern BYTE* dword_6F7C74;
extern BYTE* dword_6F7C78;
extern int (*nox_video_cursorThreadedDrawFnPtr)(int);
extern void (*dword_6F7C10)(_DWORD, _DWORD, _DWORD);
extern __int16 (*dword_6F7C40)();
extern __int16 (*dword_6F7C34)();
extern void (*dword_975240)(_DWORD, _DWORD*, _DWORD*, _DWORD*);
extern int (*dword_975380)(_DWORD, _DWORD, _DWORD);
extern void (*nox_color_rgb_func)(uint8_t, uint8_t, uint8_t, uint32_t*);
extern void (*g_copy_backbuffer_ptr)();

extern SDL_Surface* dword_6F7C48;
extern SDL_Surface* g_cursor_surf;
extern SDL_Surface* dword_973C60;
extern SDL_Surface* g_backbuffer1;
extern SDL_Surface* dword_973C88;
extern Uint32 g_format;

extern SDL_Window* windowHandle_dword_973FE0;

extern int g_rotate;
extern int g_rotated;

extern float draw_gamma;

extern unsigned int g_tex_coord_itemsize, g_tex_coord_numitems;

extern int nox_backbuffer_pitch32;
extern int nox_backbuffer_width32;

#endif

enum {
	DDSD_CAPS = 1,
	DDSD_WIDTH = 2,
	DDSD_HEIGHT = 4,
};

enum {
	DDSCAPS_OFFSCREENPLAIN = 1,
	DDSCAPS_SYSTEMMEMORY = 2,
	DDSCAPS_VIDEOMEMORY = 4,
	DDSCAPS_PRIMARYSURFACE = 8,
};

#endif
