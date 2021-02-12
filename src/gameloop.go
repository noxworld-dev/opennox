package main

/*
#include <fenv.h>

#include "proto.h"
#include "common__system__team.h"
#include "common__system__gamedisk.h"
#include "client__system__gameloop.h"

extern unsigned int nox_game_loop_xxx_805872;
extern unsigned int dword_5d4594_2660032;
extern unsigned int dword_5d4594_811372;
extern unsigned int dword_5d4594_815704;
extern unsigned int dword_5d4594_815708;
extern unsigned int dword_5d4594_3844304;
extern unsigned int dword_5d4594_2649712;
extern unsigned int dword_5d4594_815700;
extern unsigned int dword_5d4594_1556112;
extern unsigned int dword_5d4594_2618912;
extern unsigned int dword_5d4594_815132;
extern unsigned int nox_gameFPS;
extern unsigned int nox_xxx_gameDownloadInProgress_587000_173328;
extern int nox_win_width;
extern int nox_win_height;

int call_func_5D4594_816388();
int call_func_5D4594_816392();
int call_nox_draw_unk1();
*/
import "C"
import (
	"encoding/binary"
	"fmt"
	"math"
	"nox/common/alloc"
	"nox/common/memmap"
	"nox/common/platform"
	"path/filepath"
	"runtime"
	"strings"
	"time"
	"unsafe"
)

var (
	g_v20              bool
	g_v21              bool
	mainloopExitPath   bool
	mainloopEnter      func()
	mainloopContinue   = true // nox_continue_mainloop_93196
	continueMenuOrHost = true // nox_game_continueMenuOrHost_93200
	g_argc2            int
	g_argv2            **C.char
)

//export nox_xxx_setContinueMenuOrHost_43DDD0
func nox_xxx_setContinueMenuOrHost_43DDD0(v C.int) {
	continueMenuOrHost = v != 0
}

//export nox_server_mainloop_exiting_43DEA0
func nox_server_mainloop_exiting_43DEA0() C.bool {
	return C.bool(!mainloopContinue)
}

//export nox_game_exit_xxx_43DE60
func nox_game_exit_xxx_43DE60() {
	mainloopContinue = false
	C.nox_xxx_gameSetCliConnected_43C720(0)
	if C.sub_43AF70() != 1 {
		return
	}
	if !getGameFlag(0x2000000) {
		C.sub_40D380()
	}
}

func mainloop_43E290() {
	fmt.Printf("mainloop_43E290 (%s)\n", caller(1))
	mainloopContinue = true
	continueMenuOrHost = true
	*memmap.PtrUint32(0x5D4594, 816400) = 60 * uint32(C.nox_gameFPS)

	// XXX
	C.nox_xxx_gameStopDownload_4AB560(0)

	mainloopEnter = nil
mainloop:
	for mainloopContinue {
		if mainloopEnter != nil {
			fmt.Printf("mainloop continues (%s)\n", caller(1))
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
				goto MAINLOOP_EXIT
			}
		}
		if C.sub_43AF70() == 1 {
			C.sub_40D250()
			C.sub_40DF90()
		}
		nox_framerate_limit_416C70(30)
		inputPollEvents()
		C.sub_413520_gamedisk()
		C.nox_xxx_time_startProfile_435770()
		if C.call_func_5D4594_816388() == 0 {
			goto MAINLOOP_EXIT
		}
		C.nox_xxx_time_endProfile_435780()
		C.sub_435740()
		C.sub_430880(1)
		C.nox_client_processMouseInput_4308A0(1)
		C.nox_xxx_cursorUpdate_46B740()
		mainloopKeysUpdate()
		if C.call_nox_draw_unk1() == 0 {
			goto MAINLOOP_EXIT
		}
		C.sub_430880(0)
		if C.call_func_5D4594_816392() == 0 {
			goto MAINLOOP_EXIT
		}
		C.sub_4519C0()
		C.sub_4312C0()
		C.sub_495430()
		if getGameFlag(1) && continueMenuOrHost {
			mainloopMaybeSwitchMapXXX()
		}
		if C.dword_5d4594_815132 != 0 {
			C.sub_43C380()
			resetEngineFlag(NOX_ENGINE_FLAG_32)
			generateMouseSparks()
		}
		if !getEngineFlag(NOX_ENGINE_FLAG_32) {
			mainloopDrawAndPresent()
		}
		C.sub_435750()
		if memmap.Uint32(0x587000, 93192) != 0 {
			if getGameFlag(1) && getGameFlag(2) && !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) && getGameFlag(0x10000000) {
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
				*memmap.PtrUint32(0x5D4594, 2598000) = uint32(bool2int(getGameFlag(1)))
				C.nox_ensure_thing_bin()
				*memmap.PtrUint32(0x5D4594, 2650664) = 0
				*memmap.PtrUint32(0x5D4594, 2649708) = 0
				if g_v21 {
					fmt.Println("goto CONNECT_RESULT")
					mainloopEnter = func() {
						CONNECT_RESULT(0)
					}
					continue mainloop
				}
				if getGameFlag(1) {
					if C.nox_xxx_servNewSession_4D1660() == 0 {
						continue mainloop
					}
				}
				if C.nox_xxx_clientResetSpriteAndGui_4357D0(C.int(g_argc2), g_argv2) == 0 {
					continue mainloop
				}
				if getGameFlag(1) && getGameFlag(0x400000) && getEngineFlag(NOX_ENGINE_FLAG_1) {
					v23 := nox_common_get_data_path_409E10()
					C.sub_4D39F0(v23)
					if C.nox_xxx_mapGenStart_4D4320() == 0 {
						C.nox_xxx_mapSwitchLevel_4D12E0(0)
						continue mainloop
					}
					C.sub_4D3C30()
					unsetGameFlag(0x400000)
				}
				fmt.Println("goto CONNECT_PREPARE")
				mainloopEnter = CONNECT_PREPARE
				continue mainloop
			}
			C.nox_xxx_cliSetupSession_437190()
			C.nox_xxx_video_43BF10_upd_video_mode(1)
			C.nox_client_initScreenParticles_431390()
			cmainLoop()
			continue mainloop
		}
		unsetGameFlag(0x10000000)
		unsetGameFlag(0xD7F0)
		unsetGameFlag(0x900000)
		C.sub_43F140(300)
		C.sub_43D990()
		C.nox_xxx_replayWriteSomeInt_4D39B0()
		if getGameFlag(1) {
			C.nox_xxx_servResetPlayers_4D23C0()
		}
		if getGameFlag(2) {
			C.sub_435EB0()
		}
		if C.nox_xxx_video_43BF10_upd_video_mode(1) == 0 {
			continue mainloop
		}
		*memmap.PtrUint32(0x587000, 80852) = uint32(C.nox_video_getGammaSetting_434B00())
		C.nox_video_setGammaSetting_434B30(1)
		C.sub_434B60()
		g_v21 = false
		if getGameFlag(1) {
			C.nox_xxx_servEndSession_4D3200()
		}
		if getGameFlag(2) {
			C.nox_xxx_cliSetupSession_437190()
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
	fmt.Printf("cmainLoop (%s)\n", caller(1))
	C.sub_43F140(300)
	if C.sub_43C060() == 0 {
		return
	}
	if C.nox_xxx_cliWaitForJoinData_43BFE0() == 0 {
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

func CONNECT_PREPARE() {
	//char* v1;            // ebx
	//unsigned __int16 v3; // ax
	//int v4;              // [esp+Ch] [ebp-A8h]
	//int v5;              // [esp+10h] [ebp-A4h]
	//int v6;              // [esp+14h] [ebp-A0h]
	//BYTE Data[1024];     // [esp+18h] [ebp-9Ch]

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

	Data := alloc.Malloc(1024)
	defer alloc.Free(Data)
	Datas := asByteSlice(Data, 1024)

	C.sub_48D740()
	*(*uint32)(unsafe.Pointer(&Datas[97])) = uint32(v5)
	*(*uint32)(unsafe.Pointer(&Datas[101])) = uint32(v4)
	C.nox_xxx_regGetSerial_420120((*C.uchar)(unsafe.Pointer(&Datas[105])))
	if C.sub_43AF70() == 0 {
		C.nox_common_getInstallPath_40E0D0(C.int(uintptr(unsafe.Pointer(&Datas[105]))), (*C.char)(memmap.PtrOff(0x587000, 86344)), 0)
	}
	Datas[152] = byte(bool2int(C.nox_xxx_checkConjSoloMap_40ABD0() == 0))
	if memmap.Uint8(0x5D4594, 2660684)&4 != 0 {
		Datas[152] |= 0x80
	}
	s1 := C.GoString((*C.char)(memmap.PtrOff(0x5D4594, 2660012+87)))
	copy(Datas[142:], s1)
	s2 := C.GoString(C.sub_41FA40())
	copy(Datas[128:], s2)
	*(*uint32)(unsafe.Pointer(&Datas[138])) = uint32(C.dword_5d4594_2660032)
	copy(Datas, infos[:97])

	if getGameFlag(1) {
		C.nox_xxx_replay_4D3860(Data)
		*memmap.PtrPtr(0x5D4594, 2616328) = unsafe.Pointer(C.nox_xxx_playerNew_4DD320(31, (C.int)(uintptr(Data))))
		C.sub_409AE0(66458)
		C.nox_xxx_netlist_494E90(31)
		C.dword_5d4594_811372 = 2

		fmt.Println("goto CONNECT_RESULT")
		mainloopEnter = func() {
			CONNECT_RESULT(0)
		}
		return
	} else {
		v3 := uint32(C.sub_43B320())
		fmt.Println("goto CONNECT_SERVER")
		mainloopEnter = func() {
			CONNECT_SERVER((*C.char)(memmap.PtrOff(0x587000, 85680)), v3, Datas[:153])
		}
		return
	}
}

func CONNECT_SERVER(cp *C.char, hostshort uint32, data []byte) {
	v7 := alloc.Calloc(40, 1)
	v7s := asByteSlice(v7, 40)
	C.dword_5d4594_815704 = 0
	C.dword_5d4594_815708 = 0
	*(*uint32)(unsafe.Pointer(&v7s[20])) = 2048
	*(*uint32)(unsafe.Pointer(&v7s[8])) = hostshort
	C.nox_xxx_allocNetGQueue_5520B0(200, 1024)
	*(*uintptr)(unsafe.Pointer(&v7s[36])) = uintptr(unsafe.Pointer(C.nox_xxx_netHandleCliPacket_43C860)) // TODO
	v4 := C.nox_xxx_netPreStructToFull_5546F0((*C.uint)(v7))
	C.dword_5d4594_815700 = C.uint(v4)

	fmt.Println("goto NET_CONNECT")
	mainloopEnter = func() {
		NET_CONNECT(uint32(v4), cp, hostshort, data)
	}
	return
}

func NET_CONNECT(a1 uint32, cp *C.char, hostshort uint32, data []byte) {
	v5 := *(**int)(memmap.PtrOff(0x5D4594, 4*uintptr(a1)+3843788))
	v5s := asU32Slice(unsafe.Pointer(v5), 5)
	if uint(a1) >= 0x80 {
		fmt.Println("goto NET_CONNECT_THEN")
		mainloopEnter = func() {
			NET_CONNECT_THEN(-3)
		}
		return
	}
	if v5 == nil {
		fmt.Println("goto NET_CONNECT_THEN")
		mainloopEnter = func() {
			NET_CONNECT_THEN(-3)
		}
		return
	}
	if cp == nil {
		fmt.Println("goto NET_CONNECT_THEN")
		mainloopEnter = func() {
			NET_CONNECT_THEN(-4)
		}
		return
	}
	if hostshort < 1024 || hostshort > 0x10000 {
		fmt.Println("goto NET_CONNECT_THEN")
		mainloopEnter = func() {
			NET_CONNECT_THEN(-15)
		}
		return
	}
	var WSAData C.struct_WSAData
	if C.WSAStartup(0x101, &WSAData) == -1 {
		fmt.Println("goto NET_CONNECT_THEN")
		mainloopEnter = func() {
			NET_CONNECT_THEN(-21)
		}
		return
	}
	v7 := C.socket(C.AF_INET, C.SOCK_DGRAM, 0)
	*v5 = int(v7)
	if v7 == -1 {
		C.WSACleanup()

		fmt.Println("goto NET_CONNECT_THEN")
		mainloopEnter = func() {
			NET_CONNECT_THEN(-22)
		}
		return
	}
	var v8 uint32
	if byte(*cp) < '0' || byte(*cp) > '9' {
		v9 := C.gethostbyname(cp)
		if v9 == nil {
			C.WSACleanup()

			fmt.Println("goto NET_CONNECT_THEN")
			mainloopEnter = func() {
				NET_CONNECT_THEN(-4)
			}
			return
		}
		v8 = *(*uint32)(unsafe.Pointer(*v9.h_addr_list))
	} else {
		v8 = uint32(C.inet_addr(cp))
	}

	var v14 [4]byte
	binary.LittleEndian.PutUint16(v14[0:], 2)
	binary.LittleEndian.PutUint16(v14[2:], uint16(C.htons(C.ushort(hostshort))))

	v5s[1] = binary.LittleEndian.Uint32(v14[:])
	v5s[2] = v8
	v5s[3] = 0
	v5s[4] = 0

	port := C.sub_40A420()
	var name C.struct_sockaddr_in
	name.sin_family = C.AF_INET
	name.sin_port = C.htons(C.ushort(port))
	name.sin_addr.s_addr = 0
	for C.bind(C.int(v5s[0]), (*C.struct_sockaddr)(unsafe.Pointer(&name)), 16) == -1 {
		if C.WSAGetLastError() != 10048 {
			C.WSACleanup()

			fmt.Println("goto NET_CONNECT_THEN")
			mainloopEnter = func() {
				NET_CONNECT_THEN(-1)
			}
			return
		}
		port++
		name.sin_port = C.htons(C.ushort(port))
	}
	C.dword_5d4594_3844304 = 0
	v12 := 0
	v11 := C.nox_xxx_netSendSock_552640(C.uint(a1), unsafe.Pointer(&v12), 1, 3) // TODO: passing Go pointer

	fmt.Println("goto NET_CONNECT_WAIT_LOOP")
	mainloopEnter = func() {
		NET_CONNECT_WAIT_LOOP(a1, int8(v11), 60, 6, 0, data)
	}
	return
}

func NET_CONNECT_WAIT_LOOP(id uint32, val int8, retries, flags, counter uint32, data []byte) {
	v4 := memmap.Uint32(0x5D4594, 4*uintptr(id)+3843788)
	if id >= 0x80 {
		fmt.Println("goto NET_CONNECT_WAIT_THEN")
		mainloopEnter = func() {
			NET_CONNECT_WAIT_THEN(id, -3, data)
		}
		return
	}
	if v4 == 0 {
		fmt.Println("goto NET_CONNECT_WAIT_THEN")
		mainloopEnter = func() {
			NET_CONNECT_WAIT_THEN(id, -3, data)
		}
		return
	}
	counter = 0 // TODO: is this correct?
	counter++
	if 20*retries < counter {
		fmt.Println("goto NET_CONNECT_WAIT_THEN")
		mainloopEnter = func() {
			NET_CONNECT_WAIT_THEN(id, -23, data)
		}
		return
	}
	C.nox_xxx_servNetInitialPackets_552A80(C.uint(id), C.char(flags|1))
	C.sub_552460()
	if *(*int8)(unsafe.Pointer(uintptr(v4) + 113)) >= val {
		fmt.Println("goto NET_CONNECT_WAIT_THEN")
		mainloopEnter = func() {
			NET_CONNECT_WAIT_THEN(id, 0, data)
		}
		return
	}

	fmt.Println("goto NET_CONNECT_WAIT_LOOP")
	mainloopEnter = func() {
		NET_CONNECT_WAIT_LOOP(id, val, retries, flags, counter, data)
	}
	return
}

func NET_CONNECT_WAIT_THEN(id uint32, result int, data []byte) {
	data = data[:153]
	a5 := len(data)
	if result != 0 {
		fmt.Println("goto NET_CONNECT_THEN")
		mainloopEnter = func() {
			NET_CONNECT_THEN(-23)
		}
		return
	}

	v5 := *(**int)(memmap.PtrOff(0x5D4594, 4*uintptr(id)+3843788))
	v5s := asU32Slice(unsafe.Pointer(v5), 13)
	if C.dword_5d4594_3844304 != 0 && int(v5s[5]) >= 0 {
		vs := asByteSlice(memmap.PtrOff(0x5D4594, 2512892), 1024)
		copy(vs, make([]byte, 1024))
		vs[0] = 31
		vs[1] = *(*byte)(unsafe.Pointer(uintptr(v5s[12]) + 1))
		vs[2] = 32
		if len(data) > 0 {
			copy(vs[3:], data[:a5])
		}
		C.nox_xxx_netSendSock_552640(C.uint(id), memmap.PtrOff(0x5D4594, 2512892), C.int(a5+3), 3)
	}

	result = int(v5s[5])
	fmt.Println("goto NET_CONNECT_THEN")
	mainloopEnter = func() {
		NET_CONNECT_THEN(result)
	}
	return
}

func NET_CONNECT_THEN(v5 int) {
	if v5 < 0 {
		fmt.Println("goto CONNECT_RESULT")
		mainloopEnter = func() {
			CONNECT_RESULT(v5)
		}
		return
	}

	if !getGameFlag(1) {
		C.dword_5d4594_2649712 |= 0x80000000
	}
	C.sub_40ED10(31, 0)
	C.sub_40A340(0)
	C.nox_xxx_mapCrcMb_40A360(0)

	deadline := platformTicks() + 10000
	fmt.Println("goto CONNECT_WAIT_LOOP")
	mainloopEnter = func() {
		CONNECT_WAIT_LOOP(deadline)
	}
	return
}

func CONNECT_WAIT_LOOP(deadline uint64) {
	if platformTicks() >= deadline {
		fmt.Println("goto CONNECT_WAIT_THEN")
		mainloopEnter = func() {
			CONNECT_WAIT_THEN(0)
		}
		return
	}

	C.nox_xxx_servNetInitialPackets_552A80(C.dword_5d4594_815700, 1)
	C.nox_xxx_netSendBySock_40EE10(C.dword_5d4594_815700, 31, 0)
	C.sub_40ED10(31, 0)
	C.sub_552460()
	if C.nox_xxx_crc_40A370() != 0 {
		fmt.Println("goto CONNECT_WAIT_THEN")
		mainloopEnter = func() {
			CONNECT_WAIT_THEN(1)
		}
		return
	}
}

func CONNECT_WAIT_THEN(result int) {
	if result == 0 {
		fmt.Println("goto CONNECT_RESULT")
		mainloopEnter = func() {
			CONNECT_RESULT(-19)
		}
		return
	}
	if C.sub_409AD0() != 66458 {
		fmt.Println("goto CONNECT_RESULT")
		mainloopEnter = func() {
			CONNECT_RESULT(-20)
		}
		return
	}
	C.dword_5d4594_811372 = 2
	if !getGameFlag(1) {
		C.sub_417C60()
	}
	fmt.Println("goto CONNECT_RESULT")
	mainloopEnter = func() {
		CONNECT_RESULT(0)
	}
	return
}

func CONNECT_RESULT(result int) {
	if result != 0 {
		unsetGameFlag(0x100000)
		g_v21 = false
		if getGameFlag(1) {
			C.nox_xxx_servEndSession_4D3200()
		}
		if getGameFlag(2) {
			C.nox_xxx_cliSetupSession_437190()
		}
		C.nox_xxx_clear18hDD_416190()
		if getEngineFlag(NOX_ENGINE_FLAG_13) {
			C.sub_413E30()
		}
		C.sub_43D0A0(C.int(result))
		cmainLoop()
		return
	}
	g_v21 = true
	if C.nox_xxx_replayStartReadingOrSaving_4D38D0() == 1 {
		cmainLoop()
		return
	}
	if !getGameFlag(1) {
		C.nox_xxx_setGameState_43DDF0(nil)
	} else if C.nox_xxx_servInitialMapLoad_4D17F0() == 0 {
		cmainLoop()
		return
	}
	if !getGameFlag(2) {
		C.nox_game_SetCliDrawFunc(nil)
	} else {
		if !getGameFlag(0x100000) {
			w, h, d := nox_xxx_gameGetScreenBoundaries_getVideoMode()
			if w == 0 || h == 0 {
				nox_xxx_gameResizeScreen_setVideoMode(noxDefaultWidth, noxDefaultHeight, d)
			}
			if C.nox_xxx_video_43BF10_upd_video_mode(0) == 0 {
				return
			}
		}
		if C.nox_xxx_initGameSession_435CC0() == 0 {
			cmainLoop()
			return
		}
	}
	if getEngineFlag(NOX_ENGINE_FLAG_13) {
		C.sub_413E30()
	}
	if getGameFlag(0x2000) && getGameFlag(1) && C.sub_43AF40() != 0 {
		C.sub_43AA70()
	}
	C.sub_43F1A0()
	C.nox_video_setGammaSetting_434B30(C.int(memmap.Int32(0x587000, 80852)))
	C.sub_434B60()
	setGameFlag(0x10000000)
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
	if C.dword_5d4594_815132 != 0 {
		return
	}
	if !getGameFlag(0x2000) {
		return
	}
	if C.nox_server_gameDoSwitchMap_40A680() != 0 {
		C.nox_xxx_netGameSettings_4DEF00()
		C.nox_server_gameUnsetMapLoad_40A690()
	} else if C.sub_459D60() != 0 && !getGameFlag(9437184) {
		if C.sub_459DA0() != 0 {
			C.sub_4DF020()
		}
		C.sub_459D50(0)
	}
	if memmap.Int32(0x5D4594, 2598000) >= memmap.Int32(0x5D4594, 816400) {
		C.sub_4161E0()
		C.sub_416690()
		*memmap.PtrUint32(0x5D4594, 816400) = memmap.Uint32(0x5D4594, 2598000) + 60*uint32(C.nox_gameFPS)
	}
}

func mainloopDrawAndPresent() {
	C.sub_437180()
	if C.dword_5d4594_1556112 == 0 {
		C.mainloop_draw() // Draw game windows
	}
	mainloopDrawSparks()
	if !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) || getEngineFlag(NOX_ENGINE_FLAG_9) || C.dword_5d4594_815132 != 0 {
		C.nox_client_drawCursorAndTooltips_477830() // Draw cursor
	}
	C.sub_44D9F0(1)
	if C.sub_409F40(4096) == 0 { // CheckRuleFlags and smth
		C.nox_xxx_screenshot_46D830()
	}
	if !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) || getEngineFlag(NOX_ENGINE_FLAG_9) || C.dword_5d4594_815132 != 0 {
		C.nox_xxx_directDrawBlitMB_48A220()
		C.sub_4AD170_call_copy_backbuffer()
		C.sub_48A290_call_present()
	}
}

func mainloopDrawSparks() {
	if C.dword_5d4594_815132 != 0 {
		v28 := alloc.Calloc(10, 4)
		v28s := asU32Slice(v28, 10)
		v28s[0] = 0
		v28s[1] = 0
		v28s[2] = uint32(C.nox_win_width)
		v28s[3] = uint32(C.nox_win_height)
		v28s[8] = uint32(C.nox_win_width)
		v28s[9] = uint32(C.nox_win_height)
		C.nox_client_screenParticlesDraw_431720((*C.int)(v28))
		alloc.Free(v28)
	} else {
		v25 := C.sub_437250()
		C.nox_client_screenParticlesDraw_431720((*C.int)(unsafe.Pointer(v25)))
	}
}

func generateMouseSparks() {
	if memmap.Uint32(0x5D4594, 816408) != 0 {
		return
	}

	mouse := C.nox_client_getMouseState_4309F0()
	// emit sparks when passing a certain distance
	const distanceSparks = 0.25
	dx := int(mouse.pos.x) - int(memmap.Uint32(0x5D4594, 816420))
	dy := int(mouse.pos.y) - int(memmap.Uint32(0x5D4594, 816424))
	r2 := dx*dx + dy*dy
	if memmap.Uint32(0x5D4594, 816428) != 0 {
		cnt := (int)(math.Sqrt(float64(r2)) * distanceSparks)
		for i := cnt; i > 0; i-- {
			v6 := randomIntMinMax(0, 100)
			v7 := int(memmap.Uint32(0x5D4594, 816420)) + dx*v6/100
			v9 := int(memmap.Uint32(0x5D4594, 816424)) + dy*v6/100
			v23 := randomIntMinMax(2, 5)
			v22 := randomIntMinMax(2, 5)
			v21 := randomIntMinMax(-7, 2)
			v10 := randomIntMinMax(-5, 5)
			C.nox_client_newScreenParticle_431540(4, C.int(v7), C.int(v9), C.int(v10), C.int(v21), 1, C.char(v22), C.char(v23), 2, 1)
		}
		if r2 < 10 {
			*memmap.PtrUint32(0x5D4594, 816428) = 0
		}
		*memmap.PtrUint32(0x5D4594, 816420) = uint32(mouse.pos.x)
		*memmap.PtrUint32(0x5D4594, 816424) = uint32(mouse.pos.y)
	} else if r2 > 64 {
		*memmap.PtrUint32(0x5D4594, 816428) = 1
	}
	// explode with sparks when clicking
	const explosionSparks = 75
	if mouse.btn[C.NOX_MOUSE_LEFT].pressed == 1 {
		randomIntMinMax(0, 2)
		if memmap.Uint32(0x5D4594, 816416) == 0 {
			*memmap.PtrUint32(0x5D4594, 816416) = 1
			C.nox_xxx_clientPlaySoundSpecial_452D80(924, 100)
			for i := explosionSparks; i > 0; i-- {
				v12 := randomIntMinMax(0, 255)
				v13 := randomIntMinMax(6, 12)
				v14 := v13 * int(memmap.Int32(0x587000, 8*uintptr(v12)+192088))
				v15 := v13*int(memmap.Int32(0x587000, 8*uintptr(v12)+192092))/16 - 6
				v24 := randomIntMinMax(2, 5)
				v16 := randomIntMinMax(2, 5)
				C.nox_client_newScreenParticle_431540(4, C.int(v14/16+int(mouse.pos.x)), C.int(int(mouse.pos.y)+v15), C.int(v14/16), C.int(v15), 1, C.char(v16), C.char(v24), 2, 1)
			}
		}
	} else {
		*memmap.PtrUint32(0x5D4594, 816416) = 0
	}
}
