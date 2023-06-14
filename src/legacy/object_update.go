package legacy

import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/player"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_updatePlayer_4F8100      func(up *server.Object)
	Nox_xxx_teleportAllPixies_4FD090 func(cobj *server.Object)
	Nox_xxx_enemyAggro_5335D0        func(cobj *server.Object, r float32) *server.Object
	Sub_5336D0                       func(cobj *server.Object) float64
)

var _ = [1]struct{}{}[2200-unsafe.Sizeof(server.MonsterUpdateData{})]
var _ = [1]struct{}{}[556-unsafe.Sizeof(server.PlayerUpdateData{})]

func init() {
	server.RegisterObjectUpdate("PlayerUpdate", nox_xxx_updatePlayer_4F8100, unsafe.Sizeof(server.PlayerUpdateData{}))
	server.RegisterObjectUpdate("SpellProjectileUpdate", nox_xxx_spellFlyUpdate_53B940, unsafe.Sizeof(server.SpellProjectileUpdateData{}))
	server.RegisterObjectUpdate("AntiSpellProjectileUpdate", nox_xxx_updateAntiSpellProj_53BB00, 28)
	server.RegisterObjectUpdate("DoorUpdate", nox_xxx_updateDoor_53AC50, 52)
	server.RegisterObjectUpdate("SparkUpdate", nox_xxx_updateSpark_53ADC0, 16)
	server.RegisterObjectUpdate("ProjectileTrailUpdate", nox_xxx_updateProjTrail_53AEC0, 0)
	server.RegisterObjectUpdate("PushUpdate", nox_xxx_updatePush_53B030, 12)
	server.RegisterObjectUpdate("TriggerUpdate", nox_xxx_updateTrigger_53B1B0, 60)
	server.RegisterObjectUpdate("ToggleUpdate", nox_xxx_updateToggle_53B060, 60)
	server.RegisterObjectUpdate("LoopAndDamageUpdate", sub_53B300, 16)
	server.RegisterObjectUpdate("ElevatorUpdate", nox_xxx_updateElevator_53B5D0, 20)
	server.RegisterObjectUpdate("ElevatorShaftUpdate", nox_xxx_updateElevatorShaft_53B380, 16)
	server.RegisterObjectUpdate("PhantomPlayerUpdate", nox_xxx_updatePhantomPlayer_53B860, 0)
	server.RegisterObjectUpdate("ObeliskUpdate", nox_xxx_updateObelisk_53C580, 4)
	server.RegisterObjectUpdate("LifetimeUpdate", nox_xxx_updateLifetime_53B8F0, 4)
	server.RegisterObjectUpdate("MagicMissileUpdate", nox_xxx_updateMagicMissile_53BDA0, 28)
	server.RegisterObjectUpdate("SkullUpdate", nox_xxx_updateShootingTrap_54F9A0, 52)
	server.RegisterObjectUpdate("PentagramUpdate", nox_xxx_updateTeleportPentagram_53BEF0, 24)
	server.RegisterObjectUpdate("InvisiblePentagramUpdate", nox_xxx_updateInvisiblePentagram_53C0C0, 24)
	server.RegisterObjectUpdate("SwitchUpdate", nox_xxx_updateSwitch_53B320, 0)
	server.RegisterObjectUpdate("BlowUpdate", nox_xxx_updateBlow_53C160, 0)
	server.RegisterObjectUpdate("MoverUpdate", nox_xxx_unitUpdateMover_54F740, 36)
	server.RegisterObjectUpdate("BlackPowderBarrelUpdate", nox_xxx_updateBlackPowderBarrel_53C9A0, 0)
	server.RegisterObjectUpdate("OneSecondDieUpdate", nox_xxx_updateOneSecondDie_53CB60, 0)
	server.RegisterObjectUpdate("WaterBarrelUpdate", nox_xxx_updateWaterBarrel_53CB90, 0)
	server.RegisterObjectUpdate("SelfDestructUpdate", nox_xxx_updateSelfDestruct_53CC90, 0)
	server.RegisterObjectUpdate("BlackPowderBurnUpdate", nox_xxx_updateBlackPowderBurn_53CCB0, 0)
	server.RegisterObjectUpdate("DeathBallUpdate", nox_xxx_updateDeathBall_53D080, 0)
	server.RegisterObjectUpdate("DeathBallFragmentUpdate", nox_xxx_updateDeathBallFragment_53D220, 0)
	server.RegisterObjectUpdate("MoonglowUpdate", nox_xxx_updateMoonglow_53D270, 0)
	server.RegisterObjectUpdate("SentryGlobeUpdate", nox_xxx_updateSentryGlobe_510E60, 12)
	server.RegisterObjectUpdate("TelekinesisUpdate", nox_xxx_updateTelekinesis_53D330, 0)
	server.RegisterObjectUpdate("FistUpdate", nox_xxx_updateFist_53D400, 4)
	server.RegisterObjectUpdate("MeteorShowerUpdate", nox_xxx_updateMeteorShower_53D5A0, 4)
	server.RegisterObjectUpdate("MeteorUpdate", nox_xxx_meteorExplode_53D6E0, 4)
	server.RegisterObjectUpdate("ToxicCloudUpdate", nox_xxx_updateToxicCloud_53D850, 4)
	server.RegisterObjectUpdate("SmallToxicCloudUpdate", nox_xxx_updateSmallToxicCloud_53D960, 4)
	server.RegisterObjectUpdate("ArachnaphobiaUpdate", nox_xxx_updateArachnaphobia_53DA60, 0)
	server.RegisterObjectUpdate("ExpireUpdate", nox_xxx_updateExpire_53DB00, 0)
	server.RegisterObjectUpdate("BreakUpdate", nox_xxx_updateBreak_53DB30, 0)
	server.RegisterObjectUpdate("OpenUpdate", nox_xxx_updateOpen_53DBB0, 0)
	server.RegisterObjectUpdate("BreakAndRemoveUpdate", nox_xxx_updateBreakAndRemove_53DC30, 0)
	server.RegisterObjectUpdate("ChakramInMotionUpdate", nox_xxx_updateChakramInMotion_53DCC0, 28)
	server.RegisterObjectUpdate("FlagUpdate", nox_xxx_updateFlag_53DDF0, 12)
	server.RegisterObjectUpdate("TrapDoorUpdate", nox_xxx_updateTrapDoor_53DE80, 0)
	server.RegisterObjectUpdate("BallUpdate", nox_xxx_updateGameBall_53DF40, 32)
	server.RegisterObjectUpdate("CrownUpdate", nox_xxx_updateCrown_53E1D0, 12)
	server.RegisterObjectUpdate("UndeadKillerUpdate", nox_xxx_updateUndeadKiller_53E190, 0)
	server.RegisterObjectUpdate("HarpoonUpdate", nox_xxx_updateHarpoon_54F380, 4)
	server.RegisterObjectUpdate("MonsterGeneratorUpdate", nox_xxx_updateMonsterGenerator_54E930, 164)

	server.RegisterObjectUpdateParse("PushUpdate", wrapObjectUpdateParseC(sub_536550))
	server.RegisterObjectUpdateParse("TriggerUpdate", wrapObjectUpdateParseC(sub_5365B0))
	server.RegisterObjectUpdateParse("ToggleUpdate", wrapObjectUpdateParseC(sub_5365B0))
	server.RegisterObjectUpdateParse("LoopAndDamageUpdate", wrapObjectUpdateParseC(sub_536580))
	server.RegisterObjectUpdateParse("LifetimeUpdate", wrapObjectUpdateParseC(sub_536600))
	server.RegisterObjectUpdateParse("SkullUpdate", wrapObjectUpdateParseC(sub_5364E0))
}

// nox_xxx_updatePlayer_4F8100
func nox_xxx_updatePlayer_4F8100(up *server.Object) { Nox_xxx_updatePlayer_4F8100(asObjectS(up)) }

// nox_xxx_objectApplyForce_52DF80
func nox_xxx_objectApplyForce_52DF80(vec *float32, obj *server.Object, force float32) {
	GetServer().ApplyForce(asObjectS(obj), AsPointf(unsafe.Pointer(vec)), float64(force))
}

// nox_xxx_teleportAllPixies_4FD090
func nox_xxx_teleportAllPixies_4FD090(cobj *server.Object) {
	Nox_xxx_teleportAllPixies_4FD090(asObjectS(cobj))
}

// nox_xxx_enemyAggro_5335D0
func nox_xxx_enemyAggro_5335D0(cobj *server.Object, r float32) *server.Object {
	return asObjectC(Nox_xxx_enemyAggro_5335D0(asObjectS(cobj), r))
}

// sub_5336D0
func sub_5336D0(cobj *server.Object) float64 { return float64(Sub_5336D0(asObjectS(cobj))) }

func wrapObjectUpdateParseC(fnc ObjectParseFunc) server.ObjectParseFunc {
	return func(objt *server.ObjectType, args []string) error {
		cstr := CString(strings.Join(args, " "))
		defer StrFree(cstr)
		if fnc(cstr, objt.UpdateData) == 0 {
			return fmt.Errorf("cannot parse update data for %q", objt.ID())
		}
		return nil
	}
}

func Nox_server_doPlayersAutoRespawn_40A5F0() int {
	return int(nox_server_doPlayersAutoRespawn_40A5F0())
}
func Sub_4E4100() uint32 {
	return uint32(sub_4E4100())
}
func Nox_xxx_questCheckSecretArea_421C70(a1 *server.Object) {
	nox_xxx_questCheckSecretArea_421C70(asObjectC(a1))
}
func Nox_xxx_playerCanMove_4F9BC0(a1 *server.Object) int {
	return int(nox_xxx_playerCanMove_4F9BC0(asObjectC(a1)))
}
func Sub_4F9AB0(a1 *server.Object) int {
	return int(sub_4F9AB0(asObjectC(a1)))
}
func Nox_xxx_playerConfusedGetDirection_4F7A40(a1 *server.Object) server.Dir16 {
	return server.Dir16(nox_xxx_playerConfusedGetDirection_4F7A40(asObjectC(a1)))
}
func Nox_xxx_playerAttack_538960(a1 *server.Object) int {
	return int(nox_xxx_playerAttack_538960(asObjectC(a1)))
}
func Nox_xxx_playerRespawn_4F7EF0(a1 *server.Object) {
	nox_xxx_playerRespawn_4F7EF0(asObjectC(a1))
}
func Sub_4F9E10(a1 *server.Object) int {
	return int(sub_4F9E10(asObjectC(a1)))
}
func Sub_4F9A80(a1 *server.Object) int {
	return int(sub_4F9A80(asObjectC(a1)))
}
func Nox_xxx_monsterTestBlockShield_533E70(a1 *server.Object) int {
	return int(nox_xxx_monsterTestBlockShield_533E70(asObjectC(a1)))
}
func Nox_common_mapPlrActionToStateId_4FA2B0(a1 *server.Object) int {
	return int(nox_common_mapPlrActionToStateId_4FA2B0(asObjectC(a1)))
}
func Nox_xxx_playerCanAttack_4F9C40(a1 *server.Object) int {
	return int(nox_xxx_playerCanAttack_4F9C40(asObjectC(a1)))
}
func Nox_xxx_checkWinkFlags_4F7DF0(a1 *server.Object) int {
	return int(nox_xxx_checkWinkFlags_4F7DF0(asObjectC(a1)))
}
func Nox_xxx_playerInputAttack_4F9C70(a1 *server.Object) {
	nox_xxx_playerInputAttack_4F9C70(asObjectC(a1))
}
func Nox_xxx_playerSubStamina_4F7D30(a1 *server.Object, a2 int) int {
	return int(nox_xxx_playerSubStamina_4F7D30(asObjectC(a1), int32(a2)))
}
func Nox_xxx_playerDoSchedSpell_4FB0E0(a1 *server.Object, a2 *server.Object) {
	nox_xxx_playerDoSchedSpell_4FB0E0(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_playerDoSchedSpellQueue_4FB1D0(a1 *server.Object, a2 *server.Object) {
	nox_xxx_playerDoSchedSpellQueue_4FB1D0(asObjectC(a1), asObjectC(a2))
}
func Sub_4E7540(a1 *server.Object, a2 *server.Object) {
	sub_4E7540(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_playerCheckStrength_4F3180(a1 *server.Object, a2 *server.Object) bool {
	return nox_xxx_playerCheckStrength_4F3180(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_unitDamageClear_4EE5E0(a1 *server.Object, a2 int) {
	nox_xxx_unitDamageClear_4EE5E0(asObjectC(a1), int32(a2))
}
func Nox_xxx_unitAdjustHP_4EE460(a1 *server.Object, a2 int) {
	nox_xxx_unitAdjustHP_4EE460(asObjectC(a1), int32(a2))
}
func Sub_509CF0(a1 *byte, a2 player.Class, a3 uint32) int {
	return int(sub_509CF0(a1, int8(a2), int32(a3)))
}
func Sub_4D79C0(a1 *server.Object) {
	sub_4D79C0(asObjectC(a1))
}
func Sub_4D7480(a1 *server.Object) {
	sub_4D7480(asObjectC(a1))
}
