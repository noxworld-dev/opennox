package legacy

/*
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_3.h"
#include "GAME5_2.h"
#include "server__script__builtin.h"
void nox_server_gotoHome(nox_object_t* obj);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_unitIsUnitTT_4E7C80 func(a1 *server.Object, a2 int) int
)

//export nox_xxx_unitIsUnitTT_4E7C80
func nox_xxx_unitIsUnitTT_4E7C80(a1 *nox_object_t, a2 int) int {
	return Nox_xxx_unitIsUnitTT_4E7C80(asObjectS(a1), a2)
}
func Nox_xxx_unitMove_4E7010(a1 *server.Object, a2 *types.Pointf) {
	C.nox_xxx_unitMove_4E7010(asObjectC(a1), (*C.float2)(unsafe.Pointer(a2)))
}
func Nox_xxx_unitSetHP_4E4560(a1 *server.Object, a2 uint16) {
	C.nox_xxx_unitSetHP_4E4560(asObjectC(a1), C.ushort(a2))
}
func Nox_xxx_mobInformOwnerHP_4EE4C0(a1 *server.Object) {
	C.nox_xxx_mobInformOwnerHP_4EE4C0(asObjectC(a1))
}
func Nox_xxx_protectMana_56F9E0(a1 int, a2 int16) {
	C.nox_xxx_protectMana_56F9E0(C.int(a1), C.short(a2))
}
func Nox_xxx_monsterWalkTo_514110(a1 *server.Object, a2 float32, a3 float32) {
	C.nox_xxx_monsterWalkTo_514110(asObjectC(a1), C.float(a2), C.float(a3))
}
func Nox_xxx_monsterLookAt_5125A0(a1 *server.Object, a2 int) {
	C.nox_xxx_monsterLookAt_5125A0(asObjectC(a1), C.int(a2))
}
func Nox_xxx_unitFreeze_4E79C0(a1 *server.Object, a2 int) {
	C.nox_xxx_unitFreeze_4E79C0(asObjectC(a1), C.int(a2))
}
func Nox_xxx_unitUnFreeze_4E7A60(a1 *server.Object, a2 int) {
	C.nox_xxx_unitUnFreeze_4E7A60(asObjectC(a1), C.int(a2))
}
func Nox_xxx_scriptMonsterRoam_512930(a1 *server.Object) {
	C.nox_xxx_scriptMonsterRoam_512930(asObjectC(a1))
}
func Nox_server_gotoHome(a1 *server.Object) {
	C.nox_server_gotoHome(asObjectC(a1))
}
func Nox_xxx_unitIdle_515820(a1 *server.Object) {
	C.nox_xxx_unitIdle_515820(asObjectC(a1))
}
func Nox_xxx_unitSetFollow_5158C0(a1 *server.Object, a2 *server.Object) {
	C.nox_xxx_unitSetFollow_5158C0(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_unitHunt_5157A0(a1 *server.Object) {
	C.nox_xxx_unitHunt_5157A0(asObjectC(a1))
}
func Nox_xxx_playerSubGold_4FA5D0(a1 *server.Object, a2 int) {
	C.nox_xxx_playerSubGold_4FA5D0(C.int(uintptr(a1.CObj())), C.uint(a2))
}
func Nox_xxx_playerAddGold_4FA590(a1 *server.Object, a2 int) {
	C.nox_xxx_playerAddGold_4FA590(C.int(uintptr(a1.CObj())), C.int(a2))
}
func Nox_xxx_playerSetState_4FA020(a1 *server.Object, a2 int) {
	C.nox_xxx_playerSetState_4FA020(asObjectC(a1), C.int(a2))
}
