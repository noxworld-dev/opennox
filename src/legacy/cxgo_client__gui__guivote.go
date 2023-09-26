package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_48CB10(a1 int32) *uint32 {
	var (
		result *uint32
		v2     *wchar2_t
		v4     *wchar2_t
		v5     *wchar2_t
		v6     *wchar2_t
		v7     *wchar2_t
		v8     *wchar2_t
		v10    *wchar2_t
		v11    *wchar2_t
		v12    *wchar2_t
		v14    *wchar2_t
		v15    *uint32
		v16    *byte
		i      *byte
		v18    *uint32
		v19    int32
		v20    *wchar2_t
		j      *byte
		v22    int32
		v23    *wchar2_t
		v24    *wchar2_t
		v25    int32
		v26    *byte
	)
	v27, free27 := alloc.Make([]wchar2_t{}, 256)
	defer free27()
	v25 = 0
	nox_window_call_field_94_fnc(dword_5d4594_1197316, 16399, 0, 0)
	nox_window_call_field_94_fnc(dword_5d4594_1197320, 16399, 0, 0)
	result = (*uint32)(a1)
	dword_5d4594_1197308 = uint32(a1)
	switch a1 {
	case 4:
		if *memmap.PtrUint32(0x8531A0, 2576) != 0 && *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 4792)) == 0 {
			v24 = nox_strman_loadString_40F1D0(internCStr("GUIVote.c:NotAllowedVote"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIVote.c"), 452)
			v2 = nox_strman_loadString_40F1D0(internCStr("guiquit.c:Vote"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIVote.c"), 451)
			return (*uint32)(nox_xxx_dialogMsgBoxCreate_449A10(nil, v2, v24, 33, nil, nil))
		}
		nox_window_set_hidden(dword_5d4594_1197316, 1)
		nox_window_set_hidden(dword_5d4594_1197320, 0)
		v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1197312, 4301)
		v4 = nox_strman_loadString_40F1D0(internCStr("SelectVoteTopic"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIVote.c"), 465)
		sub_46AEE0(v3, int32(uintptr(unsafe.Pointer(v4))))
		v5 = nox_strman_loadString_40F1D0(internCStr("VoteTopicLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIVote.c"), 468)
		nox_wcscpy(&v27[0], v5)
		nox_wcscat(&v27[0], internWStr(" "))
		v6 = nox_strman_loadString_40F1D0(internCStr("VoteResetServer"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIVote.c"), 470)
		nox_wcscat(&v27[0], v6)
		nox_window_call_field_94_fnc(dword_5d4594_1197320, 16397, uintptr(unsafe.Pointer(&v27[0])), 4)
		v7 = nox_strman_loadString_40F1D0(internCStr("VoteTopicLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIVote.c"), 474)
		nox_wcscpy(&v27[0], v7)
		nox_wcscat(&v27[0], internWStr(" "))
		v8 = nox_strman_loadString_40F1D0(internCStr("VoteKickPlayer"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIVote.c"), 476)
		nox_wcscat(&v27[0], v8)
		nox_window_call_field_94_fnc(dword_5d4594_1197320, 16397, uintptr(unsafe.Pointer(&v27[0])), 4)
		return (*uint32)(unsafe.Pointer(uintptr(nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1197312))))
	case 2:
		nox_window_set_hidden(dword_5d4594_1197316, 1)
		nox_window_set_hidden(dword_5d4594_1197320, 0)
		v9 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1197312, 4301)
		v10 = nox_strman_loadString_40F1D0(internCStr("Vote:ResetQuest"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIVote.c"), 491)
		sub_46AEE0(v9, int32(uintptr(unsafe.Pointer(v10))))
		v11 = nox_strman_loadString_40F1D0(internCStr("WindowDir:Yes"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIVote.c"), 495)
		nox_window_call_field_94_fnc(dword_5d4594_1197320, 16397, uintptr(unsafe.Pointer(v11)), 4)
		v12 = nox_strman_loadString_40F1D0(internCStr("WindowDir:No"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIVote.c"), 498)
		nox_window_call_field_94_fnc(dword_5d4594_1197320, 16397, uintptr(unsafe.Pointer(v12)), 4)
		if dword_5d4594_1197332 == 1 {
			nox_window_call_field_94_fnc(dword_5d4594_1197320, 16403, 0, 0)
		} else {
			nox_window_call_field_94_fnc(dword_5d4594_1197320, 16403, 1, 0)
		}
		return (*uint32)(unsafe.Pointer(uintptr(nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1197312))))
	case 0, 1, 3:
		nox_window_set_hidden(dword_5d4594_1197316, 0)
		nox_window_set_hidden(dword_5d4594_1197320, 1)
		v13 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1197312, 4301)
		v14 = nox_strman_loadString_40F1D0(internCStr("VoteKickPlayer"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIVote.c"), 520)
		sub_46AEE0(v13, int32(uintptr(unsafe.Pointer(v14))))
		if int32(nox_xxx_getTeamCounter_417DD0()) != 0 {
			v15 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
			v16 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v15), 4)))))))
			v26 = v16
			if v16 != nil {
				for i = nox_common_playerInfoGetFirst_416EA0(); i != nil; i = nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(i))) {
					if i != *(**byte)(memmap.PtrOff(0x8531A0, 2576)) {
						v18 = nox_xxx_objGetTeamByNetCode_418C80(*((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*515))))
						if v18 != nil {
							if nox_xxx_teamCompare2_419180((*server.ObjectTeam)(unsafe.Pointer(v18)), server.TeamID(*(*byte)(unsafe.Add(unsafe.Pointer(v16), 57)))) != 0 {
								nox_window_call_field_94_fnc(dword_5d4594_1197316, 16397, uintptr(unsafe.Add(unsafe.Pointer(i), 4704)), uintptr(*memmap.PtrUint32(0x587000, uintptr((int32(*(*byte)(unsafe.Add(unsafe.Pointer(v16), 57)))%10)*8)+156400)))
								v19 = 0
								if dword_5d4594_1197324 > 0 {
									v20 = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1193720))
									for {
										if nox_wcscmp(v20, (*wchar2_t)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(wchar2_t(0))*2352))) == 0 {
											nox_window_call_field_94_fnc(dword_5d4594_1197316, 16405, uintptr(v25), 0)
										}
										v19++
										v20 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v20), unsafe.Sizeof(wchar2_t(0))*28))
										if v19 >= dword_5d4594_1197324 {
											break
										}
									}
									v16 = v26
								}
								v25++
							}
						}
					}
				}
			}
		} else {
			for j = nox_common_playerInfoGetFirst_416EA0(); j != nil; j = nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(j))) {
				if j != *(**byte)(memmap.PtrOff(0x8531A0, 2576)) {
					nox_window_call_field_94_fnc(dword_5d4594_1197316, 16397, uintptr(unsafe.Add(unsafe.Pointer(j), 4704)), 4)
					v22 = 0
					if dword_5d4594_1197324 > 0 {
						v23 = (*wchar2_t)(memmap.PtrOff(0x5D4594, 1193720))
						for {
							if nox_wcscmp(v23, (*wchar2_t)(unsafe.Add(unsafe.Pointer(j), unsafe.Sizeof(wchar2_t(0))*2352))) == 0 {
								nox_window_call_field_94_fnc(dword_5d4594_1197316, 16405, uintptr(v25), 0)
							}
							v22++
							v23 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v23), unsafe.Sizeof(wchar2_t(0))*28))
							if v22 >= dword_5d4594_1197324 {
								break
							}
						}
					}
					v25++
				}
			}
		}
		return (*uint32)(unsafe.Pointer(uintptr(nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1197312))))
	}
	return result
}
