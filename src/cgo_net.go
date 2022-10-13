package opennox

import (
	"net"
	"net/netip"
	"unsafe"
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
