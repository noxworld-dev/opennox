package main

/*
#include "proto.h"
*/
import "C"
import (
	"fmt"
	"unsafe"

	"nox/v1/common/types"
	"nox/v1/server/script"
)

func getObjectTypeByID(id string) *ObjectType {
	cstr := CString(id)
	defer StrFree(cstr)
	p := C.nox_xxx_unitDefByName_4E3830(cstr)
	if p == 0 {
		return nil
	}
	return asObjectType(unsafe.Pointer(uintptr(p)))
}

type ObjectType [0]byte

func asObjectType(p unsafe.Pointer) *ObjectType {
	return (*ObjectType)(p)
}

func (t *ObjectType) C() unsafe.Pointer {
	return unsafe.Pointer(t)
}

func (t *ObjectType) ID() string {
	// TODO: find offset for the name
	return fmt.Sprintf("%T(%p)", t, t)
}

func (t *ObjectType) CreateObject(p types.Pointf) script.Object {
	obj := C.nox_new_objMem_4E3470(C.int(uintptr(t.C())))
	if obj == nil {
		return nil
	}
	C.nox_xxx_createAt_4DAA50(C.int(uintptr(obj)), 0, C.float(p.X), C.float(p.Y))
	return asObject(obj)
}
