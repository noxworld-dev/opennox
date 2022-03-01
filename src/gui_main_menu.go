package nox

/*
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME3.h"
#include "GAME3_2.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME5_2.h"
#include "client__shell__noxworld.h"
#include "client__shell__selchar.h"
#include "client__shell__mainmenu.h"
#include "client__video__draw_common.h"
extern void* dword_5d4594_1307292;
extern void* dword_5d4594_831236;
extern unsigned int dword_5d4594_831220;
extern unsigned int nox_client_gui_flag_815132;
extern unsigned int nox_game_createOrJoin_815048;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
int sub_4A1D40();
int sub_4A1D80();
*/
import "C"
import (
	"unsafe"

	"nox/v1/common/alloc"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/keybind"
	"nox/v1/common/memmap"
)

var (
	nox_win_main_bg     *Window
	nox_win_main_menu   *Window
	nox_wnd_xxx_1307304 *guiAnim
	nox_wnd_xxx_1307308 *guiAnim
)

func sub_4A2490(win *Window, ev WindowEvent) WindowEventResp {
	switch ev.(type) {
	case WindowFocus:
		return RawEventResp(1)
	}
	return nil
}

func sub_4A1A60() bool {
	v0 := newWindowFromFile("OptsBack.wnd", sub_4A1AA0)
	C.dword_5d4594_1307292 = unsafe.Pointer(v0.C())
	if v0 == nil {
		return false
	}
	v0.setFunc93(sub4A18E0)
	return true
}

func sub_4A1AA0(a1 *Window, ev WindowEvent) WindowEventResp {
	a2, a3p, _ := ev.EventArgsC()

	if a2 == 16389 {
		clientPlaySoundSpecial(920, 100)
		return RawEventResp(1)
	}
	if a2 != 16391 {
		return nil
	}
	if sub_43BE30() != 2 && sub_43BE30() != 3 || sub_4D6F30() != 0 {
		a3 := asWindowP(unsafe.Pointer(a3p))
		v3 := a3.ID() - 151
		if v3 != 0 {
			if v3 == 1 {
				if gameGetStateCode() == 100 {
					v6 := strMan.GetStringInFile("GUIQuit.c:ReallyQuitMessage", "C:\\NoxPost\\src\\client\\shell\\OptsBack.c")
					v4 := strMan.GetStringInFile("GUIQuit.c:ReallyQuitTitle", "C:\\NoxPost\\src\\client\\shell\\OptsBack.c")
					NewDialogWindow(asWindowP(C.dword_5d4594_1307292), v4, v6, 56, sub_4A19D0, nil)
				} else {
					if sub_4D6F30() != 0 {
						sub_4D6F90(2)
					}
					if gameGetStateCode() == 700 {
						C.sub_4A7A60(1)
					}
					nox_game_checkStateSwitch_43C1E0()
				}
			}
		} else {
			if gameGetStateCode() == 700 {
				C.sub_4A7A60(0)
			}
			nox_game_checkStateOptions_43C220()
		}
		clientPlaySoundSpecial(921, 100)
		return nil
	}
	return RawEventResp(1)
}

func nox_xxx_wndLoadMainBG_4A2210() int {
	//uint32_t* v1;      // esi
	//const char* v2;    // eax
	//unsigned char* v3; // esi

	C.nox_client_gui_flag_815132 = 1
	nox_win_main_bg = newWindowFromFile("MainBG.wnd", sub_4A2490)
	if !sub_4A1A60() {
		return 0
	}
	v1 := nox_win_main_bg.ChildByID(98)
	v1.setFunc93(sub4A18E0)
	v1.setDraw(wrapWindowDrawFuncC(C.sub_4A22A0))
	if memmap.Uint32(0x587000, 168832) != 0 {
		v3 := memmap.PtrOff(0x587000, 168832)
		v2 := *(**byte)(v3)
		for {
			*(*unsafe.Pointer)(unsafe.Add(v3, 4)) = unsafe.Pointer(nox_xxx_gLoadImg(GoStringP(unsafe.Pointer(v2))).C())
			v2 = *(**byte)(unsafe.Add(v3, 48))
			v3 = unsafe.Add(v3, 48)
			if v2 == nil {
				break
			}
		}
	}
	guiFocus(nox_win_main_bg)
	return 1
}

func sub_4A24F0() {
	guiFocus(nox_win_main_bg)
}

//export sub_4A1D40
func sub_4A1D40() C.int {
	nox_wnd_xxx_1307308.state = C.nox_gui_anim_state(NOX_GUI_ANIM_OUT)
	nox_wnd_xxx_1307304.state = C.nox_gui_anim_state(NOX_GUI_ANIM_OUT)
	sub_43BE40(2)
	clientPlaySoundSpecial(923, 100)
	return 1
}

//export sub_44E320
func sub_44E320() {
	nox_xxx_wndClearCaptureMain(asWindowP(C.dword_5d4594_831236))
	guiFocus(nil)
	asWindowP(C.dword_5d4594_831236).Hide()
	sub_450580()
	sub_43DDA0()
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	if C.dword_5d4594_831220 == 255 {
		if C.nox_client_gui_flag_815132 == 1 {
			C.sub_4505E0()
			sub_4A2500()
			C.sub_578E00()
		}
	} else if memmap.Uint8(0x5D4594, 832472)&0x5 != 0 {
		C.nox_client_lockScreenBriefing_450160(254, 1, 2)
		return
	}
	v0 := nox_client_getIntroScreenDuration_44E3B0()
	C.nox_client_screenFadeXxx_44DB30(v0, 1, (*[0]byte)(C.sub_44E3C0))
}

func sub_4A2500() {
	nox_xxx_setFrameLimit_43DDE0(1)
	nox_win_main_bg.Show()
	nox_win_main_menu.Show()
	sub_4A24F0()
}

//export sub_4A2530
func sub_4A2530() {
	nox_xxx_setFrameLimit_43DDE0(0)
	nox_win_main_bg.Hide()
	nox_win_main_menu.Hide()
}

//export sub_4A1D80
func sub_4A1D80() C.int {
	ani := *nox_wnd_xxx_1307308 // copy
	nox_wnd_xxx_1307308.Free()
	nox_wnd_xxx_1307308 = nil
	nox_wnd_xxx_1307304.Free()
	nox_wnd_xxx_1307304 = nil
	nox_win_main_menu.Destroy()
	nox_win_main_menu = nil
	ani.Func13()
	return 1
}

//export sub_4A24C0
func sub_4A24C0(a1 C.int) C.int {
	sub4A24C0(a1 != 0)
	return 1
}

func sub4A24C0(a1 bool) {
	v1 := nox_win_main_bg.ChildByID(99)
	if a1 {
		v1.Hide()
	} else {
		v1.Show()
	}
	if !a1 {
		C.sub_43E8C0(1)
	}
}

//export nox_game_showMainMenu_4A1C00
func nox_game_showMainMenu_4A1C00() C.int {
	//uint32_t* v1; // esi
	//uint32_t* v2; // esi
	//uint32_t* v3; // eax

	sub_4D6F40(0)
	sub_4D6F90(0)
	gameAddStateCode(100)
	win := newWindowFromFile("MainMenu.wnd", nox_xxx_windowMainMenuProc_4A1DC0)
	if win == nil {
		return 0
	}
	nox_win_main_menu = win
	win.setFunc93(sub4A18E0)
	v1 := win.ChildByID(110)
	v1.setFunc94(nox_xxx_windowMainMenuProc_4A1DC0)
	nox_wnd_xxx_1307308 = nox_gui_makeAnimation(v1, 0, 0, 0, -270, 0, 20, 0, -40)
	if nox_wnd_xxx_1307308 == nil {
		return 0
	}
	nox_wnd_xxx_1307308.field_0 = 100
	_ = sub_4A1D40
	nox_wnd_xxx_1307308.field_12 = (*[0]byte)(C.sub_4A1D40)
	_ = sub_4A1D80
	nox_wnd_xxx_1307308.fnc_done_out = (*[0]byte)(C.sub_4A1D80)
	v2 := win.ChildByID(120)
	v2.setFunc94(nox_xxx_windowMainMenuProc_4A1DC0)
	nox_wnd_xxx_1307304 = nox_gui_makeAnimation(v2, 0, 270, 0, 510, 0, -20, 0, 40)
	if nox_wnd_xxx_1307304 == nil {
		return 0
	}
	sub4A19F0("OptsBack.wnd:Quit")
	nox_xxx_unknown_libname_11_4D1650()
	C.sub_578CD0()
	C.sub_43D9B0(25, 100)
	if noxflags.HasGame(noxflags.GameFlag26) {
		v3 := win.ChildByID(112)
		win.Func94(asWindowEvent(0x4007, uintptr(unsafe.Pointer(v3.C())), 0))
	}
	return 1
}

//export sub_43BE40
func sub_43BE40(a1 C.int) {
	*memmap.PtrUint32(0x5D4594, 815204) = uint32(a1)
}

//export sub_43BE30
func sub_43BE30() C.int {
	return C.int(memmap.Uint32(0x5D4594, 815204))
}

func sub43BE30() bool {
	return memmap.Uint32(0x5D4594, 815204) != 0
}

func sub_4A19D0() {
	nox_xxx_setContinueMenuOrHost_43DDD0(0)
	C.nox_client_gui_flag_815132 = 0
}

//export sub_4A18E0
func sub_4A18E0(a1, a2, a3, a4 C.int) C.int {
	res := sub4A18E0(asWindowP(unsafe.Pointer(uintptr(a1))), asWindowEvent(int(a2), uintptr(a3), uintptr(a4)))
	return C.int(eventRespInt(res))
}

func sub4A18E0(a1 *Window, ev WindowEvent) WindowEventResp {
	if sub_450560() {
		return RawEventResp(1)
	}
	switch ev := ev.(type) {
	case WindowKeyPress:
		if ev.Key != keybind.KeyEsc {
			return nil
		}
		if !ev.Pressed {
			return RawEventResp(1)
		}
		if sub43BE30() {
			if sub_4D6F30() != 0 {
				sub_4D6F90(2)
			}
			return RawEventResp(1)
		}
		if !sub44A4A0() {
			if gameGetStateCode() == 10000 {
				sub_4373A0()
			} else if gameGetStateCode() == 100 {
				v6 := strMan.GetStringInFile("GUIQuit.c:ReallyQuitMessage", "C:\\NoxPost\\src\\client\\shell\\OptsBack.c")
				v5 := strMan.GetStringInFile("GUIQuit.c:ReallyQuitTitle", "C:\\NoxPost\\src\\client\\shell\\OptsBack.c")
				NewDialogWindow(asWindowP(C.dword_5d4594_1307292), v5, v6, 56, sub_4A19D0, nil)
			} else {
				if gameGetStateCode() == 700 {
					C.sub_4A7A60(1)
				}
				nox_game_checkStateSwitch_43C1E0()
			}
			if sub_4D6F30() != 0 {
				sub_4D6F90(2)
			}
			return RawEventResp(1)
		}
	}
	return nil
}

func nox_xxx_unknown_libname_11_4D1650() {
	nox_xxx_gamedataFree_419DB0()
	C.nox_xxx_monsterListFree_5174F0()
}

//export nox_client_drawGeneralCallback_4A2200
func nox_client_drawGeneralCallback_4A2200() C.int {
	return C.int(nox_client_drawGeneral_4B0340(0))
}

func nox_xxx_windowMainMenuProc_4A1DC0(a1 *Window, ev WindowEvent) WindowEventResp {
	a2, a3p, _ := ev.EventArgsC()
	if a2 == 16389 {
		clientPlaySoundSpecial(920, 100)
		return RawEventResp(1)
	}
	if a2 != 16391 {
		return nil
	}
	if guiAnimState(nox_wnd_xxx_1307308.state) != NOX_GUI_ANIM_IN_DONE && !noxflags.HasGame(noxflags.GameFlag26) {
		clientPlaySoundSpecial(921, 100)
		return RawEventResp(1)
	}
	a3 := asWindowP(unsafe.Pointer(a3p))
	switch a3.ID() {
	case 111: // Solo campaign button
		noxServer.announce = false
		if nox_xxx_checkHasSoloMaps() {
			noxflags.SetGame(noxflags.GameModeCoop)
			noxflags.UnsetGame(noxflags.GameOnline)
			noxflags.UnsetGame(noxflags.GameNotQuest)
			C.nox_xxx_gameSetAudioFadeoutMb_501AC0(0)
			noxflags.UnsetEngine(noxflags.EngineAdmin | noxflags.EngineGodMode)
			sub_4D6F40(0)
			sub_4D6F90(0)
			noxServer.nox_xxx_setQuest_4D6F60(0)
			C.sub_4D6F80(0)
			C.nox_xxx_cliShowHideTubes_470AA0(0)
			C.sub_461440(0)
			sub_4A1D40()
			C.nox_xxx_cliSetMinimapZoom_472520(1110)
			if C.nox_xxx_parseGamedataBinPre_4D1630() == 0 {
				nox_xxx_setContinueMenuOrHost_43DDD0(0)
				C.nox_client_gui_flag_815132 = 0
				return nil
			}
			if C.nox_client_countSaveFiles_4DC550() != 0 {
				C.sub_4A7A70(1)
				_ = nox_game_showSelChar_4A4DB0
				nox_wnd_xxx_1307308.field_13 = (*[0]byte)(C.nox_game_showSelChar_4A4DB0)
			} else {
				C.sub_4A7A70(0)
				nox_wnd_xxx_1307308.field_13 = (*[0]byte)(C.nox_game_showSelClass_4A4840)
			}
			clientPlaySoundSpecial(921, 100)
		} else {
			v9 := strMan.GetStringInFile("caution", "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c")
			v5 := strMan.GetStringInFile("solo", "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c")
			NewDialogWindow(nox_win_main_menu, v5, v9, 33, nil, nil)
			sub_44A360(1)
			sub_44A4B0()
			clientPlaySoundSpecial(921, 100)
		}
		return RawEventResp(1)
	case 112: // Multiplayer button
		noxServer.announce = true
		// prepare to start a server
		sub_4A1D40()
		noxflags.SetEngine(noxflags.EngineAdmin)
		noxflags.UnsetEngine(noxflags.EngineGodMode)
		noxflags.SetGame(noxflags.GameOnline)
		noxflags.SetGame(noxflags.GameNotQuest)
		noxflags.UnsetGame(noxflags.GameModeCoop)
		C.sub_461440(0)
		sub_4D6F40(0)
		sub_4D6F90(0)
		noxServer.nox_xxx_setQuest_4D6F60(0)
		C.sub_4D6F80(0)
		if sub_473670() == 0 {
			nox_client_toggleMap_473610()
		}
		C.nox_xxx_cliShowHideTubes_470AA0(0)
		C.nox_xxx_cliSetMinimapZoom_472520(2300)
		if C.nox_xxx_parseGamedataBinPre_4D1630() == 0 {
			nox_xxx_setContinueMenuOrHost_43DDD0(0)
			C.nox_client_gui_flag_815132 = 0
			return nil
		}
		// sub_4AA450();
		nox_wnd_xxx_1307308.field_13 = (*[0]byte)(C.nox_game_showGameSel_4379F0)
		C.sub_43AF50(0)
		clientPlaySoundSpecial(921, 100)
	case 121:
		ptr, free := alloc.Malloc(128)
		defer free()
		if !nox_game_setMovieFile_4CB230("Intro.vqa", (*C.char)(ptr)) {
			clientPlaySoundSpecial(921, 100)
			break
		}
		sub_4A1D40()
		C.sub_4B0300((*C.char)(ptr))
		sub4B0640(func() {
			nox_game_switchStates()
		})
		_ = nox_client_drawGeneralCallback_4A2200
		nox_wnd_xxx_1307308.field_13 = (*[0]byte)(C.nox_client_drawGeneralCallback_4A2200)
		clientPlaySoundSpecial(921, 100)
		return RawEventResp(1)
	case 122:
		if C.sub_44E560() != nil {
			C.nox_client_lockScreenBriefing_450160(255, 1, 0)
			sub_4A2530()
		}
		a3.DrawData().field_0 &= 0xFFFFFFFD
		clientPlaySoundSpecial(921, 100)
	case 131: // Solo Quest
		noxServer.announce = false
		sub_4A1D40()
		noxflags.SetEngine(noxflags.EngineAdmin)
		noxflags.UnsetEngine(noxflags.EngineGodMode)
		noxflags.SetGame(noxflags.GameOnline)
		noxflags.SetGame(noxflags.GameNotQuest)
		noxflags.UnsetGame(noxflags.GameModeCoop)
		sub_4D6F40(1)
		sub_4D6F90(1)
		noxServer.nox_game_setQuestStage_4E3CD0(0)
		C.sub_4D7440(0)
		C.nox_xxx_cliSetMinimapZoom_472520(2300)
		if sub_473670() == 0 {
			nox_client_toggleMap_473610()
		}
		C.sub_461440(0)
		if C.nox_xxx_parseGamedataBinPre_4D1630() == 0 {
			nox_xxx_setContinueMenuOrHost_43DDD0(0)
			C.nox_client_gui_flag_815132 = 0
			return nil
		}
		// sub_4AA450();
		nox_wnd_xxx_1307308.field_13 = (*[0]byte)(C.nox_game_showGameSel_4379F0)
		C.sub_43AF50(0)
		clientPlaySoundSpecial(921, 100)
	default:
		clientPlaySoundSpecial(921, 100)
	}
	return RawEventResp(1)
}
