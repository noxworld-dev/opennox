package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/client/audio/ail"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_win_unk1 *gui.Window
var dword_5d4594_1046512 *gui.Window
var dword_587000_122856 uint32 = 0x1
var audioStream2 ail.Stream
var dword_5d4594_831092 uint32
var nox_player_netCode_85319C uint32

func sub_44D040(i int32) int32 {
	var obj *client.ObjectType = nox_get_thing(i)
	if obj == nil {
		return 0
	}
	return int32((obj.ObjClass >> 22) & 1)
}
func sub_44D060(a1 int32) int32 {
	v1 := unsafe.Pointer(nox_get_thing(a1))
	return bool2int32(v1 != nil && *(*uint32)(unsafe.Add(v1, 32))&0x400000 != 0 && int32(*(*uint8)(unsafe.Add(v1, 36)))&0x18 != 0)
}
func sub_44D090(a1 int32) int32 {
	result := unsafe.Pointer(nox_get_thing(a1))
	if result == nil {
		return 0
	}
	return bool2int32((*(*uint32)(unsafe.Add(result, 32)) & 0x20400000) != 0)
}
func Sub_44D3A0() {
	if dword_5d4594_831076 == 0 {
		return
	}
	switch dword_5d4594_830864 {
	case 0:
		if dword_5d4594_830872 != nil && dword_587000_122848 != 0 {
			if sub_44D660((*byte)(dword_5d4594_830872)) == 0 {
				dword_5d4594_830872 = nil
			} else if dword_587000_122856 == 0 || *memmap.PtrUint32(0x587000, 93160) == 0 || dword_5d4594_831084 != 0 {
				dword_5d4594_830864 = 2
			} else {
				dword_5d4594_831084 = 1
				sub_43DBD0()
				dword_5d4594_830864 = 1
			}
		} else if dword_5d4594_831084 != 0 {
			sub_43DBE0()
			dword_5d4594_831084 = 0
		}
	case 1:
		if sub_43DC40() == 0 {
			dword_5d4594_830864 = 2
		}
	case 2:
		sub_486320(memmap.PtrOff(0x5D4594, 830876), 0x4000)
		if sub_44D7E0(memmap.Int32(0x5D4594, 830868)) == 0 {
			dword_5d4594_830864 = 0
			dword_5d4594_830872 = nil
		} else {
			dword_5d4594_830864 = 3
			dword_5d4594_830972 = dword_5d4594_830872
			*memmap.PtrUint32(0x5D4594, 830860) = *memmap.PtrUint32(0x5D4594, 830868)
		}
	case 3:
		if dword_587000_122848 == 0 || dword_5d4594_830972 == nil || dword_5d4594_830872 != dword_5d4594_830972 || audioStream2 == 0 || AIL_stream_status(audioStream2) == 2 {
			dword_5d4594_830864 = 4
			sub_486350(memmap.PtrOff(0x5D4594, 830876), 0)
		}
	case 4:
		if audioStream2 == 0 || AIL_stream_status(audioStream2) == 2 || (*memmap.PtrUint32(0x5D4594, 830880)&0xFFFF0000) == 0 {
			sub_44D640()
			dword_5d4594_830864 = 0
			if dword_5d4594_831084 != 0 {
				sub_43DBE0()
				dword_5d4594_831084 = 0
			}
			if dword_5d4594_830972 == dword_5d4594_830872 {
				dword_5d4594_830872 = nil
			}
		}
	default:
	}
	sub_486520(memmap.PtrOff(0x5D4594, 830980))
	sub_486520(memmap.PtrOff(0x5D4594, 830876))
	if audioStream2 != 0 && (int32(*(*uint8)(dword_587000_81128))&2 != 0 || int32(*memmap.PtrUint8(0x5D4594, 830876))&2 != 0 || int32(*memmap.PtrUint8(0x5D4594, 830980))&2 != 0) {
		sub_44D5C0(audioStream2, *memmap.PtrInt32(0x5D4594, 830860))
	}
}
func sub_44D5C0(a1 ail.Stream, a2 int32) {
	if a1 != 0 {
		v2 := (*(*uint32)(unsafe.Add(dword_587000_81128, 4)) >> 16) * ((uint32(*memmap.PtrUint16(0x5D4594, 830882)) * ((uint32(a2) * uint32(*memmap.PtrUint16(0x5D4594, 830986))) >> 14)) >> 14)
		*memmap.PtrUint32(0x5D4594, 830876) &= 0xFFFFFFFD
		*(*uint32)(dword_587000_122852) &= 0xFFFFFFFD
		AIL_set_stream_volume(a1, int32((v2>>14)*math.MaxInt8)/100)
	}
}
func sub_44D8C0() {
	if dword_5d4594_831076 != 0 {
		sub_44D8F0()
		sub_44D640()
		Sub_44D3A0()
		dword_5d4594_831076 = 0
	}
}
func nox_xxx_playDialogFile_44D900(a1p *byte, a2 int32) int32 {
	var (
		a1 = unsafe.Pointer(a1p)
		v2 int32
	)
	if !(dword_587000_122848 != 0 && a1 != nil) {
		return 1
	}
	v2 = a2
	if a2 > 100 {
		v2 = 100
	}
	dword_5d4594_830872 = a1
	*memmap.PtrUint32(0x5D4594, 830868) = uint32(v2)
	return 1
}
func sub_44D930() int32 {
	if dword_587000_122848 == 0 {
		return 0
	}
	if dword_5d4594_830872 != nil || audioStream2 != 0 {
		return 1
	}
	return 0
}
func sub_44D960() {
	dword_587000_122848 = 0
}
func sub_44D970() int32 {
	var result int32
	result = int32(dword_5d4594_831092)
	if dword_5d4594_831092 != 0 {
		dword_587000_122848 = 1
	}
	return result
}
func sub_44D990() int32 {
	return int32(dword_587000_122848)
}
func sub_44E110() {
	if dword_5d4594_832484 == 0 {
		dword_5d4594_832484 = uint32(uintptr(nox_xxx_guiFontPtrByName_43F360(internCStr("default"))))
	}
	v0 := dword_5d4594_832496
	if dword_5d4594_832496 == nil {
		v1 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GauntletExitB"))
		v0 = nox_new_drawable_for_thing(v1)
		dword_5d4594_832496 = v0
	}
	v0.Flags30Val |= 0x1000000
	v2 := dword_5d4594_832492
	if dword_5d4594_832492 == nil {
		v3 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BeholderGenerator"))
		v2 = nox_new_drawable_for_thing(v3)
		dword_5d4594_832492 = v2
	}
	v2.Flags30Val |= 0x1000000
	v4 := dword_5d4594_832500
	if dword_5d4594_832500 == nil {
		v5 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Ankh"))
		v4 = nox_new_drawable_for_thing(v5)
		dword_5d4594_832500 = v4
	}
	v4.Flags30Val |= 0x1000000
	v6 := dword_5d4594_832504
	if dword_5d4594_832504 == nil {
		v7 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SoulGate"))
		v6 = nox_new_drawable_for_thing(v7)
		dword_5d4594_832504 = v6
	}
	v6.Flags30Val |= 0x1000000
	v8 := dword_5d4594_832508
	if dword_5d4594_832508 == nil {
		v9 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SilverKey"))
		v8 = nox_new_drawable_for_thing(v9)
		dword_5d4594_832508 = v8
	}
	v8.Flags30Val |= 0x1000000
	v10 := dword_5d4594_832512
	if dword_5d4594_832512 == nil {
		v11 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GoldKey"))
		v10 = nox_new_drawable_for_thing(v11)
		dword_5d4594_832512 = v10
	}
	v10.Flags30Val |= 0x1000000
	v12 := dword_5d4594_832516
	if dword_5d4594_832516 == nil {
		v13 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("QuestGoldChest"))
		v12 = nox_new_drawable_for_thing(v13)
		dword_5d4594_832516 = v12
	}
	v12.Flags30Val |= 0x1000000
	v14 := dword_5d4594_832520
	if dword_5d4594_832520 == nil {
		v15 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("QuestGoldPile"))
		v14 = nox_new_drawable_for_thing(v15)
		dword_5d4594_832520 = v14
	}
	v14.Flags30Val |= 0x1000000
	v16 := dword_5d4594_832524
	if dword_5d4594_832524 == nil {
		v17 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DunMirChest4"))
		v16 = nox_new_drawable_for_thing(v17)
		dword_5d4594_832524 = v16
	}
	v16.Flags30Val |= 0x1000000
	v18 := dword_5d4594_832528
	if dword_5d4594_832528 == nil {
		v19 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("WarHammer"))
		v18 = nox_new_drawable_for_thing(v19)
		dword_5d4594_832528 = v18
	}
	v18.Flags30Val |= 0x1000000
	v20 := dword_5d4594_832532
	if dword_5d4594_832532 == nil {
		v21 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("HastePotion"))
		v20 = nox_new_drawable_for_thing(v21)
		dword_5d4594_832532 = v20
	}
	v20.Flags30Val |= 0x1000000
	result := dword_5d4594_832536
	if dword_5d4594_832536 == nil {
		v23 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ConjurerSpellBook"))
		result = nox_new_drawable_for_thing(v23)
		dword_5d4594_832536 = result
	}
	result.Flags30Val |= 0x1000000
}
func nox_xxx_playGMCAPsmth_44E3E0() {
	*memmap.PtrUint32(0x5D4594, 831248) = 1
	if dword_5d4594_831224 != 0 {
		nox_xxx_playDialogFile_44D900(dword_5d4594_831240, 100)
		dword_5d4594_831244 = 1
	}
}
func sub_44E560() *gui.Window {
	*memmap.PtrUint32(0x5D4594, 831284) = uint32((nox_win_width - NOX_DEFAULT_WIDTH) / 2)
	*memmap.PtrUint32(0x5D4594, 831288) = uint32((nox_win_height - NOX_DEFAULT_HEIGHT) / 2)
	r1 := nox_window_new(nil, 56, 0, 0, int(nox_win_width), int(nox_win_height), nox_xxx_wndProc_44E6E0)
	dword_5d4594_831236 = r1
	if r1 == nil {
		return nil
	}
	nox_xxx_wndSetWindowProc_46B300(r1, nox_client_wndQuestBriefProc_44E630)
	dword_5d4594_831236.DrawData().BgColorVal = nox_color_black_2650656
	nox_wnd_briefing_831232 = nox_new_window_from_file(internCStr("Briefing.wnd"), nil)
	r2 := nox_wnd_briefing_831232
	if r2 == nil {
		return nil
	}
	sub_46B120(r2, dword_5d4594_831236)
	nox_window_setPos_46A9B0(nox_wnd_briefing_831232, *memmap.PtrInt32(0x5D4594, 831284), *memmap.PtrInt32(0x5D4594, 831288))
	v1 := nox_xxx_wndGetChildByID_46B0C0(nox_wnd_briefing_831232, 1010)
	nox_xxx_wndSetDrawFn_46B340(v1, sub_44E6F0)
	sub_44E410()
	return dword_5d4594_831236
}
func nox_client_wndQuestBriefProc_44E630(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	var v2 int32
	if !(*memmap.PtrUint32(0x5D4594, 831248) != 0 && p2 != 18 && p2 != 17 && sub_41D1B0() != 1) {
		return 1
	}
	sub_450580()
	if dword_5d4594_831220 != 0 {
		if dword_5d4594_831220 == math.MaxUint8 {
			nox_gameDisableMapDraw_5d4594_2650672 = 0
			v2 = nox_client_getIntroScreenDuration_44E3B0()
			nox_video_fadeInScreen_44DAB0(v2, 1, ccall.FuncAddr(sub_44E320))
			nox_gameDisableMapDraw_5d4594_2650672 = 1
		}
	} else {
		nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_831236)
		nox_xxx_windowFocus_46B500(nil)
		dword_5d4594_831256 = 1
		nox_savegame_sub_46D580()
	}
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_831236, nil)
	return 1
}
func nox_xxx_wndProc_44E6E0(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	return uintptr(bool2int(p2 == 23))
}
func sub_44E6F0(a1 *gui.Window, a2 *gui.WindowData) int {
	dword_5d4594_831276 = float32(float64(dword_5d4594_831276) - sub_44E8B0())
	v2 := int32(dword_5d4594_831276)
	nox_window_setPos_46A9B0(a1, 0, v2)
	nox_client_copyRect_49F6F0(*memmap.PtrInt32(0x5D4594, 831284), *memmap.PtrInt32(0x5D4594, 831288), NOX_DEFAULT_WIDTH, NOX_DEFAULT_HEIGHT)
	if int32(*memmap.PtrUint8(0x5D4594, 832472))&1 != 0 {
		sub_44E8E0(int32(uintptr(unsafe.Pointer(a1))), a2)
	} else if int32(*memmap.PtrUint8(0x5D4594, 832472))&2 != 0 {
		sub_44F0F0(int32(uintptr(unsafe.Pointer(a1))), a2)
	} else if int32(*memmap.PtrUint8(0x5D4594, 832472))&4 != 0 {
		sub_44F300(int32(uintptr(unsafe.Pointer(a1))), a2)
	} else {
		nox_xxx_wndStaticDrawNoImage_488D00(a1, a2)
	}
	nox_client_copyRect_49F6F0(0, 0, nox_getBackbufWidth(), nox_getBackbufHeight())
	if !(int64(dword_5d4594_831276) <= int64(*memmap.PtrInt32(0x5D4594, 831280)) && dword_5d4594_831244 == 1 && sub_44D930() == 0 && (uint64(nox_platform_get_ticks())-*memmap.PtrUint64(0x5D4594, 831292)) > uint64(nox_client_getBriefDuration()) && (*memmap.PtrUint32(0x5D4594, 832488) == 1 || (int32(*memmap.PtrUint8(0x5D4594, 832472))&5) == 0)) {
		return 1
	}
	if int32(*memmap.PtrUint8(0x5D4594, 832472))&2 != 0 && dword_5d4594_832480 != 0 {
		nox_xxx_clientPlaySoundSpecial_452D80(582, 100)
	}
	sub_450580()
	if dword_5d4594_831220 != 0 {
		nox_gameDisableMapDraw_5d4594_2650672 = 0
		v3 := nox_client_getIntroScreenDuration_44E3B0()
		nox_video_fadeInScreen_44DAB0(v3, 1, ccall.FuncAddr(sub_44E320))
		nox_gameDisableMapDraw_5d4594_2650672 = 1
	} else if dword_5d4594_831256 == 0 {
		nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_831236)
		dword_5d4594_831256 = 1
		nox_savegame_sub_46D580()
		nox_xxx_wndSetWindowProc_46B300(dword_5d4594_831236, nil)
	}
	nox_xxx_wndSetDrawFn_46B340(a1, sub_44E8D0)
	return 1
}
func sub_44E8B0() float64 {
	var result float64
	if dword_5d4594_831220 == math.MaxUint8 {
		result = 1.0
	} else {
		result = 0.0
	}
	return result
}
func sub_44E8D0(win *gui.Window, draw *gui.WindowData) int {
	return 1
}
func nox_client_lockScreenBriefing_450160(a1 int32, a2 int32, a3 int8) int32 {
	var (
		v3     int32
		v4     int32
		v6     int32
		v10    int32
		v12    int32
		result int32
		v14    int32
		v15    **uint16
	)
	v3 = a1
	dword_5d4594_831260 = 1
	dword_5d4594_831244 = 1
	v14 = int32(*memmap.PtrUint32(0x8531A0, 2576))
	*memmap.PtrUint32(0x5D4594, 832488) = 0
	*memmap.PtrUint32(0x5D4594, 832472) = 0
	dword_5d4594_831256 = 0
	*memmap.PtrUint8(0x5D4594, 831252) = uint8(int8(a1 + 1))
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
		v4 = int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251)))
	} else {
		v4 = a2
	}
	nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_831236)
	nox_xxx_wndSetCaptureMain_46ADC0(dword_5d4594_831236)
	nox_xxx_windowFocus_46B500(dword_5d4594_831236)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_831236, nox_client_wndQuestBriefProc_44E630)
	v5 := nox_xxx_wndGetChildByID_46B0C0(nox_wnd_briefing_831232, 1010)
	nox_xxx_wndSetDrawFn_46B340(v5, sub_44E6F0)
	dword_5d4594_831220 = uint32(a2)
	v15 = (**uint16)(v5.WidgetData)
	if v3 == math.MaxUint8 {
		nox_xxx_wndSetIcon_46AE60(nox_wnd_briefing_831232, nil)
		nox_window_call_field_94_fnc(v5, 16385, uintptr(*memmap.PtrInt32(0x5D4594, 831268)), 0)
		nox_xxx_wndClearFlag_46AD80(v5, 0x2000)
		dword_5d4594_831240 = nox_xxx_GetEndgameDialog_578D80()
		v6 = 24
		dword_5d4594_831220 = math.MaxUint8
	} else if v3 == 254 {
		nox_server_currentMapGetFilename_409B30()
		v7 := nox_xxx_gLoadImg_42F970(internCStr("GauntletStartMines"))
		nox_xxx_wndSetIcon_46AE60(nox_wnd_briefing_831232, v7)
		nox_window_call_field_94_fnc(v5, 16385, uintptr(memmap.PtrOff(0x5D4594, 832540)), 0)
		v6 = 0
		if int32(a3)&1 != 0 {
			*memmap.PtrUint32(0x5D4594, 832472) = 1
			v8 := nox_xxx_gLoadImg_42F970(internCStr("MenuSystemBG"))
			nox_xxx_wndSetIcon_46AE60(nox_wnd_briefing_831232, v8)
			nox_client_resetScreenParticles_431510()
			nox_xxx_bookHideMB_45ACA0(1)
		} else if int32(a3)&4 != 0 {
			*memmap.PtrUint32(0x5D4594, 832472) = 4
			v9 := nox_xxx_gLoadImg_42F970(internCStr("GauntletInstructionBackground"))
			nox_xxx_wndSetIcon_46AE60(nox_wnd_briefing_831232, v9)
			nox_client_resetScreenParticles_431510()
			nox_xxx_bookHideMB_45ACA0(1)
		} else {
			*memmap.PtrUint32(0x5D4594, 832472) = 2
			nox_xxx_wndSetIcon_46AE60(nox_wnd_briefing_831232, noxrender.ImageHandle(*memmap.PtrPtr(0x5D4594, 832460)))
			if *memmap.PtrUint32(0x5D4594, 832464) != 0 {
				nox_window_call_field_94_fnc(v5, 16385, uintptr(*memmap.PtrInt32(0x5D4594, 832464)), 0)
			}
			nox_client_resetScreenParticles_431510()
			nox_xxx_bookHideMB_45ACA0(1)
		}
		sub_446780()
		dword_5d4594_831240 = nil
		dword_5d4594_831244 = 1
		dword_5d4594_831224 = 0
	} else {
		v10 = (v3 + v4 + v4*10) * 32
		var v11 unsafe.Pointer
		if a2 != 0 {
			nox_xxx_wndSetIcon_46AE60(nox_wnd_briefing_831232, noxrender.ImageHandle(*memmap.PtrPtr(0x5D4594, uintptr(v10)+831300)))
			nox_window_call_field_94_fnc(v5, 16385, uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v10)+831304)), 0)
			v11 = *memmap.PtrPtr(0x5D4594, uintptr(v10)+831308)
			v6 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v10)+831312))
		} else {
			nox_xxx_wndSetIcon_46AE60(nox_wnd_briefing_831232, noxrender.ImageHandle(*memmap.PtrPtr(0x5D4594, uintptr(v10)+831316)))
			nox_window_call_field_94_fnc(v5, 16385, uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v10)+831320)), 0)
			v11 = *memmap.PtrPtr(0x5D4594, uintptr(v10)+831324)
			v6 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v10)+831328))
		}
		dword_5d4594_831240 = (*byte)(v11)
	}
	nox_xxx_drawGetStringSize_43F840(v5.DrawData().FontPtr, *v15, nil, (*int32)(memmap.PtrOff(0x5D4594, 831280)), NOX_DEFAULT_HEIGHT)
	sub_46AB20(v5, NOX_DEFAULT_WIDTH, *memmap.PtrInt32(0x5D4594, 831280))
	if v3 == math.MaxUint8 {
		dword_5d4594_831276 = 1140457472
		*memmap.PtrUint32(0x5D4594, 831280) = 4294967276 - *memmap.PtrUint32(0x5D4594, 831280)
	} else {
		*memmap.PtrUint32(0x5D4594, 831280) = uint32((480 - nox_xxx_guiFontHeightMB_43F320(v5.DrawData().FontPtr) - *memmap.PtrInt32(0x5D4594, 831280)) / 2)
		dword_5d4594_831276 = float32(float64(*memmap.PtrInt32(0x5D4594, 831280)))
	}
	sub_431290()
	dword_5d4594_831224 = 0
	if a2 != 0 || v3 == math.MaxUint8 {
		if v3 != 254 {
			dword_5d4594_831224 = 1
		}
	} else if v3 != 254 {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v14+v3*4)), 4408)) != 0 {
			nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_831236)
			dword_5d4594_831256 = 1
			nox_savegame_sub_46D580()
			nox_xxx_wndSetWindowProc_46B300(dword_5d4594_831236, nil)
		} else {
			dword_5d4594_831224 = 1
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v14+v3*4)), 4408)) = 1
		}
	}
	sub_43DD70(v6, 50)
	*memmap.PtrUint64(0x5D4594, 831292) = uint64(nox_platform_get_ticks())
	*memmap.PtrUint32(0x5D4594, 831248) = 0
	v12 = nox_client_getIntroScreenDuration_44E3B0()
	nox_video_fadeOutScreen_44DB30(v12, 1, ccall.FuncAddr(nox_xxx_playGMCAPsmth_44E3E0))
	result = int32(dword_5d4594_831224)
	if dword_5d4594_831224 != 0 {
		dword_5d4594_831244 = 0
	}
	return result
}
func sub_4505E0() {
	if dword_5d4594_831236 != nil {
		nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_831236)
		dword_5d4594_831236 = nil
		nox_wnd_briefing_831232 = nil
	}
	dword_5d4594_831260 = 0
	dword_5d4594_832484 = 0
	if dword_5d4594_832504 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832504)
	}
	dword_5d4594_832504 = nil
	if dword_5d4594_832492 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832492)
	}
	dword_5d4594_832492 = nil
	if dword_5d4594_832500 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832500)
	}
	dword_5d4594_832500 = nil
	if dword_5d4594_832496 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832496)
	}
	dword_5d4594_832496 = nil
	if dword_5d4594_832508 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832508)
	}
	dword_5d4594_832508 = nil
	if dword_5d4594_832512 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832512)
	}
	dword_5d4594_832512 = nil
	if dword_5d4594_832516 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832516)
	}
	dword_5d4594_832516 = nil
	if dword_5d4594_832520 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832520)
	}
	dword_5d4594_832520 = nil
	if dword_5d4594_832524 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832524)
	}
	dword_5d4594_832524 = nil
	if dword_5d4594_832528 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832528)
	}
	dword_5d4594_832528 = nil
	if dword_5d4594_832532 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832532)
	}
	dword_5d4594_832532 = nil
	if dword_5d4594_832536 != nil {
		nox_xxx_spriteDelete_45A4B0(dword_5d4594_832536)
	}
	dword_5d4594_832536 = nil
}
func sub_450750() uint8 {
	return *memmap.PtrUint8(0x5D4594, 831252)
}
func sub_450760(a1 int8) int8 {
	var result int8
	result = a1
	*memmap.PtrUint8(0x5D4594, 831252) = uint8(a1)
	return result
}
func sub_450960(a1 unsafe.Pointer, a2 unsafe.Pointer) int32 {
	var (
		v2     uint32
		v3     uint32
		result int32
	)
	v2 = *(*uint32)(unsafe.Add(a1, 4*3))
	v3 = *(*uint32)(unsafe.Add(a2, 4*3))
	if v2 == v3 {
		result = 0
	} else {
		if v2 < v3 {
			result = 1
		} else {
			result = -1
		}
	}
	return result
}
func sub_450AD0(a1 noxrender.ImageHandle) {
	result := a1
	if a1 == nil {
		result = nox_xxx_gLoadImg_42F970(internCStr("WarriorChapterBegin8"))
	}
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 832460) = result
}
func sub_450AF0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 832464) = uint32(a1)
	return result
}
func nox_gui_setQuestStage_450B00(a1 int32) {
	*memmap.PtrUint32(0x5D4594, 832468) = uint32(a1)
}
func nox_gui_getQuestStage_450B10() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 832468))
}
func Sub_451850(a2 unsafe.Pointer, a3 unsafe.Pointer) int32 {
	var (
		v2     int32
		v3     *uint8
		result int32
	)
	v2 = 0
	v3 = (*uint8)(memmap.PtrOff(0x5D4594, 840712))
	for {
		sub_451920((*uint32)(unsafe.Add(unsafe.Pointer(v3), -int(4*21))))
		*(*uint32)(unsafe.Pointer(v3)) = uint32(uintptr(unsafe.Pointer(nox_xxx_getSndName_40AF80(v2))))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 200))
		v2++
		if int32(uintptr(unsafe.Pointer(v3))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1045312))) {
			break
		}
	}
	dword_5d4594_1045420 = a3
	dword_5d4594_1045428 = a2
	if a3 != nil {
		dword_5d4594_1045424 = sub_4BD340(a3, 0x100000, 200, 0x2000)
		dword_5d4594_1045436 = sub_4BD280(200, 576)
	}
	if dword_5d4594_1045424 == nil || dword_5d4594_1045420 == nil || dword_5d4594_1045428 == nil || dword_5d4594_1045436 == nil {
		return 0
	}
	nox_common_list_clear_425760((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 840612)))
	sub_4864A0((*uint32)(memmap.PtrOff(0x5D4594, 1045228)))
	result = 1
	*(*uint32)(unsafe.Add(dword_5d4594_1045428, 184)) = uint32(uintptr(memmap.PtrOff(0x5D4594, 1045228)))
	dword_5d4594_1045432 = 1
	return result
}
func sub_451920(a2 *uint32) int32 {
	*a2 = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*1)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*2)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*14)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*15)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*19)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*20)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*12)) = 1
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*48)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*18)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*17)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*25)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*26)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*16)) = 600
	return sub_4862E0(unsafe.Add(unsafe.Pointer(a2), 4*4), 0x4000)
}
func sub_451970() {
	sub_4521F0()
	sub_452230()
	if dword_5d4594_1045424 != nil {
		sub_4BD3C0(dword_5d4594_1045424)
		dword_5d4594_1045424 = nil
	}
	if dword_5d4594_1045436 != nil {
		sub_4BD2D0(dword_5d4594_1045436)
		dword_5d4594_1045436 = nil
	}
	dword_5d4594_1045432 = 0
}
func Sub_4519C0() {
	var (
		v3  int32
		v5  *uint8
		v6  *uint8
		v7  *uint8
		v8  int32
		v9  int32
		v10 int32
	)
	if dword_5d4594_1045432 == 0 {
		return
	}
	if *memmap.PtrUint32(0x5D4594, 1045448) != 0 {
		return
	}
	*memmap.PtrUint32(0x5D4594, 1045448) = 1
	sub_486520(dword_587000_127004)
	v1 := *memmap.PtrPtr(0x5D4594, 840612)
	*memmap.PtrUint32(0x5D4594, 1045440)++
	if unsafe.Pointer(*(**uint8)(memmap.PtrOff(0x5D4594, 840612))) != memmap.PtrOff(0x5D4594, 840612) {
		for {
			v2 := *(*unsafe.Pointer)(unsafe.Add(v1, 36))
			if *(*uint32)(unsafe.Add(v2, 100)) != *memmap.PtrUint32(0x5D4594, 1045440) {
				nox_common_list_clear_425760((*nox_list_item_t)(unsafe.Add(v2, 88)))
				*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 36)), 52)) = 0
				*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 36)), 100)) = *memmap.PtrUint32(0x5D4594, 1045440)
			}
			sub_486520(unsafe.Add(v1, 184))
			if *(*uint32)(unsafe.Add(v1, 28)) != 4 {
				sub_451BE0(v1)
			}
			v1 = *(*unsafe.Pointer)(v1)
			if v1 == memmap.PtrOff(0x5D4594, 840612) {
				break
			}
		}
		v1 = *memmap.PtrPtr(0x5D4594, 840612)
		if unsafe.Pointer(*(**uint8)(memmap.PtrOff(0x5D4594, 840612))) != memmap.PtrOff(0x5D4594, 840612) {
			for {
				sub_452510(v1)
				v1 = *(*unsafe.Pointer)(v1)
				if v1 == memmap.PtrOff(0x5D4594, 840612) {
					break
				}
			}
			v1 = *memmap.PtrPtr(0x5D4594, 840612)
		}
	}
	v3 = 0
	sub_452010()
	if v1 != memmap.PtrOff(0x5D4594, 840612) {
		for {
			v4 := *(*unsafe.Pointer)(unsafe.Add(v1, 176))
			v5 = *(**uint8)(v1)
			if v4 == nil || v1 != *(*unsafe.Pointer)(unsafe.Add(v4, 152)) {
				sub_4523D0(v1)
			}
			if int32(*(*uint8)(unsafe.Add(v1, 24)))&1 != 0 {
				sub_451FE0(v1)
			} else {
				v3 += int32(((*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 36)), 20)) >> 16) * 33) >> 14)
				sub_452050((*uint32)(v1))
			}
			v1 = unsafe.Pointer(v5)
			if unsafe.Pointer(v5) == memmap.PtrOff(0x5D4594, 840612) {
				break
			}
		}
	}
	if v3 <= 100 {
		sub_486350(memmap.PtrOff(0x5D4594, 1045228), 0x4000)
	} else {
		sub_486350(memmap.PtrOff(0x5D4594, 1045228), int32(0x190000/uint32(v3)))
	}
	sub_486520(memmap.PtrOff(0x5D4594, 1045228))
	v6 = *(**uint8)(memmap.PtrOff(0x5D4594, 840612))
	if unsafe.Pointer(*(**uint8)(memmap.PtrOff(0x5D4594, 840612))) != memmap.PtrOff(0x5D4594, 840612) {
		for {
			v7 = *(**uint8)(unsafe.Pointer(v6))
			result := int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*7)))
			if result == 1 {
				sub_451DC0(int32(uintptr(unsafe.Pointer(v6))))
				v8 = sub_451CA0((*uint32)(unsafe.Pointer(v6)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*74)) = uint32(v8)
				if v8 == 0 {
					for {
						if sub_452120(unsafe.Pointer(v6)) == 0 {
							break
						}
						v7 = *(**uint8)(unsafe.Pointer(v6))
						sub_451DC0(int32(uintptr(unsafe.Pointer(v6))))
						v9 = sub_451CA0((*uint32)(unsafe.Pointer(v6)))
						*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*74)) = uint32(v9)
						if v9 != 0 {
							break
						}
					}
				}
				v10 = sub_451CA0((*uint32)(unsafe.Pointer(v6)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*74)) = uint32(v10)
				if v10 == 0 || (func() int32 {
					result = sub_452490(unsafe.Pointer(v6))
					return result
				}()) == 0 {
					sub_4523D0(unsafe.Pointer(v6))
					sub_451FE0(unsafe.Pointer(v6))
				}
			}
			v6 = v7
			if unsafe.Pointer(v7) == memmap.PtrOff(0x5D4594, 840612) {
				break
			}
		}
	}
	*memmap.PtrUint32(0x5D4594, 1045448) = 0
}
func sub_451BE0(a1 unsafe.Pointer) {
	var (
		v3  uint32
		v4  *uint32
		v5  int32
		v6  int32
		v7  *uint32
		v9  int32
		v10 *uint32
	)
	v1 := a1
	v2 := *(*unsafe.Pointer)(unsafe.Add(a1, 36))
	v3 = *(*uint32)(unsafe.Add(a1, 188)) >> 16
	v4 = *(**uint32)(unsafe.Add(v2, 88))
	if v4 != (*uint32)(unsafe.Add(v2, 88)) {
		for {
			v5 = int32((*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*44)) >> 16) - v3)
			if v5 < 0 {
				v5 = int32(v3 - (*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*44)) >> 16))
			}
			if uint32(v5) >= (*(*uint32)(unsafe.Add(v2, 20))>>16)/10 {
				if *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*44))>>16 < v3 {
					break
				}
			} else {
				v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*4)))
				if int32(*(*uint8)(unsafe.Add(v2, 4)))&0x10 != 0 {
					if v6 != 0 {
						break
					}
				} else if v6 == 0 {
					break
				}
			}
			v4 = (*uint32)(unsafe.Pointer(uintptr(*v4)))
			if v4 == (*uint32)(unsafe.Add(v2, 88)) {
				break
			}
		}
		v1 = a1
	}
	v7 = (*uint32)(unsafe.Add(v1, 12))
	sub_425770(unsafe.Add(v1, 12))
	nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Pointer(v4)), (*nox_list_item_t)(unsafe.Pointer(v7)))
	result := int32(*(*uint32)(unsafe.Add(v2, 56)))
	v9 = int32(*(*uint32)(unsafe.Add(v2, 52)) + 1)
	*(*uint32)(unsafe.Add(v2, 52)) = uint32(v9)
	if result != 0 {
		if v9 > result {
			v10 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v2, 92)) - 12)))
			nox_common_list_remove_425920(unsafe.Pointer(*(***uint32)(unsafe.Add(v2, 92))))
			sub_4523D0(unsafe.Pointer(v10))
			result := int32(*(*uint32)(unsafe.Add(v2, 52)) - 1)
			*(*uint32)(unsafe.Add(v2, 52)) = uint32(result)
		}
	}
}
func sub_451CA0(a1 *uint32) int32 {
	var (
		v1 int32
		v3 int32
		v4 *uint32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*42)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*108)) = uint32(v1)
	if v1 == 0 {
		return 0
	}
	v3 = 0
	if v1 > 0 {
		v4 = (*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*76))
		for {
			*v4 = uint32(func() int32 {
				p := &v3
				x := *p
				*p++
				return x
			}())
			v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
			if uint32(v3) >= *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*108)) {
				break
			}
		}
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*43)) = math.MaxUint32
	return sub_451CF0(a1)
}
func sub_451F30(a1 unsafe.Pointer, a2 int32) int32 {
	var (
		v2     int32
		result int32
	)
	*(*uint32)(unsafe.Add(a1, *(*uint32)(unsafe.Add(a1, 168))*4+40)) = uint32(uintptr(sub_4BD470(dword_5d4594_1045424, int32(*(*int16)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(a1, 36))+uint32(a2*2))), 128))))))
	v2 = int32(*(*uint32)(unsafe.Add(a1, 168)))
	result = int32(*(*uint32)(unsafe.Add(a1, v2*4+40)))
	if result == 0 {
		return result
	}
	sub_4BD650(*(*unsafe.Pointer)(unsafe.Add(a1, v2*4+40)))
	result = int32(*(*uint32)(unsafe.Add(a1, 168)) + 1)
	*(*uint32)(unsafe.Add(a1, 168)) = uint32(result)
	return result
}
func sub_451F90(a1 unsafe.Pointer) {
	var (
		v1     int32
		result int32
	)
	v1 = 0
	result = int32(*(*uint32)(unsafe.Add(a1, 168)))
	if result <= 0 {
		*(*uint32)(unsafe.Add(a1, 168)) = 0
	} else {
		v3 := (*unsafe.Pointer)(unsafe.Add(a1, 40))
		for {
			sub_4BD660(*v3)
			*v3 = nil
			result = int32(*(*uint32)(unsafe.Add(a1, 168)))
			v1++
			v3 = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*1))
			if v1 >= result {
				break
			}
		}
		*(*uint32)(unsafe.Add(a1, 168)) = 0
	}
}
func sub_451FE0(a1 unsafe.Pointer) {
	nox_common_list_remove_425920(a1)
	*(*uint32)(unsafe.Add(a1, 280)) = 0
	sub_4BD300(dword_5d4594_1045436, a1)
}
func sub_452010() int32 {
	var (
		v0 *uint8
		v1 int32
		v2 int32
	)
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 839892))
	v1 = 6
	for {
		v2 = 10
		for {
			nox_common_list_clear_425760((*nox_list_item_t)(unsafe.Pointer(v0)))
			v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 12))
			v2--
			if v2 == 0 {
				break
			}
		}
		v1--
		if v1 == 0 {
			break
		}
	}
	return int32(func() uint32 {
		p := mem_getU32Ptr(0x5D4594, 1045444)
		*p++
		return *p
	}())
}
func sub_452050(a1 *uint32) {
	v1 := (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*9)))
	v2 := int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*12)) + *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*75)))
	v3 := (*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*47)) >> 16) / 0x666
	v4 := (*uint8)(memmap.PtrOff(0x5D4594, uintptr(v2*120)+839892))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*26)) == *memmap.PtrUint32(0x5D4594, 1045444) {
		result := *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*27))
		if v2 <= result {
			if v2 == result && v3 > *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*31)) {
				*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*31)) = v3
				v7 := unsafe.Add(unsafe.Pointer(v1), 4*28)
				nox_common_list_remove_425920(v7)
				nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Add(unsafe.Pointer(v4), v3*12)), (*nox_list_item_t)(v7))
			}
		} else {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*27)) = uint32(v2)
			*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*31)) = v3
			v6 := (**uint32)(unsafe.Add(unsafe.Pointer(v1), 4*28))
			nox_common_list_remove_425920(unsafe.Pointer(v6))
			nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Add(unsafe.Pointer(v4), v3*12)), (*nox_list_item_t)(unsafe.Pointer(v6)))
		}
	} else {
		*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*26)) = *memmap.PtrUint32(0x5D4594, 1045444)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*27)) = uint32(v2)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*31)) = v3
		v8 := unsafe.Add(unsafe.Pointer(v1), 4*28)
		sub_425770(v8)
		nox_common_list_append_4258E0((*nox_list_item_t)(unsafe.Add(unsafe.Pointer(v4), v3*12)), (*nox_list_item_t)(v8))
	}
}
func sub_452120(a1 unsafe.Pointer) int32 {
	var (
		v1     int32
		result *int32
		v3     *int32
		v4     *uint8
		v5     *uint8
	)
	v1 = 0
	result = sub_4521A0(int32(*(*uint32)(unsafe.Add(a1, 300)) + *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 36)), 48))))
	v3 = result
	if result == nil {
		return 0
	}
	sub_452190(unsafe.Pointer(result))
	v4 = *(**uint8)(memmap.PtrOff(0x5D4594, 840612))
	if unsafe.Pointer(*(**uint8)(memmap.PtrOff(0x5D4594, 840612))) == memmap.PtrOff(0x5D4594, 840612) {
		return v1
	}
	for {
		v5 = *(**uint8)(unsafe.Pointer(v4))
		if *(**int32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*int32)(nil))*9)) == v3 {
			sub_4523D0(unsafe.Pointer(v4))
			sub_451FE0(unsafe.Pointer(v4))
			v1 = 1
		}
		v4 = v5
		if unsafe.Pointer(v5) == memmap.PtrOff(0x5D4594, 840612) {
			break
		}
	}
	return v1
}
func sub_452190(a1 unsafe.Pointer) {
	nox_common_list_remove_425920(unsafe.Add(a1, 112))
}
func sub_4521A0(a1 int32) *int32 {
	var (
		v1 int32
		v2 *uint8
		v3 int32
		v4 *int32
		v5 *int32
	)
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 839892))
	if a1 <= 0 {
		return nil
	}
	for {
		v3 = 0
		v4 = (*int32)(unsafe.Pointer(v2))
		for {
			v5 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(v4)))))
			if v5 != nil {
				return (*int32)(unsafe.Add(unsafe.Pointer(v5), -int(4*28)))
			}
			v3++
			v4 = (*int32)(unsafe.Add(unsafe.Pointer(v4), 4*3))
			if v3 >= 10 {
				break
			}
		}
		v1++
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 120))
		if v1 < a1 {
			continue
		}
		break
	}
	return nil
}
func sub_4521F0() {
	if dword_5d4594_1045432 == 0 {
		return
	}
	v1 := *(**uint8)(memmap.PtrOff(0x5D4594, 840612))
	if unsafe.Pointer(*(**uint8)(memmap.PtrOff(0x5D4594, 840612))) == memmap.PtrOff(0x5D4594, 840612) {
		return
	}
	for {
		v2 := *(**uint8)(unsafe.Pointer(v1))
		sub_4523D0(unsafe.Pointer(v1))
		sub_451FE0(unsafe.Pointer(v1))
		v1 = v2
		if unsafe.Pointer(v2) == memmap.PtrOff(0x5D4594, 840612) {
			break
		}
	}
}
func sub_452230() {
	if dword_5d4594_1045432 != 0 {
		result := *(*unsafe.Pointer)(memmap.PtrOff(0x5D4594, 840612))
		if unsafe.Pointer(*(**uint8)(memmap.PtrOff(0x5D4594, 840612))) != memmap.PtrOff(0x5D4594, 840612) {
			for {
				v1 := *(*unsafe.Pointer)(result)
				if int32(uint8(uintptr(*(*unsafe.Pointer)(unsafe.Add(result, 4*6)))))&1 != 0 {
					sub_451FE0(result)
				}
				result = v1
				if v1 == memmap.PtrOff(0x5D4594, 840612) {
					break
				}
			}
		}
	}
}
func nox_xxx_draw_452270(a1 int32) unsafe.Pointer {
	if dword_5d4594_1045432 != 0 && a1 >= 0 && a1 < 1023 {
		return memmap.PtrOff(0x5D4594, uintptr(a1*200)+840628)
	} else {
		return nil
	}
}
func sub_4522A0(a1 unsafe.Pointer) int32 {
	if dword_5d4594_1045432 != 0 {
		return int32(*(*uint32)(unsafe.Add(a1, 64)))
	} else {
		return 0
	}
}
func nox_xxx_draw_452300(a1 unsafe.Pointer) unsafe.Pointer {
	if dword_5d4594_1045432 == 0 {
		return nil
	}
	if dword_587000_126996 == 0 {
		return nil
	}
	if *(*uint32)(a1) == 0 {
		return nil
	}
	v1 := sub_4BD2E0(dword_5d4594_1045436)
	if v1 == nil {
		sub_452230()
		v1 = sub_4BD2E0(dword_5d4594_1045436)
		if v1 == nil {
			return nil
		}
	}
	libc.MemSet(v1, 0, 0x240)
	*(*unsafe.Pointer)(unsafe.Add(v1, 4*9)) = a1
	sub_425770(v1)
	*(*uint32)(unsafe.Add(v1, 4*7)) = 0
	*(*uint32)(unsafe.Add(v1, 4*75)) = 0
	*(*uint32)(unsafe.Add(v1, 4*142)) = 0
	*(*uint32)(unsafe.Add(v1, 4*108)) = 0
	*(*uint32)(unsafe.Add(v1, 4*42)) = 0
	sub_4864A0((*uint32)(unsafe.Add(v1, 4*46)))
	nox_common_list_append_4258E0((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 840612)), (*nox_list_item_t)(v1))
	*(*uint32)(unsafe.Add(v1, 4*70)) = func() uint32 {
		p := mem_getU32Ptr(0x587000, 127000)
		x := *p
		*p++
		return x
	}()
	return v1
}
func sub_4523D0(a1 unsafe.Pointer) {
	if (*(*uint32)(unsafe.Add(a1, 4*6)) & 1) == 0 {
		sub_452410(a1)
		sub_451F90(a1)
		*(*uint32)(unsafe.Add(a1, 4*7)) = 4
		*(*uint32)(unsafe.Add(a1, 4*70)) = 0
		result := int32(*(*uint32)(unsafe.Add(a1, 4*6)))
		*(*uint8)(unsafe.Pointer(&result)) = uint8(int8(result | 1))
		*(*uint32)(unsafe.Add(a1, 4*6)) = uint32(result)
	}
}
func sub_452410(a1 unsafe.Pointer) {
	result := *(*unsafe.Pointer)(unsafe.Add(a1, 176))
	if result != nil && a1 == *(*unsafe.Pointer)(unsafe.Add(result, 152)) {
		if int32(*(*uint8)(unsafe.Add(a1, 24)))&2 != 0 {
			sub_4BDA80(*(*unsafe.Pointer)(unsafe.Add(a1, 176)))
		}
		sub_4BDB30(*(*unsafe.Pointer)(unsafe.Add(a1, 176)))
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 176)), 152)) = 0
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 176)), 148)) = 0
		r2 := *(*unsafe.Pointer)(unsafe.Add(a1, 176))
		*(*uint32)(unsafe.Add(r2, 140)) = 0
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 176)), 144)) = 0
		*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 176)), 112)) = 0
		*(*uint32)(unsafe.Add(a1, 176)) = 0
	}
}
func sub_452490(a1 unsafe.Pointer) int32 {
	v1 := *(*unsafe.Pointer)(unsafe.Add(a1, 4*44))
	if a1 != *(*unsafe.Pointer)(unsafe.Add(v1, 152)) {
		return 0
	}
	v3 := int32(*(*uint32)(unsafe.Add(a1, 4*74)))
	sub_4BDB90(v1, *(*unsafe.Pointer)(unsafe.Add(a1, 4*74)))
	*(*uint32)(unsafe.Add(a1, 4*7)) = 3
	v4 := int32(*(*uint32)(unsafe.Add(a1, 4*6)))
	*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(v4 | 2))
	*(*uint32)(unsafe.Add(a1, 4*6)) = uint32(v4)
	*(*uint32)(unsafe.Add(a1, 4*74)) = 0
	if sub_4BDB40(*(*unsafe.Pointer)(unsafe.Add(a1, 4*44))) == 0 {
		return 1
	}
	*(*uint32)(unsafe.Add(a1, 4*7)) = 1
	*(*uint32)(unsafe.Add(a1, 4*74)) = uint32(v3)
	*(*uint32)(unsafe.Add(a1, 4*6)) &= 0xFFFFFFFD
	return 0
}
func sub_452510(a3 unsafe.Pointer) {
	var (
		v1 int32
		v2 int32
	)
	if dword_587000_126996 == 0 {
		*(*uint32)(unsafe.Add(a3, 28)) = 4
	}
	for {
		v1 = int32(*(*uint32)(unsafe.Add(a3, 28)))
		if v1 == 0 {
			break
		}
		v2 = v1 - 2
		if v2 != 0 {
			var v3 uint32 = uint32(v2 - 2)
			if v3 == 0 {
				sub_4523D0(a3)
			}
			return
		}
		if uint64(nox_platform_get_ticks()) <= *(*uint64)(unsafe.Add(a3, 288)) {
			return
		}
		*(*uint32)(unsafe.Add(a3, 28)) = *(*uint32)(unsafe.Add(a3, 32))
	}
	if sub_452580((*uint32)(a3)) == 0 {
		sub_4523D0(a3)
	}
}
func sub_452690(a3 unsafe.Pointer, a4 int64, a5 int32) {
	*(*uint32)(unsafe.Add(a3, 32)) = uint32(a5)
	result := a4 + int64(nox_platform_get_ticks())
	*(*uint64)(unsafe.Add(a3, 288)) = uint64(result)
	*(*uint32)(unsafe.Add(a3, 28)) = 2
}
func sub_4526D0(a1 unsafe.Pointer) int32 {
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 152)), 28)) = 4
	return 0
}
func sub_4526F0(a1 unsafe.Pointer) int32 {
	var (
		v1 *uint32
		v2 int32
	)
	v1 = *(**uint32)(unsafe.Add(a1, 152))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*6)) &= 0xFFFFFFFD
	v2 = 4
	if *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*7)) == 4 {
		return 0
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*74)) != 0 || *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*142)) != 0 {
		v2 = 1
	} else {
		*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*71)) = 0
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*71)) != 0 {
		sub_452690(unsafe.Pointer(v1), int64(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*71))), v2)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*71)) = 0
		return 0
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*7)) = uint32(v2)
	return 0
}
func sub_452810(a1 int32, a2 int8) unsafe.Pointer {
	var (
		v2 unsafe.Pointer
		v3 unsafe.Pointer
	)
	v2 = nil
	if dword_5d4594_1045428 == nil {
		return v2
	}
	v3 = sub_487810(dword_5d4594_1045428, 1)
	v2 = v3
	if v3 == nil {
		return v2
	}
	if *(*int32)(unsafe.Add(v3, 4*31))&0x15 != 0 && *(*int32)(unsafe.Add(v3, 4*30)) > a1 {
		return nil
	}
	sub_4BDA80(v3)
	*(*int32)(unsafe.Add(v2, 4*29)) = int32(uintptr(dword_587000_127004))
	*(*int32)(unsafe.Add(v2, 4*30)) = a1
	if int32(a2)&1 != 0 {
		*(*int32)(unsafe.Add(v2, 4*32)) = -1
	} else {
		*(*int32)(unsafe.Add(v2, 4*32)) = 0
	}
	sub_486320(unsafe.Add(v2, 4*4), 0x4000)
	return v2
}
func nox_thing_read_AVNT_452890(a1p *binfile.MemFile, a2 unsafe.Pointer) int32 {
	var (
		a1     = unsafe.Pointer(a1p)
		v3     *uint8
		v4     int32
		v5     unsafe.Pointer
		v6     *byte
		v7     int8
		v8     *byte
		v9     int32
		v10    *uint8
		v11    int16
		v12    int32
		v13    *int32
		v14    int32
		v15    int16
		v16    int16
		v17    int32
		v18    *byte
		v19    int8
		result int32
		v22    *uint16
		v23    uint8
		v24    uint8
		v25    uint8
		v26    uint8
		v27    uint8
		v28    uint8
		v29    uint8
	)
	v2 := a1
	v3 = *(**uint8)(unsafe.Add(a1, 8))
	v21 := a1
	v28 = *v3
	*(*uint32)(unsafe.Add(v21, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v3), 1)))
	nox_memfile_read(a2, 1, int32(v28), (*binfile.MemFile)(v21))
	*(*uint8)(unsafe.Add(a2, v28)) = 0
	v4 = nox_xxx_utilFindSound_40AF50((*byte)(a2))
	if v4 != 0 && (func() unsafe.Pointer {
		v5 = nox_xxx_draw_452270(v4)
		return v5
	}()) != nil {
		for {
			v6 = *(**byte)(unsafe.Add(v2, 8))
			v7 = int8(*v6)
			v8 = (*byte)(unsafe.Add(unsafe.Pointer(v6), 1))
			*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Pointer(v8)))
			switch v7 {
			case 0:
				*(*uint32)(v5) = 1
				result = bool2int32(int32(v7) == 0)
			case 1:
				v23 = *v8
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v8), 1)))
				*(*uint32)(unsafe.Add(v5, 4*12)) = uint32(v23)
				continue
			case 2:
				v26 = *v8
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v8), 1)))
				*(*uint32)(unsafe.Add(v5, 4*1)) = uint32(v26)
				continue
			case 3:
				v27 = *v8
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v8), 1)))
				sub_4862E0(unsafe.Add(v5, 16), int32(v27)*163)
				continue
			case 4:
				v24 = *v8
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v8), 1)))
				*(*uint32)(unsafe.Add(v5, 4*14)) = uint32(v24)
				continue
			case 5:
				v25 = *v8
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v8), 1)))
				*(*uint32)(unsafe.Add(v5, 4*15)) = uint32(v25)
				continue
			case 6:
				v17 = int32(*v8)
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v8), 1)))
				*(*uint32)(unsafe.Add(v5, 4*19)) = uint32(v17)
				v18 = *(**byte)(unsafe.Add(v2, 8))
				v19 = int8(*v18)
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v18), 1)))
				*(*uint32)(unsafe.Add(v5, 4*20)) = uint32(v19)
				continue
			case 7:
				v9 = 0
				v22 = (*uint16)(unsafe.Add(v5, 128))
				for {
					v10 = *(**uint8)(unsafe.Add(v2, 8))
					v29 = *v10
					*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v10), 1)))
					if int32(v29) == 0 {
						break
					}
					nox_memfile_read(a2, 1, int32(v29), (*binfile.MemFile)(v2))
					*(*uint8)(unsafe.Add(a2, v29)) = 0
					if v9 < 32 {
						v11 = int16(uint16(sub_486A10(dword_5d4594_1045420, a2)))
						*v22 = uint16(v11)
						if int32(v11) != -1 {
							v9++
							v22 = (*uint16)(unsafe.Add(unsafe.Pointer(v22), unsafe.Sizeof(uint16(0))*1))
						}
					}
				}
				*(*uint32)(unsafe.Add(v5, 4*48)) = uint32(v9)
				continue
			case 8:
				v12 = int32(*(*uint32)(unsafe.Pointer(v8)))
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v8), 4)))
				*(*uint32)(unsafe.Add(v5, 4*17)) = uint32(v12)
				v13 = *(**int32)(unsafe.Add(v2, 8))
				v14 = *v13
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v13), 4*1)))
				*(*uint32)(unsafe.Add(v5, 4*18)) = uint32(v14)
				continue
			case 9:
				v15 = int16(*(*uint16)(unsafe.Pointer(v8)))
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v8), 2)))
				if int32(v15) > 0 {
					*(*uint32)(unsafe.Add(v5, 4*16)) = uint32(int32(v15) * 15)
				}
				continue
			case 0xA:
				v16 = int16(*(*uint16)(unsafe.Pointer(v8)))
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v8), 2)))
				*(*uint32)(unsafe.Add(v5, 4*2)) = uint32(v16)
				continue
			default:
				result = 0
			}
			break
		}
		return result
	} else {
		nox_thing_skip_AVNT_inner_452B30((*binfile.MemFile)(v2))
		return 1
	}
}
func nox_thing_skip_AVNT_452B00(f *binfile.MemFile) int32 {
	var sz int32 = int32(nox_memfile_read_u8(f))
	nox_memfile_skip(f, sz)
	return nox_thing_skip_AVNT_inner_452B30(f)
}
func nox_thing_skip_AVNT_inner_452B30(f *binfile.MemFile) int32 {
	var (
		v3     int8
		v5     uint8
		result int32
		v8     int8
	)
	for {
		v3 = nox_memfile_read_i8(f)
		v8 = v3
		switch v8 {
		case 0:
			result = bool2int32(int32(v3) == 0)
		case 1, 2, 3, 4, 5:
			nox_memfile_skip(f, 1)
			continue
		case 6, 9, 0xA:
			nox_memfile_skip(f, 2)
			continue
		case 7:
			for {
				v5 = nox_memfile_read_u8(f)
				if int32(v5) == 0 {
					break
				}
				nox_memfile_skip(f, int32(v5))
			}
			continue
		case 8:
			nox_memfile_skip(f, 8)
			continue
		default:
			result = 0
		}
		break
	}
	return result
}
func sub_452BD0(a1 unsafe.Pointer, a2 *byte) int32 {
	var (
		v6     int32
		v7     unsafe.Pointer
		v8     *int16
		v9     int16
		v10    *uint8
		v11    *int16
		v12    int16
		v13    *byte
		v14    int8
		v15    *byte
		v16    int8
		v17    *byte
		v18    int32
		v19    *byte
		v20    int8
		result int32
		v22    *byte
		v23    int8
		v24    int32
		v25    *byte
		v26    int16
		v27    *byte
		v28    int8
		v29    int32
		v30    uint8
		v31    *uint16
		v32    *byte
	)
	v2 := a1
	v3 := a2
	v4 := *(**byte)(unsafe.Add(a1, 8))
	v5 := int32(*v4)
	*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v4), 1)))
	nox_memfile_read(unsafe.Pointer(a2), 1, v5, (*binfile.MemFile)(a1))
	*(*byte)(unsafe.Add(unsafe.Pointer(a2), v5)) = 0
	v6 = nox_xxx_utilFindSound_40AF50(a2)
	if v6 != 0 && (func() unsafe.Pointer {
		v7 = nox_xxx_draw_452270(v6)
		return v7
	}()) != nil {
		v8 = *(**int16)(unsafe.Add(a1, 8))
		v9 = *v8
		*(*uint32)(unsafe.Add(a1, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(int16(0))*1)))
		*(*uint32)(unsafe.Add(v7, 4*1)) = 2
		*(*uint32)(unsafe.Add(v7, 4*2)) = uint32(v9)
		v10 = *(**uint8)(unsafe.Add(a1, 8))
		v30 = *v10
		*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v10), 1)))
		sub_4862E0(unsafe.Add(v7, 16), int32(v30)*163)
		v11 = *(**int16)(unsafe.Add(v2, 8))
		v12 = *v11
		*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v11), unsafe.Sizeof(int16(0))*1)))
		if int32(v12) > 0 {
			*(*uint32)(unsafe.Add(v7, 4*16)) = uint32(int32(v12) * 15)
		}
		v13 = *(**byte)(unsafe.Add(v2, 8))
		v14 = int8(*v13)
		*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v13), 1)))
		*(*uint32)(unsafe.Add(v7, 4*14)) = uint32(v14)
		v15 = *(**byte)(unsafe.Add(v2, 8))
		v16 = int8(*v15)
		*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v15), 1)))
		*(*uint32)(unsafe.Add(v7, 4*19)) = uint32(v16)
		v17 = *(**byte)(unsafe.Add(v2, 8))
		v18 = int32(*v17)
		*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v17), 1)))
		*(*uint32)(unsafe.Add(v7, 4*20)) = uint32(v18)
		v19 = *(**byte)(unsafe.Add(v2, 8))
		v20 = int8(*v19)
		*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v19), 1)))
		*(*uint32)(unsafe.Add(v7, 4*12)) = uint32(v20)
		if int32(v20) < 3 {
			v32 = nil
			v31 = (*uint16)(unsafe.Add(v7, 128))
			for {
				v22 = *(**byte)(unsafe.Add(v2, 8))
				v23 = int8(*v22)
				*(*uint32)(unsafe.Add(v2, 8)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v22), 1)))
				if int32(v23) == 0 {
					break
				}
				v24 = int32(v23)
				nox_memfile_read(unsafe.Pointer(v3), 1, int32(v23), (*binfile.MemFile)(v2))
				*(*byte)(unsafe.Add(unsafe.Pointer(v3), v24)) = 0
				v25 = libc.StrRChr(v3, 46)
				if v25 != nil {
					*v25 = 0
				}
				v26 = int16(uint16(sub_486A10(dword_5d4594_1045420, unsafe.Pointer(v3))))
				*v31 = uint16(v26)
				if int32(v26) != -1 {
					v32 = (*byte)(unsafe.Add(unsafe.Pointer(v32), 1))
					v31 = (*uint16)(unsafe.Add(unsafe.Pointer(v31), unsafe.Sizeof(uint16(0))*1))
				}
			}
			*(*uint32)(v7) = 1
			*(*uint32)(unsafe.Add(v7, 4*48)) = uint32(uintptr(unsafe.Pointer(v32)))
			result = 1
		} else {
			result = 0
		}
		return result
	} else {
		for *(*uint32)(unsafe.Add(a1, 8)) += 9; ; *(*uint32)(unsafe.Add(a1, 8)) = uint32(v29 + int32(v28)) {
			v27 = *(**byte)(unsafe.Add(a1, 8))
			v28 = int8(*v27)
			v29 = int32(uintptr(unsafe.Add(unsafe.Pointer(v27), 1)))
			*(*uint32)(unsafe.Add(a1, 8)) = uint32(v29)
			if int32(v28) == 0 {
				break
			}
		}
		return 1
	}
}
func nox_xxx_clientPlaySoundSpecial_452D80(a1 int32, a2 int32) {
	r1 := nox_xxx_draw_452270(a1)
	if r1 == nil {
		return
	}
	r2 := nox_xxx_draw_452300(r1)
	v3 := r2
	if r2 == nil {
		return
	}
	sub_452EE0(r2, a2)
	sub_452510(v3)
}
func sub_452DC0(a1 int32, a2 int32, a3 int32) {
	r1 := nox_xxx_draw_452270(a1)
	if r1 == nil {
		return
	}
	v4 := nox_xxx_draw_452300(r1)
	if v4 == nil {
		return
	}
	sub_452EE0(v4, a2)
	sub_452F80(v4, a3)
	sub_452510(v4)
}
func sub_452E10(a1 int32, a2 int32, a3 int32) {
	r1 := nox_xxx_draw_452270(a1)
	if r1 == nil {
		return
	}
	v4 := nox_xxx_draw_452300(r1)
	if v4 == nil {
		return
	}
	sub_452EE0(v4, a2)
	sub_452F80(v4, a3)
	*(*uint32)(unsafe.Add(v4, 4*75)) = 2
	sub_452510(v4)
}
func sub_452E90(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	*(*unsafe.Pointer)(a1) = a2
	if a2 != nil {
		*(*uint32)(unsafe.Add(a1, 4*1)) = *(*uint32)(unsafe.Add(a2, 280))
		result := int32(*(*uint32)(unsafe.Add(a2, 36)))
		*(*uint32)(unsafe.Add(a1, 4*2)) = uint32(result)
	}
}
func sub_452EB0(a1 unsafe.Pointer) unsafe.Pointer {
	p := *(*unsafe.Pointer)(a1)
	if p != nil && (uint32(*(*int32)(unsafe.Add(a1, 4*2))) != *(*uint32)(unsafe.Add(p, 36)) || uint32(*(*int32)(unsafe.Add(a1, 4*1))) != *(*uint32)(unsafe.Add(p, 280))) {
		*(*unsafe.Pointer)(a1) = nil
		return nil
	}
	return p
}
func sub_452EE0(a1 unsafe.Pointer, a2 int32) {
	v2 := sub_452F10(a1, a2)
	sub_486320(unsafe.Add(a1, 184), v2)
	sub_4863B0(unsafe.Add(a1, 184))
}
func sub_452F10(a1 unsafe.Pointer, a2 int32) uint32 {
	var v2 int32
	v2 = a2
	if a2 <= 100 {
		if a2 < 0 {
			v2 = 0
		}
	} else {
		v2 = 100
	}
	return (uint32(v2*163) * (*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 36)), 20)) >> 16)) >> 14
}
func sub_452F50(a1 unsafe.Pointer, a2 int32) int32 {
	v2 := sub_452F10(a1, a2)
	return sub_486350(unsafe.Add(a1, 184), int32(v2))
}
func sub_452F80(a1 unsafe.Pointer, a2 int32) {
	v2 := sub_452FA0(a2)
	sub_486320(unsafe.Add(a1, 248), uint32(v2))
}
func sub_452FA0(a1 int32) int32 {
	var v1 int32
	v1 = a1
	if a1 <= 50 {
		if a1 < -50 {
			v1 = -50
		}
	} else {
		v1 = 50
	}
	return (v1*8192)/50 + 8192
}
func sub_452FE0(a1 unsafe.Pointer, a2 int32) {
	v2 := sub_452FA0(a2)
	sub_486350(unsafe.Add(a1, 248), v2)
}
func sub_453050() {
	dword_587000_126996 = 0
}
func nox_xxx____setargv_9_453060() {
	dword_587000_126996 = 1
}
func sub_453070() int32 {
	return int32(dword_587000_126996)
}
func sub_453080(a1 int8) int32 {
	var result int32
	if dword_5d4594_1045460 != 0 {
		result = sub_453690(1 << int32(a1))
	} else {
		result = sub_453660(1 << int32(a1))
	}
	return result
}
func sub_4532E0() {
	v0 := nox_xxx_guiFontHeightMB_43F320(dword_5d4594_1045464.DrawData().FontPtr) + 1
	sub_46AB20(dword_5d4594_1045464, int32(dword_5d4594_1045464.SizeVal.X), v0*15+2)
	v1 := int32(1520)
	v2 := int32(dword_5d4594_1045464.Off.Y + int(uint32(v0)) + 2)
	for {
		result := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045468, v1)
		result.Off.Y = int(uint32(v2))
		v2 += v0
		v1++
		if v1 >= 1534 {
			break
		}
	}
}
func sub_453350(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win.C()
		a2    = draw.C()
		xLeft int32
		yTop  int32
	)
	nox_client_wndGetPosition_46AA60(win, &xLeft, &yTop)
	if int32(int8(*(*uint8)(unsafe.Add(a1, 4)))) >= 0 {
		if *(*uint32)(unsafe.Add(a2, 20)) != 0x80000000 {
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, int32(*(*uint32)(unsafe.Add(a1, 8))), int32(*(*uint32)(unsafe.Add(a1, 12))))
		}
		return 1
	} else {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*(*unsafe.Pointer)(unsafe.Add(a2, 24))), xLeft, yTop)
		return 1
	}
}
func sub_4533D0(a1 *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v3  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 *wchar2_t
	)
	if a2 == 0x4000 {
		if (*gui.Window)(unsafe.Pointer(a3)) == nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045468, 1513) ||
			(*gui.Window)(unsafe.Pointer(a3)) == nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045468, 1514) {
			nox_window_call_field_94_fnc(dword_5d4594_1045464, 0x4000, a3, 0)
			sub_453750()
		}
		return 0
	}
	if a2 != 16391 {
		return 0
	}
	v3 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	switch v3 {
	case 1513, 1514:
		nox_window_call_field_94_fnc(dword_5d4594_1045464, 0x4000, a3, 0)
		sub_453750()
		return 0
	case 1515:
		if dword_5d4594_1045460 != 0 {
			*memmap.PtrUint32(0x5D4594, 1045456) = math.MaxUint32
		} else {
			*memmap.PtrUint32(0x5D4594, 1045452) = math.MaxUint32
		}
		sub_453750()
		sub_459D50(1)
	case 1516:
		if dword_5d4594_1045460 != 0 {
			*memmap.PtrUint32(0x5D4594, 1045456) = 0
		} else {
			*memmap.PtrUint32(0x5D4594, 1045452) = 0
		}
		sub_453750()
		sub_459D50(1)
	case 1520, 1521, 1522, 1523, 1524, 1525, 1526, 1527, 1528, 1529, 1530, 1531, 1532, 1533:
		v5 = sub_4A4800(dword_5d4594_1045464.WidgetData)
		v11 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045464, 16406, uintptr(v5+v3-1520), 0)))
		if dword_5d4594_1045460 != 0 {
			v6 = sub_415DA0(v11)
		} else {
			v6 = sub_415960(v11)
		}
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a3), 36)))&4 != 0 {
			if dword_5d4594_1045460 != 0 {
				sub_453640((*uint32)(memmap.PtrOff(0x5D4594, 1045456)), v6, 0)
			} else {
				v7 = 0
				if v6 > 0 {
					for {
						v8 = v6 >> 8
						if v6>>8 > 0 {
							v6 >>= 8
						}
						v7++
						if v8 <= 0 {
							break
						}
					}
				}
				sub_453620((*uint8)(memmap.PtrOff(0x5D4594, uintptr(v7)+1045451)), int8(v6), 0)
			}
		} else if dword_5d4594_1045460 != 0 {
			sub_453640((*uint32)(memmap.PtrOff(0x5D4594, 1045456)), v6, 1)
		} else {
			v9 = 0
			if v6 > 0 {
				for {
					v10 = v6 >> 8
					if v6>>8 > 0 {
						v6 >>= 8
					}
					v9++
					if v10 <= 0 {
						break
					}
				}
			}
			sub_453620((*uint8)(memmap.PtrOff(0x5D4594, uintptr(v9)+1045451)), int8(v6), 1)
		}
		sub_459D50(1)
	default:
	}
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	return 0
}
func sub_4535E0(a1 *int32) *int32 {
	var result *int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1045452) = uint32(*a1)
	return result
}
func sub_4535F0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1045456) = uint32(a1)
	return result
}
func sub_453600() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 1045452))
}
func sub_453610() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1045456))
}
func sub_453620(a1 *uint8, a2 int8, a3 int32) *uint8 {
	var result *uint8
	result = a1
	if a3 != 0 {
		*a1 |= uint8(a2)
	} else {
		*a1 &= uint8(int8(int32(^a2)))
	}
	return result
}
func sub_453640(a1 *uint32, a2 int32, a3 int32) *uint32 {
	var result *uint32
	result = a1
	if a3 != 0 {
		*a1 |= uint32(a2)
	} else {
		*a1 &= uint32(^a2)
	}
	return result
}
func sub_453660(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		v3 int32
	)
	v1 = a1
	v2 = 0
	if a1 <= 0 {
		return bool2int32((int32(uint8(int8(v1))) & int32(*memmap.PtrUint8(0x5D4594, uintptr(v2)+1045451))) != 0)
	}
	for {
		v3 = v1 >> 8
		if v1>>8 > 0 {
			v1 >>= 8
		}
		v2++
		if v3 <= 0 {
			break
		}
	}
	return bool2int32((int32(uint8(int8(v1))) & int32(*memmap.PtrUint8(0x5D4594, uintptr(v2)+1045451))) != 0)
}
func sub_453690(a1 int32) int32 {
	return bool2int32((uint32(a1) & *memmap.PtrUint32(0x5D4594, 1045456)) != 0)
}
func sub_4536B0(a1 *uint32) {
	var (
		v1 int32
		v2 int32
		v3 *uint32
		v4 int32
	)
	v1 = 1
	*a1 = math.MaxUint32
	v2 = 1
	v3 = a1
	v4 = 27
	for {
		result := sub_415840(uint32(v2))
		if result != 0 {
			if nox_xxx_getUnitDefDd10_4E3BA0(result) == 0 {
				*(*uint8)(unsafe.Pointer(v3)) &= ^uint8(int8(v1))
			}
		}
		if v1 == 128 {
			v1 = 1
			v3 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), 1))
		} else {
			v1 *= 2
		}
		v2 *= 2
		v4--
		if v4 == 0 {
			break
		}
	}
}
func sub_453710() int32 {
	var (
		v0 int32
		v1 int32
		v2 int32
		v3 int32
	)
	v0 = -1
	v1 = 1
	v2 = 26
	for {
		v3 = sub_415CD0(uint32(v1))
		if v3 != 0 && nox_xxx_getUnitDefDd10_4E3BA0(v3) == 0 {
			v0 &= ^v1
		}
		v1 *= 2
		v2--
		if v2 == 0 {
			break
		}
	}
	return v0
}
func sub_453750() int8 {
	var (
		v0 int32
		i  int32
		j  *gui.Window
		v3 bool
		v4 int32
	)
	v0 = sub_4A4800(dword_5d4594_1045464.WidgetData)
	for i = 1520; i <= 1533; i++ {
		for j = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045468, i); (1<<v0)&0x33 != 0; v0++ {
		}
		if v0 >= *memmap.PtrInt32(0x5D4594, uintptr(dword_5d4594_1045460)*4+1045472) {
			*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(nox_window_set_hidden(j, 1)))
		} else {
			nox_window_set_hidden(j, 0)
			v3 = sub_453080(int8(v0)) == 0
			v4 = int32(j.DrawData().Field0)
			if v3 {
				*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(v4 & 0xFB))
			} else {
				*(*uint8)(unsafe.Pointer(&v4)) = uint8(int8(v4 | 4))
			}
			j.DrawData().Field0 = uint32(v4)
		}
		v0++
	}
	return int8(v4)
}
func sub_453B00() {
	var (
		v0 int32
		v1 int32
		v2 int32
	)
	v0 = nox_xxx_guiFontHeightMB_43F320(dword_5d4594_1045480.DrawData().FontPtr) + 1
	sub_46AB20(dword_5d4594_1045480, int32(dword_5d4594_1045480.SizeVal.X), v0*15+2)
	sub_46AB20(dword_5d4594_1045508, int32(dword_5d4594_1045508.SizeVal.X), v0*15+2)
	v1 = 1120
	v2 = int32(dword_5d4594_1045480.Off.Y + int(uint32(v0)) + 2)
	for {
		result := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045484, v1)
		result.Off.Y = int(uint32(v2))
		v2 += v0
		v1++
		if v1 >= 1134 {
			break
		}
	}
}
func sub_453B80(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win.C()
		a2    = draw.C()
		xLeft int32
		yTop  int32
	)
	nox_client_wndGetPosition_46AA60(win, &xLeft, &yTop)
	if int32(int8(*(*uint8)(unsafe.Add(a1, 4)))) >= 0 {
		if *(*uint32)(unsafe.Add(a2, 20)) != 0x80000000 {
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, int32(*(*uint32)(unsafe.Add(a1, 8))), int32(*(*uint32)(unsafe.Add(a1, 12))))
		}
		return 1
	} else {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*(*unsafe.Pointer)(unsafe.Add(a2, 24))), xLeft, yTop)
		return 1
	}
}
func sub_453F70(a1 unsafe.Pointer) {
	alloc.Memcpy(memmap.PtrOff(0x5D4594, 1045488), a1, 0x14)
}
func sub_453F90() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 1045488))
}
func sub_453FA0(a1 int32, a2 int32, a3 int32) int32 {
	var (
		v3     bool
		v4     int8
		result int32
		v6     uint8
	)
	v4 = int8(a2 & 0x1F)
	v3 = (uint32(a2) & 0x8000001F & 0x80000000) != 0
	v6 = uint8(int8(a2 / 32))
	if v3 {
		v4 = int8(((int32(v4) - 1) | 0xE0) + 1)
	}
	result = 1 << int32(v4)
	if a3 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + int32(v6)*4))) |= uint32(result)
	} else {
		result = ^result
		*(*uint32)(unsafe.Pointer(uintptr(a1 + int32(v6)*4))) &= uint32(result)
	}
	return result
}
func sub_454000(a1 unsafe.Pointer, a2 int32) int32 {
	return bool2int32((*(*uint32)(unsafe.Add(a1, ((a2/32)&math.MaxUint8)*4)) & uint32(1<<(a2%32))) != 0)
}
func sub_454040(a1 *uint32) {
	var (
		v1 int32
		v2 int32
		v4 uint8
	)
	v1 = 1
	*a1 = math.MaxUint32
	v4 = 0
	v2 = 1
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) = math.MaxUint32
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) = math.MaxUint32
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) = math.MaxUint32
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) = math.MaxUint32
	for {
		if uint32(v1) == 0x80000000 {
			v1 = 1
			v4++
		} else {
			v1 *= 2
		}
		if nox_xxx_spellIsValid_424B50(v2) {
			if nox_xxx_spellFlags_424A70(v2)&0x7000000 != 0 {
				if !nox_xxx_spellIsEnabled_424B70(v2) {
					r4 := unsafe.Add(unsafe.Pointer(a1), 4*uintptr(v4))
					*(*uint32)(r4) = uint32(^v1) & *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*uintptr(v4)))
				}
			}
		}
		v2++
		if v2 >= 137 {
			break
		}
	}
}
func sub_4540E0(a1 unsafe.Pointer) int32 {
	var (
		v1     int32
		result int32
	)
	v1 = 1
	for {
		if sub_454000(a1, v1) != 0 {
			result = bool2int32(nox_xxx_spellEnable_424B90(v1))
		} else {
			result = bool2int32(nox_xxx_spellDisable_424BB0(v1))
		}
		v1++
		if v1 >= 137 {
			break
		}
	}
	return result
}
func sub_454120() int8 {
	var (
		v0 int32
		v1 int32
		v3 int32
		v4 int32
		v5 bool
		v6 int32
	)
	v8 := dword_5d4594_1045480.WidgetData
	v0 = 1120
	v1 = sub_4A4800(v8) * 524
	for {
		v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045484, v0)
		v3 = 0
		v4 = int32(*(*uint32)(unsafe.Add(v8, 24)))
		if v4+v1 != -4 && int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v4+v1)), 4))) != 0 {
			v3 = nox_xxx_spellByTitle_424960((*wchar2_t)(unsafe.Add(unsafe.Pointer(uintptr(v4+v1)), 4)))
			nox_window_set_hidden(v2, 0)
		} else {
			nox_window_set_hidden(v2, 1)
		}
		v1 += 524
		if v3 != 0 {
			v5 = sub_454000(memmap.PtrOff(0x5D4594, 1045488), v3) == 0
			v6 = int32(v2.DrawData().Field0)
			if !v5 {
				*(*uint8)(unsafe.Pointer(&v6)) = uint8(int8(v6 | 4))
				goto LABEL_11
			}
		} else {
			v6 = int32(v2.DrawData().Field0)
		}
		*(*uint8)(unsafe.Pointer(&v6)) = uint8(int8(v6 & 0xFB))
	LABEL_11:
		v0++
		v2.DrawData().Field0 = uint32(v6)
		if v0 > 1133 {
			break
		}
	}
	return int8(v6)
}
func nox_xxx_guiServerAccessLoad_4541D0(a1 *gui.Window) *gui.Window {
	if dword_5d4594_1045516 != nil {
		return nil
	}
	v2 := nox_strman_get_lang_code()
	if nox_xxx_guiFontHeightMB_43F320(nil) > 10 {
		v2 = 2
	}
	dword_5d4594_1045516 = nox_new_window_from_file(*(**byte)(memmap.PtrOff(0x587000, uintptr(v2*4)+127824)), nox_xxx_windowAccessProc_454BA0)
	nox_draw_setTabWidth_43FE20(100)
	sub_46B120(dword_5d4594_1045516, a1)
	dword_5d4594_1045520 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10102)
	*memmap.PtrPtrT[*gui.Window](0x5D4594, 1045524) = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10103)
	dword_5d4594_1045532 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10109)
	dword_5d4594_1045528 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10105)
	dword_5d4594_1045536 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10200)
	dword_5d4594_1045540 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10111)
	dword_5d4594_1045544 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10112)
	dword_5d4594_1045548 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10113)
	dword_5d4594_1045556 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10104)
	*memmap.PtrPtrT[*gui.Window](0x5D4594, 1045560) = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10125)
	*memmap.PtrPtrT[*gui.Window](0x5D4594, 1045564) = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10127)
	*memmap.PtrPtrT[*gui.Window](0x5D4594, 1045568) = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10129)
	*memmap.PtrPtrT[*gui.Window](0x5D4594, 1045572) = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10131)
	dword_5d4594_1045576 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10126)
	dword_5d4594_1045580 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10128)
	dword_5d4594_1045584 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10130)
	dword_5d4594_1045588 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10132)
	dword_5d4594_1045552 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10123)
	*memmap.PtrPtrT[*gui.Window](0x5D4594, 1045592) = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10133)
	v3 := dword_5d4594_1045532.WidgetData
	v4 := nox_xxx_gLoadImg_42F970(internCStr("UISlider"))
	v5 := nox_xxx_gLoadImg_42F970(internCStr("UISliderLit"))
	v6 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10190)
	v15 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10188)
	v12 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10189)
	v6.Field100Ptr.SizeVal.X = 16
	v6.Field100Ptr.SizeVal.Y = 10
	sub_4B5700(v6, nil, nil, v4, v5, v5)
	nox_xxx_wnd_46B280(v6, dword_5d4594_1045532)
	nox_xxx_wnd_46B280(v15, dword_5d4594_1045532)
	nox_xxx_wnd_46B280(v12, dword_5d4594_1045532)
	*(*uint32)(unsafe.Add(v3, 4*9)) = uint32(uintptr(unsafe.Pointer(v6)))
	*(*uint32)(unsafe.Add(v3, 4*7)) = uint32(uintptr(unsafe.Pointer(v15)))
	*(*uint32)(unsafe.Add(v3, 4*8)) = uint32(uintptr(unsafe.Pointer(v12)))
	v7 := dword_5d4594_1045528.WidgetData
	v8 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10187)
	v16 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10185)
	v13 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10186)
	v8.Field100Ptr.SizeVal.X = 16
	v8.Field100Ptr.SizeVal.Y = 10
	sub_4B5700(v8, nil, nil, v4, v5, v5)
	nox_xxx_wnd_46B280(v8, dword_5d4594_1045528)
	nox_xxx_wnd_46B280(v16, dword_5d4594_1045528)
	nox_xxx_wnd_46B280(v13, dword_5d4594_1045528)
	*(*uint32)(unsafe.Add(v7, 4*9)) = uint32(uintptr(unsafe.Pointer(v8)))
	*(*uint32)(unsafe.Add(v7, 4*7)) = uint32(uintptr(unsafe.Pointer(v16)))
	*(*uint32)(unsafe.Add(v7, 4*8)) = uint32(uintptr(unsafe.Pointer(v13)))
	v9 := dword_5d4594_1045536.WidgetData
	v10 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10203)
	v17 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10201)
	v11 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10202)
	v10.Field100Ptr.SizeVal.X = 16
	v14 := v11
	v10.Field100Ptr.SizeVal.Y = 10
	sub_4B5700(v10, nil, nil, v4, v5, v5)
	nox_xxx_wnd_46B280(v10, dword_5d4594_1045536)
	nox_xxx_wnd_46B280(v17, dword_5d4594_1045536)
	nox_xxx_wnd_46B280(v14, dword_5d4594_1045536)
	*(**gui.Window)(unsafe.Add(v9, 4*9)) = v10
	*(**gui.Window)(unsafe.Add(v9, 4*7)) = v17
	*(**gui.Window)(unsafe.Add(v9, 4*8)) = v14
	sub_454740()
	sub_454640()
	if noxflags.HasGame(1) {
		nox_xxx_wndSetDrawFn_46B340(dword_5d4594_1045516, sub_454A90)
	}
	nox_xxx_wndRetNULL_46A8A0()
	return dword_5d4594_1045516
}
func sub_454A90(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win.C()
		a2    = draw.C()
		v2    *uint16
		v3    int32
		v4    int8
		xLeft int32
		yTop  int32
	)
	nox_client_wndGetPosition_46AA60(win, &xLeft, &yTop)
	if int32(int8(*(*uint8)(unsafe.Add(a1, 4)))) >= 0 {
		if *(*uint32)(unsafe.Add(a2, 20)) != 0x80000000 {
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, int32(*(*uint32)(unsafe.Add(a1, 8))), int32(*(*uint32)(unsafe.Add(a1, 12))))
		}
	} else {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*(*unsafe.Pointer)(unsafe.Add(a2, 24))), xLeft, yTop)
	}
	if int32(dword_5d4594_1045540.Flags)&8 != 0 {
		v2 = (*uint16)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045540, 16413, 0, 0)))
		if v2 != nil && int32(*v2) != 0 {
			if (int32(dword_5d4594_1045544.Flags) & 8) == 0 {
				nox_xxx_wnd_46ABB0(dword_5d4594_1045544, 1)
			}
		} else if int32(dword_5d4594_1045544.Flags)&8 != 0 {
			nox_xxx_wnd_46ABB0(dword_5d4594_1045544, 0)
		}
	}
	v3 = int32(nox_window_call_field_94_fnc(dword_5d4594_1045596, 16404, 0, 0))
	v4 = int8(dword_5d4594_1045548.Flags)
	if v3 < 0 {
		if int32(v4)&8 != 0 {
			nox_xxx_wnd_46ABB0(dword_5d4594_1045548, 0)
		}
	} else if (int32(v4) & 8) == 0 {
		nox_xxx_wnd_46ABB0(dword_5d4594_1045548, 1)
		return 1
	}
	return 1
}
func nox_xxx_windowAccessProc_454BA0(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v4     int32
		result int32
		v6     *byte
	)
	var v7 int32
	var v8 *byte
	var v9 *wchar2_t
	var v10 *byte
	var v11 *wchar2_t
	var v12 *byte
	var v13 *wchar2_t
	var v14 *byte
	var v15 *wchar2_t
	var v16 *byte
	var v17 int8
	var v21 *byte
	var v22 *wchar2_t
	var v23 int32
	var v24 int32
	var v25 *byte
	var v26 *int32
	var v27 *int32
	var v28 int32
	var v29 *wchar2_t
	var v30 *wchar2_t
	var v33 *int32
	var v34 *int32
	var v35 int32
	var v36 *wchar2_t
	var v39 *byte
	var v40 *wchar2_t
	var v41 *wchar2_t
	var v42 int32
	var v43 int32
	var v45 *wchar2_t
	var v46 *wchar2_t
	var v47 int32
	var v49 *byte
	var v50 *byte
	var v51 *byte
	WideCharStr, free := alloc.Make([]wchar2_t{}, 8)
	defer free()
	switch a2 {
	case 16387:
		v43 = int32(a4)
		v44 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, int32(a4))
		v51 = sub_416630()
		v49 = (*byte)(sub_416640())
		if v44 == nil || int32(uint16(a3)) == 1 {
			return 0
		}
		v45 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(v44, 16413, 0, 0)))
		v46 = v45
		if v45 == nil || *v45 == 0 || (func() bool {
			v47 = int32(libc.WStrtol(v45, nil, 10))
			return v47 < 0
		}()) {
			v47 = 0
		}
		switch v43 {
		case 10104:
			nox_wcscpy((*wchar2_t)(unsafe.Add(unsafe.Pointer(v49), unsafe.Sizeof(wchar2_t(0))*39)), v46)
			return 0
		case 10126:
			if v47 > 14 {
				*(*uint8)(unsafe.Pointer(&v47)) = 14
				nox_itow(14, &WideCharStr[0], 10)
				nox_window_call_field_94_fnc(v44, 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), math.MaxUint32)
			}
			*(*byte)(unsafe.Add(unsafe.Pointer(v51), 1)) = byte(int8(v47 | int32(*(*byte)(unsafe.Add(unsafe.Pointer(v51), 1))&0xF0)))
			result = 0
		case 10128:
			if v47 > 14 {
				*(*uint8)(unsafe.Pointer(&v47)) = 14
				nox_itow(14, &WideCharStr[0], 10)
				nox_window_call_field_94_fnc(v44, 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), math.MaxUint32)
			}
			*(*byte)(unsafe.Add(unsafe.Pointer(v51), 1)) = byte(int8((v47 * 16) | int32(*(*byte)(unsafe.Add(unsafe.Pointer(v51), 1))&0xF)))
			result = 0
		case 10130:
			*(*uint16)(unsafe.Add(unsafe.Pointer(v51), 5)) = uint16(int16(v47))
			result = 0
		case 10132:
			*(*uint16)(unsafe.Add(unsafe.Pointer(v51), 7)) = uint16(int16(v47))
			result = 0
		case 10133:
			if v47 <= 32 {
				if v47 < 1 {
					v47 = 1
					nox_itow(1, &WideCharStr[0], 10)
					nox_window_call_field_94_fnc(v44, 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), math.MaxUint32)
				}
			} else {
				v47 = 32
				nox_itow(32, &WideCharStr[0], 10)
				nox_window_call_field_94_fnc(v44, 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), math.MaxUint32)
			}
			nox_xxx_servSetPlrLimit_409F80(v47)
			result = 0
			*(*byte)(unsafe.Add(unsafe.Pointer(v51), 4)) = byte(int8(v47))
		case 10136:
			nox_xxx_sysopSetPass_40A610(v46)
			result = 0
		default:
			return 0
		}
	case 16391:
		v7 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
		switch v7 {
		case 10102:
			v16 = sub_416630()
			v17 = int8(*v16 ^ 0x10)
			*v16 = byte(v17)
			if int32(v17)&0x10 != 0 {
				v20 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10206)
				nox_xxx_wnd_46ABB0(v20, 1)
			} else {
				v18 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10206)
				nox_xxx_wnd_46ABB0(v18, 0)
				v18.DrawData().Field0 &= 0xFFFFFFFB
				v19 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10207)
				v19.DrawData().Field0 |= 4
				nox_window_set_hidden(dword_5d4594_1045532, 1)
				sub_46ACE0(dword_5d4594_1045516, 10188, 10190, 1)
				nox_window_set_hidden(dword_5d4594_1045528, 0)
				sub_46ACE0(dword_5d4594_1045516, 10185, 10187, 0)
			}
			return 0
		case 10103:
			v21 = sub_416630()
			nox_xxx_wnd_46ABB0(dword_5d4594_1045556, int32((^*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1045524), 36))>>2)&1))
			*v21 ^= 0x20
			return 0
		case 10112:
			v22 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045540, 16413, 0, 0)))
			if wndIsShown_nox_xxx_wndIsShown_46ACC0(dword_5d4594_1045528) != 0 {
				sub_4168A0(v22)
			} else {
				sub_416770(0, v22, nil)
			}
			nox_window_call_field_94_fnc(dword_5d4594_1045540, 16414, uintptr(memmap.PtrOff(0x5D4594, 1045600)), 0)
			return 0
		case 10113:
			if int32(dword_5d4594_1045520.DrawData().Field0)&4 != 0 {
				v23 = int32(nox_window_call_field_94_fnc(dword_5d4594_1045532, 16404, 0, 0))
				nox_window_call_field_94_fnc(dword_5d4594_1045532, 16398, uintptr(v23), 0)
				sub_416860(v23)
			} else {
				v24 = int32(nox_window_call_field_94_fnc(dword_5d4594_1045528, 16404, 0, 0))
				nox_window_call_field_94_fnc(dword_5d4594_1045528, 16398, uintptr(v24), 0)
				sub_416820(v24)
			}
			return 0
		case 10124:
			v25 = sub_416630()
			*(*byte)(unsafe.Add(unsafe.Pointer(v25), 2)) ^= 0x80
			return 0
		case 10125:
			v8 = sub_416630()
			if int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1045560), 36)))&4 != 0 {
				nox_xxx_wnd_46ABB0(dword_5d4594_1045576, 0)
				*(*byte)(unsafe.Add(unsafe.Pointer(v8), 1)) |= 0xF
				return 0
			}
			nox_xxx_wnd_46ABB0(dword_5d4594_1045576, 1)
			v9 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045576, 16413, 0, 0)))
			if *v9 == 0 {
				return 0
			}
			*(*byte)(unsafe.Add(unsafe.Pointer(v8), 1)) = byte(int8(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v8), 1))&0xF0) | int32(libc.WStrtol(v9, nil, 10))))
			return 0
		case 10127:
			v10 = sub_416630()
			if int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1045564), 36)))&4 != 0 {
				nox_xxx_wnd_46ABB0(dword_5d4594_1045580, 0)
				*(*byte)(unsafe.Add(unsafe.Pointer(v10), 1)) |= 0xF0
				return 0
			}
			nox_xxx_wnd_46ABB0(dword_5d4594_1045580, 1)
			v11 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045580, 16413, 0, 0)))
			if *v11 == 0 {
				return 0
			}
			*(*byte)(unsafe.Add(unsafe.Pointer(v10), 1)) = byte(int8(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v10), 1))&0xF) | int32(libc.WStrtol(v11, nil, 10))))
			return 0
		case 10129:
			v12 = sub_416630()
			if int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1045568), 36)))&4 != 0 {
				nox_xxx_wnd_46ABB0(dword_5d4594_1045584, 0)
				*(*uint16)(unsafe.Add(unsafe.Pointer(v12), 5)) = math.MaxUint16
				return 0
			}
			nox_xxx_wnd_46ABB0(dword_5d4594_1045584, 1)
			v13 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045584, 16413, 0, 0)))
			if *v13 == 0 {
				return 0
			}
			*(*uint16)(unsafe.Add(unsafe.Pointer(v12), 5)) = uint16(int16(libc.WStrtol(v13, nil, 10)))
			return 0
		case 10131:
			v14 = sub_416630()
			if int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x5D4594, 1045572), 36)))&4 != 0 {
				nox_xxx_wnd_46ABB0(dword_5d4594_1045588, 0)
				*(*uint16)(unsafe.Add(unsafe.Pointer(v14), 7)) = math.MaxUint16
				return 0
			}
			nox_xxx_wnd_46ABB0(dword_5d4594_1045588, 1)
			v15 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045588, 16413, 0, 0)))
			if *v15 == 0 {
				return 0
			}
			*(*uint16)(unsafe.Add(unsafe.Pointer(v14), 7)) = uint16(int16(libc.WStrtol(v15, nil, 10)))
			result = 0
		case 10191:
			v33 = (*int32)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045536, 16404, 0, 0)))
			v34 = v33
			v35 = *v33
			if v35 < 0 {
				return 0
			}
			for {
				v36 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045536, 16406, uintptr(v35), 0)))
				v37 := nox_xxx_playerByName_4170D0(v36)
				v38 := v37
				if v37 != nil && v37.PlayerInd != 31 {
					if noxflags.HasGame(4096) {
						sub_4DCFB0(v38.PlayerUnit)
					} else {
						nox_xxx_playerCallDisconnect_4DEAB0(int32(v38.PlayerInd), 4)
					}
				}
				v35 = *(*int32)(unsafe.Add(unsafe.Pointer(v34), 4*1))
				v34 = (*int32)(unsafe.Add(unsafe.Pointer(v34), 4*1))
				if v35 < 0 {
					break
				}
			}
			return 0
		case 10192:
			v26 = (*int32)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045536, 16404, 0, 0)))
			v27 = v26
			v28 = *v26
			if v28 < 0 {
				return 0
			}
			for {
				v29 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045536, 16406, uintptr(v28), 0)))
				v30 = v29
				v31 := nox_xxx_playerByName_4170D0(v29)
				v32 := v31
				if v31 != nil && v31.PlayerInd != 31 {
					if noxflags.HasGame(4096) {
						sub_4DCFB0(v32.PlayerUnit)
					} else {
						nox_xxx_playerDisconnByPlrID_4DEB00(int32(v32.PlayerInd))
					}
					sub_416770(0, v30, (*byte)(unsafe.Add(unsafe.Pointer(v32), 2112)))
				}
				v28 = *(*int32)(unsafe.Add(unsafe.Pointer(v27), 4*1))
				v27 = (*int32)(unsafe.Add(unsafe.Pointer(v27), 4*1))
				if v28 < 0 {
					break
				}
			}
			return 0
		case 10206:
			nox_window_set_hidden(dword_5d4594_1045532, 0)
			sub_46ACE0(dword_5d4594_1045516, 10188, 10190, 0)
			nox_window_set_hidden(dword_5d4594_1045528, 1)
			sub_46ACE0(dword_5d4594_1045516, 10185, 10187, 1)
			dword_5d4594_1045596 = dword_5d4594_1045532
			return 0
		case 10207:
			nox_window_set_hidden(dword_5d4594_1045532, 1)
			sub_46ACE0(dword_5d4594_1045516, 10188, 10190, 1)
			nox_window_set_hidden(dword_5d4594_1045528, 0)
			sub_46ACE0(dword_5d4594_1045516, 10185, 10187, 0)
			dword_5d4594_1045596 = dword_5d4594_1045528
			return 0
		default:
			return 0
		}
	case 16400:
		v4 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) - 10123
		if v4 != 0 {
			if v4 != 77 {
				return 0
			}
			if sub_455770() != 0 {
				sub_46AD20(dword_5d4594_1045516, 10191, 10192, 1)
			} else {
				sub_46AD20(dword_5d4594_1045516, 10191, 10192, 0)
			}
			result = 0
		} else {
			v6 = (*byte)(sub_416640())
			*(*byte)(unsafe.Add(unsafe.Pointer(v6), 100)) ^= byte(int8(1 << a4))
			result = 0
		}
	case 16415:
		v39 = sub_416630()
		v50 = (*byte)(sub_416640())
		v40 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16413, 0, 0)))
		v41 = v40
		if v40 == nil || *v40 == 0 || (func() bool {
			v42 = int32(libc.WStrtol(v40, nil, 10))
			return v42 < 0
		}()) {
			v42 = 0
		}
		switch nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) {
		case 10104:
			nox_wcscpy((*wchar2_t)(unsafe.Add(unsafe.Pointer(v50), unsafe.Sizeof(wchar2_t(0))*39)), v41)
			return 0
		case 10126:
			if v42 > 14 {
				*(*uint8)(unsafe.Pointer(&v42)) = 14
				nox_itow(14, &WideCharStr[0], 10)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), math.MaxUint32)
			}
			result = 0
			*(*byte)(unsafe.Add(unsafe.Pointer(v39), 1)) = byte(int8(v42 | int32(*(*byte)(unsafe.Add(unsafe.Pointer(v39), 1))&0xF0)))
		case 10128:
			if v42 > 14 {
				*(*uint8)(unsafe.Pointer(&v42)) = 14
				nox_itow(14, &WideCharStr[0], 10)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), math.MaxUint32)
			}
			result = 0
			*(*byte)(unsafe.Add(unsafe.Pointer(v39), 1)) = byte(int8((v42 * 16) | int32(*(*byte)(unsafe.Add(unsafe.Pointer(v39), 1))&0xF)))
		case 10130:
			*(*uint16)(unsafe.Add(unsafe.Pointer(v39), 5)) = uint16(int16(v42))
			result = 0
		case 10132:
			*(*uint16)(unsafe.Add(unsafe.Pointer(v39), 7)) = uint16(int16(v42))
			result = 0
		case 10133:
			if v42 <= 32 {
				if v42 < 1 {
					v42 = 1
					nox_itow(1, &WideCharStr[0], 10)
					nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), math.MaxUint32)
				}
			} else {
				v42 = 32
				nox_itow(32, &WideCharStr[0], 10)
				nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), math.MaxUint32)
			}
			nox_xxx_servSetPlrLimit_409F80(v42)
			*(*byte)(unsafe.Add(unsafe.Pointer(v39), 4)) = byte(int8(v42))
			result = 0
		case 10136:
			nox_xxx_sysopSetPass_40A610(v41)
			result = 0
		default:
			return 0
		}
	default:
		return 0
	}
	return uintptr(result)
}
func sub_455770() int32 {
	var (
		v0 *int32
		v1 *int32
		v2 int32
		v3 *wchar2_t
	)
	v0 = (*int32)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045536, 16404, 0, 0)))
	v1 = v0
	v2 = *v0
	if v2 < 0 {
		return 0
	}
	for {
		v3 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045536, 16406, uintptr(v2), 0)))
		v4 := nox_xxx_playerByName_4170D0(v3)
		if v4 != nil {
			if v4.PlayerInd != 31 {
				break
			}
		}
		v2 = *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*1))
		v1 = (*int32)(unsafe.Add(unsafe.Pointer(v1), 4*1))
		if v2 < 0 {
			return 0
		}
	}
	return 1
}
func sub_4557D0(a1 int32) {
	if a1 != 0 {
		if dword_5d4594_1045516 != nil {
			nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1045516)
		}
	}
	dword_5d4594_1045516 = nil
}
func sub_455800() {
	WideCharStr, free1 := alloc.Make([]wchar2_t{}, 10)
	defer free1()
	v5, free2 := alloc.Make([]wchar2_t{}, 26)
	defer free2()
	if dword_5d4594_1045516 != nil {
		v1 := nox_xxx_servGetPlrLimit_409FA0()
		nox_itow(v1, &WideCharStr[0], 10)
		nox_window_call_field_94_fnc((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1045592)), 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), 0)
		if noxflags.HasGame(1) {
			nox_window_call_field_94_fnc(dword_5d4594_1045528, 16399, 0, 0)
			nox_window_call_field_94_fnc(dword_5d4594_1045532, 16399, 0, 0)
			for i := sub_4168E0(); i != nil; i = sub_4168F0(i) {
				nox_window_call_field_94_fnc(dword_5d4594_1045532, 16397, uintptr(unsafe.Add(i, 4*3)), math.MaxUint32)
			}
			r3 := sub_416900()
			for j := r3; r3 != nil; j = r3 {
				if int32(*(*uint8)(unsafe.Add(j, 72))) != 0 {
					nox_window_call_field_94_fnc(dword_5d4594_1045528, 16397, uintptr(unsafe.Add(j, 4*3)), math.MaxUint32)
				} else {
					nox_swprintf(&v5[0], internWStr("*%s"), (*int32)(unsafe.Add(j, 4*3)))
					nox_window_call_field_94_fnc(dword_5d4594_1045528, 16397, uintptr(unsafe.Pointer(&v5[0])), math.MaxUint32)
				}
				r3 = sub_416910(j)
			}
		}
	}
}
func sub_455920(a1 *wchar2_t) {
	if dword_5d4594_1045516 != nil {
		v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045516, 10200)
		nox_window_call_field_94_fnc(v2, 16397, uintptr(unsafe.Pointer(a1)), 3)
	}
}
func sub_455950(a1 *wchar2_t) {
	if dword_5d4594_1045516 != nil {
		v1 := sub_4559B0(a1)
		if v1 != -1 {
			nox_window_call_field_94_fnc(dword_5d4594_1045536, 16398, uintptr(v1), 0)
			if sub_455770() == 0 {
				sub_46AD20(dword_5d4594_1045516, 10191, 10192, 0)
			}
		}
	}
}
func sub_4559B0(a1 *wchar2_t) int32 {
	var (
		v1 int32
		v3 *wchar2_t
	)
	v1 = 0
	v2 := dword_5d4594_1045536.WidgetData
	if int32(*(*int16)(unsafe.Add(v2, 44))) <= 0 {
		return -1
	}
	for {
		v3 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1045536, 16406, uintptr(v1), 0)))
		if nox_wcscmp(v3, a1) == 0 {
			break
		}
		if func() int32 {
			p := &v1
			*p++
			return *p
		}() >= int32(*(*int16)(unsafe.Add(v2, 44))) {
			return -1
		}
	}
	return v1
}
func sub_455A00(a1 int32) int32 {
	var result int32
	if a1 != 0 && *memmap.PtrUint32(0x5D4594, 1045608) != 0 && nox_xxx_wndGetFlags_46ADA0(dword_5d4594_1045604)&0x10 != 0 {
		result = nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1045604)
	} else {
		result = nox_window_set_hidden(dword_5d4594_1045604, 1)
	}
	return result
}
func sub_455A50(a1 int8) {
	var (
		v3 int32
		v4 int32
	)
	nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
	if dword_5d4594_1045604 == nil && sub_455C30() == 0 {
		return
	}
	var cur_w, cur_h, cur_d int32
	nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(&cur_w, &cur_h, &cur_d)
	var max_w, max_h int32
	nox_xxx_screenGetSize_430C50_get_video_max(&max_w, &max_h)
	if cur_w > max_w {
		cur_w = max_w
	}
	if cur_h > max_h {
		cur_h = max_h
	}
	*memmap.PtrUint32(0x5D4594, 1045612) = 0
	*memmap.PtrUint32(0x5D4594, 1045616) = 0
	*memmap.PtrUint32(0x5D4594, 1045620) = 0
	*memmap.PtrUint32(0x5D4594, 1045608) = 1
	*memmap.PtrUint32(0x5D4594, 1045624) = 0
	sub_46ACE0(dword_5d4594_1045604, 8811, 8826, 1)
	v3 = 0
	*memmap.PtrUint8(0x5D4594, 1045628) = uint8(a1)
	var v1 *gui.Window
	if int32(a1) != 0 {
		for {
			v1 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045604, v3+8811)
			nox_window_set_hidden(v1, 0)
			v3++
			if v3 >= int32(*memmap.PtrUint8(0x5D4594, 1045628)) {
				break
			}
		}
	}
	if int32(*memmap.PtrUint8(0x5D4594, 1045628)) <= 4 {
		v4 = int32(int(uint32(cur_w)) - dword_5d4594_1045604.SizeVal.X/2)
	} else {
		v4 = int32(int(uint32(cur_w)) - dword_5d4594_1045604.SizeVal.X)
	}
	dword_5d4594_1045604.Off.X = int(uint32(v4 - 91))
	dword_5d4594_1045604.EndPos.X = dword_5d4594_1045604.SizeVal.X + dword_5d4594_1045604.Off.X
	if int32(*memmap.PtrUint8(0x5D4594, 1045628)) <= 8 {
		if int32(*memmap.PtrUint8(0x5D4594, 1045628)) <= 4 {
			if v1 == nil {
				*memmap.PtrUint32(0x5D4594, 1045608) = 0
				return
			}
			dword_5d4594_1045604.Off.Y = int(uint32(cur_h - int32(*memmap.PtrUint8(0x5D4594, 1045628))*40))
		} else {
			dword_5d4594_1045604.Off.Y = int(cur_h) - dword_5d4594_1045604.SizeVal.Y/2
		}
	} else {
		dword_5d4594_1045604.Off.Y = int(uint32(cur_h)) - dword_5d4594_1045604.SizeVal.Y
	}
	dword_5d4594_1045604.EndPos.Y = dword_5d4594_1045604.SizeVal.Y + dword_5d4594_1045604.Off.Y
	nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1045604)
}
func sub_455C10() int32 {
	*memmap.PtrUint32(0x5D4594, 1045608) = 0
	return sub_455A00(0)
}
func sub_455CD0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1 = win.C()
		a2 = draw.C()
	)
	v2 := a1
	v5 := a1
	v8 := uint8(int8(int32(*(*uint8)(a1)) - 107))
	var v6, v7 int32
	nox_client_wndGetPosition_46AA60((*gui.Window)(v5), &v6, &v7)
	if int32(*memmap.PtrUint8(0x5D4594, uintptr(v8)+1045612)) == 1 {
		v3 := *(*unsafe.Pointer)(unsafe.Add(a2, 4*8))
		if v3 != nil {
			nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(v3), v6, v7)
		}
	} else if int32(*memmap.PtrUint8(0x5D4594, uintptr(v8)+1045612)) == 2 {
		v3 := *(*unsafe.Pointer)(unsafe.Add(a2, 4*12))
		if v3 != nil {
			nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(v3), v6, v7)
		}
	} else {
		v3 := *(*unsafe.Pointer)(unsafe.Add(a2, 4*6))
		if v3 != nil {
			nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(v3), v6, v7)
		}
	}
	if int32(*(*uint8)(unsafe.Add(v2, 4)))&0x20 != 0 && *memmap.PtrUint32(0x5D4594, 1045632) != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1045632)), v6-4, v7-4)
	}
	return 1
}
func sub_455E70(a1 uint8) int32 {
	for i := int32(0); i < int32(*memmap.PtrUint8(0x5D4594, 1045628)); i++ {
		v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045604, i+8811)
		nox_xxx_wndClearFlag_46AD80(v2, 32)
	}
	v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045604, int32(a1)+8810)
	return nox_xxx_wnd_46AD60(v3, 32)
}
func sub_455EE0() {
	if dword_5d4594_1045604 != nil {
		nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1045604)
	}
	dword_5d4594_1045604 = nil
	*memmap.PtrUint32(0x5D4594, 1045608) = 0
}
func sub_455F10(a1 int32) {
	if a1 != 0 && dword_5d4594_1045640 != 0 && nox_xxx_wndGetFlags_46ADA0(dword_5d4594_1045636)&0x10 != 0 {
		nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1045636)
	} else {
		nox_window_set_hidden(dword_5d4594_1045636, 1)
	}
}
func sub_455F60() {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v6 int32
	)
	nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
	if dword_5d4594_1045636 != nil || sub_456070() != 0 {
		nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(&v3, &v2, &v6)
		nox_xxx_screenGetSize_430C50_get_video_max(&v4, &v5)
		v1 = v3
		if v3 > v4 {
			v1 = v4
			v3 = v4
		}
		if v2 > v5 {
			v2 = v5
		}
		dword_5d4594_1045640 = 1
		dword_5d4594_1045636.Off.X = int(uint32(v1)) - dword_5d4594_1045636.SizeVal.X/3 - 91
		dword_5d4594_1045636.EndPos.X = dword_5d4594_1045636.SizeVal.X + dword_5d4594_1045636.Off.X
		dword_5d4594_1045636.Off.Y = int(uint32(v2 - 120))
		dword_5d4594_1045636.EndPos.Y = dword_5d4594_1045636.SizeVal.Y + dword_5d4594_1045636.Off.Y
		*memmap.PtrUint8(0x5D4594, 1045644) = 0
		nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1045636)
	}
}
func sub_456050() {
	dword_5d4594_1045640 = 0
	sub_455F10(0)
}
func sub_456070() int32 {
	if dword_5d4594_1045636 != nil {
		return 1
	}
	dword_5d4594_1045636 = nox_new_window_from_file(internCStr("gui_fb.wnd"), nil)
	nox_window_set_all_funcs(dword_5d4594_1045636, nil, sub_4560D0, nil)
	if dword_5d4594_1045636 == nil {
		return 0
	}
	sub_455F10(0)
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1045648) = nox_xxx_gLoadImg_42F970(internCStr("FlagTeamBorder"))
	return 1
}
func sub_4560D0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1 = win
		a2 = draw
		v4 int32
		v5 int32
	)
	nox_client_wndGetPosition_46AA60(win, &v4, &v5)
	v2 := a2.BgImageHnd
	if v2 != nil {
		nox_client_drawImageAt_47D2C0(v2, v4, v5)
	}
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))&0x20 != 0 && *memmap.PtrUint32(0x5D4594, 1045648) != 0 {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*memmap.PtrPtr(0x5D4594, 1045648)), v4-4, v5-4)
	}
	return 1
}
func sub_456240() {
	if dword_5d4594_1045636 != nil {
		nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1045636)
	}
	dword_5d4594_1045636 = nil
	dword_5d4594_1045640 = 0
}
func sub_456500() {
	v0 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10501)
	v1 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10502)
	nox_window_call_field_94_fnc(v0, 16399, 0, 0)
	nox_window_call_field_94_fnc(v1, 16399, 0, 0)
	nox_xxx_wnd_46ABB0(dword_5d4594_1045688, 0)
	nox_xxx_wnd_46ABB0(dword_5d4594_1045692, 0)
	for i := nox_server_teamFirst_418B10(); i != nil; i = nox_server_teamNext_418B60(i) {
		sub_457230(i)
	}
	for j := nox_common_playerInfoGetFirst_416EA0(); j != nil; j = nox_common_playerInfoGetNext_416EE0(j) {
		if j.PlayerInd != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
			sub_457140(int32(j.NetCodeVal), (*wchar2_t)(unsafe.Add(unsafe.Pointer(j), unsafe.Sizeof(wchar2_t(0))*2352)))
			v4 := nox_xxx_objGetTeamByNetCode_418C80(j.NetCodeVal)
			if nox_xxx_servObjectHasTeam_419130(v4) != 0 {
				sub_4571A0(int32(j.NetCodeVal), int32(v4.ID))
			}
		}
	}
	if noxflags.HasGame(4096) {
		nox_xxx_wnd_46ABB0(v0, 0)
		nox_xxx_wnd_46ABB0(v1, 0)
	} else {
		nox_xxx_wnd_46ABB0(v0, 1)
		nox_xxx_wnd_46ABB0(v1, 1)
	}
}
func sub_456640(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win
		a2    = draw
		xLeft int32
		yTop  int32
	)
	nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
	nox_client_wndGetPosition_46AA60(win, &xLeft, &yTop)
	if int32(int8(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 4)))) >= 0 {
		if a2.BgColorVal != 0x80000000 {
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, int32(a1.SizeVal.X), int32(a1.SizeVal.Y))
		}
	} else {
		nox_client_drawImageAt_47D2C0(a2.BgImageHnd, xLeft, yTop)
	}
	if noxflags.HasGame(1) && !noxflags.HasGame(0x8000) && sub_40A740() == 0 {
		v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10502)
		if nox_window_call_field_94_fnc(v2, 16404, 0, 0) < 0 {
			v6 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10503)
			nox_xxx_wnd_46ABB0(v6, 0)
		} else {
			v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10501)
			v4 := (*uint32)(unsafe.Pointer(nox_window_call_field_94_fnc(v3, 16404, 0, 0)))
			v5 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10503)
			nox_xxx_wnd_46ABB0(v5, bool2int32(*v4 >= 0))
		}
	}
	v7 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10502)
	if nox_window_call_field_94_fnc(v7, 16404, 0, 0) < 0 {
		nox_xxx_wnd_46ABB0(dword_5d4594_1045688, 0)
		nox_xxx_wnd_46ABB0(dword_5d4594_1045692, 0)
	}
	return 1
}
func sub_456BB0(a1 unsafe.Pointer) {
	var (
		v6 types.Pointf
	)
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 || (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 4)))&1) == 0 && (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 3680)))&1) == 0 {
		v2 := bool2int32(noxflags.HasGame(1))
		v1a := nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
		v3 := v1a
		if v1a != nil {
			if nox_xxx_servObjectHasTeam_419130(v1a) != 0 {
				if v2 == 0 {
					sub_419960(a1, v3, int16(uint16(nox_player_netCode_85319C)))
					*memmap.PtrUint32(0x5D4594, 1045696)++
					return
				}
				sub_4196D0(unsafe.Pointer(v3), a1, int32(nox_player_netCode_85319C), 1)
				if !noxflags.HasGame(128) {
					v1 := nox_common_playerInfoGetByID_417040(int32(nox_player_netCode_85319C))
					v4 := v1
					if v1 != nil {
						nox_xxx_mapFindPlayerStart_4F7AB0(&v6, v1.PlayerUnit)
						nox_xxx_unitMove_4E7010(v4.PlayerUnit, &v6)
						*memmap.PtrUint32(0x5D4594, 1045696)++
						return
					}
				}
			} else {
				if v2 != 0 {
					nox_xxx_createAtImpl_4191D0(*(*uint8)(unsafe.Add(a1, 57)), unsafe.Pointer(v3), v2, int32(nox_player_netCode_85319C), 1)
					*memmap.PtrUint32(0x5D4594, 1045696)++
					return
				}
				sub_419900(a1, unsafe.Pointer(v3), int16(uint16(nox_player_netCode_85319C)))
			}
			*memmap.PtrUint32(0x5D4594, 1045696)++
		}
	}
}
func sub_456D00(a1 int32, a2 *wchar2_t) *wchar2_t {
	var (
		v3 *wchar2_t
		v4 *wchar2_t
		v6 [56]wchar2_t
	)
	v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10502)
	v3 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(v2, 16406, uintptr(a1), 0)))
	nox_wcscpy(&v6[0], v3)
	v4 = nox_wcstok(&v6[0], internWStr("\t\n\r"))
	return nox_wcscpy(a2, v4)
}
func sub_456D60(a1 int32) *int32 {
	var (
		v1     *int32
		v2     *int32
		result *int32
		v4     *int32
		v5     *int32
	)
	if a1 != 0 && dword_5d4594_1045684 != nil {
		nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1045684)
	}
	v1 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1045652))))))
	if v1 != nil {
		for {
			v2 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v1)))))
			nox_common_list_remove_425920(unsafe.Pointer(v1))
			alloc.Free(v1)
			v1 = v2
			if v2 == nil {
				break
			}
		}
	}
	result = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1045668))))))
	v4 = result
	if result != nil {
		for {
			v5 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v4)))))
			nox_common_list_remove_425920(unsafe.Pointer(v4))
			alloc.Free(v4)
			v4 = v5
			if v5 == nil {
				break
			}
		}
	}
	dword_5d4594_1045684 = nil
	return result
}
func sub_456DF0(a1 int32) {
	if dword_5d4594_1045684 != nil {
		result := sub_456E40(a1, 1)
		v2 := result
		if result != -1 {
			v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10501)
			nox_window_call_field_94_fnc(v3, 16398, uintptr(v2), 0)
		}
	}
}
func sub_456E40(a1 int32, a2 int32) int32 {
	var (
		v2 *int32
		v3 int32
	)
	v2 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1045652))))))
	v3 = 0
	if v2 == nil {
		return -1
	}
	for *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*15)) != a1 {
		v2 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v2)))))
		v3++
		if v2 == nil {
			return -1
		}
	}
	if a2 != 0 {
		nox_common_list_remove_425920(unsafe.Pointer(v2))
		alloc.Free(v2)
	}
	return v3
}
func sub_456EA0(a1 *wchar2_t) {
	if dword_5d4594_1045684 != nil {
		v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10502)
		v3 := sub_456F10(a1, 1)
		v4 := v3
		if v3 != -1 {
			sub_4258C0((**uint32)(memmap.PtrOff(0x5D4594, 1045668)), v3)
			nox_window_call_field_94_fnc(v2, 16404, 0, 0)
			nox_window_call_field_94_fnc(v2, 16398, uintptr(v4), 0)
		}
		sub_456500()
	}
}
func sub_456F10(a1 *wchar2_t, a2 int32) int32 {
	var (
		v2 *int32
		v3 int32
		v4 *wchar2_t
		v6 [56]wchar2_t
	)
	v2 = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1045668))))))
	v3 = 0
	if v2 == nil {
		return -1
	}
	for {
		nox_wcscpy(&v6[0], (*wchar2_t)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(wchar2_t(0))*6)))
		v4 = nox_wcstok(&v6[0], internWStr(" \t\n\r"))
		if _nox_wcsicmp(v4, a1) == 0 {
			break
		}
		v2 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v2)))))
		v3++
		if v2 == nil {
			return -1
		}
	}
	if a2 != 0 {
		nox_common_list_remove_425920(unsafe.Pointer(v2))
		alloc.Free(v2)
	}
	return v3
}
func sub_456FA0() {
	if dword_5d4594_1045684 != nil {
		v1 := unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1045668)))))
		if v1 != nil {
			for {
				v2 := unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(v1)))
				nox_common_list_remove_425920(v1)
				alloc.FreePtr(v1)
				v1 = v2
				if v2 == nil {
					break
				}
			}
		}
		nox_xxx_wnd_46ABB0(dword_5d4594_1045688, 0)
		nox_xxx_wnd_46ABB0(dword_5d4594_1045692, 0)
		sub_456500()
	}
}
func sub_457120(a1 unsafe.Pointer) uint8 {
	return *memmap.PtrUint8(0x587000, uintptr((int32(*(*uint8)(unsafe.Add(a1, 56)))%10)*8)+128968)
}
func sub_457140(a1 int32, a2 *wchar2_t) {
	if dword_5d4594_1045684 != nil {
		v3 := (*wchar2_t)(alloc.Calloc1(1, 0x48))
		sub_425770(unsafe.Pointer(v3))
		nox_common_list_append_4258E0((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 1045652)), (*nox_list_item_t)(unsafe.Pointer(v3)))
		nox_wcscpy((*wchar2_t)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(wchar2_t(0))*6)), a2)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*15)) = uint32(a1)
		v4 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10501)
		nox_window_call_field_94_fnc(v4, 16397, uintptr(unsafe.Pointer(a2)), 3)
	}
}
func sub_4571A0(a1 int32, a2 int32) {
	if dword_5d4594_1045684 != nil {
		v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1045684, 10501).WidgetData
		result := sub_456E40(a1, 0)
		v4 := result
		if result != -1 {
			v5 := int32(3)
			if a2 != 0 {
				for i := unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(mem_getI32Ptr(0x5D4594, 1045668))))); i != nil; i = unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(i))) {
					if *(*int32)(unsafe.Add(i, 4*15)) == a2 {
						v5 = int32(*(*uint8)(unsafe.Add(i, 64)))
					}
				}
			}
			result := *(*unsafe.Pointer)(unsafe.Add(v3, 24))
			*(*uint32)(unsafe.Add(result, v4*524+516)) = **(**uint32)(memmap.PtrOff(0x85B3FC, uintptr(v5*4+132)))
		}
	}
}
func sub_4573A0() {
	if dword_5d4594_1045684 != nil {
		sub_456500()
	}
}
func sub_4573B0() {
	*memmap.PtrUint32(0x5D4594, 1045696) = 0
}
func sub_457460(a1 unsafe.Pointer) {
	WideCharStr, free := alloc.Make([]wchar2_t{}, 16)
	defer free()
	nox_itow(int32(*(*uint16)(unsafe.Add(a1, 54))), &WideCharStr[0], 10)
	nox_window_call_field_94_fnc(dword_5d4594_1046516, 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), 0)
	nox_itow(int32(*(*uint8)(unsafe.Add(a1, 56))), &WideCharStr[0], 10)
	nox_window_call_field_94_fnc(dword_5d4594_1046520, 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), 0)
}
func nox_xxx_guiServerOptionsTryHide_4574D0() int32 {
	if dword_5d4594_1046492 == nil {
		return 0
	}
	nox_xxx_guiServerOptionsHide_4597E0(0)
	dword_5d4594_1046492 = nil
	return 1
}
func sub_457B60(a1 unsafe.Pointer) {
	var (
		v1  *byte
		v3  *byte
		v4  uint16
		v5  *byte
		v7  uint16
		v8  uint8
		v12 int32
		v14 int32
		v16 int32
		v17 uint32
	)
	WideCharStr, free1 := alloc.Make([]wchar2_t{}, 16)
	defer free1()
	v20, free2 := alloc.Make([]wchar2_t{}, 100)
	defer free2()
	v1 = nox_xxx_serverOptionsGetServername_40A4C0()
	nox_swprintf(&v20[0], internWStr("%S"), v1)
	nox_window_call_field_94_fnc(dword_5d4594_1046512, 16414, uintptr(unsafe.Pointer(&v20[0])), 0)
	sub_459CD0()
	var v2 *gui.Window
	if noxflags.HasGame(128) {
		v2 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10122)
	} else {
		v2 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10119)
	}
	nox_window_set_hidden(v2, 1)
	if noxflags.HasGame(1) {
		nox_xxx_wnd_46ABB0(dword_5d4594_1046508, 1)
		if noxflags.HasGame(128) {
			v3 = nox_xxx_cliGamedataGet_416590(1)
			v4 = uint16(int16(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*26))) & 0x17F0))
			nox_client_guiserv_updateMapList_458230(int32(v4), v3, true)
			v5 = sub_4165B0()
			*(*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*26)) = uint16(int16(int32(v4) | (int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*26))) & 0xE80F)))
			if sub_40A740() != 0 {
				nox_xxx_wnd_46ABB0(dword_5d4594_1046508, 0)
			} else if nox_xxx_CheckGameplayFlags_417DA0(4) {
				v6 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046508, 10330)
				v6.DrawData().Field0 |= 4
			} else {
				sub_46AD20(dword_5d4594_1046508, 10331, 10333, 0)
			}
		} else {
			if nox_xxx_CheckGameplayFlags_417DA0(4) {
				sub_46AD20(dword_5d4594_1046508, 10330, 10331, 0)
			} else {
				sub_46AD20(dword_5d4594_1046508, 10330, 10333, 0)
			}
			v5 = (*byte)(a1)
			nox_client_guiserv_updateMapList_458230(int32(*(*uint16)(unsafe.Add(a1, 52))), (*byte)(a1), false)
		}
		v7 = uint16(nox_xxx_servGamedataGet_40A020(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*26)))))
		nox_itow(int32(v7), &WideCharStr[0], 10)
		nox_window_call_field_94_fnc(dword_5d4594_1046516, 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), 0)
		v8 = sub_40A180(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*26))))
		nox_itow(int32(v8), &WideCharStr[0], 10)
		nox_window_call_field_94_fnc(dword_5d4594_1046520, 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), 0)
		sub_4580E0(int32(uintptr(unsafe.Pointer(v5))))
	} else {
		v9 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10161)
		nox_xxx_wnd_46ABB0(v9, 0)
		nox_xxx_wnd_46ABB0(dword_5d4594_1046536, 0)
		dword_5d4594_1046536.Flags |= 8
		nox_xxx_wnd_46ABB0(dword_5d4594_1046504, 1)
		sub_46AD20(dword_5d4594_1046504, 10134, 10135, 0)
		sub_46ACE0(dword_5d4594_1046492, 10141, 10141, 1)
		v5 = (*byte)(a1)
		nox_client_guiserv_updateMapList_458230(int32(*(*uint16)(unsafe.Add(a1, 52))), (*byte)(a1), false)
		nox_itow(int32(*(*uint16)(unsafe.Add(a1, 54))), &WideCharStr[0], 10)
		nox_window_call_field_94_fnc(dword_5d4594_1046516, 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), 0)
		nox_itow(int32(*(*uint8)(unsafe.Add(a1, 56))), &WideCharStr[0], 10)
		nox_window_call_field_94_fnc(dword_5d4594_1046520, 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), 0)
		if false {
			v10 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10210)
			nox_window_set_hidden(v10, 0)
			sub_457FE0()
		}
	}
	v11 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046508, 10331)
	if nox_xxx_CheckGameplayFlags_417DA0(2) {
		v12 = int32(v11.DrawData().Field0)
		*(*uint8)(unsafe.Pointer(&v12)) = uint8(int8(v12 | 4))
		v11.DrawData().Field0 = uint32(v12)
	}
	v13 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046508, 10333)
	if nox_xxx_CheckGameplayFlags_417DA0(1) {
		v14 = int32(v13.DrawData().Field0)
		*(*uint8)(unsafe.Pointer(&v14)) = uint8(int8(v14 | 4))
		v13.DrawData().Field0 = uint32(v14)
	}
	v15 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10119)
	v16 = int32(uintptr(unsafe.Pointer(nox_xxx_guiServerOptionsGetGametypeName_4573C0(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*26)))))))
	nox_window_call_field_94_fnc(v15, 16385, uintptr(v16), 0)
	sub_459880(int32(uintptr(unsafe.Pointer(v5))))
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v17), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*26))
	sub_457F30(int32((v17 >> 12) & 1))
}
func sub_457F30(a1 int32) {
	v1 := bool2int32(a1 != 1)
	v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046504, 10152)
	nox_xxx_wnd_46ABB0(v2, v1)
	v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046504, 10141)
	nox_xxx_wnd_46ABB0(v3, v1)
	nox_xxx_wnd_46ABB0(dword_5d4594_1046516, v1)
	nox_xxx_wnd_46ABB0(dword_5d4594_1046520, v1)
	if a1 == 1 {
		v4 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10122)
		if wndIsShown_nox_xxx_wndIsShown_46ACC0(v4) == 0 {
			nox_window_set_hidden(v4, 1)
		}
	}
	v5 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10183)
	nox_window_set_hidden(v5, a1)
}
func nox_xxx_windowServerOptionsDrawProc_458500(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = win
		xLeft int32
		v5    int32
		mpos  = nox_client_getMousePos_4309F0()
	)
	nox_client_wndGetPosition_46AA60(win, &xLeft, &v5)
	nox_client_drawRectFilledAlpha_49CF10(xLeft, v5+25, int32(a1.SizeVal.X), int32(a1.SizeVal.Y-25))
	v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10120)
	if wndIsShown_nox_xxx_wndIsShown_46ACC0(v2) == 0 && !nox_xxx_wndPointInWnd_46AAB0(v2, mpos.X, mpos.Y) {
		nox_xxx_wndClearCaptureMain_46ADE0(v2)
		nox_window_set_hidden(v2, 1)
	}
	return 1
}
func nox_xxx_guiServerOptionsProc_458590(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	if a2 != 21 {
		return 1
	}
	if a3 != 1 {
		return 0
	}
	if a4 == 2 {
		nox_xxx_clientPlaySoundSpecial_452D80(231, 100)
		nox_xxx_guiServerOptionsHide_4597E0(0)
	}
	return 1
}
func sub_459150() {
	var (
		v0  *byte
		i   int32
		v2  *byte
		v3  int32
		v4  *wchar2_t
		v6  *byte
		v7  *byte
		v8  int32
		v9  *byte
		v10 uint8
		v11 *byte
	)
	var v12 *byte
	var v13 *byte
	var v14 *int32
	var v16 *int32
	var v17 *int32
	var v18 int16
	var v19 [16]byte
	v0 = sub_4165B0()
	if *(*byte)(unsafe.Add(unsafe.Pointer(v0), 52))&0x60 != 0 {
		for i = int32(nox_xxx_getTeamCounter_417DD0()); i < 2; i++ {
			v2 = (*byte)(unsafe.Pointer(nox_xxx_teamCreate_4186D0(0)))
			v3 = bool2int32(i != 0) + 1
			if sub_40A740() != 0 {
				sub_418800((*wchar2_t)(unsafe.Pointer(v2)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1046564)), 0)
			} else {
				v4 = nox_server_teamTitle_418C20(v3)
				sub_418800((*wchar2_t)(unsafe.Pointer(v2)), v4, 1)
			}
			*(*byte)(unsafe.Add(unsafe.Pointer(v2), 56)) = byte(int8(v3))
			sub_4184D0((*server.Team)(unsafe.Pointer(v2)))
		}
		nox_xxx_SetGameplayFlag_417D50(4)
	}
	if *(*byte)(unsafe.Add(unsafe.Pointer(v0), 57)) != 0 {
		v5 := sub_409B80()
		v6 = v5
	} else {
		v6 = v0
	}
	if *v6 != 0 {
		v7 = nox_xxx_mapGetMapName_409B40()
		v8 = nox_strcmpi(v6, v7)
		sub_4165F0(1, 0)
		v9 = sub_4165D0(0)
		nox_xxx_gameSetServername_40A440((*byte)(unsafe.Add(unsafe.Pointer(v9), 9)))
		if ((int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*26))) >> 8) & 0x10) == 0 {
			sub_409FB0_settings(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*26))), *(*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*27)))
			sub_40A040_settings(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*26))), *(*byte)(unsafe.Add(unsafe.Pointer(v9), 56)))
		}
		if v8 != 0 && false {
			if !noxflags.HasGame(128) {
				nox_xxx_net_4263C0()
				sub_4264D0()
				sub_416150(15, 0)
			}
			if *(*byte)(unsafe.Add(unsafe.Pointer(v9), 57)) == 0 {
				sub_41D650()
			}
		}
		if noxflags.HasGame(128) {
			nox_common_gameFlags_unset_40A540(49152)
			nox_xxx_setGameFlags_40A4D0(uint32(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*26))) & 0xC000))
		}
		*(*byte)(unsafe.Add(unsafe.Pointer(v9), 57)) = 0
		if v8 != 0 {
			v19[0] = 0
			*(*uint32)(unsafe.Pointer(&v19[1])) = 0
			*(*uint32)(unsafe.Pointer(&v19[5])) = 0
			*(*uint32)(unsafe.Pointer(&v19[9])) = 0
			v10 = *memmap.PtrUint8(0x587000, 131672)
			libc.StrCpy(&v19[0], v6)
			v11 = &v19[libc.StrLen(&v19[0])]
			*(*uint32)(unsafe.Pointer(v11)) = *memmap.PtrUint32(0x587000, 131668)
			*(*byte)(unsafe.Add(unsafe.Pointer(v11), 4)) = v10
			nox_xxx_mapLoad_4D2450(&v19[0])
			sub_416690()
			sub_4165D0(1)
			nox_xxx_guiServerOptionsHide_4597E0(0)
		} else {
			nox_xxx_spellEnableAll_424BD0()
			sub_4537F0()
			v17 = (*int32)(unsafe.Pointer(sub_459870()))
			v12 = nox_xxx_cliGamedataGet_416590(1)
			sub_57AAA0(internCStr("user.rul"), v12, v17)
			v13 = nox_server_currentMapGetFilename_409B30()
			sub_57A950(v13)
			v18 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
			v16 = (*int32)(unsafe.Pointer(sub_459870()))
			v14 = (*int32)(unsafe.Pointer(nox_xxx_cliGamedataGet_416590(0)))
			sub_57A1E0(v14, internCStr("user.rul"), v16, 3, v18)
			nox_xxx_guiServerOptionsHide_4597E0(0)
		}
	}
}
func sub_4593B0(a1 int32) {
	v1 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10163)
	v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10161)
	v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10162)
	if a1 != 0 {
		if a1 == 1 {
			v1.DrawData().BgImageHnd = dword_5d4594_1046360
			v3.DrawData().BgImageHnd = dword_5d4594_1046356
			if dword_5d4594_1046532 != nil {
				sub_456D60(1)
				dword_5d4594_1046532 = nil
			}
			if dword_5d4594_1046540 != nil {
				sub_4AD820()
				dword_5d4594_1046540 = nil
			}
			dword_5d4594_1046528 = nox_xxx_guiServerAccessLoad_4541D0(dword_5d4594_1046492)
			sub_459560(10161)
		} else {
			if a1 == 2 {
				v1.DrawData().BgImageHnd = dword_5d4594_1046360
				if noxflags.HasGame(1) {
					v2.DrawData().BgImageHnd = dword_5d4594_1046360
				} else {
					v2.DrawData().DisImageHnd = dword_5d4594_1046360
				}
				if dword_5d4594_1046528 != nil {
					sub_4557D0(1)
					dword_5d4594_1046528 = nil
				}
				if dword_5d4594_1046540 != nil {
					sub_4AD820()
					dword_5d4594_1046540 = nil
				}
				dword_5d4594_1046532 = nox_xxx_guiServerPlayersLoad_456270(dword_5d4594_1046492)
				sub_459560(10162)
			}
		}
	} else {
		if noxflags.HasGame(1) {
			v2.DrawData().BgImageHnd = dword_5d4594_1046356
		} else {
			v2.DrawData().DisImageHnd = dword_5d4594_1046356
		}
		v3.DrawData().BgImageHnd = dword_5d4594_1046356
		if dword_5d4594_1046532 != nil {
			sub_456D60(1)
			dword_5d4594_1046532 = nil
		} else if dword_5d4594_1046528 != nil {
			sub_4557D0(1)
			dword_5d4594_1046528 = nil
		}
		dword_5d4594_1046540 = nox_xxx_gui_4AD320(dword_5d4594_1046492)
		sub_459560(10163)
	}
}
func sub_459560(a1 int32) {
	v1 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, a1)
	v2 := v1.ParentPtr
	switch a1 {
	case 10161:
		v6 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10163)
		sub_46B120(v6, nil)
		sub_46B120(v6, v2)
		v4 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10162)
		v7 := v4
		sub_46B120(v4, nil)
		sub_46B120(v7, v2)
	case 10162:
		v5 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10163)
		sub_46B120(v5, nil)
		sub_46B120(v5, v2)
		v4 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10161)
		v7 := v4
		sub_46B120(v4, nil)
		sub_46B120(v7, v2)
	case 10163:
		v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10162)
		sub_46B120(v3, nil)
		sub_46B120(v3, v2)
		v4 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10161)
		v7 := v4
		sub_46B120(v4, nil)
		sub_46B120(v7, v2)
	}
	sub_46B120(v1, nil)
	sub_46B120(v1, v2)
}
func sub_459700() int32 {
	var (
		v0 *byte
		v1 int32
		v2 int32
		v3 *wchar2_t
		v5 [256]wchar2_t = [256]wchar2_t{}
	)
	sub_416580()
	v0 = sub_4165B0()
	v1 = int32(nox_window_call_field_94_fnc(dword_5d4594_1046496, 16404, 0, 0))
	v2 = v1
	v3 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1046496, 16406, uintptr(v1), 0)))
	if v3 != nil {
		nox_wcsncpy(&v5[0], v3, math.MaxUint8)
		v5[math.MaxUint8] = 0
	} else {
		v5[0] = 0
	}
	nox_window_call_field_94_fnc(dword_5d4594_1046496, 16398, uintptr(v2), 0)
	nox_window_call_field_94_fnc(dword_5d4594_1046496, 16402, uintptr(v2), 0)
	nox_window_call_field_94_fnc(dword_5d4594_1046496, 16397, uintptr(unsafe.Pointer(&v5[0])), math.MaxUint32)
	nox_window_call_field_94_fnc(dword_5d4594_1046496, 16403, uintptr(v2), 0)
	sub_57A9F0(v0, internCStr("user.rul"))
	sub_57A1E0((*int32)(unsafe.Pointer(v0)), internCStr("user.rul"), nil, 5, int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof(uint16(0))*26))))
	sub_459880(int32(uintptr(unsafe.Pointer(v0))))
	return sub_459D50(1)
}
func nox_xxx_guiServerOptionsHide_4597E0(a1 int32) {
	if dword_5d4594_1046492 != nil {
		v1 := nox_xxx_wndGetFocus_46B4F0()
		if nox_window_is_child(dword_5d4594_1046492, v1) != 0 {
			nox_xxx_windowFocus_46B500(nil)
		}
		nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_1046492)
		dword_5d4594_1046492 = nil
		sub_456D60(0)
		sub_4BE610()
		dword_5d4594_1046532 = nil
		sub_4557D0(0)
		dword_5d4594_1046528 = nil
		sub_4AD820()
		dword_5d4594_1046536 = nil
	}
	if a1 != 0 {
		sub_57ADF0(mem_getI32Ptr(0x5D4594, 1045956))
		dword_587000_129656 = 1
	}
}
func sub_459870() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 1045956))
}
func sub_459A40(a1 *byte) {
	v2, free2 := alloc.Make([]byte{}, 100)
	defer free2()
	v3, free3 := alloc.Make([]wchar2_t{}, 100)
	defer free3()
	libc.StrNCpy(&v2[0], a1, 0xF)
	v2[15] = 0
	nox_swprintf(&v3[0], internWStr("%S"), &v2[0])
	nox_window_call_field_94_fnc(dword_5d4594_1046512, 16414, uintptr(unsafe.Pointer(&v3[0])), 0)
}
func sub_459AA0(a1 unsafe.Pointer) {
	var (
		v1     int32
		v2     *wchar2_t
		v3     *wchar2_t
		result *byte
		v5     int32
		v6     *byte
		v7     [100]byte
	)
	v1 = int32(nox_window_call_field_94_fnc(dword_5d4594_1046512, 16413, 0, 0))
	nox_sprintf(&v7[0], internCStr("%S"), v1)
	libc.StrNCpy((*byte)(unsafe.Add(a1, 9)), &v7[0], 0xF)
	*(*uint16)(unsafe.Add(a1, 52)) = uint16(int16(sub_459C10()))
	alloc.Memcpy(unsafe.Add(a1, 24), unsafe.Pointer(sub_453F90()), 0x14)
	*(*uint32)(unsafe.Add(a1, 44)) = *(*uint32)(unsafe.Pointer(sub_453600()))
	*(*uint32)(unsafe.Add(a1, 48)) = uint32(sub_453610())
	v2 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1046516, 16413, 0, 0)))
	if *v2 != 0 {
		*(*uint16)(unsafe.Add(a1, 54)) = uint16(int16(libc.WStrtol(v2, nil, 10)))
	}
	v3 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1046520, 16413, 0, 0)))
	if *v3 != 0 {
		*(*uint8)(unsafe.Add(a1, 56)) = uint8(int8(libc.WStrtol(v3, nil, 10)))
	}
	*(*uint8)(unsafe.Add(a1, 57)) = uint8((nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10122).DrawData().Field0 >> 2) & 1)
	result = (*byte)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_1046496, 16404, 0, 0)))
	if int32(uintptr(unsafe.Pointer(result))) >= 0 && (func() bool {
		v5 = int32(nox_window_call_field_94_fnc(dword_5d4594_1046496, 16406, uintptr(unsafe.Pointer(result)), 0))
		nox_sprintf(&v7[0], internCStr("%S"), v5)
		return (func() *byte {
			result = libc.StrTok(&v7[0], internCStr("\t"))
			return result
		}()) != nil
	}()) {
		v6 = result
		result = nil
		libc.StrCpy((*byte)(a1), v6)
	} else {
		*(*uint8)(a1) = 0
	}
}
func sub_459C30() {
	v0 := nox_xxx_cliGamedataGet_416590(1)
	sub_453F70(unsafe.Add(unsafe.Pointer(v0), 24))
	sub_4535E0((*int32)(unsafe.Add(unsafe.Pointer(v0), 4*11)))
	sub_4535F0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*12))))
	if dword_5d4594_1046492 != nil {
		sub_459880(int32(uintptr(unsafe.Pointer(v0))))
		sub_4BDF70((*int32)(unsafe.Pointer(v0)))
		nox_client_guiserv_updateMapList_458230(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof(uint16(0))*26))), v0, false)
		sub_457460(unsafe.Pointer(v0))
		if false {
			sub_457FE0()
		}
		v2 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10119)
		v3 := unsafe.Pointer(nox_xxx_guiServerOptionsGetGametypeName_4573C0(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof(uint16(0))*26)))))
		nox_window_call_field_94_fnc(v2, 16385, uintptr(v3), 0)
	}
}
func sub_459D50(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1046544) = uint32(a1)
	return result
}
func sub_459D60() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1046544))
}
func sub_459D80(a1 int32) {
	if dword_5d4594_1046492 != nil {
		nox_window_set_hidden(dword_5d4594_1046492, a1)
	}
}
func sub_459DA0() int32 {
	return bool2int32(dword_5d4594_1046492 != nil)
}
func sub_459DB0(dr *client.Drawable) int32 {
	return bool2int32(dr.Flags28Val&0x400000 != 0 && int32(dr.Flags29Val)&8 != 0)
}
func nox_xxx_cliNextMinimapObj_459EC0(a1 *client.Drawable) *client.Drawable {
	next := a1.Field_102
	if a1 != nil && a1 == next {
		panic("infinite loop!")
	}
	return next
}
func sub_45A010(dr *client.Drawable) *client.Drawable {
	return dr.Field_104
}
func sub_45A040(a1 *client.Drawable) *client.Drawable {
	if a1 == nil {
		return nil
	}
	return a1.Field_90
}
func nox_drawable_next_45A070(a1 *client.Drawable) *client.Drawable {
	if a1 == nil {
		return nil
	}
	return a1.NextPtr
}
func sub_45A0A0(a1 unsafe.Pointer) unsafe.Pointer {
	if a1 == nil {
		return nil
	}
	return *(*unsafe.Pointer)(unsafe.Add(a1, 424))
}
func nox_xxx_spriteSetActiveMB_45A990_drawable(a1 unsafe.Pointer) {
	*(*uint32)(unsafe.Add(a1, 120)) |= 4
}
func nox_xxx_cliDestroyObj_45A9A0(a1 unsafe.Pointer) {
	*(*uint32)(unsafe.Add(a1, 120)) &= 0xFFFFFFFB
}
func sub_45A9B0(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	var (
		v3  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int64
		v12 int32
		v14 *int32
		v16 int32
	)
	v2 := a1
	v3 = 0
	v16 = 0
	v4 := nox_xxx_draw_452270(int32(*(*uint32)(unsafe.Add(a1, 492))))
	v5 := v4
	v17 := v4
	r1 := nox_draw_getViewport_437250()
	v18 := r1
	if v5 == nil || r1 == nil {
		return
	}
	if *(*uint32)(unsafe.Add(a1, 120))&0x1000000 != 0 && (int32(*(*uint8)(unsafe.Add(a1, 280)))&0xC) == 0 {
		v7 = int32(*(*uint32)(unsafe.Add(a2, 12)) - *(*uint32)(unsafe.Add(a1, 12)))
		v8 = int32(*(*uint32)(unsafe.Add(a2, 16)) - *(*uint32)(unsafe.Add(a1, 16)))
		v9 = sub_4522A0(v17)
		v10 = v9
		if v7 < v9 && v8 < v9 && v9 > 0 {
			v11 = int64(math.Sqrt(float64(v8*v8 + v7*v7 + 1)))
			if int32(v11) < v10 {
				v12 = (v10 - int32(v11)) * 100 / v10
				v3 = v12
				if v12 <= 100 {
					if v12 < 0 {
						v3 = 0
					}
				} else {
					v3 = 100
				}
				v16 = int32((int(*(*int32)(unsafe.Add(a1, 12))) - v18.World.Max.X - int(*(*int32)(unsafe.Pointer(v18)))) * 50 / int(nox_win_width/2))
			}
		}
		v2 = a1
	}
	v13 := unsafe.Add(v2, 496)
	r2 := (*int32)(sub_452EB0(v13))
	v14 = r2
	if v3 != 0 {
		if r2 != nil {
			sub_452FE0(unsafe.Pointer(r2), v16)
			sub_452F50(unsafe.Pointer(v14), v3)
		} else {
			result := nox_xxx_draw_452300(v17)
			v15 := result
			if result != nil {
				sub_452EE0(result, v3)
				sub_452F80(v15, v16)
				sub_452E90(v13, v15)
			}
		}
	} else if r2 != nil {
		sub_4523D0(unsafe.Pointer(r2))
	}
}
func sub_45AB40() {
	result := unsafe.Pointer(sub_45A090())
	for i := result; result != nil; i = result {
		if *(*uint32)(unsafe.Add(i, 492)) != 0 {
			sub_45A9B0(i, *memmap.PtrPtr(0x852978, 8))
		}
		result = sub_45A0A0(i)
	}
}
func nox_xxx_spriteSetFrameMB_45AB80(a1 unsafe.Pointer, a2 int32) {
	if (int32(*(*uint8)(unsafe.Add(a1, 112)))&2) == 0 || (*(*uint32)(unsafe.Add(a1, 116))&0x40000) == 0 || *(*uint32)(unsafe.Add(a1, 276)) != 8 {
		*(*uint32)(unsafe.Add(a1, 312)) = *(*uint32)(unsafe.Add(a1, 308))
		*(*uint32)(unsafe.Add(a1, 308)) = uint32(a2)
	}
}
func nox_xxx_bookSetColor_45AC40() {
	*memmap.PtrUint32(0x5D4594, 1046880) = nox_color_rgb_4344A0(15, 15, 15)
	*memmap.PtrUint32(0x5D4594, 1046884) = nox_color_rgb_4344A0(115, 100, 100)
}
func nox_client_toggleSpellbook_45AC70() {
	if wndIsShown_nox_xxx_wndIsShown_46ACC0(nox_win_unk1) != 0 {
		nox_xxx_bookShowMB_45AD70(0)
	} else {
		nox_xxx_bookHideMB_45ACA0(0)
	}
}
func nox_xxx_bookHideMB_45ACA0(a1 int32) int32 {
	if wndIsShown_nox_xxx_wndIsShown_46ACC0(nox_win_unk1) != 0 || dword_5d4594_1047520 == 1 {
		return 0
	}
	dword_5d4594_1046864 = 0
	set_dword_5d4594_3799468(1)
	dword_5d4594_1046868 = uint32(bool2int32(dword_5d4594_1046872 != 0))
	v1 := nox_xxx_wndGetCaptureMain_46AE00()
	v2 := nox_win_unk1
	if v1 == nox_win_unk1 {
		nox_xxx_wndClearCaptureMain_46ADE0(nox_win_unk1)
		v2 = nox_win_unk1
	}
	nox_window_set_hidden(v2, 1)
	nox_xxx_clientPlaySoundSpecial_452D80(787, 100)
	if a1 != 0 {
		nox_xxx_aNox_cfg_0_587000_132132 = 1
		dword_5d4594_1046936 = 0
		nox_window_set_hidden(dword_5d4594_1046952, 1)
	}
	if nox_xxx_bookGetSpellDnDType_477670() == 1 {
		nox_xxx_bookSpellDnDclear_477660()
	}
	return 1
}
func nox_xxx_guiSpellSortList_45ADF0(a1 int32) int32 {
	var (
		v1 int32
		i  int32
		v3 int32
		k  int32
		v5 int32
		j  int32
		v7 int32
		v9 int32
	)
	v1 = 0
	dword_5d4594_1046656 = nox_xxx_guiFontHeightMB_43F320(nil) + 2
	*memmap.PtrUint32(0x5D4594, 1047508) = 0
	dword_5d4594_1047512 = 0
	v9 = (141/dword_5d4594_1046656)*2 - 2
	if dword_5d4594_1046868 == 1 {
		for i = nox_xxx_bookGetFirstCreMB_427300(); i != 0; i = nox_xxx_bookGetNextCre_427320(i) {
			if noxflags.HasGame(0x2000) && !noxflags.HasGame(4096) || *(*uint32)(unsafe.Add(dword_5d4594_1047516, i*4+4244)) != 0 {
				if nox_xxx_bookCreatureTest_4D70C0(i) != 0 {
					v3 = int32(*memmap.PtrUint32(0x5D4594, 1047508))
					v1 = 1
					*memmap.PtrUint32(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 1047508))*4+1046960) = uint32(i)
					*memmap.PtrUint32(0x5D4594, 1047508) = uint32(v3 + 1)
				}
			}
		}
	} else if a1 != 0 {
		for j = nox_xxx_spellFirstValid_424AD0(); j != 0; j = nox_xxx_spellNextValid_424AF0(j) {
			if j != 34 && nox_xxx_playerCheckSpellClass_57AEA0(a1, j) == 0 && (noxflags.HasGame(0x2000) && !noxflags.HasGame(4096) || *(*uint32)(unsafe.Add(dword_5d4594_1047516, j*4+3696)) != 0) {
				if nox_xxx_spellHasFlags_424A50(j, 0x15000) {
					dword_5d4594_1047512++
				}
				if !nox_xxx_spellHasFlags_424A50(j, 0x2000) {
					v7 = int32(*memmap.PtrUint32(0x5D4594, 1047508))
					v1 = 1
					*memmap.PtrUint32(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 1047508))*4+1046960) = uint32(j)
					*memmap.PtrUint32(0x5D4594, 1047508) = uint32(v7 + 1)
				}
			}
		}
	} else {
		for k = nox_xxx_bookFirstKnownAbil_425330(); k != 0; k = nox_xxx_bookNextKnownAbil_425350(k) {
			if noxflags.HasGame(0x2000) && !noxflags.HasGame(4096) || *(*uint32)(unsafe.Add(dword_5d4594_1047516, k*4+3696)) != 0 {
				v5 = int32(*memmap.PtrUint32(0x5D4594, 1047508))
				v1 = 1
				*memmap.PtrUint32(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 1047508))*4+1046960) = uint32(k)
				*memmap.PtrUint32(0x5D4594, 1047508) = uint32(v5 + 1)
			}
		}
	}
	*memmap.PtrUint32(0x5D4594, 1046940) = (*memmap.PtrUint32(0x5D4594, 1047508)-uint32(dword_5d4594_1047512))/uint32(v9) + 1
	libc.Sort(memmap.PtrOff(0x5D4594, 1046960), *memmap.PtrUint32(0x5D4594, 1047508)-uint32(dword_5d4594_1047512), 4, func(a, b unsafe.Pointer) int32 {
		v2 := int32(*(*uint32)(b))
		v6 := int32(*(*uint32)(a))
		var v3, v4 *wchar2_t
		if dword_5d4594_1046868 == 1 {
			v3 = nox_xxx_guiCreatureGetName_427240(v6)
			v4 = nox_xxx_guiCreatureGetName_427240(v2)
		} else if int32(*(*uint8)(unsafe.Add(dword_5d4594_1047516, 2251))) != 0 {
			v3 = nox_xxx_spellTitle_424930(v6)
			v4 = nox_xxx_spellTitle_424930(v2)
		} else {
			v3 = nox_xxx_abilityGetName_0_425260(v6)
			v4 = nox_xxx_abilityGetName_0_425260(v2)
		}
		if v3 != nil && v4 != nil {
			return _nox_wcsicmp(v3, v4)
		} else {
			return 0
		}
	})
	return v1
}
func nox_xxx_book_45B010(a1 int32) {
	var result uint32
	result = nox_gui_xxx_check_446360()
	if result != 0 {
		return
	}
	result = uint32(sub_4AE3D0())
	if result != 0 {
		return
	}
	if a1 != 0 || nox_xxx_get_57AF20() == 0 {
		dword_5d4594_1046864 = 1
		dword_5d4594_1046868 = uint32(bool2int32(dword_5d4594_1046872 != 0))
		nox_xxx_wndShowModalMB_46A8C0(nox_win_unk1)
		nox_xxx_clientPlaySoundSpecial_452D80(786, 100)
	}
}
func nox_xxx_bookWndProc_45B070(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	if dword_5d4594_1047520 == 1 {
		return 1
	}
	if a2 == 10 {
		nox_client_toggleSpellbook_45AC70()
		return 1
	}
	if *memmap.PtrUint32(0x852978, 8) != 0 && sub_478030() == 0 && sub_47A260() == 0 && (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 120)))&2) == 2 {
		return 1
	}
	if a2 != 5 {
		return 0
	}
	nox_window_set_hidden(dword_5d4594_1046944, 0)
	if nox_xxx_aNox_cfg_0_587000_132132 != 0 {
		if dword_5d4594_1046936+1 < memmap.Int32(0x5D4594, 1046940) {
			dword_5d4594_1046936++
		} else {
			dword_5d4594_1046932 = 0
			nox_xxx_aNox_cfg_0_587000_132132 = 0
			nox_window_set_hidden(dword_5d4594_1046952, 0)
		}
		if dword_5d4594_1046872 != 0 {
			dword_5d4594_1046924.Field24ptr().OnEnd.Set(nox_xxx_bookClickCreature_45B200)
		} else {
			dword_5d4594_1046924.Field24ptr().OnEnd.Set(nox_xxx_bookClickSpell_45B1F0)
		}
		dword_5d4594_1046868 = 2
		dword_5d4594_1046924.Field24ptr().Field_3 = uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq())
		nox_xxx_clientPlaySoundSpecial_452D80(788, 100)
		return 1
	}
	if dword_5d4594_1046932 < memmap.Int32(0x5D4594, 1047508)-dword_5d4594_1047512-1 {
		dword_5d4594_1046932++
		if dword_5d4594_1046872 != 0 {
			dword_5d4594_1046924.Field24ptr().OnEnd.Set(nox_xxx_bookClickCreature_45B200)
		} else {
			dword_5d4594_1046924.Field24ptr().OnEnd.Set(nox_xxx_bookClickSpell_45B1F0)
		}
		dword_5d4594_1046868 = 2
		dword_5d4594_1046924.Field24ptr().Field_3 = uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq())
		nox_xxx_clientPlaySoundSpecial_452D80(788, 100)
		return 1
	}
	return 1
}
func nox_xxx_bookClickSpell_45B1F0(_ *ImageRef) {
	dword_5d4594_1046868 = 0
	dword_5d4594_1046872 = 0
}
func nox_xxx_bookClickCreature_45B200(_ *ImageRef) {
	dword_5d4594_1046868 = 1
	dword_5d4594_1046872 = 1
}
func nox_xxx_book_45B210(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	if dword_5d4594_1047520 == 1 {
		return 1
	}
	if a2 == 10 {
		nox_client_toggleSpellbook_45AC70()
		return 1
	}
	if *memmap.PtrUint32(0x852978, 8) != 0 && sub_478030() == 0 && sub_47A260() == 0 && (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 120)))&2) == 2 {
		return 1
	}
	if a2 != 5 {
		return 0
	}
	nox_window_set_hidden(dword_5d4594_1046948, 0)
	if nox_xxx_aNox_cfg_0_587000_132132 == 0 {
		if dword_5d4594_1046932 < *memmap.PtrInt32(0x5D4594, 1047508)-dword_5d4594_1047512 {
			if dword_5d4594_1046932 <= 0 {
				nox_xxx_aNox_cfg_0_587000_132132 = 1
				dword_5d4594_1046936 = memmap.Int32(0x5D4594, 1046940) - 1
				nox_window_set_hidden(dword_5d4594_1046952, 1)
			} else {
				dword_5d4594_1046932--
			}
		} else {
			nox_xxx_aNox_cfg_0_587000_132132 = 1
			dword_5d4594_1046936 = 0
			nox_window_set_hidden(dword_5d4594_1046952, 1)
		}
	} else {
		if dword_5d4594_1046936 == 0 {
			return 1
		}
		dword_5d4594_1046936--
	}
	if dword_5d4594_1046872 != 0 {
		dword_5d4594_1046928.Field24ptr().OnEnd.Set(nox_xxx_bookClickCreature_45B200)
	} else {
		dword_5d4594_1046928.Field24ptr().OnEnd.Set(nox_xxx_bookClickSpell_45B1F0)
	}
	dword_5d4594_1046868 = 3
	dword_5d4594_1046928.Field24ptr().Field_3 = uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq())
	nox_xxx_clientPlaySoundSpecial_452D80(788, 100)
	return 1
}
func nox_xxx_bookChildWndProcMB_45B360(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	var (
		a1 = (*uint32)(win.C())
		v2 int32
	)
	v2 = 0
	if dword_5d4594_1047520 == 1 || *memmap.PtrUint32(0x852978, 8) != 0 && sub_478030() == 0 && sub_47A260() == 0 && (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 120)))&2) == 2 {
		return 1
	}
	if p2 != 5 {
		if p2 <= 5 || p2 > 7 {
			return 0
		}
		return 1
	}
	if *a1 == 1310 {
		if dword_5d4594_1046872 != 0 {
			dword_5d4594_1046868 = 0
			dword_5d4594_1046872 = 0
			if nox_xxx_guiSpellSortList_45ADF0(int32(*(*uint8)(unsafe.Add(dword_5d4594_1047516, 2251)))) == 0 {
				dword_5d4594_1046868 = 1
				dword_5d4594_1046872 = 1
				nox_xxx_guiSpellSortList_45ADF0(int32(*(*uint8)(unsafe.Add(dword_5d4594_1047516, 2251))))
				nox_xxx_clientPlaySoundSpecial_452D80(925, 100)
				return 1
			}
			v2 = 1
		}
		if !(nox_xxx_aNox_cfg_0_587000_132132 == 0 || dword_5d4594_1046936 != 0 || v2 == 1) {
			return 1
		}
		nox_xxx_aNox_cfg_0_587000_132132 = 1
		dword_5d4594_1046936 = 0
		nox_xxx_clientPlaySoundSpecial_452D80(788, 100)
		dword_5d4594_1046868 = 3
		dword_5d4594_1046928.Field24ptr().Field_3 = uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq())
		dword_5d4594_1046928.Field24ptr().OnEnd.Set(nox_xxx_bookClickSpell_45B1F0)
		nox_window_set_hidden(dword_5d4594_1046952, 1)
		nox_window_set_hidden(dword_5d4594_1046948, 0)
		nox_xxx_wndClearCaptureMain_46ADE0(nox_win_unk1)
		nox_xxx_bookSpellDnDclear_477660()
		return 1
	}
	if *a1 != 1320 {
		return 1
	}
	if dword_5d4594_1046872 != 1 {
		dword_5d4594_1046868 = 1
		dword_5d4594_1046872 = 1
		if nox_xxx_guiSpellSortList_45ADF0(int32(*(*uint8)(unsafe.Add(dword_5d4594_1047516, 2251)))) == 0 {
			dword_5d4594_1046868 = 0
			dword_5d4594_1046872 = 0
			nox_xxx_guiSpellSortList_45ADF0(int32(*(*uint8)(unsafe.Add(dword_5d4594_1047516, 2251))))
			nox_xxx_clientPlaySoundSpecial_452D80(925, 100)
			return 1
		}
		v2 = 1
	}
	if nox_xxx_aNox_cfg_0_587000_132132 != 0 && dword_5d4594_1046936 == 0 && v2 != 1 {
		return 1
	}
	nox_xxx_aNox_cfg_0_587000_132132 = 1
	dword_5d4594_1046936 = 0
	nox_xxx_clientPlaySoundSpecial_452D80(788, 100)
	if v2 == 1 {
		dword_5d4594_1046868 = 2
		dword_5d4594_1046924.Field24ptr().Field_3 = uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq())
		dword_5d4594_1046924.Field24ptr().OnEnd.Set(nox_xxx_bookClickCreature_45B200)
	} else {
		dword_5d4594_1046868 = 3
		dword_5d4594_1046928.Field24ptr().Field_3 = uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq())
		dword_5d4594_1046928.Field24ptr().OnEnd.Set(nox_xxx_bookClickCreature_45B200)
	}
	nox_window_set_hidden(dword_5d4594_1046952, 1)
	nox_window_set_hidden(dword_5d4594_1046948, 0)
	nox_xxx_wndClearCaptureMain_46ADE0(nox_win_unk1)
	nox_xxx_bookSpellDnDclear_477660()
	return 1
}
func nox_xxx_bookListWndProc_45B5F0(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	var (
		a3  = uint32(p3)
		v3  int32
		v4  int32
		v5  int32
		v7  bool
		v8  int32
		v9  int32
		v10 int32
		v11 int8
		v12 int32
		v13 int32
		v14 int32
	)
	v3 = int32(a3 >> 16)
	v4 = int32(uint16(a3))
	if dword_5d4594_1047520 == 1 || *memmap.PtrUint32(0x852978, 8) != 0 && sub_478030() == 0 && sub_47A260() == 0 && (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 120)))&2) == 2 {
		return 1
	}
	if nox_xxx_aNox_cfg_0_587000_132132 == 0 {
		if p2 < 5 {
			return 0
		}
		if p2 <= 8 {
			return 1
		}
		if p2 == 11 {
			nox_client_toggleSpellbook_45AC70()
			return 1
		}
		return 0
	}
	dword_5d4594_1046656 = nox_xxx_guiFontHeightMB_43F320(nil) + 2
	v5 = 141/dword_5d4594_1046656 - 1
	nox_gui_getWindowOffs_46AA20(win, (*uint32)(unsafe.Pointer(&v14)), &a3)
	switch p2 {
	case 5:
		if *memmap.PtrUint32(0x852978, 8) != 0 && (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 120)))&2) == 2 {
			return 1
		}
		dword_5d4594_1047536 = v3
		v7 = int32(0xFFFFFFED-a3+uint32(v3)) < 0
		v8 = int32(0xFFFFFFED - a3 + uint32(v3))
		dword_5d4594_1047532 = v4
		if v7 {
			nox_xxx_aNox_cfg_0_587000_132136 = -1
			return 1
		}
		v9 = v8 / dword_5d4594_1046656
		if v8/dword_5d4594_1046656 >= v5 {
			nox_xxx_aNox_cfg_0_587000_132136 = -1
			return 1
		}
		if v4-v14 > 145 {
			v9 += v5
		}
		nox_xxx_aNox_cfg_0_587000_132136 = (v5*2)*dword_5d4594_1046936 + v9
		nox_xxx_wndSetCaptureMain_46ADC0(win)
		v10 = nox_xxx_aNox_cfg_0_587000_132136
		if nox_xxx_aNox_cfg_0_587000_132136 >= memmap.Int32(0x5D4594, 1047508)-dword_5d4594_1047512 {
			nox_xxx_aNox_cfg_0_587000_132136 = -1
			return 1
		}
		v11 = int8(*(*uint8)(unsafe.Add(dword_5d4594_1047516, 2251)))
		if int32(v11) == 0 && dword_5d4594_1046868 == 0 {
			dword_5d4594_1047528 = memmap.Int32(0x5D4594, uintptr(nox_xxx_aNox_cfg_0_587000_132136)*4+1046960)
			nox_xxx_bookSaveSpellForDragDrop_477640(dword_5d4594_1047528, 1)
			nox_xxx_clientPlaySoundSpecial_452D80(793, 100)
			return 1
		}
		if int32(v11) != 2 || dword_5d4594_1046868 != 1 {
			if dword_5d4594_1046868 != 0 {
				return 1
			}
			dword_5d4594_1047528 = memmap.Int32(0x5D4594, uintptr(nox_xxx_aNox_cfg_0_587000_132136)*4+1046960)
			nox_xxx_bookSaveSpellForDragDrop_477640(dword_5d4594_1047528, 1)
			nox_xxx_clientPlaySoundSpecial_452D80(793, 100)
			return 1
		} else {
			if *(*uint32)(unsafe.Add(dword_5d4594_1047516, 4232)) == 0 {
				if !noxflags.HasGame(0x2000) || noxflags.HasGame(4096) {
					nox_xxx_wndClearCaptureMain_46ADE0(win)
					nox_xxx_bookMoveToPage_45B930(nox_xxx_aNox_cfg_0_587000_132136)
					dword_5d4594_1047528 = 0
					nox_xxx_aNox_cfg_0_587000_132136 = -1
					return 1
				}
				v10 = nox_xxx_aNox_cfg_0_587000_132136
			}
			dword_5d4594_1047528 = memmap.Int32(0x5D4594, uintptr(v10*4)+1046960) + 74
			nox_xxx_bookSaveSpellForDragDrop_477640(dword_5d4594_1047528, 1)
			nox_xxx_clientPlaySoundSpecial_452D80(793, 100)
			return 1
		}
	case 6, 7:
		if nox_xxx_aNox_cfg_0_587000_132136 >= 0 {
			v12 = dword_5d4594_1047532 - v4
			if dword_5d4594_1047532-v4 < 0 {
				v12 = v4 - dword_5d4594_1047532
			}
			if v12 >= 5 {
				nox_xxx_bookSpellDrop_45DCA0(dword_5d4594_1047528, 0, v4, v3, nil)
			} else {
				v13 = dword_5d4594_1047536 - v3
				if dword_5d4594_1047536-v3 < 0 {
					v13 = v3 - dword_5d4594_1047536
				}
				if v13 >= 5 {
					nox_xxx_bookSpellDrop_45DCA0(dword_5d4594_1047528, 0, v4, v3, nil)
				} else {
					nox_xxx_bookMoveToPage_45B930(nox_xxx_aNox_cfg_0_587000_132136)
				}
			}
		}
		if nox_xxx_wndGetCaptureMain_46AE00() != nil {
			nox_xxx_wndClearCaptureMain_46ADE0(win)
		}
		nox_xxx_bookSpellDnDclear_477660()
		return 1
	case 8:
		return 1
	case 0xB:
		nox_client_toggleSpellbook_45AC70()
		return 1
	default:
		return 0
	}
}
func nox_xxx_bookMoveToPage_45B930(a1 int32) {
	nox_xxx_aNox_cfg_0_587000_132132 = 0
	dword_5d4594_1046932 = a1
	dword_5d4594_1046936 = 99
	if dword_5d4594_1046872 != 0 {
		dword_5d4594_1046924.Field24ptr().OnEnd.Set(nox_xxx_bookClickCreature_45B200)
	} else {
		dword_5d4594_1046924.Field24ptr().OnEnd.Set(nox_xxx_bookClickSpell_45B1F0)
	}
	dword_5d4594_1046868 = 2
	dword_5d4594_1046924.Field24ptr().Field_3 = uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq())
	nox_xxx_clientPlaySoundSpecial_452D80(788, 100)
	nox_window_set_hidden(dword_5d4594_1046952, 0)
	nox_window_set_hidden(dword_5d4594_1046944, 0)
	nox_window_set_hidden(dword_5d4594_1046948, 0)
}
func nox_xxx_book_45BD30(win *gui.Window, draw *gui.WindowData) int {
	return 1
}
func nox_xxx_bookInit_45B9D0() int32 {
	dword_5d4594_1047516 = *memmap.PtrPtr(0x8531A0, 2576)
	img := nox_xxx_gLoadImg_42F970(internCStr("ArrowNW"))
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1046888) = img
	if img == nil {
		return 0
	}
	img = nox_xxx_gLoadImg_42F970(internCStr("ArrowN"))
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1046892) = img
	if img == nil {
		return 0
	}
	img = nox_xxx_gLoadImg_42F970(internCStr("ArrowNE"))
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1046896) = img
	if img == nil {
		return 0
	}
	img = nox_xxx_gLoadImg_42F970(internCStr("ArrowW"))
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1046900) = img
	if img == nil {
		return 0
	}
	img = nox_xxx_gLoadImg_42F970(internCStr("ArrowE"))
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1046908) = img
	if img == nil {
		return 0
	}
	img = nox_xxx_gLoadImg_42F970(internCStr("ArrowSW"))
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1046912) = img
	if img == nil {
		return 0
	}
	img = nox_xxx_gLoadImg_42F970(internCStr("ArrowS"))
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1046916) = img
	if img == nil {
		return 0
	}
	img = nox_xxx_gLoadImg_42F970(internCStr("ArrowSE"))
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1046920) = img
	if img == nil {
		return 0
	}
	img = nox_xxx_gLoadImg_42F970(internCStr("BookOfKnowledge"))
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1046856) = img
	if img == nil {
		return 0
	}
	img = nox_xxx_gLoadImg_42F970(internCStr("GuideTabLit"))
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1046660) = img
	if img == nil {
		return 0
	}
	img = nox_xxx_gLoadImg_42F970(internCStr("SpellTabLit"))
	*memmap.PtrPtrT[noxrender.ImageHandle](0x5D4594, 1046644) = img
	if img == nil {
		return 0
	}

	ani := nox_xxx_gLoadAnim_42FA20(internCStr("BookPageForward"))
	dword_5d4594_1046924 = ani
	if ani == nil {
		return 0
	}
	ani.Field24ptr().OnEnd.Set(nox_xxx_bookClickSpell_45B1F0)

	ani = nox_xxx_gLoadAnim_42FA20(internCStr("BookPageBackward"))
	dword_5d4594_1046928 = ani
	if ani == nil {
		return 0
	}
	ani.Field24ptr().OnEnd.Set(nox_xxx_bookClickSpell_45B1F0)

	nox_win_unk1 = nox_window_new(nil, 1196, 5, int(nox_win_height-323), 285, 168, nil)
	nox_window_set_all_funcs(nox_win_unk1, nox_xxx_bookListWndProc_45B5F0, nox_xxx_bookDrawList_45BD40, nil)
	nox_window_set_hidden(nox_win_unk1, 1)
	r1 := nox_window_new(nox_win_unk1, 8, 257, 15, 27, 40, nil)
	if r1 == nil {
		return 0
	}
	nox_window_set_all_funcs(r1, nox_xxx_bookChildWndProcMB_45B360, nox_xxx_book_45BD30, nox_xxx_book_45CF00)
	r1.SetID(1320)

	r2 := nox_window_new(nox_win_unk1, 8, 253, 61, 27, 40, nil)
	if r2 == nil {
		return 0
	}
	nox_window_set_all_funcs(r2, nox_xxx_bookChildWndProcMB_45B360, nox_xxx_book_45BD30, nox_xxx_book_45CF00)
	r2.SetID(1310)
	dword_5d4594_1046944 = nox_window_new(nox_win_unk1, 136, 24, 138, 20, 20, nil)
	nox_window_set_all_funcs(dword_5d4594_1046944, nox_xxx_book_45B210, nil, nil)
	v3 := nox_xxx_gLoadImg_42F970(internCStr("ArrowW"))
	nox_xxx_wndSetIcon_46AE60(dword_5d4594_1046944, v3)
	dword_5d4594_1046948 = nox_window_new(nox_win_unk1, 136, 233, 138, 20, 20, nil)
	nox_window_set_all_funcs(dword_5d4594_1046948, nox_xxx_bookWndProc_45B070, nil, nil)
	v4 := nox_xxx_gLoadImg_42F970(internCStr("ArrowE"))
	nox_xxx_wndSetIcon_46AE60(dword_5d4594_1046948, v4)
	dword_5d4594_1046952 = nox_window_new(nox_win_unk1, 8, 63, 19, 30, 30, nil)
	nox_window_set_all_funcs(dword_5d4594_1046952, nox_xxx_bookWndFn_45CC10, nox_xxx_bookDrawIconFn_45CB30, nil)
	nox_window_set_hidden(dword_5d4594_1046952, 1)
	dword_5d4594_1046956 = nox_window_new(nil, 40, 0, 0, 30, 30, nil)
	nox_window_set_all_funcs(dword_5d4594_1046956, nil, nox_xxx_bookDrawFn_45C7D0, nil)
	nox_window_set_hidden(dword_5d4594_1046956, 1)
	dword_5d4594_1046868 = 0
	dword_5d4594_1046872 = 0
	nox_xxx_aNox_cfg_0_587000_132132 = 1
	dword_5d4594_1046936 = 0
	return 1
}
func nox_xxx_bookDrawIconFn_45CB30(win *gui.Window, draw *gui.WindowData) int {
	var v1 noxrender.ImageHandle
	if dword_5d4594_1046868 != 0 {
		if dword_5d4594_1046868 != 1 || int32(*(*uint8)(unsafe.Add(dword_5d4594_1047516, 2251))) != 2 || *(*uint32)(unsafe.Add(dword_5d4594_1047516, 4232)) == 0 && (!noxflags.HasGame(0x2000) || noxflags.HasGame(4096)) {
			return 1
		}
		v1 = nox_xxx_spellIcon_424A90(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960) + 74))
	} else if int32(*(*uint8)(unsafe.Add(dword_5d4594_1047516, 2251))) != 0 {
		v1 = nox_xxx_spellIcon_424A90(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)))
	} else {
		v1 = nox_xxx_spellGetAbilityIcon_425310(int32(*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)), 0)
	}
	if v1 == nil {
		return 1
	}
	var v5, v4 int32
	nox_client_wndGetPosition_46AA60(win, &v5, &v4)
	nox_client_drawImageAt_47D2C0(v1, v5, v4)
	return 1
}
func nox_xxx_bookWndFn_45CC10(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	var (
		a1 = win.C()
		v4 int32
		v5 int8
		v6 int8
	)
	if *memmap.PtrUint32(0x852978, 8) != 0 && (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 120)))&2) == 2 {
		return 1
	}
	v4 = int32(a3 >> 16)
	if dword_5d4594_1046868 == 1 {
		v5 = int8(*(*uint8)(unsafe.Add(dword_5d4594_1047516, 2251)))
		if int32(v5) == 1 || int32(v5) == 0 || !noxflags.HasGame(0x2000) && !noxflags.HasGame(4096) && *(*uint32)(unsafe.Add(dword_5d4594_1047516, 4232)) == 0 {
			return 0
		}
	}
	switch a2 {
	case 5:
		if nox_xxx_wndGetCaptureMain_46AE00() != nil || dword_5d4594_1047540 != 0 {
			return 1
		}
		v6 = int8(*(*uint8)(unsafe.Add(dword_5d4594_1047516, 2251)))
		if int32(v6) == 0 && dword_5d4594_1046868 == 0 {
			dword_5d4594_1047540 = memmap.Int32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)
			nox_xxx_bookSaveSpellForDragDrop_477640(dword_5d4594_1047540, 1)
			nox_xxx_wndSetCaptureMain_46ADC0((*gui.Window)(a1))
			nox_xxx_clientPlaySoundSpecial_452D80(793, 100)
			return 1
		}
		if int32(v6) == 2 && dword_5d4594_1046868 == 1 {
			dword_5d4594_1047540 = memmap.Int32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960) + 74
			nox_xxx_bookSaveSpellForDragDrop_477640(dword_5d4594_1047540, 1)
			nox_xxx_wndSetCaptureMain_46ADC0((*gui.Window)(a1))
			nox_xxx_clientPlaySoundSpecial_452D80(793, 100)
			return 1
		}
		if dword_5d4594_1046868 != 0 {
			return 1
		}
		dword_5d4594_1047540 = memmap.Int32(0x5D4594, uintptr(dword_5d4594_1046932)*4+1046960)
		if !nox_xxx_spellHasFlags_424A50(dword_5d4594_1047540, 0x15000) {
			nox_xxx_bookSaveSpellForDragDrop_477640(dword_5d4594_1047540, 1)
			nox_xxx_wndSetCaptureMain_46ADC0((*gui.Window)(a1))
			nox_xxx_clientPlaySoundSpecial_452D80(793, 100)
			return 1
		}
		dword_5d4594_1047540 = 0
		return 1
	case 6, 7:
		if dword_5d4594_1047540 == 0 {
			return 1
		}
		if !nox_xxx_wndPointInWnd_46AAB0(win, int32(uint16(a3)), v4) {
			if nox_xxx_guiSpell_460650() != 0 {
				nox_xxx_guiSpellTargetClickSet_45D9D0(dword_5d4594_1047540)
			} else if sub_4611A0() != 0 {
				sub_4611B0()
			} else {
				nox_xxx_bookSpellDrop_45DCA0(dword_5d4594_1047540, 0, int32(uint16(a3)), v4, nil)
			}
			dword_5d4594_1047540 = 0
			nox_xxx_wndClearCaptureMain_46ADE0((*gui.Window)(a1))
			nox_xxx_bookSpellDnDclear_477660()
			return 1
		}
		if int32(*(*uint8)(unsafe.Add(dword_5d4594_1047516, 2251))) != 0 {
			if nox_xxx_guiSpell_460650() != 0 {
				nox_xxx_guiSpellSetCursor_45DF60(0, 0)
				dword_5d4594_1047540 = 0
				nox_xxx_wndClearCaptureMain_46ADE0((*gui.Window)(a1))
				nox_xxx_bookSpellDnDclear_477660()
				return 1
			}
			if !nox_xxx_spellHasFlags_424A50(dword_5d4594_1047540, 0x600) {
				nox_xxx_guiSpellSetCursor_45DF60(dword_5d4594_1047540, 0)
				nox_xxx_bookSpellDnDclear_477660()
				return 1
			}
			if nox_xxx_guiSpellSetCursor_45DF60(dword_5d4594_1047540, 1) != 0 {
				dword_5d4594_1047540 = 0
				nox_xxx_wndClearCaptureMain_46ADE0((*gui.Window)(a1))
				nox_xxx_bookSpellDnDclear_477660()
				return 1
			}
		} else {
			if sub_4611A0() != 0 {
				sub_45DFC0(0)
				dword_5d4594_1047540 = 0
				nox_xxx_wndClearCaptureMain_46ADE0((*gui.Window)(a1))
				nox_xxx_bookSpellDnDclear_477660()
				return 1
			}
			if sub_45DFC0(dword_5d4594_1047540) != 0 {
				dword_5d4594_1047540 = 0
				nox_xxx_wndClearCaptureMain_46ADE0((*gui.Window)(a1))
				nox_xxx_bookSpellDnDclear_477660()
				return 1
			}
		}
		nox_xxx_bookSpellDnDclear_477660()
		return 1
	case 8:
		return 1
	default:
		return 0
	}
}
func sub_45CFC0() int32 {
	return (int32(uint8(int8(^nox_xxx_wndGetFlags_46ADA0(nox_win_unk1)))) >> 4) & 1
}
func nox_xxx_netSpellRewardCli_45CFE0(a1 int32, a2 int32, a3 int32, a4 int32) {
	var (
		v5  int32
		v6  int32
		v7  *int32
		v8  int32
		v9  int32
		v10 *uint8
		v11 int32
	)
	v4 := *memmap.PtrPtr(0x8531A0, 2576)
	if v4 == nil {
		return
	}
	v5 = a1
	if nox_xxx_playerCheckSpellClass_57AEA0(int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))), a1) == 9 {
		return
	}
	*(*uint32)(unsafe.Add(v4, a1*4+3696)) = uint32(a2)
	if nox_xxx_spellHasFlags_424A50(a1, 0x1000) {
		v11 = 0x2000
		goto LABEL_9
	} else if nox_xxx_spellHasFlags_424A50(a1, 0x4000) {
		v11 = 0x8000
		goto LABEL_9
	} else if nox_xxx_spellHasFlags_424A50(a1, 0x10000) {
		v11 = 0x20000
		goto LABEL_9
	} else {
		goto LABEL_A
	}
LABEL_9:
	v6 = 1
	v7 = (*int32)(unsafe.Add(v4, 3700))
	for {
		if nox_xxx_spellHasFlags_424A50(v6, v11) && nox_xxx_spellIsValid_424B50(v6) {
			*v7 = a2
		}
		v6++
		v7 = (*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1))
		if v6 >= 137 {
			break
		}
	}
LABEL_A:
	dword_5d4594_1046868 = 0
	dword_5d4594_1046872 = 0
	nox_xxx_guiSpellSortList_45ADF0(int32(*(*uint8)(unsafe.Add(v4, 2251))))
	if v5 == 34 {
		v8 = 1
		if *(*uint32)(unsafe.Add(v4, 3832)) != 1 || a3 == 0 {
			v8 = 0
		}
		nox_xxx_quickbarAddTrap_460EC0(v8)
	} else if a3 != 0 {
		v9 = 0
		v10 = (*uint8)(memmap.PtrOff(0x5D4594, 1046960))
		for {
			if *(*uint32)(unsafe.Pointer(v10)) == uint32(v5) {
				break
			}
			v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v10), 4))
			v9++
			if int32(uintptr(unsafe.Pointer(v10))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1047508))) {
				break
			}
		}
		if v9 != 137 {
			nox_xxx_bookHideMB_45ACA0(0)
			nox_xxx_bookMoveToPage_45B930(v9)
			nox_xxx_book_45B010(0)
			nox_xxx_bookRewardCli_499CF0(2, v5, a4)
		}
	}
}
func nox_xxx_netGuideRewardCli_45D140(a1 int32, a2 int32) {
	var (
		v3 *uint8
		v4 *uint32
		v5 int32
		v6 *int32
		v7 int32
		v8 int32
		v9 *uint8
	)
	v2 := *memmap.PtrPtr(0x8531A0, 2576)
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
		v3 = (*uint8)(memmap.PtrOff(0x587000, 132124))
		*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x8531A0, 2576)+uint32(a1*4))), 4244)) = 1
		if *memmap.PtrUint32(0x587000, 132124) != 0 {
			for {
				v4 = *(**uint32)(unsafe.Pointer(v3))
				if uint32(a1) == **(**uint32)(unsafe.Pointer(v3)) {
					v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))
					v6 = (*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
					if v5 != 0 {
						for {
							v6 = (*int32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
							*(*uint32)(unsafe.Add(v2, v5*4+4244)) = 1
							v5 = *v6
							if *v6 == 0 {
								break
							}
						}
					}
				}
				v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)))
				v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
				if v7 == 0 {
					break
				}
			}
		}
		dword_5d4594_1046868 = 1
		dword_5d4594_1046872 = 1
		nox_xxx_guiSpellSortList_45ADF0(int32(*(*uint8)(unsafe.Add(v2, 2251))))
		if a2 != 0 {
			v8 = 0
			v9 = (*uint8)(memmap.PtrOff(0x5D4594, 1046960))
			for {
				if *(*uint32)(unsafe.Pointer(v9)) == uint32(a1) {
					break
				}
				v9 = (*uint8)(unsafe.Add(unsafe.Pointer(v9), 4))
				v8++
				if int32(uintptr(unsafe.Pointer(v9))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1047124))) {
					break
				}
			}
			if v8 != 41 {
				nox_xxx_bookHideMB_45ACA0(0)
				nox_xxx_bookMoveToPage_45B930(v8)
				nox_xxx_book_45B010(0)
				nox_xxx_bookRewardCli_499CF0(4, a1, 0)
			}
		}
	}
}
func nox_xxx_bookSetForward_45D200(a1 uint32, a2 int32, a3 *Point32) {
	nox_xxx_bookShowMB_45AD70(1)
	nox_window_setPos_46A9B0(nox_win_unk1, a3.X, a3.Y)
	if a1 == 2 || a1 == 4 {
		v5 := int32(0)
		result := mem_getI32Ptr(0x5D4594, 1046960)
		for {
			if *result == a2 {
				break
			}
			result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
			v5++
			if int32(uintptr(unsafe.Pointer(result))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1047508))) {
				break
			}
		}
		if v5 != 137 {
			nox_xxx_bookMoveToPage_45B930(v5)
		}
	} else if a1 == 3 {
		v4 := int32(0)
		result := mem_getI32Ptr(0x5D4594, 1046960)
		for {
			if *result == a2 {
				break
			}
			result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
			v4++
			if int32(uintptr(unsafe.Pointer(result))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1046984))) {
				break
			}
		}
		if v4 != 6 {
			nox_xxx_bookMoveToPage_45B930(v4)
		}
	}
}
func nox_xxx_abilityReward_45D290(a1 int32, a2 *byte, a3 int32) {
	pl := (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(nox_player_netCode_85319C))))
	if pl != nil {
		dword_5d4594_1046868 = 0
		dword_5d4594_1046872 = 0
		nox_xxx_guiSpellSortList_45ADF0(int32(*(*byte)(unsafe.Add(unsafe.Pointer(pl), 2251))))
		if a2 != nil {
			v4 := int32(0)
			r3 := (*byte)(memmap.PtrOff(0x5D4594, 1046960))
			for {
				if *(*uint32)(unsafe.Pointer(r3)) == uint32(a1) {
					break
				}
				r3 = (*byte)(unsafe.Add(unsafe.Pointer(r3), 4))
				v4++
				if int32(uintptr(unsafe.Pointer(r3))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1046984))) {
					break
				}
			}
			if v4 != 6 {
				nox_xxx_bookHideMB_45ACA0(0)
				nox_xxx_bookMoveToPage_45B930(v4)
				nox_xxx_book_45B010(0)
				if a3 != 0 {
					nox_xxx_bookRewardCli_499CF0(3, a1, a3)
				}
			}
		}
	}
}
func sub_45D320(a1 int32) {
	var (
		v3 int32
		v4 int32
		v5 *uint32
	)
	v1 := *memmap.PtrPtr(0x8531A0, 2576)
	nox_xxx_bookHideMB_45ACA0(1)
	if v1 == nil {
		return
	}
	*(*uint32)(unsafe.Add(v1, a1*4+3696)) = 0
	sub_461360(a1)
	if nox_xxx_spellHasFlags_424A50(a1, 0x1000) {
		v3 = 0x2000
	} else if nox_xxx_spellHasFlags_424A50(a1, 0x4000) {
		v3 = 0x8000
	} else {
		if !nox_xxx_spellHasFlags_424A50(a1, 0x10000) {
			nox_xxx_guiSpellSortList_45ADF0(int32(*(*uint8)(unsafe.Add(v1, 2251))))
			return
		}
		v3 = 0x20000
	}
	v4 = 1
	v5 = (*uint32)(unsafe.Add(v1, 3700))
	for {
		if nox_xxx_spellHasFlags_424A50(v4, v3) {
			if nox_xxx_spellIsValid_424B50(v4) {
				*v5 = 0
				sub_461360(v4)
			}
		}
		v4++
		v5 = (*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
		if v4 >= 137 {
			break
		}
	}
	nox_xxx_guiSpellSortList_45ADF0(int32(*(*uint8)(unsafe.Add(v1, 2251))))
}
func sub_45D400(a1 int32) {
	var (
		v3 *uint8
		v4 *uint32
		v5 int32
		i  *uint32
		v7 int32
	)
	v1 := *memmap.PtrPtr(0x8531A0, 2576)
	nox_xxx_bookHideMB_45ACA0(1)
	if v1 != nil {
		*(*uint32)(unsafe.Add(v1, a1*4+4244)) = 0
		sub_461360(a1 + 74)
		v3 = (*uint8)(memmap.PtrOff(0x587000, 132124))
		if *memmap.PtrUint32(0x587000, 132124) != 0 {
			for {
				v4 = *(**uint32)(unsafe.Pointer(v3))
				if uint32(a1) == **(**uint32)(unsafe.Pointer(v3)) {
					v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))
					for i = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)); v5 != 0; i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) {
						*(*uint32)(unsafe.Add(v1, v5*4+4244)) = 0
						sub_461360(int32(*i + 74))
						v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)))
					}
				}
				v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)))
				v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 4))
				if v7 == 0 {
					break
				}
			}
		}
		nox_xxx_guiSpellSortList_45ADF0(int32(*(*uint8)(unsafe.Add(v1, 2251))))
	}
}
func nox_xxx_clientQuestDisableAbility_45D4A0(a1 int32) {
	nox_xxx_bookHideMB_45ACA0(1)
	nox_xxx_netAbilityRewardCli_4611E0(a1, 0, nil)
	if dword_5d4594_1047516 != nil {
		*(*uint32)(unsafe.Add(dword_5d4594_1047516, a1*4+3696)) = 0
	}
	sub_461360(a1)
	result := (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(nox_player_netCode_85319C))))
	if result != nil {
		nox_xxx_guiSpellSortList_45ADF0(int32(*(*byte)(unsafe.Add(unsafe.Pointer(result), 2251))))
	}
}
func sub_45D500(a1 int32) int32 {
	var result int32
	result = int32(dword_5d4594_1046864)
	if a1 != 0 {
		if dword_5d4594_1046864 != 0 {
			result = nox_window_set_hidden(nox_win_unk1, 0)
		}
	} else if dword_5d4594_1046864 != 0 {
		result = sub_47A260()
		if result == 0 {
			result = nox_window_set_hidden(nox_win_unk1, 1)
		}
	}
	return result
}
func sub_45D550(a1p *Point32) {
	if a1p != nil {
		nox_client_wndGetPosition_46AA60(dword_5d4594_1046952, &a1p.X, &a1p.Y)
	}
}
func nox_xxx_bookFillAll_45D570(a1 uint32, a2 int32) {
	var (
		v3 float64
		a4 Point32
		a3 Point32
	)
	if dword_5d4594_1047520 == 1 {
		return
	}
	nox_xxx_quickBarClose_4606B0()
	*memmap.PtrUint32(0x5D4594, 1046612) = uint32(nox_xxx_buttonsGetSelectedRow_45E180())
	if a1 != 2 || !nox_xxx_spellHasFlags_424A50(a2, 0x15000) {
		if nox_xxx_buttonHaveSpellInBarMB_4612D0(a2) != 1 {
			if a1 == 2 || a1 == 4 {
				dword_5d4594_1046852 = nox_xxx_buttonFindFirstEmptySlot_461250()
			} else {
				if a1 != 3 {
					return
				}
				dword_5d4594_1046852 = sub_4612A0()
			}
			if dword_5d4594_1046852 != -1 {
				dword_5d4594_1047520 = 1
				if a1 == 2 || a1 == 3 {
					dword_5d4594_1046868 = 0
					dword_5d4594_1046872 = 0
				} else {
					dword_5d4594_1046868 = 1
					dword_5d4594_1046872 = 1
				}
				sub_45D550((*Point32)(memmap.PtrOff(0x5D4594, 1046844)))
				dword_5d4594_1046636 = *memmap.PtrInt32(0x5D4594, 1046844)
				dword_5d4594_1046640 = *memmap.PtrInt32(0x5D4594, 1046848)
				nox_window_setPos_46A9B0(dword_5d4594_1046956, *memmap.PtrInt32(0x5D4594, 1046844), *memmap.PtrInt32(0x5D4594, 1046848))
				nox_xxx_buttonSetImgMB_461320(dword_5d4594_1046852, (*Point32)(memmap.PtrOff(0x5D4594, 1046668)))
				a3.X = 400
				a4.Y = 400
				dword_5d4594_1047524 = uint32(a2)
				dword_5d4594_1046652 = uint32(bool2int32(a1 == 3))
				*memmap.PtrUint32(0x5D4594, 1046676) = a1
				nox_client_setRenderGUI(1)
				a3.Y = -500
				a4.X = 350
				*memmap.PtrUint32(0x5D4594, 1046680) = 0
				sub_4BEDE0((*Point32)(memmap.PtrOff(0x5D4594, 1046844)), (*Point32)(memmap.PtrOff(0x5D4594, 1046668)), &a3, &a4, 19, 0.0, sub_45D7D0, nil)
				*memmap.PtrUint32(0x5D4594, 1046628) = 0
				obj_5d4594_1046620.X = *mem_getFloatPtr(0x5D4594, 1046692) - *mem_getFloatPtr(0x5D4594, 1046684)
				obj_5d4594_1046620.Y = *mem_getFloatPtr(0x5D4594, 1046696) - *mem_getFloatPtr(0x5D4594, 1046688)
				nox_xxx_utilNormalizeVector_509F20(&obj_5d4594_1046620)
				if nox_win_width < 1000 {
					if nox_win_width < 750 {
						v3 = 6.0
					} else {
						v3 = 8.0
					}
				} else {
					v3 = 10.0
				}
				obj_5d4594_1046620.X = float32(float64(obj_5d4594_1046620.X) * v3)
				obj_5d4594_1046620.Y = float32(float64(obj_5d4594_1046620.Y) * v3)
				nox_window_set_hidden(dword_5d4594_1046956, 0)
				nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1046956)
				if noxflags.HasGame(2048) {
					sub_57AF30(nil, a1)
				}
				dword_5d4594_1046648 = uint32(nox_xxx_bookGet_430B40_get_mouse_prev_seq())
				if !noxflags.HasGame(2048) || nox_gui_xxx_check_446360() == 1 || nox_xxx_gameGet_4DB1B0() == 1 {
					sub_45D870()
				}
			}
		}
	}
}
func sub_45D7D0(a1p, a2p *Point32, _ unsafe.Pointer) {
	a1 := (*int32)(unsafe.Pointer(a1p))
	a2 := (*int32)(unsafe.Pointer(a2p))
	var (
		result int32
		v3     float64
	)
	result = int32(*memmap.PtrUint32(0x5D4594, 1046680))
	if *memmap.PtrInt32(0x5D4594, 1046680) < 20 {
		result = int32(*memmap.PtrUint32(0x5D4594, 1046680) + 1)
		*mem_getFloatPtr(0x5D4594, uint32(result*8)+1046676) = float32(float64(*a1))
		*mem_getFloatPtr(0x5D4594, uint32(result*8)+1046680) = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))))
		*mem_getFloatPtr(0x5D4594, uint32(result*8)+1046684) = float32(float64(*a2))
		v3 = float64(*(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*1)))
		*memmap.PtrUint32(0x5D4594, 1046680) = uint32(result)
		*mem_getFloatPtr(0x5D4594, uint32(result*8)+1046688) = float32(v3)
	}
}
func sub_45D810() {
	if dword_5d4594_1047520 != 0 {
		dword_5d4594_1047520 = 0
		nox_window_set_hidden(dword_5d4594_1046956, 1)
		dword_5d4594_1046648 = 0
		nox_xxx_clientUpdateButtonRow_45E110(*memmap.PtrInt32(0x5D4594, 1046612))
		if noxflags.HasGame(2048) {
			sub_57B0A0()
			sub_413A00(0)
		}
	}
}
func sub_45D9B0() int32 {
	return int32(dword_5d4594_1047520)
}
func nox_xxx_guiSpellTargetClickSet_45D9D0(a1 int32) int32 {
	if *memmap.PtrUint32(0x5D4594, 1047916) != 0 {
		return 0
	}
	*memmap.PtrUint32(0x5D4594, 1047916) = uint32(a1)
	*memmap.PtrUint8(0x5D4594, 1047920) = 0
	nox_xxx_setKeybTimeout_4160D0(5)
	*memmap.PtrUint32(0x5D4594, 1047928) = 0
	*memmap.PtrUint32(0x5D4594, 1047924) = 0
	return 1
}
func nox_xxx_guiSpell_45DA10(a1 int32) int32 {
	var result int32
	if *memmap.PtrUint32(0x5D4594, 1047916) != 0 {
		return 0
	}
	*memmap.PtrUint32(0x5D4594, 1047916) = uint32(a1)
	*memmap.PtrUint8(0x5D4594, 1047920) = 0
	nox_xxx_setKeybTimeout_4160D0(5)
	result = 1
	*memmap.PtrUint32(0x5D4594, 1047924) = 1
	return result
}
func nox_client_invokeSpellSlot_45DA50(a1 int32) {
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
		if nox_xxx_playerAnimCheck_4372B0() == 0 {
			if int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))) != 0 {
				nox_xxx_clientSendSpell_45DB20((*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 204))+uint32(a1*8)))), 1, int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 204))+uint32(a1*8))), 4)))&1))
				nox_xxx_clientStoreLastButton_45DAD0(a1)
			} else {
				nox_xxx_clientSendAbil_45DAF0(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 204)) + uint32(a1*8))))))
				nox_xxx_clientStoreLastButton_45DAD0(a1)
			}
		}
	}
}
func nox_xxx_clientStoreLastButton_45DAD0(a1 int32) {
	*memmap.PtrUint32(0x587000, 133484) = uint32(a1)
	*memmap.PtrUint32(0x5D4594, 1049540) = gameFrame()
}
func nox_xxx_clientSendAbil_45DAF0(a1 int32) {
	if nox_xxx_guiCursor_477600() == 0 {
		if a1 != 0 {
			var buf [2]byte
			buf[0] = 122
			buf[1] = uint8(int8(a1))
			nox_netlist_addToMsgListCli_40EBC0(31, 0, &buf[0], 2)
		}
	}
}
func nox_xxx_clientSendSpell_45DB20(a1 *byte, a2 int32, a3 int8) int32 {
	var (
		result int32
		v4     int32
		v5     *byte
		v6     [22]byte
	)
	result = nox_xxx_guiCursor_477600()
	if !(result == 0 && *(*uint32)(unsafe.Pointer(a1)) != 0) {
		return result
	}
	v4 = 0
	v6[0] = 121
	v5 = &v6[1]
	for {
		if v4 >= a2 {
			*(*uint32)(unsafe.Pointer(v5)) = 0
		} else {
			*(*uint32)(unsafe.Pointer(v5)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v5), int32(uintptr(unsafe.Pointer(a1))-uintptr(unsafe.Pointer(&v6[1])))))
		}
		v4++
		v5 = (*byte)(unsafe.Add(unsafe.Pointer(v5), 4))
		if v4 >= 5 {
			break
		}
	}
	v6[21] = byte(a3)
	result = nox_netlist_addToMsgListCli_40EBC0(31, 0, &v6[0], 22)
	return result
}
func sub_45DB90() int32 {
	var result int32
	result = 0
	libc.MemSet(memmap.PtrOff(0x5D4594, 1049544), 0, 0x88)
	*memmap.PtrUint8(0x5D4594, 1049680) = 0
	return result
}
func nox_xxx_guiSpellTargetClickCheckSend_45DBB0() {
	if *memmap.PtrUint32(0x5D4594, 1047916) != 0 {
		nox_xxx_clientSendSpell_45DB20((*byte)(memmap.PtrOff(0x5D4594, 1047916)), 1, int8(*memmap.PtrUint8(0x5D4594, 1047924)))
		*memmap.PtrUint32(0x5D4594, 1047916) = 0
	}
}
func nox_xxx_book_45DBE0(a1 uint32, a2 int32, a3 int32) {
	nox_xxx_spellKeyPackSetSpell_45DC40(nox_xxx_aClosewoodengat_587000_133480, a2, a3)
	if a1 == 2 {
		if a2 != 0 && nox_xxx_spellHasFlags_424A50(a2, 0x600) {
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 204))+uint32(a3*8))), 4)) = 1
		} else {
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 204))+uint32(a3*8))), 4)) = 0
		}
	}
}
func nox_xxx_spellKeyPackSetSpell_45DC40(a1 unsafe.Pointer, a2 int32, a3 int32) {
	var v3 *wchar2_t
	*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(a1, 204)) + uint32(a3*8)))) = uint32(a2)
	if *(*uint32)(unsafe.Add(a1, a3*4+212)) != 0 {
		v3 = nox_xxx_spellTitle_424930(a2)
		nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, a3*4+212)), 36)), v3)
	}
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
		nox_xxx_clientPlaySoundSpecial_452D80(794, 100)
	}
}
func nox_xxx_bookSpellDrop_45DCA0(a1 int32, a2 int8, a3 int32, a4 int32, a5 unsafe.Pointer) int32 {
	var (
		v5  uint16
		v6  int32
		v7  *int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v13 uint16
		v14 uint16
	)
	v5 = 0
	v14 = 137
	v13 = 0
	if !((wndIsShown_nox_xxx_wndIsShown_46ACC0((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1048148))) != 0 || nox_xxx_spellPutInBox_45DEB0(mem_getI32Ptr(0x5D4594, 1047940), a1, a3, a4) == 0) && a5 != memmap.PtrOff(0x5D4594, 1047940)) {
		return int32(v5) | int32(v14)<<16
	}
	if *memmap.PtrUint32(0x5D4594, 1049476) != 0 {
		v6 = 0
	} else {
		v6 = 4
	}
	v7 = mem_getI32Ptr(0x5D4594, uint32(v6*256)+1048196)
	for {
		v8 = nox_xxx_spellBoxPointToWnd_45DE60(unsafe.Pointer(v7), a3, a4)
		v9 = v8
		if v8 >= 0 {
			v10 = *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*51))
			v14 = *(*uint16)(unsafe.Pointer(uintptr(v10 + v8*8)))
			v13 = uint16(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v10+v8*8)), 4)))
		}
		if nox_xxx_spellPutInBox_45DEB0(v7, a1, a3, a4) != 0 {
			break
		}
		v7 = (*int32)(unsafe.Add(unsafe.Pointer(v7), 4*64))
		v6++
		if int32(uintptr(unsafe.Pointer(v7))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1049476))) {
			goto LABEL_16
		}
	}
	if nox_xxx_bookGetSpellDnDType_477670() == 1 {
		v11 = v6 << 8
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v11)+1048400)+uint32(v9*8))), 4)) = uint8(int8(bool2int32(nox_xxx_spellHasFlags_424A50(a1, 0x600))))
	} else {
		v11 = v6 << 8
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x5D4594, uintptr(v11)+1048400)+uint32(v9*8))), 4)) = uint8(a2)
	}
	nox_xxx_updateSpellIcons_45DDF0(memmap.PtrOff(0x5D4594, uintptr(v11)+1048196))
LABEL_16:
	v5 = v13
	return int32(v5) | int32(v14)<<16
}
func nox_xxx_updateSpellIcons_45DDF0(a1 unsafe.Pointer) {
	for i := 0; i < 5; i++ {
		nox_xxx_updateSpellIconDir_45DE10(int32(i), a1)
	}
}
func nox_xxx_updateSpellIconDir_45DE10(a1 int32, a2 unsafe.Pointer) {
	var (
		v2 int32
		v3 int8
		v4 *uint32
	)
	v2 = int32(*(*uint32)(unsafe.Add(a2, 204)))
	v3 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2+a1*8)), 4)))
	v4 = (*uint32)(unsafe.Pointer(uintptr(v2 + a1*8)))
	if int32(v3)&1 != 0 && *v4 != 0 {
		sub_46AE10(*(*unsafe.Pointer)(unsafe.Add(a2, a1*4+232)), 1)
	} else {
		sub_46AE10(*(*unsafe.Pointer)(unsafe.Add(a2, a1*4+232)), 0)
	}
}
func nox_xxx_spellBoxPointToWnd_45DE60(a1 unsafe.Pointer, a2 int32, a3 int32) int32 {
	var (
		v3 int32
	)
	v3 = 0
	for i := unsafe.Add(a1, 212); !nox_xxx_wndPointInWnd_46AAB0(*(**gui.Window)(i), a2, a3); i = unsafe.Add(i, unsafe.Sizeof((*uint32)(nil))*1) {
		if func() int32 {
			p := &v3
			*p++
			return *p
		}() >= 5 {
			return -1
		}
	}
	return v3
}
func nox_xxx_guiSpellSetCursor_45DF60(a1 int32, a2 int8) int32 {
	var result int32
	if a1 != 0 {
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
		if (int32(a2)&1) == 0 || nox_xxx_spellHasFlags_424A50(a1, 0x2000) {
			*memmap.PtrUint32(0x5D4594, 1047556) = uint32(a1)
			*memmap.PtrUint32(0x5D4594, 1047928) = 1
			result = 0
		} else {
			nox_xxx_guiSpell_45DA10(a1)
			result = 1
		}
	} else {
		*memmap.PtrUint32(0x5D4594, 1047928) = 0
		result = 0
	}
	return result
}
func sub_45DFC0(a1 int32) int32 {
	if a1 != 0 {
		v2 := int32(*memmap.PtrUint32(0x5D4594, uintptr(a1*24)+1047764+4))
		if v2 != 0 {
			dword_5d4594_1047932 = 0
			dword_5d4594_1047936 = 0
			nox_xxx_clientSendAbil_45DAF0(a1)
			nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
			return v2
		} else {
			v3 := memmap.Int32(0x5D4594, uintptr(a1*24)+1047764)
			dword_5d4594_1047932 = 1
			dword_5d4594_1047936 = v3
			nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
			return 0
		}
	} else {
		dword_5d4594_1047932 = 0
		dword_5d4594_1047936 = 0
		return 0
	}
}
func nox_xxx_clientUpdateButtonRow_45E110(a1 int32) {
	if a1 >= 0 && a1 < 5 && *memmap.PtrUint32(0x5D4594, 1049476) == 0 && dword_5d4594_1049496 == 0 {
		*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)) = uint8(int8(a1))
		*(*uint32)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 204)) = uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) + uint32(int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)))*40)
		if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
			nox_xxx_clientPlaySoundSpecial_452D80(798, 100)
		}
		nox_xxx_updateSpellIcons_45DDF0(nox_xxx_aClosewoodengat_587000_133480)
	}
}
func nox_xxx_buttonsGetSelectedRow_45E180() int32 {
	return int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)))
}
func nox_xxx_quickbarButtonBookDraw_45EF30(win *gui.Window, draw *gui.WindowData) int {
	return 1
}
func sub_45EF40(win *gui.Window, p2, p3, p4 uintptr) uintptr {
	return 0
}
func nox_xxx_quickBarWnd_45EF50(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	var (
		v4  int32
		v5  unsafe.Pointer
		v7  uint16
		v8  int32
		v9  *uint32
		v10 int32
		v11 unsafe.Pointer
		v12 uint32
		v13 int32
		v14 Point32
		v15 int32
	)
	v3 := unsafe.Pointer(win.Field92Val)
	if !(*memmap.PtrUint32(0x852978, 8) == 0 || (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 120)))&2) != 2) {
		return 1
	}
	v4 = 0
	v5 = unsafe.Add(v3, 4*53)
	for {
		if win == *(**gui.Window)(v5) {
			break
		}
		v4++
		v5 = unsafe.Add(v5, 4*1)
		if v4 >= 5 {
			break
		}
	}
	if v4 == 5 {
		return 0
	}
	v7 = uint16(a3)
	v8 = v4 * 8
	v15 = int32(a3 >> 16)
	v9 = (*uint32)(unsafe.Pointer(uintptr(v4*8 + *(*int32)(unsafe.Add(v3, 4*51)))))
	v14.X = v4*8 + *(*int32)(unsafe.Add(v3, 4*51))
	switch a2 {
	case 5:
		if *v9 == 0 || *memmap.PtrUint32(0x5D4594, 1047928) != 0 || dword_5d4594_1047932 != 0 || nox_xxx_get_57AF20() != 0 || int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))) != 0 && !nox_xxx_spellIsEnabled_424B70(int32(*(*uint32)(unsafe.Pointer(uintptr(v14.X))))) {
			return 1
		}
		nox_xxx_wndSetCaptureMain_46ADC0(win)
		nox_xxx_bookSaveSpellForDragDrop_477640(int32(*(*uint32)(unsafe.Pointer(uintptr(v14.X)))), 2)
		dword_5d4594_1049692 = v3
		dword_5d4594_1049696 = *(*unsafe.Pointer)(unsafe.Add(v3, 4*51))
		nox_xxx_clientPlaySoundSpecial_452D80(793, 100)
		return 1
	case 6, 7:
		if nox_xxx_wndGetCaptureMain_46AE00() == nil {
			return 1
		}
		if nox_xxx_get_57AF20() != 0 {
			goto LABEL_51
		}
		v10 = nox_xxx_spellBoxPointToWnd_45DE60(v3, int32(v7), v15)
		if dword_5d4594_1047932 != 0 {
			if v10 < 0 {
				sub_4611B0()
			}
			dword_5d4594_1047932 = 0
			goto LABEL_51
		}
		if *memmap.PtrUint32(0x5D4594, 1047928) != 0 {
			if v10 < 0 {
				nox_xxx_guiSpellTargetClickSet_45D9D0(*memmap.PtrInt32(0x5D4594, 1047556))
			}
			*memmap.PtrUint32(0x5D4594, 1047928) = 0
			if dword_5d4594_1047932 == 0 {
				nox_xxx_wndClearCaptureMain_46ADE0(win)
				dword_5d4594_1049532 = nil
			}
			nox_xxx_bookSpellDnDclear_477660()
			return 1
		}
		if v10 < 0 {
			v12 = uint32(nox_xxx_bookSpellDrop_45DCA0(int32(*(*uint32)(unsafe.Pointer(uintptr(v8 + *(*int32)(unsafe.Add(v3, 4*51)))))), int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v8+*(*int32)(unsafe.Add(v3, 4*51)))), 4))), int32(v7), v15, v3))
			if v12>>16 == 137 {
				v14.X = int32(v7)
				v14.Y = v15
				v13 = nox_xxx_pointInRect_4281F0(&v14, (*int4)(memmap.PtrOff(0x587000, 133656)))
				if v13 != 0 || dword_5d4594_1049696 != nil && dword_5d4594_1049696 != *(*unsafe.Pointer)(unsafe.Add(v3, 4*51)) {
					goto LABEL_51
				}
				*(*uint32)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(v3, 4*51)) + v4*8))) = 0
				*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(v3, 4*51))+v8)), 4)) = 0
				if unsafe.Pointer(v3) == memmap.PtrOff(0x5D4594, 1047940) {
					goto LABEL_51
				}
			} else {
				*(*uint32)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(v3, 4*51)) + v4*8))) = v12 >> 16
				*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(v3, 4*51))+v8)), 4)) = uint8(v12)
				if unsafe.Pointer(v3) == memmap.PtrOff(0x5D4594, 1047940) {
					goto LABEL_51
				}
			}
		} else {
			if dword_5d4594_1049692 != nil {
				if dword_5d4594_1049692 == unsafe.Pointer(v3) && dword_5d4594_1049692 == nox_xxx_aClosewoodengat_587000_133480 {
					if dword_5d4594_1049696 != nil {
						v11 = *(*unsafe.Pointer)(unsafe.Add(v3, 4*51))
						if dword_5d4594_1049696 != v11 {
							sub_45F390(dword_5d4594_1049696, v11, v4, v10)
							nox_xxx_clientPlaySoundSpecial_452D80(794, 100)
							nox_xxx_updateSpellIcons_45DDF0(v3)
							goto LABEL_51
						}
					}
				}
			}
			if v10 == v4 {
				dword_5d4594_1049532 = win
				if *memmap.PtrUint32(0x8531A0, 2576) == 0 || unsafe.Pointer(v3) == memmap.PtrOff(0x5D4594, 1047940) {
					nox_xxx_wndClearCaptureMain_46ADE0(win)
					dword_5d4594_1049532 = nil
					nox_xxx_bookSpellDnDclear_477660()
					return 1
				}
				if int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))) != 0 {
					if nox_xxx_spellIsEnabled_424B70(int32(*(*uint32)(unsafe.Pointer(uintptr(v14.X))))) {
						nox_xxx_guiSpellSetCursor_45DF60(int32(*(*uint32)(unsafe.Pointer(uintptr(v14.X)))), int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v14.X)), 4))))
						nox_xxx_clientStoreLastButton_45DAD0(v4)
					}
				} else {
					sub_45DFC0(int32(*(*uint32)(unsafe.Pointer(uintptr(v14.X)))))
					nox_xxx_clientStoreLastButton_45DAD0(v4)
				}
				goto LABEL_51
			}
			nox_xxx_clientSwapQuickbarKeys_45F300(v3, v4, v10)
			nox_xxx_clientPlaySoundSpecial_452D80(794, 100)
			if unsafe.Pointer(v3) == memmap.PtrOff(0x5D4594, 1047940) {
				goto LABEL_51
			}
		}
		nox_xxx_updateSpellIcons_45DDF0(v3)
	LABEL_51:
		if *memmap.PtrUint32(0x5D4594, 1047928) == 0 && dword_5d4594_1047932 == 0 {
			nox_xxx_wndClearCaptureMain_46ADE0(win)
			dword_5d4594_1049532 = nil
		}
		nox_xxx_bookSpellDnDclear_477660()
		return 1
	case 8, 12, 16:
		return 0
	default:
		return 1
	}
	return 1
}
func nox_xxx_clientSwapQuickbarKeys_45F300(a1 unsafe.Pointer, a2 int32, a3 int32) {
	var (
		v3 int32
		v4 int32
		v5 int32
		v6 *uint32
		v7 *wchar2_t
		v8 *wchar2_t
	)
	v3 = int32(*(*uint32)(unsafe.Add(a1, 204)))
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + a2*8))))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v3+a2*8)), 4)))
	*(*uint32)(unsafe.Pointer(uintptr(v3 + a2*8))) = *(*uint32)(unsafe.Pointer(uintptr(a3*8 + v3)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v3+a2*8)), 4)) = *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a3*8+v3)), 4))
	v6 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(a1, 204)) + uint32(a3*8))))
	*v6 = uint32(v4)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1)) = uint32(v5)
	v7 = nox_xxx_spellTitle_424930(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(a1, 204)) + uint32(a2*8))))))
	nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, a2*4+212)), 36)), v7)
	v8 = nox_xxx_spellTitle_424930(int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(a3*8) + *(*uint32)(unsafe.Add(a1, 204)))))))
	nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, a3*4+212)), 36)), v8)
}
func sub_45F390(a1 unsafe.Pointer, a2 unsafe.Pointer, a3 int32, a4 int32) {
	v4 := int32(*(*uint32)(unsafe.Add(a2, a4*8)))
	v5 := int32(*(*uint32)(unsafe.Add(a2, a4*8+4)))
	*(*uint32)(unsafe.Add(a2, a4*8)) = *(*uint32)(unsafe.Add(a1, a3*8))
	*(*uint32)(unsafe.Add(a2, a4*8+4)) = *(*uint32)(unsafe.Add(a1, a3*8+4))
	*(*uint32)(unsafe.Add(a1, a3*8)) = uint32(v4)
	*(*uint32)(unsafe.Add(a1, a3*8+4)) = uint32(v5)
	v6 := nox_xxx_spellTitle_424930(int32(*(*uint32)(unsafe.Add(a2, a4*8))))
	nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480))+uint32(a4*4))), 212)), 36)), v6)
}
func nox_xxx_quickbarButtonBookWnd_45F450(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	if a2 < 5 {
		return 0
	}
	if a2 <= 6 {
		return 1
	}
	if a2 == 7 {
		nox_client_toggleSpellbook_45AC70()
		return 1
	}
	return 0
}
func sub_45F500(a1 int32, a2 int32) int32 {
	return int32((*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr(a2+a1*4)), 232)), 36)) >> 1) & 1)
}
func sub_45F520(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	var (
		a1 = win.C()
		v2 int32
		v3 int32
		v6 int32
	)
	v2 = int32(uint16(*(*uint32)(unsafe.Add(a1, 368))>>16)) << 8
	v3 = int32(*(*uint16)(unsafe.Add(a1, 368)))
	v4 := *memmap.PtrPtr(0x5D4594, uintptr(v2)+1048400)
	v5 := unsafe.Add(v4, v3*8)
	v6 = int32(*(*uint32)(v5))
	if v6 == 0 {
		return 0
	}
	if a2 != 5 {
		if a2 > 5 && a2 <= 7 {
			return 1
		}
		return 0
	}
	if nox_xxx_spellHasFlags_424A50(v6, 0x200400) {
		nox_xxx_clientPlaySoundSpecial_452D80(925, 100)
	} else {
		*(*uint8)(unsafe.Add(v5, 4)) ^= 1
		nox_xxx_updateSpellIconDir_45DE10(v3, memmap.PtrOff(0x5D4594, uintptr(v2)+1048196))
		nox_xxx_clientPlaySoundSpecial_452D80(921, 100)
	}
	return 1
}
func sub_45F5D0(win *gui.Window, draw *gui.WindowData) int {
	v1 := int32(win.Field92Val)
	var v4, a1 int32
	nox_client_wndGetPosition_46AA60(win, &v4, &a1)
	v2 := (*int16)(unsafe.Pointer(sub_42E8E0(v1+28, 1)))
	if v2 != nil {
		nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
		nox_xxx_drawString_43F6E0(*memmap.PtrPtr(0x5D4594, 1049684), (*wchar2_t)(unsafe.Pointer(v2)), v4, a1)
	}
	return 1
}
func nox_xxx_quickbarTrapUpDownProc_45F630(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	a1 := win.C()
	var v2 int32
	v2 = int32(*(*uint32)(unsafe.Add(a1, 368)))
	if !((*memmap.PtrUint32(0x852978, 8) == 0 || (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 120)))&2) != 2) && sub_4AE3D0() == 0) {
		return 1
	}
	if a2 == 5 {
		switch v2 {
		case 0:
			dword_5d4594_1049508.DrawData().BgImageHnd = nil
			nox_client_spellSetPrev_460540()
		case 1:
			dword_5d4594_1049508.DrawData().BgImageHnd = nil
			nox_client_spellSetNext_4604F0()
		case 2:
			dword_5d4594_1049508.DrawData().BgImageHnd = nil
			sub_460920()
		case 3:
			nox_client_trapSetPrev_4603F0()
		case 4:
			nox_client_trapSetNext_4603A0()
		default:
		}
		*memmap.PtrUint32(0x5D4594, 1049700) = 2
		*memmap.PtrUint32(0x5D4594, 1049704) = uint32(v2)
	} else if a2 <= 5 || a2 > 7 {
		return 0
	}
	return 1
}
func nox_xxx_quickbarTrapUpDownDraw_45F6F0(win *gui.Window, draw *gui.WindowData) int {
	var (
		v2 int32
		v3 int32
		v4 int32
		v6 int32
	)
	v1 := win.C()
	v2 = int32(win.Field92Val)
	var a1, v8 int32
	nox_client_wndGetPosition_46AA60(win, &a1, &v8)
	v3 = a1 + *(*int32)(unsafe.Add(v1, 4*24))
	v4 = int32(*(*uint32)(unsafe.Add(v1, 4*25)) + uint32(v8))
	a1 = a1 + *(*int32)(unsafe.Add(v1, 4*24))
	v8 = v4
	if *memmap.PtrInt32(0x5D4594, 1049700) <= 0 || *memmap.PtrInt32(0x5D4594, 1049704) != v2 {
		v5 := *(*noxrender.ImageHandle)(unsafe.Add(v1, 4*15))
		if v5 != nil {
			nox_client_drawImageAt_47D2C0(v5, v3, v4)
		}
	} else {
		nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*(*unsafe.Pointer)(unsafe.Add(v1, 4*19))), v3, v4)
		if func() uint32 {
			p := mem_getU32Ptr(0x5D4594, 1049700)
			*p--
			return *p
		}() == 0 && *memmap.PtrUint32(0x5D4594, 1049704) <= 2 {
			dword_5d4594_1049508.DrawData().BgImageHnd = dword_5d4594_1049508.DrawData().HlImageHnd
		}
	}
	v6 = sub_45CFC0()
	sub_46AE10(dword_5d4594_1049524, v6)
	return 1
}
func nox_xxx_quickbarTrapButtonProc_45F7A0(win *gui.Window, a2, a3, p4 uintptr) uintptr {
	if a2 < 5 {
		sub_46AE10(dword_5d4594_1049504.C(), 0)
		return 0
	}
	if a2 <= 6 {
		return 1
	}
	if a2 != 7 {
		sub_46AE10(dword_5d4594_1049504.C(), 0)
		return 0
	}
	if *memmap.PtrUint32(0x5D4594, 1047928) != 0 {
		if !nox_xxx_wndPointInWnd_46AAB0(win, int32(uint16(a3)), int32(a3>>16)) {
			nox_client_buildTrap_45E040()
		}
		nox_xxx_wndClearCaptureMain_46ADE0(win)
		dword_5d4594_1049532 = nil
		*memmap.PtrUint32(0x5D4594, 1047928) = 0
		return 1
	}
	sub_46AE10(dword_5d4594_1049504.C(), 1)
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 {
		return 1
	}
	if int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))) == 1 && sub_45F890() != 0 {
		nox_xxx_wndSetCaptureMain_46ADC0(win)
		dword_5d4594_1049532 = win
		*memmap.PtrUint32(0x5D4594, 1047928) = 1
		return 1
	} else {
		nox_client_buildTrap_45E040()
		return 1
	}
}
func sub_45F890() int32 {
	var (
		v0 *int32
		v1 int32
	)
	v0 = *(**int32)(memmap.PtrOff(0x5D4594, 1048144))
	v1 = 0
	for *v0 == 0 || (nox_xxx_spellFlags_424A70(*v0)&8) != 8 {
		v1++
		v0 = (*int32)(unsafe.Add(unsafe.Pointer(v0), 4*2))
		if v1 >= 3 {
			return 0
		}
	}
	return 1
}
func nox_xxx_quickbar_45F8D0(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	return uintptr(bool2int(a2 != 8 && a2 != 12 && a2 != 16))
}
func sub_45F8F0(win *gui.Window, draw *gui.WindowData) int {
	sub_45F900()
	return 1
}
func sub_45F900() {
	var (
		result *uint32
		i      int32
		v3     int32
	)
	if nox_xxx_aClosewoodengat_587000_133480 == nil {
		return
	}
	if dword_5d4594_1049496 != 0 {
		result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_bookGet_430B40_get_mouse_prev_seq())))
		if *(**uint32)(memmap.PtrOff(0x5D4594, 1049492)) == result {
			return
		}
		dword_5d4594_1049496 = 0
	} else {
		result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_bookGet_430B40_get_mouse_prev_seq())))
		if *(**uint32)(memmap.PtrOff(0x5D4594, 1049492)) != result {
			return
		}
		dword_5d4594_1049496 = 1
	}
	for i = 0; i < 5; i++ {
		v2 := *(*unsafe.Pointer)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 204))
		v3 = int32(*(*uint32)(unsafe.Add(v2, i*8)))
		v4 := unsafe.Add(v2, i*8)
		if v3 != 0 {
			if !nox_xxx_spellHasFlags_424A50(v3, 0x200400) {
				*(*uint8)(unsafe.Add(v4, 4)) ^= 1
				nox_xxx_updateSpellIconDir_45DE10(i, nox_xxx_aClosewoodengat_587000_133480)
			}
		}
	}
	nox_xxx_updateSpellIcons_45DDF0(nox_xxx_aClosewoodengat_587000_133480)
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100)
}
func nox_xxx_quickbarTrapProc_45FB90(win *gui.Window, a2, p3, p4 uintptr) uintptr {
	if a2 < 5 {
		return 0
	}
	if a2 <= 6 {
		return 1
	}
	if a2 == 7 {
		if wndIsShown_nox_xxx_wndIsShown_46ACC0(win) == 0 {
			sub_461060()
		}
		return 1
	}
	return 0
}
func nox_xxx_quickbarDrawFn_460000(win *gui.Window, draw *gui.WindowData) int {
	var (
		v0 int32
		v1 int32
	)
	v0 = int32(dword_5d4594_1049504.Off.Y)
	v1 = int32(dword_5d4594_1049504.Off.Y - int(dword_5d4594_1049536))
	if v1 >= 0 {
		if v1 <= 0 {
			if dword_5d4594_1049536 > uint32(nox_win_height) {
				sub_460070()
				dword_5d4594_1049536 = uint32(nox_win_height - 74)
			}
			return 1
		} else {
			nox_window_setPos_46A9B0(dword_5d4594_1049504, int32(dword_5d4594_1049504.Off.X), v0-1)
			return 1
		}
	} else {
		nox_window_setPos_46A9B0(dword_5d4594_1049504, int32(dword_5d4594_1049504.Off.X), v0+1)
		return 1
	}
}
func nox_xxx_quickBarInitWindow_4601F0(a1 unsafe.Pointer, a2 int32, a3 int32, a4 int32, a5 int32, a6 gui.WindowFuncLegacy, a7 gui.WindowDrawFunc) {
	var (
		v9  int32
		v10 *uint8
		v11 unsafe.Pointer
		v13 unsafe.Pointer
		v15 int32
	)
	v7 := a1
	*(*unsafe.Pointer)(unsafe.Add(a1, 208)) = nox_window_new(nil, 1224, int(a2-10), int(a3-15), 199, 59, nil).C()
	v8 := nox_xxx_gLoadImg_42F970(internCStr("QuickBarBase"))
	nox_xxx_wndSetIcon_46AE60(*(**gui.Window)(unsafe.Add(a1, 208)), v8)
	nox_xxx_wndSetOffsetMB_46AE40(*(**gui.Window)(unsafe.Add(a1, 208)), -61, -18)
	nox_xxx_wndSetWindowProc_46B300(*(**gui.Window)(unsafe.Add(a1, 208)), nox_xxx_quickbar_45F8D0)
	v9 = a5 + 10
	if a4 > 0 {
		v10 = (*uint8)(memmap.PtrOff(0x587000, 133488))
		v11 = unsafe.Add(a1, 212)
		v15 = a4
		for {
			v12 := nox_window_new((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(v7, 208))), 1032, int(v9), 15, 34, 34, nil)
			*(*unsafe.Pointer)(v11) = v12.C()
			nox_window_set_all_funcs(v12, a6, a7, nil)
			v13 = *(*unsafe.Pointer)(v11)
			v11 = unsafe.Add(v11, 4*1)
			v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v10), 4))
			*(*unsafe.Pointer)(unsafe.Add(v13, 368)) = v7
			v9 += int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v10), -int(4*1))))
			v15--
			if v15 == 0 {
				break
			}
		}
	}
	result := int32(*(*uint8)(unsafe.Add(v7, 200)))
	*(*unsafe.Pointer)(unsafe.Add(v7, 204)) = unsafe.Add(v7, result*40)
}
func sub_4602F0() {
	var (
		v0 int32
		v1 *uint8
		v2 int32
		v3 *uint32
		v4 *uint8
		v5 int32
		v6 *uint8
		v7 *uint8
		v8 int32
	)
	nox_xxx_quickBarClose_4606B0()
	v0 = 0
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1048196))
	for {
		v2 = 5
		v3 = (*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) + uint32(v0))))
		v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 4))
		v5 = int32(uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) + uint32(v0) - uint32(uintptr(unsafe.Pointer(v1))))
		for {
			*v3 = 0
			*(*uint8)(unsafe.Add(unsafe.Pointer(v4), v5)) = 0
			*(*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*1))) = 0
			*v4 = 0
			v3 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2))
			v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 8))
			v2--
			if v2 == 0 {
				break
			}
		}
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 256))
		v0 += 40
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1049476))) {
			break
		}
	}
	v6 = (*uint8)(memmap.PtrOff(0x5D4594, 1047940))
	for {
		v7 = v6
		v8 = 3
		for {
			*(*uint32)(unsafe.Pointer(v7)) = 0
			*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 4)) = 0
			v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 8))
			v8--
			if v8 == 0 {
				break
			}
		}
		v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 40))
		if int32(uintptr(unsafe.Pointer(v6))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1048060))) {
			break
		}
	}
	if *(*uint32)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 232)) != 0 {
		nox_xxx_updateSpellIcons_45DDF0(nox_xxx_aClosewoodengat_587000_133480)
	}
}
func Sub_460380() {
	var v0 *uint8
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 1047764+24*1+16))
	for {
		*(*uint32)(unsafe.Pointer(v0)) = 0
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 24))
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1047924))) {
			break
		}
	}
	sub_4602F0()
}
func nox_client_trapSetNext_4603A0() {
	if int32(*memmap.PtrUint8(0x5D4594, 1048140)) == 2 {
		*memmap.PtrUint8(0x5D4594, 1048140) = 0
	} else {
		*memmap.PtrUint8(0x5D4594, 1048140)++
	}
	*memmap.PtrUint32(0x5D4594, 1048144) = uint32(uintptr(memmap.PtrOff(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1048140))*40)+1047940)))
	nox_xxx_clientPlaySoundSpecial_452D80(798, 100)
}
func nox_client_trapSetPrev_4603F0() {
	if int32(*memmap.PtrUint8(0x5D4594, 1048140)) != 0 {
		*memmap.PtrUint8(0x5D4594, 1048140)--
	} else {
		*memmap.PtrUint8(0x5D4594, 1048140) = 2
	}
	*memmap.PtrUint32(0x5D4594, 1048144) = uint32(uintptr(memmap.PtrOff(0x5D4594, uintptr(int32(*memmap.PtrUint8(0x5D4594, 1048140))*40)+1047940)))
	nox_xxx_clientPlaySoundSpecial_452D80(798, 100)
}
func nox_client_trapSetSelect_4604B0(a1 int32) int32 {
	var result int32
	result = a1
	if !(a1 >= 0 && a1 < 3) {
		return result
	}
	*memmap.PtrUint8(0x5D4594, 1048140) = uint8(int8(a1))
	result = int32(uint8(int8(a1))) * 5
	*memmap.PtrUint32(0x5D4594, 1048144) = uint32(uintptr(memmap.PtrOff(0x5D4594, uintptr(int32(uint8(int8(a1)))*40)+1047940)))
	return result
}
func sub_4604E0() int32 {
	return int32(*memmap.PtrUint8(0x5D4594, 1048140))
}
func nox_client_spellSetNext_4604F0() {
	var (
		result int32
		v1     int32
	)
	result = int32(*memmap.PtrUint32(0x5D4594, 1049476))
	if *memmap.PtrUint32(0x5D4594, 1049476) == 0 {
		result = int32(dword_5d4594_1049496)
		if dword_5d4594_1049496 == 0 {
			result = nox_xxx_get_57AF20()
			if result == 0 {
				nox_xxx_clientStoreLastButton_45DAD0(-1)
				v1 = int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200))) + 1
				if v1 > 4 {
					v1 = 0
				}
				nox_xxx_clientUpdateButtonRow_45E110(v1)
			}
		}
	}
}
func nox_client_spellSetPrev_460540() {
	var (
		result int32
		v1     int32
	)
	result = int32(*memmap.PtrUint32(0x5D4594, 1049476))
	if *memmap.PtrUint32(0x5D4594, 1049476) == 0 {
		result = int32(dword_5d4594_1049496)
		if dword_5d4594_1049496 == 0 {
			result = nox_xxx_get_57AF20()
			if result == 0 {
				nox_xxx_clientStoreLastButton_45DAD0(-1)
				v1 = int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200))) - 1
				if v1 < 0 {
					v1 = 4
				}
				nox_xxx_clientUpdateButtonRow_45E110(v1)
			}
		}
	}
}
func nox_client_spellSetSelect_460590() {
	var result int32
	result = int32(*memmap.PtrUint32(0x5D4594, 1049476))
	if *memmap.PtrUint32(0x5D4594, 1049476) == 0 {
		result = int32(dword_5d4594_1049496)
		if dword_5d4594_1049496 == 0 {
			if nox_xxx_checkKeybTimeout_4160F0(7, gameFPS()>>1) {
				*(*uint8)(unsafe.Pointer(&result)) = 0
				*memmap.PtrUint32(0x5D4594, 1049712) = 0
			} else {
				result = int32(func() uint32 {
					p := mem_getU32Ptr(0x5D4594, 1049712)
					*p++
					return *p
				}())
				if *memmap.PtrInt32(0x5D4594, 1049712) >= 5 {
					*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)) = 4
					return
				}
			}
			*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)) = uint8(int8(result))
			*(*uint32)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 204)) = uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) + uint32(int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)))*40)
			nox_xxx_setKeybTimeout_4160D0(7)
			nox_xxx_clientPlaySoundSpecial_452D80(798, 100)
			nox_xxx_updateSpellIcons_45DDF0(nox_xxx_aClosewoodengat_587000_133480)
		}
	}
}
func sub_460630() {
	if *memmap.PtrUint32(0x5D4594, 1049476) == 0 {
		var result int32 = nox_xxx_bookGet_430B40_get_mouse_prev_seq()
		*memmap.PtrUint32(0x5D4594, 1049492) = uint32(result)
	}
}
func nox_xxx_guiSpell_460650() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1047928))
}
func sub_460660() int32 {
	if dword_5d4594_1049532 != nil || *memmap.PtrUint32(0x5D4594, 1047928) != 0 || dword_5d4594_1047932 != 0 {
		nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_1049532)
		dword_5d4594_1049532 = nil
		*memmap.PtrUint32(0x5D4594, 1047928) = 0
		dword_5d4594_1047932 = 0
		return 1
	}
	return bool2int32(dword_5d4594_1049532 != nil)
}
func nox_xxx_quickBarClose_4606B0() int32 {
	var (
		v0 *uint8
		v1 int32
		v2 *uint8
		v3 *int32
		v4 *uint8
		v6 int32
		v7 int32
		v8 int32
	)
	if *memmap.PtrUint32(0x5D4594, 1049476) != 1 {
		return 0
	}
	v6 = 0
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 1048196))
	for {
		v1 = int32(uintptr(unsafe.Add(unsafe.Pointer(v0), uint32(-v6)-uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)))))
		v2 = v0
		v3 = (*int32)(unsafe.Add(unsafe.Pointer(v0), 232))
		v4 = (*uint8)(unsafe.Add(unsafe.Pointer(uintptr(uint32(v6)+uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)))), 4))
		v8 = int32(uintptr(unsafe.Add(unsafe.Pointer(v0), uint32(-v6)-uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)))))
		v7 = 5
		for {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*1))) = *(*uint32)(unsafe.Pointer(v2))
			*v4 = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), v1))
			nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*v3))), 1)
			v3 = (*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
			v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 8))
			v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 8))
			if func() int32 {
				p := &v7
				*p--
				return *p
			}() == 0 {
				break
			}
			v1 = v8
		}
		nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*52))))), 1)
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 256))
		v6 += 40
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1049220))) {
			break
		}
	}
	*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)) = *memmap.PtrUint8(0x5D4594, 1047908)
	*(*uint32)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 204)) = uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) + uint32(int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)))*40)
	nox_xxx_updateSpellIcons_45DDF0(nox_xxx_aClosewoodengat_587000_133480)
	nox_window_set_hidden(dword_5d4594_1049512, 0)
	nox_xxx_clientPlaySoundSpecial_452D80(800, 100)
	*memmap.PtrUint32(0x5D4594, 1049476) = 0
	return 1
}
func sub_460920() {
	var (
		v0 *uint8
		v1 *int32
		v2 *uint8
		v3 *uint32
		v4 int32
		v6 int32
		v7 int32
		i  int32
	)
	if *memmap.PtrUint32(0x5D4594, 1049476) != 0 {
		nox_xxx_quickBarClose_4606B0()
		return
	}
	if dword_5d4594_1049496 != 0 {
		return
	}
	if nox_xxx_get_57AF20() != 0 {
		return
	}
	if *memmap.PtrUint32(0x5D4594, 1049476) != 0 {
		return
	}
	if dword_5d4594_1049484 == 1 {
		sub_461010()
	}
	v6 = 0
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 1048428))
	for {
		v1 = (*int32)(unsafe.Pointer(v0))
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), -228))
		v3 = (*uint32)(unsafe.Pointer(uintptr(uint32(v6) + uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)))))
		v7 = 5
		v4 = int32(uint32(v6) + uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) - uint32(uintptr(unsafe.Add(unsafe.Pointer(v0), -232))))
		for i = int32(uint32(v6) + uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) - uint32(uintptr(unsafe.Add(unsafe.Pointer(v0), -232)))); ; v4 = i {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), -int(4*1))) = *v3
			*v2 = *(*uint8)(unsafe.Add(unsafe.Pointer(v2), v4))
			nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*v1))), 0)
			v1 = (*int32)(unsafe.Add(unsafe.Pointer(v1), 4*1))
			v3 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2))
			v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 8))
			if func() int32 {
				p := &v7
				*p--
				return *p
			}() == 0 {
				break
			}
		}
		nox_window_set_hidden((*gui.Window)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), -int(4*6)))))), 0)
		nox_xxx_updateSpellIcons_45DDF0(unsafe.Add(unsafe.Pointer(v0), -232))
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 256))
		v6 += 40
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1049452))) {
			break
		}
	}
	*memmap.PtrUint32(0x5D4594, 1047912) = uint32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)))
	*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)) = 4
	*(*uint32)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 204)) = uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) + uint32(int32(*(*uint8)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 200)))*40)
	nox_xxx_updateSpellIcons_45DDF0(nox_xxx_aClosewoodengat_587000_133480)
	nox_window_set_hidden(dword_5d4594_1049512, 1)
	nox_xxx_clientPlaySoundSpecial_452D80(799, 100)
	*memmap.PtrUint32(0x5D4594, 1049476) = 1
}
func sub_460940(this unsafe.Pointer) int32 {
	var (
		result int32
		v2     unsafe.Pointer
	)
	v2 = this
	if nox_crypt_IsReadOnly() == 0 && sub_461450() == 1 {
		sub_461400()
		sub_461440(0)
	}
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
		*(*uint8)(unsafe.Pointer(&v2)) = *(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))
	} else {
		*(*uint8)(unsafe.Pointer(&v2)) = *(*byte)(unsafe.Add(unsafe.Pointer(nox_xxx_getHostInfoPtr_431770()), 66))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v2)), 1)
	if int32(uint8(uintptr(v2))) == 0 {
		result = sub_460A10(nox_xxx_aClosewoodengat_587000_133480, 5, 5, 0)
		if result == 0 {
			return result
		}
		return 1
	}
	result = sub_460A10(nox_xxx_aClosewoodengat_587000_133480, 5, 5, int8(uintptr(v2)))
	if result == 0 {
		return result
	}
	result = sub_460A10(memmap.PtrOff(0x5D4594, 1047940), 3, 3, int8(uintptr(v2)))
	if result != 0 {
		if *(*uint32)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 232)) != 0 {
			nox_xxx_updateSpellIcons_45DDF0(nox_xxx_aClosewoodengat_587000_133480)
		}
		return 1
	}
	return result
}
func sub_460A10(a1 unsafe.Pointer, a2 int32, a3 int32, a4 int8) int32 {
	var (
		v5  int32
		v6  *byte
		v7  bool
		v9  uint32
		v10 int32
		v12 int32
		v13 [256]byte
	)
	if a2 <= 0 {
		return 1
	}
	v4 := a1
	v11 := a1
	v12 = a2
	for {
		v5 = a3
		if a3 > 0 {
			for {
				if nox_crypt_IsReadOnly() == 1 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 1)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v13[0], uint32(uint8(int8(v10))))
					v13[uint8(int8(v10))] = 0
					if int32(a4) != 0 {
						*(*uint32)(v4) = uint32(nox_xxx_spellNameToN_4243F0(&v13[0]))
					} else {
						*(*uint32)(v4) = uint32(nox_xxx_abilityNameToN_424D80(&v13[0]))
					}
				} else {
					if int32(a4) != 0 {
						*(*uint8)(unsafe.Pointer(&v10)) = uint8(int8(libc.StrLen(nox_xxx_spellNameByN_424870(int32(*(*uint32)(v4))))))
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 1)
						v9 = uint32(uint8(int8(v10)))
						v6 = nox_xxx_spellNameByN_424870(int32(*(*uint32)(v4)))
					} else {
						*(*uint8)(unsafe.Pointer(&v10)) = uint8(int8(libc.StrLen(nox_xxx_abilityGetName_425250(int32(*(*uint32)(v4))))))
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 1)
						v9 = uint32(uint8(int8(v10)))
						v6 = nox_xxx_abilityGetName_425250(int32(*(*uint32)(v4)))
					}
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v6, v9)
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v4, 4)), 1)
				v4 = unsafe.Add(v4, 8)
				v5--
				if v5 == 0 {
					break
				}
			}
		}
		v4 = unsafe.Add(v11, 40)
		v7 = v12 == 1
		v11 = unsafe.Add(v11, 40)
		v12--
		if v7 {
			break
		}
	}
	return 1
}
func sub_460B90(a1 int32) {
	var (
		i int32
		j int32
	)
	if a1 != 0 {
		nox_window_set_hidden(dword_5d4594_1049500, 0)
		nox_window_set_hidden(dword_5d4594_1049504, 0)
		nox_window_set_hidden(dword_5d4594_1049520, 0)
		nox_window_set_hidden(dword_5d4594_1049508, 0)
		nox_window_set_hidden(dword_5d4594_1049512, 0)
		for i = 232; i < 252; i += 4 {
			nox_window_set_hidden((*gui.Window)(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(uint32(i) + uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) - 20)))), 0)
			nox_window_set_hidden((*gui.Window)(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(uint32(i) + uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)))))), 0)
			if dword_5d4594_1049484 != 0 {
				nox_window_set_hidden((*gui.Window)(*memmap.PtrPtr(0x5D4594, uintptr(i)+1047920)), 0)
				nox_window_set_hidden((*gui.Window)(*memmap.PtrPtr(0x5D4594, uintptr(i)+1047940)), 0)
				nox_window_set_hidden(dword_5d4594_1049512, 1)
			}
		}
		if dword_5d4594_1049484 != 0 {
			nox_window_set_hidden((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1048148)), 0)
		}
		nox_window_set_hidden((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 208))), 0)
	} else {
		if *memmap.PtrUint32(0x5D4594, 1049476) != 0 {
			sub_460920()
		}
		nox_window_set_hidden(dword_5d4594_1049500, 1)
		nox_window_set_hidden(dword_5d4594_1049504, 1)
		nox_window_set_hidden(dword_5d4594_1049520, 1)
		nox_window_set_hidden(dword_5d4594_1049508, 1)
		nox_window_set_hidden(dword_5d4594_1049512, 1)
		for j = 232; j < 252; j += 4 {
			nox_window_set_hidden((*gui.Window)(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(uint32(j) + uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)) - 20)))), 1)
			nox_window_set_hidden((*gui.Window)(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(uint32(j) + uint32(uintptr(nox_xxx_aClosewoodengat_587000_133480)))))), 1)
		}
		nox_window_set_hidden((*gui.Window)(*(*unsafe.Pointer)(unsafe.Add(nox_xxx_aClosewoodengat_587000_133480, 208))), 1)
		nox_window_set_hidden((*gui.Window)(*memmap.PtrPtr(0x5D4594, 1048148)), 1)
	}
}
