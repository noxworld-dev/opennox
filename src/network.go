package opennox

import (
	"context"
	"encoding/binary"
	"fmt"
	"image"
	"net/netip"
	"strings"
	"time"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/binenc"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/client"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/common/serial"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	lastCliHandlePackets uint64
	ticks815732          uint64
	dword_5d4594_815704  bool
	dword_5d4594_815708  bool

	noxUseMapFrame = 0
	noxServerHost  = "localhost"
)

func networkLogPrint(str string) {
	if !noxflags.HasGame(noxflags.GameFlag3) {
		return
	}
	netstr.Log.Println(str)
	noxConsole.Print(console.ColorGreen, str)
}

func networkLogPrintf(format string, args ...any) {
	networkLogPrint(fmt.Sprintf(format, args...))
}

func clientSetServerHost(host string) {
	netstr.Log.Printf("server host: %s", host)
	noxServerHost = host
}

func clientGetServerHost() string {
	return noxServerHost
}

func clientGetClientPort() int {
	return int(memmap.Uint32(0x5D4594, 3528))
}

func nox_xxx_setClientNetPort_40A410(a1 int) {
	*memmap.PtrUint32(0x5D4594, 3528) = uint32(a1)
}

func noxGetUseMapFrame() int {
	return noxUseMapFrame
}

func noxSetUseMapFrame(frame int) {
	if noxServer.NetStr.Debug {
		netstr.Log.Printf("use map frame: %d", frame)
	}
	noxUseMapFrame = frame
}

func noxOnCliPacketDebug(op noxnet.Op, buf []byte) {
	if noxServer.NetStr.Debug && len(buf) != 0 {
		netstr.Log.Printf("CLIENT: op=%d (%s) [%d:%d]\n%02x %x", int(op), op.String(), int(len(buf))-1, op.Len(), buf[0], buf[1:])
	}
}

func convSendToServerErr(n int, err error) int {
	if err == client.ErrLobbyNoSocket {
		return -17
	} else if err != nil {
		return -1
	}
	return n
}

func nox_client_createSockAndJoin_43B440() error {
	return nox_client_joinGame()
}

func nox_client_joinGame_438A90() int {
	if err := nox_client_joinGame(); err != nil {
		return convSendToServerErr(0, err)
	}
	return 1
}

func nox_client_joinGame() error {
	endianess := binary.LittleEndian
	buf, freeBuf := alloc.Make([]byte{}, 100)
	defer freeBuf()
	if s, ok := serial.Serial(); ok {
		copy(buf[56:], s)
	}
	wstr := memmap.PtrOff(0x85B3FC, 12204)
	if n := alloc.StrLen((*uint16)(wstr)); n != 0 {
		copy(buf[4:54], unsafe.Slice((*byte)(wstr), n*2))
	}
	buf[54] = byte(getPlayerClass())
	buf[55] = memmap.Uint8(0x85B3FC, 12256)
	endianess.PutUint32(buf[80:], uint32(NOX_CLIENT_VERS_CODE))
	endianess.PutUint32(buf[84:], uint32(legacy.Get_dword_5d4594_2660032()))

	copy(buf[88:98], alloc.GoString((*byte)(memmap.PtrOff(0x85B3FC, 10344))))
	buf[98] = byte(bool2int(!nox_xxx_checkHasSoloMaps()))

	legacy.Sub_43AF90(3)
	legacy.Set_qword_5d4594_814956(platformTicks() + 20000)

	addr := legacy.Nox_client_getServerAddr_43B300()
	port := legacy.ClientGetServerPort()
	netstr.Log.Printf("join server: %s:%d", addr.String(), port)
	_, err := sendJoinGame(netip.AddrPortFrom(addr, uint16(port)), buf)
	return err
}

func sendJoinGame(addr netip.AddrPort, data []byte) (int, error) {
	data[0] = 0
	data[1] = 0
	data[2] = 14 // 0x0E
	return sendToServer(addr, data)
}

func sendXXX_5550D0(addr netip.AddrPort, data []byte) (int, error) {
	data[0] = 0
	data[1] = 0
	data[2] = 17 // 0x11
	return sendToServer(addr, data)
}

func nox_xxx_netClientSendSocial(a1 int, emote byte, a4, a5 int) {
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_SOCIAL)
	buf[1] = emote
	nox_xxx_netClientSend2_4E53C0(a1, buf[:], a4, a5)
}

func nox_xxx_netClientSend2_4E53C0(a1 int, buf []byte, a4, a5 int) {
	p, free := alloc.CloneSlice(buf)
	defer free()
	legacy.Nox_xxx_netClientSend2_4E53C0(a1, unsafe.Pointer(&p[0]), len(buf), a4, a5)
}

func (c *Client) clientSendInput(pli ntype.PlayerInd) bool {
	nbuf := c.ctrl.netBuf
	if len(nbuf) == 0 {
		return true
	}
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_PLAYER_INPUT)
	buf[1] = byte(len(nbuf))
	if !c.srv.NetList.AddToMsgListCli(pli, netlist.Kind0, buf[:2]) {
		return false
	}
	if !c.srv.NetList.AddToMsgListCli(pli, netlist.Kind0, nbuf) {
		return false
	}
	return true
}

func (c *Client) clientSendInputMouse(pli ntype.PlayerInd, mp image.Point) bool {
	sp := legacy.Nox_xxx_spriteGetMB_476F80()
	if sp != nil {
		mp.Y = sp.Pos().Y
	}
	if mp == c.netPrevMouse {
		return true
	}
	c.netPrevMouse = mp

	buf, err := noxnet.AppendPacket(nil, &noxnet.MsgMouse{
		X: uint16(mp.X),
		Y: uint16(mp.Y),
	})
	if err != nil {
		panic(err)
	}
	return c.srv.NetList.AddToMsgListCli(pli, netlist.Kind0, buf)
}

func (s *Server) listen(ctx context.Context, port int) error {
	narg := &netstr.Options{
		Port:       port,
		Max:        s.getServerMaxPlayers(),
		BufferSize: 2048,
		OnReceive: func(conn netstr.Handle, buf []byte) int {
			// should pass the pointer unchanged, otherwise expect bugs!
			s.onPacketRaw(conn.Player(), buf)
			return 1
		},
		OnSend:  s.onSend,
		OnJoin:  nox_xxx_netBigSwitch_553210_op_14_check,
		Check17: nox_xxx_netBigSwitch_553210_op_17_check,
	}
	s.SetUpdateFunc2(s.checkPingLimits)
	s.NetStr.Reset()
	return s.Listen(ctx, narg)
}

func nox_xxx_servNetInitialPackets_552A80_discover(src, dst []byte) int {
	// received a lobby info request from the client
	if true {
		// send server info packet
		return legacy.Nox_server_makeServerInfoPacket_554040(src, dst)
	}
	return 0
}

func netSendGauntlet() {
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_GAUNTLET)
	buf[1] = 27
	nox_xxx_netClientSend2_4E53C0(server.HostPlayerIndex, buf[:2], 0, 0)
}

func (s *Server) nox_xxx_netSendBySock_40EE10(conn *netstr.Conn, ind ntype.PlayerInd, kind netlist.Kind) {
	s.NetList.HandlePacketsA(ind, kind, func(data []byte) {
		if len(data) == 0 {
			return
		}
		conn.Send(data, 0)
		conn.SendReadPacket(true)
	})
}

func sub_4168E0() unsafe.Pointer {
	return nox_common_list_getFirstSafe_425890(memmap.PtrOff(0x5D4594, 371364))
}

func sub_4168F0(a1 unsafe.Pointer) unsafe.Pointer {
	return nox_common_list_getNextSafe_4258A0(a1)
}

func sub_416900() unsafe.Pointer {
	return nox_common_list_getFirstSafe_425890(memmap.PtrOff(0x5D4594, 371500))
}

func sub_416910(a1 unsafe.Pointer) unsafe.Pointer {
	return nox_common_list_getNextSafe_4258A0(a1)
}

func nox_xxx_netBigSwitch_553210_op_17_check(out []byte, packet []byte) int {
	v33 := sub_416640()
	if alloc.GoString16B(packet[4:]) != alloc.GoString16B(v33[39:]) {
		out[2] = 19
		out[3] = 6
		return 4
	}
	if *(*int16)(unsafe.Pointer(&v33[105])) == -1 && *(*int16)(unsafe.Pointer(&v33[107])) == -1 {
		out[2] = 20
		return 3
	}
	return 0
}

func nox_xxx_netBigSwitch_553210_op_14_check(out []byte, packet []byte, a4a bool, add func(pid ntype.Player) bool) int {
	s := noxServer
	v43 := false
	v78 := sub_416640()
	nox_xxx_cliGamedataGet_416590(0)

	// TODO: This code is disabled because it causes issues with players reconnecting to the server.
	//       For some reason the player record gets stuck in the server's player list, so this check fails.
	if false {
		if true {
			serial := alloc.GoStringS(packet[56:])
			for it := s.Players.First(); it != nil; it = s.Players.Next(it) {
				if byte(it.Field2135) == packet[98] {
					if it.Serial() == serial {
						out[2] = 19
						out[3] = 12
						return 4
					}
				}
			}
		}
	}

	if vers := NoxVersion(binary.LittleEndian.Uint32(packet[80:])); vers != NOX_CLIENT_VERS_CODE {
		out[2] = 19
		out[3] = 13
		return 4
	}
	if legacy.Sub_40A740() != 0 {
		v46 := legacy.Nox_xxx_countObserverPlayers_425BF0()
		f21 := binary.LittleEndian.Uint32(packet[84:])
		if f21 == 0 {
			if byte(v46) >= v78[53] {
				out[2] = 19
				out[3] = 11
				return 4
			}
		} else if s.Teams.ByXxx(int(f21)) != nil {
			if v46 > 0 {
				v43 = true
			}
		} else {
			if byte(legacy.Sub_417DE0()) >= v78[52] {
				if byte(v46) >= v78[53] {
					out[2] = 19
					out[3] = 11
					return 4
				}
			} else if v46 > 0 {
				v43 = true
			}
		}
	}
	if a4a {
		if !v43 || *(*uint32)(unsafe.Pointer(&v78[54])) == 0 {
			out[2] = 19
			out[3] = 11
			return 4
		}
		var found *Player
		s.Players.EachReplaceable(func(it *server.Player) bool {
			pit := it
			if add(it) {
				found = pit
				return false
			}
			return true // continue
		})
		if found != nil {
			s.PlayerDisconnect(s.Players.ByInd(found.PlayerIndex()), 4)
			out[2] = 21
			return 3
		}
	}
	if v78[100]&0x10 != 0 {
		var found bool
		for it := sub_4168E0(); it != nil; it = sub_4168F0(it) {
			if strings.ToLower(alloc.GoString16((*uint16)(unsafe.Add(it, 12)))) == strings.ToLower(alloc.GoString16B(packet[4:])) {
				found = true
				break
			}
		}
		if !found {
			out[2] = 19
			out[3] = 4
			return 4
		}
	} else {
		for it := sub_416900(); it != nil; it = sub_416910(it) {
			if alloc.GoString((*byte)(unsafe.Add(it, 72))) == "0" {
				if strings.ToLower(alloc.GoString16((*uint16)(unsafe.Add(it, 12)))) == strings.ToLower(alloc.GoString16B(packet[4:])) {
					out[2] = 19
					out[3] = 5
					return 4
				}
			} else {
				if strings.ToLower(alloc.GoString((*byte)(unsafe.Add(it, 72)))) == strings.ToLower(alloc.GoStringS(packet[56:])) {
					out[2] = 19
					out[3] = 5
					return 4
				}
			}
		}
	}
	v52 := v78[100]
	if v52 != 0 && (1<<packet[54])&v52 != 0 {
		out[2] = 19
		out[3] = 7
		return 4
	}
	if v52&0x20 != 0 {
		out[2] = 15
		return 3
	}
	if *(*int16)(unsafe.Pointer(&v78[105])) == -1 && *(*int16)(unsafe.Pointer(&v78[107])) == -1 {
		out[2] = 20 // OK
		return 3
	}
	return 0
}

func sub_554240(pli ntype.PlayerInd) int {
	if pli != server.HostPlayerIndex {
		return noxServer.NetStr.GetTimingByInd1(pli)
	}
	return int(nox_ctrlevent_add_ticks_42E630())
}

func sub_43CC80() {
	noxClient.Conn.SendClose()
	legacy.Set_dword_5d4594_2649712(0)
}

func (s *Server) checkPingLimits() bool {
	v13 := sub_416640()
	min := int(*(*int16)(unsafe.Pointer(&v13[105])))
	max := int(*(*int16)(unsafe.Pointer(&v13[107])))
	var tmin, tmax time.Duration = -1, -1
	if min >= 0 {
		tmin = time.Millisecond * time.Duration(min)
	}
	if max >= 0 {
		tmax = time.Millisecond * time.Duration(max)
	}
	s.NetStr.ProcessStats(tmin, tmax)
	return true
}

func sub_43C790() uint32 {
	return memmap.Uint32(0x587000, 91876)
}

func sub_43C7A0(v uint32) {
	*memmap.PtrUint32(0x587000, 91876) = v
}

func getCurPlayer() *server.Player {
	return legacy.Get_dword_8531A0_2576()
}

func setCurPlayer(p *Player) {
	legacy.Set_dword_8531A0_2576(p)
}

func nox_xxx_netTestHighBit_578B70(v uint16) bool    { return (v>>15)&1 != 0 }
func nox_xxx_netClearHighBit_578B30(v uint16) uint16 { return v & 0x7FFF }

func nox_xxx_playerCantTalkMB_57A160(pl *server.Player) bool {
	if pl == nil {
		return false
	}
	if !noxflags.HasGame(noxflags.GameClient) {
		return false
	}
	return (pl.Field3680>>3)&0x1 != 0
}

func sub_43C6E0() int {
	return bool2int(!dword_5d4594_815704 && !dword_5d4594_815708)
}

func sub_43CF40() {
	ticks815732 = platformTicks()
	dword_5d4594_815708 = false
	legacy.Sub_4AB4D0(0)
}

func sub_43CF70() {
	if !dword_5d4594_815708 {
		legacy.Sub_4AB4D0(1)
		dword_5d4594_815708 = true
		if pl := getCurPlayer(); pl != nil {
			legacy.Nox_xxx_netNeedTimestampStatus_4174F0(pl, 64)
			var buf [1]byte
			buf[0] = byte(noxnet.MSG_NEED_TIMESTAMP)
			nox_xxx_netClientSend2_4E53C0(server.HostPlayerIndex, buf[:1], 0, 1)
		}
	}
}

func (s *Server) sendSettings(u *server.Object) {
	pl := u.ControllingPlayer()
	{
		buf, err := noxnet.AppendPacket(nil, &noxnet.MsgFullTimestamp{
			T: s.Frame(),
		})
		if err != nil {
			panic(err)
		}
		s.NetList.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf)
	}
	{
		buf, err := noxnet.AppendPacket(nil, &noxnet.MsgJoinData{
			NetCode: uint16(s.GetUnitNetCode(u)),
			Unk2:    uint32(pl.Field2068),
		})
		if err != nil {
			panic(err)
		}
		s.NetList.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf)
		legacy.Sub_4161E0()
	}

	v3 := nox_xxx_cliGamedataGet_416590(0)
	{
		var buf [20]byte
		buf[0] = byte(noxnet.MSG_GAME_SETTINGS)
		binary.LittleEndian.PutUint32(buf[1:], s.Frame())
		binary.LittleEndian.PutUint32(buf[5:], uint32(NOX_CLIENT_VERS_CODE))
		binary.LittleEndian.PutUint32(buf[9:], uint32(noxflags.GetGame()&0x7FFF0))
		binary.LittleEndian.PutUint32(buf[13:], uint32(legacy.Nox_xxx_getServerSubFlags_409E60()))
		buf[17] = byte(s.getServerMaxPlayers())
		buf[18] = byte(legacy.Nox_xxx_servGamedataGet_40A020(*(*int16)(unsafe.Pointer(&v3[52]))))
		buf[19] = byte(legacy.Sub_40A180(noxflags.GameFlag(*(*uint16)(unsafe.Pointer(&v3[52])))))
		s.NetList.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:20])
	}
	{
		var buf [49]byte
		buf[0] = byte(noxnet.MSG_GAME_SETTINGS_2)
		copy(buf[1:17], s.getServerName())
		buf[16] = 0
		copy(buf[17:45], v3[24:24+28])
		if legacy.Sub_40A220() != 0 && (s.GetFlag3592() || legacy.Sub_40A180(noxflags.GameFlag(*(*uint16)(unsafe.Pointer(&v3[26])))) != 0) {
			binary.LittleEndian.PutUint32(buf[45:], legacy.Sub_40A230())
		} else {
			binary.LittleEndian.PutUint32(buf[45:], 0)
		}
		s.NetList.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:49])
	}
	{
		var buf [129]byte
		nox_xxx_netNewPlayerMakePacket_4DDA90(buf[:], pl)
		s.NetList.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:129])
		s.Nox_xxx_netSendBySock_4DDDC0(pl.PlayerIndex())
	}
	{
		buf, err := noxnet.AppendPacket(nil, &noxnet.MsgUseMap{
			MapName: binenc.String{Value: s.nox_server_currentMapGetFilename_409B30()},
			CRC:     nox_xxx_mapCrcGetMB_409B00(),
			T:       s.Frame(),
		})
		if err != nil {
			panic(err)
		}
		s.NetStr.ByPlayer(pl).Send(buf, netstr.SendQueue|netstr.SendFlush)
		legacy.Sub_4DDE10(pl.Index(), pl)
	}
}

func (s *Server) nox_xxx_netUseMap_4DEE00(mname string, crc uint32) {
	pck, err := noxnet.AppendPacket(nil, &noxnet.MsgUseMap{
		MapName: binenc.String{Value: mname},
		CRC:     crc,
		T:       s.Frame(),
	})
	if err != nil {
		panic(err)
	}
	for pl := s.Players.First(); pl != nil; pl = s.Players.Next(pl) {
		u := pl.PlayerUnit
		if u == nil {
			continue
		}
		s.NetList.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, pck)
		legacy.Nox_xxx_netPlayerObjSend_518C30(u, u, 0, 0)
		if !noxflags.HasGame(noxflags.GameClient) || pl.PlayerIndex() != server.HostPlayerIndex {
			buf := s.NetList.CopyPacketsA(pl.PlayerIndex(), netlist.Kind1)
			if len(buf) != 0 {
				s.NetStr.ByPlayer(pl).Send(buf, netstr.SendQueue|netstr.SendFlush)
			}
		}
	}
}

func Nox_xxx_netTimerStatus_4D8F50(a1 ntype.PlayerInd, a2 int) {
	s := noxServer
	var buf [13]byte
	buf[0] = byte(noxnet.MSG_TIMER_STATUS)
	binary.LittleEndian.PutUint32(buf[1:], uint32(a2))
	binary.LittleEndian.PutUint32(buf[5:], uint32(legacy.Sub_40A230()))
	binary.LittleEndian.PutUint32(buf[9:], s.Frame())
	s.NetSendPacketXxx1(int(a1), buf[:13], 0, 1)
}

func (s *Server) netSendAudioEvent(u *server.Object, ev *server.AudioEvent, perc int16) {
	pl := u.ControllingPlayer()
	packed := uint16(uint32(uint16(ev.Sound)) | uint32(perc)<<10)
	dx := ev.Pos.X - pl.Pos3632().X
	mv := uint8(int8(50 * int(dx) / (videoGetWindowSize().X / 2)))
	var buf [4]byte
	if u == ev.Obj {
		buf[0] = byte(noxnet.MSG_AUDIO_PLAYER_EVENT)
	} else {
		buf[0] = byte(noxnet.MSG_AUDIO_EVENT)
	}
	buf[1] = mv
	binary.LittleEndian.PutUint16(buf[2:], packed)
	s.NetList.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:4])
}

func (s *Server) nox_xxx_netPlayerObjSendCamera_519330(u *server.Object) bool {
	ud := u.UpdateDataPlayer()
	pl := ud.Player
	var buf [12]byte
	buf[0] = byte(noxnet.MSG_PLAYER_OBJ)
	binary.LittleEndian.PutUint16(buf[1:], 0)
	binary.LittleEndian.PutUint16(buf[3:], 0)
	pos := pl.Pos3632()
	binary.LittleEndian.PutUint16(buf[5:], uint16(pos.X))
	binary.LittleEndian.PutUint16(buf[7:], uint16(pos.Y))
	buf[9] = 0
	buf[10] = 0xff
	buf[11] = 0
	return nox_netlist_addToMsgListSrv(pl.PlayerIndex(), buf[:12])
}
