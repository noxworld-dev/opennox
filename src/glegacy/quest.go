package legacy

/*
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_1.h"
int  sub_51A920(int a1);
void sub_4D10F0(char* a1);
void sub_4F1F20();
void sub_51A1F0(int a1);
extern unsigned int nox_client_gui_flag_1556112;
*/
import "C"
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

//export nox_server_questAllowDefault
func nox_server_questAllowDefault() C.bool { return C.bool(Nox_server_questAllowDefault()) }

//export nox_server_questNextStageThreshold_4D74F0
func nox_server_questNextStageThreshold_4D74F0(lvl int) int {
	return Nox_server_questNextStageThreshold_4D74F0(lvl)
}

//export sub_4D6F30
func sub_4D6F30() int { return Sub_4D6F30() }
func Nox_game_getQuestStage_4E3CC0() int {
	return int(C.nox_game_getQuestStage_4E3CC0())
}
func Nox_xxx_getQuestStage_51A930() int {
	return int(C.nox_xxx_getQuestStage_51A930())
}
func Sub_4E3D50() {
	C.sub_4E3D50()
}
func Sub_4E3DD0() {
	C.sub_4E3DD0()
}
func Sub_4F1F20() {
	C.sub_4F1F20()
}
func Nox_xxx_getQuestMapFile_4D0F60() string {
	return GoString(C.nox_xxx_getQuestMapFile_4D0F60())
}
func Sub_4D0F30() {
	C.sub_4D0F30()
}
func Nox_game_setQuestStage_4E3CD0(a1 int) {
	C.nox_game_setQuestStage_4E3CD0(C.int(a1))
}
func Sub_51A920(a1 int) {
	C.sub_51A920(C.int(a1))
}
func Sub_51A1F0(a1 int) {
	C.sub_51A1F0(C.int(a1))
}
func Sub_4D10F0(a1 string) {
	C.sub_4D10F0(internCStr(a1))
}
func Sub_4D7520(a1 int) {
	C.sub_4D7520(C.int(a1))
}
func Sub_4D9CF0(a1 int) {
	C.sub_4D9CF0(C.int(a1))
}
func Sub_4D6000(a1 *server.Object) {
	C.sub_4D6000(asObjectC(a1))
}
func Sub_4D9D20(a1 int, a2 *server.Object) {
	C.sub_4D9D20(C.int(a1), asObjectC(a2))
}
func Nox_xxx_unitInitPlayer_4EFE80(a1 *server.Object) {
	C.nox_xxx_unitInitPlayer_4EFE80(asObjectC(a1))
}
func Sub_415D10(a1 int) int {
	return int(C.sub_415D10(C.int(a1)))
}
func Nox_xxx_playerRespawnItem_4EF750(a1 *server.Object, a2 string, a3 unsafe.Pointer, a4 int, a5 int) *server.Object {
	return asObjectS(C.nox_xxx_playerRespawnItem_4EF750(asObjectC(a1), internCStr(a2), (*C.int)(a3), C.int(a4), C.int(a5)))
}
func Nox_xxx_modifSetItemAttrs_4E4990(a1 *server.Object, a2 unsafe.Pointer) {
	C.nox_xxx_modifSetItemAttrs_4E4990(asObjectC(a1), (*C.int)(a2))
}
func Sub_4184D0(a1 unsafe.Pointer) {
	C.sub_4184D0((*nox_team_t)(a1))
}
func Nox_xxx_createAtImpl_4191D0(a1 server.TeamID, a2 *server.ObjectTeam, a3 int, a4 uint32, a5 int) {
	C.nox_xxx_createAtImpl_4191D0(C.uchar(a1), a2.C(), C.int(a3), C.int(a4), C.int(a5))
}
func Nox_xxx_cliPlrInfoLoadFromFile_41A2E0(a1 string, a2 ntype.PlayerInd) int {
	return int(C.nox_xxx_cliPlrInfoLoadFromFile_41A2E0(internCStr(a1), C.int(a2)))
}
