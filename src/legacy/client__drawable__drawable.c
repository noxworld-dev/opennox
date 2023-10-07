#include "client__drawable__drawable.h"
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
#include "client__draw__mondraw.h"
#include "client__draw__npcdraw.h"
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
#include "client__draw__vectdraw.h"
#include "client__draw__vortexdraw.h"
#include "client__draw__weapondraw.h"

#include "GAME2.h"
#include "common__random.h"

nox_parse_thing_draw_funcs_t nox_parse_thing_draw_funcs[] = {
	{"NoDraw", 0, 0, 0},
	{"DebugDraw", &nox_thing_debug_draw, 0, 0},
	{"StaticDraw", &nox_thing_static_draw, 1, &nox_things_static_draw_parse},
	{"StaticRandomDraw", &nox_thing_static_random_draw, 2, &nox_things_static_random_draw_parse},
	{"DoorDraw", &nox_thing_door_draw, 2, &nox_things_door_draw_parse},
	{"AnimateDraw", &nox_thing_animate_draw, 3, &nox_things_animate_draw_parse},
	{"ConditionalAnimateDraw", &nox_thing_cond_animate_draw, 4, &nox_things_cond_animate_draw_parse},
	{"MonsterGeneratorDraw", &nox_thing_monster_gen_draw, 4, &nox_things_cond_animate_draw_parse},
	{"VectorAnimateDraw", &nox_thing_vector_animate_draw, 5, &nox_things_vector_animate_draw_parse},
	{"MonsterDraw", &nox_thing_monster_draw, 7, &nox_things_monster_draw_parse},
	{"MaidenDraw", &nox_thing_maiden_draw, 7, &nox_things_maiden_draw_parse},
	{"AnimateStateDraw", &nox_thing_animate_state_draw, 8, &nox_things_animate_state_draw_parse},
	{"PlayerDraw", &nox_thing_player_draw, 6, &nox_things_player_draw_parse},
	{"SlaveDraw", &nox_thing_slave_draw, 2, &nox_things_slave_draw_parse},
	{"TriggerDraw", &nox_thing_trigger_draw, 0, 0},
	{"PressurePlateDraw", &nox_thing_pressure_plate_draw, 0, 0},
	{"LightningDraw", &nox_thing_lightning_draw, 0, 0},
	{"ChainLightningBoltDraw", &nox_thing_chain_lightning_bolt_draw, 0, 0},
	{"EnergyBoltDraw", &nox_thing_energy_bolt_draw, 0, 0},
	{"GreenBoltDraw", &nox_thing_green_bolt_draw, 0, 0},
	{"PlasmaDraw", &nox_thing_plasma_draw, 0, 0},
	{"YellowSparkDraw", &nox_thing_yellow_spark_draw, 0, 0},
	{"RedSparkDraw", &nox_thing_red_spark_draw, 0, 0},
	{"BlueSparkDraw", &nox_thing_blue_spark_draw, 0, 0},
	{"CyanSparkDraw", &nox_thing_cyan_spark_draw, 0, 0},
	{"GreenSparkDraw", &nox_thing_green_spark_draw, 0, 0},
	{"VioletSparkDraw", &nox_thing_violet_spark_draw, 0, 0},
	{"WhiteSparkDraw", &nox_thing_white_spark_draw, 0, 0},
	{"BlueRainSparkDraw", &nox_thing_blue_rain_spark_draw, 0, 0},
	{"DeathBallSparkDraw", &nox_thing_death_ball_spark_draw, 0, 0},
	{"PixieDraw", &nox_thing_pixie_draw, 0, 0},
	{"PixieDustDraw", &nox_thing_pixie_dust_draw, 0, 0},
	{"ParticleDraw", &nox_thing_particle_draw, 0, 0},
	{"BubbleDraw", &nox_thing_bubble_draw, 0, 0},
	{"VortexDraw", &nox_thing_vortex_draw, 0, 0},
	{"BlackPowderDraw", &nox_thing_black_powder_draw, 0, 0},
	{"SpiderSpitDraw", &nox_thing_spider_spit_draw, 0, 0},
	{"GlyphDraw", &nox_thing_glyph_draw, 3, &nox_things_animate_draw_parse},
	{"BoulderDraw", &nox_thing_boulder_draw, 2, &nox_things_slave_draw_parse},
	{"DrainManaDraw", &nox_thing_drain_mana_draw, 0, 0},
	{"GlowOrbDraw", &nox_thing_glow_orb_draw, 0, 0},
	{"GlowOrbMoveDraw", &nox_thing_glow_orb_move_draw, 0, 0},
	{"MagicDraw", &nox_thing_magic_draw, 0, 0},
	{"MagicMissileDraw", &nox_thing_magic_missle_draw, 0, 0},
	{"MagicTailLinkDraw", &nox_thing_magic_tail_link_draw, 0, 0},
	{"MagicMissileTailLinkDraw", &nox_thing_magic_missle_tail_link_draw, 0, 0},
	{"MagicSparkleDraw", &nox_thing_magic_sparkle_draw, 0, 0},
	{"PlayerWaypointDraw", &nox_thing_player_waypoint_draw, 0, 0},
	{"WeaponDraw", &nox_thing_weapon_draw, 1, &nox_things_static_draw_parse},
	{"ArmorDraw", &nox_thing_armor_draw, 1, &nox_things_static_draw_parse},
	{"WeaponAnimateDraw", &nox_thing_weapon_animate_draw, 3, &nox_things_animate_draw_parse},
	{"ArmorAnimateDraw", &nox_thing_armor_animate_draw, 3, &nox_things_animate_draw_parse},
	{"FlagDraw", &nox_thing_flag_draw, 3, &nox_things_animate_draw_parse},
	{"BaseDraw", &nox_thing_base_draw, 1, &nox_things_static_draw_parse},
	{"NPCDraw", &nox_thing_npc_draw, 0, 0},
	{"SphericalShieldDraw", &nox_thing_spherical_shield_draw, 3, &nox_things_animate_draw_parse},
	{"SummonEffectDraw", &nox_thing_summon_effect_draw, 3, &nox_things_animate_draw_parse},
	{"ReleasedSoulDraw", &nox_thing_released_soul_draw, 5, &nox_things_vector_animate_draw_parse},
	{"UndeadKillerDraw", &nox_thing_undead_killer_draw, 0, 0},
	{"ArrowDraw", &nox_thing_arrow_draw, 2, &nox_things_slave_draw_parse},
	{"WeakArrowDraw", &nox_thing_weak_arrow_draw, 2, &nox_things_slave_draw_parse},
	{"ArrowTailLinkDraw", &nox_thing_arrow_tail_link_draw, 0, 0},
	{"WeakArrowTailLinkDraw", &nox_thing_weak_arrow_tail_link_draw, 0, 0},
	{"BlueRainDraw", &nox_thing_blue_rain_draw, 0, 0},
	{"LevelUpDraw", &nox_thing_levelup_draw, 0, 0},
	{"OblivionUpDraw", &nox_thing_oblivion_up_draw, 0, 0},
	{"RainOrbDraw", &nox_thing_rain_orb_draw, 0, 0},
	{"HarpoonDraw", &nox_thing_harpoon_draw, 2, &nox_things_slave_draw_parse},
	{"HarpoonRopeDraw", &nox_thing_harpoon_rope_draw, 0, 0},
};
int nox_parse_thing_draw_funcs_cnt = sizeof(nox_parse_thing_draw_funcs) / sizeof(nox_parse_thing_draw_funcs_t);
