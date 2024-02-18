package legacy

/*
#include "defs.h"
#include "client__draw__animdraw.h"
#include "client__draw__armordraw.h"
#include "client__draw__arrowdraw.h"
#include "client__draw__basedraw.h"
#include "client__draw__boulderdraw.h"
#include "client__draw__bubbledraw.h"
#include "client__draw__canidraw.h"
#include "client__draw__debugdraw.h"
#include "client__draw__doordraw.h"
#include "client__draw__drawrays.h"
#include "client__draw__flagdraw.h"
#include "client__draw__fx.h"
#include "client__draw__glowdraw.h"
#include "client__draw__glyphdraw.h"
#include "client__draw__harpoondraw.h"
#include "client__draw__lightning.h"
#include "client__draw__lvupdraw.h"
#include "client__draw__magicdrw.h"
#include "client__draw__maidendraw.h"
#include "client__draw__mgendraw.h"
#include "client__draw__partrain.h"
#include "client__draw__partscrn.h"
#include "client__draw__plasma.h"
#include "client__draw__playerdraw.h"
#include "client__draw__powderdraw.h"
#include "client__draw__pressureplatedraw.h"
#include "client__draw__slavedraw.h"
#include "client__draw__souldraw.h"
#include "client__draw__spiderspitdraw.h"
#include "client__draw__staticdraw.h"
#include "client__draw__summondraw.h"
#include "client__draw__triggerdraw.h"
#include "client__draw__udeddraw.h"
#include "client__draw__vortexdraw.h"
#include "client__draw__weapondraw.h"
int nox_thing_static_random_draw(uint32_t* a1, nox_drawable* dr);
int nox_thing_monster_draw(nox_draw_viewport_t* a1, nox_drawable* dr);
int nox_thing_player_draw(nox_draw_viewport_t* a1, nox_drawable* dr);
int nox_thing_vector_animate_draw(nox_draw_viewport_t* a1, nox_drawable* dr);
int nox_thing_npc_draw(nox_draw_viewport_t* a1, nox_drawable* dr);
int nox_thing_released_soul_draw(nox_draw_viewport_t* a1, nox_drawable* dr);
void nox_xxx_drawObject_4C4770_draw(nox_draw_viewport_t* vp, nox_drawable* dr, void* img);
int sub_495180(int a1, uint16_t* a2, uint16_t* a3, uint8_t* a4);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func init() {
	client.RegisterDraw("StaticDraw", C.nox_thing_static_draw, 1, wrapDrawParseC(C.nox_things_static_draw_parse))
	client.RegisterDraw("StaticRandomDraw", C.nox_thing_static_random_draw, 2, wrapDrawParseC(C.nox_things_static_random_draw_parse))
	client.RegisterDraw("DoorDraw", C.nox_thing_door_draw, 2, wrapDrawParseC(C.nox_things_door_draw_parse))
	client.RegisterDraw("AnimateDraw", C.nox_thing_animate_draw, 3, wrapDrawParseC(C.nox_things_animate_draw_parse))
	client.RegisterDraw("ConditionalAnimateDraw", C.nox_thing_cond_animate_draw, 4, wrapDrawParseC(C.nox_things_cond_animate_draw_parse))
	client.RegisterDraw("MonsterGeneratorDraw", C.nox_thing_monster_gen_draw, 4, wrapDrawParseC(C.nox_things_cond_animate_draw_parse))
	client.RegisterDraw("AnimateStateDraw", C.nox_thing_animate_state_draw, 8, wrapDrawParseC(C.nox_things_animate_state_draw_parse))
	client.RegisterDraw("SlaveDraw", C.nox_thing_slave_draw, 2, wrapDrawParseC(C.nox_things_slave_draw_parse))
	client.RegisterDraw("TriggerDraw", C.nox_thing_trigger_draw, 0, nil)
	client.RegisterDraw("PressurePlateDraw", C.nox_thing_pressure_plate_draw, 0, nil)
	client.RegisterDraw("LightningDraw", C.nox_thing_lightning_draw, 0, nil)
	client.RegisterDraw("ChainLightningBoltDraw", C.nox_thing_chain_lightning_bolt_draw, 0, nil)
	client.RegisterDraw("EnergyBoltDraw", C.nox_thing_energy_bolt_draw, 0, nil)
	client.RegisterDraw("GreenBoltDraw", C.nox_thing_green_bolt_draw, 0, nil)
	client.RegisterDraw("PlasmaDraw", C.nox_thing_plasma_draw, 0, nil)
	client.RegisterDraw("YellowSparkDraw", C.nox_thing_yellow_spark_draw, 0, nil)
	client.RegisterDraw("RedSparkDraw", C.nox_thing_red_spark_draw, 0, nil)
	client.RegisterDraw("BlueSparkDraw", C.nox_thing_blue_spark_draw, 0, nil)
	client.RegisterDraw("CyanSparkDraw", C.nox_thing_cyan_spark_draw, 0, nil)
	client.RegisterDraw("GreenSparkDraw", C.nox_thing_green_spark_draw, 0, nil)
	client.RegisterDraw("VioletSparkDraw", C.nox_thing_violet_spark_draw, 0, nil)
	client.RegisterDraw("WhiteSparkDraw", C.nox_thing_white_spark_draw, 0, nil)
	client.RegisterDraw("BlueRainSparkDraw", C.nox_thing_blue_rain_spark_draw, 0, nil)
	client.RegisterDraw("DeathBallSparkDraw", C.nox_thing_death_ball_spark_draw, 0, nil)
	client.RegisterDraw("PixieDraw", C.nox_thing_pixie_draw, 0, nil)
	client.RegisterDraw("PixieDustDraw", C.nox_thing_pixie_dust_draw, 0, nil)
	client.RegisterDraw("ParticleDraw", C.nox_thing_particle_draw, 0, nil)
	client.RegisterDraw("BubbleDraw", C.nox_thing_bubble_draw, 0, nil)
	client.RegisterDraw("VortexDraw", C.nox_thing_vortex_draw, 0, nil)
	client.RegisterDraw("BlackPowderDraw", C.nox_thing_black_powder_draw, 0, nil)
	client.RegisterDraw("SpiderSpitDraw", C.nox_thing_spider_spit_draw, 0, nil)
	client.RegisterDraw("GlyphDraw", C.nox_thing_glyph_draw, 3, wrapDrawParseC(C.nox_things_animate_draw_parse))
	client.RegisterDraw("BoulderDraw", C.nox_thing_boulder_draw, 2, wrapDrawParseC(C.nox_things_slave_draw_parse))
	client.RegisterDraw("DrainManaDraw", C.nox_thing_drain_mana_draw, 0, nil)
	client.RegisterDraw("GlowOrbDraw", C.nox_thing_glow_orb_draw, 0, nil)
	client.RegisterDraw("GlowOrbMoveDraw", C.nox_thing_glow_orb_move_draw, 0, nil)
	client.RegisterDraw("MagicDraw", C.nox_thing_magic_draw, 0, nil)
	client.RegisterDraw("MagicMissileDraw", C.nox_thing_magic_missle_draw, 0, nil)
	client.RegisterDraw("MagicTailLinkDraw", C.nox_thing_magic_tail_link_draw, 0, nil)
	client.RegisterDraw("MagicMissileTailLinkDraw", C.nox_thing_magic_missle_tail_link_draw, 0, nil)
	client.RegisterDraw("MagicSparkleDraw", C.nox_thing_magic_sparkle_draw, 0, nil)
	client.RegisterDraw("PlayerWaypointDraw", C.nox_thing_player_waypoint_draw, 0, nil)
	client.RegisterDraw("WeaponDraw", C.nox_thing_weapon_draw, 1, wrapDrawParseC(C.nox_things_static_draw_parse))
	client.RegisterDraw("ArmorDraw", C.nox_thing_armor_draw, 1, wrapDrawParseC(C.nox_things_static_draw_parse))
	client.RegisterDraw("WeaponAnimateDraw", C.nox_thing_weapon_animate_draw, 3, wrapDrawParseC(C.nox_things_animate_draw_parse))
	client.RegisterDraw("ArmorAnimateDraw", C.nox_thing_armor_animate_draw, 3, wrapDrawParseC(C.nox_things_animate_draw_parse))
	client.RegisterDraw("FlagDraw", C.nox_thing_flag_draw, 3, wrapDrawParseC(C.nox_things_animate_draw_parse))
	client.RegisterDraw("BaseDraw", C.nox_thing_base_draw, 1, wrapDrawParseC(C.nox_things_static_draw_parse))
	client.RegisterDraw("SphericalShieldDraw", C.nox_thing_spherical_shield_draw, 3, wrapDrawParseC(C.nox_things_animate_draw_parse))
	client.RegisterDraw("SummonEffectDraw", C.nox_thing_summon_effect_draw, 3, wrapDrawParseC(C.nox_things_animate_draw_parse))
	client.RegisterDraw("UndeadKillerDraw", C.nox_thing_undead_killer_draw, 0, nil)
	client.RegisterDraw("ArrowDraw", C.nox_thing_arrow_draw, 2, wrapDrawParseC(C.nox_things_slave_draw_parse))
	client.RegisterDraw("WeakArrowDraw", C.nox_thing_weak_arrow_draw, 2, wrapDrawParseC(C.nox_things_slave_draw_parse))
	client.RegisterDraw("ArrowTailLinkDraw", C.nox_thing_arrow_tail_link_draw, 0, nil)
	client.RegisterDraw("WeakArrowTailLinkDraw", C.nox_thing_weak_arrow_tail_link_draw, 0, nil)
	client.RegisterDraw("BlueRainDraw", C.nox_thing_blue_rain_draw, 0, nil)
	client.RegisterDraw("LevelUpDraw", C.nox_thing_levelup_draw, 0, nil)
	client.RegisterDraw("OblivionUpDraw", C.nox_thing_oblivion_up_draw, 0, nil)
	client.RegisterDraw("RainOrbDraw", C.nox_thing_rain_orb_draw, 0, nil)
	client.RegisterDraw("HarpoonDraw", C.nox_thing_harpoon_draw, 2, wrapDrawParseC(C.nox_things_slave_draw_parse))
	client.RegisterDraw("HarpoonRopeDraw", C.nox_thing_harpoon_rope_draw, 0, nil)
}

var (
	Nox_thing_debug_draw          func(vp *noxrender.Viewport, dr *client.Drawable) int
	Nox_thing_monster_draw        func(vp *noxrender.Viewport, dr *client.Drawable) int
	Nox_thing_vector_animate_draw func(vp *noxrender.Viewport, dr *client.Drawable) int
	Nox_thing_animate_state_draw  func(vp *noxrender.Viewport, dr *client.Drawable) int
	Nox_thing_player_draw         func(vp *noxrender.Viewport, dr *client.Drawable) int
	Nox_thing_npc_draw            func(vp *noxrender.Viewport, dr *client.Drawable) int
)

func wrapDrawParseC(fnc unsafe.Pointer) client.ThingFieldFunc {
	return func(typ *client.ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		StrNCopyBytes(buf, str)
		ccall.CallVoidPtr3(fnc, typ.C(), f.C(), unsafe.Pointer(&buf[0]))
		return nil
	}
}

//export nox_thing_debug_draw
func nox_thing_debug_draw(cvp *nox_draw_viewport_t, cdr *nox_drawable) int {
	return Nox_thing_debug_draw(asViewport(cvp), asDrawable(cdr))
}

//export nox_thing_monster_draw
func nox_thing_monster_draw(vp *nox_draw_viewport_t, dr *nox_drawable) int {
	return Nox_thing_monster_draw(asViewport(vp), asDrawable(dr))
}

//export nox_thing_vector_animate_draw
func nox_thing_vector_animate_draw(vp *nox_draw_viewport_t, dr *nox_drawable) int {
	return Nox_thing_vector_animate_draw(asViewport(vp), asDrawable(dr))
}

//export nox_thing_released_soul_draw
func nox_thing_released_soul_draw(vp *nox_draw_viewport_t, dr *nox_drawable) int {
	return Nox_thing_vector_animate_draw(asViewport(vp), asDrawable(dr))
}

//export nox_thing_animate_state_draw
func nox_thing_animate_state_draw(vp *nox_draw_viewport_t, dr *nox_drawable) int {
	return Nox_thing_animate_state_draw(asViewport(vp), asDrawable(dr))
}

//export nox_thing_player_draw
func nox_thing_player_draw(vp *nox_draw_viewport_t, dr *nox_drawable) int {
	return Nox_thing_player_draw(asViewport(vp), asDrawable(dr))
}

//export nox_thing_npc_draw
func nox_thing_npc_draw(vp *nox_draw_viewport_t, dr *nox_drawable) int {
	return Nox_thing_npc_draw(asViewport(vp), asDrawable(dr))
}

func Nox_xxx_drawObject_4C4770_draw(vp *noxrender.Viewport, dr *client.Drawable, img noxrender.ImageHandle) {
	C.nox_xxx_drawObject_4C4770_draw((*nox_draw_viewport_t)(vp.C()), (*nox_drawable)(dr.C()), unsafe.Pointer(img))
}
func Sub_495180(id int) (cur, max int, alt, ok bool) {
	var (
		curV, maxV C.uint16_t
		altV       C.uint8_t
	)
	ok = C.sub_495180(C.int(id), &curV, &maxV, &altV) != 0
	return int(curV), int(maxV), altV != 0, ok
}

func Get_nox_thing_static_random_draw() unsafe.Pointer {
	return C.nox_thing_static_random_draw
}
func Get_nox_thing_red_spark_draw() unsafe.Pointer {
	return C.nox_thing_red_spark_draw
}
func Get_nox_thing_blue_spark_draw() unsafe.Pointer {
	return C.nox_thing_blue_spark_draw
}
func Get_nox_thing_yellow_spark_draw() unsafe.Pointer {
	return C.nox_thing_yellow_spark_draw
}
func Get_nox_thing_green_spark_draw() unsafe.Pointer {
	return C.nox_thing_green_spark_draw
}
func Get_nox_thing_cyan_spark_draw() unsafe.Pointer {
	return C.nox_thing_cyan_spark_draw
}
func Get_nox_thing_monster_draw() unsafe.Pointer {
	return C.nox_thing_monster_draw
}
func Get_nox_thing_maiden_draw() unsafe.Pointer {
	return C.nox_thing_maiden_draw
}
func Get_nox_thing_player_draw() unsafe.Pointer {
	return C.nox_thing_player_draw
}
func Get_nox_thing_animate_draw() unsafe.Pointer {
	return C.nox_thing_animate_draw
}
func Get_nox_thing_vector_animate_draw() unsafe.Pointer {
	return C.nox_thing_vector_animate_draw
}
func Get_nox_thing_released_soul_draw() unsafe.Pointer {
	return C.nox_thing_released_soul_draw
}
func Get_nox_thing_debug_draw() unsafe.Pointer {
	return C.nox_thing_debug_draw
}
func Get_nox_thing_npc_draw() unsafe.Pointer {
	return C.nox_thing_npc_draw
}
