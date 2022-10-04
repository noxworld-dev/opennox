package opennox

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "GAME3_2.h"
#include "GAME5.h"
#include "common__net_list.h"
#include "client__system__parsecmd.h"
#include "common__object__armrlook.h"
#include "common__object__weaplook.h"
#include "common__log.h"

extern int nox_enable_audio;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern unsigned int nox_gameFPS;

extern unsigned int dword_5d4594_2650652;
extern void* dword_587000_81128;
extern unsigned int dword_5d4594_1193336;
extern unsigned int dword_5d4594_805980;
extern unsigned int dword_587000_93156;
extern unsigned int dword_5d4594_816340;
extern unsigned int dword_5d4594_816348;
extern unsigned int dword_5d4594_805988;

extern nox_gui_animation* nox_wnd_xxx_1309740;
*/
import "C"
import (
	"errors"
	"flag"
	"fmt"
	"image"
	"image/color"
	"net/http"
	_ "net/http/pprof"
	"os"
	"path/filepath"
	"strings"
	"unsafe"

	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promauto"
	"github.com/prometheus/client_golang/prometheus/promhttp"
	"github.com/spf13/viper"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/env"
	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox/v1/client/audio/ail"
	"github.com/noxworld-dev/opennox/v1/common/alloc/handles"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/version"
)

func init() {
	http.Handle("/metrics", promhttp.Handler())
	viper.SetDefault(configManualSpellCastDelay, 0.5)
	promauto.NewCounterVec(prometheus.CounterOpts{
		Name: "opennox_version",
		Help: "OpenNox version",
	}, []string{"vers", "commit"}).WithLabelValues(
		version.Version(), version.Commit(),
	).Inc()
}

const (
	configManualSpellCastDelay = "extensions.spells.manual_cast.timeout"
)

var (
	isServer      bool
	isServerQuest bool
	serverExec    []string
	onDataPathSet []func()
)

func registerOnDataPathSet(fnc func()) {
	onDataPathSet = append(onDataPathSet, fnc)
}

// Nox only works on 32bit
var _ = [1]struct{}{}[unsafe.Sizeof(int(0))-4]

func writeLogsToDir(dir string) error {
	if dir == "" {
		dir = filepath.Dir(os.Args[0])
		if sdir := env.AppUserDir(); sdir != "" {
			dir = sdir
		}
		dir = filepath.Join(dir, "logs")
	}
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
	flags := flag.NewFlagSet("", flag.ContinueOnError)
	// TODO: add missing flag descriptions
	rconDefHost := ""
	if env.IsDevMode() {
		rconDefHost = rconDefaultHost
	}
	var (
		fConfig     = flags.String("config", "", "use specified config file")
		fData       = flags.String("data", "", "explicitly set Nox data dir")
		fServer     = flags.Bool("serveronly", false, "run the server only")
		fWindow     = flags.Bool("window", false, "window")
		fSWindow    = flags.Bool("swindow", false, "swindow")
		fFullScreen = flags.Bool("fullscreen", false, "fullscreen")
		fMinimize   = flags.Bool("minimize", false, "minimize")
		fNoLimit    = flags.Bool("nolimit", false, "nolimit")
		fSleep      = flags.Bool("sleep", false, "sleep")
		fDrop       = flags.Int("drop", 0, "drop given percent of network packets")
		fNoText     = flags.Bool("notext", false, "notext")
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
		fRecord     = flags.String("record", "", "record the game to a given file")
		fReplay     = flags.String("replay", "", "replay game recording from a given file")
		fPProf      = flags.String("pprof", "", "enable pprof")
		fRcon       = flags.String("rcon", rconDefHost, "enable remote console")
		fRconPass   = flags.String("rcon-pass", "", "remote console password")
		fLogs       = flags.String("logs", "", "directory for logs")
	)
	if err := flags.Parse(args[1:]); err != nil {
		return err
	}
	if !env.IsE2E() {
		if err := writeLogsToDir(*fLogs); err != nil {
			log.Println("cannot persist logs:", err)
		}
		defer log.Close()
	} else {
		e2eInit()
		defer e2eStop()
	}
	version.LogVersion()

	handles.Init()
	defer handles.Release()
	if !isDedicatedServer {
		go version.Latest() // prefetch
	}
	if env.IsDevMode() || version.IsDev() || env.IsE2E() || *fPProf != "" {
		go func() {
			host := *fPProf
			if host == "" {
				host = "127.0.0.1:6060"
			}
			log.Printf("starting pprof server on %q", host)
			if err := http.ListenAndServe(host, nil); err != nil {
				log.Printf("failed to start pprof: %v", err)
			}
		}()
	}
	noxServer = NewServer(noxConsole, strMan)
	var err error
	noxClient, err = NewClient(noxConsole, noxServer)
	if err != nil {
		return err
	}
	if err := readConfig(*fConfig); err != nil {
		return fmt.Errorf("cannot read config: %w", err)
	}
	defer maybeWriteConfig()
	if env.IsE2E() {
		*fNoLimit = true
		mainloopHook = e2eRun
	}
	if path := *fData; path != "" {
		datapath.SetData(path)
	} else if path = os.Getenv("NOX_DATA"); path != "" {
		datapath.SetData(path)
	} else if path = viper.GetString(configNoxDataPath); path != "" {
		datapath.SetData(path)
		if filepath.IsAbs(path) && strings.HasPrefix(path, filepath.Dir(viper.ConfigFileUsed())) {
			if rel, err := filepath.Rel(filepath.Dir(viper.ConfigFileUsed()), path); err == nil {
				viper.Set(configNoxDataPath, rel)
				writeConfigLater()
			}
		}
	} else {
		path = datapath.FindData()
		if path == "" {
			err := errors.New("cannot find Nox data dir")
			datapath.Log.Println(err)
			return err
		}
		datapath.SetData(path)
		if filepath.IsAbs(path) && strings.HasPrefix(path, filepath.Dir(viper.ConfigFileUsed())) {
			if rel, err := filepath.Rel(filepath.Dir(viper.ConfigFileUsed()), path); err == nil {
				path = rel
			}
		}
		viper.Set(configNoxDataPath, path)
		writeConfigLater()
	}
	maybeWriteConfig()
	for _, fnc := range onDataPathSet {
		fnc()
	}
	if err := os.Chdir(datapath.Data()); err != nil {
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
		err = noxClient.initSeat(image.Point{X: noxDefaultWidth, Y: noxDefaultHeight})
		if err != nil {
			return err
		}
	}
	if *fWindow {
		dword_5d4594_805860 = false
		noxClient.updateFullScreen(-2)
	}
	if *fSWindow {
		dword_5d4594_805860 = true
		noxClient.updateFullScreen(-3)
	}
	if *fFullScreen {
		noxClient.updateFullScreen(-1)
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
			nox_server_gameSettingsUpdated_40A670()
		}
	})
	noxflags.OnGameSet(func(f noxflags.GameFlag) {
		log.Printf("game flag set: %v", f)
		C.nox_xxx_guiChatShowHide_445730(C.int(bool2int(noxflags.GetGame().Mode() != noxflags.GameModeChat)))
		if f.Has(noxflags.GameSuddenDeath) && noxflags.HasGame(noxflags.GameHost) {
			noxServer.netPrintLineToAll("Settings.c:SuddenDeathStart")
		}
	})
	noxflags.OnGameUnset(func(f noxflags.GameFlag) {
		log.Printf("game flag unset: %v", f)
		if f.Has(noxflags.GameSuddenDeath) {
			noxServer.flag3592 = false
		}
	})
	noxflags.SetGame(noxflags.GameHost | noxflags.GameClient)
	noxflags.SetEngine(noxflags.EngineSoftShadowEdge)
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
		noxflags.SetEngine(noxflags.EngineNoRendering |
			noxflags.EngineNoTextRendering |
			noxflags.EngineNoFloorRendering |
			noxflags.EngineSleep)
	}
	if *fSleep {
		noxflags.SetEngine(noxflags.EngineSleep)
	}
	if v := *fDrop; v != 0 {
		netPacketDrop = v
	}
	if *fNoText {
		noxflags.SetEngine(noxflags.EngineNoTextRendering)
	}
	if *fLock {
		noxflags.SetEngine(noxflags.EngineLockResolution)
	}
	if *fSafe {
		noxflags.UnsetEngine(noxflags.EngineSoftShadowEdge)
		noxflags.SetEngine(noxflags.EngineWindowed)
		C.nox_enable_audio = 0
		legacyUnlockSurface = true
		*memmap.PtrUint32(0x5D4594, 805840) = 1
		nox_enable_threads = false
		mode := image.Point{
			X: noxDefaultWidth,
			Y: noxDefaultHeight,
		}
		noxClient.videoSetGameMode(mode)
		videoSetMenuMode(mode)
	}
	if *fNoAudio {
		C.nox_enable_audio = 0
	}
	if *fNoMMX {
		*memmap.PtrUint32(0x5D4594, 805840) = 1
	}
	if *fNoThreads {
		nox_enable_threads = false
	}
	if v := *fVol; v >= 0 {
		*memmap.PtrUint8(0x587000, 88) = byte(v)
	}
	if *fNoFloor {
		noxflags.SetEngine(noxflags.EngineNoFloorRendering)
	}
	if *fNoDraw {
		noxflags.SetEngine(noxflags.EngineNoRendering)
	}
	if v := *fPort; v > 0 {
		noxServer.setServerPort(v)
	}
	if v := *fClientPort; v > 0 {
		C.nox_xxx_setClientNetPort_40A410(C.int(v))
	}
	if *fNoSoft {
		noxflags.SetEngine(noxflags.EngineNoSoftLights)
	}
	if fname := *fRecord; fname != "" {
		if err := noxServer.nox_xxx_replayStartSave_4D3370(fname); err != nil {
			return err
		}
	} else if fname = *fReplay; fname != "" {
		if err := noxServer.nox_xxx_replayFileOpen_4D34C0(fname); err != nil {
			return err
		}
	}
	C.nox_xxx_servSetPlrLimit_409F80(32)

	// manual spell cast timeout (in seconds)
	msmul := viper.GetFloat64(configManualSpellCastDelay)
	// manual spell cast timeout (in frames)
	*memmap.PtrUint32(0x852978, 16) = uint32(float64(gameFPS()) * msmul)

	if err := nox_common_scanAllMaps_4D07F0(); err != nil {
		return fmt.Errorf("cannot find maps: %w", err)
	}
	keyBinding = keybind.New(strMan)
	C.nox_xxx_mapSetDataDefault_416500()
	if err := nox_common_readcfgfile("nox.cfg", false); err != nil {
		return fmt.Errorf("failed to load config file: %w", err)
	}
	if env.IsE2E() {
		noxClient.videoSetGameMode(image.Point{X: 1024, Y: 768})
	} else {
		noxClient.videoSetGameMode(image.Point{
			X: viper.GetInt(configVideoWidth),
			Y: viper.GetInt(configVideoHeight),
		})
	}
	if err := gameexReadConfig("game_ex.cfg"); err != nil {
		return fmt.Errorf("failed to load gameex config file: %w", err)
	}
	inputClearKeyTimeouts()
	noxCommonInitRandom()
	C.nox_xxx_loadLook_415D50()
	C.nox_xxx_loadModifyers_4158C0()
	initConsole(strMan)
	C.sub_4D11A0()
	if !isDedicatedServer {
		videoResizeView(image.Point{})
		if err := noxClient.gameResetVideoMode(true, true); err != nil {
			return fmt.Errorf("failed to update video mode: %w", err)
		}
		noxClient.r.ClearScreen(color.Black)
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
	if err := nox_xxx_loadAllBinFiles_415470(); err != nil {
		thingsLog.Println(err)
		return fmt.Errorf("failed to load bin files: %w", err)
	}
	if err := nox_xxx_initInput_430190(); err != nil {
		return fmt.Errorf("failed to init input: %w", err)
	}
	if nox_xxx_mapAlloc_4101D0() == 0 {
		return fmt.Errorf("failed to init map")
	}
	if C.nox_xxx_tileAlloc_410F60_init() == 0 {
		return fmt.Errorf("failed to init tiles")
	}
	C.nox_xxx_initSinCosTables_414C90()
	C.nox_xxx_loadMapCycle_4D0A30()
	C.nox_xxx_mapSelectFirst_4D0E00()
	nox_netlist_init_40EA10()
	C.sub_40B890(32)
	C.sub_40B170(32)
	C.sub_4134D0()
	if v := strMan.Lang(); v == 6 || v == 8 {
		noxClient.r.SetBold(false)
	}
	C.sub_413920()
	nox_client_initScreenParticles_431390()
	mainloopNoSkip = *fNoSkip
	if host := *fRcon; host != "" {
		rconLog.Println("starting rcon at", host)
		rcon, err := NewRemoteConsole(host, execConsoleCmdAuthed, RconOptions{
			Pass: *fRconPass,
		})
		if err != nil {
			if !env.IsDevMode() {
				return err
			}
			rconLog.Println(err)
		} else {
			defer rcon.Close()
			consoleMux.Add(rcon)
			go func() {
				if err := rcon.Serve(); err != nil {
					rconLog.Println(err)
				}
			}()
		}
	}
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

//export nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode
func nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(w, h, d *C.int) {
	mode := noxClient.videoGetGameMode()
	if w != nil {
		*w = C.int(mode.X)
	}
	if h != nil {
		*h = C.int(mode.Y)
	}
	if d != nil {
		*d = 16
	}
}

func videoUpdateGameMode(mode image.Point) {
	noxClient.videoSetGameMode(mode)
	changeWindowedOrFullscreen()
}

//export sub_4AA9C0
func sub_4AA9C0() C.int {
	sub_44D8F0()
	if !env.IsE2E() {
		videoUpdateGameMode(guiOptionsRes)
	}
	writeConfigLegacy("nox.cfg")
	C.nox_wnd_xxx_1309740.state = C.nox_gui_anim_state(NOX_GUI_ANIM_OUT)
	sub_43BE40(2)
	clientPlaySoundSpecial(sound.SoundShellSlideOut, 100)
	return 1
}

func cleanup() {
	log.Println("cleanup")
	writeConfigLegacy("nox.cfg")
	nox_xxx_freeScreenParticles_4314D0()
	sub_413960()
	C.sub_431380()
	C.nox_xxx_freeWeaponArmorDefAndModifs_413060()
	sub_4311B0()
	nox_video_freeFloorBuffer_430EC0()
	nox_xxx_freeKeyboard_430210()
	C.nox_xxx_tileFree_410FC0_free()
	C.sub_4106C0()
	nox_video_bagFree_42F4D0()
	C.sub_42EDC0()
	ctrlEvent.Reset()
	nox_strman_free_410020()
	nox_netlist_free_40EA70()
	C.sub_40D0F0()
	C.sub_4D11D0()
	C.sub_4D0DA0()
	C.sub_40C0D0()
	C.sub_40B740()
	C.nox_common_maplist_free_4D0970()
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
	sub_44D8F0()
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
			sub_43D650()
			C.dword_5d4594_816348 = 0
		}
		sub_4312C0()
	}
}

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
