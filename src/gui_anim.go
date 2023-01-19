package opennox

/*
#include "defs.h"
#include "client__gui__window.h"
*/
import "C"
import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/env"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func init() {
	if env.IsDevMode() || env.IsE2E() {
		gui.AnimSpeed = 5
	}
}

func asGUIAnim(p *C.nox_gui_animation) *gui.Anim {
	return (*gui.Anim)(unsafe.Pointer(p))
}

var _ = [1]struct{}{}[68-unsafe.Sizeof(gui.Anim{})]

//export nox_gui_freeAnimation_43C570
func nox_gui_freeAnimation_43C570(a *C.nox_gui_animation) {
	asGUIAnim(a).Free()
}

//export nox_gui_makeAnimation_43C5B0
func nox_gui_makeAnimation_43C5B0(win *C.nox_window, x1, y1, x2, y2, in_dx, in_dy, out_dx, out_dy C.int) *C.nox_gui_animation {
	a := nox_gui_makeAnimation(asWindow(win), int(x1), int(y1), int(x2), int(y2), int(in_dx), int(in_dy), int(out_dx), int(out_dy))
	return (*C.nox_gui_animation)(unsafe.Pointer(a))
}

func nox_gui_makeAnimation(win *gui.Window, x1, y1, x2, y2, inDx, inDy, outDx, outDy int) *gui.Anim {
	a := gui.NewAnim(win, image.Pt(x1, y1), image.Pt(x2, y2), image.Pt(inDx, inDy), image.Pt(outDx, outDy))
	clientPlaySoundSpecial(sound.SoundShellSlideIn, 100)
	return a
}
