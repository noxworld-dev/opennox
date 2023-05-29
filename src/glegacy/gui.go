package legacy

import (
	"os"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	guiLog   = log.New("gui")
	guiDebug = os.Getenv("NOX_DEBUG_GUI") == "true"
)

var (
	Nox_client_gui_set_flag_815132 func(v int)
	Nox_client_onClientStatusA     func(v int)
	Nox_client_setRenderGUI        func(v int)
	Nox_client_getRenderGUI        func() int
)

var _ = [1]struct{}{}[332-unsafe.Sizeof(gui.WindowData{})]

func asWindowDataP(data unsafe.Pointer) *gui.WindowData {
	return (*gui.WindowData)(data)
}

func asWindowData(data *nox_window_data) *gui.WindowData {
	return asWindowDataP(unsafe.Pointer(data))
}

// nox_client_gui_set_flag_815132
func nox_client_gui_set_flag_815132(v int) { Nox_client_gui_set_flag_815132(v) }

// nox_client_onClientStatusA
func nox_client_onClientStatusA(v int) { Nox_client_onClientStatusA(v) }

// nox_client_setRenderGUI
func nox_client_setRenderGUI(v int) { Nox_client_setRenderGUI(v) }

// nox_client_getRenderGUI
func nox_client_getRenderGUI() int { return Nox_client_getRenderGUI() }

// nox_xxx_wndGetFocus_46B4F0
func nox_xxx_wndGetFocus_46B4F0() *nox_window {
	return (*nox_window)(GetClient().Cli().GUI.Focused().C())
}

// nox_xxx_windowFocus_46B500
func nox_xxx_windowFocus_46B500(win *nox_window) int {
	GetClient().Cli().GUI.Focus(asWindow(win))
	return 0
}

// nox_client_getWin1064916_46C720
func nox_client_getWin1064916_46C720() *nox_window {
	return (*nox_window)(GetClient().Cli().GUI.WinYYY.C())
}

// nox_xxx_wndSetCaptureMain_46ADC0
func nox_xxx_wndSetCaptureMain_46ADC0(win *nox_window) int {
	if !asWindow(win).Capture(true) {
		return -4
	}
	return 0
}

// nox_xxx_wndClearCaptureMain_46ADE0
func nox_xxx_wndClearCaptureMain_46ADE0(win *nox_window) int {
	asWindow(win).Capture(false)
	return 0
}

// nox_xxx_wndGetCaptureMain_46AE00
func nox_xxx_wndGetCaptureMain_46AE00() *nox_window {
	return (*nox_window)(GetClient().Cli().GUI.Captured().C())
}

// nox_gui_draw
func nox_gui_draw() {
	GetClient().Cli().GUI.Draw()
}

// nox_color_rgb_4344A0
func nox_color_rgb_4344A0(r, g, b int) uint32 {
	return uint32(noxcolor.RGB5551Color(byte(r), byte(g), byte(b)).Color32())
}

// nox_set_color_rgb_434430
func nox_set_color_rgb_434430(r, g, b int) {
	GetClient().R2().Data().SetColor2(noxcolor.RGB5551Color(byte(r), byte(g), byte(b)))
}

// nox_xxx_wndWddSetTooltip_46B000
func nox_xxx_wndWddSetTooltip_46B000(draw *nox_window_data, str *wchar2_t) {
	sm := GetClient().Cli().Strings()
	d := asWindowData(draw)
	if str == nil {
		d.SetTooltip(sm, "")
		return
	}
	d.SetTooltip(sm, GoWString(str))
}

// sub_46B120
func sub_46B120(a1, a2 *nox_window) int {
	return asWindow(a1).SetParent(asWindow(a2))
}

func Sub_46A4A0() int {
	return int(sub_46A4A0())
}

func Nox_xxx_wndEditProc_487D70(a1 *gui.Window, ev gui.WindowEvent) gui.RawEventResp {
	a2 := ev.EventCode()
	a3, a4 := ev.EventArgsC()
	return gui.RawEventResp(nox_xxx_wndEditProc_487D70((*nox_window)(a1.C()), int(a2), int(a3), int(a4)))
}

func Nox_gui_xxx_check_446360() int {
	return int(nox_gui_xxx_check_446360())
}
