package legacy

import "C"
import "github.com/noxworld-dev/opennox/v1/client/gui"

//export nox_client_setCursorType_477610
func nox_client_setCursorType_477610(v int) int {
	GetClient().Nox_client_setCursorType(gui.Cursor(v))
	return v
}

//export nox_xxx_cursorGetTypePrev_477630
func nox_xxx_cursorGetTypePrev_477630() int {
	return int(GetClient().Cli().CursorPrev)
}
