package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/server"
	"github.com/noxworld-dev/opennox/v1/server/noxscript"
)

var (
	Nox_script_indexByEvent           func(name string) int
	Nox_script_getString_512E40       func(i int) (string, bool)
	Nox_setImaginaryCaster            func() int
	Nox_script_readWriteZzz_541670    func(cpath, cpath2, cdst *byte) int
	Nox_script_callbackName           func(h int) string
	Nox_script_objCallbackName_508CB0 func(obj *server.Object, event int) (string, bool)
	Sub_511E60                        func()
)

type NoxScript interface {
	noxscript.VM
	ActResolveObjs()
	ScriptToObject(h int) *server.Object
	CallByIndex(index int, caller, trigger *server.Object) error
	ScriptCallback(b *server.ScriptCallback, caller, trigger *server.Object, eventCode server.ScriptEventType) unsafe.Pointer
	Caller() *server.Object
	Trigger() *server.Object
}

// nox_script_activatorResolveObjs_51B0C0
func nox_script_activatorResolveObjs_51B0C0() {
	GetServer().NoxScriptC().ActResolveObjs()
}

// nox_xxx_netGetUnitCodeServ_578AC0
func nox_xxx_netGetUnitCodeServ_578AC0(cobj *server.Object) uint32 {
	return uint32(GetServer().GetUnitNetCode(asObjectS(cobj)))
}

// nox_server_scriptValToObjectPtr_511B60
func nox_server_scriptValToObjectPtr_511B60(val int32) *server.Object {
	return asObjectC(GetServer().NoxScriptC().ScriptToObject(int(val)))
}

func nox_script_push(v int32) {
	GetServer().NoxScriptC().PushI32(v)
}

func nox_script_pop() int32 {
	return GetServer().NoxScriptC().PopI32()
}

func nox_script_pushf(v float32) {
	GetServer().NoxScriptC().PushF32(v)
}

func nox_script_popf() float32 {
	return GetServer().NoxScriptC().PopF32()
}

// nox_script_indexByEvent
func nox_script_indexByEvent(cname *byte) int32 {
	return int32(Nox_script_indexByEvent(GoString(cname)))
}

// nox_script_getString_512E40
func nox_script_getString_512E40(i int32) *byte {
	s, ok := Nox_script_getString_512E40(int(i))
	if !ok {
		return nil
	}
	return internCStr(s)
}

// nox_setImaginaryCaster
func nox_setImaginaryCaster() int { return Nox_setImaginaryCaster() }

// nox_script_readWriteZzz_541670
func nox_script_readWriteZzz_541670(cpath, cpath2, cdst *byte) int {
	return Nox_script_readWriteZzz_541670(cpath, cpath2, cdst)
}

// nox_xxx_scriptCallByEventBlock_502490
func nox_xxx_scriptCallByEventBlock_502490(a1 unsafe.Pointer, a2, a3 unsafe.Pointer, eventCode int32) unsafe.Pointer {
	return GetServer().NoxScriptC().ScriptCallback((*server.ScriptCallback)(a1), AsObjectP(a2), AsObjectP(a3), server.ScriptEventType(eventCode))
}

// nox_script_callByIndex_507310
func nox_script_callByIndex_507310(index int32, a2 unsafe.Pointer, a3 unsafe.Pointer) {
	if err := GetServer().NoxScriptC().CallByIndex(int(index), AsObjectP(a2), AsObjectP(a3)); err != nil {
		scriptLog.Println(err)
	}
}

// nox_script_callbackName
func nox_script_callbackName(h int32) *byte {
	s := Nox_script_callbackName(int(h))
	return internCStr(s)
}

// nox_script_objCallbackName_508CB0
func nox_script_objCallbackName_508CB0(obj *server.Object, event int32) *byte {
	s, ok := Nox_script_objCallbackName_508CB0(asObjectS(obj), int(event))
	if !ok {
		return nil
	}
	return internCStr(s)
}

// sub_511E60
func sub_511E60() {
	Sub_511E60()
}

func Sub_516570() {
	sub_516570()
}
func Nox_xxx_script_511C50(a1 int) *server.Object {
	return asObjectS(nox_xxx_script_511C50(int32(a1)))
}
func Nox_xxx_scriptPrepareFoundUnit_511D70(a1 *server.Object) {
	nox_xxx_scriptPrepareFoundUnit_511D70(asObjectC(a1))
}
func Nox_script_readWriteWww_5417C0(a1 *binfile.File, a2 *binfile.File, a3 *binfile.File) {
	nox_script_readWriteWww_5417C0(NewFileHandle(a1), NewFileHandle(a2), NewFileHandle(a3))
}
