package legacy

import (
	"math"
	"unicode"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_server_gameSettingsUpdated int32
var nox_tile_def_cnt uint32
var nox_tile_defs_arr [176]nox_tileDef_t

type nox_tileDef_t struct {
	name     [32]byte
	data_32  *noxrender.ImageHandle
	field_36 int32
	field_40 int32
	field_44 uint16
	field_46 uint16
	color_48 uint32
	field_52 uint8
	field_53 uint8
	field_54 uint8
	field_55 uint8
	field_56 uint8
	field_57 uint8
	field_58 uint8
	field_59 uint8
}

func nox_xxx_parseString_409470(a1 *FILE, a2 *uint8) int32 {
	var (
		v2       *uint8
		v3       int32
		v4       int32
		v5       int32
		v6       int32
		CharType [2]uint16
	)
	v2 = a2
	v3 = 0
	*(*uint32)(unsafe.Pointer(&CharType[0])) = 0
	v4 = 1
	for {
		for {
			v5 = v3
			nox_binfile_fread_408E40((*byte)(unsafe.Pointer(&CharType[0])), 1, 1, a1)
			if nox_binfile_lastErr_409370(a1) == -1 {
				return 0
			}
			v3 = int32(*(*uint32)(unsafe.Pointer(&CharType[0])))
			v6 = bool2int32(unicode.IsSpace(rune(CharType[0])))
			if v6 != 0 {
				break
			}
			v4 = 0
			if v3 != '/' || v5 != '/' {
				*func() *uint8 {
					p := &v2
					x := *p
					*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
					return x
				}() = uint8(int8(v3))
			} else {
				nox_binfile_skipLine_409520(a1)
				v2 = a2
				v3 = int32(*(*uint32)(unsafe.Pointer(&CharType[0])))
				v4 = 1
			}
		}
		if v4 == 0 {
			break
		}
	}
	*v2 = 0
	return 1
}
func sub_409A70(a1 int16) int32 {
	var (
		result int32
		v2     *uint8
	)
	result = 0
	v2 = (*uint8)(memmap.PtrOff(0x587000, 4704))
	for *(*uint32)(unsafe.Pointer(v2)) != uint32(int32(a1)&0x17F0) {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 4))
		result++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 4728))) {
			return 0
		}
	}
	return result
}
func nox_server_currentMapGetFilename_409B30() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 2598188))
}
func nox_xxx_mapGetMapName_409B40() *byte {
	return (*byte)(memmap.PtrOff(0x85B3FC, 36))
}
func sub_409B50(a1 *byte) uint32 {
	var result uint32
	result = uint32(libc.StrLen(a1) + 1)
	alloc.Memcpy(memmap.PtrOff(0x5D4594, 3452), unsafe.Pointer(a1), uintptr(result))
	return result
}
func sub_409B80() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 3452))
}
func nox_xxx_gameSetMapPath_409D70(a1 *byte) *byte {
	var (
		result *byte
		v2     *byte
		v3     int32
	)
	result = (*byte)(unsafe.Pointer(uintptr(nox_strcmpi((*byte)(memmap.PtrOff(0x5D4594, 2598188)), a1))))
	if result == nil {
		return result
	}
	libc.StrNCpy((*byte)(memmap.PtrOff(0x5D4594, 2598188)), a1, 0x50)
	*memmap.PtrUint8(0x5D4594, 2598267) = 0
	v2 = libc.StrRChr(a1, 92)
	if v2 != nil {
		v3 = int32(libc.StrLen((*byte)(unsafe.Add(unsafe.Pointer(v2), 1))) - 4)
		result = libc.StrNCpy((*byte)(memmap.PtrOff(0x85B3FC, 36)), (*byte)(unsafe.Add(unsafe.Pointer(v2), 1)), int(v3))
	} else {
		v3 = int32(libc.StrLen((*byte)(memmap.PtrOff(0x5D4594, 2598188))) - 4)
		if v3 < 0 {
			v3 = 0
		}
		result = libc.StrNCpy((*byte)(memmap.PtrOff(0x85B3FC, 36)), (*byte)(memmap.PtrOff(0x5D4594, 2598188)), int(v3))
	}
	*memmap.PtrUint8(0x85B3FC, uintptr(v3+36)) = 0
	nox_server_gameSettingsUpdated = 1
	return result
}
func sub_409E40(a1 int32) int32 {
	var result int32
	result = a1
	if dword_5d4594_3484 != uint32(a1) {
		dword_5d4594_3484 = uint32(a1)
		nox_server_gameSettingsUpdated = 1
	}
	return result
}
func nox_xxx_getServerSubFlags_409E60() int32 {
	return int32(dword_5d4594_3484)
}
func sub_409E70(a1 int32) {
	if (uint32(a1) & dword_5d4594_3484) == uint32(a1) {
		return
	}
	dword_5d4594_3484 |= uint32(a1)
	if noxflags.HasGame(1) {
		if a1&0x2000 != 0 {
			sub_4D7EA0()
		}
	}
	nox_server_gameSettingsUpdated = 1
}
func sub_409EC0(a1 int32) int32 {
	var result int32
	result = a1
	if dword_5d4594_3484&uint32(a1) == 0 {
		return result
	}
	result = ^a1
	nox_server_gameSettingsUpdated = 1
	dword_5d4594_3484 &= uint32(^a1)
	return result
}
func sub_409EF0(a1 int32) {
	dword_5d4594_3484 ^= uint32(a1)
	if noxflags.HasGame(1) {
		if a1&0x2000 != 0 {
			if dword_5d4594_3484&0x2000 != 0 {
				sub_4D7EA0()
			}
		}
	}
	nox_server_gameSettingsUpdated = 1
}
func sub_409F40(a1 int32) int32 {
	var result int32
	if a1 == 0x2000 && noxflags.HasGame(1056) {
		result = 1
	} else {
		result = bool2int32((uint32(a1) & dword_5d4594_3484) != 0)
	}
	return result
}
func nox_xxx_servSetPlrLimit_409F80(a1 int32) int32 {
	var result int32
	result = a1
	if *memmap.PtrUint32(0x5D4594, 3464) != uint32(a1) {
		*memmap.PtrUint32(0x5D4594, 3464) = uint32(a1)
		nox_server_gameSettingsUpdated = 1
	}
	return result
}
func nox_xxx_servGetPlrLimit_409FA0() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 3464))
}
func nox_xxx_servGamedataGet_40A020(a1 int16) int16 {
	return int16(*memmap.PtrUint16(0x5D4594, uintptr(sub_409A70(a1)*2+3488)))
}
func sub_40A180(a1 int16) uint8 {
	return *memmap.PtrUint8(0x5D4594, uintptr(sub_409A70(a1)+3500))
}
func sub_40A1F0(a1 int32) int32 {
	var result int32
	*memmap.PtrUint32(0x587000, 4660) = uint32(a1)
	result = bool2int32(noxflags.HasGame(1))
	if result != 0 {
		result = nox_xxx_netTimerStatus_4D8F50(159, a1)
	}
	return result
}
func sub_40A220() int32 {
	return int32(*memmap.PtrUint32(0x587000, 4660))
}
func sub_40A230() int32 {
	return int32(uint32(uint64(*memmap.PtrUint32(0x5D4594, 3468)) - uint64(nox_platform_get_ticks())))
}
func sub_40A250() int64 {
	var (
		v0     int16
		v1     int32
		v2     int64
		result int64
	)
	v0 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
	v1 = sub_409A70(v0)
	v2 = int64(nox_platform_get_ticks())
	result = int64(int32(*memmap.PtrUint8(0x5D4594, uintptr(v1+3500))) * 60000)
	*memmap.PtrUint64(0x5D4594, 3468) = uint64(result + v2)
	return result
}
func sub_40A310(a1 int32) int64 {
	var (
		v1     int64
		result int64
	)
	v1 = int64(nox_platform_get_ticks())
	result = int64(a1)
	*memmap.PtrUint64(0x5D4594, 3468) = uint64(int64(a1) + v1)
	return result
}
func nox_xxx_set3512_40A340(a1 int32) {
	*memmap.PtrUint32(0x5D4594, 3512) = uint32(a1)
}
func nox_xxx_get3512_40A350() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 3512))
}
func sub_40A3C0(a1 uint32) uint32 {
	var result uint32
	result = a1
	if a1 > 0x800 && a1 < 0x8000 {
		*memmap.PtrUint32(0x587000, 4652) = a1
	}
	return result
}
func nox_xxx_gameSetServername_40A440(a1 *byte) *byte {
	var (
		result *byte
		v2     [16]byte
	)
	result = a1
	if a1 != nil {
		libc.StrNCpy(&v2[0], a1, 0xF)
		v2[15] = 0
		result = (*byte)(unsafe.Pointer(uintptr(nox_strcmpi((*byte)(memmap.PtrOff(0x5D4594, 1324)), &v2[0]))))
		if result != nil {
			result = libc.StrNCpy((*byte)(memmap.PtrOff(0x5D4594, 1324)), &v2[0], 0xF)
			*memmap.PtrUint8(0x5D4594, 1339) = 0
			nox_server_gameSettingsUpdated = 1
		}
	} else {
		*memmap.PtrUint8(0x5D4594, 1324) = 0
		nox_server_gameSettingsUpdated = 1
	}
	return result
}
func nox_xxx_serverOptionsGetServername_40A4C0() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 1324))
}
func nox_xxx_ruleSetNoRespawn_40A5E0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 3584) = uint32(a1)
	return result
}
func nox_server_doPlayersAutoRespawn_40A5F0() int32 {
	if !noxflags.HasGame(4096) {
		return int32(*memmap.PtrUint32(0x5D4594, 3584))
	}
	return 0
}
func nox_xxx_sysopSetPass_40A610(a1 *wchar2_t) *wchar2_t {
	return nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 3540)), a1)
}
func nox_xxx_sysopGetPass_40A630() *wchar2_t {
	return (*wchar2_t)(memmap.PtrOff(0x5D4594, 3540))
}
func nox_server_gameSettingsUpdated_40A670() {
	nox_server_gameSettingsUpdated = 1
}
func nox_server_gameDoSwitchMap_40A680() int32 {
	return nox_server_gameSettingsUpdated
}
func Nox_server_gameUnsetMapLoad_40A690() {
	nox_server_gameSettingsUpdated = 0
}
func sub_40A6A0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 3588) = uint32(a1)
	return result
}
func sub_40A6B0() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 3588))
}
func nox_xxx_rateGet_40A6C0() int32 {
	return int32(*memmap.PtrUint32(0x587000, 4728))
}
func nox_xxx_rateUpdate_40A6D0(a1 int32) int32 {
	var result int32
	result = int32(*memmap.PtrUint32(0x587000, 4728))
	if uint32(a1) != *memmap.PtrUint32(0x587000, 4728) {
		result = bool2int32(noxflags.HasGame(0x20000))
		if result == 1 {
			result = nox_xxx_netNotifyRate_4D7F10(159)
		}
	}
	*memmap.PtrUint32(0x587000, 4728) = uint32(a1)
	return result
}
func sub_40A710(a1 int32) int32 {
	var (
		v1 int32
		v2 *uint8
	)
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x587000, 4664))
	for *(*uint32)(unsafe.Pointer(v2)) != uint32(a1) {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 8))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 4704))) {
			return 1
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*8+4668)))
}
func sub_40A740() int32 {
	var v0 *byte
	v0 = sub_4165B0()
	return bool2int32(noxflags.HasGame(128) && *(*byte)(unsafe.Add(unsafe.Pointer(v0), 53)) < 0)
}
func sub_40A770() int32 {
	var (
		v0 int32
		v3 unsafe.Pointer
	)
	v0 = 0
	if !nox_xxx_CheckGameplayFlags_417DA0(4) {
		for i := nox_common_playerInfoGetFirst_416EA0(); i != nil; i = nox_common_playerInfoGetNext_416EE0(i) {
			if (*(*byte)(unsafe.Add(unsafe.Pointer(i), 3680))&1) == 0 && (i.PlayerInd != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				v0++
			}
		}
		return v0
	}
	v1 := nox_server_teamFirst_418B10()
	if v1 == nil {
		return v0
	}
	for {
		v2 := nox_xxx_getFirstPlayerUnit_4DA7C0()
		if v2 != nil {
			for {
				v3 = *(*unsafe.Pointer)(unsafe.Add(v2.UpdateData, 276))
				if (int32(*(*uint8)(unsafe.Add(v3, 3680)))&1) == 0 && (int32(*(*uint8)(unsafe.Add(v3, 2064))) != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
					break
				}
				v2 = nox_xxx_getNextPlayerUnit_4DA7F0(v2)
				if v2 == nil {
					goto LABEL_10
				}
			}
			v0++
		}
	LABEL_10:
		v1 = nox_server_teamNext_418B60(v1)
		if v1 == nil {
			break
		}
	}
	return v0
}
func nox_xxx_countNonEliminatedPlayersInTeam_40A830(a1p *server.Team) int32 {
	var (
		a1 = unsafe.Pointer(a1p)
		v1 int32
	)
	v1 = 0
	v2 := nox_xxx_getFirstPlayerUnit_4DA7C0()
	if v2 == nil {
		return 0
	}
	for {
		if nox_xxx_teamCompare2_419180((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(v2), 48)), server.TeamID(*(*uint8)(unsafe.Add(a1, 57)))) != 0 {
			v3 := *(*unsafe.Pointer)(unsafe.Add(v2.UpdateData, 276))
			if (int32(*(*uint8)(unsafe.Add(v3, 3680)))&1) == 0 && (int32(*(*uint8)(unsafe.Add(v3, 2064))) != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				v1++
			}
		}
		v2 = nox_xxx_getNextPlayerUnit_4DA7F0(v2)
		if v2 == nil {
			break
		}
	}
	return v1
}
func nox_xxx_gamePlayIsAnyPlayers_40A8A0() int32 {
	var (
		v0     int32
		v3     int32
		result int32
		v6     int32
	)
	v0 = 0
	if !nox_xxx_CheckGameplayFlags_417DA0(4) {
		for i := nox_common_playerInfoGetFirst_416EA0(); i != nil; i = nox_common_playerInfoGetNext_416EE0(i) {
			if i.PlayerUnit != nil {
				v6 = int32(i.Field3680)
				if (v6&1) == 0 || v6&0x20 != 0 {
					v0++
				}
			}
		}
		result = bool2int32(v0 < 1)
		*(*uint8)(unsafe.Pointer(&result)) = uint8(int8(bool2int32(v0 > 1)))
		return result
	}
	v1 := nox_server_teamFirst_418B10()
	if v1 == nil {
		result = bool2int32(v0 < 1)
		*(*uint8)(unsafe.Pointer(&result)) = uint8(int8(bool2int32(v0 > 1)))
		return result
	}
	for {
		v2 := nox_xxx_getFirstPlayerUnit_4DA7C0()
		if v2 != nil {
			for {
				if nox_xxx_teamCompare2_419180((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(v2), 48)), v1.IDVal) != 0 {
					v3 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2.UpdateData, 276)), 3680)))
					if (v3&1) == 0 || v3&0x20 != 0 {
						break
					}
				}
				v2 = nox_xxx_getNextPlayerUnit_4DA7F0(v2)
				if v2 == nil {
					goto LABEL_10
				}
			}
			v0++
		}
	LABEL_10:
		v1 = nox_server_teamNext_418B60(v1)
		if v1 == nil {
			break
		}
	}
	return bool2int32(v0 > 1)
}
func sub_40A970() {
	var (
		v1 int32
		v3 float32
		v4 float32
	)
	*memmap.PtrUint32(0x5D4594, 3520) = gameFrame()
	*memmap.PtrUint32(0x5D4594, 3536) = 0
	v3 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("SuddenDeathPlayerThreshold")))
	*memmap.PtrUint32(0x5D4594, 3476) = uint32(int32(v3))
	v4 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("SuddenDeathLifeTime")))
	*memmap.PtrUint32(0x5D4594, 1392) = uint32(int32(v4))
	for i := nox_common_playerInfoGetFirst_416EA0(); i != nil; i = nox_common_playerInfoGetNext_416EE0(i) {
		v1 = int32(i.Field3680)
		if v1&0x100 != 0 {
			nox_xxx_playerUnsetStatus_417530(i, 256)
		}
	}
	nox_common_gameFlags_unset_40A540(0x4000000)
}
func sub_40AA00() int32 {
	return bool2int32(gameFPS()*20 < (gameFrame() - *memmap.PtrUint32(0x5D4594, 3520)))
}
func sub_40AA20() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 3536))
}
func sub_40AA30(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 3536) = uint32(a1)
	return result
}
func sub_40AA40() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 3476))
}
func sub_40AA60(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 3508) = uint32(a1)
	return result
}
func sub_40AA70(pl *server.Player) int32 {
	var (
		a1     = pl
		result int32
		v3     int32
		v4     int32
		v5     int32
	)
	v1 := sub_416640()
	if a1 == nil {
		goto LABEL_31
	}
	if noxflags.HasGame(4096) {
		return bool2int32(sub_40A770() < 6)
	}
	v3 = int32(a1.Field3680)
	if v3&0x100 != 0 && *memmap.PtrUint32(0x5D4594, 3508) == 0 {
		return 0
	}
	if sub_40A740() == 0 && !noxflags.HasGame(0x8000) {
		goto LABEL_31
	}
	result = int32(a1.Field2068)
	if result == 0 {
		return result
	}
	if nox_server_teamByXxx_418AE0(int32(a1.Field2068)) != nil {
		goto LABEL_31
	}
	v4 = int32(*(*byte)(unsafe.Add(v1, 52)))
	if (noxflags.HasGame(96) || noxflags.HasGame(16) && nox_xxx_CheckGameplayFlags_417DA0(4)) && v4 > 2 {
		v4 = 2
	}
	if int32(uint8(sub_417DE0())) >= v4 {
		return 0
	}
	if noxflags.HasGame(96) {
		v5 = int32(uint8(sub_417DE0()))
		if v5 >= sub_417DC0() {
			return 0
		}
	}
LABEL_31:
	if noxflags.HasGame(128) {
		return 1
	}
	if !noxflags.HasGame(1024) {
		return 1
	}
	v6 := nox_common_playerInfoGetFirst_416EA0()
	if v6 == nil {
		return 1
	}
	for v6.Field2140 <= 0 {
		v6 = nox_common_playerInfoGetNext_416EE0(v6)
		if v6 == nil {
			return 1
		}
	}
	if sub_40AA00() == 0 {
		return 1
	}
	return 0
}
func sub_40E090() {
	dword_5d4594_10984 = 0
}
func nox_xxx_cliCanTalkMB_4100F0(a1 *int16) int32 {
	var (
		v1 int16
		v2 *int16
	)
	v1 = *a1
	v2 = (*int16)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(int16(0))*1))
	if int32(*a1) == 0 {
		return 1
	}
	for int32(*(*uint8)(unsafe.Add(unsafe.Pointer(&v1), unsafe.Sizeof(int16(0))-1))) == 0 {
		v1 = *v2
		v2 = (*int16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(int16(0))*1))
		if int32(v1) == 0 {
			return 1
		}
	}
	return 0
}
func nox_xxx_doorAttachWall_410360(data unsafe.Pointer, x, y int32) {
	wl := nox_xxx_wallCreateAt_410250(x, y)
	if wl == nil {
		return
	}
	wl.Data28 = data
	wl.Flags4 |= 0x10
}
func sub_410390(a1 unsafe.Pointer, a2 int32, a3 int32) {
	var (
		v5 int32
		v6 int8
		v7 [2]int32
	)
	v3 := nox_xxx_wall_4105E0(a2, a3)
	var r1 *server.Wall
	if !(v3 != nil || (func() bool {
		r1 = nox_xxx_wallCreateAt_410250(a2, a3)
		return (func() *server.Wall {
			v3 = r1
			return v3
		}()) != nil
	}())) {
		return
	}
	v5 = int32(*(*uint32)(unsafe.Add(a1, 16)))
	v7[0] = int32(*(*uint32)(unsafe.Add(a1, 12)))
	v6 = int8(v3.Flags4)
	v3.Field32 = a1
	v7[1] = v5
	v3.Flags4 = server.WallFlags(uint8(int8(int32(v6) | 0x10)))
	result := nox_xxx_polygonIsPlayerInPolygon_4217B0((*Point32)(unsafe.Pointer(&v7[0])), 0)
	if result != nil || (func() *nox_player_polygon_check_data {
		result = (*nox_player_polygon_check_data)(unsafe.Pointer(sub_421990((*Point32)(unsafe.Pointer(&v7[0])), 10.0, 0)))
		return result
	}()) != nil {
		*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 8)) = *(*uint8)(unsafe.Add(unsafe.Pointer(result), 130))
	} else {
		*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 8)) = 1
	}
}
func nox_xxx_wallDestroyedByWallid_410520(a1 int16) {
	result := nox_xxx_wallGetFirstBreakableCli_410870()
	if result == nil {
		return
	}
	for {
		v2 := result.Field4
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v2), 10))) == int32(a1) {
			v2.Flags4 |= 0x20
			return
		}
		result = nox_xxx_wallGetNextBreakableCli_410880(result)
		if result == nil {
			return
		}
	}
}
func sub_410550(a1 int16) int32 {
	v1 := nox_xxx_wallSecretGetFirstWall_410780()
	if v1 == nil {
		return 0
	}
	for int32(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 4*3)), 10))) != int32(a1) {
		v1 = nox_xxx_wallSecretNext_410790(v1)
		if v1 == nil {
			return 0
		}
	}
	return *(*int32)(unsafe.Add(v1, 4*3))
}
func Sub_410730() {
	result := dword_5d4594_251560
	if dword_5d4594_251560 != nil {
		for {
			v1 := *(*unsafe.Pointer)(result)
			alloc.FreePtr(result)
			result = v1
			if v1 == nil {
				break
			}
		}
	}
	dword_5d4594_251560 = nil
}
func nox_xxx_wallSecretBlock_410760(a1 unsafe.Pointer) {
	*(*uint32)(a1) = uint32(uintptr(dword_5d4594_251560))
	dword_5d4594_251560 = a1
}
func nox_xxx_wallSecretGetFirstWall_410780() unsafe.Pointer {
	return dword_5d4594_251560
}
func nox_xxx_wallSecretNext_410790(a1 unsafe.Pointer) unsafe.Pointer {
	if a1 == nil {
		return nil
	}
	return *(*unsafe.Pointer)(a1)
}
func sub_4107A0(lpMem unsafe.Pointer) {
	result := dword_5d4594_251560
	var v2 unsafe.Pointer
	if dword_5d4594_251560 == nil {
		return
	}
	for unsafe.Pointer(result) != lpMem {
		v2 = result
		result = nox_xxx_wallSecretNext_410790(result)
		if result == nil {
			return
		}
	}
	if unsafe.Pointer(result) == dword_5d4594_251560 {
		dword_5d4594_251560 = nox_xxx_wallSecretNext_410790(result)
	} else {
		*(*unsafe.Pointer)(v2) = nox_xxx_wallSecretNext_410790(result)
	}
	alloc.FreePtr(lpMem)
}
func nox_xxx_wallBreackableListClear_410810() {
	result := dword_5d4594_251564
	if dword_5d4594_251564 != nil {
		for {
			v1 := result.Field0
			alloc.Free(result)
			result = v1
			if v1 == nil {
				break
			}
		}
	}
	dword_5d4594_251564 = nil
}

type breakableWall struct {
	Field0 *breakableWall
	Field4 *server.Wall
}

func nox_xxx_wallBreackableListAdd_410840(a1 *server.Wall) {
	result, _ := alloc.New(breakableWall{})
	result.Field4 = a1
	result.Field0 = dword_5d4594_251564
	dword_5d4594_251564 = result
}
func nox_xxx_wallGetFirstBreakableCli_410870() *breakableWall { return dword_5d4594_251564 }
func nox_xxx_wallGetNextBreakableCli_410880(a1 *breakableWall) *breakableWall {
	if a1 == nil {
		return nil
	}
	return a1.Field0
}
func nox_xxx_tileAlloc_410F60_init() int32 {
	arr := make([][]obj_5D4594_2650668_t, int(ptr_5D4594_2650668_cap))
	ptr_5D4594_2650668 = arr
	if ptr_5D4594_2650668 == nil {
		return 0
	}
	for i := int32(0); i < ptr_5D4594_2650668_cap; i++ {
		arr2, _ := alloc.Make([]obj_5D4594_2650668_t{}, int(ptr_5D4594_2650668_cap))
		ptr_5D4594_2650668[i] = arr2
		if ptr_5D4594_2650668[i] == nil {
			return 0
		}
	}
	return 1
}
func nox_xxx_tileFree_410FC0_free() {
	for i := int32(0); i < ptr_5D4594_2650668_cap; i++ {
		ptr := ptr_5D4594_2650668[i]
		if ptr != nil {
			alloc.FreeSlice(ptr)
		}
		ptr_5D4594_2650668[i] = nil
	}
	ptr_5D4594_2650668 = nil
}
func nox_xxx_tileNFromPoint_411160(a1 *types.Pointf) int32 {
	var (
		v12 = float32((float64(a1.X) + 11.5) * 0.021739131)
		v13 = float32((float64(a1.Y) + 11.5) * 0.021739131)
		i   = int32(v12)
		j   = int32(v13)
		v14 = float32(float64(a1.X) + 11.5)
		v15 = float32(float64(a1.Y) + 11.5)
		v4  = int32(v14) % 46
		v5  = int32(v15) % 46
	)
	if i-1 <= 0 || i >= math.MaxInt8 || j-1 <= 0 || j >= math.MaxInt8 {
		return -1
	}
	var result int32
	var v16 [2]int32
	if v4 <= v5 {
		if 46-v4 <= v5 {
			obj := &ptr_5D4594_2650668[i][j]
			result = obj.Field24
			if obj.Field40 != nil {
				v16[0] = v4
				v16[1] = v5 - 23
				result = sub_411350((*int32)(obj.Field40), &v16[0], result)
			}
		} else {
			obj := &ptr_5D4594_2650668[i-1][j]
			result = obj.Field4
			if obj.Field20 != nil {
				v16[1] = v5
				v16[0] = v4 + 23
				result = sub_411350((*int32)(obj.Field20), &v16[0], result)
			}
		}
	} else if 46-v4 <= v5 {
		obj := &ptr_5D4594_2650668[i][j]
		result = obj.Field4
		if obj.Field20 != nil {
			v16[1] = v5
			v16[0] = v4 - 23
			result = sub_411350((*int32)(obj.Field20), &v16[0], result)
		}
	} else {
		obj := &ptr_5D4594_2650668[i][j-1]
		result = obj.Field24
		if obj.Field40 != nil {
			v16[0] = v4
			v16[1] = v5 + 23
			result = sub_411350((*int32)(obj.Field40), &v16[0], result)
		}
	}
	return result
}
func sub_411350(a1 *int32, a2 *int32, a3 int32) int32 {
	var (
		v3 *int32
		v4 int32
		v5 int32
	)
	v3 = a1
	if a1 == nil {
		return a3
	}
	v4 = a3
	for {
		v5 = sub_411490(*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*2)), *(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*3)))
		if sub_4113A0(a2, v5) != 0 {
			v4 = *v3
		}
		v3 = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*4)))
		if v3 == nil {
			break
		}
	}
	return v4
}
func sub_4113A0(a1 *int32, a2 int32) int32 {
	var (
		v2 int32 = *a1
		v3 int32 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		v4 bool
		v5 bool
	)
	if *a1 == v3 {
		v4 = true
		v5 = true
	} else if *a1 >= v3 {
		v4 = true
		v5 = false
	} else {
		v4 = false
		v5 = true
	}
	var v6 bool
	var v7 bool
	if v2 == 46-v3 {
		v6 = true
		v7 = true
	} else if v2 >= 46-v3 {
		v6 = true
		v7 = false
	} else {
		v6 = false
		v7 = true
	}
	switch a2 {
	case 0:
		if !v5 || !v6 {
			return 0
		}
		return 1
	case 1:
		if !v5 {
			return 0
		}
		return 1
	case 2:
		if !v5 || !v7 {
			return 0
		}
		return 1
	case 3:
		if !v6 {
			return 0
		}
		return 1
	case 4:
		if !v7 {
			return 0
		}
		return 1
	case 5:
		if !v6 || !v4 {
			return 0
		}
		return 1
	case 6:
		if !v4 {
			return 0
		}
		return 1
	case 7:
		if !v4 || !v7 {
			return 0
		}
		return 1
	case 8:
		if v5 {
			return 1
		}
		if !v6 {
			return 0
		}
		return 1
	case 9:
		if !v5 && !v7 {
			return 0
		}
		return 1
	case 10:
		if !v4 && !v7 {
			return 0
		}
		return 1
	case 11:
		if v4 {
			return 1
		}
		if !v6 {
			return 0
		}
		return 1
	}
	return 0
}
func sub_411490(a1 int32, a2 int32) int32 {
	var (
		v2 int32
		v3 int32
		v5 int32
	)
	v2 = int32(*memmap.PtrUint8(0x85B3FC, uintptr(a1*60+28696)))
	v3 = int32(*memmap.PtrUint8(0x85B3FC, uintptr(a1*60+28697)))
	if v2 == 3 && v3 == 3 {
		return a2
	}
	if a2 == 0 {
		return 0
	}
	if a2 <= v2-2 {
		return 1
	}
	if a2 == v2-1 {
		return 2
	}
	v5 = v2 + v3*2 - 4
	if a2 < v5 {
		return bool2int32(((int32(uint8(int8(v2)))^int32(uint8(int8(a2))))&1) != 0) + 3
	}
	if a2 == v5 {
		return 5
	} else if a2 > (v3+v2)*2-6 {
		if a2 == (v3+v2)*2-5 {
			return 7
		}
		return a2 + (6-v3-v2)*2
	}
	return 6
}
func nox_thing_read_FLOR_411540(f *binfile.MemFile, a2 *uint8) int32 {
	if nox_tile_def_cnt >= 176 {
		return 0
	}
	var ind int32 = int32(nox_tile_def_cnt)
	var p *nox_tileDef_t = &nox_tile_defs_arr[ind]
	nox_memfile_skip(f, 4)
	var sz int32 = int32(nox_memfile_read_u8(f))
	var buf [32]byte
	nox_memfile_read(unsafe.Pointer(&buf[0]), 1, sz, f)
	buf[sz] = 0
	libc.StrNCpy(&p.name[0], &buf[0], 31)
	var v7 int8 = nox_memfile_read_i8(f)
	var v8 int8 = nox_memfile_read_i8(f)
	var v9 int8 = nox_memfile_read_i8(f)
	var cbuf [6]uint8
	cbuf[0] = uint8(v7)
	cbuf[1] = uint8(v8)
	cbuf[2] = uint8(v9)
	if int32(v7) != -1 || int32(cbuf[1]) != 0 || int32(v9) != -1 {
		p.color_48 = nox_color_rgb_4344A0(*(*int32)(unsafe.Pointer(&cbuf[0])), *(*int32)(unsafe.Pointer(&cbuf[1])), *(*int32)(unsafe.Pointer(&cbuf[2])))
	} else {
		p.color_48 = 0x80000000
	}
	p.field_58 = 0
	if nox_xxx_checkFacade_4117E0(p) == 1 {
		p.field_58 |= 1
	}
	p.field_36 = nox_memfile_read_i32(f)
	p.field_40 = nox_memfile_read_i32(f)
	var v14 uint8 = nox_memfile_read_u8(f)
	p.field_57 = v14
	v14 = nox_memfile_read_u8(f)
	p.field_53 = v14
	v14 = nox_memfile_read_u8(f)
	p.field_52 = v14
	v14 = nox_memfile_read_u8(f)
	p.field_54 = v14
	p.field_46 = 0
	v14 = nox_memfile_read_u8(f)
	p.field_55 = v14
	p.field_56 = v14
	p.field_44 = uint16(int16(int32(p.field_52) * int32(p.field_53)))
	var v22 int32 = int32(p.field_53) * int32(p.field_54)
	var v23 int32 = int32(p.field_52)
	p.data_32 = nil
	var v24 int32 = v23 * v22
	if v24 > 0 {
		for i := int32(0); i < v24; i++ {
			var v26 int32 = nox_memfile_read_i32(f)
			*a2 = *memmap.PtrUint8(0x5D4594, 251576)
			if v26 == -1 {
				nox_memfile_skip(f, 1)
				var v33 uint8 = nox_memfile_read_u8(f)
				nox_memfile_read(unsafe.Pointer(a2), 1, int32(v33), f)
				*(*uint8)(unsafe.Add(unsafe.Pointer(a2), v33)) = 0
			}
		}
	}
	nox_tile_def_cnt++
	return 1
}
func nox_xxx_checkFacade_4117E0(tile *nox_tileDef_t) int32 {
	var (
		v1 *byte
		v2 *uint8
	)
	v1 = *(**byte)(memmap.PtrOff(0x587000, 26488))
	if *memmap.PtrUint32(0x587000, 26488) == 0 {
		return 0
	}
	v2 = (*uint8)(memmap.PtrOff(0x587000, 26488))
	for libc.StrCmp(v1, &tile.name[0]) != 0 {
		v1 = (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)))))
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 4))
		if v1 == nil {
			return 0
		}
	}
	return 1
}
func nox_thing_read_EDGE_411850(f *binfile.MemFile, a2 *uint8) int32 {
	var (
		v5  int32
		v7  int32
		v9  int32
		v12 int32
		v14 int32
		v17 uint8
		v19 uint8
		v20 int32
		v21 int32
		v23 int32
		v26 int32
		v28 uint8
		v29 [32]byte
		v30 uint8
		v31 uint8
	)
	if dword_5d4594_251572 >= 64 {
		return 0
	}
	nox_memfile_skip(f, 4)
	v30 = nox_memfile_read_u8(f)
	nox_memfile_read(unsafe.Pointer(&v29[0]), 1, int32(v30), f)
	v5 = dword_5d4594_251572 * 3
	v29[v30] = 0
	libc.StrCpy((*byte)(memmap.PtrOff(0x85B3FC, uintptr(v5*20+28644))), &v29[0])
	v7 = nox_memfile_read_i32(f)
	*memmap.PtrUint32(0x85B3FC, uintptr(dword_5d4594_251572)*60+28680) = uint32(v7)
	v9 = nox_memfile_read_i32(f)
	*memmap.PtrUint32(0x85B3FC, uintptr(dword_5d4594_251572)*60+28684) = uint32(v9)
	*(*uint8)(unsafe.Pointer(&v9)) = nox_memfile_read_u8(f)
	*memmap.PtrUint8(0x85B3FC, uintptr(dword_5d4594_251572)*60+28701) = uint8(int8(v9))
	*(*uint8)(unsafe.Pointer(&v9)) = nox_memfile_read_u8(f)
	v28 = uint8(int8(v9))
	v12 = dword_5d4594_251572 * 60
	*memmap.PtrUint8(0x85B3FC, uintptr(v12+28698)) = uint8(int8(v9))
	*memmap.PtrUint16(0x85B3FC, uintptr(v12+28690)) = 0
	*(*uint8)(unsafe.Pointer(&v9)) = nox_memfile_read_u8(f)
	v14 = dword_5d4594_251572 * 60
	*memmap.PtrUint8(0x85B3FC, uintptr(v14+28699)) = uint8(int8(v9))
	*memmap.PtrUint8(0x85B3FC, uintptr(v14+28700)) = uint8(int8(v9))
	*(*uint8)(unsafe.Pointer(&v9)) = nox_memfile_read_u8(f)
	if int32(uint8(int8(v9))) == 1 {
		return 0
	}
	v17 = nox_memfile_read_u8(f)
	*memmap.PtrUint8(0x85B3FC, uintptr(dword_5d4594_251572)*60+28697) = v17
	v19 = nox_memfile_read_u8(f)
	v20 = dword_5d4594_251572 * 60
	*memmap.PtrUint8(0x85B3FC, uintptr(v20+28696)) = v19
	*memmap.PtrUint16(0x85B3FC, uintptr(v20+28688)) = uint16(int16((int32(v17) + int32(v19)) * 2))
	*memmap.PtrUint32(0x85B3FC, uintptr(v20+28676)) = 0
	if int32(v28)*2*(int32(v17)+int32(v19)) > 0 {
		v21 = int32(v28) * 2 * (int32(v17) + int32(v19))
		for {
			v23 = nox_memfile_read_i32(f)
			*a2 = *memmap.PtrUint8(0x5D4594, 251580)
			if v23 == -1 {
				nox_memfile_skip(f, 1)
				v31 = nox_memfile_read_u8(f)
				nox_memfile_read(unsafe.Pointer(a2), 1, int32(v31), f)
				*(*uint8)(unsafe.Add(unsafe.Pointer(a2), v31)) = 0
			}
			v21--
			if v21 == 0 {
				break
			}
		}
	}
	v26 = nox_memfile_read_i32(f)
	if uint32(v26) != 0x454E4420 {
		return 0
	}
	dword_5d4594_251572++
	return 1
}
func nox_xxx_mapTileAllowTeleport_411A90(a1 *types.Pointf) int32 {
	if *memmap.PtrInt32(0x587000, 26520) == -1 {
		for i := int32(0); i < 176; i++ {
			p := &nox_tile_defs_arr[i]
			if libc.StrCmp(&p.name[0], internCStr("WaterNoTeleport")) == 0 {
				*memmap.PtrUint32(0x587000, 26516) = uint32(i)
			} else if libc.StrCmp(&p.name[0], internCStr("WaterDeepNoTeleport")) == 0 {
				*memmap.PtrUint32(0x587000, 26520) = uint32(i)
			} else if libc.StrCmp(&p.name[0], internCStr("WaterShallowNoTeleport")) == 0 {
				*memmap.PtrUint32(0x587000, 26524) = uint32(i)
			} else if libc.StrCmp(&p.name[0], internCStr("WaterSwampDeepNoTeleport")) == 0 {
				*memmap.PtrUint32(0x587000, 26528) = uint32(i)
			} else if libc.StrCmp(&p.name[0], internCStr("WaterSwampShallowNoTeleport")) == 0 {
				*memmap.PtrUint32(0x587000, 26532) = uint32(i)
			}
		}
	}
	var v3 int32 = nox_xxx_tileNFromPoint_411160(a1)
	return bool2int32(uint32(v3) == *memmap.PtrUint32(0x587000, 26516) || uint32(v3) == *memmap.PtrUint32(0x587000, 26520) || uint32(v3) == *memmap.PtrUint32(0x587000, 26524) || uint32(v3) == *memmap.PtrUint32(0x587000, 26528) || uint32(v3) == *memmap.PtrUint32(0x587000, 26532))
}
func nox_xxx_modifNext_4133C0(a1 *obj_412ae0_t) *obj_412ae0_t {
	return a1.field_34
}
func sub_4133D0(a1 *server.Object) int32 {
	v1 := *memmap.PtrT[*server.ModifierEff](0x5D4594, 251620)
	v2 := a1.InitDataModifier()
	if *memmap.PtrUint32(0x5D4594, 251620) != 0 {
		return bool2int32(a1.ObjClass&0x13001000 != 0 && v2.Modifiers[1] == v1)
	}
	v3 := nox_xxx_modifGetIdByName_413290(internCStr("Material7"))
	v1b := nox_xxx_modifGetDescById_413330(v3)
	*memmap.PtrT[*server.ModifierEff](0x5D4594, 251620) = v1b
	return bool2int32(a1.ObjClass&0x13001000 != 0 && v2.Modifiers[1] == v1b)
}
func sub_413420(a1 int8) noxrender.ImageHandle {
	var (
		v1 *uint8
		v2 int32
		v3 *uint8
	)
	if *memmap.PtrUint32(0x5D4594, 251624) == 0 {
		v1 = (*uint8)(memmap.PtrOff(0x587000, 27340))
		for {
			*(*noxrender.ImageHandle)(unsafe.Pointer(v1)) = nox_xxx_gLoadImg_42F970(*(**byte)(unsafe.Add(unsafe.Pointer(v1), -int(unsafe.Sizeof((*byte)(nil))*1))))
			v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 20))
			if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x587000, 27460))) {
				break
			}
		}
		*memmap.PtrUint32(0x5D4594, 251624) = 1
	}
	v2 = 0
	v3 = (*uint8)(memmap.PtrOff(0x587000, 27332))
	for int32(*v3) != int32(a1) {
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 20))
		v2++
		if int32(uintptr(unsafe.Pointer(v3))) >= int32(uintptr(memmap.PtrOff(0x587000, 27452))) {
			return nil
		}
	}
	return noxrender.ImageHandle(*memmap.PtrPtr(0x587000, uintptr(v2*20+27340)))
}
func sub_4134D0() int32 {
	dword_5d4594_251708 = 0
	dword_5d4594_251712 = 0
	dword_5d4594_251716 = 0
	dword_5d4594_251720 = 0
	return 0
}
func sub_4137E0() int32 {
	var result int32
	result = int32(dword_5d4594_251720)
	if dword_5d4594_251720 != 0 {
		dword_5d4594_251720 = 0
		result = sub_43DBE0()
	}
	return result
}
func sub_413890() *byte {
	var (
		v0 *uint8
		v1 int32
		v2 int16
		v3 uint8
	)
	*memmap.PtrUint8(0x5D4594, 251636) = 0
	*memmap.PtrUint8(0x5D4594, 251637) = 0
	if int32(*memmap.PtrUint8(0x5D4594, 251636)) == 0 {
		return nil
	}
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(libc.StrLen((*byte)(memmap.PtrOff(0x5D4594, 251636)))+251637)))
	v1 = int32(*memmap.PtrUint32(0x587000, 32316))
	v2 = int16(*memmap.PtrUint16(0x587000, 32320))
	*(*uint32)(unsafe.Pointer(func() *uint8 {
		p := &v0
		*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), -1))
		return *p
	}())) = *memmap.PtrUint32(0x587000, 32312)
	v3 = *memmap.PtrUint8(0x587000, 32322)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*1)) = uint32(v1)
	*(*uint16)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof(uint16(0))*4)) = uint16(v2)
	*(*uint8)(unsafe.Add(unsafe.Pointer(v0), 10)) = v3
	return (*byte)(memmap.PtrOff(0x5D4594, 251636))
}
func sub_4138E0(a1 int32) {
	*memmap.PtrUint32(0x5D4594, 251740) = uint32(nox_xxx_checkGameFlagPause_413A50())
	sub_413A00(1)
}
func sub_413900(a1 int32) {
	if nox_video_inFadeTransition_44E0D0() == 0 {
		if *memmap.PtrUint32(0x5D4594, 251740) == 0 {
			sub_413A00(0)
		}
	}
}
func sub_413920() int32 {
	sub_42EBB0(1, ccall.FuncAddr(sub_413900), 0, internCStr("Pause"))
	sub_42EBB0(2, ccall.FuncAddr(sub_4138E0), 0, internCStr("Pause"))
	dword_5d4594_251744 = 0
	return 1
}
func sub_4139B0() int32 {
	return bool2int32(dword_5d4594_251744 != 0)
}
func nox_xxx_checkGameFlagPause_413A50() int32 {
	return bool2int32(noxflags.HasGame(0x40000))
}
func nox_xxx_gameLoopMemDump_413E30() {
	var (
		v0 int32
		v1 int32
	)
	var v2 *uint8
	var v4 int32
	var v5 *byte
	var v6 *uint8
	var v7 int32
	var v8 int32
	var v9 int32
	v0 = 0
	v1 = 0
	v9 = 0
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 252364))
	for {
		*(*uint32)(unsafe.Pointer(v2)) = 0
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 84))
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 338380))) {
			break
		}
	}
	v3 := *memmap.PtrPtr(0x5D4594, 338304)
	if *memmap.PtrUint32(0x5D4594, 338304) != 0 {
		for {
			v4 = 0
			if v0 > 0 {
				v5 = (*byte)(memmap.PtrOff(0x5D4594, 252284))
				for libc.StrCmp(v5, (*byte)(unsafe.Add(v3, 20))) != 0 {
					v0 = v9
					v4++
					v5 = (*byte)(unsafe.Add(unsafe.Pointer(v5), 84))
					if v4 >= v9 {
						goto LABEL_10
					}
				}
				v0 = v9
				*memmap.PtrUint32(0x5D4594, uintptr(v4*84)+252364) += *(*uint32)(unsafe.Add(v3, 16))
			}
		LABEL_10:
			if v4 == v0 {
				*memmap.PtrUint32(0x5D4594, uintptr(v4*84)+252364) = *(*uint32)(unsafe.Add(v3, 16))
				libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, uintptr(v4*84)+252284)), (*byte)(unsafe.Add(v3, 20)))
				v9 = func() int32 {
					p := &v0
					*p++
					return *p
				}()
			}
			v3 = *(*unsafe.Pointer)(unsafe.Add(v3, 4))
			if v3 == nil {
				break
			}
		}
		v1 = 0
	}
	libc.Sort(memmap.PtrOff(0x5D4594, 252284), uint32(v0), 0x54, sub_413F60)
	if v0 > 0 {
		v6 = (*uint8)(memmap.PtrOff(0x5D4594, 252364))
		v7 = v0
		for {
			v8 = int32(*(*uint32)(unsafe.Pointer(v6)))
			v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 84))
			v1 += v8
			v7--
			if v7 == 0 {
				break
			}
		}
	}
}
func sub_413F60(a1 unsafe.Pointer, a2 unsafe.Pointer) int32 {
	return int32(*(*uint32)(unsafe.Add(a1, 4*20)) - *(*uint32)(unsafe.Add(a2, 4*20)))
}
func sub_414BD0(a1 int32) int32 {
	v1 := a1
	if a1 < 0 {
		v1 = a1 + ((25735-a1)/0x6488)*25736
	}
	if v1 >= 25736 {
		v1 %= 0x6488
	}
	return memmap.Int32(0x85B3FC, uintptr(((v1<<12)/25736)*4+12260))
}
func sub_414C50(a1 int32) int32 {
	var (
		v1     int32
		v2     int32
		result int32
	)
	v1 = sub_414BD0(a1)
	v2 = sub_414BD0(6434 - a1)
	if v2 != 0 {
		result = (v1 << 12) / v2
	} else {
		result = bool2int32(v1 <= 0) + math.MaxInt32
	}
	return result
}
func nox_xxx_initSinCosTables_414C90() int8 {
	var (
		v0 int64
		v1 *uint8
		v2 *uint8
		v4 int32
		v5 int32
	)
	*(*uint8)(unsafe.Pointer(&v0)) = *memmap.PtrUint8(0x5D4594, 371240)
	if int32(*memmap.PtrUint8(0x5D4594, 371240)) != 0 {
		return int8(v0)
	}
	*memmap.PtrUint8(0x5D4594, 371240) = 1
	v4 = 0
	v1 = (*uint8)(memmap.PtrOff(0x85B3FC, 12260))
	for {
		*(*uint32)(unsafe.Pointer(v1)) = uint32(int32(int64(math.Sin(float64(v4)*0.0015339808) * *memmap.PtrFloat64(0x581450, 7200))))
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 4))
		v4++
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x85B3FC, 28644))) {
			break
		}
	}
	v5 = 0
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 338472))
	for {
		v0 = int64(math.Acos(float64(v5)*0.00024414062-1.0) * *memmap.PtrFloat64(0x581450, 7184))
		*(*uint32)(unsafe.Pointer(v2)) = uint32(int32(v0))
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 4))
		v5++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 371240))) {
			break
		}
	}
	return int8(v0)
}
func nox_thing_skip_AUD_414D40(f *binfile.MemFile) int32 {
	var (
		v2 int32
		v3 int32
		v5 uint8
	)
	v2 = nox_memfile_read_i32(f)
	if v2 <= 0 {
		return 1
	}
	v3 = v2
	for {
		v5 = nox_memfile_read_u8(f)
		nox_memfile_skip(f, int32(v5)+9)
		for {
			v5 = nox_memfile_read_u8(f)
			if int32(v5) == 0 {
				break
			}
			nox_memfile_skip(f, int32(v5))
		}
		v3--
		if v3 == 0 {
			break
		}
	}
	return 1
}
func nox_thing_read_FLOR_414DB0(f *binfile.MemFile) int32 {
	var (
		v2  *uint8
		v3  *uint8
		v4  *uint8
		v5  int32
		v6  int32
		v7  *int32
		v8  int32
		v9  unsafe.Pointer
		v10 *uint8
		v11 *int32
		v12 int32
		v14 uint8
		v15 uint8
	)
	v2 = (*byte)(unsafe.Add(f.Cur, 4))
	f.Cur = unsafe.Pointer(v2)
	v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), int32(*v2)+13))
	f.Cur = unsafe.Pointer(v3)
	v4 = (*byte)(unsafe.Add(f.Cur, 1))
	v14 = *v3
	f.Cur = unsafe.Pointer(v4)
	v15 = *v4
	f.Cur = unsafe.Add(unsafe.Pointer(v4), 1)
	v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 3))
	v5 = int32(v14) * int32(v15)
	v14 = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), -2))
	f.Cur = unsafe.Pointer(v4)
	v6 = v5 * int32(v14)
	if v6 > 0 {
		for {
			v7 = (*int32)(f.Cur)
			v8 = *v7
			v9 = unsafe.Add(unsafe.Pointer(v7), 4*1)
			f.Cur = v9
			if v8 == -1 {
				v10 = (*uint8)(unsafe.Add(v9, 1))
				f.Cur = unsafe.Pointer(v10)
				f.Cur = unsafe.Add(f.Cur, int32(*v10)+1)
			}
			v6--
			if v6 == 0 {
				break
			}
		}
	}
	v11 = (*int32)(f.Cur)
	v12 = *v11
	f.Cur = unsafe.Add(unsafe.Pointer(v11), 4*1)
	return bool2int32(uint32(v12) == 1162757152)
}
func nox_thing_read_EDGE_414E70(f *binfile.MemFile, a2 unsafe.Pointer) int32 {
	var (
		a1  = unsafe.Pointer(f)
		v2  unsafe.Pointer
		v3  *uint8
		v4  *uint8
		v5  uint8
		v6  uint8
		v7  *uint8
		v9  uint8
		v10 *uint8
		v11 int32
		v12 *int32
		v13 int32
		v14 unsafe.Pointer
		v15 *uint8
		v16 *int32
		v17 int32
		v18 unsafe.Pointer
		v19 uint8
		v20 uint8
		v21 uint8
	)
	v2 = a1
	v18 = a1
	v3 = (*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 8)), 4))
	*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v3)))
	v20 = *v3
	*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v3), 1)))
	nox_memfile_read(a2, 1, int32(v20), (*binfile.MemFile)(v18))
	v4 = (*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 8)), 9))
	*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Pointer(v4)))
	v5 = *v4
	v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 2))
	v19 = v5
	*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Pointer(v4)))
	v6 = *v4
	v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 1))
	*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Pointer(v7)))
	if int32(v6) == 1 {
		return 0
	}
	v9 = *v7
	v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 1))
	*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Pointer(v10)))
	v21 = *v10
	*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v10), 1)))
	v11 = int32(v19) * 2 * (int32(v9) + int32(v21))
	if v11 > 0 {
		for {
			v12 = *(**int32)(unsafe.Add(v2, 8))
			v13 = *v12
			v14 = unsafe.Add(unsafe.Pointer(v12), 4*1)
			*(*unsafe.Pointer)(unsafe.Add(v2, 8)) = v14
			if v13 == -1 {
				v15 = (*uint8)(unsafe.Add(v14, 1))
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Pointer(v15)))
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v15), int32(*v15)+1)))
			}
			v11--
			if v11 == 0 {
				break
			}
		}
	}
	v16 = *(**int32)(unsafe.Add(v2, 8))
	v17 = *v16
	*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v16), 4*1)))
	return bool2int32(uint32(v17) == 1162757152)
}
func nox_thing_read_WALL_414F60(f *binfile.MemFile, a2p unsafe.Pointer) int32 {
	var (
		a1  *uint32 = (*uint32)(unsafe.Pointer(f))
		v2  *uint32
		v3  unsafe.Pointer
		v4  *uint8
		v5  int32
		v6  *uint8
		v7  *uint8
		v8  *uint8
		v9  *uint8
		v10 int32
		v11 int32
		v12 int32
		v13 *int32
		v14 int32
		v15 unsafe.Pointer
		v16 *uint8
		v17 *int32
		v18 int32
		v20 *uint32
		v21 int32
		v22 uint8
		v23 uint8
		v24 uint8
		v25 uint8
		v26 uint8
	)
	v2 = a1
	v3 = a2p
	v20 = a1
	v4 = (*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*2)), 4))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) = uint32(uintptr(unsafe.Pointer(v4)))
	v22 = *v4
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v4), 1)))
	nox_memfile_read(v3, 1, int32(v22), (*binfile.MemFile)(unsafe.Pointer(v20)))
	*(*uint8)(unsafe.Add(v3, v22)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) += 14
	var a2 uint32
	nox_memfile_read64align_40AD60((*byte)(unsafe.Pointer(&a2)), 1, 1, (*binfile.MemFile)(unsafe.Pointer(v2)))
	v5 = 0
	if a2 != 0 {
		for v5 < 8 {
			v6 = (*uint8)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
			v23 = *v6
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v6), 1)))
			nox_memfile_read(v3, 1, int32(v23), (*binfile.MemFile)(unsafe.Pointer(v2)))
			*(*uint8)(unsafe.Add(v3, v23)) = 0
			if func() int32 {
				p := &v5
				*p++
				return *p
			}() >= int32(uint8(uintptr(a2))) {
				goto LABEL_4
			}
		}
		return 0
	}
LABEL_4:
	v7 = (*uint8)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
	v24 = *v7
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v7), 1)))
	nox_memfile_read(v3, 1, int32(v24), (*binfile.MemFile)(unsafe.Pointer(v2)))
	*(*uint8)(unsafe.Add(v3, v24)) = 0
	v8 = (*uint8)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
	v25 = *v8
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v8), 1)))
	nox_memfile_read(v3, 1, int32(v25), (*binfile.MemFile)(unsafe.Pointer(v2)))
	*(*uint8)(unsafe.Add(v3, v25)) = 0
	v9 = (*uint8)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
	v26 = *v9
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v9), 1)))
	nox_memfile_read(v3, 1, int32(v26), (*binfile.MemFile)(unsafe.Pointer(v2)))
	*(*uint8)(unsafe.Add(v3, v26)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2))++
	v10 = 15
	for {
		nox_memfile_read64align_40AD60((*byte)(unsafe.Pointer(&v21)), 1, 1, (*binfile.MemFile)(unsafe.Pointer(v2)))
		if int32(uint8(int8(v21))) > 0 {
			v11 = int32(uint8(int8(v21)))
			for {
				v12 = 4
				for {
					v13 = (*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*2)), 8))
					*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = uint32(uintptr(unsafe.Pointer(v13)))
					v14 = *v13
					v15 = unsafe.Add(unsafe.Pointer(v13), 4*1)
					*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = v15
					if v14 == -1 {
						v16 = (*uint8)(unsafe.Add(v15, 1))
						*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = uint32(uintptr(unsafe.Pointer(v16)))
						*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v16), int32(*v16)+1)))
					}
					v12--
					if v12 == 0 {
						break
					}
				}
				v11--
				if v11 == 0 {
					break
				}
			}
		}
		v10--
		if v10 == 0 {
			break
		}
	}
	v17 = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
	v18 = *v17
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v17), 4*1)))
	return bool2int32(uint32(v18) == 1162757152)
}
func nox_thing_skip_spells_415100(f *binfile.MemFile) int32 {
	var (
		a1  = unsafe.Pointer(f)
		v1  *int32
		v2  int32
		v3  int32
		v4  *uint8
		v5  *int32
		v6  int32
		v7  unsafe.Pointer
		v8  *uint8
		v9  *int32
		v10 int32
		v11 unsafe.Pointer
		v12 *uint8
		v13 *uint8
		v14 *int16
		v15 *uint8
		v16 *uint8
		v17 *uint8
	)
	v1 = *(**int32)(unsafe.Add(a1, 8))
	v2 = *v1
	*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v1), 4*1)))
	if v2 <= 0 {
		return 1
	}
	v3 = v2
	for {
		v4 = (*uint8)(unsafe.Pointer(uintptr(uint32(int32(**(**uint8)(unsafe.Add(a1, 8)))+4) + *(*uint32)(unsafe.Add(a1, 8)))))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v4)))
		v5 = (*int32)(unsafe.Pointer(uintptr(uint32(int32(*v4)+1) + *(*uint32)(unsafe.Add(a1, 8)))))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v5)))
		v6 = *v5
		v7 = unsafe.Add(unsafe.Pointer(v5), 4*1)
		*(*unsafe.Pointer)(unsafe.Add(a1, 8)) = v7
		if v6 == -1 {
			v8 = (*uint8)(unsafe.Add(v7, 1))
			*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v8)))
			*(*uint32)(unsafe.Add(a1, 8)) += uint32(int32(*v8) + 1)
		}
		v9 = *(**int32)(unsafe.Add(a1, 8))
		v10 = *v9
		v11 = unsafe.Add(unsafe.Pointer(v9), 4*1)
		*(*unsafe.Pointer)(unsafe.Add(a1, 8)) = v11
		if v10 == -1 {
			v12 = (*uint8)(unsafe.Add(v11, 1))
			*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v12)))
			*(*uint32)(unsafe.Add(a1, 8)) += uint32(int32(*v12) + 1)
		}
		v13 = (*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 8)), 4))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v13)))
		v14 = (*int16)(unsafe.Pointer(uintptr(uint32(int32(*v13)+1) + *(*uint32)(unsafe.Add(a1, 8)))))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v14)))
		v15 = (*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(v14), *v14), 2))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v15)))
		v16 = (*uint8)(unsafe.Pointer(uintptr(uint32(int32(*v15)+1) + *(*uint32)(unsafe.Add(a1, 8)))))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v16)))
		v17 = (*uint8)(unsafe.Pointer(uintptr(uint32(int32(*v16)+1) + *(*uint32)(unsafe.Add(a1, 8)))))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v17)))
		v3--
		*(*uint32)(unsafe.Add(a1, 8)) += uint32(int32(*v17) + 1)
		if v3 == 0 {
			break
		}
	}
	return 1
}
func nox_thing_read_image_415240(f *binfile.MemFile) int32 {
	var (
		a1  = unsafe.Pointer(f)
		v1  unsafe.Pointer
		v2  *int32
		v3  int32
		v4  int32
		v6  *uint8
		v7  *uint8
		v8  uint8
		v9  int32
		v10 *int32
		v11 int32
		v12 unsafe.Pointer
		v13 *uint8
		v14 uint8
		v15 int8
	)
	v1 = a1
	v2 = *(**int32)(unsafe.Add(a1, 8))
	v3 = *v2
	*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v2), 4*1)))
	if v3 <= 0 {
		return 1
	}
	for v4 = v3; v4 != 0; v4-- {
		v6 = (*uint8)(unsafe.Pointer(uintptr(uint32(int32(**(**uint8)(unsafe.Add(v1, 8)))+1) + *(*uint32)(unsafe.Add(v1, 8)))))
		*(*uint32)(unsafe.Add(v1, 8)) = uint32(uintptr(unsafe.Pointer(v6)))
		v15 = int8(*v6)
		*(*uint32)(unsafe.Add(v1, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v6), 1)))
		v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 1))
		if int32(v15) == 1 || int32(v15) != 2 {
			v14 = 1
		} else {
			v8 = *v7
			*(*uint32)(unsafe.Add(v1, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v7), 2)))
			v14 = v8
			*(*uint32)(unsafe.Add(v1, 8)) += uint32(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 2))) + 1)
			if int32(v8) == 0 {
				continue
			}
		}
		v9 = int32(v14)
		for {
			v10 = *(**int32)(unsafe.Add(v1, 8))
			v11 = *v10
			v12 = unsafe.Add(unsafe.Pointer(v10), 4*1)
			*(*unsafe.Pointer)(unsafe.Add(v1, 8)) = v12
			if v11 == -1 {
				v13 = (*uint8)(unsafe.Add(v12, 1))
				*(*uint32)(unsafe.Add(v1, 8)) = uint32(uintptr(unsafe.Pointer(v13)))
				*(*uint32)(unsafe.Add(v1, 8)) += uint32(int32(*v13) + 1)
			}
			v9--
			if v9 == 0 {
				break
			}
		}
	}
	return 1
}
func nox_thing_read_ability_415320(f *binfile.MemFile) int32 {
	var (
		a1  = unsafe.Pointer(f)
		v1  *int32
		v2  int32
		v3  int32
		v4  *int32
		v5  int32
		v6  unsafe.Pointer
		v7  *uint8
		v8  *int32
		v9  int32
		v10 unsafe.Pointer
		v11 *uint8
		v12 *int32
		v13 int32
		v14 unsafe.Pointer
		v15 *uint8
		v16 *int16
		v17 *uint8
		v18 *uint8
		v19 *uint8
	)
	v1 = *(**int32)(unsafe.Add(a1, 8))
	v2 = *v1
	*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v1), 4*1)))
	if v2 <= 0 {
		return 1
	}
	v3 = v2
	for {
		v4 = (*int32)(unsafe.Pointer(uintptr(uint32(int32(**(**uint8)(unsafe.Add(a1, 8)))+2) + *(*uint32)(unsafe.Add(a1, 8)))))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v4)))
		v5 = *v4
		v6 = unsafe.Add(unsafe.Pointer(v4), 4*1)
		*(*unsafe.Pointer)(unsafe.Add(a1, 8)) = v6
		if v5 == -1 {
			v7 = (*uint8)(unsafe.Add(v6, 1))
			*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v7)))
			*(*uint32)(unsafe.Add(a1, 8)) += uint32(int32(*v7) + 1)
		}
		v8 = *(**int32)(unsafe.Add(a1, 8))
		v9 = *v8
		v10 = unsafe.Add(unsafe.Pointer(v8), 4*1)
		*(*unsafe.Pointer)(unsafe.Add(a1, 8)) = v10
		if v9 == -1 {
			v11 = (*uint8)(unsafe.Add(v10, 1))
			*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v11)))
			*(*uint32)(unsafe.Add(a1, 8)) += uint32(int32(*v11) + 1)
		}
		v12 = *(**int32)(unsafe.Add(a1, 8))
		v13 = *v12
		v14 = unsafe.Add(unsafe.Pointer(v12), 4*1)
		*(*unsafe.Pointer)(unsafe.Add(a1, 8)) = v14
		if v13 == -1 {
			v15 = (*uint8)(unsafe.Add(v14, 1))
			*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v15)))
			*(*uint32)(unsafe.Add(a1, 8)) += uint32(int32(*v15) + 1)
		}
		v16 = (*int16)(unsafe.Pointer(uintptr(uint32(int32(**(**uint8)(unsafe.Add(a1, 8)))+1) + *(*uint32)(unsafe.Add(a1, 8)))))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v16)))
		v17 = (*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(v16), *v16), 2))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v17)))
		v18 = (*uint8)(unsafe.Pointer(uintptr(uint32(int32(*v17)+1) + *(*uint32)(unsafe.Add(a1, 8)))))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v18)))
		v19 = (*uint8)(unsafe.Pointer(uintptr(uint32(int32(*v18)+1) + *(*uint32)(unsafe.Add(a1, 8)))))
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Pointer(v19)))
		v3--
		*(*uint32)(unsafe.Add(a1, 8)) += uint32(int32(*v19) + 1)
		if v3 == 0 {
			break
		}
	}
	return 1
}
func nox_thing_read_audio_415660(a1p *binfile.MemFile, a2 *byte) int32 {
	var (
		a1 = unsafe.Pointer(a1p)
		v2 int32
		v3 *int32
		v4 int32
	)
	v2 = 0
	v3 = *(**int32)(unsafe.Add(a1, 8))
	v4 = *v3
	*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v3), 4*1)))
	if v4 <= 0 {
		return 1
	}
	for sub_452BD0(a1, a2) != 0 {
		if func() int32 {
			p := &v2
			*p++
			return *p
		}() >= v4 {
			return 1
		}
	}
	return 0
}
func nox_xxx_weaponInventoryEquipFlags_415820(item *server.Object) uint32 {
	if item == nil {
		return 0
	}
	return nox_xxx_ammoCheck_415880(item.TypeInd)
}
func sub_415840(a1 uint32) int32 {
	var (
		v1 int32
		i  *uint8
		v3 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 33064) == 0 {
		return 0
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 33064)); *(*uint32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof((*byte)(nil))*2)) != a1; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 12)) {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*3)))
		v1++
		if v3 == 0 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*12+33068)))
}
func nox_xxx_ammoCheck_415880(typ_ind uint16) uint32 {
	var (
		v1 int32
		i  *uint8
		v3 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 33064) == 0 {
		return 0
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 33064)); *(*uint32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof((*byte)(nil))*1)) != uint32(typ_ind); i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 12)) {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*3)))
		v1++
		if v3 == 0 {
			return 0
		}
	}
	return memmap.Uint32(0x587000, uintptr(v1)*12+33072)
}
func sub_415910(a1 *byte) int32 {
	var (
		v1 int32
		v2 **byte
		v3 *uint8
		v4 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 33064) == 0 {
		return 0
	}
	v2 = (**byte)(memmap.PtrOff(0x587000, 33064))
	v3 = (*uint8)(memmap.PtrOff(0x587000, 33064))
	for nox_strcmpi(a1, *v2) != 0 {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3)))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 12))
		v1++
		v2 = (**byte)(unsafe.Pointer(v3))
		if v4 == 0 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*12+33072)))
}
func sub_415960(a1 *wchar2_t) int32 {
	var (
		v1 int32
		v2 **wchar2_t
		v3 *uint8
		v4 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 33392) == 0 {
		return 0
	}
	v2 = (**wchar2_t)(memmap.PtrOff(0x587000, 33392))
	v3 = (*uint8)(memmap.PtrOff(0x587000, 33392))
	for _nox_wcsicmp(a1, *v2) != 0 {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3)))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 12))
		v1++
		v2 = (**wchar2_t)(unsafe.Pointer(v3))
		if v4 == 0 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*12+33400)))
}
func sub_4159B0(a1 *byte) *byte {
	var (
		v1 int32
		i  *uint8
		v3 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 33064) == 0 {
		return nil
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 33064)); *(**byte)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof((*byte)(nil))*2)) != a1; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 12)) {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*3)))
		v1++
		if v3 == 0 {
			return nil
		}
	}
	return *(**byte)(memmap.PtrOff(0x587000, uintptr(v1*12+33064)))
}
func sub_4159F0(a1 int32) int32 {
	var (
		v1 int32
		i  *uint8
		v3 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 33392) == 0 {
		return 0
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 33392)); *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*2)) != uint32(a1); i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 12)) {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*3)))
		v1++
		if v3 == 0 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*12+33392)))
}
func sub_415BD0(a1 unsafe.Pointer) float64 {
	var (
		v1     *server.Modifier
		result float64
	)
	if *(*uint32)(unsafe.Add(a1, 8))&0x2000000 != 0 && (func() *server.Modifier {
		v1 = nox_xxx_equipClothFindDefByTT_413270(int32(*(*uint16)(unsafe.Add(a1, 4))))
		return v1
	}()) != nil {
		result = float64(v1.DamageCoeffOrArmor64)
	} else {
		result = 0.0
	}
	return result
}
func nox_xxx_itemApplyDefendEffect_415C00(a1p *server.Object) float64 {
	a1 := a1p
	if (a1.ObjClass & 0x2000000) == 0 {
		return 0
	}
	idata := a1p.InitDataModifier()
	v2 := nox_xxx_equipClothFindDefByTT_413270(int32(a1.TypeInd))
	if v2 == nil {
		return 0
	}
	v6 := v2.DamageCoeffOrArmor64
	if m := idata.Modifiers[0]; m != nil {
		if fnc := m.Defend76.Fnc.Get(); fnc != nil {
			fnc(m, a1p, nil, a1p, nil, unsafe.Pointer(&v6))
		}
	}
	return float64(v6)
}
func nox_xxx_unitArmorInventoryEquipFlags_415C70(item *server.Object) uint32 {
	v1 := sub_415C90(item)
	if v1 < 0 {
		return 0
	}
	return *memmap.PtrUint32(0x587000, uintptr(v1)*24+34860)
}
func sub_415C90(item *server.Object) int32 {
	var (
		result int32
		v2     int32
		i      *uint8
		v4     int32
	)
	if item == nil {
		return -1
	}
	result = 0
	if *memmap.PtrUint32(0x587000, 34848) == 0 {
		return -1
	}
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v2), unsafe.Sizeof(uint16(0))*1)) = 0
	for i = (*uint8)(memmap.PtrOff(0x587000, 34848)); ; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 24)) {
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v2), unsafe.Sizeof(uint16(0))*0)) = item.TypeInd
		if uint32(v2) == *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*2)) {
			break
		}
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*6)))
		result++
		if v4 == 0 {
			return -1
		}
	}
	return result
}
func sub_415CD0(a1 uint32) int32 {
	var (
		v1 int32
		i  *uint8
		v3 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 34848) == 0 {
		return 0
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 34848)); a1 != *(*uint32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof((*byte)(nil))*3)); i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 24)) {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*6)))
		v1++
		if v3 == 0 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*24+34856)))
}
func sub_415D10(a1 int32) int32 {
	var (
		v1 int32
		i  *uint8
		v3 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 34848) == 0 {
		return 0
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 34848)); a1 != *(*int32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof((*byte)(nil))*2)); i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 24)) {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*6)))
		v1++
		if v3 == 0 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*24+34860)))
}
func sub_415DA0(a1 *wchar2_t) int32 {
	var (
		v1 int32
		v2 **wchar2_t
		v3 *uint8
		v4 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 35496) == 0 {
		return 0
	}
	v2 = (**wchar2_t)(memmap.PtrOff(0x587000, 35496))
	v3 = (*uint8)(memmap.PtrOff(0x587000, 35496))
	for _nox_wcsicmp(a1, *v2) != 0 {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*3)))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 12))
		v1++
		v2 = (**wchar2_t)(unsafe.Pointer(v3))
		if v4 == 0 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*12+35504)))
}
func sub_415DF0(a1 *byte) int32 {
	var (
		v1 int32
		v2 **byte
		v3 *uint8
		v4 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 34848) == 0 {
		return 0
	}
	v2 = (**byte)(memmap.PtrOff(0x587000, 34848))
	v3 = (*uint8)(memmap.PtrOff(0x587000, 34848))
	for nox_strcmpi(a1, *v2) != 0 {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*6)))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 24))
		v1++
		v2 = (**byte)(unsafe.Pointer(v3))
		if v4 == 0 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*24+34860)))
}
func sub_415E40(a1 *byte) *byte {
	var (
		v1 int32
		i  *uint8
		v3 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 34852) == 0 {
		return nil
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 34852)); *(**byte)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof((*byte)(nil))*2)) != a1; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 24)) {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*6)))
		v1++
		if v3 == 0 {
			return nil
		}
	}
	return *(**byte)(memmap.PtrOff(0x587000, uintptr(v1*24+34848)))
}
func sub_415E80(a1 int32) int32 {
	var (
		v1 int32
		i  *uint8
		v3 int32
	)
	v1 = 0
	if *memmap.PtrUint32(0x587000, 35496) == 0 {
		return 0
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 35496)); *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*2)) != uint32(a1); i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 12)) {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*3)))
		v1++
		if v3 == 0 {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*12+35496)))
}
func sub_4161E0() int32 {
	var (
		v0     int32
		v1     int32
		v2     int8
		v3     uint16
		v4     int16
		v5     *byte
		v6     uint8
		v7     uint8
		result int32
		v9     uint8
		v10    uint8
		v11    [4]byte
		v12    int32
		v13    [12]byte
		v14    [16]byte
		v15    [5]int32
	)
	sub_454040((*uint32)(unsafe.Pointer(&v15[0])))
	sub_4536B0((*uint32)(unsafe.Pointer(&v11[0])))
	v12 = sub_453710()
	v0 = nox_common_playerInfoCount_416F40()
	v1 = nox_xxx_servGetPlrLimit_409FA0()
	if nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
		v0--
		v1--
	}
	if int32(*memmap.PtrUint8(0x5D4594, 371619)) != v0 {
		*memmap.PtrUint8(0x5D4594, 371619) = uint8(int8(v0))
		dword_5d4594_371692 = 1
	}
	if int32(*memmap.PtrUint8(0x5D4594, 371620)) != v1 {
		*memmap.PtrUint8(0x5D4594, 371620) = uint8(int8(v1))
		dword_5d4594_371692 = 1
	}
	if (int32(*memmap.PtrUint8(0x5D4594, 371618)) & 0xEF) != sub_43BE50_get_video_mode_id() {
		v2 = int8(sub_43BE50_get_video_mode_id())
		dword_5d4594_371692 = 1
		*memmap.PtrUint8(0x5D4594, 371618) = uint8(int8(int32(*memmap.PtrUint8(0x5D4594, 371618))&0x80 | int32(v2)))
	}
	v3 = uint16(nox_common_gameFlags_getVal_40A5B0())
	v4 = int16(*memmap.PtrUint16(0x5D4594, 371380+52))
	if (int32(*memmap.PtrUint16(0x5D4594, 371380+52))^int32(v3))&0xFFF0 != 0 {
		*memmap.PtrUint16(0x5D4594, 371380+52) = uint16(nox_common_gameFlags_getVal_40A5B0())
		v4 = int16(*memmap.PtrUint16(0x5D4594, 371380+52))
		dword_5d4594_371692 = 1
	}
	if int32(*memmap.PtrUint16(0x5D4594, 371380+54)) != int32(nox_xxx_servGamedataGet_40A020(v4)) {
		*memmap.PtrUint16(0x5D4594, 371380+54) = uint16(nox_xxx_servGamedataGet_40A020(*memmap.PtrInt16(0x5D4594, 371380+52)))
		dword_5d4594_371692 = 1
	}
	if int32(*memmap.PtrUint8(0x5D4594, 371380+56)) != int32(sub_40A180(*memmap.PtrInt16(0x5D4594, 371380+52))) {
		*memmap.PtrUint8(0x5D4594, 371380+56) = sub_40A180(*memmap.PtrInt16(0x5D4594, 371380+52))
		dword_5d4594_371692 = 1
	}
	libc.StrNCpy(&v14[0], (*byte)(memmap.PtrOff(0x5D4594, 371380+9)), 0xF)
	v14[15] = 0
	if libc.StrCmp(&v14[0], nox_xxx_serverOptionsGetServername_40A4C0()) != 0 {
		v5 = nox_xxx_serverOptionsGetServername_40A4C0()
		libc.StrNCpy((*byte)(memmap.PtrOff(0x5D4594, 371380+9)), v5, 0xF)
		dword_5d4594_371692 = 1
	}
	libc.StrCpy(&v13[0], (*byte)(memmap.PtrOff(0x5D4594, 371380)))
	if libc.StrCmp(&v13[0], nox_xxx_mapGetMapName_409B40()) != 0 {
		libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, 371380)), nox_xxx_mapGetMapName_409B40())
		dword_5d4594_371692 = 1
	}
	v6 = 0
	v9 = 0
	for {
		if *memmap.PtrUint32(0x5D4594, uintptr(int32(v9)*4+(371380+24))) != uint32(v15[v9]) {
			break
		}
		v9 = func() uint8 {
			p := &v6
			*p++
			return *p
		}()
		if int32(v6) >= 5 {
			break
		}
	}
	if int32(v6) != 5 {
		dword_5d4594_371692 = 1
		alloc.Memcpy(memmap.PtrOff(0x5D4594, 371380+24), unsafe.Pointer(&v15[0]), 0x14)
	}
	if !noxflags.HasGame(1) {
		return int32(dword_5d4594_371692)
	}
	if *memmap.PtrUint32(0x5D4594, 371380+48) != uint32(v12) {
		*memmap.PtrUint32(0x5D4594, 371380+48) = uint32(v12)
		dword_5d4594_371692 = 1
	}
	v7 = 0
	v10 = 0
	for {
		if (*memmap.PtrUint8(0x5D4594, uintptr(int32(v10)+(371380+44)))) != v11[v10] {
			break
		}
		v10 = func() uint8 {
			p := &v7
			*p++
			return *p
		}()
		if int32(v7) >= 4 {
			break
		}
	}
	if int32(v7) == 4 {
		return int32(dword_5d4594_371692)
	}
	*memmap.PtrUint32(0x5D4594, 371380+44) = *(*uint32)(unsafe.Pointer(&v11[0]))
	result = 1
	dword_5d4594_371692 = 1
	return result
}
func sub_4164F0() {
	dword_5d4594_371692 = 0
}
func sub_416580() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 371688))
}
func nox_xxx_cliGamedataGet_416590(a1 int32) *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(a1)*58+371380))
}
func sub_4165B0() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(memmap.Uint32(0x5D4594, 371688))*58+371380))
}
func sub_4165D0(a1 int32) *byte {
	*memmap.PtrUint32(0x5D4594, 371688) = uint32(a1)
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr(a1)*58+371380))
}
func sub_4165F0(a1 int32, a2 int32) int32 {
	var result int32
	result = a2
	alloc.Memcpy(memmap.PtrOff(0x5D4594, uintptr(a2)*58+371380), memmap.PtrOff(0x5D4594, uintptr(a1*58)+371380), 0x3A)
	return result
}
func sub_416630() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 371616))
}
func sub_416640() unsafe.Pointer {
	return memmap.PtrOff(0x5D4594, 371516)
}
func sub_416650() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 371700))
}
func sub_416690() {
	var (
		v0 *byte
		v1 *byte
		v2 int16
		v3 [84]byte
	)
	if false {
		v0 = nox_xxx_cliGamedataGet_416590(0)
		sub_4161E0()
		v1 = sub_416630()
		alloc.Memcpy(unsafe.Add(unsafe.Pointer(v1), 11), unsafe.Pointer(v0), 0x3A)
		if nox_xxx_isQuest_4D6F50() != 0 {
			v2 = int16(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), 63))) & 0xFF7F)
			*(*uint8)(unsafe.Add(unsafe.Pointer(&v2), unsafe.Sizeof(int16(0))-1)) |= 0x10
			*(*uint16)(unsafe.Add(unsafe.Pointer(v1), 63)) = uint16(v2)
			*(*uint16)(unsafe.Add(unsafe.Pointer(v1), 65)) = uint16(int16(nox_game_getQuestStage_4E3CC0()))
		}
		v3[sub_425550(v1, &v3[0], 552)] = 0
		sub_4164F0()
	}
}
func sub_416720() {
	var (
		v0 int32 = 0
		v2       = sub_416900()
	)
	for v2 != nil {
		v3 := sub_416910(v2)
		if *(*uint32)(unsafe.Add(v2, 68)) != 0 || (*(*uint32)(unsafe.Add(v2, 64))) != 0 {
			if uint64(nox_platform_get_ticks()) > *(*uint64)(unsafe.Add(v2, 64)) {
				sub_416820(v0)
			}
		}
		v0++
		v2 = v3
	}
}
func sub_416770(a1 int32, a2 *wchar2_t, a3 *byte) {
	var v3 *uint32
	v3 = (*uint32)(alloc.Calloc1(1, 0x60))
	sub_425770(unsafe.Pointer(v3))
	nox_wcscpy((*wchar2_t)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(wchar2_t(0))*6)), a2)
	if a3 != nil {
		libc.StrCpy((*byte)(unsafe.Add(unsafe.Pointer(v3), 72)), a3)
	} else {
		*(*uint8)(unsafe.Add(unsafe.Pointer(v3), 72)) = 0
	}
	nox_common_list_append_4258E0((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 371500)), (*nox_list_item_t)(unsafe.Pointer(v3)))
	if a1 != 0 {
		*(*uint64)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint64(0))*8)) = uint64(uint32(a1*60000) + nox_platform_get_ticks())
	} else {
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*16)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*17)) = 0
	}
	sub_455800()
}
func sub_416820(a1 int32) {
	var (
		v3 int32
		v4 int32
	)
	v2 := sub_416900()
	if v2 == nil {
		return
	}
	v3 = a1
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
		v2 = sub_416910(v2)
		if v2 == nil {
			return
		}
	}
	nox_common_list_remove_425920(v2)
	alloc.FreePtr(v2)
}
func sub_416860(a1 int32) {
	var (
		v3 int32
		v4 int32
	)
	result := sub_4168E0()
	v2 := result
	if result != nil {
		v3 = a1
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
			result = sub_4168F0(v2)
			v2 = result
			if result == nil {
				return
			}
		}
		nox_common_list_remove_425920(v2)
		alloc.FreePtr(v2)
	}
}
func sub_4168A0(a1 *wchar2_t) {
	var v1 *wchar2_t
	v1 = (*wchar2_t)(alloc.Calloc1(1, 0x40))
	sub_425770(unsafe.Pointer(v1))
	nox_wcscpy((*wchar2_t)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(wchar2_t(0))*6)), a1)
	nox_common_list_append_4258E0((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 371364)), (*nox_list_item_t)(unsafe.Pointer(v1)))
	sub_455800()
}
func sub_4168E0() unsafe.Pointer {
	return unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(memmap.PtrInt32(0x5D4594, 371364)))))
}
func sub_4168F0(a1 unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(a1)))
}
func sub_416900() unsafe.Pointer {
	return unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(memmap.PtrInt32(0x5D4594, 371500)))))
}
func sub_416910(a1 unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(a1)))
}
func sub_416920() int32 {
	nox_common_list_clear_425760((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 371364)))
	nox_common_list_clear_425760((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 371500)))
	return sub_4E41B0((*byte)(memmap.PtrOff(0x587000, 54280)))
}
func sub_416950() {
	sub_4E43F0(internCStr("ban.txt"))
	v0 := sub_4168E0()
	if v0 != nil {
		for {
			v1 := sub_4168F0(v0)
			nox_common_list_remove_425920(v0)
			alloc.FreePtr(v0)
			v0 = v1
			if v1 == nil {
				break
			}
		}
	}
	result := sub_416900()
	v3 := result
	if result != nil {
		for {
			v4 := sub_416910(v3)
			nox_common_list_remove_425920(v3)
			alloc.FreePtr(v3)
			v3 = v4
			if v4 == nil {
				break
			}
		}
	}
}
func sub_4169C0() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 371704))
}
func nox_xxx_cliSetSettingsAcquired_4169D0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 371704) = uint32(a1)
	return result
}
func sub_4169F0() *byte {
	var result *byte
	result = (*byte)(sub_416640())
	*(*byte)(unsafe.Add(unsafe.Pointer(result), 100)) &= 0xEF
	return result
}
func nox_xxx_playerForceSendLessons_416E50(a1 int32) {
	result := nox_common_playerInfoGetFirst_416EA0()
	for i := result; result != nil; i = result {
		i.Lessons = 0
		i.Field2140 = 0
		if a1 != 0 {
			if i.PlayerUnit != nil {
				nox_xxx_netReportLesson_4D8EF0(i.PlayerUnit)
			}
		}
		result = nox_common_playerInfoGetNext_416EE0(i)
	}
}
func nox_xxx_playerByName_4170D0(a1 *wchar2_t) *server.Player {
	if a1 == nil {
		return nil
	}
	v1 := nox_common_playerInfoGetFirst_416EA0()
	if v1 == nil {
		return nil
	}
	for _nox_wcsicmp((*wchar2_t)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(wchar2_t(0))*2352)), a1) != 0 {
		v1 = nox_common_playerInfoGetNext_416EE0(v1)
		if v1 == nil {
			return nil
		}
	}
	return v1
}

func nox_xxx_netMarkMinimapObject_417190(pind int32, obj *server.Object, flags uint32) int32 {
	if pind < 0 || pind >= NOX_PLAYERINFO_MAX || obj == nil {
		return 0
	}
	pl := nox_common_playerInfoFromNumRaw(pind)
	if pl.Field4580 != nil {
		if pl.Field4580.Field4 == obj {
			pl.Field4580.Field0 |= flags
			return 1
		}
		for it := pl.Field4580.Field8; it != nil && it != pl.Field4580; it = it.Field8 {
			if it.Field4 == obj {
				it.Field0 |= flags
				return 1
			}
		}
	}
	m, _ := alloc.New(server.MinimapItem{})
	if m == nil {
		return 0
	}
	m.Field4 = obj
	m.Field0 = flags
	if pl.Field4580 != nil {
		m.Field8 = pl.Field4580
		m.Field12 = pl.Field4580.Field12
		pl.Field4580.Field12 = m
		m.Field12.Field8 = m
		pl.Field4580 = m
	} else {
		pl.Field4580 = m
		m.Field12 = m
		m.Field8 = m
	}
	nox_xxx_unitSetXStatus_4E4800(obj, 1)
	return 1
}
func sub_417270(a1 int32) int32 {
	var result int32
	if !(a1 >= 0 && a1 < NOX_PLAYERINFO_MAX) {
		return result
	}
	pl := nox_common_playerInfoFromNumRaw(a1)
	v2 := pl.Field4580
	if v2 == nil {
		return result
	}
	v3 := v2.Field8
	for result = 1; v3 != v2; result++ {
		v3 = v3.Field8
	}
	return result
}
func nox_xxx_netUnmarkMinimapObj_417300(pind int32, obj *server.Object, a3 uint32) int32 {
	if pind < 0 || pind >= NOX_PLAYERINFO_MAX {
		return 0
	}
	if obj == nil {
		return 0
	}
	pl := nox_common_playerInfoFromNumRaw(pind)
	m := pl.Field4580
	if m == nil {
		return 0
	}
	for {
		v6 := m.Field8
		if m.Field4 == obj {
			break
		}
		if v6 == pl.Field4580 {
			return 0
		}
		m = m.Field8
		if v6 == nil {
			return 0
		}
	}
	m.Field0 &^= a3
	if m.Field0 != 0 {
		return 0
	}
	v8 := pl.Field4580
	if v8.Field8 == v8 {
		pl.Field4580 = nil
	} else {
		if v8 == m {
			pl.Field4580 = m.Field8
		}
		m.Field8.Field12 = m.Field12
		m.Field12.Field8 = m.Field8
	}
	alloc.Free(m)
	v9 := int32(obj.Field5)
	*(*uint8)(unsafe.Pointer(&v9)) = uint8(int8(v9 & 0xFE))
	obj.Field5 = uint32(v9)
	return 1
}
func nox_xxx_playerMapTracksObj_4173D0(a1 int32, a2p *server.Object) int32 {
	var (
		a2 = a2p
	)
	if !(a1 >= 0 && a1 < NOX_PLAYERINFO_MAX) {
		return 0
	}
	if a2 == nil {
		return 0
	}
	pl := nox_common_playerInfoFromNumRaw(a1)
	v3 := pl.Field4580
	if v3 == nil {
		return 0
	}
	for v3.Field4 != a2 {
		v3 = v3.Field8
		if v3 == pl.Field4580 || v3 == nil {
			return 0
		}
	}
	return 1
}
func nox_xxx_netUnmarkMinimapSpec_417470(a1 *server.Object, a2 int32) {
	result := nox_common_playerInfoGetFirst_416EA0()
	for i := result; result != nil; i = result {
		nox_xxx_netUnmarkMinimapObj_417300(int32(i.PlayerInd), a1, uint32(a2))
		result = nox_common_playerInfoGetNext_416EE0(i)
	}
}
func nox_xxx_netMarkMinimapForAll_4174B0(a1 *server.Object, a2 int32) {
	result := nox_common_playerInfoGetFirst_416EA0()
	for i := result; result != nil; i = result {
		nox_xxx_netMarkMinimapObject_417190(int32(i.PlayerInd), a1, uint32(a2))
		result = nox_common_playerInfoGetNext_416EE0(i)
	}
}
func nox_xxx_netNeedTimestampStatus_4174F0(a1 *server.Player, a2 int32) {
	a1.Field3680 |= uint32(a2)
	if !noxflags.HasGame(1) {
		return
	}
	if a2&0x423 != 0 {
		nox_xxx_netReportPlayerStatus_417630(a1)
	}
}
func nox_xxx_playerUnsetStatus_417530(a1p *server.Player, a2 int32) {
	var (
		a1 = a1p
		v2 int32
		v3 int16
	)
	a1.Field3680 &= uint32(^a2)
	v2 = bool2int32(noxflags.HasGame(1))
	if v2 == 0 {
		return
	}
	if a2&1 != 0 {
		v2 = bool2int32(noxflags.HasGame(128))
		if v2 == 0 {
			v2 = nox_xxx_gamePlayIsAnyPlayers_40A8A0()
			if v2 != 0 {
				v2 = sub_40A220()
				if v2 == 0 {
					v3 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
					*(*uint8)(unsafe.Pointer(&v2)) = sub_40A180(v3)
					if int32(uint8(int8(v2))) != 0 {
						sub_40A250()
						*(*uint8)(unsafe.Pointer(&v2)) = uint8(int8(sub_40A1F0(1)))
					}
				}
			}
		}
	}
	if a2&0x423 != 0 {
		nox_xxx_netReportPlayerStatus_417630(a1)
	}
}
func nox_xxx_sendAllClientStatus_4175C0(a1 unsafe.Pointer) {
	var (
		v3 int32
		v4 [7]byte
	)
	result := nox_common_playerInfoGetFirst_416EA0()
	for i := result; result != nil; i = result {
		v4[0] = 106
		*(*uint16)(unsafe.Pointer(&v4[1])) = *(*uint16)(unsafe.Add(unsafe.Pointer(i), 2060))
		v3 = int32(*(*uint8)(unsafe.Add(a1, 2064)))
		*(*uint32)(unsafe.Pointer(&v4[3])) = i.Field3680 & 0x423
		nox_xxx_netSendPacket1_4E5390(v3, unsafe.Pointer(&v4[0]), 7, nil, 0)
		result = nox_common_playerInfoGetNext_416EE0(i)
	}
}
func nox_xxx_netReportPlayerStatus_417630(pl *server.Player) {
	var (
		a1 = unsafe.Pointer(pl)
		v1 int16
		v2 int32
		v4 [7]byte
	)
	v1 = int16(*(*uint16)(unsafe.Add(a1, 2060)))
	v2 = int32(*(*uint32)(unsafe.Add(a1, 3680)) & 0x423)
	v4[0] = 106
	*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(v1)
	*(*uint32)(unsafe.Pointer(&v4[3])) = uint32(v2)
	nox_xxx_netSendPacket1_4E5390(math.MaxUint8, unsafe.Pointer(&v4[0]), 7, nil, 0)
}
func nox_xxx_cliPlayerRespawn_417680(a1p unsafe.Pointer, a2 int8) {
	var (
		v4  int32
		v5  *uint32
		v7  int32
		v8  *uint32
		v9  int32
		v12 int32
		v13 int8
		v14 int32
		v15 int8
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int8
		v21 int32
		v22 int32
		v23 int8
		v24 int32
		v25 int32
		v26 int32
	)
	v2 := a1p
	if a1p == nil {
		return
	}
	if !noxflags.HasGame(1) {
		*(*uint32)(unsafe.Add(v2, 4)) = 0
	}
	v3 := unsafe.Add(v2, 2328)
	v4 = 27
	for {
		v5 = (*uint32)(v3)
		*(*uint32)(unsafe.Add(v3, -4)) = 0
		v3 = unsafe.Add(v3, 24)
		*v5 = 0
		v4--
		*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*3)) = 0
		if v4 == 0 {
			break
		}
	}
	if !noxflags.HasGame(1) {
		*(*uint32)(v2) = 0
	}
	v6 := unsafe.Add(v2, 2976)
	v7 = 26
	for {
		v8 = (*uint32)(v6)
		*(*uint32)(unsafe.Add(v6, -4)) = 0
		v6 = unsafe.Add(v6, 24)
		*v8 = 0
		v7--
		*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*2)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*3)) = 0
		if v7 == 0 {
			break
		}
	}
	v9 = nox_xxx_modifGetIdByName_413290(internCStr("UserColor1"))
	v10 := nox_xxx_modifGetDescById_413330(v9)
	if v10 == nil {
		return
	}
	var a1b uint32
	if int32(*(*uint8)(unsafe.Add(v2, 2251))) != 0 || noxflags.HasGame(2048) {
		*(*uint8)(unsafe.Pointer(&a1b)) = math.MaxUint8
		v11 := nox_xxx_modifGetDescById_413330(int32(v10.Ind4 + uint32(*(*uint8)(unsafe.Add(v2, 2269)))))
		v12 = int32(*(*uint8)(unsafe.Add(v2, 2270)))
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a1b), 1)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v11), 4))
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a1b), 2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(nox_xxx_modifGetDescById_413330(int32(v10.Ind4+uint32(v12)))), 4))
		*(*uint8)(unsafe.Add(unsafe.Pointer(&a1b), 4-1)) = math.MaxUint8
		if int32(a2)&1 != 0 {
			nox_xxx_clientEquipWeaponArmor_417AA0(82, int32(*(*uint32)(unsafe.Add(v2, 2060))), 1024, unsafe.Pointer(&a1b))
		}
	}
	*(*uint8)(unsafe.Pointer(&a1b)) = math.MaxUint8
	*(*uint8)(unsafe.Add(unsafe.Pointer(&a1b), 1)) = *(*uint8)(unsafe.Add(unsafe.Pointer(nox_xxx_modifGetDescById_413330(int32(v10.Ind4+uint32(*(*uint8)(unsafe.Add(v2, 2268)))))), 4))
	*(*uint16)(unsafe.Add(unsafe.Pointer(&a1b), unsafe.Sizeof(uint16(0))*1)) = math.MaxUint16
	if int32(a2)&2 != 0 {
		nox_xxx_clientEquipWeaponArmor_417AA0(82, int32(*(*uint32)(unsafe.Add(v2, 2060))), 4, unsafe.Pointer(&a1b))
	}
	v13 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(nox_xxx_modifGetDescById_413330(int32(v10.Ind4+uint32(*(*uint8)(unsafe.Add(v2, 2272)))))), 4)))
	v14 = int32(*(*uint8)(unsafe.Add(v2, 2271)))
	*(*uint8)(unsafe.Pointer(&a1b)) = uint8(v13)
	*(*uint8)(unsafe.Add(unsafe.Pointer(&a1b), 1)) = *(*uint8)(unsafe.Add(unsafe.Pointer(nox_xxx_modifGetDescById_413330(int32(v10.Ind4+uint32(v14)))), 4))
	*(*uint16)(unsafe.Add(unsafe.Pointer(&a1b), unsafe.Sizeof(uint16(0))*1)) = math.MaxUint16
	if int32(a2)&4 != 0 {
		nox_xxx_clientEquipWeaponArmor_417AA0(82, int32(*(*uint32)(unsafe.Add(v2, 2060))), 1, unsafe.Pointer(&a1b))
	}
	v15 = int8(*(*uint8)(unsafe.Add(v2, 2251)))
	a1a := int32(-1)
	if int32(v15) == 1 {
		if noxflags.HasGame(2048) {
			if int32(a2)&8 != 0 {
				v16 = nox_xxx_modifGetIdByName_413290(internCStr("ArmorQuality1"))
				*(*uint8)(unsafe.Pointer(&a1a)) = *(*uint8)(unsafe.Add(unsafe.Pointer(nox_xxx_modifGetDescById_413330(v16)), 4))
				nox_xxx_clientEquipWeaponArmor_417AA0(80, int32(*(*uint32)(unsafe.Add(v2, 2060))), 0x8000, unsafe.Pointer(&a1a))
			}
		} else if noxflags.HasGame(4096) {
			a1b := int32(-1)
			v17 = nox_xxx_modifGetIdByName_413290(internCStr("Replenishment1"))
			*(*uint8)(unsafe.Add(unsafe.Pointer(&a1b), 2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(nox_xxx_modifGetDescById_413330(v17)), 4))
			nox_xxx_clientEquipWeaponArmor_417AA0(80, int32(*(*uint32)(unsafe.Add(v2, 2060))), 0x10000, unsafe.Pointer(&a1b))
		} else if int32(a2)&0x10 != 0 {
			nox_xxx_clientEquipWeaponArmor_417AA0(79, int32(*(*uint32)(unsafe.Add(v2, 2060))), 0x4000, unsafe.Pointer(&a1b))
		}
	}
	if int32(*(*uint8)(unsafe.Add(v2, 2251))) == 0 {
		if noxflags.HasGame(2048) {
			if int32(a2)&0x20 != 0 {
				v18 = nox_xxx_modifGetIdByName_413290(internCStr("ArmorQuality1"))
				*(*uint8)(unsafe.Pointer(&a1a)) = *(*uint8)(unsafe.Add(unsafe.Pointer(nox_xxx_modifGetDescById_413330(v18)), 4))
				v19 = nox_xxx_modifGetIdByName_413290(internCStr("Material1"))
				v20 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(nox_xxx_modifGetDescById_413330(v19)), 4)))
				v21 = int32(*(*uint32)(unsafe.Add(v2, 2060)))
				*(*uint8)(unsafe.Pointer(&a1a)) = uint8(v20)
				nox_xxx_clientEquipWeaponArmor_417AA0(80, v21, 256, unsafe.Pointer(&a1a))
			}
		} else if noxflags.HasGame(4096) {
			v25 = int32(*(*uint32)(unsafe.Add(v2, 2060)))
			a1b := int32(-1)
			nox_xxx_clientEquipWeaponArmor_417AA0(80, v25, 256, unsafe.Pointer(&a1b))
		} else {
			if int32(a2)&0x40 != 0 {
				nox_xxx_clientEquipWeaponArmor_417AA0(80, int32(*(*uint32)(unsafe.Add(v2, 2060))), 512, unsafe.Pointer(&a1a))
			}
			if int32(a2) < 0 {
				nox_xxx_clientEquipWeaponArmor_417AA0(79, int32(*(*uint32)(unsafe.Add(v2, 2060))), 0x1000000, unsafe.Pointer(&a1a))
			}
		}
	}
	if int32(*(*uint8)(unsafe.Add(v2, 2251))) == 2 {
		if noxflags.HasGame(2048) {
			if int32(a2)&8 != 0 {
				v22 = nox_xxx_modifGetIdByName_413290(internCStr("ArmorQuality1"))
				v23 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(nox_xxx_modifGetDescById_413330(v22)), 4)))
				v24 = int32(*(*uint32)(unsafe.Add(v2, 2060)))
				a1b := uint32(uint8(v23))
				nox_xxx_clientEquipWeaponArmor_417AA0(80, v24, 0x8000, unsafe.Pointer(&a1b))
			}
		} else if noxflags.HasGame(4096) {
			v26 = int32(*(*uint32)(unsafe.Add(v2, 2060)))
			a1b := int32(-1)
			nox_xxx_clientEquipWeaponArmor_417AA0(80, v26, 4, unsafe.Pointer(&a1b))
		}
	}
}
func nox_xxx_clientEquipWeaponArmor_417AA0(a1 int8, a2 int32, a3 int32, a4 unsafe.Pointer) {
	var (
		v5  *byte
		v6  int32
		v7  int32
		v8  *byte
		v9  *byte
		v10 int32
		v11 int32
		v12 *byte
	)
	pl := nox_common_playerInfoGetByID_417040(a2)
	if pl == nil {
		return
	}
	if int32(a1) == 81 || int32(a1) == 80 {
		v9 = (*byte)(unsafe.Add(unsafe.Pointer(pl), 2324))
		pl.Field4 |= uint32(a3)
		v10 = 0
		for *(*uint32)(unsafe.Pointer(v9)) != 0 {
			v10++
			v9 = (*byte)(unsafe.Add(unsafe.Pointer(v9), 24))
			if v10 >= 27 {
				return
			}
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(pl), v10*24+2324)) = uint32(a3)
		v11 = 0
		v12 = (*byte)(unsafe.Add(unsafe.Pointer(pl), v10*24+2328))
		for {
			r9 := nox_xxx_modifGetDescById_413330(int32(*(*uint8)(unsafe.Add(a4, v11))))
			*(*uint32)(unsafe.Pointer(v12)) = uint32(uintptr(unsafe.Pointer(r9)))
			v11++
			v12 = (*byte)(unsafe.Add(unsafe.Pointer(v12), 4))
			if v11 >= 4 {
				break
			}
		}
	} else {
		v5 = (*byte)(unsafe.Add(unsafe.Pointer(pl), 2972))
		*(*uint32)(unsafe.Pointer(pl)) |= uint32(a3)
		v6 = 0
		for *(*uint32)(unsafe.Pointer(v5)) != 0 {
			v6++
			v5 = (*byte)(unsafe.Add(unsafe.Pointer(v5), 24))
			if v6 >= 26 {
				return
			}
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(pl), v6*24+2972)) = uint32(a3)
		v7 = 0
		v8 = (*byte)(unsafe.Add(unsafe.Pointer(pl), v6*24+2976))
		for {
			r10 := nox_xxx_modifGetDescById_413330(int32(*(*uint8)(unsafe.Add(a4, v7))))
			*(*uint32)(unsafe.Pointer(v8)) = uint32(uintptr(unsafe.Pointer(r10)))
			v7++
			v8 = (*byte)(unsafe.Add(unsafe.Pointer(v8), 4))
			if v7 >= 4 {
				break
			}
		}
	}
}
func sub_417B80(a1 int8, a2 int32, a3 int32) *byte {
	var (
		result *byte
		v4     int32
		v5     int32
		v6     int32
		i      *byte
		v8     int32
		v9     int32
		j      *byte
	)
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(a2)))
	if result == nil {
		return result
	}
	v4 = ^a3
	if int32(a1) == 84 {
		v5 = int32(uint32(v4) & *(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1)))
		v6 = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1)) = uint32(v5)
		for i = (*byte)(unsafe.Add(unsafe.Pointer(result), 2324)); *(*uint32)(unsafe.Pointer(i)) != uint32(a3); i = (*byte)(unsafe.Add(unsafe.Pointer(i), 24)) {
			if func() int32 {
				p := &v6
				*p++
				return *p
			}() >= 27 {
				return result
			}
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(result), v6*24+2324)) = 0
	} else {
		v8 = int32(uint32(v4) & *(*uint32)(unsafe.Pointer(result)))
		v9 = 0
		*(*uint32)(unsafe.Pointer(result)) = uint32(v8)
		for j = (*byte)(unsafe.Add(unsafe.Pointer(result), 2972)); *(*uint32)(unsafe.Pointer(j)) != uint32(a3); j = (*byte)(unsafe.Add(unsafe.Pointer(j), 24)) {
			if func() int32 {
				p := &v9
				*p++
				return *p
			}() >= 26 {
				return result
			}
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(result), v9*24+2972)) = 0
	}
	return result
}
func sub_417CF0() int32 {
	return int32(nox_server_teamsZzz_419030(0))
}
func sub_417DC0() int32 {
	return int32(dword_5d4594_526276)
}
func sub_417DE0() int8 {
	var (
		v0 int8
	)
	v0 = 0
	for i := nox_server_teamFirst_418B10(); i != nil; i = nox_server_teamNext_418B60(i) {
		if i.Field60Val != 0 {
			v0++
		}
	}
	return v0
}
func nox_xxx_mapInfoSetCapflag_417EA0() int32 {
	v0 := bool2int32(sub_417EC0())
	if v0 != 0 {
		sub_455A50(2)
	}
	return v0
}
func sub_417EC0() bool {
	dword_5d4594_526276 = 0
	for i := nox_server_getFirstObject_4DA790(); i != nil; i = nox_server_getNextObject_4DA7A0(i) {
		if i.ObjClass&0x10000000 != 0 {
			dword_5d4594_526276++
		}
	}
	if dword_5d4594_526276 > 0 && !noxflags.HasGame(0x8000) {
		sub_4181F0(0)
	}
	return dword_5d4594_526276 > 0
}
func nox_xxx_mapInfoSetFlagball_417F30() int8 {
	var v0 int32
	*(*uint8)(unsafe.Pointer(&v0)) = uint8(int8(bool2int32(sub_417EC0())))
	if v0 != 0 {
		sub_455F60()
		*(*uint8)(unsafe.Pointer(&v0)) = uint8(int8(sub_417F50(nil)))
	}
	return int8(v0)
}
func sub_417F50(a1 unsafe.Pointer) int32 {
	var (
		v1  int32
		v3  int32
		v10 float32
	)
	if dword_5d4594_527656 == 0 {
		dword_5d4594_527656 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("GameBallStart")))
	}
	v1 = 0
	v2 := nox_server_getFirstObject_4DA790()
	if v2 == nil {
		return 0
	}
	for {
		if uint32(v2.TypeInd) == dword_5d4594_527656 {
			v1++
		}
		v2 = nox_server_getNextObject_4DA7A0(v2)
		if v2 == nil {
			break
		}
	}
	if v1 == 0 {
		return 0
	}
	v3 = nox_common_randomInt_415FA0(0, v1-1)
	v4 := nox_server_getFirstObject_4DA790()
	if v4 == nil {
		return 0
	}
	for {
		if uint32(v4.TypeInd) == dword_5d4594_527656 {
			if v3 == 0 {
				break
			}
			v3--
		}
		v4 = nox_server_getNextObject_4DA7A0(v4)
		if v4 == nil {
			return 0
		}
	}
	v6 := nox_xxx_newObjectByTypeID_4E3810(internCStr("GameBall"))
	v7 := v6
	if v6 == nil {
		return 0
	}
	v8 := v6.UpdateData
	*(*uint64)(unsafe.Add(v8, 8)) = uint64(nox_platform_get_ticks())
	v10 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("FlagballPossDuration")))
	*(*uint32)(unsafe.Add(v8, 20)) = uint32(int32(v10))
	*(*float32)(unsafe.Add(v8, 24)) = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("FlagballResetVel")))
	nox_xxx_netMarkMinimapForAll_4174B0(v7, 1)
	nox_xxx_createAt_4DAA50(v7, nil, 0.0, 0.0)
	Nox_xxx_unitClearOwner_4EC300(v7)
	sub_4EB9B0(v7, nil)
	sub_4E8290(0, 0)
	nox_xxx_unitMove_4E7010(v7, (*types.Pointf)(unsafe.Add(unsafe.Pointer(v4), 56)))
	v7.VelVec.X = 0
	v7.VelVec.Y = 0
	v7.ForceVec.X = 0
	v7.Pos24.Y = 0
	if a1 == nil {
		return 1
	}
	for i := nox_xxx_getFirstPlayerUnit_4DA7C0(); i != nil; i = nox_xxx_getNextPlayerUnit_4DA7F0(i) {
		if *(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i.UpdateData, 276)), 3628)) == a1 {
			nox_xxx_playerCameraUnlock_4E6040(i)
			nox_xxx_playerCameraFollow_4E6060(i, v7)
		}
	}
	nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(a1))
	return 1
}
func nox_xxx_mapInfoSetKotr_4180D0() int32 {
	var (
		v3 int32
		v6 bool
		v7 int8
	)
	if *memmap.PtrUint32(0x5D4594, 527652) == 0 {
		*memmap.PtrUint32(0x5D4594, 527652) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Crown")))
	}
	v0 := nox_server_getFirstObject_4DA790()
	if v0 != nil {
		for {
			v1 := nox_server_getNextObject_4DA7A0(v0)
			if v0.ObjClass&0x10000000 != 0 {
				nox_xxx_delayedDeleteObject_4E5CC0(v0)
			}
			v0 = v1
			if v1 == nil {
				break
			}
		}
	}
	for i := nox_server_teamFirst_418B10(); i != nil; i = nox_server_teamNext_418B60(i) {
		*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*19)) = 0
	}
	v3 = 0
	v4 := nox_server_getFirstObject_4DA790()
	if v4 == nil {
		return 0
	}
	for {
		v5 := nox_server_getNextObject_4DA7A0(v4)
		if uint32(v4.TypeInd) != *memmap.PtrUint32(0x5D4594, 527652) {
			v4 = v5
			continue
		}
		v3++
		*(*uint32)(unsafe.Add(v4.UpdateData, 4)) = 0
		v6 = !nox_xxx_CheckGameplayFlags_417DA0(4)
		v7 = int8(v4.TeamVal.ID)
		if v6 {
			if int32(v7) != 0 {
				nox_xxx_delayedDeleteObject_4E5CC0(v4)
				sub_4EC6A0(v4)
				v4 = v5
				continue
			}
			nox_xxx_netMarkMinimapForAll_4174B0(v4, 1)
			v4 = v5
			continue
		}
		if int32(v7) == 0 {
			nox_xxx_delayedDeleteObject_4E5CC0(v4)
			sub_4EC6A0(v4)
			v4 = v5
			continue
		}
		v8 := nox_xxx_getTeamByID_418AB0(int32(v4.TeamVal.ID))
		if v8 != nil {
			*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v8), 4*19)) = unsafe.Pointer(v4)
			nox_xxx_netMarkMinimapForAll_4174B0(v4, 1)
		}
		v4 = v5
		if v5 == nil {
			break
		}
	}
	if v3 == 0 {
		return 0
	}
	return 1
}
func sub_4181F0(a1 int32) {
	var (
		v1  uint8
		v5  unsafe.Pointer
		v6  int32
		v7  int32
		v8  bool
		v9  uint8
		v10 int32
		v18 unsafe.Pointer
		v19 uint8
		v20 uint8
		v21 uint8
		v22 [32]*server.Object
	)
	v1 = 0
	v19 = 0
	if a1 != 0 {
		for i := nox_server_teamFirst_418B10(); i != nil; i = nox_server_teamNext_418B60(i) {
			sub_418D80(unsafe.Pointer(i))
		}
	}
	result := nox_common_playerInfoGetFirst_416EA0()
	v4 := result
	if result == nil {
		return
	}
	for {
		v5 = unsafe.Pointer(v4.PlayerUnit)
		if v5 != nil && (v4.NetCodeVal != nox_player_netCode_85319C || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
			v6 = int32(v4.Field3680)
			if ((v6&1) == 0 || v6&0x20 != 0) && nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Add(v5, 48))) == 0 {
				v7 = int32(v19)
				v19 = func() uint8 {
					p := &v1
					*p++
					return *p
				}()
				v22[v7] = v4.PlayerUnit
			}
		}
		result = nox_common_playerInfoGetNext_416EE0(v4)
		v4 = result
		if result == nil {
			break
		}
	}
	if int32(v1) == 0 {
		return
	}
	v8 = int32(v1) <= 1
	v9 = v19
	if !v8 {
		v10 = 50
		for {
			v20 = uint8(int8(nox_common_randomInt_415FA0(0, int32(v9)-1)))
			v21 = uint8(int8(nox_common_randomInt_415FA0(0, int32(v9)-1)))
			v11 := &v22[v20]
			v10--
			v12 := *v11
			*v11 = v22[v21]
			v22[v21] = v12
			if v10 == 0 {
				break
			}
		}
	}
	if int32(v9) <= 0 {
		return
	}
	v13 := &v22[0]
	v14 := int32(v9)
	for {
		v15 := *(*unsafe.Pointer)(unsafe.Pointer(v13))
		v16 := (*v13).UpdateData
		if sub_40A740() != 0 {
			v17 := *(*unsafe.Pointer)(unsafe.Add(v16, 276))
			if *(*int32)(unsafe.Add(v17, 2068)) != 0 {
				t := nox_server_teamByXxx_418AE0(int32(*(*uint32)(unsafe.Add(v17, 2068))))
				if t != nil {
					Nox_xxx_createAtImpl_4191D0(t.IDVal, (*server.ObjectTeam)(unsafe.Add(v15, 48)), 1, *(*uint32)(unsafe.Add(v15, 36)), 0)
				}
			}
		} else {
			v18 = sub_4189D0()
			Nox_xxx_createAtImpl_4191D0(server.TeamID(*(*byte)(unsafe.Add(v18, 57))), (*server.ObjectTeam)(unsafe.Add(v15, 48)), 1, *(*uint32)(unsafe.Add(v15, 36)), 1)
		}
		v13 = (**server.Object)(unsafe.Add(unsafe.Pointer(v13), 4*1))
		v14--
		if v14 == 0 {
			break
		}
	}
}
func sub_418390() int32 {
	if int32(nox_xxx_getTeamCounter_417DD0()) == 0 {
		return 0
	}
	nox_xxx_SetGameplayFlag_417D50(2)
	sub_4181F0(0)
	return 1
}
func sub_4183C0() {
	var (
		v3  unsafe.Pointer
		v4  int32
		v5  unsafe.Pointer
		v6  unsafe.Pointer
		v8  unsafe.Pointer
		v9  float64
		v10 float64
		v11 float64
		v12 float32
	)
	result := nox_xxx_getFirstPlayerUnit_4DA7C0()
	for i := result; result != nil; i = result {
		v2 := i.UpdateData
		if v2 == nil || ((func() bool {
			v3 = *(*unsafe.Pointer)(unsafe.Add(v2, 276))
			return *(*uint32)(unsafe.Add(v3, 2060)) != nox_player_netCode_85319C
		}()) || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) && ((func() bool {
			v4 = int32(*(*uint32)(unsafe.Add(v3, 3680)))
			return (v4 & 1) == 0
		}()) || v4&0x20 != 0) {
			v5 = unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(i.TeamVal.ID)))
			v6 = nil
			v12 = 1e+09
			v7 := nox_server_teamFirst_418B10()
			if v7 != nil {
				for {
					v8 = v7.Field_72
					if v8 != nil {
						v9 = float64(*(*float32)(unsafe.Add(v8, 60)) - i.PosVec.Y)
						v10 = float64(*(*float32)(unsafe.Add(v8, 56)) - i.PosVec.X)
						v11 = v10*v10 + v9*v9
						if v11 < float64(v12) {
							v12 = float32(v11)
							v6 = unsafe.Pointer(v7)
						}
					}
					v7 = nox_server_teamNext_418B60(v7)
					if v7 == nil {
						break
					}
				}
				if v6 != nil {
					if v5 != nil {
						if v6 != v5 {
							sub_4196D0(unsafe.Add(unsafe.Pointer(i), 48), v6, int32(i.NetCode), 0)
						}
					} else {
						Nox_xxx_createAtImpl_4191D0(server.TeamID(*(*uint8)(unsafe.Add(v6, 57))), (*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(i), 48)), 1, i.NetCode, 0)
					}
				}
			}
		}
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i)
	}
}
func sub_4184D0(a1p *server.Team) {
	var (
		a1 = a1p
		v1 int32
		v2 *uint32
		v3 [18]byte
	)
	if a1 != nil {
		sub_457230(a1)
		*(*uint32)(unsafe.Pointer(&v3[6])) = a1.Field60Val
		*(*uint32)(unsafe.Pointer(&v3[2])) = uint32(a1.IDVal)
		*(*uint16)(unsafe.Pointer(&v3[0])) = 196
		*(*uint32)(unsafe.Pointer(&v3[10])) = uint32(a1.Lessons)
		v3[14] = 0
		v3[16] = byte(a1.ColorInd)
		v3[17] = *(*uint8)(unsafe.Add(unsafe.Pointer(a1), 68))
		if noxflags.HasGame(512) {
			v3[14] = 1
		}
		v3[15] = byte(nox_wcslen(&a1.NameBuf[0]))
		v1 = int32(v3[15]) * 2
		v2 = (*uint32)(alloc.Calloc1(1, uintptr(v1+18)))
		*(*uint64)(unsafe.Pointer(v2)) = *(*uint64)(unsafe.Pointer(&v3[0]))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) = *(*uint32)(unsafe.Pointer(&v3[8]))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) = *(*uint32)(unsafe.Pointer(&v3[12]))
		*(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*8)) = *(*uint16)(unsafe.Pointer(&v3[16]))
		alloc.Memcpy(unsafe.Add(unsafe.Pointer(v2), 18), unsafe.Pointer(a1), uintptr(int32(v3[15])*2))
		nox_xxx_netSendPacket1_4E5390(159, unsafe.Pointer(v2), v1+18, nil, 1)
		alloc.Free(v2)
	}
}
func nox_xxx_wndGuiTeamCreate_4185B0() {
	var (
		v2 *byte
		v3 int32
		v4 int8
		v5 *wchar2_t
	)
	nox_xxx_SetGameplayFlag_417D50(4)
	nox_xxx_teamCreate_4186D0(0)
	nox_xxx_teamCreate_4186D0(0)
	result := nox_server_getFirstObject_4DA790()
	for i := result; result != nil; i = result {
		if i.ObjClass&0x10000000 != 0 {
			v2 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(i.TeamVal.ID))))
			if v2 != nil {
				v3 = sub_4ECBD0(unsafe.Pointer(i))
				v4 = int8(v3)
				v5 = nox_server_teamTitle_418C20(v3)
				if v5 != nil {
					sub_418800((*wchar2_t)(unsafe.Pointer(v2)), v5, 1)
				}
				*(*byte)(unsafe.Add(unsafe.Pointer(v2), 56)) = byte(v4)
				sub_4184D0((*server.Team)(unsafe.Pointer(v2)))
				*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*18)) = unsafe.Pointer(i)
			}
		}
		result = nox_server_getNextObject_4DA7A0(i)
	}
}
func nox_xxx_teamAssignFlags_418640() {
	result := nox_server_getFirstObject_4DA790()
	for i := result; result != nil; i = result {
		if i.ObjClass&0x10000000 != 0 {
			v2 := int8(sub_4ECBD0(unsafe.Pointer(i)))
			v3 := (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(i.TeamVal.ID))))
			if v3 != nil {
				*(*byte)(unsafe.Add(unsafe.Pointer(v3), 56)) = byte(v2)
				*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*18)) = unsafe.Pointer(i)
			}
		}
		result = nox_server_getNextObject_4DA7A0(i)
	}
}
func nox_xxx_toggleAllTeamFlags_418690(a1 int32) {
	result := nox_server_teamFirst_418B10()
	for i := result; result != nil; i = result {
		if i.Field_72 != nil {
			v3 := i.Field_72
			if a1 != 0 {
				nox_xxx_objectSetOn_4E75B0((*server.Object)(v3))
			} else {
				nox_xxx_objectSetOff_4E7600((*server.Object)(v3))
			}
		}
		result = nox_server_teamNext_418B60(i)
	}
}
