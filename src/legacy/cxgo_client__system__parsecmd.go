package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_console_playerWhoSent_823692 *server.Player = nil
var nox_client_consoleIsServer_823684 uint32 = 0

func nox_cmd_set_sysop(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	if tokCnt != 3 {
		return 0
	}
	nox_xxx_sysopSetPass_40A610(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))))
	var s *wchar2_t = nox_strman_loadString_40F1D0(internCStr("sysoppasswordset"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 1352)
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s)
	return 1
}
func sub_440A20(a1 *wchar2_t, _rest ...interface{}) {
	var va libc.ArgList
	va.Start(a1, _rest)
	nox_vswprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 822660)), a1, va)
	nox_xxx_printCentered_445490((*wchar2_t)(memmap.PtrOff(0x5D4594, 822660)))
}
func nox_cmd_set_cycle(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var v3 *wchar2_t
	if tokCnt == 3 {
		if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))), internWStr("on")) == 0 {
			sub_4D0D90(1)
			v3 = nox_strman_loadString_40F1D0(internCStr("MapCycleOn"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2614)
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3)
			sub_4AD840()
			return 1
		}
		if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))), internWStr("off")) == 0 {
			sub_4D0D90(0)
			v3 = nox_strman_loadString_40F1D0(internCStr("MapCycleOff"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2621)
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3)
			sub_4AD840()
			return 1
		}
	}
	return 0
}
func nox_cmd_set_weapons(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v3 *wchar2_t
		v5 *wchar2_t
	)
	if tokCnt == 3 {
		if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))), internWStr("on")) == 0 {
			sub_409E70(1)
			nox_server_gameSettingsUpdated_40A670()
			v5 = nox_strman_loadString_40F1D0(internCStr("cmd_token:on"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2644)
			v3 = nox_strman_loadString_40F1D0(internCStr("weapons"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2645)
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5)
			return 1
		}
		if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))), internWStr("off")) == 0 {
			sub_409EC0(1)
			nox_server_gameSettingsUpdated_40A670()
			v5 = nox_strman_loadString_40F1D0(internCStr("cmd_token:off"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2652)
			v3 = nox_strman_loadString_40F1D0(internCStr("weapons"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2653)
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5)
			return 1
		}
	}
	return 0
}
func nox_cmd_set_staffs(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v3 *wchar2_t
		v5 *wchar2_t
	)
	if tokCnt == 3 {
		if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))), internWStr("on")) == 0 {
			sub_409E70(16)
			nox_server_gameSettingsUpdated_40A670()
			v5 = nox_strman_loadString_40F1D0(internCStr("cmd_token:on"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2674)
			v3 = nox_strman_loadString_40F1D0(internCStr("staffs"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2675)
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5)
			return 1
		}
		if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))), internWStr("off")) == 0 {
			sub_409EC0(16)
			nox_server_gameSettingsUpdated_40A670()
			v5 = nox_strman_loadString_40F1D0(internCStr("cmd_token:off"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2682)
			v3 = nox_strman_loadString_40F1D0(internCStr("staffs"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2683)
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5)
			return 1
		}
	}
	return 0
}
func nox_cmd_set_name(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v3  int32
		v5  uint32
		v6  *byte
		v7  *byte
		v8  *byte
		v9  int8
		v10 int32
		v11 *wchar2_t
		v12 *uint32
		v13 [128]byte
		v14 [128]byte
	)
	v3 = tokInd
	if tokCnt < 3 {
		return 0
	}
	v13[0] = 0
	if tokInd < tokCnt {
		v12 = (*uint32)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd)))
		for {
			nox_sprintf(&v14[0], internCStr("%S"), *v12)
			v5 = uint32(libc.StrLen(&v14[0]) + 1)
			v6 = &v13[libc.StrLen(&v13[0])]
			alloc.Memcpy(unsafe.Pointer(v6), unsafe.Pointer(&v14[0]), uintptr((v5>>2)*4))
			v8 = &v14[(v5>>2)*4]
			v7 = (*byte)(unsafe.Add(unsafe.Pointer(v6), (v5>>2)*4))
			v9 = int8(uint8(v5))
			v10 = v3 + 1
			alloc.Memcpy(unsafe.Pointer(v7), unsafe.Pointer(v8), uintptr(int32(v9)&3))
			if v3+1 < tokCnt {
				*(*uint16)(unsafe.Pointer(&v13[libc.StrLen(&v13[0])])) = *memmap.PtrUint16(0x587000, 104484)
			}
			v3++
			v12 = (*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*1))
			if v10 >= tokCnt {
				break
			}
		}
		if v13[0] != 0 {
			nox_xxx_gameSetServername_40A440(&v13[0])
			v11 = nox_strman_loadString_40F1D0(internCStr("setgamename"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2766)
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v11, &v13[0])
		}
	}
	return 1
}
func nox_cmd_set_mnstrs(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v3 *wchar2_t
		v5 *wchar2_t
	)
	if tokCnt == 3 || tokCnt == 4 {
		if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*2)), *(**wchar2_t)(memmap.PtrOff(0x587000, 94468+4*6))) != 0 {
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))), internWStr("on")) == 0 {
				sub_409E70(4)
				nox_server_gameSettingsUpdated_40A670()
				v5 = nox_strman_loadString_40F1D0(internCStr("cmd_token:on"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2810)
				v3 = nox_strman_loadString_40F1D0(internCStr("monsters"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2811)
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5)
				return 1
			}
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))), internWStr("off")) == 0 {
				sub_409EC0(4)
				nox_server_gameSettingsUpdated_40A670()
				v5 = nox_strman_loadString_40F1D0(internCStr("cmd_token:off"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2818)
				v3 = nox_strman_loadString_40F1D0(internCStr("monsters"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2819)
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5)
				return 1
			}
		} else if tokCnt != 3 {
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*3)), internWStr("on")) == 0 {
				sub_409E70(8)
				nox_server_gameSettingsUpdated_40A670()
				v5 = nox_strman_loadString_40F1D0(internCStr("cmd_token:on"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2788)
				v3 = nox_strman_loadString_40F1D0(internCStr("monsterrespawn"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2789)
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5)
				return 1
			}
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*3)), internWStr("off")) == 0 {
				sub_409E70(8)
				nox_server_gameSettingsUpdated_40A670()
				v5 = nox_strman_loadString_40F1D0(internCStr("cmd_token:off"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2796)
				v3 = nox_strman_loadString_40F1D0(internCStr("monsterrespawn"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 2797)
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5)
				return 1
			}
		}
	}
	return 0
}
func nox_cmd_set_spell(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v3  *wchar2_t
		v4  int32
		v5  *byte
		v7  *wchar2_t
		v8  int32
		v9  int32
		v10 [100]byte
	)
	if tokCnt == 4 {
		if noxflags.HasGame(128) {
			v8 = int32(uintptr(unsafe.Pointer(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*2)))))
			v3 = nox_strman_loadString_40F1D0(internCStr("NotInChat"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3293)
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8)
			return 1
		}
		v4 = nox_xxx_spellByTitle_424960(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*2)))
		if v4 != 0 || (func() bool {
			nox_sprintf(&v10[0], internCStr("%S"), *(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*2)))
			return (func() int32 {
				v4 = nox_xxx_spellNameToN_4243F0(&v10[0])
				return v4
			}()) != 0
		}()) {
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*3)), internWStr("on")) == 0 {
				v5 = sub_4165B0()
				if (noxflags.HasGame(64) || *(*byte)(unsafe.Add(unsafe.Pointer(v5), 52))&0x40 != 0) && v4 == 132 {
					return 1
				}
				if nox_xxx_spellIsEnabled_424B70(v4) {
					return 1
				}
				nox_xxx_spellEnable_424B90(v4)
				nox_server_gameSettingsUpdated_40A670()
				v8 = int32(uintptr(unsafe.Pointer(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*2)))))
				v3 = nox_strman_loadString_40F1D0(internCStr("spellenabled"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3324)
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8)
				return 1
			}
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*3)), internWStr("off")) == 0 {
				if !nox_xxx_spellIsEnabled_424B70(v4) {
					return 1
				}
				nox_xxx_spellDisable_424BB0(v4)
				nox_server_gameSettingsUpdated_40A670()
				v8 = int32(uintptr(unsafe.Pointer(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*2)))))
				v3 = nox_strman_loadString_40F1D0(internCStr("spelldisabled"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3333)
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8)
				return 1
			}
		} else {
			v9 = int32(uintptr(unsafe.Pointer(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*2)))))
			v7 = nox_strman_loadString_40F1D0(internCStr("invalidspell"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3342)
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v7, v9)
		}
	}
	return 0
}
func nox_cmd_ban(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v4 *wchar2_t
		v5 *byte
		v6 *byte
		v7 *wchar2_t
		v8 *wchar2_t
		v9 int32
	)
	if tokCnt != 2 {
		return 0
	}
	v4 = *(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd)))
	v5 = nox_xxx_playerByName_4170D0(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))))
	v6 = v5
	if v5 != nil {
		if *(*byte)(unsafe.Add(unsafe.Pointer(v5), 2064)) == 31 {
			v8 = nox_strman_loadString_40F1D0(internCStr("cantbanyourself"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3580)
			sub_440A20(v8)
			return 1
		}
		if noxflags.HasGame(4096) {
			sub_4DCFB0((*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*514)))))))
		} else {
			nox_xxx_playerDisconnByPlrID_4DEB00(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v6), 2064))))
		}
		sub_416770(0, v4, (*byte)(unsafe.Add(unsafe.Pointer(v6), 2112)))
		v9 = int32(uintptr(unsafe.Add(unsafe.Pointer(v6), 4704)))
		v7 = nox_strman_loadString_40F1D0(internCStr("banned"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3577)
	} else {
		sub_416770(0, v4, nil)
		v9 = int32(uintptr(unsafe.Pointer(v4)))
		v7 = nox_strman_loadString_40F1D0(internCStr("banDisallow"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3585)
	}
	sub_440A20(v7, v9)
	return 1
}
func nox_cmd_allow_user(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var s *wchar2_t = nox_strman_loadString_40F1D0(internCStr("notyetimplemented"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3698)
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s)
	return 1
}
func nox_cmd_allow_ip(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var s *wchar2_t = nox_strman_loadString_40F1D0(internCStr("notyetimplemented"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3704)
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s)
	return 1
}
func nox_cmd_kick(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v4 *byte
		v5 *byte
		v6 *wchar2_t
		v7 *wchar2_t
	)
	if tokCnt != 2 {
		return 0
	}
	v4 = nox_xxx_playerByName_4170D0(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))))
	v5 = v4
	if v4 == nil {
		return 1
	}
	if *(*byte)(unsafe.Add(unsafe.Pointer(v4), 2064)) == 31 {
		v7 = nox_strman_loadString_40F1D0(internCStr("cantkickyourself"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3745)
		sub_440A20(v7)
		return 1
	}
	if noxflags.HasGame(4096) {
		sub_4DCFB0((*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*514)))))))
	} else {
		nox_xxx_playerCallDisconnect_4DEAB0(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v5), 2064))), 4)
		v6 = nox_strman_loadString_40F1D0(internCStr("kicked"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3739)
		sub_440A20(v6, (*byte)(unsafe.Add(unsafe.Pointer(v5), 4704)))
	}
	return 1
}
func nox_cmd_set_players(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v3 int32
		v5 *wchar2_t
		v6 int32
		v7 *wchar2_t
	)
	v3 = 0
	if tokCnt != 3 {
		return 0
	}
	v5 = *(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*2))
	if v5 != nil {
		v6 = int32(libc.WStrtol(v5, nil, 10))
		v3 = v6
		if v6 >= 0 {
			if v6 > 999 {
				v3 = 999
			}
		} else {
			v3 = 0
		}
		if nox_xxx_servGetPlrLimit_409FA0() == v3 {
			return 1
		}
		nox_xxx_servSetPlrLimit_409F80(v3)
		sub_455800()
	}
	v7 = nox_strman_loadString_40F1D0(internCStr("playersset"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3779)
	sub_440A20(v7, v3)
	return 1
}
func nox_cmd_set_spellpts(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var s *wchar2_t = nox_strman_loadString_40F1D0(internCStr("notyetimplemented"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3830)
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s)
	return 1
}
func nox_cmd_list_users(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v0 *wchar2_t
		i  *byte
		v2 *wchar2_t
		v3 *wchar2_t
		v5 [128]wchar2_t
	)
	v0 = nox_strman_loadString_40F1D0(internCStr("userslist"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3839)
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v0)
	for i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); i != nil; i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(i))))) {
		v5[0] = 0
		nox_wcscat(&v5[0], (*wchar2_t)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(wchar2_t(0))*2352)))
		if nox_client_consoleIsServer_823684 != 0 && *(*byte)(unsafe.Add(unsafe.Pointer(i), 3680))&4 != 0 {
			nox_wcscat(&v5[0], internWStr(", "))
			v2 = nox_strman_loadString_40F1D0(internCStr("SysMuted"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3851)
			nox_wcscat(&v5[0], v2)
		}
		if *(*byte)(unsafe.Add(unsafe.Pointer(i), 3680))&8 != 0 {
			nox_wcscat(&v5[0], internWStr(", "))
			v3 = nox_strman_loadString_40F1D0(internCStr("ClientMuted"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3857)
			nox_wcscat(&v5[0], v3)
		}
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (*wchar2_t)(memmap.PtrOff(0x587000, 106604)), &v5[0])
	}
	return 1
}
func sub_57A0F0(a1 *wchar2_t) int32 {
	if !noxflags.HasGame(2) {
		return 0
	}
	if a1 == nil {
		return 0
	}
	var v1 *byte = nox_xxx_playerByName_4170D0(a1)
	if v1 == nil {
		return 0
	}
	nox_xxx_playerUnsetStatus_417530((*server.Player)(unsafe.Pointer(v1)), 8)
	return 1
}
func sub_57A130(a1 *wchar2_t) int32 {
	if a1 == nil {
		return 0
	}
	var v1 *byte = nox_xxx_playerByName_4170D0(a1)
	if v1 == nil {
		return 0
	}
	nox_xxx_playerUnsetStatus_417530((*server.Player)(unsafe.Pointer(v1)), 4)
	return 1
}
func nox_cmd_unmute(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v3 **wchar2_t
		v4 int32
		v5 int32
		v6 *wchar2_t
		v8 *wchar2_t
	)
	if tokCnt < 2 || tokCnt > 3 {
		return 0
	}
	v3 = (**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd)))
	if nox_client_consoleIsServer_823684 == 0 {
		v5 = sub_57A0F0(*v3)
	} else {
		if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))), *(**wchar2_t)(memmap.PtrOff(0x587000, 94468+4*7))) != 0 {
			v5 = sub_57A0F0(*v3)
		} else {
			v4 = tokInd + 1
			if tokInd+1 != tokCnt-1 {
				return 0
			}
			v3 = (**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(v4)))
			v5 = sub_57A130(*v3)
		}
	}
	v8 = *v3
	if v5 != 0 {
		v6 = nox_strman_loadString_40F1D0(internCStr("UnMuted"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3923)
	} else {
		v6 = nox_strman_loadString_40F1D0(internCStr("UserNotFound"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3921)
	}
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v6, v8)
	return 1
}
func sub_57A080(a1 *wchar2_t) int32 {
	if !noxflags.HasGame(2) {
		return 0
	}
	if a1 == nil {
		return 0
	}
	var v1 *byte = nox_xxx_playerByName_4170D0(a1)
	if v1 == nil || *(*byte)(unsafe.Add(unsafe.Pointer(v1), 2064)) == 31 {
		return 0
	}
	nox_xxx_netNeedTimestampStatus_4174F0((*server.Player)(unsafe.Pointer(v1)), 8)
	return 1
}
func sub_57A0C0(a1 *wchar2_t) int32 {
	if a1 == nil {
		return 0
	}
	var v1 *byte = nox_xxx_playerByName_4170D0(a1)
	if v1 == nil {
		return 0
	}
	nox_xxx_netNeedTimestampStatus_4174F0((*server.Player)(unsafe.Pointer(v1)), 4)
	return 1
}
func nox_cmd_mute(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v3 **wchar2_t
		v4 int32
		v5 int32
		v6 *wchar2_t
		v8 *wchar2_t
	)
	if tokCnt < 2 || tokCnt > 3 {
		return 0
	}
	v3 = (**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd)))
	if nox_client_consoleIsServer_823684 == 0 {
		v5 = sub_57A080(*v3)
	} else {
		if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd))), *(**wchar2_t)(memmap.PtrOff(0x587000, 94468+4*7))) != 0 {
			v5 = sub_57A080(*v3)
		} else {
			v4 = tokInd + 1
			if tokInd+1 != tokCnt-1 {
				return 0
			}
			v3 = (**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(v4)))
			v5 = sub_57A0C0(*v3)
		}
	}
	v8 = *v3
	if v5 != 0 {
		v6 = nox_strman_loadString_40F1D0(internCStr("Muted"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3961)
	} else {
		v6 = nox_strman_loadString_40F1D0(internCStr("UserNotFound"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 3959)
	}
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v6, v8)
	return 1
}
func nox_cmd_exec_rul(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	if tokCnt != 2 {
		return 0
	}
	buf, free := alloc.Make([]wchar2_t{}, 128)
	defer free()
	nox_wcscpy(&buf[0], *(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*1)))
	if nox_wcschr(&buf[0], 0x2E) == nil {
		nox_wcscat(&buf[0], internWStr(".rul"))
	}
	var s *wchar2_t = nox_strman_loadString_40F1D0(internCStr("ExecutingRul"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 4002)
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s, &buf[0])
	nox_xxx_doExecrul_4438A0(unsafe.Pointer(&buf[0]))
	return 1
}
func nox_xxx_serverHandleClientConsole_443E90(pl *server.Player, a2 int8, a3 *wchar2_t) int32 {
	var (
		v3     int32
		result int32
		v5     int32
		v6     *wchar2_t
		v7     int32
		v8     int32
		v9     *wchar2_t
		v10    *wchar2_t
		v11    int32
		v12    *wchar2_t
		v13    *wchar2_t
		v14    *byte
		v15    int32
		v16    *wchar2_t
		v17    *byte
		v18    *wchar2_t
		v19    int32
		v20    int32
		v21    *wchar2_t
		v22    [128]byte
	)
	if pl == nil || pl.PlayerUnit == nil {
		return 0
	}
	if a3 != nil {
		nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 818228)), a3)
	} else {
		*memmap.PtrUint16(0x5D4594, 818228) = 0
	}
	v3 = int32(uintptr(unsafe.Pointer(pl)))
	nox_console_playerWhoSent_823692 = pl
	if int32(a2) != 4 && int32(a2) != 5 && int32(a2) != 0 {
		if noxflags.HasGame(49152) {
			return 1
		}
	}
	switch a2 {
	case 0:
		if noxflags.HasGame(8) || noxflags.HasGame(4096) || int32(*(*uint8)(unsafe.Add(unsafe.Pointer(pl), 3680)))&1 != 0 {
			nox_console_playerWhoSent_823692 = nil
			return 1
		}
		v5 = bool2int32(int32(*memmap.PtrInt16(0x5D4594, 818228)) == -4083 && int32(*memmap.PtrInt16(0x5D4594, 818230)) == -3923 && int32(*memmap.PtrUint16(0x5D4594, 818232)) == 0)
		if nox_xxx_playerGoObserver_4E6860(pl, v5, 0) != 1 {
			nox_console_playerWhoSent_823692 = nil
			return 1
		}
		v6 = nox_strman_loadString_40F1D0(internCStr("set"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 4287)
		v7 = nox_xxx_gamePlayIsAnyPlayers_40A8A0()
		if v7 != 0 {
			if v5 == 0 {
				nox_xxx_netNeedTimestampStatus_4174F0(pl, 256)
			}
			if noxflags.HasGame(1024) && sub_40A770() == 1 {
				sub_5095E0()
			}
		}
		v8 = int32(uintptr(unsafe.Pointer(pl.PlayerUnit)))
		if v8 != 0 {
			nox_xxx_netChangeTeamMb_419570(unsafe.Add(v8, 48), int32(pl.NetCodeVal))
		}
		v21 = v6
		v9 = nox_strman_loadString_40F1D0(internCStr("observermode"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 4308)
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v9, v21)
		nox_console_playerWhoSent_823692 = nil
		return 1
	case 1:
		if sub_4D12A0(int32(pl.PlayerInd)) == 0 && uint32(pl.PlayerInd) != nox_player_netCode_85319C && !noxflags.HasGame(2048) {
			nox_console_playerWhoSent_823692 = nil
			return 1
		}
		nox_wcstok((*wchar2_t)(memmap.PtrOff(0x5D4594, 818228)), internWStr(" "))
		v10 = nox_wcstok(nil, internWStr(" "))
		nox_sprintf(&v22[0], internCStr("%S"), v10)
		v11 = nox_script_indexByEvent(&v22[0])
		if v11 != -1 && nox_console_playerWhoSent_823692 != nil {
			v12 = nox_strman_loadString_40F1D0(internCStr("ExecutingFunction"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 4332)
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v12, v10)
			nox_script_callByIndex_507310(v11, unsafe.Pointer(nox_console_playerWhoSent_823692.PlayerUnit), unsafe.Pointer(nox_console_playerWhoSent_823692.PlayerUnit))
			nox_console_playerWhoSent_823692 = nil
		} else {
			v21 = v10
			v9 = nox_strman_loadString_40F1D0(internCStr("InvalidFunction"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 4329)
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v9, v21)
			nox_console_playerWhoSent_823692 = nil
		}
		return 1
	case 2:
		if sub_4D12A0(int32(pl.PlayerInd)) == 0 && uint32(pl.PlayerInd) != nox_player_netCode_85319C && !noxflags.HasGame(2048) {
			nox_console_playerWhoSent_823692 = nil
			return 1
		}
		v19 = int32(uintptr(unsafe.Add(unsafe.Pointer(nox_console_playerWhoSent_823692), 4704)))
		v13 = nox_strman_loadString_40F1D0(internCStr("RemoteSysop"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 4345)
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v13, v19, a3)
		nox_server_parseCmdText_443C80(a3, 0)
		nox_console_playerWhoSent_823692 = nil
		return 1
	case 3:
		nox_xxx_printToAll_4D9FD0(0, a3)
		nox_console_playerWhoSent_823692 = nil
		return 1
	case 4:
		if (int32(*(*uint8)(unsafe.Add(v3, 3680)))&1) == 0 && !nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ) {
			if noxflags.HasGame(1) {
				v16 = nox_strman_loadString_40F1D0(internCStr("notinobserver"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 4392)
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v16)
				nox_console_playerWhoSent_823692 = nil
				return 1
			}
			nox_console_playerWhoSent_823692 = nil
			return 1
		}
		if *a3 == 0 {
			nox_xxx_playerCameraUnlock_4E6040((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v3, 2056))))
			nox_console_playerWhoSent_823692 = nil
			return 1
		}
		v17 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
		if v17 == nil {
			nox_console_playerWhoSent_823692 = nil
			return 1
		}
		for {
			if _nox_wcsicmp(a3, (*wchar2_t)(unsafe.Add(unsafe.Pointer(v17), unsafe.Sizeof(wchar2_t(0))*2352))) == 0 {
				nox_xxx_playerCameraFollow_4E6060(nox_console_playerWhoSent_823692.PlayerUnit, (*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v17), 4*514)))))))
			}
			v17 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(v17)))))
			if v17 == nil {
				break
			}
		}
		nox_console_playerWhoSent_823692 = nil
		return 1
	case 5:
		nox_xxx_printToAll_4D9FD0(16, a3)
		v14 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
		if v14 == nil {
			nox_console_playerWhoSent_823692 = nil
			return 1
		}
		for {
			v15 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*514))))
			if v15 != 0 {
				nox_xxx_aud_501960(902, (*server.Object)(v15), 0, 0)
			}
			v14 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(v14)))))
			if v14 == nil {
				break
			}
		}
		nox_console_playerWhoSent_823692 = nil
		return 1
	default:
		v20 = v3 + 4704
		v18 = nox_strman_loadString_40F1D0(internCStr("invalidattempt"), nil, internCStr("C:\\NoxPost\\src\\Client\\System\\parsecmd.c"), 4400)
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v18, v20, a3)
		nox_console_playerWhoSent_823692 = nil
		return 1
	}
	return result
}
func nox_cmd_offonly1(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	if tokCnt != 2 {
		return 0
	}
	nox_xxx_wndGuiTeamCreate_4185B0()
	return 1
}
func nox_cmd_offonly2(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		result int32
		v4     *byte
		v5     *wchar2_t
		v6     int32
		v7     *uint8
	)
	if tokCnt != 3 {
		return 0
	}
	result = int32(uintptr(memmap.PtrOff(0x5D4594, 822660)))
	if true {
		v4 = nox_xxx_cliGamedataGet_416590(1)
		v5 = *(**wchar2_t)(memmap.PtrOff(0x587000, 94400))
		v6 = 0
		if *memmap.PtrUint32(0x587000, 94400) != 0 {
			v7 = (*uint8)(memmap.PtrOff(0x587000, 94400))
			for _nox_wcsicmp(v5, *(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd)))) != 0 {
				v5 = (*wchar2_t)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*2))))))
				v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 8))
				v6++
				if v5 == nil {
					return 1
				}
			}
			*((*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*26))) &= 0xE80F
			*((*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*26))) |= *memmap.PtrUint16(0x587000, uintptr(v6*8)+94404)
		}
		result = 1
	}
	return result
}
func nox_cmd_set_net_debug(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	if tokCnt != 2 {
		return 0
	}
	nox_common_setEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)
	return 1
}
func nox_cmd_unset_net_debug(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	if tokCnt != 2 {
		return 0
	}
	nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)
	return 1
}
func nox_cmd_show_info(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100)
	sub_435F60()
	return 1
}
func nox_cmd_show_mem(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	nox_server_currentMapGetFilename_409B30()
	nox_xxx_gameLoopMemDump_413E30()
	return 1
}
func nox_cmd_show_rank(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	if noxflags.HasGame(0x2000) {
		sub_4703F0()
	}
	return 1
}
func nox_cmd_show_motd(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	if tokCnt != 2 {
		return 0
	}
	nox_xxx_motd_4467F0()
	return 1
}
func nox_cmd_show_seq(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	if tokCnt != 2 {
		return 0
	}
	sub_48D7B0()
	return 1
}
func nox_cmd_list_maps(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v0 *int32
		i  int32
		v2 bool
		v3 int32
	)
	libc.MemSet(memmap.PtrOff(0x5D4594, 822404), 0, 0x100)
	v0 = (*int32)(unsafe.Pointer(nox_common_maplist_first_4D09B0()))
	for i = 1; v0 != nil; i++ {
		sub_4417E0((*wchar2_t)(memmap.PtrOff(0x5D4594, 822404)), (*byte)(unsafe.Add(unsafe.Pointer(v0), 12)))
		if (i % 4) == 0 {
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (*wchar2_t)(memmap.PtrOff(0x587000, 103276)), memmap.PtrOff(0x5D4594, 822404))
			*memmap.PtrUint16(0x5D4594, 822404) = 0
		}
		v0 = (*int32)(unsafe.Pointer(nox_common_maplist_next_4D09C0((*Nox_map_list_item)(unsafe.Pointer(v0)))))
	}
	v3 = int32(uint32(i-1) & 0x80000003)
	v2 = v3 == 0
	if v3 < 0 {
		v2 = (uint32(int32(uint8(int8(v3)))-1) | 0xFFFFFFFC) == math.MaxUint32
	}
	if !v2 {
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (*wchar2_t)(memmap.PtrOff(0x587000, 103284)), memmap.PtrOff(0x5D4594, 822404))
	}
	return 1
}
func nox_cmd_cheat_ability(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var i *byte
	if !noxflags.HasGame(0x2000) {
		for i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); i != nil; i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(i))))) {
			if *((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*514))) != 0 {
				nox_xxx_playerCancelAbils_4FC180((*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*514)))))))
			}
		}
	}
	return 1
}
func nox_cmd_cheat_level(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		i  *byte
		v5 uint8
	)
	if !noxflags.HasGame(0x2000) {
		if tokCnt < 3 {
			return 0
		}
		for i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); i != nil; i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(i))))) {
			if *((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*514))) != 0 {
				v5 = uint8(int8(libc.WStrtol(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*2)), nil, 10)))
				sub_4EF410(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*514)), v5)
			}
		}
	}
	return 1
}
func nox_cmd_window(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v3 *wchar2_t
		v4 int32
		v6 int32
	)
	if tokCnt > 1 {
		v3 = *(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*uintptr(tokInd)))
		if *v3 != 43 && *v3 != 45 {
			v4 = int32(libc.WStrtol(v3, nil, 10))
			nox_draw_setCutSize_476700(v4, 0)
			return 1
		}
		v6 = int32(libc.WStrtol(v3, nil, 10))
		nox_draw_setCutSize_476700(0, v6)
	}
	return 1
}
func nox_cmd_set_qual_modem(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	dword_5d4594_2650652 = 1
	var v0 int32 = sub_40A710(4)
	nox_xxx_rateUpdate_40A6D0(v0)
	nox_server_connectionType_3596 = 4
	sub_4AD840()
	return 1
}
func nox_cmd_set_qual_isdn(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	dword_5d4594_2650652 = 1
	var v0 int32 = sub_40A710(3)
	nox_xxx_rateUpdate_40A6D0(v0)
	nox_server_connectionType_3596 = 3
	sub_4AD840()
	return 1
}
func nox_cmd_set_qual_cable(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	dword_5d4594_2650652 = 1
	var v0 int32 = sub_40A710(2)
	nox_xxx_rateUpdate_40A6D0(v0)
	nox_server_connectionType_3596 = 2
	sub_4AD840()
	return 1
}
func nox_cmd_set_qual_t1(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	dword_5d4594_2650652 = 1
	var v0 int32 = sub_40A710(1)
	nox_xxx_rateUpdate_40A6D0(v0)
	nox_server_connectionType_3596 = 1
	sub_4AD840()
	return 1
}
func nox_cmd_set_qual_lan(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	dword_5d4594_2650652 = nil
	var v0 int32 = sub_40A710(1)
	nox_xxx_rateUpdate_40A6D0(v0)
	nox_server_connectionType_3596 = 1
	sub_4AD840()
	return 1
}
func nox_cmd_set_time(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v4 *byte
		v5 *wchar2_t
		v6 uint8
	)
	if tokCnt != 3 {
		return 0
	}
	v4 = sub_4165B0()
	v5 = *(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*2))
	if v5 != nil {
		v6 = uint8(int8(libc.WStrtol(v5, nil, 10)))
		sub_40A040_settings(int16(*((*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*26)))), v6)
	}
	return 1
}
func nox_cmd_set_lessons(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	var (
		v4 *wchar2_t
		v5 *byte
		v6 uint16
	)
	if tokCnt != 3 {
		return 0
	}
	v4 = *(**wchar2_t)(unsafe.Add(unsafe.Pointer(tokens), unsafe.Sizeof((*wchar2_t)(nil))*2))
	v5 = sub_4165B0()
	if v4 != nil {
		v6 = uint16(int16(libc.WStrtol(v4, nil, 10)))
		sub_409FB0_settings(int16(*((*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*26)))), v6)
	}
	return 1
}
func nox_cmd_menu_options(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	if !noxflags.HasGame(8) && noxflags.HasGame(0x2000) {
		nox_xxx_guiServerOptsLoad_457500()
	}
	return 1
}
func nox_cmd_menu_vidopt(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	sub_4ADA40()
	return 1
}
func nox_cmd_reenter(tokInd int32, tokCnt int32, tokens **wchar2_t) int32 {
	if !noxflags.HasGame(0x2000) {
		sub_40AA60(1)
	}
	return 1
}
