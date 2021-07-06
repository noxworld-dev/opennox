//+build !server

package main

/*
#include "client__video__draw_common.h"
*/
import "C"
import (
	"errors"
	"fmt"
	"image"
	"unsafe"

	noxcolor "nox/v1/common/color"
	"nox/v1/common/log"
	"nox/v1/common/memmap"
	"nox/v1/common/types"

	"github.com/veandco/go-sdl2/sdl"
)

var (
	noxWindow            *sdl.Window
	noxRenderer          *sdl.Renderer
	noxBackbuf           *sdl.Surface
	g_cursor_surf        *sdl.Surface
	g_cursor_surf_6F7C48 *sdl.Surface
	g_surface_973C60     *sdl.Surface
	g_surface_973C88     *sdl.Surface
	noxViewport          sdl.Rect
	noxViewRotate        bool
	noxViewRotated       bool
)

//export nox_video_setWinTitle_401FE0
func nox_video_setWinTitle_401FE0(title *C.char) {
	noxWindow.SetTitle(C.GoString(title))
}

func sub_48B1D0_free_surface(p **sdl.Surface) {
	if s := *p; s != nil {
		s.Free()
		*p = nil
	}
}

func createSurface(w, h int) (*sdl.Surface, error) {
	return sdl.CreateRGBSurfaceWithFormat(0, int32(w), int32(h), 16, sdl.PIXELFORMAT_RGB555)
}

//export nox_video_getSurfaceData_48A720
func nox_video_getSurfaceData_48A720(s unsafe.Pointer, outPitch *C.int, outPixels *unsafe.Pointer) C.int {
	surf := (*sdl.Surface)(unsafe.Pointer(s))
	if outPitch != nil {
		*outPitch = C.int(surf.Pitch)
	}
	if outPixels != nil {
		*outPixels = surf.Data()
	}
	return 0
}

func nox_video_copyBackBuffer3_4AD1E0() {
	if dword_973C70 != 0 {
		return
	}

	width := int(noxBackbuf.W)
	height := int(noxBackbuf.H)

	if noxBackbuf.Lock() != nil {
		return
	}
	defer noxBackbuf.Unlock()

	dpix := asU16Slice(noxBackbuf.Data(), int(noxBackbuf.Pitch*noxBackbuf.H)/2)
	pitch := int(noxBackbuf.Pitch)
	for y := 0; y < height; y++ {
		row := asU16Slice(nox_pixbuffer_rows_3798784_arr[y], width)
		drow := dpix[y*pitch/2 : (y+1)*pitch/2]
		copy(drow, row[:width])
	}
	*memmap.PtrUint32(0x5D4594, 3798652)++
}

//export nox_video_setBackBufferPtrs_48A190
func nox_video_setBackBufferPtrs_48A190() {
	C.nox_backbuffer1_pix = noxBackbuf.Data()
	C.nox_backbuffer_pix = C.nox_backbuffer1_pix
}

//export nox_video_lockSurface_48A670
func nox_video_lockSurface_48A670(s unsafe.Pointer) {
	surf := (*sdl.Surface)(unsafe.Pointer(s))
	_ = surf.Lock()
}

//export nox_video_unlockSurface_48A6B0
func nox_video_unlockSurface_48A6B0(s unsafe.Pointer) {
	surf := (*sdl.Surface)(unsafe.Pointer(s))
	surf.Unlock()
}

func nox_video_copyBackBuffer_4AD2A0() {
	// FIXME unlocked surfaces
	if dword_973C70 != 0 {
		return
	}
	width32 := nox_backbuffer_width32
	width := width32 * 32
	pitch := width + nox_backbuffer_pitchDiff
	height := nox_backbuffer_height

	dst := asByteSlice(unsafe.Pointer(C.nox_backbuffer_pix), height*width)
	for y := 0; y < height; y++ {
		row := asByteSlice(nox_pixbuffer_rows_3798784_arr[y], width32*32)
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

	sz := videoGetWindowSize()
	win, err := sdl.CreateWindow("OpenNox "+ClientVersionString(), sdl.WINDOWPOS_UNDEFINED, sdl.WINDOWPOS_UNDEFINED,
		int32(sz.W), int32(sz.H), sdl.WINDOW_RESIZABLE)
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
	noxWindow.SetSize(int32(size.W), int32(size.H))
	noxWindow.SetPosition(int32(pos.X), int32(pos.Y))
}

func setFullScreenMode(size types.Size, pos image.Point) {
	noxBorderless = false
	noxWindow.SetResizable(false)
	noxWindow.SetBordered(false)
	setWindowRect(size, pos)
	noxWindow.SetFullscreen(sdl.WINDOW_FULLSCREEN_DESKTOP)
	sdl.ShowCursor(sdl.DISABLE)
}

func setFullScreenBorderlessMode(size types.Size, pos image.Point) {
	noxBorderless = true
	noxWindow.SetFullscreen(0)
	noxWindow.SetResizable(false)
	noxWindow.SetBordered(true)
	setWindowRect(size, pos)
	sdl.ShowCursor(sdl.DISABLE)
}

func setWindowedMode(size types.Size, pos image.Point) {
	noxWindow.SetFullscreen(0)
	noxWindow.SetResizable(true)
	noxWindow.SetBordered(true)
	setWindowRect(size, pos)
	sdl.ShowCursor(sdl.ENABLE)
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

func setViewport(srcw, srch, tw, th int) sdl.Rect {
	var (
		ratio              = float32(srcw) / float32(srch)
		offx               = 0
		offy               = 0
		vpw, vph, vpx, vpy int
	)

	vpw, vph = tw, th

	// Maintain source aspect ratio
	if noxViewRotate && float32(vph)-ratio*float32(vpw) > float32(vpw)-ratio*float32(vph) {
		noxViewRotated = true
	} else {
		noxViewRotated = false
	}
	if noxViewRotated {
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
	return sdl.Rect{
		X: int32(vpx),
		Y: int32(vpy),
		W: int32(vpw),
		H: int32(vph),
	}
}

func initRenderer() error {
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

func resetRenderer(width, height int) error {
	dword_6F7BB0 = 0

	dropRenderer()
	noxBackbuf = nil // TODO: should we release it?

	g_surface_973C88 = nil
	g_surface_973C60 = nil
	dword_973C70 = 0
	dword_974854 = 0
	if C.nox_video_renderTargetFlags&4 == 0 {
		if err := initRenderer(); err != nil {
			return err
		}
		if err := createSurfaces(width, height); err != nil {
			return err
		}
	}
	dword_6F7BB0 = 1
	//sub_48A820(1)
	if nox_video_setBackBufSizes_48A3D0() == 0 {
		return errors.New("nox_video_setBackBufSizes_48A3D0 failed")
	}
	//sub_48A7F0()
	return nil
}

func nox_video_setBackBufSizes_48A3D0() int {
	C.dword_5d4594_3801780 = 2
	*memmap.PtrUint32(0x5D4594, 3801796) = 0
	if noxBackbuf == nil {
		return 0
	}
	nox_backbuffer_width = int(noxBackbuf.W)
	nox_backbuffer_height = int(noxBackbuf.H)
	*memmap.PtrUint32(0x5D4594, 3799564) = uint32(noxBackbuf.Pitch)
	*memmap.PtrUint32(0x5D4594, 3801796) = 1
	nox_video_setBackBufferPtrs_48A190()

	nox_backbuffer_width32 = int(noxBackbuf.W >> 4)
	*memmap.PtrUint32(0x5D4594, 3801776) = uint32(noxBackbuf.W >> 1)
	C.dword_5d4594_3801780 = 1
	nox_backbuffer_pitch_3801808 = 2 * int(noxBackbuf.W)
	nox_backbuffer_pitchDiff = int(noxBackbuf.Pitch - 2*noxBackbuf.W)
	C.dword_5d4594_3799624 = 1
	return 1
}

//export nox_video_free_renderer_48A120
func nox_video_free_renderer_48A120() {
	dword_6F7BB0 = 0

	sub_48B1D0_free_surface(&g_surface_973C60)
	sub_48B1D0_free_surface(&g_surface_973C88)
	if noxBackbuf != nil {
		noxBackbuf.Free()
		noxBackbuf = nil
	}
	nox_video_minimizeOrMaximize_48A9C0(0)
	_ = noxRenderer.Destroy()
}

func dropRenderer() {
	if noxRenderer != nil {
		_ = noxRenderer.Destroy()
		noxRenderer = nil
	}
	noxPresentTicks = 0
}

func presentFrame() {
	if noxBackbuf == nil {
		return
	}

	dstw, dsth := noxWindow.GetSize()
	var srect sdl.Rect
	noxBackbuf.GetClipRect(&srect)

	nox_video_mouseThreadXxx_48BE50(true)
	defer nox_video_mouseThreadXxx_48BE50(false)
	nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(0, 0)

	drect := setViewport(int(noxBackbuf.W), int(noxBackbuf.H), int(dstw), int(dsth))
	if drect != noxViewport {
		noxViewport = drect
		inpHandler.SetWinSize(types.Size{W: int(noxViewport.W), H: int(noxViewport.H)}, image.Pt(int(noxViewport.X), int(noxViewport.Y)))
	}

	// maybe find a way to get the buffer
	tex, err := noxRenderer.CreateTextureFromSurface(noxBackbuf)
	if err != nil {
		panic(err)
	}
	if err := noxRenderer.Clear(); err != nil {
		panic(err)
	}
	if err := noxRenderer.Copy(tex, &srect, &noxViewport); err != nil {
		panic(err)
	}
	noxRenderer.Present()
	_ = tex.Destroy()
}

func nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(a1, a2 int) int {
	if memmap.Uint32(0x5D4594, 1193708) == 0 && nox_video_drawCursorThreadOk && C.dword_5d4594_823776 != 0 &&
		nox_video_cursorDrawIsThreaded && C.dword_5d4594_1193672 != 0 && memmap.Uint32(0x5D4594, 1193108) != 0 && C.nox_video_bag_ready != 0 {
		*memmap.PtrUint32(0x5D4594, 1193708) = 1
		mu := asMutex(memmap.PtrOff(0x5D4594, 3799596))
		mu.Lock()
		res := sdl_drawCursorThreaded(a1) // FIXME SDL will always wait for vblank?
		mu.Unlock()
		*memmap.PtrUint32(0x5D4594, 1193708) = 0
		return res
	}
	return 0
}

func nox_video_mouseThreadXxx_48BE50(a1 bool) {
	if nox_video_drawCursorThreadOk && nox_video_cursorDrawIsThreaded {
		nox_video_pauseThreadedDrawCursor = a1
	}
}

//export nox_video_showMovieFrame
func nox_video_showMovieFrame(s unsafe.Pointer) {
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

func sdl_drawCursorThreaded(a1 int) int {
	r1 := (*types.Rect)(memmap.PtrOff(0x5D4594, 1193532))
	r2 := (*types.Rect)(memmap.PtrOff(0x5D4594, 1193548))
	r3 := (*types.Rect)(memmap.PtrOff(0x5D4594, 1193604))
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

	objRect := *(*types.Rect)(unsafe.Pointer(&C.obj_5D4594_3800716.data[9]))
	if a1 == 0 || C.dword_5d4594_1193668 != 0 || C.dword_5d4594_1193664 != 0 {
		if v4, ok := nox_xxx_utilRect_49F930(*r1, objRect); ok {
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
	}

	if v4, ok := nox_xxx_utilRect_49F930(*r1, objRect); ok {
		r3.Left = v4.Left - r1.Left
		r3.Top = v4.Top - r1.Top
		r3.Right = v4.Right - r1.Left
		r3.Bottom = v4.Bottom - r1.Top

		// FIXME frontbuffer?
		src = rect2sdl(r3)
		dst = rect2sdl(&v4)

		if err := g_cursor_surf.BlitScaled(&src, noxBackbuf, &dst); err != nil {
			log.Println(err)
			return 0
		}

		*r1 = v4
	}

	C.dword_5d4594_1193664 = 0
	C.dword_5d4594_1193668 = 0
	return 1
}

//export nox_xxx_makeFillerColor_48BDE0
func nox_xxx_makeFillerColor_48BDE0() C.bool {
	v0 := noxcolor.ExtendColor16(noxcolor.RGBColor(255, 0, 255))
	*memmap.PtrUint32(0x5D4594, 1193592) = uint32(v0)
	if g_cursor_surf != nil {
		// FIXME use SDL_MapRGB instead?
		var v uint32
		if C.dword_5d4594_3799624 != 0 {
			v = uint32(uint16(v0))
		} else {
			v = uint32(uint8(v0))
		}
		g_cursor_surf.SetColorKey(true, v)
	}
	return true
}

func nox_video_minimizeOrMaximize_48A9C0(a1 int) {
	if dword_6F7BB0 == 0 {
		return
	}
	mu := asMutex(memmap.PtrOff(0x5D4594, 3799596))
	mu.Lock()
	defer mu.Unlock()

	if dword_974854 != 0 {
		return
	}

	if C.nox_video_renderTargetFlags&0x10 != 0 {
		dword_974854 = 1
		log.Println("Ungrab")
		noxWindow.SetGrab(false)
		return
	}
	if a1 != 0 {
		dword_974854 = 1
		dword_973C70 = 1
		log.Println("Minimize")
		windowMinimize()
	}
}

func windowMinimize() {
	noxWindow.Minimize()
}
