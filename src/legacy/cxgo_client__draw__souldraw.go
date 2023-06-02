package legacy

import "github.com/noxworld-dev/opennox/v1/client/noxrender"

func nox_thing_released_soul_draw(vp *noxrender.Viewport, dr *nox_drawable) int {
	return nox_thing_vector_animate_draw(vp, dr)
}
