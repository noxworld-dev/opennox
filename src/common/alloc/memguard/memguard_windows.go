//+build windows

package memguard

import (
	"reflect"
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
	var b []byte
	h := (*reflect.SliceHeader)(unsafe.Pointer(&b))
	h.Data = addr
	h.Len = size
	h.Cap = size

	return b, func() {
		if err := windows.VirtualFree(addr, 0, windows.MEM_RELEASE); err != nil {
			panic(err)
		}
	}
}
