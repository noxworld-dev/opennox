//go:build !server

package opennox

/*
#include "GAME1_3.h"
#include "GAME2_1.h"
#include "GAME3.h"
void sub_431290();
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

func (c *Client) drawGeneral(a1 bool) error {
	dword_5d4594_1311936 = true
	*memmap.PtrUint32(0x5D4594, 1311932) = uint32(bool2int(a1))
	// FIXME
	v1 := false
	videoLog.Println("DrawGeneralStart")
	if /*noxflags.HasEngine(noxflags.EngineWindowed) ||*/ v1 /*|| nox_video_renderTargetFlags&0x10 != 0*/ {
		videoLog.Println("DrawGeneralSkip")
		sub_4B05D0()
		return nil
	}
	C.sub_431290()
	C.sub_43DBD0()
	sub_44D8F0()
	for C.sub_43DC40() != 0 || sub_44D930() {
		c.sub4312C0()
	}
	sub_43E8E0(0)
	v12 := sub_48B3E0(false)
	//inpHandler.UnacquireMouse()

	c.playMovieFile(movieFilesStack[0])

	sub_43E910(0)
	C.sub_43DBE0()
	//inpHandler.AcquireMouse()
	sub_48B3E0(v12)
	sub_4B05D0()
	return nil
}

func (c *Client) playMovieFile(name string) {
	videoLog.Printf("playMovieFile: %q", name)
	if f, err := ifs.Open(name); err == nil {
		defer f.Close()
		if plr, err := noxmovie.NewPlayerWithHandle(f, noxClient.seat, audioDev); err == nil {
			defer plr.Close()
			plr.Start()
			plr.Play()
		}
	}
}

func (c *Client) clientDraw() bool {
	return c.nox_xxx_client_435F80_draw()
}

func (c *Client) copyPixBuffer() {
	c.win.CopyBuffer(noxPixBuffer.img)
	*memmap.PtrUint32(0x973A20, 496)++
}

func (c *Client) resetRenderer(sz image.Point, init bool) error {
	if nox_video_renderTargetFlags&4 == 0 && !init {
		if err := c.win.Reset(sz); err != nil {
			return err
		}
	}
	if nox_video_setBackBufSizes_48A3D0(sz) == 0 {
		return errors.New("nox_video_setBackBufSizes_48A3D0 failed")
	}
	return nil
}

func (c *Client) gameResetVideoMode(inMenu, force bool) error {
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
		mode = c.videoGetGameMode()
	}
	videoLog.Printf("mode switch: %+v (menu: %v)", mode, inMenu)
	videoResizeView(mode)
	if !force && mode == noxPixBuffer.img.Size() {
		return nil
	}
	if err := recreateBuffersAndTarget(mode); err != nil {
		return err
	}
	c.nox_xxx_loadPal_4A96C0_video_read_palette()
	C.sub_461520()
	return nil
}

func (c *Client) nox_xxx_loadPal_4A96C0_video_read_palette() {
	nox_xxx_loadDefColor_4A94A0()
	for i := 0; i < 6; i++ {
		c.r.Data().SetMaterial(i, color.White)
	}
}

func sub_43C060() bool {
	noxClient.nox_xxx_loadPal_4A96C0_video_read_palette()
	C.nox_xxx_wndLoadBorder_4AA1F0()
	nox_xxx_wndLoadMainBG_4A2210()
	nox_client_setCursorType(gui.CursorSelect)
	sub_48B3E0(true)
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
