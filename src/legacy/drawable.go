package legacy

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func asDrawable(p *nox_drawable) *client.Drawable {
	return (*client.Drawable)(unsafe.Pointer(p))
}

func AsDrawableP(p unsafe.Pointer) *client.Drawable {
	return (*client.Drawable)(p)
}

type nox_drawable = client.Drawable

// nox_xxx_sprite_49AA00_drawable
func nox_xxx_sprite_49AA00_drawable(d *nox_drawable) {
	GetClient().Cli().Objs.AddIndex2D(asDrawable(d))
}

// nox_xxx_forEachSprite_49AB00
func nox_xxx_forEachSprite_49AB00(a1 *int4, cfnc unsafe.Pointer, data int32) {
	if cfnc == nil {
		return
	}
	rect := image.Rect(int(a1.field_0), int(a1.field_4), int(a1.field_8), int(a1.field_C))
	GetClient().Cli().Objs.EachInRect(rect, func(dr *client.Drawable) {
		ccall.AsFunc[func(*nox_drawable, int32)](cfnc)((*nox_drawable)(dr.C()), data)
	})
}

// nox_drawable_find_49ABF0
func nox_drawable_find_49ABF0(pt *nox_point, r int) *nox_drawable {
	return (*nox_drawable)(GetClient().Nox_drawable_find(image.Point{X: int(pt.x), Y: int(pt.y)}, r).C())
}

// nox_xxx_spriteLoadAdd_45A360_drawable
func nox_xxx_spriteLoadAdd_45A360_drawable(id, x, y int32) *nox_drawable {
	return (*nox_drawable)(GetClient().Nox_xxx_spriteLoadAdd_45A360_drawable(int(id), image.Pt(int(x), int(y))).C())
}

// nox_xxx_sprite_45A110_drawable
func nox_xxx_sprite_45A110_drawable(dr *nox_drawable) {
	GetClient().Cli().Objs.List34Add(asDrawable(dr))
}

// nox_xxx_netSpriteByCodeStatic_45A720
func nox_xxx_netSpriteByCodeStatic_45A720(id int32) *nox_drawable {
	return (*nox_drawable)(GetClient().Cli().Objs.ByNetCodeStatic(int(id)).C())
}

// nox_xxx_netSpriteByCodeDynamic_45A6F0
func nox_xxx_netSpriteByCodeDynamic_45A6F0(id int32) *nox_drawable {
	return (*nox_drawable)(GetClient().Cli().Objs.ByNetCodeDynamic(int(id)).C())
}

// nox_xxx_cliRemoveHealthbar_459E30
func nox_xxx_cliRemoveHealthbar_459E30(dr *nox_drawable, v uint8) {
	GetClient().Cli().Objs.RemoveHealthBar(asDrawable(dr), v)
}

// sub_45A670
func sub_45A670(a1 uint32) {
	GetClient().Sub_45A670(a1)
}

// nox_xxx_spriteTransparentDecay_49B950
func nox_xxx_spriteTransparentDecay_49B950(dr *nox_drawable, a2 int32) {
	GetClient().Cli().Objs.TransparentDecay(asDrawable(dr), int(a2))
}

// sub_459DD0
func sub_459DD0(dr *nox_drawable, a2 uint8) {
	GetClient().Cli().Objs.MinimapAdd(asDrawable(dr), a2)
}

// nox_xxx_spriteToList_49BC80_drawable
func nox_xxx_spriteToList_49BC80_drawable(dr *nox_drawable) {
	GetClient().Cli().Objs.ClientUpdateAdd(asDrawable(dr))
}

// nox_xxx_spriteDelete_45A4B0
func nox_xxx_spriteDelete_45A4B0(dr *nox_drawable) int32 {
	return int32(GetClient().Nox_xxx_spriteDelete_45A4B0(asDrawable(dr)))
}

// nox_new_drawable_for_thing
func nox_new_drawable_for_thing(i int32) *nox_drawable {
	return (*nox_drawable)(GetClient().Nox_new_drawable_for_thing(int(i)).C())
}

// nox_xxx_spriteDeleteStatic_45A4E0_drawable
func nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr *nox_drawable) {
	GetClient().Nox_xxx_spriteDeleteStatic_45A4E0_drawable(asDrawable(dr))
}

// nox_xxx_spriteToSightDestroyList_49BAB0_drawable
func nox_xxx_spriteToSightDestroyList_49BAB0_drawable(dr *nox_drawable) {
	GetClient().Cli().Objs.List6Add(asDrawable(dr))
}

// sub_45A060
func sub_45A060() *nox_drawable {
	return (*nox_drawable)(GetClient().Cli().Objs.FirstList1().C())
}

// nox_xxx_cliFirstMinimapObj_459EB0
func nox_xxx_cliFirstMinimapObj_459EB0() *nox_drawable {
	return (*nox_drawable)(GetClient().Cli().Objs.FirstMinimapList().C())
}

// nox_xxx_cliGetSpritePlayer_45A000
func nox_xxx_cliGetSpritePlayer_45A000() *nox_drawable {
	return (*nox_drawable)(GetClient().Cli().Objs.FirstPlayerList().C())
}

// nox_xxx_getSomeSprite_49BD40
func nox_xxx_getSomeSprite_49BD40() *nox_drawable {
	return (*nox_drawable)(GetClient().Cli().Objs.FirstList5().C())
}

// sub_45A090
func sub_45A090() *nox_drawable {
	return (*nox_drawable)(GetClient().Cli().Objs.FirstList8().C())
}

// nox_xxx_sprite_45A030
func nox_xxx_sprite_45A030() *nox_drawable {
	return (*nox_drawable)(GetClient().Cli().Objs.FirstList2().C())
}

// nox_xxx_sprite_49BA10
func nox_xxx_sprite_49BA10(dr *nox_drawable) {
	GetClient().Cli().Objs.DeadlineRemove(asDrawable(dr))
}

// sub_49BCD0
func sub_49BCD0(dr *nox_drawable) {
	GetClient().Cli().Objs.ClientUpdateDelete(asDrawable(dr))
}

// nox_xxx_spriteDeleteAll_45A5E0
func nox_xxx_spriteDeleteAll_45A5E0(a1 int32) {
	GetClient().Nox_xxx_spriteDeleteAll_45A5E0(int(a1))
}

func Nox_xxx_client_4984B0_drawable(dr *client.Drawable) int {
	return int(nox_xxx_client_4984B0_drawable((*nox_drawable)(dr.C())))
}

func Nox_xxx_spriteGetMB_476F80() *client.Drawable {
	return asDrawable((*nox_drawable)(dword_5d4594_1096640))
}

func Nox_xxx_clientGetSpriteAtCursor_476F90() *client.Drawable {
	return asDrawable((*nox_drawable)(nox_client_spriteUnderCursorXxx_1096644))
}
func Get_dword_5d4594_1096640() *client.Drawable {
	return AsDrawableP(dword_5d4594_1096640)
}
func Set_dword_5d4594_1096640(dr *client.Drawable) {
	dword_5d4594_1096640 = dr.C()
}
func Get_nox_client_spriteUnderCursorXxx_1096644() *client.Drawable {
	return AsDrawableP(nox_client_spriteUnderCursorXxx_1096644)
}
func Set_nox_client_spriteUnderCursorXxx_1096644(dr *client.Drawable) {
	nox_client_spriteUnderCursorXxx_1096644 = dr.C()
}
func Sub_495B50(fx *client.DrawableFX) {
	sub_495B50(fx.C())
}
func Sub_4523D0(p unsafe.Pointer) {
	sub_4523D0(p)
}
func Sub_495FC0(p *client.DrawableFX, dr *client.Drawable) {
	sub_495FC0(p.C(), (*nox_drawable)(dr.C()))
}
func Sub_49C520(dr *client.Drawable) int {
	return int(sub_49C520((*nox_drawable)(dr.C())))
}
