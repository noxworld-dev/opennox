package nox

/*
#include "defs.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_3.h"
#include "GAME5.h"
void nullsub_65();
void nullsub_69();
void nullsub_70();

static int nox_call_objectType_parse_go(int (*fnc)(char*, void*), char* arg1, void* arg2) { return fnc(arg1, arg2); }
*/
import "C"
import (
	"strings"
	"unsafe"

	"nox/v1/common/alloc"
)

type noxObjectUpdateFuncs struct {
	Name      string
	Func      unsafe.Pointer
	DataSize  int
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

//export nox_xxx_parseUpdate_536620
func nox_xxx_parseUpdate_536620(a1 *C.nox_objectType_t, _ C.int, a3 *C.char) C.int {
	objt := asObjectType(unsafe.Pointer(a1))
	str := GoString(a3)
	name := str
	if i := strings.IndexAny(str, " \t\n\r"); i > 0 {
		name = str[:i]
		str = str[i+1:]
	}
	t := noxObjectUpdateByName[name]
	if t == nil {
		thingsLog.Printf("unsupported update function: %q", name)
		return 1
	}
	objt.func_update = (*[0]byte)(t.Func)
	objt.data_update = nil
	objt.data_update_size = C.int(t.DataSize)
	if t.DataSize == 0 {
		return 1
	}
	data, _ := alloc.Calloc(1, uintptr(t.DataSize))
	objt.data_update = data
	if t.ParseFunc != nil {
		cstr := CString(str)
		defer StrFree(cstr)
		return C.int(C.nox_call_objectType_parse_go((*[0]byte)(t.ParseFunc), cstr, data))
	}
	return 1
}

var noxObjectUpdateTable = []noxObjectUpdateFuncs{
	{"NoUpdate", nil, 0, nil},
	{"PlayerUpdate", C.nox_xxx_updatePlayer_4F8100, 556, nil},
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
	{"MonsterUpdate", C.nox_xxx_unitUpdateMonster_50A5C0, 2200, nil},
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
