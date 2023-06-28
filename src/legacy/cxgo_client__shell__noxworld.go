package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

var dword_5d4594_815104 int32 = 0
var nox_wnd_xxx_815040 *gui.Anim = nil

func Nox_game_showGameSel_4379F0() int {
	var (
		v2 *uint32
		v3 *uint32
		v4 *uint32
		v5 *wchar2_t
		v6 *uint32
	)
	_ = v6
	var v7 *wchar2_t
	_ = v7
	var v8 *uint32
	var v9 *uint32
	var v10 *uint32
	var v11 *uint32
	var v12 *uint32
	var v13 *uint32
	var v14 *uint32
	var v15 *uint32
	var v16 int32
	var v17 *wchar2_t
	var v18 *wchar2_t
	var v19 *uint32
	var v20 *uint32
	var v21 *uint32
	var v22 *uint32
	var v23 *uint32
	var v24 *uint32
	var v25 *uint32
	var v26 *uint32
	var v27 *wchar2_t
	var v28 *wchar2_t
	nox_xxx_setQuest_4D6F60(0)
	sub_4D6F80(0)
	if !noxflags.HasGame(0x2000000) && sub_4D6F30() == 0 {
		nox_game_createOrJoin_815048 = 0
		dword_587000_87412 = math.MaxUint32
	}
	*memmap.PtrUint32(0x5D4594, 815076) = 0
	*memmap.PtrUint32(0x5D4594, 815080) = 0
	*memmap.PtrUint32(0x5D4594, 815084) = 0
	nox_game_addStateCode_43BDD0(10000)
	sub_4A24C0(1)
	if func() bool {
		sub_4A1BE0(0)
		return dword_587000_87412 != -1
	}() {
		sub_49FDB0(0)
	}
	if nox_wol_wnd_world_814980 != nil {
		dword_5d4594_815044 = 0
		nox_wnd_xxx_815040.SetState(NOX_GUI_ANIM_IN)
		nox_wnd_xxx_815040.FncDoneOutPtr.Set(sub_438330)
		sub_43BE40(3)
		nox_xxx_clientPlaySoundSpecial_452D80(922, 100)
		nox_window_set_hidden(nox_wol_wnd_world_814980, 0)
		nox_window_set_hidden(dword_5d4594_815000, 0)
		nox_xxx_wnd_46ABB0((*gui.Window)(dword_5d4594_814984), 1)
		if nox_game_createOrJoin_815048 != 0 {
			sub_4375C0(0)
		}
		sub_46ACE0(nox_wol_wnd_world_814980, 10047, 10051, bool2int32(dword_587000_87408 == 0))
		if sub_4D6FA0() == 2 {
			v25 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10010)))
			nox_window_call_field_94_fnc(nox_wol_wnd_world_814980, 16391, uintptr(unsafe.Pointer(v25)), 0)
			v26 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10010)))
			nox_window_call_field_94_fnc(nox_wol_wnd_world_814980, 16391, uintptr(unsafe.Pointer(v26)), 0)
		}
		return 1
	}
	nox_wol_wnd_world_814980 = nox_new_window_from_file(internCStr("noxworld.wnd"), nox_xxx_windowMultiplayerSub_439E70)
	if nox_wol_wnd_world_814980 == nil {
		return 0
	}
	sub_49FF20()
	nox_xxx_wndShowModalMB_46A8C0(nox_wol_wnd_world_814980)
	nox_window_set_all_funcs(nox_wol_wnd_world_814980, sub_439D00, nil, nil)
	nox_wnd_xxx_815040 = nox_gui_makeAnimation_43C5B0(nox_wol_wnd_world_814980, 0, 0, 0, -480, 0, 20, 0, -40)
	if nox_wnd_xxx_815040 == nil {
		return 0
	}
	nox_wnd_xxx_815040.StateID = 10000
	nox_wnd_xxx_815040.Func12Ptr.Set(sub_438370)
	nox_wnd_xxx_815040.FncDoneOutPtr.Set(sub_438330)
	dword_5d4594_814984 = unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10020))
	dword_5d4594_814988 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10021))))
	nox_xxx_wndSetWindowProc_46B300((*gui.Window)(dword_5d4594_814984), sub_439D00)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_814988, sub_439D00)
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_814988, nox_xxx_windowMultiplayerSub_439E70)
	dword_5d4594_814996 = unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10011))
	nox_wol_wnd_gameList_815012 = nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10037)
	dword_5d4594_815004 = nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10034)
	dword_5d4594_815000 = nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10033)
	dword_5d4594_814992 = uint32(uintptr(unsafe.Pointer(sub_489B80(nox_wol_wnd_world_814980))))
	*memmap.PtrPtr(0x5D4594, 815008) = unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10001))
	dword_5d4594_815016 = nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10038)
	dword_5d4594_815020 = nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10039)
	dword_5d4594_815024 = nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10040)
	dword_5d4594_815028 = nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10041)
	dword_5d4594_815032 = nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10042)
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10002)))
	if noxflags.HasGame(0x1000000) {
		nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v2)), 0)
	}
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10003)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*9)) &= 0xFFFFFFFB
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10046)))
	nox_xxx_wndSetDrawFn_46B340((*gui.Window)(unsafe.Pointer(v4)), sub_438C80)
	nox_xxx_wndSetProc_46B2C0(nox_wol_wnd_gameList_815012, nox_xxx_windowMultiplayerSub_439E70)
	nox_window_set_hidden(nox_wol_wnd_gameList_815012, 1)
	nox_window_set_hidden(dword_5d4594_815000, 1)
	nox_xxx_wnd_46B280(*memmap.PtrInt32(0x5D4594, 815008), nox_wol_wnd_world_814980)
	dword_587000_87412 = 0
	nox_window_set_hidden((*gui.Window)(dword_5d4594_814988), 1)
	v5 = nox_strman_loadString_40F1D0(internCStr("JoinServer"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 2517)
	nox_window_call_field_94_fnc((*gui.Window)(dword_5d4594_814996), 16385, uintptr(unsafe.Pointer(v5)), 0)
	sub_46ACE0((*gui.Window)(dword_5d4594_814984), 10620, 10631, 1)
	sub_49FDB0(0)
	*memmap.PtrPtr(0x5D4594, 814556) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconLargeGreen")))
	*memmap.PtrPtr(0x5D4594, 814560) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconLargeGreenLit")))
	*memmap.PtrPtr(0x5D4594, 814564) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconSmallGreen")))
	*memmap.PtrPtr(0x5D4594, 814568) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconSmallGreenLit")))
	*memmap.PtrPtr(0x5D4594, 814572) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconLargeYellow")))
	*memmap.PtrPtr(0x5D4594, 814576) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconLargeYellowLit")))
	*memmap.PtrPtr(0x5D4594, 814580) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconSmallYellow")))
	*memmap.PtrPtr(0x5D4594, 814584) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconSmallYellowLit")))
	*memmap.PtrPtr(0x5D4594, 814588) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconLargeRed")))
	*memmap.PtrPtr(0x5D4594, 814592) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconLargeRedLit")))
	*memmap.PtrPtr(0x5D4594, 814596) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconSmallRed")))
	*memmap.PtrPtr(0x5D4594, 814600) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWGameIconSmallRedLit")))
	*memmap.PtrPtr(0x5D4594, 814900) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWMapULLg")))
	*memmap.PtrPtr(0x5D4594, 814904) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWMapURLg")))
	*memmap.PtrPtr(0x5D4594, 814908) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWMapLLLg")))
	*memmap.PtrPtr(0x5D4594, 814912) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("NWMapLRLg")))
	v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_gameList_815012, 10053)))
	v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_gameList_815012, 10043)))
	v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_gameList_815012, 10044)))
	v11 = (*uint32)(nox_wol_wnd_gameList_815012.WidgetData)
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v8))), nox_wol_wnd_gameList_815012)
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v9))), nox_wol_wnd_gameList_815012)
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v10))), nox_wol_wnd_gameList_815012)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*9)) = uint32(uintptr(unsafe.Pointer(v8)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*7)) = uint32(uintptr(unsafe.Pointer(v9)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*8)) = uint32(uintptr(unsafe.Pointer(v10)))
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v8), 4*100)), 8)) = 16
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v8), 4*100)), 12)) = 12
	nox_xxx_wndSetOffsetMB_46AE40(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*100))), 0, -15)
	v12 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_815000, 10032)))
	v13 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_815000, 10035)))
	v14 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_815000, 10036)))
	v15 = (*uint32)(dword_5d4594_815004.WidgetData)
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v12))), dword_5d4594_815004)
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v13))), dword_5d4594_815004)
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v14))), dword_5d4594_815004)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*9)) = uint32(uintptr(unsafe.Pointer(v12)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*7)) = uint32(uintptr(unsafe.Pointer(v13)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*8)) = uint32(uintptr(unsafe.Pointer(v14)))
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v12), 4*100)), 8)) = 16
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v12), 4*100)), 12)) = 10
	sub_438480()
	v16 = nox_xxx_servGetPort_40A430()
	sub_40A3C0(uint32(v16))
	nox_game_createOrJoin_815048 = 0
	dword_5d4594_815044 = 0
	dword_5d4594_815052 = 0
	dword_5d4594_814548 = 0
	qword_5d4594_815068 = uint64(nox_platform_get_ticks() + 1000)
	if dword_587000_87408 == 1 {
		sub_4383A0()
	}
	nox_xxx_createSocketLocal_554B40(0)
	nox_wol_server_result_cnt_815088 = 0
	nox_xxx_loadModifyers_4158C0()
	nox_xxx_loadLook_415D50()
	sub_430C30_set_video_max(NOX_MAX_WIDTH, NOX_MAX_HEIGHT)
	nox_client_setCursorType_477610(0)
	if dword_5d4594_815096 != 0 {
		v27 = nox_strman_loadString_40F1D0(internCStr("Kicked"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 2616)
		v17 = nox_strman_loadString_40F1D0(internCStr("Notification"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 2616)
		nox_xxx_dialogMsgBoxCreate_449A10(nil, v17, v27, 33, nil, nil)
		sub_44A360(1)
		dword_5d4594_815096 = 0
	} else if dword_5d4594_815100 != 0 {
		v28 = nox_strman_loadString_40F1D0(internCStr("Timeout"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 2623)
		v18 = nox_strman_loadString_40F1D0(internCStr("Notification"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 2623)
		nox_xxx_dialogMsgBoxCreate_449A10(nil, v18, v28, 33, nil, nil)
		sub_44A360(1)
		dword_5d4594_815100 = 0
	}
	sub_43DE40(sub_438770)
	if sub_44A4A0() != 0 {
		sub_44A4B0()
	}
	nox_xxx_wndSetDrawFn_46B340((*gui.Window)(dword_5d4594_814984), sub_438E30)
	v19 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10054)))
	nox_xxx_wndSetDrawFn_46B340((*gui.Window)(unsafe.Pointer(v19)), sub_438E30)
	v20 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10055)))
	nox_xxx_wndSetDrawFn_46B340((*gui.Window)(unsafe.Pointer(v20)), sub_438E30)
	v21 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10056)))
	nox_xxx_wndSetDrawFn_46B340((*gui.Window)(unsafe.Pointer(v21)), sub_438E30)
	v22 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10057)))
	nox_xxx_wndSetDrawFn_46B340((*gui.Window)(unsafe.Pointer(v22)), sub_438E30)
	if dword_587000_87408 == 0 {
		sub_46ACE0(nox_wol_wnd_world_814980, 10047, 10051, 1)
	}
	if sub_4D6FA0() == 1 {
		v23 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10002)))
		nox_window_call_field_94_fnc(nox_wol_wnd_world_814980, 16391, uintptr(unsafe.Pointer(v23)), 0)
		nox_xxx_setQuest_4D6F60(1)
		v24 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10020)))
		nox_window_call_field_93((*gui.Window)(unsafe.Pointer(v24)), 5, 15663512, 0)
	}
	return 1
}
func sub_4383A0() int32 {
	var (
		v0     *wchar2_t
		result int32
	)
	_ = result
	if wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(dword_5d4594_814992)) == 0 {
		nox_window_set_hidden((*gui.Window)(dword_5d4594_814992), 1)
		sub_489870()
	}
	nox_window_set_hidden(nox_wol_wnd_gameList_815012, 0)
	nox_window_set_hidden((*gui.Window)(dword_5d4594_814984), 1)
	nox_window_set_hidden((*gui.Window)(dword_5d4594_814988), 1)
	sub_46AD20(nox_wol_wnd_world_814980, 10006, 10007, 1)
	sub_46ACE0(nox_wol_wnd_world_814980, 10047, 10051, 0)
	v0 = nox_strman_loadString_40F1D0(internCStr("ListJoinServer"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 418)
	nox_window_call_field_94_fnc((*gui.Window)(dword_5d4594_814996), 16385, uintptr(unsafe.Pointer(v0)), 0)
	dword_587000_87408 = 1
	return 0
}
func sub_438770() bool {
	var (
		v1 int64
		v2 *wchar2_t
		v3 *wchar2_t
		v4 *wchar2_t
		v5 *wchar2_t
		v6 *uint16
		v7 *uint32
	)
	if dword_5d4594_814548 != 0 {
		switch dword_5d4594_814548 {
		case 2:
			sub_438BD0()
			sub_43AF90(1)
			return true
		case 3:
			if uint64(nox_platform_get_ticks()) < qword_5d4594_814956 {
				return true
			}
			nox_client_setConnError_43AFA0(8)
			return true
		case 4:
			sub_43AF90(3)
			v2 = nox_strman_loadString_40F1D0(internCStr("TestCon"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 1343)
			sub_449E30(v2)
			qword_5d4594_814956 = uint64(nox_platform_get_ticks() + 20000)
			return true
		case 5:
			v3 = nox_strman_loadString_40F1D0(internCStr("Password"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 1349)
			sub_449E00(v3)
			v4 = nox_strman_loadString_40F1D0(internCStr("PasswordRequired"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 1350)
			sub_449E30(v4)
			sub_449EA0(7)
			sub_44A360(0)
			sub_43AF90(6)
			sub_4A24C0(1)
			return true
		case 7:
			sub_44A360(1)
			v5 = nox_strman_loadString_40F1D0(internCStr("Connected"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 1364)
			sub_449E30(v5)
			sub_449EA0(0)
			nox_game_SetCliDrawFunc(ccall.FuncAddr(nox_xxx_cliDrawConnectedLoop_43B360))
			sub_43AF90(1)
			return true
		case 8:
			v1 = int64(nox_platform_get_ticks())
			dword_5d4594_814548 = 9
			*memmap.PtrUint64(0x5D4594, 814972) = uint64(v1 + 1000)
			return true
		case 9:
			if uint64(nox_platform_get_ticks()) <= *memmap.PtrUint64(0x5D4594, 814972) {
				return true
			}
			nox_client_joinGame_438A90()
			return true
		case 0xA:
			v6 = (*uint16)(unsafe.Pointer(uintptr(sub_449E60(4))))
			v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nil, 4001)))
			if v6 != nil && int32(*v6) != 0 {
				nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v7)), 1)
			} else {
				nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v7)), 0)
			}
			return true
		default:
			return true
		}
	} else {
		if (wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(dword_5d4594_814984)) == 0 || wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(dword_5d4594_814988)) == 0 || wndIsShown_nox_xxx_wndIsShown_46ACC0(nox_wol_wnd_gameList_815012) == 0) && nox_game_createOrJoin_815048 == 0 && dword_5d4594_815044 == 0 && dword_5d4594_815052 == 0 && wndIsShown_nox_xxx_wndIsShown_46ACC0(dword_5d4594_815000) != 0 {
			if uint64(nox_platform_get_ticks()) > qword_5d4594_815068 {
				nox_client_refreshServerList_4378B0()
				return true
			}
			sub_438770_waitList()
		}
		return true
	}
}
func sub_438BD0() int32 {
	var (
		v0 int32
		v1 *wchar2_t
		v2 *wchar2_t
	)
	if sub_44A4A0() == 0 {
		nox_xxx_dialogMsgBoxCreate_449A10(nox_wol_wnd_world_814980, nil, nil, 0, nil, nil)
	}
	v0 = int32(nox_client_connError_814552)
	if nox_client_connError_814552 != 8 && nox_client_connError_814552 != 9 && nox_client_connError_814552 != 10 {
		v1 = nox_strman_loadString_40F1D0(internCStr("ConnError"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 1262)
		sub_449E00(v1)
		v0 = int32(nox_client_connError_814552)
	}
	v2 = nox_strman_loadString_40F1D0(*(**byte)(memmap.PtrOff(0x587000, uintptr(v0*4)+87416)), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 1265)
	sub_449E30(v2)
	dword_5d4594_815044 = 0
	sub_449EA0(1)
	sub_44A360(1)
	return sub_4A24C0(1)
}
func nox_client_gui_serverInfoBlockCheckExp_439370(a1 *int2, a2 int32) {
	if (int32(*(*uint8)(unsafe.Add(a2, 164)))&0x10) != 0 && false {
		var v3 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("GeneralPrint:InformExpansion"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 688)
		nox_xxx_dialogMsgBoxCreate_449A10(nox_wol_wnd_world_814980, nil, v3, 33, nil, nil)
		sub_44A360(0)
		sub_44A4B0()
		return
	}
	sub_439450(a1.field_0, a1.field_4, (*uint32)(unsafe.Pointer(a1)))
	sub_46B120(dword_5d4594_815000, nil)
	nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_815000)
	sub_46C690(dword_5d4594_815000)
	nox_window_setPos_46A9B0(dword_5d4594_815000, a1.field_0, a1.field_4)
	nox_client_gui_serverInfoBlock_4394D0(a2)
	dword_5d4594_815056 = 1
	*memmap.PtrUint16(0x5D4594, 814604) = *(*uint16)(unsafe.Add(a2, 109))
	if nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
		nox_xxx_wnd_46ABB0((*gui.Window)(*memmap.PtrPtr(0x5D4594, 815008)), 0)
	}
}
func nox_client_gui_serverInfoBlock_4394D0(a1 int32) {
	var (
		v1   int32
		v9   int16
		v10  *wchar2_t
		v14  *wchar2_t
		v15  int32
		v16  int32
		v17  int32
		v18  int32
		v19  int32
		v20  *wchar2_t
		v21  int32
		v22  *wchar2_t
		v23  int32
		v24  int32
		v25  int32
		v27  *wchar2_t
		v28  int32
		v29  *wchar2_t
		v30  int32
		v31  int32
		v32  *wchar2_t
		v33  *wchar2_t
		v34  uint8
		v35  uint8
		v36  int32
		buf  [256]byte     = [256]byte{}
		wbuf [512]wchar2_t = [512]wchar2_t{}
	)
	v36 = a1 + 111
	v1 = int32(*(*uint8)(unsafe.Add(a1, 102))) & math.MaxInt8
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16399, 0, 0)
	var nameTitle *wchar2_t = nox_strman_loadString_40F1D0(internCStr("Name"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 749)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(nameTitle)), 14)
	if int32(*(*uint8)(unsafe.Add(a1, 120))) != 0 {
		libc.StrNCpy(&buf[0], (*byte)(unsafe.Add(a1, 120)), 256-1)
	} else {
		nox_sprintAddrPort_43BC80((*byte)(unsafe.Add(a1, 12)), *(*uint16)(unsafe.Add(a1, 109)), &buf[0])
	}
	buf[256-1] = 0
	nox_swprintf(&wbuf[0], internWStr("%S"), &buf[0])
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(&wbuf[0])), math.MaxUint32)
	if false {
		nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(memmap.PtrOff(0x587000, 89332)), math.MaxUint32)
		var hostTitle *wchar2_t = nox_strman_loadString_40F1D0(internCStr("GameHost"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 766)
		nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(hostTitle)), 14)
		sub_439CC0(int32(*(*uint32)(unsafe.Add(a1, 32))), &buf[0])
		nox_swprintf(&wbuf[0], internWStr("%S"), &buf[0])
		nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(&wbuf[0])), math.MaxUint32)
	}
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(memmap.PtrOff(0x587000, 89396)), math.MaxUint32)
	var pingTitle *wchar2_t = nox_strman_loadString_40F1D0(internCStr("Ping"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 774)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(pingTitle)), 14)
	if *(*uint32)(unsafe.Add(a1, 96)) == 9999 {
		nox_swprintf(&wbuf[0], internWStr("--"))
	} else {
		nox_swprintf(&wbuf[0], internWStr("%d"), *(*uint32)(unsafe.Add(a1, 96)))
	}
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(&wbuf[0])), math.MaxUint32)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(memmap.PtrOff(0x587000, 89464)), math.MaxUint32)
	var modeTitle *wchar2_t = nox_strman_loadString_40F1D0(internCStr("GameType"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 787)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(modeTitle)), 14)
	var gameMode *wchar2_t = nox_gui_wol_gameModeString_43BCB0(int16(*(*uint16)(unsafe.Add(a1, 163))))
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(gameMode)), math.MaxUint32)
	if int32(*(*uint8)(unsafe.Add(a1, 164)))&0x10 != 0 {
		nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(memmap.PtrOff(0x587000, 89520)), math.MaxUint32)
		var stageTitle *wchar2_t = nox_strman_loadString_40F1D0(internCStr("Stage"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 794)
		nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(stageTitle)), 14)
		nox_swprintf(&wbuf[0], internWStr("%d"), *(*uint16)(unsafe.Add(a1, 165)))
		nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(&wbuf[0])), math.MaxUint32)
	}
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(memmap.PtrOff(0x587000, 89580)), math.MaxUint32)
	var mapTitle *wchar2_t = nox_strman_loadString_40F1D0(internCStr("Map"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 801)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(mapTitle)), 14)
	libc.StrNCpy(&buf[0], (*byte)(unsafe.Add(a1, 111)), 256-1)
	buf[256-1] = 0
	nox_swprintf(&wbuf[0], internWStr("%S"), &buf[0])
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(&wbuf[0])), math.MaxUint32)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(memmap.PtrOff(0x587000, 89636)), math.MaxUint32)
	v9 = int16(*(*uint16)(unsafe.Add(a1, 163)))
	if int32(v9)&0xC000 != 0 {
		if int32(v9)&0x4000 != 0 {
			v33 = nox_strman_loadString_40F1D0(internCStr("Individual"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 811)
		} else {
			v33 = nox_strman_loadString_40F1D0(internCStr("Clan"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 815)
		}
		nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(v33)), 6)
		v10 = nox_strman_loadString_40F1D0(internCStr("Ladder"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 817)
		nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(v10)), 6)
	}
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(memmap.PtrOff(0x587000, 89788)), math.MaxUint32)
	var playersTitle *wchar2_t = nox_strman_loadString_40F1D0(internCStr("Occupancy"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 822)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(playersTitle)), 14)
	nox_swprintf(&wbuf[0], internWStr("%d/%d\n"), *(*uint8)(unsafe.Add(a1, 103)), *(*uint8)(unsafe.Add(a1, 104)))
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(&wbuf[0])), math.MaxUint32)
	if (int32(*(*uint8)(unsafe.Add(a1, 164))) & 0x20) == 0 {
		return
	}
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(memmap.PtrOff(0x587000, 89860)), math.MaxUint32)
	var resTitle *wchar2_t = nox_strman_loadString_40F1D0(internCStr("Resolution"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 831)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(resTitle)), 14)
	var rstr int32 = int32(uintptr(unsafe.Pointer(get_video_mode_string(v1))))
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(rstr), math.MaxUint32)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(memmap.PtrOff(0x587000, 89916)), math.MaxUint32)
	v14 = nox_strman_loadString_40F1D0(internCStr("DisabledSpells"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 836)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(v14)), 14)
	v15 = 0
	v16 = 1
	v34 = 0
	v17 = 1
	v18 = 136
	for {
		if uint32(v16) == 0x80000000 {
			v16 = 1
			v34++
		} else {
			v16 *= 2
		}
		if nox_xxx_spellIsValid_424B50(v17) && (uint32(v16)&*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v36+int32(v34)*4)), 24))) == 0 && nox_xxx_spellFlags_424A70(v17)&0x7000000 != 0 {
			v15 = 1
			v19 = int32(uintptr(unsafe.Pointer(nox_xxx_spellTitle_424930(v17))))
			nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(v19), 4)
		}
		v17++
		v18--
		if v18 == 0 {
			break
		}
	}
	if v15 == 0 {
		v20 = nox_strman_loadString_40F1D0(internCStr("None"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 866)
		nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(v20)), 4)
	}
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(memmap.PtrOff(0x587000, 90024)), math.MaxUint32)
	v21 = 0
	v22 = nox_strman_loadString_40F1D0(internCStr("DisabledWeapons"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 872)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(v22)), 14)
	v23 = 1
	v35 = 0
	v24 = 1
	v25 = 27
	for {
		if (int32(uint8(int8(v23))) & int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(int32(v35)+v36)), 44)))) == 0 {
			var v26 int32 = sub_4159F0(v24)
			if v26 != 0 {
				nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(v26), math.MaxUint32)
				v21 = 1
			}
		}
		if v23 == 128 {
			v23 = 1
			v35++
		} else {
			v23 *= 2
		}
		v24 *= 2
		v25--
		if v25 == 0 {
			break
		}
	}
	if v21 == 0 {
		v27 = nox_strman_loadString_40F1D0(internCStr("None"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 899)
		nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(v27)), 4)
	}
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(memmap.PtrOff(0x587000, 90132)), math.MaxUint32)
	v28 = 0
	v29 = nox_strman_loadString_40F1D0(internCStr("DisabledArmor"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 905)
	nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(v29)), 14)
	v30 = 1
	v31 = 26
	for {
		if (uint32(v30) & *(*uint32)(unsafe.Add(a1, 159))) == 0 {
			var result int32 = sub_415E80(v30)
			if result != 0 {
				v28 = 1
				nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(result), math.MaxUint32)
			}
		}
		v30 *= 2
		v31--
		if v31 == 0 {
			break
		}
	}
	if v28 == 0 {
		v32 = nox_strman_loadString_40F1D0(internCStr("None"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 920)
		nox_window_call_field_94_fnc(dword_5d4594_815004, 16397, uintptr(unsafe.Pointer(v32)), 4)
	}
}
func nox_xxx_windowMultiplayerSub_439E70(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v4  int32
		v5  int32
		v6  *int32
		v7  *int32
		v8  int32
		v9  int32
		v10 int32
		v12 *wchar2_t
		v13 int32
		v14 int32
		v15 *wchar2_t
		v16 int32
		v17 *uint32
		v18 *uint32
		v19 int32
		v20 int32
		v21 *wchar2_t
		v22 int32
		v23 *wchar2_t
		v24 *byte
		v25 *byte
		v26 *byte
		v27 int32
		v28 uint16
		v30 int32
		v31 int32
	)
	_ = v31
	var buf [4]byte
	var v33 [10]wchar2_t
	var v34 [36]byte
	_ = v34
	var v35 [72]byte
	if a2 > 0x4010 {
		if a2 == 16403 || a2 == 16412 {
			nox_window_call_field_94_fnc(dword_5d4594_815016, a2, a3, 0)
			nox_window_call_field_94_fnc(dword_5d4594_815020, a2, a3, 0)
			nox_window_call_field_94_fnc(dword_5d4594_815024, a2, a3, 0)
			nox_window_call_field_94_fnc(dword_5d4594_815028, a2, a3, 0)
			nox_window_call_field_94_fnc(dword_5d4594_815032, a2, a3, 0)
		}
		return 0
	}
	switch a2 {
	case 0x4010:
		if nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) == 10061 {
			var mpos nox_point = nox_client_getMousePos_4309F0()
			dword_5d4594_814624 = unsafe.Pointer(uintptr(sub_4A28C0(int32(a4))))
			nox_client_gui_serverInfoBlockCheckExp_439370((*int2)(unsafe.Pointer(&mpos)), int32(uintptr(dword_5d4594_814624)))
			return 0
		}
		return 0
	case 0x17:
		return 1
	case 0x4000:
		v27 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
		if v27 >= 10043 && v27 <= 10044 {
			nox_window_call_field_94_fnc(dword_5d4594_815016, 0x4000, a3, 0)
			nox_window_call_field_94_fnc(dword_5d4594_815020, 0x4000, a3, 0)
			nox_window_call_field_94_fnc(dword_5d4594_815024, 0x4000, a3, 0)
			nox_window_call_field_94_fnc(dword_5d4594_815028, 0x4000, a3, 0)
			nox_window_call_field_94_fnc(dword_5d4594_815032, 0x4000, a3, 0)
			return 0
		}
		return 0
	}
	if a2 != 16391 {
		return 0
	}
	v4 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	v5 = v4
	if v4 != 10043 && v4 != 10044 && v4 != 10035 && v4 != 10036 {
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	}
	if v5 >= 10070 {
		var mpos nox_point = nox_client_getMousePos_4309F0()
		v30 = mpos.x - 216
		v31 = mpos.y - 27
		v6 = (*int32)(unsafe.Pointer(sub_4A0020()))
		if sub_4A25C0((*uint32)(unsafe.Pointer(&v30)), v6) >= 2 {
			v7 = (*int32)(unsafe.Pointer(sub_4A0020()))
			*memmap.PtrUint32(0x5D4594, 815036) = uint32(sub_4A2610(nox_wol_wnd_world_814980, (*uint32)(unsafe.Pointer(&v30)), v7))
		} else {
			dword_5d4594_814624 = unsafe.Pointer(sub_4A0490(v5 - 10070))
			nox_client_gui_serverInfoBlockCheckExp_439370((*int2)(unsafe.Pointer(&mpos)), int32(uintptr(dword_5d4594_814624)))
		}
		nox_xxx_cursorSetTooltip_4776B0((*wchar2_t)(memmap.PtrOff(0x5D4594, 815112)))
	}
	if v5 > 10006 {
		switch v5 {
		case 10007:
			if nox_game_createOrJoin_815048 != 0 {
				sub_4373A0()
			}
			return 0
		case 10010:
			sub_4373A0()
			return 0
		case 10047, 10048, 10049, 10050, 10051:
			sub_4379C0()
			nox_wol_servers_sortBtnHandler_4A0290(v5)
			sub_4A0390()
			return 0
		case 10054:
			dword_587000_87412 = 0
			sub_43A810()
			nox_client_refreshServerList_4378B0()
			if noxflags.HasGame(0x2000000) {
				v24 = sub_4A7EF0()
				sub_439D90(*(*uint32)(unsafe.Pointer(v24))+216, *((*uint32)(unsafe.Add(unsafe.Pointer(v24), 4*1)))+27)
			} else {
				sub_439D90(0x198, 0xEF)
			}
			return 0
		case 10055:
			dword_587000_87412 = 1
			sub_43A810()
			nox_client_refreshServerList_4378B0()
			if !noxflags.HasGame(0x2000000) {
				sub_439D90(0x198, 0xEF)
				return 0
			} else {
				v25 = sub_4A7EF0()
				sub_439D90(*(*uint32)(unsafe.Pointer(v25))+216, *((*uint32)(unsafe.Add(unsafe.Pointer(v25), 4*1)))+27)
				return 0
			}
		case 10056:
			dword_587000_87412 = 2
			sub_43A810()
			nox_client_refreshServerList_4378B0()
			if !noxflags.HasGame(0x2000000) {
				sub_439D90(0x198, 0xEF)
			} else {
				v24 = sub_4A7EF0()
				sub_439D90(*(*uint32)(unsafe.Pointer(v24))+216, *((*uint32)(unsafe.Add(unsafe.Pointer(v24), 4*1)))+27)
			}
			return 0
		case 10057:
			dword_587000_87412 = 3
			sub_43A810()
			nox_client_refreshServerList_4378B0()
			if noxflags.HasGame(0x2000000) {
				v26 = sub_4A7EF0()
				sub_439D90(*(*uint32)(unsafe.Pointer(v26))+216, *((*uint32)(unsafe.Add(unsafe.Pointer(v26), 4*1)))+27)
			} else {
				sub_439D90(0x198, 0xEF)
			}
			return 0
		default:
			return 0
		}
	}
	if v5 == 10006 {
		nox_game_createOrJoin_815048 = 0
		nox_client_refreshServerList_4378B0()
		return 0
	}
	if v5 > 10002 {
		v19 = v5 - 10003
		if v5 != 10003 {
			v20 = v19 - 1
			if v20 == 0 {
				nox_game_createOrJoin_815048 = 0
				sub_4383A0()
				nox_client_refreshServerList_4378B0()
				return 0
			}
			if v20 == 1 {
				nox_game_createOrJoin_815048 = 0
				nox_window_set_hidden(nox_wol_wnd_gameList_815012, 1)
				nox_window_set_hidden((*gui.Window)(dword_5d4594_814984), 1)
				nox_window_set_hidden((*gui.Window)(dword_5d4594_814988), 1)
				nox_window_set_hidden((*gui.Window)(dword_5d4594_814992), 0)
				sub_46AD20(nox_wol_wnd_world_814980, 10006, 10007, 0)
				sub_46ACE0(nox_wol_wnd_world_814980, 10047, 10051, 1)
				v21 = nox_strman_loadString_40F1D0(internCStr("FilterMsg"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 2186)
				nox_window_call_field_94_fnc((*gui.Window)(dword_5d4594_814996), 16385, uintptr(unsafe.Pointer(v21)), 0)
				return 0
			}
			return 0
		}
		*((*uint8)(unsafe.Pointer(&v22))) = 1
		if v22 == 0 {
			v23 = nox_strman_loadString_40F1D0(internCStr("GeneralPrint:InformExpansion"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 2013)
			nox_xxx_dialogMsgBoxCreate_449A10(nox_wol_wnd_world_814980, nil, v23, 33, nil, nil)
			sub_44A360(0)
			sub_44A4B0()
			return 0
		}
		nox_game_createOrJoin_815048 = 1
		nox_common_gameFlags_unset_40A540(0x10000)
		nox_client_setMousePos_430B10(408, 239)
		sub_4375C0(0)
		if wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(dword_5d4594_814992)) == 0 {
			sub_489870()
		}
		nox_xxx_setQuest_4D6F60(1)
		nox_xxx_cliShowHideTubes_470AA0(1)
		if false {
			if dword_587000_87412 != -1 {
				return 0
			}
			v16 = nox_common_randomInt_415FA0(10054, 10057)
			v17 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, v16)))
			nox_window_call_field_94_fnc(nox_wol_wnd_world_814980, 16391, uintptr(unsafe.Pointer(v17)), 0)
			return 0
		}
		dword_587000_87412 = 0
		v18 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10020)))
		nox_window_call_field_93((*gui.Window)(unsafe.Pointer(v18)), 5, 15663512, 0)
		return 0
	}
	if v5 == 10002 {
		if noxflags.HasGame(0x1000000) {
			return 0
		}
		nox_game_createOrJoin_815048 = 1
		nox_xxx_setGameFlags_40A4D0(0x10000)
		nox_xxx_cliShowHideTubes_470AA0(0)
		nox_client_setMousePos_430B10(408, 239)
		sub_4375C0(0)
		if wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(dword_5d4594_814992)) == 0 {
			sub_489870()
		}
		if noxflags.HasGame(0x2000000) || sub_4D6F30() != 0 {
			return 0
		}
		if false {
			if dword_587000_87412 != -1 {
				return 0
			}
			v16 = nox_common_randomInt_415FA0(10054, 10057)
			v17 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, v16)))
			nox_window_call_field_94_fnc(nox_wol_wnd_world_814980, 16391, uintptr(unsafe.Pointer(v17)), 0)
			return 0
		}
		dword_587000_87412 = 0
		v18 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wol_wnd_world_814980, 10020)))
		nox_window_call_field_93((*gui.Window)(unsafe.Pointer(v18)), 5, 15663512, 0)
		return 0
	}
	v8 = v5 - 4001
	if v8 == 0 {
		if sub_43AF80() == 6 {
			v12 = (*wchar2_t)(unsafe.Pointer(uintptr(sub_449E60(4))))
			nox_wcsncpy(&v33[0], v12, 9)
			v33[8] = 0
			v28 = uint16(int16(nox_client_getServerPort_43B320()))
			v13 = int32(nox_client_getServerAddr_43B300())
			sub_5550D0(v13, v28, &buf[0])
			sub_43AF90(3)
			qword_5d4594_814956 = uint64(nox_platform_get_ticks() + 20000)
			sub_449EA0(0)
			return 0
		}
		if sub_43AF80() == 10 {
			v14 = sub_449E60(4)
			nox_sprintf(&v35[0], internCStr("%S"), v14)
			v15 = nox_strman_loadString_40F1D0(internCStr("Finding"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 2209)
			sub_449E30(v15)
			sub_43AF90(11)
			sub_449EA0(0)
			return 0
		}
		if sub_43AF80() == 1 {
			sub_43A920()
			Nox_game_showGameSel_4379F0()
			return 0
		}
		if dword_5d4594_815104 != 0 {
			qword_5d4594_815068 = uint64(nox_platform_get_ticks() + 1000)
			return 0
		}
		return 0
	}
	v9 = v8 - 1
	if v9 == 0 {
		sub_43A920()
		Nox_game_showGameSel_4379F0()
		return 0
	}
	if v9 != 5999 || dword_5d4594_815044 != 0 {
		return 0
	}
	v10 = sub_43B340()
	if v10&0x1000 != 0 {
		sub_4D6F80(1)
		nox_xxx_cliShowHideTubes_470AA0(1)
	}
	sub_43B460()
	if sub_4D6F70() != 0 {
		if nox_client_countPlayerFiles04_4DC7D0() != 0 {
			sub_4A7A70(1)
			nox_game_showSelChar_4A4DB0()
			dword_5d4594_815044 = 1
			sub_4A2890()
			return 0
		}
	} else if nox_client_countPlayerFiles02_4DC630() != 0 {
		sub_4A7A70(1)
		nox_game_showSelChar_4A4DB0()
		dword_5d4594_815044 = 1
		sub_4A2890()
		return 0
	}
	sub_4A7A70(0)
	Nox_game_showSelClass_4A4840()
	dword_5d4594_815044 = 1
	sub_4A2890()
	return 0
}
func sub_43A810() {
	var (
		v0 int32
		v1 *int32
		v2 *wchar2_t
	)
	nox_window_set_hidden((*gui.Window)(dword_5d4594_814984), 0)
	nox_window_set_hidden((*gui.Window)(dword_5d4594_814988), 1)
	nox_xxx_wndSetIcon_46AE60((*gui.Window)(dword_5d4594_814984), int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_587000_87412)*4+814900)))
	if nox_game_createOrJoin_815048 == 1 {
		v2 = nox_strman_loadString_40F1D0(internCStr("CreateMsg"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 377)
	} else {
		v2 = nox_strman_loadString_40F1D0(internCStr("JoinServer"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 382)
	}
	nox_window_call_field_94_fnc((*gui.Window)(dword_5d4594_814996), 16385, uintptr(unsafe.Pointer(v2)), 0)
	if false {
		sub_46ACE0((*gui.Window)(dword_5d4594_814984), 10600, 10611, 1)
		v0 = 0
		v1 = mem_getI32Ptr(0x587000, 87560)
		for {
			sub_46ACE0((*gui.Window)(dword_5d4594_814984), *v1, *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*1)), bool2int32(uint32(v0) != dword_587000_87412))
			v1 = (*int32)(unsafe.Add(unsafe.Pointer(v1), 4*2))
			v0++
			if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x587000, 87592))) {
				break
			}
		}
	}
	sub_49FDB0(dword_587000_87412)
}
func sub_43B630() *uint32 {
	var v0 *wchar2_t
	nox_xxx_wnd_46C6E0(dword_5d4594_815000)
	v0 = nox_strman_loadString_40F1D0(internCStr("AttemptingConn"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 1284)
	return (*uint32)(nox_xxx_dialogMsgBoxCreate_449A10(nox_wol_wnd_world_814980, nil, v0, 34, nil, nil))
}
func sub_43B6E0() {
	var (
		v1 *wchar2_t
		v2 *wchar2_t
	)
	if nox_wol_wnd_world_814980 != nil {
		v2 = nox_strman_loadString_40F1D0(internCStr("Kicked"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3331)
		v1 = nox_strman_loadString_40F1D0(internCStr("Notification"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3331)
		nox_xxx_dialogMsgBoxCreate_449A10(nil, v1, v2, 33, nil, nil)
		sub_44A360(1)
		dword_5d4594_815096 = 0
	} else {
		dword_5d4594_815096 = 1
	}
}
func sub_43B750() {
	var (
		v1 *wchar2_t
		v2 *wchar2_t
	)
	if nox_wol_wnd_world_814980 != nil {
		v2 = nox_strman_loadString_40F1D0(internCStr("Timeout"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3351)
		v1 = nox_strman_loadString_40F1D0(internCStr("Notification"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3351)
		nox_xxx_dialogMsgBoxCreate_449A10(nil, v1, v2, 33, nil, nil)
		sub_44A360(1)
		dword_5d4594_815100 = 0
	} else {
		dword_5d4594_815100 = 1
	}
}
func nox_gui_wol_newServerLine_43B7C0(srv *nox_gui_server_ent_t) {
	var (
		buf [332]byte
	)
	wbuf, wfree := alloc.Make([]wchar2_t{}, 128)
	defer wfree()
	if dword_587000_87408 != 0 {
		nox_window_call_field_94_fnc(nox_wol_wnd_gameList_815012, 16397, uintptr(memmap.PtrOff(0x587000, 91164)), 4)
		libc.StrNCpy(&buf[0], &srv.server_name[0], 15)
		buf[15] = 0
		if libc.MemCmp(unsafe.Pointer(&buf[0]), memmap.PtrOff(0x5D4594, 815120), 1) == 0 {
			nox_sprintAddrPort_43BC80(&srv.addr[0], srv.port, &buf[0])
		}
		nox_swprintf(&wbuf[0], internWStr("%S"), &buf[0])
		sub_43BC10(&wbuf[0], 100)
		nox_window_call_field_94_fnc(dword_5d4594_815016, 16397, uintptr(unsafe.Pointer(&wbuf[0])), 4)
		nox_swprintf(&wbuf[0], internWStr("%d/%d"), srv.players, srv.max_players)
		nox_window_call_field_94_fnc(dword_5d4594_815020, 16397, uintptr(unsafe.Pointer(&wbuf[0])), 4)
		var v6 *wchar2_t = nox_gui_wol_gameModeString_43BCB0(int16(srv.flags))
		if int32(srv.flags)&0x1000 != 0 {
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 814772)), internWStr("%s %d"), v6, srv.quest_level)
			nox_window_call_field_94_fnc(dword_5d4594_815024, 16397, uintptr(memmap.PtrOff(0x5D4594, 814772)), 4)
		} else {
			nox_window_call_field_94_fnc(dword_5d4594_815024, 16397, uintptr(unsafe.Pointer(v6)), 4)
		}
		if srv.ping == 9999 {
			nox_swprintf(&wbuf[0], internWStr("--"))
		} else {
			nox_itow(srv.ping, &wbuf[0], 10)
		}
		nox_window_call_field_94_fnc(dword_5d4594_815028, 16397, uintptr(unsafe.Pointer(&wbuf[0])), 4)
		wbuf[0] = 0
		if int32(srv.status)&0x20 != 0 {
			var v9 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("Noxworld.wnd:private"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3486)
			nox_wcscat(&wbuf[0], v9)
		}
		if int32(srv.status)&0x10 != 0 {
			if wbuf[0] != 0 {
				nox_wcscat(&wbuf[0], internWStr("+"))
			}
			var v10 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("Noxworld.wnd:closed"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3494)
			nox_wcscat(&wbuf[0], v10)
		}
		if wbuf[0] == 0 {
			var v11 *wchar2_t
			if int32(srv.players) < int32(srv.max_players) {
				v11 = nox_strman_loadString_40F1D0(internCStr("Open"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3505)
			} else {
				v11 = nox_strman_loadString_40F1D0(internCStr("Full"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3501)
			}
			nox_wcscat(&wbuf[0], v11)
		}
		nox_window_call_field_94_fnc(dword_5d4594_815032, 16397, uintptr(unsafe.Pointer(&wbuf[0])), 4)
	} else {
		var a1 int32 = int32(uintptr(unsafe.Pointer(srv)))
		*(*[332]byte)(unsafe.Pointer(&buf[0])) = [332]byte{}
		*(*uint32)(unsafe.Pointer(&buf[8])) = 257
		*(*uint32)(unsafe.Pointer(&buf[16])) = uint32(uintptr(unsafe.Pointer(nox_wol_wnd_world_814980)))
		var v4 int32
		if dword_587000_87412 == -1 {
			var (
				v1 int32 = sub_437860(int32(*(*int16)(unsafe.Add(a1, 44))), int32(*(*int16)(unsafe.Add(a1, 46))))
				v2 int16 = int16(*memmap.PtrUint16(0x587000, uintptr(v1*8)+87528))
			)
			v1 += 10054
			*(*uint16)(unsafe.Add(a1, 44)) -= uint16(v2)
			*(*uint16)(unsafe.Add(a1, 46)) -= *memmap.PtrUint16(0x587000, uintptr(v1*8+7098))
			*(*uint16)(unsafe.Add(a1, 44)) >>= 1
			*(*uint16)(unsafe.Add(a1, 46)) >>= 1
			var v3 *uint32 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_814988)), v1)))
			v4 = int32(uintptr(unsafe.Pointer(nox_gui_newButtonOrCheckbox_4A91A0((*gui.Window)(unsafe.Pointer(v3)), 1185, int(*(*int16)(unsafe.Add(a1, 44)))-5, int(*(*int16)(unsafe.Add(a1, 46)))-5, 10, 10, (*gui.WindowData)(unsafe.Pointer(&buf[0]))))))
		} else {
			*(*uint16)(unsafe.Add(a1, 44)) -= *memmap.PtrUint16(0x587000, uintptr(dword_587000_87412)*8+87528)
			*(*uint16)(unsafe.Add(a1, 46)) -= *memmap.PtrUint16(0x587000, uintptr(dword_587000_87412)*8+87530)
			v4 = int32(uintptr(unsafe.Pointer(nox_gui_newButtonOrCheckbox_4A91A0((*gui.Window)(dword_5d4594_814984), 1192, int(*(*int16)(unsafe.Add(a1, 44)))-10, int(*(*int16)(unsafe.Add(a1, 46)))-10, 20, 20, (*gui.WindowData)(unsafe.Pointer(&buf[0]))))))
		}
		*(*uint32)(unsafe.Add(a1, 28)) = uint32(v4)
		sub_437320(a1)
		var v13 [32]byte
		if int32(*(*uint8)(unsafe.Add(a1, 120))) != 0 {
			libc.StrNCpy(&v13[0], (*byte)(unsafe.Add(a1, 120)), 15)
			v13[15] = 0
		} else {
			nox_sprintAddrPort_43BC80((*byte)(unsafe.Add(a1, 12)), *(*uint16)(unsafe.Add(a1, 109)), &v13[0])
		}
		if *(*uint32)(unsafe.Add(a1, 96)) == 9999 {
			nox_swprintf(&wbuf[0], internWStr("%S -- ms"), &v13[0])
		} else {
			nox_swprintf(&wbuf[0], internWStr("%S %dms"), &v13[0], *(*uint32)(unsafe.Add(a1, 96)))
		}
		nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 28)), 36)), &wbuf[0])
		nox_xxx_wndSetProc_46B2C0(*(**gui.Window)(unsafe.Add(a1, 28)), nox_xxx_windowMultiplayerSub_439E70)
		var result *uint32 = *(**uint32)(unsafe.Add(a1, 28))
		_ = result
		*result = *(*uint32)(unsafe.Add(a1, 36)) + 10070
	}
}
func nox_gui_wol_gameModeString_43BCB0(a1 int16) *wchar2_t {
	if int32(a1)&0x1000 != 0 {
		return nox_strman_loadString_40F1D0(internCStr("Quest"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3534)
	}
	if int32(a1)&0x20 != 0 {
		return nox_strman_loadString_40F1D0(internCStr("CTF"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3541)
	}
	if int32(a1)&0x400 != 0 {
		return nox_strman_loadString_40F1D0(internCStr("Highlander"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3545)
	}
	if int32(a1)&0x10 != 0 {
		return nox_strman_loadString_40F1D0(internCStr("KotR"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3550)
	}
	if int32(a1)&0x40 != 0 {
		return nox_strman_loadString_40F1D0(internCStr("Flagball"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3555)
	}
	if (int32(a1) & 0x80) == 0 {
		return nox_strman_loadString_40F1D0(internCStr("Arena"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3563)
	}
	return nox_strman_loadString_40F1D0(internCStr("Chat"), nil, internCStr("C:\\NoxPost\\src\\client\\shell\\noxworld.c"), 3559)
}
