//+build none

#ifdef _WIN32
#include <GL/glew.h>
#else
#define GL_GLEXT_PROTOTYPES
#endif
#include "client__video__draw_common.h"
#include "common/fs/nox_fs.h"

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
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"

SDL_GLContext g_ddraw;
extern uint32_t g_present_ticks;
GLuint g_texture, g_program, g_tex_coord_buffer, g_tex_coord_attr, g_gamma_uniform, g_matrix_uniform, g_sampler_uniform;

unsigned int g_tex_coord_itemsize, g_tex_coord_numitems;

SDL_Surface* g_frontbuffer1;

static void glCheckError() {
#if 0
    GLenum error = glGetError();
    if (error)
        abort();
#endif
}

//----- (0048A120) --------------------------------------------------------
void nox_video_free_renderer_48A120() {
	dword_6F7BB0 = 0;

	sub_48B1D0_free_surface(&g_surface_973C60);
	sub_48B1D0_free_surface(&g_surface_973C88);
	if (g_backbuffer1 != g_frontbuffer1) {
		sub_48B1D0_free_surface(&g_frontbuffer1);
	} else {
		g_frontbuffer1 = 0;
	}
	sub_48B1D0_free_surface(&g_backbuffer1);
	nox_video_minimizeOrMaximize_48A9C0(0);
	sub_48AA40();
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

	glViewport(vpx, vpy, vpw, vph);
}

#ifndef NOX_CGO
void sdl_present() {
	if (g_ddraw && g_backbuffer1) {
		SDL_Rect srcrect;
		SDL_Rect dstrect;
		SDL_Rect currrect;
		int res;
		int isRectDifferent = 0;

		dstrect.x = 0;
		dstrect.y = 0;
		SDL_GL_GetDrawableSize(nox_video_getWindow_401FD0(), &(dstrect.w), &(dstrect.h));
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
			g_frontbuffer1 = nox_video_createSurface_48A600(dstrect.w, dstrect.h, DDSCAPS_OFFSCREENPLAIN);
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

		nox_video_mouseThreadXxx_48BE50(1);
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
		glUniform1f(g_gamma_uniform, nox_video_getGamma());
		glCheckError();
		glBindBuffer(GL_ARRAY_BUFFER, g_tex_coord_buffer);
		glCheckError();
		glVertexAttribPointer(g_tex_coord_attr, g_tex_coord_itemsize, GL_FLOAT, GL_FALSE, 0, 0);
		glCheckError();
		glDrawArrays(GL_TRIANGLE_STRIP, 0, g_tex_coord_numitems);
		glCheckError();

		SDL_GL_SwapWindow(nox_video_getWindow_401FD0());

		nox_video_mouseThreadXxx_48BE50(0);
	}
}
#endif // NOX_CGO

int create_surfaces(int width, int height) {
	int result = 0;
	uint8_t v3;

	v3 = nox_video_renderTargetFlags;

	g_backbuffer1 = nox_video_createSurface_48A600(width, height, DDSCAPS_OFFSCREENPLAIN);
	// g_backbufferrgb = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_ABGR8888);
	if (g_backbuffer1) {
		// if (SDL_RenderSetLogicalSize(g_ddraw, width, height) == 0)
		result = 1;
	}
	return result;
}

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

int nox_video_init_renderer_48B000() {
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
		g_ddraw = SDL_GL_CreateContext(nox_video_getWindow_401FD0());
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
		_dprintf("Error: %s\n", glewGetErrorString(err));
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

//----- (0048A3D0) --------------------------------------------------------
int nox_video_setBackBufSizes_48A3D0() {
	dword_5d4594_3801780 = 2;
	*getMemU32Ptr(0x973F18, 2368) = 0;
	if (g_backbuffer1) {
		nox_backbuffer_width = g_backbuffer1->w;
		nox_backbuffer_height = g_backbuffer1->h;
		*getMemU32Ptr(0x973F18, 136) = g_backbuffer1->pitch;
		*getMemU32Ptr(0x973F18, 2368) = 1;
		nox_video_setBackBufferPtrs_48A190();
		if (g_format == SDL_PIXELFORMAT_RGBA5551 || g_format == SDL_PIXELFORMAT_RGB565) {
			nox_backbuffer_width32 = g_backbuffer1->w >> 4;
			*getMemU32Ptr(0x973F18, 2348) = g_backbuffer1->w >> 1;
			dword_5d4594_3801780 = 1;
			nox_backbuffer_pitch_3801808 = 2 * g_backbuffer1->w;
			nox_backbuffer_pitchDiff = g_backbuffer1->pitch - 2 * g_backbuffer1->w;

			if (g_format == SDL_PIXELFORMAT_RGBA5551)
				nox_video_pixmode_3799624 = 1;
			else if (g_format == SDL_PIXELFORMAT_RGB565)
				nox_video_pixmode_3799624 = 2;
			return 1;
		}
	}
	return 0;
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
	int v7 = 0; // [esp+10h] [ebp-44h]
	int v8 = 0; // [esp+14h] [ebp-40h]
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
#ifdef NOX_PLAY_MOVIES
#ifdef __linux__
		;
		if (nox_enable_audio) { // TODO: disable audio in movies instead
			char* path = nox_fs_normalize(getMemAt(0x5D4594, 1311940));
			PlayMovie(path);
			free(path);
		}
#else  // __linux__
		PlayMovie(getMemAt(0x5D4594, 1311940));
#endif // __linux__
#endif // NOX_PLAY_MOVIES
		;
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
int nox_video_resetRenderer_48A040(int a2, int a3, int a4) {
	int result; // eax

	g_backbuffer_count = 2;
	dword_6F7BB0 = 0;

	g_ddraw = 0;
	g_backbuffer1 = 0;

	g_surface_973C88 = 0;
	g_surface_973C60 = 0;
	dword_973C70 = 0;
	g_present_ticks = 0;
	dword_974854 = 0;
	dword_6F7B9C = 1;
	dword_5ACFAC = 1;
	if (!(nox_video_renderTargetFlags & 4)) {
		sub_48AA40();
		result = nox_video_init_renderer_48B000();
		if (!result)
			return result;

		create_surfaces(a2, a3);
	}
	dword_6F7BB0 = 1;
	sub_48A820(1u);
	result = nox_video_setBackBufSizes_48A3D0();
	if (result) {
		sub_48A7F0();
		result = 1;
	}
	return result;
}

void sub_48B1B0() {
	if (g_ddraw) {
		SDL_GL_DeleteContext(g_ddraw);
		g_ddraw = NULL;
	}
}
