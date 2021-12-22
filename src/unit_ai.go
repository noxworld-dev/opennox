package nox

/*
#include "defs.h"
*/
import "C"

import (
	"nox/v1/common/unit/ai"
)

//export nox_ai_debug_print
func nox_ai_debug_print(str *C.char) {
	ai.Log.Printf("%s", GoString(str))
}

//export nox_ai_debug_printStack_509F60
func nox_ai_debug_printStack_509F60(cu *C.nox_object_t, event *C.char) {
	if !getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_AI) {
		return
	}
	u := asUnitC(cu)
	ud := u.updateDataMonster()
	ai.Log.Printf("%d: stack (%s):\n", gameFrame(), GoString(event))
	defer ai.Log.Println("----------------------------------------")
	ind := int(int8(ud.ai_stack_ind))
	if ind < 0 {
		return
	}
	for i := ind; i >= 0; i-- {
		r := &ud.ai_stack[i]
		ai.Log.Printf("  %s", ai.ActionType(r.action).String())
	}
}
