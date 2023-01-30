package opennox

import (
	"image"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

const (
	nox_drawable_2d_index_cap = 47
	nox_drawable_2d_div       = 128
)

var (
	nox_drawable_2d_index      [][]*client.Drawable
	nox_drawable_2d_index_size int
)

func sub_49A8E0_init() {
	nox_drawable_2d_index_size = nox_drawable_2d_index_cap
	nox_drawable_2d_index = make([][]*client.Drawable, nox_drawable_2d_index_size)
	for i := 0; i < nox_drawable_2d_index_size; i++ {
		nox_drawable_2d_index[i] = make([]*client.Drawable, nox_drawable_2d_index_size)
	}
}

func sub_49A950_free() {
	nox_drawable_2d_index = nil
	nox_drawable_2d_index_size = 0
}

func nox_xxx_sprite_49AA00_drawable(dr *client.Drawable) {
	pos := dr.Pos()
	xi := pos.X / nox_drawable_2d_div
	yi := pos.Y / nox_drawable_2d_div

	ext := dr.Ext()
	if ext.Field99 != nil {
		client.Nox_xxx_sprite_2d_remove(dr, ext)
	}

	dr.Field_101 = nil

	if xi < 0 || xi >= len(nox_drawable_2d_index) {
		return
	}
	index := nox_drawable_2d_index[xi]
	if yi < 0 || yi >= len(index) {
		return
	}
	v4 := index[yi]
	dr.Field_100 = v4
	if v4 != nil {
		v4.Field_101 = dr
	}
	nox_drawable_2d_index[xi][yi] = dr

	ext.Field99 = &nox_drawable_2d_index[xi][yi]
}

func nox_xxx_forEachSprite(rect image.Rectangle, fnc func(dr *client.Drawable)) {
	if fnc == nil {
		return
	}
	xs := rect.Min.X / nox_drawable_2d_div
	if xs < 0 {
		xs = 0
	}
	ys := rect.Min.Y / nox_drawable_2d_div
	if ys < 0 {
		ys = 0
	}
	xe := rect.Max.X / nox_drawable_2d_div
	if xe >= nox_drawable_2d_index_size {
		xe = nox_drawable_2d_index_size - 1
	}
	ye := rect.Max.Y / nox_drawable_2d_div
	if ye >= nox_drawable_2d_index_size {
		ye = nox_drawable_2d_index_size - 1
	}
	for y := ys; y <= ye; y++ {
		for x := xs; x <= xe; x++ {
			for cur := nox_drawable_2d_index[x][y]; cur != nil; cur = cur.Field100() {
				fnc(cur)
			}
		}
	}
}

func nox_drawable_find(pt image.Point, r int) *client.Drawable {
	xs := (pt.X - r) / nox_drawable_2d_div
	if xs < 0 {
		xs = 0
	}
	ys := (pt.Y - r) / nox_drawable_2d_div
	if ys < 0 {
		ys = 0
	}
	xe := (pt.X + r) / nox_drawable_2d_div
	if xe >= nox_drawable_2d_index_size {
		xe = nox_drawable_2d_index_size - 1
	}
	ye := (pt.Y + r) / nox_drawable_2d_div
	if ye >= nox_drawable_2d_index_size {
		ye = nox_drawable_2d_index_size - 1
	}
	var (
		out *client.Drawable
		min = -1
		r2  = r * r
	)
	for y := ys; y <= ye; y++ {
		for x := xs; x <= xe; x++ {
			for dr := nox_drawable_2d_index[x][y]; dr != nil; dr = dr.Field100() {
				if legacy.Nox_xxx_client_4984B0_drawable(dr) == 0 {
					continue
				}
				dp := pt.Sub(dr.Pos())
				d2 := dp.X*dp.X + dp.Y*dp.Y
				if d2 >= r2 {
					continue
				}
				if min < 0 || d2 < min {
					min = d2
					out = dr
				}
			}
		}
	}
	return out
}
