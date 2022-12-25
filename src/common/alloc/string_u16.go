package alloc

import (
	"sync"
	"unicode/utf16"
	"unsafe"
)

var (
	smu16     sync.RWMutex
	strings16 = make(map[string]*uint16)
)

func freeIntern16() {
	smu16.Lock()
	defer smu16.Unlock()
	for _, v := range strings16 {
		Free(unsafe.Pointer(v))
	}
	strings16 = make(map[string]*uint16)
}

// CString16 is similar to CString, but makes a UTF16 C string.
// It also returns a free function, so that it's harder to forget it.
func CString16(s string) (*uint16, func()) {
	wstr := utf16.Encode([]rune(s))
	arr, free := Make([]uint16{}, len(wstr)+1)
	copy(arr, wstr)
	arr[len(arr)-1] = 0
	return &arr[0], free
}

// InternCString16 is similar to CString16, but allocates a string as a constant.
// Multiple calls with the same string will lead to the same pointer.
// Caller MUST NOT free the pointer!
func InternCString16(s string) *uint16 {
	smu16.RLock()
	p := strings16[s]
	smu16.RUnlock()
	if p != nil {
		return p
	}
	smu16.Lock()
	defer smu16.Unlock()
	p = strings16[s]
	if p != nil {
		return p
	}
	p, _ = CString16(s)
	strings16[s] = p
	return p
}

// GoString16 is similar to GoString, but accepts a UTF16 string (*wchar_t).
func GoString16(p *uint16) string {
	if p == nil {
		return ""
	}
	n := StrLen(p)
	arr := unsafe.Slice(p, n)
	return string(utf16.Decode(arr))
}

// GoString16S is similar to GoWString16, but accepts a slice and finds a null terminator there.
func GoString16S(p []uint16) string {
	if len(p) == 0 {
		return ""
	}
	n := StrLenS(p)
	return string(utf16.Decode(p[:n]))
}

// StrCopy16P will copy a UTF16 C string from src to dst.
// It will NOT add a zero terminator if len(src) == len(dst).
func StrCopy16P(dst []uint16, src *uint16) int {
	n := StrLen(src)
	sarr := unsafe.Slice(src, n)
	n = copy(dst, sarr)
	if n < len(dst) {
		dst[n] = 0
	}
	return n
}

// StrCopyZero16P will copy a UTF16 C string from src to dst.
// It will ALWAYS add a zero terminator.
func StrCopyZero16P(dst []uint16, src *uint16) int {
	n := StrLen(src)
	sarr := unsafe.Slice(src, n)
	n = copy(dst, sarr)
	if n == len(dst) {
		n = len(dst) - 1
	}
	dst[n] = 0
	return n
}

// StrCopy16S will copy a UTF16 C string from src to dst.
// It will NOT add a zero terminator if len(src) == len(dst).
func StrCopy16S(dst []uint16, src []uint16) int {
	n := StrLenS(src)
	n = copy(dst, src[:n])
	if n < len(dst) {
		dst[n] = 0
	}
	return n
}

// StrCopyZero16S will copy a C string from src to dst.
// It will ALWAYS add a zero terminator.
func StrCopyZero16S(dst []uint16, src []uint16) int {
	n := StrLenS(src)
	n = copy(dst, src[:n])
	if n == len(dst) {
		n = len(dst) - 1
	}
	dst[n] = 0
	return n
}

// StrCopy16 will copy a UTF16 C string from src to dst.
// It will NOT add a zero terminator if len(src) == len(dst).
func StrCopy16(dst []uint16, src string) int {
	wstr := utf16.Encode([]rune(src))
	n := copy(dst, wstr)
	if n < len(dst) {
		dst[n] = 0
	}
	return n
}

// StrCopyZero16 will copy a UTF16 C string from src to dst.
// It will ALWAYS add a zero terminator.
func StrCopyZero16(dst []uint16, src string) int {
	wstr := utf16.Encode([]rune(src))
	n := copy(dst, wstr)
	if n == len(dst) {
		n = len(dst) - 1
	}
	dst[n] = 0
	return n
}
