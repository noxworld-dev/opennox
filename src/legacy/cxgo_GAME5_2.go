package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_server_makeServerInfoPacket_554040(inBuf *byte, inSz int32, out *byte) uint32 {
	if sub_43AF30() == 0 || sub_4D6F30() != 0 {
		return 0
	}
	game := nox_xxx_cliGamedataGet_416590(0)
	p := sub_416640()
	playerLimit := int8(nox_xxx_servGetPlrLimit_409FA0())
	playerCount := int8(nox_common_playerInfoCount_416F40())
	if nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
		playerCount--
		playerLimit--
	}
	srvName := nox_xxx_serverOptionsGetServername_40A4C0()
	var buf [72]byte
	buf[0] = 0
	buf[1] = 0
	buf[2] = byte(noxnet.MSG_SERVER_INFO)
	buf[3] = byte(playerCount)
	buf[4] = byte(playerLimit)
	buf[5] = p.Field101 & 0xF
	buf[6] = byte(int8(int32(p.Field101) >> 4))
	*(*[4]byte)(unsafe.Pointer(&buf[7])) = game.Field44
	libc.StrCpy(&buf[10], nox_xxx_mapGetMapName_409B40())
	buf[19] = byte(int8(int32(p.Field102) | sub_43BE50_get_video_mode_id()))
	buf[20] = p.Field100
	buf[21] = p.Field100 & 0x10
	*(*uint32)(unsafe.Pointer(&buf[24])) = p.Version48
	gameFlags := nox_common_gameFlags_getVal_40A5B0()
	if nox_xxx_isQuest_4D6F50() != 0 {
		gameFlags = (gameFlags & 0xFFFFFF7F) | 0x1000
		*(*uint16)(unsafe.Pointer(&buf[68])) = uint16(int16(nox_game_getQuestStage_4E3CC0()))
	}
	*(*uint32)(unsafe.Pointer(&buf[28])) = gameFlags
	*(*uint32)(unsafe.Pointer(&buf[32])) = game.Field48
	*(*uint16)(unsafe.Pointer(&buf[36])) = *(*uint16)(unsafe.Pointer(&p.Field105))
	*(*uint16)(unsafe.Pointer(&buf[38])) = *(*uint16)(unsafe.Pointer(&p.Field107))
	*(*uint32)(unsafe.Pointer(&buf[40])) = p.Field44
	*(*uint32)(unsafe.Pointer(&buf[44])) = *(*uint32)(unsafe.Add(unsafe.Pointer(inBuf), 8))
	alloc.Memcpy(unsafe.Pointer(&buf[48]), unsafe.Pointer(&game.Field24), 20)
	alloc.Memcpy(unsafe.Pointer(out), unsafe.Pointer(&buf[0]), 72)
	libc.StrCpy((*byte)(unsafe.Add(unsafe.Pointer(out), 72)), srvName)
	return uint32(libc.StrLen(srvName) + 72 + 1)
}
func sub_554290() uint32 {
	var (
		v0 uint32
		v1 int32
		v3 uint32
	)
	v0 = math.MaxUint32
	v1 = 0
	v2 := nox_common_playerInfoGetFirst_416EA0()
	if v2 == nil {
		return 0
	}
	for {
		if v2.PlayerInd != 31 && sub_554240(int32(v2.PlayerInd)) > 0 {
			v3 = uint32(sub_554240(int32(v2.PlayerInd)))
			if v3 < v0 {
				v0 = v3
			}
			v1++
		}
		v2 = nox_common_playerInfoGetNext_416EE0(v2)
		if v2 == nil {
			break
		}
	}
	if v1 != 0 {
		return v0
	} else {
		return 0
	}
}
func sub_554300() int32 {
	var (
		v0 int32
		v1 int32
	)
	v0 = 0
	v1 = 0
	v2 := nox_common_playerInfoGetFirst_416EA0()
	if v2 == nil {
		return 0
	}
	for {
		if v2.PlayerInd != 31 && sub_554240(int32(v2.PlayerInd)) > 0 {
			v0 += sub_554240(int32(v2.PlayerInd))
			v1++
		}
		v2 = nox_common_playerInfoGetNext_416EE0(v2)
		if v2 == nil {
			break
		}
	}
	if v1 != 0 {
		return v0 / v1
	} else {
		return 0
	}
}

func sub_56F4F0(a1 *uint32) {
	if sub_56F510(*a1) != 0 {
		*a1 = 0
	}
}
func sub_56FB60(item *server.Object) int32 {
	var (
		result int32
		v2     int32
		v3     int32
		v4     int32
		v6     int32
	)
	result = 0
	if item == nil {
		return result
	}
	v2 = sub_4E4C00(item)
	v3 = int32(uint16(nox_xxx_unitGetHP_4EE780(item))) ^ v2
	v4 = sub_4E4C10(item) ^ v3
	v5 := (*byte)(unsafe.Pointer(uintptr(nox_object_getInitData_4E4C30(item))))
	v6 = sub_4E4C50(item)
	if v5 != nil && v6 > 0 {
		v4 ^= int32(nox_xxx_protectionStringCRC_56FAC0(v5, uint32(v6)))
	}
	v7 := sub_4E4C80(item)
	if v7 != nil {
		if libc.StrLen(v7) != 0 {
			v4 ^= int32(nox_xxx_protectionStringCRC_56FAC0(v7, uint32(libc.StrLen(v7))))
		}
	}
	result = v4
	return result
}
func nox_xxx_netGetUnitCodeCli_578B00(a1 *client.Drawable) uint32 {
	if a1 == nil {
		return 0
	}
	code := a1.NetCode32
	if code >= 0x8000 {
		return 0
	}
	if a1.Flags28()&0x20400000 != 0 {
		code |= 0x8000
	}
	return code
}
func nox_xxx_netClearHighBit_578B30(a1 int16) int32 {
	return int32(a1 & 0x7FFF)
}
func nox_xxx_packetDynamicUnitCode_578B40(a1 int32) int32 {
	var (
		result int32
	)
	result = a1
	if (a1 & 0x8000) != 0x8000 {
		return result
	}
	*(*uint8)(unsafe.Add(unsafe.Pointer(&result), 1)) &= math.MaxInt8
	v2 := nox_xxx_netGetUnitByExtent_4ED020(result)
	if v2 != nil {
		result = int32(v2.NetCode)
	} else {
		result = 0
	}
	return result
}
func nox_xxx_netTestHighBit_578B70(a1 uint32) uint32 {
	return (a1 >> 15) & 1
}
func nox_xxx_waypointNext_579870(a1 *server.Waypoint) *server.Waypoint {
	if a1 != nil {
		return a1.WpNext
	} else {
		return nil
	}
}
func sub_579E70() *server.Waypoint {
	wp, _ := alloc.New(server.Waypoint{})
	if wp != nil {
		wp.Flags |= 0x1000000
	}
	return wp
}
func sub_579EE0(a1 *server.Waypoint, a2 uint8) int32 {
	return bool2int32((int32(a2) & int32(a1.Flags2)) != 0)
}
func nox_xxx_playerCanTalkMB_57A160(a1 int32) int32 {
	var result int32
	if a1 != 0 && noxflags.HasGame(2) {
		result = int32((*(*uint32)(unsafe.Add(a1, 3680)) >> 3) & 1)
	} else {
		result = 0
	}
	return result
}
func sub_57A1B0(a1 int16) *byte {
	var (
		v1 int32
		v2 *uint8
	)
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x587000, 312212))
	for uint32(int32(a1)&0x17F0) != *(*uint32)(unsafe.Pointer(v2)) {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 8))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 312268))) {
			return nil
		}
	}
	return *(**byte)(memmap.PtrOff(0x587000, uintptr(v1*8)+312208))
}
func sub_57A1E0(a1 *MapListXxx, a2 *byte, a3 *int32, a4 int8, a5 int16) {
	var (
		v5 *int32
		v6 int32
		v7 uint8
	)
	var v8 *byte
	var v9 int32
	var v10 int32
	var v12 uint8
	v5 = a3
	v6 = int32(a5) & 0x17F0
	if a3 != nil {
		sub_57ADF0(a3)
	}
	a1.Field24[0] = -1
	a1.Field24[1] = -1
	a1.Field24[2] = -1
	a1.Field24[3] = -1
	a1.Field24[4] = -1
	a1.Field44 = -1
	a1.Field48 = -1
	if int32(a4)&3 != 0 {
		var v14 [256]byte
		var v15 [256]byte
		libc.StrCpy(&v14[0], internCStr("maps\\"))
		libc.StrNCat(&v14[0], &a1.Field0[0], 8)
		libc.StrCat(&v14[0], internCStr("\\"))
		if int32(a4)&2 != 0 {
			libc.StrCpy(&v15[0], &v14[0])
			if a2 != nil {
				libc.StrCat(&v15[0], a2)
			} else {
				libc.StrCat(&v15[0], internCStr("user.rul"))
			}
			v10 = sub_57A3F0(&v15[0], a1, int32(uintptr(unsafe.Pointer(a3))), v6)
			v5 = a3
		} else {
			v10 = 0
		}
		if int32(a4)&1 != 0 && v10 == 0 {
			libc.StrNCat(&v14[0], &a1.Field0[0], 8)
			libc.StrNCat(&v14[0], internCStr(".rul"), math.MaxUint8)
			sub_57A3F0(&v14[0], a1, int32(uintptr(unsafe.Pointer(v5))), v6)
		}
	}
	if dword_5d4594_2650652 != 0 && int32(a4)&4 != 0 {
		sub_57A3F0(internCStr("internet.rul"), a1, int32(uintptr(unsafe.Pointer(v5))), v6)
	}
	if int32(a5)&0x40 != 0 {
		sub_453FA0(unsafe.Add(unsafe.Pointer(a1), 4*6), 132, 0)
	}
}
func sub_57A3F0(a1 *byte, a2 *MapListXxx, a3 int32, a4 int32) int32 {
	var (
		v4 *FILE
		v5 *FILE
		v6 *byte
		v8 [256]byte
		v9 [256]wchar2_t
	)
	dword_5d4594_2523764 = 6128
	v4 = nox_fs_open_text(a1)
	v5 = v4
	if v4 == nil {
		return 0
	}
	if !nox_fs_feof(v4) {
		for {
			*(*[256]byte)(unsafe.Pointer(&v8[0])) = [256]byte{}
			nox_fs_fgets(v5, &v8[0], 256)
			v6 = libc.StrChr(&v8[0], 10)
			if v6 != nil {
				*v6 = 0
			}
			if v8[0] != 0 {
				nox_swprintf(&v9[0], internWStr("%S"), &v8[0])
				sub_57A4D0(&v9[0], a2, a3, a4)
			}
			if nox_fs_feof(v5) {
				break
			}
		}
	}
	nox_fs_close(v5)
	return 1
}
func sub_57A4D0(a1 *wchar2_t, a2 *MapListXxx, a3 int32, a4 int32) {
	var (
		v4     uint8
		v5     int32
		result *wchar2_t
		v7     *wchar2_t
		v8     int32
		v9     *wchar2_t
		v10    *wchar2_t
		v11    uint8
		v12    [32]int32
		v13    [256]wchar2_t
	)
	v4 = 0
	v5 = 0
	v11 = 0
	sub_416580()
	result = nox_wcscpy(&v13[0], a1)
	if true {
		if v13[0] == 34 {
			result = nox_wcstok(&v13[1], internWStr("\"\n\r"))
			v7 = result
			v5 = 1
		} else {
			result = nox_wcstok(&v13[0], internWStr(" \n\t\r"))
			v7 = result
		}
		if v7 != nil {
			for {
				v8 = int32(v11)
				v11 = func() uint8 {
					p := &v4
					*p++
					return *p
				}()
				v12[v8] = int32(uintptr(unsafe.Pointer(v7)))
				v9 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(wchar2_t(0))*uintptr(nox_wcslen(v7)+1)))
				if v5 != 0 {
					v9 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(wchar2_t(0))*1))
				}
				if *v9 == 34 {
					result = nox_wcstok((*wchar2_t)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(wchar2_t(0))*1)), internWStr("\"\n\r"))
					v7 = result
					v5 = 1
				} else {
					result = nox_wcstok(nil, internWStr(" \n\t\r"))
					v7 = result
					v5 = 0
				}
				if v7 == nil {
					break
				}
			}
			if int32(v4) != 0 {
				result = (*wchar2_t)(unsafe.Pointer(uintptr(sub_57A620(v4, (**wchar2_t)(unsafe.Pointer(&v12[0])), a2, a4))))
				if result == nil {
					if a3 != 0 {
						v10 = (*wchar2_t)(alloc.Calloc1(1, 0x20C))
						nox_wcscpy((*wchar2_t)(unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(wchar2_t(0))*6)), a1)
						nox_common_list_append_4258E0((*nox_list_item_t)(a3), (*nox_list_item_t)(unsafe.Pointer(v10)))
					}
				}
			}
		}
	}
}
func sub_57A620(a1 uint8, a2 **wchar2_t, a3 *MapListXxx, a4 int32) int32 {
	var (
		v4  **wchar2_t
		v5  uint8
		v6  int32
		v9  int32
		v10 int32
		v11 uint8
		v12 int32
		v14 int32
		v16 [100]byte
		v17 uint8
		v18 uint8
	)
	v4 = a2
	nox_sprintf(&v16[0], internCStr("%S"), *a2)
	v5 = 0
	v17 = 0
	for {
		if libc.StrCmp(*(**byte)(memmap.PtrOff(0x587000, uintptr(int32(v17)*8)+312208)), &v16[0]) == 0 {
			dword_5d4594_2523764 = *memmap.PtrUint32(0x587000, uintptr(int32(v17)*8)+312212)
			return bool2int32(uint32(a4) == dword_5d4594_2523764)
		}
		v17 = func() uint8 {
			p := &v5
			*p++
			return *p
		}()
		if int32(v5) >= 7 {
			break
		}
	}
	if (dword_5d4594_2523764&uint32(a4)) == 0 || _nox_wcsicmp(*v4, internWStr("set")) != 0 || int32(a1) <= 1 {
		return 0
	}
	if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*1)), internWStr("spell")) != 0 {
		if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*1)), internWStr("weapon")) != 0 {
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*1)), internWStr("armor")) != 0 {
				return 0
			}
			if int32(a1) != 4 {
				return 0
			}
			if !noxflags.HasGame(1) {
				return 0
			}
			nox_sprintf(&v16[0], internCStr("%S"), *(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*2)))
			var v13 int32 = sub_415EC0(&v16[0])
			if v13 < 0 {
				return 0
			}
			v14 = int32(sub_415D10(uint32(v13)))
			if v14 == 0 {
				return 0
			}
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*3)), internWStr("off")) != 0 {
				a3.Field48 = uint32(v14) | a3.Field48
			} else {
				a3.Field48 = uint32(v14) &^ a3.Field48
			}
		} else {
			if int32(a1) != 4 {
				return 0
			}
			if !noxflags.HasGame(1) {
				return 0
			}
			nox_sprintf(&v16[0], internCStr("%S"), *(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*2)))
			var v8 int32 = sub_415A30(&v16[0])
			if v8 < 0 {
				return 0
			}
			v9 = int32(nox_xxx_ammoCheck_415880(uint16(int16(v8))))
			v10 = v9
			if v9 == 0 {
				return 0
			}
			v11 = 0
			v18 = 0
			if v9 > 0 {
				for {
					v12 = v10 >> 8
					if v10>>8 > 0 {
						v10 >>= 8
					}
					v11++
					if v12 <= 0 {
						break
					}
				}
				v18 = v11
			}
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*3)), internWStr("off")) != 0 {
				*(*uint8)(unsafe.Add(unsafe.Pointer(a3), uintptr(int32(v18))+43)) |= uint8(int8(v10))
			} else {
				*(*uint8)(unsafe.Add(unsafe.Pointer(a3), uintptr(int32(v18))+43)) &^= uint8(int8(v10))
			}
		}
	} else {
		if int32(a1) != 4 {
			return 0
		}
		nox_sprintf(&v16[0], internCStr("%S"), *(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*2)))
		v6 = nox_xxx_spellNameToN_4243F0(&v16[0])
		if v6 == 0 {
			v6 = nox_xxx_spellByTitle_424960(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*2)))
			if v6 == 0 {
				return 0
			}
		}
		if !nox_xxx_spellIsValid_424B50(v6) {
			return 0
		}
		if nox_xxx_spellFlags_424A70(v6)&0x7000000 != 0 {
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*3)), internWStr("off")) == 0 {
				sub_453FA0(a3+24, v6, 0)
			}
		}
	}
	if uint32(a4) == dword_5d4594_2523764 {
		return 1
	}
	return 0
}
func sub_57A950(a1 *byte) int32 {
	var v2 [256]byte
	libc.StrCpy(&v2[0], internCStr("maps\\"))
	libc.StrNCat(&v2[0], a1, 256-6)
	v2[libc.StrLen(&v2[0])-4] = 0
	libc.StrNCat(&v2[0], internCStr("\\"), 256-4)
	libc.StrCat(&v2[0], a1)
	return sub_4D0550(&v2[0])
}
func sub_57A9F0(a1 *byte, a2 *byte) int32 {
	var FileName [256]byte
	libc.StrCpy(&FileName[0], internCStr("maps\\"))
	libc.StrCat(&FileName[0], a1)
	libc.StrCat(&FileName[0], internCStr("\\"))
	libc.StrCat(&FileName[0], a2)
	return bool2int32(nox_fs_remove(&FileName[0]))
}
func sub_57AAA0(a1 *byte, a2 *byte, a3 *int32) int8 {
	var (
		v3       *FILE
		v4       *FILE
		i        *int32
		v6       *byte
		v7       int32
		v8       int32
		v9       *byte
		v10      int32
		v11      int32
		v12      *byte
		v13      int32
		v14      int32
		v15      *byte
		v16      *byte
		v18      int32
		v19      [24]byte
		v20      [36]byte
		v21      [24]byte
		v22      [36]byte
		v23      [256]byte
		FileName [256]byte
	)
	*((*uint8)(unsafe.Pointer(&v3))) = *(*byte)(unsafe.Add(unsafe.Pointer(a2), 52))
	if int32(int8(uintptr(unsafe.Pointer(v3)))) < 0 {
		return int8(uintptr(unsafe.Pointer(v3)))
	}
	libc.StrCpy(&FileName[0], internCStr("maps\\"))
	libc.StrNCat(&FileName[0], a2, 8)
	libc.StrNCat(&FileName[0], internCStr("\\"), 10)
	libc.StrCat(&FileName[0], a1)
	v3 = nox_fs_create_text(&FileName[0])
	v4 = v3
	if v3 == nil {
		return int8(uintptr(unsafe.Pointer(v3)))
	}
	if dword_5d4594_2650652 != 0 {
		libc.StrCpy(&v21[0], a2)
		libc.StrCpy(&v19[0], a2)
		sub_57A1E0((*int32)(unsafe.Pointer(&v21[0])), nil, nil, 4, int16(*((*uint16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(uint16(0))*26)))))
		sub_57A1E0((*int32)(unsafe.Pointer(&v19[0])), nil, nil, 3, int16(*((*uint16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(uint16(0))*26)))))
	}
	if a3 != nil {
		for i = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(a3))))); i != nil; i = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(i))))) {
			nox_sprintf(&v23[0], internCStr("%S\n"), (*int32)(unsafe.Add(unsafe.Pointer(i), 4*3)))
			nox_fs_fputs(v4, &v23[0])
		}
	}
	v6 = sub_57A1B0(int16(*((*uint16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(uint16(0))*26)))))
	nox_fs_fputs(v4, v6)
	nox_fs_fputs(v4, internCStr("\n"))
	v7 = 1
	v8 = 136
	for {
		if nox_xxx_spellIsValid_424B50(v7) && sub_454000(unsafe.Add(unsafe.Pointer(a2), 24), v7) == 0 && nox_xxx_spellFlags_424A70(v7)&0x7000000 != 0 && (dword_5d4594_2650652 == nil || sub_454000(unsafe.Pointer(&v22[0]), v7) != 0 || sub_454000(unsafe.Pointer(&v20[0]), v7) == 0) {
			v9 = nox_xxx_spellNameByN_424870(v7)
			nox_sprintf(&v23[0], internCStr("%s %s \"%s\" %s\n"), "set", "spell", v9, "off")
			nox_fs_fputs(v4, &v23[0])
		}
		v7++
		v8--
		if v8 == 0 {
			break
		}
	}
	v10 = 1
	v11 = 26
	for {
		if (uint32(v10) & *((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*12)))) == 0 {
			v12 = sub_415E40(uint32(v10))
			if v12 != nil {
				nox_sprintf(&v23[0], internCStr("%s %s \"%s\" %s\n"), "set", "Armor", v12, "off")
				nox_fs_fputs(v4, &v23[0])
			}
		}
		v10 *= 2
		v11--
		if v11 == 0 {
			break
		}
	}
	v13 = 1
	v14 = 1
	v18 = 27
	v15 = (*byte)(unsafe.Add(unsafe.Pointer(a2), 44))
	for {
		if (int32(uint8(int8(v13))) & int32(*v15)) == 0 {
			v16 = sub_4159B0((*byte)(v14))
			if v16 != nil {
				nox_sprintf(&v23[0], internCStr("%s %s \"%s\" %s\n"), "set", "weapon", v16, "off")
				nox_fs_fputs(v4, &v23[0])
			}
		}
		if v13 == 128 {
			v13 = 1
			v15 = (*byte)(unsafe.Add(unsafe.Pointer(v15), 1))
		} else {
			v13 *= 2
		}
		v14 *= 2
		v18--
		if v18 == 0 {
			break
		}
	}
	*((*uint8)(unsafe.Pointer(&v3))) = 0
	nox_fs_close(v4)
	return int8(uintptr(unsafe.Pointer(v3)))
}
func sub_57ADF0(a1 *int32) *int32 {
	var (
		result *int32
		v2     *int32
		v3     *int32
	)
	result = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(a1)))))
	v2 = result
	if result == nil {
		return result
	}
	for {
		v3 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v2)))))
		nox_common_list_remove_425920(unsafe.Pointer(v2))
		alloc.Free(v2)
		v2 = v3
		if v3 == nil {
			break
		}
	}
	return result
}
func sub_57AE30(a1 *byte) int32 {
	var (
		v1 int32
		v2 **byte
	)
	v1 = 0
	v2 = (**byte)(memmap.PtrOff(0x587000, 312208))
	for libc.StrCmp(*v2, a1) != 0 {
		v2 = (**byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((*byte)(nil))*2))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 312264))) {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*8)+312212))
}
func nox_xxx_playerCheckSpellClass_57AEA0(a1 int32, a2 int32) int32 {
	var (
		v2     int32
		result int32
		v4     int32
	)
	v2 = int32(nox_xxx_spellFlags_424A70(a2))
	if a1 == 1 {
		v4 = 0x2000000
	} else {
		if a1 != 2 {
			return 9
		}
		v4 = 0x4000000
	}
	if uint32(v2)&0x1000000 != 0 || v4&v2 != 0 {
		result = 0
	} else {
		result = 9
	}
	return result
}
func nox_xxx_get_57AF20() int32 {
	return int32(dword_5d4594_2523804)
}
func sub_57B0A0() {
	var (
		result int32
		v1     *uint32
	)
	result = int32(dword_5d4594_2523804)
	if result == 0 {
		return
	}
	v1 = (*uint32)(dword_5d4594_2523780)
	if dword_5d4594_2523780 != nil && (*memmap.PtrUint32(0x5D4594, 2523772) == 0 || *memmap.PtrUint32(0x5D4594, 2523772) == 1) {
		nox_xxx_netSendPointFx_522FF0(-102, (*types.Pointf)(unsafe.Add(unsafe.Pointer(dword_5d4594_2523780), 56)))
		v1 = (*uint32)(dword_5d4594_2523780)
	}
	if dword_5d4594_2523776 != nil {
		nox_xxx_delayedDeleteObject_4E5CC0(dword_5d4594_2523776)
		v1 = (*uint32)(dword_5d4594_2523780)
	}
	dword_5d4594_2523776 = nil
	if v1 != nil {
		nox_xxx_playerSetState_4FA020((*server.Object)(unsafe.Pointer(v1)), 13)
	}
	dword_5d4594_2523780 = nil
	if sub_45D9B0() == 0 {
		sub_413A00(0)
	}
	dword_5d4594_2523804 = 0
}
func nox_xxx___Getcvt_57B180() int64 {
	return int64(*memmap.PtrUint64(0x5D4594, 2523788))
}
func sub_57B190(a1 uint16, a2 uint16) int32 {
	var (
		result int32
		v3     float64
		v4     float64
	)
	if int32(a2) == 0 {
		return 4
	}
	if int32(a1) == int32(a2) {
		return 0
	}
	v3 = float64(a1)
	v4 = float64(a2)
	if v3 >= v4*qword_581450_9544 {
		return 1
	}
	result = 2
	if v3 < v4**memmap.PtrFloat64(0x581450, 9608) {
		result = 3
	}
	return result
}
func sub_57B350() *float32 {
	return memmap.PtrFloat32(0x5D4594, 2523812)
}
func nox_xxx_plrGetMaxVarsPtr_57B360(a1 int32) *float32 {
	return memmap.PtrFloat32(0x5D4594, uintptr(uint32(a1*16)+2523828))
}
func sub_57B370(cl object.Class, sub object.SubClass, typ int32) byte {
	if cl.HasAny(object.ClassWeapon | object.ClassWand) {
		m := nox_xxx_getProjectileClassById_413250(typ)
		if m == nil {
			return 0
		}
		return m.Classes62
	}
	if cl.Has(object.ClassArmor) {
		m := nox_xxx_equipClothFindDefByTT_413270(typ)
		if m == nil {
			return 0
		}
		return m.Classes62
	}
	if cl.Has(object.ClassFood) {
		return byte(^(uint32(sub) >> 5) | 0xFE)
	}
	return 0xFF
}

var nox_cheat_allowall int32 = 0

func nox_xxx_playerClassCanUseItem_57B3D0(item *server.Object, cl player.Class) int32 {
	if nox_cheat_allowall != 0 {
		return 1
	}
	return bool2int32(((byte(1) << cl) & sub_57B370(item.Class(), item.SubClass(), int32(item.TypeInd))) != 0)
}
func nox_xxx_client_57B400(a1 *client.Drawable) int32 {
	var v1 int32
	v1 = int32(*memmap.PtrUint32(0x5D4594, 2523876))
	if *memmap.PtrUint32(0x5D4594, 2523876) == 0 {
		v1 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Glyph"))
		*memmap.PtrUint32(0x5D4594, 2523876) = uint32(v1)
	}
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 {
		return 0
	}
	if a1.TypeIDVal != uint32(v1) || int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))) == 1 {
		return 1
	}
	return 0
}
func sub_57B450(a1p *client.Drawable) int32 {
	var (
		a1 *int32 = (*int32)(unsafe.Pointer(a1p))
		v1 int32
		v2 uint8
	)
	v1 = int32(*memmap.PtrUint32(0x5D4594, 2523880))
	if *memmap.PtrUint32(0x5D4594, 2523880) == 0 {
		v1 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Glyph"))
		*memmap.PtrUint32(0x5D4594, 2523880) = uint32(v1)
	}
	if a1 == nil || *memmap.PtrUint32(0x852978, 8) == 0 || *memmap.PtrUint32(0x8531A0, 2576) == 0 || *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*27)) == v1 && int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))) != 1 {
		return 0
	}
	if nox_cheat_allowall != 0 {
		return 1
	}
	v2 = uint8(int8(1 << int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251)))))
	return bool2int32((int32(v2) & int32(uint8(sub_57B370(object.Class(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*28))), object.SubClass(uint8(int8(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*29))))), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*27)))))) != 0)
}
func sub_57B630(a1 *server.Object, x int32, y int32) int8 {
	if x < 0 || x >= 256 || y < 0 || y >= 256 {
		return -1
	}
	wl := nox_xxx_wall_4105E0(x, y)
	if wl == nil {
		return -1
	}
	if wl.Flags4&0x10 != 0 {
		obj := AsObjectP(wl.Data28)
		if obj != nil {
			ud := obj.UpdateData
			v7 := *(*uint32)(unsafe.Add(ud, 12))
			if v7 == *(*uint32)(unsafe.Add(ud, 4)) {
				v8 := *memmap.PtrInt32(0x587000, uintptr(v7*8)+196184)
				v9 := v8 < 0
				v10 := v8 <= 0
				if v8 > 0 {
					if *memmap.PtrInt32(0x587000, uintptr(v7*8)+196188) > 0 {
						if obj.ObjOwner != nil {
							if nox_common_randomInt_415FA0(0, 100) >= 50 {
								return 1
							}
						} else {
							if int32(*(*uint8)(unsafe.Add(ud, 1))) != 0 && nox_xxx_doorGetSomeKey_4E8910(a1, obj) == nil {
								return 1
							}
						}
						return -1
					}
					v9 = v8 < 0
					v10 = v8 <= 0
				}
				if v9 {
					if *memmap.PtrInt32(0x587000, uintptr(v7*8)+196188) < 0 {
						if obj.ObjOwner != nil {
							if nox_common_randomInt_415FA0(0, 100) >= 50 {
								return 1
							}
						} else {
							if int32(*(*uint8)(unsafe.Add(ud, 1))) != 0 && nox_xxx_doorGetSomeKey_4E8910(a1, obj) == nil {
								return 1
							}
						}
						return -1
					}
					v10 = v8 <= 0
					if v8 < 0 {
						if *memmap.PtrInt32(0x587000, uintptr(v7*8)+196188) > 0 {
							if obj.ObjOwner != nil {
								if nox_common_randomInt_415FA0(0, 100) >= 50 {
									return 0
								}
							} else {
								if int32(*(*uint8)(unsafe.Add(ud, 1))) != 0 && nox_xxx_doorGetSomeKey_4E8910(a1, obj) == nil {
									return 0
								}
							}
							return -1
						}
						v10 = v8 <= 0
					}
				}
				if !v10 && *memmap.PtrInt32(0x587000, uintptr(v7*8)+196188) < 0 {
					if obj.ObjOwner != nil {
						if nox_common_randomInt_415FA0(0, 100) >= 50 {
							return 0
						}
					} else {
						if int32(*(*uint8)(unsafe.Add(ud, 1))) != 0 && nox_xxx_doorGetSomeKey_4E8910(a1, obj) == nil {
							return 0
						}
					}
					return -1
				}
			}
		}
	} else if (a1.ObjFlags&0x4000) == 0 || (wl.Flags4&0x40) == 0 {
		if (wl.Flags4 & 4) == 0 {
			return int8(wl.Dir0)
		}
		v13 := wl.Data28
		if (int32(*(*uint8)(unsafe.Add(v13, 20)))&2) == 0 && int32(*(*uint8)(unsafe.Add(v13, 22))) <= 11 {
			return int8(wl.Dir0)
		}
	}
	return -1
}
func sub_57B770(a1 *types.Pointf, a2 *types.Pointf) {
	v9 := a2.X
	v3 := math.Sqrt(float64(a2.X*a2.X + a2.Y*a2.Y))
	v4 := v3 + 0.1
	v5 := float64(-a2.Y)
	v6 := float64(a1.X*a2.X+a1.Y*a2.Y) / (v3 + 0.1)
	v11 := float32((float64(a2.X*a1.Y) + v5*float64(a1.X)) / v4)
	v7 := float32(v6 * float64(a2.X) / v4)
	v8 := float32(v6 * float64(a2.Y) / v4)
	v10 := float32(float64(v11) * v5 / v4)
	a1.X = v10 - v7
	a1.Y = float32(float64(v11*v9)/v4 - float64(v8))
}
func nox_xxx_collideReflect_57B810(a1 *types.Pointf, a2 *types.Pointf) {
	if a1.Y*a1.X <= 0.0 {
		a2.X, a2.Y = a2.Y, a2.X
	} else {
		a2.X, a2.Y = -a2.Y, -a2.X
	}
}
func nox_xxx_map_57B850(a1 *types.Pointf, a2 *server.Shape, a3 *types.Pointf) int32 {
	var (
		v4 float32
		v5 float32
		v6 float32
		v7 float32
	)
	v4 = a2.Box.LeftTop + a1.X
	v5 = a2.Box.LeftBottom + a1.Y
	if !(float64(v5-v4+a3.X-a3.Y)*0.70709997 < 0.0 && float64(a2.Box.LeftTop2+a1.Y-(a2.Box.LeftBottom2+a1.X)+a3.X-a3.Y)*0.70709997 > 0.0) {
		return 0
	}
	v6 = a2.Box.RightTop + a1.X
	v7 = a2.Box.RightBottom + a1.Y
	if float64(v7+v6-a3.X-a3.Y)*0.70709997 > 0.0 && float64(v5+v4-a3.X-a3.Y)*0.70709997 < 0.0 {
		return 1
	}
	return 0
}
func sub_57B920(a1 unsafe.Pointer) int32 {
	var result int32
	result = 0
	libc.MemSet(a1, 0, 0x7F8)
	return result
}
func nox_xxx_cliGenerateAlias_57B9A0(a1 int32, a2 int32, a3 int32, a4 uint32) int8 {
	var (
		v4 int32
		v5 int32
	)
	v4 = int32(uint8(int8(a2)))
	v5 = int32(uint8(int8(a2)))
	if int32(uint8(int8(a2))) == math.MaxUint8 || int32(uint8(int8(a2))) == 0 {
		v4 = 1
		v5 = 1
	}
	for (int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + v4*8)))) != a2 || int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a1+v4*8)), 2))) != a3) && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1+v4*8)), 4)) >= a4 {
		if func() int32 {
			p := &v4
			*p++
			return *p
		}() == math.MaxUint8 {
			v4 = 1
		}
		if v4 == v5 {
			*((*uint8)(unsafe.Pointer(&v4))) = math.MaxUint8
			return int8(v4)
		}
	}
	return int8(v4)
}
func sub_57BA10(a1 int32, a2 int16, a3 int16, a4 int32) int32 {
	var result int32
	result = a1
	*(*uint16)(a1) = uint16(a2)
	*(*uint16)(unsafe.Add(a1, 2)) = uint16(a3)
	*(*uint32)(unsafe.Add(a1, 4)) = uint32(a4)
	return result
}
func nox_server_getNextMapGroup_57C090(a1 *server.MapGroup) *server.MapGroup {
	return a1.Next()
}
func sub_57C790(a1 *float4, a2 *types.Pointf, a3 *types.Pointf, a4 float32) {
	var (
		v4  float64
		v5  float64
		v6  float64
		v7  float64
		v8  float32
		v9  float32
		v10 float32
		v11 float32
		v12 float32
		v13 float32
	)
	v8 = a1.field_8 - a1.field_0
	v4 = float64(a1.field_C - a1.field_4)
	v9 = float32(v4)
	v5 = v4*float64(a2.Y-a1.field_4) + float64(v8*(a2.X-a1.field_0))
	v6 = float64(a4 * a4)
	v10 = float32(v5 * float64(v8) / v6)
	a3.X = v10 + a1.field_0
	a3.Y = float32(v5*float64(v9)/v6 + float64(a1.field_4))
	if float64(a1.field_0) >= float64(a1.field_8) {
		v12 = a1.field_0
		v13 = a1.field_8
	} else {
		v13 = a1.field_0
		v12 = a1.field_8
	}
	if float64(a1.field_4) >= float64(a1.field_C) {
		v7 = float64(a1.field_C)
		v11 = a1.field_4
	} else {
		v7 = float64(a1.field_4)
		v11 = a1.field_C
	}
	if float64(a3.X) >= float64(v13) {
		if float64(a3.X) > float64(v12) {
			a3.X = v12
		}
	} else {
		a3.X = v13
	}
	if v7 <= float64(a3.Y) {
		if float64(a3.Y) > float64(v11) {
			a3.Y = v11
		}
	} else {
		a3.Y = float32(v7)
	}
}
func nox_xxx_mathPointOnTheLine_57C8A0(a1 *float4, a2 *types.Pointf, a3 *types.Pointf) int32 {
	var (
		v3  *float4
		v4  *types.Pointf
		v5  float64
		v6  float64
		v7  float64
		v8  float64
		v10 float32
		v11 float32
		v12 float32
		v13 float32
		v14 float32
		v15 float32
		v16 float32
		v17 float32
	)
	v3 = a1
	v4 = a3
	v5 = float64(a1.field_8 - a1.field_0)
	v6 = float64(a1.field_C - a1.field_4)
	v12 = float32(v6)
	v10 = float32(v6*float64(v12) + v5*v5)
	v7 = float64((a2.Y-a1.field_4)*v12) + float64(a2.X-a1.field_0)*v5
	v14 = float32(v7)
	v13 = v14 * v12 / v10
	a3.X = float32(v5*v7/float64(v10) + float64(v3.field_0))
	v15 = v13 + v3.field_4
	a3.Y = v15
	if float64(v3.field_0) >= float64(v3.field_8) {
		v8 = float64(v3.field_8)
		v16 = v3.field_0
	} else {
		v8 = float64(v3.field_0)
		v16 = v3.field_8
	}
	if float64(v3.field_4) >= float64(v3.field_C) {
		v11 = v3.field_4
		v17 = v3.field_C
	} else {
		v17 = v3.field_4
		v11 = v3.field_C
	}
	return bool2int32(v8 <= float64(v4.X) && float64(v4.X) <= float64(v16) && float64(v15) >= float64(v17) && float64(v15) <= float64(v11))
}
func sub_57CDB0(a1 *Point32, a2 *float32, a3 *types.Pointf) int32 {
	var (
		v3     *Point32
		v4     int8
		result int32
		v6     *types.Pointf
		v7     *types.Pointf
		v8     *types.Pointf
		v9     int8
	)
	v3 = a1
	v9 = int8(sub_57F2A0((*types.Pointf)(unsafe.Pointer(a2)), a1.X, a1.Y))
	v4 = sub_57F1D0((*types.Pointf)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(types.Pointf{})*1)))
	switch sub_57B500(v3.X, v3.Y, 64) {
	case 0:
		if int32(v9) != 1 && int32(v9) != 0 {
			v8 = a3
			v8.X = 0.70709997
			v8.Y = 0.70709997
			return 1
		}
		a3.X = -0.70709997
		a3.Y = -0.70709997
		return 1
	case 1:
		if int32(v9) == 1 || int32(v9) == 2 {
			a3.X = 0.70709997
			a3.Y = -0.70709997
			return 1
		}
		a3.X = -0.70709997
		a3.Y = 0.70709997
		return 1
	case 2:
		switch v9 {
		case 0:
			v8 = a3
			a3.X = -0.70709997
			if (int32(v4) & 2) == 0 {
				a3.Y = -0.70709997
				return 1
			}
			v8.Y = 0.70709997
			return 1
		case 1:
			v6 = a3
			if (int32(v4) & 1) == 0 {
				v6.X = 0.70709997
				v6.Y = -0.70709997
				return 1
			}
			a3.X = -0.70709997
			a3.Y = -0.70709997
			result = 1
		case 2:
			v8 = a3
			a3.X = 0.70709997
			if int32(v4)&1 != 0 {
				v8.Y = 0.70709997
				return 1
			}
			a3.Y = -0.70709997
			return 1
		case 3:
			v8 = a3
			if (int32(v4) & 4) == 0 {
				v8.X = 0.70709997
				v8.Y = 0.70709997
				return 1
			}
			a3.X = -0.70709997
			a3.Y = 0.70709997
			return 1
		default:
			return 1
		}
		return result
	case 3:
		if int32(v9) == 0 {
			v8 = a3
			a3.X = -0.70709997
			if (int32(v4) & 2) == 0 {
				a3.Y = -0.70709997
				return 1
			}
			v8.Y = 0.70709997
			return 1
		}
		if int32(v9) != 1 {
			v8 = a3
			v8.X = 0.70709997
			v8.Y = 0.70709997
			return 1
		}
		v7 = a3
		if (int32(v4) & 1) == 0 {
			v7.X = 0.70709997
			v7.Y = -0.70709997
			return 1
		}
		v7.X = -0.70709997
		v7.Y = -0.70709997
		return 1
	case 4:
		if int32(v9) == 1 {
			v7 = a3
			if (int32(v4) & 1) == 0 {
				v7.X = 0.70709997
				v7.Y = -0.70709997
				return 1
			}
			v7.X = -0.70709997
			v7.Y = -0.70709997
			return 1
		}
		if int32(v9) == 2 {
			v8 = a3
			a3.X = 0.70709997
			if int32(v4)&1 != 0 {
				v8.Y = 0.70709997
				return 1
			}
			a3.Y = -0.70709997
			return 1
		}
		a3.X = -0.70709997
		a3.Y = 0.70709997
		return 1
	case 5:
		if int32(v9) == 2 {
			v8 = a3
			a3.X = 0.70709997
			if int32(v4)&1 != 0 {
				v8.Y = 0.70709997
				return 1
			}
			a3.Y = -0.70709997
			return 1
		}
		if int32(v9) == 3 {
			v8 = a3
			if (int32(v4) & 4) == 0 {
				v8.X = 0.70709997
				v8.Y = 0.70709997
				return 1
			}
			a3.X = -0.70709997
			a3.Y = 0.70709997
			return 1
		}
		a3.X = -0.70709997
		a3.Y = -0.70709997
		return 1
	case 6:
		if int32(v9) == 0 {
			v8 = a3
			a3.X = -0.70709997
			if (int32(v4) & 2) == 0 {
				a3.Y = -0.70709997
				return 1
			}
			v8.Y = 0.70709997
			return 1
		}
		if int32(v9) == 3 {
			v8 = a3
			if (int32(v4) & 4) == 0 {
				v8.X = 0.70709997
				v8.Y = 0.70709997
				return 1
			}
			a3.X = -0.70709997
			a3.Y = 0.70709997
			return 1
		}
		v6 = a3
		v6.X = 0.70709997
		v6.Y = -0.70709997
		return 1
	case 7:
		if int32(v9) == 1 {
			v7 = a3
			if (int32(v4) & 1) == 0 {
				v7.X = 0.70709997
				v7.Y = -0.70709997
				return 1
			}
			v7.X = -0.70709997
			v7.Y = -0.70709997
			return 1
		}
		v8 = a3
		if int32(v4)&1 != 0 {
			v8.X = 0.70709997
			v8.Y = 0.70709997
			return 1
		}
		a3.X = -0.70709997
		a3.Y = 0.70709997
		return 1
	case 8:
		if int32(v9) == 2 {
			v8 = a3
			a3.X = 0.70709997
			if int32(v4)&1 != 0 {
				v8.Y = 0.70709997
				return 1
			}
			a3.Y = -0.70709997
			return 1
		} else {
			v8 = a3
			a3.X = -0.70709997
			if (int32(v4) & 1) == 0 {
				v8.Y = 0.70709997
				return 1
			}
			a3.Y = -0.70709997
			return 1
		}
		fallthrough
	case 9:
		if int32(v9) == 3 {
			v8 = a3
			if (int32(v4) & 4) == 0 {
				v8.X = 0.70709997
				v8.Y = 0.70709997
				return 1
			}
			a3.X = -0.70709997
			a3.Y = 0.70709997
			return 1
		} else {
			v7 = a3
			if int32(v4)&4 != 0 {
				v7.X = 0.70709997
				v7.Y = -0.70709997
				return 1
			} else {
				v7.X = -0.70709997
				v7.Y = -0.70709997
				return 1
			}
		}
		fallthrough
	case 0xA:
		if int32(v9) != 0 {
			if int32(v4)&2 != 0 {
				a3.X = 0.70709997
				a3.Y = -0.70709997
				return 1
			}
			v8 = a3
			v8.X = 0.70709997
			v8.Y = 0.70709997
			return 1
		} else {
			v8 = a3
			a3.X = -0.70709997
			if (int32(v4) & 2) == 0 {
				a3.Y = -0.70709997
				return 1
			}
			v8.Y = 0.70709997
			return 1
		}
	default:
		return 0
	}
}
func sub_57F1D0(a1 *types.Pointf) int8 {
	var (
		v1 int8
		v2 int32
		v3 float64
		v4 float64
		v5 float64
		v7 uint8
	)
	v1 = 0
	v2 = int32(a1.X)
	v7 = uint8(int8(int32(a1.Y) % 23))
	v3 = float64(uint8(int8(v2 % 23)))
	if v3 >= 11.5 {
		v4 = float64(v7)
		if v4 >= 11.5 {
			v1 = 4
		}
		if v4 <= 11.5 {
			v1 |= 1
		}
	}
	if v3 > 11.5 {
		return v1
	}
	v5 = float64(v7)
	if v5 >= 11.5 {
		v1 |= 8
	}
	if v5 <= 11.5 {
		v1 |= 2
	}
	return v1
}
func sub_57F2A0(a1 *types.Pointf, a2 int32, a3 int32) int32 {
	var (
		v3     int32
		v4     int32
		result int32
		v6     int32
		v7     float32
		v8     float32
	)
	v7 = float32(float64(a1.X) - float64(a2*23))
	v3 = int32(v7)
	v8 = float32(float64(a1.Y) - float64(a3*23))
	v4 = int32(v8)
	if v3 <= v4 {
		*((*uint8)(unsafe.Pointer(&v4))) = uint8(int8(bool2int32(22-v3 <= v4)))
		v6 = v4 - 1
		*((*uint8)(unsafe.Pointer(&v6))) = uint8(int8(v6 & 0xFD))
		result = v6 + 3
	} else {
		*((*uint8)(unsafe.Pointer(&v4))) = uint8(int8(bool2int32(22-v3 <= v4)))
		result = v4 + 1
	}
	return result
}
func nullsub_10(a1 uint32) {
}
func sub_42CC50(this *unsafe.Pointer) int32 {
	return sub_42C770(this)
}
func nox_xxx_j_resetNPCRenderData_49A2E0() {
	nox_alloc_npcs()
}
func nox_xxx_j_inventoryNameSignInit_467460() int32 {
	return nox_xxx_inventoryNameSignInit_4671E0()
}
func nox_alloc_npcs_2() {
	nox_alloc_npcs()
}
func Nullsub_8(a1 *Point32, a2 unsafe.Pointer) {
}
func nullsub_30(a1 unsafe.Pointer) {
}
func Nullsub_29(sp *server.DurSpell) {
}
func nullsub_35(a1 unsafe.Pointer, a2 uint32) {
}
func nox_xxx_j_allocHitArray_511840() {
	nox_xxx_allocHitArray_5486D0()
}
