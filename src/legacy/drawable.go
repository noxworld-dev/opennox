package legacy

/*
#include "defs.h"
extern int nox_drawable_count;
extern void* dword_5d4594_1096640;
extern void* nox_client_spriteUnderCursorXxx_1096644;
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

var (
	Nox_xxx_sprite_49AA00_drawable func(dr *client.Drawable)
	Nox_xxx_forEachSprite          func(rect image.Rectangle, fnc func(dr *client.Drawable))
	Nox_drawable_find              func(pt image.Point, r int) *client.Drawable
)

func asDrawable(p *nox_drawable) *client.Drawable {
	return (*client.Drawable)(unsafe.Pointer(p))
}

func AsDrawableP(p unsafe.Pointer) *client.Drawable {
	return (*client.Drawable)(p)
}

type nox_drawable = C.nox_drawable

//export nox_xxx_sprite_49AA00_drawable
func nox_xxx_sprite_49AA00_drawable(d *nox_drawable) {
	Nox_xxx_sprite_49AA00_drawable(asDrawable(d))
}

//export nox_xxx_sprite_49A9B0_drawable
func nox_xxx_sprite_49A9B0_drawable(d *nox_drawable) int {
	dr := asDrawable(d)
	client.Nox_xxx_sprite_2d_remove(dr, dr.Ext())
	return 0
}

//export nox_xxx_forEachSprite_49AB00
func nox_xxx_forEachSprite_49AB00(a1 *C.int4, cfnc unsafe.Pointer, data int) {
	if cfnc == nil {
		return
	}
	rect := image.Rect(int(a1.field_0), int(a1.field_4), int(a1.field_8), int(a1.field_C))
	Nox_xxx_forEachSprite(rect, func(dr *client.Drawable) {
		C.go_nox_drawable_call_sprite_func((*[0]byte)(cfnc), (*nox_drawable)(dr.C()), C.int(data))
	})
}

//export nox_drawable_find_49ABF0
func nox_drawable_find_49ABF0(pt *C.nox_point, r int) *nox_drawable {
	return (*nox_drawable)(Nox_drawable_find(image.Point{X: int(pt.x), Y: int(pt.y)}, r).C())
}

func DrawableCount() int {
	return int(C.nox_drawable_count)
}

func CallDrawFunc(s *client.Drawable, vp *noxrender.Viewport) int {
	return int(C.go_nox_drawable_call_draw_func((*nox_draw_viewport_t)(vp.C()), (*nox_drawable)(s.C())))
}

func nox_xxx_spriteLoadAdd_45A360_drawable(thingInd int, pos image.Point) *client.Drawable {
	return asDrawable(C.nox_xxx_spriteLoadAdd_45A360_drawable(C.int(thingInd), C.int(pos.X), C.int(pos.Y)))
}

func Nox_xxx_client_4984B0_drawable(dr *client.Drawable) int {
	return int(C.nox_xxx_client_4984B0_drawable((*nox_drawable)(dr.C())))
}

func Nox_xxx_spriteGetMB_476F80() *client.Drawable {
	return asDrawable((*nox_drawable)(C.dword_5d4594_1096640))
}

func Nox_xxx_clientGetSpriteAtCursor_476F90() *client.Drawable {
	return asDrawable((*nox_drawable)(C.nox_client_spriteUnderCursorXxx_1096644))
}
