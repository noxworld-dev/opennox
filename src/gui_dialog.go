package main

/*
#include "cdrom.h"
#include "client__drawable__drawdb.h"
#include "client__draw__fx.h"
#include "client__draw__image.h"
#include "client__gui__guiinv.h"
#include "client__gui__guimeter.h"
#include "client__gui__guishop.h"
#include "client__gui__guispell.h"
#include "client__gui__servopts__guiserv.h"
#include "client__gui__window.h"
#include "client__io__win95__focus.h"
#include "client__network__netclint.h"
#include "client__shell__optsback.h"
#include "client__system__ctrlevnt.h"
#include "client__video__draw_common.h"
#include "client__video__sdl__draw_nogl.h"
#include "common__config.h"
#include "common__magic__speltree.h"
#include "defs.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME2.h"
#include "GAME3_3.h"
#include "GAME3.h"
#include "GAME4_1.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "input_common.h"
#include "input.h"
#include "movie.h"
#include "server__network__mapsend.h"
#include "server__script__builtin.h"
#include "server__script__script.h"
#include "server__xfer__savegame__savegame.h"
#include "thing.h"
#include "win.h"
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
