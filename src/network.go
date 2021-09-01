package main

/*
#include "defs.h"
#include "nox_net.h"
extern unsigned int dword_5d4594_2660032;
extern unsigned int dword_5d4594_814548;
extern unsigned int dword_587000_87404;
extern unsigned long long qword_5d4594_814956;
extern nox_socket_t nox_xxx_sockLocalBroadcast_2513920;
extern nox_net_struct_t* nox_net_struct_arr[NOX_NET_STRUCT_MAX];
unsigned int nox_client_getServerAddr_43B300();
int nox_client_getServerPort_43B320();
int nox_client_getClientPort_40A420();
int mix_recvfrom(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr* from);
int sub_43B6D0();
int sub_43AF80();
int sub_43AF90(int a1);
int nox_xxx_netClientSend2_4E53C0(int a1, const void* a2, int a3, int a4, int a5);
int  nox_netlist_addToMsgListCli_40EBC0(int ind1, int ind2, unsigned char* buf, int sz);
void* nox_xxx_spriteGetMB_476F80();
int nox_xxx_netSendPacket_4E5030(int a1, const void* a2, signed int a3, int a4, int a5, char a6);
*/
import "C"
import (
	"encoding/binary"
	"net"
	"os"
	"strconv"
	"unsafe"

	"nox/v1/common/alloc"
	"nox/v1/common/log"
	"nox/v1/common/memmap"
	"nox/v1/common/serial"
)

const (
	NOX_NET_STRUCT_MAX = C.NOX_NET_STRUCT_MAX
)

var (
	noxNetNoXor = os.Getenv("NOX_NET_NO_XOR") == "true"
	debugNet    = os.Getenv("NOX_DEBUG_NET") == "true"
	netLog      = log.New("network")
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
	case 33:
		return pref + "STOP"
	case 39:
		return pref + "FRAME_39"
	case 43:
		return pref + "MAP_43"
	case 44:
		return pref + "PLAYER_NEW_44"
	case 45:
		return pref + "PLAYER_JOIN_45"
	case 46:
		return pref + "PLAYER_LEFT_46"
	case 47:
		return pref + "SPRITE_CREATE_47"
	case 48:
		return pref + "SPRITE_XXX_48"
	case 49:
		return pref + "SPRITE_XXX_49"
	case 50:
		return pref + "SPRITE_XXX_50"
	case 51:
		return pref + "SPRITE_XXX_51"
	case 52:
		return pref + "ADD_OBJ_FRIEND_52"
	case 56:
		return pref + "SPRITE_XXX_56"
	case 57:
		return pref + "SPRITE_SET_FRAME_57"
	case 58:
		return pref + "WALL_DESTROY_ID_58"
	case 61:
		return pref + "WALL_CREATE_AT_61"
	case 62:
		return pref + "WALL_DESTROY_AT_62"
	case 66:
		return pref + "HEALTH_CHANGE_66"
	case 69:
		return pref + "MANA_SET_69"
	case 72:
		return pref + "INV_XXX_72"
	case 75:
		return pref + "INV_XXX_75"
	case 76:
		return pref + "INV_XXX_76"
	case 79:
		return pref + "EQUIP_XXX_79"
	case 80:
		return pref + "EQUIP_XXX_80"
	case 81:
		return pref + "EQUIP_XXX_81"
	case 82:
		return pref + "EQUIP_XXX_82"
	case 228: // 0xE4
		return pref + "FADE"
	}
	return strconv.FormatUint(uint64(op), 16)
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
	buf := asByteSlice(unsafe.Pointer(cbuf), int(sz))
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
	buf := alloc.Bytes(100)
	defer alloc.FreeBytes(buf)
	if s, ok := serial.Serial(); ok {
		copy(buf[56:], s)
	}
	wstr := memmap.PtrOff(0x85B3FC, 12204)
	if n := WStrLen((*C.wchar_t)(wstr)); n != 0 {
		copy(buf[4:54], asByteSlice(wstr, n*2))
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
	buf := asByteSlice(unsafe.Pointer(cdata), 22)
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
	b := alloc.Bytes(uintptr(len(buf)))
	defer alloc.FreeBytes(b)
	copy(b, buf)
	return int(C.nox_xxx_netSendPacket_4E5030(C.int(a1), unsafe.Pointer(&b[0]), C.int(len(b)), C.int(a4), C.int(a5), C.char(a6)))
}

func nox_xxx_netSendPacket1_4E5390(a1 int, buf []byte, a4, a5 int) int {
	return nox_xxx_netSendPacket_4E5030(a1, buf, a4, a5, 1)
}

func nox_xxx_netMsgFadeBegin_4D9800(a1, a2 bool) int {
	var p [3]byte
	p[0] = 0xE4
	p[1] = byte(bool2int(a1))
	p[2] = byte(bool2int(a2))
	return nox_xxx_netSendPacket1_4E5390(255, p[:], 0, 1)
}

func nox_client_getServerAddr_43B300() net.IP {
	return int2ip(uint32(C.nox_client_getServerAddr_43B300()))
}

func nox_xxx_netClientSend2_4E53C0(a1 int, buf []byte, a4, a5 int) {
	p := alloc.Bytes(uintptr(len(buf)))
	copy(p, buf)
	defer alloc.FreeBytes(p)
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
	buf[0] = 63
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
		v6 = uint16(*(*uint32)(unsafe.Pointer(uintptr(v3) + 16)))
	}
	if a2 == memmap.Uint16(0x5D4594, 815768) && v6 == memmap.Uint16(0x5D4594, 815770) {
		return true
	}
	*memmap.PtrUint16(0x5D4594, 815768) = a2
	*memmap.PtrUint16(0x5D4594, 815770) = v6
	buf[0] = 0xAC
	binary.LittleEndian.PutUint16(buf[1:], a2)
	binary.LittleEndian.PutUint16(buf[3:], v6)
	if !nox_netlist_addToMsgListCli_40EBC0(a1, 0, buf[:5]) {
		return false
	}
	return true
}

func nox_netlist_addToMsgListCli_40EBC0(ind1, ind2 int, buf []byte) bool {
	cbuf := alloc.Bytes(uintptr(len(buf)))
	defer alloc.FreeBytes(cbuf)
	copy(cbuf, buf)
	return C.nox_netlist_addToMsgListCli_40EBC0(C.int(ind1), C.int(ind2), (*C.uchar)(unsafe.Pointer(&cbuf[0])), C.int(len(cbuf))) != 0
}
