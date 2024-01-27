package opennox

import (
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/server"
)

type clientDrawInfo struct {
	c     *Client
	skull *client.Drawable
	crown *client.Drawable
	flag  *client.Drawable
}

func (c *clientDrawInfo) Init(cl *Client) {
	c.c = cl
}

func (c *clientDrawInfo) Free() {
	if c.skull != nil {
		c.c.Nox_xxx_spriteDelete_45A4B0(c.skull)
	}
	if c.crown != nil {
		c.c.Nox_xxx_spriteDelete_45A4B0(c.crown)
	}
	if c.flag != nil {
		c.c.Nox_xxx_spriteDelete_45A4B0(c.flag)
	}
	c.skull = nil
	c.crown = nil
	c.flag = nil
}

func (c *Client) DrawSpinningSkull(vp *noxrender.Viewport, dr *client.Drawable) {
	var vp2 noxrender.Viewport
	vp2.Screen.Max = videoGetWindowSize()
	vp2.Size = videoGetWindowSize()
	obj := c.info.skull
	if obj == nil {
		obj = c.Nox_new_drawable_for_thing(c.Things.TypeByID("SpinningSkull").Index())
		obj.ObjFlags |= 0x1000000
		c.info.skull = obj
	}
	if obj == nil {
		return
	}
	obj.PosVec.X = dr.PosVec.X + vp.Screen.Min.X - vp.World.Min.X
	obj.PosVec.Y = dr.PosVec.Y + vp.Screen.Min.Y - vp.World.Min.Y - 50
	obj.CallDraw(&vp2)
}

func (c *Client) DrawSpinningCrown(vp *noxrender.Viewport, dr *client.Drawable) {
	var vp2 noxrender.Viewport
	vp2.Screen.Max = videoGetWindowSize()
	vp2.Size = videoGetWindowSize()
	obj := c.info.crown
	if obj == nil {
		obj = c.Nox_new_drawable_for_thing(c.Things.TypeByID("SpinningCrown").Index())
		obj.ObjFlags |= 0x1000000
		c.info.crown = obj
	}
	if obj == nil {
		return
	}
	obj.PosVec.X = dr.PosVec.X - vp.World.Min.X + vp.Screen.Min.X
	obj.PosVec.Y = dr.PosVec.Y - vp.World.Min.Y + vp.Screen.Min.Y - 50
	obj.CallDraw(&vp2)
}

func (c *Client) DrawFlagOn(vp *noxrender.Viewport, dr *client.Drawable, weapons *server.EquipWeaponData) {
	var vp2 noxrender.Viewport
	vp2.Screen.Max = videoGetWindowSize()
	vp2.Size = videoGetWindowSize()
	obj := c.info.flag
	if obj == nil {
		obj = c.Nox_new_drawable_for_thing(c.Things.TypeByID("Flag").Index())
		c.info.flag = obj
	}
	if obj == nil {
		return
	}
	if weapons != nil {
		for i := range weapons {
			p := &weapons[i]
			if p.Field0 == 1 {
				obj.Union = *(*client.DrawableUnion)(unsafe.Pointer(&p.Field4))
				break
			}
		}
	}
	obj.PosVec.X = dr.PosVec.X - vp.World.Min.X + vp.Screen.Min.X + 15
	obj.PosVec.Y = dr.PosVec.Y - vp.World.Min.Y + vp.Screen.Min.Y - 25
	obj.CallDraw(&vp2)
}

func (c *Client) EnchantColorize(dr *client.Drawable, poison bool, colors []noxcolor.RGBA5551) {
	if dr.HasEnchant(server.ENCHANT_INVULNERABLE) {
		cl := nox_color_blue_2650684
		if c.Server.Frame()%2 != 0 {
			cl = nox_color_white_2523948
		}
		for i := range colors {
			colors[i] = cl
		}
	} else if dr.HasEnchant(server.ENCHANT_FREEZE) {
		cl := nox_color_blue_2650684
		for i := range colors {
			colors[i] = cl
		}
	} else if poison {
		for i, cv := range colors {
			cl := noxrender.SplitColor(cv)
			if int(cl.G)+100 >= 255 {
				cl.G = 255
			} else {
				cl.G += 100
			}
			colors[i] = noxcolor.RGB5551Color(byte(cl.R), byte(cl.G), byte(cl.B))
		}
	}
}

func (c *Client) DrawEnchantsTop(vp *noxrender.Viewport, dr *client.Drawable) {
	if dr.HasEnchant(server.ENCHANT_DEATH) {
		c.DrawSpinningSkull(vp, dr)
	}
	if dr.HasEnchant(server.ENCHANT_CROWN) {
		c.DrawSpinningCrown(vp, dr)
	}
}
