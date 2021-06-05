package main

/*
#include "proto.h"
*/
import "C"
import "nox/v1/common/strman"

func (win *Window) NewDialogID(id strman.ID, file string) {
	str := strMan.GetStringInFile(id, file)
	C.nox_xxx_dialogMsgBoxCreate_449A10(win.C(), 0, internWStr(str), 0, nil, nil)
}
