package main

/*
#include <SDL2/SDL.h>
#include "client__video__draw_common.h"
*/
import "C"
import (
	"fmt"
	"image"
	"log"
	"unsafe"

	"nox/common/memmap"
	"nox/common/types"

	"github.com/veandco/go-sdl2/sdl"
)

var (
	noxFullScreen      int = -4 // unset
	noxWindow          *sdl.Window
	noxRenderer        *sdl.Renderer
	noxBackbuf         *sdl.Surface
	noxBackBufCopyFunc func()
)

//export nox_video_getFullScreen
func nox_video_getFullScreen() C.int {
	return C.int(noxFullScreen)
}

//export nox_video_setFullScreen
func nox_video_setFullScreen(v C.int) {
	noxFullScreen = int(v)
}

//export nox_video_setWinTitle_401FE0
func nox_video_setWinTitle_401FE0(title *C.char) {
	noxWindow.SetTitle(C.GoString(title))
}

//export nox_video_getWindow_401FD0
func nox_video_getWindow_401FD0() *C.SDL_Window {
	return (*C.SDL_Window)(unsafe.Pointer(noxWindow))
}

//export nox_video_createSurface_48A600
func nox_video_createSurface_48A600(w, h, caps C.int) *C.SDL_Surface {
	surf, err := createSurface(int(w), int(h))
	if err != nil {
		panic(err)
	}
	return (*C.SDL_Surface)(unsafe.Pointer(surf))
}

func createSurface(w, h int) (*sdl.Surface, error) {
	return sdl.CreateRGBSurfaceWithFormat(0, int32(w), int32(h), 16, uint32(C.g_format))
}

//export nox_video_getSurfaceData_48A720
func nox_video_getSurfaceData_48A720(surf *C.SDL_Surface, outPitch *C.int, outPixels *unsafe.Pointer) C.int {
	if outPitch != nil {
		*outPitch = C.int(surf.pitch)
	}
	if outPixels != nil {
		*outPixels = unsafe.Pointer(surf.pixels)
	}
	return 0
}

//export nox_video_setBackBufferCopyFunc_4AD100
func nox_video_setBackBufferCopyFunc_4AD100() C.int {
	if C.nox_video_renderTargetFlags&0x40 != 0 {
		noxBackBufCopyFunc = nox_video_copyBackBuffer2_4AD180
		panic("not implemented")
	} else {
		nox_video_setBackBufferCopyFunc2_4AD150()
	}
	*memmap.PtrUint32(0x5D4594, 3798652) = 0
	return 1
}

//export nox_video_setBackBufferCopyFunc2_4AD150
func nox_video_setBackBufferCopyFunc2_4AD150() {
	if C.nox_video_renderTargetFlags&0x40 != 0 {
		noxBackBufCopyFunc = nox_video_copyBackBuffer_4AD2A0
	} else {
		noxBackBufCopyFunc = nox_video_copyBackBuffer3_4AD1E0
	}
}

//export nox_video_callCopyBackBuffer_4AD170
func nox_video_callCopyBackBuffer_4AD170() {
	noxBackBufCopyFunc()
}

func nox_video_copyBackBuffer2_4AD180() {
	panic("not implemented")
}

func nox_video_copyBackBuffer3_4AD1E0() {
	if C.dword_973C70 != 0 {
		return
	}

	width := int(noxBackbuf.W)
	height := int(noxBackbuf.H)

	if noxBackbuf.Lock() != nil {
		return
	}
	defer noxBackbuf.Unlock()

	pixbuf := asPtrSlice(unsafe.Pointer(C.nox_pixbuffer_rows_3798784), height)

	dpix := asU16Slice(noxBackbuf.Data(), int(noxBackbuf.Pitch*noxBackbuf.H)/2)
	pitch := int(noxBackbuf.Pitch)
	for y := 0; y < height; y++ {
		row := asU16Slice(pixbuf[y], width)
		drow := dpix[y*pitch/2 : (y+1)*pitch/2]
		copy(drow, row[:width])
	}
	*memmap.PtrUint32(0x5D4594, 3798652)++
}

//export nox_video_setBackBufferPtrs_48A190
func nox_video_setBackBufferPtrs_48A190() {
	C.dword_6F7B9C = 1
	C.nox_backbuffer1_pix = noxBackbuf.Data()
	C.nox_backbuffer_pix = C.nox_backbuffer1_pix
}

//export nox_video_lockSurface_48A670
func nox_video_lockSurface_48A670(s *C.SDL_Surface) {
	surf := (*sdl.Surface)(unsafe.Pointer(s))
	_ = surf.Lock()
}

//export nox_video_unlockSurface_48A6B0
func nox_video_unlockSurface_48A6B0(s *C.SDL_Surface) {
	surf := (*sdl.Surface)(unsafe.Pointer(s))
	surf.Unlock()
}

func nox_video_copyBackBuffer_4AD2A0() {
	// FIXME unlocked surfaces
	if C.dword_973C70 != 0 {
		return
	}
	width32 := int(C.nox_backbuffer_width32)
	width := width32 * 32
	pitch := width + int(C.nox_backbuffer_pitchDiff)
	height := int(C.nox_backbuffer_height)

	dst := asByteSlice(unsafe.Pointer(C.nox_backbuffer_pix), height*width)
	pixbuf := asPtrSlice(unsafe.Pointer(C.nox_pixbuffer_rows_3798784), height)
	for y := 0; y < height; y++ {
		row := asByteSlice(pixbuf[y], width32*32)
		drow := dst[y*pitch:]
		for x := 0; x < width32; x++ {
			i := x * 32
			copy(drow[i:], row[i:i+32])
		}
	}
	*memmap.PtrUint32(0x5D4594, 3798652)++
}

func windowInit() (func(), error) {
	nox_xxx_gameResizeScreen_43BEF0_set_video_mode(0, 0, 0) // probably not needed
	if err := sdl.Init(sdl.INIT_VIDEO | sdl.INIT_TIMER | sdl.INIT_GAMECONTROLLER); err != nil {
		return nil, fmt.Errorf("SDL Initialization failed: %w", err)
	}
	sdl.SetHint(sdl.HINT_RENDER_SCALE_QUALITY, "1")

	win, err := sdl.CreateWindow("Nox Game Window", sdl.WINDOWPOS_UNDEFINED, sdl.WINDOWPOS_UNDEFINED,
		int32(C.nox_win_width), int32(C.nox_win_height), sdl.WINDOW_RESIZABLE)
	if err != nil {
		sdl.Quit()
		return nil, fmt.Errorf("SDL Window creation failed: %w", err)
	}
	noxWindow = win
	return func() {
		sdl.Quit()
	}, nil
}

func setWindowRect(size types.Size, pos image.Point) {
	inpHandler.SetWinSize(size)
	noxWindow.SetSize(int32(size.W), int32(size.H))
	noxWindow.SetPosition(int32(pos.X), int32(pos.Y))
}

func setFullScreenMode(size types.Size, pos image.Point) {
	noxWindow.SetResizable(false)
	noxWindow.SetBordered(false)
	setWindowRect(size, pos)
	noxWindow.SetFullscreen(sdl.WINDOW_FULLSCREEN_DESKTOP)
}

func setFullScreenBorderlessMode(size types.Size, pos image.Point) {
	noxWindow.SetFullscreen(0)
	noxWindow.SetResizable(false)
	noxWindow.SetBordered(true)
	setWindowRect(size, pos)
}

func setWindowedMode(size types.Size, pos image.Point) {
	noxWindow.SetFullscreen(0)
	noxWindow.SetResizable(true)
	noxWindow.SetBordered(true)
	setWindowRect(size, pos)
}

func getDisplayDim() (r [4]int) {
	r = [4]int{-1, -1, 0, 0}
	disp, err := noxWindow.GetDisplayIndex()
	if err != nil {
		log.Println("can't get display index: ", err)
		return
	}
	rect, err := sdl.GetDisplayBounds(disp)
	if err != nil {
		log.Println("can't get display bounds: ", err)
		return
	}
	return [4]int{
		int(rect.W),
		int(rect.H),
		int(rect.X),
		int(rect.Y),
	}
}

func setViewport(srcw, srch float32) {
	var (
		ratio              = srcw / srch
		offx               = 0
		offy               = 0
		vpw, vph, vpx, vpy int
	)

	tw, th := noxWindow.GLGetDrawableSize()
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

func initRenderer() error {
	C.g_format = sdl.PIXELFORMAT_RGB555
	if noxRenderer == nil {
		var err error
		noxRenderer, err = sdl.CreateRenderer(noxWindow, 0, sdl.RENDERER_ACCELERATED|sdl.RENDERER_PRESENTVSYNC)
		if err != nil {
			return fmt.Errorf("SDL Renderer context creation failed: %w", err)
		}
	}
	return nil
}

func createSurfaces(width, height int) error {
	surf, err := createSurface(width, height)
	if err != nil {
		return err
	}
	noxBackbuf = surf
	return nil
}

//export nox_video_resetRenderer_48A040
func nox_video_resetRenderer_48A040(width, height, depth C.int) C.int {
	C.g_backbuffer_count = 2
	C.dword_6F7BB0 = 0

	dropRenderer()
	noxBackbuf = nil // TODO: should we release it?

	C.g_surface_973C88 = nil
	C.g_surface_973C60 = nil
	C.dword_973C70 = 0
	C.dword_974854 = 0
	C.dword_6F7B9C = 1
	C.dword_5ACFAC = 1
	if C.nox_video_renderTargetFlags&4 == 0 {
		C.sub_48AA40()
		if err := initRenderer(); err != nil {
			log.Println(err)
			return 0
		}
		if err := createSurfaces(int(width), int(height)); err != nil {
			log.Println(err)
			return 0
		}
	}
	C.dword_6F7BB0 = 1
	C.sub_48A820(1)
	if nox_video_setBackBufSizes_48A3D0() == 0 {
		return 0
	}
	C.sub_48A7F0()
	return 1
}

func nox_video_setBackBufSizes_48A3D0() int {
	C.dword_5d4594_3801780 = 2
	*memmap.PtrUint32(0x5D4594, 3801796) = 0
	if noxBackbuf == nil {
		return 0
	}
	C.nox_backbuffer_width = C.int(noxBackbuf.W)
	C.nox_backbuffer_height = C.int(noxBackbuf.H)
	*memmap.PtrUint32(0x5D4594, 3799564) = uint32(noxBackbuf.Pitch)
	*memmap.PtrUint32(0x5D4594, 3801796) = 1
	nox_video_setBackBufferPtrs_48A190()

	C.nox_backbuffer_width32 = C.int(noxBackbuf.W >> 4)
	*memmap.PtrUint32(0x5D4594, 3801776) = uint32(noxBackbuf.W >> 1)
	C.dword_5d4594_3801780 = 1
	C.nox_backbuffer_pitch_3801808 = 2 * C.int(noxBackbuf.W)
	C.nox_backbuffer_pitchDiff = C.int(noxBackbuf.Pitch - 2*noxBackbuf.W)
	C.dword_5d4594_3799624 = 1
	return 1
}

//export nox_video_free_renderer_48A120
func nox_video_free_renderer_48A120() {
	C.dword_6F7BB0 = 0

	C.sub_48B1D0_free_surface(&C.g_surface_973C60)
	C.sub_48B1D0_free_surface(&C.g_surface_973C88)
	if noxBackbuf != nil {
		noxBackbuf.Free()
		noxBackbuf = nil
	}
	C.sub_48A9C0(0)
	C.sub_48AA40()
	_ = noxRenderer.Destroy()
}

func dropRenderer() {
	if noxRenderer != nil {
		_ = noxRenderer.Destroy()
		noxRenderer = nil
	}
	noxPresentTicks = 0
}

//export sub_48A290_call_present
func sub_48A290_call_present() {
	callPresent()
}

func presentFrame() {
	if noxBackbuf == nil {
		return
	}

	var srect sdl.Rect
	dstw, dsth := noxWindow.GetSize()
	noxBackbuf.GetClipRect(&srect)

	C.nox_video_mouseThreadXxx_48BE50(1)
	C.nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(0, 0)

	setViewport(float32(noxBackbuf.W), float32(noxBackbuf.H))

	// maybe find a way to get the buffer
	tex, err := noxRenderer.CreateTextureFromSurface(noxBackbuf)
	if err != nil {
		panic(err)
	}

	var drect sdl.Rect
	drect.W = dstw
	drect.H = dsth

	if err := noxRenderer.Copy(tex, &srect, &drect); err != nil {
		panic(err)
	}
	noxRenderer.Present()
	_ = tex.Destroy()

	C.nox_video_mouseThreadXxx_48BE50(0)
}

//export nox_video_showMovieFrame
func nox_video_showMovieFrame(s *C.SDL_Surface) {
	surf := (*sdl.Surface)(unsafe.Pointer(s))

	noxBackbuf.SetBlendMode(sdl.BLENDMODE_NONE)
	surf.SetBlendMode(sdl.BLENDMODE_NONE)

	srcRect := surf.ClipRect
	dstRect := noxBackbuf.ClipRect
	if srcRect.W < dstRect.W {
		dstRect.X = (dstRect.W - srcRect.W) / 2
	}
	if srcRect.H < dstRect.H {
		dstRect.Y = (dstRect.H - srcRect.H) / 2
	}
	surf.Blit(&srcRect, noxBackbuf, &dstRect)

	presentFrame()
}

func rect2sdl(r *types.Rect) (sr sdl.Rect) {
	sr.X = int32(r.Left)
	sr.Y = int32(r.Top)
	sr.W = int32(r.Right - r.Left)
	sr.H = int32(r.Bottom - r.Top)
	return
}

func nox_xxx_utilRect_49F930(out, a2, a3 *types.Rect) bool {
	left := a3.Left
	if a2.Left >= a3.Left {
		left = a2.Left
	}
	right := a3.Right
	if a2.Right <= right {
		right = a2.Right
	}
	if left >= right {
		return false
	}
	top := a3.Top
	if a2.Top >= top {
		top = a2.Top
	}
	bottom := a3.Bottom
	if a2.Bottom <= bottom {
		bottom = a2.Bottom
	}
	if top >= bottom {
		return false
	}
	out.Left = left
	out.Top = top
	out.Right = right
	out.Bottom = bottom
	return true
}

//export sdl_drawCursorThreaded
func sdl_drawCursorThreaded(a1 C.int) C.int {
	r1 := (*types.Rect)(memmap.PtrOff(0x5D4594, 1193532))
	r2 := (*types.Rect)(memmap.PtrOff(0x5D4594, 1193548))
	r3 := (*types.Rect)(memmap.PtrOff(0x5D4594, 1193604))
	var v4 types.Rect
	var src, dst sdl.Rect

	if a1 != 0 && (C.dword_5d4594_1193668 != 0 || C.dword_5d4594_1193664 != 0) && !r1.IsEmpty() {
		// FIXME frontbuffer?
		src = rect2sdl(r2)
		dst = rect2sdl(r1)
		// SDL_BlitScaled(g_cursor_surf_6F7C48, &src, g_backbuffer1, &dst)
	}

	r1.Left = int(C.dword_5d4594_1193648) - int(memmap.Uint32(0x5D4594, 1193580))
	r1.Right = r1.Left + int(memmap.Uint32(0x5D4594, 1193600))
	r1.Top = int(C.dword_5d4594_1193524) - int(memmap.Uint32(0x5D4594, 1193636))
	r1.Bottom = r1.Top + int(memmap.Uint32(0x5D4594, 1193620))

	objRect := (*types.Rect)(unsafe.Pointer(&C.obj_5D4594_3800716.data[9]))
	if (a1 == 0 || C.dword_5d4594_1193668 != 0 || C.dword_5d4594_1193664 != 0) && nox_xxx_utilRect_49F930(&v4, r1, objRect) {
		r2.Left = 0
		r2.Top = 0
		r2.Right = v4.Right - v4.Left
		r2.Bottom = v4.Bottom - v4.Top

		// FIXME frontbuffer?
		src = rect2sdl(&v4)
		dst = rect2sdl(r2)
		// if (SDL_BlitScaled(g_backbuffer1, &src, g_cursor_surf_6F7C48, &dst))
		//    return 0;
	}

	if nox_xxx_utilRect_49F930(&v4, r1, objRect) {
		r3.Left = v4.Left - r1.Left
		r3.Top = v4.Top - r1.Top
		r3.Right = v4.Right - r1.Left
		r3.Bottom = v4.Bottom - r1.Top

		// FIXME frontbuffer?
		src = rect2sdl(r3)
		dst = rect2sdl(&v4)

		csurf := (*sdl.Surface)(unsafe.Pointer(C.g_cursor_surf))
		if err := csurf.BlitScaled(&src, noxBackbuf, &dst); err != nil {
			log.Println(err)
			return 0
		}

		*r1 = v4
	}

	C.dword_5d4594_1193664 = 0
	C.dword_5d4594_1193668 = 0
	return 1
}
