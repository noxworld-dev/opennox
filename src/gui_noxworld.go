package opennox

import (
	"context"
	"errors"
	"fmt"
	"image"
	"net"
	"net/netip"
	"time"
	"unsafe"

	"github.com/noxworld-dev/lobby"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/discover"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var (
	lobbyBroadcast      net.PacketConn
	discoverDone        = make(chan []discover.Server, 1)
	dword_5d4594_815060 int
)

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

func nox_client_refreshServerList_4378B0() {
	if sub44A4A0() {
		legacy.Set_dword_5d4594_815104(1)
		return
	}

	*memmap.PtrUint64(0x5D4594, 815076) = platformTicks()
	dword_5d4594_815060 = 0
	legacy.Sub_4379C0()
	legacy.Get_dword_5d4594_815004().Func94(gui.AsWindowEvent(0x400F, 0, 0))
	legacy.Sub_49FFA0(1)
	legacy.Set_nox_wol_server_result_cnt_815088(0)

	ctx := context.Background()
	winNewDialogID(legacy.Get_nox_wol_wnd_world_814980(), "Wolchat.c:PleaseWait", "C:\\NoxPost\\src\\client\\shell\\noxworld.c")
	netstr.Global.Responded = false
	go discoverAndPingServers(ctx)
	legacy.Set_dword_5d4594_815104(0)
	legacy.Set_qword_5d4594_815068(
		// next auto-refresh
		*memmap.PtrUint64(0x5D4594, 815076) + 120000)
}

func sub_438770_waitList() {
	if dword_5d4594_815060 != 0 {
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
	legacy.Sub_4379C0()
	legacy.Sub_4A0360()
	dword_5d4594_815060 = 1
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
	noxClient.SetDrawFunc(clientWaitForLobbyResults)
	return nil
}

func sub_554D10() int {
	if lobbyBroadcast != nil {
		_ = lobbyBroadcast.Close()
		lobbyBroadcast = nil
		noxClient.SetDrawFunc(nil)
	}
	return 0
}

func clientOnLobbyServer(info *LobbyServerInfo) int {
	discover.Log.Printf("server response: %s", info)
	if legacy.Get_nox_wol_server_result_cnt_815088() >= 2500 || legacy.Get_dword_5d4594_815044() != 0 || dword_5d4594_815060 != 0 {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: don't need more results", info.Address)
		return 0
	}
	if info.Address == "" {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: invalid address", info.Address)
		return 0
	}
	if !legacy.Sub_4A0410(info.Address, info.Port) {
		discover.Log.Printf("OnLobbyServer_4375F0: ignoring server %q: duplicate?", info.Address)
		return 0
	}
	srv, freeSrv := alloc.New(legacy.Nox_gui_server_ent_t{})
	defer freeSrv()
	srv.Field_11_0 = info.Field_11_0
	srv.Field_11_2 = info.Field_11_2
	srv.SetVersion(info.Version)
	if info.Ping <= 0 {
		srv.PingVal = 9999 // UI interprets it as N/A
	} else {
		srv.PingVal = int32(info.Ping / time.Millisecond)
	}
	srv.StatusVal = info.Status
	srv.Field_25_1 = info.Field_25_1
	srv.Field_25_2 = info.Field_25_2
	if info.Players.Cur < 0 || info.Players.Cur > 0xff {
		srv.PlayersVal = 255
	} else {
		srv.PlayersVal = byte(info.Players.Cur)
	}
	if info.Players.Max < 0 || info.Players.Cur > 0xff {
		srv.MaxPlayersVal = 255
	} else {
		srv.MaxPlayersVal = byte(info.Players.Max)
	}
	*(*uint16)(unsafe.Pointer(&srv.Field_26_1)) = info.Field_26_1
	*(*uint16)(unsafe.Pointer(&srv.Field_26_3)) = info.Field_26_3
	srv.SetMapName(info.Map)
	copy(srv.Field_33_3[:], info.Field_33_3[:])
	*(*uint32)(unsafe.Pointer(&srv.Field_38_3)) = info.Field_38_3
	*(*uint32)(unsafe.Pointer(&srv.Field_39_3)) = info.Field_39_3
	srv.SetFlags(noxflags.GameFlag(info.Flags))
	srv.SetQuestLevel(info.Level)
	srv.Field_42 = 0
	if legacy.Get_dword_587000_87412() == -1 || legacy.Sub_437860(int(srv.Field_11_0), int(srv.Field_11_2)) == legacy.Get_dword_587000_87412() {
		if legacy.Nox_xxx_checkSomeFlagsOnJoin_4899C0(srv) != 0 {
			srv.SetAddr(info.Address)
			srv.Field_9 = uint32(legacy.Get_nox_wol_server_result_cnt_815088())
			srv.Field_7 = 0
			srv.SetPort(uint16(info.Port))
			srv.SetServerName(info.Name)
			srv.SetFlags(noxflags.GameFlag(info.Flags))
			legacy.Nox_wol_servers_addResult_4A0030(srv)
			legacy.Inc_nox_wol_server_result_cnt_815088()
		}
	}
	return 0
}

func clientWaitForLobbyResults() bool {
	waitForLobbyResults(lobbyBroadcast, netstr.RecvCanRead)
	return true
}

func waitForLobbyResults(conn net.PacketConn, flag netstr.RecvFlags) (int, error) {
	if conn == nil {
		return 0, client.ErrLobbyNoSocket
	}
	return netstr.WaitForLobbyResults(conn, legacy.Nox_client_getServerAddr_43B300(), flag, netstr.LobbyWaitOptions{
		OnResult: func(addr netip.AddrPort, data []byte) {
			saddr := addr.Addr().String()
			port := int(addr.Port())
			name := data[72:]
			name = name[:alloc.StrLenS(name)]
			onLobbyServerPacket(saddr, port, string(name), data)
		},
		OnCode15: func() {
			if legacy.Sub_43B6D0() != 0 {
				legacy.Sub_43AF90(5)
			}
		},
		OnPing: func(addr netip.AddrPort, buf []byte) {
			if legacy.Sub_43B6D0() != 0 {
				legacy.Sub_43AF90(4)
				buf[2] = 18
				sendToServer(addr, buf[:8])
			}
		},
		OnCode19: func(code byte) bool {
			errcode := ConnectError(code)
			if errcode != ErrDupSerial {
				if legacy.Sub_43B6D0() != 0 {
					nox_client_setConnError_43AFA0(errcode)
				}
				return false
			}
			// TODO: Code above is disabled because it causes issues with players reconnecting to the server.
			//       For some reason the player record gets stuck in the server's player list, so this check fails.
			gameLog.Printf("connect error: %d (%s, ignored)", errcode, errcode.Name())
			// from code20
			if legacy.Sub_43B6D0() != 0 && legacy.Sub_43AF80() == 3 {
				legacy.Sub_43AF90(7)
			}
			return true
		},
		OnCode20: func() {
			if legacy.Sub_43B6D0() != 0 && legacy.Sub_43AF80() == 3 {
				legacy.Sub_43AF90(7)
			}
		},
		OnCode21: func() {
			if legacy.Sub_43B6D0() != 0 {
				legacy.Sub_43AF90(8)
			}
		},
	})
}

func sendToServer(addr netip.AddrPort, data []byte) (int, error) {
	if lobbyBroadcast == nil {
		return 0, client.ErrLobbyNoSocket
	}
	if len(data) < 2 {
		return 0, nil
	}
	if lobbyBroadcast == nil {
		return 0, errors.New("no broadcast socket")
	}
	return lobbyBroadcast.WriteTo(data, net.UDPAddrFromAddrPort(addr))
}

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
	legacy.Set_nox_client_connError_814552(int(err))
	legacy.Sub_43AF90(2)
}

func sub_4373A0() {
	c := noxClient
	if win := legacy.Get_dword_5d4594_815000(); !win.GetFlags().IsHidden() {
		win.Hide()
		legacy.Set_dword_5d4594_815056(0)
		win.StackPop()
		legacy.Get_nox_wol_wnd_world_814980().Focus()
	}
	if legacy.Get_dword_587000_87408() == 1 || legacy.Get_dword_587000_87412() == -1 {
		if legacy.Get_nox_game_createOrJoin_815048() == 1 {
			legacy.Set_nox_game_createOrJoin_815048(0)
			c.SetMouseBounds(image.Rect(0, 0, nox_win_width-1, nox_win_height-1))
			v2 := c.Strings().GetStringInFile("ChooseArea", "C:\\NoxPost\\src\\client\\shell\\noxworld.c")
			legacy.Get_dword_5d4594_814996().Func94(&gui.StaticTextSetText{Str: v2})
			clientPlaySoundSpecial(sound.SoundPermanentFizzle, 100)
		} else {
			c.nox_game_checkStateSwitch_43C1E0()
			legacy.Sub_49FF20()
			clientPlaySoundSpecial(sound.SoundPermanentFizzle, 100)
		}
	} else if legacy.Get_nox_game_createOrJoin_815048() == 1 {
		legacy.Set_nox_game_createOrJoin_815048(0)
		c.SetMouseBounds(image.Rect(0, 0, nox_win_width-1, nox_win_height-1))
		legacy.Get_dword_5d4594_814984().Capture(false)
		legacy.Sub_4375C0(1)
		v0 := c.Strings().GetStringInFile("JoinServer", "C:\\NoxPost\\src\\client\\shell\\noxworld.c")
		legacy.Get_dword_5d4594_814996().Func94(&gui.StaticTextSetText{Str: v0})
		clientPlaySoundSpecial(sound.SoundPermanentFizzle, 100)
	} else {
		legacy.Sub_49FF20()
		c.nox_game_checkStateSwitch_43C1E0()
	}
}
