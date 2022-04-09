//go:build linux
// +build linux

package opennox

/*
#include <sys/ioctl.h>
*/
import "C"
import (
	"syscall"
	"unsafe"
)

func netCanRead(fd uintptr) (uint32, syscall.Errno) {
	var n uint32
	_, _, err := syscall.Syscall(syscall.SYS_IOCTL, fd, uintptr(C.FIONREAD), uintptr(unsafe.Pointer(&n)))
	return n, err
}
