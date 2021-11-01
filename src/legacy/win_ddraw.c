#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

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
#include "legacy/client__video__ddraw__draw_ddraw.h"
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

WNDCLASSEXA g_wnd_class;
HWND g_hwnd;

DWORD dword_974854;
int g_fullscreen = -4; // -4 means "unset"
extern _DWORD dword_5d4594_371712;
extern _DWORD dword_5d4594_805860;
extern _DWORD dword_5d4594_823776;
extern int nox_video_dxFullScreen;

extern int g_scaled;
// FIXME: w&h are set to 0 at initialization (but window will be resized a moment later)
extern int nox_win_width;
extern int nox_win_height;

//----- (00401C70) --------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	char* v4; // edi
	int v7;   // esi
#ifdef __EMSCRIPTEN__
	int v10; // eax
#endif
	const char* g_argv[21];
	unsigned int g_argc;

	init_data();

	g_argv[0] = "nox.exe";
	g_argc = 1;

	nox_xxx_gameResizeScreen_43BEF0_set_video_mode(0, 0, 0); // probably not needed

	for (v4 = strtok(lpCmdLine, " \t"); v4; v4 = strtok(0, " \t")) {
		if (!strcmp("-window", v4)) {
			*(_DWORD*)&nox_video_dxFullScreen = 0;
			dword_5d4594_805860 = 0;
			g_fullscreen = -2;
		} else if (!strcmp("-swindow", v4)) {
			*(_DWORD*)&nox_video_dxFullScreen = 0;
			dword_5d4594_805860 = 1;
			g_fullscreen = -3;
		} else if (!strcmp("-fullscreen", v4)) {
			g_fullscreen = -1;
		} else if (!strcmp("-stretch", v4)) {
			g_scaled = -1;
		} else if (!strcmp("-minimize", v4)) {
			*getMemU32Ptr(0x5D4594, 805864) = 1;
		} else {
			g_argv[g_argc] = v4;
			g_argc++;
		}
	}
#ifdef __EMSCRIPTEN__
	if (EM_ASM_INT(return Module['shouldStretch']())) {
		g_scaled = -1;
	}
	v10 = 0;
#endif
	g_argv[g_argc] = NULL;
	v7 = 0;
	while (v7 < g_argc) {
		if (!_strcmpi(g_argv[v7++], "-serveronly")) {
#ifdef __EMSCRIPTEN__
			v10 = 1;
#endif
			break;
		}
	}

	HWND v11; // esi
	HWND v13; // eax
	if (v10 || !(v11 = FindWindowA("Nox Game Window", 0))) {
		*getMemU32Ptr(0x5D4594, 823784) = hInstance;
		*getMemU32Ptr(0x5D4594, 823788) = nShowCmd;

		g_wnd_class.cbSize = 48;
		g_wnd_class.style = 4099;
		g_wnd_class.lpfnWndProc = nox_xxx_windowProc_444FF0;
		g_wnd_class.cbClsExtra = 0;
		g_wnd_class.cbWndExtra = 0;
		g_wnd_class.hInstance = hInstance;
		g_wnd_class.hIcon = LoadIconA(hInstance, (LPCSTR)0x65);
		g_wnd_class.hCursor = LoadCursorA(0, (LPCSTR)0x7F00);
		g_wnd_class.hbrBackground = (HBRUSH)GetStockObject(4);
		g_wnd_class.lpszMenuName = 0;
		g_wnd_class.lpszClassName = "Nox Game Window";
		g_wnd_class.hIconSm = 0;

		RegisterClassExA(&g_wnd_class);
		v13 = CreateWindowExA(0x40000u, "Nox Game Window", "NOX", 0x80000000, 0, 0, nox_win_width, nox_win_height, 0, 0,
							  hInstance, 0);
		if (!v13)
			return 0;
		g_hwnd = v13;

		sub_401070(g_argc, g_argv);
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_GAMELOOP_MEMDUMP))
			nox_xxx_gameLoopMemDump_413E30(/* "Memory dump after GameLoop() :" */);
		*getMemU32Ptr(0x5D4594, 823800) = 1;
		nox_input_pollEvents_4453A0();
		DestroyWindow(g_hwnd);
		sub_416B00();
		UnregisterClassA(g_wnd_class.lpszClassName, hInstance);
		ClipCursor(0);
	} else {
		SetForegroundWindow(v11);
		ShowWindow(v11, SW_RESTORE);
	}
	return 1;
}

//----- (00401FD0) --------------------------------------------------------
HWND nox_video_getWindow_401FD0() { return g_hwnd; }

//----- (00401FE0) --------------------------------------------------------
void sub_401FE0(LPCSTR lpString) {
	if (lpString)
		SetWindowTextA(g_hwnd, lpString);
}

//----- (0047D8A0) --------------------------------------------------------
void nox_xxx_showWindow_47D8A0() { ShowWindow(nox_video_getWindow_401FD0(), SW_RESTORE); }

//----- (00444FF0) --------------------------------------------------------
int __stdcall nox_xxx_windowProc_444FF0(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	LPARAM v4;  // ebx
	WPARAM v5;  // esi
	UINT v6;    // edi
	int result; // eax
	WPARAM v8;  // esi

	v4 = lParam;
	v5 = wParam;
	v6 = Msg;
	if (Msg > 0x102) {
		if (Msg > 0x3B9) {
			if (Msg == 1040) {
				// character from IME
				v8 = wParam;
				nox_xxx_onChar_488BD0(wParam);
				return DefWindowProcA(hWnd, 0x410u, v8, v4);
			}
			if (Msg == 3024) {
				sub_414690((unsigned int*)wParam, (void(__stdcall*)(char*))lParam);
				if (sub_414800()) {
				LABEL_41:
					PostQuitMessage(0);
					nox_xxx_setContinueMenuOrHost_43DDD0(0);
					nox_game_exit_xxx_43DE60();
					return DefWindowProcA(hWnd, v6, v5, v4);
				}
			}
			return DefWindowProcA(hWnd, v6, v5, v4);
		}
		switch (Msg) {
		case 0x3B9u:
			sub_413870(wParam);
			return 1;
		case 0x201u:
			if (dword_5d4594_823776)
				sub_4B0610(0);
			break;
		case 0x30Fu:
			goto LABEL_34;
		case 0x311u:
			v5 = wParam;
			if ((HWND)wParam == hWnd)
				return DefWindowProcA(hWnd, v6, v5, v4);
		LABEL_34:
			sub_4348C0();
			return 1;
		}
	LABEL_23:
		v5 = wParam;
		return DefWindowProcA(hWnd, v6, v5, v4);
	}
	if (Msg == WM_CHAR) {
		v5 = wParam;
		Msg = wParam;
		wParam = 0;
		if (MultiByteToWideChar(0, 0, (LPCSTR)&Msg, -1, (LPWSTR)&wParam, 2) > 0) {
			nox_xxx_onChar_488BD0(wParam);
			return DefWindowProcA(hWnd, 0x102u, v5, v4);
		}
		return DefWindowProcA(hWnd, v6, v5, v4);
	}
	switch (Msg) {
	case WM_DESTROY:
		goto LABEL_41;
	case WM_ACTIVATE:
		v5 = (_WORD)wParam == 1 || (_WORD)wParam == 2;
		goto LABEL_13;
	case WM_SETFOCUS:
		if (dword_5d4594_823776)
			sub_48A820(0);
		goto LABEL_23;
	case WM_ACTIVATEAPP:
	LABEL_13:
		*getMemU32Ptr(0x5D4594, 823792) = v5;
		if (v5) {
			if (dword_5d4594_823776) {
				if (nox_xxx_directDrawBlitImpl_48A2A0())
					dword_974854 = 0;
			}
			sub_42ED20();
			result = DefWindowProcA(hWnd, v6, v5, v4);
		} else {
			if (dword_5d4594_823776)
				sub_48A9C0(1);
			sub_42ED70();
			result = DefWindowProcA(hWnd, v6, 0, v4);
		}
		return result;
	case WM_SETCURSOR:
		SetCursor(0);
		return 1;
	case WM_KEYDOWN:
		if (!dword_5d4594_823776)
			goto LABEL_23;
		v5 = wParam;
		if (wParam == 27) {
			sub_4B0610(1);
			return DefWindowProcA(hWnd, v6, 0x1Bu, v4);
		}
		sub_4B0610(0);
		if (v5 != 19)
			return DefWindowProcA(hWnd, v6, v5, v4);
		sub_48A9C0(0);
		result = DefWindowProcA(hWnd, v6, 0x13u, v4);
		break;
	default:
		return DefWindowProcA(hWnd, v6, v5, v4);
	}
	return result;
}

//----- (004147E0) --------------------------------------------------------
BOOL sub_4147E0(HWND hWnd) {
	// Trigger expiration time check.
	return PostMessageA(hWnd, 3024u, (WPARAM)getMemAt(0x5D4594, 338464), *(LPARAM*)getMemAt(0x587000, 32580));
}

// 4514E0: using guessed type void  nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (00416A10) --------------------------------------------------------
int nox_xxx_createMutexCheck_416A10() {
	HWND v0;    // esi
	int result; // eax
	HWND v2;    // eax
	dword_5d4594_371712 = CreateMutexA(0, 0, "843ED62B-354B-11d3-8F70-0060089C05B1");
	if (GetLastError() == 183) {
		if (dword_5d4594_371712) {
			CloseHandle(*(HANDLE*)&dword_5d4594_371712);
			dword_5d4594_371712 = 0;
		}
		v0 = FindWindowA("Nox Game Window", 0);
		if (v0 || (v0 = FindWindowA("NOX Setup", 0)) != 0) {
			if (IsIconic(v0))
				ShowWindow(v0, 9);
			SetForegroundWindow(v0);
		}
		result = 0;
	} else {
		*getMemU32Ptr(0x5D4594, 371708) = OpenMutexA(0x1F0001u, 0, "01AF9993-3492-11d3-8F6F-0060089C05B1");
		if (*getMemU32Ptr(0x5D4594, 371708)) {
			v2 = FindWindowA("NOX Autorun", 0);
			if (v2)
				SetForegroundWindow(v2);
			if (*getMemU32Ptr(0x5D4594, 371708)) {
				CloseHandle(*(HANDLE*)getMemAt(0x5D4594, 371708));
				*getMemU32Ptr(0x5D4594, 371708) = 0;
			}
			if (dword_5d4594_371712) {
				CloseHandle(*(HANDLE*)&dword_5d4594_371712);
				dword_5d4594_371712 = 0;
			}
			result = 0;
		} else {
			result = 1;
		}
	}
	return result;
}

//----- (00416B00) --------------------------------------------------------
HANDLE sub_416B00() {
	HANDLE result; // eax

	result = *(HANDLE*)&dword_5d4594_371712;
	if (dword_5d4594_371712) {
		result = (HANDLE)CloseHandle(*(HANDLE*)&dword_5d4594_371712);
		dword_5d4594_371712 = 0;
	}
	return result;
}
