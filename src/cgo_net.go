package main

/*
#include "nox_net.h"
*/
import "C"
import (
	"encoding/binary"
	"fmt"
	"log"
	"net"
	"sync"
	"syscall"
	"unsafe"

	"nox/common/alloc"
	"nox/common/alloc/handles"
)

const (
	NOX_AF_INET        = C.NOX_AF_INET
	NOX_NET_EADDRINUSE = C.NOX_NET_EADDRINUSE
)

//export nox_net_init
func nox_net_init() C.int {
	C.debugNet = C.bool(debugNet)
	C.nox_net_no_xor = C.bool(noxNetNoXor)
	return 0
}

//export nox_net_stop
func nox_net_stop() C.int {
	return 0
}

//export nox_net_ip2str
func nox_net_ip2str(addr C.nox_net_in_addr) *C.char {
	ip := int2ip(uint32(addr))
	return internCStr(ip.String())
}

func newSocketUDP() *Socket {
	return &Socket{udp: true}
}

type Socket struct {
	c         net.Conn
	l         net.Listener
	pc        net.PacketConn
	udp       bool
	broadcast bool
	errno     int
}

func (s *Socket) setErrno(v int) {
	s.errno = v // TODO: mutex
	sockets.Lock()
	sockets.errno = v
	sockets.Unlock()
}

func (s *Socket) getErrno() int {
	return s.errno // TODO: mutex
}

func (s *Socket) CanRead() (int, error) {
	if s.pc == nil {
		panic("TODO")
	}
	sc, ok := s.pc.(syscall.Conn)
	if !ok {
		panic(fmt.Errorf("unexpected type: %T", s.pc))
	}
	rc, err := sc.SyscallConn()
	if err != nil {
		panic(fmt.Errorf("unexpected type: %T: %w", s.pc, err))
	}
	var (
		ierr syscall.Errno
		cnt  uint32
	)
	err = rc.Control(func(fd uintptr) {
		cnt, ierr = netCanRead(fd)
	})
	if err != nil {
		log.Println(err)
		return 0, err
	}
	if ierr == 0 {
		return int(cnt), nil
	}
	s.setErrno(int(ierr))
	if debugNet {
		netLog.Printf("can read: %d", cnt)
	}
	return int(cnt), ierr
}

func ErrIsInUse(err error) bool {
	return false // TODO
}

func (s *Socket) Bind(ip net.IP, port int) error {
	if s.udp {
		netLog.Printf("bind udp %s:%d", ip, port)
		l, err := net.ListenUDP("udp4", &net.UDPAddr{IP: ip, Port: port})
		if err != nil {
			s.setErrno(123456) // TODO
			return err
		}
		s.pc = l
		return nil
	}
	netLog.Printf("bind tcp %s:%d", ip, port)
	l, err := net.ListenTCP("tcp4", &net.TCPAddr{IP: ip, Port: port})
	if err != nil {
		s.setErrno(123456) // TODO
		return err
	}
	s.l = l
	return nil
}

func (s *Socket) Close() error {
	if s == nil {
		return nil
	}
	if s.l != nil {
		_ = s.l.Close()
		s.l = nil
	}
	if s.c != nil {
		_ = s.c.Close()
		s.c = nil
	}
	if s.pc != nil {
		_ = s.pc.Close()
		s.pc = nil
	}
	return nil
}

var sockets struct {
	sync.RWMutex
	errno    int
	byHandle map[uintptr]*Socket
}

func init() {
	sockets.byHandle = make(map[uintptr]*Socket)
}

func newSocketHandle(s *Socket) C.nox_socket_t {
	h := handles.New()
	sockets.Lock()
	sockets.byHandle[h] = s
	sockets.Unlock()
	return C.nox_socket_t(h)
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

func int2ip(v uint32) net.IP {
	b := (*[4]byte)(unsafe.Pointer(&v))[:]
	ip := net.IPv4(b[0], b[1], b[2], b[3])
	return ip
}

func ip2int(ip net.IP) uint32 {
	var b [4]byte
	copy(b[:], ip.To4())
	v := *(*uint32)(unsafe.Pointer(&b[0]))
	return v
}

func toIPPort(addr *C.struct_nox_net_sockaddr_in) (net.IP, int) {
	if addr == nil {
		return nil, 0
	}
	return int2ip(uint32(addr.sin_addr)), int2port(uint16(addr.sin_port))
}

func setIPPort(dst *C.struct_nox_net_sockaddr_in, ip net.IP, port int) {
	if dst == nil {
		return
	}
	dst.sin_family = NOX_AF_INET
	dst.sin_addr = C.uint(ip2int(ip))
	dst.sin_port = C.ushort(port2int(port))
	alloc.Memset(unsafe.Pointer(&dst.sin_zero[0]), 0, 8)
}

func setAddr(dst *C.struct_nox_net_sockaddr_in, addr net.Addr) (net.IP, int) {
	var (
		ip   net.IP
		port int
	)
	switch a := addr.(type) {
	case nil:
	case *net.TCPAddr:
		ip, port = a.IP, a.Port
	case *net.UDPAddr:
		ip, port = a.IP, a.Port
	default:
		log.Printf("unsupported address type: %T", a)
	}
	setIPPort(dst, ip, port)
	return ip, port
}

//export nox_net_socket_tcp
func nox_net_socket_tcp() C.nox_socket_t {
	s := &Socket{}
	return newSocketHandle(s)
}

//export nox_net_socket_udp
func nox_net_socket_udp() C.nox_socket_t {
	s := newSocketUDP()
	return newSocketHandle(s)
}

//export nox_net_socket_udp_broadcast
func nox_net_socket_udp_broadcast() C.nox_socket_t {
	s := &Socket{udp: true, broadcast: true}
	return newSocketHandle(s)
}

//export nox_net_close
func nox_net_close(fd C.nox_socket_t) {
	h := uintptr(fd)
	handles.AssertValid(h)
	sockets.Lock()
	s := sockets.byHandle[h]
	delete(sockets.byHandle, h)
	sockets.Unlock()
	_ = s.Close()
}

func getSocket(fd C.nox_socket_t) *Socket {
	h := uintptr(fd)
	handles.AssertValid(h)
	sockets.RLock()
	s := sockets.byHandle[h]
	sockets.RUnlock()
	return s
}

//export nox_net_shutdown
func nox_net_shutdown(fd C.nox_socket_t) {
	_ = getSocket(fd).Close()
}

//export nox_net_error
func nox_net_error(fd C.nox_socket_t) C.int {
	if fd <= 0 {
		return nox_net_last_error()
	}
	return C.int(getSocket(fd).getErrno())
}

//export nox_net_last_error
func nox_net_last_error() C.int {
	sockets.RLock()
	errno := sockets.errno
	sockets.RUnlock()
	return C.int(errno)
}

//export nox_net_bind
func nox_net_bind(fd C.nox_socket_t, addr *C.struct_nox_net_sockaddr_in) C.int {
	s := getSocket(fd)
	if s == nil {
		s.setErrno(123456) // TODO
		return -1
	}
	ip, port := toIPPort(addr)
	err := s.Bind(ip, port)
	if err != nil {
		netLog.Println(err)
		return -1
	}
	return 0
}

//export nox_net_accept
func nox_net_accept(fd C.nox_socket_t, addr *C.struct_nox_net_sockaddr_in) C.nox_socket_t {
	s := getSocket(fd)
	if s == nil {
		s.setErrno(123456) // TODO
		return -1
	}
	if s.l == nil {
		netLog.Printf("warning: accept on UDP connection")
		s.setErrno(123456) // TODO
		return -1
	}
	c, err := s.l.Accept()
	if err != nil {
		netLog.Println(err)
		s.setErrno(123456) // TODO
		return -1
	}
	s2 := &Socket{c: c}
	ip, port := setAddr(addr, c.RemoteAddr())
	if debugNet {
		netLog.Printf("accept tcp %s:%d", ip, port)
	}
	return newSocketHandle(s2)
}

//export nox_net_send
func nox_net_send(fd C.nox_socket_t, buffer unsafe.Pointer, length C.uint) C.int {
	s := getSocket(fd)
	if s == nil {
		s.setErrno(123456) // TODO
		return -1
	}
	if s.udp || s.c == nil {
		netLog.Printf("warning: send on UDP connection")
		s.setErrno(123456) // TODO
		return -1
	}
	buf := asByteSlice(buffer, int(length))
	n, err := s.c.Write(buf)
	if err != nil {
		netLog.Println(err)
		s.setErrno(123456) // TODO
		return -1
	}
	return C.int(n)
}

//export nox_net_recv
func nox_net_recv(fd C.nox_socket_t, buffer unsafe.Pointer, length C.uint) C.int {
	s := getSocket(fd)
	if s == nil {
		s.setErrno(123456) // TODO
		return -1
	}
	if s.udp || s.c == nil {
		netLog.Printf("warning: recv on UDP connection")
		s.setErrno(123456) // TODO
		return -1
	}
	buf := asByteSlice(buffer, int(length))
	n, err := s.c.Read(buf)
	if err != nil {
		netLog.Println(err)
		s.setErrno(123456) // TODO
		return -1
	}
	return C.int(n)
}

//export nox_net_sendto
func nox_net_sendto(fd C.nox_socket_t, buffer unsafe.Pointer, length C.uint, addr *C.struct_nox_net_sockaddr_in) C.int {
	if addr == nil {
		return nox_net_send(fd, buffer, length)
	}
	s := getSocket(fd)
	if s == nil {
		s.setErrno(123456) // TODO
		return -1
	}
	if !s.udp || s.pc == nil {
		netLog.Printf("warning: send on UDP connection")
		s.setErrno(123456) // TODO
		return -1
	}
	buf := asByteSlice(buffer, int(length))
	ip, port := toIPPort(addr)
	if debugNet {
		netLog.Printf("send %s -> %s:%d [%d]\n%x", s.pc.LocalAddr(), ip, port, len(buf), buf)
	}
	n, err := s.pc.WriteTo(buf, &net.UDPAddr{IP: ip, Port: port})
	if err != nil {
		netLog.Println(err)
		s.setErrno(123456) // TODO
		return -1
	}
	return C.int(n)
}

//export nox_net_recvfrom
func nox_net_recvfrom(fd C.nox_socket_t, buffer unsafe.Pointer, length C.uint, addr *C.struct_nox_net_sockaddr_in) C.int {
	if addr == nil {
		return nox_net_recv(fd, buffer, length)
	}
	s := getSocket(fd)
	if s == nil {
		s.setErrno(123456) // TODO
		return -1
	}
	if !s.udp || s.pc == nil {
		netLog.Printf("warning: recv on UDP connection")
		s.setErrno(123456) // TODO
		return -1
	}
	buf := asByteSlice(buffer, int(length))
	n, src, err := s.pc.ReadFrom(buf)
	if err != nil {
		netLog.Println(err)
		s.setErrno(123456) // TODO
		return -1
	}
	ip, port := setAddr(addr, src)
	if debugNet {
		netLog.Printf("recv %s:%d -> %s [%d]\n%x", ip, port, s.pc.LocalAddr(), n, buf[:n])
	}
	return C.int(n)
}

//export nox_net_recv_available
func nox_net_recv_available(fd C.nox_socket_t, out *C.uint) C.int {
	s := getSocket(fd)
	if s == nil {
		s.setErrno(123456) // TODO
		return -1
	}
	n, err := s.CanRead()
	if err != nil {
		netLog.Println(err)
		return -1
	}
	*out = C.uint(n)
	return 0
}

//export nox_net_non_blocking
func nox_net_non_blocking(fd C.nox_socket_t, enabled C.int) C.int {
	s := getSocket(fd)
	if s == nil {
		s.setErrno(123456) // TODO
		return -1
	}
	netLog.Printf("nox_net_non_blocking: %T, %T", s.c, s.pc)
	panic("TODO")
}
