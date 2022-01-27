package nox

/*
#include "client__gui__window.h"
extern unsigned int nox_video_dxUnlockSurface;
extern unsigned int nox_client_drawFrontWalls_80812;
extern unsigned int nox_client_translucentFrontWalls_805844;
extern unsigned int nox_client_highResFrontWalls_80820;
extern unsigned int nox_client_highResFloors_154952;
extern unsigned int nox_client_lockHighResFloors_1193152;
extern unsigned int nox_client_texturedFloors_154956;
extern unsigned int nox_gui_console_translucent;
extern unsigned int nox_client_renderGlow_805852;
extern unsigned int nox_client_fadeObjects_80836;
extern unsigned int nox_client_renderBubbles_80844;
extern unsigned int nox_client_renderGUI_80828;
extern unsigned int nox_client_showTooltips_80840;
extern unsigned int nox_xxx_xxxRenderGUI_587000_80832;
extern unsigned int nox_client_texturedFloors2_154960;
extern unsigned int dword_5d4594_1193156;
extern unsigned int dword_5d4594_1301812;
extern unsigned int dword_5d4594_1301816;
extern unsigned int dword_5d4594_1301808;
extern unsigned int dword_5d4594_1301796;
int nox_client_advVideoOptsProc_4CB5D0(void* a1, int a2, void* a3, int a4);
int nox_xxx_tileSetDrawFn_481420();
*/
import "C"
import (
	"unsafe"

	"nox/v1/client/gui"
	"nox/v1/client/noxfont"
	noxcolor "nox/v1/common/color"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/strman"
)

var (
	nox_win_advVideoOpts_1522600 *Window
	noxVideoAdvOpts              = make(map[uint]*videoOpt)
)

//export nox_client_advVideoOpts_New_4CB590
func nox_client_advVideoOpts_New_4CB590(par *C.nox_window) C.int {
	nox_win_advVideoOpts_1522600 = newAdvVideoOpts(strMan)
	sub46B120(nox_win_advVideoOpts_1522600, asWindow(par))
	nox_client_advVideoOptsLoad(nox_win_advVideoOpts_1522600)
	return 1
}

type videoOpt struct {
	ID     uint
	Flag   noxflags.EngineFlag
	CFlag  *C.uint
	TextID strman.ID
	Text   string
	Get    func() bool
	Toggle func()
	Def    bool
	Hidden bool
}

var noxVideoAdvOptsList = []*videoOpt{
	{ID: 2051, Get: getFiltering, Toggle: toggleFiltering, Text: "Smooth image", TextID: "AdVidOpt.wnd:Filtering"},
	{ID: 2050, Get: getScaled, Toggle: toggleScaled, Text: "Stretch image", TextID: "AdVidOpt.wnd:Stretched"},
	{ID: 2010, CFlag: &C.nox_video_dxUnlockSurface, TextID: "AdVidOpt.wnd:ClipWalls", Def: true, Hidden: true},
	{ID: 2012, Flag: noxflags.EngineSoftShadowEdge, TextID: "AdVidOpt.wnd:GouradShading"},
	{ID: 2014, CFlag: &C.nox_gui_console_translucent, TextID: "AdVidOpt.wnd:TranslucentConsole"},
	{ID: 2015, CFlag: &C.nox_client_renderGlow_805852, TextID: "AdVidOpt.wnd:RenderGlow"},
	{ID: 2016, CFlag: &C.nox_client_fadeObjects_80836, TextID: "AdVidOpt.wnd:FadeObjects"},
	{ID: 2017, CFlag: &C.nox_client_showTooltips_80840, TextID: "AdVidOpt.wnd:ShowTooltips"},
	{ID: 2020, CFlag: &C.nox_client_drawFrontWalls_80812, TextID: "AdVidOpt.wnd:DrawFrontWalls"},
	{ID: 2021, CFlag: &C.nox_client_translucentFrontWalls_805844, TextID: "AdVidOpt.wnd:TranslucentFrontWalls"},
	{ID: 2022, CFlag: &C.nox_client_highResFrontWalls_80820, TextID: "AdVidOpt.wnd:InterlacedFrontWalls"},
	{ID: 2031, CFlag: &C.nox_client_highResFloors_154952, TextID: "AdVidOpt.wnd:InterlacedFloors"},
	{ID: 2032, CFlag: &C.nox_client_lockHighResFloors_1193152, TextID: "AdVidOpt.wnd:LockHiResFloors"},
	{ID: 2033, CFlag: &C.nox_client_texturedFloors2_154960, TextID: "AdVidOpt.wnd:FlatShadedFloors"},
	{ID: 2041, CFlag: &C.nox_client_renderBubbles_80844, TextID: "AdVidOpt.wnd:RenderBubbles"},
	{ID: 2040, CFlag: &C.nox_client_renderGUI_80828, TextID: "AdVidOpt.wnd:RenderGUI"},
}

func init() {
	for _, opt := range noxVideoAdvOptsList {
		registerVideoOpt(opt)
	}
}

func registerVideoOpt(opt *videoOpt) {
	if opt.ID == 0 {
		panic("ID must be set")
	}
	noxVideoAdvOpts[opt.ID] = opt
}

//export nox_client_advVideoOptsLoad_4CB330
func nox_client_advVideoOptsLoad_4CB330() {
	nox_client_advVideoOptsLoad(nox_win_advVideoOpts_1522600)
}

func nox_client_advVideoOptsLoad(win *Window) {
	for id, opt := range noxVideoAdvOpts {
		if w := win.ChildByID(id); w != nil {
			v := opt.Def
			if opt.Get != nil {
				v = opt.Get()
			} else if opt.Flag != 0 {
				v = noxflags.HasEngine(opt.Flag)
			} else if opt.CFlag != nil {
				v = *opt.CFlag != 0
			}
			w.DrawData().Field0Set(0x4, v)
		}
	}
}

func sub_49B3C0() {
	C.dword_5d4594_1301812 = 0
	C.dword_5d4594_1301816 = 0
	C.dword_5d4594_1301808 = 0
	C.dword_5d4594_1301796 = 0
}

func nox_client_advVideoOptsProc_4CB5D0(win *Window, e WindowEvent) WindowEventResp {
	ev, a3, _ := e.EventArgsC()
	if ev == 0x4005 {
		clientPlaySoundSpecial(920, 100)
		return RawEventResp(1)
	}
	if ev != 0x4007 {
		return nil
	}
	targ := asWindowP(unsafe.Pointer(a3))
	clientPlaySoundSpecial(766, 100)
	id := targ.ID()
	switch id {
	case 2010:
		// always enabled
		C.nox_video_dxUnlockSurface = 1
		win.DrawData().Field0Set(0x4, true)
		return nil
	case 2033:
		v := C.nox_client_texturedFloors2_154960 != 0
		C.nox_client_texturedFloors2_154960 = C.uint(bool2int(!v))
		C.nox_client_texturedFloors_154956 = C.uint(bool2int(!v))
		C.nox_xxx_tileSetDrawFn_481420()
		C.dword_5d4594_1193156 = 0
		return nil
	case 2099:
		detectBestVideoSettings()
		nox_client_advVideoOptsLoad(nox_win_advVideoOpts_1522600)
		if par := win.Parent(); par != nil {
			par.Func94(asWindowEvent(0x4007, uintptr(unsafe.Pointer(targ.C())), 0))
		}
		return nil
	}
	if opt, ok := noxVideoAdvOpts[id]; ok {
		if opt.Toggle != nil {
			opt.Toggle()
		} else if opt.Flag != 0 {
			noxflags.ToggleEngine(opt.Flag)
		} else if opt.CFlag != nil {
			v := *opt.CFlag != 0
			*opt.CFlag = C.uint(bool2int(!v))
		}
	}
	switch id {
	case 2020:
		sub_49B3C0()
	case 2040:
		C.nox_xxx_xxxRenderGUI_587000_80832 = C.nox_client_renderGUI_80828
	}
	return nil
}

func newAdvVideoOpts(sm *strman.StringManager) *Window {
	draw, drawFree := tempDrawData()
	defer drawFree()

	draw.SetStatus(gui.StatusEnabled | gui.StatusNoFocus)

	draw.SetHighlightColor(noxcolor.RGBColor(192, 128, 128))
	draw.SetTextColor(noxcolor.RGBColor(240, 180, 42))
	draw.SetEnabledColor(gui.ColorTransparent)
	draw.SetDisabledColor(gui.ColorTransparent)
	draw.SetSelectedColor(gui.ColorTransparent)
	draw.SetBackgroundColor(gui.ColorTransparent)
	draw.SetFont(guiFontPtrByName(noxfont.LargeName))

	const (
		width  = 184
		height = 315
	)

	root := newUserWindow(nil, 2000, draw.Status(), 280, 38, width, height, draw, nox_client_advVideoOptsProc_4CB5D0)

	const (
		pad     = 3
		cheight = 15
		crow    = 20
	)

	n := 0
	for _, opt := range noxVideoAdvOptsList {
		if opt.Hidden {
			continue
		}
		y := pad + crow*n
		str := opt.Text
		if opt.TextID != "" {
			if e, ok := sm.GetInFile(opt.TextID, "psscript.c"); ok {
				str = e.Value().Str
			}
		}
		NewCheckbox(root, opt.ID, pad, y, width, cheight, str)
		n++
	}
	return root
}
