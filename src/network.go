package opennox

import (
	"context"
	"encoding/binary"
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
	"github.com/noxworld-dev/opennox/v1/common/serial"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	configBoolPtr("network.xor", "NOX_NET_XOR", true, &netstr.Xor)
	configHiddenBoolPtr("debug.network", "NOX_DEBUG_NET", &netstr.Debug)
	netstr.GameFrame = func() uint32 {
		return noxServer.Frame()
	}
	netstr.OnDiscover = nox_xxx_servNetInitialPackets_552A80_discover
	netstr.OnExtPacket = MixRecvFromReplacer
	netstr.GetMaxPlayers = func() int {
		return noxServer.getServerMaxPlayers()
	}
	netstr.KeyRand = func(min, max int) int {
		return noxRndCounter1.IntClamp(min, max)
	}
	netstr.PacketDropRand = func(min, max int) int {
		return randomIntMinMax(min, max)
	}
}

var (
	netstrClientIndex    netstr.Index
	lastCliHandlePackets uint64
	ticks815732          uint64
	dword_5d4594_815704  bool
	dword_5d4594_815708  bool
	dword_973f18_44216   string
	dword_5d4594_3843632 netip.Addr
)

var (
	noxMapCRC     = 0
	noxServerHost = "localhost"
)

func networkLogPrint(str string) {
	if !noxflags.HasGame(noxflags.GameFlag3) {
		return
	}
	netstr.Log.Println(str)
	noxConsole.Print(console.ColorGreen, str)
}

func netstrGetClientIndex() int { return int(netstrClientIndex) }

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

func nox_xxx_getMapCRC_40A370() int {
	return noxMapCRC
}

func nox_xxx_setMapCRC_40A360(crc int) {
	if netstr.Debug {
		netstr.Log.Printf("map crc set: %d", crc)
	}
	noxMapCRC = crc
}

func noxOnCliPacketDebug(op noxnet.Op, buf []byte) {
	if netstr.Debug && len(buf) != 0 {
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

func (c *Client) clientSendInput(pli int) bool {
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

func (c *Client) clientSendInputMouse(pli int, mp image.Point) bool {
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

func (s *Server) nox_xxx_netAddPlayerHandler_4DEBC0(port int) (ind netstr.Index, cport int, _ error) {
	narg := &netstr.Options{
		Port:     port,
		Max:      s.getServerMaxPlayers(),
		DataSize: 2048,
		Func2: func(ind netstr.Index, buf []byte, _ unsafe.Pointer) int {
			// should pass the pointer unchanged, otherwise expect bugs!
			s.onPacketRaw(int(ind)-1, buf)
			return 1
		},
		Func1:   nox_xxx_netFn_UpdateStream_4DF630,
		Check14: nox_xxx_netBigSwitch_553210_op_14_check,
		Check17: nox_xxx_netBigSwitch_553210_op_17_check,
	}
	nox_xxx_allocNetGQueue_5520B0()
	ind, err := nox_xxx_netInit_554380(narg)
	if err != nil {
		return ind, 0, err
	}
	return ind, narg.Port, err
}

var netSomePort uint16

func sub_5545A0() uint16 {
	return netSomePort
}

func sub_554230() string {
	return dword_973f18_44216
}

func nox_xxx_netInit_554380(narg *netstr.Options) (ind netstr.Index, _ error) {
	dword_973f18_44216 = ""
	v2, err := netstr.InitNew(narg)
	netSomePort = uint16(narg.Port)
	if err != nil {
		return v2, err
	}
	if ip, err := nat.ExternalIP(context.Background()); err == nil {
		dword_5d4594_3843632, _ = netip.AddrFromSlice(ip.To4())
		dword_973f18_44216 = ip.String()
	} else if ips, err := nat.InternalIPs(context.Background()); err == nil && len(ips) != 0 {
		ip = ips[0].IP
		dword_5d4594_3843632, _ = netip.AddrFromSlice(ip.To4())
		dword_973f18_44216 = ip.String()
	}
	return v2, nil
}

func (s *Server) nox_server_netClose_5546A0(i netstr.Index) {
	netstr.CloseByInd(i)
}

func (s *Server) nox_xxx_netStructReadPackets2_4DEC50(ind int) int {
	return netstr.ReadPackets(netstr.Index(ind + 1))
}

func nox_xxx_netSendSock_552640(id netstr.Index, ptr *byte, sz int, flags int) int {
	n, _ := netstr.Send(id, unsafe.Slice(ptr, sz), flags)
	return n
}

func nox_xxx_netSendClientReady_43C9F0() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_CLIENT_READY)
	netstr.Send(netstrClientIndex, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	return 1
}

func nox_xxx_netKeepAliveSocket_43CA20() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_KEEP_ALIVE)
	netstr.Send(netstrClientIndex, data[:], netstr.SendFlagFlush)
	return 1
}

func nox_xxx_netRequestMap_43CA50() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_REQUEST_MAP)
	netstr.Send(netstrClientIndex, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	return 1
}

func nox_xxx_netMapReceived_43CA80() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_RECEIVED_MAP)
	netstr.Send(netstrClientIndex, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	return 1
}

func nox_xxx_cliSendCancelMap_43CAB0() int {
	id := netstrClientIndex
	var data [1]byte
	data[0] = byte(noxnet.MSG_CANCEL_MAP)
	v0, _ := netstr.Send(id, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	if netstr.WaitServerResponse(id, v0, 20, 6) != 0 {
		return 0
	}
	netlist.ResetByInd(common.MaxPlayers-1, netlist.Kind0)
	return 1
}

func nox_xxx_netSendIncomingClient_43CB00() int {
	id := netstrClientIndex
	var data [1]byte
	data[0] = byte(noxnet.MSG_INCOMING_CLIENT)
	v0, _ := netstr.Send(id, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	if netstr.WaitServerResponse(id, v0, 20, 6) != 0 {
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
	id := netstrClientIndex
	var data [1]byte
	data[0] = byte(noxnet.MSG_OUTGOING_CLIENT)
	v0, _ := netstr.Send(id, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	if netstr.WaitServerResponse(id, v0, 20, 6) != 0 {
		return 0
	}
	netstr.ServeInitialPackets(id, 3)
	netlist.ResetByInd(common.MaxPlayers-1, netlist.Kind0)
	return 1
}

func nox_xxx_netInformTextMsg_4DA0F0(pid int, code byte, ind int) bool {
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
		netlist.AddToMsgListCli(pl.Index(), netlist.Kind1, buf[:3])
	}
}

func netSendGauntlet() {
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_GAUNTLET)
	buf[1] = 27
	nox_xxx_netClientSend2_4E53C0(common.MaxPlayers-1, buf[:2], 0, 0)
}

func nox_xxx_sendGauntlet_4DCF80(ind int, v byte) {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_GAUNTLET)
	buf[1] = 28
	buf[2] = v
	noxServer.nox_xxx_netSendPacket1_4E5390(ind, buf[:3], 0, 0)
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
	netlist.AddToMsgListCli(u.ControllingPlayer().Index(), netlist.Kind1, buf[:n+4])
}

func nox_xxx_netSendBySock_40EE10(nind netstr.Index, ind int, kind netlist.Kind) {
	netlist.HandlePacketsA(ind, kind, func(data []byte) {
		if len(data) == 0 {
			return
		}
		netstr.Send(nind, data, 0)
		netstr.SendReadPacket(nind, 1)
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

func nox_xxx_netBigSwitch_553210_op_14_check(out []byte, packet []byte, a4a bool, add func(pid netstr.Index) bool) int {
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
			if add(netstr.Index(it.Index()) + 1) {
				found = pit
				return false
			}
			return true // continue
		})
		if found != nil {
			s.GetPlayerByInd(found.Index()).Disconnect(4)
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

func sub_554240(a1 int) int {
	if a1 != 31 {
		return netstr.GetTimingByInd1(a1)
	}
	return int(nox_ctrlevent_add_ticks_42E630())
}

func sub_43CC80() {
	netstr.SendClose(netstrClientIndex)
	legacy.Set_dword_5d4594_2649712(0)
}

func nox_xxx_netSendReadPacket_5528B0(ind netstr.Index, a2 byte) int {
	return netstr.SendReadPacket(ind, a2)
}

func sub_5521A0() bool {
	v13 := sub_416640()
	netstr.ProcessStats(int(*(*int16)(unsafe.Pointer(&v13[105]))), int(*(*int16)(unsafe.Pointer(&v13[107]))))
	return true
}

func nox_xxx_allocNetGQueue_5520B0() {
	noxClient.SetUpdateFunc2(sub_5521A0)
	netstr.Init()
}

func nox_xxx_net_getIP_554200(a1 netstr.Index) uint32 {
	return ip2int(netGetIP(a1))
}

func netGetIP(ind netstr.Index) netip.Addr {
	if ind == 0 {
		return dword_5d4594_3843632
	}
	return netstr.GetIPByInd(ind)
}

func sub_519930(a1 int) int {
	cnt := 0
	v2 := netstr.Index(memmap.Uint32(0x5D4594, 2387148+48*uintptr(a1)))
	if v2 != 0 {
		if a1 < 32 {
			for it := netstr.QueueFirst(v2); it != nil; it = netstr.QueueNext(v2) {
				if op := noxnet.Op(it[0]); op == noxnet.MSG_MAP_SEND_START || op == noxnet.MSG_MAP_SEND_PACKET {
					cnt++
				}
			}
		}
	}
	return cnt
}

func sub_43C790() uint32 {
	return memmap.Uint32(0x587000, 91876)
}

func nox_xxx_netOnPacketRecvCli_48EA70(ind int, buf *byte, sz int) int {
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

func (c *Client) nox_xxx_netOnPacketRecvCli48EA70_switch(ind int, op noxnet.Op, data []byte, v364 *uint32, v373 *uint16) int {
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
			return 1
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
			return 1
		}
		if c.srv.Frame() > prevFrame+1 {
			noxPerfmon.latePackets += int(c.srv.Frame() - prevFrame)
		}
		legacy.Sub_43C650()
		return 3
	case noxnet.MSG_USE_MAP:
		if len(data) < 41 {
			return -1
		}
		if v1 := binary.LittleEndian.Uint32(data[37:]); v1 > uint32(legacy.Get_dword_5d4594_1200804()) {
			nox_xxx_setMapCRC_40A360(int(v1))
			legacy.Nox_xxx_gameClearAll_467DF0(1)
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
			if tobj != nil && server.Nox_xxx_servObjectHasTeam_419130(tobj) {
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
		c.mapsend.onMapDownloadStart(alloc.GoStringS(data[8:88]), uint(sz))
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
	}
	return legacy.Nox_xxx_netOnPacketRecvCli_48EA70_switch(ind, op, data)
}

func (c *Client) nox_xxx_netOnPacketRecvCli48EA70(ind int, data []byte) int {
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
		noxOnCliPacketDebug(op, data[:n])
		data = data[n:]
	}
	return 1
}

func sub_43C6E0() int {
	return bool2int(!dword_5d4594_815704 && !dword_5d4594_815708)
}

func nox_xxx_netHandleCliPacket_43C860(_ netstr.Index, data []byte, _ unsafe.Pointer) int {
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

func (s *Server) nox_xxx_netSendBySock_4DDDC0(ind int) {
	if !noxflags.HasGame(noxflags.GameClient) || ind != common.MaxPlayers-1 {
		netlist.HandlePacketsA(ind, netlist.Kind1, func(data []byte) {
			if len(data) == 0 {
				return
			}
			netstr.Send(netstr.Index(ind+1), data, netstr.SendNoLock|netstr.SendFlagFlush)
		})
	}
}

func (s *Server) sendSettings(u *Object) {
	pl := u.ControllingPlayer()
	{
		var buf [5]byte
		buf[0] = byte(noxnet.MSG_FULL_TIMESTAMP)
		binary.LittleEndian.PutUint32(buf[1:], s.Frame())
		netlist.AddToMsgListCli(pl.Index(), netlist.Kind1, buf[:5])
	}
	{
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_JOIN_DATA)
		binary.LittleEndian.PutUint16(buf[1:], uint16(s.GetUnitNetCode(u)))
		binary.LittleEndian.PutUint32(buf[3:], uint32(pl.Field2068))
		netlist.AddToMsgListCli(pl.Index(), netlist.Kind1, buf[:7])
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
		netlist.AddToMsgListCli(pl.Index(), netlist.Kind1, buf[:20])
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
		netlist.AddToMsgListCli(pl.Index(), netlist.Kind1, buf[:49])
	}
	{
		var buf [129]byte
		nox_xxx_netNewPlayerMakePacket_4DDA90(buf[:], pl)
		netlist.AddToMsgListCli(pl.Index(), netlist.Kind1, buf[:129])
		s.nox_xxx_netSendBySock_4DDDC0(pl.Index())
	}
	{
		var buf [41]byte
		buf[0] = byte(noxnet.MSG_USE_MAP)
		copy(buf[1:33], s.nox_server_currentMapGetFilename_409B30())
		buf[32] = 0
		binary.LittleEndian.PutUint32(buf[33:], nox_xxx_mapCrcGetMB_409B00())
		binary.LittleEndian.PutUint32(buf[37:], s.Frame())
		netstr.Send(netstr.Index(pl.Index()+1), buf[:41], netstr.SendNoLock|netstr.SendFlagFlush)
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
		netlist.AddToMsgListCli(pl.Index(), netlist.Kind1, pck[:41])
		legacy.Nox_xxx_netPlayerObjSend_518C30(u.SObj(), u.SObj(), 0, 0)
		if !noxflags.HasGame(noxflags.GameClient) || pl.Index() != common.MaxPlayers-1 {
			buf := netlist.CopyPacketsA(pl.Index(), netlist.Kind1)
			if len(buf) != 0 {
				netstr.Send(netstr.Index(pl.Index()+1), buf, netstr.SendNoLock|netstr.SendFlagFlush)
			}
		}
	}
}

func (s *Server) onPacket(ind int, data []byte) bool {
	cdata, cfree := alloc.Make([]byte{}, len(data))
	defer cfree()
	return s.onPacketRaw(ind, cdata)
}

func (s *Server) onPacketRaw(pli int, data []byte) bool {
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
			netstr.ReadPackets(netstr.Index(pli + 1))
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
		if netstr.Debug && n != 0 {
			netstr.Log.Printf("SERVER: op=%d (%s) [%d:%d]\n%02x %x", int(op), op.String(), int(n)-1, op.Len(), data[0], data[1:])
		}
		data = data[n:]
	}
	pl.Frame3596 = s.Frame()
	return true
}

func (s *Server) onPacketOp(pli int, op noxnet.Op, data []byte, pl *Player, u *Object) (int, bool) {
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
			s.abilities.Do(u, server.Ability(data[1]))
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
		legacy.Nox_xxx_playerDisconnFinish_4DE530(pl.Index(), 2)
		return 1, true
	case noxnet.MSG_REQUEST_TIMER_STATUS:
		v41 := legacy.Sub_40A220()
		nox_xxx_netTimerStatus_4D8F50(pli, v41)
		return 1, true
	case noxnet.MSG_CANCEL_MAP:
		legacy.Nox_xxx_netMapSendCancelMap_519DE0_net_mapsend(pl.Index())
		return 1, true
	case noxnet.MSG_RECEIVED_MAP:
		pl.Field3676 = 3
		legacy.Sub_519E80(pl.Index())
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
		_ = text
		msz := 11 + sz
		if pl != nil && (pl.Field3680>>2)&0x1 != 0 {
			return msz, true
		}
		if flags&0x1 == 0 { // global chat
			for it := s.PlayerFirst(); it != nil; it = s.PlayerNext(it) {
				if noxflags.HasGame(noxflags.GameClient) && it.Index() == common.MaxPlayers-1 {
					noxClient.nox_xxx_netOnPacketRecvCli48EA70(common.MaxPlayers-1, data[:msz])
				} else {
					netstr.Send(netstr.Index(it.Index()+1), data[:msz], 0)
					netstr.SendReadPacket(netstr.Index(it.Index()+1), 1)
				}
			}
			return msz, true
		}
		// team message
		netcode := int(binary.LittleEndian.Uint16(data[1:]))
		tm := nox_xxx_objGetTeamByNetCode_418C80(netcode)
		if tm == nil || !server.Nox_xxx_servObjectHasTeam_419130(tm) {
			return msz, true
		}
		tcl := s.Teams.ByYyy(tm.Field1)
		if tcl == nil {
			return msz, true
		}
		for it := s.PlayerFirst(); it != nil; it = s.PlayerNext(it) {
			uit := it.UnitC()
			if uit == nil {
				continue
			}
			if legacy.Nox_xxx_teamCompare2_419180(unsafe.Pointer(uit.TeamPtr()), tcl.Ind57()) != 0 {
				if noxflags.HasGame(noxflags.GameClient) && int(uit.NetCode) == legacy.ClientPlayerNetCode() {
					noxClient.nox_xxx_netOnPacketRecvCli48EA70(it.Index(), data[:msz])
				} else {
					netstr.Send(netstr.Index(it.Index()+1), data[:msz], 0)
					netstr.SendReadPacket(netstr.Index(it.Index()+1), 1)
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
		return 5 + 2*sz + 2, true
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
		legacy.Nox_xxx_netMapSend_519D20(pl.Index())
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
			if nox_xxx_playerSaveToFile_41A140(fname, pl.Index()) {
				sub41CFA0(fname, pl.Index())
			}
		}
		return 3, true
	case noxnet.MSG_TEAM_MSG:
		if len(data) < 10 {
			return 0, false
		}
		switch data[1] {
		case 10:
			ti := int(binary.LittleEndian.Uint32(data[2:]))
			tm := s.Teams.ByYyy(byte(ti))
			if tm == nil {
				return 10, true
			}
			netcode := int(binary.LittleEndian.Uint16(data[6:]))
			obj := s.getObjectFromNetCode(netcode)
			legacy.Nox_xxx_createAtImpl_4191D0(tm.Ind57(), obj.TeamPtr(), 1, uint32(netcode), 1)
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
			ti := int(binary.LittleEndian.Uint32(data[2:]))
			tm := s.Teams.ByYyy(byte(ti))
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
			if nox_xxx_gameGet_4DB1B0() != 0 {
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
	default:
		res := legacy.Nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_switch(pli, data, pl.S(), u.SObj(), u.UpdateData)
		if res <= 0 || res > len(data) {
			return 0, false
		}
		return res, true
	}
}

func nox_xxx_netTimerStatus_4D8F50(a1, a2 int) {
	var buf [13]byte

	buf[0] = byte(noxnet.MSG_TIMER_STATUS)
	binary.LittleEndian.PutUint32(buf[1:], uint32(a2))
	binary.LittleEndian.PutUint32(buf[5:], uint32(legacy.Sub_40A230()))
	binary.LittleEndian.PutUint32(buf[9:], noxServer.Frame())
	noxServer.nox_xxx_netSendPacket1_4E5390(a1, buf[:13], 0, 1)
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
	netlist.AddToMsgListCli(pl.Index(), netlist.Kind1, buf[:4])
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
	return nox_netlist_addToMsgListSrv(pl.Index(), buf[:12])
}
