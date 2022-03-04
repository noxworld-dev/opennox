package nox

/*
#include "defs.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "server__magic__plyrspel.h"
void nullsub_65();
void nullsub_69();
void nullsub_70();

static int nox_call_objectType_parseUpdate_go(int (*fnc)(char*, void*), char* arg1, void* arg2) { return fnc(arg1, arg2); }
*/
import "C"
import (
	"fmt"
	"strings"
	"unsafe"

	"nox/v1/common/alloc"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/memmap"
	"nox/v1/common/object"
	"nox/v1/common/types"
	"nox/v1/common/unit/ai"
)

type noxObjectUpdateFuncs struct {
	Name      string
	Func      unsafe.Pointer
	DataSize  uintptr
	ParseFunc unsafe.Pointer
}

var (
	noxObjectUpdateByName = make(map[string]*noxObjectUpdateFuncs)
)

func init() {
	for i := range noxObjectUpdateTable {
		t := &noxObjectUpdateTable[i]
		noxObjectUpdateByName[t.Name] = t
	}
}

func nox_xxx_parseUpdate_536620(objt *ObjectType, _ *MemFile, str string, _ []byte) error {
	name := str
	if i := strings.IndexAny(str, " \t\n\r"); i > 0 {
		name = str[:i]
		str = str[i+1:]
	}
	t := noxObjectUpdateByName[name]
	if t == nil {
		// TODO: add "unknown" updates as a nop update types (similar to NoUpdate)
		return nil
	}
	objt.func_update = (*[0]byte)(t.Func)
	objt.data_update = nil
	objt.data_update_size = C.int(t.DataSize)
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

var noxObjectUpdateTable = []noxObjectUpdateFuncs{
	{"NoUpdate", nil, 0, nil},
	{"PlayerUpdate", C.nox_xxx_updatePlayer_4F8100, unsafe.Sizeof(C.nox_object_Player_data_t{}), nil},
	{"ProjectileUpdate", C.nox_xxx_updateProjectile_53AC10, 0, nil},
	{"HomingProjectileUpdate", C.nullsub_65, 4, nil},
	{"SpellProjectileUpdate", C.nox_xxx_spellFlyUpdate_53B940, 28, nil},
	{"AntiSpellProjectileUpdate", C.nox_xxx_updateAntiSpellProj_53BB00, 28, nil},
	{"DoorUpdate", C.nox_xxx_updateDoor_53AC50, 52, nil},
	{"SparkUpdate", C.nox_xxx_updateSpark_53ADC0, 16, nil},
	{"ProjectileTrailUpdate", C.nox_xxx_updateProjTrail_53AEC0, 0, nil},
	{"PushUpdate", C.nox_xxx_updatePush_53B030, 12, C.sub_536550},
	{"TriggerUpdate", C.nox_xxx_updateTrigger_53B1B0, 60, C.sub_5365B0},
	{"ToggleUpdate", C.nox_xxx_updateToggle_53B060, 60, C.sub_5365B0},
	{"MonsterUpdate", C.nox_xxx_unitUpdateMonster_50A5C0, unsafe.Sizeof(C.nox_object_Monster_data_t{}), nil},
	{"LoopAndDamageUpdate", C.sub_53B300, 16, C.sub_536580},
	{"ElevatorUpdate", C.nox_xxx_updateElevator_53B5D0, 20, nil},
	{"ElevatorShaftUpdate", C.nox_xxx_updateElevatorShaft_53B380, 16, nil},
	{"PhantomPlayerUpdate", C.nox_xxx_updatePhantomPlayer_53B860, 0, nil},
	{"ObeliskUpdate", C.nox_xxx_updateObelisk_53C580, 4, nil},
	{"LifetimeUpdate", C.nox_xxx_updateLifetime_53B8F0, 4, C.sub_536600},
	{"MagicMissileUpdate", C.nox_xxx_updateMagicMissile_53BDA0, 28, nil},
	{"PixieUpdate", C.nox_xxx_updatePixie_53CD20, 28, nil},
	{"SpikeBlockUpdate", C.nullsub_70, 2200, nil},
	{"TowerUpdate", C.nullsub_69, 8, nil},
	{"SkullUpdate", C.nox_xxx_updateShootingTrap_54F9A0, 52, C.sub_5364E0},
	{"PentagramUpdate", C.nox_xxx_updateTeleportPentagram_53BEF0, 24, nil},
	{"InvisiblePentagramUpdate", C.nox_xxx_updateInvisiblePentagram_53C0C0, 24, nil},
	{"SwitchUpdate", C.nox_xxx_updateSwitch_53B320, 0, nil},
	{"BlowUpdate", C.nox_xxx_updateBlow_53C160, 0, nil},
	{"MoverUpdate", C.nox_xxx_unitUpdateMover_54F740, 36, nil},
	{"BlackPowderBarrelUpdate", C.nox_xxx_updateBlackPowderBarrel_53C9A0, 0, nil},
	{"OneSecondDieUpdate", C.nox_xxx_updateOneSecondDie_53CB60, 0, nil},
	{"WaterBarrelUpdate", C.nox_xxx_updateWaterBarrel_53CB90, 0, nil},
	{"SelfDestructUpdate", C.nox_xxx_updateSelfDestruct_53CC90, 0, nil},
	{"BlackPowderBurnUpdate", C.nox_xxx_updateBlackPowderBurn_53CCB0, 0, nil},
	{"DeathBallUpdate", C.nox_xxx_updateDeathBall_53D080, 0, nil},
	{"DeathBallFragmentUpdate", C.nox_xxx_updateDeathBallFragment_53D220, 0, nil},
	{"MoonglowUpdate", C.nox_xxx_updateMoonglow_53D270, 0, nil},
	{"SentryGlobeUpdate", C.nox_xxx_updateSentryGlobe_510E60, 12, nil},
	{"TelekinesisUpdate", C.nox_xxx_updateTelekinesis_53D330, 0, nil},
	{"FistUpdate", C.nox_xxx_updateFist_53D400, 4, nil},
	{"MeteorShowerUpdate", C.nox_xxx_updateMeteorShower_53D5A0, 4, nil},
	{"MeteorUpdate", C.nox_xxx_meteorExplode_53D6E0, 4, nil},
	{"ToxicCloudUpdate", C.nox_xxx_updateToxicCloud_53D850, 4, nil},
	{"SmallToxicCloudUpdate", C.nox_xxx_updateSmallToxicCloud_53D960, 4, nil},
	{"ArachnaphobiaUpdate", C.nox_xxx_updateArachnaphobia_53DA60, 0, nil},
	{"ExpireUpdate", C.nox_xxx_updateExpire_53DB00, 0, nil},
	{"BreakUpdate", C.nox_xxx_updateBreak_53DB30, 0, nil},
	{"OpenUpdate", C.nox_xxx_updateOpen_53DBB0, 0, nil},
	{"BreakAndRemoveUpdate", C.nox_xxx_updateBreakAndRemove_53DC30, 0, nil},
	{"ChakramInMotionUpdate", C.nox_xxx_updateChakramInMotion_53DCC0, 28, nil},
	{"FlagUpdate", C.nox_xxx_updateFlag_53DDF0, 12, nil},
	{"TrapDoorUpdate", C.nox_xxx_updateTrapDoor_53DE80, 0, nil},
	{"BallUpdate", C.nox_xxx_updateGameBall_53DF40, 32, nil},
	{"CrownUpdate", C.nox_xxx_updateCrown_53E1D0, 12, nil},
	{"UndeadKillerUpdate", C.nox_xxx_updateUndeadKiller_53E190, 0, nil},
	{"HarpoonUpdate", C.nox_xxx_updateHarpoon_54F380, 4, nil},
	{"WeaponArmorUpdate", nil, 8, nil},
	{"MonsterGeneratorUpdate", C.nox_xxx_updateMonsterGenerator_54E930, 164, nil},
}

type PlayerUpdateData C.nox_object_Player_data_t

func (ud *PlayerUpdateData) Player() *Player {
	if ud == nil {
		return nil
	}
	return asPlayer(ud.player)
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
	ai.Log.Printf("%d: stack (%s):\n", gameFrame(), event)
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
	u := asUnitC(up)
	ud := u.updateDataPlayer()
	v5 := (*C.ushort)(unsafe.Pointer(u.field_139))
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
	if noxflags.HasGame(noxflags.GameModeQuest) && ud.field_137 != 0 && ud.player.playerInd != 31 && (gameFrame()-uint32(ud.field_137) > (30 * gameFPS())) {
		C.sub_4DCFB0(u.CObj())
		return
	}
	v2 := 0
	if ud.field_19_1 != 0 {
		ud.field_19_1--
	} else {
		if ud.field_19_0 != 0 {
			v2 = 1000 * (int(ud.field_19_0) - int(*v5)) / int(ud.field_19_0)
		}
		ud.field_19_0 = *v5
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
	pl.pos_x_3632 = u2.x
	pl.pos_y_3636 = u2.y
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
					nox_xxx_aud_501960(330, u, 0, 0)
				} else if v2 <= 450 {
					if v2 <= 70 {
						nox_xxx_aud_501960(327, u, 0, 0)
					} else {
						nox_xxx_aud_501960(328, u, 0, 0)
					}
				} else {
					nox_xxx_aud_501960(329, u, 0, 0)
				}
			} else {
				if v14 == 5 {
					nox_xxx_aud_501960(320, u, 0, 0)
				} else if v2 <= 450 {
					if v2 <= 70 {
						nox_xxx_aud_501960(317, u, 0, 0)
					} else {
						nox_xxx_aud_501960(318, u, 0, 0)
					}
				} else {
					nox_xxx_aud_501960(319, u, 0, 0)
				}
			}
		}
		if ud.field_22_3 < 100 {
			ud.field_22_3 += C.uchar(100 / gameFPS())
		}
	}
	if ud.field_54 != 0 && ud.field_47_0 == 0 && (gameFrame()-uint32(ud.field_54)) > memmap.Uint32(0x852978, 16) {
		C.nox_xxx_playerSpell_4FB2A0_magic_plyrspel(u.CObj()) // (manual?) spell casting
		ud.field_54 = 0
	}
	nox_xxx_playerInventory_4F8420(u)
	C.nox_xxx_unitUpdatePlayerImpl_4F8460(u.CObj())
	if u.testBuff(8) && ud.field_22_0 != 1 {
		C.nox_xxx_playerSetState_4FA020(u.CObj(), 5)
	}
	C.nox_xxx_questCheckSecretArea_421C70(u.CObj())
	if harp := asObjectC(ud.harpoon); harp != nil {
		if harp.Flags().Has(object.FlagDestroyed) {
			nox_xxx_harpoonBreakForPlr_537520(u)
		} else {
			force := gamedataFloat("HarpoonForce")
			C.sub_4E7540(u.CObj(), harp.CObj())
			harp.applyForce(u.Pos(), -force)
		}
	}
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
	r := dp.Len() + 0.1
	f := 10.0 * force / float64(obj.Mass())
	obj.force_x += C.float(float64(dp.X) * f / r)
	obj.force_y += C.float(float64(dp.Y) * f / r)
	if !obj.Class().Has(object.ClassMissile) {
		C.nox_xxx_unitHasCollideOrUpdateFn_537610(obj.CObj())
	}
}

func nox_xxx_harpoonBreakForPlr_537520(u *Unit) {
	C.sub_5374D0(u.CObj())
	nox_xxx_aud_501960(998, u, 0, 0)
}

func nox_xxx_aud_501960(a1 int, u *Unit, a3, a4 int) {
	C.nox_xxx_aud_501960(C.int(a1), u.CObj(), C.int(a3), C.int(a4))
}

func playerSuddedDeath4F9E70(u *Unit) {
	v1 := memmap.Uint32(0x5D4594, 1392)
	v3 := unsafe.Slice((*uint16)(u.field_139), 3)
	if !u.Flags().Has(object.FlagDead) && v3 != nil && v3[0] != 0 && (gameFrame()%(v1*gameFPS()/uint32(v3[2]))) == 0 {
		C.nox_xxx_unitDamageClear_4EE5E0(u.CObj(), 1)
	}
}

func sub_4F9ED0(u *Unit) {
	ud := u.updateDataPlayer()
	v3 := unsafe.Slice((*uint16)(u.field_139), 3)
	if u.Flags().Has(object.FlagDead) {
		return
	}
	if v3 != nil && (gameFrame()-uint32(u.field_134)) > gameFPS() {
		v5 := v3[2]
		if v3[0] < v5 && v5 != 0 && (gameFrame()%(300*gameFPS()/uint32(v3[2]))) == 0 {
			C.nox_xxx_unitAdjustHP_4EE460(u.CObj(), 1)
		}
	}
	if ud.mana_cur < ud.mana_max && (gameFrame()%(300*gameFPS()/uint32(ud.mana_max))) == 0 {
		C.nox_xxx_playerManaAdd_4EEB80(u.CObj(), 1)
	}
}
