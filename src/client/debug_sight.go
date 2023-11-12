package client

import (
	"image"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func (c *Client) DebugSightAdd() {
	c.Debug.showSightData = append(c.Debug.showSightData, c.Sight.GetSightPoints())
}

func (c *Client) drawDebugSight(arr []image.Point, gen int) {
	if len(arr) == 0 {
		return
	}
	prev := arr[len(arr)-1]
	colors := []noxcolor.Color16{
		noxcolor.RGB5551Color(0, 128, 0), // final
		noxcolor.RGB5551Color(255, 0, 0),
		noxcolor.RGB5551Color(255, 128, 0),
		noxcolor.RGB5551Color(255, 255, 0),
		noxcolor.RGB5551Color(255, 0, 255),
	}
	cl := colors[gen%len(colors)]
	for _, v := range arr {
		c.r.DrawLine(prev, v, cl)
		prev = v
	}
}

func (c *Client) DrawDebugSight(vp *noxrender.Viewport) {
	draw := c.r.Data()
	oldAlpha, oldEnabled := draw.Alpha(), draw.IsAlphaEnabled()
	defer func() {
		draw.SetAlpha(oldAlpha)
		draw.SetAlphaEnabled(oldEnabled)
	}()
	c.drawDebugSightFinal()
	c.drawDebugSightObjs(vp)
}

func (c *Client) drawDebugSightObjs(vp *noxrender.Viewport) {
	draw := c.r.Data()
	draw.SetAlpha(255)
	draw.SetAlphaEnabled(false)
	for _, ss := range c.Sight.getSightObjs() {
		pos1, pos2 := c.Sight.sightObjVec(vp, ss)
		cl := noxcolor.RGB5551Color(255, 0, 0)
		switch ss.Kind56 {
		case sightKindWall:
			cl = noxcolor.RGB5551Color(0, 255, 0)
		case sightKindDrCircle:
			cl = noxcolor.RGB5551Color(0, 0, 255)
		case sightKindDrDoor:
			cl = noxcolor.RGB5551Color(255, 0, 255)
		case sightKindDrBox1, sightKindDrBox2, sightKindDrBox3, sightKindDrBox4, sightKindDrBox5, sightKindDrBox6:
			cl = noxcolor.RGB5551Color(0, 255, 255)
		case sightKindOK:
			cl = noxcolor.RGB5551Color(255, 255, 255)
		}
		sp1 := vp.ToScreenPos(pos1.Point())
		sp2 := vp.ToScreenPos(pos2.Point())
		c.r.DrawLine(sp1, sp2, cl)
	}
}

func (c *Client) drawDebugSightFinal() {
	draw := c.r.Data()
	draw.SetAlpha(256 / 3)
	draw.SetAlphaEnabled(true)
	arrs := c.Debug.showSightData
	c.Debug.showSightData = nil
	for i, arr := range arrs {
		c.drawDebugSight(arr, i+1)
	}
	c.drawDebugSight(c.Sight.GetSightPoints(), 0)
}
