package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

func Sub_4BDFD0() {
	sub_4BDFD0()
}
func Mix_MouseKeyboardWeaponRoll(a1 *server.Object, a2 int8) int {
	return int(mix_MouseKeyboardWeaponRoll(asObjectC(a1), a2))
}
func PlayerInfoStructParser_0(a1 unsafe.Pointer) int {
	return int(playerInfoStructParser_0(a1))
}
func PlayerInfoStructParser_1(a1 unsafe.Pointer, a2 *int32) int {
	return int(playerInfoStructParser_1(a1, a2))
}
func PlayerDropATrap(a1 *server.Object) {
	playerDropATrap(a1.CObj())
}
func GetFlagValueFromFlagIndex(a1 int) uint32 {
	return uint32(getFlagValueFromFlagIndex(int32(a1)))
}
