//+build none

// This code is kept only for the reference. Please DO NOT REMOVE it and try to refactor if you touch any of the
// variables used here.
#ifdef USE_DDRAW

#include "legacy/client__video__ddraw__draw_ddraw.h"
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
#include "cdrom.h"
#include "client__draw__fx.h"
#include "client__draw__image.h"
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
#include "common__config.h"
#include "common__magic__speltree.h"
#include "defs.h"
#include "input.h"
#include "input_common.h"
#include "legacy/input_ddraw.h"
#include "legacy/mmx.h"
#include "legacy/win_ddraw.h"
#include "movie.h"
#include "server__network__mapsend.h"
#include "server__script__builtin.h"
#include "server__script__script.h"
#include "server__xfer__savegame__savegame.h"
#include "thing.h"
#include "win.h"

unsigned char byte_5D4594_3804364[160] = {0};

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

void sub_435380(LPDIRECTDRAWGAMMACONTROL* a1);
void sub_4353A0(LPDIRECTDRAWPALETTE* a1);
LPDIRECTDRAWSURFACE sub_48A600(int a1, int a2, int a3, int a4);
void sub_48A670(LPDIRECTDRAWSURFACE a1);
void sub_48A6B0(LPDIRECTDRAWSURFACE a1);
LPVOID sub_48A6C0(LPDIRECTDRAWSURFACE a1);
int sub_48A720(LPDIRECTDRAWSURFACE a1, _DWORD* a2, _DWORD* a3, _DWORD* a4, int* a5);
void sub_48A7B0(LPDIRECTDRAWSURFACE a1);
int __stdcall sub_48AE80(LPDIRECTDRAWSURFACE a1, LPDDSURFACEDESC a2, LPVOID a3);
BOOL __stdcall Callback(GUID*, LPSTR, LPSTR, LPVOID); // idb
int sub_48B140(LPDIRECTDRAW a1, const IID* a2, int* a3);
void sub_48B190(LPDIRECTDRAWCLIPPER* a1);
void sub_48B1B0(LPDIRECTDRAW* a1);
void sub_48B1D0(LPDIRECTDRAWSURFACE* a1);
int sub_48AD40(HWND a1, int a2, int a3, int a4);
int nox_xxx_initWindowed1_48AED0(HWND a1, int a2, int a3);

HWND windowHandle_dword_973FE0;

int nox_backbuffer_pitch32;
int nox_backbuffer_width32;
DWORD dword_973C64;

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
int sub_48A040(HWND a1, int a2, int a3, int a4) {
	int result; // eax

	g_backbuffer_count = 2;
	dword_6F7BB0 = 0;
	g_ddraw = 0;
	g_frontbuffer = 0;
	g_backbuffer1 = 0;
	g_clipper = 0;
	dword_973C88 = 0;
	dword_973C60 = 0;
	dword_973C70 = 0;
	g_present_ticks = 0;
	dword_974854 = 0;
	dword_6F7B9C = 1;
	dword_5ACFAC = 1;
	if (!(nox_video_renderTargetFlags & 4)) {
		sub_48AA40();
		result = nox_xxx_initDDraw_48B000();
		if (!result)
			return result;
		if (nox_video_renderTargetFlags & 0x10) {
			// windowed mode
			result = nox_xxx_initWindowed1_48AED0(a1, a2, a3);
			if (!result)
				return result;
		} else {
			// fullscreen mode
			result = sub_48AD40(a1, a2, a3, a4);
			if (!result)
				return result;
		}
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
	if (g_ddraw)
		g_ddraw->lpVtbl->RestoreDisplayMode(g_ddraw);
	sub_48B190(&g_clipper);
	sub_48B1D0(&g_frontbuffer);
	sub_48B1D0_free_surface(&dword_973C60);
	sub_48B1D0_free_surface(&dword_973C88);
	if (g_backbuffer1 != g_frontbuffer1) {
		sub_48B1D0_free_surface(&g_frontbuffer1);
	} else {
		g_frontbuffer1 = 0;
	}
	sub_48B1D0_free_surface(&g_backbuffer1);
	sub_48B1B0(&g_ddraw);
	sub_48A9C0(0);
	sub_48AA40();
}

//----- (0048A190) --------------------------------------------------------
char sub_48A190() {
	int v0; // eax

	if (*getMemU32Ptr(0x5D4594, 3801796) && nox_video_renderTargetFlags & 0x20 && (v0 = sub_48ACC0()) != 0) {
		g_present_ptr = sub_48AB50;
	} else {
		v0 = *(_DWORD*)&nox_video_renderTargetFlags;
		g_present_ptr = sub_48AAF0;
		LOBYTE(v0) = nox_video_renderTargetFlags & 0xDF;
		*(_DWORD*)&nox_video_renderTargetFlags = v0;
	}
	return v0;
}

//----- (0048A220) --------------------------------------------------------
void nox_xxx_directDrawBlitMB_48A220() {
	HRESULT i; // eax

	if (g_ddraw && !dword_974854 && dword_973C64 && (!dword_973C70 || nox_xxx_directDrawBlitImpl_48A2A0())) {
		for (i = g_frontbuffer->lpVtbl->GetFlipStatus(g_frontbuffer, 2); i;
			 i = g_frontbuffer->lpVtbl->GetFlipStatus(g_frontbuffer, 2)) {
			if (i == DDERR_SURFACELOST) {
				if (!nox_xxx_directDrawBlitImpl_48A2A0())
					return;
			} else if (i == DDERR_SURFACEBUSY) {
				return;
			}
		}
	}
}

//----- (0048A290) --------------------------------------------------------
void sub_48A290_call_present() {
	g_present_ptr();
	++g_present_ticks;
}

//----- (0048A2A0) --------------------------------------------------------
int nox_xxx_directDrawBlitImpl_48A2A0() {
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
LPDIRECTDRAWSURFACE sub_48A600(int a1, int a2, int a3, int a4) {
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
void sub_48A670(LPDIRECTDRAWSURFACE a1) {
	DDSURFACEDESC v3; // [esp+4h] [ebp-6Ch]

	memset(&v3, 0, sizeof(v3));
	v3.dwSize = sizeof(v3);
	a1->lpVtbl->Lock(a1, 0, &v3, DDLOCK_WAIT | DDLOCK_WRITEONLY | DDLOCK_NOSYSLOCK, 0);
}

//----- (0048A6B0) --------------------------------------------------------
void sub_48A6B0(LPDIRECTDRAWSURFACE a1) { a1->lpVtbl->Unlock(a1, 0); }

//----- (0048A6C0) --------------------------------------------------------
LPVOID sub_48A6C0(LPDIRECTDRAWSURFACE a1) {
	DDSURFACEDESC v3; // [esp+8h] [ebp-6Ch]

	memset(&v3, 0, sizeof(v3));
	v3.dwSize = 108;
	if (a1->lpVtbl->Lock(a1, 0, &v3, DDLOCK_WAIT, 0))
		return 0;
	a1->lpVtbl->Unlock(a1, v3.lpSurface);
	return v3.lpSurface;
}

//----- (0048A720) --------------------------------------------------------
int sub_48A720(LPDIRECTDRAWSURFACE a1, _DWORD* a2, _DWORD* a3, _DWORD* a4, int* a5) {
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
void sub_48A7B0(LPDIRECTDRAWSURFACE a1) {
	DDBLTFX v2; // [esp+0h] [ebp-64h]

	if (a1) {
		v2.dwSize = 100;
		v2.dwFillColor = 0;
		a1->lpVtbl->Blt(a1, 0, 0, 0, DDBLT_COLORFILL | DDBLT_WAIT, &v2);
	}
}

//----- (0048A7F0) --------------------------------------------------------
void sub_48A7F0() {
	sub_48A7B0(g_frontbuffer);
	sub_48A7B0(g_backbuffer1);
	sub_48A7B0(g_backbuffer2);
}

//----- (0048A820) --------------------------------------------------------
void sub_48A820(UINT uFlags) {
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
}

//----- (0048A9C0) --------------------------------------------------------
void sub_48A9C0(int a1) {
	if (dword_6F7BB0) {
		nox_mutex_lock(getMemAt(0x5D4594, 3799596));
		if (!dword_974854) {
			if (nox_video_renderTargetFlags & 0x10) {
				dword_974854 = 1;
				ClipCursor(0);
				nox_mutex_unlock(getMemAt(0x5D4594, 3799596));
				return;
			}
			if (a1) {
				dword_974854 = 1;
				dword_973C70 = 1;
				ShowWindow(windowHandle_dword_973FE0, SW_MINIMIZE);
			}
		}
		nox_mutex_unlock(getMemAt(0x5D4594, 3799596);
	}
}

//----- (0048AA40) --------------------------------------------------------
void sub_48AA40() {
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
}

//----- (0048AAF0) --------------------------------------------------------
void sub_48AAF0() {
	if (g_ddraw && !dword_974854 &&
		(!g_frontbuffer->lpVtbl->IsLost(g_frontbuffer) || nox_xxx_directDrawBlitImpl_48A2A0())) {
		sub_48BE50(1);
		sub_48B5D0(0, 0);
		g_frontbuffer->lpVtbl->Flip(g_frontbuffer, 0, DDFLIP_WAIT);
		sub_48BE50(0);
	}
}

//----- (0048AB50) --------------------------------------------------------
void sub_48AB50() {
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
void sub_48ABC0() {
	POINT Point;     // [esp+4h] [ebp-28h]
	RECT rectClient; // [esp+Ch] [ebp-20h]
	RECT rc;         // [esp+1Ch] [ebp-10h]

	if (!dword_974854 && g_ddraw &&
		(!g_frontbuffer->lpVtbl->IsLost(g_frontbuffer) || nox_xxx_directDrawBlitImpl_48A2A0())) {
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

//----- (0048AD40) --------------------------------------------------------
signed int sub_48AD40(HWND a1, int a2, int a3, int a4) {
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
int nox_xxx_initWindowed1_48AED0(HWND a1, int a2, int a3) {
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
				nox_xxx_msgError_48C940("8 bit color windowed mode requires you switch your desktop to 256 colors");
				return 0;
			}
		} else if (nox_backbuffer_depth == 16 && v5 != 16) {
			nox_xxx_msgError_48C940(
				"16 bit color windowed mode requires you switch your desktop to High Color (65536 colors)");
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

//----- (0048B000) --------------------------------------------------------
int nox_xxx_initDDraw_48B000() {
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
		nox_xxx_msgError_48C940("You do not have the correct version of DirectX!");
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
int sub_48B140(LPDIRECTDRAW a1, const IID* a2, int* a3) {
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

//----- (0048B190) --------------------------------------------------------
void sub_48B190(LPDIRECTDRAWCLIPPER* a1) {
	if (*a1) {
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}

//----- (0048B1B0) --------------------------------------------------------
void sub_48B1B0(LPDIRECTDRAW* a1) {
	if (*a1) {
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}

//----- (0048B1D0) --------------------------------------------------------
void sub_48B1D0(LPDIRECTDRAWSURFACE* a1) {
	if (*a1) {
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
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
	if (nox_video_renderTargetFlags & 0x10)
		// windowed mode
		dword_6F7BF0 = sub_48BA50;
	else
		// fullscreen mode
		dword_6F7BF0 = sub_48B840;
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

#if 0
//----- (0048B840) --------------------------------------------------------
int  sub_48B840(int a1)
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
    *getMemU32Ptr(0x5D4594, 1193532 + 8) = *(_DWORD*)& dword_5d4594_1193648
        - *getMemU32Ptr(0x5D4594, 1193580)
        + *getMemU32Ptr(0x5D4594, 1193600);
    *getMemU32Ptr(0x5D4594, 1193532 + 4) = *(_DWORD*)& dword_5d4594_1193524 - *getMemU32Ptr(0x5D4594, 1193636);
    *getMemU32Ptr(0x5D4594, 1193532 + 12) = *(_DWORD*)& dword_5d4594_1193524
        - *getMemU32Ptr(0x5D4594, 1193636)
        + *getMemU32Ptr(0x5D4594, 1193620);
    if ((!a1 || *(_DWORD*)& dword_5d4594_1193668 || *(_DWORD*)& dword_5d4594_1193664)
        && nox_xxx_utilRect_49F930((int4*)& v4, (int4*)getMemAt(0x5D4594, 1193532),(int4*)(&obj_5D4594_3800716.data[9])))
    {
        *getMemU32Ptr(0x5D4594, 1193548 + 8) = v4.right - v4.left;
        v1 = g_frontbuffer;
        *getMemU32Ptr(0x5D4594, 1193548) = 0;
        *getMemU32Ptr(0x5D4594, 1193548 + 4) = 0;
        *getMemU32Ptr(0x5D4594, 1193548 + 12) = v4.bottom - v4.top;
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
    if (nox_xxx_utilRect_49F930((int4*)& v4, (int4*)getMemAt(0x5D4594, 1193532), (int4*)(&obj_5D4594_3800716.data[9])))
    {
        *getMemU32Ptr(0x5D4594, 1193604) = v4.left - *getMemU32Ptr(0x5D4594, 1193532);
        *getMemU32Ptr(0x5D4594, 1193604 + 4) = v4.top - *getMemU32Ptr(0x5D4594, 1193532 + 4);
        *getMemU32Ptr(0x5D4594, 1193604 + 8) = v4.right - *getMemU32Ptr(0x5D4594, 1193532);
        v3 = g_frontbuffer;
        *getMemU32Ptr(0x5D4594, 1193604 + 12) = v4.bottom - *getMemU32Ptr(0x5D4594, 1193532 + 4);
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
int  sub_48BA50(int a1)
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
    *getMemU32Ptr(0x5D4594, 1193532 + 8) = *(_DWORD*)& dword_5d4594_1193648
        - *getMemU32Ptr(0x5D4594, 1193580)
        + *getMemU32Ptr(0x5D4594, 1193600);
    *getMemU32Ptr(0x5D4594, 1193532 + 4) = *(_DWORD*)& dword_5d4594_1193524 - *getMemU32Ptr(0x5D4594, 1193636);
    *getMemU32Ptr(0x5D4594, 1193532 + 12) = *(_DWORD*)& dword_5d4594_1193524
        - *getMemU32Ptr(0x5D4594, 1193636)
        + *getMemU32Ptr(0x5D4594, 1193620);
    if ((!a1 || *(_DWORD*)& dword_5d4594_1193668 || *(_DWORD*)& dword_5d4594_1193664)
        && nox_xxx_utilRect_49F930((int4*)& v4, (int4*)getMemAt(0x5D4594, 1193532), (int4*)(&obj_5D4594_3800716.data[9])))
    {
        *getMemU32Ptr(0x5D4594, 1193548 + 8) = v4.right - v4.left;
        *getMemU32Ptr(0x5D4594, 1193548) = 0;
        *getMemU32Ptr(0x5D4594, 1193548 + 4) = 0;
        *getMemU32Ptr(0x5D4594, 1193548 + 12) = v4.bottom - v4.top;
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
    if (nox_xxx_utilRect_49F930((int4*)& v4, (int4*)getMemAt(0x5D4594, 1193532), (int4*)(&obj_5D4594_3800716.data[9])))
    {
        *getMemU32Ptr(0x5D4594, 1193604) = v4.left - *getMemU32Ptr(0x5D4594, 1193532);
        *getMemU32Ptr(0x5D4594, 1193604 + 4) = v4.top - *getMemU32Ptr(0x5D4594, 1193532 + 4);
        *getMemU32Ptr(0x5D4594, 1193604 + 8) = v4.right - *getMemU32Ptr(0x5D4594, 1193532);
        *getMemU32Ptr(0x5D4594, 1193604 + 12) = v4.bottom - *getMemU32Ptr(0x5D4594, 1193532 + 4);
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

//----- (004348C0) --------------------------------------------------------
int sub_4348C0() {
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
}

//----- (00434FB0) --------------------------------------------------------
int sub_434FB0() {
	PALETTEENTRY v1[256]; // [esp+0h] [ebp-400h]

	g_ddraw_palette = 0;
	if (nox_video_renderTargetFlags & 4 || nox_video_pixmode_3799624)
		return 1;

	sub_4350E0(v1, getMemAt(0x5D4594, 3803308));
	if (g_ddraw->lpVtbl->CreatePalette(g_ddraw, 68, v1, &g_ddraw_palette, 0))
		return 0;
	if (g_frontbuffer->lpVtbl->SetPalette(g_frontbuffer, g_ddraw_palette))
		return 0;
	return 1;
}

//----- (004352E0) --------------------------------------------------------
void sub_4352E0() {
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
void sub_444FC0(HDC a1) {
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
	HDC v0; // esi

	v0 = GetDC(0);
	GetSystemPaletteEntries(v0, 0, 0x100u, (LPPALETTEENTRY)getMemAt(0x587000, 84412));
	return ReleaseDC(0, v0);
}

//----- (004353F0) --------------------------------------------------------
void sub_4353F0() {
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
	if (!nox_video_pixmode_3799624 && nox_video_renderTargetFlags & 0x10) {
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
}

//----- (004354F0) --------------------------------------------------------
void sub_4354F0() {
	HDC v1; // esi

	if (!nox_video_pixmode_3799624 && nox_video_renderTargetFlags & 0x10) {
		if (*getMemU32Ptr(0x5D4594, 809596)) {
			v1 = GetDC(windowHandle_dword_973FE0);
			SelectPalette(v1, *(HPALETTE*)getMemAt(0x5D4594, 809596), 0);
			RealizePalette(v1);
			ReleaseDC(windowHandle_dword_973FE0, v1);
		}
	}
}

//----- (00435550) --------------------------------------------------------
void sub_435550() {
	if (*getMemU32Ptr(0x5D4594, 809596)) {
		DeleteObject(*(HGDIOBJ*)getMemAt(0x5D4594, 809596));
		*getMemU32Ptr(0x5D4594, 809596) = 0;
	}
}

//----- (00433C20) --------------------------------------------------------
void nox_draw_freeColorTables_433C20() {
	sub_48A7F0();
	sub_435380(&g_ddraw_gamma_control);
	sub_4353A0(&g_ddraw_palette);
	if (dword_5d4594_810640) {
		free(*(LPVOID*)&dword_5d4594_810640);
		dword_5d4594_810640 = 0;
	}
	if (nox_draw_colorTablesRev_3804668) {
		free(*(LPVOID*)&nox_draw_colorTablesRev_3804668);
		nox_draw_colorTablesRev_3804668 = 0;
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
int nox_xxx_GfxInit_444930(HWND wnd, int w, int h, int depth, int flags) {
	dword_5d4594_823776 = 0;
	nox_draw_curDrawData_3799572 = &obj_5D4594_3799660;
	int result = nox_client_drawInitAll_4449D0(wnd, w, h, depth, flags);
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result) {
		return 0;
	}
	nox_draw_curDrawData_3799572 = &obj_5D4594_3800716;
	memcpy(&obj_5D4594_3800716, &obj_5D4594_3799660, sizeof(obj_5D4594_3799572_t));
	if (nox_video_renderTargetFlags & 0x200) {
		ShowWindow(windowHandle_dword_973FE0, SW_MINIMIZE);
		PostMessageA(windowHandle_dword_973FE0, WM_ACTIVATEAPP, 0, 0);
	}
	result = 1;
	dword_5d4594_823776 = 1;
	++dword_5d4594_823772;
	return 1;
}

//----- (0048C110) --------------------------------------------------------
void sub_48C110() {
	RECT Rect; // [esp+0h] [ebp-10h]
	if (nox_video_renderTargetFlags & 0x10) {
		GetClientRect(windowHandle_dword_973FE0, &Rect);
		*getMemU32Ptr(0x5D4594, 1193684) = Rect.right - Rect.left;
		*getMemU32Ptr(0x5D4594, 1193688) = Rect.bottom - Rect.top;
	} else {
		*getMemU32Ptr(0x5D4594, 1193684) = nox_backbuffer_width;
		*getMemU32Ptr(0x5D4594, 1193688) = nox_backbuffer_height;
	}
}

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
	DDSURFACEDESC v11; // [esp+Ch] [ebp-70h]
	v11.dwSize = sizeof(v11);
	v11.dwFlags = 0;
	result = g_backbuffer1->lpVtbl->Lock(g_backbuffer1, 0, &v11, 1, 0);
	v1 = v11.lpSurface;
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
	g_backbuffer1->lpVtbl->Unlock(g_backbuffer1, v11.lpSurface);
	++*getMemU32Ptr(0x5D4594, 3798652);
}

//----- (00486090) --------------------------------------------------------
int nox_video_initPixbuffer_486090() {
	int result; // eax

	result = nox_video_initPixbufferData_4861D0();
	if (result) {
		result = nox_video_initPixbufferRows_486230();
		if (result) {
			if (!(nox_video_renderTargetFlags & 0x40) || (result = sub_48A5D0(), (dword_973C88 = result) != 0) &&
															 (result = sub_48A5D0(), (dword_973C60 = result) != 0)) {
				result = 1;
			}
		}
	}
	return result;
}

//----- (0048A3D0) --------------------------------------------------------
int sub_48A3D0() {
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

	nox_video_modeXxx_3801780 = 2;
	*getMemU32Ptr(0x5D4594, 3801796) = 0;
	if (g_backbuffer1) {
		if (g_backbuffer1->lpVtbl->IsLost(g_backbuffer1)) {
			result = nox_xxx_directDrawBlitImpl_48A2A0();
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
				nox_video_modeXxx_3801780 = 1;
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
						nox_video_pixmode_3799624 = 1;
					return 1;
				}
				if (i != 6 || j != 5)
					return 1;
				nox_video_pixmode_3799624 = 2;
				return 1;
			}
			if (v12.ddpfPixelFormat.dwRGBBitCount == 8) {
				nox_video_modeXxx_3801780 = 0;
				*getMemU32Ptr(0x5D4594, 3801776) = v1 >> 2;
				nox_video_pixmode_3799624 = 0;
				nox_pitch_3801808 = v1;
				nox_backbuffer_width32 = v1 >> 5;
				nox_backbuffer_pitch32 = v2 - v1;
				return 1;
			}
		}
		if (nox_video_modeXxx_3801780 != 2)
			return 1;
	}
	if (!(nox_video_renderTargetFlags & 4)) {
		if (nox_video_renderTargetFlags & 0x10) {
			nox_xxx_msgError_48C940("Unsupported windowed video mode detected\r\n\r\nPlease change your desktop to 16 "
									"bit color");
			return 0;
		}
		nox_xxx_msgError_48C940("Unsupported video mode\r\n\r\nPlease select either 16 bit color or 256 colors");
	}
	return 0;
}

//----- (0048BF70) --------------------------------------------------------
int nox_video_createCursorSurface_48BF70() {
	int result; // eax
	int v1;     // [esp+0h] [ebp-18h]
	int v2;     // [esp+4h] [ebp-14h]
	int4 a1;    // [esp+8h] [ebp-10h]

	g_cursor_surf =
		sub_48A600(128, 128, DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT, DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY);
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

//----- (0048BDE0) --------------------------------------------------------
BOOL nox_xxx_makeFillerColor_48BDE0() {
	int v0; // eax

	v0 = nox_color_rgb_4344A0(255, 0, 255);
	*getMemU32Ptr(0x5D4594, 1193592) = v0;
	if (g_cursor_surf) {
		DDCOLORKEY v2; // [esp+0h] [ebp-8h]

		v0 = nox_video_pixmode_3799624 ? (unsigned __int16)v0 : (unsigned __int8)v0;
		v2.dwColorSpaceHighValue = v0;
		v2.dwColorSpaceLowValue = v0;
		if (g_cursor_surf->lpVtbl->SetColorKey(g_cursor_surf, DDCKEY_SRCBLT, &v2))
			return 0;
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
	if (g_cursor_surf) {
		g_cursor_surf->lpVtbl->Release(g_cursor_surf);
		g_cursor_surf = 0;
	}
	if (dword_6F7C48) {
		dword_6F7C48->lpVtbl->Release(dword_6F7C48);
		dword_6F7C48 = 0;
	}
	if (dword_5d4594_1193704) {
		free(*(LPVOID*)&dword_5d4594_1193704);
		dword_5d4594_1193704 = 0;
	}
	dword_5d4594_1193624 = 0;
}

//----- (00435380) --------------------------------------------------------
void sub_435380(LPDIRECTDRAWGAMMACONTROL* a1) {
	if (*a1) {
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}

//----- (004353A0) --------------------------------------------------------
void sub_4353A0(LPDIRECTDRAWPALETTE* a1) {
	if (*a1) {
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}

//----- (004338D0) --------------------------------------------------------
int sub_4338D0() {
	int result;       // eax
	pixel888 v2[256]; // [esp+Ch] [ebp-300h]

	switch (nox_video_pixmode_3799624) {
	case 0:
		nox_color_rgb_func = nox_color_func_435180;
		dword_975240 = sub_435240;
		dword_975380 = sub_434E80;
		memcpy(byte_5D4594_3804364, byte_581450_9176, sizeof(byte_581450_9176));
		break;
	case 1:
		nox_color_rgb_func = nox_color_rgba5551ext_4351C0;
		dword_975240 = sub_435280;
		dword_975380 = sub_434E80;
		memcpy(byte_5D4594_3804364, byte_581450_9176, sizeof(byte_581450_9176));
		break;
	case 2:
		nox_color_rgb_func = nox_color_rgb565ext_435200;
		dword_975240 = sub_435280;
		dword_975380 = sub_434EC0;
		memcpy(byte_5D4594_3804364, byte_581450_9336, sizeof(byte_581450_9336));
		break;
	}
	nox_draw_curDrawData_3799572->data[13] = 0;
	nox_draw_curDrawData_3799572->data[14] = 0;
	nox_draw_curDrawData_3799572->data[17] = 0;
	nox_draw_curDrawData_3799572->data[24] = 0;
	nox_draw_curDrawData_3799572->data[25] = 0;
	nox_draw_curDrawData_3799572->data[26] = 0;
	nox_draw_curDrawData_3799572->data[44] = 0;
	nox_draw_curDrawData_3799572->data[45] = 0;
	nox_draw_curDrawData_3799572->data[46] = 0;
	nox_draw_curDrawData_3799572->data[54] = 0;
	nox_draw_curDrawData_3799572->data[55] = 0;
	nox_draw_curDrawData_3799572->data[56] = 0;
	nox_draw_curDrawData_3799572->data[58] = 0;
	nox_draw_curDrawData_3799572->data[59] = 0;
	nox_draw_curDrawData_3799572->data[60] = 0;
	nox_draw_curDrawData_3799572->data[61] = 0;
	nox_draw_curDrawData_3799572->data[259] = 255;
	nox_draw_curDrawData_3799572->data[260] = 16711935;
	nox_draw_curDrawData_3799572->data[261] = 16711935;
	nox_draw_curDrawData_3799572->data[262] = 0;
	sub_434990(25, 25, 25);
	result = sub_434CC0();
	if (result) {
		result = nox_draw_initColorTablesRev_434DA0();
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
				g_ddraw_gamma_control = 0;
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

//----- (00434B60) --------------------------------------------------------
BOOL sub_434B60() {
	int v0;       // ebp
	pixel888* v1; // edi
	int v2;       // ebx
	char* v3;     // esi
	__int64 v4;   // rax
	int v13;      // [esp+10h] [ebp-90Ch]
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
	unsigned __int8* v5; // eax
	int v6;              // ecx
	int v7;              // edi
	char v8;             // dl
	int v9;              // ecx
	char v10;            // dl
	int v11;             // ecx
	if (nox_video_pixmode_3799624)
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
}
// 434B60: using guessed type char var_8FF[511];
// 434B60: using guessed type char var_6FF[512];
// 434B60: using guessed type char var_4FF[511];

#ifdef NOX_PLAY_MOVIES
int PlayMovie(char* filename);
#endif // NOX_PLAY_MOVIES

//----- (004B0340) --------------------------------------------------------
int nox_client_drawGeneral_4B0340(int a1) // draw general
{
	BOOL v1;    // esi
	int v2;     // ebp
	int v3;     // edi
	int v4;     // ebx
	int result; // eax
	int v7;     // [esp+10h] [ebp-44h]
	int v8;     // [esp+14h] [ebp-40h]
	int v9;     // [esp+18h] [ebp-3Ch]
	int v10;    // [esp+1Ch] [ebp-38h]
	int v11;    // [esp+20h] [ebp-34h]
	int v12;    // [esp+24h] [ebp-30h]

	dword_5d4594_1311936 = 1;
	*getMemU32Ptr(0x5D4594, 1311932) = a1;
	v1 = (GetAsyncKeyState(VK_SHIFT) & 0x8000u) != 0;
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE) || v1 || nox_video_renderTargetFlags & 0x10)
		goto LABEL_23;
	sub_431290();
	sub_43DBD0();
	sub_44D8F0();
	while (sub_43DC40() || sub_44D930()) {
		sub_4312C0();
	}
	sub_43E8E0(0);
	v12 = sub_48B3E0(0);
	unacquireMouse_sub_47D8B0();
	sub_48A7F0();
	v2 = nox_video_modeXxx_3801780;
	if (nox_video_modeXxx_3801780) {
		v3 = a1;
		v4 = a1;
	LABEL_13:
#ifdef NOX_PLAY_MOVIES
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
#endif // NOX_PLAY_MOVIES
		;
		if (!v2) {
			nox_free_pixbuffers_486110();
			sub_48A120();
			nox_video_renderTargetFlags = v4;
			result = sub_48A040(v3, v8, v7, a1);
			if (!result)
				return result;
			result = nox_video_initPixbuffer_486090();
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
	v2 = nox_video_modeXxx_3801780;
	v3 = windowHandle_dword_973FE0;
	v4 = nox_video_renderTargetFlags;
	v8 = nox_backbuffer_width;
	v7 = nox_backbuffer_height;
	a1 = nox_backbuffer_depth;
	nox_video_stopCursorDrawThread_48B350();
	nox_draw_freeColorTables_433C20();
	nox_free_pixbuffers_486110();
	sub_48A120();
	nox_video_renderTargetFlags = v4;
	result = sub_48A040(v3, NOX_DEFAULT_WIDTH, NOX_DEFAULT_HEIGHT, NOX_DEFAULT_DEPTH);
	if (result) {
		result = nox_video_initPixbuffer_486090();
		if (result)
			goto LABEL_13;
	}
	return result;
}
// 4B0536: variable 'v8' is possibly undefined
// 4B0536: variable 'v7' is possibly undefined

//----- (0048B5D0) --------------------------------------------------------
int nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(int a1, int a2) {
	int result; // eax
	int v3;     // esi

	result = 0;
	if (!*getMemU32Ptr(0x5D4594, 1193708) && nox_video_drawCursorThreadOk && dword_5d4594_823776 &&
		nox_video_cursorDrawIsThreaded && dword_5d4594_1193672 && *getMemU32Ptr(0x5D4594, 1193108) &&
		dword_5d4594_787144) {
		*getMemU32Ptr(0x5D4594, 1193708) = 1;
		nox_mutex_lock(getMemAt(0x5D4594, 3799596));
		if (a2)
			g_ddraw->lpVtbl->WaitForVerticalBlank(g_ddraw, 1, 0);
		v3 = nox_video_cursorThreadedDrawFnPtr(a1);
		nox_mutex_unlock(getMemAt(0x5D4594, 3799596));
		result = v3;
		*getMemU32Ptr(0x5D4594, 1193708) = 0;
	}
	return result;
}

#endif // USE_DDRAW
