package legacy

/*
#include "defs.h"
extern void* dword_5d4594_1096640;
extern void* nox_client_spriteUnderCursorXxx_1096644;
int  nox_xxx_client_4984B0_drawable(nox_drawable* dr);
void sub_495B50(void* a1);
int sub_4523D0(void* a1);
nox_drawable* nox_xxx_spriteLoadAdd_45A360_drawable(int thingInd, int a2, int a3);
void nox_xxx_spriteDeleteStatic_45A4E0_drawable(nox_drawable* dr);
void* sub_452EB0(void* a1);
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
	Nox_xxx_sprite_49AA00_drawable                   func(dr *client.Drawable)
	Nox_xxx_forEachSprite                            func(rect image.Rectangle, fnc func(dr *client.Drawable))
	Nox_drawable_find                                func(pt image.Point, r int) *client.Drawable
	Nox_xxx_sprite_45A110_drawable                   func(dr *client.Drawable)
	Nox_xxx_netSpriteByCodeStatic_45A720             func(id int) *client.Drawable
	Nox_xxx_netSpriteByCodeDynamic_45A6F0            func(id int) *client.Drawable
	Nox_xxx_cliRemoveHealthbar_459E30                func(dr *client.Drawable, a2 uint8)
	Nox_xxx_spriteTransparentDecay_49B950            func(dr *client.Drawable, lifetime int)
	Sub_459DD0                                       func(dr *client.Drawable, a2 uint8)
	Nox_xxx_spriteToList_49BC80_drawable             func(dr *client.Drawable)
	Nox_xxx_spriteDelete_45A4B0                      func(dr *client.Drawable) int
	Nox_new_drawable_for_thing                       func(i int) *client.Drawable
	Nox_xxx_spriteToSightDestroyList_49BAB0_drawable func(dr *client.Drawable)
	Nox_xxx_cliFirstMinimapObj_459EB0                func() *client.Drawable
	Nox_xxx_cliNextMinimapObj_459EC0                 func(dr *client.Drawable) *client.Drawable
	Nox_xxx_cliGetSpritePlayer_45A000                func() *client.Drawable
	Nox_xxx_getSomeSprite_49BD40                     func() *client.Drawable
	Sub_45A090                                       func() *client.Drawable
	Nox_xxx_sprite_49BA10                            func(dr *client.Drawable)
	Sub_49BCD0                                       func(dr *client.Drawable)
	Nox_xxx_spriteDeleteAll_45A5E0                   func(a1 int)
	Sub_45A160_drawable                              func(dr *client.Drawable)
	Sub_459ED0_drawable                              func(dr *client.Drawable)
	Sub_459F00                                       func(dr *client.Drawable)
	Sub_49BAF0                                       func(dr *client.Drawable)
	Sub_459F40_drawable                              func(dr *client.Drawable)
	Sub_459F70                                       func(dr *client.Drawable)
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

//export nox_xxx_sprite_45A110_drawable
func nox_xxx_sprite_45A110_drawable(dr *nox_drawable) {
	Nox_xxx_sprite_45A110_drawable(asDrawable(dr))
}

//export nox_xxx_netSpriteByCodeStatic_45A720
func nox_xxx_netSpriteByCodeStatic_45A720(id int) *nox_drawable {
	return (*nox_drawable)(Nox_xxx_netSpriteByCodeStatic_45A720(id).C())
}

//export nox_xxx_netSpriteByCodeDynamic_45A6F0
func nox_xxx_netSpriteByCodeDynamic_45A6F0(id int) *nox_drawable {
	return (*nox_drawable)(Nox_xxx_netSpriteByCodeDynamic_45A6F0(id).C())
}

//export nox_xxx_cliRemoveHealthbar_459E30
func nox_xxx_cliRemoveHealthbar_459E30(dr *nox_drawable, v uint8) {
	Nox_xxx_cliRemoveHealthbar_459E30(asDrawable(dr), v)
}

//export nox_xxx_spriteTransparentDecay_49B950
func nox_xxx_spriteTransparentDecay_49B950(dr *nox_drawable, a2 int) {
	Nox_xxx_spriteTransparentDecay_49B950(asDrawable(dr), a2)
}

//export sub_459DD0
func sub_459DD0(dr *nox_drawable, a2 uint8) {
	Sub_459DD0(asDrawable(dr), a2)
}

//export nox_xxx_spriteToList_49BC80_drawable
func nox_xxx_spriteToList_49BC80_drawable(dr *nox_drawable) {
	Nox_xxx_spriteToList_49BC80_drawable(asDrawable(dr))
}

//export nox_xxx_spriteDelete_45A4B0
func nox_xxx_spriteDelete_45A4B0(dr *nox_drawable) int {
	return Nox_xxx_spriteDelete_45A4B0(asDrawable(dr))
}

//export nox_new_drawable_for_thing
func nox_new_drawable_for_thing(i int) *nox_drawable {
	return (*nox_drawable)(Nox_new_drawable_for_thing(i).C())
}

//export nox_xxx_spriteToSightDestroyList_49BAB0_drawable
func nox_xxx_spriteToSightDestroyList_49BAB0_drawable(dr *nox_drawable) {
	Nox_xxx_spriteToSightDestroyList_49BAB0_drawable(asDrawable(dr))
}

//export nox_xxx_cliFirstMinimapObj_459EB0
func nox_xxx_cliFirstMinimapObj_459EB0() *nox_drawable {
	return (*nox_drawable)(Nox_xxx_cliFirstMinimapObj_459EB0().C())
}

//export nox_xxx_cliNextMinimapObj_459EC0
func nox_xxx_cliNextMinimapObj_459EC0(dr *nox_drawable) *nox_drawable {
	return (*nox_drawable)(Nox_xxx_cliNextMinimapObj_459EC0(asDrawable(dr)).C())
}

//export nox_xxx_cliGetSpritePlayer_45A000
func nox_xxx_cliGetSpritePlayer_45A000() *nox_drawable {
	return (*nox_drawable)(Nox_xxx_cliGetSpritePlayer_45A000().C())
}

//export nox_xxx_getSomeSprite_49BD40
func nox_xxx_getSomeSprite_49BD40() *nox_drawable {
	return (*nox_drawable)(Nox_xxx_getSomeSprite_49BD40().C())
}

//export sub_45A090
func sub_45A090() *nox_drawable {
	return (*nox_drawable)(Sub_45A090().C())
}

//export nox_xxx_sprite_49BA10
func nox_xxx_sprite_49BA10(dr *nox_drawable) {
	Nox_xxx_sprite_49BA10(asDrawable(dr))
}

//export sub_49BCD0
func sub_49BCD0(dr *nox_drawable) {
	Sub_49BCD0(asDrawable(dr))
}

//export nox_xxx_spriteDeleteAll_45A5E0
func nox_xxx_spriteDeleteAll_45A5E0(a1 int) {
	Nox_xxx_spriteDeleteAll_45A5E0(a1)
}

//export sub_459ED0_drawable
func sub_459ED0_drawable(dr *nox_drawable) {
	Sub_459ED0_drawable(asDrawable(dr))
}

//export sub_459F00
func sub_459F00(dr *nox_drawable) {
	Sub_459F00(asDrawable(dr))
}

//export sub_49BAF0
func sub_49BAF0(dr *nox_drawable) {
	Sub_49BAF0(asDrawable(dr))
}

//export sub_45A160_drawable
func sub_45A160_drawable(dr *nox_drawable) {
	Sub_45A160_drawable(asDrawable(dr))
}

//export sub_459F40_drawable
func sub_459F40_drawable(dr *nox_drawable) {
	Sub_459F40_drawable(asDrawable(dr))
}

//export sub_459F70
func sub_459F70(dr *nox_drawable) {
	Sub_459F70(asDrawable(dr))
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
func Sub_4523D0(p unsafe.Pointer) {
	C.sub_4523D0(p)
}
func Sub_495B50(fx *client.DrawableFX) {
	C.sub_495B50(fx.C())
}
func Nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr *client.Drawable) {
	C.nox_xxx_spriteDeleteStatic_45A4E0_drawable((*nox_drawable)(dr.C()))
}
func Sub_452EB0(p *unsafe.Pointer) unsafe.Pointer {
	return C.sub_452EB0(unsafe.Pointer(p))
}
