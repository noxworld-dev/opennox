package legacy

import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectCollide("DefaultCollide", funAddrP(nox_objectCollideDefault), 0)
	server.RegisterObjectCollide("MonsterCollide", funAddrP(nox_xxx_collideMonsterEventProc_4E83B0), 0)
	server.RegisterObjectCollide("PlayerCollide", funAddrP(nox_xxx_collidePlayer_4E8460), 0)
	server.RegisterObjectCollide("ProjectileCollide", funAddrP(nox_xxx_collideProjectileGeneric_4E87B0), 8)
	server.RegisterObjectCollide("ProjectileSparkCollide", funAddrP(nox_xxx_collideProjectileSpark_4E8880), 8)
	server.RegisterObjectCollide("DoorCollide", funAddrP(nox_xxx_collideDoor_4E8AC0), 0)
	server.RegisterObjectCollide("PickupCollide", funAddrP(nox_xxx_collidePickup_4E8DF0), 0)
	server.RegisterObjectCollide("ExitCollide", funAddrP(nox_xxx_collideExit_4E9090), 88)
	server.RegisterObjectCollide("DamageCollide", funAddrP(nox_xxx_collideDamage_4E9430), 8)
	server.RegisterObjectCollide("ManaDrainCollide", funAddrP(nox_xxx_collideManadrain_4E9490), 8)
	server.RegisterObjectCollide("BombCollide", funAddrP(nox_xxx_collideBomb_4E96F0), 8)
	server.RegisterObjectCollide("SparkExplosionCollide", funAddrP(nox_xxx_fireballCollide_4E9AC0), 1)
	server.RegisterObjectCollide("ChestCollide", funAddrP(nox_xxx_collideChest_4E9C40), 0)
	server.RegisterObjectCollide("WallReflectCollide", funAddrP(nox_xxx_collideSulphurShot2_4E9D80), 8)
	server.RegisterObjectCollide("WallReflectSparkCollide", funAddrP(nox_xxx_collideWallReflectSpark_4EA200), 8)
	server.RegisterObjectCollide("PixieCollide", funAddrP(nox_xxx_collidePixie_4EA080), 8)
	server.RegisterObjectCollide("OwnCollide", funAddrP(sub_4EA2C0), 0)
	server.RegisterObjectCollide("SparkCollide", funAddrP(nox_xxx_collideSpark_4EA300), 8)
	server.RegisterObjectCollide("BarrelCollide", funAddrP(sub_4EAAA0), 0)
	server.RegisterObjectCollide("AudioEventCollide", funAddrP(sub_4EAAD0), 4)
	server.RegisterObjectCollide("TriggerCollide", funAddrP(nox_xxx_collideTrigger_54FCD0), 0)
	server.RegisterObjectCollide("TeleportCollide", funAddrP(sub_4EACA0), 8)
	server.RegisterObjectCollide("ElevatorCollide", funAddrP(nox_objectCollideDefault), 8)
	server.RegisterObjectCollide("AwardSpellCollide", funAddrP(nox_xxx_collideSpellPedestal_4EAD20), 4)
	server.RegisterObjectCollide("DieCollide", funAddrP(nox_xxx_collideDie_4E99B0), 0)
	server.RegisterObjectCollide("GlyphCollide", funAddrP(nox_xxx_collideGlyph_4E9A00), 0)
	server.RegisterObjectCollide("SpellProjectileCollide", funAddrP(nox_xxx_spellFlyCollide_4E9500), 0)
	server.RegisterObjectCollide("BoomCollide", funAddrP(nox_xxx_collideBoom_4E9770), 0)
	server.RegisterObjectCollide("SignCollide", funAddrP(nox_xxx_collideSign_4EAB40), 0)
	server.RegisterObjectCollide("PentagramCollide", funAddrP(nox_xxx_collidePentagram_4EAB20), 0)
	server.RegisterObjectCollide("SpiderSpitCollide", funAddrP(nox_xxx_collideWebbing_4EA380), 0)
	server.RegisterObjectCollide("DeathBallCollide", funAddrP(nox_xxx_collideDeathBall_4E9E90), 0)
	server.RegisterObjectCollide("DeathBallFragmentCollide", funAddrP(nox_xxx_collideDeathBallFragment_4E9FE0), 0)
	server.RegisterObjectCollide("TelekinesisCollide", funAddrP(nox_objectCollideDefault), 0)
	server.RegisterObjectCollide("FistCollide", funAddrP(nox_xxx_collideFist_4EADF0), 0)
	server.RegisterObjectCollide("TeleportWakeCollide", funAddrP(nox_xxx_collideTeleportWake_4EAE30), 8)
	server.RegisterObjectCollide("FlagCollide", funAddrP(sub_4EA400), 0)
	server.RegisterObjectCollide("ChakramInMotionCollide", funAddrP(nox_xxx_collideChakram_4EAF00), 0)
	server.RegisterObjectCollide("ArrowCollide", funAddrP(nox_xxx_collideArrow_4EB490), 8)
	server.RegisterObjectCollide("MonsterArrowCollide", funAddrP(nox_xxx_collideMonsterArrow_4EB800), 8)
	server.RegisterObjectCollide("BearTrapCollide", funAddrP(nox_xxx_collideBearTrap_4EB890), 0)
	server.RegisterObjectCollide("PoisonGasTrapCollide", funAddrP(nox_xxx_collidePoisonGasTrap_4EB910), 0)
	server.RegisterObjectCollide("TrapDoorCollide", funAddrP(nox_xxx_collideTrapDoor_4EAB60), 28)
	server.RegisterObjectCollide("BallCollide", funAddrP(nox_xxx_collideBall_4EBA00), 0)
	server.RegisterObjectCollide("HomeBaseCollide", funAddrP(nox_xxx_collideHomeBase_4EBB80), 0)
	server.RegisterObjectCollide("CrownCollide", funAddrP(sub_4EBB50), 0)
	server.RegisterObjectCollide("UndeadKillerCollide", funAddrP(nox_xxx_collideUndeadKiller_4EBD40), 4)
	server.RegisterObjectCollide("YellowStarShotCollide", funAddrP(nox_xxx_collideSulphurShot_4E9E50), 8)
	server.RegisterObjectCollide("MimicCollide", funAddrP(nox_xxx_collideMimic_4E83D0), 0)
	server.RegisterObjectCollide("HarpoonCollide", funAddrP(nox_xxx_collideHarpoon_4EB6A0), 8)
	server.RegisterObjectCollide("MonsterGeneratorCollide", funAddrP(nox_xxx_collideMonsterGen_4EBE10), 0)
	server.RegisterObjectCollide("SoulGateCollide", funAddrP(sub_4EBE40), 4)
	server.RegisterObjectCollide("AnkhCollide", funAddrP(nox_xxx_collideAnkhQuest_4EBF40), 0)

	server.RegisterObjectCollideParse("ProjectileCollide", wrapObjectCollideParseC(funAddrP(sub_536D80)))
	server.RegisterObjectCollideParse("ProjectileSparkCollide", wrapObjectCollideParseC(funAddrP(sub_536D80)))
	server.RegisterObjectCollideParse("DamageCollide", wrapObjectCollideParseC(funAddrP(nox_xxx_collideDamageLoad_536E10)))
	server.RegisterObjectCollideParse("ManaDrainCollide", wrapObjectCollideParseC(funAddrP(sub_536E50)))
	server.RegisterObjectCollideParse("SparkExplosionCollide", wrapObjectCollideParseC(funAddrP(sub_536DE0)))
	server.RegisterObjectCollideParse("WallReflectCollide", wrapObjectCollideParseC(funAddrP(sub_536D80)))
	server.RegisterObjectCollideParse("WallReflectSparkCollide", wrapObjectCollideParseC(funAddrP(sub_536D80)))
	server.RegisterObjectCollideParse("PixieCollide", wrapObjectCollideParseC(funAddrP(sub_536D80)))
	server.RegisterObjectCollideParse("AudioEventCollide", wrapObjectCollideParseC(funAddrP(sub_536DA0)))
	server.RegisterObjectCollideParse("MonsterArrowCollide", wrapObjectCollideParseC(funAddrP(sub_536E80)))
	server.RegisterObjectCollideParse("YellowStarShotCollide", wrapObjectCollideParseC(funAddrP(sub_536D80)))
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
	return int(asFuncT[func(*byte, unsafe.Pointer) int32](a1)(cstr, a3))
}
