package legacy

/*
#include <stdint.h>

extern uint32_t dword_5d4594_816444;
*/
import "C"
import "unsafe"

//export nox_xxx_guiFontPtrByName_43F360
func nox_xxx_guiFontPtrByName_43F360(cname *C.char) unsafe.Pointer {
	name := GoString(cname)
	return GetClient().R2().GetFonts().FontPtrByName(name)
}

func Set_dword_5d4594_816444(v int) {
	C.dword_5d4594_816444 = C.uint(v)
}
