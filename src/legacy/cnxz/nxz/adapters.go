package nxz

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func calloc(num int, size uintptr) unsafe.Pointer {
	p, _ := alloc.Calloc(num, size)
	return p
}

func free(p unsafe.Pointer) {
	alloc.FreePtr(p)
}

func memcpy(dst, src unsafe.Pointer, size int) {
	alloc.Memcpy(dst, src, uintptr(size))
}

func memset(ptr unsafe.Pointer, v byte, size int) {
	alloc.Memset(ptr, v, uintptr(size))
}

func abs[T ~int | ~int32 | ~int64](v T) T {
	if v < 0 {
		return -v
	}
	return v
}

func __ROL4__(value uint32, shift int32) uint32 {
	var c uint32 = uint32(shift & 31)
	if c == 0 {
		return value
	}
	return (value << c) | value>>(32-c)
}
