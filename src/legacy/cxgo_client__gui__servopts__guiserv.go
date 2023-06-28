package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type nox_gui_gamemode struct {
	name  string
	title *wchar2_t
	mode  uint32
	hide  bool
}

var nox_gui_gamemodes = []nox_gui_gamemode{
	{name: "CTF", title: nil, mode: 0x20, hide: false},
	{name: "Arena", title: nil, mode: 0x100, hide: false},
	{name: "Highlander", title: nil, mode: 0x400, hide: false},
	{name: "KotR", title: nil, mode: 0x10, hide: false},
	{name: "Flagball", title: nil, mode: 0x40, hide: false},
	{name: "Quest", title: nil, mode: 0x1000, hide: true},
	{name: "Noxworld.c:Chat", title: nil, mode: 0x80, hide: false},
	{},
}
var nox_gui_gamemode_cnt int32 = int32(len(nox_gui_gamemodes) - 1)
var nox_gui_gamemode_loaded_1046548 int32 = 0

func nox_gui_gamemode_load_457410() {
	if nox_gui_gamemode_loaded_1046548 != 0 {
		return
	}
	for i := range nox_gui_gamemodes {
		p := &nox_gui_gamemodes[i]
		if p.name == "" {
			break
		}
		p.title = nox_strman_loadString_40F1D0(internCStr(p.name), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 212)
	}
	nox_gui_gamemode_loaded_1046548 = 1
}
func nox_xxx_guiServerOptionsGetGametypeName_4573C0(mode int16) *wchar2_t {
	mode &= 0x17F0
	if nox_gui_gamemode_loaded_1046548 == 0 {
		nox_gui_gamemode_load_457410()
	}
	for i := int32(0); i < nox_gui_gamemode_cnt; i++ {
		var p *nox_gui_gamemode = &nox_gui_gamemodes[i]
		if p.mode == uint32(mode) {
			return p.title
		}
	}
	return nox_gui_gamemodes[1].title
}
func sub_457A10() {
	var (
		v0 *uint32
		v1 *uint32
		v3 int32
		v6 int32
		v7 int32
	)
	v0 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10120)))
	v1 = v0
	var max int32 = 0
	var cnt int32 = 0
	for i := int32(0); i < nox_gui_gamemode_cnt; i++ {
		var p *nox_gui_gamemode = &nox_gui_gamemodes[i]
		if p.hide {
			continue
		}
		cnt++
		var w int32 = 0
		nox_xxx_drawGetStringSize_43F840(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*59)), p.title, &w, nil, 0)
		if w > max {
			max = w
		}
	}
	v3 = cnt * (nox_xxx_guiFontHeightMB_43F320(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v0), 4*59))) + 1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*7)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*5)) + uint32(v3) + 2
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*3)) = uint32(v3 + 2)
	v6 = max + 7
	v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*6)) - uint32(v6))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*2)) = uint32(v6)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*4)) = uint32(v7)
}
func sub_459650(title *wchar2_t) int32 {
	for i := int32(0); i < nox_gui_gamemode_cnt; i++ {
		var p *nox_gui_gamemode = &nox_gui_gamemodes[i]
		if nox_wcscmp(p.title, title) == 0 {
			return int32(p.mode)
		}
	}
	return 0
}
func sub_459C10() int32 {
	var v0 *wchar2_t
	v0 = (*wchar2_t)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10119)))
	return sub_459650((*wchar2_t)(unsafe.Add(unsafe.Pointer(v0), unsafe.Sizeof(wchar2_t(0))*54)))
}
func nox_xxx_windowServerOptionsFillGametypeList_4596A0() {
	var v0 unsafe.Pointer = unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10120))
	nox_window_call_field_94_fnc((*gui.Window)(v0), 16399, 0, 0)
	for i := int32(0); i < nox_gui_gamemode_cnt; i++ {
		var p *nox_gui_gamemode = &nox_gui_gamemodes[i]
		if !p.hide {
			nox_window_call_field_94_fnc((*gui.Window)(v0), 16397, uintptr(unsafe.Pointer(p.title)), math.MaxUint32)
		}
	}
}
func nox_xxx_guiServerOptsLoad_457500() int32 {
	var (
		v1  int32
		v2  *uint32
		v3  *uint32
		v4  *uint32
		v5  *byte
		v6  *uint32
		v7  *uint32
		v8  *uint32
		v9  *byte
		v10 *wchar2_t
		v11 *wchar2_t
		v12 *wchar2_t
		v13 *uint32
		v14 *byte
		v15 *uint32
	)
	if nox_gui_xxx_check_446360() != 0 {
		return 1
	}
	if dword_5d4594_1046492 != nil {
		nox_xxx_clientPlaySoundSpecial_452D80(231, 100)
		nox_xxx_guiServerOptionsTryHide_4574D0()
		return 1
	}
	if noxflags.HasGame(1) {
		sub_459D50(1)
		if dword_587000_129656 != 0 {
			nox_common_list_clear_425760((*nox_list_item_t)(memmap.PtrOff(0x5D4594, 1045956)))
		}
	}
	v1 = nox_strman_get_lang_code()
	if nox_xxx_guiFontHeightMB_43F320(nil) > 10 {
		v1 = 2
	}
	dword_5d4594_1046492 = nox_new_window_from_file(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1*4)+129760)), nox_xxx_guiServerOptionsProcPre_4585D0)
	nox_draw_setTabWidth_43FE20(100)
	nox_window_setPos_46A9B0(dword_5d4594_1046492, int32(int(uint32(nox_win_width))-dword_5d4594_1046492.SizeVal.X-10), 0)
	nox_xxx_wndSetWindowProc_46B300(dword_5d4594_1046492, nox_xxx_guiServerOptionsProc_458590)
	nox_xxx_wndSetDrawFn_46B340(dword_5d4594_1046492, nox_xxx_windowServerOptionsDrawProc_458500)
	dword_5d4594_1046512 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10101)
	dword_5d4594_1046496 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10114)
	dword_5d4594_1046500 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10183))))
	dword_5d4594_1046504 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10197)
	dword_5d4594_1046508 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10199)
	dword_5d4594_1046524 = uint32(uintptr(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10150))))
	dword_5d4594_1046516 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10134)
	dword_5d4594_1046520 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10135)
	dword_5d4594_1046536 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10153)
	v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10331)))
	nox_gui_winSetFunc96_46B070((*gui.Window)(unsafe.Pointer(v2)), nox_xxx_options_457AA0)
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10333)))
	nox_gui_winSetFunc96_46B070((*gui.Window)(unsafe.Pointer(v3)), nox_xxx_options_457B00)
	nox_xxx_wnd_46B280(dword_5d4594_1046524, dword_5d4594_1046492)
	nox_xxx_wnd_46B280(dword_5d4594_1046532, dword_5d4594_1046492)
	nox_xxx_wnd_46B280(dword_5d4594_1046536, dword_5d4594_1046492)
	nox_xxx_wnd_46B280(dword_5d4594_1046500, dword_5d4594_1046492)
	nox_xxx_wnd_46B280(dword_5d4594_1046504, dword_5d4594_1046492)
	nox_xxx_wnd_46B280(dword_5d4594_1046508, dword_5d4594_1046492)
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_1046524, nox_xxx_guiServerOptionsProcPre_4585D0)
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_1046532, nox_xxx_guiServerOptionsProcPre_4585D0)
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_1046536, nox_xxx_guiServerOptionsProcPre_4585D0)
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_1046500, nox_xxx_guiServerOptionsProcPre_4585D0)
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_1046504, nox_xxx_guiServerOptionsProcPre_4585D0)
	nox_xxx_wndSetProc_46B2C0(dword_5d4594_1046508, nox_xxx_guiServerOptionsProcPre_4585D0)
	*memmap.PtrPtr(0x5D4594, 1046352) = unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("UITabs1")))
	dword_5d4594_1046356 = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("UITabs2")))))
	dword_5d4594_1046360 = uint32(uintptr(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("UITabs3")))))
	v4 = (*uint32)(dword_5d4594_1046496.WidgetData)
	v14 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("UISlider"))))
	v5 = (*byte)(unsafe.Pointer(nox_xxx_gLoadImg_42F970(internCStr("UISliderLit"))))
	v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1046500)), 10182)))
	v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1046500)), 10180)))
	v15 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(dword_5d4594_1046500)), 10181)))
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v6), 4*100)), 8)) = 16
	*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v6), 4*100)), 12)) = 10
	sub_4B5700(int32(uintptr(unsafe.Pointer(v6))), 0, 0, unsafe.Pointer(v14), unsafe.Pointer(v5), unsafe.Pointer(v5))
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v6))), dword_5d4594_1046496)
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v7))), dword_5d4594_1046496)
	nox_xxx_wnd_46B280(int32(uintptr(unsafe.Pointer(v15))), dword_5d4594_1046496)
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*9)) = uint32(uintptr(unsafe.Pointer(v6)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*7)) = uint32(uintptr(unsafe.Pointer(v7)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*8)) = uint32(uintptr(unsafe.Pointer(v15)))
	v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10160)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*9)) |= 4
	v9 = sub_4165D0(0)
	if noxflags.HasGame(1) {
		sub_4161E0()
	}
	nox_gui_gamemode_load_457410()
	sub_457B60(unsafe.Pointer(v9))
	sub_457A10()
	if noxflags.HasGame(1) {
		sub_4165F0(0, 1)
		sub_4165D0(1)
	} else {
		v10 = (*wchar2_t)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10159)))
		v11 = nox_strman_loadString_40F1D0(internCStr("servopts.wnd:teams"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 1811)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v10)), 16385, uintptr(unsafe.Pointer(v11)), math.MaxUint32)
		v12 = nox_strman_loadString_40F1D0(internCStr("servopts.wnd:TeamTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 1812)
		nox_xxx_wndWddSetTooltip_46B000((*gui.WindowData)(unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(wchar2_t(0))*18)), v12)
		v13 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10149)))
		nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v13)), 0)
		nox_window_set_hidden(dword_5d4594_1046508, 1)
		sub_46ACE0(dword_5d4594_1046492, 10145, 10146, 1)
	}
	if dword_587000_129656 != 0 {
		if sub_4D6F30() != 0 || nox_xxx_isQuest_4D6F50() != 0 {
			nox_server_parseCmdText_443C80(internWStr("execrul OTQuest.rul"), 1)
		} else if nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
			nox_server_parseCmdText_443C80(internWStr("execrul server.rul"), 1)
		}
	}
	dword_587000_129656 = 0
	return 1
}
func nox_xxx_options_457AA0(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	a2 := (*uint32)(draw.C())
	var v2 *wchar2_t
	if int32(*a2)&4 != 0 {
		v2 = nox_strman_loadString_40F1D0(internCStr("AutoAssignOnTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 446)
	} else {
		v2 = nox_strman_loadString_40F1D0(internCStr("AutoAssignOffTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 450)
	}
	nox_xxx_cursorSetTooltip_4776B0(v2)
	return 1
}
func nox_xxx_options_457B00(win *gui.Window, draw *gui.WindowData, a3 uintptr) int {
	a2 := (*uint8)(draw.C())
	var v2 *wchar2_t
	if int32(*a2)&4 != 0 {
		v2 = nox_strman_loadString_40F1D0(internCStr("TeamDamageOnTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 465)
	} else {
		v2 = nox_strman_loadString_40F1D0(internCStr("TeamDamageOffTT"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 469)
	}
	nox_xxx_cursorSetTooltip_4776B0(v2)
	return 1
}
func sub_457FE0() {
	var (
		v0 *uint32
		v1 *wchar2_t
		v2 *wchar2_t
		v3 *wchar2_t
		v5 *wchar2_t
		v6 *wchar2_t
	)
	v0 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10210)))
	if noxflags.HasGame(0x4000) {
		v5 = nox_strman_loadString_40F1D0(internCStr("Servopts.wnd:Individual"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 380)
		v1 = nox_strman_loadString_40F1D0(internCStr("Servopts.wnd:Ladder"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 379)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1045700)), internWStr("%s %s"), v1, v5)
	} else if noxflags.HasGame(0x8000) {
		v6 = nox_strman_loadString_40F1D0(internCStr("Servopts.wnd:Clan"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 385)
		v2 = nox_strman_loadString_40F1D0(internCStr("Servopts.wnd:Ladder"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 384)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1045700)), internWStr("%s %s"), v2, v6)
	} else {
		v3 = nox_strman_loadString_40F1D0(internCStr("WindowDir:Empty"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 389)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1045700)), v3)
	}
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v0)), 16385, uintptr(memmap.PtrOff(0x5D4594, 1045700)), math.MaxUint32)
}
func sub_4580E0(a1 int32) {
	var (
		v1  *wchar2_t
		v2  *wchar2_t
		v3  int16
		v4  *wchar2_t
		v5  *wchar2_t
		v6  *uint32
		v7  *uint32
		v8  *uint32
		v10 int32
	)
	v1 = nox_strman_loadString_40F1D0(internCStr("SettingsMsg"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 736)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1045968)), v1, a1)
	if noxflags.HasGame(128) {
		v2 = nox_strman_loadString_40F1D0(internCStr("GameType"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 739)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1046096)), v2)
	} else {
		v3 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
		v10 = int32(uintptr(unsafe.Pointer(nox_xxx_guiServerOptionsGetGametypeName_4573C0(v3))))
		v4 = nox_strman_loadString_40F1D0(internCStr("GameTypeIs"), nil, (*byte)(memmap.PtrOff(0x587000, 131072)), 743)
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1046096)), v4, v10)
	}
	if noxflags.HasGame(1) {
		v5 = nox_strman_loadString_40F1D0(internCStr("GoMessage"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 748)
	} else {
		v5 = nox_strman_loadString_40F1D0(internCStr("OptsMessage"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 752)
	}
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1046224)), v5)
	v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10121)))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v6)), 16385, uintptr(memmap.PtrOff(0x5D4594, 1045968)), math.MaxUint32)
	v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10118)))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v7)), 16385, uintptr(memmap.PtrOff(0x5D4594, 1046096)), math.MaxUint32)
	v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10117)))
	nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v8)), 16385, uintptr(memmap.PtrOff(0x5D4594, 1046224)), math.MaxUint32)
}
func nox_client_guiserv_updateMapList_458230(mode int32, current *byte, a3 bool) {
	var (
		v19 [58]byte
		v20 [58]byte
	)
	v21, free21 := alloc.Make([]wchar2_t{}, 100)
	defer free21()
	nox_window_call_field_94_fnc(dword_5d4594_1046496, 16399, 0, 0)
	var v18 int32 = -1
	*memmap.PtrUint32(0x5D4594, 1046552) = uint32(mode)
	var v17 int32 = 0
	for it := nox_common_maplist_first_4D09B0(); it != nil; it = nox_common_maplist_next_4D09C0(it) {
		if it.Field_6 == 0 {
			continue
		}
		if (sub_4CFFC0(unsafe.Pointer(it)) & mode) == 0 {
			continue
		}
		libc.StrCpy(&v19[0], &it.Name[0])
		alloc.Memcpy(unsafe.Pointer(&v20[0]), unsafe.Pointer(&v19[0]), 0x38)
		*(*uint16)(unsafe.Pointer(&v20[56])) = *(*uint16)(unsafe.Pointer(&v19[56]))
		sub_57A1E0((*int32)(unsafe.Pointer(&v19[0])), nil, nil, 1, int16(mode))
		sub_57A1E0((*int32)(unsafe.Pointer(&v20[0])), internCStr("user.rul"), nil, 3, int16(mode))
		var v6 int32 = -1
		for i := int32(0); i < 20; i += 4 {
			if *(*uint32)(unsafe.Pointer(&v19[i+24])) != *(*uint32)(unsafe.Pointer(&v20[i+24])) {
				v6 = 6
			}
		}
		if v6 == -1 {
			for j := int32(0); j < 4; j++ {
				if v19[j+44] != v20[j+44] {
					v6 = 6
				}
			}
			if v6 == -1 && *(*uint32)(unsafe.Pointer(&v19[48])) != *(*uint32)(unsafe.Pointer(&v20[48])) {
				v6 = 6
			}
		}
		var v16 int32 = int32(it.Field_8_1)
		var v15 int32 = int32(it.Field_8_0)
		var v9 *wchar2_t = nox_strman_loadString_40F1D0(internCStr("RecPlayers"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 823)
		nox_swprintf(&v21[0], v9, &it.Name[0], v15, v16)
		nox_window_call_field_94_fnc(dword_5d4594_1046496, 16397, uintptr(unsafe.Pointer(&v21[0])), uintptr(v6))
		if nox_strcmpi(current, &it.Name[0]) == 0 {
			v18 = v17
			nox_window_call_field_94_fnc(dword_5d4594_1046496, 16403, uintptr(v17), 0)
			nox_window_call_field_94_fnc(dword_5d4594_1046496, 16412, uintptr(v17), 0)
		}
		v17++
	}
	if v18 < 0 {
		nox_window_call_field_94_fnc(dword_5d4594_1046496, 16403, 0, 0)
		nox_window_call_field_94_fnc(dword_5d4594_1046496, 16412, 0, 0)
	}
	if !a3 {
		return
	}
	var v11 *byte = sub_4165B0()
	var v12 int32 = int32(nox_window_call_field_94_fnc(dword_5d4594_1046496, 16404, 0, 0))
	if v12 < 0 {
		*v11 = 0
	} else {
		var v13 int32 = int32(nox_window_call_field_94_fnc(dword_5d4594_1046496, 16406, uintptr(v12), 0))
		nox_sprintf((*byte)(unsafe.Pointer(&v21[0])), internCStr("%S"), v13)
		var v14 *byte = libc.StrTok((*byte)(unsafe.Pointer(&v21[0])), internCStr("\t"))
		if v14 == nil {
			*v11 = 0
		} else {
			libc.StrCpy(v11, v14)
		}
	}
	sub_57A1E0((*int32)(unsafe.Pointer(v11)), internCStr("user.rul"), nil, 7, int16(mode))
	sub_459880(int32(uintptr(unsafe.Pointer(v11))))
}
func nox_xxx_guiServerOptionsProcPre_4585D0(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		v4  *uint32
		v5  *byte
		v7  int32
		v8  int32
		v9  int32
		v10 *int32
		v11 int32
		v12 *uint32
		v13 *uint32
		v14 *uint32
		v15 *uint32
		v16 int32
		v17 *uint32
		v18 *byte
		v19 int32
		v20 int16
		v21 bool
		v22 *wchar2_t
		v23 *wchar2_t
		v24 *wchar2_t
		v25 *byte
		v26 *uint32
		v27 int32
		v28 int32
		v29 *byte
		v30 *uint32
		v31 int32
		v32 *wchar2_t
		v33 int32
		v34 uint32
		v35 int32
		v36 *byte
		v37 *byte
		v38 *wchar2_t
		v39 *wchar2_t
		v41 [100]byte
		v42 [100]byte
	)
	WideCharStr, free := alloc.Make([]wchar2_t{}, 4)
	defer free()
	if a2 > 16391 {
		if a2 != 16400 {
			return 1
		}
		v28 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3))) - 10114
		if v28 != 0 {
			if v28 == 6 {
				v29 = sub_4165B0()
				v30 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10119)))
				v31 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16404, 0, 0))
				if v31 >= 0 && v31 < int32(*(*int16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a3), 32)), 44))) {
					v32 = (*wchar2_t)(unsafe.Pointer(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16406, a4, 0)))
					nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v30)), 16385, uintptr(unsafe.Pointer(v32)), math.MaxUint32)
					v33 = int32(*((*uint16)(unsafe.Add(unsafe.Pointer(v29), unsafe.Sizeof(uint16(0))*26)))) & 0x17F0
					*((*uint16)(unsafe.Add(unsafe.Pointer(v29), unsafe.Sizeof(uint16(0))*26))) &= 0xE80F
					*((*uint16)(unsafe.Add(unsafe.Pointer(v29), unsafe.Sizeof(uint16(0))*26))) |= uint16(int16(sub_459650(v32)))
					if v33 != (int32(*((*uint16)(unsafe.Add(unsafe.Pointer(v29), unsafe.Sizeof(uint16(0))*26)))) & 0x17F0) {
						nox_client_guiserv_updateMapList_458230(int32(*((*uint16)(unsafe.Add(unsafe.Pointer(v29), unsafe.Sizeof(uint16(0))*26)))), (*byte)(memmap.PtrOff(0x5D4594, 1046556)), true)
					}
					nox_window_set_hidden((*gui.Window)(unsafe.Pointer(a3)), 1)
					nox_xxx_wndClearCaptureMain_46ADE0((*gui.Window)(unsafe.Pointer(a3)))
					*((*uint16)(unsafe.Add(unsafe.Pointer(v29), unsafe.Sizeof(uint16(0))*27))) = uint16(nox_xxx_servGamedataGet_40A020(int16(*((*uint16)(unsafe.Add(unsafe.Pointer(v29), unsafe.Sizeof(uint16(0))*26))))))
					*(*byte)(unsafe.Add(unsafe.Pointer(v29), 56)) = sub_40A180(int16(*((*uint16)(unsafe.Add(unsafe.Pointer(v29), unsafe.Sizeof(uint16(0))*26)))))
					sub_457460(unsafe.Pointer(v29))
					sub_459D50(1)
					if *(*byte)(unsafe.Add(unsafe.Pointer(v29), 53))&0x10 != 0 {
						nox_xxx_spellEnableAll_424BD0()
						sub_4537F0()
						sub_459700()
					}
					*(*uint16)(unsafe.Add(unsafe.Pointer(&v34), unsafe.Sizeof(uint16(0))*0)) = *((*uint16)(unsafe.Add(unsafe.Pointer(v29), unsafe.Sizeof(uint16(0))*26)))
					sub_457F30(int32((v34 >> 12) & 1))
					return 1
				}
			}
		} else if nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16404, 0, 0) >= 0 {
			v35 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(a3)), 16406, a4, 0))
			nox_sprintf(&v42[0], internCStr("%S"), v35)
			v36 = libc.StrTok(&v42[0], internCStr("\t"))
			v37 = sub_4165B0()
			if v36 == nil {
				v36 = internCStr("")
			}
			libc.StrCpy(v37, v36)
			sub_57A1E0((*int32)(unsafe.Pointer(v37)), internCStr("user.rul"), nil, 7, int16(*((*uint16)(unsafe.Add(unsafe.Pointer(v37), unsafe.Sizeof(uint16(0))*26)))))
			sub_459880(int32(uintptr(unsafe.Pointer(v37))))
			sub_459D50(1)
		}
		return 1
	}
	if a2 == 16391 {
		v9 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
		switch v9 {
		case 10119:
			v26 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10120)))
			nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v26)), 0)
			nox_xxx_wndSetCaptureMain_46ADC0((*gui.Window)(unsafe.Pointer(v26)))
			nox_xxx_wndShowModalMB_46A8C0((*gui.Window)(unsafe.Pointer(v26)))
			nox_xxx_windowServerOptionsFillGametypeList_4596A0()
			return 1
		case 10122:
			v27 = bool2int32((int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a3), 36))) & 4) != 0)
			if !noxflags.HasGame(49152) {
				nox_xxx_wnd_46ABB0((*gui.Window)(dword_5d4594_1046500), v27)
				nox_xxx_wnd_46ABB0(dword_5d4594_1046504, v27)
			}
			sub_459D50(1)
			return 1
		case 10141:
			sub_459700()
			return 1
		case 10145:
			v18 = nox_xxx_cliGamedataGet_416590(1)
			sub_459AA0(unsafe.Pointer(v18))
			sub_4165F0(1, 0)
			v19 = int32(nox_xxx_getTeamCounter_417DD0())
			if noxflags.HasGame(128) && (func() int32 {
				v20 = int16(*((*uint16)(unsafe.Add(unsafe.Pointer(v18), unsafe.Sizeof(uint16(0))*26))))
				return int32(v20) & 0x60
			}()) != 0 {
				if int32(v20) < 0 {
					v21 = v19 <= 2
				} else {
					v21 = v19 <= 2
					if v19 < 2 {
						v22 = nox_strman_loadString_40F1D0(internCStr("NeedTeams"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 1363)
						nox_xxx_dialogMsgBoxCreate_449A10(dword_5d4594_1046492, (*wchar2_t)(memmap.PtrOff(0x5D4594, 1046560)), v22, 56, sub_459150, nil)
						sub_44A360(1)
						return 1
					}
				}
				if !v21 {
					v38 = nox_strman_loadString_40F1D0(internCStr("TooManyTeams"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 1371)
					v23 = nox_strman_loadString_40F1D0(internCStr("Notice"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 1370)
					nox_xxx_dialogMsgBoxCreate_449A10(dword_5d4594_1046492, v23, v38, 33, nil, nil)
					sub_44A360(1)
					return 1
				}
			} else if noxflags.HasGame(128) && noxflags.HasGame(16) && nox_xxx_CheckGameplayFlags_417DA0(4) && v19 > 2 {
				v39 = nox_strman_loadString_40F1D0(internCStr("TooManyTeams"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 1384)
				v24 = nox_strman_loadString_40F1D0(internCStr("Notice"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 1383)
				nox_xxx_dialogMsgBoxCreate_449A10(dword_5d4594_1046492, v24, v39, 33, nil, nil)
				sub_44A360(1)
				return 1
			}
			sub_459150()
			return 1
		case 10146:
			v25 = sub_4165B0()
			if noxflags.HasGame(128) {
				if int32(*(*byte)(unsafe.Add(unsafe.Pointer(v25), 53))) < 0 {
					nox_server_teamsZzz_419030(1)
				}
				*((*uint16)(unsafe.Add(unsafe.Pointer(v25), unsafe.Sizeof(uint16(0))*26))) &= 0x3FFF
			}
			nox_xxx_guiServerOptionsHide_4597E0(0)
			return 1
		case 10149:
			nox_xxx_guiServerOptionsHide_4597E0(0)
			return 1
		case 10152:
			v10 = (*int32)(unsafe.Pointer(nox_xxx_cliGamedataGet_416590(1)))
			nox_xxx_loadAdvancedWnd_4BDC10(v10)
			return 1
		case 10159:
			v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 396)))
			sub_46B120((*gui.Window)(unsafe.Pointer(a3)), nil)
			sub_46B120((*gui.Window)(unsafe.Pointer(a3)), (*gui.Window)(v11))
			v12 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10196)))
			if noxflags.HasGame(1) {
				nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v12)), 0)
				sub_46ACE0(dword_5d4594_1046492, 10161, 10163, 0)
				sub_46AD20(dword_5d4594_1046492, 10161, 10163, 1)
				sub_4593B0(0)
				v13 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10163)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*9)) |= 4
				v14 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10161)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*9)) &= 0xFFFFFFFB
				v15 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10162)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*9)) &= 0xFFFFFFFB
				sub_46ACE0(dword_5d4594_1046492, 10141, 10141, 1)
			} else {
				nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v12)), 1)
				dword_5d4594_1046532 = nox_xxx_guiServerPlayersLoad_456270(dword_5d4594_1046492)
				sub_46ACE0(dword_5d4594_1046492, 10141, 10141, 1)
			}
			nox_window_set_hidden((*gui.Window)(dword_5d4594_1046524), 1)
			return 1
		case 10160:
			v16 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a3), 396)))
			sub_46B120((*gui.Window)(unsafe.Pointer(a3)), nil)
			sub_46B120((*gui.Window)(unsafe.Pointer(a3)), (*gui.Window)(v16))
			if dword_5d4594_1046532 != nil {
				sub_456D60(1)
				dword_5d4594_1046532 = nil
			}
			if dword_5d4594_1046528 != nil {
				sub_4557D0(1)
				dword_5d4594_1046528 = nil
			}
			if dword_5d4594_1046536 != nil {
				sub_4AD820()
				dword_5d4594_1046540 = nil
			}
			sub_46ACE0(dword_5d4594_1046492, 10161, 10163, 1)
			if noxflags.HasGame(1) {
				sub_46ACE0(dword_5d4594_1046492, 10141, 10141, 0)
			}
			v17 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10196)))
			nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v17)), 1)
			nox_window_set_hidden((*gui.Window)(dword_5d4594_1046524), 0)
			return 1
		case 10161:
			sub_4593B0(1)
			return 1
		case 10162:
			sub_4593B0(2)
			return 1
		case 10163:
			sub_4593B0(0)
			return 1
		case 10330:
			if nox_xxx_CheckGameplayFlags_417DA0(4) {
				nox_xxx_toggleAllTeamFlags_418690(0)
				nox_server_teamsZzz_419030(1)
				sub_46AD20(dword_5d4594_1046508, 10331, 10333, 0)
				return 1
			} else {
				nox_xxx_wndGuiTeamCreate_4185B0()
				if nox_xxx_CheckGameplayFlags_417DA0(2) {
					sub_4181F0(0)
				} else {
					nox_xxx_toggleAllTeamFlags_418690(1)
				}
				sub_46AD20(dword_5d4594_1046508, 10331, 10333, 1)
				return 1
			}
		case 10331:
			if nox_xxx_CheckGameplayFlags_417DA0(2) {
				nox_xxx_UnsetGameplayFlags_417D70(2)
				nox_xxx_toggleAllTeamFlags_418690(1)
			} else {
				nox_xxx_toggleAllTeamFlags_418690(0)
				sub_418390()
			}
			return 1
		case 10332:
			sub_4181F0(1)
			return 1
		case 10333:
			if nox_xxx_CheckGameplayFlags_417DA0(1) {
				nox_xxx_UnsetGameplayFlags_417D70(1)
			} else {
				nox_xxx_SetGameplayFlag_417D50(1)
			}
			return 1
		default:
			return 1
		}
	}
	if a2 == 23 {
		return 0
	}
	if a2 != 16387 {
		return 1
	}
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, int32(a4))))
	v5 = sub_4165B0()
	if v4 == nil {
		return 0
	}
	if int32(uint16(int16(a3))) == 1 {
		if a4 == 10101 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*26)) = nox_color_white_2523948
			return 1
		}
		return 1
	}
	v7 = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v4)), 16413, 0, 0))
	nox_sprintf(&v41[0], internCStr("%S"), v7)
	if v41[0] == 0 {
		return 1
	}
	v8 = int32(libc.Atoi(libc.GoString(&v41[0])))
	if v8 < 0 {
		v8 = 0
	}
	if a4 == 10101 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*26)) = nox_color_rgb_4344A0(230, 165, 65)
		libc.StrCpy((*byte)(unsafe.Add(unsafe.Pointer(v5), 9)), &v41[0])
		nox_xxx_gameSetServername_40A440(&v41[0])
		return 1
	}
	if a4 == 10134 {
		*((*uint16)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(uint16(0))*27))) = uint16(int16(v8))
		sub_459D50(1)
		return 1
	}
	if a4 != 10135 {
		return 1
	}
	if v8 > math.MaxUint8 {
		*((*uint8)(unsafe.Pointer(&v8))) = math.MaxUint8
		nox_itow(math.MaxUint8, &WideCharStr[0], 10)
		nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v4)), 16414, uintptr(unsafe.Pointer(&WideCharStr[0])), math.MaxUint32)
	}
	*(*byte)(unsafe.Add(unsafe.Pointer(v5), 56)) = byte(int8(v8))
	sub_459D50(1)
	return 1
}
func sub_459880(a1 int32) int32 {
	var (
		v1 int16
		v2 *wchar2_t
		v4 *uint32
		v5 int32
		v6 uint32
	)
	v1 = int16(*(*uint16)(unsafe.Add(a1, 52)))
	if int32(v1)&0x20 != 0 {
		if int32(*(*uint8)(unsafe.Add(a1, 57))) == 0 && noxflags.HasGame(1) {
			nox_xxx_wnd_46ABB0(dword_5d4594_1046516, 1)
			nox_xxx_wnd_46ABB0(dword_5d4594_1046520, 1)
		}
		v2 = nox_strman_loadString_40F1D0(internCStr("Servopts.wnd:CaptureLimit"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 1900)
	} else {
		*((*uint8)(unsafe.Pointer(&v1))) = *(*uint8)(unsafe.Add(a1, 57))
		if int32(v1)&0x400 != 0 {
			if int32(*((*uint8)(unsafe.Pointer(&v1)))) == 0 && noxflags.HasGame(1) {
				nox_xxx_wnd_46ABB0(dword_5d4594_1046516, 1)
				nox_xxx_wnd_46ABB0(dword_5d4594_1046520, 1)
			}
			v2 = nox_strman_loadString_40F1D0(internCStr("Servopts.wnd:DeathLimit"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 1912)
		} else {
			if int32(*((*uint8)(unsafe.Pointer(&v1)))) == 0 && noxflags.HasGame(1) && !noxflags.HasGame(49152) {
				nox_xxx_wnd_46ABB0(dword_5d4594_1046516, 1)
				nox_xxx_wnd_46ABB0(dword_5d4594_1046520, 1)
			}
			v2 = nox_strman_loadString_40F1D0(internCStr("Servopts.wnd:KillLimit"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 1926)
		}
	}
	nox_wcscpy((*wchar2_t)(unsafe.Add(dword_5d4594_1046516, 108)), v2)
	sub_4580E0(a1)
	sub_459A40((*byte)(unsafe.Add(a1, 9)))
	if noxflags.HasGame(1) && !noxflags.HasGame(49152) {
		nox_xxx_wnd_46ABB0((*gui.Window)(dword_5d4594_1046500), bool2int32(int32(*(*uint8)(unsafe.Add(a1, 57))) == 0))
		nox_xxx_wnd_46ABB0(dword_5d4594_1046504, bool2int32(int32(*(*uint8)(unsafe.Add(a1, 57))) == 0))
	}
	v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10122)))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*9)))
	if int32(*(*uint8)(unsafe.Add(a1, 57))) != 0 {
		v6 = uint32(v5 | 4)
	} else {
		v6 = uint32(v5) & 0xFFFFFFFB
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*9)) = v6
	sub_453F70(unsafe.Add(a1, 24))
	sub_4535E0((*int32)(unsafe.Add(a1, 44)))
	return sub_4535F0(int32(*(*uint32)(unsafe.Add(a1, 48))))
}
func sub_459CD0() int32 {
	var (
		result int32
		v1     uint8
		v2     *wchar2_t
		v3     *uint32
		v4     int32
	)
	result = int32(dword_5d4594_1046492)
	if dword_5d4594_1046492 == nil {
		return result
	}
	if sub_40A740() != 0 || noxflags.HasGame(0x8000) {
		v1 = uint8(sub_417DE0())
	} else {
		v1 = nox_xxx_getTeamCounter_417DD0()
	}
	v4 = int32(v1)
	v2 = nox_strman_loadString_40F1D0(internCStr("NumTeamsMsg"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c"), 2071)
	nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1046364)), v2, v4)
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1046492, 10110)))
	result = int32(nox_window_call_field_94_fnc((*gui.Window)(unsafe.Pointer(v3)), 16385, uintptr(memmap.PtrOff(0x5D4594, 1046364)), math.MaxUint32))
	return result
}
