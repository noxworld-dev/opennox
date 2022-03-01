package nox

import "C"
import "nox/v1/client/gui"

var (
	nox_client_mouseCursorType           = gui.CursorSelect
	nox_xxx_cursorTypePrev_587000_151528 = gui.Cursor17
)

func nox_client_setCursorType(v gui.Cursor) {
	nox_client_mouseCursorType = v
}

func nox_client_getCursorType() gui.Cursor {
	return nox_client_mouseCursorType
}

//export nox_client_setCursorType_477610
func nox_client_setCursorType_477610(v C.int) C.int {
	nox_client_setCursorType(gui.Cursor(v))
	return v
}

//export nox_client_getCursorType_477620
func nox_client_getCursorType_477620() C.int {
	return C.int(nox_client_getCursorType())
}

//export nox_xxx_cursorGetTypePrev_477630
func nox_xxx_cursorGetTypePrev_477630() C.int {
	return C.int(nox_xxx_cursorTypePrev_587000_151528)
}
