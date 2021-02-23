package main

/*
#include <stddef.h>
#include <stdlib.h>
*/
import "C"
import (
	"reflect"
	"unicode/utf16"
	"unsafe"
)

func StrFree(s *C.char) {
	C.free(unsafe.Pointer(s))
}

func WStrFree(s *C.wchar_t) {
	C.free(unsafe.Pointer(s))
}

func WStrSliceFree(arr []*C.wchar_t) {
	for _, p := range arr {
		WStrFree(p)
	}
	C.free(unsafe.Pointer(&arr[0]))
}

func CStringArray(arr []string) []*C.char {
	out := make([]*C.char, 0, len(arr)+1)
	for _, arg := range arr {
		out = append(out, C.CString(arg))
	}
	out = append(out, nil)
	return out[:len(arr):len(arr)]
}

func asByteSlice(p unsafe.Pointer, sz int) (out []byte) {
	*(*reflect.SliceHeader)(unsafe.Pointer(&out)) = reflect.SliceHeader{
		Data: uintptr(p),
		Len:  sz, Cap: sz,
	}
	return
}

func asU16Slice(p unsafe.Pointer, sz int) (out []uint16) {
	*(*reflect.SliceHeader)(unsafe.Pointer(&out)) = reflect.SliceHeader{
		Data: uintptr(p),
		Len:  sz, Cap: sz,
	}
	return
}

func asU32Slice(p unsafe.Pointer, sz int) (out []uint32) {
	*(*reflect.SliceHeader)(unsafe.Pointer(&out)) = reflect.SliceHeader{
		Data: uintptr(p),
		Len:  sz, Cap: sz,
	}
	return
}

func asWStr(p unsafe.Pointer, sz int) (out []C.wchar_t) {
	*(*reflect.SliceHeader)(unsafe.Pointer(&out)) = reflect.SliceHeader{
		Data: uintptr(p),
		Len:  sz, Cap: sz,
	}
	return
}

func asWStrSlice(p unsafe.Pointer, sz int) (out []*C.wchar_t) {
	*(*reflect.SliceHeader)(unsafe.Pointer(&out)) = reflect.SliceHeader{
		Data: uintptr(p),
		Len:  sz, Cap: sz,
	}
	return
}

func StrLen(s *C.char) int {
	if s == nil {
		return 0
	}
	n := 0
	for *s != 0 {
		n++
		s = (*C.char)(unsafe.Pointer(uintptr(unsafe.Pointer(s)) + 1))
	}
	return n
}

func WStrLen(s *C.wchar_t) int {
	if s == nil {
		return 0
	}
	n := 0
	for *s != 0 {
		n++
		s = (*C.wchar_t)(unsafe.Pointer(uintptr(unsafe.Pointer(s)) + 2))
	}
	return n
}

func GoString(s *C.char) string {
	return C.GoString(s)
}

func CString(s string) *C.char {
	return C.CString(s)
}

func GoWString(s *C.wchar_t) string {
	n := WStrLen(s)
	if n == 0 {
		return ""
	}
	arr := asU16Slice(unsafe.Pointer(s), n)
	return string(utf16.Decode(arr))
}

func CWString(s string) *C.wchar_t {
	buf := utf16.Encode([]rune(s))
	ptr := C.calloc(C.uint(len(buf)+1), 2)
	copy(asU16Slice(ptr, len(buf)), buf)
	return (*C.wchar_t)(ptr)
}

func CWStringCopyTo(dst *C.wchar_t, dstSz int, src string) {
	str := asU16Slice(unsafe.Pointer(dst), dstSz)
	n := copy(str, utf16.Encode([]rune(src)))
	str[n] = 0
}

func GoWStrSlice(arr **C.wchar_t) []string {
	n := PtrArrLen(unsafe.Pointer(arr))
	return GoWStrSliceN(arr, n)
}

func GoWStrSliceN(arr **C.wchar_t, n int) []string {
	if n == 0 {
		return nil
	}
	out := make([]string, 0, n)
	for _, c := range asWStrSlice(unsafe.Pointer(arr), n) {
		out = append(out, GoWString(c))
	}
	return out
}

func CWStrSlice(arr []string) []*C.wchar_t {
	ptr := C.calloc(C.uint(len(arr)+1), C.uint(ptrSize))
	out := asWStrSlice(ptr, len(arr))
	for i, s := range arr {
		out[i] = CWString(s)
	}
	return out
}
