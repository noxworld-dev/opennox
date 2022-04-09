//go:build !server
// +build !server

package opennox

/*
#include "GAME2_1.h"
#include "GAME3.h"
#include "client__video__draw_common.h"
*/
import "C"
import (
	"errors"
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func clientDraw() bool {
	return nox_xxx_client_435F80_draw(inpHandlerS)
}

func copyPixBuffer() {
	noxRendererS.CopyBuffer(noxPixBuffer.img)
	*memmap.PtrUint32(0x973A20, 496)++
}

//export sub_444D00
func sub_444D00() {
	mu := asMutex(memmap.PtrOff(0x973F18, 168))
	mu.Lock()
	defer mu.Unlock()
	nox_video_setBackBufferCopyFunc2_4AD150()
}

func resetRenderer(sz image.Point, init bool) error {
	if C.nox_video_renderTargetFlags&4 == 0 && !init {
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
	var mode image.Point
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
	if !force && mode == noxPixBuffer.img.Size() {
		return nil
	}
	if err := recreateBuffersAndTarget(mode); err != nil {
		return err
	}
	C.nox_xxx_loadPal_4A96C0_video_read_palette(internCStr("default.pal"))
	C.sub_461520()
	return nil
}

func nox_video_setBackBufSizes_48A3D0(sz image.Point) int {
	*memmap.PtrUint32(0x973F18, 2368) = 0

	*memmap.PtrUint32(0x973F18, 136) = uint32(2 * sz.X)
	*memmap.PtrUint32(0x973F18, 2368) = 1

	*memmap.PtrUint32(0x973F18, 2348) = uint32(sz.X / 2)
	C.nox_video_modeXxx_3801780 = 1
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
