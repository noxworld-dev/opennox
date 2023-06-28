package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_cliShowHelpGui_49C560() {
	v0 := nox_strman_get_lang_code()
	if nox_xxx_guiFontHeightMB_43F320(nil) > 10 {
		v0 = 2
	}
	result := nox_new_window_from_file(*(**byte)(memmap.PtrOff(0x587000, uintptr(v0*4)+164512)), nox_xxx_wnd_49C760)
	dword_5d4594_1305680 = result
	if result != nil {
		sub_46B120(result, nil)
		nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_1305680)
		sub_46C690(dword_5d4594_1305680)
		nox_xxx_windowFocus_46B500(dword_5d4594_1305680)
		nox_window_setPos_46A9B0(dword_5d4594_1305680, (nox_win_width-dword_5d4594_1305680.SizeVal.X)/2, (nox_win_height-dword_5d4594_1305680.SizeVal.Y)/2)
		var v4 *wchar2_t
		var v7 *byte
		var v2 *gui.Window
		if noxflags.HasGame(1) {
			v2 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1305680, 4102)
			v6 := (*byte)(unsafe.Pointer(sub_42E8E0(45, 1)))
			v3 := nox_strman_loadString_40F1D0(internCStr("Sanchlp.wnd:Help"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\chathelp.c"), 85)
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304656)), v3, v6)
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304656)), internWStr(" "))
			v7 = (*byte)(unsafe.Pointer(sub_42E8E0(8, 1)))
			v4 = nox_strman_loadString_40F1D0(internCStr("cdecode.c:KeyToChat"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\chathelp.c"), 87)
		} else {
			v2 = nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_1305680, 4102)
			v8 := (*byte)(unsafe.Pointer(sub_42E8E0(45, 1)))
			v5 := nox_strman_loadString_40F1D0(internCStr("Sanchlp.wnd:ClientHelp"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\chathelp.c"), 94)
			nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304656)), v5, v8)
			nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304656)), internWStr(" "))
			v7 = (*byte)(unsafe.Pointer(sub_42E8E0(8, 1)))
			v4 = nox_strman_loadString_40F1D0(internCStr("cdecode.c:KeyToChat"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\chathelp.c"), 96)
		}
		nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304400)), v4, v7)
		nox_wcscat((*wchar2_t)(memmap.PtrOff(0x5D4594, 1304656)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1304400)))
		nox_window_call_field_94_fnc(v2, 16385, uintptr(memmap.PtrOff(0x5D4594, 1304656)), 0)
		if noxflags.HasGame(1) {
			if sub_459DA0() == 0 {
				nox_xxx_guiServerOptsLoad_457500()
			}
			sub_459D80(1)
		}
		if noxflags.HasGame(4096) || nox_xxx_isQuest_4D6F50() != 0 {
			sub_49C7A0()
		}
	}
}
