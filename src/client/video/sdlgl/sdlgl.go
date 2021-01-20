package sdlgl

/*
#cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
#cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
#cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup
#cgo windows LDFLAGS: -lSDL2
#cgo linux freebsd darwin openbsd pkg-config: sdl2
#cgo CFLAGS: -DNOX_CGO

#cgo darwin LDFLAGS: -framework OpenGL
#cgo windows LDFLAGS: -lopengl32
#cgo linux LDFLAGS: -lGL

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_opengl_glext.h>
#include "../draw_common.h"

extern SDL_GLContext g_ddraw;
extern SDL_Surface* g_frontbuffer1;
extern GLuint g_texture, g_program, g_tex_coord_buffer, g_tex_coord_attr, g_gamma_uniform, g_matrix_uniform, g_sampler_uniform;

void set_viewport(float srcw, float srch);
SDL_Surface* nox_video_createSurface_48A600(int width, int height, int flags, int caps);
*/
import "C"
import (
	_ "github.com/veandco/go-sdl2/sdl"
)

func glCheckError() {
	// TODO
}

//export sdl_present
func sdl_present() {
	if C.g_ddraw != nil && C.g_backbuffer1 != nil {
		var (
			srcrect, dstrect, currrect C.SDL_Rect
			isRectDifferent            bool
		)
		C.SDL_GL_GetDrawableSize(C.getWindowHandle_nox_xxx_getHWND_401FD0(), &dstrect.w, &dstrect.h)
		C.SDL_GetClipRect(C.g_backbuffer1, &srcrect)

		if dstrect.w != srcrect.w || dstrect.h != srcrect.h {
			newCoefficient := float32(dstrect.w) / float32(dstrect.h)
			oldCoefficient := float32(srcrect.w) / float32(srcrect.h)
			var newW, newH float32
			if newCoefficient > oldCoefficient {
				newW = srcrect.h * newCoefficient
				newH = srcrect.h
			} else {
				newW = srcrect.w
				newH = srcrect.w / newCoefficient
			}
			dstrect.w = newW
			dstrect.h = newH

			isRectDifferent = true
		}
		if C.g_frontbuffer1 != C.g_backbuffer1 {
			if !C.g_scaled || isRectDifferent {
				C.sub_48B1D0_free_surface(&C.g_frontbuffer1)
				C.g_frontbuffer1 = nil
			} else {
				C.SDL_GetClipRect(C.g_frontbuffer1, &currrect)
				if dstrect.h != currrect.h || dstrect.w != currrect.w {
					C.sub_48B1D0_free_surface(&C.g_frontbuffer1)
					C.g_frontbuffer1 = 0
				}
			}
		}
		if C.g_scaled && C.g_frontbuffer1 == 0 {
			C.g_frontbuffer1 = C.nox_video_createSurface_48A600(dstrect.w, dstrect.h, C.DDSD_CAPS|C.DDSD_HEIGHT|C.DDSD_WIDTH, C.DDSCAPS_OFFSCREENPLAIN)
			C.SDL_SetSurfaceBlendMode(C.g_backbuffer1, C.SDL_BLENDMODE_NONE)
			C.SDL_SetSurfaceBlendMode(C.g_frontbuffer1, C.SDL_BLENDMODE_NONE)
		}
		if C.g_scaled {
			C.SDL_BlitScaled(C.g_backbuffer1, &srcrect, C.g_frontbuffer1, &dstrect)
		} else {
			C.g_frontbuffer1 = C.g_backbuffer1
		}
		matrix := [4]float32{1.0, 0.0, 0.0, 1.0}
		matrixRotated := []float32{0.0, 1.0, 1.0, 0.0}

		C.sub_48BE50(1)
		C.nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(0, 0)

		C.glBindTexture(C.GL_TEXTURE_2D, C.g_texture)
		glCheckError()

		C.glPixelStorei(C.GL_UNPACK_ROW_LENGTH, C.g_frontbuffer1.pitch/2)
		glCheckError()

		C.glTexImage2D(C.GL_TEXTURE_2D, 0, C.GL_RGBA, C.g_frontbuffer1.w, C.g_frontbuffer1.h, 0, C.GL_BGRA, C.GL_UNSIGNED_SHORT_1_5_5_5_REV, nil)
		glCheckError()

		C.glTexSubImage2D(C.GL_TEXTURE_2D, 0, 0, 0, C.g_frontbuffer1.w, C.g_frontbuffer1.h, C.GL_BGRA, C.GL_UNSIGNED_SHORT_1_5_5_5_REV, C.g_frontbuffer1.pixels)
		glCheckError()

		C.glTexParameteri(C.GL_TEXTURE_2D, C.GL_TEXTURE_WRAP_S, C.GL_CLAMP_TO_EDGE)
		C.glTexParameteri(C.GL_TEXTURE_2D, C.GL_TEXTURE_WRAP_T, C.GL_CLAMP_TO_EDGE)
		C.glTexParameteri(C.GL_TEXTURE_2D, C.GL_TEXTURE_MIN_FILTER, C.GL_LINEAR)
		glCheckError()

		C.glBindFramebuffer(C.GL_FRAMEBUFFER, 0)
		glCheckError()
		C.set_viewport(C.g_frontbuffer1.w, C.g_frontbuffer1.h)
		glCheckError()

		C.glClear(C.GL_COLOR_BUFFER_BIT)
		glCheckError()

		C.glUseProgram(C.g_program)
		glCheckError()
		C.glUniform1i(C.g_sampler_uniform, 0)
		glCheckError()
		if C.g_rotated {
			C.glUniformMatrix2fv(C.g_matrix_uniform, 1, C.GL_FALSE, &matrixRotated[0])
		} else {
			C.glUniformMatrix2fv(C.g_matrix_uniform, 1, C.GL_FALSE, &matrix[0])
		}
		glCheckError()
		C.glUniform1f(C.g_gamma_uniform, C.draw_gamma)
		glCheckError()
		C.glBindBuffer(C.GL_ARRAY_BUFFER, C.g_tex_coord_buffer)
		glCheckError()
		C.glVertexAttribPointer(C.g_tex_coord_attr, C.g_tex_coord_itemsize, C.GL_FLOAT, C.GL_FALSE, 0, 0)
		glCheckError()
		C.glDrawArrays(C.GL_TRIANGLE_STRIP, 0, C.g_tex_coord_numitems)
		glCheckError()

		C.SDL_GL_SwapWindow(C.windowHandle_dword_973FE0)

		C.sub_48BE50(0)
	}
}
