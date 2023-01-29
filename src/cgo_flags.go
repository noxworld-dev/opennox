package opennox

/*
#include <stdbool.h>
*/
import "C"

import noxflags "github.com/noxworld-dev/opennox/v1/common/flags"

var gameplayFlags uint32

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

//export nox_xxx_GetGameplayFlags_417D90
func nox_xxx_GetGameplayFlags_417D90() int {
	return int(gameplayFlags)
}

//export nox_xxx_CheckGameplayFlags_417DA0
func nox_xxx_CheckGameplayFlags_417DA0(v int) C.bool {
	return C.bool(checkGameplayFlags(uint32(v)))
}

func checkGameplayFlags(v uint32) bool {
	return gameplayFlags&v != 0
}

//export nox_xxx_SetGameplayFlag_417D50
func nox_xxx_SetGameplayFlag_417D50(v int) {
	gameplayFlags |= uint32(v)
}

//export nox_xxx_UnsetGameplayFlags_417D70
func nox_xxx_UnsetGameplayFlags_417D70(v int) {
	gameplayFlags &^= uint32(v)
}
