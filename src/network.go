package opennox

import (
	"bytes"
	"context"
	"encoding/binary"
	"encoding/hex"
	"errors"
	"fmt"
	"image"
	"math"
	"net/netip"
	"strings"
	"time"
	"unsafe"

	"github.com/noxworld-dev/nat"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/common/serial"
	"github.com/noxworld-dev/opennox/v1/common/sound"
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
	buf[54] = memmap.Uint8(0x85B3FC, 12254)
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

func (s *Server) nox_xxx_netSendPacket_4E5030(a1 int, buf []byte, a4, a5, a6 int) int {
	return legacy.Nox_xxx_netSendPacket_4E5030(a1, buf, a4, a5, a6)
}

func (s *Server) nox_xxx_netSendPacket0_4E5420(a1 int, buf []byte, a4, a5 int) int {
	return s.nox_xxx_netSendPacket_4E5030(a1, buf, a4, a5, 0)
}
func (s *Server) nox_xxx_netSendPacket1_4E5390(a1 int, buf []byte, a4, a5 int) int {
	return s.nox_xxx_netSendPacket_4E5030(a1, buf, a4, a5, 1)
}

func (s *Server) nox_xxx_netMsgFadeBegin_4D9800(a1, a2 bool) int {
	var p [3]byte
	p[0] = byte(noxnet.MSG_FADE_BEGIN)
	p[1] = byte(bool2int(a1))
	p[2] = byte(bool2int(a2))
	return s.nox_xxx_netSendPacket1_4E5390(255, p[:], 0, 1)
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
	nbuf := ctrlEvent.netBuf
	if len(nbuf) == 0 {
		return true
	}
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_PLAYER_INPUT)
	buf[1] = byte(len(nbuf))
	if !netlist.AddToMsgListCli(pli, netlist.Kind0, buf[:2]) {
		return false
	}
	if !netlist.AddToMsgListCli(pli, netlist.Kind0, nbuf) {
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

	var buf [5]byte
	buf[0] = byte(noxnet.MSG_MOUSE)
	binary.LittleEndian.PutUint16(buf[1:], uint16(mp.X))
	binary.LittleEndian.PutUint16(buf[3:], uint16(mp.Y))
	return netlist.AddToMsgListCli(pli, netlist.Kind0, buf[:5])
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
	conn := netstrClientConn
	var data [1]byte
	data[0] = byte(noxnet.MSG_CANCEL_MAP)
	v0, _ := conn.Send(data[:], netstr.SendQueue|netstr.SendFlush)
	if conn.WaitServerResponse(v0, 20, netstr.RecvNoHooks|netstr.RecvJustOne) != 0 {
		return 0
	}
	netlist.ResetByInd(common.MaxPlayers-1, netlist.Kind0)
	return 1
}

func nox_xxx_netSendIncomingClient_43CB00() int {
	conn := netstrClientConn
	var data [1]byte
	data[0] = byte(noxnet.MSG_INCOMING_CLIENT)
	v0, _ := conn.Send(data[:], netstr.SendQueue|netstr.SendFlush)
	if conn.WaitServerResponse(v0, 20, netstr.RecvNoHooks|netstr.RecvJustOne) != 0 {
		return 0
	}
	netlist.ResetByInd(common.MaxPlayers-1, netlist.Kind0)
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
	conn := netstrClientConn
	var data [1]byte
	data[0] = byte(noxnet.MSG_OUTGOING_CLIENT)
	v0, _ := conn.Send(data[:], netstr.SendQueue|netstr.SendFlush)
	if conn.WaitServerResponse(v0, 20, netstr.RecvNoHooks|netstr.RecvJustOne) != 0 {
		return 0
	}
	conn.RecvLoop(netstr.RecvCanRead | netstr.RecvNoHooks)
	netlist.ResetByInd(common.MaxPlayers-1, netlist.Kind0)
	return 1
}

func nox_xxx_netInformTextMsg_4DA0F0(pid ntype.PlayerInd, code byte, ind int) bool {
	if pid < 0 {
		return false
	}
	var buf [6]byte
	buf[0] = byte(noxnet.MSG_INFORM)
	buf[1] = code
	switch code {
	case 0, 1, 2, 12, 13, 16, 20, 21:
		binary.LittleEndian.PutUint32(buf[2:], uint32(ind))
		return netlist.AddToMsgListCli(pid, netlist.Kind1, buf[:6])
	case 17:
		return netlist.AddToMsgListCli(pid, netlist.Kind1, buf[:2])
	default:
		return true
	}
}

func nox_xxx_netReportSpellStat_4D9630(a1 int, a2 spell.ID, a3 byte) bool {
	var buf [6]byte
	buf[0] = byte(noxnet.MSG_REPORT_SPELL_STAT)
	binary.LittleEndian.PutUint32(buf[1:], uint32(a2))
	buf[5] = a3
	return noxServer.nox_xxx_netSendPacket0_4E5420(a1, buf[:], 0, 1) != 0
}

func nox_xxx_netSendPointFx_522FF0(fx noxnet.Op, pos types.Pointf) bool {
	var buf [5]byte
	buf[0] = byte(fx)
	binary.LittleEndian.PutUint16(buf[1:], uint16(int(pos.X)))
	binary.LittleEndian.PutUint16(buf[3:], uint16(int(pos.Y)))
	return legacy.Nox_xxx_netSendFxAllCli_523030(pos, buf[:5])
}

func nox_xxx_netSendRayFx_5232F0(fx noxnet.Op, p1, p2 image.Point) bool {
	var buf [9]byte
	buf[0] = byte(fx)
	binary.LittleEndian.PutUint16(buf[1:], uint16(p1.X))
	binary.LittleEndian.PutUint16(buf[3:], uint16(p1.Y))
	binary.LittleEndian.PutUint16(buf[5:], uint16(p2.X))
	binary.LittleEndian.PutUint16(buf[7:], uint16(p2.Y))
	return legacy.Nox_xxx_servCode_523340(p1, p2, buf[:9])
}

func nox_xxx_netSparkExplosionFx_5231B0(pos types.Pointf, a2 byte) bool {
	var buf [6]byte
	buf[0] = byte(noxnet.MSG_FX_SPARK_EXPLOSION)
	binary.LittleEndian.PutUint16(buf[1:], uint16(pos.X))
	binary.LittleEndian.PutUint16(buf[3:], uint16(pos.Y))
	buf[5] = a2
	return legacy.Nox_xxx_netSendFxAllCli_523030(pos, buf[:6])
}

func nox_xxx_netSendFxGreenBolt_523790(p1, p2 image.Point, a2 int) bool {
	var buf [11]byte
	buf[0] = byte(noxnet.MSG_FX_GREEN_BOLT)
	binary.LittleEndian.PutUint16(buf[1:], uint16(p1.X))
	binary.LittleEndian.PutUint16(buf[3:], uint16(p1.Y))
	binary.LittleEndian.PutUint16(buf[5:], uint16(p2.X))
	binary.LittleEndian.PutUint16(buf[7:], uint16(p2.Y))
	binary.LittleEndian.PutUint16(buf[9:], uint16(a2))
	pos := types.Pointf{
		X: float32(p1.X) + float32(p2.X-p1.X)*0.5,
		Y: float32(p1.Y) + float32(p2.Y-p1.Y)*0.5,
	}
	return legacy.Nox_xxx_netSendFxAllCli_523030(pos, buf[:11])
}

func nox_xxx_netSendVampFx_523270(fx noxnet.Op, p1, p2 image.Point, a3 int) bool {
	var buf [11]byte
	buf[0] = byte(fx)
	binary.LittleEndian.PutUint16(buf[1:], uint16(p1.X))
	binary.LittleEndian.PutUint16(buf[3:], uint16(p1.Y))
	binary.LittleEndian.PutUint16(buf[5:], uint16(p2.X))
	binary.LittleEndian.PutUint16(buf[7:], uint16(p2.Y))
	binary.LittleEndian.PutUint16(buf[9:], uint16(a3))
	pos := types.Pointf{
		X: float32(p2.X),
		Y: float32(p2.Y),
	}
	return legacy.Nox_xxx_netSendFxAllCli_523030(pos, buf[:11])
}

func nox_xxx_netReportLesson_4D8EF0(u *Object) {
	var buf [11]byte
	buf[0] = byte(noxnet.MSG_REPORT_LESSON)
	pl := u.ControllingPlayer()
	binary.LittleEndian.PutUint16(buf[1:], uint16(u.NetCode))
	binary.LittleEndian.PutUint32(buf[3:], uint32(pl.Lessons))
	binary.LittleEndian.PutUint32(buf[7:], uint32(pl.Field2140))
	noxServer.nox_xxx_netSendPacket1_4E5390(255, buf[:11], 0, 1)
}

func nox_xxx_netScriptMessageKill_4D9760(u *Object) {
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	pl := u.ControllingPlayer()
	var buf [1]byte
	buf[0] = byte(noxnet.MSG_MESSAGES_KILL)
	noxServer.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:1], 0, 1)
}

func nox_xxx_netKillChat_528D00(u *Object) {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_CHAT_KILL)
	binary.LittleEndian.PutUint16(buf[1:], uint16(noxServer.GetUnitNetCode(u)))
	for _, pl := range noxServer.GetPlayers() {
		u := pl.UnitC()
		if u == nil {
			continue
		}
		netlist.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:3])
	}
}

func netSendGauntlet() {
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_GAUNTLET)
	buf[1] = 27
	nox_xxx_netClientSend2_4E53C0(common.MaxPlayers-1, buf[:2], 0, 0)
}

func nox_xxx_sendGauntlet_4DCF80(ind ntype.PlayerInd, v byte) {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_GAUNTLET)
	buf[1] = 28
	buf[2] = v
	noxServer.nox_xxx_netSendPacket1_4E5390(int(ind), buf[:3], 0, 0)
}

func nox_xxx_netStatsMultiplier_4D9C20(u *server.Object) int {
	if u == nil {
		return 0
	}
	pl := u.ControllingPlayer()
	var buf [17]byte
	buf[0] = byte(noxnet.MSG_STAT_MULTIPLIERS)
	switch pl.PlayerClass() {
	default:
		return 0
	case player.Warrior:
		binary.LittleEndian.PutUint32(buf[1:], math.Float32bits(float32(legacy.Get_nox_xxx_warriorMaxHealth_587000_312784())))
		binary.LittleEndian.PutUint32(buf[5:], math.Float32bits(float32(legacy.Get_nox_xxx_warriorMaxMana_587000_312788())))
		binary.LittleEndian.PutUint32(buf[9:], math.Float32bits(noxServer.Players.Mult.Warrior.Strength))
		binary.LittleEndian.PutUint32(buf[13:], math.Float32bits(noxServer.Players.Mult.Warrior.Speed))
	case player.Wizard:
		binary.LittleEndian.PutUint32(buf[1:], math.Float32bits(float32(legacy.Get_nox_xxx_wizardMaxHealth_587000_312816())))
		binary.LittleEndian.PutUint32(buf[5:], math.Float32bits(float32(legacy.Get_nox_xxx_wizardMaximumMana_587000_312820())))
		binary.LittleEndian.PutUint32(buf[9:], math.Float32bits(noxServer.Players.Mult.Wizard.Strength))
		binary.LittleEndian.PutUint32(buf[13:], math.Float32bits(noxServer.Players.Mult.Wizard.Speed))
	case player.Conjurer:
		binary.LittleEndian.PutUint32(buf[1:], math.Float32bits(float32(legacy.Get_nox_xxx_conjurerMaxHealth_587000_312800())))
		binary.LittleEndian.PutUint32(buf[5:], math.Float32bits(float32(legacy.Get_nox_xxx_conjurerMaxMana_587000_312804())))
		binary.LittleEndian.PutUint32(buf[9:], math.Float32bits(noxServer.Players.Mult.Conjurer.Strength))
		binary.LittleEndian.PutUint32(buf[13:], math.Float32bits(noxServer.Players.Mult.Conjurer.Speed))
	}
	return noxServer.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:17], 0, 1)
}

func netSendServerQuit() {
	var buf [1]byte
	buf[0] = byte(noxnet.MSG_SERVER_QUIT)
	noxServer.nox_xxx_netSendPacket0_4E5420(159, buf[:1], 0, 1)
}

func nox_xxx_netSendBallStatus_4D95F0(a1 int, a2 byte, a3 uint16) int {
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_REPORT_BALL_STATUS)
	buf[1] = a2
	binary.LittleEndian.PutUint16(buf[2:], a3)
	return noxServer.nox_xxx_netSendPacket1_4E5390(a1, buf[:4], 0, 1)
}

func (s *Server) netPrintLineToAll(id strman.ID) { // nox_xxx_netPrintLineToAll_4DA390
	for _, u := range s.getPlayerUnits() {
		nox_xxx_netPriMsgToPlayer_4DA2C0(u.SObj(), id, 0)
	}
}

func nox_xxx_netPriMsgToPlayer_4DA2C0(u *server.Object, id strman.ID, a3 byte) {
	var buf [52]byte
	if u == nil || !u.Class().Has(object.ClassPlayer) || id == "" || len(id) > len(buf)-4 || legacy.Sub_419E60(u.SObj()) != 0 {
		return
	}
	buf[0] = byte(noxnet.MSG_INFORM)
	buf[1] = 15
	buf[2] = a3
	n := copy(buf[3:len(buf)-1], string(id))
	buf[3+n] = 0
	netlist.AddToMsgListCli(u.ControllingPlayer().PlayerIndex(), netlist.Kind1, buf[:n+4])
}

func nox_xxx_netSendBySock_40EE10(conn netstr.Handle, ind ntype.PlayerInd, kind netlist.Kind) {
	netlist.HandlePacketsA(ind, kind, func(data []byte) {
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
			for it := s.PlayerFirst(); it != nil; it = s.PlayerNext(it) {
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
			pit := asPlayerS(it)
			if add(it) {
				found = pit
				return false
			}
			return true // continue
		})
		if found != nil {
			s.GetPlayerByInd(found.PlayerIndex()).Disconnect(4)
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
	if pli != common.MaxPlayers-1 {
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

func nox_xxx_netOnPacketRecvCli_48EA70(ind ntype.PlayerInd, buf *byte, sz int) int {
	return noxClient.nox_xxx_netOnPacketRecvCli48EA70(ind, unsafe.Slice(buf, sz))
}

func getCurPlayer() *Player {
	return asPlayerS(legacy.AsPlayerP(*memmap.PtrPtr(0x8531A0, 2576)))
}

func setCurPlayer(p *Player) {
	*memmap.PtrPtr(0x8531A0, 2576) = p.C()
}

func nox_xxx_netTestHighBit_578B70(v uint16) bool    { return (v>>15)&1 != 0 }
func nox_xxx_netClearHighBit_578B30(v uint16) uint16 { return v & 0x7FFF }

func (c *Client) nox_xxx_netOnPacketRecvCli48EA70_switch(ind ntype.PlayerInd, op noxnet.Op, data []byte, v364 *uint32, v373 *uint16) int {
	if len(data) == 0 {
		return 0
	}
	switch op {
	case noxnet.MSG_XXX_STOP:
		return 1
	case noxnet.MSG_FULL_TIMESTAMP:
		if len(data) < 5 {
			return -1
		}
		frame := binary.LittleEndian.Uint32(data[1:])
		c.srv.SetFrame(frame)
		*memmap.PtrUint32(0x5D4594, 1200800) = c.srv.Frame()
		*v364 = c.srv.Frame()
		*memmap.PtrUint32(0x5D4594, 1200808) = (c.srv.Frame() & 0xffff) >> 14
		if p := getCurPlayer(); p != nil {
			legacy.Nox_xxx_playerUnsetStatus_417530(p.S(), 64)
		}
		legacy.Sub_43C650()
		return 5
	case noxnet.MSG_SIMULATED_TIMESTAMP:
		frame := uint32(*v373)
		if frame < (memmap.Uint32(0x5D4594, 1200800) + sub_43C790()) {
			c.srv.SetFrame(frame)
		}
		return 5
	case noxnet.MSG_TIMESTAMP:
		if len(data) < 3 {
			return -1
		}
		fr := binary.LittleEndian.Uint16(data[1:])
		*v373 = fr
		if p := getCurPlayer(); p != nil && p.Field3680&0x40 != 0 {
			return 3
		}
		v9 := 1
		prevFrame := c.srv.Frame()
		v11 := fr
		v12 := uint32(v11) + (c.srv.Frame() & 0xFFFF0000)
		v13 := int32(v11) >> 14
		if uint32(v13) != memmap.Uint32(0x5D4594, 1200808) {
			if v13 == ((int32(memmap.Uint8(0x5D4594, 1200808)) + 1) & 3) {
				*memmap.PtrUint32(0x5D4594, 1200808) = uint32(v13)
				if v13 == 0 {
					v12 += 0x10000
				}
			} else {
				v9 = 0
			}
		}
		if v12 < c.srv.Frame() {
			v9 = 0
		}
		if !noxflags.HasGame(noxflags.GameHost) && v9 == 1 {
			c.srv.SetFrame(v12)
			*memmap.PtrUint32(0x5D4594, 1200800) = v12
		}
		*v364 = v12
		if !noxflags.HasGame(noxflags.GameHost) && v9 == 0 {
			noxPerfmon.latePackets--
			*memmap.PtrUint32(0x85B3FC, 120)++
			return 3
		}
		if c.srv.Frame() > prevFrame+1 {
			noxPerfmon.latePackets += int(c.srv.Frame() - prevFrame)
		}
		legacy.Sub_43C650()
		return 3
	case noxnet.MSG_SERVER_QUIT:
		var buf [1]byte
		buf[0] = byte(noxnet.MSG_SERVER_QUIT_ACK)
		netstrGetClientIndex().Send(buf[:1], netstr.SendFlush)
		sub_446380()
		return 1
	case noxnet.MSG_USE_MAP:
		if len(data) < 41 {
			return -1
		}
		if mframe := binary.LittleEndian.Uint32(data[37:]); mframe > uint32(legacy.Get_dword_5d4594_1200804()) {
			noxSetUseMapFrame(int(mframe))
			noxClient.nox_xxx_gameClearAll_467DF0(true)
			c.srv.nox_xxx_gameSetMapPath_409D70(alloc.GoStringS(data[1:33]))
			nox_xxx_mapSetCrcMB_409B10(binary.LittleEndian.Uint32(data[33:]))
			if !noxflags.HasGame(noxflags.GameHost) {
				noxflags.UnsetGame(noxflags.GameFlag4)
				if legacy.Get_dword_5d4594_2650652() != 0 {
					legacy.Sub_41D6C0()
				}
			}
			noxflags.SetGame(noxflags.GameFlag24)
			legacy.Set_dword_5d4594_1200804(c.srv.Frame())
			nox_xxx_gameSetCliConnected(false)
			legacy.Sub_49C7A0()
			legacy.Nox_xxx_guiServerOptionsHide_4597E0(0)
			sub_44A400()
		}
		return 41
	case noxnet.MSG_JOIN_DATA:
		if len(data) < 7 {
			return -1
		}
		playerID := nox_xxx_netClearHighBit_578B30(binary.LittleEndian.Uint16(data[1:]))
		legacy.Set_nox_player_netCode_85319C(uint32(playerID))
		pl := c.srv.NewPlayerInfo(int(playerID))
		if pl != nil {
			pl.Field2068 = binary.LittleEndian.Uint32(data[3:])
			setCurPlayer(pl)
		}
		if !noxflags.HasGame(noxflags.GameHost) {
			legacy.Sub_57B920(memmap.PtrOff(0x5D4594, 1198020))
		}
		legacy.Set_dword_5d4594_1200804(0)
		noxPerfmon.latePackets = 0
		*memmap.PtrUint32(0x85B3FC, 120) = 0
		noxPerfmon.ping = 0
		legacy.Set_dword_5d4594_1200832(0)
		legacy.Nox_xxx_cliSetSettingsAcquired_4169D0(0)
		return 7
	case noxnet.MSG_NEW_PLAYER:
		if len(data) < 129 {
			return -1
		}
		playerID := nox_xxx_netClearHighBit_578B30(binary.LittleEndian.Uint16(data[1:]))
		pl := c.srv.NewPlayerInfo(int(playerID))
		if pl == nil {
			return 129
		}
		if !noxflags.HasGame(noxflags.GameHost) {
			pl.NetCodeVal = uint32(playerID)
			pl.Lessons = int32(int16(binary.LittleEndian.Uint16(data[100:])))
			pl.Field2140 = uint32(int32(int16(binary.LittleEndian.Uint16(data[102:]))))
			pl.Field0 = binary.LittleEndian.Uint32(data[104:])
			pl.Field4 = binary.LittleEndian.Uint32(data[108:])
			pl.Field2152 = uint32(data[116])
			pl.Field2156 = uint32(data[117])
			pl.SetField2096(alloc.GoStringS(data[119:]))
			pl.Field3680 |= binary.LittleEndian.Uint32(data[112:])
			pl.Info()
			*pl.Info() = *(*server.PlayerInfo)(unsafe.Pointer(&data[3 : 3+97][0])) // TODO: safe copy
			pl.SetName(pl.Info().Name() + pl.Info().NameSuff())
			if legacy.Get_dword_5d4594_2650652() != 0 {
				pl.Field2108 = 0
				legacy.Sub_41D670(pl.Field2096())
			}
			legacy.Nox_xxx_playerInitColors_461460(pl.S())
		}
		legacy.Sub_457140(int(playerID), &pl.NameFinal[0])
		legacy.Sub_455920(&pl.NameFinal[0])
		if gameGetPlayState() == 3 {
			format := c.Strings().GetStringInFile("PlayerJoined", "cdecode.c")
			nox_xxx_printCentered_445490(fmt.Sprintf(format, pl.Name()))
		}
		if uint32(playerID) == uint32(legacy.Get_nox_player_netCode_85319C()) && alloc.GoString16((*uint16)(memmap.PtrOff(0x85B3FC, 12204))) != pl.Name() {
			legacy.Set_dword_5d4594_1200832(1)
		}
		return 129
	case noxnet.MSG_PLAYER_QUIT:
		if len(data) < 3 {
			return -1
		}
		if !nox_client_isConnected() {
			return 3
		}

		playerID := nox_xxx_netClearHighBit_578B30(binary.LittleEndian.Uint16(data[1:]))
		pl := c.srv.GetPlayerByID(int(playerID))
		var msg string
		if pl != nil {
			legacy.Sub_456DF0(int(playerID))
			legacy.Sub_455950(&pl.NameFinal[0])
			format := c.Strings().GetStringInFile("PlayerLeft", "cdecode.c")
			msg = fmt.Sprintf(format, pl.Name())

			pl.Active = 0
			tobj := nox_xxx_objGetTeamByNetCode_418C80(int(playerID))
			if tobj != nil && tobj.Has() {
				legacy.Nox_xxx_netChangeTeamMb_419570(tobj, uint32(playerID))
			}
		} else {
			msg = c.Strings().GetStringInFile("UnknownLeft", "cdecode.c")
		}
		if gameGetPlayState() == 3 {
			nox_xxx_printCentered_445490(msg)
		}
		return 3
	case noxnet.MSG_REPORT_SPELL_START:
		if len(data) < 2 {
			return -1
		}
		legacy.Sub_49BB80(data[1])
		return 2
	case noxnet.MSG_REPORT_INVENTORY_LOADED:
		legacy.Sub_467CA0()
		return 1
	case noxnet.MSG_FX_DEATH_RAY:
		if len(data) < 9 {
			return -1
		}
		p1x := binary.LittleEndian.Uint16(data[1:])
		p1y := binary.LittleEndian.Uint16(data[3:])
		p2x := binary.LittleEndian.Uint16(data[5:])
		p2y := binary.LittleEndian.Uint16(data[7:])
		c.clientFXDeathRay(image.Pt(int(p1x), int(p1y)), image.Pt(int(p2x), int(p2y)))
		return 9
	case noxnet.MSG_FX_PARTICLEFX:
		if len(data) < 14 {
			return -1
		}
		drID := nox_xxx_netClearHighBit_578B30(binary.LittleEndian.Uint16(data[8:]))
		if nox_client_isConnected() {
			var dr *client.Drawable
			if nox_xxx_netTestHighBit_578B70(binary.LittleEndian.Uint16(data[8:])) {
				dr = c.Objs.ByNetCodeStatic(int(drID))
			} else {
				dr = c.Objs.ByNetCodeDynamic(int(drID))
			}
			c.r.partfx.onParticleFx(data[1], dr, int(binary.LittleEndian.Uint16(data[2:])), binary.LittleEndian.Uint16(data[4:]) != 0, int(binary.LittleEndian.Uint16(data[6:])))
		}
		return 14
	case noxnet.MSG_IMPORTANT:
		n := 1
		if noxflags.HasGame(noxflags.GameHost) {
			n = 5
		}
		if len(data) < n {
			return -1
		}
		if nox_client_isConnected() {
			var buf [5]byte
			buf[0] = byte(noxnet.MSG_IMPORTANT_ACK)
			if noxflags.HasGame(noxflags.GameHost) {
				v := binary.LittleEndian.Uint32(data[1:])
				binary.LittleEndian.PutUint32(buf[1:], v)
			} else {
				binary.LittleEndian.PutUint32(buf[1:], *v364)
			}
			netlist.AddToMsgListCli(ind, 0, buf[:5])
		}
		return n
	case noxnet.MSG_MAP_SEND_START:
		if len(data) < 88 {
			return -1
		}
		sz := binary.LittleEndian.Uint32(data[4:])
		name := alloc.GoStringS(data[8:88])
		c.mapsend.onMapDownloadStart(name, uint(sz))
		return 88
	case noxnet.MSG_MAP_SEND_PACKET:
		if len(data) < 6 {
			return -1
		}
		bind := binary.LittleEndian.Uint16(data[2:])
		sz := binary.LittleEndian.Uint16(data[4:])
		c.mapsend.onMapDownloadPart(uint(bind), data[6:6+sz])
		return 6 + int(sz)
	case noxnet.MSG_MAP_SEND_ABORT:
		if len(data) < 2 {
			return -1
		}
		c.mapsend.onMapDownloadAbort()
		return 2
	case noxnet.MSG_DIALOG:
		if len(data) < 2 {
			return -1
		}
		typ := data[1]
		switch typ {
		case 3:
			if len(data) < 135 {
				return -1
			}
			if nox_client_isConnected() {
				str := strman.ID(alloc.GoStringS(data[2:34]))
				title := alloc.GoString16B(data[34:98])
				snd := sound.ID(binary.LittleEndian.Uint32(data[98:]))
				pic := alloc.GoStringS(data[102:134])
				flags := server.DialogFlags(data[134])
				guiOpenNPCDialogID(title, snd, str, pic, flags)
				if pl := getCurPlayer(); pl != nil {
					legacy.Nox_xxx_netNeedTimestampStatus_4174F0(pl.S(), 512)
				}
			}
			return 135
		case 4:
			if nox_client_isConnected() {
				guiCloseNPCDialog()
				if pl := getCurPlayer(); pl != nil {
					legacy.Nox_xxx_playerUnsetStatus_417530(pl.S(), 512)
				}
			}
			return 2
		}
		return -1
	case noxnet.MSG_XFER_MSG:
		if len(data) < 2 {
			return -1
		}
		typ := data[1]
		switch typ {
		case 0:
			if len(data) < 140 {
				return -1
			}
			a2 := data[2]
			sz := binary.LittleEndian.Uint32(data[4:])
			styp := alloc.GoStringS(data[8:136])
			a4 := data[136]
			sub_40B5D0(netstrGetClientIndex(), a2, styp, sz, a4)
			return 140
		case 1:
			if len(data) < 4 {
				return -1
			}
			a2 := data[2]
			a3 := data[3]
			sub_40BFF0(netstrGetClientIndex(), a2, a3)
			return 4
		case 2:
			if len(data) < 8 {
				return -1
			}
			a2 := data[2]
			a3 := binary.LittleEndian.Uint16(data[4:])
			sz := int(binary.LittleEndian.Uint16(data[6:]))
			if len(data) < 8+sz {
				return -1
			}
			var buf [6]byte
			buf[0] = byte(noxnet.MSG_XFER_MSG)
			buf[1] = 3
			buf[2] = a2
			binary.LittleEndian.PutUint16(buf[4:], a3)
			netstrGetClientIndex().Send(buf[:6], netstr.SendQueue|netstr.SendFlush)
			sub_40B250(netstrGetClientIndex(), a2, a3, data[8:8+sz])
			return 8 + sz
		case 3:
			if len(data) < 6 {
				return -1
			}
			a2 := data[2]
			a3 := binary.LittleEndian.Uint16(data[4:])
			sub_40BF60(netstrGetClientIndex(), a2, a3)
			return 6
		case 4:
			if len(data) < 3 {
				return -1
			}
			a2 := data[2]
			sub_40C030(netstrGetClientIndex(), a2)
			return 3
		case 5:
			if len(data) < 4 {
				return -1
			}
			a2 := data[2]
			a3 := data[3]
			sub_40B720(a3, a2)
			return 4
		case 6:
			if len(data) < 4 {
				return -1
			}
			a2 := data[2]
			a3 := data[3]
			sub_40C070(netstrGetClientIndex(), a3, a2)
			return 4
		}
		return -1
	}
	return legacy.Nox_xxx_netOnPacketRecvCli_48EA70_switch(ind, op, data)
}

func (c *Client) nox_xxx_netOnPacketRecvCli48EA70(ind ntype.PlayerInd, data []byte) int {
	orig := data
	var iters [][]byte
	sub_470A80()
	var (
		v364 uint32
		v373 uint16
	)
	for len(data) > 0 {
		op := noxnet.Op(data[0])
		n := c.nox_xxx_netOnPacketRecvCli48EA70_switch(ind, op, data, &v364, &v373)
		if n == 0 {
			break // stop earlier
		} else if n < 0 {
			return 0 // error
		}
		if n == 0 { // safeguard
			n = 1
		}
		if n > len(data) {
			var buf bytes.Buffer
			fmt.Fprintf(&buf, "overflow when handling net packet: [%d:%d]\n", n, len(data))
			fmt.Fprintf(&buf, "PACKET: (%d bytes)\n", len(orig))
			buf.WriteString(hex.EncodeToString(orig))
			buf.WriteString("\n")
			buf.WriteString("SPLIT:\n")
			for _, b := range iters {
				buf.WriteString(hex.EncodeToString(b))
				buf.WriteString("\n")
			}
			buf.WriteString(hex.EncodeToString(data))
			buf.WriteString("\n")
			panic(errors.New(buf.String()))
		}
		iters = append(iters, data[:n])
		noxOnCliPacketDebug(op, data[:n])
		data = data[n:]
	}
	return 1
}

func sub_43C6E0() int {
	return bool2int(!dword_5d4594_815704 && !dword_5d4594_815708)
}

func nox_xxx_netHandleCliPacket_43C860(_ netstr.Handle, data []byte) int {
	op := noxnet.Op(data[0])
	noxPerfmon.packetSizeCli = len(data)
	if op == noxnet.MSG_XXX_STOP {
		sub_446380()
	} else if op == noxnet.MSG_PING {
		noxPerfmon.ping = time.Duration(binary.LittleEndian.Uint32(data[1:])) * time.Millisecond
	} else if op >= noxnet.MSG_TIMESTAMP {
		noxClient.nox_xxx_netOnPacketRecvCli48EA70(common.MaxPlayers-1, data)
		if nox_client_isConnected() {
			legacy.Sub_48D660()
		}
	}
	lastCliHandlePackets = platformTicks()
	if dword_5d4594_815704 {
		legacy.Sub_4AB4A0(0)
		dword_5d4594_815704 = false
	}
	if dword_5d4594_815708 {
		sub_43CF40()
	}
	return 1
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
			legacy.Nox_xxx_netNeedTimestampStatus_4174F0(pl.S(), 64)
			var buf [1]byte
			buf[0] = byte(noxnet.MSG_NEED_TIMESTAMP)
			nox_xxx_netClientSend2_4E53C0(common.MaxPlayers-1, buf[:1], 0, 1)
		}
	}
}

func (s *Server) nox_xxx_netSendBySock_4DDDC0(ind ntype.PlayerInd) {
	if !noxflags.HasGame(noxflags.GameClient) || ind != common.MaxPlayers-1 {
		netlist.HandlePacketsA(ind, netlist.Kind1, func(data []byte) {
			if len(data) == 0 {
				return
			}
			netstr.Global.ByPlayerInd(ind).Send(data, netstr.SendQueue|netstr.SendFlush)
		})
	}
}

func (s *Server) sendSettings(u *Object) {
	pl := u.ControllingPlayer()
	{
		var buf [5]byte
		buf[0] = byte(noxnet.MSG_FULL_TIMESTAMP)
		binary.LittleEndian.PutUint32(buf[1:], s.Frame())
		netlist.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:5])
	}
	{
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_JOIN_DATA)
		binary.LittleEndian.PutUint16(buf[1:], uint16(s.GetUnitNetCode(u)))
		binary.LittleEndian.PutUint32(buf[3:], uint32(pl.Field2068))
		netlist.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:7])
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
		netlist.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:20])
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
		netlist.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:49])
	}
	{
		var buf [129]byte
		nox_xxx_netNewPlayerMakePacket_4DDA90(buf[:], pl)
		netlist.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:129])
		s.nox_xxx_netSendBySock_4DDDC0(pl.PlayerIndex())
	}
	{
		var buf [41]byte
		buf[0] = byte(noxnet.MSG_USE_MAP)
		copy(buf[1:33], s.nox_server_currentMapGetFilename_409B30())
		buf[32] = 0
		binary.LittleEndian.PutUint32(buf[33:], nox_xxx_mapCrcGetMB_409B00())
		binary.LittleEndian.PutUint32(buf[37:], s.Frame())
		netstr.Global.ByPlayer(pl).Send(buf[:41], netstr.SendQueue|netstr.SendFlush)
		legacy.Sub_4DDE10(pl.Index(), pl.S())
	}
}

func nox_xxx_netUseMap_4DEE00(mname string, crc uint32) {
	var pck [41]byte
	pck[0] = byte(noxnet.MSG_USE_MAP)
	copy(pck[1:33], mname)
	binary.LittleEndian.PutUint32(pck[33:], crc)
	binary.LittleEndian.PutUint32(pck[37:], noxServer.Frame())

	for pl := noxServer.PlayerFirst(); pl != nil; pl = noxServer.PlayerNext(pl) {
		u := pl.UnitC()
		if u == nil {
			continue
		}
		netlist.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, pck[:41])
		legacy.Nox_xxx_netPlayerObjSend_518C30(u.SObj(), u.SObj(), 0, 0)
		if !noxflags.HasGame(noxflags.GameClient) || pl.PlayerIndex() != common.MaxPlayers-1 {
			buf := netlist.CopyPacketsA(pl.PlayerIndex(), netlist.Kind1)
			if len(buf) != 0 {
				netstr.Global.ByPlayer(pl).Send(buf, netstr.SendQueue|netstr.SendFlush)
			}
		}
	}
}

func (s *Server) onPacket(ind ntype.PlayerInd, data []byte) bool {
	cdata, cfree := alloc.Make([]byte{}, len(data))
	defer cfree()
	return s.onPacketRaw(ind, cdata)
}

func (s *Server) onPacketRaw(pli ntype.PlayerInd, data []byte) bool {
	pl := s.GetPlayerByInd(pli)
	if len(data) == 0 {
		if pl != nil {
			pl.Frame3596 = s.Frame()
		}
		return true
	}
	if noxflags.HasEngine(noxflags.EngineReplayWrite) {
		s.nox_xxx_replayWriteMSgMB(pl, data)
	}
	op := noxnet.Op(data[0])
	switch op {
	case 0x20:
		if s.newPlayerFromPacket(pli, data[1:]) == 0 {
			netstr.Global.ReadPackets(netstr.Global.ByPlayerInd(pli))
		}
		return true
	case 0x22:
		legacy.Nox_xxx_playerForceDisconnect_4DE7C0(pli)
		return true
	case 0x25:
		if pl != nil {
			pl.Frame3596 = s.Frame()
		}
		return true
	}
	if pl == nil {
		return true
	}
	u := pl.UnitC()
	if u == nil {
		return true
	}
	for len(data) > 0 {
		op = noxnet.Op(data[0])
		n, ok := s.onPacketOp(pli, op, data, pl, u)
		if !ok {
			netstr.Log.Printf("SERVER: ERR: op=%d (%s) [%d:???]\n%02x %x", int(op), op.String(), op.Len(), data[0], data[1:])
			return false
		}
		if netstr.Global.Debug && n != 0 {
			netstr.Log.Printf("SERVER: op=%d (%s) [%d:%d]\n%02x %x", int(op), op.String(), int(n)-1, op.Len(), data[0], data[1:])
		}
		if n > len(data) {
			panic(fmt.Errorf("incorrect length returned for op: %v", op))
		}
		data = data[n:]
	}
	pl.Frame3596 = s.Frame()
	return true
}

func (s *Server) onPacketOp(pli ntype.PlayerInd, op noxnet.Op, data []byte, pl *Player, u *Object) (int, bool) {
	if n, ok, err := s.Server.OnPacketOpSub(pli, op, data, pl.S(), u.SObj()); err != nil {
		return n, false
	} else if ok {
		return n, true
	}
	switch op {
	case noxnet.MSG_NEED_TIMESTAMP:
		legacy.Nox_xxx_netNeedTimestampStatus_4174F0(pl.S(), 64)
		return 1, true
	case noxnet.MSG_TRY_ABILITY:
		if len(data) < 2 {
			return 0, false
		}
		if !noxflags.HasGame(noxflags.GameModeChat) && pl.Field3680&0x3 == 0 {
			s.abilities.Do(u.SObj(), server.Ability(data[1]))
		}
		return 2, true
	case noxnet.MSG_CLIENT_READY:
		legacy.Nox_xxx_gameServerReadyMB_4DD180(pl.Index())
		return 1, true
	case noxnet.MSG_SERVER_QUIT_ACK:
		serverQuitAck()
		return 1, true
	case noxnet.MSG_INCOMING_CLIENT:
		legacy.Nox_xxx_netPlayerIncomingServ_4DDF60(pl.Index())
		return 1, true
	case noxnet.MSG_OUTGOING_CLIENT:
		nox_xxx_playerDisconnFinish_4DE530(pl.PlayerIndex(), 2)
		return 1, true
	case noxnet.MSG_REQUEST_TIMER_STATUS:
		v41 := legacy.Sub_40A220()
		nox_xxx_netTimerStatus_4D8F50(pli, v41)
		return 1, true
	case noxnet.MSG_CANCEL_MAP:
		s.mapSend.mapSendCancel(pl.PlayerIndex())
		return 1, true
	case noxnet.MSG_RECEIVED_MAP:
		pl.Field3676 = 3
		s.mapSend.EndReceive(pl.PlayerIndex())
		return 1, true
	case noxnet.MSG_TEXT_MESSAGE:
		if len(data) < 11 {
			return 0, false
		}
		sz := int(data[8])
		flags := data[3]
		rtext := data[11:]
		var text string
		if flags&0x2 != 0 { // ASCII or UTF-8
			sz *= 1
			if sz > len(rtext) {
				return 0, false
			}
			rtext = rtext[:sz]
			text = alloc.GoStringS(rtext)
		} else { // UTF-16
			sz *= 2
			if sz > len(rtext) {
				return 0, false
			}
			rtext = rtext[:sz]
			text = alloc.GoString16B(rtext)
		}
		msz := 11 + sz
		if pl != nil && (pl.Field3680>>2)&0x1 != 0 {
			return msz, true
		}
		orig := text
		if flags&0x1 == 0 { // global chat
			text = s.callOnChat(nil, pl.S(), pl.UnitC().SObj(), text)
			if text == "" {
				return msz, true // mute
			}
			if text != orig {
				// FIXME: rebuild the packet and replace the message
			}
			for it := s.PlayerFirst(); it != nil; it = s.PlayerNext(it) {
				if noxflags.HasGame(noxflags.GameClient) && it.Index() == common.MaxPlayers-1 {
					noxClient.nox_xxx_netOnPacketRecvCli48EA70(common.MaxPlayers-1, data[:msz])
				} else {
					conn := netstr.Global.ByPlayer(it)
					conn.Send(data[:msz], 0)
					conn.SendReadPacket(true)
				}
			}
			return msz, true
		}
		// team message
		netcode := int(binary.LittleEndian.Uint16(data[1:]))
		tm := nox_xxx_objGetTeamByNetCode_418C80(netcode)
		if tm == nil || !tm.Has() {
			return msz, true
		}
		tcl := s.Teams.ByID(tm.ID)
		if tcl == nil {
			return msz, true
		}
		text = s.callOnChat(tcl, pl.S(), pl.UnitC().SObj(), text)
		if text == "" {
			return msz, true // mute
		}
		if text != orig {
			// FIXME: rebuild the packet and replace the message
		}
		for it := s.PlayerFirst(); it != nil; it = s.PlayerNext(it) {
			uit := it.UnitC()
			if uit == nil {
				continue
			}
			if legacy.Nox_xxx_teamCompare2_419180(uit.TeamPtr(), tcl.ID()) != 0 {
				if noxflags.HasGame(noxflags.GameClient) && int(uit.NetCode) == legacy.ClientPlayerNetCode() {
					noxClient.nox_xxx_netOnPacketRecvCli48EA70(it.PlayerIndex(), data[:msz])
				} else {
					conn := netstr.Global.ByPlayer(it)
					conn.Send(data[:msz], 0)
					conn.SendReadPacket(true)
				}
			}
		}
		return msz, true
	case noxnet.MSG_SYSOP_PW:
		if len(data) < 21 {
			return 0, false
		}
		var buf [2]byte
		buf[0] = byte(noxnet.MSG_SYSOP_RESULT)
		pass := legacy.Nox_xxx_sysopGetPass_40A630()
		got := alloc.GoString16B(data[1:])
		if pass == "" || pass != got {
			buf[1] = 0
		} else {
			buf[1] = 1
			if legacy.Sub_4D12A0(pl.Index()) == 0 {
				legacy.Sub_4D1210(pl.Index())
				str := s.Strings().GetStringInFile("sysopAccessGranted", "sdecode.c")
				s.Printf(console.ColorRed, str, pl.Name())
			}
		}
		s.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:2], 0, 1)
		return 1 + 20, true
	case noxnet.MSG_SERVER_CMD:
		if len(data) < 7 {
			return 0, false
		}
		sz := int(data[4])
		wtext := data[5:]
		if len(wtext) < 2*sz {
			return 0, false
		}
		wtext = wtext[:2*sz]
		nox_xxx_serverHandleClientConsole_443E90(pl, data[1], alloc.GoString16B(wtext))
		return 5 + 2*sz, true
	case noxnet.MSG_IMPORTANT_ACK:
		if len(data) < 5 {
			return 0, false
		}
		id := binary.LittleEndian.Uint32(data[1:])
		legacy.Nox_net_importantACK_4E55A0(pl.Index(), int(id))
		return 5, true
	case noxnet.MSG_REQUEST_MAP:
		pl.GoObserver(true, true)
		if u != nil {
			legacy.Nox_xxx_netChangeTeamMb_419570(u.TeamPtr(), uint32(pl.NetCode()))
		}
		s.mapSend.StartSendShared(pl.PlayerIndex())
		return 1, true
	case noxnet.MSG_REQUEST_SAVE_PLAYER:
		if len(data) < 3 {
			return 0, false
		}
		if noxflags.HasGame(noxflags.GameModeQuest) && pl.Index() != common.MaxPlayers-1 && pl.IsActive() && u != nil && u.UpdateDataPlayer().Field138 == 1 {
			pl.Disconnect(2)
		} else {
			fname := datapath.Save(common.SaveDir, "_temp_.dat")
			defer ifs.Remove(fname)
			if savePlayerData(fname, pl.PlayerIndex()) {
				sub41CFA0(fname, pl.PlayerIndex())
			}
		}
		return 3, true
	case noxnet.MSG_TEAM_MSG:
		if len(data) < 10 {
			return 0, false
		}
		switch data[1] {
		case 10:
			ti := server.TeamID(binary.LittleEndian.Uint32(data[2:]))
			tm := s.Teams.ByID(ti)
			if tm == nil {
				return 10, true
			}
			netcode := int(binary.LittleEndian.Uint16(data[6:]))
			obj := s.getObjectFromNetCode(netcode)
			legacy.Nox_xxx_createAtImpl_4191D0(tm.ID(), obj.TeamPtr(), 1, uint32(netcode), 1)
			return 10, true
		case 11:
			netcode := int(binary.LittleEndian.Uint16(data[6:]))
			u2 := s.getObjectFromNetCode(netcode)
			if u2 == nil {
				return 10, true
			}
			if !noxflags.HasGame(noxflags.GameModeChat) {
				pos := s.nox_xxx_mapFindPlayerStart_4F7AB0(u2)
				u2.SetPos(pos)
			}
			ti := server.TeamID(binary.LittleEndian.Uint32(data[2:]))
			tm := s.Teams.ByID(ti)
			if tm == nil {
				return 10, true
			}
			legacy.Sub_4196D0(unsafe.Pointer(u2.TeamPtr()), tm.C(), netcode, 1)
			return 10, true
		default:
			return 0, false
		}
	case noxnet.MSG_SOCIAL:
		if len(data) < 2 {
			return 0, false
		}
		switch data[1] {
		case 1:
			nox_xxx_playerSetState_4FA020(u, 26)
		case 2:
			nox_xxx_playerSetState_4FA020(u, 25)
		case 4:
			nox_xxx_playerSetState_4FA020(u, 27)
		}
		return 2, true
	case noxnet.MSG_DIALOG:
		if len(data) < 2 {
			return 0, false
		}
		typ := data[1]
		switch typ {
		case 1:
			if len(data) < 4 {
				return 0, false
			}
			if nox_xxx_gameGet_4DB1B0() {
				return 4, true
			}
			if pl.Field3680&0x3 != 0 {
				return 4, true
			}
			id := binary.LittleEndian.Uint16(data[2:])
			if obj := legacy.Nox_server_getObjectFromNetCode_4ECCB0(int(id)); obj != nil {
				nox_xxx_script_forcedialog_548CD0(u.SObj(), obj)
			}
			return 4, true
		case 2:
			if len(data) < 3 {
				return 0, false
			}
			legacy.Nox_xxx_scriptDialog_548D30(u.SObj(), data[2])
			return 3, true
		}
		return 0, false
	case noxnet.MSG_XFER_MSG:
		if len(data) < 2 {
			return 0, false
		}
		typ := data[1]
		switch typ {
		case 0:
			if len(data) < 140 {
				return 0, false
			}
			a2 := data[2]
			a3 := binary.LittleEndian.Uint32(data[4:])
			styp := alloc.GoStringS(data[8:136])
			a4 := data[136]
			sub_40B5D0(netstr.Global.ByPlayer(pl), a2, styp, a3, a4)
			return 140, true
		case 1:
			if len(data) < 4 {
				return 0, false
			}
			a2 := data[2]
			a3 := data[3]
			sub_40BFF0(netstr.Global.ByPlayer(pl), a2, a3)
			return 4, true
		case 2:
			if len(data) < 8 {
				return 0, false
			}
			a2 := data[2]
			a3 := binary.LittleEndian.Uint16(data[4:])
			sz := int(binary.LittleEndian.Uint16(data[6:]))
			if len(data) < 8+sz {
				return 0, false
			}
			var buf [6]byte
			buf[0] = byte(noxnet.MSG_XFER_MSG)
			buf[1] = 3
			buf[2] = a2
			binary.LittleEndian.PutUint16(buf[4:], a3)
			netstr.Global.ByPlayer(pl).Send(buf[:6], netstr.SendQueue|netstr.SendFlush)
			sub_40B250(netstr.Global.ByPlayer(pl), a2, a3, data[8:8+sz])
			return 8 + sz, true
		case 3:
			if len(data) < 6 {
				return 0, false
			}
			a2 := data[2]
			a3 := binary.LittleEndian.Uint16(data[4:])
			sub_40BF60(netstr.Global.ByPlayer(pl), a2, a3)
			return 6, true
		case 4:
			if len(data) < 3 {
				return 0, false
			}
			a2 := data[2]
			sub_40C030(netstr.Global.ByPlayer(pl), a2)
			return 3, true
		case 5:
			if len(data) < 4 {
				return 0, false
			}
			a2 := data[2]
			a3 := data[3]
			sub_40B720(a3, a2)
			return 4, true
		case 6:
			if len(data) < 4 {
				return 0, false
			}
			a2 := data[2]
			a3 := data[3]
			sub_40C070(netstr.Global.ByPlayer(pl), a3, a2)
			return 4, true
		}
		return 0, false
	default:
		res := legacy.Nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_switch(pli, data, pl.S(), u.SObj(), u.UpdateData)
		if res <= 0 || res > len(data) {
			return 0, false
		}
		return res, true
	}
}

func nox_xxx_netTimerStatus_4D8F50(a1 ntype.PlayerInd, a2 int) {
	var buf [13]byte

	buf[0] = byte(noxnet.MSG_TIMER_STATUS)
	binary.LittleEndian.PutUint32(buf[1:], uint32(a2))
	binary.LittleEndian.PutUint32(buf[5:], uint32(legacy.Sub_40A230()))
	binary.LittleEndian.PutUint32(buf[9:], noxServer.Frame())
	noxServer.nox_xxx_netSendPacket1_4E5390(int(a1), buf[:13], 0, 1)
}

func netSendAudioEvent(u *Object, ev *server.AudioEvent, perc int16) {
	pl := u.ControllingPlayer()
	packed := uint16(uint32(uint16(ev.Sound)) | uint32(perc)<<10)
	dx := ev.Pos.X - pl.Pos3632().X
	mv := uint8(int8(50 * int(dx) / (videoGetWindowSize().X / 2)))
	var buf [4]byte
	if u.SObj() == ev.Obj {
		buf[0] = byte(noxnet.MSG_AUDIO_PLAYER_EVENT)
	} else {
		buf[0] = byte(noxnet.MSG_AUDIO_EVENT)
	}
	buf[1] = mv
	binary.LittleEndian.PutUint16(buf[2:], packed)
	netlist.AddToMsgListCli(pl.PlayerIndex(), netlist.Kind1, buf[:4])
}

func (s *Server) nox_xxx_netObjectOutOfSight_528A60(ind int, obj *server.Object) int {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_OBJECT_OUT_OF_SIGHT)
	binary.LittleEndian.PutUint16(buf[1:], uint16(s.GetUnitNetCode(obj)))
	return s.nox_xxx_netSendPacket0_4E5420(ind, buf[:3], 0, 1)
}

func (s *Server) nox_xxx_netObjectInShadows_528A90(ind int, obj *Object) int {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_OBJECT_IN_SHADOWS)
	binary.LittleEndian.PutUint16(buf[1:], uint16(s.GetUnitNetCode(obj)))
	return s.nox_xxx_netSendPacket0_4E5420(ind, buf[:3], 0, 1)
}

func (s *Server) nox_xxx_netPlayerObjSendCamera_519330(u *Object) bool {
	ud := u.UpdateDataPlayer()
	pl := asPlayerS(ud.Player)
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
	buf[1] = 2 // XFER_BLOCK?
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
	Kind4     byte          // 1, 4
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
	Field4   byte          // 1, 4
	Field5   byte          // 1, 5
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
	p.Kind4 = 0
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
							sub_40BB20(it.NetInd0, it.Kind4, 2)
							break
						}
					} else {
						sub_40BA90(it.NetInd0, it.Kind4, it2.Ind0, it2.Data4)
						it2.Frame12 = s.Frame()
						it2.Cnt16++
					}
				}
			} else {
				sub_40BA90(it.NetInd0, it.Kind4, it2.Ind0, it2.Data4)
				it.Cnt12++
				it2.Frame12 = s.Frame()
			}
		}
	}
}

func sub_40BC10(ind netstr.Handle, a2 byte) *xferData {
	for i := 0; i < xferDataCnt; i++ {
		it := &xferDataArr[i]
		if it.NetInd0 == ind && it.Kind4 == a2 {
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

func sub_40BFF0(a1 netstr.Handle, a2 byte, i byte) {
	if int(i) >= xferDataCnt {
		return
	}
	p := &xferDataArr[i]
	p.Kind4 = a2
	p.Kind6 = 2
}

func sub_40C0D0() {
	alloc.FreeSlice(xferDataArr)
}

func sub_40C0E0(ind netstr.Handle) {
	for i := 0; i < xferDataCnt; i++ {
		it := &xferDataArr[i]
		if it.Blocks16 == 2 && it.NetInd0 == ind {
			sub_40BB20(it.NetInd0, it.Kind4, 1)
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
	buf[1] = 5
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
		if pli == common.MaxPlayers-1 {
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
	p.Kind4 = 0
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

func nox_xxx_netXferMsg_40BE80(conn netstr.Handle, a2 byte, typ string, sz int, a5 byte) {
	var buf [140]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 0 // XFER_HEADER?
	buf[2] = a2
	binary.LittleEndian.PutUint32(buf[4:], uint32(sz))
	n := copy(buf[8:136], typ)
	buf[8+n] = 0
	buf[136] = a5
	conn.Send(buf[:140], netstr.SendQueue|netstr.SendFlush)
}

func sub_40C030(ind netstr.Handle, a2 byte) {
	p := sub_40BC10(ind, a2)
	if p == nil {
		return
	}
	sub_40B850(ind, p.Field22)
	xferDataActive--
	sub_40B930(p)
}

func sub_40C070(ind netstr.Handle, a2 byte, a3 byte) {
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

func sub_40BF60(ind netstr.Handle, a2 byte, a3 uint16) {
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

func sub_40B5D0(a1 netstr.Handle, a2 byte, typ string, sz uint32, a5 byte) {
	s := noxServer
	if sz == 0 {
		return
	}
	p, v9 := sub_40B6D0()
	if p == nil {
		return
	}
	p.NetInd0 = a1
	p.Field4 = a2
	if typ != "" {
		p.Type24 = typ
	}
	p.Field5 = v9
	p.Data20 = make([]byte, sz)
	p.Frame156 = s.Frame()
	dword_5d4594_3628++
	sub_40B690(a1, v9, a5)
}

func sub_40B1F0(i byte) {
	p := &dword_5d4594_3620[i]
	p.Field4 = 0
	p.Field5 = i
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
		nox_xxx_neXfer_40B590(p.NetInd0, p.Field5, a2)
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
	buf[1] = 6
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

func sub_40B250(ind netstr.Handle, a2 byte, a3 uint16, data []byte) {
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
		nox_xxx_netXfer_40B4B0(p.NetInd0, p.Field5)
		nox_xxx_soloGameEscMenuCallback_40AF90(ind.Player(), p.Field5, p.Field4, p.Type24, p.Data20)
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
	buf[1] = 4
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

func sub_40B690(conn netstr.Handle, a2 byte, a3 byte) {
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 1
	buf[2] = a2
	buf[3] = a3
	conn.Send(buf[:4], netstr.SendQueue|netstr.SendFlush)
}

func sub_40B720(a1 byte, a2 byte) {
	sub_40B4E0(a2)
	sub_40B1F0(a2)
}
