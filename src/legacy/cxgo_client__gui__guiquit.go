package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_wnd_quitMenu_825760 *gui.Window = nil

func Nox_xxx_menuGameOnButton_445840(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	var (
		a1     = (*uint32)(win.C())
		v3     int32
		v4     int32
		result int32
		v6     int32
		v7     int32
		v8     *byte
		v9     int32
		v10    int32
		v12    int32
		v13    *wchar2_t
		v14    int32
		v15    *wchar2_t
		v16    int32
		v17    int32
		v18    int32
		v19    *uint32
		v20    int32
		v21    int32
		v22    *wchar2_t
		v23    *wchar2_t
	)
	if a2 != 16391 {
		return 0
	}
	v3 = nox_xxx_wndGetID_46B0A0((*gui.Window)(unsafe.Pointer(a3)))
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
	switch v3 {
	case 9001:
		sub_445C40()
		sub_413A00(1)
		if !noxflags.HasGame(2048) || nox_xxx_playerAnimCheck_4372B0() != 0 {
			sub_445B40()
			v17 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
			*((*uint8)(unsafe.Pointer(&v17))) = uint8(int8(v17 & 0xFD))
			*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v17
			result = 0
		} else {
			v23 = nox_strman_loadString_40F1D0(internCStr("GUIQuit.c:ReallyLoadMessage"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guiquit.c"), 199)
			v15 = nox_strman_loadString_40F1D0(internCStr("SelChar.c:LoadLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guiquit.c"), 198)
			nox_xxx_dialogMsgBoxCreate_449A10(nil, (*wchar2_t)(unsafe.Pointer(v15)), (*wchar2_t)(unsafe.Pointer(v23)), 56, ccall.FuncAddr(sub_445B40), ccall.FuncAddr(sub_445BA0))
			v16 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
			*((*uint8)(unsafe.Pointer(&v16))) = uint8(int8(v16 & 0xFD))
			*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v16
			result = 0
		}
	case 9002:
		v18 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x852978, 8))), 120)))
		if (v18 & 0x8000) == 0 {
			sub_445C40()
			if noxflags.HasGame(2048) {
				nox_setSaveFileName_4DB130(internCStr("AUTOSAVE"))
				sub_4DB170(1, nil, 0)
			}
			v21 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
			*((*uint8)(unsafe.Pointer(&v21))) = uint8(int8(v21 & 0xFD))
			*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v21
			result = 0
			break
		}
		v19 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0((*gui.Window)(unsafe.Pointer(a1)), v3)))
		nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v19)), 0)
		v20 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
		*((*uint8)(unsafe.Pointer(&v20))) = uint8(int8(v20 & 0xFD))
		*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v20
		result = 0
	case 9003:
		sub_445C40()
		if noxflags.HasGame(2048) {
			nox_savegame_sub_46D580()
		} else {
			nox_xxx_netSavePlayer_41CE00()
		}
		if sub_43C6E0() != 0 {
			v21 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
			*((*uint8)(unsafe.Pointer(&v21))) = uint8(int8(v21 & 0xFD))
			*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v21
			result = 0
			break
		}
		sub_43CF70()
		v12 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
		*((*uint8)(unsafe.Pointer(&v12))) = uint8(int8(v12 & 0xFD))
		*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v12
		result = 0
	case 9004:
		nox_xxx_wndClearCaptureMain_46ADE0(nox_wnd_quitMenu_825760)
		v22 = nox_strman_loadString_40F1D0(internCStr("GUIQuit.c:ReallyQuitMessage"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guiquit.c"), 185)
		v13 = nox_strman_loadString_40F1D0(internCStr("GUIQuit.c:ReallyQuitTitle"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guiquit.c"), 184)
		nox_xxx_dialogMsgBoxCreate_449A10(nox_wnd_quitMenu_825760, (*wchar2_t)(unsafe.Pointer(v13)), (*wchar2_t)(unsafe.Pointer(v22)), 56, ccall.FuncAddr(nox_xxx_quitDialogYes_445B20), ccall.FuncAddr(nox_xxx_quitDialogNo_445B30))
		v14 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
		*((*uint8)(unsafe.Pointer(&v14))) = uint8(int8(v14 & 0xFD))
		*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v14
		result = 0
	case 9005:
		sub_445C40()
		sub_4ADA40()
		v4 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
		*((*uint8)(unsafe.Pointer(&v4))) = uint8(int8(v4 & 0xFD))
		*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v4
		result = 0
	case 9006:
		sub_445C40()
		v9 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
		*((*uint8)(unsafe.Pointer(&v9))) = uint8(int8(v9 & 0xFD))
		*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v9
		result = 0
	case 9007:
		if noxflags.HasGame(1) {
			v8 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(nox_player_netCode_85319C))))
			nox_xxx_serverHandleClientConsole_443E90((*server.Player)(unsafe.Pointer(v8)), 0, nil)
			sub_445C40()
			v9 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
			*((*uint8)(unsafe.Pointer(&v9))) = uint8(int8(v9 & 0xFD))
			*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v9
			result = 0
		} else {
			nox_xxx_netServerCmd_440950_empty()
			sub_445C40()
			v7 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
			*((*uint8)(unsafe.Pointer(&v7))) = uint8(int8(v7 & 0xFD))
			*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v7
			result = 0
		}
	case 9008:
		sub_445C40()
		nox_xxx_guiServerOptsLoad_457500()
		v10 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
		*((*uint8)(unsafe.Pointer(&v10))) = uint8(int8(v10 & 0xFD))
		*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v10
		result = 0
	case 9009:
		sub_445C40()
		if noxflags.HasGame(4096) {
			sub_48CB10(4)
		} else {
			sub_48CB10(0)
		}
		v6 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
		*((*uint8)(unsafe.Pointer(&v6))) = uint8(int8(v6 & 0xFD))
		*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v6
		result = 0
	default:
		v21 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9))
		*((*uint8)(unsafe.Pointer(&v21))) = uint8(int8(v21 & 0xFD))
		*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*9)) = v21
		result = 0
	}
	return uintptr(result)
}
func sub_445C40() {
	var (
		result int32
		v1     *uint32
		v2     *uint32
		v3     *uint32
		v4     *uint32
		v5     *uint32
		v6     *uint32
		v7     *uint32
		v8     *uint32
		v9     *uint32
		v10    *uint32
		v11    *uint32
		v12    *uint32
		v13    *uint32
		v14    *uint32
		v15    *uint32
		v16    *uint32
		v17    *uint32
		v18    *uint32
		v19    *uint32
		v20    *wchar2_t
		v21    *wchar2_t
	)
	if nox_xxx_wndGetFlags_46ADA0(int32(uintptr(unsafe.Pointer(nox_wnd_quitMenu_825760))))&0x10 != 0 {
		if *memmap.PtrUint32(0x852978, 8) == 0 || !noxflags.HasGame(2048) || (func() bool {
			result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x852978, 8))), 276)))
			return result != 2
		}()) && result != 1 && result != 51 {
			if sub_45D9B0() != 1 {
				if nox_xxx_checkGameFlagPause_413A50() != 1 {
					nox_xxx_clientPlaySoundSpecial_452D80(921, 100)
					nox_xxx_wndShowModalMB_46A8C0(nox_wnd_quitMenu_825760)
					nox_wnd_quitMenu_825760.Flags |= 8
					nox_xxx_wndSetCaptureMain_46ADC0(nox_wnd_quitMenu_825760)
					if noxflags.HasGame(2048) {
						v20 = nox_strman_loadString_40F1D0(internCStr("SoloSaveLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guiquit.c"), 396)
						v1 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9003)))
						sub_46AEE0(int32(uintptr(unsafe.Pointer(v1))), int32(uintptr(unsafe.Pointer(v20))))
						v2 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9001)))
						nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v2)), 0)
						v3 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9002)))
						nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v3)), 0)
						v4 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9007)))
						nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v4)), 1)
						v5 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9008)))
						nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v5)), 1)
						v6 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9009)))
						nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v6)), 1)
						v7 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9004)))
						nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(v7)), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*4))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*5))))
						sub_413A00(1)
						sub_46AB20((*uint32)(unsafe.Pointer(nox_wnd_quitMenu_825760)), 220, 285)
					} else {
						v21 = nox_strman_loadString_40F1D0(internCStr("MultiplayerSaveLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\guiquit.c"), 427)
						v8 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9003)))
						sub_46AEE0(int32(uintptr(unsafe.Pointer(v8))), int32(uintptr(unsafe.Pointer(v21))))
						v9 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9001)))
						nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v9)), 1)
						v10 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9002)))
						nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v10)), 1)
						v11 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9007)))
						nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v11)), 0)
						nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v11)), 1)
						v12 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9008)))
						nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v12)), 0)
						v13 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9009)))
						nox_window_set_hidden((*gui.Window)(unsafe.Pointer(v13)), 0)
						sub_46AEE0(int32(uintptr(unsafe.Pointer(v13))), int32(uintptr(memmap.PtrOff(0x5D4594, 825772))))
						if noxflags.HasGame(49152) || int32(nox_xxx_getTeamCounter_417DD0()) == 0 {
							nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v13)), 0)
						} else {
							nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v13)), 1)
						}
						v14 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9004)))
						nox_window_setPos_46A9B0((*gui.Window)(unsafe.Pointer(v14)), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*4))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*5))+45))
						sub_46AB20((*uint32)(unsafe.Pointer(nox_wnd_quitMenu_825760)), 220, 330)
						if noxflags.HasGame(4096) {
							v15 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9007)))
							nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v15)), 0)
							v16 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9003)))
							nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v16)), 0)
						}
						if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
							v17 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9007)))
							nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v17)), 0)
							v18 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9005)))
							nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v18)), 0)
							v19 = (*uint32)(unsafe.Pointer(nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, 9003)))
							nox_xxx_wnd_46ABB0((*gui.Window)(unsafe.Pointer(v19)), 0)
						}
					}
				}
			}
		}
	} else {
		nox_xxx_windowFocus_46B500(nil)
		nox_xxx_wndClearCaptureMain_46ADE0(nox_wnd_quitMenu_825760)
		nox_window_set_hidden(nox_wnd_quitMenu_825760, 1)
		f := -0x9
		nox_wnd_quitMenu_825760.Flags &= gui.StatusFlags(f)
		sub_413A00(0)
	}
}
