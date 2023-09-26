package legacy

/*
#include "defs.h"
#include "GAME4_1.h"
#include "GAME5_2.h"
*/
import "C"
import (
	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

var (
	Nox_thing_debug_draw func(vp *noxrender.Viewport, dr *client.Drawable) int
)

//export nox_thing_debug_draw
func nox_thing_debug_draw(cvp *nox_draw_viewport_t, cdr *nox_drawable) int {
	return Nox_thing_debug_draw(asViewport(cvp), asDrawable(cdr))
}
