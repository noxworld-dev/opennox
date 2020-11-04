// This must come before the SDL includes.
#ifdef _WIN32
#include <GL/glew.h>
#include <windows.h>
#else
#define GL_GLEXT_PROTOTYPES
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#include <OpenGL/glu.h>
#include <SDL2/SDL_opengl.h>
#else
#include <GL/gl.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_opengl_glext.h>
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#endif

#include "proto.h"

extern unsigned char byte_581450_9176[160];

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

void* nox_backbuffer1_pix = 0;
void* nox_backbuffer_pix = 0;

int nox_backbuffer_width = 0;
int nox_backbuffer_height = 0;
int nox_backbuffer_depth = 0;

int nox_video_renderTargetFlags = 0;
int nox_video_pauseThreadedDrawCursor = 0;
int nox_video_drawCursorThreadOk = 0;
int nox_video_allowCursorDrawThread = 0;
int nox_video_windowsPlatformVersion = 0;
int nox_video_cursorDrawIsThreaded = 0;
int nox_video_gammaValue = 0;
extern HANDLE* nox_video_cursorDrawThreadHandle;
int (*func_5d4594_1311924)(void) = 0;

#ifdef USE_SDL
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

static inline void rect_to_sdl(const RECT* r, SDL_Rect* sr) {
	sr->x = r->left;
	sr->y = r->top;
	sr->w = r->right - r->left;
	sr->h = r->bottom - r->top;
}
void sdl_present();
int sdl_drawCursorThreaded(int);
int create_surfaces(HWND a1, int width, int height);

void __cdecl sub_48B1B0(SDL_GLContext* a1);
void __cdecl sub_48B1D0_free_surface(SDL_Surface** a1);
SDL_Surface* __cdecl sub_48A600(int a1, int a2, int a3, int a4);
int __cdecl sub_48A720(SDL_Surface* a1, _DWORD* a2, _DWORD* a3, _DWORD* a4, int* a5);
void __cdecl sub_48A670(SDL_Surface* a1);
void __cdecl sub_48A6B0(SDL_Surface* a1);

SDL_Window* windowHandle_dword_973FE0;
#else
void __cdecl sub_435380(LPDIRECTDRAWGAMMACONTROL* a1);
void __cdecl sub_4353A0(LPDIRECTDRAWPALETTE* a1);
LPDIRECTDRAWSURFACE __cdecl sub_48A600(int a1, int a2, int a3, int a4);
void __cdecl sub_48A670(LPDIRECTDRAWSURFACE a1);
void __cdecl sub_48A6B0(LPDIRECTDRAWSURFACE a1);
LPVOID __cdecl sub_48A6C0(LPDIRECTDRAWSURFACE a1);
int __cdecl sub_48A720(LPDIRECTDRAWSURFACE a1, _DWORD* a2, _DWORD* a3, _DWORD* a4, int* a5);
void __cdecl sub_48A7B0(LPDIRECTDRAWSURFACE a1);
int __stdcall sub_48AE80(LPDIRECTDRAWSURFACE a1, LPDDSURFACEDESC a2, LPVOID a3);
BOOL __stdcall Callback(GUID*, LPSTR, LPSTR, LPVOID); // idb
int __cdecl sub_48B140(LPDIRECTDRAW a1, const IID* a2, int* a3);
void __cdecl sub_48B190(LPDIRECTDRAWCLIPPER* a1);
void __cdecl sub_48B1B0(LPDIRECTDRAW* a1);
void __cdecl sub_48B1D0(LPDIRECTDRAWSURFACE* a1);
int __cdecl sub_48AD40(HWND a1, int a2, int a3, int a4);
int __cdecl sub_48AED0(HWND a1, int a2, int a3);

HWND windowHandle_dword_973FE0;
#endif

int nox_backbuffer_pitch32;
int nox_backbuffer_width32;
DWORD dword_973C64;

//----- (00444AC0) --------------------------------------------------------
int __cdecl sub_444AC0(HWND wnd, int w, int h, int depth, int flags) {
	int v5;             // eax
	bool v6;            // zf
	unsigned __int8 v7; // al
	int v8;             // esi
	int v9;             // eax
	int v10;            // eax

	InitializeCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
	*getMemU32Ptr(0x5D4594, 823780) = 1;
#ifdef USE_SDL
	windowHandle_dword_973FE0 = (SDL_Window*)wnd;
#else
	windowHandle_dword_973FE0 = a1;
#endif
	nox_backbuffer_width = w;
	nox_backbuffer_height = h;
	nox_backbuffer_depth = depth;
	nox_video_renderTargetFlags = flags;
#ifndef USE_SDL
	v5 = nox_client_winVerGetMajor_48C870(0); // Check Windows version
	nox_video_windowsPlatformVersion = v5;
#else
	v5 = 5; // Fix for Linux
	nox_video_windowsPlatformVersion = v5;
#endif
	v6 = v5 == 5;
	if (v6) // if Windows NT platform
	{
		v7 = nox_video_renderTargetFlags | 0x20;
		nox_video_renderTargetFlags |= 0x120u;
	}
	v8 = w & 0xFFFFFFE0;
	if (!(v7 & 4)) {
		if (!sub_48A040(wnd, v8, h, depth))
			return 0;
		dword_5d4594_3801804 = sub_444D90();
		return 1;
	}
	v9 = (v7 & 0x17) - 20;
	*getMemU32Ptr(0x5D4594, 3801796) = 0;
	nox_backbuffer_width = w & 0xFFFFFFE0;
	nox_backbuffer_height = h;
	nox_backbuffer_pitch32 = 0;
	dword_973C64 = 0;
	if (!v9) {
		dword_5d4594_3799624 = 0;
		nox_pitch_3801808 = w & 0xFFFFFFE0;
		dword_5d4594_3801780 = 0;
		*getMemU32Ptr(0x5D4594, 3801776) = v8 >> 2;
		nox_backbuffer_width32 = v8 >> 5;
		dword_5d4594_3801804 = sub_444D90();
		return 1;
	}
	v10 = v9 - 1;
	if (v10) {
		if (v10 != 1)
			return 0;
		dword_5d4594_3799624 = 2;
	} else {
		dword_5d4594_3799624 = 1;
	}
	dword_5d4594_3801780 = 1;
	nox_pitch_3801808 = 2 * v8;
	*getMemU32Ptr(0x5D4594, 3801776) = v8 >> 1;
	nox_backbuffer_width32 = v8 >> 4;
	dword_5d4594_3801804 = sub_444D90();
	return 1;
}

#if 0
// update screen
int __cdecl sub_48B5D0(int a1, int a2)
{
    return 0;
}

// on focus
void __cdecl sub_48A820(UINT uFlags)
{
}

// on deactivate
void __cdecl sub_48A9C0(int a1)
{
}

// restore device
int sub_48A2A0()
{
    return 0;
}

// check flip status, restore device if needed
void __cdecl sub_48A220()
{
}

// flip?
void __cdecl sub_48AAF0()
{
}

// flip?
void __cdecl sub_48AB50()
{
}

// initialize flip?
int sub_48ACC0()
{
}

// blit?
int __cdecl sub_48B840(int a1)
{
}

// blit?
int __cdecl sub_48BA50(int a1)
{
}

// draws to g_cursor_surf surface
int __cdecl sub_48B3F0(int a1, int a2, int a3)
{
}

// GfxInit
int __cdecl sub_444930(HWND a1, int a2, int a3, int a4, int a5)
{
    return 1;
}

// uninit?
void sub_444C50()
{
}

// init?
int sub_486090()
{
    return 1;
}

int sub_48B1F0()
{
    return 1;
}

// init?
int sub_4AD100()
{
    return 1;
}

void sub_4AD150()
{
}

// load palette
BOOL __cdecl sub_4347F0(char* a1, int a2)
{
    return 0;
}

int sub_4348C0()
{
    return 0;
}

// set color key of g_cursor_surf
BOOL sub_48BDE0()
{
    return 1;
}

// init gamma?
int sub_4338D0()
{
    return 1;
}

// current gamma
int sub_434B00()
{
    return 0;
}

// set gamma
int __cdecl sub_434B30(int a1)
{
    return 0;
}

// apply gamma
BOOL sub_434B60()
{
    return 0;
}

int(*g_on_movie_finished)();

// queue movie
int __cdecl sub_4B0300(char* a1)
{
    return 0;
}

// show movies
int __cdecl sub_4B0340(int a1)
{
    g_on_movie_finished();
    return 0;
}

// set on movies finished
int __cdecl sub_4B0640(int(*a1)(void))
{
    g_on_movie_finished = a1;
    return 0;
}

void sub_48A290_call_present()
{
}

char sub_48A190()
{
}

uint32_t nox_color_rgb_4344A0(int r, int g, int b)
{
    return 0;
}

void nox_set_color_rgb_434430(int a1, int a2, int a3)
{
}

int __cdecl sub_433E40(int a1)
{
    return 0;
}

int __cdecl sub_434040(int a1)
{
    return 0;
}

int __cdecl sub_4341D0(int a1, int a2)
{
    return 0;
}

int sub_4AD170_call_copy_backbuffer(void)
{
    return 0;
}

int __cdecl sub_433CD0(int a1, int a2, int a3)
{
    return 0;
}

void __cdecl sub_434480(int a1, int a2, int a3, int a4)
{
}

int __cdecl sub_434AA0(int a1, int a2, int a3)
{
}

void nox_set_color_rgb_4343B0(int a1, int a2, int a3)
{
}

void __cdecl sub_4340A0(int a1, int a2, int a3, int a4)
{
}

int __cdecl sub_48A040(int a1, int a2, int a3, int a4)
{
    return 0;
}

#else

#ifdef USE_SDL
int g_rotate;
int g_rotated;
Uint32 g_format;
SDL_GLContext g_ddraw;
GLuint g_texture, g_program, g_tex_coord_buffer, g_tex_coord_attr, g_gamma_uniform, g_matrix_uniform, g_sampler_uniform;
unsigned int g_tex_coord_itemsize, g_tex_coord_numitems;
float draw_gamma = 1.0f;

SDL_Surface* dword_6F7C48;
SDL_Surface* g_cursor_surf;
SDL_Surface* dword_973C60;
SDL_Surface* g_backbuffer1;
SDL_Surface* g_frontbuffer1;
SDL_Surface* g_backbufferrgb;
SDL_Surface* dword_973C88;

int4 sdl_get_display_dim() {
	int display_id;
	int4 result;
	SDL_Rect bounds = {0};

	result.field_0 = -1;
	result.field_4 = -1;
	result.field_8 = 0;
	result.field_C = 0;

	display_id = SDL_GetWindowDisplayIndex(getWindowHandle_sub_401FD0());

	if (display_id >= 0 && SDL_GetDisplayBounds(display_id, &bounds) == 0) {
		result.field_0 = bounds.w;
		result.field_4 = bounds.h;
		result.field_8 = bounds.x;
		result.field_C = bounds.y;
	}

	return result;
}

void sdl_set_window_rect(int2 size, int2 position) {
	SDL_SetWindowSize(getWindowHandle_sub_401FD0(), size.field_0, size.field_4);
	SDL_SetWindowPosition(getWindowHandle_sub_401FD0(), position.field_0, position.field_4);
}

extern int g_fullscreen;
extern int g_scaled;
extern int nox_win_width_1;
extern int nox_win_height_1;
void change_windowed_fullscreen() {
	int windowSizeW = nox_win_width_1;
	int windowSizeH = nox_win_height_1;
	int2 windowedSize;
	int2 fullscreenSize;
	int4 displaySize = sdl_get_display_dim();
	int centeredPositionX = displaySize.field_8 + (displaySize.field_0 - windowSizeW) / 2;
	int centeredPositionY = displaySize.field_C + (displaySize.field_4 - windowSizeH) / 2;
	int2 windowedPosition;
	int2 fullscreenPosition;
	int mode = g_fullscreen;

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
		SDL_SetWindowResizable(getWindowHandle_sub_401FD0(), SDL_FALSE);
		SDL_SetWindowBordered(getWindowHandle_sub_401FD0(), SDL_FALSE);
		sdl_set_window_rect(fullscreenSize, fullscreenPosition);
		SDL_SetWindowFullscreen(getWindowHandle_sub_401FD0(), SDL_WINDOW_FULLSCREEN_DESKTOP);
		break;
	case -2:
	case 2:
		// Borderless fullscreen
		SDL_SetWindowFullscreen(getWindowHandle_sub_401FD0(), 0);
		SDL_SetWindowResizable(getWindowHandle_sub_401FD0(), SDL_FALSE);
		SDL_SetWindowBordered(getWindowHandle_sub_401FD0(), SDL_TRUE);
		sdl_set_window_rect(fullscreenSize, fullscreenPosition);
		break;
	default:
		// Windowed
		SDL_SetWindowFullscreen(getWindowHandle_sub_401FD0(), 0);
		SDL_SetWindowResizable(getWindowHandle_sub_401FD0(), SDL_TRUE);
		SDL_SetWindowBordered(getWindowHandle_sub_401FD0(), SDL_TRUE);
		sdl_set_window_rect(windowedSize, windowedPosition);
		break;
	}
}

static void glCheckError() {
#if 0
    GLenum error = glGetError();
    if (error)
        DebugBreak();
#endif
}
#else
GUID* g_driver_guid;
LPDIRECTDRAW g_ddraw;
LPDIRECTDRAWSURFACE dword_6F7C48;
LPDIRECTDRAWSURFACE g_cursor_surf;
LPDIRECTDRAWSURFACE dword_973C60;
LPDIRECTDRAWSURFACE g_backbuffer2;
LPDIRECTDRAWSURFACE g_frontbuffer;
LPDIRECTDRAWSURFACE g_backbuffer1;
LPDIRECTDRAWSURFACE dword_973C88;
LPDIRECTDRAWCLIPPER g_clipper;
LPDIRECTDRAWPALETTE g_ddraw_palette;
LPDIRECTDRAWGAMMACONTROL g_ddraw_gamma_control;
#endif
DWORD dword_973C70;
DWORD g_present_ticks;
DWORD g_backbuffer_count;
DWORD dword_5ACFAC;
DWORD dword_6F7B9C;
void (*g_present_ptr)();
DWORD dword_6F7BB0;
DWORD dword_6F7BF8;
BYTE* dword_6F7C74;
BYTE* dword_6F7C78;
extern DWORD dword_974854;
int (*nox_video_cursorThreadedDrawFnPtr)(int);
void (*dword_6F7C10)(_DWORD, _DWORD, _DWORD);
__int16 (*dword_6F7C40)();
__int16 (*dword_6F7C34)();
void (*dword_975240)(_DWORD, _DWORD*, _DWORD*, _DWORD*);
int (*dword_975380)(_DWORD, _DWORD, _DWORD);
void (*nox_color_rgb_func)(uint8_t, uint8_t, uint8_t, uint32_t*);
void (*g_copy_backbuffer_ptr)();

//----- (0048A040) --------------------------------------------------------
int __cdecl sub_48A040(HWND a1, int a2, int a3, int a4) {
	int result; // eax

	g_backbuffer_count = 2;
	dword_6F7BB0 = 0;
#ifdef USE_SDL
	g_ddraw = 0;
	g_backbuffer1 = 0;
#else
	g_ddraw = 0;
	g_frontbuffer = 0;
	g_backbuffer1 = 0;
	g_clipper = 0;
#endif
	dword_973C88 = 0;
	dword_973C60 = 0;
	dword_973C70 = 0;
	g_present_ticks = 0;
	dword_974854 = 0;
	dword_6F7B9C = 1;
	dword_5ACFAC = 1;
	if (!(nox_video_renderTargetFlags & 4)) {
		sub_48AA40();
		result = sub_48B000();
		if (!result)
			return result;
#ifdef USE_SDL
		create_surfaces(a1, a2, a3);
#else
		if (nox_video_renderTargetFlags & 0x10) {
			// windowed mode
			result = sub_48AED0(a1, a2, a3);
			if (!result)
				return result;
		} else {
			// fullscreen mode
			result = sub_48AD40(a1, a2, a3, a4);
			if (!result)
				return result;
		}
#endif
	}
	dword_6F7BB0 = 1;
	sub_48A820(1u);
	result = sub_48A3D0();
	if (result) {
		sub_48A7F0();
		result = 1;
	}
	return result;
}

//----- (0048A120) --------------------------------------------------------
void sub_48A120() {
	dword_6F7BB0 = 0;
#ifndef USE_SDL
	if (g_ddraw)
		g_ddraw->lpVtbl->RestoreDisplayMode(g_ddraw);
	sub_48B190(&g_clipper);
	sub_48B1D0(&g_frontbuffer);
#endif
	sub_48B1D0_free_surface(&dword_973C60);
	sub_48B1D0_free_surface(&dword_973C88);
	if (g_backbuffer1 != g_frontbuffer1) {
		sub_48B1D0_free_surface(&g_frontbuffer1);
	} else {
		g_frontbuffer1 = 0;
	}
	sub_48B1D0_free_surface(&g_backbuffer1);
#ifndef USE_SDL
	sub_48B1B0(&g_ddraw);
#endif
	sub_48A9C0(0);
	sub_48AA40();
}

//----- (0048A190) --------------------------------------------------------
char sub_48A190() {
	int v0; // eax

#ifdef USE_SDL
	g_present_ptr = sdl_present;

	dword_6F7B9C = 1;
	nox_backbuffer1_pix = g_backbuffer1->pixels;
	nox_backbuffer_pix = nox_backbuffer1_pix;
#else
	if (*getMemU32Ptr(0x5D4594, 3801796) && nox_video_renderTargetFlags & 0x20 && (v0 = sub_48ACC0()) != 0) {
		g_present_ptr = sub_48AB50;
	} else {
		v0 = *(_DWORD*)&nox_video_renderTargetFlags;
		g_present_ptr = sub_48AAF0;
		LOBYTE(v0) = nox_video_renderTargetFlags & 0xDF;
		*(_DWORD*)&nox_video_renderTargetFlags = v0;
	}
#endif
	return v0;
}

//----- (0048A220) --------------------------------------------------------
void __cdecl sub_48A220() {
#ifndef USE_SDL
	HRESULT i; // eax

	if (g_ddraw && !dword_974854 && dword_973C64 && (!dword_973C70 || sub_48A2A0())) {
		for (i = g_frontbuffer->lpVtbl->GetFlipStatus(g_frontbuffer, 2); i;
			 i = g_frontbuffer->lpVtbl->GetFlipStatus(g_frontbuffer, 2)) {
			if (i == DDERR_SURFACELOST) {
				if (!sub_48A2A0())
					return;
			} else if (i == DDERR_SURFACEBUSY) {
				return;
			}
		}
	}
#endif
}

//----- (0048A290) --------------------------------------------------------
void sub_48A290_call_present() {
	g_present_ptr();
	++g_present_ticks;
}

#ifdef USE_SDL
SDL_Surface* __cdecl sub_48A600(int width, int height, int flags, int caps) {
	if (!(flags & DDSD_WIDTH))
		DebugBreak();
	if (!(flags & DDSD_HEIGHT))
		DebugBreak();
	return SDL_CreateRGBSurfaceWithFormat(0, width, height, 16, g_format);
	// FIXME
	//    return SDL_CreateRGBSurface(0, width, height, 16, 0xF800, 0x7E0, 0x1F, 0);
}

int __cdecl sub_48A720(SDL_Surface* a1, _DWORD* a2, _DWORD* a3, _DWORD* a4, int* a5) {
	if (a2)
		*a2 = a1->w;
	if (a3)
		*a3 = a1->h;
	if (a4)
		*a4 = a1->pitch;
	if (a5)
		*a5 = a1->pixels;
	return 0;
}

void __cdecl sub_48A670(SDL_Surface* a1) { SDL_LockSurface(a1); }

void __cdecl sub_48A6B0(SDL_Surface* a1) { SDL_UnlockSurface(a1); }
#else
//----- (0048A2A0) --------------------------------------------------------
int sub_48A2A0() {
	int v0; // esi

	if (!dword_6F7BB0 || !dword_974854)
		return 0;
	if (!(nox_video_renderTargetFlags & 0x200))
		SetForegroundWindow(windowHandle_dword_973FE0);
	v0 = 0;
	if (g_frontbuffer && g_frontbuffer->lpVtbl->IsLost(g_frontbuffer))
		v0 = g_frontbuffer->lpVtbl->Restore(g_frontbuffer);
	if (dword_6F7C48 && dword_6F7C48->lpVtbl->IsLost(dword_6F7C48))
		v0 = dword_6F7C48->lpVtbl->Restore(dword_6F7C48);
	if (nox_video_renderTargetFlags & 0x10) {
		if (v0 || g_backbuffer1 && g_backbuffer1->lpVtbl->IsLost(g_backbuffer1) &&
					  g_backbuffer1->lpVtbl->Restore(g_backbuffer1)) {
			goto LABEL_22;
		}
		if (!g_backbuffer2 || !g_backbuffer2->lpVtbl->IsLost(g_backbuffer2)) {
			goto LABEL_20;
		}
		v0 = g_backbuffer2->lpVtbl->Restore(g_backbuffer2);
	}
	if (!v0) {
	LABEL_20:
		sub_48A820(1u);
		if (sub_48ACC0()) {
			sub_48BE50(0);
			dword_973C70 = 0;
			return 1;
		}
	}
LABEL_22:
	if (!dword_973C70) {
		sub_48BE50(1);
		ShowWindow(windowHandle_dword_973FE0, SW_MINIMIZE);
		dword_973C70 = 1;
	}
	return 0;
}

//----- (0048A600) --------------------------------------------------------
LPDIRECTDRAWSURFACE __cdecl sub_48A600(int a1, int a2, int a3, int a4) {
	LPDIRECTDRAWSURFACE result; // eax
	DDSURFACEDESC v5;           // [esp+4h] [ebp-6Ch]
	LPDIRECTDRAWSURFACE surf;

	memset(&v5, 0, sizeof(v5));
	v5.dwSize = 108;
	v5.dwWidth = a1;
	v5.dwHeight = a2;
	v5.dwFlags = a3;
	v5.ddsCaps.dwCaps = a4;
	if (g_ddraw->lpVtbl->CreateSurface(g_ddraw, &v5, &surf, 0))
		surf = NULL;
	return surf;
}

//----- (0048A670) --------------------------------------------------------
void __cdecl sub_48A670(LPDIRECTDRAWSURFACE a1) {
	DDSURFACEDESC v3; // [esp+4h] [ebp-6Ch]

	memset(&v3, 0, sizeof(v3));
	v3.dwSize = sizeof(v3);
	a1->lpVtbl->Lock(a1, 0, &v3, DDLOCK_WAIT | DDLOCK_WRITEONLY | DDLOCK_NOSYSLOCK, 0);
}

//----- (0048A6B0) --------------------------------------------------------
void __cdecl sub_48A6B0(LPDIRECTDRAWSURFACE a1) { a1->lpVtbl->Unlock(a1, 0); }

//----- (0048A6C0) --------------------------------------------------------
LPVOID __cdecl sub_48A6C0(LPDIRECTDRAWSURFACE a1) {
	DDSURFACEDESC v3; // [esp+8h] [ebp-6Ch]

	memset(&v3, 0, sizeof(v3));
	v3.dwSize = 108;
	if (a1->lpVtbl->Lock(a1, 0, &v3, DDLOCK_WAIT, 0))
		return 0;
	a1->lpVtbl->Unlock(a1, v3.lpSurface);
	return v3.lpSurface;
}

//----- (0048A720) --------------------------------------------------------
int __cdecl sub_48A720(LPDIRECTDRAWSURFACE a1, _DWORD* a2, _DWORD* a3, _DWORD* a4, int* a5) {
	IDirectDrawSurfaceVtbl* v5; // eax
	int v6;                     // edi
	DDSURFACEDESC v8;           // [esp+Ch] [ebp-6Ch]

	memset(&v8, 0, sizeof(v8));
	v8.dwSize = sizeof(v8);
	v8.dwFlags = DDSD_HEIGHT | DDSD_WIDTH | DDSD_PITCH;
	v6 = a1->lpVtbl->GetSurfaceDesc(a1, &v8);
	if (!v6) {
		if (a2)
			*a2 = v8.dwWidth;
		if (a3)
			*a3 = v8.dwHeight;
		if (a4)
			*a4 = v8.lPitch;
	}
	if (a5)
		*a5 = (int)sub_48A6C0(a1);
	return v6;
}

//----- (0048A7B0) --------------------------------------------------------
void __cdecl sub_48A7B0(LPDIRECTDRAWSURFACE a1) {
	DDBLTFX v2; // [esp+0h] [ebp-64h]

	if (a1) {
		v2.dwSize = 100;
		v2.dwFillColor = 0;
		a1->lpVtbl->Blt(a1, 0, 0, 0, DDBLT_COLORFILL | DDBLT_WAIT, &v2);
	}
}
#endif

//----- (0048A7F0) --------------------------------------------------------
void sub_48A7F0() {
#ifdef USE_SDL
#if 0
    SDL_SetRenderDrawColor(g_ddraw, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(g_ddraw);
    SDL_RenderPresent(g_ddraw);
#endif
#else
	sub_48A7B0(g_frontbuffer);
	sub_48A7B0(g_backbuffer1);
	sub_48A7B0(g_backbuffer2);
#endif
}

//----- (0048A820) --------------------------------------------------------
void __cdecl sub_48A820(UINT uFlags) {
#ifdef USE_SDL
    //	DWORD width = nox_backbuffer_width;
    //	DWORD height = nox_backbuffer_height;

	// SDL_SetWindowSize(windowHandle_dword_973FE0, width, height);
	// SDL_SetWindowGrab(windowHandle_dword_973FE0, SDL_TRUE);
#else
	HCURSOR result; // eax
	int v2;         // ebp
	int v3;         // eax
	int v4;         // esi
	int v5;         // edi
	int v6;         // ebx
	int v7;         // ecx
	int v8;         // eax
	DWORD v9;       // eax
	HMENU v10;      // [esp-14h] [ebp-24h]
	RECT rc;        // [esp+0h] [ebp-10h]
	UINT uFlagsa;   // [esp+14h] [ebp+4h]

	if (nox_video_renderTargetFlags & 0x200 || (result = (HCURSOR)uFlags) != 0) {
		result = (HCURSOR)IsWindow(windowHandle_dword_973FE0);
		if (result) {
			v2 = GetSystemMetrics(0);
			v3 = GetSystemMetrics(1);
			v4 = nox_backbuffer_width;
			v5 = nox_backbuffer_height;
			v6 = v3;
			v7 = 0;
			v8 = 0;
			if (uFlags) {
				uFlagsa = 0;
				if ((nox_video_renderTargetFlags & 0x18) == 24) {
					v7 = (v2 - nox_backbuffer_width) / 2;
					v8 = (v6 - nox_backbuffer_height) / 2;
				LABEL_11:
					SetRect(&rc, v7, v8, v7 + v4, v8 + v5);
					v10 = GetMenu(windowHandle_dword_973FE0);
					v9 = GetWindowLongA(windowHandle_dword_973FE0, -16);
					AdjustWindowRect(&rc, v9, (BOOL)v10);
					SetWindowPos(windowHandle_dword_973FE0, (HWND)(((nox_video_renderTargetFlags & 0x10) != 0) - 1),
								 rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, uFlagsa);
					ShowWindow(windowHandle_dword_973FE0, 1);
					GetClientRect(windowHandle_dword_973FE0, &rc);
					ClientToScreen(windowHandle_dword_973FE0, (LPPOINT)&rc);
					ClientToScreen(windowHandle_dword_973FE0, (LPPOINT)&rc.right);
					if (!(nox_video_renderTargetFlags & 4))
						ClipCursor(&rc);
					sub_4348C0();
					dword_5ACFAC = 0;
					SetCursor(0);
					return;
				}
				if ((nox_video_renderTargetFlags & 0x10) != 16)
					goto LABEL_11;
			} else {
				uFlagsa = SWP_NOMOVE;
				if ((nox_video_renderTargetFlags & 0x18) != 16)
					goto LABEL_11;
			}
			v4 = v2;
			v5 = v6;
			goto LABEL_11;
		}
	}
#endif
}

//----- (0048A9C0) --------------------------------------------------------
void __cdecl sub_48A9C0(int a1) {
	if (dword_6F7BB0) {
		EnterCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
		if (!dword_974854) {
			if (nox_video_renderTargetFlags & 0x10) {
				dword_974854 = 1;
#ifdef USE_SDL
				printf("Ungrab\n");
				SDL_SetWindowGrab(windowHandle_dword_973FE0, SDL_FALSE);
#else
				ClipCursor(0);
#endif
				LeaveCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
				return;
			}
			if (a1) {
				dword_974854 = 1;
				dword_973C70 = 1;
#ifdef USE_SDL
				printf("Minimize\n");
				SDL_MinimizeWindow(windowHandle_dword_973FE0);
#else
				ShowWindow(windowHandle_dword_973FE0, SW_MINIMIZE);
#endif
			}
		}
		LeaveCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
	}
}

//----- (0048AA40) --------------------------------------------------------
void sub_48AA40() {
#ifdef USE_SDL
	// FIXME
#else
	int v1;   // eax
	DWORD v2; // eax
	int v3;   // [esp-8h] [ebp-18h]
	HMENU v4; // [esp-8h] [ebp-18h]
	RECT rc;  // [esp+0h] [ebp-10h]

	if (IsWindow(windowHandle_dword_973FE0)) {
		if ((nox_video_renderTargetFlags & 0x18) != 24) {
			v3 = GetSystemMetrics(1);
			v1 = GetSystemMetrics(0);
			SetRect(&rc, 0, 0, v1, v3);
			v4 = GetMenu(windowHandle_dword_973FE0);
			v2 = GetWindowLongA(windowHandle_dword_973FE0, -16);
			AdjustWindowRect(&rc, v2, (BOOL)v4);
			SetWindowPos(windowHandle_dword_973FE0, 0, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, 0);
			ShowWindow(windowHandle_dword_973FE0, 1);
		}
	}
	return result;
#endif
}

#ifdef USE_SDL
static void set_viewport(float srcw, float srch) {
	float ratio = srcw / srch, offx = 0, offy = 0;
	int vpw, vph, vpx, vpy;

#ifdef __EMSCRIPTEN__
	if (!g_scaled) {
		EM_ASM_({
			if (canvas.width / canvas.height !=
				(canvas.clientWidth * devicePixelRatio) / (canvas.clientHeight * devicePixelRatio)) {
				canvas.width = canvas.clientWidth * devicePixelRatio;
				canvas.height = canvas.clientHeight * devicePixelRatio;
			}
		});
	}
	vpw = EM_ASM_INT(return canvas.width);
	vph = EM_ASM_INT(return canvas.height);
#else
	SDL_GL_GetDrawableSize(windowHandle_dword_973FE0, &vpw, &vph);
#endif

	//
	// Maintain source aspect ratio
	//
	g_rotated = g_rotate && vph - ratio * vpw > vpw - ratio * vph;
	if (g_rotated)
		ratio = 1.0f / ratio;

	if (ratio * vph <= vpw) {
		offx = (vpw - vph * ratio) / 2;
		vpw = vph * ratio;
	} else {
		offy = (vph - vpw / ratio) / 2;
		vph = vpw / ratio;
	}
	vpx = offx;
	vpy = offy;

	glViewport(vpx, vpy, vpw, vph);
}

void sdl_present() {
	if (g_ddraw && g_backbuffer1) {
		SDL_Rect srcrect;
		SDL_Rect dstrect;
		SDL_Rect currrect;
		int res;
		BOOL isRectDifferent = 0;

		dstrect.x = 0;
		dstrect.y = 0;
		SDL_GL_GetDrawableSize(getWindowHandle_sub_401FD0(), &(dstrect.w), &(dstrect.h));
		SDL_GetClipRect(g_backbuffer1, &srcrect);
		if (dstrect.w != srcrect.w || dstrect.h != srcrect.h) {
			float newW;
			float newH;
			float newCoefficient = (float)(dstrect.w) / (float)(dstrect.h);
			float oldCoefficient = (float)(srcrect.w) / (float)(srcrect.h);
			if (newCoefficient > oldCoefficient) {
				newW = srcrect.h * newCoefficient;
				newH = srcrect.h;
			} else {
				newW = srcrect.w;
				newH = srcrect.w / newCoefficient;
			}
			dstrect.w = newW;
			dstrect.h = newH;

			isRectDifferent = 1;
		}
		if (g_frontbuffer1 != g_backbuffer1) {
			if (!g_scaled || isRectDifferent) {
				sub_48B1D0_free_surface(&g_frontbuffer1);
				g_frontbuffer1 = 0;
			} else {
				SDL_GetClipRect(g_frontbuffer1, &currrect);
				if (dstrect.h != currrect.h || dstrect.w != currrect.w) {
					sub_48B1D0_free_surface(&g_frontbuffer1);
					g_frontbuffer1 = 0;
				}
			}
		}
		if (g_scaled && g_frontbuffer1 == 0) {
			g_frontbuffer1 =
				sub_48A600(dstrect.w, dstrect.h, DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH, DDSCAPS_OFFSCREENPLAIN);
			SDL_SetSurfaceBlendMode(g_backbuffer1, SDL_BLENDMODE_NONE);
			SDL_SetSurfaceBlendMode(g_frontbuffer1, SDL_BLENDMODE_NONE);
		}
		if (g_scaled) {
			res = SDL_BlitScaled(g_backbuffer1, &srcrect, g_frontbuffer1, &dstrect);
		} else {
			g_frontbuffer1 = g_backbuffer1;
		}
		const float matrix[] = {1.0, 0.0, 0.0, 1.0};
		const float matrixRotated[] = {0.0, 1.0, 1.0, 0.0};

		sub_48BE50(1);
		nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(0, 0);

		glBindTexture(GL_TEXTURE_2D, g_texture);
		glCheckError();
#ifndef __EMSCRIPTEN__
		glPixelStorei(GL_UNPACK_ROW_LENGTH, g_frontbuffer1->pitch / 2);
		glCheckError();
#endif
#ifndef __EMSCRIPTEN__
		// XXX FIXME WHY?
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, g_frontbuffer1->w, g_frontbuffer1->h, 0, GL_BGRA,
					 GL_UNSIGNED_SHORT_1_5_5_5_REV, NULL);
#else
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, g_frontbuffer1->w, g_frontbuffer1->h, 0, GL_RGBA,
					 GL_UNSIGNED_SHORT_5_5_5_1, NULL);
#endif
		glCheckError();
#ifndef __EMSCRIPTEN__
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, g_frontbuffer1->w, g_frontbuffer1->h, GL_BGRA,
						GL_UNSIGNED_SHORT_1_5_5_5_REV, g_frontbuffer1->pixels);
#else
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, g_frontbuffer1->w, g_frontbuffer1->h, GL_RGBA,
						GL_UNSIGNED_SHORT_5_5_5_1, g_frontbuffer1->pixels);
#endif
		glCheckError();

		/*
			EM_ASM_({
				Module['renderTexture']($0, $1);
			}, g_backbuffer1->w, g_backbuffer1->h);
		*/
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glCheckError();

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glCheckError();
		set_viewport(g_frontbuffer1->w, g_frontbuffer1->h);
		glCheckError();

		glClear(GL_COLOR_BUFFER_BIT);
		glCheckError();

		glUseProgram(g_program);
		glCheckError();
		glUniform1i(g_sampler_uniform, 0);
		glCheckError();
		glUniformMatrix2fv(g_matrix_uniform, 1, GL_FALSE, g_rotated ? matrixRotated : matrix);
		glCheckError();
		glUniform1f(g_gamma_uniform, draw_gamma);
		glCheckError();
		glBindBuffer(GL_ARRAY_BUFFER, g_tex_coord_buffer);
		glCheckError();
		glVertexAttribPointer(g_tex_coord_attr, g_tex_coord_itemsize, GL_FLOAT, GL_FALSE, 0, 0);
		glCheckError();
		glDrawArrays(GL_TRIANGLE_STRIP, 0, g_tex_coord_numitems);
		glCheckError();

		SDL_GL_SwapWindow(windowHandle_dword_973FE0);

		sub_48BE50(0);
	}
}
#else
//----- (0048AAF0) --------------------------------------------------------
void __cdecl sub_48AAF0() {
	if (g_ddraw && !dword_974854 && (!g_frontbuffer->lpVtbl->IsLost(g_frontbuffer) || sub_48A2A0())) {
		sub_48BE50(1);
		sub_48B5D0(0, 0);
		g_frontbuffer->lpVtbl->Flip(g_frontbuffer, 0, DDFLIP_WAIT);
		sub_48BE50(0);
	}
}

//----- (0048AB50) --------------------------------------------------------
void __cdecl sub_48AB50() {
	int v0; // eax

	if (g_ddraw) {
		sub_48BE50(1);
		sub_48B5D0(0, 0);
		if (!g_frontbuffer->lpVtbl->Flip(g_frontbuffer, 0, DDFLIP_WAIT)) {
			v0 = ++dword_6F7B9C;
			if (dword_6F7B9C >= g_backbuffer_count) {
				v0 = 0;
				dword_6F7B9C = 0;
			}
			nox_backbuffer_pix = *getMemU32Ptr(0x5D4594, 4 * v0 + 1193488);
		}
		sub_48BE50(0);
	}
}

//----- (0048ABC0) --------------------------------------------------------
void __cdecl sub_48ABC0() {
	POINT Point;     // [esp+4h] [ebp-28h]
	RECT rectClient; // [esp+Ch] [ebp-20h]
	RECT rc;         // [esp+1Ch] [ebp-10h]

	if (!dword_974854 && g_ddraw && (!g_frontbuffer->lpVtbl->IsLost(g_frontbuffer) || sub_48A2A0())) {
		if (IsWindow(windowHandle_dword_973FE0)) {
			Point.x = 0;
			Point.y = 0;
			ClientToScreen(windowHandle_dword_973FE0, &Point);
			GetClientRect(windowHandle_dword_973FE0, &rectClient);
			OffsetRect(&rectClient, Point.x, Point.y);
			SetRect(&rc, 0, 0, nox_backbuffer_width, nox_backbuffer_height);
			sub_48BE50(1);
			sub_48BD90(0);
			sub_48B5D0(0, 0);
			g_frontbuffer->lpVtbl->Blt(g_frontbuffer, &rectClient, g_backbuffer1, &rc, 0x1000000, 0);
			sub_48BE50(0);
		}
	}
}

//----- (0048ACC0) --------------------------------------------------------
int sub_48ACC0() {
	int result; // eax

	if (!(nox_video_renderTargetFlags & 0x20))
		return 1;
	result = sub_48A6C0(g_frontbuffer);
	if (result) {
		*getMemU32Ptr(0x5D4594, 1193488) = result;
		result = sub_48A6C0(g_backbuffer1);
		if (result) {
			nox_backbuffer1_pix = result;
			if ((nox_video_renderTargetFlags & 0x80u) != 0) {
				result = sub_48A6C0(g_backbuffer2);
				if (!result)
					return result;
				*getMemU32Ptr(0x5D4594, 1193496) = result;
			}
			dword_6F7B9C = 1;
			nox_backbuffer_pix = nox_backbuffer1_pix;
			return 1;
		}
	}
	return result;
}
#endif

#ifdef USE_SDL
int create_surfaces(HWND a1, int width, int height) {
	int result = 0;
	BYTE v3;

	v3 = nox_video_renderTargetFlags;
#if 0
    if ((v3 & 0x18) == 24)
        SetWindowLongA(windowHandle_dword_973FE0, GWL_STYLE, WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_GROUP);
#endif
	g_backbuffer1 = sub_48A600(width, height, DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH, DDSCAPS_OFFSCREENPLAIN);
	// g_backbufferrgb = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_ABGR8888);
	if (g_backbuffer1) {
		// if (SDL_RenderSetLogicalSize(g_ddraw, width, height) == 0)
		result = 1;
	}
	return result;
}
#else
//----- (0048AD40) --------------------------------------------------------
signed int __cdecl sub_48AD40(HWND a1, int a2, int a3, int a4) {
	int v5;           // [esp+2Ch] [ebp-70h]
	DDSURFACEDESC v6; // [esp+30h] [ebp-6Ch]

	SetWindowLongA(windowHandle_dword_973FE0, GWL_STYLE, WS_POPUP);
	SetForegroundWindow(windowHandle_dword_973FE0);
	if (g_ddraw->lpVtbl->SetCooperativeLevel(g_ddraw, windowHandle_dword_973FE0, 19))
		return 0;
	if (g_ddraw->lpVtbl->SetDisplayMode(g_ddraw, a2, a3, a4))
		return 0;
	memset(&v6, 0, sizeof(v6));
	v6.dwSize = 108;
	v6.dwFlags = 33;
	v6.ddsCaps.dwCaps = 536;
	v6.dwBackBufferCount = 1;
	if ((*(_DWORD*)&nox_video_renderTargetFlags & 0x80u) != 0) {
		v6.dwBackBufferCount = 2;
		++g_backbuffer_count;
	}
	if (g_ddraw->lpVtbl->CreateSurface(g_ddraw, &v6, &g_frontbuffer, 0))
		return 0;
	v5 = 1;
	g_frontbuffer->lpVtbl->EnumAttachedSurfaces(g_frontbuffer, &v5, sub_48AE80);
	g_ddraw->lpVtbl->CreateClipper(g_ddraw, 0, &g_clipper, 0);
	g_clipper->lpVtbl->SetHWnd(g_clipper, 0, windowHandle_dword_973FE0);
	g_frontbuffer->lpVtbl->SetClipper(g_frontbuffer, g_clipper);
	return 1;
}

//----- (0048AE80) --------------------------------------------------------
int __stdcall sub_48AE80(LPDIRECTDRAWSURFACE a1, LPDDSURFACEDESC a2, LPVOID a3) {
	int v4; // eax

	v4 = *(_DWORD*)a3 - 1;
	if ((*(_DWORD*)a3)++ == 1) {
		g_backbuffer1 = a1;
		a1->lpVtbl->EnumAttachedSurfaces(a1, a3, sub_48AE80);
	} else if (v4 == 1 && g_backbuffer_count > 2) {
		g_backbuffer2 = a1;
		return 0;
	}
	return 0;
}

//----- (0048AED0) --------------------------------------------------------
int __cdecl sub_48AED0(HWND a1, int a2, int a3) {
	char v3;    // al
	HDC v4;     // esi
	int v5;     // edi
	int result; // eax

	v3 = nox_video_renderTargetFlags;
	if (!(v3 & 4)) {
		v4 = CreateICA("Display", 0, 0, 0);
		v5 = GetDeviceCaps(v4, 12);
		DeleteDC(v4);
		if (nox_backbuffer_depth == 8) {
			if (v5 != nox_backbuffer_depth) {
				sub_48C940("8 bit color windowed mode requires you switch your desktop to 256 colors");
				return 0;
			}
		} else if (nox_backbuffer_depth == 16 && v5 != 16) {
			sub_48C940("16 bit color windowed mode requires you switch your desktop to High Color (65536 colors)");
			return 0;
		}
	}
	if ((v3 & 0x18) == 24)
		SetWindowLongA(windowHandle_dword_973FE0, GWL_STYLE, WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_GROUP);
	if (g_ddraw->lpVtbl->SetCooperativeLevel(g_ddraw, windowHandle_dword_973FE0, 12))
		return 0;

	g_frontbuffer = sub_48A600(0, 0, DDSD_CAPS, DDSCAPS_PRIMARYSURFACE);
	if (g_frontbuffer) {
		g_backbuffer1 = sub_48A600(a2, a3, DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH, DDSCAPS_OFFSCREENPLAIN);
		if (g_backbuffer1) {
			g_ddraw->lpVtbl->CreateClipper(g_ddraw, 0, &g_clipper, 0);
			g_clipper->lpVtbl->SetHWnd(g_clipper, 0, windowHandle_dword_973FE0);
			g_frontbuffer->lpVtbl->SetClipper(g_frontbuffer, g_clipper);
			result = 1;
		} else {
			result = 0;
		}
	} else {
		result = 0;
	}
	return result;
}
#endif

#ifdef USE_SDL

#ifdef __EMSCRIPTEN__
#define FLOAT_PRECISION "precision mediump float;\n"
#else
#define FLOAT_PRECISION ""
#endif

const GLchar* vertex_source = FLOAT_PRECISION "attribute vec2 aTextureCoord;\n"
											  "varying vec4 vColor;\n"
											  "varying vec2 vTextureCoord;\n"
											  "\n"
											  "void main(void) {\n"
											  "    vec2 pos = 2.0 * aTextureCoord - 1.0;\n"
											  "    gl_Position = vec4(pos.x, pos.y, 0.0, 1.0);\n"
											  "    vTextureCoord = aTextureCoord;\n"
											  "}\n";
const GLchar* fragment_source =
	FLOAT_PRECISION "varying vec2 vTextureCoord;\n"
					"uniform sampler2D uSampler;\n"
					"uniform float uGamma;\n"
					"uniform mat2 uMatrix;\n"
					"\n"
					"void main(void) {\n"
					"    vec2 coordTex = vec3(vTextureCoord - 0.5, 1).xy + 0.5;\n"
					"    coordTex.y = uMatrix[1].y - (2.0 * uMatrix[1].y - 1.0) * coordTex.y;\n"
					"    gl_FragColor.rgb = pow(texture2D(uSampler, coordTex * uMatrix).rgb, vec3(1.0/uGamma));\n"
					"}\n";

int sub_48B000() {
	GLint status;
	GLuint vertex, fragment;
	float coords[] = {1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0};

#if __EMSCRIPTEN__
	g_rotate = EM_ASM_INT(return Module['shouldRotate']());
#else
	g_rotate = 0;
#endif
	g_format = SDL_PIXELFORMAT_RGBA5551;
	if (!g_ddraw) {
		g_ddraw = SDL_GL_CreateContext(windowHandle_dword_973FE0);
		if (g_ddraw == NULL) {
			fprintf(stderr, "SDL GL context creation failed: %s\n", SDL_GetError());
			return 0;
		}
	}
	SDL_GL_SetSwapInterval(1);

#ifdef _WIN32
    GLenum err = glewInit();
	if (GLEW_OK != err) {
		/* Problem: glewInit failed, something is seriously wrong. */
		dprintf("Error: %s\n", glewGetErrorString(err));
	}
#endif

	glGenTextures(1, &g_texture);
	glCheckError();
	glActiveTexture(GL_TEXTURE0);
	glCheckError();
	glBindTexture(GL_TEXTURE_2D, g_texture);
	glCheckError();
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, nox_win_width, nox_win_height, 0, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1, NULL);
	glCheckError();

#if 0
    EM_ASM_({
        Module['initGL']($0, $1);
        }, nox_win_width, nox_win_height);
#endif

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glCheckError();
	glShaderSource(vertex, 1, &vertex_source, NULL);
	glCheckError();
	glCompileShader(vertex);
	glCheckError();
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		char tmp[8192];
		glGetShaderInfoLog(vertex, 8192, NULL, tmp);
		fprintf(stderr, "vertex shader error: %s\n", tmp);
		return 0;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glCheckError();
	glShaderSource(fragment, 1, &fragment_source, NULL);
	glCheckError();
	glCompileShader(fragment);
	glCheckError();
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		char tmp[8192];
		glGetShaderInfoLog(fragment, 8192, NULL, tmp);
		fprintf(stderr, "fragment shader error: %s\n", tmp);
		return 0;
	}

	g_program = glCreateProgram();
	glCheckError();
	glAttachShader(g_program, vertex);
	glCheckError();
	glAttachShader(g_program, fragment);
	glCheckError();
	glLinkProgram(g_program);
	glCheckError();
	glGetProgramiv(g_program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) {
		fprintf(stderr, "Link failed.\n");
		return 0;
	}

	glUseProgram(g_program);
	glCheckError();
	g_tex_coord_attr = glGetAttribLocation(g_program, "aTextureCoord");
	glCheckError();
	glEnableVertexAttribArray(g_tex_coord_attr);
	glCheckError();
	g_gamma_uniform = glGetUniformLocation(g_program, "uGamma");
	glCheckError();
	g_matrix_uniform = glGetUniformLocation(g_program, "uMatrix");
	glCheckError();
	g_sampler_uniform = glGetUniformLocation(g_program, "uSampler");
	glCheckError();

	glGenBuffers(1, &g_tex_coord_buffer);
	glCheckError();
	glBindBuffer(GL_ARRAY_BUFFER, g_tex_coord_buffer);
	glCheckError();
	glBufferData(GL_ARRAY_BUFFER, sizeof(coords), coords, GL_STATIC_DRAW);
	g_tex_coord_itemsize = 2;
	g_tex_coord_numitems = 4;

	return 1;
}
#else
//----- (0048B000) --------------------------------------------------------
int sub_48B000() {
	int result;        // eax
	GUID* v1;          // eax
	LPDIRECTDRAW lpDD; // [esp+14h] [ebp-8h]
	int v3;            // [esp+18h] [ebp-4h]

	lpDD = 0;
	g_driver_guid = NULL;
	if (DirectDrawEnumerateA(Callback, 0))
		return 0;
	if (DirectDrawCreate(g_driver_guid, &lpDD, 0))
		return 0;
	if (*getMemU32Ptr(0x5D4594, 1193504))
		lpDD->lpVtbl->EnumDisplayModes(lpDD, 0, 0, 0, *(LPDDENUMMODESCALLBACK*)getMemAt(0x5D4594, 1193504));
	if (sub_48B140(lpDD, &IID_IDirectDraw, &v3)) {
		if (v3)
			lpDD->lpVtbl->Release(lpDD);
		result = 1;
	} else {
		sub_48C940("You do not have the correct version of DirectX!");
		result = 0;
	}
	return result;
}

//----- (0048B0C0) --------------------------------------------------------
BOOL __stdcall Callback(GUID* lpGUID, LPSTR a2, LPSTR a3, LPVOID a4) {
	LPDIRECTDRAW lpDD; // [esp+Ch] [ebp-180h]
	DDCAPS v6;

	if (!DirectDrawCreate(lpGUID, &lpDD, 0)) {
		memset(&v6, 0, sizeof(v6));
		v6.dwSize = 380;
		if (!lpDD->lpVtbl->GetCaps(lpDD, &v6, 0) && (v6.dwCaps & (DDCAPS_BLT | DDCAPS_3D)) == DDCAPS_BLT)
			g_driver_guid = lpGUID;
		lpDD->lpVtbl->Release(lpDD);
	}
	return 1;
}

//----- (0048B140) --------------------------------------------------------
int __cdecl sub_48B140(LPDIRECTDRAW a1, const IID* a2, int* a3) {
	LPVOID pvObj;
	int result; // eax

	if (a1->lpVtbl->QueryInterface(a1, a2, &pvObj)) {
		g_ddraw = a1;
		result = 1;
		*a3 = 0;
	} else {
		g_ddraw = pvObj;
		result = 1;
		*a3 = 1;
	}
	return result;
}
#endif

#ifdef USE_SDL
void __cdecl sub_48B1B0(SDL_GLContext* a1) {
	if (*a1) {
		SDL_GL_DeleteContext(*a1);
		*a1 = NULL;
	}
}

void __cdecl sub_48B1D0_free_surface(SDL_Surface** a1) {
	if (*a1) {
		SDL_FreeSurface(*a1);
		*a1 = NULL;
	}
}
#else
//----- (0048B190) --------------------------------------------------------
void __cdecl sub_48B190(LPDIRECTDRAWCLIPPER* a1) {
	if (*a1) {
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}

//----- (0048B1B0) --------------------------------------------------------
void __cdecl sub_48B1B0(LPDIRECTDRAW* a1) {
	if (*a1) {
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}

//----- (0048B1D0) --------------------------------------------------------
void __cdecl sub_48B1D0(LPDIRECTDRAWSURFACE* a1) {
	if (*a1) {
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}
#endif

//----- (0048B1F0) --------------------------------------------------------
int nox_video_initCursorDrawVars_48B1F0() {
	int result; // eax

	if (nox_video_renderTargetFlags & 0x100) {
		nox_video_cursorDrawIsThreaded = 0;
		return 1;
	}
	nox_video_cursorDrawIsThreaded = 1;
	if (nox_video_renderTargetFlags & 4)
		return 1;
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
	if (dword_5d4594_3801780) {
		if (dword_5d4594_3801780 == 1) {
			dword_6F7C10 = sub_48C200;
			dword_6F7C40 = sub_48C480;
			dword_6F7C34 = sub_48C4D0;
		}
	} else {
		dword_6F7C10 = sub_48C320;
		dword_6F7C40 = sub_48C420;
		dword_6F7C34 = sub_48C420;
	}
#ifdef USE_SDL
	nox_video_cursorThreadedDrawFnPtr = sdl_drawCursorThreaded;
#else
	if (nox_video_renderTargetFlags & 0x10)
		// windowed mode
		dword_6F7BF0 = sub_48BA50;
	else
		// fullscreen mode
		dword_6F7BF0 = sub_48B840;
#endif
	result = nox_video_createCursorSurface_48BF70();
	printf("%s: %d\n", __FUNCTION__, result);
	if (result) {
		result = sub_48C060();
		printf("%s: %d\n", __FUNCTION__, result);
		if (result) {
			result = sub_48BDE0();
			printf("%s: %d\n", __FUNCTION__, result);
			if (result) {
				result = nox_video_createCursorDrawThread_48BE70();
				printf("%s: %d\n", __FUNCTION__, result);
				if (result) {
					nox_video_drawCursorThreadOk = 1;
					return 1;
				}
			}
		}
	}
	return result;
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
		// SDL_BlitScaled(dword_6F7C48, &src, g_backbuffer1, &dst);
	}

	r1->left = dword_5d4594_1193648 - *getMemU32Ptr(0x5D4594, 1193580);
	r1->right = r1->left + *getMemU32Ptr(0x5D4594, 1193600);
	r1->top = dword_5d4594_1193524 - *getMemU32Ptr(0x5D4594, 1193636);
	r1->bottom = r1->top + *getMemU32Ptr(0x5D4594, 1193620);

	if ((!a1 || dword_5d4594_1193668 || dword_5d4594_1193664) &&
		sub_49F930((int4*)&v4, r1, (int4*)(&obj_5D4594_3800716.data[9]))) {
		r2->left = 0;
		r2->top = 0;
		r2->right = v4.right - v4.left;
		r2->bottom = v4.bottom - v4.top;

		// FIXME frontbuffer?
		rect_to_sdl(&v4, &src);
		rect_to_sdl(r2, &dst);
		// if (SDL_BlitScaled(g_backbuffer1, &src, dword_6F7C48, &dst))
		//    return 0;
	}

	if (sub_49F930((int4*)&v4, r1, (int4*)(&obj_5D4594_3800716.data[9]))) {
		r3->left = v4.left - r1->left;
		r3->top = v4.top - r1->top;
		r3->right = v4.right - r1->left;
		r3->bottom = v4.bottom - r1->top;

		// FIXME frontbuffer?
		rect_to_sdl(r3, &src);
		rect_to_sdl(&v4, &dst);

#if 0 // SDL textures cannot be locked from threads other than where they were created in.
        uint16_t * dstpixels;
        int dstpitch;

        if (SDL_LockTexture(g_texture, &dst, (void**)& dstpixels, &dstpitch) == 0)
        {
            unsigned int x, y;
            unsigned int colorkey;
            int srcpitch = g_cursor_surf->pitch;
            uint16_t* srcpixels = (uint16_t*)g_cursor_surf->pixels;
            SDL_Rect srcrect;

            SDL_GetColorKey(g_cursor_surf, &colorkey);

            srcpixels += src.x + src.y * srcpitch / sizeof(*srcpixels);

            for (y = 0; y < src.h; y++)
            {
                for (x = 0; x < src.w; x++)
                {
                    uint16_t pixel = srcpixels[x];
                    if (pixel != colorkey)
                        dstpixels[x] = pixel;
                    dstpixels[x] = 0;
                }
                dstpixels += dstpitch / sizeof(*dstpixels);
                srcpixels += srcpitch / sizeof(*srcpixels);
            }

            SDL_UnlockTexture(g_texture);
			/*
            SDL_RenderCopy(g_ddraw, g_texture, &dst, &dst);
            SDL_RenderPresent(g_ddraw);
			*/
        }
#endif

		if (SDL_BlitScaled(g_cursor_surf, &src, g_backbuffer1, &dst))
			return 0;

		*r1 = v4;
	}

	dword_5d4594_1193664 = 0;
	dword_5d4594_1193668 = 0;
	return 1;
}

#if 0
//----- (0048B840) --------------------------------------------------------
int __cdecl sub_48B840(int a1)
{
    LPDIRECTDRAWSURFACE v1;
    LPDIRECTDRAWSURFACE v3; // eax
    RECT v4; // [esp+30h] [ebp-10h]

    if (a1
        && (*(_DWORD*)& dword_5d4594_1193668 || *(_DWORD*)& dword_5d4594_1193664)
        && !IsRectEmpty((const RECT*)getMemAt(0x5D4594, 1193532)))
    {
        g_frontbuffer->lpVtbl->Blt(g_frontbuffer,
            getMemAt(0x5D4594, 1193532),
            dword_6F7C48,
            getMemAt(0x5D4594, 1193548),
            0x1000000,
            0);
    }
    *getMemU32Ptr(0x5D4594, 1193532) = *(_DWORD*)& dword_5d4594_1193648 - *getMemU32Ptr(0x5D4594, 1193580);
    *getMemU32Ptr(0x5D4594, 1193540) = *(_DWORD*)& dword_5d4594_1193648
        - *getMemU32Ptr(0x5D4594, 1193580)
        + *getMemU32Ptr(0x5D4594, 1193600);
    *getMemU32Ptr(0x5D4594, 1193536) = *(_DWORD*)& dword_5d4594_1193524 - *getMemU32Ptr(0x5D4594, 1193636);
    *getMemU32Ptr(0x5D4594, 1193544) = *(_DWORD*)& dword_5d4594_1193524
        - *getMemU32Ptr(0x5D4594, 1193636)
        + *getMemU32Ptr(0x5D4594, 1193620);
    if ((!a1 || *(_DWORD*)& dword_5d4594_1193668 || *(_DWORD*)& dword_5d4594_1193664)
        && sub_49F930((int4*)& v4, (int4*)getMemAt(0x5D4594, 1193532),(int4*)(&obj_5D4594_3800716.data[9])))
    {
        *getMemU32Ptr(0x5D4594, 1193556) = v4.right - v4.left;
        v1 = g_frontbuffer;
        *getMemU32Ptr(0x5D4594, 1193548) = 0;
        *getMemU32Ptr(0x5D4594, 1193552) = 0;
        *getMemU32Ptr(0x5D4594, 1193560) = v4.bottom - v4.top;
        if (!a1)
            v1 = g_backbuffer1;
        if (dword_6F7C48->lpVtbl->Blt(dword_6F7C48,
            getMemAt(0x5D4594, 1193548),
            v1,
            &v4,
            0x1000000,
            0))
        {
            return 0;
        }
    }
    if (sub_49F930((int4*)& v4, (int4*)getMemAt(0x5D4594, 1193532), (int4*)(&obj_5D4594_3800716.data[9])))
    {
        *getMemU32Ptr(0x5D4594, 1193604) = v4.left - *getMemU32Ptr(0x5D4594, 1193532);
        *getMemU32Ptr(0x5D4594, 1193608) = v4.top - *getMemU32Ptr(0x5D4594, 1193536);
        *getMemU32Ptr(0x5D4594, 1193612) = v4.right - *getMemU32Ptr(0x5D4594, 1193532);
        v3 = g_frontbuffer;
        *getMemU32Ptr(0x5D4594, 1193616) = v4.bottom - *getMemU32Ptr(0x5D4594, 1193536);
        if (!a1)
            v3 = g_backbuffer1;
        if (v3->lpVtbl->Blt(v3,
            &v4,
            g_cursor_surf,
            getMemAt(0x5D4594, 1193604),
            16809984,
            0))
        {
            return 0;
        }
        *(RECT*)getMemAt(0x5D4594, 1193532) = v4;
    }
    *(_DWORD*)& dword_5d4594_1193664 = 0;
    *(_DWORD*)& dword_5d4594_1193668 = 0;
    return 1;
}

//----- (0048BA50) --------------------------------------------------------
int __cdecl sub_48BA50(int a1)
{
    int v2; // eax
    struct tagPOINT Point; // [esp+28h] [ebp-38h]
    RECT v4; // [esp+30h] [ebp-30h]
    RECT rc; // [esp+40h] [ebp-20h]
    int v6[4]; // [esp+50h] [ebp-10h]

    if (a1
        && (*(_DWORD*)& dword_5d4594_1193668 || *(_DWORD*)& dword_5d4594_1193664)
        && !IsRectEmpty((const RECT*)getMemAt(0x5D4594, 1193532)))
    {
        sub_48C170((int4*)& rc, (int4*)getMemAt(0x5D4594, 1193532));
        sub_48C170((int4*)v6, (int4*)getMemAt(0x5D4594, 1193548));
        Point.x = 0;
        Point.y = 0;
        ClientToScreen(windowHandle_dword_973FE0, &Point);
        OffsetRect(&rc, Point.x, Point.y);
        g_frontbuffer->lpVtbl->Blt(g_frontbuffer,
            &rc,
            dword_6F7C48,
            v6,
            0x1000000,
            0);
    }
    *getMemU32Ptr(0x5D4594, 1193532) = *(_DWORD*)& dword_5d4594_1193648 - *getMemU32Ptr(0x5D4594, 1193580);
    *getMemU32Ptr(0x5D4594, 1193540) = *(_DWORD*)& dword_5d4594_1193648
        - *getMemU32Ptr(0x5D4594, 1193580)
        + *getMemU32Ptr(0x5D4594, 1193600);
    *getMemU32Ptr(0x5D4594, 1193536) = *(_DWORD*)& dword_5d4594_1193524 - *getMemU32Ptr(0x5D4594, 1193636);
    *getMemU32Ptr(0x5D4594, 1193544) = *(_DWORD*)& dword_5d4594_1193524
        - *getMemU32Ptr(0x5D4594, 1193636)
        + *getMemU32Ptr(0x5D4594, 1193620);
    if ((!a1 || *(_DWORD*)& dword_5d4594_1193668 || *(_DWORD*)& dword_5d4594_1193664)
        && sub_49F930((int4*)& v4, (int4*)getMemAt(0x5D4594, 1193532), (int4*)(&obj_5D4594_3800716.data[9])))
    {
        *getMemU32Ptr(0x5D4594, 1193556) = v4.right - v4.left;
        *getMemU32Ptr(0x5D4594, 1193548) = 0;
        *getMemU32Ptr(0x5D4594, 1193552) = 0;
        *getMemU32Ptr(0x5D4594, 1193560) = v4.bottom - v4.top;
        if (a1)
        {
            sub_48C170((int4*)& rc, (int4*)& v4);
            sub_48C170((int4*)v6, (int4*)getMemAt(0x5D4594, 1193548));
            Point.x = 0;
            Point.y = 0;
            ClientToScreen(windowHandle_dword_973FE0, &Point);
            OffsetRect(&rc, Point.x, Point.y);
            if (dword_6F7C48->lpVtbl->Blt(dword_6F7C48,
                v6,
                g_frontbuffer,
                &rc,
                0x1000000,
                0))
            {
                return 0;
            }
        }
        else
        {
            sub_48C170((int4*)v6, (int4*)getMemAt(0x5D4594, 1193548));
            if (dword_6F7C48->lpVtbl->Blt(dword_6F7C48,
                v6,
                g_backbuffer1,
                &v4,
                0x1000000,
                0))
            {
                return 0;
            }
        }
    }
    if (sub_49F930((int4*)& v4, (int4*)getMemAt(0x5D4594, 1193532), (int4*)(&obj_5D4594_3800716.data[9])))
    {
        *getMemU32Ptr(0x5D4594, 1193604) = v4.left - *getMemU32Ptr(0x5D4594, 1193532);
        *getMemU32Ptr(0x5D4594, 1193608) = v4.top - *getMemU32Ptr(0x5D4594, 1193536);
        *getMemU32Ptr(0x5D4594, 1193612) = v4.right - *getMemU32Ptr(0x5D4594, 1193532);
        *getMemU32Ptr(0x5D4594, 1193616) = v4.bottom - *getMemU32Ptr(0x5D4594, 1193536);
        if (a1)
        {
            sub_48C170((int4*)& rc, (int4*)& v4);
            Point.x = 0;
            Point.y = 0;
            ClientToScreen(windowHandle_dword_973FE0, &Point);
            OffsetRect(&rc, Point.x, Point.y);
            v2 = g_frontbuffer->lpVtbl->Blt(g_frontbuffer,
                &rc,
                g_cursor_surf,
                getMemAt(0x5D4594, 1193604),
                16809984,
                0);
        }
        else
        {
            v2 = g_backbuffer1->lpVtbl->Blt(g_backbuffer1,
                &v4,
                g_cursor_surf,
                getMemAt(0x5D4594, 1193604),
                16809984,
                0);
        }
        if (v2)
            return 0;
        *(RECT*)getMemAt(0x5D4594, 1193532) = v4;
    }
    *(_DWORD*)& dword_5d4594_1193664 = 0;
    *(_DWORD*)& dword_5d4594_1193668 = 0;
    return 1;
}
#endif

//----- (004340A0) --------------------------------------------------------
void __cdecl sub_4340A0(int a1, int a2, int a3, int a4) {
	unsigned __int64 v4; // rax
	int v5;              // esi
	unsigned __int64 v6; // rax
	unsigned __int64 v7; // rax

	a2 = a2 & 0xFF;
	a3 = a3 & 0xFF;
	a4 = a4 & 0xFF;

	v4 = a1;
	if (a1 >= 0 && a1 < 16) {
		v5 = 48 * a1 + (_DWORD)(&ptr_5D4594_3799572->data[66]);
		*(_DWORD*)(v5 + 32) = (unsigned __int8)a4;
		*(_DWORD*)(v5 + 24) = (unsigned __int8)a2;
		*(_DWORD*)(v5 + 28) = (unsigned __int8)a3;
		nox_color_rgb_func(a2, a3, a4, (DWORD*)(v5 + 40));
		LODWORD(v4) = dword_5d4594_3801804;
		if (dword_5d4594_3801804) {
			v6 = ((unsigned __int8)a2 | (((unsigned __int8)a2 | ((unsigned __int64)(unsigned __int8)a2 << 16)) << 16))
				 << 16;
			*(_DWORD*)v5 = (unsigned __int8)a2 | (unsigned int)v6;
			*(_DWORD*)(v5 + 4) = HIDWORD(v6);
			v7 = ((unsigned __int8)a3 | (((unsigned __int8)a3 | ((unsigned __int64)(unsigned __int8)a3 << 16)) << 16))
				 << 16;
			*(_DWORD*)(v5 + 8) = (unsigned __int8)a3 | (unsigned int)v7;
			*(_DWORD*)(v5 + 12) = HIDWORD(v7);
			v4 = ((unsigned __int8)a4 | (((unsigned __int8)a4 | ((unsigned __int64)(unsigned __int8)a4 << 16)) << 16))
				 << 16;
			LODWORD(v4) = (unsigned __int8)a4 | (unsigned int)v4;
			*(_QWORD*)(v5 + 16) = v4;
		}
	}
}

//----- (004347F0) --------------------------------------------------------
BOOL __cdecl sub_4347F0(char* a1, int a2) {
	if (a2 <= 256) {
		sub_435120(getMemAt(0x5D4594, 3803308), a1);
		sub_4353F0();
		sub_435040();
		sub_434F00();
	}
	return sub_48BDE0();
}

//----- (004348C0) --------------------------------------------------------
int sub_4348C0() {
#ifdef USE_SDL
	// FIXME 8-bit support
	return 0;
#else
	int result;           // eax
	PALETTEENTRY v1[256]; // [esp+0h] [ebp-400h]

	if (!g_ddraw_palette)
		return 0;
	sub_4350E0(v1, getMemAt(0x5D4594, 3803308));
	if (g_ddraw_palette->lpVtbl->SetEntries(g_ddraw_palette, 0, 0, 256, v1)) {
		return 0;
	}
	sub_4354F0();
	result = 1;
	*getMemU32Ptr(0x5D4594, 3804660) = 1;
	return result;
#endif
}

//----- (00434FB0) --------------------------------------------------------
int sub_434FB0() {
#ifdef USE_SDL
	// FIXME 8-bit support
	return 1;
#else
	PALETTEENTRY v1[256]; // [esp+0h] [ebp-400h]

	g_ddraw_palette = 0;
	if (nox_video_renderTargetFlags & 4 || dword_5d4594_3799624)
		return 1;

	sub_4350E0(v1, getMemAt(0x5D4594, 3803308));
	if (g_ddraw->lpVtbl->CreatePalette(g_ddraw, 68, v1, &g_ddraw_palette, 0))
		return 0;
	if (g_frontbuffer->lpVtbl->SetPalette(g_frontbuffer, g_ddraw_palette))
		return 0;
	return 1;
#endif
}

//----- (004352E0) --------------------------------------------------------
void __cdecl sub_4352E0() {
#ifdef USE_SDL
	// FIXME gamma control
#else
	DDCAPS v0; // [esp+4h] [ebp-2F8h]
	DDCAPS v1; // [esp+180h] [ebp-17Ch]

	if (g_ddraw) {
		memset(&v0, 0, 0x17Cu);
		memset(&v1, 0, 0x17Cu);
		v0.dwSize = 380;
		v1.dwSize = 380;
		if (!g_ddraw->lpVtbl->GetCaps(g_ddraw, &v0, &v1) &&
			(v0.dwCaps2 & DDCAPS2_PRIMARYGAMMA || v1.dwCaps2 & DDCAPS2_PRIMARYGAMMA)) {
			g_frontbuffer->lpVtbl->QueryInterface(g_frontbuffer, &IID_IDirectDrawGammaControl, &g_ddraw_gamma_control);
		}
	}
#endif
}

//----- (00444F90) --------------------------------------------------------
HDC sub_444F90() {
	DebugBreak();

#if 0
    HDC result; // eax
    HDC v1; // [esp+8h] [ebp-4h]

    result = 0;
    v1 = 0;
    if (g_frontbuffer)
    {
        g_frontbuffer->lpVtbl->GetDC(g_frontbuffer, &v1);
        result = v1;
    }
    return result;
#else
	return 0;
#endif
}

//----- (00444FC0) --------------------------------------------------------
void __cdecl sub_444FC0(HDC a1) {
	DebugBreak();

#if 0
    if (g_frontbuffer)
    {
        if (a1)
            g_frontbuffer->lpVtbl->ReleaseDC(g_frontbuffer, a1);
    }
#endif
}

//----- (004353C0) --------------------------------------------------------
void sub_4353C0() {
#ifdef USE_SDL
	// FIXME 8-bit support
#else
	HDC v0; // esi

	v0 = GetDC(0);
	GetSystemPaletteEntries(v0, 0, 0x100u, (LPPALETTEENTRY)getMemAt(0x587000, 84412));
	return ReleaseDC(0, v0);
#endif
}

//----- (004353F0) --------------------------------------------------------
void sub_4353F0() {
#ifdef USE_SDL
	// FIXME 8-bit support
#else
	char* v1;           // eax
	int v2;             // ecx
	HDC v3;             // esi
	HPALETTE v4;        // eax
	HPALETTE v5;        // ebp
	HPALETTE v6;        // eax
	int i;              // eax
	unsigned __int8 v8; // cl
	unsigned __int8 v9; // dl
	char plpal[1028];   // [esp+8h] [ebp-404h]

	*(_WORD*)plpal = 768;
	*(_WORD*)&plpal[2] = 256;
	memset(&plpal[4], 0, 0x400u);
	if (!dword_5d4594_3799624 && nox_video_renderTargetFlags & 0x10) {
		sub_435550();
		v1 = &plpal[5];
		v2 = 256;
		do {
			*(v1 - 1) = 0;
			*v1 = 0;
			v1[1] = 0;
			v1[2] = 4;
			v1 += 4;
			--v2;
		} while (v2);
		v3 = GetDC(0);
		v4 = CreatePalette((const LOGPALETTE*)plpal);
		if (v4) {
			v5 = SelectPalette(v3, v4, 0);
			RealizePalette(v3);
			v6 = SelectPalette(v3, v5, 0);
			DeleteObject(v6);
		}
		GetSystemPaletteEntries(v3, 0, 0x100u, (LPPALETTEENTRY)&plpal[4]);
		ReleaseDC(0, v3);
		for (i = 0; i < 944; i += 4) {
			v8 = getMemByte(0x5D4594, i + 3803349);
			plpal[i + 44] = getMemByte(0x5D4594, i + 3803348);
			v9 = getMemByte(0x5D4594, i + 3803350);
			plpal[i + 45] = v8;
			plpal[i + 46] = v9;
			plpal[i + 47] = 4;
		}

		*getMemU32Ptr(0x5D4594, 809596) = CreatePalette((const LOGPALETTE*)plpal);
	}
#endif
}

//----- (004354F0) --------------------------------------------------------
void sub_4354F0() {
#ifdef USE_SDL
	// FIXME 8-bit support
#else
	HDC v1; // esi

	if (!dword_5d4594_3799624 && nox_video_renderTargetFlags & 0x10) {
		if (*getMemU32Ptr(0x5D4594, 809596)) {
			v1 = GetDC(windowHandle_dword_973FE0);
			SelectPalette(v1, *(HPALETTE*)getMemAt(0x5D4594, 809596), 0);
			RealizePalette(v1);
			ReleaseDC(windowHandle_dword_973FE0, v1);
		}
	}
#endif
}

//----- (00435550) --------------------------------------------------------
void sub_435550() {
#ifdef USE_SDL
	// FIXME 8-bit support
#else
	if (*getMemU32Ptr(0x5D4594, 809596)) {
		DeleteObject(*(HGDIOBJ*)getMemAt(0x5D4594, 809596));
		*getMemU32Ptr(0x5D4594, 809596) = 0;
	}
#endif
}

//----- (00433C20) --------------------------------------------------------
void sub_433C20() {
	sub_48A7F0();
#ifdef USE_SDL
#else
	sub_435380(&g_ddraw_gamma_control);
	sub_4353A0(&g_ddraw_palette);
#endif
	if (dword_5d4594_810640) {
		free(*(LPVOID*)&dword_5d4594_810640);
		dword_5d4594_810640 = 0;
	}
	if (dword_5d4594_3804668) {
		free(*(LPVOID*)&dword_5d4594_3804668);
		dword_5d4594_3804668 = 0;
	}
	if (dword_5d4594_3804672) {
		free(*(LPVOID*)&dword_5d4594_3804672);
		dword_5d4594_3804672 = 0;
	}
	if (dword_5d4594_3804656) {
		free(*(LPVOID*)&dword_5d4594_3804656);
		dword_5d4594_3804656 = 0;
	}
	if (dword_5d4594_3804664) {
		free(*(LPVOID*)&dword_5d4594_3804664);
		dword_5d4594_3804664 = 0;
	}
	sub_435550();
	*getMemU32Ptr(0x5D4594, 3804660) = 0;
}

//----- (00444930) --------------------------------------------------------
int __cdecl sub_444930(HWND wnd, int w, int h, int depth, int flags) {
	dword_5d4594_823776 = 0;
	ptr_5D4594_3799572 = &obj_5D4594_3799660;
	int result = sub_4449D0(wnd, w, h, depth, flags);
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return 0;
	}
	ptr_5D4594_3799572 = &obj_5D4594_3800716;
	memcpy(&obj_5D4594_3800716, &obj_5D4594_3799660, sizeof(obj_5D4594_3799572_t));
	if (nox_video_renderTargetFlags & 0x200) {
#ifdef USE_SDL
		SDL_MinimizeWindow(windowHandle_dword_973FE0);
#else
		ShowWindow(windowHandle_dword_973FE0, SW_MINIMIZE);
		PostMessageA(windowHandle_dword_973FE0, WM_ACTIVATEAPP, 0, 0);
#endif
	}
	result = 1;
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
		sub_433C20();
		nullsub_15();
		sub_48A120();
		sub_44D9D0();
		sub_4B0660();
		nullsub_13();
		nullsub_11();
		nullsub_18();
		sub_4AF950();
		nullsub_17();
		sub_4AE540();
		nullsub_12();
		sub_43F2E0();
		nullsub_16();
		sub_49F4D0();
		windowHandle_dword_973FE0 = 0;
		dword_5d4594_823776 = 0;
		if (*getMemU32Ptr(0x5D4594, 823780)) {
			DeleteCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
			*getMemU32Ptr(0x5D4594, 823780) = 0;
		}
	}
}

//----- (0048C110) --------------------------------------------------------
void sub_48C110() {

#ifdef USE_SDL
	*getMemU32Ptr(0x5D4594, 1193684) = nox_backbuffer_width;
	*getMemU32Ptr(0x5D4594, 1193688) = nox_backbuffer_height;
#else
    RECT Rect; // [esp+0h] [ebp-10h]
	if (nox_video_renderTargetFlags & 0x10) {
		GetClientRect(windowHandle_dword_973FE0, &Rect);
		*getMemU32Ptr(0x5D4594, 1193684) = Rect.right - Rect.left;
		*getMemU32Ptr(0x5D4594, 1193688) = Rect.bottom - Rect.top;
	} else {
		*getMemU32Ptr(0x5D4594, 1193684) = nox_backbuffer_width;
		*getMemU32Ptr(0x5D4594, 1193688) = nox_backbuffer_height;
	}
#endif
}

#ifndef USE_SDL
//----- (0048C940) --------------------------------------------------------
int __cdecl sub_48C940(LPCSTR lpText) {
	if (g_ddraw)
		g_ddraw->lpVtbl->FlipToGDISurface(g_ddraw);
	ClipCursor(0);
	ShowCursor(1);
	return MessageBoxA(windowHandle_dword_973FE0, lpText, "NOX", 0x42010u);
}
#endif

//----- (004AD100) --------------------------------------------------------
int sub_4AD100() {
	if (nox_video_renderTargetFlags & 0x40)
		g_copy_backbuffer_ptr = sub_4AD180;
	else
		sub_4AD150();
	*getMemU32Ptr(0x5D4594, 3798652) = 0;
	return 1;
}

//----- (004AD150) --------------------------------------------------------
void sub_4AD150() {
	g_copy_backbuffer_ptr = sub_4AD2A0;
	if (!(nox_video_renderTargetFlags & 0x20))
		g_copy_backbuffer_ptr = sub_4AD1E0;
}

void sub_4AD170_call_copy_backbuffer(void) { g_copy_backbuffer_ptr(); }

//----- (004AD180) --------------------------------------------------------
void sub_4AD180() {
	DebugBreak();

#if 0
    int result; // eax
    DDBLTFX v1; // [esp+4h] [ebp-64h]

    memset(&v1, 0, sizeof(v1));
    v1.dwSize = 100;
    v1.dwROP = SRCCOPY;
    result = g_backbuffer1->lpVtbl->Blt(g_backbuffer1, 0, dword_973C88, 0, 0, &v1);
    if (!result)
    {
        nox_pixbuffer_swap_4861A0();
        result = sub_48A5E0();
    }
    return result;
#endif
}

//----- (004AD1E0) --------------------------------------------------------
void sub_4AD1E0() {
	int result; // eax
	_WORD* v1;  // edi
	_WORD* v4;  // esi

	if (dword_973C70) {
		return;
	}
#ifdef USE_SDL
	result = SDL_LockSurface(g_backbuffer1);
	v1 = g_backbuffer1->pixels;
#else
	DDSURFACEDESC v11; // [esp+Ch] [ebp-70h]
	v11.dwSize = sizeof(v11);
	v11.dwFlags = 0;
	result = g_backbuffer1->lpVtbl->Lock(g_backbuffer1, 0, &v11, 1, 0);
	v1 = v11.lpSurface;
#endif
	if (result) {
		return;
	}

	_WORD** v3 = nox_pixbuffer_rows_3798784;
	for (int v2 = nox_backbuffer_height; v2 > 0; v2--) {
		v4 = *v3;
		for (int v5 = nox_backbuffer_width32; v5 > 0; v5--) {
			for (int i = 0; i < 16; i++) {
				*v1 = *v4 << 1;
				v1++;
				v4++;
			}
		}
		// memcpy(v1, v4, v5 * 32);
		// v1 = (_DWORD *)((char *)v1 + v5 * 32);
		v1 = (_WORD*)((char*)v1 + nox_backbuffer_pitch32);
		++v3;
	}
#ifdef USE_SDL
	SDL_UnlockSurface(g_backbuffer1);
#else
	g_backbuffer1->lpVtbl->Unlock(g_backbuffer1, v11.lpSurface);
#endif
	++*getMemU32Ptr(0x5D4594, 3798652);
}

//----- (004AD2A0) --------------------------------------------------------
void sub_4AD2A0() {
	// FIXME unlocked surfaces
	if (dword_973C70) {
		return;
	}
	_DWORD* dst = nox_backbuffer_pix;
	_DWORD** src = nox_pixbuffer_rows_3798784;
	for (int y = 0; y < nox_backbuffer_height; y++) {
		_DWORD* row = src[y];
		for (int x = 0; x < nox_backbuffer_width32; x++) {
			memcpy(dst, row, 32);
			row += 8;
			dst += 8;
		}
		dst = (_DWORD*)((char*)dst + nox_backbuffer_pitch32);
	}
	++*getMemU32Ptr(0x5D4594, 3798652);
}

//----- (00486090) --------------------------------------------------------
int sub_486090() {
	int result; // eax

	result = sub_4861D0();
	if (result) {
		result = sub_486230();
		if (result) {
			if (!(nox_video_renderTargetFlags & 0x40) || (result = sub_48A5D0(), (dword_973C88 = result) != 0) &&
															 (result = sub_48A5D0(), (dword_973C60 = result) != 0)) {
				result = 1;
			}
		}
	}
	return result;
}

//----- (0048A5E0) --------------------------------------------------------
int sub_48A5E0() {
	int result; // eax

	result = dword_973C88;
	dword_973C88 = dword_973C60;
	dword_973C60 = result;
	return result;
}

//----- (0048A3D0) --------------------------------------------------------
int sub_48A3D0() {
#ifdef USE_SDL
	dword_5d4594_3801780 = 2;
	*getMemU32Ptr(0x5D4594, 3801796) = 0;
	if (g_backbuffer1) {
		nox_backbuffer_width = g_backbuffer1->w;
		nox_backbuffer_height = g_backbuffer1->h;
		*getMemU32Ptr(0x5D4594, 3799564) = g_backbuffer1->pitch;
		*getMemU32Ptr(0x5D4594, 3801796) = 1;
		sub_48A190();
		if (g_format == SDL_PIXELFORMAT_RGBA5551 || g_format == SDL_PIXELFORMAT_RGB565) {
			nox_backbuffer_width32 = g_backbuffer1->w >> 4;
			*getMemU32Ptr(0x5D4594, 3801776) = g_backbuffer1->w >> 1;
			dword_5d4594_3801780 = 1;
			nox_pitch_3801808 = 2 * g_backbuffer1->w;
			nox_backbuffer_pitch32 = g_backbuffer1->pitch - 2 * g_backbuffer1->w;

			if (g_format == SDL_PIXELFORMAT_RGBA5551)
				dword_5d4594_3799624 = 1;
			else if (g_format == SDL_PIXELFORMAT_RGB565)
				dword_5d4594_3799624 = 2;
			return 1;
		}
	}
	return 0;
#else
	int result;        // eax
	int v1;            // eax
	int v2;            // ecx
	int v3;            // edx
	int v4;            // esi
	int v5;            // ecx
	unsigned int v6;   // eax
	int v7;            // esi
	unsigned int v8;   // eax
	int i;             // edx
	unsigned int v10;  // eax
	int j;             // ecx
	DDSURFACEDESC v12; // [esp+4h] [ebp-6Ch]

	dword_5d4594_3801780 = 2;
	*getMemU32Ptr(0x5D4594, 3801796) = 0;
	if (g_backbuffer1) {
		if (g_backbuffer1->lpVtbl->IsLost(g_backbuffer1)) {
			result = sub_48A2A0();
			if (!result)
				return result;
		}
		v12.dwSize = 108;
		v12.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PITCH | DDSD_CKDESTBLT;
		if (!g_backbuffer1->lpVtbl->GetSurfaceDesc(g_backbuffer1, &v12)) {
			v1 = v12.dwWidth;
			v2 = v12.lPitch;
			nox_backbuffer_height = v12.dwHeight;
			nox_backbuffer_width = v12.dwWidth;
			*getMemU32Ptr(0x5D4594, 3799564) = v12.lPitch;
			dword_973C64 = v12.ddsCaps.dwCaps & DDSCAPS_FLIP;
			if (v12.ddsCaps.dwCaps & DDSCAPS_FLIP) {
				*getMemU32Ptr(0x5D4594, 3801796) = 1;
				sub_48A190();
				v1 = nox_backbuffer_width;
				v2 = *getMemU32Ptr(0x5D4594, 3799564);
			} else {
				*getMemU32Ptr(0x5D4594, 3801796) = 0;
				g_present_ptr = sub_48ABC0;
				*(_DWORD*)&nox_video_renderTargetFlags &= 0xFFFFFFDF;
			}
			if (v12.ddpfPixelFormat.dwRGBBitCount == 16) {
				v3 = 2 * v1;
				v4 = v1;
				v5 = v2 - 2 * v1;
				nox_backbuffer_width32 = v1 >> 4;
				v6 = v12.ddpfPixelFormat.dwRBitMask;
				*getMemU32Ptr(0x5D4594, 3801776) = v4 >> 1;
				v7 = 0;
				dword_5d4594_3801780 = 1;
				nox_pitch_3801808 = v3;
				for (nox_backbuffer_pitch32 = v5; v6; v6 >>= 1) {
					if (v6 & 1)
						++v7;
				}
				v8 = v12.ddpfPixelFormat.dwGBitMask;
				for (i = 0; v8; v8 >>= 1) {
					if (v8 & 1)
						++i;
				}
				v10 = v12.ddpfPixelFormat.dwBBitMask;
				for (j = 0; v10; v10 >>= 1) {
					if (v10 & 1)
						++j;
				}
				if (v7 != 5)
					return 1;
				if (i == 5) {
					if (j == 5)
						dword_5d4594_3799624 = 1;
					return 1;
				}
				if (i != 6 || j != 5)
					return 1;
				dword_5d4594_3799624 = 2;
				return 1;
			}
			if (v12.ddpfPixelFormat.dwRGBBitCount == 8) {
				dword_5d4594_3801780 = 0;
				*getMemU32Ptr(0x5D4594, 3801776) = v1 >> 2;
				dword_5d4594_3799624 = 0;
				nox_pitch_3801808 = v1;
				nox_backbuffer_width32 = v1 >> 5;
				nox_backbuffer_pitch32 = v2 - v1;
				return 1;
			}
		}
		if (dword_5d4594_3801780 != 2)
			return 1;
	}
	if (!(nox_video_renderTargetFlags & 4)) {
		if (nox_video_renderTargetFlags & 0x10) {
			sub_48C940("Unsupported windowed video mode detected\r\n\r\nPlease change your desktop to 16 "
					   "bit color");
			return 0;
		}
		sub_48C940("Unsupported video mode\r\n\r\nPlease select either 16 bit color or 256 colors");
	}
	return 0;
#endif
}

//----- (0048BF70) --------------------------------------------------------
int nox_video_createCursorSurface_48BF70() {
	int result; // eax
	int v1;     // [esp+0h] [ebp-18h]
	int v2;     // [esp+4h] [ebp-14h]
	int4 a1;    // [esp+8h] [ebp-10h]

#ifdef USE_SDL
	g_cursor_surf =
		sub_48A600(128, 128, DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT, DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY);
#else
	g_cursor_surf =
		sub_48A600(128, 128, DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT, DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY);
#endif
	if (g_cursor_surf) {
		if (sub_48A720(g_cursor_surf, &v2, &v1, &dword_6F7BF8, &dword_6F7C74)) {
			result = 0;
		} else if (dword_6F7C74) {
			a1.field_0 = 0;
			a1.field_4 = 0;
			a1.field_8 = 128;
			a1.field_C = 128;
			sub_48C170(&a1, &a1);
			dword_6F7C48 =
				sub_48A600(a1.field_8, a1.field_C, DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT, DDSCAPS_VIDEOMEMORY);
			if (dword_6F7C48) {
				if (sub_48A720(dword_6F7C48, &v2, &v1, 0, &dword_6F7C78))
					result = 0;
				else
					result = dword_6F7C78 != 0;
			} else {
				result = 0;
			}
		} else {
			result = 0;
		}
	} else {
		result = 0;
	}
	return result;
}

//----- (0048B3F0) --------------------------------------------------------
int __cdecl sub_48B3F0(int a1, int a2, int a3) {
	int i; // esi

	if (nox_video_cursorDrawIsThreaded) {
		EnterCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
		*getMemU32Ptr(0x5D4594, 1193640) = dword_5d4594_1193648;
		*getMemU32Ptr(0x5D4594, 1193628) = dword_5d4594_1193524;
		dword_5d4594_1193648 = a2;
		dword_5d4594_1193524 = a3;
		if (a1 && a1 != dword_5d4594_1193624) {
			dword_5d4594_1193624 = a1;
			sub_48A670(g_cursor_surf);
			for (i = 0; i < 512; i += 4)
				sub_49D1C0(*(_DWORD*)(i + dword_5d4594_1193704), *getMemIntPtr(0x5D4594, 1193592), 128);
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
			sub_48A6B0(g_cursor_surf);
		}
		if (dword_5d4594_1193648 != *getMemU32Ptr(0x5D4594, 1193640) ||
			dword_5d4594_1193524 != *getMemU32Ptr(0x5D4594, 1193628)) {
			dword_5d4594_1193668 = 1;
		}
		LeaveCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
	} else if (dword_5d4594_1193672 && a1) {
		nox_client_drawImageAt_47D2C0(a1, a2, a3);
		return 1;
	}
	return 1;
}

//----- (0048BDE0) --------------------------------------------------------
BOOL sub_48BDE0() {
	int v0; // eax

	v0 = nox_color_rgb_4344A0(255, 0, 255);
	*getMemU32Ptr(0x5D4594, 1193592) = v0;
	if (g_cursor_surf) {
#if USE_SDL
		// FIXME use SDL_MapRGB instead?
		v0 = dword_5d4594_3799624 ? (unsigned __int16)v0 : (unsigned __int8)v0;
		SDL_SetColorKey(g_cursor_surf, SDL_TRUE, v0);
#else
		DDCOLORKEY v2; // [esp+0h] [ebp-8h]

		v0 = dword_5d4594_3799624 ? (unsigned __int16)v0 : (unsigned __int8)v0;
		v2.dwColorSpaceHighValue = v0;
		v2.dwColorSpaceLowValue = v0;
		if (g_cursor_surf->lpVtbl->SetColorKey(g_cursor_surf, DDCKEY_SRCBLT, &v2))
			return 0;
#endif
	}
	return 1;
}

//----- (0048C060) --------------------------------------------------------
int sub_48C060() {
	int result; // eax
	int v1;     // ecx
	int v2;     // edx

	if (g_cursor_surf && dword_6F7C74) {
		result = (int)malloc(0x200u);
		dword_5d4594_1193704 = result;
		if (!result)
			return result;
		v1 = dword_6F7C74;
		v2 = 0;
		while (1) {
			*(_DWORD*)(v2 + result) = v1;
			v2 += 4;
			v1 += dword_6F7BF8;
			if (v2 >= 512)
				break;
			result = dword_5d4594_1193704;
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
#ifdef USE_SDL
	sub_48B1D0_free_surface(&g_cursor_surf);
	sub_48B1D0_free_surface(&dword_6F7C48);
#else
	if (g_cursor_surf) {
		g_cursor_surf->lpVtbl->Release(g_cursor_surf);
		g_cursor_surf = 0;
	}
	if (dword_6F7C48) {
		dword_6F7C48->lpVtbl->Release(dword_6F7C48);
		dword_6F7C48 = 0;
	}
#endif
	if (dword_5d4594_1193704) {
		free(*(LPVOID*)&dword_5d4594_1193704);
		dword_5d4594_1193704 = 0;
	}
	dword_5d4594_1193624 = 0;
}

#ifdef USE_SDL
#else
//----- (00435380) --------------------------------------------------------
void __cdecl sub_435380(LPDIRECTDRAWGAMMACONTROL* a1) {
	if (*a1) {
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}

//----- (004353A0) --------------------------------------------------------
void __cdecl sub_4353A0(LPDIRECTDRAWPALETTE* a1) {
	if (*a1) {
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}
#endif

//----- (004338D0) --------------------------------------------------------
int sub_4338D0() {
	int result;          // eax
	pixel888 v2[256];    // [esp+Ch] [ebp-300h]

	switch (dword_5d4594_3799624) {
	case 0:
		nox_color_rgb_func = nox_color_func_435180;
		dword_975240 = sub_435240;
		dword_975380 = sub_434E80;
		memcpy(getMemAt(0x5D4594, 3804364), byte_581450_9176, sizeof(byte_581450_9176));
		break;
	case 1:
		nox_color_rgb_func = nox_color_func_4351C0;
		dword_975240 = sub_435280;
		dword_975380 = sub_434E80;
		memcpy(getMemAt(0x5D4594, 3804364), byte_581450_9176, sizeof(byte_581450_9176));
		break;
	case 2:
		nox_color_rgb_func = nox_color_func_435200;
		dword_975240 = sub_435280;
		dword_975380 = sub_434EC0;
		void* v0 = getMemAt(0x581450, 9336);
		memcpy(getMemAt(0x5D4594, 3804364), v0, 0xA0u);
		break;
	}
	ptr_5D4594_3799572->data[13] = 0;
	ptr_5D4594_3799572->data[14] = 0;
	ptr_5D4594_3799572->data[17] = 0;
	ptr_5D4594_3799572->data[24] = 0;
	ptr_5D4594_3799572->data[25] = 0;
	ptr_5D4594_3799572->data[26] = 0;
	ptr_5D4594_3799572->data[44] = 0;
	ptr_5D4594_3799572->data[45] = 0;
	ptr_5D4594_3799572->data[46] = 0;
	ptr_5D4594_3799572->data[54] = 0;
	ptr_5D4594_3799572->data[55] = 0;
	ptr_5D4594_3799572->data[56] = 0;
	ptr_5D4594_3799572->data[58] = 0;
	ptr_5D4594_3799572->data[59] = 0;
	ptr_5D4594_3799572->data[60] = 0;
	ptr_5D4594_3799572->data[61] = 0;
	ptr_5D4594_3799572->data[259] = 255;
	ptr_5D4594_3799572->data[260] = 16711935;
	ptr_5D4594_3799572->data[261] = 16711935;
	ptr_5D4594_3799572->data[262] = 0;
	sub_434990(25, 25, 25);
	result = sub_434CC0();
	if (result) {
		result = sub_434DA0();
		if (result) {
			if (!dword_5d4594_823772)
				sub_4353C0();
			*getMemU32Ptr(0x5D4594, 809596) = 0;
			dword_5d4594_808568 = 0;
			dword_5d4594_810628 = 0;
			if (dword_5d4594_823772) {
				sub_435150(v2, (char*)getMemAt(0x5D4594, 3803308));
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
#ifdef USE_SDL
				// TODO gamma control
#else
				g_ddraw_gamma_control = 0;
#endif
				dword_5d4594_808564 = 0;
				sub_4348C0();
				sub_4352E0();
				*getMemU32Ptr(0x5D4594, 3804660) = 0;
				result = 1;
			}
		}
	}
	return result;
}

//----- (00433CD0) --------------------------------------------------------
int __cdecl sub_433CD0(BYTE a1, BYTE a2, BYTE a3) {
	__int64 v5;          // rax
	unsigned __int64 v6; // rax
	unsigned __int64 v7; // rax
	int result;          // eax

	ptr_5D4594_3799572->data[24] = a1;
	ptr_5D4594_3799572->data[25] = a2;
	ptr_5D4594_3799572->data[26] = a3;
	ptr_5D4594_3799572->data[16] = a1 == 0xFF && a2 == 0xFF && a3 == 0xFF;
	if (dword_5d4594_3801804) {
		v5 = a1 | (a1 << 16);
		v5 <<= 16;
		LODWORD(v5) = a1 | (unsigned int)v5;
		v5 <<= 16;
		ptr_5D4594_3799572->data[18] = a1 | (unsigned int)v5;
		ptr_5D4594_3799572->data[19] = HIDWORD(v5);
		v6 = (a2 | ((a2 | ((unsigned __int64)a2 << 16)) << 16)) << 16;
		ptr_5D4594_3799572->data[20] = a2 | (unsigned int)v6;
		ptr_5D4594_3799572->data[21] = HIDWORD(v6);
		v7 = (a3 | ((a3 | ((unsigned __int64)a3 << 16)) << 16)) << 16;
		ptr_5D4594_3799572->data[22] = a3 | (unsigned int)v7;
		ptr_5D4594_3799572->data[23] = HIDWORD(v7);
	}
	result = dword_975380(a1, a2, a3);
	((_WORD*)(&ptr_5D4594_3799572->data[258]))[1] = result;
	return result;
}

//----- (00433E40) --------------------------------------------------------
int __cdecl sub_433E40(int a1) {
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	return sub_433CD0(v3, v2, a1);
}

//----- (00433ED0) --------------------------------------------------------
void __cdecl sub_433ED0(int a1) {
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	sub_433E80(v3, v2, a1);
}

//----- (00434040) --------------------------------------------------------
int __cdecl sub_434040(int a1) {
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	return sub_433F10(v3, v2, a1);
}

//----- (004341D0) --------------------------------------------------------
int __cdecl sub_4341D0(int a1, int a2) {
	int result;          // eax
	int v3;              // edi
	int v4;              // esi
	int v5;              // ecx
	unsigned __int64 v6; // rax
	unsigned __int64 v7; // rax
	__int64 v8;          // kr10_8
	unsigned __int64 v9; // rax
	int v10;             // [esp+8h] [ebp-4h]

	result = a1;
	if (a1 >= 0 && a1 < 16) {
		v3 = a2;
		v4 = 48 * a1 + (_DWORD)(&ptr_5D4594_3799572->data[66]);
		result = *(_DWORD*)(48 * a1 + (_DWORD)(&ptr_5D4594_3799572->data[76]));
		if (a2 != result) {
			dword_975240(a2, &a1, &a2, &v10);
			*(_DWORD*)(v4 + 24) = (unsigned __int8)a1;
			*(_DWORD*)(v4 + 28) = (unsigned __int8)a2;
			v5 = (unsigned __int8)v10;
			*(_DWORD*)(v4 + 40) = v3;
			*(_DWORD*)(v4 + 32) = v5;
			result = dword_5d4594_3801804;
			if (dword_5d4594_3801804) {
				v6 = (unsigned __int64)((unsigned __int8)a1 | ((unsigned __int8)a1 << 16)) << 16;
				LODWORD(v6) = (unsigned __int8)a1 | (unsigned int)v6;
				*(_QWORD*)v4 = (unsigned __int8)a1 | (v6 << 16);
				v7 = (unsigned __int64)((unsigned __int8)a2 | ((unsigned __int8)a2 << 16)) << 16;
				LODWORD(v7) = (unsigned __int8)a2 | (unsigned int)v7;
				*(_QWORD*)(v4 + 8) = (unsigned __int8)a2 | (v7 << 16);
				v8 = (unsigned __int8)v10;
				v9 = (unsigned __int64)((unsigned __int8)v10 | ((unsigned __int8)v10 << 16)) << 16;
				LODWORD(v9) = (unsigned __int8)v10 | (unsigned int)v9;
				v9 <<= 16;
				result = (unsigned __int8)v10 | (unsigned int)v9;
				*(_DWORD*)(v4 + 16) = result;
				*(_DWORD*)(v4 + 20) = HIDWORD(v8) | HIDWORD(v9);
			}
		}
	}
	return result;
}

//----- (00434320) --------------------------------------------------------
void nox_set_color_rgb_434320(int r, int g, int b) {
	r = r & 0xFF;
	g = g & 0xFF;
	b = b & 0xFF;
	if (nox_color_rgb_func)
		nox_color_rgb_func(r, g, b, &ptr_5D4594_3799572->data[58]);
}

//----- (004343B0) --------------------------------------------------------
void nox_set_color_rgb_4343B0(int r, int g, int b) {
	r = r & 0xFF;
	g = g & 0xFF;
	b = b & 0xFF;
	if (nox_color_rgb_func)
		nox_color_rgb_func(r, g, b, &ptr_5D4594_3799572->data[59]);
}

//----- (00434400) --------------------------------------------------------
void nox_set_color_rgb_434400(int r, int g, int b) {
	r = r & 0xFF;
	g = g & 0xFF;
	b = b & 0xFF;
	if (nox_color_rgb_func)
		nox_color_rgb_func(r, g, b, &ptr_5D4594_3799572->data[60]);
}

//----- (00434430) --------------------------------------------------------
void nox_set_color_rgb_434430(int r, int g, int b) {
	r = r & 0xFF;
	g = g & 0xFF;
	b = b & 0xFF;
	if (nox_color_rgb_func)
		nox_color_rgb_func(r, g, b, &ptr_5D4594_3799572->data[61]);
}

//----- (00434480) --------------------------------------------------------
void __cdecl sub_434480(int a1, int a2, int a3, int a4) { dword_975240(a1, a2, a3, a4); }

//----- (004344A0) --------------------------------------------------------
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

//----- (00434AA0) --------------------------------------------------------
int __cdecl sub_434AA0(int a1, int a2, int a3) { return dword_975380(a1, a2, a3); }

//----- (00434AC0) --------------------------------------------------------
int __cdecl sub_434AC0(int a1) {
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	return dword_975380(v3, v2, a1);
}

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

//----- (00434B30) --------------------------------------------------------
int __cdecl nox_video_setGammaSetting_434B30(int a1) {
	int result; // eax

	result = a1;
	if (a1 >= 1) {
		if (a1 > 10)
			result = 10;
		nox_video_gammaValue = result;
	} else {
		result = 1;
		nox_video_gammaValue = 1;
	}

	return result;
}

//----- (00434B60) --------------------------------------------------------
BOOL sub_434B60() {
	int v0;              // ebp
	pixel888* v1;        // edi
	int v2;              // ebx
	char* v3;            // esi
	__int64 v4;          // rax
	int v13;             // [esp+10h] [ebp-90Ch]
	char v14[1536];
	pixel888 v19[256]; // [esp+61Ch] [ebp-300h]

	v0 = nox_video_gammaValue;
	v1 = v19;
	if (nox_video_gammaValue < 1) {
		v0 = 1;
	LABEL_5:
		nox_video_gammaValue = v0;
		goto LABEL_6;
	}
	if (nox_video_gammaValue > 10) {
		v0 = 10;
		goto LABEL_5;
	}
LABEL_6:
	v2 = 0;
	v3 = &v14[512];
	v13 = 0;
	do {
		if (v0 == 1)
			LOWORD(v4) = (_WORD)v2 << 8;
		else
			v4 = (__int64)(pow((double)v13 * 0.00392156862745098, 1.0 / ((double)(v0 - 1) * 0.1666666666666667 + 1.0)) *
						   65535.0);
		*((_WORD*)v3 + 256) = v4;
		*(_WORD*)v3 = v4;
		*((_WORD*)v3 - 256) = v4;
		++v2;
		v3 += 2;
		v13 = v2;
	} while (v2 < 256);
#ifdef USE_SDL
	// FIXME gamma control
	return 0;
#else
    unsigned __int8* v5; // eax
	int v6;              // ecx
	int v7;              // edi
    char v8;             // dl
    int v9;              // ecx
    char v10;            // dl
	int v11;             // ecx
	if (dword_5d4594_3799624)
		return g_ddraw_gamma_control && !g_ddraw_gamma_control->lpVtbl->SetGammaRamp(g_ddraw_gamma_control, 0, &v14);
	sub_434920();
	v5 = getMemAt(0x5D4594, 808573);
	do {
		v6 = *(v5 - 1);
		v7 = (int)&v1->field_1;
		v5 += 4;
		v8 = v14[2 * v6 + 1];
		v9 = *(v5 - 4);
		*(_BYTE*)(v7++ - 1) = v8;
		v10 = v14[2 * v9 + 513];
		v11 = *(v5 - 3);
		*(_BYTE*)(v7 - 1) = v10;
		v1 = (pixel888*)(v7 + 1);
		v1[-1].field_2 = v14[2 * v11 + 1025];
	} while ((int)v5 < (int)getMemAt(0x5D4594, 809597));
	sub_4347F0((char*)v19, 256);
	sub_4348C0();
	return 1;
#endif
}
// 434B60: using guessed type char var_8FF[511];
// 434B60: using guessed type char var_6FF[512];
// 434B60: using guessed type char var_4FF[511];

//----- (00434CC0) --------------------------------------------------------
int sub_434CC0() {
	int v0;       // edi
	void* result; // eax
	int i;        // esi

	if (!dword_5d4594_3801780) {
		v0 = nox_color_rgb_func;
		nox_color_rgb_func = nox_color_func_4351C0;
	}
	result = calloc(257, 2);
	dword_5d4594_3804672 = result;
	if (!result) {
		return 0;
	}
	result = calloc(257, 2);
	dword_5d4594_3804656 = result;
	if (!result) {
		return 0;
	}
	result = calloc(257, 2);
	dword_5d4594_3804664 = result;
	if (!result) {
		return 0;
	}
	for (i = 0; i < 256; ++i) {
		*(_WORD*)(dword_5d4594_3804672 + 2 * i) = nox_color_rgb_4344A0(i, 0, 0);
		*(_WORD*)(dword_5d4594_3804656 + 2 * i) = nox_color_rgb_4344A0(0, i, 0);
		*(_WORD*)(dword_5d4594_3804664 + 2 * i) = nox_color_rgb_4344A0(0, 0, i);
	}
	if (!dword_5d4594_3801780)
		nox_color_rgb_func = v0;
	return 1;
}
// 434CDD: variable 'v3' is possibly undefined

//----- (004B0300) --------------------------------------------------------
int __cdecl sub_4B0300(char* a1) {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 1311928);
	if (*getMemIntPtr(0x5D4594, 1311928) < 2) {
		strncpy((char*)getMemAt(0x5D4594, 260 * *getMemU32Ptr(0x5D4594, 1311928) + 1311940), a1, 0x104u);
		result = ++*getMemU32Ptr(0x5D4594, 1311928);
	}
	return result;
}

#ifdef NOX_PLAY_MOVIES
int PlayMovie(char* filename);
#endif // NOX_PLAY_MOVIES

//----- (004B0340) --------------------------------------------------------
int __cdecl sub_4B0340(int a1) // draw general
{
	BOOL v1;             // esi
	int v2;              // ebp
	int v3;              // edi
	int v4;              // ebx
	int result;          // eax
	int v7;              // [esp+10h] [ebp-44h]
	int v8;              // [esp+14h] [ebp-40h]
	int v9;              // [esp+18h] [ebp-3Ch]
	int v10;             // [esp+1Ch] [ebp-38h]
	int v11;             // [esp+20h] [ebp-34h]
	int v12;             // [esp+24h] [ebp-30h]

	dword_5d4594_1311936 = 1;
	*getMemU32Ptr(0x5D4594, 1311932) = a1;
#ifdef USE_SDL
	// FIXME
	v1 = 0;
#else
	v1 = (GetAsyncKeyState(VK_SHIFT) & 0x8000u) != 0;
#endif
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE) || v1 || nox_video_renderTargetFlags & 0x10)
		goto LABEL_23;
	sub_431290();
	sub_43DBD0();
	sub_44D8F0();
	while (sub_43DC40() || sub_44D930()) {
		sub_4312C0();
#ifdef __EMSCRIPTEN__
		nox_sleep(0x32u);
#endif
	}
	sub_43E8E0(0);
	v12 = sub_48B3E0(0);
	unacquireMouse_sub_47D8B0();
	sub_48A7F0();
	v2 = dword_5d4594_3801780;
	if (dword_5d4594_3801780) {
		v3 = a1;
		v4 = a1;
	LABEL_13:
#ifdef NOX_PLAY_MOVIES
#ifdef USE_SDL
#ifdef __linux__
		;
		if (nox_enable_audio) { // TODO: disable audio in movies instead
			char* path = dos_to_unix(getMemAt(0x5D4594, 1311940));
			PlayMovie(path);
			free(path);
		}
#else // __linux__
		PlayMovie(getMemAt(0x5D4594, 1311940));
#endif // __linux__
#else // USE_SDL
        unsigned __int8* v6; // esi
        int v13[11];         // [esp+28h] [ebp-2Ch]
		v13[1] = *getMemU32Ptr(0x5D4594, 823784);
		v13[0] = windowHandle_dword_973FE0;
		v13[4] = g_backbuffer1;
		v13[2] = g_ddraw;
		v13[5] = nox_pixbuffer_3798780;
		v13[6] = nox_pixbuffer_3798780;
		v13[3] = g_frontbuffer;
		v13[7] = nox_backbuffer_width;
		v13[8] = nox_backbuffer_height;
		v13[9] = 1;
		if (*getMemU32Ptr(0x5D4594, 1311928)) {
			v6 = getMemAt(0x5D4594, 1311940);
			do {
				v13[10] = (int)v6;
				v6 += 260;
				sub_555430((HWND*)v13);
				--*getMemU32Ptr(0x5D4594, 1311928);
			} while (*getMemU32Ptr(0x5D4594, 1311928));
		}
#endif // USE_SDL
#endif // NOX_PLAY_MOVIES
		;
		if (!v2) {
			nox_free_pixbuffers_486110();
			sub_48A120();
			nox_video_renderTargetFlags = v4;
			result = sub_48A040(v3, v8, v7, a1);
			if (!result)
				return result;
			result = sub_486090();
			if (!result)
				return result;
			result = sub_4338D0();
			if (!result)
				return result;
			result = nox_video_initCursorDrawVars_48B1F0();
			if (!result)
				return result;
			sub_48B3F0(v11, v10, v9);
		}
		sub_43E910(0);
		sub_43DBE0();
		acquireMouse_sub_47D8C0();
		sub_48B3E0(v12);
	LABEL_23:
		sub_4B05D0();
		return 1;
	}
	sub_48B590(&v11, &v10, &v9);
	v2 = dword_5d4594_3801780;
	v3 = windowHandle_dword_973FE0;
	v4 = nox_video_renderTargetFlags;
	v8 = nox_backbuffer_width;
	v7 = nox_backbuffer_height;
	a1 = nox_backbuffer_depth;
	nox_video_stopCursorDrawThread_48B350();
	sub_433C20();
	nox_free_pixbuffers_486110();
	sub_48A120();
	nox_video_renderTargetFlags = v4;
	result = sub_48A040(v3, NOX_DEFAULT_WIDTH, NOX_DEFAULT_HEIGHT, NOX_DEFAULT_DEPTH);
	if (result) {
		result = sub_486090();
		if (result)
			goto LABEL_13;
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
			sub_440900();
			func_5d4594_1311924();
		}
	}
}

//----- (004B0640) --------------------------------------------------------
int __cdecl sub_4B0640(int (*a1)(void)) {
	int result; // eax

	result = a1;
	func_5d4594_1311924 = a1;
	return result;
}

//----- (0048B5D0) --------------------------------------------------------
int __cdecl nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(int a1, int a2) {
	int result; // eax
	int v3;     // esi

	result = 0;
	if (!*getMemU32Ptr(0x5D4594, 1193708) && nox_video_drawCursorThreadOk && dword_5d4594_823776 &&
		nox_video_cursorDrawIsThreaded && dword_5d4594_1193672 && *getMemU32Ptr(0x5D4594, 1193108) &&
		dword_5d4594_787144) {
		*getMemU32Ptr(0x5D4594, 1193708) = 1;
		EnterCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
#ifdef USE_SDL
		// FIXME SDL will always wait for vblank?
#else
		if (a2)
			g_ddraw->lpVtbl->WaitForVerticalBlank(g_ddraw, 1, 0);
#endif
		v3 = nox_video_cursorThreadedDrawFnPtr(a1);
		LeaveCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
		result = v3;
		*getMemU32Ptr(0x5D4594, 1193708) = 0;
	}
	return result;
}

//----- (0048C200) --------------------------------------------------------
unsigned __int8* __cdecl sub_48C200(int a1, int a2, int a3) {
	unsigned __int8* result; // eax
	int v4;                  // ebp
	unsigned __int8* v5;     // eax
	int v6;                  // ecx
	int v7;                  // edi
	int v8;                  // edx
	int v9;                  // ebx
	int v10;                 // esi
	void (*v11)(void);       // edi
	int v12;                 // edi
	int v13;                 // ecx
	int v14;                 // ebx
	int v15;                 // edi
	int v16;                 // esi
	int v17;                 // ecx
	unsigned __int8* v18;    // eax
	int v19;                 // edx
	int v20;                 // ecx
	void (*v21)(void);       // [esp+14h] [ebp+4h]
	int v22;                 // [esp+18h] [ebp+8h]
	int v23;                 // [esp+1Ch] [ebp+Ch]

	result = (unsigned __int8*)(*(int(__cdecl**)(_DWORD)) & dword_5d4594_3799492)(a1);
	dword_5d4594_1193516 = result;
	if (result) {
		v4 = *(_DWORD*)result;
		v5 = result + 4;
		dword_5d4594_1193516 = v5;
		v6 = *(_DWORD*)v5;
		v5 += 4;
		dword_5d4594_1193516 = v5;
		v7 = *(_DWORD*)v5;
		v5 += 4;
		dword_5d4594_1193516 = v5;
		v8 = v7 + a2;
		v9 = *(_DWORD*)v5;
		result = v5 + 5;
		v10 = v9 + a3;
		dword_5d4594_1193568 = v4;
		dword_5d4594_1193576 = v6;
		dword_5d4594_1193516 = result;
		v11 = dword_6F7C34;
		if (!ptr_5D4594_3799572->data[15])
			v11 = dword_6F7C40;
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
				v16 = v23 + *(_DWORD*)(v14 + dword_5d4594_1193704 - 4);
				for (dword_5d4594_1193584 = v23 + *(_DWORD*)(v14 + dword_5d4594_1193704 - 4); v15 > 0; v15 -= v19) {
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
							result = *(unsigned __int8**)&dword_5d4594_1193516;
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
unsigned __int8* __cdecl sub_48C320(int a1, int a2, int a3) {
	unsigned __int8* result; // eax
	int v4;                  // edi
	unsigned __int8* v5;     // eax
	int v6;                  // ecx
	int v7;                  // esi
	int v8;                  // ebx
	int v9;                  // ebp
	void (*v10)(void);       // esi
	int v11;                 // esi
	int v12;                 // ecx
	int v13;                 // ebp
	int v14;                 // esi
	int v15;                 // ecx
	unsigned __int8* v16;    // eax
	int v17;                 // edx
	int v18;                 // ecx
	void (*v19)(void);       // [esp+14h] [ebp+4h]
	int v20;                 // [esp+18h] [ebp+8h]

	result = (unsigned __int8*)(*(int(__cdecl**)(_DWORD)) & dword_5d4594_3799492)(a1);
	dword_5d4594_1193516 = result;
	if (result) {
		v4 = *(_DWORD*)result;
		v5 = result + 4;
		dword_5d4594_1193516 = v5;
		v6 = *(_DWORD*)v5;
		v5 += 4;
		dword_5d4594_1193516 = v5;
		v7 = *(_DWORD*)v5;
		v5 += 4;
		dword_5d4594_1193516 = v5;
		v8 = v7 + a2;
		v9 = *(_DWORD*)v5;
		result = v5 + 5;
		dword_5d4594_1193568 = v4;
		dword_5d4594_1193576 = v6;
		dword_5d4594_1193516 = result;
		v10 = dword_6F7C34;
		if (!ptr_5D4594_3799572->data[15])
			v10 = dword_6F7C40;
		v19 = v10;
		v11 = v6;
		v12 = v6 - 1;
		if (v11) {
			v13 = 4 * (v9 + a3);
			v20 = v12 + 1;
			do {
				v13 += 4;
				v14 = v4;
				for (dword_5d4594_1193584 = v8 + *(_DWORD*)(dword_5d4594_1193704 + v13 - 4); v14 > 0; v14 -= v17) {
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
							result = *(unsigned __int8**)&dword_5d4594_1193516;
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
#endif
