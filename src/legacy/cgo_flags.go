package legacy

import (
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_moveUpdateSpecial_517970 func(obj *server.Object)
)

// nox_xxx_setGameFlags_40A4D0
func nox_xxx_setGameFlags_40A4D0(f uint32) {
	noxflags.SetGame(noxflags.GameFlag(f))
}

// nox_common_gameFlags_unset_40A540
func nox_common_gameFlags_unset_40A540(f uint) {
	noxflags.UnsetGame(noxflags.GameFlag(f))
}

// nox_common_gameFlags_getVal_40A5B0
func nox_common_gameFlags_getVal_40A5B0() uint32 {
	return uint32(noxflags.GetGame())
}

// nox_xxx_GetGameplayFlags_417D90
func nox_xxx_GetGameplayFlags_417D90() int {
	return int(noxflags.GetGamePlay())
}

// nox_xxx_CheckGameplayFlags_417DA0
func nox_xxx_CheckGameplayFlags_417DA0(v int32) bool {
	return noxflags.HasGamePlay(uint32(v))
}

// nox_xxx_SetGameplayFlag_417D50
func nox_xxx_SetGameplayFlag_417D50(v int32) {
	noxflags.SetGamePlay(uint32(v))
}

// nox_xxx_UnsetGameplayFlags_417D70
func nox_xxx_UnsetGameplayFlags_417D70(v int32) {
	noxflags.UnsetGamePlay(uint32(v))
}

// nox_xxx_moveUpdateSpecial_517970
func nox_xxx_moveUpdateSpecial_517970(cunit *server.Object) {
	Nox_xxx_moveUpdateSpecial_517970(asObjectS(cunit))
}
