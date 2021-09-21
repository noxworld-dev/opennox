package tainted

/*
#include "server__script__script.h"
#include "server__script__internal.h"
extern int nox_script_count_xxx_1599640;
extern nox_script_xxx_t* nox_script_arr_xxx_1599636;
*/
import "C"
import (
	"strings"
	"unsafe"

	"nox/v1/server/script"
)

//export nox_script_callOnEvent
func nox_script_callOnEvent(cevent *C.char, a1, a2 C.int) {
	if a1 != 0 || a2 != 0 { // these are never set to anything
		panic("unexpected argument to nox_script_callOnEvent")
	}
	event := script.EventType(GoString(cevent))
	scriptOnEvent(event)
}

func noxscriptOnEvent(event script.EventType) {
	for i := 0; i < int(C.nox_script_count_xxx_1599640); i++ {
		sc := (*C.nox_script_xxx_t)(unsafe.Pointer(uintptr(unsafe.Pointer(C.nox_script_arr_xxx_1599636)) + unsafe.Sizeof(C.nox_script_xxx_t{})*uintptr(i)))
		name := GoString(sc.field_0)
		if strings.HasPrefix(name, string(event)) {
			C.nox_script_callByIndex_507310(C.int(i), 0, nil)
		}
	}
}
