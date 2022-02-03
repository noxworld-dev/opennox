package nox

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__network__netclint.h"
#include "client__video__draw_common.h"
#include "common__config.h"
#include "GAME2_3.h"
#include "thing.h"
#include "common__system__team.h"
#include "common__system__gamedisk.h"
#include "common__net_list.h"
#include "client__drawable__drawdb.h"
#include "client__io__console.h"
#include "client__gui__guimsg.h"
#include "client__system__client.h"
#include "client__drawable__drawable.h"

extern unsigned int nox_game_loop_xxx_805872;
extern unsigned int dword_5d4594_2660032;
extern void* dword_5d4594_814624;
extern unsigned int dword_5d4594_815704;
extern unsigned int dword_5d4594_815708;
extern unsigned int dword_5d4594_3844304;
extern unsigned int dword_5d4594_2649712;
extern unsigned int dword_5d4594_2618912;
extern unsigned int dword_587000_145664;
extern unsigned int dword_587000_145668;
extern unsigned int nox_client_gui_flag_815132;
extern unsigned int nox_gameFPS;
extern unsigned int nox_xxx_gameDownloadInProgress_587000_173328;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern unsigned int nox_xxx_mapDownloadOK_587000_173332;
extern void* nox_alloc_chat_1197364;
extern unsigned int nox_client_renderGUI_80828;
extern char nox_clientServerAddr[32];
extern uint32_t dword_5d4594_1090120;
extern nox_window* dword_5d4594_1090048;
extern nox_window* dword_5d4594_1090100;
extern void* dword_5d4594_1307292;
extern uint32_t nox_color_black_2650656;

static void go_call_sub_4516C0(wchar_t* a1, char* a2) {
	sub_4516C0(a1, a2);
}
*/
import "C"
import (
	"context"
	"errors"
	"fmt"
	"net"
	"os"
	"path/filepath"
	"runtime"
	"strings"
	"time"
	"unsafe"

	"nox/v1/common/env"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/log"
	"nox/v1/common/memmap"
	"nox/v1/common/noxnet"
	"nox/v1/common/platform"
	"nox/v1/common/serial"
)

var (
	debugMainloop           = os.Getenv("NOX_DEBUG_MAINLOOP") == "true"
	g_v20                   bool
	mainloopConnectResultOK bool
	mainloopCnt             uint64
	mainloopContinue        = true // nox_continue_mainloop_93196
	continueMenuOrHost      = true // nox_game_continueMenuOrHost_93200
	mainloopNoSkip          bool
	nox_draw_unk1           func() bool
	func_5D4594_816392      func() bool
	useFrameLimit           = true
	mainloopHook            func()
)

func gameSetCliDrawFunc(fnc func() bool) {
	nox_draw_unk1 = fnc
}

func gameSet816392Func(fnc func() bool) {
	func_5D4594_816392 = fnc
}

//export nox_client_getIntroScreenDuration_44E3B0
func nox_client_getIntroScreenDuration_44E3B0() C.int {
	if env.IsE2E() {
		return 10
	}
	return 25
}

//export nox_client_getFadeDuration
func nox_client_getFadeDuration() C.int {
	if env.IsE2E() {
		return 10
	} else if env.IsDevMode() {
		return 5
	}
	return 25
}

//export nox_client_getBriefDuration
func nox_client_getBriefDuration() C.int {
	if env.IsE2E() {
		return 10
	} else if env.IsDevMode() {
		return 3000
	}
	return 15000
}

//export nox_game_SetCliDrawFunc
func nox_game_SetCliDrawFunc(fnc unsafe.Pointer) {
	if fnc == nil {
		gameSetCliDrawFunc(nil)
	} else {
		gameSetCliDrawFunc(func() bool {
			return cgoCallIntVoidFunc(fnc) != 0
		})
	}
}

//export sub_43DE40
func sub_43DE40(fnc unsafe.Pointer) C.int {
	if fnc == nil {
		gameSet816392Func(nil)
	} else {
		gameSet816392Func(func() bool {
			return cgoCallIntVoidFunc(fnc) != 0
		})
	}
	return 1
}

//export nox_xxx_setContinueMenuOrHost_43DDD0
func nox_xxx_setContinueMenuOrHost_43DDD0(v C.int) {
	if debugMainloop {
		log.Println("nox_xxx_setContinueMenuOrHost_43DDD0 =", int(v))
	}
	continueMenuOrHost = v != 0
}

//export nox_xxx_setFrameLimit_43DDE0
func nox_xxx_setFrameLimit_43DDE0(v C.int) {
	useFrameLimit = v != 0
}

//export nox_server_mainloop_exiting_43DEA0
func nox_server_mainloop_exiting_43DEA0() C.bool {
	return C.bool(!mainloopContinue)
}

//export nox_game_exit_xxx_43DE60
func nox_game_exit_xxx_43DE60() {
	if debugMainloop {
		log.Println("nox_game_exit_xxx_43DE60")
	}
	mainloopContinue = false
	nox_xxx_gameSetCliConnected(false)
	if C.nox_xxx_check_flag_aaa_43AF70() != 1 {
		return
	}
	if !noxflags.HasGame(noxflags.GameFlag26) {
		C.sub_40D380()
	}
}

func nox_xxx_gameIsNotMultiplayer_4DB250() bool {
	return C.nox_xxx_gameIsNotMultiplayer_4DB250() != 0
}

var gameLoopHooks = make(chan func())

func addGameLoopHook(ctx context.Context, fnc func()) {
	select {
	case <-ctx.Done():
	case gameLoopHooks <- fnc:
	}
}

func runGameLoopHooks() {
	mainloopSleep(time.Millisecond)
}

func mainloopSleep(dt time.Duration) {
	tm := time.NewTimer(dt)
	defer tm.Stop()
	for {
		select {
		case <-tm.C:
			return
		case fnc := <-gameLoopHooks:
			fnc()
		}
	}
}

func mainloopStop() {
	mainloopContinue = false
	continueMenuOrHost = false
}

func mainloop_43E290(exitPath bool) {
	if debugMainloop {
		log.Printf("mainloop_43E290 (%s)\n", caller(1))
		defer func() {
			log.Printf("mainloop_43E290 exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	mainloopContinue = true
	continueMenuOrHost = true
	*memmap.PtrUint32(0x5D4594, 816400) = 60 * gameFPS()

	// XXX
	nox_xxx_mapSetDownloadInProgress(false)

mainloop:
	for mainloopContinue {
		cntMainloop.Inc()
		if mainloopHook != nil {
			mainloopHook()
		}
		runGameLoopHooks()
		if mapDownloading() {
			if done, err := mapDownloadLoop(false); !done {
				continue mainloop
			} else if err != nil {
				log.Println(err)
				// map error
				mainloopStop()
				if debugMainloop {
					log.Println("mapDownloadLoop exit")
				}
				goto MAINLOOP_EXIT
			}
		} else {
			if err := nox_xxx_gameChangeMap_43DEB0(); err != nil {
				if err != nil && err != ErrMapDownload {
					gameLog.Println(err)
				}
				// XXX
				if mapDownloading() {
					continue mainloop
				}
				mainloopStop()
				if debugMainloop {
					log.Println("nox_xxx_gameChangeMap_43DEB0 exit")
				}
				goto MAINLOOP_EXIT
			}
		}
		if C.nox_xxx_check_flag_aaa_43AF70() == 1 {
			C.sub_40D250()
			C.sub_40DF90()
		}
		nox_framerate_limit_416C70(30)
		processInput()
		C.sub_413520_gamedisk()
		C.nox_xxx_time_startProfile_435770()
		if !gameStateFunc() {
			if debugMainloop {
				log.Println("gameStateFunc exit")
			}
			goto MAINLOOP_EXIT
		}
		C.nox_xxx_time_endProfile_435780()
		C.sub_435740()
		if !isDedicatedServer {
			C.sub_430880(1)
			if nox_draw_unk1 != nil && !nox_draw_unk1() {
				if debugMainloop {
					log.Println("call_nox_draw_unk1 exit")
				}
				goto MAINLOOP_EXIT
			}
			C.sub_430880(0)
		}
		if func_5D4594_816392 != nil && !func_5D4594_816392() {
			if debugMainloop {
				log.Println("call_func_5D4594_816392 exit")
			}
			goto MAINLOOP_EXIT
		}
		C.sub_4519C0()
		sub_4312C0()
		C.sub_495430()
		if noxflags.HasGame(noxflags.GameHost) && continueMenuOrHost {
			mainloopMaybeSwitchMapXXX()
		}
		drawAndPresent()
		C.sub_435750()
		if useFrameLimit {
			if noxflags.HasGame(noxflags.GameHost) && noxflags.HasGame(noxflags.GameFlag2) && !noxflags.HasEngine(noxflags.EngineNoRendering) && noxflags.HasGame(noxflags.GameFlag29) {
				if !noxflags.HasEngine(noxflags.EnginePause) {
					nox_ticks_maybe_sleep_416DD0()
				}
			} else {
				if !noxflags.HasEngine(noxflags.EngineSleep) {
					for !nox_ticks_should_update_416CD0() {
						mainloopSleep(time.Microsecond)
					}
				} else {
					ms := nox_ticks_until_next_416D00()
					*memmap.PtrUint32(0x5D4594, 816404) = uint32(ms)
					if ms > 0 {
						mainloopSleep(time.Duration(ms) * time.Millisecond)
					}
				}
			}
		}
		if C.nox_game_loop_xxx_805872 != 0 {
			continueMenuOrHost = true
		} else {
			if mainloopContinue {
				// unwind the stack and continue the mainloop
				continue mainloop
			}
		}
	MAINLOOP_EXIT:
		if !exitPath {
			if !continueMenuOrHost {
				cleanup()
				nox_exit(0)
			}
			// repeat
			if C.nox_game_loop_xxx_805872 == 0 {
				C.sub_43DB60()
				C.sub_43D990()
				g_v20 = true
				sub_43F140(800)
				nox_common_initRandom_415F70()
				gameFrameSetFromFlags()
				C.nox_ensure_thing_bin()
				*memmap.PtrUint32(0x85B3FC, 960) = 0
				*memmap.PtrUint32(0x85B3FC, 4) = 0
				if mainloopConnectResultOK {
					if debugMainloop {
						log.Println("CONNECT_RESULT_OK retry")
					}
					CONNECT_RESULT_OK()
					continue mainloop
				}
				if noxflags.HasGame(noxflags.GameHost) {
					if err := noxServer.nox_xxx_servNewSession_4D1660(); err != nil {
						log.Println(err)
						continue mainloop
					}
				}
				if !nox_xxx_clientResetSpriteAndGui_4357D0(mainloopNoSkip) {
					continue mainloop
				}
				if noxflags.HasGame(noxflags.GameHost) && noxflags.HasGame(noxflags.GameFlag23) && noxflags.HasEngine(noxflags.EngineFlag1) {
					v23 := nox_fs_root()
					C.sub_4D39F0(v23)
					if C.nox_xxx_mapGenStart_4D4320() == 0 {
						C.nox_xxx_mapSwitchLevel_4D12E0(0)
						continue mainloop
					}
					sub_4D3C30()
					noxflags.UnsetGame(noxflags.GameFlag23)
				}
				CONNECT_OR_HOST()
				continue mainloop
			}
			nox_xxx_cliSetupSession_437190()
			gameUpdateVideoMode(true)
			nox_client_initScreenParticles_431390()
			cmainLoop()
			continue mainloop
		}
		if debugMainloop {
			log.Println("MAINLOOP_EXIT")
		}
		noxflags.UnsetGame(noxflags.GameFlag29)
		noxflags.UnsetGame(noxflags.GameModeKOTR | noxflags.GameModeCTF | noxflags.GameModeFlagBall | noxflags.GameModeChat | noxflags.GameModeArena | noxflags.GameModeSolo10 | noxflags.GameModeElimination | noxflags.GameModeQuest | noxflags.GameFlag15 | noxflags.GameFlag16)
		noxflags.UnsetGame(noxflags.GameFlag24 | noxflags.GameFlag21)
		sub_43F140(300)
		C.sub_43D990()
		nox_xxx_replayWriteFrame_4D39B0()
		if noxflags.HasGame(noxflags.GameHost) {
			C.nox_xxx_servResetPlayers_4D23C0()
		}
		if noxflags.HasGame(noxflags.GameFlag2) {
			sub_435EB0()
		}
		if err := gameUpdateVideoMode(true); err != nil {
			if debugMainloop {
				log.Printf("gameUpdateVideoMode: %v (%s)", err, caller(0))
			}
			continue mainloop
		}
		*memmap.PtrUint32(0x587000, 80852) = uint32(nox_video_getGammaSetting_434B00())
		nox_video_setGammaSetting_434B30(1)
		C.sub_434B60()
		mainloopConnectResultOK = false
		if noxflags.HasGame(noxflags.GameHost) {
			noxServer.nox_xxx_servEndSession_4D3200()
		}
		if noxflags.HasGame(noxflags.GameFlag2) {
			nox_xxx_cliSetupSession_437190()
		}
		inputClearKeyTimeouts()
		if noxflags.HasEngine(noxflags.EngineGameLoopMemdump) {
			C.nox_xxx_gameLoopMemDump_413E30()
		}
		// C.nullsub_2()

		// repeat
		cmainLoop()
		continue mainloop
	}
}

//export nox_game_cdMaybeSwitchState_413800
func nox_game_cdMaybeSwitchState_413800() {
	if memmap.Uint32(0x5D4594, 251724) == 0 {
		*memmap.PtrUint32(0x5D4594, 251724) = 1
		if !nox_game_switchStates() {
			C.sub_413760()
		}
	}
}

func nox_xxx_clientResetSpriteAndGui_4357D0(noSkip bool) bool {
	clientSetPlayerNetCode(0)
	*memmap.PtrUint32(0x852978, 8) = 0
	*memmap.PtrUint32(0x8531A0, 2576) = 0
	// TODO: size is a guess
	StrCopy((*C.char)(memmap.PtrOff(0x5D4594, 811280)), 1024, GoString(C.nox_xxx_getRandomName_4358A0()))
	if noSkip {
		*memmap.PtrUint32(0x587000, 85724) = 0
	}
	*memmap.PtrUint32(0x5D4594, 811064) = uint32(C.nox_client_renderGUI_80828)
	C.nox_netlist_resetAll_40EE60()
	if !noxflags.HasGame(noxflags.GameHost) {
		noxServer.resetAllPlayers()
	}
	if !nox_xxx_chatInit_48D7D0() {
		return false
	}
	C.sub_4E4EF0()
	C.sub_48D740()
	nox_xxx_gameSetCliConnected(false)
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	C.sub_473930()
	C.sub_48D4B0(0)
	return true
}

//----- (0048D7D0) --------------------------------------------------------
func nox_xxx_chatInit_48D7D0() bool {
	C.nox_alloc_chat_1197364 = unsafe.Pointer(nox_new_alloc_class(internCStr("Chat"), 692, 64))
	return C.nox_alloc_chat_1197364 != nil
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
	sub_43F140(300)
	if !isDedicatedServer {
		if !sub_43C060() {
			return
		}
	}
	if !nox_xxx_cliWaitForJoinData_43BFE0() {
		return
	}
	if g_v20 {
		C.sub_43DBA0()
		g_v20 = false
	}
	sub_43F1A0()
	mainloop_43E290(false)
}

func CONNECT_OR_HOST() {
	if debugMainloop {
		log.Println("CONNECT_OR_HOST")
		defer func() {
			log.Printf("CONNECT_OR_HOST exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	mode := videoGetGameMode()
	info := (*PlayerInfo)(unsafe.Pointer(C.nox_xxx_getHostInfoPtr_431770()))
	name := GoWString((*C.wchar_t)(memmap.PtrOff(0x85B3FC, 12204)))
	info.SetName(name)
	info.playerClass = C.uchar(getPlayerClass())
	info.isFemale = C.uchar(memmap.Uint8(0x85B3FC, 12255))
	info.field_2253 = C.ushort(memmap.Uint16(0x85B3FC, 12187))
	info.field_2255 = C.uchar(memmap.Uint8(0x85B3FC, 12189))
	info.SetField2256(memmap.Uint16(0x85B3FC, 12184))
	info.field_2258 = C.uchar(memmap.Uint8(0x85B3FC, 12186))
	info.field_2259 = C.ushort(memmap.Uint16(0x85B3FC, 12190))
	info.field_2261 = C.uchar(memmap.Uint8(0x85B3FC, 12192))
	info.SetField2262(memmap.Uint16(0x85B3FC, 12193))
	info.field_2264 = C.uchar(memmap.Uint8(0x85B3FC, 12195))
	info.field_2265 = C.ushort(memmap.Uint16(0x85B3FC, 12196))
	info.field_2267 = C.uchar(memmap.Uint8(0x85B3FC, 12198))
	info.field_2268 = C.uchar(memmap.Uint8(0x85B3FC, 12199))
	info.field_2269 = C.uchar(memmap.Uint8(0x85B3FC, 12200))
	info.field_2270 = C.uchar(memmap.Uint8(0x85B3FC, 12201))
	info.field_2271 = C.uchar(memmap.Uint8(0x85B3FC, 12202))
	info.field_2272 = C.uchar(memmap.Uint8(0x85B3FC, 12203))

	C.sub_48D740()

	var popts PlayerOpts
	popts.Screen = mode
	if s, ok := serial.Serial(); ok {
		popts.Serial = s
	}
	popts.Byte152 = byte(bool2int(!nox_xxx_checkHasSoloMaps()))
	if memmap.Uint8(0x85B3FC, 10980)&4 != 0 {
		popts.Byte152 |= 0x80
	}
	popts.Field2072 = GoString((*C.char)(memmap.PtrOff(0x85B3FC, 10395)))
	popts.Field2096 = GoString(C.sub_41FA40())
	popts.Field2068 = int(C.dword_5d4594_2660032)
	popts.Info = *info

	if noxflags.HasGame(noxflags.GameHost) {
		if err := nox_xxx_replay_4D3860(&popts); err != nil {
			log.Println(err)
			CONNECT_RESULT_FAIL(err)
			return
		}
		if !isDedicatedServer {
			clientSetPlayerNetCode(noxServer.newPlayer(31, &popts))
		}
		C.nox_client_setVersion_409AE0(NOX_CLIENT_VERS_CODE)
		if !isDedicatedServer {
			C.nox_netlist_receiveCli_494E90(31)
		}
		gameSetPlayState(2)
	} else {
		host := clientGetServerHost()
		port := clientGetServerPort()
		if err := CONNECT_SERVER(host, port, &popts); err != nil {
			log.Println(err)
			CONNECT_RESULT_FAIL(err)
			return
		}
	}
	CONNECT_RESULT_OK()
	return
}

func newConnectFailErr(code int, err error) *connectFailErr {
	if code == 0 {
		code = -1
	}
	return &connectFailErr{
		Err:    err,
		Code:   code,
		Caller: caller(1),
	}
}

type connectFailErr struct {
	Err    error
	Code   int
	Caller string
}

func (e *connectFailErr) Error() string {
	return fmt.Sprintf("CONNECT_SERVER failed: %s (code=%d, %s)", e.Err, e.Code, e.Caller)
}

func (e *connectFailErr) Unwrap() error {
	return e.Err
}

func CONNECT_SERVER(host string, port int, opts *PlayerOpts) error {
	if debugMainloop {
		log.Println("CONNECT_SERVER", host, port)
		defer func() {
			log.Printf("CONNECT_SERVER exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	narg := &netStructOpt{
		datasize: 2048,
		port:     port,
		funcyyy:  C.nox_xxx_netHandleCliPacket_43C860,
	}
	C.dword_5d4594_815704 = 0
	C.dword_5d4594_815708 = 0
	C.nox_xxx_allocNetGQueue_5520B0(200, 1024)
	ind, err := nox_xxx_netPreStructToFull(narg)
	if err != nil {
		return newConnectFailErr(0, err)
	}
	*memmap.PtrUint32(0x5D4594, 815700) = uint32(ind)

	if debugMainloop {
		log.Println("NET_CONNECT", ind, host, port)
	}
	ns := getNetStructByInd(ind)
	if ns == nil {
		if debugMainloop {
			log.Println("NET_CONNECT_THEN_FAIL", -3)
		}
		return newConnectFailErr(-3, errors.New("no net struct"))
	}
	if len(host) == 0 {
		if debugMainloop {
			log.Println("NET_CONNECT_THEN_FAIL", -4)
		}
		return newConnectFailErr(-4, errors.New("empty hostname"))
	}
	if port < 1024 || port > 0x10000 {
		if debugMainloop {
			log.Println("NET_CONNECT_THEN_FAIL", -15)
		}
		return newConnectFailErr(-15, errors.New("invalid port"))
	}
	if nox_net_init() == -1 {
		if debugMainloop {
			log.Println("NET_CONNECT_THEN_FAIL", -21)
		}
		return newConnectFailErr(-21, errors.New("net init failed"))
	}
	sock := newSocketUDP()
	if sock == nil {
		if debugMainloop {
			log.Println("NET_CONNECT_THEN_FAIL", -22)
		}
		return newConnectFailErr(-22, errors.New("cannot create socket"))
	}
	ns.SetSocket(sock)
	var ip net.IP
	if host[0] < '0' || host[0] > '9' {
		list, err := net.LookupIP(host)
		if err != nil || len(list) == 0 {
			log.Printf("error: cannot find ip for a host %q: %v", host, err)

			if debugMainloop {
				log.Println("NET_CONNECT_THEN_FAIL", -4)
			}
			return newConnectFailErr(-4, err)
		}
		ip = list[0]
	} else {
		ip = net.ParseIP(host)
	}
	ns.SetAddr(ip, port)

	cport := clientGetClientPort()
	for {
		err := sock.Bind(nil, cport)
		if err == nil {
			break
		} else if !ErrIsInUse(err) {
			if debugMainloop {
				log.Println("NET_CONNECT_THEN_FAIL", -1)
			}
			return newConnectFailErr(-1, err)
		}
		cport++
	}
	C.dword_5d4594_3844304 = 0
	var v12 [1]byte
	v11, err := nox_xxx_netSendSock_552640(ind, v12[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	if err != nil {
		return fmt.Errorf("cannot send data: %w", err)
	}

	if debugMainloop {
		log.Println("start NET_CONNECT_WAIT_LOOP")
	}
	id, retries, flags, counter := ind, 60, 6, 0
	for {
		if debugMainloop {
			log.Println("NET_CONNECT_WAIT_LOOP", id, v11, retries, flags, counter)
		}
		ns := getNetStructByInd(id)
		if ns == nil {
			if debugMainloop {
				log.Println("NET_CONNECT_WAIT_THEN_FAIL", -3)
				log.Println("NET_CONNECT_THEN_FAIL", -23)
			}
			return newConnectFailErr(-23, errors.New("no net struct"))
		}
		//counter = 0 // TODO: is this correct?
		counter++
		if counter > 20*retries {
			if debugMainloop {
				log.Println("NET_CONNECT_WAIT_THEN_FAIL", -23)
				log.Println("NET_CONNECT_THEN_FAIL", -23)
			}
			return newConnectFailErr(-23, errors.New("timeout"))
		}
		C.nox_xxx_servNetInitialPackets_552A80(C.uint(id), C.char(flags|1))
		C.nox_xxx_netMaybeSendAll_552460()
		f28 := int(int8(ns.field_28_1))
		if debugMainloop {
			log.Printf("NET_CONNECT_WAIT_LOOP: state %d\n", f28)
		}
		if f28 >= v11 {
			break
		}
		platform.Sleep(30 * time.Millisecond)
		if debugMainloop {
			log.Println("continue NET_CONNECT_WAIT_LOOP")
		}
	}

	if debugMainloop {
		log.Println("NET_CONNECT_WAIT_THEN_OK", id)
	}

	ns = getNetStructByInd(id)
	if C.dword_5d4594_3844304 != 0 && ns.ID() >= 0 {
		vs := unsafe.Slice((*byte)(memmap.PtrOff(0x5D4594, 2512892)), 1024)
		copy(vs, make([]byte, 1024))
		data, err := opts.MarshalBinary()
		if err != nil {
			return err
		}
		vs = vs[:3+len(data)]

		vs[0] = byte(noxnet.MSG_ACCEPTED)
		vs[1] = ns.Data2()[1]
		vs[2] = 32
		if len(data) > 0 {
			copy(vs[3:], data[:153])
		}
		nox_xxx_netSendSock_552640(id, vs, NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	}

	if ns.ID() < 0 {
		if debugMainloop {
			log.Println("NET_CONNECT_THEN_FAIL", -1)
		}
		return newConnectFailErr(-1, errors.New("invalid net struct id"))
	}
	if debugMainloop {
		log.Println("NET_CONNECT_THEN_OK")
	}

	if !noxflags.HasGame(noxflags.GameHost) {
		C.dword_5d4594_2649712 |= 0x80000000
	}
	C.nox_netlist_resetByInd_40ED10(31, 0)
	C.nox_xxx_set3512_40A340(0)
	nox_xxx_setMapCRC_40A360(0)

	deadline := platform.Ticks() + 10*time.Second
	if debugMainloop {
		log.Println("CONNECT_WAIT_LOOP_START", deadline)
	}
	for {
		now := platform.Ticks()
		if debugMainloop {
			log.Println("CONNECT_WAIT_LOOP", now, deadline, deadline-now)
		}
		if now >= deadline {
			if debugMainloop {
				log.Println("CONNECT_WAIT_THEN_DEADLINE")
			}
			return newConnectFailErr(-19, errors.New("timeout 2"))
		}
		C.nox_xxx_servNetInitialPackets_552A80(C.uint(memmap.Uint32(0x5D4594, 815700)), 1)
		C.nox_xxx_netSendBySock_40EE10(C.uint(memmap.Uint32(0x5D4594, 815700)), 31, 0)
		C.nox_netlist_resetByInd_40ED10(31, 0)
		C.nox_xxx_netMaybeSendAll_552460()
		if nox_xxx_getMapCRC_40A370() != 0 {
			break
		}
		platform.Sleep(5 * time.Millisecond)
		if debugMainloop {
			log.Println("continue CONNECT_WAIT_LOOP")
		}
	}
	if debugMainloop {
		log.Println("CONNECT_WAIT_THEN_SUCCESS")
	}
	if vers := C.nox_client_getVersionCode_409AD0(); vers != NOX_CLIENT_VERS_CODE {
		err := fmt.Errorf("invalid client version: %x", int(vers))
		log.Println(err)
		return newConnectFailErr(-20, err)
	}
	gameSetPlayState(2)
	if !noxflags.HasGame(noxflags.GameHost) {
		noxServer.teamsReset()
	}
	return nil
}

func CONNECT_RESULT_FAIL(err error) {
	errcode := 0
	if e, ok := err.(*connectFailErr); ok {
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
	if noxflags.HasGame(noxflags.GameFlag2) {
		nox_xxx_cliSetupSession_437190()
	}
	inputClearKeyTimeouts()
	if noxflags.HasEngine(noxflags.EngineGameLoopMemdump) {
		C.nox_xxx_gameLoopMemDump_413E30()
	}
	nox_client_showConnError_43D0A0(errcode)
	cmainLoop()
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
	C.sub_44A360(1)
}

func CONNECT_RESULT_OK() {
	if debugMainloop {
		log.Printf("CONNECT_RESULT_OK (%s)\n", caller(1))
		defer func() {
			log.Printf("CONNECT_RESULT_OK exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	mainloopConnectResultOK = true
	if err := noxServer.nox_xxx_replayStartReadingOrSaving_4D38D0(); err != nil {
		if debugMainloop {
			log.Println("nox_xxx_replayStartReadingOrSaving_4D38D0:", err)
		}
		cmainLoop()
		return
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		nox_xxx_setGameState_43DDF0(nil)
	} else if !noxServer.nox_xxx_servInitialMapLoad_4D17F0() {
		if debugMainloop {
			log.Println("nox_xxx_servInitialMapLoad_4D17F0 exit")
		}
		cmainLoop()
		return
	}
	if !noxflags.HasGame(noxflags.GameFlag2) {
		gameSetCliDrawFunc(nil)
	} else {
		if !noxflags.HasGame(noxflags.GameFlag21) {
			if mode := videoGetGameMode(); mode.W == 0 || mode.H == 0 {
				mode.W = noxDefaultWidth
				mode.H = noxDefaultHeight
				videoUpdateGameMode(mode)
			}
			if err := gameUpdateVideoMode(false); err != nil {
				if debugMainloop {
					log.Printf("gameUpdateVideoMode: %v (%s)", err, caller(0))
				}
				return
			}
		}
		if err := initGameSession435CC0(); err != nil {
			gameLog.Println("failed to init game session:", err)
			cmainLoop()
			return
		}
	}
	if noxflags.HasEngine(noxflags.EngineGameLoopMemdump) {
		C.nox_xxx_gameLoopMemDump_413E30()
	}
	if noxflags.HasGame(noxflags.GameOnline) && noxflags.HasGame(noxflags.GameHost) && C.sub_43AF40() != 0 {
		C.sub_43AA70()
	}
	sub_43F1A0()
	nox_video_setGammaSetting_434B30(C.int(memmap.Int32(0x587000, 80852)))
	C.sub_434B60()
	noxflags.SetGame(noxflags.GameFlag29)
	mainloop_43E290(true)
}

func mainloopMaybeSwitchMapXXX() {
	if C.nox_client_gui_flag_815132 != 0 {
		return
	}
	if !noxflags.HasGame(noxflags.GameOnline) {
		return
	}
	if C.nox_server_gameDoSwitchMap_40A680() != 0 {
		C.nox_xxx_netGameSettings_4DEF00()
		C.nox_server_gameUnsetMapLoad_40A690()
	} else if C.sub_459D60() != 0 && !noxflags.HasGame(noxflags.GameFlag24|noxflags.GameFlag21) {
		if C.sub_459DA0() != 0 {
			C.sub_4DF020()
		}
		C.sub_459D50(0)
	}
	if gameFrame() >= memmap.Uint32(0x5D4594, 816400) {
		C.sub_4161E0()
		C.sub_416690()
		*memmap.PtrUint32(0x5D4594, 816400) = gameFrame() + 60*gameFPS()
	}
}

var gameStateFunc func() bool

func nox_xxx_setGameState_43DDF0(fnc func() bool) {
	if fnc != nil {
		gameStateFunc = fnc
	} else {
		if debugMainloop {
			log.Println("gameStateFunc = nil")
		}
		gameStateFunc = func() bool {
			return true
		}
	}
}

func nox_xxx_cliWaitForJoinData_43BFE0() bool {
	if debugMainloop {
		log.Println("gameStateFunc = nox_xxx_gameStateWait_43C020")
	}
	nox_xxx_setGameState_43DDF0(nox_xxx_gameStateWait_43C020)
	gameSetCliDrawFunc(nil)
	if memmap.Uint32(0x587000, 91840) != 0 {
		*memmap.PtrUint32(0x587000, 91840) = 0
		C.nox_client_gui_flag_815132 = 1
		return true
	}
	if !nox_game_switchStates() {
		return false
	}
	C.nox_client_gui_flag_815132 = 1
	return true
}

func nox_xxx_gameStateWait_43C020() bool {
	gameFrameInc()
	if C.nox_client_gui_flag_815132 != 0 {
		return true
	}
	if !isDedicatedServer {
		noxrend.SelectColor(uint32(C.nox_color_black_2650656))
		noxrend.ClearScreen()
	}
	return false
}

func nox_xxx_cliSetupSession_437190() {
	if C.nox_xxx_check_flag_aaa_43AF70() == 1 {
		C.sub_40D380()
	}
	C.sub_473960()
	noxServer.resetAllPlayers()
	C.sub_455EE0()
	C.sub_456240()
	C.sub_48D800()
	C.sub_49A8C0()
	sub_470550()
	sub_46C5D0()
	C.sub_44DF70()
	if !noxflags.HasGame(noxflags.GameHost) {
		C.sub_43CC80()
	}
	gameSetPlayState(0)
	if !noxflags.HasGame(noxflags.GameHost) {
		C.sub_4E4DE0()
	}
	noxServer.nox_xxx_mapLoad_40A380()
	clientSetServerHost("")
	C.sub_446580(1)
	C.sub_48D760()
	if !noxflags.HasGame(noxflags.GameHost) {
		C.nox_netlist_resetAll_40EE60()
	}
	C.sub_417CF0()
	clientSetPlayerNetCode(0)
	*memmap.PtrUint32(0x852978, 8) = 0
	*memmap.PtrUint32(0x8531A0, 2576) = 0
}

//export sub_470510
func sub_470510() {
	if C.dword_5d4594_1090048 != nil {
		if C.dword_5d4594_1090120 == 2 {
			C.dword_587000_145664 = 1
		} else {
			C.dword_587000_145668 = C.dword_5d4594_1090120
			C.dword_5d4594_1090120 = 0
			sub_4703F0()
		}
	}
}

func sub_470550() {
	if C.dword_5d4594_1090048 != nil && C.dword_5d4594_1090120 != 0 {
		C.dword_5d4594_1090120 = 4
		sub_4703F0()
	}
}

//export sub_4703F0
func sub_4703F0() {
	C.dword_5d4594_1090120 = (C.dword_5d4594_1090120 + 1) % 6
	v1 := int32(C.dword_5d4594_1090120)
	if C.nox_xxx_check_flag_aaa_43AF70() != 0 || v1 != 5 {
		if v1 == 1 {
			if !noxflags.HasGame(noxflags.GameModeQuest) {
				v1 = int32((C.dword_5d4594_1090120 + 1) % 6)
				C.dword_5d4594_1090120 = (C.dword_5d4594_1090120 + 1) % 6
			}
		}
	} else {
		v1 = 0
		C.dword_5d4594_1090120 = 0
	}
	switch v1 {
	case 0:
		guiFocus(nil)
		asWindow(C.dword_5d4594_1090048).Hide()
		asWindow(C.dword_5d4594_1090100).Hide()
		*(*uint32)(unsafe.Add(*memmap.PtrPtr(6112660, 0x10A204), 4)) &= 0xFFFFFFF7
		*(*uint32)(unsafe.Add(*memmap.PtrPtr(6112660, 0x10A208), 4)) &= 0xFFFFFFF7
	case 1, 2:
		nox_xxx_wndShowModalMB(asWindow(C.dword_5d4594_1090048))
		sub := asWindow(C.dword_5d4594_1090100)
		nox_xxx_wndShowModalMB(sub)
		sub.Show()
		*(*uint32)(unsafe.Add(*memmap.PtrPtr(6112660, 0x10A204), 4)) |= 8
		*(*uint32)(unsafe.Add(*memmap.PtrPtr(6112660, 0x10A208), 4)) |= 8
		C.dword_587000_145664 = 1
	case 3, 4, 5:
		C.dword_587000_145664 = 1
	}
}

func (s *Server) nox_xxx_mapLoad_40A380() {
	C.nox_xxx_set3512_40A340(0)
	nox_xxx_setMapCRC_40A360(0)
	name := GoString((*C.char)(memmap.PtrOff(0x5D4594, 3608)))
	s.nox_xxx_gameSetMapPath_409D70(name)
	noxflags.SetGame(noxflags.GameHost | noxflags.GameFlag2)
	noxflags.UnsetGame(noxflags.GameFlag3 | noxflags.GameFlag4 | noxflags.GameModeKOTR | noxflags.GameModeCTF | noxflags.GameModeFlagBall | noxflags.GameModeChat | noxflags.GameModeArena | noxflags.GameModeSolo10 | noxflags.GameModeElimination | noxflags.GameModeQuest | noxflags.GameFlag18) // TODO
	C.nox_server_gameSettingsUpdated = 1
}

func (s *Server) nox_xxx_gameSetMapPath_409D70(path string) {
	log.Printf("set map path: %q", path)
	C.nox_xxx_gameSetMapPath_409D70(internCStr(path))
}

func map_download_finish() int {
	nox_xxx_guiDownloadClose_4CC930()
	if mapsend.downloadOK {
		if mode := videoGetGameMode(); mode.W == 0 || mode.H == 0 {
			mode.W = noxDefaultWidth
			mode.H = noxDefaultHeight
			videoUpdateGameMode(mode)
		}
	}

	if !mapsend.downloadOK {
		noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
		return 0
	}
	C.nox_xxx_gui_43E1A0(0)
	if !noxflags.HasEngine(noxflags.EngineNoRendering) {
		C.nox_gameDisableMapDraw_5d4594_2650672 = 1
		C.nox_client_fadeXxx_44DA60(1)
	}
	fname := noxServer.nox_server_currentMapGetFilename_409B30()
	if err := nox_xxx_mapCliReadAll_4AC2B0(fname); err != nil {
		gameLog.Println(err)
		v6 := strMan.GetStringInFile("MapLoadError", "C:\\NoxPost\\src\\Client\\System\\gameloop.c")
		C.go_call_sub_4516C0(internWStr(v6), internCStr(fname))
		C.nox_xxx_spriteLoadError_4356E0()
		return 0
	}
	if noxflags.HasGame(noxflags.GameHost) {
		C.nox_xxx_gameServerReadyMB_4DD180(31)
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
	C.nox_common_writecfgfile(internCStr("nox.cfg"))
	if noxflags.HasGame(noxflags.GameHost) {
		C.nox_xxx_playerDisconnFinish_4DE530(31, 2)
	} else {
		nox_xxx_cliSendOutgoingClient_43CB50()
	}
	C.sub_499450()
	C.nox_xxx_gameClearAll_467DF0(0)
	C.sub_495AE0()
	C.sub_4959D0()
	sub_473B30_free()
	C.sub_496120()
	sub_473840()
	C.nox_things_free_44C580()
	sub_49A950_free()
	C.nox_drawable_free()
	C.sub_49AEA0()
	C.nox_xxx_j_resetNPCRenderData_49A2E0()
	C.sub_4951C0()
	gameSetPlayState(2)
}

func nox_xxx_printCentered_445490(str string) {
	wstr, free := CWString(str)
	defer free()
	C.nox_xxx_printCentered_445490(wstr)
}

var (
	ErrMapDownload = errors.New("map download started")
)

func nox_xxx_gameChangeMap_43DEB0() error {
	if noxflags.HasGame(noxflags.GameFlag24) {
		nox_client_setCursorType_477610(10)

		mapName := ""
		if nox_xxx_gameIsNotMultiplayer_4DB250() {
			mapName = nox_xxx_mapFilenameGetSolo_4DB260()
		} else {
			mapName = noxServer.nox_server_currentMapGetFilename_409B30()
		}
		gameLog.Printf("nox_xxx_gameChangeMap_43DEB0: %q", mapName)
		// TODO: remove this partial path denormalization once we port map parsing
		mapName2 := mapName
		if i := strings.LastIndexByte(mapName2, '/'); i >= 0 {
			mapName2 = mapName2[:i] + "\\" + mapName2[i+1:]
		}
		crc := C.nox_xxx_mapCrcGetMB_409B00()
		v3 := C.nox_xxx_mapValidateMB_4CF470(internCStr(mapName2), crc)
		if v3&0x2 == 0 {
			gameLog.Printf("nox_xxx_mapValidateMB_4CF470: invalid or missing map file: %q", mapName)
		}
		if v3&0x4 == 0 {
			gameLog.Printf("nox_xxx_mapValidateMB_4CF470: CRC check failed: %q (expected: 0x%x)", mapName, crc)
		}
		gameLog.Println("nox_xxx_mapValidateMB_4CF470:", uint32(v3))
		if v3&2 != 0 && v3&4 != 0 {
			sub_43F140(500)
			if err := nox_xxx_mapCliReadAll_4AC2B0(mapName); err != nil {
				err = fmt.Errorf("change map failed: %w", err)
				gameLog.Println(err)
				v13 := noxServer.nox_server_currentMapGetFilename_409B30()
				v6 := strMan.GetStringInFile("MapLoadError", "C:\\NoxPost\\src\\Client\\System\\gameloop.c")
				C.go_call_sub_4516C0(internWStr(v6), internCStr(v13))
				C.nox_xxx_spriteLoadError_4356E0()
				return err
			}
			sub_43F1A0()
			if noxflags.HasGame(noxflags.GameHost) {
				C.nox_xxx_gameServerReadyMB_4DD180(31)
			} else {
				nox_xxx_netSendClientReady_43C9F0()
			}
			nox_xxx_gameSetCliConnected(true)
			if memmap.Int32(0x973F18, 3800) < 0 {
				v7 := strMan.GetStringInFile("cdecode.c:EnterChat", "C:\\NoxPost\\src\\Client\\System\\gameloop.c")
				nox_xxx_printCentered_445490(v7)
				v14 := ctrlEvent.sub_42E8E0_go(8, 1)
				v8 := strMan.GetStringInFile("cdecode.c:KeyToChat", "C:\\NoxPost\\src\\Client\\System\\gameloop.c")
				nox_xxx_printCentered_445490(fmt.Sprintf(v8, v14))
			}
			if !noxflags.HasEngine(noxflags.EngineNoRendering) {
				C.nox_gameDisableMapDraw_5d4594_2650672 = 1
				C.nox_client_fadeXxx_44DA60(1)
			}
		} else if !noxflags.HasGame(noxflags.GameHost) {
			if v3&1 == 0 || v3&4 != 0 {
				noxflags.SetGame(noxflags.GameFlag21)
			} else {
				noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
				sub_477530(1)
				C.nox_xxx_gui_43E1A0(1)
				v12 := strMan.GetStringInFile("OverwriteReadOnly", "C:\\NoxPost\\src\\Client\\System\\gameloop.c")
				v10 := strMan.GetStringInFile("Warning", "C:\\NoxPost\\src\\Client\\System\\gameloop.c")
				NewDialogWindow(nil, v10, v12, 24, C.sub_43E230, C.sub_43E200)
			}
		} else {
			if !isDedicatedServer {
				C.nox_xxx_gameServerReadyMB_4DD180(31)
			}
			if !noxflags.HasEngine(noxflags.EngineNoRendering) {
				C.nox_gameDisableMapDraw_5d4594_2650672 = 1
				C.nox_client_fadeXxx_44DA60(1)
			}
		}
	}
	if noxflags.HasGame(noxflags.GameFlag21) {
		map_download_start()
		return ErrMapDownload
	}
	if noxflags.HasGame(noxflags.GameFlag21 | noxflags.GameFlag24) {
		noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
	}
	return nil
}

//export nox_xxx_cliDrawConnectedLoop_43B360
func nox_xxx_cliDrawConnectedLoop_43B360() C.int {
	noxflags.SetGame(noxflags.GameFlag3)
	noxflags.UnsetGame(noxflags.GameHost)
	v0 := GoStringP(unsafe.Add(C.dword_5d4594_814624, 12))
	if v0 == "" {
		clientSetServerHost("localhost")
	} else {
		v1 := clientGetServerPort()
		v5 := fmt.Sprintf("%s:%d", v0, v1)
		C.nox_xxx_copyServerIPAndPort_431790(internCStr(v5))
		clientSetServerHost(v0)
	}
	C.nox_common_writecfgfile(internCStr("nox.cfg"))
	v2 := *(*int8)(unsafe.Add(C.dword_5d4594_814624, 102))
	if v2 >= 0 {
		videoSetMaxSize(noxVideoMax)
	} else if res, ok := videoModeByID(byte(v2) & 0x7F); ok {
		videoSetMaxSize(res)
	} else {
		videoSetMaxSize(noxVideoMax)
	}
	sub_44A400()
	C.nox_client_guiXxx_43A9D0()
	nox_client_guiXxxDestroy_4A24A0()
	return 1
}

//export nox_client_guiXxxDestroy_4A24A0
func nox_client_guiXxxDestroy_4A24A0() C.int {
	sub_4A1BD0()
	sub_46C5D0()
	C.nox_client_gui_flag_815132 = 0
	return 1
}

func sub_4A1BD0() {
	asWindowP(C.dword_5d4594_1307292).Destroy()
}
