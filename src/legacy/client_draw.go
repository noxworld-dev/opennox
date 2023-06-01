//go:build !server

package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/server"
)

func Nox_xxx_clientDrawAll_436100_draw_A() {
	nox_xxx_clientDrawAll_436100_draw_A()
}

func Nox_xxx_drawMinimapAndLines_4738E0() {
	nox_xxx_drawMinimapAndLines_4738E0()
}

func Nox_xxx_clientDrawAll_436100_draw_B() {
	nox_xxx_clientDrawAll_436100_draw_B()
}

func Sub_436F50() {
	sub_436F50()
}

func Sub_437100() {
	sub_437100()
}

func Sub_470DE0() {
	sub_470DE0()
}

func Nox_xxx_clientEnumHover_476FA0() {
	nox_xxx_clientEnumHover_476FA0()
}

func Nox_xxx_spriteDeleteSomeList_49C4B0() {
	nox_xxx_spriteDeleteSomeList_49C4B0()
}

func Sub_49BBC0() {
	sub_49BBC0()
}

func Nox_xxx_polygonDrawColor_421B80() {
	nox_xxx_polygonDrawColor_421B80()
}

func Nox_xxx_cliToggleObsWindow_4357A0() {
	nox_xxx_cliToggleObsWindow_4357A0()
}

func Nox_xxx_motd_4467F0() {
	nox_xxx_motd_4467F0()
}

func Sub_42EBA0() int {
	return int(sub_42EBA0())
}

func Sub_49B6E0() {
	sub_49B6E0()
}

func Sub_45AB40() {
	sub_45AB40()
}

func Sub_498AE0() {
	sub_498AE0()
}

func Get_nox_thing_glow_orb_draw() unsafe.Pointer {
	return funAddrP(nox_thing_glow_orb_draw)
}

func Sub_49BD70(vp *noxrender.Viewport) {
	sub_49BD70((*nox_draw_viewport_t)(vp.C()))
}

func Nox_xxx_drawBlack_496150(vp *noxrender.Viewport) {
	nox_xxx_drawBlack_496150((*nox_draw_viewport_t)(vp.C()))
}
func Nox_xxx_drawAllMB_475810_draw_B(vp *noxrender.Viewport) int {
	return int(nox_xxx_drawAllMB_475810_draw_B((*nox_draw_viewport_t)(vp.C())))
}
func Nox_video_drawCursorSelectCircle_4773C0(vp *noxrender.Viewport) {
	nox_video_drawCursorSelectCircle_4773C0((*nox_draw_viewport_t)(vp.C()))
}
func Sub_4C5060(vp *noxrender.Viewport) {
	sub_4C5060((*nox_draw_viewport_t)(vp.C()))
}
func Nox_xxx_drawWalls_473C10(vp *noxrender.Viewport, a2 *server.Wall) {
	nox_xxx_drawWalls_473C10((*nox_draw_viewport_t)(vp.C()), a2.C())
}
func Sub_4761B0(dr *client.Drawable) int {
	return int(sub_4761B0((*nox_drawable)(dr.C())))
}
func Sub_476080(a1 unsafe.Pointer) int {
	return int(sub_476080((*byte)(a1)))
}
func Sub_459DB0(dr *client.Drawable) int {
	return int(sub_459DB0((*nox_drawable)(dr.C())))
}
func Sub_49A6A0(vp *noxrender.Viewport, dr *client.Drawable) {
	sub_49A6A0((*nox_draw_viewport_t)(vp.C()), (*nox_drawable)(dr.C()))
}
func Nox_xxx_sprite_4756E0_drawable(dr *client.Drawable) int {
	return int(nox_xxx_sprite_4756E0_drawable((*nox_drawable)(dr.C())))
}
func Nox_xxx_sprite_475740_drawable(dr *client.Drawable) int {
	return int(nox_xxx_sprite_475740_drawable((*nox_drawable)(dr.C())))
}
func Nox_xxx_sprite_4757A0_drawable(dr *client.Drawable) int {
	return int(nox_xxx_sprite_4757A0_drawable((*nox_drawable)(dr.C())))
}
func Sub_4757D0_drawable(dr *client.Drawable) int {
	return int(sub_4757D0_drawable((*nox_drawable)(dr.C())))
}
func Nox_xxx_tileDrawImpl_4826A0(vp *noxrender.Viewport) {
	nox_xxx_tileDrawImpl_4826A0((*nox_draw_viewport_t)(vp.C()))
}
func Nox_xxx_tileDrawMB_481C20_A(vp *noxrender.Viewport, a2 int) {
	nox_xxx_tileDrawMB_481C20_A((*nox_draw_viewport_t)(vp.C()), int32(a2))
}
func Nox_xxx_tileDrawMB_481C20_B(vp *noxrender.Viewport, a2 int) {
	nox_xxx_tileDrawMB_481C20_B((*nox_draw_viewport_t)(vp.C()), int32(a2))
}
func Nox_xxx_tileCheckRedrawMB_482570(vp *noxrender.Viewport) int {
	return int(nox_xxx_tileCheckRedrawMB_482570((*nox_draw_viewport_t)(vp.C())))
}
