package legacy

import "github.com/noxworld-dev/opennox/v1/server"

func Nox_xxx_serverHandleClientConsole_443E90(a1 *server.Player, a2 byte, cmd string) {
	cstr, free := CWString(cmd)
	defer free()
	nox_xxx_serverHandleClientConsole_443E90(a1, int8(a2), cstr)
}
func Nox_xxx_cmdSayDo_46A4B0(text string, a2 int) {
	cstr, free := CWString(text)
	defer free()
	nox_xxx_cmdSayDo_46A4B0(cstr, int32(a2))
}
