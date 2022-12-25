package alloc

import (
	"sync"
	"unsafe"
)

var (
	smu8     sync.RWMutex
	strings8 = make(map[string]*byte)
)

// FreeStrings frees string constants created by InternCString and InternCString16.
func FreeStrings() {
	freeIntern8()
	freeIntern16()
}

func freeIntern8() {
	smu8.Lock()
	defer smu8.Unlock()
	for _, v := range strings8 {
		Free(unsafe.Pointer(v))
	}
	strings8 = make(map[string]*byte)
}

// CString is similar to C.CString, but with portable return type.
// It also returns a free function, so that it's harder to forget it.
func CString(s string) (*byte, func()) {
	arr, free := Make([]byte{}, len(s)+1)
	copy(arr, s)
	arr[len(arr)-1] = 0
	return &arr[0], free
}

// InternCString is similar to CString, but allocates a string as a constant.
// Multiple calls with the same string will lead to the same pointer.
// Caller MUST NOT free the pointer!
func InternCString(s string) *byte {
	smu8.RLock()
	p := strings8[s]
	smu8.RUnlock()
	if p != nil {
		return p
	}
	smu8.Lock()
	defer smu8.Unlock()
	p = strings8[s]
	if p != nil {
		return p
	}
	p, _ = CString(s)
	strings8[s] = p
	return p
}

// GoString is similar to C.GoString, but with a portable argument type.
func GoString(p *byte) string {
	n := StrLen(p)
	arr := unsafe.Slice(p, n)
	return string(arr)
}

// GoStringS is similar to GoString, but accepts a slice and finds a null terminator there.
func GoStringS(p []byte) string {
	n := StrLenS(p)
	return string(p[:n])
}

// StrCopyP will copy a C string from src to dst.
// It will NOT add a zero terminator if len(src) == len(dst).
func StrCopyP(dst []byte, src *byte) int {
	n := StrLen(src)
	sarr := unsafe.Slice(src, n)
	n = copy(dst, sarr)
	if n < len(dst) {
		dst[n] = 0
	}
	return n
}

// StrCopyZeroP will copy a C string from src to dst.
// It will ALWAYS add a zero terminator.
func StrCopyZeroP(dst []byte, src *byte) int {
	n := StrLen(src)
	sarr := unsafe.Slice(src, n)
	n = copy(dst, sarr)
	if n == len(dst) {
		n = len(dst) - 1
	}
	dst[n] = 0
	return n
}

// StrCopyS will copy a C string from src to dst.
// It will NOT add a zero terminator if len(src) == len(dst).
func StrCopyS(dst []byte, src []byte) int {
	n := StrLenS(src)
	n = copy(dst, src[:n])
	if n < len(dst) {
		dst[n] = 0
	}
	return n
}

// StrCopyZeroS will copy a C string from src to dst.
// It will ALWAYS add a zero terminator.
func StrCopyZeroS(dst []byte, src []byte) int {
	n := StrLenS(src)
	n = copy(dst, src[:n])
	if n == len(dst) {
		n = len(dst) - 1
	}
	dst[n] = 0
	return n
}

// StrCopy will copy a C string from src to dst.
// It will NOT add a zero terminator if len(src) == len(dst).
func StrCopy(dst []byte, src string) int {
	n := copy(dst, src)
	if n < len(dst) {
		dst[n] = 0
	}
	return n
}

// StrCopyZero will copy a C string from src to dst.
// It will ALWAYS add a zero terminator.
func StrCopyZero(dst []byte, src string) int {
	n := copy(dst, src)
	if n == len(dst) {
		n = len(dst) - 1
	}
	dst[n] = 0
	return n
}
