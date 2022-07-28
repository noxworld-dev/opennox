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

func Malloc(size uintptr) (unsafe.Pointer, func()) {
	if size == 0 {
		panic("zero alloc")
	}
	ptr := C.calloc(1, C.size_t(size))
	if ptr == nil {
		panic("cannot allocate")
	}
	allocMu.Lock()
	allocs[ptr] = size
	allocMu.Unlock()
	return ptr, func() {
		Free(ptr)
	}
}

type number interface {
	~int | ~int8 | ~int16 | ~int32 | ~int64 |
		~uint | ~uint8 | ~uint16 | ~uint32 | ~uint64 |
		~uintptr
}

// New is an analog of builtin new that allocates on C heap.
// Since passing types as parameters is not supported, the first argument must be a value, instead of a type.
func New[T comparable](zero T) (*T, func()) {
	ptr, free := Malloc(unsafe.Sizeof(zero))
	return (*T)(ptr), free
}

// Make is an analog of builtin make that allocates on C heap.
// Since passing types as parameters is not supported, the first argument must be a slice value, instead of a type.
// If the slice value is not empty, the content of it will be copied to the beginning of a new slice.
func Make[T comparable, N number](src []T, n N) ([]T, func()) {
	var elem T
	ptr, free := Calloc(int(n), unsafe.Sizeof(elem))
	out := unsafe.Slice((*T)(ptr), n)
	copy(out, src)
	return out, free
}

// CloneSlice copies the slice to the C heap.
func CloneSlice[T comparable](src []T) ([]T, func()) {
	return Make(src, len(src))
}

func Realloc(ptr unsafe.Pointer, size uintptr) unsafe.Pointer {
	if size == 0 {
		panic("zero alloc")
	}
	old := ptr
	ptr = C.realloc(ptr, C.size_t(size))
	allocMu.Lock()
	if ptr != old {
		delete(allocs, old)
	}
	allocs[ptr] = size
	allocMu.Unlock()
	return ptr
}

func Calloc(num int, size uintptr) (unsafe.Pointer, func()) {
	if uintptr(num)*size == 0 {
		panic("zero alloc")
	}
	ptr := C.calloc(C.size_t(num), C.size_t(size))
	allocMu.Lock()
	allocs[ptr] = uintptr(num) * size
	allocMu.Unlock()
	return ptr, func() {
		Free(ptr)
	}
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

func FreeSlice[T comparable](b []T) {
	b = b[:1]
	Free(unsafe.Pointer(&b[0]))
}

func Memset(ptr unsafe.Pointer, v byte, size uintptr) unsafe.Pointer {
	logMemWrite(ptr, size)
	return C.memset(ptr, C.int(v), C.size_t(size))
}

func Memcpy(dst, src unsafe.Pointer, size uintptr) unsafe.Pointer {
	logMemRead(src, size)
	logMemWrite(dst, size)
	return C.memcpy(dst, src, C.size_t(size))
}

func Memcmp(ptr1, ptr2 unsafe.Pointer, size uintptr) int {
	logMemRead(ptr1, size)
	logMemRead(ptr2, size)
	return int(C.memcmp(ptr1, ptr2, C.size_t(size)))
}

func strlen[T comparable](s *T) int {
	if s == nil {
		return 0
	}
	var zero T
	elem := unsafe.Sizeof(zero)
	n := 0
	for *s != zero {
		n++
		s = (*T)(unsafe.Add(unsafe.Pointer(s), elem))
	}
	return n
}

func strlenN[T comparable](s *T, max int) int {
	if s == nil {
		return 0
	}
	var zero T
	elem := unsafe.Sizeof(zero)
	n := 0
	for *s != zero {
		s = (*T)(unsafe.Add(unsafe.Pointer(s), elem))
		if n == max {
			return n
		}
		n++
	}
	return n
}

func ZeroTermLen[T comparable](s *T) int {
	return strlen(s)
}

func StrLen[T number](s *T) int {
	if s == nil {
		return 0
	}
	n := strlen(s)
	logMemReadString(unsafe.Pointer(s), uintptr(n+1))
	return n
}

func StrLenN[T number](s *T, max int) int {
	if s == nil {
		return 0
	}
	n := strlenN(s, max)
	logMemReadString(unsafe.Pointer(s), uintptr(max))
	return n
}

func Strlen(ptr unsafe.Pointer) int {
	return StrLen((*byte)(ptr))
}

func Strcpy(dst, src unsafe.Pointer) unsafe.Pointer {
	n := uintptr(strlen((*byte)(src)))
	logMemReadString(src, n+1)
	logMemWriteString(dst, n+1)
	return unsafe.Pointer(C.strcpy((*C.char)(dst), (*C.char)(src)))
}

func Strcat(dst, src unsafe.Pointer) unsafe.Pointer {
	ns := uintptr(strlen((*byte)(src)))
	nd := uintptr(strlen((*byte)(dst)))
	logMemReadString(src, ns+1)
	logMemWriteString(dst, nd+ns+1)
	return unsafe.Pointer(C.strcat((*C.char)(dst), (*C.char)(src)))
}

func Strcmp(str1, str2 unsafe.Pointer) int {
	n1 := uintptr(strlen((*byte)(str1)))
	n2 := uintptr(strlen((*byte)(str2)))
	logMemReadString(str1, n1+1)
	logMemReadString(str2, n2+1)
	return int(C.strcmp((*C.char)(str1), (*C.char)(str2)))
}
