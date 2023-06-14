package legacy

import (
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func internCStr(s string) *byte {
	p := alloc.InternCString(s)
	return p
}

func internWStr(s string) *wchar2_t {
	p := alloc.InternCString16(s)
	return p
}

// nox_strman_loadString_40F1D0
func nox_strman_loadString_40F1D0(name *byte, strOut **byte, srcFile *byte, srcLine int) *wchar2_t {
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
func nox_strman_get_lang_code() int32 {
	return int32(GetServer().S().Strings().Lang())
}
