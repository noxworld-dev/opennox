package opennox

/*
#include "defs.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "server__magic__plyrspel.h"

extern uint32_t dword_5d4594_1569672;
extern uint32_t dword_5d4594_251568;
extern unsigned int dword_5d4594_2650652;
extern void* nox_alloc_magicEnt_1569668;
extern void* nox_alloc_spellDur_1569724;

void nox_xxx_maybeAnimatePixie_53D010(nox_object_t* a1, nox_object_t* a2);
static int nox_call_objectType_parseUpdate_go(int (*fnc)(char*, void*), char* arg1, void* arg2) { return fnc(arg1, arg2); }
*/
import "C"
import (
	"errors"
	"fmt"
	"math"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
)

var (
	noxPixieObjID int
	spellTimeout  uint32
)

func nox_xxx_parseUpdate_536620(objt *ObjectType, _ *MemFile, str string, _ []byte) error {
	name := str
	if i := strings.IndexAny(str, " \t\n\r"); i > 0 {
		name = str[:i]
		str = str[i+1:]
	}
	t, ok := noxObjectUpdateTable[name]
	if !ok {
		// TODO: add "unknown" updates as a nop update types (similar to NoUpdate)
		return nil
	}
	objt.func_update = t.Func
	objt.data_update = nil
	objt.data_update_size = int32(t.DataSize)
	if t.DataSize == 0 {
		return nil
	}
	data, _ := alloc.Malloc(t.DataSize)
	objt.data_update = data
	if t.ParseFunc != nil {
		cstr := CString(str)
		defer StrFree(cstr)
		if C.nox_call_objectType_parseUpdate_go((*[0]byte)(t.ParseFunc), cstr, data) == 0 {
			return fmt.Errorf("cannot parse update data for %q", name)
		}
	}
	return nil
}

var noxObjectUpdateTable = map[string]struct {
	Func      unsafe.Pointer
	DataSize  uintptr
	ParseFunc unsafe.Pointer
}{
	"NoUpdate":                  {},
	"PlayerUpdate":              {Func: C.nox_xxx_updatePlayer_4F8100, DataSize: unsafe.Sizeof(C.nox_object_Player_data_t{})},
	"ProjectileUpdate":          {Func: C.nox_xxx_updateProjectile_53AC10},
	"HomingProjectileUpdate":    {DataSize: 4},
	"SpellProjectileUpdate":     {Func: C.nox_xxx_spellFlyUpdate_53B940, DataSize: 28},
	"AntiSpellProjectileUpdate": {Func: C.nox_xxx_updateAntiSpellProj_53BB00, DataSize: 28},
	"DoorUpdate":                {Func: C.nox_xxx_updateDoor_53AC50, DataSize: 52},
	"SparkUpdate":               {Func: C.nox_xxx_updateSpark_53ADC0, DataSize: 16},
	"ProjectileTrailUpdate":     {Func: C.nox_xxx_updateProjTrail_53AEC0},
	"PushUpdate":                {Func: C.nox_xxx_updatePush_53B030, DataSize: 12, ParseFunc: C.sub_536550},
	"TriggerUpdate":             {Func: C.nox_xxx_updateTrigger_53B1B0, DataSize: 60, ParseFunc: C.sub_5365B0},
	"ToggleUpdate":              {Func: C.nox_xxx_updateToggle_53B060, DataSize: 60, ParseFunc: C.sub_5365B0},
	"MonsterUpdate":             {Func: C.nox_xxx_unitUpdateMonster_50A5C0, DataSize: unsafe.Sizeof(C.nox_object_Monster_data_t{})},
	"LoopAndDamageUpdate":       {Func: C.sub_53B300, DataSize: 16, ParseFunc: C.sub_536580},
	"ElevatorUpdate":            {Func: C.nox_xxx_updateElevator_53B5D0, DataSize: 20},
	"ElevatorShaftUpdate":       {Func: C.nox_xxx_updateElevatorShaft_53B380, DataSize: 16},
	"PhantomPlayerUpdate":       {Func: C.nox_xxx_updatePhantomPlayer_53B860},
	"ObeliskUpdate":             {Func: C.nox_xxx_updateObelisk_53C580, DataSize: 4},
	"LifetimeUpdate":            {Func: C.nox_xxx_updateLifetime_53B8F0, DataSize: 4, ParseFunc: C.sub_536600},
	"MagicMissileUpdate":        {Func: C.nox_xxx_updateMagicMissile_53BDA0, DataSize: 28},
	"PixieUpdate":               {Func: C.nox_xxx_updatePixie_53CD20, DataSize: 28},
	"SpikeBlockUpdate":          {DataSize: 2200},
	"TowerUpdate":               {DataSize: 8},
	"SkullUpdate":               {Func: C.nox_xxx_updateShootingTrap_54F9A0, DataSize: 52, ParseFunc: C.sub_5364E0},
	"PentagramUpdate":           {Func: C.nox_xxx_updateTeleportPentagram_53BEF0, DataSize: 24},
	"InvisiblePentagramUpdate":  {Func: C.nox_xxx_updateInvisiblePentagram_53C0C0, DataSize: 24},
	"SwitchUpdate":              {Func: C.nox_xxx_updateSwitch_53B320},
	"BlowUpdate":                {Func: C.nox_xxx_updateBlow_53C160},
	"MoverUpdate":               {Func: C.nox_xxx_unitUpdateMover_54F740, DataSize: 36},
	"BlackPowderBarrelUpdate":   {Func: C.nox_xxx_updateBlackPowderBarrel_53C9A0},
	"OneSecondDieUpdate":        {Func: C.nox_xxx_updateOneSecondDie_53CB60},
	"WaterBarrelUpdate":         {Func: C.nox_xxx_updateWaterBarrel_53CB90},
	"SelfDestructUpdate":        {Func: C.nox_xxx_updateSelfDestruct_53CC90},
	"BlackPowderBurnUpdate":     {Func: C.nox_xxx_updateBlackPowderBurn_53CCB0},
	"DeathBallUpdate":           {Func: C.nox_xxx_updateDeathBall_53D080},
	"DeathBallFragmentUpdate":   {Func: C.nox_xxx_updateDeathBallFragment_53D220},
	"MoonglowUpdate":            {Func: C.nox_xxx_updateMoonglow_53D270},
	"SentryGlobeUpdate":         {Func: C.nox_xxx_updateSentryGlobe_510E60, DataSize: 12},
	"TelekinesisUpdate":         {Func: C.nox_xxx_updateTelekinesis_53D330},
	"FistUpdate":                {Func: C.nox_xxx_updateFist_53D400, DataSize: 4},
	"MeteorShowerUpdate":        {Func: C.nox_xxx_updateMeteorShower_53D5A0, DataSize: 4},
	"MeteorUpdate":              {Func: C.nox_xxx_meteorExplode_53D6E0, DataSize: 4},
	"ToxicCloudUpdate":          {Func: C.nox_xxx_updateToxicCloud_53D850, DataSize: 4},
	"SmallToxicCloudUpdate":     {Func: C.nox_xxx_updateSmallToxicCloud_53D960, DataSize: 4},
	"ArachnaphobiaUpdate":       {Func: C.nox_xxx_updateArachnaphobia_53DA60},
	"ExpireUpdate":              {Func: C.nox_xxx_updateExpire_53DB00},
	"BreakUpdate":               {Func: C.nox_xxx_updateBreak_53DB30},
	"OpenUpdate":                {Func: C.nox_xxx_updateOpen_53DBB0},
	"BreakAndRemoveUpdate":      {Func: C.nox_xxx_updateBreakAndRemove_53DC30},
	"ChakramInMotionUpdate":     {Func: C.nox_xxx_updateChakramInMotion_53DCC0, DataSize: 28},
	"FlagUpdate":                {Func: C.nox_xxx_updateFlag_53DDF0, DataSize: 12},
	"TrapDoorUpdate":            {Func: C.nox_xxx_updateTrapDoor_53DE80},
	"BallUpdate":                {Func: C.nox_xxx_updateGameBall_53DF40, DataSize: 32},
	"CrownUpdate":               {Func: C.nox_xxx_updateCrown_53E1D0, DataSize: 12},
	"UndeadKillerUpdate":        {Func: C.nox_xxx_updateUndeadKiller_53E190},
	"HarpoonUpdate":             {Func: C.nox_xxx_updateHarpoon_54F380, DataSize: 4},
	"WeaponArmorUpdate":         {DataSize: 8},
	"MonsterGeneratorUpdate":    {Func: C.nox_xxx_updateMonsterGenerator_54E930, DataSize: 164},
}

type PlayerUpdateData C.nox_object_Player_data_t

func (ud *PlayerUpdateData) Player() *Player {
	if ud == nil {
		return nil
	}
	return asPlayer(ud.player)
}

func (ud *PlayerUpdateData) CursorObj() *Object {
	if ud == nil {
		return nil
	}
	return asObjectC(ud.cursor_obj)
}

type MonsterUpdateData C.nox_object_Monster_data_t

func (ud *MonsterUpdateData) getAIStackInd() int {
	if ud == nil {
		return -1
	}
	return int(int8(ud.ai_stack_ind))
}

func (ud *MonsterUpdateData) getAIStack() []aiStack {
	ind := ud.getAIStackInd()
	if ind < 0 {
		return nil
	}
	ptr := (*aiStack)(unsafe.Pointer(&ud.ai_stack[0]))
	stack := unsafe.Slice(ptr, cap(ud.ai_stack))
	return stack[:ind+1]
}

func (ud *MonsterUpdateData) printAIStack(event string) {
	ai.Log.Printf("%d: stack (%s):\n", noxServer.Frame(), event)
	defer ai.Log.Println("----------------------------------------")
	stack := ud.getAIStack()
	if len(stack) == 0 {
		return
	}
	for i := len(stack) - 1; i >= 0; i-- {
		typ := stack[i].Type()
		ai.Log.Printf("  %s", typ.String())
	}
}

//export nox_xxx_updatePlayer_4F8100
func nox_xxx_updatePlayer_4F8100(up *nox_object_t) {
	s := noxServer
	u := asUnitC(up)
	ud := u.updateDataPlayer()
	h := u.healthData()
	for i := 0; i < 4; i++ {
		p := asObjectC(ud.field_29[i])
		if p != nil && p.Flags().Has(object.FlagDestroyed) {
			ud.field_29[i] = nil
		}
	}
	if u.Flags().Has(object.FlagDestroyed) {
		return
	}
	if noxflags.HasGame(noxflags.GameModeQuest) && ud.field_70 != 0 {
		u.force_x = 0
		u.force_y = 0
		u.vel_x = 0
		u.vel_y = 0
	}
	if noxflags.HasGame(noxflags.GameModeQuest) && ud.field_137 != 0 && ud.Player().Index() != common.MaxPlayers-1 && (s.Frame()-uint32(ud.field_137) > (30 * s.TickRate())) {
		sub_4DCFB0(u.CObj())
		return
	}
	v2 := 0
	if ud.field_19_1 != 0 {
		ud.field_19_1--
	} else {
		if ud.field_19_0 != 0 {
			v2 = 1000 * (int(ud.field_19_0) - int(h.cur)) / int(ud.field_19_0)
		}
		ud.field_19_0 = C.ushort(h.cur)
		if v2 > 0 {
			ud.field_19_1 = 7
		}
	}
	if noxflags.HasGame(noxflags.GameSuddenDeath) {
		playerSuddedDeath4F9E70(u)
	}
	sub_4F9ED0(u)
	pl := ud.Player()
	u2 := pl.CameraTarget().AsUnit()
	if u2 == nil {
		u2 = pl.UnitC()
	}
	pl.setPos3632(u2.Pos())
	if ud.field_40_0 != 0 {
		ud.field_40_0--
	}
	u.needSync()
	if ud.field_20_1 != 0 {
		ud.field_20_1--
	}
	if !u.Flags().Has(object.FlagDead) {
		if v2 > 0 {
			v14 := u.field_131
			if pl.Info().IsFemale() {
				if v14 == 5 {
					nox_xxx_aud_501960(sound.SoundHumanFemaleHurtPoison, u, 0, 0)
				} else if v2 <= 450 {
					if v2 <= 70 {
						nox_xxx_aud_501960(sound.SoundHumanFemaleHurtLight, u, 0, 0)
					} else {
						nox_xxx_aud_501960(sound.SoundHumanFemaleHurtMedium, u, 0, 0)
					}
				} else {
					nox_xxx_aud_501960(sound.SoundHumanFemaleHurtHeavy, u, 0, 0)
				}
			} else {
				if v14 == 5 {
					nox_xxx_aud_501960(sound.SoundHumanMaleHurtPoison, u, 0, 0)
				} else if v2 <= 450 {
					if v2 <= 70 {
						nox_xxx_aud_501960(sound.SoundHumanMaleHurtLight, u, 0, 0)
					} else {
						nox_xxx_aud_501960(sound.SoundHumanMaleHurtMedium, u, 0, 0)
					}
				} else {
					nox_xxx_aud_501960(sound.SoundHumanMaleHurtHeavy, u, 0, 0)
				}
			}
		}
		if ud.field_22_3 < 100 {
			ud.field_22_3 += C.uchar(100 / s.TickRate())
		}
	}
	if ud.spell_cast_start != 0 && ud.field_47_0 == 0 && (s.Frame()-uint32(ud.spell_cast_start)) > spellTimeout {
		s.playerSpell(u) // (manual?) spell casting
		ud.spell_cast_start = 0
	}
	nox_xxx_playerInventory_4F8420(u)
	if oa1, ov68, ok := s.unitUpdatePlayerImplA(u); ok {
		s.unitUpdatePlayerImplB(u, oa1, ov68)
	}
	if u.HasEnchant(ENCHANT_RUN) && ud.field_22_0 != 1 {
		nox_xxx_playerSetState_4FA020(u, 5)
	}
	C.nox_xxx_questCheckSecretArea_421C70(u.CObj())
	s.abilities.harpoon.UpdatePlayer(u)
}

func (s *Server) unitUpdatePlayerImplA(u *Unit) (a1, v68 bool, _ bool) {
	ud := u.updateDataPlayer()
	pl := ud.Player()
	switch ud.field_22_0 {
	default:
		return a1, v68, true
	case 0, 5:
		if C.nox_xxx_playerCanMove_4F9BC0(u.CObj()) == 0 {
			return a1, v68, true
		}
		if pl.field_3656 != 0 {
			if pl.Info().IsFemale() {
				nox_xxx_aud_501960(sound.SoundHumanFemaleExertionHeavy, u, 0, 0)
			} else {
				nox_xxx_aud_501960(sound.SoundHumanMaleExertionHeavy, u, 0, 0)
			}
			nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 13, 3)
			return a1, v68, true
		}
		v68 = true
		dp := pl.CursorPos().Sub(u.Pos())
		dx := float64(dp.X)
		dy := float64(dp.Y)
		a1 = false
		const runCursorDist = 100
		if !(ud.field_22_0 != 5 && (dy*dy+dx*dx <= runCursorDist*runCursorDist) || s.abilities.IsActive(u, AbilityTreadLightly)) {
			// switch from walking to running
			a1 = true
			u.speed_cur *= 2
			v67, v69 := playerAnimGetFrameRange(6)
			v25a := int(u.net_code) + int(noxServer.Frame())
			v25 := v25a / (v69 + 1) % v67
			if !(v25 <= ((v25a-1)/(v69+1)%v67) || v25 != 2 && v25 != 8) {
				if v26 := nox_xxx_tileNFromPoint_411160(u.Pos()); v26 >= 0 && v26 < int(C.dword_5d4594_251568) {
					// emit sound based on the tile material
					switch memmap.Uint32(0x85B3FC, 32520+60*uintptr(v26)) {
					case 2:
						// nop
					case 8:
						nox_xxx_aud_501960(sound.SoundRunOnWood, u, 0, 0)
					case 64:
						nox_xxx_aud_501960(sound.SoundRunOnDirt, u, 0, 0)
					case 128:
						nox_xxx_aud_501960(sound.SoundRunOnWater, u, 0, 0)
					case 0x400:
						nox_xxx_aud_501960(sound.SoundRunOnSnow, u, 0, 0)
					case 0x800:
						nox_xxx_aud_501960(sound.SoundRunOnMud, u, 0, 0)
					case 0x4000:
						// nop
					default:
						nox_xxx_aud_501960(sound.SoundRunOnStone, u, 0, 0)
					}
				}
			}
			if noxRndCounter1.IntClamp(0, 100) <= 1 {
				nox_xxx_aud_501960(sound.SoundHumanMaleExertionLight, u, 0, 0)
			}
		}
		if C.sub_4F9AB0(u.CObj()) == 0 {
			if u.HasEnchant(ENCHANT_CONFUSED) {
				u.direction2 = C.ushort(C.nox_xxx_playerConfusedGetDirection_4F7A40(u.CObj()))
			}
			// update force based on direction, speed, etc
			cos, sin := sincosDir(byte(u.direction2))
			u.force_x += C.float(cos) * u.speed_cur
			u.force_y += C.float(sin) * u.speed_cur
		}
		if ud.field_22_0 == 0 {
			v67, v69 := playerAnimGetFrameRange(4)
			v31 := int(u.net_code) + int(noxServer.Frame())
			v32 := (v31 - 1) / (v69 + 1) % v67
			v33 := v31 / (v69 + 1) % v67
			if (!s.abilities.IsActive(u, AbilityTreadLightly) || a1) && v33 != v32 && (v33 == 3 || v33 == 9) {
				if v34 := nox_xxx_tileNFromPoint_411160(u.Pos()); v34 >= 0 && v34 < int(C.dword_5d4594_251568) {
					switch memmap.Uint32(0x85B3FC, 32520+60*uintptr(v34)) {
					case 2:
						// nop
					case 8:
						nox_xxx_aud_501960(sound.SoundWalkOnWood, u, 0, 0)
					case 64:
						nox_xxx_aud_501960(sound.SoundWalkOnDirt, u, 0, 0)
					case 128:
						nox_xxx_aud_501960(sound.SoundWalkOnWater, u, 0, 0)
					case 0x400:
						nox_xxx_aud_501960(sound.SoundWalkOnSnow, u, 0, 0)
					case 0x800:
						nox_xxx_aud_501960(sound.SoundWalkOnMud, u, 0, 0)
					case 0x4000:
						// nop
					default:
						nox_xxx_aud_501960(sound.SoundWalkOnStone, u, 0, 0)
					}
				}
			}
		}
		return a1, v68, true
	case 1:
		if C.nox_xxx_playerAttack_538960(u.CObj()) == 0 {
			if pl.field_4&4 != 0 {
				nox_xxx_playerSetState_4FA020(u, 14)
				u.field_34 = C.uint(noxServer.Frame())
			} else {
				nox_xxx_playerSetState_4FA020(u, 13)
				pl.field_8 &^= 0xff
			}
		}
		return a1, v68, true
	case 2:
		v67, v69 := playerAnimGetFrameRange(21)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v69 + 1))
		if int(ud.field_59_0) >= v67 {
			ud.field_59_0 = C.uchar(v67 - 1)
		}
		return a1, v68, true
	case 3:
		if (int(s.Frame()) - int(u.field_34)) > int(s.TickRate()) {
			nox_xxx_playerSetState_4FA020(u, 4)
			ud.field_60 &^= 0x20
			u.field_34 = C.uint(s.Frame())
			u.obj_flags |= C.uint(object.FlagShort | object.FlagAllowOverlap)
			u.setVel(types.Pointf{})
			u.setForce(types.Pointf{})
			u.float_24 = 0
			u.float_25 = 0
			s.scriptOnEvent(script.EventPlayerDeath)
		}
		return a1, v68, false
	case 4:
		if (int(s.Frame()) - int(u.field_34)) <= int(s.TickRate())/2 {
			return a1, v68, false
		}
		v41 := int(C.nox_xxx_servGamedataGet_40A020(1024))
		if !noxflags.HasGame(noxflags.GameModeElimination) || (v41 <= 0) || (int(pl.field_2140) < v41) {
			if noxflags.HasGame(noxflags.GameOnline) && (pl.field_3680&1 == 0) {
				cb := s.ctrlbuf.Player(pl.Index())
				for it := cb.First(); it != nil; it = cb.Next() {
					if it.code == player.CCAction {
						cb.Reset()
						C.nox_xxx_playerRespawn_4F7EF0(u.CObj())
						return a1, v68, true
					}
				}
			}
			if C.nox_server_doPlayersAutoRespawn_40A5F0() == 0 {
				return a1, v68, false
			}
			C.nox_xxx_playerRespawn_4F7EF0(u.CObj())
			return a1, v68, true
		}
		if pl.field_3680&1 != 0 {
			a1 = pl.CameraTarget() != nil
			pl.CameraUnlock()
			for _, it := range s.getPlayerUnits() {
				pl2 := s.getPlayerByID(int(it.net_code))
				if !it.Flags().Has(object.FlagDead) && (pl2.field_3680&1 == 0) {
					pl.CameraToggle(it)
				}
			}
		} else {
			C.nox_xxx_netNeedTimestampStatus_4174F0(pl.C(), 32)
			pl.GoObserver(false, false)
			pl.CameraUnlock()
			s.nox_xxx_playerLeaveObsByObserved_4E60A0(u)
			if C.sub_4F9E10(u.CObj()) == 0 {
				for _, it := range s.getPlayerUnits() {
					pl2 := s.getPlayerByID(int(it.net_code))
					if !it.Flags().Has(object.FlagDead) && (pl2.field_3680&1 == 0) {
						pl.CameraToggle(it)
					}
				}
			}
		}
		return a1, v68, false
	case 0xA:
		ud.field_59_0 = 0
		return a1, v68, true
	case 0xC:
		v67, v69 := playerAnimGetFrameRange(3)
		v49 := (int(s.Frame()) - int(u.field_34)) / (v69 + 1)

		found := false
		for _, it := range s.getPlayerUnits() {
			ud2 := it.updateDataPlayer()
			if ud2.harpoon_targ == u.CObj() {
				found = true
				break
			}
		}
		if !found {
			cos, sin := sincosDir(byte(u.direction1))
			u.force_x = 2 * u.speed_cur * C.float(cos)
			u.force_y = 2 * u.speed_cur * C.float(sin)
		}
		if v49 >= v67 {
			// stop hovering after a jump?
			nox_xxx_playerSetState_4FA020(u, 0)
			u.obj_flags &= 0xFFFFBFFF
			u.field_34 = C.uint(s.Frame())
		}
		a1 = v69 != 0
		return a1, v68, false
	case 0xD:
		u.obj_flags &= 0xFFFFBFFE
		if C.sub_4F9A80(u.CObj()) != 0 {
			nox_xxx_playerSetState_4FA020(u, 0)
		}
		if noxflags.HasGame(noxflags.GameModeChat) || (pl.field_0&0x3000000 == 0) ||
			C.nox_xxx_monsterTestBlockShield_533E70(u.CObj()) == 0 &&
				(int(s.Frame())-int(u.field_34)) <= int(s.TickRate())/4 {
			return a1, v68, true
		}
		nox_xxx_playerSetState_4FA020(u, 15)
		ud.field_59_0 = 0
		return a1, v68, true
	case 0xE:
		_, v69 := playerAnimGetFrameRange(33)
		ud.field_59_0 = C.uchar(v69 - 1)
		if int(s.Frame())-int(u.field_34) > int(s.TickRate()) {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		return a1, v68, true
	case 0xF:
		v67, v69 := playerAnimGetFrameRange(40)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v69 + 1))
		if int(ud.field_59_0) >= v67 {
			nox_xxx_playerSetState_4FA020(u, 16)
			ud.field_59_0 = C.uchar(v67 - 1)
		}
		return a1, v68, true
	case 0x10:
		_, v69 := playerAnimGetFrameRange(40)
		ud.field_59_0 = C.uchar(v69 - 1)
		return a1, v68, true
	case 0x11:
		v67, v69 := playerAnimGetFrameRange(40)
		v11 := v67 - (int(s.Frame())-int(u.field_34))/(v69+1)
		if v11 >= v67 {
			ud.field_59_0 = C.uchar(v67 - 1)
		} else {
			if v11 <= 0 {
				v11 = 0
				nox_xxx_playerSetState_4FA020(u, 13)
			}
			ud.field_59_0 = C.uchar(v11)
		}
		return a1, v68, true
	case 0x12:
		v67, v69 := playerAnimGetFrameRange(48)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v69 + 1))
		if int(ud.field_59_0) >= v67 {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		return a1, v68, true
	case 0x13:
		v67, v69 := playerAnimGetFrameRange(49)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v69 + 1))
		if int(ud.field_59_0) >= v67 {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		return a1, v68, true
	case 0x14:
		v67, v69 := playerAnimGetFrameRange(47)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v69 + 1))
		if int(ud.field_59_0) >= v67 {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		return a1, v68, true
	case 0x15:
		v67, v69 := playerAnimGetFrameRange(30)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v67 + 1))
		if int(ud.field_59_0) >= v69 {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		return a1, v68, true
	case 0x16:
		_, v69 := playerAnimGetFrameRange(31)
		ud.field_59_0 = C.uchar(v69 - 1)
		return a1, v68, true
	case 0x17:
		v67, v69 := playerAnimGetFrameRange(50)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v69 + 1))
		if int(ud.field_59_0) >= v67 {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		return a1, v68, true
	case 0x18:
		v67, v69 := playerAnimGetFrameRange(19)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v69 + 1))
		if int(ud.field_59_0) >= v67 {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		return a1, v68, true
	case 0x19:
		v67, v69 := playerAnimGetFrameRange(20)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v69 + 1))
		if int(ud.field_59_0) >= v67 {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		return a1, v68, true
	case 0x1A:
		v67, v69 := playerAnimGetFrameRange(15)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v69 + 1))
		if int(ud.field_59_0) >= v67 {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		return a1, v68, true
	case 0x1B:
		v67, v69 := playerAnimGetFrameRange(16)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v69 + 1))
		if int(ud.field_59_0) >= v67/2 {
			nox_xxx_playerSetState_4FA020(u, 28)
			ud.field_59_0 = C.uchar(v67 / 2)
		}
		return a1, v68, true
	case 0x1C:
		v67, _ := playerAnimGetFrameRange(16)
		ud.field_59_0 = C.uchar(v67 / 2)
		if (int(s.Frame()) - int(u.field_34)) > 0x14 {
			nox_xxx_playerSetState_4FA020(u, 29)
			ud.field_59_0 = C.uchar(v67 / 2)
		}
		return a1, v68, true
	case 0x1D:
		v67, v69 := playerAnimGetFrameRange(16)
		ud.field_59_0 = C.uchar(v67/2 + (int(s.Frame())-int(u.field_34))/(v69+1))
		if int(ud.field_59_0) >= v67 {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		return a1, v68, true
	case 0x1E:
		v67, v69 := playerAnimGetFrameRange(52)
		ud.field_59_0 = C.uchar((int(s.Frame()) - int(u.field_34)) / (v69 + 1))
		if int(ud.field_59_0) >= v67 {
			nox_xxx_playerSetState_4FA020(u, 13)
			ud.field_41 = 0
		}
		return a1, v68, true
	case 0x20:
		v67, _ := playerAnimGetFrameRange(54)
		ud.field_59_0 = C.uchar(v67 / 2)
		if (int(s.Frame()) - int(u.field_34)) > 0x14 {
			nox_xxx_playerSetState_4FA020(u, 33)
			ud.field_59_0 = C.uchar(v67 / 2)
		}
		return a1, v68, true
	case 0x21:
		v67, v69 := playerAnimGetFrameRange(54)
		ud.field_59_0 = C.uchar(v67/2 + (int(s.Frame())-int(u.field_34))/(v69+1))
		if int(ud.field_59_0) >= v67 {
			nox_xxx_playerSetState_4FA020(u, 13)
		}
		return a1, v68, true
	}
}

func (s *Server) unitUpdatePlayerImplB(u *Unit, a1, v68 bool) {
	ud := u.updateDataPlayer()
	pl := ud.Player()
	orientationOnly := false
	cb := s.ctrlbuf.Player(pl.Index())
	if cb.IsEmpty() {
		goto LABEL_247
	}
	if (ud.field_22_0 == 0 || ud.field_22_0 == 5) && C.sub_4F9A80(u.CObj()) == 0 {
		nox_xxx_playerSetState_4FA020(u, 13)
		u.field_34 = C.uint(s.Frame())
	}
	ud.field_60 &^= 0x2 | 0x4 | 0x8 | 0x10
	if pl.field_3680&3 != 0 {
		goto LABEL_247
	}
	orientationOnly = C.sub_4FEE50(common.MaxPlayers-1, u.CObj()) != 0
	for it := cb.First(); it != nil; it = cb.Next() {
		if orientationOnly && it.code != player.CCOrientation {
			continue
		}
		switch it.code {
		case player.CCOrientation:
			if !u.HasEnchant(ENCHANT_FREEZE) &&
				(!noxflags.HasGame(noxflags.GameModeQuest) || ud.field_70 == 0) &&
				!s.abilities.IsActive(u, AbilityBerserk) {
				u.direction2 = C.ushort(it.Uint16())
			}
		case player.CCMoveForward, player.CCMoveBackward, player.CCMoveLeft, player.CCMoveRight:
			if C.nox_xxx_playerCanMove_4F9BC0(u.CObj()) != 0 {
				C.nox_xxx_cancelAllSpells_4FEE90(u.CObj())
				if !s.abilities.IsActive(u, AbilityBerserk) &&
					(ud.field_22_0 != 1 || (pl.field_4&0x47F0000 != 0) &&
						C.nox_common_mapPlrActionToStateId_4FA2B0(u.CObj()) != 29) {
					if ud.field_22_0 == 16 {
						nox_xxx_playerSetState_4FA020(u, 17)
					} else {
						if a1 {
							nox_xxx_playerSetState_4FA020(u, 5)
						} else {
							nox_xxx_playerSetState_4FA020(u, 0)
						}
						if it.Uint8()&2 != 0 {
							ud.field_60 |= 0x1
						} else {
							ud.field_60 &^= 0x1
						}
						switch it.code {
						case player.CCMoveForward:
							ud.field_60 |= 0x8
						case player.CCMoveBackward:
							ud.field_60 |= 0x10
						case player.CCMoveLeft:
							ud.field_60 |= 0x4
						case player.CCMoveRight:
							ud.field_60 |= 0x2
						}
						u.field_34 = C.uint(s.Frame())
					}
				}
			}
		case player.CCAction:
			if C.nox_xxx_playerCanAttack_4F9C40(u.CObj()) != 0 {
				if !noxflags.HasGame(noxflags.GameModeChat) && C.nox_xxx_checkWinkFlags_4F7DF0(u.CObj()) == 0 {
					C.nox_xxx_playerInputAttack_4F9C70(u.CObj())
				}
				if ud.field_22_0 == 10 {
					nox_xxx_playerSetState_4FA020(u, 13)
				}
			}
		case player.CCJump:
			if C.nox_xxx_playerCanMove_4F9BC0(u.CObj()) == 0 || s.abilities.IsActive(u, AbilityBerserk) ||
				s.abilities.IsActiveVal(u, AbilityWarcry) {
				break
			}
			C.nox_xxx_cancelAllSpells_4FEE90(u.CObj())
			if pl.field_3656 != 0 {
				if pl.Info().IsFemale() {
					nox_xxx_aud_501960(sound.SoundHumanFemaleExertionHeavy, u, 0, 0)
				} else {
					nox_xxx_aud_501960(sound.SoundHumanMaleExertionHeavy, u, 0, 0)
				}
				nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 13, 3)
			} else if C.nox_xxx_playerSubStamina_4F7D30(u.CObj(), 90) != 0 {
				if u.HasEnchant(ENCHANT_CONFUSED) {
					u.direction2 = C.ushort(C.nox_xxx_playerConfusedGetDirection_4F7A40(u.CObj()))
				}
				u.obj_flags |= 0x4000
				nox_xxx_playerSetState_4FA020(u, 12)
				u.field_34 = C.uint(s.Frame())
				return
			}
		case player.CCSpellGestureUp:
			if !noxflags.HasGame(noxflags.GameModeChat) {
				if ud.spell_cast_start == 0 {
					nox_xxx_plrSetSpellType_4F9B90(u)
				}
				ud.spell_phoneme_leaf = nox_xxx_updateSpellRelated_424830(ud.spell_phoneme_leaf, 1)
				nox_xxx_aud_501960(sound.SoundSpellPhonemeUp, u, 0, 0)
				ud.field_47_0 = 0
			}
		case player.CCSpellGestureDown:
			if !noxflags.HasGame(noxflags.GameModeChat) {
				if ud.spell_cast_start == 0 {
					nox_xxx_plrSetSpellType_4F9B90(u)
				}
				ud.spell_phoneme_leaf = nox_xxx_updateSpellRelated_424830(ud.spell_phoneme_leaf, 7)
				nox_xxx_aud_501960(sound.SoundSpellPhonemeDown, u, 0, 0)
				ud.field_47_0 = 0
			}
		case player.CCSpellGestureLeft:
			if !noxflags.HasGame(noxflags.GameModeChat) {
				if ud.spell_cast_start == 0 {
					nox_xxx_plrSetSpellType_4F9B90(u)
				}
				ud.spell_phoneme_leaf = nox_xxx_updateSpellRelated_424830(ud.spell_phoneme_leaf, 3)
				nox_xxx_aud_501960(sound.SoundSpellPhonemeLeft, u, 0, 0)
				ud.field_47_0 = 0
			}
		case player.CCSpellGestureRight:
			if !noxflags.HasGame(noxflags.GameModeChat) {
				if ud.spell_cast_start == 0 {
					nox_xxx_plrSetSpellType_4F9B90(u)
				}
				ud.spell_phoneme_leaf = nox_xxx_updateSpellRelated_424830(ud.spell_phoneme_leaf, 5)
				nox_xxx_aud_501960(sound.SoundSpellPhonemeRight, u, 0, 0)
				ud.field_47_0 = 0
			}
		case player.CCSpellGestureUpperRight:
			if !noxflags.HasGame(noxflags.GameModeChat) {
				if ud.spell_cast_start == 0 {
					nox_xxx_plrSetSpellType_4F9B90(u)
				}
				ud.spell_phoneme_leaf = nox_xxx_updateSpellRelated_424830(ud.spell_phoneme_leaf, 2)
				nox_xxx_aud_501960(sound.SoundSpellPhonemeUpRight, u, 0, 0)
				ud.field_47_0 = 0
			}
		case player.CCSpellGestureUpperLeft:
			if !noxflags.HasGame(noxflags.GameModeChat) {
				if ud.spell_cast_start == 0 {
					nox_xxx_plrSetSpellType_4F9B90(u)
				}
				ud.spell_phoneme_leaf = nox_xxx_updateSpellRelated_424830(ud.spell_phoneme_leaf, 0)
				nox_xxx_aud_501960(sound.SoundSpellPhonemeUpLeft, u, 0, 0)
				ud.field_47_0 = 0
			}
		case player.CCSpellGestureLowerRight:
			if !noxflags.HasGame(noxflags.GameModeChat) {
				if ud.spell_cast_start == 0 {
					nox_xxx_plrSetSpellType_4F9B90(u)
				}
				ud.spell_phoneme_leaf = nox_xxx_updateSpellRelated_424830(ud.spell_phoneme_leaf, 8)
				nox_xxx_aud_501960(sound.SoundSpellPhonemeDownRight, u, 0, 0)
				ud.field_47_0 = 0
			}
		case player.CCSpellGestureLowerLeft:
			if !noxflags.HasGame(noxflags.GameModeChat) {
				if ud.spell_cast_start == 0 {
					nox_xxx_plrSetSpellType_4F9B90(u)
				}
				ud.spell_phoneme_leaf = nox_xxx_updateSpellRelated_424830(ud.spell_phoneme_leaf, 6)
				nox_xxx_aud_501960(sound.SoundSpellPhonemeDownLeft, u, 0, 0)
				ud.field_47_0 = 0
			}
		case player.CCSpellPatternEnd:
			nox_xxx_playerSetState_4FA020(u, 13)
			if !noxflags.HasGame(noxflags.GameModeChat) {
				if ud.spell_cast_start != 0 {
					s.playerSpell(u)
					ud.spell_cast_start = 0
				} else {
					targ := s.getObjectFromNetCode(int(it.Uint32()))
					C.nox_xxx_playerDoSchedSpell_4FB0E0(u.CObj(), targ.CObj())
				}
			}
		case player.CCCastQueuedSpell:
			nox_xxx_playerSetState_4FA020(u, 13)
			if !noxflags.HasGame(noxflags.GameModeChat) {
				if ud.spell_cast_start != 0 {
					s.playerSpell(u)
					ud.spell_cast_start = 0
				}
				ud.field_55 = pl.field_2284
				ud.field_56 = pl.field_2288
				targ := s.getObjectFromNetCode(int(it.Uint32()))
				C.nox_xxx_playerDoSchedSpell_4FB0E0(u.CObj(), targ.CObj())
			}
		case player.CCCastMostRecentSpell:
			if !noxflags.HasGame(noxflags.GameModeChat) {
				if ud.spell_cast_start != 0 {
					s.playerSpell(u)
					ud.spell_cast_start = 0
				}
				ud.field_55 = pl.field_2284
				ud.field_56 = pl.field_2288
				targ := s.getObjectFromNetCode(int(it.Uint32()))
				C.nox_xxx_playerDoSchedSpellQueue_4FB1D0(u.CObj(), targ.CObj())
			}
		}
	}

LABEL_247:
	if v68 && ud.field_22_0 != 0 && ud.field_22_0 != 5 {
		if s.abilities.IsActive(u, AbilityTreadLightly) {
			s.abilities.DisableAbility(u, AbilityTreadLightly)
		}
	}
}

func sub_4FF310(a1 noxObject) {
	C.sub_4FF310(a1.CObj())
}

func sub_4E7540(a1, a2 noxObject) {
	C.sub_4E7540(a1.CObj(), a2.CObj())
}

//export nox_xxx_objectApplyForce_52DF80
func nox_xxx_objectApplyForce_52DF80(vec *C.float, obj *C.nox_object_t, force C.float) {
	asObjectC(obj).applyForce(asPointf(unsafe.Pointer(vec)), float64(force))
}

func nox_xxx_playerInventory_4F8420(u *Unit) {
	for it := u.FirstItem(); it != nil; it = it.NextItem() {
		if it.Flags().Has(object.FlagEquipped) {
			if !C.nox_xxx_playerCheckStrength_4F3180(u.CObj(), it.CObj()) {
				u.forceDrop(it)
			}
		}
	}
}

func (obj *Object) applyForce(vec types.Pointf, force float64) { // nox_xxx_objectApplyForce_52DF80
	if !obj.IsMovable() {
		return
	}
	dp := obj.Pos().Sub(vec)
	r := float32(dp.Len() + 0.1)
	f := 10.0 * float32(force) / obj.Mass()
	// This weird conversion is how Nox is doing it.
	// Be aware that changing it may cause minor deviation in physics.
	obj.force_x += C.float(float64(dp.X) * float64(f) / float64(r))
	obj.force_y += C.float(float64(dp.Y) * float64(f) / float64(r))
	if !obj.Class().Has(object.ClassMissile) {
		C.nox_xxx_unitHasCollideOrUpdateFn_537610(obj.CObj())
	}
}

func nox_xxx_aud_501960(snd sound.ID, u *Unit, a3, a4 int) {
	C.nox_xxx_aud_501960(C.int(snd), u.CObj(), C.int(a3), C.int(a4))
}

func playerSuddedDeath4F9E70(u *Unit) {
	v1 := memmap.Uint32(0x5D4594, 1392)
	h := u.healthData()
	if !u.Flags().Has(object.FlagDead) && h != nil && h.cur != 0 && (noxServer.Frame()%(v1*noxServer.TickRate()/uint32(h.max))) == 0 {
		C.nox_xxx_unitDamageClear_4EE5E0(u.CObj(), 1)
	}
}

func sub_4F9ED0(u *Unit) {
	s := u.getServer()
	ud := u.updateDataPlayer()
	h := u.healthData()
	if u.Flags().Has(object.FlagDead) {
		return
	}
	if h != nil && (s.Frame()-uint32(u.field_134)) > s.TickRate() {
		if h.cur < h.max && h.max != 0 && (s.Frame()%(300*s.TickRate()/uint32(h.max))) == 0 {
			C.nox_xxx_unitAdjustHP_4EE460(u.CObj(), 1)
		}
	}
	if ud.mana_cur < ud.mana_max && (s.Frame()%(300*s.TickRate()/uint32(ud.mana_max))) == 0 {
		C.nox_xxx_playerManaAdd_4EEB80(u.CObj(), 1)
	}
}

func nox_xxx_allocSpellRelatedArrays_4FC9B0() error {
	C.nox_alloc_spellDur_1569724 = alloc.NewClass("spellDuration", 120, 512).UPtr()
	C.nox_alloc_magicEnt_1569668 = alloc.NewClass("magicEntityClass", 60, 64).UPtr()
	nox_xxx_imagCasterUnit_1569664 = noxServer.newObjectByTypeID("ImaginaryCaster").AsUnit()
	if nox_xxx_imagCasterUnit_1569664 == nil {
		return errors.New("cannot find ImaginaryCaster object type")
	}
	noxServer.createObjectAt(nox_xxx_imagCasterUnit_1569664, nil, types.Pointf{X: 2944.0, Y: 2944.0})
	noxPixieObjID = noxServer.getObjectTypeID("Pixie")
	*memmap.PtrUint32(0x5D4594, 1569676) = uint32(noxPixieObjID)
	*memmap.PtrUint32(0x5D4594, 1569680) = uint32(noxServer.getObjectTypeID("MagicMissile"))
	*memmap.PtrUint32(0x5D4594, 1569684) = uint32(noxServer.getObjectTypeID("SmallFist"))
	*memmap.PtrUint32(0x5D4594, 1569688) = uint32(noxServer.getObjectTypeID("MediumFist"))
	*memmap.PtrUint32(0x5D4594, 1569692) = uint32(noxServer.getObjectTypeID("LargeFist"))
	*memmap.PtrUint32(0x5D4594, 1569696) = uint32(noxServer.getObjectTypeID("DeathBall"))
	*memmap.PtrUint32(0x5D4594, 1569700) = uint32(noxServer.getObjectTypeID("Meteor"))
	return nil
}

func nox_xxx_freeSpellRelated_4FCA80() {
	alloc.AsClass(C.nox_alloc_spellDur_1569724).Free()
	alloc.AsClass(C.nox_alloc_magicEnt_1569668).Free()
	C.dword_5d4594_1569672 = 0
	nox_xxx_imagCasterUnit_1569664.Delete()
	nox_xxx_imagCasterUnit_1569664 = nil
}

//export nox_xxx_updatePixie_53CD20
func nox_xxx_updatePixie_53CD20(cobj *nox_object_t) {
	u := asUnitC(cobj)
	s := u.getServer()
	ud := unsafe.Slice((*uint32)(u.updateDataPtr()), 7)
	if memmap.Uint32(0x5D4594, 2488696) == 0 {
		dt := gamedataFloat("PixieReturnTimeout")
		*memmap.PtrUint32(0x5D4594, 2488696) = uint32(float64(s.TickRate()) * dt)
	}

	if deadline := ud[5]; deadline != 0 && s.Frame() > deadline {
		u.Delete()
		return
	}

	if targ := asObjectC(*(**nox_object_t)(unsafe.Pointer(&ud[1]))); targ != nil {
		if targ.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			ud[1] = 0
		}
	}
	var owner *Object = u.OwnerC()
	if u.Flags().Has(object.FlagEnabled) {
		if s.Frame()-uint32(u.field_34) > s.TickRate()/4 {
			targ := nox_xxx_pixieFindTarget_533570(u)
			*(**nox_object_t)(unsafe.Pointer(&ud[1])) = targ.CObj()
			if targ == owner {
				ud[1] = 0
			}
			u.field_34 = C.uint(s.Frame())
		}
	} else {
		ud[1] = 0
	}
	if owner != nil && owner.Class().HasAny(object.ClassPlayer) && owner.Flags().HasAny(object.FlagNoUpdate) {
		ud[1] = 0
	}
	if targ := asObjectC(*(**nox_object_t)(unsafe.Pointer(&ud[1]))); targ != nil {
		nox_xxx_pixieIdleAnimate_53CF90(u, targ.Pos().Sub(u.Pos()), 32)
	} else {
		_ = nox_xxx_maybeAnimatePixie_53D010
		C.sub_518170(unsafe.Pointer(&u.x), 200.0, C.nox_xxx_maybeAnimatePixie_53D010, u.CObj())
		if owner != nil {
			pos1, pos2 := u.Pos(), owner.Pos()
			if MapTraceRay9(pos1, pos2) {
				nox_xxx_pixieIdleAnimate_53CF90(u, pos2.Sub(pos1), 25)
			}
		} else {
			pos1, pos2 := u.Pos(), types.Pointf{X: float32(u.float_39), Y: float32(u.float_40)}
			if MapTraceRay9(pos1, pos2) {
				nox_xxx_pixieIdleAnimate_53CF90(u, pos2.Sub(pos1), 25)
			}
		}
	}
	u.float_28 = 0.9
	cos, sin := sincosDir(byte(u.Dir2()))
	u.setForce(types.Pointf{
		X: cos * u.curSpeed(),
		Y: sin * u.curSpeed(),
	})
	if (s.Frame()&8 == 0) && owner != nil {
		if C.nox_xxx_mapCheck_537110(u.CObj(), owner.CObj()) == 1 {
			ud[6] = s.Frame()
		}
		if s.Frame()-ud[6] > memmap.Uint32(0x5D4594, 2488696) {
			nox_xxx_teleportPixie_4FD050(u, owner)
			ud[6] = s.Frame()
		}
	}
}

func nox_xxx_pixieIdleAnimate_53CF90(obj *Unit, vec types.Pointf, ddir int) {
	dir := int(obj.Dir2())
	cos, sin := sincosDir(byte(dir))
	if cos*vec.Y-sin*vec.X >= 0.0 {
		dir += ddir
		for dir >= 256 {
			dir -= 256
		}
	} else {
		dir -= ddir
		for dir < 0 {
			dir += 256
		}
	}
	obj.direction2 = C.ushort(dir)
}

//export nox_xxx_maybeAnimatePixie_53D010
func nox_xxx_maybeAnimatePixie_53D010(cit *nox_object_t, cu *nox_object_t) {
	it := asObjectC(cit)
	u := asUnitC(cu)
	if noxPixieObjID == 0 {
		noxPixieObjID = noxServer.getObjectTypeID("Pixie")
	}
	if it.objTypeInd() != noxPixieObjID {
		return
	}
	if it != u.AsObject() && u.OwnerC() == it.OwnerC() {
		nox_xxx_pixieIdleAnimate_53CF90(u, it.Pos().Sub(u.Pos()), 16)
	}
}

func nox_xxx_teleportPixie_4FD050(u *Unit, owner *Object) {
	pos := owner.Pos()
	u.setPos(pos)
	u.setPrevPos(pos)
	u.setNewPos(pos)
	nox_xxx_moveUpdateSpecial_517970(u.CObj())
}

func nox_xxx_pixieFindTarget_533570(u *Unit) *Object {
	r := float32(640.0)
	if !noxflags.HasGame(noxflags.GameModeQuest) {
		r = 250.0
	}
	return nox_xxx_enemyAggro(u, r, math.MaxFloat32)
}

//export nox_xxx_teleportAllPixies_4FD090
func nox_xxx_teleportAllPixies_4FD090(cobj *nox_object_t) {
	u := asUnitC(cobj)
	for it := u.FirstOwned516(); it != nil; it = it.NextOwned512() {
		if it.objTypeInd() != noxPixieObjID {
			continue
		}
		if it.Flags().HasAny(object.FlagDead) {
			continue
		}
		if *(*uint32)(unsafe.Add(it.updateDataPtr(), 4)) == 0 {
			nox_xxx_teleportPixie_4FD050(it.AsUnit(), u.AsObject())
		}
	}
}

//export nox_xxx_enemyAggro_5335D0
func nox_xxx_enemyAggro_5335D0(cobj *nox_object_t, r float32) *nox_object_t {
	return nox_xxx_enemyAggro(asUnitC(cobj), r, r).CObj()
}

func nox_xxx_enemyAggro(self *Unit, r, max float32) *Object {
	var (
		found    *Object
		min      = max
		someFlag = false
	)
	getUnitsInCircle(self.Pos(), r, func(it *Object) {
		if self.AsObject() == it {
			return
		}
		if !it.Class().HasAny(object.ClassMonsterGenerator | object.MaskUnits) {
			return
		}
		if !self.isEnemyTo(it) {
			return
		}
		if it.Flags().HasAny(object.FlagDead) {
			return
		}
		if !nox_xxx_unitCanInteractWith_5370E0(self, it, 0) {
			return
		}
		vec := it.Pos().Sub(self.Pos())
		dist := float32(math.Sqrt(float64(vec.X*vec.X+vec.Y*vec.Y)) + 0.001)
		cos, sin := sincosDir(byte(self.direction1))
		if !someFlag || vec.Y/dist*sin+vec.X/dist*cos > 0.5 {
			dist2 := dist
			if it.HasEnchant(ENCHANT_VILLAIN) {
				dist2 /= 3
			}
			if dist2 < min {
				min = dist2
				found = it
			}
		}
	})
	return found
}

//export sub_5336D0
func sub_5336D0(cobj *nox_object_t) C.double {
	obj := asObjectC(cobj)
	var (
		found *Object
		minR2 = float32(math.MaxFloat32)
	)
	getUnitsInCircle(obj.Pos(), 1000.0, func(it *Object) {
		if it.Class().HasAny(object.MaskUnits) && obj.isEnemyTo(it) && !it.Flags().HasAny(object.FlagDead|object.FlagDestroyed) {
			vec := obj.Pos().Sub(it.Pos())
			r2 := vec.X*vec.X + vec.Y*vec.Y
			if r2 < minR2 {
				minR2 = r2
				found = it
			}
		}
	})
	if found == nil {
		return -1.0
	}
	return C.double(math.Sqrt(float64(minR2)))
}

//export nox_xxx_updatePlayerObserver_4E62F0
func nox_xxx_updatePlayerObserver_4E62F0(a1p *nox_object_t) {
	s := noxServer
	u := asUnitC(a1p)
	ud := u.updateDataPlayer()
	pl := ud.Player()
	for i := range ud.field_29 {
		it := asObjectC(ud.field_29[i])
		if it != nil && it.Flags().Has(object.FlagDestroyed) {
			ud.field_29[i] = nil
		}
	}
	u.needSync()
	if targ := pl.CameraTarget(); targ != nil {
		pl.setPos3632(targ.Pos())
	}
	cb := s.ctrlbuf.Player(pl.Index())
	if cb.First() == nil {
		return
	}
	pl.field_3688 = 0
	for it := cb.First(); it != nil; it = cb.Next() {
		if it.code == player.CCMoveForward {
			if pl.field_3672 == 0 {
				pl.field_3688 = 1
				if pl.field_3692 == 0 {
					pl.leaveMonsterObserver()
				}
				it.active = false
			} else if pl.field_3672 == 1 {
				const max = 30
				dp := pl.pos3632().Sub(pl.CursorPos())
				opos := pl.pos3632()
				if dp.X > max {
					opos.X -= (dp.X - max) * 0.1
				} else if dp.X < -max {
					opos.X -= (dp.X + max) * 0.1
				}
				if dp.Y > max {
					opos.Y -= (dp.Y - max) * 0.1
				} else if dp.Y < -max {
					opos.Y -= (dp.Y + max) * 0.1
				}
				if C.sub_517590(C.float(opos.X), C.float(opos.Y)) != 0 {
					pl.setPos3632(opos)
				}
			}
			continue
		}
		if it.code != player.CCAction {
			if it.code != player.CCJump {
				continue
			}
			if pl.ObserveTarget() == nil && !noxflags.HasGame(noxflags.GameModeQuest) {
				pos2 := pl.pos3632()
				var (
					found *Object
					min   = float32(1e+08)
				)
				rect := types.RectFromPointsf(pos2.Sub(types.Pointf{X: 100, Y: 100}), pos2.Add(types.Pointf{X: 100, Y: 100}))
				getUnitsInRect(rect, func(obj *Object) {
					if obj.Class().Has(object.ClassMonster) && obj.OwnerC() != nil && obj.OwnerC().CObj() == u.CObj() {
						dp := obj.Pos().Sub(pos2)
						dist := dp.X*dp.X + dp.Y*dp.Y
						if dist < min {
							found = obj
							min = dist
						}
					}
				})
				if found != nil && found.CObj() != pl.CameraTarget().CObj() {
					pl.CameraToggle(found)
					pl.field_3672 = 0
				} else {
					pl.CameraUnlock()
					pl.field_3672 = 1
				}
				continue
			}
		}
		if C.dword_5d4594_2650652 != 0 && noxflags.HasGame(noxflags.GameFlag15|noxflags.GameFlag16) && C.sub_509CF0(&pl.field_2096[0], C.char(pl.PlayerClass()), C.int(pl.field_2068)) == 0 {
			nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 17, 0)
			it.active = false
			continue
		}
		if pl.field_3680&0x20 != 0 {
			pl.leaveMonsterObserver()
			it.active = false
			continue
		}
		if noxflags.HasGame(noxflags.GameModeQuest) {
			if pl.field_4792 == 0 {
				if ud.field_138 == 1 {
					nox_xxx_netPriMsgToPlayer_4DA2C0(u, "MainBG.wnd:Loading", 0)
				} else {
					pl.field_4792 = C.uint(C.sub_4E4100())
					if pl.field_4792 == 1 {
						C.sub_4D79C0(u.CObj())
					} else {
						nox_xxx_netPriMsgToPlayer_4DA2C0(u, "GeneralPrint:QuestGameFull", 0)
					}
				}
			}
			if ud.field_79 != 0 {
				C.sub_4D7480(u.CObj())
				continue
			}
			if ud.field_78 != 0 {
				pl.leaveMonsterObserver()
				it.active = false
				continue
			}
			if pl.field_4792 == 0 {
				pl.leaveMonsterObserver()
				it.active = false
				continue
			}
		}
		v13 := C.nox_xxx_gamePlayIsAnyPlayers_40A8A0() != 0
		if C.sub_40A740() != 0 || noxflags.HasGame(noxflags.GameFlag16) || (pl.field_3680&0x100 != 0) && v13 {
			if C.sub_40AA70(pl.C()) == 0 {
				pl.leaveMonsterObserver()
				it.active = false
				continue
			}
		}
		if noxflags.HasEngine(noxflags.EngineNoRendering) && u.CObj() == HostPlayerUnit().CObj() {
			it.active = false
			continue
		}
		if pl.ObserveTarget() == nil {
			C.sub_4DF3C0(pl.C())
			C.nox_xxx_playerLeaveObserver_0_4E6AA0(pl.C())
			pl.CameraUnlock()
			if !noxflags.HasGame(noxflags.GameModeQuest) {
				v22 := nox_xxx_mapFindPlayerStart_4F7AB0(pl.UnitC())
				pl.UnitC().SetPos(v22)
			}
			it.active = false
			continue
		}
		u.observeClear()
		it.active = false
	}
	pl.field_3692 = pl.field_3688
}
