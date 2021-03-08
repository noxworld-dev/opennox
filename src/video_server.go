//+build server

package main

/*
#include <stdbool.h>
*/
import "C"
import (
	"image"
	"unsafe"

	"nox/common/alloc"
	"nox/common/types"
)

func windowInit() (func(), error) {
	return func() {}, nil
}

type fakeSurface struct {
	data unsafe.Pointer
	w, h int
}

//export nox_video_createSurface_48A600
func nox_video_createSurface_48A600(w, h, caps C.int) unsafe.Pointer {
	data := alloc.Calloc(uintptr(w*h), 2)
	surf := (*fakeSurface)(alloc.Calloc(1, unsafe.Sizeof(fakeSurface{})))
	surf.data = data
	surf.w = int(w)
	surf.h = int(h)
	return unsafe.Pointer(surf)
}

//export sub_48B1D0_free_surface
func sub_48B1D0_free_surface(p *unsafe.Pointer) {
	if s := *p; s != nil {
		surf := (*fakeSurface)(unsafe.Pointer(s))
		alloc.Free(surf.data)
		alloc.Free(unsafe.Pointer(surf))
		*p = nil
	}
}

//export nox_video_getSurfaceData_48A720
func nox_video_getSurfaceData_48A720(s unsafe.Pointer, outPitch *C.int, outPixels *unsafe.Pointer) C.int {
	surf := (*fakeSurface)(unsafe.Pointer(s))
	if outPitch != nil {
		*outPitch = C.int(surf.w * surf.h * 2)
	}
	if outPixels != nil {
		*outPixels = surf.data
	}
	return 0
}

//export nox_video_setWinTitle_401FE0
func nox_video_setWinTitle_401FE0(title *C.char) {
}

//export nox_video_showMovieFrame
func nox_video_showMovieFrame(s unsafe.Pointer) {
}

//export nox_video_resetRenderer_48A040
func nox_video_resetRenderer_48A040(width, height, depth C.int) C.int {
	return 1
}

//export nox_video_free_renderer_48A120
func nox_video_free_renderer_48A120() {
}

//export sdl_drawCursorThreaded
func sdl_drawCursorThreaded(a1 C.int) C.int {
	return 1
}

//export nox_xxx_makeFillerColor_48BDE0
func nox_xxx_makeFillerColor_48BDE0() C.bool {
	return true
}

//export nox_video_lockSurface_48A670
func nox_video_lockSurface_48A670(s unsafe.Pointer) {
}

//export nox_video_unlockSurface_48A6B0
func nox_video_unlockSurface_48A6B0(s unsafe.Pointer) {
}

//export nox_video_setBackBufferPtrs_48A190
func nox_video_setBackBufferPtrs_48A190() {
}

func presentFrame() {
}

func getDisplayDim() (r [4]int) {
	r[0] = noxDefaultWidth
	r[1] = noxDefaultHeight
	return
}

func setFullScreenMode(size types.Size, pos image.Point) {
}

func setFullScreenBorderlessMode(size types.Size, pos image.Point) {
}

func setWindowedMode(size types.Size, pos image.Point) {
}

func nox_video_copyBackBuffer_4AD2A0() {
}
func nox_video_copyBackBuffer3_4AD1E0() {
}

func windowMinimize() {
}
