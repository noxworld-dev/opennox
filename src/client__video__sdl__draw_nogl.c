#include "client__video__draw_common.h"

#ifndef NOX_CGO
extern uint32_t g_present_ticks;
SDL_Renderer* g_ddraw;

//----- (0048A120) --------------------------------------------------------
void nox_video_free_renderer_48A120() {
	dword_6F7BB0 = 0;

	sub_48B1D0_free_surface(&g_surface_973C60);
	sub_48B1D0_free_surface(&g_surface_973C88);
	sub_48B1D0_free_surface(&g_backbuffer1);
	nox_video_minimizeOrMaximize_48A9C0(0);
	sub_48AA40();
	SDL_DestroyRenderer(g_ddraw);
}

SDL_Surface* nox_video_createSurface_48A600(int width, int height, int caps) {
	SDL_Surface* pSurface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 16, g_format);

	return pSurface;
}

int nox_video_getSurfaceData_48A720(SDL_Surface* surf, int* outPitch, void** outPixels) {
	if (outPitch)
		*outPitch = surf->pitch;
	if (outPixels)
		*outPixels = surf->pixels;
	return 0;
}

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
	SDL_GL_GetDrawableSize(nox_video_getWindow_401FD0(), &vpw, &vph);
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

	// glViewport(vpx, vpy, vpw, vph);
}

void sdl_present() {
	if (g_backbuffer1) {
		SDL_Rect srcrect;
		SDL_Rect dstrect;
		// SDL_Rect currrect;
		// int res;
		// int isRectDifferent = 0;

		dstrect.x = 0;
		dstrect.y = 0;
		SDL_GetWindowSize(nox_video_getWindow_401FD0(), &(dstrect.w), &(dstrect.h));
		SDL_GetClipRect(g_backbuffer1, &srcrect);

		nox_video_mouseThreadXxx_48BE50(1);
		nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(0, 0);

		set_viewport(g_backbuffer1->w, g_backbuffer1->h);

		SDL_Texture* tex = SDL_CreateTextureFromSurface(g_ddraw, g_backbuffer1); // Maybe find a way to get the buffer

		SDL_RenderCopy(g_ddraw, tex, &srcrect, &dstrect);
		SDL_RenderPresent(g_ddraw);
		SDL_DestroyTexture(tex);

		nox_video_mouseThreadXxx_48BE50(0);
	}
}

int create_surfaces(int width, int height) {
	uint8_t v3;

	v3 = nox_video_renderTargetFlags;

	g_backbuffer1 = nox_video_createSurface_48A600(width, height, DDSCAPS_OFFSCREENPLAIN);

	if (g_backbuffer1)
		return 1;

	return 0;
}

int nox_video_init_renderer_48B000() {
#if __EMSCRIPTEN__
	g_rotate = EM_ASM_INT(return Module['shouldRotate']());
#else
	g_rotate = 0;
#endif
	g_format = SDL_PIXELFORMAT_RGB555;
	if (!g_ddraw) {
		g_ddraw =
			SDL_CreateRenderer(nox_video_getWindow_401FD0(), 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (g_ddraw == NULL) {
			fprintf(stderr, "SDL Renderer context creation failed: %s\n", SDL_GetError());
			return 0;
		}
	}

	return 1;
}

void nox_video_drop_renderer() {
	g_ddraw = 0; // TODO: shouldn't we free it?
	g_present_ticks = 0;
}

//----- (0048A3D0) --------------------------------------------------------
int nox_video_setBackBufSizes_48A3D0() {
	dword_5d4594_3801780 = 2;
	*getMemU32Ptr(0x973F18, 2368) = 0;
	if (!g_backbuffer1) {
		return 0;
	}
	nox_backbuffer_width = g_backbuffer1->w;
	nox_backbuffer_height = g_backbuffer1->h;
	*getMemU32Ptr(0x973F18, 136) = g_backbuffer1->pitch;
	*getMemU32Ptr(0x973F18, 2368) = 1;
	nox_video_setBackBufferPtrs_48A190();

	nox_backbuffer_width32 = g_backbuffer1->w >> 4;
	*getMemU32Ptr(0x973F18, 2348) = g_backbuffer1->w >> 1;
	dword_5d4594_3801780 = 1;
	nox_backbuffer_pitch_3801808 = 2 * g_backbuffer1->w;
	nox_backbuffer_pitchDiff = g_backbuffer1->pitch - 2 * g_backbuffer1->w;
	nox_video_pixmode_3799624 = 1;
	return 1;
}

#ifdef NOX_PLAY_MOVIES
int PlayMovie(char* filename);
#endif // NOX_PLAY_MOVIES

//----- (004B0340) --------------------------------------------------------
int nox_client_drawGeneral_4B0340(int a1) // draw general
{
	int v1;     // esi
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
	// FIXME
	v1 = 0;
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE) || v1 || nox_video_renderTargetFlags & 0x10)
		goto LABEL_23;
	sub_431290();
	sub_43DBD0();
	sub_44D8F0();
	while (sub_43DC40() || sub_44D930()) {
		sub_4312C0();
#ifdef __EMSCRIPTEN__
		nox_platform_sleep(0x32u);
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

// FIXME: play movies
#if 0
#ifdef __linux__
			;
			if (nox_enable_audio) { // TODO: disable audio in movies instead
				char* path = nox_fs_normalize(&byte_5D4594[1311940]);
				PlayMovie(path);
				free(path);
			}
#else
			//PlayMovie(&byte_5D4594[1311940]);
#endif
#endif

		if (!v2) {
			nox_free_pixbuffers_486110();
			nox_video_free_renderer_48A120();
			nox_video_renderTargetFlags = v4;
			result = nox_video_resetRenderer_48A040(v8, v7, a1);
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
	v2 = dword_5d4594_3801780;
	v4 = nox_video_renderTargetFlags;
	v8 = nox_backbuffer_width;
	v7 = nox_backbuffer_height;
	a1 = nox_backbuffer_depth;
	nox_video_stopCursorDrawThread_48B350();
	sub_433C20();
	nox_free_pixbuffers_486110();
	nox_video_free_renderer_48A120();
	nox_video_renderTargetFlags = v4;
	result = nox_video_resetRenderer_48A040(NOX_DEFAULT_WIDTH, NOX_DEFAULT_HEIGHT, NOX_DEFAULT_DEPTH);
	if (result) {
		result = nox_video_initPixbuffer_486090();
		if (result)
			goto LABEL_13;
	}
	return result;
}

//----- (0048A040) --------------------------------------------------------
int nox_video_resetRenderer_48A040(int width, int height, int depth) {
	g_backbuffer_count = 2;
	dword_6F7BB0 = 0;

	nox_video_drop_renderer();
	g_backbuffer1 = 0;

	g_surface_973C88 = 0;
	g_surface_973C60 = 0;
	dword_973C70 = 0;
	dword_974854 = 0;
	dword_6F7B9C = 1;
	dword_5ACFAC = 1;
	if (!(nox_video_renderTargetFlags & 4)) {
		sub_48AA40();
		if (!nox_video_init_renderer_48B000())
			return 0;

		create_surfaces(width, height);
	}
	dword_6F7BB0 = 1;
	sub_48A820(1);
	if (!nox_video_setBackBufSizes_48A3D0())
		return 0;
	sub_48A7F0();
	return 1;
}
#endif // NOX_CGO

void sub_48B1B0() {
	// nop
}
