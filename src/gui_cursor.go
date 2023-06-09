package opennox

import (
	"image"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

const cursorSize = 64

func (c *Client) getCursorAnimFrame(ref *legacy.ImageRef, dt int) *noxrender.Image {
	if ref == nil {
		return nil
	}
	anim := ref.Field24ptr()
	ts := int(c.GetInputSeq()) + dt
	imgs := anim.Images()
	switch anim.AnimType {
	case 0: // OneShot
		ind := (ts - int(anim.Field_3)) / (int(anim.Field_2_1) + 1)
		if ind+1 >= len(imgs) {
			ind = len(imgs) - 1
			if fnc := anim.OnEnd.Get(); fnc != nil {
				fnc(ref)
			}
		}
		return c.r.Bag.AsImage(imgs[ind])
	case 2: // Loop
		ind := ts / (int(anim.Field_2_1) + 1)
		ind %= len(imgs)
		return c.r.Bag.AsImage(imgs[ind])
	default:
		return nil
	}
}

func (c *Client) sub_4BE710(ref *legacy.ImageRef, pos image.Point, ind int) {
	anim := ref.Field24ptr()
	imgs := anim.Images()
	img := c.r.Bag.AsImage(imgs[ind])
	if c.flag3798728 {
		c.r.noxDrawCursor(img, pos)
	} else {
		c.r.DrawImageAt(img, pos)
	}
}
