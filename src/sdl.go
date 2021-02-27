package main

/*
#include <SDL2/SDL.h>
#include "client__video__draw_common.h"

extern SDL_Renderer* g_ddraw;
extern uint32_t g_texture, g_program, g_tex_coord_buffer, g_tex_coord_attr, g_gamma_uniform, g_matrix_uniform, g_sampler_uniform;
*/
import "C"
import (
	_ "github.com/veandco/go-sdl2/sdl"
)

func set_viewport(srcw, srch float32) {
	var (
		ratio              = srcw / srch
		offx               = 0
		offy               = 0
		vpw, vph, vpx, vpy int
	)

	var tw, th C.int
	C.SDL_GL_GetDrawableSize(C.windowHandle_dword_973FE0, &tw, &th)
	vpw, vph = int(tw), int(th)

	// Maintain source aspect ratio
	if C.g_rotate != 0 && float32(vph)-ratio*float32(vpw) > float32(vpw)-ratio*float32(vph) {
		C.g_rotated = 1
	} else {
		C.g_rotated = 0
	}
	if C.g_rotated != 0 {
		ratio = 1.0 / ratio
	}

	if ratio*float32(vph) <= float32(vpw) {
		offx = int(float32(vpw)-float32(vph)*ratio) / 2
		vpw = int(float32(vph) * ratio)
	} else {
		offy = int(float32(vph)-float32(vpw)/ratio) / 2
		vph = int(float32(vpw) / ratio)
	}
	vpx = offx
	vpy = offy
	_ = vpx
	_ = vpy
}

//export sdl_present
func sdl_present() {
	if C.g_backbuffer1 == nil {
		return
	}
	var srcrect, dstrect C.SDL_Rect
	C.SDL_GetWindowSize(C.nox_video_getWindow_401FD0(), &dstrect.w, &dstrect.h)
	C.SDL_GetClipRect(C.g_backbuffer1, &srcrect)

	C.sub_48BE50(1)
	C.nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(0, 0)

	set_viewport(float32(C.g_backbuffer1.w), float32(C.g_backbuffer1.h))

	tex := C.SDL_CreateTextureFromSurface(C.g_ddraw, C.g_backbuffer1) // maybe find a way to get the buffer

	//This is only available after SDL 2.0.12
	//C.SDL_SetTextureScaleMode(tex, C.SDL_ScaleModeBest)

	C.SDL_RenderCopy(C.g_ddraw, tex, &srcrect, &dstrect)
	C.SDL_RenderPresent(C.g_ddraw)
	C.SDL_DestroyTexture(tex)

	C.sub_48BE50(0)
}
