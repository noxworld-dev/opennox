package legacy

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
)

func AsDrawableP(p unsafe.Pointer) *client.Drawable {
	return (*client.Drawable)(p)
}

// nox_xxx_sprite_49AA00_drawable
func nox_xxx_sprite_49AA00_drawable(d *client.Drawable) {
	GetClient().Cli().Objs.AddIndex2D(d)
}

func nox_xxx_forEachSprite_49AB00(a1 *int4, cfnc func(*client.Drawable, unsafe.Pointer), data unsafe.Pointer) {
	if cfnc == nil {
		return
	}
	rect := image.Rect(int(a1.field_0), int(a1.field_4), int(a1.field_8), int(a1.field_C))
	GetClient().Cli().Objs.EachInRect(rect, func(dr *client.Drawable) {
		cfnc(dr, data)
	})
}

// nox_drawable_find_49ABF0
func nox_drawable_find_49ABF0(pt *Point32, r int) *client.Drawable {
	return (*client.Drawable)(GetClient().Nox_drawable_find(image.Point{X: int(pt.X), Y: int(pt.Y)}, r).C())
}

// nox_xxx_spriteLoadAdd_45A360_drawable
func nox_xxx_spriteLoadAdd_45A360_drawable(id, x, y int32) *client.Drawable {
	return (*client.Drawable)(GetClient().Nox_xxx_spriteLoadAdd_45A360_drawable(int(id), image.Pt(int(x), int(y))).C())
}

// nox_xxx_sprite_45A110_drawable
func nox_xxx_sprite_45A110_drawable(dr *client.Drawable) {
	GetClient().Cli().Objs.List34Add(dr)
}

// nox_xxx_netSpriteByCodeStatic_45A720
func nox_xxx_netSpriteByCodeStatic_45A720(id uint32) *client.Drawable {
	return (*client.Drawable)(GetClient().Cli().Objs.ByNetCodeStatic(int(id)).C())
}

// nox_xxx_netSpriteByCodeDynamic_45A6F0
func nox_xxx_netSpriteByCodeDynamic_45A6F0(id uint32) *client.Drawable {
	return (*client.Drawable)(GetClient().Cli().Objs.ByNetCodeDynamic(int(id)).C())
}

// nox_xxx_cliRemoveHealthbar_459E30
func nox_xxx_cliRemoveHealthbar_459E30(dr *client.Drawable, v uint8) {
	GetClient().Cli().Objs.RemoveHealthBar(dr, v)
}

// sub_45A670
func sub_45A670(a1 uint32) {
	GetClient().Sub_45A670(a1)
}

// nox_xxx_spriteTransparentDecay_49B950
func nox_xxx_spriteTransparentDecay_49B950(dr *client.Drawable, a2 int32) {
	GetClient().Cli().Objs.TransparentDecay(dr, int(a2))
}

// sub_459DD0
func sub_459DD0(dr *client.Drawable, a2 uint8) {
	GetClient().Cli().Objs.MinimapAdd(dr, a2)
}

// nox_xxx_spriteToList_49BC80_drawable
func nox_xxx_spriteToList_49BC80_drawable(dr *client.Drawable) {
	GetClient().Cli().Objs.ClientUpdateAdd(dr)
}

// nox_xxx_spriteDelete_45A4B0
func nox_xxx_spriteDelete_45A4B0(dr *client.Drawable) {
	GetClient().Nox_xxx_spriteDelete_45A4B0(dr)
}

// nox_new_drawable_for_thing
func nox_new_drawable_for_thing(i int32) *client.Drawable {
	return (*client.Drawable)(GetClient().Nox_new_drawable_for_thing(int(i)).C())
}

// nox_xxx_spriteDeleteStatic_45A4E0_drawable
func nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr *client.Drawable) {
	GetClient().Nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
}

// nox_xxx_spriteToSightDestroyList_49BAB0_drawable
func nox_xxx_spriteToSightDestroyList_49BAB0_drawable(dr *client.Drawable) {
	GetClient().Cli().Objs.List6Add(dr)
}

// sub_45A060
func sub_45A060() *client.Drawable {
	return (*client.Drawable)(GetClient().Cli().Objs.FirstList1().C())
}

// nox_xxx_cliFirstMinimapObj_459EB0
func nox_xxx_cliFirstMinimapObj_459EB0() *client.Drawable {
	return (*client.Drawable)(GetClient().Cli().Objs.FirstMinimapList().C())
}

// nox_xxx_cliGetSpritePlayer_45A000
func nox_xxx_cliGetSpritePlayer_45A000() *client.Drawable {
	return (*client.Drawable)(GetClient().Cli().Objs.FirstPlayerList().C())
}

// nox_xxx_getSomeSprite_49BD40
func nox_xxx_getSomeSprite_49BD40() *client.Drawable {
	return (*client.Drawable)(GetClient().Cli().Objs.FirstList5().C())
}

// sub_45A090
func sub_45A090() *client.Drawable {
	return (*client.Drawable)(GetClient().Cli().Objs.FirstList8().C())
}

// nox_xxx_sprite_45A030
func nox_xxx_sprite_45A030() *client.Drawable {
	return (*client.Drawable)(GetClient().Cli().Objs.FirstList2().C())
}

// nox_xxx_sprite_49BA10
func nox_xxx_sprite_49BA10(dr *client.Drawable) {
	GetClient().Cli().Objs.DeadlineRemove(dr)
}

// sub_49BCD0
func sub_49BCD0(dr *client.Drawable) {
	GetClient().Cli().Objs.ClientUpdateDelete(dr)
}

// nox_xxx_spriteDeleteAll_45A5E0
func nox_xxx_spriteDeleteAll_45A5E0(a1 int32) {
	GetClient().Nox_xxx_spriteDeleteAll_45A5E0(int(a1))
}

func Nox_xxx_client_4984B0_drawable(dr *client.Drawable) int {
	return int(nox_xxx_client_4984B0_drawable(dr))
}

func Nox_xxx_spriteGetMB_476F80() *client.Drawable {
	return (*client.Drawable)(dword_5d4594_1096640)
}

func Nox_xxx_clientGetSpriteAtCursor_476F90() *client.Drawable {
	return (*client.Drawable)(nox_client_spriteUnderCursorXxx_1096644)
}
func Get_dword_5d4594_1096640() *client.Drawable {
	return AsDrawableP(unsafe.Pointer(dword_5d4594_1096640))
}
func Set_dword_5d4594_1096640(dr *client.Drawable) {
	dword_5d4594_1096640 = dr
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
func Sub_49C520(dr *client.Drawable) int {
	return int(sub_49C520(dr))
}
