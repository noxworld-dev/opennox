package nox

/*
#include <stddef.h>
#include <stdlib.h>
*/
import "C"
import (
	"unsafe"

	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promauto"

	"nox/v1/common/log"
	"nox/v1/common/strman"
)

var (
	strMan      = strman.New()
	strManDone  = false
	strManC     = make(map[string]*C.char)
	strManW     = make(map[string]*C.wchar_t)
	cntStringsC = promauto.NewCounter(prometheus.CounterOpts{
		Name: "nox_cgo_strings",
		Help: "The number of interned string values",
	})
	cntStringsW = promauto.NewCounter(prometheus.CounterOpts{
		Name: "nox_cgo_wstrings",
		Help: "The number of interned wide string values",
	})
)

func internCStr(s string) *C.char {
	p, ok := strManC[s]
	if ok {
		return p
	}
	p = CString(s)
	strManC[s] = p
	cntStringsC.Inc()
	return p
}

func internCBytes(b []byte) unsafe.Pointer {
	p, ok := strManC[string(b)]
	if ok {
		return unsafe.Pointer(p)
	}
	bp := CBytes(b)
	strManC[string(b)] = (*C.char)(bp)
	cntStringsC.Inc()
	return bp
}

func internWStr(s string) *C.wchar_t {
	p, ok := strManW[s]
	if ok {
		return p
	}
	p, _ = CWString(s)
	strManW[s] = p
	cntStringsW.Inc()
	return p
}

//export nox_strman_readfile
func nox_strman_readfile(cpath *C.char) C.int {
	err := strmanReadFile(GoString(cpath))
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
		v, _ := strMan.GetVariantInFile(strman.ID(GoString(name)), GoString(srcFile))
		*strOut = internCStr(v.Str2)
		return internWStr(v.Str)
	}
	s := strMan.GetStringInFile(strman.ID(GoString(name)), GoString(srcFile))
	return internWStr(s)
}

//export nox_strman_free_410020
func nox_strman_free_410020() {
	strMan = strman.New()
	strManDone = false
	for _, p := range strManC {
		StrFree(p)
	}
	for _, p := range strManW {
		WStrFree(p)
	}
	strManC = make(map[string]*C.char)
	strManW = make(map[string]*C.wchar_t)
}

//export nox_strman_get_lang_code
func nox_strman_get_lang_code() C.int {
	return C.int(strMan.Lang())
}
