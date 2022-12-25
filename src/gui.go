package opennox

/*
#include "GAME1_3.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "client__gui__guicon.h"
*/
import "C"
import (
	"context"
	"image"
	"os"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	guiLog                            = log.New("gui")
	guiDebug                          = os.Getenv("NOX_DEBUG_GUI") == "true"
	nox_xxx_xxxRenderGUI_587000_80832 = true
	nox_client_renderGUI_80828        = true
	nox_client_gui_flag_815132        int
)

func init() {
	noxCmdShow.Register(&console.Command{
		Token: "gui", HelpID: "showguihelp",
		Flags: console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			v0 := !nox_client_renderGUI_80828
			nox_client_renderGUI_80828 = v0
			nox_xxx_xxxRenderGUI_587000_80832 = v0
			return true
		},
	})
}

func enableGUIDrawing(enable bool) {
	nox_client_renderGUI_80828 = enable
	nox_xxx_xxxRenderGUI_587000_80832 = enable
}

//export nox_client_gui_set_flag_815132
func nox_client_gui_set_flag_815132(v int) {
	nox_client_gui_flag_815132 = v
}

//export nox_client_onClientStatusA
func nox_client_onClientStatusA(v int) {
	if v&1 != 0 {
		nox_client_renderGUI_80828 = false
	} else if nox_xxx_xxxRenderGUI_587000_80832 {
		nox_client_renderGUI_80828 = true
	}
}

//export nox_client_setRenderGUI
func nox_client_setRenderGUI(v int) {
	nox_client_renderGUI_80828 = v != 0
}

//export nox_client_getRenderGUI
func nox_client_getRenderGUI() int {
	return bool2int(nox_client_renderGUI_80828)
}

//export nox_xxx_wndGetFocus_46B4F0
func nox_xxx_wndGetFocus_46B4F0() *C.nox_window {
	return (*C.nox_window)(noxClient.GUI.Focused().C())
}

//export nox_xxx_windowFocus_46B500
func nox_xxx_windowFocus_46B500(win *C.nox_window) C.int {
	noxClient.GUI.Focus(asWindow(win))
	return 0
}

//export nox_client_getWin1064916_46C720
func nox_client_getWin1064916_46C720() *C.nox_window {
	return (*C.nox_window)(noxClient.GUI.WinYYY.C())
}

//export nox_xxx_wndSetCaptureMain_46ADC0
func nox_xxx_wndSetCaptureMain_46ADC0(win *C.nox_window) C.int {
	if !asWindow(win).Capture(true) {
		return -4
	}
	return 0
}

//export nox_xxx_wndClearCaptureMain_46ADE0
func nox_xxx_wndClearCaptureMain_46ADE0(win *C.nox_window) C.int {
	asWindow(win).Capture(false)
	return 0
}

//export nox_xxx_wndGetCaptureMain_46AE00
func nox_xxx_wndGetCaptureMain_46AE00() *C.nox_window {
	return (*C.nox_window)(noxClient.GUI.Captured().C())
}

func asWindowData(data *C.nox_window_data) *gui.WindowData {
	return asWindowDataP(unsafe.Pointer(data))
}

func asWindowDataP(data unsafe.Pointer) *gui.WindowData {
	return (*gui.WindowData)(data)
}

var _ = [1]struct{}{}[332-unsafe.Sizeof(gui.WindowData{})]

//export nox_gui_draw
func nox_gui_draw() {
	noxClient.GUI.Draw()
}

//export nox_color_rgb_4344A0
func nox_color_rgb_4344A0(r, g, b C.int) C.uint32_t {
	return C.uint32_t(noxcolor.RGB5551Color(byte(r), byte(g), byte(b)).Color32())
}

//export nox_set_color_rgb_434430
func nox_set_color_rgb_434430(r, g, b C.int) {
	noxClient.r.Data().SetColor2(noxcolor.RGB5551Color(byte(r), byte(g), byte(b)))
}

func unsafePtrToInt(p unsafe.Pointer) C.int {
	return C.int(uintptr(p))
}

func dataPtrToInt(p *gui.WindowData) C.int {
	return C.int(uintptr(unsafe.Pointer(p)))
}

//export nox_xxx_wndWddSetTooltip_46B000
func nox_xxx_wndWddSetTooltip_46B000(draw *C.nox_window_data, str *C.wchar_t) {
	d := asWindowData(draw)
	if str == nil {
		d.SetTooltip(strMan, "")
		return
	}
	d.SetTooltip(strMan, GoWString(str))
}

func (c *Client) keyBindingsCheckActive() int {
	if C.sub_46A4A0() != 0 {
		return 1
	}
	for _, key := range c.Inp.KeyboardKeys() {
		if !c.Inp.GetKeyFlag(key) && !c.Inp.IsPressed(key) && nox_xxx_guiCursor_477600() == 0 {
			if noxConsole.ExecMacros(context.Background(), key) {
				c.Inp.SetKeyFlag(key, true)
			}
		}
	}
	return 1
}

func nox_xxx_pointInRect_4281F0(p image.Point, r image.Rectangle) bool {
	return p.In(r)
}

//export sub_46B120
func sub_46B120(a1, a2 *C.nox_window) C.int {
	return C.int(asWindow(a1).SetParent(asWindow(a2)))
}

func sub_46AEE0(a1 *gui.Window, a2 string) {
	a1.Func94(&gui.StaticTextSetText{Str: a2})
}

func nox_xxx_wndEditProc_487D70(a1 *gui.Window, ev gui.WindowEvent) gui.RawEventResp {
	a2 := ev.EventCode()
	a3, a4 := ev.EventArgsC()
	return gui.RawEventResp(C.nox_xxx_wndEditProc_487D70((*C.nox_window)(a1.C()), C.int(a2), C.int(a3), C.int(a4)))
}
