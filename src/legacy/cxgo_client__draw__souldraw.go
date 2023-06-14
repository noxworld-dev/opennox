package legacy

import (
	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func nox_thing_released_soul_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	return nox_thing_vector_animate_draw(vp, dr)
}
