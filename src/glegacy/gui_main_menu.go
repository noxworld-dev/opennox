package legacy

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

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
)

var (
	WinMainMenuAnimOutStartFnc   func() int
	Sub_44E320                   func()
	WinMainMenuAnimOutDoneFnc    func() int
	Sub_4A24C0                   func(a1 int) int
	Nox_game_showMainMenu_4A1C00 func() int
	Sub_43BE40                   func(a1 int)
	Sub_43BE30                   func() int
	Sub_4A18E0                   func(a1 *gui.Window, a2, a3, a4 int) int
)

// winMainMenuAnimOutStartFnc
func winMainMenuAnimOutStartFnc() int { return WinMainMenuAnimOutStartFnc() }

// sub_44E320
func sub_44E320() { Sub_44E320() }

// winMainMenuAnimOutDoneFnc
func winMainMenuAnimOutDoneFnc() int { return WinMainMenuAnimOutDoneFnc() }

// sub_4A24C0
func sub_4A24C0(a1 int) int { return Sub_4A24C0(a1) }

// nox_game_showMainMenu_4A1C00
func nox_game_showMainMenu_4A1C00() int { return Nox_game_showMainMenu_4A1C00() }

// sub_43BE40
func sub_43BE40(a1 int) { Sub_43BE40(a1) }

// sub_43BE30
func sub_43BE30() int { return Sub_43BE30() }

// sub_4A18E0
func sub_4A18E0(a1 unsafe.Pointer, a2, a3, a4 int) int { return Sub_4A18E0(AsWindowP(a1), a2, a3, a4) }

// nox_client_drawGeneralCallback_4A2200
func nox_client_drawGeneralCallback_4A2200() int {
	if err := GetClient().DrawGeneral(false); err != nil {
		guiLog.Println(err)
		return 0
	}
	return 1
}

func Get_nox_client_drawGeneralCallback_4A2200() unsafe.Pointer {
	return unsafe.Pointer(nox_client_drawGeneralCallback_4A2200)
}

func Get_nox_game_showGameSel_4379F0() unsafe.Pointer {
	return unsafe.Pointer(nox_game_showGameSel_4379F0)
}

func Sub_461440(v int) {
	sub_461440(int(v))
}

func Sub_4D7440(v int) {
	sub_4D7440(int(v))
}

func Nox_xxx_cliSetMinimapZoom_472520(v int) {
	nox_xxx_cliSetMinimapZoom_472520(int(v))
}
func Nox_xxx_monsterListFree_5174F0() {
	nox_xxx_monsterListFree_5174F0()
}
func Nox_client_countSaveFiles_4DC550() int {
	return int(nox_client_countSaveFiles_4DC550())
}
func Sub_4A7A60(a1 int) {
	sub_4A7A60(int(a1))
}
func Nox_client_lockScreenBriefing_450160(a1 int, a2 int, a3 int) {
	nox_client_lockScreenBriefing_450160(int(a1), int(a2), char(a3))
}
func Sub_43E8C0(a1 int) {
	sub_43E8C0(int(a1))
}
func Sub_43D9B0(a1 int, a2 int) {
	sub_43D9B0(int(a1), int(a2))
}
func Sub_4D6F80(a1 int) {
	sub_4D6F80(int(a1))
}
func Sub_4A7A70(a1 int) {
	sub_4A7A70(int(a1))
}

func Get_nox_game_showSelChar_4A4DB0() unsafe.Pointer {
	return nox_game_showSelChar_4A4DB0
}
func Get_nox_game_showSelClass_4A4840() unsafe.Pointer {
	return nox_game_showSelClass_4A4840
}
func Get_winMainMenuAnimOutStartFnc() unsafe.Pointer {
	return winMainMenuAnimOutStartFnc
}
func Get_winMainMenuAnimOutDoneFnc() unsafe.Pointer {
	return winMainMenuAnimOutDoneFnc
}
func Get_sub_4A22A0() unsafe.Pointer {
	return sub_4A22A0
}
