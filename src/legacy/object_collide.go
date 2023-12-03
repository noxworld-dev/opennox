package legacy

/*
#include "GAME3_3.h"
#include "GAME4_3.h"
#include "GAME5.h"

int nox_objectCollideDefault(int a1, int a2, float* a3);
static int nox_call_objectType_parseCollide_go(int (*fnc)(char*, void*), char* arg1, void* arg2) { return fnc(arg1, arg2); }
void nox_xxx_collideDeathBall_4E9E90(nox_object_t* a1, nox_object_t* a2, float* a3);
*/
import "C"
import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_collideDeathBall_4E9E90         func(a1, a2 *server.Object, pos *types.Pointf)
	Nox_xxx_deathBallCreateFragments_52BD30 func(a1 *server.Object)
)

func init() {
	server.RegisterObjectCollide("DefaultCollide", C.nox_objectCollideDefault, 0)
	server.RegisterObjectCollide("MonsterCollide", C.nox_xxx_collideMonsterEventProc_4E83B0, 0)
	server.RegisterObjectCollide("PlayerCollide", C.nox_xxx_collidePlayer_4E8460, 0)
	server.RegisterObjectCollide("ProjectileCollide", C.nox_xxx_collideProjectileGeneric_4E87B0, 8)
	server.RegisterObjectCollide("ProjectileSparkCollide", C.nox_xxx_collideProjectileSpark_4E8880, 8)
	server.RegisterObjectCollide("DoorCollide", C.nox_xxx_collideDoor_4E8AC0, 0)
	server.RegisterObjectCollide("PickupCollide", C.nox_xxx_collidePickup_4E8DF0, 0)
	server.RegisterObjectCollide("ExitCollide", C.nox_xxx_collideExit_4E9090, 88)
	server.RegisterObjectCollide("DamageCollide", C.nox_xxx_collideDamage_4E9430, 8)
	server.RegisterObjectCollide("ManaDrainCollide", C.nox_xxx_collideManadrain_4E9490, 8)
	server.RegisterObjectCollide("BombCollide", C.nox_xxx_collideBomb_4E96F0, 8)
	server.RegisterObjectCollide("SparkExplosionCollide", C.nox_xxx_fireballCollide_4E9AC0, 1)
	server.RegisterObjectCollide("ChestCollide", C.nox_xxx_collideChest_4E9C40, 0)
	server.RegisterObjectCollide("WallReflectCollide", C.nox_xxx_collideSulphurShot2_4E9D80, 8)
	server.RegisterObjectCollide("WallReflectSparkCollide", C.nox_xxx_collideWallReflectSpark_4EA200, 8)
	server.RegisterObjectCollide("PixieCollide", C.nox_xxx_collidePixie_4EA080, 8)
	server.RegisterObjectCollide("OwnCollide", C.sub_4EA2C0, 0)
	server.RegisterObjectCollide("SparkCollide", C.nox_xxx_collideSpark_4EA300, 8)
	server.RegisterObjectCollide("BarrelCollide", C.sub_4EAAA0, 0)
	server.RegisterObjectCollide("AudioEventCollide", C.sub_4EAAD0, 4)
	server.RegisterObjectCollide("TriggerCollide", C.nox_xxx_collideTrigger_54FCD0, 0)
	server.RegisterObjectCollide("TeleportCollide", C.sub_4EACA0, 8)
	server.RegisterObjectCollide("ElevatorCollide", C.nox_objectCollideDefault, 8)
	server.RegisterObjectCollide("AwardSpellCollide", C.nox_xxx_collideSpellPedestal_4EAD20, 4)
	server.RegisterObjectCollide("DieCollide", C.nox_xxx_collideDie_4E99B0, 0)
	server.RegisterObjectCollide("GlyphCollide", C.nox_xxx_collideGlyph_4E9A00, 0)
	server.RegisterObjectCollide("SpellProjectileCollide", C.nox_xxx_spellFlyCollide_4E9500, 0)
	server.RegisterObjectCollide("BoomCollide", C.nox_xxx_collideBoom_4E9770, 0)
	server.RegisterObjectCollide("SignCollide", C.nox_xxx_collideSign_4EAB40, 0)
	server.RegisterObjectCollide("PentagramCollide", C.nox_xxx_collidePentagram_4EAB20, 0)
	server.RegisterObjectCollide("SpiderSpitCollide", C.nox_xxx_collideWebbing_4EA380, 0)
	server.RegisterObjectCollide("DeathBallCollide", C.nox_xxx_collideDeathBall_4E9E90, 0)
	server.RegisterObjectCollide("DeathBallFragmentCollide", C.nox_xxx_collideDeathBallFragment_4E9FE0, 0)
	server.RegisterObjectCollide("TelekinesisCollide", C.nox_objectCollideDefault, 0)
	server.RegisterObjectCollide("FistCollide", C.nox_xxx_collideFist_4EADF0, 0)
	server.RegisterObjectCollide("TeleportWakeCollide", C.nox_xxx_collideTeleportWake_4EAE30, 8)
	server.RegisterObjectCollide("FlagCollide", C.sub_4EA400, 0)
	server.RegisterObjectCollide("ChakramInMotionCollide", C.nox_xxx_collideChakram_4EAF00, 0)
	server.RegisterObjectCollide("ArrowCollide", C.nox_xxx_collideArrow_4EB490, 8)
	server.RegisterObjectCollide("MonsterArrowCollide", C.nox_xxx_collideMonsterArrow_4EB800, 8)
	server.RegisterObjectCollide("BearTrapCollide", C.nox_xxx_collideBearTrap_4EB890, 0)
	server.RegisterObjectCollide("PoisonGasTrapCollide", C.nox_xxx_collidePoisonGasTrap_4EB910, 0)
	server.RegisterObjectCollide("TrapDoorCollide", C.nox_xxx_collideTrapDoor_4EAB60, 28)
	server.RegisterObjectCollide("BallCollide", C.nox_xxx_collideBall_4EBA00, 0)
	server.RegisterObjectCollide("HomeBaseCollide", C.nox_xxx_collideHomeBase_4EBB80, 0)
	server.RegisterObjectCollide("CrownCollide", C.sub_4EBB50, 0)
	server.RegisterObjectCollide("UndeadKillerCollide", C.nox_xxx_collideUndeadKiller_4EBD40, 4)
	server.RegisterObjectCollide("YellowStarShotCollide", C.nox_xxx_collideSulphurShot_4E9E50, 8)
	server.RegisterObjectCollide("MimicCollide", C.nox_xxx_collideMimic_4E83D0, 0)
	server.RegisterObjectCollide("HarpoonCollide", C.nox_xxx_collideHarpoon_4EB6A0, 8)
	server.RegisterObjectCollide("MonsterGeneratorCollide", C.nox_xxx_collideMonsterGen_4EBE10, 0)
	server.RegisterObjectCollide("SoulGateCollide", C.sub_4EBE40, 4)
	server.RegisterObjectCollide("AnkhCollide", C.nox_xxx_collideAnkhQuest_4EBF40, 0)

	server.RegisterObjectCollideParse("ProjectileCollide", wrapObjectCollideParseC(C.sub_536D80))
	server.RegisterObjectCollideParse("ProjectileSparkCollide", wrapObjectCollideParseC(C.sub_536D80))
	server.RegisterObjectCollideParse("DamageCollide", wrapObjectCollideParseC(C.nox_xxx_collideDamageLoad_536E10))
	server.RegisterObjectCollideParse("ManaDrainCollide", wrapObjectCollideParseC(C.sub_536E50))
	server.RegisterObjectCollideParse("SparkExplosionCollide", wrapObjectCollideParseC(C.sub_536DE0))
	server.RegisterObjectCollideParse("WallReflectCollide", wrapObjectCollideParseC(C.sub_536D80))
	server.RegisterObjectCollideParse("WallReflectSparkCollide", wrapObjectCollideParseC(C.sub_536D80))
	server.RegisterObjectCollideParse("PixieCollide", wrapObjectCollideParseC(C.sub_536D80))
	server.RegisterObjectCollideParse("AudioEventCollide", wrapObjectCollideParseC(C.sub_536DA0))
	server.RegisterObjectCollideParse("MonsterArrowCollide", wrapObjectCollideParseC(C.sub_536E80))
	server.RegisterObjectCollideParse("YellowStarShotCollide", wrapObjectCollideParseC(C.sub_536D80))
}

func wrapObjectCollideParseC(ptr unsafe.Pointer) server.ObjectParseFunc {
	return func(objt *server.ObjectType, args []string) error {
		if Nox_call_objectType_parseCollide_go(ptr, strings.Join(args, " "), objt.CollideData) == 0 {
			return fmt.Errorf("cannot parse collide data for %q", objt.ID())
		}
		return nil
	}
}
func Nox_call_objectType_parseCollide_go(a1 unsafe.Pointer, a2 string, a3 unsafe.Pointer) int {
	cstr := CString(a2)
	defer StrFree(cstr)
	return int(C.nox_call_objectType_parseCollide_go((*[0]byte)(a1), cstr, a3))
}

//export nox_xxx_collideDeathBall_4E9E90
func nox_xxx_collideDeathBall_4E9E90(a1, a2 *nox_object_t, pos *C.float) {
	Nox_xxx_collideDeathBall_4E9E90(asObjectS(a1), asObjectS(a2), (*types.Pointf)(unsafe.Pointer(pos)))
}

//export nox_xxx_deathBallCreateFragments_52BD30
func nox_xxx_deathBallCreateFragments_52BD30(a1 *nox_object_t) {
	Nox_xxx_deathBallCreateFragments_52BD30(asObjectS(a1))
}
