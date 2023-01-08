//go:build server

package opennox

import (
	"image"
)

func (c *Client) initSeat(sz image.Point) error {
	return nil
}

func (c *Client) drawGeneral(a1 bool) error {
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

func (c *Client) sub4C42A0(a1, a2 image.Point, a3 *int, a4 *int) int32 {
	panic("unreachable")
}

func (c *Client) sub4C5630(a1 int, a2 int, a3 int) int {
	panic("unreachable")
}

func playMovieFile(name string) {}
