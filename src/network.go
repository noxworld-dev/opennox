package main

/*
#include "defs.h"
#include "nox_net.h"
extern unsigned int dword_5d4594_2513916;
extern nox_socket_t nox_xxx_sockLocalBroadcast_2513920;
extern nox_net_struct_t* nox_net_struct_arr[NOX_NET_STRUCT_MAX];
int nox_client_getServerPort_43B320();
int nox_client_getClientPort_40A420();
*/
import "C"
import (
	"errors"
	"log"
	"net"
	"os"
	"strconv"
	"unsafe"
)

const (
	NOX_NET_STRUCT_MAX = C.NOX_NET_STRUCT_MAX
)

var (
	noxNetNoXor = os.Getenv("NOX_NET_NO_XOR") == "true"
	debugNet    = os.Getenv("NOX_DEBUG_NET") == "true"
	netLog      = log.New(os.Stderr, "[network]: ", log.LstdFlags|log.Lmsgprefix)
)

var (
	noxMapCRC     = 0
	noxServerHost = "localhost"
)

func asNetStruct(ptr *C.nox_net_struct_t) *netStruct {
	return (*netStruct)(unsafe.Pointer(ptr))
}

func getNetStructByInd(id int) *netStruct {
	if id < 0 || id >= NOX_NET_STRUCT_MAX {
		return nil
	}
	return asNetStruct(C.nox_net_struct_arr[id])
}

type netStruct C.nox_net_struct_t

func (ns *netStruct) C() *C.nox_net_struct_t {
	return (*C.nox_net_struct_t)(unsafe.Pointer(ns))
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
	return asByteSlice(unsafe.Pointer(ns.data_1_base), sz)
}

func (ns *netStruct) Data2() []byte {
	if ns == nil {
		return nil
	}
	sz := int(uintptr(unsafe.Pointer(ns.data_2_end)) - uintptr(unsafe.Pointer(ns.data_2_base)))
	if sz < 0 {
		panic("negative size")
	}
	return asByteSlice(unsafe.Pointer(ns.data_2_base), sz)
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
	buf := asByteSlice(unsafe.Pointer(p), int(n))
	netCryptXor(byte(key), buf)
}

//export nox_xxx_cryptXorDst_56FE00
func nox_xxx_cryptXorDst_56FE00(key C.char, src *C.uchar, n C.int, dst *C.uchar) {
	if src == nil || dst == nil || n == 0 {
		return
	}
	sbuf := asByteSlice(unsafe.Pointer(src), int(n))
	dbuf := asByteSlice(unsafe.Pointer(dst), int(n))
	if noxNetNoXor {
		copy(dbuf, sbuf)
		return
	}
	netCryptDst(byte(key), sbuf, dbuf)
}

func netCryptXor(key byte, p []byte) {
	for i := range p {
		p[i] ^= key
	}
}

func netCryptDst(key byte, src, dst []byte) {
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
	buf := asByteSlice(unsafe.Pointer(data), int(sz))
	if debugNet {
		netLog.Printf("noxOnCliPacketDebug: op=%d (%s) [%d]\n%x", int(op), clientNetOp(op).String(), int(sz), buf)
	}
}

type clientNetOp byte

func (op clientNetOp) String() string {
	const pref = "NET_OP_"
	switch op {
	case 39:
		return pref + "FRAME_39"
	case 228: // 0xE4
		return pref + "FADE"
	}
	return strconv.FormatUint(uint64(op), 16)
}

var errDword_5d4594_2513916 = errors.New("dword_5d4594_2513916 is false")

func convSendToServerErr(n int, err error) C.int {
	if err == errDword_5d4594_2513916 {
		return -17
	} else if err != nil {
		return -1
	}
	return C.int(n)
}

//export nox_client_sendToServer_555010
func nox_client_sendToServer_555010(addr C.uint, port C.uint16_t, cbuf *C.char, sz C.int) C.int {
	buf := asByteSlice(unsafe.Pointer(cbuf), int(sz))
	n, err := sendToServer(int2ip(uint32(addr)), int(port), buf)
	return convSendToServerErr(n, err)
}

//export nox_client_sendJoinGame_5550A0
func nox_client_sendJoinGame_5550A0(addr C.uint, port C.uint16_t, cdata *C.char) C.int {
	buf := asByteSlice(unsafe.Pointer(cdata), 100)
	n, err := sendJoinGame(int2ip(uint32(addr)), int(port), buf)
	return convSendToServerErr(n, err)
}

//export sub_5550D0
func sub_5550D0(addr C.int, port C.uint16_t, cdata *C.char) C.int {
	buf := asByteSlice(unsafe.Pointer(cdata), 22)
	n, err := sendXXX_5550D0(int2ip(uint32(addr)), int(port), buf)
	return convSendToServerErr(n, err)
}

func sendToServer(addr net.IP, port int, data []byte) (int, error) {
	if C.dword_5d4594_2513916 == 0 {
		return 0, errDword_5d4594_2513916
	}
	if len(data) < 2 {
		return 0, nil
	}
	s := getSocket(C.nox_xxx_sockLocalBroadcast_2513920)
	if s == nil {
		return 0, errors.New("no broadcast socket")
	}
	return s.WriteTo(data, &net.UDPAddr{IP: addr, Port: port})
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
