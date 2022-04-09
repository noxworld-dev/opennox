package opennox

import (
	"unsafe"
)

const ptrSize = unsafe.Sizeof(unsafe.Pointer(nil))

func PtrArrLen(p unsafe.Pointer) int {
	if p == nil {
		return 0
	}
	ptr := (*unsafe.Pointer)(p)
	n := 0
	for *ptr != nil {
		n++
		ptr = (*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(ptr), ptrSize))
	}
	return n
}
