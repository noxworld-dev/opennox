package opennox

/*
#include <stddef.h>
#include <stdlib.h>
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

var (
	strMan     = strman.New()
	strManDone = false
)

func internCStr(s string) *C.char {
	p := alloc.InternCString(s)
	return (*C.char)(unsafe.Pointer(p))
}

func internWStr(s string) *C.wchar_t {
	p := alloc.InternCString16(s)
	return (*C.wchar_t)(unsafe.Pointer(p))
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
func nox_strman_loadString_40F1D0(name *C.char, strOut **C.char, srcFile *C.char, srcLine int) *C.wchar_t {
	if strOut != nil {
		*strOut = nil
		v, _ := strMan.GetVariantInFile(strman.ID(GoString(name)), GoString(srcFile))
		*strOut = internCStr(v.Str2)
		return internWStr(v.Str)
	}
	s := strMan.GetStringInFile(strman.ID(GoString(name)), GoString(srcFile))
	return internWStr(s)
}

func nox_strman_free_410020() {
	strMan = strman.New()
	strManDone = false
	alloc.FreeStrings()
}

//export nox_strman_get_lang_code
func nox_strman_get_lang_code() int {
	return strMan.Lang()
}
