//go:build !server

package legacy

/*
#include "defs.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"
#include "client__draw__glowdraw.h"
#include "client__gui__guiggovr.h"
void nox_xxx_tileDrawMB_481C20_A(nox_draw_viewport_t* vp, int v3);
void nox_xxx_tileDrawMB_481C20_B(nox_draw_viewport_t* vp, int v78);
void nox_xxx_tileDrawMB_481C20_C_textured(nox_draw_viewport_t* vp, int v72, int v78);
void  nox_xxx_cliLight16_469140(nox_drawable* dr, nox_draw_viewport_t* vp);
void nox_xxx_clientDrawAll_436100_draw_A();
void nox_xxx_clientDrawAll_436100_draw_B();
void nox_xxx_drawAllMB_475810_draw_A(nox_draw_viewport_t* vp);
int nox_xxx_drawAllMB_475810_draw_B(nox_draw_viewport_t* vp);
void nox_xxx_drawAllMB_475810_draw_C(nox_draw_viewport_t* vp, int v36, int v7);
int sub_436F50();
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/server"
)

func Nox_xxx_clientDrawAll_436100_draw_A() {
	C.nox_xxx_clientDrawAll_436100_draw_A()
}

func Nox_xxx_drawMinimapAndLines_4738E0() {
	C.nox_xxx_drawMinimapAndLines_4738E0()
}

func Nox_xxx_clientDrawAll_436100_draw_B() {
	C.nox_xxx_clientDrawAll_436100_draw_B()
}

func Sub_436F50() {
	C.sub_436F50()
}

func Sub_437100() {
	C.sub_437100()
}

func Sub_470DE0() {
	C.sub_470DE0()
}

func Nox_xxx_clientEnumHover_476FA0() {
	C.nox_xxx_clientEnumHover_476FA0()
}

func Nox_xxx_spriteDeleteSomeList_49C4B0() {
	C.nox_xxx_spriteDeleteSomeList_49C4B0()
}

func Sub_49BBC0() {
	C.sub_49BBC0()
}

func Nox_xxx_polygonDrawColor_421B80() {
	C.nox_xxx_polygonDrawColor_421B80()
}

func Nox_xxx_cliToggleObsWindow_4357A0() {
	C.nox_xxx_cliToggleObsWindow_4357A0()
}

func Nox_xxx_motd_4467F0() {
	C.nox_xxx_motd_4467F0()
}

func Sub_42EBA0() int {
	return int(C.sub_42EBA0())
}

func Sub_49B6E0() {
	C.sub_49B6E0()
}

func Get_nox_thing_glow_orb_draw() unsafe.Pointer {
	return C.nox_thing_glow_orb_draw
}

func Nox_xxx_drawAllMB_475810_draw_B(vp *noxrender.Viewport) int {
	return int(C.nox_xxx_drawAllMB_475810_draw_B((*nox_draw_viewport_t)(vp.C())))
}
func Sub_4C5060(vp *noxrender.Viewport) {
	C.sub_4C5060((*nox_draw_viewport_t)(vp.C()))
}
func Nox_xxx_drawWalls_473C10(vp *noxrender.Viewport, a2 *server.Wall) {
	C.nox_xxx_drawWalls_473C10((*nox_draw_viewport_t)(vp.C()), a2.C())
}
func Sub_4761B0(dr *client.Drawable) int {
	return int(C.sub_4761B0((*nox_drawable)(dr.C())))
}
func Sub_476080(a1 unsafe.Pointer) int {
	return int(C.sub_476080((*C.uchar)(a1)))
}
func Sub_459DB0(dr *client.Drawable) int {
	return int(C.sub_459DB0((*nox_drawable)(dr.C())))
}
func Sub_49A6A0(vp *noxrender.Viewport, dr *client.Drawable) {
	C.sub_49A6A0((*nox_draw_viewport_t)(vp.C()), (*nox_drawable)(dr.C()))
}
func Nox_xxx_sprite_4756E0_drawable(dr *client.Drawable) int {
	return int(C.nox_xxx_sprite_4756E0_drawable((*nox_drawable)(dr.C())))
}
func Nox_xxx_sprite_475740_drawable(dr *client.Drawable) int {
	return int(C.nox_xxx_sprite_475740_drawable((*nox_drawable)(dr.C())))
}
func Nox_xxx_sprite_4757A0_drawable(dr *client.Drawable) int {
	return int(C.nox_xxx_sprite_4757A0_drawable((*nox_drawable)(dr.C())))
}
func Sub_4757D0_drawable(dr *client.Drawable) int {
	return int(C.sub_4757D0_drawable((*nox_drawable)(dr.C())))
}
func Nox_xxx_tileDrawImpl_4826A0(vp *noxrender.Viewport) {
	C.nox_xxx_tileDrawImpl_4826A0((*nox_draw_viewport_t)(vp.C()))
}
func Nox_xxx_tileDrawMB_481C20_A(vp *noxrender.Viewport, a2 int) {
	C.nox_xxx_tileDrawMB_481C20_A((*nox_draw_viewport_t)(vp.C()), C.int(a2))
}
func Nox_xxx_tileDrawMB_481C20_B(vp *noxrender.Viewport, a2 int) {
	C.nox_xxx_tileDrawMB_481C20_B((*nox_draw_viewport_t)(vp.C()), C.int(a2))
}
func Nox_xxx_tileCheckRedrawMB_482570(vp *noxrender.Viewport) int {
	return int(C.nox_xxx_tileCheckRedrawMB_482570((*nox_draw_viewport_t)(vp.C())))
}
