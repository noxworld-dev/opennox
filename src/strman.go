package main

/*
#include <wchar.h>
#include <stdlib.h>
*/
import "C"
import (
	"log"
	"reflect"
	"unicode/utf16"
	"unsafe"

	"nox/common/strman"
)

var (
	strMan     = strman.New()
	strManDone = false
	strManC    = make(map[string]*C.char)
	strManW    = make(map[string]*C.wchar_t)
)

func internCStr(s string) *C.char {
	p, ok := strManC[s]
	if ok {
		return p
	}
	p = C.CString(s)
	strManC[s] = p
	return p
}

func asU16Slice(p unsafe.Pointer, sz int) (out []uint16) {
	*(*reflect.SliceHeader)(unsafe.Pointer(&out)) = reflect.SliceHeader{
		Data: uintptr(p),
		Len:  sz, Cap: sz,
	}
	return
}

func internWStr(s string) *C.wchar_t {
	p, ok := strManW[s]
	if ok {
		return p
	}
	buf := utf16.Encode([]rune(s))
	ptr := C.calloc(C.uint(len(buf)+1), 2)
	copy(asU16Slice(ptr, len(buf)), buf)
	p = (*C.wchar_t)(ptr)
	strManW[s] = p
	return p
}

//export nox_strman_readfile
func nox_strman_readfile(cpath *C.char) C.int {
	err := strmanReadFile(C.GoString(cpath))
	if err != nil {
		log.Println(err)
		return 0
	}
	return 1
}

func strmanReadFile(path string) error {
	if strManDone {
		return nil
	}
	err := strMan.ReadFile(path)
	if err != nil {
		return err
	}
	strManDone = true
	return nil
}

//export nox_strman_loadString_40F1D0
func nox_strman_loadString_40F1D0(name *C.char, strOut **C.char, srcFile *C.char, srcLine C.int) *C.wchar_t {
	if strOut != nil {
		*strOut = nil
		s1, s2 := strMan.GetString2InFile(C.GoString(srcFile), C.GoString(name))
		*strOut = internCStr(s2)
		return internWStr(s1)
	}
	s := strMan.GetStringInFile(C.GoString(srcFile), C.GoString(name))
	return internWStr(s)
}

//export nox_strman_free_410020
func nox_strman_free_410020() {
	strMan = strman.New()
	strManDone = false
	for _, p := range strManC {
		C.free(unsafe.Pointer(p))
	}
	for _, p := range strManW {
		C.free(unsafe.Pointer(p))
	}
	strManC = make(map[string]*C.char)
	strManW = make(map[string]*C.wchar_t)
}

//export nox_strman_get_lang_code
func nox_strman_get_lang_code() C.int {
	return C.int(strMan.Lang())
}
