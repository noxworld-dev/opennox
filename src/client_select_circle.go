package opennox

import (
	"image/color"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (c *Client) drawSelection(vp *noxrender.Viewport) {
	dr := legacy.Get_dword_5d4594_1096640()
	if dr == nil {
		return
	}
	var cl color.Color
	if dr.ObjClass&6 != 0 && legacy.Sub_495A80(dr.NetCode32) == 0 {
		switch c.srv.Rand.Other.Int(0, 1) {
		case 0:
			cl = nox_color_violet_2598268
		case 1:
			cl = nox_color_red
		}
	} else {
		switch c.srv.Rand.Other.Int(0, 2) {
		case 0:
			cl = nox_color_white_2523948
		case 1:
			cl = nox_color_blue_2650684
		case 2:
			cl = nox_color_cyan_2649820
		}
	}
	if (dr.ObjClass & 0x200) == 0 {
		c.drawSelectionCursor(vp, cl, dr)
	}
}

func (c *Client) drawSelectionCursor(vp *noxrender.Viewport, cl color.Color, dr *client.Drawable) {
	if dr == nil {
		return
	}
	rad := 6
	if dr.Shape.Kind == server.ShapeKindCircle {
		rad += int(dr.Shape.Circle.R)
	} else if dr.Shape.Kind == server.ShapeKindBox {
		rad += int(dr.Shape.Box.H+dr.Shape.Box.W) / 2
	}
	cx := dr.PosVec.X + vp.Screen.Min.X - vp.World.Min.X
	cy := dr.PosVec.Y + vp.Screen.Min.Y - vp.World.Min.Y
	c.r.Data().SetColor2(cl)
	c.r.Data().SetAlphaEnabled(true)
	c.r.Data().SetAlphaEnabled(true)
	c.r.Data().SetAlpha(128)
	c.r.DrawCircle(cx, cy, rad-1, cl)
	c.r.DrawCircle(cx, cy, rad+1, cl)
	c.r.Data().SetAlphaEnabled(false)
	c.r.DrawCircle(cx, cy, rad, cl)
}
