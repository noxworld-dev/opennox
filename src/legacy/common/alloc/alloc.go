package alloc

import (
	"fmt"
	"runtime"
	"sync"
	"unsafe"
)

var (
	allocMu sync.Mutex
	allocs  = make(map[unsafe.Pointer]uintptr)
	freed   = make(map[unsafe.Pointer]string)
)

const (
	trackFree          = false
	removeFreedOnAlloc = false
)

func Malloc(size uintptr) (unsafe.Pointer, func()) {
	if size == 0 {
		panic("zero alloc")
	}
	ptr := calloc(1, size)
	if ptr == nil {
		panic("cannot allocate")
	}
	allocMu.Lock()
	allocs[ptr] = size
	if trackFree && removeFreedOnAlloc {
		delete(freed, ptr)
	}
	allocMu.Unlock()
	return ptr, func() {
		freePtr(ptr, 1)
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
	if n < 0 {
		panic("negative size")
	}
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
	ptr = realloc(ptr, size)
	allocMu.Lock()
	if ptr != old {
		delete(allocs, old)
		if trackFree {
			freed[ptr] = caller(1)
		}
	}
	allocs[ptr] = size
	allocMu.Unlock()
	return ptr
}

func ReallocT[T comparable, N number](src []T, n N) []T {
	if n < 0 {
		panic("negative size")
	}
	src = src[:1]
	var elem T
	dstp := Realloc(unsafe.Pointer(&src[0]), uintptr(n)*unsafe.Sizeof(elem))
	return unsafe.Slice((*T)(dstp), n)
}

func Calloc(num int, size uintptr) (unsafe.Pointer, func()) {
	ptr := Calloc1(num, size)
	return ptr, func() {
		freePtr(ptr, 1)
	}
}

func Calloc1(num int, size uintptr) unsafe.Pointer {
	if uintptr(num)*size == 0 {
		panic("zero alloc")
	}
	ptr := calloc(uintptr(num), size)
	allocMu.Lock()
	allocs[ptr] = uintptr(num) * size
	if trackFree && removeFreedOnAlloc {
		delete(freed, ptr)
	}
	allocMu.Unlock()
	return ptr
}

func FreePtr(ptr unsafe.Pointer) {
	freePtr(ptr, 1)
}

func freePtr(ptr unsafe.Pointer, skip int) {
	var from string
	allocMu.Lock()
	_, ok := allocs[ptr]
	delete(allocs, ptr)
	if trackFree {
		if ok {
			freed[ptr] = caller(skip + 1)
		} else {
			from = freed[ptr]
		}
	}
	allocMu.Unlock()
	if !ok {
		if from != "" {
			panic("incorrect free: already freed from " + from)
		} else {
			panic("incorrect free")
		}
	}
	free(ptr)
}

func caller(skip int) string {
	pc, file, line, ok := runtime.Caller(skip + 1)
	if !ok {
		return "<unknown>"
	}
	fnc := "<unknown>"
	if f := runtime.FuncForPC(pc); f != nil {
		fnc = f.Name()
	}
	return fmt.Sprintf("%s, %s:%d", fnc, file, line)
}

func Free[T comparable](ptr *T) {
	freePtr(unsafe.Pointer(ptr), 1)
}

func FreeSlice[T comparable](b []T) {
	b = b[:1]
	Free(&b[0])
}

func Memset(ptr unsafe.Pointer, v byte, size uintptr) unsafe.Pointer {
	logMemWrite(ptr, size)
	return memset(ptr, int(v), size)
}

func Memcpy(dst, src unsafe.Pointer, size uintptr) unsafe.Pointer {
	logMemRead(src, size)
	logMemWrite(dst, size)
	return memcpy(dst, src, size)
}

func Memcmp(ptr1, ptr2 unsafe.Pointer, size uintptr) int {
	logMemRead(ptr1, size)
	logMemRead(ptr2, size)
	return memcmp(ptr1, ptr2, size)
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

func strlenS[T comparable](s []T) int {
	if s == nil {
		return 0
	}
	var zero T
	for i, v := range s {
		if v == zero {
			return i
		}
	}
	return len(s)
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

func StrLenS[T number](s []T) int {
	if len(s) == 0 {
		return 0
	}
	n := strlenS(s)
	logMemReadString(unsafe.Pointer(&s[0]), uintptr(len(s)))
	return n
}

func Strlen(ptr unsafe.Pointer) int {
	return StrLen((*byte)(ptr))
}

func Strcpy(dst, src unsafe.Pointer) unsafe.Pointer {
	n := uintptr(strlen((*byte)(src)))
	logMemReadString(src, n+1)
	logMemWriteString(dst, n+1)
	return strcpy(dst, src)
}

func Strcat(dst, src unsafe.Pointer) unsafe.Pointer {
	ns := uintptr(strlen((*byte)(src)))
	nd := uintptr(strlen((*byte)(dst)))
	logMemReadString(src, ns+1)
	logMemWriteString(dst, nd+ns+1)
	return strcat(dst, src)
}

func Strcmp(str1, str2 unsafe.Pointer) int {
	n1 := uintptr(strlen((*byte)(str1)))
	n2 := uintptr(strlen((*byte)(str2)))
	logMemReadString(str1, n1+1)
	logMemReadString(str2, n2+1)
	return strcmp(str1, str2)
}
