package opennox

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
extern void* dword_5d4594_1307292;
extern void* dword_5d4594_831236;
extern unsigned int dword_5d4594_831220;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern uint32_t dword_5d4594_831260;
int winMainMenuAnimOutStartFnc();
int winMainMenuAnimOutDoneFnc();
int nox_client_drawGeneralCallback_4A2200();
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

var (
	winMainMenu           *gui.Window
	winMainMenuAnimTop    *gui.Anim
	winMainMenuAnimBottom *gui.Anim
)

func sub_4A2490(win *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
	switch ev.(type) {
	case gui.WindowFocus:
		return gui.RawEventResp(1)
	}
	return nil
}

func sub_4A1A60() bool {
	v0 := newWindowFromFile(noxClient.GUI, "OptsBack.wnd", sub_4A1AA0)
	C.dword_5d4594_1307292 = unsafe.Pointer(v0.C())
	if v0 == nil {
		return false
	}
	v0.SetFunc93(sub4A18E0)
	return true
}

func sub_4A1AA0(a1 *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
	switch ev := ev.(type) {
	case *WindowEvent0x4005:
		clientPlaySoundSpecial(sound.SoundShellSelect, 100)
		return gui.RawEventResp(1)
	case *WindowEvent0x4007:
		if gui.AnimGlobalState() != gui.AnimOut && gui.AnimGlobalState() != gui.AnimIn || sub4D6F30() {
			v3 := ev.Win.ID() - 151
			if v3 != 0 {
				if v3 == 1 {
					if gameGetStateCode() == gameStateMainMenu {
						v6 := strMan.GetStringInFile("GUIQuit.c:ReallyQuitMessage", "C:\\NoxPost\\src\\client\\shell\\OptsBack.c")
						v4 := strMan.GetStringInFile("GUIQuit.c:ReallyQuitTitle", "C:\\NoxPost\\src\\client\\shell\\OptsBack.c")
						NewDialogWindow(asWindowP(C.dword_5d4594_1307292), v4, v6, 56, sub_4A19D0, nil)
					} else {
						if sub4D6F30() {
							sub_4D6F90(2)
						}
						if gameGetStateCode() == gameStateColorSelect {
							C.sub_4A7A60(1)
						}
						nox_game_checkStateSwitch_43C1E0()
					}
				}
			} else {
				if gameGetStateCode() == gameStateColorSelect {
					C.sub_4A7A60(0)
				}
				nox_game_checkStateOptions_43C220()
			}
			clientPlaySoundSpecial(sound.SoundShellClick, 100)
			return nil
		}
		return gui.RawEventResp(1)
	}
	return nil
}

func (c *Client) nox_xxx_wndLoadMainBG_4A2210() int {
	//uint32_t* v1;      // esi
	//const char* v2;    // eax
	//unsigned char* v3; // esi

	nox_client_gui_flag_815132 = 1
	gui.MainBg = newWindowFromFile(c.GUI, "MainBG.wnd", sub_4A2490)
	if !sub_4A1A60() {
		return 0
	}
	v1 := gui.MainBg.ChildByID(98)
	v1.SetFunc93(sub4A18E0)
	v1.SetDraw(gui.WrapDrawFuncC(C.sub_4A22A0))
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
	gui.FocusMainBg()
	return 1
}

//export winMainMenuAnimOutStartFnc
func winMainMenuAnimOutStartFnc() int {
	winMainMenuAnimTop.SetState(gui.AnimOut)
	winMainMenuAnimBottom.SetState(gui.AnimOut)
	gui.SetAnimGlobalState(gui.AnimOut)
	clientPlaySoundSpecial(sound.SoundShellSlideOut, 100)
	return 1
}

//export sub_44E320
func sub_44E320() {
	c := noxClient
	asWindowP(C.dword_5d4594_831236).Capture(false)
	c.GUI.Focus(nil)
	asWindowP(C.dword_5d4594_831236).Hide()
	sub_450580()
	sub_43DDA0()
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	if C.dword_5d4594_831220 == 255 {
		if nox_client_gui_flag_815132 == 1 {
			C.sub_4505E0()
			sub_4A2500()
			sub_578E00()
		}
	} else if memmap.Uint8(0x5D4594, 832472)&0x5 != 0 {
		C.nox_client_lockScreenBriefing_450160(254, 1, 2)
		return
	}
	v0 := int(nox_client_getIntroScreenDuration_44E3B0())
	c.r.FadeOutScreen(v0, true, func() {
		sub_450580()
		C.dword_5d4594_831260 = 0
		sub_413A00(0)
	})
}

func sub_4A2500() {
	setEnableFrameLimit(true)
	gui.MainBg.Show()
	winMainMenu.Show()
	gui.FocusMainBg()
}

func sub_4A2530() {
	setEnableFrameLimit(false)
	gui.MainBg.Hide()
	winMainMenu.Hide()
}

//export winMainMenuAnimOutDoneFnc
func winMainMenuAnimOutDoneFnc() int {
	ani := *winMainMenuAnimTop // copy
	winMainMenuAnimTop.Free()
	winMainMenuAnimTop = nil
	winMainMenuAnimBottom.Free()
	winMainMenuAnimBottom = nil
	winMainMenu.Destroy()
	winMainMenu = nil
	ani.Func13()
	return 1
}

//export sub_4A24C0
func sub_4A24C0(a1 C.int) C.int {
	sub4A24C0(a1 != 0)
	return 1
}

func sub4A24C0(a1 bool) {
	v1 := gui.MainBg.ChildByID(99)
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
	if nox_game_showMainMenu4A1C00() {
		return 1
	}
	return 0
}
func nox_game_showMainMenu4A1C00() bool {
	//uint32_t* v1; // esi
	//uint32_t* v2; // esi
	//uint32_t* v3; // eax

	sub_4D6F40(0)
	sub_4D6F90(0)
	gameAddStateCode(100)
	win := newWindowFromFile(noxClient.GUI, "MainMenu.wnd", nox_xxx_windowMainMenuProc_4A1DC0)
	if win == nil {
		return false
	}
	winMainMenu = win
	win.SetFunc93(sub4A18E0)
	v1 := win.ChildByID(110)
	v1.SetFunc94(nox_xxx_windowMainMenuProc_4A1DC0)
	winMainMenuAnimTop = nox_gui_makeAnimation(v1, 0, 0, 0, -270, 0, 20, 0, -40)
	if winMainMenuAnimTop == nil {
		return false
	}
	winMainMenuAnimTop.StateID = gameStateMainMenu
	_ = winMainMenuAnimOutStartFnc
	winMainMenuAnimTop.Func12Ptr = unsafe.Pointer(C.winMainMenuAnimOutStartFnc)
	_ = winMainMenuAnimOutDoneFnc
	winMainMenuAnimTop.FncDoneOutPtr = unsafe.Pointer(C.winMainMenuAnimOutDoneFnc)
	v2 := win.ChildByID(120)
	v2.SetFunc94(nox_xxx_windowMainMenuProc_4A1DC0)
	winMainMenuAnimBottom = nox_gui_makeAnimation(v2, 0, 270, 0, 510, 0, -20, 0, 40)
	if winMainMenuAnimBottom == nil {
		return false
	}
	sub4A19F0("OptsBack.wnd:Quit")
	nox_xxx_unknown_libname_11_4D1650()
	sub_578CD0()
	C.sub_43D9B0(25, 100)
	if noxflags.HasGame(noxflags.GameFlag26) {
		v3 := win.ChildByID(112)
		win.Func94(&WindowEvent0x4007{Win: v3})
	}
	return true
}

//export sub_43BE40
func sub_43BE40(a1 C.int) {
	gui.SetAnimGlobalState(gui.AnimState(a1))
}

//export sub_43BE30
func sub_43BE30() C.int {
	return C.int(gui.AnimGlobalState())
}

func sub_4A19D0() {
	nox_xxx_setContinueMenuOrHost_43DDD0(0)
	nox_client_gui_flag_815132 = 0
}

//export sub_4A18E0
func sub_4A18E0(a1, a2, a3, a4 C.int) C.int {
	res := sub4A18E0(asWindowP(unsafe.Pointer(uintptr(a1))), gui.AsWindowEvent(int(a2), uintptr(a3), uintptr(a4)))
	return C.int(gui.EventRespInt(res))
}

func sub4A18E0(a1 *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
	if sub_450560() {
		return gui.RawEventResp(1)
	}
	switch ev := ev.(type) {
	case gui.WindowKeyPress:
		if ev.Key != keybind.KeyEsc {
			return nil
		}
		if !ev.Pressed {
			return gui.RawEventResp(1)
		}
		if gui.AnimGlobalState() != gui.AnimInDone {
			if sub4D6F30() {
				sub_4D6F90(2)
			}
			return gui.RawEventResp(1)
		}
		if !sub44A4A0() {
			if gameGetStateCode() == gameStateServerList {
				sub_4373A0()
			} else if gameGetStateCode() == gameStateMainMenu {
				v6 := strMan.GetStringInFile("GUIQuit.c:ReallyQuitMessage", "C:\\NoxPost\\src\\client\\shell\\OptsBack.c")
				v5 := strMan.GetStringInFile("GUIQuit.c:ReallyQuitTitle", "C:\\NoxPost\\src\\client\\shell\\OptsBack.c")
				NewDialogWindow(asWindowP(C.dword_5d4594_1307292), v5, v6, 56, sub_4A19D0, nil)
			} else {
				if gameGetStateCode() == gameStateColorSelect {
					C.sub_4A7A60(1)
				}
				nox_game_checkStateSwitch_43C1E0()
			}
			if sub4D6F30() {
				sub_4D6F90(2)
			}
			return gui.RawEventResp(1)
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
	if err := noxClient.drawGeneral(false); err != nil {
		videoLog.Println(err)
		return 0
	}
	return 1
}

func nox_xxx_windowMainMenuProc_4A1DC0(a1 *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
	switch ev := ev.(type) {
	case *WindowEvent0x4005:
		clientPlaySoundSpecial(sound.SoundShellSelect, 100)
		return gui.RawEventResp(1)
	case *WindowEvent0x4007:
		if winMainMenuAnimTop.State() != gui.AnimInDone && !noxflags.HasGame(noxflags.GameFlag26) {
			clientPlaySoundSpecial(sound.SoundShellClick, 100)
			return gui.RawEventResp(1)
		}
		switch ev.Win.ID() {
		case 111: // Solo campaign button
			noxServer.announce = false
			if nox_xxx_checkHasSoloMaps() {
				noxflags.SetGame(noxflags.GameModeCoop)
				noxflags.UnsetGame(noxflags.GameOnline)
				noxflags.UnsetGame(noxflags.GameNotQuest)
				noxServer.ai.nox_xxx_gameSetAudioFadeoutMb(0)
				noxflags.UnsetEngine(noxflags.EngineAdmin | noxflags.EngineGodMode)
				sub_4D6F40(0)
				sub_4D6F90(0)
				noxServer.nox_xxx_setQuest_4D6F60(0)
				C.sub_4D6F80(0)
				C.nox_xxx_cliShowHideTubes_470AA0(0)
				C.sub_461440(0)
				winMainMenuAnimOutStartFnc()
				C.nox_xxx_cliSetMinimapZoom_472520(1110)
				if nox_xxx_parseGamedataBinPre_4D1630() == 0 {
					nox_xxx_setContinueMenuOrHost_43DDD0(0)
					nox_client_gui_flag_815132 = 0
					return nil
				}
				if C.nox_client_countSaveFiles_4DC550() != 0 {
					C.sub_4A7A70(1)
					_ = nox_game_showSelChar_4A4DB0
					winMainMenuAnimTop.Func13Ptr = unsafe.Pointer(C.nox_game_showSelChar_4A4DB0)
				} else {
					C.sub_4A7A70(0)
					winMainMenuAnimTop.Func13Ptr = unsafe.Pointer(C.nox_game_showSelClass_4A4840)
				}
				clientPlaySoundSpecial(sound.SoundShellClick, 100)
			} else {
				v9 := strMan.GetStringInFile("caution", "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c")
				v5 := strMan.GetStringInFile("solo", "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c")
				NewDialogWindow(winMainMenu, v5, v9, 33, nil, nil)
				sub_44A360(1)
				sub_44A4B0()
				clientPlaySoundSpecial(sound.SoundShellClick, 100)
			}
			return gui.RawEventResp(1)
		case 112: // Multiplayer button
			noxServer.announce = true
			// prepare to start a server
			winMainMenuAnimOutStartFnc()
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
			if nox_xxx_parseGamedataBinPre_4D1630() == 0 {
				nox_xxx_setContinueMenuOrHost_43DDD0(0)
				nox_client_gui_flag_815132 = 0
				return nil
			}
			winMainMenuAnimTop.Func13Ptr = unsafe.Pointer(C.nox_game_showGameSel_4379F0)
			sub_43AF50()
			clientPlaySoundSpecial(sound.SoundShellClick, 100)
		case 121:
			path, ok := nox_game_setMovieFile_4CB230("intro.vqa")
			if !ok {
				clientPlaySoundSpecial(sound.SoundShellClick, 100)
				break
			}
			winMainMenuAnimOutStartFnc()
			pushMovieFile(path)
			sub4B0640(func() {
				nox_game_state.Switch()
			})
			_ = nox_client_drawGeneralCallback_4A2200
			winMainMenuAnimTop.Func13Ptr = unsafe.Pointer(C.nox_client_drawGeneralCallback_4A2200)
			clientPlaySoundSpecial(sound.SoundShellClick, 100)
			return gui.RawEventResp(1)
		case 122:
			if C.sub_44E560() != nil {
				C.nox_client_lockScreenBriefing_450160(255, 1, 0)
				sub_4A2530()
			}
			ev.Win.DrawData().Field0 &= 0xFFFFFFFD
			clientPlaySoundSpecial(sound.SoundShellClick, 100)
		case 131: // Solo Quest
			noxServer.announce = false
			winMainMenuAnimOutStartFnc()
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
			if nox_xxx_parseGamedataBinPre_4D1630() == 0 {
				nox_xxx_setContinueMenuOrHost_43DDD0(0)
				nox_client_gui_flag_815132 = 0
				return nil
			}
			winMainMenuAnimTop.Func13Ptr = unsafe.Pointer(C.nox_game_showGameSel_4379F0)
			sub_43AF50()
			clientPlaySoundSpecial(sound.SoundShellClick, 100)
		default:
			clientPlaySoundSpecial(sound.SoundShellClick, 100)
		}
		return gui.RawEventResp(1)
	default:
		return nil
	}
}
