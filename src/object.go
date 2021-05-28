package main

/*
#include "proto.h"
extern void* nox_server_objects_1556844;
extern void* nox_server_objects_uninited_1556860;
*/
import "C"
import (
	"strings"
	"unsafe"

	"nox/v1/common/alloc"
	"nox/v1/common/object"
	"nox/v1/common/types"
	"nox/v1/server/script"
)

func asObject(p unsafe.Pointer) *Object {
	return (*Object)(p)
}

func firstServerObject() *Object {
	return asObject(C.nox_server_objects_1556844)
}

func firstServerObjectUninited() *Object {
	return asObject(C.nox_server_objects_uninited_1556860)
}

func getObjects() []*Object {
	var out []*Object
	for p := firstServerObject(); p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func getObjectsUninited() []*Object {
	var out []*Object
	for p := firstServerObjectUninited(); p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func getObjectByID(id string) *Object {
	for obj := firstServerObject(); obj != nil; obj = obj.Next() {
		if p := obj.findByID(id); p != nil {
			return p
		}
	}
	for obj := firstServerObjectUninited(); obj != nil; obj = obj.Next() {
		if p := obj.findByID(id); p != nil {
			return p
		}
	}
	return nil
}

type Object [0]byte

func (obj *Object) C() unsafe.Pointer {
	return unsafe.Pointer(obj)
}

func (obj *Object) field(dp uintptr) unsafe.Pointer {
	return unsafe.Pointer(uintptr(unsafe.Pointer(obj)) + dp)
}

func (obj *Object) ID() string {
	p := *(**C.char)(obj.field(0))
	return GoString(p)
}

func (obj *Object) Class() object.Class {
	v := *(*uint32)(obj.field(8))
	return object.Class(v)
}

func (obj *Object) findByID(id string) *Object {
	if obj.equalID(id) {
		return obj
	}
	for p := obj.FirstXxx(); p != nil; p = p.NextXxx() {
		if p.equalID(id) {
			return p
		}
	}
	return nil
}

func (obj *Object) equalID(id2 string) bool {
	id := obj.ID()
	if id == "" {
		return false
	}
	return id == id2 || strings.HasSuffix(id, ":"+id2)
}

func (obj *Object) Next() *Object {
	p := *(*unsafe.Pointer)(obj.field(444))
	return asObject(p)
}

func (obj *Object) FirstXxx() *Object {
	p := *(*unsafe.Pointer)(obj.field(504))
	return asObject(p)
}

func (obj *Object) NextXxx() *Object {
	p := *(*unsafe.Pointer)(obj.field(496))
	return asObject(p)
}

func (obj *Object) GetXxx() []*Object {
	var out []*Object
	for p := obj.FirstXxx(); p != nil; p = p.NextXxx() {
		out = append(out, p)
	}
	return out
}

func (obj *Object) AsUnit() *Unit {
	// TODO: check somehow
	return asUnit(unsafe.Pointer(obj))
}

func (obj *Object) ObjectType() script.ObjectType {
	panic("implement me")
}

func (obj *Object) Pos() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	// TODO: verify
	return types.Pointf{
		X: float32(*(*C.float)(obj.field(56))),
		Y: float32(*(*C.float)(obj.field(60))),
	}
}

func (obj *Object) MoveTo(p types.Pointf) {
	cp := (*C.float2)(alloc.Malloc(unsafe.Sizeof(C.float2{})))
	defer alloc.Free(unsafe.Pointer(cp))
	cp.field_0 = C.float(p.X)
	cp.field_4 = C.float(p.Y)
	C.nox_xxx_unitMove_4E7010(C.int(uintptr(obj.C())), cp)
}

func (obj *Object) Z() float32 {
	return float32(*(*C.int)(obj.field(104)))
}

func (obj *Object) SetZ(z float32) {
	panic("implement me")
}

func (obj *Object) Push(vec types.Pointf, force float32) {
	panic("implement me")
}

func (obj *Object) PushTo(p types.Pointf) {
	panic("implement me")
}

func (obj *Object) IsEnabled() bool {
	if obj == nil {
		return false
	}
	return *(*uint32)(obj.field(16))&0x1000000 != 0
}

func (obj *Object) Enable(enable bool) {
	if obj == nil {
		return
	}
	if enable {
		C.nox_xxx_objectSetOn_4E75B0(C.int(uintptr(obj.C())))
	} else {
		C.nox_xxx_objectSetOff_4E7600(C.int(uintptr(obj.C())))
	}
}

func (obj *Object) Delete() {
	C.nox_xxx_delayedDeleteObject_4E5CC0(C.int(uintptr(obj.C())))
}
