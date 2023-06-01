package legacy

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

// nox_client_getIntroScreenDuration_44E3B0
func nox_client_getIntroScreenDuration_44E3B0() int32 {
	return int32(Nox_client_getIntroScreenDuration_44E3B0())
}

// nox_client_getBriefDuration
func nox_client_getBriefDuration() int32 {
	return int32(Nox_client_getBriefDuration())
}

// nox_game_SetCliDrawFunc
func nox_game_SetCliDrawFunc(fnc unsafe.Pointer) {
	if fnc == nil {
		GetClient().SetDrawFunc(nil)
	} else {
		GetClient().SetDrawFunc(func() bool {
			return ccall.AsFunc[func() int](fnc)() != 0
		})
	}
}

func sub_43DE40(fnc func() bool) int32 {
	if fnc == nil {
		GetServer().SetUpdateFunc2(nil)
	} else {
		GetServer().SetUpdateFunc2(fnc)
	}
	return 1
}

// nox_game_exit_xxx2
func nox_game_exit_xxx2() {
	Nox_game_exit_xxx2()
}

// sub_470510
func sub_470510() {
	Sub_470510()
}

// sub_4703F0
func sub_4703F0() {
	Sub_4703F0()
}

// nox_xxx_cliDrawConnectedLoop_43B360
func nox_xxx_cliDrawConnectedLoop_43B360() int {
	return Nox_xxx_cliDrawConnectedLoop_43B360()
}

// nox_client_guiXxxDestroy_4A24A0
func nox_client_guiXxxDestroy_4A24A0() int {
	return Nox_client_guiXxxDestroy_4A24A0()
}

// nox_client_quit_4460C0
func nox_client_quit_4460C0() {
	Nox_client_quit_4460C0()
}
func Sub_43DB60() {
	sub_43DB60()
}
func Nox_xxx_mapGenStart_4D4320() int {
	return int(nox_xxx_mapGenStart_4D4320())
}
func Nox_xxx_servResetPlayers_4D23C0() {
	nox_xxx_servResetPlayers_4D23C0()
}
func Nox_xxx_gameLoopMemDump_413E30() {
	nox_xxx_gameLoopMemDump_413E30()
}
func Sub_4137E0() {
	sub_4137E0()
}
func Nox_xxx_getRandomName_4358A0() string {
	return GoString(nox_xxx_getRandomName_4358A0())
}
func Sub_4E4EF0() {
	sub_4E4EF0()
}
func Sub_48D740() {
	sub_48D740()
}
func Sub_473930() {
	sub_473930()
}
func Sub_43DBA0() {
	sub_43DBA0()
}
func Nox_xxx_getHostInfoPtr_431770() *server.PlayerInfo {
	return (*server.PlayerInfo)(unsafe.Pointer(nox_xxx_getHostInfoPtr_431770()))
}
func Sub_41FA40() string {
	return GoString(sub_41FA40())
}
func Sub_43AF40() int {
	return int(sub_43AF40())
}
func Sub_43AA70() {
	sub_43AA70()
}
func Nox_server_gameDoSwitchMap_40A680() int {
	return int(nox_server_gameDoSwitchMap_40A680())
}
func Sub_459D60() int {
	return int(sub_459D60())
}
func Sub_459DA0() int {
	return int(sub_459DA0())
}
func Sub_4DF020() {
	sub_4DF020()
}
func Sub_4161E0() {
	sub_4161E0()
}
func Sub_473960() {
	sub_473960()
}
func Sub_48D800() {
	sub_48D800()
}
func Sub_49A8C0() {
	sub_49A8C0()
}
func Sub_4E4DE0() {
	sub_4E4DE0()
}
func Sub_48D760() {
	sub_48D760()
}
func Sub_417CF0() {
	sub_417CF0()
}
func Nox_xxx_spriteLoadError_4356E0() {
	nox_xxx_spriteLoadError_4356E0()
}
func Sub_499450() {
	sub_499450()
}
func Sub_4959D0() {
	sub_4959D0()
}
func Sub_496120() {
	sub_496120()
}
func Sub_49AEA0() {
	sub_49AEA0()
}
func Nox_xxx_j_resetNPCRenderData_49A2E0() {
	nox_xxx_j_resetNPCRenderData_49A2E0()
}
func Nox_xxx_netSavePlayer_41CE00() {
	nox_xxx_netSavePlayer_41CE00()
}
func Sub_4D39F0(a1 string) {
	sub_4D39F0(internCStr(a1))
}
func Sub_48D4B0(a1 int) {
	sub_48D4B0(int32(a1))
}
func Nox_xxx_set3512_40A340(a1 int) {
	nox_xxx_set3512_40A340(int32(a1))
}
func Sub_459D50(a1 int) {
	sub_459D50(int32(a1))
}
func Nox_xxx_gameSetMapPath_409D70(a1 string) {
	nox_xxx_gameSetMapPath_409D70(internCStr(a1))
}
func Nox_xxx_gui_43E1A0(a1 int) {
	nox_xxx_gui_43E1A0(int32(a1))
}
func Nox_xxx_printCentered_445490(str string) {
	wstr, free := CWString(str)
	defer free()
	nox_xxx_printCentered_445490(wstr)
}
func Nox_xxx_mapValidateMB_4CF470(a1 string, a2 uint32) int {
	return int(nox_xxx_mapValidateMB_4CF470(internCStr(a1), int32(a2)))
}
func Nox_xxx_copyServerIPAndPort_431790(a1 string) {
	nox_xxx_copyServerIPAndPort_431790(internCStr(a1))
}
