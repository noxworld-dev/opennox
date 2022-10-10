package netstr

import (
	"errors"
	"fmt"
	"net"
	"syscall"
)

func ErrIsInUse(err error) bool {
	return errors.Is(err, syscall.EADDRINUSE)
}

func NewConnectFailErr(code int, err error) *ConnectFailErr {
	if code == 0 {
		code = -1
	}
	return &ConnectFailErr{
		Err:  err,
		Code: code,
	}
}

type ConnectFailErr struct {
	Err  error
	Code int
}

func (e *ConnectFailErr) Error() string {
	return fmt.Sprintf("CONNECT_SERVER failed: %s (code=%d)", e.Err, e.Code)
}

func (e *ConnectFailErr) Unwrap() error {
	return e.Err
}

func GetAddr(addr net.Addr) (net.IP, int) {
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
		Log.Printf("unsupported address type: %T", a)
	}
	return ip, port
}

func ListenUDPBroadcast(ip net.IP, port int) (*net.UDPConn, *Socket, error) {
	Log.Printf("listen udp broadcast %s:%d", ip, port)
	l, err := net.ListenUDP("udp4", &net.UDPAddr{IP: ip, Port: port})
	if err != nil {
		return nil, nil, err
	}
	return l, &Socket{pc: l}, nil
}

type Socket struct {
	pc net.PacketConn
}

func (s *Socket) CanRead() (int, error) {
	if s == nil {
		return 0, errors.New("nil socket")
	}
	if s.pc == nil {
		panic("TODO")
	}
	cnt, ierr, err := NetCanReadConn(s.pc)
	if ierr != 0 {
		return cnt, err
	} else if err != nil {
		Log.Println(err)
		return cnt, err
	}
	return cnt, nil
}

func udpListen(ip net.IP, port int) (*Socket, error) {
	Log.Printf("listen udp %s:%d", ip, port)
	l, err := net.ListenUDP("udp4", &net.UDPAddr{IP: ip, Port: port})
	if err != nil {
		return nil, err
	}
	return &Socket{pc: l}, nil
}

func (s *Socket) ReadFrom(buf []byte) (int, net.Addr, error) {
	n, src, err := s.pc.ReadFrom(buf)
	if err != nil {
		Log.Println(err)
		return n, src, err
	}
	ip, port := GetAddr(src)
	if Debug {
		Log.Printf("recv %s:%d -> %s [%d]\n%x", ip, port, s.pc.LocalAddr(), n, buf[:n])
	}
	return n, src, nil
}

func (s *Socket) SendTo(buf []byte, ip net.IP, port int) (int, error) {
	return s.WriteTo(buf, &net.UDPAddr{IP: ip, Port: port})
}

func (s *Socket) WriteTo(buf []byte, addr *net.UDPAddr) (int, error) {
	if Debug {
		Log.Printf("send %s -> %s [%d]\n%x", s.pc.LocalAddr(), addr, len(buf), buf)
	}
	n, err := s.pc.WriteTo(buf, addr)
	if err != nil {
		Log.Println(err)
		return 0, err
	}
	return n, nil
}

func (s *Socket) Close() error {
	if s == nil {
		return nil
	}
	if s.pc != nil {
		_ = s.pc.Close()
		s.pc = nil
	}
	return nil
}

func NetCanReadConn(pc net.PacketConn) (int, syscall.Errno, error) {
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
	if Debug {
		Log.Printf("can read: %d", cnt)
	}
	return int(cnt), ierr, ierr
}
