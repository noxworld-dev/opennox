package opennox

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

extern uint32_t dword_5d4594_1569672;
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

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
)

var (
	noxPixieObjID int
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
	s := noxServer
	u := asUnitC(up)
	ud := u.updateDataPlayer()
	v5 := (*C.ushort)(u.ptrXxx())
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
			ud.field_22_3 += C.uchar(100 / gameFPS())
		}
	}
	if ud.field_54 != 0 && ud.field_47_0 == 0 && (gameFrame()-uint32(ud.field_54)) > memmap.Uint32(0x852978, 16) {
		nox_xxx_playerSpell_4FB2A0_magic_plyrspel(u.CObj()) // (manual?) spell casting
		ud.field_54 = 0
	}
	nox_xxx_playerInventory_4F8420(u)
	C.nox_xxx_unitUpdatePlayerImpl_4F8460(u.CObj())
	if u.HasEnchant(ENCHANT_RUN) && ud.field_22_0 != 1 {
		nox_xxx_playerSetState_4FA020(u, 5)
	}
	C.nox_xxx_questCheckSecretArea_421C70(u.CObj())
	s.abilities.harpoon.UpdatePlayer(u)
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
	v3 := unsafe.Slice((*uint16)(u.ptrXxx()), 3)
	if !u.Flags().Has(object.FlagDead) && v3 != nil && v3[0] != 0 && (gameFrame()%(v1*gameFPS()/uint32(v3[2]))) == 0 {
		C.nox_xxx_unitDamageClear_4EE5E0(u.CObj(), 1)
	}
}

func sub_4F9ED0(u *Unit) {
	ud := u.updateDataPlayer()
	v3 := unsafe.Slice((*uint16)(u.ptrXxx()), 3)
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

func nox_xxx_allocSpellRelatedArrays_4FC9B0() error {
	C.nox_alloc_spellDur_1569724 = alloc.NewClass("spellDuration", 120, 512).UPtr()
	C.nox_alloc_magicEnt_1569668 = alloc.NewClass("magicEntityClass", 60, 64).UPtr()
	nox_xxx_imagCasterUnit_1569664 = noxServer.newObjectByTypeID("ImaginaryCaster").AsUnit()
	if nox_xxx_imagCasterUnit_1569664 == nil {
		return errors.New("cannot find ImaginaryCaster object type")
	}
	nox_xxx_createAt_4DAA50(nox_xxx_imagCasterUnit_1569664, nil, types.Pointf{X: 2944.0, Y: 2944.0})
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
	ud := unsafe.Slice((*uint32)(u.updateDataPtr()), 7)
	if memmap.Uint32(0x5D4594, 2488696) == 0 {
		dt := gamedataFloat("PixieReturnTimeout")
		*memmap.PtrUint32(0x5D4594, 2488696) = uint32(float64(gameFPS()) * dt)
	}

	if deadline := ud[5]; deadline != 0 && gameFrame() > deadline {
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
		if gameFrame()-uint32(u.field_34) > gameFPS()/4 {
			targ := nox_xxx_pixieFindTarget_533570(u)
			*(**nox_object_t)(unsafe.Pointer(&ud[1])) = targ.CObj()
			if targ == owner {
				ud[1] = 0
			}
			u.field_34 = C.uint(gameFrame())
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
	u.setForce(types.Pointf{
		X: memmap.Float32(0x587000, 194136+8*uintptr(u.Dir())) * u.curSpeed(),
		Y: memmap.Float32(0x587000, 194140+8*uintptr(u.Dir())) * u.curSpeed(),
	})
	if (gameFrame()&8 == 0) && owner != nil {
		if C.nox_xxx_mapCheck_537110(u.CObj(), owner.CObj()) == 1 {
			ud[6] = gameFrame()
		}
		if gameFrame()-ud[6] > memmap.Uint32(0x5D4594, 2488696) {
			nox_xxx_teleportPixie_4FD050(u, owner)
			ud[6] = gameFrame()
		}
	}
}

func nox_xxx_pixieIdleAnimate_53CF90(obj *Unit, vec types.Pointf, ddir int) {
	dir := int(obj.Dir())
	cos := memmap.Float32(0x587000, 194136+8*uintptr(dir))
	sin := memmap.Float32(0x587000, 194140+8*uintptr(dir))
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
		cos := memmap.Float32(0x587000, 194136+8*uintptr(self.direction1))
		sin := memmap.Float32(0x587000, 194140+8*uintptr(self.direction1))
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
