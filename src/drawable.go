package opennox

/*
#include "defs.h"
extern int nox_drawable_count;
int  nox_xxx_client_4984B0_drawable(nox_drawable* dr);
nox_drawable* nox_xxx_spriteLoadAdd_45A360_drawable(int thingInd, int a2, int a3);
static int go_nox_drawable_call_draw_func(nox_draw_viewport_t* vp, nox_drawable* dr) {
	return dr->draw_func(vp, dr);
}
static void go_nox_drawable_call_sprite_func(void(* fnc)(nox_drawable*, int), nox_drawable* dr, int arg) {
	fnc(dr, arg);
}
*/
import "C"
import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func drawableCount() int {
	return int(C.nox_drawable_count)
}

func asDrawable(p *nox_drawable) *client.Drawable {
	return (*client.Drawable)(unsafe.Pointer(p))
}

type nox_drawable = C.nox_drawable

func callDrawFunc(s *client.Drawable, vp *noxrender.Viewport) int {
	return int(C.go_nox_drawable_call_draw_func((*nox_draw_viewport_t)(vp.C()), (*nox_drawable)(s.C())))
}

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

func nox_xxx_spriteLoadAdd_45A360_drawable(thingInd int, pos image.Point) *client.Drawable {
	return asDrawable(C.nox_xxx_spriteLoadAdd_45A360_drawable(C.int(thingInd), C.int(pos.X), C.int(pos.Y)))
}

//export nox_xxx_sprite_49AA00_drawable
func nox_xxx_sprite_49AA00_drawable(d *nox_drawable) {
	dr := asDrawable(d)
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

//export nox_xxx_sprite_49A9B0_drawable
func nox_xxx_sprite_49A9B0_drawable(d *nox_drawable) C.int {
	dr := asDrawable(d)
	client.Nox_xxx_sprite_2d_remove(dr, dr.Ext())
	return 0
}

//export nox_xxx_forEachSprite_49AB00
func nox_xxx_forEachSprite_49AB00(a1 *C.int4, cfnc unsafe.Pointer, data C.int) {
	if cfnc == nil {
		return
	}
	rect := image.Rect(int(a1.field_0), int(a1.field_4), int(a1.field_8), int(a1.field_C))
	nox_xxx_forEachSprite(rect, func(dr *client.Drawable) {
		C.go_nox_drawable_call_sprite_func((*[0]byte)(cfnc), (*nox_drawable)(dr.C()), data)
	})
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

//export nox_drawable_find_49ABF0
func nox_drawable_find_49ABF0(pt *C.nox_point, r C.int) *nox_drawable {
	return (*nox_drawable)(nox_drawable_find(image.Point{X: int(pt.x), Y: int(pt.y)}, int(r)).C())
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
				if C.nox_xxx_client_4984B0_drawable((*nox_drawable)(dr.C())) == 0 {
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
