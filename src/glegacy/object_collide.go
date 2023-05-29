package legacy

/*
#include "GAME3_3.h"
#include "GAME4_3.h"
#include "GAME5.h"

int nox_objectCollideDefault(int a1, int a2, float* a3);
static int nox_call_objectType_parseCollide_go(int (*fnc)(char*, void*), char* arg1, void* arg2) { return fnc(arg1, arg2); }
*/

import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectCollide("DefaultCollide", nox_objectCollideDefault, 0)
	server.RegisterObjectCollide("MonsterCollide", nox_xxx_collideMonsterEventProc_4E83B0, 0)
	server.RegisterObjectCollide("PlayerCollide", nox_xxx_collidePlayer_4E8460, 0)
	server.RegisterObjectCollide("ProjectileCollide", nox_xxx_collideProjectileGeneric_4E87B0, 8)
	server.RegisterObjectCollide("ProjectileSparkCollide", nox_xxx_collideProjectileSpark_4E8880, 8)
	server.RegisterObjectCollide("DoorCollide", nox_xxx_collideDoor_4E8AC0, 0)
	server.RegisterObjectCollide("PickupCollide", nox_xxx_collidePickup_4E8DF0, 0)
	server.RegisterObjectCollide("ExitCollide", nox_xxx_collideExit_4E9090, 88)
	server.RegisterObjectCollide("DamageCollide", nox_xxx_collideDamage_4E9430, 8)
	server.RegisterObjectCollide("ManaDrainCollide", nox_xxx_collideManadrain_4E9490, 8)
	server.RegisterObjectCollide("BombCollide", nox_xxx_collideBomb_4E96F0, 8)
	server.RegisterObjectCollide("SparkExplosionCollide", nox_xxx_fireballCollide_4E9AC0, 1)
	server.RegisterObjectCollide("ChestCollide", nox_xxx_collideChest_4E9C40, 0)
	server.RegisterObjectCollide("WallReflectCollide", nox_xxx_collideSulphurShot2_4E9D80, 8)
	server.RegisterObjectCollide("WallReflectSparkCollide", nox_xxx_collideWallReflectSpark_4EA200, 8)
	server.RegisterObjectCollide("PixieCollide", nox_xxx_collidePixie_4EA080, 8)
	server.RegisterObjectCollide("OwnCollide", sub_4EA2C0, 0)
	server.RegisterObjectCollide("SparkCollide", nox_xxx_collideSpark_4EA300, 8)
	server.RegisterObjectCollide("BarrelCollide", sub_4EAAA0, 0)
	server.RegisterObjectCollide("AudioEventCollide", sub_4EAAD0, 4)
	server.RegisterObjectCollide("TriggerCollide", nox_xxx_collideTrigger_54FCD0, 0)
	server.RegisterObjectCollide("TeleportCollide", sub_4EACA0, 8)
	server.RegisterObjectCollide("ElevatorCollide", nox_objectCollideDefault, 8)
	server.RegisterObjectCollide("AwardSpellCollide", nox_xxx_collideSpellPedestal_4EAD20, 4)
	server.RegisterObjectCollide("DieCollide", nox_xxx_collideDie_4E99B0, 0)
	server.RegisterObjectCollide("GlyphCollide", nox_xxx_collideGlyph_4E9A00, 0)
	server.RegisterObjectCollide("SpellProjectileCollide", nox_xxx_spellFlyCollide_4E9500, 0)
	server.RegisterObjectCollide("BoomCollide", nox_xxx_collideBoom_4E9770, 0)
	server.RegisterObjectCollide("SignCollide", nox_xxx_collideSign_4EAB40, 0)
	server.RegisterObjectCollide("PentagramCollide", nox_xxx_collidePentagram_4EAB20, 0)
	server.RegisterObjectCollide("SpiderSpitCollide", nox_xxx_collideWebbing_4EA380, 0)
	server.RegisterObjectCollide("DeathBallCollide", nox_xxx_collideDeathBall_4E9E90, 0)
	server.RegisterObjectCollide("DeathBallFragmentCollide", nox_xxx_collideDeathBallFragment_4E9FE0, 0)
	server.RegisterObjectCollide("TelekinesisCollide", nox_objectCollideDefault, 0)
	server.RegisterObjectCollide("FistCollide", nox_xxx_collideFist_4EADF0, 0)
	server.RegisterObjectCollide("TeleportWakeCollide", nox_xxx_collideTeleportWake_4EAE30, 8)
	server.RegisterObjectCollide("FlagCollide", sub_4EA400, 0)
	server.RegisterObjectCollide("ChakramInMotionCollide", nox_xxx_collideChakram_4EAF00, 0)
	server.RegisterObjectCollide("ArrowCollide", nox_xxx_collideArrow_4EB490, 8)
	server.RegisterObjectCollide("MonsterArrowCollide", nox_xxx_collideMonsterArrow_4EB800, 8)
	server.RegisterObjectCollide("BearTrapCollide", nox_xxx_collideBearTrap_4EB890, 0)
	server.RegisterObjectCollide("PoisonGasTrapCollide", nox_xxx_collidePoisonGasTrap_4EB910, 0)
	server.RegisterObjectCollide("TrapDoorCollide", nox_xxx_collideTrapDoor_4EAB60, 28)
	server.RegisterObjectCollide("BallCollide", nox_xxx_collideBall_4EBA00, 0)
	server.RegisterObjectCollide("HomeBaseCollide", nox_xxx_collideHomeBase_4EBB80, 0)
	server.RegisterObjectCollide("CrownCollide", sub_4EBB50, 0)
	server.RegisterObjectCollide("UndeadKillerCollide", nox_xxx_collideUndeadKiller_4EBD40, 4)
	server.RegisterObjectCollide("YellowStarShotCollide", nox_xxx_collideSulphurShot_4E9E50, 8)
	server.RegisterObjectCollide("MimicCollide", nox_xxx_collideMimic_4E83D0, 0)
	server.RegisterObjectCollide("HarpoonCollide", nox_xxx_collideHarpoon_4EB6A0, 8)
	server.RegisterObjectCollide("MonsterGeneratorCollide", nox_xxx_collideMonsterGen_4EBE10, 0)
	server.RegisterObjectCollide("SoulGateCollide", sub_4EBE40, 4)
	server.RegisterObjectCollide("AnkhCollide", nox_xxx_collideAnkhQuest_4EBF40, 0)

	server.RegisterObjectCollideParse("ProjectileCollide", wrapObjectCollideParseC(sub_536D80))
	server.RegisterObjectCollideParse("ProjectileSparkCollide", wrapObjectCollideParseC(sub_536D80))
	server.RegisterObjectCollideParse("DamageCollide", wrapObjectCollideParseC(nox_xxx_collideDamageLoad_536E10))
	server.RegisterObjectCollideParse("ManaDrainCollide", wrapObjectCollideParseC(sub_536E50))
	server.RegisterObjectCollideParse("SparkExplosionCollide", wrapObjectCollideParseC(sub_536DE0))
	server.RegisterObjectCollideParse("WallReflectCollide", wrapObjectCollideParseC(sub_536D80))
	server.RegisterObjectCollideParse("WallReflectSparkCollide", wrapObjectCollideParseC(sub_536D80))
	server.RegisterObjectCollideParse("PixieCollide", wrapObjectCollideParseC(sub_536D80))
	server.RegisterObjectCollideParse("AudioEventCollide", wrapObjectCollideParseC(sub_536DA0))
	server.RegisterObjectCollideParse("MonsterArrowCollide", wrapObjectCollideParseC(sub_536E80))
	server.RegisterObjectCollideParse("YellowStarShotCollide", wrapObjectCollideParseC(sub_536D80))
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
	return int(nox_call_objectType_parseCollide_go((*[0]byte)(a1), cstr, a3))
}
