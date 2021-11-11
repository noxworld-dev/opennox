package nox

/*
#include "defs.h"
#include "nox_net.h"
#include "common__net_list.h"
#include "server__network__sdecode.h"
#include "GAME5.h"
#include "GAME3_2.h"
#include "GAME5_2.h"
#ifdef _WIN32
#include <windows.h>
#else
#include "windows_compat.h"
#endif
extern unsigned int dword_5d4594_2660032;
extern unsigned int dword_5d4594_814548;
extern unsigned int dword_587000_87404;
extern unsigned int dword_5d4594_3843632;
extern unsigned int dword_5d4594_2496472;
extern unsigned int dword_5d4594_2496988;
extern unsigned int dword_5d4594_2495920;
extern unsigned long long qword_5d4594_814956;
extern nox_alloc_class* nox_alloc_gQueue_3844300;
extern nox_socket_t nox_xxx_sockLocalBroadcast_2513920;
extern nox_net_struct_t* nox_net_struct_arr[NOX_NET_STRUCT_MAX];
extern nox_net_list_t* nox_net_lists[3][NOX_PLAYERINFO_MAX];
unsigned int nox_client_getServerAddr_43B300();
int nox_client_getServerPort_43B320();
int nox_client_getClientPort_40A420();
int sub_43B6D0();
int sub_43AF80();
int sub_43AF90(int a1);
int nox_xxx_netClientSend2_4E53C0(int a1, const void* a2, int a3, int a4, int a5);
int  nox_netlist_addToMsgListCli_40EBC0(int ind1, int ind2, unsigned char* buf, int sz);
void* nox_xxx_spriteGetMB_476F80();
int nox_xxx_netSendPacket_4E5030(int a1, const void* a2, signed int a3, int a4, int a5, char a6);
int  nox_xxx_netSendReadPacket_5528B0(unsigned int a1, char a2);

int nox_xxx_netHandlerDefXxx_553D60(unsigned int a1, char* a2, int a3, void* a4);
int nox_xxx_netHandlerDefYyy_553D70(unsigned int a1, char* a2, int a3, void* a4);
*/
import "C"
import (
	"context"
	"encoding/binary"
	"errors"
	"net"
	"time"
	"unsafe"

	"github.com/noxworld-dev/nat"

	"nox/v1/common/alloc"
	"nox/v1/common/log"
	"nox/v1/common/memmap"
	"nox/v1/common/noxnet"
	"nox/v1/common/platform"
	"nox/v1/common/serial"
)

const (
	NOX_NET_STRUCT_MAX = C.NOX_NET_STRUCT_MAX
)

func init() {
	configBoolPtr("network.xor", "NOX_NET_NO_XOR", true, &noxNetNoXor)
	configHiddenBoolPtr("debug.network", "NOX_DEBUG_NET", &debugNet)
}

var (
	noxNetNoXor bool
	debugNet    bool
	netLog      = log.New("network")
)

var (
	noxMapCRC     = 0
	noxServerHost = "localhost"
)

func newNetStruct() (*netStruct, func()) {
	p, free := alloc.Malloc(unsafe.Sizeof(C.nox_net_struct_t{}))
	return (*netStruct)(p), free
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
	clientSetServerHost(C.GoString(addr))
}

//export nox_client_getServerConnectAddr
func nox_client_getServerConnectAddr() *C.char {
	return internCStr(clientGetServerHost())
}

//export nox_xxx_cryptXor_56FDD0
func nox_xxx_cryptXor_56FDD0(key C.char, p *C.uchar, n C.int) {
	if p == nil || n == 0 || noxNetNoXor {
		return
	}
	buf := unsafe.Slice((*byte)(unsafe.Pointer(p)), int(n))
	netCryptXor(byte(key), buf)
}

//export nox_xxx_cryptXorDst_56FE00
func nox_xxx_cryptXorDst_56FE00(key C.char, src *C.uchar, n C.int, dst *C.uchar) {
	if src == nil || dst == nil || n == 0 {
		return
	}
	sbuf := unsafe.Slice((*byte)(unsafe.Pointer(src)), int(n))
	dbuf := unsafe.Slice((*byte)(unsafe.Pointer(dst)), int(n))
	nox_xxx_cryptXorDst(byte(key), sbuf, dbuf)
}

func nox_xxx_cryptXorDst(key byte, src, dst []byte) {
	if len(src) == 0 || len(dst) == 0 {
		return
	}
	netCryptDst(key, src, dst)
}

func netCryptXor(key byte, p []byte) {
	if len(p) == 0 || noxNetNoXor {
		return
	}
	for i := range p {
		p[i] ^= key
	}
}

func netCryptDst(key byte, src, dst []byte) {
	if noxNetNoXor {
		copy(dst, src)
		return
	}
	for i := range src {
		dst[i] = key ^ src[i]
	}
}

//export nox_xxx_getMapCRC_40A370
func nox_xxx_getMapCRC_40A370() C.int {
	return C.int(noxMapCRC)
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

//export nox_client_sendToServer_555010
func nox_client_sendToServer_555010(addr C.uint, port C.uint16_t, cbuf *C.char, sz C.int) C.int {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(sz))
	n, err := sendToServer(int2ip(uint32(addr)), int(port), buf)
	return convSendToServerErr(n, err)
}

func sub_43AF90(v int) {
	C.dword_5d4594_814548 = C.uint(v)
}

func nox_client_createSockAndJoin_43B440() error {
	if C.dword_587000_87404 == 1 {
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
	buf, freeBuf := alloc.Bytes(100)
	defer freeBuf()
	if s, ok := serial.Serial(); ok {
		copy(buf[56:], s)
	}
	wstr := memmap.PtrOff(0x85B3FC, 12204)
	if n := WStrLen((*C.wchar_t)(wstr)); n != 0 {
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

func nox_xxx_netSendPacket_4E5030(a1 int, buf []byte, a4, a5, a6 int) int {
	b, free := alloc.Bytes(uintptr(len(buf)))
	defer free()
	copy(b, buf)
	return int(C.nox_xxx_netSendPacket_4E5030(C.int(a1), unsafe.Pointer(&b[0]), C.int(len(b)), C.int(a4), C.int(a5), C.char(a6)))
}

func nox_xxx_netSendPacket1_4E5390(a1 int, buf []byte, a4, a5 int) int {
	return nox_xxx_netSendPacket_4E5030(a1, buf, a4, a5, 1)
}

func nox_xxx_netMsgFadeBegin_4D9800(a1, a2 bool) int {
	var p [3]byte
	p[0] = byte(noxnet.MSG_FADE_BEGIN)
	p[1] = byte(bool2int(a1))
	p[2] = byte(bool2int(a2))
	return nox_xxx_netSendPacket1_4E5390(255, p[:], 0, 1)
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
	p, free := alloc.Bytes(uintptr(len(buf)))
	defer free()
	copy(p, buf)
	C.nox_xxx_netClientSend2_4E53C0(C.int(a1), unsafe.Pointer(&p[0]), C.int(len(buf)), C.int(a4), C.int(a5))
}

//export nox_xxx_clientSendInput_43C8F0
func nox_xxx_clientSendInput_43C8F0(a1, a2, a3 C.int) C.int {
	if !clientSendInput(int(a1), uint16(a2), uint16(a3)) {
		return 0
	}
	return 1
}

func clientSendInput(a1 int, a2 uint16, a3 uint16) bool {
	v3 := C.nox_xxx_spriteGetMB_476F80()
	v4 := noxCtrlEventNetbuf[:noxCtrlEventNetbufSize]
	if len(v4) == 0 {
		return true
	}
	var buf [5]byte
	buf[0] = byte(noxnet.MSG_PLAYER_INPUT)
	if !nox_netlist_addToMsgListCli_40EBC0(a1, 0, buf[:1]) {
		return false
	}
	buf[0] = byte(len(v4))
	if !nox_netlist_addToMsgListCli_40EBC0(a1, 0, buf[:1]) {
		return false
	}
	if !nox_netlist_addToMsgListCli_40EBC0(a1, 0, v4) {
		return false
	}
	v6 := a3
	if v3 != nil {
		v6 = uint16(*(*uint32)(unsafe.Add(v3, 16)))
	}
	if a2 == memmap.Uint16(0x5D4594, 815768) && v6 == memmap.Uint16(0x5D4594, 815770) {
		return true
	}
	*memmap.PtrUint16(0x5D4594, 815768) = a2
	*memmap.PtrUint16(0x5D4594, 815770) = v6
	buf[0] = byte(noxnet.MSG_MOUSE)
	binary.LittleEndian.PutUint16(buf[1:], a2)
	binary.LittleEndian.PutUint16(buf[3:], v6)
	if !nox_netlist_addToMsgListCli_40EBC0(a1, 0, buf[:5]) {
		return false
	}
	return true
}

func nox_netlist_addToMsgListCli_40EBC0(ind1, ind2 int, buf []byte) bool {
	cbuf, bufFree := alloc.Bytes(uintptr(len(buf)))
	defer bufFree()
	copy(cbuf, buf)
	return C.nox_netlist_addToMsgListCli_40EBC0(C.int(ind1), C.int(ind2), (*C.uchar)(unsafe.Pointer(&cbuf[0])), C.int(len(cbuf))) != 0
}

func asNetList(p *C.nox_net_list_t) *NetList {
	return (*NetList)(unsafe.Pointer(p))
}

type NetList C.nox_net_list_t

func (l *NetList) C() *C.nox_net_list_t {
	return (*C.nox_net_list_t)(unsafe.Pointer(l))
}

func (l *NetList) freeItem(item *C.nox_net_list_item_t) {
	alloc.AsClass(unsafe.Pointer(l.alloc)).FreeObjectFirst(unsafe.Pointer(item))
}

func (l *NetList) get() []byte { // nox_netlist_get_420A90
	if l.first == nil {
		return nil
	}
	item := l.first
	sz := int(item.size)

	l.count--
	l.size -= item.size

	if next := item.next; next != nil {
		next.prev = item.prev
	} else {
		l.last = item.prev
	}
	if prev := item.prev; prev != nil {
		prev.next = item.next
	} else {
		l.first = item.next
	}

	buf := unsafe.Slice((*byte)(unsafe.Pointer(item.buf)), sz)
	l.freeItem(item)
	return buf
}

func nox_netlist_copyPacketList_40ED60(ind1, ind2 int) []byte {
	list := asNetList(C.nox_net_lists[ind2][ind1])
	out := make([]byte, 0, netListsBufSize)
	for {
		buf := list.get()
		if len(buf) == 0 {
			return out
		} else if len(out)+len(buf) > cap(out) {
			// TODO: is it okay that it discards data?
			return out
		}
		out = append(out, buf...)
	}
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

func nox_xxx_netAddPlayerHandler_4DEBC0(port int) (ind, cport int, _ error) {
	narg := &netStructOpt{
		port:      port,
		data3size: 0,
		field4:    getServerMaxPlayers(),
		datasize:  2048,
		funcyyy:   C.nox_xxx_netlist_ServRecv_4DEC30,
		funcxxx:   C.nox_xxx_netFn_UpdateStream_4DF630,
	}
	C.nox_xxx_allocNetGQueue_5520B0(200, 1024)
	ind, err := nox_xxx_netInit_554380(narg)
	if err != nil {
		return ind, 0, err
	}
	*memmap.PtrInt32(0x5D4594, 1563148) = int32(ind)
	return ind, narg.port, err
}

//export nox_xxx_netPreStructToFull_5546F0
func nox_xxx_netPreStructToFull_5546F0(arg *C.nox_net_struct_arg_t) C.int {
	narg := toNetStructOpt(arg)
	ind, err := nox_xxx_netPreStructToFull(narg)
	if err != nil {
		netLog.Println(err)
	}
	return C.int(ind)
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
	nox_net_init()
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

func toNetStructOpt(arg *C.nox_net_struct_arg_t) *netStructOpt {
	return &netStructOpt{
		field0:    uint32(arg.field_0),
		field1:    uint32(arg.field_1),
		port:      int(arg.port),
		data3size: int(arg.data_3_size),
		field4:    int(arg.field_4),
		datasize:  int(arg.data_size),
		field6:    uint32(arg.field_6),
		field7:    uint32(arg.field_7),
		funcxxx:   unsafe.Pointer(arg.func_xxx),
		funcyyy:   unsafe.Pointer(arg.func_yyy),
	}
}

//export nox_xxx_makeNewNetStruct_553000
func nox_xxx_makeNewNetStruct_553000(arg *C.nox_net_struct_arg_t) *C.nox_net_struct_t {
	narg := toNetStructOpt(arg)
	return nox_xxx_makeNewNetStruct(narg).C()
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
		p, _ := alloc.Bytes(uintptr(arg.data3size))
		ns.data_3 = unsafe.Pointer(&p[0])
	}
	if dsz := arg.datasize; dsz > 0 {
		dsz -= dsz % 4
		arg.datasize = dsz
	} else {
		arg.datasize = 1024
	}
	data1, _ := alloc.Bytes(uintptr(arg.datasize + 2))
	ns.data_1_base = (*C.char)(unsafe.Pointer(&data1[0]))
	ns.data_1_xxx = (*C.char)(unsafe.Pointer(&data1[0]))
	ns.data_1_yyy = (*C.char)(unsafe.Pointer(&data1[0]))
	ns.data_1_end = (*C.char)(unsafe.Add(unsafe.Pointer(&data1[0]), len(data1)))

	data2, _ := alloc.Bytes(uintptr(arg.datasize) + 2)
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

func nox_server_netClose_5546A0(i int) {
	if ns := getNetStructByInd(i); ns != nil {
		_ = ns.Socket().Close()
		ns.SetSocket(nil)
		ns.FreeXxx()
		setNetStructByInd(i, nil)
	}
}

//export nox_xxx_netStructFree_5531C0
func nox_xxx_netStructFree_5531C0(ns *C.nox_net_struct_t) {
	asNetStruct(ns).FreeXxx()
}

//export nox_xxx_netStructReadPackets_5545B0
func nox_xxx_netStructReadPackets_5545B0(ind C.uint) C.int {
	return C.int(nox_xxx_netStructReadPackets(int(ind)))
}

func nox_xxx_netStructReadPackets(ind int) int {
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
		C.nox_xxx_netSendReadPacket_5528B0(C.uint(i), 1)
		var buf [1]byte
		buf[0] = 11
		nox_xxx_netSendSock_552640(i, buf[:], 0)
		C.nox_xxx_netSendReadPacket_5528B0(C.uint(i), 1)
		getNetStructByInd(v4).field_21--
		C.sub_555360(C.uint(v1), 0, 2)
		ns2.FreeXxx()
		setNetStructByInd(i, nil)
	}
	return 0
}

func nox_xxx_netStructReadPackets2_4DEC50(a1 int) int {
	return nox_xxx_netStructReadPackets(a1 + 1)
}

//export nox_xxx_netlist_ServRecv_4DEC30
func nox_xxx_netlist_ServRecv_4DEC30(a1 C.int, a2 *C.uchar, a3 C.int, a4 unsafe.Pointer) C.int {
	C.nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode(a1-1, a2, a3)
	return 1
}

const (
	NOX_NET_SEND_NO_LOCK = 0x1
	NOX_NET_SEND_FLAG2   = 0x2
)

func nox_xxx_netSendSock_552640(id int, buf []byte, flags int) (int, error) {
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
				v12, err := sub_555130(i, buf)
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
			n2, err := nox_xxx_sendto_551F90(ns2.Socket(), d2x[:n+2], ip, port)
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

func sub_553F40(a1, a2 int) {
	*memmap.PtrUint32(0x5D4594, 2495952) += uint32(a1)
	*memmap.PtrUint32(0x5D4594, 2495956) += uint32(a2)
	i := memmap.Uint32(0x5D4594, 2497504)
	j := memmap.Uint32(0x5D4594, 2498020)
	*memmap.PtrUint32(0x5D4594, 2496992+4*uintptr(i)) = uint32(a1)
	*memmap.PtrUint32(0x5D4594, 2497508+4*uintptr(j)) = uint32(a2)
	*memmap.PtrUint32(0x5D4594, 2497504) = uint32(C.dword_5d4594_2496472+1) % 128
	*memmap.PtrUint32(0x5D4594, 2498020) = uint32(C.dword_5d4594_2496988+1) % 128
}

func sub_555130(a1 int, buf []byte) (int, error) {
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

var sendXorBuf [4096]byte

func nox_xxx_sendto_551F90(s *Socket, buf []byte, ip net.IP, port int) (int, error) {
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
				if _, err := nox_xxx_sendto_551F90(ns.Socket(), gb[20:20+sz], ip, port); err != nil {
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
			if _, err := nox_xxx_sendto_551F90(ns.Socket(), gb[20:20+sz], ip, port); err != nil {
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
	nox_xxx_netSendSock_552640(int(memmap.Uint32(0x5D4594, 815700)), data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	return 1
}

func nox_xxx_netKeepAliveSocket_43CA20() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_KEEP_ALIVE)
	nox_xxx_netSendSock_552640(int(memmap.Uint32(0x5D4594, 815700)), data[:], NOX_NET_SEND_FLAG2)
	return 1
}

func nox_xxx_netRequestMap_43CA50() int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_REQUEST_MAP)
	nox_xxx_netSendSock_552640(int(memmap.Uint32(0x5D4594, 815700)), data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	return 1
}

func nox_xxx_netMapReceived_43CA80() C.int {
	var data [1]byte
	data[0] = byte(noxnet.MSG_RECEIVED_MAP)
	nox_xxx_netSendSock_552640(int(memmap.Uint32(0x5D4594, 815700)), data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	return 1
}

//export nox_xxx_cliSendCancelMap_43CAB0
func nox_xxx_cliSendCancelMap_43CAB0() C.int {
	id := int(memmap.Uint32(0x5D4594, 815700))
	var data [1]byte
	data[0] = byte(noxnet.MSG_CANCEL_MAP)
	v0, _ := nox_xxx_netSendSock_552640(id, data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	if nox_xxx_cliWaitServerResponse_5525B0(id, v0, 20, 6) != 0 {
		return 0
	}
	C.nox_netlist_resetByInd_40ED10(31, 0)
	return 1
}

func nox_xxx_netSendIncomingClient_43CB00() int {
	id := int(memmap.Uint32(0x5D4594, 815700))
	var data [1]byte
	data[0] = byte(noxnet.MSG_INCOMING_CLIENT)
	v0, _ := nox_xxx_netSendSock_552640(id, data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	if nox_xxx_cliWaitServerResponse_5525B0(id, v0, 20, 6) != 0 {
		return 0
	}
	C.nox_netlist_resetByInd_40ED10(31, 0)
	return 1
}

func nox_xxx_cliSendOutgoingClient_43CB50() int {
	id := int(memmap.Uint32(0x5D4594, 815700))
	var data [1]byte
	data[0] = byte(noxnet.MSG_OUTGOING_CLIENT)
	v0, _ := nox_xxx_netSendSock_552640(id, data[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
	if nox_xxx_cliWaitServerResponse_5525B0(id, v0, 20, 6) != 0 {
		return 0
	}
	C.nox_xxx_servNetInitialPackets_552A80(C.uint(id), 3)
	C.nox_netlist_resetByInd_40ED10(31, 0)
	return 1
}

func nox_xxx_cliWaitServerResponse_5525B0(a1 int, a2 int, a3 int, a4 byte) int {
	if debugNet {
		netLog.Printf("nox_xxx_cliWaitServerResponse_5525B0: %d, %d, %d, %d\n", a1, a2, a3, a4)
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
		C.nox_xxx_servNetInitialPackets_552A80(C.uint(a1), C.char(a4|1))
		C.nox_xxx_netMaybeSendAll_552460()
		if int(ns.field_28_1) >= a2 {
			return 0
		}
		// FIXME(awesie)
		return 0
	}
	return -23
}
