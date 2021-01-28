package main

/*
#cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
#cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
#cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup
#cgo windows LDFLAGS: -lSDL2
#cgo linux freebsd darwin openbsd pkg-config: sdl2
#cgo CFLAGS: -DNOX_NO_MOUSE_GRAB
#cgo CFLAGS: -DNOX_CGO

#include <SDL2/SDL.h>
#include "memmap.h"
#include "proto.h"
#include "common/random.h"
#include "common/object/armrlook.h"
#include "common/object/weaplook.h"
#include "client/system/ctrlevnt.h"
#include "client/system/parsecmd.h"

extern unsigned int dword_5d4594_805860;
extern int g_fullscreen;
extern int g_scaled;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_win_width_1;
extern int nox_win_height_1;
extern int nox_win_depth_1;
extern int nox_win_width_2;
extern int nox_win_height_2;
extern int nox_win_depth_2;
extern int nox_video_dxFullScreen;
extern int nox_enable_audio;
extern int nox_video_dxUnlockSurface;
extern int nox_enable_threads;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern unsigned int nox_gameFPS;
extern unsigned int nox_profiled_805856;
extern unsigned int nox_xxx_useAudio_587000_80800;

extern unsigned int dword_5d4594_2650652;
extern unsigned int dword_5d4594_3804680;

extern int g_v20, g_v21;
extern int g_argc2;
extern char** g_argv2;

extern SDL_Window* g_window;

void init_data();
void cmain_loop(int);
void input_cleanup();
*/
import "C"
import (
	"errors"
	"flag"
	"fmt"
	"log"
	"net/http"
	_ "net/http/pprof"
	"os"
	"strings"
	"unsafe"

	_ "nox/client"
	_ "nox/common"
	_ "nox/comw32"
	_ "nox/server"

	"github.com/veandco/go-sdl2/sdl"
)

func init() {
	go func() {
		if err := http.ListenAndServe(":6060", nil); err != nil {
			log.Printf("failed to start pprof: %v", err)
		}
	}()
}

const (
	noxDefaultWidth  = C.NOX_DEFAULT_WIDTH
	noxDefaultHeight = C.NOX_DEFAULT_HEIGHT
)

var (
	noxWindow *sdl.Window
)

// Nox only works on 32bit
var _ = [1]struct{}{}[unsafe.Sizeof(int(0))-4]

func init() {
	C.init_data()
}

func main() {
	if err := run(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func CStringArray(arr []string) []*C.char {
	out := make([]*C.char, 0, len(arr)+1)
	for _, arg := range arr {
		out = append(out, C.CString(arg))
	}
	out = append(out, nil)
	return out[:len(arr):len(arr)]
}

func run() error { // aka WinMain
	args := []string{os.Args[0]}
	cmdline := strings.Join(os.Args[1:], " ")

	C.nox_xxx_gameResizeScreen_43BEF0_set_video_mode(0, 0, 0) // probably not needed

	for _, arg := range strings.Fields(cmdline) {
		switch arg {
		case "-window":
			C.nox_video_dxFullScreen = 0
			C.dword_5d4594_805860 = 0
			C.g_fullscreen = -2
		case "-swindow":
			C.nox_video_dxFullScreen = 0
			C.dword_5d4594_805860 = 1
			C.g_fullscreen = -3
		case "-fullscreen":
			C.g_fullscreen = -1
		case "-stretch":
			C.g_scaled = -1
		case "-minimize":
			*C.getMemU32Ptr(0x5D4594, 805864) = 1
		default:
			args = append(args, arg)
		}
	}
	if err := sdl.Init(sdl.INIT_VIDEO | sdl.INIT_TIMER | sdl.INIT_GAMECONTROLLER); err != nil {
		return fmt.Errorf("SDL Initialization failed: %w", err)
	}
	defer sdl.Quit()

	sdl.SetHint(sdl.HINT_RENDER_SCALE_QUALITY, "1")
	defer C.input_cleanup()

	win, err := sdl.CreateWindow("Nox Game Window", sdl.WINDOWPOS_UNDEFINED, sdl.WINDOWPOS_UNDEFINED,
		int32(C.nox_win_width), int32(C.nox_win_height), sdl.WINDOW_RESIZABLE)
	if err != nil {
		return fmt.Errorf("SDL Window creation failed: %w", err)
	}
	noxWindow = win
	C.g_window = (*C.SDL_Window)(win)

	return cmain(args)
}

func cmain(args []string) error {
	flags := flag.NewFlagSet("", flag.ContinueOnError)
	// TODO: add missing flag descriptions
	var (
		fServer     = flag.Bool("serveronly", false, "run the server only")
		fNoLimit    = flag.Bool("nolimit", false, "nolimit")
		fSleep      = flag.Bool("sleep", false, "sleep")
		fDrop       = flag.Int("drop", 0, "drop")
		fNoText     = flag.Bool("notext", false, "notext")
		fNoLog      = flag.Bool("nolog", false, "nolog")
		fLock       = flag.Bool("lock", false, "lock")
		fSafe       = flag.Bool("safe", false, "run in safe mode")
		fNoAudio    = flag.Bool("noaudio", false, "disable audio")
		fNoMMX      = flag.Bool("noMMX", false, "noMMX")
		fNoThreads  = flag.Bool("nothread", false, "nothread")
		fVol        = flag.Int("vol", -1, "vol")
		fNoFloor    = flag.Bool("noFloor", false, "noFloor")
		fNoDraw     = flag.Bool("noDraw", false, "noDraw")
		fPort       = flag.Int("port", 0, "port")
		fClientPort = flag.Int("clientport", 0, "clientport")
		fNoSoft     = flag.Bool("nosoft", false, "nosoft")
	)
	if err := flags.Parse(args[1:]); err != nil {
		return err
	}

	C.nox_init_ticks_func()
	*C.getMemU32Ptr(0x5D4594, 2650640) = 0
	*C.getMemU32Ptr(0x5D4594, 2618916) = 0
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	C.sub_43BDD0(10)
	C.nox_common_gameFlags_unset_40A540(-1)
	C.nox_xxx_setGameFlags_40A4D0(3)
	C.nox_common_setEngineFlag(C.NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE)
	C.dword_5d4594_2650652 = 0
	v2 := C.nox_common_gameFlags_check_40A5C0(1)
	C.nox_gameFPS = 30
	*C.getMemU32Ptr(0x5D4594, 2598000) = C.uint(v2)
	C.nox_ticks_xxx_416D40()
	if !*fServer {
		if C.nox_xxx_createMutexCheck_416A10() == 0 {
			return errors.New("create mutex failed")
		}
	}
	C.nox_xxx_setGameState_43DDF0(nil)
	C.nox_game_SetCliDrawFunc(nil)
	C.sub_43DE40(nil)
	C.nox_xxx_setGameFlags_40A4D0(256)
	if *fNoLimit {
		C.sub_43DDE0(0)
		*C.getMemU32Ptr(0x587000, 84) = 0
	}
	if *fServer {
		C.nox_enable_audio = 0
		C.nox_common_setEngineFlag(C.NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING | C.NOX_ENGINE_FLAG_31)
		C.nox_init_ticks_func()
	}
	if *fSleep {
		C.nox_common_setEngineFlag(C.NOX_ENGINE_FLAG_31)
	}
	if v := *fDrop; v != 0 {
		// TODO: can it be 0?
		C.sub_552010(C.int(v))
	}
	if *fNoText {
		C.nox_common_setEngineFlag(C.NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING)
	}
	if *fNoLog {
		C.sub_413C00()
	}
	if *fLock {
		C.nox_common_setEngineFlag(C.NOX_ENGINE_FLAG_26)
	}
	if *fSafe {
		C.nox_common_resetEngineFlag(C.NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE)
		C.nox_common_setEngineFlag(C.NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE)
		C.nox_enable_audio = 0
		C.nox_video_dxUnlockSurface = 1
		C.nox_xxx_useAudio_587000_80800 = 0
		*C.getMemU32Ptr(0x5D4594, 805840) = 1
		C.nox_enable_threads = 0
		depth := 16
		if C.sub_4300D0(1) == 0 {
			depth = 8
		}
		C.nox_win_width_1 = noxDefaultWidth
		C.nox_win_height_1 = noxDefaultHeight
		C.nox_win_depth_1 = C.int(depth)
		C.nox_win_width_2 = noxDefaultWidth
		C.nox_win_height_2 = noxDefaultHeight
		C.nox_win_depth_2 = C.int(depth)
	}
	if *fNoAudio {
		C.nox_enable_audio = 0
	}
	if *fNoMMX {
		C.nox_xxx_useAudio_587000_80800 = 0
		*C.getMemU32Ptr(0x5D4594, 805840) = 1
	}
	if *fNoThreads {
		C.nox_enable_threads = 0
	}
	if v := *fVol; v >= 0 {
		*C.getMemU8Ptr(0x587000, 88) = C.uchar(v)
	}
	if *fNoFloor {
		C.nox_common_setEngineFlag(C.NOX_ENGINE_FLAG_DISABLE_FLOOR_RENDERING)
	}
	if *fNoDraw {
		C.nox_common_setEngineFlag(C.NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)
	}
	if v := *fPort; v > 0 {
		C.nox_xxx_setPortParam_40A3E0(C.int(v))
	}
	if v := *fClientPort; v > 0 {
		C.nox_xxx_setClientNetPort_40A410(C.int(v))
	}
	if *fNoSoft {
		C.nox_common_resetEngineFlag(C.NOX_ENGINE_FLAG_12)
	}
	wd, err := os.Getwd()
	if err != nil {
		return fmt.Errorf("cannot get workdir: %w", err)
	}
	C.nox_common_set_data_path_409E20(C.CString(wd))
	// C.nox_common_readSKU_fromRegistry_4D78C0()
	C._controlfp(0x300, 0x300)
	C.nox_win_width = 0
	C.nox_xxx_servSetPlrLimit_409F80(32)
	*C.getMemU32Ptr(0x5D4594, 2614260) = C.nox_gameFPS >> 1
	C.sub_4093A0()
	C.nox_ensure_thing_bin()
	// should be .csf but it works anyway
	if C.nox_strman_readfile(C.CString("nox.str")) == 0 {
		return fmt.Errorf("failed to load strings file")
	}
	C.nox_common_scanAllMaps_4D07F0()
	C.sub_40AED0()
	C.nox_xxx_mapSetDataDefault_416500()
	if C.nox_common_readcfgfile(C.CString("nox.cfg"), 0) == 0 {
		return fmt.Errorf("failed to load config file")
	}
	if C.nox_profiled_805856 == 0 {
		C.sub_4445C0()
	}
	C.nox_xxx_clear18hDD_416190()
	C.nox_common_initRandom_415F70()
	C.nox_xxx_bindevent_42EAE0()
	C.nox_xxx_loadLook_415D50()
	C.nox_xxx_loadModifyers_4158C0()
	C.nox_xxx_cmdTokensLoad_4444F0()
	C.sub_4D11A0()
	C.nox_video_resizewnd(0, 0, 16)
	if C.nox_xxx_video_43BF10_upd_video_mode(1) == 0 {
		return fmt.Errorf("failed to update video mode")
	}
	C.nox_xxx_drawSelectColor_434350(*C.getMemIntPtr(0x5D4594, 2650656))
	C.sub_440900()
	if C.nox_video_read_videobag(C.int(C.dword_5d4594_3804680)) == 0 {
		return fmt.Errorf("failed to read videos")
	}
	if C.sub_431370() == 0 {
		return fmt.Errorf("sub_431370 failed")
	}
	if C.nox_audio_initall(C.nox_enable_audio) == 0 && C.nox_enable_audio != 0 {
		return fmt.Errorf("failed to init audio")
	}
	if !C.nox_xxx_loadAllBinFiles_415470() {
		return fmt.Errorf("failed to load bin files")
	}
	if C.nox_xxx_initInput_430190() == 0 {
		return fmt.Errorf("failed to init input")
	}
	if C.nox_xxx_mapAlloc_4101D0() == 0 {
		return fmt.Errorf("failed to init map")
	}
	if C.nox_xxx_tileAlloc_410F60_init() == 0 {
		return fmt.Errorf("failed to init tiles")
	}
	C.nox_xxx_initSinCosTables_414C90()
	C.nox_xxx_loadMapCycle_4D0A30()
	C.nox_xxx_mapSelectFirst_4D0E00()
	C.nox_xxx_netInitMsgBufs_40EA10()
	C.sub_40B890(32)
	C.sub_40B170(32)
	C.sub_4134D0()
	if v := C.nox_strman_get_lang_code(); v == 6 || v == 8 {
		C.sub_43F680(0)
	}
	C.sub_413920()
	if C.nox_client_initScreenParticles_431390() == 0 {
		return fmt.Errorf("failed to init particles")
	}
	C.sub_4147E0(C.int(uintptr(unsafe.Pointer(noxWindow)))) // TODO: fix argument type
	C.g_argc2 = C.int(len(args))
	C.g_argv2 = &CStringArray(args)[0]
	C.g_v20 = 0
	C.g_v21 = 0
	C.cmain_loop(0)
	return nil
}
