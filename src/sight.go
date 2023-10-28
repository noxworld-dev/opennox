//go:build !server

package opennox

import (
	"github.com/noxworld-dev/opennox/v1/client"
)

func (c *Client) Nox_xxx_client_4984B0_drawable(dr *client.Drawable) int {
	if dr.DrawFuncPtr == nil {
		return 0
	}
	if dr == c.ClientPlayerUnit() {
		return 1
	}
	return c.Sight.Nox_xxx_client_4984B0_drawable_A(c.Viewport(), dr)
}

func (c *Client) nox_xxx_drawBlack_496150_B() {
	arr := c.Sight.Nox_xxx_drawBlack_496150_C()
	if len(arr) == 0 {
		return
	}
	c.sub_4C52E0(arr)
}
