package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_mapToGameFlags                func(v int) noxflags.GameFlag
	Sub_40A1A0                        func() int
	Nox_xxx_mapSwitchLevel_4D12E0_end func()
)

type Server interface {
	S() *server.Server
	SetUpdateFunc2(fnc func() bool)
	ServerPort() int
	ServStartCountdown(dt int, text strman.ID)
	TickRate() uint32
	Frame() uint32
	SwitchMap(name string)
	GetFlag3592() bool
	Sub40A040settings(a1 int, a2 int)
	CreateObjectAt(obj, owner server.Obj, pt types.Pointf)
	FirstServerObject() *server.Object
	AudioEventObj(id sound.ID, iobj server.Obj, kind int, code uint32)
	AudioEventPos(id sound.ID, pos types.Pointf, kind int, code uint32)
	NetUpdateRemotePlrAudioEvents(obj *server.Object, v2 unsafe.Pointer, v18 int8)
	Nox_xxx_mapDamageUnitsAround(pos types.Pointf, r1, r2 float32, dmg int, dtyp object.DamageType, who *server.Object, a7 server.Obj, damageWalls bool)
	Sub_518460(pos types.Pointf, mask byte, scanSub bool) *server.Waypoint
	Sub4537F0()
	Nox_xxx_mapReset5028E0()
	Nox_xxx_free503F40()
	ObjectDeleteLast(obj *server.Object)
	ObjectsAddPending()
	ObjectsClearPending()
	FinalizeDeletingObjects()
	TeamsResetYyy() int
	TeamsRemoveActive(hooks bool) int
	TeamRemove(t *server.Team, netUpd bool)
	DelayedDelete(obj *server.Object)
	PendingObjByScriptID4CFFE0(sid int) *server.Object
	PendingWaypointByInd579C60(id uint32) *server.Waypoint
	Sub504720(a1, a2 uint32) int32
	IsEnemyTo(a1, a2 *server.Object) bool
	IsFish(obj *server.Object) bool
	IsRat(obj *server.Object) bool
	IsFrog(obj *server.Object) bool
	NewObjectByTypeID(id string) *server.Object
	ApplyForce(obj *server.Object, vec types.Pointf, force float64)
	PlayerSpell(u *server.Object)
	Nox_script_event_playerLeave(pl *server.Player)
	NoxScriptC() NoxScript
	GetUnitNetCode(p server.Obj) int
	Nox_xxx_spellFlySearchTarget(pos *types.Pointf, mslo server.Obj, sflags things.SpellFlags, dist float32, a5 int, sself *server.Object) *server.Object
	SpellHasFlags(ind spell.ID, flag things.SpellFlags) bool
	SpellFlags(ind spell.ID) things.SpellFlags
	Nox_xxx_spellAccept4FD400(spellID spell.ID, a2, obj3, obj4 *server.Object, sa *server.SpellAcceptArg, lvl int) bool
}

var (
	GetServer func() Server
)

// nox_getHostPlayerUnit
func nox_getHostPlayerUnit() *nox_object_t {
	return asObjectC(GetServer().S().Players.HostUnit)
}

// nox_xxx_servStartCountdown_40A2A0
func nox_xxx_servStartCountdown_40A2A0(a1 int32, a2 *byte) {
	GetServer().ServStartCountdown(int(a1), strman.ID(GoString(a2)))
}

// sub_40A040_settings
func sub_40A040_settings(a1 int16, a2 byte) {
	GetServer().Sub40A040settings(int(a1), int(a2))
}

// nox_server_SetLastObjectScriptID
func nox_server_SetLastObjectScriptID(id uint32) {
	GetServer().S().Objs.SetLastObjectScriptID(server.ObjectScriptID(id))
}

// nox_server_LastObjectScriptID
func nox_server_LastObjectScriptID() uint32 {
	return uint32(GetServer().S().Objs.LastObjectScriptID())
}

// nox_server_NextObjectScriptID
func nox_server_NextObjectScriptID() uint32 {
	return uint32(GetServer().S().Objs.NextObjectScriptID())
}

// nox_xxx_servGetPort_40A430
func nox_xxx_servGetPort_40A430() int32 {
	return int32(GetServer().ServerPort())
}

// sub_40A300
func sub_40A300() int32 {
	return bool2int32(GetServer().GetFlag3592())
}

// nox_xxx_mapLoad_4D2450
func nox_xxx_mapLoad_4D2450(a1 *byte) {
	GetServer().SwitchMap(GoString(a1))
}

// nox_mapToGameFlags_4CFF50
func nox_mapToGameFlags_4CFF50(v int32) int32 {
	return int32(Nox_mapToGameFlags(int(v)))
}

// sub_40A1A0
func sub_40A1A0() int32 {
	return int32(Sub_40A1A0())
}

// gameFPS
func gameFPS() uint32 {
	return GetServer().TickRate()
}

// gameFrame
func gameFrame() uint32 {
	return GetServer().Frame()
}
func Sub_409A70(a1 int) int {
	return int(sub_409A70(int16(a1)))
}
func Nox_xxx_netInformTextMsg2_4DA180(a1 int, a2 unsafe.Pointer) {
	nox_xxx_netInformTextMsg2_4DA180(int32(a1), (*byte)(a2))
}
func Nox_xxx_netReportUnitHeight_4D9020(a1 ntype.PlayerInd, a2 *server.Object) {
	nox_xxx_netReportUnitHeight_4D9020(int32(a1), asObjectC(a2))
}
func Sub_4FF7B0(pl *server.Player) {
	sub_4FF7B0((*nox_playerInfo)(pl.C()))
}
func Sub_511100(a1 int) {
	sub_511100(int32(a1))
}
func Nox_xxx_netUpdateRemotePlr_501CA0(a1 *server.Object) {
	nox_xxx_netUpdateRemotePlr_501CA0(asObjectC(a1))
}
func Nox_xxx_netSendObjects2Plr_519410(a1 *server.Object, a2 *server.Object) {
	nox_xxx_netSendObjects2Plr_519410(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_netUnmarkMinimapObj_417300(a1 ntype.PlayerInd, a2 *server.Object, a3 int) {
	nox_xxx_netUnmarkMinimapObj_417300(int32(a1), asObjectC(a2), int32(a3))
}
func Sub_4D6770(a1 ntype.PlayerInd) {
	sub_4D6770(int32(a1))
}
func Sub_4D6880(a1 int, a2 int) {
	sub_4D6880(int32(a1), int32(a2))
}
func Sub_4D60B0() {
	sub_4D60B0()
}
func Sub_4CFDF0(a1 int) {
	sub_4CFDF0(int32(a1))
}
func Nox_xxx_playerMapTracksObj_4173D0(a1 int, a2 *server.Object) int {
	return int(nox_xxx_playerMapTracksObj_4173D0(int32(a1), asObjectC(a2)))
}
func Sub_519710(a1 unsafe.Pointer) int {
	return int(sub_519710(a1))
}
func Nox_xxx_updateUnits_51B100_D() {
	nox_xxx_updateUnits_51B100_D()
}
func Nox_xxx_decay_511750() {
	nox_xxx_decay_511750()
}
func Nox_server_checkVictory_509A60() {
	nox_server_checkVictory_509A60()
}
func Nox_xxx_allocHitArray_5486D0() {
	nox_xxx_allocHitArray_5486D0()
}
func Nox_xxx_updateObjectsVelocity_5118A0(a1 float32) {
	nox_xxx_updateObjectsVelocity_5118A0(float32(a1))
}
func Sub_548B60() {
	sub_548B60()
}
func Sub_537700() *server.Object {
	return asObjectS(sub_537700())
}
func Nox_xxx_collide_548740() {
	nox_xxx_collide_548740()
}
func Nox_xxx_updatePoison_4EE8F0(a1 *server.Object, a2 int) {
	nox_xxx_updatePoison_4EE8F0(asObjectC(a1), int32(a2))
}
func Nox_xxx_updateUnitBuffs_4FF620(a1 *server.Object) {
	nox_xxx_updateUnitBuffs_4FF620(asObjectC(a1))
}
func Nox_xxx_reconAttempt_41E390() {
	nox_xxx_reconAttempt_41E390()
}
func Sub_5096F0() {
	sub_5096F0()
}
func Sub_416720() {
	sub_416720()
}
func Sub_4D7CC0() {
	sub_4D7CC0()
}
func Sub_40AA00() int {
	return int(sub_40AA00())
}
func Sub_40AA40() int {
	return int(sub_40AA40())
}
func Nox_xxx_countNonEliminatedPlayersInTeam_40A830(a1 *server.Team) int {
	return int(nox_xxx_countNonEliminatedPlayersInTeam_40A830((*nox_team_t)(a1.C())))
}
func Sub_40A770() int {
	return int(sub_40A770())
}
func Sub_40A6B0() int {
	return int(sub_40A6B0())
}
func Sub_40A6A0(a1 int) {
	sub_40A6A0(int32(a1))
}
func Nox_xxx_netReportAllLatency_4D3050() {
	nox_xxx_netReportAllLatency_4D3050()
}
func Sub_4183C0() {
	sub_4183C0()
}
func Sub_4D7150() {
	sub_4D7150()
}
func Sub_4D71F0() {
	sub_4D71F0()
}
func Nox_server_checkWarpGate_4D7600() {
	nox_server_checkWarpGate_4D7600()
}
func Sub_4D7A80() {
	sub_4D7A80()
}
func Sub_4EC720() {
	sub_4EC720()
}
func Sub_50D890() {
	sub_50D890()
}
func Sub_4E4170() {
	sub_4E4170()
}
func Nox_xxx_voteUptate_506F30() {
	nox_xxx_voteUptate_506F30()
}
func Nox_xxx_net_4263C0() {
	nox_xxx_net_4263C0()
}
func Sub_4E76C0() {
	sub_4E76C0()
}
func Nox_xxx_protectData_56F5C0() {
	nox_xxx_protectData_56F5C0()
}
func Nox_xxx_playerSomeWallsUpdate_5003B0(a1 *server.Object) {
	nox_xxx_playerSomeWallsUpdate_5003B0(asObjectC(a1))
}
func Sub_57B140() bool {
	return bool(sub_57B140())
}
func Sub_57B0A0() {
	sub_57B0A0()
}
func Sub_4DF120(a1 unsafe.Pointer) {
	sub_4DF120(a1)
}
func Sub_4DF180(a1 unsafe.Pointer) {
	sub_4DF180(a1)
}
func Nox_xxx_netUpdateObjectSpecial_527E50(a1 *server.Object, a2 *server.Object) {
	nox_xxx_netUpdateObjectSpecial_527E50(asObjectC(a1), asObjectC(a2))
}
func Sub_4D15C0() {
	sub_4D15C0()
}
func Sub_4D7B40() {
	sub_4D7B40()
}
func Sub_41E4B0(a1 int) {
	sub_41E4B0(int32(a1))
}
func Sub_56F1C0() {
	sub_56F1C0()
}
func Sub_4E4ED0() {
	sub_4E4ED0()
}
func Nox_motd_4463E0(a1 int) {
	nox_motd_4463E0(int32(a1))
}
func Sub_4259C0() {
	sub_4259C0()
}
func Sub_4D7C60() {
	sub_4D7C60()
}
func Sub_518770() int {
	return int(sub_518770())
}
func Nox_xxx_allocVisitNodesArray_50AB90() int {
	return int(nox_xxx_allocVisitNodesArray_50AB90())
}
func Nox_xxx_allocItemRespawnArray_4ECA60() int {
	return int(nox_xxx_allocItemRespawnArray_4ECA60())
}
func Nox_xxx_registerShopClasses_50E2A0() int {
	return int(nox_xxx_registerShopClasses_50E2A0())
}
func Nox_xxx_allocMonsterRelatedArrays_50D780() int {
	return int(nox_xxx_allocMonsterRelatedArrays_50D780())
}
func Nox_xxx_allocVoteArray_5066D0() int {
	return int(nox_xxx_allocVoteArray_5066D0())
}
func Nox_xxx_allocMagicWallArray_4FF730() int {
	return int(nox_xxx_allocMagicWallArray_4FF730())
}
func Nox_xxx_monsterList_517520() int {
	return int(nox_xxx_monsterList_517520())
}
func Sub_416920() {
	sub_416920()
}
func Nox_xxx_allocPendingOwnsArray_516EE0() int {
	return int(nox_xxx_allocPendingOwnsArray_516EE0())
}
func Sub_421B10() {
	sub_421B10()
}
func Sub_516F10() {
	sub_516F10()
}
func Sub_4FF770() {
	sub_4FF770()
}
func Sub_4259F0() {
	sub_4259F0()
}
func Sub_50ABF0() {
	sub_50ABF0()
}
func Sub_4ECA90() {
	sub_4ECA90()
}
func Sub_506720() {
	sub_506720()
}
func Sub_50D820() {
	sub_50D820()
}
func Nox_xxx_deleteShopInventories_50E300() {
	nox_xxx_deleteShopInventories_50E300()
}
func Sub_416950() {
	sub_416950()
}
func Sub_56F3B0() {
	sub_56F3B0()
}
func Sub_51D0E0() {
	sub_51D0E0()
}
func Sub_502DF0() {
	sub_502DF0()
}
func Sub_481410() {
	sub_481410()
}
func Sub_4D0550(a1 string) {
	sub_4D0550(internCStr(a1))
}
func Sub_4165F0(a1 int, a2 int) {
	sub_4165F0(int32(a1), int32(a2))
}
func Sub_4D7430() int {
	return int(sub_4D7430())
}
func Sub_4D76F0() int {
	return int(sub_4D76F0())
}
func Sub_4D76E0(a1 int) {
	sub_4D76E0(int32(a1))
}
func Nox_xxx_ruleSetNoRespawn_40A5E0(a1 int) {
	nox_xxx_ruleSetNoRespawn_40A5E0(int32(a1))
}
func Sub_455C10() {
	sub_455C10()
}
func Sub_456050() {
	sub_456050()
}
func Nox_xxx_mapFindCrown_4CFC30() {
	nox_xxx_mapFindCrown_4CFC30()
}
func Nox_xxx_mapInfoSetCapflag_417EA0() int {
	return int(nox_xxx_mapInfoSetCapflag_417EA0())
}
func Nox_xxx_mapInfoSetFlagball_417F30() int {
	return int(nox_xxx_mapInfoSetFlagball_417F30())
}
func Nox_xxx_mapInfoSetKotr_4180D0() int {
	return int(nox_xxx_mapInfoSetKotr_4180D0())
}
func Nox_xxx_teamAssignFlags_418640() {
	nox_xxx_teamAssignFlags_418640()
}
func Nox_xxx_toggleAllTeamFlags_418690(a1 int) {
	nox_xxx_toggleAllTeamFlags_418690(int32(a1))
}
func Sub_410730() {
	sub_410730()
}
func Nox_xxx_wallBreackableListClear_410810() {
	nox_xxx_wallBreackableListClear_410810()
}
func Nox_xxx_waypointDeleteAll_579DD0() {
	nox_xxx_waypointDeleteAll_579DD0()
}
func Nox_xxx_j_allocHitArray_511840() {
	nox_xxx_j_allocHitArray_511840()
}
func Nox_xxx_decayDestroy_5117B0() {
	nox_xxx_decayDestroy_5117B0()
}
func Sub_510E50() {
	sub_510E50()
}
func Sub_4D1610() {
	sub_4D1610()
}
func Sub_4EC5B0() {
	sub_4EC5B0()
}
func Sub_50E360() {
	sub_50E360()
}
func Sub_50D7E0() {
	sub_50D7E0()
}
func Sub_4E4F80() {
	sub_4E4F80()
}

// nox_xxx_mapSwitchLevel_4D12E0_end
func nox_xxx_mapSwitchLevel_4D12E0_end() {
	Nox_xxx_mapSwitchLevel_4D12E0_end()
}

var _ = [1]struct{}{}[60-unsafe.Sizeof(server.TileDef{})]

func Get_nox_tile_defs_arr() []server.TileDef {
	ptr := (*server.TileDef)(unsafe.Pointer(&nox_tile_defs_arr[0]))
	sz := int(nox_tile_def_cnt)
	return unsafe.Slice(ptr, len(nox_tile_defs_arr))[:sz]
}
