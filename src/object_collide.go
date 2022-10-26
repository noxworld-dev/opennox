package opennox

/*
#include "GAME3_3.h"
#include "GAME4_3.h"
#include "GAME5.h"

int nox_objectCollideDefault(int a1, int a2, float* a3);
static int nox_call_objectType_parseCollide_go(int (*fnc)(char*, void*), char* arg1, void* arg2) { return fnc(arg1, arg2); }
*/
import "C"
import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

func nox_xxx_parseCollide_536EC0(objt *ObjectType, d *things.ProcFunc) error {
	t, ok := noxObjectCollideTable[d.Name]
	if !ok {
		// TODO: add "unknown" collide as a nop types (similar to NoCollide)
		return nil
	}
	objt.func_collide = t.Func
	objt.collide_data = nil
	objt.collide_data_size = int32(t.DataSize)
	if t.DataSize == 0 {
		return nil
	}
	data, _ := alloc.Malloc(uintptr(t.DataSize))
	objt.collide_data = data
	if t.ParseFunc != nil {
		cstr := CString(strings.Join(d.Args, " "))
		defer StrFree(cstr)
		if C.nox_call_objectType_parseCollide_go((*[0]byte)(t.ParseFunc), cstr, data) == 0 {
			return fmt.Errorf("cannot parse collide data for %q", d.Name)
		}
	}
	return nil
}

var noxObjectCollideTable = map[string]struct {
	Func      unsafe.Pointer
	DataSize  int
	ParseFunc unsafe.Pointer
}{
	"NoCollide":                {},
	"DefaultCollide":           {Func: C.nox_objectCollideDefault},
	"MonsterCollide":           {Func: C.nox_xxx_collideMonsterEventProc_4E83B0},
	"PlayerCollide":            {Func: C.nox_xxx_collidePlayer_4E8460},
	"ProjectileCollide":        {Func: C.nox_xxx_collideProjectileGeneric_4E87B0, DataSize: 8, ParseFunc: C.sub_536D80},
	"ProjectileSparkCollide":   {Func: C.nox_xxx_collideProjectileSpark_4E8880, DataSize: 8, ParseFunc: C.sub_536D80},
	"DoorCollide":              {Func: C.nox_xxx_collideDoor_4E8AC0},
	"PickupCollide":            {Func: C.nox_xxx_collidePickup_4E8DF0},
	"ExitCollide":              {Func: C.nox_xxx_collideExit_4E9090, DataSize: 88},
	"DamageCollide":            {Func: C.nox_xxx_collideDamage_4E9430, DataSize: 8, ParseFunc: C.nox_xxx_collideDamageLoad_536E10},
	"ManaDrainCollide":         {Func: C.nox_xxx_collideManadrain_4E9490, DataSize: 8, ParseFunc: C.sub_536E50},
	"BombCollide":              {Func: C.nox_xxx_collideBomb_4E96F0, DataSize: 8},
	"SparkExplosionCollide":    {Func: C.nox_xxx_fireballCollide_4E9AC0, DataSize: 1, ParseFunc: C.sub_536DE0},
	"ChestCollide":             {Func: C.nox_xxx_collideChest_4E9C40},
	"WallReflectCollide":       {Func: C.nox_xxx_collideSulphurShot2_4E9D80, DataSize: 8, ParseFunc: C.sub_536D80},
	"WallReflectSparkCollide":  {Func: C.nox_xxx_collideWallReflectSpark_4EA200, DataSize: 8, ParseFunc: C.sub_536D80},
	"PixieCollide":             {Func: C.nox_xxx_collidePixie_4EA080, DataSize: 8, ParseFunc: C.sub_536D80},
	"OwnCollide":               {Func: C.sub_4EA2C0},
	"SparkCollide":             {Func: C.nox_xxx_collideSpark_4EA300, DataSize: 8},
	"BarrelCollide":            {Func: C.sub_4EAAA0},
	"AudioEventCollide":        {Func: C.sub_4EAAD0, DataSize: 4, ParseFunc: C.sub_536DA0},
	"TriggerCollide":           {Func: C.nox_xxx_collideTrigger_54FCD0},
	"TeleportCollide":          {Func: C.sub_4EACA0, DataSize: 8},
	"ElevatorCollide":          {Func: C.nox_objectCollideDefault, DataSize: 8},
	"AwardSpellCollide":        {Func: C.nox_xxx_collideSpellPedestal_4EAD20, DataSize: 4},
	"DieCollide":               {Func: C.nox_xxx_collideDie_4E99B0},
	"GlyphCollide":             {Func: C.nox_xxx_collideGlyph_4E9A00},
	"SpellProjectileCollide":   {Func: C.nox_xxx_spellFlyCollide_4E9500},
	"BoomCollide":              {Func: C.nox_xxx_collideBoom_4E9770},
	"SignCollide":              {Func: C.nox_xxx_collideSign_4EAB40},
	"PentagramCollide":         {Func: C.nox_xxx_collidePentagram_4EAB20},
	"SpiderSpitCollide":        {Func: C.nox_xxx_collideWebbing_4EA380},
	"DeathBallCollide":         {Func: C.nox_xxx_collideDeathBall_4E9E90},
	"DeathBallFragmentCollide": {Func: C.nox_xxx_collideDeathBallFragment_4E9FE0},
	"TelekinesisCollide":       {Func: C.nox_objectCollideDefault},
	"FistCollide":              {Func: C.nox_xxx_collideFist_4EADF0},
	"TeleportWakeCollide":      {Func: C.nox_xxx_collideTeleportWake_4EAE30, DataSize: 8},
	"FlagCollide":              {Func: C.sub_4EA400},
	"ChakramInMotionCollide":   {Func: C.nox_xxx_collideChakram_4EAF00},
	"ArrowCollide":             {Func: C.nox_xxx_collideArrow_4EB490, DataSize: 8},
	"MonsterArrowCollide":      {Func: C.nox_xxx_collideMonsterArrow_4EB800, DataSize: 8, ParseFunc: C.sub_536E80},
	"BearTrapCollide":          {Func: C.nox_xxx_collideBearTrap_4EB890},
	"PoisonGasTrapCollide":     {Func: C.nox_xxx_collidePoisonGasTrap_4EB910},
	"TrapDoorCollide":          {Func: C.nox_xxx_collideTrapDoor_4EAB60, DataSize: 28},
	"BallCollide":              {Func: C.nox_xxx_collideBall_4EBA00},
	"HomeBaseCollide":          {Func: C.nox_xxx_collideHomeBase_4EBB80},
	"CrownCollide":             {Func: C.sub_4EBB50},
	"UndeadKillerCollide":      {Func: C.nox_xxx_collideUndeadKiller_4EBD40, DataSize: 4},
	"YellowStarShotCollide":    {Func: C.nox_xxx_collideSulphurShot_4E9E50, DataSize: 8, ParseFunc: C.sub_536D80},
	"MimicCollide":             {Func: C.nox_xxx_collideMimic_4E83D0},
	"HarpoonCollide":           {Func: C.nox_xxx_collideHarpoon_4EB6A0, DataSize: 8},
	"MonsterGeneratorCollide":  {Func: C.nox_xxx_collideMonsterGen_4EBE10},
	"SoulGateCollide":          {Func: C.sub_4EBE40, DataSize: 4},
	"AnkhCollide":              {Func: C.nox_xxx_collideAnkhQuest_4EBF40},
}
