package legacy

import "github.com/noxworld-dev/opennox/v1/client/gui"

// nox_client_setCursorType_477610
func nox_client_setCursorType_477610(v int32) int32 {
	GetClient().Nox_client_setCursorType(gui.Cursor(v))
	return v
}

// nox_xxx_cursorGetTypePrev_477630
func nox_xxx_cursorGetTypePrev_477630() int32 {
	return int32(GetClient().Cli().CursorPrev)
}
