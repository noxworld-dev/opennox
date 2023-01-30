package legacy

/*
#include "client__gui__window.h"
#include "client__gui__guicon.h"
void nox_xxx_consoleEsc_49B7A0();
unsigned int nox_gui_xxx_check_446360();
*/
import "C"
import "github.com/noxworld-dev/opennox-lib/console"

var (
	GetConsole                     func() *console.Console
	Nox_gui_console_flagXxx_451410 func() int
	Nox_gui_console_Hide_4512B0    func() int
)

//export nox_gui_console_flagXxx_451410
func nox_gui_console_flagXxx_451410() int { return Nox_gui_console_flagXxx_451410() }

//export nox_gui_console_Print_450B90
func nox_gui_console_Print_450B90(cl C.uchar, cstr *C.wchar_t) int {
	// since legacy code still calls it, we redirect into global printer instead of GUI printer
	GetConsole().Print(console.Color(cl), GoWString(cstr))
	return 1
}

//export nox_gui_console_PrintOrError_450C30
func nox_gui_console_PrintOrError_450C30(cl C.uchar, cstr *C.wchar_t) {
	GetConsole().PrintOrError(console.Color(cl), GoWString(cstr))
}

//export nox_gui_console_Hide_4512B0
func nox_gui_console_Hide_4512B0() int { return Nox_gui_console_Hide_4512B0() }

func Nox_xxx_consoleEsc_49B7A0() {
	C.nox_xxx_consoleEsc_49B7A0()
}
