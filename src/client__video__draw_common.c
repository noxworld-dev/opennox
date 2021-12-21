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

#ifndef NOX_CGO
void* nox_backbuffer_pix = 0;
void* nox_backbuffer1_pix = 0;
int nox_backbuffer_width = 0;
int nox_backbuffer_height = 0;
int nox_backbuffer_depth = 0;
int nox_backbuffer_pitchDiff;
int nox_backbuffer_width32;
int nox_video_gammaValue = 1;

int nox_video_allowCursorDrawThread = 0;
int nox_video_drawCursorThreadOk = 0;
int nox_video_pauseThreadedDrawCursor = 0;
int nox_video_cursorDrawIsThreaded = 0;
void (*dword_6F7C10)(uint32_t, uint32_t, uint32_t);

uint32_t dword_974854;
uint32_t dword_973C70;
uint32_t dword_5ACFAC;
uint32_t dword_6F7B9C;
uint32_t dword_6F7BB0;
#endif // NOX_CGO

uint32_t dword_973C64;
short (*dword_6F7C40)();
short (*dword_6F7C34)();

int nox_video_renderTargetFlags = 0;
int nox_video_windowsPlatformVersion = 0;
int (*func_5d4594_1311924)(void) = 0;

void (*dword_975240)(uint32_t, uint32_t*, uint32_t*, uint32_t*);
int (*dword_975380)(uint32_t, uint32_t, uint32_t);
#ifndef NOX_CGO
void (*nox_color_rgb_func)(uint8_t, uint8_t, uint8_t, uint32_t*);
#else  // NOX_CGO
void nox_color_rgb_func(uint8_t r, uint8_t g, uint8_t b, uint32_t* p);
int nox_color_rgb_func_get();
void nox_color_rgb_func_set(int mode);
#endif // NOX_CGO

unsigned char* nox_draw_colors_r_3804672 = 0;
unsigned char* nox_draw_colors_g_3804656 = 0;
unsigned char* nox_draw_colors_b_3804664 = 0;
unsigned int dword_5d4594_3799476 = 0;
unsigned int dword_5d4594_3799552 = 0;
unsigned int dword_5d4594_3799484 = 0;
unsigned int dword_5d4594_3799508 = 0;

#ifndef NOX_CGO
uint32_t g_backbuffer_count;
uint32_t g_cursor_surf_pitch;
uint8_t* g_cursor_surf_pixels;
uint8_t* g_cursor_surf_pixels_6F7C78;
uint32_t cpuid_5d4594_3801804 = 0; // always 0
uint32_t g_present_ticks;
void (*g_copy_backbuffer_ptr)();
SDL_Surface* g_backbuffer1;
SDL_Surface* g_cursor_surf_6F7C48;
SDL_Surface* g_cursor_surf;

SDL_Surface* g_surface_973C60;
SDL_Surface* g_surface_973C88;

int nox_getBackbufWidth() { return nox_backbuffer_width; }
int nox_getBackbufHeight() { return nox_backbuffer_height; }

static inline void rect_to_sdl(const RECT* r, SDL_Rect* sr) {
	sr->x = r->left;
	sr->y = r->top;
	sr->w = r->right - r->left;
	sr->h = r->bottom - r->top;
}
unsigned int g_format;
int g_rotate;
int g_rotated;
float draw_gamma = 1.0f;

SDL_Surface* nox_video_createSurface_48A600(int w, int h, int a4);
int nox_video_getSurfaceData_48A720(SDL_Surface* surf, int* outPitch, void** outPixels);
void nox_video_lockSurface_48A670(SDL_Surface* a1);
void nox_video_unlockSurface_48A6B0(SDL_Surface* a1);

void sdl_present();
int sdl_drawCursorThreaded(int);
int create_surfaces(int width, int height);

//----- (00444AC0) --------------------------------------------------------
int nox_client_drawXxx_444AC0(int w, int h, int depth, int flags) {
	int v5;               // eax
	bool v6;              // zf
	unsigned char v7 = 0; // al
	int v8;               // esi
	int v9;               // eax
	int v10;              // eax

	nox_mutex_init(getMemAt(0x973F18, 168));
	*getMemU32Ptr(0x5D4594, 823780) = 1;

	nox_backbuffer_width = w;
	nox_backbuffer_height = h;
	nox_backbuffer_depth = depth;
	nox_video_renderTargetFlags = flags;

#ifdef __EMSCRIPTEN__
	v5 = nox_client_winVerGetMajor_48C870(0); // Check Windows version
#else                                         // !__EMSCRIPTEN__
#ifdef USE_SDL
	v5 = 5; // Force always WINNT, forces always using unlocked DX surfaces
#else  // !USE_SDL
	v5 = nox_client_winVerGetMajor_48C870(0); // Check Windows version
#endif // USE_SDL
#endif // __EMSCRIPTEN__
	nox_video_windowsPlatformVersion = v5;

	v6 = v5 == 5;
	if (v6) // if Windows NT platform
	{
		v7 = nox_video_renderTargetFlags | 0x20;
		nox_video_renderTargetFlags |= 0x120u;
	}
	v8 = w & 0xFFFFFFE0;
	if (!(v7 & 4)) {
		if (!nox_video_resetRenderer_48A040(v8, h, depth)) {
			return 0;
		}
#ifndef NOX_CGO
		cpuid_5d4594_3801804 = nox_xxx_testCPUID2_444D90();
#endif // NOX_CGO
		return 1;
	}
	v9 = (v7 & 0x17) - 20;
	*getMemU32Ptr(0x973F18, 2368) = 0;
	nox_backbuffer_width = w & 0xFFFFFFE0;
	nox_backbuffer_height = h;
	nox_backbuffer_pitchDiff = 0;
	dword_973C64 = 0;
	if (!v9) {
		nox_video_pixmode_3799624 = 0;
		nox_backbuffer_pitch_3801808 = w & 0xFFFFFFE0;
		nox_video_modeXxx_3801780 = 0;
		*getMemU32Ptr(0x973F18, 2348) = v8 >> 2;
		nox_backbuffer_width32 = v8 >> 5;
#ifndef NOX_CGO
		cpuid_5d4594_3801804 = nox_xxx_testCPUID2_444D90();
#endif // NOX_CGO
		return 1;
	}
	v10 = v9 - 1;
	if (v10) {
		if (v10 != 1) {
			return 0;
		}
		nox_video_pixmode_3799624 = 2;
	} else {
		nox_video_pixmode_3799624 = 1;
	}
	nox_video_modeXxx_3801780 = 1;
	nox_backbuffer_pitch_3801808 = 2 * v8;
	*getMemU32Ptr(0x973F18, 2348) = v8 >> 1;
	nox_backbuffer_width32 = v8 >> 4;
#ifndef NOX_CGO
	cpuid_5d4594_3801804 = nox_xxx_testCPUID2_444D90();
#endif // NOX_CGO
	return 1;
}

int4 sdl_get_display_dim() {
	int display_id;
	int4 result;
	SDL_Rect bounds = {0};

	result.field_0 = -1;
	result.field_4 = -1;
	result.field_8 = 0;
	result.field_C = 0;

	display_id = SDL_GetWindowDisplayIndex(nox_video_getWindow_401FD0());

	if (display_id >= 0 && SDL_GetDisplayBounds(display_id, &bounds) == 0) {
		result.field_0 = bounds.w;
		result.field_4 = bounds.h;
		result.field_8 = bounds.x;
		result.field_C = bounds.y;
	}

	return result;
}

void input_set_win_size(int w, int h);
void sdl_set_window_rect(int2 size, int2 position) {
	input_set_win_size(size.field_0, size.field_4);
	SDL_SetWindowSize(nox_video_getWindow_401FD0(), size.field_0, size.field_4);
	SDL_SetWindowPosition(nox_video_getWindow_401FD0(), position.field_0, position.field_4);
}

extern int nox_win_width_game;
extern int nox_win_height_game;
void change_windowed_fullscreen() {
	int windowSizeW = nox_win_width_game;
	int windowSizeH = nox_win_height_game;
	int2 windowedSize;
	int2 fullscreenSize;
	int4 displaySize = sdl_get_display_dim();
	int centeredPositionX = displaySize.field_8 + (displaySize.field_0 - windowSizeW) / 2;
	int centeredPositionY = displaySize.field_C + (displaySize.field_4 - windowSizeH) / 2;
	int2 windowedPosition;
	int2 fullscreenPosition;
	int mode = nox_video_getFullScreen();

	// Init all sizes

	// Windowed
	windowedSize.field_0 = windowSizeW;
	windowedSize.field_4 = windowSizeH;
	windowedPosition.field_0 = centeredPositionX;
	windowedPosition.field_4 = centeredPositionY;

	// Fullscreen
	fullscreenSize.field_0 = displaySize.field_0;
	fullscreenSize.field_4 = displaySize.field_4;
	fullscreenPosition.field_0 = displaySize.field_8;
	fullscreenPosition.field_4 = displaySize.field_C;

	switch (mode) {
	case -1:
	case 1:
		// Normal fullscreen
		SDL_SetWindowResizable(nox_video_getWindow_401FD0(), SDL_FALSE);
		SDL_SetWindowBordered(nox_video_getWindow_401FD0(), SDL_FALSE);
		sdl_set_window_rect(fullscreenSize, fullscreenPosition);
		SDL_SetWindowFullscreen(nox_video_getWindow_401FD0(), SDL_WINDOW_FULLSCREEN_DESKTOP);
		break;
	case -2:
	case 2:
		// Borderless fullscreen
		SDL_SetWindowFullscreen(nox_video_getWindow_401FD0(), 0);
		SDL_SetWindowResizable(nox_video_getWindow_401FD0(), SDL_FALSE);
		SDL_SetWindowBordered(nox_video_getWindow_401FD0(), SDL_TRUE);
		sdl_set_window_rect(fullscreenSize, fullscreenPosition);
		break;
	default:
		// Windowed
		SDL_SetWindowFullscreen(nox_video_getWindow_401FD0(), 0);
		SDL_SetWindowResizable(nox_video_getWindow_401FD0(), SDL_TRUE);
		SDL_SetWindowBordered(nox_video_getWindow_401FD0(), SDL_TRUE);
		sdl_set_window_rect(windowedSize, windowedPosition);
		break;
	}
}

//----- (0048A190) --------------------------------------------------------
void nox_video_setBackBufferPtrs_48A190() {
	dword_6F7B9C = 1;
	nox_backbuffer1_pix = g_backbuffer1->pixels;
	nox_backbuffer_pix = nox_backbuffer1_pix;
}

void nox_video_lockSurface_48A670(SDL_Surface* a1) { SDL_LockSurface(a1); }

void nox_video_unlockSurface_48A6B0(SDL_Surface* a1) { SDL_UnlockSurface(a1); }

//----- (0048A9C0) --------------------------------------------------------
void nox_video_minimizeOrMaximize_48A9C0(int a1) {
	if (dword_6F7BB0) {
		nox_mutex_lock(getMemAt(0x973F18, 168));
		if (!dword_974854) {
			if (nox_video_renderTargetFlags & 0x10) {
				dword_974854 = 1;
				printf("Ungrab\n");
				SDL_SetWindowGrab(nox_video_getWindow_401FD0(), SDL_FALSE);
				nox_mutex_unlock(getMemAt(0x973F18, 168));
				return;
			}
			if (a1) {
				dword_974854 = 1;
				dword_973C70 = 1;
				printf("Minimize\n");
				SDL_MinimizeWindow(nox_video_getWindow_401FD0());
			}
		}
		nox_mutex_unlock(getMemAt(0x973F18, 168));
	}
}

void sub_48B1D0_free_surface(SDL_Surface** a1) {
	if (*a1) {
		SDL_FreeSurface(*a1);
		*a1 = NULL;
	}
}

//----- (0048A220) --------------------------------------------------------
void nox_xxx_directDrawBlitMB_48A220() {}

//----- (0048A7F0) --------------------------------------------------------
void sub_48A7F0() {
	// SDL_SetRenderDrawColor(g_ddraw, 0, 0, 0, SDL_ALPHA_OPAQUE);
	// SDL_RenderClear(g_ddraw);
	// SDL_RenderPresent(g_ddraw);
}

//----- (0048A820) --------------------------------------------------------
void sub_48A820(unsigned int uFlags) {
	// uint32_t width = nox_backbuffer_width;
	// uint32_t height = nox_backbuffer_height;

	// SDL_SetWindowSize(nox_video_getWindow_401FD0(), width, height);
	// SDL_SetWindowGrab(nox_video_getWindow_401FD0(), SDL_TRUE);
}

//----- (0048AA40) --------------------------------------------------------
void sub_48AA40() {
	// FIXME
}

//----- (0048B1F0) --------------------------------------------------------
int nox_video_initCursorDrawVars_48B1F0() {
	if (nox_video_renderTargetFlags & 0x100) {
		nox_video_cursorDrawIsThreaded = 0;
		return 1;
	}
	nox_video_cursorDrawIsThreaded = 1;
	if (nox_video_renderTargetFlags & 4) {
		return 1;
	}
	*getMemU32Ptr(0x5D4594, 1193640) = 0;
	*getMemU32Ptr(0x5D4594, 1193628) = 0;
	dword_5d4594_1193648 = 0;
	dword_5d4594_1193524 = 0;
	*getMemU32Ptr(0x5D4594, 1193580) = 0;
	*getMemU32Ptr(0x5D4594, 1193636) = 0;
	*getMemU32Ptr(0x5D4594, 1193600) = 0;
	*getMemU32Ptr(0x5D4594, 1193620) = 0;
	SetRect((LPRECT)getMemAt(0x5D4594, 1193532), 0, 0, 0, 0);
	SetRect((LPRECT)getMemAt(0x5D4594, 1193548), 0, 0, 0, 0);
	SetRect((LPRECT)getMemAt(0x5D4594, 1193604), 0, 0, 0, 0);
	dword_5d4594_1193624 = 0;
	dword_5d4594_3798728 = 0;
	dword_5d4594_1193664 = 0;
	dword_5d4594_1193668 = 0;
	dword_5d4594_1193672 = 0;
	nox_video_pauseThreadedDrawCursor = 0;
	nox_video_allowCursorDrawThread = 0;
	sub_48C110();
	if (nox_video_modeXxx_3801780) {
		if (nox_video_modeXxx_3801780 == 1) {
			dword_6F7C10 = sub_48C200;
			dword_6F7C40 = sub_48C480;
			dword_6F7C34 = sub_48C4D0;
		}
	} else {
		dword_6F7C10 = sub_48C320;
		dword_6F7C40 = sub_48C420;
		dword_6F7C34 = sub_48C420;
	}
	int result = nox_video_createCursorSurface_48BF70();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return 0;
	}
	result = sub_48C060();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return 0;
	}
	result = nox_xxx_makeFillerColor_48BDE0();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return 0;
	}
	result = nox_video_createCursorDrawThread_48BE70();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return 0;
	}
	nox_video_drawCursorThreadOk = 1;
	return 1;
}

int sdl_drawCursorThreaded(int a1) {
	RECT* r1 = (RECT*)getMemAt(0x5D4594, 1193532);
	RECT* r2 = (RECT*)getMemAt(0x5D4594, 1193548);
	RECT* r3 = (RECT*)getMemAt(0x5D4594, 1193604);
	RECT v4;
	SDL_Rect src, dst;

	if (a1 && (dword_5d4594_1193668 || dword_5d4594_1193664) && !IsRectEmpty(r1)) {
		// FIXME frontbuffer?
		rect_to_sdl(r2, &src);
		rect_to_sdl(r1, &dst);
		// SDL_BlitScaled(g_cursor_surf_6F7C48, &src, g_backbuffer1, &dst);
	}

	r1->left = dword_5d4594_1193648 - *getMemU32Ptr(0x5D4594, 1193580);
	r1->right = r1->left + *getMemU32Ptr(0x5D4594, 1193600);
	r1->top = dword_5d4594_1193524 - *getMemU32Ptr(0x5D4594, 1193636);
	r1->bottom = r1->top + *getMemU32Ptr(0x5D4594, 1193620);

	if ((!a1 || dword_5d4594_1193668 || dword_5d4594_1193664) &&
		nox_xxx_utilRect_49F930((int4*)&v4, r1, (int4*)(&obj_5D4594_3800716.field_9))) {
		r2->left = 0;
		r2->top = 0;
		r2->right = v4.right - v4.left;
		r2->bottom = v4.bottom - v4.top;

		// FIXME frontbuffer?
		rect_to_sdl(&v4, &src);
		rect_to_sdl(r2, &dst);
		// if (SDL_BlitScaled(g_backbuffer1, &src, g_cursor_surf_6F7C48, &dst))
		//    return 0;
	}

	if (nox_xxx_utilRect_49F930((int4*)&v4, r1, (int4*)(&obj_5D4594_3800716.field_9))) {
		r3->left = v4.left - r1->left;
		r3->top = v4.top - r1->top;
		r3->right = v4.right - r1->left;
		r3->bottom = v4.bottom - r1->top;

		// FIXME frontbuffer?
		rect_to_sdl(r3, &src);
		rect_to_sdl(&v4, &dst);

		if (SDL_BlitScaled(g_cursor_surf, &src, g_backbuffer1, &dst)) {
			return 0;
		}

		*r1 = v4;
	}

	dword_5d4594_1193664 = 0;
	dword_5d4594_1193668 = 0;
	return 1;
}
#endif // NOX_CGO

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
#ifndef NOX_CGO
		LODWORD(v4) = cpuid_5d4594_3801804;
		if (cpuid_5d4594_3801804) {
			v6 = ((unsigned char)a2 | (((unsigned char)a2 | ((unsigned long long)(unsigned char)a2 << 16)) << 16))
				 << 16;
			*(uint32_t*)v5 = (unsigned char)a2 | (unsigned int)v6;
			*(uint32_t*)(v5 + 4) = HIDWORD(v6);
			v7 = ((unsigned char)a3 | (((unsigned char)a3 | ((unsigned long long)(unsigned char)a3 << 16)) << 16))
				 << 16;
			*(uint32_t*)(v5 + 8) = (unsigned char)a3 | (unsigned int)v7;
			*(uint32_t*)(v5 + 12) = HIDWORD(v7);
			v4 = ((unsigned char)a4 | (((unsigned char)a4 | ((unsigned long long)(unsigned char)a4 << 16)) << 16))
				 << 16;
			LODWORD(v4) = (unsigned char)a4 | (unsigned int)v4;
			*(uint64_t*)(v5 + 16) = v4;
		}
#endif // NOX_CGO
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

//----- (00444F90) --------------------------------------------------------
HDC sub_444F90() {
	abort();
	return 0;
}

//----- (00444FC0) --------------------------------------------------------
void sub_444FC0(HDC a1) { abort(); }

//----- (004353C0) --------------------------------------------------------
void sub_4353C0() {
	// FIXME 8-bit support
}

//----- (004353F0) --------------------------------------------------------
void sub_4353F0() {
	// FIXME 8-bit support
}

//----- (004354F0) --------------------------------------------------------
void sub_4354F0() {
	// FIXME 8-bit support
}

//----- (00435550) --------------------------------------------------------
void sub_435550() {
	// FIXME 8-bit support
}

//----- (00433C20) --------------------------------------------------------
#ifndef NOX_CGO
void nox_draw_freeColorTables_433C20_2() {
	if (nox_draw_colors_r_3804672) {
		free(*(void**)&nox_draw_colors_r_3804672);
		nox_draw_colors_r_3804672 = 0;
	}
	if (nox_draw_colors_g_3804656) {
		free(*(void**)&nox_draw_colors_g_3804656);
		nox_draw_colors_g_3804656 = 0;
	}
	if (nox_draw_colors_b_3804664) {
		free(*(void**)&nox_draw_colors_b_3804664);
		nox_draw_colors_b_3804664 = 0;
	}
}
#else  // NOX_CGO
void nox_draw_freeColorTables_433C20_2();
#endif // NOX_CGO

#ifndef NOX_CGO
void nox_draw_freeColorTables_433C20() {
	if (dword_5d4594_810640) {
		free(dword_5d4594_810640);
		dword_5d4594_810640 = 0;
	}
	if (nox_draw_colorTablesRev_3804668) {
		free(nox_draw_colorTablesRev_3804668);
		nox_draw_colorTablesRev_3804668 = 0;
	}
	nox_draw_freeColorTables_433C20_2();
	sub_435550();
	*getMemU32Ptr(0x973F18, 5232) = 0;
}

//----- (00444930) --------------------------------------------------------
int nox_xxx_GfxInit_444930(int w, int h, int depth, int flags) {
	dword_5d4594_823776 = 0;
	nox_draw_curDrawData_3799572 = &obj_5D4594_3799660;
	int result = nox_client_drawInitAll_4449D0(w, h, depth, flags);
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return 0;
	}
	nox_draw_curDrawData_3799572 = &obj_5D4594_3800716;
	memcpy(&obj_5D4594_3800716, &obj_5D4594_3799660, sizeof(nox_render_data_t));
	if (nox_video_renderTargetFlags & 0x200) {
		SDL_MinimizeWindow(nox_video_getWindow_401FD0());
	}
	dword_5d4594_823776 = 1;
	++dword_5d4594_823772;
	return 1;
}

//----- (00444C50) --------------------------------------------------------
void sub_444C50() {
	if (dword_5d4594_823776) {
		nox_video_stopCursorDrawThread_48B350();
		nullsub_6();
		nox_free_pixbuffers_486110();
		nullsub_19();
		nullsub_3();
		nullsub_14();
		nox_draw_freeColorTables_433C20();
		nullsub_15();
		nox_video_free_renderer_48A120();
		nox_client_initFade_44D9D0();
		sub_4B0660();
		nullsub_13();
		nullsub_11();
		nullsub_18();
		sub_4AF950();
		nullsub_17();
		sub_4AE540();
		nullsub_12();
		nox_xxx_FontDestroy_43F2E0();
		nullsub_16();
		sub_49F4D0();
		dword_5d4594_823776 = 0;
		if (*getMemU32Ptr(0x5D4594, 823780)) {
			nox_mutex_free(getMemAt(0x973F18, 168));
			*getMemU32Ptr(0x5D4594, 823780) = 0;
		}
	}
}

//----- (0048C110) --------------------------------------------------------
void sub_48C110() {
	*getMemU32Ptr(0x5D4594, 1193684) = nox_backbuffer_width;
	*getMemU32Ptr(0x5D4594, 1193688) = nox_backbuffer_height;
}

//----- (004AD100) --------------------------------------------------------
int nox_video_setBackBufferCopyFunc_4AD100() {
	if (nox_video_renderTargetFlags & 0x40) {
		g_copy_backbuffer_ptr = nox_video_copyBackBuffer2_4AD180;
	} else {
		nox_video_setBackBufferCopyFunc2_4AD150();
	}
	*getMemU32Ptr(0x973A20, 496) = 0;
	return 1;
}

//----- (004AD150) --------------------------------------------------------
void nox_video_setBackBufferCopyFunc2_4AD150() {
	if (nox_video_renderTargetFlags & 0x20) {
		g_copy_backbuffer_ptr = nox_video_copyBackBuffer_4AD2A0;
	} else {
		g_copy_backbuffer_ptr = nox_video_copyBackBuffer3_4AD1E0;
	}
}

void nox_video_callCopyBackBuffer_4AD170(void) { g_copy_backbuffer_ptr(); }

//----- (004AD180) --------------------------------------------------------
void nox_video_copyBackBuffer2_4AD180() { abort(); }

//----- (004AD1E0) --------------------------------------------------------
void nox_video_copyBackBuffer3_4AD1E0() {
	if (dword_973C70) {
		return;
	}

	if (SDL_LockSurface(g_backbuffer1)) {
		return;
	}

	uint16_t* v1 = g_backbuffer1->pixels;
	uint16_t** v3 = nox_pixbuffer_rows_3798784;
	for (int v2 = nox_backbuffer_height; v2 > 0; v2--) {
		uint16_t* v4 = *v3;
		for (int v5 = nox_backbuffer_width32; v5 > 0; v5--) {
			for (int i = 0; i < 16; i++) {
				*v1 = *v4 << 1;
				v1++;
				v4++;
			}
		}
		// memcpy(v1, v4, v5 * 32);
		// v1 = (uint32_t *)((char *)v1 + v5 * 32);
		v1 = (uint16_t*)((char*)v1 + nox_backbuffer_pitchDiff);
		++v3;
	}
	SDL_UnlockSurface(g_backbuffer1);
	++*getMemU32Ptr(0x973A20, 496);
}

//----- (004AD2A0) --------------------------------------------------------
void nox_video_copyBackBuffer_4AD2A0() {
	// FIXME unlocked surfaces
	if (dword_973C70) {
		return;
	}
	uint32_t* dst = nox_backbuffer_pix;
	uint32_t** src = nox_pixbuffer_rows_3798784;
	for (int y = 0; y < nox_backbuffer_height; y++) {
		uint32_t* row = src[y];
		for (int x = 0; x < nox_backbuffer_width32; x++) {
			memcpy(dst, row, 32);
			row += 8;
			dst += 8;
		}
		dst = (uint32_t*)((char*)dst + nox_backbuffer_pitchDiff);
	}
	++*getMemU32Ptr(0x973A20, 496);
}

//----- (00486090) --------------------------------------------------------
int nox_video_initPixbuffer_486090() {
	int result; // eax

	result = nox_video_initPixbufferData_4861D0();
	if (result) {
		result = nox_video_initPixbufferRows_486230();
		if (result) {
			if (!(nox_video_renderTargetFlags & 0x40) ||
				(result = sub_48A5D0(), (g_surface_973C88 = result) != 0) &&
					(result = sub_48A5D0(), (g_surface_973C60 = result) != 0)) {
				result = 1;
			}
		}
	}
	return result;
}

//----- (0048A5E0) --------------------------------------------------------
int sub_48A5E0() {
	int result; // eax

	result = g_surface_973C88;
	g_surface_973C88 = g_surface_973C60;
	g_surface_973C60 = result;
	return result;
}

//----- (0048BF70) --------------------------------------------------------
int nox_video_createCursorSurface_48BF70() {
	g_cursor_surf = nox_video_createSurface_48A600(128, 128, DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY);
	if (!g_cursor_surf) {
		return 0;
	}
	if (nox_video_getSurfaceData_48A720(g_cursor_surf, &g_cursor_surf_pitch, &g_cursor_surf_pixels)) {
		return 0;
	}
	if (!g_cursor_surf_pixels) {
		return 0;
	}
	int4 rect;
	rect.field_0 = 0;
	rect.field_4 = 0;
	rect.field_8 = 128;
	rect.field_C = 128;
	sub_48C170(&rect, &rect);
	g_cursor_surf_6F7C48 = nox_video_createSurface_48A600(rect.field_8, rect.field_C, DDSCAPS_VIDEOMEMORY);
	if (!g_cursor_surf_6F7C48) {
		return 0;
	}
	if (nox_video_getSurfaceData_48A720(g_cursor_surf_6F7C48, 0, &g_cursor_surf_pixels_6F7C78)) {
		return 0;
	}
	return g_cursor_surf_pixels_6F7C78 != 0;
}

//----- (0048B3F0) --------------------------------------------------------
int sub_48B3F0(void* a1p, int a2, int a3) {
	int a1 = a1p;
	int i; // esi

	if (nox_video_cursorDrawIsThreaded) {
		nox_mutex_lock(getMemAt(0x973F18, 168));
		*getMemU32Ptr(0x5D4594, 1193640) = dword_5d4594_1193648;
		*getMemU32Ptr(0x5D4594, 1193628) = dword_5d4594_1193524;
		dword_5d4594_1193648 = a2;
		dword_5d4594_1193524 = a3;
		if (a1 && a1 != dword_5d4594_1193624) {
			dword_5d4594_1193624 = a1;
			nox_video_lockSurface_48A670(g_cursor_surf);
			for (i = 0; i < 512; i += 4) {
				sub_49D1C0(*(uint32_t*)(i + (uint32_t)dword_5d4594_1193704), *getMemIntPtr(0x5D4594, 1193592), 128);
			}
			a3 = 0;
			a2 = 0;
			if (sub_48C0C0(a1, &a2, &a3)) {
				dword_6F7C10(a1, a2, a3);
				*getMemU32Ptr(0x5D4594, 1193580) = a2;
				*getMemU32Ptr(0x5D4594, 1193600) = dword_5d4594_1193568;
				*getMemU32Ptr(0x5D4594, 1193620) = dword_5d4594_1193576;
				*getMemU32Ptr(0x5D4594, 1193636) = a3;
				*getMemU32Ptr(0x5D4594, 1193604) = 0;
				*getMemU32Ptr(0x5D4594, 1193608) = 0;
				*getMemU32Ptr(0x5D4594, 1193612) = dword_5d4594_1193568;
				*getMemU32Ptr(0x5D4594, 1193616) = dword_5d4594_1193576;
				dword_5d4594_1193664 = 1;
			}
			nox_video_unlockSurface_48A6B0(g_cursor_surf);
		}
		if (dword_5d4594_1193648 != *getMemU32Ptr(0x5D4594, 1193640) ||
			dword_5d4594_1193524 != *getMemU32Ptr(0x5D4594, 1193628)) {
			dword_5d4594_1193668 = 1;
		}
		nox_mutex_unlock(getMemAt(0x973F18, 168));
	} else if (dword_5d4594_1193672 && a1) {
		nox_client_drawImageAt_47D2C0(a1, a2, a3);
		return 1;
	}
	return 1;
}

//----- (0048BDE0) --------------------------------------------------------
bool nox_xxx_makeFillerColor_48BDE0() {
	int v0; // eax

	v0 = nox_color_rgb_4344A0(255, 0, 255);
	*getMemU32Ptr(0x5D4594, 1193592) = v0;
	if (g_cursor_surf) {
		// FIXME use SDL_MapRGB instead?
		v0 = nox_video_pixmode_3799624 ? (unsigned short)v0 : (unsigned char)v0;
		SDL_SetColorKey(g_cursor_surf, SDL_TRUE, v0);
	}
	return 1;
}

//----- (0048C060) --------------------------------------------------------
int sub_48C060() {
	if (g_cursor_surf && g_cursor_surf_pixels) {
		dword_5d4594_1193704 = calloc(1, 512);
		if (!dword_5d4594_1193704) {
			return 0;
		}
		int v1 = g_cursor_surf_pixels;

		for (int v2 = 0; v2 < 512; v2 += 4) {
			*(uint32_t*)((uint32_t)dword_5d4594_1193704 + v2) = v1;
			v1 += g_cursor_surf_pitch;
		}
	}
	return 1;
}

//----- (0048B350) --------------------------------------------------------
void nox_video_stopCursorDrawThread_48B350() {
	nox_video_drawCursorThreadOk = 0;
	nox_video_allowCursorDrawThread = 0;
	if (nox_video_cursorDrawThreadHandle) {
		nox_video_pauseThreadedDrawCursor = 1;
		WaitForSingleObject(nox_video_cursorDrawThreadHandle, 0x108u);
		CloseHandle(nox_video_cursorDrawThreadHandle);
		nox_video_cursorDrawThreadHandle = 0;
	}

	sub_48B1D0_free_surface(&g_cursor_surf);
	sub_48B1D0_free_surface(&g_cursor_surf_6F7C48);

	if (dword_5d4594_1193704) {
		free(*(void**)&dword_5d4594_1193704);
		dword_5d4594_1193704 = 0;
	}
	dword_5d4594_1193624 = 0;
}

//----- (004338D0) --------------------------------------------------------
int sub_4338D0() {
	int result;       // eax
	pixel888 v2[256]; // [esp+Ch] [ebp-300h]

	switch (nox_video_pixmode_3799624) {
	case 0:
#ifndef NOX_CGO
		nox_color_rgb_func = nox_color_func_435180;
#else  // NOX_CGO
		nox_color_rgb_func_set(0);
#endif // NOX_CGO
		dword_975240 = sub_435240;
		dword_975380 = sub_434E80;
		memcpy(byte_5D4594_3804364, byte_581450_9176, sizeof(byte_581450_9176));
		break;
	case 1:
#ifndef NOX_CGO
		nox_color_rgb_func = nox_color_rgba5551ext_4351C0;
#else  // NOX_CGO
		nox_color_rgb_func_set(1);
#endif // NOX_CGO
		dword_975240 = sub_435280;
		dword_975380 = sub_434E80;
		memcpy(byte_5D4594_3804364, byte_581450_9176, sizeof(byte_581450_9176));
		break;
	case 2:
#ifndef NOX_CGO
		nox_color_rgb_func = nox_color_rgb565ext_435200;
#else  // NOX_CGO
		nox_color_rgb_func_set(2);
#endif // NOX_CGO
		dword_975240 = sub_435280;
		dword_975380 = sub_434EC0;
		memcpy(byte_5D4594_3804364, byte_581450_9336, sizeof(byte_581450_9336));
		break;
	}
	nox_draw_curDrawData_3799572->field_13 = 0;
	nox_draw_curDrawData_3799572->field_14 = 0;
	nox_draw_curDrawData_3799572->field_17 = 0;
	nox_draw_curDrawData_3799572->field_24 = 0;
	nox_draw_curDrawData_3799572->field_25 = 0;
	nox_draw_curDrawData_3799572->field_26 = 0;
	nox_draw_curDrawData_3799572->field_44 = 0;
	nox_draw_curDrawData_3799572->field_45 = 0;
	nox_draw_curDrawData_3799572->field_46 = 0;
	nox_draw_curDrawData_3799572->field_54 = 0;
	nox_draw_curDrawData_3799572->field_55 = 0;
	nox_draw_curDrawData_3799572->field_56 = 0;
	nox_draw_curDrawData_3799572->field_58 = 0;
	nox_draw_curDrawData_3799572->field_59 = 0;
	nox_draw_curDrawData_3799572->field_60 = 0;
	nox_draw_curDrawData_3799572->field_61 = 0;
	nox_draw_curDrawData_3799572->field_259 = 255;
	nox_draw_curDrawData_3799572->field_260 = 16711935;
	nox_draw_curDrawData_3799572->field_261 = 16711935;
	nox_draw_curDrawData_3799572->field_262 = 0;
	sub_434990(25, 25, 25);
	result = nox_draw_initColorTables_434CC0();
	if (result) {
		result = nox_draw_initColorTablesRev_434DA0();
		if (result) {
			if (!dword_5d4594_823772) {
				sub_4353C0();
			}
			*getMemU32Ptr(0x5D4594, 809596) = 0;
			dword_5d4594_808568 = 0;
			dword_5d4594_810628 = 0;
			if (dword_5d4594_823772) {
				sub_435150(v2, (char*)getMemAt(0x973F18, 3880));
				sub_4347F0((char*)v2, 256);
			} else {
				sub_4347F0((char*)getMemAt(0x581450, 8404), 256);
			}
			result = sub_434FB0();
			if (result) {
				sub_4340A0(0, 0, 0, 255);
				sub_4340A0(1, 0, 255, 0);
				sub_4340A0(2, 0, 255, 255);
				sub_4340A0(3, 255, 0, 0);
				sub_4340A0(4, 255, 0, 255);
				sub_4340A0(5, 255, 255, 0);
				sub_4340A0(6, 255, 255, 255);
				sub_4340A0(7, 0, 0, 0);
				sub_4340A0(8, 0, 0, 128);
				sub_4340A0(9, 0, 128, 0);
				sub_4340A0(10, 0, 128, 128);
				sub_4340A0(11, 128, 0, 0);
				sub_4340A0(12, 128, 0, 128);
				sub_4340A0(13, 128, 128, 0);
				sub_4340A0(14, 128, 128, 128);
				sub_4340A0(15, 0, 0, 0);
				// TODO gamma control
				dword_5d4594_808564 = 0;
				sub_4348C0();
				sub_4352E0();
				*getMemU32Ptr(0x973F18, 5232) = 0;
				result = 1;
			}
		}
	}
	return result;
}
#endif // NOX_CGO

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
#ifndef NOX_CGO
	if (cpuid_5d4594_3801804) {
		v5 = a1 | (a1 << 16);
		v5 <<= 16;
		LODWORD(v5) = a1 | (unsigned int)v5;
		v5 <<= 16;
		nox_draw_curDrawData_3799572->field_18 = a1 | (unsigned int)v5;
		nox_draw_curDrawData_3799572->field_19 = HIDWORD(v5);
		v6 = (a2 | ((a2 | ((unsigned long long)a2 << 16)) << 16)) << 16;
		nox_draw_curDrawData_3799572->field_20 = a2 | (unsigned int)v6;
		nox_draw_curDrawData_3799572->field_21 = HIDWORD(v6);
		v7 = (a3 | ((a3 | ((unsigned long long)a3 << 16)) << 16)) << 16;
		nox_draw_curDrawData_3799572->field_22 = a3 | (unsigned int)v7;
		nox_draw_curDrawData_3799572->field_23 = HIDWORD(v7);
	}
#endif // NOX_CGO
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

//----- (00433ED0) --------------------------------------------------------
void sub_433ED0(int a1) {
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	sub_433E80(v3, v2, a1);
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
#ifndef NOX_CGO
			result = cpuid_5d4594_3801804;
			if (cpuid_5d4594_3801804) {
				v6 = (unsigned long long)((unsigned char)a1 | ((unsigned char)a1 << 16)) << 16;
				LODWORD(v6) = (unsigned char)a1 | (unsigned int)v6;
				*(uint64_t*)v4 = (unsigned char)a1 | (v6 << 16);
				v7 = (unsigned long long)((unsigned char)a2 | ((unsigned char)a2 << 16)) << 16;
				LODWORD(v7) = (unsigned char)a2 | (unsigned int)v7;
				*(uint64_t*)(v4 + 8) = (unsigned char)a2 | (v7 << 16);
				v8 = (unsigned char)v10;
				v9 = (unsigned long long)((unsigned char)v10 | ((unsigned char)v10 << 16)) << 16;
				LODWORD(v9) = (unsigned char)v10 | (unsigned int)v9;
				v9 <<= 16;
				result = (unsigned char)v10 | (unsigned int)v9;
				*(uint32_t*)(v4 + 16) = result;
				*(uint32_t*)(v4 + 20) = HIDWORD(v8) | HIDWORD(v9);
			}
#endif // NOX_CGO
		}
	}
	return result;
}

//----- (00434320) --------------------------------------------------------
void nox_set_color_rgb_434320(int r, int g, int b) {
	*(int*)(&nox_draw_curDrawData_3799572->field_58) = nox_color_rgb_4344A0(r, g, b);
}

//----- (004343B0) --------------------------------------------------------
void nox_set_color_rgb_4343B0(int r, int g, int b) {
	*(int*)(&nox_draw_curDrawData_3799572->field_59) = nox_color_rgb_4344A0(r, g, b);
}

//----- (00434400) --------------------------------------------------------
void nox_set_color_rgb_434400(int r, int g, int b) {
	*(int*)(&nox_draw_curDrawData_3799572->field_60) = nox_color_rgb_4344A0(r, g, b);
}

//----- (00434430) --------------------------------------------------------
void nox_set_color_rgb_434430(int r, int g, int b) {
	*(int*)(&nox_draw_curDrawData_3799572->field_61) = nox_color_rgb_4344A0(r, g, b);
}

//----- (00434480) --------------------------------------------------------
void sub_434480(int a1, int* a2, int* a3, int* a4) { dword_975240(a1, a2, a3, a4); }

//----- (004344A0) --------------------------------------------------------
#ifndef NOX_CGO
uint32_t nox_color_rgb_4344A0(int r, int g, int b) {
	r = r & 0xFF;
	g = g & 0xFF;
	b = b & 0xFF;
	int color = 0;
	if (nox_color_rgb_func) {
		nox_color_rgb_func(r, g, b, &color);
	}
	return color;
}
#endif // NOX_CGO

//----- (00434AA0) --------------------------------------------------------
int sub_434AA0(int a1, int a2, int a3) { return dword_975380(a1, a2, a3); }

//----- (00434AC0) --------------------------------------------------------
int sub_434AC0(int a1) {
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	return dword_975380(v3, v2, a1);
}

#ifndef NOX_CGO
//----- (00434B00) --------------------------------------------------------
int nox_video_getGammaSetting_434B00() {
	int result; // eax

	result = nox_video_gammaValue;
	if (nox_video_gammaValue >= 1) {
		if (nox_video_gammaValue > 10) {
			result = 10;
			nox_video_gammaValue = 10;
		}
	} else {
		result = 1;
		nox_video_gammaValue = 1;
	}
	return result;
}

void updateGamma(int value) {
	float modificator;

	modificator = 0;

	if (value > 0) {
		modificator = 0.1;
	}
	if (value < 0) {
		modificator = -0.1;
	}

	if (draw_gamma <= 0.1 && modificator < 0) {
		modificator = 0;
	} else if (draw_gamma >= 3 && modificator > 0) {
		modificator = 0;
	}

	draw_gamma += modificator;
}

float nox_video_getGamma() { return draw_gamma; }

void nox_video_setGamma(float v) { draw_gamma = v; }

//----- (00434B30) --------------------------------------------------------
int nox_video_setGammaSetting_434B30(int a1) {
	int result; // eax

	result = a1;
	if (a1 >= 1) {
		if (a1 > 10) {
			result = 10;
		}
		nox_video_gammaValue = result;
	} else {
		result = 1;
		nox_video_gammaValue = 1;
	}

	return result;
}
#endif // NOX_CGO

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

#ifndef NOX_CGO
//----- (00434CC0) --------------------------------------------------------
int nox_draw_initColorTables_434CC0() {
	int v0 = 0;   // edi
	void* result; // eax
	int i;        // esi

	if (!nox_video_modeXxx_3801780) {
		v0 = nox_color_rgb_func;
		nox_color_rgb_func = nox_color_rgba5551ext_4351C0;
	}
	result = calloc(257, 2);
	nox_draw_colors_r_3804672 = result;
	if (!result) {
		return 0;
	}
	result = calloc(257, 2);
	nox_draw_colors_g_3804656 = result;
	if (!result) {
		return 0;
	}
	result = calloc(257, 2);
	nox_draw_colors_b_3804664 = result;
	if (!result) {
		return 0;
	}
	for (i = 0; i < 256; ++i) {
		*(uint16_t*)(nox_draw_colors_r_3804672 + 2 * i) = nox_color_rgb_4344A0(i, 0, 0);
		*(uint16_t*)(nox_draw_colors_g_3804656 + 2 * i) = nox_color_rgb_4344A0(0, i, 0);
		*(uint16_t*)(nox_draw_colors_b_3804664 + 2 * i) = nox_color_rgb_4344A0(0, 0, i);
	}
	if (!nox_video_modeXxx_3801780) {
		nox_color_rgb_func = v0;
	}
	return 1;
}
// 434CDD: variable 'v3' is possibly undefined
#endif // NOX_CGO

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

//----- (004B05D0) --------------------------------------------------------
void sub_4B05D0() {
	if (dword_5d4594_1311936) {
		sub_555500(1);
		dword_5d4594_1311936 = 0;
		*getMemU32Ptr(0x5D4594, 1311928) = 0;
		if (func_5d4594_1311924) {
			nox_client_clearScreen_440900();
			func_5d4594_1311924();
		}
	}
}

//----- (004B0640) --------------------------------------------------------
int sub_4B0640(int (*a1)(void)) {
	int result; // eax

	result = a1;
	func_5d4594_1311924 = a1;
	return result;
}

#ifndef NOX_CGO
//----- (0048B5D0) --------------------------------------------------------
int nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(int a1, int a2) {
	if (!*getMemU32Ptr(0x5D4594, 1193708) && nox_video_drawCursorThreadOk && dword_5d4594_823776 &&
		nox_video_cursorDrawIsThreaded && dword_5d4594_1193672 && *getMemU32Ptr(0x5D4594, 1193108) &&
		nox_video_bag_ready) {
		*getMemU32Ptr(0x5D4594, 1193708) = 1;
		nox_mutex_lock(getMemAt(0x973F18, 168));
		// FIXME SDL will always wait for vblank?
		int res = sdl_drawCursorThreaded(a1);
		nox_mutex_unlock(getMemAt(0x973F18, 168));
		*getMemU32Ptr(0x5D4594, 1193708) = 0;
		return res;
	}
	return 0;
}
#endif // NOX_CGO

//----- (0048C200) --------------------------------------------------------
unsigned char* sub_48C200(void* a1p, int a2, int a3) {
	int a1 = a1p;
	unsigned char* result; // eax
	int v4;                // ebp
	unsigned char* v5;     // eax
	int v6;                // ecx
	int v7;                // edi
	int v8;                // edx
	int v9;                // ebx
	int v10;               // esi
	void (*v11)(void);     // edi
	int v12;               // edi
	int v13;               // ecx
	int v14;               // ebx
	int v15;               // edi
	int v16;               // esi
	int v17;               // ecx
	unsigned char* v18;    // eax
	int v19;               // edx
	int v20;               // ecx
	void (*v21)(void);     // [esp+14h] [ebp+4h]
	int v22;               // [esp+18h] [ebp+8h]
	int v23;               // [esp+1Ch] [ebp+Ch]

	result = nox_video_getImagePixdata_func(a1);
	dword_5d4594_1193516 = result;
	if (result) {
		v4 = *(uint32_t*)result;
		v5 = result + 4;
		dword_5d4594_1193516 = v5;
		v6 = *(uint32_t*)v5;
		v5 += 4;
		dword_5d4594_1193516 = v5;
		v7 = *(uint32_t*)v5;
		v5 += 4;
		dword_5d4594_1193516 = v5;
		v8 = v7 + a2;
		v9 = *(uint32_t*)v5;
		result = v5 + 5;
		v10 = v9 + a3;
		dword_5d4594_1193568 = v4;
		dword_5d4594_1193576 = v6;
		dword_5d4594_1193516 = result;
		v11 = dword_6F7C34;
		if (!nox_draw_curDrawData_3799572->field_15) {
			v11 = dword_6F7C40;
		}
		v21 = v11;
		v12 = v6;
		v13 = v6 - 1;
		if (v12) {
			v23 = 2 * v8;
			v14 = 4 * v10;
			v22 = v13 + 1;
			do {
				v14 += 4;
				v15 = v4;
				v16 = v23 + *(uint32_t*)(v14 + (uint32_t)dword_5d4594_1193704 - 4);
				for (dword_5d4594_1193584 = v23 + *(uint32_t*)(v14 + (uint32_t)dword_5d4594_1193704 - 4); v15 > 0;
					 v15 -= v19) {
					v17 = *result;
					v18 = result + 1;
					*getMemU32Ptr(0x5D4594, 1193588) = v17;
					dword_5d4594_1193516 = v18;
					v19 = *v18;
					result = v18 + 1;
					v20 = (v17 & 0xF) - 1;
					*getMemU32Ptr(0x5D4594, 1193520) = v19;
					dword_5d4594_1193516 = result;
					if (v20) {
						if (v20 == 1) {
							v21();
							result = *(unsigned char**)&dword_5d4594_1193516;
							v16 = dword_5d4594_1193584;
							v19 = *getMemU32Ptr(0x5D4594, 1193520);
						}
					} else {
						v16 += 2 * v19;
						dword_5d4594_1193584 = v16;
					}
				}
				--v22;
			} while (v22);
		}
	}
	return result;
}

//----- (0048C320) --------------------------------------------------------
unsigned char* sub_48C320(void* a1p, int a2, int a3) {
	int a1 = a1p;
	unsigned char* result; // eax
	int v4;                // edi
	unsigned char* v5;     // eax
	int v6;                // ecx
	int v7;                // esi
	int v8;                // ebx
	int v9;                // ebp
	void (*v10)(void);     // esi
	int v11;               // esi
	int v12;               // ecx
	int v13;               // ebp
	int v14;               // esi
	int v15;               // ecx
	unsigned char* v16;    // eax
	int v17;               // edx
	int v18;               // ecx
	void (*v19)(void);     // [esp+14h] [ebp+4h]
	int v20;               // [esp+18h] [ebp+8h]

	result = nox_video_getImagePixdata_func(a1);
	dword_5d4594_1193516 = result;
	if (result) {
		v4 = *(uint32_t*)result;
		v5 = result + 4;
		dword_5d4594_1193516 = v5;
		v6 = *(uint32_t*)v5;
		v5 += 4;
		dword_5d4594_1193516 = v5;
		v7 = *(uint32_t*)v5;
		v5 += 4;
		dword_5d4594_1193516 = v5;
		v8 = v7 + a2;
		v9 = *(uint32_t*)v5;
		result = v5 + 5;
		dword_5d4594_1193568 = v4;
		dword_5d4594_1193576 = v6;
		dword_5d4594_1193516 = result;
		v10 = dword_6F7C34;
		if (!nox_draw_curDrawData_3799572->field_15) {
			v10 = dword_6F7C40;
		}
		v19 = v10;
		v11 = v6;
		v12 = v6 - 1;
		if (v11) {
			v13 = 4 * (v9 + a3);
			v20 = v12 + 1;
			do {
				v13 += 4;
				v14 = v4;
				for (dword_5d4594_1193584 = v8 + *(uint32_t*)((uint32_t)dword_5d4594_1193704 + v13 - 4); v14 > 0;
					 v14 -= v17) {
					v15 = *result;
					v16 = result + 1;
					*getMemU32Ptr(0x5D4594, 1193588) = v15;
					dword_5d4594_1193516 = v16;
					v17 = *v16;
					result = v16 + 1;
					v18 = (v15 & 0xF) - 1;
					*getMemU32Ptr(0x5D4594, 1193520) = v17;
					dword_5d4594_1193516 = result;
					if (v18) {
						if (v18 == 1) {
							v19();
							result = *(unsigned char**)&dword_5d4594_1193516;
							v17 = *getMemU32Ptr(0x5D4594, 1193520);
						}
					} else {
						dword_5d4594_1193584 += v17;
					}
				}
				--v20;
			} while (v20);
		}
	}
	return result;
}

//----- (0048A290) --------------------------------------------------------
#ifndef NOX_CGO
void sub_48A290_call_present() {
	sdl_present();
	++g_present_ticks;
}

void nox_video_showMovieFrame(SDL_Surface* surf) {
	SDL_SetSurfaceBlendMode(g_backbuffer1, SDL_BLENDMODE_NONE);
	SDL_SetSurfaceBlendMode(surf, SDL_BLENDMODE_NONE);
	SDL_Rect srcRect = surf->clip_rect;
	SDL_Rect dstRect = g_backbuffer1->clip_rect;
	if (srcRect.w < dstRect.w) {
		dstRect.x = (dstRect.w - srcRect.w) / 2;
	}
	if (srcRect.h < dstRect.h) {
		dstRect.y = (dstRect.h - srcRect.h) / 2;
	}

	SDL_BlitSurface(surf, &srcRect, g_backbuffer1, &dstRect);
	sdl_present();
}
#endif // NOX_CGO
