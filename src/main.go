package main

/*
#cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
#cgo windows LDFLAGS: -lSDL2 -lws2_32
#cgo linux LDFLAGS: -lm
#cgo linux freebsd darwin openbsd pkg-config: sdl2
#cgo CFLAGS: -DNOX_CGO

#include <fenv.h>
#include <SDL2/SDL.h>
#include "proto.h"
#include "common__object__armrlook.h"
#include "common__object__weaplook.h"
#include "client__system__ctrlevnt.h"
#include "client__system__parsecmd.h"

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

extern SDL_Window* g_window;

void init_data();
*/
import "C"
import (
	"flag"
	"fmt"
	"log"
	"net/http"
	_ "net/http/pprof"
	"nox/common/memmap"
	"nox/common/types"
	"os"
	"unsafe"

	"github.com/veandco/go-sdl2/sdl"
)

const noxVersionStr = "1.2g"

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
	noxWindow   *sdl.Window
	noxDataPath string
)

// Nox only works on 32bit
var _ = [1]struct{}{}[unsafe.Sizeof(int(0))-4]

func main() {
	if err := run(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func run() error { // aka WinMain
	C.init_data()
	nox_xxx_gameResizeScreen_43BEF0_set_video_mode(0, 0, 0) // probably not needed
	if err := sdl.Init(sdl.INIT_VIDEO | sdl.INIT_TIMER | sdl.INIT_GAMECONTROLLER); err != nil {
		return fmt.Errorf("SDL Initialization failed: %w", err)
	}
	defer sdl.Quit()

	sdl.SetHint(sdl.HINT_RENDER_SCALE_QUALITY, "1")
	defer inputCleanup()

	win, err := sdl.CreateWindow("Nox Game Window", sdl.WINDOWPOS_UNDEFINED, sdl.WINDOWPOS_UNDEFINED,
		int32(C.nox_win_width), int32(C.nox_win_height), sdl.WINDOW_RESIZABLE)
	if err != nil {
		return fmt.Errorf("SDL Window creation failed: %w", err)
	}
	noxWindow = win
	C.g_window = (*C.SDL_Window)(win)

	return cmain(os.Args)
}

func cmain(args []string) error {
	flags := flag.NewFlagSet("", flag.ContinueOnError)
	// TODO: add missing flag descriptions
	var (
		fServer     = flag.Bool("serveronly", false, "run the server only")
		fWindow     = flag.Bool("window", false, "window")
		fSWindow    = flag.Bool("swindow", false, "swindow")
		fFullScreen = flag.Bool("fullscreen", false, "fullscreen")
		fStretch    = flag.Bool("stretch", false, "stretch")
		fMinimize   = flag.Bool("minimize", false, "minimize")
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
	if *fWindow {
		C.nox_video_dxFullScreen = 0
		C.dword_5d4594_805860 = 0
		C.g_fullscreen = -2
	}
	if *fSWindow {
		C.nox_video_dxFullScreen = 0
		C.dword_5d4594_805860 = 1
		C.g_fullscreen = -3
	}
	if *fFullScreen {
		C.g_fullscreen = -1
	}
	if *fStretch {
		C.g_scaled = -1
	}
	if *fMinimize {
		*memmap.PtrUint32(0x5D4594, 805864) = 1
	}

	// static, don't need this
	//C.nox_init_ticks_func()
	*memmap.PtrUint32(0x5D4594, 2650640) = 0
	*memmap.PtrUint32(0x5D4594, 2618916) = 0
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	C.sub_43BDD0(10)
	unsetGameFlag(GameFlag_ALL)
	setGameFlag(3)
	setEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE)
	C.dword_5d4594_2650652 = 0
	v2 := getGameFlag(1)
	C.nox_gameFPS = 30
	*memmap.PtrUint32(0x5D4594, 2598000) = uint32(bool2int(v2))
	nox_ticks_xxx_416D40()
	// does nothing on SDL
	//if !*fServer {
	//	if C.nox_xxx_createMutexCheck_416A10() == 0 {
	//		return errors.New("create mutex failed")
	//	}
	//}
	C.nox_xxx_setGameState_43DDF0(nil)
	C.nox_game_SetCliDrawFunc(nil)
	C.sub_43DE40(nil)
	setGameFlag(256)
	if *fNoLimit {
		C.sub_43DDE0(0)
		*memmap.PtrUint32(0x587000, 84) = 0
	}
	if *fServer {
		C.nox_enable_audio = 0
		setEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING | NOX_ENGINE_FLAG_31)
		// static, don't need this
		//C.nox_init_ticks_func()
	}
	if *fSleep {
		setEngineFlag(NOX_ENGINE_FLAG_31)
	}
	if v := *fDrop; v != 0 {
		// TODO: can it be 0?
		C.sub_552010(C.int(v))
	}
	if *fNoText {
		setEngineFlag(NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING)
	}
	if *fNoLog {
		C.sub_413C00()
	}
	if *fLock {
		setEngineFlag(NOX_ENGINE_FLAG_26)
	}
	if *fSafe {
		resetEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE)
		setEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE)
		C.nox_enable_audio = 0
		C.nox_video_dxUnlockSurface = 1
		C.nox_xxx_useAudio_587000_80800 = 0
		*memmap.PtrUint32(0x5D4594, 805840) = 1
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
		*memmap.PtrUint32(0x5D4594, 805840) = 1
	}
	if *fNoThreads {
		C.nox_enable_threads = 0
	}
	if v := *fVol; v >= 0 {
		*memmap.PtrUint8(0x587000, 88) = byte(v)
	}
	if *fNoFloor {
		setEngineFlag(NOX_ENGINE_FLAG_DISABLE_FLOOR_RENDERING)
	}
	if *fNoDraw {
		setEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)
	}
	if v := *fPort; v > 0 {
		C.nox_xxx_setPortParam_40A3E0(C.int(v))
	}
	if v := *fClientPort; v > 0 {
		C.nox_xxx_setClientNetPort_40A410(C.int(v))
	}
	if *fNoSoft {
		resetEngineFlag(NOX_ENGINE_FLAG_12)
	}
	wd, err := os.Getwd()
	if err != nil {
		return fmt.Errorf("cannot get workdir: %w", err)
	}
	setDataPath(wd)
	// C.nox_common_readSKU_fromRegistry_4D78C0()
	C.fesetround(C.FE_TOWARDZERO)
	C.nox_win_width = 0
	C.nox_xxx_servSetPlrLimit_409F80(32)
	*memmap.PtrUint32(0x5D4594, 2614260) = uint32(C.nox_gameFPS) >> 1
	C.sub_4093A0()
	C.nox_ensure_thing_bin()
	// should be .csf but it works anyway
	if err := strmanReadFile("nox.str"); err != nil {
		return fmt.Errorf("failed to load strings file: %w", err)
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
	noxCommonInitRandom()
	C.nox_xxx_bindevent_42EAE0()
	C.nox_xxx_loadLook_415D50()
	C.nox_xxx_loadModifyers_4158C0()
	C.nox_xxx_cmdTokensLoad_4444F0()
	C.sub_4D11A0()
	C.nox_video_resizewnd(0, 0, 16)
	if C.nox_xxx_video_43BF10_upd_video_mode(1) == 0 {
		return fmt.Errorf("failed to update video mode")
	}
	C.nox_xxx_drawSelectColor_434350(C.int(memmap.Int32(0x5D4594, 2650656)))
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
	if v := strMan.Lang(); v == 6 || v == 8 {
		C.sub_43F680(0)
	}
	C.sub_413920()
	if C.nox_client_initScreenParticles_431390() == 0 {
		return fmt.Errorf("failed to init particles")
	}
	// does nothing on SDL
	// C.sub_4147E0(C.int(uintptr(unsafe.Pointer(noxWindow))))
	g_argc2 = len(args)
	g_argv2 = &CStringArray(args)[0]
	cmainLoop()
	return nil
}

func setDataPath(path string) {
	noxDataPath = path
}

func getDataPath() string {
	return noxDataPath
}

//export nox_common_get_data_path_409E10
func nox_common_get_data_path_409E10() *C.char {
	return internCStr(getDataPath())
}

//export nox_exit
func nox_exit(exitCode C.int) {
	os.Exit(int(exitCode))
}

//export nox_xxx_getNoxVer_401020
func nox_xxx_getNoxVer_401020() *C.wchar_t {
	return internWStr("V:" + noxVersionStr)
}

//export nox_xxx_gameResizeScreen_43BEF0_set_video_mode
func nox_xxx_gameResizeScreen_43BEF0_set_video_mode(w, h, d C.int) {
	nox_xxx_gameResizeScreen_setVideoMode(int(w), int(h), int(d))
}

//export nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode
func nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(w, h, d *C.int) {
	cw, ch, cd := nox_xxx_gameGetScreenBoundaries_getVideoMode()
	if w != nil {
		*w = C.int(cw)
	}
	if h != nil {
		*h = C.int(ch)
	}
	if d != nil {
		*d = C.int(cd)
	}
}

func nox_xxx_gameGetScreenBoundaries_getVideoMode() (w, h, d int) {
	w = int(C.nox_win_width_1)
	h = int(C.nox_win_height_1)
	d = int(C.nox_win_depth_1)
	return
}

func nox_xxx_gameResizeScreen_setVideoMode(w, h, d int) {
	d = 16 // 8 bit not supported
	C.nox_win_width_1 = C.int(w)
	C.nox_win_height_1 = C.int(h)
	C.nox_win_depth_1 = C.int(d)

	changeWindowedOrFullscreen()
}

func noxGetWinSize1() types.Size {
	return types.Size{W: int(C.nox_win_width_1), H: int(C.nox_win_height_1)}
}

func noxGetScreenMode() int {
	return int(C.g_fullscreen)
}

//export change_windowed_fullscreen
func change_windowed_fullscreen() {
	changeWindowedOrFullscreen()
}

//export sdl_set_window_rect
func sdl_set_window_rect(size, pos C.int2) {
	sdlSetWindowRect(int2size(size), int2pos(pos))
}

func int2size(v C.int2) types.Size {
	return types.Size{
		W: int(v.field_0),
		H: int(v.field_4),
	}
}

func int2pos(v C.int2) types.Point {
	return types.Point{
		X: int(v.field_0),
		Y: int(v.field_4),
	}
}

//export sdl_get_display_dim
func sdl_get_display_dim() C.int4 {
	r := sdlGetDisplayDim()
	var v C.int4
	v.field_0 = C.int(r[0])
	v.field_4 = C.int(r[1])
	v.field_8 = C.int(r[2])
	v.field_C = C.int(r[3])
	return v
}

func cleanup() {
	fmt.Println("cleanup")
	if getGameFlag(0x2000000) {
		C.nox_xxx_closeNetworkLog_413D00()
	}
	C.nox_common_writecfgfile(internCStr("nox.cfg"))
	C.nox_xxx_freeScreenParticles_4314D0()
	C.sub_413960()
	C.sub_431380()
	C.sub_4134F0()
	C.nox_xxx_freeWeaponArmorDefAndModifs_413060()
	C.sub_4311B0()
	C.nox_xxx_freeFloorBuffer_430EF0()
	C.nox_xxx_freeKeyboard_430210()
	C.nox_xxx_tileFree_410FC0_free()
	C.sub_4106C0()
	C.sub_42F4D0()
	C.sub_42EDC0()
	C.sub_42CD90()
	nox_strman_free_410020()
	C.nox_xxx_net_40EA70()
	C.sub_40D0F0()
	C.sub_40E070()
	C.sub_4D11D0()
	C.sub_4D0DA0()
	C.sub_40C0D0()
	C.sub_40B740()
	C.sub_4D0970()
	C.sub_4093D0()
	C.sub_40AF30()
	//C.sub_48B1B0() // does nothing on SDL
	C.nox_free_thing_bin()
}
