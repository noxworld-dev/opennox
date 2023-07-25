//go:build cgo

package alloc

/*
#include <stdlib.h>
#include <string.h>
*/
import "C"
import "unsafe"

func calloc(num, size uintptr) unsafe.Pointer {
	return C.calloc(C.size_t(num), C.size_t(size))
}

func free(p unsafe.Pointer) {
	C.free(p)
}

func realloc(p unsafe.Pointer, size uintptr) unsafe.Pointer {
	return C.realloc(p, C.size_t(size))
}

func memset(p unsafe.Pointer, v int, size uintptr) unsafe.Pointer {
	return C.memset(p, C.int(v), C.size_t(size))
}

func memcpy(p1, p2 unsafe.Pointer, size uintptr) unsafe.Pointer {
	return C.memcpy(p1, p2, C.size_t(size))
}

func memcmp(p1, p2 unsafe.Pointer, size uintptr) int {
	return int(C.memcmp(p1, p2, C.size_t(size)))
}

func strcpy(p1, p2 unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer(C.strcpy((*C.char)(p1), (*C.char)(p2)))
}

func strcat(p1, p2 unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer(C.strcat((*C.char)(p1), (*C.char)(p2)))
}

func strcmp(p1, p2 unsafe.Pointer) int {
	return int(C.strcmp((*C.char)(p1), (*C.char)(p2)))
}
