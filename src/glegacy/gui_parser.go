package legacy

/*
#include "client__gui__window.h"
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	Nox_new_window_from_file func(name string, fnc gui.WindowFunc) *gui.Window
)

//export nox_new_window_from_file
func nox_new_window_from_file(cname *C.char, fnc unsafe.Pointer) *nox_window {
	return (*nox_window)(Nox_new_window_from_file(GoString(cname), gui.WrapFuncC(fnc)).C())
}
