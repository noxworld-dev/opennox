package legacy

import (
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

var gameex_flags uint32 = 0x1E

func nox_CharToOemW(pSrc *wchar2_t, pDst *byte) int32 {
	return nox_sprintf(pDst, internCStr("%S"), pSrc)
}
func getPlayerClassFromObjPtr(a1 unsafe.Pointer) int8 {
	return int8(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 276)), 2251)))
}
func playerInfoStructParser_0(a1p unsafe.Pointer) int8 {
	var (
		a1   *byte = (*byte)(a1p)
		v1   *byte
		pDst int8
	)
	if uintptr(unsafe.Pointer(a1)) == uintptr(4294967294) {
		return 0
	}
	v1 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
	if v1 == nil {
		return 0
	}
	for {
		nox_CharToOemW((*wchar2_t)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(wchar2_t(0))*2352)), (*byte)(unsafe.Pointer(&pDst)))
		if libc.StrCmp((*byte)(unsafe.Pointer(&pDst)), (*byte)(unsafe.Add(unsafe.Pointer(a1), 2))) == 0 {
			break
		}
		v1 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(v1)))))
		if v1 == nil {
			return 0
		}
	}
	*(*byte)(unsafe.Add(unsafe.Pointer(a1), 1)) = *((*uint8)(unsafe.Add(unsafe.Pointer(nox_xxx_objGetTeamByNetCode_418C80(*((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*515))))), 4)))
	*a1 = *(*byte)(unsafe.Add(unsafe.Pointer(v1), 2251))
	return 1
}
func playerInfoStructParser_1(a1p unsafe.Pointer, a3 *int32) int8 {
	var (
		a1   int32 = int32(uintptr(a1p))
		v3   *byte
		v4   *byte
		v6   *uint32
		pDst int8
	)
	if a1 == -2 {
		return 0
	}
	v3 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
	var a2 int32 = int32(uintptr(unsafe.Pointer(v3)))
	if v3 == nil {
		return 0
	}
	for {
		nox_CharToOemW((*wchar2_t)(unsafe.Add(a2, 4704)), (*byte)(unsafe.Pointer(&pDst)))
		if libc.StrCmp((*byte)(unsafe.Pointer(&pDst)), (*byte)(unsafe.Add(a1, 2))) == 0 {
			break
		}
		v4 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(a2))))
		a2 = int32(uintptr(unsafe.Pointer(v4)))
		if v4 == nil {
			return 0
		}
	}
	v6 = nox_xxx_objGetTeamByNetCode_418C80(int32(*(*uint32)(unsafe.Add(a2, 2060))))
	*a3 = int32(uintptr(unsafe.Pointer(v6)))
	*(*uint8)(unsafe.Add(a1, 1)) = *((*uint8)(unsafe.Add(unsafe.Pointer(v6), 4)))
	*(*uint8)(a1) = *(*uint8)(unsafe.Add(a2, 2251))
	return 1
}
func mix_MouseKeyboardWeaponRoll(playerObjP *server.Object, a2 int8) int8 {
	var (
		playerObj int32 = int32(uintptr(unsafe.Pointer(playerObjP)))
		v2        int32
		v4        int32
		i         int32
		v6        int32
		v8        int32
		weapFlags int32
		v11       int32
		v16       int8
	)
	v16 = 0
	v2 = int32(*(*uint32)(unsafe.Add(playerObj, 748)))
	if !((int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 3680)))&3) == 0 && int32(*(*uint8)(unsafe.Add(v2, 88))) != 1) {
		return v16
	}
	var cur int32 = int32(*(*uint32)(unsafe.Add(v2, 104)))
	v4 = 496
	if int32(a2) == 0 {
		v4 = 500
	}
	if cur != 0 {
		var next int32 = cur
		for {
			next = int32(*(*uint32)(unsafe.Pointer(uintptr(next + v4))))
			if next == 0 {
				break
			}
			weapFlags = nox_xxx_weaponInventoryEquipFlags_415820((*server.Object)(next))
			if weapFlags != 0 && weapFlags != 2 {
				if nox_xxx_playerClassCanUseItem_57B3D0((*server.Object)(next), int8(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(playerObj, 748)), 276)), 2251)))) != 0 {
					v11 = bool2int32(nox_xxx_playerCheckStrength_4F3180((*server.Object)(playerObj), (*server.Object)(next)))
					if v11 != 0 {
						if nox_xxx_playerTryDequip_4F2FB0((*uint32)(playerObj), (*server.Object)(cur)) != 0 && nox_xxx_playerTryEquip_4F2F70((*server.Object)(playerObj), (*server.Object)(next)) != 0 {
							v16 = 1
						}
						return v16
					}
				}
			}
		}
	} else {
		for i = int32(*(*uint32)(unsafe.Add(playerObj, 504))); i != 0; i = int32(*(*uint32)(unsafe.Add(i, 496))) {
			v6 = nox_xxx_weaponInventoryEquipFlags_415820((*server.Object)(i))
			if v6 != 0 && v6 != 2 {
				if nox_xxx_playerClassCanUseItem_57B3D0((*server.Object)(i), int8(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(playerObj, 0x2EC)), 0x114)), 0x8CB)))) != 0 {
					v8 = bool2int32(nox_xxx_playerCheckStrength_4F3180((*server.Object)(playerObj), (*server.Object)(i)))
					if v8 != 0 {
						if nox_xxx_playerTryEquip_4F2F70((*server.Object)(playerObj), (*server.Object)(i)) != 0 {
							v16 = 1
						}
						return v16
					}
				}
			}
		}
	}
	return v16
}
func playerDropATrap(playerObj unsafe.Pointer) int8 {
	var (
		v2  int32
		v7  int8
		v8  int8
		pos [2]float32
	)
	v7 = 17
	if playerObj == nil {
		return 0
	}
	v8 = 0
	v2 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(playerObj, 0x2EC)), 0x114)))
	pos[0] = *(*float32)(unsafe.Add(v2, 0xE30))
	pos[1] = *(*float32)(unsafe.Add(v2, 0xE34))
	if !((int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(playerObj, 0x2EC)), 0x114)), 0xE60)))&3) == 0 && int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(playerObj, 0x2EC)), 0x58))) != 1) {
		return v8
	}
	for i := *(*unsafe.Pointer)(unsafe.Add(playerObj, 0x1F8)); i != nil; i = *(*unsafe.Pointer)(unsafe.Add(i, 0x1F0)) {
		if int32(*(*uint8)(unsafe.Add(i, 0xA))) == int32(v7) {
			nox_xxx_drop_4ED810(playerObj, i, &pos[0])
			return 1
		}
	}
	return v8
}
func OnLibraryNotice_420(arg1 unsafe.Pointer, arg2 uint32, arg3 unsafe.Pointer, arg4 uint32) {
	var (
		v23         = arg1
		v19 int32   = int32(arg2)
		v16 *uint32 = (*uint32)(unsafe.Pointer(uintptr(getPlayerClassFromObjPtr(arg1))))
	)
	if int32(*(*uint8)(unsafe.Add(v19, 0xA))) != 17 {
		nox_xxx_inventoryServPlace_4F36F0((*server.Object)(v23), (*server.Object)(v19), 1, 1)
		return
	}
	var v17 int8 = int8(*(*uint8)(unsafe.Add(v19, 4)))
	if int32(v17) != 0x6A {
		if (int32(v17) == 0x6B || int32(v17) == 0x6D) && int32(uint8(uintptr(unsafe.Pointer(v16)))) != 0 {
			goto ifIsWarrior
		}
		nox_xxx_inventoryServPlace_4F36F0((*server.Object)(v23), (*server.Object)(v19), 1, 1)
		return
	}
	if int32(uint8(uintptr(unsafe.Pointer(v16)))) == 1 {
		nox_xxx_inventoryServPlace_4F36F0((*server.Object)(v23), (*server.Object)(v19), 1, 1)
		return
	}
ifIsWarrior:
	nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(v23), (*byte)(memmap.PtrOff(0x587000, 215732)), 0)
	nox_xxx_aud_501960(925, (*server.Object)(v23), 2, int32(*(*uint32)(unsafe.Add(v23, 36))))
}
func getFlagValueFromFlagIndex(a1 int32) int32 {
	var (
		v1     int32
		v2     uint32
		v3     int32
		result int32
	)
	v1 = 2
	v2 = uint32(a1)
	if a1 < 0 {
		v2 = uint32(-a1)
	}
	v3 = 1
	for {
		if v2&1 != 0 {
			v3 *= v1
		}
		v2 >>= 1
		if v2 == 0 {
			break
		}
		v1 *= v1
	}
	if a1 >= 0 {
		result = v3
	} else {
		result = 1 / v3
	}
	return result
}
