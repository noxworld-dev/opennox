#include "draw_common.h"

SDL_Renderer* g_ddraw;
uint32_t g_texture, g_program, g_tex_coord_buffer, g_tex_coord_attr, g_gamma_uniform, g_matrix_uniform, g_sampler_uniform;





//----- (0048A120) --------------------------------------------------------
void sub_48A120() {
	dword_6F7BB0 = 0;

	sub_48B1D0_free_surface(&dword_973C60);
	sub_48B1D0_free_surface(&dword_973C88);
	sub_48B1D0_free_surface(&g_backbuffer1);
	sub_48A9C0(0);
	sub_48AA40();
	SDL_DestroyRenderer(g_ddraw);
}

SDL_Surface* __cdecl nox_video_createSurface_48A600(int width, int height, int flags, int caps) {
	if (!(flags & DDSD_WIDTH))
		DebugBreak();
	if (!(flags & DDSD_HEIGHT))
		DebugBreak();

	SDL_Surface* pSurface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 16, g_format);

	return pSurface;
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

	//glViewport(vpx, vpy, vpw, vph);
}

void sdl_present() {
	if (g_backbuffer1) {
		SDL_Rect srcrect;
		SDL_Rect dstrect;
		//SDL_Rect currrect;
		//int res;
		//BOOL isRectDifferent = 0;

		dstrect.x = 0;
		dstrect.y = 0;
		SDL_GetWindowSize(getWindowHandle_nox_xxx_getHWND_401FD0(), &(dstrect.w), &(dstrect.h));
		SDL_GetClipRect(g_backbuffer1, &srcrect);
		
		sub_48BE50(1);
		nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(0, 0);

		set_viewport(g_backbuffer1->w, g_backbuffer1->h);

		SDL_Texture* tex = SDL_CreateTextureFromSurface(g_ddraw, g_backbuffer1); //Maybe find a way to get the buffer

		//This is only available after SDL 2.0.12
#if SDL_PATCHLEVEL >= 12
		SDL_SetTextureScaleMode(tex, SDL_ScaleModeBest);
#endif

		SDL_RenderCopy(g_ddraw, tex, &srcrect, &dstrect);
		SDL_RenderPresent(g_ddraw);
		SDL_DestroyTexture(tex);

		sub_48BE50(0);
	}
}

int create_surfaces(HWND a1, int width, int height) {
	BYTE v3;

	v3 = nox_video_renderTargetFlags;

	g_backbuffer1 = nox_video_createSurface_48A600(width, height, DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH, DDSCAPS_OFFSCREENPLAIN);

	if (g_backbuffer1)
		return 1;

	return 0;
}

int nox_xxx_initDDraw_48B000() {
#if __EMSCRIPTEN__
	g_rotate = EM_ASM_INT(return Module['shouldRotate']());
#else
	g_rotate = 0;
#endif
	g_format = SDL_PIXELFORMAT_RGB555;
	if (!g_ddraw) {
		g_ddraw =
			SDL_CreateRenderer(windowHandle_dword_973FE0, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (g_ddraw == NULL) {
			fprintf(stderr, "SDL Renderer context creation failed: %s\n", SDL_GetError());
			return 0;
		}
	}

	return 1;
}



//----- (0048A3D0) --------------------------------------------------------
int sub_48A3D0() {
	dword_5d4594_3801780 = 2;
	*getMemU32Ptr(0x5D4594, 3801796) = 0;
	if (g_backbuffer1) {
		nox_backbuffer_width = g_backbuffer1->w;
		nox_backbuffer_height = g_backbuffer1->h;
		*getMemU32Ptr(0x5D4594, 3799564) = g_backbuffer1->pitch;
		*getMemU32Ptr(0x5D4594, 3801796) = 1;
		sub_48A190();

		nox_backbuffer_width32 = g_backbuffer1->w >> 4;
		*getMemU32Ptr(0x5D4594, 3801776) = g_backbuffer1->w >> 1;
		dword_5d4594_3801780 = 1;
		nox_pitch_3801808 = 2 * g_backbuffer1->w;
		nox_backbuffer_pitch32 = g_backbuffer1->pitch - 2 * g_backbuffer1->w;
		dword_5d4594_3799624 = 1;
		return 1;
	}
	return 0;
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
				char* path = dos_to_unix(&byte_5D4594[1311940]);
				PlayMovie(path);
				free(path);
			}
	#else
			//PlayMovie(&byte_5D4594[1311940]);
	#endif
#endif

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

//----- (0048A040) --------------------------------------------------------
int __cdecl sub_48A040(HWND a1, int a2, int a3, int a4) {
	int result; // eax

	g_backbuffer_count = 2;
	dword_6F7BB0 = 0;

	g_ddraw = 0;
	g_backbuffer1 = 0;

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

		create_surfaces(a1, a2, a3);

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
