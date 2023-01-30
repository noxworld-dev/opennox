//go:build windows

package memguard

import (
	"unsafe"

	"golang.org/x/sys/windows"
)

func newPage(size int) ([]byte, func()) {
	page := PageSize()
	num := size / page
	if size%page != 0 {
		num++
	}
	addr, err := windows.VirtualAlloc(0, uintptr(page*num), windows.MEM_RESERVE, windows.PAGE_NOACCESS)
	if err != nil {
		panic(err)
	}
	b := unsafe.Slice((*byte)(unsafe.Pointer(addr)), size)
	return b, func() {
		if err := windows.VirtualFree(addr, 0, windows.MEM_RELEASE); err != nil {
			panic(err)
		}
	}
}
