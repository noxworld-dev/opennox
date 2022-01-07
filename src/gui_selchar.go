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
#include "GAME3_2.h"
#include "GAME4.h"
#include "client__shell__noxworld.h"

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
extern uint32_t dword_5d4594_1563080;
extern uint32_t dword_5d4594_1563084;
extern uint32_t dword_5d4594_1563088;
extern uint32_t dword_5d4594_1563092;
extern uint32_t dword_5d4594_1563096;
extern uint32_t dword_5d4594_830872;
extern uint32_t dword_5d4594_830972;
extern uint32_t dword_5d4594_831224;
extern unsigned int dword_5d4594_251744;
extern unsigned int nox_game_createOrJoin_815048;
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
	"image"
	"io"
	"time"
	"unsafe"

	"nox/v1/common"
	"nox/v1/common/alloc"
	"nox/v1/common/datapath"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/log"
	"nox/v1/common/memmap"
)

const NOX_SAVEGAME_XXX_MAX = 14

var (
	saveLog = log.New("save")
)

//export sub_468480
func sub_468480(a1 C.int, a2 C.int, a3 C.int, a4 C.int) C.int {
	if a2 != 21 {
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
	win := newWindowFromFile("wolreg.wnd", C.sub_4685D0)
	C.dword_5d4594_1064816 = unsafe.Pointer(win.C())
	win.SetAllFuncs(C.sub_468480, nil, nil)
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
		C.sub_4A1BE0(1)
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
		C.sub_4A1BE0(1)
	}
}

//export sub_41E300
func sub_41E300(a1 C.int) C.int {
	if a1 == 11 && noxflags.HasGame(noxflags.GameFlag29) && sub_43C710() {
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

func sub_43C710() bool {
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

//export sub_413A00
func sub_413A00(a1 C.int) {
	if noxflags.HasGame(2048) {
		if a1 != 0 {
			noxflags.SetGame(0x40000)
		} else {
			if C.dword_5d4594_251744 == 0 {
				noxflags.UnsetGame(0x40000)
				nox_ticks_reset_416D40()
			}
		}
	}
}

//export sub_448640
func sub_448640() { sub_44A400() }

//export sub_43E200
func sub_43E200() C.int {
	C.sub_477530(0)
	C.nox_xxx_gui_43E1A0(0)
	nox_xxx_setContinueMenuOrHost_43DDD0(0)
	nox_game_exit_xxx_43DE60()
	sub_44A400()
	return 1
}

//export sub_43E230
func sub_43E230() C.int {
	C.sub_477530(0)
	noxflags.SetGame(noxflags.GameFlag21)
	sub_44A400()
	return 1
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

//export nox_savegame_findLatestSave_46CDC0
func nox_savegame_findLatestSave_46CDC0(sptr *C.nox_savegame_xxx) C.int {
	return C.int(nox_savegame_findLatestSave(unsafe.Slice(sptr, NOX_SAVEGAME_XXX_MAX)))
}

func nox_savegame_findLatestSave(sarr []C.nox_savegame_xxx) int {
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

//export sub_4DCE60
func sub_4DCE60(a1 C.int) {
	*memmap.PtrUint32(0x5D4594, 1563100) = uint32(a1)
}

//export sub_4DCE80
func sub_4DCE80(a1 *C.char) {
	sub4DCE80(GoString(a1))
}

func sub4DCE80(a1 string) {
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
	if !noxflags.HasGame(2048) {
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

//export sub_4505B0
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
	asWindow(C.dword_5d4594_1082856).Destroy()
	C.dword_5d4594_1082856 = nil
	C.dword_5d4594_1082864 = nil
	C.dword_5d4594_1082868 = nil
}

//export sub_46CC70
func sub_46CC70() C.int {
	C.sub_4DB130((*C.char)(memmap.PtrOff(0x5D4594, 1082840)))
	sub_4DB170(1, 0, 0)
	return C.sub_46D6F0()
}

//export sub_46CC90
func sub_46CC90() C.int {
	nox_xxx_wndSetCaptureMain_46ADC0(C.dword_5d4594_1082856)
	return 0
}

//export sub_46CCA0
func sub_46CCA0(a1, a2, a3, a4 C.int) C.int {
	return 1
}
