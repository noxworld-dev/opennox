//+build !server

package main

/*
#include "client__video__draw_common.h"
extern unsigned int nox_game_loop_xxx_805872;
*/
import "C"
import (
	"errors"
	"unsafe"

	"nox/v1/client/render"
	noxcolor "nox/v1/common/color"
	"nox/v1/common/memmap"
	"nox/v1/common/types"
)

func clientDraw() bool {
	return nox_xxx_client_435F80_draw(inpHandlerS)
}

func getBackbufWidth() int {
	return noxRendererS.RenderMode().Width
}

func getBackbufHeight() int {
	return noxRendererS.RenderMode().Height
}

func nox_video_copyBackBuffer3_4AD1E0() {
	sz := noxRendererS.BufferSize()
	width := sz.W
	height := sz.H

	pixbuf := asPtrSlice(unsafe.Pointer(C.nox_pixbuffer_rows_3798784), height)
	rows := make([][]byte, height)
	for i := range rows {
		rows[i] = asByteSlice(pixbuf[i], width*2)
	}
	noxRendererS.CopyBufferRows(rows)

	*memmap.PtrUint32(0x5D4594, 3798652)++
}

func nox_video_setBackBufferPtrs_48A190() {
	C.nox_backbuffer1_pix = noxRendererS.BufferData()
	C.nox_backbuffer_pix = C.nox_backbuffer1_pix
}

//export sub_444D00
func sub_444D00() {
	mu := asMutex(memmap.PtrOff(0x5D4594, 3799596))
	mu.Lock()
	defer mu.Unlock()
	nox_video_setBackBufferPtrs_48A190()
	nox_video_setBackBufferCopyFunc2_4AD150()
}

func nox_video_copyBackBuffer_4AD2A0() {
	// FIXME unlocked surfaces
	width32 := nox_backbuffer_width32
	width := width32 * 32
	pitch := width + nox_backbuffer_pitchDiff
	height := noxRendererS.BufferSize().H

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

func resetRenderer(sz types.Size) error {
	if C.nox_video_renderTargetFlags&4 == 0 {
		if err := noxRendererS.Reset(sz); err != nil {
			return err
		}
	}
	//sub_48A820(1)
	if nox_video_setBackBufSizes_48A3D0(sz) == 0 {
		return errors.New("nox_video_setBackBufSizes_48A3D0 failed")
	}
	//sub_48A7F0()
	return nil
}

func gameResetVideoMode(inMenu, force bool) error {
	var mode render.Mode
	if inMenu {
		if debugMainloop {
			videoLog.Printf("gameUpdateVideoMode: menu (%s)", caller(1))
		}
		mode = videoGetMenuMode()
	} else {
		if debugMainloop {
			videoLog.Printf("gameUpdateVideoMode: game (%s)", caller(1))
		}
		mode = videoGetGameMode()
	}
	videoLog.Printf("mode switch: %+v (menu: %v)", mode, inMenu)
	videoResizeView(mode)
	C.nox_game_loop_xxx_805872 = 0
	cur := noxRendererS.RenderMode()
	if !force && mode == cur {
		return nil
	}
	if mode.Depth != cur.Depth {
		if C.nox_video_bagMaybeReload(C.int(bool2int(videoIs16Bit()))) == 0 {
			return errors.New("nox_video_bagMaybeReload failed")
		}
	}
	if err := recreateBuffersAndTarget(); err != nil {
		return err
	}
	C.nox_xxx_loadPal_4A96C0_video_read_palette(internCStr("default.pal"))
	C.sub_461520()
	return nil
}

func nox_video_setBackBufSizes_48A3D0(sz types.Size) int {
	pitch := noxRendererS.BufferPitch()
	C.dword_5d4594_3801780 = 2
	*memmap.PtrUint32(0x5D4594, 3801796) = 0

	*memmap.PtrUint32(0x5D4594, 3799564) = uint32(pitch)
	*memmap.PtrUint32(0x5D4594, 3801796) = 1
	nox_video_setBackBufferPtrs_48A190()

	nox_backbuffer_width32 = sz.W >> 4
	*memmap.PtrUint32(0x5D4594, 3801776) = uint32(sz.W >> 1)
	C.dword_5d4594_3801780 = 1
	nox_backbuffer_pitch_3801808 = 2 * int(sz.W)
	nox_backbuffer_pitchDiff = pitch - 2*sz.W
	C.dword_5d4594_3799624 = 1
	return 1
}

//export nox_video_getSurfaceData_48A720
func nox_video_getSurfaceData_48A720(s unsafe.Pointer, outPitch *C.int, outPixels *unsafe.Pointer) C.int {
	panic("TODO")
}

//export nox_video_showMovieFrame
func nox_video_showMovieFrame(s unsafe.Pointer) {
	panic("TODO")
	//surf := (*sdl.Surface)(unsafe.Pointer(s))
	//noxBackbuf.SetBlendMode(sdl.BLENDMODE_NONE)
	//surf.SetBlendMode(sdl.BLENDMODE_NONE)
	//
	//srcRect := surf.ClipRect
	//dstRect := noxBackbuf.ClipRect
	//if srcRect.W < dstRect.W {
	//	dstRect.X = (dstRect.W - srcRect.W) / 2
	//}
	//if srcRect.H < dstRect.H {
	//	dstRect.Y = (dstRect.H - srcRect.H) / 2
	//}
	//surf.Blit(&srcRect, noxBackbuf, &dstRect)
	//
	//presentFrame()
}

//export nox_xxx_makeFillerColor_48BDE0
func nox_xxx_makeFillerColor_48BDE0() C.bool {
	v0 := noxcolor.ExtendColor16(noxcolor.RGBColor(255, 0, 255))
	*memmap.PtrUint32(0x5D4594, 1193592) = v0
	return true
}
