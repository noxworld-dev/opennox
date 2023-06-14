package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	Nox_gui_makeAnimation_43C5B0 func(win *gui.Window, x1, y1, x2, y2, in_dx, in_dy, out_dx, out_dy int) *gui.Anim
)

var _ = [1]struct{}{}[68-unsafe.Sizeof(gui.Anim{})]

// nox_gui_freeAnimation_43C570
func nox_gui_freeAnimation_43C570(a *gui.Anim) {
	a.Free()
}

// nox_gui_makeAnimation_43C5B0
func nox_gui_makeAnimation_43C5B0(win *gui.Window, x1, y1, x2, y2, in_dx, in_dy, out_dx, out_dy int) *gui.Anim {
	return Nox_gui_makeAnimation_43C5B0(asWindow(win), x1, y1, x2, y2, in_dx, in_dy, out_dx, out_dy)
}
