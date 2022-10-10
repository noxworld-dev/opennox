package opennox

/*
#include "defs.h"
#include "nox_net.h"
#include "common__net_list.h"
#include "server__network__sdecode.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_2.h"
#include "GAME4_2.h"
#include "GAME5.h"
#include "GAME5_2.h"
#ifdef _WIN32
#include <windows.h>
#else
#include "windows_compat.h"
#endif
extern unsigned int dword_5d4594_2649712;
extern unsigned int dword_5d4594_2660032;
extern unsigned int dword_5d4594_814548;
extern unsigned int dword_5d4594_2495920;
extern uint32_t nox_perfmon_ping_2614264;
extern unsigned long long qword_5d4594_814956;
unsigned int nox_client_getServerAddr_43B300();
int nox_client_getServerPort_43B320();
int nox_client_getClientPort_40A420();
int sub_419E60(nox_object_t* a1);
int sub_43AF90(int a1);
int nox_xxx_netClientSend2_4E53C0(int a1, const void* a2, int a3, int a4, int a5);
void* nox_xxx_spriteGetMB_476F80();
int nox_xxx_netSendPacket_4E5030(int a1, const void* a2, signed int a3, int a4, int a5, char a6);
int nox_xxx_netOnPacketRecvCli_48EA70(int a1, unsigned char* data, int sz);
static int nox_xxx_netSendLineMessage_go(nox_object_t* a1, wchar_t* str) {
	return nox_xxx_netSendLineMessage_4D9EB0(a1, str);
}

extern float nox_xxx_warriorMaxHealth_587000_312784;
extern float nox_xxx_warriorMaxMana_587000_312788;

extern float nox_xxx_conjurerMaxHealth_587000_312800;
extern float nox_xxx_conjurerMaxMana_587000_312804;

extern float nox_xxx_wizardMaxHealth_587000_312816;
extern float nox_xxx_wizardMaximumMana_587000_312820;

static int nox_call_net_xxxyyy_go(int (*fnc)(unsigned int, char*, int, void*), unsigned int a1, void* a2, int a3, void* a4) { return fnc(a1, a2, a3, a4); }
*/
import "C"
import (
	"context"
	"encoding/binary"
	"image"
	"math"
	"net/netip"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/nat"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/serial"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
)

func init() {
	configBoolPtr("network.xor", "NOX_NET_XOR", true, &netstr.Xor)
	configHiddenBoolPtr("debug.network", "NOX_DEBUG_NET", &netstr.Debug)
	netstr.GameFrame = gameFrame
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
	dword_5D4594_815700  int
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

//export nox_xxx_networkLog_print
func nox_xxx_networkLog_print(cstr *C.char) {
	networkLogPrint(GoString(cstr))
}

func networkLogPrint(str string) {
	if !noxflags.HasGame(noxflags.GameFlag3) {
		return
	}
	netstr.Log.Println(str)
	noxConsole.Print(console.ColorGreen, str)
}

//export nox_xxx_netGet_43C750
func nox_xxx_netGet_43C750() C.int { return C.int(dword_5D4594_815700) }

func clientSetServerHost(host string) {
	netstr.Log.Printf("server host: %s", host)
	noxServerHost = host
}

func clientGetServerHost() string {
	return noxServerHost
}

func clientGetServerPort() int {
	return int(C.nox_client_getServerPort_43B320())
}

func clientGetClientPort() int {
	return int(C.nox_client_getClientPort_40A420())
}

//export nox_client_setServerConnectAddr_435720
func nox_client_setServerConnectAddr_435720(addr *C.char) {
	clientSetServerHost(GoString(addr))
}

func nox_xxx_getMapCRC_40A370() int {
	return noxMapCRC
}

//export nox_xxx_setMapCRC_40A360
func nox_xxx_setMapCRC_40A360(crc C.int) {
	if netstr.Debug {
		netstr.Log.Printf("map crc set: %d", int(crc))
	}
	noxMapCRC = int(crc)
}

//export noxOnCliPacketDebug
func noxOnCliPacketDebug(op C.int, data *C.uchar, sz C.int) {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(data)), int(sz))
	if netstr.Debug && sz != 0 {
		op := noxnet.Op(op)
		netstr.Log.Printf("CLIENT: op=%d (%s) [%d:%d]\n%02x %x", int(op), op.String(), int(sz)-1, op.Len(), buf[0], buf[1:])
	}
}

//export noxOnSrvPacketDebug
func noxOnSrvPacketDebug(op C.int, data *C.uchar, sz C.int) {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(data)), int(sz))
	if netstr.Debug && sz != 0 {
		op := noxnet.Op(op)
		netstr.Log.Printf("SERVER: op=%d (%s) [%d:%d]\n%02x %x", int(op), op.String(), int(sz)-1, op.Len(), buf[0], buf[1:])
	}
}

func convSendToServerErr(n int, err error) C.int {
	if err == errLobbyNoSocket {
		return -17
	} else if err != nil {
		return -1
	}
	return C.int(n)
}

func sub_43AF90(v int) {
	C.dword_5d4594_814548 = C.uint(v)
}

func nox_client_createSockAndJoin_43B440() error {
	if dword_587000_87404 == 1 {
		if err := nox_xxx_createSocketLocal(0); err != nil {
			return err
		}
	}
	return nox_client_joinGame()
}

//export nox_client_joinGame_438A90
func nox_client_joinGame_438A90() C.int {
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
	if n := alloc.StrLen((*C.wchar_t)(wstr)); n != 0 {
		copy(buf[4:54], unsafe.Slice((*byte)(wstr), n*2))
	}
	buf[54] = memmap.Uint8(0x85B3FC, 12254)
	buf[55] = memmap.Uint8(0x85B3FC, 12256)
	endianess.PutUint32(buf[80:], NOX_CLIENT_VERS_CODE)
	endianess.PutUint32(buf[84:], uint32(C.dword_5d4594_2660032))

	copy(buf[88:98], GoStringP(memmap.PtrOff(0x85B3FC, 10344)))
	buf[98] = byte(bool2int(!nox_xxx_checkHasSoloMaps()))

	sub_43AF90(3)
	C.qword_5d4594_814956 = C.ulonglong(platformTicks() + 20000)

	addr := nox_client_getServerAddr_43B300()
	port := clientGetServerPort()
	netstr.Log.Printf("join server: %s:%d", addr.String(), port)
	_, err := sendJoinGame(netip.AddrPortFrom(addr, uint16(port)), buf)
	return err
}

//export sub_5550D0
func sub_5550D0(addr C.int, port C.uint16_t, cdata *C.char) C.int {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cdata)), 22)
	n, err := sendXXX_5550D0(netip.AddrPortFrom(int2ip(uint32(addr)), uint16(port)), buf)
	return convSendToServerErr(n, err)
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
	b, free := alloc.CloneSlice(buf)
	defer free()
	return int(C.nox_xxx_netSendPacket_4E5030(C.int(a1), unsafe.Pointer(&b[0]), C.int(len(b)), C.int(a4), C.int(a5), C.char(a6)))
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

func nox_client_getServerAddr_43B300() netip.Addr {
	return int2ip(uint32(C.nox_client_getServerAddr_43B300()))
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
	C.nox_xxx_netClientSend2_4E53C0(C.int(a1), unsafe.Pointer(&p[0]), C.int(len(buf)), C.int(a4), C.int(a5))
}

func (c *Client) clientSendInput(pli int) bool {
	nbuf := ctrlEvent.netBuf
	if len(nbuf) == 0 {
		return true
	}
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_PLAYER_INPUT)
	buf[1] = byte(len(nbuf))
	if !nox_netlist_addToMsgListCli(pli, 0, buf[:2]) {
		return false
	}
	if !nox_netlist_addToMsgListCli(pli, 0, nbuf) {
		return false
	}
	return true
}

func (c *Client) clientSendInputMouse(pli int, mp image.Point) bool {
	sp := nox_xxx_spriteGetMB_476F80()
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
	return nox_netlist_addToMsgListCli(pli, 0, buf[:5])
}

func (s *Server) nox_xxx_netAddPlayerHandler_4DEBC0(port int) (ind, cport int, _ error) {
	narg := &netstr.Options{
		Port:     port,
		Max:      s.getServerMaxPlayers(),
		DataSize: 2048,
		Func2:    nox_xxx_netlist_ServRecv,
		Func1: func(a1 int, a2 []byte, a3 unsafe.Pointer) int {
			return int(C.nox_xxx_netFn_UpdateStream_4DF630(C.int(a1), (*C.char)(unsafe.Pointer(&a2[0])), C.uint(len(a2)), a3))
		},
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

//export sub_5545A0
func sub_5545A0() C.short {
	return C.short(netSomePort)
}

//export sub_554230
func sub_554230() *C.char {
	return internCStr(dword_973f18_44216)
}

func nox_xxx_netInit_554380(narg *netstr.Options) (ind int, _ error) {
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

func (s *Server) nox_server_netClose_5546A0(i int) {
	netstr.CloseByInd(i)
}

//export nox_xxx_netStructReadPackets_5545B0
func nox_xxx_netStructReadPackets_5545B0(ind C.uint) C.int {
	return C.int(netstr.ReadPackets(int(ind)))
}

func (s *Server) nox_xxx_netStructReadPackets2_4DEC50(a1 int) int {
	return netstr.ReadPackets(a1 + 1)
}

func nox_xxx_netlist_ServRecv(a1 int, a2 []byte, _ unsafe.Pointer) int {
	// should pass the pointer unchanged, otherwise expect bugs!
	nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_raw(a1-1, a2)
	return 1
}

//export nox_xxx_netSendSock_552640
func nox_xxx_netSendSock_552640(id int, ptr *byte, sz int, flags int) int {
	n, _ := netstr.Send(id, unsafe.Slice(ptr, sz), flags)
	return n
}

func nox_xxx_netSendClientReady_43C9F0() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_CLIENT_READY)
	netstr.Send(dword_5D4594_815700, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	return 1
}

func nox_xxx_netKeepAliveSocket_43CA20() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_KEEP_ALIVE)
	netstr.Send(dword_5D4594_815700, data[:], netstr.SendFlagFlush)
	return 1
}

func nox_xxx_netRequestMap_43CA50() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_REQUEST_MAP)
	netstr.Send(dword_5D4594_815700, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	return 1
}

func nox_xxx_netMapReceived_43CA80() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_RECEIVED_MAP)
	netstr.Send(dword_5D4594_815700, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	return 1
}

func nox_xxx_cliSendCancelMap_43CAB0() int {
	id := dword_5D4594_815700
	var data [1]byte
	data[0] = byte(noxnet.MSG_CANCEL_MAP)
	v0, _ := netstr.Send(id, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	if netstr.WaitServerResponse(id, v0, 20, 6) != 0 {
		return 0
	}
	nox_netlist_resetByInd_40ED10(noxMaxPlayers-1, 0)
	return 1
}

func nox_xxx_netSendIncomingClient_43CB00() int {
	id := dword_5D4594_815700
	var data [1]byte
	data[0] = byte(noxnet.MSG_INCOMING_CLIENT)
	v0, _ := netstr.Send(id, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	if netstr.WaitServerResponse(id, v0, 20, 6) != 0 {
		return 0
	}
	nox_netlist_resetByInd_40ED10(noxMaxPlayers-1, 0)
	return 1
}

func nox_xxx_servNetInitialPackets_552A80_discover(src, dst []byte) int {
	// received a lobby info request from the client
	if nox_xxx_check_flag_aaa_43AF70() == 0 {
		// send server info packet
		return nox_server_makeServerInfoPacket_554040(src, dst)
	}
	return 0
}

func nox_xxx_servNetInitialPackets_552A80(id int, flags int) int {
	return netstr.ServeInitialPackets(id, flags)
}

func nox_xxx_cliSendOutgoingClient_43CB50() int {
	id := dword_5D4594_815700
	var data [1]byte
	data[0] = byte(noxnet.MSG_OUTGOING_CLIENT)
	v0, _ := netstr.Send(id, data[:], netstr.SendNoLock|netstr.SendFlagFlush)
	if netstr.WaitServerResponse(id, v0, 20, 6) != 0 {
		return 0
	}
	nox_xxx_servNetInitialPackets_552A80(id, 3)
	nox_netlist_resetByInd_40ED10(noxMaxPlayers-1, 0)
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
		return nox_netlist_addToMsgListCli(pid, 1, buf[:6])
	case 17:
		return nox_netlist_addToMsgListCli(pid, 1, buf[:2])
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

func nox_xxx_netSendLineMessage_4D9EB0(u *Unit, s string) bool {
	_ = noxnet.MSG_TEXT_MESSAGE
	cstr, free := CWString(s)
	defer free()
	return C.nox_xxx_netSendLineMessage_go(u.CObj(), cstr) != 0
}

func nox_xxx_netSendPointFx_522FF0(fx noxnet.Op, pos types.Pointf) bool {
	var buf [5]byte
	buf[0] = byte(fx)
	binary.LittleEndian.PutUint16(buf[1:], uint16(int(pos.X)))
	binary.LittleEndian.PutUint16(buf[3:], uint16(int(pos.Y)))
	return nox_xxx_netSendFxAllCli_523030(pos, buf[:5])
}

func nox_xxx_netSendRayFx_5232F0(fx noxnet.Op, p1, p2 image.Point) bool {
	var buf [9]byte
	buf[0] = byte(fx)
	binary.LittleEndian.PutUint16(buf[1:], uint16(p1.X))
	binary.LittleEndian.PutUint16(buf[3:], uint16(p1.Y))
	binary.LittleEndian.PutUint16(buf[5:], uint16(p2.X))
	binary.LittleEndian.PutUint16(buf[7:], uint16(p2.Y))
	return nox_xxx_servCode_523340(p1, p2, buf[:9])
}

func nox_xxx_netSparkExplosionFx_5231B0(pos types.Pointf, a2 byte) bool {
	var buf [6]byte
	buf[0] = byte(noxnet.MSG_FX_SPARK_EXPLOSION)
	binary.LittleEndian.PutUint16(buf[1:], uint16(pos.X))
	binary.LittleEndian.PutUint16(buf[3:], uint16(pos.Y))
	buf[5] = a2
	return nox_xxx_netSendFxAllCli_523030(pos, buf[:6])
}

func nox_xxx_earthquakeSend_4D9110(pos types.Pointf, a2 int) {
	cpos, pfree := alloc.Make([]float32{}, 2)
	defer pfree()
	cpos[0] = pos.X
	cpos[1] = pos.Y

	C.nox_xxx_earthquakeSend_4D9110((*C.float)(unsafe.Pointer(&cpos[0])), C.int(a2))
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
	return nox_xxx_netSendFxAllCli_523030(pos, buf[:11])
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
	return nox_xxx_netSendFxAllCli_523030(pos, buf[:11])
}

func nox_xxx_netSendFxAllCli_523030(pos types.Pointf, data []byte) bool {
	cdata, dfree := alloc.Make([]byte{}, len(data))
	defer dfree()
	copy(cdata, data)

	cpos, pfree := alloc.Make([]float32{}, 2)
	defer pfree()
	cpos[0] = pos.X
	cpos[1] = pos.Y

	return C.nox_xxx_netSendFxAllCli_523030((*C.float2)(unsafe.Pointer(&cpos[0])), unsafe.Pointer(&cdata[0]), C.int(len(data))) != 0
}

func nox_xxx_servCode_523340(p1, p2 image.Point, data []byte) bool {
	cdata, dfree := alloc.Make([]byte{}, len(data))
	defer dfree()
	copy(cdata, data)

	cpos, pfree := alloc.Make([]int32{}, 4)
	defer pfree()
	cpos[0] = int32(p1.X)
	cpos[1] = int32(p1.Y)
	cpos[2] = int32(p2.X)
	cpos[3] = int32(p2.Y)

	return C.nox_xxx_servCode_523340((*C.int)(unsafe.Pointer(&cpos[0])), unsafe.Pointer(&cdata[0]), C.int(len(data))) != 0
}

func nox_xxx_netReportLesson_4D8EF0(u *Unit) {
	var buf [11]byte
	buf[0] = byte(noxnet.MSG_REPORT_LESSON)
	pl := u.ControllingPlayer()
	binary.LittleEndian.PutUint16(buf[1:], uint16(u.net_code))
	binary.LittleEndian.PutUint32(buf[3:], uint32(pl.lessons))
	binary.LittleEndian.PutUint32(buf[7:], uint32(pl.field_2140))
	noxServer.nox_xxx_netSendPacket1_4E5390(255, buf[:11], 0, 1)
}

func nox_xxx_netScriptMessageKill_4D9760(u *Unit) {
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	pl := u.ControllingPlayer()
	var buf [1]byte
	buf[0] = byte(noxnet.MSG_MESSAGES_KILL)
	noxServer.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:1], 0, 1)
}

func nox_xxx_netKillChat_528D00(u *Unit) {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_CHAT_KILL)
	binary.LittleEndian.PutUint16(buf[1:], uint16(noxServer.getUnitNetCode(u)))
	for _, pl := range noxServer.getPlayers() {
		u := pl.UnitC()
		if u == nil {
			continue
		}
		nox_netlist_addToMsgListCli(pl.Index(), 1, buf[:3])
	}
}

func netSendGauntlet() {
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_GAUNTLET)
	buf[1] = 27
	nox_xxx_netClientSend2_4E53C0(noxMaxPlayers-1, buf[:2], 0, 0)
}

func nox_xxx_sendGauntlet_4DCF80(ind int, v byte) {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_GAUNTLET)
	buf[1] = 28
	buf[2] = v
	noxServer.nox_xxx_netSendPacket1_4E5390(ind, buf[:3], 0, 0)
}

//export nox_xxx_netStatsMultiplier_4D9C20
func nox_xxx_netStatsMultiplier_4D9C20(a1p *nox_object_t) C.int {
	u := asUnitC(a1p)
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
		binary.LittleEndian.PutUint32(buf[1:], math.Float32bits(float32(C.nox_xxx_warriorMaxHealth_587000_312784)))
		binary.LittleEndian.PutUint32(buf[5:], math.Float32bits(float32(C.nox_xxx_warriorMaxMana_587000_312788)))
		binary.LittleEndian.PutUint32(buf[9:], math.Float32bits(noxServer.players.mult.warrior.strength))
		binary.LittleEndian.PutUint32(buf[13:], math.Float32bits(noxServer.players.mult.warrior.speed))
	case player.Wizard:
		binary.LittleEndian.PutUint32(buf[1:], math.Float32bits(float32(C.nox_xxx_wizardMaxHealth_587000_312816)))
		binary.LittleEndian.PutUint32(buf[5:], math.Float32bits(float32(C.nox_xxx_wizardMaximumMana_587000_312820)))
		binary.LittleEndian.PutUint32(buf[9:], math.Float32bits(noxServer.players.mult.wizard.strength))
		binary.LittleEndian.PutUint32(buf[13:], math.Float32bits(noxServer.players.mult.wizard.speed))
	case player.Conjurer:
		binary.LittleEndian.PutUint32(buf[1:], math.Float32bits(float32(C.nox_xxx_conjurerMaxHealth_587000_312800)))
		binary.LittleEndian.PutUint32(buf[5:], math.Float32bits(float32(C.nox_xxx_conjurerMaxMana_587000_312804)))
		binary.LittleEndian.PutUint32(buf[9:], math.Float32bits(noxServer.players.mult.conjurer.strength))
		binary.LittleEndian.PutUint32(buf[13:], math.Float32bits(noxServer.players.mult.conjurer.speed))
	}
	return C.int(noxServer.nox_xxx_netSendPacket0_4E5420(pl.Index(), buf[:17], 0, 1))
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
		nox_xxx_netPriMsgToPlayer_4DA2C0(u, id, 0)
	}
}

func nox_xxx_netPriMsgToPlayer_4DA2C0(u *Unit, id strman.ID, a3 byte) {
	var buf [52]byte
	if u == nil || !u.Class().Has(object.ClassPlayer) || id == "" || len(id) > len(buf)-4 || C.sub_419E60(u.CObj()) != 0 {
		return
	}
	buf[0] = byte(noxnet.MSG_INFORM)
	buf[1] = 15
	buf[2] = a3
	n := copy(buf[3:len(buf)-1], string(id))
	buf[3+n] = 0
	nox_netlist_addToMsgListCli(u.ControllingPlayer().Index(), 1, buf[:n+4])
}

func nox_xxx_netSendBySock_40EE10(a1 int, a2 int, a3 int) {
	v3 := nox_netlist_copyPacketList(a2, a3)
	if len(v3) != 0 {
		netstr.Send(a1, v3, 0)
		netstr.SendReadPacket(a1, 1)
	}
}

func nox_server_makeServerInfoPacket_554040(src, dst []byte) int {
	csrc, free := alloc.Make([]byte{}, len(src))
	defer free()
	copy(csrc, src)
	return int(C.nox_server_makeServerInfoPacket_554040((*C.char)(unsafe.Pointer(&src[0])), C.int(len(src)), (*C.char)(unsafe.Pointer(&dst[0]))))
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
	if GoWStringBytes(packet[4:]) != GoWStringBytes(v33[39:]) {
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

func nox_xxx_netBigSwitch_553210_op_14_check(out []byte, packet []byte, a4a bool, add func(pid int) bool) int {
	s := noxServer
	v43 := false
	v78 := sub_416640()
	nox_xxx_cliGamedataGet_416590(0)

	// TODO: This code is disabled because it causes issues with players reconnecting to the server.
	//       For some reason the player record gets stuck in the server's player list, so this check fails.
	if false {
		if nox_xxx_check_flag_aaa_43AF70() == 0 {
			serial := GoStringS(packet[56:])
			for it := s.playerFirst(); it != nil; it = s.playerNext(it) {
				if byte(it.field_2135) == packet[98] {
					if it.Serial() == serial {
						out[2] = 19
						out[3] = 12
						return 4
					}
				}
			}
		}
	}

	if binary.LittleEndian.Uint32(packet[80:]) != NOX_CLIENT_VERS_CODE {
		out[2] = 19
		out[3] = 13
		return 4
	}
	if C.sub_40A740() != 0 {
		v46 := int(C.nox_xxx_countObserverPlayers_425BF0())
		f21 := binary.LittleEndian.Uint32(packet[84:])
		if f21 == 0 {
			if byte(v46) >= v78[53] {
				out[2] = 19
				out[3] = 11
				return 4
			}
		} else if s.teamByXxx(int(f21)) != nil {
			if v46 > 0 {
				v43 = true
			}
		} else {
			if byte(C.sub_417DE0()) >= v78[52] {
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
		for it := s.firstReplaceablePlayer(); it != nil; it = s.nextReplaceablePlayer(it) {
			if add(it.Index() + 1) {
				s.getPlayerByInd(it.Index()).Disconnect(4)
				out[2] = 21
				return 3
			}
		}
	}
	if v78[100]&0x10 != 0 {
		var found bool
		for it := sub_4168E0(); it != nil; it = sub_4168F0(it) {
			if strings.ToLower(GoWStringP(unsafe.Add(it, 12))) == strings.ToLower(GoWStringBytes(packet[4:])) {
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
			if GoStringP(unsafe.Add(it, 72)) == "0" {
				if strings.ToLower(GoWStringP(unsafe.Add(it, 12))) == strings.ToLower(GoWStringBytes(packet[4:])) {
					out[2] = 19
					out[3] = 5
					return 4
				}
			} else {
				if strings.ToLower(GoStringP(unsafe.Add(it, 72))) == strings.ToLower(GoStringS(packet[56:])) {
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

//export sub_554240
func sub_554240(a1 int) int {
	if a1 != 31 {
		return netstr.GetTimingByInd1(a1)
	}
	return int(nox_ctrlevent_add_ticks_42E630())
}

func sub_43CC80() {
	netstr.SendClose(int(nox_xxx_netGet_43C750()))
	C.dword_5d4594_2649712 = 0
}

//export nox_xxx_netSendReadPacket_5528B0
func nox_xxx_netSendReadPacket_5528B0(ind int, a2 byte) int {
	return netstr.SendReadPacket(ind, a2)
}

func sub_5521A0() bool {
	v13 := sub_416640()
	netstr.ProcessStats(int(*(*int16)(unsafe.Pointer(&v13[105]))), int(*(*int16)(unsafe.Pointer(&v13[107]))))
	return true
}

func nox_xxx_allocNetGQueue_5520B0() {
	gameSet816392Func(sub_5521A0)
	netstr.Init()
}

//export nox_xxx_net_getIP_554200
func nox_xxx_net_getIP_554200(a1 int) uint32 {
	if a1 == 0 {
		return ip2int(dword_5d4594_3843632)
	}
	return ip2int(netstr.GetIPByInd(a1))
}

//export sub_519930
func sub_519930(a1 int) int {
	cnt := 0
	v2 := int(memmap.Uint32(0x5D4594, 2387148+48*uintptr(a1)))
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

func nox_xxx_netOnPacketRecvCli_48EA70(ind int, buf []byte) int {
	return int(C.nox_xxx_netOnPacketRecvCli_48EA70(C.int(ind), (*C.uchar)(unsafe.Pointer(&buf[0])), C.int(len(buf))))
}

//export sub_43C6E0
func sub_43C6E0() int {
	return bool2int(!dword_5d4594_815704 && !dword_5d4594_815708)
}

func nox_xxx_netHandleCliPacket_43C860(_ int, data []byte, _ unsafe.Pointer) int {
	op := noxnet.Op(data[0])
	noxPerfmon.packetSizeCli = len(data)
	if op == noxnet.MSG_XXX_STOP {
		sub_446380()
	} else if op == noxnet.MSG_PING {
		C.nox_perfmon_ping_2614264 = C.uint(binary.LittleEndian.Uint32(data[1:]))
	} else if op >= noxnet.MSG_TIMESTAMP {
		nox_xxx_netOnPacketRecvCli_48EA70(noxMaxPlayers-1, data)
		if nox_client_isConnected() {
			C.sub_48D660()
		}
	}
	lastCliHandlePackets = platformTicks()
	if dword_5d4594_815704 {
		C.sub_4AB4A0(0)
		dword_5d4594_815704 = false
	}
	if dword_5d4594_815708 {
		sub_43CF40()
	}
	return 1
}

//export sub_43CF40
func sub_43CF40() {
	ticks815732 = platformTicks()
	dword_5d4594_815708 = false
	C.sub_4AB4D0(0)
}

//export sub_43CF70
func sub_43CF70() {
	if !dword_5d4594_815708 {
		C.sub_4AB4D0(1)
		dword_5d4594_815708 = true
		if pl := asPlayer((*C.nox_playerInfo)(*memmap.PtrPtr(0x8531A0, 2576))); pl != nil {
			C.nox_xxx_netNeedTimestampStatus_4174F0(pl.C(), 64)
			var buf [1]byte
			buf[0] = byte(noxnet.MSG_NEED_TIMESTAMP)
			nox_xxx_netClientSend2_4E53C0(noxMaxPlayers-1, buf[:1], 0, 1)
		}
	}
}
