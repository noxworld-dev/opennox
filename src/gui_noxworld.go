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
	"fmt"
	"net"
	"unsafe"

	"nox/v1/common/alloc"
	"nox/v1/common/discover"
	"nox/v1/common/memmap"
)

var (
	lobbyBroadcastSock  *Socket
	lobbyBroadcastSockC nox_socket_t
	lobbySockFlag       int
	errLobbySockFlag    = errors.New("lobbySockFlag is false")
)

type LobbyServerInfo struct {
	Addr       string
	Port       int
	Name       string
	Map        string
	Status     byte
	Ticks      uint64 // TODO: replace with actual ping
	Players    byte
	MaxPlayers byte
	Flags      uint16
	Level      uint16
	Field_11_0 int16
	Field_11_2 int16
	Field_12   uint32
	Field_25_1 byte
	Field_25_2 byte
	Field_26_1 uint16
	Field_26_3 uint16
	Field_33_3 [20]byte
	Field_38_3 uint32
	Field_39_3 uint32
}

func (s *LobbyServerInfo) String() string {
	return fmt.Sprintf("{%s:%d, %q, %d/%d, F:%v, M:%q, L:%d}", s.Addr, s.Port, s.Name, s.Players, s.MaxPlayers, s.Flags, s.Map, s.Level)
}

type LobbyServerFunc func(info *LobbyServerInfo) int

var guiOnLobbyServer LobbyServerFunc

func clientSetOnLobbyServer(fnc LobbyServerFunc) {
	guiOnLobbyServer = fnc
}

func onLobbyServer(info *LobbyServerInfo) bool {
	if guiOnLobbyServer == nil {
		discover.Log.Printf("ignoring server response: %s:%d, %q", info.Addr, info.Port, info.Name)
		return false
	}
	return guiOnLobbyServer(info) != 0
}

func onLobbyServerPacket(addr string, port int, name string, packet []byte) bool {
	if guiOnLobbyServer == nil {
		discover.Log.Printf("ignoring server response: %s:%d, %q", addr, port, name)
		return false
	}
	mi := StrLenBytes(packet[10:])
	info := &LobbyServerInfo{
		Addr:       addr,
		Port:       port,
		Name:       name,
		Players:    packet[3],
		MaxPlayers: packet[4],
		Field_25_1: packet[5] | (packet[6] << 4),
		Field_38_3: binary.LittleEndian.Uint32(packet[7:]) & 0xffffff,
		Map:        string(packet[10 : 10+mi]),
		Field_25_2: packet[19],
		Status:     packet[20] | packet[21],
		Field_12:   binary.LittleEndian.Uint32(packet[24:]),
		Flags:      binary.LittleEndian.Uint16(packet[28:]),
		Field_39_3: binary.LittleEndian.Uint32(packet[32:]),
		Field_26_1: binary.LittleEndian.Uint16(packet[36:]),
		Field_26_3: binary.LittleEndian.Uint16(packet[38:]),
		Field_11_0: int16(binary.LittleEndian.Uint16(packet[40:])),
		Field_11_2: int16(binary.LittleEndian.Uint16(packet[42:])),
		Ticks:      uint64(binary.LittleEndian.Uint32(packet[44:])),
		Level:      binary.LittleEndian.Uint16(packet[68:]),
	}
	copy(info.Field_33_3[:], packet[48:48+20])
	return onLobbyServer(info)
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
		clientSetOnLobbyServer(clientOnLobbyServer)
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
	lobbyBroadcastSockC = newSocketHandle(sock)
	C.nox_game_SetCliDrawFunc((*[0]byte)(C.sub_554FF0))
	lobbySockFlag = 1
	return 0
}

//export sub_554D10
func sub_554D10() C.int {
	if lobbySockFlag != 0 {
		_ = lobbyBroadcastSock.Close()
		lobbyBroadcastSock = nil
		lobbyBroadcastSockC = 0
		lobbySockFlag = 0
		C.nox_game_SetCliDrawFunc(nil)
		clientSetOnLobbyServer(nil)
		nox_net_stop()
	}
	return 0
}

func sub_4A0410(addr string, port int) bool {
	cstr := CString(addr)
	defer StrFree(cstr)
	v := C.sub_4A0410(cstr, C.short(port))
	return v != 0
}

func clientOnLobbyServer(info *LobbyServerInfo) int {
	discover.Log.Printf("server response: %s", info)
	if C.nox_wol_server_result_cnt_815088 >= 2500 || C.dword_5d4594_815044 != 0 || C.dword_5d4594_815060 != 0 {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: don't need more results", info.Addr)
		return 0
	}
	if info.Addr == "" {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: invalid address", info.Addr)
		return 0
	}
	ticks := info.Ticks
	if exp := *memmap.PtrUint32(0x5D4594, 814964); uint32(ticks) != exp {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: invalid ts: 0x%x vs 0x%x", info.Addr, ticks, exp)
		return 0
	}
	if !sub_4A0410(info.Addr, info.Port) {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: duplicate?", info.Addr)
		return 0
	}
	curTicks := platformTicks()

	srv := (*C.nox_gui_server_ent_t)(alloc.Malloc(unsafe.Sizeof(C.nox_gui_server_ent_t{})))
	defer alloc.Free(unsafe.Pointer(srv))
	// see https://github.com/golang/go/issues/7560
	field := func(off uintptr) unsafe.Pointer {
		return unsafe.Pointer(uintptr(unsafe.Pointer(srv)) + off)
	}
	srv.field_11_0 = C.short(info.Field_11_0)
	srv.field_11_2 = C.short(info.Field_11_2)
	srv.field_12 = C.uint(info.Field_12)
	srv.ping = C.int(curTicks - ticks)
	srv.status = C.uchar(info.Status)
	srv.field_25_1 = C.uchar(info.Field_25_1)
	srv.field_25_2 = C.uchar(info.Field_25_2)
	srv.players = C.uchar(info.Players)
	srv.max_players = C.uchar(info.MaxPlayers)
	*(*uint16)(field(105)) = info.Field_26_1 // field_26_1
	*(*uint16)(field(107)) = info.Field_26_3 // field_26_3
	StrCopy(&srv.map_name[0], 9, info.Map)
	copy(asByteSlice(unsafe.Pointer(&srv.field_33_3[0]), 20), info.Field_33_3[:])
	*(*uint32)(field(155)) = info.Field_38_3 // field_38_3
	*(*uint32)(field(159)) = info.Field_39_3 // field_39_3
	*(*uint16)(field(163)) = info.Flags      // flags
	*(*uint16)(field(165)) = info.Level      // quest_level
	srv.field_42 = 0
	if *(*int32)(unsafe.Pointer(&C.dword_587000_87412)) == -1 || C.sub_437860(C.int(srv.field_11_0), C.int(srv.field_11_2)) == C.int(C.dword_587000_87412) {
		if C.nox_xxx_checkSomeFlagsOnJoin_4899C0(srv) != 0 {
			StrCopy(&srv.addr[0], 16, info.Addr)
			srv.field_9 = C.nox_wol_server_result_cnt_815088
			srv.field_7 = 0
			*(*uint16)(field(109)) = uint16(info.Port) // port
			StrCopy(&srv.server_name[0], 15, info.Name)
			*(*uint16)(field(163)) = info.Flags // flags
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
	discoverAndPingServers(port, ticks, data)
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
	sub_554D70(lobbyBroadcastSock, lobbyBroadcastSockC, 1)
	return 1
}

func sub_554D70(sock *Socket, csock nox_socket_t, a1 byte) (int, error) {
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
						port := inPort
						name := buf[72:]
						name = name[:StrLenBytes(name)]
						if onLobbyServerPacket(saddr, port, string(name), buf) {
							clientSetOnLobbyServer(nil)
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
