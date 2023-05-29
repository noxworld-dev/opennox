package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func internCStr(s string) *char {
	p := alloc.InternCString(s)
	return (*char)(unsafe.Pointer(p))
}

func internWStr(s string) *wchar2_t {
	p := alloc.InternCString16(s)
	return (*wchar2_t)(unsafe.Pointer(p))
}

// nox_strman_loadString_40F1D0
func nox_strman_loadString_40F1D0(name *char, strOut **char, srcFile *char, srcLine int) *wchar2_t {
	if strOut != nil {
		*strOut = nil
		v, _ := GetServer().S().Strings().GetVariantInFile(strman.ID(GoString(name)), GoString(srcFile))
		*strOut = internCStr(v.Str2)
		return internWStr(v.Str)
	}
	s := GetServer().S().Strings().GetStringInFile(strman.ID(GoString(name)), GoString(srcFile))
	return internWStr(s)
}

// nox_strman_get_lang_code
func nox_strman_get_lang_code() int {
	return GetServer().S().Strings().Lang()
}
