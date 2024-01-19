package legacy

/*
#include <stdbool.h>
*/
import "C"

import (
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_moveUpdateSpecial_517970 func(obj *server.Object)
)

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

//export nox_xxx_GetGameplayFlags_417D90
func nox_xxx_GetGameplayFlags_417D90() int {
	return int(noxflags.GetGamePlay())
}

//export nox_xxx_CheckGameplayFlags_417DA0
func nox_xxx_CheckGameplayFlags_417DA0(v int) C.bool {
	return C.bool(noxflags.HasGamePlay(noxflags.GameplayFlag(v)))
}

//export nox_xxx_SetGameplayFlag_417D50
func nox_xxx_SetGameplayFlag_417D50(v int) {
	noxflags.SetGamePlay(noxflags.GameplayFlag(v))
}

//export nox_xxx_UnsetGameplayFlags_417D70
func nox_xxx_UnsetGameplayFlags_417D70(v int) {
	noxflags.UnsetGamePlay(noxflags.GameplayFlag(v))
}

//export nox_xxx_moveUpdateSpecial_517970
func nox_xxx_moveUpdateSpecial_517970(cunit *nox_object_t) {
	Nox_xxx_moveUpdateSpecial_517970(asObjectS(cunit))
}
