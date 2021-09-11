package main

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
import "unsafe"

var nox_win_advVideoOpts_1522600 *Window

//export nox_client_advVideoOpts_New_4CB590
func nox_client_advVideoOpts_New_4CB590(par *C.nox_window) C.int {
	nox_win_advVideoOpts_1522600 = newWindowFromFile("advidopt.wnd", C.nox_client_advVideoOptsProc_4CB5D0)
	sub46B120(nox_win_advVideoOpts_1522600, asWindow(par))
	nox_client_advVideoOptsLoad(nox_win_advVideoOpts_1522600)
	return 1
}

var noxVideoAdvOpts = map[uint]struct {
	Flag  EngineFlags
	CFlag *C.uint
	Def   bool
}{
	2010: {CFlag: &C.nox_video_dxUnlockSurface},
	2012: {Flag: NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE},
	2014: {CFlag: &C.nox_gui_console_translucent},
	2015: {CFlag: &C.nox_client_renderGlow_805852},
	2016: {CFlag: &C.nox_client_fadeObjects_80836},
	2017: {CFlag: &C.nox_client_showTooltips_80840},
	2020: {CFlag: &C.nox_client_drawFrontWalls_80812},
	2021: {CFlag: &C.nox_client_translucentFrontWalls_805844},
	2022: {CFlag: &C.nox_client_highResFrontWalls_80820},
	2031: {CFlag: &C.nox_client_highResFloors_154952},
	2032: {CFlag: &C.nox_client_lockHighResFloors_1193152},
	2033: {CFlag: &C.nox_client_texturedFloors2_154960},
	2040: {CFlag: &C.nox_client_renderGUI_80828},
	2041: {CFlag: &C.nox_client_renderBubbles_80844},
}

//export nox_client_advVideoOptsLoad_4CB330
func nox_client_advVideoOptsLoad_4CB330() {
	nox_client_advVideoOptsLoad(nox_win_advVideoOpts_1522600)
}

func nox_client_advVideoOptsLoad(win *Window) {
	for id, opt := range noxVideoAdvOpts {
		if w := win.ChildByID(id); w != nil {
			v := opt.Def
			if opt.Flag != 0 {
				v = getEngineFlag(opt.Flag)
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

//export nox_client_advVideoOptsProc_4CB5D0
func nox_client_advVideoOptsProc_4CB5D0(a1 unsafe.Pointer, ev C.int, a3 unsafe.Pointer, a4 C.int) C.int {
	if ev == 16389 {
		clientPlaySoundSpecial(920, 100)
		return 1
	}
	if ev != 16391 {
		return 0
	}
	win := asWindow((*C.nox_window)(a1))
	targ := asWindow((*C.nox_window)(a3))
	clientPlaySoundSpecial(766, 100)
	id := targ.ID()
	switch id {
	case 2010:
		// always enabled
		C.nox_video_dxUnlockSurface = 1
		win.DrawData().Field0Set(0x4, true)
		return 0
	case 2033:
		v := C.nox_client_texturedFloors2_154960 != 0
		C.nox_client_texturedFloors2_154960 = C.uint(bool2int(!v))
		C.nox_client_texturedFloors_154956 = C.uint(bool2int(!v))
		C.nox_xxx_tileSetDrawFn_481420()
		C.dword_5d4594_1193156 = 0
		return 0
	case 2099:
		detectBestVideoSettings()
		nox_client_advVideoOptsLoad(nox_win_advVideoOpts_1522600)
		if par := win.Parent(); par != nil {
			par.Func94(16391, uintptr(unsafe.Pointer(targ.C())), 0)
		}
		return 0
	}
	if opt, ok := noxVideoAdvOpts[id]; ok {
		if opt.Flag != 0 {
			toggleEngineFlag(opt.Flag)
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
	return 0
}
