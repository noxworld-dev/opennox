package nox

/*
#include "server__script__script.h"
#include "server__script__internal.h"
#include "GAME4_1.h" // for nox_xxx_scriptPrepareFoundUnit_511D70 and nox_xxx_script_511C50
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
func nox_script_callOnEvent(cevent *C.char, a1, a2 unsafe.Pointer) {
	if a1 != nil || a2 != nil { // these are never set to anything
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
			C.nox_script_callByIndex_507310(C.int(i), nil, nil)
		}
	}
}

//export nox_server_scriptValToObjectPtr_511B60
func nox_server_scriptValToObjectPtr_511B60(val C.int) *C.nox_object_t {
	return nox_server_scriptValToObjectPtr(int(val)).CObj()
}

func nox_server_scriptValToObjectPtr(val int) *Object {
	if val == -1 {
		obj := asObject(C.nox_script_get_caller())
		if obj == nil || (obj.field_4&0x20) != 0 {
			return nil
		}
		return obj
	}
	if val == -2 {
		obj := asObject(C.nox_script_get_trigger())
		if obj == nil || (obj.field_4&0x20) != 0 {
			return nil
		}
		return obj
	}
	if obj := asObjectC(C.nox_xxx_script_511C50(C.int(val))); obj != nil {
		return obj
	}

	for obj := firstServerObject(); obj != nil; obj = obj.Next() {
		if (obj.field_4&0x20) == 0 && obj.ScriptID() == val {
			C.nox_xxx_scriptPrepareFoundUnit_511D70(obj.CObj())
			return obj
		}
		for sub := obj.FirstItem(); sub != nil; sub = sub.NextItem() {
			if (sub.field_4&0x20) == 0 && sub.ScriptID() == val {
				C.nox_xxx_scriptPrepareFoundUnit_511D70(sub.CObj())
				return sub
			}
		}
	}
	for obj := firstServerObjectUninited(); obj != nil; obj = obj.Next() {
		if (obj.field_4&0x20) == 0 && obj.ScriptID() == val {
			C.nox_xxx_scriptPrepareFoundUnit_511D70(obj.CObj())
			return obj
		}
	}
	return nil
}
