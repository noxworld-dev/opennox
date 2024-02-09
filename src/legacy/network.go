package legacy

/*
#include "defs.h"
#include "common__net_list.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_2.h"
#include "GAME4_2.h"
#include "GAME5.h"
#include "GAME5_2.h"
extern unsigned int dword_5d4594_2649712;
extern unsigned int dword_5d4594_2660032;
extern unsigned int dword_5d4594_814548;
extern unsigned int dword_5d4594_2650652;
extern unsigned int nox_player_netCode_85319C;
extern unsigned long long qword_5d4594_814956;
extern uint32_t dword_5d4594_1200804;
extern uint32_t dword_5d4594_1200832;
unsigned int nox_client_getServerAddr_43B300();
void nox_xxx_playerInitColors_461460(nox_playerInfo* pl);
int nox_client_getServerPort_43B320();
int sub_457140(int a1, wchar2_t* a2);
int sub_43AF90(int a1);
int sub_456DF0(int a1);
void sub_455950(wchar2_t* a1);
int sub_455920(wchar2_t* a1);
int sub_43C650();
int sub_467CA0();
void* sub_49BB80(char a1);
int* nox_xxx_guiServerOptionsHide_4597E0(int a1);
int nox_net_importantACK_4E55A0(int a1, int a2);
int nox_xxx_netClientSend2_4E53C0(int a1, const void* a2, int a3, int a4, int a5);
void* nox_xxx_spriteGetMB_476F80();
int nox_xxx_netSendPacket_4E5030(int a1, const void* a2, signed int a3, int a4, int a5, char a6);
int nox_xxx_netOnPacketRecvCli_48EA70(int a1, unsigned char* data, int sz);
static int nox_xxx_netSendLineMessage_go(nox_object_t* a1, wchar2_t* str) {
	return nox_xxx_netSendLineMessage_4D9EB0(a1, str);
}

nox_drawable* nox_xxx_netSpriteByCodeDynamic_45A6F0(int a1);

int nox_xxx_netPlayerObjSend_518C30(nox_object_t* a1, nox_object_t* a2, int a3, signed int a4);
int nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_switch(int a1, unsigned char* data, int dsz, nox_playerInfo* v8p, nox_object_t* unitp, void* v10p);
int nox_xxx_netOnPacketRecvCli_48EA70_switch(int a1, int op, unsigned char* data, int sz);
*/
import "C"
import (
	"net"
	"net/netip"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/noxnet"

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
	addr, _ := netip.AddrFromSlice(ip.To4())
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

//export nox_xxx_networkLog_print
func nox_xxx_networkLog_print(cstr *C.char) {
	NetworkLogPrint(GoString(cstr))
}

//export nox_client_setServerConnectAddr_435720
func nox_client_setServerConnectAddr_435720(addr *C.char) {
	ClientSetServerHost(GoString(addr))
}

//export nox_client_joinGame_438A90
func nox_client_joinGame_438A90() int { return Nox_client_joinGame_438A90() }

//export sub_5550D0
func sub_5550D0(addr int, port C.uint16_t, cdata *C.char) int {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cdata)), 22)
	n, err := SendXXX_5550D0(netip.AddrPortFrom(int2ip(uint32(addr)), uint16(port)), buf)
	return convSendToServerErr(n, err)
}

//export sub_5545A0
func sub_5545A0() C.short { return C.short(GetServer().S().GetServerPort()) }

//export sub_554230
func sub_554230() *C.char { return internCStr(GetServer().S().GetOwnIP()) }

//export nox_xxx_netStatsMultiplier_4D9C20
func nox_xxx_netStatsMultiplier_4D9C20(a1p *nox_object_t) int {
	return Nox_xxx_netStatsMultiplier_4D9C20(asObjectS(a1p))
}

//export sub_554240
func sub_554240(a1 int) int { return Sub_554240(ntype.PlayerInd(a1)) }

//export nox_xxx_net_getIP_554200
func nox_xxx_net_getIP_554200(a1 int) uint32 {
	if a1 < 0 || a1 >= 31 {
		panic("unexpected index")
	}
	var conn netstr.Handle
	if a1 == 0 {
		conn = GetServer().S().NetStr.Host()
	} else {
		conn = GetServer().S().NetStr.ByPlayerInd(ntype.PlayerInd(a1) + 1)
	}
	return Nox_xxx_net_getIP_554200(conn)
}

//export nox_xxx_netOnPacketRecvCli_48EA70
func nox_xxx_netOnPacketRecvCli_48EA70(ind int, buf *byte, sz int) int {
	return Nox_xxx_netOnPacketRecvCli_48EA70(ntype.PlayerInd(ind), buf, sz)
}

//export sub_43C6E0
func sub_43C6E0() int { return Sub_43C6E0() }

//export sub_43CF40
func sub_43CF40() { Sub_43CF40() }

//export sub_43CF70
func sub_43CF70() { Sub_43CF70() }

func ClientGetServerPort() int {
	return int(C.nox_client_getServerPort_43B320())
}

func Sub_43AF90(v int) {
	C.dword_5d4594_814548 = C.uint(v)
}

func Nox_xxx_netSendPacket_4E5030(a1 int, buf []byte, a4, a5, a6 int) int {
	b, free := alloc.CloneSlice(buf)
	defer free()
	return int(C.nox_xxx_netSendPacket_4E5030(C.int(a1), unsafe.Pointer(&b[0]), C.int(len(b)), C.int(a4), C.int(a5), C.char(a6)))
}

func Nox_client_getServerAddr_43B300() netip.Addr {
	return int2ip(uint32(C.nox_client_getServerAddr_43B300()))
}

func Nox_xxx_netSendLineMessage_4D9EB0(u *server.Object, s string) bool {
	_ = noxnet.MSG_TEXT_MESSAGE
	cstr, free := CWString(s)
	defer free()
	return C.nox_xxx_netSendLineMessage_go(asObjectC(u), cstr) != 0
}

func Nox_server_makeServerInfoPacket_554040(src, dst []byte) int {
	csrc, free := alloc.Make([]byte{}, len(src))
	defer free()
	copy(csrc, src)
	return int(C.nox_server_makeServerInfoPacket_554040((*C.char)(unsafe.Pointer(&src[0])), C.int(len(src)), (*C.char)(unsafe.Pointer(&dst[0]))))
}

func Sub_40A740() int {
	return int(C.sub_40A740())
}

func Sub_417DE0() int {
	return int(C.sub_417DE0())
}

func Nox_xxx_countObserverPlayers_425BF0() int {
	return int(C.nox_xxx_countObserverPlayers_425BF0())
}

func Sub_43C650() {
	C.sub_43C650()
}

func Sub_41D6C0() {
	C.sub_41D6C0()
}

func Sub_49C7A0() {
	C.sub_49C7A0()
}
func Sub_467CA0() {
	C.sub_467CA0()
}
func Sub_48D660() {
	C.sub_48D660()
}
func Sub_40A220() int {
	return int(C.sub_40A220())
}
func Sub_40A230() uint32 {
	return uint32(C.sub_40A230())
}

func convSendToServerErr(n int, err error) int {
	if err == client.ErrLobbyNoSocket {
		return -17
	} else if err != nil {
		return -1
	}
	return n
}
func Nox_xxx_netClientSend2_4E53C0(a1 int, a2 unsafe.Pointer, a3 int, a4 int, a5 int) {
	C.nox_xxx_netClientSend2_4E53C0(C.int(a1), a2, C.int(a3), C.int(a4), C.int(a5))
}
func Sub_57B920(a1 unsafe.Pointer) {
	C.sub_57B920(a1)
}
func Nox_xxx_cliSetSettingsAcquired_4169D0(a1 int) {
	C.nox_xxx_cliSetSettingsAcquired_4169D0(C.int(a1))
}
func Sub_457140(a1 int, a2 *uint16) {
	C.sub_457140(C.int(a1), (*C.ushort)(unsafe.Pointer(a2)))
}
func Sub_455920(a1 *uint16) {
	C.sub_455920((*C.ushort)(unsafe.Pointer(a1)))
}
func Sub_456DF0(a1 int) {
	C.sub_456DF0(C.int(a1))
}
func Sub_455950(a1 *uint16) {
	C.sub_455950((*C.ushort)(unsafe.Pointer(a1)))
}
func Nox_xxx_netChangeTeamMb_419570(a1 *server.ObjectTeam, a2 uint32) {
	C.nox_xxx_netChangeTeamMb_419570(a1.C(), C.int(a2))
}
func Sub_49BB80(a1 byte) {
	C.sub_49BB80(C.char(a1))
}
func Nox_xxx_netOnPacketRecvCli_48EA70_switch(a1 ntype.PlayerInd, a2 noxnet.Op, data []byte) int {
	return int(C.nox_xxx_netOnPacketRecvCli_48EA70_switch(C.int(a1), C.int(a2), (*C.uchar)(unsafe.Pointer(&data[0])), C.int(len(data))))
}
func Sub_4DDE10(a1 int, a2 *server.Player) {
	C.sub_4DDE10(C.int(a1), (*nox_playerInfo)(a2.C()))
}
func Nox_xxx_netPlayerObjSend_518C30(a1 *server.Object, a2 *server.Object, a3 int, a4 int) int {
	return int(C.nox_xxx_netPlayerObjSend_518C30(asObjectC(a1), asObjectC(a2), C.int(a3), C.int(a4)))
}
func Nox_xxx_gameServerReadyMB_4DD180(a1 int) {
	C.nox_xxx_gameServerReadyMB_4DD180(C.int(a1))
}
func Nox_xxx_teamCompare2_419180(t *server.ObjectTeam, id server.TeamID) int {
	return int(C.nox_xxx_teamCompare2_419180(unsafe.Pointer(t), C.uchar(id)))
}
func Sub_4D12A0(a1 int) int {
	return int(C.sub_4D12A0(C.int(a1)))
}
func Sub_4D1210(a1 int) {
	C.sub_4D1210(C.int(a1))
}
func Nox_net_importantACK_4E55A0(a1 int, a2 int) {
	C.nox_net_importantACK_4E55A0(C.int(a1), C.int(a2))
}
func Sub_4196D0(a1 unsafe.Pointer, a2 unsafe.Pointer, a3 int, a4 int) {
	C.sub_4196D0(a1, a2, C.int(a3), C.int(a4))
}
func Nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_switch(a1 ntype.PlayerInd, data []byte, a4 *server.Player, a5 *server.Object, a6 unsafe.Pointer) int {
	return int(C.nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_switch(C.int(a1), (*C.uchar)(unsafe.Pointer(&data[0])), C.int(len(data)), (*nox_playerInfo)(a4.C()), asObjectC(a5), a6))
}
func Nox_xxx_netReportAcquireCreature_4D91A0(pli int, obj *server.Object) {
	C.nox_xxx_netReportAcquireCreature_4D91A0(C.int(pli), asObjectC(obj))
}
func Nox_xxx_netSendSimpleObject2_4DF360(pli int, obj *server.Object) {
	C.nox_xxx_netSendSimpleObject2_4DF360(C.int(pli), asObjectC(obj))
}
func Nox_xxx_netCode2ChatBubble_48D850(a1 int) int {
	return int(C.nox_xxx_netCode2ChatBubble_48D850(C.int(a1)))
}
