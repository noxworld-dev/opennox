#define IGNORE_EXTERNS
#include "draw_common.h"
#undef IGNORE_EXTERNS

unsigned char byte_5D4594_3804364[160] = { 0 };

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
int (*func_5d4594_1311924)(void) = 0;

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
int (*nox_video_cursorThreadedDrawFnPtr)(int);
void (*dword_6F7C10)(_DWORD, _DWORD, _DWORD);
__int16 (*dword_6F7C40)();
__int16 (*dword_6F7C34)();
void (*dword_975240)(_DWORD, _DWORD*, _DWORD*, _DWORD*);
int (*dword_975380)(_DWORD, _DWORD, _DWORD);
void (*nox_color_rgb_func)(uint8_t, uint8_t, uint8_t, uint32_t*);
void (*g_copy_backbuffer_ptr)();

SDL_Surface* dword_6F7C48;
SDL_Surface* g_cursor_surf;
SDL_Surface* dword_973C60;
SDL_Surface* g_backbuffer1;
SDL_Surface* g_backbuffer2;
SDL_Surface* dword_973C88;
Uint32 g_format;

SDL_Window* windowHandle_dword_973FE0;

int g_rotate;
int g_rotated;

float draw_gamma = 1.0f;

unsigned int g_tex_coord_itemsize, g_tex_coord_numitems;

int nox_backbuffer_pitch32;
int nox_backbuffer_width32;


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
SDL_Surface* __cdecl nox_video_createSurface_48A600(int a1, int a2, int a3, int a4);
int __cdecl sub_48A720(SDL_Surface* a1, _DWORD* a2, _DWORD* a3, _DWORD* a4, int* a5);
void __cdecl sub_48A670(SDL_Surface* a1);
void __cdecl sub_48A6B0(SDL_Surface* a1);

SDL_Window* windowHandle_dword_973FE0;

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

	windowHandle_dword_973FE0 = (SDL_Window*)wnd;

	nox_backbuffer_width = w;
	nox_backbuffer_height = h;
	nox_backbuffer_depth = depth;
	nox_video_renderTargetFlags = flags;

	v5 = 5; // Fix for Linux
	nox_video_windowsPlatformVersion = v5;

	v6 = v5 == 5;
	if (v6) // if Windows NT platform
	{
		v7 = nox_video_renderTargetFlags | 0x20;
		nox_video_renderTargetFlags |= 0x120u;
	}
	v8 = w & 0xFFFFFFE0;
	if (!(v7 & 4)) {
		if (!sdl_render_start_threaded(wnd, v8, h, depth))
			return 0;
		dword_5d4594_3801804 = nox_xxx_testCPUID2_444D90();
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
		dword_5d4594_3801804 = nox_xxx_testCPUID2_444D90();
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
	dword_5d4594_3801804 = nox_xxx_testCPUID2_444D90();
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

	display_id = SDL_GetWindowDisplayIndex(getWindowHandle_nox_xxx_getHWND_401FD0());

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
	SDL_SetWindowSize(getWindowHandle_nox_xxx_getHWND_401FD0(), size.field_0, size.field_4);
	SDL_SetWindowPosition(getWindowHandle_nox_xxx_getHWND_401FD0(), position.field_0, position.field_4);
}

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
		SDL_SetWindowResizable(getWindowHandle_nox_xxx_getHWND_401FD0(), SDL_FALSE);
		SDL_SetWindowBordered(getWindowHandle_nox_xxx_getHWND_401FD0(), SDL_FALSE);
		sdl_set_window_rect(fullscreenSize, fullscreenPosition);
		SDL_SetWindowFullscreen(getWindowHandle_nox_xxx_getHWND_401FD0(), SDL_WINDOW_FULLSCREEN_DESKTOP);
		break;
	case -2:
	case 2:
		// Borderless fullscreen
		SDL_SetWindowFullscreen(getWindowHandle_nox_xxx_getHWND_401FD0(), 0);
		SDL_SetWindowResizable(getWindowHandle_nox_xxx_getHWND_401FD0(), SDL_FALSE);
		SDL_SetWindowBordered(getWindowHandle_nox_xxx_getHWND_401FD0(), SDL_TRUE);
		sdl_set_window_rect(fullscreenSize, fullscreenPosition);
		break;
	default:
		// Windowed
		SDL_SetWindowFullscreen(getWindowHandle_nox_xxx_getHWND_401FD0(), 0);
		SDL_SetWindowResizable(getWindowHandle_nox_xxx_getHWND_401FD0(), SDL_TRUE);
		SDL_SetWindowBordered(getWindowHandle_nox_xxx_getHWND_401FD0(), SDL_TRUE);
		sdl_set_window_rect(windowedSize, windowedPosition);
		break;
	}
}


//----- (0048A190) --------------------------------------------------------
char sub_48A190() {
	int v0; // eax

	g_present_ptr = sdl_present;

	dword_6F7B9C = 1;
	nox_backbuffer1_pix = g_backbuffer1->pixels;
	nox_backbuffer_pix = nox_backbuffer1_pix;
	return v0;
}

//----- (0048A220) --------------------------------------------------------
void __cdecl nox_xxx_directDrawBlitMB_48A220() {

}

void __cdecl sub_48A670(SDL_Surface* a1) { SDL_LockSurface(a1); }

void __cdecl sub_48A6B0(SDL_Surface* a1) { SDL_UnlockSurface(a1); }

//----- (0048A7F0) --------------------------------------------------------
void sub_48A7F0() {
    //SDL_SetRenderDrawColor(g_ddraw, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //SDL_RenderClear(g_ddraw);
    //SDL_RenderPresent(g_ddraw);
}

//----- (0048A820) --------------------------------------------------------
void __cdecl sub_48A820(UINT uFlags) {
	//DWORD width = nox_backbuffer_width;
	//DWORD height = nox_backbuffer_height;

	// SDL_SetWindowSize(windowHandle_dword_973FE0, width, height);
	// SDL_SetWindowGrab(windowHandle_dword_973FE0, SDL_TRUE);
}

//----- (0048A9C0) --------------------------------------------------------
void __cdecl sub_48A9C0(int a1) {
	if (dword_6F7BB0) {
		EnterCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
		if (!dword_974854) {
			if (nox_video_renderTargetFlags & 0x10) {
				dword_974854 = 1;
				printf("Ungrab\n");
				SDL_SetWindowGrab(windowHandle_dword_973FE0, SDL_FALSE);
				LeaveCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
				return;
			}
			if (a1) {
				dword_974854 = 1;
				dword_973C70 = 1;
				printf("Minimize\n");
				SDL_MinimizeWindow(windowHandle_dword_973FE0);
			}
		}
		LeaveCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
	}
}

//----- (0048AA40) --------------------------------------------------------
void sub_48AA40() {
	// FIXME
}

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
	nox_video_cursorThreadedDrawFnPtr = sdl_drawCursorThreaded;
	result = nox_video_createCursorSurface_48BF70();
	printf("%s: %d\n", __FUNCTION__, result);
	if (result) {
		result = sub_48C060();
		printf("%s: %d\n", __FUNCTION__, result);
		if (result) {
			result = nox_xxx_makeFillerColor_48BDE0();
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
		nox_xxx_utilRect_49F930((int4*)&v4, r1, (int4*)(&obj_5D4594_3800716.data[9]))) {
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

	if (nox_xxx_utilRect_49F930((int4*)&v4, r1, (int4*)(&obj_5D4594_3800716.data[9]))) {
		r3->left = v4.left - r1->left;
		r3->top = v4.top - r1->top;
		r3->right = v4.right - r1->left;
		r3->bottom = v4.bottom - r1->top;

		// FIXME frontbuffer?
		rect_to_sdl(r3, &src);
		rect_to_sdl(&v4, &dst);

		if (SDL_BlitScaled(g_cursor_surf, &src, g_backbuffer1, &dst))
			return 0;

		*r1 = v4;
	}

	dword_5d4594_1193664 = 0;
	dword_5d4594_1193668 = 0;
	return 1;
}

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
void __cdecl sub_4352E0() {
	// FIXME gamma control
}

//----- (00444F90) --------------------------------------------------------
HDC sub_444F90() {
	DebugBreak();
	return 0;
}

//----- (00444FC0) --------------------------------------------------------
void __cdecl sub_444FC0(HDC a1) {
	DebugBreak();
}

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
void sub_433C20() {
	sub_48A7F0();

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
int __cdecl nox_xxx_GfxInit_444930(HWND wnd, int w, int h, int depth, int flags) {
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
		SDL_MinimizeWindow(windowHandle_dword_973FE0);
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
		nox_client_CleanupRender_48A120();
		sub_44D9D0();
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
	*getMemU32Ptr(0x5D4594, 1193684) = nox_backbuffer_width;
	*getMemU32Ptr(0x5D4594, 1193688) = nox_backbuffer_height;
}

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
}

//----- (004AD1E0) --------------------------------------------------------
void sub_4AD1E0() {
	int result; // eax
	_WORD* v1;  // edi
	_WORD* v4;  // esi

	if (dword_973C70) {
		return;
	}
	result = SDL_LockSurface(g_backbuffer1);
	v1 = g_backbuffer1->pixels;

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
	SDL_UnlockSurface(g_backbuffer1);
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

//----- (0048BF70) --------------------------------------------------------
int nox_video_createCursorSurface_48BF70() {
	int result; // eax
	int v1;     // [esp+0h] [ebp-18h]
	int v2;     // [esp+4h] [ebp-14h]
	int4 a1;    // [esp+8h] [ebp-10h]

	g_cursor_surf =
		nox_video_createSurface_48A600(128, 128, DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT, DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY);
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
				nox_video_createSurface_48A600(a1.field_8, a1.field_C, DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT, DDSCAPS_VIDEOMEMORY);
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
BOOL nox_xxx_makeFillerColor_48BDE0() {
	int v0; // eax

	v0 = nox_color_rgb_4344A0(255, 0, 255);
	*getMemU32Ptr(0x5D4594, 1193592) = v0;
	if (g_cursor_surf) {
		// FIXME use SDL_MapRGB instead?
		v0 = dword_5d4594_3799624 ? (unsigned __int16)v0 : (unsigned __int8)v0;
		SDL_SetColorKey(g_cursor_surf, SDL_TRUE, v0);
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

	sub_48B1D0_free_surface(&g_cursor_surf);
	sub_48B1D0_free_surface(&dword_6F7C48);

	if (dword_5d4594_1193704) {
		free(*(LPVOID*)&dword_5d4594_1193704);
		dword_5d4594_1193704 = 0;
	}
	dword_5d4594_1193624 = 0;
}

//----- (004338D0) --------------------------------------------------------
int sub_4338D0() {
	int result;          // eax
	pixel888 v2[256];    // [esp+Ch] [ebp-300h]

	switch (dword_5d4594_3799624) {
	case 0:
		nox_color_rgb_func = nox_color_func_435180;
		dword_975240 = sub_435240;
		dword_975380 = sub_434E80;
		memcpy(byte_5D4594_3804364, byte_581450_9176, sizeof(byte_581450_9176));
		break;
	case 1:
		nox_color_rgb_func = nox_color_func_4351C0;
		dword_975240 = sub_435280;
		dword_975380 = sub_434E80;
		memcpy(byte_5D4594_3804364, byte_581450_9176, sizeof(byte_581450_9176));
		break;
	case 2:
		nox_color_rgb_func = nox_color_func_435200;
		dword_975240 = sub_435280;
		dword_975380 = sub_434EC0;
		memcpy(byte_5D4594_3804364, byte_581450_9336, sizeof(byte_581450_9336));
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
				// TODO gamma control
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
	return nox_xxx_drawMakeRGB_433F10(v3, v2, a1);
}

//----- (004341D0) --------------------------------------------------------
int __cdecl nox_xxx_drawPlayer_4341D0(int a1, int a2) {
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
	// FIXME gamma control
	return 0;
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
		// FIXME SDL will always wait for vblank?
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

//----- (0048A290) --------------------------------------------------------
void sub_48A290_call_present() {
	g_present_ptr();
	++g_present_ticks;
}

extern int nox_enable_threads;

#define THREAD_ERROR (unsigned int)(-1)

unsigned int renderCommand = 0;
void (*renderExec)() = NULL;
SDL_mutex* renderLock = NULL;
SDL_cond* renderReady = NULL;
bool renderNotified = false;

bool renderThreadStarted = false;

SDL_mutex* renderExitLock = NULL;
SDL_cond* renderExitCond = NULL;

typedef struct render_thread_data
{
	HWND wnd;
	int width;
	int height;
	int depth;
	int result;
	SDL_cond* startupWait;
	SDL_mutex* startupLock;
} render_thread_data;

int sdl_render_start_threaded(HWND wnd, int width, int height, int depth)
{
#ifndef __EMSCRIPTEN__
	if (nox_enable_threads)
	{
		//sdl_render_notify_thread(RENDER_THREAD_EXIT, NULL);

		render_thread_data data;
		memset(&data, 0, sizeof(render_thread_data));
		SDL_mutex *startupLock = SDL_CreateMutex();
		SDL_cond *startupWait = SDL_CreateCond();
		renderLock = SDL_CreateMutex();
		renderReady = SDL_CreateCond();

		data.wnd = wnd;
		data.width = width;
		data.height = height;
		data.depth = depth;
		data.startupWait = startupWait;
		data.startupLock = startupLock;

		sdl_render_threaded_specific(false);
		SDL_LockMutex(startupLock);
		unsigned int thread = _beginthread(sdl_render_threaded, NULL, &data);
		if (thread == 0 || thread == THREAD_ERROR)
		{
			nox_enable_threads = 0;
			SDL_UnlockMutex(startupLock);
			SDL_DestroyMutex(startupLock);
			SDL_DestroyCond(startupWait);
			SDL_DestroyMutex(renderLock);
			SDL_DestroyCond(renderReady);
			renderLock = 0;
			renderReady = 0;
			return nox_client_initRender_48A040(wnd, width, height, depth);
		}
		while (!renderThreadStarted)
		{
			SDL_CondWait(startupWait, startupLock);
		}
		SDL_UnlockMutex(startupLock);
		SDL_DestroyMutex(startupLock);
		SDL_DestroyCond(startupWait);
		return data.result;
	}
	else
	{
#endif
		return nox_client_initRender_48A040(wnd, width, height, depth);
#ifndef __EMSCRIPTEN__
	}
#endif
}

#ifndef __EMSCRIPTEN__
void sdl_render_notify_thread(unsigned int cmd, void (*exec)())
{
	if (!nox_enable_threads)
	{
		return;
	}
	SDL_LockMutex(renderLock);
	renderCommand = cmd;
	renderExec = NULL;
	switch (cmd)
	{
	case RENDER_THREAD_RENDER:
		sub_4AD170_call_copy_backbuffer();
		break;
	case RENDER_THREAD_EXEC:
		renderExec = exec;
		break;
	case RENDER_THREAD_EXIT:
		renderExitLock = SDL_CreateMutex();
		renderExitCond = SDL_CreateCond();
		SDL_LockMutex(renderExitLock);
		break;
	default:
		DebugBreak();
	}
	renderNotified = true;
	SDL_CondSignal(renderReady);
	SDL_UnlockMutex(renderLock);
	if (cmd == RENDER_THREAD_EXIT)
	{
		while (renderThreadStarted)
		{
			SDL_CondWait(renderExitCond, renderExitLock);
		}
		SDL_UnlockMutex(renderExitLock);
		SDL_DestroyMutex(renderExitLock);
		SDL_DestroyCond(renderExitCond);
	}
}

void __cdecl sdl_render_threaded(void* d)
{
	printf("Render thread created!\n");
	render_thread_data* data = d;
	data->result = nox_client_initRender_48A040(data->wnd, data->width, data->height, data->depth);
	SDL_LockMutex(data->startupLock);
	renderThreadStarted = true;
	renderNotified = false;
	SDL_CondSignal(data->startupWait);
	SDL_UnlockMutex(data->startupLock);
	while (true)
	{
		void (*exec)() = NULL;
		unsigned int cmd = 0;
		SDL_mutex* lRenderLock = renderLock;
		SDL_cond* lRenderReady = renderReady;
		SDL_LockMutex(lRenderLock);
		while (!renderNotified)
		{
			SDL_CondWait(lRenderReady, lRenderLock);
		}
		cmd = renderCommand;
		exec = renderExec;
		if (cmd == RENDER_THREAD_RENDER)
		{
			sdl_render_threaded_get_backbuffer();
		}
		renderNotified = false;
		SDL_UnlockMutex(lRenderLock);
		switch (cmd)
		{
		case RENDER_THREAD_RENDER:
			sub_48A290_call_present();
			break;
		case RENDER_THREAD_EXEC:
			exec();
			break;
		case RENDER_THREAD_EXIT:
			sdl_render_threaded_specific(true);
			SDL_DestroyCond(lRenderReady);
			SDL_DestroyMutex(lRenderLock);

			renderThreadStarted = false;
			SDL_CondSignal(renderExitCond);

			SDL_UnlockMutex(renderExitLock);
			printf("Render thread exited!\n");
			return;
		default:
			DebugBreak();
		}
	}
}
#endif

SDL_Surface* sdl_render_threaded_get_backbuffer()
{
	SDL_Surface* backbuffer_copy = NULL;
	if (g_backbuffer1 != NULL)
	{
		if (g_backbuffer2 != NULL)
		{
			backbuffer_copy = g_backbuffer2;
		}
		else
		{
			backbuffer_copy = SDL_CreateRGBSurfaceWithFormat(0, g_backbuffer1->w, g_backbuffer1->h, g_backbuffer1->format->BitsPerPixel, g_backbuffer1->format->format);
		}
		//char* error = SDL_GetError();
		SDL_SetSurfaceBlendMode(backbuffer_copy, SDL_BLENDMODE_NONE);
		SDL_SetSurfaceBlendMode(g_backbuffer1, SDL_BLENDMODE_NONE);
		SDL_BlitSurface(g_backbuffer1, NULL, backbuffer_copy, NULL);
		g_backbuffer2 = backbuffer_copy;
	}
	return backbuffer_copy;
}
