//+build none

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "input.h"
#include "proto.h"

#include <SDL2/SDL.h>

SDL_Window* g_window;
int g_fullscreen = -4; // -4 means "unset"
extern _DWORD dword_5d4594_371712;
extern _DWORD dword_5d4594_805860;
extern _DWORD dword_5d4594_823776;
extern int nox_video_dxFullScreen;

extern int g_scaled;
// FIXME: w&h are set to 0 at initialization (but window will be resized a moment later)
extern int nox_win_width;
extern int nox_win_height;

#ifndef NOX_CGO
int nox_video_getFullScreen() {
	return g_fullscreen;
}
void nox_video_setFullScreen(int v) {
	g_fullscreen = v;
}
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
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) < 0) {
		fprintf(stderr, "ERROR: SDL Initialization failed: %s\n", SDL_GetError());
		return 0;
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	g_window = SDL_CreateWindow("Nox Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, nox_win_width,
								nox_win_height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (g_window == NULL) {
		fprintf(stderr, "ERROR: SDL Window creation failed: %s\n", SDL_GetError());
		return 0;
	}

#ifdef __EMSCRIPTEN__
	if (EM_ASM_INT(return isMobile())) {
		SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
		SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
		SDL_EventState(SDL_MOUSEBUTTONUP, SDL_IGNORE);
		SDL_EventState(SDL_MOUSEWHEEL, SDL_IGNORE);
	} else {
		SDL_EventState(SDL_FINGERDOWN, SDL_IGNORE);
		SDL_EventState(SDL_FINGERUP, SDL_IGNORE);
		SDL_EventState(SDL_FINGERMOTION, SDL_IGNORE);
	}
#endif // __EMSCRIPTEN__

	cmain(g_argc, g_argv);
	input_cleanup(); // TODO: move inside the cmain
#ifndef __EMSCRIPTEN__
	SDL_Quit();
#endif
	return 1;
}
#endif // NOX_CGO

//----- (00401FD0) --------------------------------------------------------
SDL_Window* nox_video_getWindow_401FD0() { return g_window; }

//----- (00401FE0) --------------------------------------------------------
void  nox_video_setWinTitle_401FE0(char* s) {
	if (s)
		SDL_SetWindowTitle(g_window, s);
}

//----- (0047D8A0) --------------------------------------------------------
void nox_xxx_showWindow_47D8A0() {
	SDL_RestoreWindow(g_window);
}

//----- (004147E0) --------------------------------------------------------
BOOL  sub_4147E0(HWND hWnd) {
	return 0;
}
