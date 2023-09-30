package legacy

import (
	"image"
	"net"
	"net/netip"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	NetworkLogPrint                   func(str string)
	ClientSetServerHost               func(addr string)
	Nox_client_joinGame_438A90        func() int
	SendXXX_5550D0                    func(addr netip.AddrPort, data []byte) (int, error)
	Sub_5545A0                        func() uint16
	Sub_554230                        func() string
	Nox_xxx_netStatsMultiplier_4D9C20 func(a1p *server.Object) int
	Sub_554240                        func(a1 ntype.PlayerInd) int
	Nox_xxx_net_getIP_554200          func(a1 netstr.Handle) uint32
	Nox_xxx_netOnPacketRecvCli_48EA70 func(ind ntype.PlayerInd, buf *byte, sz int) int
	Sub_43C6E0                        func() int
	Sub_43CF40                        func()
	Sub_43CF70                        func()
)

func int2ip(v uint32) netip.Addr {
	b := (*[4]byte)(unsafe.Pointer(&v))[:]
	ip := net.IPv4(b[0], b[1], b[2], b[3])
	addr, _ := netip.AddrFromSlice(([]byte)(ip.To4()))
	return addr
}

func ip2int(ip netip.Addr) uint32 {
	if !ip.IsValid() {
		return 0
	}
	b := ip.As4()
	v := *(*uint32)(unsafe.Pointer(&b[0]))
	return v
}

func parseIP(s string) uint32 {
	addr, err := netip.ParseAddr(s)
	if err != nil {
		return 0
	}
	return ip2int(addr)
}

// nox_xxx_networkLog_print
func nox_xxx_networkLog_print(cstr *byte) {
	NetworkLogPrint(GoString(cstr))
}

// nox_client_setServerConnectAddr_435720
func nox_client_setServerConnectAddr_435720(addr *byte) {
	ClientSetServerHost(GoString(addr))
}

// nox_client_joinGame_438A90
func nox_client_joinGame_438A90() int32 { return int32(Nox_client_joinGame_438A90()) }

// sub_5550D0
func sub_5550D0(addr int32, port uint16, cdata *byte) int {
	buf := unsafe.Slice(cdata, 22)
	n, err := SendXXX_5550D0(netip.AddrPortFrom(int2ip(uint32(addr)), port), buf)
	return convSendToServerErr(n, err)
}

// sub_5545A0
func sub_5545A0() int16 { return int16(Sub_5545A0()) }

// sub_554230
func sub_554230() *byte { return internCStr(Sub_554230()) }

// nox_xxx_netStatsMultiplier_4D9C20
func nox_xxx_netStatsMultiplier_4D9C20(a1p *server.Object) int {
	return Nox_xxx_netStatsMultiplier_4D9C20(asObjectS(a1p))
}

// sub_554240
func sub_554240(a1 int32) int32 { return int32(Sub_554240(ntype.PlayerInd(a1))) }

// nox_xxx_net_getIP_554200
func nox_xxx_net_getIP_554200(a1 int32) uint32 {
	return Nox_xxx_net_getIP_554200(netstr.Global.ByIndexRaw(int(a1)))
}

// nox_xxx_netOnPacketRecvCli_48EA70
func nox_xxx_netOnPacketRecvCli_48EA70(ind int32, buf *byte, sz int32) int32 {
	return int32(Nox_xxx_netOnPacketRecvCli_48EA70(ntype.PlayerInd(ind), buf, int(sz)))
}

// sub_43C6E0
func sub_43C6E0() int { return Sub_43C6E0() }

// sub_43CF40
func sub_43CF40() { Sub_43CF40() }

// sub_43CF70
func sub_43CF70() { Sub_43CF70() }

func ClientGetServerPort() int {
	return int(nox_client_getServerPort_43B320())
}

func Sub_43AF90(v int) {
	dword_5d4594_814548 = uint32(v)
}

func Nox_client_getServerAddr_43B300() netip.Addr {
	return int2ip(nox_client_getServerAddr_43B300())
}

func Nox_xxx_netSendLineMessage_4D9EB0(u *server.Object, s string) {
	_ = noxnet.MSG_TEXT_MESSAGE
	cstr, free := CWString(s)
	defer free()
	nox_xxx_netSendLineMessage_4D9EB0(asObjectC(u), cstr)
}

func Nox_xxx_earthquakeSend_4D9110(pos types.Pointf, a2 int) {
	nox_xxx_earthquakeSend_4D9110(&pos, int32(a2))
}

func Nox_xxx_netSendFxAllCli_523030(pos types.Pointf, data []byte) {
	cdata, dfree := alloc.Make([]byte{}, len(data))
	defer dfree()
	copy(cdata, data)

	nox_xxx_netSendFxAllCli_523030(&pos, unsafe.Pointer(&cdata[0]), int32(len(data)))
}

func Nox_xxx_servCode_523340(p1, p2 image.Point, data []byte) bool {
	cdata, dfree := alloc.Make([]byte{}, len(data))
	defer dfree()
	copy(cdata, data)

	cpos, pfree := alloc.Make([]int32{}, 4)
	defer pfree()
	cpos[0] = int32(p1.X)
	cpos[1] = int32(p1.Y)
	cpos[2] = int32(p2.X)
	cpos[3] = int32(p2.Y)

	return nox_xxx_servCode_523340(&cpos[0], unsafe.Pointer(&cdata[0]), int32(len(data))) != 0
}

func Nox_server_makeServerInfoPacket_554040(src, dst []byte) int {
	csrc, free := alloc.Make([]byte{}, len(src))
	defer free()
	copy(csrc, src)
	return int(nox_server_makeServerInfoPacket_554040(&src[0], int32(len(src)), &dst[0]))
}

func Sub_40A740() int {
	return int(sub_40A740())
}

func Sub_417DE0() int {
	return int(sub_417DE0())
}

func Nox_xxx_countObserverPlayers_425BF0() int {
	return int(nox_xxx_countObserverPlayers_425BF0())
}

func Sub_43C650() {
	sub_43C650()
}

func Sub_41D6C0() {
	sub_41D6C0()
}

func Sub_49C7A0() {
	sub_49C7A0()
}
func Sub_467CA0() {
	sub_467CA0()
}
func Sub_40A220() int {
	return int(sub_40A220())
}
func Sub_40A230() uint32 {
	return uint32(sub_40A230())
}

func convSendToServerErr(n int, err error) int {
	if err == client.ErrLobbyNoSocket {
		return -17
	} else if err != nil {
		return -1
	}
	return n
}
func Nox_xxx_netClientSend2_4E53C0(a1 int, a2 unsafe.Pointer, a3 int, a5 int) {
	nox_xxx_netClientSend2_4E53C0(int32(a1), a2, int32(a3), int32(a5))
}
func Sub_57B920(a1 unsafe.Pointer) {
	sub_57B920(a1)
}
func Nox_xxx_cliSetSettingsAcquired_4169D0(a1 int) {
	nox_xxx_cliSetSettingsAcquired_4169D0(int32(a1))
}
func Sub_457140(a1 int, a2 *uint16) {
	sub_457140(int32(a1), a2)
}
func Sub_455920(a1 *uint16) {
	sub_455920(a1)
}
func Sub_456DF0(a1 int) {
	sub_456DF0(int32(a1))
}
func Sub_455950(a1 *uint16) {
	sub_455950(a1)
}
func Nox_xxx_netChangeTeamMb_419570(a1 *server.ObjectTeam, a2 uint32) {
	nox_xxx_netChangeTeamMb_419570(a1.C(), int32(a2))
}
func Sub_49BB80(a1 byte) {
	sub_49BB80(int8(a1))
}
func Nox_xxx_netOnPacketRecvCli_48EA70_switch(a1 ntype.PlayerInd, a2 noxnet.Op, data []byte) int {
	return int(nox_xxx_netOnPacketRecvCli_48EA70_switch(int32(a1), int32(a2), &data[0], int32(len(data))))
}
func Sub_4DDE10(a1 int, a2 *server.Player) {
	sub_4DDE10(int32(a1), a2)
}
func Nox_xxx_netPlayerObjSend_518C30(a1 *server.Object, a2 *server.Object, a3 int, a4 int) int {
	return int(nox_xxx_netPlayerObjSend_518C30(asObjectC(a1), asObjectC(a2), int32(a3), int32(a4)))
}
func Nox_xxx_gameServerReadyMB_4DD180(a1 int) {
	nox_xxx_gameServerReadyMB_4DD180(int32(a1))
}
func Nox_xxx_teamCompare2_419180(t *server.ObjectTeam, id server.TeamID) int {
	return int(nox_xxx_teamCompare2_419180(t, id))
}
func Sub_4D12A0(a1 int) int {
	return int(sub_4D12A0(int32(a1)))
}
func Sub_4D1210(a1 int) {
	sub_4D1210(int32(a1))
}
func Nox_net_importantACK_4E55A0(a1 int, a2 int) {
	nox_net_importantACK_4E55A0(int32(a1), int32(a2))
}
func Sub_4196D0(a1 unsafe.Pointer, a2 unsafe.Pointer, a3 int, a4 int) {
	sub_4196D0(a1, a2, int32(a3), int32(a4))
}
func Nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_switch(a1 ntype.PlayerInd, data []byte, a4 *server.Player, a5 *server.Object, a6 unsafe.Pointer) int {
	return int(nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_switch(int32(a1), &data[0], int32(len(data)), a4, asObjectC(a5), a6))
}
func Nox_xxx_netReportAcquireCreature_4D91A0(pli int, obj *server.Object) {
	nox_xxx_netReportAcquireCreature_4D91A0(int32(pli), asObjectC(obj))
}
func Nox_xxx_netMarkMinimapObject_417190(pli int, obj *server.Object, a3 int) {
	nox_xxx_netMarkMinimapObject_417190(int32(pli), asObjectC(obj), uint32(int32(a3)))
}
func Nox_xxx_netSendSimpleObject2_4DF360(pli int, obj *server.Object) {
	nox_xxx_netSendSimpleObject2_4DF360(int32(pli), asObjectC(obj))
}
