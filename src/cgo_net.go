package opennox

/*
#include "nox_net.h"
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"fmt"
	"net"
	"sync"
	"syscall"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/alloc/handles"
)

const (
	NOX_AF_INET        = C.NOX_AF_INET
	NOX_NET_EADDRINUSE = C.NOX_NET_EADDRINUSE
)

func nox_net_init() {
	C.debugNet = C.bool(debugNet)
	C.nox_net_no_xor = C.bool(!noxNetXor)
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

func listenUDPBroadcast(ip net.IP, port int) (*net.UDPConn, *Socket, error) {
	netLog.Printf("bind udp %s:%d", ip, port)
	l, err := net.ListenUDP("udp4", &net.UDPAddr{IP: ip, Port: port})
	if err != nil {
		return nil, nil, err
	}
	return l, &Socket{udp: true, pc: l}, nil
}

type Socket struct {
	c   net.Conn
	l   net.Listener
	pc  net.PacketConn
	udp bool
	err error
}

func (s *Socket) setErrno(v int, err error) {
	if s != nil {
		s.err = err
	}
	sockets.Lock()
	sockets.errno = v
	sockets.Unlock()
}

func netCanReadConn(pc net.PacketConn) (int, syscall.Errno, error) {
	sc, ok := pc.(syscall.Conn)
	if !ok {
		panic(fmt.Errorf("unexpected type: %T", pc))
	}
	rc, err := sc.SyscallConn()
	if err != nil {
		panic(fmt.Errorf("unexpected type: %T: %w", pc, err))
	}
	var (
		ierr syscall.Errno
		cnt  uint32
	)
	err = rc.Control(func(fd uintptr) {
		cnt, ierr = netCanRead(fd)
	})
	if err != nil {
		return 0, 0, err
	}
	if ierr == 0 {
		return int(cnt), 0, nil
	}
	if debugNet {
		netLog.Printf("can read: %d", cnt)
	}
	return int(cnt), ierr, ierr
}

func (s *Socket) CanRead() (int, error) {
	if s == nil {
		return 0, errors.New("nil socket")
	}
	if s.pc == nil {
		panic("TODO")
	}
	cnt, ierr, err := netCanReadConn(s.pc)
	if ierr != 0 {
		s.setErrno(int(ierr), err)
		return cnt, err
	} else if err != nil {
		s.setErrno(12345, err)
		log.Println(err)
		return cnt, err
	}
	return cnt, nil
}

func ErrIsInUse(err error) bool {
	return errors.Is(err, syscall.EADDRINUSE)
}

func (s *Socket) Bind(ip net.IP, port int) error {
	if s.udp {
		netLog.Printf("bind udp %s:%d", ip, port)
		l, err := net.ListenUDP("udp4", &net.UDPAddr{IP: ip, Port: port})
		if ErrIsInUse(err) {
			s.setErrno(NOX_NET_EADDRINUSE, err)
			return err
		} else if err != nil {
			s.setErrno(123456, err) // TODO
			return err
		}
		s.pc = l
		s.setErrno(0, nil)
		return nil
	}
	netLog.Printf("bind tcp %s:%d", ip, port)
	l, err := net.ListenTCP("tcp4", &net.TCPAddr{IP: ip, Port: port})
	if ErrIsInUse(err) {
		s.setErrno(NOX_NET_EADDRINUSE, err)
		return err
	} else if err != nil {
		s.setErrno(123456, err) // TODO
		return err
	}
	s.l = l
	s.setErrno(0, nil)
	return nil
}

func (s *Socket) ReadFrom(buf []byte) (int, net.Addr, error) {
	if !s.udp || s.pc == nil {
		err := errors.New("recv on TCP connection")
		netLog.Printf("warning: %v", err)
		s.setErrno(123456, err) // TODO
		return 0, nil, err
	}
	n, src, err := s.pc.ReadFrom(buf)
	if err != nil {
		netLog.Println(err)
		s.setErrno(123456, err) // TODO
		return n, src, err
	}
	ip, port := getAddr(src)
	if debugNet {
		netLog.Printf("recv %s:%d -> %s [%d]\n%x", ip, port, s.pc.LocalAddr(), n, buf[:n])
	}
	return n, src, nil
}

func (s *Socket) SendTo(buf []byte, ip net.IP, port int) (int, error) {
	if ip == nil {
		return s.Write(buf)
	}
	return s.WriteTo(buf, &net.UDPAddr{IP: ip, Port: port})
}

func (s *Socket) Write(buf []byte) (int, error) {
	if s.udp || s.c == nil {
		err := errors.New("send on UDP connection")
		netLog.Printf("warning: %v", err)
		s.setErrno(123456, err) // TODO
		return 0, err
	}
	n, err := s.c.Write(buf)
	if err != nil {
		netLog.Println(err)
		s.setErrno(123456, err) // TODO
		return 0, err
	}
	return n, nil
}

func (s *Socket) WriteTo(buf []byte, addr *net.UDPAddr) (int, error) {
	if !s.udp || s.pc == nil {
		err := errors.New("send on UDP connection")
		netLog.Printf("warning: %v", err)
		s.setErrno(123456, err) // TODO
		return 0, err
	}
	if debugNet {
		netLog.Printf("send %s -> %s [%d]\n%x", s.pc.LocalAddr(), addr, len(buf), buf)
	}
	n, err := s.pc.WriteTo(buf, addr)
	if err != nil {
		netLog.Println(err)
		s.setErrno(123456, err) // TODO
		return 0, err
	}
	return n, nil
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

type nox_socket_t = C.nox_socket_t

func newSocketHandle(s *Socket) nox_socket_t {
	if s == nil {
		return 0
	}
	h := handles.New()
	sockets.Lock()
	sockets.byHandle[h] = s
	sockets.Unlock()
	return nox_socket_t(h)
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

func getAddr(addr net.Addr) (net.IP, int) {
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
	return ip, port
}

func setAddr(dst *C.struct_nox_net_sockaddr_in, addr net.Addr) (net.IP, int) {
	ip, port := getAddr(addr)
	setIPPort(dst, ip, port)
	return ip, port
}

//export nox_net_close
func nox_net_close(fd nox_socket_t) {
	h := uintptr(fd)
	handles.AssertValid(h)
	sockets.Lock()
	s := sockets.byHandle[h]
	delete(sockets.byHandle, h)
	sockets.Unlock()
	_ = s.Close()
}

func getSocket(fd nox_socket_t) *Socket {
	h := uintptr(fd)
	if !handles.IsValid(h) {
		return nil
	}
	sockets.RLock()
	s := sockets.byHandle[h]
	sockets.RUnlock()
	return s
}

func nox_net_recv(fd nox_socket_t, buffer unsafe.Pointer, length C.uint) C.int {
	s := getSocket(fd)
	if s == nil {
		s.setErrno(123456, errors.New("no socket")) // TODO
		return -1
	}
	if s.udp || s.c == nil {
		err := errors.New("recv on UDP connection")
		netLog.Printf("warning: %v", err)
		s.setErrno(123456, err) // TODO
		return -1
	}
	buf := unsafe.Slice((*byte)(buffer), int(length))
	n, err := s.c.Read(buf)
	if err != nil {
		netLog.Println(err)
		s.setErrno(123456, err) // TODO
		return -1
	}
	return C.int(n)
}

//export nox_net_sendto
func nox_net_sendto(fd nox_socket_t, buffer unsafe.Pointer, length C.uint, addr *C.struct_nox_net_sockaddr_in) C.int {
	s := getSocket(fd)
	if s == nil {
		s.setErrno(123456, errors.New("no socket")) // TODO
		return -1
	}
	buf := unsafe.Slice((*byte)(buffer), int(length))
	var (
		n   int
		err error
	)
	if addr == nil {
		n, err = s.Write(buf)
	} else {
		ip, port := toIPPort(addr)
		n, err = s.WriteTo(buf, &net.UDPAddr{IP: ip, Port: port})
	}
	if err != nil {
		return -1
	}
	return C.int(n)
}

//export nox_net_recv_available
func nox_net_recv_available(fd nox_socket_t, out *C.uint) C.int {
	s := getSocket(fd)
	if s == nil {
		s.setErrno(123456, errors.New("no socket")) // TODO
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
