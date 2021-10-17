package nox

/*
#include <stdbool.h>
*/
import "C"

import noxflags "nox/v1/common/flags"

//export nox_xxx_setGameFlags_40A4D0
func nox_xxx_setGameFlags_40A4D0(f C.uint) {
	noxflags.SetGame(noxflags.GameFlag(f))
}

//export nox_common_gameFlags_unset_40A540
func nox_common_gameFlags_unset_40A540(f C.uint) {
	noxflags.UnsetGame(noxflags.GameFlag(f))
}

//export nox_common_gameFlags_getVal_40A5B0
func nox_common_gameFlags_getVal_40A5B0() C.uint {
	return C.uint(noxflags.GetGame())
}

//export nox_common_gameFlags_check_40A5C0
func nox_common_gameFlags_check_40A5C0(f C.uint) C.bool {
	return C.bool(noxflags.HasGame(noxflags.GameFlag(f)))
}

func nox_xxx_checkGameFlagPause_413A50() bool {
	return noxflags.HasGame(noxflags.GamePause)
}
