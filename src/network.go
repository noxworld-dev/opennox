package opennox

/*
#include "defs.h"
#include "nox_net.h"
#include "common__net_list.h"
#include "server__network__sdecode.h"
#include "GAME1_1.h"
#include "GAME5.h"
#include "GAME3_2.h"
#include "GAME4_2.h"
#include "GAME5_2.h"
#ifdef _WIN32
#include <windows.h>
#else
#include "windows_compat.h"
#endif
extern unsigned int dword_5d4594_2649712;
extern unsigned int dword_5d4594_2660032;
extern unsigned int dword_5d4594_814548;
extern unsigned int dword_5d4594_3843632;
extern unsigned int dword_5d4594_2495920;
extern unsigned long long qword_5d4594_814956;
extern nox_alloc_class* nox_alloc_gQueue_3844300;
extern nox_socket_t nox_xxx_sockLocalBroadcast_2513920;
extern nox_net_struct_t* nox_net_struct_arr[NOX_NET_STRUCT_MAX];
extern nox_net_struct2_t nox_net_struct2_arr[NOX_NET_STRUCT_MAX];
unsigned int nox_client_getServerAddr_43B300();
int nox_client_getServerPort_43B320();
int nox_client_getClientPort_40A420();
int sub_419E60(nox_object_t* a1);
int sub_43AF90(int a1);
int nox_xxx_netClientSend2_4E53C0(int a1, const void* a2, int a3, int a4, int a5);
void* nox_xxx_spriteGetMB_476F80();
int nox_xxx_netSendPacket_4E5030(int a1, const void* a2, signed int a3, int a4, int a5, char a6);
static int nox_xxx_netSendLineMessage_go(nox_object_t* a1, wchar_t* str) {
	return nox_xxx_netSendLineMessage_4D9EB0(a1, str);
}
int MixRecvFromReplacer(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr_in* from);

int nox_xxx_netHandlerDefXxx_553D60(unsigned int a1, char* a2, int a3, void* a4);
int nox_xxx_netHandlerDefYyy_553D70(unsigned int a1, char* a2, int a3, void* a4);

extern float nox_xxx_warriorMaxHealth_587000_312784;
extern float nox_xxx_warriorMaxMana_587000_312788;

extern float nox_xxx_conjurerMaxHealth_587000_312800;
extern float nox_xxx_conjurerMaxMana_587000_312804;

extern float nox_xxx_wizardMaxHealth_587000_312816;
extern float nox_xxx_wizardMaximumMana_587000_312820;

static int nox_call_net_xxxyyy_go(int (*fnc)(unsigned int, char*, int, void*), unsigned int a1, void* a2, int a3, void* a4) { return fnc(a1, a2, a3, a4); }

int nox_xxx_netBigSwitch_553210_op_14(int pid, uint8_t* out, unsigned char* packet, nox_net_struct_t* ns1, char p1, struct nox_net_sockaddr_in* from);
int nox_xxx_netBigSwitch_553210_op_18(uint8_t* out, unsigned char* packet, struct nox_net_sockaddr_in* from);
*/
import "C"
import (
	"context"
	"encoding/binary"
	"errors"
	"image"
	"math"
	"net"
	"time"
	"unsafe"

	"github.com/noxworld-dev/nat"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/platform"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/serial"
)

const (
	NOX_NET_STRUCT_MAX = 128
)

func init() {
	configBoolPtr("network.xor", "NOX_NET_XOR", true, &noxNetXor)
	configHiddenBoolPtr("debug.network", "NOX_DEBUG_NET", &debugNet)
}

var (
	noxNetXor            bool
	debugNet             bool
	netLog               = log.New("network")
	dword_5D4594_815700  int
	dword_5d4594_2496472 int
	dword_5d4594_2496988 int
	dword_5d4594_3844304 bool
	arr2508788           [NOX_NET_STRUCT_MAX]netTimingStruct
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
	netLog.Println(str)
	noxConsole.Print(console.ColorGreen, str)
}

//export nox_xxx_netGet_43C750
func nox_xxx_netGet_43C750() C.int { return C.int(dword_5D4594_815700) }

func newNetStruct() (*netStruct, func()) {
	return alloc.New(netStruct{})
}

func asNetStruct(ptr *C.nox_net_struct_t) *netStruct {
	return (*netStruct)(unsafe.Pointer(ptr))
}

func getNetStructByInd(i int) *netStruct {
	if i < 0 || i >= NOX_NET_STRUCT_MAX {
		return nil
	}
	return asNetStruct(C.nox_net_struct_arr[i])
}

func setNetStructByInd(i int, ns *netStruct) {
	if i < 0 || i >= NOX_NET_STRUCT_MAX {
		panic("out of bounds")
	}
	C.nox_net_struct_arr[i] = ns.C()
}

func getFreeNetStruct() int {
	for i := 0; i < NOX_NET_STRUCT_MAX; i++ {
		if C.nox_net_struct_arr[i] == nil {
			return i
		}
	}
	return -1
}

func nox_xxx_netStructByAddr_551E60(ip net.IP, port int) *netStruct {
	for i := 0; i < NOX_NET_STRUCT_MAX; i++ {
		ns := asNetStruct(C.nox_net_struct_arr[i])
		if ns == nil {
			continue
		}
		ip2, port2 := ns.Addr()
		if port == port2 && ip.Equal(ip2) {
			return ns
		}
	}
	return nil
}

type netStruct C.nox_net_struct_t

func (ns *netStruct) C() *C.nox_net_struct_t {
	return (*C.nox_net_struct_t)(unsafe.Pointer(ns))
}

func (ns *netStruct) FreeXxx() {
	if ns == nil {
		return
	}
	if ns.data_3 != nil {
		alloc.Free(unsafe.Pointer(ns.data_3))
	}
	alloc.Free(unsafe.Pointer(ns.data_1_base))
	alloc.Free(unsafe.Pointer(ns.data_2_base))
	C.CloseHandle(C.HANDLE(ns.mutex_yyy))
	C.CloseHandle(C.HANDLE(ns.mutex_xxx))
	alloc.Free(unsafe.Pointer(ns.C()))
}

func (ns *netStruct) Socket() *Socket {
	if ns == nil {
		return nil
	}
	return getSocket(ns.sock)
}

func (ns *netStruct) SetSocket(s *Socket) {
	ns.sock = newSocketHandle(s)
}

func (ns *netStruct) Addr() (net.IP, int) {
	if ns == nil {
		return nil, 0
	}
	return toIPPort(&ns.addr)
}

func (ns *netStruct) SetAddr(ip net.IP, port int) {
	setIPPort(&ns.addr, ip, port)
}

func (ns *netStruct) ID() int {
	if ns == nil {
		return -1
	}
	return int(ns.id)
}

func (ns *netStruct) Data1() []byte {
	if ns == nil {
		return nil
	}
	sz := int(uintptr(unsafe.Pointer(ns.data_1_end)) - uintptr(unsafe.Pointer(ns.data_1_base)))
	if sz < 0 {
		panic("negative size")
	}
	return unsafe.Slice((*byte)(unsafe.Pointer(ns.data_1_base)), sz)
}

func (ns *netStruct) Data2() []byte {
	if ns == nil {
		return nil
	}
	sz := int(uintptr(unsafe.Pointer(ns.data_2_end)) - uintptr(unsafe.Pointer(ns.data_2_base)))
	if sz < 0 {
		panic("negative size")
	}
	return unsafe.Slice((*byte)(unsafe.Pointer(ns.data_2_base)), sz)
}

func (ns *netStruct) Datax2() []byte {
	if ns == nil {
		return nil
	}
	sz := int(uintptr(unsafe.Pointer(ns.data_2_xxx)) - uintptr(unsafe.Pointer(ns.data_2_base)))
	if sz < 0 {
		panic("negative size")
	}
	return unsafe.Slice((*byte)(unsafe.Pointer(ns.data_2_base)), sz)
}

func (ns *netStruct) Data1xxx() []byte {
	if ns == nil {
		return nil
	}
	sz := int(uintptr(unsafe.Pointer(ns.data_1_end)) - uintptr(unsafe.Pointer(ns.data_1_xxx)))
	if sz < 0 {
		panic("negative size")
	}
	return unsafe.Slice((*byte)(unsafe.Pointer(ns.data_1_xxx)), sz)
}

func (ns *netStruct) Data1yyy() []byte {
	if ns == nil {
		return nil
	}
	sz := int(uintptr(unsafe.Pointer(ns.data_1_xxx)) - uintptr(unsafe.Pointer(ns.data_1_yyy)))
	if sz < 0 {
		panic("negative size")
	}
	return unsafe.Slice((*byte)(unsafe.Pointer(ns.data_1_yyy)), sz)
}

func (ns *netStruct) Data2xxx() []byte {
	if ns == nil {
		return nil
	}
	sz := int(uintptr(unsafe.Pointer(ns.data_2_end)) - uintptr(unsafe.Pointer(ns.data_2_xxx)))
	if sz < 0 {
		panic("negative size")
	}
	return unsafe.Slice((*byte)(unsafe.Pointer(ns.data_2_xxx)), sz)
}

func (ns *netStruct) callXxx(id int, buf []byte, data3 unsafe.Pointer) int {
	return int(C.nox_call_net_xxxyyy_go((*[0]byte)(ns.func_xxx), C.uint(id), unsafe.Pointer(&buf[0]), C.int(len(buf)), data3))
}

func (ns *netStruct) callYyy(id int, buf []byte, data3 unsafe.Pointer) int {
	switch unsafe.Pointer(ns.func_yyy) {
	case unsafe.Pointer(C.nox_xxx_netlist_ServRecv_4DEC30):
		return nox_xxx_netlist_ServRecv(id, buf)
	}
	return int(C.nox_call_net_xxxyyy_go((*[0]byte)(ns.func_yyy), C.uint(id), unsafe.Pointer(&buf[0]), C.int(len(buf)), data3))
}

func clientSetServerHost(host string) {
	netLog.Printf("server host: %s", host)
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

func nox_xxx_cryptXorDst(key byte, src, dst []byte) {
	if len(src) == 0 || len(dst) == 0 {
		return
	}
	netCryptDst(key, src, dst)
}

func netCryptXor(key byte, p []byte) {
	if len(p) == 0 || !noxNetXor {
		return
	}
	for i := range p {
		p[i] ^= key
	}
}

func netCryptDst(key byte, src, dst []byte) {
	if !noxNetXor {
		copy(dst, src)
		return
	}
	for i := range src {
		dst[i] = key ^ src[i]
	}
}

func nox_xxx_getMapCRC_40A370() int {
	return noxMapCRC
}

//export nox_xxx_setMapCRC_40A360
func nox_xxx_setMapCRC_40A360(crc C.int) {
	if debugNet {
		netLog.Printf("map crc set: %d", int(crc))
	}
	noxMapCRC = int(crc)
}

//export noxOnCliPacketDebug
func noxOnCliPacketDebug(op C.int, data *C.uchar, sz C.int) {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(data)), int(sz))
	if debugNet && sz != 0 {
		op := noxnet.Op(op)
		netLog.Printf("CLIENT: op=%d (%s) [%d:%d]\n%02x %x", int(op), op.String(), int(sz)-1, op.Len(), buf[0], buf[1:])
	}
}

//export noxOnSrvPacketDebug
func noxOnSrvPacketDebug(op C.int, data *C.uchar, sz C.int) {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(data)), int(sz))
	if debugNet && sz != 0 {
		op := noxnet.Op(op)
		netLog.Printf("SERVER: op=%d (%s) [%d:%d]\n%02x %x", int(op), op.String(), int(sz)-1, op.Len(), buf[0], buf[1:])
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
	netLog.Printf("join server: %s:%d", addr.String(), port)
	_, err := sendJoinGame(addr, port, buf)
	return err
}

//export sub_5550D0
func sub_5550D0(addr C.int, port C.uint16_t, cdata *C.char) C.int {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cdata)), 22)
	n, err := sendXXX_5550D0(int2ip(uint32(addr)), int(port), buf)
	return convSendToServerErr(n, err)
}

func sendJoinGame(addr net.IP, port int, data []byte) (int, error) {
	data[0] = 0
	data[1] = 0
	data[2] = 14 // 0x0E
	return sendToServer(addr, port, data)
}

func sendXXX_5550D0(addr net.IP, port int, data []byte) (int, error) {
	data[0] = 0
	data[1] = 0
	data[2] = 17 // 0x11
	return sendToServer(addr, port, data)
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

func nox_client_getServerAddr_43B300() net.IP {
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

type netStructOpt struct {
	field0    uint32
	field1    uint32
	port      int
	data3size int
	field4    int
	datasize  int
	field6    uint32
	field7    uint32
	funcxxx   unsafe.Pointer
	funcyyy   unsafe.Pointer
}

func (s *Server) nox_xxx_netAddPlayerHandler_4DEBC0(port int) (ind, cport int, _ error) {
	narg := &netStructOpt{
		port:      port,
		data3size: 0,
		field4:    s.getServerMaxPlayers(),
		datasize:  2048,
		funcyyy:   C.nox_xxx_netlist_ServRecv_4DEC30,
		funcxxx:   C.nox_xxx_netFn_UpdateStream_4DF630,
	}
	nox_xxx_allocNetGQueue_5520B0()
	ind, err := nox_xxx_netInit_554380(narg)
	if err != nil {
		return ind, 0, err
	}
	*memmap.PtrInt32(0x5D4594, 1563148) = int32(ind)
	return ind, narg.port, err
}

func nox_xxx_netPreStructToFull(narg *netStructOpt) (ind int, _ error) {
	if narg == nil {
		return -2, errors.New("empty options")
	}
	if narg.field0 != 0 {
		return -5, errors.New("not empty")
	}
	ind = getFreeNetStruct()
	if ind < 0 {
		return -8, errors.New("no more slots for net structs")
	}
	ns := nox_xxx_makeNewNetStruct(narg)
	setNetStructByInd(ind, ns)
	return ind, nil
}

var netSomePort uint16

//export sub_5545A0
func sub_5545A0() C.short {
	return C.short(netSomePort)
}

func nox_xxx_netInit_554380(narg *netStructOpt) (ind int, _ error) {
	if narg == nil {
		return -2, errors.New("empty options")
	}
	if narg.field0 != 0 {
		return -5, errors.New("not empty")
	}
	if narg.field4 > 128 {
		return -2, errors.New("max limit reached")
	}
	*memmap.PtrUint8(0x973F18, 44216) = 0
	*memmap.PtrUint8(0x973F18, 44232) = 0
	v2 := getFreeNetStruct()
	if v2 < 0 {
		return -8, errors.New("no more slots for net structs")
	}
	ns := nox_xxx_makeNewNetStruct(narg)
	setNetStructByInd(v2, ns)
	ns.Data2()[0] = byte(v2)
	ns.id = -1
	sock := newSocketUDP()
	ns.SetSocket(sock)

	if narg.port < 1024 || narg.port > 0x10000 {
		narg.port = 18590
	}

	netSomePort = uint16(narg.port)
	for {
		err := sock.Bind(nil, narg.port)
		if err == nil {
			break
		} else if !ErrIsInUse(err) {
			return 0, err
		}
		narg.port++
	}
	if ip, err := nat.ExternalIP(context.Background()); err == nil {
		C.dword_5d4594_3843632 = C.uint(ip2int(ip))
		StrCopyP(memmap.PtrOff(0x973F18, 44216), 16, ip.String())
	} else if ips, err := nat.InternalIPs(context.Background()); err == nil && len(ips) != 0 {
		ip = ips[0].IP
		C.dword_5d4594_3843632 = C.uint(ip2int(ip))
		StrCopyP(memmap.PtrOff(0x973F18, 44216), 16, ip.String())
	}
	return v2, nil
}

var zeroHandle C.HANDLE

func nox_xxx_makeNewNetStruct(arg *netStructOpt) *netStruct {
	ns, _ := newNetStruct()

	my := C.CreateMutexA(nil, 0, nil)
	if my == zeroHandle {
		panic("cannot create mutex")
	}
	ns.mutex_yyy = unsafe.Pointer(my)

	mx := C.CreateMutexA(nil, 0, nil)
	if mx == zeroHandle {
		panic("cannot create mutex")
	}
	ns.mutex_xxx = unsafe.Pointer(mx)
	if arg.data3size > 0 {
		p, _ := alloc.Make([]byte{}, arg.data3size)
		ns.data_3 = unsafe.Pointer(&p[0])
	}
	if dsz := arg.datasize; dsz > 0 {
		dsz -= dsz % 4
		arg.datasize = dsz
	} else {
		arg.datasize = 1024
	}
	data1, _ := alloc.Make([]byte{}, arg.datasize+2)
	ns.data_1_base = (*C.char)(unsafe.Pointer(&data1[0]))
	ns.data_1_xxx = (*C.char)(unsafe.Pointer(&data1[0]))
	ns.data_1_yyy = (*C.char)(unsafe.Pointer(&data1[0]))
	ns.data_1_end = (*C.char)(unsafe.Add(unsafe.Pointer(&data1[0]), len(data1)))

	data2, _ := alloc.Make([]byte{}, arg.datasize+2)
	data2[0] = 0xff
	ns.data_2_base = (*C.char)(unsafe.Pointer(&data2[0]))
	ns.data_2_xxx = (*C.char)(unsafe.Pointer(&data2[2]))
	ns.data_2_yyy = (*C.char)(unsafe.Pointer(&data2[2]))
	ns.data_2_end = (*C.char)(unsafe.Add(unsafe.Pointer(&data2[0]), len(data2)))

	ns.field_20 = C.uint(arg.field4)
	if arg.funcxxx != nil {
		ns.func_xxx = (*[0]byte)(arg.funcxxx)
	} else {
		ns.func_xxx = (*[0]byte)(C.nox_xxx_netHandlerDefXxx_553D60)
	}
	if arg.funcyyy != nil {
		ns.func_yyy = (*[0]byte)(arg.funcyyy)
	} else {
		ns.func_yyy = (*[0]byte)(C.nox_xxx_netHandlerDefYyy_553D70)
	}
	ns.field_28_1 = -1
	ns.xor_key = 0
	return ns
}

func (s *Server) nox_server_netClose_5546A0(i int) {
	if ns := getNetStructByInd(i); ns != nil {
		_ = ns.Socket().Close()
		ns.SetSocket(nil)
		ns.FreeXxx()
		setNetStructByInd(i, nil)
	}
}

//export nox_xxx_netStructReadPackets_5545B0
func nox_xxx_netStructReadPackets_5545B0(ind C.uint) C.int {
	return C.int(noxServer.nox_xxx_netStructReadPackets(int(ind)))
}

func (s *Server) nox_xxx_netStructReadPackets(ind int) int {
	if ind < 0 || ind >= NOX_NET_STRUCT_MAX {
		return -3
	}
	ns := getNetStructByInd(ind)
	if ns == nil {
		return 0
	}
	v4 := ns.ID()
	v1 := ind
	var si, ei int
	if v4 == -1 {
		si, ei = 0, NOX_NET_STRUCT_MAX
		v4 = v1
	} else {
		si, ei = ind, ind+1
		ns2 := getNetStructByInd(v4)
		if ns2 == nil || ns2.id != -1 {
			ns.FreeXxx()
			setNetStructByInd(v1, nil)
			return 0
		}
	}
	for i := si; i < ei; i++ {
		ns2 := getNetStructByInd(i)
		if ns2 == nil || ns2.ID() != v4 {
			continue
		}
		nox_xxx_netSendReadPacket_5528B0(i, 1)
		var buf [1]byte
		buf[0] = 11
		nox_xxx_netSendSock552640(i, buf[:], 0)
		nox_xxx_netSendReadPacket_5528B0(i, 1)
		getNetStructByInd(v4).field_21--
		C.sub_555360(C.uint(v1), 0, 2)
		ns2.FreeXxx()
		setNetStructByInd(i, nil)
	}
	return 0
}

func (s *Server) nox_xxx_netStructReadPackets2_4DEC50(a1 int) int {
	return s.nox_xxx_netStructReadPackets(a1 + 1)
}

//export nox_xxx_netlist_ServRecv_4DEC30
func nox_xxx_netlist_ServRecv_4DEC30(a1 C.int, a2 *C.uchar, a3 C.int, a4 unsafe.Pointer) C.int {
	return C.int(nox_xxx_netlist_ServRecv(int(a1), unsafe.Slice((*byte)(a2), int(a3))))
}
func nox_xxx_netlist_ServRecv(a1 int, a2 []byte) int {
	// should pass the pointer unchanged, otherwise expect bugs!
	nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_raw(a1-1, a2)
	return 1
}

const (
	NOX_NET_SEND_NO_LOCK = 0x1
	NOX_NET_SEND_FLAG2   = 0x2
)

//export nox_xxx_netSendSock_552640
func nox_xxx_netSendSock_552640(id int, ptr *byte, sz int, flags int) int {
	n, _ := nox_xxx_netSendSock552640(id, unsafe.Slice(ptr, sz), flags)
	return n
}

func nox_xxx_netSendSock552640(id int, buf []byte, flags int) (int, error) {
	ns := getNetStructByInd(id)
	if ns == nil {
		return -3, errors.New("no net struct")
	}
	if len(buf) == 0 {
		return -2, errors.New("empty buffer")
	}
	var (
		idd    int
		ei, si int
	)
	if ns.id == -1 {
		ei = NOX_NET_STRUCT_MAX
		si = 0
		idd = id
	} else {
		si = id
		ei = id + 1
		idd = ns.ID()
	}
	if flags&NOX_NET_SEND_NO_LOCK != 0 {
		n := len(buf)
		for i := si; i < ei; i++ {
			ns2 := getNetStructByInd(i)
			if ns2 != nil && ns2.ID() == idd {
				v12, err := sub555130(i, buf)
				if v12 == -1 {
					return -1, err
				}
				n = v12
				if flags&NOX_NET_SEND_FLAG2 != 0 {
					nox_xxx_netSend_5552D0(i, byte(v12), true)
				}
			}
		}
		return n, nil
	}
	n := len(buf)
	for i := si; i < ei; i++ {
		ns2 := getNetStructByInd(i)
		if ns2 == nil {
			continue
		}
		if ns2.ID() != idd {
			continue
		}
		d2b := ns2.Data2()
		d2x := ns2.Data2xxx()
		if n+1 > len(d2x) {
			return -7, errors.New("buffer too short")
		}
		v14 := int32(C.WaitForSingleObject(C.HANDLE(ns2.mutex_yyy), 0x3E8))
		if v14 == -1 || v14 == 258 {
			return -16, errors.New("cannot wait for object")
		}
		if flags&NOX_NET_SEND_FLAG2 != 0 {
			copy(d2x[:2], d2b[:2])
			copy(d2x[2:2+n], buf)
			ip, port := ns2.Addr()
			n2, err := nox_xxx_sendto551F90(ns2.Socket(), d2x[:n+2], ip, port)
			if n2 == -1 {
				return -1, err
			}
			sub_553F40(n+2, 1)
			nox_xxx_netCountData_554030(n+2, i)
			C.ReleaseMutex(C.HANDLE(ns2.mutex_yyy))
			return n2, nil
		}
		copy(d2x[:n], buf)
		ns2.data_2_xxx = (*C.char)(unsafe.Pointer(&d2x[n]))
		if C.ReleaseMutex(C.HANDLE(ns2.mutex_yyy)) == 0 {
			C.ReleaseMutex(C.HANDLE(ns2.mutex_yyy))
		}
	}
	return n, nil
}

func nox_xxx_netCountData_554030(n int, ind int) {
	*memmap.PtrUint32(0x5D4594, 2498024+4*uintptr(ind)) += uint32(n)
}

//export sub_553F40
func sub_553F40(a1, a2 int) {
	cnt2495952 += uint32(a1)
	cnt2495956 += uint32(a2)
	i := memmap.Uint32(0x5D4594, 2497504)
	j := memmap.Uint32(0x5D4594, 2498020)
	*memmap.PtrUint32(0x5D4594, 2496992+4*uintptr(i)) = uint32(a1)
	*memmap.PtrUint32(0x5D4594, 2497508+4*uintptr(j)) = uint32(a2)
	*memmap.PtrUint32(0x5D4594, 2497504) = uint32(dword_5d4594_2496472+1) % 128
	*memmap.PtrUint32(0x5D4594, 2498020) = uint32(dword_5d4594_2496988+1) % 128
}

//export sub_555130
func sub_555130(a1 int, a2 unsafe.Pointer, a3 int) int {
	n, _ := sub555130(a1, unsafe.Slice((*byte)(a2), a3))
	return n
}

func sub555130(a1 int, buf []byte) (int, error) {
	if len(buf) > int(memmap.Int32(0x5D4594, 2512884)) {
		return -1, errors.New("buffer too large")
	}
	if len(buf) == 0 {
		return -1, errors.New("empty buffer")
	}
	ns := getNetStructByInd(a1)
	if ns == nil {
		return -3, errors.New("no net struct")
	}
	v5p := alloc.AsClass(unsafe.Pointer(C.nox_alloc_gQueue_3844300)).NewObject()
	if v5p == nil {
		return -1, errors.New("cannot alloc gqueue")
	}
	v5 := unsafe.Slice((*uint32)(v5p), 5)
	v5b := unsafe.Slice((*byte)(v5p), 22+len(buf))
	v5[0] = uint32(uintptr(ns.field_29))
	ns.field_29 = v5p

	v5[3] = 1
	v5[4] = uint32(len(buf) + 2)
	v5b[20] = ns.Data2()[0] | 0x80
	v5b[21] = byte(ns.field_28_0)
	ns.field_28_0++
	copy(v5b[22:], buf)
	return int(v5b[21]), nil
}

//export nox_xxx_sendto_551F90
func nox_xxx_sendto_551F90(s nox_socket_t, buf *C.char, sz C.int, to *C.struct_nox_net_sockaddr_in) C.int {
	ip, port := toIPPort(to)
	n, err := nox_xxx_sendto551F90(getSocket(s), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz)), ip, port)
	if err != nil {
		return -1
	}
	return C.int(n)
}

var sendXorBuf [4096]byte

func nox_xxx_sendto551F90(s *Socket, buf []byte, ip net.IP, port int) (int, error) {
	ns := nox_xxx_netStructByAddr_551E60(ip, port)
	if ns == nil {
		return s.SendTo(buf, ip, port)
	}
	if ns.xor_key == 0 {
		return s.SendTo(buf, ip, port)
	}
	dst := sendXorBuf[:len(buf)]
	nox_xxx_cryptXorDst(byte(ns.xor_key), buf, dst)
	return s.SendTo(dst, ip, port)
}

func nox_xxx_netSend_5552D0(ind int, a2 byte, a3 bool) int {
	ns := getNetStructByInd(ind)
	if ns == nil {
		return -3
	}
	for it := unsafe.Pointer(ns.field_29); it != nil; it = *(*unsafe.Pointer)(it) {
		gb := unsafe.Slice((*byte)(it), 22)
		gi := unsafe.Slice((*uint32)(it), 5)
		if a3 {
			if gb[21] == a2 {
				sz := int(gi[4])
				gi[3] = 0
				gi[1] = uint32(C.dword_5d4594_2495920) + 2000
				gb := unsafe.Slice((*byte)(it), 22+sz)
				ip, port := ns.Addr()
				if _, err := nox_xxx_sendto551F90(ns.Socket(), gb[20:20+sz], ip, port); err != nil {
					netLog.Println(err)
					return 0
				}
			}
		} else if gi[3] != 0 {
			sz := int(gi[4])
			gi[3] = 0
			gi[1] = uint32(C.dword_5d4594_2495920) + 2000
			gb := unsafe.Slice((*byte)(it), 22+sz)
			ip, port := ns.Addr()
			if _, err := nox_xxx_sendto551F90(ns.Socket(), gb[20:20+sz], ip, port); err != nil {
				netLog.Println(err)
				return 0
			}
		}
	}
	return 0
}

func nox_xxx_netSendClientReady_43C9F0() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_CLIENT_READY)
	nox_xxx_netSendSock552640(dword_5D4594_815700, data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	return 1
}

func nox_xxx_netKeepAliveSocket_43CA20() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_KEEP_ALIVE)
	nox_xxx_netSendSock552640(dword_5D4594_815700, data[:], NOX_NET_SEND_FLAG2)
	return 1
}

func nox_xxx_netRequestMap_43CA50() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_REQUEST_MAP)
	nox_xxx_netSendSock552640(dword_5D4594_815700, data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	return 1
}

func nox_xxx_netMapReceived_43CA80() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_RECEIVED_MAP)
	nox_xxx_netSendSock552640(dword_5D4594_815700, data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	return 1
}

func nox_xxx_cliSendCancelMap_43CAB0() int {
	id := dword_5D4594_815700
	var data [1]byte
	data[0] = byte(noxnet.MSG_CANCEL_MAP)
	v0, _ := nox_xxx_netSendSock552640(id, data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	if nox_xxx_cliWaitServerResponse_5525B0(id, v0, 20, 6) != 0 {
		return 0
	}
	nox_netlist_resetByInd_40ED10(noxMaxPlayers-1, 0)
	return 1
}

func nox_xxx_netSendIncomingClient_43CB00() int {
	id := dword_5D4594_815700
	var data [1]byte
	data[0] = byte(noxnet.MSG_INCOMING_CLIENT)
	v0, _ := nox_xxx_netSendSock552640(id, data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	if nox_xxx_cliWaitServerResponse_5525B0(id, v0, 20, 6) != 0 {
		return 0
	}
	nox_netlist_resetByInd_40ED10(noxMaxPlayers-1, 0)
	return 1
}

func nox_xxx_cliSendOutgoingClient_43CB50() int {
	id := dword_5D4594_815700
	var data [1]byte
	data[0] = byte(noxnet.MSG_OUTGOING_CLIENT)
	v0, _ := nox_xxx_netSendSock552640(id, data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	if nox_xxx_cliWaitServerResponse_5525B0(id, v0, 20, 6) != 0 {
		return 0
	}
	nox_xxx_servNetInitialPackets_552A80(id, 3)
	nox_netlist_resetByInd_40ED10(noxMaxPlayers-1, 0)
	return 1
}

func nox_xxx_cliWaitServerResponse_5525B0(a1 int, a2 int, a3 int, flags int) int {
	if debugNet {
		netLog.Printf("nox_xxx_cliWaitServerResponse_5525B0: %d, %d, %d, %d\n", a1, a2, a3, flags)
	}
	if a1 >= NOX_NET_STRUCT_MAX {
		return -3
	}
	ns := getNetStructByInd(a1)
	if ns == nil {
		return -3
	}

	if int(ns.field_28_1) >= a2 {
		return 0
	}
	for v6 := 0; v6 <= 20*a3; v6++ {
		platform.Sleep(50 * time.Millisecond)
		nox_xxx_servNetInitialPackets_552A80(a1, flags|1)
		nox_xxx_netMaybeSendAll_552460()
		if int(ns.field_28_1) >= a2 {
			return 0
		}
		// FIXME(awesie)
		return 0
	}
	return -23
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
		nox_xxx_netSendSock552640(a1, v3, 0)
		nox_xxx_netSendReadPacket_5528B0(a1, 1)
	}
}

func sub_553FC0(a1, a2 int) {
	cnt2495944 += uint32(a1)
	cnt2495948 += uint32(a2)
	*memmap.PtrUint32(0x5D4594, 2495960+4*uintptr(dword_5d4594_2496472)) = uint32(a1)
	*memmap.PtrUint32(0x5D4594, 2496476+4*uintptr(dword_5d4594_2496988)) = uint32(a2)
	dword_5d4594_2496472 = (dword_5d4594_2496472 + 1) % 128
	dword_5d4594_2496988 = (dword_5d4594_2496988 + 1) % 128
}

func sub_551E00(ind int, ip net.IP, port int) bool {
	for i := 0; i < NOX_NET_STRUCT_MAX; i++ {
		ns := asNetStruct(C.nox_net_struct_arr[i])
		if ns == nil {
			continue
		}
		ip2, port2 := ns.Addr()
		if port == port2 && ip.Equal(ip2) && ind == i {
			return true
		}
	}
	return false
}

func nox_server_makeServerInfoPacket_554040(src, dst []byte) int {
	csrc, free := alloc.Make([]byte{}, len(src))
	defer free()
	copy(csrc, src)
	return int(C.nox_server_makeServerInfoPacket_554040((*C.char)(unsafe.Pointer(&src[0])), C.int(len(src)), (*C.char)(unsafe.Pointer(&dst[0]))))
}

func nox_xxx_servNetInitialPackets_552A80(id int, flags int) int {
	if id >= NOX_NET_STRUCT_MAX {
		return -3
	}
	ns := getNetStructByInd(id)
	if ns == nil {
		return -3
	}
	nsock := ns.Socket()
	ns2 := ns

	argp := 1
	var err error
	if flags&1 != 0 {
		argp, err = nsock.CanRead()
		if err != nil || argp == 0 {
			return -1
		}
	}
	buf, bfree := alloc.Make([]byte{}, 256)
	defer bfree()

	v26 := 1
	for {
		n, src := nox_xxx_netRecv_552020(ns.sock, nsock, ns.Data1xxx())
		if n == -1 {
			return -1
		}
		ip, port := getAddr(src)
		sub_553FC0(n, 1)
		if n < 3 {
			ns.data_1_yyy = ns.data_1_base
			ns.data_1_xxx = ns.data_1_base
			if flags&1 == 0 || flags&4 != 0 {
				return n
			}
			argp, err = nsock.CanRead()
			if err != nil {
				return -1
			} else if argp == 0 {
				return n
			}
			continue
		}
		ns.data_1_xxx = (*C.char)(unsafe.Add(unsafe.Pointer(ns.data_1_xxx), n))
		hdr := ns.Data1yyy()[:3]
		id2 := int(hdr[0])
		v9 := hdr[1]
		op := noxnet.Op(hdr[2])
		if debugNet {
			netLog.Printf("servNetInitialPackets: op=%d (%s)\n", int(op), op.String())
		}
		if op == noxnet.MSG_SERVER_DISCOVER {
			// received a lobby info request from the client
			if nox_xxx_check_flag_aaa_43AF70() == 0 {
				// send server info packet
				n = nox_server_makeServerInfoPacket_554040(ns.Data1yyy(), buf)
				if n > 0 {
					n, _ = nsock.WriteTo(buf[:n], &net.UDPAddr{IP: ip, Port: port})
					sub_553F40(n, 1)
				}
			}
			ns.data_1_yyy = ns.data_1_base
			ns.data_1_xxx = ns.data_1_base
			if flags&1 == 0 || flags&4 != 0 {
				return n
			}
			argp, err = nsock.CanRead()
			if err != nil {
				return -1
			} else if argp == 0 {
				return n
			}
			continue
		}
		if op >= noxnet.MSG_SERVER_JOIN && op <= noxnet.MSG_SERVER_JOIN_OK {
			v26 = 1
		} else {
			if id2 == 255 {
				if v26 != 1 {
					goto LABEL_48
				}
			} else {
				v26 = 0
				if !sub_551E00(id2&127, ip, port) {
					goto LABEL_48
				}
				v26 = 1
			}
			if ns.id == -1 {
				ns2 = getNetStructByInd(id2 & 127)
			}
			if id2&NOX_NET_STRUCT_MAX == 0 {
				if ns2 == nil {
					goto LABEL_48
				}
				if v9 != byte(ns2.field_28_1) {
					sub_5551F0(id2, v9, 1)
					C.sub_555360(C.uint(id2), C.uchar(v9), 1)
					ns2.field_28_1 = C.char(v9)
					v20 := 0
					if nox_xxx_netRead2Xxx_551EB0(id, id2, v9, ns.Data1yyy()) {
						v20 = 0
					} else {
						v20 = 1
					}
					buf[0] = 38
					buf[1] = byte(ns2.field_28_1)
					ns.callYyy(id2, buf[:2], ns2.data_3)
					if v20 == 0 {
						goto LABEL_48
					}
				}
			} else if id2 == 255 {
				if op == 0 {
					data := ns.Data1yyy()
					n = nox_xxx_netBigSwitch_553210(id, data, buf, src)
					if n > 0 {
						n, _ = nox_xxx_sendto551F90(nsock, buf[:n], ip, port)
						sub_553F40(n, 1)
					}
					goto LABEL_48
				}
			} else {
				data := ns.Data1yyy()
				data[0] &= 127
				id2 = int(data[0])
				if ns2 == nil {
					goto LABEL_48
				}
				data2 := ns2.Data2()
				if data2[1] != v9 {
					goto LABEL_48
				}
				data2[1]++
				if nox_xxx_netRead2Xxx_551EB0(id, id2, v9, ns.Data1yyy()) {
					goto LABEL_48
				}
			}
		}
		if op < 32 {
			data := ns.Data1yyy()
			n = nox_xxx_netBigSwitch_553210(id, data, buf, src)
			if n > 0 {
				n, _ = nox_xxx_sendto551F90(nsock, buf[:n], ip, port)
				sub_553F40(n, 1)
			}
		} else {
			if ns2 != nil && flags&2 == 0 {
				data := ns.Data1yyy()[2:n]
				ns.callYyy(id2, data, ns2.data_3)
			}
		}
	LABEL_48:
		ns.data_1_yyy = ns.data_1_base
		ns.data_1_xxx = ns.data_1_base
		if flags&1 == 0 || flags&4 != 0 {
			return n
		}
		argp, err = nsock.CanRead()
		if err != nil {
			return -1
		} else if argp == 0 {
			return n
		}
	}
	// unreachable
}

func nox_xxx_netRead2Xxx_551EB0(id1, id2 int, a3 byte, buf []byte) bool {
	ns2 := getNetStructByInd(id2)
	if ns2 == nil || ns2.field_38 != 1 || byte(ns2.data_39[0]) > a3 {
		return false
	}
	ns1 := getNetStructByInd(id1)
	if int(ns1.field_21) > (noxServer.getServerMaxPlayers() - 1) {
		noxServer.nox_xxx_netStructReadPackets(id2)
		return true
	}
	if len(buf) >= 4 && buf[4] == 32 {
		ns2.field_38 = 2
		ns2.data_39[0] = 0xff
		ns2.field_40 = 0
		ns1.callYyy(id2, buf[4:], ns2.data_3)
	}
	return true
}

func nox_xxx_netRecv_552020(cs nox_socket_t, s *Socket, buf []byte) (int, net.Addr) {
	n, src, err := mix_recvfrom(cs, s, buf)
	if err == nil {
		ip, port := getAddr(src)
		ns := nox_xxx_netStructByAddr_551E60(ip, port)
		if ns != nil {
			if ns.xor_key != 0 {
				netCryptXor(byte(ns.xor_key), buf[:n])
			}
		}
	}
	if noxflags.HasGame(noxflags.GameHost) {
		return n, src
	}

	r := randomIntMinMax(1, 99)
	if r >= int(memmap.Int32(0x5D4594, 2495940)) {
		return n, src
	}
	return 0, src
}

func mix_recvfrom(cs nox_socket_t, s *Socket, buf []byte) (int, net.Addr, error) {
	n, src, err := s.pc.ReadFrom(buf)
	if err != nil {
		return n, src, err
	}
	ip, port := getAddr(src)
	if debugNet {
		netLog.Printf("recv %s:%d -> %s [%d]\n%x", ip, port, s.pc.LocalAddr(), n, buf[:n])
	}
	if n >= 2 && binary.LittleEndian.Uint16(buf[:2]) == 0xF13A { // extension packet code
		n = MixRecvFromReplacer(cs, buf, src)
		return n, src, nil
	}
	return n, src, nil
}

func MixRecvFromReplacer(cs nox_socket_t, buf []byte, from net.Addr) int {
	caddr, afree := alloc.New(C.struct_nox_net_sockaddr_in{})
	defer afree()
	setAddr(caddr, from)
	return int(C.MixRecvFromReplacer(cs, (*C.char)(unsafe.Pointer(&buf[0])), C.int(len(buf)), caddr))
}

func nox_xxx_netBigSwitch_553210(id int, packet []byte, out []byte, from net.Addr) int {
	if len(packet) < 2 {
		return 0
	}
	pid := int(int8(packet[0]))
	p1 := packet[1]
	packetCur := packet[2:]

	ns1 := getNetStructByInd(id)
	if ns1 == nil {
		return 0
	}

	caddr, afree := alloc.New(C.struct_nox_net_sockaddr_in{})
	defer afree()
	setAddr(caddr, from)

	pidb := pid // TODO: some of the functions assume it's different from pid, check what's wrong
	for len(packetCur) != 0 {
		op := packetCur[0]
		packetCur = packetCur[1:]
		if debugNet {
			netLog.Printf("nox_xxx_netBigSwitch_553210: op=%d [%d]\n", op, len(packetCur))
		}
		switch op {
		default:
			return 0
		case 0:
			return nox_xxx_netBigSwitch_553210_op_0(id, out, pidb, p1, ns1, from)
		case 1:
			if len(packetCur) < 5 {
				return 0
			}
			v11 := binary.LittleEndian.Uint32(packetCur[:4])
			xor := packetCur[4]
			packetCur = packetCur[5:]

			ns1.id = C.int(v11)
			*ns1.data_2_base = C.char(v11)
			ns1.xor_key = C.uchar(xor)
			dword_5d4594_3844304 = true
		case 2:
			ns1.id = -18
			dword_5d4594_3844304 = true
		case 3: // ack?
			ns1.id = -12
			dword_5d4594_3844304 = true
		case 4:
			ns1.id = -13
			dword_5d4594_3844304 = true
		case 5:
			if len(packetCur) < 4 {
				return 0
			}
			v := binary.LittleEndian.Uint32(packetCur[:4])
			out[0] = byte(ns1.xor_key)
			out[1] = 0
			out[2] = 7
			binary.LittleEndian.PutUint32(out[3:], v)
			return 7
		case 6:
			return nox_xxx_netBigSwitch_553210_op_6(pid, out, ns1, packetCur)
		case 7:
			return nox_xxx_netBigSwitch_553210_op_7(pid, out, ns1)
		case 8:
			return nox_xxx_netBigSwitch_553210_op_8(pid, out, ns1, packetCur)
		case 9:
			return nox_xxx_netBigSwitch_553210_op_9(pid, packetCur)
		case 10:
			return nox_xxx_netBigSwitch_553210_op_10(id, pid, out, ns1)
		case 11:
			ns7 := getNetStructByInd(pid)
			if ns7 == nil {
				return 0
			}
			out[0] = 33
			ns1.callYyy(pid, out[:1], ns7.data_3)
			sub_554A50(id)
			return 0
		case 14: // join game request?
			return int(C.nox_xxx_netBigSwitch_553210_op_14(C.int(pid), (*C.uchar)(unsafe.Pointer(&out[0])), (*C.uchar)(unsafe.Pointer(&packet[0])), ns1.C(), C.char(p1), caddr))
		case 17:
			return nox_xxx_netBigSwitch_553210_op_17(out, packet, p1, from)
		case 18:
			return int(C.nox_xxx_netBigSwitch_553210_op_18((*C.uchar)(unsafe.Pointer(&out[0])), (*C.uchar)(unsafe.Pointer(&packet[0])), caddr))
		case 31:
			if len(packetCur) < 1 {
				return 0
			}
			v14 := packetCur[0]
			packetCur = packetCur[1:]

			ns8 := getNetStructByInd(pidb)
			if ns8 == nil {
				return 0
			}
			netLog.Printf("switch 31: 0x%x 0x%x\n", v14, ns8.field_28_1)
			if v14 != byte(ns8.field_28_1) {
				sub_5551F0(pid, v14, 1)
				C.sub_555360(C.uint(pid), C.uchar(v14), 1)
				ns8.field_28_1 = C.char(v14)
				out[0] = 38
				out[1] = v14
				ns1.callYyy(pid, out[:2], ns8.data_3)
			}
		}
	}
	return 0
}

type netTimingStruct struct {
	field0  uint32
	field4  uint32
	field8  [5]uint32
	field28 uint32
}

func nox_xxx_netBigSwitch_553210_op_0(id int, out []byte, pid int, p1 byte, ns1 *netStruct, from net.Addr) int {
	if noxflags.HasGame(noxflags.GameHost) && noxflags.HasGame(noxflags.GameFlag4) {
		return 0
	}
	out[0] = 0
	out[1] = p1
	if int(ns1.field_21) >= noxServer.getServerMaxPlayers()+int(memmap.Uint8(0x5D4594, 2500076)-1) {
		out[2] = 2
		return 3
	}
	if pid != -1 {
		netLog.Printf("pid must be set to -1 when joining: was %d (%s)\n", pid, from.String())
		// pid in the request must be -1 (0xff); fail if it's not
		out[2] = 2
		return 3
	}
	ip, port := getAddr(from)
	// now, find free net struct index and use it as pid
	for i := 0; i < NOX_NET_STRUCT_MAX; i++ {
		ns9 := asNetStruct(C.nox_net_struct_arr[i])
		if ns9 == nil {
			pid = i
			break
		}
		ip2, port2 := ns9.Addr()
		if port == port2 && ip.Equal(ip2) {
			netLog.Printf("already joined: %s\n", from.String())
			out[2] = 4 // already joined?
			return 3
		}
	}
	if pid == -1 {
		out[2] = 2
		return 3
	}
	data1 := ns1.Data2()
	ns10 := nox_xxx_makeNewNetStruct(&netStructOpt{
		data3size: 4,
		datasize:  len(data1),
	})
	setNetStructByInd(pid, ns10)
	ns1.field_21++

	data1 = ns10.Data2()
	data1[0] = byte(id)
	if data1[1] == p1 {
		data1[1]++
	}
	ns10.id = C.int(id)
	ns10.sock = ns1.sock
	ns10.func_xxx = ns1.func_xxx
	ns10.func_yyy = ns1.func_yyy

	arr2508788[id] = netTimingStruct{field28: 1}
	key := byte(noxRndCounter1.IntClamp(1, 255))
	if !noxNetXor {
		key = 0
	}
	ns10.xor_key = 0 // send this packet without xor encoding

	ns10.SetAddr(ip, port)

	out[0] = 31
	out[1] = p1
	out[2] = 1
	binary.LittleEndian.PutUint32(out[3:], uint32(pid))
	out[7] = key
	v67, _ := nox_xxx_netSendSock552640(pid, out[:8], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)

	ns10.xor_key = C.uchar(key)
	ns10.field_38 = 1
	ns10.data_39[0] = C.uchar(v67)
	ns10.field_40 = C.uint(gameFrame())
	return 0
}

func nox_xxx_netBigSwitch_553210_op_6(pid int, out []byte, ns1 *netStruct, packetCur []byte) int {
	if len(packetCur) < 4 {
		return 0
	}
	v := binary.LittleEndian.Uint32(packetCur[:4])

	ns2 := getNetStructByInd(pid)
	if ns2 == nil {
		return 0
	}
	out[0] = 37
	ns1.callYyy(pid, out[:1], ns2.data_3)

	arr2508788[pid].field4 = v
	var v18 []byte
	if ns1.id == -1 {
		out[0] = byte(ns2.id)
		v18 = ns2.Data2()
	} else {
		out[0] = byte(ns1.id)
		v18 = ns1.Data2()
	}
	out[1] = v18[0]
	out[2] = 8
	binary.LittleEndian.PutUint32(out[3:], v)
	return 7
}

func nox_xxx_netBigSwitch_553210_op_7(pid int, out []byte, ns1 *netStruct) int {
	ns4 := getNetStructByInd(pid)
	if ns4 == nil && ns4.field_25 == 0 {
		return 0
	}
	v31 := int(C.dword_5d4594_2495920) - int(ns4.field_26) - int(ns4.field_24)
	v32 := -1
	if v31 >= 1 {
		v32 = 256000 / v31
	}
	out[0] = 35
	binary.LittleEndian.PutUint32(out[1:], uint32(v32))
	if ns1.id == -1 {
		ns1.callYyy(pid, out[:5], ns4.data_3)
	} else {
		ns1.callYyy(pid, out[:5], ns1.data_3)
	}
	return 0
}

func nox_xxx_netBigSwitch_553210_op_8(pid int, out []byte, ns1 *netStruct, packetCur []byte) int {
	ns5 := getNetStructByInd(pid)
	if ns5 == nil && binary.LittleEndian.Uint32(packetCur) != uint32(ns5.field_22) {
		return 0
	}
	ns5.field_24 = C.uint(int(C.dword_5d4594_2495920) - int(ns5.field_23))
	out[0] = 36
	binary.LittleEndian.PutUint32(out[1:], uint32(ns5.field_24))
	var v19 unsafe.Pointer
	if ns1.id == -1 {
		v19 = ns5.data_3
	} else {
		v19 = ns1.data_3
	}
	ns1.callYyy(pid, out[:5], v19)

	out[0] = ns1.Data2()[0]
	out[1] = ns5.Data2()[1]
	out[2] = 9
	binary.LittleEndian.PutUint32(out[3:], uint32(C.dword_5d4594_2495920))
	return 7
}

func nox_xxx_netBigSwitch_553210_op_9(pid int, packetCur []byte) int {
	if len(packetCur) < 4 {
		return 0
	}
	v := binary.LittleEndian.Uint32(packetCur[:4])
	p := &arr2508788[pid]
	dv := v - p.field4
	if dv <= 0 || dv >= 1000 {
		return 0
	}
	ind := p.field0
	p.field8[ind] = dv
	v26 := (ind + 1) % 5
	v27 := v26
	if v26 == 0 {
		for _, vv := range p.field8 {
			v26 += vv
		}
		p.field28 = v26 / uint32(len(p.field8))
	}
	p.field0 = v27
	return 0
}

func nox_xxx_netBigSwitch_553210_op_10(id int, pid int, out []byte, ns1 *netStruct) int {
	if pid == -1 {
		return 0
	}
	ns6 := getNetStructByInd(pid)
	if ns6 == nil || ns6.field_38 == 1 {
		return 0
	}
	out[0] = 34
	ns1.callYyy(pid, out[:1], ns6.data_3)

	arr2508788[id] = netTimingStruct{}

	v69 := nox_xxx_findPlayerID_5541D0(pid)
	if v69 != nil {
		C.sub_425920(v69)
		C.free(unsafe.Pointer(v69))
		*memmap.PtrUint8(0x5D4594, 2500076)--
	}
	noxServer.nox_xxx_netStructReadPackets(pid)
	return 0
}

//export sub_553D10
func sub_553D10() int {
	for i := 0; i < NOX_NET_STRUCT_MAX; i++ {
		if C.nox_net_struct2_arr[i].field_0 == 0 {
			return i
		}
	}
	return -1
}

func nox_xxx_netBigSwitch_553210_op_17(out []byte, packet []byte, p1 byte, from net.Addr) int {
	v33 := sub_416640()
	out[0] = 0
	out[1] = p1
	if GoWStringBytes(packet[4:]) != GoWStringBytes(v33[39:]) {
		out[2] = 19
		out[3] = 6
		return 4
	}
	if *(*int16)(unsafe.Pointer(&v33[105])) == -1 && *(*int16)(unsafe.Pointer(&v33[107])) == -1 {
		out[2] = 20
		return 3
	}
	id53 := sub_553D10()
	if id53 < 0 {
		out[2] = 20
		return 3
	}
	nx1 := &C.nox_net_struct2_arr[id53]
	nx1.field_0 = 1
	nx1.field_1_1 = 0
	nx1.field_1_0 = 0
	setAddr(&nx1.addr, from)

	return copy(out, nox_xxx_makePacketTime_552340(id53))
}

//export sub_554240
func sub_554240(a1 int) int {
	if a1 != 31 {
		return int(arr2508788[1+a1].field28)
	}
	return int(nox_ctrlevent_add_ticks_42E630())
}

func sub_554A50(ind int) int {
	if ind >= NOX_NET_STRUCT_MAX {
		return -3
	}
	if ns := getNetStructByInd(ind); ns != nil {
		_ = ns.Socket().Close()
		ns.FreeXxx()
		setNetStructByInd(ind, nil)
	}
	return 0
}

func sub_5549F0(ind int) int {
	if ind >= NOX_NET_STRUCT_MAX {
		return -3
	}
	if getNetStructByInd(ind) != nil {
		nox_xxx_netSendReadPacket_5528B0(ind, 0)
		var buf [1]byte
		buf[0] = 10
		nox_xxx_netSendSock552640(ind, buf[:1], 0)
		nox_xxx_netSendReadPacket_5528B0(ind, 0)
		sub_554A50(ind)
	}
	return 0
}

func sub_43CC80() {
	sub_5549F0(int(nox_xxx_netGet_43C750()))
	C.dword_5d4594_2649712 = 0
}

func sub_5524C0() {
	C.dword_5d4594_2495920 = C.uint(platformTicks())
	for i := 0; i < NOX_NET_STRUCT_MAX; i++ {
		ns := asNetStruct(C.nox_net_struct_arr[i])
		if ns != nil && ns.field_38 == 1 {
			if uint32(ns.field_40+300) < gameFrame() {
				noxServer.nox_xxx_netStructReadPackets(i)
			}
		}
	}
}

func nox_xxx_netMaybeSendAll_552460() {
	ticks := platformTicks()
	C.dword_5d4594_2495920 = C.uint(ticks)
	if uint32(ticks)-*memmap.PtrUint32(0x5D4594, 2512888) <= 1000 {
		return
	}
	for i := 0; i < NOX_NET_STRUCT_MAX; i++ {
		if C.nox_net_struct_arr[i] != nil {
			sub_5551F0(i, 0, 0)
			nox_xxx_netSend_5552D0(i, 0, false)
		}
	}
	*memmap.PtrUint32(0x5D4594, 2512888) = uint32(ticks)
}

//export nox_xxx_netSendReadPacket_5528B0
func nox_xxx_netSendReadPacket_5528B0(ind int, a2 byte) int {
	ns := getNetStructByInd(ind)
	if ns == nil {
		return -3
	}
	find := ind
	min := 0
	max := NOX_NET_STRUCT_MAX
	if ns.id == -1 {
		if ns.field_19 != 0 {
			panic(ns.field_34)
			return 0
		}
	} else {
		min = ind
		max = ind + 1
		find = int(ns.id)
	}
	for j := min; j < max; j++ {
		ns2 := asNetStruct(C.nox_net_struct_arr[j])
		if ns2 == nil || int(ns2.id) != find {
			continue
		}
		nox_xxx_netSend_5552D0(j, 0, false)
		v10 := int(C.WaitForSingleObject(C.HANDLE(ns2.mutex_yyy), 0x3E8))
		if v10 == -1 || v10 == 258 {
			return -16
		}
		if a2&1 == 0 {
			data2 := ns2.Data2xxx()
			n := ns2.callXxx(j, data2, ns2.data_3)
			if n > 0 && n <= len(data2) {
				ns2.data_2_xxx = (*C.char)(unsafe.Add(unsafe.Pointer(ns2.data_2_xxx), n))
			}
		}
		v13 := ns2.Datax2()
		if len(v13) > 2 {
			ip, port := ns2.Addr()
			_, err := nox_xxx_sendto551F90(ns.Socket(), v13, ip, port)
			if err != nil {
				return -1
			}
			sub_553F40(len(v13), 1)
			nox_xxx_netCountData_554030(len(v13), j)
			ns2.data_2_xxx = ns2.data_2_yyy
		}
		if C.ReleaseMutex(C.HANDLE(ns2.mutex_yyy)) == 0 {
			C.ReleaseMutex(C.HANDLE(ns2.mutex_yyy))
		}
	}
	return 0
}

func sub_5551F0(a1 int, a2 byte, a3 int) int {
	ns := getNetStructByInd(a1)
	if ns == nil {
		return -3
	}
	for it := unsafe.Pointer(ns.field_29); it != nil; it = *(*unsafe.Pointer)(it) {
		gb := unsafe.Slice((*byte)(it), 22)
		gi := unsafe.Slice((*uint32)(it), 5)
		if a3 != 0 {
			if gb[21] == a2 {
				gi[3] = 1
				continue
			}
		} else if gi[1] <= uint32(C.dword_5d4594_2495920) {
			gi[3] = 1
			continue
		}
	}
	return 0
}

func sub_4DF550() int {
	return int(memmap.Uint32(0x5D4594, 1563148))
}

//export sub_5522E0
func sub_5522E0(id int) {
	i := sub_4DF550()
	ns := asNetStruct(C.nox_net_struct_arr[i])
	buf := nox_xxx_makePacketTime_552340(id)
	ns2 := &C.nox_net_struct2_arr[id]
	ip, port := toIPPort(&ns2.addr)
	n, _ := nox_xxx_sendto551F90(ns.Socket(), buf, ip, port)
	sub_553F40(n, 1)
}

func nox_xxx_makePacketTime_552340(id int) []byte {
	var buf [8]byte
	nx := &C.nox_net_struct2_arr[id]
	nx.ticks = C.uint(platformTicks())
	buf[2] = 16
	buf[3] = byte(nx.field_1_1)
	binary.LittleEndian.PutUint32(buf[4:], uint32(nx.ticks))
	return buf[:]
}

//export sub_552380
func sub_552380(a1 int) {
	i := sub_4DF550()
	ns := asNetStruct(C.nox_net_struct_arr[i])
	var buf [3]byte
	buf[0] = 0
	buf[1] = 0
	buf[2] = 20
	nx := &C.nox_net_struct2_arr[a1]
	ip, port := toIPPort(&nx.addr)
	n, _ := nox_xxx_sendto551F90(ns.Socket(), buf[:], ip, port)
	sub_553F40(n, 1)
	nx.field_0 = 0
}

//export sub_5523E0
func sub_5523E0(a1 byte, a2 int) {
	i := sub_4DF550()
	ns := asNetStruct(C.nox_net_struct_arr[i])
	var buf [4]byte
	buf[0] = 0
	buf[1] = 0
	buf[2] = 19
	buf[3] = a1
	nx := &C.nox_net_struct2_arr[a2]
	ip, port := toIPPort(&nx.addr)
	v4, _ := nox_xxx_sendto551F90(ns.Socket(), buf[:], ip, port)
	sub_553F40(v4, 1)
	nx.field_0 = 0
}

func sub_552E70(ind int) int {
	var buf [5]byte

	ns := getNetStructByInd(ind)
	if ns == nil {
		return -3
	}
	var (
		min, max int
		find     int
	)
	if ns.id == -1 {
		min = 0
		max = NOX_NET_STRUCT_MAX
		find = ind
	} else {
		min = ind
		max = ind + 1
		find = int(ns.id)
	}
	buf[0] = 6
	for i := min; i < max; i++ {
		ns2 := asNetStruct(C.nox_net_struct_arr[i])
		if ns2 != nil && int(ns2.id) == find {
			ns2.field_22 = C.dword_5d4594_2495920
			ns2.field_23 = ns2.field_22
			binary.LittleEndian.PutUint32(buf[1:], uint32(ns2.field_22))
			nox_xxx_netSendSock552640(i, buf[:5], NOX_NET_SEND_FLAG2)
		}
	}
	return 0
}

var (
	flag2495924 bool
	cnt2495944  uint32
	cnt2495948  uint32
	cnt2495952  uint32
	cnt2495956  uint32
)

func nox_xxx_allocNetGQueue_5520B0() {
	gameSet816392Func(func() bool {
		return C.sub_5521A0() != 0
	})
	if flag2495924 {
		return
	}
	C.nox_alloc_gQueue_3844300 = nil
	for i := range C.nox_net_struct_arr {
		C.nox_net_struct_arr[i] = nil
	}
	for i := range C.nox_net_struct2_arr {
		C.nox_net_struct2_arr[i] = C.nox_net_struct2_t{}
	}
	*memmap.PtrUint32(0x5D4594, 2512884) = 1024
	C.nox_alloc_gQueue_3844300 = (*C.nox_alloc_class)(alloc.NewClass("GQueue", 1024, 200).UPtr())
	if flag2495924 {
		var next unsafe.Pointer
		for it := nox_common_list_getFirstSafe_425890(*memmap.PtrPtr(0x5D4594, 2495908)); it != nil; it = next {
			next = nox_common_list_getNextSafe_4258A0(it)
			C.sub_425920(it)
			C.free(unsafe.Pointer(it))
			*memmap.PtrUint8(0x5D4594, 2500076)--
		}
	} else {
		nox_common_list_clear_425760(memmap.PtrOff(0x5D4594, 2495908))
	}
	cnt2495944 = 0
	cnt2495948 = 0
	cnt2495952 = 0
	cnt2495956 = 0
	flag2495924 = true
}

//export nox_xxx_findPlayerID_5541D0
func nox_xxx_findPlayerID_5541D0(a1 int) unsafe.Pointer {
	for it := nox_common_list_getFirstSafe_425890(memmap.PtrOff(0x5D4594, 2495908)); it != nil; it = nox_common_list_getNextSafe_4258A0(it) {
		if *(*int32)(unsafe.Add(it, 3*4)) == int32(a1) {
			return it
		}
	}
	return nil
}
