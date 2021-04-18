package main

/*
#include <fenv.h>

#include "proto.h"
#include "common__log.h"
#include "common__system__team.h"
#include "common__system__gamedisk.h"
#include "common__net_list.h"
#include "client__system__gameloop.h"
#include "client__drawable__drawdb.h"

extern unsigned int nox_game_loop_xxx_805872;
extern unsigned int dword_5d4594_2660032;
extern unsigned int dword_5d4594_811372;
extern unsigned int dword_5d4594_815704;
extern unsigned int dword_5d4594_815708;
extern unsigned int dword_5d4594_3844304;
extern unsigned int dword_5d4594_2649712;
extern unsigned int nox_xxx_netStructID_815700;
extern unsigned int dword_5d4594_2618912;
extern unsigned int nox_client_gui_flag_815132;
extern unsigned int nox_gameFPS;
extern unsigned int nox_xxx_gameDownloadInProgress_587000_173328;
extern char nox_clientServerAddr[32];

int call_func_5D4594_816392();
int call_nox_draw_unk1();
*/
import "C"
import (
	"errors"
	"fmt"
	"log"
	"net"
	"os"
	"path/filepath"
	"runtime"
	"strings"
	"time"
	"unsafe"

	"nox/common/alloc"
	noxflags "nox/common/flags"
	"nox/common/fs"
	"nox/common/memmap"
	"nox/common/platform"
)

const NOX_CLIENT_VERS_CODE = C.NOX_CLIENT_VERS_CODE

var (
	debugMainloop           = os.Getenv("NOX_DEBUG_MAINLOOP") == "true"
	g_v20                   bool
	mainloopConnectResultOK bool
	mainloopExitPath        bool
	mainloopEnter           func()
	mainloopContinue        = true // nox_continue_mainloop_93196
	continueMenuOrHost      = true // nox_game_continueMenuOrHost_93200
	g_argc2                 int
	g_argv2                 **C.char
)

//export nox_xxx_setContinueMenuOrHost_43DDD0
func nox_xxx_setContinueMenuOrHost_43DDD0(v C.int) {
	if debugMainloop {
		log.Println("nox_xxx_setContinueMenuOrHost_43DDD0 =", int(v))
	}
	continueMenuOrHost = v != 0
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
	C.nox_xxx_gameSetCliConnected_43C720(0)
	if C.nox_xxx_check_flag_aaa_43AF70() != 1 {
		return
	}
	if !noxflags.HasGame(noxflags.GameFlag26) {
		C.sub_40D380()
	}
}

func mainloop_43E290() {
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
	C.nox_xxx_gameStopDownload_4AB560(0)

	mainloopEnter = nil
mainloop:
	for mainloopContinue {
		if mainloopEnter != nil {
			if debugMainloop {
				log.Printf("mainloop continues (%s)\n", caller(1))
			}
			mainloopEnter()
			continue mainloop
		}
		if C.nox_xxx_gameDownloadInProgress_587000_173328 != 0 {
			ret := C.map_download_loop(0)
			if ret == -1 {
				continue mainloop
			} else if ret == 0 {
				// map error
				mainloopContinue = false
				continueMenuOrHost = false
				if debugMainloop {
					log.Println("map_download_loop exit")
				}
				goto MAINLOOP_EXIT
			}
		} else {
			C.fesetround(C.FE_TOWARDZERO)
			if C.nox_xxx_gameChangeMap_43DEB0() == 0 {
				// XXX
				if C.nox_xxx_gameDownloadInProgress_587000_173328 != 0 {
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
		if C.nox_xxx_check_flag_aaa_43AF70() == 1 {
			C.sub_40D250()
			C.sub_40DF90()
		}
		nox_framerate_limit_416C70(30)
		inpHandler.Tick()
		C.sub_413520_gamedisk()
		C.nox_xxx_time_startProfile_435770()
		if fnc := gameStateFunc; !gameStateFunc() {
			if debugMainloop {
				log.Println("gameStateFunc exit", fnc)
			}
			goto MAINLOOP_EXIT
		}
		C.nox_xxx_time_endProfile_435780()
		C.sub_435740()
		if !isDedicatedServer {
			C.sub_430880(1)
			C.nox_client_processMouseInput_4308A0(1)
			C.nox_xxx_cursorUpdate_46B740()
			mainloopKeysUpdate()
			if C.call_nox_draw_unk1() == 0 {
				if debugMainloop {
					log.Println("call_nox_draw_unk1 exit")
				}
				goto MAINLOOP_EXIT
			}
			C.sub_430880(0)
		}
		if C.call_func_5D4594_816392() == 0 {
			if debugMainloop {
				log.Println("call_func_5D4594_816392 exit")
			}
			goto MAINLOOP_EXIT
		}
		C.sub_4519C0()
		C.sub_4312C0()
		C.sub_495430()
		if noxflags.HasGame(noxflags.GameHost) && continueMenuOrHost {
			mainloopMaybeSwitchMapXXX()
		}
		if C.nox_client_gui_flag_815132 != 0 {
			C.sub_43C380()
			resetEngineFlag(NOX_ENGINE_FLAG_32)
			generateMouseSparks()
		}
		if !getEngineFlag(NOX_ENGINE_FLAG_32) {
			mainloopDrawAndPresent()
		}
		C.sub_435750()
		if memmap.Uint32(0x587000, 93192) != 0 {
			if noxflags.HasGame(noxflags.GameHost) && noxflags.HasGame(noxflags.GameFlag2) && !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) && noxflags.HasGame(noxflags.GameFlag29) {
				if !getEngineFlag(NOX_ENGINE_FLAG_32) {
					nox_ticks_maybe_sleep_416DD0()
				}
			} else {
				if !getEngineFlag(NOX_ENGINE_FLAG_31) {
					for !nox_ticks_should_update_416CD0() {
					}
				} else {
					ms := nox_ticks_until_next_416D00()
					*memmap.PtrUint32(0x5D4594, 816404) = uint32(ms)
					if ms > 0 {
						platform.Sleep(time.Duration(ms) * time.Millisecond)
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
		if !mainloopExitPath {
			if !continueMenuOrHost {
				cleanup()
				nox_exit(0)
			}
			// repeat
			if C.nox_game_loop_xxx_805872 == 0 {
				C.sub_43DB60()
				C.sub_43D990()
				g_v20 = true
				C.sub_43F140(800)
				nox_common_initRandom_415F70()
				gameFrameSetFromFlags()
				C.nox_ensure_thing_bin()
				*memmap.PtrUint32(0x5D4594, 2650664) = 0
				*memmap.PtrUint32(0x5D4594, 2649708) = 0
				if mainloopConnectResultOK {
					if debugMainloop {
						log.Println("CONNECT_RESULT_OK retry")
					}
					CONNECT_RESULT_OK()
					continue mainloop
				}
				if noxflags.HasGame(noxflags.GameHost) {
					if C.nox_xxx_servNewSession_4D1660() == 0 {
						continue mainloop
					}
				}
				if C.nox_xxx_clientResetSpriteAndGui_4357D0(C.int(g_argc2), g_argv2) == 0 {
					continue mainloop
				}
				if noxflags.HasGame(noxflags.GameHost) && noxflags.HasGame(noxflags.GameFlag23) && getEngineFlag(NOX_ENGINE_FLAG_1) {
					v23 := nox_fs_root()
					C.sub_4D39F0(v23)
					if C.nox_xxx_mapGenStart_4D4320() == 0 {
						C.nox_xxx_mapSwitchLevel_4D12E0(0)
						continue mainloop
					}
					C.sub_4D3C30()
					noxflags.UnsetGame(noxflags.GameFlag23)
				}
				CONNECT_OR_HOST()
				continue mainloop
			}
			nox_xxx_cliSetupSession_437190()
			gameUpdateVideoMode(true)
			C.nox_client_initScreenParticles_431390()
			cmainLoop()
			continue mainloop
		}
		if debugMainloop {
			log.Println("MAINLOOP_EXIT")
		}
		noxflags.UnsetGame(noxflags.GameFlag29)
		noxflags.UnsetGame(0xD7F0)
		noxflags.UnsetGame(noxflags.GameFlag24 | noxflags.GameFlag21)
		C.sub_43F140(300)
		C.sub_43D990()
		C.nox_xxx_replayWriteSomeInt_4D39B0()
		if noxflags.HasGame(noxflags.GameHost) {
			C.nox_xxx_servResetPlayers_4D23C0()
		}
		if noxflags.HasGame(noxflags.GameFlag2) {
			C.sub_435EB0()
		}
		if err := gameUpdateVideoMode(true); err != nil {
			if debugMainloop {
				log.Printf("gameUpdateVideoMode: %v (%s)", err, caller(0))
			}
			continue mainloop
		}
		*memmap.PtrUint32(0x587000, 80852) = uint32(C.nox_video_getGammaSetting_434B00())
		C.nox_video_setGammaSetting_434B30(1)
		C.sub_434B60()
		mainloopConnectResultOK = false
		if noxflags.HasGame(noxflags.GameHost) {
			nox_xxx_servEndSession_4D3200()
		}
		if noxflags.HasGame(noxflags.GameFlag2) {
			nox_xxx_cliSetupSession_437190()
		}
		C.nox_xxx_clear18hDD_416190()
		if getEngineFlag(NOX_ENGINE_FLAG_13) {
			C.sub_413E30()
		}
		// C.nullsub_2()

		// repeat
		cmainLoop()
		continue mainloop
	}
}

func caller(skip int) string {
	pc, file, line, ok := runtime.Caller(skip + 1)
	if !ok {
		return "<unknown>"
	}
	fnc := "<unknown>"
	if f := runtime.FuncForPC(pc); f != nil {
		fnc = strings.TrimPrefix(f.Name(), "main.")
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
	C.sub_43F140(300)
	if C.sub_43C060() == 0 {
		return
	}
	if !nox_xxx_cliWaitForJoinData_43BFE0() {
		return
	}
	if g_v20 {
		C.sub_43DBA0()
		g_v20 = false
	}
	C.sub_43F1A0()
	mainloopExitPath = false
	mainloop_43E290()
}

func CONNECT_OR_HOST() {
	if debugMainloop {
		log.Println("CONNECT_OR_HOST")
		defer func() {
			log.Printf("CONNECT_OR_HOST exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	v5, v4, _ := nox_xxx_gameGetScreenBoundaries_getVideoMode()
	var info *C.char = C.nox_xxx_getHostInfoPtr_431770()
	infos := asByteSlice(unsafe.Pointer(info), 97)

	C.nox_wcscpy((*C.wchar_t)(unsafe.Pointer(&infos[0])), (*C.wchar_t)(memmap.PtrOff(0x5D4594, 2661908)))
	infos[66] = memmap.Uint8(0x5D4594, 2661958)
	infos[67] = memmap.Uint8(0x5D4594, 2661959)
	*(*uint16)(unsafe.Pointer(&infos[68])) = memmap.Uint16(0x5D4594, 2661891)
	infos[70] = memmap.Uint8(0x5D4594, 2661893)
	*(*uint16)(unsafe.Pointer(&infos[71])) = memmap.Uint16(0x5D4594, 2661888)
	infos[73] = memmap.Uint8(0x5D4594, 2661890)
	*(*uint16)(unsafe.Pointer(&infos[74])) = memmap.Uint16(0x5D4594, 2661894)
	infos[76] = memmap.Uint8(0x5D4594, 2661896)
	*(*uint16)(unsafe.Pointer(&infos[77])) = memmap.Uint16(0x5D4594, 2661897)
	infos[79] = memmap.Uint8(0x5D4594, 2661899)
	*(*uint16)(unsafe.Pointer(&infos[80])) = memmap.Uint16(0x5D4594, 2661900)
	infos[82] = memmap.Uint8(0x5D4594, 2661902)
	infos[83] = memmap.Uint8(0x5D4594, 2661903)
	infos[84] = memmap.Uint8(0x5D4594, 2661904)
	infos[85] = memmap.Uint8(0x5D4594, 2661905)
	infos[86] = memmap.Uint8(0x5D4594, 2661906)
	infos[87] = memmap.Uint8(0x5D4594, 2661907)

	Datas := alloc.Bytes(1024)
	defer alloc.FreeBytes(Datas)

	C.sub_48D740()
	*(*uint32)(unsafe.Pointer(&Datas[97])) = uint32(v5)
	*(*uint32)(unsafe.Pointer(&Datas[101])) = uint32(v4)
	C.nox_xxx_regGetSerial_420120((*C.uchar)(unsafe.Pointer(&Datas[105])))
	if C.nox_xxx_check_flag_aaa_43AF70() == 0 {
		C.nox_common_getInstallPath_40E0D0((*C.char)(unsafe.Pointer(&Datas[105])), internCStr("SOFTWARE\\Westwood\\Nox"), 0)
	}
	Datas[152] = byte(bool2int(C.nox_xxx_checkHasSoloMaps_40ABD0() == 0))
	if memmap.Uint8(0x5D4594, 2660684)&4 != 0 {
		Datas[152] |= 0x80
	}
	s1 := C.GoString((*C.char)(memmap.PtrOff(0x5D4594, 2660012+87)))
	StrCopyBytes(Datas[142:], s1)
	s2 := C.GoString(C.sub_41FA40())
	StrCopyBytes(Datas[128:], s2)
	*(*uint32)(unsafe.Pointer(&Datas[138])) = uint32(C.dword_5d4594_2660032)
	copy(Datas, infos[:97])

	if noxflags.HasGame(noxflags.GameHost) {
		C.nox_xxx_replay_4D3860(unsafe.Pointer(&Datas[0]))
		*memmap.PtrPtr(0x5D4594, 2616328) = newPlayer(31, unsafe.Pointer(&Datas[0]))
		C.nox_client_setVersion_409AE0(NOX_CLIENT_VERS_CODE)
		C.nox_xxx_netlist_494E90(31)
		C.dword_5d4594_811372 = 2
	} else {
		host := clientGetServerHost()
		port := clientGetServerPort()
		if err := CONNECT_SERVER(host, port, Datas[:153]); err != nil {
			log.Println(err)
			if debugMainloop {
				log.Println("goto CONNECT_RESULT")
			}
			mainloopEnter = func() {
				CONNECT_RESULT_FAIL(err.Code)
			}
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

func CONNECT_SERVER(host string, port int, data []byte) *connectFailErr {
	if debugMainloop {
		log.Println("CONNECT_SERVER", host, port, len(data))
		defer func() {
			log.Printf("CONNECT_SERVER exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	narg := (*C.nox_net_struct_arg_t)(alloc.Calloc(1, unsafe.Sizeof(C.nox_net_struct_arg_t{})))
	defer alloc.Free(unsafe.Pointer(narg))
	C.dword_5d4594_815704 = 0
	C.dword_5d4594_815708 = 0
	narg.data_size = 2048
	narg.port = C.int(port)
	C.nox_xxx_allocNetGQueue_5520B0(200, 1024)
	narg.func_yyy = (*[0]byte)(unsafe.Pointer(C.nox_xxx_netHandleCliPacket_43C860)) // TODO
	ind := int(C.nox_xxx_netPreStructToFull_5546F0(narg))
	C.nox_xxx_netStructID_815700 = C.uint(ind)

	if debugMainloop {
		log.Println("NET_CONNECT", ind, host, port, len(data))
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
		nox_net_stop()
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
			nox_net_stop()

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
			nox_net_stop()

			if debugMainloop {
				log.Println("NET_CONNECT_THEN_FAIL", -1)
			}
			return newConnectFailErr(-1, err)
		}
		cport++
	}
	C.dword_5d4594_3844304 = 0
	v12 := 0
	// TODO: passing Go pointer
	v11 := int8(C.nox_xxx_netSendSock_552640(C.uint(ind), (*C.char)(unsafe.Pointer(&v12)), 1, C.NOX_NET_SEND_NO_LOCK|C.NOX_NET_SEND_FLAG2))

	if debugMainloop {
		log.Println("start NET_CONNECT_WAIT_LOOP")
	}
	id, retries, flags, counter := ind, 60, 6, 0
	for {
		if debugMainloop {
			log.Println("NET_CONNECT_WAIT_LOOP", id, v11, retries, flags, counter, len(data))
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
		f28 := int8(ns.field_28_1)
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
		log.Println("NET_CONNECT_WAIT_THEN_OK", id, len(data))
	}
	data = data[:153]

	ns = getNetStructByInd(id)
	if C.dword_5d4594_3844304 != 0 && ns.ID() >= 0 {
		vs := asByteSlice(memmap.PtrOff(0x5D4594, 2512892), 1024)
		copy(vs, make([]byte, 1024))
		vs = vs[:3+len(data)]

		vs[0] = 31
		vs[1] = ns.Data2()[1]
		vs[2] = 32
		if len(data) > 0 {
			copy(vs[3:], data[:153])
		}
		C.nox_xxx_netSendSock_552640(C.uint(id), (*C.char)(unsafe.Pointer(&vs[0])), C.int(len(vs)), C.NOX_NET_SEND_NO_LOCK|C.NOX_NET_SEND_FLAG2)
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
	C.nox_netlist_xxx_40ED10(31, 0)
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
		C.nox_xxx_servNetInitialPackets_552A80(C.nox_xxx_netStructID_815700, 1)
		C.nox_xxx_netSendBySock_40EE10(C.nox_xxx_netStructID_815700, 31, 0)
		C.nox_netlist_xxx_40ED10(31, 0)
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
	C.dword_5d4594_811372 = 2
	if !noxflags.HasGame(noxflags.GameHost) {
		C.sub_417C60()
	}
	return nil
}

func CONNECT_RESULT_FAIL(result int) {
	if debugMainloop {
		log.Printf("CONNECT_RESULT_FAIL %d (%s)\n", result, caller(1))
		defer func() {
			log.Printf("CONNECT_RESULT_FAIL exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	noxflags.UnsetGame(noxflags.GameFlag21)
	mainloopConnectResultOK = false
	if noxflags.HasGame(noxflags.GameHost) {
		nox_xxx_servEndSession_4D3200()
	}
	if noxflags.HasGame(noxflags.GameFlag2) {
		nox_xxx_cliSetupSession_437190()
	}
	C.nox_xxx_clear18hDD_416190()
	if getEngineFlag(NOX_ENGINE_FLAG_13) {
		C.sub_413E30()
	}
	C.sub_43D0A0(C.int(result))
	cmainLoop()
	return
}

func CONNECT_RESULT_OK() {
	if debugMainloop {
		log.Printf("CONNECT_RESULT_OK (%s)\n", caller(1))
		defer func() {
			log.Printf("CONNECT_RESULT_OK exit (%s -> %s)\n", caller(1), caller(2))
		}()
	}
	mainloopConnectResultOK = true
	if C.nox_xxx_replayStartReadingOrSaving_4D38D0() == 1 {
		if debugMainloop {
			log.Println("nox_xxx_replayStartReadingOrSaving_4D38D0 exit")
		}
		cmainLoop()
		return
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		nox_xxx_setGameState_43DDF0(nil)
	} else if !nox_xxx_servInitialMapLoad_4D17F0() {
		if debugMainloop {
			log.Println("nox_xxx_servInitialMapLoad_4D17F0 exit")
		}
		cmainLoop()
		return
	}
	if !noxflags.HasGame(noxflags.GameFlag2) {
		C.nox_game_SetCliDrawFunc(nil)
	} else {
		if !noxflags.HasGame(noxflags.GameFlag21) {
			w, h, d := nox_xxx_gameGetScreenBoundaries_getVideoMode()
			if w == 0 || h == 0 {
				nox_xxx_gameResizeScreen_setVideoMode(noxDefaultWidth, noxDefaultHeight, d)
			}
			if err := gameUpdateVideoMode(false); err != nil {
				if debugMainloop {
					log.Printf("gameUpdateVideoMode: %v (%s)", err, caller(0))
				}
				return
			}
		}
		if initGameSession435CC0() == 0 {
			if debugMainloop {
				log.Println("initGameSession435CC0 exit")
			}
			cmainLoop()
			return
		}
	}
	if getEngineFlag(NOX_ENGINE_FLAG_13) {
		C.sub_413E30()
	}
	if noxflags.HasGame(noxflags.GameServerXxx) && noxflags.HasGame(noxflags.GameHost) && C.sub_43AF40() != 0 {
		C.sub_43AA70()
	}
	C.sub_43F1A0()
	C.nox_video_setGammaSetting_434B30(C.int(memmap.Int32(0x587000, 80852)))
	C.sub_434B60()
	noxflags.SetGame(noxflags.GameFlag29)
	mainloopExitPath = true
	mainloop_43E290()
}

func mainloopKeysUpdate() {
	v0 := (*C.uchar)(unsafe.Pointer(C.nox_xxx_wndKeyGet_430940()))
	for C.dword_5d4594_2618912 = C.uint(uintptr(unsafe.Pointer(v0))); *v0 != 0; C.dword_5d4594_2618912 = C.uint(uintptr(unsafe.Pointer(v0))) {
		C.nox_xxx_windowUpdateKeysMB_46B6B0(v0)
		v0 = (*C.uchar)(unsafe.Pointer(uintptr(C.dword_5d4594_2618912) + 8))
	}
}

func mainloopMaybeSwitchMapXXX() {
	if C.nox_client_gui_flag_815132 != 0 {
		return
	}
	if !noxflags.HasGame(noxflags.GameServerXxx) {
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
		log.Println("gameStateFunc = nox_xxx_gameStateWait_43C020", nox_xxx_gameStateWait_43C020)
	}
	nox_xxx_setGameState_43DDF0(nox_xxx_gameStateWait_43C020)
	C.nox_game_SetCliDrawFunc(nil)
	if memmap.Uint32(0x587000, 91840) != 0 {
		*memmap.PtrUint32(0x587000, 91840) = 0
		C.nox_client_gui_flag_815132 = 1
		return true
	}
	if C.nox_game_switchStates_43C0A0() == 0 {
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
	C.nox_xxx_drawSelectColor_434350(C.int(memmap.Uint32(0x5D4594, 2650656)))
	C.sub_440900()
	return false
}

func nox_xxx_cliSetupSession_437190() {
	if C.nox_xxx_check_flag_aaa_43AF70() == 1 {
		C.sub_40D380()
	}
	C.sub_473960()
	C.nox_xxx_cliResetAllPlayers_416E30()
	C.sub_455EE0()
	C.sub_456240()
	C.sub_48D800()
	C.sub_49A8C0()
	C.sub_470550()
	C.sub_46C5D0()
	C.sub_44DF70()
	if !noxflags.HasGame(noxflags.GameHost) {
		C.sub_43CC80()
	}
	C.dword_5d4594_811372 = 0
	if !noxflags.HasGame(noxflags.GameHost) {
		C.sub_4E4DE0()
	}
	nox_xxx_mapLoad_40A380()
	clientSetServerHost("")
	C.sub_446580(1)
	C.sub_48D760()
	if !noxflags.HasGame(noxflags.GameHost) {
		C.nox_netlist_xxx_40EE60()
	}
	C.sub_417CF0()
	*memmap.PtrUint32(0x5D4594, 2616328) = 0
	*memmap.PtrUint32(0x5D4594, 2614252) = 0
	*memmap.PtrUint32(0x5D4594, 2618908) = 0
}

func nox_xxx_mapLoad_40A380() {
	C.nox_xxx_set3512_40A340(0)
	nox_xxx_setMapCRC_40A360(0)
	nox_xxx_gameSetMapPath_409D70(C.GoString((*C.char)(memmap.PtrOff(0x5D4594, 3608))))
	noxflags.SetGame(noxflags.GameHost | noxflags.GameFlag2)
	noxflags.UnsetGame(137212) // TODO
	C.nox_server_gameSettingsUpdated = 1
}

func nox_xxx_gameSetMapPath_409D70(path string) {
	log.Println("set map path:", path)
	C.nox_xxx_gameSetMapPath_409D70(internCStr(path))
}

func nox_xxx_servEndSession_4D3200() {
	C.sub_50D1E0()
	C.sub_4DB100()
	C.sub_421B10()
	C.sub_516F10()
	C.sub_4FF770()
	C.nox_xxx_replayStopSave_4D33B0()
	C.nox_xxx_replayStopReadMB_4D3530()
	C.nox_xxx_cliResetAllPlayers_416E30()
	C.sub_446490(1)
	C.sub_4259F0()
	C.nox_xxx_mapSwitchLevel_4D12E0(0)
	nox_xxx_mapLoad_40A380()
	C.sub_4E4DE0()
	C.sub_57C460()
	C.sub_57C030()
	C.sub_511310()
	C.nox_xxx_freeSpellRelated_4FCA80()
	C.sub_50ABF0()
	C.sub_517B30()
	C.sub_5018D0()
	C.sub_4ECA90()
	C.sub_506720()
	C.sub_50D820()
	C.nox_xxx_deleteShopInventories_50E300()
	C.sub_416950()
	C.sub_4E3420()
	C.nox_xxx_free_4E2A20()
	if !noxflags.HasGame(noxflags.GameSolo) {
		C.nox_xxx_netCloseHandler_4DEC60(C.uint(*memmap.PtrUint32(0x5D4594, 1548516)))
		if !noxflags.HasGame(noxflags.GameFlag26) {
			C.nox_xxx_networkLog_close_413D00()
		}
	}
	C.sub_56F3B0()
	C.nox_netlist_xxx_40EE60()
	_ = fs.Remove(fmt.Sprintf("%s\\Save\\_temp_.dat", getDataPath()))
}
