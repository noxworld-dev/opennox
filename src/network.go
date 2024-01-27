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

	"github.com/noxworld-dev/nat"
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

func init() {
	configBoolPtr("network.xor", "NOX_NET_XOR", true, &netstr.Global.Xor)
	configHiddenBoolPtr("debug.network", "NOX_DEBUG_NET", &netstr.Global.Debug)
	netstr.Global.GameFrame = func() uint32 {
		return noxServer.Frame()
	}
	netstr.Global.OnDiscover = nox_xxx_servNetInitialPackets_552A80_discover
	netstr.Global.OnExtPacket = MixRecvFromReplacer
	netstr.Global.GetMaxPlayers = func() int {
		return noxServer.getServerMaxPlayers()
	}
	netstr.Global.KeyRand = func(min, max int) int {
		return noxServer.Rand.Logic.IntClamp(min, max)
	}
	netstr.Global.PacketDropRand = func(min, max int) int {
		return noxServer.Rand.Other.Int(min, max)
	}
}

var (
	netstrClientConn     netstr.Handle
	lastCliHandlePackets uint64
	ticks815732          uint64
	dword_5d4594_815704  bool
	dword_5d4594_815708  bool
	ownIPStr             string
	ownIP                netip.Addr
	xferDataArr          []xferData
	xferDataCnt          int
	xferDataActive       int
	dword_5d4594_3624    int
	dword_5d4594_3620    []xferDataTwo
	dword_5d4594_3628    int
)

var (
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

func netstrGetClientIndex() netstr.Handle { return netstrClientConn }

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
	if netstr.Global.Debug {
		netstr.Log.Printf("use map frame: %d", frame)
	}
	noxUseMapFrame = frame
}

func noxOnCliPacketDebug(op noxnet.Op, buf []byte) {
	if netstr.Global.Debug && len(buf) != 0 {
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

func (s *Server) initConn(port int) (conn netstr.Handle, cport int, _ error) {
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
	netstr.Global.Reset()
	conn, err := netInitServer(narg)
	if err != nil {
		return conn, 0, err
	}
	return conn, narg.Port, err
}

var netServerPort uint16

func getServerPort() uint16 {
	return netServerPort
}

func getOwnIP() string {
	return ownIPStr
}

func netInitServer(narg *netstr.Options) (ind netstr.Handle, _ error) {
	ownIPStr = ""
	conn, err := netstr.Global.Listen(narg)
	netServerPort = uint16(narg.Port)
	if err != nil {
		return conn, err
	}
	if ip, err := nat.ExternalIP(context.Background()); err == nil {
		ownIP, _ = netip.AddrFromSlice(ip.To4())
		ownIPStr = ip.String()
	} else if ips, err := nat.InternalIPs(context.Background()); err == nil && len(ips) != 0 {
		ip = ips[0].IP
		ownIP, _ = netip.AddrFromSlice(ip.To4())
		ownIPStr = ip.String()
	}
	return conn, nil
}

func (s *Server) nox_server_netClose_5546A0(i netstr.Handle) {
	i.Close()
}

func (s *Server) nox_xxx_netStructReadPackets2_4DEC50(ind ntype.PlayerInd) int {
	return netstr.Global.ReadPackets(netstr.Global.ByPlayerInd(ind))
}

func nox_xxx_netSendClientReady_43C9F0() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_CLIENT_READY)
	netstrClientConn.Send(data[:], netstr.SendQueue|netstr.SendFlush)
	return 1
}

func nox_xxx_netKeepAliveSocket_43CA20() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_KEEP_ALIVE)
	netstrClientConn.Send(data[:], netstr.SendFlush)
	return 1
}

func nox_xxx_netRequestMap_43CA50() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_REQUEST_MAP)
	netstrClientConn.Send(data[:], netstr.SendQueue|netstr.SendFlush)
	return 1
}

func nox_xxx_netMapReceived_43CA80() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_RECEIVED_MAP)
	netstrClientConn.Send(data[:], netstr.SendQueue|netstr.SendFlush)
	return 1
}

func nox_xxx_cliSendCancelMap_43CAB0() int {
	s := noxServer
	conn := netstrClientConn
	var data [1]byte
	data[0] = byte(noxnet.MSG_CANCEL_MAP)
	v0, _ := conn.Send(data[:], netstr.SendQueue|netstr.SendFlush)
	if conn.WaitServerResponse(v0, 20, netstr.RecvNoHooks|netstr.RecvJustOne) != 0 {
		return 0
	}
	s.NetList.ResetByInd(server.HostPlayerIndex, netlist.Kind0)
	return 1
}

func nox_xxx_netSendIncomingClient_43CB00() int {
	s := noxServer
	conn := netstrClientConn
	var data [1]byte
	data[0] = byte(noxnet.MSG_INCOMING_CLIENT)
	v0, _ := conn.Send(data[:], netstr.SendQueue|netstr.SendFlush)
	if conn.WaitServerResponse(v0, 20, netstr.RecvNoHooks|netstr.RecvJustOne) != 0 {
		return 0
	}
	s.NetList.ResetByInd(server.HostPlayerIndex, netlist.Kind0)
	return 1
}

func nox_xxx_servNetInitialPackets_552A80_discover(src, dst []byte) int {
	// received a lobby info request from the client
	if true {
		// send server info packet
		return legacy.Nox_server_makeServerInfoPacket_554040(src, dst)
	}
	return 0
}

func nox_xxx_cliSendOutgoingClient_43CB50() int {
	s := noxServer
	conn := netstrClientConn
	var data [1]byte
	data[0] = byte(noxnet.MSG_OUTGOING_CLIENT)
	v0, _ := conn.Send(data[:], netstr.SendQueue|netstr.SendFlush)
	if conn.WaitServerResponse(v0, 20, netstr.RecvNoHooks|netstr.RecvJustOne) != 0 {
		return 0
	}
	conn.RecvLoop(netstr.RecvCanRead | netstr.RecvNoHooks)
	s.NetList.ResetByInd(server.HostPlayerIndex, netlist.Kind0)
	return 1
}

func netSendGauntlet() {
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_GAUNTLET)
	buf[1] = 27
	nox_xxx_netClientSend2_4E53C0(server.HostPlayerIndex, buf[:2], 0, 0)
}

func (s *Server) nox_xxx_netSendBySock_40EE10(conn netstr.Handle, ind ntype.PlayerInd, kind netlist.Kind) {
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
		return netstr.Global.GetTimingByInd1(pli)
	}
	return int(nox_ctrlevent_add_ticks_42E630())
}

func sub_43CC80() {
	netstrClientConn.SendClose()
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
	netstr.Global.ProcessStats(tmin, tmax)
	return true
}

func nox_xxx_net_getIP_554200(a1 netstr.Handle) uint32 {
	return ip2int(netGetIP(a1))
}

func netGetIP(ind netstr.Handle) netip.Addr {
	if ind.IsFirst() {
		return ownIP
	}
	return ind.IP()
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

func (s *Server) nox_xxx_netSendBySock_4DDDC0(ind ntype.PlayerInd) {
	if !noxflags.HasGame(noxflags.GameClient) || ind != server.HostPlayerIndex {
		s.NetList.HandlePacketsA(ind, netlist.Kind1, func(data []byte) {
			if len(data) == 0 {
				return
			}
			netstr.Global.ByPlayerInd(ind).Send(data, netstr.SendQueue|netstr.SendFlush)
		})
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
		s.nox_xxx_netSendBySock_4DDDC0(pl.PlayerIndex())
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
		netstr.Global.ByPlayer(pl).Send(buf, netstr.SendQueue|netstr.SendFlush)
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
				netstr.Global.ByPlayer(pl).Send(buf, netstr.SendQueue|netstr.SendFlush)
			}
		}
	}
}

func Nox_xxx_netTimerStatus_4D8F50(a1 ntype.PlayerInd, a2 int) {
	var buf [13]byte
	buf[0] = byte(noxnet.MSG_TIMER_STATUS)
	binary.LittleEndian.PutUint32(buf[1:], uint32(a2))
	binary.LittleEndian.PutUint32(buf[5:], uint32(legacy.Sub_40A230()))
	binary.LittleEndian.PutUint32(buf[9:], noxServer.Frame())
	noxServer.NetSendPacketXxx1(int(a1), buf[:13], 0, 1)
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

func sub_40BA90(conn netstr.Handle, a2 byte, block uint16, data []byte) int {
	buf := make([]byte, 8+len(data))
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 2 // XFER_DATA
	buf[2] = a2
	buf[3] = 0
	binary.LittleEndian.PutUint16(buf[4:], block)
	binary.LittleEndian.PutUint16(buf[6:], uint16(len(data)))
	copy(buf[8:], data)
	conn.Send(buf, 0)
	return conn.SendReadPacket(true)
}

type xferData struct {
	NetInd0   netstr.Handle // 0, 0
	Stream4   byte          // 1, 4
	Kind6     uint16        // 1, 6
	Size8     int           // 2, 8
	Cnt12     uint32        // 3, 12
	Blocks16  int           // 4, 16
	BlockSz20 uint16        // 5, 20
	Field22   byte          // 5, 22
	Type23    string        // 5, 23
	First152  *xferBlock    // 38, 152
	Last156   *xferBlock    // 39, 156
}

type xferDataTwo struct {
	NetInd0  netstr.Handle // 0, 0
	Act4     byte          // 1, 4
	Stream5  byte          // 1, 5
	Cnt8     uint32        // 2, 8
	Cur12    int           // 3, 12
	Data20   []byte        // 5, 20
	Type24   string        // 6, 24
	Perc152  float32       // 38, 152
	Frame156 uint32        // 39, 156
	Field160 *xferBlock    // 40, 160
	Field164 *xferBlock    // 41, 164
}

type xferBlock struct {
	Ind0    uint16     // 0, 0
	Data4   []byte     // 1, 4
	Frame12 uint32     // 3, 12
	Cnt16   uint16     // 4, 16
	Next20  *xferBlock // 5, 20
	Prev24  *xferBlock // 6, 24
}

func sub_40B890(n int) {
	if n < 0 {
		xferDataCnt = 16
	} else {
		xferDataCnt = 256
		if n <= 256 {
			xferDataCnt = n
		}
	}
	xferDataArr, _ = alloc.Make([]xferData{}, xferDataCnt)
	for i := 0; i < xferDataCnt; i++ {
		sub_40B930(&xferDataArr[i])
	}
	xferDataActive = 0
}

func sub_40B930(p *xferData) {
	p.NetInd0 = netstr.Handle{}
	p.Stream4 = 0
	p.Kind6 = 0
	p.Size8 = 0
	p.Cnt12 = 1
	p.Blocks16 = 0
	p.BlockSz20 = 0
	p.Field22 = 0
	p.Type23 = ""
	p.First152 = nil
	p.Last156 = nil
}

func sub_40B970() {
	s := noxServer
	if xferDataActive == 0 {
		return
	}
	if int32(xferDataCnt) <= 0 {
		return
	}
	for i := 0; i < xferDataCnt; i++ {
		it := &xferDataArr[i]
		if it.Kind6 != 2 {
			continue
		}
		for j, it2 := 0, it.First152; j < 2 && it2 != nil; j, it2 = j+1, it2.Next20 {
			if t := it2.Frame12; t != 0 {
				if s.Frame() > t+90 {
					if it2.Cnt16 >= 20 {
						if it.Kind6 == 2 {
							sub_40BB20(it.NetInd0, it.Stream4, 2)
							break
						}
					} else {
						sub_40BA90(it.NetInd0, it.Stream4, it2.Ind0, it2.Data4)
						it2.Frame12 = s.Frame()
						it2.Cnt16++
					}
				}
			} else {
				sub_40BA90(it.NetInd0, it.Stream4, it2.Ind0, it2.Data4)
				it.Cnt12++
				it2.Frame12 = s.Frame()
			}
		}
	}
}

func sub_40BC10(ind netstr.Handle, a2 byte) *xferData {
	for i := 0; i < xferDataCnt; i++ {
		it := &xferDataArr[i]
		if it.NetInd0 == ind && it.Stream4 == a2 {
			return it
		}
	}
	return nil
}

func sub_40BF10() (*xferData, int) {
	for i := 0; i < xferDataCnt; i++ {
		it2 := &xferDataArr[i]
		if it2.Kind6 == 0 && it2.Size8 == 0 {
			return it2, i
		}
	}
	return nil, -1
}

func xferAccept40BFF0(a1 netstr.Handle, stream byte, tok byte) {
	if int(tok) >= xferDataCnt {
		return
	}
	p := &xferDataArr[tok]
	p.Stream4 = stream
	p.Kind6 = 2
}

func sub_40C0D0() {
	alloc.FreeSlice(xferDataArr)
}

func sub_40C0E0(ind netstr.Handle) {
	for i := 0; i < xferDataCnt; i++ {
		it := &xferDataArr[i]
		if it.Blocks16 == 2 && it.NetInd0 == ind {
			sub_40BB20(it.NetInd0, it.Stream4, 1)
		}
	}
}

func sub_40BB20(conn netstr.Handle, a2 byte, a3 byte) *xferData {
	p := sub_40BC10(conn, a2)
	if p == nil {
		return nil
	}
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 5 // XFER_CODE5
	buf[2] = a2
	buf[3] = a3
	conn.Send(buf[:4], netstr.SendQueue|netstr.SendFlush)
	sub_40BBC0(p.NetInd0, p.Field22)
	if xferDataActive != 0 {
		xferDataActive--
	}
	for it := p.First152; it != nil; it = it.Next20 {
		*it = xferBlock{}
	}
	sub_40B930(p)
	return p
}

func sub_40BC60(pli ntype.PlayerInd, a2 byte, typ string, data []byte, flag bool) bool {
	p, pi := sub_40BF10()
	if p == nil {
		return false
	}
	if len(data) == 0 {
		return false
	}
	var nind netstr.Handle
	if !noxflags.HasGame(noxflags.GameHost) {
		nind = netstrClientConn
	} else {
		if !noxflags.HasGame(noxflags.GameClient) {
			return false
		}
		if !flag {
			sub_40B810(a2, data)
			return true
		}
		if pli == server.HostPlayerIndex {
			sub_40B810(a2, data)
			return true
		}
		nind = netstr.Global.ByPlayerInd(pli)
	}
	xferDataActive++
	left := data
	const blockSz = 512
	blocks := (len(data)-1)/blockSz + 1
	for i := 0; i < blocks; i++ {
		b := &xferBlock{
			Ind0: uint16(i + 1),
		}
		n := blockSz
		if len(left) <= n {
			n = len(left)
		}
		buf := make([]byte, n)
		copy(buf, left[:n])
		b.Data4 = buf
		b.Frame12 = 0
		b.Cnt16 = 0
		b.Next20 = nil
		b.Prev24 = p.Last156
		left = left[n:]
		if prev := p.Last156; prev != nil {
			prev.Next20 = b
		} else {
			p.First152 = b
		}
		p.Last156 = b
	}
	p.NetInd0 = nind
	p.Stream4 = 0
	p.Kind6 = 1
	p.Size8 = len(data)
	p.Cnt12 = 1
	p.Blocks16 = blocks
	p.BlockSz20 = blockSz
	if typ != "" {
		p.Type23 = typ
	}
	p.Field22 = a2
	nox_xxx_netXferMsg_40BE80(nind, a2, typ, len(data), byte(pi))
	return true
}

func nox_xxx_netXferMsg_40BE80(conn netstr.Handle, act byte, typ string, sz int, tok byte) {
	var buf [140]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 0 // XFER_START
	buf[2] = act
	binary.LittleEndian.PutUint32(buf[4:], uint32(sz))
	n := copy(buf[8:136], typ)
	buf[8+n] = 0
	buf[136] = tok
	conn.Send(buf[:140], netstr.SendQueue|netstr.SendFlush)
}

func xferClose40C030(ind netstr.Handle, a2 byte) {
	p := sub_40BC10(ind, a2)
	if p == nil {
		return
	}
	sub_40B850(ind, p.Field22)
	xferDataActive--
	sub_40B930(p)
}

func xferCodeSix40C070(ind netstr.Handle, a2 byte, a3 byte) {
	p := sub_40BC10(ind, a3)
	if p == nil {
		return
	}
	sub_40BBC0(p.NetInd0, p.Field22)
	for it := p.First152; it != nil; it = it.Next20 {
		*it = xferBlock{}
	}
	sub_40B930(p)
}

func xferAck40BF60(ind netstr.Handle, a2 byte, a3 uint16) {
	p := sub_40BC10(ind, a2)
	if p == nil {
		return
	}
	for it := p.First152; it != nil; it = it.Next20 {
		if it.Ind0 == a3 {
			if next := it.Next20; next != nil {
				next.Prev24 = it.Prev24
			} else {
				p.Last156 = it.Prev24
			}
			if prev := it.Prev24; prev != nil {
				prev.Next20 = it.Next20
			} else {
				p.First152 = it.Next20
			}
			*it = xferBlock{}
			return
		}
	}
}

func xferStart40B5D0(a1 netstr.Handle, act byte, typ string, sz uint32, tok byte) {
	s := noxServer
	if sz == 0 {
		return
	}
	p, ind := sub_40B6D0()
	if p == nil {
		return
	}
	p.NetInd0 = a1
	p.Act4 = act
	if typ != "" {
		p.Type24 = typ
	}
	p.Stream5 = ind
	p.Data20 = make([]byte, sz)
	p.Frame156 = s.Frame()
	dword_5d4594_3628++
	xferSendAccept(a1, ind, tok)
}

func sub_40B1F0(i byte) {
	p := &dword_5d4594_3620[i]
	p.Act4 = 0
	p.Stream5 = i
	p.Cnt8 = 1
	p.Cur12 = 0
	p.Data20 = nil
	p.Type24 = ""
	p.Perc152 = 0
	p.Frame156 = 0
	p.Field160 = nil
	p.Field164 = nil
}

func sub_40B4E0(a1 uint8) {
	p := &dword_5d4594_3620[a1]
	for it := p.Field160; it != nil; it = it.Next20 {
		*it = xferBlock{}
	}
}

func sub_40B530(i byte, a2 byte) {
	p := &dword_5d4594_3620[i]
	if len(p.Data20) != 0 {
		nox_xxx_neXfer_40B590(p.NetInd0, p.Stream5, a2)
		if dword_5d4594_3628 != 0 {
			dword_5d4594_3628--
		}
		sub_40B4E0(i)
		sub_40B1F0(i)
	}
}

func nox_xxx_neXfer_40B590(conn netstr.Handle, a2 byte, a3 byte) {
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 6 // XFER_CODE6
	buf[2] = a2
	buf[3] = a3
	conn.Send(buf[:4], netstr.SendQueue|netstr.SendFlush)
}

func sub_40B170(cnt int) {
	n := cnt
	if cnt >= 0 {
		if cnt > 256 {
			n = 256
		}
	} else {
		n = 16
	}
	dword_5d4594_3624 = n
	dword_5d4594_3620 = make([]xferDataTwo, n)
	for i := 0; i < dword_5d4594_3624; i++ {
		sub_40B1F0(byte(i))
	}
}

func sub_40B6D0() (*xferDataTwo, byte) {
	if dword_5d4594_3624 <= 0 {
		return nil, 0
	}
	for i := 0; i < dword_5d4594_3624; i++ {
		it := &dword_5d4594_3620[i]
		if len(it.Data20) == 0 {
			return it, byte(i)
		}
	}
	return nil, 0
}

func xferDataChunk40B250(ind netstr.Handle, a2 byte, a3 uint16, data []byte) {
	s := noxServer
	if len(data) == 0 {
		return
	}
	if int(a2) >= dword_5d4594_3624 {
		return
	}
	p := &dword_5d4594_3620[a2]
	if len(p.Data20) == 0 {
		return
	}
	p.Frame156 = s.Frame()
	if uint32(a3) == p.Cnt8 {
		copy(p.Data20[p.Cur12:p.Cur12+len(data)], data)
		p.Cur12 += len(data)
		p.Cnt8++
	} else {
		b := &xferBlock{
			Ind0:  a3,
			Data4: make([]byte, len(data)),
		}
		copy(b.Data4, data)
		b.Next20 = nil
		b.Prev24 = p.Field164
		if v9 := p.Field164; v9 != nil {
			v9.Next20 = b
		}
		p.Field164 = b
		if v10 := p.Field160; v10 == nil {
			p.Field160 = b
		}
	}

	for it := p.Field160; it != nil; it = it.Next20 {
		if p.Cnt8 == uint32(it.Ind0) {
			copy(p.Data20[p.Cur12:p.Cur12+len(it.Data4)], it.Data4)
			p.Cur12 += len(it.Data4)
			p.Cnt8++
			if v14 := it.Prev24; v14 != nil {
				v14.Next20 = it.Next20
			} else {
				p.Field160 = it.Next20
			}
			if v15 := it.Next20; v15 != nil {
				v15.Prev24 = it.Prev24
			} else {
				p.Field164 = it.Prev24
			}
			*it = xferBlock{}
		}
	}
	p.Perc152 = float32(float64(p.Cur12) / float64(len(p.Data20)) * 100.0)
	if p.Cur12 == len(p.Data20) {
		nox_xxx_netXfer_40B4B0(p.NetInd0, p.Stream5)
		xferDataCallback40AF90(ind.Player(), p.Stream5, p.Act4, p.Type24, p.Data20)
		if dword_5d4594_3628 != 0 {
			dword_5d4594_3628--
		}
		p.Data20 = nil
		sub_40B4E0(a2)
		sub_40B1F0(a2)
	}
}

func nox_xxx_netXfer_40B4B0(conn netstr.Handle, a2 byte) {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 4 // XFER_CLOSE
	buf[2] = a2
	conn.Send(buf[:3], netstr.SendQueue|netstr.SendFlush)
}

func sub_40B740() {
	for i := 0; i < dword_5d4594_3624; i++ {
		sub_40B4E0(byte(i))
	}
	dword_5d4594_3620 = nil
}

func sub_40B790() {
	s := noxServer
	for i := 0; i < dword_5d4594_3624; i++ {
		it := &dword_5d4594_3620[i]
		if len(it.Data20) != 0 && s.Frame() > it.Frame156+900 {
			sub_40B530(byte(i), 3)
		}
	}
}

func xferSendAccept(conn netstr.Handle, stream byte, tok byte) {
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 1 // XFER_ACCEPT
	buf[2] = stream
	buf[3] = tok
	conn.Send(buf[:4], netstr.SendQueue|netstr.SendFlush)
}

func xferCodeFive40B720(a1 byte, a2 byte) {
	sub_40B4E0(a2)
	sub_40B1F0(a2)
}
