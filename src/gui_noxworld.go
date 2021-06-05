package main

/*
#include "proto.h"
extern unsigned int dword_587000_87404;
extern unsigned int dword_587000_87412;
extern unsigned int dword_5d4594_3844304;
extern nox_window* dword_5d4594_815004;
extern unsigned int dword_5d4594_815044;
extern unsigned int dword_5d4594_815060;
extern nox_window* nox_wol_wnd_world_814980;
extern unsigned int nox_wol_server_result_cnt_815088;
extern int dword_5d4594_815104;
extern unsigned long long qword_5d4594_815068;
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"net"
	"unsafe"

	"nox/v1/common/alloc"
	"nox/v1/common/discover"
	"nox/v1/common/memmap"
)

var (
	lobbyBroadcastSock *Socket
	lobbySockFlag      int
	errLobbySockFlag   = errors.New("lobbySockFlag is false")
)

type LobbyServerFunc func(addr string, port uint16, name string, packet []byte) int

var guiOnLobbyServer LobbyServerFunc

func nox_client_setOnLobbyServer_555000(fnc LobbyServerFunc) {
	guiOnLobbyServer = fnc
}

//export nox_client_refreshServerList_4378B0
func nox_client_refreshServerList_4378B0() {
	if C.sub_44A4A0() != 0 {
		C.dword_5d4594_815104 = 1
		return
	}

	*memmap.PtrUint64(0x5D4594, 815076) = platformTicks()
	C.dword_5d4594_815060 = 0
	C.sub_4379C0()
	asWindow(C.dword_5d4594_815004).Func94(16399, 0, 0)
	C.sub_49FFA0(1)
	C.nox_wol_server_result_cnt_815088 = 0
	if C.dword_587000_87404 != 0 {
		C.sub_41F370(1)
		v3 := C.sub_41E2F0()
		C.sub_41DA70(v3, 12)
	} else {
		nox_client_setOnLobbyServer_555000(nox_client_OnLobbyServer_4375F0)
		ticks := platformTicks()
		*memmap.PtrUint32(0x5D4594, 814964) = uint32(ticks)
		port := nox_xxx_servGetPort_40A430()
		nox_xxx_lobbyMakePacket_554AA0(port, nil, uint32(ticks))
		asWindow(C.nox_wol_wnd_world_814980).NewDialogID("Wolchat.c:PleaseWait", "C:\\NoxPost\\src\\client\\shell\\noxworld.c")
	}
	C.dword_5d4594_815104 = 0
	C.qword_5d4594_815068 = C.ulonglong(*memmap.PtrUint64(0x5D4594, 815076) + 120000)
}

//export nox_xxx_createSocketLocal_554B40
func nox_xxx_createSocketLocal_554B40(port uint16) int {
	if lobbySockFlag == 1 {
		return -14
	}
	if nox_net_init() == -1 {
		return -1
	}
	sock := newSocketUDPBroadcast()
	if err := sock.Bind(nil, int(port)); err != nil {
		netLog.Println("cannot bind broadcast socket:", err)
		return -1
	}
	lobbyBroadcastSock = sock
	C.nox_game_SetCliDrawFunc((*[0]byte)(C.sub_554FF0))
	lobbySockFlag = 1
	return 0
}

//export sub_554D10
func sub_554D10() C.int {
	if lobbySockFlag != 0 {
		_ = lobbyBroadcastSock.Close()
		lobbyBroadcastSock = nil
		lobbySockFlag = 0
		C.nox_game_SetCliDrawFunc(nil)
		nox_client_setOnLobbyServer_555000(nil)
		nox_net_stop()
	}
	return 0
}

func sub_4A0410(addr string, port uint16) bool {
	cstr := CString(addr)
	defer StrFree(cstr)
	v := C.sub_4A0410(cstr, C.short(port))
	return v != 0
}

func nox_client_OnLobbyServer_4375F0(addr string, port uint16, name string, packet []byte) int {
	if C.nox_wol_server_result_cnt_815088 >= 2500 || C.dword_5d4594_815044 != 0 || C.dword_5d4594_815060 != 0 {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: don't need more results", addr)
		return 0
	}
	if addr == "" {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: invalid address", addr)
		return 0
	}
	ticks := binary.LittleEndian.Uint32(packet[44:])
	if exp := *memmap.PtrUint32(0x5D4594, 814964); ticks != exp {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: invalid ts: 0x%x vs 0x%x\n", addr, ticks, exp)
		return 0
	}
	if !sub_4A0410(addr, port) {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: duplicate?", addr)
		return 0
	}
	curTicks := platformTicks()

	srv := (*C.nox_gui_server_ent_t)(alloc.Malloc(unsafe.Sizeof(C.nox_gui_server_ent_t{})))
	defer alloc.Free(unsafe.Pointer(srv))
	// see https://github.com/golang/go/issues/7560
	field := func(off uintptr) unsafe.Pointer {
		return unsafe.Pointer(uintptr(unsafe.Pointer(srv)) + off)
	}
	srv.field_11_0 = C.short(int16(binary.LittleEndian.Uint16(packet[40:])))
	srv.field_11_2 = C.short(int16(binary.LittleEndian.Uint16(packet[42:])))
	srv.field_12 = C.uint(binary.LittleEndian.Uint32(packet[24:]))
	srv.ping = C.int(curTicks - uint64(ticks))
	srv.status = C.uchar(packet[20] | packet[21])
	srv.field_25_1 = C.uchar(packet[5] | (packet[6] << 4))
	srv.field_25_2 = C.uchar(packet[19])
	srv.players = C.uchar(packet[3])
	srv.max_players = C.uchar(packet[4])
	*(*uint16)(field(105)) = binary.LittleEndian.Uint16(packet[36:]) // field_26_1
	*(*uint16)(field(107)) = binary.LittleEndian.Uint16(packet[38:]) // field_26_3
	i := StrLenBytes(packet[10:])
	StrCopy(&srv.map_name[0], 9, string(packet[10:10+i]))
	copy(asByteSlice(unsafe.Pointer(&srv.field_33_3[0]), 20), packet[48:48+20])
	*(*uint32)(field(155)) = binary.LittleEndian.Uint32(packet[7:])  // field_38_3
	*(*uint32)(field(159)) = binary.LittleEndian.Uint32(packet[32:]) // field_39_3
	*(*uint16)(field(163)) = binary.LittleEndian.Uint16(packet[28:]) // flags
	*(*uint16)(field(165)) = binary.LittleEndian.Uint16(packet[68:]) // quest_level
	srv.field_42 = 0
	if *(*int32)(unsafe.Pointer(&C.dword_587000_87412)) == -1 || C.sub_437860(C.int(srv.field_11_0), C.int(srv.field_11_2)) == C.int(C.dword_587000_87412) {
		if C.nox_xxx_checkSomeFlagsOnJoin_4899C0(srv) != 0 {
			StrCopy(&srv.addr[0], 16, addr)
			srv.field_9 = C.nox_wol_server_result_cnt_815088
			srv.field_7 = 0
			*(*uint16)(field(109)) = port // port
			StrCopy(&srv.server_name[0], 15, name)
			*(*uint16)(field(163)) = binary.LittleEndian.Uint16(packet[28:]) // flags
			C.nox_wol_servers_addResult_4A0030(srv)
			C.nox_wol_server_result_cnt_815088++
		}
	}
	return 0
}

func nox_xxx_lobbyMakePacket_554AA0(port int, payload []byte, ticks uint32) {
	data := make([]byte, 12+len(payload))
	data[0] = 0
	data[1] = 0
	data[2] = 12
	// data[3] = ???
	// data[4:5] = 0
	// data[6] = ???
	// data[7] = ???
	binary.LittleEndian.PutUint32(data[8:], uint32(ticks))
	if len(payload) > 0 {
		binary.LittleEndian.PutUint16(data[4:], uint16(len(payload)))
		copy(data[12:], payload)
	}
	C.dword_5d4594_3844304 = 0
	nox_xxx_sendLobbyPacket_554C80(port, data)
	discoverAndPingServers(port, data)
}

func nox_xxx_sendLobbyPacket_554C80(port int, buf []byte) (int, error) {
	if lobbySockFlag == 0 {
		return 0, errLobbySockFlag
	}
	if len(buf) < 2 {
		return 0, nil
	}
	ip := net.IPv4(255, 255, 255, 255)
	return lobbyBroadcastSock.WriteTo(buf, &net.UDPAddr{IP: ip, Port: port})
}

//export sub_554FF0
func sub_554FF0() C.int {
	sub_554D70(lobbyBroadcastSock, 1)
	return 1
}

func sub_554D70(sock *Socket, a1 byte) (int, error) {
	if lobbySockFlag == 0 {
		return 0, errLobbySockFlag
	}
	if sock == nil {
		return 0, errors.New("lobbyBroadcastSock is nil")
	}
	v11 := int(a1 & 1)
	argp := 0
	if a1&1 != 0 {
		var err error
		argp, err = sock.CanRead()
		if err != nil {
			return 0, err
		} else if argp == 0 {
			// TODO: is it an error at all?
			return 0, errors.New("nothing to read")
		}
	} else {
		argp = 1
	}
	buf := alloc.Bytes(256)
	// TODO: this is bad, because it creates a new handle all the time
	csock := newSocketHandle(lobbyBroadcastSock)
	for {
		buf = buf[:cap(buf)]
		var cfrom C.struct_nox_net_sockaddr_in
		n := int(C.mix_recvfrom(csock, (*C.char)(unsafe.Pointer(&buf[0])), C.int(cap(buf)), (*C.struct_nox_net_sockaddr)(unsafe.Pointer(&cfrom))))
		if n < 0 {
			return 0, sock.err
		}
		buf = buf[:n]
		fromIP, fromPort := toIPPort(&cfrom)
		op := buf[2]
		if op < 32 {
			inIP, inPort := fromIP, fromPort
			if op == 13 || fromIP.Equal(nox_client_getServerAddr_43B300()) {
				switch op {
				case 13:
					if inIP != nil {
						saddr := inIP.String()
						if guiOnLobbyServer != nil {
							port := inPort
							name := buf[72:]
							name = name[:StrLenBytes(name)]
							if onLobbyServer(saddr, port, string(name), buf) {
								nox_client_setOnLobbyServer_555000(nil)
							}
						}
					}
				case 15:
					if C.sub_43B6D0() != 0 {
						C.sub_43AF90(5)
					}
				case 16:
					if C.sub_43B6D0() != 0 {
						C.sub_43AF90(4)
						buf[2] = 18
						sendToServer(fromIP, fromPort, buf[:8])
					}
				//case 19:
				//  if sub_43B6D0() {
				//		sub_43AFA0(buf[3])
				//  }
				case 19, 20:
					if C.sub_43B6D0() != 0 && C.sub_43AF80() == 3 {
						C.sub_43AF90(7)
					}
				case 21:
					if C.sub_43B6D0() != 0 {
						C.sub_43AF90(8)
					}
				}
			}
		}
		if v11 == 0 || (a1&4) != 0 {
			return n, nil
		}
		var err error
		argp, err = sock.CanRead()
		if err != nil {
			return n, err
		} else if argp == 0 {
			return n, nil
		}
	}
}

func sendToServer(addr net.IP, port int, data []byte) (int, error) {
	if lobbySockFlag == 0 {
		return 0, errLobbySockFlag
	}
	if len(data) < 2 {
		return 0, nil
	}
	if lobbyBroadcastSock == nil {
		return 0, errors.New("no broadcast socket")
	}
	return lobbyBroadcastSock.WriteTo(data, &net.UDPAddr{IP: addr, Port: port})
}
