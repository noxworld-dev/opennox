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
#include "client__draw__selectdw.h"
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

uint32_t* sub_495B50(uint32_t* a1);

extern unsigned int nox_frame_xxx_2598000;

int nox_drawable_count = 0;
nox_alloc_class* nox_alloc_drawable = 0;
nox_drawable* nox_drawable_head_unk1 = 0;
nox_drawable* nox_drawable_head_unk2 = 0;
nox_drawable* nox_drawable_head_unk3 = 0;
nox_drawable* nox_drawable_head_unk4 = 0;

//----- (0045A020) --------------------------------------------------------
int nox_get_drawable_count() { return nox_drawable_count; }

//----- (0045A030) --------------------------------------------------------
int nox_xxx_sprite_45A030() { return nox_drawable_head_unk2; }

//----- (0045A1D0) --------------------------------------------------------
int nox_alloc_drawable_init(int cnt) {
	nox_alloc_drawable = nox_new_alloc_class("drawableClass", sizeof(nox_drawable), cnt);
	return nox_alloc_drawable != 0;
}

//----- (0045A200) --------------------------------------------------------
void nox_drawable_free() {
	nox_free_alloc_class(nox_alloc_drawable);
	nox_alloc_drawable = 0;
	nox_drawable_head_unk2 = 0;
	nox_drawable_head_unk1 = 0;
	nox_drawable_head_unk3 = 0;
	nox_drawable_head_unk4 = 0;
	nox_drawable_count = 0;
}

//----- (00495B00) --------------------------------------------------------
void sub_495B00(nox_drawable* dr) {
	int a1 = dr;
	uint32_t* v1; // esi
	uint32_t* v2; // edi

	v1 = *(uint32_t**)(a1 + 456);
	if (v1) {
		do {
			v2 = (uint32_t*)v1[16];
			sub_495B50(v1);
			nox_alloc_class_free_obj_first(*(unsigned int**)getMemAt(0x5D4594, 1203868), v1);
			v1 = v2;
		} while (v2);
		*(uint32_t*)(a1 + 456) = 0;
	} else {
		*(uint32_t*)(a1 + 456) = 0;
	}
}

//----- (0045A4B0) --------------------------------------------------------
int nox_xxx_spriteDelete_45A4B0(nox_drawable* dr) {
	sub_495B00(dr);
	nox_alloc_class_free_obj_first(nox_alloc_drawable, dr);
	return --nox_drawable_count;
}

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

//----- (0045A330) --------------------------------------------------------
void* nox_xxx_spriteFromCache_45A330_drawable() {
	if (!nox_drawable_head_unk4) {
		return 0;
	}

	nox_xxx_spriteDeleteStatic_45A4E0_drawable(nox_drawable_head_unk4);
	return nox_alloc_class_new_obj_zero(nox_alloc_drawable);
}

//----- (0045A240) --------------------------------------------------------
nox_drawable* nox_new_drawable_for_thing(int i) {
	int v4; // eax

	nox_drawable* v1 = (nox_drawable*)nox_alloc_class_new_obj_zero(nox_alloc_drawable);
	if (!v1) {
		v1 = nox_xxx_spriteFromCache_45A330_drawable();
	}
	if (!v1) {
		return 0;
	}

	if (!nox_drawable_link_thing(v1, i)) {
		return 0;
	}

	int (*draw_fnc)(unsigned int*, nox_drawable*);
	draw_fnc = v1->draw_func;
	if (draw_fnc == nox_thing_static_random_draw) {
		v4 = nox_common_randomIntMinMax_415FF0(0, *(unsigned char*)((char*)v1->field_76 + 8) - 1,
											   "C:\\NoxPost\\src\\Client\\Drawable\\drawable.c", 401);
		nox_xxx_spriteSetFrameMB_45AB80(v1, v4);
	} else if (draw_fnc == nox_thing_red_spark_draw || draw_fnc == nox_thing_blue_spark_draw ||
			   draw_fnc == nox_thing_yellow_spark_draw || draw_fnc == nox_thing_green_spark_draw ||
			   draw_fnc == nox_thing_cyan_spark_draw) {
		*((unsigned short*)v1 + 26 * 2) = 35;
		*((unsigned char*)v1 + 74 * 4) = 2;
	} else {
		nox_xxx_spriteSetFrameMB_45AB80(v1, 0);
	}
	v1->field_79 = nox_frame_xxx_2598000;
	v1->field_85 = nox_frame_xxx_2598000;
	nox_drawable_count++;
	v1->field_120 = 0;
	v1->field_121 = 0;
	return v1;
}
