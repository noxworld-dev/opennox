package legacy

import "unsafe"

// nox_xxx_guiFontPtrByName_43F360
func nox_xxx_guiFontPtrByName_43F360(cname *byte) unsafe.Pointer {
	name := GoString(cname)
	return GetClient().R2().GetFonts().FontPtrByName(name)
}

func Set_dword_5d4594_816444(v int) {
	dword_5d4594_816444 = uint32(v)
}
