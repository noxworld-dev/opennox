package opennox

import (
	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

type clientSpells struct {
	skull *client.Drawable // dword_5d4594_1313796
}

func (c *Client) DrawSpinningSkull(vp *noxrender.Viewport, dr *client.Drawable) {
	var vp2 noxrender.Viewport
	vp2.Screen.Max = videoGetWindowSize()
	vp2.Size = videoGetWindowSize()
	skull := c.spells.skull
	if skull == nil {
		skull = c.Nox_new_drawable_for_thing(c.Things.TypeByID("SpinningSkull").Index())
		skull.ObjFlags |= 0x1000000
		c.spells.skull = skull
	}
	skull.PosVec.X = dr.PosVec.X + vp.Screen.Min.X - vp.World.Min.X
	skull.PosVec.Y = dr.PosVec.Y + vp.Screen.Min.Y - vp.World.Min.Y - 50
	skull.CallDraw(&vp2)
}
