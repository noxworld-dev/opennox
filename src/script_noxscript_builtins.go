package opennox

/*
#include "server__script__internal.h"
extern unsigned int nox_xxx_wallSounds_2386840;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
int nox_xxx_destroyEveryChatMB_528D60();
void sub_43D9B0(int a1, int a2);
int sub_43DA80();
void sub_43DAD0();
*/
import "C"
import (
	"image"
	"strings"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

//export nox_script_secondTimer_512320
func nox_script_secondTimer_512320() C.int {
	s := noxServer
	fnc := s.noxScriptPopU32()
	dt := s.noxScriptPopU32()
	s.scriptPushU32(s.noxScript.newScriptTimer(int(dt*gameFPS()), fnc, 0))
	return 0
}

//export nox_script_frameTimer_512350
func nox_script_frameTimer_512350() C.int {
	s := noxServer
	fnc := s.noxScriptPopU32()
	df := int(s.noxScriptPopU32())
	s.scriptPushU32(s.noxScript.newScriptTimer(df, fnc, 0))
	return 0
}

//export nox_script_deleteObject_5128B0
func nox_script_deleteObject_5128B0() C.int {
	s := noxServer
	if obj := s.noxScriptPopObject(); obj != nil {
		obj.Delete()
	}
	return 0
}

//export nox_script_getObject2_5129C0
func nox_script_getObject2_5129C0() C.int {
	s := noxServer
	_ = s.noxScriptPopObject()
	return 0
}

//export nox_script_getObject3_5129E0
func nox_script_getObject3_5129E0() C.int {
	s := noxServer
	_ = s.noxScriptPopObject()
	return 0
}

//export nox_script_printToCaller_512B10
func nox_script_printToCaller_512B10() C.int {
	s := noxServer
	strID := s.noxScriptPopString()
	if c := asObject(C.nox_script_get_caller()).AsUnit(); c != nil && c.Class().Has(object.ClassPlayer) {
		str := s.Strings().GetStringInFile(strman.ID(strID), "CScrFunc.c")
		nox_xxx_netSendLineMessage_4D9EB0(c, str)
	}
	return 0
}

//export nox_script_printToAll_512B60
func nox_script_printToAll_512B60() C.int {
	s := noxServer
	strID := s.noxScriptPopString()
	str := s.Strings().GetStringInFile(strman.ID(strID), "CScrFunc.c")
	PrintToPlayers(str)
	return 0
}

//export nox_script_returnOne_512C10
func nox_script_returnOne_512C10() C.int { return 1 }

//export nox_script_randomFloat_512D70
func nox_script_randomFloat_512D70() C.int {
	s := noxServer
	max := float64(s.noxScriptPopF32())
	min := float64(s.noxScriptPopF32())
	val := noxRndCounter1.FloatClamp(min, max)
	s.scriptPushF32(float32(val))
	return 0
}

//export nox_script_randomInt_512DB0
func nox_script_randomInt_512DB0() C.int {
	s := noxServer
	max := int(s.noxScriptPopU32())
	min := int(s.noxScriptPopU32())
	val := noxRndCounter1.IntClamp(min, max)
	s.scriptPushI32(int32(val))
	return 0
}

//export nox_script_timerSecSpecial_512DE0
func nox_script_timerSecSpecial_512DE0() C.int {
	s := noxServer
	fnc := s.noxScriptPopU32()
	arg := s.noxScriptPopU32()
	dt := s.noxScriptPopU32()
	s.scriptPushU32(s.noxScript.newScriptTimer(int(dt*gameFPS()), fnc, arg))
	return 0
}

//export nox_script_specialTimer_512E10
func nox_script_specialTimer_512E10() C.int {
	s := noxServer
	fnc := s.noxScriptPopU32()
	arg := s.noxScriptPopU32()
	df := int(s.noxScriptPopU32())
	s.scriptPushU32(s.noxScript.newScriptTimer(df, fnc, arg))
	return 0
}

//export nox_script_builtin_513C60
func nox_script_builtin_513C60() C.int { return 0 }

//export nox_script_fn58_513F10
func nox_script_fn58_513F10() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_fn59_513F20
func nox_script_fn59_513F20() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_fn5A_513F30
func nox_script_fn5A_513F30() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_fn5B_513F40
func nox_script_fn5B_513F40() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_Fn5C_513F50
func nox_script_Fn5C_513F50() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_Fn5D_513F60
func nox_script_Fn5D_513F60() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_CancelTimer_5141F0
func nox_script_CancelTimer_5141F0() C.int {
	s := noxServer
	act := s.noxScriptPopU32()
	ok := s.noxScript.actCancel(act)
	s.scriptPushBool(ok)
	return 0
}

//export nox_script_Effect_514210
func nox_script_Effect_514210() C.int {
	s := noxServer
	pos2 := s.noxScriptPopPointf()
	pos := s.noxScriptPopPointf()
	name := "MSG_FX_" + strings.ToUpper(s.noxScriptPopString())
	dpos := image.Point{
		X: nox_script_builtinGetF40(),
		Y: nox_script_builtinGetF44(),
	}
	pos = pos.Add(types.Point2f(dpos))

	switch fx := s.noxScript.fxNames[name]; fx {
	case noxnet.MSG_FX_BLUE_SPARKS,
		noxnet.MSG_FX_YELLOW_SPARKS,
		noxnet.MSG_FX_CYAN_SPARKS,
		noxnet.MSG_FX_VIOLET_SPARKS,
		noxnet.MSG_FX_EXPLOSION,
		noxnet.MSG_FX_LESSER_EXPLOSION,
		noxnet.MSG_FX_COUNTERSPELL_EXPLOSION,
		noxnet.MSG_FX_THIN_EXPLOSION,
		noxnet.MSG_FX_TELEPORT,
		noxnet.MSG_FX_SMOKE_BLAST,
		noxnet.MSG_FX_DAMAGE_POOF,
		noxnet.MSG_FX_RICOCHET,
		noxnet.MSG_FX_WHITE_FLASH,
		noxnet.MSG_FX_TURN_UNDEAD,
		noxnet.MSG_FX_MANA_BOMB_CANCEL:
		nox_xxx_netSendPointFx_522FF0(fx, pos)
	case noxnet.MSG_FX_LIGHTNING,
		noxnet.MSG_FX_ENERGY_BOLT,
		noxnet.MSG_FX_PLASMA,
		noxnet.MSG_FX_DRAIN_MANA,
		noxnet.MSG_FX_CHARM,
		noxnet.MSG_FX_GREATER_HEAL,
		noxnet.MSG_FX_DEATH_RAY,
		noxnet.MSG_FX_SENTRY_RAY:
		nox_xxx_netSendRayFx_5232F0(fx, dpos.Add(pos.Point()), dpos.Add(pos2.Point()))
	case noxnet.MSG_FX_SPARK_EXPLOSION:
		nox_xxx_netSparkExplosionFx_5231B0(pos, byte(pos2.X))
	case noxnet.MSG_FX_JIGGLE:
		nox_xxx_earthquakeSend_4D9110(pos, int(pos2.X))
	case noxnet.MSG_FX_GREEN_BOLT:
		nox_xxx_netSendFxGreenBolt_523790(dpos.Add(pos.Point()), dpos.Add(pos2.Point()), 30)
	case noxnet.MSG_FX_VAMPIRISM:
		nox_xxx_netSendVampFx_523270(fx, dpos.Add(pos.Point()), dpos.Add(pos2.Point()), 100)
	}
	return 0
}

//export nox_script_Pop2_74_514BA0
func nox_script_Pop2_74_514BA0() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_RemoveChat_514BB0
func nox_script_RemoveChat_514BB0() C.int {
	s := noxServer
	if u := s.noxScriptPopObject().AsUnit(); u != nil {
		nox_xxx_netKillChat_528D00(u)
	}
	return 0
}

//export nox_script_NoChatAll_514BD0
func nox_script_NoChatAll_514BD0() C.int {
	C.nox_xxx_destroyEveryChatMB_528D60()
	return 0
}

//export nox_script_CastObject2_514F10
func nox_script_CastObject2_514F10() C.int {
	s := noxServer
	targID := s.noxScriptPopU32()
	caster := s.noxScriptPopObject().AsUnit()
	sp := spell.ParseID(s.noxScriptPopString())
	if !sp.Valid() {
		return 0
	}
	if caster == nil {
		return 0
	}
	if caster.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
		return 0
	}
	targ := s.nox_server_scriptValToObjectPtr(int(targID))
	if targ == nil {
		return 0
	}
	caster.direction1 = C.ushort(nox_xxx_math_509ED0(targ.Pos().Sub(caster.Pos())))
	s.castSpellBy(sp, caster, targ, targ.Pos())
	return 0
}

//export nox_script_CastObjectLocation_514FC0
func nox_script_CastObjectLocation_514FC0() C.int {
	s := noxServer
	targPos := s.noxScriptPopPointf()
	caster := s.noxScriptPopObject().AsUnit()
	sp := spell.ParseID(s.noxScriptPopString())
	if !sp.Valid() {
		return 0
	}
	if caster == nil {
		return 0
	}
	caster.direction1 = C.ushort(nox_xxx_math_509ED0(targPos.Sub(caster.Pos())))
	s.castSpellBy(sp, caster, nil, targPos)
	return 0
}

//export nox_script_CastLocationObject_515060
func nox_script_CastLocationObject_515060() C.int {
	s := noxServer
	targ := s.noxScriptPopObject()
	srcPos := s.noxScriptPopPointf()
	sp := spell.ParseID(s.noxScriptPopString())
	if !sp.Valid() {
		return 0
	}
	if targ == nil {
		return 0
	}
	nox_xxx_imagCasterUnit_1569664.SetPos(srcPos)
	nox_xxx_imagCasterUnit_1569664.direction1 = C.ushort(nox_xxx_math_509ED0(targ.Pos().Sub(srcPos)))
	s.castSpellBy(sp, nox_xxx_imagCasterUnit_1569664, targ, targ.Pos())
	return 0
}

//export nox_script_CastLocation2_515130
func nox_script_CastLocation2_515130() C.int {
	s := noxServer
	targPos := s.noxScriptPopPointf()
	srcPos := s.noxScriptPopPointf()
	sp := spell.ParseID(s.noxScriptPopString())
	if !sp.Valid() {
		return 0
	}
	nox_xxx_imagCasterUnit_1569664.SetPos(srcPos)
	nox_xxx_imagCasterUnit_1569664.direction1 = C.ushort(nox_xxx_math_509ED0(targPos.Sub(srcPos)))
	s.castSpellBy(sp, nox_xxx_imagCasterUnit_1569664, nil, targPos)
	return 0
}

//export nox_script_UnBlind_515200
func nox_script_UnBlind_515200() C.int {
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	noxClient.r.FadeOutScreen(25, false, nil)
	return 0
}

//export nox_script_Blind_515220
func nox_script_Blind_515220() C.int {
	noxClient.r.FadeInScreen(25, false, fadeDisableGameDraw)
	return 0
}

//export nox_script_WideScreen_515240
func nox_script_WideScreen_515240() C.int {
	s := noxServer
	s.CinemaPlayers(s.noxScriptPopI32() == 1)
	return 0
}

//export nox_script_IsAttackedBy_5161C0
func nox_script_IsAttackedBy_5161C0() C.int {
	s := noxServer
	obj2 := s.noxScriptPopObject()
	obj1 := s.noxScriptPopObject()
	val := obj1 != nil && obj2 != nil && obj1.isEnemyTo(obj2)
	s.scriptPushBool(val)
	return 0
}

//export nox_script_ForceAutosave_516400
func nox_script_ForceAutosave_516400() C.int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		sub_4DB130("AUTOSAVE")
		sub_4DB170(1, 0, 0)
	}
	return 0
}

//export nox_script_Music_516430
func nox_script_Music_516430() C.int {
	s := noxServer
	v0 := s.noxScriptPopU32()
	v3 := s.noxScriptPopU32()
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43D9B0(C.int(v3), C.int(v0))
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_EVENT)
		buf[1] = byte(v3)
		buf[2] = byte(v0)
		s.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

//export nox_script_DeathScreen_516680
func nox_script_DeathScreen_516680() C.int {
	*memmap.PtrUint32(0x5D4594, 2386832) = 0
	sub_5165D0()
	return 0
}

//export nox_script_Frozen_516920
func nox_script_Frozen_516920() C.int {
	s := noxServer
	val := s.noxScriptPopBool()
	if u := s.noxScriptPopObject().AsUnit(); u != nil {
		u.Freeze(val)
	}
	return 0
}

//export nox_script_NoWallSound_516960
func nox_script_NoWallSound_516960() C.int {
	s := noxServer
	C.nox_xxx_wallSounds_2386840 = C.uint(s.noxScriptPopU32())
	return 0
}

//export nox_script_SetCallback_516970
func nox_script_SetCallback_516970() C.int {
	s := noxServer
	fnc := C.int(s.noxScriptPopU32())
	ev := s.noxScriptPopU32()
	u := s.noxScriptPopObject().AsUnit()
	if u == nil || !u.Class().Has(object.ClassMonster) {
		return 0
	}
	ud := u.updateDataMonster()
	switch ev {
	case 3: // Enemy sighted
		ud.script_enemy_sighted_cb = fnc
	case 4: // Looking for enemy
		ud.script_looking_for_enemy_cb = fnc
	case 5: // Death
		ud.script_death_cb = fnc
	case 6: // Change focus
		ud.script_change_focus_cb = fnc
	case 7: // Is hit
		ud.script_is_hit_cb = fnc
	case 8: // Retreat
		ud.script_retreat_cb = fnc
	case 9: // Collision
		ud.script_collision_cb = fnc
	case 10: // Enemy heard
		ud.script_hear_enemy_cb = fnc
	case 11: // End of waypoint
		ud.script_end_of_waypoint_cb = fnc
	case 13: // Lost sight of enemy
		ud.script_lost_enemy_cb = fnc
	}
	return 0
}

//export nox_script_ClearMessages_516BC0
func nox_script_ClearMessages_516BC0() C.int {
	s := noxServer
	if u := s.noxScriptPopObject().AsUnit(); u != nil {
		nox_xxx_netScriptMessageKill_4D9760(u)
	}
	return 0
}

//export nox_script_StopAllFades_516C10
func nox_script_StopAllFades_516C10() C.int {
	nox_video_stopAllFades_44E040()
	return 0
}

//export nox_script_MusicPushEvent_5164A0
func nox_script_MusicPushEvent_5164A0() C.int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43DA80()
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_PUSH_EVENT)
		noxServer.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

//export nox_script_MusicPopEvent_5164E0
func nox_script_MusicPopEvent_5164E0() C.int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43DAD0()
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_POP_EVENT)
		noxServer.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

//export nox_script_ClearMusic_516520
func nox_script_ClearMusic_516520() C.int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43D9B0(0, 0)
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_EVENT)
		noxServer.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

//export nox_script_EndGame_516E10
func nox_script_EndGame_516E10() C.int {
	s := noxServer
	v := int(s.noxScriptPopI32())
	noxScriptEndGame(v)
	return 0
}

//export nox_script_StartGame_516C20
func nox_script_StartGame_516C20() C.int {
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	return 0
}

//export nox_script_ChangeScore_516E30
func nox_script_ChangeScore_516E30() C.int {
	s := noxServer
	val := int(s.noxScriptPopU32())
	u := s.noxScriptPopObject().AsUnit()
	if u == nil || !u.Class().Has(object.ClassPlayer) {
		return 0
	}
	if val <= 0 {
		nox_xxx_playerSubLessons_4D8EC0(u, -val)
	} else {
		nox_xxx_changeScore_4D8E90(u, val)
	}

	if tm := s.teamByYyy(u.team()); tm != nil {
		s.teamChangeLessons(tm, val+int(tm.lessons))
	}
	nox_xxx_netReportLesson_4D8EF0(u)
	return 0
}

//export nox_script_GetScore_516EA0
func nox_script_GetScore_516EA0() C.int {
	s := noxServer
	u := s.noxScriptPopObject().AsUnit()
	if u == nil || !u.Class().Has(object.ClassPlayer) {
		s.scriptPushU32(0)
		return 0
	}
	pl := u.ControllingPlayer()
	s.scriptPushI32(int32(pl.lessons))
	return 0
}
