package main

/*
#include "proto.h"
*/
import "C"
import (
	"fmt"
	"math"
	"unsafe"

	"nox/v1/common/object"
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

func getObjectTypeByInd(ind int) *ObjectType {
	if ind == math.MaxUint16 {
		return nil
	}
	if ind < 0 || ind >= int(C.nox_xxx_unitDefGetCount_4E3AC0()) {
		return nil
	}
	p := C.nox_xxx_unitDefGet_4E3B70(C.int(ind))
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

func (t *ObjectType) field(dp uintptr) unsafe.Pointer {
	return unsafe.Pointer(uintptr(unsafe.Pointer(t)) + dp)
}

func (t *ObjectType) ID() string {
	return GoString(*(**C.char)(t.field(4)))
}

func (t *ObjectType) Ind() int {
	return int(*(*uint16)(t.field(0)))
}

func (t *ObjectType) String() string {
	return fmt.Sprintf("ObjectType(%d,%q)", t.Ind(), t.ID())
}

func (t *ObjectType) CreateObject(p types.Pointf) script.Object {
	cobj := C.nox_new_objMem_4E3470(C.int(uintptr(t.C())))
	if cobj == nil {
		return nil
	}
	C.nox_xxx_createAt_4DAA50(C.int(uintptr(cobj)), 0, C.float(p.X), C.float(p.Y))
	obj := asObject(cobj)
	if obj.Class().Has(object.MaskUnits) {
		return obj.AsUnit()
	}
	return obj
}
