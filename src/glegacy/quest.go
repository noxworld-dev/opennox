package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_server_questAllowDefault              func() bool
	Nox_server_questNextStageThreshold_4D74F0 func(lvl int) int
	Sub_4D6F30                                func() int
)

// nox_server_questAllowDefault
func nox_server_questAllowDefault() bool { return bool(Nox_server_questAllowDefault()) }

// nox_server_questNextStageThreshold_4D74F0
func nox_server_questNextStageThreshold_4D74F0(lvl int32) int32 {
	return int32(Nox_server_questNextStageThreshold_4D74F0(int(lvl)))
}

// sub_4D6F30
func sub_4D6F30() int { return Sub_4D6F30() }
func Nox_game_getQuestStage_4E3CC0() int {
	return int(nox_game_getQuestStage_4E3CC0())
}
func Nox_xxx_getQuestStage_51A930() int {
	return int(nox_xxx_getQuestStage_51A930())
}
func Sub_4E3D50() {
	sub_4E3D50()
}
func Sub_4E3DD0() {
	sub_4E3DD0()
}
func Sub_4F1F20() {
	sub_4F1F20()
}
func Nox_xxx_getQuestMapFile_4D0F60() string {
	return GoString(nox_xxx_getQuestMapFile_4D0F60())
}
func Sub_4D0F30() {
	sub_4D0F30()
}
func Nox_game_setQuestStage_4E3CD0(a1 int) {
	nox_game_setQuestStage_4E3CD0(int32(a1))
}
func Sub_51A920(a1 int) {
	sub_51A920(int32(a1))
}
func Sub_51A1F0(a1 int) {
	sub_51A1F0(int32(a1))
}
func Sub_4D10F0(a1 string) {
	sub_4D10F0(internCStr(a1))
}
func Sub_4D7520(a1 int) {
	sub_4D7520(int32(a1))
}
func Sub_4D9CF0(a1 int) {
	sub_4D9CF0(int32(a1))
}
func Sub_4D6000(a1 *server.Object) {
	sub_4D6000(asObjectC(a1))
}
func Sub_4D9D20(a1 int, a2 *server.Object) {
	sub_4D9D20(int32(a1), asObjectC(a2))
}
func Nox_xxx_unitInitPlayer_4EFE80(a1 *server.Object) {
	nox_xxx_unitInitPlayer_4EFE80(asObjectC(a1))
}
func Sub_415D10(a1 int) int {
	return int(sub_415D10(int32(a1)))
}
func Nox_xxx_playerRespawnItem_4EF750(a1 *server.Object, a2 string, a3 unsafe.Pointer, a4 int, a5 int) *server.Object {
	return asObjectS(nox_xxx_playerRespawnItem_4EF750(asObjectC(a1), internCStr(a2), (*int32)(a3), int32(a4), int32(a5)))
}
func Nox_xxx_modifSetItemAttrs_4E4990(a1 *server.Object, a2 unsafe.Pointer) {
	nox_xxx_modifSetItemAttrs_4E4990(asObjectC(a1), (*int32)(a2))
}
func Sub_4184D0(a1 unsafe.Pointer) {
	sub_4184D0((*nox_team_t)(a1))
}
func Nox_xxx_createAtImpl_4191D0(a1 server.TeamID, a2 *server.ObjectTeam, a3 int, a4 uint32, a5 int) {
	nox_xxx_createAtImpl_4191D0(byte(a1), a2.C(), int32(a3), int32(a4), int32(a5))
}
func Nox_xxx_cliPlrInfoLoadFromFile_41A2E0(a1 string, a2 ntype.PlayerInd) int {
	return int(nox_xxx_cliPlrInfoLoadFromFile_41A2E0(internCStr(a1), int32(a2)))
}
