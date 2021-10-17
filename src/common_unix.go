//go:build linux
// +build linux

package nox

import "syscall"

func fdWrite(fd int, buf []byte) int {
	n, _ := syscall.Write(fd, buf[:])
	return n
}

func fdRead(fd int, buf []byte) int {
	n, _ := syscall.Read(fd, buf[:])
	return n
}
