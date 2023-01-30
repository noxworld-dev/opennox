package opennox

import (
	"image"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/internal/version"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

var (
	nox_win_legalBg_1522892 *gui.Window
	nox_win_legalBg_timer   int
)

func sub_4CC6F0(win *gui.Window, draw *gui.WindowData) int {
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
	noxClient.r.Data().SetTextColor(noxcolor.RGB5551Color(150, 150, 150))
	noxClient.r.DrawString(nil, "TM", image.Pt(500, 150))
	return 1
}

func nox_xxx_windowMainBGProc_4CC6A0(win *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
	if nox_win_legalBg_timer > 270 {
		return gui.RawEventResp(1)
	}
	switch ev := ev.(type) {
	case *WindowEvent0x4007:
		if ev.Win.ID() == 9901 {
			win.Destroy()
			nox_game_showMainMenu4A1C00()
		}
		return gui.RawEventResp(1)
	default:
		return nil
	}
}

func sub_4CC660(win *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
	if nox_win_legalBg_timer <= 270 {
		ekey, ok := ev.(gui.WindowKeyPress)
		if !ok {
			return nil
		}
		if ekey.Pressed {
			win.Destroy()
			nox_game_showMainMenu4A1C00()
		}
	}
	return gui.RawEventResp(1)
}

func nox_game_showLegal_4CC4E0() {
	win := newWindowFromFile(noxClient.GUI, "legal.wnd", nox_xxx_windowMainBGProc_4CC6A0)
	nox_win_legalBg_1522892 = win
	win.SetAllFuncs(sub_4CC660, nil, nil)
	win.ShowModal()
	v0 := win.ChildByID(9980)
	v8 := legacy.Sub_46AF00(v0)
	v1 := noxClient.r.Fonts.AsFont(legacy.Sub_46AF40(v0))
	v9 := noxClient.r.GetStringSizeWrapped(v1, v8, 640).Y
	v0.SetPos(image.Pt(0, 477-v9))
	vers := version.ClientVersion()
	versText := win.ChildByID(9999)
	if !version.IsDev() && !version.IsLatest() {
		vers += "\n\nRelease " + version.Latest() + " is now available!"
		versText.SetPos(versText.Offs().Add(image.Pt(0, 10)))
	}
	versText.Func94(&gui.StaticTextSetText{Str: vers})
	win.ChildByID(9998).Func94(&gui.StaticTextSetText{Str: " "})
	win.ChildByID(9970).SetDraw(sub_4CC6F0)
	nox_win_legalBg_timer = 300
	if noxflags.HasGame(noxflags.GameFlag26) {
		v6 := win.ChildByID(9901)
		win.Func94(&WindowEvent0x4007{Win: v6})
	}
	legacy.Sub_43D9B0(14, 100)
	nox_client_onShowLegal(win)
}

func nox_client_onShowLegal(win *gui.Window) {
	vers := win.ChildByID(9999)
	draw := vers.DrawData()
	// original version text color is grey, we change it to yellow
	// when the new release is available - highlight with green
	// and if it's a dev build - make the text red
	if version.IsDev() {
		draw.SetTextColor(noxcolor.RGB5551Color(255, 0, 0))
	} else if !version.IsLatest() {
		draw.SetTextColor(noxcolor.RGB5551Color(0, 242, 0))
	} else {
		draw.SetTextColor(noxcolor.RGB5551Color(242, 218, 0))
	}
}
