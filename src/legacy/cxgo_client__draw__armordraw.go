package legacy

import (
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func nox_thing_armor_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	sub_4B96F0(dr)
	return nox_thing_static_draw(vp, dr)
}
func nox_thing_armor_animate_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	sub_4B96F0(dr)
	return nox_thing_animate_draw(vp, dr)
}
