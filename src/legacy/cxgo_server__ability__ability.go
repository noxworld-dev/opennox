package legacy

import (
	"unsafe"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_netAbilityReport_4D8060(a1 int32, a2 int32, a3 int32) int32 {
	var (
		result int32
		v4     int32
	)
	result = a1
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 8)))&4 != 0 {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 748)))
		*((*uint8)(unsafe.Pointer(&a1))) = 205
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a1), 1)) = uint8(int8(a2))
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a1), 2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v4)), 276))+uint32(a2*4))), 3696))
		if a3 != 0 {
			*(*uint8)(unsafe.Add(unsafe.Pointer(&a1), 2)) |= 0x80
		}
		result = nox_xxx_netSendPacket1_4E5390(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v4)), 276)))), 2064))), unsafe.Pointer(&a1), 3, nil, 1)
	}
	return result
}
func nox_xxx_abilGetSuccess_4FB960_ability(a1 int32) {
	var v1 *wchar2_t
	v1 = nox_strman_loadString_40F1D0(*(**byte)(memmap.PtrOff(0x587000, uintptr(a1*4)+217092)), nil, internCStr("C:\\NoxPost\\src\\Server\\Ability\\Ability.c"), 75)
	nox_xxx_printCentered_445490(v1)
}
func nox_xxx_abilityRewardServ_4FB9C0_ability(a1 int32, a2 int32, a3 int32) int32 {
	var (
		v3 int32
		v4 int32
		v5 int32
		v6 *uint32
	)
	_ = v6
	var v7 *uint32
	var i int32
	var result int32
	var v10 *wchar2_t
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 8))) & 4) == 0 {
		return 0
	}
	if a2 <= 0 || a2 >= 6 {
		v10 = nox_strman_loadString_40F1D0(internCStr("AwardAbilityError"), nil, internCStr("C:\\NoxPost\\src\\Server\\Ability\\Ability.c"), 108)
		nox_xxx_netSendLineMessage_4D9EB0((*server.Object)(unsafe.Pointer(uintptr(a1))), v10)
		return 0
	}
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 748)))
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v3)), 276)))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v4+a2*4)), 3696)))
	v6 = (*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v4+a2*4)), 3696))
	if v5 != 0 {
		nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(unsafe.Pointer(uintptr(a1))), internCStr("use.c:HadAbility"), 0)
		result = 0
	} else {
		*v6 = 5
		v7 = (*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v3)), 276))+uint32(a2*4))), 3696))
		if *v7 > 5 {
			*v7 = 5
		}
		nox_xxx_playerAwardSpellProtectionCRC_56FCE0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v3)), 276)))), 4636))), a2, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v3)), 276))+uint32(a2*4))), 3696))))
		nox_xxx_netAbilityReport_4D8060(a1, a2, a3)
		if noxflags.HasGame(4096) {
			nox_xxx_netSendRewardNotify_4FAD50(a1, 2, a1, int8(a2))
			if sub_419E60((*server.Object)(unsafe.Pointer(uintptr(a1)))) == 0 {
				for i = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(uintptr(i))))))) {
					if i != a1 {
						nox_xxx_netSendRewardNotify_4FAD50(i, 2, a1, int8(a2))
					}
				}
			}
		}
		result = 1
	}
	return result
}
