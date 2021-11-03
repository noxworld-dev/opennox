package nox

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "GAME3_2.h"
#include "GAME5.h"
#include "common__config.h"
#include "thing.h"
#include "common__net_list.h"
#include "client__system__parsecmd.h"
#include "common__object__armrlook.h"
#include "common__object__weaplook.h"
#include "common__log.h"
#include "common__binfile.h"

extern unsigned int dword_5d4594_805860;
extern int nox_video_dxFullScreen;
extern int nox_enable_audio;
extern unsigned int nox_video_dxUnlockSurface;
extern int nox_enable_threads;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern unsigned int nox_gameFPS;
extern unsigned int nox_profiled_805856;
extern unsigned int nox_xxx_useMMX_587000_80800;

extern unsigned int dword_5d4594_3592;
extern unsigned int dword_5d4594_2650652;
extern void* dword_587000_81128;
extern unsigned int dword_5d4594_1193336;
extern unsigned int dword_5d4594_805980;
extern unsigned int dword_587000_93156;
extern unsigned int dword_5d4594_816340;
extern unsigned int dword_5d4594_816348;
extern unsigned int dword_5d4594_805988;
extern int nox_video_bag_var_2650640;

extern nox_gui_animation* nox_wnd_xxx_1309740;
*/
import "C"
import (
	"errors"
	"flag"
	"fmt"
	"net/http"
	_ "net/http/pprof"
	"os"
	"path/filepath"
	"strings"
	"unsafe"

	"github.com/spf13/viper"

	"nox/v1/client/audio/ail"
	"nox/v1/client/input/keybind"
	"nox/v1/common"
	"nox/v1/common/alloc/handles"
	"nox/v1/common/datapath"
	"nox/v1/common/env"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/log"
	"nox/v1/common/memmap"
	"nox/v1/common/types"
)

func init() {
	if env.IsDevMode() || IsDevVersion() || env.IsE2E() {
		go func() {
			if err := http.ListenAndServe("127.0.0.1:6060", nil); err != nil {
				log.Printf("failed to start pprof: %v", err)
			}
		}()
	}
}

var (
	isServer      bool
	isServerQuest bool
	serverExec    []string
)

// Nox only works on 32bit
var _ = [1]struct{}{}[unsafe.Sizeof(int(0))-4]

func writeLogsToDir() error {
	dir := filepath.Dir(os.Args[0])
	dir = filepath.Join(dir, "logs")
	if err := os.MkdirAll(dir, 0755); err != nil {
		return err
	}
	name := "opennox.log"
	if isDedicatedServer {
		name = "opennox-server.log"
	}
	return log.WriteToFile(filepath.Join(dir, name))
}

func RunArgs(args []string) (gerr error) {
	defer func() {
		switch r := recover().(type) {
		case ErrExit:
			if r != 0 {
				gerr = r
			}
		default:
			panic(r)
		case nil:
			// ok
		}
	}()
	if !env.IsE2E() {
		if err := writeLogsToDir(); err != nil {
			log.Println("cannot persist logs:", err)
		}
		defer log.Close()
	} else {
		e2eInit()
	}
	log.Printf("[nox] version: %s (%s)", Version, Commit)
	handles.Init()
	defer handles.Release()
	flags := flag.NewFlagSet("", flag.ContinueOnError)
	// TODO: add missing flag descriptions
	var (
		fConfig     = flags.String("config", "", "use specified config file")
		fData       = flags.String("data", "", "explicitly set Nox data dir")
		fServer     = flags.Bool("serveronly", false, "run the server only")
		fWindow     = flags.Bool("window", false, "window")
		fSWindow    = flags.Bool("swindow", false, "swindow")
		fFullScreen = flags.Bool("fullscreen", false, "fullscreen")
		fStretch    = flags.Bool("stretch", false, "stretch")
		fMinimize   = flags.Bool("minimize", false, "minimize")
		fNoLimit    = flags.Bool("nolimit", false, "nolimit")
		fSleep      = flags.Bool("sleep", false, "sleep")
		fDrop       = flags.Int("drop", 0, "drop given percent of network packets")
		fNoText     = flags.Bool("notext", false, "notext")
		fNoLog      = flags.Bool("nolog", false, "nolog")
		fLock       = flags.Bool("lock", false, "lock")
		fSafe       = flags.Bool("safe", false, "run in safe mode")
		fNoAudio    = flags.Bool("noaudio", false, "disable audio")
		fNoMMX      = flags.Bool("noMMX", false, "noMMX")
		fNoThreads  = flags.Bool("nothread", false, "nothread")
		fVol        = flags.Int("vol", -1, "vol")
		fNoFloor    = flags.Bool("noFloor", false, "noFloor")
		fNoDraw     = flags.Bool("noDraw", false, "noDraw")
		fPort       = flags.Int("port", common.GamePort, "server port number to use")
		fClientPort = flags.Int("clientport", 0, "clientport")
		fNoSoft     = flags.Bool("nosoft", false, "nosoft")
		fNoSkip     = flags.Bool("noskip", false, "noskip")
		// TODO: replace with -serveronly once we figure out all the details
		fAutoServer = flags.Bool("autosrv", isDedicatedServer, "automatically start the server")
		fAutoQuest  = flags.Bool("autoquest", false, "automatically start the quest game")
		fAutoExec   = flags.String("autoexec", "load estate", "run the specified command at server startup")
	)
	if err := flags.Parse(args[1:]); err != nil {
		return err
	}
	if err := readConfig(*fConfig); err != nil {
		return err
	}
	defer maybeWriteConfig()
	if env.IsE2E() {
		*fNoLimit = true
		mainloopHook = e2eRun
	}
	if path := *fData; path != "" {
		datapath.Set(path)
	} else if path = os.Getenv("NOX_DATA"); path != "" {
		datapath.Set(path)
	} else if path = viper.GetString(configNoxDataPath); path != "" {
		datapath.Set(path)
		if filepath.IsAbs(path) && strings.HasPrefix(path, filepath.Dir(viper.ConfigFileUsed())) {
			if rel, err := filepath.Rel(filepath.Dir(viper.ConfigFileUsed()), path); err == nil {
				viper.Set(configNoxDataPath, rel)
				writeConfigLater()
			}
		}
	} else {
		path = datapath.Find()
		if path == "" {
			err := errors.New("cannot find Nox data dir")
			datapath.Log.Println(err)
			return err
		}
		datapath.Set(path)
		if filepath.IsAbs(path) && strings.HasPrefix(path, filepath.Dir(viper.ConfigFileUsed())) {
			if rel, err := filepath.Rel(filepath.Dir(viper.ConfigFileUsed()), path); err == nil {
				path = rel
			}
		}
		viper.Set(configNoxDataPath, path)
		writeConfigLater()
	}
	maybeWriteConfig()
	if err := os.Chdir(datapath.Path()); err != nil {
		return err
	}
	initBlobData()
	isServer = *fAutoServer
	isServerQuest = *fAutoQuest
	serverExec = strings.Split(*fAutoExec, ";")
	if err := strmanReadFile("nox.str"); err != nil {
		return fmt.Errorf("failed to load strings file: %w", err)
	}
	if !*fServer && !*fNoDraw {
		err := InitSeat(types.Size{W: noxDefaultWidth, H: noxDefaultHeight})
		if err != nil {
			return err
		}
		defer FreeSeat()
	}
	if *fWindow {
		C.nox_video_dxFullScreen = 0
		C.dword_5d4594_805860 = 0
		updateFullScreen(-2)
	}
	if *fSWindow {
		C.nox_video_dxFullScreen = 0
		C.dword_5d4594_805860 = 1
		updateFullScreen(-3)
	}
	if *fFullScreen {
		updateFullScreen(-1)
	}
	if *fStretch {
		g_scaled = -1
	}
	if *fMinimize {
		*memmap.PtrUint32(0x5D4594, 805864) = 1
	}

	*memmap.PtrUint32(0x8531A0, 2584) = 0
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	gameAddStateCode(gameStateMovies)
	noxflags.ResetGame()
	noxflags.OnGameChange(func(f noxflags.GameFlag) {
		if f.Has(noxflags.GameServerSettings) {
			C.nox_server_gameSettingsUpdated = 1
		}
	})
	noxflags.OnGameSet(func(f noxflags.GameFlag) {
		log.Printf("game flag set: %v", f)
		C.nox_xxx_guiChatShowHide_445730(C.int(bool2int((noxflags.GetGame() & 0x17F0) != noxflags.GameModeChat)))
		if f.Has(noxflags.GameSuddenDeath) && noxflags.HasGame(noxflags.GameHost) {
			C.nox_xxx_netPrintLineToAll_4DA390(C.CString("Settings.c:SuddenDeathStart"))
		}
	})
	noxflags.OnGameUnset(func(f noxflags.GameFlag) {
		log.Printf("game flag unset: %v", f)
		if f.Has(noxflags.GameSuddenDeath) {
			C.dword_5d4594_3592 = 0
		}
	})
	noxflags.SetGame(noxflags.GameHost | noxflags.GameFlag2)
	setEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE)
	C.dword_5d4594_2650652 = 0
	gameFPSSet(30)
	gameFrameSetFromFlags()
	nox_ticks_reset_416D40()
	nox_xxx_setGameState_43DDF0(nil)
	gameSetCliDrawFunc(nil)
	gameSet816392Func(nil)
	noxflags.SetGame(noxflags.GameModeArena)
	if *fNoLimit {
		useFrameLimit = false
		*memmap.PtrUint32(0x587000, 84) = 0
	}
	if *fServer {
		C.nox_enable_audio = 0
		setEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING |
			NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING |
			NOX_ENGINE_FLAG_DISABLE_FLOOR_RENDERING |
			NOX_ENGINE_FLAG_SLEEP)
	}
	if *fSleep {
		setEngineFlag(NOX_ENGINE_FLAG_SLEEP)
	}
	if v := *fDrop; v != 0 {
		C.nox_net_setPacketDrop_552010(C.int(v))
	}
	if *fNoText {
		setEngineFlag(NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING)
	}
	if *fNoLog {
		C.nox_xxx_log_4_close_413C00()
	}
	if *fLock {
		setEngineFlag(NOX_ENGINE_FLAG_LOCK_VIDEO_RESOLUTION)
	}
	if *fSafe {
		resetEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE)
		setEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE)
		C.nox_enable_audio = 0
		C.nox_video_dxUnlockSurface = 1
		*memmap.PtrUint32(0x5D4594, 805840) = 1
		C.nox_enable_threads = 0
		mode := types.Size{
			W: noxDefaultWidth,
			H: noxDefaultHeight,
		}
		videoSetGameMode(mode)
		videoSetMenuMode(mode)
	}
	if *fNoAudio {
		C.nox_enable_audio = 0
	}
	if *fNoMMX {
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
		setServerPort(v)
	}
	if v := *fClientPort; v > 0 {
		C.nox_xxx_setClientNetPort_40A410(C.int(v))
	}
	if *fNoSoft {
		setEngineFlag(NOX_ENGINE_DISABLE_SOFT_LIGHTS)
	}
	// C.nox_common_readSKU_fromRegistry_4D78C0()
	// C.fesetround(C.FE_TOWARDZERO)
	C.nox_xxx_servSetPlrLimit_409F80(32)
	*memmap.PtrUint32(0x852978, 16) = gameFPS() / 2
	C.nox_binfile_reset_4093A0()
	C.nox_ensure_thing_bin()
	if err := nox_common_scanAllMaps_4D07F0(); err != nil {
		return fmt.Errorf("cannot find maps: %w", err)
	}
	keyBinding = keybind.New(strMan)
	C.nox_init_sound_index_40AED0()
	C.nox_xxx_mapSetDataDefault_416500()
	if C.nox_common_readcfgfile(C.CString("nox.cfg"), 0) == 0 {
		return fmt.Errorf("failed to load config file")
	}
	if env.IsE2E() {
		videoSetGameMode(types.Size{W: 1024, H: 768})
	} else {
		videoSetGameMode(types.Size{
			W: viper.GetInt(configVideoWidth),
			H: viper.GetInt(configVideoHeight),
		})
	}
	if err := gameexReadConfig("game_ex.cfg"); err != nil {
		return fmt.Errorf("failed to load gameex config file: %w", err)
	}
	inputClearKeyTimeouts()
	noxCommonInitRandom()
	C.nox_xxx_loadLook_415D50()
	C.nox_xxx_loadModifyers_4158C0()
	C.nox_xxx_cmdTokensLoad_4444F0()
	C.sub_4D11A0()
	if !isDedicatedServer {
		videoResizeView(types.Size{})
		if err := gameResetVideoMode(true, true); err != nil {
			return fmt.Errorf("failed to update video mode: %w", err)
		}
		noxrend.SelectColor(memmap.Uint32(0x85B3FC, 952))
		sub_440900()
	} else {
		enableGUIDrawing(false)
		videoInitStub()
	}
	if err := nox_video_read_videobag(); err != nil {
		return err
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
	if err := nox_xxx_initInput_430190(); err != nil {
		return fmt.Errorf("failed to init input: %w", err)
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
	C.nox_netlist_init_40EA10()
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
	mainloopNoSkip = *fNoSkip
	cmainLoop()
	return nil
}

type ErrExit int

func (e ErrExit) Error() string {
	return fmt.Sprintf("exit code: %d", int(e))
}

//export nox_exit
func nox_exit(exitCode C.int) {
	panic(ErrExit(exitCode))
}

//export nox_xxx_getNoxVer_401020
func nox_xxx_getNoxVer_401020() *C.wchar_t {
	return internWStr(ClientVersionString())
}

//export nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode
func nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(w, h, d *C.int) {
	mode := videoGetGameMode()
	if w != nil {
		*w = C.int(mode.W)
	}
	if h != nil {
		*h = C.int(mode.H)
	}
	if d != nil {
		*d = 16
	}
}

func videoUpdateGameMode(mode types.Size) {
	videoSetGameMode(mode)
	changeWindowedOrFullscreen()
}

//export change_windowed_fullscreen
func change_windowed_fullscreen() {
	changeWindowedOrFullscreen()
}

//export sub_4AA9C0
func sub_4AA9C0() C.int {
	C.sub_44D8F0()
	if !env.IsE2E() {
		videoUpdateGameMode(guiOptionsRes)
	}
	C.nox_common_writecfgfile(internCStr("nox.cfg"))
	C.nox_wnd_xxx_1309740.state = C.nox_gui_anim_state(NOX_GUI_ANIM_OUT)
	C.sub_43BE40(2)
	clientPlaySoundSpecial(923, 100)
	return 1
}

func cleanup() {
	log.Println("cleanup")
	if noxflags.HasGame(noxflags.GameFlag26) {
		C.nox_xxx_networkLog_close_413D00()
	}
	C.nox_common_writecfgfile(internCStr("nox.cfg"))
	C.nox_xxx_freeScreenParticles_4314D0()
	C.sub_413960()
	C.sub_431380()
	C.sub_4134F0()
	C.nox_xxx_freeWeaponArmorDefAndModifs_413060()
	sub_4311B0()
	C.nox_xxx_freeFloorBuffer_430EF0()
	nox_xxx_freeKeyboard_430210()
	C.nox_xxx_tileFree_410FC0_free()
	C.sub_4106C0()
	nox_video_bagFree_42F4D0()
	C.sub_42EDC0()
	ctrlEvent.Reset()
	nox_strman_free_410020()
	C.nox_netlist_free_40EA70()
	C.sub_40D0F0()
	C.sub_40E070()
	C.sub_4D11D0()
	C.sub_4D0DA0()
	C.sub_40C0D0()
	C.sub_40B740()
	C.nox_common_maplist_free_4D0970()
	C.nox_binfile_disable_409560()
	C.sub_40AF30()
	//C.sub_48B1B0() // does nothing on SDL
	C.nox_free_thing_bin()
	ail.Shutdown()
}

func sub_4311B0() {
	sub_43DCC0()
	sub_4312B0()
	sub_43D970()
	C.sub_44D8C0()
	C.sub_451970()
	if C.dword_5d4594_805980 != 0 {
		C.sub_4869C0(unsafe.Pointer(uintptr(C.dword_5d4594_805980)))
	}
	C.dword_587000_81128 = nil
	C.sub_431270()
	if C.dword_5d4594_1193336 != 0 {
		C.sub_4875F0()
		C.sub_4870A0()
		C.dword_5d4594_1193336 = 0
	}
}

func sub_4312B0() {
	C.sub_431290()
	C.sub_44D8F0()
	C.sub_43D990()
}

func sub_43D970() {
	if C.dword_5d4594_816340 != 0 {
		sub_43DCC0()
		C.dword_5d4594_816340 = 0
	}
}

func sub_43DCC0() {
	if C.dword_587000_93156 == 0 {
		return
	}
	if C.dword_5d4594_816340 == 0 {
		return
	}
	C.sub_43D990()
	for C.dword_5d4594_816348 != 0 {
		if C.dword_5d4594_816348 == 3 {
			C.sub_43D650()
			C.dword_5d4594_816348 = 0
		}
		sub_4312C0()
	}
}

//export sub_4312C0
func sub_4312C0() {
	ail.Serve()
	if C.dword_5d4594_805988 != 0 {
		return
	}
	C.dword_5d4594_805988 = 1
	v1 := platformTicks()
	v3 := int64(v1) - int64(memmap.Uint64(0x5D4594, 805996))
	if v3 > 33 {
		C.sub_44D3A0()
		C.sub_43D440()
		*memmap.PtrUint64(0x5D4594, 805996) = v1
	}
	C.dword_5d4594_805988 = 0
}
