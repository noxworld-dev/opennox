//+build safe

package blobs

/*
#cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
#cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
#cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup
#cgo CFLAGS: -DNOX_CGO
*/
import "C"

//export mem_getPtr
func mem_getPtr(base, off C.uintptr_t) unsafe.Pointer {
	return Ptr(uintptr(base), uintptr(off))
}

//export mem_getPtrSize
func mem_getPtrSize(base, off, size C.uintptr_t) unsafe.Pointer {
	return PtrSize(uintptr(base), uintptr(off), uintptr(size))
}
