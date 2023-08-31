package legacy

import (
	"unsafe"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_56F980(a1 int32, a2 uint8) {
	if uint32(a1) < 657757279 {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	dword_5d4594_2516328 ^= p.Field4
	v3 := int32(dword_5d4594_2516348 ^ (uint32(a2) + (dword_5d4594_2516348 ^ p.Field4)))
	p.Field4 = uint32(v3)
	dword_5d4594_2516328 ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}
func sub_4EF2E0_exp_level(a1 unsafe.Pointer) {
	var (
		v1 int32
		v2 *wchar2_t
	)
	v1 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 276)))
	if (nox_xxx_gameGet_4DB1B0() != 1 || sub_4DB1C0() == nil) && nox_xxx_gamedataGetFloatTable_419D70(internCStr("XPTable"), int32(*(*byte)(unsafe.Add(v1, 3684))+1)) <= float64(*(*float32)(unsafe.Add(a1, 28))) {
		*(*uint8)(unsafe.Add(v1, 3684))++
		sub_56F980(int32(*(*uint32)(unsafe.Add(v1, 4644))), 1)
		nox_xxx_plrReadVals_4EEDC0((*server.Object)(a1), 1)
		if noxflags.HasGame(2048) {
			sub_57AF30((*server.Object)(a1), 0)
		} else {
			nox_xxx_aud_501960(902, (*server.Object)(a1), 2, int32(*(*uint32)(unsafe.Add(a1, 36))))
			v2 = nox_strman_loadString_40F1D0(internCStr("LevelUP"), nil, internCStr("C:\\NoxPost\\src\\Server\\GameMech\\explevel.c"), 253)
			nox_xxx_netSendLineMessage_4D9EB0((*server.Object)(a1), v2)
		}
	}
}
func nox_xxx_plyrGiveExp_4EF3A0_exp_level(a1 unsafe.Pointer, a2 float32) {
	var (
		v2 int32
		v3 *wchar2_t
	)
	v2 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	*(*float32)(unsafe.Add(a1, 28)) = a2 + *(*float32)(unsafe.Add(a1, 28))
	sub_56FA40(int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 4604))), a2)
	sub_4D81A0((*server.Object)(a1))
	v3 = nox_strman_loadString_40F1D0(internCStr("health.c:gainpoints"), nil, internCStr("C:\\NoxPost\\src\\Server\\GameMech\\explevel.c"), 381)
	nox_xxx_netSendLineMessage_4D9EB0((*server.Object)(a1), v3, uint32(int32(int64(a2))))
	sub_4EF2E0_exp_level(a1)
}
