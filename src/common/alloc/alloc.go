package alloc

/*
#include <stdlib.h>
#include <string.h>
*/
import "C"
import (
	"sync"
	"unsafe"
)

var (
	allocMu sync.Mutex
	allocs  = make(map[unsafe.Pointer]uintptr)
)

func Malloc(size uintptr) unsafe.Pointer {
	if size == 0 {
		panic("zero alloc")
	}
	ptr := C.calloc(1, C.uint(size))
	allocMu.Lock()
	allocs[ptr] = size
	allocMu.Unlock()
	return ptr
}

func Realloc(ptr unsafe.Pointer, size uintptr) unsafe.Pointer {
	if size == 0 {
		panic("zero alloc")
	}
	old := ptr
	ptr = C.realloc(ptr, C.uint(size))
	allocMu.Lock()
	if ptr != old {
		delete(allocs, old)
	}
	allocs[ptr] = size
	allocMu.Unlock()
	return ptr
}

func Calloc(num, size uintptr) unsafe.Pointer {
	if num*size == 0 {
		panic("zero alloc")
	}
	ptr := C.calloc(C.uint(num), C.uint(size))
	allocMu.Lock()
	allocs[ptr] = num * size
	allocMu.Unlock()
	return ptr
}

func Free(ptr unsafe.Pointer) {
	allocMu.Lock()
	_, ok := allocs[ptr]
	delete(allocs, ptr)
	allocMu.Unlock()
	if !ok {
		panic("incorrect free")
	}
	C.free(ptr)
}

func Memset(ptr unsafe.Pointer, v byte, size uintptr) unsafe.Pointer {
	logMemWrite(ptr, size)
	return C.memset(ptr, C.int(v), C.uint(size))
}

func Memcpy(dst, src unsafe.Pointer, size uintptr) unsafe.Pointer {
	logMemRead(src, size)
	logMemWrite(dst, size)
	return C.memcpy(dst, src, C.uint(size))
}

func Memcmp(ptr1, ptr2 unsafe.Pointer, size uintptr) int {
	logMemRead(ptr1, size)
	logMemRead(ptr2, size)
	return int(C.memcmp(ptr1, ptr2, C.uint(size)))
}

func Strlen(ptr unsafe.Pointer) int {
	n := int(C.strlen((*C.char)(ptr)))
	logMemReadString(ptr, uintptr(n+1))
	return n
}

func Strcpy(dst, src unsafe.Pointer) unsafe.Pointer {
	n := uintptr(C.strlen((*C.char)(src)))
	logMemReadString(src, n+1)
	logMemWriteString(dst, n+1)
	return unsafe.Pointer(C.strcpy((*C.char)(dst), (*C.char)(src)))
}

func Strcat(dst, src unsafe.Pointer) unsafe.Pointer {
	ns := uintptr(C.strlen((*C.char)(src)))
	nd := uintptr(C.strlen((*C.char)(dst)))
	logMemReadString(src, ns+1)
	logMemWriteString(dst, nd+ns+1)
	return unsafe.Pointer(C.strcat((*C.char)(dst), (*C.char)(src)))
}

func Strcmp(str1, str2 unsafe.Pointer) int {
	n1 := uintptr(C.strlen((*C.char)(str1)))
	n2 := uintptr(C.strlen((*C.char)(str2)))
	logMemReadString(str1, n1+1)
	logMemReadString(str2, n2+1)
	return int(C.strcmp((*C.char)(str1), (*C.char)(str2)))
}
