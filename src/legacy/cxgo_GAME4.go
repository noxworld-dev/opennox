package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/gotranspile/cxgo/runtime/stdio"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_file_8 *FILE = nil
var nox_cheat_charmall int32 = 0
var dword_5d4594_1599480 int32
var dword_5d4594_1599476 uint32 = 0
var dword_5d4594_1599540 *UnitListXxx
var dword_5d4594_1599556 *TileXxx
var dword_5d4594_1599548 *WaypointListXxx
var dword_5d4594_1599588 *byte
var dword_5d4594_1599592 *byte

func nox_xxx_XFerSpellReward_4F5F30(a1p *server.Object, data unsafe.Pointer) int {
	a1 := a1p
	var (
		v1     *uint8
		result int32
		v3     uint8
		v4     uint8
		v5     uint8
		v6     uint8
		v7     int32
		v8     uint8
		v9     uint8
		v10    int32
		v11    int8
		v12    int8
		v13    int32
		v14    [128]byte
	)
	v1 = (*uint8)(a1.UseData)
	v13 = int32(a1.Field34)
	v10 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 2)
	if int32(int16(v10)) > 60 {
		return 0
	}
	result = int32(Nox_xxx_mapReadWriteObjData_4F4530(a1, int(int32(int16(v10)))))
	if result == 0 {
		return int(result)
	}
	if int32(int16(v10)) >= 31 {
		if nox_crypt_IsReadOnly() == 1 {
			if int32(int16(v10)) >= 41 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 1)
				if int32(uint8(int8(v7))) >= 0x80 {
					return 0
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v14[0], uint32(uint8(int8(v7))))
				v14[uint8(int8(v7))] = 0
				*v1 = uint8(int8(nox_xxx_spellNameToN_4243F0(&v14[0])))
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 1)
				if int32(uint8(int8(v7))) >= 0x80 {
					return 0
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v14[0], uint32(uint8(int8(v7))))
				v14[uint8(int8(v7))] = 0
				nox_xxx_spellNameToN_4243F0(&v14[0])
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 1)
				if int32(uint8(int8(v7))) >= 0x80 {
					return 0
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v14[0], uint32(uint8(int8(v7))))
				v14[uint8(int8(v7))] = 0
				v5 = uint8(int8(nox_xxx_spellNameToN_4243F0(&v14[0])))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 1)
				if int32(uint8(int8(v7))) >= 0x80 {
					return 0
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v14[0], uint32(uint8(int8(v7))))
				v14[uint8(int8(v7))] = 0
				v6 = uint8(int8(nox_xxx_spellNameToN_4243F0(&v14[0])))
				*v1 = v5
				if int32(v6) != 0 {
					*v1 = v6
				}
			}
			goto LABEL_28
		}
	} else if nox_crypt_IsReadOnly() == 1 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v9, 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v8, 1)
		v3 = v9
		if int32(v9) >= 0x89 {
			v3 = 0
			v9 = 0
		}
		v4 = v8
		if int32(v8) >= 0x89 {
			v4 = 0
			v8 = 0
		}
		*v1 = v3
		if int32(v4) != 0 {
			*v1 = v4
		}
		if int32(uint16(int16(v10))) == 10 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 1)
		}
		goto LABEL_28
	}
	libc.StrCpy(&v14[0], nox_xxx_spellNameByN_424870(int32(*v1)))
	*(*uint8)(unsafe.Pointer(&v7)) = uint8(int8(libc.StrLen(&v14[0])))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v14[0], uint32(uint8(int8(v7))))
LABEL_28:
	if a1.Field34 == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
		result = Nox_xxx_xfer_4F3E30(uint16(int16(v10)), a1, a1.Field34)
		return result
	}()) != 0 {
		a1.Field34 = uint32(v13)
		result = 1
	}
	return int(result)
}
func Nox_xxx_XFerAbilityReward_4F6240(a1p *server.Object, data unsafe.Pointer) int {
	a1 := a1p
	var (
		v1     *uint8
		result int32
		v3     int32
		v4     int32
		v5     int32
		v6     [128]byte
	)
	v1 = (*uint8)(a1.UseData)
	v5 = int32(a1.Field34)
	v4 = 61
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 2)
	if int32(int16(v4)) > 61 {
		return 0
	}
	result = int32(Nox_xxx_mapReadWriteObjData_4F4530(a1, int(int32(int16(v4)))))
	if result == 0 {
		return int(result)
	}
	libc.StrCpy(&v6[0], nox_xxx_abilityGetName_425250(int32(*v1)))
	*(*uint8)(unsafe.Pointer(&v3)) = uint8(int8(libc.StrLen(&v6[0])))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3)), 1)
	if int32(uint8(int8(v3))) < 0x80 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v6[0], uint32(uint8(int8(v3))))
		v6[uint8(int8(v3))] = 0
		*v1 = uint8(int8(nox_xxx_abilityNameToN_424D80(&v6[0])))
		if a1.Field34 == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
			result = Nox_xxx_xfer_4F3E30(uint16(int16(v4)), a1, a1.Field34)
			return result
		}()) != 0 {
			a1.Field34 = uint32(v5)
			result = 1
		}
	} else {
		result = 0
	}
	return int(result)
}
func Nox_xxx_XFerFieldGuide_4F6390(a1p *server.Object, data unsafe.Pointer) int {
	var (
		v2     *byte
		v3     int32
		result int32
		v5     int32
	)
	v1 := a1p
	v2 = (*byte)(a1p.UseData)
	v3 = int32(a1p.Field34)
	v5 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 2)
	if int32(int16(v5)) > 60 {
		return 0
	}
	result = int32(Nox_xxx_mapReadWriteObjData_4F4530(v1, int(int32(int16(v5)))))
	if result == 0 {
		return int(result)
	}
	if nox_crypt_IsReadOnly() != 0 {
		var a1 int32
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
		if a1 >= 0x40 {
			return 0
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v2, uint32(uint8(a1)))
		*(*byte)(unsafe.Add(unsafe.Pointer(v2), uint8(a1))) = 0
	} else {
		var a1 int32
		*(*uint8)(unsafe.Pointer(&a1)) = uint8(int8(libc.StrLen(v2)))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v2, uint32(uint8(a1)))
	}
	if v1.Field34 == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
		result = Nox_xxx_xfer_4F3E30(uint16(int16(v5)), v1, v1.Field34)
		return result
	}()) != 0 {
		v1.Field34 = uint32(v3)
		return 1
	}
	return int(result)
}
func nox_xxx_XFerWeapon_4F64A0(a1p *server.Object, data unsafe.Pointer) int {
	a1 := a1p
	var (
		result int32
		v2     ***byte
		v3     int32
		v4     int32
		v5     *byte
		v6     int32
		v7     int32
		v9     uint8
		v10    int32
		v11    int32
		v12    uint32
		v14    uint8
		v15    uint8
		v16    int32
		v17    int32
		v18    int32
		v19    int32
		v20    [20]byte
		v21    [256]byte
	)
	v19 = int32(a1.Field34)
	v17 = 64
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v17)), 2)
	if int32(int16(v17)) > 64 {
		return 0
	}
	result = int32(Nox_xxx_mapReadWriteObjData_4F4530(a1, int(int32(int16(v17)))))
	if result == 0 {
		return 0
	}
	if int32(int16(v17)) < 11 && nox_crypt_IsReadOnly() == 1 {
		*(*uint32)(unsafe.Pointer(&v20[0])) = 0
		*(*uint32)(unsafe.Pointer(&v20[4])) = 0
		*(*uint32)(unsafe.Pointer(&v20[8])) = 0
		*(*uint32)(unsafe.Pointer(&v20[12])) = 0
		nox_xxx_modifSetItemAttrs_4E4990(a1, (*int32)(unsafe.Pointer(&v20[0])))
		return 1
	}
	if nox_crypt_IsReadOnly() != 0 {
		v4 = 0
		v5 = &v20[0]
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 1)
			if int32(uint8(int8(v18))) >= 256 {
				return 0
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v21[0], uint32(uint8(int8(v18))))
			v21[uint8(int8(v18))] = 0
			v6 = nox_xxx_modifGetIdByName_413290(&v21[0])
			*(**server.ModifierEff)(unsafe.Pointer(v5)) = nox_xxx_modifGetDescById_413330(v6)
			v4++
			v5 = (*byte)(unsafe.Add(unsafe.Pointer(v5), 4))
			if v4 >= 4 {
				*(*uint16)(unsafe.Pointer(&v20[16])) = math.MaxUint16
				*(*uint16)(unsafe.Pointer(&v20[18])) = math.MaxUint16
				nox_xxx_modifSetItemAttrs_4E4990(a1, (*int32)(unsafe.Pointer(&v20[0])))
				goto LABEL_18
			}
		}
	}
	v2 = (***byte)(a1.InitData)
	v3 = 4
	for {
		if *v2 != nil {
			*(*uint8)(unsafe.Pointer(&v18)) = uint8(int8(libc.StrLen(**v2)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(**v2, uint32(uint8(int8(v18))))
		} else {
			*(*uint8)(unsafe.Pointer(&v18)) = 0
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 1)
		}
		v2 = (***byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((**byte)(nil))*1))
		v3--
		if v3 == 0 {
			break
		}
	}
LABEL_18:
	if int32(int16(v17)) >= 41 {
		v7 = 0
		if a1.ObjClass&0x1000 != 0 && a1.ObjSubClass&0x47F0000 != 0 {
			v7 = 1
		}
		if (int32(int16(v17)) >= 62 || (a1.ObjClass&0x1000) == 0 || (a1.ObjSubClass&0x4000000) == 0) && v7 != 0 {
			v8 := a1.UseData
			v14 = *(*uint8)(unsafe.Add(v8, 108))
			v15 = *(*uint8)(unsafe.Add(v8, 109))
			v9 = v15
			v16 = int32(*(*uint32)(unsafe.Add(v8, 112)))
			v10 = v16
			v14 = *(*uint8)(unsafe.Add(v8, 108))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v14, 1)
			v15 = *(*uint8)(unsafe.Add(v8, 109))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v15, 1)
			if int32(int16(v17)) >= 61 {
				v16 = int32(*(*uint32)(unsafe.Add(v8, 112)))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v16)), 4)
			}
			if !noxflags.HasGame(4096) {
				*(*uint8)(unsafe.Add(v8, 108)) = v14
				*(*uint8)(unsafe.Add(v8, 109)) = v15
				*(*uint32)(unsafe.Add(v8, 112)) = uint32(v16)
				goto LABEL_37
			}
			if int32(v14) <= int32(v9) && v16 >= 0 && v16 <= v10 && int32(v9) == int32(v15) {
				*(*uint8)(unsafe.Add(v8, 108)) = v14
				*(*uint8)(unsafe.Add(v8, 109)) = v15
				*(*uint32)(unsafe.Add(v8, 112)) = uint32(v16)
				goto LABEL_37
			}
			*(*uint8)(unsafe.Add(v8, 108)) = 0
			*(*uint8)(unsafe.Add(v8, 109)) = v9
			*(*uint32)(unsafe.Add(v8, 112)) = 0
		}
	}
LABEL_37:
	if int32(int16(v17)) >= 42 {
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v11), unsafe.Sizeof(uint16(0))*0)) = uint16(nox_xxx_unitGetHP_4EE780(a1))
		v16 = v11
		v12 = nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v16)), 2)
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v12), unsafe.Sizeof(uint16(0))*0)) = a1.HealthData.Max
		if int32(uint16(int16(v16))) > int32(uint16(v12)) {
			v16 = int32(v12)
		}
		if nox_crypt_IsReadOnly() == 1 {
			if nox_xxx_gameIsSwitchToSolo_4DB240() == 1 || nox_xxx_gameIsNotMultiplayer_4DB250() == 1 || noxflags.HasGame(4096) && sub_419EA0() != 0 {
				nox_xxx_unitSetHP_4E4560(a1, uint16(int16(v16)))
			} else {
				v13 := nox_xxx_getProjectileClassById_413250(int32(a1.TypeInd))
				if v13 != nil {
					a1.HealthData.Max = *(*uint16)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(uint16(0))*26))
					a1.HealthData.Field2 = *(*uint16)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(uint16(0))*26))
					nox_xxx_unitSetHP_4E4560(a1, *(*uint16)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(uint16(0))*26)))
				}
			}
		}
	}
	if int32(uint16(int16(v17))) == 63 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v14, 1)
	}
	if int32(int16(v17)) >= 64 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(a1.UpdateData, 4)), 4)
	}
	if a1.Field34 != 0 && nox_crypt_IsReadOnly() == 1 && Nox_xxx_xfer_4F3E30(uint16(int16(v17)), a1, a1.Field34) == 0 {
		return 0
	}
	a1.Field34 = uint32(v19)
	return 1
}
func nox_xxx_XFerArmor_4F6860(a1p *server.Object, data unsafe.Pointer) int {
	a1 := a1p
	var (
		result int32
		v2     ***byte
		v3     int32
		v4     int32
		v5     *byte
		v6     int32
		v7     int32
		v8     uint32
		v10    int32
		v11    int32
		v12    uint32
		v13    int8
		v14    int32
		v15    [20]byte
		v16    [256]byte
	)
	v14 = int32(a1.Field34)
	v10 = 62
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 2)
	if int32(int16(v10)) > 62 {
		return 0
	}
	result = int32(Nox_xxx_mapReadWriteObjData_4F4530(a1, int(int32(int16(v10)))))
	if result == 0 {
		return int(result)
	}
	if int32(int16(v10)) < 11 && nox_crypt_IsReadOnly() == 1 {
		*(*uint32)(unsafe.Pointer(&v15[0])) = 0
		*(*uint32)(unsafe.Pointer(&v15[4])) = 0
		*(*uint32)(unsafe.Pointer(&v15[8])) = 0
		*(*uint32)(unsafe.Pointer(&v15[12])) = 0
		nox_xxx_modifSetItemAttrs_4E4990(a1, (*int32)(unsafe.Pointer(&v15[0])))
		return 1
	}
	if nox_crypt_IsReadOnly() != 0 {
		v4 = 0
		v5 = &v15[0]
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 1)
			if int32(uint8(int8(v11))) >= 256 {
				return 0
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v16[0], uint32(uint8(int8(v11))))
			v16[uint8(int8(v11))] = 0
			v6 = nox_xxx_modifGetIdByName_413290(&v16[0])
			*(**server.ModifierEff)(unsafe.Pointer(v5)) = nox_xxx_modifGetDescById_413330(v6)
			v4++
			v5 = (*byte)(unsafe.Add(unsafe.Pointer(v5), 4))
			if v4 >= 4 {
				*(*uint16)(unsafe.Pointer(&v15[16])) = math.MaxUint16
				*(*uint16)(unsafe.Pointer(&v15[18])) = math.MaxUint16
				nox_xxx_modifSetItemAttrs_4E4990(a1, (*int32)(unsafe.Pointer(&v15[0])))
				goto LABEL_18
			}
		}
	}
	v2 = (***byte)(a1.InitData)
	v3 = 4
	for {
		if *v2 != nil {
			*(*uint8)(unsafe.Pointer(&v11)) = uint8(int8(libc.StrLen(**v2)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(**v2, uint32(uint8(int8(v11))))
		} else {
			*(*uint8)(unsafe.Pointer(&v11)) = 0
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 1)
		}
		v2 = (***byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((**byte)(nil))*1))
		v3--
		if v3 == 0 {
			break
		}
	}
LABEL_18:
	if int32(int16(v10)) >= 41 {
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v7), unsafe.Sizeof(uint16(0))*0)) = uint16(nox_xxx_unitGetHP_4EE780(a1))
		v12 = uint32(v7)
		v8 = nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 2)
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v8), unsafe.Sizeof(uint16(0))*0)) = a1.HealthData.Max
		if int32(uint16(v12)) > int32(uint16(v8)) {
			v12 = v8
		}
		if nox_crypt_IsReadOnly() == 1 {
			if nox_xxx_gameIsSwitchToSolo_4DB240() == 1 || nox_xxx_gameIsNotMultiplayer_4DB250() == 1 || noxflags.HasGame(4096) && sub_419EA0() != 0 {
				nox_xxx_unitSetHP_4E4560(a1, uint16(v12))
			} else {
				v9 := nox_xxx_equipClothFindDefByTT_413270(int32(a1.TypeInd))
				if v9 != nil {
					a1.HealthData.Max = *(*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*26))
					a1.HealthData.Field2 = *(*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*26))
					nox_xxx_unitSetHP_4E4560(a1, *(*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*26)))
				}
			}
		}
	}
	if int32(uint16(int16(v10))) == 61 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13)), 1)
	}
	if int32(int16(v10)) >= 62 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(a1.UpdateData, 4)), 4)
	}
	if a1.Field34 != 0 && nox_crypt_IsReadOnly() == 1 && Nox_xxx_xfer_4F3E30(uint16(int16(v10)), a1, a1.Field34) == 0 {
		return 0
	}
	a1.Field34 = uint32(v14)
	return 1
}
func nox_xxx_XFerAmmo_4F6B20(a1p *server.Object, data unsafe.Pointer) int {
	a1 := a1p
	var (
		v1     int32
		result int32
		v3     ***byte
		v4     int32
		v5     *byte
		v6     int32
		v7     *byte
		v8     int32
		v9     bool
		v10    *byte
	)
	var v11 int8
	var v12 int8
	var v13 int8
	var v14 int32
	var v15 *byte
	var v16 int32
	var v17 int32
	var v18 [20]byte
	var v19 [256]byte
	v1 = int32(a1.Field34)
	v15 = (*byte)(a1.UseData)
	v17 = v1
	v16 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v16)), 2)
	if int32(int16(v16)) > 60 {
		return 0
	}
	result = int32(Nox_xxx_mapReadWriteObjData_4F4530(a1, int(int32(int16(v16)))))
	if result == 0 {
		return int(result)
	}
	if nox_crypt_IsReadOnly() != 0 {
		v6 = 0
		v7 = &v18[0]
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 1)
			if int32(uint8(int8(v14))) >= 256 {
				return 0
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v19[0], uint32(uint8(int8(v14))))
			v19[uint8(int8(v14))] = 0
			v8 = nox_xxx_modifGetIdByName_413290(&v19[0])
			*(**server.ModifierEff)(unsafe.Pointer(v7)) = nox_xxx_modifGetDescById_413330(v8)
			v6++
			v7 = (*byte)(unsafe.Add(unsafe.Pointer(v7), 4))
			if v6 >= 4 {
				*(*uint16)(unsafe.Pointer(&v18[16])) = math.MaxUint16
				*(*uint16)(unsafe.Pointer(&v18[18])) = math.MaxUint16
				nox_xxx_modifSetItemAttrs_4E4990(a1, (*int32)(unsafe.Pointer(&v18[0])))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 1)
				v9 = !noxflags.HasGame(4096)
				v10 = v15
				if !v9 {
					*(*byte)(unsafe.Add(unsafe.Pointer(v15), 2)) = 0
				}
				v11 = v12
				*(*byte)(unsafe.Add(unsafe.Pointer(v10), 1)) = byte(v13)
				*v10 = byte(v11)
				goto LABEL_17
			}
		}
	}
	v3 = (***byte)(a1.InitData)
	v4 = 4
	for {
		if *v3 != nil {
			*(*uint8)(unsafe.Pointer(&v14)) = uint8(int8(libc.StrLen(**v3)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(**v3, uint32(uint8(int8(v14))))
		} else {
			*(*uint8)(unsafe.Pointer(&v14)) = 0
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 1)
		}
		v3 = (***byte)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((**byte)(nil))*1))
		v4--
		if v4 == 0 {
			break
		}
	}
	v5 = v15
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v15), 1)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v5, 1)
LABEL_17:
	if a1.Field34 != 0 && nox_crypt_IsReadOnly() == 1 && Nox_xxx_xfer_4F3E30(uint16(int16(v16)), a1, a1.Field34) == 0 {
		return 0
	}
	a1.Field34 = uint32(v17)
	result = 1
	return int(result)
}
func nox_xxx_XFerTeam_4F6D20(a1p *server.Object, data unsafe.Pointer) int {
	a1 := a1p
	var (
		result int32
		v2     ***byte
		v3     int32
		v4     *byte
		v5     int32
		v6     int32
		v7     *uint32
		v8     int32
		v9     int32
		v10    int32
		v11    [20]byte
		v12    [256]byte
	)
	v10 = int32(a1.Field34)
	v9 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v9)), 2)
	if int32(int16(v9)) > 60 {
		return 0
	}
	result = int32(Nox_xxx_mapReadWriteObjData_4F4530(a1, int(int32(int16(v9)))))
	if result == 0 {
		return int(result)
	}
	if nox_crypt_IsReadOnly() != 0 {
		v4 = &v11[0]
		v5 = 4
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v12[0], uint32(uint8(int8(v8))))
			v12[uint8(int8(v8))] = 0
			v6 = nox_xxx_modifGetIdByName_413290(&v12[0])
			*(**server.ModifierEff)(unsafe.Pointer(v4)) = nox_xxx_modifGetDescById_413330(v6)
			v4 = (*byte)(unsafe.Add(unsafe.Pointer(v4), 4))
			v5--
			if v5 == 0 {
				break
			}
		}
		*(*uint16)(unsafe.Pointer(&v11[16])) = math.MaxUint16
		*(*uint16)(unsafe.Pointer(&v11[18])) = math.MaxUint16
		nox_xxx_modifSetItemAttrs_4E4990(a1, (*int32)(unsafe.Pointer(&v11[0])))
		if uint32(a1.ObjClass)&0x10000000 != 0 {
			v7 = (*uint32)(a1.UpdateData)
			*v7 = uint32(a1.PosVec.X)
			*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1)) = uint32(a1.PosVec.Y)
		}
	} else {
		v2 = (***byte)(a1.InitData)
		v3 = 4
		for {
			if *v2 != nil {
				*(*uint8)(unsafe.Pointer(&v8)) = uint8(int8(libc.StrLen(**v2)))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(**v2, uint32(uint8(int8(v8))))
			} else {
				*(*uint8)(unsafe.Pointer(&v8)) = 0
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 1)
			}
			v2 = (***byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((**byte)(nil))*1))
			v3--
			if v3 == 0 {
				break
			}
		}
	}
	if a1.Field34 == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
		result = Nox_xxx_xfer_4F3E30(uint16(int16(v9)), a1, a1.Field34)
		return result
	}()) != 0 {
		a1.Field34 = uint32(v10)
		result = 1
	}
	return int(result)
}
func nox_xxx_XFerGold_4F6EC0(a1p *server.Object, data unsafe.Pointer) int {
	var (
		v2     *uint8
		v3     int32
		result int32
	)
	v1 := a1p
	v2 = (*uint8)(a1p.InitData)
	v3 = int32(a1p.Field34)
	a1 := int32(60)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
	if int32(int16(a1)) > 60 {
		return 0
	}
	result = int32(Nox_xxx_mapReadWriteObjData_4F4530(v1, int(int32(int16(a1)))))
	if result == 0 {
		return int(result)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v2, 4)
	if v1.Field34 == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
		result = Nox_xxx_xfer_4F3E30(uint16(int16(a1)), v1, v1.Field34)
		return result
	}()) != 0 {
		v1.Field34 = uint32(v3)
		result = 1
	}
	return int(result)
}
func nox_xxx_XFerObelisk_4F6F60(a1p *server.Object, data unsafe.Pointer) int {
	var (
		v2     *uint8
		v3     int32
		result int32
		v7     float32
		v8     int32
		v9     int32
	)
	v1 := a1p
	v2 = (*uint8)(a1p.UpdateData)
	v3 = int32(a1p.Field34)
	v8 = 61
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 2)
	if int32(int16(v8)) > 61 {
		return 0
	}
	result = int32(Nox_xxx_mapReadWriteObjData_4F4530(v1, int(int32(int16(v8)))))
	if result == 0 {
		return int(result)
	}
	if int32(int16(v8)) >= 61 {
		var a1 int32
		*(*uint8)(unsafe.Pointer(&a1)) = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v2, 4)
		if nox_crypt_IsReadOnly() == 1 {
			v9 = int32(*(*uint32)(unsafe.Pointer(v2)) * 80 / 50)
			v7 = float32(float64(v9))
			nullsub_35(unsafe.Pointer(v1), *(*uint32)(unsafe.Add(unsafe.Pointer(&v7), 4*0)))
		}
		if noxflags.HasGame(2048) {
			v5 := nox_xxx_netSpriteByCodeStatic_45A720(v1.Extent)
			if v5 != nil {
				v6 := nox_xxx_cliFirstMinimapObj_459EB0()
				if v6 != nil {
					for v6 != v5 {
						v6 = nox_xxx_cliNextMinimapObj_459EC0(v6)
						if v6 == nil {
							goto LABEL_14
						}
					}
					*(*uint8)(unsafe.Pointer(&a1)) = 1
				}
			}
		}
	LABEL_14:
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
	}
	if v1.Field34 == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
		result = Nox_xxx_xfer_4F3E30(uint16(int16(v8)), v1, v1.Field34)
		return result
	}()) != 0 {
		v1.Field34 = uint32(v3)
		return 1
	}
	return int(result)
}
func nox_xxx_XFerToxicCloud_4F70A0(a1p *server.Object, data unsafe.Pointer) int {
	var (
		v3 int32
	)
	v1 := a1p
	v2 := a1p.UpdateData
	v3 = int32(a1p.Field34)
	a1 := int32(61)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
	if int32(int16(a1)) > 61 {
		return 0
	}
	if int32(int16(a1)) <= 0 {
		return 0
	}
	if Nox_xxx_mapReadWriteObjData_4F4530(v1, int(int32(int16(a1)))) == 0 {
		return 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*byte)(v2), 4)
	if v1.Field34 != 0 {
		if nox_crypt_IsReadOnly() == 1 && Nox_xxx_xfer_4F3E30(uint16(int16(a1)), v1, v1.Field34) == 0 {
			return 0
		}
	}
	v1.Field34 = uint32(v3)
	return 1
}
func nox_xxx_XFerMonsterGen_4F7130(a1p *server.Object, data unsafe.Pointer) int {
	a1 := a1p
	var (
		v2  int32
		v4  int32
		v5  *uint8
		v6  *byte
		v7  *byte
		v8  *byte
		v9  *byte
		v10 *int32
		v11 int8
		v12 *int32
		v13 int32
		v15 *uint8
		v16 int32
		v17 int32
		v19 int32
		v20 bool
		v21 int32
		v22 *uint8
		v24 uint32
		v25 int8
		v26 int32
		v27 int32
		v28 int32
		v29 int32
		v30 int32
		v31 int32
		v32 *uint8
		v33 int32
		v34 [256]byte
	)
	v1 := a1.UpdateData
	v2 = int32(a1.Field34)
	v3 := a1.Field189
	v32 = (*uint8)(a1.UpdateData)
	v33 = v2
	v29 = 63
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v29)), 2)
	if !(int32(int16(v29)) <= 63 && int32(int16(v29)) > 0 && Nox_xxx_mapReadWriteObjData_4F4530(a1, int(int32(int16(v29)))) != 0) {
		return 0
	}
	*(*uint8)(unsafe.Pointer(&v31)) = 3
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v31)), 1)
	v4 = 0
	if int32(uint8(int8(v31))) != 0 {
		v5 = (*uint8)(unsafe.Add(v1, 80))
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v5, 1)
			v4++
			v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 1))
			if v4 >= int32(uint8(int8(v31))) {
				break
			}
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 86)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 87)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 88)), 4)
	if v3 != nil {
		v6 = (*byte)(unsafe.Add(v3, 1920))
	} else {
		v6 = nil
	}
	nox_xxx_xferReadScriptHandler_4F5580(unsafe.Add(v1, 48), v6)
	if v3 != nil {
		v7 = (*byte)(unsafe.Add(v3, 2048))
	} else {
		v7 = nil
	}
	nox_xxx_xferReadScriptHandler_4F5580(unsafe.Add(v1, 56), v7)
	if v3 != nil {
		v8 = (*byte)(unsafe.Add(v3, 2176))
	} else {
		v8 = nil
	}
	nox_xxx_xferReadScriptHandler_4F5580(unsafe.Add(v1, 72), v8)
	if v3 != nil {
		v9 = (*byte)(unsafe.Add(v3, 2304))
	} else {
		v9 = nil
	}
	nox_xxx_xferReadScriptHandler_4F5580(unsafe.Add(v1, 64), v9)
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v27)), 1)
		v16 = 0
		if int32(uint8(int8(v27))) != 0 {
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v30)), 1)
				v17 = 0
				if int32(uint8(int8(v30))) != 0 {
					for {
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v28)), 1)
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v34[0], uint32(uint8(int8(v28))))
						v34[uint8(int8(v28))] = 0
						v18 := nox_xxx_newObjectByTypeID_4E3810(&v34[0])
						if v18 == nil {
							return 0
						}
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v26)), 2)
						nox_xxx_fileCryptReadCrcMB_426C20((*uint8)(unsafe.Pointer(&v32)), 4)
						if v18.Xfer.Get()(v18, nil) == 0 {
							return 0
						}
						v19 = func() int32 {
							p := &v17
							x := *p
							*p++
							return x
						}() + v16*4
						v20 = v17 < int32(uint8(int8(v30)))
						*(*uint32)(unsafe.Add(v1, v19*4)) = uint32(uintptr(unsafe.Pointer(v18)))
						if !v20 {
							break
						}
					}
				}
				if func() int32 {
					p := &v16
					*p++
					return *p
				}() >= int32(uint8(int8(v27))) {
					goto LABEL_37
				}
			}
		}
	} else {
		*(*uint8)(unsafe.Pointer(&v26)) = 3
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v26)), 1)
		v10 = (*int32)(unsafe.Pointer(v1))
		v28 = 3
		for {
			v11 = 0
			v12 = v10
			v25 = 0
			v13 = 4
			for {
				if *v12 != 0 {
					v11++
				}
				v12 = (*int32)(unsafe.Add(unsafe.Pointer(v12), 4*1))
				v13--
				if v13 == 0 {
					break
				}
			}
			v25 = v11
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v25)), 1)
			v30 = 4
			for {
				v14 := *(**server.Object)(unsafe.Pointer(v10))
				if v14 != nil {
					*(*uint8)(unsafe.Pointer(&v27)) = uint8(int8(libc.StrLen(nox_xxx_getUnitName_4E39D0(v14))))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v27)), 1)
					v24 = uint32(uint8(int8(v27)))
					v15 = nox_xxx_getUnitName_4E39D0(v14)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v15, v24)
					nox_xxx_xfer_saveObj_51DF90(v14)
				}
				v10 = (*int32)(unsafe.Add(unsafe.Pointer(v10), 4*1))
				v30--
				if v30 == 0 {
					break
				}
			}
			v10 = v12
			v28--
			if v28 == 0 {
				break
			}
		}
		v1 = unsafe.Pointer(v32)
	}
LABEL_37:
	if int32(int16(v29)) >= 62 {
		*(*uint8)(unsafe.Pointer(&v26)) = 3
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v26)), 1)
		v21 = 0
		if int32(uint8(int8(v26))) != 0 {
			v22 = (*uint8)(unsafe.Add(v1, 83))
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v22, 1)
				v21++
				v22 = (*uint8)(unsafe.Add(unsafe.Pointer(v22), 1))
				if v21 >= int32(uint8(int8(v26))) {
					break
				}
			}
		}
	}
	if int32(int16(v29)) >= 63 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 92)), 4)
	}
	if a1.Field34 == 0 || nox_crypt_IsReadOnly() != 1 || Nox_xxx_xfer_4F3E30(uint16(int16(v29)), a1, a1.Field34) != 0 {
		a1.Field34 = uint32(v33)
		return 1
	}
	return 0
}
func nox_xxx_XFerRewardMarker_4F74D0(a1p *server.Object, data unsafe.Pointer) int {
	a1 := a1p
	var (
		v1  *uint8
		v2  int32
		i   int32
		v4  *byte
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 *byte
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 *byte
		v16 int32
		v18 uint32
		v19 uint32
		v20 uint32
		v21 int32
		v22 int32
		v23 int32
		v24 int32
		v25 [256]byte
	)
	v1 = (*uint8)(a1.InitData)
	v24 = int32(a1.Field34)
	v23 = 63
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v23)), 2)
	if int32(int16(v23)) > 63 {
		return 0
	}
	v2 = 0
	if int32(int16(v23)) <= 0 {
		return 0
	}
	if Nox_xxx_mapReadWriteObjData_4F4530(a1, int(int32(int16(v23)))) == 0 {
		return 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v1, 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 4)), 4)
	v22 = 0
	for i = 0; i < 137; i++ {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), i+8))) == 1 {
			v22++
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 2)
	if nox_crypt_IsReadOnly() != 0 {
		v5 = 0
		if int32(uint16(int16(v22))) != 0 {
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v25[0], uint32(uint8(int8(v21))))
				v25[uint8(int8(v21))] = 0
				v6 = nox_xxx_spellNameToN_4243F0(&v25[0])
				if v6 == 0 {
					return 0
				}
				*(*uint8)(unsafe.Add(unsafe.Pointer(v1), v6+8)) = 1
				if func() int32 {
					p := &v5
					*p++
					return *p
				}() >= int32(uint16(int16(v22))) {
					break
				}
			}
		}
	} else {
		for {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), v2+8))) != 0 {
				*(*uint8)(unsafe.Pointer(&v21)) = uint8(int8(libc.StrLen(nox_xxx_spellNameByN_424870(v2))))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 1)
				v18 = uint32(uint8(int8(v21)))
				v4 = nox_xxx_spellNameByN_424870(v2)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v4, v18)
			}
			v2++
			if v2 >= 137 {
				break
			}
		}
	}
	v7 = 0
	v8 = 0
	v22 = 0
	for {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), v8+145))) == 1 {
			v22++
		}
		v8++
		if v8 >= 6 {
			break
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 2)
	if nox_crypt_IsReadOnly() != 0 {
		if int32(uint16(int16(v22))) != 0 {
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v25[0], uint32(uint8(int8(v21))))
				v25[uint8(int8(v21))] = 0
				v11 = nox_xxx_abilityNameToN_424D80(&v25[0])
				if v11 == 0 {
					return 0
				}
				*(*uint8)(unsafe.Add(unsafe.Pointer(v1), v11+145)) = 1
				if func() int32 {
					p := &v7
					*p++
					return *p
				}() >= int32(uint16(int16(v22))) {
					break
				}
			}
		}
	} else {
		v9 = 0
		for {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), v9+145))) != 0 {
				*(*uint8)(unsafe.Pointer(&v21)) = uint8(int8(libc.StrLen(nox_xxx_abilityGetName_425250(v9))))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 1)
				v19 = uint32(uint8(int8(v21)))
				v10 = nox_xxx_abilityGetName_425250(v9)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v10, v19)
			}
			v9++
			if v9 >= 6 {
				break
			}
		}
	}
	v12 = 0
	v13 = 0
	v22 = 0
	for {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), v13+151))) == 1 {
			v22++
		}
		v13++
		if v13 >= 41 {
			break
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 2)
	if nox_crypt_IsReadOnly() != 0 {
		if int32(uint16(int16(v22))) != 0 {
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v25[0], uint32(uint8(int8(v21))))
				v25[uint8(int8(v21))] = 0
				v16 = nox_xxx_guide_427010(&v25[0])
				if v16 == 0 {
					return 0
				}
				*(*uint8)(unsafe.Add(unsafe.Pointer(v1), v16+151)) = 1
				if func() int32 {
					p := &v12
					*p++
					return *p
				}() >= int32(uint16(int16(v22))) {
					break
				}
			}
		}
	} else {
		v14 = 0
		for {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), v14+151))) != 0 {
				*(*uint8)(unsafe.Pointer(&v21)) = uint8(int8(libc.StrLen(nox_xxx_guideNameByN_427230(v14))))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 1)
				v20 = uint32(uint8(int8(v21)))
				v15 = nox_xxx_guideNameByN_427230(v14)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v15, v20)
			}
			v14++
			if v14 >= 41 {
				break
			}
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 196)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 192)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 200)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 204)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 208)), 4)
	if int32(int16(v23)) >= 62 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 212)), 4)
	}
	if int32(int16(v23)) >= 63 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 216)), 1)
	}
	if a1.Field34 == 0 || nox_crypt_IsReadOnly() != 1 || Nox_xxx_xfer_4F3E30(uint16(int16(v23)), a1, a1.Field34) != 0 {
		a1.Field34 = uint32(v24)
		return 1
	}
	return 0
}
func nox_xxx_equipedItemByCode_4F7920(a1 *server.Object, a2 int32) *server.Object {
	result := a1.InvFirstItem
	if result == nil {
		return nil
	}
	for result.NetCode != uint32(a2) {
		result = result.InvNextItem
		if result == nil {
			return nil
		}
	}
	return result
}
func sub_4F7950(a1 *server.Object) {
	var (
		v2 int32
	)
	v1 := a1.UpdateDataPlayer()
	v2 = 3
	v3 := &v1.Field42
	for {
		if *v3 != 0 {
			nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(unsafe.Pointer(uintptr(*v3))))
		}
		*v3 = 0
		v3 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
		v2--
		if v2 == 0 {
			break
		}
	}
	*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 181)) = 0
	*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 180)) = 0
}
func nox_xxx_playerSetCustomWP_4F79A0(a1 *server.Object, a2 int32, a3 int32) {
	var (
		v5 types.Pointf
	)
	v3 := a1.UpdateData
	if (int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 3680))) & 3) == 0 {
		v4 := *(**server.Object)(unsafe.Add(v3, int32(*(*uint8)(unsafe.Add(v3, 180)))*4+168))
		if v4 != nil {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5.X), 4*0)) = uint32(a2)
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5.Y), 4*0)) = uint32(a3)
			nox_xxx_unitMove_4E7010(v4, &v5)
		} else {
			*(**server.Object)(unsafe.Add(v3, int32(*(*uint8)(unsafe.Add(v3, 180)))*4+168)) = nox_xxx_newObjectByTypeID_4E3810(internCStr("PlayerWaypoint"))
			nox_xxx_createAt_4DAA50((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v3, int32(*(*uint8)(unsafe.Add(v3, 180)))*4+168))), a1, float32(a2), float32(a3))
		}
	}
}
func nox_xxx_playerConfusedGetDirection_4F7A40(a1p *server.Object) int32 {
	var (
		a1 = a1p
		v1 int32
		v2 int32
		v3 int32
		v4 int32
	)
	v1 = int32(a1.Direction2)
	v2 = int32(uint8(nox_xxx_buffGetPower_4FF570(a1, 3)))
	v3 = int32((gameFrame() + a1.NetCode) % 0x28)
	if v3 > 20 {
		v3 = 40 - v3
	}
	v4 = (v2+3)*(v3-10) + v1
	if v4 < 0 {
		v4 += int32(uint32(math.MaxUint8-v4) >> 8 << 8)
	}
	if v4 >= 256 {
		v4 += int32((uint32(v4) >> 8) * 4294967040)
	}
	return v4
}
func nox_xxx_mapFindPlayerStart_4F7AB0(a1 *types.Pointf, a2p *server.Object) {
	var (
		a2  = a2p
		v3  int32
		v4  int32
		v8  int32
		v11 float64
		v12 float64
		v13 float64
		v14 int32
		v15 float32
		v16 int32
		v17 float32
		v18 int32
	)
	v3 = 0
	v16 = 0
	if dword_5d4594_1568868 == 0 {
		result := nox_xxx_getNameId_4E3AA0(internCStr("PlayerStart"))
		dword_5d4594_1568868 = uint32(result)
	}
	if a2 != nil {
		if nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(a2), 48))) != 0 {
			v16 = int32(a2.TeamVal.ID)
			nox_xxx_getTeamByID_418AB0(v16)
			v3 = v16
		}
		v4 = 0
		var v5 *server.Object
		v6 := nox_server_getFirstObject_4DA790()
		if v6 == nil {
			a1.X = 2000.0
			a1.Y = 2000.0
			return
		}
		for {
			if uint32(v6.TypeInd) == dword_5d4594_1568868 {
				v5 = v6
				if sub_4F7CE0(unsafe.Pointer(v6), v3) != 0 {
					v4++
				}
			}
			v6 = nox_server_getNextObject_4DA7A0(v6)
			if v6 == nil {
				break
			}
		}
		v18 = v4
		if v4 != 0 {
			v17 = 0.0
			var j *server.Object
			v8 = 1
			v9 := nox_server_getFirstObject_4DA790()
			for v9 != nil {
				if uint32(v9.TypeInd) == dword_5d4594_1568868 && sub_4F7CE0(unsafe.Pointer(v9), v16) != 0 {
					v15 = 1e+07
					for i := nox_xxx_getFirstPlayerUnit_4DA7C0(); i != nil; i = nox_xxx_getNextPlayerUnit_4DA7F0(i) {
						if i != a2 && nox_xxx_unitIsEnemyTo_5330C0(a2, i) != 0 {
							v11 = float64(v9.PosVec.X - i.PosVec.X)
							v12 = float64(v9.PosVec.Y - i.PosVec.Y)
							v13 = v12*v12 + v11*v11
							if v13 < float64(v15) {
								v15 = float32(v13)
							}
							v8 = 0
						}
					}
					if float64(v15) > float64(v17) {
						j = v9
						v17 = v15
					}
				}
				v9 = nox_server_getNextObject_4DA7A0(v9)
			}
			if v8 != 0 || j == nil {
				v14 = nox_common_randomInt_415FA0(0, v18-1)
				for j = nox_server_getFirstObject_4DA790(); j != nil; j = nox_server_getNextObject_4DA7A0(j) {
					if uint32(j.TypeInd) == dword_5d4594_1568868 && sub_4F7CE0(unsafe.Pointer(j), v16) != 0 {
						if v14 == 0 {
							break
						}
						v14--
					}
				}
			}
			*a1 = *(*types.Pointf)(unsafe.Add(unsafe.Pointer(j), 56))
		} else {
			if v5 == nil {
				a1.X = 2000.0
				a1.Y = 2000.0
				return
			}
			*a1 = *(*types.Pointf)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(types.Pointf{})*7))
		}
	}
}
func sub_4F7CE0(a1 unsafe.Pointer, a2 int32) int32 {
	return bool2int32(*(*uint32)(unsafe.Add(a1, 16))&0x1000000 != 0 && (a2 == 0 || nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Add(a1, 48))) == 0 || nox_xxx_teamCompare2_419180((*server.ObjectTeam)(unsafe.Add(a1, 48)), server.TeamID(uint8(int8(a2)))) != 0))
}
func nox_xxx_playerSubStamina_4F7D30(a1p *server.Object, a2 int32) int32 {
	var (
		a1 = a1p
		v2 int32
	)
	v2 = int32(a1.ObjClass)
	if v2&4 != 0 {
		v3 := a1.UpdateData
		if int32(*(*uint8)(unsafe.Add(v3, 91))) >= a2 {
			*(*uint8)(unsafe.Add(v3, 91)) -= uint8(int8(a2))
			nox_xxx_netReportStamina_4D8800(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 2064))), a1)
			return 1
		}
	} else {
		if (v2 & 2) == 0 {
			return 1
		}
		v5 := a1.UpdateData
		if int32(*(*uint8)(unsafe.Add(v5, 1128))) >= a2 {
			*(*uint8)(unsafe.Add(v5, 1128)) -= uint8(int8(a2))
			return 1
		}
	}
	return 0
}
func sub_4F7DB0(a1 *server.Object, a2 int8) {
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 {
		v2 := a1.UpdateData
		*(*uint8)(unsafe.Add(v2, 91)) -= uint8(a2)
		nox_xxx_netReportStamina_4D8800(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 2064))), a1)
	}
}
func nox_xxx_checkWinkFlags_4F7DF0(a1p *server.Object) int32 {
	var (
		a1 = a1p
		v1 int32
		v4 int32
	)
	v1 = int32(*memmap.PtrUint32(0x5D4594, 1568872))
	if *memmap.PtrUint32(0x5D4594, 1568872) == 0 {
		v1 = nox_xxx_getNameId_4E3AA0(internCStr("GameBall"))
		*memmap.PtrUint32(0x5D4594, 1568872) = uint32(v1)
	}
	v2 := a1.Field129
	if v2 == nil {
		return 0
	}
	for int32(v2.TypeInd) != v1 {
		v2 = v2.Field128
		if v2 == nil {
			return 0
		}
	}
	v4 = int32(v2.ObjFlags)
	*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(v4 & 0xBF))
	v2.ObjFlags = uint32(v4)
	nox_xxx_objectApplyForce_52DF80(&a1.PosVec, v2, 100.0)
	v2.Obj130 = nil
	Nox_xxx_unitClearOwner_4EC300(v2)
	nox_xxx_aud_501960(926, a1, 0, 0)
	sub_4E8290(1, 0)
	return 1
}
func nox_xxx_weaponGetStaminaByType_4F7E80(a1 int32) int32 {
	if a1&0x200 != 0 {
		return 70
	}
	if a1&0x4000 != 0 {
		return 100
	}
	if a1&0x800 != 0 {
		return 50
	}
	if a1&0x100 != 0 {
		return 45
	}
	if a1&0x1000 != 0 {
		return 75
	}
	if a1&0x2000 != 0 {
		return 100
	}
	if uint32(a1)&0x7FF8000 != 0 {
		return 45
	}
	if (a1 & 0x400) != 0 {
		return 75
	}
	return 10
}
func Nox_xxx_playerRespawn_4F7EF0(a1p *server.Object) {
	var (
		a1 = a1p
		v2 *byte
		v9 types.Pointf
	)
	v1 := (*byte)(sub_416640())
	v2 = v1
	if a1 == nil {
		return
	}
	v3 := a1.UpdateDataPlayer()
	v4 := v3.Player
	if !(!noxflags.HasGame(4096) || (func() *byte {
		v1 = (*byte)(unsafe.Pointer(uintptr(v3.Field137)))
		return v1
	}()) == nil) {
		return
	}
	if v4 != nil {
		v4.Field4700 = 0
	}
	if noxflags.HasGame(4096) {
		nox_xxx_playerMakeDefItems_4EF7D0(a1, 1, 1)
		*(*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(v3), v3.Player.PlayerInd), 452)) = 250
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, internCStr("GeneralPrint:Respawn"), 0)
	} else {
		nox_xxx_playerMakeDefItems_4EF7D0(a1, 1, 0)
	}
	if noxflags.HasGame(4096) {
		nox_xxx_aud_501960(1006, a1, 0, 0)
	} else {
		nox_xxx_aud_501960(148, a1, 0, 0)
	}
	if dword_5d4594_2650652 == 0 || *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 58)) != 0 {
		nox_xxx_respawnPlayerImpl_53FBC0(&a1.PosVec, int32(a1.Direction1))
	}
	v9 = a1.PosVec
	if noxflags.HasGame(4096) && v3.Field77 != nil {
		sub_4F80C0(v3.Field77, &v9)
	} else {
		nox_xxx_mapFindPlayerStart_4F7AB0(&v9, a1)
	}
	nox_xxx_unitMove_4E7010(a1, &v9)
	if noxflags.HasGame(16) {
		if nox_xxx_CheckGameplayFlags_417DA0(4) {
			v7 := *(**server.Object)(unsafe.Add(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(v4.PlayerUnit.TeamVal.ID))), 4*19))
			if v7 != nil {
				if v7.InvHolder == nil {
					sub_4F3400(v4.PlayerUnit, v7, 1, 0)
				}
			}
		}
	}
	if noxflags.HasGame(0x2000) {
		nox_xxx_buffApplyTo_4FF380(a1, 23, int16(int32(uint16(gameFPS()))*5), 5)
	}
}
func sub_4F80C0(a1 unsafe.Pointer, a3 *types.Pointf) {
	var (
		v2 int32
	)
	*a3 = *(*types.Pointf)(unsafe.Add(a1, 56))
	v2 = 32
	for {
		sub_4ED970(60.0, (*types.Pointf)(unsafe.Add(a1, 56)), a3)
		if nox_xxx_mapTileAllowTeleport_411A90(a3) == 0 {
			break
		}
		v2--
		if v2 == 0 {
			break
		}
	}
}
func sub_4F9A80(a1 *server.Object) int32 {
	return bool2int32(*(*uint32)(unsafe.Add(a1.UpdateData, uint32(int32(*(*uint8)(unsafe.Add(a1.UpdateData, 181)))*4)+168)) != 0)
}
func sub_4F9AB0(a1p *server.Object) int32 {
	var (
		a1     = a1p
		result int32
		v4     float64
		v5     int32
		v6     float64
		v7     types.Pointf
	)
	v1 := a1.UpdateData
	v2 := *(**server.Object)(unsafe.Add(v1, int32(*(*uint8)(unsafe.Add(v1, 181)))*4+168))
	if v2 == nil {
		return 0
	}
	v7.X = v2.PosVec.X - a1.PosVec.X
	v4 = float64(v2.PosVec.Y - a1.PosVec.Y)
	v7.Y = float32(v4)
	if v4*float64(v7.Y)+float64(v7.X*v7.X) >= 100.0 {
		a1.Direction2 = server.Dir16(uint16(int16(nox_xxx_math_509ED0(&v7))))
		if nox_xxx_testUnitBuffs_4FF350(a1, 3) != 0 {
			a1.Direction2 = server.Dir16(uint16(int16(nox_xxx_playerConfusedGetDirection_4F7A40(a1))))
		}
		v5 = int32(a1.Direction2) * 8
		a1.ForceVec.X = *memmap.PtrFloat32(0x587000, uintptr(v5)+194136)*a1.SpeedCur + a1.ForceVec.X
		v6 = float64(*memmap.PtrFloat32(0x587000, uintptr(v5)+194140) * a1.SpeedCur)
		result = 1
		a1.ForceVec.Y = float32(v6 + float64(a1.ForceVec.Y))
	} else {
		nox_xxx_delayedDeleteObject_4E5CC0(v2)
		result = 0
		*(*uint32)(unsafe.Add(v1, int32(*(*uint8)(unsafe.Add(v1, 181)))*4+168)) = 0
	}
	return result
}
func nox_xxx_playerCanMove_4F9BC0(a1 *server.Object) int32 {
	v1 := a1.UpdateData
	if nox_xxx_testUnitBuffs_4FF350(a1, 25) != 0 {
		return 0
	}
	if nox_xxx_testUnitBuffs_4FF350(a1, 5) != 0 {
		return 0
	}
	if noxflags.HasGame(4096) && *(*uint32)(unsafe.Add(v1, 280)) != 0 {
		return 0
	}
	if int32(*(*uint8)(unsafe.Add(v1, 88))) != 1 {
		return 1
	}
	v3 := *(*unsafe.Pointer)(unsafe.Add(v1, 104))
	if v3 == nil {
		return 1
	}
	if *(*uint32)(unsafe.Add(v3, 8))&0x1000000 != 0 && int32(*(*uint8)(unsafe.Add(v3, 12)))&8 != 0 {
		return 0
	}
	return 1
}
func nox_xxx_playerCanAttack_4F9C40(a1 *server.Object) int32 {
	v1 := a1.UpdateData
	if nox_xxx_testUnitBuffs_4FF350(a1, 25) != 0 {
		return 0
	} else {
		return bool2int32(int32(*(*uint8)(unsafe.Add(v1, 88))) != 23)
	}
}
func nox_xxx_playerInputAttack_4F9C70(a1p *server.Object) {
	var (
		a1 = a1p
		v2 int32
		v4 int32
		v5 int32
		v6 int8
	)
	if a1 != nil && nox_xxx_playerAimsAtEnemy_4F9DC0(a1) != 0 {
		v1 := a1.UpdateData
		v2 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 276)), 4)))
		if v2 != 0 {
			if uint32(v2)&0x47F0000 != 0 && nox_common_mapPlrActionToStateId_4FA2B0(a1) != 29 {
				v3 := *(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 104)), 736))
				if int32(*(*uint8)(unsafe.Add(v3, 108))) != 0 || int32(*(*uint8)(unsafe.Add(v3, 109))) == 0 {
					a1.Field34 = gameFrame()
					*(*uint8)(unsafe.Add(v1, 236)) = 0
					nox_xxx_playerSetState_4FA020(a1, 1)
					nox_xxx_useByNetCode_53F8E0(a1, (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 104))))
				} else if nox_xxx_playerSubStamina_4F7D30(a1, 45) != 0 {
					v4 = int32(*(*uint32)(unsafe.Add(v3, 96)))
					*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(v4 | 2))
					*(*uint32)(unsafe.Add(v3, 96)) = uint32(v4)
					a1.Field34 = gameFrame()
					*(*uint8)(unsafe.Add(v1, 236)) = 0
					nox_xxx_playerSetState_4FA020(a1, 1)
				}
			} else if int32(*(*uint8)(unsafe.Add(v1, 88))) != 1 {
				v5 = nox_xxx_weaponGetStaminaByType_4F7E80(int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 276)), 4))))
				v6 = int8(v5)
				if nox_xxx_playerSubStamina_4F7D30(a1, v5) != 0 {
					a1.Field34 = gameFrame()
					*(*uint8)(unsafe.Add(v1, 236)) = 0
					if nox_xxx_playerSetState_4FA020(a1, 1) == 0 {
						sub_4F7DB0(a1, int8(int32(-v6)))
					}
				}
			}
			nox_xxx_spellBuffOff_4FF5B0(a1, 0)
			nox_xxx_spellBuffOff_4FF5B0(a1, 23)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_OVAL_SHIELD, a1)
		} else if int32(*(*uint8)(unsafe.Add(v1, 88))) != 1 {
			nox_xxx_playerSetState_4FA020(a1, 1)
		}
	}
}
func nox_xxx_playerAimsAtEnemy_4F9DC0(a1 *server.Object) int32 {
	var result int32
	if a1 == nil {
		return 0
	}
	if *(*uint32)(unsafe.Add(a1.UpdateData, 288)) == 0 || nox_xxx_unitIsEnemyTo_5330C0(a1, (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 288)))) != 0 || (func() int32 {
		result = bool2int32(noxflags.HasGame(4096))
		return result
	}()) != 0 {
		result = 1
	}
	return result
}
func sub_4F9E10(a1p *server.Object) int32 {
	var (
		a1 = a1p
		v2 int32
	)
	if a1 == nil {
		return 0
	}
	if a1.Obj130 == nil {
		return 0
	}
	v1 := nox_xxx_findParentChainPlayer_4EC580(a1.Obj130)
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 16)))&0x20 != 0 {
		return 0
	}
	v2 = int32(v1.ObjClass)
	if v2&2 != 0 || v2&4 != 0 && int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1.UpdateData, 276)), 3680)))&1 != 0 {
		return 0
	}
	nox_xxx_playerCameraFollow_4E6060(a1, v1)
	return 1
}
func nox_xxx_unitGetStrength_4F9FD0(obj *server.Object) int32 {
	if obj == nil {
		return 0
	}
	if obj.Class().Has(object.ClassPlayer) {
		return int32(*(*uint32)(unsafe.Add(unsafe.Pointer(obj.UpdateDataPlayer().Player), 2239)))
	}
	if !obj.Class().Has(object.ClassMonster) {
		return 0
	}
	if obj.SubClass().AsMonster().Has(object.MonsterNPC) {
		return int32(*(*uint8)(unsafe.Add(unsafe.Pointer(obj.UpdateDataMonster()), 1324)))
	}
	return 30
}
func nox_xxx_playerSetState_4FA020(a1p *server.Object, a2 int32) int32 {
	var (
		a1 = a1p
		v3 int32
		v4 int32
		v7 int32
		v9 int32
	)
	v2 := a2
	v3 = 1
	v4 = int32(a1.ObjFlags)
	v5 := a1.UpdateDataPlayer()
	if (v4&0x8000) != 0 && a2 != 3 && a2 != 4 {
		return 0
	}
	if !noxflags.HasGame(2048) {
		v7 = int32(a1.ObjFlags)
		if v7&0x4000 != 0 {
			if a2 == 30 {
				return 0
			}
		}
	}
	if a2 == 24 || a2 == 25 || a2 == 26 || a2 == 27 || a2 == 28 || a2 == 29 {
		if nox_common_playerIsAbilityActive_4FC250(a1, 1) != 0 {
			return 0
		}
		if int32(v5.State) == 12 {
			return 0
		}
	}
	if int32(v5.State) == 1 {
		if a2 == 1 {
			goto LABEL_26
		}
		if nox_xxx_probablyWarcryCheck_4FC3E0(a1, 2) != 0 && a2 != 4 && a2 != 3 {
			return 0
		}
	}
	if a2 != 1 {
		*(*uint8)(unsafe.Add(unsafe.Pointer(v5.Player), 8)) = 0
		switch a2 {
		case 3, 4:
			v5.Field40_0 = 0
			v5.Field41 = 0
		case 25:
			if int32(v5.State) != a2 {
				nox_xxx_aud_501960(301, a1, 0, 0)
			}
		case 26:
			if int32(v5.State) != a2 {
				nox_xxx_aud_501960(300, a1, 0, 0)
			}
		case 28:
			if int32(v5.State) != a2 {
				nox_xxx_aud_501960(302, a1, 0, 0)
			}
		default:
			goto LABEL_42
		}
		goto LABEL_42
	}
LABEL_26:
	if v5.Field0 <= gameFrame() {
		v8 := v5.Player
		v9 = int32(v8.Field4)
		v5.Field0 = 0
		if v9 != 0 {
			*(*uint8)(unsafe.Add(unsafe.Pointer(v8), 8)) = 0
		} else {
			*(*uint8)(unsafe.Add(unsafe.Pointer(v5.Player), 8)) = uint8(int8(nox_common_randomInt_415FA0(23, 24)))
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v5.Player), 2251))) == 0 && nox_common_randomInt_415FA0(0, 100) > 75 {
				*(*uint8)(unsafe.Add(unsafe.Pointer(v5.Player), 8)) = 25
			}
			nox_xxx_spellBuffOff_4FF5B0(a1, 0)
			nox_xxx_spellBuffOff_4FF5B0(a1, 23)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_OVAL_SHIELD, a1)
		}
	} else {
		v3 = 0
		v2 = int32(v5.State)
	}
LABEL_42:
	if int32(v5.State) != v2 {
		v5.State2 = v5.State
		v5.State = uint8(int8(v2))
		a1.Field34 = gameFrame()
		v5.Field59_0 = 0
	}
	if v2 == 30 {
		v5.Field41 = gameFrame()
	}
	return v3
}
func sub_4FA280(a1 int32) int32 {
	var v1 int32
	v1 = 2
	for ((1 << v1) & a1) == 0 {
		if func() int32 {
			p := &v1
			*p++
			return *p
		}() >= 27 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*4)+215824))
}
func nox_common_mapPlrActionToStateId_4FA2B0(a1p *server.Object) int32 {
	var (
		a1 = a1p
		v3 int32
	)
	v1 := a1.UpdateData
	switch *(*uint8)(unsafe.Add(v1, 88)) {
	case 0:
		return 4
	case 1, 0xE, 0x16:
		if nox_common_playerIsAbilityActive_4FC250(a1, 2) != 0 && nox_xxx_probablyWarcryCheck_4FC3E0(a1, 2) != 0 {
			return 46
		} else if nox_common_playerIsAbilityActive_4FC250(a1, 1) != 0 {
			return 45
		} else {
			r1 := *(*unsafe.Pointer)(unsafe.Add(v1, 276))
			v3 = int32(*(*uint32)(unsafe.Add(r1, 4)))
			if uint32(v3)&0x47F0000 != 0 {
				result := int32(^uint8(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 104)), 736)), 96)))) & 2
				return result | 0x1D
			} else if v3 != 0 && v3 != 1 || *(*uint8)(unsafe.Add(r1, 8)) == 0 {
				return sub_4FA280(v3)
			}
			return 0
		}
	case 2, 0xA:
		return 21
	case 3:
		return 1
	case 4:
		return 2
	case 5:
		return 6
	case 0xC:
		return 3
	case 0xD:
		if (*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 276)), 4)) & 0x400) != 0 {
			return 0x26
		} else {
			return 0
		}
	case 0xF, 0x10, 0x11:
		return 40
	case 0x12:
		return 48
	case 0x13:
		return 49
	case 0x14:
		return 47
	case 0x15:
		return 30
	case 0x17:
		return 50
	case 0x18:
		return 19
	case 0x19:
		return 20
	case 0x1A:
		return 15
	case 0x1B, 0x1C, 0x1D:
		return 16
	case 0x1E:
		return 52
	case 0x20:
		return 54
	default:
		return 0
	}
}
func nox_xxx_checkInversionEffect_4FA4F0(a1 *server.Object, a2 *server.Object) int32 {
	var (
		v3  int32
		v4  int32
		v10 int32
	)
	v2 := a1.InvFirstItem
	if v2 == nil {
		return 0
	}
	for {
		v3 = int32(v2.ObjFlags)
		if v3&0x100 != 0 {
			if v2.ObjClass&0x13001000 != 0 {
				v4 = 2
				v5 := unsafe.Add(v2.InitData, 8)
				for {
					v6 := *(*unsafe.Pointer)(v5)
					v10 = 0
					if v6 != nil {
						v7 := ccall.AsFunc[func(int32, int32, int32, int32, int32, *int32) int32](*(*unsafe.Pointer)(unsafe.Add(v6, 88)))
						if v7 != nil {
							if ccall.FuncAddr(v7) == ccall.FuncAddr(nox_xxx_inversionEffect_4E03D0) {
								v8 := nox_xxx_findParentChainPlayer_4EC580(a2)
								ccall.AsFunc[func(unsafe.Pointer, *server.Object, unsafe.Pointer, unsafe.Pointer, *server.Object, *int32)](*(*unsafe.Pointer)(unsafe.Add(v6, 88)))(v6, v2, unsafe.Pointer(a1), unsafe.Pointer(a2), v8, &v10)
								if v10 == 1 {
									return 1
								}
							}
						}
					}
					v4++
					v5 = unsafe.Add(v5, 4*1)
					if v4 >= 4 {
						goto LABEL_10
					}
				}
			}
		}
	LABEL_10:
		v2 = v2.InvNextItem
		if v2 == nil {
			return 0
		}
	}
}
func nox_xxx_playerAddGold_4FA590(a1 *server.Object, a2 int32) {
	v2 := a1.UpdateDataPlayer()
	v2.Player.GoldVal += uint32(a2)
	sub_56F920(v2.Player.ProtPlayerGold, a2)
}
func nox_xxx_playerSubGold_4FA5D0(a1 *server.Object, a2 uint32) {
	v2 := a1.UpdateDataPlayer()
	v3 := v2.Player
	v4 := v3.GoldVal
	if v4 >= a2 {
		v3.GoldVal = v4 - a2
	} else {
		v3.GoldVal = 0
	}
	sub_56F920(v2.Player.ProtPlayerGold, int32(-a2))
}
func nox_object_setGold_4FA620(obj *server.Object, a2 int32) {
	var v4 *server.Player
	if obj != nil && obj.Class().Has(object.ClassPlayer) {
		v3 := obj.UpdateDataPlayer()
		if a2 >= 0 || (func() bool {
			v4 = v3.Player
			return v4.GoldVal >= uint32(-a2)
		}()) {
			v3.Player.GoldVal += uint32(a2)
			sub_56F920(v3.Player.ProtPlayerGold, a2)
		} else {
			v4.GoldVal = 0
			nox_xxx_playerResetProtectionCRC_56F7D0(v3.Player.ProtPlayerGold, 0)
		}
	}
}
func nox_xxx_playerGetGold_4FA6B0(a1 *server.Object) int32 {
	return int32(a1.UpdateDataPlayer().Player.GoldVal)
}
func nox_object_getGold_4FA6D0(a1 *server.Object) int32 {
	if a1 != nil && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 {
		return int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 276)), 2164)))
	} else {
		return 0
	}
}
func nox_xxx_playerBotCreate_4FA700(obj *server.Object) {
	ud := obj.UpdateDataPlayer()
	if ud.UpdateDataBot == nil {
		m, _ := alloc.New(server.MonsterUpdateData{})
		ud.UpdateDataBot = m
	}
	m := ud.UpdateDataBot
	if m != nil {
		typ := nox_xxx_getNameId_4E3AA0(internCStr("NPC"))
		*m = server.MonsterUpdateData{
			UpdateDataBot:         ud,
			MonsterDef:            Nox_xxx_monsterDefByTT_517560(int(typ)),
			RetreatLevel:          math.Float32frombits(1048576000),
			Field335:              1,
			ResumeLevel:           math.Float32frombits(1061997773),
			Field337:              1,
			StatusFlags:           0x2D808,
			Field361:              0,
			Field85:               38,
			Aggression2:           math.Float32frombits(1056964608),
			Aggression:            math.Float32frombits(1062501089),
			Field328:              math.Float32frombits(1125515264),
			Field329:              math.Float32frombits(1106247680),
			Field330:              math.Float32frombits(1065353216),
			Field332:              math.Float32frombits(1056964608),
			Field338:              math.Float32frombits(1065353216),
			ScriptLookingForEnemy: server.ScriptCallback{Func: -1},
			ScriptEnemySighted:    server.ScriptCallback{Func: -1},
			ScriptChangeFocus:     server.ScriptCallback{Func: -1},
			ScriptIsHit:           server.ScriptCallback{Func: -1},
			ScriptRetreat:         server.ScriptCallback{Func: -1},
			ScriptDeath:           server.ScriptCallback{Func: -1},
			ScriptCollision:       server.ScriptCallback{Func: -1},
			ScriptHearEnemy:       server.ScriptCallback{Func: -1},
			ScriptEndOfWaypoint:   server.ScriptCallback{Func: -1},
			ScriptLostEnemy:       server.ScriptCallback{Func: -1},
			Field510:              3,
			DialogStartFunc:       -1,
			DialogEndFunc:         -1,
			Field0:                0xDEADFACE,
			Direction94:           uint32(int16(obj.Direction1)),
			Pos95:                 obj.PosVec,
		}
		m.AIStackInd = 0
		m.AIStack[0].Action = ai.ACTION_HUNT
		*(*uint8)(unsafe.Pointer(&m.Field331)) = 30
		*(*uint8)(unsafe.Pointer(&m.Field333)) = math.MaxUint8
		switch ud.Player.PlayerClass() {
		case player.Warrior:
			m.FleeRange = 0
		case player.Wizard:
			m.FleeRange = math.Float32frombits(1112014848)
			m.Field410 = 0x8000000
			m.StatusFlags |= object.MonStatusCanCastSpells
			m.Field423 = 0x10000000
			m.Field408 = 0x10000000
			m.Field411 = 0x10000000
			m.Field384 = 0x20000000
			m.Field405 = 0x20000000
			m.Field362_0 = 0
			m.Field362_2 = uint16(gameFPS() / 2)
			m.Field364_0 = 0
			m.Field364_2 = uint16(gameFPS())
			m.Field366_0 = uint16(gameFPS() * 3)
			m.Field366_2 = uint16(gameFPS() * 30)
			if v := nox_common_randomInt_415FA0(0, 100); v < 33 {
				m.Field399 = 0x40000000
			} else if v < 66 {
				m.Field388 = 0x40000000
			} else {
				m.Field415 = 0x40000000
				m.Field422 = 0x40000000
			}
			m.Field368_0 = 0
			m.Field376 = math.Float32frombits(2147483648)
			m.Field370_0 = 0
			m.Field368_2 = uint16(gameFPS() * 2)
			m.Field370_2 = uint16(gameFPS() * 6)
		case player.Conjurer:
			m.FleeRange = math.Float32frombits(1112014848)
			m.Field410 = 0x8000000
			m.StatusFlags |= object.MonStatusCanCastSpells
			m.Field362_0 = 0
			m.Field362_2 = uint16(gameFPS() / 2)
			m.Field430 = 0x10000000
			m.Field364_0 = 0
			m.Field364_2 = uint16(gameFPS() * 6)
			m.Field432 = 0x20000000
			m.Field446 = 0x20000000
			m.Field366_0 = uint16(gameFPS() * 3)
			m.Field368_0 = 0
			m.Field366_2 = uint16(gameFPS() * 30)
			m.Field401 = 0x40000000
			m.Field424 = 0x40000000
			m.Field456 = 0x40000000
			m.Field455 = 0x40000000
			m.Field464 = 0x40000000
			m.Field376 = math.Float32frombits(2147483648)
			m.Field370_0 = 0
			m.Field368_2 = uint16(gameFPS() * 2)
			m.Field370_2 = uint16(gameFPS() * 6)
		}
	}
}
func nox_xxx_mobMorphFromPlayer_4FAAC0(obj *server.Object) {
	if obj.Class().Has(object.ClassPlayer) {
		ud := obj.UpdateDataPlayer()
		obj.ObjClass &^= uint32(object.ClassPlayer)
		obj.ObjClass |= uint32(object.ClassMonster)
		obj.ObjSubClass = uint32(object.MonStatusUnused5)
		obj.UpdateData = unsafe.Pointer(ud.UpdateDataBot)
	}
}
func nox_xxx_mobMorphToPlayer_4FAAF0(obj *server.Object) {
	if obj.Class().Has(object.ClassMonster) {
		ud := obj.UpdateDataMonster()
		obj.ObjClass &^= uint32(object.ClassMonster)
		obj.ObjClass |= uint32(object.ClassPlayer)
		obj.ObjSubClass = 0
		obj.UpdateData = unsafe.Pointer(ud.UpdateDataBot)
	}
}
func Nox_xxx_updatePlayerMonsterBot_4FAB20(obj *server.Object) {
	ud := obj.UpdateDataPlayer()
	if ud.UpdateDataBot == nil {
		nox_xxx_playerBotCreate_4FA700(obj)
	}
	if ud.UpdateDataBot == nil {
		obj.Update.Set(nox_xxx_updatePlayer_4F8100)
		return
	}
	if !nox_xxx_respawnPlayerBot_4FAC70(obj) {
		mud := ud.UpdateDataBot
		mud.StatusFlags |= object.MonStatusDestroyWhenDead
		nox_xxx_mobMorphFromPlayer_4FAAC0(obj)
		nox_xxx_unitUpdateMonster_50A5C0(obj)
		nox_xxx_mobMorphToPlayer_4FAAF0(obj)
		ud.State = uint8(nox_xxx_monsterActionToPlrState_4FABC0(obj))
		ud.Field59_0 = mud.Field120_1
		ud.Player.Pos3632Vec = obj.PosVec
	}
}
func nox_xxx_monsterActionToPlrState_4FABC0(obj *server.Object) int8 {
	ud := obj.UpdateDataPlayer()
	mud := ud.UpdateDataBot
	act := mud.AIStackHead()
	if act == nil {
		return 13
	}
	switch act.Type() {
	case ai.ACTION_MOVE_TO, ai.ACTION_FAR_MOVE_TO, ai.ACTION_ROAM, ai.ACTION_FIND_OBJECT, ai.ACTION_RANDOM_WALK:
		if mud.StatusFlags.Has(object.MonStatusRunning) {
			return 5
		}
		return 0
	case ai.ACTION_DODGE:
		return 0
	case ai.ACTION_MELEE_ATTACK, ai.ACTION_MISSILE_ATTACK:
		return 1
	case ai.ACTION_CAST_SPELL_ON_OBJECT, ai.ACTION_CAST_SPELL_ON_LOCATION, ai.ACTION_CAST_DURATION_SPELL:
		return 2
	case ai.ACTION_BLOCK_ATTACK, ai.ACTION_WEAPON_BLOCK:
		return 16
	case ai.ACTION_BLOCK_FINISH:
		return 17
	case ai.ACTION_FLEE:
		return 5
	case ai.ACTION_DYING:
		return 3
	case ai.ACTION_DEAD:
		return 4
	default:
		return 13
	}
}
func nox_xxx_respawnPlayerBot_4FAC70(obj *server.Object) bool {
	a1 := obj
	var (
		v2 *byte
		v4 types.Pointf
	)
	v1 := *(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 292))
	v2 = (*byte)(sub_416640())
	if int32(a1.HealthData.Cur) != 0 {
		return false
	}
	if gameFrame()-*(*uint32)(unsafe.Add(v1, 548)) < (gameFPS() * 2) {
		return true
	}
	nox_xxx_playerBotCreate_4FA700(obj)
	nox_xxx_playerMakeDefItems_4EF7D0(a1, 1, 0)
	if dword_5d4594_2650652 == 0 || *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 58)) != 0 {
		nox_xxx_respawnPlayerImpl_53FBC0(&a1.PosVec, int32(a1.Direction1))
	}
	nox_xxx_mapFindPlayerStart_4F7AB0(&v4, obj)
	nox_xxx_unitMove_4E7010(obj, &v4)
	nox_xxx_aud_501960(148, obj, 0, 0)
	if noxflags.HasGame(0x2000) {
		nox_xxx_buffApplyTo_4FF380(a1, 23, int16(int32(uint16(gameFPS()))*5), 5)
	}
	return false
}
func nox_xxx_netSendRewardNotify_4FAD50(a1 unsafe.Pointer, a2 int32, a3 unsafe.Pointer, a4 int8) {
	var (
		v6 [5]byte
	)
	if !(a1 != nil && int32(*(*uint8)(unsafe.Add(a1, 8)))&4 != 0) {
		return
	}
	v5 := *(*unsafe.Pointer)(unsafe.Add(a1, 748))
	v6[0] = 240
	if a2 != 0 {
		if a2 == 1 {
			v6[1] = 31
		} else {
			if a2 != 2 {
				return
			}
			v6[1] = 32
		}
	} else {
		v6[1] = 30
	}
	*(*uint16)(unsafe.Pointer(&v6[3])) = *(*uint16)(unsafe.Add(a3, 36))
	v6[2] = byte(a4)
	nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 276)), 2064))), unsafe.Pointer(&v6[0]), 5, nil, 1)
}
func sub_4FADD0(a1 *server.Object, a2 *byte, a3 int8) {
	var (
		v4 uint32
		v5 [52]byte
	)
	if a1 != nil {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 {
			if a2 != nil {
				v4 = uint32(libc.StrLen(a2) + 1)
				if int32(uint8(v4)) != 1 && int32(uint8(v4-1)) <= 0x30 {
					v5[51] = byte(a3)
					v5[0] = 240
					v5[1] = 33
					libc.StrCpy(&v5[2], a2)
					nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 276)), 2064))), unsafe.Pointer(&v5[0]), 52, nil, 1)
				}
			}
		}
	}
}
func sub_4FB000(a1 *server.Object, a2 *server.Object) int32 {
	var (
		v2     unsafe.Pointer
		v3     *byte
		v4     int32
		result int32
	)
	if a1 != nil && a2 != nil && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 8)))&2 != 0 && (func() bool {
		v2 = a1.UpdateData
		v3 = nox_xxx_getUnitName_4E39D0(a2)
		return (func() int32 {
			v4 = nox_xxx_guide_427010(v3)
			return v4
		}()) != 0
	}()) {
		result = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), uint32(v4*4)+4244)))
	} else {
		result = 0
	}
	return result
}
func sub_4FB050(a1 *server.Object, a2 *server.Object, a3 *int32) {
	var (
		result int32
		v4     float32
	)
	result = sub_4FB000(a1, a2)
	if result == 0 {
		return
	}
	v4 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("FieldGuideDamageBonus"))*float64(*a3) + 0.5)
	result = int32(v4)
	*a3 = result
}
func Nox_xxx_playerDoSchedSpell_4FB0E0(a1p *server.Object, a2 *server.Object) int32 {
	var (
		v5 int32
		v6 *uint32
	)
	v2 := a1p
	ud := a1p.UpdateDataPlayer()
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(ud), 212))) == 0 {
		return 0
	}
	a1 := nox_xxx_checkPlrCantCastSpell_4FD150(a1p, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(ud), 192))), 0)
	var sa server.SpellAcceptArg
	sa.Obj = a2
	sa.Pos.X = float32(float64(ud.Field55))
	sa.Pos.Y = float32(float64(ud.Field56))
	if a1 != 0 {
		nox_xxx_netInformTextMsg_4DA0F0(int32(ud.Player.PlayerInd), 0, &a1)
		nox_xxx_aud_501960(231, v2, 0, 0)
	} else {
		nox_xxx_castSpellByUser_4FDD20(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(ud), 192))), v2, &sa)
	}
	v5 = 1
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(ud), 212))) > 1 {
		v6 = (*uint32)(unsafe.Add(unsafe.Pointer(ud), 192))
		for {
			v5++
			*v6 = *(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
			v6 = (*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
			if v5 >= int32(*(*uint8)(unsafe.Add(unsafe.Pointer(ud), 212))) {
				break
			}
		}
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(ud), v5*4+188)) = 0
	*(*uint8)(unsafe.Add(unsafe.Pointer(ud), 212))--
	return 1
}
func Nox_xxx_playerDoSchedSpellQueue_4FB1D0(a1p *server.Object, a2 *server.Object) int32 {
	v2 := a1p
	ud := a1p.UpdateDataPlayer()
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(ud), 212))) == 0 {
		return 0
	}
	a1 := nox_xxx_checkPlrCantCastSpell_4FD150(a1p, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(ud), int32(*(*uint8)(unsafe.Add(unsafe.Pointer(ud), 212)))*4+188))), 0)
	var v5 server.SpellAcceptArg
	v5.Obj = a2
	v5.Pos.X = float32(float64(ud.Field55))
	v5.Pos.Y = float32(float64(ud.Field56))
	if a1 != 0 {
		nox_xxx_netInformTextMsg_4DA0F0(int32(ud.Player.PlayerInd), 0, &a1)
		nox_xxx_aud_501960(231, v2, 0, 0)
	} else {
		nox_xxx_castSpellByUser_4FDD20(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(ud), int32(*(*uint8)(unsafe.Add(unsafe.Pointer(ud), 212)))*4+188))), v2, &v5)
	}
	*(*uint8)(unsafe.Add(unsafe.Pointer(ud), 212))--
	return 1
}
func nox_xxx_resetMapInit_4FC570(a1 int32) {
	nox_xxx_resetMapInit_1569652 = uint32(a1)
}
func sub_4FC580(a1 int32) {
	dword_5d4594_1569656 = uint32(a1)
}
func sub_4FC960(a1 *server.Object, a2 int8) {
	var (
		v4 int32
		v5 int32
	)
	result := nox_xxx_getFirstPlayerUnit_4DA7C0()
	for i := result; result != nil; i = result {
		if i != a1 {
			v5 = int32(i.NetCode)
			v4 = nox_xxx_spellGetPhoneme_4FE1C0(int32(a1.NetCode), a2)
			nox_xxx_aud_501960(v4, a1, 2, v5)
		}
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i)
	}
}
func nox_xxx_Fn_4FCAC0(a1 bool, a2 int32) int32 {
	sub_4FE8A0(a1)
	Nox_alloc_magicEnt_1569668.FreeAllObjects()
	Dword_5d4594_1569672 = nil
	for u := nox_xxx_getFirstPlayerUnit_4DA7C0(); u != nil; u = nox_xxx_getNextPlayerUnit_4DA7F0(u) {
		v3 := u.UpdateDataPlayer()
		v3.Field47_0 = 0
		v3.SpellCastStart = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 192)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 196)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 200)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 204)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 208)) = 0
		*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 212)) = 0
	}
	if a2 == 0 {
		return 1
	}
	if nox_setImaginaryCaster() == 0 {
		return 0
	}
	return 1
}
func nox_xxx_spellCastByBook_4FCB80() {
	var (
		v4  *server.PlayerUpdateData
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 *uint32
		v14 *server.Object
		v18 *MagicEntityClass
		v19 *byte
		v20 uint8
		v23 [2]byte
		v24 int32
		v25 int32
		v26 int32
		v27 int32
	)
	v0 := Dword_5d4594_1569672
	if Dword_5d4594_1569672 == nil {
		return
	}
	for {
		v1 := v0.Field4
		if v1.ObjFlags&0x8020 != 0 {
			v2 := v0.Field52
			if v2 != nil {
				v2.Field56 = v0.Field56
			}
			v3 := v0.Field56
			if v3 == nil {
				Dword_5d4594_1569672 = v0.Field52
			} else {
				v3.Field52 = v0.Field52
			}
			goto LABEL_40
		}
		if gameFrame() < uint32(v0.Field40) {
			v0 = v0.Field52
			goto LABEL_48
		}
		v4 = nil
		if v1.Class().Has(object.ClassPlayer) {
			v4 = v1.UpdateDataPlayer()
		}
		if int32(v0.Field36) == 0 {
			v23[0] = 112
			v5 := v4.Player
			v23[1] = *(*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(v0), uintptr(v0.Field28)*4), 8))
			nox_netlist_addToMsgListCli_40EBC0(int32(v5.PlayerInd), 1, &v23[0], 2)
		}
		v6 = int32(v0.Field28)
		v7 = v0.Field32.Ind
		v24 = int32(*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v0), uintptr(v6)*4), 8)))
		v8 = v24
		if v7 != v24 {
			v19 = (*byte)(sub_416640())
			*(*uint8)(unsafe.Pointer(&v27)) = uint8(nox_xxx_spellPhonemes_424A20(int32(*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v0), uintptr(int32(v0.Field28)*4)), 8))), int32(v0.Field36)))
			v20 = uint8(int8(v27))
			if dword_5d4594_2650652 == 0 || *(*uint32)(unsafe.Add(unsafe.Pointer(v19), 62)) != 0 {
				sub_4FC960(v0.Field4, int8(v27))
			}
			v21 := nox_xxx_updateSpellRelated_424830(v0.Field32, int32(v20))
			v22 := v0.Field4
			v0.Field32 = v21
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v22), 8)))&4 != 0 {
				v4.SpellPhonemeLeaf = v0.Field32
			}
			v0.Field36++
			v0.Field40 = gameFrame() + v0.Field44
			v0 = v0.Field52
			goto LABEL_48
		}
		v26 = int32(*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v0), uintptr(v6*4)), 12)))
		if int32(v0.Field29) == 0 {
			if v8 != 34 && v26 != 0 {
				v0.Field36 = 0
				v0.Field32 = nox_xxx_spellGetDefArrayPtr_424820()
				v0.Field40 = gameFrame() + v0.Field44
				v0.Field28++
				v0 = v0.Field52
				goto LABEL_48
			}
		} else if v24 != 34 {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v0.Field4), 8)))&4 != 0 {
				v9 = 0
				v10 = 1
				if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 212))) != 0 {
					v11 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 192))
					for {
						if *v11 == uint32(v8) {
							v12 := v4.Player
							v25 = 6
							nox_xxx_netInformTextMsg_4DA0F0(int32(v12.PlayerInd), 0, &v25)
							v8 = v24
							v10 = 0
						}
						v9++
						v11 = (*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
						if v9 >= int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 212))) {
							break
						}
					}
				}
				if v10 != 0 {
					if sub_4FCF90(v0.Field4, v8, 2) < 0 {
						v13 := v4.Player
						v25 = 11
						nox_xxx_netInformTextMsg_4DA0F0(int32(v13.PlayerInd), 0, &v25)
						nox_xxx_aud_501960(232, v0.Field4, 0, 0)
					} else {
						*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v4), uintptr(int32(func() uint8 {
							p := (*uint8)(unsafe.Add(unsafe.Pointer(v4), 212))
							x := *p
							*p++
							return x
						}())*4)), 192)) = uint32(v24)
					}
					v8 = v24
				}
			}
			if v8 != 34 && v26 != 0 {
				v0.Field36 = 0
				v0.Field32 = nox_xxx_spellGetDefArrayPtr_424820()
				v0.Field40 = gameFrame() + v0.Field44
				v0.Field28++
				v0 = v0.Field52
				goto LABEL_48
			}
		}
		v14 = v0.Field4
		if v14.ObjClass&4 != 0 {
			v15 := v4.Player
			v4.Field55 = v15.CursorVec.X
			v4.Field56 = v15.CursorVec.Y
			if v0.Field48 != 0 {
				v15.Obj3640 = v0.Field4
			} else {
				v15.Obj3640 = v4.CursorObj
			}
			nox_xxx_playerSpell_4FB2A0_magic_plyrspel(v0.Field4)
			v4.SpellCastStart = 0
			v4.Field47_0 = 0
			*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 212)) = 0
		} else {
			nox_xxx_castSpellByUser_4FDD20(v8, v14, nil)
		}
		if v16 := v0.Field52; v16 != nil {
			v16.Field56 = v0.Field56
		}

		if v17 := v0.Field56; v17 == nil {
			Dword_5d4594_1569672 = v0.Field52
		} else {
			v17.Field52 = v0.Field52
		}
	LABEL_40:
		v18 = v0.Field52
		Nox_alloc_magicEnt_1569668.FreeObjectFirst(v0)
		v0 = v18
	LABEL_48:
		if v0 == nil {
			return
		}
	}
}
func sub_4FCEB0(a1 bool) {
	var (
		v3 *server.Object
	)
	result := nox_xxx_spellCastedFirst_4FE930()
	if result == nil {
		return
	}
	for {
		v2 := result.Next
		if !a1 || (func() *server.Object {
			v3 = result.Target48
			return v3
		}()) == nil || (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 8)))&4) != 4 {
			nox_xxx_spellCancelSpellDo_4FE9D0(result)
		}
		result = v2
		if v2 == nil {
			break
		}
	}
}
func nox_xxx_spellCheckSmth_4FCEF0(a1 unsafe.Pointer, a2 *int32, a3 int32) int32 {
	var (
		v3 *int32
		v5 int32
		v6 int32
		v7 int32
		v8 int32
	)
	if a1 == nil {
		return 0
	}
	v3 = a2
	if a2 == nil {
		return 0
	}
	if a3 == 0 {
		return 0
	}
	if nox_common_getEngineFlag(NOX_ENGINE_FLAG_GODMODE) {
		return 1
	}
	if int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 {
		return 1
	}
	v5 = int32(uint16(nox_xxx_unitGetOldMana_4EEC80((*server.Object)(a1))))
	v6 = 0
	if a3 <= 0 {
		return 1
	}
	for {
		v7 = *v3
		if *v3 < 75 || v7 > 114 {
			v8 = nox_xxx_spellManaCost_4249A0(v7, 2)
		} else {
			v8 = sub_500CA0(v7, (*server.Object)(a1))
		}
		if v8 > v5 {
			break
		}
		v5 -= v8
		v6++
		v3 = (*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
		if v6 >= a3 {
			return 1
		}
	}
	return 0
}
func sub_4FCF90(a1 *server.Object, a2 int32, a3 int32) int32 {
	var (
		v3     *uint16
		result int32
		v5     int32
		v6     int32
	)
	v3 = (*uint16)(a1.UpdateData)
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8))) & 4) == 0 {
		return -1
	}
	if a2 == 0 {
		return -1
	}
	if nox_common_getEngineFlag(NOX_ENGINE_FLAG_GODMODE) {
		return 0
	}
	if a2 < 75 || a2 > 114 {
		v5 = nox_xxx_spellManaCost_4249A0(a2, a3)
	} else {
		v5 = sub_500CA0(a2, a1)
	}
	v6 = v5
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*2))) >= v5 {
		nox_xxx_playerManaSub_4EEBF0(a1, v5)
		result = v6
	} else {
		*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*40)) = uint16(int16(nox_xxx_spellManaCost_4249A0(a2, 1)))
		result = -1
		*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*41)) = uint16(gameFPS())
	}
	return result
}
func sub_4FD030(a1 *server.Object, a2 int16) {
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 {
		nox_xxx_playerManaAdd_4EEB80(a1, a2)
	}
}
func sub_4FD0E0(a1 *server.Object, a2 int32) int32 {
	var (
		v4 int32
	)
	nox_xxx_spellFlags_424A70(a2)
	v2 := nox_xxx_findParentChainPlayer_4EC580(a1)
	if !nox_xxx_spellIsEnabled_424B70(a2) {
		return 10
	}
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 {
		return nox_xxx_playerCheckSpellClass_57AEA0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 276)), 2251))), a2)
	}
	v4 = -sub_57AEE0(a2, v2)
	*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(v4 & 0xF6))
	return v4 + 10
}
func nox_xxx_checkPlrCantCastSpell_4FD150(a1 *server.Object, a2 int32, a3 int32) int32 {
	nox_xxx_findParentChainPlayer_4EC580(a1)
	if a3 != 0 {
		goto LABEL_9
	}
	if noxflags.HasGame(16) {
		if *memmap.PtrUint32(0x5D4594, 1569704) == 0 {
			*memmap.PtrUint32(0x5D4594, 1569704) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Crown")))
		}
		if nox_xxx_spellHasFlags_424A50(a2, 0x80000) {
			v3 := a1.Field129
			if v3 != nil {
				for uint32(v3.TypeInd) != *memmap.PtrUint32(0x5D4594, 1569704) {
					v3 = v3.Field128
					if v3 == nil {
						goto LABEL_9
					}
				}
				if nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(a1), 48))) != 0 {
					return 17
				}
			}
		}
		goto LABEL_9
	}
	if !noxflags.HasGame(64) {
		if !noxflags.HasGame(32) {
			goto LABEL_9
		}
		if !nox_xxx_spellHasFlags_424A50(a2, 0x80000) {
			goto LABEL_9
		}
		v6 := a1.InvFirstItem
		if v6 == nil {
			goto LABEL_9
		}
		for (v6.ObjClass & 0x10000000) == 0 {
			v6 = v6.InvNextItem
			if v6 == nil {
				goto LABEL_9
			}
		}
		return 13
	}
	if *memmap.PtrUint32(0x5D4594, 1569708) == 0 {
		*memmap.PtrUint32(0x5D4594, 1569708) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("GameBall")))
	}
	if nox_xxx_spellHasFlags_424A50(a2, 0x80000) {
		v5 := a1.Field129
		if v5 != nil {
			for uint32(v5.TypeInd) != *memmap.PtrUint32(0x5D4594, 1569708) {
				v5 = v5.Field128
				if v5 == nil {
					goto LABEL_9
				}
			}
			return 16
		}
	}
LABEL_9:
	if nox_xxx_testUnitBuffs_4FF350(a1, 29) != 0 {
		return 14
	}
	if sub_4D7100(a2) == 0 {
		return 10
	}
	switch a2 {
	case 29:
		if nox_xxx_unitIsUnitTT_4E7C80(a1, *memmap.PtrInt32(0x5D4594, 1569692)) > 0 {
			return 3
		}
		if nox_xxx_unitIsUnitTT_4E7C80(a1, *memmap.PtrInt32(0x5D4594, 1569688)) <= 0 {
			v10 := int32(*memmap.PtrUint32(0x5D4594, 1569684))
			v9 := nox_xxx_unitIsUnitTT_4E7C80(a1, v10)
			if v9 <= 0 {
				return 0
			}
		}
		return 3
	case 31:
		v9 := nox_xxx_unitIsUnitTT_4E7C80(a1, *memmap.PtrInt32(0x5D4594, 1569696))
		if v9 <= 0 {
			return 0
		}
		return 3
	case 50:
		v7 := nox_xxx_unitIsUnitTT_4E7C80(a1, *memmap.PtrInt32(0x5D4594, 1569680))
		v12 := nox_xxx_spellGetPower_4FE7B0(a2, a1) - 1
		v8 := nox_xxx_gamedataGetFloatTable_419D70(internCStr("MagicMissileCount"), v12)
		if v7 < int32(int64(v8)) {
			return 0
		}
		return 3
	case 52:
		v10 := int32(*memmap.PtrUint32(0x5D4594, 1569700))
		v9 := nox_xxx_unitIsUnitTT_4E7C80(a1, v10)
		if v9 <= 0 {
			return 0
		}
		return 3
	case 58:
		v7 := nox_xxx_unitIsUnitTT_4E7C80(a1, *memmap.PtrInt32(0x5D4594, 1569676))
		v11 := nox_xxx_spellGetPower_4FE7B0(a2, a1) - 1
		v8 := nox_xxx_gamedataGetFloatTable_419D70(internCStr("PixieCount"), v11)
		if v7 < int32(int64(v8)) {
			return 0
		}
		return 3
	default:
		return 0
	}
}
func nox_xxx_gameCaptureMagic_4FDC10(a1 int32, a2 *server.Object) int32 {
	if *memmap.PtrUint32(0x5D4594, 1569712) == 0 {
		*memmap.PtrUint32(0x5D4594, 1569712) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("GameBall")))
		*memmap.PtrUint32(0x5D4594, 1569716) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Crown")))
	}
	if a2 == nil {
		return 0
	}
	if !(nox_xxx_spellHasFlags_424A50(a1, 0x80000) && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 8)))&4 != 0) {
		return 1
	}
	v3 := a2.UpdateData
	if noxflags.HasGame(32) {
		if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 4)))&1 != 0 {
			return 0
		}
	} else if noxflags.HasGame(64) {
		v4 := a2.Field129
		if v4 != nil {
			for uint32(v4.TypeInd) != *memmap.PtrUint32(0x5D4594, 1569712) {
				v4 = v4.Field128
				if v4 == nil {
					return 1
				}
			}
			return 0
		}
	} else if noxflags.HasGame(16) {
		v5 := a2.Field129
		if v5 != nil {
			for uint32(v5.TypeInd) != *memmap.PtrUint32(0x5D4594, 1569716) || nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(a2), 48))) == 0 {
				v5 = v5.Field128
				if v5 == nil {
					return 1
				}
			}
			return 0
		}
	}
	return 1
}
func nox_xxx_createSpellFly_4FDDA0(a1 *server.Object, a2 *server.Object, a3 int32) {
	var (
		v5  *server.Object
		v6  int32
		v7  float32
		v8  float64
		v9  float64
		v10 float64
		v14 int16
		v18 int32
		v19 int32
		v21 Point32
		v22 float4
		a2a float32
	)
	v3 := a1
	a2a = float32(float64(a1.Shape.Circle.R) + 4.0)
	if a2 == nil {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 8)))&4 != 0 {
			v4 := v3.UpdateData
			*(*float32)(unsafe.Pointer(&v21.X)) = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 2284))))
			*(*float32)(unsafe.Pointer(&v21.Y)) = float32(float64(*(*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 2288))))
			v18 = int32(nox_xxx_spellFlags_424A70(a3))
			v5 = nox_xxx_spellFlySearchTarget_540610((*types.Pointf)(unsafe.Pointer(&v21)), v3, v18, 600.0, 0, v3)
		} else {
			v19 = int32(nox_xxx_spellFlags_424A70(a3))
			v5 = nox_xxx_spellFlySearchTarget_540610(nil, v3, v19, 600.0, 0, v3)
		}
		a2 = v5
	}
	v6 = int32(v3.Direction1) * 8
	v7 = v3.PosVec.Y
	v8 = float64(a2a * *memmap.PtrFloat32(0x587000, uintptr(uint32(v6)+194136)))
	v22.field_0 = v3.PosVec.X
	v9 = v8 + float64(v3.PosVec.X)
	v10 = float64(a2a * *memmap.PtrFloat32(0x587000, uintptr(uint32(v6)+194140)))
	v22.field_4 = v7
	v22.field_C = float32(v10 + float64(v3.PosVec.Y))
	v22.field_8 = float32(v9 + float64(v3.VelVec.X))
	v22.field_C = v22.field_C + v3.VelVec.Y
	if nox_xxx_mapTraceRay_535250(&v22, nil, nil, 5) == 0 {
		return
	}
	v12 := nox_xxx_newObjectByTypeID_4E3810(internCStr("Magic"))
	if v12 == nil {
		return
	}
	v13 := v12.UpdateData
	*(*int32)(unsafe.Add(v13, 4*4)) = nox_xxx_spellGetPower_4FE7B0(a3, v3)
	nox_xxx_createAt_4DAA50(v12, v3, v22.field_8, v22.field_C)
	v14 = int16(v3.Direction1)
	v12.Direction1 = server.Dir16(uint16(v14))
	v12.Direction2 = server.Dir16(uint16(v14))
	*(**server.Object)(v13) = v3
	*(**server.Object)(unsafe.Add(v13, 4*1)) = a2
	*(**server.Object)(unsafe.Add(v13, 4*2)) = v3
	*(*int32)(unsafe.Add(v13, 4*3)) = a3
	nox_xxx_xferIndexedDirection_509E20(int32(v3.Direction1), &v21)
	v15 := int32(v12.Direction1)
	v12.VelVec.X = *memmap.PtrFloat32(0x587000, uintptr(v15)*8+194136) * v12.SpeedCur
	v12.VelVec.Y = *memmap.PtrFloat32(0x587000, uintptr(v15)*8+194140) * v12.SpeedCur
	v12.VelVec.X = v12.VelVec.X + v3.VelVec.X
	v12.VelVec.Y = v12.VelVec.Y + v3.VelVec.Y
	if nox_xxx_testUnitBuffs_4FF350(v3, 21) != 0 {
		v20 := nox_xxx_buffGetPower_4FF570(v3, 21)
		v16 := int16(nox_xxx_unitGetBuffTimer_4FF550(v3, 21))
		nox_xxx_buffApplyTo_4FF380(v12, 21, v16, v20)
	}
	v17 := nox_xxx_spellGetAud44_424800(a3, 0)
	nox_xxx_aud_501960(v17, v3, 0, 0)
}
func nox_xxx_collide_4FDF90(a1 *server.Object, a2 *server.Object) {
	var (
		v2     int32
		v3     int32
		result int32
		v5     float32
	)
	if nox_xxx_testUnitBuffs_4FF350(a1, 22) != 0 && (a2.ObjFlags&0x8008) == 0 && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 8)))&6 != 0 && nox_xxx_unitIsEnemyTo_5330C0(a1, a2) != 0 {
		v2 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 430))) - 1
		nox_xxx_aud_501960(135, a1, 0, 0)
		nox_xxx_spellBuffOff_4FF5B0(a1, 22)
		v5 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("ShockDamage"), v2))
		v3 = int32(v5)
		a2.Damage.Get()(a2, a1, a1, int(v3), 9)
	}
	result = int32(a2.ObjClass)
	if uint32(result)&0x20006 != 0 {
		if (a2.ObjFlags & 0x8020) == 0 {
			if nox_xxx_unitsHaveSameTeam_4EC520(a2, a1) == 0 {
				nox_xxx_spellBuffOff_4FF5B0(a1, 0)
			}
		}
	}
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 && a2.ObjClass&0x20000 != 0 && (a2.ObjFlags&0x8020) == 0 {
		nox_xxx_spellBuffOff_4FF5B0(a1, 0)
	}
}
func nox_xxx_spellGetPhoneme_4FE1C0(a1 int32, a2 int8) int32 {
	var v2 *byte
	if noxflags.HasGame(1) {
		if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(uint32(a1))), unsafe.Sizeof(server.Object{})*8))) & 4) == 0 {
			switch a2 {
			case 0:
				return 193
			case 1:
				return 186
			case 2:
				return 187
			case 3:
				return 192
			case 5:
				return 188
			case 6:
				return 191
			case 7:
				return 190
			case 8:
				return 189
			default:
				return 0
			}
		}
	} else if (nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(a1)).ObjClass & 4) == 0 {
		switch a2 {
		case 0:
			return 193
		case 1:
			return 186
		case 2:
			return 187
		case 3:
			return 192
		case 5:
			return 188
		case 6:
			return 191
		case 7:
			return 190
		case 8:
			return 189
		default:
			return 0
		}
	}
	v2 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(a1)))
	if v2 == nil {
		return 0
	}
	if *(*byte)(unsafe.Add(unsafe.Pointer(v2), 2252)) == 0 {
		switch a2 {
		case 0:
			return 193
		case 1:
			return 186
		case 2:
			return 187
		case 3:
			return 192
		case 5:
			return 188
		case 6:
			return 191
		case 7:
			return 190
		case 8:
			return 189
		default:
			return 0
		}
	}
	switch a2 {
	case 0:
		return 201
	case 1:
		return 194
	case 2:
		return 195
	case 3:
		return 200
	case 5:
		return 196
	case 6:
		return 199
	case 7:
		return 198
	case 8:
		return 197
	default:
		return 0
	}
}

type MagicEntityClass struct {
	Field0  uint32              // 0, 0
	Field4  *server.Object      // 1, 4
	Field8  [5]int32            // 2, 8
	Field28 byte                // 7, 28
	Field29 byte                // 7, 29
	Field30 uint16              // 7, 30
	Field32 *server.PhonemeLeaf // 8, 32
	Field36 byte                // 9, 36
	Field37 byte                // 9, 37
	Field38 uint16              // 9, 38
	Field40 uint32              // 10, 40
	Field44 uint32              // 11, 44
	Field48 uint32              // 12, 48
	Field52 *MagicEntityClass   // 13, 52
	Field56 *MagicEntityClass   // 14, 56
}

func nox_xxx_spellByBookInsert_4FE340(a1p *server.Object, a2 *int32, a3 int32, a4 int32, a5 int32) int32 {
	var (
		a1  int32
		v10 int32
		v11 *int32
		v12 *int32
		v13 int32
		v15 uint8
		v16 int32
		v17 *int32
		v18 int32
		v19 int32
		v21 int32
		v22 int32
		v26 int32
	)
	v5 := a1p
	if a1p.ObjFlags&0x8022 != 0 {
		return 0
	}
	v6 := unsafe.Slice(a2, 5)
	for _, v := range v6 {
		if v < 0 || v >= 137 {
			return 0
		}
	}
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1p), 8))) & 4) == 0 {
		return 0
	}
	v9 := a1p.UpdateData
	if *(*uint32)(unsafe.Add(v9, 280)) != 0 {
		return 0
	}
	v10 = 0
	v11 = a2
	for {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v9, 276))+uint32(*v11*4))), 3696)) == 0 && *v11 != 0 {
			return 0
		}
		v10++
		v11 = (*int32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
		if v10 >= 5 {
			break
		}
	}
	if *(*uint32)(unsafe.Add(v9, 216)) != 0 {
		return 0
	}
	v26 = 0
	if a3 > 0 {
		v12 = a2
		v13 = a3
		for {
			if *v12 == 34 {
				v26 = 1
			}
			v12 = (*int32)(unsafe.Add(unsafe.Pointer(v12), 4*1))
			v13--
			if v13 == 0 {
				break
			}
		}
		if v26 != 0 {
			if nox_xxx_spellCheckSmth_4FCEF0(unsafe.Pointer(a1p), a2, a3) == 0 {
				a1 := int32(12)
				nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v9, 276)), 2064))), 0, &a1)
				nox_xxx_aud_501960(232, v5, 0, 0)
				return 0
			}
			if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v9, 276)), 2251))) == 2 {
				v15 = uint8(int8(bool2int32(nox_xxx_checkSummonedCreaturesLimit_500D70(v5, 5))))
				if int32(v15) == 0 {
					a1 := int32(4)
					nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v9, 276)), 2064))), 0, &a1)
					nox_xxx_aud_501960(231, v5, 0, 0)
					return 0
				}
				v16 = nox_xxx_unitCountSlaves_4E7CF0(v5, 2, 0x2000)
				if v16 >= int32(int64(nox_xxx_gamedataGetFloat_419D40(internCStr("MaxBomberCount")))) {
					a1 := int32(5)
					nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v9, 276)), 2064))), 0, &a1)
					nox_xxx_aud_501960(231, v5, 0, 0)
					return 0
				}
			} else if int32(*(*uint8)(unsafe.Add(v9, 244))) >= int32(int64(nox_xxx_gamedataGetFloat_419D40(internCStr("MaxTrapCount")))) {
				a1 := int32(5)
				nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v9, 276)), 2064))), 0, &a1)
				nox_xxx_aud_501960(231, v5, 0, 0)
				return 0
			}
			v17 = a2
			v18 = 0
			for {
				a1 := sub_4FD0E0(v5, *v17)
				if a1 != 0 {
					nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v9, 276)), 2064))), 0, &a1)
					nox_xxx_aud_501960(231, v5, 0, 0)
					return 0
				}
				a1 = nox_xxx_checkPlrCantCastSpell_4FD150(v5, *v17, v26)
				if a1 != 0 {
					nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v9, 276)), 2064))), 0, &a1)
					nox_xxx_aud_501960(231, v5, 0, 0)
					return 0
				}
				v18++
				v17 = (*int32)(unsafe.Add(unsafe.Pointer(v17), 4*1))
				if v18 >= a3 {
					goto LABEL_36
				}
			}
		}
	}
	a1 = sub_4FD0E0(a1p, *a2)
	if a1 != 0 {
		nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v9, 276)), 2064))), 0, &a1)
		nox_xxx_aud_501960(231, v5, 0, 0)
		return 0
	}
	a1 = nox_xxx_checkPlrCantCastSpell_4FD150(v5, v6[0], 0)
	if a1 != 0 {
		nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v9, 276)), 2064))), 0, &a1)
		nox_xxx_aud_501960(231, v5, 0, 0)
		return 0
	}
LABEL_36:
	nox_xxx_playerSetState_4FA020(v5, 2)
	v19 = int32(gameFrame())
	*(*uint8)(unsafe.Add(v9, 188)) = 1
	*(*uint32)(unsafe.Add(v9, 216)) = uint32(v19)
	v20 := Nox_alloc_magicEnt_1569668.NewObject()
	if v20 == nil {
		return 0
	}
	v21 = a5
	v22 = a4
	v20.Field4 = v5
	v20.Field48 = uint32(v21)
	v20.Field36 = 0
	v20.Field40 = gameFrame()
	v20.Field44 = uint32(v22)
	v20.Field32 = nox_xxx_spellGetDefArrayPtr_424820()
	v20.Field28 = 0
	v20.Field29 = 0

	v24 := v6[:a3]
	for i := range v20.Field8 {
		if i >= len(v24) {
			v20.Field8[i] = 0
		} else {
			v20.Field8[i] = v24[i]
			if v24[i] == 34 {
				v20.Field29 = 1
			}
		}
	}
	v20.Field56 = nil
	v20.Field52 = Dword_5d4594_1569672
	if Dword_5d4594_1569672 != nil {
		Dword_5d4594_1569672.Field56 = v20
	}
	Dword_5d4594_1569672 = v20
	return 1
}
func nox_xxx_spell_4FE680(a1 *server.Object, a2 float32) {
	var (
		v6 float64
		v7 float64
	)
	v2 := Dword_5d4594_1569672
	if v2 != nil {
		v3 := a1
		for {
			v4 := v2.Field4
			if ((int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 8)))&4) != 4 || nox_xxx_servCompareTeams_419150((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(v3), 48)), (*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(v4), 48))) == 0) && (func() bool {
				v5 := v2.Field4
				v6 = float64(v5.PosVec.X - v3.PosVec.X)
				v7 = float64(v5.PosVec.Y - v3.PosVec.Y)
				return math.Sqrt(v7*v7+v6*v6)+0.1 < float64(a2)
			}()) && nox_xxx_mapCheck_537110(v3, v2.Field4) != 0 {
				v8 := v2.Field4
				if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v8), 8))) & 4) == 4 {
					v9 := v8.UpdateData
					*(*uint32)(unsafe.Add(v9, 216)) = 0
					*(*uint8)(unsafe.Add(v9, 188)) = 0
					a1 := int32(15)
					nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v9, 276)), 2064))), 0, &a1)
					nox_xxx_aud_501960(231, v2.Field4, 0, 0)
					nox_xxx_playerSetState_4FA020(v2.Field4, 13)
				}
				v10 := v2.Field52
				if v10 != nil {
					v10.Field56 = v2.Field56
				}
				v11 := v2.Field56
				if v11 != nil {
					v11.Field52 = v2.Field52
				} else {
					Dword_5d4594_1569672 = v2.Field52
				}
				v12 := v2.Field52
				Nox_alloc_magicEnt_1569668.FreeObjectFirst(v2)
				v2 = v12
			} else {
				v2 = v2.Field52
			}
			if v2 == nil {
				break
			}
		}
	}
}
func nox_xxx_spellGetPower_4FE7B0(a1 int32, a2p *server.Object) int32 {
	var (
		a2 = a2p
		v2 int32
		v4 int32
	)
	v2 = int32(*memmap.PtrUint32(0x5D4594, 1569720))
	if *memmap.PtrUint32(0x5D4594, 1569720) == 0 {
		v2 = nox_xxx_getNameId_4E3AA0(internCStr("ImaginaryCaster"))
		*memmap.PtrUint32(0x5D4594, 1569720) = uint32(v2)
	}
	if int32(a2.TypeInd) == v2 {
		return 1
	}
	if noxflags.HasGame(1392) {
		return 3
	}
	if a2 == nil {
		return 2
	}
	v4 = int32(a2.ObjClass)
	if v4&4 != 0 {
		return int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(a2.UpdateData, 276))+uint32(a1*4))), 3696)))
	}
	if (v4 & 2) == 0 {
		return 3
	} else {
		return int32(*(*uint32)(unsafe.Add(a2.UpdateData, 2040)))
	}
}
func nox_xxx_spellCancelSpellDo_4FE9D0(a1 *server.DurSpell) {
	obj := a1.Caster16
	spl := spell.ID(a1.Spell)
	if obj != nil && obj.Class().Has(object.ClassPlayer) {
		v3 := obj.UpdateDataPlayer()
		if spl == spell.SPELL_CHAIN_LIGHTNING {
			nox_xxx_netReportSpellStat_4D9630(int32(v3.Player.PlayerInd), int32(spl), 0)
		} else {
			nox_xxx_netReportSpellStat_4D9630(int32(v3.Player.PlayerInd), int32(spl), 15)
		}
	}
	if spl == spell.SPELL_CHAIN_LIGHTNING {
		for i := a1.Sub108; i != nil; i = i.Next {
			if i.Target48 != nil {
				nox_xxx_netStopRaySpell_4FEF90(i, i.Target48)
			}
		}
	} else if a1.Target48 != nil {
		nox_xxx_netStopRaySpell_4FEF90(a1, a1.Target48)
	}
	a1.Flags88 |= 1
}
func sub_4FEA70(a1 *server.Object, a2 *types.Pointf) int32 {
	var (
		v2 float64
		v3 float64
		v5 float32
	)
	v2 = float64(a2.X - a1.PosVec.X)
	if v2 < 0.0 {
		v2 = -v2
	}
	v5 = float32(v2)
	v3 = float64(a2.Y - a1.PosVec.Y)
	if v3 < 0.0 {
		v3 = -v3
	}
	return bool2int32(float64(v5) >= 5.0 || v3 >= 5.0)
}
func nox_xxx_playerCancelSpells_4FEAE0(a1 *server.Object) {
	it := nox_xxx_spellCastedFirst_4FE930()
	if it == nil {
		return
	}
	for {
		next := it.Next
		if it.Caster16 == a1 {
			nox_xxx_spellCancelSpellDo_4FE9D0(it)
		}
		it = next
		if next == nil {
			break
		}
	}
}

// sub_4FEB60 cancels channeling spells associated with a wand weapon.
func sub_4FEB60(obj *server.Object, item *server.Object) {
	if item.Class().Has(object.ClassWand) {
		if item.SubClass().AsWeapon().Has(object.WeaponStaffLightning) {
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_CHAIN_LIGHTNING, obj)
		}
		if item.SubClass().AsWeapon().Has(object.WeaponStaffOblivionOrb) {
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_PLASMA, obj)
		}
	}
}
func Nox_xxx_plrCastSmth_4FEDA0(sp *server.DurSpell) {
	if sp.Caster16 != nil {
		snd := nox_xxx_spellGetAud44_424800(int32(sp.Spell), 2)
		nox_xxx_aud_501960(snd, sp.Caster16, 0, 0)
	}
	if destroy := sp.Destroy.Get(); destroy != nil {
		destroy(sp)
	}
	if u := sp.Caster16; u != nil {
		if u.Class().Has(object.ClassPlayer) {
			ud := u.UpdateDataPlayer()
			if ud.Player.PlayerClass() != player.Warrior || nox_common_playerIsAbilityActive_4FC250(u, 1) == 0 {
				nox_xxx_playerSetState_4FA020(u, 13)
				sub_4FE900(sp)
				sub_4FE980(sp)
				return
			}
		} else if u.Class().Has(object.ClassMonster) {
			sub_541630(u, int32(sp.Spell))
		}
	}
	sub_4FE900(sp)
	sub_4FE980(sp)
}
func nox_xxx_cancelAllSpells_4FEE90(obj *server.Object) {
	var next *server.DurSpell
	for it := nox_xxx_spellCastedFirst_4FE930(); it != nil; it = next {
		next = nox_xxx_spellCastedNext_4FE940(it)
		if it.Caster16 == obj {
			switch spell.ID(it.Spell) {
			case spell.SPELL_LIGHTNING, spell.SPELL_CHAIN_LIGHTNING,
				spell.SPELL_GREATER_HEAL, spell.SPELL_CHANNEL_LIFE, spell.SPELL_DRAIN_MANA,
				spell.SPELL_PLASMA, spell.SPELL_OVAL_SHIELD:
				nox_xxx_spellCancelSpellDo_4FE9D0(it)
			}
		}
	}
}
func nox_xxx_netStopRaySpell_4FEF90(a1 *server.DurSpell, a2 *server.Object) {
	if a1 == nil {
		return
	}
	v2 := a1.Caster16
	if v2 == nil {
		return
	}
	if a2 == nil {
		return
	}
	var buf [7]byte
	buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
	switch spell.ID(a1.Spell) {
	case spell.SPELL_CHAIN_LIGHTNING_BOLT:
		buf[1] = 10
		buf[2] = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8))
	case spell.SPELL_CHARM:
		buf[1] = 9
		buf[2] = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8))
	case spell.SPELL_DRAIN_MANA:
		buf[1] = 12
		buf[2] = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8))
	case spell.SPELL_LIGHTNING:
		buf[1] = 11
		buf[2] = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8))
	case spell.SPELL_GREATER_HEAL:
		if v2 == a1.Target48 {
			return
		}
		buf[1] = 13
		buf[2] = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8))
		*(*uint16)(unsafe.Pointer(&buf[3])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(a2))
		*(*uint16)(unsafe.Pointer(&buf[5])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(a1.Caster16))
		nox_xxx_netSendPacket1_4E5390(math.MaxUint8, unsafe.Pointer(&buf[0]), 7, nil, 1)
		nox_xxx_netUnmarkMinimapSpec_417470(a1.Caster16, 2)
		nox_xxx_netUnmarkMinimapSpec_417470(a2, 2)
		return
	case spell.SPELL_CHAIN_LIGHTNING:
		for i := a1.Sub108; i != nil; i = i.Next {
			nox_xxx_netStopRaySpell_4FEF90(i, i.Target48)
		}
		return
	case spell.SPELL_PLASMA:
		buf[1] = 8
		buf[2] = *(*uint8)(unsafe.Add(unsafe.Pointer(v2), 124))
	default:
		return
	}
	*(*uint16)(unsafe.Pointer(&buf[5])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(a2))
	*(*uint16)(unsafe.Pointer(&buf[3])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(a1.Caster16))
	nox_xxx_netSendPacket1_4E5390(math.MaxUint8, unsafe.Pointer(&buf[0]), 7, nil, 1)
	nox_xxx_netUnmarkMinimapSpec_417470(a1.Caster16, 2)
	nox_xxx_netUnmarkMinimapSpec_417470(a2, 2)
}
func nox_xxx_netStartDurationRaySpell_4FF130(a1 *server.DurSpell) {
	var buf [7]byte
	buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
	switch spell.ID(a1.Spell) {
	case spell.SPELL_CHAIN_LIGHTNING_BOLT:
		v4 := int8(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))
		buf[1] = 3
		buf[2] = byte(v4)
	case spell.SPELL_CHARM:
		buf[1] = 2
		buf[2] = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8))
	case spell.SPELL_DRAIN_MANA:
		buf[1] = 5
		buf[2] = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8))
	case spell.SPELL_LIGHTNING:
		v5 := int8(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))
		buf[1] = 4
		buf[2] = byte(v5)
	case spell.SPELL_GREATER_HEAL:
		if a1.Caster16 == a1.Target48 {
			return
		}
		v10 := a1.Target48
		buf[1] = 6
		*(*uint16)(unsafe.Pointer(&buf[3])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(v10))
		v8 := int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0(a1.Caster16)))
		v9 := int8(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))
		*(*uint16)(unsafe.Pointer(&buf[5])) = uint16(v8)
		buf[2] = byte(v9)
		nox_xxx_netSendPacket1_4E5390(math.MaxUint8, unsafe.Pointer(&buf[0]), 7, nil, 1)
		nox_xxx_netMarkMinimapForAll_4174B0(a1.Caster16, 2)
		nox_xxx_netMarkMinimapForAll_4174B0(a1.Target48, 2)
		return
	case spell.SPELL_CHAIN_LIGHTNING:
		for i := a1.Sub108; i != nil; i = i.Next {
			nox_xxx_netStartDurationRaySpell_4FF130(i)
		}
		return
	case spell.SPELL_PLASMA:
		v2 := a1.Caster16
		buf[1] = 1
		buf[2] = *(*uint8)(unsafe.Add(unsafe.Pointer(v2), 124))
	default:
		return
	}
	if a1.Target48 == nil {
		return
	}
	v7 := a1.Caster16
	*(*uint16)(unsafe.Pointer(&buf[3])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(v7))
	*(*uint16)(unsafe.Pointer(&buf[5])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(a1.Target48))
	nox_xxx_netSendPacket1_4E5390(math.MaxUint8, unsafe.Pointer(&buf[0]), 7, nil, 1)
	nox_xxx_netMarkMinimapForAll_4174B0(a1.Caster16, 2)
	nox_xxx_netMarkMinimapForAll_4174B0(a1.Target48, 2)
}
func sub_4FF2D0(a1 uint32, a2 *server.Object) *server.DurSpell {
	for it := nox_xxx_spellCastedFirst_4FE930(); it != nil; it = nox_xxx_spellCastedNext_4FE940(it) {
		if it.Flags88&0x1 == 0 && it.Spell == a1 {
			if v3 := it.Target48; v3 != nil && v3 == a2 {
				return it
			}
		}
	}
	return nil
}
func nox_xxx_testUnitBuffs_4FF350(obj *server.Object, buff server.EnchantID) int32 {
	return bool2int32(obj.HasEnchant(buff))
}
func nox_xxx_buffApplyTo_4FF380(obj *server.Object, buff server.EnchantID, dur int16, power int8) {
	if *memmap.PtrUint32(0x5D4594, 1569740) == 0 {
		*memmap.PtrUint32(0x5D4594, 1569740) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Hecubah")))
		*memmap.PtrUint32(0x5D4594, 1569744) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Necromancer")))
	}
	if obj == nil {
		return
	}
	if uint32(obj.TypeInd) == *memmap.PtrUint32(0x5D4594, 1569740) && buff == server.ENCHANT_ANTI_MAGIC {
		return
	}
	if noxflags.HasGame(4096) && uint32(obj.TypeInd) == *memmap.PtrUint32(0x5D4594, 1569740) && buff == server.ENCHANT_CONFUSED {
		nox_xxx_aud_501960(582, obj, 0, 0)
		return
	}
	if noxflags.HasGame(4096) && uint32(obj.TypeInd) == *memmap.PtrUint32(0x5D4594, 1569744) && buff == server.ENCHANT_CONFUSED {
		nox_xxx_aud_501960(595, obj, 0, 0)
		return
	}
	if obj.Class().Has(object.ClassMonster) && obj.SubClass().AsMonster().Has(object.MonsterImmuneFear) && buff == server.ENCHANT_AFRAID && !noxflags.HasGame(2048) {
		if uint32(obj.TypeInd) == *memmap.PtrUint32(0x5D4594, 1569740) {
			nox_xxx_aud_501960(582, obj, 0, 0)
		} else if uint32(obj.TypeInd) == *memmap.PtrUint32(0x5D4594, 1569744) {
			nox_xxx_aud_501960(595, obj, 0, 0)
		}
		return
	}
	if obj.Flags().HasAny(object.FlagDead | object.FlagDestroyed | object.FlagNoUpdate) {
		return
	}
	if nox_xxx_testUnitBuffs_4FF350(obj, buff) == 0 || nox_xxx_unitGetBuffTimer_4FF550(obj, buff) != 0 {
		if buff != 0 {
			nox_xxx_spellBuffOff_4FF5B0(obj, 0)
		}
		obj.BuffsDur[buff] = uint16(dur)
		obj.BuffsPower[buff] = uint8(power)
		nox_xxx_setUnitBuffFlags_4E48F0(obj, uint32(1<<buff)|obj.Buffs)
		sp := nox_xxx_getEnchantSpell_424920(buff)
		aud := nox_xxx_spellGetAud44_424800(sp, 1)
		nox_xxx_aud_501960(aud, obj, 0, 0)
	}
}
func nox_xxx_unitGetBuffTimer_4FF550(unit *server.Object, buff server.EnchantID) int32 {
	return int32(unit.EnchantDur(buff))
}
func nox_xxx_buffGetPower_4FF570(unit *server.Object, buff server.EnchantID) int8 {
	return int8(unit.EnchantPower(buff))
}
func nox_xxx_unitClearBuffs_4FF580(obj *server.Object) {
	nox_xxx_setUnitBuffFlags_4E48F0(obj, 0)
	for i := int32(0); i < 32; i++ {
		obj.BuffsDur[i] = 0
		obj.BuffsPower[i] = 0
	}
}
func nox_xxx_spellBuffOff_4FF5B0(obj *server.Object, enc server.EnchantID) {
	bit := uint32(1) << enc
	buffs := obj.Buffs
	if buffs&bit == 0 {
		return
	}
	nox_xxx_setUnitBuffFlags_4E48F0(obj, buffs&^bit)
	obj.BuffsDur[enc] = 0
	obj.BuffsPower[enc] = 0
	if enc == server.ENCHANT_DEATH || enc == server.ENCHANT_CROWN {
		return
	}
	sp := nox_xxx_getEnchantSpell_424920(enc)
	aud := nox_xxx_spellGetAud44_424800(sp, 2)
	nox_xxx_aud_501960(aud, obj, 0, 0)
}
func nox_xxx_updateUnitBuffs_4FF620(a1p *server.Object) {
	var (
		a1 = unsafe.Pointer(a1p)
		v1 int32
		v2 uint16
		v3 int16
		v4 int32
	)
	if *(*uint32)(unsafe.Add(a1, 340)) != 0 {
		v1 = 0
		for {
			if uint32(1<<v1)&*(*uint32)(unsafe.Add(a1, 340)) != 0 {
				if v1 == 16 && uint32(*(*uint16)(unsafe.Add(a1, 376)))%gameFPS() == gameFPS()-1 {
					nox_xxx_aud_501960(26, (*server.Object)(a1), 0, 0)
				}
				v2 = *(*uint16)(unsafe.Add(a1, v1*2+344))
				if int32(v2) > 0 {
					v3 = int16(int32(v2) - 1)
					*(*uint16)(unsafe.Add(a1, v1*2+344)) = uint16(v3)
					if int32(v3) == 0 {
						if v1 == 7 {
							v4 = int32(*(*uint32)(unsafe.Add(a1, 16)))
							*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(v4 & 0xBF))
							*(*uint32)(unsafe.Add(a1, 16)) = uint32(v4)
						} else if v1 == 16 {
							*(*uint32)(unsafe.Add(a1, 520)) = 0
							*(*uint32)(unsafe.Add(a1, 524)) = 13
							nox_xxx_unitDamageClear_4EE5E0((*server.Object)(a1), 9999999)
							nox_xxx_aud_501960(779, (*server.Object)(a1), 0, 0)
							if int32(*(*uint8)(unsafe.Add(a1, 8)))&4 != 0 {
								nox_xxx_playerIncrementElimDeath_4D8D40(a1)
								nox_xxx_netReportLesson_4D8EF0((*server.Object)(a1))
							}
						}
						nox_xxx_spellBuffOff_4FF5B0((*server.Object)(a1), server.EnchantID(v1))
						*(*uint8)(unsafe.Add(a1, v1+408)) = 0
					}
				}
			}
			v1++
			if v1 >= 32 {
				break
			}
		}
		if nox_xxx_testUnitBuffs_4FF350((*server.Object)(a1), 9) != 0 {
			*(*float32)(unsafe.Add(a1, 544)) = float32(float64(*(*float32)(unsafe.Add(a1, 544))) * 1.25)
		}
	}
}

func nox_xxx_journalQuestSet_500540(a1 *byte, a2 int32) {
	p := nox_xxx_scriptGetJournal_5005E0(a1)
	if p != nil {
		p.Value136 = uint32(a2)
	} else {
		p, _ = alloc.New(Journal{})
		v3 := p
		if p != nil {
			libc.StrCpy(&p.Field0[0], (*byte)(memmap.PtrOff(0x5D4594, 1570140)))
			p.Field132 = 0
			p.Value136 = uint32(a2)
			p.Field144 = nil
			p.Field140 = dword_5d4594_1570272
			p = dword_5d4594_1570272
			if dword_5d4594_1570272 != nil {
				dword_5d4594_1570272.Field144 = v3
			}
			dword_5d4594_1570272 = v3
		}
	}
}
func nox_xxx_scriptGetJournal_5005E0(a1 *byte) *Journal {
	var (
		v1 uint32
		v2 *uint8
		v3 *uint8
		v4 *byte
		v5 int8
		v6 uint32
		v7 int8
	)
	if libc.StrChr(a1, 58) != nil {
		v6 = uint32(libc.StrLen(a1) + 1)
		v7 = int8(uint8(v6))
		v6 >>= 2
		alloc.Memcpy(memmap.PtrOff(0x5D4594, 1570140), unsafe.Pointer(a1), uintptr(v6*4))
		v4 = (*byte)(unsafe.Add(unsafe.Pointer(a1), v6*4))
		v3 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v6)*4+1570140))
		v5 = v7
	} else {
		libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, 1570140)), (*byte)(memmap.PtrOff(0x5D4594, 1570008)))
		*memmap.PtrUint16(0x5D4594, uintptr(libc.StrLen((*byte)(memmap.PtrOff(0x5D4594, 1570140)))+1570140)) = *memmap.PtrUint16(0x587000, 217952)
		v1 = uint32(libc.StrLen(a1) + 1)
		v2 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(libc.StrLen((*byte)(memmap.PtrOff(0x5D4594, 1570140)))+1570140)))
		alloc.Memcpy(unsafe.Pointer(v2), unsafe.Pointer(a1), uintptr((v1>>2)*4))
		v4 = (*byte)(unsafe.Add(unsafe.Pointer(a1), (v1>>2)*4))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), (v1>>2)*4))
		v5 = int8(uint8(v1))
	}
	alloc.Memcpy(unsafe.Pointer(v3), unsafe.Pointer(v4), uintptr(int32(v5)&3))
	var it *Journal
	for it = dword_5d4594_1570272; it != nil; it = it.Field140 {
		if nox_strcmpi(&it.Field0[0], (*byte)(memmap.PtrOff(0x5D4594, 1570140))) == 0 {
			break
		}
	}
	return it
}
func nox_xxx_journalQuestSetBool_5006B0(a1 *byte, a2 int32) {
	p := nox_xxx_scriptGetJournal_5005E0(a1)
	if p != nil {
		p.Value136 = uint32(a2)
	} else {
		p, _ = alloc.New(Journal{})
		v3 := p
		if p != nil {
			libc.StrCpy(&p.Field0[0], (*byte)(memmap.PtrOff(0x5D4594, 1570140)))
			p.Field132 = 1
			p.Value136 = uint32(a2)
			p.Field144 = nil
			p.Field140 = dword_5d4594_1570272
			p = dword_5d4594_1570272
			if dword_5d4594_1570272 != nil {
				dword_5d4594_1570272.Field144 = v3
			}
			dword_5d4594_1570272 = v3
		}
	}
}
func sub_500750(a1 *byte) int32 {
	v1 := nox_xxx_scriptGetJournal_5005E0(a1)
	if v1 != nil {
		return int32(v1.Value136)
	} else {
		return 0
	}
}
func sub_500770(a1 *byte) float64 {
	v1 := nox_xxx_scriptGetJournal_5005E0(a1)
	if v1 != nil {
		return float64(math.Float32frombits(v1.Value136))
	} else {
		return 0
	}
}
func sub_500790(p *Journal) {
	v1 := p.Field144
	if v1 != nil {
		v1.Field140 = p.Field140
	}
	v2 := p.Field140
	if v2 != nil {
		v2.Field144 = p.Field144
	}
	if p == dword_5d4594_1570272 {
		dword_5d4594_1570272 = p.Field140
	}
	alloc.Free(p)
}
func sub_5007E0(a1 *byte) {
	var (
		v3  uint32
		v9  *byte
		v10 *byte
		v11 *byte
		v13 uint32
		v14 int32
		v16 uint32
		v17 int32
	)
	sub_5009B0(a1)
	v1 := libc.StrChr((*byte)(memmap.PtrOff(0x5D4594, 1570140)), 42)
	if v1 != nil {
		v3 = uint32(libc.StrLen((*byte)(memmap.PtrOff(0x5D4594, 1570140))) + 1)
		if libc.StrCmp((*byte)(memmap.PtrOff(0x5D4594, 1570140)), internCStr("*:*")) == 0 {
			result := dword_5d4594_1570272
			if dword_5d4594_1570272 != nil {
				for {
					v4 := result.Field140
					sub_500790(result)
					result = v4
					if v4 == nil {
						break
					}
				}
			}
		} else if unsafe.Pointer(v1) == memmap.PtrOff(0x5D4594, uintptr(v3)+1570138) {
			v5 := dword_5d4594_1570272
			if dword_5d4594_1570272 != nil {
				for {
					v6 := v5.Field140
					if nox_strnicmp(&v5.Field0[0], (*byte)(memmap.PtrOff(0x5D4594, 1570140)), int32(v3-2)) == 0 {
						sub_500790(v5)
					}
					v5 = v6
					if v6 == nil {
						break
					}
				}
			}
		} else if unsafe.Pointer(v1) == memmap.PtrOff(0x5D4594, 1570140) {
			v7 := dword_5d4594_1570272
			if v7 != nil {
				for {
					v8 := v7.Field140
					result := libc.StrStr(&v7.Field0[0], (*byte)(memmap.PtrOff(0x5D4594, 1570141)))
					if result != nil {
						v9 = result
						result = nil
						if v3-2 == uint32(libc.StrLen(v9)) {
							sub_500790(v7)
						}
					}
					v7 = v8
					if v8 == nil {
						break
					}
				}
			}
		} else {
			v10 = libc.StrChr((*byte)(memmap.PtrOff(0x5D4594, 1570140)), 58)
			v11 = (*byte)(unsafe.Add(unsafe.Pointer(v10), 2))
			v12 := dword_5d4594_1570272
			v13 = uint32(libc.StrLen((*byte)(unsafe.Add(unsafe.Pointer(v10), 2))) + 1)
			if v12 != nil {
				v14 = int32(uintptr(unsafe.Pointer(v10)) - uintptr(memmap.PtrOff(0x5D4594, 1570140)))
				v17 = int32(uintptr(unsafe.Pointer(v10)) - uintptr(memmap.PtrOff(0x5D4594, 1570140)))
				for {
					v15 := v12.Field140
					if nox_strnicmp(&v12.Field0[0], (*byte)(memmap.PtrOff(0x5D4594, 1570140)), v14+1) == 0 {
						r9 := libc.StrStr((*byte)(unsafe.Add(unsafe.Add(unsafe.Pointer(v12), uintptr(v14)), 2)), v11)
						if r9 != nil {
							v16 = uint32(libc.StrLen(r9) + 1)
							if v13-1 == v16-1 {
								sub_500790(v12)
							}
							v14 = v17
						}
					}
					v12 = v15
					if v15 == nil {
						break
					}
				}
			}
		}
	} else {
		if p := nox_xxx_scriptGetJournal_5005E0(a1); p != nil {
			sub_500790(p)
		}
	}
}
func sub_5009B0(a1 *byte) {
	var (
		v1 uint32
		v2 int8
		v3 *uint8
		v4 *uint8
	)
	if libc.StrChr(a1, 58) != nil {
		result := uint32(libc.StrLen(a1) + 1)
		alloc.Memcpy(memmap.PtrOff(0x5D4594, 1570140), unsafe.Pointer(a1), uintptr(result))
	} else {
		v1 = uint32(libc.StrLen((*byte)(memmap.PtrOff(0x5D4594, 1570008))) + 1)
		v2 = int8(uint8(v1))
		v1 >>= 2
		alloc.Memcpy(memmap.PtrOff(0x5D4594, 1570140), memmap.PtrOff(0x5D4594, 1570008), uintptr(v1*4))
		v4 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v1)*4+1570008))
		v3 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v1)*4+1570140))
		*(*uint8)(unsafe.Pointer(&v1)) = uint8(v2)
		alloc.Memcpy(unsafe.Pointer(v3), unsafe.Pointer(v4), uintptr(v1&3))
		*memmap.PtrUint16(0x5D4594, uintptr(libc.StrLen((*byte)(memmap.PtrOff(0x5D4594, 1570140)))+1570140)) = *memmap.PtrUint16(0x587000, 217960)
		libc.StrCat((*byte)(memmap.PtrOff(0x5D4594, 1570140)), a1)
	}
}
func sub_500A60() int32 {
	var (
		v3 int32
		i  int32
		v5 int32
	)
	v5 = 1
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 2)
	if int32(int16(v5)) > 1 {
		return 0
	}
	v1 := dword_5d4594_1570272
	for i = 0; v1 != nil; i++ {
		v1 = v1.Field140
	}
	if noxflags.HasGame(2048) {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&i)), 4)
		for j := dword_5d4594_1570272; j != nil; j = j.Field140 {
			v6 := uint8(int8(libc.StrLen(&j.Field0[0])))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v6, 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&j.Field0[0], uint32(uint8(int8(v6))))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(j), 132)), 4)
			v3 = int32(j.Field132)
			if v3 != 0 {
				if v3 == 1 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(j), 136)), 4)
				}
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(j), 136)), 4)
			}
		}
		return 1
	} else {
		i = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&i)), 4)
		return 1
	}
}
func sub_500B70() int32 {
	var (
		i  uint32
		v2 int32
		v3 int32
		v4 uint32
		v5 int32
		v6 int32
		v7 int32
		v8 [256]byte
	)
	sub_5007E0(internCStr("*:*"))
	v3 = 1
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3)), 2)
	if int32(int16(v3)) > 1 {
		return 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 4)
	for i = 0; i < v4; i++ {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v2)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v8[0], uint32(uint8(int8(v2))))
		v8[uint8(int8(v2))] = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 4)
		if v5 != 0 {
			if v5 == 1 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 4)
				nox_xxx_journalQuestSetBool_5006B0(&v8[0], v7)
			}
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6)), 4)
			nox_xxx_journalQuestSet_500540(&v8[0], v6)
		}
	}
	return 1
}
func nox_xxx_orderUnitLocal_500C70(owner int32, orderType int32) int32 {
	nox_common_playerInfoFromNum_417090(owner).SummonOrderAll = uint32(orderType)
	return nox_xxx_netCreatureCmd_4D7EE0(owner, int8(orderType))
}
func sub_500CA0(a1 int32, a2 *server.Object) int32 {
	if a2 != nil && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 8)))&4 != 0 {
		return int32(*memmap.PtrUint32(0x587000, uintptr(a1*4)+217668))
	} else {
		return 0
	}
}
func nox_xxx_creatureIsMonitored_500CC0(owner *server.Object, u *server.Object) int32 {
	if u.Class().Has(object.ClassMonster) && (!u.Flags().Has(object.FlagDead) || nox_xxx_unitIsZombie_534A40(u) != 0) && (u.UpdateDataMonster().StatusFlags&0x80) != 0 {
		return nox_xxx_unitHasThatParent_4EC4F0(u, owner)
	} else {
		return 0
	}
}
func Nox_xxx_summonStart_500DA0(sp *server.DurSpell) int32 {
	var (
		v7  int32
		v8  int32
		v9  int32
		v13 int32
		v14 int8
		v16 int16
		v17 [16]uint8
	)
	v1 := sp.Caster16
	v2 := int32(sp.Spell - 74)
	if v1 == nil || v1.ObjFlags&0x8020 != 0 || sp.Flag20 != 0 {
		return 1
	}
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 8)))&4 != 0 {
		v3 := v1.UpdateDataPlayer()
		if noxflags.HasGame(4608) && v3.Player.BeastScrollLvl[v2] == 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0(sp.Caster16, internCStr("Summon.c:NeedGuideToSummon"), 0)
			return 1
		}
		if !nox_xxx_checkSummonedCreaturesLimit_500D70(sp.Caster16, v2) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(sp.Caster16, internCStr("Summon.c:CreatureControlFailed"), 0)
			return 1
		}
	}
	if sub_500F40(sp, COERCE_FLOAT(uint32(uintptr(unsafe.Pointer(&v17[2]))))) == 0 {
		return 1
	}
	v17[10] = *(*uint8)(unsafe.Add(unsafe.Pointer(sp.Caster16), 124))
	v6 := nox_xxx_guideNameByN_427230(v2)
	*(*uint16)(unsafe.Pointer(&v17[0])) = uint16(int16(nox_xxx_getNameId_4E3AA0(v6)))
	*(*uint16)(unsafe.Pointer(&v17[11])) = func() uint16 {
		p := memmap.PtrUint16(0x5D4594, 1570276)
		x := *p
		*p++
		return x
	}()
	if int32(*memmap.PtrUint16(0x5D4594, 1570276)) >= 0xFDE8 {
		*memmap.PtrUint16(0x5D4594, 1570276) = 0
	}
	v7 = int32(*(*uint32)(unsafe.Pointer(&v17[4])))
	v17[13] = 0
	sp.Field72 = int32(*(*uint32)(unsafe.Pointer(&v17[0])))
	v8 = int32(*(*uint32)(unsafe.Pointer(&v17[8])))
	sp.Field76 = uintptr(uint32(v7))
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v7), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(&v17[12]))
	sp.Field80 = uint32(v8)
	*(*uint16)(unsafe.Add(unsafe.Pointer(sp), 84)) = uint16(int16(v7))
	var (
		v11 float64
		v12 int32
	)
	v9 = int32(nox_xxx_guideGetUnitSize_427460(v2)) - 1
	if v9 == 0 {
		v11 = nox_xxx_gamedataGetFloatTable_419D70(internCStr("SummonDuration"), 0)
	} else if v10 := v9 - 1; v10 == 0 {
		v11 = nox_xxx_gamedataGetFloatTable_419D70(internCStr("SummonDuration"), 1)
	} else if v10 == 2 {
		v11 = nox_xxx_gamedataGetFloatTable_419D70(internCStr("SummonDuration"), 2)
	} else {
		// TODO: compiler error? was v12 = sp
	}
	v12 = int32(float32(v11))
	v13 = int32(uint32(v12) + gameFrame())
	v16 = int16(v12)
	v14 = int8(v17[10])
	sp.Frame68 = uint32(v13)
	nox_xxx_sendSummonStartFX_5236F0(*(*int16)(unsafe.Pointer(&v17[11])), (*float32)(unsafe.Pointer(&v17[2])), v14, *(*int16)(unsafe.Pointer(&v17[0])), v16)
	return 0
}
func sub_500F40(a1p *server.DurSpell, a2 float32) int32 {
	var (
		v4  float32
		v5  float32
		v6  float32
		v7  float64
		v8  float64
		v9  float64
		v10 float32
		v14 float32
		v15 float32
		v16 float32
		v18 int32
		v19 float4
	)
	v2 := a1p
	if a1p == nil {
		return 0
	}
	v3 := a1p.Caster16
	if v3 == nil {
		return 0
	}
	v4 = a2
	if float64(a2) == 0.0 {
		return 0
	}
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 8)))&4 != 0 {
		v19.field_0 = v3.PosVec.X
		v5 = v3.PosVec.Y
		v6 = a1p.Pos2.Y
		v19.field_8 = a1p.Pos2.X
		v19.field_C = v6
		v7 = float64(v19.field_8 - v19.field_0)
		v19.field_4 = v5
		v8 = float64(v6 - v5)
		a1c := int32(float32(v8))
		v9 = math.Sqrt(v8*float64(a1c) + v7*v7)
		a2 = float32(v9)
		if v9 > 50.0 {
			v19.field_8 = float32(v7*50.0/float64(a2) + float64(v19.field_0))
			v19.field_C = float32(float64(a1c)*50.0/float64(a2) + float64(v19.field_4))
		}
		if nox_xxx_mapTraceRay_535250(&v19, nil, nil, 9) != 0 && nox_xxx_mapTileAllowTeleport_411A90((*types.Pointf)(unsafe.Pointer(&v19.field_8))) == 0 {
			v10 = v19.field_C
			*(*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(&v4), 4*0))) = *(*uint32)(unsafe.Add(unsafe.Pointer(&v19.field_8), 4*0))
			*(*float32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v4), 4*0))))), 4)) = v10
			return 1
		}
		v12 := v2.Caster16
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v12), 8)))&4 == 0 {
			return 0
		}
		v13 := v12.UpdateDataPlayer()
		a1b := int32(2)
		nox_xxx_netInformTextMsg_4DA0F0(int32(v13.Player.PlayerInd), 0, &a1b)
		return 0
	}
	v19.field_0 = v3.PosVec.X
	v14 = v3.PosVec.Y
	v15 = a1p.Pos2.X
	v16 = a1p.Pos2.Y
	v19.field_4 = v14
	v19.field_8 = v15
	v19.field_C = v16
	if nox_xxx_mapTraceRay_535250(&v19, nil, nil, 9) != 0 {
		*(*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(&v4), 4*0))) = uint32(v2.Pos2.X)
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v4), 4*0))))), 4)) = uint32(v2.Pos2.Y)
		return 1
	} else {
		v17 := v2.Caster16
		*(*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(&v4), 4*0))) = uint32(v17.PosVec.X)
		v18 = int32(v17.PosVec.Y)
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v4), 4*0))))), 4)) = uint32(v18)
		return 1
	}
}
func Nox_xxx_summonFinish_5010D0(sp *server.DurSpell) int32 {
	caster := sp.Caster16
	if caster == nil || caster.ObjFlags&0x8020 != 0 {
		return 1
	}
	if sp.Frame68-1 != gameFrame() {
		return 0
	}
	ind := int32(sp.Spell - 74)
	if caster.Class().Has(object.ClassPlayer) {
		ud := caster.UpdateDataPlayer()
		if noxflags.HasGame(512) && ud.Player.BeastScrollLvl[ind] == 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0(sp.Caster16, internCStr("Summon.c:NeedGuideToSummon"), 0)
			return 1
		}
		if !nox_xxx_checkSummonedCreaturesLimit_500D70(sp.Caster16, ind) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(sp.Caster16, internCStr("Summon.c:CreatureControlFailed"), 0)
			return 1
		}
	}
	sumn := nox_xxx_unitDoSummonAt_5016C0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(sp), 72))), (*float32)(unsafe.Add(unsafe.Pointer(sp), 74)), sp.Caster16, *(*uint8)(unsafe.Add(unsafe.Pointer(sp), 82)))
	if sumn != nil {
		nox_xxx_aud_501960(int32(sound.SoundSummonComplete), sumn, 0, 0)
	}
	*(*uint8)(unsafe.Add(unsafe.Pointer(sp), 85)) = 1
	return 1
}
func Nox_xxx_summonCancel_5011C0(sp *server.DurSpell) {
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(sp), 85))) == 0 {
		nox_xxx_sendSummonCancelFX_523760(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(sp), 83))))
		nox_xxx_audCreate_501A30(900, (*types.Pointf)(unsafe.Add(unsafe.Pointer(sp), 74)), 0, 0)
	}
}
func Nox_xxx_charmCreature1_5011F0(sp *server.DurSpell) int32 {
	if sp.Flag20 != 0 {
		v14 := float32(nox_xxx_gamedataGetFloat_419D40(internCStr("ConfuseEnchantDuration")))
		v1 := int16(int32(v14))
		nox_xxx_buffApplyTo_4FF380(sp.Target48, 3, v1, int8(sp.Level))
		sub_4E7540(sp.Caster16, sp.Target48)
		return 1
	}
	v15 := sp.Caster16
	v3 := int32(nox_xxx_spellFlags_424A70(int32(sp.Spell)))
	v4 := nox_xxx_spellFlySearchTarget_540610((*types.Pointf)(unsafe.Add(unsafe.Pointer(sp), 4*13)), sp.Caster16, v3, 300.0, 0, v15)
	sp.Target48 = v4
	if v4 == nil {
		nox_xxx_netPriMsgToPlayer_4DA2C0(sp.Caster16, internCStr("Summon.c:CharmNoCreatureCloseEnough"), 0)
		nox_xxx_aud_501960(16, sp.Caster16, 0, 0)
		return 1
	}
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 8)))&2 != 0 && nox_xxx_creatureIsMonitored_500CC0(sp.Caster16, v4) == 0 {
		v5 := nox_xxx_creatureIsCharmableByTT_4272B0(int32(sp.Target48.TypeInd))
		v6 := sp.Caster16
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 8)))&4 != 0 && nox_cheat_charmall == 0 {
			if v5 == 0 {
				nox_xxx_netPriMsgToPlayer_4DA2C0(v6, internCStr("Summon.c:CreatureNotCharmable"), 0)
				v12 := sp.Caster16
				sp.Target48 = nil
				nox_xxx_aud_501960(16, v12, 0, 0)
				return 1
			}
			if v6.UpdateDataPlayer().Player.BeastScrollLvl[v5] == 0 {
				sp.Target48 = nil
				nox_xxx_netPriMsgToPlayer_4DA2C0(v6, internCStr("Summon.c:NeedGuideToCharm"), 0)
				nox_xxx_aud_501960(16, sp.Caster16, 0, 0)
				return 1
			}
		}
		var (
			v9  float64
			v10 int32
		)
		v7 := int32(nox_xxx_guideGetUnitSize_427460(v5)) - 1
		if v7 <= 0 {
			v9 = nox_xxx_gamedataGetFloatTable_419D70(internCStr("CharmSmallDuration"), int32(sp.Level-1))
		} else if v7 == 1 {
			v9 = nox_xxx_gamedataGetFloatTable_419D70(internCStr("CharmMediumDuration"), int32(sp.Level-1))
		} else if v7-1 == 2 {
			v9 = nox_xxx_gamedataGetFloatTable_419D70(internCStr("CharmLargeDuration"), int32(sp.Level-1))
		} else {
			// TODO: C compiler error? was v10 = sp
		}
		v10 = int32(float32(v9))
		v11 := sp.Target48
		sp.Frame68 = uint32(v10) + gameFrame()
		nox_xxx_buffApplyTo_4FF380(v11, 28, int16(v10)+1, 5)
		nox_xxx_netStartDurationRaySpell_4FF130(sp)
		return 0
	}
	v13 := sp.Caster16
	sp.Target48 = nil
	nox_xxx_aud_501960(16, v13, 0, 0)
	return 1
}
func Nox_xxx_charmCreatureFinish_5013E0(sp *server.DurSpell) int32 {
	v1 := sp.Target48
	if v1 == nil || v1.ObjFlags&0x8020 != 0 {
		nox_xxx_aud_501960(16, sp.Caster16, 0, 0)
		return 1
	}
	if nox_xxx_calcDistance_4E6C00(sp.Caster16, sp.Target48) > 300.0 {
		v2 := sp.Caster16
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 8)))&4 != 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0(v2, internCStr("Summon.c:CharmBrokenDistance"), 0)
		}
		nox_xxx_aud_501960(16, sp.Caster16, 0, 0)
		return 1
	}
	if uint32(sp.Frame68-1) != gameFrame() {
		return 0
	}
	v4 := sp.Target48
	v5 := int32(v4.ObjSubClass)
	if nox_cheat_charmall == 0 {
		if v5&0x2000 != 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0(sp.Caster16, internCStr("Summon.c:CreatureControlImpossible"), 0)
			nox_xxx_aud_501960(16, sp.Caster16, 0, 0)
			return 1
		}
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(sp.Caster16), 8)))&4 != 0 {
			v6 := nox_xxx_creatureIsCharmableByTT_4272B0(int32(v4.TypeInd))
			if !nox_xxx_checkSummonedCreaturesLimit_500D70(sp.Caster16, v6) {
				nox_xxx_netPriMsgToPlayer_4DA2C0(sp.Caster16, internCStr("Summon.c:CreatureControlFailed"), 0)
				nox_xxx_aud_501960(16, sp.Caster16, 0, 0)
				return 1
			}
		}
	}
	nox_xxx_spellBuffOff_4FF5B0(sp.Target48, 28)
	v8 := nox_xxx_findParentChainPlayer_4EC580(sp.Target48)
	v9 := sp.Caster16
	if v8 == v9 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v9), 8)))&4 != 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0(v9, internCStr("Summon.c:CreatureAlreadyOwned"), 0)
		}
		nox_xxx_aud_501960(16, sp.Caster16, 0, 0)
		return 1
	}
	Nox_xxx_unitClearOwner_4EC300(sp.Target48)
	nox_xxx_unitSetOwner_4EC290(sp.Caster16, sp.Target48)
	if nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(sp.Target48), 48))) != 0 {
		nox_xxx_netChangeTeamMb_419570(unsafe.Add(unsafe.Pointer(sp.Target48), 48), int32(sp.Target48.NetCode))
	}
	v10 := sp.Target48.UpdateData
	v11 := int32(*(*uint32)(unsafe.Add(v10, 1440)))
	*(*uint8)(unsafe.Pointer(&v11)) = uint8(int8(v11 | 0x80))
	*(*uint32)(unsafe.Add(v10, 1440)) = uint32(v11)
	if noxflags.HasGame(4096) {
		v12 := nox_xxx_objectTypeByIndHealthData(int32(sp.Target48.TypeInd))
		v13 := uint16(nox_xxx_unitGetHP_4EE780(sp.Target48))
		v14 := *(*unsafe.Pointer)(unsafe.Add(v10, 484))
		var v15 uint16
		if v14 != nil {
			v15 = *(*uint16)(unsafe.Add(v14, 72))
		} else {
			v15 = v12.Max
		}
		sp.Target48.HealthData.Max = v15
		if int32(v13) > int32(v15) {
			nox_xxx_unitSetHP_4E4560(sp.Target48, v15)
		}
	}
	v16 := sp.Caster16
	if v16.Class().Has(object.ClassPlayer) {
		v17 := v16.UpdateDataPlayer()
		nox_xxx_orderUnit_533900(v16, sp.Target48, int32(v17.Player.SummonOrderAll))
		v18 := sp.Target48
		v19 := int32(v18.ObjSubClass)
		*(*uint8)(unsafe.Pointer(&v19)) = uint8(int8(v19 | 0x80))
		v18.ObjSubClass = uint32(v19)
		v20 := sp.Target48
		v21 := int32(v20.ObjSubClass)
		*(*uint8)(unsafe.Add(unsafe.Pointer(&v21), 1)) |= 1
		v20.ObjSubClass = uint32(v21)
		nox_xxx_netReportAcquireCreature_4D91A0(int32(v17.Player.PlayerInd), sp.Target48)
		nox_xxx_netMarkMinimapObject_417190(int32(v17.Player.PlayerInd), sp.Target48, 1)
		nox_xxx_netSendSimpleObject2_4DF360(int32(v17.Player.PlayerInd), sp.Target48)
		if noxflags.HasGame(4096) {
			sub_50E140(unsafe.Pointer(sp.Target48))
		}
	} else {
		nox_xxx_orderUnit_533900(v16, sp.Target48, 4)
	}
	v23 := sp.Caster16
	v22 := nox_xxx_spellGetAud44_424800(int32(sp.Spell), 1)
	nox_xxx_aud_501960(v22, v23, 0, 0)
	return 1
}
func Nox_xxx_charmCreature2_501690(sp *server.DurSpell) {
	a1 := sp
	result := a1.Target48
	if result == nil {
		return
	}
	if (result.ObjFlags & 0x8020) == 0 {
		nox_xxx_spellBuffOff_4FF5B0(result, 5)
		nox_xxx_spellBuffOff_4FF5B0(a1.Target48, 28)
	}
}
func nox_xxx_banishUnit_5017F0(unit *server.Object) {
	if *memmap.PtrUint32(0x5D4594, 1570280) == 0 {
		*memmap.PtrUint32(0x5D4594, 1570280) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Glyph")))
	}
	if unit != nil {
		v1 := unit.InvFirstItem
		if v1 != nil {
			for {
				v2 := v1.InvNextItem
				if uint32(v1.TypeInd) == *memmap.PtrUint32(0x5D4594, 1570280) {
					nox_xxx_delayedDeleteObject_4E5CC0(v1)
				}
				v1 = v2
				if v2 == nil {
					break
				}
			}
		}
		nox_xxx_netSendPointFx_522FF0(-127, (*types.Pointf)(unsafe.Add(unsafe.Pointer(unit), 56)))
		ud := unit.UpdateData
		nox_xxx_scriptCallByEventBlock_502490(unsafe.Add(ud, 1264), nil, unsafe.Pointer(unit), 7)
		nox_xxx_delayedDeleteObject_4E5CC0(unit)
	}
}
func sub_501C00(a1 *float32, a2 *server.Object) int8 {
	var (
		v2 int8
		v4 *byte
		v5 int32
		v6 float32
		v7 *nox_player_polygon_check_data
		v9 Point32
	)
	v2 = 0
	if a2 != nil {
		if a2.Class().Has(object.ClassPlayer) {
			v2 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(a2.UpdateDataPlayer().Player), 3668)))
			if int32(v2) != 0 {
				return v2
			}
			goto LABEL_8
		}
		if a2.Class().Has(object.ClassMonster) {
			v4 = nox_xxx_polygonGetByIdx_4214A0(a2.UpdateDataMonster().Field0)
			if v4 != nil {
				v2 = int8(*(*byte)(unsafe.Add(unsafe.Pointer(v4), 130)))
				if int32(v2) != 0 {
					return v2
				}
				goto LABEL_8
			}
		}
	}
LABEL_8:
	v5 = int32(*a1)
	v6 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1))
	v9.X = v5
	v9.Y = int32(v6)
	v7 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v9, 0)
	if v7 != nil {
		return int8(*(*uint8)(unsafe.Add(unsafe.Pointer(&v7.field_0[32]), 2)))
	}
	return v2
}
func Nox_xxx_netUpdateRemotePlr_501CA0(a1 *server.Object) {
	var (
		v4  *server.Object
		v6  int32
		v17 Point32
		v18 int8
	)
	ud := a1.UpdateDataPlayer()
	v3 := ud.Player
	if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 3680)))&3) == 0 || (func() *server.Object {
		v4 = v3.CameraFollowObj
		return v4
	}()) == nil {
		if *(*int32)(unsafe.Add(unsafe.Pointer(v3), 3664)) == -559023410 {
			nox_xxx_questCheckSecretArea_421C70(a1)
		}
		v5 := ud.Player
		v18 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 3668)))
	} else if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 8)))&4 != 0 {
		v5 := v4.UpdateDataPlayer().Player
		v18 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 3668)))
	} else {
		v6 = int32(v3.CameraFollowObj.PosVec.X)
		v7 := ud.Player
		v17.X = v6
		v17.Y = int32(v7.CameraFollowObj.PosVec.Y)
		v8 := nox_xxx_polygonIsPlayerInPolygon_4217B0(&v17, 0)
		if v8 != nil {
			v18 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(&v8.field_0[32]), 2)))
		} else {
			v18 = 0
		}
	}
	nox_xxx_netUpdateRemotePlr_501CA0_B(a1, unsafe.Pointer(ud), v18)
}
func nox_server_scriptExecuteFnForEachGroupObj_502670(g *server.MapGroup, expectedType int32, a3 func(unsafe.Pointer, unsafe.Pointer), a4 unsafe.Pointer) {
	if g == nil {
		return
	}
	switch g.GroupType() {
	case server.MapGroupObjects:
		if expectedType != 0 {
			break
		}
		for i := g.List; i != nil; i = i.Next8 {
			v5 := nox_xxx_netGetUnitByExtent_4ED020(int32(i.Raw0))
			if v5 != nil {
				a3(unsafe.Pointer(v5), a4)
			}
		}
	case server.MapGroupWaypoints:
		if expectedType != 1 {
			break
		}
		for j := g.List; j != nil; j = j.Next8 {
			v7 := (*uint32)(unsafe.Pointer(nox_server_getWaypointById_579C40(int32(j.Raw0))))
			if v7 != nil {
				a3(unsafe.Pointer(v7), a4)
			}
		}
	case server.MapGroupWalls:
		if expectedType != 2 {
			break
		}
		for k := g.List; k != nil; k = k.Next8 {
			v9 := nox_server_getWallAtGrid_410580(int32(k.Raw0), int32(k.Raw4))
			if v9 != nil {
				a3(unsafe.Pointer(v9), a4)
			}
		}
		fallthrough
	case server.MapGroupGroups:
		for l := g.List; l != nil; l = l.Next8 {
			v11 := nox_server_scriptGetGroup_57C0A0(int32(l.Raw0))
			if v11 != nil {
				nox_server_scriptExecuteFnForEachGroupObj_502670(v11, expectedType, a3, a4)
			}
		}
	default:
		return
	}
}
func nox_xxx_mapgenMakeScript_502790(a1 *FILE, a2 *byte) int32 {
	var (
		result int32
		i      int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    [1024]byte
	)
	nox_binfile_fread_408E40((*byte)(unsafe.Pointer(&v8)), 4, 1, a1)
	nox_binfile_fread_408E40(&v10[0], 1, v8, a1)
	nox_binfile_fread_408E40(a2, 4, 1, a1)
	nox_binfile_fread_408E40((*byte)(unsafe.Pointer(&v7)), 4, 1, a1)
	result = v7
	for i = 0; i < v7; i++ {
		nox_binfile_fread_408E40((*byte)(unsafe.Pointer(&v6)), 1, 1, a1)
		nox_binfile_fseek_409050(a1, 1, stdio.SEEK_CUR)
		v4 = 0
		v5 = int32(uint8(int8(v6))) * 268
		if int32(*memmap.PtrUint8(0x587000, uintptr(v5)+218640)) != 0 {
			for {
				switch *memmap.PtrUint32(0x587000, uintptr(v4)*8+218648+uintptr(v5)) {
				case 0, 3, 4, 5, 6:
					nox_binfile_fseek_409050(a1, 4, stdio.SEEK_CUR)
				case 1:
					nox_binfile_fseek_409050(a1, 8, stdio.SEEK_CUR)
				case 2, 7:
					nox_binfile_fread_408E40((*byte)(unsafe.Pointer(&v9)), 1, 1, a1)
					nox_binfile_fseek_409050(a1, int32(uint8(int8(v9))), stdio.SEEK_CUR)
				default:
				}
				v4++
				v5 = int32(uint8(int8(v6))) * 268
				if v4 >= int32(*memmap.PtrUint8(0x587000, uintptr(v5)+218640)) {
					break
				}
			}
		}
		result = v7
	}
	return result
}
func sub_5029A0(a1 *byte) int32 {
	var (
		v1 int32
		i  int32
	)
	v1 = 0
	if dword_5d4594_1599596 <= 0 {
		return -1
	}
	for i = 0; nox_strcmpi(a1, (*byte)(unsafe.Add(dword_5d4594_1599576, uintptr(uint32(i))))) != 0; i += 76 {
		if func() int32 {
			p := &v1
			*p++
			return *p
		}() >= int32(dword_5d4594_1599596) {
			return -1
		}
	}
	return v1
}
func sub_5029F0(a1 int32) unsafe.Pointer {
	if a1 < 0 || a1 > dword_5d4594_1599596 {
		return nil
	}
	return unsafe.Add(dword_5d4594_1599576, uint32(a1*76))
}
func sub_502A20() int32 {
	return dword_5d4594_1599596
}
func sub_502A50(a1 *byte) int32 {
	sub_502DF0()
	if a1 != nil {
		libc.StrNCpy(dword_5d4594_1599588, a1, 0x7FF)
		return 1
	} else {
		*dword_5d4594_1599588 = *memmap.PtrUint8(0x5D4594, 1599608)
		return 0
	}
}
func sub_502AB0(a1 *byte) int32 {
	if a1 != nil {
		libc.StrNCpy(dword_5d4594_1599592, a1, 0x7FF)
		return 1
	} else {
		*dword_5d4594_1599592 = *memmap.PtrUint8(0x5D4594, 1599612)
		return 0
	}
}
func sub_502B10() int32 {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int8
		v5  int8
		v6  int32
		v7  int32
		v8  uint32
		v9  float32
		v10 float32
		v11 [64]byte
	)
	dword_5d4594_1599596 = 0
	if dword_5d4594_1599588 == nil {
		dword_5d4594_1599588 = (*byte)(alloc.Calloc1(1, 0x800))
	}
	if dword_5d4594_1599592 == nil {
		dword_5d4594_1599592 = (*byte)(alloc.Calloc1(1, 0x800))
	}
	if dword_5d4594_1599576 == nil {
		dword_5d4594_1599576 = alloc.Calloc1(1, 0x26000)
	}
	if libc.StrLen(dword_5d4594_1599588) == 0 {
		return 0
	}
	if sub_502DA0(dword_5d4594_1599588) == 0 {
		return 0
	}
	nox_fs_fread(nox_file_8, unsafe.Pointer(&v8), 4)
	if v8 == 0xCAFEDEAD {
		for {
			v6 = 0
			nox_fs_fread(nox_file_8, unsafe.Pointer(&v6), 4)
			v1 = v6
			if v6 == 0 {
				break
			}
			if dword_5d4594_1599596 >= 2048 {
				sub_502DF0()
				return 0
			}
			*(*uint32)(unsafe.Add(unsafe.Add(dword_5d4594_1599576, uintptr(dword_5d4594_1599596*76)), 72)) = uint32(nox_fs_ftell(nox_file_8) - 4)
			nox_fs_fread(nox_file_8, unsafe.Pointer(&v7), 1)
			nox_fs_fread(nox_file_8, unsafe.Pointer(&v11[0]), int32(uint8(int8(v7))))
			v2 = -1 - int32(uint8(int8(v7)))
			v11[uint8(int8(v7))] = 0
			v3 = v2 + v1
			libc.StrCpy((*byte)(unsafe.Add(dword_5d4594_1599576, uintptr(dword_5d4594_1599596*76))), &v11[0])
			nox_fs_fread(nox_file_8, unsafe.Pointer(&v4), 1)
			nox_fs_fread(nox_file_8, unsafe.Pointer(&v5), 1)
			nox_fs_fread(nox_file_8, unsafe.Pointer(&v9), 4)
			nox_fs_fread(nox_file_8, unsafe.Pointer(&v10), 4)
			*(*float32)(unsafe.Add(unsafe.Add(dword_5d4594_1599576, uintptr(dword_5d4594_1599596*76)), 64)) = v9
			*(*float32)(unsafe.Add(unsafe.Add(dword_5d4594_1599576, uintptr(func() int32 {
				p := &dword_5d4594_1599596
				x := *p
				*p++
				return x
			}()*76)), 68)) = v10
			nox_fs_fseek(nox_file_8, v3-10, stdio.SEEK_CUR)
		}
		sub_502DF0()
		return 1
	} else {
		sub_502DF0()
		return 0
	}
}
func sub_502D70(a1 int32) int32 {
	if a1 < 0 || a1 >= dword_5d4594_1599596 {
		return 0
	}
	dword_5d4594_3835396 = a1
	return bool2int32(nox_xxx_mapgenSaveMap_503830(a1) == 0)
}
func sub_502DA0(a1 *byte) int32 {
	var result int32
	result = bool2int32(nox_file_8 != nil)
	if nox_file_8 != nil || (func() int32 {
		result = nox_xxx_cryptOpen_426910(a1, 1, -1)
		return result
	}()) != 0 && (func() bool {
		f := nox_xxx_mapgenGetSomeFile_426A60()
		result = bool2int32(f != nil)
		return (func() *FILE {
			nox_file_8 = f
			return nox_file_8
		}()) != nil
	}()) {
		nox_fs_fseek(nox_file_8, 0, stdio.SEEK_SET)
		return 1
	}
	return result
}
func sub_502DF0() {
	if nox_file_8 != nil {
		nox_xxx_cryptClose_4269F0()
		nox_file_8 = nil
	}
}
func sub_502E10(a1 int32) *FILE {
	if nox_file_8 == nil || a1 < 0 || a1 >= dword_5d4594_1599596 {
		return nil
	}
	nox_fs_fseek(nox_file_8, int32(*(*uint32)(unsafe.Add(unsafe.Add(dword_5d4594_1599576, uintptr(a1)*76), 72))), stdio.SEEK_SET)
	return nox_file_8
}
func sub_502E70(a1 int32) float64 {
	var result float64
	if a1 < 0 || a1 >= dword_5d4594_1599596 {
		result = -1.0
	} else {
		result = float64(*(*float32)(unsafe.Add(dword_5d4594_1599576, uintptr(a1)*76+64)))
	}
	return result
}
func sub_502EA0(a1 int32) float64 {
	var result float64
	if a1 < 0 || a1 >= dword_5d4594_1599596 {
		result = -1.0
	} else {
		result = float64(*(*float32)(unsafe.Add(dword_5d4594_1599576, uintptr(a1)*76+68)))
	}
	return result
}
func nox_xxx_mapgenSaveMap_503830(a1 int32) int32 {
	var (
		v1  *FILE
		v5  uint8
		v6  int32
		v7  int8
		v8  int32
		v9  int32
		v10 int32
		v11 [8]int32
		v19 [2]int32
		v21 int32
		v22 int32
		v23 int32
		v24 [4]byte
		v25 int4
		v26 [64]byte
		v27 [256]byte
	)
	if a1 < 0 {
		return 0
	}
	if a1 >= dword_5d4594_1599596 {
		return 0
	}
	nox_xxx_free_503F40()
	*memmap.PtrUint32(0x5D4594, 1599572) = math.MaxUint32
	dword_5d4594_1599644 = 0
	sub_502DA0(dword_5d4594_1599588)
	if sub_502E10(a1) == nil {
		return 0
	}
	v1 = nox_xxx_mapgenGetSomeFile_426A60()
	nox_fs_fread(v1, unsafe.Pointer(&v22), 4)
	nox_fs_fread(v1, unsafe.Pointer(&v9), 1)
	nox_fs_fread(v1, unsafe.Pointer(&v26[0]), int32(uint8(int8(v9))))
	nox_fs_fread(v1, unsafe.Pointer(&v7), 1)
	nox_fs_fread(v1, unsafe.Pointer(&v5), 1)
	nox_fs_fread(v1, unsafe.Pointer(&v21), 4)
	nox_fs_fread(v1, unsafe.Pointer(&v23), 4)
	if int32(v5) > 1 {
		nox_fs_fread(v1, unsafe.Pointer(&v6), 4)
		nox_fs_fseek(v1, v6, stdio.SEEK_CUR)
	}
	nox_fs_fread(v1, unsafe.Pointer(&v10), 4)
	if v10 != -889266515 {
		return 0
	}
	nox_fs_fread(v1, unsafe.Pointer(&v19[0]), 4)
	nox_fs_fread(v1, unsafe.Pointer(&v19[1]), 4)
	nox_xxx_mapWall_426A80(&v19[0])
	nox_fs_fread(v1, unsafe.Pointer(&v11[0]), 4)
	nox_fs_fread(v1, unsafe.Pointer(&v11[1]), 4)
	nox_fs_fread(v1, unsafe.Pointer(&v11[6]), 4)
	nox_fs_fread(v1, unsafe.Pointer(&v11[7]), 4)
	nox_fs_fread(v1, unsafe.Pointer(&v11[2]), 4)
	nox_fs_fread(v1, unsafe.Pointer(&v11[3]), 4)
	nox_fs_fread(v1, unsafe.Pointer(&v11[4]), 4)
	nox_fs_fread(v1, unsafe.Pointer(&v11[5]), 4)
	sub_4D3C80((*uint32)(unsafe.Pointer(&v11[0])))
	alloc.Memcpy(memmap.PtrOff(0x5D4594, 1599500), unsafe.Pointer(&v11[0]), 0x20)
	sub_428170(unsafe.Pointer(&v11[0]), &v25)
	nox_xxx_cryptSetTypeMB_426A50(1)
	for {
		v6 = 0
		*(*uint8)(unsafe.Pointer(&v8)) = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 1)
		if int32(uint8(int8(v8))) == 0 {
			break
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v27[0], uint32(uint8(int8(v8))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v24[0], 4)
		if nox_xxx_mapReadSection_426EA0(unsafe.Pointer(&v11[0]), &v27[0], (*uint32)(unsafe.Pointer(&v6))) == 0 {
			if v6 == 1 {
				sub_502DF0()
				return 0
			}
			v2 := nox_xxx_newObjectByTypeID_4E3810(&v27[0])
			v3 := v2
			if v2 == nil {
				return 0
			}
			if v2.Xfer.Get()(v2, unsafe.Pointer(&v25)) == 0 {
				nox_xxx_objectFreeMem_4E38A0(v3)
				sub_502DF0()
				return 0
			}
			nox_xxx_servMapLoadPlaceObj_4F3F50(v3, nil, unsafe.Pointer(&v25))
		}
	}
	nox_xxx_cryptSetTypeMB_426A50(0)
	dword_5d4594_1599480 = a1
	dword_5d4594_1599476 = 0
	dword_5d4594_3835396 = a1
	sub_502DF0()
	return 1
}
func sub_503B30(a1 *types.Pointf) int32 {
	var (
		result int32
		v2     int32
		v3     float64
		v4     float32
		v5     *byte
		v6     *byte
		v7     int32
		v8     int32
		v9     int32
		v13    types.Pointf
		v14    types.Pointf
		a2     types.Pointf
		v16    Point32
		v17    int4
		v18    [8]int32
	)
	result = nox_xxx_mapGenFixCoords_4D3D90(a1, &a2)
	if result == 0 {
		return result
	}
	v2 = dword_5d4594_3835396
	if dword_5d4594_1599480 != dword_5d4594_3835396 || dword_5d4594_1599480 == -1 || dword_5d4594_1599476 == 1 {
		result = nox_xxx_mapgenSaveMap_503830(dword_5d4594_3835396)
		if result == 0 {
			return result
		}
		v2 = dword_5d4594_3835396
	}
	v18[2] = int32(int64(a2.X))
	v18[3] = int32(int64(a2.Y))
	v13.X = *(*float32)(unsafe.Add(unsafe.Add(dword_5d4594_1599576, uintptr(uint32(v2*76))), 64)) + a1.X
	v13.Y = *(*float32)(unsafe.Add(unsafe.Add(dword_5d4594_1599576, uintptr(uint32(v2*76))), 68)) + a1.Y
	nox_xxx_mapGenFixCoords_4D3D90(&v13, &v14)
	v18[4] = int32(int64(v14.X))
	v18[5] = int32(int64(v14.Y))
	v3 = float64(*(*float32)(unsafe.Add(unsafe.Add(dword_5d4594_1599576, uintptr(dword_5d4594_3835396*76)), 64)) + a1.X)
	v13.Y = a1.Y
	v13.X = float32(v3)
	nox_xxx_mapGenFixCoords_4D3D90(&v13, &v14)
	v18[0] = int32(int64(v14.X))
	v4 = a1.X
	v18[1] = int32(int64(v14.Y))
	v13.X = v4
	v13.Y = *(*float32)(unsafe.Add(unsafe.Add(dword_5d4594_1599576, uintptr(dword_5d4594_3835396*76)), 68)) + a1.Y
	nox_xxx_mapGenFixCoords_4D3D90(&v13, &v14)
	v18[6] = int32(int64(v14.X))
	v18[7] = int32(int64(v14.Y))
	sub_4D3C80((*uint32)(unsafe.Pointer(&v18[0])))
	sub_428170(unsafe.Pointer(&v18[0]), &v17)
	v5 = nox_xxx_mapGetWallSize_426A70()
	v6 = v5
	v7 = int32(*(*uint32)(unsafe.Pointer(v5)))
	*memmap.PtrUint32(0x5D4594, 1599484) = uint32(v7)
	*memmap.PtrUint32(0x5D4594, 1599488) = *(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
	*memmap.PtrFloat32(0x5D4594, 1599492) = float32(float64(v7 * 23))
	*memmap.PtrFloat32(0x5D4594, 1599496) = float32(float64(int32(*memmap.PtrUint32(0x5D4594, 1599488) * 23)))
	v8 = int32(int64(float64(a2.X) - float64(*memmap.PtrInt32(0x5D4594, 1599508))))
	v9 = int32(int64(float64(a2.Y) - float64(*memmap.PtrInt32(0x5D4594, 1599512))))
	result = nox_xxx_tileInit_504150(v8, v9)
	if result == 0 {
		return result
	}
	result = sub_504330(v8, v9)
	if result == 0 {
		return result
	}
	result = sub_504560(v8, v9)
	if result == 0 {
		return result
	}
	result = sub_504910(v8, v9)
	if result == 0 {
		return result
	}
	sub_579D20()
	for i := sub_579890(); i != nil; i = sub_5798A0(i) {
		i.Flags |= 0x80000000
	}
	dword_5d4594_3835392 = uint32(nox_xxx_interesting_xfer_4D0010((*uint32)(unsafe.Pointer(&v17)), int32(dword_5d4594_3835392)))
	result = sub_504720(uint32(v8), uint32(v9))
	if result == 0 {
		return result
	}
	for j := sub_579890(); j != nil; j = sub_5798A0(j) {
		j.Field1 = 0
	}
	for k := nox_server_getFirstObjectUninited_4DA870(); k != nil; k = nox_server_getNextObjectUninited_4DA880(k) {
		k.ScriptIDVal = 0
	}
	nox_xxx_waypoint_5799C0()
	nox_xxx_unitClearPendingMB_4DB030()
	dword_5d4594_1599476 = 1
	if dword_5d4594_1599644 != 0 {
		*memmap.PtrUint32(0x973F18, 35880)++
		sub_542BF0(int32(dword_5d4594_3835312), v8, v9)
		v16.X = v8
		v16.Y = v9
		sub_543110((*byte)(memmap.PtrOff(0x973F18, 30760)), &v16.X)
		if *memmap.PtrUint32(0x5D4594, 1599580) != 0 {
			nox_fs_remove((*byte)(memmap.PtrOff(0x973F18, 36008)))
			nox_fs_move((*byte)(memmap.PtrOff(0x973F18, 38056)), (*byte)(memmap.PtrOff(0x973F18, 36008)))
			nox_script_readWriteZzz_541670((*byte)(memmap.PtrOff(0x973F18, 36008)), (*byte)(memmap.PtrOff(0x973F18, 30760)), (*byte)(memmap.PtrOff(0x973F18, 38056)))
		} else {
			*memmap.PtrUint32(0x5D4594, 1599580) = 1
			nox_fs_move((*byte)(memmap.PtrOff(0x973F18, 30760)), (*byte)(memmap.PtrOff(0x973F18, 38056)))
		}
	}
	dword_5d4594_3835312++
	return 1
}
func sub_503EC0(a1 *server.Object, a2 *float32) int32 {
	var (
		a1a types.Pointf
		v4  types.Pointf
		a2a types.Pointf
	)
	if dword_5d4594_1599480 != dword_5d4594_3835396 || dword_5d4594_1599480 == -1 || dword_5d4594_1599476 == 1 {
		return 0
	}
	a1a.X = float32(float64(*memmap.PtrInt32(0x5D4594, 1599508)))
	a1a.Y = float32(float64(*memmap.PtrInt32(0x5D4594, 1599512)))
	sub_4D3E30(&a1a, &a2a)
	sub_4D3E30(&a1.PosVec, &v4)
	*a2 = v4.X - a2a.X
	*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) = v4.Y - a2a.Y
	return 1
}

type TileXxx struct {
	Field0  *TileYyy // 0, 0
	Field4  float32  // 1, 4
	Field8  float32  // 2, 8
	Field12 uint32   // 3, 12
	Field16 *TileXxx // 4, 16
	Field20 *TileXxx // 5, 20
}

type TileYyy struct {
	Field0  uint32   // 0, 0
	Field4  uint32   // 1, 4
	Field8  uint32   // 2, 8
	Field12 uint32   // 3, 12
	Field16 *TileYyy // 4, 16
}

func nox_xxx_tileAllocTileInCoordList_5040A0(a1 int32, a2 int32, a3 uint8) *TileXxx {
	var (
		v6 float64
		v7 bool
		v8 float32
	)
	v4, _ := alloc.New(TileXxx{})
	if v4 == nil {
		return nil
	}
	v5, _ := alloc.New(TileYyy{})
	v4.Field0 = v5
	if v5 == nil {
		alloc.Free(v4)
		return nil
	}
	v4.Field20 = nil
	v4.Field16 = dword_5d4594_1599556
	if dword_5d4594_1599556 != nil {
		dword_5d4594_1599556.Field20 = v4
	}
	dword_5d4594_1599556 = v4
	v6 = float64(a1) * 46.0
	*memmap.PtrUint32(0x5D4594, 1599560)++
	v7 = a3 == 1
	*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 12)) = a3
	v4.Field4 = float32(v6)
	v8 = float32(float64(a2) * 46.0)
	v4.Field8 = v8
	if v7 {
		v4.Field4 = float32(v6 + 23.0)
	} else {
		v4.Field8 = float32(float64(v8) + 23.0)
	}
	return v4
}
func nox_xxx_tileInit_504150(a1 int32, a2 int32) int32 {
	var (
		a1a types.Pointf
		v8  [72]byte
		v9  float32
		v10 float32
	)
	if *memmap.PtrInt32(0x587000, 229704) == -1 {
		if nox_tile_def_cnt > 0 {
			var v2 int32 = 0
			for i := int32(0); uint32(i) < nox_tile_def_cnt; i++ {
				p := &nox_tile_defs_arr[i]
				if libc.StrCmp(&p.name[0], internCStr("TransparentFloor")) == 0 {
					*memmap.PtrUint32(0x587000, 229704) = uint32(i)
					v2 = i
					break
				}
			}
			if v2 == -1 {
				return 0
			}
		}
	}
	alloc.Memcpy(unsafe.Pointer(&v8[0]), unsafe.Pointer(sub_4D3C70()), 72)
	v5 := dword_5d4594_1599556
	if dword_5d4594_1599556 != nil {
		v9 = float32(float64(a1))
		v10 = float32(float64(a2))
		for {
			a1a.X = v9 + v5.Field4
			a1a.Y = v10 + v5.Field8
			nox_xxx_tileCheckImage_51D540(int32(v5.Field0.Field0))
			nox_xxx_tileCheckImageVari_51D570(int32(v5.Field0.Field4))
			nox_xxx_tile_51D5C0(1)
			if v5.Field0.Field0 != *memmap.PtrUint32(0x587000, 229704) {
				sub_51D8F0(&a1a)
			}
			for i := v5.Field0.Field16; i != nil; i = i.Field16 {
				nox_xxx_tileCheckByte3_544070(int32(i.Field8))
				nox_xxx_tileCheckByte4_5440A0(int32(i.Field12))
				nox_xxx_tileCheckImage_51D540(int32(i.Field0))
				nox_xxx_tileCheckImageVari_51D570(int32(i.Field4))
				nox_xxx_tileSubtile_544310(&a1a)
			}
			v5 = v5.Field16
			if v5 == nil {
				break
			}
		}
	}
	nox_xxx_tileInitdataClear_4D3C50(unsafe.Pointer(&v8[0]))
	return 1
}

type WallListItem struct {
	Wall *server.Wall
	Next *WallListItem
	Prev *WallListItem
}

var dword_5d4594_1599532 *WallListItem

func sub_504290(x, y int8) *WallListItem {
	p, _ := alloc.New(WallListItem{})
	if p == nil {
		return nil
	}
	p.Prev = nil
	p.Next = dword_5d4594_1599532
	if dword_5d4594_1599532 != nil {
		dword_5d4594_1599532.Prev = p
	}
	dword_5d4594_1599532 = p
	wl, _ := alloc.New(server.Wall{})
	p.Wall = wl
	wl.X5 = uint8(x)
	wl.Y6 = uint8(y)
	return p
}
func nox_xxx_cliWallGet_5042F0(a1 int32, a2 int32) *WallListItem {
	p := dword_5d4594_1599532
	if dword_5d4594_1599532 == nil {
		return nil
	}
	for int32(p.Wall.X5) != a1 || int32(p.Wall.Y6) != a2 {
		p = p.Next
		if p == nil {
			return nil
		}
	}
	return p
}
func sub_504330(a1 int32, a2 int32) int32 {
	for v2 := dword_5d4594_1599532; v2 == nil; v2 = v2.Next {
		v3 := (a1 + int32(v2.Wall.X5)*23) / 23
		v4 := a2 + int32(v2.Wall.Y6)*23
		v6 := v4 / 23
		v7 := nox_server_getWallAtGrid_410580(v3, v6)
		if v7 != nil {
			v8 := v2.Wall.Dir0
			if dword_5d4594_3835368 != 0 {
				v7.Dir0 = nox_xxx_wall_42A6C0(v7.Dir0, v8)
			} else {
				v7.Dir0 = v8
			}
		} else {
			v7 = nox_xxx_wallCreateAt_410250(v3, v6)
			if v7 == nil {
				return 0
			}
			v7.Dir0 = v2.Wall.Dir0
		}
		v7.Tile1 = v2.Wall.Tile1
		v7.Field2 = v2.Wall.Field2
		v7.Health7 = v2.Wall.Health7
		if (int32(v2.Wall.Flags4) & 0x80) != 0 {
			v7.Flags4 |= 0x80
		}
		if int32(v7.Field2) >= int32(nox_xxx_mapWallMaxVariation_410DD0(int32(v7.Tile1), int32(v7.Dir0), 0)) {
			v7.Field2 = 0
		}
		if int32(v7.Flags4)&4 != 0 {
			sub_4107A0(v7.Data28)
		}
		if int32(v2.Wall.Flags4)&4 != 0 {
			v7.Flags4 |= 4
			v11 := v2.Wall.Data28
			v7.Data28 = v11
			nox_xxx_wallSecretBlock_410760(v11)
		}
		if int32(v2.Wall.Flags4)&8 != 0 {
			v9 := v7.Flags4
			if (int32(v9) & 8) == 0 {
				v12 := v7.Data28
				v7.Flags4 = server.WallFlags(uint8(int8(int32(v9) | 8)))
				nox_xxx_wallBreackableListAdd_410840((*server.Wall)(v12))
			}
		}
		if int32(v2.Wall.Flags4)&0x40 != 0 {
			v7.Flags4 |= 0x40
		}
	}
	return 1
}

type WaypointListXxx struct {
	Field0 *server.Waypoint
	Field4 *WaypointListXxx
	Field8 *WaypointListXxx
}

func sub_5044B0(ind int32, x, y float32) *WaypointListXxx {
	p, _ := alloc.New(WaypointListXxx{})
	if p == nil {
		return nil
	}
	wp := sub_579E70()
	p.Field0 = wp
	if wp == nil {
		alloc.Free(p)
		return nil
	}
	p.Field8 = nil
	p.Field4 = dword_5d4594_1599548
	if dword_5d4594_1599548 != nil {
		dword_5d4594_1599548.Field8 = p
	}
	dword_5d4594_1599548 = p
	p.Field0.Index = uint32(ind)
	p.Field0.PosVec.X = x
	p.Field0.PosVec.Y = y
	p.Field0.WpPrev = nil
	v6 := p.Field4
	if v6 != nil {
		p.Field0.WpNext = v6.Field0
		p.Field4.Field0.WpPrev = p.Field0
	} else {
		p.Field0.WpNext = nil
	}
	return p
}
func sub_504560(a1 int32, a2 int32) int32 {
	var (
		v4 float32
		v5 float32
	)
	v2 := dword_5d4594_1599548
	if dword_5d4594_1599548 == nil {
		return 1
	}
	v4 = float32(float64(a1))
	v5 = float32(float64(a2))
	for {
		v2.Field0.PosVec.X = v4 + v2.Field0.PosVec.X
		v2.Field0.PosVec.Y = v5 + v2.Field0.PosVec.Y
		sub_579E90(v2.Field0)
		v2 = v2.Field4
		if v2 == nil {
			break
		}
	}
	return 1
}

type UnitListXxx struct {
	Field0 *server.Object
	Field4 *UnitListXxx
	Field8 *UnitListXxx
}

func nox_xxx_unitAddToList_5048A0(a1 *server.Object) {
	p, _ := alloc.New(UnitListXxx{})
	if p == nil {
		return
	}
	p.Field8 = nil
	p.Field0 = a1
	p.Field4 = dword_5d4594_1599540
	if dword_5d4594_1599540 != nil {
		dword_5d4594_1599540.Field8 = p
	}
	dword_5d4594_1599540 = p
	p.Field0.ObjPrev = nil
	if v2 := p.Field4; v2 != nil {
		p.Field0.ObjNext = v2.Field0
		p.Field4.Field0.ObjPrev = p.Field0
	} else {
		p.Field0.ObjNext = nil
	}
}
func sub_504910(a1 int32, a2 int32) int32 {
	var (
		v4 float32
		v5 float32
	)
	v2 := dword_5d4594_1599540
	if dword_5d4594_1599540 == nil {
		return 1
	}
	v4 = float32(float64(a1))
	v5 = float32(float64(a2))
	for {
		obj := v2.Field0
		obj.PosVec.X = v4 + obj.PosVec.X
		obj.PosVec.Y = v5 + obj.PosVec.Y
		nox_xxx_createAt_4DAA50(obj, nil, obj.PosVec.X, obj.PosVec.Y)
		obj.ObjFlags |= 0x80000000
		v2 = v2.Field4
		if v2 == nil {
			break
		}
	}
	return 1
}
func sub_504980() *server.Object {
	if (dword_5d4594_1599480 == dword_5d4594_3835396 && dword_5d4594_1599480 != -1 && dword_5d4594_1599476 != 1 || nox_xxx_mapgenSaveMap_503830(dword_5d4594_3835396) != 0) && dword_5d4594_1599540 != nil {
		return dword_5d4594_1599540.Field0
	} else {
		return nil
	}
}
func sub_5049C0(a1 *server.Object) *server.Object {
	if a1 == nil {
		return nil
	}
	return a1.ObjNext
}
func sub_5049D0() *UnitListXxx {
	return dword_5d4594_1599540
}
func sub_5049E0(a1 *UnitListXxx) *UnitListXxx {
	if a1 == nil {
		return nil
	}
	return a1.Field4
}
func sub_504A10(a1 *server.Object) int32 {
	if a1 == nil {
		return 0
	}
	v1 := dword_5d4594_1599540
	if dword_5d4594_1599540 == nil {
		return 0
	}
	for v1.Field0 != a1 {
		v1 = v1.Field4
		if v1 == nil {
			return 0
		}
	}
	v3 := v1.Field4
	if v3 != nil {
		v3.Field8 = v1.Field8
	}
	v4 := v1.Field8
	if v4 != nil {
		v4.Field4 = v1.Field4
	}
	if v1 == dword_5d4594_1599540 {
		dword_5d4594_1599540 = v1.Field4
	}
	v5 := v1.Field0.ObjNext
	if v5 != nil {
		v5.ObjPrev = v1.Field0.ObjPrev
	}
	v6 := v1.Field0.ObjPrev
	if v6 != nil {
		v6.ObjNext = v1.Field0.ObjNext
	}
	nox_xxx_objectFreeMem_4E38A0(v1.Field0)
	alloc.Free(v1)
	return 1
}
func sub_505060() {
	if dword_5d4594_1599616 != nil {
		alloc.FreePtr(dword_5d4594_1599616)
		dword_5d4594_1599616 = nil
	}
}
func nox_server_mapRWMapIntro_505080() int32 {
	var (
		v0  *FILE
		v1  int32
		v2  *byte
		v3  int16
		v4  uint8
		v5  *byte
		v6  *byte
		v7  uint8
		v8  int16
		v9  int32
		v10 *FILE
		v11 *FILE
		v13 *uint8
		v14 *uint8
		i   int32
		v16 int8
		v17 uint32
		v18 int32
		v19 [1024]byte
	)
	v0 = nil
	v18 = 1
	v17 = 0
	v1 = bool2int32(noxflags.HasGame(0x200000))
	sub_505060()
	v2 = nox_fs_root()
	v3 = int16(*memmap.PtrUint16(0x587000, 229832))
	libc.StrCpy(&v19[0], v2)
	v4 = *memmap.PtrUint8(0x587000, 229834)
	v5 = &v19[libc.StrLen(&v19[0])]
	*(*uint32)(unsafe.Pointer(v5)) = *memmap.PtrUint32(0x587000, 229828)
	*(*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*2)) = uint16(v3)
	*(*byte)(unsafe.Add(unsafe.Pointer(v5), 6)) = v4
	libc.StrCat(&v19[0], nox_xxx_mapGetMapName_409B40())
	*(*uint16)(unsafe.Pointer(&v19[libc.StrLen(&v19[0])])) = *memmap.PtrUint16(0x587000, 229836)
	libc.StrCat(&v19[0], nox_xxx_mapGetMapName_409B40())
	v6 = &v19[libc.StrLen(&v19[0])+1]
	v7 = *memmap.PtrUint8(0x587000, 229844)
	v8 = int16(v18)
	*(*uint32)(unsafe.Pointer(func() *byte {
		p := &v6
		*p = (*byte)(unsafe.Add(unsafe.Pointer(*p), -1))
		return *p
	}())) = *memmap.PtrUint32(0x587000, 229840)
	*(*byte)(unsafe.Add(unsafe.Pointer(v6), 4)) = v7
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 2)
	if int32(v8) > int32(int16(v18)) {
		return 0
	}
	v9 = 0
	if nox_crypt_IsReadOnly() != 0 {
		if nox_crypt_IsReadOnly() != 1 {
			return 0
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v17)), 4)
		if int32(v17) <= 0 {
			return 1
		}
		if noxflags.HasGame(0x400000) {
			nox_xxx_cryptSeekCur_40E0A0(int32(v17))
			return 1
		}
		if v1 != 0 {
			v0 = nox_fs_create(&v19[0])
			if v0 == nil {
				return 0
			}
			v14 = (*uint8)(v18)
		} else {
			v13 = (*uint8)(alloc.Calloc1(1, uintptr(v17)))
			dword_5d4594_1599616 = unsafe.Pointer(v13)
			if v13 == nil {
				return 0
			}
			v14 = v13
		}
		for i = 0; i < int32(v17); i++ {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v16)), 1)
			if v1 != 0 {
				nox_fs_fwrite(v0, unsafe.Pointer(&v16), 1)
			} else {
				*func() *uint8 {
					p := &v14
					x := *p
					*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
					return x
				}() = uint8(v16)
			}
		}
		if v0 != nil {
			nox_fs_close(v0)
		}
		return 1
	}
	if v1 != 0 && (func() bool {
		v10 = nox_fs_open(&v19[0])
		return (func() *FILE {
			v11 = v10
			return v11
		}()) != nil
	}()) {
		v17 = uint32(nox_fs_fsize(v11))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v17)), 4)
		if int32(v17) > 0 {
			for {
				nox_fs_fread(v11, unsafe.Pointer(&v16), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v16)), 1)
				v9++
				if v9 >= int32(v17) {
					break
				}
			}
		}
		nox_fs_close(v11)
		return 1
	} else {
		v17 = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v17)), 4)
		return 1
	}
}
func nox_server_mapRWGroupData_505C30() int32 {
	var (
		v0  int8
		v8  bool
		v9  *byte
		v10 *byte
		v12 int32
		v14 [2]byte
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 [4]int32
		v21 int32
	)
	var v22 int32
	var v23 [76]byte
	var v24 [76]byte
	var v25 [76]byte
	var v26 [76]byte
	v15 = 3
	v0 = int8(nox_xxx_wallGet_426A30())
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v15)), 2)
	if int32(int16(v15)) > 3 {
		return 0
	}
	if nox_crypt_IsReadOnly() != 0 {
		v21 = 0
		v22 = 0
		var v13 int32
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13)), 4)
		if v13 <= 0 {
			return 1
		}
		for v2 := int32(0); v2 < v13; v2++ {
			v17 = 0
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v17)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v23[0], uint32(uint8(int8(v17))))
			v23[v17] = 0
			v8 = int32(uint16(int16(v15))) == 2
			if int32(int16(v15)) < 2 {
				if libc.StrLen(nox_server_currentMapGetFilename_409B30())+1+libc.StrLen(&v23[0]) >= 0x35 {
					return 0
				}
				v9 = nox_server_currentMapGetFilename_409B30()
				nox_sprintf(&v25[0], internCStr("%s.map:%s"), v9, &v23[0])
				libc.StrCpy(&v23[0], &v25[0])
				v8 = int32(uint16(int16(v15))) == 2
			}
			if v8 {
				libc.StrCpy(&v14[0], internCStr(":"))
				libc.StrCpy(&v24[0], nox_server_currentMapGetFilename_409B30())
				*(*uint16)(unsafe.Pointer(&v24[libc.StrLen(&v24[0])])) = *memmap.PtrUint16(0x587000, 229976)
				libc.StrCpy(&v26[0], &v23[0])
				libc.StrTok(&v26[0], &v14[0])
				v10 = libc.StrTok(nil, &v14[0])
				if libc.StrLen(nox_server_currentMapGetFilename_409B30())+1+libc.StrLen(v10) >= 0x35 {
					return 0
				}
				libc.StrCat(&v24[0], v10)
				libc.StrCpy(&v23[0], &v24[0])
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v16)), 4)
			if (int32(v0) & 4) == 0 {
				if noxflags.HasGame(0x400000) {
					sub_504600(&v23[0], uint32(v16), uint8(int8(v18)))
				} else if noxflags.HasGame(2097153) {
					nox_server_mapLoadAddGroup_57C0C0(&v23[0], uint32(v16), uint8(int8(v18)))
				}
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 4)
			for v11 := int32(0); v11 < v12; v11++ {
				if int32(uint8(int8(v18))) != 0 {
					if int32(uint8(int8(v18))) == 1 {
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19[0])), 4)
					} else if int32(uint8(int8(v18))) != 2 {
						if int32(uint8(int8(v18))) != 3 {
							return 0
						}
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19[0])), 4)
					} else {
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19[0])), 4)
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19[1])), 4)
					}
				} else {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19[0])), 4)
				}
				if (int32(v0) & 4) == 0 {
					if noxflags.HasGame(0x400000) {
						sub_5046A0((*uint32)(unsafe.Pointer(&v19[0])), uint32(v16))
					} else {
						sub_57C130((*uint32)(unsafe.Pointer(&v19[0])), v16)
					}
				}
			}
		}
		return 1
	}
	var v13 int32 = 0
	for i := nox_server_getFirstMapGroup_57C080(); i != nil; i = nox_server_getNextMapGroup_57C090(i) {
		v13++
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13)), 4)
	for v4 := nox_server_getFirstMapGroup_57C080(); v4 != nil; v4 = nox_server_getNextMapGroup_57C090(v4) {
		*(*uint8)(unsafe.Pointer(&v17)) = uint8(int8(libc.StrLen((*byte)(unsafe.Add(unsafe.Pointer(v4), 8))) + 1))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v17)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 8)), uint32(uint8(int8(v17))))
		typ := byte(v4.GroupType())
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&typ, 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 4)), 4)
		v12 = 0
		for j := v4.List; j != nil; j = j.Next8 {
			v12++
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 4)
		for v6 := v4.List; v6 != nil; v6 = v6.Next8 {
			v7 := v4.GroupType()
			if v7 == 0 || v7 == 1 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6.Raw0)), 4)
			} else if v7 != 2 {
				if v7 != 3 {
					return 0
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6.Raw0)), 4)
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6.Raw0)), 4)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6.Raw4)), 4)
			}
		}
	}
	return 1
}
func nox_server_mapRWWaypoints_506260(a1 *uint32) int32 {
	var (
		v3  *uint32
		v5  int32
		v6  *uint8
		v7  *byte
		v9  *server.Waypoint
		v10 *uint8
		v11 int32
		v12 *uint8
		v13 *uint8
		v14 int32
		v15 *uint8
		v16 *uint8
		v17 *server.Waypoint
		v18 int32
		v19 int32
		v20 int32
		v21 uint32
		v22 float32
		v23 float32
		v24 int32
		v25 int32
		v26 Point32
		v27 int32
		v28 int64
	)
	var v29 int64
	var v30 int4
	var v31 [76]byte
	v18 = 4
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 2)
	if int32(int16(v18)) > 4 {
		return 0
	}
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19)), 4)
		v24 = 0
		if v19 > 0 {
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v25)), 4)
				if int32(int16(v18)) < 4 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 4)
					v28 = int64(v21)
					v22 = float32(float64(v21))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 4)
					v29 = int64(v21)
					v23 = float32(float64(v21))
				} else {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 4)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v23)), 4)
				}
				if int32(int16(v18)) >= 3 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v20)), 1)
					if int32(uint8(int8(v20))) != 0 {
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v31[0], uint32(uint8(int8(v20))))
						v31[uint8(int8(v20))] = 0
					} else {
						v31[0] = *memmap.PtrUint8(0x5D4594, 1599648)
					}
				}
				if a1 != nil {
					v7 = nox_xxx_mapGetWallSize_426A70()
					sub_428170(unsafe.Pointer(a1), &v30)
					v22 = float32(float64(v22) - float64(int32(*(*uint32)(unsafe.Pointer(v7))*23)) + float64(v30.field_0) - 11.0)
					v23 = float32(float64(v23) - float64(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1))*23)) + float64(v30.field_4) - 11.0)
				}
				if noxflags.HasGame(0x400000) {
					v8 := sub_5044B0(v25, v22, v23)
					v9 = v8.Field0
					v17 = v8.Field0
				} else {
					v17 = nox_xxx_waypointNewNotMap_579970(v25, v22, v23)
					v9 = v17
				}
				if v9 == nil {
					break
				}
				if int32(int16(v18)) >= 3 {
					libc.StrCpy((*byte)(unsafe.Add(unsafe.Pointer(v9), 16)), &v31[0])
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v9), 480)), 4)
				if int32(int16(v18)) < 4 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 4)
					v10 = &v9.PointsCnt
					v9.PointsCnt = byte(v21)
				} else {
					v10 = &v9.PointsCnt
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v9.PointsCnt, 1)
				}
				if int32(int16(v18)) >= 2 {
					v14 = 0
					if int32(*v10) != 0 {
						v15 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 96))
						v16 = (*uint8)(unsafe.Add(unsafe.Pointer(v17), unsafe.Sizeof(float32(0))*87))
						for {
							nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v16, 4)
							nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v15, 1)
							v14++
							v16 = (*uint8)(unsafe.Add(unsafe.Pointer(v16), 4))
							v15 = (*uint8)(unsafe.Add(unsafe.Pointer(v15), 8))
							if v14 >= int32(*v10) {
								break
							}
						}
					}
				} else {
					v11 = 0
					if int32(*v10) != 0 {
						v12 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 96))
						v13 = (*uint8)(unsafe.Add(unsafe.Pointer(v17), unsafe.Sizeof(float32(0))*87))
						for {
							nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v13, 4)
							*v12 = 2
							v11++
							v13 = (*uint8)(unsafe.Add(unsafe.Pointer(v13), 4))
							v12 = (*uint8)(unsafe.Add(unsafe.Pointer(v12), 8))
							if v11 >= int32(*v10) {
								break
							}
						}
					}
				}
				if func() int32 {
					p := &v24
					*p++
					return *p
				}() >= v19 {
					return 1
				}
			}
			return 0
		}
		return 1
	}
	v19 = 0
	v2 := nox_xxx_waypointGetList_579860()
	if v2 != nil {
		for {
			v3 = a1
			if a1 == nil || (func() int32 {
				v26.X = int32(int64(v2.PosVec.X))
				v26.Y = int32(int64(v2.PosVec.Y))
				return nox_xxx_wallMath_427F30(&v26, (*int32)(unsafe.Pointer(a1)))
			}()) != 0 {
				v19++
			}
			v2 = nox_xxx_waypointNext_579870(v2)
			if v2 == nil {
				break
			}
		}
	} else {
		v3 = a1
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19)), 4)
	v4 := nox_xxx_waypointGetList_579860()
	if v4 == nil {
		return 1
	}
	for {
		if v3 == nil || (func() int32 {
			v26.X = int32(int64(v4.PosVec.X))
			v26.Y = int32(int64(v4.PosVec.Y))
			return nox_xxx_wallMath_427F30(&v26, (*int32)(unsafe.Pointer(v3)))
		}()) != 0 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v4, 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 8)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 12)), 4)
			*(*uint8)(unsafe.Pointer(&v20)) = uint8(int8(libc.StrLen((*byte)(unsafe.Add(unsafe.Pointer(v4), 16)))))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v20)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v4), 16)), uint32(uint8(int8(v20))))
			v27 = int32(v4.Flags & 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v27)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v4.PointsCnt, 1)
			v5 = 0
			if v4.PointsCnt != 0 {
				v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 96))
				for {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(*(**uint8)(unsafe.Add(unsafe.Pointer(v6), -int(unsafe.Sizeof((*uint8)(nil))*1))), 4)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v6, 1)
					v5++
					v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 8))
					if v5 >= int32(v4.PointsCnt) {
						break
					}
				}
			}
			v3 = a1
		}
		v4 = nox_xxx_waypointNext_579870(v4)
		if v4 == nil {
			break
		}
	}
	return 1
}

type Vote struct {
	Field0  uint32 // 0, 0
	Field4  uint32 // 1, 4
	Field8  uint32 // 2, 8
	Field12 uint32 // 3, 12
	Field16 uint32 // 4, 16
	Field20 uint32 // 5, 20
	Field24 uint32 // 6, 24
	Field28 uint32 // 7, 28
	Field32 uint32 // 8, 32
	Field36 uint32 // 9, 36
	Field40 uint32 // 10, 40
	Field44 *Vote  // 11, 44
	Field48 *Vote  // 12, 48
}

func nox_xxx_allocVoteArray_5066D0() int32 {
	nox_alloc_vote_1599652 = alloc.NewClassT("VoteClass", Vote{}, 64)
	dword_5d4594_1599656 = nil
	return 1
}
func sub_506720() int32 {
	nox_alloc_vote_1599652.Free()
	dword_5d4594_1599656 = nil
	return 0
}
func sub_506740(a1 *server.Object) {
	if a1 == nil {
		return
	}
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 == 0 {
		return
	}
	result := dword_5d4594_1599656
	v2 := 1 << int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 276)), 2064)))
	if dword_5d4594_1599656 == nil {
		return
	}
	for {
		v3 := int32(result.Field8)
		v4 := int32(result.Field44)
		if v3&v2 != 0 {
			result.Field8 = uint32(^v2 & int(v3))
			*(*uint8)(unsafe.Add(unsafe.Pointer(result), 4))--
		}
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(result), 4))) == 0 {
			sub_5067B0(result)
		}
		result = v4
		if v4 == 0 {
			break
		}
	}
}
func sub_5067B0(a1 *Vote) {
	var v1 int32
	if a1 != nil {
		if *(*uint32)(a1) == 2 {
			v1 = 0
			for {
				if uint32(1<<v1)&a1.Field8 != 0 {
					nox_xxx_netSendVote_506840(v1)
				}
				v1++
				if v1 >= 32 {
					break
				}
			}
		}
		sub_506810(a1)
		nox_alloc_vote_1599652.FreeObjectFirst(a1)
		if dword_5d4594_1599656 == nil {
			sub_507190(math.MaxUint8, 0)
		}
	}
}
func sub_506810(a1 int32) int32 {
	var (
		result int32
		v2     int32
		v3     int32
	)
	result = a1
	v2 = int32(*(*uint32)(unsafe.Add(a1, 44)))
	if v2 != 0 {
		*(*uint32)(unsafe.Add(v2, 48)) = *(*uint32)(unsafe.Add(a1, 48))
	}
	v3 = int32(*(*uint32)(unsafe.Add(a1, 48)))
	if v3 != 0 {
		result = int32(*(*uint32)(unsafe.Add(a1, 44)))
		*(*uint32)(unsafe.Add(v3, 44)) = uint32(result)
	} else {
		dword_5d4594_1599656 = *(*uint32)(unsafe.Add(a1, 44))
	}
	return result
}
func nox_xxx_netSendVote_506840(a1 int32) int32 {
	var v2 [2]byte
	v2[0] = 238
	v2[1] = 7
	return nox_xxx_netSendPacket1_4E5390(a1, unsafe.Pointer(&v2[0]), 2, nil, 1)
}
func sub_506870(a1 int32, a2 *server.Object, a3 *wchar2_t) {
	if a2 != nil && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 8)))&4 != 0 {
		switch a1 {
		case 0:
			sub_5068E0(0, a2, a3)
		case 1:
			sub_5068E0(1, a2, a3)
		case 2:
			sub_506B00(2, a2)
		case 3:
			sub_506B80(3, a2, a3)
		}
	}
}
func sub_5068E0(a1 int32, a2 *server.Object, a3 *wchar2_t) {
	if *memmap.PtrUint32(0x587000, 229980) > 0x20 {
		return
	}
	if *memmap.PtrUint32(0x587000, 229980) == 0 {
		return
	}
	if a3 == nil {
		return
	}
	if a2 == nil {
		return
	}
	v4 := 1 << int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a2.UpdateData, 276)), 2064)))
	v3 := nox_common_playerInfoGetFirst_416EA0()
	v5 := v3
	if v3 == nil {
		return
	}
	for {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 2092)) == 1 {
			if nox_wcscmp((*wchar2_t)(unsafe.Add(unsafe.Pointer(v5), 4704)), a3) == 0 {
				break
			}
		}
		v3 = nox_common_playerInfoGetNext_416EE0(v5)
		v5 = v3
		if v3 == nil {
			return
		}
	}
	if int32(v5.PlayerInd) == 31 {
		return
	}
	v6 := v5.PlayerUnit
	if v6 == nil {
		return
	}
	if a2 == v6 {
		return
	}
	if !(!nox_xxx_CheckGameplayFlags_417DA0(4) || nox_xxx_servCompareTeams_419150((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(a2), 48)), (*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(v6), 48))) != 0) {
		return
	}
	v7 := dword_5d4594_1599656
	if dword_5d4594_1599656 != nil {
		for *(*uint32)(v7) != uint32(a1) || v7.Field28 != v6 {
			v7 = v7.Field44
			if v7 == nil {
				break
			}
		}
	}
	if v7 == nil {
		v3d := sub_506A20(a1, unsafe.Pointer(a2))
		v7 = v3d
		if v3d == nil {
			return
		}
		v3d.Field28 = v6
		if nox_xxx_CheckGameplayFlags_417DA0(4) {
			v7.Field20 = 1
		}
	}
	v3e := int32(v7.Field8)
	if (v4 & int(v3e)) != 0 {
		return
	}
	v3f := uint8(int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 4))) + 1))
	v7.Field8 |= uint32(v4)
	*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 4)) = v3f
}
func sub_506A20(a1 int32, a2 unsafe.Pointer) *Vote {
	var (
		v2 int32
	)
	v2 = 0
	if a2 == nil || (int32(*(*uint8)(unsafe.Add(a2, 8)))&4) == 0 {
		return nil
	}
	if dword_5d4594_1599656 == nil {
		v2 = 1
	}
	v3 := nox_alloc_vote_1599652.NewObject()
	if v3 == nil {
		return nil
	}
	v3.Field0 = uint32(a1)
	v3.Field24 = gameFrame()
	v3.Field16 = unsafe.Add(a2, 48)
	switch a1 {
	case 0, 1:
		*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 12)) = *memmap.PtrUint8(0x587000, 229980)
	case 2, 3:
		*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 12)) = 6
	default:
		*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 12)) = *memmap.PtrUint8(0x587000, 229984)
	}
	nox_xxx_voteAddMB_506AD0(v3)
	if v2 != 0 {
		sub_507190(math.MaxUint8, 1)
	}
	return v3
}
func nox_xxx_voteAddMB_506AD0(a1 *Vote) {
	a1.Field48 = nil
	a1.Field44 = dword_5d4594_1599656
	if dword_5d4594_1599656 != nil {
		dword_5d4594_1599656.Field48 = a1
	}
	dword_5d4594_1599656 = a1
}
func sub_506B00(a1 int32, a2 *server.Object) {
	var (
		v3 int32
		v4 int8
	)
	if nox_server_resetQuestMinVotes_229988 == 0 {
		return
	}
	if a2 == nil {
		return
	}
	r1 := *(**uint32)(unsafe.Add(a2.UpdateData, 276))
	v3 = 1 << int32(*(*uint8)(unsafe.Add(unsafe.Pointer(r1), 2064)))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(r1), 4*1198)) == 0 {
		return
	}
	r2 := dword_5d4594_1599656
	if dword_5d4594_1599656 != nil {
		for r2.Field0 != uint32(a1) {
			r2 = r2.Field44
			if r2 == nil {
				break
			}
		}
	}
	if r2 == nil {
		r2 = sub_506A20(a1, unsafe.Pointer(a2))
		if r2 == nil {
			return
		}
		r2.Field20 = 0
	}
	if (r2.Field8 & uint32(v3)) != 0 {
		return
	}
	v4 = int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(r2), 4))) + 1)
	r2.Field8 |= uint32(v3)
	*(*uint8)(unsafe.Add(unsafe.Pointer(r2), 4)) = uint8(v4)
}
func sub_506B80(a1 int32, a2 *server.Object, a3 *wchar2_t) {
	if nox_server_kickQuestPlayerMinVotes_229992 == 0 {
		return
	}
	if a3 == nil {
		return
	}
	if a2 == nil {
		return
	}
	r2 := *(**uint32)(unsafe.Add(a2.UpdateData, 276))
	v4 := 1 << int32(*(*uint8)(unsafe.Add(unsafe.Pointer(r2), 2064)))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(r2), 4*1198)) == 0 {
		return
	}
	r3 := nox_common_playerInfoGetFirst_416EA0()
	v5 := r3
	if r3 == nil {
		return
	}
	for {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*523)) == 1 {
			r3 = (*uint32)(unsafe.Pointer(uintptr(nox_wcscmp((*wchar2_t)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(wchar2_t(0))*2352)), a3))))
			if r3 == nil {
				break
			}
		}
		r3 = nox_common_playerInfoGetNext_416EE0(v5)
		v5 = r3
		if r3 == nil {
			return
		}
	}
	if int32(v5.PlayerInd) == 31 {
		return
	}
	if v5.Field4792 == 0 {
		return
	}
	v6 := v5.PlayerUnit
	if v6 == nil {
		return
	}
	if a2 == v6 {
		return
	}
	r5 := dword_5d4594_1599656
	if dword_5d4594_1599656 != nil {
		for r5.Field0 != uint32(a1) || r5.Field28 != v6 {
			r5 = r5.Field44
			if r5 == nil {
				break
			}
		}
	}
	if r5 == nil {
		r5 = sub_506A20(a1, unsafe.Pointer(a2))
		if r5 == nil {
			return
		}
		r5.Field28 = v6
	}
	if (r5.Field8 & uint32(v4)) != 0 {
		return
	}
	v7 := int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(r5), 4))) + 1)
	r5.Field8 |= uint32(v4)
	*(*uint8)(unsafe.Add(unsafe.Pointer(r5), 4)) = uint8(v7)
}
func sub_506C90(a1 int32, a2 *server.Object, a3 *wchar2_t) {
	if a2 != nil && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a2), 8)))&4 != 0 {
		switch a1 {
		case 0:
			sub_506D00(a2, a3)
		case 1:
			sub_506D00(a2, a3)
		case 2:
			sub_506DE0(a2)
		case 3:
			sub_506E50(a2, a3)
		default:
			return
		}
	}
}
func sub_506D00(a1 *server.Object, a2 *wchar2_t) {
	var (
		v2 *byte
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 bool
	)
	if a1 != nil {
		if a2 != nil {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 {
				v2 = nox_common_playerInfoGetFirst_416EA0()
				if v2 != nil {
					for *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*523)) != 1 || nox_wcscmp((*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(wchar2_t(0))*2352)), a2) != 0 {
						v2 = nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(v2)))
						if v2 == nil {
							return
						}
					}
					if *(*byte)(unsafe.Add(unsafe.Pointer(v2), 2064)) != 31 {
						v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*514)))
						if v3 != 0 {
							v4 = int32(dword_5d4594_1599656)
							v5 = 1 << int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 276)), 2064)))
							if dword_5d4594_1599656 != nil {
								for *(*uint32)(v4) != 0 || *(*uint32)(unsafe.Add(v4, 28)) != uint32(v3) || (uint32(v5)&*(*uint32)(unsafe.Add(v4, 8))) == 0 {
									v4 = int32(*(*uint32)(unsafe.Add(v4, 44)))
									if v4 == 0 {
										return
									}
								}
								if v4 != 0 {
									v6 = int32(uint32(^v5) & *(*uint32)(unsafe.Add(v4, 8)))
									v7 = int32(func() uint8 {
										p := (*uint8)(unsafe.Add(v4, 4))
										x := *p
										*p--
										return x
									}()) == 1
									*(*uint32)(unsafe.Add(v4, 8)) = uint32(v6)
									if v7 {
										sub_5067B0(v4)
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
func sub_506DE0(a1 *server.Object) {
	var (
		result int32
		v2     int32
		v3     int8
		v4     int32
	)
	if a1 != nil {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 {
			result = int32(dword_5d4594_1599656)
			v2 = 1 << int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 276)), 2064)))
			if dword_5d4594_1599656 != nil {
				for *(*uint32)(result) != 2 {
					result = int32(*(*uint32)(unsafe.Add(result, 44)))
					if result == 0 {
						return
					}
				}
				if result != 0 && uint32(v2)&*(*uint32)(unsafe.Add(result, 8)) != 0 {
					v3 = int8(int32(*(*uint8)(unsafe.Add(result, 4))) - 1)
					v4 = int32(uint32(^v2) & *(*uint32)(unsafe.Add(result, 8)))
					*(*uint8)(unsafe.Add(result, 4)) = uint8(v3)
					*(*uint32)(unsafe.Add(result, 8)) = uint32(v4)
					if int32(v3) == 0 {
						sub_5067B0(result)
					}
				}
			}
		}
	}
}
func sub_506E50(a1 *server.Object, a2 *wchar2_t) {
	var (
		v2 *byte
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 bool
	)
	if a1 != nil {
		if a2 != nil {
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 {
				v2 = nox_common_playerInfoGetFirst_416EA0()
				if v2 != nil {
					for *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*523)) != 1 || nox_wcscmp((*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(wchar2_t(0))*2352)), a2) != 0 {
						v2 = nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(v2)))
						if v2 == nil {
							return
						}
					}
					if *(*byte)(unsafe.Add(unsafe.Pointer(v2), 2064)) != 31 {
						v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*514)))
						if v3 != 0 {
							v4 = int32(dword_5d4594_1599656)
							v5 = 1 << int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 276)), 2064)))
							if dword_5d4594_1599656 != nil {
								for *(*uint32)(v4) != 3 || *(*uint32)(unsafe.Add(v4, 28)) != uint32(v3) || (uint32(v5)&*(*uint32)(unsafe.Add(v4, 8))) == 0 {
									v4 = int32(*(*uint32)(unsafe.Add(v4, 44)))
									if v4 == 0 {
										return
									}
								}
								if v4 != 0 {
									v6 = int32(uint32(^v5) & *(*uint32)(unsafe.Add(v4, 8)))
									v7 = int32(func() uint8 {
										p := (*uint8)(unsafe.Add(v4, 4))
										x := *p
										*p--
										return x
									}()) == 1
									*(*uint32)(unsafe.Add(v4, 8)) = uint32(v6)
									if v7 {
										sub_5067B0(v4)
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
func sub_506F80(a1 int32) {
	var (
		v1 int32
		v3 int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 28)))
	if int32(*(*uint8)(unsafe.Add(v1, 16)))&0x20 != 0 {
		sub_5067B0(a1)
		return
	}
	*(*uint32)(unsafe.Add(a1, 16)) = uint32(v1 + 48)
	if sub_507000(a1) == 1 {
		v3 = int32(*(*uint32)(unsafe.Add(v1, 748)))
		nox_xxx_playerCallDisconnect_4DEAB0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 2064))), 4)
		sub_416770(15, (*wchar2_t)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 4704)), (*byte)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 2112)))
		sub_5067B0(a1)
	}
}
func sub_507000(a1 int32) int32 {
	var (
		v1 int32
		j  int32
	)
	v1 = 0
	if int32(*(*uint8)(unsafe.Add(a1, 4))) >= int32(*(*uint8)(unsafe.Add(a1, 12))) {
		return 1
	}
	if *(*uint32)(unsafe.Add(a1, 20)) == 1 {
		for i := nox_xxx_getFirstPlayerUnit_4DA7C0(); i != nil; i = nox_xxx_getNextPlayerUnit_4DA7F0(i) {
			if nox_xxx_servCompareTeams_419150(*(*unsafe.Pointer)(unsafe.Add(a1, 16)), (*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(i), 48))) != 0 {
				v1++
			}
		}
	} else {
		for j = nox_xxx_getFirstPlayerUnit_4DA7C0(); j != 0; j = nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(j)) {
			v1++
		}
	}
	return bool2int32(uint32(*(*uint8)(unsafe.Add(a1, 4))) >= uint32(v1-1) && int32(*(*uint8)(unsafe.Add(a1, 4))) >= 2)
}
func sub_507090(a1 int32) {
	var (
		i  int32
		v3 int32
		v4 *byte
	)
	nox_xxx_player_4E3CE0()
	if int32(*(*uint8)(unsafe.Add(a1, 4))) >= nox_xxx_player_4E3CE0() {
		for i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i != 0; i = nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(i)) {
			v3 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i, 748)), 276)))
			if *(*uint32)(unsafe.Add(v3, 4792)) == 1 {
				Nox_xxx_playerRespawn_4F7EF0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v3, 2056))))
			}
		}
		nox_game_setQuestStage_4E3CD0(0)
		v4 = nox_xxx_getQuestMapFile_4D0F60()
		nox_xxx_mapLoad_4D2450(v4)
		sub_5067B0(a1)
	}
}
func sub_507100(a1 int32) {
	var (
		v1     int32
		v2     int32
		v3     uint32
		result uint32
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 28)))
	if v1 == 0 {
		sub_5067B0(a1)
		return
	}
	if int32(*(*uint8)(unsafe.Add(v1, 16)))&0x20 != 0 {
		sub_5067B0(a1)
		return
	}
	v2 = int32(*(*uint32)(unsafe.Add(v1, 748)))
	if *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 4792)) == 0 {
		sub_5067B0(a1)
		return
	}
	if int32(*(*uint8)(unsafe.Add(a1, 4))) >= int32(*(*uint8)(unsafe.Add(a1, 12))) {
		goto LABEL_8
	}
	v3 = uint32(nox_xxx_player_4E3CE0())
	if v3 <= 1 {
		sub_5067B0(a1)
		return
	}
	result = v3 - 1
	if uint32(*(*uint8)(unsafe.Add(a1, 4))) < result || int32(*(*uint8)(unsafe.Add(a1, 4))) < 2 {
		return
	}
LABEL_8:
	sub_4DCFB0((*server.Object)(v1))
	sub_416770(15, (*wchar2_t)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 4704)), (*byte)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 2112)))
	sub_5067B0(a1)
	return
}
func sub_507190(a1 int32, a2 int8) int32 {
	var v4 [3]byte
	v4[0] = 238
	v4[1] = 6
	v4[2] = byte(a2)
	return nox_xxx_netSendPacket1_4E5390(a1, unsafe.Pointer(&v4[0]), 3, nil, 1)
}
func sub_5071C0() int32 {
	return bool2int32(dword_5d4594_1599656 != nil)
}
func sub_509120(a1 *uint32, a2 int32, a3 *byte) {
	var (
		v3 *byte
		v4 int32
		v5 *uint32
		v6 *byte
		v7 *uint32
		v8 int32
		v9 *uint32
	)
	v3 = (*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*189)))
	if v3 != nil {
		if a2 == 14 {
			if noxflags.HasGame(6291456) {
				libc.StrCpy(v3, a3)
			} else {
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*192)) = uint32(nox_script_indexByEvent(a3))
			}
			return
		}
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
		if v4&0x200 != 0 {
			v5 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*187)))
			if a2 != 0 {
				if a2 == 1 {
					if !noxflags.HasGame(6291456) {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*6)) = uint32(nox_script_indexByEvent(a3))
						return
					}
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 256))
				} else {
					if a2 != 2 {
						return
					}
					if !noxflags.HasGame(6291456) {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*8)) = uint32(nox_script_indexByEvent(a3))
						return
					}
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 384))
				}
			} else {
				if !noxflags.HasGame(6291456) {
					*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*4)) = uint32(nox_script_indexByEvent(a3))
					return
				}
				v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 512))
			}
			libc.StrCpy(v6, a3)
			return
		}
		if v4&2 != 0 {
			v7 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*187)))
			switch a2 {
			case 3:
				if noxflags.HasGame(6291456) {
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 640))
					libc.StrCpy(v6, a3)
					return
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*309)) = uint32(nox_script_indexByEvent(a3))
			case 4:
				if noxflags.HasGame(6291456) {
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 768))
					libc.StrCpy(v6, a3)
					return
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*307)) = uint32(nox_script_indexByEvent(a3))
			case 5:
				if noxflags.HasGame(6291456) {
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 896))
					libc.StrCpy(v6, a3)
					return
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*317)) = uint32(nox_script_indexByEvent(a3))
			case 6:
				if noxflags.HasGame(6291456) {
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1024))
					libc.StrCpy(v6, a3)
					return
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*311)) = uint32(nox_script_indexByEvent(a3))
			case 7:
				if noxflags.HasGame(6291456) {
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1152))
					libc.StrCpy(v6, a3)
					return
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*313)) = uint32(nox_script_indexByEvent(a3))
			case 8:
				if noxflags.HasGame(6291456) {
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1280))
					libc.StrCpy(v6, a3)
					return
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*315)) = uint32(nox_script_indexByEvent(a3))
			case 9:
				if noxflags.HasGame(6291456) {
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1408))
					libc.StrCpy(v6, a3)
					return
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*319)) = uint32(nox_script_indexByEvent(a3))
			case 10:
				if noxflags.HasGame(6291456) {
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1536))
					libc.StrCpy(v6, a3)
					return
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*321)) = uint32(nox_script_indexByEvent(a3))
			case 11:
				if noxflags.HasGame(6291456) {
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1664))
					libc.StrCpy(v6, a3)
					return
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*323)) = uint32(nox_script_indexByEvent(a3))
			case 13:
				if noxflags.HasGame(6291456) {
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1792))
					libc.StrCpy(v6, a3)
					return
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*325)) = uint32(nox_script_indexByEvent(a3))
			default:
				return
			}
		} else {
			if v4&0x800 != 0 {
				v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*175)))
				if a2 != 12 {
					return
				}
				if !noxflags.HasGame(6291456) {
					*(*uint32)(unsafe.Add(v8, 4)) = uint32(nox_script_indexByEvent(a3))
					return
				}
				v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 128))
				libc.StrCpy(v6, a3)
				return
			}
			if uint32(v4)&0x20000 != 0 {
				v9 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*187)))
				switch a2 {
				case 15:
					if noxflags.HasGame(6291456) {
						v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1920))
						libc.StrCpy(v6, a3)
						return
					}
					*(*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*13)) = uint32(nox_script_indexByEvent(a3))
				case 16:
					if noxflags.HasGame(6291456) {
						v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 2048))
						libc.StrCpy(v6, a3)
						return
					}
					*(*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*15)) = uint32(nox_script_indexByEvent(a3))
				case 17:
					if noxflags.HasGame(6291456) {
						v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 2304))
						libc.StrCpy(v6, a3)
						return
					}
					*(*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*17)) = uint32(nox_script_indexByEvent(a3))
				case 18:
					if noxflags.HasGame(6291456) {
						v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 2176))
						libc.StrCpy(v6, a3)
						return
					}
					*(*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*19)) = uint32(nox_script_indexByEvent(a3))
				default:
					return
				}
			}
		}
	}
}
func sub_5095E0() {
	var (
		v0  *server.Team
		v1  int32
		v2  int32
		v4  int32
		v7  int32
		v8  int32
		v10 *server.Team
		v11 unsafe.Pointer
	)
	v2 = math.MaxInt32
	for i := nox_server_teamFirst_418B10(); i != nil; i = nox_server_teamNext_418B60(i) {
		v4 = int32(i.Lessons)
		if v4 <= v2 {
			v1 = bool2int32(v4 == v2 && v0 != nil)
			v2 = int32(i.Lessons)
			v10 = i
			v0 = i
		}
	}
	v5 := nox_xxx_getFirstPlayerUnit_4DA7C0()
	if v5 != nil {
		for {
			v6 := v5.UpdateData
			if nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(v5), 48))) == 0 {
				v7 = int32(*(*uint32)(unsafe.Add(v6, 276)))
				if (int32(*(*uint8)(unsafe.Add(v7, 3680))) & 1) == 0 {
					v8 = int32(*(*uint32)(unsafe.Add(v7, 2140)))
					if v8 <= v2 {
						v1 = bool2int32(v8 == v2 && v11 != nil)
						v2 = v8
						v11 = unsafe.Pointer(v5)
					}
				}
			}
			v5 = nox_xxx_getNextPlayerUnit_4DA7F0(v5)
			if v5 == nil {
				break
			}
		}
		v0 = v10
	}
	nox_xxx_setGameFlags_40A4D0(8)
	if v1 != 0 {
		nox_xxx_netSendDMTeamWinner_4D8BF0(nil, 1)
		return
	}
	if v11 != nil {
		nox_xxx_netSendDMWinner_4D8B90((*server.Object)(v11), 1)
		return
	}
	if v0 != nil {
		nox_xxx_netSendDMTeamWinner_4D8BF0(v0, 1)
	}
}
func sub_5096F0() int32 {
	var (
		result int32
		v1     *uint8
		v2     int32
		v3     int32
		v4     int32
		v5     int32
		v6     [5]byte
	)
	result = sub_40A1A0()
	if result == 0 {
		return result
	}
	if noxflags.HasGame(4096) {
		v1 = sub_4E8E50()
		nox_xxx_mapLoad_4D2450(v1)
		nox_xxx_netPrintLineToAll_4DA390(internCStr("chklimit.c:AutoExitToNextMap"))
		v2 = nox_xxx_getFirstPlayerUnit_4DA7C0()
		if v2 != 0 {
			for {
				v3 = int32(*(*uint32)(unsafe.Add(v2, 748)))
				if *(*uint32)(unsafe.Add(v3, 312)) == 0 && *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 4792)) == 1 {
					sub_4D60E0(v2)
				}
				v2 = nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(v2))
				if v2 == 0 {
					break
				}
			}
			return sub_40A1F0(0)
		}
		return sub_40A1F0(0)
	}
	if sub_40A300() == 0 {
		if noxflags.HasGame(96) {
			sub_5099B0()
			return sub_40A1F0(0)
		}
		if noxflags.HasGame(272) {
			sub_5098A0()
			return sub_40A1F0(0)
		}
		if noxflags.HasGame(1024) {
			sub_5095E0()
		}
		return sub_40A1F0(0)
	}
	nox_xxx_setGameFlags_40A4D0(0x4000000)
	v6[0] = 154
	v4 = nox_xxx_getFirstPlayerUnit_4DA7C0()
	if v4 == 0 {
		return sub_40A1F0(0)
	}
	for {
		v5 = int32(*(*uint32)(unsafe.Add(v4, 748)))
		if v5 != 0 {
			*(*uint16)(unsafe.Pointer(&v6[1])) = uint16(int16(int64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 276)), 3632)))))
			*(*uint16)(unsafe.Pointer(&v6[3])) = uint16(int16(int64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 276)), 3636)))))
			nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 276)), 2064))), 1, &v6[0], 5)
		}
		nox_xxx_aud_501960(582, (*server.Object)(v4), 2, int32(*(*uint32)(unsafe.Add(v4, 36))))
		v4 = nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(v4))
		if v4 == 0 {
			break
		}
	}
	return sub_40A1F0(0)
}
