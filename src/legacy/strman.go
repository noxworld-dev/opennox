package legacy

/*
#include <stddef.h>
#include <stdlib.h>
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func internCStr(s string) *C.char {
	p := alloc.InternCString(s)
	return (*C.char)(unsafe.Pointer(p))
}

func internWStr(s string) *C.wchar_t {
	p := alloc.InternCString16(s)
	return (*C.wchar_t)(unsafe.Pointer(p))
}

//export nox_strman_loadString_40F1D0
func nox_strman_loadString_40F1D0(name *C.char, strOut **C.char, srcFile *C.char, srcLine int) *C.wchar_t {
	if strOut != nil {
		*strOut = nil
		v, _ := GetServer().S().Strings().GetVariantInFile(strman.ID(GoString(name)), GoString(srcFile))
		*strOut = internCStr(v.Str2)
		return internWStr(v.Str)
	}
	s := GetServer().S().Strings().GetStringInFile(strman.ID(GoString(name)), GoString(srcFile))
	return internWStr(s)
}

//export nox_strman_get_lang_code
func nox_strman_get_lang_code() int {
	return GetServer().S().Strings().Lang()
}
