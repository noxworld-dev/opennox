package legacy

/*
#include "defs.h"
void nox_xxx_sprite_45A110_drawable(nox_drawable* a1);
*/
import "C"
import "github.com/noxworld-dev/opennox/v1/client"

func Nox_xxx_sprite_45A110_drawable(a1 *client.Drawable) {
	C.nox_xxx_sprite_45A110_drawable((*nox_drawable)(a1.C()))
}
