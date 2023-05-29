package legacy

import (
	"github.com/noxworld-dev/opennox/v1/server"
)

func Nox_xxx_getObjectByScrName_4DA4F0(name string) *server.Object {
	cstr := CString(name)
	defer StrFree(cstr)
	return asObjectS(nox_xxx_getObjectByScrName_4DA4F0(cstr))
}
func Nox_server_scriptMoveTo_5123C0(a1 *server.Object, a2 *server.Waypoint) {
	nox_server_scriptMoveTo_5123C0(int(uintptr(a1.CObj())), int(uintptr(a2.C())))
}
func Nox_xxx_playerCanCarryItem_513B00(a1 *server.Object, a2 *server.Object) {
	nox_xxx_playerCanCarryItem_513B00(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_inventoryServPlace_4F36F0(a1 *server.Object, a2 *server.Object, a3 int, a4 int) int {
	return int(nox_xxx_inventoryServPlace_4F36F0(asObjectC(a1), asObjectC(a2), int(a3), int(a4)))
}
func Sub_516D00(a1 *server.Object) {
	sub_516D00(asObjectC(a1))
}
func Nox_xxx_netSendChat_528AC0(a1 *server.Object, a2 string, a3 uint16) {
	nox_xxx_netSendChat_528AC0(asObjectC(a1), internWStr(a2), uint16(a3))
}
func Nox_xxx_playDialogFile_44D900(a1 string, a2 int) {
	nox_xxx_playDialogFile_44D900(internCStr(a1), int(a2))
}
