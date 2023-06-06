package legacy

import (
	"unsafe"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_netSendSpellAward_4D7F90(a1 int32, a2 int32, a3 int8, a4 int32) int32 {
	var (
		result int32
		v5     int32
	)
	result = a1
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 8)))&4 != 0 {
		v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 748)))
		*((*uint8)(unsafe.Pointer(&a1))) = 111
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a1), 1)) = uint8(int8(a2))
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a1), 2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v5)), 276))+uint32(a2*4))), 3696))
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a1), 4-1)) = uint8(a3)
		if a4 != 0 {
			*(*uint8)(unsafe.Add(unsafe.Pointer(&a1), 4-1)) = uint8(int8(int32(a3) | 0x80))
		}
		result = nox_xxx_netSendPacket1_4E5390(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v5)), 276)))), 2064))), unsafe.Pointer(&a1), 4, 0, 1)
	}
	return result
}
func nox_xxx_abilGetError_4FB0B0_magic_plyrspel(a1 int32) {
	var v1 *wchar2_t
	v1 = nox_strman_loadString_40F1D0(*(**byte)(memmap.PtrOff(0x587000, uintptr(a1*4)+216380)), nil, internCStr("C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c"), 86)
	nox_xxx_printCentered_445490(v1)
}
func nox_xxx_spellGrantToPlayer_4FB550(a1p *server.Object, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var (
		a1  int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v5  int32
		v6  int32
		v7  int32
		v8  *wchar2_t
		v9  *uint32
		v10 int32
		v11 int32
		v12 int32
		v13 *uint32
		v14 int32
		v15 int32
		i   *byte
		v17 int32
		v18 *uint32
	)
	v5 = a1
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 8))) & 4) == 0 {
		return 0
	}
	v6 = a2
	if a2 <= 0 || a2 >= 137 {
		v8 = nox_strman_loadString_40F1D0(internCStr("AwardSpellError"), nil, internCStr("C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c"), 339)
		nox_xxx_netSendLineMessage_4D9EB0((*server.Object)(unsafe.Pointer(uintptr(a1))), v8)
		return 0
	}
	v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 748)))
	if noxflags.HasGame(6144) && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276))+uint32(a2*4))), 3696)) == 3 || *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276))+uint32(a2*4))), 3696)) == 5 {
		v8 = nox_strman_loadString_40F1D0(internCStr("MaxSpellLevel"), nil, internCStr("C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c"), 351)
		nox_xxx_netSendLineMessage_4D9EB0((*server.Object)(unsafe.Pointer(uintptr(a1))), v8)
		return 0
	}
	if noxflags.HasGame(4096) && (a2 == 34 || a2 == 134 || a2 == 45 || a2 == 46 || a2 == 47 || a2 == 48 || a2 == 49 || a2 == 117 || a2 == 118 || a2 == 119 || a2 == 120 || a2 == 121 || a2 == 122 || a2 == 123 || a2 == 124 || a2 == 125 || a2 == 19) && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276))+uint32(a2*4))), 3696)) != 0 {
		v8 = nox_strman_loadString_40F1D0(internCStr("MaxSpellLevel"), nil, internCStr("C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c"), 386)
		nox_xxx_netSendLineMessage_4D9EB0((*server.Object)(unsafe.Pointer(uintptr(a1))), v8)
		return 0
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276))+uint32(a2*4))), 3696))++
	v9 = (*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276))+uint32(a2*4))), 3696))
	if *v9 > 5 {
		*v9 = 5
	}
	if noxflags.HasGame(4096) {
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276)))
		if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v10+a2*4)), 3696)) > 3 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v10+a2*4)), 3696)) = 3
		}
	}
	if a5 != 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276))+uint32(a2*4))), 3696)) = uint32(a5)
	}
	nox_xxx_playerAwardSpellProtectionCRC_56FCE0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276)))), 4636))), a2, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276))+uint32(a2*4))), 3696))))
	var v20 int32 = 0
	if nox_xxx_spellHasFlags_424A50(a2, 4096) {
		v20 = 0x2000
	} else if nox_xxx_spellHasFlags_424A50(a2, 0x4000) {
		v20 = 0x8000
	} else if nox_xxx_spellHasFlags_424A50(a2, 0x10000) {
		v20 = 0x20000
	}
	if v20 != 0 {
		v11 = 1
		v12 = 3700
		for v12 < 4244 {
			if nox_xxx_spellHasFlags_424A50(v11, v20) && nox_xxx_spellIsValid_424B50(v11) {
				if a5 != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(uint32(v12) + *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276))))) = uint32(a5)
				} else {
					*(*uint32)(unsafe.Pointer(uintptr(uint32(v12) + *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276)))))++
				}
				v13 = (*uint32)(unsafe.Pointer(uintptr(uint32(v12) + *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276)))))
				if *v13 > 5 {
					*v13 = 5
				}
				if noxflags.HasGame(4096) {
					v14 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276)))
					if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v14+v6*4)), 3696)) > 3 {
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v14+v6*4)), 3696)) = 3
					}
				}
				nox_xxx_playerAwardSpellProtectionCRC_56FCE0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276)))), 4636))), v6, int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(v12) + *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276)))))))
			}
			v12 += 4
			v11++
		}
		v5 = a1
	}
	if a3 != 0 {
		v15 = 1
		nox_xxx_aud_501960(226, (*server.Object)(unsafe.Pointer(uintptr(v5))), 0, 0)
		if noxflags.HasGame(2048) && (v6 == 34 || nox_xxx_spellHasFlags_424A50(v6, 86016)) {
			v15 = 0
		}
		if !noxflags.HasGame(4096) || *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 276)))), 4792)) != 0 {
			if v15 != 0 {
				nox_xxx_netSendRewardNotify_4FAD50(v5, 0, v5, int8(v6))
				if sub_419E60((*server.Object)(unsafe.Pointer(uintptr(v5)))) == 0 {
					for i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); i != nil; i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(i))))) {
						v17 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*514))))
						if v17 != v5 && v17 != 0 {
							nox_xxx_netSendRewardNotify_4FAD50(v17, 0, v5, int8(v6))
						}
					}
				}
			}
		}
	}
	if noxflags.HasGame(2048) && a3 == 1 && a4 == 1 {
		v18 = *(**uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 280))
		if v18 != nil {
			nox_xxx_shopExit_50F4C0(v18)
		}
	}
	nox_xxx_netSendSpellAward_4D7F90(v5, v6, int8(a3), a4)
	return 1
}
