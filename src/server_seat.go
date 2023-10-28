//go:build server

package opennox

import (
	"image"

	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
)

func (c *Client) initSeat(sz image.Point) error {
	return nil
}

func errorMessage(format string, args ...any) {
	log.Printf(format, args...)
}

func (c *Client) DrawGeneral(a1 bool) error {
	return nil
}

func (c *Client) freeSeat() {
}

func (c *Client) gameResetVideoMode(inMenu, force bool) error {
	return nil
}

func (c *Client) clientDraw() bool { return true }

func (c *Client) drawAndPresent() {}

func (c *Client) map_download_start() {}

func (c *Client) mapDownloadLoop(first bool) (bool, error) {
	return true, nil
}

func (c *Client) resetRenderer(sz image.Point, _ bool) error {
	return nil
}

func (c *Client) copyPixBuffer() {
}

func (c *Client) sub_43C060() bool {
	return true
}

func (c *Client) Sub4C42A0(a1, a2 image.Point, a3 *int, a4 *int) int32 {
	panic("unreachable")
}

func (c *Client) Sub4C5630(a1 int, a2 int, a3 int) int {
	panic("unreachable")
}

func (c *Client) Nox_drawable_find(pt image.Point, r int) *client.Drawable {
	panic("unreachable")
}

func (c *Client) Nox_xxx_client_4984B0_drawable(dr *client.Drawable) int {
	panic("unreachable")
}

func (c *Client) Sub_498C20(a1 *ntype.Point32, a2 *ntype.Point32, a3 int32) int32 {
	panic("unreachable")
}

func (c *Client) Sub_499290(a1 int) ntype.Point32 {
	panic("unreachable")
}

func (c *Client) Sub_4992B0(a1 int, a2 int) int {
	panic("unreachable")
}

func playMovieFile(name string) {}

func sub_4960B0() int {
	return 1
}
func sub_496120_free() {}
