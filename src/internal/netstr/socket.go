package netstr

import (
	"errors"
	"fmt"
	"log"
	"net"
	"net/netip"
	"syscall"
)

var DebugSockets = false

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

func GetAddr(addr net.Addr) netip.AddrPort {
	switch a := addr.(type) {
	case nil:
	case interface{ AddrPort() netip.AddrPort }:
		return a.AddrPort()
	case *net.TCPAddr:
		return a.AddrPort()
	case *net.UDPAddr:
		return a.AddrPort()
	default:
		Log.Printf("unsupported address type: %T", a)
	}
	return netip.AddrPort{}
}

func Listen(addr netip.AddrPort) (net.PacketConn, error) {
	return listen(Log, addr)
}

func listen(log *log.Logger, addr netip.AddrPort) (net.PacketConn, error) {
	log.Printf("listen udp %s", addr)
	l, err := net.ListenUDP("udp4", net.UDPAddrFromAddrPort(addr))
	if err != nil {
		return nil, err
	}
	return l, nil
}

func ReadFrom(pc net.PacketConn, buf []byte) (int, netip.AddrPort, error) {
	return readFrom(DebugSockets, Log, pc, buf)
}

func readFrom(debug bool, log *log.Logger, pc net.PacketConn, buf []byte) (int, netip.AddrPort, error) {
	n, src, err := pc.ReadFrom(buf)
	ap := GetAddr(src)
	if err != nil {
		Log.Println(err)
		return n, ap, err
	}
	if debug {
		log.Printf("recv %s -> %s [%d]\n%x", ap, pc.LocalAddr(), n, buf[:n])
	}
	return n, ap, nil
}

func WriteTo(pc net.PacketConn, buf []byte, addr netip.AddrPort) (int, error) {
	return writeTo(DebugSockets, Log, pc, buf, addr)
}

func writeTo(debug bool, log *log.Logger, pc net.PacketConn, buf []byte, addr netip.AddrPort) (int, error) {
	if debug {
		log.Printf("send %s -> %s [%d]\n%x", pc.LocalAddr(), addr, len(buf), buf)
	}
	n, err := pc.WriteTo(buf, net.UDPAddrFromAddrPort(addr))
	if err != nil {
		Log.Println(err)
		return 0, err
	}
	return n, nil
}

func CanReadConn(pc net.PacketConn) (int, error) {
	return canReadConn(DebugSockets, Log, pc)
}

func canReadConn(debug bool, log *log.Logger, pc net.PacketConn) (int, error) {
	if pc == nil {
		panic(errors.New("nil connection"))
	}
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
		return 0, err
	}
	if ierr == 0 {
		return int(cnt), nil
	}
	if debug {
		log.Printf("can read: %d", cnt)
	}
	return int(cnt), ierr
}
