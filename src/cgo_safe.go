//+build safe

package main

/*
#cgo CFLAGS: -DNOX_CGO_MEMMAP
typedef unsigned int uintptr_t;
*/
import "C"
import (
	"nox/common/memmap"
	"unsafe"
)

func init() {
	memmap.SetRuntimeChecks(true)
}

//export mem_getPtr
func mem_getPtr(base, off C.uintptr_t) unsafe.Pointer {
	return memmap.PtrOff(uintptr(base), uintptr(off))
}

//export mem_getPtrSize
func mem_getPtrSize(base, off, size C.uintptr_t) unsafe.Pointer {
	return memmap.PtrSizeOff(uintptr(base), uintptr(off), uintptr(size))
}
