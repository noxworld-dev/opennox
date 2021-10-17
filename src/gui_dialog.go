package nox

/*
#include "GAME1_3.h"
*/
import "C"
import (
	"unsafe"

	"nox/v1/common/strman"
)

func (win *Window) NewDialogID(id strman.ID, file string) {
	str := strMan.GetStringInFile(id, file)
	NewDialogWindow(win, "", str, 0, nil, nil)
}

func NewDialogWindow(par *Window, a2 string, text string, a4 int, a5, a6 unsafe.Pointer) {
	var (
		arg2 *C.wchar_t
	)
	if a2 != "" {
		arg2 = internWStr(a2)
	}
	C.nox_xxx_dialogMsgBoxCreate_449A10(par.C(), arg2, internWStr(text), C.int(a4), (*[0]byte)(a5), (*[0]byte)(a6))
}
