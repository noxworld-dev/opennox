package nox

/*
#include "client__gui__window.h"
extern nox_window* nox_gui_console_scrollbox;
*/
import "C"
import (
	"fmt"

	"nox/v1/common/console"
)

var (
	guiCon = new(guiConsolePrinter)
)

func init() {
	consoleMux.Add(guiCon)
}

type guiConsolePrinter struct {
	enabled bool
}

func (p guiConsolePrinter) Print(cl console.Color, str string) {
	if p.enabled && C.nox_gui_console_scrollbox != nil {
		asWindow(C.nox_gui_console_scrollbox).Func94(&WindowEvent0x400d{Str: str, Val: int(cl)})
	}
}

func (p guiConsolePrinter) Printf(cl console.Color, format string, args ...interface{}) {
	str := fmt.Sprintf(format, args...)
	p.Print(cl, str)
}

//export nox_gui_console_Enable_450BE0
func nox_gui_console_Enable_450BE0() {
	guiCon.enabled = true
}

//export nox_gui_console_Disable_450BF0
func nox_gui_console_Disable_450BF0() {
	guiCon.enabled = false
}

//export nox_gui_console_Print_450B90
func nox_gui_console_Print_450B90(cl C.uchar, cstr *C.wchar_t) C.int {
	// since legacy code still calls it, we redirect into global printer instead of GUI printer
	noxConsole.Print(console.Color(cl), GoWString(cstr))
	return 1
}

//export nox_gui_console_PrintOrError_450C30
func nox_gui_console_PrintOrError_450C30(cl C.uchar, cstr *C.wchar_t) {
	if cstr != nil {
		nox_gui_console_Print_450B90(cl, cstr)
		return
	}
	str := noxConsole.Strings().GetStringInFile("InternalError", "C:\\NoxPost\\src\\Client\\Gui\\guicon.c")
	if str != "" {
		noxConsole.Print(console.Color(cl), str)
	}
}
