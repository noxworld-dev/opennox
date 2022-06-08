//go:build !server

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
	"image/color"

	"github.com/noxworld-dev/opennox-lib/ifs"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxmovie"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func playMovieFile(name string) {
	videoLog.Printf("playMovieFile: %q", name)
	if f, err := ifs.Open(name); err == nil {
		defer f.Close()
		if plr, err := noxmovie.NewPlayerWithHandle(f, noxSeat, audioDev); err == nil {
			defer plr.Close()
			plr.Start()
			plr.Play()
		}
	}
}

func clientDraw() bool {
	return nox_xxx_client_435F80_draw(inpHandlerS)
}

func copyPixBuffer() {
	noxRendererS.CopyBuffer(noxPixBuffer.img)
	*memmap.PtrUint32(0x973A20, 496)++
}

func resetRenderer(sz image.Point, init bool) error {
	if nox_video_renderTargetFlags&4 == 0 && !init {
		if err := noxRendererS.Reset(sz); err != nil {
			return err
		}
	}
	if nox_video_setBackBufSizes_48A3D0(sz) == 0 {
		return errors.New("nox_video_setBackBufSizes_48A3D0 failed")
	}
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
	nox_xxx_loadPal_4A96C0_video_read_palette()
	C.sub_461520()
	return nil
}

func nox_xxx_loadPal_4A96C0_video_read_palette() {
	nox_xxx_loadDefColor_4A94A0()
	for i := 0; i < 6; i++ {
		noxrend.Data().SetMaterial(i, color.White)
	}
}

func sub_43C060() bool {
	nox_xxx_loadPal_4A96C0_video_read_palette()
	C.nox_xxx_wndLoadBorder_4AA1F0()
	nox_xxx_wndLoadMainBG_4A2210()
	nox_client_setCursorType(gui.CursorSelect)
	C.sub_48B3E0(1)
	nox_video_stopAllFades_44E040()
	C.sub_43E8C0(0)
	return C.nox_xxx_compassGenStrings_4A9C80() != 0
}

func nox_video_setBackBufSizes_48A3D0(sz image.Point) int {
	*memmap.PtrUint32(0x973F18, 2368) = 0

	*memmap.PtrUint32(0x973F18, 136) = uint32(2 * sz.X)
	*memmap.PtrUint32(0x973F18, 2368) = 1

	*memmap.PtrUint32(0x973F18, 2348) = uint32(sz.X / 2)
	return 1
}
