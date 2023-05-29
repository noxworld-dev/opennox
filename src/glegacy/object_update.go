package legacy

import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/player"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_updatePlayer_4F8100         func(up *server.Object)
	Nox_xxx_updatePixie_53CD20          func(cobj *server.Object)
	Nox_xxx_teleportAllPixies_4FD090    func(cobj *server.Object)
	Nox_xxx_enemyAggro_5335D0           func(cobj *server.Object, r float32) *server.Object
	Sub_5336D0                          func(cobj *server.Object) float64
	Nox_xxx_updatePlayerObserver_4E62F0 func(a1p *server.Object)
	Nox_xxx_updateProjectile_53AC10     func(a1 *server.Object)
	Nox_xxx___mkgmtime_538280           func(a1 *server.Object)
)

var _ = [1]struct{}{}[2200-unsafe.Sizeof(server.MonsterUpdateData{})]
var _ = [1]struct{}{}[556-unsafe.Sizeof(server.PlayerUpdateData{})]

func init() {
	_ = nox_xxx_updatePlayer_4F8100
	server.RegisterObjectUpdate("PlayerUpdate", funAddrP(nox_xxx_updatePlayer_4F8100), unsafe.Sizeof(server.PlayerUpdateData{}))
	_ = nox_xxx_updateProjectile_53AC10
	server.RegisterObjectUpdate("ProjectileUpdate", funAddrP(nox_xxx_updateProjectile_53AC10), 0)
	server.RegisterObjectUpdate("SpellProjectileUpdate", funAddrP(nox_xxx_spellFlyUpdate_53B940), unsafe.Sizeof(server.SpellProjectileUpdateData{}))
	server.RegisterObjectUpdate("AntiSpellProjectileUpdate", funAddrP(nox_xxx_updateAntiSpellProj_53BB00), 28)
	server.RegisterObjectUpdate("DoorUpdate", funAddrP(nox_xxx_updateDoor_53AC50), 52)
	server.RegisterObjectUpdate("SparkUpdate", funAddrP(nox_xxx_updateSpark_53ADC0), 16)
	server.RegisterObjectUpdate("ProjectileTrailUpdate", funAddrP(nox_xxx_updateProjTrail_53AEC0), 0)
	server.RegisterObjectUpdate("PushUpdate", funAddrP(nox_xxx_updatePush_53B030), 12)
	server.RegisterObjectUpdate("TriggerUpdate", funAddrP(nox_xxx_updateTrigger_53B1B0), 60)
	server.RegisterObjectUpdate("ToggleUpdate", funAddrP(nox_xxx_updateToggle_53B060), 60)
	server.RegisterObjectUpdate("MonsterUpdate", funAddrP(nox_xxx_unitUpdateMonster_50A5C0), unsafe.Sizeof(server.MonsterUpdateData{}))
	server.RegisterObjectUpdate("LoopAndDamageUpdate", funAddrP(sub_53B300), 16)
	server.RegisterObjectUpdate("ElevatorUpdate", funAddrP(nox_xxx_updateElevator_53B5D0), 20)
	server.RegisterObjectUpdate("ElevatorShaftUpdate", funAddrP(nox_xxx_updateElevatorShaft_53B380), 16)
	server.RegisterObjectUpdate("PhantomPlayerUpdate", funAddrP(nox_xxx_updatePhantomPlayer_53B860), 0)
	server.RegisterObjectUpdate("ObeliskUpdate", funAddrP(nox_xxx_updateObelisk_53C580), 4)
	server.RegisterObjectUpdate("LifetimeUpdate", funAddrP(nox_xxx_updateLifetime_53B8F0), 4)
	server.RegisterObjectUpdate("MagicMissileUpdate", funAddrP(nox_xxx_updateMagicMissile_53BDA0), 28)
	server.RegisterObjectUpdate("PixieUpdate", funAddrP(nox_xxx_updatePixie_53CD20), 28)
	server.RegisterObjectUpdate("SkullUpdate", funAddrP(nox_xxx_updateShootingTrap_54F9A0), 52)
	server.RegisterObjectUpdate("PentagramUpdate", funAddrP(nox_xxx_updateTeleportPentagram_53BEF0), 24)
	server.RegisterObjectUpdate("InvisiblePentagramUpdate", funAddrP(nox_xxx_updateInvisiblePentagram_53C0C0), 24)
	server.RegisterObjectUpdate("SwitchUpdate", funAddrP(nox_xxx_updateSwitch_53B320), 0)
	server.RegisterObjectUpdate("BlowUpdate", funAddrP(nox_xxx_updateBlow_53C160), 0)
	server.RegisterObjectUpdate("MoverUpdate", funAddrP(nox_xxx_unitUpdateMover_54F740), 36)
	server.RegisterObjectUpdate("BlackPowderBarrelUpdate", funAddrP(nox_xxx_updateBlackPowderBarrel_53C9A0), 0)
	server.RegisterObjectUpdate("OneSecondDieUpdate", funAddrP(nox_xxx_updateOneSecondDie_53CB60), 0)
	server.RegisterObjectUpdate("WaterBarrelUpdate", funAddrP(nox_xxx_updateWaterBarrel_53CB90), 0)
	server.RegisterObjectUpdate("SelfDestructUpdate", funAddrP(nox_xxx_updateSelfDestruct_53CC90), 0)
	server.RegisterObjectUpdate("BlackPowderBurnUpdate", funAddrP(nox_xxx_updateBlackPowderBurn_53CCB0), 0)
	server.RegisterObjectUpdate("DeathBallUpdate", funAddrP(nox_xxx_updateDeathBall_53D080), 0)
	server.RegisterObjectUpdate("DeathBallFragmentUpdate", funAddrP(nox_xxx_updateDeathBallFragment_53D220), 0)
	server.RegisterObjectUpdate("MoonglowUpdate", funAddrP(nox_xxx_updateMoonglow_53D270), 0)
	server.RegisterObjectUpdate("SentryGlobeUpdate", funAddrP(nox_xxx_updateSentryGlobe_510E60), 12)
	server.RegisterObjectUpdate("TelekinesisUpdate", funAddrP(nox_xxx_updateTelekinesis_53D330), 0)
	server.RegisterObjectUpdate("FistUpdate", funAddrP(nox_xxx_updateFist_53D400), 4)
	server.RegisterObjectUpdate("MeteorShowerUpdate", funAddrP(nox_xxx_updateMeteorShower_53D5A0), 4)
	server.RegisterObjectUpdate("MeteorUpdate", funAddrP(nox_xxx_meteorExplode_53D6E0), 4)
	server.RegisterObjectUpdate("ToxicCloudUpdate", funAddrP(nox_xxx_updateToxicCloud_53D850), 4)
	server.RegisterObjectUpdate("SmallToxicCloudUpdate", funAddrP(nox_xxx_updateSmallToxicCloud_53D960), 4)
	server.RegisterObjectUpdate("ArachnaphobiaUpdate", funAddrP(nox_xxx_updateArachnaphobia_53DA60), 0)
	server.RegisterObjectUpdate("ExpireUpdate", funAddrP(nox_xxx_updateExpire_53DB00), 0)
	server.RegisterObjectUpdate("BreakUpdate", funAddrP(nox_xxx_updateBreak_53DB30), 0)
	server.RegisterObjectUpdate("OpenUpdate", funAddrP(nox_xxx_updateOpen_53DBB0), 0)
	server.RegisterObjectUpdate("BreakAndRemoveUpdate", funAddrP(nox_xxx_updateBreakAndRemove_53DC30), 0)
	server.RegisterObjectUpdate("ChakramInMotionUpdate", funAddrP(nox_xxx_updateChakramInMotion_53DCC0), 28)
	server.RegisterObjectUpdate("FlagUpdate", funAddrP(nox_xxx_updateFlag_53DDF0), 12)
	server.RegisterObjectUpdate("TrapDoorUpdate", funAddrP(nox_xxx_updateTrapDoor_53DE80), 0)
	server.RegisterObjectUpdate("BallUpdate", funAddrP(nox_xxx_updateGameBall_53DF40), 32)
	server.RegisterObjectUpdate("CrownUpdate", funAddrP(nox_xxx_updateCrown_53E1D0), 12)
	server.RegisterObjectUpdate("UndeadKillerUpdate", funAddrP(nox_xxx_updateUndeadKiller_53E190), 0)
	server.RegisterObjectUpdate("HarpoonUpdate", funAddrP(nox_xxx_updateHarpoon_54F380), 4)
	server.RegisterObjectUpdate("MonsterGeneratorUpdate", funAddrP(nox_xxx_updateMonsterGenerator_54E930), 164)

	server.RegisterObjectUpdateParse("PushUpdate", wrapObjectUpdateParseC(funAddrP(sub_536550)))
	server.RegisterObjectUpdateParse("TriggerUpdate", wrapObjectUpdateParseC(funAddrP(sub_5365B0)))
	server.RegisterObjectUpdateParse("ToggleUpdate", wrapObjectUpdateParseC(funAddrP(sub_5365B0)))
	server.RegisterObjectUpdateParse("LoopAndDamageUpdate", wrapObjectUpdateParseC(funAddrP(sub_536580)))
	server.RegisterObjectUpdateParse("LifetimeUpdate", wrapObjectUpdateParseC(funAddrP(sub_536600)))
	server.RegisterObjectUpdateParse("SkullUpdate", wrapObjectUpdateParseC(funAddrP(sub_5364E0)))
}

// nox_xxx_updatePlayer_4F8100
func nox_xxx_updatePlayer_4F8100(up *nox_object_t) { Nox_xxx_updatePlayer_4F8100(asObjectS(up)) }

// nox_xxx_objectApplyForce_52DF80
func nox_xxx_objectApplyForce_52DF80(vec *float32, obj *nox_object_t, force float32) {
	GetServer().ApplyForce(asObjectS(obj), AsPointf(unsafe.Pointer(vec)), float64(force))
}

// nox_xxx_updatePixie_53CD20
func nox_xxx_updatePixie_53CD20(cobj *nox_object_t) { Nox_xxx_updatePixie_53CD20(asObjectS(cobj)) }

// nox_xxx_teleportAllPixies_4FD090
func nox_xxx_teleportAllPixies_4FD090(cobj *nox_object_t) {
	Nox_xxx_teleportAllPixies_4FD090(asObjectS(cobj))
}

// nox_xxx_enemyAggro_5335D0
func nox_xxx_enemyAggro_5335D0(cobj *nox_object_t, r float32) *nox_object_t {
	return asObjectC(Nox_xxx_enemyAggro_5335D0(asObjectS(cobj), r))
}

// sub_5336D0
func sub_5336D0(cobj *nox_object_t) float64 { return float64(Sub_5336D0(asObjectS(cobj))) }

// nox_xxx_updatePlayerObserver_4E62F0
func nox_xxx_updatePlayerObserver_4E62F0(a1p *nox_object_t) {
	Nox_xxx_updatePlayerObserver_4E62F0(asObjectS(a1p))
}

// nox_xxx_updateProjectile_53AC10
func nox_xxx_updateProjectile_53AC10(a1 *nox_object_t) {
	Nox_xxx_updateProjectile_53AC10(asObjectS(a1))
}

// nox_xxx___mkgmtime_538280
func nox_xxx___mkgmtime_538280(a1 *nox_object_t) {
	Nox_xxx___mkgmtime_538280(asObjectS(a1))
}

func Get_nox_xxx___mkgmtime_538280() unsafe.Pointer {
	return funAddrP(nox_xxx___mkgmtime_538280)
}

func wrapObjectUpdateParseC(ptr unsafe.Pointer) server.ObjectParseFunc {
	return func(objt *server.ObjectType, args []string) error {

		if Nox_call_objectType_parseUpdate_go(ptr, strings.Join(args, " "), objt.UpdateData) == 0 {
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
func Nox_call_objectType_parseUpdate_go(a1 unsafe.Pointer, a2 string, a3 unsafe.Pointer) int {
	cstr := CString(a2)
	defer StrFree(cstr)
	return int(asFuncT[func(*byte, unsafe.Pointer) int32](uintptr(a1))(cstr, a3))
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
	return bool(nox_xxx_playerCheckStrength_4F3180(asObjectC(a1), asObjectC(a2)))
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
