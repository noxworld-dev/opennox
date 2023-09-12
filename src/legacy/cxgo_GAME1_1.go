package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/cnet"
	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/gotranspile/cxgo/runtime/stdio"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_418800(a1 *wchar2_t, a2 *wchar2_t, a3 int32) {
	if a1 != nil {
		nox_wcsncpy(a1, a2, 20)
		*(*wchar2_t)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(wchar2_t(0))*20)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*17)) = uint32(a3)
	}
}
func sub_418830(a1 unsafe.Pointer, a2 int32) {
	if a1 != nil {
		*(*uint32)(unsafe.Add(a1, 60)) = uint32(a2)
	}
}
func nox_xxx_unused_418840() int32 {
	var (
		v0 int32
		v1 *byte
		v2 *byte
		v3 int16
		v5 *byte
		v7 *uint32
		v8 int32
		v9 int32
	)
	v0 = 0
	v1 = (*byte)(sub_416640())
	v2 = sub_4165B0()
	nox_server_teamsZzz_419030(1)
	v3 = int16(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*26))) & 0x3FFF)
	*(*uint8)(unsafe.Add(unsafe.Pointer(&v3), unsafe.Sizeof(int16(0))-1)) |= 0x80
	*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*26)) = uint16(v3)
	for i := sub_425A50(); i != nil; i = sub_425A60(i) {
		if v0 >= int32(*(*byte)(unsafe.Add(unsafe.Pointer(v1), 52))) {
			break
		}
		v5 = (*byte)(unsafe.Pointer(nox_xxx_teamCreate_4186D0(0)))
		*(*int32)(unsafe.Add(i, 4*9)) = int32(uintptr(unsafe.Pointer(v5)))
		if v5 != nil {
			sub_418800((*wchar2_t)(unsafe.Pointer(v5)), (*wchar2_t)(unsafe.Add(i, unsafe.Sizeof(wchar2_t(0))*6)), 0)
			sub_418830(*(*unsafe.Pointer)(unsafe.Add(i, 4*9)), *(*int32)(unsafe.Add(i, 4*8)))
			sub_4184D0((*server.Team)(*(*unsafe.Pointer)(unsafe.Add(i, 4*9))))
			v0++
			for j := nox_xxx_getFirstPlayerUnit_4DA7C0(); j != nil; j = nox_xxx_getNextPlayerUnit_4DA7F0(j) {
				v7 = *(**uint32)(unsafe.Add(j.UpdateData, 276))
				if *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*515)) != nox_player_netCode_85319C || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
					v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*920)))
					if (v8&1) == 0 || v8&0x20 != 0 {
						v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*517)))
						if v9 != 0 {
							if v9 == *(*int32)(unsafe.Add(i, 4*8)) {
								nox_xxx_createAtImpl_4191D0(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i, 4*9)), 57)), unsafe.Add(unsafe.Pointer(j), 48), 1, int32(j.NetCode), 0)
							}
						}
					}
				}
			}
		}
	}
	for k := nox_xxx_getFirstPlayerUnit_4DA7C0(); k != nil; k = nox_xxx_getNextPlayerUnit_4DA7F0(k) {
		if nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(k), 48))) == 0 {
			v11 := *(*unsafe.Pointer)(unsafe.Add(k.UpdateData, 276))
			if (*(*uint32)(unsafe.Add(v11, 2060)) != nox_player_netCode_85319C || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) && (int32(*(*uint8)(unsafe.Add(v11, 3680)))&1) == 0 {
				nox_xxx_playerGoObserver_4E6860((*server.Player)(v11), 0, 0)
			}
		}
	}
	nox_xxx_SetGameplayFlag_417D50(4)
	return 1
}
func sub_4189D0() unsafe.Pointer {
	var (
		v0 unsafe.Pointer
		v1 uint8
	)
	v0 = nil
	v1 = 32
	for i := nox_server_teamFirst_418B10(); i != nil; i = nox_server_teamNext_418B60(i) {
		v3 := uint8(int8(sub_418BC0(unsafe.Pointer(i))))
		if int32(v3) < int32(v1) {
			v1 = v3
			v0 = unsafe.Pointer(i)
		}
	}
	return v0
}
func sub_418A10() *server.Team {
	result := nox_server_teamFirst_418B10()
	if result == nil {
		return nox_xxx_teamCreate_4186D0(0)
	}
	for result.Field60Val != 0 {
		result = nox_server_teamNext_418B60(result)
		if result == nil {
			return nox_xxx_teamCreate_4186D0(0)
		}
	}
	return result
}
func sub_418A40(a1 *wchar2_t) *server.Team {
	v1 := nox_server_teamFirst_418B10()
	if v1 == nil {
		return nil
	}
	for _nox_wcsicmp(&v1.NameBuf[0], a1) != 0 {
		v1 = nox_server_teamNext_418B60(v1)
		if v1 == nil {
			return nil
		}
	}
	return v1
}
func sub_418A80(a1 int32) *server.Team {
	result := nox_server_teamFirst_418B10()
	if result == nil {
		return nil
	}
	for int32(result.ColorInd) != a1 {
		result = nox_server_teamNext_418B60(result)
		if result == nil {
			return nil
		}
	}
	return result
}
func sub_418BC0(a1 unsafe.Pointer) int32 {
	var (
		v1 int32
	)
	v1 = 0
	if a1 == nil {
		return 0
	}
	for i := nox_common_playerInfoGetFirst_416EA0(); i != nil; i = nox_common_playerInfoGetNext_416EE0(i) {
		v4 := nox_xxx_objGetTeamByNetCode_418C80(i.NetCodeVal)
		if v4 != nil {
			if nox_xxx_teamCompare2_419180(v4, *(*uint8)(unsafe.Add(a1, 57))) != 0 {
				v1++
			}
		}
	}
	return v1
}
func nox_xxx_teamCheckSmth_418C60(a1 *server.Team) *server.ObjectTeam {
	if a1 == nil {
		return nil
	}
	return a1.Field44Val
}
func sub_418C70(a1 *server.ObjectTeam) *server.ObjectTeam {
	if a1 == nil {
		return nil
	}
	return a1.Field0
}
func nox_xxx_objGetTeamByNetCode_418C80(a1 uint32) *server.ObjectTeam {
	if noxflags.HasGame(1) {
		if obj := nox_server_getObjectFromNetCode_4ECCB0(a1); obj != nil {
			return obj.TeamPtr()
		}
	} else {
		if obj := nox_xxx_netSpriteByCodeDynamic_45A6F0(a1); obj != nil {
			return obj.TeamPtr()
		}
	}
	return nil
}
func nox_xxx_teamRenameMB_418CD0(a1 *wchar2_t, a2 *wchar2_t) {
	var (
		v2 int32
		v3 [46]byte
	)
	if a1 != nil {
		sub_457010(unsafe.Pointer(a1), a2)
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*17)) = 0
		if noxflags.HasGame(1) {
			v2 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 57)))
			*(*uint16)(unsafe.Pointer(&v3[0])) = 1220
			*(*uint32)(unsafe.Pointer(&v3[2])) = uint32(v2)
			nox_wcscpy((*wchar2_t)(unsafe.Pointer(&v3[6])), a2)
			nox_xxx_netSendPacket1_4E5390(159, unsafe.Pointer(&v3[0]), 46, nil, 1)
		}
		nox_wcscpy(a1, a2)
	}
}
func sub_418D80(a1 unsafe.Pointer) {
	var (
		v1 int32
		v5 [6]byte
	)
	if a1 != nil && sub_418BC0(a1) > 0 {
		if noxflags.HasGame(1) {
			v1 = int32(*(*uint8)(unsafe.Add(a1, 57)))
			v5[0] = 196
			v5[1] = 5
			*(*uint32)(unsafe.Pointer(&v5[2])) = uint32(v1)
			nox_xxx_netSendPacket1_4E5390(159, unsafe.Pointer(&v5[0]), 6, nil, 1)
		}
		for i := nox_common_playerInfoGetFirst_416EA0(); i != nil; i = nox_common_playerInfoGetNext_416EE0(i) {
			v3 := nox_xxx_objGetTeamByNetCode_418C80(i.NetCodeVal)
			v4 := v3
			if v3 != nil {
				if int32(v3.ID) == int32(*(*uint8)(unsafe.Add(a1, 57))) {
					sub_4571A0(int32(i.NetCodeVal), 0)
					Sub_418E40((*server.Team)(a1), v4)
				}
			}
		}
	}
}
func Sub_418E40(a1 *server.Team, a2 *server.ObjectTeam) {
	if a1 != nil && a2 != nil {
		if a1.Field44Val == a2 {
			a1.Field44Val = a2.Field0
		} else {
			result := nox_xxx_teamCheckSmth_418C60(a1)
			if result == nil {
				return
			}
			for result.Field0 != a2 {
				result = sub_418C70(result)
				if result == nil {
					return
				}
			}
			result.Field0 = a2.Field0
		}
		a2.Field0 = nil
		a2.ID = 0
		result := nox_xxx_getFirstPlayerUnit_4DA7C0()
		v3 := result
		if result != nil {
			for v3.TeamPtr() != a2 {
				result = nox_xxx_getNextPlayerUnit_4DA7F0(v3)
				v3 = result
				if result == nil {
					return
				}
			}
			v4 := v3.UpdateData
			sub_4D97E0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 2064))))
			sub_4E8110(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v4, 276)), 2064))))
			nox_xxx_monsterMarkUpdate_4E8020(v3)
			for i := v3.Field129; i != nil; i = i.Field128 {
				if i.ObjClass&6 != 0 {
					nox_xxx_monsterMarkUpdate_4E8020(i)
				}
			}
		}
	}
}
func nox_xxx_netChangeTeamID_419090(a1 unsafe.Pointer, a2 int32) {
	var (
		v2 int32
		v3 int32
		v4 [10]byte
	)
	if a1 != nil {
		*(*uint32)(unsafe.Add(a1, 52)) = uint32(a2)
		if noxflags.HasGame(1) {
			v2 = int32(*(*uint32)(unsafe.Add(a1, 52)))
			v3 = int32(*(*uint8)(unsafe.Add(a1, 57)))
			v4[0] = 196
			v4[1] = 8
			*(*uint32)(unsafe.Pointer(&v4[2])) = uint32(v3)
			*(*uint32)(unsafe.Pointer(&v4[6])) = uint32(v2)
			nox_xxx_netSendPacket1_4E5390(159, unsafe.Pointer(&v4[0]), 10, nil, 1)
		}
	}
}
func sub_4190F0(a1 *wchar2_t) int32 {
	v1 := nox_server_teamFirst_418B10()
	if v1 == nil {
		return 0
	}
	for _nox_wcsicmp((*wchar2_t)(unsafe.Pointer(v1)), a1) != 0 {
		v1 = nox_server_teamNext_418B60(v1)
		if v1 == nil {
			return 0
		}
	}
	return 1
}
func nox_xxx_servObjectHasTeam_419130(a1 *server.ObjectTeam) int32 {
	if a1 != nil {
		return bool2int32(a1.ID != 0)
	}
	return 0
}
func nox_xxx_servCompareTeams_419150(a1 *server.ObjectTeam, a2 *server.ObjectTeam) int32 {
	var (
		v2     int8
		v3     int8
		result int32
	)
	result = 0
	if a1 == nil {
		return result
	}
	if a2 == nil {
		return result
	}
	v2 = int8(a1.ID)
	if int32(v2) == 0 {
		return result
	}
	v3 = int8(a2.ID)
	if int32(v3) == 0 {
		return result
	}
	if int32(v2) == int32(v3) {
		result = 1
	}
	return result
}
func nox_xxx_teamCompare2_419180(a1 *server.ObjectTeam, a2 uint8) int32 {
	if a1 == nil {
		return 0
	}
	if int32(a1.ID) != int32(a2) {
		return 0
	}
	v2 := nox_xxx_getTeamByID_418AB0(int32(a2))
	if v2 == nil {
		return 0
	}
	v3 := nox_xxx_teamCheckSmth_418C60(v2)
	if v3 == nil {
		return 0
	}
	for v3 != a1 {
		v3 = sub_418C70(v3)
		if v3 == nil {
			return 0
		}
	}
	return 1
}
func nox_xxx_netChangeTeamMb_419570(a1 unsafe.Pointer, a2 int32) {
	var (
		v2 *byte
		v3 *byte
		v4 [6]byte
	)
	if a1 != nil {
		v2 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Add(a1, 4))))))
		if v2 != nil {
			if nox_xxx_teamCompare2_419180((*server.ObjectTeam)(a1), *(*uint8)(unsafe.Add(a1, 4))) != 0 {
				if noxflags.HasGame(1) && noxflags.HasGame(0x2000) {
					v3 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(a2)))
					if v3 != nil && false && !noxflags.HasGame(128) {
						sub_425ED0(unsafe.Pointer(v3), 0)
					}
					sub_4571A0(a2, 0)
					v4[0] = 196
					v4[1] = 2
					*(*uint32)(unsafe.Pointer(&v4[2])) = uint32(a2)
					nox_xxx_netSendPacket1_4E5390(159, unsafe.Pointer(&v4[0]), 6, nil, 1)
				}
				Sub_418E40((*server.Team)(unsafe.Pointer(v2)), (*server.ObjectTeam)(a1))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*12))--
				if (sub_40A740() != 0 || noxflags.HasGame(0x8000)) && sub_418BC0(unsafe.Pointer(v2)) == 0 {
					if noxflags.HasGame(96) || noxflags.HasGame(16) && nox_xxx_CheckGameplayFlags_417DA0(4) {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*15)) = 0
						sub_418800((*wchar2_t)(unsafe.Pointer(v2)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 527664)), 0)
					} else {
						sub_418F20((*server.Team)(unsafe.Pointer(v2)), 1)
					}
				}
			}
		}
	}
}
func sub_4196D0(a1 unsafe.Pointer, a2 unsafe.Pointer, a3 int32, a4 int32) int32 {
	var (
		v4 int32
		v5 *byte
		v7 [10]byte
	)
	if a1 == nil || a2 == nil || nox_xxx_teamCompare2_419180((*server.ObjectTeam)(a1), *(*uint8)(unsafe.Add(a1, 4))) == 0 {
		return 0
	}
	nox_common_playerInfoGetByID_417040(a3)
	if noxflags.HasGame(1) && noxflags.HasGame(0x2000) {
		v4 = int32(*(*uint8)(unsafe.Add(a2, 57)))
		v7[0] = 196
		v7[1] = 3
		*(*uint32)(unsafe.Pointer(&v7[2])) = uint32(v4)
		*(*uint16)(unsafe.Pointer(&v7[6])) = uint16(int16(a3))
		nox_xxx_netSendPacket1_4E5390(159, unsafe.Pointer(&v7[0]), 10, nil, 1)
		sub_4571A0(a3, int32(*(*uint8)(unsafe.Add(a2, 57))))
	}
	v5 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Add(a1, 4))))))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*12))--
	Sub_418E40((*server.Team)(unsafe.Pointer(v5)), (*server.ObjectTeam)(a1))
	nox_xxx_createAtImpl_4191D0(*(*uint8)(unsafe.Add(a2, 57)), a1, 0, a3, a4)
	if uint32(a3) == nox_player_netCode_85319C {
		sub_455E70(*(*uint8)(unsafe.Add(a2, 57)))
	}
	return 1
}
func sub_4197C0(a1 *wchar2_t, a2 int32) {
	var (
		v2 int32
		v3 *uint32
		v4 [18]byte
	)
	if a1 != nil {
		*(*uint32)(unsafe.Pointer(&v4[6])) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*15))
		*(*uint32)(unsafe.Pointer(&v4[2])) = uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 57)))
		*(*uint16)(unsafe.Pointer(&v4[0])) = 196
		*(*uint32)(unsafe.Pointer(&v4[10])) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*13))
		v4[14] = 0
		v4[16] = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 56))
		v4[17] = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 68))
		if noxflags.HasGame(512) {
			v4[14] = 1
		}
		v4[15] = byte(nox_wcslen(a1))
		v2 = int32(v4[15]) * 2
		v3 = (*uint32)(alloc.Calloc1(1, uintptr(v2+18)))
		*(*uint64)(unsafe.Pointer(v3)) = *(*uint64)(unsafe.Pointer(&v4[0]))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2)) = *(*uint32)(unsafe.Pointer(&v4[8]))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3)) = *(*uint32)(unsafe.Pointer(&v4[12]))
		*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*8)) = *(*uint16)(unsafe.Pointer(&v4[16]))
		alloc.Memcpy(unsafe.Add(unsafe.Pointer(v3), 18), unsafe.Pointer(a1), uintptr(v4[15])*2)
		nox_xxx_netSendPacket1_4E5390(a2, unsafe.Pointer(v3), v2+18, nil, 1)
		alloc.Free(v3)
	}
}
func sub_4198A0(a1 unsafe.Pointer, a2 int32, a3 int32) {
	var (
		v4 int32
		v5 [10]byte
	)
	if a1 != nil {
		v3 := unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(uint32(a3)))
		if v3 != nil {
			v5[0] = 196
			v4 = int32(*(*uint8)(unsafe.Add(a1, 4)))
			v5[1] = 1
			*(*uint16)(unsafe.Pointer(&v5[6])) = uint16(int16(a3))
			*(*uint32)(unsafe.Pointer(&v5[2])) = uint32(v4)
			*(*uint16)(unsafe.Pointer(&v5[8])) = *(*uint16)(unsafe.Add(v3, 4))
			nox_xxx_netSendPacket1_4E5390(a2, unsafe.Pointer(&v5[0]), 10, nil, 1)
		}
	}
}
func sub_419900(a1 unsafe.Pointer, a2 unsafe.Pointer, a3 int16) {
	var v4 [10]byte
	if a1 != nil && a2 != nil {
		result := int8(*(*uint8)(unsafe.Add(a1, 57)))
		if int32(*(*uint8)(unsafe.Add(a2, 4))) != int32(result) {
			*(*uint32)(unsafe.Pointer(&v4[2])) = uint32(*(*uint8)(unsafe.Add(a1, 57)))
			v4[0] = 196
			v4[1] = 10
			*(*uint16)(unsafe.Pointer(&v4[6])) = uint16(a3)
			nox_xxx_netClientSend2_4E53C0(31, unsafe.Pointer(&v4[0]), 10, 1)
		}
	}
}
func sub_419960(a1 unsafe.Pointer, a2 *server.ObjectTeam, a3 int16) {
	var v4 [10]byte
	if a1 != nil && a2 != nil {
		result := int8(*(*uint8)(unsafe.Add(a1, 57)))
		if int32(a2.ID) != int32(result) {
			*(*uint32)(unsafe.Pointer(&v4[2])) = uint32(*(*uint8)(unsafe.Add(a1, 57)))
			v4[0] = 196
			v4[1] = 11
			*(*uint16)(unsafe.Pointer(&v4[6])) = uint16(a3)
			nox_xxx_netClientSend2_4E53C0(31, unsafe.Pointer(&v4[0]), 10, 1)
		}
	}
}
func sub_419A10(a1 float32) float64 {
	*memmap.PtrFloat32(0x5D4594, 527672) = a1
	**(**uint32)(memmap.PtrOff(0x587000, 55744)) &= math.MaxInt32
	return float64(*memmap.PtrFloat32(0x5D4594, 527672))
}
func sub_419A30(a1 float32) uint32 {
	var result uint32
	if float64(a1) < 0.0 {
		return 0
	}
	*memmap.PtrUint32(0x5D4594, 527668) = uint32(uintptr(memmap.PtrOff(0x5D4594, 527676)))
	*memmap.PtrFloat32(0x5D4594, 527676) = float32(float64(a1) + 8.388608e+06)
	result = *memmap.PtrUint32(0x5D4594, 527676) & 0x7FFFFF
	*memmap.PtrUint32(0x5D4594, 527680) = *memmap.PtrUint32(0x5D4594, 527676) & 0x7FFFFF
	return result
}
func nox_float2int16(a1 float32) int16 {
	return int16(int32(a1))
}
func nox_float2int16_abs(a1 float32) int16 {
	return int16(int32(math.Abs(float64(a1))))
}
func sub_419E10(a1 *server.Object, a2 int32) {
	if a1 != nil && (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 16)))&0x20) == 0 {
		result := 1 << int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 276)), 2064)))
		if a2 != 0 {
			dword_5d4594_527712 |= uint32(result)
		} else {
			result = ^result
			dword_5d4594_527712 &= uint32(result)
		}
	}
}
func sub_419E60(a1p *server.Object) int32 {
	var (
		a1     = a1p
		result int32
	)
	if a1 != nil && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4 != 0 {
		result = bool2int32((dword_5d4594_527712 & uint32(1<<int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 276)), 2064))))) != 0)
	} else {
		result = 0
	}
	return result
}
func sub_419EA0() int32 {
	return bool2int32(dword_5d4594_527712 != 0)
}
func sub_41A000(a1 *byte, sv *Nox_savegame_xxx) int32 {
	var (
		result int32
		v3     int32
		v4     *uint8
		v5     int32
		v6     uint32
		v7     int8
		v8     *uint8
		v9     *byte
		v11    int32
		v12    [1276]byte
		v13    int16
	)
	sv.Field_1028[0] = *memmap.PtrUint8(0x5D4594, 527728)
	result = nox_xxx_cryptOpen_426910(a1, 1, 27)
	if result == 0 {
		return 0
	}
	for {
		var v10 int32 = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 4)
		if v10 == 0 {
			break
		}
		nox_xxx_fileCryptReadCrcMB_426C20((*uint8)(unsafe.Pointer(&v11)), 4)
		if v10 == 1 {
			alloc.Memcpy(unsafe.Pointer(&v12[0]), memmap.PtrOff(0x85B3FC, 10980), 1276)
			v3 = 0
			v13 = int16(*memmap.PtrUint16(0x85B3FC, 12256))
			if *memmap.PtrUint32(0x587000, 55936) != 0 {
				v4 = (*uint8)(memmap.PtrOff(0x587000, 55936))
				for unsafe.Pointer(v4) != memmap.PtrOff(0x587000, 55948) {
					v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*3)))
					v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 12))
					v3++
					if v5 == 0 {
						goto LABEL_10
					}
				}
				if ccall.AsFunc[func(unsafe.Pointer) int32](*memmap.PtrPtr(0x587000, 55956))(nil) == 0 {
					nox_xxx_cryptClose_4269F0()
					return 0
				}
			}
		LABEL_10:
			alloc.Memcpy(unsafe.Pointer(sv), memmap.PtrOff(0x85B3FC, 10980), unsafe.Sizeof(Nox_savegame_xxx{}))
			alloc.Memcpy(memmap.PtrOff(0x85B3FC, 10980), unsafe.Pointer(&v12[0]), 0x4FC)
			*memmap.PtrUint16(0x85B3FC, 12256) = uint16(v13)
		} else {
			nox_xxx_cryptSeekCur_40E0A0(v11)
		}
	}
	nox_xxx_cryptClose_4269F0()
	v6 = uint32(libc.StrLen(a1) + 1)
	v7 = int8(uint8(v6))
	v6 >>= 2
	alloc.Memcpy(unsafe.Pointer(&sv.Path[0]), unsafe.Pointer(a1), uintptr(v6*4))
	v9 = (*byte)(unsafe.Add(unsafe.Pointer(a1), v6*4))
	v8 = &sv.Path[v6*4]
	*(*uint8)(unsafe.Pointer(&v6)) = uint8(v7)
	alloc.Memcpy(unsafe.Pointer(v8), unsafe.Pointer(v9), uintptr(v6&3))
	return 1
}

type table_55816_t struct {
	name string
	ind  uint32
	fnc  func(*server.Object, unsafe.Pointer) int32
}

var table_55816 = []table_55816_t{
	{name: "Attrib Data", ind: 0x2, fnc: sub_41A590},
	{name: "Status Data", ind: 0x3, fnc: sub_41AA30},
	{name: "Inventory Data", ind: 0x4, fnc: sub_41AC30},
	{name: "FieldGuide Data", ind: 0x8, fnc: nox_xxx_guiFieldbook_41B420},
	{name: "Spellbook Data", ind: 0x5, fnc: nox_xxx_guiSpellbook_41B660},
	{name: "Enchantment Data", ind: 0x6, fnc: nox_xxx_guiEnchantment_41B9C0},
	{name: "Journal Data", ind: 0x9, fnc: sub_41BEC0},
	{name: "Game Data", ind: 0xA, fnc: sub_41C080},
	{name: "PAD_DATA", ind: 0xB, fnc: sub_41C200},
	{},
}
var table_55816_cnt = int32(len(table_55816) - 1)

func nox_xxx_mapSavePlayerDataMB_41A230(a1 *byte) int32 {
	var (
		v1 *byte
		v3 *uint8
		v5 int32
		v7 int32
	)
	v1 = a1
	if nox_xxx_cryptOpen_426910(a1, 2, 27) == 0 {
		return 0
	}
	if sub_45D9B0() != 0 {
		sub_45D870()
	}
	if (*byte)(memmap.PtrOff(0x85B3FC, 10984)) != v1 {
		libc.StrCpy((*byte)(memmap.PtrOff(0x85B3FC, 10984)), v1)
	}
	if *memmap.PtrUint32(0x587000, 55936) != 0 {
		v3 = (*uint8)(memmap.PtrOff(0x587000, 55944))
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v3), -4)), 4)
			nox_xxx_crypt_426C90()
			v5 = ccall.AsFunc[func(unsafe.Pointer) int32](*(*unsafe.Pointer)(unsafe.Pointer(v3)))(nil)
			nox_xxx_crypt_426D40()
			if v5 == 0 {
				nox_xxx_cryptClose_4269F0()
				return 0
			}
			v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)))
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 12))
			if v7 == 0 {
				break
			}
		}
	}
	a1 = nil
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
	nox_xxx_cryptClose_4269F0()
	return 1
}
func nox_xxx_cliPlrInfoLoadFromFile_41A2E0(path *byte, pind int32) int32 {
	result := nox_common_playerInfoFromNum_417090(pind)
	if result == nil {
		return 0
	}
	v3 := result.PlayerUnit
	if v3 == nil {
		return 0
	}
	var v4 *byte = (*byte)(unsafe.Add(unsafe.Pointer(result), 2185))
	if nox_xxx_cryptOpen_426910(path, 1, 27) == 0 {
		return 0
	}
	if noxflags.HasGame(2048) {
		nox_xxx_set_god_4EF500(0)
	}
	*memmap.PtrUint16(0x5D4594, 527696) = uint16(nox_xxx_unitGetHP_4EE780(v3))
	*memmap.PtrUint32(0x5D4594, 527696) = uint32(*memmap.PtrUint16(0x5D4594, 527696))
	*memmap.PtrUint16(0x5D4594, 527700) = uint16(nox_xxx_unitGetOldMana_4EEC80(v3))
	*memmap.PtrUint32(0x5D4594, 527700) = uint32(*memmap.PtrUint16(0x5D4594, 527700))
	sub_4EFF10(v3)
	sub_419E10(v3, 1)
	for {
		var a2b int32 = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2b)), 4)
		if a2b == 0 {
			nox_xxx_cryptClose_4269F0()
			sub_4EF140(v3)
			var v10 uint16 = uint16(nox_xxx_unitGetMaxHP_4EE7A0(v3))
			nox_xxx_unitDamageClear_4EE5E0(v3, int32(uint32(v10)-*memmap.PtrUint32(0x5D4594, 527696)))
			var v11 uint16 = uint16(nox_xxx_playerGetMaxMana_4EECB0(v3))
			nox_xxx_playerManaSub_4EEBF0(v3, int32(uint32(v11)-*memmap.PtrUint32(0x5D4594, 527700)))
			nox_xxx_playerHP_4EE730(v3)
			sub_419E10(v3, 0)
			return 1
		}
		var a1b int32 = 0
		nox_xxx_fileCryptReadCrcMB_426C20((*uint8)(unsafe.Pointer(&a1b)), 4)
		var csec *table_55816_t = nil
		for i := int32(0); i < table_55816_cnt; i++ {
			sec := &table_55816[i]
			if uint32(a2b) == sec.ind {
				csec = sec
				break
			}
		}
		if csec == nil {
			nox_xxx_cryptSeekCur_40E0A0(a1b)
			continue
		}
		if csec.fnc(v3, unsafe.Pointer(v4)) == 0 {
			v8 := v3.InvFirstItem
			if v8 != nil {
				var v9 unsafe.Pointer
				for {
					v9 = unsafe.Pointer(v8.InvNextItem)
					nox_xxx_delayedDeleteObject_4E5CC0(v8)
					v8 = (*server.Object)(v9)
					if v9 == nil {
						break
					}
				}
			}
			sub_419E10(v3, 0)
			nox_xxx_cryptClose_4269F0()
			return 0
		}
	}
}
func nox_xxx_plrLoad_41A480(a1 *byte) int32 {
	var (
		v2 int32
		v3 *uint8
		v4 int32
		v5 int32
		v6 int32
		v7 [1024]byte
	)
	libc.StrCpy(&v7[0], a1)
	if nox_xxx_cryptOpen_426910(a1, 1, 27) == 0 {
		return 0
	}
	sub_4602F0()
	for {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 4)
		if v5 == 0 {
			break
		}
		nox_xxx_fileCryptReadCrcMB_426C20((*uint8)(unsafe.Pointer(&v6)), 4)
		v2 = 0
		if *memmap.PtrUint32(0x587000, 55936) == 0 {
			nox_xxx_cryptSeekCur_40E0A0(v6)
			continue
		}
		v3 = (*uint8)(memmap.PtrOff(0x587000, 55936))
		for {
			if uint32(v5) == *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) {
				if ccall.AsFunc[func(unsafe.Pointer) int32](*memmap.PtrPtr(0x587000, uintptr(v2*12+55944)))(nil) == 0 {
					nox_xxx_cryptClose_4269F0()
					return 0
				}
				break
			}
			v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3)))
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 12))
			v2++
			if v4 == 0 {
				nox_xxx_cryptSeekCur_40E0A0(v6)
				break
			}
		}
	}
	nox_xxx_cryptClose_4269F0()
	libc.StrCpy((*byte)(memmap.PtrOff(0x85B3FC, 10984)), &v7[0])
	return 1
}
func sub_41A590(a1p *server.Object, a2p unsafe.Pointer) int32 {
	var (
		v3  unsafe.Pointer
		v4  unsafe.Pointer
		v6  uint32
		v7  int32
		v9  *byte
		v10 int32
		v12 float32
		v13 int32
		v14 int32
		v15 unsafe.Pointer
	)
	v2 := a2p
	if a2p == nil {
		return 0
	}
	if a1p != nil {
		v3 = a1p.UpdateData
		if v3 != nil {
			v15 = *(*unsafe.Pointer)(unsafe.Add(v3, 276))
			v4 = v15
		}
	}
	a2 := int32(5)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 2)
	if int32(int16(a2)) > 5 {
		return 0
	}
	if int32(int16(a2)) >= 5 {
		if noxflags.HasGame(4096) {
			v13 = 4
		} else {
			v13 = 2 - bool2int32(noxflags.HasGame(2048))
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13)), 4)
		if v4 != nil {
			if int32(*(*uint8)(unsafe.Add(v4, 2064))) != 31 {
				if noxflags.HasGame(4096) {
					if v13 != 4 {
						nox_xxx_playerCallDisconnect_4DEAB0(int32(*(*uint8)(unsafe.Add(v4, 2064))), 1)
						return 0
					}
				} else if v13 != 4 {
					goto LABEL_20
				}
				if !noxflags.HasGame(4096) {
					nox_xxx_playerCallDisconnect_4DEAB0(int32(*(*uint8)(unsafe.Add(v4, 2064))), 1)
					return 0
				}
			}
		}
	}
LABEL_20:
	*(*uint8)(unsafe.Pointer(&v14)) = uint8(nox_wcslen((*wchar2_t)(v2)))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 1)
	if int32(uint8(int8(v14))) >= 0x19 {
		return 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(v2), uint32(int32(uint8(int8(v14)))*2))
	*(*uint16)(unsafe.Add(v2, int32(uint8(int8(v14)))*2)) = 0
	if v3 != nil {
		nox_wcscpy((*wchar2_t)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 4704)), (*wchar2_t)(v2))
	}
	if nox_crypt_IsReadOnly() == 1 && v3 != nil {
		v6 = nox_wcslen((*wchar2_t)(v2))
		v7 = int32(nox_xxx_protectionStringCRCLen_56FAE0((*byte)(v2), v6*2))
		nox_xxx_playerResetProtectionCRC_56F7D0(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 4628)), uint32(v7))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 50)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 54)), 4)
	if nox_crypt_IsReadOnly() == 1 && v3 != nil {
		sub_56F780(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 4624)), int32(*(*uint32)(unsafe.Add(v2, 54))))
		sub_56F780(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 4620)), int32(*(*uint32)(unsafe.Add(v2, 50))))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 58)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 62)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 66)), 1)
	if nox_crypt_IsReadOnly() == 1 && v3 != nil {
		sub_56F820(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 4616)), *(*uint8)(unsafe.Add(v2, 66)))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 67)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 68)), 3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 71)), 3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 74)), 3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 77)), 3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 80)), 3)
	if int32(int16(a2)) >= 2 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 83)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 84)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 85)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 86)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 87)), 1)
	}
	v8 := a1p
	if nox_crypt_IsReadOnly() == 1 {
		if a1p != nil {
			v9 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(a1p.NetCode))))
			if v9 != nil {
				nox_xxx_playerInitColors_461460((*server.Player)(unsafe.Pointer(v9)))
			}
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 88)), 1)
	if int32(int16(a2)) >= 3 {
		v13 = 0
		if v3 != nil {
			v13 = int32(*(*uint32)(unsafe.Add(v3, 320)))
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13)), 4)
		if nox_crypt_IsReadOnly() == 1 && v3 != nil {
			*(*uint32)(unsafe.Add(v3, 320)) = uint32(v13)
		}
		v12 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("MaxExtraLives")))
		v10 = int32(v12)
		if v3 != nil && *(*uint32)(unsafe.Add(v3, 320)) > uint32(v10) {
			return 0
		}
		if int32(uint16(int16(a2))) == 3 {
			var a1 int32
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
		}
	}
	if nox_crypt_IsReadOnly() == 1 {
		sub_4D6000(v8)
	}
	if int32(int16(a2)) < 4 {
		return 1
	}
	v11 := v15
	var a1 int32
	if v15 != nil {
		a1 = int32(*(*uint32)(unsafe.Add(v15, 4696)))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
	if nox_crypt_IsReadOnly() != 1 {
		return 1
	}
	if !(v11 == nil || (func() bool {
		*(*uint32)(unsafe.Add(v11, 4696)) = uint32(a1)
		return nox_crypt_IsReadOnly() == 1
	}())) {
		return 1
	}
	if v3 != nil {
		sub_4D7450(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 2064))), int16(uint16(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v3, 276)), 4696)))))
	}
	return 1
}
func sub_41AA30(a1p *server.Object, a2 unsafe.Pointer) int32 {
	var result *byte
	var v4 int32
	var v5 int32
	var v6 int32
	var v7 int32
	var v8 int32
	v1 := a1p
	v2 := a1p.UpdateData
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(a1p.NetCode))))
	var a1 int32
	*(*uint8)(unsafe.Pointer(&a1)) = 1
	if result == nil {
		return int32(uintptr(unsafe.Pointer(result)))
	}
	v7 = 2
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 2)
	if int32(int16(v7)) > 2 {
		return 0
	}
	if !noxflags.HasGame(2048) {
		*(*uint8)(unsafe.Pointer(&a1)) = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
	if int32(uint8(int8(a1))) != 0 {
		result = (*byte)(unsafe.Pointer(uintptr(bool2int32(noxflags.HasGame(2048)))))
		if result == nil {
			return int32(uintptr(unsafe.Pointer(result)))
		}
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v4), unsafe.Sizeof(uint16(0))*0)) = uint16(nox_xxx_unitGetMaxHP_4EE7A0(v1))
		v6 = v4
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6)), 2)
		if nox_crypt_IsReadOnly() == 1 {
			nox_xxx_unitSetMaxHP_4EE7C0(v1, int16(v6))
			nox_xxx_unitSetHP_4E4560(v1, uint16(int16(v6)))
		}
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*0)) = uint16(nox_xxx_playerGetMaxMana_4EECB0(v1))
		v6 = v5
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6)), 2)
		if nox_crypt_IsReadOnly() == 1 {
			nox_xxx_playerSetMaxMana_4EECD0(v1, int16(v6))
			nox_xxx_playerManaRefresh_4EECF0(v1)
		}
		*memmap.PtrUint32(0x5D4594, 527696) = uint32(v1.HealthData.Cur)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 527696)), 2)
		*memmap.PtrUint32(0x5D4594, 527700) = uint32(*(*uint16)(unsafe.Add(v2, 4)))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 527700)), 2)
		*(*uint8)(unsafe.Pointer(&v8)) = v1.Field540
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 1)
		if nox_crypt_IsReadOnly() == 1 {
			nox_xxx_setSomePoisonData_4EEA90(v1, int32(uint8(int8(v8))))
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v1.Field541, 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 542)), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 28)), 4)
		if nox_crypt_IsReadOnly() == 1 {
			sub_56F8C0(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 4604)), v1.Experience)
			sub_4D81A0(v1)
		}
		if int32(int16(v7)) >= 2 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v1), 124)), 2)
			if nox_crypt_IsReadOnly() == 1 {
				v1.Direction2 = v1.Direction1
			}
		}
	}
	result = (*byte)(unsafe.Pointer(uintptr(1)))
	return int32(uintptr(unsafe.Pointer(result)))
}
func sub_41AC30(a1p *server.Object, a2p unsafe.Pointer) int32 {
	var (
		a1     = a1p
		result int32
		v3     int32
		v4     unsafe.Pointer
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     *byte
		v10    int32
		v11    *int32
		v14    *uint8
		v16    *uint8
		m      unsafe.Pointer
		v19    int32
		v20    int32
		v23    int32
		v26    int32
		v27    int32
		v32    *uint8
		v33    uint32
		v34    uint32
		l      int8
		v36    int8
		v37    int32
		k      int32
		v39    int32
		v41    int32
		v42    int32
		v43    int32
		v44    int32
		v45    int32
		v46    [256]byte
	)
	v1 := a1
	v36 = 1
	v40 := a1.UpdateData
	if *memmap.PtrUint32(0x5D4594, 527704) == 0 {
		*memmap.PtrUint32(0x5D4594, 527704) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Glyph")))
	}
	if nox_crypt_IsReadOnly() == 1 {
		sub_4EF140(a1)
	}
	v42 = 3
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v42)), 2)
	if int32(int16(v42)) > 3 {
		return 0
	}
	if noxflags.HasGame(0x2000) && !noxflags.HasGame(4096) {
		v36 = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v36)), 1)
	if int32(v36) == 0 {
		goto LABEL_115
	}
	if !noxflags.HasGame(2048) {
		result = bool2int32(noxflags.HasGame(4096))
		if result == 0 {
			return 0
		}
	}
	v44 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v40, 276)), 2164)))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 4)
	if nox_crypt_IsReadOnly() == 1 {
		v3 = nox_xxx_playerGetGold_4FA6B0(a1)
		nox_xxx_playerSubGold_4FA5D0(a1, uint32(v3))
		nox_xxx_playerAddGold_4FA590(a1, v44)
	}
	if nox_crypt_IsReadOnly() != 0 {
		v21 := a1.InvFirstItem
		if v21 != nil {
			for {
				v22 := v21.InvNextItem
				nox_xxx_delayedDeleteObject_4E5CC0(v21)
				v21 = v22
				if v22 == nil {
					break
				}
			}
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&k)), 4)
		if noxflags.HasGame(4096) && k > 2560 {
			return 0
		}
		v23 = 0
		if k > 0 {
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v39)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v46[0], uint32(uint8(int8(v39))))
				v46[uint8(int8(v39))] = 0
				v24p := nox_xxx_newObjectByTypeID_4E3810(&v46[0])
				v24 := v24p
				v25 := v24
				if v24p == nil {
					return 0
				}
				if v24p.Xfer.Get()(v24p, nil) == 0 {
					return 0
				}
				v25.PosVec.X = 1161297920
				v25.PosVec.Y = 1161297920
				if noxflags.HasGame(4096) {
					if sub_4F2590(v25) == 0 {
						return 0
					}
				}
				nox_xxx_servMapLoadPlaceObj_4F3F50(v25, a1, nil)
				nox_xxx_unitsNewAddToList_4DAC00()
				if nox_xxx_inventoryServPlace_4F36F0(a1, v25, 1, 1) == 0 {
					if !noxflags.HasGame(4096) {
						return 0
					}
					nox_xxx_delayedDeleteObject_4E5CC0(v25)
				}
				v26 = int32(v25.ObjFlags)
				if (v26&0x20) == 0 && v26&0x100 != 0 {
					nox_xxx_playerTryDequip_4F2FB0(a1, v25)
				}
				if func() int32 {
					p := &v23
					*p++
					return *p
				}() >= k {
					break
				}
			}
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v41)), 1)
		v27 = 0
		if int32(uint8(int8(v41))) != 0 {
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v37)), 4)
				for i := a1.InvFirstItem; i != nil; i = i.InvNextItem {
					if i.ScriptIDVal == int(uint32(v37)) {
						nox_xxx_playerTryEquip_4F2F70(a1, i)
					}
				}
				v27++
				if v27 >= int32(uint8(int8(v41))) {
					break
				}
			}
		}
		if noxflags.HasGame(2048) {
			sub_467750(0, 0)
			sub_467740(0)
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v37)), 4)
		if v37 != 0 {
			v29 := a1.InvFirstItem
			if v29 != nil {
				for {
					if v29.ScriptIDVal == int(uint32(v37)) {
						nox_xxx_netSendSecondaryWeapon_4D9670(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v40, 276)), 2064))), v29, 0)
						break
					}
					v29 = v29.InvNextItem
					if v29 == nil {
						break
					}
				}
			}
		}
		if int32(int16(v42)) >= 2 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v37)), 4)
			if v37 != 0 {
				v30 := a1.InvFirstItem
				if v30 != nil {
					for {
						if v30.ScriptIDVal == int(uint32(v37)) {
							nox_xxx_netMsgLastQuiver_4D96B0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v40, 276)), 2064))), v30)
							break
						}
						v30 = v30.InvNextItem
						if v30 == nil {
							break
						}
					}
				}
			}
		}
		if noxflags.HasGame(4096) {
			for j := nox_xxx_inventoryGetFirst_4E7980(a1); j != nil; j = nox_xxx_inventoryGetNext_4E7990(j) {
				j.ScriptIDVal = int(nox_server_NextObjectScriptID())
				j.Extent = j.NetCode
			}
		}
		goto LABEL_109
	}
	v4 = unsafe.Pointer(a1.InvFirstItem)
	v5 = 0
	for k = 0; v4 != nil; v4 = *(*unsafe.Pointer)(unsafe.Add(v4, 496)) {
		if !noxflags.HasGame(4096) || sub_41B3E0(v4) != 0 {
			k++
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&k)), 4)
	if noxflags.HasGame(2048) {
		v5 = sub_41B3B0()
	}
	if k != v5 || !noxflags.HasGame(2048) {
		v15 := a1.InvFirstItem
		if v15 != nil {
			for {
				if !noxflags.HasGame(4096) || sub_41B3E0(unsafe.Pointer(v15)) != 0 {
					*(*uint8)(unsafe.Pointer(&v39)) = uint8(int8(libc.StrLen(nox_xxx_getUnitName_4E39D0(v15))))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v39)), 1)
					v34 = uint32(uint8(int8(v39)))
					v16 = nox_xxx_getUnitName_4E39D0(v15)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v16, v34)
					if ccall.AsFunc[func(unsafe.Pointer, uint32) int32](*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v15), 704)))(unsafe.Pointer(v15), 0) == 0 {
						return 0
					}
				}
				v15 = v15.InvNextItem
				if v15 == nil {
					v1 = a1
					break
				}
			}
		}
	} else {
		v6 = 0
		v41 = 0
		for {
			v7 = 0
			v43 = 0
			for {
				v8 = sub_467810(v7, v6)
				v45 = v8
				if v8 != 0 {
					v9 = sub_467870(v7, v6)
					v10 = 0
					if v8 > 0 {
						v11 = (*int32)(unsafe.Pointer(v9))
						for {
							v12 := nox_xxx_equipedItemByCode_4F7920(a1, *v11)
							v13 := v12
							if v12 == nil {
								return 0
							}
							*(*uint8)(unsafe.Pointer(&v39)) = uint8(int8(libc.StrLen(nox_xxx_getUnitName_4E39D0(v12))))
							nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v39)), 1)
							v33 = uint32(uint8(int8(v39)))
							v14 = nox_xxx_getUnitName_4E39D0(v13)
							nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v14, v33)
							v13p := AsObjectP(unsafe.Pointer(v13))
							if v13p.Xfer.Get()(v13p, nil) == 0 {
								return 0
							}
							v10++
							v11 = (*int32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
							if v10 >= v45 {
								v6 = v41
								v7 = v43
								break
							}
						}
					}
				}
				v7++
				v43 = v7
				if v7 >= 4 {
					break
				}
			}
			v6++
			v41 = v6
			if v6 >= 20 {
				break
			}
		}
		v1 = a1
	}
	l = 0
	for v17 := v1.InvFirstItem; v17 != nil; v17 = v17.InvNextItem {
		if v17.ObjFlags&0x100 != 0 {
			l++
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&l)), 1)
	for m = unsafe.Pointer(v1.InvFirstItem); m != nil; m = *(*unsafe.Pointer)(unsafe.Add(m, 496)) {
		if *(*uint32)(unsafe.Add(m, 16))&0x100 != 0 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(m, 44)), 4)
		}
	}
	v19 = sub_4678B0()
	v37 = v19
	if v19 == 0 {
		if m == nil {
			v37 = 0
		}
	} else {
		m = unsafe.Pointer(v1.InvFirstItem)
		if m != nil {
			for {
				if *(*uint32)(unsafe.Add(m, 36)) == uint32(v19) {
					v37 = int32(*(*uint32)(unsafe.Add(m, 44)))
					if m == nil {
						v37 = 0
					}
					break
				}
				m = *(*unsafe.Pointer)(unsafe.Add(m, 496))
				if m == nil {
					v37 = 0
					break
				}
			}
		} else {
			v37 = 0
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v37)), 4)
	v20 = sub_4678C0()
	v37 = v20
	if v20 != 0 {
		m = unsafe.Pointer(v1.InvFirstItem)
		if m == nil {
			v37 = 0
			goto LABEL_67
		}
		for *(*uint32)(unsafe.Add(m, 36)) != uint32(v20) {
			m = *(*unsafe.Pointer)(unsafe.Add(m, 496))
			if m == nil {
				v37 = 0
				goto LABEL_67
			}
		}
		v37 = int32(*(*uint32)(unsafe.Add(m, 44)))
	}
	if m == nil {
		v37 = 0
	}
LABEL_67:
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v37)), 4)
LABEL_109:
	v32 = (*uint8)(unsafe.Add(v40, 244))
	if int32(int16(v42)) < 3 {
		*(*uint8)(unsafe.Add(v40, 244)) = 0
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v40, 244)), 1)
	}
	if nox_crypt_IsReadOnly() == 1 && noxflags.HasGame(4096) {
		*v32 = 0
	}
LABEL_115:
	if noxflags.HasGame(4096) && sub_4F2C30(unsafe.Pointer(v1)) == 0 {
		return 0
	}
	nox_xxx_netMsgInventoryLoaded_4D96E0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v40, 276)), 2064))))
	return 1
}
func sub_41B3B0() int32 {
	var (
		v0 int32
		i  int32
		j  int32
	)
	v0 = 0
	for i = 0; i < 20; i++ {
		for j = 0; j < 4; j++ {
			v0 += sub_467810(j, i)
		}
	}
	return v0
}
func sub_41B3E0(a1 unsafe.Pointer) int32 {
	var (
		v1     int32
		result int32
	)
	v1 = int32(*memmap.PtrUint32(0x5D4594, 527724))
	if *memmap.PtrUint32(0x5D4594, 527724) == 0 {
		v1 = nox_xxx_getNameId_4E3AA0(internCStr("Glyph"))
		*memmap.PtrUint32(0x5D4594, 527724) = uint32(v1)
	}
	if (int32(*(*uint8)(unsafe.Add(a1, 8))) & 0x40) == 64 {
		result = 0
	} else {
		result = bool2int32(int32(*(*uint16)(unsafe.Add(a1, 4))) != v1)
	}
	return result
}
func nox_xxx_guiFieldbook_41B420(a1 *server.Object, a2 unsafe.Pointer) int32 {
	var v1 *byte
	var result int32
	var v3 *uint32
	var v4 *uint32
	var v5 int32
	var i int32
	var v7 *byte
	var v8 int32
	var v9 int32
	var v10 int32
	var v11 uint32
	var v12 int8
	var v13 int32
	var v14 int32
	var v15 int32
	var v16 [256]byte
	v1 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(a1.NetCode))))
	v12 = 1
	if v1 == nil {
		return 0
	}
	v15 = 1
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v15)), 2)
	if int32(int16(v15)) > 1 {
		return 0
	}
	if noxflags.HasGame(0x2000) && !noxflags.HasGame(4096) {
		v12 = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 1)
	if int32(v12) == 0 {
		return 1
	}
	if !noxflags.HasGame(2048) {
		result = bool2int32(noxflags.HasGame(4096))
		if result == 0 {
			return result
		}
	}
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13)), 1)
		if int32(uint8(int8(v13))) > 0x29 {
			return 0
		}
		v8 = 0
		if int32(uint8(int8(v13))) > 0 {
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 1)
				if int32(uint8(int8(v14))) >= 256 {
					break
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v16[0], uint32(uint8(int8(v14))))
				v16[uint8(int8(v14))] = 0
				if noxflags.HasGame(4096) {
					v9 = nox_xxx_guide_427010(&v16[0])
					if sub_4F2EF0(v9) == 0 {
						break
					}
				}
				v10 = nox_xxx_guide_427010(&v16[0])
				nox_xxx_awardBeastGuide_4FAE80_magic_plyrgide(unsafe.Pointer(a1), v10, 0)
				if func() int32 {
					p := &v8
					*p++
					return *p
				}() >= int32(uint8(int8(v13))) {
					return 1
				}
			}
			return 0
		}
		return 1
	}
	v3 = (*uint32)(unsafe.Add(unsafe.Pointer(v1), 4248))
	*(*uint8)(unsafe.Pointer(&v13)) = 0
	v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v1), 4248))
	v5 = 40
	for {
		if *v4 != 0 {
			*(*uint8)(unsafe.Pointer(&v13)) = uint8(int8(v13 + 1))
		}
		v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
		v5--
		if v5 == 0 {
			break
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13)), 1)
	for i = 1; i < 41; i++ {
		if *v3 != 0 {
			*(*uint8)(unsafe.Pointer(&v14)) = uint8(int8(libc.StrLen(nox_xxx_guideNameByN_427230(i))))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 1)
			v11 = uint32(uint8(int8(v14)))
			v7 = nox_xxx_guideNameByN_427230(i)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v7, v11)
		}
		v3 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
	}
	return 1
}
func nox_xxx_guiSpellbook_41B660(a1 *server.Object, a2 unsafe.Pointer) int32 {
	var v3 *uint8
	var v4 *uint32
	var v5 int32
	var v6 int32
	var v7 int8
	var v8 int32
	var v9 *byte
	var v10 *byte
	var v11 int32
	var v12 bool
	var v13 int32
	var v14 int32
	var v15 int32
	var v16 uint32
	var v17 uint32
	var v18 int32
	var v19 int8
	var v20 int32
	var v21 int32
	var v22 int32
	var v23 int32
	var v24 [256]byte
	v2 := unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(a1.NetCode)))
	v19 = 1
	if v2 == nil {
		return 0
	}
	v22 = 3
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 2)
	if int32(int16(v22)) > 3 {
		return 0
	}
	if noxflags.HasGame(0x2000) && !noxflags.HasGame(4096) {
		v19 = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19)), 1)
	if int32(v19) == 0 {
		return 1
	}
	if !noxflags.HasGame(2048) && !noxflags.HasGame(4096) {
		return 0
	}
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v20)), 1)
		if int32(uint8(int8(v20))) > 0x89 {
			return 0
		}
		v11 = 0
		if int32(uint8(int8(v20))) != 0 {
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 1)
				if int32(uint8(int8(v21))) >= 256 {
					break
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v24[0], uint32(uint8(int8(v21))))
				v12 = int32(int16(v22)) < 2
				v23 = 3
				v24[uint8(int8(v21))] = 0
				if !v12 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v23)), 4)
				}
				if noxflags.HasGame(4096) && v23 > 3 && int32(*(*uint8)(unsafe.Add(v2, 2251))) != 0 {
					break
				}
				if noxflags.HasGame(4096) {
					if int32(*(*uint8)(unsafe.Add(v2, 2251))) != 0 {
						v13 = nox_xxx_spellNameToN_4243F0(&v24[0])
						if nox_xxx_spell_4F2E70(v13) == 0 {
							break
						}
					}
				}
				if int32(int16(v22)) < 3 || int32(*(*uint8)(unsafe.Add(v2, 2251))) != 0 {
					v18 = v23
					v15 = nox_xxx_spellNameToN_4243F0(&v24[0])
					nox_xxx_spellGrantToPlayer_4FB550(a1, v15, 0, 0, v18)
				} else {
					v14 = nox_xxx_abilityNameToN_424D80(&v24[0])
					nox_xxx_abilityRewardServ_4FB9C0_ability(unsafe.Pointer(a1), v14, 0)
				}
				if func() int32 {
					p := &v11
					*p++
					return *p
				}() >= int32(uint8(int8(v20))) {
					return 1
				}
			}
			return 0
		}
		return 1
	}
	*(*uint8)(unsafe.Pointer(&v20)) = 0
	v3 = (*uint8)(unsafe.Add(v2, 3700))
	v4 = (*uint32)(unsafe.Add(v2, 3700))
	if int32(*(*uint8)(unsafe.Add(v2, 2251))) != 0 {
		v6 = 136
		for {
			if *v4 != 0 {
				*(*uint8)(unsafe.Pointer(&v20)) = uint8(int8(v20 + 1))
			}
			v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
			v6--
			if v6 == 0 {
				break
			}
		}
	} else {
		v5 = 5
		for {
			if *v4 != 0 {
				*(*uint8)(unsafe.Pointer(&v20)) = uint8(int8(v20 + 1))
			}
			v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
			v5--
			if v5 == 0 {
				break
			}
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v20)), 1)
	v7 = int8(*(*uint8)(unsafe.Add(v2, 2251)))
	v8 = 1
	if int32(v7) != 0 {
		for {
			if *(*uint32)(unsafe.Pointer(v3)) != 0 {
				*(*uint8)(unsafe.Pointer(&v21)) = uint8(int8(libc.StrLen(nox_xxx_spellNameByN_424870(v8))))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 1)
				v17 = uint32(uint8(int8(v21)))
				v10 = nox_xxx_spellNameByN_424870(v8)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v10, v17)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v3, 4)
			}
			v8++
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
			if v8 >= 137 {
				break
			}
		}
		return 1
	} else {
		for {
			if *(*uint32)(unsafe.Pointer(v3)) != 0 {
				*(*uint8)(unsafe.Pointer(&v21)) = uint8(int8(libc.StrLen(nox_xxx_abilityGetName_425250(v8))))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 1)
				v16 = uint32(uint8(int8(v21)))
				v9 = nox_xxx_abilityGetName_425250(v8)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v9, v16)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v3, 4)
			}
			v8++
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
			if v8 >= 6 {
				break
			}
		}
		return 1
	}
}
func nox_xxx_guiEnchantment_41B9C0(a1 *server.Object, a2 unsafe.Pointer) int32 {
	var result int32
	var i int32
	var v3 *byte
	var v5 int32
	var v6 int32
	var v7 int32
	var v8 int32
	var v9 int16
	var j int32
	var k int32
	var v13 int32
	var v14 int8
	var v15 int8
	var v16 int8
	var v17 int32
	var v18 int32
	var v20 int32
	var v21 int32
	var v22 int32
	var v23 int32
	var v24 [3]int32
	var v27 [256]byte
	v19 := a1.UpdateData
	v16 = 1
	v18 = 5
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 2)
	if int32(int16(v18)) > 5 {
		return 0
	}
	if nox_crypt_IsReadOnly() == 1 && noxflags.HasGame(2048) {
		nox_xxx_spellCastByPlayer_4FEEF0()
		sub_4FE8A0(0)
	}
	if noxflags.HasGame(0x2000) {
		v16 = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v16)), 1)
	if int32(v16) != 0 {
		result = bool2int32(noxflags.HasGame(2048))
		if result == 0 {
			return result
		}
		if nox_crypt_IsReadOnly() != 0 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 1)
			v5 = 0
			if int32(uint8(int8(v22))) != 0 {
				for {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v20)), 1)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v27[0], uint32(uint8(int8(v20))))
					v27[uint8(int8(v20))] = 0
					v6 = nox_xxx_enchantByName_424880(&v27[0])
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v17)), 2)
					*(*uint8)(unsafe.Pointer(&v21)) = 2
					if int32(int16(v18)) >= 2 {
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 1)
					}
					v7 = int32(a1.PosVec.Y)
					v24[1] = int32(a1.PosVec.X)
					v13 = int32(uint8(int8(v21)))
					*(**server.Object)(unsafe.Pointer(&v24[0])) = a1
					v24[2] = v7
					v8 = nox_xxx_getEnchantSpell_424920(server.EnchantID(v6))
					nox_xxx_spellAccept_4FD400(v8, a1, a1, a1, (*server.SpellAcceptArg)(unsafe.Pointer(&v24[0])), v13)
					v9 = int16(v17)
					if int32(uint16(int16(v17))) == 0 {
						v9 = int16(uint16(gameFPS()))
						v17 = int32(gameFPS())
					}
					*(*uint16)(unsafe.Add(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(uint16(0))*uintptr(v6)), unsafe.Sizeof(uint16(0))*172)) = uint16(v9)
					if v6 == 26 && int32(int16(v18)) >= 3 {
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v23)), 4)
						v10 := sub_4FF2D0(51, a1)
						if v10 != nil {
							v10.Field72 = v23
						}
					}
					v5++
					if v5 >= int32(uint8(int8(v22))) {
						break
					}
				}
			}
		} else {
			*(*uint8)(unsafe.Pointer(&v22)) = uint8(sub_424CB0(unsafe.Pointer(a1)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 1)
			for i = sub_424D00(); i != -1; i = sub_424D20(i) {
				if nox_xxx_testUnitBuffs_4FF350(a1, server.EnchantID(i)) != 0 {
					v3 = nox_xxx_getEnchantName_4248F0(i)
					*(*uint8)(unsafe.Pointer(&v20)) = uint8(int8(libc.StrLen(v3)))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v20)), 1)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v3, uint32(uint8(int8(v20))))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(a1), i*2), 344)), 2)
					*(*uint8)(unsafe.Pointer(&v21)) = uint8(nox_xxx_buffGetPower_4FF570(a1, server.EnchantID(i)))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 1)
					if i == 26 {
						v4 := sub_4FF2D0(51, a1)
						if v4 != nil {
							v17 = v4.Field72
						} else {
							v17 = 100
						}
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v17)), 4)
					}
				}
			}
		}
		if int32(int16(v18)) >= 5 && int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 276)), 2251))) == 0 {
			v14 = int8(nox_common_playerIsAbilityActive_4FC250(a1, 1))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 1)
			if nox_crypt_IsReadOnly() == 1 && int32(v14) == 1 {
				sub_4FC670(1)
			}
			v15 = int8(nox_common_playerIsAbilityActive_4FC250(a1, 4))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v15)), 1)
			v23 = sub_4FC030(a1, 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v23)), 4)
			if nox_crypt_IsReadOnly() == 1 && int32(v15) == 1 {
				nox_xxx_playerExecuteAbil_4FBB70(a1, 4)
				sub_4FC070(a1, 4, v23)
			}
			for j = 2 - bool2int32(int32(v14) != 1); j < 6; j++ {
				v17 = sub_4FBE60(unsafe.Pointer(a1), j)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v17)), 4)
				if nox_crypt_IsReadOnly() == 1 {
					sub_4FBEA0(unsafe.Pointer(a1), j, v17)
					if v17 != 0 {
						nox_xxx_netAbilRepotState_4D8100(a1, int8(j), 0)
					}
				}
			}
		}
	}
	if !(int32(uint16(int16(v18))) == 4 && int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 276)), 2251))) == 0) {
		return 1
	}
	v14 = int8(nox_common_playerIsAbilityActive_4FC250(a1, 1))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 1)
	if nox_crypt_IsReadOnly() == 1 && int32(v14) == 1 {
		sub_4FC670(1)
	}
	v15 = int8(nox_common_playerIsAbilityActive_4FC250(a1, 4))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v15)), 1)
	v19b := sub_4FC030(a1, 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19b)), 4)
	if nox_crypt_IsReadOnly() == 1 && int32(v15) == 1 {
		nox_xxx_playerExecuteAbil_4FBB70(a1, 4)
		sub_4FC070(a1, 4, v19b)
	}
	for k = 2 - bool2int32(int32(v14) != 1); k < 6; k++ {
		v17 = sub_4FBE60(unsafe.Pointer(a1), k)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v17)), 4)
		if nox_crypt_IsReadOnly() == 1 {
			sub_4FBEA0(unsafe.Pointer(a1), k, v17)
			if v17 != 0 {
				nox_xxx_netAbilRepotState_4D8100(a1, int8(k), 0)
			}
		}
	}
	return 1
}
func sub_41BEC0(a1p *server.Object, a2 unsafe.Pointer) int32 {
	var result int32
	var v5 int32
	var v8 int32
	var v9 int32
	var v10 int32
	var v11 int32
	var v12 [64]byte
	v1 := a1p
	v2 := *(*unsafe.Pointer)(unsafe.Add(a1p.UpdateData, 276))
	var a1 int32
	*(*uint8)(unsafe.Pointer(&a1)) = 1
	v10 = 1
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 2)
	if int32(int16(v10)) > 1 {
		return 0
	}
	if noxflags.HasGame(0x2000) {
		*(*uint8)(unsafe.Pointer(&a1)) = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
	if int32(uint8(int8(a1))) == 0 {
		return 1
	}
	result = bool2int32(noxflags.HasGame(2048))
	if result == 0 {
		return result
	}
	v8 = 0
	for i := *(*unsafe.Pointer)(unsafe.Add(v2, 3644)); i != nil; i = *(*unsafe.Pointer)(unsafe.Add(i, 64)) {
		v8++
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 2)
	if nox_crypt_IsReadOnly() != 1 {
		if int32(uint16(int16(v8))) <= 0 {
			return 1
		}
		v6 := *(*unsafe.Pointer)(unsafe.Add(v2, 3644))
		var j unsafe.Pointer
		for j = *(*unsafe.Pointer)(unsafe.Add(v6, 64)); j != nil; j = *(*unsafe.Pointer)(unsafe.Add(j, 64)) {
			v6 = j
		}
		for ; v6 != nil; v6 = *(*unsafe.Pointer)(unsafe.Add(v6, 68)) {
			*(*uint8)(unsafe.Pointer(&v9)) = uint8(int8(libc.StrLen((*byte)(v6))))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v9)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(v6), uint32(uint8(int8(v9))))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v6, 72)), 2)
		}
		return 1
	}
	sub_4277B0(v1, math.MaxUint16)
	v5 = 0
	if int32(uint16(int16(v8))) <= 0 {
		return 1
	}
	for {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v9)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v12[0], uint32(uint8(int8(v9))))
		v12[uint8(int8(v9))] = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 2)
		nox_xxx_comJournalEntryAdd_427500(v1, &v12[0], int16(v11))
		v5++
		if v5 >= int32(uint16(int16(v8))) {
			break
		}
	}
	return 1
}
func sub_41C080(a1p *server.Object, a2 unsafe.Pointer) int32 {
	var result int32
	var v4 uint32
	var v5 int32
	var v6 [4]byte
	v1 := a1p
	v2 := *(*unsafe.Pointer)(unsafe.Add(a1p.UpdateData, 276))
	if noxflags.HasGame(0x2000) {
		return 1
	}
	a1 := int32(5)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
	if int32(int16(a1)) > 5 {
		return 0
	}
	if int32(int16(a1)) >= 5 {
		if nox_crypt_IsReadOnly() != 0 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v6[0], 4)
		} else {
			var oid int32 = int32(nox_server_LastObjectScriptID())
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&oid)), 4)
			nox_server_SetLastObjectScriptID(uint32(oid))
		}
	}
	if nox_crypt_IsReadOnly() == 0 {
		libc.StrCpy((*byte)(unsafe.Add(v2, 4760)), nox_xxx_mapGetMapName_409B40())
	}
	v4 = uint32(libc.StrLen((*byte)(unsafe.Add(v2, 4760))))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 2)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v2, 4760)), uint32(int32(uint16(v4))*2))
	*(*uint8)(unsafe.Add(v2, int32(uint16(v4))+4760)) = 0
	if !(int32(int16(a1)) < 2 || (func() int32 {
		if nox_crypt_IsReadOnly() != 0 {
			result = sub_500B70()
		} else {
			result = sub_500A60()
		}
		return result
	}()) != 0) {
		return result
	}
	if int32(int16(a1)) < 3 || (func() int32 {
		result = sub_5000B0(v1)
		return result
	}()) != 0 {
		if int32(int16(a1)) >= 4 {
			*(*uint8)(unsafe.Pointer(&v5)) = sub_450750()
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 1)
			sub_450760(int8(v5))
			return 1
		}
		sub_450760(0)
		return 1
	}
	return result
}
func sub_41C280(a1 unsafe.Pointer) int32 {
	var (
		result int32
		v2     *byte
		v3     *byte
		v4     int32
	)
	v4 = 3
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 2)
	if int32(int16(v4)) > 3 {
		return 0
	}
	result = sub_460940(a1)
	if result == 0 {
		return result
	}
	if int32(int16(v4)) >= 2 {
		*(*uint8)(unsafe.Pointer(&a1)) = uint8(int8(nox_xxx_buttonsGetSelectedRow_45E180()))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
		if nox_crypt_IsReadOnly() == 1 {
			nox_xxx_clientUpdateButtonRow_45E110(int32(uint8(uintptr(a1))))
		}
		*(*uint8)(unsafe.Pointer(&a1)) = uint8(int8(sub_4604E0()))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
		if nox_crypt_IsReadOnly() == 1 {
			nox_client_trapSetSelect_4604B0(int32(uint8(uintptr(a1))))
		}
	}
	if int32(int16(v4)) >= 3 {
		v2 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(nox_player_netCode_85319C))))
		v3 = v2
		if v2 != nil {
			*(*uint8)(unsafe.Pointer(&a1)) = *(*byte)(unsafe.Add(unsafe.Pointer(v2), 3648))
		} else {
			*(*uint8)(unsafe.Pointer(&a1)) = 4
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
		if nox_crypt_IsReadOnly() == 1 {
			if noxflags.HasGame(2048) {
				nox_xxx_orderUnitLocal_500C70(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v3), 2064))), int32(uint8(uintptr(a1))))
			}
		}
	}
	result = 1
	return result
}
func nox_xxx_parseFileInfoData_41C3B0(a1 unsafe.Pointer) int32 {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 uint32
		v5 int32
	)
	v5 = 12
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 2)
	if int32(int16(v5)) > 12 {
		return 0
	}
	if noxflags.HasGame(0x2000) {
		*memmap.PtrUint32(0x85B3FC, 10980) &= 0xFFFFFFFE
		if noxflags.HasGame(4096) || nox_xxx_isQuest_4D6F50() != 0 || sub_4D6F70() != 0 {
			v2 = int32(*memmap.PtrUint32(0x85B3FC, 10980))
			*(*uint8)(unsafe.Pointer(&v2)) = uint8(int8(int32(*memmap.PtrUint8(0x85B3FC, 10980)) | 4))
			*memmap.PtrUint32(0x85B3FC, 10980) = uint32(v2)
		} else {
			v1 = int32(*memmap.PtrUint32(0x85B3FC, 10980))
			*(*uint8)(unsafe.Pointer(&v1)) = uint8(int8(int32(*memmap.PtrUint8(0x85B3FC, 10980)) | 2))
			*memmap.PtrUint32(0x85B3FC, 10980) = uint32(v1)
		}
	} else {
		*memmap.PtrUint32(0x85B3FC, 10980) = *memmap.PtrUint32(0x85B3FC, 10980)&0xFFFFFFF9 | 1
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 10980)), 4)
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 10984)), uint32(int16(uint16(v4))))
		*memmap.PtrUint8(0x85B3FC, uintptr(int32(int16(uint16(v4)))+10984)) = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12008)), uint32(uint8(int8(v3))))
		*memmap.PtrUint8(0x85B3FC, uintptr(int32(uint8(int8(v3)))+12008)) = 0
	} else {
		v4 = uint32(libc.StrLen((*byte)(memmap.PtrOff(0x85B3FC, 10984))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 10984)), uint32(int16(uint16(v4))))
		*(*uint8)(unsafe.Pointer(&v3)) = uint8(int8(libc.StrLen((*byte)(memmap.PtrOff(0x85B3FC, 12008)))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12008)), uint32(uint8(int8(v3))))
	}
	noxGetLocalTime((*noxSYSTEMTIME)(memmap.PtrOff(0x85B3FC, 12168)))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12168)), 2)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12170)), 2)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12172)), 2)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12174)), 2)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12176)), 2)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12178)), 2)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12180)), 2)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12182)), 2)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12187)), 3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12184)), 3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12190)), 3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12193)), 3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12196)), 3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12199)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12200)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12201)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12202)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12203)), 1)
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12204)), uint32(int32(uint8(int8(v3)))*2))
		*memmap.PtrUint16(0x85B3FC, uintptr(int32(uint8(int8(v3)))*2+12204)) = 0
	} else {
		*(*uint8)(unsafe.Pointer(&v3)) = uint8(nox_wcslen((*wchar2_t)(memmap.PtrOff(0x85B3FC, 12204))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12204)), uint32(int32(uint8(int8(v3)))*2))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12254)), 1)
	*memmap.PtrUint8(0x85B3FC, 12255) = 0
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12255)), 1)
	if nox_crypt_IsReadOnly() == 0 {
		*memmap.PtrUint8(0x85B3FC, 12256) = uint8(int8(sub_467590()))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12256)), 1)
	if int32(int16(v5)) >= 11 {
		libc.StrCpy((*byte)(memmap.PtrOff(0x85B3FC, 12136)), nox_xxx_mapGetMapName_409B40())
		*(*uint8)(unsafe.Pointer(&v3)) = uint8(int8(libc.StrLen((*byte)(memmap.PtrOff(0x85B3FC, 12136)))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12136)), uint32(uint8(int8(v3))))
		*memmap.PtrUint8(0x85B3FC, uintptr(int32(uint8(int8(v3)))+12136)) = 0
	}
	if int32(int16(v5)) < 12 {
		*memmap.PtrUint8(0x85B3FC, 12257) = 0
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x85B3FC, 12257)), 1)
	}
	return 1
}
func sub_41C780(a1 unsafe.Pointer) int32 {
	var (
		i  int32
		v2 *byte
		v3 bool
		v4 int32
		v5 int32
		v6 int4
	)
	v5 = 11
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 2)
	if int32(int16(v5)) > 11 {
		return 0
	}
	if !(int32(int16(v5)) < 11 || (func() bool {
		v3 = !noxflags.HasGame(0x2000)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3)), 1)
		return v3
	}())) {
		return 1
	}
	if nox_crypt_IsReadOnly() != 0 {
		v6.field_0 = 0
		v6.field_4 = 0
		v6.field_8 = 0
		v6.field_C = 0
	} else {
		sub_43DD10(&v6.field_0)
		v4 = sub_43DB20()
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6.field_C)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6.field_8)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6.field_4)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 4)
	for i = 0; i < v4; i++ {
		v2 = sub_43DB40(i)
		if nox_crypt_IsReadOnly() == 1 {
			*(*uint32)(unsafe.Pointer(v2)) = 0
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = 0
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = 0
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) = 0
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 12)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 8)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v2, 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 4)), 4)
	}
	if nox_crypt_IsReadOnly() == 1 && !noxflags.HasGame(0x2000) {
		sub_43D9E0(&v6)
		sub_43DB30(v4)
	}
	return 1
}
func sub_41CAC0(a1 *byte, a2 unsafe.Pointer) {
	var f *FILE = nox_binfile_open_408CC0(a1, 0)
	if f == nil {
		return
	}
	if nox_binfile_cryptSet_408D40(f, 27) == 0 {
		return
	}
	var v3 *byte = (*byte)(a2)
	var v4 int32 = 0
	for {
		var v13 int32 = 0
		nox_binfile_fread_408E40((*byte)(unsafe.Pointer(&v13)), 4, 1, f)
		if v13 == 0 {
			*(*uint32)(unsafe.Pointer(v3)) = 0
			nox_binfile_close_408D90(f)
			return
		}
		var v5 int32 = nox_binfile_ftell_426A50(f)
		var v12 int32 = 0
		nox_binfile_fread_align_408FE0((*byte)(unsafe.Pointer(&v12)), 4, 1, f)
		var v6 int32 = nox_binfile_ftell_426A50(f)
		if table_55816_cnt == 0 {
			nox_binfile_fseek_409050(f, v12, stdio.SEEK_CUR)
			continue
		}
		var csec *table_55816_t = nil
		for i := int32(0); i < table_55816_cnt; i++ {
			var sec *table_55816_t = &table_55816[i]
			if uint32(v13) == sec.ind {
				csec = sec
				break
			}
		}
		if csec == nil {
			nox_binfile_fseek_409050(f, v12, stdio.SEEK_CUR)
			continue
		}
		var v9 int32 = v6 - v5
		*(*uint32)(unsafe.Pointer(v3)) = uint32(v13)
		var v10 *uint32 = (*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v3), v9), -4))
		v4 += v9 + 4
		*v10 = uint32(v12)
		v3 = (*byte)(unsafe.Add(unsafe.Pointer(v10), 4*2))
		if v12 != 0 {
			v4 += v12
			for v11 := v12; v11 > 0; v11-- {
				nox_binfile_fread_408E40((*byte)(unsafe.Pointer(&a1)), 1, 1, f)
				*v3 = uint8(uintptr(unsafe.Pointer(a1)))
				v3 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1))
			}
		}
	}
}
func nox_xxx_netSavePlayer_41CE00() int32 {
	var v2 [3]byte
	v2[0] = 193
	*(*uint16)(unsafe.Pointer(&v2[1])) = uint16(nox_player_netCode_85319C)
	nox_xxx_netClientSend2_4E53C0(31, unsafe.Pointer(&v2[0]), 3, 1)
	return 1
}
func sub_41CEE0(a1p unsafe.Pointer, a2 int32) int32 {
	var (
		v3 int32
		v6 int32
		v8 int32
	)
	alloc.Memcpy(memmap.PtrOff(0x85B3FC, 10980), a1p, unsafe.Sizeof(Nox_savegame_xxx{}))
	if nox_xxx_cryptOpen_426910((*byte)(memmap.PtrOff(0x85B3FC, 10984)), 0, 27) == 0 {
		return 0
	}
	v3 = a2
	var a1a int32 // FIXME: was a1 = a1p
	if a2 == 0 {
		a1a = 1
	}
	if *memmap.PtrUint32(0x587000, 55936) != 0 {
		v4 := (*uint8)(memmap.PtrOff(0x587000, 55940))
		for {
			if v3 != 0 || *(*uint32)(unsafe.Pointer(v4)) == uint32(a1a) {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v4, 4)
				nox_xxx_crypt_426C90()
				v6 = ccall.AsFunc[func(unsafe.Pointer) int32](*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uintptr(0))*1)))(nil)
				nox_xxx_crypt_426D40()
				if v6 == 0 {
					nox_xxx_cryptClose_4269F0()
					return 0
				}
			}
			v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2)))
			v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 12))
			if v8 == 0 {
				break
			}
		}
	}
	a1 := int32(0)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
	nox_xxx_cryptClose_4269F0()
	return 1
}
func sub_41D1A0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 527720) = uint32(a1)
	return result
}
func sub_41D1B0() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 527720))
}
func sub_41D650() int32 {
	var (
		v0     *byte
		result int32
	)
	v0 = sub_41FA40()
	result = sub_41F800(v0)
	if result != 0 {
		result = 0
	}
	*memmap.PtrUint32(0x5D4594, 371700) = 1
	return result
}
func sub_41D670(a1 *byte) int32 {
	var v1 int32
	var v3 int16
	var v4 [72]byte
	if sub_420230(&v4[0], (*uint16)(unsafe.Pointer(&v3))) == 0 {
		return 0
	}
	v1 = sub_4200E0()
	panic("abort")
	_ = v1
	return 0
}
func sub_41D6C0() int32 {
	var v0 int32
	var v3 int32
	var result int32
	var v9 int16
	var v11 int32
	var v12 int32
	var v13 int32
	var v14 [72]byte
	var v15 [1024]byte
	v0 = 1
	v11 = 1
	v12 = 1
	if sub_420230(&v14[0], (*uint16)(unsafe.Pointer(&v9))) == 0 {
		return 0
	}
	if uint32(nox_common_playerInfoCount_416F40()) > 25 {
		v1 := nox_common_playerInfoGetFirst_416EA0()
		v13 = 25
		var v10 *server.Player
		for {
			if *(*byte)(unsafe.Add(unsafe.Pointer(v1), 2096)) != 0 {
				if v0 != 0 {
					libc.StrCat(&v15[0], (*byte)(unsafe.Add(unsafe.Pointer(v1), 2096)))
					v0 = 0
				} else {
					*(*uint16)(unsafe.Pointer(&v15[libc.StrLen(&v15[0])])) = *memmap.PtrUint16(0x587000, 58112)
					libc.StrCat(&v15[0], (*byte)(unsafe.Add(unsafe.Pointer(v1), 2096)))
				}
			}
			v10 = nox_common_playerInfoGetNext_416EE0(v1)
			v13--
			if v13 == 0 {
				break
			}
			v1 = v10
		}
		if v0 == 0 {
			v2 := sub_4200E0()
			panic("abort")
			_ = v2
		}
		v3 = 1
		if v10 == nil {
			return bool2int32(v11 != 0 && v12 == 1)
		}
		v15[0] = 0
		v4 := nox_common_playerInfoGetNext_416EE0(v10)
		if v4 == nil {
			return bool2int32(v11 != 0 && v12 == 1)
		}
		for {
			if *(*byte)(unsafe.Add(unsafe.Pointer(v4), 2096)) != 0 {
				if v3 != 0 {
					libc.StrCat(&v15[0], (*byte)(unsafe.Add(unsafe.Pointer(v4), 2096)))
					v3 = 0
				} else {
					*(*uint16)(unsafe.Pointer(&v15[libc.StrLen(&v15[0])])) = *memmap.PtrUint16(0x587000, 58116)
					libc.StrCat(&v15[0], (*byte)(unsafe.Add(unsafe.Pointer(v4), 2096)))
				}
			}
			v4 = nox_common_playerInfoGetNext_416EE0(v4)
			if v4 == nil {
				break
			}
		}
		if v3 == 0 {
			v5 := sub_4200E0()
			panic("abort")
			_ = v5
		} else {
			result = v12
		}
		return bool2int32(v11 != 0 && result == 1)
	}
	v7 := nox_common_playerInfoGetFirst_416EA0()
	if v7 == nil {
		return v11
	}
	for {
		if *(*byte)(unsafe.Add(unsafe.Pointer(v7), 2096)) != 0 {
			if v0 != 0 {
				libc.StrCat(&v15[0], (*byte)(unsafe.Add(unsafe.Pointer(v7), 2096)))
				v0 = 0
			} else {
				*(*uint16)(unsafe.Pointer(&v15[libc.StrLen(&v15[0])])) = *memmap.PtrUint16(0x587000, 58120)
				libc.StrCat(&v15[0], (*byte)(unsafe.Add(unsafe.Pointer(v7), 2096)))
			}
		}
		v7 = nox_common_playerInfoGetNext_416EE0(v7)
		if v7 == nil {
			break
		}
	}
	if v0 != 0 {
		return v11
	}
	v8 := sub_4200E0()
	panic("abort")
	_ = v8
	return v11
}
func sub_41DA10(a1 int32) int32 {
	var (
		v1     *uint16
		result int32 = 0
	)
	v1 = *(**uint16)(memmap.PtrOff(0x587000, uintptr(a1*16+58132)))
	if v1 == nil {
		return result
	}
	result = 0
	libc.MemSet(unsafe.Pointer(v1), 0, 0x2C)
	*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*22)) = 0
	*memmap.PtrUint32(0x587000, uintptr(a1*16+58136)) = 0
	return result
}
func sub_41DA70(a1 int32, a2 int16) {
	var (
		v3 int32
		v4 int32
	)
	v3 = int32(*memmap.PtrUint32(0x587000, uintptr(a1*16+58132)))
	if v3 != 0 && (func() bool {
		v4 = int32(*memmap.PtrUint32(0x587000, uintptr(a1*16+58136)))
		return v4 < 23
	}()) {
		*(*uint16)(unsafe.Pointer(uintptr(v3 + v4*2))) = uint16(a2)
		*memmap.PtrUint32(0x587000, uintptr(a1*16+58136))++
	} else {
		if sub_41E300(11) != 0 {
			dword_5d4594_2660652 = 0
		}
	}
}
func sub_41E2F0() int32 {
	return int32(dword_5d4594_527988)
}
func sub_41E370() int32 {
	var result int32
	result = 0
	dword_5d4594_528252 = 0
	dword_5d4594_528256 = 0
	dword_5d4594_528260 = 0
	dword_5d4594_528264 = 0
	return result
}
func nox_xxx_reconAttempt_41E390() int32 {
	var result int32
	if gameFrame()-dword_5d4594_528264 <= (gameFPS() * 3600) {
		result = int32(dword_5d4594_528252)
		if dword_5d4594_528252 != 0 {
			result = int32(dword_5d4594_528256)
			if dword_5d4594_528256 == 0 {
				nox_xxx_networkLog_printf_413D30(internCStr("RECON: Attempting to re-login"))
				sub_40E090()
				result = nox_xxx_officialStringCmp_41FDE0()
				if result == 1 {
					dword_5d4594_528256 = 1
				} else {
					result = sub_41E470()
				}
			}
		}
	} else {
		sub_41E370()
		result = sub_41E4B0(1)
	}
	return result
}
func nox_xxx_reconStart_41E400() {
	if dword_5d4594_528252 != 1 && dword_5d4594_528256 != 1 {
		if dword_5d4594_528260 == 0 {
			if dword_5d4594_528264 == 0 {
				nox_xxx_networkLog_printf_413D30(internCStr("RECON: Starting reconnection process frame (%d)"), gameFrame())
				dword_5d4594_528252 = 1
				dword_5d4594_528256 = 0
				dword_5d4594_528264 = gameFrame()
				dword_5d4594_528260 = gameFrame() + gameFPS()*120
			}
		}
	}
}
func sub_41E470() int32 {
	var result int32
	nox_xxx_networkLog_printf_413D30(internCStr("RECON: TryReconnectAgain called on frame (%d)"), gameFrame())
	dword_5d4594_528256 = 0
	result = int32(gameFrame() + gameFPS()*120)
	dword_5d4594_528260 = gameFrame() + gameFPS()*120
	return result
}
func sub_41E4B0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 528268) = uint32(a1)
	return result
}
func sub_41EC30() {
	v0 := dword_5d4594_529316
	dword_5d4594_529332 = 0
	dword_5d4594_529336 = 0
	if dword_5d4594_529316 != nil {
		for {
			v1 := *(*unsafe.Pointer)(unsafe.Add(v0, 4*7))
			if v1 != nil {
				for {
					v2 := *(*unsafe.Pointer)(unsafe.Add(v1, 40))
					if *(*uint32)(v1) != 0 {
						alloc.FreePtr(*(*unsafe.Pointer)(v1))
					}
					alloc.FreePtr(v1)
					v1 = v2
					if v2 == nil {
						break
					}
				}
			}
			*(*uint32)(unsafe.Add(v0, 4*7)) = 0
			*(*uint32)(unsafe.Add(v0, 4*8)) = 0
			*(*uint32)(unsafe.Add(v0, 4*6)) = 0
			v0 = *(*unsafe.Pointer)(unsafe.Add(v0, 4*9))
			if v0 == nil {
				break
			}
		}
	}
	if sub_41E2F0() == 7 {
		v4 := sub_41E2F0()
		sub_41DA70(v4, 10)
	}
	dword_5d4594_529340 = 0
}
func sub_41F4B0() {
	v0 := dword_5d4594_531648
	if dword_5d4594_531648 != nil {
		for {
			v1 := *(*unsafe.Pointer)(unsafe.Add(v0, 20))
			if *(*uint32)(v0) != 0 {
				alloc.FreePtr(*(*unsafe.Pointer)(v0))
			}
			alloc.FreePtr(v0)
			v0 = v1
			if v1 == nil {
				break
			}
		}
	}
	dword_5d4594_531648 = nil
	dword_5d4594_531652 = 0
	dword_5d4594_531656 = 0
	if sub_41E2F0() == 7 {
		v3 := sub_41E2F0()
		sub_41DA70(v3, 11)
	}
}
func sub_41F790(a1 *byte) unsafe.Pointer {
	v1 := dword_5d4594_531648
	if a1 == nil || dword_5d4594_531648 == nil {
		return nil
	}
	for libc.StrCmp((*byte)(unsafe.Add(*(*unsafe.Pointer)(v1), 36)), a1) != 0 {
		v1 = *(*unsafe.Pointer)(unsafe.Add(v1, 4*5))
		if v1 == nil {
			return nil
		}
	}
	return v1
}
func sub_41F800(a1 *byte) int32 {
	var (
		v1     *int32
		result int32
	)
	v1 = (*int32)(sub_41F790(a1))
	if v1 != nil {
		result = *v1
	} else {
		result = 0
	}
	return result
}
func sub_41FA40() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 534756))
}
func sub_41FA50(a1 *byte) {
	if a1 != nil {
		libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, 534756)), a1)
	}
}
func sub_41FBE0(a1 *uint32, a2 *uint32) int32 {
	var result int32
	if dword_587000_60044 == -1 {
		return 0
	}
	*a1 = uint32(uintptr(memmap.PtrOff(0x5D4594, uintptr(dword_587000_60044)*24+531660)))
	result = 1
	*a2 = uint32(uintptr(memmap.PtrOff(0x5D4594, uintptr(dword_587000_60044)*24+531670)))
	return result
}
func nox_xxx_officialStringCmp_41FDE0() int32 {
	var (
		v1 uint32
		v3 *byte
		v4 *byte
	)
	libc.MemSet(memmap.PtrOff(0x85B3FC, 10308), 0, 0x6C)
	if sub_41FBE0((*uint32)(unsafe.Pointer(&v3)), (*uint32)(unsafe.Pointer(&v4))) != 1 {
		return 0
	}
	v0 := sub_4207E0()
	if v0 == nil {
		return 1
	}
	libc.StrCpy((*byte)(unsafe.Add(v0, 228)), v3)
	libc.StrCpy((*byte)(unsafe.Add(v0, 238)), v4)
	sub_41FA50(v3)
	v1 = uint32(libc.StrCSpn((*byte)(unsafe.Add(v0, 24)), internCStr(":")))
	if libc.StrNCmp(internCStr("Official"), (*byte)(unsafe.Add(v0, v1+25)), 8) == 0 {
		nox_xxx_setGameFlags_40A4D0(0x1000000)
	} else {
		nox_common_gameFlags_unset_40A540(0x1000000)
	}
	return 1
}
func sub_4200E0() int32 {
	return int32(*memmap.PtrUint32(0x587000, 60072))
}
func sub_420100() int32 {
	return int32(*memmap.PtrUint32(0x587000, 60072) >> 8)
}
func sub_420230(a1 *byte, a2 *uint16) int32 {
	var (
		v3 *byte
		v4 *byte
		v6 [128]byte
	)
	if a1 == nil {
		return 0
	}
	if a2 == nil {
		return 0
	}
	v2 := dword_5d4594_534808
	if dword_5d4594_534808 == nil {
		return 0
	}
	for {
		if nox_strcmpi((*byte)(unsafe.Add(v2, 95)), internCStr("LAD")) == 0 {
			libc.StrCpy(&v6[0], (*byte)(unsafe.Add(v2, 100)))
			*a1 = 0
			*a2 = 0
			libc.StrTok(&v6[0], internCStr(";"))
			v3 = libc.StrTok(nil, internCStr(";"))
			if v3 != nil {
				libc.StrCpy(a1, v3)
			}
			v4 = libc.StrTok(nil, internCStr(";"))
			if v4 != nil {
				*a2 = uint16(int16(libc.Atoi(libc.GoString(v4))))
			}
			if *a1 != 0 && int32(*a2) != 0 {
				break
			}
		}
		v2 = *(*unsafe.Pointer)(unsafe.Add(v2, 20))
		if v2 == nil {
			return 0
		}
	}
	return 1
}
func sub_420360(a1 *byte, a2 *uint16) int32 {
	var (
		v3 *byte
		v4 *byte
		v5 *byte
		v7 [128]byte
	)
	if a1 == nil {
		return 0
	}
	if a2 == nil {
		return 0
	}
	*a1 = 0
	*a2 = 0
	v2 := dword_5d4594_534808
	if dword_5d4594_534808 == nil {
		return 0
	}
	for {
		if nox_strcmpi((*byte)(unsafe.Add(v2, 95)), internCStr("GAM")) == 0 {
			if noxflags.HasGame(4096) {
				if nox_strcmpi((*byte)(unsafe.Add(v2, 24)), internCStr("Quest gameres server")) == 0 {
					libc.StrCpy(&v7[0], (*byte)(unsafe.Add(v2, 100)))
					*a1 = 0
					*a2 = 0
					libc.StrTok(&v7[0], internCStr(";"))
					v3 = libc.StrTok(nil, internCStr(";"))
					if v3 != nil {
						libc.StrCpy(a1, v3)
					}
					v4 = libc.StrTok(nil, internCStr(";"))
					if v4 != nil {
						*a2 = uint16(int16(libc.Atoi(libc.GoString(v4))))
					}
				}
			} else {
				if !noxflags.HasGame(0x2000) {
					return 0
				}
				if nox_strcmpi((*byte)(unsafe.Add(v2, 24)), internCStr("Gameres server")) == 0 {
					libc.StrCpy(&v7[0], (*byte)(unsafe.Add(v2, 100)))
					*a1 = 0
					*a2 = 0
					libc.StrTok(&v7[0], internCStr(";"))
					v5 = libc.StrTok(nil, internCStr(";"))
					if v5 != nil {
						libc.StrCpy(a1, v5)
					}
					v4 = libc.StrTok(nil, internCStr(";"))
					if v4 != nil {
						*a2 = uint16(int16(libc.Atoi(libc.GoString(v4))))
					}
				}
			}
			if *a1 != 0 && int32(*a2) != 0 {
				return 1
			}
		}
		v2 = *(*unsafe.Pointer)(unsafe.Add(v2, 20))
		if v2 == nil {
			return 0
		}
	}
}
func sub_4207E0() unsafe.Pointer {
	return *memmap.PtrPtr(0x5D4594, 534812)
}
func sub_420C40(a1 int32, a2 int32) unsafe.Pointer {
	result := alloc.Calloc1(1, 0xC)
	if result == nil {
		return result
	}
	*(*uint32)(result) = uint32(a1)
	*(*uint32)(unsafe.Add(result, 4*1)) = uint32(a2)
	*(*unsafe.Pointer)(unsafe.Add(result, 4*2)) = dword_5d4594_588068
	dword_5d4594_588068 = result
	return result
}
func sub_420C70() {
	if dword_5d4594_588068 != nil {
		result := dword_5d4594_588068
		for {
			v1 := *(*unsafe.Pointer)(unsafe.Add(result, 4*2))
			alloc.FreePtr(result)
			result = v1
			if v1 == nil {
				break
			}
		}
	}
	dword_5d4594_588068 = nil
}
func nox_xxx_polygon_420CA0() *byte {
	var (
		v0 int32
		i  *uint8
	)
	v0 = 1
	if nox_xxx_polygonNextAngle_587000_60356 <= 1 {
		return nil
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, 535872)); *(*uint32)(unsafe.Pointer(i)) == 0; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 16)) {
		if uint32(func() int32 {
			p := &v0
			*p++
			return *p
		}()) >= nox_xxx_polygonNextAngle_587000_60356 {
			return nil
		}
	}
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v0*16)+535844))
}
func nox_xxx_polygon_420CD0(a1 *uint32) *byte {
	var (
		v1 uint32
		i  *uint8
	)
	v1 = *a1 + 1
	if v1 >= nox_xxx_polygonNextAngle_587000_60356 {
		return nil
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v1)*16+535856)); *(*uint32)(unsafe.Pointer(i)) == 0; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 16)) {
		if func() uint32 {
			p := &v1
			*p++
			return *p
		}() >= nox_xxx_polygonNextAngle_587000_60356 {
			return nil
		}
	}
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v1)*16+535844))
}
func sub_420D10() int32 {
	var (
		result int32
		i      *uint8
	)
	result = 1
	if nox_xxx_polygonNextAngle_587000_60356 <= 1 {
		return int32(func() uint32 {
			p := &nox_xxx_polygonNextAngle_587000_60356
			x := *p
			*p++
			return x
		}())
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, 535872)); *(*uint32)(unsafe.Pointer(i)) != 0; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 16)) {
		if uint32(func() int32 {
			p := &result
			*p++
			return *p
		}()) >= nox_xxx_polygonNextAngle_587000_60356 {
			return int32(func() uint32 {
				p := &nox_xxx_polygonNextAngle_587000_60356
				x := *p
				*p++
				return x
			}())
		}
	}
	return result
}
func nox_xxx_polygonSetAngle_420D40(a1 int32, a2 int32, a3 uint32, a4 int32) *uint32 {
	var (
		v4     bool
		result *uint32
	)
	if a4 != 0 {
		sub_420C40(int32(a3), a4)
	}
	v4 = a3 < nox_xxx_polygonNextAngle_587000_60356
	result = memmap.PtrUint32(0x5D4594, uintptr(a3)*16+535844)
	*result = a3
	if !v4 {
		nox_xxx_polygonNextAngle_587000_60356 = a3 + 1
	}
	*memmap.PtrUint32(0x5D4594, uintptr(a3)*16+535848) = uint32(a1)
	*memmap.PtrUint32(0x5D4594, uintptr(a3)*16+535852) = uint32(a2)
	*memmap.PtrUint32(0x5D4594, uintptr(a3)*16+535856) = 1
	return result
}
func sub_420DA0(a1 float32, a2 float32) *uint32 {
	var (
		v2     *int32
		v3     *int32
		v4     int32
		result *uint32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    Point32
	)
	v10.X = int32(a1)
	v10.Y = int32(a2)
	if noxflags.HasGame(0x200000) && (func() bool {
		v2 = (*int32)(unsafe.Pointer(uintptr(sub_420E80(a1, a2, 900.0))))
		return (func() *int32 {
			v3 = v2
			return v3
		}()) != nil
	}()) {
		if sub_421B40((*uint32)(unsafe.Pointer(v2))) == 0 {
			v8 = *v3
			v9 = int32(*memmap.PtrUint16(0x5D4594, 588072))
			*memmap.PtrUint16(0x5D4594, 588072)++
			*memmap.PtrUint32(0x5D4594, uintptr(v9*4)+534820) = uint32(v8)
		}
	} else if !noxflags.HasGame(0x200000) || nox_xxx_polygonIsPlayerInPolygon_4217B0(&v10, 0) == nil {
		v4 = sub_420D10()
		result = nox_xxx_polygonSetAngle_420D40(*(*int32)(unsafe.Add(unsafe.Pointer(&a1), 4*0)), *(*int32)(unsafe.Add(unsafe.Pointer(&a2), 4*0)), uint32(v4), 0)
		v6 = int32(*result)
		v7 = int32(*memmap.PtrUint16(0x5D4594, 588072))
		*memmap.PtrUint16(0x5D4594, 588072)++
		*memmap.PtrUint32(0x5D4594, uintptr(v7*4)+534820) = uint32(v6)
		return result
	}
	return nil
}
func sub_420E80(a1 float32, a2 float32, a3 float32) int32 {
	var (
		v3 int32
		v4 *uint8
		v5 int32
		v6 float64
		v7 float64
	)
	v3 = 0
	if nox_xxx_polygonNextAngle_587000_60356 <= 1 {
		return v3
	}
	v4 = (*uint8)(memmap.PtrOff(0x5D4594, 535864))
	v5 = int32(nox_xxx_polygonNextAngle_587000_60356 - 1)
	for {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) != 0 {
			v6 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*1)) - a2)
			v7 = v6*v6 + float64((*(*float32)(unsafe.Pointer(v4))-a1)*(*(*float32)(unsafe.Pointer(v4))-a1))
			if v7 < float64(a3) {
				a3 = float32(v7)
				v3 = int32(uintptr(unsafe.Add(unsafe.Pointer(v4), -4)))
			}
		}
		v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 16))
		v5--
		if v5 == 0 {
			break
		}
	}
	return v3
}
func sub_421430() unsafe.Pointer {
	var (
		v0     *uint8
		result unsafe.Pointer
	)
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 552476))
	for i := int32(0); i < math.MaxUint8; i++ {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v0), -int(4*27))) != 0 {
			if *memmap.PtrUint32(0x5D4594, 588076) != 0 {
				alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v0), -int(unsafe.Sizeof(unsafe.Pointer(nil))*27))))
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(v0), -int(4*27))) = 0
		}
		result = *(*unsafe.Pointer)(unsafe.Pointer(v0))
		if *(*uint32)(unsafe.Pointer(v0)) != 0 {
			if *memmap.PtrUint32(0x5D4594, 588076) != 0 {
				alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(v0)))
			}
			*(*uint32)(unsafe.Pointer(v0)) = 0
		}
		*(*uint16)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof(uint16(0))*10)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v0), -int(4*7))) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*2)) = math.MaxUint32
		*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*4)) = math.MaxUint32
		*(*uint32)(unsafe.Add(unsafe.Pointer(v0), -int(4*6))) = 0
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 140))
	}
	nox_xxx_polygonNextIdx_587000_60352 = 1
	return result
}
func sub_421010() *byte {
	var result *byte
	result = (*byte)(memmap.PtrOff(0x5D4594, 535872))
	for {
		*(*uint32)(unsafe.Pointer(result)) = 0
		result = (*byte)(unsafe.Add(unsafe.Pointer(result), 16))
		if int32(uintptr(unsafe.Pointer(result))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 552240))) {
			break
		}
	}
	nox_xxx_polygonNextAngle_587000_60356 = 1
	return result
}
func nox_xxx_polygonGetAngle_421030(a1 int32) *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(a1*16)+535844))
}
func sub_421040(a1 unsafe.Pointer) {
	v1 := int32(0)
	if int32(*(*uint16)(unsafe.Add(a1, 128))) != 0 {
		v2 := dword_5d4594_588068
		for {
			v3 := v2
			if v2 != nil {
				v4 := int32(*(*uint32)(unsafe.Add(a1, 108)))
				v5 := int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + v1*4))))
				v6 := (*uint32)(unsafe.Pointer(uintptr(v4 + v1*4)))
				for uint32(v5) != *(*uint32)(unsafe.Add(v3, 4*1)) {
					v3 = *(*unsafe.Pointer)(unsafe.Add(v3, 4*2))
					if v3 == nil {
						goto LABEL_9
					}
				}
				*v6 = *(*uint32)(v3)
				v2 = dword_5d4594_588068
			}
		LABEL_9:
			v1++
			if v1 >= int32(*(*uint16)(unsafe.Add(a1, 128))) {
				break
			}
		}
	}
}
func nox_xxx_polygonGetNext_4210A0() *byte {
	var (
		v0 int32
		i  *uint8
	)
	v0 = 1
	if nox_xxx_polygonNextIdx_587000_60352 <= 1 {
		return nil
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, 552452)); *(*uint32)(unsafe.Pointer(i)) == 0; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 140)) {
		if uint32(func() int32 {
			p := &v0
			*p++
			return *p
		}()) >= nox_xxx_polygonNextIdx_587000_60352 {
			return nil
		}
	}
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v0*140)+552228))
}
func sub_4210E0(a1 unsafe.Pointer) *byte {
	var (
		v1 uint32
		i  *uint8
	)
	v1 = *(*uint32)(unsafe.Add(a1, 80)) + 1
	if v1 >= nox_xxx_polygonNextIdx_587000_60352 {
		return nil
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v1)*140+552312)); *(*uint32)(unsafe.Pointer(i)) == 0; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 140)) {
		if func() uint32 {
			p := &v1
			*p++
			return *p
		}() >= nox_xxx_polygonNextIdx_587000_60352 {
			return nil
		}
	}
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(v1)*140+552228))
}
func sub_421130() int32 {
	var (
		result int32
		i      *uint8
	)
	result = 1
	if nox_xxx_polygonNextIdx_587000_60352 <= 1 {
		return int32(func() uint32 {
			p := &nox_xxx_polygonNextIdx_587000_60352
			x := *p
			*p++
			return x
		}())
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, 552452)); *(*uint32)(unsafe.Pointer(i)) != 0; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 140)) {
		if uint32(func() int32 {
			p := &result
			*p++
			return *p
		}()) >= nox_xxx_polygonNextIdx_587000_60352 {
			return int32(func() uint32 {
				p := &nox_xxx_polygonNextIdx_587000_60352
				x := *p
				*p++
				return x
			}())
		}
	}
	return result
}
func sub_421160(a1 unsafe.Pointer) {
	libc.StrCpy((*byte)(unsafe.Add(a1, 4)), (*byte)(memmap.PtrOff(0x587000, 60364)))
	*(*uint8)(unsafe.Add(a1, 104)) = *memmap.PtrUint8(0x587000, 60464)
	*(*uint8)(unsafe.Add(a1, 105)) = *memmap.PtrUint8(0x587000, 60465)
	*(*uint8)(unsafe.Add(a1, 106)) = *memmap.PtrUint8(0x587000, 60466)
	*(*uint8)(unsafe.Add(a1, 130)) = *memmap.PtrUint8(0x587000, 60490)
	*(*uint32)(unsafe.Add(a1, 132)) = 0
	*(*uint32)(unsafe.Add(a1, 136)) = 0
}
func sub_4211D0(a1 unsafe.Pointer) {
	libc.StrCpy((*byte)(memmap.PtrOff(0x587000, 60364)), (*byte)(unsafe.Add(a1, 4)))
	*memmap.PtrUint8(0x587000, 60464) = *(*uint8)(unsafe.Add(a1, 104))
	*memmap.PtrUint8(0x587000, 60465) = *(*uint8)(unsafe.Add(a1, 105))
	*memmap.PtrUint8(0x587000, 60466) = *(*uint8)(unsafe.Add(a1, 106))
	*memmap.PtrUint8(0x587000, 60490) = *(*uint8)(unsafe.Add(a1, 130))
	*(*uint32)(unsafe.Add(a1, 132)) = 0
	*(*uint32)(unsafe.Add(a1, 136)) = 0
}
func sub_421230() *uint8 {
	v0 := sub_421130()
	v1 := (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v0)*140+552228))
	*(*uint32)(unsafe.Pointer(v1)) = 0
	if noxflags.HasGame(0x200000) {
		v2 := (*uint8)(alloc.Calloc1(1, 0x100))
		*(*uint32)(unsafe.Pointer(v1)) = uint32(uintptr(unsafe.Pointer(v2)))
		if v2 == nil {
			alloc.FreePtr(unsafe.Pointer(v1))
			return nil
		}
		*v2 = 0
		*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v1)), 128)) = 0
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*20)) = uint32(v0)
	nox_itoa(v0, (*byte)(unsafe.Add(unsafe.Pointer(v1), 4)), 10)
	sub_421160(unsafe.Pointer(v1))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*21)) = 1
	return (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v0*140)+552228))
}
func nox_xxx_polygonGetByIdx_4214A0(a1 uint32) *byte {
	if a1 == 0xDEADFACE {
		return nil
	}
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(a1)*140+552228))
}
func sub_4214D0() {
	var (
		v0 *uint8
		v1 int32
		v2 *uint8
		v3 int32
		v4 int32
		v5 bool
		v6 *uint8
	)
	if int32(*memmap.PtrUint16(0x5D4594, 588072)) >= 3 {
		v0 = sub_421230()
		if v0 != nil {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*27)) = uint32(uintptr(alloc.Calloc1(int(*memmap.PtrUint16(0x5D4594, 588072)), 4)))
			v1 = 0
			*(*uint16)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof(uint16(0))*64)) = *memmap.PtrUint16(0x5D4594, 588072)
			if int32(*memmap.PtrUint16(0x5D4594, 588072)) != 0 {
				for {
					*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*27)) + uint32(v1*4)))) = *memmap.PtrUint32(0x5D4594, uintptr(v1*4)+534820)
					v1++
					if v1 >= int32(*memmap.PtrUint16(0x5D4594, 588072)) {
						break
					}
				}
			}
			v2 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(**(**uint32)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof((*uint32)(nil))*27)))*16+535844))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*22)) = uint32(int32(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*1))))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*23)) = uint32(int32(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*2))))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*24)) = uint32(int32(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*1))))
			v3 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float32(0))*2)))
			v4 = 1
			v5 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof(uint16(0))*64))) <= 1
			*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*25)) = uint32(v3)
			if !v5 {
				for {
					v6 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*27)) + uint32(v4*4)))))*16+535844))
					if float64(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*1))) >= float64(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*22))) {
						if float64(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*1))) > float64(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*24))) {
							*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*24)) = uint32(int32(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*1))))
						}
					} else {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*22)) = uint32(int32(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*1))))
					}
					if float64(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*2))) >= float64(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*23))) {
						if float64(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*2))) > float64(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*25))) {
							*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*25)) = uint32(int32(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*2))))
						}
					} else {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*23)) = uint32(int32(*(*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*2))))
					}
					v4++
					if v4 >= int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof(uint16(0))*64))) {
						break
					}
				}
			}
			*memmap.PtrUint16(0x5D4594, 588072) = 0
		}
	}
}
func nox_xxx_polygon_421660(a1 *int32, a2 unsafe.Pointer) int32 {
	var (
		v2  int8
		v4  int32
		v5  int32
		v6  *uint32
		v7  *uint8
		v8  int32
		v9  uint16
		v10 uint16
		v11 *uint8
		v12 int4
		v16 int4
	)
	v2 = 0
	if a2 == nil {
		return 0
	}
	v4 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	v16.field_0 = *a1
	v16.field_4 = v4
	if (int32(*memmap.PtrUint8(0x5D4594, 588080)) & 2) != 0 {
		v5 = 0x1700
	} else {
		v5 = 0
	}
	*memmap.PtrUint32(0x5D4594, 588080)++
	v6 = *(**uint32)(unsafe.Add(a2, 108))
	v16.field_8 = v5
	if (int32(*memmap.PtrUint8(0x5D4594, 588080)) & 2) != 0 {
		v16.field_C = 0x1700
	} else {
		v16.field_C = 0
	}
	v7 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(*v6)*16+535844))
	v12.field_0 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*1)))
	v8 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*2)))
	v9 = *(*uint16)(unsafe.Add(a2, 128))
	v10 = 1
	for v12.field_4 = v8; int32(v10) <= int32(v9); v10++ {
		v11 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(a2, 108)) + uint32((int32(v10)%int32(v9))*4)))))*16+535844))
		if int32(v10)&1 != 0 {
			v12.field_8 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v11), unsafe.Sizeof(float32(0))*1)))
			v12.field_C = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v11), unsafe.Sizeof(float32(0))*2)))
		} else {
			v12.field_0 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v11), unsafe.Sizeof(float32(0))*1)))
			v12.field_4 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v11), unsafe.Sizeof(float32(0))*2)))
		}
		if sub_427C80(&v16, &v12) != 0 {
			v2++
		}
		v9 = *(*uint16)(unsafe.Add(a2, 128))
	}
	return int32(v2) & 1
}
func nox_xxx_polygonGetIdxA_421790(a1 *Point32, a2 int32) int32 {
	var (
		v2     *nox_player_polygon_check_data
		result int32
	)
	v2 = nox_xxx_polygonIsPlayerInPolygon_4217B0(a1, a2)
	if v2 != nil {
		result = v2.field_0[20]
	} else {
		result = 0
	}
	return result
}
func nox_xxx_polygonIsPlayerInPolygon_4217B0(a1 *Point32, a2 int32) *nox_player_polygon_check_data {
	var (
		v2 int32
		v4 int32
		i  *uint8
		v6 int32
	)
	if a2 != 0 {
		if a2 != -559023410 {
			if *memmap.PtrUint32(0x5D4594, uintptr(a2*140)+552312) != 0 {
				v2 = nox_xxx_pointInRect_4281F0(a1, (*int4)(memmap.PtrOff(0x5D4594, uintptr(a2*140)+552316)))
				if v2 != 0 {
					if nox_xxx_polygon_421660(&a1.X, memmap.PtrOff(0x5D4594, uintptr(a2*140)+552228)) != 0 {
						return (*nox_player_polygon_check_data)(memmap.PtrOff(0x5D4594, uintptr(a2*140)+552228))
					}
				}
			}
		}
	}
	v4 = 1
	if nox_xxx_polygonNextIdx_587000_60352 <= 1 {
		return nil
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, 552448)); ; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 140)) {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) != 0 {
			if *(*uint32)(unsafe.Pointer(i)) != uint32(a2) {
				v6 = nox_xxx_pointInRect_4281F0(a1, (*int4)(unsafe.Add(unsafe.Pointer(i), 8)))
				if v6 != 0 {
					if nox_xxx_polygon_421660(&a1.X, unsafe.Add(unsafe.Pointer(i), -80)) != 0 {
						break
					}
				}
			}
		}
		if uint32(func() int32 {
			p := &v4
			*p++
			return *p
		}()) >= nox_xxx_polygonNextIdx_587000_60352 {
			return nil
		}
	}
	return (*nox_player_polygon_check_data)(unsafe.Add(unsafe.Pointer(i), -80))
}
func sub_421880(a1 unsafe.Pointer, a2 unsafe.Pointer, a3 float32) int32 {
	var (
		v3 *uint8
		v4 int32
		v5 int32
		v6 int32
		v7 *uint8
		v9 int4
	)
	v3 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(**(**uint32)(unsafe.Add(a2, 108)))*16+535844))
	v9.field_0 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*1)))
	v4 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*2)))
	v5 = 1
	v6 = int32(*(*uint16)(unsafe.Add(a2, 128)))
	v9.field_4 = v4
	if int32(uint16(int16(v6))) < 1 {
		return 0
	}
	for {
		v7 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(a2, 108)) + uint32((v5%v6)*4)))))*16+535844))
		if v5&1 != 0 {
			v9.field_8 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*1)))
			v9.field_C = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*2)))
		} else {
			v9.field_0 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*1)))
			v9.field_4 = int32(*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*2)))
		}
		if sub_427DF0(a1, unsafe.Pointer(&v9.field_0), a3) != 0 {
			break
		}
		v5++
		v6 = int32(*(*uint16)(unsafe.Add(a2, 128)))
		if v5 > int32(uint16(int16(v6))) {
			return 0
		}
	}
	return 1
}
func sub_421990(a1 *Point32, a2 float32, a3 int32) *int32 {
	var (
		i  *int32
		v5 int32
	)
	if a3 != 0 {
		if a3 != -559023410 {
			i = memmap.PtrInt32(0x5D4594, uintptr(a3)*140+552228)
			if *memmap.PtrUint32(0x5D4594, uintptr(a3)*140+552312) != 0 {
				if sub_421880(unsafe.Pointer(a1), memmap.PtrOff(0x5D4594, uintptr(a3*140)+552228), a2) != 0 {
					return i
				}
			}
		}
	}
	v5 = 1
	if nox_xxx_polygonNextIdx_587000_60352 > 1 {
		for i = memmap.PtrInt32(0x5D4594, 552368); *(*int32)(unsafe.Add(unsafe.Pointer(i), 4*21)) == 0 || *(*int32)(unsafe.Add(unsafe.Pointer(i), 4*20)) == a3 || sub_421880(unsafe.Pointer(a1), unsafe.Pointer(i), a2) == 0; i = (*int32)(unsafe.Add(unsafe.Pointer(i), 4*35)) {
			if uint32(func() int32 {
				p := &v5
				*p++
				return *p
			}()) >= nox_xxx_polygonNextIdx_587000_60352 {
				return nil
			}
		}
		return i
	}
	return nil
}
func sub_421B10() {
	sub_421430()
	sub_421010()
	sub_420C70()
	*memmap.PtrUint32(0x5D4594, 588076) = 1
	*memmap.PtrUint16(0x5D4594, 588072) = 0
}
func sub_421B40(a1 *uint32) int32 {
	var (
		v1 int32
		i  *uint8
	)
	v1 = 0
	if int32(*memmap.PtrUint16(0x5D4594, 588072)) <= 0 {
		return 0
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, 534820)); *(*uint32)(unsafe.Pointer(i)) != *a1; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 4)) {
		if func() int32 {
			p := &v1
			*p++
			return *p
		}() >= int32(*memmap.PtrUint16(0x5D4594, 588072)) {
			return 0
		}
	}
	return 1
}
func nox_xxx_polygonDrawColor_421B80() {
	var (
		v1 *byte
		v2 *byte
		v3 *nox_player_polygon_check_data
		v4 *byte
		v5 Point32
		v6 Point32
	)
	v0 := *memmap.PtrPtr(0x852978, 8)
	if v0 == nil {
		return
	}
	nox_xxx_getSomeCoods_435670(&v5)
	sub_435690((*uint32)(unsafe.Pointer(&v6)))
	v1 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(v0, 128))))))
	v2 = v1
	if v1 == nil {
		return
	}
	if nox_xxx_polygonNextIdx_587000_60352 > 1 {
		if *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*915)) != -559023410 && v5.X == v6.X && v5.Y == v6.Y {
			return
		}
		v3 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v5, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*915))))
		if v3 != nil {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*915)) != uint32(v3.field_0[20]) {
				*(*byte)(unsafe.Add(unsafe.Pointer(v2), 3668)) = *(*uint8)(unsafe.Add(unsafe.Pointer(&v3.field_0[32]), 2))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*915)) = uint32(v3.field_0[20])
				sub_434990(int32(*(*uint8)(unsafe.Pointer(&v3.field_0[26]))), int32(*(*uint8)(unsafe.Add(unsafe.Pointer(&v3.field_0[26]), 1))), int32(*(*uint8)(unsafe.Add(unsafe.Pointer(&v3.field_0[26]), 2))))
			}
			return
		}
	}
	*(*byte)(unsafe.Add(unsafe.Pointer(v2), 3668)) = 1
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*915)) = 0
	v4 = nox_xxx_getAmbientColor_469BB0()
	sub_4349C0(*(*[3]uint32)(unsafe.Pointer(v4)))
}
func nox_xxx_questCheckSecretArea_421C70(a1p *server.Object) {
	var (
		a1  = a1p
		v2  int32
		v3  float32
		v4  *uint8
		v5  int32
		v6  int32
		v7  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 Point32
	)
	if a1 == nil || (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&4) == 0 {
		return
	}
	v1 := *(*unsafe.Pointer)(unsafe.Add(a1.UpdateData, 276))
	if int32(*(*uint8)(unsafe.Add(v1, 2064))) == 31 {
		v11 = int32(*(*uint32)(unsafe.Add(v1, 3660)))
		if v11 == 0 {
			*(*uint32)(unsafe.Add(v1, 3664)) = 0
			goto LABEL_33
		}
		if v11 == -559023410 {
			goto LABEL_33
		}
		v4 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v11*140)+552228))
	} else {
		if *(*int32)(unsafe.Add(v1, 3664)) != -559023410 && a1.PosVec.X == a1.PrevPos.X && a1.PosVec.Y == a1.PrevPos.Y {
			return
		}
		v2 = int32(a1.PosVec.X)
		v3 = a1.PosVec.Y
		v13.X = v2
		v13.Y = int32(v3)
		v4 = (*uint8)(unsafe.Pointer(nox_xxx_polygonIsPlayerInPolygon_4217B0(&v13, int32(*(*uint32)(unsafe.Add(v1, 3664))))))
		if v4 != nil {
			goto LABEL_12
		}
		v5 = int32(*(*uint32)(unsafe.Add(v1, 3664)))
		if v5 == 0 || v5 == -559023410 {
			goto LABEL_33
		}
		v4 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v5*140)+552228))
	}
	if v4 == nil {
		goto LABEL_33
	} else {
		goto LABEL_12
	}
LABEL_33:
	v12 = int32(*(*uint32)(unsafe.Add(v1, 3664)))
	if v12 != 0 && v12 != -559023410 {
		if *memmap.PtrInt32(0x5D4594, uintptr(v12*140)+552352) != -1 {
			nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(memmap.PtrInt32(0x5D4594, uintptr(v12)*140+552348)), unsafe.Pointer(a1), nil, 27)
		}
		*(*uint32)(unsafe.Add(v1, 3664)) = 0
		*(*uint8)(unsafe.Add(v1, 3668)) = 1
	}
	return
LABEL_12:
	v6 = int32(*(*uint32)(unsafe.Add(v1, 3664)))
	if uint32(v6) != *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*20)) {
		if v6 != -559023410 {
			if v6 != 0 {
				v7 = v6 * 35
				if *memmap.PtrInt32(0x5D4594, uintptr(v7*4)+552352) != -1 {
					nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(memmap.PtrInt32(0x5D4594, uintptr(v7)*4+552348)), unsafe.Pointer(a1), nil, 29)
				}
			}
			if (uint32(1<<int32(*(*uint8)(unsafe.Add(v1, 2064))))&*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*34))) == 0 && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 132)))&1 != 0 && noxflags.HasGame(4096) {
				sub_4D61F0(unsafe.Pointer(a1))
				nox_xxx_netPriMsgToPlayer_4DA2C0(a1, internCStr("GeneralPrint:SecretFound"), 0)
				nox_xxx_aud_501960(904, a1, 0, 0)
				for i := nox_xxx_getFirstPlayerUnit_4DA7C0(); i != nil; i = nox_xxx_getNextPlayerUnit_4DA7F0(i) {
					if i != a1 {
						nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i.UpdateData, 276)), 2064))), 20, (*int32)(unsafe.Pointer(&a1.NetCode)))
					}
				}
				v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*33)))
				*(*uint8)(unsafe.Pointer(&v9)) = uint8(int8(v9 & 0xFE))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*33)) = uint32(v9)
			}
			v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*29)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*34)) |= 1 << int32(*(*uint8)(unsafe.Add(v1, 2064)))
			if v10 != -1 {
				nox_xxx_scriptCallByEventBlock_502490(unsafe.Add(unsafe.Pointer(v4), 4*28), unsafe.Pointer(a1), nil, 28)
			}
		}
		*(*uint32)(unsafe.Add(v1, 3664)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*20))
		*(*uint8)(unsafe.Add(v1, 3668)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), 130))
	}
	return
}
func sub_421F10(a1 *int32, a2 int32) *uint8 {
	var (
		v2 *uint8
		v3 int32
		v5 int32
		i  *uint8
		v7 int32
	)
	if a2 != 0 {
		if uint32(a2) != 0xDEADFACE {
			v2 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(a2*140)+552228))
			if *memmap.PtrUint32(0x5D4594, uintptr(a2*140)+552312) != 0 {
				if *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*29)) != -1 || *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*31)) != -1 {
					v3 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(a1)), (*int4)(unsafe.Add(unsafe.Pointer(v2), 88)))
					if v3 != 0 {
						if nox_xxx_polygon_421660(a1, memmap.PtrOff(0x5D4594, uintptr(a2*140)+552228)) != 0 {
							return (*uint8)(memmap.PtrOff(0x5D4594, uintptr(a2*140)+552228))
						}
					}
				}
			}
		}
	}
	v5 = 1
	if nox_xxx_polygonNextIdx_587000_60352 <= 1 {
		return nil
	}
	for i = (*uint8)(memmap.PtrOff(0x5D4594, 552448)); ; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 140)) {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) != 0 && *(*int32)(unsafe.Pointer(i)) != a2 && (*(*int32)(unsafe.Add(unsafe.Pointer(i), 4*9)) != -1 || *(*int32)(unsafe.Add(unsafe.Pointer(i), 4*11)) != -1) {
			v7 = nox_xxx_pointInRect_4281F0((*Point32)(unsafe.Pointer(a1)), (*int4)(unsafe.Add(unsafe.Pointer(i), 8)))
			if v7 != 0 {
				if nox_xxx_polygon_421660(a1, unsafe.Add(unsafe.Pointer(i), -80)) != 0 {
					break
				}
			}
		}
		if uint32(func() int32 {
			p := &v5
			*p++
			return *p
		}()) >= nox_xxx_polygonNextIdx_587000_60352 {
			return nil
		}
	}
	return (*uint8)(unsafe.Add(unsafe.Pointer(i), -80))
}
func nox_xxx_monsterPolygonEnter_421FF0(a1p *server.Object) {
	var (
		a1  = unsafe.Pointer(a1p)
		v1  *int32
		v2  int32
		v3  float32
		v4  *uint32
		v5  int32
		v6  *uint32
		v7  int32
		v8  int32
		v9  *uint8
		v10 Point32
	)
	v1 = *(**int32)(unsafe.Add(a1, 748))
	if a1p != nil && int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 && (*v1 == -559023410 || *(*float32)(unsafe.Add(a1, 56)) != *(*float32)(unsafe.Add(a1, 72)) || *(*float32)(unsafe.Add(a1, 60)) != *(*float32)(unsafe.Add(a1, 76))) {
		v2 = int32(*(*float32)(unsafe.Add(a1, 56)))
		v3 = *(*float32)(unsafe.Add(a1, 60))
		v10.X = v2
		v10.Y = int32(v3)
		if *v1 == -559023410 {
			v4 = (*uint32)(unsafe.Pointer(nox_xxx_polygonIsPlayerInPolygon_4217B0(&v10, 0)))
		} else {
			v4 = (*uint32)(unsafe.Pointer(sub_421F10(&v10.X, *v1)))
		}
		v5 = *v1
		v6 = v4
		if v4 != nil {
			if uint32(v5) != *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*20)) {
				if v5 != -559023410 {
					if v5 != 0 {
						v7 = v5 * 35
						if *memmap.PtrInt32(0x5D4594, uintptr(v7*4)+552352) != -1 {
							nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(memmap.PtrInt32(0x5D4594, uintptr(v7)*4+552348)), a1, nil, 26)
						}
					}
					if *(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*29)) != math.MaxUint32 {
						nox_xxx_scriptCallByEventBlock_502490(unsafe.Add(unsafe.Pointer(v6), 4*28), a1, nil, 25)
					}
				}
				*v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*20)))
			}
		} else if v5 != 0 && v5 != -559023410 {
			v8 = v5 * 35
			v9 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v8*4)+552228))
			if *memmap.PtrUint32(0x5D4594, uintptr(v8*4)+552312) != 0 && *(*int32)(unsafe.Add(unsafe.Pointer(v9), 4*31)) != -1 {
				nox_xxx_scriptCallByEventBlock_502490(unsafe.Add(unsafe.Pointer(v9), 4*30), a1, nil, 24)
			}
			*v1 = 0
		}
	}
}
func sub_422140(a1 unsafe.Pointer) {
	if a1 != nil {
		*(*uint32)(unsafe.Add(a1, 3660)) = 3735943886
		*(*uint32)(unsafe.Add(a1, 3664)) = 3735943886
	}
}

type TileZzz struct {
	Field0   uint32   // 0, 0
	Field4   uint32   // 1, 4
	Field8   uint32   // 2, 8
	Field12  uint32   // 3, 12
	Field16  *TileZzz // 4, 16
	Field20  uint32   // 5, 20
	Field24  uint32   // 6, 24
	Field28  uint32   // 7, 28
	Field32  uint32   // 8, 32
	Field36  uint32   // 9, 36
	Field40  uint32   // 10, 40
	Field44  uint32   // 11, 44
	Field48  uint32   // 12, 48
	Field52  uint32   // 13, 52
	Field56  uint32   // 14, 56
	Field60  uint32   // 15, 60
	Field64  uint32   // 16, 64
	Field68  uint32   // 17, 68
	Field72  uint32   // 18, 72
	Field76  uint32   // 19, 76
	Field80  uint32   // 20, 80
	Field84  uint32   // 21, 84
	Field88  uint32   // 22, 88
	Field92  uint32   // 23, 92
	Field96  uint32   // 24, 96
	Field100 uint32   // 25, 100
	Field104 uint32   // 26, 104
	Field108 uint32   // 27, 108
	Field112 uint32   // 28, 112
	Field116 uint32   // 29, 116
	Field120 uint32   // 30, 120
	Field124 uint32   // 31, 124
	Field128 uint32   // 32, 128
	Field132 uint32   // 33, 132
	Field136 uint32   // 34, 136
	Field140 uint32   // 35, 140
	Field144 uint32   // 36, 144
	Field148 uint32   // 37, 148
	Field152 uint32   // 38, 152
	Field156 uint32   // 39, 156
	Field160 uint32   // 40, 160
	Field164 uint32   // 41, 164
	Field168 uint32   // 42, 168
	Field172 uint32   // 43, 172
	Field176 uint32   // 44, 176
	Field180 uint32   // 45, 180
	Field184 uint32   // 46, 184
	Field188 uint32   // 47, 188
	Field192 uint32   // 48, 192
	Field196 uint32   // 49, 196
}

type TileZzzSub struct {
	Field0  uint32 // 0, 0
	Field4  uint32 // 1, 4
	Field8  uint32 // 2, 8
	Field12 uint32 // 3, 12
	Field16 uint32 // 4, 16
}

func nox_xxx_tileListAddNewSubtile_422160(a1 int32, a2 int32, a3 int32, a4 int32) *TileZzz {
	p := dword_5d4594_588084
	if dword_5d4594_588084 == nil {
		v5, _ := alloc.New(TileZzz{})
		dword_5d4594_588084 = v5
		for i := 0; i < 180; i += 20 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v5), i+16)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v5), i+20)))
			v5 = dword_5d4594_588084
		}
		dword_5d4594_588084.Field196 = 0
		p = dword_5d4594_588084
	}
	dword_5d4594_588084 = p.Field16
	p.Field0 = uint32(a1)
	p.Field4 = uint32(a2)
	p.Field8 = uint32(a3)
	p.Field12 = uint32(a4)
	p.Field16 = nil
	return p
}
func Nox_xxx_tileFreeTileOne_4221E0(a1 *TileZzz) {
	a1.Field16 = dword_5d4594_588084
	dword_5d4594_588084 = a1
}
func nox_xxx_tileFreeTile_422200(a1 *obj_5D4594_2650668_t2) {
	result := a1.Field16
	if result != nil {
		for {
			v2 := *(*unsafe.Pointer)(unsafe.Add(result, 16))
			Nox_xxx_tileFreeTileOne_4221E0((*TileZzz)(result))
			result = v2
			if v2 == nil {
				break
			}
		}
	}
	a1.Field16 = nil
}
func nox_server_mapRWFloorMap_422230(a1p unsafe.Pointer) int32 {
	var (
		v2  int32
		v3  int8
		v4  int32
		v7  int8
		v8  int32
		m   int32
		v10 int32
		v12 int8
		v13 int32
		v16 int32
		v18 int32
		v19 int8
		n   int32
		v22 int32
		v23 int32
		v25 int32
		ii  int32
		v28 uint16
		v29 int32
		v30 int32
		v31 *uint8
		v32 *uint8
		v33 int32
		v34 int32
		v35 int8
		v36 int32
		v40 uint16
		v41 int32
		v42 int32
		v43 uint16
		k   uint16
		v47 int16
		v48 int32
		v49 int32
		v50 int32
		v51 int32
		v52 int32
		v53 int32
		v54 unsafe.Pointer
		v55 *uint8
	)
	var v56 int32
	var v58 int32
	var v59 int32
	var v60 int32
	var v61 int32
	var v62 int32
	var v63 int32 = 0
	var v64 int32 = 0
	var v65 int32 = 0
	var v66 int32
	var v67 int32
	var v68 int32
	var v69 Point32
	var v70 int4
	v62 = 4
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v62)), 2)
	if int32(int16(v62)) > 4 {
		return 0
	}
	if int32(int16(v62)) <= 3 {
		return nox_xxx_tile_422C10(v62, a1p)
	}
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v60)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v61)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v66)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v67)), 4)
		if a1p != nil {
			sub_428170(a1p, &v70)
			v41 = v70.field_0/23 - v60
			v42 = v70.field_4/23 - v61
			a1 := v70.field_4/23 - v61
			v61 = v70.field_4 / 23
			v60 = v70.field_0 / 23
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v59)), 2)
			v43 = uint16(int16(v59))
			if int32(uint16(int16(v59))) != math.MaxUint16 {
				for {
					v50 = v41 + (int32(v43) >> 8)
					v51 = v42 + int32(uint8(v43))
					if (int32(uint8(int8(v42)))+int32(uint8(v43)))&1 != 0 {
						v56 = (v50*23 - 23) / 46
						v58 = (v51*23 + 23) / 46
						if noxflags.HasGame(0x400000) {
							v54 = unsafe.Pointer(nox_xxx_tileAllocTileInCoordList_5040A0(v56, v58, 1).Field0)
						} else {
							ptr_5D4594_2650668[v56][v58].Field0 |= 0x1
							v54 = unsafe.Pointer(&ptr_5D4594_2650668[v56][v58].Field4)
						}
					} else {
						v52 = v50 * 23 / 46
						v53 = v51 * 23 / 46
						if noxflags.HasGame(0x400000) {
							v54 = unsafe.Pointer(nox_xxx_tileAllocTileInCoordList_5040A0(v52, v51*23/46, 2).Field0)
						} else {
							v55 = &ptr_5D4594_2650668[v52][v53].Field0
							*v55 |= 0x2
							v54 = unsafe.Pointer(&ptr_5D4594_2650668[v52][v53].Field24)
						}
					}
					nox_xxx_tileReadOne_422A40(v62, (*uint8)(v54))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v59)), 2)
					v43 = uint16(int16(v59))
					if int32(uint16(int16(v59))) == math.MaxUint16 {
						break
					}
					v42 = a1
				}
				return 1
			}
		} else {
			for i := int32(0); i < ptr_5D4594_2650668_cap; i++ {
				for j := int32(0); j < ptr_5D4594_2650668_cap; j++ {
					ptr_5D4594_2650668[j][i].Field0 = 0
				}
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v59)), 2)
			for k = uint16(int16(v59)); int32(uint16(int16(v59))) != math.MaxUint16; k = uint16(int16(v59)) {
				v47 = 0
				v48 = (int32(k) >> 8) & math.MaxInt8
				v49 = int32(k) & math.MaxInt8
				if (int32(k) & 0x8000) != 0 {
					v47 = math.MinInt16
				}
				if (int32(k) & 0x80) != 0 {
					*(*uint8)(unsafe.Pointer(&v47)) = uint8(int8(int32(v47) | 0x80))
				}
				if int32(v47) < 0 {
					ptr_5D4594_2650668[v48][v49].Field0 |= 0x1
					nox_xxx_tileReadOne_422A40(v62, &ptr_5D4594_2650668[v48][v49].Field4)
				}
				if int32(v47)&0x80 != 0 {
					ptr_5D4594_2650668[v48][v49].Field0 |= 0x2
					nox_xxx_tileReadOne_422A40(v62, &ptr_5D4594_2650668[v48][v49].Field24)
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v59)), 2)
			}
		}
		return 1
	}
	if a1p != nil {
		sub_428170(a1p, &v70)
		v60 = v70.field_0 / 23
		v18 = v70.field_8 / 23
		v64 = v70.field_8 / 23
		v63 = v70.field_C / 23
		v61 = v70.field_4 / 23
		v66 = v70.field_8/23 - v70.field_0/23 + 1
		v67 = v70.field_C/23 - v70.field_4/23 + 1
		goto LABEL_43
	}
	v2 = v65
	v3 = 0
	for v4 = 0; v4 < ptr_5D4594_2650668_cap; v4++ {
		if int32(v3) != 0 {
			break
		}

		v65 = v4 * 44
		for v2 = 0; v2 < ptr_5D4594_2650668_cap; v2++ {
			v6 := &ptr_5D4594_2650668[v2][v4]
			if v6.Field0 != 0 {
				v61 = v4
				v3 = 1
				break
			}
		}
	}
	if v2 == ptr_5D4594_2650668_cap && v4 == ptr_5D4594_2650668_cap {
		return 1
	}
	v7 = 0
	v8 = 127
	for m = 127 * 44; m >= 0; m -= 44 {
		if int32(v7) != 0 {
			break
		}
		v10 = 0
		v65 = m
		v11 := ptr_5D4594_2650668
		for v11[0][m/44].Field0 == 0 {
			v10++
			v11 = v11[1:]
			if v10 >= ptr_5D4594_2650668_cap {
				goto LABEL_24
			}
		}
		v63 = v8
		v7 = 1
	LABEL_24:
		v8--
	}
	v12 = 0
	v13 = 0
	v14 := ptr_5D4594_2650668
	for {
		if int32(v12) != 0 {
			break
		}
		v15 := v14[0]
		v16 = 0
		for v15[0].Field0 == 0 {
			v16++
			v15 = v15[1:]
			if v16 >= ptr_5D4594_2650668_cap {
				goto LABEL_32
			}
		}
		v60 = v13
		v12 = 1
	LABEL_32:
		v13++
		v14 = v14[1:]
		if v13 >= ptr_5D4594_2650668_cap {
			break
		}
	}
	v18 = v64
	v19 = 0
	for n = ptr_5D4594_2650668_cap - 1; n >= 0; n-- {
		if int32(v19) != 0 {
			break
		}
		v21 := ptr_5D4594_2650668[n]
		v22 = 0
		for v21[0].Field0 == 0 {
			v22++
			v21 = v21[1:]
			if v22 >= ptr_5D4594_2650668_cap {
				goto LABEL_40
			}
		}
		v18 = n
		v19 = 1
	LABEL_40:
	}
	v64 = v18
	v66 = v18 - v60 + 1
	v67 = v63 - v61 + 1
LABEL_43:
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v60)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v61)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v66)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v67)), 4)
	if a1p != nil {
		v33 = v61
		if v61 > v63 {
			v59 = math.MaxUint16
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v59)), 2)
			return 1
		}
		v34 = v60
		for {
			v35 = int8(v34)
			v65 = v34
			if v34 <= v64 {
				v36 = v34*23 + 11
				for {
					if ((int32(uint8(int8(v33))) + int32(v35)) & 1) == 0 {
						if v33&1 != 0 {
							v39 := &ptr_5D4594_2650668[(v36-34)/46][(v33+1)*23/46]
							if v39.Field0&1 != 0 {
								v38 := &v39.Field4
								v69.X = v36
								v69.Y = v33*23 + 34
								if nox_xxx_wallMath_427F30(&v69, (*int32)(a1p)) != 0 {
									*(*uint8)(unsafe.Pointer(&v40)) = 0
									*(*uint8)(unsafe.Add(unsafe.Pointer(&v40), unsafe.Sizeof(uint16(0))-1)) = uint8(int8(v65))
									v68 = v33 | int32(v40)
									nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v68)), 2)
									nox_xxx_tileReadOne_422A40(v62, v38)
								}
								v34 = v60
								goto LABEL_73
							}
						} else {
							v37 := &ptr_5D4594_2650668[(v36-11)/46][v33*23/46]
							if v37.Field0&2 != 0 {
								v38 := &v37.Field24
								v69.X = v36
								v69.Y = v33*23 + 34
								if nox_xxx_wallMath_427F30(&v69, (*int32)(a1p)) != 0 {
									*(*uint8)(unsafe.Pointer(&v40)) = 0
									*(*uint8)(unsafe.Add(unsafe.Pointer(&v40), unsafe.Sizeof(uint16(0))-1)) = uint8(int8(v65))
									v68 = v33 | int32(v40)
									nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v68)), 2)
									nox_xxx_tileReadOne_422A40(v62, v38)
								}
								v34 = v60
								goto LABEL_73
							}
						}
					}
				LABEL_73:
					v35 = int8(v65 + 1)
					v36 += 23
					if func() int32 {
						p := &v65
						*p++
						return *p
					}() > v64 {
						break
					}
				}
			}
			v33++
			if v33 > v63 {
				v59 = math.MaxUint16
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v59)), 2)
				return 1
			}
		}
	}
	v23 = v61
	if v61 <= v63 {
		v24 := ptr_5D4594_2650668
		v25 = v61 * 44
		for {
			for ii = v60; ii <= v18; ii++ {
				v27 := v24[ii]
				if v27[v25/44].Field0&3 != 0 {
					*(*uint8)(unsafe.Pointer(&v28)) = 0
					*(*uint8)(unsafe.Add(unsafe.Pointer(&v28), unsafe.Sizeof(uint16(0))-1)) = uint8(int8(ii))
					a1 := v23 | int32(v28)
					if v27[v25/44].Field0&1 != 0 {
						v29 = a1
						*(*uint8)(unsafe.Add(unsafe.Pointer(&v29), 1)) |= 0x80
						a1 = v29
					}
					if int32(*(*uint8)(unsafe.Pointer(uintptr(uint32(v25) + *(*uint32)(unsafe.Pointer(uintptr(v24 + ii*4)))))))&2 != 0 {
						v30 = a1
						*(*uint8)(unsafe.Pointer(&v30)) = uint8(int8(a1 | 0x80))
						a1 = v30
					}
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
					v24 = ptr_5D4594_2650668
				}
				v31 = (*uint8)(unsafe.Pointer(uintptr(uint32(v25) + *(*uint32)(unsafe.Pointer(uintptr(v24 + ii*4))))))
				if int32(*v31)&1 != 0 {
					nox_xxx_tileReadOne_422A40(v62, (*uint8)(unsafe.Add(unsafe.Pointer(v31), 4)))
					v24 = ptr_5D4594_2650668
				}
				v32 = (*uint8)(unsafe.Pointer(uintptr(uint32(v25) + *(*uint32)(unsafe.Pointer(uintptr(v24 + ii*4))))))
				if int32(*v32)&2 != 0 {
					nox_xxx_tileReadOne_422A40(v62, (*uint8)(unsafe.Add(unsafe.Pointer(v32), 24)))
					v24 = ptr_5D4594_2650668
				}
			}
			v23++
			v25 += 44
			if v23 > v63 {
				break
			}
		}
	}
	v59 = math.MaxUint16
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v59)), 2)
	return 1
}
func nox_xxx_tileReadOne_422A40(a1 int32, a2p *obj_5D4594_2650668_t2) {
	var (
		v3  uint32
		v4  int8
		v5  int8
		v9  uint32
		v10 int32
		v11 bool
		v14 uint32
		v15 int32
	)
	v2 := a2p
	var a2 int32
	*(*uint8)(unsafe.Pointer(&a2)) = *(*uint8)(unsafe.Pointer(&a2p.Field0))
	v3 = nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v3), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*2))
	*(*uint32)(unsafe.Pointer(v2)) = uint32(uint8(uintptr(unsafe.Pointer(a2))))
	v14 = v3
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 2)
	v4 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 8)))
	v2.Field4 = int32(uint32(int16(uint16(v14))))
	*(*uint8)(unsafe.Pointer(&a2)) = uint8(v4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
	v5 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 12)))
	v2.Field8 = uint32(uint8(uintptr(unsafe.Pointer(a2))))
	*(*uint8)(unsafe.Pointer(&a2)) = uint8(v5)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
	v6 := v2.Field16
	v2.Field12 = uint32(uint8(uintptr(unsafe.Pointer(a2))))
	for *(*uint8)(unsafe.Pointer(&v15)) = 0; v6 != nil; v6 = *(*unsafe.Pointer)(unsafe.Add(v6, 16)) {
		*(*uint8)(unsafe.Pointer(&v15)) = uint8(int8(v15 + 1))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v15)), 1)
	if nox_crypt_IsReadOnly() != 0 {
		v10 = 0
		v11 = int32(uint8(int8(v15))) == 0
		v2.Field16 = nil
		v12 := unsafe.Pointer(v2)
		if !v11 {
			for {
				v13 := nox_xxx_tileListAddNewSubtile_422160(0, 0, 0, 0)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
				v13.Field0 = uint32(int32(uint8(uintptr(unsafe.Pointer(a2)))))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 2)
				v13.Field4 = uint32(int32(int16(uint16(v14))))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
				v13.Field8 = uint32(int32(uint8(uintptr(unsafe.Pointer(a2)))))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
				v10++
				v13.Field12 = uint32(int32(uint8(uintptr(unsafe.Pointer(a2)))))
				*(*int32)(unsafe.Add(v12, 4*4)) = int32(uintptr(v13))
				v12 = unsafe.Pointer(v13)
				if v10 >= int32(uint8(int8(v15))) {
					break
				}
			}
		}
	} else {
		for i := v2.Field16; i != nil; i = *(*unsafe.Pointer)(unsafe.Add(i, 16)) {
			*(*uint8)(unsafe.Pointer(&a2)) = *(*uint8)(i)
			v9 = nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v9), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(i, 4))
			v14 = v9
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 2)
			*(*uint8)(unsafe.Pointer(&a2)) = *(*uint8)(unsafe.Add(i, 8))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
			*(*uint8)(unsafe.Pointer(&a2)) = *(*uint8)(unsafe.Add(i, 12))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
		}
	}
}
func nox_xxx_tile_422C10(a1 int32, a2p unsafe.Pointer) int32 {
	var (
		v3  int32
		v4  int8
		v5  int32
		i   int32
		v7  *uint32
		v8  int8
		v9  int32
		j   int32
		v11 int32
		v12 *uint32
		v13 int8
		v14 int32
		v15 **uint8
		v16 *uint8
		v17 int32
		v18 **uint8
		v19 int32
		v20 int8
		k   int32
		v22 *uint8
		v23 int32
		v24 int32
		v26 int32
		v27 int32
		v35 int32
		v36 int32
		v37 int32
		v38 int32
		v39 *uint8
		v41 *uint8
		v44 int32
		v45 int32
		v46 int32
		v47 int32
		v48 int32
		v49 int32
		v51 int32
		v55 int32
		v56 int32
		v57 int32
		v58 int32
		v59 int32
		v60 *uint8
		v61 int32
		v64 int32
		v66 int32
		v67 int32
		v70 bool
		v71 *uint8
		v72 int32
		v75 int32
		v76 int32
		v77 int32
		v78 int32
		v79 int32
		v80 int32 = 0
		v81 int32 = 0
		v82 Point32
		v83 int4
	)
	if int32(int16(a1)) < 3 {
		return 0
	}
	if nox_crypt_IsReadOnly() == 0 {
		if a2p != nil {
			sub_428170(a2p, &v83)
			v76 = v83.field_0 / 23
			v80 = v83.field_8 / 23
			v77 = v83.field_4 / 23
			v81 = v83.field_C / 23
			v24 = v81
			v78 = v83.field_8/23 - v83.field_0/23 + 1
			v79 = v81 - v83.field_4/23 + 1
		} else {
			v3 = 0
			v4 = 0
			v5 = 0
			for i = 0; i < ptr_5D4594_2650668_cap*44; i += 44 {
				if int32(v4) != 0 {
					break
				}
				v3 = 0
				a1 = i
				v7 = (*uint32)(unsafe.Pointer(&ptr_5D4594_2650668[0]))
				for int32(*(*uint8)(unsafe.Pointer(uintptr(uint32(i) + *v7)))) == 0 {
					v3++
					v7 = (*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1))
					if v3 >= ptr_5D4594_2650668_cap {
						goto LABEL_12
					}
				}
				v77 = v5
				v4 = 1
			LABEL_12:
				v5++
			}
			if v3 == ptr_5D4594_2650668_cap && v5 == ptr_5D4594_2650668_cap {
				return 1
			}
			v8 = 0
			v9 = math.MaxInt8
			for j = 5588; j >= 0; j -= 44 {
				if int32(v8) != 0 {
					break
				}
				v11 = 0
				a1 = j
				v12 = (*uint32)(unsafe.Pointer(&ptr_5D4594_2650668[0]))
				for int32(*(*uint8)(unsafe.Pointer(uintptr(uint32(j) + *v12)))) == 0 {
					v11++
					v12 = (*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*1))
					if v11 >= ptr_5D4594_2650668_cap {
						goto LABEL_22
					}
				}
				v81 = v9
				v8 = 1
			LABEL_22:
				v9--
			}
			v13 = 0
			v14 = 0
			v15 = (**uint8)(unsafe.Pointer(&ptr_5D4594_2650668[0]))
			for {
				if int32(v13) != 0 {
					break
				}
				v16 = *v15
				v17 = 0
				for int32(*v16) == 0 {
					v17++
					v16 = (*uint8)(unsafe.Add(unsafe.Pointer(v16), 44))
					if v17 >= ptr_5D4594_2650668_cap {
						goto LABEL_30
					}
				}
				v76 = v14
				v13 = 1
			LABEL_30:
				v14++
				v15 = (**uint8)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof((*uint8)(nil))*1))
				if v14 >= 128 {
					break
				}
			}
			v18 = (**uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(&ptr_5D4594_2650668[0]), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(ptr_5D4594_2650668_cap)), -int(unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*1)))
			v19 = v80
			v20 = 0
			for k = ptr_5D4594_2650668_cap - 1; k >= 0; k-- {
				if int32(v20) != 0 {
					break
				}
				v22 = *v18
				v23 = 0
				for int32(*v22) == 0 {
					v23++
					v22 = (*uint8)(unsafe.Add(unsafe.Pointer(v22), 44))
					if v23 >= ptr_5D4594_2650668_cap {
						goto LABEL_38
					}
				}
				v19 = k
				v20 = 1
			LABEL_38:
				v18 = (**uint8)(unsafe.Add(unsafe.Pointer(v18), -int(unsafe.Sizeof((*uint8)(nil))*1)))
			}
			v24 = v81
			v80 = v19
			v78 = v19 - v76 + 1
			v79 = v81 - v77 + 1
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v76)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v77)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v78)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v79)), 4)
		if a2p == nil {
			if v77 > v24 {
				return 1
			}
			v26 = v76
			v27 = v80
			var v28 int32 = v77
			a2 := v81 - v77 + 1
			for {
				if v26 <= v27 {
					for {
						{
							var obj *obj_5D4594_2650668_t = (*obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668[v26]), unsafe.Sizeof(obj_5D4594_2650668_t{})*uintptr(v28)))
							nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&obj.Field0, 1)
							if int32(obj.Field0)&0x1 != 0 {
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&obj.Field4)), 16)
								*(*uint8)(unsafe.Pointer(&v75)) = 0
								for l := obj.Field20; l != nil; l = *(*unsafe.Pointer)(unsafe.Add(l, 16)) {
									*(*uint8)(unsafe.Pointer(&v75)) = uint8(int8(v75 + 1))
								}
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v75)), 1)
								for m := obj.Field20; m != nil; m = *(*unsafe.Pointer)(unsafe.Add(m, 16)) {
									nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(m), 16)
								}
							}
							if int32(obj.Field0)&0x2 != 0 {
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&obj.Field24)), 16)
								*(*uint8)(unsafe.Pointer(&v75)) = 0
								for n := obj.Field40; n != nil; n = *(*unsafe.Pointer)(unsafe.Add(n, 16)) {
									*(*uint8)(unsafe.Pointer(&v75)) = uint8(int8(v75 + 1))
								}
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v75)), 1)
								for ii := obj.Field40; ii != nil; ii = *(*unsafe.Pointer)(unsafe.Add(ii, 16)) {
									nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(ii), 16)
								}
							}
							v26++
						}
						if v26 > v27 {
							break
						}
					}
					v26 = v76
				}
				v28++
				a2--
				if a2 == 0 {
					break
				}
			}
			return 1
		}
		v35 = v77
		if v77 > v24 {
			return 1
		}
		v36 = v76
	LABEL_61:
		v37 = v36
		if v36 > v80 {
			if func() int32 {
				p := &v35
				*p++
				return *p
			}() > v81 {
				return 1
			}
			goto LABEL_61
		}
		v38 = v36*23 + 11
		for {
			if ((int32(uint8(int8(v35))) + int32(uint8(int8(v37)))) & 1) == 0 {
				var v40 unsafe.Pointer
				if v35&1 != 0 {
					v41 = (*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(&ptr_5D4594_2650668[0]), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr((v38-34)/46)))))) + uint32(((v35+1)*23/46)*44))))
					if (int32(*v41) & 1) == 0 {
						goto LABEL_75
					}
					v40 = unsafe.Add(unsafe.Pointer(v41), 4)
				} else {
					v39 = (*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(&ptr_5D4594_2650668[0]), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr((v38-11)/46)))))) + uint32((v35*23/46)*44))))
					if (int32(*v39) & 2) == 0 {
						goto LABEL_75
					}
					v40 = unsafe.Add(unsafe.Pointer(v39), 24)
				}
				v82.X = v38
				v82.Y = v35*23 + 34
				if nox_xxx_wallMath_427F30(&v82, (*int32)(a2p)) != 0 {
					*(*uint8)(unsafe.Pointer(&a1)) = 1
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(v40), 0x10)
					*(*uint8)(unsafe.Pointer(&v75)) = 0
					for jj := *(*unsafe.Pointer)(unsafe.Add(v40, 16)); jj != nil; jj = *(*unsafe.Pointer)(unsafe.Add(jj, 16)) {
						*(*uint8)(unsafe.Pointer(&v75)) = uint8(int8(v75 + 1))
					}
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v75)), 1)
					for kk := *(*unsafe.Pointer)(unsafe.Add(v40, 16)); kk != nil; kk = *(*unsafe.Pointer)(unsafe.Add(kk, 16)) {
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(kk), 0x10)
					}
					goto LABEL_76
				}
			}
		LABEL_75:
			*(*uint8)(unsafe.Pointer(&a1)) = 0
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
		LABEL_76:
			v37++
			v38 += 23
			if v37 > v80 {
				v36 = v76
				if func() int32 {
					p := &v35
					*p++
					return *p
				}() > v81 {
					return 1
				}
				goto LABEL_61
			}
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v76)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v77)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v78)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v79)), 4)
	if a2p == nil {
		for ll := int32(0); ll < ptr_5D4594_2650668_cap; ll++ {
			for mm := int32(0); mm < ptr_5D4594_2650668_cap; mm++ {
				(*obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668[mm]), unsafe.Sizeof(obj_5D4594_2650668_t{})*uintptr(ll))).Field0 = 0
			}
		}
		v55 = v77
		v81 = v77
		if v77 >= v77+v79 {
			return 1
		}
		v56 = v78
		a2 := v77 * 44
		v57 = v76
		for {
			v58 = v57
			if v57 < v56+v57 {
				for {
					v59 = a2
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(uint32(a2)+uint32(uintptr(unsafe.Pointer(ptr_5D4594_2650668[v58])))))), 1)
					v60 = (*uint8)(unsafe.Pointer(uintptr(uint32(v59) + uint32(uintptr(unsafe.Pointer(ptr_5D4594_2650668[v58]))))))
					if int32(*v60)&1 != 0 {
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v60), 4)), 0x10)
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v75)), 1)
						if int32(uint8(int8(v75))) != 0 {
							v61 = 0
							v62 := unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668[v58]), uint32(v59)+4)
							if int32(uint8(int8(v75))) != 0 {
								for {
									v63 := nox_xxx_tileListAddNewSubtile_422160(0, 0, 0, 0)
									nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(v63), 0x10)
									*(*uint32)(unsafe.Add(v62, 16)) = uint32(uintptr(v63))
									v61++
									v62 = unsafe.Pointer(v63)
									if v61 >= int32(uint8(int8(v75))) {
										break
									}
								}
							}
						} else {
							*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(ptr_5D4594_2650668[v58])))+uint32(a2))), 20)) = 0
						}
					}
					v71 = (*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(ptr_5D4594_2650668[v58]))) + uint32(a2))))
					if int32(*v71)&2 != 0 {
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v71), 24)), 0x10)
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v75)), 1)
						if int32(uint8(int8(v75))) != 0 {
							v72 = 0
							v73 := unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668[v58]), uint32(a2)+24)
							if int32(uint8(int8(v75))) != 0 {
								for {
									v74 := nox_xxx_tileListAddNewSubtile_422160(0, 0, 0, 0)
									nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(v74), 0x10)
									*(*uint32)(unsafe.Add(v73, 16)) = uint32(uintptr(v74))
									v72++
									v73 = unsafe.Pointer(v74)
									if v72 >= int32(uint8(int8(v75))) {
										break
									}
								}
							}
						} else {
							*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(ptr_5D4594_2650668[v58])))+uint32(a2))), 40)) = 0
						}
					}
					v56 = v78
					v57 = v76
					v58++
					if v58 >= v78+v76 {
						break
					}
				}
				v55 = v77
			}
			v70 = func() int32 {
				p := &v81
				*p++
				return *p
			}() < v55+v79
			a2 += 44
			if !v70 {
				break
			}
		}
		return 1
	}
	sub_428170(a2p, &v83)
	v44 = v83.field_0 / 23
	v76 = v83.field_0 / 23
	v45 = v83.field_4 / 23
	v77 = v83.field_4 / 23
	v46 = v83.field_4 / 23
	if v83.field_4/23 >= v83.field_4/23+v79 {
		return 1
	}
	v47 = v78
	for {
		a2 := v44
		if v44 < v47+v44 {
			v81 = v44 * 23
			v48 = v44 * 23
			for {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
				if int32(uint8(int8(a1))) != 0 {
					var v52 unsafe.Pointer
					if v46&1 != 0 {
						v64 = (v48 - 23) / 46
						v66 = (v46 + 23) / 46
						if noxflags.HasGame(0x400000) {
							v52 = unsafe.Pointer(nox_xxx_tileAllocTileInCoordList_5040A0(v64, v66, 1).Field0)
						} else {
							*(*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(ptr_5D4594_2650668[v64]))) + uint32(v66*44)))) |= 1
							v52 = unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668[v64]), uint32(v66*44)+4)
						}
					} else {
						v49 = v48 / 46
						v51 = v46 / 46
						if noxflags.HasGame(0x400000) {
							v52 = unsafe.Pointer(nox_xxx_tileAllocTileInCoordList_5040A0(v49, v51, 2).Field0)
						} else {
							*(*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(ptr_5D4594_2650668[v49]))) + uint32(v51*44)))) |= 2
							v52 = unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668[v49]), uint32(v51*44)+24)
						}
					}
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(v52), 0x10)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v75)), 1)
					if int32(uint8(int8(v75))) != 0 {
						v67 = 0
						v68 := v52
						if int32(uint8(int8(v75))) != 0 {
							for {
								v69 := nox_xxx_tileListAddNewSubtile_422160(0, 0, 0, 0)
								nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(v69), 0x10)
								*(*int32)(unsafe.Add(v68, 4*4)) = int32(uintptr(v69))
								v67++
								v68 = unsafe.Pointer(v69)
								if v67 >= int32(uint8(int8(v75))) {
									break
								}
							}
						}
					} else {
						*(*uint32)(unsafe.Add(v52, 16)) = 0
					}
				}
				v47 = v78
				v44 = v76
				v48 = v81 + 23
				v70 = func() int32 {
					p := &a2
					*p++
					return *p
				}() < v78+v76
				v81 += 23
				if !v70 {
					break
				}
			}
			v45 = v77
		}
		v46++
		if v46 >= v45+v79 {
			break
		}
	}
	return 1
}
func set_bitmask_flags_from_plus_separated_names_423930(input *byte, bitmask *uint32, allowed_names **byte) {
	var input_copy [256]byte
	libc.StrCpy(&input_copy[0], input)
	if libc.StrNCmp(&input_copy[0], internCStr("NULL"), 4) == 0 {
		return
	}
	var cur_value *byte = libc.StrTok(&input_copy[0], internCStr("+"))
	for cur_value != nil {
		set_one_bitmask_flag_by_name_4239C0(cur_value, bitmask, allowed_names)
		cur_value = libc.StrTok(nil, internCStr("+"))
	}
}
func set_one_bitmask_flag_by_name_4239C0(name *byte, bitmask *uint32, allowed_names **byte) int32 {
	for i := int8(0); *(**byte)(unsafe.Add(unsafe.Pointer(allowed_names), unsafe.Sizeof((*byte)(nil))*uintptr(i))) != nil; i++ {
		if nox_strcmpi(*(**byte)(unsafe.Add(unsafe.Pointer(allowed_names), unsafe.Sizeof((*byte)(nil))*uintptr(i))), name) == 0 {
			*bitmask |= 1 << int32(i)
			return 1
		}
	}
	return 0
}
func sub_4240F0(a1 int32, a2 *byte, a3 int32) int32 {
	var (
		v3 *byte
		v4 int32
		v5 *uint8
	)
	v3 = *(**byte)(memmap.PtrOff(0x587000, 64704))
	v4 = 0
	if *memmap.PtrUint32(0x587000, 64704) == 0 {
		return 0
	}
	v5 = (*uint8)(memmap.PtrOff(0x587000, 64704))
	for libc.StrCmp(a2, v3) != 0 {
		v3 = (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2)))))
		v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 8))
		v4++
		if v3 == nil {
			return 0
		}
	}
	*(*uint32)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x587000, uintptr(v4*8+64708)) + uint32(a1)))) = uint32(a3)
	return 1
}
func nox_xxx_parseSoundSetBin_424170(a1 *byte) int32 {
	var (
		v2 *FILE
		v4 *byte
		v5 int32
		v6 [256]byte
		v7 [256]byte
	)
	v2 = nox_binfile_open_408CC0(a1, 0)
	if v2 == nil {
		return 0
	}
	if nox_binfile_cryptSet_408D40(v2, 5) == 0 {
		return 0
	}
	for nox_xxx_parseString_409470(v2, &v6[0]) != 0 {
		v3 := alloc.Calloc1(1, 0x54)
		*(*unsafe.Pointer)(unsafe.Add(v3, 4*19)) = dword_5d4594_588120
		*(*uint32)(unsafe.Add(v3, 4*20)) = 0
		dword_5d4594_588120 = v3
		v4 = (*byte)(alloc.Calloc1(libc.StrLen(&v6[0])+1, 1))
		*(*uint32)(v3) = uint32(uintptr(unsafe.Pointer(v4)))
		libc.StrCpy(v4, &v6[0])
		for nox_xxx_parseString_409470(v2, &v6[0]) != 0 && libc.StrCmp(&v6[0], internCStr("END")) != 0 && nox_xxx_parseString_409470(v2, &v7[0]) != 0 {
			v5 = nox_xxx_utilFindSound_40AF50(&v7[0])
			if sub_4240F0(int32(uintptr(v3)), &v6[0], v5) == 0 {
				return 0
			}
		}
	}
	nox_binfile_close_408D90(v2)
	return 1
}
func nox_xxx_monsterGetSoundSet_424300(a1p *server.Object) unsafe.Pointer {
	var (
		a1 = unsafe.Pointer(a1p)
	)
	if a1 == nil {
		return nil
	}
	if int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 {
		return *(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 488))
	} else {
		return nil
	}
}
func nox_xxx_setNPCVoiceSet_424320(a1 unsafe.Pointer, a2 int32) {
	if a1 != nil {
		if int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 {
			*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 488)) = uint32(a2)
		}
	}
}
func nox_xxx_getDefaultSoundSet_424350(a1 *byte) unsafe.Pointer {
	if a1 == nil {
		return nil
	}
	v1 := dword_5d4594_588120
	if dword_5d4594_588120 == nil {
		return nil
	}
	for libc.StrCmp(*(**byte)(v1), a1) != 0 {
		v1 = *(*unsafe.Pointer)(unsafe.Add(v1, 76))
		if v1 == nil {
			return nil
		}
	}
	return v1
}
func sub_424CB0(a1 unsafe.Pointer) int8 {
	var (
		v1 int8
		v2 int32
		v3 *uint8
	)
	v1 = 0
	v2 = 0
	if dword_587000_66116 <= 0 {
		return 0
	}
	v3 = (*uint8)(memmap.PtrOff(0x587000, 66000))
	for {
		if nox_xxx_testUnitBuffs_4FF350((*server.Object)(a1), server.EnchantID(*(*uint32)(unsafe.Pointer(v3)))) != 0 {
			v1++
		}
		v2++
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
		if v2 >= dword_587000_66116 {
			break
		}
	}
	return v1
}
func sub_424D00() int32 {
	var result int32
	if dword_587000_66116 <= 0 {
		result = -1
	} else {
		result = int32(*memmap.PtrUint32(0x587000, 66000))
	}
	return result
}
func sub_424D20(a1 int32) int32 {
	var (
		v1 int32
		i  *uint8
	)
	v1 = 0
	if dword_587000_66116 <= 0 {
		return -1
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 66000)); *(*int32)(unsafe.Pointer(i)) != a1 || v1 >= dword_587000_66116-1; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 4)) {
		if func() int32 {
			p := &v1
			*p++
			return *p
		}() >= dword_587000_66116 {
			return -1
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*4)+66004))
}
func nox_xxx_abilityNameToN_424D80(a1 *byte) int32 {
	var (
		v1 *byte
		v2 int32
		v3 *uint8
	)
	v1 = *(**byte)(memmap.PtrOff(0x587000, 69736))
	v2 = 0
	if *memmap.PtrUint32(0x587000, 69736) == 0 {
		return 0
	}
	v3 = (*uint8)(memmap.PtrOff(0x587000, 69736))
	for libc.StrCmp(v1, a1) != 0 {
		v1 = (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)))))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
		v2++
		if v1 == nil {
			return 0
		}
	}
	return v2
}
func sub_4254A0(a1 unsafe.Pointer, a2 *uint8) int32 {
	*(*uint32)(a1) = uint32(uintptr(unsafe.Pointer(a2)))
	*(*uint8)(unsafe.Add(a1, 4)) = 0
	return int32(*a2) & 1
}
func sub_4254C0(a1 **uint8) bool {
	var (
		v1 int8
		v2 *uint8
	)
	v1 = int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4))) + 1)
	*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)) = uint8(v1)
	if int32(v1) != 8 {
		return ((1 << int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))) & int32(**a1)) > 0
	}
	v2 = *a1
	*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)) = 0
	*a1 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 1))
	return ((1 << int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))) & int32(**a1)) > 0
}
func sub_425500(a1 unsafe.Pointer, a2 *uint8, a3 int8) *uint8 {
	var result *uint8
	result = a2
	*(*uint32)(a1) = uint32(uintptr(unsafe.Pointer(a2)))
	*(*uint8)(unsafe.Add(a1, 4)) = 0
	*a2 = uint8(a3)
	return result
}
func sub_425520(a1 unsafe.Pointer, a2 int8) int8 {
	var (
		v2     int8
		v3     *uint8
		result int8
	)
	v2 = int8(int32(*(*uint8)(unsafe.Add(a1, 4))) + 1)
	*(*uint8)(unsafe.Add(a1, 4)) = uint8(v2)
	if int32(v2) == 8 {
		v3 = *(**uint8)(a1)
		*(*uint8)(unsafe.Add(a1, 4)) = 0
		*(*uint32)(a1) = uint32(uintptr(unsafe.Pointer(func() *uint8 {
			p := &v3
			*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
			return *p
		}())))
		*v3 = 0
	}
	result = int8(int32(a2) << int32(*(*uint8)(unsafe.Add(a1, 4))))
	**(**uint8)(a1) |= uint8(result)
	return result
}
func sub_425550(a1 *uint8, a2 *uint8, a3 int32) int32 {
	var (
		v3  int32
		v4  int32
		v5  int8
		v6  int32
		v8  [8]byte
		v9  [8]byte
		v10 bool
	)
	v3 = 1
	v4 = 0
	v5 = int8(sub_4254A0(unsafe.Pointer(&v9[0]), a1))
	sub_425500(unsafe.Pointer(&v8[0]), a2, v5)
	if a3 == 1 {
		return 1
	}
	v6 = a3 - 1
	for {
		if (func() int32 {
			p := &v4
			*p++
			return *p
		}() % 7) == 0 {
			sub_425520(unsafe.Pointer(&v8[0]), 1)
			v3++
		}
		v10 = sub_4254C0((**uint8)(unsafe.Pointer(&v9[0])))
		sub_425520(unsafe.Pointer(&v8[0]), int8(bool2int32(v10)))
		v6--
		if v6 == 0 {
			break
		}
	}
	return v3
}
func nox_common_list_clear_425760(list *nox_list_item_t) {
	list.field_0 = list
	list.field_1 = list
	list.field_2 = list
}
func sub_425770(a1p unsafe.Pointer) unsafe.Pointer {
	var (
		a1     *uint32 = (*uint32)(a1p)
		result *uint32
	)
	result = a1
	*a1 = uint32(uintptr(unsafe.Pointer(a1)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) = uint32(uintptr(unsafe.Pointer(a1)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) = 0
	return unsafe.Pointer(result)
}
func sub_425790(a1 *int32, a2 *uint32) int32 {
	var (
		v2 int32
		v3 int32
		v4 *int32
	)
	v2 = 0
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*2)))
	v4 = (*int32)(unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Pointer(a1)))))
	if v4 == nil {
		nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(a1)), (*nox_list_item_t)(unsafe.Pointer(a2)))
		return v2
	}
	for v3 > *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) {
		v2++
		v4 = (*int32)(unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Pointer(v4)))))
		if v4 == nil {
			nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(a1)), (*nox_list_item_t)(unsafe.Pointer(a2)))
			return v2
		}
	}
	nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(v4)), (*nox_list_item_t)(unsafe.Pointer(a2)))
	return v2
}
func sub_4257F0(a1 *int32, a2 *uint32) {
	var (
		v2 int32
		v3 *int32
	)
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*2)))
	v3 = (*int32)(unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Pointer(a1)))))
	if v3 == nil {
		nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(a1)), (*nox_list_item_t)(unsafe.Pointer(a2)))
		return
	}
	for *(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*2)) > v2 {
		v3 = (*int32)(unsafe.Pointer(nox_common_list_getNext_425940((*nox_list_item_t)(unsafe.Pointer(v3)))))
		if v3 == nil {
			nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(a1)), (*nox_list_item_t)(unsafe.Pointer(a2)))
			return
		}
	}
	nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(v3)), (*nox_list_item_t)(unsafe.Pointer(a2)))
}
func nox_common_list_getFirstSafe_425890(list *nox_list_item_t) *nox_list_item_t {
	return nox_common_list_getNextSafe_4258A0(list)
}
func nox_common_list_getNextSafe_4258A0(list *nox_list_item_t) *nox_list_item_t {
	if list == nil {
		return nil
	}
	return nox_common_list_getNext_425940(list)
}
func sub_4258C0(a1 **uint32, a2 int32) *uint32 {
	var (
		result *uint32
		v3     int32
		v4     int32
	)
	result = *a1
	if unsafe.Pointer(*a1) == unsafe.Pointer(a1) {
		return nil
	}
	v3 = a2
	for {
		v4 = func() int32 {
			p := &v3
			x := *p
			*p--
			return x
		}()
		if v4 == 0 {
			break
		}
		result = (*uint32)(unsafe.Pointer(uintptr(*result)))
		if unsafe.Pointer(result) == unsafe.Pointer(a1) {
			return nil
		}
	}
	return result
}
func nox_common_list_append_4258E0(list *nox_list_item_t, cur *nox_list_item_t) {
	if list == nil || cur == nil {
		panic("abort")
	}
	var it *nox_list_item_t = list.field_1
	cur.field_0 = list
	cur.field_1 = it
	list.field_1 = cur
	if it != nil {
		it.field_0 = cur
	}
}
func sub_425900(a1 *uint32, a2 *uint32) *uint32 {
	var result *uint32
	result = a2
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*1)) = uint32(uintptr(unsafe.Pointer(a1)))
	*a2 = *a1
	*a1 = uint32(uintptr(unsafe.Pointer(a2)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*a2)), 4)) = uint32(uintptr(unsafe.Pointer(a2)))
	return result
}
func nox_common_list_remove_425920(a1p unsafe.Pointer) {
	var a1 **uint32 = (**uint32)(a1p)
	**(**uint32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((*uint32)(nil))*1)) = uint32(uintptr(unsafe.Pointer(*a1)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(*a1), 4*1)) = uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((*uint32)(nil))*1)))))
	*a1 = (*uint32)(unsafe.Pointer(a1))
	*(**uint32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof((*uint32)(nil))*1)) = (*uint32)(unsafe.Pointer(a1))
}
func nox_common_list_getNext_425940(list *nox_list_item_t) *nox_list_item_t {
	var it *nox_list_item_t = list.field_0
	if it != nil && it == it.field_2 {
		return nil
	}
	return it
}
func sub_425960(a1 unsafe.Pointer) unsafe.Pointer {
	if *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 4)), 8)) != *(*uint32)(unsafe.Add(a1, 4)) {
		return *(*unsafe.Pointer)(unsafe.Add(a1, 4))
	}
	return nil
}
func sub_4259C0() {
	if *memmap.PtrUint32(0x5D4594, 599472) == 0 {
		nox_common_list_clear_425760((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 599460)))
		*memmap.PtrUint32(0x5D4594, 599472) = 1
	}
}
func sub_4259F0() {
	result := sub_425A50()
	v1 := result
	if result != nil {
		for {
			v2 := sub_425A60(v1)
			v3 := sub_425BC0(v1)
			if v3 != nil {
				for {
					v4 := sub_425BE0(v3)
					nox_common_list_remove_425920(v3)
					alloc.FreePtr(v3)
					v3 = v4
					if v4 == nil {
						break
					}
				}
			}
			nox_common_list_remove_425920(v1)
			alloc.FreePtr(v1)
			v1 = v2
			if v2 == nil {
				break
			}
		}
	}
}
func sub_425A50() unsafe.Pointer {
	return unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(memmap.PtrInt32(0x5D4594, 599460)))))
}
func sub_425A60(a1 unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(a1)))
}
func sub_425A70(a1 int32) unsafe.Pointer {
	result := sub_425A50()
	if result == nil {
		return nil
	}
	for *(*int32)(unsafe.Add(result, 4*8)) != a1 {
		result = sub_425A60(result)
		if result == nil {
			return nil
		}
	}
	return result
}
func sub_425AA0(a1 int32) int32 {
	v1 := sub_425A50()
	if v1 == nil {
		return 0
	}
	for *(*int32)(unsafe.Add(v1, 4*8)) != a1 {
		v1 = sub_425A60(v1)
		if v1 == nil {
			return 0
		}
	}
	return 1
}
func sub_425AD0(a1 int32, a2 *wchar2_t) *wchar2_t {
	var v2 *wchar2_t
	v2 = nil
	if sub_425AA0(a1) != 0 {
		return v2
	}
	v2 = (*wchar2_t)(alloc.Calloc1(1, 0x34))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*8)) = uint32(a1)
	nox_wcscpy((*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(wchar2_t(0))*6)), a2)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*9)) = 0
	sub_425770(unsafe.Pointer(v2))
	nox_common_list_clear_425760((*nox_list_item_t)(unsafe.Add(unsafe.Pointer(v2), 4*10)))
	nox_common_list_append_4258E0((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 599460)), (*nox_list_item_t)(unsafe.Pointer(v2)))
	return v2
}
func sub_425B30(a1 unsafe.Pointer, a2 int32) {
	var (
		v2 *uint32
		v3 *uint32
	)
	v2 = (*uint32)(alloc.Calloc1(1, 0x10))
	v3 = v2
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) = uint32(a2)
	sub_425770(unsafe.Pointer(v2))
	nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Add(a1, 40)), (*nox_list_item_t)(unsafe.Pointer(v3)))
}
func sub_425B60(lpMem unsafe.Pointer, a2 int32) {
	v2 := sub_425BC0(lpMem)
	if v2 != nil {
		for *(*int32)(unsafe.Add(v2, 4*3)) != a2 {
			v2 = sub_425BE0(v2)
			if v2 == nil {
				goto LABEL_6
			}
		}
		nox_common_list_remove_425920(v2)
		alloc.FreePtr(v2)
	}
LABEL_6:
	if *(*unsafe.Pointer)(unsafe.Add(lpMem, unsafe.Sizeof(unsafe.Pointer(nil))*11)) == unsafe.Add(lpMem, 40) {
		nox_common_list_remove_425920(lpMem)
		alloc.FreePtr(lpMem)
	}
}
func sub_425BC0(a1 unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Add(a1, 40))))
}
func sub_425BE0(a1 unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(a1)))
}
func nox_xxx_countObserverPlayers_425BF0() int32 {
	var (
		v0 int32
		v2 int32
	)
	v0 = 0
	if !(noxflags.HasGame(0x8000)) {
		return v0
	}
	for i := nox_common_playerInfoGetFirst_416EA0(); i != nil; i = nox_common_playerInfoGetNext_416EE0(i) {
		v2 = int32(i.Field3680)
		if v2&1 != 0 && (v2&0x20) == 0 && i.PlayerInd != 31 {
			v0++
		}
	}
	return v0
}
func sub_425CA0(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	var (
		result *byte
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
	)
	result = (*byte)(unsafe.Pointer(uintptr(bool2int32(noxflags.HasGame(0x2000)))))
	if result != nil {
		result = (*byte)(unsafe.Pointer(uintptr(bool2int32(noxflags.HasGame(4096)))))
		if result == nil {
			if a1 != nil {
				v3 := a2
				if *(*int32)(unsafe.Add(a1, 4648)) == -1 {
					v4 = int32(func() uint32 {
						p := &dword_5d4594_608316
						x := *p
						*p++
						return x
					}())
					v13 = v4
					v5 = v4 * 32
					libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, uintptr(v5)+600124)), (*byte)(unsafe.Add(a1, 2096)))
					if int32(*(*uint8)(unsafe.Add(v3, 2064))) == 31 {
						v6 = int32(nox_xxx_net_getIP_554200(0))
					} else {
						v6 = int32(nox_xxx_net_getIP_554200(int32(*(*uint8)(unsafe.Add(a1, 2064))) + 1))
					}
					*memmap.PtrUint32(0x5D4594, uintptr(v5)+600136) = cnet.Htonl(uint32(v6))
					*memmap.PtrUint32(0x5D4594, uintptr(v5)+600140) = *(*uint32)(unsafe.Add(a1, 2068))
					*memmap.PtrUint8(0x5D4594, uintptr(v5)+600144) = *(*uint8)(unsafe.Add(a1, 2251))
					*(*uint32)(unsafe.Add(a1, 4648)) = uint32(v13)
				} else {
					v13 = int32(*(*uint32)(unsafe.Add(a1, 4648)))
				}
				if v3 != nil {
					if *(*int32)(unsafe.Add(v3, 4648)) == -1 {
						v12 = int32(func() uint32 {
							p := &dword_5d4594_608316
							x := *p
							*p++
							return x
						}())
						libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, uintptr(v13*32)+600124)), (*byte)(unsafe.Add(v3, 2096)))
						if int32(*(*uint8)(unsafe.Add(v3, 2064))) == 31 {
							v7 = int32(nox_xxx_net_getIP_554200(0))
							v8 = v12
							*memmap.PtrUint32(0x5D4594, uintptr(v13*32)+600136) = cnet.Htonl(uint32(v7))
						} else {
							v9 = int32(nox_xxx_net_getIP_554200(int32(*(*uint8)(unsafe.Add(v3, 2064))) + 1))
							v8 = v12
							*memmap.PtrUint32(0x5D4594, uintptr(v12*32)+600136) = cnet.Htonl(uint32(v9))
						}
						v10 = v8 * 32
						*memmap.PtrUint32(0x5D4594, uintptr(v10)+600140) = *(*uint32)(unsafe.Add(v3, 2068))
						*memmap.PtrUint8(0x5D4594, uintptr(v10)+600144) = *(*uint8)(unsafe.Add(v3, 2251))
						*(*uint32)(unsafe.Add(v3, 4648)) = uint32(v8)
					} else {
						v12 = int32(*(*uint32)(unsafe.Add(v3, 4648)))
					}
				} else {
					*(*uint8)(unsafe.Pointer(&v12)) = math.MaxUint8
				}
				v11 = int32(dword_5d4594_739392)
				*memmap.PtrUint8(0x5D4594, uintptr(dword_5d4594_739392)*2+608320) = uint8(int8(v13))
				*memmap.PtrUint8(0x5D4594, uintptr(v11*2)+608321) = uint8(int8(v12))
				dword_5d4594_739392 = uint32(v11 + 1)
				if dword_5d4594_608316 >= math.MaxUint8 {
					nox_xxx_net_4263C0()
				}
			}
		}
	}
}
func sub_425E90(a1 unsafe.Pointer, a2 int8) int32 {
	var result int32
	result = bool2int32(noxflags.HasGame(0x2000))
	if result == 0 {
		return result
	}
	result = bool2int32(noxflags.HasGame(4096))
	if result != 0 {
		return result
	}
	result = int32(*(*uint32)(unsafe.Add(a1, 4648)))
	if result != -1 {
		result *= 32
		*memmap.PtrUint8(0x5D4594, uintptr(result)+600145) = uint8(a2)
	}
	return result
}
func sub_425ED0(a1 unsafe.Pointer, a2 int8) {
	if noxflags.HasGame(0x2000) {
		if !noxflags.HasGame(4096) {
			result := int32(*(*uint32)(unsafe.Add(a1, 4648)))
			if result != -1 {
				result *= 32
				*memmap.PtrUint8(0x5D4594, uintptr(result)+600152) = uint8(a2)
			}
		}
	}
}
func sub_425F10(pl *server.Player) {
	var (
		a1     = unsafe.Pointer(pl)
		result int32
		v3     int32
		v4     int32
		v5     *uint8
		v6     int32
		v7     bool
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
	)
	result = bool2int32(noxflags.HasGame(0x2000))
	if result != 0 {
		result = bool2int32(noxflags.HasGame(4096))
		if result == 0 {
			v2 := a1
			if a1 != nil {
				result = int32(*(*uint32)(unsafe.Add(a1, 4648)))
				v3 = -1
				if result == -1 {
					v4 = int32(func() uint32 {
						p := &dword_5d4594_608316
						x := *p
						*p++
						return x
					}())
					v12 = v4
					v5 = (*uint8)(unsafe.Add(v2, 2096))
					v6 = v4 * 32
					for {
						if v3 == 0 {
							break
						}
						v7 = int32(*func() *uint8 {
							p := &v5
							x := *p
							*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
							return x
						}()) == 0
						v3--
						if v7 {
							break
						}
					}
					alloc.Memcpy(memmap.PtrOff(0x5D4594, uintptr(v6)+600124), unsafe.Add(unsafe.Pointer(v5), v3+1), uintptr(^v3))
					if int32(*(*uint8)(unsafe.Add(v2, 2064))) == 31 {
						v8 = int32(nox_xxx_net_getIP_554200(0))
						*memmap.PtrUint32(0x5D4594, uintptr(v6)+600136) = cnet.Htonl(uint32(v8))
						if nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
							*memmap.PtrUint8(0x5D4594, uintptr(v6)+600152) = 0
							goto LABEL_18
						}
						v9 = int32(*(*uint32)(unsafe.Add(v2, 3680)))
						if v9&1 != 0 && (v9&0x20) == 0 {
							*memmap.PtrUint8(0x5D4594, uintptr(v6)+600152) = 0
							goto LABEL_18
						}
					} else {
						v10 = int32(nox_xxx_net_getIP_554200(int32(*(*uint8)(unsafe.Add(v2, 2064))) + 1))
						*memmap.PtrUint32(0x5D4594, uintptr(v6)+600136) = cnet.Htonl(uint32(v10))
						v11 = int32(*(*uint32)(unsafe.Add(v2, 3680)))
						if v11&1 != 0 && (v11&0x20) == 0 {
							*memmap.PtrUint8(0x5D4594, uintptr(v6)+600152) = 0
							goto LABEL_18
						}
					}
					*memmap.PtrUint8(0x5D4594, uintptr(v6)+600152) = 1
				LABEL_18:
					*memmap.PtrUint32(0x5D4594, uintptr(v6)+600140) = *(*uint32)(unsafe.Add(v2, 2068))
					*memmap.PtrUint8(0x5D4594, uintptr(v6)+600144) = *(*uint8)(unsafe.Add(v2, 2251))
					*memmap.PtrUint32(0x5D4594, uintptr(v6)+600148) = uint32(libc.GetTime(nil))
					result = v12
					*memmap.PtrUint8(0x5D4594, uintptr(v6)+600145) = 1
					*(*uint32)(unsafe.Add(v2, 4648)) = uint32(v12)
				}
			}
		}
	}
}
func sub_426150() {
	var (
		v1 *byte
		v2 *byte
		v3 int16
	)
	if !noxflags.HasGame(0x2000) {
		return
	}
	if noxflags.HasGame(4096) {
		return
	}
	v1 = (*byte)(sub_416640())
	v2 = nox_xxx_cliGamedataGet_416590(0)
	*memmap.PtrUint16(0x5D4594, 599482) = uint16(*(*byte)(unsafe.Add(unsafe.Pointer(v1), 103)))
	*memmap.PtrUint32(0x5D4594, 599484) = uint32(*(*byte)(unsafe.Add(unsafe.Pointer(v1), 104)))
	*memmap.PtrUint32(0x5D4594, 599488) = *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*10))
	*memmap.PtrUint32(0x5D4594, 599492) = uint32(sub_4200E0())
	*memmap.PtrUint8(0x5D4594, 599502) = uint8(int8(bool2int32((*(*byte)(unsafe.Add(unsafe.Pointer(v2), 53)) & 0xC0) != 0)))
	v3 = int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*26)))
	if int32(v3)&0x100 != 0 {
		dword_5d4594_599496 = 0
	} else if int32(v3)&0x20 != 0 {
		dword_5d4594_599496 = 1
	} else if int32(v3)&0x40 != 0 {
		dword_5d4594_599496 = 2
	} else if int32(v3)&0x10 != 0 {
		dword_5d4594_599496 = 3
	} else if int32(v3)&0x400 != 0 {
		dword_5d4594_599496 = 4
	}
	*memmap.PtrUint8(0x5D4594, 599500) = uint8(int8(bool2int32((*(*byte)(unsafe.Add(unsafe.Pointer(v2), 53)) & 0x40) == 0)))
	*memmap.PtrUint32(0x5D4594, 599508) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*27)))
	*memmap.PtrUint32(0x5D4594, 599512) = uint32(*(*byte)(unsafe.Add(unsafe.Pointer(v2), 56)))
	*memmap.PtrUint8(0x5D4594, 599516) = *(*byte)(unsafe.Add(unsafe.Pointer(v1), 100))
	*memmap.PtrUint32(0x5D4594, 599520) = uint32(*(*byte)(unsafe.Add(unsafe.Pointer(v1), 101)) & 0xF)
	*memmap.PtrUint32(0x5D4594, 599524) = uint32(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v1), 101))) >> 4)
	*memmap.PtrUint32(0x5D4594, 599528) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), 105)))
	*memmap.PtrUint32(0x5D4594, 599532) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), 107)))
	*memmap.PtrUint8(0x5D4594, 599536) = *(*byte)(unsafe.Add(unsafe.Pointer(v1), 102))
	*memmap.PtrUint8(0x5D4594, 599537) = *(*byte)(unsafe.Add(unsafe.Pointer(v1), 100)) & 0x30
	*memmap.PtrUint8(0x5D4594, 599501) = uint8(sub_417DE0())
	libc.StrNCpy((*byte)(memmap.PtrOff(0x5D4594, 599828)), (*byte)(unsafe.Add(unsafe.Pointer(v2), 9)), 0xF)
	*memmap.PtrUint8(0x5D4594, 599843) = 0
	alloc.Memcpy(memmap.PtrOff(0x5D4594, 599540), unsafe.Add(unsafe.Pointer(v2), 24), 0x64)
	*memmap.PtrUint32(0x5D4594, 599564) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*12))
	*memmap.PtrUint32(0x5D4594, 599560) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*11))
	libc.StrNCpy((*byte)(memmap.PtrOff(0x5D4594, 599572)), v2, 8)
	*memmap.PtrUint8(0x5D4594, 599580) = 0
	*memmap.PtrUint32(0x5D4594, 600112) = 0
	*memmap.PtrUint32(0x5D4594, 600084) = 0
	*memmap.PtrUint32(0x5D4594, 600088) = 0
	*memmap.PtrUint32(0x5D4594, 600092) = 0
	*memmap.PtrUint32(0x5D4594, 600096) = 0
}
func nox_xxx_net_4263C0() {
	if noxflags.HasGame(0x2000) {
		if !noxflags.HasGame(4096) {
			sub_4282F0(memmap.PtrOff(0x5D4594, 599476), memmap.PtrOff(0x5D4594, 600124), dword_5d4594_608316)
			sub_428540(memmap.PtrOff(0x5D4594, 599476), memmap.PtrOff(0x5D4594, 608320), int32(dword_5d4594_739392))
			*memmap.PtrUint32(0x5D4594, 599504) = uint32(libc.GetTime(nil) - dword_5d4594_600116)
			sub_428810(memmap.PtrOff(0x5D4594, 599476), 1)
			libc.MemSet(memmap.PtrOff(0x5D4594, 600124), 0, 0x2000)
			libc.MemSet(memmap.PtrOff(0x5D4594, 608320), 0, 0x20000)
			dword_5d4594_608316 = 0
			dword_5d4594_739392 = 0
			for i := nox_common_playerInfoGetFirst_416EA0(); i != nil; i = nox_common_playerInfoGetNext_416EE0(i) {
				i.Field4648 = -1
			}
			v2 := nox_common_playerInfoFromNum_417090(31)
			if v2 != nil {
				sub_425F10(v2)
			}
			r3 := nox_common_playerInfoGetFirst_416EA0()
			for j := unsafe.Pointer(r3); r3 != nil; j = unsafe.Pointer(r3) {
				if int32(*(*uint8)(unsafe.Add(j, 2064))) != 31 {
					sub_425F10((*server.Player)(j))
				}
				r3 = nox_common_playerInfoGetNext_416EE0((*server.Player)(j))
			}
		}
	}
}
func sub_4264D0() int32 {
	if !noxflags.HasGame(0x2000) || noxflags.HasGame(4096) {
		if noxflags.HasGame(4096) {
			*memmap.PtrUint32(0x5D4594, 739416) = uint32(libc.GetTime(nil) - dword_5d4594_600116)
		}
	} else {
		for i := nox_common_playerInfoGetFirst_416EA0(); i != nil; i = nox_common_playerInfoGetNext_416EE0(i) {
			sub_425E90(unsafe.Pointer(i), 1)
		}
		*memmap.PtrUint32(0x5D4594, 599504) = uint32(libc.GetTime(nil) - dword_5d4594_600116)
	}
	if !noxflags.HasGame(4096) {
		return sub_428810(memmap.PtrOff(0x5D4594, 599476), 2)
	}
	sub_4285C0(memmap.PtrInt16(0x5D4594, 739396))
	return sub_428890(unsafe.Pointer(memmap.PtrInt16(0x5D4594, 739396)))
}
func nox_xxx_wallGet_426A30() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 739992))
}
func nox_xxx_mapGetWallSize_426A70() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 739980))
}
func nox_xxx_mapWall_426A80(a1 *int32) {
	*memmap.PtrUint32(0x5D4594, 739980) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*0)))
	*memmap.PtrUint32(0x5D4594, 739984) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
}
func nox_xxx_guide_427010(a1 *byte) int32 {
	var (
		v1 int32
		v2 **byte
	)
	v1 = 0
	v2 = (**byte)(memmap.PtrOff(0x587000, 70500))
	for libc.StrCmp(*v2, a1) != 0 {
		v2 = (**byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((*byte)(nil))*1))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 70664))) {
			return 0
		}
	}
	return v1
}
func nox_xxx_guideNameByN_427230(a1 int32) *byte {
	return *(**byte)(memmap.PtrOff(0x587000, uintptr(a1*4)+70500))
}
func nox_xxx_guiCreatureGetName_427240(a1 int32) *wchar2_t {
	if a1 <= 0 || a1 >= 41 {
		return nil
	}
	if memmap.Uint32(0x5D4594, uintptr(a1*28)+740080) == 0 {
		return nil
	}
	return (*wchar2_t)(*memmap.PtrPtr(0x5D4594, uintptr(a1*28)+740076))
}
func nox_xxx_creatureIsCharmableByTT_4272B0(a1 int32) int32 {
	var (
		result int32
		v2     *uint8
	)
	result = 1
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 740108))
	for *(*uint32)(unsafe.Pointer(v2)) == 0 || *(*uint32)(unsafe.Pointer(v2)) != uint32(a1) {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 28))
		result++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 741228))) {
			return 0
		}
	}
	return result
}
func nox_xxx_guideGetDescById_4272E0(a1 int32) int32 {
	return int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*28)+740084))
}
func nox_xxx_bookGetFirstCreMB_427300() int32 {
	var (
		result int32
		v1     *uint8
	)
	result = 1
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 740108))
	for *(*uint32)(unsafe.Pointer(v1)) == 0 {
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 28))
		result++
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 741228))) {
			return 0
		}
	}
	return result
}
func nox_xxx_bookGetNextCre_427320(a1 int32) int32 {
	var (
		result int32
		v2     *uint8
	)
	result = a1 + 1
	if a1+1 >= 41 {
		return 0
	}
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(result*28)+740080))
	for *(*uint32)(unsafe.Pointer(v2)) == 0 {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 28))
		result++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 741228))) {
			return 0
		}
	}
	return result
}
func nox_xxx_bookGetCreatureImg_427400(a1 int32) int32 {
	var result int32
	if a1 <= 0 || a1 >= 41 {
		result = 0
	} else {
		result = int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*28)+740092))
	}
	return result
}
func sub_427430(a1 int32) noxrender.ImageHandle {
	if a1 <= 0 || a1 >= 41 {
		return nil
	} else {
		return *memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, uintptr(a1*28)+740088)
	}
}
func nox_xxx_guideGetUnitSize_427460(a1 int32) uint8 {
	return *memmap.PtrUint8(0x5D4594, uintptr(a1*28)+740100)
}
func nox_xxx_journalEntryAdd_427490(a1p *server.Player, a2 *byte, a3 int16) *nox_playerInfo_journal {
	var (
		a1     = unsafe.Pointer(a1p)
		result *uint8
		v4     *uint8
	)
	result = (*uint8)(alloc.Calloc1(1, 0x4C))
	v4 = result
	if result == nil {
		return (*nox_playerInfo_journal)(unsafe.Pointer(result))
	}
	libc.MemSet(unsafe.Pointer(result), 0, 0x4C)
	libc.StrNCpy(result, a2, 0x3F)
	*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 63)) = 0
	*(*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*36)) = uint16(a3)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*17)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*16)) = *(*uint32)(unsafe.Add(a1, 3644))
	v5 := *(*unsafe.Pointer)(unsafe.Add(a1, 3644))
	if v5 != nil {
		*(*uint32)(unsafe.Add(v5, 68)) = uint32(uintptr(unsafe.Pointer(v4)))
	}
	*(*uint32)(unsafe.Add(a1, 3644)) = uint32(uintptr(unsafe.Pointer(v4)))
	result = v4
	return (*nox_playerInfo_journal)(unsafe.Pointer(result))
}
func nox_xxx_comJournalEntryAdd_427500(a1p *server.Object, a2 *byte, a3 int16) {
	var (
		a1 = unsafe.Pointer(a1p)
		v4 *uint8
	)
	v3 := *(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 276))
	v4 = (*uint8)(unsafe.Pointer(nox_xxx_journalEntryAdd_427490((*server.Player)(v3), a2, a3)))
	if v4 != nil {
		if int32(*(*uint8)(unsafe.Add(v3, 2064))) == 31 {
			nox_xxx_cliBuildJournalString_469BC0()
		} else {
			nox_xxx_netSendJournalAdd_4D9440(int32(*(*uint8)(unsafe.Add(v3, 2064))), (*nox_playerInfo_journal)(unsafe.Pointer(v4)))
		}
	}
}
func nox_xxx_journalEntryRemove_427590(a1p *server.Player, a2 *byte) int32 {
	a1 := unsafe.Pointer(a1p)
	v2 := *(*unsafe.Pointer)(unsafe.Add(a1, 3644))
	if v2 == nil {
		return 0
	}
	for libc.StrCmp((*byte)(v2), a2) != 0 {
		v2 = *(*unsafe.Pointer)(unsafe.Add(v2, 64))
		if v2 == nil {
			return 0
		}
	}
	v4 := *(*unsafe.Pointer)(unsafe.Add(v2, 68))
	if v4 != nil {
		*(*uint32)(unsafe.Add(v4, 64)) = *(*uint32)(unsafe.Add(v2, 64))
	}
	v5 := *(*unsafe.Pointer)(unsafe.Add(v2, 64))
	if v5 != nil {
		*(*uint32)(unsafe.Add(v5, 68)) = *(*uint32)(unsafe.Add(v2, 68))
	}
	if v2 == *(*unsafe.Pointer)(unsafe.Add(a1, 3644)) {
		*(*uint32)(unsafe.Add(a1, 3644)) = *(*uint32)(unsafe.Add(v2, 64))
	}
	alloc.FreePtr(v2)
	return 1
}
func nox_xxx_comJournalEntryRemove_427630(a1 unsafe.Pointer, a2 *byte) {
	v2 := *(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 276))
	if nox_xxx_journalEntryRemove_427590((*server.Player)(v2), a2) != 0 {
		if int32(*(*uint8)(unsafe.Add(v2, 2064))) == 31 {
			nox_xxx_cliBuildJournalString_469BC0()
		} else {
			nox_xxx_netSendJournalRemove_4D94A0(int32(*(*uint8)(unsafe.Add(v2, 2064))), a2)
		}
	}
}
func nox_xxx_comRemoveEntryAll_427680(a1 *byte) {
	result := nox_xxx_getFirstPlayerUnit_4DA7C0()
	for i := result; result != nil; i = result {
		nox_xxx_comJournalEntryRemove_427630(unsafe.Pointer(i), a1)
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i)
	}
}
func nox_xxx_journalUpdateEntry_4276B0(a1p *server.Player, a2 *byte, a3 int16) unsafe.Pointer {
	a1 := unsafe.Pointer(a1p)
	v3 := *(*unsafe.Pointer)(unsafe.Add(a1, 3644))
	if v3 == nil {
		return nil
	}
	for libc.StrCmp((*byte)(v3), a2) != 0 {
		v3 = *(*unsafe.Pointer)(unsafe.Add(v3, 64))
		if v3 == nil {
			return nil
		}
	}
	*(*uint16)(unsafe.Add(v3, 72)) = uint16(a3)
	return v3
}
func nox_xxx_comJournalEntryUpdate_427720(a1 unsafe.Pointer, a2 *byte, a3 int16) {
	v3 := *(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 276))
	result := nox_xxx_journalUpdateEntry_4276B0((*server.Player)(v3), a2, a3)
	if result != nil {
		if int32(*(*uint8)(unsafe.Add(v3, 2064))) != 31 {
			nox_xxx_netSendJournalUpdate_4D9500(int32(*(*uint8)(unsafe.Add(v3, 2064))), result)
		}
	}
}
func nox_xxx_comUpdateEntryAll_427770(a1 *byte, a2 int16) {
	result := nox_xxx_getFirstPlayerUnit_4DA7C0()
	for i := result; result != nil; i = result {
		nox_xxx_comJournalEntryUpdate_427720(unsafe.Pointer(i), a1, a2)
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i)
	}
}
func sub_4277B0(a1p *server.Object, a2 uint16) {
	a1 := unsafe.Pointer(a1p)
	v2 := *(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 276))
	result := *(*unsafe.Pointer)(unsafe.Add(v2, 3644))
	if result != nil {
		for {
			v4 := *(*unsafe.Pointer)(unsafe.Add(result, 64))
			if int32(a2)&int32(*(*uint16)(unsafe.Add(result, 72))) != 0 {
				v5 := *(*unsafe.Pointer)(unsafe.Add(result, 68))
				if v5 != nil {
					*(*uint32)(unsafe.Add(v5, 64)) = *(*uint32)(unsafe.Add(result, 64))
				}
				v6 := *(*unsafe.Pointer)(unsafe.Add(result, 64))
				if v6 != nil {
					*(*uint32)(unsafe.Add(v6, 68)) = *(*uint32)(unsafe.Add(result, 68))
				}
				if result == *(*unsafe.Pointer)(unsafe.Add(v2, 3644)) {
					*(*uint32)(unsafe.Add(v2, 3644)) = *(*uint32)(unsafe.Add(result, 64))
				}
				alloc.FreePtr(result)
			}
			result = v4
			if v4 == nil {
				break
			}
		}
	}
}
func sub_427C80(a1 *int4, a2 *int4) int32 {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 int32
		v23 int32
	)
	v2 = a1.field_0
	v3 = a1.field_4
	v4 = a1.field_8
	v19 = a1.field_C
	v5 = a2.field_0
	v21 = a2.field_4
	v17 = a2.field_C
	v6 = a2.field_8
	v7 = v4 - v2
	v8 = a2.field_0 - v6
	v20 = a2.field_0
	if v4-v2 >= 0 {
		v6 = a2.field_8
		v22 = v2
	} else {
		v22 = v4
		v4 = v2
	}
	if v8 <= 0 {
		if v4 < v5 || v6 < v22 {
			return 0
		}
	} else if v4 < v6 || v5 < v22 {
		return 0
	}
	v10 = v19
	v11 = v21 - v17
	v18 = v19 - v3
	if v19-v3 >= 0 {
		v23 = v3
	} else {
		v23 = v19
		v10 = v3
	}
	if v11 <= 0 {
		if v10 < v21 || v17 < v23 {
			return 0
		}
	} else {
		if v10 < v17 {
			return 0
		}
		if v21 < v23 {
			return 0
		}
	}
	v12 = v2 - v20
	v13 = v3 - v21
	v14 = v11*(v2-v20) - v8*(v3-v21)
	v15 = v8*v18 - v7*v11
	if v15 <= 0 {
		if v14 > 0 || v14 < v15 {
			return 0
		}
	} else {
		if v14 < 0 {
			return 0
		}
		if v14 > v15 {
			return 0
		}
	}
	v16 = v7*v13 - v18*v12
	if v15 <= 0 {
		if v16 <= 0 && v16 >= v15 {
			return 1
		}
		return 0
	}
	if v16 < 0 {
		return 0
	}
	if v16 > v15 {
		return 0
	}
	return 1
}
func sub_427DF0(a1 unsafe.Pointer, a2 unsafe.Pointer, a3 float32) int32 {
	var (
		v3  float64
		v4  float64
		v6  float64
		v7  float32
		v8  float32
		v9  float32
		v10 float32
		v11 float32
		v12 float32
		v13 float32
		v14 float32
		v15 float32
		v16 float32
		v17 float32
		v18 float32
	)
	v16 = float32(float64(*(*int32)(a2)))
	v17 = float32(float64(*(*int32)(unsafe.Add(a2, 4*1))))
	v8 = float32(float64(*(*int32)(unsafe.Add(a2, 4*2))) - float64(v16))
	v3 = float64(*(*int32)(unsafe.Add(a2, 4*3))) - float64(v17)
	v11 = float32(v3)
	v7 = float32(math.Sqrt(v3*float64(v11) + float64(v8*v8)))
	v14 = v8 / v7
	v4 = float64(v11 / v7)
	v15 = float32(v4)
	v9 = float32(float64(*(*int32)(a1)) - float64(v16))
	v12 = float32(float64(*(*int32)(unsafe.Add(a1, 4))) - float64(v17))
	if float32(math.Abs(float64(v9)*(-v4)+float64(v12*v14))) > a3 {
		return 0
	}
	v6 = float64(v12*v15 + v9*v14)
	v18 = float32(v6)
	if v6 > float64(v7) {
		return 0
	}
	if float64(v18) < 0.0 {
		return 0
	}
	v10 = v18*v14 + v16
	v13 = v18*v15 + v17
	*(*uint32)(a1) = uint32(int32(v10))
	*(*uint32)(unsafe.Add(a1, 4)) = uint32(int32(v13))
	return 1
}
