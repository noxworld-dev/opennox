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

	rows := make([][]byte, height)
	for i := range rows {
		rows[i] = asByteSlice(nox_pixbuffer_main_rows[i], width*2)
	}
	noxRendererS.CopyBufferRows(rows)

	*memmap.PtrUint32(0x973A20, 496)++
}

//export sub_444D00
func sub_444D00() {
	mu := asMutex(memmap.PtrOff(0x973F18, 168))
	mu.Lock()
	defer mu.Unlock()
	nox_video_setBackBufferCopyFunc2_4AD150()
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
	C.dword_5d4594_3801780 = 2
	*memmap.PtrUint32(0x973F18, 2368) = 0

	*memmap.PtrUint32(0x973F18, 136) = uint32(2 * sz.W)
	*memmap.PtrUint32(0x973F18, 2368) = 1

	nox_backbuffer_width32 = sz.W >> 4
	*memmap.PtrUint32(0x973F18, 2348) = uint32(sz.W >> 1)
	C.dword_5d4594_3801780 = 1
	C.dword_5d4594_3799624 = 1
	return 1
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
