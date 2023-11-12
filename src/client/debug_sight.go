package client

import (
	"image"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func (c *Client) DebugSightAdd() {
	c.Debug.showSightData = append(c.Debug.showSightData, c.Sight.Get_arr_5d4594_1203876())
}

func (c *Client) drawDebugSight(vp *noxrender.Viewport, arr []image.Point, gen int) {
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
	draw.SetAlpha(256 / 3)
	draw.SetAlphaEnabled(true)
	arrs := c.Debug.showSightData
	c.Debug.showSightData = nil
	for i, arr := range arrs {
		c.drawDebugSight(vp, arr, i+1)
	}
	c.drawDebugSight(vp, c.Sight.Get_arr_5d4594_1203876(), 0)
}
