package legacy

/*
#include "defs.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2_2.h"
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

var (
	Sub_44A4A0                        func() int
	Nox_xxx_dialogMsgBoxCreate_449A10 func(win *gui.Window, title, text string, a4 gui.DialogFlags, a5, a6 func())
	Sub_449E00                        func(a1 string) int
	Sub_449E30                        func(a1 string) int
	Sub_449E60                        func(a1 int8) int
	Sub_449EA0                        func(a1 gui.DialogFlags)
	Sub_44A4E0                        func() int
	Sub_44A4B0                        func()
	Sub_44A360                        func(a1 int)
)

//export sub_44A4A0
func sub_44A4A0() int { return Sub_44A4A0() }

//export nox_xxx_dialogMsgBoxCreate_449A10
func nox_xxx_dialogMsgBoxCreate_449A10(win *nox_window, title, text *C.wchar_t, a4 int, a5, a6 unsafe.Pointer) unsafe.Pointer {
	var fnc5, fnc6 func()
	if a5 != nil {
		fnc5 = func() {
			ccall.CallVoidVoid(a5)
		}
	}
	if a6 != nil {
		fnc6 = func() {
			ccall.CallVoidVoid(a6)
		}
	}
	Nox_xxx_dialogMsgBoxCreate_449A10(asWindow(win), GoWString(title), GoWString(text), gui.DialogFlags(a4), fnc5, fnc6)
	return nil
}

//export sub_449E00
func sub_449E00(a1 *wchar_t) int { return Sub_449E00(GoWString(a1)) }

//export sub_449E30
func sub_449E30(a1 *wchar_t) int { return Sub_449E30(GoWString(a1)) }

//export sub_449E60
func sub_449E60(a1 C.char) int { return Sub_449E60(int8(a1)) }

//export sub_449EA0
func sub_449EA0(a1 int) { Sub_449EA0(gui.DialogFlags(a1)) }

//export sub_44A4E0
func sub_44A4E0() int { return Sub_44A4E0() }

//export sub_44A4B0
func sub_44A4B0() { Sub_44A4B0() }

//export sub_44A360
func sub_44A360(a1 int) { Sub_44A360(a1) }

func Sub_41DA70(a1, a2 int) {
	C.sub_41DA70(C.int(a1), C.short(a2))
}
