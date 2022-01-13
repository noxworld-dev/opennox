package nox

/*
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME4.h"
#include "client__shell__optsback.h"
#include "client__gui__servopts__guiserv.h"
#include "client__shell__noxworld.h"
#include "client__gui__guicon.h"
#include "client__gui__guibook.h"
#include "client__gui__guisave.h"
#include "client__shell__selchar.h"
#include "client__shell__mainmenu.h"

extern void* dword_5d4594_1307292;
extern uint32_t dword_5d4594_1064296;
extern void* dword_5d4594_1064816;
extern void* dword_5d4594_1064820;
extern void* dword_5d4594_1064824;
extern void* dword_5d4594_1064828;
extern void* dword_5d4594_814624;
extern uint32_t dword_5d4594_10984;
extern unsigned int dword_5d4594_527988;
extern uint32_t dword_5d4594_528256;
extern void* dword_5d4594_830224;
extern uint32_t dword_5d4594_830228;
extern void* dword_5d4594_830232;
extern void* dword_5d4594_830236;
extern uint32_t dword_5d4594_831220;
extern uint32_t dword_5d4594_831260;
extern uint32_t dword_5d4594_1563080;
extern uint32_t dword_5d4594_1563084;
extern uint32_t dword_5d4594_1563088;
extern uint32_t dword_5d4594_1563092;
extern uint32_t dword_5d4594_1563096;
extern unsigned int dword_5d4594_825768;
extern uint32_t dword_5d4594_830872;
extern uint32_t dword_5d4594_830972;
extern uint32_t dword_5d4594_831224;
extern unsigned int dword_5d4594_251744;
extern unsigned int nox_client_renderGUI_80828;
extern unsigned int nox_game_createOrJoin_815048;
extern unsigned int nox_xxx_xxxRenderGUI_587000_80832;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern nox_screenParticle* dword_5d4594_806052;
extern nox_screenParticle* nox_screenParticles_head;
extern void* nox_alloc_screenParticles_806044;
extern nox_window* dword_5d4594_1082856;
extern void* dword_5d4594_1082864;
extern void* dword_5d4594_1082868;
*/
import "C"
import (
	"encoding/binary"
	"fmt"
	"image"
	"io"
	"path/filepath"
	"sort"
	"strings"
	"time"
	"unsafe"

	"nox/v1/common"
	"nox/v1/common/alloc"
	"nox/v1/common/datapath"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/fs"
	"nox/v1/common/log"
	"nox/v1/common/memmap"
	"nox/v1/common/strman"
	"nox/v1/common/types"
	"nox/v1/server"
)

const NOX_SAVEGAME_XXX_MAX = 14

var (
	saveLog                   = log.New("save")
	nox_xxx_saves_arr         []C.nox_savegame_xxx
	nox_savegame_arr_1064948  [NOX_SAVEGAME_XXX_MAX]C.nox_savegame_xxx
	nox_savegame_name_1307752 string
	nox_wnd_xxx_1307748       *guiAnim
	winSelSave                *Window
	winCharList               *Window
	winCharListNames          *Window
	winCharListStyle          *Window
	dword_5d4594_1082856      *Window
	dword_5d4594_1082860      *Window
	dword_5d4594_1082864      *Window
	dword_5d4594_1082868      *Window
	dword_5d4594_1082880      *Window
)

//export sub_4A1BE0
func sub_4A1BE0(a1 C.int) C.int {
	return C.int(nox_xxx_wnd_46ABB0(asWindowP(C.dword_5d4594_1307292), int(a1)))
}

func sub_468480(win *Window, ev int, a3, a4 uintptr) uintptr {
	if ev != 21 {
		return 0
	}
	if a3 != 1 {
		return 0
	}
	if a4 == 2 {
		clientPlaySoundSpecial(231, 100)
		sub_4684C0()
	}
	return 1
}

//export sub_4683B0
func sub_4683B0() C.int {
	gameSetCliDrawFunc(func() bool {
		return C.sub_41E210() != 0
	})
	win := newWindowFromFile("wolreg.wnd", wrapWindowFuncC(C.sub_4685D0))
	C.dword_5d4594_1064816 = unsafe.Pointer(win.C())
	win.SetAllFuncs(sub_468480, nil, nil)
	C.dword_5d4594_1064820 = unsafe.Pointer(win.ChildByID(1755).C())
	C.dword_5d4594_1064824 = unsafe.Pointer(win.ChildByID(1756).C())
	C.dword_5d4594_1064828 = unsafe.Pointer(win.ChildByID(1754).C())
	v0 := win.ChildByID(1766)
	v0.DrawData().field_0 |= 4
	v1 := win.ChildByID(1767)
	v1.DrawData().field_0 |= 4
	C.dword_5d4594_1064296 = 0
	nox_xxx_wnd_46ABB0(win, 1)
	return 1
}

//export sub_4684C0
func sub_4684C0() {
	v0 := GUIChildByID(1700)
	switch C.dword_5d4594_1064296 {
	case 0:
		sub_41E300(5)
		C.sub_4207F0(1)
		nox_xxx_wnd_46ABB0(v0, 1)
		sub_4A1BE0(1)
		C.sub_4A1A40(0)
	case 1:
		C.dword_5d4594_1064296 = 0
		asWindowP(C.dword_5d4594_1064824).Hide()
		asWindowP(C.dword_5d4594_1064820).Show()
	case 2:
		C.dword_5d4594_1064296 = 0
		asWindowP(C.dword_5d4594_1064828).Hide()
		asWindowP(C.dword_5d4594_1064820).Show()
	case 3:
		C.dword_5d4594_1064296 = 1
		asWindowP(C.dword_5d4594_1064828).Hide()
		asWindowP(C.dword_5d4594_1064824).Show()
	case 4:
		sub_41E300(5)
		C.sub_4207F0(1)
		nox_xxx_wnd_46ABB0(v0, 1)
		sub_4A1BE0(1)
	}
}

//export sub_41E300
func sub_41E300(a1 C.int) C.int {
	if a1 == 11 && noxflags.HasGame(noxflags.GameFlag29) && checkFlag29() {
		if C.dword_5d4594_528256 != 0 {
			C.sub_41E470()
		} else {
			C.nox_xxx_reconStart_41E400()
		}
		return 0
	}
	if C.int(C.dword_5d4594_527988) != a1 {
		C.dword_5d4594_527988 = C.uint(a1)
		C.sub_41DA10(a1)
		if C.dword_5d4594_527988 == 11 {
			sub_40E0A0()
		}
	}
	return 1
}

//export sub_43C710
func sub_43C710() C.int {
	return C.int(bool2int(checkFlag29()))
}

func checkFlag29() bool {
	return noxflags.HasGame(noxflags.GameFlag29)
}

func sub_40E0A0() {
	C.dword_5d4594_10984 = 1
}

func sub_40E090() {
	C.dword_5d4594_10984 = 0
}

//export sub_43BE40
func sub_43BE40(a1 C.int) {
	*memmap.PtrUint32(0x5D4594, 815204) = uint32(a1)
}

//export sub_4A4CB0
func sub_4A4CB0(sv1, sv2 *C.nox_savegame_xxx) C.int {
	dt := asTime(&sv1.timestamp).Sub(asTime(&sv2.timestamp))
	if dt < 0 {
		return -1
	} else if dt > 0 {
		return +1
	}
	return 0
}

//export sub_4A50A0
func sub_4A50A0() C.int {
	nox_wnd_xxx_1307748.state = C.nox_gui_anim_state(NOX_GUI_ANIM_OUT)
	sub_43BE40(2)
	clientPlaySoundSpecial(923, 100)
	return 1
}

//export sub_4A50D0
func sub_4A50D0() C.int {
	v0 := nox_wnd_xxx_1307748.field_13
	nox_wnd_xxx_1307748.Free()
	nox_wnd_xxx_1307748 = nil
	winSelSave.Destroy()
	winSelSave = nil
	if v0 != nil {
		nox_cgo_call_intvoid((*[0]byte)(v0))
		return 1
	}
	nox_client_resetScreenParticles_431510()
	DrawGUI()
	if !noxflags.HasGame(noxflags.GameOnline) {
		nox_client_guiXxxDestroy_4A24A0()
		return 1
	}
	if C.nox_xxx_check_flag_aaa_43AF70() == 0 {
		nox_xxx_serverHost_43B4D0()
		return 1
	}
	if C.nox_xxx_check_flag_aaa_43AF70() == 1 {
		sub_43B670()
		return 1
	}
	return 1
}

func nox_xxx_particlesLoadColor_4313E0() {
	*memmap.PtrUint32(0x5D4594, 806012) = uint32(nox_color_rgb_4344A0(255, 255, 200))
	*memmap.PtrUint32(0x5D4594, 806004) = uint32(nox_color_rgb_4344A0(50, 150, 255))
	*memmap.PtrUint32(0x5D4594, 806036) = uint32(nox_color_rgb_4344A0(200, 255, 255))
	*memmap.PtrUint32(0x5D4594, 806024) = uint32(nox_color_rgb_4344A0(255, 200, 100))
	*memmap.PtrUint32(0x5D4594, 806040) = uint32(nox_color_rgb_4344A0(200, 255, 200))
	*memmap.PtrUint32(0x5D4594, 806020) = uint32(nox_color_rgb_4344A0(255, 255, 0))
	*memmap.PtrUint32(0x5D4594, 806028) = uint32(nox_color_rgb_4344A0(0, 0, 255))
	*memmap.PtrUint32(0x5D4594, 806016) = uint32(nox_color_rgb_4344A0(128, 128, 255))
	*memmap.PtrUint32(0x5D4594, 806008) = uint32(nox_color_rgb_4344A0(255, 128, 64))
	*memmap.PtrUint32(0x5D4594, 806032) = uint32(nox_color_rgb_4344A0(0, 255, 0))
}

func nox_client_initScreenParticles_431390() {
	if C.nox_alloc_screenParticles_806044 == nil {
		C.nox_alloc_screenParticles_806044 = alloc.NewClass("ScreenParticles", unsafe.Sizeof(C.nox_screenParticle{}), 2000).UPtr()
		if C.nox_alloc_screenParticles_806044 == nil {
			panic("cannot init particles")
		}
	}
	nox_client_resetScreenParticles_431510()
}

func nox_xxx_freeScreenParticles_4314D0() {
	if C.nox_alloc_screenParticles_806044 != nil {
		alloc.AsClass(C.nox_alloc_screenParticles_806044).Free()
	}
	C.nox_alloc_screenParticles_806044 = nil
	C.nox_screenParticles_head = nil
	C.dword_5d4594_806052 = nil
}

//export nox_client_resetScreenParticles_431510
func nox_client_resetScreenParticles_431510() {
	if C.nox_alloc_screenParticles_806044 != nil {
		alloc.AsClass(C.nox_alloc_screenParticles_806044).FreeAllObjects()
	}
	C.nox_screenParticles_head = nil
	C.dword_5d4594_806052 = nil
	nox_xxx_particlesLoadColor_4313E0()
}

//export sub_43B670
func sub_43B670() {
	v0 := sub_416640()
	if C.nox_game_createOrJoin_815048 != 0 {
		sub_44A400()
		C.nox_client_xxx_switchChatMap_43B510()
		C.nox_client_guiXxx_43A9D0()
		nox_client_guiXxxDestroy_4A24A0()
		C.nox_xxx_gameSetAudioFadeoutMb_501AC0(C.int(*(*uint32)(unsafe.Pointer(&v0[74]))))
	} else {
		C.sub_43B630()
		C.sub_40D350(C.int(*(*uint32)(unsafe.Add(C.dword_5d4594_814624, 32))))
	}
	C.sub_49FF20()
}

//export sub_46D6F0
func sub_46D6F0() C.int {
	nox_savegame_arr_1064948 = [NOX_SAVEGAME_XXX_MAX]C.nox_savegame_xxx{}
	win := dword_5d4594_1082856
	if win.Flags().IsHidden() {
		return 0
	}
	win.Hide()
	nox_xxx_wnd_46ABB0(win, 0)
	nox_xxx_wndClearCaptureMain_46ADE0(win.C())
	sub_413A00(0)
	return 1
}

//export sub_413A00
func sub_413A00(a1 C.int) {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		if a1 != 0 {
			noxflags.SetGame(noxflags.GamePause)
		} else {
			if C.dword_5d4594_251744 == 0 {
				noxflags.UnsetGame(noxflags.GamePause)
				nox_ticks_reset_416D40()
			}
		}
	}
}

//export sub_448640
func sub_448640() { sub_44A400() }

//export sub_43E200
func sub_43E200() C.int {
	sub_477530(0)
	C.nox_xxx_gui_43E1A0(0)
	nox_xxx_setContinueMenuOrHost_43DDD0(0)
	nox_game_exit_xxx_43DE60()
	sub_44A400()
	return 1
}

//export sub_43E230
func sub_43E230() C.int {
	sub_477530(0)
	noxflags.SetGame(noxflags.GameFlag21)
	sub_44A400()
	return 1
}

//export sub_477530
func sub_477530(a1 C.int) {
	if a1 == 1 {
		*memmap.PtrUint32(0x5D4594, 0x10BBCC) = uint32(C.nox_xxx_bookHideMB_45ACA0(0))
		*memmap.PtrUint32(0x5D4594, 0x10BBD8) = uint32(C.sub_467C10())
		*memmap.PtrUint32(0x5D4594, 1096660) = uint32(C.nox_xxx_guiServerOptionsTryHide_4574D0())
		C.nox_client_renderGUI_80828 = 0
		*memmap.PtrUint32(0x5D4594, 0x10BBD0) = uint32(C.sub_473670())
		if *memmap.PtrUint32(0x5D4594, 0x10BBD0) == 1 {
			C.nox_client_toggleMap_473610()
		}
		C.nox_gui_console_Hide_4512B0()
		C.sub_446780()
		C.sub_4AD9B0(1)
		C.sub_4C35B0(1)
		sub_46D6F0()
		C.sub_460660()
		*memmap.PtrUint32(0x5D4594, 0x10BBE0) = 1
	} else {
		*memmap.PtrUint32(0x5D4594, 0x10BBE0) = 0
		if *memmap.PtrUint32(0x5D4594, 0x10BBCC) != 0 {
			C.nox_xxx_bookShowMB_45AD70(0)
		}
		if *memmap.PtrUint32(0x5D4594, 0x10BBD8) != 0 {
			C.sub_467BB0()
		}
		if *memmap.PtrUint32(0x5D4594, 1096660) != 0 {
			C.nox_xxx_guiServerOptsLoad_457500()
		}
		if *memmap.PtrUint32(0x5D4594, 0x10BBD0) != 0 {
			C.nox_client_toggleMap_473610()
		}
		if C.nox_xxx_xxxRenderGUI_587000_80832 == 1 {
			C.nox_client_renderGUI_80828 = 1
		}
	}
}

//export sub_44A400
func sub_44A400() {
	if win1 := asWindowP(C.dword_5d4594_830224); win1 != nil {
		if C.dword_5d4594_830236 != nil {
			nox_xxx_wndSetCaptureMain_46ADC0(asWindowP(C.dword_5d4594_830236).C())
			C.dword_5d4594_830236 = nil
		}
		C.nox_xxx_wnd_46C6E0(win1.C())
		nox_xxx_wndClearCaptureMain_46ADE0(win1.C())
		win1.Destroy()
		if C.dword_5d4594_830232 != nil {
			guiFocus(asWindowP(C.dword_5d4594_830232))
		}
		C.dword_5d4594_830224 = nil
		C.dword_5d4594_830228 = 0
		nox_client_setCursorType_477610(0)

		setMouseBounds(image.Rect(0, 0, nox_win_width-1, nox_win_height-1))
	}
}

//export nox_game_showSelChar_4A4DB0
func nox_game_showSelChar_4A4DB0() C.int {
	nox_client_setCursorType_477610(0)
	if sub_4D6F30() != 0 {
		sub_4D6F90(1)
	}
	gameAddStateCode(500)
	sub_4A1BE0(1)
	win := newWindowFromFile("selchar.wnd", nox_xxx_windowSelCharProc_4A5710)
	winSelSave = win
	if win == nil {
		return 0
	}
	win.setFunc93(wrapWindowFuncC(C.sub_4A18E0))
	anim := nox_gui_makeAnimation(win, 0, 0, 0, -440, 0, 20, 0, -40)
	nox_wnd_xxx_1307748 = anim
	if anim == nil {
		return 0
	}
	anim.field_0 = 500
	anim.field_12 = (*[0]byte)(C.sub_4A50A0)
	anim.fnc_done_out = (*[0]byte)(C.sub_4A50D0)
	wlist := win.ChildByID(510)
	wnames := win.ChildByID(511)
	wstyle := win.ChildByID(512)
	winCharList = wlist
	winCharListNames = wnames
	winCharListStyle = wstyle
	wlist.setFunc94(nox_xxx_windowSelCharProc_4A5710)
	sub46B120(wnames, wlist)
	sub46B120(wstyle, wlist)
	if noxflags.HasGame(noxflags.GameModeCoop) {
		wup := win.ChildByID(504)
		wup.Hide()

		wdown := win.ChildByID(505)
		wdown.Hide()

		wblank := win.ChildByID(509)
		v8 := strMan.GetStringInFile("LoadLabel", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
		sub_46AEE0(wblank, v8)
	} else {
		wup := win.ChildByID(504)
		v1a := uintptr(unsafe.Pointer(wup))
		wlist.Func94(0x4018, v1a, 0)
		wnames.Func94(0x4018, v1a, 0)
		wstyle.Func94(0x4018, v1a, 0)

		wdown := win.ChildByID(505)
		v2a := uintptr(unsafe.Pointer(wdown))
		wlist.Func94(0x4019, v2a, 0)
		wnames.Func94(0x4019, v2a, 0)
		wstyle.Func94(0x4019, v2a, 0)

		wblank := win.ChildByID(509)
		v4 := strMan.GetStringInFile("LoadCharLabel", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
		sub_46AEE0(wblank, v4)
	}
	nox_xxx_findAutosaves_4A5150()
	sub_4A19F0("OptsBack.wnd:Back")
	if noxflags.HasGame(noxflags.GameOnline) {
		setEngineFlag(NOX_ENGINE_FLAG_ADMIN)
	} else {
		resetEngineFlag(NOX_ENGINE_FLAG_ADMIN)
		C.sub_4602F0()
	}
	if noxflags.HasGame(noxflags.GameFlag26) {
		wload := win.ChildByID(502)
		win.Func94(0x4007, uintptr(unsafe.Pointer(wload)), 0)
	}
	return 1
}

func nox_xxx_findAutosaves_4A5150() {
	wlist := winCharList
	wnames := winCharListNames
	wstyle := winCharListStyle
	v1 := winSelSave.ChildByID(501)
	nox_xxx_wnd_46ABB0(v1, 1)
	PathName := datapath.Save()
	fs.Mkdir(PathName)
	if noxflags.HasGame(noxflags.GameModeCoop) {
		p, _ := alloc.Calloc(NOX_SAVEGAME_XXX_MAX, unsafe.Sizeof(C.nox_savegame_xxx{}))
		nox_xxx_saves_arr = unsafe.Slice((*C.nox_savegame_xxx)(p), NOX_SAVEGAME_XXX_MAX)
		nox_savegame_sub_46CE40(wlist, wnames, wstyle, nox_xxx_saves_arr)
		return
	}
	fs.Chdir(PathName)
	files, _ := fs.ReadDir(PathName)
	v0 := 0
	for _, f := range files {
		if !f.IsDir() && strings.HasSuffix(f.Name(), ".plr") {
			v0++
		}
	}
	p, _ := alloc.Calloc(v0, unsafe.Sizeof(C.nox_savegame_xxx{}))
	nox_xxx_saves_arr = unsafe.Slice((*C.nox_savegame_xxx)(p), v0)
	v9 := 0
	for _, f := range files {
		if f.IsDir() || !strings.HasSuffix(f.Name(), ".plr") {
			continue
		}
		s := filepath.Join(PathName, f.Name())
		sv := &nox_xxx_saves_arr[v9]
		if C.sub_41A000(internCStr(s), sv) == 0 {
			saveLog.Printf("%q: failed", f.Name())
		}
		if sub_4A5690(sv) == 1 {
			v9++
		}
	}
	sort.Slice(nox_xxx_saves_arr[:v9], func(i, j int) bool {
		sv1, sv2 := &nox_xxx_saves_arr[i], &nox_xxx_saves_arr[j]
		return asTime(&sv1.timestamp).Before(asTime(&sv2.timestamp))
	})
	for i := 0; i < v9; i++ {
		sv := &nox_xxx_saves_arr[i]
		v28 := fmt.Sprintf("nox.str:%s", saveClasses[sv.player_class])
		v26 := strMan.GetStringInFile(strman.ID(v28), "C:\\NoxPost\\src\\client\\shell\\selchar.c")
		v24 := GoWString(&sv.player_name[0])
		v14 := strMan.GetStringInFile("GuiInv.c:ElaborateNameFormat", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
		v30 := fmt.Sprintf(v14, v24, v26)
		if sv.flags&0x4 != 0 {
			v15 := int(sv.stage)
			if v15 < 1 {
				v15 = 1
			}
			v30 += " - "
			v30 += strMan.GetStringInFile("Noxworld.c:Stage", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
			v30 += fmt.Sprintf(" %d", v15)
		}
		wlist.Func94(0x400D, uintptr(unsafe.Pointer(internWStr(" "))), 14)
		wstyle.Func94(0x400D, uintptr(unsafe.Pointer(internWStr(v30))), 14)
		var v25 string
		if sv.flags&0x4 != 0 {
			v25 = strMan.GetStringInFile("Noxworld.c:Quest", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
		} else {
			v25 = strMan.GetStringInFile("Multiplayer", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
		}
		wnames.Func94(0x400D, uintptr(unsafe.Pointer(internWStr(v25))), 14)
	}
	fs.Chdir(datapath.Path())
	if v9 != 0 {
		v21 := winSelSave.ChildByID(503)
		v22 := winSelSave.ChildByID(502)
		v20 := winSelSave.ChildByID(501)
		nox_xxx_wnd_46ABB0(v21, 1)
		nox_xxx_wnd_46ABB0(v22, 1)
		if (noxServer.nox_xxx_isQuest_4D6F50() || sub_4D6F70()) && nox_client_countPlayerFiles04_4DC7D0() >= 14 {
			nox_xxx_wnd_46ABB0(v20, 0)
		} else {
			nox_xxx_wnd_46ABB0(v20, 1)
		}
	} else {
		v21 := winSelSave.ChildByID(503)
		v22 := winSelSave.ChildByID(502)
		v23 := winSelSave.ChildByID(501)
		nox_xxx_wnd_46ABB0(v21, 0)
		nox_xxx_wnd_46ABB0(v22, 0)
		nox_xxx_wnd_46ABB0(v23, 1)
	}
	if int32(*(*uint16)(unsafe.Add(wnames.widget_data, 46))) != 0 { // TODO: check widget type
		wnames.Func94(0x4013, 0, 0)
		wstyle.Func94(0x4013, 0, 0)
	}
}

//export sub_4A5690
func sub_4A5690(sv *C.nox_savegame_xxx) C.int {
	if sv.flags&4 == 0 {
		if !noxServer.nox_xxx_isQuest_4D6F50() && !sub_4D6F70() {
			return 1
		}
		if sv.flags&4 == 0 {
			return 0
		}
	}
	if noxServer.nox_xxx_isQuest_4D6F50() || sub_4D6F70() {
		return 1
	}
	return 0
}

//export sub_4A5C70
func sub_4A5C70() C.int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		nox_savegame_rm(nox_savegame_name_1307752, true)
	} else {
		ind := memmap.Uint32(0x5D4594, 1307772)
		path := GoString(&nox_xxx_saves_arr[ind].path[0])
		fs.Remove(path)
	}
	winCharList.Func94(16399, 0, 0)
	winCharListNames.Func94(16399, 0, 0)
	winCharListStyle.Func94(16399, 0, 0)
	nox_xxx_findAutosaves_4A5150()
	return 1
}

var saveClasses = []string{
	"Warrior",
	"Wizard",
	"Conjurer",
}

func nox_savegame_sub_46CE40(wlist, wnames, wstyles *Window, sarr []C.nox_savegame_xxx) int {
	const stringsFile = "C:\\NoxPost\\src\\client\\Gui\\GUISave.c"
	PathName := datapath.Save()
	fs.Mkdir(PathName)
	wlist.Func94(0x400F, 0, 0)
	wnames.Func94(0x400F, 0, 0)
	wstyles.Func94(0x400F, 0, 0)
	v45 := filepath.Join(PathName, common.SaveAuto, common.PlayerFile)
	var v4 int32 = 0
	if C.sub_41A000(internCStr(v45), &sarr[0]) != 0 {
		v4++
	}
	for i := int32(1); i < NOX_SAVEGAME_XXX_MAX; i++ {
		v45 = filepath.Join(PathName, fmt.Sprintf(common.SaveFormat, i), common.PlayerFile)
		if C.sub_41A000(internCStr(v45), &sarr[i]) != 0 {
			v4++
		}
	}

	swin := dword_5d4594_1082856
	for v9 := 0; v9 < NOX_SAVEGAME_XXX_MAX; v9++ {
		sv := &sarr[v9]
		spath := GoString(&sv.path[0])
		if spath == "" {
			wlist.Func94(0x400D, uintptr(memmap.PtrOff(0x587000, 143900)), 3)
			str := " "
			if v9 != 0 {
				str = strMan.GetStringInFile("EmptySlot", stringsFile)
			}
			wnames.Func94(0x400D, uintptr(unsafe.Pointer(internWStr(str))), 3)
			wstyles.Func94(0x400D, uintptr(unsafe.Pointer(internWStr(str))), 3)
			continue
		}
		playerName := GoWString(&sv.player_name[0])
		sname := datapath.SaveNameFromPath(spath)
		class := int(sv.player_class)
		classNameID := fmt.Sprintf("nox.str:%s", saveClasses[class])
		v39 := strMan.GetStringInFile(strman.ID(classNameID), stringsFile)
		v13 := strMan.GetStringInFile("the", stringsFile)
		v42 := fmt.Sprintf(v13, playerName, v39)
		if sname == common.SaveAuto {
			v42 += " "
			v14 := strMan.GetStringInFile("AutoSaveLabel", stringsFile)
			v42 += v14
		} else {
			v42 += " - "
			var v17 string
			switch sv.stage {
			case 1:
				if class == 0 {
					v17 = strMan.GetStringInFile("WolChat.c:Nox_Lobby_3", stringsFile)
				} else if class != 1 {
					v17 = strMan.GetStringInFile("Noxworld.wnd:VillageIx", stringsFile)
				} else {
					v17 = strMan.GetStringInFile("NPC:Horvath", stringsFile)
				}
			case 2:
				if class == 0 {
					v17 = strMan.GetStringInFile("War02a.scr:Sign5", stringsFile)
				} else if class != 1 {
					v17 = strMan.GetStringInFile("NPC:Aldwyn", stringsFile)
				} else {
					v17 = strMan.GetStringInFile("Noxworld.wnd:Galava", stringsFile)
				}
			case 3:
				if class == 0 {
					v17 = strMan.GetStringInFile("Noxworld.wnd:VillageIx", stringsFile)
				} else if class != 1 {
					v17 = strMan.GetStringInFile("Noxworld.wnd:Mines", stringsFile)
				} else {
					v17 = strMan.GetStringInFile("WolChat.c:Nox_Lobby_9", stringsFile)
				}
			case 4:
				v17 = strMan.GetStringInFile("Noxworld.wnd:FieldValor", stringsFile)
			case 5:
				v17 = strMan.GetStringInFile("Noxworld.wnd:HamletBrin", stringsFile)
			case 6:
				v17 = strMan.GetStringInFile("NPC:Horrendous", stringsFile)
			case 7:
				v17 = strMan.GetStringInFile("Noxworld.wnd:Galava", stringsFile)
			case 8:
				v17 = strMan.GetStringInFile("Noxworld.wnd:TempleIx", stringsFile)
			case 9:
				v17 = strMan.GetStringInFile("Noxworld.wnd:DismalSwamp", stringsFile)
			case 10:
				v17 = strMan.GetStringInFile("Noxworld.wnd:LandDead", stringsFile)
			case 11:
				if class == 0 {
					v17 = strMan.GetStringInFile("WolChat.c:Nox_Lobby_47", stringsFile)
				} else if class == 1 {
					v17 = strMan.GetStringInFile("NPC:Hecubah", stringsFile)
				} else {
					v17 = strMan.GetStringInFile("Noxworld.wnd:GrokkTorr", stringsFile)
				}
			default:
				v17 = strMan.GetStringInFile("GuiInv.c:IdentifyUnknown", stringsFile)
			}
			v42 += v17
		}
		v21 := sub_46CD70(sv)
		stime := asTime(&sv.timestamp).Format("06-01-02, 15:04 ")
		wlist.Func94(0x400D, uintptr(unsafe.Pointer(internWStr(" "))), uintptr(v21))
		wstyles.Func94(0x400D, uintptr(unsafe.Pointer(internWStr(v42))), uintptr(v21))
		wnames.Func94(0x400D, uintptr(unsafe.Pointer(internWStr(stime))), uintptr(v21))
	}
	v22 := swin.ChildByID(503)
	v24 := swin.ChildByID(502)
	if v4 <= 0 {
		nox_xxx_wnd_46ABB0(v22, 0)
		nox_xxx_wnd_46ABB0(v24, 0)
	} else {
		nox_xxx_wnd_46ABB0(v22, 1)
		nox_xxx_wnd_46ABB0(v24, 1)
	}
	ind := nox_savegame_findLatestSave_46CDC0(sarr)
	if ind == -1 {
		return -1
	}
	wlist.Func94(0x4013, uintptr(ind), 0)
	wnames.Func94(0x4013, uintptr(ind), 0)
	wstyles.Func94(0x4013, uintptr(ind), 0)
	return ind
}

//export sub_46CD70
func sub_46CD70(sv *C.nox_savegame_xxx) C.int {
	return C.int(sub46CD70(sv))
}

func sub46CD70(sv *C.nox_savegame_xxx) int {
	if sv.flags&0x8 != 0 {
		return 10
	}
	buf := datapath.SaveNameFromPath(GoString(&sv.path[0]))
	return bool2int(buf != common.SaveAuto) + (NOX_SAVEGAME_XXX_MAX - 1)
}

func nox_savegame_findLatestSave_46CDC0(sarr []C.nox_savegame_xxx) int {
	var (
		ind    = -1
		latest time.Time
	)
	for i := 0; i < len(sarr); i++ {
		sv := &sarr[i]
		spath := GoString(&sv.path[0])
		if spath == "" {
			continue
		}
		t := asTime(&sv.timestamp)
		if ind == -1 || t.After(latest) {
			ind = i
			latest = t
		}
	}
	return ind
}

func asTime(ts *C.SYSTEMTIME) time.Time {
	if ts == nil {
		return time.Time{}
	}
	return time.Date(
		int(ts.wYear), time.Month(ts.wMonth), int(ts.wDay),
		int(ts.wHour), int(ts.wMinute), int(ts.wSecond),
		int(ts.wMilliseconds)*int(time.Millisecond),
		time.Local,
	)
}

func sub_4D6F70() bool {
	return memmap.Uint32(0x5D4594, 1556164) != 0
}

func sub_450560() bool {
	return C.dword_5d4594_831260 != 0
}

func sub_450570() bool {
	return C.dword_5d4594_831220 != 0
}

//export nox_savegame_sub_46D580
func nox_savegame_sub_46D580() {
	if noxflags.HasGame(noxflags.GameModeQuest) {
		return
	}
	nox_savegame_arr_1064948 = [NOX_SAVEGAME_XXX_MAX]C.nox_savegame_xxx{}
	nox_savegame_sub_46CE40(dword_5d4594_1082860, dword_5d4594_1082864, dword_5d4594_1082868, nox_savegame_arr_1064948[:])
	win1 := dword_5d4594_1082856
	nox_xxx_wndShowModalMB(win1)
	nox_xxx_wnd_46ABB0(win1, 1)
	nox_xxx_wndSetCaptureMain_46ADC0(win1.C())
	v1 := win1.ChildByID(501)
	if sub_450560() && !sub_450570() {
		nox_xxx_wnd_46ABB0(v1, 0)
	} else {
		v2 := *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 276))
		switch v2 {
		case 1, 2, 51:
			nox_xxx_wnd_46ABB0(v1, 0)
		default:
			nox_xxx_wnd_46ABB0(v1, 1)
		}
	}
	var (
		v4 *Window
		v5 string
	)
	if sub_450560() {
		v3 := strMan.GetStringInFile("SaveGUIQuit", "C:\\NoxPost\\src\\client\\Gui\\GUISave.c")
		sub_46AEE0(dword_5d4594_1082880, v3)
		v4 = win1.ChildByID(509)
		v5 = strMan.GetStringInFile("LoadLabel", "C:\\NoxPost\\src\\client\\Gui\\GUISave.c")
	} else {
		v6 := strMan.GetStringInFile("SaveGUICancel", "C:\\NoxPost\\src\\client\\Gui\\GUISave.c")
		sub_46AEE0(dword_5d4594_1082880, v6)
		v4 = win1.ChildByID(509)
		v5 = strMan.GetStringInFile("SaveLoadLabel", "C:\\NoxPost\\src\\client\\Gui\\GUISave.c")
	}
	sub_46AEE0(v4, v5)
	sub_413A00(1)
}

func nox_xxx_windowSelCharProc_4A5710(a1 *Window, ev int, a3w, a4 uintptr) uintptr {
	win := asWindowP(unsafe.Pointer(a3w))
	switch ev {
	case 0x2:
		if win.ID() == 500 {
			nox_xxx_saves_arr = nil
		}
		return 0
	case 0x4005:
		clientPlaySoundSpecial(920, 100)
		return 1
	case 0x4010:
		winCharList.Func94(0x4013, a4, 0)
		winCharListNames.Func94(0x4013, a4, 0)
		winCharListStyle.Func94(0x4013, a4, 0)
		return 0
	}
	if ev != 0x4007 {
		return 0
	}
	switch win.ID() {
	case 501:
		noxServer.SetFirstObjectScriptID(1000000000)
		sub_4A50A0()
		nox_wnd_xxx_1307748.field_13 = (*[0]byte)(C.nox_game_showSelClass_4A4840)
	case 502:
		v7 := winCharListNames.widget_data
		v10 := *(*int32)(unsafe.Add(v7, 48))
		if v10 == -1 {
			break
		}
		sv := &nox_xxx_saves_arr[v10]
		spath := GoString(&sv.path[0])
		if spath == "" {
			saveLog.Printf("save path is empty for slot %d", v10)
			clientPlaySoundSpecial(925, 100)
			clientPlaySoundSpecial(921, 100)
			return 1
		}
		v20 := datapath.SaveNameFromPath(spath)
		saveLog.Printf("loading slot %d: %q (%q, %q)", v10, v20, spath, GoString(&sv.map_name[0]))
		var v23 C.nox_savegame_xxx
		if (!noxflags.HasGame(noxflags.GameModeCoop) || nox_client_copySave(v20, common.SaveTmp) == nil) && C.sub_41A000(&sv.path[0], &v23) != 0 {

			v23d := (*C.nox_savegame_xxx)(memmap.PtrOff(0x85B3FC, 10980))
			*v23d = v23
			gamePopState()
			if int32(*memmap.PtrUint8(0x85B3FC, 0x2FDE)) == 0 {
				noxServer.nox_xxx_gameSetMapPath_409D70("war01a.map")
			} else if int32(*memmap.PtrUint8(0x85B3FC, 0x2FDE)) == 1 {
				noxServer.nox_xxx_gameSetMapPath_409D70("wiz01a.map")
			} else if int32(*memmap.PtrUint8(0x85B3FC, 0x2FDE)) == 2 {
				noxServer.nox_xxx_gameSetMapPath_409D70("con01a.map")
			}
			if noxflags.HasGame(noxflags.GameModeCoop) {
				C.nox_xxx_gameSetSwitchSolo_4DB220(1)
				C.nox_xxx_gameSetNoMPFlag_4DB230(1)
				mname := GoString(&sv.map_name[0])
				fbase := fmt.Sprintf("%s.map", mname)
				v22, err := nox_client_checkSaveMapExistsTmp(fbase)
				if err != nil {
					v22 = datapath.Maps(mname, fbase)
				}
				C.nox_xxx_gameSetSoloSavePath_4DB270(internCStr(v22))
				noxServer.nox_xxx_gameSetMapPath_409D70(fbase)
				nox_xxx_mapLoadOrSaveMB_4DCC70(1)
				v13, _ := sub41D090(GoString(&sv.path[0]))
				noxServer.SetFirstObjectScriptID(server.ObjectScriptID(v13))
			} else if sub_4D6F30() != 0 {
				sub_4DCE60(int(sv.stage))
				noxServer.sub_4DCE80(GoString(&sv.map_name[0]))
				v14, _ := sub41D090(GoString(&sv.path[0]))
				noxServer.SetFirstObjectScriptID(server.ObjectScriptID(v14))
			}
			C.sub_4A24C0(0)
			sub_4A50A0()
			nox_wnd_xxx_1307748.field_13 = nil
		}
	case 503:
		v7 := winCharListNames.widget_data
		v5 := *(*int32)(unsafe.Add(v7, 48))
		if v5 == -1 {
			break
		}
		sv := &nox_xxx_saves_arr[v5]
		spath := GoString(&sv.path[0])
		var (
			v17     unsafe.Pointer
			v16     int
			v6, v15 string
		)
		*memmap.PtrInt32(0x5D4594, 0x13F47C) = v5
		npath := datapath.SaveNameFromPath(spath)
		nox_savegame_name_1307752 = npath
		if noxflags.HasGame(noxflags.GameModeCoop) && nox_savegame_name_1307752 == common.SaveAuto {
			clientPlaySoundSpecial(925, 100)
			v17 = nil
			v16 = 33
			v15 = strMan.GetStringInFile("GUISave.c:AutoSaveDeleteNotAllowed", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
			v6 = strMan.GetStringInFile("GUISave.c:AutoSaveDeleteTitle", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
		} else {
			if spath == "" {
				clientPlaySoundSpecial(925, 100)
				clientPlaySoundSpecial(921, 100)
				return 1
			}
			v17 = C.sub_4A5C70
			v16 = 56
			if noxflags.HasGame(noxflags.GameModeCoop) {
				v15 = strMan.GetStringInFile("GUISave.c:DeleteSaveMessage", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
				v6 = strMan.GetStringInFile("GUISave.c:DeleteSaveTitle", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
			} else {
				v15 = strMan.GetStringInFile("GUISave.c:DeleteCharacterMessage", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
				v6 = strMan.GetStringInFile("GUISave.c:DeleteCharacterTitle", "C:\\NoxPost\\src\\client\\shell\\selchar.c")
			}
		}
		NewDialogWindow(nil, v6, v15, v16, v17, nil)
	case 504, 505:
		winCharList.Func94(0x4000, a3w, 0)
		winCharListNames.Func94(0x4000, a3w, 0)
		winCharListStyle.Func94(0x4000, a3w, 0)
	}
	clientPlaySoundSpecial(921, 100)
	return 1
}

func sub_4DCE60(a1 int) {
	*memmap.PtrUint32(0x5D4594, 1563100) = uint32(a1)
}

func (s *Server) sub_4DCE80(a1 string) {
	ptr := memmap.PtrOff(0x5D4594, 1563104)
	alloc.Memset(ptr, 0, 20)
	StrCopy((*C.char)(ptr), 20, a1)
}

//export sub_41D090
func sub_41D090(a1 *C.char) C.int {
	v, err := sub41D090(GoString(a1))
	if err != nil {
		saveLog.Println(err)
		return 0
	}
	return C.int(v)
}

func sub41D090(path string) (uint32, error) {
	if err := cryptFileOpen(path, 1, 27); err != nil {
		return 0, err
	}
	defer cryptFileClose()
	var buf [4]byte
	for {
		_, err := cryptFileReadWrite(buf[:4])
		if err == io.EOF {
			return 0, nil
		} else if err != nil {
			return 0, err
		}
		a1 := binary.LittleEndian.Uint32(buf[:])
		if a1 == 0 {
			return 0, nil
		}
		cryptFileReadMaybeAlign(buf[:4])
		v3 := binary.LittleEndian.Uint32(buf[:])
		if a1 == 10 {
			return sub_41D110()
		}
		nox_xxx_cryptSeekCur(int64(v3))
	}
}

func sub_41D110() (uint32, error) {
	if !noxflags.HasGame(noxflags.GameModeCoop) {
		return 0, nil
	}
	var buf [4]byte
	v2 := uint16(5)
	binary.LittleEndian.PutUint16(buf[:], v2)
	_, err := cryptFileReadWrite(buf[:2])
	v2 = binary.LittleEndian.Uint16(buf[:])
	if int16(v2) <= 5 && int16(v2) >= 5 {
		buf = [4]byte{}
		_, err = cryptFileReadWrite(buf[:4])
		v3 := binary.LittleEndian.Uint32(buf[:])
		return v3, err
	}
	return uint32(v2), err
}

func nox_savegame_sub_46C730() int {
	win := newWindowFromFile("selchar.wnd", nox_savegame_sub_46C920)
	dword_5d4594_1082856 = win
	if win == nil {
		return 0
	}
	win.flags |= 32
	dword_5d4594_1082856.setFunc93(func(win *Window, ev int, a1, a2 uintptr) uintptr {
		return 1
	})
	dword_5d4594_1082860 = dword_5d4594_1082856.ChildByID(510)
	dword_5d4594_1082864 = dword_5d4594_1082856.ChildByID(511)
	dword_5d4594_1082868 = dword_5d4594_1082856.ChildByID(512)
	dword_5d4594_1082860.setFunc94(nox_savegame_sub_46C920)
	sub46B120(dword_5d4594_1082864, dword_5d4594_1082860)
	sub46B120(dword_5d4594_1082868, dword_5d4594_1082860)
	swin1 := dword_5d4594_1082856.ChildByID(501)
	swin2 := dword_5d4594_1082856.ChildByID(502)
	dword_5d4594_1082880 = dword_5d4594_1082856.ChildByID(503)
	v1 := dword_5d4594_1082856.ChildByID(504)
	v1.Hide()
	v2 := dword_5d4594_1082856.ChildByID(505)
	v2.Hide()
	for i := uint(500); i <= 512; i++ {
		if v4 := dword_5d4594_1082856.ChildByID(i); v4 != nil {
			v4.flags |= 1024
		}
	}
	v5 := strMan.GetStringInFile("SaveGUISave", "C:\\NoxPost\\src\\client\\Gui\\GUISave.c")
	sub_46AEE0(swin1, v5)
	v6 := strMan.GetStringInFile("SaveGUILoad", "C:\\NoxPost\\src\\client\\Gui\\GUISave.c")
	sub_46AEE0(swin2, v6)
	dword_5d4594_1082856.SetPos(types.Point{
		X: (nox_win_width - dword_5d4594_1082856.Size().W) / 2,
	})
	dword_5d4594_1082856.Hide()
	nox_xxx_wnd_46ABB0(dword_5d4594_1082856, 0)
	return 1
}

func nox_savegame_sub_46C920(win1 *Window, a2 int, a3w, a4 uintptr) uintptr {
	if a2 != 0x4007 {
		if a2 != 16400 {
			return 0
		}
		dword_5d4594_1082860.Func94(0x4013, a4, 0)
		dword_5d4594_1082864.Func94(0x4013, a4, 0)
		dword_5d4594_1082868.Func94(0x4013, a4, 0)
		return 0
	}
	win3 := asWindowP(unsafe.Pointer(a3w))
	wid := win3.ID()
	clientPlaySoundSpecial(766, 100)
	if wid == 501 {
		v8 := *(*int32)(unsafe.Add(dword_5d4594_1082864.widget_data, 48))
		if v8 < 0 {
			return 0
		}
		v9 := *(*uint32)(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x852978, 8) + 120)))
		if (v9 & 0x8000) != 0 {
			v10 := win1.ChildByID(501)
			nox_xxx_wnd_46ABB0(v10, 0)
			return 0
		}
		if GoString(&nox_savegame_arr_1064948[v8].path[0]) != "" {
			path := datapath.SaveNameFromPath(GoString(&nox_savegame_arr_1064948[v8].path[0]))
			StrCopy((*C.char)(memmap.PtrOff(0x5D4594, 1082840)), 16, path)
			nox_xxx_wndClearCaptureMain_46ADE0(dword_5d4594_1082856.C())
			v13 := strMan.GetStringInFile("GUISave.c:OverwriteSaveMessage", "C:\\NoxPost\\src\\client\\Gui\\GUISave.c")
			v11 := strMan.GetStringInFile("GUISave.c:OverwriteSaveTitle", "C:\\NoxPost\\src\\client\\Gui\\GUISave.c")
			NewDialogWindow(dword_5d4594_1082856, v11, v13, 56, C.sub_46CC70, C.sub_46CC90)
			return 0
		}
		var v14 string
		if v8 != 0 {
			v14 = fmt.Sprintf(common.SaveFormat, v8)
		} else {
			v14 = common.SaveAuto
		}
		sub_4DB130(v14)
		sub_4DB170(1, 0, 0)
		sub_46D6F0()
		return 0
	} else if wid == 502 {
		v6 := *(*int32)(unsafe.Add(dword_5d4594_1082864.widget_data, 48))
		if v6 >= 0 && GoString(&nox_savegame_arr_1064948[v6].path[0]) != "" {
			if C.nox_xxx_playerAnimCheck_4372B0() != 0 {
				nox_savegame_sub_46CBD0()
				return 0
			}
			v12 := strMan.GetStringInFile("GUIQuit.c:ReallyLoadMessage", "C:\\NoxPost\\src\\client\\Gui\\GUISave.c")
			v7 := strMan.GetStringInFile("SelChar.c:LoadLabel", "C:\\NoxPost\\src\\client\\Gui\\GUISave.c")
			NewDialogWindow(nil, v7, v12, 24, C.nox_savegame_sub_46CBD0, C.sub_44A400)
			return 0
		}
		clientPlaySoundSpecial(925, 100)
		return 0
	} else if wid == 503 {
		if sub_450560() {
			sub_450580()
			sub_43DDA0()
			nox_xxx_setContinueMenuOrHost_43DDD0(0)
			nox_game_exit_xxx_43DE60()
			sub_446060()
			sub_46D6F0()
			return 0
		}
		sub_46D6F0()
		return 0
	}
	return 0
}

//export nox_savegame_sub_46CBD0
func nox_savegame_sub_46CBD0() C.int {
	i := *(*int32)(unsafe.Add(dword_5d4594_1082864.widget_data, 48))
	if GoString(&nox_savegame_arr_1064948[i].path[0]) == "" {
		return 0
	}
	v3 := datapath.SaveNameFromPath(GoString(&nox_savegame_arr_1064948[i].path[0]))
	if sub4DB790(v3) == 0 {
		v1 := strMan.GetStringInFile("SaveErrorTitle", "C:\\NoxPost\\src\\client\\Gui\\GUISave.c")
		NewDialogWindow(nil, v1, v1, 33, nil, nil)
	}
	if sub_450560() {
		sub_4505B0()
	}
	sub_44A400()
	return sub_46D6F0()
}

func sub_446060() {
	C.dword_5d4594_825768 = 0
}

func sub_4505B0() {
	sub_450580()
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	v0 := nox_client_getIntroScreenDuration_44E3B0()
	C.nox_client_screenFadeTimeout_44DAB0(v0, 1, (*[0]byte)(C.sub_44E320))
	C.nox_gameDisableMapDraw_5d4594_2650672 = 1
}

//export sub_43DDA0
func sub_43DDA0() {
	*memmap.PtrUint32(0x5D4594, 816344) = 0
	C.sub_43D9E0((*C.int4)(memmap.PtrOff(0x5D4594, 816060)))
}

//export sub_450580
func sub_450580() {
	sub_44D8F0()
	*memmap.PtrUint32(0x5D4594, 832488) = 1
	C.dword_5d4594_831224 = 0
	*memmap.PtrUint32(0x5D4594, 831292) = 0
	*memmap.PtrUint32(0x5D4594, 831296) = 0
}

func sub_4DB130(a1 string) {
	StrCopyP(memmap.PtrOff(0x5D4594, 1557900), len(a1)+1, a1)
}

//export sub_4DB170
func sub_4DB170(a1, a2, a3 C.int) {
	C.dword_5d4594_1563092 = C.uint(a3)
	C.dword_5d4594_1563088 = C.uint(gameFrame())
	C.dword_5d4594_1563084 = C.uint(a2)
	C.dword_5d4594_1563080 = C.uint(a1)
	C.dword_5d4594_1563096 = C.uint(bool2int(a2 != 0))
	if a1 == 0 {
		sub_4DCBD0(0)
	}
}

func sub_4DCBD0(a1 int) {
	*memmap.PtrUint32(0x5D4594, 1563076) = uint32(a1)
}

//export sub_44D8F0
func sub_44D8F0() {
	C.dword_5d4594_830872 = 0
	C.dword_5d4594_830972 = 0
}

//export nox_savegame_nameFromPath_4DC970
func nox_savegame_nameFromPath_4DC970(src, dst *C.char, max C.int) {
	name := datapath.SaveNameFromPath(GoString(src))
	StrCopy(dst, int(max), name)
}

func sub_46CCB0() {
	dword_5d4594_1082856.Destroy()
	dword_5d4594_1082856 = nil
	dword_5d4594_1082864 = nil
	dword_5d4594_1082868 = nil
}

//export sub_46CC70
func sub_46CC70() C.int {
	sub_4DB130(GoStringP(memmap.PtrOff(0x5D4594, 1082840)))
	sub_4DB170(1, 0, 0)
	return sub_46D6F0()
}

//export sub_46CC90
func sub_46CC90() C.int {
	nox_xxx_wndSetCaptureMain_46ADC0(dword_5d4594_1082856.C())
	return 0
}
