package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	Nox_gui_makeAnimation_43C5B0 func(win *gui.Window, x1, y1, x2, y2, in_dx, in_dy, out_dx, out_dy int) *gui.Anim
)

var _ = [1]struct{}{}[68-unsafe.Sizeof(gui.Anim{})]

func asGUIAnim(p *nox_gui_animation) *gui.Anim {
	return (*gui.Anim)(unsafe.Pointer(p))
}

// nox_gui_freeAnimation_43C570
func nox_gui_freeAnimation_43C570(a *nox_gui_animation) {
	asGUIAnim(a).Free()
}

// nox_gui_makeAnimation_43C5B0
func nox_gui_makeAnimation_43C5B0(win *nox_window, x1, y1, x2, y2, in_dx, in_dy, out_dx, out_dy int) *nox_gui_animation {
	a := Nox_gui_makeAnimation_43C5B0(asWindow(win), x1, y1, x2, y2, in_dx, in_dy, out_dx, out_dy)
	return (*nox_gui_animation)(unsafe.Pointer(a))
}
