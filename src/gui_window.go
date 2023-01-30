package opennox

import (
	"image"

	"github.com/noxworld-dev/opennox-lib/env"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func init() {
	if env.IsDevMode() || env.IsE2E() {
		gui.AnimSpeed = 5
	}
}

func (c *Client) guiLoadBorderImages() {
	c.GUI.SetBorders(gui.Borders{
		CornerUL:        nox_xxx_gLoadImg("BorderCornerUL"),
		CornerUR:        nox_xxx_gLoadImg("BorderCornerUR"),
		CornerLL:        nox_xxx_gLoadImg("BorderCornerLL"),
		CornerLR:        nox_xxx_gLoadImg("BorderCornerLR"),
		Horizontal:      nox_xxx_gLoadImg("BorderHorizontal"),
		HorizontalShort: nox_xxx_gLoadImg("BorderHorizontalShort"),
		Vertical:        nox_xxx_gLoadImg("BorderVertical"),
		VerticalShort:   nox_xxx_gLoadImg("BorderVerticalShort"),
	})
}

func nox_gui_makeAnimation(win *gui.Window, x1, y1, x2, y2, inDx, inDy, outDx, outDy int) *gui.Anim {
	a := gui.NewAnim(win, image.Pt(x1, y1), image.Pt(x2, y2), image.Pt(inDx, inDy), image.Pt(outDx, outDy))
	clientPlaySoundSpecial(sound.SoundShellSlideIn, 100)
	return a
}
