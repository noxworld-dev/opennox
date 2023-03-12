package opennox

import (
	"errors"
	"fmt"
	"image/color"
	"os"
	"path/filepath"
	"runtime"
	"strings"
	"time"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/env"
	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/serial"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var (
	debugMainloop           = os.Getenv("NOX_DEBUG_MAINLOOP") == "true"
	g_v20                   bool
	mainloopConnectResultOK bool
	mainloopContinue        = true // nox_continue_mainloop_93196
	continueMenuOrHost      = true // nox_game_continueMenuOrHost_93200
	initialStateSwitch      = false
	mainloopStopError       bool
	mainloopNoSkip          bool
	useFrameLimit           = true
	mainloopHook            func()
)

func nox_client_getIntroScreenDuration_44E3B0() int {
	if env.IsE2E() {
		return 10
	}
	return 25
}

func nox_client_getBriefDuration() int {
	if env.IsE2E() {
		return 10
	} else if env.IsDevMode() {
		return 3000
	}
	return 15000
}

func nox_xxx_setContinueMenuOrHost_43DDD0(v int) {
	if debugMainloop {
		log.Println("nox_xxx_setContinueMenuOrHost_43DDD0 =", v)
	}
	continueMenuOrHost = v != 0
}

func setEnableFrameLimit(enable bool) {
	useFrameLimit = enable
}

func nox_game_exit_xxx_43DE60() {
	if debugMainloop {
		log.Println("nox_game_exit_xxx_43DE60")
	}
	mainloopContinue = false
	nox_xxx_gameSetCliConnected(false)
}

func nox_game_exit_xxx2() {
	nox_xxx_setContinueMenuOrHost_43DDD0(0)
	nox_game_exit_xxx_43DE60()
}

func mainloopFrameLimit() {
	if !useFrameLimit {
		return
	}
	if noxflags.HasGame(noxflags.GameHost) && noxflags.HasGame(noxflags.GameClient) && !noxflags.HasEngine(noxflags.EngineNoRendering) && noxflags.HasGame(noxflags.GameFlag29) {
		if noxflags.HasEngine(noxflags.EnginePause) {
			return
		}
		if dt := nox_ticks_getNext(); dt > 0 {
			noxServer.LoopSleep(dt)
		}
		return
	}
	noxServer.RateWait()
}

func mainloopStop() {
	mainloopStopError = true
}

func mainloop_43E290(exitPath bool) {
	if debugMainloop {
		log.Printf("mainloop_43E290 (%s)\n", caller(1))
		defer func() {
			log.Printf("mainloop_43E290 exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	mainloopStopError = false
	mainloopContinue = true
	continueMenuOrHost = true
	*memmap.PtrUint32(0x5D4594, 816400) = 60 * noxServer.TickRate()

	// XXX
	noxClient.mapsend.setDownloading(false)

mainloop:
	for mainloopContinue && !mainloopStopError {
		cntMainloop.Inc()
		if mainloopHook != nil {
			mainloopHook()
		}
		noxServer.RunLoopHooks()
		if noxClient.mapsend.Downloading() {
			if done, err := noxClient.mapDownloadLoop(false); !done {
				continue mainloop
			} else if err != nil {
				log.Println(err)
				// map error
				mainloopContinue = false
				continueMenuOrHost = false
				if debugMainloop {
					log.Println("mapDownloadLoop exit")
				}
				goto MAINLOOP_EXIT
			}
		} else {
			if err := nox_xxx_gameChangeMap_43DEB0(); err != nil {
				if err != nil && err != ErrMapDownload {
					gameLog.Println("change game map:", err)
				}
				// XXX
				if noxClient.mapsend.Downloading() {
					continue mainloop
				}
				mainloopContinue = false
				continueMenuOrHost = false
				if debugMainloop {
					log.Println("nox_xxx_gameChangeMap_43DEB0 exit")
				}
				goto MAINLOOP_EXIT
			}
		}
		noxServer.SetRateLimit(30)
		noxClient.processInput()
		noxClient.nox_game_cdMaybeSwitchState_413800()

		if !noxServer.Update() {
			goto MAINLOOP_EXIT
		}
		if !noxClient.Update() {
			goto MAINLOOP_EXIT
		}

		mainloopFrameLimit()
		if mainloopContinue && !mainloopStopError {
			// unwind the stack and continue the mainloop
			continue mainloop
		}
	MAINLOOP_EXIT:
		if !exitPath {
			if !continueMenuOrHost || mainloopStopError {
				cleanup()
				nox_exit(0)
			}
			// repeat
			again, err := mainloopConnectOrHost()
			if err != nil {
				log.Println(err)
				if again {
					cmainLoop()
				}
				continue mainloop
			}
			if again {
				mainloop_43E290(true)
			}
			continue mainloop
		}
		if debugMainloop {
			log.Println("MAINLOOP_EXIT")
		}
		if err := mainloopReset(); err != nil {
			log.Println("mainloopReset:", err)
			continue mainloop
		}
		// repeat
		cmainLoop()
		continue mainloop
	}
}

func mainloopConnectOrHost() (again bool, _ error) {
	legacy.Sub_43DB60()
	legacy.Sub_43D990()
	g_v20 = true
	noxAudioServeT(800)
	noxCommonInitRandom()
	noxServer.SetInitialFrame()
	if mainloopConnectResultOK {
		if debugMainloop {
			log.Println("CONNECT_RESULT_OK retry")
		}
		err := CONNECT_RESULT_OK()
		return true, err
	}
	if noxflags.HasGame(noxflags.GameHost) {
		if err := noxServer.nox_xxx_servNewSession_4D1660(); err != nil {
			return false, err
		}
	}
	if !nox_xxx_clientResetSpriteAndGui_4357D0(mainloopNoSkip) {
		return false, nil
	}
	if noxflags.HasGame(noxflags.GameHost) && noxflags.HasGame(noxflags.GameFlag23) && noxflags.HasEngine(noxflags.EngineFlag1) {
		legacy.Sub_4D39F0(datapath.Data())
		if legacy.Nox_xxx_mapGenStart_4D4320() == 0 {
			legacy.Nox_xxx_mapSwitchLevel_4D12E0(0)
			return false, nil
		}
		sub_4D3C30()
		noxflags.UnsetGame(noxflags.GameFlag23)
	}
	err := CONNECT_OR_HOST()
	return true, err
}

func mainloopReset() error {
	if debugMainloop {
		log.Println("mainloopReset")
	}
	noxflags.UnsetGame(noxflags.GameFlag29)
	noxflags.UnsetGame(noxflags.GameModeMask | noxflags.GameFlag15 | noxflags.GameFlag16)
	noxflags.UnsetGame(noxflags.GameFlag24 | noxflags.GameFlag21)
	noxAudioServeT(300)
	legacy.Sub_43D990()
	nox_xxx_replayWriteFrame_4D39B0()
	if noxflags.HasGame(noxflags.GameHost) {
		legacy.Nox_xxx_servResetPlayers_4D23C0()
	}
	if noxflags.HasGame(noxflags.GameClient) {
		sub_435EB0()
	}
	if err := gameUpdateVideoMode(true); err != nil {
		if debugMainloop {
			log.Printf("gameUpdateVideoMode: %v (%s)", err, caller(0))
		}
		return err
	}
	mainloopConnectResultOK = false
	if noxflags.HasGame(noxflags.GameHost) {
		noxServer.nox_xxx_servEndSession_4D3200()
	}
	if noxflags.HasGame(noxflags.GameClient) {
		nox_xxx_cliSetupSession_437190()
	}
	inputClearKeyTimeouts()
	if noxflags.HasEngine(noxflags.EngineGameLoopMemdump) {
		legacy.Nox_xxx_gameLoopMemDump_413E30()
	}
	return nil
}

func (c *Client) nox_game_cdMaybeSwitchState_413800() {
	if initialStateSwitch {
		return
	}
	initialStateSwitch = true
	legacy.Sub_4137E0()
	if !c.GameStateSwitch() {
		nox_game_exit_xxx2()
	}
}

func nox_xxx_clientResetSpriteAndGui_4357D0(noSkip bool) bool {
	legacy.ClientSetPlayerNetCode(0)
	*memmap.PtrUint32(0x852978, 8) = 0
	setCurPlayer(nil)
	// TODO: size is a guess
	alloc.StrCopy(unsafe.Slice((*byte)(memmap.PtrOff(0x5D4594, 811280)), 1024), legacy.Nox_xxx_getRandomName_4358A0())
	if noSkip {
		*memmap.PtrUint32(0x587000, 85724) = 0
	}
	*memmap.PtrUint32(0x5D4594, 811064) = uint32(bool2int(nox_client_renderGUI_80828))
	netlist.ResetAll()
	if !noxflags.HasGame(noxflags.GameHost) {
		noxServer.Players.ResetAll()
	}
	if !nox_xxx_chatInit_48D7D0() {
		return false
	}
	legacy.Sub_4E4EF0()
	legacy.Sub_48D740()
	nox_xxx_gameSetCliConnected(false)
	legacy.Set_nox_gameDisableMapDraw_5d4594_2650672(0)
	legacy.Sub_473930()
	legacy.Sub_48D4B0(0)
	return true
}

// ----- (0048D7D0) --------------------------------------------------------
func nox_xxx_chatInit_48D7D0() bool {
	legacy.Set_nox_alloc_chat_1197364(alloc.NewClass("Chat", 692, 64).UPtr())
	return legacy.Get_nox_alloc_chat_1197364() != nil
}

func caller(skip int) string {
	pc, file, line, ok := runtime.Caller(skip + 1)
	if !ok {
		return "<unknown>"
	}
	fnc := "<unknown>"
	if f := runtime.FuncForPC(pc); f != nil {
		fnc = f.Name()
		if i := strings.LastIndexByte(fnc, '.'); i >= 0 {
			fnc = fnc[i+1:]
		}
	}
	return fmt.Sprintf("%s, %s:%d", fnc, filepath.Base(file), line)
}

func cmainLoop() {
	if debugMainloop {
		log.Printf("cmainLoop (%s)\n", caller(1))
		defer func() {
			log.Printf("cmainLoop exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	noxAudioServeT(300)
	if !isDedicatedServer {
		if !noxClient.sub_43C060() {
			return
		}
	}
	if !nox_xxx_cliWaitForJoinData_43BFE0() {
		return
	}
	if g_v20 {
		legacy.Sub_43DBA0()
		g_v20 = false
	}
	noxAudioServe()
	mainloop_43E290(false)
}

func CONNECT_OR_HOST() error {
	if debugMainloop {
		log.Println("CONNECT_OR_HOST")
		defer func() {
			log.Printf("CONNECT_OR_HOST exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	mode := noxClient.videoGetGameMode()
	info := legacy.Nox_xxx_getHostInfoPtr_431770()
	name := alloc.GoString16((*uint16)(memmap.PtrOff(0x85B3FC, 12204)))
	info.SetName(name)
	info.SetPlayerClass(getPlayerClass())
	info.SetIsFemale(memmap.Uint8(0x85B3FC, 12255))
	info.SetField2253(memmap.Uint16(0x85B3FC, 12187))
	info.Field2255 = memmap.Uint8(0x85B3FC, 12189)
	info.SetField2256(memmap.Uint16(0x85B3FC, 12184))
	info.Field2258 = memmap.Uint8(0x85B3FC, 12186)
	info.SetField2259(memmap.Uint16(0x85B3FC, 12190))
	info.Field2261 = memmap.Uint8(0x85B3FC, 12192)
	info.SetField2262(memmap.Uint16(0x85B3FC, 12193))
	info.Field2264 = memmap.Uint8(0x85B3FC, 12195)
	info.SetField2265(memmap.Uint16(0x85B3FC, 12196))
	info.Field2267 = memmap.Uint8(0x85B3FC, 12198)
	info.Field2268 = memmap.Uint8(0x85B3FC, 12199)
	info.Field2269 = memmap.Uint8(0x85B3FC, 12200)
	info.Field2270 = memmap.Uint8(0x85B3FC, 12201)
	info.Field2271 = memmap.Uint8(0x85B3FC, 12202)
	info.Field2272 = memmap.Uint8(0x85B3FC, 12203)
	legacy.Sub_48D740()

	var popts PlayerOpts
	popts.Screen = mode
	if s, ok := serial.Serial(); ok {
		popts.Serial = s
	}
	popts.Byte152 = byte(bool2int(!nox_xxx_checkHasSoloMaps()))
	if memmap.Uint8(0x85B3FC, 10980)&4 != 0 {
		popts.Byte152 |= 0x80
	}
	popts.Field2072 = memmap.String(0x85B3FC, 10395)
	popts.Field2096 = legacy.Sub_41FA40()
	popts.Field2068 = int(legacy.Get_dword_5d4594_2660032())
	popts.Info = *info

	if noxflags.HasGame(noxflags.GameHost) {
		if err := nox_xxx_replay_4D3860(&popts); err != nil {
			CONNECT_RESULT_FAIL(err)
			return fmt.Errorf("nox_xxx_replay_4D3860: %w", err)
		}
		if !isDedicatedServer {
			legacy.ClientSetPlayerNetCode(noxServer.newPlayer(common.MaxPlayers-1, &popts))
		}
		setVersionCode(NOX_CLIENT_VERS_CODE)
		if !isDedicatedServer {
			noxClient.nox_netlist_receiveCli_494E90(common.MaxPlayers - 1)
		}
		gameSetPlayState(2)
	} else {
		host := clientGetServerHost()
		port := legacy.ClientGetServerPort()
		if err := CONNECT_SERVER(host, port, &popts); err != nil {
			CONNECT_RESULT_FAIL(err)
			return fmt.Errorf("connect to server failed: %w", err)
		}
	}
	if err := CONNECT_RESULT_OK(); err != nil {
		return fmt.Errorf("connect result: %w", err)
	}
	return nil
}

func CONNECT_SERVER(host string, port int, opts *PlayerOpts) error {
	if debugMainloop {
		log.Println("CONNECT_SERVER", host, port)
		defer func() {
			log.Printf("CONNECT_SERVER exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	narg := &netstr.Options{
		DataSize: 2048,
		Port:     port,
		Func2:    nox_xxx_netHandleCliPacket_43C860,
		Check14:  nox_xxx_netBigSwitch_553210_op_14_check,
		Check17:  nox_xxx_netBigSwitch_553210_op_17_check,
	}
	dword_5d4594_815704 = false
	dword_5d4594_815708 = false
	nox_xxx_allocNetGQueue_5520B0()
	ind, err := netstr.NewClient(narg)
	if err != nil {
		return err
	}
	dword_5D4594_815700 = ind

	if err := netstr.Dial(ind, host, port, clientGetClientPort(), opts); err != nil {
		return err
	}

	if !noxflags.HasGame(noxflags.GameHost) {
		*legacy.Get_dword_5d4594_1599592_ptr() |= 0x80000000
	}
	netlist.ResetByInd(common.MaxPlayers-1, netlist.Kind0)
	legacy.Nox_xxx_set3512_40A340(0)
	nox_xxx_setMapCRC_40A360(0)

	if err := netstr.DialWait(ind, 10*time.Second, func() {
		nox_xxx_netSendBySock_40EE10(ind, common.MaxPlayers-1, netlist.Kind0)
	}, func() bool {
		return nox_xxx_getMapCRC_40A370() != 0
	}); err != nil {
		return err
	}

	if vers := getVersionCode(); vers != NOX_CLIENT_VERS_CODE {
		err := fmt.Errorf("invalid client version: %x", int(vers))
		log.Println(err)
		return netstr.NewConnectFailErr(-20, err)
	}
	gameSetPlayState(2)
	if !noxflags.HasGame(noxflags.GameHost) {
		noxServer.teamsReset()
	}
	return nil
}

func CONNECT_RESULT_FAIL(err error) {
	errcode := 0
	if e, ok := err.(*netstr.ConnectFailErr); ok {
		errcode = e.Code
	}
	if debugMainloop {
		log.Printf("CONNECT_RESULT_FAIL %d (%s)\n", errcode, caller(1))
		defer func() {
			log.Printf("CONNECT_RESULT_FAIL exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	noxflags.UnsetGame(noxflags.GameFlag21)
	mainloopConnectResultOK = false
	if noxflags.HasGame(noxflags.GameHost) {
		noxServer.nox_xxx_servEndSession_4D3200()
	}
	if noxflags.HasGame(noxflags.GameClient) {
		nox_xxx_cliSetupSession_437190()
	}
	inputClearKeyTimeouts()
	if noxflags.HasEngine(noxflags.EngineGameLoopMemdump) {
		legacy.Nox_xxx_gameLoopMemDump_413E30()
	}
	nox_client_showConnError_43D0A0(errcode)
	return
}

func nox_client_showConnError_43D0A0(errcode int) {
	const strfile = "netclint.c"
	title := strMan.GetStringInFile("ConnectionError", strfile)
	var desc string
	switch errcode + 23 {
	case 0:
		desc = strMan.GetStringInFile("ConnectAckTimeout", strfile)
	case 1:
		desc = strMan.GetStringInFile("SocketCreate", strfile)
	case 2:
		desc = strMan.GetStringInFile("WinsockInit", strfile)
	case 3:
		desc = strMan.GetStringInFile("VersionConflict", strfile)
	case 4:
		desc = strMan.GetStringInFile("Timeout", strfile)
	case 5:
		desc = strMan.GetStringInFile("JoinConnTooManyUsers", strfile)
	case 8:
		desc = strMan.GetStringInFile("InvalidPort", strfile)
	case 10:
		desc = strMan.GetStringInFile("JoinConnUserNotAllowed", strfile)
	case 11:
		desc = strMan.GetStringInFile("JoinConnUserBanned", strfile)
	case 17:
		desc = strMan.GetStringInFile("JoinConnRefused", strfile)
	case 19:
		desc = strMan.GetStringInFile("InvalidAddress", strfile)
	case 20:
		desc = strMan.GetStringInFile("InvalidHandle", strfile)
	default:
		desc = strMan.GetStringInFile("UnknownConnError", strfile)
	}
	NewDialogWindow(nil, title, desc, 33, nil, nil)
	sub_44A360(1)
}

func CONNECT_RESULT_OK() error {
	if debugMainloop {
		log.Printf("CONNECT_RESULT_OK (%s)\n", caller(1))
		defer func() {
			log.Printf("CONNECT_RESULT_OK exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	mainloopConnectResultOK = true
	if err := noxServer.nox_xxx_replayStartReadingOrSaving_4D38D0(); err != nil {
		return fmt.Errorf("nox_xxx_replayStartReadingOrSaving_4D38D0: %w", err)
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		noxServer.SetUpdateFunc(nil)
	} else if !noxServer.nox_xxx_servInitialMapLoad_4D17F0() {
		return errors.New("nox_xxx_servInitialMapLoad_4D17F0 exit")
	}
	if !noxflags.HasGame(noxflags.GameClient) {
		noxClient.SetDrawFunc(nil)
	} else {
		if !noxflags.HasGame(noxflags.GameFlag21) {
			if mode := noxClient.videoGetGameMode(); mode.X == 0 || mode.Y == 0 {
				mode.X = noxDefaultWidth
				mode.Y = noxDefaultHeight
				videoUpdateGameMode(mode)
			}
			if err := gameUpdateVideoMode(false); err != nil {
				return fmt.Errorf("gameUpdateVideoMode: %w", err)
			}
		}
		if err := initGameSession435CC0(); err != nil {
			return fmt.Errorf("failed to init game session: %w", err)
		}
	}
	if noxflags.HasEngine(noxflags.EngineGameLoopMemdump) {
		legacy.Nox_xxx_gameLoopMemDump_413E30()
	}
	if noxflags.HasGame(noxflags.GameOnline) && noxflags.HasGame(noxflags.GameHost) && legacy.Sub_43AF40() != 0 {
		legacy.Sub_43AA70()
	}
	noxAudioServe()
	noxflags.SetGame(noxflags.GameFlag29)
	return nil
}

func mainloopMaybeSwitchMapXXX() {
	if nox_client_gui_flag_815132 != 0 {
		return
	}
	if !noxflags.HasGame(noxflags.GameOnline) {
		return
	}
	if legacy.Nox_server_gameDoSwitchMap_40A680() != 0 {
		legacy.Nox_xxx_netGameSettings_4DEF00()
		legacy.Nox_server_gameUnsetMapLoad_40A690()
	} else if legacy.Sub_459D60() != 0 && !noxflags.HasGame(noxflags.GameFlag24|noxflags.GameFlag21) {
		if legacy.Sub_459DA0() != 0 {
			legacy.Sub_4DF020()
		}
		legacy.Sub_459D50(0)
	}
	if noxServer.Frame() >= memmap.Uint32(0x5D4594, 816400) {
		legacy.Sub_4161E0()
		legacy.Sub_416690()
		*memmap.PtrUint32(0x5D4594, 816400) = noxServer.Frame() + 60*noxServer.TickRate()
	}
}

func nox_xxx_cliWaitForJoinData_43BFE0() bool {
	if debugMainloop {
		log.Println("gameStateFunc = nox_xxx_gameStateWait_43C020")
	}
	noxServer.SetUpdateFunc(func() bool {
		noxServer.IncFrame()
		if nox_client_gui_flag_815132 != 0 {
			return true
		}
		if !isDedicatedServer {
			noxClient.r.ClearScreen(color.Black)
		}
		return false
	})
	noxClient.SetDrawFunc(nil)
	if memmap.Uint32(0x587000, 91840) != 0 {
		*memmap.PtrUint32(0x587000, 91840) = 0
		nox_client_gui_flag_815132 = 1
		return true
	}
	if !noxClient.GameStateSwitch() {
		return false
	}
	nox_client_gui_flag_815132 = 1
	return true
}

func nox_xxx_cliSetupSession_437190() {
	legacy.Sub_473960()
	noxServer.Players.ResetAll()
	legacy.Sub_455EE0()
	legacy.Sub_456240()
	legacy.Sub_48D800()
	legacy.Sub_49A8C0()
	sub_470550()
	noxClient.GUI.DestroyAll()
	noxClient.r.FadeDisable()
	if !noxflags.HasGame(noxflags.GameHost) {
		sub_43CC80()
	}
	gameSetPlayState(0)
	if !noxflags.HasGame(noxflags.GameHost) {
		legacy.Sub_4E4DE0()
	}
	noxServer.nox_xxx_mapLoad_40A380()
	clientSetServerHost("")
	legacy.Sub_446580(1)
	legacy.Sub_48D760()
	if !noxflags.HasGame(noxflags.GameHost) {
		netlist.ResetAll()
	}
	legacy.Sub_417CF0()
	legacy.ClientSetPlayerNetCode(0)
	*memmap.PtrUint32(0x852978, 8) = 0
	setCurPlayer(nil)
}

func sub_470510() {
	if legacy.Get_dword_5d4594_1090048() != nil {
		if legacy.Get_dword_5d4594_1090120() == 2 {
			legacy.Set_dword_587000_145664(1)
		} else {
			legacy.Set_dword_587000_145668(legacy.Get_dword_5d4594_1090120())
			legacy.Set_dword_5d4594_1090120(0)
			sub_4703F0()
		}
	}
}

func sub_470550() {
	if legacy.Get_dword_5d4594_1090048() != nil && legacy.Get_dword_5d4594_1090120() != 0 {
		legacy.Set_dword_5d4594_1090120(4)
		sub_4703F0()
	}
}

func sub_4703F0() {
	legacy.Set_dword_5d4594_1090120((legacy.Get_dword_5d4594_1090120() + 1) % 6)
	v1 := int32(legacy.Get_dword_5d4594_1090120())
	if false || v1 != 5 {
		if v1 == 1 {
			if !noxflags.HasGame(noxflags.GameModeQuest) {
				v1 = int32((legacy.Get_dword_5d4594_1090120() + 1) % 6)
				legacy.Set_dword_5d4594_1090120((legacy.Get_dword_5d4594_1090120() + 1) % 6)
			}
		}
	} else {
		v1 = 0
		legacy.Set_dword_5d4594_1090120(0)
	}
	switch v1 {
	case 0:
		noxClient.GUI.Focus(nil)
		legacy.Get_dword_5d4594_1090048().Hide()
		legacy.Get_dword_5d4594_1090100().Hide()
		*(*uint32)(unsafe.Add(*memmap.PtrPtr(6112660, 1090052), 4)) &= 0xFFFFFFF7
		*(*uint32)(unsafe.Add(*memmap.PtrPtr(6112660, 1090056), 4)) &= 0xFFFFFFF7
	case 1, 2:
		legacy.Get_dword_5d4594_1090048().ShowModal()
		sub := legacy.Get_dword_5d4594_1090100()
		sub.ShowModal()
		sub.Show()
		*(*uint32)(unsafe.Add(*memmap.PtrPtr(6112660, 1090052), 4)) |= 8
		*(*uint32)(unsafe.Add(*memmap.PtrPtr(6112660, 1090056), 4)) |= 8
		legacy.Set_dword_587000_145664(1)
	case 3, 4, 5:
		legacy.Set_dword_587000_145664(1)
	}
}

func (s *Server) nox_xxx_mapLoad_40A380() {
	legacy.Nox_xxx_set3512_40A340(0)
	nox_xxx_setMapCRC_40A360(0)
	name := memmap.String(0x5D4594, 3608)
	s.nox_xxx_gameSetMapPath_409D70(name)
	noxflags.SetGame(noxflags.GameHost | noxflags.GameClient)
	noxflags.UnsetGame(noxflags.GameFlag3 | noxflags.GameFlag4 | noxflags.GameModeMask | noxflags.GameFlag18) // TODO
	legacy.Nox_server_gameSettingsUpdated_40A670()
}

func (s *Server) nox_xxx_gameSetMapPath_409D70(path string) {
	log.Printf("set map path: %q", path)
	legacy.Nox_xxx_gameSetMapPath_409D70(path)
}

func (c *Client) map_download_finish() int {
	c.mapsend.CloseDialog()
	if c.mapsend.downloadOK {
		if mode := c.videoGetGameMode(); mode.X == 0 || mode.Y == 0 {
			mode.X = noxDefaultWidth
			mode.Y = noxDefaultHeight
			videoUpdateGameMode(mode)
		}
	}

	if !c.mapsend.downloadOK {
		noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
		return 0
	}
	legacy.Nox_xxx_gui_43E1A0(0)
	if !noxflags.HasEngine(noxflags.EngineNoRendering) {
		legacy.Set_nox_gameDisableMapDraw_5d4594_2650672(1)
		c.r.FadeClearScreen(true, color.Black)
	}
	fname := noxServer.nox_server_currentMapGetFilename_409B30()
	if err := nox_xxx_mapCliReadAll_4AC2B0(fname); err != nil {
		gameLog.Println("read downloaded map:", err)
		legacy.Nox_xxx_spriteLoadError_4356E0()
		return 0
	}
	if noxflags.HasGame(noxflags.GameHost) {
		legacy.Nox_xxx_gameServerReadyMB_4DD180(common.MaxPlayers - 1)
	} else {
		nox_xxx_netSendClientReady_43C9F0()
	}
	nox_xxx_gameSetCliConnected(true)

	if noxflags.HasGame(noxflags.GameFlag21 | noxflags.GameFlag24) {
		noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
	}
	return 1
}

func sub_435EB0() {
	writeConfigLegacy("nox.cfg")
	if noxflags.HasGame(noxflags.GameHost) {
		legacy.Nox_xxx_playerDisconnFinish_4DE530(common.MaxPlayers-1, 2)
	} else {
		nox_xxx_cliSendOutgoingClient_43CB50()
	}
	legacy.Sub_499450()
	legacy.Nox_xxx_gameClearAll_467DF0(0)
	sub_495AE0()
	legacy.Sub_4959D0()
	sub_473B30_free()
	legacy.Sub_496120()
	sub_473840()
	noxClient.Nox_things_free_44C580()
	sub_49A950_free()
	nox_drawable_free()
	legacy.Sub_49AEA0()
	legacy.Nox_xxx_j_resetNPCRenderData_49A2E0()
	legacy.Sub_4951C0()
	gameSetPlayState(2)
}

func nox_xxx_printCentered_445490(str string) {
	legacy.Nox_xxx_printCentered_445490(str)
}

var (
	ErrMapDownload = errors.New("map download started")
)

func nox_xxx_gameChangeMap_43DEB0() error {
	c := noxClient
	if noxflags.HasGame(noxflags.GameFlag24) {
		c.Nox_client_setCursorType(gui.CursorBusy)

		mapName := ""
		if gameIsNotMultiplayer {
			mapName = nox_xxx_mapFilenameGetSolo_4DB260()
		} else {
			mapName = c.srv.nox_server_currentMapGetFilename_409B30()
		}
		gameLog.Printf("nox_xxx_gameChangeMap_43DEB0: %q", mapName)
		// TODO: remove this partial path denormalization once we port map parsing
		mapName2 := mapName
		if i := strings.LastIndexByte(mapName2, '/'); i >= 0 {
			mapName2 = mapName2[:i] + "\\" + mapName2[i+1:]
		}
		crc := nox_xxx_mapCrcGetMB_409B00()
		v3 := legacy.Nox_xxx_mapValidateMB_4CF470(mapName2, crc)
		if v3&0x2 == 0 {
			gameLog.Printf("nox_xxx_mapValidateMB_4CF470: invalid or missing map file: %q", mapName)
		}
		if v3&0x4 == 0 {
			gameLog.Printf("nox_xxx_mapValidateMB_4CF470: CRC check failed: %q (expected: 0x%x)", mapName, crc)
		}
		gameLog.Println("nox_xxx_mapValidateMB_4CF470:", uint32(v3))
		if v3&2 != 0 && v3&4 != 0 {
			noxAudioServeT(500)
			if err := nox_xxx_mapCliReadAll_4AC2B0(mapName); err != nil {
				err = fmt.Errorf("change map failed: %w", err)
				gameLog.Println("client read map:", err)
				legacy.Nox_xxx_spriteLoadError_4356E0()
				return err
			}
			noxAudioServe()
			if noxflags.HasGame(noxflags.GameHost) {
				legacy.Nox_xxx_gameServerReadyMB_4DD180(common.MaxPlayers - 1)
			} else {
				nox_xxx_netSendClientReady_43C9F0()
			}
			nox_xxx_gameSetCliConnected(true)
			if memmap.Int32(0x973F18, 3800) < 0 {
				v7 := c.Strings().GetStringInFile("cdecode.c:EnterChat", "C:\\NoxPost\\src\\Client\\System\\gameloop.c")
				nox_xxx_printCentered_445490(v7)
				v14 := ctrlEvent.Sub_42E8E0_go(8, 1)
				v8 := c.Strings().GetStringInFile("cdecode.c:KeyToChat", "C:\\NoxPost\\src\\Client\\System\\gameloop.c")
				nox_xxx_printCentered_445490(fmt.Sprintf(v8, v14))
			}
			if !noxflags.HasEngine(noxflags.EngineNoRendering) {
				legacy.Set_nox_gameDisableMapDraw_5d4594_2650672(1)
				c.r.FadeClearScreen(true, color.Black)
			}
		} else if !noxflags.HasGame(noxflags.GameHost) {
			if v3&1 == 0 || v3&4 != 0 {
				noxflags.SetGame(noxflags.GameFlag21)
			} else {
				noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
				sub_477530(true)
				legacy.Nox_xxx_gui_43E1A0(1)
				v12 := c.Strings().GetStringInFile("OverwriteReadOnly", "C:\\NoxPost\\src\\Client\\System\\gameloop.c")
				v10 := c.Strings().GetStringInFile("Warning", "C:\\NoxPost\\src\\Client\\System\\gameloop.c")
				NewDialogWindow(nil, v10, v12, 24, func() {
					sub_477530(false)
					noxflags.SetGame(noxflags.GameFlag21)
					sub_44A400()
				}, func() {
					sub_477530(false)
					legacy.Nox_xxx_gui_43E1A0(0)
					nox_game_exit_xxx2()
					sub_44A400()
				})
			}
		} else {
			if !isDedicatedServer {
				legacy.Nox_xxx_gameServerReadyMB_4DD180(common.MaxPlayers - 1)
			}
			if !noxflags.HasEngine(noxflags.EngineNoRendering) {
				legacy.Set_nox_gameDisableMapDraw_5d4594_2650672(1)
				c.r.FadeClearScreen(true, color.Black)
			}
		}
	}
	if noxflags.HasGame(noxflags.GameFlag21) {
		c.map_download_start()
		return ErrMapDownload
	}
	if noxflags.HasGame(noxflags.GameFlag21 | noxflags.GameFlag24) {
		noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
	}
	return nil
}

func nox_xxx_cliDrawConnectedLoop_43B360() int {
	noxflags.SetGame(noxflags.GameFlag3)
	noxflags.UnsetGame(noxflags.GameHost)
	v0 := alloc.GoString((*byte)(unsafe.Add(legacy.Get_dword_5d4594_814624(), 12)))
	if v0 == "" {
		clientSetServerHost("localhost")
	} else {
		v1 := legacy.ClientGetServerPort()
		v5 := fmt.Sprintf("%s:%d", v0, v1)
		legacy.Nox_xxx_copyServerIPAndPort_431790(v5)
		clientSetServerHost(v0)
	}
	writeConfigLegacy("nox.cfg")
	v2 := *(*int8)(unsafe.Add(legacy.Get_dword_5d4594_814624(), 102))
	if v2 >= 0 {
		videoSetMaxSize(noxVideoMax)
	} else if res, ok := videoModeByID(byte(v2) & 0x7F); ok {
		videoSetMaxSize(res)
	} else {
		videoSetMaxSize(noxVideoMax)
	}
	sub_44A400()
	legacy.Nox_client_guiXxx_43A9D0()
	nox_client_guiXxxDestroy_4A24A0()
	return 1
}

func nox_client_guiXxxDestroy_4A24A0() int {
	sub_4A1BD0()
	noxClient.GUI.DestroyAll()
	nox_client_gui_flag_815132 = 0
	return 1
}

func sub_4A1BD0() {
	legacy.Get_dword_5d4594_1307292().Destroy()
}

func nox_client_quit_4460C0() {
	if noxflags.HasGame(noxflags.GameModeQuest) {
		if noxflags.HasGame(noxflags.GameHost) {
			sub_4DCD40()
		} else if sub_4460B0() {
			sub_4460A0(0)
			sub_446140()
		} else {
			legacy.Nox_xxx_netSavePlayer_41CE00()
			sub_4460A0(1)
		}
	} else {
		nox_xxx_serverIsClosing_825764 = true
		if noxflags.HasGame(noxflags.GameModeQuest) {
			if noxflags.HasGame(noxflags.GameHost) {
				sub_4D6B10(false)
			}
		}
	}
}

func sub_413960() {
	legacy.Set_dword_5d4594_251744(0)
	sub_413A00(0)
}
