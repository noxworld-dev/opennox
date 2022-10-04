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
	"syscall"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/log"
)

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

func (s *Socket) setErr(err error) {
	if s != nil {
		s.err = err
	}
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
		s.setErr(err)
		return cnt, err
	} else if err != nil {
		s.setErr(err)
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
			s.setErr(err)
			return err
		} else if err != nil {
			s.setErr(err) // TODO
			return err
		}
		s.pc = l
		s.setErr(nil)
		return nil
	}
	netLog.Printf("bind tcp %s:%d", ip, port)
	l, err := net.ListenTCP("tcp4", &net.TCPAddr{IP: ip, Port: port})
	if ErrIsInUse(err) {
		s.setErr(err)
		return err
	} else if err != nil {
		s.setErr(err)
		return err
	}
	s.l = l
	s.setErr(nil)
	return nil
}

func (s *Socket) ReadFrom(buf []byte) (int, net.Addr, error) {
	if !s.udp || s.pc == nil {
		err := errors.New("recv on TCP connection")
		netLog.Printf("warning: %v", err)
		s.setErr(err)
		return 0, nil, err
	}
	n, src, err := s.pc.ReadFrom(buf)
	if err != nil {
		netLog.Println(err)
		s.setErr(err)
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
		s.setErr(err)
		return 0, err
	}
	n, err := s.c.Write(buf)
	if err != nil {
		netLog.Println(err)
		s.setErr(err)
		return 0, err
	}
	return n, nil
}

func (s *Socket) WriteTo(buf []byte, addr *net.UDPAddr) (int, error) {
	if !s.udp || s.pc == nil {
		err := errors.New("send on UDP connection")
		netLog.Printf("warning: %v", err)
		s.setErr(err)
		return 0, err
	}
	if debugNet {
		netLog.Printf("send %s -> %s [%d]\n%x", s.pc.LocalAddr(), addr, len(buf), buf)
	}
	n, err := s.pc.WriteTo(buf, addr)
	if err != nil {
		netLog.Println(err)
		s.setErr(err)
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
