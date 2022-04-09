package opennox

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "win.h"
#include "MixPatch.h"
extern unsigned int dword_587000_87404;
extern int dword_587000_87412;
extern unsigned int dword_5d4594_3844304;
extern unsigned int dword_5d4594_2660652;
extern unsigned int dword_5d4594_527988;
extern unsigned int nox_client_connError_814552;
extern nox_window* dword_5d4594_815004;
extern unsigned int dword_5d4594_815044;
extern unsigned int dword_5d4594_815060;
extern nox_window* nox_wol_wnd_world_814980;
extern unsigned int nox_wol_server_result_cnt_815088;
extern int dword_5d4594_815104;
extern unsigned long long qword_5d4594_815068;
extern unsigned int nox_game_createOrJoin_815048;
extern uint32_t dword_587000_87408;
extern void* dword_5d4594_814984;
extern void* dword_5d4594_814988;
extern void* dword_5d4594_814996;
extern void* dword_5d4594_815000;
extern uint32_t dword_5d4594_815056;
*/
import "C"
import (
	"context"
	"encoding/binary"
	"errors"
	"fmt"
	"image"
	"net"
	"time"
	"unsafe"

	"github.com/noxworld-dev/lobby"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/discover"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	lobbyBroadcast struct {
		Conn  *net.UDPConn
		Sock  *Socket
		SockC nox_socket_t
	}
	errLobbyNoSocket = errors.New("no broadcast socket")
	discoverDone     = make(chan []discover.Server, 1)
)

type nox_gui_server_ent_t C.nox_gui_server_ent_t

func (s *nox_gui_server_ent_t) C() *C.nox_gui_server_ent_t {
	return (*C.nox_gui_server_ent_t)(unsafe.Pointer(s))
}

func (s *nox_gui_server_ent_t) field(off uintptr) unsafe.Pointer {
	// see https://github.com/golang/go/issues/7560
	return unsafe.Add(unsafe.Pointer(s), off)
}

func (s *nox_gui_server_ent_t) Players() int {
	if s == nil {
		return 0
	}
	return int(s.players)
}

func (s *nox_gui_server_ent_t) MaxPlayers() int {
	if s == nil {
		return 0
	}
	return int(s.max_players)
}

func (s *nox_gui_server_ent_t) Ping() int {
	if s == nil {
		return 0
	}
	return int(s.ping)
}

func (s *nox_gui_server_ent_t) Version() uint32 {
	if s == nil {
		return 0
	}
	return uint32(s.version)
}

func (s *nox_gui_server_ent_t) SetVersion(v uint32) {
	s.version = C.uint(v)
}

func (s *nox_gui_server_ent_t) Status() int {
	if s == nil {
		return 0
	}
	return int(s.status)
}

func (s *nox_gui_server_ent_t) QuestLevel() int {
	if s == nil {
		return 0
	}
	return int(*(*uint16)(s.field(165))) // quest_level
}

func (s *nox_gui_server_ent_t) SetQuestLevel(v uint16) {
	*(*uint16)(s.field(165)) = v // quest_level
}

func (s *nox_gui_server_ent_t) Addr() string {
	if s == nil {
		return ""
	}
	return GoString(&s.addr[0])
}

func (s *nox_gui_server_ent_t) SetAddr(v string) {
	StrCopy(&s.addr[0], 16, v)
}

func (s *nox_gui_server_ent_t) Port() int {
	if s == nil {
		return 0
	}
	return int(*(*uint16)(s.field(109))) // port
}

func (s *nox_gui_server_ent_t) SetPort(v uint16) {
	*(*uint16)(s.field(109)) = v // port
}

func (s *nox_gui_server_ent_t) ServerName() string {
	if s == nil {
		return ""
	}
	return GoString(&s.server_name[0])
}

func (s *nox_gui_server_ent_t) SetServerName(v string) {
	StrNCopy(&s.server_name[0], 15, v)
}

func (s *nox_gui_server_ent_t) MapName() string {
	if s == nil {
		return ""
	}
	return GoString(&s.map_name[0])
}

func (s *nox_gui_server_ent_t) SetMapName(v string) {
	StrCopy(&s.map_name[0], 9, v)
}

func (s *nox_gui_server_ent_t) Flags() noxflags.GameFlag {
	if s == nil {
		return 0
	}
	return noxflags.GameFlag(*(*uint16)(s.field(163))) // flags
}

func (s *nox_gui_server_ent_t) SetFlags(v noxflags.GameFlag) {
	*(*uint16)(s.field(163)) = uint16(v) // flags
}

type LobbyServerInfo struct {
	discover.Server
	Status     byte
	Flags      uint16 // TODO: should be the same as GameFlags
	Level      uint16
	Field_11_0 int16
	Field_11_2 int16
	Version    uint32
	Field_25_1 byte
	Field_25_2 byte
	Field_26_1 uint16
	Field_26_3 uint16
	Field_33_3 [20]byte
	Field_38_3 uint32
	Field_39_3 uint32
}

func (s *LobbyServerInfo) String() string {
	addr := fmt.Sprintf("%s:%d", s.IP, s.Port)
	ping := ""
	if s.Ping > 0 {
		ping = fmt.Sprintf(" P:%s,", s.Ping)
	}
	return fmt.Sprintf("{%q, %q (%s), %d/%d,%s F:%v, M:%q, L:%d}", addr, s.Name, s.Source, s.Players.Cur, s.Players.Max, ping, s.Flags, s.Map, s.Level)
}

func onLobbyServerPacket(addr string, port int, name string, packet []byte) bool {
	discover.Log.Printf("ignoring server response: %s:%d, %q", addr, port, name)
	return false
	/*
		ticks := uint64(binary.LittleEndian.Uint32(packet[44:]))
		if exp := *memmap.PtrUint32(0x5D4594, 814964); uint32(ticks) != exp {
			discover.Log.Printf("onLobbyServerPacket: ignoring server %q: invalid ts: 0x%x vs 0x%x", addr, ticks, exp)
			return false
		}
		mi := StrLenBytes(packet[10:])
		info := &LobbyServerInfo{
			Addr:       addr,
			Port:       port,
			Name:       name,
			Players:    int(packet[3]),
			MaxPlayers: int(packet[4]),
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
			Ping:       time.Duration(platformTicks()-ticks) * time.Millisecond,
			Level:      binary.LittleEndian.Uint16(packet[68:]),
		}
		copy(info.Field_33_3[:], packet[48:48+20])
		return onLobbyServer(info)
	*/
}

//export nox_client_refreshServerList_4378B0
func nox_client_refreshServerList_4378B0() {
	if sub44A4A0() {
		C.dword_5d4594_815104 = 1
		return
	}

	*memmap.PtrUint64(0x5D4594, 815076) = platformTicks()
	C.dword_5d4594_815060 = 0
	C.sub_4379C0()
	asWindow(C.dword_5d4594_815004).Func94(asWindowEvent(0x400F, 0, 0))
	C.sub_49FFA0(1)
	C.nox_wol_server_result_cnt_815088 = 0
	if C.dword_587000_87404 != 0 {
		C.sub_41F370(1)
		v3 := sub_41E2F0()
		C.sub_41DA70(C.int(v3), 12)
	} else {
		ctx := context.Background()
		asWindow(C.nox_wol_wnd_world_814980).NewDialogID("Wolchat.c:PleaseWait", "C:\\NoxPost\\src\\client\\shell\\noxworld.c")
		C.dword_5d4594_3844304 = 0
		go discoverAndPingServers(ctx)
	}
	C.dword_5d4594_815104 = 0
	// next auto-refresh
	C.qword_5d4594_815068 = C.ulonglong(*memmap.PtrUint64(0x5D4594, 815076) + 120000)
}

//export sub_438770_waitList
func sub_438770_waitList() {
	if C.dword_5d4594_815060 != 0 || C.dword_587000_87404 != 0 {
		return
	}
	timer := time.NewTimer(10 * time.Millisecond)
	defer timer.Stop()
	var list []discover.Server
	select {
	case <-timer.C:
		return
	case list = <-discoverDone:
	}
	for _, g := range list {
		level := 0
		if g.Quest != nil {
			level = g.Quest.Stage
		}
		var status byte
		switch g.Access {
		case lobby.AccessClosed:
			status |= 0x10
		case lobby.AccessPassword:
			status |= 0x20
		}
		// TODO: should propagate this via lobby
		v := uint32(noxProtoVersionLegacy)
		if g.Res.HighRes || g.Res.Width > 1024 || g.Res.Height > 768 {
			v = noxProtoVersionHighRes
		}
		clientOnLobbyServer(&LobbyServerInfo{
			Server:  g,
			Flags:   gameModeToFlags(g.Mode),
			Status:  status,
			Level:   uint16(level),
			Version: v,
		})
	}
	sub_44A400()
	C.sub_4379C0()
	C.sub_4A0360()
	C.dword_5d4594_815060 = 1
}

//export nox_xxx_createSocketLocal_554B40
func nox_xxx_createSocketLocal_554B40(port uint16) int {
	if err := nox_xxx_createSocketLocal(int(port)); err != nil {
		return -1
	}
	return 0
}

func nox_xxx_createSocketLocal(port int) error {
	if lobbyBroadcast.Conn != nil {
		return nil
	}
	nox_net_init()
	conn, sock, err := listenUDPBroadcast(nil, port)
	if err != nil {
		netLog.Println("cannot bind broadcast socket:", err)
		return err
	}
	lobbyBroadcast.Conn = conn
	lobbyBroadcast.Sock = sock
	lobbyBroadcast.SockC = newSocketHandle(sock)
	gameSetCliDrawFunc(sub_554FF0)
	return nil
}

//export sub_554D10
func sub_554D10() C.int {
	if lobbyBroadcast.Conn != nil {
		_ = lobbyBroadcast.Conn.Close()
		lobbyBroadcast.Conn = nil
		lobbyBroadcast.Sock = nil
		lobbyBroadcast.SockC = 0
		gameSetCliDrawFunc(nil)
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
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: don't need more results", info.Address)
		return 0
	}
	if info.Address == "" {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: invalid address", info.Address)
		return 0
	}
	if !sub_4A0410(info.Address, info.Port) {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: duplicate?", info.Address)
		return 0
	}
	srv, freeSrv := alloc.New(nox_gui_server_ent_t{})
	defer freeSrv()
	srv.field_11_0 = C.short(info.Field_11_0)
	srv.field_11_2 = C.short(info.Field_11_2)
	srv.SetVersion(info.Version)
	if info.Ping <= 0 {
		srv.ping = 9999 // UI interprets it as N/A
	} else {
		srv.ping = C.int(info.Ping / time.Millisecond)
	}
	srv.status = C.uchar(info.Status)
	srv.field_25_1 = C.uchar(info.Field_25_1)
	srv.field_25_2 = C.uchar(info.Field_25_2)
	if info.Players.Cur < 0 || info.Players.Cur > 0xff {
		srv.players = 255
	} else {
		srv.players = C.uchar(info.Players.Cur)
	}
	if info.Players.Max < 0 || info.Players.Cur > 0xff {
		srv.max_players = 255
	} else {
		srv.max_players = C.uchar(info.Players.Max)
	}
	*(*uint16)(srv.field(105)) = info.Field_26_1 // field_26_1
	*(*uint16)(srv.field(107)) = info.Field_26_3 // field_26_3
	srv.SetMapName(info.Map)
	copy(unsafe.Slice((*byte)(unsafe.Pointer(&srv.field_33_3[0])), 20), info.Field_33_3[:])
	*(*uint32)(srv.field(155)) = info.Field_38_3 // field_38_3
	*(*uint32)(srv.field(159)) = info.Field_39_3 // field_39_3
	srv.SetFlags(noxflags.GameFlag(info.Flags))
	srv.SetQuestLevel(info.Level)
	srv.field_42 = 0
	if C.dword_587000_87412 == -1 || C.sub_437860(C.int(srv.field_11_0), C.int(srv.field_11_2)) == C.dword_587000_87412 {
		if C.nox_xxx_checkSomeFlagsOnJoin_4899C0(srv.C()) != 0 {
			srv.SetAddr(info.Address)
			srv.field_9 = C.nox_wol_server_result_cnt_815088
			srv.field_7 = 0
			srv.SetPort(uint16(info.Port))
			srv.SetServerName(info.Name)
			srv.SetFlags(noxflags.GameFlag(info.Flags))
			C.nox_wol_servers_addResult_4A0030(srv.C())
			C.nox_wol_server_result_cnt_815088++
		}
	}
	return 0
}

func sub_554FF0() bool {
	sub_554D70(lobbyBroadcast.Conn, lobbyBroadcast.Sock, lobbyBroadcast.SockC, 1)
	return true
}

func sub_554D70(conn net.PacketConn, sock *Socket, csock nox_socket_t, a1 byte) (int, error) {
	if conn == nil {
		return 0, errLobbyNoSocket
	}
	v11 := int(a1 & 1)
	argp := 0
	if a1&1 != 0 {
		var err error
		argp, _, err = netCanReadConn(conn)
		if err != nil {
			return 0, err
		} else if argp == 0 {
			// TODO: is it an error at all?
			return 0, errors.New("nothing to read")
		}
	} else {
		argp = 1
	}
	buf, freeBuf := alloc.Make([]byte{}, 256)
	defer freeBuf()
	for {
		buf = buf[:cap(buf)]
		n, from, err := sock.ReadFrom(buf)
		if err != nil {
			return 0, err
		}
		buf = buf[:n]
		fromIP, fromPort := getAddr(from)
		if len(buf) > 2 && binary.LittleEndian.Uint16(buf) == 0xF13A { // extension packet code
			var cfrom C.struct_nox_net_sockaddr_in
			setAddr(&cfrom, from)
			n = int(C.MixRecvFromReplacer(csock, (*C.char)(unsafe.Pointer(&buf[0])), C.int(cap(buf)), (*C.struct_nox_net_sockaddr)(unsafe.Pointer(&cfrom))))
			if n < 0 {
				return 0, sock.err
			}
			buf = buf[:n]
		}
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
						onLobbyServerPacket(saddr, port, string(name), buf)
					}
				case 15:
					if C.sub_43B6D0() != 0 {
						sub_43AF90(5)
					}
				case 16:
					if C.sub_43B6D0() != 0 {
						sub_43AF90(4)
						buf[2] = 18
						sendToServer(fromIP, fromPort, buf[:8])
					}
				case 19:
					errcode := ConnectError(buf[3])
					if errcode != ErrDupSerial {
						if C.sub_43B6D0() != 0 {
							nox_client_setConnError_43AFA0(errcode)
						}
						break
					}
					// TODO: Code above is disabled because it causes issues with players reconnecting to the server.
					//       For some reason the player record gets stuck in the server's player list, so this check fails.
					gameLog.Printf("connect error: %d (%s, ignored)", errcode, errcode.Name())
					fallthrough
				case 20:
					if C.sub_43B6D0() != 0 && C.sub_43AF80() == 3 {
						sub_43AF90(7)
					}
				case 21:
					if C.sub_43B6D0() != 0 {
						sub_43AF90(8)
					}
				}
			}
		}
		if v11 == 0 || (a1&4) != 0 {
			return n, nil
		}
		argp, _, err = netCanReadConn(conn)
		if err != nil {
			return n, err
		} else if argp == 0 {
			return n, nil
		}
	}
}

func sendToServer(addr net.IP, port int, data []byte) (int, error) {
	if lobbyBroadcast.Conn == nil {
		return 0, errLobbyNoSocket
	}
	if len(data) < 2 {
		return 0, nil
	}
	if lobbyBroadcast.Conn == nil {
		return 0, errors.New("no broadcast socket")
	}
	return lobbyBroadcast.Conn.WriteTo(data, &net.UDPAddr{IP: addr, Port: port})
}

//export sub_41D4C0
func sub_41D4C0() C.int {
	C.sub_41EB40()
	C.sub_41F4B0()
	gameSetCliDrawFunc(nil)
	C.sub_40D0F0()
	return 1
}

func sub_41E2F0() int { return int(C.dword_5d4594_527988) }

func sub_420100() int { return int(memmap.Uint32(0x587000, 60072) >> 8) }

type ConnectError int

func (e ConnectError) Name() string {
	switch e {
	case ErrLowPing:
		return "ErrLowPing"
	case ErrHighPing:
		return "ErrHighPing"
	case ErrLowLevel:
		return "ErrLowLevel"
	case ErrHighLevel:
		return "ErrHighLevel"
	case ErrClosed:
		return "ErrClosed"
	case ErrBanned:
		return "ErrBanned"
	case ErrWrongPassword:
		return "ErrWrongPassword"
	case ErrIllegalClass:
		return "ErrIllegalClass"
	case ErrTimeOut:
		return "ErrTimeOut"
	case ErrFindFailed:
		return "ErrFindFailed"
	case ErrNeedRefresh:
		return "ErrNeedRefresh"
	case ErrFull:
		return "ErrFull"
	case ErrDupSerial:
		return "ErrDupSerial"
	case ErrWrongVer:
		return "ErrWrongVer"
	}
	return fmt.Sprintf("ConnectError(%d)", int(e))
}

const (
	ErrLowPing = ConnectError(iota)
	ErrHighPing
	ErrLowLevel
	ErrHighLevel
	ErrClosed
	ErrBanned
	ErrWrongPassword
	ErrIllegalClass
	ErrTimeOut
	ErrFindFailed
	ErrNeedRefresh
	ErrFull
	ErrDupSerial
	ErrWrongVer
)

func nox_client_setConnError_43AFA0(err ConnectError) {
	gameLog.Printf("connect error: %d (%s)", err, err.Name())
	C.nox_client_connError_814552 = C.uint(err)
	sub_43AF90(2)
}

//export sub_41E0D0
func sub_41E0D0() C.int {
	for v0 := memmap.Uint32(0x587000, 58264); v0 != 0; v0-- {
		v1 := sub_41E2F0()
		switch C.sub_41DCC0(C.int(v1)) {
		case 5:
			if C.dword_5d4594_2660652 == 0x8004006E {
				nox_client_setConnError_43AFA0(ErrFull)
			}
		case 10:
			C.sub_43ACC0()
		case 12:
			v2 := sub_420100()
			sub_41F3A0(v2, 1)
		case 19:
			nox_client_createSockAndJoin_43B440()
		}
		v0--
	}
	C.sub_40D250()
	return 1
}

func sub_41F3A0(a1, a2 int) bool {
	var v2, v4 string
	if sub_41E2F0() == 7 {
		v4 = strMan.GetStringInFile("wolchat.c:LoadingChannels", "C:\\NoxPost\\src\\common\\WolAPI\\wolchnl.c")
		v2 = strMan.GetStringInFile("wolchat.c:PleaseWait", "C:\\NoxPost\\src\\common\\WolAPI\\wolchnl.c")
	} else {
		v4 = strMan.GetStringInFile("noxworld.c:LoadingGames", "C:\\NoxPost\\src\\common\\WolAPI\\wolchnl.c")
		v2 = strMan.GetStringInFile("wolchat.c:PleaseWait", "C:\\NoxPost\\src\\common\\WolAPI\\wolchnl.c")
	}
	NewDialogWindow(nil, v2, v4, 288, nil, nil)
	sub_44A4B0()
	return C.sub_40D2F0(C.int(a1), C.int(a2)) != 0
}

//export sub_4373A0
func sub_4373A0() {
	if win := asWindowP(C.dword_5d4594_815000); !win.Flags().IsHidden() {
		win.Hide()
		C.dword_5d4594_815056 = 0
		nox_xxx_wnd46C6E0(win)
		guiFocus(asWindow(C.nox_wol_wnd_world_814980))
	}
	if C.dword_587000_87408 == 1 || C.dword_587000_87412 == -1 {
		if C.nox_game_createOrJoin_815048 == 1 {
			C.nox_game_createOrJoin_815048 = 0
			setMouseBounds(image.Rect(0, 0, nox_win_width-1, nox_win_height-1))
			v2 := strMan.GetStringInFile("ChooseArea", "C:\\NoxPost\\src\\client\\shell\\noxworld.c")
			asWindowP(C.dword_5d4594_814996).Func94(&WindowEvent0x4001{Str: v2})
			clientPlaySoundSpecial(231, 100)
		} else {
			nox_game_checkStateSwitch_43C1E0()
			C.sub_49FF20()
			if C.dword_587000_87404 == 1 {
				*memmap.PtrUint32(0x5D4594, 815084) = 1
				sub_41E300(7)
				C.sub_4207F0(4)
				C.sub_40D380()
			}
			clientPlaySoundSpecial(231, 100)
		}
	} else if C.nox_game_createOrJoin_815048 == 1 {
		C.nox_game_createOrJoin_815048 = 0
		setMouseBounds(image.Rect(0, 0, nox_win_width-1, nox_win_height-1))
		nox_xxx_wndClearCaptureMain(asWindowP(C.dword_5d4594_814984))
		C.sub_4375C0(1)
		v0 := strMan.GetStringInFile("JoinServer", "C:\\NoxPost\\src\\client\\shell\\noxworld.c")
		asWindowP(C.dword_5d4594_814996).Func94(&WindowEvent0x4001{Str: v0})
		clientPlaySoundSpecial(231, 100)
	} else {
		C.sub_49FF20()
		if C.dword_587000_87404 != 0 {
			C.dword_587000_87412 = -1
			nox_xxx_wndClearCaptureMain(asWindowP(C.dword_5d4594_814984))
			asWindowP(C.dword_5d4594_814984).Hide()
			asWindowP(C.dword_5d4594_814988).Show()
			v1 := strMan.GetStringInFile("ChooseArea", "C:\\NoxPost\\src\\client\\shell\\noxworld.c")
			asWindowP(C.dword_5d4594_814996).Func94(&WindowEvent0x4001{Str: v1})
			nox_client_refreshServerList_4378B0()
			clientPlaySoundSpecial(231, 100)
		} else {
			nox_game_checkStateSwitch_43C1E0()
		}
	}
}
