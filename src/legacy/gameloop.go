package legacy

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "GAME2_3.h"
#include "common__system__team.h"
#include "common__net_list.h"
#include "client__gui__guimsg.h"
#include "client__drawable__drawable.h"

char* nox_xxx_getRandomName_4358A0();
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_client_getIntroScreenDuration_44E3B0 func() int
	Nox_client_getBriefDuration              func() int
	Nox_game_exit_xxx2                       func()
	Sub_470510                               func()
	Sub_4703F0                               func()
	Nox_xxx_cliDrawConnectedLoop_43B360      func() int
	Nox_client_guiXxxDestroy_4A24A0          func() int
	Nox_client_quit_4460C0                   func()
)

//export nox_client_getIntroScreenDuration_44E3B0
func nox_client_getIntroScreenDuration_44E3B0() int {
	return Nox_client_getIntroScreenDuration_44E3B0()
}

//export nox_client_getBriefDuration
func nox_client_getBriefDuration() int {
	return Nox_client_getBriefDuration()
}

//export nox_game_SetCliDrawFunc
func nox_game_SetCliDrawFunc(fnc unsafe.Pointer) {
	if fnc == nil {
		GetClient().SetDrawFunc(nil)
	} else {
		GetClient().SetDrawFunc(func() bool {
			return ccall.CallIntVoid(fnc) != 0
		})
	}
}

//export sub_43DE40
func sub_43DE40(fnc unsafe.Pointer) int {
	if fnc == nil {
		GetClient().SetUpdateFunc2(nil)
	} else {
		GetClient().SetUpdateFunc2(func() bool {
			return ccall.CallIntVoid(fnc) != 0
		})
	}
	return 1
}

//export nox_game_exit_xxx2
func nox_game_exit_xxx2() {
	Nox_game_exit_xxx2()
}

//export sub_470510
func sub_470510() {
	Sub_470510()
}

//export sub_4703F0
func sub_4703F0() {
	Sub_4703F0()
}

//export nox_xxx_cliDrawConnectedLoop_43B360
func nox_xxx_cliDrawConnectedLoop_43B360() int {
	return Nox_xxx_cliDrawConnectedLoop_43B360()
}

//export nox_client_guiXxxDestroy_4A24A0
func nox_client_guiXxxDestroy_4A24A0() int {
	return Nox_client_guiXxxDestroy_4A24A0()
}

//export nox_client_quit_4460C0
func nox_client_quit_4460C0() {
	Nox_client_quit_4460C0()
}
func Sub_43DB60() {
	C.sub_43DB60()
}
func Nox_xxx_mapGenStart_4D4320() int {
	return int(C.nox_xxx_mapGenStart_4D4320())
}
func Nox_xxx_servResetPlayers_4D23C0() {
	C.nox_xxx_servResetPlayers_4D23C0()
}
func Nox_xxx_gameLoopMemDump_413E30() {
	C.nox_xxx_gameLoopMemDump_413E30()
}
func Sub_4137E0() {
	C.sub_4137E0()
}
func Nox_xxx_getRandomName_4358A0() string {
	return GoString(C.nox_xxx_getRandomName_4358A0())
}
func Sub_4E4EF0() {
	C.sub_4E4EF0()
}
func Sub_48D740() {
	C.sub_48D740()
}
func Sub_473930() {
	C.sub_473930()
}
func Sub_43DBA0() {
	C.sub_43DBA0()
}
func Nox_xxx_getHostInfoPtr_431770() *server.PlayerInfo {
	return (*server.PlayerInfo)(unsafe.Pointer(C.nox_xxx_getHostInfoPtr_431770()))
}
func Sub_41FA40() string {
	return GoString(C.sub_41FA40())
}
func Sub_43AF40() int {
	return int(C.sub_43AF40())
}
func Sub_43AA70() {
	C.sub_43AA70()
}
func Nox_server_gameDoSwitchMap_40A680() int {
	return int(C.nox_server_gameDoSwitchMap_40A680())
}
func Sub_459D60() int {
	return int(C.sub_459D60())
}
func Sub_459DA0() int {
	return int(C.sub_459DA0())
}
func Sub_4DF020() {
	C.sub_4DF020()
}
func Sub_4161E0() {
	C.sub_4161E0()
}
func Sub_473960() {
	C.sub_473960()
}
func Sub_48D800() {
	C.sub_48D800()
}
func Sub_49A8C0() {
	C.sub_49A8C0()
}
func Sub_4E4DE0() {
	C.sub_4E4DE0()
}
func Sub_48D760() {
	C.sub_48D760()
}
func Sub_417CF0() {
	C.sub_417CF0()
}
func Nox_xxx_spriteLoadError_4356E0() {
	C.nox_xxx_spriteLoadError_4356E0()
}
func Sub_499450() {
	C.sub_499450()
}
func Sub_495AE0() {
	C.sub_495AE0()
}
func Sub_4959D0() {
	C.sub_4959D0()
}
func Sub_496120() {
	C.sub_496120()
}
func Sub_49AEA0() {
	C.sub_49AEA0()
}
func Nox_xxx_j_resetNPCRenderData_49A2E0() {
	C.nox_xxx_j_resetNPCRenderData_49A2E0()
}
func Nox_xxx_netSavePlayer_41CE00() {
	C.nox_xxx_netSavePlayer_41CE00()
}
func Sub_4D39F0(a1 string) {
	C.sub_4D39F0(internCStr(a1))
}
func Sub_48D4B0(a1 int) {
	C.sub_48D4B0(C.int(a1))
}
func Nox_xxx_set3512_40A340(a1 int) {
	C.nox_xxx_set3512_40A340(C.int(a1))
}
func Sub_459D50(a1 int) {
	C.sub_459D50(C.int(a1))
}
func Sub_446580(a1 int) {
	C.sub_446580(C.int(a1))
}
func Nox_xxx_gameSetMapPath_409D70(a1 string) {
	C.nox_xxx_gameSetMapPath_409D70(internCStr(a1))
}
func Nox_xxx_gui_43E1A0(a1 int) {
	C.nox_xxx_gui_43E1A0(C.int(a1))
}
func Nox_xxx_printCentered_445490(str string) {
	wstr, free := CWString(str)
	defer free()
	C.nox_xxx_printCentered_445490(wstr)
}
func Nox_xxx_mapValidateMB_4CF470(a1 string, a2 uint32) int {
	return int(C.nox_xxx_mapValidateMB_4CF470(internCStr(a1), C.int(a2)))
}
func Nox_xxx_copyServerIPAndPort_431790(a1 string) {
	C.nox_xxx_copyServerIPAndPort_431790(internCStr(a1))
}
