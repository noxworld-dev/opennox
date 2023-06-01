package legacy

import "github.com/noxworld-dev/opennox-lib/console"

var (
	GetConsole                     func() *console.Console
	Nox_gui_console_flagXxx_451410 func() int
	Nox_gui_console_Hide_4512B0    func() int
)

// nox_gui_console_flagXxx_451410
func nox_gui_console_flagXxx_451410() int { return Nox_gui_console_flagXxx_451410() }

// nox_gui_console_Print_450B90
func nox_gui_console_Print_450B90(cl byte, cstr *wchar2_t) int {
	// since legacy code still calls it, we redirect into global printer instead of GUI printer
	GetConsole().Print(console.Color(cl), GoWString(cstr))
	return 1
}

// nox_gui_console_PrintOrError_450C30
func nox_gui_console_PrintOrError_450C30(cl byte, cstr *wchar2_t) {
	GetConsole().PrintOrError(console.Color(cl), GoWString(cstr))
}

// nox_gui_console_Hide_4512B0
func nox_gui_console_Hide_4512B0() int { return Nox_gui_console_Hide_4512B0() }

func Nox_xxx_consoleEsc_49B7A0() {
	nox_xxx_consoleEsc_49B7A0()
}
