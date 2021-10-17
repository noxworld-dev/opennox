//go:build windows
// +build windows

package nox

import "syscall"

func fdWrite(fd int, buf []byte) int {
	n, _ := syscall.Write(syscall.Handle(fd), buf[:])
	return n
}

func fdRead(fd int, buf []byte) int {
	n, _ := syscall.Read(syscall.Handle(fd), buf[:])
	return n
}
