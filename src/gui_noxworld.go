package opennox

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "MixPatch.h"
extern int dword_587000_87412;
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
	"net/netip"
	"time"
	"unsafe"

	"github.com/noxworld-dev/lobby"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/discover"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
)

var (
	lobbyBroadcast   net.PacketConn
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
			GetFlags:      binary.LittleEndian.Uint16(packet[28:]),
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
	asWindow(C.dword_5d4594_815004).Func94(gui.AsWindowEvent(0x400F, 0, 0))
	C.sub_49FFA0(1)
	C.nox_wol_server_result_cnt_815088 = 0

	ctx := context.Background()
	winNewDialogID(asWindow(C.nox_wol_wnd_world_814980), "Wolchat.c:PleaseWait", "C:\\NoxPost\\src\\client\\shell\\noxworld.c")
	netstr.Flag1 = false
	go discoverAndPingServers(ctx)

	C.dword_5d4594_815104 = 0
	// next auto-refresh
	C.qword_5d4594_815068 = C.ulonglong(*memmap.PtrUint64(0x5D4594, 815076) + 120000)
}

//export sub_438770_waitList
func sub_438770_waitList() {
	if C.dword_5d4594_815060 != 0 {
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
		v := noxProtoVersionLegacy
		if g.Res.HighRes || g.Res.Width > 1024 || g.Res.Height > 768 {
			v = noxProtoVersionHighRes
		}
		clientOnLobbyServer(&LobbyServerInfo{
			Server:  g,
			Flags:   gameModeToFlags(g.Mode),
			Status:  status,
			Level:   uint16(level),
			Version: uint32(v),
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
	if lobbyBroadcast != nil {
		return nil
	}
	conn, err := netstr.Listen(netip.AddrPortFrom(netip.IPv4Unspecified(), uint16(port)))
	if err != nil {
		netstr.Log.Println("cannot bind broadcast socket:", err)
		return err
	}
	lobbyBroadcast = conn
	noxClient.SetDrawFunc(sub_554FF0)
	return nil
}

//export sub_554D10
func sub_554D10() C.int {
	if lobbyBroadcast != nil {
		_ = lobbyBroadcast.Close()
		lobbyBroadcast = nil
		noxClient.SetDrawFunc(nil)
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
	sub_554D70(lobbyBroadcast, 1)
	return true
}

func sub_554D70(conn net.PacketConn, a1 byte) (int, error) {
	if conn == nil {
		return 0, errLobbyNoSocket
	}
	v11 := int(a1 & 1)
	argp := 0
	if a1&1 != 0 {
		var err error
		argp, err = netstr.CanReadConn(conn)
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
		n, from, err := netstr.ReadFrom(conn, buf)
		if err != nil {
			return 0, err
		}
		buf = buf[:n]
		if len(buf) > 2 && binary.LittleEndian.Uint16(buf) == 0xF13A { // extension packet code
			MixRecvFromReplacer(conn, buf, from)
			continue
		}
		op := buf[2]
		if op < 32 {
			in := from
			if op == 13 || nox_client_getServerAddr_43B300() == from.Addr() {
				switch op {
				case 13:
					if in.Addr().IsValid() {
						saddr := in.Addr().String()
						port := int(in.Port())
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
						sendToServer(from, buf[:8])
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
		argp, err = netstr.CanReadConn(conn)
		if err != nil {
			return n, err
		} else if argp == 0 {
			return n, nil
		}
	}
}

func sendToServer(addr netip.AddrPort, data []byte) (int, error) {
	if lobbyBroadcast == nil {
		return 0, errLobbyNoSocket
	}
	if len(data) < 2 {
		return 0, nil
	}
	if lobbyBroadcast == nil {
		return 0, errors.New("no broadcast socket")
	}
	return lobbyBroadcast.WriteTo(data, net.UDPAddrFromAddrPort(addr))
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

//export sub_4373A0
func sub_4373A0() {
	if win := asWindowP(C.dword_5d4594_815000); !win.GetFlags().IsHidden() {
		win.Hide()
		C.dword_5d4594_815056 = 0
		gui.Nox_xxx_wnd46C6E0(win)
		gui.Focus(asWindow(C.nox_wol_wnd_world_814980))
	}
	if C.dword_587000_87408 == 1 || C.dword_587000_87412 == -1 {
		if C.nox_game_createOrJoin_815048 == 1 {
			C.nox_game_createOrJoin_815048 = 0
			noxClient.SetMouseBounds(image.Rect(0, 0, nox_win_width-1, nox_win_height-1))
			v2 := strMan.GetStringInFile("ChooseArea", "C:\\NoxPost\\src\\client\\shell\\noxworld.c")
			asWindowP(C.dword_5d4594_814996).Func94(&WindowEvent0x4001{Str: v2})
			clientPlaySoundSpecial(sound.SoundPermanentFizzle, 100)
		} else {
			nox_game_checkStateSwitch_43C1E0()
			C.sub_49FF20()
			clientPlaySoundSpecial(sound.SoundPermanentFizzle, 100)
		}
	} else if C.nox_game_createOrJoin_815048 == 1 {
		C.nox_game_createOrJoin_815048 = 0
		noxClient.SetMouseBounds(image.Rect(0, 0, nox_win_width-1, nox_win_height-1))
		gui.Nox_xxx_wndClearCaptureMain(asWindowP(C.dword_5d4594_814984))
		C.sub_4375C0(1)
		v0 := strMan.GetStringInFile("JoinServer", "C:\\NoxPost\\src\\client\\shell\\noxworld.c")
		asWindowP(C.dword_5d4594_814996).Func94(&WindowEvent0x4001{Str: v0})
		clientPlaySoundSpecial(sound.SoundPermanentFizzle, 100)
	} else {
		C.sub_49FF20()
		nox_game_checkStateSwitch_43C1E0()
	}
}
