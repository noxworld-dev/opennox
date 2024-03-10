package legacy

/*
#include "server__script__script.h"
#include "server__script__internal.h"
#include "GAME4_1.h" // for nox_xxx_scriptPrepareFoundUnit_511D70 and nox_xxx_script_511C50
int sub_516570();
int nox_xxx_gameIsSwitchToSolo_4DB240();
size_t nox_script_readWriteWww_5417C0(FILE* a1, FILE* a2, FILE* a3);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/server"
	"github.com/noxworld-dev/opennox/v1/server/noxscript"
)

var (
	Nox_script_readWriteZzz_541670 func(cpath, cpath2, cdst *byte) int
)

type NoxScript interface {
	noxscript.VM
	ActResolveObjs()
	ScriptToObject(h int) *server.Object
	ScriptCallback(b *server.ScriptCallback, caller, trigger *server.Object, eventCode server.ScriptEventType) unsafe.Pointer
}

//export nox_script_activatorResolveObjs_51B0C0
func nox_script_activatorResolveObjs_51B0C0() {
	GetServer().NoxScriptC().ActResolveObjs()
}

//export nox_xxx_netGetUnitCodeServ_578AC0
func nox_xxx_netGetUnitCodeServ_578AC0(cobj *nox_object_t) C.uint {
	return C.uint(GetServer().S().GetUnitNetCode(asObjectS(cobj)))
}

//export nox_server_scriptValToObjectPtr_511B60
func nox_server_scriptValToObjectPtr_511B60(val int) *nox_object_t {
	return asObjectC(GetServer().NoxScriptC().ScriptToObject(val))
}

//export nox_script_push
func nox_script_push(v int) {
	GetServer().NoxScriptC().PushI32(int32(v))
}

//export nox_script_pop
func nox_script_pop() int {
	return int(GetServer().NoxScriptC().PopI32())
}

//export nox_script_pushf
func nox_script_pushf(v C.float) {
	GetServer().NoxScriptC().PushF32(float32(v))
}

//export nox_script_popf
func nox_script_popf() C.float {
	return C.float(GetServer().NoxScriptC().PopF32())
}

//export nox_script_indexByEvent
func nox_script_indexByEvent(cname *C.char) int {
	return GetServer().S().NoxScriptVM.ScriptIndexByName(GoString(cname))
}

//export nox_script_getString_512E40
func nox_script_getString_512E40(i int) *C.char {
	s, ok := GetServer().S().NoxScriptVM.LookupString(uint32(i))
	if !ok {
		return nil
	}
	return internCStr(s)
}

//export nox_script_readWriteZzz_541670
func nox_script_readWriteZzz_541670(cpath, cpath2, cdst *C.char) int {
	return Nox_script_readWriteZzz_541670((*byte)(unsafe.Pointer(cpath)), (*byte)(unsafe.Pointer(cpath2)), (*byte)(unsafe.Pointer(cdst)))
}

//export nox_xxx_scriptCallByEventBlock_502490
func nox_xxx_scriptCallByEventBlock_502490(a1 unsafe.Pointer, a2, a3 unsafe.Pointer, eventCode int32) unsafe.Pointer {
	return GetServer().NoxScriptC().ScriptCallback((*server.ScriptCallback)(a1), AsObjectP(a2), AsObjectP(a3), server.ScriptEventType(eventCode))
}

//export nox_script_callByIndex_507310
func nox_script_callByIndex_507310(index int, a2 unsafe.Pointer, a3 unsafe.Pointer) {
	if err := GetServer().S().NoxScriptVM.CallByIndex(index, AsObjectP(a2), AsObjectP(a3)); err != nil {
		scriptLog.Println(err)
	}
}

//export nox_script_callbackName
func nox_script_callbackName(h int) *C.char {
	s := GetServer().S().NoxScriptVM.ScriptNameByIndex(h)
	return internCStr(s)
}

//export nox_script_objCallbackName_508CB0
func nox_script_objCallbackName_508CB0(obj *nox_object_t, event int) *C.char {
	s, ok := GetServer().S().NoxScriptVM.Nox_script_objCallbackName_508CB0(asObjectS(obj), event)
	if !ok {
		return nil
	}
	return internCStr(s)
}

func Sub_516570() {
	C.sub_516570()
}
func Nox_xxx_script_511C50(a1 int) *server.Object {
	return asObjectS(C.nox_xxx_script_511C50(C.int(a1)))
}
func Nox_xxx_scriptPrepareFoundUnit_511D70(a1 *server.Object) {
	C.nox_xxx_scriptPrepareFoundUnit_511D70(asObjectC(a1))
}
func Nox_script_readWriteWww_5417C0(a1 *binfile.File, a2 *binfile.File, a3 *binfile.File) {
	C.nox_script_readWriteWww_5417C0(NewFileHandle(a1), NewFileHandle(a2), NewFileHandle(a3))
}
