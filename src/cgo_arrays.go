package nox

import (
	"reflect"
	"unsafe"
)

const ptrSize = unsafe.Sizeof(unsafe.Pointer(nil))

func asPtrSlice(p unsafe.Pointer, sz int) (out []unsafe.Pointer) {
	*(*reflect.SliceHeader)(unsafe.Pointer(&out)) = reflect.SliceHeader{
		Data: uintptr(p),
		Len:  sz, Cap: sz,
	}
	return
}

func PtrArrLen(p unsafe.Pointer) int {
	if p == nil {
		return 0
	}
	ptr := (*unsafe.Pointer)(p)
	n := 0
	for *ptr != nil {
		n++
		ptr = (*unsafe.Pointer)(unsafe.Pointer(uintptr(unsafe.Pointer(ptr)) + ptrSize))
	}
	return n
}
