//go:build windows
// +build windows

package nox

/*
#include <winsock2.h>
*/
import "C"
import (
	"errors"
	"syscall"
)

func netCanRead(fd uintptr) (uint32, syscall.Errno) {
	var n C.ulong
	r, err := C.ioctlsocket(C.uint(fd), C.FIONREAD, &n)
	if r != 0 {
		var ierr syscall.Errno
		if errors.As(err, &ierr) {
			return uint32(n), ierr
		}
		return uint32(n), 12345 // TODO
	}
	return uint32(n), 0
}
