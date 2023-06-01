package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_unitIsUnitTT_4E7C80 func(a1 *server.Object, a2 int) int
)

// nox_xxx_unitIsUnitTT_4E7C80
func nox_xxx_unitIsUnitTT_4E7C80(a1 *nox_object_t, a2 int32) int32 {
	return int32(Nox_xxx_unitIsUnitTT_4E7C80(asObjectS(a1), int(a2)))
}
func Nox_xxx_unitMove_4E7010(a1 *server.Object, a2 *types.Pointf) {
	nox_xxx_unitMove_4E7010(asObjectC(a1), (*float2)(unsafe.Pointer(a2)))
}
func Nox_xxx_unitSetHP_4E4560(a1 *server.Object, a2 uint16) {
	nox_xxx_unitSetHP_4E4560(asObjectC(a1), uint16(a2))
}
func Nox_xxx_mobInformOwnerHP_4EE4C0(a1 *server.Object) {
	nox_xxx_mobInformOwnerHP_4EE4C0(asObjectC(a1))
}
func Nox_xxx_protectMana_56F9E0(a1 int, a2 int16) {
	nox_xxx_protectMana_56F9E0(int32(a1), int16(a2))
}
func Nox_xxx_monsterWalkTo_514110(a1 *server.Object, a2 float32, a3 float32) {
	nox_xxx_monsterWalkTo_514110(asObjectC(a1), float32(a2), float32(a3))
}
func Nox_xxx_monsterLookAt_5125A0(a1 *server.Object, a2 int) {
	nox_xxx_monsterLookAt_5125A0(asObjectC(a1), int32(a2))
}
func Nox_xxx_unitFreeze_4E79C0(a1 *server.Object, a2 int) {
	nox_xxx_unitFreeze_4E79C0(asObjectC(a1), int32(a2))
}
func Nox_xxx_unitUnFreeze_4E7A60(a1 *server.Object, a2 int) {
	nox_xxx_unitUnFreeze_4E7A60(asObjectC(a1), int32(a2))
}
func Nox_xxx_scriptMonsterRoam_512930(a1 *server.Object) {
	nox_xxx_scriptMonsterRoam_512930(asObjectC(a1))
}
func Nox_server_gotoHome(a1 *server.Object) {
	nox_server_gotoHome(asObjectC(a1))
}
func Nox_xxx_unitIdle_515820(a1 *server.Object) {
	nox_xxx_unitIdle_515820(asObjectC(a1))
}
func Nox_xxx_unitSetFollow_5158C0(a1 *server.Object, a2 *server.Object) {
	nox_xxx_unitSetFollow_5158C0(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_unitHunt_5157A0(a1 *server.Object) {
	nox_xxx_unitHunt_5157A0(asObjectC(a1))
}
func Nox_xxx_playerSubGold_4FA5D0(a1 *server.Object, a2 int) {
	nox_xxx_playerSubGold_4FA5D0(int32(uintptr(a1.CObj())), uint32(a2))
}
func Nox_xxx_playerAddGold_4FA590(a1 *server.Object, a2 int) {
	nox_xxx_playerAddGold_4FA590(int32(uintptr(a1.CObj())), int32(a2))
}
func Nox_xxx_playerSetState_4FA020(a1 *server.Object, a2 int) {
	nox_xxx_playerSetState_4FA020(asObjectC(a1), int32(a2))
}
