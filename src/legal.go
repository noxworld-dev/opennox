package opennox

/*
#include "GAME1_3.h"
#include "GAME2_1.h"
#include "client__gui__window.h"
*/
import "C"
import (
	"image"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/internal/version"
)

var (
	nox_win_legalBg_1522892 *Window
	nox_win_legalBg_timer   int
)

func sub_4CC6F0(win *Window, draw *WindowData) int {
	nox_win_legalBg_timer--
	if nox_win_legalBg_timer < 0 {
		nox_win_legalBg_1522892.Destroy()
		nox_win_legalBg_1522892 = nil
		nox_game_showMainMenu4A1C00()
	}
	if nox_win_legalBg_timer < 270 {
		v0 := nox_win_legalBg_1522892.ChildByID(9910)
		v0.Show()
	}
	noxrend.Data().SetTextColor(noxrender.ColorRGB(150, 150, 150))
	noxrend.DrawString(nil, "TM", image.Pt(500, 150))
	return 1
}

func nox_xxx_windowMainBGProc_4CC6A0(win *Window, ev WindowEvent) WindowEventResp {
	if nox_win_legalBg_timer > 270 {
		return RawEventResp(1)
	}
	switch ev := ev.(type) {
	case *WindowEvent0x4007:
		if ev.Win.ID() == 9901 {
			win.Destroy()
			nox_game_showMainMenu4A1C00()
		}
		return RawEventResp(1)
	default:
		return nil
	}
}

func sub_4CC660(win *Window, ev WindowEvent) WindowEventResp {
	if nox_win_legalBg_timer <= 270 {
		ekey, ok := ev.(WindowKeyPress)
		if !ok {
			return nil
		}
		if ekey.Pressed {
			win.Destroy()
			nox_game_showMainMenu4A1C00()
		}
	}
	return RawEventResp(1)
}

func nox_game_showLegal_4CC4E0() {
	win := newWindowFromFile("legal.wnd", nox_xxx_windowMainBGProc_4CC6A0)
	nox_win_legalBg_1522892 = win
	win.SetAllFuncs(sub_4CC660, nil, nil)
	nox_xxx_wndShowModalMB(win)
	v0 := win.ChildByID(9980)
	v8 := GoWString(C.sub_46AF00(unsafe.Pointer(v0.C())))
	v1 := asFont(C.sub_46AF40(unsafe.Pointer(v0.C())))
	v9 := noxrend.GetStringSizeWrapped(v1, v8, 640).Y
	v0.SetPos(image.Pt(0, 477-v9))
	vers := version.ClientVersion()
	versText := win.ChildByID(9999)
	if !version.IsDev() && !version.IsLatest() {
		vers += "\n\nRelease " + version.Latest() + " is now available!"
		versText.SetPos(versText.Offs().Add(image.Pt(0, 10)))
	}
	versText.Func94(&WindowEvent0x4001{Str: vers})
	win.ChildByID(9998).Func94(&WindowEvent0x4001{Str: " "})
	win.ChildByID(9970).setDraw(sub_4CC6F0)
	nox_win_legalBg_timer = 300
	if noxflags.HasGame(noxflags.GameFlag26) {
		v6 := win.ChildByID(9901)
		win.Func94(&WindowEvent0x4007{Win: v6})
	}
	C.sub_43D9B0(14, 100)
	nox_client_onShowLegal(win)
}

func nox_client_onShowLegal(win *Window) {
	vers := win.ChildByID(9999)
	draw := vers.DrawData()
	// original version text color is grey, we change it to yellow
	// when the new release is available - highlight with green
	// and if it's a dev build - make the text red
	if version.IsDev() {
		draw.SetTextColor(noxcolor.RGBColor(255, 0, 0))
	} else if !version.IsLatest() {
		draw.SetTextColor(noxcolor.RGBColor(0, 242, 0))
	} else {
		draw.SetTextColor(noxcolor.RGBColor(242, 218, 0))
	}
}
