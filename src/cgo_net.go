package opennox

/*
#include "nox_net.h"
*/
import "C"
import (
	"encoding/binary"
	"net"
	"net/netip"
	"unsafe"
)

//export nox_net_ip2str
func nox_net_ip2str(addr C.nox_net_in_addr) *C.char {
	ip := int2ip(uint32(addr))
	return internCStr(ip.String())
}

func int2port(v uint16) int {
	b := (*[2]byte)(unsafe.Pointer(&v))[:]
	vn := int(binary.BigEndian.Uint16(b))
	return vn
}

func port2int(v int) uint16 {
	var b [2]byte
	binary.BigEndian.PutUint16(b[:], uint16(v))
	vi := *(*uint16)(unsafe.Pointer(&b[0]))
	return vi
}

func int2ip(v uint32) netip.Addr {
	b := (*[4]byte)(unsafe.Pointer(&v))[:]
	ip := net.IPv4(b[0], b[1], b[2], b[3])
	addr, _ := netip.AddrFromSlice(ip)
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
