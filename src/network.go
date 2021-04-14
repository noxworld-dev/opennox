package main

/*
#include "defs.h"
extern nox_net_struct_t* nox_net_struct_arr[NOX_NET_STRUCT_MAX];
int nox_client_getServerPort_43B320();
int nox_client_getClientPort_40A420();
*/
import "C"
import (
	"log"
	"net"
	"os"
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
		netLog.Printf("noxOnCliPacketDebug: op=%d (%x) [%d]\n%x", int(op), int(op), int(sz), buf)
	}
}
